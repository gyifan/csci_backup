// File vga.vhd translated with vhd2vl v2.4 VHDL to Verilog RTL translator
// vhd2vl settings:
//  * Verilog Module Declaration Style: 1995

// vhd2vl is Free (libre) Software:
//   Copyright (C) 2001 Vincenzo Liguori - Ocean Logic Pty Ltd
//     http://www.ocean-logic.com
//   Modifications Copyright (C) 2006 Mark Gonzales - PMC Sierra Inc
//   Modifications (C) 2010 Shankar Giri
//   Modifications Copyright (C) 2002, 2005, 2008-2010 Larry Doolittle - LBNL
//     http://doolittle.icarus.com/~larry/vhd2vl/
//
//   vhd2vl comes with ABSOLUTELY NO WARRANTY.  Always check the resulting
//   Verilog for correctness, ideally with a formal verification tool.
//
//   You are welcome to redistribute vhd2vl under certain conditions.
//   See the license (GPLv2) file included with the source for details.

// The result of translation follows.  Its copyright status should be
// considered unchanged from the original VHDL.

//--------------------------------------------------------------------------------
// Engineer: Mike Field <hamster@snap.net.nz>
// 
// Description: Generate analog 640x480 VGA, double-doublescanned from 19200 bytes of RAM
// 
// Revision: Yifan Ge - 4/28/2014
//		Added laser detection mechanism. 
//
//--------------------------------------------------------------------------------
// no timescale needed

module vga(
clk25,
vga_red,
vga_green,
vga_blue,
vga_hSync,
vga_vSync,
frame_addr,
frame_pixel,
led,
xOffset,
yOffset,
valid
);

input clk25;
output [3:0] vga_red;
output [3:0] vga_green;
output [3:0] vga_blue;
output vga_hSync;
output vga_vSync;
output [18:0] frame_addr;
input [11:0] frame_pixel;
output [7:0] led;

// Laser location control
output signed [9:0] xOffset;
output signed [9:0] yOffset;
output valid;

wire clk25;
reg [3:0] vga_red;
reg [3:0] vga_green;
reg [3:0] vga_blue;
reg vga_hSync;
reg vga_vSync;
wire [18:0] frame_addr;
wire [11:0] frame_pixel;
wire [7:0] led;


// Laser detection
parameter ACC = 2'b01;
parameter AVG = 2'b10;
parameter RST = 2'b00;
parameter XCENTER = 10'b101000000; // 320
parameter YCENTER = 10'b11110000; // 240
parameter REDTHRESH = 14;

reg [3:0] vga_red_r;
reg [3:0] vga_green_r;
reg [3:0] vga_blue_r;
reg [13:0] hSum = 14'b0; 		// Sum of horizontal location of pixels pass threshold
reg [13:0] nexthSum = 14'b0;
reg [13:0] vSum = 14'b0;		// Sum of vertical location of pixels pass threshold
reg [13:0] nextvSum = 14'b0;
reg [9:0] hLaser = 10'b0;		// horizontal location of the laser
reg [9:0] nexthLaser = 10'b0;
reg [9:0] vLaser = 10'b0;		// vertical location of the laser
reg [9:0] nextvLaser = 10'b0;
reg [4:0] cnt = 5'b0;			// Counter for number of pixels pass threshold
reg [4:0] nextCnt = 5'b0;
wire signed [9:0] xOffset;		// Laser horizontal location offset from the center
wire signed [9:0] yOffset;		// Laser vertical location offset from the center
reg valid = 1'b0;					// The valid bit of the laser offsets
reg nextValid = 1'b0;

reg [1:0] cstate = RST;
reg [1:0] nstate = RST;


