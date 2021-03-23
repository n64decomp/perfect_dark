#include <ultra64.h>
#include "constants.h"
#include "game/debug.h"
#include "bss.h"
#include "data.h"
#include "types.h"

s32 var80075d60 = 0x00000002;
u32 var80075d64 = 0x00000002;
u32 var80075d68 = 0x00000002;
u32 var80075d6c = 0x00000002;
u32 var80075d70 = 0x00000000;
bool g_DebugTurboMode = false;
s32 var80075d78 = 0;
u32 var80075d7c = 0x00000000;
u32 var80075d80 = 0x00000000;
u32 var80075d84 = 0x00000000;
u32 var80075d88 = 0x00000000;
u32 var80075d8c = 0x00000000;
u32 var80075d90 = 0x00000000;
u32 var80075d94 = 0xbf800000;
u32 var80075d98 = 0x00000000;
u32 var80075d9c = 0x3f800000;
u32 var80075da0 = 0x00000000;
u32 var80075da4 = 0x00000000;
u32 var80075da8 = 0x3f800000;
u32 var80075dac = 0x00000000;
u32 var80075db0 = 0x00000000;
u32 var80075db4 = 0x3f800000;
u32 var80075db8 = 0x00000000;
u32 var80075dbc = 0x00000000;
u32 var80075dc0 = 0x00000000;
u32 var80075dc4 = 0x00000000;
u32 var80075dc8 = 0x00000000;
u32 var80075dcc = 0x00000000;
u32 var80075dd0 = 0x00000000;
u32 var80075dd4 = 0x00000000;
u32 var80075dd8 = 0x3f800000;
u32 var80075ddc = 0x00000000;

void debug0f118c80nb(void)
{
	// empty
}

GLOBAL_ASM(
glabel debug0f118c88nb
/*  f118c88:	3c018008 */ 	lui	$at,0x8008
/*  f118c8c:	03e00008 */ 	jr	$ra
/*  f118c90:	ac248138 */ 	sw	$a0,-0x7ec8($at)
);

GLOBAL_ASM(
glabel debug0f118c94nb
/*  f118c94:	3c018008 */ 	lui	$at,0x8008
/*  f118c98:	ac248128 */ 	sw	$a0,-0x7ed8($at)
/*  f118c9c:	3c018008 */ 	lui	$at,0x8008
/*  f118ca0:	ac25812c */ 	sw	$a1,-0x7ed4($at)
/*  f118ca4:	3c018008 */ 	lui	$at,0x8008
/*  f118ca8:	ac268134 */ 	sw	$a2,-0x7ecc($at)
/*  f118cac:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f118cb0:	00001025 */ 	or	$v0,$zero,$zero
/*  f118cb4:	00c01825 */ 	or	$v1,$a2,$zero
/*  f118cb8:	05c20007 */ 	bltzl	$t6,.NB0f118cd8
/*  f118cbc:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f118cc0:	8c6f0004 */ 	lw	$t7,0x4($v1)
.NB0f118cc4:
/*  f118cc4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f118cc8:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f118ccc:	05e3fffd */ 	bgezl	$t7,.NB0f118cc4
/*  f118cd0:	8c6f0004 */ 	lw	$t7,0x4($v1)
/*  f118cd4:	0002c080 */ 	sll	$t8,$v0,0x2
.NB0f118cd8:
/*  f118cd8:	00d8c821 */ 	addu	$t9,$a2,$t8
/*  f118cdc:	8f28fffc */ 	lw	$t0,-0x4($t9)
/*  f118ce0:	3c018008 */ 	lui	$at,0x8008
/*  f118ce4:	ac288124 */ 	sw	$t0,-0x7edc($at)
/*  f118ce8:	3c018008 */ 	lui	$at,0x8008
/*  f118cec:	03e00008 */ 	jr	$ra
/*  f118cf0:	ac228130 */ 	sw	$v0,-0x7ed0($at)
);

