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
static const char *ng0 = "H:/Users/ygg001.BUCKNELL/Downloads/Zedboard_OV7670/ov7670/vga.v";
static int ng1[] = {1, 0};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static int ng4[] = {640, 0};
static int ng5[] = {14, 0};
static int ng6[] = {16, 0};
static int ng7[] = {480, 0};
static int ng8[] = {4, 0};
static int ng9[] = {10, 0};
static unsigned int ng10[] = {320U, 0U};
static unsigned int ng11[] = {240U, 0U};



static void Cont_113_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 8936U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(113, ng0);
    t2 = (t0 + 7856);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 11184);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 524287U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 18);
    t18 = (t0 + 10992);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_114_1(char *t0)
{
    char t9[8];
    char t10[8];
    char t42[8];
    char t45[8];
    char t48[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    char *t43;
    char *t44;
    char *t46;
    char *t47;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    int t62;
    int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    char *t77;

LAB0:    t1 = (t0 + 9184U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(114, ng0);
    t2 = (t0 + 11008);
    *((int *)t2) = 1;
    t3 = (t0 + 9216);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(114, ng0);

LAB5:    xsi_set_current_line(116, ng0);
    t4 = (t0 + 7536);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 1288);
    t8 = *((char **)t7);
    t7 = ((char*)((ng1)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_minus(t9, 32, t8, 32, t7, 32);
    memset(t10, 0, 8);
    t11 = (t6 + 4);
    t12 = (t9 + 4);
    t13 = *((unsigned int *)t6);
    t14 = *((unsigned int *)t9);
    t15 = (t13 ^ t14);
    t16 = *((unsigned int *)t11);
    t17 = *((unsigned int *)t12);
    t18 = (t16 ^ t17);
    t19 = (t15 | t18);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t12);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB9;

LAB6:    if (t22 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t10) = 1;

LAB9:    t26 = (t10 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (~(t27));
    t29 = *((unsigned int *)t10);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(125, ng0);

LAB23:    xsi_set_current_line(126, ng0);
    t2 = (t0 + 7536);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_add(t9, 32, t4, 10, t5, 32);
    t6 = (t0 + 7536);
    xsi_vlogvar_wait_assign_value(t6, t9, 0, 0, 10, 0LL);

LAB12:    xsi_set_current_line(129, ng0);
    t2 = (t0 + 8016);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t9, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t5);
    t15 = (t13 ^ t14);
    t16 = *((unsigned int *)t6);
    t17 = *((unsigned int *)t7);
    t18 = (t16 ^ t17);
    t19 = (t15 | t18);
    t20 = *((unsigned int *)t6);
    t21 = *((unsigned int *)t7);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB27;

LAB24:    if (t22 != 0)
        goto LAB26;

LAB25:    *((unsigned int *)t9) = 1;

LAB27:    t11 = (t9 + 4);
    t27 = *((unsigned int *)t11);
    t28 = (~(t27));
    t29 = *((unsigned int *)t9);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB28;

LAB29:    xsi_set_current_line(134, ng0);

LAB32:    xsi_set_current_line(135, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4976);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    xsi_set_current_line(136, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5136);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    xsi_set_current_line(137, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5296);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);

LAB30:    xsi_set_current_line(140, ng0);
    t2 = (t0 + 7696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1424);
    t6 = *((char **)t5);
    memset(t9, 0, 8);
    t5 = (t4 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB34;

LAB33:    t7 = (t6 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB34;

LAB37:    if (*((unsigned int *)t4) < *((unsigned int *)t6))
        goto LAB36;

LAB35:    *((unsigned int *)t9) = 1;

LAB36:    t11 = (t9 + 4);
    t13 = *((unsigned int *)t11);
    t14 = (~(t13));
    t15 = *((unsigned int *)t9);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB38;

LAB39:    xsi_set_current_line(144, ng0);

LAB42:    xsi_set_current_line(145, ng0);
    t2 = (t0 + 7536);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t9, 0, 8);
    t6 = (t4 + 4);
    if (*((unsigned int *)t6) != 0)
        goto LAB44;

LAB43:    t7 = (t5 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB44;

LAB47:    if (*((unsigned int *)t4) < *((unsigned int *)t5))
        goto LAB45;

LAB46:    t11 = (t9 + 4);
    t13 = *((unsigned int *)t11);
    t14 = (~(t13));
    t15 = *((unsigned int *)t9);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB48;

LAB49:    xsi_set_current_line(149, ng0);

LAB52:    xsi_set_current_line(150, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 8016);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB50:
LAB40:    xsi_set_current_line(155, ng0);
    t2 = (t0 + 7536);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1016);
    t6 = *((char **)t5);
    memset(t9, 0, 8);
    t5 = (t4 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB54;

LAB53:    t7 = (t6 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB54;

LAB57:    if (*((unsigned int *)t4) > *((unsigned int *)t6))
        goto LAB55;

LAB56:    memset(t10, 0, 8);
    t11 = (t9 + 4);
    t13 = *((unsigned int *)t11);
    t14 = (~(t13));
    t15 = *((unsigned int *)t9);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB58;

LAB59:    if (*((unsigned int *)t11) != 0)
        goto LAB60;

LAB61:    t25 = (t10 + 4);
    t18 = *((unsigned int *)t10);
    t19 = *((unsigned int *)t25);
    t20 = (t18 || t19);
    if (t20 > 0)
        goto LAB62;

LAB63:    memcpy(t48, t10, 8);

LAB64:    t70 = (t48 + 4);
    t71 = *((unsigned int *)t70);
    t72 = (~(t71));
    t73 = *((unsigned int *)t48);
    t74 = (t73 & t72);
    t75 = (t74 != 0);
    if (t75 > 0)
        goto LAB77;

LAB78:    xsi_set_current_line(158, ng0);

LAB81:    xsi_set_current_line(159, ng0);
    t2 = (t0 + 1968);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t4 = (t3 + 4);
    memcpy(t9, t3, 8);
    t13 = *((unsigned int *)t9);
    t14 = (~(t13));
    t15 = *((unsigned int *)t2);
    t16 = (t14 | t15);
    *((unsigned int *)t9) = t16;
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 4294967295U);
    t18 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t18 & 4294967295U);
    t5 = (t0 + 4496);
    xsi_vlogvar_wait_assign_value(t5, t9, 0, 0, 1, 0LL);

LAB79:    xsi_set_current_line(163, ng0);
    t2 = (t0 + 7696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1560);
    t6 = *((char **)t5);
    memset(t9, 0, 8);
    t5 = (t4 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB83;

LAB82:    t7 = (t6 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB83;

LAB86:    if (*((unsigned int *)t4) < *((unsigned int *)t6))
        goto LAB85;

LAB84:    *((unsigned int *)t9) = 1;

LAB85:    memset(t10, 0, 8);
    t11 = (t9 + 4);
    t13 = *((unsigned int *)t11);
    t14 = (~(t13));
    t15 = *((unsigned int *)t9);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB87;

LAB88:    if (*((unsigned int *)t11) != 0)
        goto LAB89;

LAB90:    t25 = (t10 + 4);
    t18 = *((unsigned int *)t10);
    t19 = *((unsigned int *)t25);
    t20 = (t18 || t19);
    if (t20 > 0)
        goto LAB91;

LAB92:    memcpy(t48, t10, 8);

LAB93:    t70 = (t48 + 4);
    t71 = *((unsigned int *)t70);
    t72 = (~(t71));
    t73 = *((unsigned int *)t48);
    t74 = (t73 & t72);
    t75 = (t74 != 0);
    if (t75 > 0)
        goto LAB106;

LAB107:    xsi_set_current_line(166, ng0);

LAB110:    xsi_set_current_line(167, ng0);
    t2 = (t0 + 2104);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t4 = (t3 + 4);
    memcpy(t9, t3, 8);
    t13 = *((unsigned int *)t9);
    t14 = (~(t13));
    t15 = *((unsigned int *)t2);
    t16 = (t14 | t15);
    *((unsigned int *)t9) = t16;
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 4294967295U);
    t18 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t18 & 4294967295U);
    t5 = (t0 + 4656);
    xsi_vlogvar_wait_assign_value(t5, t9, 0, 0, 1, 0LL);

LAB108:    goto LAB2;

LAB8:    t25 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(116, ng0);

LAB13:    xsi_set_current_line(117, ng0);
    t32 = ((char*)((ng2)));
    t33 = (t0 + 7536);
    xsi_vlogvar_wait_assign_value(t33, t32, 0, 0, 10, 0LL);
    xsi_set_current_line(118, ng0);
    t2 = (t0 + 7696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1832);
    t6 = *((char **)t5);
    t5 = ((char*)((ng1)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_minus(t9, 32, t6, 32, t5, 32);
    memset(t10, 0, 8);
    t7 = (t4 + 4);
    t8 = (t9 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t9);
    t15 = (t13 ^ t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 ^ t17);
    t19 = (t15 | t18);
    t20 = *((unsigned int *)t7);
    t21 = *((unsigned int *)t8);
    t22 = (t20 | t21);
    t23 = (~(t22));
    t24 = (t19 & t23);
    if (t24 != 0)
        goto LAB17;

LAB14:    if (t22 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t10) = 1;

LAB17:    t12 = (t10 + 4);
    t27 = *((unsigned int *)t12);
    t28 = (~(t27));
    t29 = *((unsigned int *)t10);
    t30 = (t29 & t28);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(121, ng0);

LAB22:    xsi_set_current_line(122, ng0);
    t2 = (t0 + 7696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_add(t9, 32, t4, 10, t5, 32);
    t6 = (t0 + 7696);
    xsi_vlogvar_wait_assign_value(t6, t9, 0, 0, 10, 0LL);

LAB20:    goto LAB12;

LAB16:    t11 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(118, ng0);

LAB21:    xsi_set_current_line(119, ng0);
    t25 = ((char*)((ng2)));
    t26 = (t0 + 7696);
    xsi_vlogvar_wait_assign_value(t26, t25, 0, 0, 10, 0LL);
    goto LAB20;

LAB26:    t8 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB27;

LAB28:    xsi_set_current_line(129, ng0);

LAB31:    xsi_set_current_line(130, ng0);
    t12 = (t0 + 3136U);
    t25 = *((char **)t12);
    memset(t10, 0, 8);
    t12 = (t10 + 4);
    t26 = (t25 + 4);
    t34 = *((unsigned int *)t25);
    t35 = (t34 >> 8);
    *((unsigned int *)t10) = t35;
    t36 = *((unsigned int *)t26);
    t37 = (t36 >> 8);
    *((unsigned int *)t12) = t37;
    t38 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t38 & 15U);
    t39 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t39 & 15U);
    t32 = (t0 + 4976);
    xsi_vlogvar_wait_assign_value(t32, t10, 0, 0, 4, 0LL);
    xsi_set_current_line(131, ng0);
    t2 = (t0 + 3136U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t4 = (t3 + 4);
    t13 = *((unsigned int *)t3);
    t14 = (t13 >> 4);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t4);
    t16 = (t15 >> 4);
    *((unsigned int *)t2) = t16;
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 15U);
    t18 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t18 & 15U);
    t5 = (t0 + 5136);
    xsi_vlogvar_wait_assign_value(t5, t9, 0, 0, 4, 0LL);
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 3136U);
    t3 = *((char **)t2);
    memset(t9, 0, 8);
    t2 = (t9 + 4);
    t4 = (t3 + 4);
    t13 = *((unsigned int *)t3);
    t14 = (t13 >> 0);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t4);
    t16 = (t15 >> 0);
    *((unsigned int *)t2) = t16;
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 15U);
    t18 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t18 & 15U);
    t5 = (t0 + 5296);
    xsi_vlogvar_wait_assign_value(t5, t9, 0, 0, 4, 0LL);
    goto LAB30;

