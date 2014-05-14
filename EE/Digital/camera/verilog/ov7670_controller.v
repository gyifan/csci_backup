// File ov7670_controller.vhd translated with vhd2vl v2.4 VHDL to Verilog RTL translator
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
// Description: Controller for the OV760 camera - transferes registers to the 
//              camera over an I2C like bus
//--------------------------------------------------------------------------------
// no timescale needed

module ov7670_controller(
clk,
resend,
config_finished,
sioc,
siod,
reset,
pwdn,
xclk
);

input clk;
input resend;
output config_finished;
output sioc;
inout siod;
output reset;
output pwdn;
output xclk;

wire clk;
wire resend;
wire config_finished;
wire sioc;
wire siod;
wire reset;
wire pwdn;
wire xclk;


reg sys_clk = 1'b 0;
wire [15:0] command;
wire finished = 1'b 0;
wire taken = 1'b 0;
wire send;
parameter camera_address = 8'h 42;  // 42"; -- Device write ID - see top of page 11 of data sheet

  assign config_finished = finished;
  assign send =  ~finished;
  i2c_sender Inst_i2c_sender(
      .clk(clk),
    .taken(taken),
    .siod(siod),
    .sioc(sioc),
    .send(send),
    .id(camera_address),
    .reg(command[15:8]),
    .value(command[7:0]));

  assign reset = 1'b 1;
  // Normal mode
  assign pwdn = 1'b 0;
  // Power device up
  assign xclk = sys_clk;
  ov7670_registers Inst_ov7670_registers(
      .clk(clk),
    .advance(taken),
    .command(command),
    .finished(finished),
    .resend(resend));

  always @(posedge clk) begin
    sys_clk <=  ~sys_clk;
  end


endmodule
