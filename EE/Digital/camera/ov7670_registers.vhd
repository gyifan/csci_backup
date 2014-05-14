----------------------------------------------------------------------------------
-- Company: 
-- Engineer: Mike Field <hamster@sanp.net.nz> 
-- 
-- Description: Register settings for the OV7670 Caamera (partially from OV7670.c
--              in the Linux Kernel
------------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity ov7670_registers is
    Port ( clk      : in  STD_LOGIC;
           resend   : in  STD_LOGIC;
           advance  : in  STD_LOGIC;
           command  : out  std_logic_vector(15 downto 0);
           finished : out  STD_LOGIC);
end ov7670_registers;

architecture Behavioral of ov7670_registers is
	signal sreg   : std_logic_vector(15 downto 0);
	signal address : std_logic_vector(7 downto 0) := (others => '0');
begin
	command <= sreg;
	with sreg select finished  <= '1' when x"FFFF", '0' when others;
	
	process(clk)
	begin
		if rising_edge(clk) then
			if resend = '1' then 
				address <= (others => '0');
			elsif advance = '1' then
				address <= std_logic_vector(unsigned(address)+1);
			end if;


			case address is
				when x"00" => sreg <= x"1280"; -- COM7   Reset
				when x"01" => sreg <= x"1280"; -- COM7   Reset
				when x"02" => sreg <= x"1204"; -- COM7   Size & RGB output
				when x"03" => sreg <= x"1100"; -- CLKRC  Prescaler - Fin/(1+1)
				when x"04" => sreg <= x"0C00"; -- COM3   Lots of stuff, enable scaling, all others off
				when x"05" => sreg <= x"3E00"; -- COM14  PCLK scaling off
				
   			when x"06" => sreg <= x"8C00"; -- RGB444 Set RGB format
   			when x"07" => sreg <= x"0400"; -- COM1   no CCIR601
 				when x"08" => sreg <= x"40D0"; -- COM15  Full 0-255 output, RGB 565
				when x"09" => sreg <= x"3a04"; -- TSLB   Set UV ordering,  do not auto-reset window
				when x"0A" => sreg <= x"1438"; -- COM9  - AGC Celling
				when x"0B" => sreg <= x"4fb3"; -- MTX1  - colour conversion matrix original b3 v-red
				when x"0C" => sreg <= x"50b3"; -- MTX2  - colour conversion matrix original b3 v-green
				when x"0D" => sreg <= x"5100"; -- MTX3  - colour conversion matrix original 00 v-blue
				when x"0E" => sreg <= x"523d"; -- MTX4  - colour conversion matrix original 3d u-red
				when x"0F" => sreg <= x"53a7"; -- MTX5  - colour conversion matrix original a7 u-green
				when x"10" => sreg <= x"54e4"; -- MTX6  - colour conversion matrix original e4 u-blue
				when x"11" => sreg <= x"589e"; -- MTXS  - Matrix sign and auto contrast original 9e
				when x"12" => sreg <= x"3dc0"; -- COM13 - Turn on GAMMA and UV Auto adjust
				when x"13" => sreg <= x"1100"; -- CLKRC  Prescaler - Fin/(1+1)
				
				when x"14" => sreg <= x"1711"; -- HSTART HREF start (high 8 bits)
				when x"15" => sreg <= x"1861"; -- HSTOP  HREF stop (high 8 bits)
				when x"16" => sreg <= x"32A4"; -- HREF   Edge offset and low 3 bits of HSTART and HSTOP
				
				when x"17" => sreg <= x"1903"; -- VSTART VSYNC start (high 8 bits)
				when x"18" => sreg <= x"1A7b"; -- VSTOP  VSYNC stop (high 8 bits) 
				when x"19" => sreg <= x"030a"; -- VREF   VSYNC low two bits
				
				when x"1A" => sreg <= x"703a";
				when x"1B" => sreg <= x"7135";
				when x"1C" => sreg <= x"7211";
				when x"1D" => sreg <= x"73F0";
				when x"1E" => sreg <= x"A201";
				when x"1F" => sreg <= x"1500";
				
--				when x"20" => sreg <= x"7a20";
--				when x"21" => sreg <= x"7b10";
--				when x"22" => sreg <= x"7c1e";
--				when x"23" => sreg <= x"7d35";
--				when x"24" => sreg <= x"7e5a";
--				when x"25" => sreg <= x"7f69";
--				when x"26" => sreg <= x"8076";
--				when x"27" => sreg <= x"8180";
--				when x"28" => sreg <= x"8288";
--				when x"29" => sreg <= x"838f";
--				when x"2A" => sreg <= x"8496";
--				when x"2B" => sreg <= x"85a3";
--				when x"2C" => sreg <= x"86af";
--				when x"2D" => sreg <= x"87c4";
--				when x"2E" => sreg <= x"88d7";
--				when x"2F" => sreg <= x"89e8";
				
				--adds color
				when x"20" => sreg <= x"13c0";
				when x"21" => sreg <= x"0000";
				when x"22" => sreg <= x"1000";
				when x"23" => sreg <= x"0d40";
				when x"24" => sreg <= x"a505";
				when x"25" => sreg <= x"ab07";
				when x"26" => sreg <= x"2495";
				when x"27" => sreg <= x"2533";
				when x"28" => sreg <= x"26e3";
				when x"29" => sreg <= x"9f78";
				when x"2A" => sreg <= x"a068";
				when x"2B" => sreg <= x"a103";
				when x"2C" => sreg <= x"a6d8";
				when x"2D" => sreg <= x"a7d8";
				when x"2E" => sreg <= x"a8f0";
				when x"2F" => sreg <= x"a990";
				when x"30" => sreg <= x"aa94";
				when x"31" => sreg <= x"13c5";
				when x"32" => sreg <= x"3000";
				when x"33" => sreg <= x"3100";
				
				--also adds color (magic reserved values)
				when x"34" => sreg <= x"0e61";
				when x"35" => sreg <= x"0f4b";
				when x"36" => sreg <= x"1602";
				when x"37" => sreg <= x"1e07";
				when x"38" => sreg <= x"2102";
				when x"39" => sreg <= x"2291";
				when x"3a" => sreg <= x"2907";
				when x"3b" => sreg <= x"330b";
				when x"3c" => sreg <= x"350b";
				when x"3d" => sreg <= x"371d";
				when x"3e" => sreg <= x"3871";
				when x"3f" => sreg <= x"392a";
				when x"40" => sreg <= x"3c78";
				when x"41" => sreg <= x"4d40";
				when x"42" => sreg <= x"4e20";
				when x"43" => sreg <= x"6900";
				when x"44" => sreg <= x"7410";
				when x"45" => sreg <= x"8d4f";
				when x"46" => sreg <= x"8e00";
				when x"47" => sreg <= x"8f00";
				when x"48" => sreg <= x"9000";
				when x"49" => sreg <= x"9100";
				when x"4a" => sreg <= x"9600";
				when x"4b" => sreg <= x"9a00";
				when x"4c" => sreg <= x"b084";
				when x"4d" => sreg <= x"b10c";
				when x"4e" => sreg <= x"b20e";
				when x"4f" => sreg <= x"b382";
				when x"50" => sreg <= x"b80a";
				
				--less yellow
				when x"51" => sreg <= x"430a";
				when x"52" => sreg <= x"44f0";
				when x"53" => sreg <= x"4534";
				when x"54" => sreg <= x"4658";
				when x"55" => sreg <= x"4728";
				when x"56" => sreg <= x"483a";
				when x"57" => sreg <= x"5988";
				when x"58" => sreg <= x"5a88";
				when x"59" => sreg <= x"5b44";
				when x"5a" => sreg <= x"5c67";
				when x"5b" => sreg <= x"5d49";
				when x"5c" => sreg <= x"5e0e";
				when x"5d" => sreg <= x"6c0a";
				when x"5e" => sreg <= x"6d55";
				when x"5f" => sreg <= x"6e11";
				when x"60" => sreg <= x"6f9e";
				when x"61" => sreg <= x"6a40";
				when x"62" => sreg <= x"0140";
				when x"63" => sreg <= x"0260";
				when x"64" => sreg <= x"13c7";
				
				
				--darkens
				when x"65" => sreg <= x"4108";
				when x"66" => sreg <= x"3f00";
				when x"67" => sreg <= x"7505";
				when x"68" => sreg <= x"76e1";
				when x"69" => sreg <= x"4c00";
				when x"6a" => sreg <= x"7701";
				when x"6b" => sreg <= x"3d48";
				when x"6c" => sreg <= x"4b09";
				when x"6d" => sreg <= x"c960";
				when x"6e" => sreg <= x"5640";
				
--				when x"7f" => sreg <= x"3411";
--				when x"80" => sreg <= x"3b12";
--				when x"81" => sreg <= x"a482";
--				when x"82" => sreg <= x"9600";
--				when x"83" => sreg <= x"9730";
--				when x"84" => sreg <= x"9820";
--				when x"85" => sreg <= x"9930";
--				when x"86" => sreg <= x"9a84";
--				when x"87" => sreg <= x"9b29";
--				when x"88" => sreg <= x"9c03";
--				when x"89" => sreg <= x"9d4c";
--				when x"8a" => sreg <= x"9e3f";
--				when x"8b" => sreg <= x"7804";
				
--				when x"8c" => sreg <= x"7901";
--				when x"8d" => sreg <= x"c8f0";
--				when x"8e" => sreg <= x"790f";
--				when x"8f" => sreg <= x"c800";
--				when x"90" => sreg <= x"7910";
--				when x"91" => sreg <= x"c87e";
--				when x"92" => sreg <= x"790a";
--				when x"93" => sreg <= x"c880";
--				when x"94" => sreg <= x"790b";
--				when x"95" => sreg <= x"c801";
--				when x"96" => sreg <= x"790c";
--				when x"97" => sreg <= x"c80f";
--				when x"98" => sreg <= x"790d";
--				when x"99" => sreg <= x"c820";
--				when x"9a" => sreg <= x"7909";
--				when x"9b" => sreg <= x"c880";
--				when x"9c" => sreg <= x"7902";
--				when x"9d" => sreg <= x"c8c0";
--				when x"9e" => sreg <= x"7903";
--				when x"9f" => sreg <= x"c840";
--				when x"a0" => sreg <= x"7905";
--				when x"a1" => sreg <= x"c830";
--				when x"a2" => sreg <= x"7926";
				
				
				
--        WriteReg(0x4f,0x80);
--        WriteReg(0x50,0x80);
--        WriteReg(0x51,0x00);
--        WriteReg(0x52,0x22);
--        WriteReg(0x53,0x5e);
--        WriteReg(0x54,0x80);
--        WriteReg(0x56,0x40);
--        WriteReg(0x58,0x9e);
--        WriteReg(0x59,0x88);
--        WriteReg(0x5a,0x88);
--        WriteReg(0x5b,0x44);
--        WriteReg(0x5c,0x67);
--        WriteReg(0x5d,0x49);
--        WriteReg(0x5e,0x0e);
--        WriteReg(0x69,0x00);
--        WriteReg(0x6a,0x40);
--        WriteReg(0x6b,0x0a);
--        WriteReg(0x6c,0x0a);
--        WriteReg(0x6d,0x55);
--        WriteReg(0x6e,0x11);
--        WriteReg(0x6f,0x9f);
				
--				when x"1A" => sreg <= x"5640";
--				when x"1B" => sreg <= x"5988";
--				when x"1C" => sreg <= x"5a88";
--				when x"1D" => sreg <= x"5b44";
--				when x"1E" => sreg <= x"5c67";
--				when x"1F" => sreg <= x"5d49";
--				when x"20" => sreg <= x"5e0e";
--				when x"21" => sreg <= x"6900";
--				when x"22" => sreg <= x"6a40";
--				when x"23" => sreg <= x"6b0a";
--				when x"24" => sreg <= x"6c0a";
--				when x"25" => sreg <= x"6d55";
--				when x"26" => sreg <= x"6e11";
--				when x"27" => sreg <= x"6f9f";
				
--				WriteReg(0xb0,0x84);
				
--				when x"28" => sreg <= x"b084";
			
--				when x"10" => sreg <= x"703a"; -- SCALING_XSC
--				when x"11" => sreg <= x"7135"; -- SCALING_YSC
--				when x"12" => sreg <= x"7200"; -- SCALING_DCWCTR  -- zzz was 11 
--				when x"13" => sreg <= x"7300"; -- SCALING_PCLK_DIV
--				when x"14" => sreg <= x"a200"; -- SCALING_PCLK_DELAY  must match COM14
--          when x"15" => sreg <= x"1500"; -- COM10 Use HREF not hSYNC
--				
--				when x"1D" => sreg <= x"B104"; -- ABLC1 - Turn on auto black level
--				when x"1F" => sreg <= x"138F"; -- COM8  - AGC, White balance
--				when x"21" => sreg <= x"FFFF"; -- spare
--				when x"22" => sreg <= x"FFFF"; -- spare
--				when x"23" => sreg <= x"0000"; -- spare
--				when x"24" => sreg <= x"0000"; -- spare
--				when x"25" => sreg <= x"138F"; -- COM8 - AGC, White balance
--				when x"26" => sreg <= x"0000"; -- spare
--				when x"27" => sreg <= x"1000"; -- AECH Exposure
--				when x"28" => sreg <= x"0D40"; -- COMM4 - Window Size
--				when x"29" => sreg <= x"0000"; -- spare
--				when x"2a" => sreg <= x"a505"; -- AECGMAX banding filter step
--				when x"2b" => sreg <= x"2495"; -- AEW AGC Stable upper limite
--				when x"2c" => sreg <= x"2533"; -- AEB AGC Stable lower limi
--				when x"2d" => sreg <= x"26e3"; -- VPT AGC fast mode limits
--				when x"2e" => sreg <= x"9f78"; -- HRL High reference level
--				when x"2f" => sreg <= x"A068"; -- LRL low reference level
--				when x"30" => sreg <= x"a103"; -- DSPC3 DSP control
--				when x"31" => sreg <= x"A6d8"; -- LPH Lower Prob High
--				when x"32" => sreg <= x"A7d8"; -- UPL Upper Prob Low
--				when x"33" => sreg <= x"A8f0"; -- TPL Total Prob Low
--				when x"34" => sreg <= x"A990"; -- TPH Total Prob High
--				when x"35" => sreg <= x"AA94"; -- NALG AEC Algo select
--				when x"36" => sreg <= x"13E5"; -- COM8 AGC Settings
				when others => sreg <= x"ffff";
			end case;
		end if;
	end process;
end Behavioral;