LAB34:    t8 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB36;

LAB38:    xsi_set_current_line(140, ng0);

LAB41:    xsi_set_current_line(141, ng0);
    t12 = ((char*)((ng2)));
    t25 = (t0 + 7856);
    xsi_vlogvar_wait_assign_value(t25, t12, 0, 0, 19, 0LL);
    xsi_set_current_line(142, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 8016);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB40;

LAB44:    t8 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB46;

LAB45:    *((unsigned int *)t9) = 1;
    goto LAB46;

LAB48:    xsi_set_current_line(145, ng0);

LAB51:    xsi_set_current_line(146, ng0);
    t12 = ((char*)((ng2)));
    t25 = (t0 + 8016);
    xsi_vlogvar_wait_assign_value(t25, t12, 0, 0, 1, 0LL);
    xsi_set_current_line(147, ng0);
    t2 = (t0 + 7856);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_add(t9, 32, t4, 19, t5, 32);
    t6 = (t0 + 7856);
    xsi_vlogvar_wait_assign_value(t6, t9, 0, 0, 19, 0LL);
    goto LAB50;

LAB54:    t8 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB56;

LAB55:    *((unsigned int *)t9) = 1;
    goto LAB56;

LAB58:    *((unsigned int *)t10) = 1;
    goto LAB61;

LAB60:    t12 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB61;

LAB62:    t26 = (t0 + 7536);
    t32 = (t26 + 56U);
    t33 = *((char **)t32);
    t40 = (t0 + 1152);
    t41 = *((char **)t40);
    memset(t42, 0, 8);
    t40 = (t33 + 4);
    if (*((unsigned int *)t40) != 0)
        goto LAB66;

LAB65:    t43 = (t41 + 4);
    if (*((unsigned int *)t43) != 0)
        goto LAB66;

LAB69:    if (*((unsigned int *)t33) > *((unsigned int *)t41))
        goto LAB68;

LAB67:    *((unsigned int *)t42) = 1;

LAB68:    memset(t45, 0, 8);
    t46 = (t42 + 4);
    t21 = *((unsigned int *)t46);
    t22 = (~(t21));
    t23 = *((unsigned int *)t42);
    t24 = (t23 & t22);
    t27 = (t24 & 1U);
    if (t27 != 0)
        goto LAB70;

LAB71:    if (*((unsigned int *)t46) != 0)
        goto LAB72;

LAB73:    t28 = *((unsigned int *)t10);
    t29 = *((unsigned int *)t45);
    t30 = (t28 & t29);
    *((unsigned int *)t48) = t30;
    t49 = (t10 + 4);
    t50 = (t45 + 4);
    t51 = (t48 + 4);
    t31 = *((unsigned int *)t49);
    t34 = *((unsigned int *)t50);
    t35 = (t31 | t34);
    *((unsigned int *)t51) = t35;
    t36 = *((unsigned int *)t51);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB74;

LAB75:
LAB76:    goto LAB64;

LAB66:    t44 = (t42 + 4);
    *((unsigned int *)t42) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB68;

LAB70:    *((unsigned int *)t45) = 1;
    goto LAB73;

LAB72:    t47 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB73;

LAB74:    t38 = *((unsigned int *)t48);
    t39 = *((unsigned int *)t51);
    *((unsigned int *)t48) = (t38 | t39);
    t52 = (t10 + 4);
    t53 = (t45 + 4);
    t54 = *((unsigned int *)t10);
    t55 = (~(t54));
    t56 = *((unsigned int *)t52);
    t57 = (~(t56));
    t58 = *((unsigned int *)t45);
    t59 = (~(t58));
    t60 = *((unsigned int *)t53);
    t61 = (~(t60));
    t62 = (t55 & t57);
    t63 = (t59 & t61);
    t64 = (~(t62));
    t65 = (~(t63));
    t66 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t66 & t64);
    t67 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t67 & t65);
    t68 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t68 & t64);
    t69 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t69 & t65);
    goto LAB76;

LAB77:    xsi_set_current_line(155, ng0);

LAB80:    xsi_set_current_line(156, ng0);
    t76 = (t0 + 1968);
    t77 = *((char **)t76);
    t76 = (t0 + 4496);
    xsi_vlogvar_wait_assign_value(t76, t77, 0, 0, 1, 0LL);
    goto LAB79;

LAB83:    t8 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB85;

LAB87:    *((unsigned int *)t10) = 1;
    goto LAB90;

LAB89:    t12 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB90;

LAB91:    t26 = (t0 + 7696);
    t32 = (t26 + 56U);
    t33 = *((char **)t32);
    t40 = (t0 + 1696);
    t41 = *((char **)t40);
    memset(t42, 0, 8);
    t40 = (t33 + 4);
    if (*((unsigned int *)t40) != 0)
        goto LAB95;

LAB94:    t43 = (t41 + 4);
    if (*((unsigned int *)t43) != 0)
        goto LAB95;

LAB98:    if (*((unsigned int *)t33) < *((unsigned int *)t41))
        goto LAB96;

LAB97:    memset(t45, 0, 8);
    t46 = (t42 + 4);
    t21 = *((unsigned int *)t46);
    t22 = (~(t21));
    t23 = *((unsigned int *)t42);
    t24 = (t23 & t22);
    t27 = (t24 & 1U);
    if (t27 != 0)
        goto LAB99;

