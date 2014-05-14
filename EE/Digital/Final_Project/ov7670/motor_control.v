`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/24/2014 10:43:23 AM
// Design Name: 
// Module Name: motor_control
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module motor_controller(
    input clock,
    input [3:0] speed,
    input enable,
    output pwm_signal
    );
    
    parameter   MOVE_0 = 4'b0000,
                MOVE_10 = 4'b0001,
                MOVE_20 = 4'b0010,
                MOVE_30 = 4'b0011,
                MOVE_40 = 4'b0100,
                MOVE_50 = 4'b0101,
                MOVE_60 = 4'b0110,
                MOVE_70 = 4'b0111,
                MOVE_80 = 4'b1000,
                MOVE_90 = 4'b1001,
                MOVE_100 = 4'b1010;
    
    wire [15:0] match_value;
    
    /* Choose speed by modifying high time of PWM signal */
    assign match_value =    (speed == MOVE_0) ? 16'd0 :
                            (speed ==  MOVE_10) ? 16'd2500 :
                            (speed ==  MOVE_20) ? 16'd5000 :
                            (speed ==  MOVE_30) ? 16'd7500 :
                            (speed ==  MOVE_40) ? 16'd10000 :
                            (speed ==  MOVE_50) ? 16'd12500 :
                            (speed ==  MOVE_60) ? 16'd15000 :
                            (speed ==  MOVE_70) ? 16'd17500 :
                            (speed ==  MOVE_80) ? 16'd20000 :
                            (speed ==  MOVE_90) ? 16'd22500 :
                            (speed ==  MOVE_100) ? 16'd25000 : 16'd0;
    
//    always @ (*) begin
//        match_value = 16'd0;
//        case (speed)
//            MOVE_0: match_value = 16'd0;
//            MOVE_10: match_value = 16'd2500;
//            MOVE_20: match_value = 16'd5000;
//            MOVE_30: match_value = 16'd7500;
//            MOVE_40: match_value = 16'd10000;
//            MOVE_50: match_value = 16'd12500;
//            MOVE_60: match_value = 16'd15000;
//            MOVE_70: match_value = 16'd17500;
//            MOVE_80: match_value = 16'd20000;
//            MOVE_90: match_value = 16'd22500;
//            MOVE_100: match_value = 16'd25000;
//            default: match_value = 16'd0;
//        endcase
//    end
    
    PWM pwm0 (
        .clock(clock),
        .enable(enable),
        .match_value(match_value),
        .signal(pwm_signal)
        );
    
endmodule
