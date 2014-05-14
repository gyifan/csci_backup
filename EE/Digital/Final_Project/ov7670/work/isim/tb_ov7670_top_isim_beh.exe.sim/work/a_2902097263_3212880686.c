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
static const char *ng0 = "H:/Users/ygg001.BUCKNELL/Downloads/Zedboard_OV7670/ov7670/i2c_sender.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_1919365254_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_1242562249_sub_2110375371_1035706684(char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_2902097263_3212880686_p_0(char *t0)
{
    unsigned char t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    char *t8;
    char *t9;
    unsigned char t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    unsigned char t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    unsigned char t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    int t41;

LAB0:    xsi_set_current_line(29, ng0);
    t3 = (t0 + 2472U);
    t4 = *((char **)t3);
    t5 = (31 - 11);
    t6 = (t5 * 1U);
    t7 = (0 + t6);
    t3 = (t4 + t7);
    t8 = (t0 + 7626);
    t10 = 1;
    if (2U == 2U)
        goto LAB11;

LAB12:    t10 = 0;

LAB13:    if (t10 == 1)
        goto LAB8;

LAB9:    t14 = (t0 + 2472U);
    t15 = *((char **)t14);
    t16 = (31 - 20);
    t17 = (t16 * 1U);
    t18 = (0 + t17);
    t14 = (t15 + t18);
    t19 = (t0 + 7628);
    t21 = 1;
    if (2U == 2U)
        goto LAB17;

LAB18:    t21 = 0;

LAB19:    t2 = t21;

LAB10:    if (t2 == 1)
        goto LAB5;

LAB6:    t25 = (t0 + 2472U);
    t26 = *((char **)t25);
    t27 = (31 - 29);
    t28 = (t27 * 1U);
    t29 = (0 + t28);
    t25 = (t26 + t29);
    t30 = (t0 + 7630);
    t32 = 1;
    if (2U == 2U)
        goto LAB23;

LAB24:    t32 = 0;

LAB25:    t1 = t32;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(34, ng0);
    t3 = (t0 + 2632U);
    t4 = *((char **)t3);
    t41 = (31 - 31);
    t5 = (t41 * -1);
    t6 = (1U * t5);
    t7 = (0 + t6);
    t3 = (t4 + t7);
    t1 = *((unsigned char *)t3);
    t8 = (t0 + 4456);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = t1;
    xsi_driver_first_trans_fast_port(t8);

LAB3:    t3 = (t0 + 4360);
    *((int *)t3) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(32, ng0);
    t36 = (t0 + 4456);
    t37 = (t36 + 56U);
    t38 = *((char **)t37);
    t39 = (t38 + 56U);
    t40 = *((char **)t39);
    *((unsigned char *)t40) = (unsigned char)4;
    xsi_driver_first_trans_fast_port(t36);
    goto LAB3;

LAB5:    t1 = (unsigned char)1;
    goto LAB7;

LAB8:    t2 = (unsigned char)1;
    goto LAB10;

LAB11:    t11 = 0;

LAB14:    if (t11 < 2U)
        goto LAB15;
    else
        goto LAB13;

LAB15:    t12 = (t3 + t11);
    t13 = (t8 + t11);
    if (*((unsigned char *)t12) != *((unsigned char *)t13))
        goto LAB12;

LAB16:    t11 = (t11 + 1);
    goto LAB14;

LAB17:    t22 = 0;

LAB20:    if (t22 < 2U)
        goto LAB21;
    else
        goto LAB19;

LAB21:    t23 = (t14 + t22);
    t24 = (t19 + t22);
    if (*((unsigned char *)t23) != *((unsigned char *)t24))
        goto LAB18;

LAB22:    t22 = (t22 + 1);
    goto LAB20;

LAB23:    t33 = 0;

LAB26:    if (t33 < 2U)
        goto LAB27;
    else
        goto LAB25;

LAB27:    t34 = (t25 + t33);
    t35 = (t30 + t33);
    if (*((unsigned char *)t34) != *((unsigned char *)t35))
        goto LAB24;

LAB28:    t33 = (t33 + 1);
    goto LAB26;

}