LAB100:    if (*((unsigned int *)t46) != 0)
        goto LAB101;

LAB102:    t28 = *((unsigned int *)t10);
    t29 = *((unsigned int *)t45);
    t30 = (t28 & t29);
    *((unsigned int *)t48) = t30;
    t49 = (t10 + 4);
    t50 = (t45 + 4);
    t51 = (t48 + 4);
    t31 = *((unsigned int *)t49);
    t34 = *((unsigned int *)t50);
    t35 = (t31 | t34);
    *((unsigned int *)t51) = t35;
    t36 = *((unsigned int *)t51);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB103;

LAB104:
LAB105:    goto LAB93;

LAB95:    t44 = (t42 + 4);
    *((unsigned int *)t42) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB97;

LAB96:    *((unsigned int *)t42) = 1;
    goto LAB97;

LAB99:    *((unsigned int *)t45) = 1;
    goto LAB102;

LAB101:    t47 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB102;

LAB103:    t38 = *((unsigned int *)t48);
    t39 = *((unsigned int *)t51);
    *((unsigned int *)t48) = (t38 | t39);
    t52 = (t10 + 4);
    t53 = (t45 + 4);
    t54 = *((unsigned int *)t10);
    t55 = (~(t54));
    t56 = *((unsigned int *)t52);
    t57 = (~(t56));
    t58 = *((unsigned int *)t45);
    t59 = (~(t58));
    t60 = *((unsigned int *)t53);
    t61 = (~(t60));
    t62 = (t55 & t57);
    t63 = (t59 & t61);
    t64 = (~(t62));
    t65 = (~(t63));
    t66 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t66 & t64);
    t67 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t67 & t65);
    t68 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t68 & t64);
    t69 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t69 & t65);
    goto LAB105;

LAB106:    xsi_set_current_line(163, ng0);

LAB109:    xsi_set_current_line(164, ng0);
    t76 = (t0 + 2104);
    t77 = *((char **)t76);
    t76 = (t0 + 4656);
    xsi_vlogvar_wait_assign_value(t76, t77, 0, 0, 1, 0LL);
    goto LAB108;

}

static void Always_173_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    t1 = (t0 + 9432U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(173, ng0);
    t2 = (t0 + 11024);
    *((int *)t2) = 1;
    t3 = (t0 + 9464);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(173, ng0);

LAB5:    xsi_set_current_line(176, ng0);
    t4 = (t0 + 7376);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 7216);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 2, 0LL);
    xsi_set_current_line(179, ng0);
    t2 = (t0 + 6896);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6736);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    xsi_set_current_line(180, ng0);
    t2 = (t0 + 5936);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5776);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 15, 0LL);
    xsi_set_current_line(181, ng0);
    t2 = (t0 + 5616);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5456);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 15, 0LL);
    xsi_set_current_line(182, ng0);
    t2 = (t0 + 7056);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4816);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(183, ng0);
    t2 = (t0 + 6576);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6416);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 0LL);
    xsi_set_current_line(184, ng0);
    t2 = (t0 + 6256);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6096);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 0LL);
    goto LAB2;

}

static void Always_189_3(char *t0)
{
    char t13[8];
    char t17[8];
    char t33[8];
    char t37[8];
    char t45[8];
    char t77[8];
    char t93[8];
    char t97[8];
    char t105[8];
    char t137[8];
    char t153[8];
    char t157[8];
    char t165[8];
    char t197[8];
    char t213[8];
    char t217[8];
    char t225[8];
    char t267[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int t9;
    char *t10;
    char *t11;
    char *t12;
    char *t14;
    char *t15;
    char *t16;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t34;
    char *t35;
    char *t36;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    char *t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    int t69;
    int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    char *t84;
    char *t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    char *t90;
    char *t91;
    char *t92;
    char *t94;
    char *t95;
    char *t96;
    char *t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    char *t104;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    char *t109;
    char *t110;
    char *t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    char *t119;
    char *t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    int t129;
    int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    char *t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    char *t144;
    char *t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    char *t149;
    char *t150;
    char *t151;
    char *t152;
    char *t154;
    char *t155;
    char *t156;
    char *t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    char *t164;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    char *t169;
    char *t170;
    char *t171;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    unsigned int t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    char *t179;
    char *t180;
    unsigned int t181;
    unsigned int t182;
    unsigned int t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    int t189;
    int t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    unsigned int t194;
    unsigned int t195;
    unsigned int t196;
    char *t198;
    unsigned int t199;
    unsigned int t200;
    unsigned int t201;
    unsigned int t202;
    unsigned int t203;
    char *t204;
    char *t205;
    unsigned int t206;
    unsigned int t207;
    unsigned int t208;
    char *t209;
    char *t210;
    char *t211;
    char *t212;
    char *t214;
    char *t215;
    char *t216;
    char *t218;
    unsigned int t219;
    unsigned int t220;
    unsigned int t221;
    unsigned int t222;
    unsigned int t223;
    char *t224;
    unsigned int t226;
    unsigned int t227;
    unsigned int t228;
    char *t229;
    char *t230;
    char *t231;
    unsigned int t232;
    unsigned int t233;
    unsigned int t234;
    unsigned int t235;
    unsigned int t236;
    unsigned int t237;
    unsigned int t238;
    char *t239;
    char *t240;
    unsigned int t241;
    unsigned int t242;
    unsigned int t243;
    unsigned int t244;
    unsigned int t245;
    unsigned int t246;
    unsigned int t247;
    unsigned int t248;
    int t249;
    int t250;
    unsigned int t251;
    unsigned int t252;
    unsigned int t253;
    unsigned int t254;
    unsigned int t255;
    unsigned int t256;
    char *t257;
    unsigned int t258;
    unsigned int t259;
    unsigned int t260;
    unsigned int t261;
    unsigned int t262;
    char *t263;
    char *t264;
    char *t265;
    char *t266;
    char *t268;

LAB0:    t1 = (t0 + 9680U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(189, ng0);
    t2 = (t0 + 11040);
    *((int *)t2) = 1;
    t3 = (t0 + 9712);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(189, ng0);

LAB5:    xsi_set_current_line(190, ng0);
    t4 = (t0 + 7216);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = (t0 + 472);
    t8 = *((char **)t7);
    t9 = xsi_vlog_unsigned_case_compare(t6, 2, t8, 32);
    if (t9 == 1)
        goto LAB7;

LAB8:    t2 = (t0 + 608);
    t3 = *((char **)t2);
    t9 = xsi_vlog_unsigned_case_compare(t6, 2, t3, 32);
    if (t9 == 1)
        goto LAB9;

LAB10:    t2 = (t0 + 744);
    t3 = *((char **)t2);
    t9 = xsi_vlog_unsigned_case_compare(t6, 2, t3, 32);
    if (t9 == 1)
        goto LAB11;

LAB12:
LAB14:
LAB13:    xsi_set_current_line(248, ng0);

LAB137:    xsi_set_current_line(249, ng0);
    t2 = (t0 + 6736);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6896);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    xsi_set_current_line(250, ng0);
    t2 = (t0 + 5776);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5936);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 15, 0LL);
    xsi_set_current_line(251, ng0);
    t2 = (t0 + 5456);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5616);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 15, 0LL);
    xsi_set_current_line(252, ng0);
    t2 = (t0 + 6416);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6576);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 0LL);
    xsi_set_current_line(253, ng0);
    t2 = (t0 + 6096);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6256);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 0LL);
    xsi_set_current_line(254, ng0);
    t2 = (t0 + 4816);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7056);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(255, ng0);
    t2 = (t0 + 7216);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7376);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 2, 0LL);

LAB15:    goto LAB2;

LAB7:    xsi_set_current_line(191, ng0);

LAB16:    xsi_set_current_line(192, ng0);
    t7 = (t0 + 4976);
    t10 = (t7 + 56U);
    t11 = *((char **)t10);
    t12 = ((char*)((ng5)));
    memset(t13, 0, 8);
    t14 = (t11 + 4);
    if (*((unsigned int *)t14) != 0)
        goto LAB18;

LAB17:    t15 = (t12 + 4);
    if (*((unsigned int *)t15) != 0)
        goto LAB18;

LAB21:    if (*((unsigned int *)t11) > *((unsigned int *)t12))
        goto LAB19;

LAB20:    memset(t17, 0, 8);
    t18 = (t13 + 4);
    t19 = *((unsigned int *)t18);
    t20 = (~(t19));
    t21 = *((unsigned int *)t13);
    t22 = (t21 & t20);
    t23 = (t22 & 1U);
    if (t23 != 0)
        goto LAB22;