GLOBAL_ASM(
glabel debug0f118cf4nb
/*  f118cf4:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f118cf8:	3c038008 */ 	lui	$v1,0x8008
/*  f118cfc:	8c638138 */ 	lw	$v1,-0x7ec8($v1)
/*  f118d00:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f118d04:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f118d08:	3c178008 */ 	lui	$s7,0x8008
/*  f118d0c:	3c1e8008 */ 	lui	$s8,0x8008
/*  f118d10:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f118d14:	248f0008 */ 	addiu	$t7,$a0,0x8
/*  f118d18:	02e3b821 */ 	addu	$s7,$s7,$v1
/*  f118d1c:	03c3f021 */ 	addu	$s8,$s8,$v1
/*  f118d20:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f118d24:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f118d28:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f118d2c:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f118d30:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f118d34:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f118d38:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f118d3c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f118d40:	92f7813c */ 	lbu	$s7,-0x7ec4($s7)
/*  f118d44:	93de8140 */ 	lbu	$s8,-0x7ec0($s8)
/*  f118d48:	afaf0040 */ 	sw	$t7,0x40($sp)
/*  f118d4c:	3c18ba00 */ 	lui	$t8,0xba00
/*  f118d50:	37180e02 */ 	ori	$t8,$t8,0xe02
/*  f118d54:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f118d58:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f118d5c:	3c028008 */ 	lui	$v0,0x8008
/*  f118d60:	8c428124 */ 	lw	$v0,-0x7edc($v0)
/*  f118d64:	3c168008 */ 	lui	$s6,0x8008
/*  f118d68:	26d68128 */ 	addiu	$s6,$s6,-32472
/*  f118d6c:	18400039 */ 	blez	$v0,.NB0f118e54
/*  f118d70:	00008025 */ 	or	$s0,$zero,$zero
/*  f118d74:	3c148008 */ 	lui	$s4,0x8008
/*  f118d78:	3c138008 */ 	lui	$s3,0x8008
/*  f118d7c:	26738120 */ 	addiu	$s3,$s3,-32480
/*  f118d80:	2694812c */ 	addiu	$s4,$s4,-32468
/*  f118d84:	24150007 */ 	addiu	$s5,$zero,0x7
.NB0f118d88:
/*  f118d88:	0fc46320 */ 	jal	0xf118c80
/*  f118d8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118d90:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f118d94:	240400c0 */ 	addiu	$a0,$zero,0xc0
/*  f118d98:	240500c0 */ 	addiu	$a1,$zero,0xc0
/*  f118d9c:	12190026 */ 	beq	$s0,$t9,.NB0f118e38
/*  f118da0:	240600c0 */ 	addiu	$a2,$zero,0xc0
/*  f118da4:	240700c0 */ 	addiu	$a3,$zero,0xc0
/*  f118da8:	001088c0 */ 	sll	$s1,$s0,0x3
/*  f118dac:	0c005106 */ 	jal	0x14418
/*  f118db0:	00109080 */ 	sll	$s2,$s0,0x2
/*  f118db4:	8e880000 */ 	lw	$t0,0x0($s4)
/*  f118db8:	01111021 */ 	addu	$v0,$t0,$s1
/*  f118dbc:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f118dc0:	8c4b0004 */ 	lw	$t3,0x4($v0)
/*  f118dc4:	01370019 */ 	multu	$t1,$s7
/*  f118dc8:	00002012 */ 	mflo	$a0
/*  f118dcc:	2484ffec */ 	addiu	$a0,$a0,-20
/*  f118dd0:	04810003 */ 	bgez	$a0,.NB0f118de0
/*  f118dd4:	00045083 */ 	sra	$t2,$a0,0x2
/*  f118dd8:	24810003 */ 	addiu	$at,$a0,0x3
/*  f118ddc:	00015083 */ 	sra	$t2,$at,0x2
.NB0f118de0:
/*  f118de0:	017e0019 */ 	multu	$t3,$s8
/*  f118de4:	01402025 */ 	or	$a0,$t2,$zero
/*  f118de8:	00006012 */ 	mflo	$t4
/*  f118dec:	258dfff8 */ 	addiu	$t5,$t4,-8
/*  f118df0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118df4:	01b5001a */ 	div	$zero,$t5,$s5
/*  f118df8:	00002812 */ 	mflo	$a1
/*  f118dfc:	16a00002 */ 	bnez	$s5,.NB0f118e08
/*  f118e00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118e04:	0007000d */ 	break	0x7
.NB0f118e08:
/*  f118e08:	2401ffff */ 	addiu	$at,$zero,-1
/*  f118e0c:	16a10004 */ 	bne	$s5,$at,.NB0f118e20
/*  f118e10:	3c018000 */ 	lui	$at,0x8000
/*  f118e14:	15a10002 */ 	bne	$t5,$at,.NB0f118e20
/*  f118e18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118e1c:	0006000d */ 	break	0x6
.NB0f118e20:
/*  f118e20:	0c0050df */ 	jal	0x1437c
/*  f118e24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118e28:	8ece0000 */ 	lw	$t6,0x0($s6)
/*  f118e2c:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f118e30:	0c005175 */ 	jal	0x145d4
/*  f118e34:	8de40000 */ 	lw	$a0,0x0($t7)
.NB0f118e38:
/*  f118e38:	3c028008 */ 	lui	$v0,0x8008
/*  f118e3c:	8c428124 */ 	lw	$v0,-0x7edc($v0)
/*  f118e40:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f118e44:	0202082a */ 	slt	$at,$s0,$v0
/*  f118e48:	1420ffcf */ 	bnez	$at,.NB0f118d88
/*  f118e4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118e50:	00008025 */ 	or	$s0,$zero,$zero
.NB0f118e54:
/*  f118e54:	3c138008 */ 	lui	$s3,0x8008
/*  f118e58:	3c148008 */ 	lui	$s4,0x8008
/*  f118e5c:	3c168008 */ 	lui	$s6,0x8008
/*  f118e60:	26d68128 */ 	addiu	$s6,$s6,-32472
/*  f118e64:	2694812c */ 	addiu	$s4,$s4,-32468
/*  f118e68:	26738120 */ 	addiu	$s3,$s3,-32480
/*  f118e6c:	18400033 */ 	blez	$v0,.NB0f118f3c
/*  f118e70:	24150007 */ 	addiu	$s5,$zero,0x7
.NB0f118e74:
/*  f118e74:	0fc46320 */ 	jal	0xf118c80
/*  f118e78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118e7c:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f118e80:	240400c0 */ 	addiu	$a0,$zero,0xc0
/*  f118e84:	00002825 */ 	or	$a1,$zero,$zero
/*  f118e88:	16180026 */ 	bne	$s0,$t8,.NB0f118f24
/*  f118e8c:	00003025 */ 	or	$a2,$zero,$zero
/*  f118e90:	240700c0 */ 	addiu	$a3,$zero,0xc0
/*  f118e94:	001088c0 */ 	sll	$s1,$s0,0x3
/*  f118e98:	0c005106 */ 	jal	0x14418
/*  f118e9c:	00109080 */ 	sll	$s2,$s0,0x2
/*  f118ea0:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f118ea4:	03311021 */ 	addu	$v0,$t9,$s1
/*  f118ea8:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f118eac:	8c4a0004 */ 	lw	$t2,0x4($v0)
/*  f118eb0:	01170019 */ 	multu	$t0,$s7
/*  f118eb4:	00002012 */ 	mflo	$a0
/*  f118eb8:	2484ffec */ 	addiu	$a0,$a0,-20
/*  f118ebc:	04810003 */ 	bgez	$a0,.NB0f118ecc
/*  f118ec0:	00044883 */ 	sra	$t1,$a0,0x2
/*  f118ec4:	24810003 */ 	addiu	$at,$a0,0x3
/*  f118ec8:	00014883 */ 	sra	$t1,$at,0x2
.NB0f118ecc:
/*  f118ecc:	015e0019 */ 	multu	$t2,$s8
/*  f118ed0:	01202025 */ 	or	$a0,$t1,$zero
/*  f118ed4:	00005812 */ 	mflo	$t3
/*  f118ed8:	256cfff8 */ 	addiu	$t4,$t3,-8
/*  f118edc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118ee0:	0195001a */ 	div	$zero,$t4,$s5
/*  f118ee4:	00002812 */ 	mflo	$a1
/*  f118ee8:	16a00002 */ 	bnez	$s5,.NB0f118ef4
/*  f118eec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118ef0:	0007000d */ 	break	0x7
.NB0f118ef4:
/*  f118ef4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f118ef8:	16a10004 */ 	bne	$s5,$at,.NB0f118f0c
/*  f118efc:	3c018000 */ 	lui	$at,0x8000
/*  f118f00:	15810002 */ 	bne	$t4,$at,.NB0f118f0c
/*  f118f04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118f08:	0006000d */ 	break	0x6
.NB0f118f0c:
/*  f118f0c:	0c0050df */ 	jal	0x1437c
/*  f118f10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118f14:	8ecd0000 */ 	lw	$t5,0x0($s6)
/*  f118f18:	01b27021 */ 	addu	$t6,$t5,$s2
/*  f118f1c:	0c005175 */ 	jal	0x145d4
/*  f118f20:	8dc40000 */ 	lw	$a0,0x0($t6)
.NB0f118f24:
/*  f118f24:	3c0f8008 */ 	lui	$t7,0x8008
/*  f118f28:	8def8124 */ 	lw	$t7,-0x7edc($t7)
/*  f118f2c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f118f30:	020f082a */ 	slt	$at,$s0,$t7
/*  f118f34:	1420ffcf */ 	bnez	$at,.NB0f118e74
/*  f118f38:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f118f3c:
/*  f118f3c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f118f40:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f118f44:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f118f48:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f118f4c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f118f50:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f118f54:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f118f58:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f118f5c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f118f60:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f118f64:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f118f68:	03e00008 */ 	jr	$ra
/*  f118f6c:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel debug0f118f70nb
/*  f118f70:	3c028008 */ 	lui	$v0,0x8008
/*  f118f74:	03e00008 */ 	jr	$ra
/*  f118f78:	8c428120 */ 	lw	$v0,-0x7ee0($v0)
);

