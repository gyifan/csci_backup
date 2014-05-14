// File ov7670_capture.vhd translated with vhd2vl v2.4 VHDL to Verilog RTL translator
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
// Description: Captures the pixels coming from the OV7670 camera and 
//              Stores them in block RAM
//--------------------------------------------------------------------------------
// no timescale needed

module ov7670_capture(
pclk,
vsync,
href,
d,
addr,
dout,
we
);

input pclk;
input vsync;
input href;
input [7:0] d;
output [18:0] addr;
output [11:0] dout;
output we;

wire pclk;
wire vsync;
wire href;
wire [7:0] d;
wire [18:0] addr;
reg [11:0] dout;
reg we;


reg [15:0] d_latch = 0;
reg [18:0] address = 0;
reg [18:0] address_next = 0;
reg [1:0] wr_hold = 0;

  assign addr = address;
  always @(posedge pclk) begin
    // This is a bit tricky href starts a pixel transfer that takes 3 cycles
    //        Input   | state after clock tick   
    //         href   | wr_hold    d_latch           d                 we address  address_next
    // cycle -1  x    |    xx      xxxxxxxxxxxxxxxx  xxxxxxxxxxxxxxxx  x   xxxx     xxxx
    // cycle 0   1    |    x1      xxxxxxxxRRRRRGGG  xxxxxxxxxxxxxxxx  x   xxxx     addr
    // cycle 1   0    |    10      RRRRRGGGGGGBBBBB  xxxxxxxxRRRRRGGG  x   addr     addr
    // cycle 2   x    |    0x      GGGBBBBBxxxxxxxx  RRRRRGGGGGGBBBBB  1   addr     addr+1
    if(vsync == 1'b 1) begin
      address <= {19{1'b0}};
      address_next <= {19{1'b0}};
      wr_hold <= {2{1'b0}};
    end
    else begin
      // This should be a different order, but seems to be GRB!
      //            dout    <= d_latch(11 downto 10) & d_latch(11 downto 10) & d_latch(15 downto 12) & d_latch(9 downto 8) & d_latch(9 downto 8); 
      dout <= {d_latch[15:12],d_latch[10:7],d_latch[4:1]};
      address <= address_next;
      we <= wr_hold[1];
      wr_hold <= {wr_hold[0],(href &  ~wr_hold[0])};
      d_latch <= {d_latch[7:0],d};
      if(wr_hold[1] == 1'b 1) begin
        address_next <= (((address_next)) + 1);
      end
    end
  end


endmodule