LAB23:    if (*((unsigned int *)t18) != 0)
        goto LAB24;

LAB25:    t25 = (t17 + 4);
    t26 = *((unsigned int *)t17);
    t27 = *((unsigned int *)t25);
    t28 = (t26 || t27);
    if (t28 > 0)
        goto LAB26;

LAB27:    memcpy(t45, t17, 8);

LAB28:    memset(t77, 0, 8);
    t78 = (t45 + 4);
    t79 = *((unsigned int *)t78);
    t80 = (~(t79));
    t81 = *((unsigned int *)t45);
    t82 = (t81 & t80);
    t83 = (t82 & 1U);
    if (t83 != 0)
        goto LAB41;

LAB42:    if (*((unsigned int *)t78) != 0)
        goto LAB43;

LAB44:    t85 = (t77 + 4);
    t86 = *((unsigned int *)t77);
    t87 = *((unsigned int *)t85);
    t88 = (t86 || t87);
    if (t88 > 0)
        goto LAB45;

LAB46:    memcpy(t105, t77, 8);

LAB47:    memset(t137, 0, 8);
    t138 = (t105 + 4);
    t139 = *((unsigned int *)t138);
    t140 = (~(t139));
    t141 = *((unsigned int *)t105);
    t142 = (t141 & t140);
    t143 = (t142 & 1U);
    if (t143 != 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t138) != 0)
        goto LAB62;

LAB63:    t145 = (t137 + 4);
    t146 = *((unsigned int *)t137);
    t147 = *((unsigned int *)t145);
    t148 = (t146 || t147);
    if (t148 > 0)
        goto LAB64;

LAB65:    memcpy(t165, t137, 8);

LAB66:    memset(t197, 0, 8);
    t198 = (t165 + 4);
    t199 = *((unsigned int *)t198);
    t200 = (~(t199));
    t201 = *((unsigned int *)t165);
    t202 = (t201 & t200);
    t203 = (t202 & 1U);
    if (t203 != 0)
        goto LAB79;

LAB80:    if (*((unsigned int *)t198) != 0)
        goto LAB81;

LAB82:    t205 = (t197 + 4);
    t206 = *((unsigned int *)t197);
    t207 = *((unsigned int *)t205);
    t208 = (t206 || t207);
    if (t208 > 0)
        goto LAB83;

LAB84:    memcpy(t225, t197, 8);

LAB85:    t257 = (t225 + 4);
    t258 = *((unsigned int *)t257);
    t259 = (~(t258));
    t260 = *((unsigned int *)t225);
    t261 = (t260 & t259);
    t262 = (t261 != 0);
    if (t262 > 0)
        goto LAB98;

LAB99:    xsi_set_current_line(197, ng0);

LAB102:    xsi_set_current_line(198, ng0);
    t2 = (t0 + 6736);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6896);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    xsi_set_current_line(199, ng0);
    t2 = (t0 + 5776);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5936);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 15, 0LL);
    xsi_set_current_line(200, ng0);
    t2 = (t0 + 5456);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5616);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 15, 0LL);

LAB100:    xsi_set_current_line(203, ng0);
    t2 = (t0 + 4816);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7056);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(204, ng0);
    t2 = (t0 + 6416);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6576);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 0LL);
    xsi_set_current_line(205, ng0);
    t2 = (t0 + 6096);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6256);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 0LL);
    xsi_set_current_line(207, ng0);
    t2 = (t0 + 7696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1696);
    t7 = *((char **)t5);
    memset(t13, 0, 8);
    t5 = (t4 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB104;

LAB103:    t8 = (t7 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB104;

LAB107:    if (*((unsigned int *)t4) > *((unsigned int *)t7))
        goto LAB105;

LAB106:    t11 = (t13 + 4);
    t19 = *((unsigned int *)t11);
    t20 = (~(t19));
    t21 = *((unsigned int *)t13);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB108;

LAB109:    xsi_set_current_line(210, ng0);
    t2 = (t0 + 7216);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7376);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 2, 0LL);

LAB110:    goto LAB15;

LAB9:    xsi_set_current_line(213, ng0);

LAB111:    xsi_set_current_line(214, ng0);
    t2 = (t0 + 6736);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t7 = ((char*)((ng6)));
    memset(t13, 0, 8);
    t8 = (t5 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB113;

LAB112:    t10 = (t7 + 4);
    if (*((unsigned int *)t10) != 0)
        goto LAB113;

LAB116:    if (*((unsigned int *)t5) < *((unsigned int *)t7))
        goto LAB114;

LAB115:    t12 = (t13 + 4);
    t19 = *((unsigned int *)t12);
    t20 = (~(t19));
    t21 = *((unsigned int *)t13);
    t22 = (t21 & t20);
    t23 = (t22 != 0);
    if (t23 > 0)
        goto LAB117;

LAB118:    xsi_set_current_line(219, ng0);

LAB121:    xsi_set_current_line(220, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 7056);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(221, ng0);
    t2 = (t0 + 5776);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng8)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_rshift(t13, 15, t4, 15, t5, 32);
    t7 = (t0 + 6576);
    xsi_vlogvar_wait_assign_value(t7, t13, 0, 0, 10, 0LL);
    xsi_set_current_line(222, ng0);
    t2 = (t0 + 5456);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng8)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_rshift(t13, 15, t4, 15, t5, 32);
    t7 = (t0 + 6256);
    xsi_vlogvar_wait_assign_value(t7, t13, 0, 0, 10, 0LL);

LAB119:    xsi_set_current_line(225, ng0);
    t2 = (t0 + 6736);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6896);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 5, 0LL);
    xsi_set_current_line(226, ng0);
    t2 = (t0 + 5776);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5936);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 15, 0LL);
    xsi_set_current_line(227, ng0);
    t2 = (t0 + 5456);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5616);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 15, 0LL);
    xsi_set_current_line(229, ng0);
    t2 = (t0 + 4816);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t13, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t19 = *((unsigned int *)t4);
    t20 = *((unsigned int *)t5);
    t21 = (t19 ^ t20);
    t22 = *((unsigned int *)t7);
    t23 = *((unsigned int *)t8);
    t26 = (t22 ^ t23);
    t27 = (t21 | t26);
    t28 = *((unsigned int *)t7);
    t39 = *((unsigned int *)t8);
    t40 = (t28 | t39);
    t41 = (~(t40));
    t42 = (t27 & t41);
    if (t42 != 0)
        goto LAB125;

LAB122:    if (t40 != 0)
        goto LAB124;

LAB123:    *((unsigned int *)t13) = 1;

LAB125:    t11 = (t13 + 4);
    t43 = *((unsigned int *)t11);
    t46 = (~(t43));
    t47 = *((unsigned int *)t13);
    t48 = (t47 & t46);
    t52 = (t48 != 0);
    if (t52 > 0)
        goto LAB126;

LAB127:    xsi_set_current_line(232, ng0);
    t2 = (t0 + 472);
    t3 = *((char **)t2);
    t2 = (t0 + 7376);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 2, 0LL);

LAB128:    goto LAB15;

LAB11:    xsi_set_current_line(235, ng0);

LAB129:    xsi_set_current_line(236, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 7056);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(237, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5936);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 15, 0LL);
    xsi_set_current_line(238, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 5616);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 15, 0LL);
    xsi_set_current_line(239, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 6896);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 5, 0LL);
    xsi_set_current_line(240, ng0);
    t2 = (t0 + 6416);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6576);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 0LL);
    xsi_set_current_line(241, ng0);
    t2 = (t0 + 6096);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6256);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 0LL);
    xsi_set_current_line(243, ng0);
    t2 = (t0 + 7696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t13, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t19 = *((unsigned int *)t4);
    t20 = *((unsigned int *)t5);
    t21 = (t19 ^ t20);
    t22 = *((unsigned int *)t7);
    t23 = *((unsigned int *)t8);
    t26 = (t22 ^ t23);
    t27 = (t21 | t26);
    t28 = *((unsigned int *)t7);
    t39 = *((unsigned int *)t8);
    t40 = (t28 | t39);
    t41 = (~(t40));
    t42 = (t27 & t41);
    if (t42 != 0)
        goto LAB133;

LAB130:    if (t40 != 0)
        goto LAB132;

LAB131:    *((unsigned int *)t13) = 1;

LAB133:    t11 = (t13 + 4);
    t43 = *((unsigned int *)t11);
    t46 = (~(t43));
    t47 = *((unsigned int *)t13);
    t48 = (t47 & t46);
    t52 = (t48 != 0);
    if (t52 > 0)
        goto LAB134;

LAB135:    xsi_set_current_line(246, ng0);
    t2 = (t0 + 7216);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7376);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 2, 0LL);

