/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

#include "xsi.h"

struct XSI_INFO xsi_info;

char *IEEE_P_2592010699;
char *STD_STANDARD;
char *STD_TEXTIO;
char *IEEE_P_3499444699;
char *IEEE_P_3620187407;
char *IEEE_P_1242562249;
char *UNISIM_P_0947159679;
char *VL_P_2533777724;
char *IEEE_P_3564397177;
char *IEEE_P_0774719531;
char *IEEE_P_2717149903;
char *IEEE_P_1367372525;
char *UNISIM_P_3222816464;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000004134447467_2073120511_init();
    work_m_00000000004062727878_2483525352_init();
    work_m_00000000003681209942_0029414236_init();
    ieee_p_2592010699_init();
    unisim_p_0947159679_init();
    ieee_p_1242562249_init();
    vl_p_2533777724_init();
    ieee_p_3499444699_init();
    ieee_p_3620187407_init();
    work_a_1585794704_3212880686_init();
    std_textio_init();
    ieee_p_3564397177_init();
    xilinxcorelib_a_1926568272_2959432447_init();
    xilinxcorelib_a_0013775584_1709443946_init();
    xilinxcorelib_a_3437865443_0543512595_init();
    xilinxcorelib_a_1118597326_3212880686_init();
    work_a_1467251916_1877245857_init();
    work_a_2205409629_3212880686_init();
    work_a_2902097263_3212880686_init();
    work_a_2681524712_3212880686_init();
    work_a_0947052234_3212880686_init();
    ieee_p_0774719531_init();
    ieee_p_2717149903_init();
    ieee_p_1367372525_init();
    unisim_p_3222816464_init();
    unisim_a_0780662263_2014779070_init();
    unisim_a_2776836208_0558579079_init();
    unisim_a_1490675510_1976025627_init();
    work_a_4015317117_0912031422_init();
    work_a_4042436569_3212880686_init();
    work_a_1057543176_2372691052_init();


    xsi_register_tops("work_a_1057543176_2372691052");
    xsi_register_tops("work_m_00000000004134447467_2073120511");

    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    STD_STANDARD = xsi_get_engine_memory("std_standard");
    STD_TEXTIO = xsi_get_engine_memory("std_textio");
    IEEE_P_3499444699 = xsi_get_engine_memory("ieee_p_3499444699");
    IEEE_P_3620187407 = xsi_get_engine_memory("ieee_p_3620187407");
    IEEE_P_1242562249 = xsi_get_engine_memory("ieee_p_1242562249");
    UNISIM_P_0947159679 = xsi_get_engine_memory("unisim_p_0947159679");
    VL_P_2533777724 = xsi_get_engine_memory("vl_p_2533777724");
    IEEE_P_3564397177 = xsi_get_engine_memory("ieee_p_3564397177");
    IEEE_P_0774719531 = xsi_get_engine_memory("ieee_p_0774719531");
    IEEE_P_2717149903 = xsi_get_engine_memory("ieee_p_2717149903");
    IEEE_P_1367372525 = xsi_get_engine_memory("ieee_p_1367372525");
    UNISIM_P_3222816464 = xsi_get_engine_memory("unisim_p_3222816464");

    return xsi_run_simulation(argc, argv);

}
