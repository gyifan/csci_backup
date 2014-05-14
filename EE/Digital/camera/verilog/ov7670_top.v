// File ov7670_top.vhd translated with vhd2vl v2.4 VHDL to Verilog RTL translator
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
// Description: Top level for the OV7670 camera project.
//--------------------------------------------------------------------------------
// no timescale needed

module ov7670_top(
clk100,
OV7670_SIOC,
OV7670_SIOD,
OV7670_RESET,
OV7670_PWDN,
OV7670_VSYNC,
OV7670_HREF,
OV7670_PCLK,
OV7670_XCLK,
OV7670_D,
LED,
vga_red,
vga_green,
vga_blue,
vga_hsync,
vga_vsync,
btn
);

input clk100;
output OV7670_SIOC;
inout OV7670_SIOD;
output OV7670_RESET;
output OV7670_PWDN;
input OV7670_VSYNC;
input OV7670_HREF;
input OV7670_PCLK;
output OV7670_XCLK;
input [7:0] OV7670_D;
output [7:0] LED;
output [3:0] vga_red;
output [3:0] vga_green;
output [3:0] vga_blue;
output vga_hsync;
output vga_vsync;
input btn;

wire clk100;
wire OV7670_SIOC;
wire OV7670_SIOD;
wire OV7670_RESET;
wire OV7670_PWDN;
wire OV7670_VSYNC;
wire OV7670_HREF;
wire OV7670_PCLK;
wire OV7670_XCLK;
wire [7:0] OV7670_D;
wire [7:0] LED;
wire [3:0] vga_red;
wire [3:0] vga_green;
wire [3:0] vga_blue;
wire vga_hsync;
wire vga_vsync;
wire btn;


wire [18:0] frame_addr;
wire [11:0] frame_pixel;
wire [18:0] capture_addr;
wire [11:0] capture_data;
wire [0:0] capture_we;
wire resend;
wire config_finished;
wire clk_feedback;
wire clk50u;
wire clk50;
wire clk25u;
wire clk25;
wire buffered_pclk;

  debounce btn_debounce(
      .clk(clk50),
    .i(btn),
    .o(resend));

  vga Inst_vga(
      .clk25(clk25),
    .vga_red(vga_red),
    .vga_green(vga_green),
    .vga_blue(vga_blue),
    .vga_hsync(vga_hsync),
    .vga_vsync(vga_vsync),
    .frame_addr(frame_addr),
    .frame_pixel(frame_pixel));

  frame_buffer fb(
      .clka(OV7670_PCLK),
    .wea(capture_we),
    .addra(capture_addr),
    .dina(capture_data),
    .clkb(clk50),
    .addrb(frame_addr),
    .doutb(frame_pixel));

  assign led = {7'b 0000000,config_finished};
  ov7670_capture capture(
      .pclk(OV7670_PCLK),
    .vsync(OV7670_VSYNC),
    .href(OV7670_HREF),
    .d(OV7670_D),
    .addr(capture_addr),
    .dout(capture_data),
    .we(capture_we[0]));

  ov7670_controller controller(
      .clk(clk50),
    .sioc(ov7670_sioc),
    .resend(resend),
    .config_finished(config_finished),
    .siod(ov7670_siod),
    .pwdn(OV7670_PWDN),
    .reset(OV7670_RESET),
    .xclk(OV7670_XCLK));

  clocking your_instance_name(
      // Clock in ports
    .CLK_100(CLK100),
    // Clock out ports
    .CLK_50(CLK50),
    .CLK_25(CLK25));


endmodule