LAB136:    goto LAB15;

LAB18:    t16 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB20;

LAB19:    *((unsigned int *)t13) = 1;
    goto LAB20;

LAB22:    *((unsigned int *)t17) = 1;
    goto LAB25;

LAB24:    t24 = (t17 + 4);
    *((unsigned int *)t17) = 1;
    *((unsigned int *)t24) = 1;
    goto LAB25;

LAB26:    t29 = (t0 + 6736);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    t32 = ((char*)((ng6)));
    memset(t33, 0, 8);
    t34 = (t31 + 4);
    if (*((unsigned int *)t34) != 0)
        goto LAB30;

LAB29:    t35 = (t32 + 4);
    if (*((unsigned int *)t35) != 0)
        goto LAB30;

LAB33:    if (*((unsigned int *)t31) < *((unsigned int *)t32))
        goto LAB31;

LAB32:    memset(t37, 0, 8);
    t38 = (t33 + 4);
    t39 = *((unsigned int *)t38);
    t40 = (~(t39));
    t41 = *((unsigned int *)t33);
    t42 = (t41 & t40);
    t43 = (t42 & 1U);
    if (t43 != 0)
        goto LAB34;

LAB35:    if (*((unsigned int *)t38) != 0)
        goto LAB36;

LAB37:    t46 = *((unsigned int *)t17);
    t47 = *((unsigned int *)t37);
    t48 = (t46 & t47);
    *((unsigned int *)t45) = t48;
    t49 = (t17 + 4);
    t50 = (t37 + 4);
    t51 = (t45 + 4);
    t52 = *((unsigned int *)t49);
    t53 = *((unsigned int *)t50);
    t54 = (t52 | t53);
    *((unsigned int *)t51) = t54;
    t55 = *((unsigned int *)t51);
    t56 = (t55 != 0);
    if (t56 == 1)
        goto LAB38;

LAB39:
LAB40:    goto LAB28;

LAB30:    t36 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB32;

LAB31:    *((unsigned int *)t33) = 1;
    goto LAB32;

LAB34:    *((unsigned int *)t37) = 1;
    goto LAB37;

LAB36:    t44 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB37;

LAB38:    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t51);
    *((unsigned int *)t45) = (t57 | t58);
    t59 = (t17 + 4);
    t60 = (t37 + 4);
    t61 = *((unsigned int *)t17);
    t62 = (~(t61));
    t63 = *((unsigned int *)t59);
    t64 = (~(t63));
    t65 = *((unsigned int *)t37);
    t66 = (~(t65));
    t67 = *((unsigned int *)t60);
    t68 = (~(t67));
    t69 = (t62 & t64);
    t70 = (t66 & t68);
    t71 = (~(t69));
    t72 = (~(t70));
    t73 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t73 & t71);
    t74 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t74 & t72);
    t75 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t75 & t71);
    t76 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t76 & t72);
    goto LAB40;

LAB41:    *((unsigned int *)t77) = 1;
    goto LAB44;

LAB43:    t84 = (t77 + 4);
    *((unsigned int *)t77) = 1;
    *((unsigned int *)t84) = 1;
    goto LAB44;

LAB45:    t89 = (t0 + 7696);
    t90 = (t89 + 56U);
    t91 = *((char **)t90);
    t92 = ((char*)((ng7)));
    memset(t93, 0, 8);
    t94 = (t91 + 4);
    if (*((unsigned int *)t94) != 0)
        goto LAB49;

LAB48:    t95 = (t92 + 4);
    if (*((unsigned int *)t95) != 0)
        goto LAB49;

LAB52:    if (*((unsigned int *)t91) < *((unsigned int *)t92))
        goto LAB50;

LAB51:    memset(t97, 0, 8);
    t98 = (t93 + 4);
    t99 = *((unsigned int *)t98);
    t100 = (~(t99));
    t101 = *((unsigned int *)t93);
    t102 = (t101 & t100);
    t103 = (t102 & 1U);
    if (t103 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t98) != 0)
        goto LAB55;

LAB56:    t106 = *((unsigned int *)t77);
    t107 = *((unsigned int *)t97);
    t108 = (t106 & t107);
    *((unsigned int *)t105) = t108;
    t109 = (t77 + 4);
    t110 = (t97 + 4);
    t111 = (t105 + 4);
    t112 = *((unsigned int *)t109);
    t113 = *((unsigned int *)t110);
    t114 = (t112 | t113);
    *((unsigned int *)t111) = t114;
    t115 = *((unsigned int *)t111);
    t116 = (t115 != 0);
    if (t116 == 1)
        goto LAB57;

LAB58:
LAB59:    goto LAB47;

LAB49:    t96 = (t93 + 4);
    *((unsigned int *)t93) = 1;
    *((unsigned int *)t96) = 1;
    goto LAB51;

LAB50:    *((unsigned int *)t93) = 1;
    goto LAB51;

LAB53:    *((unsigned int *)t97) = 1;
    goto LAB56;

LAB55:    t104 = (t97 + 4);
    *((unsigned int *)t97) = 1;
    *((unsigned int *)t104) = 1;
    goto LAB56;

LAB57:    t117 = *((unsigned int *)t105);
    t118 = *((unsigned int *)t111);
    *((unsigned int *)t105) = (t117 | t118);
    t119 = (t77 + 4);
    t120 = (t97 + 4);
    t121 = *((unsigned int *)t77);
    t122 = (~(t121));
    t123 = *((unsigned int *)t119);
    t124 = (~(t123));
    t125 = *((unsigned int *)t97);
    t126 = (~(t125));
    t127 = *((unsigned int *)t120);
    t128 = (~(t127));
    t129 = (t122 & t124);
    t130 = (t126 & t128);
    t131 = (~(t129));
    t132 = (~(t130));
    t133 = *((unsigned int *)t111);
    *((unsigned int *)t111) = (t133 & t131);
    t134 = *((unsigned int *)t111);
    *((unsigned int *)t111) = (t134 & t132);
    t135 = *((unsigned int *)t105);
    *((unsigned int *)t105) = (t135 & t131);
    t136 = *((unsigned int *)t105);
    *((unsigned int *)t105) = (t136 & t132);
    goto LAB59;

LAB60:    *((unsigned int *)t137) = 1;
    goto LAB63;

LAB62:    t144 = (t137 + 4);
    *((unsigned int *)t137) = 1;
    *((unsigned int *)t144) = 1;
    goto LAB63;

LAB64:    t149 = (t0 + 7536);
    t150 = (t149 + 56U);
    t151 = *((char **)t150);
    t152 = ((char*)((ng4)));
    memset(t153, 0, 8);
    t154 = (t151 + 4);
    if (*((unsigned int *)t154) != 0)
        goto LAB68;

LAB67:    t155 = (t152 + 4);
    if (*((unsigned int *)t155) != 0)
        goto LAB68;

LAB71:    if (*((unsigned int *)t151) < *((unsigned int *)t152))
        goto LAB69;

LAB70:    memset(t157, 0, 8);
    t158 = (t153 + 4);
    t159 = *((unsigned int *)t158);
    t160 = (~(t159));
    t161 = *((unsigned int *)t153);
    t162 = (t161 & t160);
    t163 = (t162 & 1U);
    if (t163 != 0)
        goto LAB72;

LAB73:    if (*((unsigned int *)t158) != 0)
        goto LAB74;

LAB75:    t166 = *((unsigned int *)t137);
    t167 = *((unsigned int *)t157);
    t168 = (t166 & t167);
    *((unsigned int *)t165) = t168;
    t169 = (t137 + 4);
    t170 = (t157 + 4);
    t171 = (t165 + 4);
    t172 = *((unsigned int *)t169);
    t173 = *((unsigned int *)t170);
    t174 = (t172 | t173);
    *((unsigned int *)t171) = t174;
    t175 = *((unsigned int *)t171);
    t176 = (t175 != 0);
    if (t176 == 1)
        goto LAB76;

LAB77:
LAB78:    goto LAB66;

LAB68:    t156 = (t153 + 4);
    *((unsigned int *)t153) = 1;
    *((unsigned int *)t156) = 1;
    goto LAB70;

LAB69:    *((unsigned int *)t153) = 1;
    goto LAB70;

LAB72:    *((unsigned int *)t157) = 1;
    goto LAB75;

LAB74:    t164 = (t157 + 4);
    *((unsigned int *)t157) = 1;
    *((unsigned int *)t164) = 1;
    goto LAB75;

