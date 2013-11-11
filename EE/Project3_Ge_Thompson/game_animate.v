`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Bucknell University 
// Engineer: Yifan Ge, Alex Thompson
// 
// Create Date:    12:15:06 04/19/2012 
// Design Name: Memory Game
// Module Name:    game_animate 
// Project Name: Project 3 ELEC 340
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
module game_animate(
    input wire clk, video_on,
	 input wire [7:0] key_in,
	 input wire key_released,
	 input wire ext,
	 input wire [9:0] pix_x, pix_y,
	 output reg [2:0] graph_rgb
	 );
	 
	 // refr_tick: 1-clock tick
	 wire refr_tick;
	 assign refr_tick = (pix_y == 481) && (pix_x == 0);
	 	 
	 wire [3:0] cursor;
	 wire [63:0] cards;
	 wire player;
	 wire [3:0] matches_p1;
	 wire [3:0] matches_p2;
	 // Finite State Machine to control the game state
	 fsm fsm_unit(
		.clk(refr_tick),
		.key_in(key_in),
		.key_released(key_released),
		.ext(ext),
		.cursor(cursor),
		.cards(cards),
		.player(player),
		.matches_p1(matches_p1),
		.matches_p2(matches_p2)
	 );
	 
	 // Constant and signal declaration
	  
	 // Color values
	 localparam BLACK		= 3'b000;
	 localparam BLUE 		= 3'b001;
	 localparam GREEN		= 3'b010;
	 localparam CYAN		= 3'b011;
	 localparam	RED		= 3'b100;
	 localparam MAGENTA	= 3'b101;
	 localparam YELLOW	= 3'b110;
	 localparam WHITE		= 3'b111;
	 
	 // Constant colors
	 localparam BKGD_RGB = BLACK;
	 localparam CARDBACK_RGB = WHITE;
	 localparam CURS_RGB = BLUE;
	 localparam SCORE_RGB = WHITE;
	 localparam PLAYER_RGB = BLUE;
	 localparam BORDER_RGB = WHITE;
	 
	 // Card constants
	 localparam CARD_BITS = 4;	 
	 localparam CARD0 = 0 * CARD_BITS;
	 localparam CARD1 = 1 * CARD_BITS;
	 localparam CARD2 = 2 * CARD_BITS;
	 localparam CARD3 = 3 * CARD_BITS;
	 localparam CARD4 = 4 * CARD_BITS;
	 localparam CARD5 = 5 * CARD_BITS;
	 localparam CARD6 = 6 * CARD_BITS;
	 localparam CARD7 = 7 * CARD_BITS;
	 localparam CARD8 = 8 * CARD_BITS;
	 localparam CARD9 = 9 * CARD_BITS;
	 localparam CARD10 = 10 * CARD_BITS;
	 localparam CARD11 = 11 * CARD_BITS;
	 localparam CARD12 = 12 * CARD_BITS;
	 localparam CARD13 = 13 * CARD_BITS;
	 localparam CARD14 = 14 * CARD_BITS;
	 localparam CARD15 = 15 * CARD_BITS;
	 localparam CARD16 = 16 * CARD_BITS;
	 localparam FLIP_BIT = CARD_BITS - 1; // The bit of each card that indicates if its flipped
	 localparam RGB_BITS = 3;
	 	 
	 // Card/screen Properties
	 localparam SCREEN_W = 640;
	 localparam SCREEN_H = 480;
	 localparam CARD_W = 80;
	 localparam CARD_H = 80;
	 localparam SPACING = 20;
	 localparam MARGIN_L = (SCREEN_W - 4 * CARD_W - 3 * SPACING) / 2;
	 localparam MARGIN_T = (SCREEN_H - 4 * CARD_H - 3 * SPACING) / 2;
	 localparam BORDER_TH = 3;
	 
	 // Y coordinates of each row and X coordinates of each column (top-left of card)
	 localparam ROW0 = MARGIN_T;
	 localparam ROW1 = MARGIN_T + CARD_H + SPACING;
	 localparam ROW2 = MARGIN_T + 2*CARD_H + 2*SPACING;
	 localparam ROW3 = MARGIN_T + 3*CARD_H + 3*SPACING;
	 
	 localparam COL0 = MARGIN_L;
	 localparam COL1 = MARGIN_L + CARD_W + SPACING;
	 localparam COL2 = MARGIN_L + 2*CARD_W + 2*SPACING;
	 localparam COL3 = MARGIN_L + 3*CARD_W + 3*SPACING;
	 
	 // Cursor properties
	 localparam CURS_TH = 5;
	 localparam CURS_W = CARD_W + 2*CURS_TH;
	 localparam CURS_H = CARD_H + 2*CURS_TH;
	 
	 // Location/size of player indicators
	 localparam P_W = 80;
	 localparam P_H = 44;
	 localparam P1_X = 20;
	 localparam P1_Y = ROW0;
	 localparam P2_X = 530;
	 localparam P2_Y = ROW0;
	 
	 
	 // Location of score values
	 localparam SCORE1_X = 50;
	 localparam SCORE1_Y = 150;
	 localparam SCORE2_X = 560;
	 localparam SCORE2_Y = 150;
	 
	 // Signals used for ROM
	 wire [8:0] rom_addr;
	 wire [23:0] rom_data;
	 
	 wire [8:0] rom_addr_p1;
	 wire [4:0] rom_col_p1;
	 wire rom_bit_p1;
	 wire score1_sq_on;
	 wire score1_on;
	 
	 assign rom_addr_p1 = (32 * matches_p1) + pix_y - SCORE1_Y;
	 assign rom_col_p1 = pix_x - SCORE1_X;
	 assign rom_bit_p1 = rom_data[23-rom_col_p1];
	 assign score1_sq_on = (SCORE1_X <= pix_x) && (pix_x <= SCORE1_X + 23)
								&& (SCORE1_Y <= pix_y) && (pix_y <= SCORE1_Y + 31);
	 assign score1_on = score1_sq_on && rom_bit_p1;
	 
	 wire [8:0] rom_addr_p2;
	 wire [4:0] rom_col_p2;
	 wire rom_bit_p2;
	 wire score2_sq_on;
	 wire score2_on;
	 
	 assign rom_addr_p2 = (32 * matches_p2) + pix_y - SCORE2_Y;
	 assign rom_col_p2 = pix_x - SCORE2_X;
	 assign rom_bit_p2 = rom_data[23-rom_col_p2];
	 assign score2_sq_on = (SCORE2_X <= pix_x) && (pix_x <= SCORE2_X + 23)
								&& (SCORE2_Y <= pix_y) && (pix_y <= SCORE2_Y + 31);
	 assign score2_on = score2_sq_on && rom_bit_p2;
	 
	 assign rom_addr = score1_sq_on ? rom_addr_p1 : rom_addr_p2;
	 
	 	 
	 // Instantiate font ROM
	 font_rom font_rom_unit(
		.clk(clk),
		.addr(rom_addr),
		.data(rom_data)
	 );
	 
	 
	 
	 // Cursor x,y position and register to track position
	 reg [9:0] curs_x, curs_x_next; // x_left value of cursor
	 reg [9:0] curs_y, curs_y_next; // y_top value of cursor
	 
	 
	 
	 // Object output signals
	 wire [15:0] card_on;
	 wire curs_on, p1_on, p2_on, border_on;
	 wire [2:0] card0_rgb, card1_rgb, card2_rgb, card3_rgb,
					card4_rgb, card5_rgb, card6_rgb, card7_rgb,
					card8_rgb, card9_rgb, card10_rgb, card11_rgb,
					card12_rgb, card13_rgb, card14_rgb, card15_rgb;
	 
	 // Body
	 // Registers
	 always @ (posedge clk)
		begin
			curs_x <= curs_x_next;
			curs_y <= curs_y_next;
		end
			
	 
	 // Define pixel boundaries where each card is on
	 assign card_on[0] = (COL0 <= pix_x) && (pix_x <= (COL0+CARD_W-1))
								&& (ROW0 <= pix_y) && (pix_y <= (ROW0+CARD_H-1));
								
	 assign card_on[1] = (COL1 <= pix_x) && (pix_x <= (COL1+CARD_W-1))
								&& (ROW0 <= pix_y) && (pix_y <= (ROW0+CARD_H-1));
								
	 assign card_on[2] = (COL2 <= pix_x) && (pix_x <= (COL2+CARD_W-1))
								&& (ROW0 <= pix_y) && (pix_y <= (ROW0+CARD_H-1));
								
    assign card_on[3] = (COL3 <= pix_x) && (pix_x <= (COL3+CARD_W-1))
								&& (ROW0 <= pix_y) && (pix_y <= (ROW0+CARD_H-1));
								
	 assign card_on[4] = (COL0 <= pix_x) && (pix_x <= (COL0+CARD_W-1))
								&& (ROW1 <= pix_y) && (pix_y <= (ROW1+CARD_H-1));
								
	 assign card_on[5] = (COL1 <= pix_x) && (pix_x <= (COL1+CARD_W-1))
								&& (ROW1 <= pix_y) && (pix_y <= (ROW1+CARD_H-1));
								
	 assign card_on[6] = (COL2 <= pix_x) && (pix_x <= (COL2+CARD_W-1))
								&& (ROW1 <= pix_y) && (pix_y <= (ROW1+CARD_H-1));
								
    assign card_on[7] = (COL3 <= pix_x) && (pix_x <= (COL3+CARD_W-1))
								&& (ROW1 <= pix_y) && (pix_y <= (ROW1+CARD_H-1));
								
	 assign card_on[8] = (COL0 <= pix_x) && (pix_x <= (COL0+CARD_W-1))
								&& (ROW2 <= pix_y) && (pix_y <= (ROW2+CARD_H-1));
								
	 assign card_on[9] = (COL1 <= pix_x) && (pix_x <= (COL1+CARD_W-1))
								&& (ROW2 <= pix_y) && (pix_y <= (ROW2+CARD_H-1));
								
	 assign card_on[10] = (COL2 <= pix_x) && (pix_x <= (COL2+CARD_W-1))
								&& (ROW2 <= pix_y) && (pix_y <= (ROW2+CARD_H-1));
								
    assign card_on[11] = (COL3 <= pix_x) && (pix_x <= (COL3+CARD_W-1))
								&& (ROW2 <= pix_y) && (pix_y <= (ROW2+CARD_H-1));
								
	 assign card_on[12] = (COL0 <= pix_x) && (pix_x <= (COL0+CARD_W-1))
								&& (ROW3 <= pix_y) && (pix_y <= (ROW3+CARD_H-1));
								
	 assign card_on[13] = (COL1 <= pix_x) && (pix_x <= (COL1+CARD_W-1))
								&& (ROW3 <= pix_y) && (pix_y <= (ROW3+CARD_H-1));
								
	 assign card_on[14] = (COL2 <= pix_x) && (pix_x <= (COL2+CARD_W-1))
								&& (ROW3 <= pix_y) && (pix_y <= (ROW3+CARD_H-1));
								
    assign card_on[15] = (COL3 <= pix_x) && (pix_x <= (COL3+CARD_W-1))
								&& (ROW3 <= pix_y) && (pix_y <= (ROW3+CARD_H-1));
								
	 wire [6:0] card_rom_addr;
	 wire [6:0] row0_rom_addr;
	 wire [6:0] row1_rom_addr;
	 wire [6:0] row2_rom_addr;
	 wire [6:0] row3_rom_addr;
	 
	 wire [6:0] card_rom_col;
	 wire [6:0] col0_rom_addr;
	 wire [6:0] col1_rom_addr;
	 wire [6:0] col2_rom_addr;
	 wire [6:0] col3_rom_addr;
	 
	 wire [239:0] card_rom_data;
	 wire [2:0] cardback_rgb;
	 
	 assign row0_rom_addr = pix_y - ROW0;
	 assign row1_rom_addr = pix_y - ROW1;
	 assign row2_rom_addr = pix_y - ROW2;
	 assign row3_rom_addr = pix_y - ROW3;
	 
	 assign col0_rom_addr = pix_x - COL0;
	 assign col1_rom_addr = pix_x - COL1;
	 assign col2_rom_addr = pix_x - COL2;
	 assign col3_rom_addr = pix_x - COL3;
	 
	 assign card_rom_addr = (card_on[0] || card_on[1] || card_on[2] || card_on[3]) ? row0_rom_addr : (
									(card_on[4] || card_on[5] || card_on[6] || card_on[7]) ? row1_rom_addr : (
									(card_on[8] || card_on[9] || card_on[10] || card_on[11]) ? row2_rom_addr : row3_rom_addr));
									
	 assign card_rom_col	 = (card_on[0] || card_on[4] || card_on[8] || card_on[12]) ? col0_rom_addr : (
									(card_on[1] || card_on[5] || card_on[9] || card_on[13]) ? col1_rom_addr : (
									(card_on[2] || card_on[6] || card_on[10] || card_on[14]) ? col2_rom_addr : col3_rom_addr));
									
	 assign cardback_rgb = card_rom_data[(79-card_rom_col)*3+:3];
									
	 // Instantiate card ROM
	 card_rom card_rom_unit(
		.clk(clk),
		.addr(card_rom_addr),
		.data(card_rom_data)
	 );
	 
	 // Define card colors. If the card is flipped, use the RGB bits from the cards data. Otherwise, use the default card back color
	 assign card0_rgb = cards[CARD0 + FLIP_BIT] ? cards[CARD0+:RGB_BITS] : cardback_rgb;
	 assign card1_rgb = cards[CARD1 + FLIP_BIT] ? cards[CARD1+:RGB_BITS] : cardback_rgb;
	 assign card2_rgb = cards[CARD2 + FLIP_BIT] ? cards[CARD2+:RGB_BITS] : cardback_rgb;
	 assign card3_rgb = cards[CARD3 + FLIP_BIT] ? cards[CARD3+:RGB_BITS] : cardback_rgb;
	 assign card4_rgb = cards[CARD4 + FLIP_BIT] ? cards[CARD4+:RGB_BITS] : cardback_rgb;
	 assign card5_rgb = cards[CARD5 + FLIP_BIT] ? cards[CARD5+:RGB_BITS] : cardback_rgb;
	 assign card6_rgb = cards[CARD6 + FLIP_BIT] ? cards[CARD6+:RGB_BITS] : cardback_rgb;
	 assign card7_rgb = cards[CARD7 + FLIP_BIT] ? cards[CARD7+:RGB_BITS] : cardback_rgb;
	 assign card8_rgb = cards[CARD8 + FLIP_BIT] ? cards[CARD8+:RGB_BITS] : cardback_rgb;
	 assign card9_rgb = cards[CARD9 + FLIP_BIT] ? cards[CARD9+:RGB_BITS] : cardback_rgb;
	 assign card10_rgb = cards[CARD10 + FLIP_BIT] ? cards[CARD10+:RGB_BITS] : cardback_rgb;
	 assign card11_rgb = cards[CARD11 + FLIP_BIT] ? cards[CARD11+:RGB_BITS] : cardback_rgb;
	 assign card12_rgb = cards[CARD12 + FLIP_BIT] ? cards[CARD12+:RGB_BITS] : cardback_rgb;
	 assign card13_rgb = cards[CARD13 + FLIP_BIT] ? cards[CARD13+:RGB_BITS] : cardback_rgb;
	 assign card14_rgb = cards[CARD14 + FLIP_BIT] ? cards[CARD14+:RGB_BITS] : cardback_rgb;
	 assign card15_rgb = cards[CARD15 + FLIP_BIT] ? cards[CARD15+:RGB_BITS] : cardback_rgb;
	 
	 // Define pixel boundaries where border is on
	 assign border_on = (card_on != 4'd0) && 
							  !((COL0 + BORDER_TH <= pix_x) && (pix_x <= COL0 + CARD_W - BORDER_TH - 1) && (ROW0 + BORDER_TH <= pix_y) && (pix_y <= ROW0 + CARD_H - BORDER_TH - 1)) &&
							  !((COL1 + BORDER_TH <= pix_x) && (pix_x <= COL1 + CARD_W - BORDER_TH - 1) && (ROW0 + BORDER_TH <= pix_y) && (pix_y <= ROW0 + CARD_H - BORDER_TH - 1)) &&
							  !((COL2 + BORDER_TH <= pix_x) && (pix_x <= COL2 + CARD_W - BORDER_TH - 1) && (ROW0 + BORDER_TH <= pix_y) && (pix_y <= ROW0 + CARD_H - BORDER_TH - 1)) &&
							  !((COL3 + BORDER_TH <= pix_x) && (pix_x <= COL3 + CARD_W - BORDER_TH - 1) && (ROW0 + BORDER_TH <= pix_y) && (pix_y <= ROW0 + CARD_H - BORDER_TH - 1)) &&
							  !((COL0 + BORDER_TH <= pix_x) && (pix_x <= COL0 + CARD_W - BORDER_TH - 1) && (ROW1 + BORDER_TH <= pix_y) && (pix_y <= ROW1 + CARD_H - BORDER_TH - 1)) &&
							  !((COL1 + BORDER_TH <= pix_x) && (pix_x <= COL1 + CARD_W - BORDER_TH - 1) && (ROW1 + BORDER_TH <= pix_y) && (pix_y <= ROW1 + CARD_H - BORDER_TH - 1)) &&
							  !((COL2 + BORDER_TH <= pix_x) && (pix_x <= COL2 + CARD_W - BORDER_TH - 1) && (ROW1 + BORDER_TH <= pix_y) && (pix_y <= ROW1 + CARD_H - BORDER_TH - 1)) &&
							  !((COL3 + BORDER_TH <= pix_x) && (pix_x <= COL3 + CARD_W - BORDER_TH - 1) && (ROW1 + BORDER_TH <= pix_y) && (pix_y <= ROW1 + CARD_H - BORDER_TH - 1)) &&
							  !((COL0 + BORDER_TH <= pix_x) && (pix_x <= COL0 + CARD_W - BORDER_TH - 1) && (ROW2 + BORDER_TH <= pix_y) && (pix_y <= ROW2 + CARD_H - BORDER_TH - 1)) &&
							  !((COL1 + BORDER_TH <= pix_x) && (pix_x <= COL1 + CARD_W - BORDER_TH - 1) && (ROW2 + BORDER_TH <= pix_y) && (pix_y <= ROW2 + CARD_H - BORDER_TH - 1)) &&
							  !((COL2 + BORDER_TH <= pix_x) && (pix_x <= COL2 + CARD_W - BORDER_TH - 1) && (ROW2 + BORDER_TH <= pix_y) && (pix_y <= ROW2 + CARD_H - BORDER_TH - 1)) &&
							  !((COL3 + BORDER_TH <= pix_x) && (pix_x <= COL3 + CARD_W - BORDER_TH - 1) && (ROW2 + BORDER_TH <= pix_y) && (pix_y <= ROW2 + CARD_H - BORDER_TH - 1)) &&
							  !((COL0 + BORDER_TH <= pix_x) && (pix_x <= COL0 + CARD_W - BORDER_TH - 1) && (ROW3 + BORDER_TH <= pix_y) && (pix_y <= ROW3 + CARD_H - BORDER_TH - 1)) &&
							  !((COL1 + BORDER_TH <= pix_x) && (pix_x <= COL1 + CARD_W - BORDER_TH - 1) && (ROW3 + BORDER_TH <= pix_y) && (pix_y <= ROW3 + CARD_H - BORDER_TH - 1)) &&
							  !((COL2 + BORDER_TH <= pix_x) && (pix_x <= COL2 + CARD_W - BORDER_TH - 1) && (ROW3 + BORDER_TH <= pix_y) && (pix_y <= ROW3 + CARD_H - BORDER_TH - 1)) &&
							  !((COL3 + BORDER_TH <= pix_x) && (pix_x <= COL3 + CARD_W - BORDER_TH - 1) && (ROW3 + BORDER_TH <= pix_y) && (pix_y <= ROW3 + CARD_H - BORDER_TH - 1));
	 
	 // Define pixel boundaries where cursor is on
	 assign curs_on = ((curs_x <= pix_x) && (pix_x <= curs_x + CURS_W - 1) &&
							(curs_y <= pix_y) && (pix_y <= curs_y + CURS_H - 1))
							&&
							!((curs_x + CURS_TH <= pix_x) && (pix_x <= curs_x + CURS_W - CURS_TH - 1) &&
							(curs_y + CURS_TH <= pix_y) && (pix_y <= curs_y + CURS_H - CURS_TH - 1));
	 
	 // Signals used for turn ROM
//	 wire [5:0] turn_rom_addr;
//	 wire [79:0] turn_rom_data;
//	 wire [6:0] turn_rom_col1, turn_rom_col2;
//	 wire turn_rom_bit1, turn_rom_bit2, player_on;
	 
	 assign p1_on = (P1_X <= pix_x) && (pix_x <= P1_X + P_W - 1) &&
							(P1_Y <= pix_y) && (pix_y <= P1_Y + P_H - 1) && !player;
	 
	 assign p2_on = (P2_X <= pix_x) && (pix_x <= P2_X + P_W - 1) &&
							(P2_Y <= pix_y) && (pix_y <= P2_Y + P_H - 1) && player;
							
//	 assign turn_rom_addr = pix_y - ROW0;
//	 assign turn_rom_col1 = pix_x - P1_X;
//	 assign turn_rom_col2 = pix_x - P2_X;
//	 assign turn_rom_bit1 = turn_rom_data[79-turn_rom_col1];
//	 assign turn_rom_bit2 = turn_rom_data[79-turn_rom_col2];
//	 
//	 assign player_on = (p1_on && turn_rom_bit1) || (p2_on && turn_rom_bit2);
//	 
//	 turn_rom turn_rom_unit(
//	 .clk(clk),
//	 .addr(turn_rom_addr),
//	 .data(turn_rom_data)
//	 );
	 
		 
	 // Combinational logic
	 always @*
	 begin
		curs_x_next = curs_x;
		curs_y_next = curs_y;
		
		if (refr_tick)
			begin
				case (cursor)
					0 : begin curs_x_next = COL0-CURS_TH; curs_y_next = ROW0-CURS_TH; end
					1 : begin curs_x_next = COL1-CURS_TH; curs_y_next = ROW0-CURS_TH; end
					2 : begin curs_x_next = COL2-CURS_TH; curs_y_next = ROW0-CURS_TH; end
					3 : begin curs_x_next = COL3-CURS_TH; curs_y_next = ROW0-CURS_TH; end
					4 : begin curs_x_next = COL0-CURS_TH; curs_y_next = ROW1-CURS_TH; end
					5 : begin curs_x_next = COL1-CURS_TH; curs_y_next = ROW1-CURS_TH; end
					6 : begin curs_x_next = COL2-CURS_TH; curs_y_next = ROW1-CURS_TH; end
					7 : begin curs_x_next = COL3-CURS_TH; curs_y_next = ROW1-CURS_TH; end
					8 : begin curs_x_next = COL0-CURS_TH; curs_y_next = ROW2-CURS_TH; end
					9 : begin curs_x_next = COL1-CURS_TH; curs_y_next = ROW2-CURS_TH; end
					10 : begin curs_x_next = COL2-CURS_TH; curs_y_next = ROW2-CURS_TH; end
					11 : begin curs_x_next = COL3-CURS_TH; curs_y_next = ROW2-CURS_TH; end
					12 : begin curs_x_next = COL0-CURS_TH; curs_y_next = ROW3-CURS_TH; end
					13 : begin curs_x_next = COL1-CURS_TH; curs_y_next = ROW3-CURS_TH; end
					14 : begin curs_x_next = COL2-CURS_TH; curs_y_next = ROW3-CURS_TH; end
					15 : begin curs_x_next = COL3-CURS_TH; curs_y_next = ROW3-CURS_TH; end
				endcase
			end
	 end
	 
	 
	 //-----------------------------------------------------------------------------
	 // rgb multiplexing circuit
	 //-----------------------------------------------------------------------------
	 always @*
		if (~video_on)
			graph_rgb = BKGD_RGB;
		else 
			if (border_on)
				graph_rgb = BORDER_RGB;
			else if (card_on[0])
				graph_rgb = card0_rgb;
			else if (card_on[1])
				graph_rgb = card1_rgb;
			else if (card_on[2])
				graph_rgb = card2_rgb;
			else if (card_on[3])
				graph_rgb = card3_rgb;
			else if (card_on[4])
				graph_rgb = card4_rgb;
			else if (card_on[5])
				graph_rgb = card5_rgb;
			else if (card_on[6])
				graph_rgb = card6_rgb;
			else if (card_on[7])
				graph_rgb = card7_rgb;
			else if (card_on[8])
				graph_rgb = card8_rgb;
			else if (card_on[9])
				graph_rgb = card9_rgb;
			else if (card_on[10])
				graph_rgb = card10_rgb;
			else if (card_on[11])
				graph_rgb = card11_rgb;
			else if (card_on[12])
				graph_rgb = card12_rgb;
			else if (card_on[13])
				graph_rgb = card13_rgb;
			else if (card_on[14])
				graph_rgb = card14_rgb;
			else if (card_on[15])
				graph_rgb = card15_rgb;
			else if (curs_on)
				graph_rgb = CURS_RGB;
			else if (p1_on || p2_on)
				graph_rgb = PLAYER_RGB;
//			else if (player_on)
//				graph_rgb = PLAYER_RGB;
			else if (score1_on)
				graph_rgb = SCORE_RGB;
			else if (score2_on)
				graph_rgb = SCORE_RGB;
			else
				graph_rgb = BKGD_RGB;
				

endmodule
