// File debounce.vhd translated with vhd2vl v2.4 VHDL to Verilog RTL translator
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
// Description: Convert the push button to a 1PPS that can be used to restart
//              camera initialisation
//--------------------------------------------------------------------------------
// no timescale needed

module debounce(
clk,
i,
o
);

input clk;
input i;
output o;

wire clk;
wire i;
reg o;


reg [23:0] c;

  always @(posedge clk) begin
    if(i == 1'b 1) begin
      if(c == 24'h FFFFFF) begin
        o <= 1'b 1;
      end
      else begin
        o <= 1'b 0;
      end
      c <= c + 1;
    end
    else begin
      c <= {24{1'b0}};
      o <= 1'b 0;
    end
  end


endmodule
