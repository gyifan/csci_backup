`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/24/2014 09:36:03 AM
// Design Name: 
// Module Name: PWM
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


module PWM(
    input clock,
    input enable,
    input [15:0] match_value,
    output signal
    );
    
    /* Assume 100 MHz clock */
    /* Creating 4 kHz PWM signal */ 
    reg [15:0] interval_counter = 16'd0;
    always @ (posedge clock) begin
        if (enable) begin
            if (interval_counter == 16'd25000)  interval_counter <= 16'd0;
            else                                interval_counter <= interval_counter + 1'b1;
        end
        else interval_counter <= 16'd0;
    end
    
    assign signal = enable && (interval_counter < match_value);
    
endmodule
