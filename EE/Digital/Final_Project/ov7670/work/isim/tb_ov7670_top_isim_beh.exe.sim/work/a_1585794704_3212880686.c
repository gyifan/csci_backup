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

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "H:/Users/ygg001.BUCKNELL/Downloads/Zedboard_OV7670/ov7670/debounce.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_1919365254_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_1242562249_sub_2110375371_1035706684(char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_1585794704_3212880686_p_0(char *t0)
{
    char t10[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t11;
    char *t12;
    int t13;
    unsigned int t14;
    unsigned char t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned int t20;

LAB0:    xsi_set_current_line(22, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 2992);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(23, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(31, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 3136);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    memcpy(t11, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(32, ng0);
    t1 = (t0 + 3072);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(24, ng0);
    t3 = (t0 + 1512U);
    t7 = *((char **)t3);
    t3 = (t0 + 4944U);
    t8 = (t0 + 4994);
    t11 = (t10 + 0U);
    t12 = (t11 + 0U);
    *((int *)t12) = 0;
    t12 = (t11 + 4U);
    *((int *)t12) = 23;
    t12 = (t11 + 8U);
    *((int *)t12) = 1;
    t13 = (23 - 0);
    t14 = (t13 * 1);
    t14 = (t14 + 1);
    t12 = (t11 + 12U);
    *((unsigned int *)t12) = t14;
    t15 = ieee_p_1242562249_sub_2110375371_1035706684(IEEE_P_1242562249, t7, t3, t8, t10);
    if (t15 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(27, ng0);
    t1 = (t0 + 3072);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB9:    xsi_set_current_line(29, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t1 = (t0 + 4944U);
    t4 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t10, t3, t1, 1);
    t7 = (t10 + 12U);
    t14 = *((unsigned int *)t7);
    t20 = (1U * t14);
    t2 = (24U != t20);
    if (t2 == 1)
        goto LAB11;

LAB12:    t8 = (t0 + 3136);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    memcpy(t16, t4, 24U);
    xsi_driver_first_trans_fast(t8);
    goto LAB6;

LAB8:    xsi_set_current_line(25, ng0);
    t12 = (t0 + 3072);
    t16 = (t12 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t12);
    goto LAB9;

LAB11:    xsi_size_not_matching(24U, t20, 0);
    goto LAB12;

}


extern void work_a_1585794704_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1585794704_3212880686_p_0};
	xsi_register_didat("work_a_1585794704_3212880686", "isim/tb_ov7670_top_isim_beh.exe.sim/work/a_1585794704_3212880686.didat");
	xsi_register_executes(pe);
}
