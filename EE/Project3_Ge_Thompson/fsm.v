`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Bucknell University
// Engineer: Yifan Ge, Alex Thompson
// 
// Create Date:    17:39:57 04/19/2012 
// Design Name: Memory game FSM
// Module Name:    fsm 
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
module fsm(
	 input wire clk,
	 input wire [7:0] key_in,
	 input wire key_released,
	 input wire ext,
	 output wire [3:0] cursor,
	 output wire [63:0] cards,
	 output wire player,
	 output wire [3:0] matches_p1,
	 output wire [3:0] matches_p2
    );
	 
	 wire loadseed;
	 wire [31:0] seed;
	 wire [31:0] random;
	 wire [5:0] rand_card;
	 
	 rng random_unit(
	 .clk(clk),
	 .reset(1),
	 .loadseed_i(loadseed),
	 .seed_i(seed),
	 .number_o(random)
	 );
	 
	 // Define keyboard scan code constants
	 localparam KEY_ARROW_UP		= 8'h75;
	 localparam KEY_ARROW_DOWN		= 8'h72;
	 localparam KEY_ARROW_LEFT		= 8'h6B;
	 localparam KEY_ARROW_RIGHT	= 8'h74;
	 localparam KEY_ENTER			= 8'h5A;
	 localparam KEY_ESC				= 8'h76;
	 
	 wire arrow_up, arrow_down, arrow_left, arrow_right, enter, esc;
	 assign arrow_up = (key_in == KEY_ARROW_UP) && ext && !key_released;
	 assign arrow_down = (key_in == KEY_ARROW_DOWN) && ext && !key_released;
	 assign arrow_left = (key_in == KEY_ARROW_LEFT) && ext && !key_released;
	 assign arrow_right = (key_in == KEY_ARROW_RIGHT) && ext && !key_released;
	 assign enter = (key_in == KEY_ENTER) && !key_released;
	 assign esc = (key_in == KEY_ESC) && !key_released;
	 
	 // Define other constants
	 localparam CARD_W = 3'd4;	 
	 localparam CARD0 = 0 * CARD_W;
	 localparam CARD1 = 1 * CARD_W;
	 localparam CARD2 = 2 * CARD_W;
	 localparam CARD3 = 3 * CARD_W;
	 localparam CARD4 = 4 * CARD_W;
	 localparam CARD5 = 5 * CARD_W;
	 localparam CARD6 = 6 * CARD_W;
	 localparam CARD7 = 7 * CARD_W;
	 localparam CARD8 = 8 * CARD_W;
	 localparam CARD9 = 9 * CARD_W;
	 localparam CARD10 = 10 * CARD_W;
	 localparam CARD11 = 11 * CARD_W;
	 localparam CARD12 = 12 * CARD_W;
	 localparam CARD13 = 13 * CARD_W;
	 localparam CARD14 = 14 * CARD_W;
	 localparam CARD15 = 15 * CARD_W;
	 
	 localparam FLIP_BIT = CARD_W - 1; // The bit of each card that indicates if its flipped
	 localparam MAX_MATCHES = 4'd8;
	 localparam FLIP_WAIT = 60;
	 
	 // Define state constants
	 localparam STATE_STARTUP 		= 3'd0;
	 localparam STATE_RANDOMIZE	= 3'd1;
	 localparam STATE_SELECTION 	= 3'd2;
	 localparam STATE_FLIP 			= 3'd3;
	 localparam STATE_MATCH 		= 3'd4;
	 localparam STATE_RESET			= 3'd5;
	 localparam STATE_WAIT			= 3'd6;
	 
	 // Define state registers
	 reg [2:0] state, next_state;
	 reg [5:0] cursor_reg, next_cursor;
	 reg [63:0] cards_reg, next_cards;
	 reg player_reg, next_player;
	 reg [3:0] matches_p1_reg, next_matches_p1;
	 reg [3:0] matches_p2_reg, next_matches_p2;
	 reg flips, next_flips;
	 reg [5:0] last_flipped, next_flipped;
	 reg [25:0] time_flipped, next_time;
	 reg [4:0] image, next_image;
	 reg loadseed_reg, next_loadseed;
	 reg [31:0] seed_reg, next_seed;
	 
	 // Initialize
	 initial begin
		state 			= STATE_STARTUP;
		cursor_reg 		= CARD0;
		cards_reg		= 64'd0;
		player_reg		= 1'b0;
		matches_p1_reg	= 4'd0;
		matches_p2_reg	= 4'd0;
		flips 			= 1'b0;
		last_flipped 	= CARD0;
		time_flipped	= 26'd0;
		image				= 5'd0;
		loadseed_reg	= 1'b0;
		seed_reg			= 32'd0;
	 end
	 
	 // State Transition Logic
	 always @ *
	 begin
	 
		// Default logic
		next_state 		= state;
		next_cursor 	= cursor_reg;
		next_cards		= cards;
		next_player		= player_reg;
		next_matches_p1= matches_p1_reg;
		next_matches_p2= matches_p2_reg;
		next_flips 		= flips;
		next_flipped 	= last_flipped;
		next_time		= time_flipped;
		next_image		= image;
		next_loadseed	= loadseed;
		next_seed		= seed_reg;
	 
		case (state)
						
			STATE_STARTUP: begin
				// Set initial values
				next_state 						= STATE_SELECTION;
				next_cards[CARD0+:CARD_W]	= 4'b1000;
				next_cards[CARD1+:CARD_W]	= 4'b1000;
				next_cards[CARD2+:CARD_W]	= 4'b1000;
				next_cards[CARD3+:CARD_W]	= 4'b1000;
				next_cards[CARD4+:CARD_W]	= 4'b1000;
				next_cards[CARD5+:CARD_W]	= 4'b1000;
				next_cards[CARD6+:CARD_W]	= 4'b1000;
				next_cards[CARD7+:CARD_W]	= 4'b1000;
				next_cards[CARD8+:CARD_W]	= 4'b1000;
				next_cards[CARD9+:CARD_W]	= 4'b1000;
				next_cards[CARD10+:CARD_W]	= 4'b1000;
				next_cards[CARD11+:CARD_W]	= 4'b1000;
				next_cards[CARD12+:CARD_W]	= 4'b1000;
				next_cards[CARD13+:CARD_W]	= 4'b1000;
				next_cards[CARD14+:CARD_W]	= 4'b1000;
				next_cards[CARD15+:CARD_W]	= 4'b1000;
				next_player						= 1'b0;
				next_matches_p1				= 4'd0;
				next_matches_p2				= 4'd0;
				next_flips 						= 1'b0;
				next_time						= 26'd0;
				next_image						= 5'd0;
				next_loadseed					= 1'b0;
				next_seed						= 32'd0;
				if (enter)
					next_state = STATE_RANDOMIZE;
				else
					begin
					next_state = STATE_STARTUP;
					next_seed = seed_reg + 1;
					next_loadseed = 1'b1;
					end
				
			end
			
			STATE_RANDOMIZE: begin
				next_loadseed = 1'b0;
				if (image == 5'b10000)
					next_state =  STATE_SELECTION;
				else
					begin
						next_state = STATE_RANDOMIZE;
						if (cards_reg[rand_card + FLIP_BIT])
							begin
							case (rand_card)
								CARD0: next_cards[CARD0+:CARD_W] = {1'b0,image[2:0]};
								CARD1: next_cards[CARD1+:CARD_W] = {1'b0,image[2:0]};
								CARD2: next_cards[CARD2+:CARD_W] = {1'b0,image[2:0]};
								CARD3: next_cards[CARD3+:CARD_W] = {1'b0,image[2:0]};
								CARD4: next_cards[CARD4+:CARD_W] = {1'b0,image[2:0]};
								CARD5: next_cards[CARD5+:CARD_W] = {1'b0,image[2:0]};
								CARD6: next_cards[CARD6+:CARD_W] = {1'b0,image[2:0]};
								CARD7: next_cards[CARD7+:CARD_W] = {1'b0,image[2:0]};
								CARD8: next_cards[CARD8+:CARD_W] = {1'b0,image[2:0]};
								CARD9: next_cards[CARD9+:CARD_W] = {1'b0,image[2:0]};
								CARD10: next_cards[CARD10+:CARD_W] = {1'b0,image[2:0]};
								CARD11: next_cards[CARD11+:CARD_W] = {1'b0,image[2:0]};
								CARD12: next_cards[CARD12+:CARD_W] = {1'b0,image[2:0]};
								CARD13: next_cards[CARD13+:CARD_W] = {1'b0,image[2:0]};
								CARD14: next_cards[CARD14+:CARD_W] = {1'b0,image[2:0]};
								CARD15: next_cards[CARD15+:CARD_W] = {1'b0,image[2:0]};
							endcase
							next_image = image + 1;
							end
					end
			end
			
			STATE_SELECTION: begin
				// Check if each button is pressed and move cursor accordingly
				if (arrow_up)
					begin
						// Enter wait state next so arrow keys dont get read more than once
						next_state = STATE_WAIT;
						case (cursor_reg)
							CARD0: next_cursor = cursor_reg;
							CARD1: next_cursor = cursor_reg;
							CARD2: next_cursor = cursor_reg;
							CARD3: next_cursor = cursor_reg;
							CARD4: next_cursor = CARD0;
							CARD5: next_cursor = CARD1;
							CARD6: next_cursor = CARD2;
							CARD7: next_cursor = CARD3;
							CARD8: next_cursor = CARD4;
							CARD9: next_cursor = CARD5;
							CARD10: next_cursor = CARD6;
							CARD11: next_cursor = CARD7;
							CARD12: next_cursor = CARD8;
							CARD13: next_cursor = CARD9;
							CARD14: next_cursor = CARD10;
							CARD15: next_cursor = CARD11;
						endcase
					end
					
				else if (arrow_down)
					begin
						next_state = STATE_WAIT;
						case (cursor_reg)
							CARD0: next_cursor = CARD4;
							CARD1: next_cursor = CARD5;
							CARD2: next_cursor = CARD6;
							CARD3: next_cursor = CARD7;
							CARD4: next_cursor = CARD8;
							CARD5: next_cursor = CARD9;
							CARD6: next_cursor = CARD10;
							CARD7: next_cursor = CARD11;
							CARD8: next_cursor = CARD12;
							CARD9: next_cursor = CARD13;
							CARD10: next_cursor = CARD14;
							CARD11: next_cursor = CARD15;
							CARD12: next_cursor = cursor_reg;
							CARD13: next_cursor = cursor_reg;
							CARD14: next_cursor = cursor_reg;
							CARD15: next_cursor = cursor_reg;
						endcase
					end
					
				else if (arrow_left)
					begin
						next_state = STATE_WAIT;
						case (cursor_reg)
							CARD0: next_cursor = cursor_reg;
							CARD1: next_cursor = CARD0;
							CARD2: next_cursor = CARD1;
							CARD3: next_cursor = CARD2;
							CARD4: next_cursor = cursor_reg;
							CARD5: next_cursor = CARD4;
							CARD6: next_cursor = CARD5;
							CARD7: next_cursor = CARD6;
							CARD8: next_cursor = cursor_reg;
							CARD9: next_cursor = CARD8;
							CARD10: next_cursor = CARD9;
							CARD11: next_cursor = CARD10;
							CARD12: next_cursor = cursor_reg;
							CARD13: next_cursor = CARD12;
							CARD14: next_cursor = CARD13;
							CARD15: next_cursor = CARD14;
						endcase
					end
					
				else if (arrow_right)
					begin
						next_state = STATE_WAIT;
						case (cursor_reg)
							CARD0: next_cursor = CARD1;
							CARD1: next_cursor = CARD2;
							CARD2: next_cursor = CARD3;
							CARD3: next_cursor = cursor_reg;
							CARD4: next_cursor = CARD5;
							CARD5: next_cursor = CARD6;
							CARD6: next_cursor = CARD7;
							CARD7: next_cursor = cursor_reg;
							CARD8: next_cursor = CARD9;
							CARD9: next_cursor = CARD10;
							CARD10: next_cursor = CARD11;
							CARD11: next_cursor = cursor_reg;
							CARD12: next_cursor = CARD13;
							CARD13: next_cursor = CARD14;
							CARD14: next_cursor = CARD15;
							CARD15: next_cursor = cursor_reg;
						endcase
					end
				
				// If ENTER is pressed and the selected card is not flipped, flip it
				else if (enter && !cards_reg[cursor_reg + FLIP_BIT])
					next_state = STATE_FLIP;
					
				else if (esc)
					next_state = STATE_RESET;
			end
			
			STATE_FLIP: begin
				// Don't flip cards until enter has been released
				if (!enter)
					begin
					next_cards[cursor_reg + FLIP_BIT] = 1'b1;
					// If no cards have been flipped yet, save the current card as last flipped and return to selection
					if (flips == 0)
						begin
						next_state = STATE_SELECTION;
						next_flips = 1'b1;
						next_flipped = cursor_reg;
						end
					// Otherwise, one card has already been flipped
					else
						begin
						// Next state will always return to zero cards flipped, whether a match is found or not
						// If the flipped card matches the last flipped card, it's a match. Don't switch players
						if (cards_reg[last_flipped+:CARD_W] == cards_reg[cursor_reg+:CARD_W])
							begin
							next_state = STATE_MATCH;
							case (player_reg)
								0 : next_matches_p1 = matches_p1_reg + 1;
								1 : next_matches_p2 = matches_p2_reg + 1;
							endcase							
							next_flips = 1'b0;	
							end
						// Otherwise, return to selecting cards and flip the current and last flipped cards back over
						else
							begin
							// Only flip back over once the wait time is reached
							if (time_flipped == FLIP_WAIT)
								begin
								next_state = STATE_SELECTION;
								next_cards[last_flipped + FLIP_BIT] = 1'b0;
								next_cards[cursor_reg + FLIP_BIT] = 1'b0;
								next_flips = 1'b0;
								next_time = 26'd0;
								// Switch players
								next_player = !player_reg;
								end
							else
								begin
								next_state = STATE_FLIP;
								next_time = time_flipped + 1;
								end
							end
						end
					end
			end
			
			STATE_MATCH: begin
				// If all matches have been found, return to startup
				if (matches_p1_reg + matches_p2_reg == MAX_MATCHES)
					next_state = STATE_RESET;					
				// Otherwise, return to selecting cards
				else
					next_state = STATE_SELECTION;
			end
			
			STATE_RESET: begin
				if (esc)
					next_state = STATE_STARTUP;
				else
					next_state = STATE_RESET;
			end
			
			STATE_WAIT: begin
				if (arrow_up || arrow_down || arrow_left || arrow_right)
					next_state = STATE_WAIT;
				else
					next_state = STATE_SELECTION;
			end
		endcase
	end
	
	always @ (posedge clk)
	begin
		// Advance state values to next state
		state <= next_state;
		cursor_reg <= next_cursor;
		cards_reg <= next_cards;
		player_reg <= next_player;
		matches_p1_reg <= next_matches_p1;
		matches_p2_reg <= next_matches_p2;
		flips <= next_flips;
		last_flipped <= next_flipped;
		time_flipped <= next_time;
		image <= next_image;
		loadseed_reg <= next_loadseed;
		seed_reg <= next_seed;
	end
	
	// Assign registers to output
	assign cursor = cursor_reg / CARD_W;
	assign cards = cards_reg;
	assign player = player_reg;
	assign matches_p1 = matches_p1_reg;
	assign matches_p2 = matches_p2_reg;
	assign loadseed = loadseed_reg;
	assign seed = seed_reg;
	assign rand_card = random[3:0] * 4;

endmodule