LAB76:    t177 = *((unsigned int *)t165);
    t178 = *((unsigned int *)t171);
    *((unsigned int *)t165) = (t177 | t178);
    t179 = (t137 + 4);
    t180 = (t157 + 4);
    t181 = *((unsigned int *)t137);
    t182 = (~(t181));
    t183 = *((unsigned int *)t179);
    t184 = (~(t183));
    t185 = *((unsigned int *)t157);
    t186 = (~(t185));
    t187 = *((unsigned int *)t180);
    t188 = (~(t187));
    t189 = (t182 & t184);
    t190 = (t186 & t188);
    t191 = (~(t189));
    t192 = (~(t190));
    t193 = *((unsigned int *)t171);
    *((unsigned int *)t171) = (t193 & t191);
    t194 = *((unsigned int *)t171);
    *((unsigned int *)t171) = (t194 & t192);
    t195 = *((unsigned int *)t165);
    *((unsigned int *)t165) = (t195 & t191);
    t196 = *((unsigned int *)t165);
    *((unsigned int *)t165) = (t196 & t192);
    goto LAB78;

LAB79:    *((unsigned int *)t197) = 1;
    goto LAB82;

LAB81:    t204 = (t197 + 4);
    *((unsigned int *)t197) = 1;
    *((unsigned int *)t204) = 1;
    goto LAB82;

LAB83:    t209 = (t0 + 7536);
    t210 = (t209 + 56U);
    t211 = *((char **)t210);
    t212 = ((char*)((ng8)));
    memset(t213, 0, 8);
    t214 = (t211 + 4);
    if (*((unsigned int *)t214) != 0)
        goto LAB87;

LAB86:    t215 = (t212 + 4);
    if (*((unsigned int *)t215) != 0)
        goto LAB87;

LAB90:    if (*((unsigned int *)t211) > *((unsigned int *)t212))
        goto LAB88;

LAB89:    memset(t217, 0, 8);
    t218 = (t213 + 4);
    t219 = *((unsigned int *)t218);
    t220 = (~(t219));
    t221 = *((unsigned int *)t213);
    t222 = (t221 & t220);
    t223 = (t222 & 1U);
    if (t223 != 0)
        goto LAB91;

LAB92:    if (*((unsigned int *)t218) != 0)
        goto LAB93;

LAB94:    t226 = *((unsigned int *)t197);
    t227 = *((unsigned int *)t217);
    t228 = (t226 & t227);
    *((unsigned int *)t225) = t228;
    t229 = (t197 + 4);
    t230 = (t217 + 4);
    t231 = (t225 + 4);
    t232 = *((unsigned int *)t229);
    t233 = *((unsigned int *)t230);
    t234 = (t232 | t233);
    *((unsigned int *)t231) = t234;
    t235 = *((unsigned int *)t231);
    t236 = (t235 != 0);
    if (t236 == 1)
        goto LAB95;

LAB96:
LAB97:    goto LAB85;

LAB87:    t216 = (t213 + 4);
    *((unsigned int *)t213) = 1;
    *((unsigned int *)t216) = 1;
    goto LAB89;

LAB88:    *((unsigned int *)t213) = 1;
    goto LAB89;

LAB91:    *((unsigned int *)t217) = 1;
    goto LAB94;

LAB93:    t224 = (t217 + 4);
    *((unsigned int *)t217) = 1;
    *((unsigned int *)t224) = 1;
    goto LAB94;

LAB95:    t237 = *((unsigned int *)t225);
    t238 = *((unsigned int *)t231);
    *((unsigned int *)t225) = (t237 | t238);
    t239 = (t197 + 4);
    t240 = (t217 + 4);
    t241 = *((unsigned int *)t197);
    t242 = (~(t241));
    t243 = *((unsigned int *)t239);
    t244 = (~(t243));
    t245 = *((unsigned int *)t217);
    t246 = (~(t245));
    t247 = *((unsigned int *)t240);
    t248 = (~(t247));
    t249 = (t242 & t244);
    t250 = (t246 & t248);
    t251 = (~(t249));
    t252 = (~(t250));
    t253 = *((unsigned int *)t231);
    *((unsigned int *)t231) = (t253 & t251);
    t254 = *((unsigned int *)t231);
    *((unsigned int *)t231) = (t254 & t252);
    t255 = *((unsigned int *)t225);
    *((unsigned int *)t225) = (t255 & t251);
    t256 = *((unsigned int *)t225);
    *((unsigned int *)t225) = (t256 & t252);
    goto LAB97;

LAB98:    xsi_set_current_line(192, ng0);

LAB101:    xsi_set_current_line(193, ng0);
    t263 = (t0 + 6736);
    t264 = (t263 + 56U);
    t265 = *((char **)t264);
    t266 = ((char*)((ng3)));
    memset(t267, 0, 8);
    xsi_vlog_unsigned_add(t267, 5, t265, 5, t266, 5);
    t268 = (t0 + 6896);
    xsi_vlogvar_wait_assign_value(t268, t267, 0, 0, 5, 0LL);
    xsi_set_current_line(194, ng0);
    t2 = (t0 + 5776);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7696);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_add(t13, 15, t4, 15, t8, 10);
    t10 = (t0 + 5936);
    xsi_vlogvar_wait_assign_value(t10, t13, 0, 0, 15, 0LL);
    xsi_set_current_line(195, ng0);
    t2 = (t0 + 5456);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7536);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_add(t13, 15, t4, 15, t8, 10);
    t10 = (t0 + 5616);
    xsi_vlogvar_wait_assign_value(t10, t13, 0, 0, 15, 0LL);
    goto LAB100;

LAB104:    t10 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB106;

LAB105:    *((unsigned int *)t13) = 1;
    goto LAB106;

LAB108:    xsi_set_current_line(208, ng0);
    t12 = (t0 + 608);
    t14 = *((char **)t12);
    t12 = (t0 + 7376);
    xsi_vlogvar_wait_assign_value(t12, t14, 0, 0, 2, 0LL);
    goto LAB110;

LAB113:    t11 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB115;

LAB114:    *((unsigned int *)t13) = 1;
    goto LAB115;

LAB117:    xsi_set_current_line(214, ng0);

LAB120:    xsi_set_current_line(215, ng0);
    t14 = ((char*)((ng2)));
    t15 = (t0 + 7056);
    xsi_vlogvar_wait_assign_value(t15, t14, 0, 0, 1, 0LL);
    xsi_set_current_line(216, ng0);
    t2 = (t0 + 6416);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6576);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 0LL);
    xsi_set_current_line(217, ng0);
    t2 = (t0 + 6096);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6256);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 10, 0LL);
    goto LAB119;

LAB124:    t10 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB125;

LAB126:    xsi_set_current_line(230, ng0);
    t12 = (t0 + 744);
    t14 = *((char **)t12);
    t12 = (t0 + 7376);
    xsi_vlogvar_wait_assign_value(t12, t14, 0, 0, 2, 0LL);
    goto LAB128;

LAB132:    t10 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB133;

LAB134:    xsi_set_current_line(244, ng0);
    t12 = (t0 + 472);
    t14 = *((char **)t12);
    t12 = (t0 + 7376);
    xsi_vlogvar_wait_assign_value(t12, t14, 0, 0, 2, 0LL);
    goto LAB136;

}

