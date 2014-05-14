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
static const char *ng0 = "H:/Users/ygg001.BUCKNELL/Downloads/Zedboard_OV7670/ov7670/ov7670_registers.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_1919365254_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_2681524712_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(39, ng0);

LAB3:    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = (t0 + 4080);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 16U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 3968);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2681524712_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    int t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 3400U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 1832U);
    t3 = *((char **)t2);
    t2 = (t0 + 6895);
    t5 = xsi_mem_cmp(t2, t3, 16U);
    if (t5 == 1)
        goto LAB5;

LAB7:
LAB6:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 4144);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);

LAB4:    xsi_set_current_line(40, ng0);

LAB11:    t2 = (t0 + 3984);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB12;

LAB1:    return;
LAB5:    xsi_set_current_line(40, ng0);
    t6 = (t0 + 4144);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t6);
    goto LAB4;

LAB8:;
LAB9:    t3 = (t0 + 3984);
    *((int *)t3) = 0;
    goto LAB2;

LAB10:    goto LAB9;

LAB12:    goto LAB10;

}

static void work_a_2681524712_3212880686_p_2(char *t0)
{
    char t13[16];
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
    int t14;
    int t15;
    int t16;
    int t17;
    char *t18;
    int t20;
    char *t21;
    int t23;
    char *t24;
    int t26;
    char *t27;
    int t29;
    char *t30;
    int t32;
    char *t33;
    int t35;
    char *t36;
    int t38;
    char *t39;
    int t41;
    char *t42;
    int t44;
    char *t45;
    int t47;
    char *t48;
    int t50;
    char *t51;
    int t53;
    char *t54;
    int t56;
    char *t57;
    int t59;
    char *t60;
    int t62;
    char *t63;
    int t65;
    char *t66;
    int t68;
    char *t69;
    int t71;
    char *t72;
    int t74;
    char *t75;
    int t77;
    char *t78;
    int t80;
    char *t81;
    int t83;
    char *t84;
    int t86;
    char *t87;
    int t89;
    char *t90;
    int t92;
    char *t93;
    int t95;
    char *t96;
    int t98;
    char *t99;
    int t101;
    char *t102;
    int t104;
    char *t105;
    int t107;
    char *t108;
    int t110;
    char *t111;
    int t113;
    char *t114;
    int t116;
    char *t117;
    int t119;
    char *t120;
    int t122;
    char *t123;
    int t125;
    char *t126;
    int t128;
    char *t129;
    int t131;
    char *t132;
    int t134;
    char *t135;
    int t137;
    char *t138;
    int t140;
    char *t141;
    int t143;
    char *t144;
    int t146;
    char *t147;
    int t149;
    char *t150;
    int t152;
    char *t153;
    int t155;
    char *t156;
    int t158;
    char *t159;
    int t161;
    char *t162;
    int t164;
    char *t165;
    int t167;
    char *t168;
    int t170;
    char *t171;
    int t173;
    char *t174;
    char *t176;
    char *t177;
    char *t178;
    char *t179;
    char *t180;

LAB0:    xsi_set_current_line(44, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 4000);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(45, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB9:
LAB6:    xsi_set_current_line(51, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    t1 = (t0 + 6911);
    t14 = xsi_mem_cmp(t1, t3, 8U);
    if (t14 == 1)
        goto LAB11;

LAB68:    t7 = (t0 + 6919);
    t15 = xsi_mem_cmp(t7, t3, 8U);
    if (t15 == 1)
        goto LAB12;

LAB69:    t9 = (t0 + 6927);
    t16 = xsi_mem_cmp(t9, t3, 8U);
    if (t16 == 1)
        goto LAB13;

LAB70:    t11 = (t0 + 6935);
    t17 = xsi_mem_cmp(t11, t3, 8U);
    if (t17 == 1)
        goto LAB14;

LAB71:    t18 = (t0 + 6943);
    t20 = xsi_mem_cmp(t18, t3, 8U);
    if (t20 == 1)
        goto LAB15;

LAB72:    t21 = (t0 + 6951);
    t23 = xsi_mem_cmp(t21, t3, 8U);
    if (t23 == 1)
        goto LAB16;

LAB73:    t24 = (t0 + 6959);
    t26 = xsi_mem_cmp(t24, t3, 8U);
    if (t26 == 1)
        goto LAB17;

LAB74:    t27 = (t0 + 6967);
    t29 = xsi_mem_cmp(t27, t3, 8U);
    if (t29 == 1)
        goto LAB18;

LAB75:    t30 = (t0 + 6975);
    t32 = xsi_mem_cmp(t30, t3, 8U);
    if (t32 == 1)
        goto LAB19;

LAB76:    t33 = (t0 + 6983);
    t35 = xsi_mem_cmp(t33, t3, 8U);
    if (t35 == 1)
        goto LAB20;

LAB77:    t36 = (t0 + 6991);
    t38 = xsi_mem_cmp(t36, t3, 8U);
    if (t38 == 1)
        goto LAB21;

LAB78:    t39 = (t0 + 6999);
    t41 = xsi_mem_cmp(t39, t3, 8U);
    if (t41 == 1)
        goto LAB22;

LAB79:    t42 = (t0 + 7007);
    t44 = xsi_mem_cmp(t42, t3, 8U);
    if (t44 == 1)
        goto LAB23;

LAB80:    t45 = (t0 + 7015);
    t47 = xsi_mem_cmp(t45, t3, 8U);
    if (t47 == 1)
        goto LAB24;

LAB81:    t48 = (t0 + 7023);
    t50 = xsi_mem_cmp(t48, t3, 8U);
    if (t50 == 1)
        goto LAB25;

LAB82:    t51 = (t0 + 7031);
    t53 = xsi_mem_cmp(t51, t3, 8U);
    if (t53 == 1)
        goto LAB26;

LAB83:    t54 = (t0 + 7039);
    t56 = xsi_mem_cmp(t54, t3, 8U);
    if (t56 == 1)
        goto LAB27;

LAB84:    t57 = (t0 + 7047);
    t59 = xsi_mem_cmp(t57, t3, 8U);
    if (t59 == 1)
        goto LAB28;

LAB85:    t60 = (t0 + 7055);
    t62 = xsi_mem_cmp(t60, t3, 8U);
    if (t62 == 1)
        goto LAB29;

LAB86:    t63 = (t0 + 7063);
    t65 = xsi_mem_cmp(t63, t3, 8U);
    if (t65 == 1)
        goto LAB30;

LAB87:    t66 = (t0 + 7071);
    t68 = xsi_mem_cmp(t66, t3, 8U);
    if (t68 == 1)
        goto LAB31;

LAB88:    t69 = (t0 + 7079);
    t71 = xsi_mem_cmp(t69, t3, 8U);
    if (t71 == 1)
        goto LAB32;

LAB89:    t72 = (t0 + 7087);
    t74 = xsi_mem_cmp(t72, t3, 8U);
    if (t74 == 1)
        goto LAB33;

LAB90:    t75 = (t0 + 7095);
    t77 = xsi_mem_cmp(t75, t3, 8U);
    if (t77 == 1)
        goto LAB34;

LAB91:    t78 = (t0 + 7103);
    t80 = xsi_mem_cmp(t78, t3, 8U);
    if (t80 == 1)
        goto LAB35;

LAB92:    t81 = (t0 + 7111);
    t83 = xsi_mem_cmp(t81, t3, 8U);
    if (t83 == 1)
        goto LAB36;

LAB93:    t84 = (t0 + 7119);
    t86 = xsi_mem_cmp(t84, t3, 8U);
    if (t86 == 1)
        goto LAB37;

LAB94:    t87 = (t0 + 7127);
    t89 = xsi_mem_cmp(t87, t3, 8U);
    if (t89 == 1)
        goto LAB38;

LAB95:    t90 = (t0 + 7135);
    t92 = xsi_mem_cmp(t90, t3, 8U);
    if (t92 == 1)
        goto LAB39;

LAB96:    t93 = (t0 + 7143);
    t95 = xsi_mem_cmp(t93, t3, 8U);
    if (t95 == 1)
        goto LAB40;

LAB97:    t96 = (t0 + 7151);
    t98 = xsi_mem_cmp(t96, t3, 8U);
    if (t98 == 1)
        goto LAB41;

LAB98:    t99 = (t0 + 7159);
    t101 = xsi_mem_cmp(t99, t3, 8U);
    if (t101 == 1)
        goto LAB42;

LAB99:    t102 = (t0 + 7167);
    t104 = xsi_mem_cmp(t102, t3, 8U);
    if (t104 == 1)
        goto LAB43;

LAB100:    t105 = (t0 + 7175);
    t107 = xsi_mem_cmp(t105, t3, 8U);
    if (t107 == 1)
        goto LAB44;

LAB101:    t108 = (t0 + 7183);
    t110 = xsi_mem_cmp(t108, t3, 8U);
    if (t110 == 1)
        goto LAB45;

LAB102:    t111 = (t0 + 7191);
    t113 = xsi_mem_cmp(t111, t3, 8U);
    if (t113 == 1)
        goto LAB46;

LAB103:    t114 = (t0 + 7199);
    t116 = xsi_mem_cmp(t114, t3, 8U);
    if (t116 == 1)
        goto LAB47;

LAB104:    t117 = (t0 + 7207);
    t119 = xsi_mem_cmp(t117, t3, 8U);
    if (t119 == 1)
        goto LAB48;

LAB105:    t120 = (t0 + 7215);
    t122 = xsi_mem_cmp(t120, t3, 8U);
    if (t122 == 1)
        goto LAB49;

LAB106:    t123 = (t0 + 7223);
    t125 = xsi_mem_cmp(t123, t3, 8U);
    if (t125 == 1)
        goto LAB50;

LAB107:    t126 = (t0 + 7231);
    t128 = xsi_mem_cmp(t126, t3, 8U);
    if (t128 == 1)
        goto LAB51;

LAB108:    t129 = (t0 + 7239);
    t131 = xsi_mem_cmp(t129, t3, 8U);
    if (t131 == 1)
        goto LAB52;

LAB109:    t132 = (t0 + 7247);
    t134 = xsi_mem_cmp(t132, t3, 8U);
    if (t134 == 1)
        goto LAB53;

LAB110:    t135 = (t0 + 7255);
    t137 = xsi_mem_cmp(t135, t3, 8U);
    if (t137 == 1)
        goto LAB54;

LAB111:    t138 = (t0 + 7263);
    t140 = xsi_mem_cmp(t138, t3, 8U);
    if (t140 == 1)
        goto LAB55;

LAB112:    t141 = (t0 + 7271);
    t143 = xsi_mem_cmp(t141, t3, 8U);
    if (t143 == 1)
        goto LAB56;

LAB113:    t144 = (t0 + 7279);
    t146 = xsi_mem_cmp(t144, t3, 8U);
    if (t146 == 1)
        goto LAB57;

LAB114:    t147 = (t0 + 7287);
    t149 = xsi_mem_cmp(t147, t3, 8U);
    if (t149 == 1)
        goto LAB58;

LAB115:    t150 = (t0 + 7295);
    t152 = xsi_mem_cmp(t150, t3, 8U);
    if (t152 == 1)
        goto LAB59;

LAB116:    t153 = (t0 + 7303);
    t155 = xsi_mem_cmp(t153, t3, 8U);
    if (t155 == 1)
        goto LAB60;

LAB117:    t156 = (t0 + 7311);
    t158 = xsi_mem_cmp(t156, t3, 8U);
    if (t158 == 1)
        goto LAB61;

LAB118:    t159 = (t0 + 7319);
    t161 = xsi_mem_cmp(t159, t3, 8U);
    if (t161 == 1)
        goto LAB62;

LAB119:    t162 = (t0 + 7327);
    t164 = xsi_mem_cmp(t162, t3, 8U);
    if (t164 == 1)
        goto LAB63;

LAB120:    t165 = (t0 + 7335);
    t167 = xsi_mem_cmp(t165, t3, 8U);
    if (t167 == 1)
        goto LAB64;

LAB121:    t168 = (t0 + 7343);
    t170 = xsi_mem_cmp(t168, t3, 8U);
    if (t170 == 1)
        goto LAB65;

LAB122:    t171 = (t0 + 7351);
    t173 = xsi_mem_cmp(t171, t3, 8U);
    if (t173 == 1)
        goto LAB66;

LAB123:
LAB67:    xsi_set_current_line(127, ng0);
    t1 = (t0 + 8255);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);

LAB10:    goto LAB3;

LAB5:    xsi_set_current_line(46, ng0);
    t3 = xsi_get_transient_memory(8U);
    memset(t3, 0, 8U);
    t7 = t3;
    memset(t7, (unsigned char)2, 8U);
    t8 = (t0 + 4208);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 8U);
    xsi_driver_first_trans_fast(t8);
    goto LAB6;

LAB8:    xsi_set_current_line(48, ng0);
    t1 = (t0 + 1992U);
    t4 = *((char **)t1);
    t1 = (t0 + 6844U);
    t7 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t13, t4, t1, 1);
    t8 = (t0 + 4208);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t7, 8U);
    xsi_driver_first_trans_fast(t8);
    goto LAB6;