static void work_a_2902097263_3212880686_p_1(char *t0)
{
    char t14[16];
    char t19[16];
    char t21[16];
    char t26[16];
    char t30[16];
    char t34[16];
    char t38[16];
    char t42[16];
    char t47[16];
    char t49[16];
    char t69[16];
    char t72[16];
    char t75[16];
    char t77[16];
    char t82[16];
    char t90[16];
    char t92[16];
    char t97[16];
    char t105[16];
    char t107[16];
    char t112[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned char t12;
    char *t13;
    unsigned char t15;
    char *t16;
    char *t17;
    char *t18;
    char *t20;
    char *t22;
    char *t23;
    int t24;
    char *t25;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    char *t32;
    char *t33;
    char *t35;
    char *t36;
    char *t37;
    char *t39;
    char *t40;
    char *t41;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t48;
    char *t50;
    char *t51;
    int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned char t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    int t62;
    int t63;
    int t64;
    int t65;
    unsigned int t66;
    int t67;
    int t68;
    int t70;
    unsigned int t71;
    int t73;
    int t74;
    char *t76;
    char *t78;
    char *t79;
    int t80;
    unsigned int t81;
    char *t83;
    int t84;
    int t85;
    char *t87;
    char *t89;
    char *t91;
    char *t93;
    char *t94;
    int t95;
    unsigned int t96;
    char *t98;
    int t99;
    int t100;
    char *t102;
    char *t104;
    char *t106;
    char *t108;
    char *t109;
    int t110;
    unsigned int t111;
    char *t113;
    int t114;
    int t115;
    char *t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    char *t120;
    int t122;
    char *t123;
    int t125;
    char *t126;
    int t128;
    char *t129;
    char *t130;
    char *t131;
    char *t132;
    char *t133;

LAB0:    xsi_set_current_line(40, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 4376);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(41, ng0);
    t3 = (t0 + 4520);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(42, ng0);
    t1 = (t0 + 2472U);
    t3 = *((char **)t1);
    t8 = (31 - 31);
    t9 = (t8 * -1);
    t10 = (1U * t9);
    t11 = (0 + t10);
    t1 = (t3 + t11);
    t2 = *((unsigned char *)t1);
    t12 = (t2 == (unsigned char)2);
    if (t12 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(55, ng0);
    t1 = (t0 + 2472U);
    t3 = *((char **)t1);
    t8 = (32 - 1);
    t9 = (31 - t8);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t1 = (t3 + t11);
    t4 = (t0 + 2472U);
    t5 = *((char **)t4);
    t53 = (31 - 2);
    t54 = (t53 * 1U);
    t55 = (0 + t54);
    t4 = (t5 + t55);
    t7 = ((IEEE_P_2592010699) + 4024);
    t13 = (t19 + 0U);
    t16 = (t13 + 0U);
    *((int *)t16) = 31;
    t16 = (t13 + 4U);
    *((int *)t16) = 29;
    t16 = (t13 + 8U);
    *((int *)t16) = -1;
    t24 = (29 - 31);
    t56 = (t24 * -1);
    t56 = (t56 + 1);
    t16 = (t13 + 12U);
    *((unsigned int *)t16) = t56;
    t16 = (t21 + 0U);
    t17 = (t16 + 0U);
    *((int *)t17) = 2;
    t17 = (t16 + 4U);
    *((int *)t17) = 0;
    t17 = (t16 + 8U);
    *((int *)t17) = -1;
    t52 = (0 - 2);
    t56 = (t52 * -1);
    t56 = (t56 + 1);
    t17 = (t16 + 12U);
    *((unsigned int *)t17) = t56;
    t6 = xsi_base_array_concat(t6, t14, t7, (char)97, t1, t19, (char)97, t4, t21, (char)101);
    t17 = (t0 + 7677);
    t20 = (t0 + 7680);
    t25 = ((IEEE_P_2592010699) + 4024);
    t27 = (t30 + 0U);
    t28 = (t27 + 0U);
    *((int *)t28) = 0;
    t28 = (t27 + 4U);
    *((int *)t28) = 2;
    t28 = (t27 + 8U);
    *((int *)t28) = 1;
    t62 = (2 - 0);
    t56 = (t62 * 1);
    t56 = (t56 + 1);
    t28 = (t27 + 12U);
    *((unsigned int *)t28) = t56;
    t28 = (t34 + 0U);
    t29 = (t28 + 0U);
    *((int *)t29) = 0;
    t29 = (t28 + 4U);
    *((int *)t29) = 2;
    t29 = (t28 + 8U);
    *((int *)t29) = 1;
    t63 = (2 - 0);
    t56 = (t63 * 1);
    t56 = (t56 + 1);
    t29 = (t28 + 12U);
    *((unsigned int *)t29) = t56;
    t23 = xsi_base_array_concat(t23, t26, t25, (char)97, t17, t30, (char)97, t20, t34, (char)101);
    t56 = (3U + 3U);
    t64 = xsi_mem_cmp(t23, t6, t56);
    if (t64 == 1)
        goto LAB21;

LAB28:    t29 = (t0 + 7683);
    t32 = (t0 + 7686);
    t36 = ((IEEE_P_2592010699) + 4024);
    t37 = (t42 + 0U);
    t39 = (t37 + 0U);
    *((int *)t39) = 0;
    t39 = (t37 + 4U);
    *((int *)t39) = 2;
    t39 = (t37 + 8U);
    *((int *)t39) = 1;
    t65 = (2 - 0);
    t66 = (t65 * 1);
    t66 = (t66 + 1);
    t39 = (t37 + 12U);
    *((unsigned int *)t39) = t66;
    t39 = (t47 + 0U);
    t40 = (t39 + 0U);
    *((int *)t40) = 0;
    t40 = (t39 + 4U);
    *((int *)t40) = 2;
    t40 = (t39 + 8U);
    *((int *)t40) = 1;
    t67 = (2 - 0);
    t66 = (t67 * 1);
    t66 = (t66 + 1);
    t40 = (t39 + 12U);
    *((unsigned int *)t40) = t66;
    t35 = xsi_base_array_concat(t35, t38, t36, (char)97, t29, t42, (char)97, t32, t47, (char)101);
    t66 = (3U + 3U);
    t68 = xsi_mem_cmp(t35, t6, t66);
    if (t68 == 1)
        goto LAB22;

LAB29:    t40 = (t0 + 7689);
    t43 = (t0 + 7692);
    t46 = ((IEEE_P_2592010699) + 4024);
    t48 = (t69 + 0U);
    t50 = (t48 + 0U);
    *((int *)t50) = 0;
    t50 = (t48 + 4U);
    *((int *)t50) = 2;
    t50 = (t48 + 8U);
    *((int *)t50) = 1;
    t70 = (2 - 0);
    t71 = (t70 * 1);
    t71 = (t71 + 1);
    t50 = (t48 + 12U);
    *((unsigned int *)t50) = t71;
    t50 = (t72 + 0U);
    t51 = (t50 + 0U);
    *((int *)t51) = 0;
    t51 = (t50 + 4U);
    *((int *)t51) = 2;
    t51 = (t50 + 8U);
    *((int *)t51) = 1;
    t73 = (2 - 0);
    t71 = (t73 * 1);
    t71 = (t71 + 1);
    t51 = (t50 + 12U);
    *((unsigned int *)t51) = t71;
    t45 = xsi_base_array_concat(t45, t49, t46, (char)97, t40, t69, (char)97, t43, t72, (char)101);
    t71 = (3U + 3U);
    t74 = xsi_mem_cmp(t45, t6, t71);
    if (t74 == 1)
        goto LAB23;

LAB30:    t51 = (t0 + 7695);
    t59 = (t0 + 7698);
    t76 = ((IEEE_P_2592010699) + 4024);
    t78 = (t77 + 0U);
    t79 = (t78 + 0U);
    *((int *)t79) = 0;
    t79 = (t78 + 4U);
    *((int *)t79) = 2;
    t79 = (t78 + 8U);
    *((int *)t79) = 1;
    t80 = (2 - 0);
    t81 = (t80 * 1);
    t81 = (t81 + 1);
    t79 = (t78 + 12U);
    *((unsigned int *)t79) = t81;
    t79 = (t82 + 0U);
    t83 = (t79 + 0U);
    *((int *)t83) = 0;
    t83 = (t79 + 4U);
    *((int *)t83) = 2;
    t83 = (t79 + 8U);
    *((int *)t83) = 1;
    t84 = (2 - 0);
    t81 = (t84 * 1);
    t81 = (t81 + 1);
    t83 = (t79 + 12U);
    *((unsigned int *)t83) = t81;
    t61 = xsi_base_array_concat(t61, t75, t76, (char)97, t51, t77, (char)97, t59, t82, (char)101);
    t81 = (3U + 3U);
    t85 = xsi_mem_cmp(t61, t6, t81);
    if (t85 == 1)
        goto LAB24;

LAB31:    t83 = (t0 + 7701);
    t87 = (t0 + 7704);
    t91 = ((IEEE_P_2592010699) + 4024);
    t93 = (t92 + 0U);
    t94 = (t93 + 0U);
    *((int *)t94) = 0;
    t94 = (t93 + 4U);
    *((int *)t94) = 2;
    t94 = (t93 + 8U);
    *((int *)t94) = 1;
    t95 = (2 - 0);
    t96 = (t95 * 1);
    t96 = (t96 + 1);
    t94 = (t93 + 12U);
    *((unsigned int *)t94) = t96;
    t94 = (t97 + 0U);
    t98 = (t94 + 0U);
    *((int *)t98) = 0;
    t98 = (t94 + 4U);
    *((int *)t98) = 2;
    t98 = (t94 + 8U);
    *((int *)t98) = 1;
    t99 = (2 - 0);
    t96 = (t99 * 1);
    t96 = (t96 + 1);
    t98 = (t94 + 12U);
    *((unsigned int *)t98) = t96;
    t89 = xsi_base_array_concat(t89, t90, t91, (char)97, t83, t92, (char)97, t87, t97, (char)101);
    t96 = (3U + 3U);
    t100 = xsi_mem_cmp(t89, t6, t96);
    if (t100 == 1)
        goto LAB25;

LAB32:    t98 = (t0 + 7707);
    t102 = (t0 + 7710);
    t106 = ((IEEE_P_2592010699) + 4024);
    t108 = (t107 + 0U);
    t109 = (t108 + 0U);
    *((int *)t109) = 0;
    t109 = (t108 + 4U);
    *((int *)t109) = 2;
    t109 = (t108 + 8U);
    *((int *)t109) = 1;
    t110 = (2 - 0);
    t111 = (t110 * 1);
    t111 = (t111 + 1);
    t109 = (t108 + 12U);
    *((unsigned int *)t109) = t111;
    t109 = (t112 + 0U);
    t113 = (t109 + 0U);
    *((int *)t113) = 0;
    t113 = (t109 + 4U);
    *((int *)t113) = 2;
    t113 = (t109 + 8U);
    *((int *)t113) = 1;
    t114 = (2 - 0);
    t111 = (t114 * 1);
    t111 = (t111 + 1);
    t113 = (t109 + 12U);
    *((unsigned int *)t113) = t111;
    t104 = xsi_base_array_concat(t104, t105, t106, (char)97, t98, t107, (char)97, t102, t112, (char)101);
    t111 = (3U + 3U);
    t115 = xsi_mem_cmp(t104, t6, t111);
    if (t115 == 1)
        goto LAB26;

LAB33:
LAB27:    xsi_set_current_line(99, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t9 = (7 - 7);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t1 = (t3 + t11);
    t4 = (t0 + 7749);
    t8 = xsi_mem_cmp(t4, t1, 2U);
    if (t8 == 1)
        goto LAB90;

LAB94:    t6 = (t0 + 7751);
    t24 = xsi_mem_cmp(t6, t1, 2U);
    if (t24 == 1)
        goto LAB91;

LAB95:    t13 = (t0 + 7753);
    t52 = xsi_mem_cmp(t13, t1, 2U);
    if (t52 == 1)
        goto LAB92;

LAB96:
LAB93:    xsi_set_current_line(103, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB89:
LAB20:    xsi_set_current_line(107, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t1 = (t0 + 7472U);
    t4 = (t0 + 7755);
    t6 = (t14 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 7;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t8 = (7 - 0);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    t2 = ieee_p_1242562249_sub_2110375371_1035706684(IEEE_P_1242562249, t3, t1, t4, t14);
    if (t2 != 0)
        goto LAB98;

LAB100:    xsi_set_current_line(112, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t1 = (t0 + 7472U);
    t4 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t14, t3, t1, 1);
    t5 = (t14 + 12U);
    t9 = *((unsigned int *)t5);
    t10 = (1U * t9);
    t2 = (8U != t10);
    if (t2 == 1)
        goto LAB105;

LAB106:    t6 = (t0 + 4776);
    t7 = (t6 + 56U);
    t13 = *((char **)t7);
    t16 = (t13 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t4, 8U);
    xsi_driver_first_trans_fast(t6);

LAB99:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(43, ng0);
    t4 = (t0 + 4584);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t13 = *((char **)t7);
    *((unsigned char *)t13) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(44, ng0);
    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t12 = (t2 == (unsigned char)3);
    if (t12 != 0)
        goto LAB8;

LAB10:
LAB9:    goto LAB6;

LAB8:    xsi_set_current_line(45, ng0);
    t1 = (t0 + 2312U);
    t4 = *((char **)t1);
    t1 = (t0 + 7472U);
    t5 = (t0 + 7632);
    t7 = (t14 + 0U);
    t13 = (t7 + 0U);
    *((int *)t13) = 0;
    t13 = (t7 + 4U);
    *((int *)t13) = 7;
    t13 = (t7 + 8U);
    *((int *)t13) = 1;
    t8 = (7 - 0);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t13 = (t7 + 12U);
    *((unsigned int *)t13) = t9;
    t15 = ieee_p_1242562249_sub_2110375371_1035706684(IEEE_P_1242562249, t4, t1, t5, t14);
    if (t15 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(50, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t1 = (t0 + 7472U);
    t4 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t14, t3, t1, 1);
    t5 = (t14 + 12U);
    t9 = *((unsigned int *)t5);
    t10 = (1U * t9);
    t2 = (8U != t10);
    if (t2 == 1)
        goto LAB18;

LAB19:    t6 = (t0 + 4776);
    t7 = (t6 + 56U);
    t13 = *((char **)t7);
    t16 = (t13 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t4, 8U);
    xsi_driver_first_trans_fast(t6);

LAB12:    goto LAB9;

LAB11:    xsi_set_current_line(46, ng0);
    t13 = (t0 + 7640);
    t17 = (t0 + 1832U);
    t18 = *((char **)t17);
    t20 = ((IEEE_P_2592010699) + 4024);
    t22 = (t21 + 0U);
    t23 = (t22 + 0U);
    *((int *)t23) = 0;
    t23 = (t22 + 4U);
    *((int *)t23) = 2;
    t23 = (t22 + 8U);
    *((int *)t23) = 1;
    t24 = (2 - 0);
    t9 = (t24 * 1);
    t9 = (t9 + 1);
    t23 = (t22 + 12U);
    *((unsigned int *)t23) = t9;
    t23 = (t0 + 7424U);
    t17 = xsi_base_array_concat(t17, t19, t20, (char)97, t13, t21, (char)97, t18, t23, (char)101);
    t27 = ((IEEE_P_2592010699) + 4024);
    t25 = xsi_base_array_concat(t25, t26, t27, (char)97, t17, t19, (char)99, (unsigned char)2, (char)101);
    t28 = (t0 + 1992U);
    t29 = *((char **)t28);
    t31 = ((IEEE_P_2592010699) + 4024);
    t32 = (t0 + 7440U);
    t28 = xsi_base_array_concat(t28, t30, t31, (char)97, t25, t26, (char)97, t29, t32, (char)101);
    t35 = ((IEEE_P_2592010699) + 4024);
    t33 = xsi_base_array_concat(t33, t34, t35, (char)97, t28, t30, (char)99, (unsigned char)2, (char)101);
    t36 = (t0 + 2152U);
    t37 = *((char **)t36);
    t39 = ((IEEE_P_2592010699) + 4024);
    t40 = (t0 + 7456U);
    t36 = xsi_base_array_concat(t36, t38, t39, (char)97, t33, t34, (char)97, t37, t40, (char)101);
    t43 = ((IEEE_P_2592010699) + 4024);
    t41 = xsi_base_array_concat(t41, t42, t43, (char)97, t36, t38, (char)99, (unsigned char)2, (char)101);
    t44 = (t0 + 7643);
    t48 = ((IEEE_P_2592010699) + 4024);
    t50 = (t49 + 0U);
    t51 = (t50 + 0U);
    *((int *)t51) = 0;
    t51 = (t50 + 4U);
    *((int *)t51) = 1;
    t51 = (t50 + 8U);
    *((int *)t51) = 1;
    t52 = (1 - 0);
    t9 = (t52 * 1);
    t9 = (t9 + 1);
    t51 = (t50 + 12U);
    *((unsigned int *)t51) = t9;
    t46 = xsi_base_array_concat(t46, t47, t48, (char)97, t41, t42, (char)97, t44, t49, (char)101);
    t9 = (3U + 8U);
    t10 = (t9 + 1U);
    t11 = (t10 + 8U);
    t53 = (t11 + 1U);
    t54 = (t53 + 8U);
    t55 = (t54 + 1U);
    t56 = (t55 + 2U);
    t57 = (32U != t56);
    if (t57 == 1)
        goto LAB14;

LAB15:    t51 = (t0 + 4648);
    t58 = (t51 + 56U);
    t59 = *((char **)t58);
    t60 = (t59 + 56U);
    t61 = *((char **)t60);
    memcpy(t61, t46, 32U);
    xsi_driver_first_trans_fast(t51);
    xsi_set_current_line(47, ng0);
    t1 = (t0 + 7645);
    t4 = (t0 + 7648);
    t7 = ((IEEE_P_2592010699) + 4024);
    t13 = (t19 + 0U);
    t16 = (t13 + 0U);
    *((int *)t16) = 0;
    t16 = (t13 + 4U);
    *((int *)t16) = 2;
    t16 = (t13 + 8U);
    *((int *)t16) = 1;
    t8 = (2 - 0);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t16 = (t13 + 12U);
    *((unsigned int *)t16) = t9;
    t16 = (t21 + 0U);
    t17 = (t16 + 0U);
    *((int *)t17) = 0;
    t17 = (t16 + 4U);
    *((int *)t17) = 8;
    t17 = (t16 + 8U);
    *((int *)t17) = 1;
    t24 = (8 - 0);
    t9 = (t24 * 1);
    t9 = (t9 + 1);
    t17 = (t16 + 12U);
    *((unsigned int *)t17) = t9;
    t6 = xsi_base_array_concat(t6, t14, t7, (char)97, t1, t19, (char)97, t4, t21, (char)101);
    t17 = (t0 + 7657);
    t22 = ((IEEE_P_2592010699) + 4024);
    t23 = (t30 + 0U);
    t25 = (t23 + 0U);
    *((int *)t25) = 0;
    t25 = (t23 + 4U);
    *((int *)t25) = 8;
    t25 = (t23 + 8U);
    *((int *)t25) = 1;
    t52 = (8 - 0);
    t9 = (t52 * 1);
    t9 = (t9 + 1);
    t25 = (t23 + 12U);
    *((unsigned int *)t25) = t9;
    t20 = xsi_base_array_concat(t20, t26, t22, (char)97, t6, t14, (char)97, t17, t30, (char)101);
    t25 = (t0 + 7666);
    t29 = ((IEEE_P_2592010699) + 4024);
    t31 = (t38 + 0U);
    t32 = (t31 + 0U);
    *((int *)t32) = 0;
    t32 = (t31 + 4U);
    *((int *)t32) = 8;
    t32 = (t31 + 8U);
    *((int *)t32) = 1;
    t62 = (8 - 0);
    t9 = (t62 * 1);
    t9 = (t9 + 1);
    t32 = (t31 + 12U);
    *((unsigned int *)t32) = t9;
    t28 = xsi_base_array_concat(t28, t34, t29, (char)97, t20, t26, (char)97, t25, t38, (char)101);
    t32 = (t0 + 7675);
    t36 = ((IEEE_P_2592010699) + 4024);
    t37 = (t47 + 0U);
    t39 = (t37 + 0U);
    *((int *)t39) = 0;
    t39 = (t37 + 4U);
    *((int *)t39) = 1;
    t39 = (t37 + 8U);
    *((int *)t39) = 1;
    t63 = (1 - 0);
    t9 = (t63 * 1);
    t9 = (t9 + 1);
    t39 = (t37 + 12U);
    *((unsigned int *)t39) = t9;
    t35 = xsi_base_array_concat(t35, t42, t36, (char)97, t28, t34, (char)97, t32, t47, (char)101);
    t9 = (3U + 9U);
    t10 = (t9 + 9U);
    t11 = (t10 + 9U);
    t53 = (t11 + 2U);
    t2 = (32U != t53);
    if (t2 == 1)
        goto LAB16;

LAB17:    t39 = (t0 + 4712);
    t40 = (t39 + 56U);
    t41 = *((char **)t40);
    t43 = (t41 + 56U);
    t44 = *((char **)t43);
    memcpy(t44, t35, 32U);
    xsi_driver_first_trans_fast(t39);
    xsi_set_current_line(48, ng0);
    t1 = (t0 + 4520);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB12;

LAB14:    xsi_size_not_matching(32U, t56, 0);
    goto LAB15;

LAB16:    xsi_size_not_matching(32U, t53, 0);
    goto LAB17;

LAB18:    xsi_size_not_matching(8U, t10, 0);
    goto LAB19;

LAB21:    xsi_set_current_line(57, ng0);
    t113 = (t0 + 2312U);
    t116 = *((char **)t113);
    t117 = (7 - 7);
    t118 = (t117 * 1U);
    t119 = (0 + t118);
    t113 = (t116 + t119);
    t120 = (t0 + 7713);
    t122 = xsi_mem_cmp(t120, t113, 2U);
    if (t122 == 1)
        goto LAB36;

LAB40:    t123 = (t0 + 7715);
    t125 = xsi_mem_cmp(t123, t113, 2U);
    if (t125 == 1)
        goto LAB37;

LAB41:    t126 = (t0 + 7717);
    t128 = xsi_mem_cmp(t126, t113, 2U);
    if (t128 == 1)
        goto LAB38;

LAB42:
LAB39:    xsi_set_current_line(61, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);

LAB35:    goto LAB20;

LAB22:    xsi_set_current_line(64, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t9 = (7 - 7);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t1 = (t3 + t11);
    t4 = (t0 + 7719);
    t8 = xsi_mem_cmp(t4, t1, 2U);
    if (t8 == 1)
        goto LAB45;

LAB49:    t6 = (t0 + 7721);
    t24 = xsi_mem_cmp(t6, t1, 2U);
    if (t24 == 1)
        goto LAB46;

LAB50:    t13 = (t0 + 7723);
    t52 = xsi_mem_cmp(t13, t1, 2U);
    if (t52 == 1)
        goto LAB47;

LAB51:
LAB48:    xsi_set_current_line(68, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);

LAB44:    goto LAB20;

LAB23:    xsi_set_current_line(71, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t9 = (7 - 7);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t1 = (t3 + t11);
    t4 = (t0 + 7725);
    t8 = xsi_mem_cmp(t4, t1, 2U);
    if (t8 == 1)
        goto LAB54;

LAB58:    t6 = (t0 + 7727);
    t24 = xsi_mem_cmp(t6, t1, 2U);
    if (t24 == 1)
        goto LAB55;

LAB59:    t13 = (t0 + 7729);
    t52 = xsi_mem_cmp(t13, t1, 2U);
    if (t52 == 1)
        goto LAB56;

LAB60:
LAB57:    xsi_set_current_line(75, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB53:    goto LAB20;

LAB24:    xsi_set_current_line(78, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t9 = (7 - 7);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t1 = (t3 + t11);
    t4 = (t0 + 7731);
    t8 = xsi_mem_cmp(t4, t1, 2U);
    if (t8 == 1)
        goto LAB63;

LAB67:    t6 = (t0 + 7733);
    t24 = xsi_mem_cmp(t6, t1, 2U);
    if (t24 == 1)
        goto LAB64;

LAB68:    t13 = (t0 + 7735);
    t52 = xsi_mem_cmp(t13, t1, 2U);
    if (t52 == 1)
        goto LAB65;

LAB69:
LAB66:    xsi_set_current_line(82, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);

LAB62:    goto LAB20;

LAB25:    xsi_set_current_line(85, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t9 = (7 - 7);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t1 = (t3 + t11);
    t4 = (t0 + 7737);
    t8 = xsi_mem_cmp(t4, t1, 2U);
    if (t8 == 1)
        goto LAB72;

LAB76:    t6 = (t0 + 7739);
    t24 = xsi_mem_cmp(t6, t1, 2U);
    if (t24 == 1)
        goto LAB73;

LAB77:    t13 = (t0 + 7741);
    t52 = xsi_mem_cmp(t13, t1, 2U);
    if (t52 == 1)
        goto LAB74;

LAB78:
LAB75:    xsi_set_current_line(89, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);

LAB71:    goto LAB20;

LAB26:    xsi_set_current_line(92, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t9 = (7 - 7);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t1 = (t3 + t11);
    t4 = (t0 + 7743);
    t8 = xsi_mem_cmp(t4, t1, 2U);
    if (t8 == 1)
        goto LAB81;

LAB85:    t6 = (t0 + 7745);
    t24 = xsi_mem_cmp(t6, t1, 2U);
    if (t24 == 1)
        goto LAB82;

LAB86:    t13 = (t0 + 7747);
    t52 = xsi_mem_cmp(t13, t1, 2U);
    if (t52 == 1)
        goto LAB83;

LAB87:
LAB84:    xsi_set_current_line(96, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);

LAB80:    goto LAB20;

LAB34:;
LAB36:    xsi_set_current_line(58, ng0);
    t129 = (t0 + 4584);
    t130 = (t129 + 56U);
    t131 = *((char **)t130);
    t132 = (t131 + 56U);
    t133 = *((char **)t132);
    *((unsigned char *)t133) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t129);
    goto LAB35;

LAB37:    xsi_set_current_line(59, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB35;

LAB38:    xsi_set_current_line(60, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB35;

LAB43:;
LAB45:    xsi_set_current_line(65, ng0);
    t17 = (t0 + 4584);
    t18 = (t17 + 56U);
    t20 = *((char **)t18);
    t22 = (t20 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t17);
    goto LAB44;

LAB46:    xsi_set_current_line(66, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB44;

LAB47:    xsi_set_current_line(67, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB44;

LAB52:;
LAB54:    xsi_set_current_line(72, ng0);
    t17 = (t0 + 4584);
    t18 = (t17 + 56U);
    t20 = *((char **)t18);
    t22 = (t20 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t17);
    goto LAB53;

LAB55:    xsi_set_current_line(73, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB53;

LAB56:    xsi_set_current_line(74, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB53;

LAB61:;
LAB63:    xsi_set_current_line(79, ng0);
    t17 = (t0 + 4584);
    t18 = (t17 + 56U);
    t20 = *((char **)t18);
    t22 = (t20 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t17);
    goto LAB62;

LAB64:    xsi_set_current_line(80, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB62;

LAB65:    xsi_set_current_line(81, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB62;

LAB70:;
LAB72:    xsi_set_current_line(86, ng0);
    t17 = (t0 + 4584);
    t18 = (t17 + 56U);
    t20 = *((char **)t18);
    t22 = (t20 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t17);
    goto LAB71;

LAB73:    xsi_set_current_line(87, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB71;

LAB74:    xsi_set_current_line(88, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB71;

LAB79:;
LAB81:    xsi_set_current_line(93, ng0);
    t17 = (t0 + 4584);
    t18 = (t17 + 56U);
    t20 = *((char **)t18);
    t22 = (t20 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t17);
    goto LAB80;

LAB82:    xsi_set_current_line(94, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB80;

LAB83:    xsi_set_current_line(95, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB80;

LAB88:;
LAB90:    xsi_set_current_line(100, ng0);
    t17 = (t0 + 4584);
    t18 = (t17 + 56U);
    t20 = *((char **)t18);
    t22 = (t20 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t17);
    goto LAB89;

LAB91:    xsi_set_current_line(101, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB89;

LAB92:    xsi_set_current_line(102, ng0);
    t1 = (t0 + 4584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB89;

LAB97:;
LAB98:    xsi_set_current_line(108, ng0);
    t7 = (t0 + 2472U);
    t13 = *((char **)t7);
    t24 = (32 - 2);
    t9 = (31 - t24);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t7 = (t13 + t11);
    t17 = ((IEEE_P_2592010699) + 4024);
    t18 = (t21 + 0U);
    t20 = (t18 + 0U);
    *((int *)t20) = 30;
    t20 = (t18 + 4U);
    *((int *)t20) = 0;
    t20 = (t18 + 8U);
    *((int *)t20) = -1;
    t52 = (0 - 30);
    t53 = (t52 * -1);
    t53 = (t53 + 1);
    t20 = (t18 + 12U);
    *((unsigned int *)t20) = t53;
    t16 = xsi_base_array_concat(t16, t19, t17, (char)97, t7, t21, (char)99, (unsigned char)2, (char)101);
    t53 = (31U + 1U);
    t12 = (32U != t53);
    if (t12 == 1)
        goto LAB101;

LAB102:    t20 = (t0 + 4712);
    t22 = (t20 + 56U);
    t23 = *((char **)t22);
    t25 = (t23 + 56U);
    t27 = *((char **)t25);
    memcpy(t27, t16, 32U);
    xsi_driver_first_trans_fast(t20);
    xsi_set_current_line(109, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t8 = (32 - 2);
    t9 = (31 - t8);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t1 = (t3 + t11);
    t5 = ((IEEE_P_2592010699) + 4024);
    t6 = (t19 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 30;
    t7 = (t6 + 4U);
    *((int *)t7) = 0;
    t7 = (t6 + 8U);
    *((int *)t7) = -1;
    t24 = (0 - 30);
    t53 = (t24 * -1);
    t53 = (t53 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t53;
    t4 = xsi_base_array_concat(t4, t14, t5, (char)97, t1, t19, (char)99, (unsigned char)3, (char)101);
    t53 = (31U + 1U);
    t2 = (32U != t53);
    if (t2 == 1)
        goto LAB103;

LAB104:    t7 = (t0 + 4648);
    t13 = (t7 + 56U);
    t16 = *((char **)t13);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t4, 32U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(110, ng0);
    t1 = xsi_get_transient_memory(8U);
    memset(t1, 0, 8U);
    t3 = t1;
    memset(t3, (unsigned char)2, 8U);
    t4 = (t0 + 4776);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t13 = *((char **)t7);
    memcpy(t13, t1, 8U);
    xsi_driver_first_trans_fast(t4);
    goto LAB99;

LAB101:    xsi_size_not_matching(32U, t53, 0);
    goto LAB102;

LAB103:    xsi_size_not_matching(32U, t53, 0);
    goto LAB104;

LAB105:    xsi_size_not_matching(8U, t10, 0);
    goto LAB106;

}


extern void work_a_2902097263_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2902097263_3212880686_p_0,(void *)work_a_2902097263_3212880686_p_1};
	xsi_register_didat("work_a_2902097263_3212880686", "isim/tb_ov7670_top_isim_beh.exe.sim/work/a_2902097263_3212880686.didat");
	xsi_register_executes(pe);
}