static void Always_261_4(char *t0)
{
    char t11[8];
    char t12[8];
    char t16[8];
    char t35[8];
    char t36[8];
    char t40[8];
    char t48[8];
    char t80[8];
    char t99[8];
    char t100[8];
    char t104[8];
    char t112[8];
    char t144[8];
    char t163[8];
    char t164[8];
    char t168[8];
    char t176[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t13;
    char *t14;
    char *t15;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t37;
    char *t38;
    char *t39;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t47;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    char *t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    int t72;
    int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    char *t87;
    char *t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;
    char *t93;
    char *t94;
    char *t95;
    char *t96;
    char *t97;
    char *t98;
    char *t101;
    char *t102;
    char *t103;
    char *t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    char *t111;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    char *t116;
    char *t117;
    char *t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    char *t126;
    char *t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    int t136;
    int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    char *t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    char *t151;
    char *t152;
    unsigned int t153;
    unsigned int t154;
    unsigned int t155;
    char *t156;
    char *t157;
    char *t158;
    char *t159;
    char *t160;
    char *t161;
    char *t162;
    char *t165;
    char *t166;
    char *t167;
    char *t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    char *t175;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    char *t180;
    char *t181;
    char *t182;
    unsigned int t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    unsigned int t189;
    char *t190;
    char *t191;
    unsigned int t192;
    unsigned int t193;
    unsigned int t194;
    unsigned int t195;
    unsigned int t196;
    unsigned int t197;
    unsigned int t198;
    unsigned int t199;
    int t200;
    int t201;
    unsigned int t202;
    unsigned int t203;
    unsigned int t204;
    unsigned int t205;
    unsigned int t206;
    unsigned int t207;
    char *t208;
    unsigned int t209;
    unsigned int t210;
    unsigned int t211;
    unsigned int t212;
    unsigned int t213;
    char *t214;
    char *t215;

LAB0:    t1 = (t0 + 9928U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(261, ng0);
    t2 = (t0 + 11056);
    *((int *)t2) = 1;
    t3 = (t0 + 9960);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(262, ng0);

LAB5:    xsi_set_current_line(263, ng0);
    t4 = (t0 + 7696);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 6416);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = ((char*)((ng9)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_add(t11, 32, t9, 10, t10, 32);
    memset(t12, 0, 8);
    t13 = (t6 + 4);
    if (*((unsigned int *)t13) != 0)
        goto LAB7;

LAB6:    t14 = (t11 + 4);
    if (*((unsigned int *)t14) != 0)
        goto LAB7;

LAB10:    if (*((unsigned int *)t6) < *((unsigned int *)t11))
        goto LAB8;

LAB9:    memset(t16, 0, 8);
    t17 = (t12 + 4);
    t18 = *((unsigned int *)t17);
    t19 = (~(t18));
    t20 = *((unsigned int *)t12);
    t21 = (t20 & t19);
    t22 = (t21 & 1U);
    if (t22 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t17) != 0)
        goto LAB13;

LAB14:    t24 = (t16 + 4);
    t25 = *((unsigned int *)t16);
    t26 = *((unsigned int *)t24);
    t27 = (t25 || t26);
    if (t27 > 0)
        goto LAB15;

LAB16:    memcpy(t48, t16, 8);

LAB17:    memset(t80, 0, 8);
    t81 = (t48 + 4);
    t82 = *((unsigned int *)t81);
    t83 = (~(t82));
    t84 = *((unsigned int *)t48);
    t85 = (t84 & t83);
    t86 = (t85 & 1U);
    if (t86 != 0)
        goto LAB30;

LAB31:    if (*((unsigned int *)t81) != 0)
        goto LAB32;

LAB33:    t88 = (t80 + 4);
    t89 = *((unsigned int *)t80);
    t90 = *((unsigned int *)t88);
    t91 = (t89 || t90);
    if (t91 > 0)
        goto LAB34;

LAB35:    memcpy(t112, t80, 8);

LAB36:    memset(t144, 0, 8);
    t145 = (t112 + 4);
    t146 = *((unsigned int *)t145);
    t147 = (~(t146));
    t148 = *((unsigned int *)t112);
    t149 = (t148 & t147);
    t150 = (t149 & 1U);
    if (t150 != 0)
        goto LAB49;

LAB50:    if (*((unsigned int *)t145) != 0)
        goto LAB51;

LAB52:    t152 = (t144 + 4);
    t153 = *((unsigned int *)t144);
    t154 = *((unsigned int *)t152);
    t155 = (t153 || t154);
    if (t155 > 0)
        goto LAB53;

LAB54:    memcpy(t176, t144, 8);

LAB55:    t208 = (t176 + 4);
    t209 = *((unsigned int *)t208);
    t210 = (~(t209));
    t211 = *((unsigned int *)t176);
    t212 = (t211 & t210);
    t213 = (t212 != 0);
    if (t213 > 0)
        goto LAB68;

LAB69:    xsi_set_current_line(270, ng0);

LAB72:    xsi_set_current_line(271, ng0);
    t2 = (t0 + 4976);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4016);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    xsi_set_current_line(272, ng0);
    t2 = (t0 + 5136);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4176);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    xsi_set_current_line(273, ng0);
    t2 = (t0 + 5296);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4336);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);

LAB70:    goto LAB2;

LAB7:    t15 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB9;

LAB8:    *((unsigned int *)t12) = 1;
    goto LAB9;

LAB11:    *((unsigned int *)t16) = 1;
    goto LAB14;

LAB13:    t23 = (t16 + 4);
    *((unsigned int *)t16) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB14;

LAB15:    t28 = (t0 + 7696);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    t31 = (t0 + 6416);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = ((char*)((ng9)));
    memset(t35, 0, 8);
    xsi_vlog_unsigned_minus(t35, 32, t33, 10, t34, 32);
    memset(t36, 0, 8);
    t37 = (t30 + 4);
    if (*((unsigned int *)t37) != 0)
        goto LAB19;

LAB18:    t38 = (t35 + 4);
    if (*((unsigned int *)t38) != 0)
        goto LAB19;

LAB22:    if (*((unsigned int *)t30) > *((unsigned int *)t35))
        goto LAB20;

LAB21:    memset(t40, 0, 8);
    t41 = (t36 + 4);
    t42 = *((unsigned int *)t41);
    t43 = (~(t42));
    t44 = *((unsigned int *)t36);
    t45 = (t44 & t43);
    t46 = (t45 & 1U);
    if (t46 != 0)
        goto LAB23;

LAB24:    if (*((unsigned int *)t41) != 0)
        goto LAB25;

LAB26:    t49 = *((unsigned int *)t16);
    t50 = *((unsigned int *)t40);
    t51 = (t49 & t50);
    *((unsigned int *)t48) = t51;
    t52 = (t16 + 4);
    t53 = (t40 + 4);
    t54 = (t48 + 4);
    t55 = *((unsigned int *)t52);
    t56 = *((unsigned int *)t53);
    t57 = (t55 | t56);
    *((unsigned int *)t54) = t57;
    t58 = *((unsigned int *)t54);
    t59 = (t58 != 0);
    if (t59 == 1)
        goto LAB27;

LAB28:
LAB29:    goto LAB17;

LAB19:    t39 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB21;

LAB20:    *((unsigned int *)t36) = 1;
    goto LAB21;

LAB23:    *((unsigned int *)t40) = 1;
    goto LAB26;

LAB25:    t47 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB26;

LAB27:    t60 = *((unsigned int *)t48);
    t61 = *((unsigned int *)t54);
    *((unsigned int *)t48) = (t60 | t61);
    t62 = (t16 + 4);
    t63 = (t40 + 4);
    t64 = *((unsigned int *)t16);
    t65 = (~(t64));
    t66 = *((unsigned int *)t62);
    t67 = (~(t66));
    t68 = *((unsigned int *)t40);
    t69 = (~(t68));
    t70 = *((unsigned int *)t63);
    t71 = (~(t70));
    t72 = (t65 & t67);
    t73 = (t69 & t71);
    t74 = (~(t72));
    t75 = (~(t73));
    t76 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t76 & t74);
    t77 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t77 & t75);
    t78 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t78 & t74);
    t79 = *((unsigned int *)t48);
    *((unsigned int *)t48) = (t79 & t75);
    goto LAB29;

LAB30:    *((unsigned int *)t80) = 1;
    goto LAB33;

LAB32:    t87 = (t80 + 4);
    *((unsigned int *)t80) = 1;
    *((unsigned int *)t87) = 1;
    goto LAB33;

LAB34:    t92 = (t0 + 7536);
    t93 = (t92 + 56U);
    t94 = *((char **)t93);
    t95 = (t0 + 6096);
    t96 = (t95 + 56U);
    t97 = *((char **)t96);
    t98 = ((char*)((ng9)));
    memset(t99, 0, 8);
    xsi_vlog_unsigned_add(t99, 32, t97, 10, t98, 32);
    memset(t100, 0, 8);
    t101 = (t94 + 4);
    if (*((unsigned int *)t101) != 0)
        goto LAB38;

LAB37:    t102 = (t99 + 4);
    if (*((unsigned int *)t102) != 0)
        goto LAB38;

LAB41:    if (*((unsigned int *)t94) < *((unsigned int *)t99))
        goto LAB39;

LAB40:    memset(t104, 0, 8);
    t105 = (t100 + 4);
    t106 = *((unsigned int *)t105);
    t107 = (~(t106));
    t108 = *((unsigned int *)t100);
    t109 = (t108 & t107);
    t110 = (t109 & 1U);
    if (t110 != 0)
        goto LAB42;

LAB43:    if (*((unsigned int *)t105) != 0)
        goto LAB44;