// Timing constants
parameter hRez = 640;
parameter hStartSync = 640 + 16;
parameter hEndSync = 640 + 16 + 96;
parameter hMaxCount = 800;
parameter vRez = 480;
parameter vStartSync = 480 + 10;
parameter vEndSync = 480 + 10 + 2;
parameter vMaxCount = 480 + 10 + 2 + 33;
parameter hsync_active = 1'b 0;
parameter vsync_active = 1'b 0;
reg [9:0] hCounter = 0;
reg [9:0] vCounter = 0;
reg [18:0] address = 0;
reg blank = 1'b 1;

  assign frame_addr = (address);
  always @(posedge clk25) begin
    // Count the lines and rows      
    if(hCounter == (hMaxCount - 1)) begin
      hCounter <= {10{1'b0}};
      if(vCounter == (vMaxCount - 1)) begin
        vCounter <= {10{1'b0}};
      end
      else begin
        vCounter <= vCounter + 1;
      end
    end
    else begin
      hCounter <= hCounter + 1;
    end
	 
    if(blank == 1'b 0) begin
      vga_red_r <= frame_pixel[11:8];
      vga_green_r <= frame_pixel[7:4];
      vga_blue_r <= frame_pixel[3:0];
    end
    else begin
      vga_red_r <= {4{1'b0}};
      vga_green_r <= {4{1'b0}};
      vga_blue_r <= {4{1'b0}};
    end
	 
    if(vCounter >= vRez) begin
      address <= {19{1'b0}};
      blank <= 1'b 1;
    end
    else begin
      if(hCounter < 640) begin
        blank <= 1'b 0;
        address <= address + 1;
      end
      else begin
        blank <= 1'b 1;
      end
    end
	 
    // Are we in the hSync pulse? (one has been added to include frame_buffer_latency)
    if(hCounter > hStartSync && hCounter <= hEndSync) begin
      vga_hSync <= hsync_active;
    end
    else begin
      vga_hSync <=  ~hsync_active;
    end
	 
    // Are we in the vSync pulse?
    if(vCounter >= vStartSync && vCounter < vEndSync) begin
      vga_vSync <= vsync_active;
    end
    else begin
      vga_vSync <=  ~vsync_active;
    end

  end
  
  /*
   * ===========================================================
   *                   FSM for laser detector
	* ===========================================================
	*/
  always @(posedge clk25) begin
	 cstate <= nstate;
	 
	 // Update the registers
	 cnt <= nextCnt;
	 vSum <= nextvSum;
	 hSum <= nexthSum;
	 valid <= nextValid;
	 vLaser <= nextvLaser;
	 hLaser <= nexthLaser;
  end

  // State logic
  always @(*) begin
    case (cstate) 
	   ACC: begin // Accumulate the vSum and hSum if the pixel passes the threshold
				 // 0 <= vCounter < 480; 4 < hCounter < 640; cnt < 16
			    if(vga_red_r > REDTHRESH && cnt < 16 && vCounter < 480 && hCounter < 640 && hCounter > 4) begin
				   nextCnt <= cnt + 5'b1;
					nextvSum <= vSum + vCounter;
					nexthSum <= hSum + hCounter;
				 end
				 else begin
				   nextCnt <= cnt;
					nextvSum <= vSum;
					nexthSum <= hSum;
				 end
				 
				 nextValid <= valid;
				 nextvLaser <= vLaser;
				 nexthLaser <= hLaser;
				 
				 // Accumulate until end of the frame
				 if(vCounter > vEndSync )
				   nstate <= AVG;
			    else
				   nstate <= cstate;
				 
			  end
      AVG: begin // If 16 valid pixels are accumulated average sums to find location of the laser
			    if(cnt < 16) begin
					nextValid <= 1'b0;
					nextvLaser <= vLaser;
					nexthLaser <= hLaser;
				 end
				 else begin
					nextValid <= 1'b1;
					nextvLaser <= vSum >> 4;
					nexthLaser <= hSum >> 4;
				 end
				 
				 nextCnt <= cnt;
				 nextvSum <= vSum;
				 nexthSum <= hSum;
				 
				 // Reset registers if new laser location is recorded
				 if(valid == 1'b1)
					nstate <= RST;
				 else
				   nstate <= ACC;
				 
		     end
		RST: begin // Reset all the valid for next frame
			    nextValid <= 1'b0;
				 nextvSum <= 14'b0;
				 nexthSum <= 14'b0;
				 nextCnt <= 5'b0;
				 nextvLaser <= vLaser;
				 nexthLaser <= hLaser;
				 
				 // Start accumulating at new frame
				 if(vCounter == 10'b0)
				   nstate <= ACC;
			    else
				   nstate <= cstate;
			  end
	   default: begin
				 nextCnt <= cnt;
				 nextvSum <= vSum;
				 nexthSum <= hSum;
				 nextvLaser <= vLaser;
				 nexthLaser <= hLaser;
				 nextValid <= valid;
				 nstate <= cstate;
			  end
    endcase
  end

  // Update the output rgb value
  always @(*)
  begin // 20 by 20 pixels black box around the last laser location
	 if(vCounter < vLaser + 10 && vCounter > vLaser - 10 && hCounter < hLaser + 10 && hCounter > hLaser - 10)
	 begin
		vga_red <= 4'b0;
		vga_green <= 4'b0;
		vga_blue <= 4'b0;
	 end 
	 else
	 begin
      vga_red <= vga_red_r;
      vga_green <= vga_green_r;
      vga_blue <= vga_blue_r;
	 end
  end

assign led = {3'b0, cnt}; // Display the number of pixels passed threshold through the LED's in binary

assign xOffset = hLaser - XCENTER;
assign yOffset = vLaser - YCENTER;

endmodule
