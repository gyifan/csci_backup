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
static const char *ng0 = "H:/Users/ygg001.BUCKNELL/Downloads/Zedboard_OV7670/ov7670/ov7670_capture.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_1919365254_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_2592010699_sub_1605435078_503743352(char *, unsigned char , unsigned char );
unsigned char ieee_p_2592010699_sub_1690584930_503743352(char *, unsigned char );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_2205409629_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(28, ng0);

LAB3:    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t1 = (t0 + 4456);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 19U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 4360);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2205409629_3212880686_p_1(char *t0)
{
    char t19[16];
    char t20[16];
    char t23[16];
    char t29[16];
    char t31[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    int t21;
    unsigned int t22;
    int t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t30;
    char *t32;
    char *t33;
    int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    unsigned char t41;
    unsigned char t42;
    unsigned char t43;

LAB0:    xsi_set_current_line(31, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 4376);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(40, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(47, ng0);
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t13 = (15 - 15);
    t14 = (t13 * 1U);
    t15 = (0 + t14);
    t1 = (t3 + t15);
    t4 = (t0 + 2152U);
    t7 = *((char **)t4);
    t16 = (15 - 10);
    t17 = (t16 * 1U);
    t18 = (0 + t17);
    t4 = (t7 + t18);
    t9 = ((IEEE_P_2592010699) + 4024);
    t10 = (t20 + 0U);
    t11 = (t10 + 0U);
    *((int *)t11) = 15;
    t11 = (t10 + 4U);
    *((int *)t11) = 12;
    t11 = (t10 + 8U);
    *((int *)t11) = -1;
    t21 = (12 - 15);
    t22 = (t21 * -1);
    t22 = (t22 + 1);
    t11 = (t10 + 12U);
    *((unsigned int *)t11) = t22;
    t11 = (t23 + 0U);
    t12 = (t11 + 0U);
    *((int *)t12) = 10;
    t12 = (t11 + 4U);
    *((int *)t12) = 7;
    t12 = (t11 + 8U);
    *((int *)t12) = -1;
    t24 = (7 - 10);
    t22 = (t24 * -1);
    t22 = (t22 + 1);
    t12 = (t11 + 12U);
    *((unsigned int *)t12) = t22;
    t8 = xsi_base_array_concat(t8, t19, t9, (char)97, t1, t20, (char)97, t4, t23, (char)101);
    t12 = (t0 + 2152U);
    t25 = *((char **)t12);
    t22 = (15 - 4);
    t26 = (t22 * 1U);
    t27 = (0 + t26);
    t12 = (t25 + t27);
    t30 = ((IEEE_P_2592010699) + 4024);
    t32 = (t31 + 0U);
    t33 = (t32 + 0U);
    *((int *)t33) = 4;
    t33 = (t32 + 4U);
    *((int *)t33) = 1;
    t33 = (t32 + 8U);
    *((int *)t33) = -1;
    t34 = (1 - 4);
    t35 = (t34 * -1);
    t35 = (t35 + 1);
    t33 = (t32 + 12U);
    *((unsigned int *)t33) = t35;
    t28 = xsi_base_array_concat(t28, t29, t30, (char)97, t8, t19, (char)97, t12, t31, (char)101);
    t35 = (4U + 4U);
    t36 = (t35 + 4U);
    t2 = (12U != t36);
    if (t2 == 1)
        goto LAB8;

LAB9:    t33 = (t0 + 4712);
    t37 = (t33 + 56U);
    t38 = *((char **)t37);
    t39 = (t38 + 56U);
    t40 = *((char **)t39);
    memcpy(t40, t28, 12U);
    xsi_driver_first_trans_fast_port(t33);
    xsi_set_current_line(48, ng0);
    t1 = (t0 + 2472U);
    t3 = *((char **)t1);
    t1 = (t0 + 4520);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 19U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(49, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t21 = (1 - 1);
    t13 = (t21 * -1);
    t14 = (1U * t13);
    t15 = (0 + t14);
    t1 = (t3 + t15);
    t2 = *((unsigned char *)t1);
    t4 = (t0 + 4776);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = t2;
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(50, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t21 = (0 - 1);
    t13 = (t21 * -1);
    t14 = (1U * t13);
    t15 = (0 + t14);
    t1 = (t3 + t15);
    t2 = *((unsigned char *)t1);
    t4 = (t0 + 1352U);
    t7 = *((char **)t4);
    t5 = *((unsigned char *)t7);
    t4 = (t0 + 2632U);
    t8 = *((char **)t4);
    t24 = (0 - 1);
    t16 = (t24 * -1);
    t17 = (1U * t16);
    t18 = (0 + t17);
    t4 = (t8 + t18);
    t6 = *((unsigned char *)t4);
    t41 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t6);
    t42 = ieee_p_2592010699_sub_1605435078_503743352(IEEE_P_2592010699, t5, t41);
    t10 = ((IEEE_P_2592010699) + 4024);
    t9 = xsi_base_array_concat(t9, t19, t10, (char)99, t2, (char)99, t42, (char)101);
    t22 = (1U + 1U);
    t43 = (2U != t22);
    if (t43 == 1)
        goto LAB10;

LAB11:    t11 = (t0 + 4648);
    t12 = (t11 + 56U);
    t25 = *((char **)t12);
    t28 = (t25 + 56U);
    t30 = *((char **)t28);
    memcpy(t30, t9, 2U);
    xsi_driver_first_trans_fast(t11);
    xsi_set_current_line(51, ng0);
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t13 = (15 - 7);
    t14 = (t13 * 1U);
    t15 = (0 + t14);
    t1 = (t3 + t15);
    t4 = (t0 + 1512U);
    t7 = *((char **)t4);
    t8 = ((IEEE_P_2592010699) + 4024);
    t9 = (t20 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 7;
    t10 = (t9 + 4U);
    *((int *)t10) = 0;
    t10 = (t9 + 8U);
    *((int *)t10) = -1;
    t21 = (0 - 7);
    t16 = (t21 * -1);
    t16 = (t16 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t16;
    t10 = (t0 + 7396U);
    t4 = xsi_base_array_concat(t4, t19, t8, (char)97, t1, t20, (char)97, t7, t10, (char)101);
    t16 = (8U + 8U);
    t2 = (16U != t16);
    if (t2 == 1)
        goto LAB12;

LAB13:    t11 = (t0 + 4840);
    t12 = (t11 + 56U);
    t25 = *((char **)t12);
    t28 = (t25 + 56U);
    t30 = *((char **)t28);
    memcpy(t30, t4, 16U);
    xsi_driver_first_trans_fast(t11);
    xsi_set_current_line(53, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t21 = (1 - 1);
    t13 = (t21 * -1);
    t14 = (1U * t13);
    t15 = (0 + t14);
    t1 = (t3 + t15);
    t2 = *((unsigned char *)t1);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB14;

LAB16:
LAB15:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(41, ng0);
    t3 = xsi_get_transient_memory(19U);
    memset(t3, 0, 19U);
    t7 = t3;
    memset(t7, (unsigned char)2, 19U);
    t8 = (t0 + 4520);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 19U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(42, ng0);
    t1 = xsi_get_transient_memory(19U);
    memset(t1, 0, 19U);
    t3 = t1;
    memset(t3, (unsigned char)2, 19U);
    t4 = (t0 + 4584);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 19U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(43, ng0);
    t1 = xsi_get_transient_memory(2U);
    memset(t1, 0, 2U);
    t3 = t1;
    memset(t3, (unsigned char)2, 2U);
    t4 = (t0 + 4648);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 2U);
    xsi_driver_first_trans_fast(t4);
    goto LAB6;

LAB8:    xsi_size_not_matching(12U, t36, 0);
    goto LAB9;

LAB10:    xsi_size_not_matching(2U, t22, 0);
    goto LAB11;

LAB12:    xsi_size_not_matching(16U, t16, 0);
    goto LAB13;

LAB14:    xsi_set_current_line(54, ng0);
    t4 = (t0 + 2472U);
    t7 = *((char **)t4);
    t4 = (t0 + 7476U);
    t8 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t19, t7, t4, 1);
    t9 = (t0 + 4584);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t25 = *((char **)t12);
    memcpy(t25, t8, 19U);
    xsi_driver_first_trans_fast(t9);
    goto LAB15;

}


extern void work_a_2205409629_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2205409629_3212880686_p_0,(void *)work_a_2205409629_3212880686_p_1};
	xsi_register_didat("work_a_2205409629_3212880686", "isim/tb_ov7670_top_isim_beh.exe.sim/work/a_2205409629_3212880686.didat");
	xsi_register_executes(pe);
}