LAB45:    t113 = *((unsigned int *)t80);
    t114 = *((unsigned int *)t104);
    t115 = (t113 & t114);
    *((unsigned int *)t112) = t115;
    t116 = (t80 + 4);
    t117 = (t104 + 4);
    t118 = (t112 + 4);
    t119 = *((unsigned int *)t116);
    t120 = *((unsigned int *)t117);
    t121 = (t119 | t120);
    *((unsigned int *)t118) = t121;
    t122 = *((unsigned int *)t118);
    t123 = (t122 != 0);
    if (t123 == 1)
        goto LAB46;

LAB47:
LAB48:    goto LAB36;

LAB38:    t103 = (t100 + 4);
    *((unsigned int *)t100) = 1;
    *((unsigned int *)t103) = 1;
    goto LAB40;

LAB39:    *((unsigned int *)t100) = 1;
    goto LAB40;

LAB42:    *((unsigned int *)t104) = 1;
    goto LAB45;

LAB44:    t111 = (t104 + 4);
    *((unsigned int *)t104) = 1;
    *((unsigned int *)t111) = 1;
    goto LAB45;

LAB46:    t124 = *((unsigned int *)t112);
    t125 = *((unsigned int *)t118);
    *((unsigned int *)t112) = (t124 | t125);
    t126 = (t80 + 4);
    t127 = (t104 + 4);
    t128 = *((unsigned int *)t80);
    t129 = (~(t128));
    t130 = *((unsigned int *)t126);
    t131 = (~(t130));
    t132 = *((unsigned int *)t104);
    t133 = (~(t132));
    t134 = *((unsigned int *)t127);
    t135 = (~(t134));
    t136 = (t129 & t131);
    t137 = (t133 & t135);
    t138 = (~(t136));
    t139 = (~(t137));
    t140 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t140 & t138);
    t141 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t141 & t139);
    t142 = *((unsigned int *)t112);
    *((unsigned int *)t112) = (t142 & t138);
    t143 = *((unsigned int *)t112);
    *((unsigned int *)t112) = (t143 & t139);
    goto LAB48;

LAB49:    *((unsigned int *)t144) = 1;
    goto LAB52;

LAB51:    t151 = (t144 + 4);
    *((unsigned int *)t144) = 1;
    *((unsigned int *)t151) = 1;
    goto LAB52;

LAB53:    t156 = (t0 + 7536);
    t157 = (t156 + 56U);
    t158 = *((char **)t157);
    t159 = (t0 + 6096);
    t160 = (t159 + 56U);
    t161 = *((char **)t160);
    t162 = ((char*)((ng9)));
    memset(t163, 0, 8);
    xsi_vlog_unsigned_minus(t163, 32, t161, 10, t162, 32);
    memset(t164, 0, 8);
    t165 = (t158 + 4);
    if (*((unsigned int *)t165) != 0)
        goto LAB57;

LAB56:    t166 = (t163 + 4);
    if (*((unsigned int *)t166) != 0)
        goto LAB57;

LAB60:    if (*((unsigned int *)t158) > *((unsigned int *)t163))
        goto LAB58;

LAB59:    memset(t168, 0, 8);
    t169 = (t164 + 4);
    t170 = *((unsigned int *)t169);
    t171 = (~(t170));
    t172 = *((unsigned int *)t164);
    t173 = (t172 & t171);
    t174 = (t173 & 1U);
    if (t174 != 0)
        goto LAB61;

LAB62:    if (*((unsigned int *)t169) != 0)
        goto LAB63;

LAB64:    t177 = *((unsigned int *)t144);
    t178 = *((unsigned int *)t168);
    t179 = (t177 & t178);
    *((unsigned int *)t176) = t179;
    t180 = (t144 + 4);
    t181 = (t168 + 4);
    t182 = (t176 + 4);
    t183 = *((unsigned int *)t180);
    t184 = *((unsigned int *)t181);
    t185 = (t183 | t184);
    *((unsigned int *)t182) = t185;
    t186 = *((unsigned int *)t182);
    t187 = (t186 != 0);
    if (t187 == 1)
        goto LAB65;

LAB66:
LAB67:    goto LAB55;

LAB57:    t167 = (t164 + 4);
    *((unsigned int *)t164) = 1;
    *((unsigned int *)t167) = 1;
    goto LAB59;

LAB58:    *((unsigned int *)t164) = 1;
    goto LAB59;

LAB61:    *((unsigned int *)t168) = 1;
    goto LAB64;

LAB63:    t175 = (t168 + 4);
    *((unsigned int *)t168) = 1;
    *((unsigned int *)t175) = 1;
    goto LAB64;

LAB65:    t188 = *((unsigned int *)t176);
    t189 = *((unsigned int *)t182);
    *((unsigned int *)t176) = (t188 | t189);
    t190 = (t144 + 4);
    t191 = (t168 + 4);
    t192 = *((unsigned int *)t144);
    t193 = (~(t192));
    t194 = *((unsigned int *)t190);
    t195 = (~(t194));
    t196 = *((unsigned int *)t168);
    t197 = (~(t196));
    t198 = *((unsigned int *)t191);
    t199 = (~(t198));
    t200 = (t193 & t195);
    t201 = (t197 & t199);
    t202 = (~(t200));
    t203 = (~(t201));
    t204 = *((unsigned int *)t182);
    *((unsigned int *)t182) = (t204 & t202);
    t205 = *((unsigned int *)t182);
    *((unsigned int *)t182) = (t205 & t203);
    t206 = *((unsigned int *)t176);
    *((unsigned int *)t176) = (t206 & t202);
    t207 = *((unsigned int *)t176);
    *((unsigned int *)t176) = (t207 & t203);
    goto LAB67;

LAB68:    xsi_set_current_line(264, ng0);

LAB71:    xsi_set_current_line(265, ng0);
    t214 = ((char*)((ng2)));
    t215 = (t0 + 4016);
    xsi_vlogvar_wait_assign_value(t215, t214, 0, 0, 4, 0LL);
    xsi_set_current_line(266, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4176);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    xsi_set_current_line(267, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4336);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    goto LAB70;

}

static void Cont_277_5(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;

LAB0:    t1 = (t0 + 10176U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(277, ng0);
    t2 = (t0 + 6736);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng2)));
    xsi_vlogtype_concat(t3, 8, 8, 2U, t6, 3, t5, 5);
    t7 = (t0 + 11248);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memset(t11, 0, 8);
    t12 = 255U;
    t13 = t12;
    t14 = (t3 + 4);
    t15 = *((unsigned int *)t3);
    t12 = (t12 & t15);
    t16 = *((unsigned int *)t14);
    t13 = (t13 & t16);
    t17 = (t11 + 4);
    t18 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t18 | t12);
    t19 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t19 | t13);
    xsi_driver_vfirst_trans(t7, 0, 7);
    t20 = (t0 + 11072);
    *((int *)t20) = 1;

LAB1:    return;
}

static void Cont_279_6(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;

LAB0:    t1 = (t0 + 10424U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(279, ng0);
    t2 = (t0 + 6096);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng10)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_minus(t6, 10, t4, 10, t5, 10);
    t7 = (t0 + 11312);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memset(t11, 0, 8);
    t12 = 1023U;
    t13 = t12;
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t6);
    t12 = (t12 & t15);
    t16 = *((unsigned int *)t14);
    t13 = (t13 & t16);
    t17 = (t11 + 4);
    t18 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t18 | t12);
    t19 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t19 | t13);
    xsi_driver_vfirst_trans(t7, 0, 9);
    t20 = (t0 + 11088);
    *((int *)t20) = 1;

LAB1:    return;
}

static void Cont_280_7(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;

LAB0:    t1 = (t0 + 10672U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(280, ng0);
    t2 = (t0 + 6416);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng11)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_minus(t6, 10, t4, 10, t5, 10);
    t7 = (t0 + 11376);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memset(t11, 0, 8);
    t12 = 1023U;
    t13 = t12;
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t6);
    t12 = (t12 & t15);
    t16 = *((unsigned int *)t14);
    t13 = (t13 & t16);
    t17 = (t11 + 4);
    t18 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t18 | t12);
    t19 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t19 | t13);
    xsi_driver_vfirst_trans(t7, 0, 9);
    t20 = (t0 + 11104);
    *((int *)t20) = 1;

LAB1:    return;
}


extern void work_m_00000000004062727878_2483525352_init()
{
	static char *pe[] = {(void *)Cont_113_0,(void *)Always_114_1,(void *)Always_173_2,(void *)Always_189_3,(void *)Always_261_4,(void *)Cont_277_5,(void *)Cont_279_6,(void *)Cont_280_7};
	xsi_register_didat("work_m_00000000004062727878_2483525352", "isim/tb_ov7670_top_isim_beh.exe.sim/work/m_00000000004062727878_2483525352.didat");
	xsi_register_executes(pe);
}