LAB11:    xsi_set_current_line(52, ng0);
    t174 = (t0 + 7359);
    t176 = (t0 + 4272);
    t177 = (t176 + 56U);
    t178 = *((char **)t177);
    t179 = (t178 + 56U);
    t180 = *((char **)t179);
    memcpy(t180, t174, 16U);
    xsi_driver_first_trans_fast(t176);
    goto LAB10;

LAB12:    xsi_set_current_line(53, ng0);
    t1 = (t0 + 7375);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB13:    xsi_set_current_line(54, ng0);
    t1 = (t0 + 7391);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB14:    xsi_set_current_line(55, ng0);
    t1 = (t0 + 7407);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB15:    xsi_set_current_line(56, ng0);
    t1 = (t0 + 7423);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB16:    xsi_set_current_line(57, ng0);
    t1 = (t0 + 7439);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB17:    xsi_set_current_line(59, ng0);
    t1 = (t0 + 7455);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB18:    xsi_set_current_line(60, ng0);
    t1 = (t0 + 7471);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB19:    xsi_set_current_line(61, ng0);
    t1 = (t0 + 7487);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB20:    xsi_set_current_line(62, ng0);
    t1 = (t0 + 7503);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB21:    xsi_set_current_line(63, ng0);
    t1 = (t0 + 7519);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB22:    xsi_set_current_line(64, ng0);
    t1 = (t0 + 7535);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB23:    xsi_set_current_line(65, ng0);
    t1 = (t0 + 7551);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB24:    xsi_set_current_line(66, ng0);
    t1 = (t0 + 7567);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB25:    xsi_set_current_line(67, ng0);
    t1 = (t0 + 7583);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB26:    xsi_set_current_line(68, ng0);
    t1 = (t0 + 7599);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB27:    xsi_set_current_line(69, ng0);
    t1 = (t0 + 7615);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB28:    xsi_set_current_line(70, ng0);
    t1 = (t0 + 7631);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB29:    xsi_set_current_line(71, ng0);
    t1 = (t0 + 7647);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB30:    xsi_set_current_line(72, ng0);
    t1 = (t0 + 7663);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB31:    xsi_set_current_line(74, ng0);
    t1 = (t0 + 7679);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB32:    xsi_set_current_line(75, ng0);
    t1 = (t0 + 7695);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB33:    xsi_set_current_line(76, ng0);
    t1 = (t0 + 7711);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB34:    xsi_set_current_line(78, ng0);
    t1 = (t0 + 7727);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB35:    xsi_set_current_line(79, ng0);
    t1 = (t0 + 7743);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB36:    xsi_set_current_line(80, ng0);
    t1 = (t0 + 7759);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB37:    xsi_set_current_line(82, ng0);
    t1 = (t0 + 7775);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB38:    xsi_set_current_line(83, ng0);
    t1 = (t0 + 7791);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB39:    xsi_set_current_line(85, ng0);
    t1 = (t0 + 7807);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB40:    xsi_set_current_line(86, ng0);
    t1 = (t0 + 7823);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB41:    xsi_set_current_line(88, ng0);
    t1 = (t0 + 7839);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB42:    xsi_set_current_line(89, ng0);
    t1 = (t0 + 7855);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB43:    xsi_set_current_line(91, ng0);
    t1 = (t0 + 7871);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB44:    xsi_set_current_line(92, ng0);
    t1 = (t0 + 7887);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB45:    xsi_set_current_line(94, ng0);
    t1 = (t0 + 7903);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB46:    xsi_set_current_line(95, ng0);
    t1 = (t0 + 7919);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB47:    xsi_set_current_line(97, ng0);
    t1 = (t0 + 7935);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB48:    xsi_set_current_line(98, ng0);
    t1 = (t0 + 7951);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB49:    xsi_set_current_line(100, ng0);
    t1 = (t0 + 7967);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB50:    xsi_set_current_line(101, ng0);
    t1 = (t0 + 7983);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB51:    xsi_set_current_line(103, ng0);
    t1 = (t0 + 7999);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB52:    xsi_set_current_line(104, ng0);
    t1 = (t0 + 8015);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB53:    xsi_set_current_line(106, ng0);
    t1 = (t0 + 8031);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB54:    xsi_set_current_line(107, ng0);
    t1 = (t0 + 8047);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB55:    xsi_set_current_line(109, ng0);
    t1 = (t0 + 8063);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB56:    xsi_set_current_line(110, ng0);
    t1 = (t0 + 8079);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB57:    xsi_set_current_line(112, ng0);
    t1 = (t0 + 8095);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB58:    xsi_set_current_line(113, ng0);
    t1 = (t0 + 8111);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB59:    xsi_set_current_line(115, ng0);
    t1 = (t0 + 8127);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB60:    xsi_set_current_line(116, ng0);
    t1 = (t0 + 8143);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB61:    xsi_set_current_line(118, ng0);
    t1 = (t0 + 8159);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB62:    xsi_set_current_line(119, ng0);
    t1 = (t0 + 8175);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB63:    xsi_set_current_line(121, ng0);
    t1 = (t0 + 8191);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB64:    xsi_set_current_line(122, ng0);
    t1 = (t0 + 8207);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB65:    xsi_set_current_line(124, ng0);
    t1 = (t0 + 8223);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB66:    xsi_set_current_line(125, ng0);
    t1 = (t0 + 8239);
    t4 = (t0 + 4272);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    goto LAB10;

LAB124:;
}


extern void work_a_2681524712_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2681524712_3212880686_p_0,(void *)work_a_2681524712_3212880686_p_1,(void *)work_a_2681524712_3212880686_p_2};
	xsi_register_didat("work_a_2681524712_3212880686", "isim/tb_ov7670_top_isim_beh.exe.sim/work/a_2681524712_3212880686.didat");
	xsi_register_executes(pe);
}