GLOBAL_ASM(
glabel debug0f118f7cnb
/*  f118f7c:	3c018008 */ 	lui	$at,0x8008
/*  f118f80:	03e00008 */ 	jr	$ra
/*  f118f84:	ac248120 */ 	sw	$a0,-0x7ee0($at)
);

GLOBAL_ASM(
glabel debug0f118f88nb
/*  f118f88:	3c068008 */ 	lui	$a2,0x8008
/*  f118f8c:	24c68120 */ 	addiu	$a2,$a2,-32480
/*  f118f90:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f118f94:	3c188008 */ 	lui	$t8,0x8008
/*  f118f98:	3c048008 */ 	lui	$a0,0x8008
/*  f118f9c:	25c2ffff */ 	addiu	$v0,$t6,-1
/*  f118fa0:	04410006 */ 	bgez	$v0,.NB0f118fbc
/*  f118fa4:	acc20000 */ 	sw	$v0,0x0($a2)
/*  f118fa8:	8f188134 */ 	lw	$t8,-0x7ecc($t8)
/*  f118fac:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f118fb0:	2728ffff */ 	addiu	$t0,$t9,-1
/*  f118fb4:	03e00008 */ 	jr	$ra
/*  f118fb8:	acc80000 */ 	sw	$t0,0x0($a2)
.NB0f118fbc:
/*  f118fbc:	8c848130 */ 	lw	$a0,-0x7ed0($a0)
/*  f118fc0:	00001825 */ 	or	$v1,$zero,$zero
/*  f118fc4:	3c058008 */ 	lui	$a1,0x8008
/*  f118fc8:	1880000d */ 	blez	$a0,.NB0f119000
/*  f118fcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118fd0:	8ca58134 */ 	lw	$a1,-0x7ecc($a1)
.NB0f118fd4:
/*  f118fd4:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f118fd8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f118fdc:	24490001 */ 	addiu	$t1,$v0,0x1
/*  f118fe0:	152a0005 */ 	bne	$t1,$t2,.NB0f118ff8
/*  f118fe4:	0064082a */ 	slt	$at,$v1,$a0
/*  f118fe8:	8cab0004 */ 	lw	$t3,0x4($a1)
/*  f118fec:	256cffff */ 	addiu	$t4,$t3,-1
/*  f118ff0:	03e00008 */ 	jr	$ra
/*  f118ff4:	accc0000 */ 	sw	$t4,0x0($a2)
.NB0f118ff8:
/*  f118ff8:	1420fff6 */ 	bnez	$at,.NB0f118fd4
/*  f118ffc:	24a50004 */ 	addiu	$a1,$a1,0x4
.NB0f119000:
/*  f119000:	03e00008 */ 	jr	$ra
/*  f119004:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel debug0f119008nb
/*  f119008:	3c078008 */ 	lui	$a3,0x8008
/*  f11900c:	24e78120 */ 	addiu	$a3,$a3,-32480
/*  f119010:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f119014:	3c038008 */ 	lui	$v1,0x8008
/*  f119018:	3c058008 */ 	lui	$a1,0x8008
/*  f11901c:	25c20001 */ 	addiu	$v0,$t6,0x1
/*  f119020:	ace20000 */ 	sw	$v0,0x0($a3)
/*  f119024:	8c638134 */ 	lw	$v1,-0x7ecc($v1)
/*  f119028:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f11902c:	14580003 */ 	bne	$v0,$t8,.NB0f11903c
/*  f119030:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119034:	03e00008 */ 	jr	$ra
/*  f119038:	ace00000 */ 	sw	$zero,0x0($a3)
.NB0f11903c:
/*  f11903c:	8ca58130 */ 	lw	$a1,-0x7ed0($a1)
/*  f119040:	00002025 */ 	or	$a0,$zero,$zero
/*  f119044:	00603025 */ 	or	$a2,$v1,$zero
/*  f119048:	18a0000b */ 	blez	$a1,.NB0f119078
/*  f11904c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f119050:
/*  f119050:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f119054:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f119058:	0085082a */ 	slt	$at,$a0,$a1
/*  f11905c:	14590004 */ 	bne	$v0,$t9,.NB0f119070
/*  f119060:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119064:	8cc8fffc */ 	lw	$t0,-0x4($a2)
/*  f119068:	03e00008 */ 	jr	$ra
/*  f11906c:	ace80000 */ 	sw	$t0,0x0($a3)
.NB0f119070:
/*  f119070:	1420fff7 */ 	bnez	$at,.NB0f119050
/*  f119074:	24c60004 */ 	addiu	$a2,$a2,0x4
.NB0f119078:
/*  f119078:	03e00008 */ 	jr	$ra
/*  f11907c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel debug0f119080nb
/*  f119080:	3c038008 */ 	lui	$v1,0x8008
/*  f119084:	8c638134 */ 	lw	$v1,-0x7ecc($v1)
/*  f119088:	3c088008 */ 	lui	$t0,0x8008
/*  f11908c:	25088120 */ 	addiu	$t0,$t0,-32480
/*  f119090:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f119094:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f119098:	3c0e8008 */ 	lui	$t6,0x8008
/*  f11909c:	0044082a */ 	slt	$at,$v0,$a0
/*  f1190a0:	1020000d */ 	beqz	$at,.NB0f1190d8
/*  f1190a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1190a8:	8dce8130 */ 	lw	$t6,-0x7ed0($t6)
/*  f1190ac:	00447821 */ 	addu	$t7,$v0,$a0
/*  f1190b0:	29c10002 */ 	slti	$at,$t6,0x2
/*  f1190b4:	1420002d */ 	bnez	$at,.NB0f11916c
/*  f1190b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1190bc:	ad0f0000 */ 	sw	$t7,0x0($t0)
/*  f1190c0:	8c650004 */ 	lw	$a1,0x4($v1)
/*  f1190c4:	01e5082a */ 	slt	$at,$t7,$a1
/*  f1190c8:	14200028 */ 	bnez	$at,.NB0f11916c
/*  f1190cc:	24b9ffff */ 	addiu	$t9,$a1,-1
/*  f1190d0:	03e00008 */ 	jr	$ra
/*  f1190d4:	ad190000 */ 	sw	$t9,0x0($t0)
.NB0f1190d8:
/*  f1190d8:	3c048008 */ 	lui	$a0,0x8008
/*  f1190dc:	8c848130 */ 	lw	$a0,-0x7ed0($a0)
/*  f1190e0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1190e4:	00603025 */ 	or	$a2,$v1,$zero
/*  f1190e8:	18800020 */ 	blez	$a0,.NB0f11916c
/*  f1190ec:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f1190f0:
/*  f1190f0:	8cc70000 */ 	lw	$a3,0x0($a2)
/*  f1190f4:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f1190f8:	0047082a */ 	slt	$at,$v0,$a3
/*  f1190fc:	50200019 */ 	beqzl	$at,.NB0f119164
/*  f119100:	00a4082a */ 	slt	$at,$a1,$a0
/*  f119104:	8ccafffc */ 	lw	$t2,-0x4($a2)
/*  f119108:	00474821 */ 	addu	$t1,$v0,$a3
/*  f11910c:	012a5823 */ 	subu	$t3,$t1,$t2
/*  f119110:	ad0b0000 */ 	sw	$t3,0x0($t0)
/*  f119114:	8cc40004 */ 	lw	$a0,0x4($a2)
/*  f119118:	0483000b */ 	bgezl	$a0,.NB0f119148
/*  f11911c:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f119120:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f119124:	016d7023 */ 	subu	$t6,$t3,$t5
/*  f119128:	ad0e0000 */ 	sw	$t6,0x0($t0)
/*  f11912c:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f119130:	01c4082a */ 	slt	$at,$t6,$a0
/*  f119134:	1420000d */ 	bnez	$at,.NB0f11916c
/*  f119138:	2498ffff */ 	addiu	$t8,$a0,-1
/*  f11913c:	03e00008 */ 	jr	$ra
/*  f119140:	ad180000 */ 	sw	$t8,0x0($t0)
/*  f119144:	8d190000 */ 	lw	$t9,0x0($t0)
.NB0f119148:
/*  f119148:	2489ffff */ 	addiu	$t1,$a0,-1
/*  f11914c:	0324082a */ 	slt	$at,$t9,$a0
/*  f119150:	14200006 */ 	bnez	$at,.NB0f11916c
/*  f119154:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119158:	03e00008 */ 	jr	$ra
/*  f11915c:	ad090000 */ 	sw	$t1,0x0($t0)
/*  f119160:	00a4082a */ 	slt	$at,$a1,$a0
.NB0f119164:
/*  f119164:	1420ffe2 */ 	bnez	$at,.NB0f1190f0
/*  f119168:	24c60004 */ 	addiu	$a2,$a2,0x4
.NB0f11916c:
/*  f11916c:	03e00008 */ 	jr	$ra
/*  f119170:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel debug0f119174nb
/*  f119174:	3c038008 */ 	lui	$v1,0x8008
/*  f119178:	8c638134 */ 	lw	$v1,-0x7ecc($v1)
/*  f11917c:	3c078008 */ 	lui	$a3,0x8008
/*  f119180:	24e78120 */ 	addiu	$a3,$a3,-32480
/*  f119184:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f119188:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f11918c:	3c058008 */ 	lui	$a1,0x8008
/*  f119190:	0044082a */ 	slt	$at,$v0,$a0
/*  f119194:	50200017 */ 	beqzl	$at,.NB0f1191f4
/*  f119198:	0044082a */ 	slt	$at,$v0,$a0
/*  f11919c:	8ca58130 */ 	lw	$a1,-0x7ed0($a1)
/*  f1191a0:	00002025 */ 	or	$a0,$zero,$zero
/*  f1191a4:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f1191a8:	18a00005 */ 	blez	$a1,.NB0f1191c0
/*  f1191ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1191b0:	24840001 */ 	addiu	$a0,$a0,0x1
.NB0f1191b4:
/*  f1191b4:	0085082a */ 	slt	$at,$a0,$a1
/*  f1191b8:	5420fffe */ 	bnezl	$at,.NB0f1191b4
/*  f1191bc:	24840001 */ 	addiu	$a0,$a0,0x1
.NB0f1191c0:
/*  f1191c0:	18800026 */ 	blez	$a0,.NB0f11925c
/*  f1191c4:	00047080 */ 	sll	$t6,$a0,0x2
/*  f1191c8:	006e2821 */ 	addu	$a1,$v1,$t6
/*  f1191cc:	8caffffc */ 	lw	$t7,-0x4($a1)
/*  f1191d0:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f1191d4:	acf80000 */ 	sw	$t8,0x0($a3)
/*  f1191d8:	8ca60000 */ 	lw	$a2,0x0($a1)
/*  f1191dc:	0306082a */ 	slt	$at,$t8,$a2
/*  f1191e0:	1420001e */ 	bnez	$at,.NB0f11925c
/*  f1191e4:	24c8ffff */ 	addiu	$t0,$a2,-1
/*  f1191e8:	03e00008 */ 	jr	$ra
/*  f1191ec:	ace80000 */ 	sw	$t0,0x0($a3)
/*  f1191f0:	0044082a */ 	slt	$at,$v0,$a0
.NB0f1191f4:
/*  f1191f4:	14200008 */ 	bnez	$at,.NB0f119218
/*  f1191f8:	00002825 */ 	or	$a1,$zero,$zero
/*  f1191fc:	00602025 */ 	or	$a0,$v1,$zero
/*  f119200:	8c890004 */ 	lw	$t1,0x4($a0)
.NB0f119204:
/*  f119204:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f119208:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f11920c:	0049082a */ 	slt	$at,$v0,$t1
/*  f119210:	5020fffc */ 	beqzl	$at,.NB0f119204
/*  f119214:	8c890004 */ 	lw	$t1,0x4($a0)
.NB0f119218:
/*  f119218:	00055080 */ 	sll	$t2,$a1,0x2
/*  f11921c:	006a2021 */ 	addu	$a0,$v1,$t2
/*  f119220:	8c8bfffc */ 	lw	$t3,-0x4($a0)
/*  f119224:	24adfffe */ 	addiu	$t5,$a1,-2
/*  f119228:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f11922c:	05a00004 */ 	bltz	$t5,.NB0f119240
/*  f119230:	acec0000 */ 	sw	$t4,0x0($a3)
/*  f119234:	8c8ffff8 */ 	lw	$t7,-0x8($a0)
/*  f119238:	018fc021 */ 	addu	$t8,$t4,$t7
/*  f11923c:	acf80000 */ 	sw	$t8,0x0($a3)
.NB0f119240:
/*  f119240:	8c82fffc */ 	lw	$v0,-0x4($a0)
/*  f119244:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f119248:	2448ffff */ 	addiu	$t0,$v0,-1
/*  f11924c:	0322082a */ 	slt	$at,$t9,$v0
/*  f119250:	14200002 */ 	bnez	$at,.NB0f11925c
/*  f119254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119258:	ace80000 */ 	sw	$t0,0x0($a3)
.NB0f11925c:
/*  f11925c:	03e00008 */ 	jr	$ra
/*  f119260:	00000000 */ 	sll	$zero,$zero,0x0
);
