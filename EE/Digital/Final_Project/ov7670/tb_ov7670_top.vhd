--------------------------------------------------------------------------------
-- Engineer:
-- Description:   
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY tb_ov7670_top IS
END tb_ov7670_top;
 
ARCHITECTURE behavior OF tb_ov7670_top IS 
    COMPONENT ov7670_top
    PORT(
         clk100 : IN  std_logic;
         OV7670_SIOC : OUT  std_logic;
         OV7670_SIOD : INOUT  std_logic;
         OV7670_RESET : OUT  std_logic;
         OV7670_PWDN : OUT  std_logic;
         OV7670_VSYNC : IN  std_logic;
         OV7670_HREF : IN  std_logic;
         OV7670_PCLK : IN  std_logic;
         OV7670_XCLK : OUT  std_logic;
         OV7670_D : IN  std_logic_vector(7 downto 0);
         vga_red : OUT  std_logic_vector(3 downto 0);
         vga_green : OUT  std_logic_vector(3 downto 0);
         vga_blue : OUT  std_logic_vector(3 downto 0);
         vga_hsync : OUT  std_logic;
         vga_vsync : OUT  std_logic;
			btn : IN  std_logic
        );
    END COMPONENT;
   --Inputs
   signal clk100 : std_logic := '0';
   signal OV7670_VSYNC : std_logic := '0';
   signal OV7670_HREF : std_logic := '0';
   signal OV7670_PCLK : std_logic := '0';
   signal OV7670_XCLK : std_logic := '0';
   signal OV7670_D : std_logic_vector(7 downto 0) := (others => '0');

	--BiDirs
   signal OV7670_SIOD : std_logic;

 	--Outputs
   signal OV7670_SIOC : std_logic;
   signal OV7670_RESET : std_logic;
   signal OV7670_PWDN : std_logic;
   signal vga_red : std_logic_vector(3 downto 0);
   signal vga_green : std_logic_vector(3 downto 0);
   signal vga_blue : std_logic_vector(3 downto 0);
   signal vga_hsync : std_logic;
   signal vga_vsync : std_logic;

   -- Clock period definitions
   constant clk100_period : time := 10 ns; 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ov7670_top PORT MAP (
          clk100 => clk100,
          OV7670_SIOC => OV7670_SIOC,
          OV7670_SIOD => OV7670_SIOD,
          OV7670_RESET => OV7670_RESET,
          OV7670_PWDN => OV7670_PWDN,
          OV7670_VSYNC => OV7670_VSYNC,
          OV7670_HREF => OV7670_HREF,
          OV7670_PCLK => OV7670_PCLK,
          OV7670_XCLK => OV7670_XCLK,
          OV7670_D => OV7670_D,
          vga_red => vga_red,
          vga_green => vga_green,
          vga_blue => vga_blue,
          vga_hsync => vga_hsync,
          vga_vsync => vga_vsync,
			 btn => '0'
        );

   -- Clock process definitions
   clk50_process :process
   begin
		clk100 <= '0';
		wait for clk100_period/2;
		clk100 <= '1';
		wait for clk100_period/2;
   end process;

   OV7670_PCLK_process :process
   begin
      wait for 5 ns;
		OV7670_PCLK <= '0';
		wait for clk100_period*2;
		OV7670_PCLK <= '1';
		wait for clk100_period*2 - 5 ns;
   end process;
 
	
END;
