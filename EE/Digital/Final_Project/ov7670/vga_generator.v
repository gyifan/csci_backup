// File vga_generator.vhd translated with vhd2vl v2.0 VHDL to Verilog RTL translator
// Copyright (C) 2001 Vincenzo Liguori - Ocean Logic Pty Ltd - http://www.ocean-logic.com
// Modifications (C) 2006 Mark Gonzales - PMC Sierra Inc
// 
// vhd2vl comes with ABSOLUTELY NO WARRANTY
// ALWAYS RUN A FORMAL VERIFICATION TOOL TO COMPARE VHDL INPUT TO VERILOG OUTPUT 
// 
// This is free software, and you are welcome to redistribute it under certain conditions.
// See the license file license.txt included with the source for details.

//--------------------------------------------------------------------------------
// Engineer:  Mike Field <hamster@snap.net.nz> 
// Module:    vga_generator.vhd
// 
// Description: A test pattern generator for the Zedboard's VGA & HDMI interface
//
// Feel free to use this how you see fit, and fix any errors you find :-)
//--------------------------------------------------------------------------------

module vga_generator(input            clk,
                     output reg [7:0] r,
                     output reg [7:0] g,
                     output reg [7:0] b,
                     output reg       de,
                     output reg       vsync = 0,
                     output reg       hsync = 0
                     );

wire  blanking = 0;
//wire  edge = 0;
reg [23:0] colour;
reg [11:0] hcounter = 0;
reg [11:0] vcounter = 0;
parameter ZERO = 0;
wire [11:0] hVisible;
wire [11:0] hStartSync;
wire [11:0] hEndSync;
wire [11:0] hMax;
wire  hSyncActive = 1;

wire [11:0] vVisible;
wire [11:0] vStartSync;
wire [11:0] vEndSync;
wire [11:0] vMax;
wire  vSyncActive = 1;

// Colours converted using The RGB -> YCbCr converter app found on Google Gadgets 
//  Y   Cb  Cr
parameter C_BLACK = 'H000000;
//  16 128 128
parameter C_RED = 'HFF0000;
//  81  90 240
parameter C_GREEN = 'H00FF00;
// 172  42  27
parameter C_BLUE = 'H0000FF;
//  32 240 118
parameter C_WHITE = 'HFFFFFF;
// 234 128 128

  // Set the video mode to 1280x720x60Hz (75MHz pixel clock needed)
  assign hVisible = ZERO + 1280;
  assign hStartSync = ZERO + 1280 + 72;
  assign hEndSync = ZERO + 1280 + 72 + 80;
  assign hMax = ZERO + 1280 + 72 + 80 + 216 - 1;
  assign vVisible = ZERO + 720;
  assign vStartSync = ZERO + 720 + 3;
  assign vEndSync = ZERO + 720 + 3 + 5;
  assign vMax = ZERO + 720 + 3 + 5 + 22 - 1;
  // Set the video mode to 1920x1080x60Hz (150MHz pixel clock needed)
  //   hVisible    <= ZERO + 1920;
  //   hStartSync  <= ZERO + 1920+88;
  //   hEndSync    <= ZERO + 1920+88+44;
  //   hMax        <= ZERO + 1920+88+44+148-1;
  //   vSyncActive <= '1';
  //   vVisible    <= ZERO + 1080;
  //   vStartSync  <= ZERO + 1080+4;
  //   vEndSync    <= ZERO + 1080+4+5;
  //   vMax        <= ZERO + 1080+4+5+36-1;
  //   hSyncActive <= '1';
  always @(hcounter or vcounter) begin
    colour <= C_BLACK;
    if(hcounter < 2) begin
      colour <= C_WHITE;
    end
    else if(hcounter < 256) begin
      colour <= C_RED;
    end
    else if(hcounter < 512) begin
      colour <= C_BLACK;
    end
    else if(hcounter < 768) begin
      colour <= C_GREEN;
    end
    else if(hcounter < 1024) begin
      colour <= C_WHITE;
    end
    else if(hcounter < 1278) begin
      colour <= C_BLUE;
    end
    else begin
      colour <= C_WHITE;
    end
    if(hcounter == 767 || hcounter == 768 || hcounter == 1023 || hcounter == 1024) begin
      colour <= C_WHITE;
    end
    colour[23:16]  <= (hcounter[7:0] );
    colour[15:8]  <= (vcounter[7:0] );
    colour[7:0]  <= (hcounter[7:0]  + vcounter[7:0] );
  end

  always @(posedge clk) begin
    if(vcounter >= vVisible || hcounter >= hVisible) begin
      r <= {8'b0};
      g <= {8'b0};
      b <= {8'b0};
      de <= 1'b 0;
    end
    else begin
      r <= colour[23:16] ;
      g <= colour[15:8] ;
      b <= colour[7:0] ;
      de <= 1'b 1;
    end
    // Generate the sync Pulses
    if(vcounter == vStartSync) begin
      vsync <= vSyncActive;
    end
    else if(vcounter == vEndSync) begin
      vsync <=  ~((vSyncActive));
    end
    if(hcounter == hStartSync) begin
      hsync <= hSyncActive;
    end
    else if(hcounter == hEndSync) begin
      hsync <=  ~((hSyncActive));
    end
    // Advance the position counters
    if(hcounter == hMax) begin
      // starting a new line
      hcounter <= {1'b0};
      if(vcounter == vMax) begin
        vcounter <= {1'b0};
      end
      else begin
        vcounter <= vcounter + 1;
      end
    end
    else begin
      hcounter <= hcounter + 1;
    end
  end


endmodule
