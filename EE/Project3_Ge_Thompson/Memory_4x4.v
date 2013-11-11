`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Bucknell University ELEC 340 
// Engineer: Yifan Ge, Alex Thompson
// 
// Create Date:    14:16:16 04/21/2012 
// Design Name: Memory Game 
// Module Name:    Memory_4x4 
// Project Name: ELEC 340 Project 3 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Memory_4x4(
	 inout wire ps2_clk,
	 inout wire ps2_data,
    input wire sysclk,
    output wire [2:0] rgb,
    output wire hsync,
    output wire vsync
    );
	 
	 // Define internal signals
	 wire [9:0] pixel_x, pixel_y;
	 wire video_on, pixel_tick;
	 reg [2:0] rgb_reg;
	 wire [2:0] rgb_next;
	 wire [7:0] key_in;
	 
	 // Clock Divider
	 parameter SYSCLK_SPEED = 50000000;
	 parameter PS2_CLK_SPEED = 500000;
	 reg [31:0] clkcount, next_clkcount;
	 reg slowclk, next_slowclk;
	 initial clkcount = 32'd0;
	 initial slowclk = 1'b0;
	 always @ (*)
	 begin
	 	if (clkcount == (SYSCLK_SPEED/PS2_CLK_SPEED))
	 	begin
	 		next_clkcount = 32'b0;
	 		next_slowclk = ~slowclk;
	 	end
	 	else
	 		next_clkcount = clkcount + 1;
	 end
	 always @ (posedge sysclk)
	 begin
	 	clkcount <= next_clkcount;
	 	slowclk <= next_slowclk;
	 end
	 
	 // Instantiate keyboard interface
	 ps2_keyboard_interface kybd_unit(
	 	.clk(slowclk),
	 	.ps2_clk(ps2_clk),
	 	.ps2_data(ps2_data),		
	 	.rx_read(1),
		.rx_released(key_released),
	 	.rx_scan_code(key_in),
	 	.rx_extended(ext)
	 );
	 
	 // Instantiate vga sync circuit
	 vga_sync vsync_unit(
		.clk(sysclk),
		.reset(0),
		.hsync(hsync),
		.vsync(vsync),
		.video_on(video_on),
		.p_tick(pixel_tick),
		.pixel_x(pixel_x),
		.pixel_y(pixel_y)
	 );
	 
	 // Instantiate graphics generator
	 game_animate game_an_unit(
		.clk(sysclk),
		.key_in(key_in),
		.key_released(key_released),
		.ext(ext),
		.video_on(video_on),
		.pix_x(pixel_x),
		.pix_y(pixel_y),
		.graph_rgb(rgb_next)
	 );
	
	 always @ (posedge sysclk)
	 begin
		// rgb buffer
		if (pixel_tick)
			rgb_reg <= rgb_next;
		// Output	
	 end
	
	 assign rgb = rgb_reg;
endmodule
