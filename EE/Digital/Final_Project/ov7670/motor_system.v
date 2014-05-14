`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Bucknell University
// Engineer: Anthony Carno
// 
// Create Date: 04/24/2014 04:12:38 PM
// Design Name: Automated Nerf Gun Turrent
// Module Name: motor_system
// Project Name: Automated Nerf Gun Turrent
// Target Devices: ZedBoard
// Tool Versions: ISE 14.5
// Description: 
//		This module specifies the value of the motor control signals based on the
//	laser location offsets. 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module motor_system(
    input clock,
    input signed [9:0] v_offset,
    input signed [9:0] h_offset,
    input enable,
    output altitude_enable,
    output altitude_up,
    output altitude_down,
    output azimuth_enable,
    output azimuth_left,
    output azimuth_right,
    output fire_enable
    );
    
    // Four state FSM
    localparam  WAITING = 2'b00, //-> Wait for valid data
                H_MOVE  = 2'b01, //-> Move horizontal
                V_MOVE  = 2'b10, //-> Move vertical
                FIRING  = 2'b11; //-> Fire cannon

    
    wire h_move_complete;   //Signal horiz is done
	 wire v_move_complete;   //Signal vert is done
	 wire firing_complete;	 //Signal fire is done
	 
    reg [1:0] current_state = WAITING;   //FSM regs  
    reg [1:0] next_state = WAITING;
    
    wire [9:0] h_offset_abs;    // Absolute values of h- and v-offsets
    wire [9:0] v_offset_abs;
        
     
    /* FSM */
    
    //Absolute values of h- and v-offset (magnitudes)
    assign h_offset_abs = h_offset[9] ? (~h_offset + 10'b1) : h_offset;
    assign v_offset_abs = v_offset[9] ? (~v_offset + 10'b1) : v_offset;
    
    // Next-state logic
    always @ (*) begin
        next_state = current_state;
        
        case (current_state)
            WAITING: begin
                if (enable) next_state = H_MOVE;    //When valid data, start moving
            end
            H_MOVE: begin
                if (h_move_complete) next_state = V_MOVE;   //When horizontal movement over, move vertically
            end
            V_MOVE: begin
                if (v_move_complete) begin      //When vertical movement over, fire or wait for valid data
                    if ((h_offset_abs < 10'd10) && (v_offset_abs < 10'd10))
                        next_state = FIRING;
                    else
                        next_state = WAITING;
                end
            end
            FIRING: begin       //FIRE MISSILE and return to waiting
                if (firing_complete) next_state = WAITING;
            end
            default: next_state = WAITING;                    
        endcase
    end
    
    // For counting period
    reg [29:0] move_counter = 30'd0;
	 reg [29:0] v_move_counter = 30'd0;
	 reg [29:0] h_move_counter = 30'd0;
    
    always @ (posedge clock) begin
        current_state <= next_state;
    end
        
    always @ (posedge clock) begin
        case (current_state)
				WAITING: begin
					h_move_counter <= 30'd0;
					v_move_counter <= 30'd0;
					move_counter <= 30'd0;
				end
            H_MOVE: begin
					h_move_counter <= h_move_counter + 1'b1;
            end
            V_MOVE: begin
					v_move_counter <= v_move_counter + 1'b1;
            end
            FIRING: begin
					move_counter <= move_counter + 1'b1;
            end
            default: begin
					move_counter <= 30'd0;
					h_move_counter <= 30'd0;
					v_move_counter <= 30'd0;
				end
        endcase
     end
     
     assign firing_complete = (move_counter == 30'd500000000); //500,000,000 cycles = 5 s
     assign h_move_complete = (h_move_counter == 30'd10000000);   //10,000,000 cycles = 0.1 s
	  assign v_move_complete = (v_move_counter == 30'd10000000);   //10,000,000 cycles = 0.1 s
     
     assign altitude_enable = (current_state == V_MOVE) && (v_offset_abs > 10); //When to move horizontally
     assign azimuth_enable = (current_state == H_MOVE) && (h_offset_abs > 10); //When to move vertically
     assign fire_enable = (current_state == FIRING);    //Firing nerf gun
     
     assign altitude_up = ~v_offset[9];
     assign altitude_down = v_offset[9];
     assign azimuth_left = h_offset[9];
     assign azimuth_right = ~h_offset[9];
     
endmodule
