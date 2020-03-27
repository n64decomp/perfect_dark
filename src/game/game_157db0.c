#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/debug.h"
#include "game/dlights.h"
#include "game/game_013550.h"
#include "game/game_013ee0.h"
#include "game/game_01e250.h"
#include "game/game_0601b0.h"
#include "game/game_097970.h"
#include "game/game_097ba0.h"
#include "game/game_0b3350.h"
#include "game/game_0b63b0.h"
#include "game/game_11f000.h"
#include "game/game_135c70.h"
#include "game/game_13b670.h"
#include "game/game_13c510.h"
#include "game/game_1531a0.h"
#include "game/game_157db0.h"
#include "game/game_165360.h"
#include "game/game_1655c0.h"
#include "game/game_165670.h"
#include "game/game_1668e0.h"
#include "game/game_166e40.h"
#include "game/game_167ae0.h"
#include "game/game_16e810.h"
#include "game/game_173a00.h"
#include "game/wallhit.h"
#include "gvars/gvars.h"
#include "lib/lib_074f0.h"
#include "lib/lib_09660.h"
#include "lib/lib_0d0a0.h"
#include "lib/lib_0d520.h"
#include "lib/lib_121e0.h"
#include "lib/lib_126b0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/lib_2f490.h"
#include "lib/lib_4a360.h"
#include "lib/lib_4b170.h"
#include "lib/lib_4b480.h"
#include "lib/lib_4e530.h"
#include "types.h"

const char var7f1b7420[] = "Checking Convex Room %d";
const char var7f1b7438[] = " Portal %d %s%s%.1f < %.1f";
const char var7f1b7454[] = "";
const char var7f1b7458[] = "";
const char var7f1b745c[] = " Convex Room Failed (1)";
const char var7f1b7474[] = " Portal %d %s%s%.1f > %.1f";
const char var7f1b7490[] = "";
const char var7f1b7494[] = "";
const char var7f1b7498[] = " Convex Room Failed (0)";
const char var7f1b74b0[] = "Checking Concave Room %d";
const char var7f1b74cc[] = " Checking Portal %d";
const char var7f1b74e0[] = "Reject P:%d (%s%s%.1f %.1f n3=%.1f)";
const char var7f1b7504[] = "";
const char var7f1b7508[] = "";
const char var7f1b750c[] = "Reject P:%d (%s%s%.1f %.1f n4=%.1f)";
const char var7f1b7530[] = "";
const char var7f1b7534[] = "";
const char var7f1b7538[] = " Full %d%s%s %.1f %.1f (%.1f %.1f)";
const char var7f1b755c[] = "";
const char var7f1b7560[] = "";
const char var7f1b7564[] = " Failed 2 - Crossed portal %d";
const char var7f1b7584[] = " Failed 1 - Crossed portal %d";
const char var7f1b75a4[] = " Passed";
const char var7f1b75ac[] = "edist";

GLOBAL_ASM(
glabel func0f157db0
/*  f157db0:	27bdfdb8 */ 	addiu	$sp,$sp,-584
/*  f157db4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f157db8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f157dbc:	27b10038 */ 	addiu	$s1,$sp,0x38
/*  f157dc0:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f157dc4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f157dc8:	a7a40238 */ 	sh	$a0,0x238($sp)
/*  f157dcc:	240effff */ 	addiu	$t6,$zero,-1
/*  f157dd0:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f157dd4:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f157dd8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f157ddc:	a7ae023a */ 	sh	$t6,0x23a($sp)
/*  f157de0:	27a40238 */ 	addiu	$a0,$sp,0x238
/*  f157de4:	02202825 */ 	or	$a1,$s1,$zero
/*  f157de8:	0fc197e0 */ 	jal	roomGetProps
/*  f157dec:	24060100 */ 	addiu	$a2,$zero,0x100
/*  f157df0:	87af0038 */ 	lh	$t7,0x38($sp)
/*  f157df4:	02208025 */ 	or	$s0,$s1,$zero
/*  f157df8:	27b80038 */ 	addiu	$t8,$sp,0x38
/*  f157dfc:	05e0001d */ 	bltz	$t7,.L0f157e74
/*  f157e00:	2413002f */ 	addiu	$s3,$zero,0x2f
/*  f157e04:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f157e08:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f157e0c:	87020000 */ 	lh	$v0,0x0($t8)
/*  f157e10:	24110048 */ 	addiu	$s1,$zero,0x48
.L0f157e14:
/*  f157e14:	00510019 */ 	multu	$v0,$s1
/*  f157e18:	8e480338 */ 	lw	$t0,0x338($s2)
/*  f157e1c:	0000c812 */ 	mflo	$t9
/*  f157e20:	03282021 */ 	addu	$a0,$t9,$t0
/*  f157e24:	8c89003c */ 	lw	$t1,0x3c($a0)
/*  f157e28:	00095ec0 */ 	sll	$t3,$t1,0x1b
/*  f157e2c:	0562000e */ 	bltzl	$t3,.L0f157e68
/*  f157e30:	86020002 */ 	lh	$v0,0x2($s0)
/*  f157e34:	12800009 */ 	beqz	$s4,.L0f157e5c
/*  f157e38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f157e3c:	8c820004 */ 	lw	$v0,0x4($a0)
/*  f157e40:	904c0003 */ 	lbu	$t4,0x3($v0)
/*  f157e44:	566c0008 */ 	bnel	$s3,$t4,.L0f157e68
/*  f157e48:	86020002 */ 	lh	$v0,0x2($s0)
/*  f157e4c:	0fc18beb */ 	jal	func0f062fac
/*  f157e50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f157e54:	10000004 */ 	beqz	$zero,.L0f157e68
/*  f157e58:	86020002 */ 	lh	$v0,0x2($s0)
.L0f157e5c:
/*  f157e5c:	0fc18beb */ 	jal	func0f062fac
/*  f157e60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f157e64:	86020002 */ 	lh	$v0,0x2($s0)
.L0f157e68:
/*  f157e68:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f157e6c:	0441ffe9 */ 	bgez	$v0,.L0f157e14
/*  f157e70:	00000000 */ 	sll	$zero,$zero,0x0
.L0f157e74:
/*  f157e74:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f157e78:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f157e7c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f157e80:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f157e84:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f157e88:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f157e8c:	03e00008 */ 	jr	$ra
/*  f157e90:	27bd0248 */ 	addiu	$sp,$sp,0x248
);

GLOBAL_ASM(
glabel func0f157e94
/*  f157e94:	3c0c800a */ 	lui	$t4,%hi(g_RoomPtrs)
/*  f157e98:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f157e9c:	258c4928 */ 	addiu	$t4,$t4,%lo(g_RoomPtrs)
/*  f157ea0:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f157ea4:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f157ea8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f157eac:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f157eb0:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f157eb4:	000e5880 */ 	sll	$t3,$t6,0x2
/*  f157eb8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f157ebc:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f157ec0:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f157ec4:	01eb1021 */ 	addu	$v0,$t7,$t3
/*  f157ec8:	94430000 */ 	lhu	$v1,0x0($v0)
/*  f157ecc:	3c0d800a */ 	lui	$t5,%hi(var800a4ce8)
/*  f157ed0:	25ad4ce8 */ 	addiu	$t5,$t5,%lo(var800a4ce8)
/*  f157ed4:	30780001 */ 	andi	$t8,$v1,0x1
/*  f157ed8:	17000087 */ 	bnez	$t8,.L0f1580f8
/*  f157edc:	34790004 */ 	ori	$t9,$v1,0x4
/*  f157ee0:	a4590000 */ 	sh	$t9,0x0($v0)
/*  f157ee4:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f157ee8:	3c07800a */ 	lui	$a3,%hi(var800a4640)
/*  f157eec:	3c1f8008 */ 	lui	$ra,%hi(var8007fc2c)
/*  f157ef0:	01cb7821 */ 	addu	$t7,$t6,$t3
/*  f157ef4:	95f80000 */ 	lhu	$t8,0x0($t7)
/*  f157ef8:	24e74640 */ 	addiu	$a3,$a3,%lo(var800a4640)
/*  f157efc:	3c088008 */ 	lui	$t0,%hi(var8007fc3c)
/*  f157f00:	33190800 */ 	andi	$t9,$t8,0x800
/*  f157f04:	13200009 */ 	beqz	$t9,.L0f157f2c
/*  f157f08:	27fffc2c */ 	addiu	$ra,$ra,%lo(var8007fc2c)
/*  f157f0c:	84ee02d4 */ 	lh	$t6,0x2d4($a3)
/*  f157f10:	a4ce0000 */ 	sh	$t6,0x0($a2)
/*  f157f14:	84ef02d6 */ 	lh	$t7,0x2d6($a3)
/*  f157f18:	a4cf0002 */ 	sh	$t7,0x2($a2)
/*  f157f1c:	84f802d8 */ 	lh	$t8,0x2d8($a3)
/*  f157f20:	a4d80004 */ 	sh	$t8,0x4($a2)
/*  f157f24:	84f902da */ 	lh	$t9,0x2da($a3)
/*  f157f28:	a4d90006 */ 	sh	$t9,0x6($a2)
.L0f157f2c:
/*  f157f2c:	8fa90020 */ 	lw	$t1,0x20($sp)
/*  f157f30:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f157f34:	9508fc3c */ 	lhu	$t0,%lo(var8007fc3c)($t0)
/*  f157f38:	00097080 */ 	sll	$t6,$t1,0x2
/*  f157f3c:	01ee2821 */ 	addu	$a1,$t7,$t6
/*  f157f40:	94b80000 */ 	lhu	$t8,0x0($a1)
/*  f157f44:	3c07800a */ 	lui	$a3,%hi(var800a4640)
/*  f157f48:	24e74640 */ 	addiu	$a3,$a3,%lo(var800a4640)
/*  f157f4c:	1518001f */ 	bne	$t0,$t8,.L0f157fcc
/*  f157f50:	01c04825 */ 	or	$t1,$t6,$zero
/*  f157f54:	84a40002 */ 	lh	$a0,0x2($a1)
/*  f157f58:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f157f5c:	3c0a800a */ 	lui	$t2,%hi(var800a4ce4+0x2)
/*  f157f60:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f157f64:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f157f68:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f157f6c:	00f91021 */ 	addu	$v0,$a3,$t9
/*  f157f70:	904e0003 */ 	lbu	$t6,0x3($v0)
/*  f157f74:	254a4ce6 */ 	addiu	$t2,$t2,%lo(var800a4ce4+0x2)
/*  f157f78:	8fb80024 */ 	lw	$t8,0x24($sp)
/*  f157f7c:	01cf082a */ 	slt	$at,$t6,$t7
/*  f157f80:	1020000e */ 	beqz	$at,.L0f157fbc
/*  f157f84:	24440004 */ 	addiu	$a0,$v0,0x4
/*  f157f88:	85590000 */ 	lh	$t9,0x0($t2)
/*  f157f8c:	330300ff */ 	andi	$v1,$t8,0xff
/*  f157f90:	a0580003 */ 	sb	$t8,0x3($v0)
/*  f157f94:	0323082a */ 	slt	$at,$t9,$v1
/*  f157f98:	10200002 */ 	beqz	$at,.L0f157fa4
/*  f157f9c:	3c07800a */ 	lui	$a3,%hi(var800a4ce4)
/*  f157fa0:	a5430000 */ 	sh	$v1,0x0($t2)
.L0f157fa4:
/*  f157fa4:	24e74ce4 */ 	addiu	$a3,$a3,%lo(var800a4ce4)
/*  f157fa8:	84ee0000 */ 	lh	$t6,0x0($a3)
/*  f157fac:	006e082a */ 	slt	$at,$v1,$t6
/*  f157fb0:	10200002 */ 	beqz	$at,.L0f157fbc
/*  f157fb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f157fb8:	a4e30000 */ 	sh	$v1,0x0($a3)
.L0f157fbc:
/*  f157fbc:	0fc5758f */ 	jal	func0f15d63c
/*  f157fc0:	00c02825 */ 	or	$a1,$a2,$zero
/*  f157fc4:	1000004d */ 	beqz	$zero,.L0f1580fc
/*  f157fc8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f157fcc:
/*  f157fcc:	8fe40000 */ 	lw	$a0,0x0($ra)
/*  f157fd0:	8fb80020 */ 	lw	$t8,0x20($sp)
/*  f157fd4:	2881003c */ 	slti	$at,$a0,0x3c
/*  f157fd8:	54200003 */ 	bnezl	$at,.L0f157fe8
/*  f157fdc:	00047880 */ 	sll	$t7,$a0,0x2
/*  f157fe0:	2404003b */ 	addiu	$a0,$zero,0x3b
/*  f157fe4:	00047880 */ 	sll	$t7,$a0,0x2
.L0f157fe8:
/*  f157fe8:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f157fec:	8fb90024 */ 	lw	$t9,0x24($sp)
/*  f157ff0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f157ff4:	00ef1021 */ 	addu	$v0,$a3,$t7
/*  f157ff8:	a4580000 */ 	sh	$t8,0x0($v0)
/*  f157ffc:	a0590003 */ 	sb	$t9,0x3($v0)
/*  f158000:	84ce0000 */ 	lh	$t6,0x0($a2)
/*  f158004:	3c0a800a */ 	lui	$t2,%hi(var800a4ce4+0x2)
/*  f158008:	254a4ce6 */ 	addiu	$t2,$t2,%lo(var800a4ce4+0x2)
/*  f15800c:	a44e0004 */ 	sh	$t6,0x4($v0)
/*  f158010:	84cf0002 */ 	lh	$t7,0x2($a2)
/*  f158014:	854e0000 */ 	lh	$t6,0x0($t2)
/*  f158018:	90430003 */ 	lbu	$v1,0x3($v0)
/*  f15801c:	a44f0006 */ 	sh	$t7,0x6($v0)
/*  f158020:	84d80004 */ 	lh	$t8,0x4($a2)
/*  f158024:	3c07800a */ 	lui	$a3,%hi(var800a4ce4)
/*  f158028:	01c3082a */ 	slt	$at,$t6,$v1
/*  f15802c:	a4580008 */ 	sh	$t8,0x8($v0)
/*  f158030:	84d90006 */ 	lh	$t9,0x6($a2)
/*  f158034:	24e74ce4 */ 	addiu	$a3,$a3,%lo(var800a4ce4)
/*  f158038:	10200002 */ 	beqz	$at,.L0f158044
/*  f15803c:	a459000a */ 	sh	$t9,0xa($v0)
/*  f158040:	a5430000 */ 	sh	$v1,0x0($t2)
.L0f158044:
/*  f158044:	84ef0000 */ 	lh	$t7,0x0($a3)
/*  f158048:	006f082a */ 	slt	$at,$v1,$t7
/*  f15804c:	50200003 */ 	beqzl	$at,.L0f15805c
/*  f158050:	a4a80000 */ 	sh	$t0,0x0($a1)
/*  f158054:	a4e30000 */ 	sh	$v1,0x0($a3)
/*  f158058:	a4a80000 */ 	sh	$t0,0x0($a1)
.L0f15805c:
/*  f15805c:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f158060:	3c028008 */ 	lui	$v0,%hi(var8007fc30)
/*  f158064:	2442fc30 */ 	addiu	$v0,$v0,%lo(var8007fc30)
/*  f158068:	0309c821 */ 	addu	$t9,$t8,$t1
/*  f15806c:	a7240002 */ 	sh	$a0,0x2($t9)
/*  f158070:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f158074:	00002825 */ 	or	$a1,$zero,$zero
/*  f158078:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f15807c:	29e1003c */ 	slti	$at,$t7,0x3c
/*  f158080:	10200002 */ 	beqz	$at,.L0f15808c
/*  f158084:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f158088:	afef0000 */ 	sw	$t7,0x0($ra)
.L0f15808c:
/*  f15808c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f158090:	0fc55f6c */ 	jal	func0f157db0
/*  f158094:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f158098:	3c0c800a */ 	lui	$t4,%hi(g_RoomPtrs)
/*  f15809c:	258c4928 */ 	addiu	$t4,$t4,%lo(g_RoomPtrs)
/*  f1580a0:	8fab0018 */ 	lw	$t3,0x18($sp)
/*  f1580a4:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f1580a8:	3c058008 */ 	lui	$a1,%hi(var8007fc10)
/*  f1580ac:	24a5fc10 */ 	addiu	$a1,$a1,%lo(var8007fc10)
/*  f1580b0:	030bc821 */ 	addu	$t9,$t8,$t3
/*  f1580b4:	87220002 */ 	lh	$v0,0x2($t9)
/*  f1580b8:	14400009 */ 	bnez	$v0,.L0f1580e0
/*  f1580bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1580c0:	84a30000 */ 	lh	$v1,0x0($a1)
/*  f1580c4:	18600006 */ 	blez	$v1,.L0f1580e0
/*  f1580c8:	246effff */ 	addiu	$t6,$v1,-1
/*  f1580cc:	a4ae0000 */ 	sh	$t6,0x0($a1)
/*  f1580d0:	0fc57716 */ 	jal	func0f15dc58
/*  f1580d4:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f1580d8:	10000008 */ 	beqz	$zero,.L0f1580fc
/*  f1580dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1580e0:
/*  f1580e0:	3c058008 */ 	lui	$a1,%hi(var8007fc10)
/*  f1580e4:	14400004 */ 	bnez	$v0,.L0f1580f8
/*  f1580e8:	24a5fc10 */ 	addiu	$a1,$a1,%lo(var8007fc10)
/*  f1580ec:	84af0000 */ 	lh	$t7,0x0($a1)
/*  f1580f0:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f1580f4:	a4b80000 */ 	sh	$t8,0x0($a1)
.L0f1580f8:
/*  f1580f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1580fc:
/*  f1580fc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f158100:	03e00008 */ 	jr	$ra
/*  f158104:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f158108
/*  f158108:	3c03800a */ 	lui	$v1,%hi(var800a4cc4)
/*  f15810c:	24634cc4 */ 	addiu	$v1,$v1,%lo(var800a4cc4)
/*  f158110:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f158114:	00041080 */ 	sll	$v0,$a0,0x2
/*  f158118:	00441021 */ 	addu	$v0,$v0,$a0
/*  f15811c:	00021080 */ 	sll	$v0,$v0,0x2
/*  f158120:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f158124:	91f80010 */ 	lbu	$t8,0x10($t7)
/*  f158128:	a0b80000 */ 	sb	$t8,0x0($a1)
/*  f15812c:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f158130:	03224021 */ 	addu	$t0,$t9,$v0
/*  f158134:	91090011 */ 	lbu	$t1,0x11($t0)
/*  f158138:	03e00008 */ 	jr	$ra
/*  f15813c:	a0c90000 */ 	sb	$t1,0x0($a2)
);

GLOBAL_ASM(
glabel func0f158140
/*  f158140:	3c0e800a */ 	lui	$t6,%hi(var800a4ce8)
/*  f158144:	8dce4ce8 */ 	lw	$t6,%lo(var800a4ce8)($t6)
/*  f158148:	00047880 */ 	sll	$t7,$a0,0x2
/*  f15814c:	3c188008 */ 	lui	$t8,%hi(var8007fc3c)
/*  f158150:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f158154:	94590000 */ 	lhu	$t9,0x0($v0)
/*  f158158:	9718fc3c */ 	lhu	$t8,%lo(var8007fc3c)($t8)
/*  f15815c:	3c09800a */ 	lui	$t1,%hi(var800a4640)
/*  f158160:	2403003c */ 	addiu	$v1,$zero,0x3c
/*  f158164:	17190002 */ 	bne	$t8,$t9,.L0f158170
/*  f158168:	25294640 */ 	addiu	$t1,$t1,%lo(var800a4640)
/*  f15816c:	84430002 */ 	lh	$v1,0x2($v0)
.L0f158170:
/*  f158170:	00034080 */ 	sll	$t0,$v1,0x2
/*  f158174:	01034023 */ 	subu	$t0,$t0,$v1
/*  f158178:	00084080 */ 	sll	$t0,$t0,0x2
/*  f15817c:	03e00008 */ 	jr	$ra
/*  f158180:	01091021 */ 	addu	$v0,$t0,$t1
);

GLOBAL_ASM(
glabel func0f158184
/*  f158184:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f158188:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f15818c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f158190:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f158194:	84ae024a */ 	lh	$t6,0x24a($a1)
/*  f158198:	00808025 */ 	or	$s0,$a0,$zero
/*  f15819c:	00a08825 */ 	or	$s1,$a1,$zero
/*  f1581a0:	59c00090 */ 	blezl	$t6,.L0f1583e4
/*  f1581a4:	a620024a */ 	sh	$zero,0x24a($s1)
/*  f1581a8:	0fc59e59 */ 	jal	func0f167964
/*  f1581ac:	84a40248 */ 	lh	$a0,0x248($a1)
/*  f1581b0:	86240248 */ 	lh	$a0,0x248($s1)
/*  f1581b4:	0fc59e73 */ 	jal	func0f1679cc
/*  f1581b8:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1581bc:	86280248 */ 	lh	$t0,0x248($s1)
/*  f1581c0:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f1581c4:	00002825 */ 	or	$a1,$zero,$zero
/*  f1581c8:	19000017 */ 	blez	$t0,.L0f158228
/*  f1581cc:	01402025 */ 	or	$a0,$t2,$zero
/*  f1581d0:	02201825 */ 	or	$v1,$s1,$zero
/*  f1581d4:	02203025 */ 	or	$a2,$s1,$zero
/*  f1581d8:	00403825 */ 	or	$a3,$v0,$zero
/*  f1581dc:	846f0028 */ 	lh	$t7,0x28($v1)
.L0f1581e0:
/*  f1581e0:	00055880 */ 	sll	$t3,$a1,0x2
/*  f1581e4:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f1581e8:	a48f0000 */ 	sh	$t7,0x0($a0)
/*  f1581ec:	8478002a */ 	lh	$t8,0x2a($v1)
/*  f1581f0:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f1581f4:	24630006 */ 	addiu	$v1,$v1,0x6
/*  f1581f8:	a498fff6 */ 	sh	$t8,-0xa($a0)
/*  f1581fc:	84790026 */ 	lh	$t9,0x26($v1)
/*  f158200:	a08bfffb */ 	sb	$t3,-0x5($a0)
/*  f158204:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f158208:	a499fff8 */ 	sh	$t9,-0x8($a0)
/*  f15820c:	8ccc0084 */ 	lw	$t4,0x84($a2)
/*  f158210:	24e70004 */ 	addiu	$a3,$a3,0x4
/*  f158214:	acecfffc */ 	sw	$t4,-0x4($a3)
/*  f158218:	86280248 */ 	lh	$t0,0x248($s1)
/*  f15821c:	00a8082a */ 	slt	$at,$a1,$t0
/*  f158220:	5420ffef */ 	bnezl	$at,.L0f1581e0
/*  f158224:	846f0028 */ 	lh	$t7,0x28($v1)
.L0f158228:
/*  f158228:	250dffff */ 	addiu	$t5,$t0,-1
/*  f15822c:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f158230:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f158234:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f158238:	3c010700 */ 	lui	$at,0x700
/*  f15823c:	00085880 */ 	sll	$t3,$t0,0x2
/*  f158240:	316cffff */ 	andi	$t4,$t3,0xffff
/*  f158244:	0301c825 */ 	or	$t9,$t8,$at
/*  f158248:	02003825 */ 	or	$a3,$s0,$zero
/*  f15824c:	032c6825 */ 	or	$t5,$t9,$t4
/*  f158250:	aced0000 */ 	sw	$t5,0x0($a3)
/*  f158254:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f158258:	86230248 */ 	lh	$v1,0x248($s1)
/*  f15825c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f158260:	3c010400 */ 	lui	$at,0x400
/*  f158264:	246effff */ 	addiu	$t6,$v1,-1
/*  f158268:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f15826c:	00036080 */ 	sll	$t4,$v1,0x2
/*  f158270:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f158274:	01836023 */ 	subu	$t4,$t4,$v1
/*  f158278:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f15827c:	00185c00 */ 	sll	$t3,$t8,0x10
/*  f158280:	0161c825 */ 	or	$t9,$t3,$at
/*  f158284:	318dffff */ 	andi	$t5,$t4,0xffff
/*  f158288:	02004825 */ 	or	$t1,$s0,$zero
/*  f15828c:	032d7025 */ 	or	$t6,$t9,$t5
/*  f158290:	ad2e0000 */ 	sw	$t6,0x0($t1)
/*  f158294:	ad2a0004 */ 	sw	$t2,0x4($t1)
/*  f158298:	8624024a */ 	lh	$a0,0x24a($s1)
/*  f15829c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1582a0:	2486ffff */ 	addiu	$a2,$a0,-1
/*  f1582a4:	04c10003 */ 	bgez	$a2,.L0f1582b4
/*  f1582a8:	00067883 */ 	sra	$t7,$a2,0x2
/*  f1582ac:	24c10003 */ 	addiu	$at,$a2,0x3
/*  f1582b0:	00017883 */ 	sra	$t7,$at,0x2
.L0f1582b4:
/*  f1582b4:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f1582b8:	0098082a */ 	slt	$at,$a0,$t8
/*  f1582bc:	25e60001 */ 	addiu	$a2,$t7,0x1
/*  f1582c0:	10200010 */ 	beqz	$at,.L0f158304
/*  f1582c4:	00802825 */ 	or	$a1,$a0,$zero
/*  f1582c8:	00045880 */ 	sll	$t3,$a0,0x2
/*  f1582cc:	01645823 */ 	subu	$t3,$t3,$a0
/*  f1582d0:	000b5840 */ 	sll	$t3,$t3,0x1
/*  f1582d4:	022b1821 */ 	addu	$v1,$s1,$t3
/*  f1582d8:	a46000cc */ 	sh	$zero,0xcc($v1)
.L0f1582dc:
/*  f1582dc:	846200cc */ 	lh	$v0,0xcc($v1)
/*  f1582e0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f1582e4:	24630006 */ 	addiu	$v1,$v1,0x6
/*  f1582e8:	a46200c4 */ 	sh	$v0,0xc4($v1)
/*  f1582ec:	a46200c2 */ 	sh	$v0,0xc2($v1)
/*  f1582f0:	862c024a */ 	lh	$t4,0x24a($s1)
/*  f1582f4:	000cc880 */ 	sll	$t9,$t4,0x2
/*  f1582f8:	00b9082a */ 	slt	$at,$a1,$t9
/*  f1582fc:	5420fff7 */ 	bnezl	$at,.L0f1582dc
/*  f158300:	a46000cc */ 	sh	$zero,0xcc($v1)
.L0f158304:
/*  f158304:	18c00036 */ 	blez	$a2,.L0f1583e0
/*  f158308:	00002825 */ 	or	$a1,$zero,$zero
/*  f15830c:	02201025 */ 	or	$v0,$s1,$zero
/*  f158310:	3c04b100 */ 	lui	$a0,0xb100
.L0f158314:
/*  f158314:	844d00cc */ 	lh	$t5,0xcc($v0)
/*  f158318:	845800de */ 	lh	$t8,0xde($v0)
/*  f15831c:	02001825 */ 	or	$v1,$s0,$zero
/*  f158320:	31ae000f */ 	andi	$t6,$t5,0xf
/*  f158324:	330b000f */ 	andi	$t3,$t8,0xf
/*  f158328:	000b6300 */ 	sll	$t4,$t3,0xc
/*  f15832c:	01c47825 */ 	or	$t7,$t6,$a0
/*  f158330:	844d00d8 */ 	lh	$t5,0xd8($v0)
/*  f158334:	01ecc825 */ 	or	$t9,$t7,$t4
/*  f158338:	844f00d2 */ 	lh	$t7,0xd2($v0)
/*  f15833c:	31ae000f */ 	andi	$t6,$t5,0xf
/*  f158340:	000ec200 */ 	sll	$t8,$t6,0x8
/*  f158344:	31ec000f */ 	andi	$t4,$t7,0xf
/*  f158348:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f15834c:	03385825 */ 	or	$t3,$t9,$t8
/*  f158350:	016d7025 */ 	or	$t6,$t3,$t5
/*  f158354:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f158358:	844c00dc */ 	lh	$t4,0xdc($v0)
/*  f15835c:	845900c8 */ 	lh	$t9,0xc8($v0)
/*  f158360:	844e00da */ 	lh	$t6,0xda($v0)
/*  f158364:	000c5f00 */ 	sll	$t3,$t4,0x1c
/*  f158368:	3338000f */ 	andi	$t8,$t9,0xf
/*  f15836c:	030b6825 */ 	or	$t5,$t8,$t3
/*  f158370:	845800d6 */ 	lh	$t8,0xd6($v0)
/*  f158374:	31d9000f */ 	andi	$t9,$t6,0xf
/*  f158378:	00197e00 */ 	sll	$t7,$t9,0x18
/*  f15837c:	01af6025 */ 	or	$t4,$t5,$t7
/*  f158380:	330b000f */ 	andi	$t3,$t8,0xf
/*  f158384:	844d00d4 */ 	lh	$t5,0xd4($v0)
/*  f158388:	000b7500 */ 	sll	$t6,$t3,0x14
/*  f15838c:	018ec825 */ 	or	$t9,$t4,$t6
/*  f158390:	844c00d0 */ 	lh	$t4,0xd0($v0)
/*  f158394:	31af000f */ 	andi	$t7,$t5,0xf
/*  f158398:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f15839c:	03385825 */ 	or	$t3,$t9,$t8
/*  f1583a0:	318e000f */ 	andi	$t6,$t4,0xf
/*  f1583a4:	000e6b00 */ 	sll	$t5,$t6,0xc
/*  f1583a8:	845900ce */ 	lh	$t9,0xce($v0)
/*  f1583ac:	016d7825 */ 	or	$t7,$t3,$t5
/*  f1583b0:	844b00ca */ 	lh	$t3,0xca($v0)
/*  f1583b4:	3338000f */ 	andi	$t8,$t9,0xf
/*  f1583b8:	00186200 */ 	sll	$t4,$t8,0x8
/*  f1583bc:	316d000f */ 	andi	$t5,$t3,0xf
/*  f1583c0:	000dc900 */ 	sll	$t9,$t5,0x4
/*  f1583c4:	01ec7025 */ 	or	$t6,$t7,$t4
/*  f1583c8:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f1583cc:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f1583d0:	24420018 */ 	addiu	$v0,$v0,0x18
/*  f1583d4:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f1583d8:	14a6ffce */ 	bne	$a1,$a2,.L0f158314
/*  f1583dc:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f1583e0:
/*  f1583e0:	a620024a */ 	sh	$zero,0x24a($s1)
.L0f1583e4:
/*  f1583e4:	a6200248 */ 	sh	$zero,0x248($s1)
/*  f1583e8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1583ec:	02001025 */ 	or	$v0,$s0,$zero
/*  f1583f0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1583f4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1583f8:	03e00008 */ 	jr	$ra
/*  f1583fc:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f158400
/*  f158400:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f158404:	3c0f8008 */ 	lui	$t7,%hi(var8007fc44)
/*  f158408:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f15840c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f158410:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f158414:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f158418:	25effc44 */ 	addiu	$t7,$t7,%lo(var8007fc44)
/*  f15841c:	8de10000 */ 	lw	$at,0x0($t7)
/*  f158420:	27ae0030 */ 	addiu	$t6,$sp,0x30
/*  f158424:	00c08025 */ 	or	$s0,$a2,$zero
/*  f158428:	adc10000 */ 	sw	$at,0x0($t6)
/*  f15842c:	95e10004 */ 	lhu	$at,0x4($t7)
/*  f158430:	00e08825 */ 	or	$s1,$a3,$zero
/*  f158434:	00004025 */ 	or	$t0,$zero,$zero
/*  f158438:	a5c10004 */ 	sh	$at,0x4($t6)
/*  f15843c:	84ab024a */ 	lh	$t3,0x24a($a1)
/*  f158440:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f158444:	29610040 */ 	slti	$at,$t3,0x40
/*  f158448:	54200008 */ 	bnezl	$at,.L0f15846c
/*  f15844c:	84a40248 */ 	lh	$a0,0x248($a1)
/*  f158450:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f158454:	0fc56061 */ 	jal	func0f158184
/*  f158458:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f15845c:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f158460:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f158464:	afa20038 */ 	sw	$v0,0x38($sp)
/*  f158468:	84a40248 */ 	lh	$a0,0x248($a1)
.L0f15846c:
/*  f15846c:	00001825 */ 	or	$v1,$zero,$zero
/*  f158470:	87ac0030 */ 	lh	$t4,0x30($sp)
/*  f158474:	1880001d */ 	blez	$a0,.L0f1584ec
/*  f158478:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f15847c:	152c001b */ 	bne	$t1,$t4,.L0f1584ec
/*  f158480:	24070006 */ 	addiu	$a3,$zero,0x6
.L0f158484:
/*  f158484:	00670019 */ 	multu	$v1,$a3
/*  f158488:	86190000 */ 	lh	$t9,0x0($s0)
/*  f15848c:	00006812 */ 	mflo	$t5
/*  f158490:	00ad1021 */ 	addu	$v0,$a1,$t5
/*  f158494:	84580028 */ 	lh	$t8,0x28($v0)
/*  f158498:	5738000d */ 	bnel	$t9,$t8,.L0f1584d0
/*  f15849c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1584a0:	860e0002 */ 	lh	$t6,0x2($s0)
/*  f1584a4:	844f002a */ 	lh	$t7,0x2a($v0)
/*  f1584a8:	55cf0009 */ 	bnel	$t6,$t7,.L0f1584d0
/*  f1584ac:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1584b0:	860a0004 */ 	lh	$t2,0x4($s0)
/*  f1584b4:	844b002c */ 	lh	$t3,0x2c($v0)
/*  f1584b8:	554b0005 */ 	bnel	$t2,$t3,.L0f1584d0
/*  f1584bc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1584c0:	a7a30030 */ 	sh	$v1,0x30($sp)
/*  f1584c4:	84a40248 */ 	lh	$a0,0x248($a1)
/*  f1584c8:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f1584cc:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f1584d0:
/*  f1584d0:	00036400 */ 	sll	$t4,$v1,0x10
/*  f1584d4:	000c1c03 */ 	sra	$v1,$t4,0x10
/*  f1584d8:	0064082a */ 	slt	$at,$v1,$a0
/*  f1584dc:	10200003 */ 	beqz	$at,.L0f1584ec
/*  f1584e0:	87b90030 */ 	lh	$t9,0x30($sp)
/*  f1584e4:	1139ffe7 */ 	beq	$t1,$t9,.L0f158484
/*  f1584e8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1584ec:
/*  f1584ec:	24070006 */ 	addiu	$a3,$zero,0x6
/*  f1584f0:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f1584f4:	1880001e */ 	blez	$a0,.L0f158570
/*  f1584f8:	00001825 */ 	or	$v1,$zero,$zero
/*  f1584fc:	87b80032 */ 	lh	$t8,0x32($sp)
/*  f158500:	1538001b */ 	bne	$t1,$t8,.L0f158570
/*  f158504:	00000000 */ 	sll	$zero,$zero,0x0
.L0f158508:
/*  f158508:	00670019 */ 	multu	$v1,$a3
/*  f15850c:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f158510:	00007012 */ 	mflo	$t6
/*  f158514:	00ae1021 */ 	addu	$v0,$a1,$t6
/*  f158518:	844a0028 */ 	lh	$t2,0x28($v0)
/*  f15851c:	55ea000d */ 	bnel	$t7,$t2,.L0f158554
/*  f158520:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f158524:	862b0002 */ 	lh	$t3,0x2($s1)
/*  f158528:	844c002a */ 	lh	$t4,0x2a($v0)
/*  f15852c:	556c0009 */ 	bnel	$t3,$t4,.L0f158554
/*  f158530:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f158534:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f158538:	8459002c */ 	lh	$t9,0x2c($v0)
/*  f15853c:	55b90005 */ 	bnel	$t5,$t9,.L0f158554
/*  f158540:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f158544:	a7a30032 */ 	sh	$v1,0x32($sp)
/*  f158548:	84a40248 */ 	lh	$a0,0x248($a1)
/*  f15854c:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f158550:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f158554:
/*  f158554:	0003c400 */ 	sll	$t8,$v1,0x10
/*  f158558:	00181c03 */ 	sra	$v1,$t8,0x10
/*  f15855c:	0064082a */ 	slt	$at,$v1,$a0
/*  f158560:	10200003 */ 	beqz	$at,.L0f158570
/*  f158564:	87af0032 */ 	lh	$t7,0x32($sp)
/*  f158568:	112fffe7 */ 	beq	$t1,$t7,.L0f158508
/*  f15856c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f158570:
/*  f158570:	1880001f */ 	blez	$a0,.L0f1585f0
/*  f158574:	00001825 */ 	or	$v1,$zero,$zero
/*  f158578:	87aa0034 */ 	lh	$t2,0x34($sp)
/*  f15857c:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f158580:	552a001c */ 	bnel	$t1,$t2,.L0f1585f4
/*  f158584:	29010003 */ 	slti	$at,$t0,0x3
.L0f158588:
/*  f158588:	00670019 */ 	multu	$v1,$a3
/*  f15858c:	84cc0000 */ 	lh	$t4,0x0($a2)
/*  f158590:	00005812 */ 	mflo	$t3
/*  f158594:	00ab1021 */ 	addu	$v0,$a1,$t3
/*  f158598:	844d0028 */ 	lh	$t5,0x28($v0)
/*  f15859c:	558d000d */ 	bnel	$t4,$t5,.L0f1585d4
/*  f1585a0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1585a4:	84d90002 */ 	lh	$t9,0x2($a2)
/*  f1585a8:	8458002a */ 	lh	$t8,0x2a($v0)
/*  f1585ac:	57380009 */ 	bnel	$t9,$t8,.L0f1585d4
/*  f1585b0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1585b4:	84ce0004 */ 	lh	$t6,0x4($a2)
/*  f1585b8:	844f002c */ 	lh	$t7,0x2c($v0)
/*  f1585bc:	55cf0005 */ 	bnel	$t6,$t7,.L0f1585d4
/*  f1585c0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1585c4:	a7a30034 */ 	sh	$v1,0x34($sp)
/*  f1585c8:	84a40248 */ 	lh	$a0,0x248($a1)
/*  f1585cc:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f1585d0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f1585d4:
/*  f1585d4:	00035400 */ 	sll	$t2,$v1,0x10
/*  f1585d8:	000a1c03 */ 	sra	$v1,$t2,0x10
/*  f1585dc:	0064082a */ 	slt	$at,$v1,$a0
/*  f1585e0:	10200003 */ 	beqz	$at,.L0f1585f0
/*  f1585e4:	87ac0034 */ 	lh	$t4,0x34($sp)
/*  f1585e8:	112cffe7 */ 	beq	$t1,$t4,.L0f158588
/*  f1585ec:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1585f0:
/*  f1585f0:	29010003 */ 	slti	$at,$t0,0x3
.L0f1585f4:
/*  f1585f4:	10200088 */ 	beqz	$at,.L0f158818
/*  f1585f8:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f1585fc:	00886823 */ 	subu	$t5,$a0,$t0
/*  f158600:	25b90003 */ 	addiu	$t9,$t5,0x3
/*  f158604:	2b210011 */ 	slti	$at,$t9,0x11
/*  f158608:	14200028 */ 	bnez	$at,.L0f1586ac
/*  f15860c:	87b90030 */ 	lh	$t9,0x30($sp)
/*  f158610:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f158614:	0fc56061 */ 	jal	func0f158184
/*  f158618:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f15861c:	afa20038 */ 	sw	$v0,0x38($sp)
/*  f158620:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f158624:	86180000 */ 	lh	$t8,0x0($s0)
/*  f158628:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f15862c:	24070006 */ 	addiu	$a3,$zero,0x6
/*  f158630:	a4b80028 */ 	sh	$t8,0x28($a1)
/*  f158634:	860e0002 */ 	lh	$t6,0x2($s0)
/*  f158638:	a4ae002a */ 	sh	$t6,0x2a($a1)
/*  f15863c:	860f0004 */ 	lh	$t7,0x4($s0)
/*  f158640:	a4af002c */ 	sh	$t7,0x2c($a1)
/*  f158644:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f158648:	acaa0088 */ 	sw	$t2,0x88($a1)
/*  f15864c:	862b0000 */ 	lh	$t3,0x0($s1)
/*  f158650:	a4ab002e */ 	sh	$t3,0x2e($a1)
/*  f158654:	862c0002 */ 	lh	$t4,0x2($s1)
/*  f158658:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f15865c:	a4ac0030 */ 	sh	$t4,0x30($a1)
/*  f158660:	862d0004 */ 	lh	$t5,0x4($s1)
/*  f158664:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f158668:	a4ad0032 */ 	sh	$t5,0x32($a1)
/*  f15866c:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f158670:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f158674:	acb9008c */ 	sw	$t9,0x8c($a1)
/*  f158678:	84d80000 */ 	lh	$t8,0x0($a2)
/*  f15867c:	a4b80034 */ 	sh	$t8,0x34($a1)
/*  f158680:	84ce0002 */ 	lh	$t6,0x2($a2)
/*  f158684:	a4ae0036 */ 	sh	$t6,0x36($a1)
/*  f158688:	84cf0004 */ 	lh	$t7,0x4($a2)
/*  f15868c:	a4af0038 */ 	sh	$t7,0x38($a1)
/*  f158690:	8faa0054 */ 	lw	$t2,0x54($sp)
/*  f158694:	a4ab0248 */ 	sh	$t3,0x248($a1)
/*  f158698:	acaa0090 */ 	sw	$t2,0x90($a1)
/*  f15869c:	a7a00030 */ 	sh	$zero,0x30($sp)
/*  f1586a0:	a7ac0032 */ 	sh	$t4,0x32($sp)
/*  f1586a4:	1000005c */ 	beqz	$zero,.L0f158818
/*  f1586a8:	a7ad0034 */ 	sh	$t5,0x34($sp)
.L0f1586ac:
/*  f1586ac:	5539001d */ 	bnel	$t1,$t9,.L0f158724
/*  f1586b0:	87af0032 */ 	lh	$t7,0x32($sp)
/*  f1586b4:	00870019 */ 	multu	$a0,$a3
/*  f1586b8:	86180000 */ 	lh	$t8,0x0($s0)
/*  f1586bc:	00007012 */ 	mflo	$t6
/*  f1586c0:	00ae7821 */ 	addu	$t7,$a1,$t6
/*  f1586c4:	a5f80028 */ 	sh	$t8,0x28($t7)
/*  f1586c8:	84ab0248 */ 	lh	$t3,0x248($a1)
/*  f1586cc:	860a0002 */ 	lh	$t2,0x2($s0)
/*  f1586d0:	01670019 */ 	multu	$t3,$a3
/*  f1586d4:	00006012 */ 	mflo	$t4
/*  f1586d8:	00ac6821 */ 	addu	$t5,$a1,$t4
/*  f1586dc:	a5aa002a */ 	sh	$t2,0x2a($t5)
/*  f1586e0:	84ae0248 */ 	lh	$t6,0x248($a1)
/*  f1586e4:	86190004 */ 	lh	$t9,0x4($s0)
/*  f1586e8:	01c70019 */ 	multu	$t6,$a3
/*  f1586ec:	0000c012 */ 	mflo	$t8
/*  f1586f0:	00b87821 */ 	addu	$t7,$a1,$t8
/*  f1586f4:	a5f9002c */ 	sh	$t9,0x2c($t7)
/*  f1586f8:	84ac0248 */ 	lh	$t4,0x248($a1)
/*  f1586fc:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f158700:	000c5080 */ 	sll	$t2,$t4,0x2
/*  f158704:	00aa6821 */ 	addu	$t5,$a1,$t2
/*  f158708:	adab0088 */ 	sw	$t3,0x88($t5)
/*  f15870c:	84ae0248 */ 	lh	$t6,0x248($a1)
/*  f158710:	a7ae0030 */ 	sh	$t6,0x30($sp)
/*  f158714:	84b80248 */ 	lh	$t8,0x248($a1)
/*  f158718:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f15871c:	a4b90248 */ 	sh	$t9,0x248($a1)
/*  f158720:	87af0032 */ 	lh	$t7,0x32($sp)
.L0f158724:
/*  f158724:	552f001e */ 	bnel	$t1,$t7,.L0f1587a0
/*  f158728:	87ad0034 */ 	lh	$t5,0x34($sp)
/*  f15872c:	84aa0248 */ 	lh	$t2,0x248($a1)
/*  f158730:	862c0000 */ 	lh	$t4,0x0($s1)
/*  f158734:	01470019 */ 	multu	$t2,$a3
/*  f158738:	00005812 */ 	mflo	$t3
/*  f15873c:	00ab6821 */ 	addu	$t5,$a1,$t3
/*  f158740:	a5ac0028 */ 	sh	$t4,0x28($t5)
/*  f158744:	84b80248 */ 	lh	$t8,0x248($a1)
/*  f158748:	862e0002 */ 	lh	$t6,0x2($s1)
/*  f15874c:	03070019 */ 	multu	$t8,$a3
/*  f158750:	0000c812 */ 	mflo	$t9
/*  f158754:	00b97821 */ 	addu	$t7,$a1,$t9
/*  f158758:	a5ee002a */ 	sh	$t6,0x2a($t7)
/*  f15875c:	84ab0248 */ 	lh	$t3,0x248($a1)
/*  f158760:	862a0004 */ 	lh	$t2,0x4($s1)
/*  f158764:	01670019 */ 	multu	$t3,$a3
/*  f158768:	00006012 */ 	mflo	$t4
/*  f15876c:	00ac6821 */ 	addu	$t5,$a1,$t4
/*  f158770:	a5aa002c */ 	sh	$t2,0x2c($t5)
/*  f158774:	84b90248 */ 	lh	$t9,0x248($a1)
/*  f158778:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f15877c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f158780:	00ae7821 */ 	addu	$t7,$a1,$t6
/*  f158784:	adf80088 */ 	sw	$t8,0x88($t7)
/*  f158788:	84ab0248 */ 	lh	$t3,0x248($a1)
/*  f15878c:	a7ab0032 */ 	sh	$t3,0x32($sp)
/*  f158790:	84ac0248 */ 	lh	$t4,0x248($a1)
/*  f158794:	258a0001 */ 	addiu	$t2,$t4,0x1
/*  f158798:	a4aa0248 */ 	sh	$t2,0x248($a1)
/*  f15879c:	87ad0034 */ 	lh	$t5,0x34($sp)
.L0f1587a0:
/*  f1587a0:	552d001e */ 	bnel	$t1,$t5,.L0f15881c
/*  f1587a4:	84aa024a */ 	lh	$t2,0x24a($a1)
/*  f1587a8:	84ae0248 */ 	lh	$t6,0x248($a1)
/*  f1587ac:	84d90000 */ 	lh	$t9,0x0($a2)
/*  f1587b0:	01c70019 */ 	multu	$t6,$a3
/*  f1587b4:	0000c012 */ 	mflo	$t8
/*  f1587b8:	00b87821 */ 	addu	$t7,$a1,$t8
/*  f1587bc:	a5f90028 */ 	sh	$t9,0x28($t7)
/*  f1587c0:	84ac0248 */ 	lh	$t4,0x248($a1)
/*  f1587c4:	84cb0002 */ 	lh	$t3,0x2($a2)
/*  f1587c8:	01870019 */ 	multu	$t4,$a3
/*  f1587cc:	00005012 */ 	mflo	$t2
/*  f1587d0:	00aa6821 */ 	addu	$t5,$a1,$t2
/*  f1587d4:	a5ab002a */ 	sh	$t3,0x2a($t5)
/*  f1587d8:	84b80248 */ 	lh	$t8,0x248($a1)
/*  f1587dc:	84ce0004 */ 	lh	$t6,0x4($a2)
/*  f1587e0:	03070019 */ 	multu	$t8,$a3
/*  f1587e4:	0000c812 */ 	mflo	$t9
/*  f1587e8:	00b97821 */ 	addu	$t7,$a1,$t9
/*  f1587ec:	a5ee002c */ 	sh	$t6,0x2c($t7)
/*  f1587f0:	84aa0248 */ 	lh	$t2,0x248($a1)
/*  f1587f4:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f1587f8:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f1587fc:	00ab6821 */ 	addu	$t5,$a1,$t3
/*  f158800:	adac0088 */ 	sw	$t4,0x88($t5)
/*  f158804:	84b80248 */ 	lh	$t8,0x248($a1)
/*  f158808:	a7b80034 */ 	sh	$t8,0x34($sp)
/*  f15880c:	84b90248 */ 	lh	$t9,0x248($a1)
/*  f158810:	272e0001 */ 	addiu	$t6,$t9,0x1
/*  f158814:	a4ae0248 */ 	sh	$t6,0x248($a1)
.L0f158818:
/*  f158818:	84aa024a */ 	lh	$t2,0x24a($a1)
.L0f15881c:
/*  f15881c:	87af0030 */ 	lh	$t7,0x30($sp)
/*  f158820:	01470019 */ 	multu	$t2,$a3
/*  f158824:	00005812 */ 	mflo	$t3
/*  f158828:	00ab6021 */ 	addu	$t4,$a1,$t3
/*  f15882c:	a58f00c8 */ 	sh	$t7,0xc8($t4)
/*  f158830:	84b8024a */ 	lh	$t8,0x24a($a1)
/*  f158834:	87ad0032 */ 	lh	$t5,0x32($sp)
/*  f158838:	03070019 */ 	multu	$t8,$a3
/*  f15883c:	0000c812 */ 	mflo	$t9
/*  f158840:	00b97021 */ 	addu	$t6,$a1,$t9
/*  f158844:	a5cd00ca */ 	sh	$t5,0xca($t6)
/*  f158848:	84ab024a */ 	lh	$t3,0x24a($a1)
/*  f15884c:	87aa0034 */ 	lh	$t2,0x34($sp)
/*  f158850:	01670019 */ 	multu	$t3,$a3
/*  f158854:	00007812 */ 	mflo	$t7
/*  f158858:	00af6021 */ 	addu	$t4,$a1,$t7
/*  f15885c:	a58a00cc */ 	sh	$t2,0xcc($t4)
/*  f158860:	84b8024a */ 	lh	$t8,0x24a($a1)
/*  f158864:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f158868:	a4b9024a */ 	sh	$t9,0x24a($a1)
/*  f15886c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f158870:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f158874:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f158878:	8fa20038 */ 	lw	$v0,0x38($sp)
/*  f15887c:	03e00008 */ 	jr	$ra
/*  f158880:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f158884
.late_rodata
glabel var7f1b75b4
.word 0x3fc90fdb
glabel var7f1b75b8
.word 0x3f266666
glabel var7f1b75bc
.word 0x3eb33333
glabel var7f1b75c0
.word 0x3fc90fdb
.text
/*  f158884:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f158888:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f15888c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f158890:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f158894:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f158898:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f15889c:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f1588a0:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f1588a4:	84af0000 */ 	lh	$t7,0x0($a1)
/*  f1588a8:	44984000 */ 	mtc1	$t8,$f8
/*  f1588ac:	448f2000 */ 	mtc1	$t7,$f4
/*  f1588b0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1588b4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1588b8:	460a3481 */ 	sub.s	$f18,$f6,$f10
/*  f1588bc:	46129102 */ 	mul.s	$f4,$f18,$f18
/*  f1588c0:	e7b2002c */ 	swc1	$f18,0x2c($sp)
/*  f1588c4:	e7a4002c */ 	swc1	$f4,0x2c($sp)
/*  f1588c8:	c4e80010 */ 	lwc1	$f8,0x10($a3)
/*  f1588cc:	4608203c */ 	c.lt.s	$f4,$f8
/*  f1588d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1588d4:	45020128 */ 	bc1fl	.L0f158d78
/*  f1588d8:	8fa90038 */ 	lw	$t1,0x38($sp)
/*  f1588dc:	84b90004 */ 	lh	$t9,0x4($a1)
/*  f1588e0:	8ce80008 */ 	lw	$t0,0x8($a3)
/*  f1588e4:	44993000 */ 	mtc1	$t9,$f6
/*  f1588e8:	44889000 */ 	mtc1	$t0,$f18
/*  f1588ec:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f1588f0:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f1588f4:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f1588f8:	46063482 */ 	mul.s	$f18,$f6,$f6
/*  f1588fc:	e7a60034 */ 	swc1	$f6,0x34($sp)
/*  f158900:	e7b20034 */ 	swc1	$f18,0x34($sp)
/*  f158904:	c4ea0010 */ 	lwc1	$f10,0x10($a3)
/*  f158908:	460a903c */ 	c.lt.s	$f18,$f10
/*  f15890c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158910:	45020119 */ 	bc1fl	.L0f158d78
/*  f158914:	8fa90038 */ 	lw	$t1,0x38($sp)
/*  f158918:	84a90002 */ 	lh	$t1,0x2($a1)
/*  f15891c:	8cea0004 */ 	lw	$t2,0x4($a3)
/*  f158920:	44894000 */ 	mtc1	$t1,$f8
/*  f158924:	448a5000 */ 	mtc1	$t2,$f10
/*  f158928:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f15892c:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f158930:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f158934:	460a5182 */ 	mul.s	$f6,$f10,$f10
/*  f158938:	e7aa0030 */ 	swc1	$f10,0x30($sp)
/*  f15893c:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f158940:	c4e80010 */ 	lwc1	$f8,0x10($a3)
/*  f158944:	4608303c */ 	c.lt.s	$f6,$f8
/*  f158948:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15894c:	4502010a */ 	bc1fl	.L0f158d78
/*  f158950:	8fa90038 */ 	lw	$t1,0x38($sp)
/*  f158954:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f158958:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f15895c:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f158960:	0c012974 */ 	jal	sqrtf
/*  f158964:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f158968:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f15896c:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f158970:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f158974:	c4e8000c */ 	lwc1	$f8,0xc($a3)
/*  f158978:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15897c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158980:	450000fc */ 	bc1f	.L0f158d74
/*  f158984:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f158988:	ad8b0000 */ 	sw	$t3,0x0($t4)
/*  f15898c:	c4e4000c */ 	lwc1	$f4,0xc($a3)
/*  f158990:	c4e20014 */ 	lwc1	$f2,0x14($a3)
/*  f158994:	3c013f80 */ 	lui	$at,0x3f80
/*  f158998:	46040303 */ 	div.s	$f12,$f0,$f4
/*  f15899c:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1589a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1589a4:	45020009 */ 	bc1fl	.L0f1589cc
/*  f1589a8:	44817000 */ 	mtc1	$at,$f14
/*  f1589ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f1589b0:	44817000 */ 	mtc1	$at,$f14
/*  f1589b4:	46026181 */ 	sub.s	$f6,$f12,$f2
/*  f1589b8:	46027481 */ 	sub.s	$f18,$f14,$f2
/*  f1589bc:	46123283 */ 	div.s	$f10,$f6,$f18
/*  f1589c0:	10000004 */ 	beqz	$zero,.L0f1589d4
/*  f1589c4:	460a7401 */ 	sub.s	$f16,$f14,$f10
/*  f1589c8:	44817000 */ 	mtc1	$at,$f14
.L0f1589cc:
/*  f1589cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1589d0:	46007406 */ 	mov.s	$f16,$f14
.L0f1589d4:
/*  f1589d4:	c4e2001c */ 	lwc1	$f2,0x1c($a3)
/*  f1589d8:	4602603c */ 	c.lt.s	$f12,$f2
/*  f1589dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1589e0:	45020083 */ 	bc1fl	.L0f158bf0
/*  f1589e4:	46026201 */ 	sub.s	$f8,$f12,$f2
/*  f1589e8:	46026003 */ 	div.s	$f0,$f12,$f2
/*  f1589ec:	3c017f1b */ 	lui	$at,%hi(var7f1b75b4)
/*  f1589f0:	c42475b4 */ 	lwc1	$f4,%lo(var7f1b75b4)($at)
/*  f1589f4:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f1589f8:	e7b00024 */ 	swc1	$f16,0x24($sp)
/*  f1589fc:	46007201 */ 	sub.s	$f8,$f14,$f0
/*  f158a00:	46044302 */ 	mul.s	$f12,$f8,$f4
/*  f158a04:	0c0068f7 */ 	jal	sinf
/*  f158a08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158a0c:	3c01437f */ 	lui	$at,0x437f
/*  f158a10:	44811000 */ 	mtc1	$at,$f2
/*  f158a14:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f158a18:	3c013f80 */ 	lui	$at,0x3f80
/*  f158a1c:	46020182 */ 	mul.s	$f6,$f0,$f2
/*  f158a20:	44817000 */ 	mtc1	$at,$f14
/*  f158a24:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f158a28:	c7b00024 */ 	lwc1	$f16,0x24($sp)
/*  f158a2c:	3c014f00 */ 	lui	$at,0x4f00
/*  f158a30:	444df800 */ 	cfc1	$t5,$31
/*  f158a34:	44cef800 */ 	ctc1	$t6,$31
/*  f158a38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158a3c:	460034a4 */ 	cvt.w.s	$f18,$f6
/*  f158a40:	444ef800 */ 	cfc1	$t6,$31
/*  f158a44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158a48:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f158a4c:	51c00013 */ 	beqzl	$t6,.L0f158a9c
/*  f158a50:	440e9000 */ 	mfc1	$t6,$f18
/*  f158a54:	44819000 */ 	mtc1	$at,$f18
/*  f158a58:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f158a5c:	46123481 */ 	sub.s	$f18,$f6,$f18
/*  f158a60:	44cef800 */ 	ctc1	$t6,$31
/*  f158a64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158a68:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f158a6c:	444ef800 */ 	cfc1	$t6,$31
/*  f158a70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158a74:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f158a78:	15c00005 */ 	bnez	$t6,.L0f158a90
/*  f158a7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158a80:	440e9000 */ 	mfc1	$t6,$f18
/*  f158a84:	3c018000 */ 	lui	$at,0x8000
/*  f158a88:	10000007 */ 	beqz	$zero,.L0f158aa8
/*  f158a8c:	01c17025 */ 	or	$t6,$t6,$at
.L0f158a90:
/*  f158a90:	10000005 */ 	beqz	$zero,.L0f158aa8
/*  f158a94:	240effff */ 	addiu	$t6,$zero,-1
/*  f158a98:	440e9000 */ 	mfc1	$t6,$f18
.L0f158a9c:
/*  f158a9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158aa0:	05c0fffb */ 	bltz	$t6,.L0f158a90
/*  f158aa4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f158aa8:
/*  f158aa8:	44cdf800 */ 	ctc1	$t5,$31
/*  f158aac:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f158ab0:	904f0251 */ 	lbu	$t7,0x251($v0)
/*  f158ab4:	46007281 */ 	sub.s	$f10,$f14,$f0
/*  f158ab8:	3c014f00 */ 	lui	$at,0x4f00
/*  f158abc:	01eec004 */ 	sllv	$t8,$t6,$t7
/*  f158ac0:	8faf0040 */ 	lw	$t7,0x40($sp)
/*  f158ac4:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f158ac8:	4459f800 */ 	cfc1	$t9,$31
/*  f158acc:	44c8f800 */ 	ctc1	$t0,$31
/*  f158ad0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158ad4:	46004124 */ 	cvt.w.s	$f4,$f8
/*  f158ad8:	4448f800 */ 	cfc1	$t0,$31
/*  f158adc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158ae0:	31080078 */ 	andi	$t0,$t0,0x78
/*  f158ae4:	51000013 */ 	beqzl	$t0,.L0f158b34
/*  f158ae8:	44082000 */ 	mfc1	$t0,$f4
/*  f158aec:	44812000 */ 	mtc1	$at,$f4
/*  f158af0:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f158af4:	46044101 */ 	sub.s	$f4,$f8,$f4
/*  f158af8:	44c8f800 */ 	ctc1	$t0,$31
/*  f158afc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158b00:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f158b04:	4448f800 */ 	cfc1	$t0,$31
/*  f158b08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158b0c:	31080078 */ 	andi	$t0,$t0,0x78
/*  f158b10:	15000005 */ 	bnez	$t0,.L0f158b28
/*  f158b14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158b18:	44082000 */ 	mfc1	$t0,$f4
/*  f158b1c:	3c018000 */ 	lui	$at,0x8000
/*  f158b20:	10000007 */ 	beqz	$zero,.L0f158b40
/*  f158b24:	01014025 */ 	or	$t0,$t0,$at
.L0f158b28:
/*  f158b28:	10000005 */ 	beqz	$zero,.L0f158b40
/*  f158b2c:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f158b30:	44082000 */ 	mfc1	$t0,$f4
.L0f158b34:
/*  f158b34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158b38:	0500fffb */ 	bltz	$t0,.L0f158b28
/*  f158b3c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f158b40:
/*  f158b40:	3c014300 */ 	lui	$at,0x4300
/*  f158b44:	44d9f800 */ 	ctc1	$t9,$31
/*  f158b48:	44813000 */ 	mtc1	$at,$f6
/*  f158b4c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f158b50:	90490252 */ 	lbu	$t1,0x252($v0)
/*  f158b54:	46068482 */ 	mul.s	$f18,$f16,$f6
/*  f158b58:	3c014f00 */ 	lui	$at,0x4f00
/*  f158b5c:	01285004 */ 	sllv	$t2,$t0,$t1
/*  f158b60:	030a5825 */ 	or	$t3,$t8,$t2
/*  f158b64:	444cf800 */ 	cfc1	$t4,$31
/*  f158b68:	44cdf800 */ 	ctc1	$t5,$31
/*  f158b6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158b70:	460092a4 */ 	cvt.w.s	$f10,$f18
/*  f158b74:	444df800 */ 	cfc1	$t5,$31
/*  f158b78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158b7c:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f158b80:	51a00013 */ 	beqzl	$t5,.L0f158bd0
/*  f158b84:	440d5000 */ 	mfc1	$t5,$f10
/*  f158b88:	44815000 */ 	mtc1	$at,$f10
/*  f158b8c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f158b90:	460a9281 */ 	sub.s	$f10,$f18,$f10
/*  f158b94:	44cdf800 */ 	ctc1	$t5,$31
/*  f158b98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158b9c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f158ba0:	444df800 */ 	cfc1	$t5,$31
/*  f158ba4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158ba8:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f158bac:	15a00005 */ 	bnez	$t5,.L0f158bc4
/*  f158bb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158bb4:	440d5000 */ 	mfc1	$t5,$f10
/*  f158bb8:	3c018000 */ 	lui	$at,0x8000
/*  f158bbc:	10000007 */ 	beqz	$zero,.L0f158bdc
/*  f158bc0:	01a16825 */ 	or	$t5,$t5,$at
.L0f158bc4:
/*  f158bc4:	10000005 */ 	beqz	$zero,.L0f158bdc
/*  f158bc8:	240dffff */ 	addiu	$t5,$zero,-1
/*  f158bcc:	440d5000 */ 	mfc1	$t5,$f10
.L0f158bd0:
/*  f158bd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158bd4:	05a0fffb */ 	bltz	$t5,.L0f158bc4
/*  f158bd8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f158bdc:
/*  f158bdc:	44ccf800 */ 	ctc1	$t4,$31
/*  f158be0:	016d7025 */ 	or	$t6,$t3,$t5
/*  f158be4:	10000063 */ 	beqz	$zero,.L0f158d74
/*  f158be8:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f158bec:	46026201 */ 	sub.s	$f8,$f12,$f2
.L0f158bf0:
/*  f158bf0:	3c017f1b */ 	lui	$at,%hi(var7f1b75b8)
/*  f158bf4:	c42675b8 */ 	lwc1	$f6,%lo(var7f1b75b8)($at)
/*  f158bf8:	46027101 */ 	sub.s	$f4,$f14,$f2
/*  f158bfc:	3c017f1b */ 	lui	$at,%hi(var7f1b75bc)
/*  f158c00:	c42a75bc */ 	lwc1	$f10,%lo(var7f1b75bc)($at)
/*  f158c04:	3c017f1b */ 	lui	$at,%hi(var7f1b75c0)
/*  f158c08:	46044003 */ 	div.s	$f0,$f8,$f4
/*  f158c0c:	c42875c0 */ 	lwc1	$f8,%lo(var7f1b75c0)($at)
/*  f158c10:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f158c14:	e7b00024 */ 	swc1	$f16,0x24($sp)
/*  f158c18:	46003482 */ 	mul.s	$f18,$f6,$f0
/*  f158c1c:	460a9000 */ 	add.s	$f0,$f18,$f10
/*  f158c20:	46080302 */ 	mul.s	$f12,$f0,$f8
/*  f158c24:	0c0068f7 */ 	jal	sinf
/*  f158c28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158c2c:	3c01437f */ 	lui	$at,0x437f
/*  f158c30:	44811000 */ 	mtc1	$at,$f2
/*  f158c34:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f158c38:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f158c3c:	46020102 */ 	mul.s	$f4,$f0,$f2
/*  f158c40:	c7b00024 */ 	lwc1	$f16,0x24($sp)
/*  f158c44:	3c014f00 */ 	lui	$at,0x4f00
/*  f158c48:	4459f800 */ 	cfc1	$t9,$31
/*  f158c4c:	44c8f800 */ 	ctc1	$t0,$31
/*  f158c50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158c54:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f158c58:	4448f800 */ 	cfc1	$t0,$31
/*  f158c5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158c60:	31080078 */ 	andi	$t0,$t0,0x78
/*  f158c64:	51000013 */ 	beqzl	$t0,.L0f158cb4
/*  f158c68:	44083000 */ 	mfc1	$t0,$f6
/*  f158c6c:	44813000 */ 	mtc1	$at,$f6
/*  f158c70:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f158c74:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f158c78:	44c8f800 */ 	ctc1	$t0,$31
/*  f158c7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158c80:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f158c84:	4448f800 */ 	cfc1	$t0,$31
/*  f158c88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158c8c:	31080078 */ 	andi	$t0,$t0,0x78
/*  f158c90:	15000005 */ 	bnez	$t0,.L0f158ca8
/*  f158c94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158c98:	44083000 */ 	mfc1	$t0,$f6
/*  f158c9c:	3c018000 */ 	lui	$at,0x8000
/*  f158ca0:	10000007 */ 	beqz	$zero,.L0f158cc0
/*  f158ca4:	01014025 */ 	or	$t0,$t0,$at
.L0f158ca8:
/*  f158ca8:	10000005 */ 	beqz	$zero,.L0f158cc0
/*  f158cac:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f158cb0:	44083000 */ 	mfc1	$t0,$f6
.L0f158cb4:
/*  f158cb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158cb8:	0500fffb */ 	bltz	$t0,.L0f158ca8
/*  f158cbc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f158cc0:
/*  f158cc0:	3c014300 */ 	lui	$at,0x4300
/*  f158cc4:	44d9f800 */ 	ctc1	$t9,$31
/*  f158cc8:	44819000 */ 	mtc1	$at,$f18
/*  f158ccc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f158cd0:	90490253 */ 	lbu	$t1,0x253($v0)
/*  f158cd4:	46128282 */ 	mul.s	$f10,$f16,$f18
/*  f158cd8:	904a0252 */ 	lbu	$t2,0x252($v0)
/*  f158cdc:	240c00ff */ 	addiu	$t4,$zero,0xff
/*  f158ce0:	0128c004 */ 	sllv	$t8,$t0,$t1
/*  f158ce4:	014c5804 */ 	sllv	$t3,$t4,$t2
/*  f158ce8:	030b6825 */ 	or	$t5,$t8,$t3
/*  f158cec:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f158cf0:	444ef800 */ 	cfc1	$t6,$31
/*  f158cf4:	44cff800 */ 	ctc1	$t7,$31
/*  f158cf8:	3c014f00 */ 	lui	$at,0x4f00
/*  f158cfc:	46005224 */ 	cvt.w.s	$f8,$f10
/*  f158d00:	444ff800 */ 	cfc1	$t7,$31
/*  f158d04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158d08:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f158d0c:	51e00013 */ 	beqzl	$t7,.L0f158d5c
/*  f158d10:	440f4000 */ 	mfc1	$t7,$f8
/*  f158d14:	44814000 */ 	mtc1	$at,$f8
/*  f158d18:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f158d1c:	46085201 */ 	sub.s	$f8,$f10,$f8
/*  f158d20:	44cff800 */ 	ctc1	$t7,$31
/*  f158d24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158d28:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f158d2c:	444ff800 */ 	cfc1	$t7,$31
/*  f158d30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158d34:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f158d38:	15e00005 */ 	bnez	$t7,.L0f158d50
/*  f158d3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158d40:	440f4000 */ 	mfc1	$t7,$f8
/*  f158d44:	3c018000 */ 	lui	$at,0x8000
/*  f158d48:	10000007 */ 	beqz	$zero,.L0f158d68
/*  f158d4c:	01e17825 */ 	or	$t7,$t7,$at
.L0f158d50:
/*  f158d50:	10000005 */ 	beqz	$zero,.L0f158d68
/*  f158d54:	240fffff */ 	addiu	$t7,$zero,-1
/*  f158d58:	440f4000 */ 	mfc1	$t7,$f8
.L0f158d5c:
/*  f158d5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158d60:	05e0fffb */ 	bltz	$t7,.L0f158d50
/*  f158d64:	00000000 */ 	sll	$zero,$zero,0x0
.L0f158d68:
/*  f158d68:	44cef800 */ 	ctc1	$t6,$31
/*  f158d6c:	01afc825 */ 	or	$t9,$t5,$t7
/*  f158d70:	ad190000 */ 	sw	$t9,0x0($t0)
.L0f158d74:
/*  f158d74:	8fa90038 */ 	lw	$t1,0x38($sp)
.L0f158d78:
/*  f158d78:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f158d7c:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f158d80:	15800002 */ 	bnez	$t4,.L0f158d8c
/*  f158d84:	340aff00 */ 	dli	$t2,0xff00
/*  f158d88:	af0a0000 */ 	sw	$t2,0x0($t8)
.L0f158d8c:
/*  f158d8c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f158d90:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f158d94:	03e00008 */ 	jr	$ra
/*  f158d98:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f158d9c
/*  f158d9c:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f158da0:	3c0f8008 */ 	lui	$t7,%hi(var8007fc4c)
/*  f158da4:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f158da8:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f158dac:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f158db0:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f158db4:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f158db8:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*  f158dbc:	25effc4c */ 	addiu	$t7,$t7,%lo(var8007fc4c)
/*  f158dc0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f158dc4:	27ae009c */ 	addiu	$t6,$sp,0x9c
/*  f158dc8:	00a08025 */ 	or	$s0,$a1,$zero
/*  f158dcc:	adc10000 */ 	sw	$at,0x0($t6)
/*  f158dd0:	95e10004 */ 	lhu	$at,0x4($t7)
/*  f158dd4:	00e08825 */ 	or	$s1,$a3,$zero
/*  f158dd8:	00c09025 */ 	or	$s2,$a2,$zero
/*  f158ddc:	a5c10004 */ 	sh	$at,0x4($t6)
/*  f158de0:	8cac0020 */ 	lw	$t4,0x20($a1)
/*  f158de4:	240affff */ 	addiu	$t2,$zero,-1
/*  f158de8:	00004025 */ 	or	$t0,$zero,$zero
/*  f158dec:	198000c7 */ 	blez	$t4,.L0f15910c
/*  f158df0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158df4:	84ed0000 */ 	lh	$t5,0x0($a3)
/*  f158df8:	84d90000 */ 	lh	$t9,0x0($a2)
/*  f158dfc:	27a40078 */ 	addiu	$a0,$sp,0x78
/*  f158e00:	01b9c023 */ 	subu	$t8,$t5,$t9
/*  f158e04:	afb800a4 */ 	sw	$t8,0xa4($sp)
/*  f158e08:	84cf0002 */ 	lh	$t7,0x2($a2)
/*  f158e0c:	84ee0002 */ 	lh	$t6,0x2($a3)
/*  f158e10:	01cf5823 */ 	subu	$t3,$t6,$t7
/*  f158e14:	afab00a8 */ 	sw	$t3,0xa8($sp)
/*  f158e18:	84cd0004 */ 	lh	$t5,0x4($a2)
/*  f158e1c:	84ec0004 */ 	lh	$t4,0x4($a3)
/*  f158e20:	8faf00a4 */ 	lw	$t7,0xa4($sp)
/*  f158e24:	018dc823 */ 	subu	$t9,$t4,$t5
/*  f158e28:	03390019 */ 	multu	$t9,$t9
/*  f158e2c:	8fad00a8 */ 	lw	$t5,0xa8($sp)
/*  f158e30:	afb900ac */ 	sw	$t9,0xac($sp)
/*  f158e34:	8cb80024 */ 	lw	$t8,0x24($a1)
/*  f158e38:	00007012 */ 	mflo	$t6
/*  f158e3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158e40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158e44:	01ef0019 */ 	multu	$t7,$t7
/*  f158e48:	00005812 */ 	mflo	$t3
/*  f158e4c:	01cb6021 */ 	addu	$t4,$t6,$t3
/*  f158e50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158e54:	01ad0019 */ 	multu	$t5,$t5
/*  f158e58:	0000c812 */ 	mflo	$t9
/*  f158e5c:	01991021 */ 	addu	$v0,$t4,$t9
/*  f158e60:	0302082a */ 	slt	$at,$t8,$v0
/*  f158e64:	50200025 */ 	beqzl	$at,.L0f158efc
/*  f158e68:	8fb300c0 */ 	lw	$s3,0xc0($sp)
/*  f158e6c:	84cf0000 */ 	lh	$t7,0x0($a2)
/*  f158e70:	84ee0000 */ 	lh	$t6,0x0($a3)
/*  f158e74:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f158e78:	02003825 */ 	or	$a3,$s0,$zero
/*  f158e7c:	01ee5821 */ 	addu	$t3,$t7,$t6
/*  f158e80:	05610003 */ 	bgez	$t3,.L0f158e90
/*  f158e84:	000b6843 */ 	sra	$t5,$t3,0x1
/*  f158e88:	25610001 */ 	addiu	$at,$t3,0x1
/*  f158e8c:	00016843 */ 	sra	$t5,$at,0x1
.L0f158e90:
/*  f158e90:	a7ad0084 */ 	sh	$t5,0x84($sp)
/*  f158e94:	86390002 */ 	lh	$t9,0x2($s1)
/*  f158e98:	864c0002 */ 	lh	$t4,0x2($s2)
/*  f158e9c:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*  f158ea0:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f158ea4:	0199c021 */ 	addu	$t8,$t4,$t9
/*  f158ea8:	07010003 */ 	bgez	$t8,.L0f158eb8
/*  f158eac:	00187843 */ 	sra	$t7,$t8,0x1
/*  f158eb0:	27010001 */ 	addiu	$at,$t8,0x1
/*  f158eb4:	00017843 */ 	sra	$t7,$at,0x1
.L0f158eb8:
/*  f158eb8:	a7af0086 */ 	sh	$t7,0x86($sp)
/*  f158ebc:	862b0004 */ 	lh	$t3,0x4($s1)
/*  f158ec0:	864e0004 */ 	lh	$t6,0x4($s2)
/*  f158ec4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f158ec8:	a7b9009c */ 	sh	$t9,0x9c($sp)
/*  f158ecc:	01cb6821 */ 	addu	$t5,$t6,$t3
/*  f158ed0:	05a10003 */ 	bgez	$t5,.L0f158ee0
/*  f158ed4:	000d6043 */ 	sra	$t4,$t5,0x1
/*  f158ed8:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f158edc:	00016043 */ 	sra	$t4,$at,0x1
.L0f158ee0:
/*  f158ee0:	a7ac0088 */ 	sh	$t4,0x88($sp)
/*  f158ee4:	afa00068 */ 	sw	$zero,0x68($sp)
/*  f158ee8:	0fc56221 */ 	jal	func0f158884
/*  f158eec:	afa80064 */ 	sw	$t0,0x64($sp)
/*  f158ef0:	8fa80064 */ 	lw	$t0,0x64($sp)
/*  f158ef4:	8faa0068 */ 	lw	$t2,0x68($sp)
/*  f158ef8:	8fb300c0 */ 	lw	$s3,0xc0($sp)
.L0f158efc:
/*  f158efc:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f158f00:	27a4007c */ 	addiu	$a0,$sp,0x7c
/*  f158f04:	86780000 */ 	lh	$t8,0x0($s3)
/*  f158f08:	27a5008a */ 	addiu	$a1,$sp,0x8a
/*  f158f0c:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f158f10:	afae00a4 */ 	sw	$t6,0xa4($sp)
/*  f158f14:	862d0002 */ 	lh	$t5,0x2($s1)
/*  f158f18:	866b0002 */ 	lh	$t3,0x2($s3)
/*  f158f1c:	016d6023 */ 	subu	$t4,$t3,$t5
/*  f158f20:	afac00a8 */ 	sw	$t4,0xa8($sp)
/*  f158f24:	86380004 */ 	lh	$t8,0x4($s1)
/*  f158f28:	86790004 */ 	lh	$t9,0x4($s3)
/*  f158f2c:	8fad00a4 */ 	lw	$t5,0xa4($sp)
/*  f158f30:	03387823 */ 	subu	$t7,$t9,$t8
/*  f158f34:	01ef0019 */ 	multu	$t7,$t7
/*  f158f38:	8fb800a8 */ 	lw	$t8,0xa8($sp)
/*  f158f3c:	afaf00ac */ 	sw	$t7,0xac($sp)
/*  f158f40:	8e0e0024 */ 	lw	$t6,0x24($s0)
/*  f158f44:	00005812 */ 	mflo	$t3
/*  f158f48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158f4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158f50:	01ad0019 */ 	multu	$t5,$t5
/*  f158f54:	00006012 */ 	mflo	$t4
/*  f158f58:	016cc821 */ 	addu	$t9,$t3,$t4
/*  f158f5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f158f60:	03180019 */ 	multu	$t8,$t8
/*  f158f64:	00007812 */ 	mflo	$t7
/*  f158f68:	032f1021 */ 	addu	$v0,$t9,$t7
/*  f158f6c:	01c2082a */ 	slt	$at,$t6,$v0
/*  f158f70:	50200025 */ 	beqzl	$at,.L0f159008
/*  f158f74:	864e0000 */ 	lh	$t6,0x0($s2)
/*  f158f78:	862d0000 */ 	lh	$t5,0x0($s1)
/*  f158f7c:	866b0000 */ 	lh	$t3,0x0($s3)
/*  f158f80:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f158f84:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f158f88:	01ab6021 */ 	addu	$t4,$t5,$t3
/*  f158f8c:	05810003 */ 	bgez	$t4,.L0f158f9c
/*  f158f90:	000cc043 */ 	sra	$t8,$t4,0x1
/*  f158f94:	25810001 */ 	addiu	$at,$t4,0x1
/*  f158f98:	0001c043 */ 	sra	$t8,$at,0x1
.L0f158f9c:
/*  f158f9c:	a7b8008a */ 	sh	$t8,0x8a($sp)
/*  f158fa0:	866f0002 */ 	lh	$t7,0x2($s3)
/*  f158fa4:	86390002 */ 	lh	$t9,0x2($s1)
/*  f158fa8:	27a60070 */ 	addiu	$a2,$sp,0x70
/*  f158fac:	02003825 */ 	or	$a3,$s0,$zero
/*  f158fb0:	032f7021 */ 	addu	$t6,$t9,$t7
/*  f158fb4:	05c10003 */ 	bgez	$t6,.L0f158fc4
/*  f158fb8:	000e6843 */ 	sra	$t5,$t6,0x1
/*  f158fbc:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f158fc0:	00016843 */ 	sra	$t5,$at,0x1
.L0f158fc4:
/*  f158fc4:	a7ad008c */ 	sh	$t5,0x8c($sp)
/*  f158fc8:	866c0004 */ 	lh	$t4,0x4($s3)
/*  f158fcc:	862b0004 */ 	lh	$t3,0x4($s1)
/*  f158fd0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f158fd4:	a7af009e */ 	sh	$t7,0x9e($sp)
/*  f158fd8:	016cc021 */ 	addu	$t8,$t3,$t4
/*  f158fdc:	07010003 */ 	bgez	$t8,.L0f158fec
/*  f158fe0:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f158fe4:	27010001 */ 	addiu	$at,$t8,0x1
/*  f158fe8:	0001c843 */ 	sra	$t9,$at,0x1
.L0f158fec:
/*  f158fec:	a7b9008e */ 	sh	$t9,0x8e($sp)
/*  f158ff0:	afaa0068 */ 	sw	$t2,0x68($sp)
/*  f158ff4:	0fc56221 */ 	jal	func0f158884
/*  f158ff8:	afa80064 */ 	sw	$t0,0x64($sp)
/*  f158ffc:	8fa80064 */ 	lw	$t0,0x64($sp)
/*  f159000:	8faa0068 */ 	lw	$t2,0x68($sp)
/*  f159004:	864e0000 */ 	lh	$t6,0x0($s2)
.L0f159008:
/*  f159008:	866d0000 */ 	lh	$t5,0x0($s3)
/*  f15900c:	27a40080 */ 	addiu	$a0,$sp,0x80
/*  f159010:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f159014:	01cd5823 */ 	subu	$t3,$t6,$t5
/*  f159018:	afab00a4 */ 	sw	$t3,0xa4($sp)
/*  f15901c:	86780002 */ 	lh	$t8,0x2($s3)
/*  f159020:	864c0002 */ 	lh	$t4,0x2($s2)
/*  f159024:	0198c823 */ 	subu	$t9,$t4,$t8
/*  f159028:	afb900a8 */ 	sw	$t9,0xa8($sp)
/*  f15902c:	866e0004 */ 	lh	$t6,0x4($s3)
/*  f159030:	864f0004 */ 	lh	$t7,0x4($s2)
/*  f159034:	8fb800a4 */ 	lw	$t8,0xa4($sp)
/*  f159038:	01ee6823 */ 	subu	$t5,$t7,$t6
/*  f15903c:	01ad0019 */ 	multu	$t5,$t5
/*  f159040:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f159044:	afad00ac */ 	sw	$t5,0xac($sp)
/*  f159048:	8e0b0024 */ 	lw	$t3,0x24($s0)
/*  f15904c:	00006012 */ 	mflo	$t4
/*  f159050:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159054:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159058:	03180019 */ 	multu	$t8,$t8
/*  f15905c:	0000c812 */ 	mflo	$t9
/*  f159060:	01997821 */ 	addu	$t7,$t4,$t9
/*  f159064:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159068:	01ce0019 */ 	multu	$t6,$t6
/*  f15906c:	00006812 */ 	mflo	$t5
/*  f159070:	01ed1021 */ 	addu	$v0,$t7,$t5
/*  f159074:	0162082a */ 	slt	$at,$t3,$v0
/*  f159078:	10200024 */ 	beqz	$at,.L0f15910c
/*  f15907c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159080:	86780000 */ 	lh	$t8,0x0($s3)
/*  f159084:	864c0000 */ 	lh	$t4,0x0($s2)
/*  f159088:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f15908c:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f159090:	030cc821 */ 	addu	$t9,$t8,$t4
/*  f159094:	07210003 */ 	bgez	$t9,.L0f1590a4
/*  f159098:	00197043 */ 	sra	$t6,$t9,0x1
/*  f15909c:	27210001 */ 	addiu	$at,$t9,0x1
/*  f1590a0:	00017043 */ 	sra	$t6,$at,0x1
.L0f1590a4:
/*  f1590a4:	a7ae0090 */ 	sh	$t6,0x90($sp)
/*  f1590a8:	864d0002 */ 	lh	$t5,0x2($s2)
/*  f1590ac:	866f0002 */ 	lh	$t7,0x2($s3)
/*  f1590b0:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f1590b4:	02003825 */ 	or	$a3,$s0,$zero
/*  f1590b8:	01ed5821 */ 	addu	$t3,$t7,$t5
/*  f1590bc:	05610003 */ 	bgez	$t3,.L0f1590cc
/*  f1590c0:	000bc043 */ 	sra	$t8,$t3,0x1
/*  f1590c4:	25610001 */ 	addiu	$at,$t3,0x1
/*  f1590c8:	0001c043 */ 	sra	$t8,$at,0x1
.L0f1590cc:
/*  f1590cc:	a7b80092 */ 	sh	$t8,0x92($sp)
/*  f1590d0:	86590004 */ 	lh	$t9,0x4($s2)
/*  f1590d4:	866c0004 */ 	lh	$t4,0x4($s3)
/*  f1590d8:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1590dc:	a7ad00a0 */ 	sh	$t5,0xa0($sp)
/*  f1590e0:	01997021 */ 	addu	$t6,$t4,$t9
/*  f1590e4:	05c10003 */ 	bgez	$t6,.L0f1590f4
/*  f1590e8:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f1590ec:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f1590f0:	00017843 */ 	sra	$t7,$at,0x1
.L0f1590f4:
/*  f1590f4:	a7af0094 */ 	sh	$t7,0x94($sp)
/*  f1590f8:	afaa0068 */ 	sw	$t2,0x68($sp)
/*  f1590fc:	0fc56221 */ 	jal	func0f158884
/*  f159100:	afa80064 */ 	sw	$t0,0x64($sp)
/*  f159104:	8fa80064 */ 	lw	$t0,0x64($sp)
/*  f159108:	8faa0068 */ 	lw	$t2,0x68($sp)
.L0f15910c:
/*  f15910c:	15000016 */ 	bnez	$t0,.L0f159168
/*  f159110:	8fb300c0 */ 	lw	$s3,0xc0($sp)
/*  f159114:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*  f159118:	8fab00d4 */ 	lw	$t3,0xd4($sp)
/*  f15911c:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f159120:	15200005 */ 	bnez	$t1,.L0f159138
/*  f159124:	02002825 */ 	or	$a1,$s0,$zero
/*  f159128:	15600003 */ 	bnez	$t3,.L0f159138
/*  f15912c:	8fb800d8 */ 	lw	$t8,0xd8($sp)
/*  f159130:	530001d9 */ 	beqzl	$t8,.L0f159898
/*  f159134:	8fa200b0 */ 	lw	$v0,0xb0($sp)
.L0f159138:
/*  f159138:	8fac00c4 */ 	lw	$t4,0xc4($sp)
/*  f15913c:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*  f159140:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*  f159144:	02403025 */ 	or	$a2,$s2,$zero
/*  f159148:	02203825 */ 	or	$a3,$s1,$zero
/*  f15914c:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f159150:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f159154:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f159158:	0fc56100 */ 	jal	func0f158400
/*  f15915c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f159160:	100001ce */ 	beqz	$zero,.L0f15989c
/*  f159164:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f159168:
/*  f159168:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*  f15916c:	8faf00d4 */ 	lw	$t7,0xd4($sp)
/*  f159170:	15200005 */ 	bnez	$t1,.L0f159188
/*  f159174:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159178:	15e00003 */ 	bnez	$t7,.L0f159188
/*  f15917c:	8fad00d8 */ 	lw	$t5,0xd8($sp)
/*  f159180:	51a00004 */ 	beqzl	$t5,.L0f159194
/*  f159184:	8e040000 */ 	lw	$a0,0x0($s0)
.L0f159188:
/*  f159188:	10000042 */ 	beqz	$zero,.L0f159294
/*  f15918c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f159190:	8e040000 */ 	lw	$a0,0x0($s0)
.L0f159194:
/*  f159194:	864b0000 */ 	lh	$t3,0x0($s2)
/*  f159198:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f15919c:	00001825 */ 	or	$v1,$zero,$zero
/*  f1591a0:	0164082a */ 	slt	$at,$t3,$a0
/*  f1591a4:	10200003 */ 	beqz	$at,.L0f1591b4
/*  f1591a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1591ac:	10000001 */ 	beqz	$zero,.L0f1591b4
/*  f1591b0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f1591b4:
/*  f1591b4:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f1591b8:	86580002 */ 	lh	$t8,0x2($s2)
/*  f1591bc:	346c0002 */ 	ori	$t4,$v1,0x2
/*  f1591c0:	0305082a */ 	slt	$at,$t8,$a1
/*  f1591c4:	50200003 */ 	beqzl	$at,.L0f1591d4
/*  f1591c8:	8e060008 */ 	lw	$a2,0x8($s0)
/*  f1591cc:	01801825 */ 	or	$v1,$t4,$zero
/*  f1591d0:	8e060008 */ 	lw	$a2,0x8($s0)
.L0f1591d4:
/*  f1591d4:	86590004 */ 	lh	$t9,0x4($s2)
/*  f1591d8:	346e0004 */ 	ori	$t6,$v1,0x4
/*  f1591dc:	0326082a */ 	slt	$at,$t9,$a2
/*  f1591e0:	50200003 */ 	beqzl	$at,.L0f1591f0
/*  f1591e4:	862f0000 */ 	lh	$t7,0x0($s1)
/*  f1591e8:	01c01825 */ 	or	$v1,$t6,$zero
/*  f1591ec:	862f0000 */ 	lh	$t7,0x0($s1)
.L0f1591f0:
/*  f1591f0:	01e4082a */ 	slt	$at,$t7,$a0
/*  f1591f4:	10200003 */ 	beqz	$at,.L0f159204
/*  f1591f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1591fc:	10000001 */ 	beqz	$zero,.L0f159204
/*  f159200:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f159204:
/*  f159204:	862d0002 */ 	lh	$t5,0x2($s1)
/*  f159208:	344b0002 */ 	ori	$t3,$v0,0x2
/*  f15920c:	01a5082a */ 	slt	$at,$t5,$a1
/*  f159210:	50200003 */ 	beqzl	$at,.L0f159220
/*  f159214:	86380004 */ 	lh	$t8,0x4($s1)
/*  f159218:	01601025 */ 	or	$v0,$t3,$zero
/*  f15921c:	86380004 */ 	lh	$t8,0x4($s1)
.L0f159220:
/*  f159220:	344c0004 */ 	ori	$t4,$v0,0x4
/*  f159224:	0306082a */ 	slt	$at,$t8,$a2
/*  f159228:	10200002 */ 	beqz	$at,.L0f159234
/*  f15922c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159230:	01801025 */ 	or	$v0,$t4,$zero
.L0f159234:
/*  f159234:	14620017 */ 	bne	$v1,$v0,.L0f159294
/*  f159238:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15923c:	86790000 */ 	lh	$t9,0x0($s3)
/*  f159240:	00001025 */ 	or	$v0,$zero,$zero
/*  f159244:	0324082a */ 	slt	$at,$t9,$a0
/*  f159248:	10200003 */ 	beqz	$at,.L0f159258
/*  f15924c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159250:	10000001 */ 	beqz	$zero,.L0f159258
/*  f159254:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f159258:
/*  f159258:	866e0002 */ 	lh	$t6,0x2($s3)
/*  f15925c:	344f0002 */ 	ori	$t7,$v0,0x2
/*  f159260:	01c5082a */ 	slt	$at,$t6,$a1
/*  f159264:	50200003 */ 	beqzl	$at,.L0f159274
/*  f159268:	866d0004 */ 	lh	$t5,0x4($s3)
/*  f15926c:	01e01025 */ 	or	$v0,$t7,$zero
/*  f159270:	866d0004 */ 	lh	$t5,0x4($s3)
.L0f159274:
/*  f159274:	344b0004 */ 	ori	$t3,$v0,0x4
/*  f159278:	01a6082a */ 	slt	$at,$t5,$a2
/*  f15927c:	10200002 */ 	beqz	$at,.L0f159288
/*  f159280:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159284:	01601025 */ 	or	$v0,$t3,$zero
.L0f159288:
/*  f159288:	14620002 */ 	bne	$v1,$v0,.L0f159294
/*  f15928c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159290:	00003825 */ 	or	$a3,$zero,$zero
.L0f159294:
/*  f159294:	10e0017f */ 	beqz	$a3,.L0f159894
/*  f159298:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f15929c:	15030075 */ 	bne	$t0,$v1,.L0f159474
/*  f1592a0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1592a4:	15400025 */ 	bnez	$t2,.L0f15933c
/*  f1592a8:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f1592ac:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f1592b0:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f1592b4:	8fb900cc */ 	lw	$t9,0xcc($sp)
/*  f1592b8:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f1592bc:	8faf00d8 */ 	lw	$t7,0xd8($sp)
/*  f1592c0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1592c4:	02403025 */ 	or	$a2,$s2,$zero
/*  f1592c8:	27a70084 */ 	addiu	$a3,$sp,0x84
/*  f1592cc:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f1592d0:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f1592d4:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1592d8:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f1592dc:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f1592e0:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f1592e4:	0fc56367 */ 	jal	func0f158d9c
/*  f1592e8:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f1592ec:	8fad00cc */ 	lw	$t5,0xcc($sp)
/*  f1592f0:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f1592f4:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*  f1592f8:	8fac00d8 */ 	lw	$t4,0xd8($sp)
/*  f1592fc:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f159300:	8fae00d4 */ 	lw	$t6,0xd4($sp)
/*  f159304:	00402025 */ 	or	$a0,$v0,$zero
/*  f159308:	02002825 */ 	or	$a1,$s0,$zero
/*  f15930c:	02603025 */ 	or	$a2,$s3,$zero
/*  f159310:	27a70084 */ 	addiu	$a3,$sp,0x84
/*  f159314:	afb10010 */ 	sw	$s1,0x10($sp)
/*  f159318:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f15931c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f159320:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f159324:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f159328:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f15932c:	0fc56367 */ 	jal	func0f158d9c
/*  f159330:	afae0028 */ 	sw	$t6,0x28($sp)
/*  f159334:	10000157 */ 	beqz	$zero,.L0f159894
/*  f159338:	afa200b0 */ 	sw	$v0,0xb0($sp)
.L0f15933c:
/*  f15933c:	15430026 */ 	bne	$t2,$v1,.L0f1593d8
/*  f159340:	24010002 */ 	addiu	$at,$zero,0x2
/*  f159344:	8faf00c8 */ 	lw	$t7,0xc8($sp)
/*  f159348:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f15934c:	8fab00c4 */ 	lw	$t3,0xc4($sp)
/*  f159350:	8fb800d4 */ 	lw	$t8,0xd4($sp)
/*  f159354:	8fac007c */ 	lw	$t4,0x7c($sp)
/*  f159358:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f15935c:	02002825 */ 	or	$a1,$s0,$zero
/*  f159360:	02203025 */ 	or	$a2,$s1,$zero
/*  f159364:	27a7008a */ 	addiu	$a3,$sp,0x8a
/*  f159368:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f15936c:	afa90028 */ 	sw	$t1,0x28($sp)
/*  f159370:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f159374:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f159378:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f15937c:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f159380:	0fc56367 */ 	jal	func0f158d9c
/*  f159384:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f159388:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*  f15938c:	8fb900c4 */ 	lw	$t9,0xc4($sp)
/*  f159390:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f159394:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*  f159398:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f15939c:	8fab00d8 */ 	lw	$t3,0xd8($sp)
/*  f1593a0:	00402025 */ 	or	$a0,$v0,$zero
/*  f1593a4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1593a8:	02403025 */ 	or	$a2,$s2,$zero
/*  f1593ac:	27a7008a */ 	addiu	$a3,$sp,0x8a
/*  f1593b0:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f1593b4:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f1593b8:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1593bc:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1593c0:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f1593c4:	afad0024 */ 	sw	$t5,0x24($sp)
/*  f1593c8:	0fc56367 */ 	jal	func0f158d9c
/*  f1593cc:	afab0028 */ 	sw	$t3,0x28($sp)
/*  f1593d0:	10000130 */ 	beqz	$zero,.L0f159894
/*  f1593d4:	afa200b0 */ 	sw	$v0,0xb0($sp)
.L0f1593d8:
/*  f1593d8:	1541012e */ 	bne	$t2,$at,.L0f159894
/*  f1593dc:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f1593e0:	8fb800cc */ 	lw	$t8,0xcc($sp)
/*  f1593e4:	8fac0074 */ 	lw	$t4,0x74($sp)
/*  f1593e8:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*  f1593ec:	8fae00d8 */ 	lw	$t6,0xd8($sp)
/*  f1593f0:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f1593f4:	8fad00d4 */ 	lw	$t5,0xd4($sp)
/*  f1593f8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1593fc:	02603025 */ 	or	$a2,$s3,$zero
/*  f159400:	27a70090 */ 	addiu	$a3,$sp,0x90
/*  f159404:	afb10010 */ 	sw	$s1,0x10($sp)
/*  f159408:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f15940c:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f159410:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f159414:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f159418:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f15941c:	0fc56367 */ 	jal	func0f158d9c
/*  f159420:	afad0028 */ 	sw	$t5,0x28($sp)
/*  f159424:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*  f159428:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*  f15942c:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f159430:	8fac00c4 */ 	lw	$t4,0xc4($sp)
/*  f159434:	8fb900d4 */ 	lw	$t9,0xd4($sp)
/*  f159438:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f15943c:	00402025 */ 	or	$a0,$v0,$zero
/*  f159440:	02002825 */ 	or	$a1,$s0,$zero
/*  f159444:	02203025 */ 	or	$a2,$s1,$zero
/*  f159448:	27a70090 */ 	addiu	$a3,$sp,0x90
/*  f15944c:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f159450:	afa90028 */ 	sw	$t1,0x28($sp)
/*  f159454:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f159458:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f15945c:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f159460:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f159464:	0fc56367 */ 	jal	func0f158d9c
/*  f159468:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f15946c:	10000109 */ 	beqz	$zero,.L0f159894
/*  f159470:	afa200b0 */ 	sw	$v0,0xb0($sp)
.L0f159474:
/*  f159474:	150100b9 */ 	bne	$t0,$at,.L0f15975c
/*  f159478:	87af009e */ 	lh	$t7,0x9e($sp)
/*  f15947c:	15e00002 */ 	bnez	$t7,.L0f159488
/*  f159480:	00001025 */ 	or	$v0,$zero,$zero
/*  f159484:	00601025 */ 	or	$v0,$v1,$zero
.L0f159488:
/*  f159488:	87ad00a0 */ 	lh	$t5,0xa0($sp)
/*  f15948c:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f159490:	02002825 */ 	or	$a1,$s0,$zero
/*  f159494:	15a00002 */ 	bnez	$t5,.L0f1594a0
/*  f159498:	02603025 */ 	or	$a2,$s3,$zero
/*  f15949c:	24020002 */ 	addiu	$v0,$zero,0x2
.L0f1594a0:
/*  f1594a0:	14400038 */ 	bnez	$v0,.L0f159584
/*  f1594a4:	27a70090 */ 	addiu	$a3,$sp,0x90
/*  f1594a8:	8fb800cc */ 	lw	$t8,0xcc($sp)
/*  f1594ac:	8fac0074 */ 	lw	$t4,0x74($sp)
/*  f1594b0:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f1594b4:	8fae00d8 */ 	lw	$t6,0xd8($sp)
/*  f1594b8:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f1594bc:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f1594c0:	27ab008a */ 	addiu	$t3,$sp,0x8a
/*  f1594c4:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f1594c8:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1594cc:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f1594d0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f1594d4:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f1594d8:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f1594dc:	0fc56367 */ 	jal	func0f158d9c
/*  f1594e0:	afad0028 */ 	sw	$t5,0x28($sp)
/*  f1594e4:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*  f1594e8:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f1594ec:	8fb90074 */ 	lw	$t9,0x74($sp)
/*  f1594f0:	8fae00d4 */ 	lw	$t6,0xd4($sp)
/*  f1594f4:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f1594f8:	8fad0080 */ 	lw	$t5,0x80($sp)
/*  f1594fc:	27ab0090 */ 	addiu	$t3,$sp,0x90
/*  f159500:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f159504:	00402025 */ 	or	$a0,$v0,$zero
/*  f159508:	02002825 */ 	or	$a1,$s0,$zero
/*  f15950c:	02203025 */ 	or	$a2,$s1,$zero
/*  f159510:	27a7008a */ 	addiu	$a3,$sp,0x8a
/*  f159514:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f159518:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f15951c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f159520:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f159524:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f159528:	0fc56367 */ 	jal	func0f158d9c
/*  f15952c:	afad0028 */ 	sw	$t5,0x28($sp)
/*  f159530:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*  f159534:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f159538:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*  f15953c:	8fb90074 */ 	lw	$t9,0x74($sp)
/*  f159540:	8fae00d4 */ 	lw	$t6,0xd4($sp)
/*  f159544:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f159548:	27ab0090 */ 	addiu	$t3,$sp,0x90
/*  f15954c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f159550:	00402025 */ 	or	$a0,$v0,$zero
/*  f159554:	02002825 */ 	or	$a1,$s0,$zero
/*  f159558:	02403025 */ 	or	$a2,$s2,$zero
/*  f15955c:	02203825 */ 	or	$a3,$s1,$zero
/*  f159560:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f159564:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f159568:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f15956c:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f159570:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f159574:	0fc56367 */ 	jal	func0f158d9c
/*  f159578:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f15957c:	100000c5 */ 	beqz	$zero,.L0f159894
/*  f159580:	afa200b0 */ 	sw	$v0,0xb0($sp)
.L0f159584:
/*  f159584:	1443003b */ 	bne	$v0,$v1,.L0f159674
/*  f159588:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f15958c:	8fab00c4 */ 	lw	$t3,0xc4($sp)
/*  f159590:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f159594:	8fac0074 */ 	lw	$t4,0x74($sp)
/*  f159598:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f15959c:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f1595a0:	27ad0090 */ 	addiu	$t5,$sp,0x90
/*  f1595a4:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f1595a8:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f1595ac:	02002825 */ 	or	$a1,$s0,$zero
/*  f1595b0:	02403025 */ 	or	$a2,$s2,$zero
/*  f1595b4:	27a70084 */ 	addiu	$a3,$sp,0x84
/*  f1595b8:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f1595bc:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f1595c0:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f1595c4:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f1595c8:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f1595cc:	0fc56367 */ 	jal	func0f158d9c
/*  f1595d0:	afae0028 */ 	sw	$t6,0x28($sp)
/*  f1595d4:	8fad00cc */ 	lw	$t5,0xcc($sp)
/*  f1595d8:	8fab0074 */ 	lw	$t3,0x74($sp)
/*  f1595dc:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f1595e0:	8fac00d8 */ 	lw	$t4,0xd8($sp)
/*  f1595e4:	8fb90080 */ 	lw	$t9,0x80($sp)
/*  f1595e8:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f1595ec:	27af0084 */ 	addiu	$t7,$sp,0x84
/*  f1595f0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1595f4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1595f8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1595fc:	02603025 */ 	or	$a2,$s3,$zero
/*  f159600:	27a70090 */ 	addiu	$a3,$sp,0x90
/*  f159604:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f159608:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f15960c:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f159610:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f159614:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f159618:	0fc56367 */ 	jal	func0f158d9c
/*  f15961c:	afae0028 */ 	sw	$t6,0x28($sp)
/*  f159620:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f159624:	8fab00cc */ 	lw	$t3,0xcc($sp)
/*  f159628:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f15962c:	8fac00d4 */ 	lw	$t4,0xd4($sp)
/*  f159630:	8fb900d8 */ 	lw	$t9,0xd8($sp)
/*  f159634:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f159638:	27af0084 */ 	addiu	$t7,$sp,0x84
/*  f15963c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f159640:	00402025 */ 	or	$a0,$v0,$zero
/*  f159644:	02002825 */ 	or	$a1,$s0,$zero
/*  f159648:	02203025 */ 	or	$a2,$s1,$zero
/*  f15964c:	02603825 */ 	or	$a3,$s3,$zero
/*  f159650:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f159654:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f159658:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f15965c:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f159660:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f159664:	0fc56367 */ 	jal	func0f158d9c
/*  f159668:	afae0028 */ 	sw	$t6,0x28($sp)
/*  f15966c:	10000089 */ 	beqz	$zero,.L0f159894
/*  f159670:	afa200b0 */ 	sw	$v0,0xb0($sp)
.L0f159674:
/*  f159674:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f159678:	8fab0070 */ 	lw	$t3,0x70($sp)
/*  f15967c:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f159680:	8fac00d4 */ 	lw	$t4,0xd4($sp)
/*  f159684:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*  f159688:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f15968c:	27af0084 */ 	addiu	$t7,$sp,0x84
/*  f159690:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f159694:	02002825 */ 	or	$a1,$s0,$zero
/*  f159698:	02203025 */ 	or	$a2,$s1,$zero
/*  f15969c:	27a7008a */ 	addiu	$a3,$sp,0x8a
/*  f1596a0:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f1596a4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1596a8:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f1596ac:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f1596b0:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f1596b4:	0fc56367 */ 	jal	func0f158d9c
/*  f1596b8:	afae0028 */ 	sw	$t6,0x28($sp)
/*  f1596bc:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*  f1596c0:	8fad00c4 */ 	lw	$t5,0xc4($sp)
/*  f1596c4:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f1596c8:	8fb80070 */ 	lw	$t8,0x70($sp)
/*  f1596cc:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f1596d0:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*  f1596d4:	27af008a */ 	addiu	$t7,$sp,0x8a
/*  f1596d8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1596dc:	00402025 */ 	or	$a0,$v0,$zero
/*  f1596e0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1596e4:	02403025 */ 	or	$a2,$s2,$zero
/*  f1596e8:	27a70084 */ 	addiu	$a3,$sp,0x84
/*  f1596ec:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f1596f0:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f1596f4:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1596f8:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f1596fc:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f159700:	0fc56367 */ 	jal	func0f158d9c
/*  f159704:	afb90028 */ 	sw	$t9,0x28($sp)
/*  f159708:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*  f15970c:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*  f159710:	8fad00c4 */ 	lw	$t5,0xc4($sp)
/*  f159714:	8fab0070 */ 	lw	$t3,0x70($sp)
/*  f159718:	8fb800d8 */ 	lw	$t8,0xd8($sp)
/*  f15971c:	8fac007c */ 	lw	$t4,0x7c($sp)
/*  f159720:	27ae008a */ 	addiu	$t6,$sp,0x8a
/*  f159724:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f159728:	00402025 */ 	or	$a0,$v0,$zero
/*  f15972c:	02002825 */ 	or	$a1,$s0,$zero
/*  f159730:	02603025 */ 	or	$a2,$s3,$zero
/*  f159734:	02403825 */ 	or	$a3,$s2,$zero
/*  f159738:	afa90024 */ 	sw	$t1,0x24($sp)
/*  f15973c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f159740:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f159744:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f159748:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f15974c:	0fc56367 */ 	jal	func0f158d9c
/*  f159750:	afac0028 */ 	sw	$t4,0x28($sp)
/*  f159754:	1000004f */ 	beqz	$zero,.L0f159894
/*  f159758:	afa200b0 */ 	sw	$v0,0xb0($sp)
.L0f15975c:
/*  f15975c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f159760:	1501004c */ 	bne	$t0,$at,.L0f159894
/*  f159764:	8fa400b0 */ 	lw	$a0,0xb0($sp)
/*  f159768:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f15976c:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f159770:	8fad0074 */ 	lw	$t5,0x74($sp)
/*  f159774:	8fab0078 */ 	lw	$t3,0x78($sp)
/*  f159778:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f15977c:	27b90090 */ 	addiu	$t9,$sp,0x90
/*  f159780:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f159784:	02002825 */ 	or	$a1,$s0,$zero
/*  f159788:	02403025 */ 	or	$a2,$s2,$zero
/*  f15978c:	27a70084 */ 	addiu	$a3,$sp,0x84
/*  f159790:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f159794:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f159798:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f15979c:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1597a0:	afab0024 */ 	sw	$t3,0x24($sp)
/*  f1597a4:	0fc56367 */ 	jal	func0f158d9c
/*  f1597a8:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f1597ac:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*  f1597b0:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f1597b4:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f1597b8:	8fad00d4 */ 	lw	$t5,0xd4($sp)
/*  f1597bc:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f1597c0:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f1597c4:	27ac0084 */ 	addiu	$t4,$sp,0x84
/*  f1597c8:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1597cc:	00402025 */ 	or	$a0,$v0,$zero
/*  f1597d0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1597d4:	02203025 */ 	or	$a2,$s1,$zero
/*  f1597d8:	27a7008a */ 	addiu	$a3,$sp,0x8a
/*  f1597dc:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1597e0:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f1597e4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f1597e8:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f1597ec:	afab0024 */ 	sw	$t3,0x24($sp)
/*  f1597f0:	0fc56367 */ 	jal	func0f158d9c
/*  f1597f4:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f1597f8:	8fb900cc */ 	lw	$t9,0xcc($sp)
/*  f1597fc:	8fae0074 */ 	lw	$t6,0x74($sp)
/*  f159800:	8faf0070 */ 	lw	$t7,0x70($sp)
/*  f159804:	8fad00d8 */ 	lw	$t5,0xd8($sp)
/*  f159808:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f15980c:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f159810:	27ac008a */ 	addiu	$t4,$sp,0x8a
/*  f159814:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f159818:	00402025 */ 	or	$a0,$v0,$zero
/*  f15981c:	02002825 */ 	or	$a1,$s0,$zero
/*  f159820:	02603025 */ 	or	$a2,$s3,$zero
/*  f159824:	27a70090 */ 	addiu	$a3,$sp,0x90
/*  f159828:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f15982c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f159830:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f159834:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f159838:	afab0024 */ 	sw	$t3,0x24($sp)
/*  f15983c:	0fc56367 */ 	jal	func0f158d9c
/*  f159840:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f159844:	8fb9006c */ 	lw	$t9,0x6c($sp)
/*  f159848:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f15984c:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f159850:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f159854:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f159858:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f15985c:	27ac0090 */ 	addiu	$t4,$sp,0x90
/*  f159860:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f159864:	00402025 */ 	or	$a0,$v0,$zero
/*  f159868:	02002825 */ 	or	$a1,$s0,$zero
/*  f15986c:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f159870:	27a7008a */ 	addiu	$a3,$sp,0x8a
/*  f159874:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f159878:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f15987c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f159880:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f159884:	afab0024 */ 	sw	$t3,0x24($sp)
/*  f159888:	0fc56367 */ 	jal	func0f158d9c
/*  f15988c:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f159890:	afa200b0 */ 	sw	$v0,0xb0($sp)
.L0f159894:
/*  f159894:	8fa200b0 */ 	lw	$v0,0xb0($sp)
.L0f159898:
/*  f159898:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f15989c:
/*  f15989c:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f1598a0:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f1598a4:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f1598a8:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f1598ac:	03e00008 */ 	jr	$ra
/*  f1598b0:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);

GLOBAL_ASM(
glabel func0f1598b4
.late_rodata
glabel var7f1b75c4
.word 0x3f333333
.text
/*  f1598b4:	27bdfc28 */ 	addiu	$sp,$sp,-984
/*  f1598b8:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f1598bc:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f1598c0:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f1598c4:	00e08025 */ 	or	$s0,$a3,$zero
/*  f1598c8:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f1598cc:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f1598d0:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f1598d4:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f1598d8:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f1598dc:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f1598e0:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f1598e4:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f1598e8:	afa403d8 */ 	sw	$a0,0x3d8($sp)
/*  f1598ec:	0fc59570 */ 	jal	stageGetCurrent
/*  f1598f0:	afa603e0 */ 	sw	$a2,0x3e0($sp)
/*  f1598f4:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f1598f8:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f1598fc:	3c017f1b */ 	lui	$at,%hi(var7f1b75c4)
/*  f159900:	c42075c4 */ 	lwc1	$f0,%lo(var7f1b75c4)($at)
/*  f159904:	c4640028 */ 	lwc1	$f4,0x28($v1)
/*  f159908:	3c013e80 */ 	lui	$at,0x3e80
/*  f15990c:	44815000 */ 	mtc1	$at,$f10
/*  f159910:	e7a40190 */ 	swc1	$f4,0x190($sp)
/*  f159914:	c7a60190 */ 	lwc1	$f6,0x190($sp)
/*  f159918:	3c013e80 */ 	lui	$at,0x3e80
/*  f15991c:	46063202 */ 	mul.s	$f8,$f6,$f6
/*  f159920:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159924:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f159928:	44815000 */ 	mtc1	$at,$f10
/*  f15992c:	e7a80194 */ 	swc1	$f8,0x194($sp)
/*  f159930:	e7b0019c */ 	swc1	$f16,0x19c($sp)
/*  f159934:	c4720024 */ 	lwc1	$f18,0x24($v1)
/*  f159938:	46069103 */ 	div.s	$f4,$f18,$f6
/*  f15993c:	e7a401a0 */ 	swc1	$f4,0x1a0($sp)
/*  f159940:	c7a801a0 */ 	lwc1	$f8,0x1a0($sp)
/*  f159944:	4608003c */ 	c.lt.s	$f0,$f8
/*  f159948:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15994c:	45000002 */ 	bc1f	.L0f159958
/*  f159950:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159954:	e7a001a0 */ 	swc1	$f0,0x1a0($sp)
.L0f159958:
/*  f159958:	e7aa0198 */ 	swc1	$f10,0x198($sp)
/*  f15995c:	844e002c */ 	lh	$t6,0x2c($v0)
/*  f159960:	241e0006 */ 	addiu	$s8,$zero,0x6
/*  f159964:	27b70120 */ 	addiu	$s7,$sp,0x120
/*  f159968:	01ce0019 */ 	multu	$t6,$t6
/*  f15996c:	afae01a4 */ 	sw	$t6,0x1a4($sp)
/*  f159970:	0000c012 */ 	mflo	$t8
/*  f159974:	afb801a8 */ 	sw	$t8,0x1a8($sp)
/*  f159978:	86190000 */ 	lh	$t9,0x0($s0)
/*  f15997c:	afb90184 */ 	sw	$t9,0x184($sp)
/*  f159980:	860e0002 */ 	lh	$t6,0x2($s0)
/*  f159984:	afae0188 */ 	sw	$t6,0x188($sp)
/*  f159988:	860f0004 */ 	lh	$t7,0x4($s0)
/*  f15998c:	a7a003ce */ 	sh	$zero,0x3ce($sp)
/*  f159990:	a7a003cc */ 	sh	$zero,0x3cc($sp)
/*  f159994:	afaf018c */ 	sw	$t7,0x18c($sp)
.L0f159998:
/*  f159998:	82c20000 */ 	lb	$v0,0x0($s6)
/*  f15999c:	2401ffb8 */ 	addiu	$at,$zero,-72
/*  f1599a0:	1041014f */ 	beq	$v0,$at,.L0f159ee0
/*  f1599a4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1599a8:	1041014b */ 	beq	$v0,$at,.L0f159ed8
/*  f1599ac:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1599b0:	5441002a */ 	bnel	$v0,$at,.L0f159a5c
/*  f1599b4:	2401ffbf */ 	addiu	$at,$zero,-65
/*  f1599b8:	92c20001 */ 	lbu	$v0,0x1($s6)
/*  f1599bc:	8ec40004 */ 	lw	$a0,0x4($s6)
/*  f1599c0:	3c0100ff */ 	lui	$at,0xff
/*  f1599c4:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1599c8:	0002a902 */ 	srl	$s5,$v0,0x4
/*  f1599cc:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f1599d0:	0081c024 */ 	and	$t8,$a0,$at
/*  f1599d4:	03002025 */ 	or	$a0,$t8,$zero
/*  f1599d8:	00009025 */ 	or	$s2,$zero,$zero
/*  f1599dc:	1aa0013e */ 	blez	$s5,.L0f159ed8
/*  f1599e0:	3043000f */ 	andi	$v1,$v0,0xf
/*  f1599e4:	8fb803e0 */ 	lw	$t8,0x3e0($sp)
/*  f1599e8:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f1599ec:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f1599f0:	0019c840 */ 	sll	$t9,$t9,0x1
/*  f1599f4:	00037080 */ 	sll	$t6,$v1,0x2
/*  f1599f8:	27af00e0 */ 	addiu	$t7,$sp,0xe0
/*  f1599fc:	01cfa021 */ 	addu	$s4,$t6,$t7
/*  f159a00:	02f98021 */ 	addu	$s0,$s7,$t9
/*  f159a04:	27b300a0 */ 	addiu	$s3,$sp,0xa0
/*  f159a08:	03048821 */ 	addu	$s1,$t8,$a0
.L0f159a0c:
/*  f159a0c:	86390000 */ 	lh	$t9,0x0($s1)
/*  f159a10:	02602025 */ 	or	$a0,$s3,$zero
/*  f159a14:	02002825 */ 	or	$a1,$s0,$zero
/*  f159a18:	a6190000 */ 	sh	$t9,0x0($s0)
/*  f159a1c:	862e0002 */ 	lh	$t6,0x2($s1)
/*  f159a20:	02803025 */ 	or	$a2,$s4,$zero
/*  f159a24:	27a70184 */ 	addiu	$a3,$sp,0x184
/*  f159a28:	a60e0002 */ 	sh	$t6,0x2($s0)
/*  f159a2c:	862f0004 */ 	lh	$t7,0x4($s1)
/*  f159a30:	0fc56221 */ 	jal	func0f158884
/*  f159a34:	a60f0004 */ 	sh	$t7,0x4($s0)
/*  f159a38:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f159a3c:	26100006 */ 	addiu	$s0,$s0,0x6
/*  f159a40:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f159a44:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f159a48:	1655fff0 */ 	bne	$s2,$s5,.L0f159a0c
/*  f159a4c:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f159a50:	1000ffd1 */ 	beqz	$zero,.L0f159998
/*  f159a54:	26d60008 */ 	addiu	$s6,$s6,0x8
/*  f159a58:	2401ffbf */ 	addiu	$at,$zero,-65
.L0f159a5c:
/*  f159a5c:	14410056 */ 	bne	$v0,$at,.L0f159bb8
/*  f159a60:	27ad00a0 */ 	addiu	$t5,$sp,0xa0
/*  f159a64:	92d80005 */ 	lbu	$t8,0x5($s6)
/*  f159a68:	241f000a */ 	addiu	$ra,$zero,0xa
/*  f159a6c:	92cf0006 */ 	lbu	$t7,0x6($s6)
/*  f159a70:	031f001a */ 	div	$zero,$t8,$ra
/*  f159a74:	00001012 */ 	mflo	$v0
/*  f159a78:	0002cc00 */ 	sll	$t9,$v0,0x10
/*  f159a7c:	00197403 */ 	sra	$t6,$t9,0x10
/*  f159a80:	01ff001a */ 	div	$zero,$t7,$ra
/*  f159a84:	01c01025 */ 	or	$v0,$t6,$zero
/*  f159a88:	00001812 */ 	mflo	$v1
/*  f159a8c:	92ce0007 */ 	lbu	$t6,0x7($s6)
/*  f159a90:	27ac00e0 */ 	addiu	$t4,$sp,0xe0
/*  f159a94:	17e00002 */ 	bnez	$ra,.L0f159aa0
/*  f159a98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159a9c:	0007000d */ 	break	0x7
.L0f159aa0:
/*  f159aa0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f159aa4:	17e10004 */ 	bne	$ra,$at,.L0f159ab8
/*  f159aa8:	3c018000 */ 	lui	$at,0x8000
/*  f159aac:	17010002 */ 	bne	$t8,$at,.L0f159ab8
/*  f159ab0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159ab4:	0006000d */ 	break	0x6
.L0f159ab8:
/*  f159ab8:	01df001a */ 	div	$zero,$t6,$ra
/*  f159abc:	00004012 */ 	mflo	$t0
/*  f159ac0:	0003c400 */ 	sll	$t8,$v1,0x10
/*  f159ac4:	0018cc03 */ 	sra	$t9,$t8,0x10
/*  f159ac8:	005e0019 */ 	multu	$v0,$s8
/*  f159acc:	03201825 */ 	or	$v1,$t9,$zero
/*  f159ad0:	17e00002 */ 	bnez	$ra,.L0f159adc
/*  f159ad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159ad8:	0007000d */ 	break	0x7
.L0f159adc:
/*  f159adc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f159ae0:	17e10004 */ 	bne	$ra,$at,.L0f159af4
/*  f159ae4:	3c018000 */ 	lui	$at,0x8000
/*  f159ae8:	15e10002 */ 	bne	$t7,$at,.L0f159af4
/*  f159aec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159af0:	0006000d */ 	break	0x6
.L0f159af4:
/*  f159af4:	0000c812 */ 	mflo	$t9
/*  f159af8:	00087c00 */ 	sll	$t7,$t0,0x10
/*  f159afc:	17e00002 */ 	bnez	$ra,.L0f159b08
/*  f159b00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159b04:	0007000d */ 	break	0x7
.L0f159b08:
/*  f159b08:	2401ffff */ 	addiu	$at,$zero,-1
/*  f159b0c:	17e10004 */ 	bne	$ra,$at,.L0f159b20
/*  f159b10:	3c018000 */ 	lui	$at,0x8000
/*  f159b14:	15c10002 */ 	bne	$t6,$at,.L0f159b20
/*  f159b18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159b1c:	0006000d */ 	break	0x6
.L0f159b20:
/*  f159b20:	007e0019 */ 	multu	$v1,$s8
/*  f159b24:	000fc403 */ 	sra	$t8,$t7,0x10
/*  f159b28:	03004025 */ 	or	$t0,$t8,$zero
/*  f159b2c:	02f93021 */ 	addu	$a2,$s7,$t9
/*  f159b30:	00024880 */ 	sll	$t1,$v0,0x2
/*  f159b34:	0189c821 */ 	addu	$t9,$t4,$t1
/*  f159b38:	00035080 */ 	sll	$t2,$v1,0x2
/*  f159b3c:	00085880 */ 	sll	$t3,$t0,0x2
/*  f159b40:	8fa403d8 */ 	lw	$a0,0x3d8($sp)
/*  f159b44:	27a50184 */ 	addiu	$a1,$sp,0x184
/*  f159b48:	00007012 */ 	mflo	$t6
/*  f159b4c:	02ee3821 */ 	addu	$a3,$s7,$t6
/*  f159b50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159b54:	031e0019 */ 	multu	$t8,$s8
/*  f159b58:	00007812 */ 	mflo	$t7
/*  f159b5c:	02efc021 */ 	addu	$t8,$s7,$t7
/*  f159b60:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f159b64:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159b68:	018a7821 */ 	addu	$t7,$t4,$t2
/*  f159b6c:	018bc821 */ 	addu	$t9,$t4,$t3
/*  f159b70:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f159b74:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159b78:	01a97821 */ 	addu	$t7,$t5,$t1
/*  f159b7c:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f159b80:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159b84:	01aac821 */ 	addu	$t9,$t5,$t2
/*  f159b88:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f159b8c:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159b90:	01ab7821 */ 	addu	$t7,$t5,$t3
/*  f159b94:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f159b98:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159b9c:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f159ba0:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159ba4:	0fc56367 */ 	jal	func0f158d9c
/*  f159ba8:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f159bac:	afa203d8 */ 	sw	$v0,0x3d8($sp)
/*  f159bb0:	1000ff79 */ 	beqz	$zero,.L0f159998
/*  f159bb4:	26d60008 */ 	addiu	$s6,$s6,0x8
.L0f159bb8:
/*  f159bb8:	2401ffb1 */ 	addiu	$at,$zero,-79
/*  f159bbc:	144100c6 */ 	bne	$v0,$at,.L0f159ed8
/*  f159bc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159bc4:	8ed00004 */ 	lw	$s0,0x4($s6)
/*  f159bc8:	92d10007 */ 	lbu	$s1,0x7($s6)
/*  f159bcc:	8ed20000 */ 	lw	$s2,0x0($s6)
/*  f159bd0:	3219000f */ 	andi	$t9,$s0,0xf
/*  f159bd4:	00197400 */ 	sll	$t6,$t9,0x10
/*  f159bd8:	000e8403 */ 	sra	$s0,$t6,0x10
/*  f159bdc:	021e0019 */ 	multu	$s0,$s8
/*  f159be0:	0011c102 */ 	srl	$t8,$s1,0x4
/*  f159be4:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f159be8:	00198c03 */ 	sra	$s1,$t9,0x10
/*  f159bec:	324f000f */ 	andi	$t7,$s2,0xf
/*  f159bf0:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f159bf4:	00189403 */ 	sra	$s2,$t8,0x10
/*  f159bf8:	27a200e0 */ 	addiu	$v0,$sp,0xe0
/*  f159bfc:	00109880 */ 	sll	$s3,$s0,0x2
/*  f159c00:	0011a080 */ 	sll	$s4,$s1,0x2
/*  f159c04:	00007012 */ 	mflo	$t6
/*  f159c08:	02ee3021 */ 	addu	$a2,$s7,$t6
/*  f159c0c:	00537021 */ 	addu	$t6,$v0,$s3
/*  f159c10:	023e0019 */ 	multu	$s1,$s8
/*  f159c14:	0012a880 */ 	sll	$s5,$s2,0x2
/*  f159c18:	27a300a0 */ 	addiu	$v1,$sp,0xa0
/*  f159c1c:	8fa403d8 */ 	lw	$a0,0x3d8($sp)
/*  f159c20:	27a50184 */ 	addiu	$a1,$sp,0x184
/*  f159c24:	00007812 */ 	mflo	$t7
/*  f159c28:	02ef3821 */ 	addu	$a3,$s7,$t7
/*  f159c2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159c30:	025e0019 */ 	multu	$s2,$s8
/*  f159c34:	0000c012 */ 	mflo	$t8
/*  f159c38:	02f8c821 */ 	addu	$t9,$s7,$t8
/*  f159c3c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f159c40:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f159c44:	0054c021 */ 	addu	$t8,$v0,$s4
/*  f159c48:	00557021 */ 	addu	$t6,$v0,$s5
/*  f159c4c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f159c50:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f159c54:	0073c021 */ 	addu	$t8,$v1,$s3
/*  f159c58:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f159c5c:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f159c60:	00747021 */ 	addu	$t6,$v1,$s4
/*  f159c64:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f159c68:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f159c6c:	0075c021 */ 	addu	$t8,$v1,$s5
/*  f159c70:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f159c74:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f159c78:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f159c7c:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f159c80:	0fc56367 */ 	jal	func0f158d9c
/*  f159c84:	afb90028 */ 	sw	$t9,0x28($sp)
/*  f159c88:	92d00006 */ 	lbu	$s0,0x6($s6)
/*  f159c8c:	96d10006 */ 	lhu	$s1,0x6($s6)
/*  f159c90:	92d20003 */ 	lbu	$s2,0x3($s6)
/*  f159c94:	320e000f */ 	andi	$t6,$s0,0xf
/*  f159c98:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f159c9c:	000f8403 */ 	sra	$s0,$t7,0x10
/*  f159ca0:	021e0019 */ 	multu	$s0,$s8
/*  f159ca4:	0011cb02 */ 	srl	$t9,$s1,0xc
/*  f159ca8:	00197400 */ 	sll	$t6,$t9,0x10
/*  f159cac:	000e8c03 */ 	sra	$s1,$t6,0x10
/*  f159cb0:	0012c102 */ 	srl	$t8,$s2,0x4
/*  f159cb4:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f159cb8:	00199403 */ 	sra	$s2,$t9,0x10
/*  f159cbc:	27a300e0 */ 	addiu	$v1,$sp,0xe0
/*  f159cc0:	00109880 */ 	sll	$s3,$s0,0x2
/*  f159cc4:	0011a080 */ 	sll	$s4,$s1,0x2
/*  f159cc8:	00007812 */ 	mflo	$t7
/*  f159ccc:	02ef3021 */ 	addu	$a2,$s7,$t7
/*  f159cd0:	00737821 */ 	addu	$t7,$v1,$s3
/*  f159cd4:	023e0019 */ 	multu	$s1,$s8
/*  f159cd8:	0012a880 */ 	sll	$s5,$s2,0x2
/*  f159cdc:	27a800a0 */ 	addiu	$t0,$sp,0xa0
/*  f159ce0:	00402025 */ 	or	$a0,$v0,$zero
/*  f159ce4:	27a50184 */ 	addiu	$a1,$sp,0x184
/*  f159ce8:	0000c012 */ 	mflo	$t8
/*  f159cec:	02f83821 */ 	addu	$a3,$s7,$t8
/*  f159cf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159cf4:	025e0019 */ 	multu	$s2,$s8
/*  f159cf8:	0000c812 */ 	mflo	$t9
/*  f159cfc:	02f97021 */ 	addu	$t6,$s7,$t9
/*  f159d00:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f159d04:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159d08:	0074c821 */ 	addu	$t9,$v1,$s4
/*  f159d0c:	00757821 */ 	addu	$t7,$v1,$s5
/*  f159d10:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f159d14:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159d18:	0113c821 */ 	addu	$t9,$t0,$s3
/*  f159d1c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f159d20:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159d24:	01147821 */ 	addu	$t7,$t0,$s4
/*  f159d28:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f159d2c:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159d30:	0115c821 */ 	addu	$t9,$t0,$s5
/*  f159d34:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f159d38:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159d3c:	afb80024 */ 	sw	$t8,0x24($sp)
/*  f159d40:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159d44:	0fc56367 */ 	jal	func0f158d9c
/*  f159d48:	afae0028 */ 	sw	$t6,0x28($sp)
/*  f159d4c:	96d00004 */ 	lhu	$s0,0x4($s6)
/*  f159d50:	92d10005 */ 	lbu	$s1,0x5($s6)
/*  f159d54:	92d20002 */ 	lbu	$s2,0x2($s6)
/*  f159d58:	320f000f */ 	andi	$t7,$s0,0xf
/*  f159d5c:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f159d60:	00188403 */ 	sra	$s0,$t8,0x10
/*  f159d64:	021e0019 */ 	multu	$s0,$s8
/*  f159d68:	00117102 */ 	srl	$t6,$s1,0x4
/*  f159d6c:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f159d70:	000f8c03 */ 	sra	$s1,$t7,0x10
/*  f159d74:	3259000f */ 	andi	$t9,$s2,0xf
/*  f159d78:	00197400 */ 	sll	$t6,$t9,0x10
/*  f159d7c:	000e9403 */ 	sra	$s2,$t6,0x10
/*  f159d80:	27a300e0 */ 	addiu	$v1,$sp,0xe0
/*  f159d84:	00109880 */ 	sll	$s3,$s0,0x2
/*  f159d88:	0011a080 */ 	sll	$s4,$s1,0x2
/*  f159d8c:	0000c012 */ 	mflo	$t8
/*  f159d90:	02f83021 */ 	addu	$a2,$s7,$t8
/*  f159d94:	0073c021 */ 	addu	$t8,$v1,$s3
/*  f159d98:	023e0019 */ 	multu	$s1,$s8
/*  f159d9c:	0012a880 */ 	sll	$s5,$s2,0x2
/*  f159da0:	27a800a0 */ 	addiu	$t0,$sp,0xa0
/*  f159da4:	00402025 */ 	or	$a0,$v0,$zero
/*  f159da8:	27a50184 */ 	addiu	$a1,$sp,0x184
/*  f159dac:	0000c812 */ 	mflo	$t9
/*  f159db0:	02f93821 */ 	addu	$a3,$s7,$t9
/*  f159db4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159db8:	025e0019 */ 	multu	$s2,$s8
/*  f159dbc:	00007012 */ 	mflo	$t6
/*  f159dc0:	02ee7821 */ 	addu	$t7,$s7,$t6
/*  f159dc4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f159dc8:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f159dcc:	00747021 */ 	addu	$t6,$v1,$s4
/*  f159dd0:	0075c021 */ 	addu	$t8,$v1,$s5
/*  f159dd4:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f159dd8:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f159ddc:	01137021 */ 	addu	$t6,$t0,$s3
/*  f159de0:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f159de4:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f159de8:	0114c021 */ 	addu	$t8,$t0,$s4
/*  f159dec:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f159df0:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f159df4:	01157021 */ 	addu	$t6,$t0,$s5
/*  f159df8:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f159dfc:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f159e00:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f159e04:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f159e08:	0fc56367 */ 	jal	func0f158d9c
/*  f159e0c:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f159e10:	92d00004 */ 	lbu	$s0,0x4($s6)
/*  f159e14:	8ed10004 */ 	lw	$s1,0x4($s6)
/*  f159e18:	96d20002 */ 	lhu	$s2,0x2($s6)
/*  f159e1c:	3218000f */ 	andi	$t8,$s0,0xf
/*  f159e20:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f159e24:	00198403 */ 	sra	$s0,$t9,0x10
/*  f159e28:	021e0019 */ 	multu	$s0,$s8
/*  f159e2c:	00117f02 */ 	srl	$t7,$s1,0x1c
/*  f159e30:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f159e34:	00188c03 */ 	sra	$s1,$t8,0x10
/*  f159e38:	00127302 */ 	srl	$t6,$s2,0xc
/*  f159e3c:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f159e40:	000f9403 */ 	sra	$s2,$t7,0x10
/*  f159e44:	27a300e0 */ 	addiu	$v1,$sp,0xe0
/*  f159e48:	00109880 */ 	sll	$s3,$s0,0x2
/*  f159e4c:	0011a080 */ 	sll	$s4,$s1,0x2
/*  f159e50:	0000c812 */ 	mflo	$t9
/*  f159e54:	02f93021 */ 	addu	$a2,$s7,$t9
/*  f159e58:	0073c821 */ 	addu	$t9,$v1,$s3
/*  f159e5c:	023e0019 */ 	multu	$s1,$s8
/*  f159e60:	0012a880 */ 	sll	$s5,$s2,0x2
/*  f159e64:	27a800a0 */ 	addiu	$t0,$sp,0xa0
/*  f159e68:	00402025 */ 	or	$a0,$v0,$zero
/*  f159e6c:	27a50184 */ 	addiu	$a1,$sp,0x184
/*  f159e70:	00007012 */ 	mflo	$t6
/*  f159e74:	02ee3821 */ 	addu	$a3,$s7,$t6
/*  f159e78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f159e7c:	025e0019 */ 	multu	$s2,$s8
/*  f159e80:	00007812 */ 	mflo	$t7
/*  f159e84:	02efc021 */ 	addu	$t8,$s7,$t7
/*  f159e88:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f159e8c:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159e90:	00747821 */ 	addu	$t7,$v1,$s4
/*  f159e94:	0075c821 */ 	addu	$t9,$v1,$s5
/*  f159e98:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f159e9c:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159ea0:	01137821 */ 	addu	$t7,$t0,$s3
/*  f159ea4:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f159ea8:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159eac:	0114c821 */ 	addu	$t9,$t0,$s4
/*  f159eb0:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f159eb4:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159eb8:	01157821 */ 	addu	$t7,$t0,$s5
/*  f159ebc:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f159ec0:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f159ec4:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f159ec8:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f159ecc:	0fc56367 */ 	jal	func0f158d9c
/*  f159ed0:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f159ed4:	afa203d8 */ 	sw	$v0,0x3d8($sp)
.L0f159ed8:
/*  f159ed8:	1000feaf */ 	beqz	$zero,.L0f159998
/*  f159edc:	26d60008 */ 	addiu	$s6,$s6,0x8
.L0f159ee0:
/*  f159ee0:	8fa403d8 */ 	lw	$a0,0x3d8($sp)
/*  f159ee4:	0fc56061 */ 	jal	func0f158184
/*  f159ee8:	27a50184 */ 	addiu	$a1,$sp,0x184
/*  f159eec:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f159ef0:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f159ef4:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f159ef8:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f159efc:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f159f00:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f159f04:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f159f08:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f159f0c:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f159f10:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f159f14:	03e00008 */ 	jr	$ra
/*  f159f18:	27bd03d8 */ 	addiu	$sp,$sp,0x3d8
);

GLOBAL_ASM(
glabel func0f159f1c
/*  f159f1c:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f159f20:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f159f24:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f159f28:	00c08025 */ 	or	$s0,$a2,$zero
/*  f159f2c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f159f30:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f159f34:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f159f38:	14c00003 */ 	bnez	$a2,.L0f159f48
/*  f159f3c:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f159f40:	10000069 */ 	beqz	$zero,.L0f15a0e8
/*  f159f44:	00801025 */ 	or	$v0,$a0,$zero
.L0f159f48:
/*  f159f48:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f159f4c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f159f50:	8fa70060 */ 	lw	$a3,0x60($sp)
/*  f159f54:	50400006 */ 	beqzl	$v0,.L0f159f70
/*  f159f58:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f159f5c:	50410012 */ 	beql	$v0,$at,.L0f159fa8
/*  f159f60:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f159f64:	10000060 */ 	beqz	$zero,.L0f15a0e8
/*  f159f68:	00801025 */ 	or	$v0,$a0,$zero
/*  f159f6c:	8e050008 */ 	lw	$a1,0x8($s0)
.L0f159f70:
/*  f159f70:	0fc5662d */ 	jal	func0f1598b4
/*  f159f74:	8e06000c */ 	lw	$a2,0xc($s0)
/*  f159f78:	8fae005c */ 	lw	$t6,0x5c($sp)
/*  f159f7c:	00402025 */ 	or	$a0,$v0,$zero
/*  f159f80:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f159f84:	11c00057 */ 	beqz	$t6,.L0f15a0e4
/*  f159f88:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f159f8c:	8faf0060 */ 	lw	$t7,0x60($sp)
/*  f159f90:	8e060004 */ 	lw	$a2,0x4($s0)
/*  f159f94:	0fc567c7 */ 	jal	func0f159f1c
/*  f159f98:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f159f9c:	10000051 */ 	beqz	$zero,.L0f15a0e4
/*  f159fa0:	00402025 */ 	or	$a0,$v0,$zero
/*  f159fa4:	8e050008 */ 	lw	$a1,0x8($s0)
.L0f159fa8:
/*  f159fa8:	50a0004f */ 	beqzl	$a1,.L0f15a0e8
/*  f159fac:	00801025 */ 	or	$v0,$a0,$zero
/*  f159fb0:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f159fb4:	8cb90004 */ 	lw	$t9,0x4($a1)
/*  f159fb8:	00a0c025 */ 	or	$t8,$a1,$zero
/*  f159fbc:	00003825 */ 	or	$a3,$zero,$zero
/*  f159fc0:	afb90044 */ 	sw	$t9,0x44($sp)
/*  f159fc4:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f159fc8:	8fa80060 */ 	lw	$t0,0x60($sp)
/*  f159fcc:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f159fd0:	c444000c */ 	lwc1	$f4,0xc($v0)
/*  f159fd4:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f159fd8:	8faa0060 */ 	lw	$t2,0x60($sp)
/*  f159fdc:	e7a40034 */ 	swc1	$f4,0x34($sp)
/*  f159fe0:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f159fe4:	e7a60038 */ 	swc1	$f6,0x38($sp)
/*  f159fe8:	c4480014 */ 	lwc1	$f8,0x14($v0)
/*  f159fec:	e7a8003c */ 	swc1	$f8,0x3c($sp)
/*  f159ff0:	c4701bb0 */ 	lwc1	$f16,0x1bb0($v1)
/*  f159ff4:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f159ff8:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f159ffc:	e7b20028 */ 	swc1	$f18,0x28($sp)
/*  f15a000:	c4661bb4 */ 	lwc1	$f6,0x1bb4($v1)
/*  f15a004:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f15a008:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f15a00c:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*  f15a010:	c7a40034 */ 	lwc1	$f4,0x34($sp)
/*  f15a014:	e7a8002c */ 	swc1	$f8,0x2c($sp)
/*  f15a018:	c4701bb8 */ 	lwc1	$f16,0x1bb8($v1)
/*  f15a01c:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f15a020:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f15a024:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f15a028:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*  f15a02c:	c7aa0038 */ 	lwc1	$f10,0x38($sp)
/*  f15a030:	e7b20030 */ 	swc1	$f18,0x30($sp)
/*  f15a034:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f15a038:	c7aa003c */ 	lwc1	$f10,0x3c($sp)
/*  f15a03c:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*  f15a040:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f15a044:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f15a048:	44804000 */ 	mtc1	$zero,$f8
/*  f15a04c:	46048000 */ 	add.s	$f0,$f16,$f4
/*  f15a050:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15a054:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a058:	4502000f */ 	bc1fl	.L0f15a098
/*  f15a05c:	00003825 */ 	or	$a3,$zero,$zero
/*  f15a060:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f15a064:	03003025 */ 	or	$a2,$t8,$zero
/*  f15a068:	0fc567c7 */ 	jal	func0f159f1c
/*  f15a06c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f15a070:	8fa90060 */ 	lw	$t1,0x60($sp)
/*  f15a074:	00402025 */ 	or	$a0,$v0,$zero
/*  f15a078:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f15a07c:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f15a080:	00003825 */ 	or	$a3,$zero,$zero
/*  f15a084:	0fc567c7 */ 	jal	func0f159f1c
/*  f15a088:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f15a08c:	1000000c */ 	beqz	$zero,.L0f15a0c0
/*  f15a090:	00402025 */ 	or	$a0,$v0,$zero
/*  f15a094:	00003825 */ 	or	$a3,$zero,$zero
.L0f15a098:
/*  f15a098:	0fc567c7 */ 	jal	func0f159f1c
/*  f15a09c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f15a0a0:	8fab0060 */ 	lw	$t3,0x60($sp)
/*  f15a0a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f15a0a8:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f15a0ac:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f15a0b0:	00003825 */ 	or	$a3,$zero,$zero
/*  f15a0b4:	0fc567c7 */ 	jal	func0f159f1c
/*  f15a0b8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f15a0bc:	00402025 */ 	or	$a0,$v0,$zero
.L0f15a0c0:
/*  f15a0c0:	8fac005c */ 	lw	$t4,0x5c($sp)
/*  f15a0c4:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f15a0c8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f15a0cc:	11800005 */ 	beqz	$t4,.L0f15a0e4
/*  f15a0d0:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f15a0d4:	8e060004 */ 	lw	$a2,0x4($s0)
/*  f15a0d8:	0fc567c7 */ 	jal	func0f159f1c
/*  f15a0dc:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f15a0e0:	00402025 */ 	or	$a0,$v0,$zero
.L0f15a0e4:
/*  f15a0e4:	00801025 */ 	or	$v0,$a0,$zero
.L0f15a0e8:
/*  f15a0e8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f15a0ec:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f15a0f0:	27bd0050 */ 	addiu	$sp,$sp,0x50
/*  f15a0f4:	03e00008 */ 	jr	$ra
/*  f15a0f8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15a0fc
/*  f15a0fc:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f15a100:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f15a104:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f15a108:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f15a10c:	00a08025 */ 	or	$s0,$a1,$zero
/*  f15a110:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f15a114:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f15a118:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f15a11c:	10a00007 */ 	beqz	$a1,.L0f15a13c
/*  f15a120:	8c460284 */ 	lw	$a2,0x284($v0)
/*  f15a124:	8c4e02bc */ 	lw	$t6,0x2bc($v0)
/*  f15a128:	001088c0 */ 	sll	$s1,$s0,0x3
/*  f15a12c:	02308821 */ 	addu	$s1,$s1,$s0
/*  f15a130:	00ae082a */ 	slt	$at,$a1,$t6
/*  f15a134:	14200003 */ 	bnez	$at,.L0f15a144
/*  f15a138:	00118880 */ 	sll	$s1,$s1,0x2
.L0f15a13c:
/*  f15a13c:	1000005c */ 	beqz	$zero,.L0f15a2b0
/*  f15a140:	8fa20060 */ 	lw	$v0,0x60($sp)
.L0f15a144:
/*  f15a144:	3c0f800a */ 	lui	$t7,%hi(g_RoomPtrs)
/*  f15a148:	8def4928 */ 	lw	$t7,%lo(g_RoomPtrs)($t7)
/*  f15a14c:	02308823 */ 	subu	$s1,$s1,$s0
/*  f15a150:	00118880 */ 	sll	$s1,$s1,0x2
/*  f15a154:	01f11021 */ 	addu	$v0,$t7,$s1
/*  f15a158:	84430002 */ 	lh	$v1,0x2($v0)
/*  f15a15c:	3c078008 */ 	lui	$a3,%hi(var8007fc10)
/*  f15a160:	24e7fc10 */ 	addiu	$a3,$a3,%lo(var8007fc10)
/*  f15a164:	1460000d */ 	bnez	$v1,.L0f15a19c
/*  f15a168:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a16c:	84e50000 */ 	lh	$a1,0x0($a3)
/*  f15a170:	02002025 */ 	or	$a0,$s0,$zero
/*  f15a174:	18a00009 */ 	blez	$a1,.L0f15a19c
/*  f15a178:	24b8ffff */ 	addiu	$t8,$a1,-1
/*  f15a17c:	a4f80000 */ 	sh	$t8,0x0($a3)
/*  f15a180:	0fc57716 */ 	jal	func0f15dc58
/*  f15a184:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f15a188:	3c19800a */ 	lui	$t9,%hi(g_RoomPtrs)
/*  f15a18c:	8f394928 */ 	lw	$t9,%lo(g_RoomPtrs)($t9)
/*  f15a190:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f15a194:	03311021 */ 	addu	$v0,$t9,$s1
/*  f15a198:	84430002 */ 	lh	$v1,0x2($v0)
.L0f15a19c:
/*  f15a19c:	3c078008 */ 	lui	$a3,%hi(var8007fc10)
/*  f15a1a0:	14600005 */ 	bnez	$v1,.L0f15a1b8
/*  f15a1a4:	24e7fc10 */ 	addiu	$a3,$a3,%lo(var8007fc10)
/*  f15a1a8:	84e80000 */ 	lh	$t0,0x0($a3)
/*  f15a1ac:	2509ffff */ 	addiu	$t1,$t0,-1
/*  f15a1b0:	a4e90000 */ 	sh	$t1,0x0($a3)
/*  f15a1b4:	84430002 */ 	lh	$v1,0x2($v0)
.L0f15a1b8:
/*  f15a1b8:	14600003 */ 	bnez	$v1,.L0f15a1c8
/*  f15a1bc:	02002025 */ 	or	$a0,$s0,$zero
/*  f15a1c0:	1000003b */ 	beqz	$zero,.L0f15a2b0
/*  f15a1c4:	8fa20060 */ 	lw	$v0,0x60($sp)
.L0f15a1c8:
/*  f15a1c8:	27a50048 */ 	addiu	$a1,$sp,0x48
/*  f15a1cc:	0fc59b7c */ 	jal	func0f166df0
/*  f15a1d0:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f15a1d4:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f15a1d8:	c7a60048 */ 	lwc1	$f6,0x48($sp)
/*  f15a1dc:	c7b0004c */ 	lwc1	$f16,0x4c($sp)
/*  f15a1e0:	c4c40018 */ 	lwc1	$f4,0x18($a2)
/*  f15a1e4:	8fa40060 */ 	lw	$a0,0x60($sp)
/*  f15a1e8:	02002825 */ 	or	$a1,$s0,$zero
/*  f15a1ec:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f15a1f0:	c7a60050 */ 	lwc1	$f6,0x50($sp)
/*  f15a1f4:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f15a1f8:	c4ca001c */ 	lwc1	$f10,0x1c($a2)
/*  f15a1fc:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f15a200:	c7aa0054 */ 	lwc1	$f10,0x54($sp)
/*  f15a204:	e7b20058 */ 	swc1	$f18,0x58($sp)
/*  f15a208:	c4c40020 */ 	lwc1	$f4,0x20($a2)
/*  f15a20c:	c7b20058 */ 	lwc1	$f18,0x58($sp)
/*  f15a210:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f15a214:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f15a218:	440b8000 */ 	mfc1	$t3,$f16
/*  f15a21c:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f15a220:	e7a8005c */ 	swc1	$f8,0x5c($sp)
/*  f15a224:	c7a6005c */ 	lwc1	$f6,0x5c($sp)
/*  f15a228:	a7ab0040 */ 	sh	$t3,0x40($sp)
/*  f15a22c:	440d2000 */ 	mfc1	$t5,$f4
/*  f15a230:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f15a234:	a7ad0042 */ 	sh	$t5,0x42($sp)
/*  f15a238:	440f4000 */ 	mfc1	$t7,$f8
/*  f15a23c:	0fc59b5f */ 	jal	func0f166d7c
/*  f15a240:	a7af0044 */ 	sh	$t7,0x44($sp)
/*  f15a244:	3c18800a */ 	lui	$t8,%hi(g_RoomPtrs)
/*  f15a248:	8f184928 */ 	lw	$t8,%lo(g_RoomPtrs)($t8)
/*  f15a24c:	27a90040 */ 	addiu	$t1,$sp,0x40
/*  f15a250:	00402025 */ 	or	$a0,$v0,$zero
/*  f15a254:	0311c821 */ 	addu	$t9,$t8,$s1
/*  f15a258:	8f280014 */ 	lw	$t0,0x14($t9)
/*  f15a25c:	02002825 */ 	or	$a1,$s0,$zero
/*  f15a260:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f15a264:	8d060008 */ 	lw	$a2,0x8($t0)
/*  f15a268:	0fc567c7 */ 	jal	func0f159f1c
/*  f15a26c:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f15a270:	3c0a800a */ 	lui	$t2,%hi(g_RoomPtrs)
/*  f15a274:	8d4a4928 */ 	lw	$t2,%lo(g_RoomPtrs)($t2)
/*  f15a278:	27ad0040 */ 	addiu	$t5,$sp,0x40
/*  f15a27c:	00402025 */ 	or	$a0,$v0,$zero
/*  f15a280:	01515821 */ 	addu	$t3,$t2,$s1
/*  f15a284:	8d6c0014 */ 	lw	$t4,0x14($t3)
/*  f15a288:	02002825 */ 	or	$a1,$s0,$zero
/*  f15a28c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f15a290:	8d86000c */ 	lw	$a2,0xc($t4)
/*  f15a294:	0fc567c7 */ 	jal	func0f159f1c
/*  f15a298:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f15a29c:	3c0f800a */ 	lui	$t7,%hi(g_RoomPtrs)
/*  f15a2a0:	8def4928 */ 	lw	$t7,%lo(g_RoomPtrs)($t7)
/*  f15a2a4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f15a2a8:	01f1c021 */ 	addu	$t8,$t7,$s1
/*  f15a2ac:	a70e0002 */ 	sh	$t6,0x2($t8)
.L0f15a2b0:
/*  f15a2b0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f15a2b4:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f15a2b8:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f15a2bc:	03e00008 */ 	jr	$ra
/*  f15a2c0:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f15a2c4
/*  f15a2c4:	27bdfdc8 */ 	addiu	$sp,$sp,-568
/*  f15a2c8:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f15a2cc:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f15a2d0:	8d060348 */ 	lw	$a2,0x348($t0)
/*  f15a2d4:	8d0e034c */ 	lw	$t6,0x34c($t0)
/*  f15a2d8:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f15a2dc:	27b60098 */ 	addiu	$s6,$sp,0x98
/*  f15a2e0:	00ce082b */ 	sltu	$at,$a2,$t6
/*  f15a2e4:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f15a2e8:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f15a2ec:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f15a2f0:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f15a2f4:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f15a2f8:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f15a2fc:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f15a300:	afa40238 */ 	sw	$a0,0x238($sp)
/*  f15a304:	10200021 */ 	beqz	$at,.L0f15a38c
/*  f15a308:	02c03825 */ 	or	$a3,$s6,$zero
/*  f15a30c:	2415ffff */ 	addiu	$s5,$zero,-1
/*  f15a310:	2405008c */ 	addiu	$a1,$zero,0x8c
/*  f15a314:	a4e00000 */ 	sh	$zero,0x0($a3)
.L0f15a318:
/*  f15a318:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f15a31c:	50600016 */ 	beqzl	$v1,.L0f15a378
/*  f15a320:	8d0b034c */ 	lw	$t3,0x34c($t0)
/*  f15a324:	846f0028 */ 	lh	$t7,0x28($v1)
/*  f15a328:	24620028 */ 	addiu	$v0,$v1,0x28
/*  f15a32c:	3c04800a */ 	lui	$a0,%hi(g_RoomPtrs)
/*  f15a330:	52af0011 */ 	beql	$s5,$t7,.L0f15a378
/*  f15a334:	8d0b034c */ 	lw	$t3,0x34c($t0)
/*  f15a338:	8c844928 */ 	lw	$a0,%lo(g_RoomPtrs)($a0)
/*  f15a33c:	84430000 */ 	lh	$v1,0x0($v0)
.L0f15a340:
/*  f15a340:	00650019 */ 	multu	$v1,$a1
/*  f15a344:	0000c012 */ 	mflo	$t8
/*  f15a348:	0098c821 */ 	addu	$t9,$a0,$t8
/*  f15a34c:	97290000 */ 	lhu	$t1,0x0($t9)
/*  f15a350:	312a0004 */ 	andi	$t2,$t1,0x4
/*  f15a354:	51400004 */ 	beqzl	$t2,.L0f15a368
/*  f15a358:	84430002 */ 	lh	$v1,0x2($v0)
/*  f15a35c:	10000005 */ 	beqz	$zero,.L0f15a374
/*  f15a360:	a4e30000 */ 	sh	$v1,0x0($a3)
/*  f15a364:	84430002 */ 	lh	$v1,0x2($v0)
.L0f15a368:
/*  f15a368:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f15a36c:	16a3fff4 */ 	bne	$s5,$v1,.L0f15a340
/*  f15a370:	00000000 */ 	sll	$zero,$zero,0x0
.L0f15a374:
/*  f15a374:	8d0b034c */ 	lw	$t3,0x34c($t0)
.L0f15a378:
/*  f15a378:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f15a37c:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f15a380:	00cb082b */ 	sltu	$at,$a2,$t3
/*  f15a384:	5420ffe4 */ 	bnezl	$at,.L0f15a318
/*  f15a388:	a4e00000 */ 	sh	$zero,0x0($a3)
.L0f15a38c:
/*  f15a38c:	2415ffff */ 	addiu	$s5,$zero,-1
/*  f15a390:	0fc599b2 */ 	jal	func0f1666c8
/*  f15a394:	8fa40238 */ 	lw	$a0,0x238($sp)
/*  f15a398:	244c0008 */ 	addiu	$t4,$v0,0x8
/*  f15a39c:	afac0238 */ 	sw	$t4,0x238($sp)
/*  f15a3a0:	3c0db600 */ 	lui	$t5,0xb600
/*  f15a3a4:	240e3000 */ 	addiu	$t6,$zero,0x3000
/*  f15a3a8:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f15a3ac:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f15a3b0:	8faf0238 */ 	lw	$t7,0x238($sp)
/*  f15a3b4:	3c19b700 */ 	lui	$t9,0xb700
/*  f15a3b8:	24090204 */ 	addiu	$t1,$zero,0x204
/*  f15a3bc:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f15a3c0:	afb80238 */ 	sw	$t8,0x238($sp)
/*  f15a3c4:	ade90004 */ 	sw	$t1,0x4($t7)
/*  f15a3c8:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f15a3cc:	8faa0238 */ 	lw	$t2,0x238($sp)
/*  f15a3d0:	3c0dfffe */ 	lui	$t5,0xfffe
/*  f15a3d4:	3c0cfcff */ 	lui	$t4,0xfcff
/*  f15a3d8:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f15a3dc:	afab0238 */ 	sw	$t3,0x238($sp)
/*  f15a3e0:	358cffff */ 	ori	$t4,$t4,0xffff
/*  f15a3e4:	35ad793c */ 	ori	$t5,$t5,0x793c
/*  f15a3e8:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f15a3ec:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f15a3f0:	8fae0238 */ 	lw	$t6,0x238($sp)
/*  f15a3f4:	3c18ba00 */ 	lui	$t8,0xba00
/*  f15a3f8:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f15a3fc:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f15a400:	afaf0238 */ 	sw	$t7,0x238($sp)
/*  f15a404:	24192000 */ 	addiu	$t9,$zero,0x2000
/*  f15a408:	add90004 */ 	sw	$t9,0x4($t6)
/*  f15a40c:	add80000 */ 	sw	$t8,0x0($t6)
/*  f15a410:	8fa90238 */ 	lw	$t1,0x238($sp)
/*  f15a414:	3c0bba00 */ 	lui	$t3,0xba00
/*  f15a418:	356b1402 */ 	ori	$t3,$t3,0x1402
/*  f15a41c:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f15a420:	afaa0238 */ 	sw	$t2,0x238($sp)
/*  f15a424:	ad200004 */ 	sw	$zero,0x4($t1)
/*  f15a428:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f15a42c:	8fac0238 */ 	lw	$t4,0x238($sp)
/*  f15a430:	3c11b900 */ 	lui	$s1,0xb900
/*  f15a434:	3c120050 */ 	lui	$s2,0x50
/*  f15a438:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f15a43c:	afad0238 */ 	sw	$t5,0x238($sp)
/*  f15a440:	3631031d */ 	ori	$s1,$s1,0x31d
/*  f15a444:	365241c8 */ 	ori	$s2,$s2,0x41c8
/*  f15a448:	ad920004 */ 	sw	$s2,0x4($t4)
/*  f15a44c:	ad910000 */ 	sw	$s1,0x0($t4)
/*  f15a450:	8fb00238 */ 	lw	$s0,0x238($sp)
/*  f15a454:	3c140103 */ 	lui	$s4,0x103
/*  f15a458:	36940040 */ 	ori	$s4,$s4,0x40
/*  f15a45c:	260f0008 */ 	addiu	$t7,$s0,0x8
/*  f15a460:	afaf0238 */ 	sw	$t7,0x238($sp)
/*  f15a464:	0fc2d402 */ 	jal	currentPlayerGetUnk1758
/*  f15a468:	ae140000 */ 	sw	$s4,0x0($s0)
/*  f15a46c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15a470:	00402025 */ 	or	$a0,$v0,$zero
/*  f15a474:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f15a478:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f15a47c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f15a480:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f15a484:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f15a488:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f15a48c:	27a40238 */ 	addiu	$a0,$sp,0x238
/*  f15a490:	00002825 */ 	or	$a1,$zero,$zero
/*  f15a494:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f15a498:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f15a49c:	00003825 */ 	or	$a3,$zero,$zero
/*  f15a4a0:	8fa90238 */ 	lw	$t1,0x238($sp)
/*  f15a4a4:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f15a4a8:	afaa0238 */ 	sw	$t2,0x238($sp)
/*  f15a4ac:	ad320004 */ 	sw	$s2,0x4($t1)
/*  f15a4b0:	ad310000 */ 	sw	$s1,0x0($t1)
/*  f15a4b4:	0fc572dd */ 	jal	func0f15cb74
/*  f15a4b8:	8fa40238 */ 	lw	$a0,0x238($sp)
/*  f15a4bc:	3c12800a */ 	lui	$s2,%hi(var800a4ce4)
/*  f15a4c0:	26524ce4 */ 	addiu	$s2,$s2,%lo(var800a4ce4)
/*  f15a4c4:	3c04800a */ 	lui	$a0,%hi(var800a4ce4+0x2)
/*  f15a4c8:	84844ce6 */ 	lh	$a0,%lo(var800a4ce4+0x2)($a0)
/*  f15a4cc:	86530000 */ 	lh	$s3,0x0($s2)
/*  f15a4d0:	afa20238 */ 	sw	$v0,0x238($sp)
/*  f15a4d4:	3c038008 */ 	lui	$v1,%hi(var8007fc2c)
/*  f15a4d8:	0093082a */ 	slt	$at,$a0,$s3
/*  f15a4dc:	1420001b */ 	bnez	$at,.L0f15a54c
/*  f15a4e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a4e4:	8c63fc2c */ 	lw	$v1,%lo(var8007fc2c)($v1)
.L0f15a4e8:
/*  f15a4e8:	18600012 */ 	blez	$v1,.L0f15a534
/*  f15a4ec:	00008825 */ 	or	$s1,$zero,$zero
/*  f15a4f0:	3c10800a */ 	lui	$s0,%hi(var800a4640)
/*  f15a4f4:	26104640 */ 	addiu	$s0,$s0,%lo(var800a4640)
.L0f15a4f8:
/*  f15a4f8:	920b0003 */ 	lbu	$t3,0x3($s0)
/*  f15a4fc:	8fa40238 */ 	lw	$a0,0x238($sp)
/*  f15a500:	566b0007 */ 	bnel	$s3,$t3,.L0f15a520
/*  f15a504:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f15a508:	0fc5683f */ 	jal	func0f15a0fc
/*  f15a50c:	86050000 */ 	lh	$a1,0x0($s0)
/*  f15a510:	3c038008 */ 	lui	$v1,%hi(var8007fc2c)
/*  f15a514:	8c63fc2c */ 	lw	$v1,%lo(var8007fc2c)($v1)
/*  f15a518:	afa20238 */ 	sw	$v0,0x238($sp)
/*  f15a51c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f15a520:
/*  f15a520:	0223082a */ 	slt	$at,$s1,$v1
/*  f15a524:	1420fff4 */ 	bnez	$at,.L0f15a4f8
/*  f15a528:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f15a52c:	3c04800a */ 	lui	$a0,%hi(var800a4ce4+0x2)
/*  f15a530:	84844ce6 */ 	lh	$a0,%lo(var800a4ce4+0x2)($a0)
.L0f15a534:
/*  f15a534:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f15a538:	00136400 */ 	sll	$t4,$s3,0x10
/*  f15a53c:	000c9c03 */ 	sra	$s3,$t4,0x10
/*  f15a540:	0093082a */ 	slt	$at,$a0,$s3
/*  f15a544:	1020ffe8 */ 	beqz	$at,.L0f15a4e8
/*  f15a548:	00000000 */ 	sll	$zero,$zero,0x0
.L0f15a54c:
/*  f15a54c:	0fc572dd */ 	jal	func0f15cb74
/*  f15a550:	8fa40238 */ 	lw	$a0,0x238($sp)
/*  f15a554:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f15a558:	afae0238 */ 	sw	$t6,0x238($sp)
/*  f15a55c:	ac540000 */ 	sw	$s4,0x0($v0)
/*  f15a560:	0fc2d402 */ 	jal	currentPlayerGetUnk1758
/*  f15a564:	00408025 */ 	or	$s0,$v0,$zero
/*  f15a568:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15a56c:	00402025 */ 	or	$a0,$v0,$zero
/*  f15a570:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f15a574:	3c13800a */ 	lui	$s3,%hi(var800a4ce4+0x2)
/*  f15a578:	86734ce6 */ 	lh	$s3,%lo(var800a4ce4+0x2)($s3)
/*  f15a57c:	86440000 */ 	lh	$a0,0x0($s2)
/*  f15a580:	3c038008 */ 	lui	$v1,%hi(var8007fc2c)
/*  f15a584:	8c63fc2c */ 	lw	$v1,%lo(var8007fc2c)($v1)
/*  f15a588:	0264082a */ 	slt	$at,$s3,$a0
/*  f15a58c:	5420004d */ 	bnezl	$at,.L0f15a6c4
/*  f15a590:	8fa40238 */ 	lw	$a0,0x238($sp)
.L0f15a594:
/*  f15a594:	18600044 */ 	blez	$v1,.L0f15a6a8
/*  f15a598:	00009025 */ 	or	$s2,$zero,$zero
/*  f15a59c:	3c10800a */ 	lui	$s0,%hi(var800a4640)
/*  f15a5a0:	26104640 */ 	addiu	$s0,$s0,%lo(var800a4640)
.L0f15a5a4:
/*  f15a5a4:	920f0003 */ 	lbu	$t7,0x3($s0)
/*  f15a5a8:	8fb10238 */ 	lw	$s1,0x238($sp)
/*  f15a5ac:	166f0038 */ 	bne	$s3,$t7,.L0f15a690
/*  f15a5b0:	26390008 */ 	addiu	$t9,$s1,0x8
/*  f15a5b4:	afb90238 */ 	sw	$t9,0x238($sp)
/*  f15a5b8:	0fc2d402 */ 	jal	currentPlayerGetUnk1758
/*  f15a5bc:	ae340000 */ 	sw	$s4,0x0($s1)
/*  f15a5c0:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15a5c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f15a5c8:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f15a5cc:	860b0008 */ 	lh	$t3,0x8($s0)
/*  f15a5d0:	860a0006 */ 	lh	$t2,0x6($s0)
/*  f15a5d4:	86090004 */ 	lh	$t1,0x4($s0)
/*  f15a5d8:	860c000a */ 	lh	$t4,0xa($s0)
/*  f15a5dc:	448b4000 */ 	mtc1	$t3,$f8
/*  f15a5e0:	448a3000 */ 	mtc1	$t2,$f6
/*  f15a5e4:	44892000 */ 	mtc1	$t1,$f4
/*  f15a5e8:	448c5000 */ 	mtc1	$t4,$f10
/*  f15a5ec:	46804220 */ 	cvt.s.w	$f8,$f8
/*  f15a5f0:	8fa40238 */ 	lw	$a0,0x238($sp)
/*  f15a5f4:	468031a0 */ 	cvt.s.w	$f6,$f6
/*  f15a5f8:	44074000 */ 	mfc1	$a3,$f8
/*  f15a5fc:	46802120 */ 	cvt.s.w	$f4,$f4
/*  f15a600:	44063000 */ 	mfc1	$a2,$f6
/*  f15a604:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f15a608:	44052000 */ 	mfc1	$a1,$f4
/*  f15a60c:	0fc572ed */ 	jal	func0f15cbb4
/*  f15a610:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f15a614:	244d0008 */ 	addiu	$t5,$v0,0x8
/*  f15a618:	afad0238 */ 	sw	$t5,0x238($sp)
/*  f15a61c:	ac540000 */ 	sw	$s4,0x0($v0)
/*  f15a620:	0fc2d3fa */ 	jal	currentPlayerGetUnk1750
/*  f15a624:	00408825 */ 	or	$s1,$v0,$zero
/*  f15a628:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15a62c:	00402025 */ 	or	$a0,$v0,$zero
/*  f15a630:	0fc47b60 */ 	jal	debug0f11ed80
/*  f15a634:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f15a638:	10400013 */ 	beqz	$v0,.L0f15a688
/*  f15a63c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a640:	0fc59eb8 */ 	jal	getVar80084040
/*  f15a644:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a648:	1040000f */ 	beqz	$v0,.L0f15a688
/*  f15a64c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a650:	86050000 */ 	lh	$a1,0x0($s0)
/*  f15a654:	8fa40238 */ 	lw	$a0,0x238($sp)
/*  f15a658:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f15a65c:	16a50005 */ 	bne	$s5,$a1,.L0f15a674
/*  f15a660:	02c03825 */ 	or	$a3,$s6,$zero
/*  f15a664:	0fc181f2 */ 	jal	func0f0607c8
/*  f15a668:	00002825 */ 	or	$a1,$zero,$zero
/*  f15a66c:	afa20238 */ 	sw	$v0,0x238($sp)
/*  f15a670:	86050000 */ 	lh	$a1,0x0($s0)
.L0f15a674:
/*  f15a674:	8fa40238 */ 	lw	$a0,0x238($sp)
/*  f15a678:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f15a67c:	0fc181f2 */ 	jal	func0f0607c8
/*  f15a680:	02c03825 */ 	or	$a3,$s6,$zero
/*  f15a684:	afa20238 */ 	sw	$v0,0x238($sp)
.L0f15a688:
/*  f15a688:	3c038008 */ 	lui	$v1,%hi(var8007fc2c)
/*  f15a68c:	8c63fc2c */ 	lw	$v1,%lo(var8007fc2c)($v1)
.L0f15a690:
/*  f15a690:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f15a694:	0243082a */ 	slt	$at,$s2,$v1
/*  f15a698:	1420ffc2 */ 	bnez	$at,.L0f15a5a4
/*  f15a69c:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f15a6a0:	3c04800a */ 	lui	$a0,%hi(var800a4ce4)
/*  f15a6a4:	84844ce4 */ 	lh	$a0,%lo(var800a4ce4)($a0)
.L0f15a6a8:
/*  f15a6a8:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f15a6ac:	00137400 */ 	sll	$t6,$s3,0x10
/*  f15a6b0:	000e9c03 */ 	sra	$s3,$t6,0x10
/*  f15a6b4:	0264082a */ 	slt	$at,$s3,$a0
/*  f15a6b8:	1020ffb6 */ 	beqz	$at,.L0f15a594
/*  f15a6bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a6c0:	8fa40238 */ 	lw	$a0,0x238($sp)
.L0f15a6c4:
/*  f15a6c4:	0fc4969b */ 	jal	func0f125a6c
/*  f15a6c8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f15a6cc:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f15a6d0:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f15a6d4:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f15a6d8:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f15a6dc:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f15a6e0:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f15a6e4:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f15a6e8:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f15a6ec:	03e00008 */ 	jr	$ra
/*  f15a6f0:	27bd0238 */ 	addiu	$sp,$sp,0x238
);

GLOBAL_ASM(
glabel func0f15a6f4
/*  f15a6f4:	27bdfcc8 */ 	addiu	$sp,$sp,-824
/*  f15a6f8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f15a6fc:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f15a700:	3c018008 */ 	lui	$at,%hi(var8007fc14)
/*  f15a704:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f15a708:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f15a70c:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f15a710:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f15a714:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f15a718:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f15a71c:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f15a720:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f15a724:	ac20fc14 */ 	sw	$zero,%lo(var8007fc14)($at)
/*  f15a728:	95cf0010 */ 	lhu	$t7,0x10($t6)
/*  f15a72c:	3c13800a */ 	lui	$s3,%hi(g_Vars+0x4b4)
/*  f15a730:	24010001 */ 	addiu	$at,$zero,0x1
/*  f15a734:	00808825 */ 	or	$s1,$a0,$zero
/*  f15a738:	8e73a474 */ 	lw	$s3,%lo(g_Vars+0x4b4)($s3)
/*  f15a73c:	15e10005 */ 	bne	$t7,$at,.L0f15a754
/*  f15a740:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f15a744:	0fc568b1 */ 	jal	func0f15a2c4
/*  f15a748:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a74c:	10000268 */ 	beqz	$zero,.L0f15b0f0
/*  f15a750:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f15a754:
/*  f15a754:	3c098008 */ 	lui	$t1,%hi(var8007fc2c)
/*  f15a758:	8d29fc2c */ 	lw	$t1,%lo(var8007fc2c)($t1)
/*  f15a75c:	00009025 */ 	or	$s2,$zero,$zero
/*  f15a760:	1920000d */ 	blez	$t1,.L0f15a798
/*  f15a764:	3c10800a */ 	lui	$s0,%hi(var800a4640)
/*  f15a768:	26104640 */ 	addiu	$s0,$s0,%lo(var800a4640)
/*  f15a76c:	27a40108 */ 	addiu	$a0,$sp,0x108
/*  f15a770:	27a30090 */ 	addiu	$v1,$sp,0x90
.L0f15a774:
/*  f15a774:	a4720000 */ 	sh	$s2,0x0($v1)
/*  f15a778:	92180003 */ 	lbu	$t8,0x3($s0)
/*  f15a77c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f15a780:	0249082a */ 	slt	$at,$s2,$t1
/*  f15a784:	24840002 */ 	addiu	$a0,$a0,0x2
/*  f15a788:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f15a78c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f15a790:	1420fff8 */ 	bnez	$at,.L0f15a774
/*  f15a794:	a498fffe */ 	sh	$t8,-0x2($a0)
.L0f15a798:
/*  f15a798:	29210002 */ 	slti	$at,$t1,0x2
/*  f15a79c:	1420001b */ 	bnez	$at,.L0f15a80c
/*  f15a7a0:	252affff */ 	addiu	$t2,$t1,-1
/*  f15a7a4:	27a90090 */ 	addiu	$t1,$sp,0x90
.L0f15a7a8:
/*  f15a7a8:	19400016 */ 	blez	$t2,.L0f15a804
/*  f15a7ac:	0000a025 */ 	or	$s4,$zero,$zero
/*  f15a7b0:	27a40108 */ 	addiu	$a0,$sp,0x108
/*  f15a7b4:	000a5840 */ 	sll	$t3,$t2,0x1
/*  f15a7b8:	01644021 */ 	addu	$t0,$t3,$a0
/*  f15a7bc:	00002825 */ 	or	$a1,$zero,$zero
.L0f15a7c0:
/*  f15a7c0:	84860002 */ 	lh	$a2,0x2($a0)
/*  f15a7c4:	84870000 */ 	lh	$a3,0x0($a0)
/*  f15a7c8:	01251821 */ 	addu	$v1,$t1,$a1
/*  f15a7cc:	00c7082a */ 	slt	$at,$a2,$a3
/*  f15a7d0:	50200009 */ 	beqzl	$at,.L0f15a7f8
/*  f15a7d4:	24840002 */ 	addiu	$a0,$a0,0x2
/*  f15a7d8:	84620000 */ 	lh	$v0,0x0($v1)
/*  f15a7dc:	846d0002 */ 	lh	$t5,0x2($v1)
/*  f15a7e0:	a4860000 */ 	sh	$a2,0x0($a0)
/*  f15a7e4:	a4870002 */ 	sh	$a3,0x2($a0)
/*  f15a7e8:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15a7ec:	a4620002 */ 	sh	$v0,0x2($v1)
/*  f15a7f0:	a46d0000 */ 	sh	$t5,0x0($v1)
/*  f15a7f4:	24840002 */ 	addiu	$a0,$a0,0x2
.L0f15a7f8:
/*  f15a7f8:	0088082b */ 	sltu	$at,$a0,$t0
/*  f15a7fc:	1420fff0 */ 	bnez	$at,.L0f15a7c0
/*  f15a800:	24a50002 */ 	addiu	$a1,$a1,0x2
.L0f15a804:
/*  f15a804:	1680ffe8 */ 	bnez	$s4,.L0f15a7a8
/*  f15a808:	00000000 */ 	sll	$zero,$zero,0x0
.L0f15a80c:
/*  f15a80c:	02202025 */ 	or	$a0,$s1,$zero
/*  f15a810:	0fc572dd */ 	jal	func0f15cb74
/*  f15a814:	0000a025 */ 	or	$s4,$zero,$zero
/*  f15a818:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f15a81c:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f15a820:	00408825 */ 	or	$s1,$v0,$zero
/*  f15a824:	8c6400d8 */ 	lw	$a0,0xd8($v1)
/*  f15a828:	14800013 */ 	bnez	$a0,.L0f15a878
/*  f15a82c:	3c0e8007 */ 	lui	$t6,%hi(var80070764)
/*  f15a830:	8dce0764 */ 	lw	$t6,%lo(var80070764)($t6)
/*  f15a834:	15c00010 */ 	bnez	$t6,.L0f15a878
/*  f15a838:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a83c:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f15a840:	50400007 */ 	beqzl	$v0,.L0f15a860
/*  f15a844:	8c6b1c54 */ 	lw	$t3,0x1c54($v1)
/*  f15a848:	1040000b */ 	beqz	$v0,.L0f15a878
/*  f15a84c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a850:	804f0037 */ 	lb	$t7,0x37($v0)
/*  f15a854:	15e00008 */ 	bnez	$t7,.L0f15a878
/*  f15a858:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a85c:	8c6b1c54 */ 	lw	$t3,0x1c54($v1)
.L0f15a860:
/*  f15a860:	8c7800c4 */ 	lw	$t8,0xc4($v1)
/*  f15a864:	0160c827 */ 	nor	$t9,$t3,$zero
/*  f15a868:	03196024 */ 	and	$t4,$t8,$t9
/*  f15a86c:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f15a870:	55a000c1 */ 	bnezl	$t5,.L0f15ab78
/*  f15a874:	02202025 */ 	or	$a0,$s1,$zero
.L0f15a878:
/*  f15a878:	14800012 */ 	bnez	$a0,.L0f15a8c4
/*  f15a87c:	3c0e8007 */ 	lui	$t6,%hi(var80070764)
/*  f15a880:	8dce0764 */ 	lw	$t6,%lo(var80070764)($t6)
/*  f15a884:	15c0000f */ 	bnez	$t6,.L0f15a8c4
/*  f15a888:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a88c:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f15a890:	50400007 */ 	beqzl	$v0,.L0f15a8b0
/*  f15a894:	8c781c54 */ 	lw	$t8,0x1c54($v1)
/*  f15a898:	1040000a */ 	beqz	$v0,.L0f15a8c4
/*  f15a89c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a8a0:	804f0037 */ 	lb	$t7,0x37($v0)
/*  f15a8a4:	15e00007 */ 	bnez	$t7,.L0f15a8c4
/*  f15a8a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a8ac:	8c781c54 */ 	lw	$t8,0x1c54($v1)
.L0f15a8b0:
/*  f15a8b0:	8c6b00c4 */ 	lw	$t3,0xc4($v1)
/*  f15a8b4:	0300c827 */ 	nor	$t9,$t8,$zero
/*  f15a8b8:	01796024 */ 	and	$t4,$t3,$t9
/*  f15a8bc:	318d0008 */ 	andi	$t5,$t4,0x8
/*  f15a8c0:	15a000ac */ 	bnez	$t5,.L0f15ab74
.L0f15a8c4:
/*  f15a8c4:	3c108008 */ 	lui	$s0,%hi(g_Stages)
/*  f15a8c8:	2610fcc0 */ 	addiu	$s0,$s0,%lo(g_Stages)
/*  f15a8cc:	860e05e8 */ 	lh	$t6,0x5e8($s0)
/*  f15a8d0:	126e001f */ 	beq	$s3,$t6,.L0f15a950
/*  f15a8d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a8d8:	860f0738 */ 	lh	$t7,0x738($s0)
/*  f15a8dc:	126f001c */ 	beq	$s3,$t7,.L0f15a950
/*  f15a8e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a8e4:	86180118 */ 	lh	$t8,0x118($s0)
/*  f15a8e8:	12780019 */ 	beq	$s3,$t8,.L0f15a950
/*  f15a8ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a8f0:	860b0000 */ 	lh	$t3,0x0($s0)
/*  f15a8f4:	126b0016 */ 	beq	$s3,$t3,.L0f15a950
/*  f15a8f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a8fc:	861904d0 */ 	lh	$t9,0x4d0($s0)
/*  f15a900:	12790013 */ 	beq	$s3,$t9,.L0f15a950
/*  f15a904:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a908:	860c0070 */ 	lh	$t4,0x70($s0)
/*  f15a90c:	126c0010 */ 	beq	$s3,$t4,.L0f15a950
/*  f15a910:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a914:	860d0620 */ 	lh	$t5,0x620($s0)
/*  f15a918:	126d000d */ 	beq	$s3,$t5,.L0f15a950
/*  f15a91c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a920:	860e0310 */ 	lh	$t6,0x310($s0)
/*  f15a924:	126e000a */ 	beq	$s3,$t6,.L0f15a950
/*  f15a928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a92c:	860f07a8 */ 	lh	$t7,0x7a8($s0)
/*  f15a930:	126f0007 */ 	beq	$s3,$t7,.L0f15a950
/*  f15a934:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a938:	86180850 */ 	lh	$t8,0x850($s0)
/*  f15a93c:	12780004 */ 	beq	$s3,$t8,.L0f15a950
/*  f15a940:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a944:	860b0700 */ 	lh	$t3,0x700($s0)
/*  f15a948:	566b008b */ 	bnel	$s3,$t3,.L0f15ab78
/*  f15a94c:	02202025 */ 	or	$a0,$s1,$zero
.L0f15a950:
/*  f15a950:	0fc599b2 */ 	jal	func0f1666c8
/*  f15a954:	02202025 */ 	or	$a0,$s1,$zero
/*  f15a958:	0c002ade */ 	jal	func0000ab78
/*  f15a95c:	00402025 */ 	or	$a0,$v0,$zero
/*  f15a960:	861905e8 */ 	lh	$t9,0x5e8($s0)
/*  f15a964:	00408825 */ 	or	$s1,$v0,$zero
/*  f15a968:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f15a96c:	1279000a */ 	beq	$s3,$t9,.L0f15a998
/*  f15a970:	24010001 */ 	addiu	$at,$zero,0x1
/*  f15a974:	860c0738 */ 	lh	$t4,0x738($s0)
/*  f15a978:	126c0007 */ 	beq	$s3,$t4,.L0f15a998
/*  f15a97c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a980:	860d0118 */ 	lh	$t5,0x118($s0)
/*  f15a984:	126d0004 */ 	beq	$s3,$t5,.L0f15a998
/*  f15a988:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a98c:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f15a990:	566e0004 */ 	bnel	$s3,$t6,.L0f15a9a4
/*  f15a994:	860f04d0 */ 	lh	$t7,0x4d0($s0)
.L0f15a998:
/*  f15a998:	1000001d */ 	beqz	$zero,.L0f15aa10
/*  f15a99c:	2412000f */ 	addiu	$s2,$zero,0xf
/*  f15a9a0:	860f04d0 */ 	lh	$t7,0x4d0($s0)
.L0f15a9a4:
/*  f15a9a4:	126f0004 */ 	beq	$s3,$t7,.L0f15a9b8
/*  f15a9a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a9ac:	86180070 */ 	lh	$t8,0x70($s0)
/*  f15a9b0:	56780004 */ 	bnel	$s3,$t8,.L0f15a9c4
/*  f15a9b4:	860b0620 */ 	lh	$t3,0x620($s0)
.L0f15a9b8:
/*  f15a9b8:	10000015 */ 	beqz	$zero,.L0f15aa10
/*  f15a9bc:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f15a9c0:	860b0620 */ 	lh	$t3,0x620($s0)
.L0f15a9c4:
/*  f15a9c4:	126b0007 */ 	beq	$s3,$t3,.L0f15a9e4
/*  f15a9c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a9cc:	86190310 */ 	lh	$t9,0x310($s0)
/*  f15a9d0:	12790004 */ 	beq	$s3,$t9,.L0f15a9e4
/*  f15a9d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15a9d8:	860c07a8 */ 	lh	$t4,0x7a8($s0)
/*  f15a9dc:	566c0004 */ 	bnel	$s3,$t4,.L0f15a9f0
/*  f15a9e0:	860d0850 */ 	lh	$t5,0x850($s0)
.L0f15a9e4:
/*  f15a9e4:	1000000a */ 	beqz	$zero,.L0f15aa10
/*  f15a9e8:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f15a9ec:	860d0850 */ 	lh	$t5,0x850($s0)
.L0f15a9f0:
/*  f15a9f0:	566d0004 */ 	bnel	$s3,$t5,.L0f15aa04
/*  f15a9f4:	860e0700 */ 	lh	$t6,0x700($s0)
/*  f15a9f8:	10000005 */ 	beqz	$zero,.L0f15aa10
/*  f15a9fc:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f15aa00:	860e0700 */ 	lh	$t6,0x700($s0)
.L0f15aa04:
/*  f15aa04:	166e0002 */ 	bne	$s3,$t6,.L0f15aa10
/*  f15aa08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15aa0c:	24120071 */ 	addiu	$s2,$zero,0x71
.L0f15aa10:
/*  f15aa10:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x6c)
/*  f15aa14:	8defa02c */ 	lw	$t7,%lo(g_Vars+0x6c)($t7)
/*  f15aa18:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x68)
/*  f15aa1c:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x64)
/*  f15aa20:	11e00003 */ 	beqz	$t7,.L0f15aa30
/*  f15aa24:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x70)
/*  f15aa28:	10000002 */ 	beqz	$zero,.L0f15aa34
/*  f15aa2c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f15aa30:
/*  f15aa30:	00002825 */ 	or	$a1,$zero,$zero
.L0f15aa34:
/*  f15aa34:	8f18a028 */ 	lw	$t8,%lo(g_Vars+0x68)($t8)
/*  f15aa38:	00001825 */ 	or	$v1,$zero,$zero
/*  f15aa3c:	00002025 */ 	or	$a0,$zero,$zero
/*  f15aa40:	13000003 */ 	beqz	$t8,.L0f15aa50
/*  f15aa44:	00001025 */ 	or	$v0,$zero,$zero
/*  f15aa48:	10000001 */ 	beqz	$zero,.L0f15aa50
/*  f15aa4c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f15aa50:
/*  f15aa50:	8d6ba024 */ 	lw	$t3,%lo(g_Vars+0x64)($t3)
/*  f15aa54:	11600003 */ 	beqz	$t3,.L0f15aa64
/*  f15aa58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15aa5c:	10000001 */ 	beqz	$zero,.L0f15aa64
/*  f15aa60:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f15aa64:
/*  f15aa64:	8f39a030 */ 	lw	$t9,%lo(g_Vars+0x70)($t9)
/*  f15aa68:	13200003 */ 	beqz	$t9,.L0f15aa78
/*  f15aa6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15aa70:	10000001 */ 	beqz	$zero,.L0f15aa78
/*  f15aa74:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f15aa78:
/*  f15aa78:	00446021 */ 	addu	$t4,$v0,$a0
/*  f15aa7c:	01836821 */ 	addu	$t5,$t4,$v1
/*  f15aa80:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f15aa84:	15c10023 */ 	bne	$t6,$at,.L0f15ab14
/*  f15aa88:	24010030 */ 	addiu	$at,$zero,0x30
/*  f15aa8c:	1261000b */ 	beq	$s3,$at,.L0f15aabc
/*  f15aa90:	24010022 */ 	addiu	$at,$zero,0x22
/*  f15aa94:	12610009 */ 	beq	$s3,$at,.L0f15aabc
/*  f15aa98:	2401004e */ 	addiu	$at,$zero,0x4e
/*  f15aa9c:	12610007 */ 	beq	$s3,$at,.L0f15aabc
/*  f15aaa0:	2401002f */ 	addiu	$at,$zero,0x2f
/*  f15aaa4:	12610005 */ 	beq	$s3,$at,.L0f15aabc
/*  f15aaa8:	24010019 */ 	addiu	$at,$zero,0x19
/*  f15aaac:	12610003 */ 	beq	$s3,$at,.L0f15aabc
/*  f15aab0:	24010034 */ 	addiu	$at,$zero,0x34
/*  f15aab4:	56610018 */ 	bnel	$s3,$at,.L0f15ab18
/*  f15aab8:	2406ffff */ 	addiu	$a2,$zero,-1
.L0f15aabc:
/*  f15aabc:	0fc54d8a */ 	jal	func0f153628
/*  f15aac0:	02202025 */ 	or	$a0,$s1,$zero
/*  f15aac4:	3c0f0103 */ 	lui	$t7,0x103
/*  f15aac8:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f15aacc:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f15aad0:	00408025 */ 	or	$s0,$v0,$zero
/*  f15aad4:	0fc2d402 */ 	jal	currentPlayerGetUnk1758
/*  f15aad8:	24510008 */ 	addiu	$s1,$v0,0x8
/*  f15aadc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15aae0:	00402025 */ 	or	$a0,$v0,$zero
/*  f15aae4:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f15aae8:	0fc30cbf */ 	jal	func0f0c32fc
/*  f15aaec:	02202025 */ 	or	$a0,$s1,$zero
/*  f15aaf0:	0fc599b2 */ 	jal	func0f1666c8
/*  f15aaf4:	00402025 */ 	or	$a0,$v0,$zero
/*  f15aaf8:	0fc4da1f */ 	jal	func0f13687c
/*  f15aafc:	00402025 */ 	or	$a0,$v0,$zero
/*  f15ab00:	0fc54de0 */ 	jal	func0f153780
/*  f15ab04:	00402025 */ 	or	$a0,$v0,$zero
/*  f15ab08:	0c002ade */ 	jal	func0000ab78
/*  f15ab0c:	00402025 */ 	or	$a0,$v0,$zero
/*  f15ab10:	00408825 */ 	or	$s1,$v0,$zero
.L0f15ab14:
/*  f15ab14:	2406ffff */ 	addiu	$a2,$zero,-1
.L0f15ab18:
/*  f15ab18:	1246000f */ 	beq	$s2,$a2,.L0f15ab58
/*  f15ab1c:	2407008c */ 	addiu	$a3,$zero,0x8c
/*  f15ab20:	02470019 */ 	multu	$s2,$a3
/*  f15ab24:	3c18800a */ 	lui	$t8,%hi(g_RoomPtrs)
/*  f15ab28:	8f184928 */ 	lw	$t8,%lo(g_RoomPtrs)($t8)
/*  f15ab2c:	00005812 */ 	mflo	$t3
/*  f15ab30:	030bc821 */ 	addu	$t9,$t8,$t3
/*  f15ab34:	872c0002 */ 	lh	$t4,0x2($t9)
/*  f15ab38:	55800004 */ 	bnezl	$t4,.L0f15ab4c
/*  f15ab3c:	02202025 */ 	or	$a0,$s1,$zero
/*  f15ab40:	0fc57716 */ 	jal	func0f15dc58
/*  f15ab44:	02402025 */ 	or	$a0,$s2,$zero
/*  f15ab48:	02202025 */ 	or	$a0,$s1,$zero
.L0f15ab4c:
/*  f15ab4c:	0fc57aca */ 	jal	func0f15eb28
/*  f15ab50:	02402825 */ 	or	$a1,$s2,$zero
/*  f15ab54:	00408825 */ 	or	$s1,$v0,$zero
.L0f15ab58:
/*  f15ab58:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f15ab5c:	35ad000e */ 	ori	$t5,$t5,0xe
/*  f15ab60:	02208025 */ 	or	$s0,$s1,$zero
/*  f15ab64:	ae0d0000 */ 	sw	$t5,0x0($s0)
/*  f15ab68:	0c002adb */ 	jal	func0000ab6c
/*  f15ab6c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f15ab70:	ae020004 */ 	sw	$v0,0x4($s0)
.L0f15ab74:
/*  f15ab74:	02202025 */ 	or	$a0,$s1,$zero
.L0f15ab78:
/*  f15ab78:	0fc4969b */ 	jal	func0f125a6c
/*  f15ab7c:	00002825 */ 	or	$a1,$zero,$zero
/*  f15ab80:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x348)
/*  f15ab84:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x34c)
/*  f15ab88:	8dcea30c */ 	lw	$t6,%lo(g_Vars+0x34c)($t6)
/*  f15ab8c:	8ca5a308 */ 	lw	$a1,%lo(g_Vars+0x348)($a1)
/*  f15ab90:	27b50198 */ 	addiu	$s5,$sp,0x198
/*  f15ab94:	3c098008 */ 	lui	$t1,%hi(var8007fc2c)
/*  f15ab98:	00ae082b */ 	sltu	$at,$a1,$t6
/*  f15ab9c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f15aba0:	2407008c */ 	addiu	$a3,$zero,0x8c
/*  f15aba4:	00408825 */ 	or	$s1,$v0,$zero
/*  f15aba8:	8d29fc2c */ 	lw	$t1,%lo(var8007fc2c)($t1)
/*  f15abac:	10200022 */ 	beqz	$at,.L0f15ac38
/*  f15abb0:	02a04025 */ 	or	$t0,$s5,$zero
/*  f15abb4:	a5000000 */ 	sh	$zero,0x0($t0)
.L0f15abb8:
/*  f15abb8:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f15abbc:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x34c)
/*  f15abc0:	10600015 */ 	beqz	$v1,.L0f15ac18
/*  f15abc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15abc8:	846f0028 */ 	lh	$t7,0x28($v1)
/*  f15abcc:	24620028 */ 	addiu	$v0,$v1,0x28
/*  f15abd0:	3c04800a */ 	lui	$a0,%hi(g_RoomPtrs)
/*  f15abd4:	10cf0010 */ 	beq	$a2,$t7,.L0f15ac18
/*  f15abd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15abdc:	8c844928 */ 	lw	$a0,%lo(g_RoomPtrs)($a0)
/*  f15abe0:	84430000 */ 	lh	$v1,0x0($v0)
.L0f15abe4:
/*  f15abe4:	00670019 */ 	multu	$v1,$a3
/*  f15abe8:	0000c012 */ 	mflo	$t8
/*  f15abec:	00985821 */ 	addu	$t3,$a0,$t8
/*  f15abf0:	95790000 */ 	lhu	$t9,0x0($t3)
/*  f15abf4:	332c0004 */ 	andi	$t4,$t9,0x4
/*  f15abf8:	51800004 */ 	beqzl	$t4,.L0f15ac0c
/*  f15abfc:	84430002 */ 	lh	$v1,0x2($v0)
/*  f15ac00:	10000005 */ 	beqz	$zero,.L0f15ac18
/*  f15ac04:	a5030000 */ 	sh	$v1,0x0($t0)
/*  f15ac08:	84430002 */ 	lh	$v1,0x2($v0)
.L0f15ac0c:
/*  f15ac0c:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f15ac10:	14c3fff4 */ 	bne	$a2,$v1,.L0f15abe4
/*  f15ac14:	00000000 */ 	sll	$zero,$zero,0x0
.L0f15ac18:
/*  f15ac18:	8dada30c */ 	lw	$t5,%lo(g_Vars+0x34c)($t5)
/*  f15ac1c:	24a50004 */ 	addiu	$a1,$a1,4
/*  f15ac20:	25080002 */ 	addiu	$t0,$t0,0x2
/*  f15ac24:	00ad082b */ 	sltu	$at,$a1,$t5
/*  f15ac28:	5420ffe3 */ 	bnezl	$at,.L0f15abb8
/*  f15ac2c:	a5000000 */ 	sh	$zero,0x0($t0)
/*  f15ac30:	3c098008 */ 	lui	$t1,%hi(var8007fc2c)
/*  f15ac34:	8d29fc2c */ 	lw	$t1,%lo(var8007fc2c)($t1)
.L0f15ac38:
/*  f15ac38:	1920008c */ 	blez	$t1,.L0f15ae6c
/*  f15ac3c:	27b30090 */ 	addiu	$s3,$sp,0x90
.L0f15ac40:
/*  f15ac40:	06c10007 */ 	bgez	$s6,.L0f15ac60
/*  f15ac44:	86720000 */ 	lh	$s2,0x0($s3)
/*  f15ac48:	00127080 */ 	sll	$t6,$s2,0x2
/*  f15ac4c:	01d27023 */ 	subu	$t6,$t6,$s2
/*  f15ac50:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f15ac54:	3c16800a */ 	lui	$s6,%hi(var800a4640)
/*  f15ac58:	02ceb021 */ 	addu	$s6,$s6,$t6
/*  f15ac5c:	86d64640 */ 	lh	$s6,%lo(var800a4640)($s6)
.L0f15ac60:
/*  f15ac60:	3c0f0103 */ 	lui	$t7,0x103
/*  f15ac64:	0012c080 */ 	sll	$t8,$s2,0x2
/*  f15ac68:	0312c023 */ 	subu	$t8,$t8,$s2
/*  f15ac6c:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f15ac70:	02201025 */ 	or	$v0,$s1,$zero
/*  f15ac74:	3c0b800a */ 	lui	$t3,%hi(var800a4640)
/*  f15ac78:	256b4640 */ 	addiu	$t3,$t3,%lo(var800a4640)
/*  f15ac7c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f15ac80:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f15ac84:	030b8021 */ 	addu	$s0,$t8,$t3
/*  f15ac88:	afa20084 */ 	sw	$v0,0x84($sp)
/*  f15ac8c:	0fc2d3fa */ 	jal	currentPlayerGetUnk1750
/*  f15ac90:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f15ac94:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15ac98:	00402025 */ 	or	$a0,$v0,$zero
/*  f15ac9c:	8fb90084 */ 	lw	$t9,0x84($sp)
/*  f15aca0:	02202025 */ 	or	$a0,$s1,$zero
/*  f15aca4:	0fc599b2 */ 	jal	func0f1666c8
/*  f15aca8:	af220004 */ 	sw	$v0,0x4($t9)
/*  f15acac:	0fc47b60 */ 	jal	debug0f11ed80
/*  f15acb0:	00408825 */ 	or	$s1,$v0,$zero
/*  f15acb4:	50400014 */ 	beqzl	$v0,.L0f15ad08
/*  f15acb8:	3c0c0103 */ 	lui	$t4,0x103
/*  f15acbc:	0fc59eb8 */ 	jal	getVar80084040
/*  f15acc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15acc4:	50400010 */ 	beqzl	$v0,.L0f15ad08
/*  f15acc8:	3c0c0103 */ 	lui	$t4,0x103
/*  f15accc:	86050000 */ 	lh	$a1,0x0($s0)
/*  f15acd0:	02202025 */ 	or	$a0,$s1,$zero
/*  f15acd4:	00003025 */ 	or	$a2,$zero,$zero
/*  f15acd8:	16c50005 */ 	bne	$s6,$a1,.L0f15acf0
/*  f15acdc:	02a03825 */ 	or	$a3,$s5,$zero
/*  f15ace0:	0fc181f2 */ 	jal	func0f0607c8
/*  f15ace4:	00002825 */ 	or	$a1,$zero,$zero
/*  f15ace8:	00408825 */ 	or	$s1,$v0,$zero
/*  f15acec:	86050000 */ 	lh	$a1,0x0($s0)
.L0f15acf0:
/*  f15acf0:	02202025 */ 	or	$a0,$s1,$zero
/*  f15acf4:	00003025 */ 	or	$a2,$zero,$zero
/*  f15acf8:	0fc181f2 */ 	jal	func0f0607c8
/*  f15acfc:	02a03825 */ 	or	$a3,$s5,$zero
/*  f15ad00:	00408825 */ 	or	$s1,$v0,$zero
/*  f15ad04:	3c0c0103 */ 	lui	$t4,0x103
.L0f15ad08:
/*  f15ad08:	358c0040 */ 	ori	$t4,$t4,0x40
/*  f15ad0c:	02201025 */ 	or	$v0,$s1,$zero
/*  f15ad10:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f15ad14:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f15ad18:	0fc2d402 */ 	jal	currentPlayerGetUnk1758
/*  f15ad1c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f15ad20:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15ad24:	00402025 */ 	or	$a0,$v0,$zero
/*  f15ad28:	8fad0080 */ 	lw	$t5,0x80($sp)
/*  f15ad2c:	02202025 */ 	or	$a0,$s1,$zero
/*  f15ad30:	ada20004 */ 	sw	$v0,0x4($t5)
/*  f15ad34:	86180008 */ 	lh	$t8,0x8($s0)
/*  f15ad38:	860f0006 */ 	lh	$t7,0x6($s0)
/*  f15ad3c:	860e0004 */ 	lh	$t6,0x4($s0)
/*  f15ad40:	860b000a */ 	lh	$t3,0xa($s0)
/*  f15ad44:	44984000 */ 	mtc1	$t8,$f8
/*  f15ad48:	448f3000 */ 	mtc1	$t7,$f6
/*  f15ad4c:	448e2000 */ 	mtc1	$t6,$f4
/*  f15ad50:	448b5000 */ 	mtc1	$t3,$f10
/*  f15ad54:	46804220 */ 	cvt.s.w	$f8,$f8
/*  f15ad58:	468031a0 */ 	cvt.s.w	$f6,$f6
/*  f15ad5c:	44074000 */ 	mfc1	$a3,$f8
/*  f15ad60:	46802120 */ 	cvt.s.w	$f4,$f4
/*  f15ad64:	44063000 */ 	mfc1	$a2,$f6
/*  f15ad68:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f15ad6c:	44052000 */ 	mfc1	$a1,$f4
/*  f15ad70:	0fc572ed */ 	jal	func0f15cbb4
/*  f15ad74:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f15ad78:	00402025 */ 	or	$a0,$v0,$zero
/*  f15ad7c:	0fc59928 */ 	jal	func0f1664a0
/*  f15ad80:	00002825 */ 	or	$a1,$zero,$zero
/*  f15ad84:	0fc47b5e */ 	jal	debug0f11ed78
/*  f15ad88:	00408825 */ 	or	$s1,$v0,$zero
/*  f15ad8c:	5040000e */ 	beqzl	$v0,.L0f15adc8
/*  f15ad90:	3c0c0103 */ 	lui	$t4,0x103
/*  f15ad94:	0fc59eb8 */ 	jal	getVar80084040
/*  f15ad98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ad9c:	10400009 */ 	beqz	$v0,.L0f15adc4
/*  f15ada0:	3c198008 */ 	lui	$t9,%hi(g_StageIndex)
/*  f15ada4:	8f39fc00 */ 	lw	$t9,%lo(g_StageIndex)($t9)
/*  f15ada8:	24010026 */ 	addiu	$at,$zero,0x26
/*  f15adac:	02202025 */ 	or	$a0,$s1,$zero
/*  f15adb0:	53210005 */ 	beql	$t9,$at,.L0f15adc8
/*  f15adb4:	3c0c0103 */ 	lui	$t4,0x103
/*  f15adb8:	0fc57aca */ 	jal	func0f15eb28
/*  f15adbc:	86050000 */ 	lh	$a1,0x0($s0)
/*  f15adc0:	00408825 */ 	or	$s1,$v0,$zero
.L0f15adc4:
/*  f15adc4:	3c0c0103 */ 	lui	$t4,0x103
.L0f15adc8:
/*  f15adc8:	358c0040 */ 	ori	$t4,$t4,0x40
/*  f15adcc:	02201025 */ 	or	$v0,$s1,$zero
/*  f15add0:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f15add4:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f15add8:	0fc2d3fa */ 	jal	currentPlayerGetUnk1750
/*  f15addc:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f15ade0:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15ade4:	00402025 */ 	or	$a0,$v0,$zero
/*  f15ade8:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f15adec:	02202025 */ 	or	$a0,$s1,$zero
/*  f15adf0:	0fc599b2 */ 	jal	func0f1666c8
/*  f15adf4:	ada20004 */ 	sw	$v0,0x4($t5)
/*  f15adf8:	0fc47b60 */ 	jal	debug0f11ed80
/*  f15adfc:	00408825 */ 	or	$s1,$v0,$zero
/*  f15ae00:	10400013 */ 	beqz	$v0,.L0f15ae50
/*  f15ae04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ae08:	0fc59eb8 */ 	jal	getVar80084040
/*  f15ae0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ae10:	1040000f */ 	beqz	$v0,.L0f15ae50
/*  f15ae14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ae18:	86050000 */ 	lh	$a1,0x0($s0)
/*  f15ae1c:	02202025 */ 	or	$a0,$s1,$zero
/*  f15ae20:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f15ae24:	16c50005 */ 	bne	$s6,$a1,.L0f15ae3c
/*  f15ae28:	02a03825 */ 	or	$a3,$s5,$zero
/*  f15ae2c:	0fc181f2 */ 	jal	func0f0607c8
/*  f15ae30:	00002825 */ 	or	$a1,$zero,$zero
/*  f15ae34:	00408825 */ 	or	$s1,$v0,$zero
/*  f15ae38:	86050000 */ 	lh	$a1,0x0($s0)
.L0f15ae3c:
/*  f15ae3c:	02202025 */ 	or	$a0,$s1,$zero
/*  f15ae40:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f15ae44:	0fc181f2 */ 	jal	func0f0607c8
/*  f15ae48:	02a03825 */ 	or	$a3,$s5,$zero
/*  f15ae4c:	00408825 */ 	or	$s1,$v0,$zero
.L0f15ae50:
/*  f15ae50:	3c0e8008 */ 	lui	$t6,%hi(var8007fc2c)
/*  f15ae54:	8dcefc2c */ 	lw	$t6,%lo(var8007fc2c)($t6)
/*  f15ae58:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15ae5c:	26730002 */ 	addiu	$s3,$s3,0x2
/*  f15ae60:	028e082a */ 	slt	$at,$s4,$t6
/*  f15ae64:	1420ff76 */ 	bnez	$at,.L0f15ac40
/*  f15ae68:	00000000 */ 	sll	$zero,$zero,0x0
.L0f15ae6c:
/*  f15ae6c:	0fc599b2 */ 	jal	func0f1666c8
/*  f15ae70:	02202025 */ 	or	$a0,$s1,$zero
/*  f15ae74:	0fc572dd */ 	jal	func0f15cb74
/*  f15ae78:	00402025 */ 	or	$a0,$v0,$zero
/*  f15ae7c:	3c0f0103 */ 	lui	$t7,0x103
/*  f15ae80:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f15ae84:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f15ae88:	00408025 */ 	or	$s0,$v0,$zero
/*  f15ae8c:	0fc2d402 */ 	jal	currentPlayerGetUnk1758
/*  f15ae90:	24510008 */ 	addiu	$s1,$v0,0x8
/*  f15ae94:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15ae98:	00402025 */ 	or	$a0,$v0,$zero
/*  f15ae9c:	0fc59eb8 */ 	jal	getVar80084040
/*  f15aea0:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f15aea4:	1040001c */ 	beqz	$v0,.L0f15af18
/*  f15aea8:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x284)
/*  f15aeac:	8f18a244 */ 	lw	$t8,%lo(g_Vars+0x284)($t8)
/*  f15aeb0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f15aeb4:	3c198008 */ 	lui	$t9,%hi(var8007fc2c)
/*  f15aeb8:	970b0010 */ 	lhu	$t3,0x10($t8)
/*  f15aebc:	11610016 */ 	beq	$t3,$at,.L0f15af18
/*  f15aec0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15aec4:	8f39fc2c */ 	lw	$t9,%lo(var8007fc2c)($t9)
/*  f15aec8:	0000a025 */ 	or	$s4,$zero,$zero
/*  f15aecc:	27b30090 */ 	addiu	$s3,$sp,0x90
/*  f15aed0:	1b200011 */ 	blez	$t9,.L0f15af18
/*  f15aed4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f15aed8:
/*  f15aed8:	86720000 */ 	lh	$s2,0x0($s3)
/*  f15aedc:	3c04800a */ 	lui	$a0,%hi(var800a4640)
/*  f15aee0:	02202825 */ 	or	$a1,$s1,$zero
/*  f15aee4:	00126080 */ 	sll	$t4,$s2,0x2
/*  f15aee8:	01926023 */ 	subu	$t4,$t4,$s2
/*  f15aeec:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f15aef0:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f15aef4:	0fc5046c */ 	jal	func0f1411b0
/*  f15aef8:	84844640 */ 	lh	$a0,%lo(var800a4640)($a0)
/*  f15aefc:	3c0d8008 */ 	lui	$t5,%hi(var8007fc2c)
/*  f15af00:	8dadfc2c */ 	lw	$t5,%lo(var8007fc2c)($t5)
/*  f15af04:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15af08:	26730002 */ 	addiu	$s3,$s3,0x2
/*  f15af0c:	028d082a */ 	slt	$at,$s4,$t5
/*  f15af10:	1420fff1 */ 	bnez	$at,.L0f15aed8
/*  f15af14:	00408825 */ 	or	$s1,$v0,$zero
.L0f15af18:
/*  f15af18:	3c098008 */ 	lui	$t1,%hi(var8007fc2c)
/*  f15af1c:	8d29fc2c */ 	lw	$t1,%lo(var8007fc2c)($t1)
/*  f15af20:	27af0090 */ 	addiu	$t7,$sp,0x90
/*  f15af24:	2534ffff */ 	addiu	$s4,$t1,-1
/*  f15af28:	0680006f */ 	bltz	$s4,.L0f15b0e8
/*  f15af2c:	00147040 */ 	sll	$t6,$s4,0x1
/*  f15af30:	3c14800a */ 	lui	$s4,%hi(var800a4bf8)
/*  f15af34:	26944bf8 */ 	addiu	$s4,$s4,%lo(var800a4bf8)
/*  f15af38:	01cf9821 */ 	addu	$s3,$t6,$t7
/*  f15af3c:	3c180103 */ 	lui	$t8,0x103
.L0f15af40:
/*  f15af40:	86720000 */ 	lh	$s2,0x0($s3)
/*  f15af44:	37180040 */ 	ori	$t8,$t8,0x40
/*  f15af48:	02201025 */ 	or	$v0,$s1,$zero
/*  f15af4c:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f15af50:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f15af54:	0fc2d402 */ 	jal	currentPlayerGetUnk1758
/*  f15af58:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f15af5c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15af60:	00402025 */ 	or	$a0,$v0,$zero
/*  f15af64:	8fab0074 */ 	lw	$t3,0x74($sp)
/*  f15af68:	0012c880 */ 	sll	$t9,$s2,0x2
/*  f15af6c:	0332c823 */ 	subu	$t9,$t9,$s2
/*  f15af70:	3c0c800a */ 	lui	$t4,%hi(var800a4640)
/*  f15af74:	258c4640 */ 	addiu	$t4,$t4,%lo(var800a4640)
/*  f15af78:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f15af7c:	032c8021 */ 	addu	$s0,$t9,$t4
/*  f15af80:	ad620004 */ 	sw	$v0,0x4($t3)
/*  f15af84:	860f0008 */ 	lh	$t7,0x8($s0)
/*  f15af88:	860e0006 */ 	lh	$t6,0x6($s0)
/*  f15af8c:	860d0004 */ 	lh	$t5,0x4($s0)
/*  f15af90:	8618000a */ 	lh	$t8,0xa($s0)
/*  f15af94:	448f3000 */ 	mtc1	$t7,$f6
/*  f15af98:	448e2000 */ 	mtc1	$t6,$f4
/*  f15af9c:	448d9000 */ 	mtc1	$t5,$f18
/*  f15afa0:	44984000 */ 	mtc1	$t8,$f8
/*  f15afa4:	468031a0 */ 	cvt.s.w	$f6,$f6
/*  f15afa8:	02202025 */ 	or	$a0,$s1,$zero
/*  f15afac:	46802120 */ 	cvt.s.w	$f4,$f4
/*  f15afb0:	44073000 */ 	mfc1	$a3,$f6
/*  f15afb4:	468094a0 */ 	cvt.s.w	$f18,$f18
/*  f15afb8:	44062000 */ 	mfc1	$a2,$f4
/*  f15afbc:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f15afc0:	44059000 */ 	mfc1	$a1,$f18
/*  f15afc4:	0fc572ed */ 	jal	func0f15cbb4
/*  f15afc8:	e7aa0010 */ 	swc1	$f10,0x10($sp)
/*  f15afcc:	00402025 */ 	or	$a0,$v0,$zero
/*  f15afd0:	0fc59928 */ 	jal	func0f1664a0
/*  f15afd4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f15afd8:	0fc47b5e */ 	jal	debug0f11ed78
/*  f15afdc:	00408825 */ 	or	$s1,$v0,$zero
/*  f15afe0:	50400009 */ 	beqzl	$v0,.L0f15b008
/*  f15afe4:	3c0b0103 */ 	lui	$t3,0x103
/*  f15afe8:	0fc59eb8 */ 	jal	getVar80084040
/*  f15afec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15aff0:	10400004 */ 	beqz	$v0,.L0f15b004
/*  f15aff4:	02202025 */ 	or	$a0,$s1,$zero
/*  f15aff8:	0fc57af5 */ 	jal	func0f15ebd4
/*  f15affc:	86050000 */ 	lh	$a1,0x0($s0)
/*  f15b000:	00408825 */ 	or	$s1,$v0,$zero
.L0f15b004:
/*  f15b004:	3c0b0103 */ 	lui	$t3,0x103
.L0f15b008:
/*  f15b008:	356b0040 */ 	ori	$t3,$t3,0x40
/*  f15b00c:	02201025 */ 	or	$v0,$s1,$zero
/*  f15b010:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f15b014:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f15b018:	0fc2d3fa */ 	jal	currentPlayerGetUnk1750
/*  f15b01c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f15b020:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15b024:	00402025 */ 	or	$a0,$v0,$zero
/*  f15b028:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f15b02c:	02202025 */ 	or	$a0,$s1,$zero
/*  f15b030:	0fc599b2 */ 	jal	func0f1666c8
/*  f15b034:	af220004 */ 	sw	$v0,0x4($t9)
/*  f15b038:	0fc47b60 */ 	jal	debug0f11ed80
/*  f15b03c:	00408825 */ 	or	$s1,$v0,$zero
/*  f15b040:	10400013 */ 	beqz	$v0,.L0f15b090
/*  f15b044:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15b048:	0fc59eb8 */ 	jal	getVar80084040
/*  f15b04c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15b050:	1040000f */ 	beqz	$v0,.L0f15b090
/*  f15b054:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15b058:	86050000 */ 	lh	$a1,0x0($s0)
/*  f15b05c:	02202025 */ 	or	$a0,$s1,$zero
/*  f15b060:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f15b064:	16c50005 */ 	bne	$s6,$a1,.L0f15b07c
/*  f15b068:	02a03825 */ 	or	$a3,$s5,$zero
/*  f15b06c:	0fc181f2 */ 	jal	func0f0607c8
/*  f15b070:	00002825 */ 	or	$a1,$zero,$zero
/*  f15b074:	00408825 */ 	or	$s1,$v0,$zero
/*  f15b078:	86050000 */ 	lh	$a1,0x0($s0)
.L0f15b07c:
/*  f15b07c:	02202025 */ 	or	$a0,$s1,$zero
/*  f15b080:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f15b084:	0fc181f2 */ 	jal	func0f0607c8
/*  f15b088:	02a03825 */ 	or	$a3,$s5,$zero
/*  f15b08c:	00408825 */ 	or	$s1,$v0,$zero
.L0f15b090:
/*  f15b090:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x314)
/*  f15b094:	8d8ca2d4 */ 	lw	$t4,%lo(g_Vars+0x314)($t4)
/*  f15b098:	5580000f */ 	bnezl	$t4,.L0f15b0d8
/*  f15b09c:	2673fffe */ 	addiu	$s3,$s3,-2
/*  f15b0a0:	0fc4f1e0 */ 	jal	func0f13c780
/*  f15b0a4:	86040000 */ 	lh	$a0,0x0($s0)
/*  f15b0a8:	3c028008 */ 	lui	$v0,%hi(var8007fc14)
/*  f15b0ac:	8c42fc14 */ 	lw	$v0,%lo(var8007fc14)($v0)
/*  f15b0b0:	28410064 */ 	slti	$at,$v0,0x64
/*  f15b0b4:	10200007 */ 	beqz	$at,.L0f15b0d4
/*  f15b0b8:	00027040 */ 	sll	$t6,$v0,0x1
/*  f15b0bc:	860d0000 */ 	lh	$t5,0x0($s0)
/*  f15b0c0:	028e7821 */ 	addu	$t7,$s4,$t6
/*  f15b0c4:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f15b0c8:	3c018008 */ 	lui	$at,%hi(var8007fc14)
/*  f15b0cc:	a5ed0000 */ 	sh	$t5,0x0($t7)
/*  f15b0d0:	ac38fc14 */ 	sw	$t8,%lo(var8007fc14)($at)
.L0f15b0d4:
/*  f15b0d4:	2673fffe */ 	addiu	$s3,$s3,-2
.L0f15b0d8:
/*  f15b0d8:	27ab0090 */ 	addiu	$t3,$sp,0x90
/*  f15b0dc:	026b082b */ 	sltu	$at,$s3,$t3
/*  f15b0e0:	5020ff97 */ 	beqzl	$at,.L0f15af40
/*  f15b0e4:	3c180103 */ 	lui	$t8,0x103
.L0f15b0e8:
/*  f15b0e8:	02201025 */ 	or	$v0,$s1,$zero
/*  f15b0ec:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f15b0f0:
/*  f15b0f0:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f15b0f4:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f15b0f8:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f15b0fc:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f15b100:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f15b104:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f15b108:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f15b10c:	03e00008 */ 	jr	$ra
/*  f15b110:	27bd0338 */ 	addiu	$sp,$sp,0x338
);

GLOBAL_ASM(
glabel func0f15b114
/*  f15b114:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f15b118:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x314)
/*  f15b11c:	8dcea2d4 */ 	lw	$t6,%lo(g_Vars+0x314)($t6)
/*  f15b120:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f15b124:	00809025 */ 	or	$s2,$a0,$zero
/*  f15b128:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f15b12c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f15b130:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f15b134:	15c0001a */ 	bnez	$t6,.L0f15b1a0
/*  f15b138:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f15b13c:	3c138008 */ 	lui	$s3,%hi(var8007fc14)
/*  f15b140:	2673fc14 */ 	addiu	$s3,$s3,%lo(var8007fc14)
/*  f15b144:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f15b148:	19e00015 */ 	blez	$t7,.L0f15b1a0
/*  f15b14c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15b150:	0fc4f503 */ 	jal	func0f13d40c
/*  f15b154:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15b158:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f15b15c:	00409025 */ 	or	$s2,$v0,$zero
/*  f15b160:	00008025 */ 	or	$s0,$zero,$zero
/*  f15b164:	1b00000b */ 	blez	$t8,.L0f15b194
/*  f15b168:	3c11800a */ 	lui	$s1,%hi(var800a4bf8)
/*  f15b16c:	26314bf8 */ 	addiu	$s1,$s1,%lo(var800a4bf8)
.L0f15b170:
/*  f15b170:	02402025 */ 	or	$a0,$s2,$zero
/*  f15b174:	0fc4f55a */ 	jal	func0f13d568
/*  f15b178:	86250000 */ 	lh	$a1,0x0($s1)
/*  f15b17c:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15b180:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15b184:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f15b188:	0219082a */ 	slt	$at,$s0,$t9
/*  f15b18c:	1420fff8 */ 	bnez	$at,.L0f15b170
/*  f15b190:	00409025 */ 	or	$s2,$v0,$zero
.L0f15b194:
/*  f15b194:	0fc4f553 */ 	jal	func0f13d54c
/*  f15b198:	02402025 */ 	or	$a0,$s2,$zero
/*  f15b19c:	00409025 */ 	or	$s2,$v0,$zero
.L0f15b1a0:
/*  f15b1a0:	0fc49c57 */ 	jal	func0f12715c
/*  f15b1a4:	02402025 */ 	or	$a0,$s2,$zero
/*  f15b1a8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f15b1ac:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f15b1b0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f15b1b4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f15b1b8:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f15b1bc:	03e00008 */ 	jr	$ra
/*  f15b1c0:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f15b1c4
/*  f15b1c4:	3c0e8008 */ 	lui	$t6,%hi(var8007fc04)
/*  f15b1c8:	8dcefc04 */ 	lw	$t6,%lo(var8007fc04)($t6)
/*  f15b1cc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f15b1d0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f15b1d4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f15b1d8:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f15b1dc:	11c00008 */ 	beqz	$t6,.L0f15b200
/*  f15b1e0:	00c03825 */ 	or	$a3,$a2,$zero
/*  f15b1e4:	3c0f8008 */ 	lui	$t7,%hi(var8007fc08)
/*  f15b1e8:	8deffc08 */ 	lw	$t7,%lo(var8007fc08)($t7)
/*  f15b1ec:	01e52021 */ 	addu	$a0,$t7,$a1
/*  f15b1f0:	0c012c5c */ 	jal	func0004b170
/*  f15b1f4:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f15b1f8:	1000000d */ 	beqz	$zero,.L0f15b230
/*  f15b1fc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f15b200:
/*  f15b200:	3c198008 */ 	lui	$t9,%hi(g_StageIndex)
/*  f15b204:	8f39fc00 */ 	lw	$t9,%lo(g_StageIndex)($t9)
/*  f15b208:	3c048008 */ 	lui	$a0,%hi(g_Stages+0x8)
/*  f15b20c:	8fa50018 */ 	lw	$a1,0x18($sp)
/*  f15b210:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f15b214:	01194023 */ 	subu	$t0,$t0,$t9
/*  f15b218:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f15b21c:	00882021 */ 	addu	$a0,$a0,$t0
/*  f15b220:	9484fcc8 */ 	lhu	$a0,%lo(g_Stages+0x8)($a0)
/*  f15b224:	0fc59bfc */ 	jal	func0f166ff0
/*  f15b228:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f15b22c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f15b230:
/*  f15b230:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f15b234:	03e00008 */ 	jr	$ra
/*  f15b238:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15b23c
/*  f15b23c:	3c058008 */ 	lui	$a1,%hi(g_Stages)
/*  f15b240:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f15b244:	24a5fcc0 */ 	addiu	$a1,$a1,%lo(g_Stages)
/*  f15b248:	00001025 */ 	or	$v0,$zero,$zero
/*  f15b24c:	2406003d */ 	addiu	$a2,$zero,0x3d
.L0f15b250:
/*  f15b250:	84ae0000 */ 	lh	$t6,0x0($a1)
/*  f15b254:	548e0003 */ 	bnel	$a0,$t6,.L0f15b264
/*  f15b258:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f15b25c:	00401825 */ 	or	$v1,$v0,$zero
/*  f15b260:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f15b264:
/*  f15b264:	1446fffa */ 	bne	$v0,$a2,.L0f15b250
/*  f15b268:	24a50038 */ 	addiu	$a1,$a1,0x38
/*  f15b26c:	03e00008 */ 	jr	$ra
/*  f15b270:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f15b274
/*  f15b274:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f15b278:	3c02800a */ 	lui	$v0,%hi(g_PortalSomethings)
/*  f15b27c:	8c424cc8 */ 	lw	$v0,%lo(g_PortalSomethings)($v0)
/*  f15b280:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f15b284:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f15b288:	afb40058 */ 	sw	$s4,0x58($sp)
/*  f15b28c:	afb30054 */ 	sw	$s3,0x54($sp)
/*  f15b290:	afb20050 */ 	sw	$s2,0x50($sp)
/*  f15b294:	afb1004c */ 	sw	$s1,0x4c($sp)
/*  f15b298:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f15b29c:	f7be0040 */ 	sdc1	$f30,0x40($sp)
/*  f15b2a0:	f7bc0038 */ 	sdc1	$f28,0x38($sp)
/*  f15b2a4:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f15b2a8:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f15b2ac:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f15b2b0:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f15b2b4:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f15b2b8:	95f80000 */ 	lhu	$t8,0x0($t7)
/*  f15b2bc:	4480e000 */ 	mtc1	$zero,$f28
/*  f15b2c0:	24110002 */ 	addiu	$s1,$zero,0x2
/*  f15b2c4:	03029821 */ 	addu	$s3,$t8,$v0
/*  f15b2c8:	92740000 */ 	lbu	$s4,0x0($s3)
/*  f15b2cc:	26720018 */ 	addiu	$s2,$s3,0x18
/*  f15b2d0:	2a810003 */ 	slti	$at,$s4,0x3
/*  f15b2d4:	14200034 */ 	bnez	$at,.L0f15b3a8
/*  f15b2d8:	3c013f00 */ 	lui	$at,0x3f00
/*  f15b2dc:	4481f000 */ 	mtc1	$at,$f30
/*  f15b2e0:	27b00084 */ 	addiu	$s0,$sp,0x84
.L0f15b2e4:
/*  f15b2e4:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f15b2e8:	02401025 */ 	or	$v0,$s2,$zero
/*  f15b2ec:	02602825 */ 	or	$a1,$s3,$zero
/*  f15b2f0:	27a30078 */ 	addiu	$v1,$sp,0x78
.L0f15b2f4:
/*  f15b2f4:	c444fff8 */ 	lwc1	$f4,-0x8($v0)
/*  f15b2f8:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*  f15b2fc:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f15b300:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f15b304:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f15b308:	24420004 */ 	addiu	$v0,$v0,4
/*  f15b30c:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f15b310:	e488fffc */ 	swc1	$f8,-0x4($a0)
/*  f15b314:	c444fff4 */ 	lwc1	$f4,-0xc($v0)
/*  f15b318:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f15b31c:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f15b320:	1470fff4 */ 	bne	$v1,$s0,.L0f15b2f4
/*  f15b324:	e466fffc */ 	swc1	$f6,-0x4($v1)
/*  f15b328:	c7b00088 */ 	lwc1	$f16,0x88($sp)
/*  f15b32c:	c7b20080 */ 	lwc1	$f18,0x80($sp)
/*  f15b330:	c7b4007c */ 	lwc1	$f20,0x7c($sp)
/*  f15b334:	c7b6008c */ 	lwc1	$f22,0x8c($sp)
/*  f15b338:	46128202 */ 	mul.s	$f8,$f16,$f18
/*  f15b33c:	c7b80078 */ 	lwc1	$f24,0x78($sp)
/*  f15b340:	c7ba0084 */ 	lwc1	$f26,0x84($sp)
/*  f15b344:	4616a282 */ 	mul.s	$f10,$f20,$f22
/*  f15b348:	4600d187 */ 	neg.s	$f6,$f26
/*  f15b34c:	4616c102 */ 	mul.s	$f4,$f24,$f22
/*  f15b350:	460a4001 */ 	sub.s	$f0,$f8,$f10
/*  f15b354:	46123202 */ 	mul.s	$f8,$f6,$f18
/*  f15b358:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15b35c:	4614d282 */ 	mul.s	$f10,$f26,$f20
/*  f15b360:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f15b364:	4610c182 */ 	mul.s	$f6,$f24,$f16
/*  f15b368:	46082080 */ 	add.s	$f2,$f4,$f8
/*  f15b36c:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f15b370:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15b374:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f15b378:	e7a20094 */ 	swc1	$f2,0x94($sp)
/*  f15b37c:	46065381 */ 	sub.s	$f14,$f10,$f6
/*  f15b380:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f15b384:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f15b388:	e7ae0098 */ 	swc1	$f14,0x98($sp)
/*  f15b38c:	0c012974 */ 	jal	sqrtf
/*  f15b390:	460a3300 */ 	add.s	$f12,$f6,$f10
/*  f15b394:	461e0102 */ 	mul.s	$f4,$f0,$f30
/*  f15b398:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f15b39c:	2652000c */ 	addiu	$s2,$s2,0xc
/*  f15b3a0:	1634ffd0 */ 	bne	$s1,$s4,.L0f15b2e4
/*  f15b3a4:	4604e700 */ 	add.s	$f28,$f28,$f4
.L0f15b3a8:
/*  f15b3a8:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f15b3ac:	4600e006 */ 	mov.s	$f0,$f28
/*  f15b3b0:	d7bc0038 */ 	ldc1	$f28,0x38($sp)
/*  f15b3b4:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f15b3b8:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f15b3bc:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f15b3c0:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f15b3c4:	d7be0040 */ 	ldc1	$f30,0x40($sp)
/*  f15b3c8:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f15b3cc:	8fb1004c */ 	lw	$s1,0x4c($sp)
/*  f15b3d0:	8fb20050 */ 	lw	$s2,0x50($sp)
/*  f15b3d4:	8fb30054 */ 	lw	$s3,0x54($sp)
/*  f15b3d8:	8fb40058 */ 	lw	$s4,0x58($sp)
/*  f15b3dc:	03e00008 */ 	jr	$ra
/*  f15b3e0:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
/*  f15b3e4:	3c03800a */ 	lui	$v1,%hi(g_PortalSomethings)
/*  f15b3e8:	8c634cc8 */ 	lw	$v1,%lo(g_PortalSomethings)($v1)
/*  f15b3ec:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f15b3f0:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f15b3f4:	95f80000 */ 	lhu	$t8,0x0($t7)
/*  f15b3f8:	03031021 */ 	addu	$v0,$t8,$v1
/*  f15b3fc:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f15b400:	e4a40000 */ 	swc1	$f4,0x0($a1)
/*  f15b404:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f15b408:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*  f15b40c:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f15b410:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*  f15b414:	c4500004 */ 	lwc1	$f16,0x4($v0)
/*  f15b418:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f15b41c:	00042880 */ 	sll	$a1,$a0,0x2
/*  f15b420:	00a42821 */ 	addu	$a1,$a1,$a0
/*  f15b424:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f15b428:	00052880 */ 	sll	$a1,$a1,0x2
/*  f15b42c:	e4d20000 */ 	swc1	$f18,0x0($a2)
/*  f15b430:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f15b434:	c4440014 */ 	lwc1	$f4,0x14($v0)
/*  f15b438:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f15b43c:	e4c80004 */ 	swc1	$f8,0x4($a2)
/*  f15b440:	c450000c */ 	lwc1	$f16,0xc($v0)
/*  f15b444:	c44a0018 */ 	lwc1	$f10,0x18($v0)
/*  f15b448:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f15b44c:	e4d20008 */ 	swc1	$f18,0x8($a2)
/*  f15b450:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*  f15b454:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f15b458:	3c06800a */ 	lui	$a2,%hi(var800a4ccc)
/*  f15b45c:	24c64ccc */ 	addiu	$a2,$a2,%lo(var800a4ccc)
/*  f15b460:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f15b464:	e4e80000 */ 	swc1	$f8,0x0($a3)
/*  f15b468:	c4500008 */ 	lwc1	$f16,0x8($v0)
/*  f15b46c:	c44a0014 */ 	lwc1	$f10,0x14($v0)
/*  f15b470:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f15b474:	e4f20004 */ 	swc1	$f18,0x4($a3)
/*  f15b478:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f15b47c:	c4440018 */ 	lwc1	$f4,0x18($v0)
/*  f15b480:	8fa30010 */ 	lw	$v1,0x10($sp)
/*  f15b484:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f15b488:	e4e80008 */ 	swc1	$f8,0x8($a3)
/*  f15b48c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f15b490:	00b94021 */ 	addu	$t0,$a1,$t9
/*  f15b494:	c50a0000 */ 	lwc1	$f10,0x0($t0)
/*  f15b498:	e46a0000 */ 	swc1	$f10,0x0($v1)
/*  f15b49c:	8cc90000 */ 	lw	$t1,0x0($a2)
/*  f15b4a0:	00a95021 */ 	addu	$t2,$a1,$t1
/*  f15b4a4:	c5500004 */ 	lwc1	$f16,0x4($t2)
/*  f15b4a8:	e4700004 */ 	swc1	$f16,0x4($v1)
/*  f15b4ac:	8ccb0000 */ 	lw	$t3,0x0($a2)
/*  f15b4b0:	00ab6021 */ 	addu	$t4,$a1,$t3
/*  f15b4b4:	c5920008 */ 	lwc1	$f18,0x8($t4)
/*  f15b4b8:	03e00008 */ 	jr	$ra
/*  f15b4bc:	e4720008 */ 	swc1	$f18,0x8($v1)
);

GLOBAL_ASM(
glabel func0f15b4c0
.late_rodata
glabel var7f1b75c8
.word 0x461c4000
.text
/*  f15b4c0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f15b4c4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f15b4c8:	0fc56c9d */ 	jal	func0f15b274
/*  f15b4cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15b4d0:	3c017f1b */ 	lui	$at,%hi(var7f1b75c8)
/*  f15b4d4:	c42475c8 */ 	lwc1	$f4,%lo(var7f1b75c8)($at)
/*  f15b4d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f15b4dc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f15b4e0:	46040183 */ 	div.s	$f6,$f0,$f4
/*  f15b4e4:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f15b4e8:	44034000 */ 	mfc1	$v1,$f8
/*  f15b4ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15b4f0:	28610100 */ 	slti	$at,$v1,0x100
/*  f15b4f4:	14200002 */ 	bnez	$at,.L0f15b500
/*  f15b4f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15b4fc:	240300ff */ 	addiu	$v1,$zero,0xff
.L0f15b500:
/*  f15b500:	03e00008 */ 	jr	$ra
/*  f15b504:	306200ff */ 	andi	$v0,$v1,0xff
/*  f15b508:	3c0e800a */ 	lui	$t6,%hi(var800a4cd0)
/*  f15b50c:	8dce4cd0 */ 	lw	$t6,%lo(var800a4cd0)($t6)
/*  f15b510:	01c47821 */ 	addu	$t7,$t6,$a0
/*  f15b514:	03e00008 */ 	jr	$ra
/*  f15b518:	91e20000 */ 	lbu	$v0,0x0($t7)
);

u32 func0f15b51c(u32 arg)
{
	return ~arg;
}

u32 xorBabebabe(u32 value)
{
	return value ^ 0xbabebabe;
}

GLOBAL_ASM(
glabel func0f15b534
/*  f15b534:	3c0f8009 */ 	lui	$t7,%hi(g_Is4Mb)
/*  f15b538:	91ef0af0 */ 	lbu	$t7,%lo(g_Is4Mb)($t7)
/*  f15b53c:	240e0008 */ 	addiu	$t6,$zero,0x8
/*  f15b540:	3c018008 */ 	lui	$at,%hi(var8007fc0c)
/*  f15b544:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f15b548:	a42efc0c */ 	sh	$t6,%lo(var8007fc0c)($at)
/*  f15b54c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f15b550:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f15b554:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f15b558:	15e10007 */ 	bne	$t7,$at,.L0f15b578
/*  f15b55c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f15b560:	24020006 */ 	addiu	$v0,$zero,0x6
/*  f15b564:	3c01800a */ 	lui	$at,%hi(var800a4bf0)
/*  f15b568:	a4224bf0 */ 	sh	$v0,%lo(var800a4bf0)($at)
/*  f15b56c:	3c01800a */ 	lui	$at,%hi(var800a4bf0+0x2)
/*  f15b570:	10000006 */ 	beqz	$zero,.L0f15b58c
/*  f15b574:	a4224bf2 */ 	sh	$v0,%lo(var800a4bf0+0x2)($at)
.L0f15b578:
/*  f15b578:	24020078 */ 	addiu	$v0,$zero,0x78
/*  f15b57c:	3c01800a */ 	lui	$at,%hi(var800a4bf0)
/*  f15b580:	a4224bf0 */ 	sh	$v0,%lo(var800a4bf0)($at)
/*  f15b584:	3c01800a */ 	lui	$at,%hi(var800a4bf0+0x2)
/*  f15b588:	a4224bf2 */ 	sh	$v0,%lo(var800a4bf0+0x2)($at)
.L0f15b58c:
/*  f15b58c:	0fc56c8f */ 	jal	func0f15b23c
/*  f15b590:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15b594:	3c038008 */ 	lui	$v1,%hi(g_StageIndex)
/*  f15b598:	2463fc00 */ 	addiu	$v1,$v1,%lo(g_StageIndex)
/*  f15b59c:	04410002 */ 	bgez	$v0,.L0f15b5a8
/*  f15b5a0:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f15b5a4:	ac600000 */ 	sw	$zero,0x0($v1)
.L0f15b5a8:
/*  f15b5a8:	03a02025 */ 	or	$a0,$sp,$zero
/*  f15b5ac:	2484007b */ 	addiu	$a0,$a0,0x7b
/*  f15b5b0:	3499000f */ 	ori	$t9,$a0,0xf
/*  f15b5b4:	3b24000f */ 	xori	$a0,$t9,0xf
/*  f15b5b8:	afa4002c */ 	sw	$a0,0x2c($sp)
/*  f15b5bc:	00002825 */ 	or	$a1,$zero,$zero
/*  f15b5c0:	0fc56c71 */ 	jal	func0f15b1c4
/*  f15b5c4:	24060040 */ 	addiu	$a2,$zero,0x40
/*  f15b5c8:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f15b5cc:	3c028008 */ 	lui	$v0,%hi(var8007fc54)
/*  f15b5d0:	3401801f */ 	dli	$at,0x801f
/*  f15b5d4:	8c6a0004 */ 	lw	$t2,0x4($v1)
/*  f15b5d8:	8c710000 */ 	lw	$s1,0x0($v1)
/*  f15b5dc:	2442fc54 */ 	addiu	$v0,$v0,%lo(var8007fc54)
/*  f15b5e0:	afaa0048 */ 	sw	$t2,0x48($sp)
/*  f15b5e4:	8c670008 */ 	lw	$a3,0x8($v1)
/*  f15b5e8:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15b5ec:	02275823 */ 	subu	$t3,$s1,$a3
/*  f15b5f0:	2631000f */ 	addiu	$s1,$s1,0xf
/*  f15b5f4:	362e000f */ 	ori	$t6,$s1,0xf
/*  f15b5f8:	39d1000f */ 	xori	$s1,$t6,0xf
/*  f15b5fc:	02212021 */ 	addu	$a0,$s1,$at
/*  f15b600:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f15b604:	256dfff4 */ 	addiu	$t5,$t3,-12
/*  f15b608:	3498000f */ 	ori	$t8,$a0,0xf
/*  f15b60c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f15b610:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f15b614:	0c0048f2 */ 	jal	malloc
/*  f15b618:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f15b61c:	8fa70058 */ 	lw	$a3,0x58($sp)
/*  f15b620:	00515021 */ 	addu	$t2,$v0,$s1
/*  f15b624:	3401800f */ 	dli	$at,0x800f
/*  f15b628:	01478023 */ 	subu	$s0,$t2,$a3
/*  f15b62c:	3c03800a */ 	lui	$v1,%hi(var800a491c)
/*  f15b630:	02018021 */ 	addu	$s0,$s0,$at
/*  f15b634:	2463491c */ 	addiu	$v1,$v1,%lo(var800a491c)
/*  f15b638:	360b000f */ 	ori	$t3,$s0,0xf
/*  f15b63c:	24e6001e */ 	addiu	$a2,$a3,0x1e
/*  f15b640:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f15b644:	3964000f */ 	xori	$a0,$t3,0xf
/*  f15b648:	3c018006 */ 	lui	$at,%hi(var8005d9a0)
/*  f15b64c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f15b650:	34ce000f */ 	ori	$t6,$a2,0xf
/*  f15b654:	00808025 */ 	or	$s0,$a0,$zero
/*  f15b658:	a02dd9a0 */ 	sb	$t5,%lo(var8005d9a0)($at)
/*  f15b65c:	39c6000f */ 	xori	$a2,$t6,0xf
/*  f15b660:	0fc56c71 */ 	jal	func0f15b1c4
/*  f15b664:	00002825 */ 	or	$a1,$zero,$zero
/*  f15b668:	3c05800a */ 	lui	$a1,%hi(var800a491c)
/*  f15b66c:	8fa60058 */ 	lw	$a2,0x58($sp)
/*  f15b670:	2604000c */ 	addiu	$a0,$s0,0xc
/*  f15b674:	0fc5766a */ 	jal	func0f15d9a8
/*  f15b678:	8ca5491c */ 	lw	$a1,%lo(var800a491c)($a1)
/*  f15b67c:	3c04800a */ 	lui	$a0,%hi(var800a491c)
/*  f15b680:	8c84491c */ 	lw	$a0,%lo(var800a491c)($a0)
/*  f15b684:	02202825 */ 	or	$a1,$s1,$zero
/*  f15b688:	0c00490c */ 	jal	func00012430
/*  f15b68c:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f15b690:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f15b694:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f15b698:	24060040 */ 	addiu	$a2,$zero,0x40
/*  f15b69c:	24a5000c */ 	addiu	$a1,$a1,12
/*  f15b6a0:	0fc56c71 */ 	jal	func0f15b1c4
/*  f15b6a4:	afa50028 */ 	sw	$a1,0x28($sp)
/*  f15b6a8:	8fa2002c */ 	lw	$v0,0x2c($sp)
/*  f15b6ac:	34018000 */ 	dli	$at,0x8000
/*  f15b6b0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15b6b4:	94510000 */ 	lhu	$s1,0x0($v0)
/*  f15b6b8:	94590002 */ 	lhu	$t9,0x2($v0)
/*  f15b6bc:	32387fff */ 	andi	$t8,$s1,0x7fff
/*  f15b6c0:	2711ffff */ 	addiu	$s1,$t8,-1
/*  f15b6c4:	3629000f */ 	ori	$t1,$s1,0xf
/*  f15b6c8:	25310001 */ 	addiu	$s1,$t1,0x1
/*  f15b6cc:	02212021 */ 	addu	$a0,$s1,$at
/*  f15b6d0:	0c0048f2 */ 	jal	malloc
/*  f15b6d4:	afb90050 */ 	sw	$t9,0x50($sp)
/*  f15b6d8:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f15b6dc:	8fa50028 */ 	lw	$a1,0x28($sp)
/*  f15b6e0:	34018000 */ 	dli	$at,0x8000
/*  f15b6e4:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f15b6e8:	00412021 */ 	addu	$a0,$v0,$at
/*  f15b6ec:	34ca000f */ 	ori	$t2,$a2,0xf
/*  f15b6f0:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f15b6f4:	00808025 */ 	or	$s0,$a0,$zero
/*  f15b6f8:	25460001 */ 	addiu	$a2,$t2,0x1
/*  f15b6fc:	0fc56c71 */ 	jal	func0f15b1c4
/*  f15b700:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f15b704:	02002025 */ 	or	$a0,$s0,$zero
/*  f15b708:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f15b70c:	0fc5766a */ 	jal	func0f15d9a8
/*  f15b710:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f15b714:	8fab002c */ 	lw	$t3,0x2c($sp)
/*  f15b718:	00001825 */ 	or	$v1,$zero,$zero
/*  f15b71c:	8fb00064 */ 	lw	$s0,0x64($sp)
/*  f15b720:	95710000 */ 	lhu	$s1,0x0($t3)
/*  f15b724:	322c7fff */ 	andi	$t4,$s1,0x7fff
/*  f15b728:	000c8843 */ 	sra	$s1,$t4,0x1
/*  f15b72c:	5220000b */ 	beqzl	$s1,.L0f15b75c
/*  f15b730:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f15b734:	96040000 */ 	lhu	$a0,0x0($s0)
.L0f15b738:
/*  f15b738:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f15b73c:	0fc5cd3a */ 	jal	func0f1734e8
/*  f15b740:	00002825 */ 	or	$a1,$zero,$zero
/*  f15b744:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f15b748:	26100002 */ 	addiu	$s0,$s0,0x2
/*  f15b74c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f15b750:	5471fff9 */ 	bnel	$v1,$s1,.L0f15b738
/*  f15b754:	96040000 */ 	lhu	$a0,0x0($s0)
/*  f15b758:	8fa40064 */ 	lw	$a0,0x64($sp)
.L0f15b75c:
/*  f15b75c:	00002825 */ 	or	$a1,$zero,$zero
/*  f15b760:	0c00490c */ 	jal	func00012430
/*  f15b764:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f15b768:	8fae0028 */ 	lw	$t6,0x28($sp)
/*  f15b76c:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f15b770:	3c01800a */ 	lui	$at,%hi(var800a4924)
/*  f15b774:	3c044fff */ 	lui	$a0,0x4fff
/*  f15b778:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f15b77c:	27190004 */ 	addiu	$t9,$t8,0x4
/*  f15b780:	ac394924 */ 	sw	$t9,%lo(var800a4924)($at)
/*  f15b784:	0fc56d47 */ 	jal	func0f15b51c
/*  f15b788:	3484fbab */ 	ori	$a0,$a0,0xfbab
/*  f15b78c:	3c04bbb7 */ 	lui	$a0,0xbbb7
/*  f15b790:	00408025 */ 	or	$s0,$v0,$zero
/*  f15b794:	0fc56d49 */ 	jal	xorBabebabe
/*  f15b798:	3484b295 */ 	ori	$a0,$a0,0xb295
/*  f15b79c:	00408825 */ 	or	$s1,$v0,$zero
/*  f15b7a0:	02002025 */ 	or	$a0,$s0,$zero
/*  f15b7a4:	0c013994 */ 	jal	func0004e650
/*  f15b7a8:	27a5003c */ 	addiu	$a1,$sp,0x3c
/*  f15b7ac:	8fa9003c */ 	lw	$t1,0x3c($sp)
/*  f15b7b0:	11310010 */ 	beq	$t1,$s1,.L0f15b7f4
/*  f15b7b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15b7b8:	0c004b70 */ 	jal	random
/*  f15b7bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15b7c0:	0c004b70 */ 	jal	random
/*  f15b7c4:	00408025 */ 	or	$s0,$v0,$zero
/*  f15b7c8:	3c010001 */ 	lui	$at,0x1
/*  f15b7cc:	3421fff8 */ 	ori	$at,$at,0xfff8
/*  f15b7d0:	02012024 */ 	and	$a0,$s0,$at
/*  f15b7d4:	3c018000 */ 	lui	$at,0x8000
/*  f15b7d8:	34211000 */ 	ori	$at,$at,0x1000
/*  f15b7dc:	00812021 */ 	addu	$a0,$a0,$at
/*  f15b7e0:	3c010001 */ 	lui	$at,0x1
/*  f15b7e4:	3421fffe */ 	ori	$at,$at,0xfffe
/*  f15b7e8:	00412824 */ 	and	$a1,$v0,$at
/*  f15b7ec:	0c003504 */ 	jal	func0000d410
/*  f15b7f0:	24060040 */ 	addiu	$a2,$zero,0x40
.L0f15b7f4:
/*  f15b7f4:	3c04800a */ 	lui	$a0,%hi(var800a491c)
/*  f15b7f8:	8c84491c */ 	lw	$a0,%lo(var800a491c)($a0)
/*  f15b7fc:	3c02800a */ 	lui	$v0,%hi(var800a4920)
/*  f15b800:	24424920 */ 	addiu	$v0,$v0,%lo(var800a4920)
/*  f15b804:	8c8a0000 */ 	lw	$t2,0x0($a0)
/*  f15b808:	3c07f100 */ 	lui	$a3,0xf100
/*  f15b80c:	3c08800a */ 	lui	$t0,%hi(var800a4cc4)
/*  f15b810:	15400038 */ 	bnez	$t2,.L0f15b8f4
/*  f15b814:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f15b818:	3c02800a */ 	lui	$v0,%hi(var800a4cc0)
/*  f15b81c:	24424cc0 */ 	addiu	$v0,$v0,%lo(var800a4cc0)
/*  f15b820:	ac440000 */ 	sw	$a0,0x0($v0)
/*  f15b824:	8c8c0004 */ 	lw	$t4,0x4($a0)
/*  f15b828:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f15b82c:	25084cc4 */ 	addiu	$t0,$t0,%lo(var800a4cc4)
/*  f15b830:	01846821 */ 	addu	$t5,$t4,$a0
/*  f15b834:	01a77021 */ 	addu	$t6,$t5,$a3
/*  f15b838:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f15b83c:	ad0e0000 */ 	sw	$t6,0x0($t0)
/*  f15b840:	ac6002bc */ 	sw	$zero,0x2bc($v1)
/*  f15b844:	8dcf0014 */ 	lw	$t7,0x14($t6)
/*  f15b848:	00802825 */ 	or	$a1,$a0,$zero
/*  f15b84c:	25c20014 */ 	addiu	$v0,$t6,0x14
/*  f15b850:	51e00009 */ 	beqzl	$t7,.L0f15b878
/*  f15b854:	8caa0008 */ 	lw	$t2,0x8($a1)
/*  f15b858:	8c7802bc */ 	lw	$t8,0x2bc($v1)
.L0f15b85c:
/*  f15b85c:	24420014 */ 	addiu	$v0,$v0,0x14
/*  f15b860:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f15b864:	ac7902bc */ 	sw	$t9,0x2bc($v1)
/*  f15b868:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f15b86c:	5520fffb */ 	bnezl	$t1,.L0f15b85c
/*  f15b870:	8c7802bc */ 	lw	$t8,0x2bc($v1)
/*  f15b874:	8caa0008 */ 	lw	$t2,0x8($a1)
.L0f15b878:
/*  f15b878:	3c01800a */ 	lui	$at,%hi(g_PortalSomethings)
/*  f15b87c:	01445821 */ 	addu	$t3,$t2,$a0
/*  f15b880:	01676021 */ 	addu	$t4,$t3,$a3
/*  f15b884:	ac2c4cc8 */ 	sw	$t4,%lo(g_PortalSomethings)($at)
/*  f15b888:	8ca2000c */ 	lw	$v0,0xc($a1)
/*  f15b88c:	3c01800a */ 	lui	$at,%hi(var800a4cd4)
/*  f15b890:	14400004 */ 	bnez	$v0,.L0f15b8a4
/*  f15b894:	00446821 */ 	addu	$t5,$v0,$a0
/*  f15b898:	3c01800a */ 	lui	$at,%hi(var800a4cd4)
/*  f15b89c:	10000003 */ 	beqz	$zero,.L0f15b8ac
/*  f15b8a0:	ac204cd4 */ 	sw	$zero,%lo(var800a4cd4)($at)
.L0f15b8a4:
/*  f15b8a4:	01a77021 */ 	addu	$t6,$t5,$a3
/*  f15b8a8:	ac2e4cd4 */ 	sw	$t6,%lo(var800a4cd4)($at)
.L0f15b8ac:
/*  f15b8ac:	8ca20010 */ 	lw	$v0,0x10($a1)
/*  f15b8b0:	3c01800a */ 	lui	$at,%hi(var800a4cd8)
/*  f15b8b4:	14400004 */ 	bnez	$v0,.L0f15b8c8
/*  f15b8b8:	00447821 */ 	addu	$t7,$v0,$a0
/*  f15b8bc:	3c01800a */ 	lui	$at,%hi(var800a4cd8)
/*  f15b8c0:	10000003 */ 	beqz	$zero,.L0f15b8d0
/*  f15b8c4:	ac204cd8 */ 	sw	$zero,%lo(var800a4cd8)($at)
.L0f15b8c8:
/*  f15b8c8:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f15b8cc:	ac384cd8 */ 	sw	$t8,%lo(var800a4cd8)($at)
.L0f15b8d0:
/*  f15b8d0:	8ca20014 */ 	lw	$v0,0x14($a1)
/*  f15b8d4:	3c01800a */ 	lui	$at,%hi(var800a4cdc)
/*  f15b8d8:	14400004 */ 	bnez	$v0,.L0f15b8ec
/*  f15b8dc:	0044c821 */ 	addu	$t9,$v0,$a0
/*  f15b8e0:	3c01800a */ 	lui	$at,%hi(var800a4cdc)
/*  f15b8e4:	10000003 */ 	beqz	$zero,.L0f15b8f4
/*  f15b8e8:	ac204cdc */ 	sw	$zero,%lo(var800a4cdc)($at)
.L0f15b8ec:
/*  f15b8ec:	03274821 */ 	addu	$t1,$t9,$a3
/*  f15b8f0:	ac294cdc */ 	sw	$t1,%lo(var800a4cdc)($at)
.L0f15b8f4:
/*  f15b8f4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f15b8f8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f15b8fc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f15b900:	03e00008 */ 	jr	$ra
/*  f15b904:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
);

GLOBAL_ASM(
glabel func0f15b908
.late_rodata
glabel var7f1b75cc
.word 0x7f7fffff
glabel var7f1b75d0
.word 0xff7fffff
.text
/*  f15b908:	27bdfeb8 */ 	addiu	$sp,$sp,-328
/*  f15b90c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f15b910:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f15b914:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f15b918:	afa40148 */ 	sw	$a0,0x148($sp)
/*  f15b91c:	8e6402bc */ 	lw	$a0,0x2bc($s3)
/*  f15b920:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f15b924:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f15b928:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f15b92c:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f15b930:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f15b934:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f15b938:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f15b93c:	25c4000f */ 	addiu	$a0,$t6,0xf
/*  f15b940:	348f000f */ 	ori	$t7,$a0,0xf
/*  f15b944:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f15b948:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f15b94c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f15b950:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f15b954:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f15b958:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f15b95c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f15b960:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f15b964:	0c0048f2 */ 	jal	malloc
/*  f15b968:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15b96c:	8e6402bc */ 	lw	$a0,0x2bc($s3)
/*  f15b970:	3c15800a */ 	lui	$s5,%hi(g_RoomPtrs)
/*  f15b974:	26b54928 */ 	addiu	$s5,$s5,%lo(g_RoomPtrs)
/*  f15b978:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f15b97c:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f15b980:	348e000f */ 	ori	$t6,$a0,0xf
/*  f15b984:	aea20000 */ 	sw	$v0,0x0($s5)
/*  f15b988:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f15b98c:	0c0048f2 */ 	jal	malloc
/*  f15b990:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15b994:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f15b998:	3c03800a */ 	lui	$v1,%hi(var800a4ce8)
/*  f15b99c:	24634ce8 */ 	addiu	$v1,$v1,%lo(var800a4ce8)
/*  f15b9a0:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f15b9a4:	1a200010 */ 	blez	$s1,.L0f15b9e8
/*  f15b9a8:	0000a025 */ 	or	$s4,$zero,$zero
/*  f15b9ac:	00001025 */ 	or	$v0,$zero,$zero
/*  f15b9b0:	3416ffff */ 	dli	$s6,0xffff
/*  f15b9b4:	8c780000 */ 	lw	$t8,0x0($v1)
.L0f15b9b8:
/*  f15b9b8:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15b9bc:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f15b9c0:	a7360000 */ 	sh	$s6,0x0($t9)
/*  f15b9c4:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f15b9c8:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f15b9cc:	a5e00002 */ 	sh	$zero,0x2($t7)
/*  f15b9d0:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f15b9d4:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f15b9d8:	0291082a */ 	slt	$at,$s4,$s1
/*  f15b9dc:	5420fff6 */ 	bnezl	$at,.L0f15b9b8
/*  f15b9e0:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f15b9e4:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15b9e8:
/*  f15b9e8:	8e780314 */ 	lw	$t8,0x314($s3)
/*  f15b9ec:	13000013 */ 	beqz	$t8,.L0f15ba3c
/*  f15b9f0:	2624000f */ 	addiu	$a0,$s1,0xf
/*  f15b9f4:	3499000f */ 	ori	$t9,$a0,0xf
/*  f15b9f8:	3b24000f */ 	xori	$a0,$t9,0xf
/*  f15b9fc:	0c0048f2 */ 	jal	malloc
/*  f15ba00:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15ba04:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f15ba08:	3c03800a */ 	lui	$v1,%hi(g_MpRoomVisibility)
/*  f15ba0c:	2463492c */ 	addiu	$v1,$v1,%lo(g_MpRoomVisibility)
/*  f15ba10:	1a20000a */ 	blez	$s1,.L0f15ba3c
/*  f15ba14:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f15ba18:	8c6f0000 */ 	lw	$t7,0x0($v1)
.L0f15ba1c:
/*  f15ba1c:	01f4c021 */ 	addu	$t8,$t7,$s4
/*  f15ba20:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f15ba24:	8e7102bc */ 	lw	$s1,0x2bc($s3)
/*  f15ba28:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15ba2c:	0291082a */ 	slt	$at,$s4,$s1
/*  f15ba30:	5420fffa */ 	bnezl	$at,.L0f15ba1c
/*  f15ba34:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f15ba38:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15ba3c:
/*  f15ba3c:	1a200020 */ 	blez	$s1,.L0f15bac0
/*  f15ba40:	00009025 */ 	or	$s2,$zero,$zero
/*  f15ba44:	8eb90000 */ 	lw	$t9,0x0($s5)
.L0f15ba48:
/*  f15ba48:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15ba4c:	03327021 */ 	addu	$t6,$t9,$s2
/*  f15ba50:	adc00044 */ 	sw	$zero,0x44($t6)
/*  f15ba54:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15ba58:	01f2c021 */ 	addu	$t8,$t7,$s2
/*  f15ba5c:	a3000008 */ 	sb	$zero,0x8($t8)
/*  f15ba60:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15ba64:	03327021 */ 	addu	$t6,$t9,$s2
/*  f15ba68:	a5c0000a */ 	sh	$zero,0xa($t6)
/*  f15ba6c:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15ba70:	01f2c021 */ 	addu	$t8,$t7,$s2
/*  f15ba74:	a7000000 */ 	sh	$zero,0x0($t8)
/*  f15ba78:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15ba7c:	03327021 */ 	addu	$t6,$t9,$s2
/*  f15ba80:	a1c0004d */ 	sb	$zero,0x4d($t6)
/*  f15ba84:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15ba88:	01f26021 */ 	addu	$t4,$t7,$s2
/*  f15ba8c:	9198004e */ 	lbu	$t8,0x4e($t4)
/*  f15ba90:	3319ff0f */ 	andi	$t9,$t8,0xff0f
/*  f15ba94:	a199004e */ 	sb	$t9,0x4e($t4)
/*  f15ba98:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15ba9c:	01d26021 */ 	addu	$t4,$t6,$s2
/*  f15baa0:	918f004e */ 	lbu	$t7,0x4e($t4)
/*  f15baa4:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f15baa8:	31f8fff0 */ 	andi	$t8,$t7,0xfff0
/*  f15baac:	a198004e */ 	sb	$t8,0x4e($t4)
/*  f15bab0:	8e7902bc */ 	lw	$t9,0x2bc($s3)
/*  f15bab4:	0299082a */ 	slt	$at,$s4,$t9
/*  f15bab8:	5420ffe3 */ 	bnezl	$at,.L0f15ba48
/*  f15babc:	8eb90000 */ 	lw	$t9,0x0($s5)
.L0f15bac0:
/*  f15bac0:	3c118008 */ 	lui	$s1,%hi(g_StageIndex)
/*  f15bac4:	2631fc00 */ 	addiu	$s1,$s1,%lo(g_StageIndex)
/*  f15bac8:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f15bacc:	24120038 */ 	addiu	$s2,$zero,0x38
/*  f15bad0:	3c108008 */ 	lui	$s0,%hi(g_Stages)
/*  f15bad4:	01d20019 */ 	multu	$t6,$s2
/*  f15bad8:	2610fcc0 */ 	addiu	$s0,$s0,%lo(g_Stages)
/*  f15badc:	00007812 */ 	mflo	$t7
/*  f15bae0:	020fc021 */ 	addu	$t8,$s0,$t7
/*  f15bae4:	0fc57220 */ 	jal	func0f15c880
/*  f15bae8:	c70c0014 */ 	lwc1	$f12,0x14($t8)
/*  f15baec:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f15baf0:	03320019 */ 	multu	$t9,$s2
/*  f15baf4:	00007012 */ 	mflo	$t6
/*  f15baf8:	020e7821 */ 	addu	$t7,$s0,$t6
/*  f15bafc:	0fc0a124 */ 	jal	func0f028490
/*  f15bb00:	c5ec0014 */ 	lwc1	$f12,0x14($t7)
/*  f15bb04:	3c188008 */ 	lui	$t8,%hi(g_StageIndex)
/*  f15bb08:	8f18fc00 */ 	lw	$t8,%lo(g_StageIndex)($t8)
/*  f15bb0c:	3c018008 */ 	lui	$at,0x8008
/*  f15bb10:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f15bb14:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f15bb18:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f15bb1c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f15bb20:	00390821 */ 	addu	$at,$at,$t9
/*  f15bb24:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x200)
/*  f15bb28:	2463a1c0 */ 	addiu	$v1,$v1,%lo(g_Vars+0x200)
/*  f15bb2c:	c420fcd8 */ 	lwc1	$f0,-0x328($at)
/*  f15bb30:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
.L0f15bb34:
/*  f15bb34:	24420080 */ 	addiu	$v0,$v0,0x80
/*  f15bb38:	0043082b */ 	sltu	$at,$v0,$v1
/*  f15bb3c:	1420fffd */ 	bnez	$at,.L0f15bb34
/*  f15bb40:	e4400068 */ 	swc1	$f0,0x68($v0)
/*  f15bb44:	3c013f80 */ 	lui	$at,0x3f80
/*  f15bb48:	44816000 */ 	mtc1	$at,$f12
/*  f15bb4c:	0c0059d2 */ 	jal	func00016748
/*  f15bb50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15bb54:	3c0e800a */ 	lui	$t6,%hi(var800a4920)
/*  f15bb58:	8dce4920 */ 	lw	$t6,%lo(var800a4920)($t6)
/*  f15bb5c:	3c17800a */ 	lui	$s7,%hi(g_PortalSomethings)
/*  f15bb60:	26f74cc8 */ 	addiu	$s7,$s7,%lo(g_PortalSomethings)
/*  f15bb64:	15c00324 */ 	bnez	$t6,.L0f15c7f8
/*  f15bb68:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15bb6c:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f15bb70:	0000f025 */ 	or	$s8,$zero,$zero
/*  f15bb74:	960f0000 */ 	lhu	$t7,0x0($s0)
/*  f15bb78:	11e00006 */ 	beqz	$t7,.L0f15bb94
/*  f15bb7c:	02001025 */ 	or	$v0,$s0,$zero
/*  f15bb80:	94580008 */ 	lhu	$t8,0x8($v0)
.L0f15bb84:
/*  f15bb84:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f15bb88:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f15bb8c:	5700fffd */ 	bnezl	$t8,.L0f15bb84
/*  f15bb90:	94580008 */ 	lhu	$t8,0x8($v0)
.L0f15bb94:
/*  f15bb94:	001ec900 */ 	sll	$t9,$s8,0x4
/*  f15bb98:	3c028008 */ 	lui	$v0,%hi(g_NumPortals)
/*  f15bb9c:	2724000f */ 	addiu	$a0,$t9,0xf
/*  f15bba0:	2442fc40 */ 	addiu	$v0,$v0,%lo(g_NumPortals)
/*  f15bba4:	348e000f */ 	ori	$t6,$a0,0xf
/*  f15bba8:	ac5e0000 */ 	sw	$s8,0x0($v0)
/*  f15bbac:	0c0048f2 */ 	jal	malloc
/*  f15bbb0:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f15bbb4:	3c01800a */ 	lui	$at,%hi(g_Portals)
/*  f15bbb8:	ac224cec */ 	sw	$v0,%lo(g_Portals)($at)
/*  f15bbbc:	001e20c0 */ 	sll	$a0,$s8,0x3
/*  f15bbc0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f15bbc4:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f15bbc8:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15bbcc:	0000b025 */ 	or	$s6,$zero,$zero
/*  f15bbd0:	2412000c */ 	addiu	$s2,$zero,0xc
.L0f15bbd4:
/*  f15bbd4:	1bc0000b */ 	blez	$s8,.L0f15bc04
/*  f15bbd8:	00001825 */ 	or	$v1,$zero,$zero
.L0f15bbdc:
/*  f15bbdc:	02031021 */ 	addu	$v0,$s0,$v1
/*  f15bbe0:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f15bbe4:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f15bbe8:	16980003 */ 	bne	$s4,$t8,.L0f15bbf8
/*  f15bbec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15bbf0:	a4440000 */ 	sh	$a0,0x0($v0)
/*  f15bbf4:	8ef00000 */ 	lw	$s0,0x0($s7)
.L0f15bbf8:
/*  f15bbf8:	16defff8 */ 	bne	$s6,$s8,.L0f15bbdc
/*  f15bbfc:	24630008 */ 	addiu	$v1,$v1,8
/*  f15bc00:	0000b025 */ 	or	$s6,$zero,$zero
.L0f15bc04:
/*  f15bc04:	02048821 */ 	addu	$s1,$s0,$a0
/*  f15bc08:	92250000 */ 	lbu	$a1,0x0($s1)
/*  f15bc0c:	18a00007 */ 	blez	$a1,.L0f15bc2c
/*  f15bc10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15bc14:	00b20019 */ 	multu	$a1,$s2
/*  f15bc18:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15bc1c:	0000c812 */ 	mflo	$t9
/*  f15bc20:	00992021 */ 	addu	$a0,$a0,$t9
/*  f15bc24:	1000ffeb */ 	beqz	$zero,.L0f15bbd4
/*  f15bc28:	24840004 */ 	addiu	$a0,$a0,0x4
.L0f15bc2c:
/*  f15bc2c:	17c00003 */ 	bnez	$s8,.L0f15bc3c
/*  f15bc30:	00008025 */ 	or	$s0,$zero,$zero
/*  f15bc34:	10000002 */ 	beqz	$zero,.L0f15bc40
/*  f15bc38:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f15bc3c:
/*  f15bc3c:	03c01025 */ 	or	$v0,$s8,$zero
.L0f15bc40:
/*  f15bc40:	00022080 */ 	sll	$a0,$v0,0x2
/*  f15bc44:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f15bc48:	348e000f */ 	ori	$t6,$a0,0xf
/*  f15bc4c:	39c4000f */ 	xori	$a0,$t6,0xf
/*  f15bc50:	0c0048f2 */ 	jal	malloc
/*  f15bc54:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15bc58:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f15bc5c:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f15bc60:	8cb102bc */ 	lw	$s1,0x2bc($a1)
/*  f15bc64:	3c13800a */ 	lui	$s3,%hi(var800a4ce0)
/*  f15bc68:	26734ce0 */ 	addiu	$s3,$s3,%lo(var800a4ce0)
/*  f15bc6c:	ae620000 */ 	sw	$v0,0x0($s3)
/*  f15bc70:	aca0002c */ 	sw	$zero,0x2c($a1)
/*  f15bc74:	1a200033 */ 	blez	$s1,.L0f15bd44
/*  f15bc78:	0000a025 */ 	or	$s4,$zero,$zero
/*  f15bc7c:	00009025 */ 	or	$s2,$zero,$zero
/*  f15bc80:	8eb80000 */ 	lw	$t8,0x0($s5)
.L0f15bc84:
/*  f15bc84:	00002025 */ 	or	$a0,$zero,$zero
/*  f15bc88:	00001825 */ 	or	$v1,$zero,$zero
/*  f15bc8c:	0312c821 */ 	addu	$t9,$t8,$s2
/*  f15bc90:	1bc0001d */ 	blez	$s8,.L0f15bd08
/*  f15bc94:	a730000e */ 	sh	$s0,0xe($t9)
.L0f15bc98:
/*  f15bc98:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f15bc9c:	01c31021 */ 	addu	$v0,$t6,$v1
/*  f15bca0:	844f0002 */ 	lh	$t7,0x2($v0)
/*  f15bca4:	568f000a */ 	bnel	$s4,$t7,.L0f15bcd0
/*  f15bca8:	84580004 */ 	lh	$t8,0x4($v0)
/*  f15bcac:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f15bcb0:	0010c840 */ 	sll	$t9,$s0,0x1
/*  f15bcb4:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f15bcb8:	03197021 */ 	addu	$t6,$t8,$t9
/*  f15bcbc:	a5d60000 */ 	sh	$s6,0x0($t6)
/*  f15bcc0:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f15bcc4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15bcc8:	01e31021 */ 	addu	$v0,$t7,$v1
/*  f15bccc:	84580004 */ 	lh	$t8,0x4($v0)
.L0f15bcd0:
/*  f15bcd0:	00107040 */ 	sll	$t6,$s0,0x1
/*  f15bcd4:	56980007 */ 	bnel	$s4,$t8,.L0f15bcf4
/*  f15bcd8:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f15bcdc:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15bce0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f15bce4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15bce8:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f15bcec:	a5f60000 */ 	sh	$s6,0x0($t7)
/*  f15bcf0:	26d60001 */ 	addiu	$s6,$s6,0x1
.L0f15bcf4:
/*  f15bcf4:	16deffe8 */ 	bne	$s6,$s8,.L0f15bc98
/*  f15bcf8:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f15bcfc:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f15bd00:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f15bd04:	0000b025 */ 	or	$s6,$zero,$zero
.L0f15bd08:
/*  f15bd08:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15bd0c:	0312c821 */ 	addu	$t9,$t8,$s2
/*  f15bd10:	a3240005 */ 	sb	$a0,0x5($t9)
/*  f15bd14:	8cae002c */ 	lw	$t6,0x2c($a1)
/*  f15bd18:	01c4082a */ 	slt	$at,$t6,$a0
/*  f15bd1c:	50200003 */ 	beqzl	$at,.L0f15bd2c
/*  f15bd20:	8cb102bc */ 	lw	$s1,0x2bc($a1)
/*  f15bd24:	aca4002c */ 	sw	$a0,0x2c($a1)
/*  f15bd28:	8cb102bc */ 	lw	$s1,0x2bc($a1)
.L0f15bd2c:
/*  f15bd2c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15bd30:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f15bd34:	0291082a */ 	slt	$at,$s4,$s1
/*  f15bd38:	5420ffd2 */ 	bnezl	$at,.L0f15bc84
/*  f15bd3c:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15bd40:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15bd44:
/*  f15bd44:	1a200058 */ 	blez	$s1,.L0f15bea8
/*  f15bd48:	00009025 */ 	or	$s2,$zero,$zero
/*  f15bd4c:	8eac0000 */ 	lw	$t4,0x0($s5)
.L0f15bd50:
/*  f15bd50:	818b0005 */ 	lb	$t3,0x5($t4)
/*  f15bd54:	5960004f */ 	blezl	$t3,.L0f15be94
/*  f15bd58:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15bd5c:	8598000e */ 	lh	$t8,0xe($t4)
/*  f15bd60:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f15bd64:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f15bd68:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f15bd6c:	01f96821 */ 	addu	$t5,$t7,$t9
/*  f15bd70:	01a0f825 */ 	or	$ra,$t5,$zero
/*  f15bd74:	00008825 */ 	or	$s1,$zero,$zero
.L0f15bd78:
/*  f15bd78:	87ea0000 */ 	lh	$t2,0x0($ra)
/*  f15bd7c:	02cb082a */ 	slt	$at,$s6,$t3
/*  f15bd80:	000a70c0 */ 	sll	$t6,$t2,0x3
/*  f15bd84:	020e1821 */ 	addu	$v1,$s0,$t6
/*  f15bd88:	84640002 */ 	lh	$a0,0x2($v1)
/*  f15bd8c:	16840003 */ 	bne	$s4,$a0,.L0f15bd9c
/*  f15bd90:	00803825 */ 	or	$a3,$a0,$zero
/*  f15bd94:	10000001 */ 	beqz	$zero,.L0f15bd9c
/*  f15bd98:	84670004 */ 	lh	$a3,0x4($v1)
.L0f15bd9c:
/*  f15bd9c:	10200034 */ 	beqz	$at,.L0f15be70
/*  f15bda0:	02c04025 */ 	or	$t0,$s6,$zero
/*  f15bda4:	00084840 */ 	sll	$t1,$t0,0x1
.L0f15bda8:
/*  f15bda8:	01a92821 */ 	addu	$a1,$t5,$t1
/*  f15bdac:	84a60000 */ 	lh	$a2,0x0($a1)
/*  f15bdb0:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f15bdb4:	00002025 */ 	or	$a0,$zero,$zero
/*  f15bdb8:	0006c0c0 */ 	sll	$t8,$a2,0x3
/*  f15bdbc:	02181021 */ 	addu	$v0,$s0,$t8
/*  f15bdc0:	84430002 */ 	lh	$v1,0x2($v0)
/*  f15bdc4:	16830007 */ 	bne	$s4,$v1,.L0f15bde4
/*  f15bdc8:	0067082a */ 	slt	$at,$v1,$a3
/*  f15bdcc:	844f0004 */ 	lh	$t7,0x4($v0)
/*  f15bdd0:	01e7082a */ 	slt	$at,$t7,$a3
/*  f15bdd4:	10200006 */ 	beqz	$at,.L0f15bdf0
/*  f15bdd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15bddc:	10000004 */ 	beqz	$zero,.L0f15bdf0
/*  f15bde0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f15bde4:
/*  f15bde4:	10200002 */ 	beqz	$at,.L0f15bdf0
/*  f15bde8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15bdec:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f15bdf0:
/*  f15bdf0:	5080001d */ 	beqzl	$a0,.L0f15be68
/*  f15bdf4:	010b082a */ 	slt	$at,$t0,$t3
/*  f15bdf8:	a4aa0000 */ 	sh	$t2,0x0($a1)
/*  f15bdfc:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15be00:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15be04:	01d2c021 */ 	addu	$t8,$t6,$s2
/*  f15be08:	870f000e */ 	lh	$t7,0xe($t8)
/*  f15be0c:	000f7040 */ 	sll	$t6,$t7,0x1
/*  f15be10:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f15be14:	03117821 */ 	addu	$t7,$t8,$s1
/*  f15be18:	a5e60000 */ 	sh	$a2,0x0($t7)
/*  f15be1c:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15be20:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f15be24:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f15be28:	03326021 */ 	addu	$t4,$t9,$s2
/*  f15be2c:	8598000e */ 	lh	$t8,0xe($t4)
/*  f15be30:	00187840 */ 	sll	$t7,$t8,0x1
/*  f15be34:	01cf6821 */ 	addu	$t5,$t6,$t7
/*  f15be38:	01b1f821 */ 	addu	$ra,$t5,$s1
/*  f15be3c:	87ea0000 */ 	lh	$t2,0x0($ra)
/*  f15be40:	000ac8c0 */ 	sll	$t9,$t2,0x3
/*  f15be44:	02191821 */ 	addu	$v1,$s0,$t9
/*  f15be48:	84640002 */ 	lh	$a0,0x2($v1)
/*  f15be4c:	16840004 */ 	bne	$s4,$a0,.L0f15be60
/*  f15be50:	00803825 */ 	or	$a3,$a0,$zero
/*  f15be54:	84670004 */ 	lh	$a3,0x4($v1)
/*  f15be58:	10000002 */ 	beqz	$zero,.L0f15be64
/*  f15be5c:	818b0005 */ 	lb	$t3,0x5($t4)
.L0f15be60:
/*  f15be60:	818b0005 */ 	lb	$t3,0x5($t4)
.L0f15be64:
/*  f15be64:	010b082a */ 	slt	$at,$t0,$t3
.L0f15be68:
/*  f15be68:	1420ffcf */ 	bnez	$at,.L0f15bda8
/*  f15be6c:	25290002 */ 	addiu	$t1,$t1,0x2
.L0f15be70:
/*  f15be70:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f15be74:	02cb082a */ 	slt	$at,$s6,$t3
/*  f15be78:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f15be7c:	1420ffbe */ 	bnez	$at,.L0f15bd78
/*  f15be80:	27ff0002 */ 	addiu	$ra,$ra,0x2
/*  f15be84:	3c11800a */ 	lui	$s1,%hi(g_Vars+0x2bc)
/*  f15be88:	8e31a27c */ 	lw	$s1,%lo(g_Vars+0x2bc)($s1)
/*  f15be8c:	0000b025 */ 	or	$s6,$zero,$zero
/*  f15be90:	26940001 */ 	addiu	$s4,$s4,0x1
.L0f15be94:
/*  f15be94:	0291082a */ 	slt	$at,$s4,$s1
/*  f15be98:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f15be9c:	1420ffac */ 	bnez	$at,.L0f15bd50
/*  f15bea0:	258c008c */ 	addiu	$t4,$t4,0x8c
/*  f15bea4:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15bea8:
/*  f15bea8:	17c00003 */ 	bnez	$s8,.L0f15beb8
/*  f15beac:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15beb0:	10000002 */ 	beqz	$zero,.L0f15bebc
/*  f15beb4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f15beb8:
/*  f15beb8:	03c01025 */ 	or	$v0,$s8,$zero
.L0f15bebc:
/*  f15bebc:	2444000f */ 	addiu	$a0,$v0,0xf
/*  f15bec0:	3498000f */ 	ori	$t8,$a0,0xf
/*  f15bec4:	0c0048f2 */ 	jal	malloc
/*  f15bec8:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f15becc:	3c10800a */ 	lui	$s0,%hi(var800a4cd0)
/*  f15bed0:	26104cd0 */ 	addiu	$s0,$s0,%lo(var800a4cd0)
/*  f15bed4:	1bc00009 */ 	blez	$s8,.L0f15befc
/*  f15bed8:	ae020000 */ 	sw	$v0,0x0($s0)
.L0f15bedc:
/*  f15bedc:	0fc56d30 */ 	jal	func0f15b4c0
/*  f15bee0:	02802025 */ 	or	$a0,$s4,$zero
/*  f15bee4:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f15bee8:	01f4c821 */ 	addu	$t9,$t7,$s4
/*  f15beec:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15bef0:	169efffa */ 	bne	$s4,$s8,.L0f15bedc
/*  f15bef4:	a3220000 */ 	sb	$v0,0x0($t9)
/*  f15bef8:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15befc:
/*  f15befc:	001e2080 */ 	sll	$a0,$s8,0x2
/*  f15bf00:	009e2021 */ 	addu	$a0,$a0,$s8
/*  f15bf04:	00042080 */ 	sll	$a0,$a0,0x2
/*  f15bf08:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f15bf0c:	3498000f */ 	ori	$t8,$a0,0xf
/*  f15bf10:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f15bf14:	0c0048f2 */ 	jal	malloc
/*  f15bf18:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15bf1c:	3c01800a */ 	lui	$at,%hi(var800a4ccc)
/*  f15bf20:	1bc00095 */ 	blez	$s8,.L0f15c178
/*  f15bf24:	ac224ccc */ 	sw	$v0,%lo(var800a4ccc)($at)
/*  f15bf28:	44808000 */ 	mtc1	$zero,$f16
/*  f15bf2c:	00009025 */ 	or	$s2,$zero,$zero
/*  f15bf30:	00003025 */ 	or	$a2,$zero,$zero
/*  f15bf34:	2413000c */ 	addiu	$s3,$zero,0xc
.L0f15bf38:
/*  f15bf38:	8ef00000 */ 	lw	$s0,0x0($s7)
/*  f15bf3c:	e7b000f8 */ 	swc1	$f16,0xf8($sp)
/*  f15bf40:	e7b000fc */ 	swc1	$f16,0xfc($sp)
/*  f15bf44:	e7b00100 */ 	swc1	$f16,0x100($sp)
/*  f15bf48:	02127821 */ 	addu	$t7,$s0,$s2
/*  f15bf4c:	95f90000 */ 	lhu	$t9,0x0($t7)
/*  f15bf50:	03308821 */ 	addu	$s1,$t9,$s0
/*  f15bf54:	92250000 */ 	lbu	$a1,0x0($s1)
/*  f15bf58:	02201825 */ 	or	$v1,$s1,$zero
/*  f15bf5c:	18a00035 */ 	blez	$a1,.L0f15c034
/*  f15bf60:	26c40001 */ 	addiu	$a0,$s6,0x1
.L0f15bf64:
/*  f15bf64:	0085001a */ 	div	$zero,$a0,$a1
/*  f15bf68:	0000c010 */ 	mfhi	$t8
/*  f15bf6c:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f15bf70:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f15bf74:	03130019 */ 	multu	$t8,$s3
/*  f15bf78:	0080b025 */ 	or	$s6,$a0,$zero
/*  f15bf7c:	14a00002 */ 	bnez	$a1,.L0f15bf88
/*  f15bf80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15bf84:	0007000d */ 	break	0x7
.L0f15bf88:
/*  f15bf88:	2401ffff */ 	addiu	$at,$zero,-1
/*  f15bf8c:	14a10004 */ 	bne	$a1,$at,.L0f15bfa0
/*  f15bf90:	3c018000 */ 	lui	$at,0x8000
/*  f15bf94:	14810002 */ 	bne	$a0,$at,.L0f15bfa0
/*  f15bf98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15bf9c:	0006000d */ 	break	0x6
.L0f15bfa0:
/*  f15bfa0:	00007012 */ 	mflo	$t6
/*  f15bfa4:	022e1021 */ 	addu	$v0,$s1,$t6
/*  f15bfa8:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f15bfac:	c452000c */ 	lwc1	$f18,0xc($v0)
/*  f15bfb0:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f15bfb4:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f15bfb8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f15bfbc:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f15bfc0:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f15bfc4:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f15bfc8:	46065480 */ 	add.s	$f18,$f10,$f6
/*  f15bfcc:	e7b200f8 */ 	swc1	$f18,0xf8($sp)
/*  f15bfd0:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f15bfd4:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*  f15bfd8:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f15bfdc:	c466fff8 */ 	lwc1	$f6,-0x8($v1)
/*  f15bfe0:	46044281 */ 	sub.s	$f10,$f8,$f4
/*  f15bfe4:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f15bfe8:	c7a600fc */ 	lwc1	$f6,0xfc($sp)
/*  f15bfec:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f15bff0:	46043480 */ 	add.s	$f18,$f6,$f4
/*  f15bff4:	e7b200fc */ 	swc1	$f18,0xfc($sp)
/*  f15bff8:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f15bffc:	c46afff8 */ 	lwc1	$f10,-0x8($v1)
/*  f15c000:	c4520004 */ 	lwc1	$f18,0x4($v0)
/*  f15c004:	c464fffc */ 	lwc1	$f4,-0x4($v1)
/*  f15c008:	46085181 */ 	sub.s	$f6,$f10,$f8
/*  f15c00c:	46122280 */ 	add.s	$f10,$f4,$f18
/*  f15c010:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f15c014:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f15c018:	46082480 */ 	add.s	$f18,$f4,$f8
/*  f15c01c:	e7b20100 */ 	swc1	$f18,0x100($sp)
/*  f15c020:	92250000 */ 	lbu	$a1,0x0($s1)
/*  f15c024:	0085082a */ 	slt	$at,$a0,$a1
/*  f15c028:	5420ffce */ 	bnezl	$at,.L0f15bf64
/*  f15c02c:	26c40001 */ 	addiu	$a0,$s6,0x1
/*  f15c030:	0000b025 */ 	or	$s6,$zero,$zero
.L0f15c034:
/*  f15c034:	c7a000f8 */ 	lwc1	$f0,0xf8($sp)
/*  f15c038:	c7a200fc */ 	lwc1	$f2,0xfc($sp)
/*  f15c03c:	c7ae0100 */ 	lwc1	$f14,0x100($sp)
/*  f15c040:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f15c044:	afa60064 */ 	sw	$a2,0x64($sp)
/*  f15c048:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f15c04c:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f15c050:	460e7202 */ 	mul.s	$f8,$f14,$f14
/*  f15c054:	0c012974 */ 	jal	sqrtf
/*  f15c058:	46044300 */ 	add.s	$f12,$f8,$f4
/*  f15c05c:	c7b200f8 */ 	lwc1	$f18,0xf8($sp)
/*  f15c060:	46000087 */ 	neg.s	$f2,$f0
/*  f15c064:	c7aa00fc */ 	lwc1	$f10,0xfc($sp)
/*  f15c068:	46029183 */ 	div.s	$f6,$f18,$f2
/*  f15c06c:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f15c070:	3c017f1b */ 	lui	$at,%hi(var7f1b75cc)
/*  f15c074:	44808000 */ 	mtc1	$zero,$f16
/*  f15c078:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f15c07c:	02201825 */ 	or	$v1,$s1,$zero
/*  f15c080:	3c18800a */ 	lui	$t8,%hi(var800a4ccc)
/*  f15c084:	46025203 */ 	div.s	$f8,$f10,$f2
/*  f15c088:	e7a600f8 */ 	swc1	$f6,0xf8($sp)
/*  f15c08c:	c42675cc */ 	lwc1	$f6,%lo(var7f1b75cc)($at)
/*  f15c090:	3c017f1b */ 	lui	$at,%hi(var7f1b75d0)
/*  f15c094:	c42a75d0 */ 	lwc1	$f10,%lo(var7f1b75d0)($at)
/*  f15c098:	e7a60104 */ 	swc1	$f6,0x104($sp)
/*  f15c09c:	e7aa0108 */ 	swc1	$f10,0x108($sp)
/*  f15c0a0:	46022483 */ 	div.s	$f18,$f4,$f2
/*  f15c0a4:	e7a800fc */ 	swc1	$f8,0xfc($sp)
/*  f15c0a8:	e7b20100 */ 	swc1	$f18,0x100($sp)
/*  f15c0ac:	922f0000 */ 	lbu	$t7,0x0($s1)
/*  f15c0b0:	19e00020 */ 	blez	$t7,.L0f15c134
/*  f15c0b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c0b8:	c4680004 */ 	lwc1	$f8,0x4($v1)
.L0f15c0bc:
/*  f15c0bc:	c7a400f8 */ 	lwc1	$f4,0xf8($sp)
/*  f15c0c0:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f15c0c4:	c7aa00fc */ 	lwc1	$f10,0xfc($sp)
/*  f15c0c8:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f15c0cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c0d0:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f15c0d4:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f15c0d8:	c7a60100 */ 	lwc1	$f6,0x100($sp)
/*  f15c0dc:	46089100 */ 	add.s	$f4,$f18,$f8
/*  f15c0e0:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f15c0e4:	c7a80104 */ 	lwc1	$f8,0x104($sp)
/*  f15c0e8:	46049000 */ 	add.s	$f0,$f18,$f4
/*  f15c0ec:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15c0f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c0f4:	45000002 */ 	bc1f	.L0f15c100
/*  f15c0f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c0fc:	e7a00104 */ 	swc1	$f0,0x104($sp)
.L0f15c100:
/*  f15c100:	c7a60108 */ 	lwc1	$f6,0x108($sp)
/*  f15c104:	4600303c */ 	c.lt.s	$f6,$f0
/*  f15c108:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c10c:	45020003 */ 	bc1fl	.L0f15c11c
/*  f15c110:	92390000 */ 	lbu	$t9,0x0($s1)
/*  f15c114:	e7a00108 */ 	swc1	$f0,0x108($sp)
/*  f15c118:	92390000 */ 	lbu	$t9,0x0($s1)
.L0f15c11c:
/*  f15c11c:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f15c120:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f15c124:	02d9082a */ 	slt	$at,$s6,$t9
/*  f15c128:	5420ffe4 */ 	bnezl	$at,.L0f15c0bc
/*  f15c12c:	c4680004 */ 	lwc1	$f8,0x4($v1)
/*  f15c130:	0000b025 */ 	or	$s6,$zero,$zero
.L0f15c134:
/*  f15c134:	8f184ccc */ 	lw	$t8,%lo(var800a4ccc)($t8)
/*  f15c138:	c7aa00f8 */ 	lwc1	$f10,0xf8($sp)
/*  f15c13c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c140:	00d81021 */ 	addu	$v0,$a2,$t8
/*  f15c144:	e44a0000 */ 	swc1	$f10,0x0($v0)
/*  f15c148:	c7b200fc */ 	lwc1	$f18,0xfc($sp)
/*  f15c14c:	24c60014 */ 	addiu	$a2,$a2,0x14
/*  f15c150:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f15c154:	e4520004 */ 	swc1	$f18,0x4($v0)
/*  f15c158:	c7a40100 */ 	lwc1	$f4,0x100($sp)
/*  f15c15c:	e4440008 */ 	swc1	$f4,0x8($v0)
/*  f15c160:	c7a80104 */ 	lwc1	$f8,0x104($sp)
/*  f15c164:	e448000c */ 	swc1	$f8,0xc($v0)
/*  f15c168:	c7a60108 */ 	lwc1	$f6,0x108($sp)
/*  f15c16c:	169eff72 */ 	bne	$s4,$s8,.L0f15bf38
/*  f15c170:	e4460010 */ 	swc1	$f6,0x10($v0)
/*  f15c174:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15c178:
/*  f15c178:	0fc2d96a */ 	jal	func0f0b65a8
/*  f15c17c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f15c180:	3c1e800a */ 	lui	$s8,%hi(var800a4cd4)
/*  f15c184:	27de4cd4 */ 	addiu	$s8,$s8,%lo(var800a4cd4)
/*  f15c188:	8fc30000 */ 	lw	$v1,0x0($s8)
/*  f15c18c:	1060001c */ 	beqz	$v1,.L0f15c200
/*  f15c190:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c194:	906e0000 */ 	lbu	$t6,0x0($v1)
/*  f15c198:	00009025 */ 	or	$s2,$zero,$zero
/*  f15c19c:	00608025 */ 	or	$s0,$v1,$zero
/*  f15c1a0:	11c00017 */ 	beqz	$t6,.L0f15c200
/*  f15c1a4:	31c200ff */ 	andi	$v0,$t6,0xff
/*  f15c1a8:	3c13800a */ 	lui	$s3,%hi(var800a491c)
/*  f15c1ac:	2673491c */ 	addiu	$s3,$s3,%lo(var800a491c)
/*  f15c1b0:	3c14f100 */ 	lui	$s4,0xf100
/*  f15c1b4:	24110064 */ 	addiu	$s1,$zero,0x64
.L0f15c1b8:
/*  f15c1b8:	5622000c */ 	bnel	$s1,$v0,.L0f15c1ec
/*  f15c1bc:	92020008 */ 	lbu	$v0,0x8($s0)
/*  f15c1c0:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f15c1c4:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15c1c8:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f15c1cc:	0fc5761c */ 	jal	func0f15d870
/*  f15c1d0:	03142021 */ 	addu	$a0,$t8,$s4
/*  f15c1d4:	8fce0000 */ 	lw	$t6,0x0($s8)
/*  f15c1d8:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c1dc:	ade20004 */ 	sw	$v0,0x4($t7)
/*  f15c1e0:	8fd90000 */ 	lw	$t9,0x0($s8)
/*  f15c1e4:	03328021 */ 	addu	$s0,$t9,$s2
/*  f15c1e8:	92020008 */ 	lbu	$v0,0x8($s0)
.L0f15c1ec:
/*  f15c1ec:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f15c1f0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15c1f4:	1440fff0 */ 	bnez	$v0,.L0f15c1b8
/*  f15c1f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c1fc:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15c200:
/*  f15c200:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f15c204:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f15c208:	8e7802bc */ 	lw	$t8,0x2bc($s3)
/*  f15c20c:	1b000021 */ 	blez	$t8,.L0f15c294
/*  f15c210:	00009025 */ 	or	$s2,$zero,$zero
/*  f15c214:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f15c218:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f15c21c:	8eae0000 */ 	lw	$t6,0x0($s5)
.L0f15c220:
/*  f15c220:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c224:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c228:	a5e00000 */ 	sh	$zero,0x0($t7)
/*  f15c22c:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c230:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15c234:	a3000006 */ 	sb	$zero,0x6($t8)
/*  f15c238:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c23c:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c240:	a1e20007 */ 	sb	$v0,0x7($t7)
/*  f15c244:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c248:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15c24c:	a7000002 */ 	sh	$zero,0x2($t8)
/*  f15c250:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c254:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c258:	ade00014 */ 	sw	$zero,0x14($t7)
/*  f15c25c:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c260:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15c264:	af030080 */ 	sw	$v1,0x80($t8)
/*  f15c268:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c26c:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c270:	ade00084 */ 	sw	$zero,0x84($t7)
/*  f15c274:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c278:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15c27c:	af000088 */ 	sw	$zero,0x88($t8)
/*  f15c280:	8e6e02bc */ 	lw	$t6,0x2bc($s3)
/*  f15c284:	2652008c */ 	addiu	$s2,$s2,0x8c
/*  f15c288:	028e082a */ 	slt	$at,$s4,$t6
/*  f15c28c:	5420ffe4 */ 	bnezl	$at,.L0f15c220
/*  f15c290:	8eae0000 */ 	lw	$t6,0x0($s5)
.L0f15c294:
/*  f15c294:	0fc04fb8 */ 	jal	func0f013ee0
/*  f15c298:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c29c:	44808000 */ 	mtc1	$zero,$f16
/*  f15c2a0:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c2a4:	e5f00018 */ 	swc1	$f16,0x18($t7)
/*  f15c2a8:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c2ac:	e730001c */ 	swc1	$f16,0x1c($t9)
/*  f15c2b0:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15c2b4:	e7100020 */ 	swc1	$f16,0x20($t8)
/*  f15c2b8:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c2bc:	e5d00024 */ 	swc1	$f16,0x24($t6)
/*  f15c2c0:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c2c4:	e5f00028 */ 	swc1	$f16,0x28($t7)
/*  f15c2c8:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c2cc:	0fc4f0fd */ 	jal	func0f13c3f4
/*  f15c2d0:	e730002c */ 	swc1	$f16,0x2c($t9)
/*  f15c2d4:	03a08025 */ 	or	$s0,$sp,$zero
/*  f15c2d8:	261000b3 */ 	addiu	$s0,$s0,0xb3
/*  f15c2dc:	3c12800a */ 	lui	$s2,%hi(var800a4924)
/*  f15c2e0:	3618000f */ 	ori	$t8,$s0,0xf
/*  f15c2e4:	26524924 */ 	addiu	$s2,$s2,%lo(var800a4924)
/*  f15c2e8:	3b04000f */ 	xori	$a0,$t8,0xf
/*  f15c2ec:	00808025 */ 	or	$s0,$a0,$zero
/*  f15c2f0:	8e450000 */ 	lw	$a1,0x0($s2)
/*  f15c2f4:	0fc56c71 */ 	jal	func0f15b1c4
/*  f15c2f8:	24060040 */ 	addiu	$a2,$zero,0x40
/*  f15c2fc:	96020000 */ 	lhu	$v0,0x0($s0)
/*  f15c300:	34018000 */ 	dli	$at,0x8000
/*  f15c304:	96110002 */ 	lhu	$s1,0x2($s0)
/*  f15c308:	304f7fff */ 	andi	$t7,$v0,0x7fff
/*  f15c30c:	25e2ffff */ 	addiu	$v0,$t7,-1
/*  f15c310:	3459000f */ 	ori	$t9,$v0,0xf
/*  f15c314:	27220001 */ 	addiu	$v0,$t9,0x1
/*  f15c318:	00412021 */ 	addu	$a0,$v0,$at
/*  f15c31c:	0c0048f2 */ 	jal	malloc
/*  f15c320:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15c324:	8e450000 */ 	lw	$a1,0x0($s2)
/*  f15c328:	34018000 */ 	dli	$at,0x8000
/*  f15c32c:	2626ffff */ 	addiu	$a2,$s1,-1
/*  f15c330:	00412021 */ 	addu	$a0,$v0,$at
/*  f15c334:	34d8000f */ 	ori	$t8,$a2,0xf
/*  f15c338:	afa2008c */ 	sw	$v0,0x8c($sp)
/*  f15c33c:	00808025 */ 	or	$s0,$a0,$zero
/*  f15c340:	27060001 */ 	addiu	$a2,$t8,0x1
/*  f15c344:	0fc56c71 */ 	jal	func0f15b1c4
/*  f15c348:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f15c34c:	02002025 */ 	or	$a0,$s0,$zero
/*  f15c350:	8fa5008c */ 	lw	$a1,0x8c($sp)
/*  f15c354:	0fc5766a */ 	jal	func0f15d9a8
/*  f15c358:	02203025 */ 	or	$a2,$s1,$zero
/*  f15c35c:	8e6302bc */ 	lw	$v1,0x2bc($s3)
/*  f15c360:	8fb0008c */ 	lw	$s0,0x8c($sp)
/*  f15c364:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15c368:	2c610002 */ 	sltiu	$at,$v1,0x2
/*  f15c36c:	1420007a */ 	bnez	$at,.L0f15c558
/*  f15c370:	3c013f00 */ 	lui	$at,0x3f00
/*  f15c374:	3c1e800a */ 	lui	$s8,%hi(g_Vars)
/*  f15c378:	3c13800a */ 	lui	$s3,%hi(var800a4cc4)
/*  f15c37c:	44818000 */ 	mtc1	$at,$f16
/*  f15c380:	26734cc4 */ 	addiu	$s3,$s3,%lo(var800a4cc4)
/*  f15c384:	27de9fc0 */ 	addiu	$s8,$s8,%lo(g_Vars)
/*  f15c388:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f15c38c:	24120014 */ 	addiu	$s2,$zero,0x14
/*  f15c390:	86190000 */ 	lh	$t9,0x0($s0)
.L0f15c394:
/*  f15c394:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f15c398:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15c39c:	44999000 */ 	mtc1	$t9,$f18
/*  f15c3a0:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c3a4:	c5ea0004 */ 	lwc1	$f10,0x4($t7)
/*  f15c3a8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f15c3ac:	03117021 */ 	addu	$t6,$t8,$s1
/*  f15c3b0:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f15c3b4:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f15c3b8:	e5c80018 */ 	swc1	$f8,0x18($t6)
/*  f15c3bc:	8618fff6 */ 	lh	$t8,-0xa($s0)
/*  f15c3c0:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f15c3c4:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c3c8:	44989000 */ 	mtc1	$t8,$f18
/*  f15c3cc:	01f2c821 */ 	addu	$t9,$t7,$s2
/*  f15c3d0:	c7260008 */ 	lwc1	$f6,0x8($t9)
/*  f15c3d4:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f15c3d8:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f15c3dc:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f15c3e0:	e5e4001c */ 	swc1	$f4,0x1c($t7)
/*  f15c3e4:	860efff8 */ 	lh	$t6,-0x8($s0)
/*  f15c3e8:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15c3ec:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c3f0:	448e9000 */ 	mtc1	$t6,$f18
/*  f15c3f4:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15c3f8:	c708000c */ 	lwc1	$f8,0xc($t8)
/*  f15c3fc:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f15c400:	01f1c821 */ 	addu	$t9,$t7,$s1
/*  f15c404:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f15c408:	e72a0020 */ 	swc1	$f10,0x20($t9)
/*  f15c40c:	860ffffa */ 	lh	$t7,-0x6($s0)
/*  f15c410:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f15c414:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c418:	448f9000 */ 	mtc1	$t7,$f18
/*  f15c41c:	03127021 */ 	addu	$t6,$t8,$s2
/*  f15c420:	c5c40004 */ 	lwc1	$f4,0x4($t6)
/*  f15c424:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f15c428:	0331c021 */ 	addu	$t8,$t9,$s1
/*  f15c42c:	46082180 */ 	add.s	$f6,$f4,$f8
/*  f15c430:	e7060024 */ 	swc1	$f6,0x24($t8)
/*  f15c434:	8619fffc */ 	lh	$t9,-0x4($s0)
/*  f15c438:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f15c43c:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15c440:	44999000 */ 	mtc1	$t9,$f18
/*  f15c444:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15c448:	c5ea0008 */ 	lwc1	$f10,0x8($t7)
/*  f15c44c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f15c450:	03117021 */ 	addu	$t6,$t8,$s1
/*  f15c454:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f15c458:	e5c80028 */ 	swc1	$f8,0x28($t6)
/*  f15c45c:	8618fffe */ 	lh	$t8,-0x2($s0)
/*  f15c460:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f15c464:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c468:	44989000 */ 	mtc1	$t8,$f18
/*  f15c46c:	01f2c821 */ 	addu	$t9,$t7,$s2
/*  f15c470:	c726000c */ 	lwc1	$f6,0xc($t9)
/*  f15c474:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f15c478:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f15c47c:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f15c480:	e5e4002c */ 	swc1	$f4,0x2c($t7)
/*  f15c484:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c488:	03311021 */ 	addu	$v0,$t9,$s1
/*  f15c48c:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f15c490:	c4520018 */ 	lwc1	$f18,0x18($v0)
/*  f15c494:	46124180 */ 	add.s	$f6,$f8,$f18
/*  f15c498:	46103282 */ 	mul.s	$f10,$f6,$f16
/*  f15c49c:	e44a0030 */ 	swc1	$f10,0x30($v0)
/*  f15c4a0:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15c4a4:	03111021 */ 	addu	$v0,$t8,$s1
/*  f15c4a8:	c4440028 */ 	lwc1	$f4,0x28($v0)
/*  f15c4ac:	c448001c */ 	lwc1	$f8,0x1c($v0)
/*  f15c4b0:	46082480 */ 	add.s	$f18,$f4,$f8
/*  f15c4b4:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f15c4b8:	e4460034 */ 	swc1	$f6,0x34($v0)
/*  f15c4bc:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15c4c0:	01d11021 */ 	addu	$v0,$t6,$s1
/*  f15c4c4:	c44a002c */ 	lwc1	$f10,0x2c($v0)
/*  f15c4c8:	c4440020 */ 	lwc1	$f4,0x20($v0)
/*  f15c4cc:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f15c4d0:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f15c4d4:	e4520038 */ 	swc1	$f18,0x38($v0)
/*  f15c4d8:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c4dc:	01f11021 */ 	addu	$v0,$t7,$s1
/*  f15c4e0:	c4460020 */ 	lwc1	$f6,0x20($v0)
/*  f15c4e4:	c44a002c */ 	lwc1	$f10,0x2c($v0)
/*  f15c4e8:	c4440018 */ 	lwc1	$f4,0x18($v0)
/*  f15c4ec:	c4480024 */ 	lwc1	$f8,0x24($v0)
/*  f15c4f0:	460a3001 */ 	sub.s	$f0,$f6,$f10
/*  f15c4f4:	c4460028 */ 	lwc1	$f6,0x28($v0)
/*  f15c4f8:	c452001c */ 	lwc1	$f18,0x1c($v0)
/*  f15c4fc:	46082081 */ 	sub.s	$f2,$f4,$f8
/*  f15c500:	46069381 */ 	sub.s	$f14,$f18,$f6
/*  f15c504:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f15c508:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c50c:	460e7102 */ 	mul.s	$f4,$f14,$f14
/*  f15c510:	46045200 */ 	add.s	$f8,$f10,$f4
/*  f15c514:	46000482 */ 	mul.s	$f18,$f0,$f0
/*  f15c518:	0c012974 */ 	jal	sqrtf
/*  f15c51c:	46089300 */ 	add.s	$f12,$f18,$f8
/*  f15c520:	3c013f00 */ 	lui	$at,0x3f00
/*  f15c524:	44818000 */ 	mtc1	$at,$f16
/*  f15c528:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c52c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c530:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f15c534:	0331c021 */ 	addu	$t8,$t9,$s1
/*  f15c538:	2631008c */ 	addiu	$s1,$s1,140
/*  f15c53c:	26520014 */ 	addiu	$s2,$s2,0x14
/*  f15c540:	e706003c */ 	swc1	$f6,0x3c($t8)
/*  f15c544:	8fc302bc */ 	lw	$v1,0x2bc($s8)
/*  f15c548:	0283082b */ 	sltu	$at,$s4,$v1
/*  f15c54c:	5420ff91 */ 	bnezl	$at,.L0f15c394
/*  f15c550:	86190000 */ 	lh	$t9,0x0($s0)
/*  f15c554:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f15c558:
/*  f15c558:	3c1e800a */ 	lui	$s8,%hi(g_Vars)
/*  f15c55c:	2c610002 */ 	sltiu	$at,$v1,0x2
/*  f15c560:	27de9fc0 */ 	addiu	$s8,$s8,%lo(g_Vars)
/*  f15c564:	14200012 */ 	bnez	$at,.L0f15c5b0
/*  f15c568:	02001025 */ 	or	$v0,$s0,$zero
/*  f15c56c:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f15c570:	944e0000 */ 	lhu	$t6,0x0($v0)
.L0f15c574:
/*  f15c574:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c578:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f15c57c:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f15c580:	25f9010f */ 	addiu	$t9,$t7,0x10f
/*  f15c584:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c588:	3738000f */ 	ori	$t8,$t9,0xf
/*  f15c58c:	3b0e000f */ 	xori	$t6,$t8,0xf
/*  f15c590:	01f1c821 */ 	addu	$t9,$t7,$s1
/*  f15c594:	af2e0080 */ 	sw	$t6,0x80($t9)
/*  f15c598:	8fc302bc */ 	lw	$v1,0x2bc($s8)
/*  f15c59c:	2631008c */ 	addiu	$s1,$s1,0x8c
/*  f15c5a0:	0283082b */ 	sltu	$at,$s4,$v1
/*  f15c5a4:	5420fff3 */ 	bnezl	$at,.L0f15c574
/*  f15c5a8:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f15c5ac:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f15c5b0:
/*  f15c5b0:	2c610002 */ 	sltiu	$at,$v1,0x2
/*  f15c5b4:	00002025 */ 	or	$a0,$zero,$zero
/*  f15c5b8:	1420001b */ 	bnez	$at,.L0f15c628
/*  f15c5bc:	00402825 */ 	or	$a1,$v0,$zero
/*  f15c5c0:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f15c5c4:	3403ffff */ 	dli	$v1,0xffff
.L0f15c5c8:
/*  f15c5c8:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f15c5cc:	90b80000 */ 	lbu	$t8,0x0($a1)
/*  f15c5d0:	01f17021 */ 	addu	$t6,$t7,$s1
/*  f15c5d4:	a1d80008 */ 	sb	$t8,0x8($t6)
/*  f15c5d8:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f15c5dc:	03311021 */ 	addu	$v0,$t9,$s1
/*  f15c5e0:	804f0008 */ 	lb	$t7,0x8($v0)
/*  f15c5e4:	59e0000a */ 	blezl	$t7,.L0f15c610
/*  f15c5e8:	a443000a */ 	sh	$v1,0xa($v0)
/*  f15c5ec:	a444000a */ 	sh	$a0,0xa($v0)
/*  f15c5f0:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15c5f4:	03117021 */ 	addu	$t6,$t8,$s1
/*  f15c5f8:	81d90008 */ 	lb	$t9,0x8($t6)
/*  f15c5fc:	00992021 */ 	addu	$a0,$a0,$t9
/*  f15c600:	00047c00 */ 	sll	$t7,$a0,0x10
/*  f15c604:	10000002 */ 	beqz	$zero,.L0f15c610
/*  f15c608:	000f2403 */ 	sra	$a0,$t7,0x10
/*  f15c60c:	a443000a */ 	sh	$v1,0xa($v0)
.L0f15c610:
/*  f15c610:	8fce02bc */ 	lw	$t6,0x2bc($s8)
/*  f15c614:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c618:	2631008c */ 	addiu	$s1,$s1,0x8c
/*  f15c61c:	028e082b */ 	sltu	$at,$s4,$t6
/*  f15c620:	1420ffe9 */ 	bnez	$at,.L0f15c5c8
/*  f15c624:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f15c628:
/*  f15c628:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f15c62c:	00002825 */ 	or	$a1,$zero,$zero
/*  f15c630:	0c00490c */ 	jal	func00012430
/*  f15c634:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f15c638:	8fd102bc */ 	lw	$s1,0x2bc($s8)
/*  f15c63c:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15c640:	2a210002 */ 	slti	$at,$s1,0x2
/*  f15c644:	5420000a */ 	bnezl	$at,.L0f15c670
/*  f15c648:	2a210002 */ 	slti	$at,$s1,0x2
.L0f15c64c:
/*  f15c64c:	0fc004f2 */ 	jal	func0f0013c8
/*  f15c650:	02802025 */ 	or	$a0,$s4,$zero
/*  f15c654:	8fd102bc */ 	lw	$s1,0x2bc($s8)
/*  f15c658:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c65c:	0291082a */ 	slt	$at,$s4,$s1
/*  f15c660:	1420fffa */ 	bnez	$at,.L0f15c64c
/*  f15c664:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c668:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15c66c:	2a210002 */ 	slti	$at,$s1,0x2
.L0f15c670:
/*  f15c670:	1420000b */ 	bnez	$at,.L0f15c6a0
/*  f15c674:	3c0c800a */ 	lui	$t4,%hi(g_RoomPtrs)
/*  f15c678:	8d8c4928 */ 	lw	$t4,%lo(g_RoomPtrs)($t4)
/*  f15c67c:	3c1e800a */ 	lui	$s8,%hi(g_Vars)
/*  f15c680:	27de9fc0 */ 	addiu	$s8,$s8,%lo(g_Vars)
/*  f15c684:	258c008c */ 	addiu	$t4,$t4,140
.L0f15c688:
/*  f15c688:	81990008 */ 	lb	$t9,0x8($t4)
/*  f15c68c:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c690:	0291082a */ 	slt	$at,$s4,$s1
/*  f15c694:	258c008c */ 	addiu	$t4,$t4,0x8c
/*  f15c698:	1420fffb */ 	bnez	$at,.L0f15c688
/*  f15c69c:	02d9b021 */ 	addu	$s6,$s6,$t9
.L0f15c6a0:
/*  f15c6a0:	12c0001c */ 	beqz	$s6,.L0f15c714
/*  f15c6a4:	3c03800a */ 	lui	$v1,%hi(g_MenuStack+0x2000)
/*  f15c6a8:	00162080 */ 	sll	$a0,$s6,0x2
/*  f15c6ac:	00962023 */ 	subu	$a0,$a0,$s6
/*  f15c6b0:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f15c6b4:	348f000f */ 	ori	$t7,$a0,0xf
/*  f15c6b8:	39e4000f */ 	xori	$a0,$t7,0xf
/*  f15c6bc:	0c0048f2 */ 	jal	malloc
/*  f15c6c0:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f15c6c4:	3c03800a */ 	lui	$v1,%hi(var800a41a0)
/*  f15c6c8:	246341a0 */ 	addiu	$v1,$v1,%lo(var800a41a0)
/*  f15c6cc:	ac620000 */ 	sw	$v0,%lo(g_MenuStack+0x2000)($v1)
/*  f15c6d0:	1ac00013 */ 	blez	$s6,.L0f15c720
/*  f15c6d4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f15c6d8:	00001025 */ 	or	$v0,$zero,$zero
.L0f15c6dc:
/*  f15c6dc:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f15c6e0:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c6e4:	01c2c821 */ 	addu	$t9,$t6,$v0
/*  f15c6e8:	a3200000 */ 	sb	$zero,0x0($t9)
/*  f15c6ec:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f15c6f0:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f15c6f4:	a3000001 */ 	sb	$zero,0x1($t8)
/*  f15c6f8:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f15c6fc:	01c2c821 */ 	addu	$t9,$t6,$v0
/*  f15c700:	24420003 */ 	addiu	$v0,$v0,0x3
/*  f15c704:	1696fff5 */ 	bne	$s4,$s6,.L0f15c6dc
/*  f15c708:	a3200002 */ 	sb	$zero,0x2($t9)
/*  f15c70c:	10000004 */ 	beqz	$zero,.L0f15c720
/*  f15c710:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15c714:
/*  f15c714:	246341a0 */ 	addiu	$v1,$v1,16800
/*  f15c718:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f15c71c:	0000a025 */ 	or	$s4,$zero,$zero
.L0f15c720:
/*  f15c720:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f15c724:	00009025 */ 	or	$s2,$zero,$zero
/*  f15c728:	95f80000 */ 	lhu	$t8,0x0($t7)
/*  f15c72c:	1300000a */ 	beqz	$t8,.L0f15c758
/*  f15c730:	00000000 */ 	sll	$zero,$zero,0x0
.L0f15c734:
/*  f15c734:	0fc592ae */ 	jal	func0f164ab8
/*  f15c738:	02802025 */ 	or	$a0,$s4,$zero
/*  f15c73c:	8eee0000 */ 	lw	$t6,0x0($s7)
/*  f15c740:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f15c744:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c748:	01d2c821 */ 	addu	$t9,$t6,$s2
/*  f15c74c:	972f0000 */ 	lhu	$t7,0x0($t9)
/*  f15c750:	15e0fff8 */ 	bnez	$t7,.L0f15c734
/*  f15c754:	00000000 */ 	sll	$zero,$zero,0x0
.L0f15c758:
/*  f15c758:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f15c75c:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f15c760:	8e1102bc */ 	lw	$s1,0x2bc($s0)
/*  f15c764:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15c768:	2a210002 */ 	slti	$at,$s1,0x2
/*  f15c76c:	5420000a */ 	bnezl	$at,.L0f15c798
/*  f15c770:	2a210002 */ 	slti	$at,$s1,0x2
.L0f15c774:
/*  f15c774:	0fc59319 */ 	jal	func0f164c64
/*  f15c778:	02802025 */ 	or	$a0,$s4,$zero
/*  f15c77c:	8e1102bc */ 	lw	$s1,0x2bc($s0)
/*  f15c780:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c784:	0291082a */ 	slt	$at,$s4,$s1
/*  f15c788:	1420fffa */ 	bnez	$at,.L0f15c774
/*  f15c78c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c790:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f15c794:	2a210002 */ 	slti	$at,$s1,0x2
.L0f15c798:
/*  f15c798:	54200009 */ 	bnezl	$at,.L0f15c7c0
/*  f15c79c:	8ef00000 */ 	lw	$s0,0x0($s7)
.L0f15c7a0:
/*  f15c7a0:	0fc59233 */ 	jal	func0f1648cc
/*  f15c7a4:	02802025 */ 	or	$a0,$s4,$zero
/*  f15c7a8:	8e1802bc */ 	lw	$t8,0x2bc($s0)
/*  f15c7ac:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f15c7b0:	0298082a */ 	slt	$at,$s4,$t8
/*  f15c7b4:	1420fffa */ 	bnez	$at,.L0f15c7a0
/*  f15c7b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c7bc:	8ef00000 */ 	lw	$s0,0x0($s7)
.L0f15c7c0:
/*  f15c7c0:	00009025 */ 	or	$s2,$zero,$zero
/*  f15c7c4:	960e0000 */ 	lhu	$t6,0x0($s0)
/*  f15c7c8:	02001025 */ 	or	$v0,$s0,$zero
/*  f15c7cc:	11c0000a */ 	beqz	$t6,.L0f15c7f8
/*  f15c7d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c7d4:	90590006 */ 	lbu	$t9,0x6($v0)
.L0f15c7d8:
/*  f15c7d8:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f15c7dc:	332f00fe */ 	andi	$t7,$t9,0xfe
/*  f15c7e0:	a04f0006 */ 	sb	$t7,0x6($v0)
/*  f15c7e4:	8ef80000 */ 	lw	$t8,0x0($s7)
/*  f15c7e8:	03121021 */ 	addu	$v0,$t8,$s2
/*  f15c7ec:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f15c7f0:	55c0fff9 */ 	bnezl	$t6,.L0f15c7d8
/*  f15c7f4:	90590006 */ 	lbu	$t9,0x6($v0)
.L0f15c7f8:
/*  f15c7f8:	0fc597b9 */ 	jal	func0f165ee4
/*  f15c7fc:	8fa40148 */ 	lw	$a0,0x148($sp)
/*  f15c800:	241900c8 */ 	addiu	$t9,$zero,0xc8
/*  f15c804:	3c018008 */ 	lui	$at,%hi(var8007fc10)
/*  f15c808:	0fc04d54 */ 	jal	func0f013550
/*  f15c80c:	a439fc10 */ 	sh	$t9,%lo(var8007fc10)($at)
/*  f15c810:	0fc00aa6 */ 	jal	func0f002a98
/*  f15c814:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c818:	0fc00703 */ 	jal	func0f001c0c
/*  f15c81c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c820:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f15c824:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f15c828:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f15c82c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f15c830:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f15c834:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f15c838:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f15c83c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f15c840:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f15c844:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f15c848:	03e00008 */ 	jr	$ra
/*  f15c84c:	27bd0148 */ 	addiu	$sp,$sp,0x148
);

GLOBAL_ASM(
glabel func0f15c850
/*  f15c850:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f15c854:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f15c858:	0fc5794e */ 	jal	func0f15e538
/*  f15c85c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c860:	3c013f80 */ 	lui	$at,0x3f80
/*  f15c864:	44816000 */ 	mtc1	$at,$f12
/*  f15c868:	0c0059d2 */ 	jal	func00016748
/*  f15c86c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15c870:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f15c874:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f15c878:	03e00008 */ 	jr	$ra
/*  f15c87c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15c880
/*  f15c880:	03e00008 */ 	jr	$ra
/*  f15c884:	e7ac0000 */ 	swc1	$f12,0x0($sp)
);

GLOBAL_ASM(
glabel func0f15c888
/*  f15c888:	3c0e8008 */ 	lui	$t6,%hi(g_StageIndex)
/*  f15c88c:	8dcefc00 */ 	lw	$t6,%lo(g_StageIndex)($t6)
/*  f15c890:	3c188008 */ 	lui	$t8,%hi(g_Stages)
/*  f15c894:	2718fcc0 */ 	addiu	$t8,$t8,%lo(g_Stages)
/*  f15c898:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f15c89c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f15c8a0:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f15c8a4:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f15c8a8:	c444001c */ 	lwc1	$f4,0x1c($v0)
/*  f15c8ac:	c4460014 */ 	lwc1	$f6,0x14($v0)
/*  f15c8b0:	03e00008 */ 	jr	$ra
/*  f15c8b4:	46062003 */ 	div.s	$f0,$f4,$f6
);

f32 currentPlayerGetScaleBg2Gfx(void)
{
	return g_Vars.currentplayerstats->scale_bg2gfx;
}

void currentPlayerSetScaleBg2Gfx(f32 scale)
{
	g_Vars.currentplayerstats->scale_bg2gfx = g_Stages[g_StageIndex].unk18 * scale;
	func00016748(g_Vars.currentplayerstats->scale_bg2gfx);
}

GLOBAL_ASM(
glabel func0f15c920
/*  f15c920:	3c038008 */ 	lui	$v1,%hi(var8007fc3c)
/*  f15c924:	2463fc3c */ 	addiu	$v1,$v1,%lo(var8007fc3c)
/*  f15c928:	946e0000 */ 	lhu	$t6,0x0($v1)
/*  f15c92c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f15c930:	3401ffff */ 	dli	$at,0xffff
/*  f15c934:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f15c938:	31e2ffff */ 	andi	$v0,$t7,0xffff
/*  f15c93c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f15c940:	14410006 */ 	bne	$v0,$at,.L0f15c95c
/*  f15c944:	a46f0000 */ 	sh	$t7,0x0($v1)
/*  f15c948:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f15c94c:	0fc5734a */ 	jal	func0f15cd28
/*  f15c950:	a4780000 */ 	sh	$t8,0x0($v1)
/*  f15c954:	3c028008 */ 	lui	$v0,%hi(var8007fc3c)
/*  f15c958:	9442fc3c */ 	lhu	$v0,%lo(var8007fc3c)($v0)
.L0f15c95c:
/*  f15c95c:	305900ff */ 	andi	$t9,$v0,0xff
/*  f15c960:	240100ff */ 	addiu	$at,$zero,0xff
/*  f15c964:	17210022 */ 	bne	$t9,$at,.L0f15c9f0
/*  f15c968:	3c027f00 */ 	lui	$v0,%hi(func0f0069dc)
/*  f15c96c:	3c067f00 */ 	lui	$a2,%hi(func0f006b08)
/*  f15c970:	244469dc */ 	addiu	$a0,$v0,%lo(func0f0069dc)
/*  f15c974:	24c56b08 */ 	addiu	$a1,$a2,%lo(func0f006b08)
/*  f15c978:	0085082b */ 	sltu	$at,$a0,$a1
/*  f15c97c:	1020000b */ 	beqz	$at,.L0f15c9ac
/*  f15c980:	00001825 */ 	or	$v1,$zero,$zero
.L0f15c984:
/*  f15c984:	8c820000 */ 	lw	$v0,0x0($a0)
/*  f15c988:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f15c98c:	0085082b */ 	sltu	$at,$a0,$a1
/*  f15c990:	00404027 */ 	nor	$t0,$v0,$zero
/*  f15c994:	00681826 */ 	xor	$v1,$v1,$t0
/*  f15c998:	00024940 */ 	sll	$t1,$v0,0x5
/*  f15c99c:	00691826 */ 	xor	$v1,$v1,$t1
/*  f15c9a0:	000253c3 */ 	sra	$t2,$v0,0xf
/*  f15c9a4:	1420fff7 */ 	bnez	$at,.L0f15c984
/*  f15c9a8:	006a1826 */ 	xor	$v1,$v1,$t2
.L0f15c9ac:
/*  f15c9ac:	3c012c7b */ 	lui	$at,0x2c7b
/*  f15c9b0:	342182c8 */ 	ori	$at,$at,0x82c8
/*  f15c9b4:	1061000e */ 	beq	$v1,$at,.L0f15c9f0
/*  f15c9b8:	3c027f16 */ 	lui	$v0,%hi(func0f15b908)
/*  f15c9bc:	2442b908 */ 	addiu	$v0,$v0,%lo(func0f15b908)
/*  f15c9c0:	24440050 */ 	addiu	$a0,$v0,0x50
/*  f15c9c4:	24850010 */ 	addiu	$a1,$a0,0x10
/*  f15c9c8:	0085082b */ 	sltu	$at,$a0,$a1
/*  f15c9cc:	10200008 */ 	beqz	$at,.L0f15c9f0
/*  f15c9d0:	3c02fffd */ 	lui	$v0,0xfffd
/*  f15c9d4:	3442b1df */ 	ori	$v0,$v0,0xb1df
.L0f15c9d8:
/*  f15c9d8:	8c8b0000 */ 	lw	$t3,0x0($a0)
/*  f15c9dc:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f15c9e0:	0085082b */ 	sltu	$at,$a0,$a1
/*  f15c9e4:	01626021 */ 	addu	$t4,$t3,$v0
/*  f15c9e8:	1420fffb */ 	bnez	$at,.L0f15c9d8
/*  f15c9ec:	ac8cfffc */ 	sw	$t4,-0x4($a0)
.L0f15c9f0:
/*  f15c9f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f15c9f4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f15c9f8:	03e00008 */ 	jr	$ra
/*  f15c9fc:	00000000 */ 	sll	$zero,$zero,0x0
);

// Mismatch because it calculates end by adding 24 to &func0f16b908,
// but needs to calculating it by adding 4 to ptr.
//void func0f15c920(void)
//{
//	var8007fc3c++;
//
//	if (var8007fc3c == 0xffff) {
//		var8007fc3c = 1;
//		func0f15cd28();
//	}
//
//#if PIRACYCHECKS
//	if ((var8007fc3c & 0xff) == 0xff) {
//		u32 checksum = 0;
//		s32 *ptr = (s32 *)&func0f0069dc;
//		s32 *end = (s32 *)&func0f006b08;
//
//		while (ptr < end) {
//			checksum ^= ~*ptr;
//			checksum ^= *ptr << 5;
//			checksum ^= *ptr >> 15;
//			ptr++;
//		}
//
//		if (checksum != 0x2c7b82c8) {
//			ptr = (s32 *)&func0f15b908 + 20;
//			end = &ptr[4];
//
//			while (ptr < end) {
//				*ptr -= 0x24e21;
//				ptr++;
//			}
//		}
//	}
//#endif
//}

GLOBAL_ASM(
glabel func0f15ca00
/*  f15ca00:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f15ca04:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f15ca08:	3c01800a */ 	lui	$at,%hi(var800a4bec)
/*  f15ca0c:	0fc57248 */ 	jal	func0f15c920
/*  f15ca10:	ac204bec */ 	sw	$zero,%lo(var800a4bec)($at)
/*  f15ca14:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f15ca18:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f15ca1c:	8cae0290 */ 	lw	$t6,0x290($a1)
/*  f15ca20:	55c00006 */ 	bnezl	$t6,.L0f15ca3c
/*  f15ca24:	8ca202ac */ 	lw	$v0,0x2ac($a1)
/*  f15ca28:	0fc579ca */ 	jal	func0f15e728
/*  f15ca2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ca30:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f15ca34:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f15ca38:	8ca202ac */ 	lw	$v0,0x2ac($a1)
.L0f15ca3c:
/*  f15ca3c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f15ca40:	3c048008 */ 	lui	$a0,%hi(var8007fc10)
/*  f15ca44:	14430012 */ 	bne	$v0,$v1,.L0f15ca90
/*  f15ca48:	2484fc10 */ 	addiu	$a0,$a0,%lo(var8007fc10)
/*  f15ca4c:	3c048008 */ 	lui	$a0,%hi(var8007fc10)
/*  f15ca50:	2484fc10 */ 	addiu	$a0,$a0,%lo(var8007fc10)
/*  f15ca54:	240f0004 */ 	addiu	$t7,$zero,0x4
/*  f15ca58:	a48f0000 */ 	sh	$t7,0x0($a0)
/*  f15ca5c:	3c188009 */ 	lui	$t8,%hi(g_Is4Mb)
/*  f15ca60:	93180af0 */ 	lbu	$t8,%lo(g_Is4Mb)($t8)
/*  f15ca64:	3c068008 */ 	lui	$a2,%hi(var8007fc0c)
/*  f15ca68:	24c6fc0c */ 	addiu	$a2,$a2,%lo(var8007fc0c)
/*  f15ca6c:	5078000f */ 	beql	$v1,$t8,.L0f15caac
/*  f15ca70:	8ca20284 */ 	lw	$v0,0x284($a1)
/*  f15ca74:	84c20000 */ 	lh	$v0,0x0($a2)
/*  f15ca78:	240800c8 */ 	addiu	$t0,$zero,0xc8
/*  f15ca7c:	1040000a */ 	beqz	$v0,.L0f15caa8
/*  f15ca80:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f15ca84:	a4d90000 */ 	sh	$t9,0x0($a2)
/*  f15ca88:	10000007 */ 	beqz	$zero,.L0f15caa8
/*  f15ca8c:	a4880000 */ 	sh	$t0,0x0($a0)
.L0f15ca90:
/*  f15ca90:	3c068008 */ 	lui	$a2,%hi(var8007fc0c)
/*  f15ca94:	24c6fc0c */ 	addiu	$a2,$a2,%lo(var8007fc0c)
/*  f15ca98:	24090008 */ 	addiu	$t1,$zero,0x8
/*  f15ca9c:	240a00c8 */ 	addiu	$t2,$zero,0xc8
/*  f15caa0:	a4c90000 */ 	sh	$t1,0x0($a2)
/*  f15caa4:	a48a0000 */ 	sh	$t2,0x0($a0)
.L0f15caa8:
/*  f15caa8:	8ca20284 */ 	lw	$v0,0x284($a1)
.L0f15caac:
/*  f15caac:	240c0064 */ 	addiu	$t4,$zero,0x64
/*  f15cab0:	944b0010 */ 	lhu	$t3,0x10($v0)
/*  f15cab4:	546b0003 */ 	bnel	$v1,$t3,.L0f15cac4
/*  f15cab8:	8c4d1ba0 */ 	lw	$t5,0x1ba0($v0)
/*  f15cabc:	a48c0000 */ 	sh	$t4,0x0($a0)
/*  f15cac0:	8c4d1ba0 */ 	lw	$t5,0x1ba0($v0)
.L0f15cac4:
/*  f15cac4:	3c018008 */ 	lui	$at,%hi(var8007fc20)
/*  f15cac8:	0fc58f8d */ 	jal	func0f163e34
/*  f15cacc:	ac2dfc20 */ 	sw	$t5,%lo(var8007fc20)($at)
/*  f15cad0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f15cad4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f15cad8:	03e00008 */ 	jr	$ra
/*  f15cadc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15cae0
/*  f15cae0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f15cae4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f15cae8:	0fc004c0 */ 	jal	func0f001300
/*  f15caec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15caf0:	3c0ebc00 */ 	lui	$t6,0xbc00
/*  f15caf4:	35ce3c06 */ 	ori	$t6,$t6,0x3c06
/*  f15caf8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f15cafc:	3c0f800a */ 	lui	$t7,%hi(var800a491c)
/*  f15cb00:	8def491c */ 	lw	$t7,%lo(var800a491c)($t7)
/*  f15cb04:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f15cb08:	00002825 */ 	or	$a1,$zero,$zero
/*  f15cb0c:	0fc59928 */ 	jal	func0f1664a0
/*  f15cb10:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f15cb14:	0fc59054 */ 	jal	func0f164150
/*  f15cb18:	00402025 */ 	or	$a0,$v0,$zero
/*  f15cb1c:	0fc572dd */ 	jal	func0f15cb74
/*  f15cb20:	00402025 */ 	or	$a0,$v0,$zero
/*  f15cb24:	0fc599b2 */ 	jal	func0f1666c8
/*  f15cb28:	00402025 */ 	or	$a0,$v0,$zero
/*  f15cb2c:	3c180103 */ 	lui	$t8,0x103
/*  f15cb30:	37180040 */ 	ori	$t8,$t8,0x40
/*  f15cb34:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f15cb38:	3c198009 */ 	lui	$t9,%hi(var80092870)
/*  f15cb3c:	8f392870 */ 	lw	$t9,%lo(var80092870)($t9)
/*  f15cb40:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f15cb44:	0fc30cbf */ 	jal	func0f0c32fc
/*  f15cb48:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f15cb4c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f15cb50:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f15cb54:	03e00008 */ 	jr	$ra
/*  f15cb58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cb5c:	3c0e800a */ 	lui	$t6,%hi(var800a4cdc)
/*  f15cb60:	8dce4cdc */ 	lw	$t6,%lo(var800a4cdc)($t6)
/*  f15cb64:	00047880 */ 	sll	$t7,$a0,0x2
/*  f15cb68:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f15cb6c:	03e00008 */ 	jr	$ra
/*  f15cb70:	c7000004 */ 	lwc1	$f0,0x4($t8)
);

GLOBAL_ASM(
glabel func0f15cb74
/*  f15cb74:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f15cb78:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f15cb7c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f15cb80:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f15cb84:	844f0632 */ 	lh	$t7,0x632($v0)
/*  f15cb88:	84460636 */ 	lh	$a2,0x636($v0)
/*  f15cb8c:	844e0630 */ 	lh	$t6,0x630($v0)
/*  f15cb90:	84450634 */ 	lh	$a1,0x634($v0)
/*  f15cb94:	00cfc021 */ 	addu	$t8,$a2,$t7
/*  f15cb98:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f15cb9c:	0fc57306 */ 	jal	func0f15cc18
/*  f15cba0:	00ae3821 */ 	addu	$a3,$a1,$t6
/*  f15cba4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f15cba8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f15cbac:	03e00008 */ 	jr	$ra
/*  f15cbb0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15cbb4
/*  f15cbb4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f15cbb8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f15cbbc:	44876000 */ 	mtc1	$a3,$f12
/*  f15cbc0:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f15cbc4:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f15cbc8:	0fc25e7a */ 	jal	func0f0979e8
/*  f15cbcc:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f15cbd0:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f15cbd4:	0fc25e7a */ 	jal	func0f0979e8
/*  f15cbd8:	c7ac0038 */ 	lwc1	$f12,0x38($sp)
/*  f15cbdc:	c7a4002c */ 	lwc1	$f4,0x2c($sp)
/*  f15cbe0:	c7a80030 */ 	lwc1	$f8,0x30($sp)
/*  f15cbe4:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f15cbe8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f15cbec:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f15cbf0:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f15cbf4:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f15cbf8:	44053000 */ 	mfc1	$a1,$f6
/*  f15cbfc:	44065000 */ 	mfc1	$a2,$f10
/*  f15cc00:	0fc57306 */ 	jal	func0f15cc18
/*  f15cc04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cc08:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f15cc0c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f15cc10:	03e00008 */ 	jr	$ra
/*  f15cc14:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15cc18
/*  f15cc18:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f15cc1c:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f15cc20:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f15cc24:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f15cc28:	84430634 */ 	lh	$v1,0x634($v0)
/*  f15cc2c:	00a3082a */ 	slt	$at,$a1,$v1
/*  f15cc30:	50200003 */ 	beqzl	$at,.L0f15cc40
/*  f15cc34:	84440636 */ 	lh	$a0,0x636($v0)
/*  f15cc38:	00602825 */ 	or	$a1,$v1,$zero
/*  f15cc3c:	84440636 */ 	lh	$a0,0x636($v0)
.L0f15cc40:
/*  f15cc40:	44852000 */ 	mtc1	$a1,$f4
/*  f15cc44:	00c4082a */ 	slt	$at,$a2,$a0
/*  f15cc48:	10200002 */ 	beqz	$at,.L0f15cc54
/*  f15cc4c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f15cc50:	00803025 */ 	or	$a2,$a0,$zero
.L0f15cc54:
/*  f15cc54:	844e0630 */ 	lh	$t6,0x630($v0)
/*  f15cc58:	8faf000c */ 	lw	$t7,0xc($sp)
/*  f15cc5c:	44868000 */ 	mtc1	$a2,$f16
/*  f15cc60:	006e3821 */ 	addu	$a3,$v1,$t6
/*  f15cc64:	00ef082a */ 	slt	$at,$a3,$t7
/*  f15cc68:	10200002 */ 	beqz	$at,.L0f15cc74
/*  f15cc6c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f15cc70:	afa7000c */ 	sw	$a3,0xc($sp)
.L0f15cc74:
/*  f15cc74:	84580632 */ 	lh	$t8,0x632($v0)
/*  f15cc78:	8fa70010 */ 	lw	$a3,0x10($sp)
/*  f15cc7c:	00981821 */ 	addu	$v1,$a0,$t8
/*  f15cc80:	0067082a */ 	slt	$at,$v1,$a3
/*  f15cc84:	50200003 */ 	beqzl	$at,.L0f15cc94
/*  f15cc88:	3c014080 */ 	lui	$at,0x4080
/*  f15cc8c:	00603825 */ 	or	$a3,$v1,$zero
/*  f15cc90:	3c014080 */ 	lui	$at,0x4080
.L0f15cc94:
/*  f15cc94:	44810000 */ 	mtc1	$at,$f0
/*  f15cc98:	8fa30000 */ 	lw	$v1,0x0($sp)
/*  f15cc9c:	3c01ed00 */ 	lui	$at,0xed00
/*  f15cca0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f15cca4:	24680008 */ 	addiu	$t0,$v1,0x8
/*  f15cca8:	afa80000 */ 	sw	$t0,0x0($sp)
/*  f15ccac:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f15ccb0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f15ccb4:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f15ccb8:	440a5000 */ 	mfc1	$t2,$f10
/*  f15ccbc:	44872000 */ 	mtc1	$a3,$f4
/*  f15ccc0:	440f3000 */ 	mfc1	$t7,$f6
/*  f15ccc4:	314b0fff */ 	andi	$t3,$t2,0xfff
/*  f15ccc8:	000b6300 */ 	sll	$t4,$t3,0xc
/*  f15cccc:	01816825 */ 	or	$t5,$t4,$at
/*  f15ccd0:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f15ccd4:	01b8c825 */ 	or	$t9,$t5,$t8
/*  f15ccd8:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f15ccdc:	8fa8000c */ 	lw	$t0,0xc($sp)
/*  f15cce0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f15cce4:	44884000 */ 	mtc1	$t0,$f8
/*  f15cce8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ccec:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f15ccf0:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f15ccf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ccf8:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f15ccfc:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f15cd00:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f15cd04:	440a9000 */ 	mfc1	$t2,$f18
/*  f15cd08:	440f5000 */ 	mfc1	$t7,$f10
/*  f15cd0c:	314b0fff */ 	andi	$t3,$t2,0xfff
/*  f15cd10:	000b6300 */ 	sll	$t4,$t3,0xc
/*  f15cd14:	31ed0fff */ 	andi	$t5,$t7,0xfff
/*  f15cd18:	018dc025 */ 	or	$t8,$t4,$t5
/*  f15cd1c:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f15cd20:	03e00008 */ 	jr	$ra
/*  f15cd24:	8fa20000 */ 	lw	$v0,0x0($sp)
);

void func0f15cd28(void)
{
	s32 i;

	for (i = 0; i < g_NumPortals; i++) {
		g_Portals[i].unk06 = -1;
		g_Portals[i].unk04 = 0;
		g_Portals[i].unk00 = 0;
	}
}

GLOBAL_ASM(
glabel func0f15cd90
/*  f15cd90:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f15cd94:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f15cd98:	000480c0 */ 	sll	$s0,$a0,0x3
/*  f15cd9c:	02048021 */ 	addu	$s0,$s0,$a0
/*  f15cda0:	00108080 */ 	sll	$s0,$s0,0x2
/*  f15cda4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f15cda8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f15cdac:	02048023 */ 	subu	$s0,$s0,$a0
/*  f15cdb0:	3c0c800a */ 	lui	$t4,%hi(g_RoomPtrs)
/*  f15cdb4:	00a03025 */ 	or	$a2,$a1,$zero
/*  f15cdb8:	0000f825 */ 	or	$ra,$zero,$zero
/*  f15cdbc:	00003825 */ 	or	$a3,$zero,$zero
/*  f15cdc0:	00004025 */ 	or	$t0,$zero,$zero
/*  f15cdc4:	00004825 */ 	or	$t1,$zero,$zero
/*  f15cdc8:	00005025 */ 	or	$t2,$zero,$zero
/*  f15cdcc:	00005825 */ 	or	$t3,$zero,$zero
/*  f15cdd0:	258c4928 */ 	addiu	$t4,$t4,%lo(g_RoomPtrs)
/*  f15cdd4:	00108080 */ 	sll	$s0,$s0,0x2
/*  f15cdd8:	24110008 */ 	addiu	$s1,$zero,0x8
/*  f15cddc:	00001825 */ 	or	$v1,$zero,$zero
/*  f15cde0:	306e0001 */ 	andi	$t6,$v1,0x1
.L0f15cde4:
/*  f15cde4:	11c00006 */ 	beqz	$t6,.L0f15ce00
/*  f15cde8:	30790002 */ 	andi	$t9,$v1,0x2
/*  f15cdec:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f15cdf0:	01f01021 */ 	addu	$v0,$t7,$s0
/*  f15cdf4:	c4440018 */ 	lwc1	$f4,0x18($v0)
/*  f15cdf8:	10000005 */ 	beqz	$zero,.L0f15ce10
/*  f15cdfc:	e7a40044 */ 	swc1	$f4,0x44($sp)
.L0f15ce00:
/*  f15ce00:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f15ce04:	03101021 */ 	addu	$v0,$t8,$s0
/*  f15ce08:	c4460024 */ 	lwc1	$f6,0x24($v0)
/*  f15ce0c:	e7a60044 */ 	swc1	$f6,0x44($sp)
.L0f15ce10:
/*  f15ce10:	13200004 */ 	beqz	$t9,.L0f15ce24
/*  f15ce14:	306e0004 */ 	andi	$t6,$v1,0x4
/*  f15ce18:	c448001c */ 	lwc1	$f8,0x1c($v0)
/*  f15ce1c:	10000003 */ 	beqz	$zero,.L0f15ce2c
/*  f15ce20:	e7a80048 */ 	swc1	$f8,0x48($sp)
.L0f15ce24:
/*  f15ce24:	c44a0028 */ 	lwc1	$f10,0x28($v0)
/*  f15ce28:	e7aa0048 */ 	swc1	$f10,0x48($sp)
.L0f15ce2c:
/*  f15ce2c:	11c00004 */ 	beqz	$t6,.L0f15ce40
/*  f15ce30:	27a40044 */ 	addiu	$a0,$sp,0x44
/*  f15ce34:	c4500020 */ 	lwc1	$f16,0x20($v0)
/*  f15ce38:	10000003 */ 	beqz	$zero,.L0f15ce48
/*  f15ce3c:	e7b0004c */ 	swc1	$f16,0x4c($sp)
.L0f15ce40:
/*  f15ce40:	c452002c */ 	lwc1	$f18,0x2c($v0)
/*  f15ce44:	e7b2004c */ 	swc1	$f18,0x4c($sp)
.L0f15ce48:
/*  f15ce48:	afbf0040 */ 	sw	$ra,0x40($sp)
/*  f15ce4c:	27a50050 */ 	addiu	$a1,$sp,0x50
/*  f15ce50:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f15ce54:	afa60064 */ 	sw	$a2,0x64($sp)
/*  f15ce58:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f15ce5c:	afa80038 */ 	sw	$t0,0x38($sp)
/*  f15ce60:	afa90034 */ 	sw	$t1,0x34($sp)
/*  f15ce64:	afaa0030 */ 	sw	$t2,0x30($sp)
/*  f15ce68:	0fc57423 */ 	jal	func0f15d08c
/*  f15ce6c:	afab002c */ 	sw	$t3,0x2c($sp)
/*  f15ce70:	3c0c800a */ 	lui	$t4,%hi(g_RoomPtrs)
/*  f15ce74:	3c0d800a */ 	lui	$t5,%hi(var800a4cf0)
/*  f15ce78:	25ad4cf0 */ 	addiu	$t5,$t5,%lo(var800a4cf0)
/*  f15ce7c:	258c4928 */ 	addiu	$t4,$t4,%lo(g_RoomPtrs)
/*  f15ce80:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f15ce84:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f15ce88:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f15ce8c:	8fa80038 */ 	lw	$t0,0x38($sp)
/*  f15ce90:	8fa90034 */ 	lw	$t1,0x34($sp)
/*  f15ce94:	8faa0030 */ 	lw	$t2,0x30($sp)
/*  f15ce98:	8fab002c */ 	lw	$t3,0x2c($sp)
/*  f15ce9c:	14400033 */ 	bnez	$v0,.L0f15cf6c
/*  f15cea0:	8fbf0040 */ 	lw	$ra,0x40($sp)
/*  f15cea4:	c7a40058 */ 	lwc1	$f4,0x58($sp)
/*  f15cea8:	c5a8000c */ 	lwc1	$f8,0xc($t5)
/*  f15ceac:	46002187 */ 	neg.s	$f6,$f4
/*  f15ceb0:	4606403e */ 	c.le.s	$f8,$f6
/*  f15ceb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ceb8:	45020003 */ 	bc1fl	.L0f15cec8
/*  f15cebc:	84cf0000 */ 	lh	$t7,0x0($a2)
/*  f15cec0:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f15cec4:	84cf0000 */ 	lh	$t7,0x0($a2)
.L0f15cec8:
/*  f15cec8:	c7b20050 */ 	lwc1	$f18,0x50($sp)
/*  f15cecc:	448f5000 */ 	mtc1	$t7,$f10
/*  f15ced0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ced4:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f15ced8:	4612803c */ 	c.lt.s	$f16,$f18
/*  f15cedc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cee0:	45020003 */ 	bc1fl	.L0f15cef0
/*  f15cee4:	84d80004 */ 	lh	$t8,0x4($a2)
/*  f15cee8:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f15ceec:	84d80004 */ 	lh	$t8,0x4($a2)
.L0f15cef0:
/*  f15cef0:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f15cef4:	44983000 */ 	mtc1	$t8,$f6
/*  f15cef8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cefc:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f15cf00:	4608203c */ 	c.lt.s	$f4,$f8
/*  f15cf04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cf08:	45020003 */ 	bc1fl	.L0f15cf18
/*  f15cf0c:	84d90002 */ 	lh	$t9,0x2($a2)
/*  f15cf10:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f15cf14:	84d90002 */ 	lh	$t9,0x2($a2)
.L0f15cf18:
/*  f15cf18:	c7b20054 */ 	lwc1	$f18,0x54($sp)
/*  f15cf1c:	44995000 */ 	mtc1	$t9,$f10
/*  f15cf20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cf24:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f15cf28:	4612803c */ 	c.lt.s	$f16,$f18
/*  f15cf2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cf30:	45020003 */ 	bc1fl	.L0f15cf40
/*  f15cf34:	84ce0006 */ 	lh	$t6,0x6($a2)
/*  f15cf38:	254a0001 */ 	addiu	$t2,$t2,0x1
/*  f15cf3c:	84ce0006 */ 	lh	$t6,0x6($a2)
.L0f15cf40:
/*  f15cf40:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*  f15cf44:	448e2000 */ 	mtc1	$t6,$f4
/*  f15cf48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cf4c:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f15cf50:	4608303c */ 	c.lt.s	$f6,$f8
/*  f15cf54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cf58:	45000002 */ 	bc1f	.L0f15cf64
/*  f15cf5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cf60:	256b0001 */ 	addiu	$t3,$t3,0x1
.L0f15cf64:
/*  f15cf64:	10000033 */ 	beqz	$zero,.L0f15d034
/*  f15cf68:	27ff0001 */ 	addiu	$ra,$ra,0x1
.L0f15cf6c:
/*  f15cf6c:	c7aa0058 */ 	lwc1	$f10,0x58($sp)
/*  f15cf70:	c5b2000c */ 	lwc1	$f18,0xc($t5)
/*  f15cf74:	46005407 */ 	neg.s	$f16,$f10
/*  f15cf78:	4610903e */ 	c.le.s	$f18,$f16
/*  f15cf7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cf80:	45020003 */ 	bc1fl	.L0f15cf90
/*  f15cf84:	84cf0000 */ 	lh	$t7,0x0($a2)
/*  f15cf88:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f15cf8c:	84cf0000 */ 	lh	$t7,0x0($a2)
.L0f15cf90:
/*  f15cf90:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f15cf94:	448f3000 */ 	mtc1	$t7,$f6
/*  f15cf98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cf9c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f15cfa0:	4608203c */ 	c.lt.s	$f4,$f8
/*  f15cfa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cfa8:	45020004 */ 	bc1fl	.L0f15cfbc
/*  f15cfac:	84d80004 */ 	lh	$t8,0x4($a2)
/*  f15cfb0:	1000000b */ 	beqz	$zero,.L0f15cfe0
/*  f15cfb4:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f15cfb8:	84d80004 */ 	lh	$t8,0x4($a2)
.L0f15cfbc:
/*  f15cfbc:	c7b20050 */ 	lwc1	$f18,0x50($sp)
/*  f15cfc0:	44985000 */ 	mtc1	$t8,$f10
/*  f15cfc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cfc8:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f15cfcc:	4612803c */ 	c.lt.s	$f16,$f18
/*  f15cfd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cfd4:	45020003 */ 	bc1fl	.L0f15cfe4
/*  f15cfd8:	84d90002 */ 	lh	$t9,0x2($a2)
/*  f15cfdc:	25290001 */ 	addiu	$t1,$t1,0x1
.L0f15cfe0:
/*  f15cfe0:	84d90002 */ 	lh	$t9,0x2($a2)
.L0f15cfe4:
/*  f15cfe4:	c7a60054 */ 	lwc1	$f6,0x54($sp)
/*  f15cfe8:	44992000 */ 	mtc1	$t9,$f4
/*  f15cfec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cff0:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f15cff4:	4608303c */ 	c.lt.s	$f6,$f8
/*  f15cff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15cffc:	45020004 */ 	bc1fl	.L0f15d010
/*  f15d000:	84ce0006 */ 	lh	$t6,0x6($a2)
/*  f15d004:	1000000b */ 	beqz	$zero,.L0f15d034
/*  f15d008:	254a0001 */ 	addiu	$t2,$t2,0x1
/*  f15d00c:	84ce0006 */ 	lh	$t6,0x6($a2)
.L0f15d010:
/*  f15d010:	c7b20054 */ 	lwc1	$f18,0x54($sp)
/*  f15d014:	448e5000 */ 	mtc1	$t6,$f10
/*  f15d018:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d01c:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f15d020:	4612803c */ 	c.lt.s	$f16,$f18
/*  f15d024:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d028:	45020003 */ 	bc1fl	.L0f15d038
/*  f15d02c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f15d030:	256b0001 */ 	addiu	$t3,$t3,0x1
.L0f15d034:
/*  f15d034:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f15d038:
/*  f15d038:	5471ff6a */ 	bnel	$v1,$s1,.L0f15cde4
/*  f15d03c:	306e0001 */ 	andi	$t6,$v1,0x1
/*  f15d040:	13f1000b */ 	beq	$ra,$s1,.L0f15d070
/*  f15d044:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d048:	10f10009 */ 	beq	$a3,$s1,.L0f15d070
/*  f15d04c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d050:	11110007 */ 	beq	$t0,$s1,.L0f15d070
/*  f15d054:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d058:	11310005 */ 	beq	$t1,$s1,.L0f15d070
/*  f15d05c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d060:	11510003 */ 	beq	$t2,$s1,.L0f15d070
/*  f15d064:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d068:	15710003 */ 	bne	$t3,$s1,.L0f15d078
/*  f15d06c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f15d070:
/*  f15d070:	10000001 */ 	beqz	$zero,.L0f15d078
/*  f15d074:	00001025 */ 	or	$v0,$zero,$zero
.L0f15d078:
/*  f15d078:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f15d07c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f15d080:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f15d084:	03e00008 */ 	jr	$ra
/*  f15d088:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f15d08c
/*  f15d08c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f15d090:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f15d094:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f15d098:	00a08025 */ 	or	$s0,$a1,$zero
/*  f15d09c:	0fc2d5be */ 	jal	currentPlayerGetUnk1740
/*  f15d0a0:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f15d0a4:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f15d0a8:	00402025 */ 	or	$a0,$v0,$zero
/*  f15d0ac:	02002825 */ 	or	$a1,$s0,$zero
/*  f15d0b0:	c4c40000 */ 	lwc1	$f4,0x0($a2)
/*  f15d0b4:	e6040000 */ 	swc1	$f4,0x0($s0)
/*  f15d0b8:	c4c60004 */ 	lwc1	$f6,0x4($a2)
/*  f15d0bc:	e6060004 */ 	swc1	$f6,0x4($s0)
/*  f15d0c0:	c4c80008 */ 	lwc1	$f8,0x8($a2)
/*  f15d0c4:	0c0056d9 */ 	jal	func00015b64
/*  f15d0c8:	e6080008 */ 	swc1	$f8,0x8($s0)
/*  f15d0cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f15d0d0:	0fc2d35a */ 	jal	func0f0b4d68
/*  f15d0d4:	02002825 */ 	or	$a1,$s0,$zero
/*  f15d0d8:	44805000 */ 	mtc1	$zero,$f10
/*  f15d0dc:	c6100008 */ 	lwc1	$f16,0x8($s0)
/*  f15d0e0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f15d0e4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f15d0e8:	4610503c */ 	c.lt.s	$f10,$f16
/*  f15d0ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d0f0:	45000003 */ 	bc1f	.L0f15d100
/*  f15d0f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d0f8:	10000001 */ 	beqz	$zero,.L0f15d100
/*  f15d0fc:	00001025 */ 	or	$v0,$zero,$zero
.L0f15d100:
/*  f15d100:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f15d104:	03e00008 */ 	jr	$ra
/*  f15d108:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f15d10c
/*  f15d10c:	3c07800a */ 	lui	$a3,%hi(g_Portals)
/*  f15d110:	24e74cec */ 	addiu	$a3,$a3,%lo(g_Portals)
/*  f15d114:	27bdfd00 */ 	addiu	$sp,$sp,-768
/*  f15d118:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f15d11c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f15d120:	00049100 */ 	sll	$s2,$a0,0x4
/*  f15d124:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f15d128:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f15d12c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f15d130:	3c0f8008 */ 	lui	$t7,%hi(var8007fc3c)
/*  f15d134:	01d21821 */ 	addu	$v1,$t6,$s2
/*  f15d138:	94780004 */ 	lhu	$t8,0x4($v1)
/*  f15d13c:	95effc3c */ 	lhu	$t7,%lo(var8007fc3c)($t7)
/*  f15d140:	00a08825 */ 	or	$s1,$a1,$zero
/*  f15d144:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f15d148:	15f80013 */ 	bne	$t7,$t8,.L0f15d198
/*  f15d14c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d150:	84790008 */ 	lh	$t9,0x8($v1)
/*  f15d154:	a4b90000 */ 	sh	$t9,0x0($a1)
/*  f15d158:	8ced0000 */ 	lw	$t5,0x0($a3)
/*  f15d15c:	01b27021 */ 	addu	$t6,$t5,$s2
/*  f15d160:	85cf000a */ 	lh	$t7,0xa($t6)
/*  f15d164:	a4af0002 */ 	sh	$t7,0x2($a1)
/*  f15d168:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f15d16c:	0312c821 */ 	addu	$t9,$t8,$s2
/*  f15d170:	872d000c */ 	lh	$t5,0xc($t9)
/*  f15d174:	a4ad0004 */ 	sh	$t5,0x4($a1)
/*  f15d178:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f15d17c:	01d27821 */ 	addu	$t7,$t6,$s2
/*  f15d180:	85f8000e */ 	lh	$t8,0xe($t7)
/*  f15d184:	a4b80006 */ 	sh	$t8,0x6($a1)
/*  f15d188:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f15d18c:	03326821 */ 	addu	$t5,$t9,$s2
/*  f15d190:	100000bf */ 	beqz	$zero,.L0f15d490
/*  f15d194:	85a20006 */ 	lh	$v0,0x6($t5)
.L0f15d198:
/*  f15d198:	0fc594d8 */ 	jal	func0f165360
/*  f15d19c:	27a502f0 */ 	addiu	$a1,$sp,0x2f0
/*  f15d1a0:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f15d1a4:	27b80050 */ 	addiu	$t8,$sp,0x50
/*  f15d1a8:	00401825 */ 	or	$v1,$v0,$zero
/*  f15d1ac:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f15d1b0:	00005825 */ 	or	$t3,$zero,$zero
/*  f15d1b4:	01f88021 */ 	addu	$s0,$t7,$t8
/*  f15d1b8:	18400039 */ 	blez	$v0,.L0f15d2a0
/*  f15d1bc:	00004825 */ 	or	$t1,$zero,$zero
/*  f15d1c0:	44807000 */ 	mtc1	$zero,$f14
/*  f15d1c4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f15d1c8:
/*  f15d1c8:	c6040008 */ 	lwc1	$f4,0x8($s0)
/*  f15d1cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f15d1d0:	27a502e4 */ 	addiu	$a1,$sp,0x2e4
/*  f15d1d4:	460e203e */ 	c.le.s	$f4,$f14
/*  f15d1d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d1dc:	4502002d */ 	bc1fl	.L0f15d294
/*  f15d1e0:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f15d1e4:	afa302f4 */ 	sw	$v1,0x2f4($sp)
/*  f15d1e8:	afa902f8 */ 	sw	$t1,0x2f8($sp)
/*  f15d1ec:	0fc2d35a */ 	jal	func0f0b4d68
/*  f15d1f0:	afab02ec */ 	sw	$t3,0x2ec($sp)
/*  f15d1f4:	8fab02ec */ 	lw	$t3,0x2ec($sp)
/*  f15d1f8:	44807000 */ 	mtc1	$zero,$f14
/*  f15d1fc:	8fa302f4 */ 	lw	$v1,0x2f4($sp)
/*  f15d200:	15600008 */ 	bnez	$t3,.L0f15d224
/*  f15d204:	8fa902f8 */ 	lw	$t1,0x2f8($sp)
/*  f15d208:	c7a002e4 */ 	lwc1	$f0,0x2e4($sp)
/*  f15d20c:	c7ac02e8 */ 	lwc1	$f12,0x2e8($sp)
/*  f15d210:	e7a002dc */ 	swc1	$f0,0x2dc($sp)
/*  f15d214:	e7a002d4 */ 	swc1	$f0,0x2d4($sp)
/*  f15d218:	e7ac02e0 */ 	swc1	$f12,0x2e0($sp)
/*  f15d21c:	1000001b */ 	beqz	$zero,.L0f15d28c
/*  f15d220:	e7ac02d8 */ 	swc1	$f12,0x2d8($sp)
.L0f15d224:
/*  f15d224:	c7a202e4 */ 	lwc1	$f2,0x2e4($sp)
/*  f15d228:	c7a602d4 */ 	lwc1	$f6,0x2d4($sp)
/*  f15d22c:	4606103c */ 	c.lt.s	$f2,$f6
/*  f15d230:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d234:	45020003 */ 	bc1fl	.L0f15d244
/*  f15d238:	c7a802dc */ 	lwc1	$f8,0x2dc($sp)
/*  f15d23c:	e7a202d4 */ 	swc1	$f2,0x2d4($sp)
/*  f15d240:	c7a802dc */ 	lwc1	$f8,0x2dc($sp)
.L0f15d244:
/*  f15d244:	4602403c */ 	c.lt.s	$f8,$f2
/*  f15d248:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d24c:	45020003 */ 	bc1fl	.L0f15d25c
/*  f15d250:	c7ac02e8 */ 	lwc1	$f12,0x2e8($sp)
/*  f15d254:	e7a202dc */ 	swc1	$f2,0x2dc($sp)
/*  f15d258:	c7ac02e8 */ 	lwc1	$f12,0x2e8($sp)
.L0f15d25c:
/*  f15d25c:	c7aa02d8 */ 	lwc1	$f10,0x2d8($sp)
/*  f15d260:	460a603c */ 	c.lt.s	$f12,$f10
/*  f15d264:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d268:	45020003 */ 	bc1fl	.L0f15d278
/*  f15d26c:	c7b002e0 */ 	lwc1	$f16,0x2e0($sp)
/*  f15d270:	e7ac02d8 */ 	swc1	$f12,0x2d8($sp)
/*  f15d274:	c7b002e0 */ 	lwc1	$f16,0x2e0($sp)
.L0f15d278:
/*  f15d278:	460c803c */ 	c.lt.s	$f16,$f12
/*  f15d27c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d280:	45020003 */ 	bc1fl	.L0f15d290
/*  f15d284:	256b0001 */ 	addiu	$t3,$t3,0x1
/*  f15d288:	e7ac02e0 */ 	swc1	$f12,0x2e0($sp)
.L0f15d28c:
/*  f15d28c:	256b0001 */ 	addiu	$t3,$t3,0x1
.L0f15d290:
/*  f15d290:	25290001 */ 	addiu	$t1,$t1,0x1
.L0f15d294:
/*  f15d294:	0123082a */ 	slt	$at,$t1,$v1
/*  f15d298:	1420ffcb */ 	bnez	$at,.L0f15d1c8
/*  f15d29c:	26100010 */ 	addiu	$s0,$s0,0x10
.L0f15d2a0:
/*  f15d2a0:	44807000 */ 	mtc1	$zero,$f14
/*  f15d2a4:	15600006 */ 	bnez	$t3,.L0f15d2c0
/*  f15d2a8:	c7b202dc */ 	lwc1	$f18,0x2dc($sp)
/*  f15d2ac:	a6200000 */ 	sh	$zero,0x0($s1)
/*  f15d2b0:	a6200004 */ 	sh	$zero,0x4($s1)
/*  f15d2b4:	a6200002 */ 	sh	$zero,0x2($s1)
/*  f15d2b8:	1000005a */ 	beqz	$zero,.L0f15d424
/*  f15d2bc:	a6200006 */ 	sh	$zero,0x6($s1)
.L0f15d2c0:
/*  f15d2c0:	c7a402d4 */ 	lwc1	$f4,0x2d4($sp)
/*  f15d2c4:	c7a602e0 */ 	lwc1	$f6,0x2e0($sp)
/*  f15d2c8:	c7a802d8 */ 	lwc1	$f8,0x2d8($sp)
/*  f15d2cc:	4604903c */ 	c.lt.s	$f18,$f4
/*  f15d2d0:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f15d2d4:	45010007 */ 	bc1t	.L0f15d2f4
/*  f15d2d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d2dc:	4608303c */ 	c.lt.s	$f6,$f8
/*  f15d2e0:	3c013f00 */ 	lui	$at,0x3f00
/*  f15d2e4:	c7b202d4 */ 	lwc1	$f18,0x2d4($sp)
/*  f15d2e8:	27a802d4 */ 	addiu	$t0,$sp,0x2d4
/*  f15d2ec:	45000016 */ 	bc1f	.L0f15d348
/*  f15d2f0:	02205025 */ 	or	$t2,$s1,$zero
.L0f15d2f4:
/*  f15d2f4:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f15d2f8:	c44a1794 */ 	lwc1	$f10,0x1794($v0)
/*  f15d2fc:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f15d300:	440d8000 */ 	mfc1	$t5,$f16
/*  f15d304:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d308:	a62d0000 */ 	sh	$t5,0x0($s1)
/*  f15d30c:	c4521798 */ 	lwc1	$f18,0x1798($v0)
/*  f15d310:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f15d314:	440f2000 */ 	mfc1	$t7,$f4
/*  f15d318:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d31c:	a62f0002 */ 	sh	$t7,0x2($s1)
/*  f15d320:	c446179c */ 	lwc1	$f6,0x179c($v0)
/*  f15d324:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f15d328:	44194000 */ 	mfc1	$t9,$f8
/*  f15d32c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d330:	a6390004 */ 	sh	$t9,0x4($s1)
/*  f15d334:	c44a17a0 */ 	lwc1	$f10,0x17a0($v0)
/*  f15d338:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f15d33c:	440e8000 */ 	mfc1	$t6,$f16
/*  f15d340:	10000038 */ 	beqz	$zero,.L0f15d424
/*  f15d344:	a62e0006 */ 	sh	$t6,0x6($s1)
.L0f15d348:
/*  f15d348:	44810000 */ 	mtc1	$at,$f0
/*  f15d34c:	c7a602d8 */ 	lwc1	$f6,0x2d8($sp)
/*  f15d350:	c7aa02dc */ 	lwc1	$f10,0x2dc($sp)
/*  f15d354:	46009101 */ 	sub.s	$f4,$f18,$f0
/*  f15d358:	c7b202e0 */ 	lwc1	$f18,0x2e0($sp)
/*  f15d35c:	3c01c6fa */ 	lui	$at,0xc6fa
/*  f15d360:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f15d364:	e7a402d4 */ 	swc1	$f4,0x2d4($sp)
/*  f15d368:	44816000 */ 	mtc1	$at,$f12
/*  f15d36c:	46005400 */ 	add.s	$f16,$f10,$f0
/*  f15d370:	3c0146fa */ 	lui	$at,0x46fa
/*  f15d374:	44811000 */ 	mtc1	$at,$f2
/*  f15d378:	46009100 */ 	add.s	$f4,$f18,$f0
/*  f15d37c:	e7a802d8 */ 	swc1	$f8,0x2d8($sp)
/*  f15d380:	e7b002dc */ 	swc1	$f16,0x2dc($sp)
/*  f15d384:	27ac02e4 */ 	addiu	$t4,$sp,0x2e4
/*  f15d388:	e7a402e0 */ 	swc1	$f4,0x2e0($sp)
/*  f15d38c:	24078300 */ 	addiu	$a3,$zero,-32000
/*  f15d390:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f15d394:	24057d00 */ 	addiu	$a1,$zero,0x7d00
.L0f15d398:
/*  f15d398:	01001825 */ 	or	$v1,$t0,$zero
/*  f15d39c:	00002025 */ 	or	$a0,$zero,$zero
/*  f15d3a0:	01401025 */ 	or	$v0,$t2,$zero
.L0f15d3a4:
/*  f15d3a4:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f15d3a8:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f15d3ac:	24840002 */ 	addiu	$a0,$a0,0x2
/*  f15d3b0:	4600703e */ 	c.le.s	$f14,$f0
/*  f15d3b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d3b8:	4502000c */ 	bc1fl	.L0f15d3ec
/*  f15d3bc:	460c003c */ 	c.lt.s	$f0,$f12
/*  f15d3c0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f15d3c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d3c8:	45020004 */ 	bc1fl	.L0f15d3dc
/*  f15d3cc:	4600018d */ 	trunc.w.s	$f6,$f0
/*  f15d3d0:	1000000f */ 	beqz	$zero,.L0f15d410
/*  f15d3d4:	a4450000 */ 	sh	$a1,0x0($v0)
/*  f15d3d8:	4600018d */ 	trunc.w.s	$f6,$f0
.L0f15d3dc:
/*  f15d3dc:	44183000 */ 	mfc1	$t8,$f6
/*  f15d3e0:	1000000b */ 	beqz	$zero,.L0f15d410
/*  f15d3e4:	a4580000 */ 	sh	$t8,0x0($v0)
/*  f15d3e8:	460c003c */ 	c.lt.s	$f0,$f12
.L0f15d3ec:
/*  f15d3ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d3f0:	45020004 */ 	bc1fl	.L0f15d404
/*  f15d3f4:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f15d3f8:	10000005 */ 	beqz	$zero,.L0f15d410
/*  f15d3fc:	a4470000 */ 	sh	$a3,0x0($v0)
/*  f15d400:	4600020d */ 	trunc.w.s	$f8,$f0
.L0f15d404:
/*  f15d404:	440d4000 */ 	mfc1	$t5,$f8
/*  f15d408:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d40c:	a44d0000 */ 	sh	$t5,0x0($v0)
.L0f15d410:
/*  f15d410:	1486ffe4 */ 	bne	$a0,$a2,.L0f15d3a4
/*  f15d414:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f15d418:	25080008 */ 	addiu	$t0,$t0,0x8
/*  f15d41c:	150cffde */ 	bne	$t0,$t4,.L0f15d398
/*  f15d420:	254a0004 */ 	addiu	$t2,$t2,0x4
.L0f15d424:
/*  f15d424:	3c03800a */ 	lui	$v1,%hi(g_Portals)
/*  f15d428:	24634cec */ 	addiu	$v1,$v1,%lo(g_Portals)
/*  f15d42c:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f15d430:	862e0000 */ 	lh	$t6,0x0($s1)
/*  f15d434:	01601025 */ 	or	$v0,$t3,$zero
/*  f15d438:	01f2c021 */ 	addu	$t8,$t7,$s2
/*  f15d43c:	a70e0008 */ 	sh	$t6,0x8($t8)
/*  f15d440:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f15d444:	86390002 */ 	lh	$t9,0x2($s1)
/*  f15d448:	01b27821 */ 	addu	$t7,$t5,$s2
/*  f15d44c:	a5f9000a */ 	sh	$t9,0xa($t7)
/*  f15d450:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f15d454:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f15d458:	03126821 */ 	addu	$t5,$t8,$s2
/*  f15d45c:	a5ae000c */ 	sh	$t6,0xc($t5)
/*  f15d460:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f15d464:	86390006 */ 	lh	$t9,0x6($s1)
/*  f15d468:	01f2c021 */ 	addu	$t8,$t7,$s2
/*  f15d46c:	a719000e */ 	sh	$t9,0xe($t8)
/*  f15d470:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f15d474:	3c0f8008 */ 	lui	$t7,%hi(var8007fc3c)
/*  f15d478:	01d26821 */ 	addu	$t5,$t6,$s2
/*  f15d47c:	a5ab0006 */ 	sh	$t3,0x6($t5)
/*  f15d480:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f15d484:	95effc3c */ 	lhu	$t7,%lo(var8007fc3c)($t7)
/*  f15d488:	0332c021 */ 	addu	$t8,$t9,$s2
/*  f15d48c:	a70f0004 */ 	sh	$t7,0x4($t8)
.L0f15d490:
/*  f15d490:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f15d494:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f15d498:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f15d49c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f15d4a0:	03e00008 */ 	jr	$ra
/*  f15d4a4:	27bd0300 */ 	addiu	$sp,$sp,0x300
);

GLOBAL_ASM(
glabel func0f15d4a8
/*  f15d4a8:	8fa80010 */ 	lw	$t0,0x10($sp)
/*  f15d4ac:	24ee0001 */ 	addiu	$t6,$a3,0x1
/*  f15d4b0:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f15d4b4:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f15d4b8:	3c01f600 */ 	lui	$at,0xf600
/*  f15d4bc:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f15d4c0:	312a03ff */ 	andi	$t2,$t1,0x3ff
/*  f15d4c4:	0301c825 */ 	or	$t9,$t8,$at
/*  f15d4c8:	30cf03ff */ 	andi	$t7,$a2,0x3ff
/*  f15d4cc:	30ad03ff */ 	andi	$t5,$a1,0x3ff
/*  f15d4d0:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f15d4d4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f15d4d8:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f15d4dc:	032b6025 */ 	or	$t4,$t9,$t3
/*  f15d4e0:	01d84025 */ 	or	$t0,$t6,$t8
/*  f15d4e4:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f15d4e8:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f15d4ec:	03e00008 */ 	jr	$ra
/*  f15d4f0:	24820008 */ 	addiu	$v0,$a0,0x8
/*  f15d4f4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f15d4f8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f15d4fc:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f15d500:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f15d504:	afa60010 */ 	sw	$a2,0x10($sp)
/*  f15d508:	0fc5752a */ 	jal	func0f15d4a8
/*  f15d50c:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f15d510:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f15d514:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f15d518:	00402025 */ 	or	$a0,$v0,$zero
/*  f15d51c:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f15d520:	00a03825 */ 	or	$a3,$a1,$zero
/*  f15d524:	0fc5752a */ 	jal	func0f15d4a8
/*  f15d528:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f15d52c:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f15d530:	00402025 */ 	or	$a0,$v0,$zero
/*  f15d534:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f15d538:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f15d53c:	0fc5752a */ 	jal	func0f15d4a8
/*  f15d540:	afa60010 */ 	sw	$a2,0x10($sp)
/*  f15d544:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f15d548:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f15d54c:	00402025 */ 	or	$a0,$v0,$zero
/*  f15d550:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f15d554:	00e02825 */ 	or	$a1,$a3,$zero
/*  f15d558:	0fc5752a */ 	jal	func0f15d4a8
/*  f15d55c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f15d560:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f15d564:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f15d568:	03e00008 */ 	jr	$ra
/*  f15d56c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15d570
/*  f15d570:	84a20000 */ 	lh	$v0,0x0($a1)
/*  f15d574:	84830000 */ 	lh	$v1,0x0($a0)
/*  f15d578:	0043082a */ 	slt	$at,$v0,$v1
/*  f15d57c:	50200004 */ 	beqzl	$at,.L0f15d590
/*  f15d580:	a4820000 */ 	sh	$v0,0x0($a0)
/*  f15d584:	10000002 */ 	beqz	$zero,.L0f15d590
/*  f15d588:	a4830000 */ 	sh	$v1,0x0($a0)
/*  f15d58c:	a4820000 */ 	sh	$v0,0x0($a0)
.L0f15d590:
/*  f15d590:	84a20002 */ 	lh	$v0,0x2($a1)
/*  f15d594:	84830002 */ 	lh	$v1,0x2($a0)
/*  f15d598:	0043082a */ 	slt	$at,$v0,$v1
/*  f15d59c:	50200004 */ 	beqzl	$at,.L0f15d5b0
/*  f15d5a0:	a4820002 */ 	sh	$v0,0x2($a0)
/*  f15d5a4:	10000002 */ 	beqz	$zero,.L0f15d5b0
/*  f15d5a8:	a4830002 */ 	sh	$v1,0x2($a0)
/*  f15d5ac:	a4820002 */ 	sh	$v0,0x2($a0)
.L0f15d5b0:
/*  f15d5b0:	84830004 */ 	lh	$v1,0x4($a0)
/*  f15d5b4:	84a20004 */ 	lh	$v0,0x4($a1)
/*  f15d5b8:	0062082a */ 	slt	$at,$v1,$v0
/*  f15d5bc:	50200004 */ 	beqzl	$at,.L0f15d5d0
/*  f15d5c0:	a4820004 */ 	sh	$v0,0x4($a0)
/*  f15d5c4:	10000002 */ 	beqz	$zero,.L0f15d5d0
/*  f15d5c8:	a4830004 */ 	sh	$v1,0x4($a0)
/*  f15d5cc:	a4820004 */ 	sh	$v0,0x4($a0)
.L0f15d5d0:
/*  f15d5d0:	84830006 */ 	lh	$v1,0x6($a0)
/*  f15d5d4:	84a20006 */ 	lh	$v0,0x6($a1)
/*  f15d5d8:	0062082a */ 	slt	$at,$v1,$v0
/*  f15d5dc:	50200004 */ 	beqzl	$at,.L0f15d5f0
/*  f15d5e0:	a4820006 */ 	sh	$v0,0x6($a0)
/*  f15d5e4:	10000002 */ 	beqz	$zero,.L0f15d5f0
/*  f15d5e8:	a4830006 */ 	sh	$v1,0x6($a0)
/*  f15d5ec:	a4820006 */ 	sh	$v0,0x6($a0)
.L0f15d5f0:
/*  f15d5f0:	84830004 */ 	lh	$v1,0x4($a0)
/*  f15d5f4:	848e0000 */ 	lh	$t6,0x0($a0)
/*  f15d5f8:	00001025 */ 	or	$v0,$zero,$zero
/*  f15d5fc:	01c3082a */ 	slt	$at,$t6,$v1
/*  f15d600:	54200004 */ 	bnezl	$at,.L0f15d614
/*  f15d604:	84830006 */ 	lh	$v1,0x6($a0)
/*  f15d608:	03e00008 */ 	jr	$ra
/*  f15d60c:	a4830000 */ 	sh	$v1,0x0($a0)
/*  f15d610:	84830006 */ 	lh	$v1,0x6($a0)
.L0f15d614:
/*  f15d614:	848f0002 */ 	lh	$t7,0x2($a0)
/*  f15d618:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f15d61c:	01e3082a */ 	slt	$at,$t7,$v1
/*  f15d620:	14200004 */ 	bnez	$at,.L0f15d634
/*  f15d624:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d628:	a4830002 */ 	sh	$v1,0x2($a0)
/*  f15d62c:	03e00008 */ 	jr	$ra
/*  f15d630:	00001025 */ 	or	$v0,$zero,$zero
.L0f15d634:
/*  f15d634:	03e00008 */ 	jr	$ra
/*  f15d638:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15d63c
/*  f15d63c:	84820000 */ 	lh	$v0,0x0($a0)
/*  f15d640:	84a30000 */ 	lh	$v1,0x0($a1)
/*  f15d644:	0043082a */ 	slt	$at,$v0,$v1
/*  f15d648:	50200004 */ 	beqzl	$at,.L0f15d65c
/*  f15d64c:	a4830000 */ 	sh	$v1,0x0($a0)
/*  f15d650:	10000002 */ 	beqz	$zero,.L0f15d65c
/*  f15d654:	a4820000 */ 	sh	$v0,0x0($a0)
/*  f15d658:	a4830000 */ 	sh	$v1,0x0($a0)
.L0f15d65c:
/*  f15d65c:	84820002 */ 	lh	$v0,0x2($a0)
/*  f15d660:	84a30002 */ 	lh	$v1,0x2($a1)
/*  f15d664:	0043082a */ 	slt	$at,$v0,$v1
/*  f15d668:	50200004 */ 	beqzl	$at,.L0f15d67c
/*  f15d66c:	a4830002 */ 	sh	$v1,0x2($a0)
/*  f15d670:	10000002 */ 	beqz	$zero,.L0f15d67c
/*  f15d674:	a4820002 */ 	sh	$v0,0x2($a0)
/*  f15d678:	a4830002 */ 	sh	$v1,0x2($a0)
.L0f15d67c:
/*  f15d67c:	84a20004 */ 	lh	$v0,0x4($a1)
/*  f15d680:	84830004 */ 	lh	$v1,0x4($a0)
/*  f15d684:	0043082a */ 	slt	$at,$v0,$v1
/*  f15d688:	50200004 */ 	beqzl	$at,.L0f15d69c
/*  f15d68c:	a4820004 */ 	sh	$v0,0x4($a0)
/*  f15d690:	10000002 */ 	beqz	$zero,.L0f15d69c
/*  f15d694:	a4830004 */ 	sh	$v1,0x4($a0)
/*  f15d698:	a4820004 */ 	sh	$v0,0x4($a0)
.L0f15d69c:
/*  f15d69c:	84a20006 */ 	lh	$v0,0x6($a1)
/*  f15d6a0:	84830006 */ 	lh	$v1,0x6($a0)
/*  f15d6a4:	0043082a */ 	slt	$at,$v0,$v1
/*  f15d6a8:	50200004 */ 	beqzl	$at,.L0f15d6bc
/*  f15d6ac:	a4820006 */ 	sh	$v0,0x6($a0)
/*  f15d6b0:	03e00008 */ 	jr	$ra
/*  f15d6b4:	a4830006 */ 	sh	$v1,0x6($a0)
/*  f15d6b8:	a4820006 */ 	sh	$v0,0x6($a0)
.L0f15d6bc:
/*  f15d6bc:	03e00008 */ 	jr	$ra
/*  f15d6c0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15d6c4
/*  f15d6c4:	84ae0000 */ 	lh	$t6,0x0($a1)
/*  f15d6c8:	a48e0000 */ 	sh	$t6,0x0($a0)
/*  f15d6cc:	84af0002 */ 	lh	$t7,0x2($a1)
/*  f15d6d0:	a48f0002 */ 	sh	$t7,0x2($a0)
/*  f15d6d4:	84b80004 */ 	lh	$t8,0x4($a1)
/*  f15d6d8:	a4980004 */ 	sh	$t8,0x4($a0)
/*  f15d6dc:	84b90006 */ 	lh	$t9,0x6($a1)
/*  f15d6e0:	03e00008 */ 	jr	$ra
/*  f15d6e4:	a4990006 */ 	sh	$t9,0x6($a0)
);

bool roomIsActive(s32 room_id)
{
	if (g_Vars.mplayerisrunning) {
		return (g_MpRoomVisibility[room_id] & 0xf) != 0;
	}

	return g_RoomPtrs[room_id].flags & ROOMFLAG_ACTIVE;
}

GLOBAL_ASM(
glabel func0f15d744
/*  f15d744:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x314)
/*  f15d748:	8dcea2d4 */ 	lw	$t6,%lo(g_Vars+0x314)($t6)
/*  f15d74c:	000450c0 */ 	sll	$t2,$a0,0x3
/*  f15d750:	01445021 */ 	addu	$t2,$t2,$a0
/*  f15d754:	11c00008 */ 	beqz	$t6,.L0f15d778
/*  f15d758:	3c09800a */ 	lui	$t1,%hi(g_RoomPtrs)
/*  f15d75c:	3c0f800a */ 	lui	$t7,%hi(g_MpRoomVisibility)
/*  f15d760:	8def492c */ 	lw	$t7,%lo(g_MpRoomVisibility)($t7)
/*  f15d764:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f15d768:	93020000 */ 	lbu	$v0,0x0($t8)
/*  f15d76c:	305900f0 */ 	andi	$t9,$v0,0xf0
/*  f15d770:	03e00008 */ 	jr	$ra
/*  f15d774:	0019102b */ 	sltu	$v0,$zero,$t9
.L0f15d778:
/*  f15d778:	8d294928 */ 	lw	$t1,%lo(g_RoomPtrs)($t1)
/*  f15d77c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f15d780:	01445023 */ 	subu	$t2,$t2,$a0
/*  f15d784:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f15d788:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f15d78c:	95620000 */ 	lhu	$v0,0x0($t3)
/*  f15d790:	304c0008 */ 	andi	$t4,$v0,0x8
/*  f15d794:	01801025 */ 	or	$v0,$t4,$zero
/*  f15d798:	03e00008 */ 	jr	$ra
/*  f15d79c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel roomIsVisibleByPlayer
/*  f15d7a0:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x314)
/*  f15d7a4:	8dcea2d4 */ 	lw	$t6,%lo(g_Vars+0x314)($t6)
/*  f15d7a8:	000460c0 */ 	sll	$t4,$a0,0x3
/*  f15d7ac:	01846021 */ 	addu	$t4,$t4,$a0
/*  f15d7b0:	11c0000b */ 	beqz	$t6,.L0f15d7e0
/*  f15d7b4:	3c0b800a */ 	lui	$t3,%hi(g_RoomPtrs)
/*  f15d7b8:	3c0f800a */ 	lui	$t7,%hi(g_MpRoomVisibility)
/*  f15d7bc:	8def492c */ 	lw	$t7,%lo(g_MpRoomVisibility)($t7)
/*  f15d7c0:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f15d7c4:	00a84804 */ 	sllv	$t1,$t0,$a1
/*  f15d7c8:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f15d7cc:	93190000 */ 	lbu	$t9,0x0($t8)
/*  f15d7d0:	03291024 */ 	and	$v0,$t9,$t1
/*  f15d7d4:	0002502b */ 	sltu	$t2,$zero,$v0
/*  f15d7d8:	03e00008 */ 	jr	$ra
/*  f15d7dc:	01401025 */ 	or	$v0,$t2,$zero
.L0f15d7e0:
/*  f15d7e0:	8d6b4928 */ 	lw	$t3,%lo(g_RoomPtrs)($t3)
/*  f15d7e4:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f15d7e8:	01846023 */ 	subu	$t4,$t4,$a0
/*  f15d7ec:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f15d7f0:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f15d7f4:	95a20000 */ 	lhu	$v0,0x0($t5)
/*  f15d7f8:	304e0004 */ 	andi	$t6,$v0,0x4
/*  f15d7fc:	01c01025 */ 	or	$v0,$t6,$zero
/*  f15d800:	03e00008 */ 	jr	$ra
/*  f15d804:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15d808
/*  f15d808:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x314)
/*  f15d80c:	8dcea2d4 */ 	lw	$t6,%lo(g_Vars+0x314)($t6)
/*  f15d810:	000460c0 */ 	sll	$t4,$a0,0x3
/*  f15d814:	01846021 */ 	addu	$t4,$t4,$a0
/*  f15d818:	11c0000b */ 	beqz	$t6,.L0f15d848
/*  f15d81c:	3c0b800a */ 	lui	$t3,%hi(g_RoomPtrs)
/*  f15d820:	3c0f800a */ 	lui	$t7,%hi(g_MpRoomVisibility)
/*  f15d824:	8def492c */ 	lw	$t7,%lo(g_MpRoomVisibility)($t7)
/*  f15d828:	24080010 */ 	addiu	$t0,$zero,0x10
/*  f15d82c:	00a84804 */ 	sllv	$t1,$t0,$a1
/*  f15d830:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f15d834:	93190000 */ 	lbu	$t9,0x0($t8)
/*  f15d838:	03291024 */ 	and	$v0,$t9,$t1
/*  f15d83c:	0002502b */ 	sltu	$t2,$zero,$v0
/*  f15d840:	03e00008 */ 	jr	$ra
/*  f15d844:	01401025 */ 	or	$v0,$t2,$zero
.L0f15d848:
/*  f15d848:	8d6b4928 */ 	lw	$t3,%lo(g_RoomPtrs)($t3)
/*  f15d84c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f15d850:	01846023 */ 	subu	$t4,$t4,$a0
/*  f15d854:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f15d858:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f15d85c:	95a20000 */ 	lhu	$v0,0x0($t5)
/*  f15d860:	304e0008 */ 	andi	$t6,$v0,0x8
/*  f15d864:	01c01025 */ 	or	$v0,$t6,$zero
/*  f15d868:	03e00008 */ 	jr	$ra
/*  f15d86c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15d870
/*  f15d870:	3c02800a */ 	lui	$v0,%hi(g_PortalSomethings)
/*  f15d874:	8c424cc8 */ 	lw	$v0,%lo(g_PortalSomethings)($v0)
/*  f15d878:	00803825 */ 	or	$a3,$a0,$zero
/*  f15d87c:	00001825 */ 	or	$v1,$zero,$zero
/*  f15d880:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f15d884:	00402825 */ 	or	$a1,$v0,$zero
/*  f15d888:	51c0000d */ 	beqzl	$t6,.L0f15d8c0
/*  f15d88c:	00001025 */ 	or	$v0,$zero,$zero
/*  f15d890:	94460000 */ 	lhu	$a2,0x0($v0)
/*  f15d894:	00c22021 */ 	addu	$a0,$a2,$v0
.L0f15d898:
/*  f15d898:	54870004 */ 	bnel	$a0,$a3,.L0f15d8ac
/*  f15d89c:	94a60008 */ 	lhu	$a2,0x8($a1)
/*  f15d8a0:	03e00008 */ 	jr	$ra
/*  f15d8a4:	00601025 */ 	or	$v0,$v1,$zero
/*  f15d8a8:	94a60008 */ 	lhu	$a2,0x8($a1)
.L0f15d8ac:
/*  f15d8ac:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f15d8b0:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f15d8b4:	54c0fff8 */ 	bnezl	$a2,.L0f15d898
/*  f15d8b8:	00c22021 */ 	addu	$a0,$a2,$v0
/*  f15d8bc:	00001025 */ 	or	$v0,$zero,$zero
.L0f15d8c0:
/*  f15d8c0:	03e00008 */ 	jr	$ra
/*  f15d8c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d8c8:	27bdfd10 */ 	addiu	$sp,$sp,-752
/*  f15d8cc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f15d8d0:	0fc47b70 */ 	jal	debug0f11edc0
/*  f15d8d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d8d8:	1040002f */ 	beqz	$v0,.L0f15d998
/*  f15d8dc:	3c06800a */ 	lui	$a2,%hi(g_Vars+0x2bc)
/*  f15d8e0:	8cc6a27c */ 	lw	$a2,%lo(g_Vars+0x2bc)($a2)
/*  f15d8e4:	00002025 */ 	or	$a0,$zero,$zero
/*  f15d8e8:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f15d8ec:	28c10002 */ 	slti	$at,$a2,0x2
/*  f15d8f0:	14200027 */ 	bnez	$at,.L0f15d990
/*  f15d8f4:	27a20030 */ 	addiu	$v0,$sp,0x30
/*  f15d8f8:	3c05800a */ 	lui	$a1,%hi(g_RoomPtrs)
/*  f15d8fc:	8ca54928 */ 	lw	$a1,%lo(g_RoomPtrs)($a1)
/*  f15d900:	240b002e */ 	addiu	$t3,$zero,0x2e
/*  f15d904:	240a004c */ 	addiu	$t2,$zero,0x4c
/*  f15d908:	2409000a */ 	addiu	$t1,$zero,0xa
/*  f15d90c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f15d910:	24070028 */ 	addiu	$a3,$zero,0x28
/*  f15d914:	24a5008c */ 	addiu	$a1,$a1,140
.L0f15d918:
/*  f15d918:	246effff */ 	addiu	$t6,$v1,-1
/*  f15d91c:	01c7001a */ 	div	$zero,$t6,$a3
/*  f15d920:	00007810 */ 	mfhi	$t7
/*  f15d924:	14e00002 */ 	bnez	$a3,.L0f15d930
/*  f15d928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d92c:	0007000d */ 	break	0x7
.L0f15d930:
/*  f15d930:	2401ffff */ 	addiu	$at,$zero,-1
/*  f15d934:	14e10004 */ 	bne	$a3,$at,.L0f15d948
/*  f15d938:	3c018000 */ 	lui	$at,0x8000
/*  f15d93c:	15c10002 */ 	bne	$t6,$at,.L0f15d948
/*  f15d940:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15d944:	0006000d */ 	break	0x6
.L0f15d948:
/*  f15d948:	55e00007 */ 	bnezl	$t7,.L0f15d968
/*  f15d94c:	84b80002 */ 	lh	$t8,0x2($a1)
/*  f15d950:	50680005 */ 	beql	$v1,$t0,.L0f15d968
/*  f15d954:	84b80002 */ 	lh	$t8,0x2($a1)
/*  f15d958:	a0490000 */ 	sb	$t1,0x0($v0)
/*  f15d95c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f15d960:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f15d964:	84b80002 */ 	lh	$t8,0x2($a1)
.L0f15d968:
/*  f15d968:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f15d96c:	24a5008c */ 	addiu	$a1,$a1,0x8c
/*  f15d970:	13000003 */ 	beqz	$t8,.L0f15d980
/*  f15d974:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f15d978:	10000002 */ 	beqz	$zero,.L0f15d984
/*  f15d97c:	a04a0000 */ 	sb	$t2,0x0($v0)
.L0f15d980:
/*  f15d980:	a04b0000 */ 	sb	$t3,0x0($v0)
.L0f15d984:
/*  f15d984:	0066082a */ 	slt	$at,$v1,$a2
/*  f15d988:	1420ffe3 */ 	bnez	$at,.L0f15d918
/*  f15d98c:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f15d990:
/*  f15d990:	03a4c821 */ 	addu	$t9,$sp,$a0
/*  f15d994:	a3200030 */ 	sb	$zero,0x30($t9)
.L0f15d998:
/*  f15d998:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f15d99c:	27bd02f0 */ 	addiu	$sp,$sp,0x2f0
/*  f15d9a0:	03e00008 */ 	jr	$ra
/*  f15d9a4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15d9a8
/*  f15d9a8:	27bdebe0 */ 	addiu	$sp,$sp,-5152
/*  f15d9ac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f15d9b0:	afa51424 */ 	sw	$a1,0x1424($sp)
/*  f15d9b4:	afa61428 */ 	sw	$a2,0x1428($sp)
/*  f15d9b8:	0c002277 */ 	jal	func000089dc
/*  f15d9bc:	afa41420 */ 	sw	$a0,0x1420($sp)
/*  f15d9c0:	8fa41420 */ 	lw	$a0,0x1420($sp)
/*  f15d9c4:	8fa51424 */ 	lw	$a1,0x1424($sp)
/*  f15d9c8:	10400005 */ 	beqz	$v0,.L0f15d9e0
/*  f15d9cc:	8fa61428 */ 	lw	$a2,0x1428($sp)
/*  f15d9d0:	0c001d3c */ 	jal	func000074f0
/*  f15d9d4:	27a6001c */ 	addiu	$a2,$sp,0x1c
/*  f15d9d8:	10000004 */ 	beqz	$zero,.L0f15d9ec
/*  f15d9dc:	00401825 */ 	or	$v1,$v0,$zero
.L0f15d9e0:
/*  f15d9e0:	0c012c5c */ 	jal	func0004b170
/*  f15d9e4:	afa6141c */ 	sw	$a2,0x141c($sp)
/*  f15d9e8:	8fa3141c */ 	lw	$v1,0x141c($sp)
.L0f15d9ec:
/*  f15d9ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f15d9f0:	27bd1420 */ 	addiu	$sp,$sp,0x1420
/*  f15d9f4:	00601025 */ 	or	$v0,$v1,$zero
/*  f15d9f8:	03e00008 */ 	jr	$ra
/*  f15d9fc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15da00
/*  f15da00:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f15da04:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f15da08:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f15da0c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f15da10:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f15da14:	00808025 */ 	or	$s0,$a0,$zero
/*  f15da18:	00a08825 */ 	or	$s1,$a1,$zero
/*  f15da1c:	00c09025 */ 	or	$s2,$a2,$zero
/*  f15da20:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f15da24:	afbf0024 */ 	sw	$ra,0x24($sp)
.L0f15da28:
/*  f15da28:	16000003 */ 	bnez	$s0,.L0f15da38
/*  f15da2c:	02202825 */ 	or	$a1,$s1,$zero
/*  f15da30:	10000019 */ 	beqz	$zero,.L0f15da98
/*  f15da34:	02401025 */ 	or	$v0,$s2,$zero
.L0f15da38:
/*  f15da38:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f15da3c:	02403025 */ 	or	$a2,$s2,$zero
/*  f15da40:	50400006 */ 	beqzl	$v0,.L0f15da5c
/*  f15da44:	8e020008 */ 	lw	$v0,0x8($s0)
/*  f15da48:	1053000e */ 	beq	$v0,$s3,.L0f15da84
/*  f15da4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15da50:	10000011 */ 	beqz	$zero,.L0f15da98
/*  f15da54:	02401025 */ 	or	$v0,$s2,$zero
/*  f15da58:	8e020008 */ 	lw	$v0,0x8($s0)
.L0f15da5c:
/*  f15da5c:	0222082b */ 	sltu	$at,$s1,$v0
/*  f15da60:	10200006 */ 	beqz	$at,.L0f15da7c
/*  f15da64:	0052082b */ 	sltu	$at,$v0,$s2
/*  f15da68:	54200004 */ 	bnezl	$at,.L0f15da7c
/*  f15da6c:	00409025 */ 	or	$s2,$v0,$zero
/*  f15da70:	16400002 */ 	bnez	$s2,.L0f15da7c
/*  f15da74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15da78:	00409025 */ 	or	$s2,$v0,$zero
.L0f15da7c:
/*  f15da7c:	1000ffea */ 	beqz	$zero,.L0f15da28
/*  f15da80:	8e100004 */ 	lw	$s0,0x4($s0)
.L0f15da84:
/*  f15da84:	0fc57680 */ 	jal	func0f15da00
/*  f15da88:	8e040008 */ 	lw	$a0,0x8($s0)
/*  f15da8c:	8e100004 */ 	lw	$s0,0x4($s0)
/*  f15da90:	1000ffe5 */ 	beqz	$zero,.L0f15da28
/*  f15da94:	00409025 */ 	or	$s2,$v0,$zero
.L0f15da98:
/*  f15da98:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f15da9c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f15daa0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f15daa4:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f15daa8:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f15daac:	03e00008 */ 	jr	$ra
/*  f15dab0:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f15dab4
/*  f15dab4:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f15dab8:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f15dabc:	3c0e800a */ 	lui	$t6,%hi(g_RoomPtrs)
/*  f15dac0:	8dce4928 */ 	lw	$t6,%lo(g_RoomPtrs)($t6)
/*  f15dac4:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f15dac8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f15dacc:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f15dad0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f15dad4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f15dad8:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f15dadc:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f15dae0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f15dae4:	8f020014 */ 	lw	$v0,0x14($t8)
/*  f15dae8:	30ca0001 */ 	andi	$t2,$a2,0x1
/*  f15daec:	00004025 */ 	or	$t0,$zero,$zero
/*  f15daf0:	8c59000c */ 	lw	$t9,0xc($v0)
/*  f15daf4:	8c470008 */ 	lw	$a3,0x8($v0)
/*  f15daf8:	00001825 */ 	or	$v1,$zero,$zero
/*  f15dafc:	1140000d */ 	beqz	$t2,.L0f15db34
/*  f15db00:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f15db04:	10e0000b */ 	beqz	$a3,.L0f15db34
/*  f15db08:	00e02025 */ 	or	$a0,$a3,$zero
/*  f15db0c:	00003025 */ 	or	$a2,$zero,$zero
/*  f15db10:	0fc57680 */ 	jal	func0f15da00
/*  f15db14:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f15db18:	8fab0030 */ 	lw	$t3,0x30($sp)
/*  f15db1c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f15db20:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f15db24:	15610003 */ 	bne	$t3,$at,.L0f15db34
/*  f15db28:	00404025 */ 	or	$t0,$v0,$zero
/*  f15db2c:	1000001e */ 	beqz	$zero,.L0f15dba8
/*  f15db30:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f15db34:
/*  f15db34:	8fac0030 */ 	lw	$t4,0x30($sp)
/*  f15db38:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f15db3c:	318d0002 */ 	andi	$t5,$t4,0x2
/*  f15db40:	11a0000e */ 	beqz	$t5,.L0f15db7c
/*  f15db44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15db48:	11c0000c */ 	beqz	$t6,.L0f15db7c
/*  f15db4c:	01c02025 */ 	or	$a0,$t6,$zero
/*  f15db50:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f15db54:	00003025 */ 	or	$a2,$zero,$zero
/*  f15db58:	0fc57680 */ 	jal	func0f15da00
/*  f15db5c:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f15db60:	8faf0030 */ 	lw	$t7,0x30($sp)
/*  f15db64:	24010002 */ 	addiu	$at,$zero,0x2
/*  f15db68:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*  f15db6c:	15e10003 */ 	bne	$t7,$at,.L0f15db7c
/*  f15db70:	00401825 */ 	or	$v1,$v0,$zero
/*  f15db74:	1000000c */ 	beqz	$zero,.L0f15dba8
/*  f15db78:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f15db7c:
/*  f15db7c:	11000009 */ 	beqz	$t0,.L0f15dba4
/*  f15db80:	00601025 */ 	or	$v0,$v1,$zero
/*  f15db84:	10600005 */ 	beqz	$v1,.L0f15db9c
/*  f15db88:	0068082b */ 	sltu	$at,$v1,$t0
/*  f15db8c:	10200003 */ 	beqz	$at,.L0f15db9c
/*  f15db90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15db94:	10000003 */ 	beqz	$zero,.L0f15dba4
/*  f15db98:	00601025 */ 	or	$v0,$v1,$zero
.L0f15db9c:
/*  f15db9c:	10000001 */ 	beqz	$zero,.L0f15dba4
/*  f15dba0:	01001025 */ 	or	$v0,$t0,$zero
.L0f15dba4:
/*  f15dba4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f15dba8:
/*  f15dba8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f15dbac:	03e00008 */ 	jr	$ra
/*  f15dbb0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15dbb4
/*  f15dbb4:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f15dbb8:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f15dbbc:	3c0e800a */ 	lui	$t6,%hi(g_RoomPtrs)
/*  f15dbc0:	8dce4928 */ 	lw	$t6,%lo(g_RoomPtrs)($t6)
/*  f15dbc4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f15dbc8:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f15dbcc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f15dbd0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f15dbd4:	8f020014 */ 	lw	$v0,0x14($t8)
/*  f15dbd8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f15dbdc:	8c460000 */ 	lw	$a2,0x0($v0)
/*  f15dbe0:	24430018 */ 	addiu	$v1,$v0,0x18
/*  f15dbe4:	24670014 */ 	addiu	$a3,$v1,0x14
/*  f15dbe8:	00c7082b */ 	sltu	$at,$a2,$a3
/*  f15dbec:	54200018 */ 	bnezl	$at,.L0f15dc50
/*  f15dbf0:	00001025 */ 	or	$v0,$zero,$zero
/*  f15dbf4:	90620000 */ 	lbu	$v0,0x0($v1)
.L0f15dbf8:
/*  f15dbf8:	50400006 */ 	beqzl	$v0,.L0f15dc14
/*  f15dbfc:	8c790008 */ 	lw	$t9,0x8($v1)
/*  f15dc00:	50440009 */ 	beql	$v0,$a0,.L0f15dc28
/*  f15dc04:	8c62000c */ 	lw	$v0,0xc($v1)
/*  f15dc08:	1000000c */ 	beqz	$zero,.L0f15dc3c
/*  f15dc0c:	00e01825 */ 	or	$v1,$a3,$zero
/*  f15dc10:	8c790008 */ 	lw	$t9,0x8($v1)
.L0f15dc14:
/*  f15dc14:	54b90009 */ 	bnel	$a1,$t9,.L0f15dc3c
/*  f15dc18:	00e01825 */ 	or	$v1,$a3,$zero
/*  f15dc1c:	03e00008 */ 	jr	$ra
/*  f15dc20:	8c62000c */ 	lw	$v0,0xc($v1)
/*  f15dc24:	8c62000c */ 	lw	$v0,0xc($v1)
.L0f15dc28:
/*  f15dc28:	0046082b */ 	sltu	$at,$v0,$a2
/*  f15dc2c:	50200003 */ 	beqzl	$at,.L0f15dc3c
/*  f15dc30:	00e01825 */ 	or	$v1,$a3,$zero
/*  f15dc34:	00403025 */ 	or	$a2,$v0,$zero
/*  f15dc38:	00e01825 */ 	or	$v1,$a3,$zero
.L0f15dc3c:
/*  f15dc3c:	24e70014 */ 	addiu	$a3,$a3,0x14
/*  f15dc40:	00c7082b */ 	sltu	$at,$a2,$a3
/*  f15dc44:	5020ffec */ 	beqzl	$at,.L0f15dbf8
/*  f15dc48:	90620000 */ 	lbu	$v0,0x0($v1)
/*  f15dc4c:	00001025 */ 	or	$v0,$zero,$zero
.L0f15dc50:
/*  f15dc50:	03e00008 */ 	jr	$ra
/*  f15dc54:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15dc58
/*  f15dc58:	27bdfd08 */ 	addiu	$sp,$sp,-760
/*  f15dc5c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f15dc60:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f15dc64:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f15dc68:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f15dc6c:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f15dc70:	108001f8 */ 	beqz	$a0,.L0f15e454
/*  f15dc74:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f15dc78:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x2bc)
/*  f15dc7c:	8dcea27c */ 	lw	$t6,%lo(g_Vars+0x2bc)($t6)
/*  f15dc80:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f15dc84:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f15dc88:	008e082a */ 	slt	$at,$a0,$t6
/*  f15dc8c:	102001f1 */ 	beqz	$at,.L0f15e454
/*  f15dc90:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f15dc94:	3c18800a */ 	lui	$t8,%hi(g_RoomPtrs)
/*  f15dc98:	8f184928 */ 	lw	$t8,%lo(g_RoomPtrs)($t8)
/*  f15dc9c:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f15dca0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f15dca4:	afaf0054 */ 	sw	$t7,0x54($sp)
/*  f15dca8:	030f1821 */ 	addu	$v1,$t8,$t7
/*  f15dcac:	846b0002 */ 	lh	$t3,0x2($v1)
/*  f15dcb0:	556001e9 */ 	bnezl	$t3,.L0f15e458
/*  f15dcb4:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f15dcb8:	8c620080 */ 	lw	$v0,0x80($v1)
/*  f15dcbc:	18400009 */ 	blez	$v0,.L0f15dce4
/*  f15dcc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15dcc4:	afa202f4 */ 	sw	$v0,0x2f4($sp)
/*  f15dcc8:	0fc47b6c */ 	jal	debug0f11edb0
/*  f15dccc:	afa402f8 */ 	sw	$a0,0x2f8($sp)
/*  f15dcd0:	10400007 */ 	beqz	$v0,.L0f15dcf0
/*  f15dcd4:	8fac02f4 */ 	lw	$t4,0x2f4($sp)
/*  f15dcd8:	258d0400 */ 	addiu	$t5,$t4,0x400
/*  f15dcdc:	10000004 */ 	beqz	$zero,.L0f15dcf0
/*  f15dce0:	afad02f4 */ 	sw	$t5,0x2f4($sp)
.L0f15dce4:
/*  f15dce4:	0c004b37 */ 	jal	func00012cdc
/*  f15dce8:	afa402f8 */ 	sw	$a0,0x2f8($sp)
/*  f15dcec:	afa202f4 */ 	sw	$v0,0x2f4($sp)
.L0f15dcf0:
/*  f15dcf0:	8fa402f4 */ 	lw	$a0,0x2f4($sp)
/*  f15dcf4:	0fc5796e */ 	jal	func0f15e5b8
/*  f15dcf8:	00002825 */ 	or	$a1,$zero,$zero
/*  f15dcfc:	0c004aac */ 	jal	func00012ab0
/*  f15dd00:	8fa402f4 */ 	lw	$a0,0x2f4($sp)
/*  f15dd04:	104001d3 */ 	beqz	$v0,.L0f15e454
/*  f15dd08:	0040a025 */ 	or	$s4,$v0,$zero
/*  f15dd0c:	0fc4f0dc */ 	jal	func0f13c370
/*  f15dd10:	87a402fa */ 	lh	$a0,0x2fa($sp)
/*  f15dd14:	8fb002f8 */ 	lw	$s0,0x2f8($sp)
/*  f15dd18:	3c11800a */ 	lui	$s1,%hi(var800a4cc4)
/*  f15dd1c:	26314cc4 */ 	addiu	$s1,$s1,%lo(var800a4cc4)
/*  f15dd20:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f15dd24:	00107080 */ 	sll	$t6,$s0,0x2
/*  f15dd28:	01d07021 */ 	addu	$t6,$t6,$s0
/*  f15dd2c:	000e8080 */ 	sll	$s0,$t6,0x2
/*  f15dd30:	01f01021 */ 	addu	$v0,$t7,$s0
/*  f15dd34:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f15dd38:	8c580014 */ 	lw	$t8,0x14($v0)
/*  f15dd3c:	3c04800a */ 	lui	$a0,%hi(var800a491c)
/*  f15dd40:	8c84491c */ 	lw	$a0,%lo(var800a491c)($a0)
/*  f15dd44:	03039023 */ 	subu	$s2,$t8,$v1
/*  f15dd48:	2652000f */ 	addiu	$s2,$s2,0xf
/*  f15dd4c:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f15dd50:	8fa702f4 */ 	lw	$a3,0x2f4($sp)
/*  f15dd54:	0241c824 */ 	and	$t9,$s2,$at
/*  f15dd58:	00645821 */ 	addu	$t3,$v1,$a0
/*  f15dd5c:	3c01f100 */ 	lui	$at,0xf100
/*  f15dd60:	3c0c8008 */ 	lui	$t4,%hi(var8007fc54)
/*  f15dd64:	01642823 */ 	subu	$a1,$t3,$a0
/*  f15dd68:	8d8cfc54 */ 	lw	$t4,%lo(var8007fc54)($t4)
/*  f15dd6c:	00a12821 */ 	addu	$a1,$a1,$at
/*  f15dd70:	00f9082a */ 	slt	$at,$a3,$t9
/*  f15dd74:	03209025 */ 	or	$s2,$t9,$zero
/*  f15dd78:	10200005 */ 	beqz	$at,.L0f15dd90
/*  f15dd7c:	00ac2823 */ 	subu	$a1,$a1,$t4
/*  f15dd80:	0fc4f0dc */ 	jal	func0f13c370
/*  f15dd84:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f15dd88:	100001b3 */ 	beqz	$zero,.L0f15e458
/*  f15dd8c:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f15dd90:
/*  f15dd90:	00f26823 */ 	subu	$t5,$a3,$s2
/*  f15dd94:	01b49821 */ 	addu	$s3,$t5,$s4
/*  f15dd98:	02602025 */ 	or	$a0,$s3,$zero
/*  f15dd9c:	0fc56c71 */ 	jal	func0f15b1c4
/*  f15dda0:	02403025 */ 	or	$a2,$s2,$zero
/*  f15dda4:	0c002277 */ 	jal	func000089dc
/*  f15dda8:	02602025 */ 	or	$a0,$s3,$zero
/*  f15ddac:	10400009 */ 	beqz	$v0,.L0f15ddd4
/*  f15ddb0:	8fae02f4 */ 	lw	$t6,0x2f4($sp)
/*  f15ddb4:	264f0020 */ 	addiu	$t7,$s2,0x20
/*  f15ddb8:	01cf082a */ 	slt	$at,$t6,$t7
/*  f15ddbc:	50200006 */ 	beqzl	$at,.L0f15ddd8
/*  f15ddc0:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15ddc4:	0fc4f0dc */ 	jal	func0f13c370
/*  f15ddc8:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f15ddcc:	100001a2 */ 	beqz	$zero,.L0f15e458
/*  f15ddd0:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f15ddd4:
/*  f15ddd4:	8e380000 */ 	lw	$t8,0x0($s1)
.L0f15ddd8:
/*  f15ddd8:	02602025 */ 	or	$a0,$s3,$zero
/*  f15dddc:	02802825 */ 	or	$a1,$s4,$zero
/*  f15dde0:	03101021 */ 	addu	$v0,$t8,$s0
/*  f15dde4:	8c590014 */ 	lw	$t9,0x14($v0)
/*  f15dde8:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f15ddec:	0fc5766a */ 	jal	func0f15d9a8
/*  f15ddf0:	032b3023 */ 	subu	$a2,$t9,$t3
/*  f15ddf4:	3c09800a */ 	lui	$t1,%hi(g_RoomPtrs)
/*  f15ddf8:	25294928 */ 	addiu	$t1,$t1,%lo(g_RoomPtrs)
/*  f15ddfc:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f15de00:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f15de04:	afa202f0 */ 	sw	$v0,0x2f0($sp)
/*  f15de08:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f15de0c:	01886821 */ 	addu	$t5,$t4,$t0
/*  f15de10:	adb40014 */ 	sw	$s4,0x14($t5)
/*  f15de14:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f15de18:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f15de1c:	8df30014 */ 	lw	$s3,0x14($t7)
/*  f15de20:	8e630000 */ 	lw	$v1,0x0($s3)
/*  f15de24:	5060000b */ 	beqzl	$v1,.L0f15de54
/*  f15de28:	8e620004 */ 	lw	$v0,0x4($s3)
/*  f15de2c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15de30:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f15de34:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f15de38:	006b6023 */ 	subu	$t4,$v1,$t3
/*  f15de3c:	01946821 */ 	addu	$t5,$t4,$s4
/*  f15de40:	ae6d0000 */ 	sw	$t5,0x0($s3)
/*  f15de44:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f15de48:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f15de4c:	8df30014 */ 	lw	$s3,0x14($t7)
/*  f15de50:	8e620004 */ 	lw	$v0,0x4($s3)
.L0f15de54:
/*  f15de54:	5040000b */ 	beqzl	$v0,.L0f15de84
/*  f15de58:	8e620008 */ 	lw	$v0,0x8($s3)
/*  f15de5c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15de60:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f15de64:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f15de68:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f15de6c:	01946821 */ 	addu	$t5,$t4,$s4
/*  f15de70:	ae6d0004 */ 	sw	$t5,0x4($s3)
/*  f15de74:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f15de78:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f15de7c:	8df30014 */ 	lw	$s3,0x14($t7)
/*  f15de80:	8e620008 */ 	lw	$v0,0x8($s3)
.L0f15de84:
/*  f15de84:	5040000b */ 	beqzl	$v0,.L0f15deb4
/*  f15de88:	8e62000c */ 	lw	$v0,0xc($s3)
/*  f15de8c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15de90:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f15de94:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f15de98:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f15de9c:	01946821 */ 	addu	$t5,$t4,$s4
/*  f15dea0:	ae6d0008 */ 	sw	$t5,0x8($s3)
/*  f15dea4:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f15dea8:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f15deac:	8df30014 */ 	lw	$s3,0x14($t7)
/*  f15deb0:	8e62000c */ 	lw	$v0,0xc($s3)
.L0f15deb4:
/*  f15deb4:	5040000b */ 	beqzl	$v0,.L0f15dee4
/*  f15deb8:	8e620000 */ 	lw	$v0,0x0($s3)
/*  f15debc:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15dec0:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f15dec4:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f15dec8:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f15decc:	01946821 */ 	addu	$t5,$t4,$s4
/*  f15ded0:	ae6d000c */ 	sw	$t5,0xc($s3)
/*  f15ded4:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f15ded8:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f15dedc:	8df30014 */ 	lw	$s3,0x14($t7)
/*  f15dee0:	8e620000 */ 	lw	$v0,0x0($s3)
.L0f15dee4:
/*  f15dee4:	26630018 */ 	addiu	$v1,$s3,0x18
/*  f15dee8:	24650014 */ 	addiu	$a1,$v1,0x14
/*  f15deec:	0045082b */ 	sltu	$at,$v0,$a1
/*  f15def0:	14200060 */ 	bnez	$at,.L0f15e074
/*  f15def4:	00402025 */ 	or	$a0,$v0,$zero
/*  f15def8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f15defc:	90620000 */ 	lbu	$v0,0x0($v1)
.L0f15df00:
/*  f15df00:	50400006 */ 	beqzl	$v0,.L0f15df1c
/*  f15df04:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f15df08:	50470029 */ 	beql	$v0,$a3,.L0f15dfb0
/*  f15df0c:	8c620004 */ 	lw	$v0,0x4($v1)
/*  f15df10:	10000050 */ 	beqz	$zero,.L0f15e054
/*  f15df14:	00a01825 */ 	or	$v1,$a1,$zero
/*  f15df18:	8c620004 */ 	lw	$v0,0x4($v1)
.L0f15df1c:
/*  f15df1c:	50400008 */ 	beqzl	$v0,.L0f15df40
/*  f15df20:	8c620008 */ 	lw	$v0,0x8($v1)
/*  f15df24:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15df28:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f15df2c:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f15df30:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f15df34:	01946821 */ 	addu	$t5,$t4,$s4
/*  f15df38:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f15df3c:	8c620008 */ 	lw	$v0,0x8($v1)
.L0f15df40:
/*  f15df40:	50400008 */ 	beqzl	$v0,.L0f15df64
/*  f15df44:	8c62000c */ 	lw	$v0,0xc($v1)
/*  f15df48:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f15df4c:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f15df50:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f15df54:	0058c823 */ 	subu	$t9,$v0,$t8
/*  f15df58:	03345821 */ 	addu	$t3,$t9,$s4
/*  f15df5c:	ac6b0008 */ 	sw	$t3,0x8($v1)
/*  f15df60:	8c62000c */ 	lw	$v0,0xc($v1)
.L0f15df64:
/*  f15df64:	50400008 */ 	beqzl	$v0,.L0f15df88
/*  f15df68:	8c620010 */ 	lw	$v0,0x10($v1)
/*  f15df6c:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f15df70:	01906821 */ 	addu	$t5,$t4,$s0
/*  f15df74:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f15df78:	004e7823 */ 	subu	$t7,$v0,$t6
/*  f15df7c:	01f4c021 */ 	addu	$t8,$t7,$s4
/*  f15df80:	ac78000c */ 	sw	$t8,0xc($v1)
/*  f15df84:	8c620010 */ 	lw	$v0,0x10($v1)
.L0f15df88:
/*  f15df88:	50400032 */ 	beqzl	$v0,.L0f15e054
/*  f15df8c:	00a01825 */ 	or	$v1,$a1,$zero
/*  f15df90:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f15df94:	03305821 */ 	addu	$t3,$t9,$s0
/*  f15df98:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*  f15df9c:	004c6823 */ 	subu	$t5,$v0,$t4
/*  f15dfa0:	01b47021 */ 	addu	$t6,$t5,$s4
/*  f15dfa4:	1000002a */ 	beqz	$zero,.L0f15e050
/*  f15dfa8:	ac6e0010 */ 	sw	$t6,0x10($v1)
/*  f15dfac:	8c620004 */ 	lw	$v0,0x4($v1)
.L0f15dfb0:
/*  f15dfb0:	50400008 */ 	beqzl	$v0,.L0f15dfd4
/*  f15dfb4:	8c620008 */ 	lw	$v0,0x8($v1)
/*  f15dfb8:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f15dfbc:	01f0c021 */ 	addu	$t8,$t7,$s0
/*  f15dfc0:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f15dfc4:	00595823 */ 	subu	$t3,$v0,$t9
/*  f15dfc8:	01746021 */ 	addu	$t4,$t3,$s4
/*  f15dfcc:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f15dfd0:	8c620008 */ 	lw	$v0,0x8($v1)
.L0f15dfd4:
/*  f15dfd4:	50400008 */ 	beqzl	$v0,.L0f15dff8
/*  f15dfd8:	8c62000c */ 	lw	$v0,0xc($v1)
/*  f15dfdc:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f15dfe0:	01b07021 */ 	addu	$t6,$t5,$s0
/*  f15dfe4:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f15dfe8:	004fc023 */ 	subu	$t8,$v0,$t7
/*  f15dfec:	0314c821 */ 	addu	$t9,$t8,$s4
/*  f15dff0:	ac790008 */ 	sw	$t9,0x8($v1)
/*  f15dff4:	8c62000c */ 	lw	$v0,0xc($v1)
.L0f15dff8:
/*  f15dff8:	50400008 */ 	beqzl	$v0,.L0f15e01c
/*  f15dffc:	8c620010 */ 	lw	$v0,0x10($v1)
/*  f15e000:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f15e004:	01706021 */ 	addu	$t4,$t3,$s0
/*  f15e008:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f15e00c:	004d7023 */ 	subu	$t6,$v0,$t5
/*  f15e010:	01d47821 */ 	addu	$t7,$t6,$s4
/*  f15e014:	ac6f000c */ 	sw	$t7,0xc($v1)
/*  f15e018:	8c620010 */ 	lw	$v0,0x10($v1)
.L0f15e01c:
/*  f15e01c:	50400008 */ 	beqzl	$v0,.L0f15e040
/*  f15e020:	8c62000c */ 	lw	$v0,0xc($v1)
/*  f15e024:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f15e028:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f15e02c:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f15e030:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f15e034:	01946821 */ 	addu	$t5,$t4,$s4
/*  f15e038:	ac6d0010 */ 	sw	$t5,0x10($v1)
/*  f15e03c:	8c62000c */ 	lw	$v0,0xc($v1)
.L0f15e040:
/*  f15e040:	0044082b */ 	sltu	$at,$v0,$a0
/*  f15e044:	50200003 */ 	beqzl	$at,.L0f15e054
/*  f15e048:	00a01825 */ 	or	$v1,$a1,$zero
/*  f15e04c:	00402025 */ 	or	$a0,$v0,$zero
.L0f15e050:
/*  f15e050:	00a01825 */ 	or	$v1,$a1,$zero
.L0f15e054:
/*  f15e054:	24a50014 */ 	addiu	$a1,$a1,0x14
/*  f15e058:	0085082b */ 	sltu	$at,$a0,$a1
/*  f15e05c:	5020ffa8 */ 	beqzl	$at,.L0f15df00
/*  f15e060:	90620000 */ 	lbu	$v0,0x0($v1)
/*  f15e064:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f15e068:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f15e06c:	8df30014 */ 	lw	$s3,0x14($t7)
/*  f15e070:	8e620000 */ 	lw	$v0,0x0($s3)
.L0f15e074:
/*  f15e074:	8e780004 */ 	lw	$t8,0x4($s3)
/*  f15e078:	2401000c */ 	addiu	$at,$zero,0xc
/*  f15e07c:	00002825 */ 	or	$a1,$zero,$zero
/*  f15e080:	0302c823 */ 	subu	$t9,$t8,$v0
/*  f15e084:	0321001b */ 	divu	$zero,$t9,$at
/*  f15e088:	00005812 */ 	mflo	$t3
/*  f15e08c:	a66b0014 */ 	sh	$t3,0x14($s3)
/*  f15e090:	0fc576ad */ 	jal	func0f15dab4
/*  f15e094:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f15e098:	3c0c800a */ 	lui	$t4,%hi(g_RoomPtrs)
/*  f15e09c:	8d8c4928 */ 	lw	$t4,%lo(g_RoomPtrs)($t4)
/*  f15e0a0:	8fad0054 */ 	lw	$t5,0x54($sp)
/*  f15e0a4:	00009025 */ 	or	$s2,$zero,$zero
/*  f15e0a8:	00002825 */ 	or	$a1,$zero,$zero
/*  f15e0ac:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f15e0b0:	8dd30014 */ 	lw	$s3,0x14($t6)
/*  f15e0b4:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f15e0b8:	8e6f0004 */ 	lw	$t7,0x4($s3)
/*  f15e0bc:	004fc023 */ 	subu	$t8,$v0,$t7
/*  f15e0c0:	0018c882 */ 	srl	$t9,$t8,0x2
/*  f15e0c4:	a6790016 */ 	sh	$t9,0x16($s3)
/*  f15e0c8:	0fc576ad */ 	jal	func0f15dab4
/*  f15e0cc:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f15e0d0:	10400014 */ 	beqz	$v0,.L0f15e124
/*  f15e0d4:	00408025 */ 	or	$s0,$v0,$zero
/*  f15e0d8:	00121080 */ 	sll	$v0,$s2,0x2
/*  f15e0dc:	27ab0208 */ 	addiu	$t3,$sp,0x208
/*  f15e0e0:	27ac0140 */ 	addiu	$t4,$sp,0x140
/*  f15e0e4:	004c8821 */ 	addu	$s1,$v0,$t4
/*  f15e0e8:	004b9821 */ 	addu	$s3,$v0,$t3
.L0f15e0ec:
/*  f15e0ec:	ae700000 */ 	sw	$s0,0x0($s3)
/*  f15e0f0:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f15e0f4:	0fc576ed */ 	jal	func0f15dbb4
/*  f15e0f8:	02002825 */ 	or	$a1,$s0,$zero
/*  f15e0fc:	ae220000 */ 	sw	$v0,0x0($s1)
/*  f15e100:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f15e104:	26730004 */ 	addiu	$s3,$s3,0x4
/*  f15e108:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f15e10c:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f15e110:	02002825 */ 	or	$a1,$s0,$zero
/*  f15e114:	0fc576ad */ 	jal	func0f15dab4
/*  f15e118:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f15e11c:	1440fff3 */ 	bnez	$v0,.L0f15e0ec
/*  f15e120:	00408025 */ 	or	$s0,$v0,$zero
.L0f15e124:
/*  f15e124:	8fae02f0 */ 	lw	$t6,0x2f0($sp)
/*  f15e128:	00123880 */ 	sll	$a3,$s2,0x2
/*  f15e12c:	27ad0208 */ 	addiu	$t5,$sp,0x208
/*  f15e130:	00ed9821 */ 	addu	$s3,$a3,$t5
/*  f15e134:	028e1021 */ 	addu	$v0,$s4,$t6
/*  f15e138:	ae620000 */ 	sw	$v0,0x0($s3)
/*  f15e13c:	8fb802f4 */ 	lw	$t8,0x2f4($sp)
/*  f15e140:	8fa40208 */ 	lw	$a0,0x208($sp)
/*  f15e144:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f15e148:	02988021 */ 	addu	$s0,$s4,$t8
/*  f15e14c:	00441823 */ 	subu	$v1,$v0,$a0
/*  f15e150:	02032823 */ 	subu	$a1,$s0,$v1
/*  f15e154:	0fc5d7bd */ 	jal	func0f175ef4
/*  f15e158:	00603025 */ 	or	$a2,$v1,$zero
/*  f15e15c:	26420001 */ 	addiu	$v0,$s2,0x1
/*  f15e160:	1840000d */ 	blez	$v0,.L0f15e198
/*  f15e164:	00004025 */ 	or	$t0,$zero,$zero
/*  f15e168:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15e16c:	27a90078 */ 	addiu	$t1,$sp,0x78
/*  f15e170:	27a30208 */ 	addiu	$v1,$sp,0x208
/*  f15e174:	02192023 */ 	subu	$a0,$s0,$t9
.L0f15e178:
/*  f15e178:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f15e17c:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f15e180:	25290004 */ 	addiu	$t1,$t1,0x4
/*  f15e184:	008b6021 */ 	addu	$t4,$a0,$t3
/*  f15e188:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f15e18c:	1502fffa */ 	bne	$t0,$v0,.L0f15e178
/*  f15e190:	ad2cfffc */ 	sw	$t4,-0x4($t1)
/*  f15e194:	00004025 */ 	or	$t0,$zero,$zero
.L0f15e198:
/*  f15e198:	1a40001e */ 	blez	$s2,.L0f15e214
/*  f15e19c:	8fa60208 */ 	lw	$a2,0x208($sp)
/*  f15e1a0:	27a90078 */ 	addiu	$t1,$sp,0x78
/*  f15e1a4:	27a30208 */ 	addiu	$v1,$sp,0x208
/*  f15e1a8:	27b00140 */ 	addiu	$s0,$sp,0x140
.L0f15e1ac:
/*  f15e1ac:	8c6d0004 */ 	lw	$t5,0x4($v1)
/*  f15e1b0:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f15e1b4:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f15e1b8:	8d240000 */ 	lw	$a0,0x0($t1)
/*  f15e1bc:	afa90040 */ 	sw	$t1,0x40($sp)
/*  f15e1c0:	afa8006c */ 	sw	$t0,0x6c($sp)
/*  f15e1c4:	afa602dc */ 	sw	$a2,0x2dc($sp)
/*  f15e1c8:	afa30038 */ 	sw	$v1,0x38($sp)
/*  f15e1cc:	00003825 */ 	or	$a3,$zero,$zero
/*  f15e1d0:	01ae2823 */ 	subu	$a1,$t5,$t6
/*  f15e1d4:	0fc5d5b0 */ 	jal	func0f1756c0
/*  f15e1d8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f15e1dc:	8fa602dc */ 	lw	$a2,0x2dc($sp)
/*  f15e1e0:	8fa90040 */ 	lw	$t1,0x40($sp)
/*  f15e1e4:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f15e1e8:	8fa8006c */ 	lw	$t0,0x6c($sp)
/*  f15e1ec:	ad260000 */ 	sw	$a2,0x0($t1)
/*  f15e1f0:	00c23021 */ 	addu	$a2,$a2,$v0
/*  f15e1f4:	24c60007 */ 	addiu	$a2,$a2,0x7
/*  f15e1f8:	34cf0007 */ 	ori	$t7,$a2,0x7
/*  f15e1fc:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f15e200:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f15e204:	39e60007 */ 	xori	$a2,$t7,0x7
/*  f15e208:	25290004 */ 	addiu	$t1,$t1,0x4
/*  f15e20c:	1512ffe7 */ 	bne	$t0,$s2,.L0f15e1ac
/*  f15e210:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f15e214:
/*  f15e214:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f15e218:	27b00078 */ 	addiu	$s0,$sp,0x78
/*  f15e21c:	3c0d800a */ 	lui	$t5,%hi(g_RoomPtrs)
/*  f15e220:	020b6021 */ 	addu	$t4,$s0,$t3
/*  f15e224:	ad860000 */ 	sw	$a2,0x0($t4)
/*  f15e228:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f15e22c:	8dad4928 */ 	lw	$t5,%lo(g_RoomPtrs)($t5)
/*  f15e230:	00d4c023 */ 	subu	$t8,$a2,$s4
/*  f15e234:	270f002f */ 	addiu	$t7,$t8,0x2f
/*  f15e238:	35f9000f */ 	ori	$t9,$t7,0xf
/*  f15e23c:	3b2b000f */ 	xori	$t3,$t9,0xf
/*  f15e240:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f15e244:	ac6b0080 */ 	sw	$t3,0x80($v1)
/*  f15e248:	3c0c800a */ 	lui	$t4,%hi(g_RoomPtrs)
/*  f15e24c:	8d8c4928 */ 	lw	$t4,%lo(g_RoomPtrs)($t4)
/*  f15e250:	8fad0054 */ 	lw	$t5,0x54($sp)
/*  f15e254:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f15e258:	3c0e800a */ 	lui	$t6,%hi(g_RoomPtrs)
/*  f15e25c:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f15e260:	a46a0002 */ 	sh	$t2,0x2($v1)
/*  f15e264:	8fb80054 */ 	lw	$t8,0x54($sp)
/*  f15e268:	8dce4928 */ 	lw	$t6,%lo(g_RoomPtrs)($t6)
/*  f15e26c:	8faf02f4 */ 	lw	$t7,0x2f4($sp)
/*  f15e270:	02802025 */ 	or	$a0,$s4,$zero
/*  f15e274:	01d81821 */ 	addu	$v1,$t6,$t8
/*  f15e278:	8c620080 */ 	lw	$v0,0x80($v1)
/*  f15e27c:	01e02825 */ 	or	$a1,$t7,$zero
/*  f15e280:	51e20009 */ 	beql	$t7,$v0,.L0f15e2a8
/*  f15e284:	8c730014 */ 	lw	$s3,0x14($v1)
/*  f15e288:	0c004b52 */ 	jal	func00012d48
/*  f15e28c:	00403025 */ 	or	$a2,$v0,$zero
/*  f15e290:	3c19800a */ 	lui	$t9,%hi(g_RoomPtrs)
/*  f15e294:	8f394928 */ 	lw	$t9,%lo(g_RoomPtrs)($t9)
/*  f15e298:	8fab0054 */ 	lw	$t3,0x54($sp)
/*  f15e29c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f15e2a0:	032b1821 */ 	addu	$v1,$t9,$t3
/*  f15e2a4:	8c730014 */ 	lw	$s3,0x14($v1)
.L0f15e2a8:
/*  f15e2a8:	3c18800a */ 	lui	$t8,%hi(var800a65e0)
/*  f15e2ac:	3c0f800a */ 	lui	$t7,%hi(g_RoomPtrs)
/*  f15e2b0:	8e670000 */ 	lw	$a3,0x0($s3)
/*  f15e2b4:	26650018 */ 	addiu	$a1,$s3,0x18
/*  f15e2b8:	24a90014 */ 	addiu	$t1,$a1,0x14
/*  f15e2bc:	00e9082b */ 	sltu	$at,$a3,$t1
/*  f15e2c0:	14200026 */ 	bnez	$at,.L0f15e35c
/*  f15e2c4:	3c19800a */ 	lui	$t9,%hi(var800a65e4)
/*  f15e2c8:	90a20000 */ 	lbu	$v0,0x0($a1)
.L0f15e2cc:
/*  f15e2cc:	50400006 */ 	beqzl	$v0,.L0f15e2e8
/*  f15e2d0:	8ca60008 */ 	lw	$a2,0x8($a1)
/*  f15e2d4:	504a0018 */ 	beql	$v0,$t2,.L0f15e338
/*  f15e2d8:	8ca2000c */ 	lw	$v0,0xc($a1)
/*  f15e2dc:	1000001b */ 	beqz	$zero,.L0f15e34c
/*  f15e2e0:	01202825 */ 	or	$a1,$t1,$zero
/*  f15e2e4:	8ca60008 */ 	lw	$a2,0x8($a1)
.L0f15e2e8:
/*  f15e2e8:	50c00018 */ 	beqzl	$a2,.L0f15e34c
/*  f15e2ec:	01202825 */ 	or	$a1,$t1,$zero
/*  f15e2f0:	1a400015 */ 	blez	$s2,.L0f15e348
/*  f15e2f4:	00004025 */ 	or	$t0,$zero,$zero
/*  f15e2f8:	00001025 */ 	or	$v0,$zero,$zero
/*  f15e2fc:	27a30208 */ 	addiu	$v1,$sp,0x208
/*  f15e300:	00c02025 */ 	or	$a0,$a2,$zero
.L0f15e304:
/*  f15e304:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f15e308:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f15e30c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f15e310:	148c0004 */ 	bne	$a0,$t4,.L0f15e324
/*  f15e314:	02026821 */ 	addu	$t5,$s0,$v0
/*  f15e318:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f15e31c:	1000000a */ 	beqz	$zero,.L0f15e348
/*  f15e320:	acae0008 */ 	sw	$t6,0x8($a1)
.L0f15e324:
/*  f15e324:	1512fff7 */ 	bne	$t0,$s2,.L0f15e304
/*  f15e328:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f15e32c:	10000007 */ 	beqz	$zero,.L0f15e34c
/*  f15e330:	01202825 */ 	or	$a1,$t1,$zero
/*  f15e334:	8ca2000c */ 	lw	$v0,0xc($a1)
.L0f15e338:
/*  f15e338:	0047082b */ 	sltu	$at,$v0,$a3
/*  f15e33c:	50200003 */ 	beqzl	$at,.L0f15e34c
/*  f15e340:	01202825 */ 	or	$a1,$t1,$zero
/*  f15e344:	00403825 */ 	or	$a3,$v0,$zero
.L0f15e348:
/*  f15e348:	01202825 */ 	or	$a1,$t1,$zero
.L0f15e34c:
/*  f15e34c:	25290014 */ 	addiu	$t1,$t1,0x14
/*  f15e350:	00e9082b */ 	sltu	$at,$a3,$t1
/*  f15e354:	5020ffdd */ 	beqzl	$at,.L0f15e2cc
/*  f15e358:	90a20000 */ 	lbu	$v0,0x0($a1)
.L0f15e35c:
/*  f15e35c:	8f1865e0 */ 	lw	$t8,%lo(var800a65e0)($t8)
/*  f15e360:	13000012 */ 	beqz	$t8,.L0f15e3ac
/*  f15e364:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15e368:	8def4928 */ 	lw	$t7,%lo(g_RoomPtrs)($t7)
/*  f15e36c:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f15e370:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f15e374:	01f95821 */ 	addu	$t3,$t7,$t9
/*  f15e378:	8d6c0014 */ 	lw	$t4,0x14($t3)
/*  f15e37c:	0fc595ca */ 	jal	func0f165728
/*  f15e380:	8d840008 */ 	lw	$a0,0x8($t4)
/*  f15e384:	3c0d800a */ 	lui	$t5,%hi(g_RoomPtrs)
/*  f15e388:	8dad4928 */ 	lw	$t5,%lo(g_RoomPtrs)($t5)
/*  f15e38c:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f15e390:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f15e394:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f15e398:	8f0f0014 */ 	lw	$t7,0x14($t8)
/*  f15e39c:	0fc595ca */ 	jal	func0f165728
/*  f15e3a0:	8de4000c */ 	lw	$a0,0xc($t7)
/*  f15e3a4:	10000014 */ 	beqz	$zero,.L0f15e3f8
/*  f15e3a8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f15e3ac:
/*  f15e3ac:	8f3965e4 */ 	lw	$t9,%lo(var800a65e4)($t9)
/*  f15e3b0:	3c0b800a */ 	lui	$t3,%hi(g_RoomPtrs)
/*  f15e3b4:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f15e3b8:	1720000f */ 	bnez	$t9,.L0f15e3f8
/*  f15e3bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15e3c0:	8d6b4928 */ 	lw	$t3,%lo(g_RoomPtrs)($t3)
/*  f15e3c4:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f15e3c8:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f15e3cc:	8dae0014 */ 	lw	$t6,0x14($t5)
/*  f15e3d0:	0fc595ca */ 	jal	func0f165728
/*  f15e3d4:	8dc40008 */ 	lw	$a0,0x8($t6)
/*  f15e3d8:	3c18800a */ 	lui	$t8,%hi(g_RoomPtrs)
/*  f15e3dc:	8f184928 */ 	lw	$t8,%lo(g_RoomPtrs)($t8)
/*  f15e3e0:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f15e3e4:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f15e3e8:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f15e3ec:	8f2b0014 */ 	lw	$t3,0x14($t9)
/*  f15e3f0:	0fc595ca */ 	jal	func0f165728
/*  f15e3f4:	8d64000c */ 	lw	$a0,0xc($t3)
.L0f15e3f8:
/*  f15e3f8:	0fc57be7 */ 	jal	func0f15ef9c
/*  f15e3fc:	8fa402f8 */ 	lw	$a0,0x2f8($sp)
/*  f15e400:	3c0c800a */ 	lui	$t4,%hi(g_RoomPtrs)
/*  f15e404:	8d8c4928 */ 	lw	$t4,%lo(g_RoomPtrs)($t4)
/*  f15e408:	8fad0054 */ 	lw	$t5,0x54($sp)
/*  f15e40c:	3c0f800a */ 	lui	$t7,%hi(g_RoomPtrs)
/*  f15e410:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f15e414:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f15e418:	946e0000 */ 	lhu	$t6,0x0($v1)
/*  f15e41c:	3c0d800a */ 	lui	$t5,%hi(g_RoomPtrs)
/*  f15e420:	35d80100 */ 	ori	$t8,$t6,0x100
/*  f15e424:	a4780000 */ 	sh	$t8,0x0($v1)
/*  f15e428:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f15e42c:	8def4928 */ 	lw	$t7,%lo(g_RoomPtrs)($t7)
/*  f15e430:	01f91821 */ 	addu	$v1,$t7,$t9
/*  f15e434:	946b0000 */ 	lhu	$t3,0x0($v1)
/*  f15e438:	356c0200 */ 	ori	$t4,$t3,0x200
/*  f15e43c:	a46c0000 */ 	sh	$t4,0x0($v1)
/*  f15e440:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f15e444:	8dad4928 */ 	lw	$t5,%lo(g_RoomPtrs)($t5)
/*  f15e448:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f15e44c:	0fc4f0dc */ 	jal	func0f13c370
/*  f15e450:	af000058 */ 	sw	$zero,0x58($t8)
.L0f15e454:
/*  f15e454:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f15e458:
/*  f15e458:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f15e45c:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f15e460:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f15e464:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f15e468:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f15e46c:	03e00008 */ 	jr	$ra
/*  f15e470:	27bd02f8 */ 	addiu	$sp,$sp,0x2f8
);

GLOBAL_ASM(
glabel func0f15e474
/*  f15e474:	000418c0 */ 	sll	$v1,$a0,0x3
/*  f15e478:	00641821 */ 	addu	$v1,$v1,$a0
/*  f15e47c:	3c0e800a */ 	lui	$t6,%hi(g_RoomPtrs)
/*  f15e480:	8dce4928 */ 	lw	$t6,%lo(g_RoomPtrs)($t6)
/*  f15e484:	00031880 */ 	sll	$v1,$v1,0x2
/*  f15e488:	00641823 */ 	subu	$v1,$v1,$a0
/*  f15e48c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f15e490:	00031880 */ 	sll	$v1,$v1,0x2
/*  f15e494:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f15e498:	01c31021 */ 	addu	$v0,$t6,$v1
/*  f15e49c:	8c460044 */ 	lw	$a2,0x44($v0)
/*  f15e4a0:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f15e4a4:	50c00012 */ 	beqzl	$a2,.L0f15e4f0
/*  f15e4a8:	8c460080 */ 	lw	$a2,0x80($v0)
/*  f15e4ac:	8c450040 */ 	lw	$a1,0x40($v0)
/*  f15e4b0:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f15e4b4:	00c02025 */ 	or	$a0,$a2,$zero
/*  f15e4b8:	00057940 */ 	sll	$t7,$a1,0x5
/*  f15e4bc:	25e5000f */ 	addiu	$a1,$t7,0xf
/*  f15e4c0:	00a1c024 */ 	and	$t8,$a1,$at
/*  f15e4c4:	0c004b2d */ 	jal	func00012cb4
/*  f15e4c8:	03002825 */ 	or	$a1,$t8,$zero
/*  f15e4cc:	3c19800a */ 	lui	$t9,%hi(g_RoomPtrs)
/*  f15e4d0:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f15e4d4:	8f394928 */ 	lw	$t9,%lo(g_RoomPtrs)($t9)
/*  f15e4d8:	3c09800a */ 	lui	$t1,%hi(g_RoomPtrs)
/*  f15e4dc:	03234021 */ 	addu	$t0,$t9,$v1
/*  f15e4e0:	ad000044 */ 	sw	$zero,0x44($t0)
/*  f15e4e4:	8d294928 */ 	lw	$t1,%lo(g_RoomPtrs)($t1)
/*  f15e4e8:	01231021 */ 	addu	$v0,$t1,$v1
/*  f15e4ec:	8c460080 */ 	lw	$a2,0x80($v0)
.L0f15e4f0:
/*  f15e4f0:	18c0000c */ 	blez	$a2,.L0f15e524
/*  f15e4f4:	00c02825 */ 	or	$a1,$a2,$zero
/*  f15e4f8:	8c440014 */ 	lw	$a0,0x14($v0)
/*  f15e4fc:	0c004b2d */ 	jal	func00012cb4
/*  f15e500:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f15e504:	3c0a800a */ 	lui	$t2,%hi(g_RoomPtrs)
/*  f15e508:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f15e50c:	8d4a4928 */ 	lw	$t2,%lo(g_RoomPtrs)($t2)
/*  f15e510:	3c0c800a */ 	lui	$t4,%hi(g_RoomPtrs)
/*  f15e514:	01435821 */ 	addu	$t3,$t2,$v1
/*  f15e518:	ad600014 */ 	sw	$zero,0x14($t3)
/*  f15e51c:	8d8c4928 */ 	lw	$t4,%lo(g_RoomPtrs)($t4)
/*  f15e520:	01831021 */ 	addu	$v0,$t4,$v1
.L0f15e524:
/*  f15e524:	a4400002 */ 	sh	$zero,0x2($v0)
/*  f15e528:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f15e52c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f15e530:	03e00008 */ 	jr	$ra
/*  f15e534:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15e538
/*  f15e538:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x2bc)
/*  f15e53c:	8c42a27c */ 	lw	$v0,%lo(g_Vars+0x2bc)($v0)
/*  f15e540:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f15e544:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f15e548:	28410002 */ 	slti	$at,$v0,0x2
/*  f15e54c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f15e550:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f15e554:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f15e558:	14200011 */ 	bnez	$at,.L0f15e5a0
/*  f15e55c:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f15e560:	3c12800a */ 	lui	$s2,%hi(g_RoomPtrs)
/*  f15e564:	26524928 */ 	addiu	$s2,$s2,%lo(g_RoomPtrs)
/*  f15e568:	2410008c */ 	addiu	$s0,$zero,0x8c
.L0f15e56c:
/*  f15e56c:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f15e570:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f15e574:	85f80002 */ 	lh	$t8,0x2($t7)
/*  f15e578:	53000006 */ 	beqzl	$t8,.L0f15e594
/*  f15e57c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f15e580:	0fc5791d */ 	jal	func0f15e474
/*  f15e584:	02202025 */ 	or	$a0,$s1,$zero
/*  f15e588:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x2bc)
/*  f15e58c:	8c42a27c */ 	lw	$v0,%lo(g_Vars+0x2bc)($v0)
/*  f15e590:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f15e594:
/*  f15e594:	0222082a */ 	slt	$at,$s1,$v0
/*  f15e598:	1420fff4 */ 	bnez	$at,.L0f15e56c
/*  f15e59c:	2610008c */ 	addiu	$s0,$s0,0x8c
.L0f15e5a0:
/*  f15e5a0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f15e5a4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f15e5a8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f15e5ac:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f15e5b0:	03e00008 */ 	jr	$ra
/*  f15e5b4:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f15e5b8
/*  f15e5b8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f15e5bc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f15e5c0:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f15e5c4:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f15e5c8:	0080a025 */ 	or	$s4,$a0,$zero
/*  f15e5cc:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f15e5d0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f15e5d4:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f15e5d8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f15e5dc:	0c004b37 */ 	jal	func00012cdc
/*  f15e5e0:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f15e5e4:	0054082a */ 	slt	$at,$v0,$s4
/*  f15e5e8:	10200046 */ 	beqz	$at,.L0f15e704
/*  f15e5ec:	00008825 */ 	or	$s1,$zero,$zero
/*  f15e5f0:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f15e5f4:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f15e5f8:	2413001e */ 	addiu	$s3,$zero,0x1e
/*  f15e5fc:	8e4502bc */ 	lw	$a1,0x2bc($s2)
.L0f15e600:
/*  f15e600:	00003025 */ 	or	$a2,$zero,$zero
/*  f15e604:	00002025 */ 	or	$a0,$zero,$zero
/*  f15e608:	28a10002 */ 	slti	$at,$a1,0x2
/*  f15e60c:	1420000e */ 	bnez	$at,.L0f15e648
/*  f15e610:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f15e614:	3c02800a */ 	lui	$v0,%hi(g_RoomPtrs)
/*  f15e618:	8c424928 */ 	lw	$v0,%lo(g_RoomPtrs)($v0)
/*  f15e61c:	2442008c */ 	addiu	$v0,$v0,140
.L0f15e620:
/*  f15e620:	84430002 */ 	lh	$v1,0x2($v0)
/*  f15e624:	0083082a */ 	slt	$at,$a0,$v1
/*  f15e628:	50200004 */ 	beqzl	$at,.L0f15e63c
/*  f15e62c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15e630:	02003025 */ 	or	$a2,$s0,$zero
/*  f15e634:	00602025 */ 	or	$a0,$v1,$zero
/*  f15e638:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f15e63c:
/*  f15e63c:	0205082a */ 	slt	$at,$s0,$a1
/*  f15e640:	1420fff7 */ 	bnez	$at,.L0f15e620
/*  f15e644:	2442008c */ 	addiu	$v0,$v0,0x8c
.L0f15e648:
/*  f15e648:	10c00005 */ 	beqz	$a2,.L0f15e660
/*  f15e64c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15e650:	0fc5791d */ 	jal	func0f15e474
/*  f15e654:	00c02025 */ 	or	$a0,$a2,$zero
/*  f15e658:	0c0049ee */ 	jal	func000127b8
/*  f15e65c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f15e660:
/*  f15e660:	0c004b37 */ 	jal	func00012cdc
/*  f15e664:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15e668:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f15e66c:	16330022 */ 	bne	$s1,$s3,.L0f15e6f8
/*  f15e670:	00401825 */ 	or	$v1,$v0,$zero
/*  f15e674:	24010001 */ 	addiu	$at,$zero,0x1
/*  f15e678:	56a10023 */ 	bnel	$s5,$at,.L0f15e708
/*  f15e67c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f15e680:	8e4e02bc */ 	lw	$t6,0x2bc($s2)
/*  f15e684:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f15e688:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f15e68c:	29c10002 */ 	slti	$at,$t6,0x2
/*  f15e690:	1420001c */ 	bnez	$at,.L0f15e704
/*  f15e694:	3c13800a */ 	lui	$s3,%hi(g_RoomPtrs)
/*  f15e698:	26734928 */ 	addiu	$s3,$s3,%lo(g_RoomPtrs)
/*  f15e69c:	8e6f0000 */ 	lw	$t7,0x0($s3)
.L0f15e6a0:
/*  f15e6a0:	01f1c021 */ 	addu	$t8,$t7,$s1
/*  f15e6a4:	87190002 */ 	lh	$t9,0x2($t8)
/*  f15e6a8:	2b210009 */ 	slti	$at,$t9,0x9
/*  f15e6ac:	5420000b */ 	bnezl	$at,.L0f15e6dc
/*  f15e6b0:	8e4802bc */ 	lw	$t0,0x2bc($s2)
/*  f15e6b4:	0fc5791d */ 	jal	func0f15e474
/*  f15e6b8:	02002025 */ 	or	$a0,$s0,$zero
/*  f15e6bc:	0c0049ee */ 	jal	func000127b8
/*  f15e6c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15e6c4:	0c004b37 */ 	jal	func00012cdc
/*  f15e6c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15e6cc:	0054082a */ 	slt	$at,$v0,$s4
/*  f15e6d0:	5020000d */ 	beqzl	$at,.L0f15e708
/*  f15e6d4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f15e6d8:	8e4802bc */ 	lw	$t0,0x2bc($s2)
.L0f15e6dc:
/*  f15e6dc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15e6e0:	2631008c */ 	addiu	$s1,$s1,0x8c
/*  f15e6e4:	0208082a */ 	slt	$at,$s0,$t0
/*  f15e6e8:	5420ffed */ 	bnezl	$at,.L0f15e6a0
/*  f15e6ec:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f15e6f0:	10000005 */ 	beqz	$zero,.L0f15e708
/*  f15e6f4:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f15e6f8:
/*  f15e6f8:	0074082a */ 	slt	$at,$v1,$s4
/*  f15e6fc:	5420ffc0 */ 	bnezl	$at,.L0f15e600
/*  f15e700:	8e4502bc */ 	lw	$a1,0x2bc($s2)
.L0f15e704:
/*  f15e704:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f15e708:
/*  f15e708:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f15e70c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f15e710:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f15e714:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f15e718:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f15e71c:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f15e720:	03e00008 */ 	jr	$ra
/*  f15e724:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f15e728
/*  f15e728:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f15e72c:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f15e730:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f15e734:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f15e738:	8e8e02bc */ 	lw	$t6,0x2bc($s4)
/*  f15e73c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f15e740:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f15e744:	29c10002 */ 	slti	$at,$t6,0x2
/*  f15e748:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f15e74c:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f15e750:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f15e754:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f15e758:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f15e75c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f15e760:	00009025 */ 	or	$s2,$zero,$zero
/*  f15e764:	14200032 */ 	bnez	$at,.L0f15e830
/*  f15e768:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f15e76c:	3c17800a */ 	lui	$s7,%hi(var800a4bf0+0x2)
/*  f15e770:	3c15800a */ 	lui	$s5,%hi(var800a4bf0)
/*  f15e774:	3c13800a */ 	lui	$s3,%hi(g_RoomPtrs)
/*  f15e778:	26734928 */ 	addiu	$s3,$s3,%lo(g_RoomPtrs)
/*  f15e77c:	26b54bf0 */ 	addiu	$s5,$s5,%lo(var800a4bf0)
/*  f15e780:	26f74bf2 */ 	addiu	$s7,$s7,%lo(var800a4bf0+0x2)
/*  f15e784:	2410008c */ 	addiu	$s0,$zero,0x8c
/*  f15e788:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f15e78c:	8e6f0000 */ 	lw	$t7,0x0($s3)
.L0f15e790:
/*  f15e790:	01f01021 */ 	addu	$v0,$t7,$s0
/*  f15e794:	84430002 */ 	lh	$v1,0x2($v0)
/*  f15e798:	1060001f */ 	beqz	$v1,.L0f15e818
/*  f15e79c:	24780001 */ 	addiu	$t8,$v1,0x1
/*  f15e7a0:	a4580002 */ 	sh	$t8,0x2($v0)
/*  f15e7a4:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f15e7a8:	96a40000 */ 	lhu	$a0,0x0($s5)
/*  f15e7ac:	03301021 */ 	addu	$v0,$t9,$s0
/*  f15e7b0:	84480002 */ 	lh	$t0,0x2($v0)
/*  f15e7b4:	0104082a */ 	slt	$at,$t0,$a0
/*  f15e7b8:	54200005 */ 	bnezl	$at,.L0f15e7d0
/*  f15e7bc:	944a0000 */ 	lhu	$t2,0x0($v0)
/*  f15e7c0:	a4440002 */ 	sh	$a0,0x2($v0)
/*  f15e7c4:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f15e7c8:	01301021 */ 	addu	$v0,$t1,$s0
/*  f15e7cc:	944a0000 */ 	lhu	$t2,0x0($v0)
.L0f15e7d0:
/*  f15e7d0:	2a410002 */ 	slti	$at,$s2,0x2
/*  f15e7d4:	314b0004 */ 	andi	$t3,$t2,0x4
/*  f15e7d8:	11600002 */ 	beqz	$t3,.L0f15e7e4
/*  f15e7dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15e7e0:	a4560002 */ 	sh	$s6,0x2($v0)
.L0f15e7e4:
/*  f15e7e4:	5020000d */ 	beqzl	$at,.L0f15e81c
/*  f15e7e8:	8e9802bc */ 	lw	$t8,0x2bc($s4)
/*  f15e7ec:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f15e7f0:	96ec0000 */ 	lhu	$t4,0x0($s7)
/*  f15e7f4:	01b07021 */ 	addu	$t6,$t5,$s0
/*  f15e7f8:	85cf0002 */ 	lh	$t7,0x2($t6)
/*  f15e7fc:	558f0007 */ 	bnel	$t4,$t7,.L0f15e81c
/*  f15e800:	8e9802bc */ 	lw	$t8,0x2bc($s4)
/*  f15e804:	0fc5791d */ 	jal	func0f15e474
/*  f15e808:	02202025 */ 	or	$a0,$s1,$zero
/*  f15e80c:	0c0049ee */ 	jal	func000127b8
/*  f15e810:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15e814:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f15e818:
/*  f15e818:	8e9802bc */ 	lw	$t8,0x2bc($s4)
.L0f15e81c:
/*  f15e81c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f15e820:	2610008c */ 	addiu	$s0,$s0,0x8c
/*  f15e824:	0238082a */ 	slt	$at,$s1,$t8
/*  f15e828:	5420ffd9 */ 	bnezl	$at,.L0f15e790
/*  f15e82c:	8e6f0000 */ 	lw	$t7,0x0($s3)
.L0f15e830:
/*  f15e830:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f15e834:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f15e838:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f15e83c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f15e840:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f15e844:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f15e848:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f15e84c:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f15e850:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f15e854:	03e00008 */ 	jr	$ra
/*  f15e858:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f15e85c
/*  f15e85c:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f15e860:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f15e864:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f15e868:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f15e86c:	00808025 */ 	or	$s0,$a0,$zero
/*  f15e870:	00c08825 */ 	or	$s1,$a2,$zero
/*  f15e874:	00a09025 */ 	or	$s2,$a1,$zero
/*  f15e878:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f15e87c:	14c00003 */ 	bnez	$a2,.L0f15e88c
/*  f15e880:	afa7007c */ 	sw	$a3,0x7c($sp)
/*  f15e884:	100000a2 */ 	beqz	$zero,.L0f15eb10
/*  f15e888:	00801025 */ 	or	$v0,$a0,$zero
.L0f15e88c:
/*  f15e88c:	92220000 */ 	lbu	$v0,0x0($s1)
/*  f15e890:	001218c0 */ 	sll	$v1,$s2,0x3
/*  f15e894:	00721821 */ 	addu	$v1,$v1,$s2
/*  f15e898:	10400006 */ 	beqz	$v0,.L0f15e8b4
/*  f15e89c:	00031880 */ 	sll	$v1,$v1,0x2
/*  f15e8a0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f15e8a4:	5041004f */ 	beql	$v0,$at,.L0f15e9e4
/*  f15e8a8:	8e240008 */ 	lw	$a0,0x8($s1)
/*  f15e8ac:	10000098 */ 	beqz	$zero,.L0f15eb10
/*  f15e8b0:	02001025 */ 	or	$v0,$s0,$zero
.L0f15e8b4:
/*  f15e8b4:	3c0e800a */ 	lui	$t6,%hi(g_RoomPtrs)
/*  f15e8b8:	8dce4928 */ 	lw	$t6,%lo(g_RoomPtrs)($t6)
/*  f15e8bc:	00721823 */ 	subu	$v1,$v1,$s2
/*  f15e8c0:	00031880 */ 	sll	$v1,$v1,0x2
/*  f15e8c4:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f15e8c8:	95f80000 */ 	lhu	$t8,0x0($t7)
/*  f15e8cc:	02402025 */ 	or	$a0,$s2,$zero
/*  f15e8d0:	33190002 */ 	andi	$t9,$t8,0x2
/*  f15e8d4:	53200006 */ 	beqzl	$t9,.L0f15e8f0
/*  f15e8d8:	3c08bc00 */ 	lui	$t0,0xbc00
/*  f15e8dc:	8e25000c */ 	lw	$a1,0xc($s1)
/*  f15e8e0:	0fc4ef12 */ 	jal	func0f13bc48
/*  f15e8e4:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f15e8e8:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f15e8ec:	3c08bc00 */ 	lui	$t0,0xbc00
.L0f15e8f0:
/*  f15e8f0:	35083806 */ 	ori	$t0,$t0,0x3806
/*  f15e8f4:	02001025 */ 	or	$v0,$s0,$zero
/*  f15e8f8:	ac480000 */ 	sw	$t0,0x0($v0)
/*  f15e8fc:	8e29000c */ 	lw	$t1,0xc($s1)
/*  f15e900:	3c018000 */ 	lui	$at,0x8000
/*  f15e904:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15e908:	01215021 */ 	addu	$t2,$t1,$at
/*  f15e90c:	ac4a0004 */ 	sw	$t2,0x4($v0)
/*  f15e910:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f15e914:	0fc01181 */ 	jal	func0f004604
/*  f15e918:	02402025 */ 	or	$a0,$s2,$zero
/*  f15e91c:	3c0b800a */ 	lui	$t3,%hi(g_RoomPtrs)
/*  f15e920:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f15e924:	8d6b4928 */ 	lw	$t3,%lo(g_RoomPtrs)($t3)
/*  f15e928:	3c068000 */ 	lui	$a2,0x8000
/*  f15e92c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f15e930:	01632821 */ 	addu	$a1,$t3,$v1
/*  f15e934:	8ca20058 */ 	lw	$v0,0x58($a1)
/*  f15e938:	3c0bbc00 */ 	lui	$t3,0xbc00
/*  f15e93c:	356b3406 */ 	ori	$t3,$t3,0x3406
/*  f15e940:	50400012 */ 	beqzl	$v0,.L0f15e98c
/*  f15e944:	8e220010 */ 	lw	$v0,0x10($s1)
/*  f15e948:	8ca30014 */ 	lw	$v1,0x14($a1)
/*  f15e94c:	8e390010 */ 	lw	$t9,0x10($s1)
/*  f15e950:	846c0014 */ 	lh	$t4,0x14($v1)
/*  f15e954:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f15e958:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f15e95c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f15e960:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f15e964:	01ae2021 */ 	addu	$a0,$t5,$t6
/*  f15e968:	24840007 */ 	addiu	$a0,$a0,0x7
/*  f15e96c:	348f0007 */ 	ori	$t7,$a0,0x7
/*  f15e970:	39f80007 */ 	xori	$t8,$t7,0x7
/*  f15e974:	03384023 */ 	subu	$t0,$t9,$t8
/*  f15e978:	00084883 */ 	sra	$t1,$t0,0x2
/*  f15e97c:	00095080 */ 	sll	$t2,$t1,0x2
/*  f15e980:	10000002 */ 	beqz	$zero,.L0f15e98c
/*  f15e984:	004a1021 */ 	addu	$v0,$v0,$t2
/*  f15e988:	8e220010 */ 	lw	$v0,0x10($s1)
.L0f15e98c:
/*  f15e98c:	02001825 */ 	or	$v1,$s0,$zero
/*  f15e990:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15e994:	00466021 */ 	addu	$t4,$v0,$a2
/*  f15e998:	ac6c0004 */ 	sw	$t4,0x4($v1)
/*  f15e99c:	ac6b0000 */ 	sw	$t3,0x0($v1)
/*  f15e9a0:	02002025 */ 	or	$a0,$s0,$zero
/*  f15e9a4:	3c0d0600 */ 	lui	$t5,0x600
/*  f15e9a8:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f15e9ac:	8e2e0008 */ 	lw	$t6,0x8($s1)
/*  f15e9b0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15e9b4:	02402825 */ 	or	$a1,$s2,$zero
/*  f15e9b8:	01c67821 */ 	addu	$t7,$t6,$a2
/*  f15e9bc:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f15e9c0:	8fb8007c */ 	lw	$t8,0x7c($sp)
/*  f15e9c4:	02002025 */ 	or	$a0,$s0,$zero
/*  f15e9c8:	53000051 */ 	beqzl	$t8,.L0f15eb10
/*  f15e9cc:	02001025 */ 	or	$v0,$s0,$zero
/*  f15e9d0:	0fc57a17 */ 	jal	func0f15e85c
/*  f15e9d4:	8e260004 */ 	lw	$a2,0x4($s1)
/*  f15e9d8:	1000004c */ 	beqz	$zero,.L0f15eb0c
/*  f15e9dc:	00408025 */ 	or	$s0,$v0,$zero
/*  f15e9e0:	8e240008 */ 	lw	$a0,0x8($s1)
.L0f15e9e4:
/*  f15e9e4:	5080004a */ 	beqzl	$a0,.L0f15eb10
/*  f15e9e8:	02001025 */ 	or	$v0,$s0,$zero
/*  f15e9ec:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f15e9f0:	8c880004 */ 	lw	$t0,0x4($a0)
/*  f15e9f4:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f15e9f8:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f15e9fc:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f15ea00:	8e22000c */ 	lw	$v0,0xc($s1)
/*  f15ea04:	0080c825 */ 	or	$t9,$a0,$zero
/*  f15ea08:	00003825 */ 	or	$a3,$zero,$zero
/*  f15ea0c:	c444000c */ 	lwc1	$f4,0xc($v0)
/*  f15ea10:	02002025 */ 	or	$a0,$s0,$zero
/*  f15ea14:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f15ea18:	e7a40040 */ 	swc1	$f4,0x40($sp)
/*  f15ea1c:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f15ea20:	02402825 */ 	or	$a1,$s2,$zero
/*  f15ea24:	e7a60044 */ 	swc1	$f6,0x44($sp)
/*  f15ea28:	c4480014 */ 	lwc1	$f8,0x14($v0)
/*  f15ea2c:	e7a80048 */ 	swc1	$f8,0x48($sp)
/*  f15ea30:	c4701bb0 */ 	lwc1	$f16,0x1bb0($v1)
/*  f15ea34:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f15ea38:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f15ea3c:	e7b20034 */ 	swc1	$f18,0x34($sp)
/*  f15ea40:	c4661bb4 */ 	lwc1	$f6,0x1bb4($v1)
/*  f15ea44:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f15ea48:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f15ea4c:	c7a60034 */ 	lwc1	$f6,0x34($sp)
/*  f15ea50:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*  f15ea54:	e7a80038 */ 	swc1	$f8,0x38($sp)
/*  f15ea58:	c4701bb8 */ 	lwc1	$f16,0x1bb8($v1)
/*  f15ea5c:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f15ea60:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f15ea64:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f15ea68:	c7b00038 */ 	lwc1	$f16,0x38($sp)
/*  f15ea6c:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f15ea70:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f15ea74:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f15ea78:	c7aa0048 */ 	lwc1	$f10,0x48($sp)
/*  f15ea7c:	c7a6003c */ 	lwc1	$f6,0x3c($sp)
/*  f15ea80:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f15ea84:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f15ea88:	44804000 */ 	mtc1	$zero,$f8
/*  f15ea8c:	46048000 */ 	add.s	$f0,$f16,$f4
/*  f15ea90:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15ea94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ea98:	4500000c */ 	bc1f	.L0f15eacc
/*  f15ea9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15eaa0:	02002025 */ 	or	$a0,$s0,$zero
/*  f15eaa4:	02402825 */ 	or	$a1,$s2,$zero
/*  f15eaa8:	0fc57a17 */ 	jal	func0f15e85c
/*  f15eaac:	03203025 */ 	or	$a2,$t9,$zero
/*  f15eab0:	00402025 */ 	or	$a0,$v0,$zero
/*  f15eab4:	02402825 */ 	or	$a1,$s2,$zero
/*  f15eab8:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f15eabc:	0fc57a17 */ 	jal	func0f15e85c
/*  f15eac0:	00003825 */ 	or	$a3,$zero,$zero
/*  f15eac4:	10000009 */ 	beqz	$zero,.L0f15eaec
/*  f15eac8:	00408025 */ 	or	$s0,$v0,$zero
.L0f15eacc:
/*  f15eacc:	0fc57a17 */ 	jal	func0f15e85c
/*  f15ead0:	00003825 */ 	or	$a3,$zero,$zero
/*  f15ead4:	00402025 */ 	or	$a0,$v0,$zero
/*  f15ead8:	02402825 */ 	or	$a1,$s2,$zero
/*  f15eadc:	8fa60058 */ 	lw	$a2,0x58($sp)
/*  f15eae0:	0fc57a17 */ 	jal	func0f15e85c
/*  f15eae4:	00003825 */ 	or	$a3,$zero,$zero
/*  f15eae8:	00408025 */ 	or	$s0,$v0,$zero
.L0f15eaec:
/*  f15eaec:	8fa9007c */ 	lw	$t1,0x7c($sp)
/*  f15eaf0:	02002025 */ 	or	$a0,$s0,$zero
/*  f15eaf4:	02402825 */ 	or	$a1,$s2,$zero
/*  f15eaf8:	11200004 */ 	beqz	$t1,.L0f15eb0c
/*  f15eafc:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f15eb00:	0fc57a17 */ 	jal	func0f15e85c
/*  f15eb04:	8e260004 */ 	lw	$a2,0x4($s1)
/*  f15eb08:	00408025 */ 	or	$s0,$v0,$zero
.L0f15eb0c:
/*  f15eb0c:	02001025 */ 	or	$v0,$s0,$zero
.L0f15eb10:
/*  f15eb10:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f15eb14:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f15eb18:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f15eb1c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f15eb20:	03e00008 */ 	jr	$ra
/*  f15eb24:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

GLOBAL_ASM(
glabel func0f15eb28
/*  f15eb28:	000510c0 */ 	sll	$v0,$a1,0x3
/*  f15eb2c:	00451021 */ 	addu	$v0,$v0,$a1
/*  f15eb30:	3c0e800a */ 	lui	$t6,%hi(g_RoomPtrs)
/*  f15eb34:	8dce4928 */ 	lw	$t6,%lo(g_RoomPtrs)($t6)
/*  f15eb38:	00021080 */ 	sll	$v0,$v0,0x2
/*  f15eb3c:	00451023 */ 	subu	$v0,$v0,$a1
/*  f15eb40:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f15eb44:	00021080 */ 	sll	$v0,$v0,0x2
/*  f15eb48:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f15eb4c:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f15eb50:	85f80002 */ 	lh	$t8,0x2($t7)
/*  f15eb54:	57000004 */ 	bnezl	$t8,.L0f15eb68
/*  f15eb58:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f15eb5c:	10000019 */ 	beqz	$zero,.L0f15ebc4
/*  f15eb60:	00801025 */ 	or	$v0,$a0,$zero
/*  f15eb64:	afa2001c */ 	sw	$v0,0x1c($sp)
.L0f15eb68:
/*  f15eb68:	0fc59b5f */ 	jal	func0f166d7c
/*  f15eb6c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f15eb70:	00402025 */ 	or	$a0,$v0,$zero
/*  f15eb74:	0fc0044e */ 	jal	func0f001138
/*  f15eb78:	87a50026 */ 	lh	$a1,0x26($sp)
/*  f15eb7c:	3c19800a */ 	lui	$t9,%hi(g_RoomPtrs)
/*  f15eb80:	8f394928 */ 	lw	$t9,%lo(g_RoomPtrs)($t9)
/*  f15eb84:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*  f15eb88:	00402025 */ 	or	$a0,$v0,$zero
/*  f15eb8c:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f15eb90:	03284821 */ 	addu	$t1,$t9,$t0
/*  f15eb94:	8d2a0014 */ 	lw	$t2,0x14($t1)
/*  f15eb98:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f15eb9c:	0fc57a17 */ 	jal	func0f15e85c
/*  f15eba0:	8d460008 */ 	lw	$a2,0x8($t2)
/*  f15eba4:	0fc004c0 */ 	jal	func0f001300
/*  f15eba8:	00402025 */ 	or	$a0,$v0,$zero
/*  f15ebac:	3c0c800a */ 	lui	$t4,%hi(g_RoomPtrs)
/*  f15ebb0:	8d8c4928 */ 	lw	$t4,%lo(g_RoomPtrs)($t4)
/*  f15ebb4:	8fad001c */ 	lw	$t5,0x1c($sp)
/*  f15ebb8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f15ebbc:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f15ebc0:	a5cb0002 */ 	sh	$t3,0x2($t6)
.L0f15ebc4:
/*  f15ebc4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f15ebc8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f15ebcc:	03e00008 */ 	jr	$ra
/*  f15ebd0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15ebd4
/*  f15ebd4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f15ebd8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f15ebdc:	10a00008 */ 	beqz	$a1,.L0f15ec00
/*  f15ebe0:	00803025 */ 	or	$a2,$a0,$zero
/*  f15ebe4:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x2bc)
/*  f15ebe8:	8dcea27c */ 	lw	$t6,%lo(g_Vars+0x2bc)($t6)
/*  f15ebec:	000518c0 */ 	sll	$v1,$a1,0x3
/*  f15ebf0:	00651821 */ 	addu	$v1,$v1,$a1
/*  f15ebf4:	00ae082a */ 	slt	$at,$a1,$t6
/*  f15ebf8:	14200003 */ 	bnez	$at,.L0f15ec08
/*  f15ebfc:	00031880 */ 	sll	$v1,$v1,0x2
.L0f15ec00:
/*  f15ec00:	10000031 */ 	beqz	$zero,.L0f15ecc8
/*  f15ec04:	00c01025 */ 	or	$v0,$a2,$zero
.L0f15ec08:
/*  f15ec08:	3c0f800a */ 	lui	$t7,%hi(g_RoomPtrs)
/*  f15ec0c:	8def4928 */ 	lw	$t7,%lo(g_RoomPtrs)($t7)
/*  f15ec10:	00651823 */ 	subu	$v1,$v1,$a1
/*  f15ec14:	00031880 */ 	sll	$v1,$v1,0x2
/*  f15ec18:	01e31021 */ 	addu	$v0,$t7,$v1
/*  f15ec1c:	84580002 */ 	lh	$t8,0x2($v0)
/*  f15ec20:	00a02025 */ 	or	$a0,$a1,$zero
/*  f15ec24:	13000024 */ 	beqz	$t8,.L0f15ecb8
/*  f15ec28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ec2c:	8c590014 */ 	lw	$t9,0x14($v0)
/*  f15ec30:	00a02025 */ 	or	$a0,$a1,$zero
/*  f15ec34:	8f28000c */ 	lw	$t0,0xc($t9)
/*  f15ec38:	55000004 */ 	bnezl	$t0,.L0f15ec4c
/*  f15ec3c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f15ec40:	10000021 */ 	beqz	$zero,.L0f15ecc8
/*  f15ec44:	00c01025 */ 	or	$v0,$a2,$zero
/*  f15ec48:	afa30018 */ 	sw	$v1,0x18($sp)
.L0f15ec4c:
/*  f15ec4c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f15ec50:	0fc01181 */ 	jal	func0f004604
/*  f15ec54:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f15ec58:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f15ec5c:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f15ec60:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f15ec64:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f15ec68:	0fc59b5f */ 	jal	func0f166d7c
/*  f15ec6c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f15ec70:	3c0b800a */ 	lui	$t3,%hi(g_RoomPtrs)
/*  f15ec74:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f15ec78:	8d6b4928 */ 	lw	$t3,%lo(g_RoomPtrs)($t3)
/*  f15ec7c:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f15ec80:	00402025 */ 	or	$a0,$v0,$zero
/*  f15ec84:	01636021 */ 	addu	$t4,$t3,$v1
/*  f15ec88:	8d8d0014 */ 	lw	$t5,0x14($t4)
/*  f15ec8c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f15ec90:	0fc57a17 */ 	jal	func0f15e85c
/*  f15ec94:	8da6000c */ 	lw	$a2,0xc($t5)
/*  f15ec98:	3c0f800a */ 	lui	$t7,%hi(g_RoomPtrs)
/*  f15ec9c:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f15eca0:	8def4928 */ 	lw	$t7,%lo(g_RoomPtrs)($t7)
/*  f15eca4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f15eca8:	00403025 */ 	or	$a2,$v0,$zero
/*  f15ecac:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f15ecb0:	10000004 */ 	beqz	$zero,.L0f15ecc4
/*  f15ecb4:	a70e0002 */ 	sh	$t6,0x2($t8)
.L0f15ecb8:
/*  f15ecb8:	0fc57716 */ 	jal	func0f15dc58
/*  f15ecbc:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f15ecc0:	8fa60020 */ 	lw	$a2,0x20($sp)
.L0f15ecc4:
/*  f15ecc4:	00c01025 */ 	or	$v0,$a2,$zero
.L0f15ecc8:
/*  f15ecc8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f15eccc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f15ecd0:	03e00008 */ 	jr	$ra
/*  f15ecd4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15ecd8
.late_rodata
glabel var7f1b75d4
.word 0x46fffe00
.text
/*  f15ecd8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f15ecdc:	afb5001c */ 	sw	$s5,0x1c($sp)
/*  f15ece0:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f15ece4:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f15ece8:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f15ecec:	afb1000c */ 	sw	$s1,0xc($sp)
/*  f15ecf0:	afb00008 */ 	sw	$s0,0x8($sp)
/*  f15ecf4:	80ce0000 */ 	lb	$t6,0x0($a2)
/*  f15ecf8:	2412ffb8 */ 	addiu	$s2,$zero,-72
/*  f15ecfc:	00808025 */ 	or	$s0,$a0,$zero
/*  f15ed00:	124e009d */ 	beq	$s2,$t6,.L0f15ef78
/*  f15ed04:	00001025 */ 	or	$v0,$zero,$zero
/*  f15ed08:	3c013f80 */ 	lui	$at,0x3f80
/*  f15ed0c:	44819000 */ 	mtc1	$at,$f18
/*  f15ed10:	3c01c700 */ 	lui	$at,0xc700
/*  f15ed14:	44818000 */ 	mtc1	$at,$f16
/*  f15ed18:	3c017f1b */ 	lui	$at,%hi(var7f1b75d4)
/*  f15ed1c:	3c15800a */ 	lui	$s5,%hi(var800a4cc4)
/*  f15ed20:	3c1400ff */ 	lui	$s4,0xff
/*  f15ed24:	3694ffff */ 	ori	$s4,$s4,0xffff
/*  f15ed28:	26b54cc4 */ 	addiu	$s5,$s5,%lo(var800a4cc4)
/*  f15ed2c:	c42e75d4 */ 	lwc1	$f14,%lo(var7f1b75d4)($at)
/*  f15ed30:	00c01825 */ 	or	$v1,$a2,$zero
/*  f15ed34:	80c40000 */ 	lb	$a0,0x0($a2)
/*  f15ed38:	24130004 */ 	addiu	$s3,$zero,0x4
/*  f15ed3c:	8fac0030 */ 	lw	$t4,0x30($sp)
/*  f15ed40:	8fa80034 */ 	lw	$t0,0x34($sp)
.L0f15ed44:
/*  f15ed44:	16640087 */ 	bne	$s3,$a0,.L0f15ef64
/*  f15ed48:	00077940 */ 	sll	$t7,$a3,0x5
/*  f15ed4c:	00af2021 */ 	addu	$a0,$a1,$t7
/*  f15ed50:	00108880 */ 	sll	$s1,$s0,0x2
/*  f15ed54:	02308821 */ 	addu	$s1,$s1,$s0
/*  f15ed58:	0007c140 */ 	sll	$t8,$a3,0x5
/*  f15ed5c:	ac860004 */ 	sw	$a2,0x4($a0)
/*  f15ed60:	a4820000 */ 	sh	$v0,0x0($a0)
/*  f15ed64:	a4880002 */ 	sh	$t0,0x2($a0)
/*  f15ed68:	00b85021 */ 	addu	$t2,$a1,$t8
/*  f15ed6c:	00118880 */ 	sll	$s1,$s1,0x2
/*  f15ed70:	00004825 */ 	or	$t1,$zero,$zero
.L0f15ed74:
/*  f15ed74:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f15ed78:	29210003 */ 	slti	$at,$t1,0x3
/*  f15ed7c:	254a0004 */ 	addiu	$t2,$t2,0x4
/*  f15ed80:	e54e0004 */ 	swc1	$f14,0x4($t2)
/*  f15ed84:	1420fffb */ 	bnez	$at,.L0f15ed74
/*  f15ed88:	e5500010 */ 	swc1	$f16,0x10($t2)
/*  f15ed8c:	906a0001 */ 	lbu	$t2,0x1($v1)
/*  f15ed90:	8c6f0004 */ 	lw	$t7,0x4($v1)
/*  f15ed94:	00004825 */ 	or	$t1,$zero,$zero
/*  f15ed98:	000ac902 */ 	srl	$t9,$t2,0x4
/*  f15ed9c:	332e000f */ 	andi	$t6,$t9,0xf
/*  f15eda0:	25ca0001 */ 	addiu	$t2,$t6,0x1
/*  f15eda4:	01f4c024 */ 	and	$t8,$t7,$s4
/*  f15eda8:	19400031 */ 	blez	$t2,.L0f15ee70
/*  f15edac:	030c5821 */ 	addu	$t3,$t8,$t4
/*  f15edb0:	01606825 */ 	or	$t5,$t3,$zero
.L0f15edb4:
/*  f15edb4:	85b90000 */ 	lh	$t9,0x0($t5)
/*  f15edb8:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f15edbc:	85ae0002 */ 	lh	$t6,0x2($t5)
/*  f15edc0:	44992000 */ 	mtc1	$t9,$f4
/*  f15edc4:	85af0004 */ 	lh	$t7,0x4($t5)
/*  f15edc8:	448e3000 */ 	mtc1	$t6,$f6
/*  f15edcc:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f15edd0:	448f4000 */ 	mtc1	$t7,$f8
/*  f15edd4:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f15edd8:	468030a0 */ 	cvt.s.w	$f2,$f6
/*  f15eddc:	460a003c */ 	c.lt.s	$f0,$f10
/*  f15ede0:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f15ede4:	45020003 */ 	bc1fl	.L0f15edf4
/*  f15ede8:	c484000c */ 	lwc1	$f4,0xc($a0)
/*  f15edec:	e4800008 */ 	swc1	$f0,0x8($a0)
/*  f15edf0:	c484000c */ 	lwc1	$f4,0xc($a0)
.L0f15edf4:
/*  f15edf4:	4604103c */ 	c.lt.s	$f2,$f4
/*  f15edf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15edfc:	45020003 */ 	bc1fl	.L0f15ee0c
/*  f15ee00:	c4860010 */ 	lwc1	$f6,0x10($a0)
/*  f15ee04:	e482000c */ 	swc1	$f2,0xc($a0)
/*  f15ee08:	c4860010 */ 	lwc1	$f6,0x10($a0)
.L0f15ee0c:
/*  f15ee0c:	4606603c */ 	c.lt.s	$f12,$f6
/*  f15ee10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ee14:	45020003 */ 	bc1fl	.L0f15ee24
/*  f15ee18:	c4880014 */ 	lwc1	$f8,0x14($a0)
/*  f15ee1c:	e48c0010 */ 	swc1	$f12,0x10($a0)
/*  f15ee20:	c4880014 */ 	lwc1	$f8,0x14($a0)
.L0f15ee24:
/*  f15ee24:	4600403c */ 	c.lt.s	$f8,$f0
/*  f15ee28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ee2c:	45020003 */ 	bc1fl	.L0f15ee3c
/*  f15ee30:	c48a0018 */ 	lwc1	$f10,0x18($a0)
/*  f15ee34:	e4800014 */ 	swc1	$f0,0x14($a0)
/*  f15ee38:	c48a0018 */ 	lwc1	$f10,0x18($a0)
.L0f15ee3c:
/*  f15ee3c:	4602503c */ 	c.lt.s	$f10,$f2
/*  f15ee40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ee44:	45020003 */ 	bc1fl	.L0f15ee54
/*  f15ee48:	c484001c */ 	lwc1	$f4,0x1c($a0)
/*  f15ee4c:	e4820018 */ 	swc1	$f2,0x18($a0)
/*  f15ee50:	c484001c */ 	lwc1	$f4,0x1c($a0)
.L0f15ee54:
/*  f15ee54:	460c203c */ 	c.lt.s	$f4,$f12
/*  f15ee58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ee5c:	45000002 */ 	bc1f	.L0f15ee68
/*  f15ee60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ee64:	e48c001c */ 	swc1	$f12,0x1c($a0)
.L0f15ee68:
/*  f15ee68:	152affd2 */ 	bne	$t1,$t2,.L0f15edb4
/*  f15ee6c:	25ad000c */ 	addiu	$t5,$t5,0xc
.L0f15ee70:
/*  f15ee70:	c4800014 */ 	lwc1	$f0,0x14($a0)
/*  f15ee74:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f15ee78:	46003032 */ 	c.eq.s	$f6,$f0
/*  f15ee7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ee80:	45020004 */ 	bc1fl	.L0f15ee94
/*  f15ee84:	c4800018 */ 	lwc1	$f0,0x18($a0)
/*  f15ee88:	46120200 */ 	add.s	$f8,$f0,$f18
/*  f15ee8c:	e4880014 */ 	swc1	$f8,0x14($a0)
/*  f15ee90:	c4800018 */ 	lwc1	$f0,0x18($a0)
.L0f15ee94:
/*  f15ee94:	c48a000c */ 	lwc1	$f10,0xc($a0)
/*  f15ee98:	46005032 */ 	c.eq.s	$f10,$f0
/*  f15ee9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15eea0:	45020004 */ 	bc1fl	.L0f15eeb4
/*  f15eea4:	c4800010 */ 	lwc1	$f0,0x10($a0)
/*  f15eea8:	46120100 */ 	add.s	$f4,$f0,$f18
/*  f15eeac:	e4840018 */ 	swc1	$f4,0x18($a0)
/*  f15eeb0:	c4800010 */ 	lwc1	$f0,0x10($a0)
.L0f15eeb4:
/*  f15eeb4:	c482001c */ 	lwc1	$f2,0x1c($a0)
/*  f15eeb8:	46020032 */ 	c.eq.s	$f0,$f2
/*  f15eebc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15eec0:	45020005 */ 	bc1fl	.L0f15eed8
/*  f15eec4:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15eec8:	46121180 */ 	add.s	$f6,$f2,$f18
/*  f15eecc:	c4800010 */ 	lwc1	$f0,0x10($a0)
/*  f15eed0:	e486001c */ 	swc1	$f6,0x1c($a0)
/*  f15eed4:	8eb80000 */ 	lw	$t8,0x0($s5)
.L0f15eed8:
/*  f15eed8:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f15eedc:	c486000c */ 	lwc1	$f6,0xc($a0)
/*  f15eee0:	0311c821 */ 	addu	$t9,$t8,$s1
/*  f15eee4:	c72a0004 */ 	lwc1	$f10,0x4($t9)
/*  f15eee8:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f15eeec:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f15eef0:	e4840008 */ 	swc1	$f4,0x8($a0)
/*  f15eef4:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15eef8:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f15eefc:	c5e80008 */ 	lwc1	$f8,0x8($t7)
/*  f15ef00:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f15ef04:	c4880014 */ 	lwc1	$f8,0x14($a0)
/*  f15ef08:	e48a000c */ 	swc1	$f10,0xc($a0)
/*  f15ef0c:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15ef10:	0311c821 */ 	addu	$t9,$t8,$s1
/*  f15ef14:	c724000c */ 	lwc1	$f4,0xc($t9)
/*  f15ef18:	46040180 */ 	add.s	$f6,$f0,$f4
/*  f15ef1c:	e4860010 */ 	swc1	$f6,0x10($a0)
/*  f15ef20:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15ef24:	c4860018 */ 	lwc1	$f6,0x18($a0)
/*  f15ef28:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f15ef2c:	c5ea0004 */ 	lwc1	$f10,0x4($t7)
/*  f15ef30:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f15ef34:	e4840014 */ 	swc1	$f4,0x14($a0)
/*  f15ef38:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f15ef3c:	c484001c */ 	lwc1	$f4,0x1c($a0)
/*  f15ef40:	0311c821 */ 	addu	$t9,$t8,$s1
/*  f15ef44:	c7280008 */ 	lwc1	$f8,0x8($t9)
/*  f15ef48:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f15ef4c:	e48a0018 */ 	swc1	$f10,0x18($a0)
/*  f15ef50:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f15ef54:	01d17821 */ 	addu	$t7,$t6,$s1
/*  f15ef58:	c5e6000c */ 	lwc1	$f6,0xc($t7)
/*  f15ef5c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f15ef60:	e488001c */ 	swc1	$f8,0x1c($a0)
.L0f15ef64:
/*  f15ef64:	80640008 */ 	lb	$a0,0x8($v1)
/*  f15ef68:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f15ef6c:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f15ef70:	1644ff74 */ 	bne	$s2,$a0,.L0f15ed44
/*  f15ef74:	00000000 */ 	sll	$zero,$zero,0x0
.L0f15ef78:
/*  f15ef78:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f15ef7c:	8fb1000c */ 	lw	$s1,0xc($sp)
/*  f15ef80:	8fb20010 */ 	lw	$s2,0x10($sp)
/*  f15ef84:	8fb30014 */ 	lw	$s3,0x14($sp)
/*  f15ef88:	8fb40018 */ 	lw	$s4,0x18($sp)
/*  f15ef8c:	8fb5001c */ 	lw	$s5,0x1c($sp)
/*  f15ef90:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f15ef94:	03e00008 */ 	jr	$ra
/*  f15ef98:	00e01025 */ 	or	$v0,$a3,$zero
);

GLOBAL_ASM(
glabel func0f15ef9c
/*  f15ef9c:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f15efa0:	000410c0 */ 	sll	$v0,$a0,0x3
/*  f15efa4:	00441021 */ 	addu	$v0,$v0,$a0
/*  f15efa8:	3c0e800a */ 	lui	$t6,%hi(g_RoomPtrs)
/*  f15efac:	8dce4928 */ 	lw	$t6,%lo(g_RoomPtrs)($t6)
/*  f15efb0:	00021080 */ 	sll	$v0,$v0,0x2
/*  f15efb4:	00441023 */ 	subu	$v0,$v0,$a0
/*  f15efb8:	00021080 */ 	sll	$v0,$v0,0x2
/*  f15efbc:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f15efc0:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f15efc4:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f15efc8:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f15efcc:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f15efd0:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f15efd4:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f15efd8:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f15efdc:	8df80044 */ 	lw	$t8,0x44($t7)
/*  f15efe0:	0080a825 */ 	or	$s5,$a0,$zero
/*  f15efe4:	00009825 */ 	or	$s3,$zero,$zero
/*  f15efe8:	1700007f */ 	bnez	$t8,.L0f15f1e8
/*  f15efec:	00002825 */ 	or	$a1,$zero,$zero
/*  f15eff0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f15eff4:	0fc576ad */ 	jal	func0f15dab4
/*  f15eff8:	afa20038 */ 	sw	$v0,0x38($sp)
/*  f15effc:	1040007a */ 	beqz	$v0,.L0f15f1e8
/*  f15f000:	0040a025 */ 	or	$s4,$v0,$zero
/*  f15f004:	10400015 */ 	beqz	$v0,.L0f15f05c
/*  f15f008:	24110004 */ 	addiu	$s1,$zero,0x4
/*  f15f00c:	2410ffb8 */ 	addiu	$s0,$zero,-72
.L0f15f010:
/*  f15f010:	80590000 */ 	lb	$t9,0x0($v0)
/*  f15f014:	02801825 */ 	or	$v1,$s4,$zero
/*  f15f018:	02802825 */ 	or	$a1,$s4,$zero
/*  f15f01c:	1219000b */ 	beq	$s0,$t9,.L0f15f04c
/*  f15f020:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f15f024:	00402025 */ 	or	$a0,$v0,$zero
/*  f15f028:	80880000 */ 	lb	$t0,0x0($a0)
.L0f15f02c:
/*  f15f02c:	56280003 */ 	bnel	$s1,$t0,.L0f15f03c
/*  f15f030:	80690008 */ 	lb	$t1,0x8($v1)
/*  f15f034:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f15f038:	80690008 */ 	lb	$t1,0x8($v1)
.L0f15f03c:
/*  f15f03c:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f15f040:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f15f044:	5609fff9 */ 	bnel	$s0,$t1,.L0f15f02c
/*  f15f048:	80880000 */ 	lb	$t0,0x0($a0)
.L0f15f04c:
/*  f15f04c:	0fc576ad */ 	jal	func0f15dab4
/*  f15f050:	02a02025 */ 	or	$a0,$s5,$zero
/*  f15f054:	1440ffee */ 	bnez	$v0,.L0f15f010
/*  f15f058:	0040a025 */ 	or	$s4,$v0,$zero
.L0f15f05c:
/*  f15f05c:	2410ffb8 */ 	addiu	$s0,$zero,-72
/*  f15f060:	24110004 */ 	addiu	$s1,$zero,0x4
/*  f15f064:	00009025 */ 	or	$s2,$zero,$zero
/*  f15f068:	02a02025 */ 	or	$a0,$s5,$zero
/*  f15f06c:	00002825 */ 	or	$a1,$zero,$zero
/*  f15f070:	0fc576ad */ 	jal	func0f15dab4
/*  f15f074:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f15f078:	10400014 */ 	beqz	$v0,.L0f15f0cc
/*  f15f07c:	0040a025 */ 	or	$s4,$v0,$zero
.L0f15f080:
/*  f15f080:	804a0000 */ 	lb	$t2,0x0($v0)
/*  f15f084:	02801825 */ 	or	$v1,$s4,$zero
/*  f15f088:	02802825 */ 	or	$a1,$s4,$zero
/*  f15f08c:	120a000b */ 	beq	$s0,$t2,.L0f15f0bc
/*  f15f090:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f15f094:	00402025 */ 	or	$a0,$v0,$zero
/*  f15f098:	808b0000 */ 	lb	$t3,0x0($a0)
.L0f15f09c:
/*  f15f09c:	562b0003 */ 	bnel	$s1,$t3,.L0f15f0ac
/*  f15f0a0:	806c0008 */ 	lb	$t4,0x8($v1)
/*  f15f0a4:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f15f0a8:	806c0008 */ 	lb	$t4,0x8($v1)
.L0f15f0ac:
/*  f15f0ac:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f15f0b0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f15f0b4:	560cfff9 */ 	bnel	$s0,$t4,.L0f15f09c
/*  f15f0b8:	808b0000 */ 	lb	$t3,0x0($a0)
.L0f15f0bc:
/*  f15f0bc:	0fc576ad */ 	jal	func0f15dab4
/*  f15f0c0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f15f0c4:	1440ffee */ 	bnez	$v0,.L0f15f080
/*  f15f0c8:	0040a025 */ 	or	$s4,$v0,$zero
.L0f15f0cc:
/*  f15f0cc:	02729821 */ 	addu	$s3,$s3,$s2
/*  f15f0d0:	00132140 */ 	sll	$a0,$s3,0x5
/*  f15f0d4:	2484000f */ 	addiu	$a0,$a0,0xf
/*  f15f0d8:	2401fff0 */ 	addiu	$at,$zero,-16
/*  f15f0dc:	00816824 */ 	and	$t5,$a0,$at
/*  f15f0e0:	0c004aac */ 	jal	func00012ab0
/*  f15f0e4:	01a02025 */ 	or	$a0,$t5,$zero
/*  f15f0e8:	1040003f */ 	beqz	$v0,.L0f15f1e8
/*  f15f0ec:	00408025 */ 	or	$s0,$v0,$zero
/*  f15f0f0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f15f0f4:	00002825 */ 	or	$a1,$zero,$zero
/*  f15f0f8:	0fc576ad */ 	jal	func0f15dab4
/*  f15f0fc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f15f100:	3c0e800a */ 	lui	$t6,%hi(g_RoomPtrs)
/*  f15f104:	8dce4928 */ 	lw	$t6,%lo(g_RoomPtrs)($t6)
/*  f15f108:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f15f10c:	0040a025 */ 	or	$s4,$v0,$zero
/*  f15f110:	00009825 */ 	or	$s3,$zero,$zero
/*  f15f114:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f15f118:	10400013 */ 	beqz	$v0,.L0f15f168
/*  f15f11c:	af100044 */ 	sw	$s0,0x44($t8)
.L0f15f120:
/*  f15f120:	02a02025 */ 	or	$a0,$s5,$zero
/*  f15f124:	0fc576ed */ 	jal	func0f15dbb4
/*  f15f128:	02802825 */ 	or	$a1,$s4,$zero
/*  f15f12c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f15f130:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f15f134:	02a02025 */ 	or	$a0,$s5,$zero
/*  f15f138:	02002825 */ 	or	$a1,$s0,$zero
/*  f15f13c:	02803025 */ 	or	$a2,$s4,$zero
/*  f15f140:	02603825 */ 	or	$a3,$s3,$zero
/*  f15f144:	0fc57b36 */ 	jal	func0f15ecd8
/*  f15f148:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f15f14c:	00409825 */ 	or	$s3,$v0,$zero
/*  f15f150:	02a02025 */ 	or	$a0,$s5,$zero
/*  f15f154:	02802825 */ 	or	$a1,$s4,$zero
/*  f15f158:	0fc576ad */ 	jal	func0f15dab4
/*  f15f15c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f15f160:	1440ffef */ 	bnez	$v0,.L0f15f120
/*  f15f164:	0040a025 */ 	or	$s4,$v0,$zero
.L0f15f168:
/*  f15f168:	12400018 */ 	beqz	$s2,.L0f15f1cc
/*  f15f16c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f15f170:	00002825 */ 	or	$a1,$zero,$zero
/*  f15f174:	0fc576ad */ 	jal	func0f15dab4
/*  f15f178:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f15f17c:	10400013 */ 	beqz	$v0,.L0f15f1cc
/*  f15f180:	0040a025 */ 	or	$s4,$v0,$zero
.L0f15f184:
/*  f15f184:	02a02025 */ 	or	$a0,$s5,$zero
/*  f15f188:	0fc576ed */ 	jal	func0f15dbb4
/*  f15f18c:	02802825 */ 	or	$a1,$s4,$zero
/*  f15f190:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f15f194:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f15f198:	02a02025 */ 	or	$a0,$s5,$zero
/*  f15f19c:	02002825 */ 	or	$a1,$s0,$zero
/*  f15f1a0:	02803025 */ 	or	$a2,$s4,$zero
/*  f15f1a4:	02603825 */ 	or	$a3,$s3,$zero
/*  f15f1a8:	0fc57b36 */ 	jal	func0f15ecd8
/*  f15f1ac:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f15f1b0:	00409825 */ 	or	$s3,$v0,$zero
/*  f15f1b4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f15f1b8:	02802825 */ 	or	$a1,$s4,$zero
/*  f15f1bc:	0fc576ad */ 	jal	func0f15dab4
/*  f15f1c0:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f15f1c4:	1440ffef */ 	bnez	$v0,.L0f15f184
/*  f15f1c8:	0040a025 */ 	or	$s4,$v0,$zero
.L0f15f1cc:
/*  f15f1cc:	3c0b800a */ 	lui	$t3,%hi(g_RoomPtrs)
/*  f15f1d0:	8d6b4928 */ 	lw	$t3,%lo(g_RoomPtrs)($t3)
/*  f15f1d4:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f15f1d8:	00134c00 */ 	sll	$t1,$s3,0x10
/*  f15f1dc:	00095403 */ 	sra	$t2,$t1,0x10
/*  f15f1e0:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f15f1e4:	adaa0040 */ 	sw	$t2,0x40($t5)
.L0f15f1e8:
/*  f15f1e8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f15f1ec:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f15f1f0:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f15f1f4:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f15f1f8:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f15f1fc:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f15f200:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f15f204:	03e00008 */ 	jr	$ra
/*  f15f208:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

GLOBAL_ASM(
glabel func0f15f20c
/*  f15f20c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f15f210:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f15f214:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f15f218:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f15f21c:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f15f220:	448f2000 */ 	mtc1	$t7,$f4
/*  f15f224:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f228:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f15f22c:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f15f230:	8cd80004 */ 	lw	$t8,0x4($a2)
/*  f15f234:	44984000 */ 	mtc1	$t8,$f8
/*  f15f238:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f23c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f15f240:	e7aa0028 */ 	swc1	$f10,0x28($sp)
/*  f15f244:	8cd90008 */ 	lw	$t9,0x8($a2)
/*  f15f248:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f15f24c:	44998000 */ 	mtc1	$t9,$f16
/*  f15f250:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f254:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f15f258:	e7b2002c */ 	swc1	$f18,0x2c($sp)
/*  f15f25c:	8ce90000 */ 	lw	$t1,0x0($a3)
/*  f15f260:	44892000 */ 	mtc1	$t1,$f4
/*  f15f264:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f268:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f15f26c:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*  f15f270:	8cea0004 */ 	lw	$t2,0x4($a3)
/*  f15f274:	448a4000 */ 	mtc1	$t2,$f8
/*  f15f278:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f27c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f15f280:	e7aa001c */ 	swc1	$f10,0x1c($sp)
/*  f15f284:	8ceb0008 */ 	lw	$t3,0x8($a3)
/*  f15f288:	27a70018 */ 	addiu	$a3,$sp,0x18
/*  f15f28c:	448b8000 */ 	mtc1	$t3,$f16
/*  f15f290:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f294:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f15f298:	0fc57cac */ 	jal	func0f15f2b0
/*  f15f29c:	e7b20020 */ 	swc1	$f18,0x20($sp)
/*  f15f2a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f15f2a4:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f15f2a8:	03e00008 */ 	jr	$ra
/*  f15f2ac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f15f2b0
/*  f15f2b0:	c4b20000 */ 	lwc1	$f18,0x0($a1)
/*  f15f2b4:	44806000 */ 	mtc1	$zero,$f12
/*  f15f2b8:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f15f2bc:	c4e80000 */ 	lwc1	$f8,0x0($a3)
/*  f15f2c0:	460c903c */ 	c.lt.s	$f18,$f12
/*  f15f2c4:	c4cc0000 */ 	lwc1	$f12,0x0($a2)
/*  f15f2c8:	460a4401 */ 	sub.s	$f16,$f8,$f10
/*  f15f2cc:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f15f2d0:	45000004 */ 	bc1f	.L0f15f2e4
/*  f15f2d4:	460a6381 */ 	sub.s	$f14,$f12,$f10
/*  f15f2d8:	46009487 */ 	neg.s	$f18,$f18
/*  f15f2dc:	46007387 */ 	neg.s	$f14,$f14
/*  f15f2e0:	46008407 */ 	neg.s	$f16,$f16
.L0f15f2e4:
/*  f15f2e4:	44805000 */ 	mtc1	$zero,$f10
/*  f15f2e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f2ec:	460a703c */ 	c.lt.s	$f14,$f10
/*  f15f2f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f2f4:	4502000a */ 	bc1fl	.L0f15f320
/*  f15f2f8:	460e803c */ 	c.lt.s	$f16,$f14
/*  f15f2fc:	44802000 */ 	mtc1	$zero,$f4
/*  f15f300:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f304:	4604803c */ 	c.lt.s	$f16,$f4
/*  f15f308:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f30c:	45020004 */ 	bc1fl	.L0f15f320
/*  f15f310:	460e803c */ 	c.lt.s	$f16,$f14
/*  f15f314:	10000090 */ 	beqz	$zero,.L0f15f558
/*  f15f318:	00001025 */ 	or	$v0,$zero,$zero
/*  f15f31c:	460e803c */ 	c.lt.s	$f16,$f14
.L0f15f320:
/*  f15f320:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f324:	45020005 */ 	bc1fl	.L0f15f33c
/*  f15f328:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f15f32c:	46007006 */ 	mov.s	$f0,$f14
/*  f15f330:	46008386 */ 	mov.s	$f14,$f16
/*  f15f334:	46000406 */ 	mov.s	$f16,$f0
/*  f15f338:	c4860004 */ 	lwc1	$f6,0x4($a0)
.L0f15f33c:
/*  f15f33c:	c4ac0004 */ 	lwc1	$f12,0x4($a1)
/*  f15f340:	e7a60004 */ 	swc1	$f6,0x4($sp)
/*  f15f344:	44803000 */ 	mtc1	$zero,$f6
/*  f15f348:	c7aa0004 */ 	lwc1	$f10,0x4($sp)
/*  f15f34c:	c4e80004 */ 	lwc1	$f8,0x4($a3)
/*  f15f350:	4606603c */ 	c.lt.s	$f12,$f6
/*  f15f354:	c4c40004 */ 	lwc1	$f4,0x4($a2)
/*  f15f358:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f15f35c:	44804000 */ 	mtc1	$zero,$f8
/*  f15f360:	45000004 */ 	bc1f	.L0f15f374
/*  f15f364:	460a2001 */ 	sub.s	$f0,$f4,$f10
/*  f15f368:	46006307 */ 	neg.s	$f12,$f12
/*  f15f36c:	46000007 */ 	neg.s	$f0,$f0
/*  f15f370:	46001087 */ 	neg.s	$f2,$f2
.L0f15f374:
/*  f15f374:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15f378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f37c:	4502000a */ 	bc1fl	.L0f15f3a8
/*  f15f380:	4600103c */ 	c.lt.s	$f2,$f0
/*  f15f384:	44802000 */ 	mtc1	$zero,$f4
/*  f15f388:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f38c:	4604103c */ 	c.lt.s	$f2,$f4
/*  f15f390:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f394:	45020004 */ 	bc1fl	.L0f15f3a8
/*  f15f398:	4600103c */ 	c.lt.s	$f2,$f0
/*  f15f39c:	1000006e */ 	beqz	$zero,.L0f15f558
/*  f15f3a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f15f3a4:	4600103c */ 	c.lt.s	$f2,$f0
.L0f15f3a8:
/*  f15f3a8:	460c7182 */ 	mul.s	$f6,$f14,$f12
/*  f15f3ac:	45000004 */ 	bc1f	.L0f15f3c0
/*  f15f3b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f3b4:	e7a00020 */ 	swc1	$f0,0x20($sp)
/*  f15f3b8:	46001006 */ 	mov.s	$f0,$f2
/*  f15f3bc:	c7a20020 */ 	lwc1	$f2,0x20($sp)
.L0f15f3c0:
/*  f15f3c0:	46120282 */ 	mul.s	$f10,$f0,$f18
/*  f15f3c4:	e7a60004 */ 	swc1	$f6,0x4($sp)
/*  f15f3c8:	c7a40004 */ 	lwc1	$f4,0x4($sp)
/*  f15f3cc:	e7aa0000 */ 	swc1	$f10,0x0($sp)
/*  f15f3d0:	c7a80000 */ 	lwc1	$f8,0x0($sp)
/*  f15f3d4:	4604403c */ 	c.lt.s	$f8,$f4
/*  f15f3d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f3dc:	4500000d */ 	bc1f	.L0f15f414
/*  f15f3e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f3e4:	46121002 */ 	mul.s	$f0,$f2,$f18
/*  f15f3e8:	4604003c */ 	c.lt.s	$f0,$f4
/*  f15f3ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f3f0:	45000003 */ 	bc1f	.L0f15f400
/*  f15f3f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f3f8:	10000057 */ 	beqz	$zero,.L0f15f558
/*  f15f3fc:	00001025 */ 	or	$v0,$zero,$zero
.L0f15f400:
/*  f15f400:	460c8282 */ 	mul.s	$f10,$f16,$f12
/*  f15f404:	e7ae0034 */ 	swc1	$f14,0x34($sp)
/*  f15f408:	e7b20030 */ 	swc1	$f18,0x30($sp)
/*  f15f40c:	1000000f */ 	beqz	$zero,.L0f15f44c
/*  f15f410:	e7aa0004 */ 	swc1	$f10,0x4($sp)
.L0f15f414:
/*  f15f414:	460c8382 */ 	mul.s	$f14,$f16,$f12
/*  f15f418:	c7a60000 */ 	lwc1	$f6,0x0($sp)
/*  f15f41c:	4606703c */ 	c.lt.s	$f14,$f6
/*  f15f420:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f424:	45000003 */ 	bc1f	.L0f15f434
/*  f15f428:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f42c:	1000004a */ 	beqz	$zero,.L0f15f558
/*  f15f430:	00001025 */ 	or	$v0,$zero,$zero
.L0f15f434:
/*  f15f434:	46121202 */ 	mul.s	$f8,$f2,$f18
/*  f15f438:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f15f43c:	e7ac0030 */ 	swc1	$f12,0x30($sp)
/*  f15f440:	e7ae0004 */ 	swc1	$f14,0x4($sp)
/*  f15f444:	e7a80000 */ 	swc1	$f8,0x0($sp)
/*  f15f448:	c7a00000 */ 	lwc1	$f0,0x0($sp)
.L0f15f44c:
/*  f15f44c:	c7a40004 */ 	lwc1	$f4,0x4($sp)
/*  f15f450:	44804000 */ 	mtc1	$zero,$f8
/*  f15f454:	4600203c */ 	c.lt.s	$f4,$f0
/*  f15f458:	44802000 */ 	mtc1	$zero,$f4
/*  f15f45c:	45020005 */ 	bc1fl	.L0f15f474
/*  f15f460:	46001006 */ 	mov.s	$f0,$f2
/*  f15f464:	46008006 */ 	mov.s	$f0,$f16
/*  f15f468:	10000003 */ 	beqz	$zero,.L0f15f478
/*  f15f46c:	46009386 */ 	mov.s	$f14,$f18
/*  f15f470:	46001006 */ 	mov.s	$f0,$f2
.L0f15f474:
/*  f15f474:	46006386 */ 	mov.s	$f14,$f12
.L0f15f478:
/*  f15f478:	c4a20008 */ 	lwc1	$f2,0x8($a1)
/*  f15f47c:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f15f480:	c4c60008 */ 	lwc1	$f6,0x8($a2)
/*  f15f484:	4608103c */ 	c.lt.s	$f2,$f8
/*  f15f488:	c4ea0008 */ 	lwc1	$f10,0x8($a3)
/*  f15f48c:	46103481 */ 	sub.s	$f18,$f6,$f16
/*  f15f490:	c7a60034 */ 	lwc1	$f6,0x34($sp)
/*  f15f494:	45000004 */ 	bc1f	.L0f15f4a8
/*  f15f498:	46105301 */ 	sub.s	$f12,$f10,$f16
/*  f15f49c:	46001087 */ 	neg.s	$f2,$f2
/*  f15f4a0:	46009487 */ 	neg.s	$f18,$f18
/*  f15f4a4:	46006307 */ 	neg.s	$f12,$f12
.L0f15f4a8:
/*  f15f4a8:	4604903c */ 	c.lt.s	$f18,$f4
/*  f15f4ac:	c7a80030 */ 	lwc1	$f8,0x30($sp)
/*  f15f4b0:	4502000a */ 	bc1fl	.L0f15f4dc
/*  f15f4b4:	4612603c */ 	c.lt.s	$f12,$f18
/*  f15f4b8:	44805000 */ 	mtc1	$zero,$f10
/*  f15f4bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f4c0:	460a603c */ 	c.lt.s	$f12,$f10
/*  f15f4c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f4c8:	45020004 */ 	bc1fl	.L0f15f4dc
/*  f15f4cc:	4612603c */ 	c.lt.s	$f12,$f18
/*  f15f4d0:	10000021 */ 	beqz	$zero,.L0f15f558
/*  f15f4d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f15f4d8:	4612603c */ 	c.lt.s	$f12,$f18
.L0f15f4dc:
/*  f15f4dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f4e0:	45000004 */ 	bc1f	.L0f15f4f4
/*  f15f4e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f4e8:	46009406 */ 	mov.s	$f16,$f18
/*  f15f4ec:	46006486 */ 	mov.s	$f18,$f12
/*  f15f4f0:	46008306 */ 	mov.s	$f12,$f16
.L0f15f4f4:
/*  f15f4f4:	46023402 */ 	mul.s	$f16,$f6,$f2
/*  f15f4f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f4fc:	46089102 */ 	mul.s	$f4,$f18,$f8
/*  f15f500:	c7a80030 */ 	lwc1	$f8,0x30($sp)
/*  f15f504:	4604803c */ 	c.lt.s	$f16,$f4
/*  f15f508:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f50c:	4500000a */ 	bc1f	.L0f15f538
/*  f15f510:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f514:	46020282 */ 	mul.s	$f10,$f0,$f2
/*  f15f518:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f51c:	460e9182 */ 	mul.s	$f6,$f18,$f14
/*  f15f520:	4606503c */ 	c.lt.s	$f10,$f6
/*  f15f524:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f528:	4500000a */ 	bc1f	.L0f15f554
/*  f15f52c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f530:	10000009 */ 	beqz	$zero,.L0f15f558
/*  f15f534:	00001025 */ 	or	$v0,$zero,$zero
.L0f15f538:
/*  f15f538:	46086102 */ 	mul.s	$f4,$f12,$f8
/*  f15f53c:	4610203c */ 	c.lt.s	$f4,$f16
/*  f15f540:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f544:	45020004 */ 	bc1fl	.L0f15f558
/*  f15f548:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f15f54c:	10000002 */ 	beqz	$zero,.L0f15f558
/*  f15f550:	00001025 */ 	or	$v0,$zero,$zero
.L0f15f554:
/*  f15f554:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f15f558:
/*  f15f558:	03e00008 */ 	jr	$ra
/*  f15f55c:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f15f560
.late_rodata
glabel var7f1b75d8
.word 0x7f7fffff
.text
/*  f15f560:	27bdff08 */ 	addiu	$sp,$sp,-248
/*  f15f564:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f15f568:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f15f56c:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f15f570:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f15f574:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f15f578:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f15f57c:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f15f580:	3c017f1b */ 	lui	$at,%hi(var7f1b75d8)
/*  f15f584:	3c09800a */ 	lui	$t1,%hi(var800a6470)
/*  f15f588:	00809825 */ 	or	$s3,$a0,$zero
/*  f15f58c:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f15f590:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f15f594:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f15f598:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f15f59c:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f15f5a0:	afa60100 */ 	sw	$a2,0x100($sp)
/*  f15f5a4:	afa70104 */ 	sw	$a3,0x104($sp)
/*  f15f5a8:	afa000dc */ 	sw	$zero,0xdc($sp)
/*  f15f5ac:	00006825 */ 	or	$t5,$zero,$zero
/*  f15f5b0:	c43475d8 */ 	lwc1	$f20,%lo(var7f1b75d8)($at)
/*  f15f5b4:	25296470 */ 	addiu	$t1,$t1,%lo(var800a6470)
/*  f15f5b8:	8fb00110 */ 	lw	$s0,0x110($sp)
/*  f15f5bc:	8fb200b4 */ 	lw	$s2,0xb4($sp)
/*  f15f5c0:	8fb500cc */ 	lw	$s5,0xcc($sp)
/*  f15f5c4:	8fb700f0 */ 	lw	$s7,0xf0($sp)
/*  f15f5c8:	87a800f4 */ 	lh	$t0,0xf4($sp)
/*  f15f5cc:	00e06025 */ 	or	$t4,$a3,$zero
/*  f15f5d0:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f15f5d4:	240a000c */ 	addiu	$t2,$zero,0xc
.L0f15f5d8:
/*  f15f5d8:	81820000 */ 	lb	$v0,0x0($t4)
/*  f15f5dc:	2401ffb8 */ 	addiu	$at,$zero,-72
/*  f15f5e0:	54410008 */ 	bnel	$v0,$at,.L0f15f604
/*  f15f5e4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f15f5e8:	8fae0108 */ 	lw	$t6,0x108($sp)
/*  f15f5ec:	00006825 */ 	or	$t5,$zero,$zero
/*  f15f5f0:	11c0026c */ 	beqz	$t6,.L0f15ffa4
/*  f15f5f4:	01c06025 */ 	or	$t4,$t6,$zero
/*  f15f5f8:	1000fff7 */ 	beqz	$zero,.L0f15f5d8
/*  f15f5fc:	afa00108 */ 	sw	$zero,0x108($sp)
/*  f15f600:	24010004 */ 	addiu	$at,$zero,0x4
.L0f15f604:
/*  f15f604:	544100c8 */ 	bnel	$v0,$at,.L0f15f928
/*  f15f608:	2401fffd */ 	addiu	$at,$zero,-3
/*  f15f60c:	91850001 */ 	lbu	$a1,0x1($t4)
/*  f15f610:	8d870004 */ 	lw	$a3,0x4($t4)
/*  f15f614:	3c0100ff */ 	lui	$at,0xff
/*  f15f618:	30a6000f */ 	andi	$a2,$a1,0xf
/*  f15f61c:	00ca0019 */ 	multu	$a2,$t2
/*  f15f620:	8fb9010c */ 	lw	$t9,0x10c($sp)
/*  f15f624:	3421ffff */ 	ori	$at,$at,0xffff
/*  f15f628:	00e17824 */ 	and	$t7,$a3,$at
/*  f15f62c:	01e03825 */ 	or	$a3,$t7,$zero
/*  f15f630:	00051902 */ 	srl	$v1,$a1,0x4
/*  f15f634:	032f7021 */ 	addu	$t6,$t9,$t7
/*  f15f638:	3078000f */ 	andi	$t8,$v1,0xf
/*  f15f63c:	03001825 */ 	or	$v1,$t8,$zero
/*  f15f640:	3c02800a */ 	lui	$v0,%hi(var800a647c)
/*  f15f644:	00007812 */ 	mflo	$t7
/*  f15f648:	01cf2023 */ 	subu	$a0,$t6,$t7
/*  f15f64c:	84980000 */ 	lh	$t8,0x0($a0)
/*  f15f650:	24630000 */ 	addiu	$v1,$v1,0x0
/*  f15f654:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f15f658:	44982000 */ 	mtc1	$t8,$f4
/*  f15f65c:	2442647c */ 	addiu	$v0,$v0,%lo(var800a647c)
/*  f15f660:	2495000c */ 	addiu	$s5,$a0,0xc
/*  f15f664:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f15f668:	e5260000 */ 	swc1	$f6,0x0($t1)
/*  f15f66c:	84990002 */ 	lh	$t9,0x2($a0)
/*  f15f670:	c5200000 */ 	lwc1	$f0,0x0($t1)
/*  f15f674:	44994000 */ 	mtc1	$t9,$f8
/*  f15f678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f67c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f15f680:	e52a0004 */ 	swc1	$f10,0x4($t1)
/*  f15f684:	848e0004 */ 	lh	$t6,0x4($a0)
/*  f15f688:	c5220004 */ 	lwc1	$f2,0x4($t1)
/*  f15f68c:	afaf00ec */ 	sw	$t7,0xec($sp)
/*  f15f690:	448e8000 */ 	mtc1	$t6,$f16
/*  f15f694:	e7a000a4 */ 	swc1	$f0,0xa4($sp)
/*  f15f698:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f15f69c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f15f6a0:	e7a200a8 */ 	swc1	$f2,0xa8($sp)
/*  f15f6a4:	e7a2009c */ 	swc1	$f2,0x9c($sp)
/*  f15f6a8:	e5320008 */ 	swc1	$f18,0x8($t1)
/*  f15f6ac:	c52c0008 */ 	lwc1	$f12,0x8($t1)
/*  f15f6b0:	e7ac00ac */ 	swc1	$f12,0xac($sp)
/*  f15f6b4:	1860003e */ 	blez	$v1,.L0f15f7b0
/*  f15f6b8:	e7ac00a0 */ 	swc1	$f12,0xa0($sp)
.L0f15f6bc:
/*  f15f6bc:	86b80000 */ 	lh	$t8,0x0($s5)
/*  f15f6c0:	26b5000c */ 	addiu	$s5,$s5,0xc
/*  f15f6c4:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f15f6c8:	44982000 */ 	mtc1	$t8,$f4
/*  f15f6cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f6d0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f15f6d4:	e4460000 */ 	swc1	$f6,0x0($v0)
/*  f15f6d8:	86b9fff6 */ 	lh	$t9,-0xa($s5)
/*  f15f6dc:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f15f6e0:	44994000 */ 	mtc1	$t9,$f8
/*  f15f6e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f6e8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f15f6ec:	e44a0004 */ 	swc1	$f10,0x4($v0)
/*  f15f6f0:	86aefff8 */ 	lh	$t6,-0x8($s5)
/*  f15f6f4:	448e8000 */ 	mtc1	$t6,$f16
/*  f15f6f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f6fc:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f15f700:	e4520008 */ 	swc1	$f18,0x8($v0)
/*  f15f704:	c7a400a4 */ 	lwc1	$f4,0xa4($sp)
/*  f15f708:	4604003c */ 	c.lt.s	$f0,$f4
/*  f15f70c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f710:	45020003 */ 	bc1fl	.L0f15f720
/*  f15f714:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f15f718:	e7a000a4 */ 	swc1	$f0,0xa4($sp)
/*  f15f71c:	c4400004 */ 	lwc1	$f0,0x4($v0)
.L0f15f720:
/*  f15f720:	c7a600a8 */ 	lwc1	$f6,0xa8($sp)
/*  f15f724:	4606003c */ 	c.lt.s	$f0,$f6
/*  f15f728:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f72c:	45020003 */ 	bc1fl	.L0f15f73c
/*  f15f730:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f15f734:	e7a000a8 */ 	swc1	$f0,0xa8($sp)
/*  f15f738:	c4400008 */ 	lwc1	$f0,0x8($v0)
.L0f15f73c:
/*  f15f73c:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f15f740:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15f744:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f748:	45020003 */ 	bc1fl	.L0f15f758
/*  f15f74c:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f15f750:	e7a000ac */ 	swc1	$f0,0xac($sp)
/*  f15f754:	c4400000 */ 	lwc1	$f0,0x0($v0)
.L0f15f758:
/*  f15f758:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
/*  f15f75c:	4600503c */ 	c.lt.s	$f10,$f0
/*  f15f760:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f764:	45020003 */ 	bc1fl	.L0f15f774
/*  f15f768:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f15f76c:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f15f770:	c4400004 */ 	lwc1	$f0,0x4($v0)
.L0f15f774:
/*  f15f774:	c7b0009c */ 	lwc1	$f16,0x9c($sp)
/*  f15f778:	4600803c */ 	c.lt.s	$f16,$f0
/*  f15f77c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f780:	45020003 */ 	bc1fl	.L0f15f790
/*  f15f784:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f15f788:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f15f78c:	c4400008 */ 	lwc1	$f0,0x8($v0)
.L0f15f790:
/*  f15f790:	c7b200a0 */ 	lwc1	$f18,0xa0($sp)
/*  f15f794:	4600903c */ 	c.lt.s	$f18,$f0
/*  f15f798:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f79c:	45000002 */ 	bc1f	.L0f15f7a8
/*  f15f7a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f7a4:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
.L0f15f7a8:
/*  f15f7a8:	1c60ffc4 */ 	bgtz	$v1,.L0f15f6bc
/*  f15f7ac:	2442000c */ 	addiu	$v0,$v0,0xc
.L0f15f7b0:
/*  f15f7b0:	c6600000 */ 	lwc1	$f0,0x0($s3)
/*  f15f7b4:	c7a400a4 */ 	lwc1	$f4,0xa4($sp)
/*  f15f7b8:	c7a80098 */ 	lwc1	$f8,0x98($sp)
/*  f15f7bc:	4604003c */ 	c.lt.s	$f0,$f4
/*  f15f7c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f7c4:	45020009 */ 	bc1fl	.L0f15f7ec
/*  f15f7c8:	4600403c */ 	c.lt.s	$f8,$f0
/*  f15f7cc:	c6c60000 */ 	lwc1	$f6,0x0($s6)
/*  f15f7d0:	4604303c */ 	c.lt.s	$f6,$f4
/*  f15f7d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f7d8:	4502000e */ 	bc1fl	.L0f15f814
/*  f15f7dc:	c6600004 */ 	lwc1	$f0,0x4($s3)
/*  f15f7e0:	1000000b */ 	beqz	$zero,.L0f15f810
/*  f15f7e4:	afa000ec */ 	sw	$zero,0xec($sp)
/*  f15f7e8:	4600403c */ 	c.lt.s	$f8,$f0
.L0f15f7ec:
/*  f15f7ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f7f0:	45020008 */ 	bc1fl	.L0f15f814
/*  f15f7f4:	c6600004 */ 	lwc1	$f0,0x4($s3)
/*  f15f7f8:	c6ca0000 */ 	lwc1	$f10,0x0($s6)
/*  f15f7fc:	460a403c */ 	c.lt.s	$f8,$f10
/*  f15f800:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f804:	45020003 */ 	bc1fl	.L0f15f814
/*  f15f808:	c6600004 */ 	lwc1	$f0,0x4($s3)
/*  f15f80c:	afa000ec */ 	sw	$zero,0xec($sp)
.L0f15f810:
/*  f15f810:	c6600004 */ 	lwc1	$f0,0x4($s3)
.L0f15f814:
/*  f15f814:	c7b000a8 */ 	lwc1	$f16,0xa8($sp)
/*  f15f818:	4610003c */ 	c.lt.s	$f0,$f16
/*  f15f81c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f820:	45020009 */ 	bc1fl	.L0f15f848
/*  f15f824:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f15f828:	c6d20004 */ 	lwc1	$f18,0x4($s6)
/*  f15f82c:	4610903c */ 	c.lt.s	$f18,$f16
/*  f15f830:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f834:	4502000f */ 	bc1fl	.L0f15f874
/*  f15f838:	c6600008 */ 	lwc1	$f0,0x8($s3)
/*  f15f83c:	1000000c */ 	beqz	$zero,.L0f15f870
/*  f15f840:	afa000ec */ 	sw	$zero,0xec($sp)
/*  f15f844:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
.L0f15f848:
/*  f15f848:	4600303c */ 	c.lt.s	$f6,$f0
/*  f15f84c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f850:	45020008 */ 	bc1fl	.L0f15f874
/*  f15f854:	c6600008 */ 	lwc1	$f0,0x8($s3)
/*  f15f858:	c6c40004 */ 	lwc1	$f4,0x4($s6)
/*  f15f85c:	4604303c */ 	c.lt.s	$f6,$f4
/*  f15f860:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f864:	45020003 */ 	bc1fl	.L0f15f874
/*  f15f868:	c6600008 */ 	lwc1	$f0,0x8($s3)
/*  f15f86c:	afa000ec */ 	sw	$zero,0xec($sp)
.L0f15f870:
/*  f15f870:	c6600008 */ 	lwc1	$f0,0x8($s3)
.L0f15f874:
/*  f15f874:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f15f878:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15f87c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f880:	45020009 */ 	bc1fl	.L0f15f8a8
/*  f15f884:	c7b200a0 */ 	lwc1	$f18,0xa0($sp)
/*  f15f888:	c6ca0008 */ 	lwc1	$f10,0x8($s6)
/*  f15f88c:	4608503c */ 	c.lt.s	$f10,$f8
/*  f15f890:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f894:	4502000f */ 	bc1fl	.L0f15f8d4
/*  f15f898:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f15f89c:	1000000c */ 	beqz	$zero,.L0f15f8d0
/*  f15f8a0:	afa000ec */ 	sw	$zero,0xec($sp)
/*  f15f8a4:	c7b200a0 */ 	lwc1	$f18,0xa0($sp)
.L0f15f8a8:
/*  f15f8a8:	4600903c */ 	c.lt.s	$f18,$f0
/*  f15f8ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f8b0:	45020008 */ 	bc1fl	.L0f15f8d4
/*  f15f8b4:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f15f8b8:	c6d00008 */ 	lwc1	$f16,0x8($s6)
/*  f15f8bc:	4610903c */ 	c.lt.s	$f18,$f16
/*  f15f8c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f8c4:	45020003 */ 	bc1fl	.L0f15f8d4
/*  f15f8c8:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f15f8cc:	afa000ec */ 	sw	$zero,0xec($sp)
.L0f15f8d0:
/*  f15f8d0:	8faf00ec */ 	lw	$t7,0xec($sp)
.L0f15f8d4:
/*  f15f8d4:	11e001b1 */ 	beqz	$t7,.L0f15ff9c
/*  f15f8d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f8dc:	02602025 */ 	or	$a0,$s3,$zero
/*  f15f8e0:	8fa50100 */ 	lw	$a1,0x100($sp)
/*  f15f8e4:	27a600a4 */ 	addiu	$a2,$sp,0xa4
/*  f15f8e8:	27a70098 */ 	addiu	$a3,$sp,0x98
/*  f15f8ec:	a7a800f4 */ 	sh	$t0,0xf4($sp)
/*  f15f8f0:	afac0104 */ 	sw	$t4,0x104($sp)
/*  f15f8f4:	0fc57cac */ 	jal	func0f15f2b0
/*  f15f8f8:	afad00c8 */ 	sw	$t5,0xc8($sp)
/*  f15f8fc:	8fac0104 */ 	lw	$t4,0x104($sp)
/*  f15f900:	3c09800a */ 	lui	$t1,%hi(var800a6470)
/*  f15f904:	25296470 */ 	addiu	$t1,$t1,%lo(var800a6470)
/*  f15f908:	87a800f4 */ 	lh	$t0,0xf4($sp)
/*  f15f90c:	240a000c */ 	addiu	$t2,$zero,0xc
/*  f15f910:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f15f914:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f15f918:	afa200ec */ 	sw	$v0,0xec($sp)
/*  f15f91c:	1000ff2e */ 	beqz	$zero,.L0f15f5d8
/*  f15f920:	258c0008 */ 	addiu	$t4,$t4,0x8
/*  f15f924:	2401fffd */ 	addiu	$at,$zero,-3
.L0f15f928:
/*  f15f928:	14410004 */ 	bne	$v0,$at,.L0f15f93c
/*  f15f92c:	8fb800ec */ 	lw	$t8,0xec($sp)
/*  f15f930:	01806825 */ 	or	$t5,$t4,$zero
/*  f15f934:	1000ff28 */ 	beqz	$zero,.L0f15f5d8
/*  f15f938:	258c0008 */ 	addiu	$t4,$t4,0x8
.L0f15f93c:
/*  f15f93c:	17000003 */ 	bnez	$t8,.L0f15f94c
/*  f15f940:	2401ffbf */ 	addiu	$at,$zero,-65
/*  f15f944:	1000ff24 */ 	beqz	$zero,.L0f15f5d8
/*  f15f948:	258c0008 */ 	addiu	$t4,$t4,0x8
.L0f15f94c:
/*  f15f94c:	10410005 */ 	beq	$v0,$at,.L0f15f964
/*  f15f950:	2401ffb1 */ 	addiu	$at,$zero,-79
/*  f15f954:	50410004 */ 	beql	$v0,$at,.L0f15f968
/*  f15f958:	2401ffbf */ 	addiu	$at,$zero,-65
/*  f15f95c:	1000ff1e */ 	beqz	$zero,.L0f15f5d8
/*  f15f960:	258c0008 */ 	addiu	$t4,$t4,0x8
.L0f15f964:
/*  f15f964:	2401ffbf */ 	addiu	$at,$zero,-65
.L0f15f968:
/*  f15f968:	5441002e */ 	bnel	$v0,$at,.L0f15fa24
/*  f15f96c:	2401ffb1 */ 	addiu	$at,$zero,-79
/*  f15f970:	2402000a */ 	addiu	$v0,$zero,0xa
/*  f15f974:	91990005 */ 	lbu	$t9,0x5($t4)
/*  f15f978:	0000b825 */ 	or	$s7,$zero,$zero
/*  f15f97c:	00004025 */ 	or	$t0,$zero,$zero
/*  f15f980:	0322001a */ 	div	$zero,$t9,$v0
/*  f15f984:	00007012 */ 	mflo	$t6
/*  f15f988:	afae0074 */ 	sw	$t6,0x74($sp)
/*  f15f98c:	918f0006 */ 	lbu	$t7,0x6($t4)
/*  f15f990:	14400002 */ 	bnez	$v0,.L0f15f99c
/*  f15f994:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f998:	0007000d */ 	break	0x7
.L0f15f99c:
/*  f15f99c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f15f9a0:	14410004 */ 	bne	$v0,$at,.L0f15f9b4
/*  f15f9a4:	3c018000 */ 	lui	$at,0x8000
/*  f15f9a8:	17210002 */ 	bne	$t9,$at,.L0f15f9b4
/*  f15f9ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f9b0:	0006000d */ 	break	0x6
.L0f15f9b4:
/*  f15f9b4:	01e2001a */ 	div	$zero,$t7,$v0
/*  f15f9b8:	0000c012 */ 	mflo	$t8
/*  f15f9bc:	afb80078 */ 	sw	$t8,0x78($sp)
/*  f15f9c0:	91990007 */ 	lbu	$t9,0x7($t4)
/*  f15f9c4:	14400002 */ 	bnez	$v0,.L0f15f9d0
/*  f15f9c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f9cc:	0007000d */ 	break	0x7
.L0f15f9d0:
/*  f15f9d0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f15f9d4:	14410004 */ 	bne	$v0,$at,.L0f15f9e8
/*  f15f9d8:	3c018000 */ 	lui	$at,0x8000
/*  f15f9dc:	15e10002 */ 	bne	$t7,$at,.L0f15f9e8
/*  f15f9e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f9e4:	0006000d */ 	break	0x6
.L0f15f9e8:
/*  f15f9e8:	0322001a */ 	div	$zero,$t9,$v0
/*  f15f9ec:	00007012 */ 	mflo	$t6
/*  f15f9f0:	afae007c */ 	sw	$t6,0x7c($sp)
/*  f15f9f4:	14400002 */ 	bnez	$v0,.L0f15fa00
/*  f15f9f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15f9fc:	0007000d */ 	break	0x7
.L0f15fa00:
/*  f15fa00:	2401ffff */ 	addiu	$at,$zero,-1
/*  f15fa04:	14410004 */ 	bne	$v0,$at,.L0f15fa18
/*  f15fa08:	3c018000 */ 	lui	$at,0x8000
/*  f15fa0c:	17210002 */ 	bne	$t9,$at,.L0f15fa18
/*  f15fa10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fa14:	0006000d */ 	break	0x6
.L0f15fa18:
/*  f15fa18:	10000011 */ 	beqz	$zero,.L0f15fa60
/*  f15fa1c:	8fb90074 */ 	lw	$t9,0x74($sp)
/*  f15fa20:	2401ffb1 */ 	addiu	$at,$zero,-79
.L0f15fa24:
/*  f15fa24:	5441000e */ 	bnel	$v0,$at,.L0f15fa60
/*  f15fa28:	8fb90074 */ 	lw	$t9,0x74($sp)
/*  f15fa2c:	8d8f0004 */ 	lw	$t7,0x4($t4)
/*  f15fa30:	01809025 */ 	or	$s2,$t4,$zero
/*  f15fa34:	0160b825 */ 	or	$s7,$t3,$zero
/*  f15fa38:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f15fa3c:	afb80074 */ 	sw	$t8,0x74($sp)
/*  f15fa40:	91990007 */ 	lbu	$t9,0x7($t4)
/*  f15fa44:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f15fa48:	00197102 */ 	srl	$t6,$t9,0x4
/*  f15fa4c:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f15fa50:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f15fa54:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f15fa58:	afb8007c */ 	sw	$t8,0x7c($sp)
/*  f15fa5c:	8fb90074 */ 	lw	$t9,0x74($sp)
.L0f15fa60:
/*  f15fa60:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f15fa64:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f15fa68:	17200005 */ 	bnez	$t9,.L0f15fa80
/*  f15fa6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fa70:	15c00003 */ 	bnez	$t6,.L0f15fa80
/*  f15fa74:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f15fa78:	11e00148 */ 	beqz	$t7,.L0f15ff9c
/*  f15fa7c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f15fa80:
/*  f15fa80:	030b0019 */ 	multu	$t8,$t3
/*  f15fa84:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f15fa88:	0000c812 */ 	mflo	$t9
/*  f15fa8c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f15fa90:	01c92021 */ 	addu	$a0,$t6,$t1
/*  f15fa94:	01eb0019 */ 	multu	$t7,$t3
/*  f15fa98:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f15fa9c:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f15faa0:	00808825 */ 	or	$s1,$a0,$zero
/*  f15faa4:	e7a600a4 */ 	swc1	$f6,0xa4($sp)
/*  f15faa8:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f15faac:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f15fab0:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f15fab4:	0000c012 */ 	mflo	$t8
/*  f15fab8:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f15fabc:	03291021 */ 	addu	$v0,$t9,$t1
/*  f15fac0:	01cb0019 */ 	multu	$t6,$t3
/*  f15fac4:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f15fac8:	0040a025 */ 	or	$s4,$v0,$zero
/*  f15facc:	4608503c */ 	c.lt.s	$f10,$f8
/*  f15fad0:	00007812 */ 	mflo	$t7
/*  f15fad4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f15fad8:	03091821 */ 	addu	$v1,$t8,$t1
/*  f15fadc:	45000003 */ 	bc1f	.L0f15faec
/*  f15fae0:	0060f025 */ 	or	$s8,$v1,$zero
/*  f15fae4:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f15fae8:	e7b200a4 */ 	swc1	$f18,0xa4($sp)
.L0f15faec:
/*  f15faec:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f15faf0:	c7b00098 */ 	lwc1	$f16,0x98($sp)
/*  f15faf4:	4600803c */ 	c.lt.s	$f16,$f0
/*  f15faf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fafc:	45020003 */ 	bc1fl	.L0f15fb0c
/*  f15fb00:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f15fb04:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f15fb08:	c4600000 */ 	lwc1	$f0,0x0($v1)
.L0f15fb0c:
/*  f15fb0c:	c7a600a4 */ 	lwc1	$f6,0xa4($sp)
/*  f15fb10:	4606003c */ 	c.lt.s	$f0,$f6
/*  f15fb14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fb18:	45020004 */ 	bc1fl	.L0f15fb2c
/*  f15fb1c:	c7a40098 */ 	lwc1	$f4,0x98($sp)
/*  f15fb20:	e7a000a4 */ 	swc1	$f0,0xa4($sp)
/*  f15fb24:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f15fb28:	c7a40098 */ 	lwc1	$f4,0x98($sp)
.L0f15fb2c:
/*  f15fb2c:	4600203c */ 	c.lt.s	$f4,$f0
/*  f15fb30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fb34:	45020003 */ 	bc1fl	.L0f15fb44
/*  f15fb38:	c6600000 */ 	lwc1	$f0,0x0($s3)
/*  f15fb3c:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f15fb40:	c6600000 */ 	lwc1	$f0,0x0($s3)
.L0f15fb44:
/*  f15fb44:	c7aa00a4 */ 	lwc1	$f10,0xa4($sp)
/*  f15fb48:	460a003c */ 	c.lt.s	$f0,$f10
/*  f15fb4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fb50:	45020007 */ 	bc1fl	.L0f15fb70
/*  f15fb54:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f15fb58:	c6c80000 */ 	lwc1	$f8,0x0($s6)
/*  f15fb5c:	460a403c */ 	c.lt.s	$f8,$f10
/*  f15fb60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fb64:	450300e1 */ 	bc1tl	.L0f15feec
/*  f15fb68:	26f7ffff */ 	addiu	$s7,$s7,-1
/*  f15fb6c:	c7b20098 */ 	lwc1	$f18,0x98($sp)
.L0f15fb70:
/*  f15fb70:	4600903c */ 	c.lt.s	$f18,$f0
/*  f15fb74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fb78:	45020007 */ 	bc1fl	.L0f15fb98
/*  f15fb7c:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f15fb80:	c6d00000 */ 	lwc1	$f16,0x0($s6)
/*  f15fb84:	4610903c */ 	c.lt.s	$f18,$f16
/*  f15fb88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fb8c:	450300d7 */ 	bc1tl	.L0f15feec
/*  f15fb90:	26f7ffff */ 	addiu	$s7,$s7,-1
/*  f15fb94:	c4860008 */ 	lwc1	$f6,0x8($a0)
.L0f15fb98:
/*  f15fb98:	e7a600ac */ 	swc1	$f6,0xac($sp)
/*  f15fb9c:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f15fba0:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f15fba4:	e7a400a0 */ 	swc1	$f4,0xa0($sp)
/*  f15fba8:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f15fbac:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15fbb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fbb4:	45020004 */ 	bc1fl	.L0f15fbc8
/*  f15fbb8:	c7aa00a0 */ 	lwc1	$f10,0xa0($sp)
/*  f15fbbc:	e7a000ac */ 	swc1	$f0,0xac($sp)
/*  f15fbc0:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f15fbc4:	c7aa00a0 */ 	lwc1	$f10,0xa0($sp)
.L0f15fbc8:
/*  f15fbc8:	4600503c */ 	c.lt.s	$f10,$f0
/*  f15fbcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fbd0:	45020003 */ 	bc1fl	.L0f15fbe0
/*  f15fbd4:	c4600008 */ 	lwc1	$f0,0x8($v1)
/*  f15fbd8:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
/*  f15fbdc:	c4600008 */ 	lwc1	$f0,0x8($v1)
.L0f15fbe0:
/*  f15fbe0:	c7b200ac */ 	lwc1	$f18,0xac($sp)
/*  f15fbe4:	4612003c */ 	c.lt.s	$f0,$f18
/*  f15fbe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fbec:	45020004 */ 	bc1fl	.L0f15fc00
/*  f15fbf0:	c7b000a0 */ 	lwc1	$f16,0xa0($sp)
/*  f15fbf4:	e7a000ac */ 	swc1	$f0,0xac($sp)
/*  f15fbf8:	c4600008 */ 	lwc1	$f0,0x8($v1)
/*  f15fbfc:	c7b000a0 */ 	lwc1	$f16,0xa0($sp)
.L0f15fc00:
/*  f15fc00:	4600803c */ 	c.lt.s	$f16,$f0
/*  f15fc04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fc08:	45020003 */ 	bc1fl	.L0f15fc18
/*  f15fc0c:	c6600008 */ 	lwc1	$f0,0x8($s3)
/*  f15fc10:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
/*  f15fc14:	c6600008 */ 	lwc1	$f0,0x8($s3)
.L0f15fc18:
/*  f15fc18:	c7a600ac */ 	lwc1	$f6,0xac($sp)
/*  f15fc1c:	4606003c */ 	c.lt.s	$f0,$f6
/*  f15fc20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fc24:	45020007 */ 	bc1fl	.L0f15fc44
/*  f15fc28:	c7a800a0 */ 	lwc1	$f8,0xa0($sp)
/*  f15fc2c:	c6c40008 */ 	lwc1	$f4,0x8($s6)
/*  f15fc30:	4606203c */ 	c.lt.s	$f4,$f6
/*  f15fc34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fc38:	450300ac */ 	bc1tl	.L0f15feec
/*  f15fc3c:	26f7ffff */ 	addiu	$s7,$s7,-1
/*  f15fc40:	c7a800a0 */ 	lwc1	$f8,0xa0($sp)
.L0f15fc44:
/*  f15fc44:	4600403c */ 	c.lt.s	$f8,$f0
/*  f15fc48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fc4c:	45020007 */ 	bc1fl	.L0f15fc6c
/*  f15fc50:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f15fc54:	c6ca0008 */ 	lwc1	$f10,0x8($s6)
/*  f15fc58:	460a403c */ 	c.lt.s	$f8,$f10
/*  f15fc5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fc60:	450300a2 */ 	bc1tl	.L0f15feec
/*  f15fc64:	26f7ffff */ 	addiu	$s7,$s7,-1
/*  f15fc68:	c4920004 */ 	lwc1	$f18,0x4($a0)
.L0f15fc6c:
/*  f15fc6c:	e7b200a8 */ 	swc1	$f18,0xa8($sp)
/*  f15fc70:	c4900004 */ 	lwc1	$f16,0x4($a0)
/*  f15fc74:	c7a400a8 */ 	lwc1	$f4,0xa8($sp)
/*  f15fc78:	e7b0009c */ 	swc1	$f16,0x9c($sp)
/*  f15fc7c:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f15fc80:	4604003c */ 	c.lt.s	$f0,$f4
/*  f15fc84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fc88:	45020004 */ 	bc1fl	.L0f15fc9c
/*  f15fc8c:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f15fc90:	e7a000a8 */ 	swc1	$f0,0xa8($sp)
/*  f15fc94:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f15fc98:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
.L0f15fc9c:
/*  f15fc9c:	4600303c */ 	c.lt.s	$f6,$f0
/*  f15fca0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fca4:	45020003 */ 	bc1fl	.L0f15fcb4
/*  f15fca8:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f15fcac:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f15fcb0:	c4600004 */ 	lwc1	$f0,0x4($v1)
.L0f15fcb4:
/*  f15fcb4:	c7a800a8 */ 	lwc1	$f8,0xa8($sp)
/*  f15fcb8:	4608003c */ 	c.lt.s	$f0,$f8
/*  f15fcbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fcc0:	45020004 */ 	bc1fl	.L0f15fcd4
/*  f15fcc4:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f15fcc8:	e7a000a8 */ 	swc1	$f0,0xa8($sp)
/*  f15fccc:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f15fcd0:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
.L0f15fcd4:
/*  f15fcd4:	4600503c */ 	c.lt.s	$f10,$f0
/*  f15fcd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fcdc:	45020003 */ 	bc1fl	.L0f15fcec
/*  f15fce0:	c6600004 */ 	lwc1	$f0,0x4($s3)
/*  f15fce4:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f15fce8:	c6600004 */ 	lwc1	$f0,0x4($s3)
.L0f15fcec:
/*  f15fcec:	c7b200a8 */ 	lwc1	$f18,0xa8($sp)
/*  f15fcf0:	4612003c */ 	c.lt.s	$f0,$f18
/*  f15fcf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fcf8:	45020007 */ 	bc1fl	.L0f15fd18
/*  f15fcfc:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f15fd00:	c6d00004 */ 	lwc1	$f16,0x4($s6)
/*  f15fd04:	4612803c */ 	c.lt.s	$f16,$f18
/*  f15fd08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fd0c:	45030077 */ 	bc1tl	.L0f15feec
/*  f15fd10:	26f7ffff */ 	addiu	$s7,$s7,-1
/*  f15fd14:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
.L0f15fd18:
/*  f15fd18:	4600203c */ 	c.lt.s	$f4,$f0
/*  f15fd1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fd20:	45020007 */ 	bc1fl	.L0f15fd40
/*  f15fd24:	02602025 */ 	or	$a0,$s3,$zero
/*  f15fd28:	c6c60004 */ 	lwc1	$f6,0x4($s6)
/*  f15fd2c:	4606203c */ 	c.lt.s	$f4,$f6
/*  f15fd30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fd34:	4503006d */ 	bc1tl	.L0f15feec
/*  f15fd38:	26f7ffff */ 	addiu	$s7,$s7,-1
/*  f15fd3c:	02602025 */ 	or	$a0,$s3,$zero
.L0f15fd40:
/*  f15fd40:	8fa50100 */ 	lw	$a1,0x100($sp)
/*  f15fd44:	27a600a4 */ 	addiu	$a2,$sp,0xa4
/*  f15fd48:	27a70098 */ 	addiu	$a3,$sp,0x98
/*  f15fd4c:	a7a800f4 */ 	sh	$t0,0xf4($sp)
/*  f15fd50:	afac0104 */ 	sw	$t4,0x104($sp)
/*  f15fd54:	0fc57cac */ 	jal	func0f15f2b0
/*  f15fd58:	afad00c8 */ 	sw	$t5,0xc8($sp)
/*  f15fd5c:	3c09800a */ 	lui	$t1,%hi(var800a6470)
/*  f15fd60:	25296470 */ 	addiu	$t1,$t1,%lo(var800a6470)
/*  f15fd64:	87a800f4 */ 	lh	$t0,0xf4($sp)
/*  f15fd68:	240a000c */ 	addiu	$t2,$zero,0xc
/*  f15fd6c:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f15fd70:	8fac0104 */ 	lw	$t4,0x104($sp)
/*  f15fd74:	1040005c */ 	beqz	$v0,.L0f15fee8
/*  f15fd78:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f15fd7c:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f15fd80:	27ae008c */ 	addiu	$t6,$sp,0x8c
/*  f15fd84:	27af0080 */ 	addiu	$t7,$sp,0x80
/*  f15fd88:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f15fd8c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f15fd90:	02202025 */ 	or	$a0,$s1,$zero
/*  f15fd94:	02802825 */ 	or	$a1,$s4,$zero
/*  f15fd98:	03c03025 */ 	or	$a2,$s8,$zero
/*  f15fd9c:	00003825 */ 	or	$a3,$zero,$zero
/*  f15fda0:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f15fda4:	afb60014 */ 	sw	$s6,0x14($sp)
/*  f15fda8:	a7a800f4 */ 	sh	$t0,0xf4($sp)
/*  f15fdac:	afac0104 */ 	sw	$t4,0x104($sp)
/*  f15fdb0:	afad00c8 */ 	sw	$t5,0xc8($sp)
/*  f15fdb4:	0c00bd58 */ 	jal	func0002f560
/*  f15fdb8:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f15fdbc:	3c09800a */ 	lui	$t1,%hi(var800a6470)
/*  f15fdc0:	25296470 */ 	addiu	$t1,$t1,%lo(var800a6470)
/*  f15fdc4:	87a800f4 */ 	lh	$t0,0xf4($sp)
/*  f15fdc8:	240a000c */ 	addiu	$t2,$zero,0xc
/*  f15fdcc:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f15fdd0:	8fac0104 */ 	lw	$t4,0x104($sp)
/*  f15fdd4:	10400044 */ 	beqz	$v0,.L0f15fee8
/*  f15fdd8:	8fad00c8 */ 	lw	$t5,0xc8($sp)
/*  f15fddc:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*  f15fde0:	c66a0000 */ 	lwc1	$f10,0x0($s3)
/*  f15fde4:	c7b00090 */ 	lwc1	$f16,0x90($sp)
/*  f15fde8:	c6720004 */ 	lwc1	$f18,0x4($s3)
/*  f15fdec:	460a4001 */ 	sub.s	$f0,$f8,$f10
/*  f15fdf0:	c6680008 */ 	lwc1	$f8,0x8($s3)
/*  f15fdf4:	c7a60094 */ 	lwc1	$f6,0x94($sp)
/*  f15fdf8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f15fdfc:	46000082 */ 	mul.s	$f2,$f0,$f0
/*  f15fe00:	46128001 */ 	sub.s	$f0,$f16,$f18
/*  f15fe04:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f15fe08:	46083001 */ 	sub.s	$f0,$f6,$f8
/*  f15fe0c:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f15fe10:	46041080 */ 	add.s	$f2,$f2,$f4
/*  f15fe14:	460a1080 */ 	add.s	$f2,$f2,$f10
/*  f15fe18:	4614103c */ 	c.lt.s	$f2,$f20
/*  f15fe1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fe20:	45020032 */ 	bc1fl	.L0f15feec
/*  f15fe24:	26f7ffff */ 	addiu	$s7,$s7,-1
/*  f15fe28:	11a0000a */ 	beqz	$t5,.L0f15fe54
/*  f15fe2c:	afb800dc */ 	sw	$t8,0xdc($sp)
/*  f15fe30:	8da20004 */ 	lw	$v0,0x4($t5)
/*  f15fe34:	3c030f00 */ 	lui	$v1,0xf00
/*  f15fe38:	0043c824 */ 	and	$t9,$v0,$v1
/*  f15fe3c:	10790005 */ 	beq	$v1,$t9,.L0f15fe54
/*  f15fe40:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15fe44:	3c030500 */ 	lui	$v1,0x500
/*  f15fe48:	00437024 */ 	and	$t6,$v0,$v1
/*  f15fe4c:	146e0003 */ 	bne	$v1,$t6,.L0f15fe5c
/*  f15fe50:	3c018000 */ 	lui	$at,0x8000
.L0f15fe54:
/*  f15fe54:	10000005 */ 	beqz	$zero,.L0f15fe6c
/*  f15fe58:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f15fe5c:
/*  f15fe5c:	2443fff8 */ 	addiu	$v1,$v0,-8
/*  f15fe60:	00617825 */ 	or	$t7,$v1,$at
/*  f15fe64:	01e01825 */ 	or	$v1,$t7,$zero
/*  f15fe68:	85e40000 */ 	lh	$a0,0x0($t7)
.L0f15fe6c:
/*  f15fe6c:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*  f15fe70:	46001506 */ 	mov.s	$f20,$f2
/*  f15fe74:	e6100000 */ 	swc1	$f16,0x0($s0)
/*  f15fe78:	c7b20090 */ 	lwc1	$f18,0x90($sp)
/*  f15fe7c:	e6120004 */ 	swc1	$f18,0x4($s0)
/*  f15fe80:	c7a40094 */ 	lwc1	$f4,0x94($sp)
/*  f15fe84:	e6040008 */ 	swc1	$f4,0x8($s0)
/*  f15fe88:	c7a60080 */ 	lwc1	$f6,0x80($sp)
/*  f15fe8c:	e606000c */ 	swc1	$f6,0xc($s0)
/*  f15fe90:	c7a80084 */ 	lwc1	$f8,0x84($sp)
/*  f15fe94:	e6080010 */ 	swc1	$f8,0x10($s0)
/*  f15fe98:	c7aa0088 */ 	lwc1	$f10,0x88($sp)
/*  f15fe9c:	e60a0014 */ 	swc1	$f10,0x14($s0)
/*  f15fea0:	8fb80074 */ 	lw	$t8,0x74($sp)
/*  f15fea4:	030a0019 */ 	multu	$t8,$t2
/*  f15fea8:	0000c812 */ 	mflo	$t9
/*  f15feac:	03357021 */ 	addu	$t6,$t9,$s5
/*  f15feb0:	ae0e0018 */ 	sw	$t6,0x18($s0)
/*  f15feb4:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f15feb8:	01ea0019 */ 	multu	$t7,$t2
/*  f15febc:	0000c012 */ 	mflo	$t8
/*  f15fec0:	0315c821 */ 	addu	$t9,$t8,$s5
/*  f15fec4:	ae19001c */ 	sw	$t9,0x1c($s0)
/*  f15fec8:	8fae007c */ 	lw	$t6,0x7c($sp)
/*  f15fecc:	a604002a */ 	sh	$a0,0x2a($s0)
/*  f15fed0:	ae0c0024 */ 	sw	$t4,0x24($s0)
/*  f15fed4:	01ca0019 */ 	multu	$t6,$t2
/*  f15fed8:	a6080028 */ 	sh	$t0,0x28($s0)
/*  f15fedc:	00007812 */ 	mflo	$t7
/*  f15fee0:	01f5c021 */ 	addu	$t8,$t7,$s5
/*  f15fee4:	ae180020 */ 	sw	$t8,0x20($s0)
.L0f15fee8:
/*  f15fee8:	26f7ffff */ 	addiu	$s7,$s7,-1
.L0f15feec:
/*  f15feec:	24010002 */ 	addiu	$at,$zero,0x2
/*  f15fef0:	56e1000d */ 	bnel	$s7,$at,.L0f15ff28
/*  f15fef4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f15fef8:	92590006 */ 	lbu	$t9,0x6($s2)
/*  f15fefc:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f15ff00:	332e000f */ 	andi	$t6,$t9,0xf
/*  f15ff04:	afae0074 */ 	sw	$t6,0x74($sp)
/*  f15ff08:	964f0006 */ 	lhu	$t7,0x6($s2)
/*  f15ff0c:	000fc302 */ 	srl	$t8,$t7,0xc
/*  f15ff10:	afb80078 */ 	sw	$t8,0x78($sp)
/*  f15ff14:	92590003 */ 	lbu	$t9,0x3($s2)
/*  f15ff18:	00197102 */ 	srl	$t6,$t9,0x4
/*  f15ff1c:	1000001d */ 	beqz	$zero,.L0f15ff94
/*  f15ff20:	afae007c */ 	sw	$t6,0x7c($sp)
/*  f15ff24:	24010001 */ 	addiu	$at,$zero,0x1
.L0f15ff28:
/*  f15ff28:	16e1000e */ 	bne	$s7,$at,.L0f15ff64
/*  f15ff2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ff30:	964f0004 */ 	lhu	$t7,0x4($s2)
/*  f15ff34:	000b4400 */ 	sll	$t0,$t3,0x10
/*  f15ff38:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f15ff3c:	afb80074 */ 	sw	$t8,0x74($sp)
/*  f15ff40:	92590005 */ 	lbu	$t9,0x5($s2)
/*  f15ff44:	00197102 */ 	srl	$t6,$t9,0x4
/*  f15ff48:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f15ff4c:	924f0002 */ 	lbu	$t7,0x2($s2)
/*  f15ff50:	0008cc03 */ 	sra	$t9,$t0,0x10
/*  f15ff54:	03204025 */ 	or	$t0,$t9,$zero
/*  f15ff58:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f15ff5c:	1000000d */ 	beqz	$zero,.L0f15ff94
/*  f15ff60:	afb8007c */ 	sw	$t8,0x7c($sp)
.L0f15ff64:
/*  f15ff64:	16e0000b */ 	bnez	$s7,.L0f15ff94
/*  f15ff68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f15ff6c:	924e0004 */ 	lbu	$t6,0x4($s2)
/*  f15ff70:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f15ff74:	31cf000f */ 	andi	$t7,$t6,0xf
/*  f15ff78:	afaf0074 */ 	sw	$t7,0x74($sp)
/*  f15ff7c:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f15ff80:	0018cf02 */ 	srl	$t9,$t8,0x1c
/*  f15ff84:	afb90078 */ 	sw	$t9,0x78($sp)
/*  f15ff88:	964e0002 */ 	lhu	$t6,0x2($s2)
/*  f15ff8c:	000e7b02 */ 	srl	$t7,$t6,0xc
/*  f15ff90:	afaf007c */ 	sw	$t7,0x7c($sp)
.L0f15ff94:
/*  f15ff94:	06e3feb2 */ 	bgezl	$s7,.L0f15fa60
/*  f15ff98:	8fb90074 */ 	lw	$t9,0x74($sp)
.L0f15ff9c:
/*  f15ff9c:	1000fd8e */ 	beqz	$zero,.L0f15f5d8
/*  f15ffa0:	258c0008 */ 	addiu	$t4,$t4,0x8
.L0f15ffa4:
/*  f15ffa4:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f15ffa8:	8fa200dc */ 	lw	$v0,0xdc($sp)
/*  f15ffac:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f15ffb0:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f15ffb4:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f15ffb8:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f15ffbc:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f15ffc0:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f15ffc4:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f15ffc8:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f15ffcc:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f15ffd0:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f15ffd4:	03e00008 */ 	jr	$ra
/*  f15ffd8:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
);

GLOBAL_ASM(
glabel func0f15ffdc
/*  f15ffdc:	27bdff10 */ 	addiu	$sp,$sp,-240
/*  f15ffe0:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f15ffe4:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f15ffe8:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f15ffec:	00c0b825 */ 	or	$s7,$a2,$zero
/*  f15fff0:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f15fff4:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f15fff8:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f15fffc:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f160000:	240e0010 */ 	addiu	$t6,$zero,0x10
/*  f160004:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f160008:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f16000c:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f160010:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f160014:	afa400f0 */ 	sw	$a0,0xf0($sp)
/*  f160018:	afa700fc */ 	sw	$a3,0xfc($sp)
/*  f16001c:	afae00dc */ 	sw	$t6,0xdc($sp)
/*  f160020:	afa000d8 */ 	sw	$zero,0xd8($sp)
/*  f160024:	afa000cc */ 	sw	$zero,0xcc($sp)
/*  f160028:	8fb20110 */ 	lw	$s2,0x110($sp)
/*  f16002c:	8fb300e8 */ 	lw	$s3,0xe8($sp)
/*  f160030:	8fb400ac */ 	lw	$s4,0xac($sp)
/*  f160034:	8fb600c0 */ 	lw	$s6,0xc0($sp)
/*  f160038:	2406ffb1 */ 	addiu	$a2,$zero,-79
/*  f16003c:	2405ffbf */ 	addiu	$a1,$zero,-65
/*  f160040:	87a800ee */ 	lh	$t0,0xee($sp)
/*  f160044:	2403000a */ 	addiu	$v1,$zero,0xa
.L0f160048:
/*  f160048:	8faf0100 */ 	lw	$t7,0x100($sp)
/*  f16004c:	2401ffb8 */ 	addiu	$at,$zero,-72
/*  f160050:	8fb80104 */ 	lw	$t8,0x104($sp)
/*  f160054:	81e20000 */ 	lb	$v0,0x0($t7)
/*  f160058:	54410007 */ 	bnel	$v0,$at,.L0f160078
/*  f16005c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f160060:	53000269 */ 	beqzl	$t8,.L0f160a08
/*  f160064:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f160068:	afb80100 */ 	sw	$t8,0x100($sp)
/*  f16006c:	1000fff6 */ 	beqz	$zero,.L0f160048
/*  f160070:	afa00104 */ 	sw	$zero,0x104($sp)
/*  f160074:	24010001 */ 	addiu	$at,$zero,0x1
.L0f160078:
/*  f160078:	1441000d */ 	bne	$v0,$at,.L0f1600b0
/*  f16007c:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f160080:	8f240004 */ 	lw	$a0,0x4($t9)
/*  f160084:	8faa00f0 */ 	lw	$t2,0xf0($sp)
/*  f160088:	3c0100ff */ 	lui	$at,0xff
/*  f16008c:	3421ffff */ 	ori	$at,$at,0xffff
/*  f160090:	8d4b000c */ 	lw	$t3,0xc($t2)
/*  f160094:	00814824 */ 	and	$t1,$a0,$at
/*  f160098:	00099982 */ 	srl	$s3,$t1,0x6
/*  f16009c:	00136180 */ 	sll	$t4,$s3,0x6
/*  f1600a0:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f1600a4:	01202025 */ 	or	$a0,$t1,$zero
/*  f1600a8:	10000252 */ 	beqz	$zero,.L0f1609f4
/*  f1600ac:	afad00a8 */ 	sw	$t5,0xa8($sp)
.L0f1600b0:
/*  f1600b0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1600b4:	144100c7 */ 	bne	$v0,$at,.L0f1603d4
/*  f1600b8:	8fb900e4 */ 	lw	$t9,0xe4($sp)
/*  f1600bc:	8fa50100 */ 	lw	$a1,0x100($sp)
/*  f1600c0:	8fb800dc */ 	lw	$t8,0xdc($sp)
/*  f1600c4:	3c0100ff */ 	lui	$at,0xff
/*  f1600c8:	90a20001 */ 	lbu	$v0,0x1($a1)
/*  f1600cc:	8ca40004 */ 	lw	$a0,0x4($a1)
/*  f1600d0:	3421ffff */ 	ori	$at,$at,0xffff
/*  f1600d4:	8faf0108 */ 	lw	$t7,0x108($sp)
/*  f1600d8:	3043000f */ 	andi	$v1,$v0,0xf
/*  f1600dc:	00817024 */ 	and	$t6,$a0,$at
/*  f1600e0:	0078082a */ 	slt	$at,$v1,$t8
/*  f1600e4:	00028902 */ 	srl	$s1,$v0,0x4
/*  f1600e8:	01c02025 */ 	or	$a0,$t6,$zero
/*  f1600ec:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1600f0:	10200002 */ 	beqz	$at,.L0f1600fc
/*  f1600f4:	01eeb021 */ 	addu	$s6,$t7,$t6
/*  f1600f8:	afa300dc */ 	sw	$v1,0xdc($sp)
.L0f1600fc:
/*  f1600fc:	8fb300dc */ 	lw	$s3,0xdc($sp)
/*  f160100:	8fac00d8 */ 	lw	$t4,0xd8($sp)
/*  f160104:	3c0a800a */ 	lui	$t2,%hi(var800a6470)
/*  f160108:	254a6470 */ 	addiu	$t2,$t2,%lo(var800a6470)
/*  f16010c:	00134880 */ 	sll	$t1,$s3,0x2
/*  f160110:	012af021 */ 	addu	$s8,$t1,$t2
/*  f160114:	02231021 */ 	addu	$v0,$s1,$v1
/*  f160118:	27cb000c */ 	addiu	$t3,$s8,0xc
/*  f16011c:	0182082a */ 	slt	$at,$t4,$v0
/*  f160120:	10200002 */ 	beqz	$at,.L0f16012c
/*  f160124:	afab0060 */ 	sw	$t3,0x60($sp)
/*  f160128:	afa200d8 */ 	sw	$v0,0xd8($sp)
.L0f16012c:
/*  f16012c:	00036880 */ 	sll	$t5,$v1,0x2
/*  f160130:	01a36823 */ 	subu	$t5,$t5,$v1
/*  f160134:	3c0f800a */ 	lui	$t7,%hi(var800a6470)
/*  f160138:	25ef6470 */ 	addiu	$t7,$t7,%lo(var800a6470)
/*  f16013c:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f160140:	1a200019 */ 	blez	$s1,.L0f1601a8
/*  f160144:	01cf8021 */ 	addu	$s0,$t6,$t7
.L0f160148:
/*  f160148:	86d80000 */ 	lh	$t8,0x0($s6)
/*  f16014c:	02002825 */ 	or	$a1,$s0,$zero
/*  f160150:	44982000 */ 	mtc1	$t8,$f4
/*  f160154:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160158:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16015c:	e6060000 */ 	swc1	$f6,0x0($s0)
/*  f160160:	86c90002 */ 	lh	$t1,0x2($s6)
/*  f160164:	44894000 */ 	mtc1	$t1,$f8
/*  f160168:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16016c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f160170:	e60a0004 */ 	swc1	$f10,0x4($s0)
/*  f160174:	86ca0004 */ 	lh	$t2,0x4($s6)
/*  f160178:	448a8000 */ 	mtc1	$t2,$f16
/*  f16017c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160180:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f160184:	e6120008 */ 	swc1	$f18,0x8($s0)
/*  f160188:	a7a800ee */ 	sh	$t0,0xee($sp)
/*  f16018c:	0c0056d9 */ 	jal	func00015b64
/*  f160190:	8fa400a8 */ 	lw	$a0,0xa8($sp)
/*  f160194:	2631ffff */ 	addiu	$s1,$s1,-1
/*  f160198:	87a800ee */ 	lh	$t0,0xee($sp)
/*  f16019c:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f1601a0:	1e20ffe9 */ 	bgtz	$s1,.L0f160148
/*  f1601a4:	26d6000c */ 	addiu	$s6,$s6,0xc
.L0f1601a8:
/*  f1601a8:	8fa200d8 */ 	lw	$v0,0xd8($sp)
/*  f1601ac:	8fab00dc */ 	lw	$t3,0xdc($sp)
/*  f1601b0:	c7c00000 */ 	lwc1	$f0,0x0($s8)
/*  f1601b4:	c7c20004 */ 	lwc1	$f2,0x4($s8)
/*  f1601b8:	c7cc0008 */ 	lwc1	$f12,0x8($s8)
/*  f1601bc:	0162082a */ 	slt	$at,$t3,$v0
/*  f1601c0:	8fb00060 */ 	lw	$s0,0x60($sp)
/*  f1601c4:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f1601c8:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f1601cc:	e7a200a0 */ 	swc1	$f2,0xa0($sp)
/*  f1601d0:	e7a20094 */ 	swc1	$f2,0x94($sp)
/*  f1601d4:	e7ac00a4 */ 	swc1	$f12,0xa4($sp)
/*  f1601d8:	1020002e */ 	beqz	$at,.L0f160294
/*  f1601dc:	e7ac0098 */ 	swc1	$f12,0x98($sp)
.L0f1601e0:
/*  f1601e0:	c6000000 */ 	lwc1	$f0,0x0($s0)
/*  f1601e4:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f1601e8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f1601ec:	4604003c */ 	c.lt.s	$f0,$f4
/*  f1601f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1601f4:	45020003 */ 	bc1fl	.L0f160204
/*  f1601f8:	c6000004 */ 	lwc1	$f0,0x4($s0)
/*  f1601fc:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f160200:	c6000004 */ 	lwc1	$f0,0x4($s0)
.L0f160204:
/*  f160204:	c7a600a0 */ 	lwc1	$f6,0xa0($sp)
/*  f160208:	4606003c */ 	c.lt.s	$f0,$f6
/*  f16020c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160210:	45020003 */ 	bc1fl	.L0f160220
/*  f160214:	c6000008 */ 	lwc1	$f0,0x8($s0)
/*  f160218:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
/*  f16021c:	c6000008 */ 	lwc1	$f0,0x8($s0)
.L0f160220:
/*  f160220:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f160224:	4608003c */ 	c.lt.s	$f0,$f8
/*  f160228:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16022c:	45020003 */ 	bc1fl	.L0f16023c
/*  f160230:	c6000000 */ 	lwc1	$f0,0x0($s0)
/*  f160234:	e7a000a4 */ 	swc1	$f0,0xa4($sp)
/*  f160238:	c6000000 */ 	lwc1	$f0,0x0($s0)
.L0f16023c:
/*  f16023c:	c7aa0090 */ 	lwc1	$f10,0x90($sp)
/*  f160240:	4600503c */ 	c.lt.s	$f10,$f0
/*  f160244:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160248:	45020003 */ 	bc1fl	.L0f160258
/*  f16024c:	c6000004 */ 	lwc1	$f0,0x4($s0)
/*  f160250:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f160254:	c6000004 */ 	lwc1	$f0,0x4($s0)
.L0f160258:
/*  f160258:	c7b00094 */ 	lwc1	$f16,0x94($sp)
/*  f16025c:	4600803c */ 	c.lt.s	$f16,$f0
/*  f160260:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160264:	45020003 */ 	bc1fl	.L0f160274
/*  f160268:	c6000008 */ 	lwc1	$f0,0x8($s0)
/*  f16026c:	e7a00094 */ 	swc1	$f0,0x94($sp)
/*  f160270:	c6000008 */ 	lwc1	$f0,0x8($s0)
.L0f160274:
/*  f160274:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f160278:	4600903c */ 	c.lt.s	$f18,$f0
/*  f16027c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160280:	45000002 */ 	bc1f	.L0f16028c
/*  f160284:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160288:	e7a00098 */ 	swc1	$f0,0x98($sp)
.L0f16028c:
/*  f16028c:	1662ffd4 */ 	bne	$s3,$v0,.L0f1601e0
/*  f160290:	2610000c */ 	addiu	$s0,$s0,0xc
.L0f160294:
/*  f160294:	c6a00000 */ 	lwc1	$f0,0x0($s5)
/*  f160298:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f16029c:	4604003c */ 	c.lt.s	$f0,$f4
/*  f1602a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1602a4:	45020007 */ 	bc1fl	.L0f1602c4
/*  f1602a8:	c7a80090 */ 	lwc1	$f8,0x90($sp)
/*  f1602ac:	c6e60000 */ 	lwc1	$f6,0x0($s7)
/*  f1602b0:	4604303c */ 	c.lt.s	$f6,$f4
/*  f1602b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1602b8:	45030038 */ 	bc1tl	.L0f16039c
/*  f1602bc:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f1602c0:	c7a80090 */ 	lwc1	$f8,0x90($sp)
.L0f1602c4:
/*  f1602c4:	4600403c */ 	c.lt.s	$f8,$f0
/*  f1602c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1602cc:	45020007 */ 	bc1fl	.L0f1602ec
/*  f1602d0:	c6a00004 */ 	lwc1	$f0,0x4($s5)
/*  f1602d4:	c6ea0000 */ 	lwc1	$f10,0x0($s7)
/*  f1602d8:	460a403c */ 	c.lt.s	$f8,$f10
/*  f1602dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1602e0:	4503002e */ 	bc1tl	.L0f16039c
/*  f1602e4:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f1602e8:	c6a00004 */ 	lwc1	$f0,0x4($s5)
.L0f1602ec:
/*  f1602ec:	c7b000a0 */ 	lwc1	$f16,0xa0($sp)
/*  f1602f0:	4610003c */ 	c.lt.s	$f0,$f16
/*  f1602f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1602f8:	45020007 */ 	bc1fl	.L0f160318
/*  f1602fc:	c7a60094 */ 	lwc1	$f6,0x94($sp)
/*  f160300:	c6f20004 */ 	lwc1	$f18,0x4($s7)
/*  f160304:	4610903c */ 	c.lt.s	$f18,$f16
/*  f160308:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16030c:	45030023 */ 	bc1tl	.L0f16039c
/*  f160310:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f160314:	c7a60094 */ 	lwc1	$f6,0x94($sp)
.L0f160318:
/*  f160318:	4600303c */ 	c.lt.s	$f6,$f0
/*  f16031c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160320:	45020007 */ 	bc1fl	.L0f160340
/*  f160324:	c6a00008 */ 	lwc1	$f0,0x8($s5)
/*  f160328:	c6e40004 */ 	lwc1	$f4,0x4($s7)
/*  f16032c:	4604303c */ 	c.lt.s	$f6,$f4
/*  f160330:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160334:	45030019 */ 	bc1tl	.L0f16039c
/*  f160338:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f16033c:	c6a00008 */ 	lwc1	$f0,0x8($s5)
.L0f160340:
/*  f160340:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f160344:	4608003c */ 	c.lt.s	$f0,$f8
/*  f160348:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16034c:	45020007 */ 	bc1fl	.L0f16036c
/*  f160350:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f160354:	c6ea0008 */ 	lwc1	$f10,0x8($s7)
/*  f160358:	4608503c */ 	c.lt.s	$f10,$f8
/*  f16035c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160360:	4503000e */ 	bc1tl	.L0f16039c
/*  f160364:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f160368:	c7b20098 */ 	lwc1	$f18,0x98($sp)
.L0f16036c:
/*  f16036c:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f160370:	27a6009c */ 	addiu	$a2,$sp,0x9c
/*  f160374:	4600903c */ 	c.lt.s	$f18,$f0
/*  f160378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16037c:	4502000c */ 	bc1fl	.L0f1603b0
/*  f160380:	02a02025 */ 	or	$a0,$s5,$zero
/*  f160384:	c6f00008 */ 	lwc1	$f16,0x8($s7)
/*  f160388:	4610903c */ 	c.lt.s	$f18,$f16
/*  f16038c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160390:	45020007 */ 	bc1fl	.L0f1603b0
/*  f160394:	02a02025 */ 	or	$a0,$s5,$zero
/*  f160398:	afa000e4 */ 	sw	$zero,0xe4($sp)
.L0f16039c:
/*  f16039c:	2406ffb1 */ 	addiu	$a2,$zero,-79
/*  f1603a0:	2405ffbf */ 	addiu	$a1,$zero,-65
/*  f1603a4:	10000193 */ 	beqz	$zero,.L0f1609f4
/*  f1603a8:	2403000a */ 	addiu	$v1,$zero,0xa
/*  f1603ac:	02a02025 */ 	or	$a0,$s5,$zero
.L0f1603b0:
/*  f1603b0:	27a70090 */ 	addiu	$a3,$sp,0x90
/*  f1603b4:	0fc57cac */ 	jal	func0f15f2b0
/*  f1603b8:	a7a800ee */ 	sh	$t0,0xee($sp)
/*  f1603bc:	87a800ee */ 	lh	$t0,0xee($sp)
/*  f1603c0:	afa200e4 */ 	sw	$v0,0xe4($sp)
/*  f1603c4:	2406ffb1 */ 	addiu	$a2,$zero,-79
/*  f1603c8:	2405ffbf */ 	addiu	$a1,$zero,-65
/*  f1603cc:	10000189 */ 	beqz	$zero,.L0f1609f4
/*  f1603d0:	2403000a */ 	addiu	$v1,$zero,0xa
.L0f1603d4:
/*  f1603d4:	17200005 */ 	bnez	$t9,.L0f1603ec
/*  f1603d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1603dc:	8fac0100 */ 	lw	$t4,0x100($sp)
/*  f1603e0:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f1603e4:	1000ff18 */ 	beqz	$zero,.L0f160048
/*  f1603e8:	afad0100 */ 	sw	$t5,0x100($sp)
.L0f1603ec:
/*  f1603ec:	10a20007 */ 	beq	$a1,$v0,.L0f16040c
/*  f1603f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1603f4:	10c20005 */ 	beq	$a2,$v0,.L0f16040c
/*  f1603f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1603fc:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f160400:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f160404:	1000ff10 */ 	beqz	$zero,.L0f160048
/*  f160408:	afaf0100 */ 	sw	$t7,0x100($sp)
.L0f16040c:
/*  f16040c:	14a2002d */ 	bne	$a1,$v0,.L0f1604c4
/*  f160410:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160414:	8fa20100 */ 	lw	$v0,0x100($sp)
/*  f160418:	00009825 */ 	or	$s3,$zero,$zero
/*  f16041c:	00004025 */ 	or	$t0,$zero,$zero
/*  f160420:	90580005 */ 	lbu	$t8,0x5($v0)
/*  f160424:	0303001a */ 	div	$zero,$t8,$v1
/*  f160428:	00004812 */ 	mflo	$t1
/*  f16042c:	afa9006c */ 	sw	$t1,0x6c($sp)
/*  f160430:	904a0006 */ 	lbu	$t2,0x6($v0)
/*  f160434:	14600002 */ 	bnez	$v1,.L0f160440
/*  f160438:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16043c:	0007000d */ 	break	0x7
.L0f160440:
/*  f160440:	2401ffff */ 	addiu	$at,$zero,-1
/*  f160444:	14610004 */ 	bne	$v1,$at,.L0f160458
/*  f160448:	3c018000 */ 	lui	$at,0x8000
/*  f16044c:	17010002 */ 	bne	$t8,$at,.L0f160458
/*  f160450:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160454:	0006000d */ 	break	0x6
.L0f160458:
/*  f160458:	0143001a */ 	div	$zero,$t2,$v1
/*  f16045c:	00005812 */ 	mflo	$t3
/*  f160460:	afab0070 */ 	sw	$t3,0x70($sp)
/*  f160464:	90590007 */ 	lbu	$t9,0x7($v0)
/*  f160468:	14600002 */ 	bnez	$v1,.L0f160474
/*  f16046c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160470:	0007000d */ 	break	0x7
.L0f160474:
/*  f160474:	2401ffff */ 	addiu	$at,$zero,-1
/*  f160478:	14610004 */ 	bne	$v1,$at,.L0f16048c
/*  f16047c:	3c018000 */ 	lui	$at,0x8000
/*  f160480:	15410002 */ 	bne	$t2,$at,.L0f16048c
/*  f160484:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160488:	0006000d */ 	break	0x6
.L0f16048c:
/*  f16048c:	0323001a */ 	div	$zero,$t9,$v1
/*  f160490:	00006012 */ 	mflo	$t4
/*  f160494:	afac0074 */ 	sw	$t4,0x74($sp)
/*  f160498:	14600002 */ 	bnez	$v1,.L0f1604a4
/*  f16049c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1604a0:	0007000d */ 	break	0x7
.L0f1604a4:
/*  f1604a4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1604a8:	14610004 */ 	bne	$v1,$at,.L0f1604bc
/*  f1604ac:	3c018000 */ 	lui	$at,0x8000
/*  f1604b0:	17210002 */ 	bne	$t9,$at,.L0f1604bc
/*  f1604b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1604b8:	0006000d */ 	break	0x6
.L0f1604bc:
/*  f1604bc:	10000010 */ 	beqz	$zero,.L0f160500
/*  f1604c0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1604c4:
/*  f1604c4:	14c2000e */ 	bne	$a2,$v0,.L0f160500
/*  f1604c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1604cc:	8fad0100 */ 	lw	$t5,0x100($sp)
/*  f1604d0:	24130003 */ 	addiu	$s3,$zero,0x3
/*  f1604d4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1604d8:	8dae0004 */ 	lw	$t6,0x4($t5)
/*  f1604dc:	01a0a025 */ 	or	$s4,$t5,$zero
/*  f1604e0:	31cf000f */ 	andi	$t7,$t6,0xf
/*  f1604e4:	afaf006c */ 	sw	$t7,0x6c($sp)
/*  f1604e8:	91b80007 */ 	lbu	$t8,0x7($t5)
/*  f1604ec:	00184902 */ 	srl	$t1,$t8,0x4
/*  f1604f0:	afa90070 */ 	sw	$t1,0x70($sp)
/*  f1604f4:	8daa0000 */ 	lw	$t2,0x0($t5)
/*  f1604f8:	314b000f */ 	andi	$t3,$t2,0xf
/*  f1604fc:	afab0074 */ 	sw	$t3,0x74($sp)
.L0f160500:
/*  f160500:	8fb9006c */ 	lw	$t9,0x6c($sp)
.L0f160504:
/*  f160504:	2403000a */ 	addiu	$v1,$zero,0xa
/*  f160508:	2405ffbf */ 	addiu	$a1,$zero,-65
/*  f16050c:	17200009 */ 	bnez	$t9,.L0f160534
/*  f160510:	2406ffb1 */ 	addiu	$a2,$zero,-79
/*  f160514:	8fac0070 */ 	lw	$t4,0x70($sp)
/*  f160518:	8fae0074 */ 	lw	$t6,0x74($sp)
/*  f16051c:	55800006 */ 	bnezl	$t4,.L0f160538
/*  f160520:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f160524:	55c00004 */ 	bnezl	$t6,.L0f160538
/*  f160528:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f16052c:	10000132 */ 	beqz	$zero,.L0f1609f8
/*  f160530:	8fac0100 */ 	lw	$t4,0x100($sp)
.L0f160534:
/*  f160534:	8faf006c */ 	lw	$t7,0x6c($sp)
.L0f160538:
/*  f160538:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f16053c:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f160540:	01e60019 */ 	multu	$t7,$a2
/*  f160544:	3c05800a */ 	lui	$a1,%hi(var800a6470)
/*  f160548:	24a56470 */ 	addiu	$a1,$a1,%lo(var800a6470)
/*  f16054c:	8fb90074 */ 	lw	$t9,0x74($sp)
/*  f160550:	0000c012 */ 	mflo	$t8
/*  f160554:	00184880 */ 	sll	$t1,$t8,0x2
/*  f160558:	01252021 */ 	addu	$a0,$t1,$a1
/*  f16055c:	01a60019 */ 	multu	$t5,$a2
/*  f160560:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f160564:	00808025 */ 	or	$s0,$a0,$zero
/*  f160568:	e7a6009c */ 	swc1	$f6,0x9c($sp)
/*  f16056c:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f160570:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f160574:	e7a40090 */ 	swc1	$f4,0x90($sp)
/*  f160578:	00005012 */ 	mflo	$t2
/*  f16057c:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f160580:	01651021 */ 	addu	$v0,$t3,$a1
/*  f160584:	03260019 */ 	multu	$t9,$a2
/*  f160588:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f16058c:	00408825 */ 	or	$s1,$v0,$zero
/*  f160590:	4608503c */ 	c.lt.s	$f10,$f8
/*  f160594:	00006012 */ 	mflo	$t4
/*  f160598:	000c7080 */ 	sll	$t6,$t4,0x2
/*  f16059c:	01c51821 */ 	addu	$v1,$t6,$a1
/*  f1605a0:	45000003 */ 	bc1f	.L0f1605b0
/*  f1605a4:	0060f025 */ 	or	$s8,$v1,$zero
/*  f1605a8:	c4520000 */ 	lwc1	$f18,0x0($v0)
/*  f1605ac:	e7b2009c */ 	swc1	$f18,0x9c($sp)
.L0f1605b0:
/*  f1605b0:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f1605b4:	c7b00090 */ 	lwc1	$f16,0x90($sp)
/*  f1605b8:	4600803c */ 	c.lt.s	$f16,$f0
/*  f1605bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1605c0:	45020003 */ 	bc1fl	.L0f1605d0
/*  f1605c4:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f1605c8:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f1605cc:	c4600000 */ 	lwc1	$f0,0x0($v1)
.L0f1605d0:
/*  f1605d0:	c7a6009c */ 	lwc1	$f6,0x9c($sp)
/*  f1605d4:	4606003c */ 	c.lt.s	$f0,$f6
/*  f1605d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1605dc:	45020004 */ 	bc1fl	.L0f1605f0
/*  f1605e0:	c7a40090 */ 	lwc1	$f4,0x90($sp)
/*  f1605e4:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f1605e8:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f1605ec:	c7a40090 */ 	lwc1	$f4,0x90($sp)
.L0f1605f0:
/*  f1605f0:	4600203c */ 	c.lt.s	$f4,$f0
/*  f1605f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1605f8:	45020003 */ 	bc1fl	.L0f160608
/*  f1605fc:	c6a00000 */ 	lwc1	$f0,0x0($s5)
/*  f160600:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f160604:	c6a00000 */ 	lwc1	$f0,0x0($s5)
.L0f160608:
/*  f160608:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f16060c:	460a003c */ 	c.lt.s	$f0,$f10
/*  f160610:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160614:	45020007 */ 	bc1fl	.L0f160634
/*  f160618:	c7b20090 */ 	lwc1	$f18,0x90($sp)
/*  f16061c:	c6e80000 */ 	lwc1	$f8,0x0($s7)
/*  f160620:	460a403c */ 	c.lt.s	$f8,$f10
/*  f160624:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160628:	450300c5 */ 	bc1tl	.L0f160940
/*  f16062c:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f160630:	c7b20090 */ 	lwc1	$f18,0x90($sp)
.L0f160634:
/*  f160634:	4600903c */ 	c.lt.s	$f18,$f0
/*  f160638:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16063c:	45020007 */ 	bc1fl	.L0f16065c
/*  f160640:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f160644:	c6f00000 */ 	lwc1	$f16,0x0($s7)
/*  f160648:	4610903c */ 	c.lt.s	$f18,$f16
/*  f16064c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160650:	450300bb */ 	bc1tl	.L0f160940
/*  f160654:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f160658:	c4860008 */ 	lwc1	$f6,0x8($a0)
.L0f16065c:
/*  f16065c:	e7a600a4 */ 	swc1	$f6,0xa4($sp)
/*  f160660:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f160664:	c7a800a4 */ 	lwc1	$f8,0xa4($sp)
/*  f160668:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f16066c:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f160670:	4608003c */ 	c.lt.s	$f0,$f8
/*  f160674:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160678:	45020004 */ 	bc1fl	.L0f16068c
/*  f16067c:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
/*  f160680:	e7a000a4 */ 	swc1	$f0,0xa4($sp)
/*  f160684:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f160688:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
.L0f16068c:
/*  f16068c:	4600503c */ 	c.lt.s	$f10,$f0
/*  f160690:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160694:	45020003 */ 	bc1fl	.L0f1606a4
/*  f160698:	c4600008 */ 	lwc1	$f0,0x8($v1)
/*  f16069c:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f1606a0:	c4600008 */ 	lwc1	$f0,0x8($v1)
.L0f1606a4:
/*  f1606a4:	c7b200a4 */ 	lwc1	$f18,0xa4($sp)
/*  f1606a8:	4612003c */ 	c.lt.s	$f0,$f18
/*  f1606ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1606b0:	45020004 */ 	bc1fl	.L0f1606c4
/*  f1606b4:	c7b00098 */ 	lwc1	$f16,0x98($sp)
/*  f1606b8:	e7a000a4 */ 	swc1	$f0,0xa4($sp)
/*  f1606bc:	c4600008 */ 	lwc1	$f0,0x8($v1)
/*  f1606c0:	c7b00098 */ 	lwc1	$f16,0x98($sp)
.L0f1606c4:
/*  f1606c4:	4600803c */ 	c.lt.s	$f16,$f0
/*  f1606c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1606cc:	45020003 */ 	bc1fl	.L0f1606dc
/*  f1606d0:	c6a00008 */ 	lwc1	$f0,0x8($s5)
/*  f1606d4:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f1606d8:	c6a00008 */ 	lwc1	$f0,0x8($s5)
.L0f1606dc:
/*  f1606dc:	c7a600a4 */ 	lwc1	$f6,0xa4($sp)
/*  f1606e0:	4606003c */ 	c.lt.s	$f0,$f6
/*  f1606e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1606e8:	45020007 */ 	bc1fl	.L0f160708
/*  f1606ec:	c7a80098 */ 	lwc1	$f8,0x98($sp)
/*  f1606f0:	c6e40008 */ 	lwc1	$f4,0x8($s7)
/*  f1606f4:	4606203c */ 	c.lt.s	$f4,$f6
/*  f1606f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1606fc:	45030090 */ 	bc1tl	.L0f160940
/*  f160700:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f160704:	c7a80098 */ 	lwc1	$f8,0x98($sp)
.L0f160708:
/*  f160708:	4600403c */ 	c.lt.s	$f8,$f0
/*  f16070c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160710:	45020007 */ 	bc1fl	.L0f160730
/*  f160714:	c4920004 */ 	lwc1	$f18,0x4($a0)
/*  f160718:	c6ea0008 */ 	lwc1	$f10,0x8($s7)
/*  f16071c:	460a403c */ 	c.lt.s	$f8,$f10
/*  f160720:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160724:	45030086 */ 	bc1tl	.L0f160940
/*  f160728:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f16072c:	c4920004 */ 	lwc1	$f18,0x4($a0)
.L0f160730:
/*  f160730:	e7b200a0 */ 	swc1	$f18,0xa0($sp)
/*  f160734:	c4900004 */ 	lwc1	$f16,0x4($a0)
/*  f160738:	c7a400a0 */ 	lwc1	$f4,0xa0($sp)
/*  f16073c:	e7b00094 */ 	swc1	$f16,0x94($sp)
/*  f160740:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f160744:	4604003c */ 	c.lt.s	$f0,$f4
/*  f160748:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16074c:	45020004 */ 	bc1fl	.L0f160760
/*  f160750:	c7a60094 */ 	lwc1	$f6,0x94($sp)
/*  f160754:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
/*  f160758:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f16075c:	c7a60094 */ 	lwc1	$f6,0x94($sp)
.L0f160760:
/*  f160760:	4600303c */ 	c.lt.s	$f6,$f0
/*  f160764:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160768:	45020003 */ 	bc1fl	.L0f160778
/*  f16076c:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f160770:	e7a00094 */ 	swc1	$f0,0x94($sp)
/*  f160774:	c4600004 */ 	lwc1	$f0,0x4($v1)
.L0f160778:
/*  f160778:	c7a800a0 */ 	lwc1	$f8,0xa0($sp)
/*  f16077c:	4608003c */ 	c.lt.s	$f0,$f8
/*  f160780:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160784:	45020004 */ 	bc1fl	.L0f160798
/*  f160788:	c7aa0094 */ 	lwc1	$f10,0x94($sp)
/*  f16078c:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
/*  f160790:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f160794:	c7aa0094 */ 	lwc1	$f10,0x94($sp)
.L0f160798:
/*  f160798:	4600503c */ 	c.lt.s	$f10,$f0
/*  f16079c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1607a0:	45020003 */ 	bc1fl	.L0f1607b0
/*  f1607a4:	c6a00004 */ 	lwc1	$f0,0x4($s5)
/*  f1607a8:	e7a00094 */ 	swc1	$f0,0x94($sp)
/*  f1607ac:	c6a00004 */ 	lwc1	$f0,0x4($s5)
.L0f1607b0:
/*  f1607b0:	c7b200a0 */ 	lwc1	$f18,0xa0($sp)
/*  f1607b4:	4612003c */ 	c.lt.s	$f0,$f18
/*  f1607b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1607bc:	45020007 */ 	bc1fl	.L0f1607dc
/*  f1607c0:	c7a40094 */ 	lwc1	$f4,0x94($sp)
/*  f1607c4:	c6f00004 */ 	lwc1	$f16,0x4($s7)
/*  f1607c8:	4612803c */ 	c.lt.s	$f16,$f18
/*  f1607cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1607d0:	4503005b */ 	bc1tl	.L0f160940
/*  f1607d4:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f1607d8:	c7a40094 */ 	lwc1	$f4,0x94($sp)
.L0f1607dc:
/*  f1607dc:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f1607e0:	27a6009c */ 	addiu	$a2,$sp,0x9c
/*  f1607e4:	4600203c */ 	c.lt.s	$f4,$f0
/*  f1607e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1607ec:	45020007 */ 	bc1fl	.L0f16080c
/*  f1607f0:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1607f4:	c6e60004 */ 	lwc1	$f6,0x4($s7)
/*  f1607f8:	4606203c */ 	c.lt.s	$f4,$f6
/*  f1607fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160800:	4503004f */ 	bc1tl	.L0f160940
/*  f160804:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f160808:	02a02025 */ 	or	$a0,$s5,$zero
.L0f16080c:
/*  f16080c:	27a70090 */ 	addiu	$a3,$sp,0x90
/*  f160810:	0fc57cac */ 	jal	func0f15f2b0
/*  f160814:	a7a800ee */ 	sh	$t0,0xee($sp)
/*  f160818:	10400048 */ 	beqz	$v0,.L0f16093c
/*  f16081c:	87a800ee */ 	lh	$t0,0xee($sp)
/*  f160820:	8faf00fc */ 	lw	$t7,0xfc($sp)
/*  f160824:	27b80084 */ 	addiu	$t8,$sp,0x84
/*  f160828:	27a90078 */ 	addiu	$t1,$sp,0x78
/*  f16082c:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f160830:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f160834:	02002025 */ 	or	$a0,$s0,$zero
/*  f160838:	02202825 */ 	or	$a1,$s1,$zero
/*  f16083c:	03c03025 */ 	or	$a2,$s8,$zero
/*  f160840:	00003825 */ 	or	$a3,$zero,$zero
/*  f160844:	afb50010 */ 	sw	$s5,0x10($sp)
/*  f160848:	afb70014 */ 	sw	$s7,0x14($sp)
/*  f16084c:	a7a800ee */ 	sh	$t0,0xee($sp)
/*  f160850:	0c00bd58 */ 	jal	func0002f560
/*  f160854:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f160858:	10400038 */ 	beqz	$v0,.L0f16093c
/*  f16085c:	87a800ee */ 	lh	$t0,0xee($sp)
/*  f160860:	c7a80084 */ 	lwc1	$f8,0x84($sp)
/*  f160864:	c6aa0000 */ 	lwc1	$f10,0x0($s5)
/*  f160868:	c7b00088 */ 	lwc1	$f16,0x88($sp)
/*  f16086c:	c6b20004 */ 	lwc1	$f18,0x4($s5)
/*  f160870:	460a4001 */ 	sub.s	$f0,$f8,$f10
/*  f160874:	c6aa0008 */ 	lwc1	$f10,0x8($s5)
/*  f160878:	c7a6008c */ 	lwc1	$f6,0x8c($sp)
/*  f16087c:	8fad010c */ 	lw	$t5,0x10c($sp)
/*  f160880:	46000082 */ 	mul.s	$f2,$f0,$f0
/*  f160884:	46128001 */ 	sub.s	$f0,$f16,$f18
/*  f160888:	c5b20000 */ 	lwc1	$f18,0x0($t5)
/*  f16088c:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f160890:	460a3001 */ 	sub.s	$f0,$f6,$f10
/*  f160894:	46000402 */ 	mul.s	$f16,$f0,$f0
/*  f160898:	46041080 */ 	add.s	$f2,$f2,$f4
/*  f16089c:	46101080 */ 	add.s	$f2,$f2,$f16
/*  f1608a0:	4612103c */ 	c.lt.s	$f2,$f18
/*  f1608a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1608a8:	45020025 */ 	bc1fl	.L0f160940
/*  f1608ac:	2673ffff */ 	addiu	$s3,$s3,-1
/*  f1608b0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f1608b4:	afaa00cc */ 	sw	$t2,0xcc($sp)
/*  f1608b8:	e5a20000 */ 	swc1	$f2,0x0($t5)
/*  f1608bc:	e6480000 */ 	swc1	$f8,0x0($s2)
/*  f1608c0:	c7a40088 */ 	lwc1	$f4,0x88($sp)
/*  f1608c4:	2402000c */ 	addiu	$v0,$zero,0xc
/*  f1608c8:	e6440004 */ 	swc1	$f4,0x4($s2)
/*  f1608cc:	c7a6008c */ 	lwc1	$f6,0x8c($sp)
/*  f1608d0:	e6460008 */ 	swc1	$f6,0x8($s2)
/*  f1608d4:	c7aa0078 */ 	lwc1	$f10,0x78($sp)
/*  f1608d8:	e64a000c */ 	swc1	$f10,0xc($s2)
/*  f1608dc:	c7b0007c */ 	lwc1	$f16,0x7c($sp)
/*  f1608e0:	e6500010 */ 	swc1	$f16,0x10($s2)
/*  f1608e4:	c7b20080 */ 	lwc1	$f18,0x80($sp)
/*  f1608e8:	e6520014 */ 	swc1	$f18,0x14($s2)
/*  f1608ec:	8fab006c */ 	lw	$t3,0x6c($sp)
/*  f1608f0:	01620019 */ 	multu	$t3,$v0
/*  f1608f4:	240bffff */ 	addiu	$t3,$zero,-1
/*  f1608f8:	0000c812 */ 	mflo	$t9
/*  f1608fc:	03366021 */ 	addu	$t4,$t9,$s6
/*  f160900:	ae4c0018 */ 	sw	$t4,0x18($s2)
/*  f160904:	8fae0070 */ 	lw	$t6,0x70($sp)
/*  f160908:	01c20019 */ 	multu	$t6,$v0
/*  f16090c:	00007812 */ 	mflo	$t7
/*  f160910:	01f6c021 */ 	addu	$t8,$t7,$s6
/*  f160914:	ae58001c */ 	sw	$t8,0x1c($s2)
/*  f160918:	8fa90074 */ 	lw	$t1,0x74($sp)
/*  f16091c:	a64b002a */ 	sh	$t3,0x2a($s2)
/*  f160920:	01220019 */ 	multu	$t1,$v0
/*  f160924:	00005012 */ 	mflo	$t2
/*  f160928:	01566821 */ 	addu	$t5,$t2,$s6
/*  f16092c:	ae4d0020 */ 	sw	$t5,0x20($s2)
/*  f160930:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f160934:	a6480028 */ 	sh	$t0,0x28($s2)
/*  f160938:	ae590024 */ 	sw	$t9,0x24($s2)
.L0f16093c:
/*  f16093c:	2673ffff */ 	addiu	$s3,$s3,-1
.L0f160940:
/*  f160940:	24010002 */ 	addiu	$at,$zero,0x2
/*  f160944:	5661000d */ 	bnel	$s3,$at,.L0f16097c
/*  f160948:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16094c:	928c0006 */ 	lbu	$t4,0x6($s4)
/*  f160950:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f160954:	318e000f */ 	andi	$t6,$t4,0xf
/*  f160958:	afae006c */ 	sw	$t6,0x6c($sp)
/*  f16095c:	968f0006 */ 	lhu	$t7,0x6($s4)
/*  f160960:	000fc302 */ 	srl	$t8,$t7,0xc
/*  f160964:	afb80070 */ 	sw	$t8,0x70($sp)
/*  f160968:	92890003 */ 	lbu	$t1,0x3($s4)
/*  f16096c:	00095102 */ 	srl	$t2,$t1,0x4
/*  f160970:	1000001b */ 	beqz	$zero,.L0f1609e0
/*  f160974:	afaa0074 */ 	sw	$t2,0x74($sp)
/*  f160978:	24010001 */ 	addiu	$at,$zero,0x1
.L0f16097c:
/*  f16097c:	1661000c */ 	bne	$s3,$at,.L0f1609b0
/*  f160980:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160984:	968d0004 */ 	lhu	$t5,0x4($s4)
/*  f160988:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f16098c:	31ab000f */ 	andi	$t3,$t5,0xf
/*  f160990:	afab006c */ 	sw	$t3,0x6c($sp)
/*  f160994:	92990005 */ 	lbu	$t9,0x5($s4)
/*  f160998:	00196102 */ 	srl	$t4,$t9,0x4
/*  f16099c:	afac0070 */ 	sw	$t4,0x70($sp)
/*  f1609a0:	928e0002 */ 	lbu	$t6,0x2($s4)
/*  f1609a4:	31cf000f */ 	andi	$t7,$t6,0xf
/*  f1609a8:	1000000d */ 	beqz	$zero,.L0f1609e0
/*  f1609ac:	afaf0074 */ 	sw	$t7,0x74($sp)
.L0f1609b0:
/*  f1609b0:	1660000b */ 	bnez	$s3,.L0f1609e0
/*  f1609b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1609b8:	92980004 */ 	lbu	$t8,0x4($s4)
/*  f1609bc:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1609c0:	3309000f */ 	andi	$t1,$t8,0xf
/*  f1609c4:	afa9006c */ 	sw	$t1,0x6c($sp)
/*  f1609c8:	8e8a0004 */ 	lw	$t2,0x4($s4)
/*  f1609cc:	000a6f02 */ 	srl	$t5,$t2,0x1c
/*  f1609d0:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f1609d4:	968b0002 */ 	lhu	$t3,0x2($s4)
/*  f1609d8:	000bcb02 */ 	srl	$t9,$t3,0xc
/*  f1609dc:	afb90074 */ 	sw	$t9,0x74($sp)
.L0f1609e0:
/*  f1609e0:	0663fec8 */ 	bgezl	$s3,.L0f160504
/*  f1609e4:	8fb9006c */ 	lw	$t9,0x6c($sp)
/*  f1609e8:	2406ffb1 */ 	addiu	$a2,$zero,-79
/*  f1609ec:	2405ffbf */ 	addiu	$a1,$zero,-65
/*  f1609f0:	2403000a */ 	addiu	$v1,$zero,0xa
.L0f1609f4:
/*  f1609f4:	8fac0100 */ 	lw	$t4,0x100($sp)
.L0f1609f8:
/*  f1609f8:	258e0008 */ 	addiu	$t6,$t4,0x8
/*  f1609fc:	1000fd92 */ 	beqz	$zero,.L0f160048
/*  f160a00:	afae0100 */ 	sw	$t6,0x100($sp)
/*  f160a04:	8fbf0054 */ 	lw	$ra,0x54($sp)
.L0f160a08:
/*  f160a08:	8fa200cc */ 	lw	$v0,0xcc($sp)
/*  f160a0c:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f160a10:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f160a14:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f160a18:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f160a1c:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f160a20:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f160a24:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f160a28:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f160a2c:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f160a30:	03e00008 */ 	jr	$ra
/*  f160a34:	27bd00f0 */ 	addiu	$sp,$sp,0xf0
);

GLOBAL_ASM(
glabel func0f160a38
.late_rodata
glabel var7f1b75dc
.word 0x7f7fffff
.text
/*  f160a38:	27bdff08 */ 	addiu	$sp,$sp,-248
/*  f160a3c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f160a40:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f160a44:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f160a48:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f160a4c:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f160a50:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f160a54:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f160a58:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f160a5c:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f160a60:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f160a64:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f160a68:	afa60100 */ 	sw	$a2,0x100($sp)
/*  f160a6c:	8fb00108 */ 	lw	$s0,0x108($sp)
/*  f160a70:	8cf10004 */ 	lw	$s1,0x4($a3)
/*  f160a74:	00809825 */ 	or	$s3,$a0,$zero
/*  f160a78:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f160a7c:	00e09025 */ 	or	$s2,$a3,$zero
/*  f160a80:	02002025 */ 	or	$a0,$s0,$zero
/*  f160a84:	0fc576ed */ 	jal	func0f15dbb4
/*  f160a88:	02202825 */ 	or	$a1,$s1,$zero
/*  f160a8c:	964e0000 */ 	lhu	$t6,0x0($s2)
/*  f160a90:	3c0100ff */ 	lui	$at,0xff
/*  f160a94:	3c1f800a */ 	lui	$ra,%hi(var800a6470)
/*  f160a98:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f160a9c:	01f14021 */ 	addu	$t0,$t7,$s1
/*  f160aa0:	91040001 */ 	lbu	$a0,0x1($t0)
/*  f160aa4:	8d180004 */ 	lw	$t8,0x4($t0)
/*  f160aa8:	3421ffff */ 	ori	$at,$at,0xffff
/*  f160aac:	00047102 */ 	srl	$t6,$a0,0x4
/*  f160ab0:	31cf000f */ 	andi	$t7,$t6,0xf
/*  f160ab4:	27ff6470 */ 	addiu	$ra,$ra,%lo(var800a6470)
/*  f160ab8:	25e40001 */ 	addiu	$a0,$t7,0x1
/*  f160abc:	0301c824 */ 	and	$t9,$t8,$at
/*  f160ac0:	03225021 */ 	addu	$t2,$t9,$v0
/*  f160ac4:	18800022 */ 	blez	$a0,.L0f160b50
/*  f160ac8:	03e01825 */ 	or	$v1,$ra,$zero
/*  f160acc:	00102880 */ 	sll	$a1,$s0,0x2
/*  f160ad0:	00b02821 */ 	addu	$a1,$a1,$s0
/*  f160ad4:	3c02800a */ 	lui	$v0,%hi(var800a4cc4)
/*  f160ad8:	24424cc4 */ 	addiu	$v0,$v0,%lo(var800a4cc4)
/*  f160adc:	00052880 */ 	sll	$a1,$a1,0x2
.L0f160ae0:
/*  f160ae0:	854e0000 */ 	lh	$t6,0x0($t2)
/*  f160ae4:	8c580000 */ 	lw	$t8,0x0($v0)
/*  f160ae8:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f160aec:	448e3000 */ 	mtc1	$t6,$f6
/*  f160af0:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f160af4:	c7240004 */ 	lwc1	$f4,0x4($t9)
/*  f160af8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f160afc:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f160b00:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f160b04:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f160b08:	e46afff4 */ 	swc1	$f10,-0xc($v1)
/*  f160b0c:	8559fff6 */ 	lh	$t9,-0xa($t2)
/*  f160b10:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f160b14:	44999000 */ 	mtc1	$t9,$f18
/*  f160b18:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f160b1c:	c7100008 */ 	lwc1	$f16,0x8($t8)
/*  f160b20:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f160b24:	46068100 */ 	add.s	$f4,$f16,$f6
/*  f160b28:	e464fff8 */ 	swc1	$f4,-0x8($v1)
/*  f160b2c:	8558fff8 */ 	lh	$t8,-0x8($t2)
/*  f160b30:	8c4e0000 */ 	lw	$t6,0x0($v0)
/*  f160b34:	44985000 */ 	mtc1	$t8,$f10
/*  f160b38:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f160b3c:	c5e8000c */ 	lwc1	$f8,0xc($t7)
/*  f160b40:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f160b44:	46124400 */ 	add.s	$f16,$f8,$f18
/*  f160b48:	1c80ffe5 */ 	bgtz	$a0,.L0f160ae0
/*  f160b4c:	e470fffc */ 	swc1	$f16,-0x4($v1)
.L0f160b50:
/*  f160b50:	81020008 */ 	lb	$v0,0x8($t0)
/*  f160b54:	3c017f1b */ 	lui	$at,%hi(var7f1b75dc)
/*  f160b58:	c43475dc */ 	lwc1	$f20,%lo(var7f1b75dc)($at)
/*  f160b5c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f160b60:	00006825 */ 	or	$t5,$zero,$zero
/*  f160b64:	104101d1 */ 	beq	$v0,$at,.L0f1612ac
/*  f160b68:	25080008 */ 	addiu	$t0,$t0,0x8
/*  f160b6c:	2401ffb8 */ 	addiu	$at,$zero,-72
/*  f160b70:	104101ce */ 	beq	$v0,$at,.L0f1612ac
/*  f160b74:	240c000c */ 	addiu	$t4,$zero,0xc
/*  f160b78:	afb20104 */ 	sw	$s2,0x104($sp)
/*  f160b7c:	241200fd */ 	addiu	$s2,$zero,0xfd
/*  f160b80:	8fbe00f0 */ 	lw	$s8,0xf0($sp)
/*  f160b84:	8fb40078 */ 	lw	$s4,0x78($sp)
/*  f160b88:	8fb0010c */ 	lw	$s0,0x10c($sp)
/*  f160b8c:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f160b90:	87a900f4 */ 	lh	$t1,0xf4($sp)
/*  f160b94:	2401ffbf */ 	addiu	$at,$zero,-65
.L0f160b98:
/*  f160b98:	10410005 */ 	beq	$v0,$at,.L0f160bb0
/*  f160b9c:	2401ffb1 */ 	addiu	$at,$zero,-79
/*  f160ba0:	50410004 */ 	beql	$v0,$at,.L0f160bb4
/*  f160ba4:	2401ffbf */ 	addiu	$at,$zero,-65
/*  f160ba8:	100001b7 */ 	beqz	$zero,.L0f161288
/*  f160bac:	25080008 */ 	addiu	$t0,$t0,0x8
.L0f160bb0:
/*  f160bb0:	2401ffbf */ 	addiu	$at,$zero,-65
.L0f160bb4:
/*  f160bb4:	5441002e */ 	bnel	$v0,$at,.L0f160c70
/*  f160bb8:	2401ffb1 */ 	addiu	$at,$zero,-79
/*  f160bbc:	2402000a */ 	addiu	$v0,$zero,0xa
/*  f160bc0:	91190005 */ 	lbu	$t9,0x5($t0)
/*  f160bc4:	0000f025 */ 	or	$s8,$zero,$zero
/*  f160bc8:	00004825 */ 	or	$t1,$zero,$zero
/*  f160bcc:	0322001a */ 	div	$zero,$t9,$v0
/*  f160bd0:	00007012 */ 	mflo	$t6
/*  f160bd4:	afae00dc */ 	sw	$t6,0xdc($sp)
/*  f160bd8:	910f0006 */ 	lbu	$t7,0x6($t0)
/*  f160bdc:	14400002 */ 	bnez	$v0,.L0f160be8
/*  f160be0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160be4:	0007000d */ 	break	0x7
.L0f160be8:
/*  f160be8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f160bec:	14410004 */ 	bne	$v0,$at,.L0f160c00
/*  f160bf0:	3c018000 */ 	lui	$at,0x8000
/*  f160bf4:	17210002 */ 	bne	$t9,$at,.L0f160c00
/*  f160bf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160bfc:	0006000d */ 	break	0x6
.L0f160c00:
/*  f160c00:	01e2001a */ 	div	$zero,$t7,$v0
/*  f160c04:	0000c012 */ 	mflo	$t8
/*  f160c08:	afb800e0 */ 	sw	$t8,0xe0($sp)
/*  f160c0c:	91190007 */ 	lbu	$t9,0x7($t0)
/*  f160c10:	14400002 */ 	bnez	$v0,.L0f160c1c
/*  f160c14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160c18:	0007000d */ 	break	0x7
.L0f160c1c:
/*  f160c1c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f160c20:	14410004 */ 	bne	$v0,$at,.L0f160c34
/*  f160c24:	3c018000 */ 	lui	$at,0x8000
/*  f160c28:	15e10002 */ 	bne	$t7,$at,.L0f160c34
/*  f160c2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160c30:	0006000d */ 	break	0x6
.L0f160c34:
/*  f160c34:	0322001a */ 	div	$zero,$t9,$v0
/*  f160c38:	00007012 */ 	mflo	$t6
/*  f160c3c:	afae00e4 */ 	sw	$t6,0xe4($sp)
/*  f160c40:	14400002 */ 	bnez	$v0,.L0f160c4c
/*  f160c44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160c48:	0007000d */ 	break	0x7
.L0f160c4c:
/*  f160c4c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f160c50:	14410004 */ 	bne	$v0,$at,.L0f160c64
/*  f160c54:	3c018000 */ 	lui	$at,0x8000
/*  f160c58:	17210002 */ 	bne	$t9,$at,.L0f160c64
/*  f160c5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160c60:	0006000d */ 	break	0x6
.L0f160c64:
/*  f160c64:	10000011 */ 	beqz	$zero,.L0f160cac
/*  f160c68:	8fb900dc */ 	lw	$t9,0xdc($sp)
/*  f160c6c:	2401ffb1 */ 	addiu	$at,$zero,-79
.L0f160c70:
/*  f160c70:	5441000e */ 	bnel	$v0,$at,.L0f160cac
/*  f160c74:	8fb900dc */ 	lw	$t9,0xdc($sp)
/*  f160c78:	8d0f0004 */ 	lw	$t7,0x4($t0)
/*  f160c7c:	0100a025 */ 	or	$s4,$t0,$zero
/*  f160c80:	0160f025 */ 	or	$s8,$t3,$zero
/*  f160c84:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f160c88:	afb800dc */ 	sw	$t8,0xdc($sp)
/*  f160c8c:	91190007 */ 	lbu	$t9,0x7($t0)
/*  f160c90:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f160c94:	00197102 */ 	srl	$t6,$t9,0x4
/*  f160c98:	afae00e0 */ 	sw	$t6,0xe0($sp)
/*  f160c9c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f160ca0:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f160ca4:	afb800e4 */ 	sw	$t8,0xe4($sp)
/*  f160ca8:	8fb900dc */ 	lw	$t9,0xdc($sp)
.L0f160cac:
/*  f160cac:	8fae00e0 */ 	lw	$t6,0xe0($sp)
/*  f160cb0:	57200006 */ 	bnezl	$t9,.L0f160ccc
/*  f160cb4:	8fb800dc */ 	lw	$t8,0xdc($sp)
/*  f160cb8:	15c00003 */ 	bnez	$t6,.L0f160cc8
/*  f160cbc:	8faf00e4 */ 	lw	$t7,0xe4($sp)
/*  f160cc0:	51e00171 */ 	beqzl	$t7,.L0f161288
/*  f160cc4:	25080008 */ 	addiu	$t0,$t0,0x8
.L0f160cc8:
/*  f160cc8:	8fb800dc */ 	lw	$t8,0xdc($sp)
.L0f160ccc:
/*  f160ccc:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f160cd0:	030b0019 */ 	multu	$t8,$t3
/*  f160cd4:	0000c812 */ 	mflo	$t9
/*  f160cd8:	00197080 */ 	sll	$t6,$t9,0x2
/*  f160cdc:	01df2021 */ 	addu	$a0,$t6,$ra
/*  f160ce0:	01eb0019 */ 	multu	$t7,$t3
/*  f160ce4:	8fae00e4 */ 	lw	$t6,0xe4($sp)
/*  f160ce8:	0080b025 */ 	or	$s6,$a0,$zero
/*  f160cec:	0000c012 */ 	mflo	$t8
/*  f160cf0:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f160cf4:	033f1021 */ 	addu	$v0,$t9,$ra
/*  f160cf8:	01cb0019 */ 	multu	$t6,$t3
/*  f160cfc:	0040b825 */ 	or	$s7,$v0,$zero
/*  f160d00:	00007812 */ 	mflo	$t7
/*  f160d04:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f160d08:	031f1821 */ 	addu	$v1,$t8,$ra
/*  f160d0c:	afa300bc */ 	sw	$v1,0xbc($sp)
/*  f160d10:	c4860000 */ 	lwc1	$f6,0x0($a0)
/*  f160d14:	e7a60098 */ 	swc1	$f6,0x98($sp)
/*  f160d18:	c7aa0098 */ 	lwc1	$f10,0x98($sp)
/*  f160d1c:	c4440000 */ 	lwc1	$f4,0x0($v0)
/*  f160d20:	460a203c */ 	c.lt.s	$f4,$f10
/*  f160d24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160d28:	45020004 */ 	bc1fl	.L0f160d3c
/*  f160d2c:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f160d30:	c4480000 */ 	lwc1	$f8,0x0($v0)
/*  f160d34:	e7a80098 */ 	swc1	$f8,0x98($sp)
/*  f160d38:	c4600000 */ 	lwc1	$f0,0x0($v1)
.L0f160d3c:
/*  f160d3c:	c7b20098 */ 	lwc1	$f18,0x98($sp)
/*  f160d40:	4612003c */ 	c.lt.s	$f0,$f18
/*  f160d44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160d48:	45020003 */ 	bc1fl	.L0f160d58
/*  f160d4c:	c6700000 */ 	lwc1	$f16,0x0($s3)
/*  f160d50:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f160d54:	c6700000 */ 	lwc1	$f16,0x0($s3)
.L0f160d58:
/*  f160d58:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f160d5c:	4606803c */ 	c.lt.s	$f16,$f6
/*  f160d60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160d64:	45020007 */ 	bc1fl	.L0f160d84
/*  f160d68:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f160d6c:	c6a40000 */ 	lwc1	$f4,0x0($s5)
/*  f160d70:	4606203c */ 	c.lt.s	$f4,$f6
/*  f160d74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160d78:	45030116 */ 	bc1tl	.L0f1611d4
/*  f160d7c:	27deffff */ 	addiu	$s8,$s8,-1
/*  f160d80:	c48a0000 */ 	lwc1	$f10,0x0($a0)
.L0f160d84:
/*  f160d84:	e7aa008c */ 	swc1	$f10,0x8c($sp)
/*  f160d88:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*  f160d8c:	c4400000 */ 	lwc1	$f0,0x0($v0)
/*  f160d90:	4600403c */ 	c.lt.s	$f8,$f0
/*  f160d94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160d98:	45020003 */ 	bc1fl	.L0f160da8
/*  f160d9c:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f160da0:	e7a0008c */ 	swc1	$f0,0x8c($sp)
/*  f160da4:	c4600000 */ 	lwc1	$f0,0x0($v1)
.L0f160da8:
/*  f160da8:	c7b2008c */ 	lwc1	$f18,0x8c($sp)
/*  f160dac:	4600903c */ 	c.lt.s	$f18,$f0
/*  f160db0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160db4:	45020003 */ 	bc1fl	.L0f160dc4
/*  f160db8:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*  f160dbc:	e7a0008c */ 	swc1	$f0,0x8c($sp)
/*  f160dc0:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
.L0f160dc4:
/*  f160dc4:	c6640000 */ 	lwc1	$f4,0x0($s3)
/*  f160dc8:	4604803c */ 	c.lt.s	$f16,$f4
/*  f160dcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160dd0:	45020007 */ 	bc1fl	.L0f160df0
/*  f160dd4:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f160dd8:	c6a60000 */ 	lwc1	$f6,0x0($s5)
/*  f160ddc:	4606803c */ 	c.lt.s	$f16,$f6
/*  f160de0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160de4:	450300fb */ 	bc1tl	.L0f1611d4
/*  f160de8:	27deffff */ 	addiu	$s8,$s8,-1
/*  f160dec:	c48a0008 */ 	lwc1	$f10,0x8($a0)
.L0f160df0:
/*  f160df0:	e7aa00a0 */ 	swc1	$f10,0xa0($sp)
/*  f160df4:	c7a800a0 */ 	lwc1	$f8,0xa0($sp)
/*  f160df8:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f160dfc:	4608003c */ 	c.lt.s	$f0,$f8
/*  f160e00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160e04:	45020003 */ 	bc1fl	.L0f160e14
/*  f160e08:	c4600008 */ 	lwc1	$f0,0x8($v1)
/*  f160e0c:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
/*  f160e10:	c4600008 */ 	lwc1	$f0,0x8($v1)
.L0f160e14:
/*  f160e14:	c7b200a0 */ 	lwc1	$f18,0xa0($sp)
/*  f160e18:	4612003c */ 	c.lt.s	$f0,$f18
/*  f160e1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160e20:	45020003 */ 	bc1fl	.L0f160e30
/*  f160e24:	c6640008 */ 	lwc1	$f4,0x8($s3)
/*  f160e28:	e7a000a0 */ 	swc1	$f0,0xa0($sp)
/*  f160e2c:	c6640008 */ 	lwc1	$f4,0x8($s3)
.L0f160e30:
/*  f160e30:	c7b000a0 */ 	lwc1	$f16,0xa0($sp)
/*  f160e34:	4610203c */ 	c.lt.s	$f4,$f16
/*  f160e38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160e3c:	45020007 */ 	bc1fl	.L0f160e5c
/*  f160e40:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f160e44:	c6a60008 */ 	lwc1	$f6,0x8($s5)
/*  f160e48:	4610303c */ 	c.lt.s	$f6,$f16
/*  f160e4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160e50:	450300e0 */ 	bc1tl	.L0f1611d4
/*  f160e54:	27deffff */ 	addiu	$s8,$s8,-1
/*  f160e58:	c48a0008 */ 	lwc1	$f10,0x8($a0)
.L0f160e5c:
/*  f160e5c:	e7aa0094 */ 	swc1	$f10,0x94($sp)
/*  f160e60:	c7a80094 */ 	lwc1	$f8,0x94($sp)
/*  f160e64:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f160e68:	4600403c */ 	c.lt.s	$f8,$f0
/*  f160e6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160e70:	45020003 */ 	bc1fl	.L0f160e80
/*  f160e74:	c4600008 */ 	lwc1	$f0,0x8($v1)
/*  f160e78:	e7a00094 */ 	swc1	$f0,0x94($sp)
/*  f160e7c:	c4600008 */ 	lwc1	$f0,0x8($v1)
.L0f160e80:
/*  f160e80:	c7b20094 */ 	lwc1	$f18,0x94($sp)
/*  f160e84:	4600903c */ 	c.lt.s	$f18,$f0
/*  f160e88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160e8c:	45020003 */ 	bc1fl	.L0f160e9c
/*  f160e90:	c7a40094 */ 	lwc1	$f4,0x94($sp)
/*  f160e94:	e7a00094 */ 	swc1	$f0,0x94($sp)
/*  f160e98:	c7a40094 */ 	lwc1	$f4,0x94($sp)
.L0f160e9c:
/*  f160e9c:	c6660008 */ 	lwc1	$f6,0x8($s3)
/*  f160ea0:	4606203c */ 	c.lt.s	$f4,$f6
/*  f160ea4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160ea8:	45020007 */ 	bc1fl	.L0f160ec8
/*  f160eac:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f160eb0:	c6b00008 */ 	lwc1	$f16,0x8($s5)
/*  f160eb4:	4610203c */ 	c.lt.s	$f4,$f16
/*  f160eb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160ebc:	450300c5 */ 	bc1tl	.L0f1611d4
/*  f160ec0:	27deffff */ 	addiu	$s8,$s8,-1
/*  f160ec4:	c48a0004 */ 	lwc1	$f10,0x4($a0)
.L0f160ec8:
/*  f160ec8:	e7aa009c */ 	swc1	$f10,0x9c($sp)
/*  f160ecc:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f160ed0:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f160ed4:	4608003c */ 	c.lt.s	$f0,$f8
/*  f160ed8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160edc:	45020003 */ 	bc1fl	.L0f160eec
/*  f160ee0:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f160ee4:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f160ee8:	c4600004 */ 	lwc1	$f0,0x4($v1)
.L0f160eec:
/*  f160eec:	c7b2009c */ 	lwc1	$f18,0x9c($sp)
/*  f160ef0:	4612003c */ 	c.lt.s	$f0,$f18
/*  f160ef4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160ef8:	45020003 */ 	bc1fl	.L0f160f08
/*  f160efc:	c6660004 */ 	lwc1	$f6,0x4($s3)
/*  f160f00:	e7a0009c */ 	swc1	$f0,0x9c($sp)
/*  f160f04:	c6660004 */ 	lwc1	$f6,0x4($s3)
.L0f160f08:
/*  f160f08:	c7a4009c */ 	lwc1	$f4,0x9c($sp)
/*  f160f0c:	4604303c */ 	c.lt.s	$f6,$f4
/*  f160f10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160f14:	45020007 */ 	bc1fl	.L0f160f34
/*  f160f18:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f160f1c:	c6b00004 */ 	lwc1	$f16,0x4($s5)
/*  f160f20:	4604803c */ 	c.lt.s	$f16,$f4
/*  f160f24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160f28:	450300aa */ 	bc1tl	.L0f1611d4
/*  f160f2c:	27deffff */ 	addiu	$s8,$s8,-1
/*  f160f30:	c48a0004 */ 	lwc1	$f10,0x4($a0)
.L0f160f34:
/*  f160f34:	e7aa0090 */ 	swc1	$f10,0x90($sp)
/*  f160f38:	c7a80090 */ 	lwc1	$f8,0x90($sp)
/*  f160f3c:	c4400004 */ 	lwc1	$f0,0x4($v0)
/*  f160f40:	4600403c */ 	c.lt.s	$f8,$f0
/*  f160f44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160f48:	45020003 */ 	bc1fl	.L0f160f58
/*  f160f4c:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f160f50:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f160f54:	c4600004 */ 	lwc1	$f0,0x4($v1)
.L0f160f58:
/*  f160f58:	c7b20090 */ 	lwc1	$f18,0x90($sp)
/*  f160f5c:	4600903c */ 	c.lt.s	$f18,$f0
/*  f160f60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160f64:	45020003 */ 	bc1fl	.L0f160f74
/*  f160f68:	c7a60090 */ 	lwc1	$f6,0x90($sp)
/*  f160f6c:	e7a00090 */ 	swc1	$f0,0x90($sp)
/*  f160f70:	c7a60090 */ 	lwc1	$f6,0x90($sp)
.L0f160f74:
/*  f160f74:	c6700004 */ 	lwc1	$f16,0x4($s3)
/*  f160f78:	4610303c */ 	c.lt.s	$f6,$f16
/*  f160f7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160f80:	45020007 */ 	bc1fl	.L0f160fa0
/*  f160f84:	02602025 */ 	or	$a0,$s3,$zero
/*  f160f88:	c6a40004 */ 	lwc1	$f4,0x4($s5)
/*  f160f8c:	4604303c */ 	c.lt.s	$f6,$f4
/*  f160f90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f160f94:	4503008f */ 	bc1tl	.L0f1611d4
/*  f160f98:	27deffff */ 	addiu	$s8,$s8,-1
/*  f160f9c:	02602025 */ 	or	$a0,$s3,$zero
.L0f160fa0:
/*  f160fa0:	8fa50100 */ 	lw	$a1,0x100($sp)
/*  f160fa4:	27a60098 */ 	addiu	$a2,$sp,0x98
/*  f160fa8:	27a7008c */ 	addiu	$a3,$sp,0x8c
/*  f160fac:	afa80080 */ 	sw	$t0,0x80($sp)
/*  f160fb0:	a7a900f4 */ 	sh	$t1,0xf4($sp)
/*  f160fb4:	afaa0088 */ 	sw	$t2,0x88($sp)
/*  f160fb8:	0fc57cac */ 	jal	func0f15f2b0
/*  f160fbc:	afad00e8 */ 	sw	$t5,0xe8($sp)
/*  f160fc0:	3c1f800a */ 	lui	$ra,%hi(var800a6470)
/*  f160fc4:	27ff6470 */ 	addiu	$ra,$ra,%lo(var800a6470)
/*  f160fc8:	8fa80080 */ 	lw	$t0,0x80($sp)
/*  f160fcc:	87a900f4 */ 	lh	$t1,0xf4($sp)
/*  f160fd0:	8faa0088 */ 	lw	$t2,0x88($sp)
/*  f160fd4:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f160fd8:	240c000c */ 	addiu	$t4,$zero,0xc
/*  f160fdc:	1040007c */ 	beqz	$v0,.L0f1611d0
/*  f160fe0:	8fad00e8 */ 	lw	$t5,0xe8($sp)
/*  f160fe4:	8fb90100 */ 	lw	$t9,0x100($sp)
/*  f160fe8:	27ae00b0 */ 	addiu	$t6,$sp,0xb0
/*  f160fec:	27af00a4 */ 	addiu	$t7,$sp,0xa4
/*  f160ff0:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f160ff4:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f160ff8:	02c02025 */ 	or	$a0,$s6,$zero
/*  f160ffc:	02e02825 */ 	or	$a1,$s7,$zero
/*  f161000:	8fa600bc */ 	lw	$a2,0xbc($sp)
/*  f161004:	00003825 */ 	or	$a3,$zero,$zero
/*  f161008:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f16100c:	afb50014 */ 	sw	$s5,0x14($sp)
/*  f161010:	afa80080 */ 	sw	$t0,0x80($sp)
/*  f161014:	a7a900f4 */ 	sh	$t1,0xf4($sp)
/*  f161018:	afaa0088 */ 	sw	$t2,0x88($sp)
/*  f16101c:	afad00e8 */ 	sw	$t5,0xe8($sp)
/*  f161020:	0c00bd58 */ 	jal	func0002f560
/*  f161024:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f161028:	3c1f800a */ 	lui	$ra,%hi(var800a6470)
/*  f16102c:	27ff6470 */ 	addiu	$ra,$ra,%lo(var800a6470)
/*  f161030:	8fa80080 */ 	lw	$t0,0x80($sp)
/*  f161034:	87a900f4 */ 	lh	$t1,0xf4($sp)
/*  f161038:	8faa0088 */ 	lw	$t2,0x88($sp)
/*  f16103c:	240b0003 */ 	addiu	$t3,$zero,0x3
/*  f161040:	240c000c */ 	addiu	$t4,$zero,0xc
/*  f161044:	10400062 */ 	beqz	$v0,.L0f1611d0
/*  f161048:	8fad00e8 */ 	lw	$t5,0xe8($sp)
/*  f16104c:	c7aa00b0 */ 	lwc1	$f10,0xb0($sp)
/*  f161050:	c6680000 */ 	lwc1	$f8,0x0($s3)
/*  f161054:	c7b200b4 */ 	lwc1	$f18,0xb4($sp)
/*  f161058:	c6700004 */ 	lwc1	$f16,0x4($s3)
/*  f16105c:	46085001 */ 	sub.s	$f0,$f10,$f8
/*  f161060:	c66a0008 */ 	lwc1	$f10,0x8($s3)
/*  f161064:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f161068:	46000082 */ 	mul.s	$f2,$f0,$f0
/*  f16106c:	46109001 */ 	sub.s	$f0,$f18,$f16
/*  f161070:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f161074:	460a2001 */ 	sub.s	$f0,$f4,$f10
/*  f161078:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f16107c:	46061080 */ 	add.s	$f2,$f2,$f6
/*  f161080:	46081080 */ 	add.s	$f2,$f2,$f8
/*  f161084:	4614103c */ 	c.lt.s	$f2,$f20
/*  f161088:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16108c:	45020051 */ 	bc1fl	.L0f1611d4
/*  f161090:	27deffff */ 	addiu	$s8,$s8,-1
/*  f161094:	91180000 */ 	lbu	$t8,0x0($t0)
/*  f161098:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f16109c:	01001025 */ 	or	$v0,$t0,$zero
/*  f1610a0:	1258000a */ 	beq	$s2,$t8,.L0f1610cc
/*  f1610a4:	0228082b */ 	sltu	$at,$s1,$t0
/*  f1610a8:	10200008 */ 	beqz	$at,.L0f1610cc
/*  f1610ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1610b0:	9059fff8 */ 	lbu	$t9,-0x8($v0)
.L0f1610b4:
/*  f1610b4:	2442fff8 */ 	addiu	$v0,$v0,-8
/*  f1610b8:	0222082b */ 	sltu	$at,$s1,$v0
/*  f1610bc:	12590003 */ 	beq	$s2,$t9,.L0f1610cc
/*  f1610c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1610c4:	5420fffb */ 	bnezl	$at,.L0f1610b4
/*  f1610c8:	9059fff8 */ 	lbu	$t9,-0x8($v0)
.L0f1610cc:
/*  f1610cc:	1051000a */ 	beq	$v0,$s1,.L0f1610f8
/*  f1610d0:	8fb90104 */ 	lw	$t9,0x104($sp)
/*  f1610d4:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f1610d8:	3c040f00 */ 	lui	$a0,0xf00
/*  f1610dc:	3c020500 */ 	lui	$v0,0x500
/*  f1610e0:	00647024 */ 	and	$t6,$v1,$a0
/*  f1610e4:	108e0004 */ 	beq	$a0,$t6,.L0f1610f8
/*  f1610e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1610ec:	00627824 */ 	and	$t7,$v1,$v0
/*  f1610f0:	144f0003 */ 	bne	$v0,$t7,.L0f161100
/*  f1610f4:	3c018000 */ 	lui	$at,0x8000
.L0f1610f8:
/*  f1610f8:	10000004 */ 	beqz	$zero,.L0f16110c
/*  f1610fc:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f161100:
/*  f161100:	2462fff8 */ 	addiu	$v0,$v1,-8
/*  f161104:	0041c025 */ 	or	$t8,$v0,$at
/*  f161108:	87040000 */ 	lh	$a0,0x0($t8)
.L0f16110c:
/*  f16110c:	972e0002 */ 	lhu	$t6,0x2($t9)
/*  f161110:	24010002 */ 	addiu	$at,$zero,0x2
/*  f161114:	15c1000a */ 	bne	$t6,$at,.L0f161140
/*  f161118:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16111c:	3c0f800b */ 	lui	$t7,%hi(var800aabc0)
/*  f161120:	8defabc0 */ 	lw	$t7,%lo(var800aabc0)($t7)
/*  f161124:	0004c0c0 */ 	sll	$t8,$a0,0x3
/*  f161128:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f16112c:	932e0000 */ 	lbu	$t6,0x0($t9)
/*  f161130:	31cf000f */ 	andi	$t7,$t6,0xf
/*  f161134:	15e00002 */ 	bnez	$t7,.L0f161140
/*  f161138:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16113c:	00006825 */ 	or	$t5,$zero,$zero
.L0f161140:
/*  f161140:	51a00024 */ 	beqzl	$t5,.L0f1611d4
/*  f161144:	27deffff */ 	addiu	$s8,$s8,-1
/*  f161148:	c7b200b0 */ 	lwc1	$f18,0xb0($sp)
/*  f16114c:	46001506 */ 	mov.s	$f20,$f2
/*  f161150:	e6120000 */ 	swc1	$f18,0x0($s0)
/*  f161154:	c7b000b4 */ 	lwc1	$f16,0xb4($sp)
/*  f161158:	e6100004 */ 	swc1	$f16,0x4($s0)
/*  f16115c:	c7a600b8 */ 	lwc1	$f6,0xb8($sp)
/*  f161160:	e6060008 */ 	swc1	$f6,0x8($s0)
/*  f161164:	c7a400a4 */ 	lwc1	$f4,0xa4($sp)
/*  f161168:	e604000c */ 	swc1	$f4,0xc($s0)
/*  f16116c:	c7aa00a8 */ 	lwc1	$f10,0xa8($sp)
/*  f161170:	e60a0010 */ 	swc1	$f10,0x10($s0)
/*  f161174:	c7a800ac */ 	lwc1	$f8,0xac($sp)
/*  f161178:	e6080014 */ 	swc1	$f8,0x14($s0)
/*  f16117c:	8fb800dc */ 	lw	$t8,0xdc($sp)
/*  f161180:	030c0019 */ 	multu	$t8,$t4
/*  f161184:	0000c812 */ 	mflo	$t9
/*  f161188:	032a7021 */ 	addu	$t6,$t9,$t2
/*  f16118c:	ae0e0018 */ 	sw	$t6,0x18($s0)
/*  f161190:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f161194:	01ec0019 */ 	multu	$t7,$t4
/*  f161198:	0000c012 */ 	mflo	$t8
/*  f16119c:	030ac821 */ 	addu	$t9,$t8,$t2
/*  f1611a0:	ae19001c */ 	sw	$t9,0x1c($s0)
/*  f1611a4:	8fae00e4 */ 	lw	$t6,0xe4($sp)
/*  f1611a8:	a604002a */ 	sh	$a0,0x2a($s0)
/*  f1611ac:	ae080024 */ 	sw	$t0,0x24($s0)
/*  f1611b0:	01cc0019 */ 	multu	$t6,$t4
/*  f1611b4:	a6090028 */ 	sh	$t1,0x28($s0)
/*  f1611b8:	00007812 */ 	mflo	$t7
/*  f1611bc:	01eac021 */ 	addu	$t8,$t7,$t2
/*  f1611c0:	ae180020 */ 	sw	$t8,0x20($s0)
/*  f1611c4:	8fb90104 */ 	lw	$t9,0x104($sp)
/*  f1611c8:	972e0002 */ 	lhu	$t6,0x2($t9)
/*  f1611cc:	a60e002c */ 	sh	$t6,0x2c($s0)
.L0f1611d0:
/*  f1611d0:	27deffff */ 	addiu	$s8,$s8,-1
.L0f1611d4:
/*  f1611d4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1611d8:	57c1000d */ 	bnel	$s8,$at,.L0f161210
/*  f1611dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1611e0:	928f0006 */ 	lbu	$t7,0x6($s4)
/*  f1611e4:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f1611e8:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f1611ec:	afb800dc */ 	sw	$t8,0xdc($sp)
/*  f1611f0:	96990006 */ 	lhu	$t9,0x6($s4)
/*  f1611f4:	00197302 */ 	srl	$t6,$t9,0xc
/*  f1611f8:	afae00e0 */ 	sw	$t6,0xe0($sp)
/*  f1611fc:	928f0003 */ 	lbu	$t7,0x3($s4)
/*  f161200:	000fc102 */ 	srl	$t8,$t7,0x4
/*  f161204:	1000001d */ 	beqz	$zero,.L0f16127c
/*  f161208:	afb800e4 */ 	sw	$t8,0xe4($sp)
/*  f16120c:	24010001 */ 	addiu	$at,$zero,0x1
.L0f161210:
/*  f161210:	17c1000e */ 	bne	$s8,$at,.L0f16124c
/*  f161214:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161218:	96990004 */ 	lhu	$t9,0x4($s4)
/*  f16121c:	000b4c00 */ 	sll	$t1,$t3,0x10
/*  f161220:	332e000f */ 	andi	$t6,$t9,0xf
/*  f161224:	afae00dc */ 	sw	$t6,0xdc($sp)
/*  f161228:	928f0005 */ 	lbu	$t7,0x5($s4)
/*  f16122c:	000fc102 */ 	srl	$t8,$t7,0x4
/*  f161230:	afb800e0 */ 	sw	$t8,0xe0($sp)
/*  f161234:	92990002 */ 	lbu	$t9,0x2($s4)
/*  f161238:	00097c03 */ 	sra	$t7,$t1,0x10
/*  f16123c:	01e04825 */ 	or	$t1,$t7,$zero
/*  f161240:	332e000f */ 	andi	$t6,$t9,0xf
/*  f161244:	1000000d */ 	beqz	$zero,.L0f16127c
/*  f161248:	afae00e4 */ 	sw	$t6,0xe4($sp)
.L0f16124c:
/*  f16124c:	17c0000b */ 	bnez	$s8,.L0f16127c
/*  f161250:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161254:	92980004 */ 	lbu	$t8,0x4($s4)
/*  f161258:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f16125c:	3319000f */ 	andi	$t9,$t8,0xf
/*  f161260:	afb900dc */ 	sw	$t9,0xdc($sp)
/*  f161264:	8e8e0004 */ 	lw	$t6,0x4($s4)
/*  f161268:	000e7f02 */ 	srl	$t7,$t6,0x1c
/*  f16126c:	afaf00e0 */ 	sw	$t7,0xe0($sp)
/*  f161270:	96980002 */ 	lhu	$t8,0x2($s4)
/*  f161274:	0018cb02 */ 	srl	$t9,$t8,0xc
/*  f161278:	afb900e4 */ 	sw	$t9,0xe4($sp)
.L0f16127c:
/*  f16127c:	07c3fe8b */ 	bgezl	$s8,.L0f160cac
/*  f161280:	8fb900dc */ 	lw	$t9,0xdc($sp)
/*  f161284:	25080008 */ 	addiu	$t0,$t0,0x8
.L0f161288:
/*  f161288:	81020000 */ 	lb	$v0,0x0($t0)
/*  f16128c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f161290:	10410006 */ 	beq	$v0,$at,.L0f1612ac
/*  f161294:	2401ffb8 */ 	addiu	$at,$zero,-72
/*  f161298:	5441fe3f */ 	bnel	$v0,$at,.L0f160b98
/*  f16129c:	2401ffbf */ 	addiu	$at,$zero,-65
/*  f1612a0:	afbe00f0 */ 	sw	$s8,0xf0($sp)
/*  f1612a4:	afb40078 */ 	sw	$s4,0x78($sp)
/*  f1612a8:	a7a900f4 */ 	sh	$t1,0xf4($sp)
.L0f1612ac:
/*  f1612ac:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f1612b0:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f1612b4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1612b8:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f1612bc:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f1612c0:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f1612c4:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f1612c8:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f1612cc:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f1612d0:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f1612d4:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f1612d8:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
/*  f1612dc:	03e00008 */ 	jr	$ra
/*  f1612e0:	01a01025 */ 	or	$v0,$t5,$zero
);

GLOBAL_ASM(
glabel func0f1612e4
/*  f1612e4:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f1612e8:	afb1000c */ 	sw	$s1,0xc($sp)
/*  f1612ec:	afb00008 */ 	sw	$s0,0x8($sp)
/*  f1612f0:	44801000 */ 	mtc1	$zero,$f2
/*  f1612f4:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f1612f8:	27b00044 */ 	addiu	$s0,$sp,0x44
/*  f1612fc:	24110002 */ 	addiu	$s1,$zero,0x2
/*  f161300:	27ab0048 */ 	addiu	$t3,$sp,0x48
/*  f161304:	27ac0038 */ 	addiu	$t4,$sp,0x38
/*  f161308:	00001025 */ 	or	$v0,$zero,$zero
/*  f16130c:	00c04825 */ 	or	$t1,$a2,$zero
/*  f161310:	00805025 */ 	or	$t2,$a0,$zero
/*  f161314:	240d0001 */ 	addiu	$t5,$zero,0x1
.L0f161318:
/*  f161318:	c5200000 */ 	lwc1	$f0,0x0($t1)
/*  f16131c:	c5440000 */ 	lwc1	$f4,0x0($t2)
/*  f161320:	25290004 */ 	addiu	$t1,$t1,0x4
/*  f161324:	00a24021 */ 	addu	$t0,$a1,$v0
/*  f161328:	4604003c */ 	c.lt.s	$f0,$f4
/*  f16132c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161330:	45020007 */ 	bc1fl	.L0f161350
/*  f161334:	c5080000 */ 	lwc1	$f8,0x0($t0)
/*  f161338:	a16d0000 */ 	sb	$t5,0x0($t3)
/*  f16133c:	c5460000 */ 	lwc1	$f6,0x0($t2)
/*  f161340:	00001825 */ 	or	$v1,$zero,$zero
/*  f161344:	1000000d */ 	beqz	$zero,.L0f16137c
/*  f161348:	e5860000 */ 	swc1	$f6,0x0($t4)
/*  f16134c:	c5080000 */ 	lwc1	$f8,0x0($t0)
.L0f161350:
/*  f161350:	4600403c */ 	c.lt.s	$f8,$f0
/*  f161354:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161358:	45020007 */ 	bc1fl	.L0f161378
/*  f16135c:	a1710000 */ 	sb	$s1,0x0($t3)
/*  f161360:	a1600000 */ 	sb	$zero,0x0($t3)
/*  f161364:	c50a0000 */ 	lwc1	$f10,0x0($t0)
/*  f161368:	00001825 */ 	or	$v1,$zero,$zero
/*  f16136c:	10000003 */ 	beqz	$zero,.L0f16137c
/*  f161370:	e58a0000 */ 	swc1	$f10,0x0($t4)
/*  f161374:	a1710000 */ 	sb	$s1,0x0($t3)
.L0f161378:
/*  f161378:	e5820000 */ 	swc1	$f2,0x0($t4)
.L0f16137c:
/*  f16137c:	258c0004 */ 	addiu	$t4,$t4,0x4
/*  f161380:	0190082b */ 	sltu	$at,$t4,$s0
/*  f161384:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f161388:	254a0004 */ 	addiu	$t2,$t2,0x4
/*  f16138c:	1420ffe2 */ 	bnez	$at,.L0f161318
/*  f161390:	256b0001 */ 	addiu	$t3,$t3,0x1
/*  f161394:	10600003 */ 	beqz	$v1,.L0f1613a4
/*  f161398:	00001025 */ 	or	$v0,$zero,$zero
/*  f16139c:	1000005c */ 	beqz	$zero,.L0f161510
/*  f1613a0:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f1613a4:
/*  f1613a4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1613a8:	27a90038 */ 	addiu	$t1,$sp,0x38
/*  f1613ac:	44810000 */ 	mtc1	$at,$f0
/*  f1613b0:	01206825 */ 	or	$t5,$t1,$zero
/*  f1613b4:	27ab0048 */ 	addiu	$t3,$sp,0x48
/*  f1613b8:	27a3002c */ 	addiu	$v1,$sp,0x2c
/*  f1613bc:	8fa80060 */ 	lw	$t0,0x60($sp)
.L0f1613c0:
/*  f1613c0:	816f0000 */ 	lb	$t7,0x0($t3)
/*  f1613c4:	256b0001 */ 	addiu	$t3,$t3,0x1
/*  f1613c8:	00e2c021 */ 	addu	$t8,$a3,$v0
/*  f1613cc:	522f0011 */ 	beql	$s1,$t7,.L0f161414
/*  f1613d0:	e4600000 */ 	swc1	$f0,0x0($v1)
/*  f1613d4:	c7100000 */ 	lwc1	$f16,0x0($t8)
/*  f1613d8:	01a2c821 */ 	addu	$t9,$t5,$v0
/*  f1613dc:	00c27021 */ 	addu	$t6,$a2,$v0
/*  f1613e0:	46101032 */ 	c.eq.s	$f2,$f16
/*  f1613e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1613e8:	4503000a */ 	bc1tl	.L0f161414
/*  f1613ec:	e4600000 */ 	swc1	$f0,0x0($v1)
/*  f1613f0:	c7320000 */ 	lwc1	$f18,0x0($t9)
/*  f1613f4:	c5c40000 */ 	lwc1	$f4,0x0($t6)
/*  f1613f8:	01027821 */ 	addu	$t7,$t0,$v0
/*  f1613fc:	c5e80000 */ 	lwc1	$f8,0x0($t7)
/*  f161400:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f161404:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f161408:	10000002 */ 	beqz	$zero,.L0f161414
/*  f16140c:	e46a0000 */ 	swc1	$f10,0x0($v1)
/*  f161410:	e4600000 */ 	swc1	$f0,0x0($v1)
.L0f161414:
/*  f161414:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f161418:	0069082b */ 	sltu	$at,$v1,$t1
/*  f16141c:	1420ffe8 */ 	bnez	$at,.L0f1613c0
/*  f161420:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f161424:	27aa002c */ 	addiu	$t2,$sp,0x2c
/*  f161428:	00004825 */ 	or	$t1,$zero,$zero
/*  f16142c:	c5400000 */ 	lwc1	$f0,0x0($t2)
/*  f161430:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f161434:	27a30030 */ 	addiu	$v1,$sp,0x30
.L0f161438:
/*  f161438:	c4700000 */ 	lwc1	$f16,0x0($v1)
/*  f16143c:	0008c880 */ 	sll	$t9,$t0,0x2
/*  f161440:	27ae002c */ 	addiu	$t6,$sp,0x2c
/*  f161444:	4610003c */ 	c.lt.s	$f0,$f16
/*  f161448:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16144c:	45020005 */ 	bc1fl	.L0f161464
/*  f161450:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f161454:	032e5021 */ 	addu	$t2,$t9,$t6
/*  f161458:	c5400000 */ 	lwc1	$f0,0x0($t2)
/*  f16145c:	01004825 */ 	or	$t1,$t0,$zero
/*  f161460:	25080001 */ 	addiu	$t0,$t0,0x1
.L0f161464:
/*  f161464:	29010003 */ 	slti	$at,$t0,0x3
/*  f161468:	1420fff3 */ 	bnez	$at,.L0f161438
/*  f16146c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f161470:	4602003c */ 	c.lt.s	$f0,$f2
/*  f161474:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f161478:	00097880 */ 	sll	$t7,$t1,0x2
/*  f16147c:	00001025 */ 	or	$v0,$zero,$zero
/*  f161480:	45000003 */ 	bc1f	.L0f161490
/*  f161484:	01ec1821 */ 	addu	$v1,$t7,$t4
/*  f161488:	10000021 */ 	beqz	$zero,.L0f161510
/*  f16148c:	00001025 */ 	or	$v0,$zero,$zero
.L0f161490:
/*  f161490:	2408000c */ 	addiu	$t0,$zero,0xc
.L0f161494:
/*  f161494:	106c0018 */ 	beq	$v1,$t4,.L0f1614f8
/*  f161498:	01a2c021 */ 	addu	$t8,$t5,$v0
/*  f16149c:	00e2c021 */ 	addu	$t8,$a3,$v0
/*  f1614a0:	c7120000 */ 	lwc1	$f18,0x0($t8)
/*  f1614a4:	c5440000 */ 	lwc1	$f4,0x0($t2)
/*  f1614a8:	00c2c821 */ 	addu	$t9,$a2,$v0
/*  f1614ac:	c7260000 */ 	lwc1	$f6,0x0($t9)
/*  f1614b0:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f1614b4:	00827021 */ 	addu	$t6,$a0,$v0
/*  f1614b8:	00a27821 */ 	addu	$t7,$a1,$v0
/*  f1614bc:	46064280 */ 	add.s	$f10,$f8,$f6
/*  f1614c0:	e58a0000 */ 	swc1	$f10,0x0($t4)
/*  f1614c4:	c5d00000 */ 	lwc1	$f16,0x0($t6)
/*  f1614c8:	c5800000 */ 	lwc1	$f0,0x0($t4)
/*  f1614cc:	4610003c */ 	c.lt.s	$f0,$f16
/*  f1614d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1614d4:	45010006 */ 	bc1t	.L0f1614f0
/*  f1614d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1614dc:	c5f20000 */ 	lwc1	$f18,0x0($t7)
/*  f1614e0:	4600903c */ 	c.lt.s	$f18,$f0
/*  f1614e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1614e8:	45020006 */ 	bc1fl	.L0f161504
/*  f1614ec:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f1614f0:
/*  f1614f0:	10000007 */ 	beqz	$zero,.L0f161510
/*  f1614f4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1614f8:
/*  f1614f8:	c7040000 */ 	lwc1	$f4,0x0($t8)
/*  f1614fc:	e5840000 */ 	swc1	$f4,0x0($t4)
/*  f161500:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f161504:
/*  f161504:	1448ffe3 */ 	bne	$v0,$t0,.L0f161494
/*  f161508:	258c0004 */ 	addiu	$t4,$t4,0x4
/*  f16150c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f161510:
/*  f161510:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f161514:	8fb1000c */ 	lw	$s1,0xc($sp)
/*  f161518:	03e00008 */ 	jr	$ra
/*  f16151c:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel func0f161520
/*  f161520:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f161524:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f161528:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f16152c:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f161530:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f161534:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f161538:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f16153c:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f161540:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f161544:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f161548:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f16154c:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f161550:	afa600f0 */ 	sw	$a2,0xf0($sp)
/*  f161554:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f161558:	3c013f80 */ 	lui	$at,0x3f80
/*  f16155c:	44810000 */ 	mtc1	$at,$f0
/*  f161560:	e7a400b8 */ 	swc1	$f4,0xb8($sp)
/*  f161564:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f161568:	00e09025 */ 	or	$s2,$a3,$zero
/*  f16156c:	00009825 */ 	or	$s3,$zero,$zero
/*  f161570:	e7a600bc */ 	swc1	$f6,0xbc($sp)
/*  f161574:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f161578:	c7a600b8 */ 	lwc1	$f6,0xb8($sp)
/*  f16157c:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x2bc)
/*  f161580:	e7a800c0 */ 	swc1	$f8,0xc0($sp)
/*  f161584:	c4aa0000 */ 	lwc1	$f10,0x0($a1)
/*  f161588:	e7aa00ac */ 	swc1	$f10,0xac($sp)
/*  f16158c:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f161590:	c7a400ac */ 	lwc1	$f4,0xac($sp)
/*  f161594:	e7b000b0 */ 	swc1	$f16,0xb0($sp)
/*  f161598:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*  f16159c:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f1615a0:	c7aa00b0 */ 	lwc1	$f10,0xb0($sp)
/*  f1615a4:	c7b000bc */ 	lwc1	$f16,0xbc($sp)
/*  f1615a8:	e7b200b4 */ 	swc1	$f18,0xb4($sp)
/*  f1615ac:	c7a400b4 */ 	lwc1	$f4,0xb4($sp)
/*  f1615b0:	c7a600c0 */ 	lwc1	$f6,0xc0($sp)
/*  f1615b4:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f1615b8:	e7a800a0 */ 	swc1	$f8,0xa0($sp)
/*  f1615bc:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f1615c0:	e7b200a4 */ 	swc1	$f18,0xa4($sp)
/*  f1615c4:	46080403 */ 	div.s	$f16,$f0,$f8
/*  f1615c8:	e7aa00a8 */ 	swc1	$f10,0xa8($sp)
/*  f1615cc:	46120103 */ 	div.s	$f4,$f0,$f18
/*  f1615d0:	e7b00094 */ 	swc1	$f16,0x94($sp)
/*  f1615d4:	460a0183 */ 	div.s	$f6,$f0,$f10
/*  f1615d8:	e7a40098 */ 	swc1	$f4,0x98($sp)
/*  f1615dc:	04c00007 */ 	bltz	$a2,.L0f1615fc
/*  f1615e0:	e7a6009c */ 	swc1	$f6,0x9c($sp)
/*  f1615e4:	8defa27c */ 	lw	$t7,%lo(g_Vars+0x2bc)($t7)
/*  f1615e8:	8fb500f0 */ 	lw	$s5,0xf0($sp)
/*  f1615ec:	3c16800a */ 	lui	$s6,%hi(g_RoomPtrs)
/*  f1615f0:	00cf082a */ 	slt	$at,$a2,$t7
/*  f1615f4:	14200003 */ 	bnez	$at,.L0f161604
/*  f1615f8:	0015c0c0 */ 	sll	$t8,$s5,0x3
.L0f1615fc:
/*  f1615fc:	10000120 */ 	beqz	$zero,.L0f161a80
/*  f161600:	00001025 */ 	or	$v0,$zero,$zero
.L0f161604:
/*  f161604:	26d64928 */ 	addiu	$s6,$s6,%lo(g_RoomPtrs)
/*  f161608:	0315c021 */ 	addu	$t8,$t8,$s5
/*  f16160c:	8ed90000 */ 	lw	$t9,0x0($s6)
/*  f161610:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f161614:	0315c023 */ 	subu	$t8,$t8,$s5
/*  f161618:	0018a880 */ 	sll	$s5,$t8,0x2
/*  f16161c:	03351821 */ 	addu	$v1,$t9,$s5
/*  f161620:	8c620044 */ 	lw	$v0,0x44($v1)
/*  f161624:	54400004 */ 	bnezl	$v0,.L0f161638
/*  f161628:	8c680040 */ 	lw	$t0,0x40($v1)
/*  f16162c:	10000114 */ 	beqz	$zero,.L0f161a80
/*  f161630:	00001025 */ 	or	$v0,$zero,$zero
/*  f161634:	8c680040 */ 	lw	$t0,0x40($v1)
.L0f161638:
/*  f161638:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f16163c:	27be00a0 */ 	addiu	$s8,$sp,0xa0
/*  f161640:	1900008f */ 	blez	$t0,.L0f161880
/*  f161644:	27b700b8 */ 	addiu	$s7,$sp,0xb8
/*  f161648:	3c14800a */ 	lui	$s4,%hi(var800a65b8)
/*  f16164c:	3c11800a */ 	lui	$s1,%hi(var800a6538)
/*  f161650:	26316538 */ 	addiu	$s1,$s1,%lo(var800a6538)
/*  f161654:	269465b8 */ 	addiu	$s4,$s4,%lo(var800a65b8)
/*  f161658:	afa20090 */ 	sw	$v0,0x90($sp)
/*  f16165c:	afa800d4 */ 	sw	$t0,0xd4($sp)
.L0f161660:
/*  f161660:	8fa20090 */ 	lw	$v0,0x90($sp)
/*  f161664:	27a90094 */ 	addiu	$t1,$sp,0x94
/*  f161668:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f16166c:	02e03025 */ 	or	$a2,$s7,$zero
/*  f161670:	03c03825 */ 	or	$a3,$s8,$zero
/*  f161674:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f161678:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f16167c:	0fc584b9 */ 	jal	func0f1612e4
/*  f161680:	24450014 */ 	addiu	$a1,$v0,0x14
/*  f161684:	10400076 */ 	beqz	$v0,.L0f161860
/*  f161688:	24010001 */ 	addiu	$at,$zero,0x1
/*  f16168c:	1441000f */ 	bne	$v0,$at,.L0f1616cc
/*  f161690:	c7a800b8 */ 	lwc1	$f8,0xb8($sp)
/*  f161694:	c6500000 */ 	lwc1	$f16,0x0($s2)
/*  f161698:	c7b200bc */ 	lwc1	$f18,0xbc($sp)
/*  f16169c:	c6440004 */ 	lwc1	$f4,0x4($s2)
/*  f1616a0:	46104001 */ 	sub.s	$f0,$f8,$f16
/*  f1616a4:	c6480008 */ 	lwc1	$f8,0x8($s2)
/*  f1616a8:	c7a600c0 */ 	lwc1	$f6,0xc0($sp)
/*  f1616ac:	46000502 */ 	mul.s	$f20,$f0,$f0
/*  f1616b0:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f1616b4:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f1616b8:	46083001 */ 	sub.s	$f0,$f6,$f8
/*  f1616bc:	46000402 */ 	mul.s	$f16,$f0,$f0
/*  f1616c0:	460aa500 */ 	add.s	$f20,$f20,$f10
/*  f1616c4:	10000004 */ 	beqz	$zero,.L0f1616d8
/*  f1616c8:	4610a500 */ 	add.s	$f20,$f20,$f16
.L0f1616cc:
/*  f1616cc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f1616d0:	4481a000 */ 	mtc1	$at,$f20
/*  f1616d4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1616d8:
/*  f1616d8:	2a610010 */ 	slti	$at,$s3,0x10
/*  f1616dc:	10200019 */ 	beqz	$at,.L0f161744
/*  f1616e0:	3c10800a */ 	lui	$s0,%hi(g_MenuStack+0x2000)
/*  f1616e4:	8fa400e4 */ 	lw	$a0,0xe4($sp)
/*  f1616e8:	1a600010 */ 	blez	$s3,.L0f16172c
/*  f1616ec:	00001825 */ 	or	$v1,$zero,$zero
/*  f1616f0:	3c10800a */ 	lui	$s0,%hi(var800a6538)
/*  f1616f4:	26106538 */ 	addiu	$s0,$s0,%lo(var800a6538)
.L0f1616f8:
/*  f1616f8:	c6020004 */ 	lwc1	$f2,0x4($s0)
/*  f1616fc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f161700:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f161704:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161708:	45000006 */ 	bc1f	.L0f161724
/*  f16170c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161710:	8e020000 */ 	lw	$v0,%lo(g_MenuStack+0x2000)($s0)
/*  f161714:	ae040000 */ 	sw	$a0,0x0($s0)
/*  f161718:	e6140004 */ 	swc1	$f20,0x4($s0)
/*  f16171c:	46001506 */ 	mov.s	$f20,$f2
/*  f161720:	00402025 */ 	or	$a0,$v0,$zero
.L0f161724:
/*  f161724:	1473fff4 */ 	bne	$v1,$s3,.L0f1616f8
/*  f161728:	26100008 */ 	addiu	$s0,$s0,8
.L0f16172c:
/*  f16172c:	000350c0 */ 	sll	$t2,$v1,0x3
/*  f161730:	022a8021 */ 	addu	$s0,$s1,$t2
/*  f161734:	ae040000 */ 	sw	$a0,0x0($s0)
/*  f161738:	e6140004 */ 	swc1	$f20,0x4($s0)
/*  f16173c:	10000048 */ 	beqz	$zero,.L0f161860
/*  f161740:	26730001 */ 	addiu	$s3,$s3,0x1
.L0f161744:
/*  f161744:	00009825 */ 	or	$s3,$zero,$zero
/*  f161748:	26106538 */ 	addiu	$s0,$s0,0x6538
/*  f16174c:	8ecd0000 */ 	lw	$t5,0x0($s6)
.L0f161750:
/*  f161750:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f161754:	8fb800f0 */ 	lw	$t8,0xf0($sp)
/*  f161758:	01b57021 */ 	addu	$t6,$t5,$s5
/*  f16175c:	8dcf0044 */ 	lw	$t7,0x44($t6)
/*  f161760:	000b6140 */ 	sll	$t4,$t3,0x5
/*  f161764:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f161768:	02e02025 */ 	or	$a0,$s7,$zero
/*  f16176c:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f161770:	03c03025 */ 	or	$a2,$s8,$zero
/*  f161774:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f161778:	0fc5828e */ 	jal	func0f160a38
/*  f16177c:	018f3821 */ 	addu	$a3,$t4,$t7
/*  f161780:	1040001d */ 	beqz	$v0,.L0f1617f8
/*  f161784:	c7b200b8 */ 	lwc1	$f18,0xb8($sp)
/*  f161788:	c6440000 */ 	lwc1	$f4,0x0($s2)
/*  f16178c:	c7aa00bc */ 	lwc1	$f10,0xbc($sp)
/*  f161790:	c6460004 */ 	lwc1	$f6,0x4($s2)
/*  f161794:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f161798:	c6520008 */ 	lwc1	$f18,0x8($s2)
/*  f16179c:	c7b000c0 */ 	lwc1	$f16,0xc0($sp)
/*  f1617a0:	46000082 */ 	mul.s	$f2,$f0,$f0
/*  f1617a4:	46065001 */ 	sub.s	$f0,$f10,$f6
/*  f1617a8:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f1617ac:	46128001 */ 	sub.s	$f0,$f16,$f18
/*  f1617b0:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f1617b4:	46081080 */ 	add.s	$f2,$f2,$f8
/*  f1617b8:	16600006 */ 	bnez	$s3,.L0f1617d4
/*  f1617bc:	46041080 */ 	add.s	$f2,$f2,$f4
/*  f1617c0:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f1617c4:	e6220004 */ 	swc1	$f2,0x4($s1)
/*  f1617c8:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f1617cc:	1000000a */ 	beqz	$zero,.L0f1617f8
/*  f1617d0:	ae390000 */ 	sw	$t9,0x0($s1)
.L0f1617d4:
/*  f1617d4:	c62a0004 */ 	lwc1	$f10,0x4($s1)
/*  f1617d8:	460a103c */ 	c.lt.s	$f2,$f10
/*  f1617dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1617e0:	45020006 */ 	bc1fl	.L0f1617fc
/*  f1617e4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1617e8:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f1617ec:	e6220004 */ 	swc1	$f2,0x4($s1)
/*  f1617f0:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f1617f4:	ae290000 */ 	sw	$t1,0x0($s1)
.L0f1617f8:
/*  f1617f8:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f1617fc:
/*  f1617fc:	5614ffd4 */ 	bnel	$s0,$s4,.L0f161750
/*  f161800:	8ecd0000 */ 	lw	$t5,0x0($s6)
/*  f161804:	12600013 */ 	beqz	$s3,.L0f161854
/*  f161808:	8fae00e4 */ 	lw	$t6,0xe4($sp)
/*  f16180c:	c6200004 */ 	lwc1	$f0,0x4($s1)
/*  f161810:	8fad00e4 */ 	lw	$t5,0xe4($sp)
/*  f161814:	24130002 */ 	addiu	$s3,$zero,0x2
/*  f161818:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f16181c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161820:	45020009 */ 	bc1fl	.L0f161848
/*  f161824:	ae2d0008 */ 	sw	$t5,0x8($s1)
/*  f161828:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*  f16182c:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f161830:	e620000c */ 	swc1	$f0,0xc($s1)
/*  f161834:	e6340004 */ 	swc1	$f20,0x4($s1)
/*  f161838:	ae2a0008 */ 	sw	$t2,0x8($s1)
/*  f16183c:	10000008 */ 	beqz	$zero,.L0f161860
/*  f161840:	ae2b0000 */ 	sw	$t3,0x0($s1)
/*  f161844:	ae2d0008 */ 	sw	$t5,0x8($s1)
.L0f161848:
/*  f161848:	e634000c */ 	swc1	$f20,0xc($s1)
/*  f16184c:	10000004 */ 	beqz	$zero,.L0f161860
/*  f161850:	24130002 */ 	addiu	$s3,$zero,0x2
.L0f161854:
/*  f161854:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f161858:	e6340004 */ 	swc1	$f20,0x4($s1)
/*  f16185c:	24130001 */ 	addiu	$s3,$zero,0x1
.L0f161860:
/*  f161860:	8fa200e4 */ 	lw	$v0,0xe4($sp)
/*  f161864:	8fac0090 */ 	lw	$t4,0x90($sp)
/*  f161868:	8fb800d4 */ 	lw	$t8,0xd4($sp)
/*  f16186c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f161870:	258f0020 */ 	addiu	$t7,$t4,0x20
/*  f161874:	afaf0090 */ 	sw	$t7,0x90($sp)
/*  f161878:	1458ff79 */ 	bne	$v0,$t8,.L0f161660
/*  f16187c:	afa200e4 */ 	sw	$v0,0xe4($sp)
.L0f161880:
/*  f161880:	27b700b8 */ 	addiu	$s7,$sp,0xb8
/*  f161884:	16600003 */ 	bnez	$s3,.L0f161894
/*  f161888:	27be00a0 */ 	addiu	$s8,$sp,0xa0
/*  f16188c:	1000007c */ 	beqz	$zero,.L0f161a80
/*  f161890:	00001025 */ 	or	$v0,$zero,$zero
.L0f161894:
/*  f161894:	8ed90000 */ 	lw	$t9,0x0($s6)
/*  f161898:	3c10800a */ 	lui	$s0,%hi(var800a6538)
/*  f16189c:	26106538 */ 	addiu	$s0,$s0,%lo(var800a6538)
/*  f1618a0:	03354821 */ 	addu	$t1,$t9,$s5
/*  f1618a4:	8d230044 */ 	lw	$v1,0x44($t1)
/*  f1618a8:	1a600074 */ 	blez	$s3,.L0f161a7c
/*  f1618ac:	afa000e4 */ 	sw	$zero,0xe4($sp)
/*  f1618b0:	afa30090 */ 	sw	$v1,0x90($sp)
.L0f1618b4:
/*  f1618b4:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f1618b8:	8fa200f0 */ 	lw	$v0,0xf0($sp)
/*  f1618bc:	8fa30090 */ 	lw	$v1,0x90($sp)
/*  f1618c0:	000a5940 */ 	sll	$t3,$t2,0x5
/*  f1618c4:	02e02025 */ 	or	$a0,$s7,$zero
/*  f1618c8:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f1618cc:	03c03025 */ 	or	$a2,$s8,$zero
/*  f1618d0:	afb20014 */ 	sw	$s2,0x14($sp)
/*  f1618d4:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f1618d8:	0fc5828e */ 	jal	func0f160a38
/*  f1618dc:	01633821 */ 	addu	$a3,$t3,$v1
/*  f1618e0:	50400061 */ 	beqzl	$v0,.L0f161a68
/*  f1618e4:	8fa200e4 */ 	lw	$v0,0xe4($sp)
/*  f1618e8:	8fa200e4 */ 	lw	$v0,0xe4($sp)
/*  f1618ec:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1618f0:	c7a600b8 */ 	lwc1	$f6,0xb8($sp)
/*  f1618f4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1618f8:	0053082a */ 	slt	$at,$v0,$s3
/*  f1618fc:	10200057 */ 	beqz	$at,.L0f161a5c
/*  f161900:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161904:	c6480000 */ 	lwc1	$f8,0x0($s2)
/*  f161908:	c7b000bc */ 	lwc1	$f16,0xbc($sp)
/*  f16190c:	c6520004 */ 	lwc1	$f18,0x4($s2)
/*  f161910:	46083001 */ 	sub.s	$f0,$f6,$f8
/*  f161914:	c6460008 */ 	lwc1	$f6,0x8($s2)
/*  f161918:	c7aa00c0 */ 	lwc1	$f10,0xc0($sp)
/*  f16191c:	3c0e800a */ 	lui	$t6,%hi(var800a6538)
/*  f161920:	46000082 */ 	mul.s	$f2,$f0,$f0
/*  f161924:	46128001 */ 	sub.s	$f0,$f16,$f18
/*  f161928:	25ce6538 */ 	addiu	$t6,$t6,%lo(var800a6538)
/*  f16192c:	0053082a */ 	slt	$at,$v0,$s3
/*  f161930:	001368c0 */ 	sll	$t5,$s3,0x3
/*  f161934:	46000102 */ 	mul.s	$f4,$f0,$f0
/*  f161938:	46065001 */ 	sub.s	$f0,$f10,$f6
/*  f16193c:	01ae8821 */ 	addu	$s1,$t5,$t6
/*  f161940:	27b40060 */ 	addiu	$s4,$sp,0x60
/*  f161944:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f161948:	46041080 */ 	add.s	$f2,$f2,$f4
/*  f16194c:	10200043 */ 	beqz	$at,.L0f161a5c
/*  f161950:	46081080 */ 	add.s	$f2,$f2,$f8
/*  f161954:	c6100004 */ 	lwc1	$f16,0x4($s0)
.L0f161958:
/*  f161958:	02e02025 */ 	or	$a0,$s7,$zero
/*  f16195c:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f161960:	4602803e */ 	c.le.s	$f16,$f2
/*  f161964:	03c03025 */ 	or	$a2,$s8,$zero
/*  f161968:	8fb80090 */ 	lw	$t8,0x90($sp)
/*  f16196c:	8fb900f0 */ 	lw	$t9,0xf0($sp)
/*  f161970:	45020037 */ 	bc1fl	.L0f161a50
/*  f161974:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f161978:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f16197c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f161980:	afb40014 */ 	sw	$s4,0x14($sp)
/*  f161984:	000c7940 */ 	sll	$t7,$t4,0x5
/*  f161988:	01f83821 */ 	addu	$a3,$t7,$t8
/*  f16198c:	0fc5828e */ 	jal	func0f160a38
/*  f161990:	e7a200c8 */ 	swc1	$f2,0xc8($sp)
/*  f161994:	1040002d */ 	beqz	$v0,.L0f161a4c
/*  f161998:	c7a200c8 */ 	lwc1	$f2,0xc8($sp)
/*  f16199c:	c7b200b8 */ 	lwc1	$f18,0xb8($sp)
/*  f1619a0:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*  f1619a4:	c7aa00bc */ 	lwc1	$f10,0xbc($sp)
/*  f1619a8:	c7a60064 */ 	lwc1	$f6,0x64($sp)
/*  f1619ac:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f1619b0:	c7b20068 */ 	lwc1	$f18,0x68($sp)
/*  f1619b4:	c7b000c0 */ 	lwc1	$f16,0xc0($sp)
/*  f1619b8:	46000502 */ 	mul.s	$f20,$f0,$f0
/*  f1619bc:	46065001 */ 	sub.s	$f0,$f10,$f6
/*  f1619c0:	46000202 */ 	mul.s	$f8,$f0,$f0
/*  f1619c4:	46128001 */ 	sub.s	$f0,$f16,$f18
/*  f1619c8:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f1619cc:	4608a500 */ 	add.s	$f20,$f20,$f8
/*  f1619d0:	460aa500 */ 	add.s	$f20,$f20,$f10
/*  f1619d4:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f1619d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1619dc:	4502001c */ 	bc1fl	.L0f161a50
/*  f1619e0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1619e4:	e6440000 */ 	swc1	$f4,0x0($s2)
/*  f1619e8:	c7a60064 */ 	lwc1	$f6,0x64($sp)
/*  f1619ec:	4600a086 */ 	mov.s	$f2,$f20
/*  f1619f0:	e6460004 */ 	swc1	$f6,0x4($s2)
/*  f1619f4:	c7a80068 */ 	lwc1	$f8,0x68($sp)
/*  f1619f8:	e6480008 */ 	swc1	$f8,0x8($s2)
/*  f1619fc:	c7b0006c */ 	lwc1	$f16,0x6c($sp)
/*  f161a00:	e650000c */ 	swc1	$f16,0xc($s2)
/*  f161a04:	c7b20070 */ 	lwc1	$f18,0x70($sp)
/*  f161a08:	e6520010 */ 	swc1	$f18,0x10($s2)
/*  f161a0c:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f161a10:	e64a0014 */ 	swc1	$f10,0x14($s2)
/*  f161a14:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f161a18:	ae490018 */ 	sw	$t1,0x18($s2)
/*  f161a1c:	8faa007c */ 	lw	$t2,0x7c($sp)
/*  f161a20:	ae4a001c */ 	sw	$t2,0x1c($s2)
/*  f161a24:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f161a28:	ae4b0020 */ 	sw	$t3,0x20($s2)
/*  f161a2c:	87ad008a */ 	lh	$t5,0x8a($sp)
/*  f161a30:	a64d002a */ 	sh	$t5,0x2a($s2)
/*  f161a34:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f161a38:	ae4e0024 */ 	sw	$t6,0x24($s2)
/*  f161a3c:	87ac0088 */ 	lh	$t4,0x88($sp)
/*  f161a40:	a64c0028 */ 	sh	$t4,0x28($s2)
/*  f161a44:	87af008c */ 	lh	$t7,0x8c($sp)
/*  f161a48:	a64f002c */ 	sh	$t7,0x2c($s2)
.L0f161a4c:
/*  f161a4c:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f161a50:
/*  f161a50:	0211082b */ 	sltu	$at,$s0,$s1
/*  f161a54:	5420ffc0 */ 	bnezl	$at,.L0f161958
/*  f161a58:	c6100004 */ 	lwc1	$f16,0x4($s0)
.L0f161a5c:
/*  f161a5c:	10000008 */ 	beqz	$zero,.L0f161a80
/*  f161a60:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f161a64:	8fa200e4 */ 	lw	$v0,0xe4($sp)
.L0f161a68:
/*  f161a68:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f161a6c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f161a70:	0053082a */ 	slt	$at,$v0,$s3
/*  f161a74:	1420ff8f */ 	bnez	$at,.L0f1618b4
/*  f161a78:	afa200e4 */ 	sw	$v0,0xe4($sp)
.L0f161a7c:
/*  f161a7c:	00001025 */ 	or	$v0,$zero,$zero
.L0f161a80:
/*  f161a80:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f161a84:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f161a88:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f161a8c:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f161a90:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f161a94:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f161a98:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f161a9c:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f161aa0:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f161aa4:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f161aa8:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f161aac:	03e00008 */ 	jr	$ra
/*  f161ab0:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
);

GLOBAL_ASM(
glabel func0f161ab4
/*  f161ab4:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f161ab8:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f161abc:	3c0e800a */ 	lui	$t6,%hi(g_RoomPtrs)
/*  f161ac0:	8dce4928 */ 	lw	$t6,%lo(g_RoomPtrs)($t6)
/*  f161ac4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f161ac8:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f161acc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f161ad0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f161ad4:	03e00008 */ 	jr	$ra
/*  f161ad8:	87020002 */ 	lh	$v0,0x2($t8)
);

GLOBAL_ASM(
glabel func0f161adc
/*  f161adc:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*  f161ae0:	afa50014 */ 	sw	$a1,0x14($sp)
/*  f161ae4:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f161ae8:	00057400 */ 	sll	$t6,$a1,0x10
/*  f161aec:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f161af0:	e7a40004 */ 	swc1	$f4,0x4($sp)
/*  f161af4:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f161af8:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f161afc:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f161b00:	3c18800a */ 	lui	$t8,%hi(g_RoomPtrs)
/*  f161b04:	e7a60008 */ 	swc1	$f6,0x8($sp)
/*  f161b08:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f161b0c:	8f184928 */ 	lw	$t8,%lo(g_RoomPtrs)($t8)
/*  f161b10:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f161b14:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f161b18:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f161b1c:	e7a8000c */ 	swc1	$f8,0xc($sp)
/*  f161b20:	03191821 */ 	addu	$v1,$t8,$t9
/*  f161b24:	c4700018 */ 	lwc1	$f16,0x18($v1)
/*  f161b28:	c7aa0004 */ 	lwc1	$f10,0x4($sp)
/*  f161b2c:	00001025 */ 	or	$v0,$zero,$zero
/*  f161b30:	460a803e */ 	c.le.s	$f16,$f10
/*  f161b34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161b38:	45000002 */ 	bc1f	.L0f161b44
/*  f161b3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161b40:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f161b44:
/*  f161b44:	1040002e */ 	beqz	$v0,.L0f161c00
/*  f161b48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161b4c:	c4720024 */ 	lwc1	$f18,0x24($v1)
/*  f161b50:	00001025 */ 	or	$v0,$zero,$zero
/*  f161b54:	c7a4000c */ 	lwc1	$f4,0xc($sp)
/*  f161b58:	4612503e */ 	c.le.s	$f10,$f18
/*  f161b5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161b60:	45000002 */ 	bc1f	.L0f161b6c
/*  f161b64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161b68:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f161b6c:
/*  f161b6c:	10400024 */ 	beqz	$v0,.L0f161c00
/*  f161b70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161b74:	c4660020 */ 	lwc1	$f6,0x20($v1)
/*  f161b78:	00001025 */ 	or	$v0,$zero,$zero
/*  f161b7c:	4604303e */ 	c.le.s	$f6,$f4
/*  f161b80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161b84:	45000002 */ 	bc1f	.L0f161b90
/*  f161b88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161b8c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f161b90:
/*  f161b90:	1040001b */ 	beqz	$v0,.L0f161c00
/*  f161b94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161b98:	c468002c */ 	lwc1	$f8,0x2c($v1)
/*  f161b9c:	00001025 */ 	or	$v0,$zero,$zero
/*  f161ba0:	c7b00008 */ 	lwc1	$f16,0x8($sp)
/*  f161ba4:	4608203e */ 	c.le.s	$f4,$f8
/*  f161ba8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161bac:	45000002 */ 	bc1f	.L0f161bb8
/*  f161bb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161bb4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f161bb8:
/*  f161bb8:	10400011 */ 	beqz	$v0,.L0f161c00
/*  f161bbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161bc0:	c472001c */ 	lwc1	$f18,0x1c($v1)
/*  f161bc4:	00001025 */ 	or	$v0,$zero,$zero
/*  f161bc8:	4610903e */ 	c.le.s	$f18,$f16
/*  f161bcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161bd0:	45000002 */ 	bc1f	.L0f161bdc
/*  f161bd4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161bd8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f161bdc:
/*  f161bdc:	10400008 */ 	beqz	$v0,.L0f161c00
/*  f161be0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161be4:	c46a0028 */ 	lwc1	$f10,0x28($v1)
/*  f161be8:	00001025 */ 	or	$v0,$zero,$zero
/*  f161bec:	460a803e */ 	c.le.s	$f16,$f10
/*  f161bf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161bf4:	45000002 */ 	bc1f	.L0f161c00
/*  f161bf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161bfc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f161c00:
/*  f161c00:	03e00008 */ 	jr	$ra
/*  f161c04:	27bd0010 */ 	addiu	$sp,$sp,0x10
);

GLOBAL_ASM(
glabel func0f161c08
/*  f161c08:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f161c0c:	00057400 */ 	sll	$t6,$a1,0x10
/*  f161c10:	000e2c03 */ 	sra	$a1,$t6,0x10
/*  f161c14:	0005c8c0 */ 	sll	$t9,$a1,0x3
/*  f161c18:	0325c821 */ 	addu	$t9,$t9,$a1
/*  f161c1c:	3c18800a */ 	lui	$t8,%hi(g_RoomPtrs)
/*  f161c20:	8f184928 */ 	lw	$t8,%lo(g_RoomPtrs)($t8)
/*  f161c24:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f161c28:	0325c823 */ 	subu	$t9,$t9,$a1
/*  f161c2c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f161c30:	03191821 */ 	addu	$v1,$t8,$t9
/*  f161c34:	80660005 */ 	lb	$a2,0x5($v1)
/*  f161c38:	00803825 */ 	or	$a3,$a0,$zero
/*  f161c3c:	00001025 */ 	or	$v0,$zero,$zero
/*  f161c40:	18c00038 */ 	blez	$a2,.L0f161d24
/*  f161c44:	3c0b800a */ 	lui	$t3,%hi(var800a4ce0)
/*  f161c48:	846c000e */ 	lh	$t4,0xe($v1)
/*  f161c4c:	8d6b4ce0 */ 	lw	$t3,%lo(var800a4ce0)($t3)
/*  f161c50:	3c08800a */ 	lui	$t0,%hi(var800a4ccc)
/*  f161c54:	3c0a800a */ 	lui	$t2,%hi(g_PortalSomethings)
/*  f161c58:	000c6840 */ 	sll	$t5,$t4,0x1
/*  f161c5c:	254a4cc8 */ 	addiu	$t2,$t2,%lo(g_PortalSomethings)
/*  f161c60:	8d084ccc */ 	lw	$t0,%lo(var800a4ccc)($t0)
/*  f161c64:	c4e20008 */ 	lwc1	$f2,0x8($a3)
/*  f161c68:	c4ec0000 */ 	lwc1	$f12,0x0($a3)
/*  f161c6c:	c4ee0004 */ 	lwc1	$f14,0x4($a3)
/*  f161c70:	24090014 */ 	addiu	$t1,$zero,0x14
/*  f161c74:	016d2021 */ 	addu	$a0,$t3,$t5
.L0f161c78:
/*  f161c78:	84830000 */ 	lh	$v1,0x0($a0)
/*  f161c7c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f161c80:	0046082a */ 	slt	$at,$v0,$a2
/*  f161c84:	00690019 */ 	multu	$v1,$t1
/*  f161c88:	00007012 */ 	mflo	$t6
/*  f161c8c:	01c83821 */ 	addu	$a3,$t6,$t0
/*  f161c90:	c4e40000 */ 	lwc1	$f4,0x0($a3)
/*  f161c94:	c4e80004 */ 	lwc1	$f8,0x4($a3)
/*  f161c98:	c4f20008 */ 	lwc1	$f18,0x8($a3)
/*  f161c9c:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f161ca0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161ca4:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f161ca8:	c4e8000c */ 	lwc1	$f8,0xc($a3)
/*  f161cac:	46121102 */ 	mul.s	$f4,$f2,$f18
/*  f161cb0:	460a3400 */ 	add.s	$f16,$f6,$f10
/*  f161cb4:	46102000 */ 	add.s	$f0,$f4,$f16
/*  f161cb8:	4608003c */ 	c.lt.s	$f0,$f8
/*  f161cbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161cc0:	45000009 */ 	bc1f	.L0f161ce8
/*  f161cc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161cc8:	8d4f0000 */ 	lw	$t7,0x0($t2)
/*  f161ccc:	0003c0c0 */ 	sll	$t8,$v1,0x3
/*  f161cd0:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f161cd4:	872c0002 */ 	lh	$t4,0x2($t9)
/*  f161cd8:	10ac0010 */ 	beq	$a1,$t4,.L0f161d1c
/*  f161cdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161ce0:	03e00008 */ 	jr	$ra
/*  f161ce4:	00001025 */ 	or	$v0,$zero,$zero
.L0f161ce8:
/*  f161ce8:	c4e60010 */ 	lwc1	$f6,0x10($a3)
/*  f161cec:	4600303c */ 	c.lt.s	$f6,$f0
/*  f161cf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161cf4:	45000009 */ 	bc1f	.L0f161d1c
/*  f161cf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161cfc:	8d4b0000 */ 	lw	$t3,0x0($t2)
/*  f161d00:	000368c0 */ 	sll	$t5,$v1,0x3
/*  f161d04:	016d7021 */ 	addu	$t6,$t3,$t5
/*  f161d08:	85cf0004 */ 	lh	$t7,0x4($t6)
/*  f161d0c:	10af0003 */ 	beq	$a1,$t7,.L0f161d1c
/*  f161d10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161d14:	03e00008 */ 	jr	$ra
/*  f161d18:	00001025 */ 	or	$v0,$zero,$zero
.L0f161d1c:
/*  f161d1c:	1420ffd6 */ 	bnez	$at,.L0f161c78
/*  f161d20:	24840002 */ 	addiu	$a0,$a0,0x2
.L0f161d24:
/*  f161d24:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f161d28:	03e00008 */ 	jr	$ra
/*  f161d2c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f161d30
/*  f161d30:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f161d34:	00053c00 */ 	sll	$a3,$a1,0x10
/*  f161d38:	00077c03 */ 	sra	$t7,$a3,0x10
/*  f161d3c:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f161d40:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f161d44:	3c18800a */ 	lui	$t8,%hi(g_RoomPtrs)
/*  f161d48:	8f184928 */ 	lw	$t8,%lo(g_RoomPtrs)($t8)
/*  f161d4c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f161d50:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f161d54:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f161d58:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f161d5c:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f161d60:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f161d64:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f161d68:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f161d6c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f161d70:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f161d74:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f161d78:	f7b60010 */ 	sdc1	$f22,0x10($sp)
/*  f161d7c:	f7b40008 */ 	sdc1	$f20,0x8($sp)
/*  f161d80:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f161d84:	03193021 */ 	addu	$a2,$t8,$t9
/*  f161d88:	c4c60030 */ 	lwc1	$f6,0x30($a2)
/*  f161d8c:	01e03825 */ 	or	$a3,$t7,$zero
/*  f161d90:	00002825 */ 	or	$a1,$zero,$zero
/*  f161d94:	e7a60074 */ 	swc1	$f6,0x74($sp)
/*  f161d98:	c4c80034 */ 	lwc1	$f8,0x34($a2)
/*  f161d9c:	3c09800a */ 	lui	$t1,%hi(var800a4ce0)
/*  f161da0:	3c08800a */ 	lui	$t0,%hi(g_PortalSomethings)
/*  f161da4:	e7a80078 */ 	swc1	$f8,0x78($sp)
/*  f161da8:	c4ca0038 */ 	lwc1	$f10,0x38($a2)
/*  f161dac:	3c0a800a */ 	lui	$t2,%hi(var800a4ccc)
/*  f161db0:	240b0014 */ 	addiu	$t3,$zero,0x14
/*  f161db4:	e7aa007c */ 	swc1	$f10,0x7c($sp)
/*  f161db8:	80cc0005 */ 	lb	$t4,0x5($a2)
/*  f161dbc:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f161dc0:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f161dc4:	598000cc */ 	blezl	$t4,.L0f1620f8
/*  f161dc8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f161dcc:	4480b000 */ 	mtc1	$zero,$f22
/*  f161dd0:	8d294ce0 */ 	lw	$t1,%lo(var800a4ce0)($t1)
/*  f161dd4:	8d084cc8 */ 	lw	$t0,%lo(g_PortalSomethings)($t0)
/*  f161dd8:	8d4a4ccc */ 	lw	$t2,%lo(var800a4ccc)($t2)
/*  f161ddc:	84ce000e */ 	lh	$t6,0xe($a2)
.L0f161de0:
/*  f161de0:	c48c0000 */ 	lwc1	$f12,0x0($a0)
/*  f161de4:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f161de8:	000e7840 */ 	sll	$t7,$t6,0x1
/*  f161dec:	012fc021 */ 	addu	$t8,$t1,$t7
/*  f161df0:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f161df4:	872d0000 */ 	lh	$t5,0x0($t9)
/*  f161df8:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f161dfc:	01ab0019 */ 	multu	$t5,$t3
/*  f161e00:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f161e04:	010e8821 */ 	addu	$s1,$t0,$t6
/*  f161e08:	962f0000 */ 	lhu	$t7,0x0($s1)
/*  f161e0c:	01e88021 */ 	addu	$s0,$t7,$t0
/*  f161e10:	0000c012 */ 	mflo	$t8
/*  f161e14:	030a9021 */ 	addu	$s2,$t8,$t2
/*  f161e18:	c64e0000 */ 	lwc1	$f14,0x0($s2)
/*  f161e1c:	c6500004 */ 	lwc1	$f16,0x4($s2)
/*  f161e20:	c6420008 */ 	lwc1	$f2,0x8($s2)
/*  f161e24:	460e6102 */ 	mul.s	$f4,$f12,$f14
/*  f161e28:	c654000c */ 	lwc1	$f20,0xc($s2)
/*  f161e2c:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f161e30:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f161e34:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f161e38:	46061102 */ 	mul.s	$f4,$f2,$f6
/*  f161e3c:	c7a80074 */ 	lwc1	$f8,0x74($sp)
/*  f161e40:	460e4182 */ 	mul.s	$f6,$f8,$f14
/*  f161e44:	460a2000 */ 	add.s	$f0,$f4,$f10
/*  f161e48:	c7a40078 */ 	lwc1	$f4,0x78($sp)
/*  f161e4c:	46102282 */ 	mul.s	$f10,$f4,$f16
/*  f161e50:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*  f161e54:	4614003c */ 	c.lt.s	$f0,$f20
/*  f161e58:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f161e5c:	46041182 */ 	mul.s	$f6,$f2,$f4
/*  f161e60:	45000007 */ 	bc1f	.L0f161e80
/*  f161e64:	46083480 */ 	add.s	$f18,$f6,$f8
/*  f161e68:	4614903c */ 	c.lt.s	$f18,$f20
/*  f161e6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161e70:	4502000f */ 	bc1fl	.L0f161eb0
/*  f161e74:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f161e78:	1000009b */ 	beqz	$zero,.L0f1620e8
/*  f161e7c:	000c6840 */ 	sll	$t5,$t4,0x1
.L0f161e80:
/*  f161e80:	c6420010 */ 	lwc1	$f2,0x10($s2)
/*  f161e84:	4600103c */ 	c.lt.s	$f2,$f0
/*  f161e88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161e8c:	45020008 */ 	bc1fl	.L0f161eb0
/*  f161e90:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f161e94:	4612103c */ 	c.lt.s	$f2,$f18
/*  f161e98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161e9c:	45020004 */ 	bc1fl	.L0f161eb0
/*  f161ea0:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
/*  f161ea4:	10000090 */ 	beqz	$zero,.L0f1620e8
/*  f161ea8:	000c6840 */ 	sll	$t5,$t4,0x1
/*  f161eac:	c7aa0074 */ 	lwc1	$f10,0x74($sp)
.L0f161eb0:
/*  f161eb0:	c7a60078 */ 	lwc1	$f6,0x78($sp)
/*  f161eb4:	26140004 */ 	addiu	$s4,$s0,0x4
/*  f161eb8:	460c5101 */ 	sub.s	$f4,$f10,$f12
/*  f161ebc:	00006025 */ 	or	$t4,$zero,$zero
/*  f161ec0:	00606825 */ 	or	$t5,$v1,$zero
/*  f161ec4:	02809825 */ 	or	$s3,$s4,$zero
/*  f161ec8:	e7a40068 */ 	swc1	$f4,0x68($sp)
/*  f161ecc:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f161ed0:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*  f161ed4:	26150010 */ 	addiu	$s5,$s0,0x10
/*  f161ed8:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f161edc:	0000b025 */ 	or	$s6,$zero,$zero
/*  f161ee0:	e7aa006c */ 	swc1	$f10,0x6c($sp)
/*  f161ee4:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f161ee8:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f161eec:	e7a80070 */ 	swc1	$f8,0x70($sp)
/*  f161ef0:	92170000 */ 	lbu	$s7,0x0($s0)
/*  f161ef4:	1ae00064 */ 	blez	$s7,.L0f162088
.L0f161ef8:
/*  f161ef8:	26d90001 */ 	addiu	$t9,$s6,0x1
/*  f161efc:	57370003 */ 	bnel	$t9,$s7,.L0f161f0c
/*  f161f00:	c6aa0000 */ 	lwc1	$f10,0x0($s5)
/*  f161f04:	0280a825 */ 	or	$s5,$s4,$zero
/*  f161f08:	c6aa0000 */ 	lwc1	$f10,0x0($s5)
.L0f161f0c:
/*  f161f0c:	c6640000 */ 	lwc1	$f4,0x0($s3)
/*  f161f10:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f161f14:	e7a6005c */ 	swc1	$f6,0x5c($sp)
/*  f161f18:	c66a0004 */ 	lwc1	$f10,0x4($s3)
/*  f161f1c:	c6a80004 */ 	lwc1	$f8,0x4($s5)
/*  f161f20:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f161f24:	e7a40060 */ 	swc1	$f4,0x60($sp)
/*  f161f28:	c6680008 */ 	lwc1	$f8,0x8($s3)
/*  f161f2c:	c6a60008 */ 	lwc1	$f6,0x8($s5)
/*  f161f30:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*  f161f34:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f161f38:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f161f3c:	e7a40038 */ 	swc1	$f4,0x38($sp)
/*  f161f40:	e7aa0064 */ 	swc1	$f10,0x64($sp)
/*  f161f44:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f161f48:	c7a40064 */ 	lwc1	$f4,0x64($sp)
/*  f161f4c:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*  f161f50:	e7a6003c */ 	swc1	$f6,0x3c($sp)
/*  f161f54:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f161f58:	e7aa0040 */ 	swc1	$f10,0x40($sp)
/*  f161f5c:	c7aa003c */ 	lwc1	$f10,0x3c($sp)
/*  f161f60:	46064201 */ 	sub.s	$f8,$f8,$f6
/*  f161f64:	c7a60068 */ 	lwc1	$f6,0x68($sp)
/*  f161f68:	e7a8004c */ 	swc1	$f8,0x4c($sp)
/*  f161f6c:	e7a8003c */ 	swc1	$f8,0x3c($sp)
/*  f161f70:	46062102 */ 	mul.s	$f4,$f4,$f6
/*  f161f74:	c7a8005c */ 	lwc1	$f8,0x5c($sp)
/*  f161f78:	46085282 */ 	mul.s	$f10,$f10,$f8
/*  f161f7c:	460a2101 */ 	sub.s	$f4,$f4,$f10
/*  f161f80:	c7aa0040 */ 	lwc1	$f10,0x40($sp)
/*  f161f84:	460a4202 */ 	mul.s	$f8,$f8,$f10
/*  f161f88:	c7aa0038 */ 	lwc1	$f10,0x38($sp)
/*  f161f8c:	e7a40050 */ 	swc1	$f4,0x50($sp)
/*  f161f90:	460a3182 */ 	mul.s	$f6,$f6,$f10
/*  f161f94:	46064281 */ 	sub.s	$f10,$f8,$f6
/*  f161f98:	c7a8003c */ 	lwc1	$f8,0x3c($sp)
/*  f161f9c:	46084182 */ 	mul.s	$f6,$f8,$f8
/*  f161fa0:	e7aa0054 */ 	swc1	$f10,0x54($sp)
/*  f161fa4:	46042202 */ 	mul.s	$f8,$f4,$f4
/*  f161fa8:	46083100 */ 	add.s	$f4,$f6,$f8
/*  f161fac:	460a5182 */ 	mul.s	$f6,$f10,$f10
/*  f161fb0:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*  f161fb4:	46043080 */ 	add.s	$f2,$f6,$f4
/*  f161fb8:	46161032 */ 	c.eq.s	$f2,$f22
/*  f161fbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f161fc0:	45020004 */ 	bc1fl	.L0f161fd4
/*  f161fc4:	c66a0000 */ 	lwc1	$f10,0x0($s3)
/*  f161fc8:	1000002f */ 	beqz	$zero,.L0f162088
/*  f161fcc:	00006825 */ 	or	$t5,$zero,$zero
/*  f161fd0:	c66a0000 */ 	lwc1	$f10,0x0($s3)
.L0f161fd4:
/*  f161fd4:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f161fd8:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f161fdc:	c66a0004 */ 	lwc1	$f10,0x4($s3)
/*  f161fe0:	460a2282 */ 	mul.s	$f10,$f4,$f10
/*  f161fe4:	460a3180 */ 	add.s	$f6,$f6,$f10
/*  f161fe8:	c66a0008 */ 	lwc1	$f10,0x8($s3)
/*  f161fec:	e7a80040 */ 	swc1	$f8,0x40($sp)
/*  f161ff0:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*  f161ff4:	46085282 */ 	mul.s	$f10,$f10,$f8
/*  f161ff8:	46065280 */ 	add.s	$f10,$f10,$f6
/*  f161ffc:	c7a60040 */ 	lwc1	$f6,0x40($sp)
/*  f162000:	e7a40040 */ 	swc1	$f4,0x40($sp)
/*  f162004:	e7aa0058 */ 	swc1	$f10,0x58($sp)
/*  f162008:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f16200c:	46043182 */ 	mul.s	$f6,$f6,$f4
/*  f162010:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*  f162014:	e7a80040 */ 	swc1	$f8,0x40($sp)
/*  f162018:	c4880004 */ 	lwc1	$f8,0x4($a0)
/*  f16201c:	46082102 */ 	mul.s	$f4,$f4,$f8
/*  f162020:	46043200 */ 	add.s	$f8,$f6,$f4
/*  f162024:	c7a40040 */ 	lwc1	$f4,0x40($sp)
/*  f162028:	c4860008 */ 	lwc1	$f6,0x8($a0)
/*  f16202c:	46043182 */ 	mul.s	$f6,$f6,$f4
/*  f162030:	46083080 */ 	add.s	$f2,$f6,$f8
/*  f162034:	460a103c */ 	c.lt.s	$f2,$f10
/*  f162038:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16203c:	45000007 */ 	bc1f	.L0f16205c
/*  f162040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162044:	15820003 */ 	bne	$t4,$v0,.L0f162054
/*  f162048:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16204c:	1000000e */ 	beqz	$zero,.L0f162088
/*  f162050:	00006825 */ 	or	$t5,$zero,$zero
.L0f162054:
/*  f162054:	10000006 */ 	beqz	$zero,.L0f162070
/*  f162058:	00606025 */ 	or	$t4,$v1,$zero
.L0f16205c:
/*  f16205c:	55830004 */ 	bnel	$t4,$v1,.L0f162070
/*  f162060:	00406025 */ 	or	$t4,$v0,$zero
/*  f162064:	10000008 */ 	beqz	$zero,.L0f162088
/*  f162068:	00006825 */ 	or	$t5,$zero,$zero
/*  f16206c:	00406025 */ 	or	$t4,$v0,$zero
.L0f162070:
/*  f162070:	92170000 */ 	lbu	$s7,0x0($s0)
/*  f162074:	26d60001 */ 	addiu	$s6,$s6,0x1
/*  f162078:	2673000c */ 	addiu	$s3,$s3,0xc
/*  f16207c:	02d7082a */ 	slt	$at,$s6,$s7
/*  f162080:	1420ff9d */ 	bnez	$at,.L0f161ef8
/*  f162084:	26b5000c */ 	addiu	$s5,$s5,0xc
.L0f162088:
/*  f162088:	51a00016 */ 	beqzl	$t5,.L0f1620e4
/*  f16208c:	80cc0005 */ 	lb	$t4,0x5($a2)
/*  f162090:	c644000c */ 	lwc1	$f4,0xc($s2)
/*  f162094:	4604003c */ 	c.lt.s	$f0,$f4
/*  f162098:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16209c:	45020007 */ 	bc1fl	.L0f1620bc
/*  f1620a0:	c6460010 */ 	lwc1	$f6,0x10($s2)
/*  f1620a4:	862e0004 */ 	lh	$t6,0x4($s1)
/*  f1620a8:	54ee000e */ 	bnel	$a3,$t6,.L0f1620e4
/*  f1620ac:	80cc0005 */ 	lb	$t4,0x5($a2)
/*  f1620b0:	10000011 */ 	beqz	$zero,.L0f1620f8
/*  f1620b4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1620b8:	c6460010 */ 	lwc1	$f6,0x10($s2)
.L0f1620bc:
/*  f1620bc:	4600303c */ 	c.lt.s	$f6,$f0
/*  f1620c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1620c4:	45020007 */ 	bc1fl	.L0f1620e4
/*  f1620c8:	80cc0005 */ 	lb	$t4,0x5($a2)
/*  f1620cc:	862f0002 */ 	lh	$t7,0x2($s1)
/*  f1620d0:	54ef0004 */ 	bnel	$a3,$t7,.L0f1620e4
/*  f1620d4:	80cc0005 */ 	lb	$t4,0x5($a2)
/*  f1620d8:	10000007 */ 	beqz	$zero,.L0f1620f8
/*  f1620dc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1620e0:	80cc0005 */ 	lb	$t4,0x5($a2)
.L0f1620e4:
/*  f1620e4:	000c6840 */ 	sll	$t5,$t4,0x1
.L0f1620e8:
/*  f1620e8:	00ad082a */ 	slt	$at,$a1,$t5
/*  f1620ec:	5420ff3c */ 	bnezl	$at,.L0f161de0
/*  f1620f0:	84ce000e */ 	lh	$t6,0xe($a2)
/*  f1620f4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1620f8:
/*  f1620f8:	d7b40008 */ 	ldc1	$f20,0x8($sp)
/*  f1620fc:	d7b60010 */ 	ldc1	$f22,0x10($sp)
/*  f162100:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f162104:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f162108:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f16210c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f162110:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f162114:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f162118:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f16211c:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f162120:	03e00008 */ 	jr	$ra
/*  f162124:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
);

GLOBAL_ASM(
glabel func0f162128
/*  f162128:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f16212c:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f162130:	00057400 */ 	sll	$t6,$a1,0x10
/*  f162134:	000e2c03 */ 	sra	$a1,$t6,0x10
/*  f162138:	0005c8c0 */ 	sll	$t9,$a1,0x3
/*  f16213c:	0325c821 */ 	addu	$t9,$t9,$a1
/*  f162140:	3c18800a */ 	lui	$t8,%hi(g_RoomPtrs)
/*  f162144:	8f184928 */ 	lw	$t8,%lo(g_RoomPtrs)($t8)
/*  f162148:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f16214c:	0325c823 */ 	subu	$t9,$t9,$a1
/*  f162150:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f162154:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f162158:	03194021 */ 	addu	$t0,$t8,$t9
/*  f16215c:	95090000 */ 	lhu	$t1,0x0($t0)
/*  f162160:	312a0010 */ 	andi	$t2,$t1,0x10
/*  f162164:	11400005 */ 	beqz	$t2,.L0f16217c
/*  f162168:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16216c:	0fc5874c */ 	jal	func0f161d30
/*  f162170:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162174:	10000004 */ 	beqz	$zero,.L0f162188
/*  f162178:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f16217c:
/*  f16217c:	0fc58702 */ 	jal	func0f161c08
/*  f162180:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162184:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f162188:
/*  f162188:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f16218c:	03e00008 */ 	jr	$ra
/*  f162190:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f162194
/*  f162194:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f162198:	afb0000c */ 	sw	$s0,0xc($sp)
/*  f16219c:	f7b40000 */ 	sdc1	$f20,0x0($sp)
/*  f1621a0:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f1621a4:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f1621a8:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f1621ac:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x2bc)
/*  f1621b0:	8c63a27c */ 	lw	$v1,%lo(g_Vars+0x2bc)($v1)
/*  f1621b4:	e7a40048 */ 	swc1	$f4,0x48($sp)
/*  f1621b8:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f1621bc:	4480a000 */ 	mtc1	$zero,$f20
/*  f1621c0:	28610002 */ 	slti	$at,$v1,0x2
/*  f1621c4:	e7a6004c */ 	swc1	$f6,0x4c($sp)
/*  f1621c8:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f1621cc:	00004825 */ 	or	$t1,$zero,$zero
/*  f1621d0:	00005025 */ 	or	$t2,$zero,$zero
/*  f1621d4:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f1621d8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1621dc:	4600a006 */ 	mov.s	$f0,$f20
/*  f1621e0:	14200041 */ 	bnez	$at,.L0f1622e8
/*  f1621e4:	e7a80050 */ 	swc1	$f8,0x50($sp)
/*  f1621e8:	3c10800a */ 	lui	$s0,%hi(g_RoomPtrs)
/*  f1621ec:	26104928 */ 	addiu	$s0,$s0,%lo(g_RoomPtrs)
/*  f1621f0:	2404008c */ 	addiu	$a0,$zero,0x8c
.L0f1621f4:
/*  f1621f4:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f1621f8:	c7aa0048 */ 	lwc1	$f10,0x48($sp)
/*  f1621fc:	01c42821 */ 	addu	$a1,$t6,$a0
/*  f162200:	80af0005 */ 	lb	$t7,0x5($a1)
/*  f162204:	59e00035 */ 	blezl	$t7,.L0f1622dc
/*  f162208:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f16220c:	c4a40018 */ 	lwc1	$f4,0x18($a1)
/*  f162210:	460a203e */ 	c.le.s	$f4,$f10
/*  f162214:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162218:	45020030 */ 	bc1fl	.L0f1622dc
/*  f16221c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f162220:	c4a60024 */ 	lwc1	$f6,0x24($a1)
/*  f162224:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f162228:	4606503e */ 	c.le.s	$f10,$f6
/*  f16222c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162230:	4502002a */ 	bc1fl	.L0f1622dc
/*  f162234:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f162238:	c4a40020 */ 	lwc1	$f4,0x20($a1)
/*  f16223c:	4608203e */ 	c.le.s	$f4,$f8
/*  f162240:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162244:	45020025 */ 	bc1fl	.L0f1622dc
/*  f162248:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f16224c:	c4a6002c */ 	lwc1	$f6,0x2c($a1)
/*  f162250:	c7aa004c */ 	lwc1	$f10,0x4c($sp)
/*  f162254:	4606403e */ 	c.le.s	$f8,$f6
/*  f162258:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16225c:	4502001f */ 	bc1fl	.L0f1622dc
/*  f162260:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f162264:	c4a4001c */ 	lwc1	$f4,0x1c($a1)
/*  f162268:	460a203e */ 	c.le.s	$f4,$f10
/*  f16226c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162270:	4502001a */ 	bc1fl	.L0f1622dc
/*  f162274:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f162278:	c4a60028 */ 	lwc1	$f6,0x28($a1)
/*  f16227c:	0147082a */ 	slt	$at,$t2,$a3
/*  f162280:	4606503e */ 	c.le.s	$f10,$f6
/*  f162284:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162288:	4500000b */ 	bc1f	.L0f1622b8
/*  f16228c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162290:	0127082a */ 	slt	$at,$t1,$a3
/*  f162294:	10200010 */ 	beqz	$at,.L0f1622d8
/*  f162298:	8fb80064 */ 	lw	$t8,0x64($sp)
/*  f16229c:	0009c840 */ 	sll	$t9,$t1,0x1
/*  f1622a0:	03197021 */ 	addu	$t6,$t8,$t9
/*  f1622a4:	a5c20000 */ 	sh	$v0,0x0($t6)
/*  f1622a8:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x2bc)
/*  f1622ac:	8c63a27c */ 	lw	$v1,%lo(g_Vars+0x2bc)($v1)
/*  f1622b0:	10000009 */ 	beqz	$zero,.L0f1622d8
/*  f1622b4:	25290001 */ 	addiu	$t1,$t1,0x1
.L0f1622b8:
/*  f1622b8:	10200007 */ 	beqz	$at,.L0f1622d8
/*  f1622bc:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f1622c0:	000ac040 */ 	sll	$t8,$t2,0x1
/*  f1622c4:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f1622c8:	a7220000 */ 	sh	$v0,0x0($t9)
/*  f1622cc:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x2bc)
/*  f1622d0:	8c63a27c */ 	lw	$v1,%lo(g_Vars+0x2bc)($v1)
/*  f1622d4:	254a0001 */ 	addiu	$t2,$t2,0x1
.L0f1622d8:
/*  f1622d8:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f1622dc:
/*  f1622dc:	0043082a */ 	slt	$at,$v0,$v1
/*  f1622e0:	1420ffc4 */ 	bnez	$at,.L0f1621f4
/*  f1622e4:	2484008c */ 	addiu	$a0,$a0,0x8c
.L0f1622e8:
/*  f1622e8:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f1622ec:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f1622f0:	3c10800a */ 	lui	$s0,%hi(g_RoomPtrs)
/*  f1622f4:	00093040 */ 	sll	$a2,$t1,0x1
/*  f1622f8:	000a6040 */ 	sll	$t4,$t2,0x1
/*  f1622fc:	26104928 */ 	addiu	$s0,$s0,%lo(g_RoomPtrs)
/*  f162300:	01c65821 */ 	addu	$t3,$t6,$a2
/*  f162304:	15200043 */ 	bnez	$t1,.L0f162414
/*  f162308:	01ec6821 */ 	addu	$t5,$t7,$t4
/*  f16230c:	15400041 */ 	bnez	$t2,.L0f162414
/*  f162310:	28610002 */ 	slti	$at,$v1,0x2
/*  f162314:	1420003f */ 	bnez	$at,.L0f162414
/*  f162318:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f16231c:	2404008c */ 	addiu	$a0,$zero,0x8c
.L0f162320:
/*  f162320:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f162324:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f162328:	03042821 */ 	addu	$a1,$t8,$a0
/*  f16232c:	80b90005 */ 	lb	$t9,0x5($a1)
/*  f162330:	57200035 */ 	bnezl	$t9,.L0f162408
/*  f162334:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f162338:	c4a40018 */ 	lwc1	$f4,0x18($a1)
/*  f16233c:	4608203e */ 	c.le.s	$f4,$f8
/*  f162340:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162344:	45020030 */ 	bc1fl	.L0f162408
/*  f162348:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f16234c:	c4a60024 */ 	lwc1	$f6,0x24($a1)
/*  f162350:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*  f162354:	4606403e */ 	c.le.s	$f8,$f6
/*  f162358:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16235c:	4502002a */ 	bc1fl	.L0f162408
/*  f162360:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f162364:	c4a40020 */ 	lwc1	$f4,0x20($a1)
/*  f162368:	460a203e */ 	c.le.s	$f4,$f10
/*  f16236c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162370:	45020025 */ 	bc1fl	.L0f162408
/*  f162374:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f162378:	c4a6002c */ 	lwc1	$f6,0x2c($a1)
/*  f16237c:	c7a8004c */ 	lwc1	$f8,0x4c($sp)
/*  f162380:	4606503e */ 	c.le.s	$f10,$f6
/*  f162384:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162388:	4502001f */ 	bc1fl	.L0f162408
/*  f16238c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f162390:	c4a4001c */ 	lwc1	$f4,0x1c($a1)
/*  f162394:	4608203e */ 	c.le.s	$f4,$f8
/*  f162398:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16239c:	4502001a */ 	bc1fl	.L0f162408
/*  f1623a0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1623a4:	c4a60028 */ 	lwc1	$f6,0x28($a1)
/*  f1623a8:	0147082a */ 	slt	$at,$t2,$a3
/*  f1623ac:	4606403e */ 	c.le.s	$f8,$f6
/*  f1623b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1623b4:	4500000b */ 	bc1f	.L0f1623e4
/*  f1623b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1623bc:	0127082a */ 	slt	$at,$t1,$a3
/*  f1623c0:	50200011 */ 	beqzl	$at,.L0f162408
/*  f1623c4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1623c8:	a5620000 */ 	sh	$v0,0x0($t3)
/*  f1623cc:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x2bc)
/*  f1623d0:	8c63a27c */ 	lw	$v1,%lo(g_Vars+0x2bc)($v1)
/*  f1623d4:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f1623d8:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f1623dc:	10000009 */ 	beqz	$zero,.L0f162404
/*  f1623e0:	256b0002 */ 	addiu	$t3,$t3,0x2
.L0f1623e4:
/*  f1623e4:	50200008 */ 	beqzl	$at,.L0f162408
/*  f1623e8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1623ec:	a5a20000 */ 	sh	$v0,0x0($t5)
/*  f1623f0:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x2bc)
/*  f1623f4:	8c63a27c */ 	lw	$v1,%lo(g_Vars+0x2bc)($v1)
/*  f1623f8:	254a0001 */ 	addiu	$t2,$t2,0x1
/*  f1623fc:	258c0002 */ 	addiu	$t4,$t4,0x2
/*  f162400:	25ad0002 */ 	addiu	$t5,$t5,0x2
.L0f162404:
/*  f162404:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f162408:
/*  f162408:	0043082a */ 	slt	$at,$v0,$v1
/*  f16240c:	1420ffc4 */ 	bnez	$at,.L0f162320
/*  f162410:	2484008c */ 	addiu	$a0,$a0,0x8c
.L0f162414:
/*  f162414:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f162418:	240affff */ 	addiu	$t2,$zero,-1
/*  f16241c:	a56a0000 */ 	sh	$t2,0x0($t3)
/*  f162420:	10800046 */ 	beqz	$a0,.L0f16253c
/*  f162424:	a5aa0000 */ 	sh	$t2,0x0($t5)
/*  f162428:	14c0003f */ 	bnez	$a2,.L0f162528
/*  f16242c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162430:	1580003d */ 	bnez	$t4,.L0f162528
/*  f162434:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x2bc)
/*  f162438:	8c63a27c */ 	lw	$v1,%lo(g_Vars+0x2bc)($v1)
/*  f16243c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f162440:	3c07800a */ 	lui	$a3,%hi(g_RoomPtrs)
/*  f162444:	28610002 */ 	slti	$at,$v1,0x2
/*  f162448:	14200037 */ 	bnez	$at,.L0f162528
/*  f16244c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162450:	8ce74928 */ 	lw	$a3,%lo(g_RoomPtrs)($a3)
/*  f162454:	27ab0054 */ 	addiu	$t3,$sp,0x54
/*  f162458:	24e7008c */ 	addiu	$a3,$a3,140
.L0f16245c:
/*  f16245c:	4600a086 */ 	mov.s	$f2,$f20
/*  f162460:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f162464:	00e04825 */ 	or	$t1,$a3,$zero
.L0f162468:
/*  f162468:	c4cc0000 */ 	lwc1	$f12,0x0($a2)
/*  f16246c:	c52e0018 */ 	lwc1	$f14,0x18($t1)
/*  f162470:	24c60004 */ 	addiu	$a2,$a2,0x4
/*  f162474:	460e603c */ 	c.lt.s	$f12,$f14
/*  f162478:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16247c:	45030007 */ 	bc1tl	.L0f16249c
/*  f162480:	460e6401 */ 	sub.s	$f16,$f12,$f14
/*  f162484:	c52a0024 */ 	lwc1	$f10,0x24($t1)
/*  f162488:	460c503c */ 	c.lt.s	$f10,$f12
/*  f16248c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162490:	45000013 */ 	bc1f	.L0f1624e0
/*  f162494:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162498:	460e6401 */ 	sub.s	$f16,$f12,$f14
.L0f16249c:
/*  f16249c:	c5240024 */ 	lwc1	$f4,0x24($t1)
/*  f1624a0:	4614803c */ 	c.lt.s	$f16,$f20
/*  f1624a4:	46046481 */ 	sub.s	$f18,$f12,$f4
/*  f1624a8:	45020003 */ 	bc1fl	.L0f1624b8
/*  f1624ac:	4614903c */ 	c.lt.s	$f18,$f20
/*  f1624b0:	46008407 */ 	neg.s	$f16,$f16
/*  f1624b4:	4614903c */ 	c.lt.s	$f18,$f20
.L0f1624b8:
/*  f1624b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1624bc:	45020003 */ 	bc1fl	.L0f1624cc
/*  f1624c0:	4610903c */ 	c.lt.s	$f18,$f16
/*  f1624c4:	46009487 */ 	neg.s	$f18,$f18
/*  f1624c8:	4610903c */ 	c.lt.s	$f18,$f16
.L0f1624cc:
/*  f1624cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1624d0:	45020003 */ 	bc1fl	.L0f1624e0
/*  f1624d4:	46101080 */ 	add.s	$f2,$f2,$f16
/*  f1624d8:	46009406 */ 	mov.s	$f16,$f18
/*  f1624dc:	46101080 */ 	add.s	$f2,$f2,$f16
.L0f1624e0:
/*  f1624e0:	14cbffe1 */ 	bne	$a2,$t3,.L0f162468
/*  f1624e4:	25290004 */ 	addiu	$t1,$t1,0x4
/*  f1624e8:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f1624ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1624f0:	4502000a */ 	bc1fl	.L0f16251c
/*  f1624f4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1624f8:	05020006 */ 	bltzl	$t0,.L0f162514
/*  f1624fc:	00404025 */ 	or	$t0,$v0,$zero
/*  f162500:	4600103c */ 	c.lt.s	$f2,$f0
/*  f162504:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162508:	45020004 */ 	bc1fl	.L0f16251c
/*  f16250c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f162510:	00404025 */ 	or	$t0,$v0,$zero
.L0f162514:
/*  f162514:	46001006 */ 	mov.s	$f0,$f2
/*  f162518:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f16251c:
/*  f16251c:	0043082a */ 	slt	$at,$v0,$v1
/*  f162520:	1420ffce */ 	bnez	$at,.L0f16245c
/*  f162524:	24e7008c */ 	addiu	$a3,$a3,0x8c
.L0f162528:
/*  f162528:	05020004 */ 	bltzl	$t0,.L0f16253c
/*  f16252c:	a48a0000 */ 	sh	$t2,0x0($a0)
/*  f162530:	10000002 */ 	beqz	$zero,.L0f16253c
/*  f162534:	a4880000 */ 	sh	$t0,0x0($a0)
/*  f162538:	a48a0000 */ 	sh	$t2,0x0($a0)
.L0f16253c:
/*  f16253c:	d7b40000 */ 	ldc1	$f20,0x0($sp)
/*  f162540:	8fb0000c */ 	lw	$s0,0xc($sp)
/*  f162544:	03e00008 */ 	jr	$ra
/*  f162548:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f16254c
/*  f16254c:	3c058008 */ 	lui	$a1,%hi(var8007fca8)
/*  f162550:	24a5fca8 */ 	addiu	$a1,$a1,%lo(var8007fca8)
/*  f162554:	8ca30000 */ 	lw	$v1,0x0($a1)
/*  f162558:	3c018008 */ 	lui	$at,%hi(var8007fc58)
/*  f16255c:	00801025 */ 	or	$v0,$a0,$zero
/*  f162560:	00037080 */ 	sll	$t6,$v1,0x2
/*  f162564:	002e0821 */ 	addu	$at,$at,$t6
/*  f162568:	ac24fc58 */ 	sw	$a0,%lo(var8007fc58)($at)
/*  f16256c:	24010014 */ 	addiu	$at,$zero,0x14
/*  f162570:	246f0001 */ 	addiu	$t7,$v1,0x1
/*  f162574:	01e1001a */ 	div	$zero,$t7,$at
/*  f162578:	0000c010 */ 	mfhi	$t8
/*  f16257c:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f162580:	03e00008 */ 	jr	$ra
/*  f162584:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f162588
/*  f162588:	3c048008 */ 	lui	$a0,%hi(var8007fca8)
/*  f16258c:	2484fca8 */ 	addiu	$a0,$a0,%lo(var8007fca8)
/*  f162590:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f162594:	24010014 */ 	addiu	$at,$zero,0x14
/*  f162598:	3c038008 */ 	lui	$v1,%hi(var8007fc58)
/*  f16259c:	25cf0013 */ 	addiu	$t7,$t6,0x13
/*  f1625a0:	01e1001a */ 	div	$zero,$t7,$at
/*  f1625a4:	0000c010 */ 	mfhi	$t8
/*  f1625a8:	00184080 */ 	sll	$t0,$t8,0x2
/*  f1625ac:	00681821 */ 	addu	$v1,$v1,$t0
/*  f1625b0:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f1625b4:	03e00008 */ 	jr	$ra
/*  f1625b8:	8c62fc58 */ 	lw	$v0,%lo(var8007fc58)($v1)
);

GLOBAL_ASM(
glabel func0f1625bc
/*  f1625bc:	3c0e8008 */ 	lui	$t6,%hi(var8007fca8)
/*  f1625c0:	8dcefca8 */ 	lw	$t6,%lo(var8007fca8)($t6)
/*  f1625c4:	24010014 */ 	addiu	$at,$zero,0x14
/*  f1625c8:	3c028008 */ 	lui	$v0,%hi(var8007fc58)
/*  f1625cc:	01c47823 */ 	subu	$t7,$t6,$a0
/*  f1625d0:	25f80013 */ 	addiu	$t8,$t7,0x13
/*  f1625d4:	0301001a */ 	div	$zero,$t8,$at
/*  f1625d8:	0000c810 */ 	mfhi	$t9
/*  f1625dc:	00194080 */ 	sll	$t0,$t9,0x2
/*  f1625e0:	00481021 */ 	addu	$v0,$v0,$t0
/*  f1625e4:	03e00008 */ 	jr	$ra
/*  f1625e8:	8c42fc58 */ 	lw	$v0,%lo(var8007fc58)($v0)
);

GLOBAL_ASM(
glabel func0f1625ec
.late_rodata
glabel var7f1b75e0
.word func0f1625ec+0x614 # f162c00
glabel var7f1b75e4
.word func0f1625ec+0x650 # f162c3c
glabel var7f1b75e8
.word func0f1625ec+0x638 # f162c24
glabel var7f1b75ec
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b75f0
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b75f4
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b75f8
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b75fc
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7600
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7604
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7608
.word func0f1625ec+0x674 # f162c60
glabel var7f1b760c
.word func0f1625ec+0x6ac # f162c98
glabel var7f1b7610
.word func0f1625ec+0x6c4 # f162cb0
glabel var7f1b7614
.word func0f1625ec+0xb8 # f1626a4
glabel var7f1b7618
.word func0f1625ec+0xc0 # f1626ac
glabel var7f1b761c
.word func0f1625ec+0xe0 # f1626cc
glabel var7f1b7620
.word func0f1625ec+0x100 # f1626ec
glabel var7f1b7624
.word func0f1625ec+0x130 # f16271c
glabel var7f1b7628
.word func0f1625ec+0x160 # f16274c
glabel var7f1b762c
.word func0f1625ec+0x188 # f162774
glabel var7f1b7630
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7634
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7638
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b763c
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7640
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7644
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7648
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b764c
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7650
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7654
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7658
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b765c
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7660
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7664
.word func0f1625ec+0x1b8 # f1627a4
glabel var7f1b7668
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b766c
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7670
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7674
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7678
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b767c
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7680
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7684
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b7688
.word func0f1625ec+0x6d4 # f162cc0
glabel var7f1b768c
.word func0f1625ec+0x1fc # f1627e8
glabel var7f1b7690
.word func0f1625ec+0x26c # f162858
glabel var7f1b7694
.word func0f1625ec+0x418 # f162a04
glabel var7f1b7698
.word func0f1625ec+0x5f8 # f162be4
glabel var7f1b769c
.word func0f1625ec+0x2e8 # f1628d4
glabel var7f1b76a0
.word func0f1625ec+0x374 # f162960
glabel var7f1b76a4
.word func0f1625ec+0x484 # f162a70
glabel var7f1b76a8
.word func0f1625ec+0x4c8 # f162ab4
glabel var7f1b76ac
.word func0f1625ec+0x530 # f162b1c
glabel var7f1b76b0
.word func0f1625ec+0x540 # f162b2c
glabel var7f1b76b4
.word func0f1625ec+0x550 # f162b3c
glabel var7f1b76b8
.word func0f1625ec+0x56c # f162b58
glabel var7f1b76bc
.word func0f1625ec+0x5bc # f162ba8
.text
/*  f1625ec:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f1625f0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f1625f4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f1625f8:	3c01800a */ 	lui	$at,%hi(var800a65d0)
/*  f1625fc:	00808025 */ 	or	$s0,$a0,$zero
/*  f162600:	00a09025 */ 	or	$s2,$a1,$zero
/*  f162604:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f162608:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f16260c:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f162610:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f162614:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f162618:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f16261c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f162620:	14800003 */ 	bnez	$a0,.L0f162630
/*  f162624:	ac2065d0 */ 	sw	$zero,%lo(var800a65d0)($at)
/*  f162628:	100001a6 */ 	beqz	$zero,.L0f162cc4
/*  f16262c:	00801025 */ 	or	$v0,$a0,$zero
.L0f162630:
/*  f162630:	3c17800a */ 	lui	$s7,%hi(g_PortalSomethings)
/*  f162634:	3c15800a */ 	lui	$s5,%hi(var800a65c0)
/*  f162638:	3c14800a */ 	lui	$s4,%hi(g_RoomPtrs)
/*  f16263c:	3c138008 */ 	lui	$s3,%hi(var8007fcac)
/*  f162640:	2673fcac */ 	addiu	$s3,$s3,%lo(var8007fcac)
/*  f162644:	26944928 */ 	addiu	$s4,$s4,%lo(g_RoomPtrs)
/*  f162648:	26b565c0 */ 	addiu	$s5,$s5,%lo(var800a65c0)
/*  f16264c:	26f74cc8 */ 	addiu	$s7,$s7,%lo(g_PortalSomethings)
/*  f162650:	24160001 */ 	addiu	$s6,$zero,0x1
.L0f162654:
/*  f162654:	92040000 */ 	lbu	$a0,0x0($s0)
.L0f162658:
/*  f162658:	2881002b */ 	slti	$at,$a0,0x2b
/*  f16265c:	14200009 */ 	bnez	$at,.L0f162684
/*  f162660:	248effb0 */ 	addiu	$t6,$a0,-80
/*  f162664:	2dc1000d */ 	sltiu	$at,$t6,0xd
/*  f162668:	10200195 */ 	beqz	$at,.L0f162cc0
/*  f16266c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f162670:	3c017f1b */ 	lui	$at,%hi(var7f1b75e0)
/*  f162674:	002e0821 */ 	addu	$at,$at,$t6
/*  f162678:	8c2e75e0 */ 	lw	$t6,%lo(var7f1b75e0)($at)
/*  f16267c:	01c00008 */ 	jr	$t6
/*  f162680:	00000000 */ 	sll	$zero,$zero,0x0
.L0f162684:
/*  f162684:	2c81002b */ 	sltiu	$at,$a0,0x2b
/*  f162688:	1020018d */ 	beqz	$at,.L0f162cc0
/*  f16268c:	00047880 */ 	sll	$t7,$a0,0x2
/*  f162690:	3c017f1b */ 	lui	$at,%hi(var7f1b7614)
/*  f162694:	002f0821 */ 	addu	$at,$at,$t7
/*  f162698:	8c2f7614 */ 	lw	$t7,%lo(var7f1b7614)($at)
/*  f16269c:	01e00008 */ 	jr	$t7
/*  f1626a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1626a4:	10000187 */ 	beqz	$zero,.L0f162cc4
/*  f1626a8:	02001025 */ 	or	$v0,$s0,$zero
/*  f1626ac:	52400004 */ 	beqzl	$s2,.L0f1626c0
/*  f1626b0:	92180001 */ 	lbu	$t8,0x1($s0)
/*  f1626b4:	0fc58953 */ 	jal	func0f16254c
/*  f1626b8:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f1626bc:	92180001 */ 	lbu	$t8,0x1($s0)
.L0f1626c0:
/*  f1626c0:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f1626c4:	1000ffe3 */ 	beqz	$zero,.L0f162654
/*  f1626c8:	02198021 */ 	addu	$s0,$s0,$t9
/*  f1626cc:	52400004 */ 	beqzl	$s2,.L0f1626e0
/*  f1626d0:	92080001 */ 	lbu	$t0,0x1($s0)
/*  f1626d4:	0fc58962 */ 	jal	func0f162588
/*  f1626d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1626dc:	92080001 */ 	lbu	$t0,0x1($s0)
.L0f1626e0:
/*  f1626e0:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f1626e4:	1000ffdb */ 	beqz	$zero,.L0f162654
/*  f1626e8:	02098021 */ 	addu	$s0,$s0,$t1
/*  f1626ec:	52400008 */ 	beqzl	$s2,.L0f162710
/*  f1626f0:	920a0001 */ 	lbu	$t2,0x1($s0)
/*  f1626f4:	0fc58962 */ 	jal	func0f162588
/*  f1626f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1626fc:	0fc58962 */ 	jal	func0f162588
/*  f162700:	00408825 */ 	or	$s1,$v0,$zero
/*  f162704:	0fc58953 */ 	jal	func0f16254c
/*  f162708:	00512024 */ 	and	$a0,$v0,$s1
/*  f16270c:	920a0001 */ 	lbu	$t2,0x1($s0)
.L0f162710:
/*  f162710:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f162714:	1000ffcf */ 	beqz	$zero,.L0f162654
/*  f162718:	020b8021 */ 	addu	$s0,$s0,$t3
/*  f16271c:	52400008 */ 	beqzl	$s2,.L0f162740
/*  f162720:	920c0001 */ 	lbu	$t4,0x1($s0)
/*  f162724:	0fc58962 */ 	jal	func0f162588
/*  f162728:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16272c:	0fc58962 */ 	jal	func0f162588
/*  f162730:	00408825 */ 	or	$s1,$v0,$zero
/*  f162734:	0fc58953 */ 	jal	func0f16254c
/*  f162738:	00512025 */ 	or	$a0,$v0,$s1
/*  f16273c:	920c0001 */ 	lbu	$t4,0x1($s0)
.L0f162740:
/*  f162740:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f162744:	1000ffc3 */ 	beqz	$zero,.L0f162654
/*  f162748:	020d8021 */ 	addu	$s0,$s0,$t5
/*  f16274c:	52400006 */ 	beqzl	$s2,.L0f162768
/*  f162750:	920e0001 */ 	lbu	$t6,0x1($s0)
/*  f162754:	0fc58962 */ 	jal	func0f162588
/*  f162758:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16275c:	0fc58953 */ 	jal	func0f16254c
/*  f162760:	2c440001 */ 	sltiu	$a0,$v0,0x1
/*  f162764:	920e0001 */ 	lbu	$t6,0x1($s0)
.L0f162768:
/*  f162768:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f16276c:	1000ffb9 */ 	beqz	$zero,.L0f162654
/*  f162770:	020f8021 */ 	addu	$s0,$s0,$t7
/*  f162774:	52400008 */ 	beqzl	$s2,.L0f162798
/*  f162778:	92180001 */ 	lbu	$t8,0x1($s0)
/*  f16277c:	0fc58962 */ 	jal	func0f162588
/*  f162780:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162784:	0fc58962 */ 	jal	func0f162588
/*  f162788:	00408825 */ 	or	$s1,$v0,$zero
/*  f16278c:	0fc58953 */ 	jal	func0f16254c
/*  f162790:	00512026 */ 	xor	$a0,$v0,$s1
/*  f162794:	92180001 */ 	lbu	$t8,0x1($s0)
.L0f162798:
/*  f162798:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f16279c:	1000ffad */ 	beqz	$zero,.L0f162654
/*  f1627a0:	02198021 */ 	addu	$s0,$s0,$t9
/*  f1627a4:	1240000c */ 	beqz	$s2,.L0f1627d8
/*  f1627a8:	3c028008 */ 	lui	$v0,%hi(var8007fc20)
/*  f1627ac:	8c42fc20 */ 	lw	$v0,%lo(var8007fc20)($v0)
/*  f1627b0:	8e08000c */ 	lw	$t0,0xc($s0)
/*  f1627b4:	0048202a */ 	slt	$a0,$v0,$t0
/*  f1627b8:	38840001 */ 	xori	$a0,$a0,0x1
/*  f1627bc:	10800004 */ 	beqz	$a0,.L0f1627d0
/*  f1627c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1627c4:	8e090014 */ 	lw	$t1,0x14($s0)
/*  f1627c8:	0122202a */ 	slt	$a0,$t1,$v0
/*  f1627cc:	38840001 */ 	xori	$a0,$a0,0x1
.L0f1627d0:
/*  f1627d0:	0fc58953 */ 	jal	func0f16254c
/*  f1627d4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1627d8:
/*  f1627d8:	920a0001 */ 	lbu	$t2,0x1($s0)
/*  f1627dc:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f1627e0:	1000ff9c */ 	beqz	$zero,.L0f162654
/*  f1627e4:	020b8021 */ 	addu	$s0,$s0,$t3
/*  f1627e8:	12400017 */ 	beqz	$s2,.L0f162848
/*  f1627ec:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f1627f0:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f1627f4:	c4441794 */ 	lwc1	$f4,0x1794($v0)
/*  f1627f8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1627fc:	440d3000 */ 	mfc1	$t5,$f6
/*  f162800:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162804:	a6ad0000 */ 	sh	$t5,0x0($s5)
/*  f162808:	c4481798 */ 	lwc1	$f8,0x1798($v0)
/*  f16280c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f162810:	440f5000 */ 	mfc1	$t7,$f10
/*  f162814:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162818:	a6af0002 */ 	sh	$t7,0x2($s5)
/*  f16281c:	c450179c */ 	lwc1	$f16,0x179c($v0)
/*  f162820:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f162824:	44199000 */ 	mfc1	$t9,$f18
/*  f162828:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16282c:	a6b90004 */ 	sh	$t9,0x4($s5)
/*  f162830:	c44417a0 */ 	lwc1	$f4,0x17a0($v0)
/*  f162834:	ae600000 */ 	sw	$zero,0x0($s3)
/*  f162838:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f16283c:	44093000 */ 	mfc1	$t1,$f6
/*  f162840:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162844:	a6a90006 */ 	sh	$t1,0x6($s5)
.L0f162848:
/*  f162848:	920a0001 */ 	lbu	$t2,0x1($s0)
/*  f16284c:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f162850:	1000ff80 */ 	beqz	$zero,.L0f162654
/*  f162854:	020b8021 */ 	addu	$s0,$s0,$t3
/*  f162858:	5240001b */ 	beqzl	$s2,.L0f1628c8
/*  f16285c:	92190001 */ 	lbu	$t9,0x1($s0)
/*  f162860:	8e04000c */ 	lw	$a0,0xc($s0)
/*  f162864:	8eec0000 */ 	lw	$t4,0x0($s7)
/*  f162868:	3c05800a */ 	lui	$a1,%hi(var800a65c8)
/*  f16286c:	000468c0 */ 	sll	$t5,$a0,0x3
/*  f162870:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f162874:	91c20006 */ 	lbu	$v0,0x6($t6)
/*  f162878:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f16287c:	11e00003 */ 	beqz	$t7,.L0f16288c
/*  f162880:	30580004 */ 	andi	$t8,$v0,0x4
/*  f162884:	53000010 */ 	beqzl	$t8,.L0f1628c8
/*  f162888:	92190001 */ 	lbu	$t9,0x1($s0)
.L0f16288c:
/*  f16288c:	0fc57443 */ 	jal	func0f15d10c
/*  f162890:	24a565c8 */ 	addiu	$a1,$a1,%lo(var800a65c8)
/*  f162894:	14400003 */ 	bnez	$v0,.L0f1628a4
/*  f162898:	02a02025 */ 	or	$a0,$s5,$zero
/*  f16289c:	10000009 */ 	beqz	$zero,.L0f1628c4
/*  f1628a0:	ae760000 */ 	sw	$s6,0x0($s3)
.L0f1628a4:
/*  f1628a4:	3c05800a */ 	lui	$a1,%hi(var800a65c8)
/*  f1628a8:	0fc5755c */ 	jal	func0f15d570
/*  f1628ac:	24a565c8 */ 	addiu	$a1,$a1,%lo(var800a65c8)
/*  f1628b0:	54400004 */ 	bnezl	$v0,.L0f1628c4
/*  f1628b4:	ae600000 */ 	sw	$zero,0x0($s3)
/*  f1628b8:	10000002 */ 	beqz	$zero,.L0f1628c4
/*  f1628bc:	ae760000 */ 	sw	$s6,0x0($s3)
/*  f1628c0:	ae600000 */ 	sw	$zero,0x0($s3)
.L0f1628c4:
/*  f1628c4:	92190001 */ 	lbu	$t9,0x1($s0)
.L0f1628c8:
/*  f1628c8:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f1628cc:	1000ff61 */ 	beqz	$zero,.L0f162654
/*  f1628d0:	02088021 */ 	addu	$s0,$s0,$t0
/*  f1628d4:	5240001f */ 	beqzl	$s2,.L0f162954
/*  f1628d8:	920f0001 */ 	lbu	$t7,0x1($s0)
/*  f1628dc:	8e04000c */ 	lw	$a0,0xc($s0)
/*  f1628e0:	8ee90000 */ 	lw	$t1,0x0($s7)
/*  f1628e4:	000450c0 */ 	sll	$t2,$a0,0x3
/*  f1628e8:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f1628ec:	91620006 */ 	lbu	$v0,0x6($t3)
/*  f1628f0:	304c0001 */ 	andi	$t4,$v0,0x1
/*  f1628f4:	11800003 */ 	beqz	$t4,.L0f162904
/*  f1628f8:	304d0004 */ 	andi	$t5,$v0,0x4
/*  f1628fc:	51a00015 */ 	beqzl	$t5,.L0f162954
/*  f162900:	920f0001 */ 	lbu	$t7,0x1($s0)
.L0f162904:
/*  f162904:	0fc57443 */ 	jal	func0f15d10c
/*  f162908:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f16290c:	10400010 */ 	beqz	$v0,.L0f162950
/*  f162910:	02a02025 */ 	or	$a0,$s5,$zero
/*  f162914:	0fc5755c */ 	jal	func0f15d570
/*  f162918:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f16291c:	5040000d */ 	beqzl	$v0,.L0f162954
/*  f162920:	920f0001 */ 	lbu	$t7,0x1($s0)
/*  f162924:	8e6e0000 */ 	lw	$t6,0x0($s3)
/*  f162928:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f16292c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f162930:	11c00005 */ 	beqz	$t6,.L0f162948
/*  f162934:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162938:	0fc575b1 */ 	jal	func0f15d6c4
/*  f16293c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f162940:	10000003 */ 	beqz	$zero,.L0f162950
/*  f162944:	ae600000 */ 	sw	$zero,0x0($s3)
.L0f162948:
/*  f162948:	0fc5758f */ 	jal	func0f15d63c
/*  f16294c:	27a50054 */ 	addiu	$a1,$sp,0x54
.L0f162950:
/*  f162950:	920f0001 */ 	lbu	$t7,0x1($s0)
.L0f162954:
/*  f162954:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f162958:	1000ff3e */ 	beqz	$zero,.L0f162654
/*  f16295c:	02188021 */ 	addu	$s0,$s0,$t8
/*  f162960:	52400025 */ 	beqzl	$s2,.L0f1629f8
/*  f162964:	920d0001 */ 	lbu	$t5,0x1($s0)
/*  f162968:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f16296c:	57200022 */ 	bnezl	$t9,.L0f1629f8
/*  f162970:	920d0001 */ 	lbu	$t5,0x1($s0)
/*  f162974:	8e04000c */ 	lw	$a0,0xc($s0)
/*  f162978:	8ee80000 */ 	lw	$t0,0x0($s7)
/*  f16297c:	000448c0 */ 	sll	$t1,$a0,0x3
/*  f162980:	01095021 */ 	addu	$t2,$t0,$t1
/*  f162984:	91420006 */ 	lbu	$v0,0x6($t2)
/*  f162988:	304b0001 */ 	andi	$t3,$v0,0x1
/*  f16298c:	11600005 */ 	beqz	$t3,.L0f1629a4
/*  f162990:	304c0004 */ 	andi	$t4,$v0,0x4
/*  f162994:	15800003 */ 	bnez	$t4,.L0f1629a4
/*  f162998:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16299c:	10000015 */ 	beqz	$zero,.L0f1629f4
/*  f1629a0:	ae760000 */ 	sw	$s6,0x0($s3)
.L0f1629a4:
/*  f1629a4:	0fc57443 */ 	jal	func0f15d10c
/*  f1629a8:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f1629ac:	14400003 */ 	bnez	$v0,.L0f1629bc
/*  f1629b0:	3c05800a */ 	lui	$a1,%hi(g_Vars+0x284)
/*  f1629b4:	1000000f */ 	beqz	$zero,.L0f1629f4
/*  f1629b8:	ae760000 */ 	sw	$s6,0x0($s3)
.L0f1629bc:
/*  f1629bc:	8ca5a244 */ 	lw	$a1,%lo(g_Vars+0x284)($a1)
/*  f1629c0:	27a4004c */ 	addiu	$a0,$sp,0x4c
/*  f1629c4:	0fc5755c */ 	jal	func0f15d570
/*  f1629c8:	24a51794 */ 	addiu	$a1,$a1,6036
/*  f1629cc:	14400003 */ 	bnez	$v0,.L0f1629dc
/*  f1629d0:	3c04800a */ 	lui	$a0,%hi(var800a65c8)
/*  f1629d4:	10000007 */ 	beqz	$zero,.L0f1629f4
/*  f1629d8:	ae760000 */ 	sw	$s6,0x0($s3)
.L0f1629dc:
/*  f1629dc:	248465c8 */ 	addiu	$a0,$a0,%lo(var800a65c8)
/*  f1629e0:	0fc5755c */ 	jal	func0f15d570
/*  f1629e4:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f1629e8:	54400003 */ 	bnezl	$v0,.L0f1629f8
/*  f1629ec:	920d0001 */ 	lbu	$t5,0x1($s0)
/*  f1629f0:	ae760000 */ 	sw	$s6,0x0($s3)
.L0f1629f4:
/*  f1629f4:	920d0001 */ 	lbu	$t5,0x1($s0)
.L0f1629f8:
/*  f1629f8:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f1629fc:	1000ff15 */ 	beqz	$zero,.L0f162654
/*  f162a00:	020e8021 */ 	addu	$s0,$s0,$t6
/*  f162a04:	52400017 */ 	beqzl	$s2,.L0f162a64
/*  f162a08:	92090001 */ 	lbu	$t1,0x1($s0)
/*  f162a0c:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f162a10:	02a02825 */ 	or	$a1,$s5,$zero
/*  f162a14:	55e00013 */ 	bnezl	$t7,.L0f162a64
/*  f162a18:	92090001 */ 	lbu	$t1,0x1($s0)
/*  f162a1c:	0fc57364 */ 	jal	func0f15cd90
/*  f162a20:	8e04000c */ 	lw	$a0,0xc($s0)
/*  f162a24:	1040000e */ 	beqz	$v0,.L0f162a60
/*  f162a28:	00002825 */ 	or	$a1,$zero,$zero
/*  f162a2c:	8e04000c */ 	lw	$a0,0xc($s0)
/*  f162a30:	0fc55fa5 */ 	jal	func0f157e94
/*  f162a34:	02a03025 */ 	or	$a2,$s5,$zero
/*  f162a38:	3c02800a */ 	lui	$v0,%hi(var800a4bec)
/*  f162a3c:	8c424bec */ 	lw	$v0,%lo(var800a4bec)($v0)
/*  f162a40:	8e18000c */ 	lw	$t8,0xc($s0)
/*  f162a44:	3c01800a */ 	lui	$at,%hi(var800a4930)
/*  f162a48:	0002c840 */ 	sll	$t9,$v0,0x1
/*  f162a4c:	00390821 */ 	addu	$at,$at,$t9
/*  f162a50:	a4384930 */ 	sh	$t8,%lo(var800a4930)($at)
/*  f162a54:	3c01800a */ 	lui	$at,%hi(var800a4bec)
/*  f162a58:	24480001 */ 	addiu	$t0,$v0,0x1
/*  f162a5c:	ac284bec */ 	sw	$t0,%lo(var800a4bec)($at)
.L0f162a60:
/*  f162a60:	92090001 */ 	lbu	$t1,0x1($s0)
.L0f162a64:
/*  f162a64:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f162a68:	1000fefa */ 	beqz	$zero,.L0f162654
/*  f162a6c:	020a8021 */ 	addu	$s0,$s0,$t2
/*  f162a70:	5240000d */ 	beqzl	$s2,.L0f162aa8
/*  f162a74:	92180001 */ 	lbu	$t8,0x1($s0)
/*  f162a78:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f162a7c:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f162a80:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f162a84:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f162a88:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f162a8c:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f162a90:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f162a94:	016d1021 */ 	addu	$v0,$t3,$t5
/*  f162a98:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f162a9c:	35cf0001 */ 	ori	$t7,$t6,0x1
/*  f162aa0:	a44f0000 */ 	sh	$t7,0x0($v0)
/*  f162aa4:	92180001 */ 	lbu	$t8,0x1($s0)
.L0f162aa8:
/*  f162aa8:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f162aac:	1000fee9 */ 	beqz	$zero,.L0f162654
/*  f162ab0:	02198021 */ 	addu	$s0,$s0,$t9
/*  f162ab4:	52400016 */ 	beqzl	$s2,.L0f162b10
/*  f162ab8:	920d0001 */ 	lbu	$t5,0x1($s0)
/*  f162abc:	8e03000c */ 	lw	$v1,0xc($s0)
/*  f162ac0:	8e080014 */ 	lw	$t0,0x14($s0)
/*  f162ac4:	000320c0 */ 	sll	$a0,$v1,0x3
/*  f162ac8:	0103082a */ 	slt	$at,$t0,$v1
/*  f162acc:	1420000f */ 	bnez	$at,.L0f162b0c
/*  f162ad0:	00832021 */ 	addu	$a0,$a0,$v1
/*  f162ad4:	00042080 */ 	sll	$a0,$a0,0x2
/*  f162ad8:	00832023 */ 	subu	$a0,$a0,$v1
/*  f162adc:	00042080 */ 	sll	$a0,$a0,0x2
/*  f162ae0:	8e890000 */ 	lw	$t1,0x0($s4)
.L0f162ae4:
/*  f162ae4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f162ae8:	01241021 */ 	addu	$v0,$t1,$a0
/*  f162aec:	944a0000 */ 	lhu	$t2,0x0($v0)
/*  f162af0:	2484008c */ 	addiu	$a0,$a0,0x8c
/*  f162af4:	354c0001 */ 	ori	$t4,$t2,0x1
/*  f162af8:	a44c0000 */ 	sh	$t4,0x0($v0)
/*  f162afc:	8e0b0014 */ 	lw	$t3,0x14($s0)
/*  f162b00:	0163082a */ 	slt	$at,$t3,$v1
/*  f162b04:	5020fff7 */ 	beqzl	$at,.L0f162ae4
/*  f162b08:	8e890000 */ 	lw	$t1,0x0($s4)
.L0f162b0c:
/*  f162b0c:	920d0001 */ 	lbu	$t5,0x1($s0)
.L0f162b10:
/*  f162b10:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f162b14:	1000fecf */ 	beqz	$zero,.L0f162654
/*  f162b18:	020e8021 */ 	addu	$s0,$s0,$t6
/*  f162b1c:	920f0001 */ 	lbu	$t7,0x1($s0)
/*  f162b20:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f162b24:	1000fecb */ 	beqz	$zero,.L0f162654
/*  f162b28:	02188021 */ 	addu	$s0,$s0,$t8
/*  f162b2c:	92190001 */ 	lbu	$t9,0x1($s0)
/*  f162b30:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f162b34:	1000fec7 */ 	beqz	$zero,.L0f162654
/*  f162b38:	02088021 */ 	addu	$s0,$s0,$t0
/*  f162b3c:	12400002 */ 	beqz	$s2,.L0f162b48
/*  f162b40:	3c01800a */ 	lui	$at,%hi(var800a65b8)
/*  f162b44:	ac3665b8 */ 	sw	$s6,%lo(var800a65b8)($at)
.L0f162b48:
/*  f162b48:	92090001 */ 	lbu	$t1,0x1($s0)
/*  f162b4c:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f162b50:	1000fec0 */ 	beqz	$zero,.L0f162654
/*  f162b54:	020a8021 */ 	addu	$s0,$s0,$t2
/*  f162b58:	52400010 */ 	beqzl	$s2,.L0f162b9c
/*  f162b5c:	92190001 */ 	lbu	$t9,0x1($s0)
/*  f162b60:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f162b64:	8eec0000 */ 	lw	$t4,0x0($s7)
/*  f162b68:	000b68c0 */ 	sll	$t5,$t3,0x3
/*  f162b6c:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f162b70:	91c20006 */ 	lbu	$v0,0x6($t6)
/*  f162b74:	30440001 */ 	andi	$a0,$v0,0x1
/*  f162b78:	2c8f0001 */ 	sltiu	$t7,$a0,0x1
/*  f162b7c:	15e00004 */ 	bnez	$t7,.L0f162b90
/*  f162b80:	01e02025 */ 	or	$a0,$t7,$zero
/*  f162b84:	30440004 */ 	andi	$a0,$v0,0x4
/*  f162b88:	2c980001 */ 	sltiu	$t8,$a0,0x1
/*  f162b8c:	2f040001 */ 	sltiu	$a0,$t8,0x1
.L0f162b90:
/*  f162b90:	0fc58953 */ 	jal	func0f16254c
/*  f162b94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162b98:	92190001 */ 	lbu	$t9,0x1($s0)
.L0f162b9c:
/*  f162b9c:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f162ba0:	1000feac */ 	beqz	$zero,.L0f162654
/*  f162ba4:	02088021 */ 	addu	$s0,$s0,$t0
/*  f162ba8:	5240000b */ 	beqzl	$s2,.L0f162bd8
/*  f162bac:	920d0001 */ 	lbu	$t5,0x1($s0)
/*  f162bb0:	8e0a000c */ 	lw	$t2,0xc($s0)
/*  f162bb4:	8e890000 */ 	lw	$t1,0x0($s4)
/*  f162bb8:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f162bbc:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f162bc0:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f162bc4:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f162bc8:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f162bcc:	012b6021 */ 	addu	$t4,$t1,$t3
/*  f162bd0:	a1800007 */ 	sb	$zero,0x7($t4)
/*  f162bd4:	920d0001 */ 	lbu	$t5,0x1($s0)
.L0f162bd8:
/*  f162bd8:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f162bdc:	1000fe9d */ 	beqz	$zero,.L0f162654
/*  f162be0:	020e8021 */ 	addu	$s0,$s0,$t6
/*  f162be4:	52400003 */ 	beqzl	$s2,.L0f162bf4
/*  f162be8:	920f0001 */ 	lbu	$t7,0x1($s0)
/*  f162bec:	ae760000 */ 	sw	$s6,0x0($s3)
/*  f162bf0:	920f0001 */ 	lbu	$t7,0x1($s0)
.L0f162bf4:
/*  f162bf4:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f162bf8:	1000fe96 */ 	beqz	$zero,.L0f162654
/*  f162bfc:	02188021 */ 	addu	$s0,$s0,$t8
/*  f162c00:	92190001 */ 	lbu	$t9,0x1($s0)
/*  f162c04:	02402825 */ 	or	$a1,$s2,$zero
/*  f162c08:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f162c0c:	0fc5897b */ 	jal	func0f1625ec
/*  f162c10:	01102021 */ 	addu	$a0,$t0,$s0
/*  f162c14:	904a0001 */ 	lbu	$t2,0x1($v0)
/*  f162c18:	000a48c0 */ 	sll	$t1,$t2,0x3
/*  f162c1c:	1000fe8d */ 	beqz	$zero,.L0f162654
/*  f162c20:	00498021 */ 	addu	$s0,$v0,$t1
/*  f162c24:	920b0001 */ 	lbu	$t3,0x1($s0)
/*  f162c28:	3c01800a */ 	lui	$at,%hi(var800a65d0)
/*  f162c2c:	ac2065d0 */ 	sw	$zero,%lo(var800a65d0)($at)
/*  f162c30:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f162c34:	10000023 */ 	beqz	$zero,.L0f162cc4
/*  f162c38:	020c1021 */ 	addu	$v0,$s0,$t4
/*  f162c3c:	920d0001 */ 	lbu	$t5,0x1($s0)
/*  f162c40:	0012102b */ 	sltu	$v0,$zero,$s2
/*  f162c44:	00009025 */ 	or	$s2,$zero,$zero
/*  f162c48:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f162c4c:	1040fe81 */ 	beqz	$v0,.L0f162654
/*  f162c50:	020e8021 */ 	addu	$s0,$s0,$t6
/*  f162c54:	3c01800a */ 	lui	$at,%hi(var800a65d0)
/*  f162c58:	1000fe7e */ 	beqz	$zero,.L0f162654
/*  f162c5c:	ac3665d0 */ 	sw	$s6,%lo(var800a65d0)($at)
/*  f162c60:	0fc58962 */ 	jal	func0f162588
/*  f162c64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162c68:	920f0001 */ 	lbu	$t7,0x1($s0)
/*  f162c6c:	00522824 */ 	and	$a1,$v0,$s2
/*  f162c70:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f162c74:	0fc5897b */ 	jal	func0f1625ec
/*  f162c78:	03102021 */ 	addu	$a0,$t8,$s0
/*  f162c7c:	3c19800a */ 	lui	$t9,%hi(var800a65d0)
/*  f162c80:	8f3965d0 */ 	lw	$t9,%lo(var800a65d0)($t9)
/*  f162c84:	00408025 */ 	or	$s0,$v0,$zero
/*  f162c88:	5320fe73 */ 	beqzl	$t9,.L0f162658
/*  f162c8c:	92040000 */ 	lbu	$a0,0x0($s0)
/*  f162c90:	1000fe70 */ 	beqz	$zero,.L0f162654
/*  f162c94:	00009025 */ 	or	$s2,$zero,$zero
/*  f162c98:	920a0001 */ 	lbu	$t2,0x1($s0)
/*  f162c9c:	3a480001 */ 	xori	$t0,$s2,0x1
/*  f162ca0:	01009025 */ 	or	$s2,$t0,$zero
/*  f162ca4:	000a48c0 */ 	sll	$t1,$t2,0x3
/*  f162ca8:	1000fe6a */ 	beqz	$zero,.L0f162654
/*  f162cac:	02098021 */ 	addu	$s0,$s0,$t1
/*  f162cb0:	920b0001 */ 	lbu	$t3,0x1($s0)
/*  f162cb4:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f162cb8:	10000002 */ 	beqz	$zero,.L0f162cc4
/*  f162cbc:	020c1021 */ 	addu	$v0,$s0,$t4
.L0f162cc0:
/*  f162cc0:	02001025 */ 	or	$v0,$s0,$zero
.L0f162cc4:
/*  f162cc4:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f162cc8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f162ccc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f162cd0:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f162cd4:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f162cd8:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f162cdc:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f162ce0:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f162ce4:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f162ce8:	03e00008 */ 	jr	$ra
/*  f162cec:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f162cf0
/*  f162cf0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f162cf4:	3c06800a */ 	lui	$a2,%hi(g_Vars+0x284)
/*  f162cf8:	3c018008 */ 	lui	$at,%hi(var8007fcac)
/*  f162cfc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f162d00:	00803825 */ 	or	$a3,$a0,$zero
/*  f162d04:	8cc6a244 */ 	lw	$a2,%lo(g_Vars+0x284)($a2)
/*  f162d08:	14800003 */ 	bnez	$a0,.L0f162d18
/*  f162d0c:	ac20fcac */ 	sw	$zero,%lo(var8007fcac)($at)
/*  f162d10:	1000001e */ 	beqz	$zero,.L0f162d8c
/*  f162d14:	00801025 */ 	or	$v0,$a0,$zero
.L0f162d18:
/*  f162d18:	00002025 */ 	or	$a0,$zero,$zero
/*  f162d1c:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f162d20:	0fc5896f */ 	jal	func0f1625bc
/*  f162d24:	afa70020 */ 	sw	$a3,0x20($sp)
/*  f162d28:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f162d2c:	3c03800a */ 	lui	$v1,%hi(var800a65c0)
/*  f162d30:	246365c0 */ 	addiu	$v1,$v1,%lo(var800a65c0)
/*  f162d34:	c4c41794 */ 	lwc1	$f4,0x1794($a2)
/*  f162d38:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f162d3c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f162d40:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f162d44:	440f3000 */ 	mfc1	$t7,$f6
/*  f162d48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162d4c:	a46f0000 */ 	sh	$t7,0x0($v1)
/*  f162d50:	c4c81798 */ 	lwc1	$f8,0x1798($a2)
/*  f162d54:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f162d58:	44195000 */ 	mfc1	$t9,$f10
/*  f162d5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162d60:	a4790002 */ 	sh	$t9,0x2($v1)
/*  f162d64:	c4d0179c */ 	lwc1	$f16,0x179c($a2)
/*  f162d68:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f162d6c:	44099000 */ 	mfc1	$t1,$f18
/*  f162d70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162d74:	a4690004 */ 	sh	$t1,0x4($v1)
/*  f162d78:	c4c417a0 */ 	lwc1	$f4,0x17a0($a2)
/*  f162d7c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f162d80:	440b3000 */ 	mfc1	$t3,$f6
/*  f162d84:	0fc5897b */ 	jal	func0f1625ec
/*  f162d88:	a46b0006 */ 	sh	$t3,0x6($v1)
.L0f162d8c:
/*  f162d8c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f162d90:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f162d94:	03e00008 */ 	jr	$ra
/*  f162d98:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f162d9c
/*  f162d9c:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f162da0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f162da4:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f162da8:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f162dac:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f162db0:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f162db4:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f162db8:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f162dbc:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f162dc0:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f162dc4:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f162dc8:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f162dcc:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f162dd0:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f162dd4:	0fc591d2 */ 	jal	func0f164748
/*  f162dd8:	8e160284 */ 	lw	$s6,0x284($s0)
/*  f162ddc:	3c038008 */ 	lui	$v1,%hi(var8007fc34)
/*  f162de0:	2463fc34 */ 	addiu	$v1,$v1,%lo(var8007fc34)
/*  f162de4:	3c028008 */ 	lui	$v0,%hi(var8007fc30)
/*  f162de8:	8c42fc30 */ 	lw	$v0,%lo(var8007fc30)($v0)
/*  f162dec:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f162df0:	01c2082a */ 	slt	$at,$t6,$v0
/*  f162df4:	50200003 */ 	beqzl	$at,.L0f162e04
/*  f162df8:	c6c41794 */ 	lwc1	$f4,0x1794($s6)
/*  f162dfc:	ac620000 */ 	sw	$v0,0x0($v1)
/*  f162e00:	c6c41794 */ 	lwc1	$f4,0x1794($s6)
.L0f162e04:
/*  f162e04:	00002025 */ 	or	$a0,$zero,$zero
/*  f162e08:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f162e0c:	44183000 */ 	mfc1	$t8,$f6
/*  f162e10:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162e14:	a7b8007c */ 	sh	$t8,0x7c($sp)
/*  f162e18:	c6c81798 */ 	lwc1	$f8,0x1798($s6)
/*  f162e1c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f162e20:	44085000 */ 	mfc1	$t0,$f10
/*  f162e24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162e28:	a7a8007e */ 	sh	$t0,0x7e($sp)
/*  f162e2c:	c6d0179c */ 	lwc1	$f16,0x179c($s6)
/*  f162e30:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f162e34:	440a9000 */ 	mfc1	$t2,$f18
/*  f162e38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162e3c:	a7aa0080 */ 	sh	$t2,0x80($sp)
/*  f162e40:	c6c417a0 */ 	lwc1	$f4,0x17a0($s6)
/*  f162e44:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f162e48:	440c3000 */ 	mfc1	$t4,$f6
/*  f162e4c:	0fc2866a */ 	jal	getCurrentPlayerWeaponId
/*  f162e50:	a7ac0082 */ 	sh	$t4,0x82($sp)
/*  f162e54:	24010016 */ 	addiu	$at,$zero,0x16
/*  f162e58:	5441000d */ 	bnel	$v0,$at,.L0f162e90
/*  f162e5c:	3c01c3fa */ 	lui	$at,0xc3fa
/*  f162e60:	8ecd17a4 */ 	lw	$t5,0x17a4($s6)
/*  f162e64:	55a0000a */ 	bnezl	$t5,.L0f162e90
/*  f162e68:	3c01c3fa */ 	lui	$at,0xc3fa
/*  f162e6c:	0fc2d5ee */ 	jal	currentPlayerGetLodScaleZ
/*  f162e70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162e74:	3c01c3fa */ 	lui	$at,0xc3fa
/*  f162e78:	44814000 */ 	mtc1	$at,$f8
/*  f162e7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162e80:	46004283 */ 	div.s	$f10,$f8,$f0
/*  f162e84:	10000005 */ 	beqz	$zero,.L0f162e9c
/*  f162e88:	e6ca002c */ 	swc1	$f10,0x2c($s6)
/*  f162e8c:	3c01c3fa */ 	lui	$at,0xc3fa
.L0f162e90:
/*  f162e90:	44818000 */ 	mtc1	$at,$f16
/*  f162e94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162e98:	e6d0002c */ 	swc1	$f16,0x2c($s6)
.L0f162e9c:
/*  f162e9c:	44800000 */ 	mtc1	$zero,$f0
/*  f162ea0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162ea4:	e7a00094 */ 	swc1	$f0,0x94($sp)
/*  f162ea8:	e7a00098 */ 	swc1	$f0,0x98($sp)
/*  f162eac:	c6d2002c */ 	lwc1	$f18,0x2c($s6)
/*  f162eb0:	0fc2d5de */ 	jal	currentPlayerGetUnk174c
/*  f162eb4:	e7b2009c */ 	swc1	$f18,0x9c($sp)
/*  f162eb8:	00402025 */ 	or	$a0,$v0,$zero
/*  f162ebc:	0c0056d9 */ 	jal	func00015b64
/*  f162ec0:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f162ec4:	c7a40094 */ 	lwc1	$f4,0x94($sp)
/*  f162ec8:	3c047f1b */ 	lui	$a0,%hi(var7f1b75ac)
/*  f162ecc:	3c058008 */ 	lui	$a1,%hi(var8007fcb0)
/*  f162ed0:	e6c40018 */ 	swc1	$f4,0x18($s6)
/*  f162ed4:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f162ed8:	24a5fcb0 */ 	addiu	$a1,$a1,%lo(var8007fcb0)
/*  f162edc:	248475ac */ 	addiu	$a0,$a0,%lo(var7f1b75ac)
/*  f162ee0:	e6c6001c */ 	swc1	$f6,0x1c($s6)
/*  f162ee4:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f162ee8:	0c0036cc */ 	jal	func0000db30
/*  f162eec:	e6c80020 */ 	swc1	$f8,0x20($s6)
/*  f162ef0:	0fc59570 */ 	jal	stageGetCurrent
/*  f162ef4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f162ef8:	844e002e */ 	lh	$t6,0x2e($v0)
/*  f162efc:	3c148008 */ 	lui	$s4,%hi(var8007fc2c)
/*  f162f00:	2694fc2c */ 	addiu	$s4,$s4,%lo(var8007fc2c)
/*  f162f04:	448e5000 */ 	mtc1	$t6,$f10
/*  f162f08:	3c018008 */ 	lui	$at,%hi(var8007fc30)
/*  f162f0c:	3c06800a */ 	lui	$a2,%hi(var800a4640)
/*  f162f10:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f162f14:	24c64640 */ 	addiu	$a2,$a2,%lo(var800a4640)
/*  f162f18:	3c17800a */ 	lui	$s7,%hi(var800a4ce4+0x2)
/*  f162f1c:	3c1e800a */ 	lui	$s8,%hi(var800a4ce4)
/*  f162f20:	27de4ce4 */ 	addiu	$s8,$s8,%lo(var800a4ce4)
/*  f162f24:	26f74ce6 */ 	addiu	$s7,$s7,%lo(var800a4ce4+0x2)
/*  f162f28:	e6d00024 */ 	swc1	$f16,0x24($s6)
/*  f162f2c:	84580030 */ 	lh	$t8,0x30($v0)
/*  f162f30:	844f002e */ 	lh	$t7,0x2e($v0)
/*  f162f34:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f162f38:	44983000 */ 	mtc1	$t8,$f6
/*  f162f3c:	448f9000 */ 	mtc1	$t7,$f18
/*  f162f40:	240800ff */ 	addiu	$t0,$zero,0xff
/*  f162f44:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f162f48:	240d7fff */ 	addiu	$t5,$zero,0x7fff
/*  f162f4c:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f162f50:	2413008c */ 	addiu	$s3,$zero,0x8c
/*  f162f54:	3c15800a */ 	lui	$s5,%hi(g_RoomPtrs)
/*  f162f58:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f162f5c:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f162f60:	e6ca0028 */ 	swc1	$f10,0x28($s6)
/*  f162f64:	c6d20028 */ 	lwc1	$f18,0x28($s6)
/*  f162f68:	c7b00094 */ 	lwc1	$f16,0x94($sp)
/*  f162f6c:	c7a40098 */ 	lwc1	$f4,0x98($sp)
/*  f162f70:	87a9007c */ 	lh	$t1,0x7c($sp)
/*  f162f74:	46128180 */ 	add.s	$f6,$f16,$f18
/*  f162f78:	c7b2009c */ 	lwc1	$f18,0x9c($sp)
/*  f162f7c:	87aa007e */ 	lh	$t2,0x7e($sp)
/*  f162f80:	87ab0080 */ 	lh	$t3,0x80($sp)
/*  f162f84:	e7a600ac */ 	swc1	$f6,0xac($sp)
/*  f162f88:	c6c80028 */ 	lwc1	$f8,0x28($s6)
/*  f162f8c:	87ac0082 */ 	lh	$t4,0x82($sp)
/*  f162f90:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f162f94:	e7aa00b0 */ 	swc1	$f10,0xb0($sp)
/*  f162f98:	c6c60028 */ 	lwc1	$f6,0x28($s6)
/*  f162f9c:	46069200 */ 	add.s	$f8,$f18,$f6
/*  f162fa0:	e7a800b4 */ 	swc1	$f8,0xb4($sp)
/*  f162fa4:	c6ca0028 */ 	lwc1	$f10,0x28($s6)
/*  f162fa8:	460a8181 */ 	sub.s	$f6,$f16,$f10
/*  f162fac:	e7a600a0 */ 	swc1	$f6,0xa0($sp)
/*  f162fb0:	c6c80028 */ 	lwc1	$f8,0x28($s6)
/*  f162fb4:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f162fb8:	e7aa00a4 */ 	swc1	$f10,0xa4($sp)
/*  f162fbc:	c6c60028 */ 	lwc1	$f6,0x28($s6)
/*  f162fc0:	ae800000 */ 	sw	$zero,0x0($s4)
/*  f162fc4:	ac20fc30 */ 	sw	$zero,%lo(var8007fc30)($at)
/*  f162fc8:	8e0402bc */ 	lw	$a0,0x2bc($s0)
/*  f162fcc:	46069201 */ 	sub.s	$f8,$f18,$f6
/*  f162fd0:	a4d902d0 */ 	sh	$t9,0x2d0($a2)
/*  f162fd4:	28810002 */ 	slti	$at,$a0,0x2
/*  f162fd8:	a0c802d3 */ 	sb	$t0,0x2d3($a2)
/*  f162fdc:	e7a800a8 */ 	swc1	$f8,0xa8($sp)
/*  f162fe0:	a6e00000 */ 	sh	$zero,0x0($s7)
/*  f162fe4:	a7cd0000 */ 	sh	$t5,0x0($s8)
/*  f162fe8:	e7b00088 */ 	swc1	$f16,0x88($sp)
/*  f162fec:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f162ff0:	a4c902d4 */ 	sh	$t1,0x2d4($a2)
/*  f162ff4:	e7b20090 */ 	swc1	$f18,0x90($sp)
/*  f162ff8:	a4ca02d6 */ 	sh	$t2,0x2d6($a2)
/*  f162ffc:	a4cb02d8 */ 	sh	$t3,0x2d8($a2)
/*  f163000:	142000a5 */ 	bnez	$at,.L0f163298
/*  f163004:	a4cc02da */ 	sh	$t4,0x2da($a2)
/*  f163008:	3c013f00 */ 	lui	$at,0x3f00
/*  f16300c:	4481a000 */ 	mtc1	$at,$f20
/*  f163010:	26b54928 */ 	addiu	$s5,$s5,%lo(g_RoomPtrs)
.L0f163014:
/*  f163014:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f163018:	c7aa00ac */ 	lwc1	$f10,0xac($sp)
/*  f16301c:	c7b000a0 */ 	lwc1	$f16,0xa0($sp)
/*  f163020:	01d38021 */ 	addu	$s0,$t6,$s3
/*  f163024:	c6060018 */ 	lwc1	$f6,0x18($s0)
/*  f163028:	4606503c */ 	c.lt.s	$f10,$f6
/*  f16302c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163030:	45030096 */ 	bc1tl	.L0f16328c
/*  f163034:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f163038:	c6080024 */ 	lwc1	$f8,0x24($s0)
/*  f16303c:	c7a400b4 */ 	lwc1	$f4,0xb4($sp)
/*  f163040:	4610403c */ 	c.lt.s	$f8,$f16
/*  f163044:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163048:	45030090 */ 	bc1tl	.L0f16328c
/*  f16304c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f163050:	c6120020 */ 	lwc1	$f18,0x20($s0)
/*  f163054:	c7a600a8 */ 	lwc1	$f6,0xa8($sp)
/*  f163058:	4612203c */ 	c.lt.s	$f4,$f18
/*  f16305c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163060:	4503008a */ 	bc1tl	.L0f16328c
/*  f163064:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f163068:	c60a002c */ 	lwc1	$f10,0x2c($s0)
/*  f16306c:	c7a800b0 */ 	lwc1	$f8,0xb0($sp)
/*  f163070:	4606503c */ 	c.lt.s	$f10,$f6
/*  f163074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163078:	45030084 */ 	bc1tl	.L0f16328c
/*  f16307c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f163080:	c610001c */ 	lwc1	$f16,0x1c($s0)
/*  f163084:	c7b200a4 */ 	lwc1	$f18,0xa4($sp)
/*  f163088:	4610403c */ 	c.lt.s	$f8,$f16
/*  f16308c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163090:	4503007e */ 	bc1tl	.L0f16328c
/*  f163094:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f163098:	c6040028 */ 	lwc1	$f4,0x28($s0)
/*  f16309c:	4612203c */ 	c.lt.s	$f4,$f18
/*  f1630a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1630a4:	45030079 */ 	bc1tl	.L0f16328c
/*  f1630a8:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1630ac:	8e830000 */ 	lw	$v1,0x0($s4)
/*  f1630b0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1630b4:	2861003c */ 	slti	$at,$v1,0x3c
/*  f1630b8:	10200073 */ 	beqz	$at,.L0f163288
/*  f1630bc:	0003c880 */ 	sll	$t9,$v1,0x2
/*  f1630c0:	960f0000 */ 	lhu	$t7,0x0($s0)
/*  f1630c4:	0323c823 */ 	subu	$t9,$t9,$v1
/*  f1630c8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1630cc:	35f80004 */ 	ori	$t8,$t7,0x4
/*  f1630d0:	a6180000 */ 	sh	$t8,0x0($s0)
/*  f1630d4:	00d98821 */ 	addu	$s1,$a2,$t9
/*  f1630d8:	a6320000 */ 	sh	$s2,0x0($s1)
/*  f1630dc:	0fc55f6c */ 	jal	func0f157db0
/*  f1630e0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1630e4:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f1630e8:	c7a40088 */ 	lwc1	$f4,0x88($sp)
/*  f1630ec:	01138021 */ 	addu	$s0,$t0,$s3
/*  f1630f0:	c60a0018 */ 	lwc1	$f10,0x18($s0)
/*  f1630f4:	c6060024 */ 	lwc1	$f6,0x24($s0)
/*  f1630f8:	c612001c */ 	lwc1	$f18,0x1c($s0)
/*  f1630fc:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f163100:	c60a0028 */ 	lwc1	$f10,0x28($s0)
/*  f163104:	46144402 */ 	mul.s	$f16,$f8,$f20
/*  f163108:	460a9180 */ 	add.s	$f6,$f18,$f10
/*  f16310c:	c612002c */ 	lwc1	$f18,0x2c($s0)
/*  f163110:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f163114:	46048001 */ 	sub.s	$f0,$f16,$f4
/*  f163118:	c6040020 */ 	lwc1	$f4,0x20($s0)
/*  f16311c:	c7b0008c */ 	lwc1	$f16,0x8c($sp)
/*  f163120:	46122280 */ 	add.s	$f10,$f4,$f18
/*  f163124:	46104081 */ 	sub.s	$f2,$f8,$f16
/*  f163128:	46145182 */ 	mul.s	$f6,$f10,$f20
/*  f16312c:	c7a80090 */ 	lwc1	$f8,0x90($sp)
/*  f163130:	46000402 */ 	mul.s	$f16,$f0,$f0
/*  f163134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163138:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f16313c:	46083381 */ 	sub.s	$f14,$f6,$f8
/*  f163140:	460e7282 */ 	mul.s	$f10,$f14,$f14
/*  f163144:	46048480 */ 	add.s	$f18,$f16,$f4
/*  f163148:	0c012974 */ 	jal	sqrtf
/*  f16314c:	460a9300 */ 	add.s	$f12,$f18,$f10
/*  f163150:	3c0142c8 */ 	lui	$at,0x42c8
/*  f163154:	44813000 */ 	mtc1	$at,$f6
/*  f163158:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f16315c:	3c038008 */ 	lui	$v1,%hi(var8007fc30)
/*  f163160:	46060203 */ 	div.s	$f8,$f0,$f6
/*  f163164:	3c014f00 */ 	lui	$at,0x4f00
/*  f163168:	2463fc30 */ 	addiu	$v1,$v1,%lo(var8007fc30)
/*  f16316c:	4449f800 */ 	cfc1	$t1,$31
/*  f163170:	44caf800 */ 	ctc1	$t2,$31
/*  f163174:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163178:	46004424 */ 	cvt.w.s	$f16,$f8
/*  f16317c:	444af800 */ 	cfc1	$t2,$31
/*  f163180:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163184:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f163188:	51400013 */ 	beqzl	$t2,.L0f1631d8
/*  f16318c:	440a8000 */ 	mfc1	$t2,$f16
/*  f163190:	44818000 */ 	mtc1	$at,$f16
/*  f163194:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f163198:	46104401 */ 	sub.s	$f16,$f8,$f16
/*  f16319c:	44caf800 */ 	ctc1	$t2,$31
/*  f1631a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1631a4:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f1631a8:	444af800 */ 	cfc1	$t2,$31
/*  f1631ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1631b0:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f1631b4:	15400005 */ 	bnez	$t2,.L0f1631cc
/*  f1631b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1631bc:	440a8000 */ 	mfc1	$t2,$f16
/*  f1631c0:	3c018000 */ 	lui	$at,0x8000
/*  f1631c4:	10000007 */ 	beqz	$zero,.L0f1631e4
/*  f1631c8:	01415025 */ 	or	$t2,$t2,$at
.L0f1631cc:
/*  f1631cc:	10000005 */ 	beqz	$zero,.L0f1631e4
/*  f1631d0:	240affff */ 	addiu	$t2,$zero,-1
/*  f1631d4:	440a8000 */ 	mfc1	$t2,$f16
.L0f1631d8:
/*  f1631d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1631dc:	0540fffb */ 	bltz	$t2,.L0f1631cc
/*  f1631e0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1631e4:
/*  f1631e4:	86eb0000 */ 	lh	$t3,0x0($s7)
/*  f1631e8:	314200ff */ 	andi	$v0,$t2,0xff
/*  f1631ec:	44c9f800 */ 	ctc1	$t1,$31
/*  f1631f0:	0162082a */ 	slt	$at,$t3,$v0
/*  f1631f4:	10200002 */ 	beqz	$at,.L0f163200
/*  f1631f8:	a22a0003 */ 	sb	$t2,0x3($s1)
/*  f1631fc:	a6e20000 */ 	sh	$v0,0x0($s7)
.L0f163200:
/*  f163200:	87cc0000 */ 	lh	$t4,0x0($s8)
/*  f163204:	004c082a */ 	slt	$at,$v0,$t4
/*  f163208:	50200003 */ 	beqzl	$at,.L0f163218
/*  f16320c:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f163210:	a7c20000 */ 	sh	$v0,0x0($s8)
/*  f163214:	8e990000 */ 	lw	$t9,0x0($s4)
.L0f163218:
/*  f163218:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f16321c:	87ad007c */ 	lh	$t5,0x7c($sp)
/*  f163220:	87ae007e */ 	lh	$t6,0x7e($sp)
/*  f163224:	87af0080 */ 	lh	$t7,0x80($sp)
/*  f163228:	87b80082 */ 	lh	$t8,0x82($sp)
/*  f16322c:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f163230:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f163234:	ae880000 */ 	sw	$t0,0x0($s4)
/*  f163238:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f16323c:	a62d0004 */ 	sh	$t5,0x4($s1)
/*  f163240:	a62e0006 */ 	sh	$t6,0x6($s1)
/*  f163244:	a62f0008 */ 	sh	$t7,0x8($s1)
/*  f163248:	a638000a */ 	sh	$t8,0xa($s1)
/*  f16324c:	8ecc1ba0 */ 	lw	$t4,0x1ba0($s6)
/*  f163250:	8eab0000 */ 	lw	$t3,0x0($s5)
/*  f163254:	3c04800a */ 	lui	$a0,%hi(g_Vars+0x2bc)
/*  f163258:	000c68c0 */ 	sll	$t5,$t4,0x3
/*  f16325c:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f163260:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f163264:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f163268:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f16326c:	016d1021 */ 	addu	$v0,$t3,$t5
/*  f163270:	944e0000 */ 	lhu	$t6,0x0($v0)
/*  f163274:	3c06800a */ 	lui	$a2,%hi(var800a4640)
/*  f163278:	24c64640 */ 	addiu	$a2,$a2,%lo(var800a4640)
/*  f16327c:	35cf0004 */ 	ori	$t7,$t6,0x4
/*  f163280:	a44f0000 */ 	sh	$t7,0x0($v0)
/*  f163284:	8c84a27c */ 	lw	$a0,%lo(g_Vars+0x2bc)($a0)
.L0f163288:
/*  f163288:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f16328c:
/*  f16328c:	0244082a */ 	slt	$at,$s2,$a0
/*  f163290:	1420ff60 */ 	bnez	$at,.L0f163014
/*  f163294:	2673008c */ 	addiu	$s3,$s3,0x8c
.L0f163298:
/*  f163298:	0fc58e5f */ 	jal	func0f16397c
/*  f16329c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1632a0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f1632a4:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f1632a8:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f1632ac:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f1632b0:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f1632b4:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f1632b8:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f1632bc:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f1632c0:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f1632c4:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f1632c8:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f1632cc:	03e00008 */ 	jr	$ra
/*  f1632d0:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);

GLOBAL_ASM(
glabel func0f1632d4
/*  f1632d4:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f1632d8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1632dc:	00058400 */ 	sll	$s0,$a1,0x10
/*  f1632e0:	00107403 */ 	sra	$t6,$s0,0x10
/*  f1632e4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1632e8:	3c1f800a */ 	lui	$ra,%hi(g_RoomPtrs)
/*  f1632ec:	000e68c0 */ 	sll	$t5,$t6,0x3
/*  f1632f0:	27ff4928 */ 	addiu	$ra,$ra,%lo(g_RoomPtrs)
/*  f1632f4:	01ae6821 */ 	addu	$t5,$t5,$t6
/*  f1632f8:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f1632fc:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f163300:	01ae6823 */ 	subu	$t5,$t5,$t6
/*  f163304:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f163308:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f16330c:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f163310:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f163314:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f163318:	01ed1021 */ 	addu	$v0,$t7,$t5
/*  f16331c:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f163320:	01c08025 */ 	or	$s0,$t6,$zero
/*  f163324:	87ae004a */ 	lh	$t6,0x4a($sp)
/*  f163328:	33190001 */ 	andi	$t9,$t8,0x1
/*  f16332c:	17200079 */ 	bnez	$t9,.L0f163514
/*  f163330:	29c10002 */ 	slti	$at,$t6,0x2
/*  f163334:	1420000e */ 	bnez	$at,.L0f163370
/*  f163338:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x2c)
/*  f16333c:	90440004 */ 	lbu	$a0,0x4($v0)
/*  f163340:	288100ff */ 	slti	$at,$a0,0xff
/*  f163344:	10200006 */ 	beqz	$at,.L0f163360
/*  f163348:	00801825 */ 	or	$v1,$a0,$zero
/*  f16334c:	248f0001 */ 	addiu	$t7,$a0,0x1
/*  f163350:	a04f0004 */ 	sb	$t7,0x4($v0)
/*  f163354:	8ff80000 */ 	lw	$t8,0x0($ra)
/*  f163358:	030d1021 */ 	addu	$v0,$t8,$t5
/*  f16335c:	90430004 */ 	lbu	$v1,0x4($v0)
.L0f163360:
/*  f163360:	8f399fec */ 	lw	$t9,%lo(g_Vars+0x2c)($t9)
/*  f163364:	0323082a */ 	slt	$at,$t9,$v1
/*  f163368:	5420006b */ 	bnezl	$at,.L0f163518
/*  f16336c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f163370:
/*  f163370:	904e0006 */ 	lbu	$t6,0x6($v0)
/*  f163374:	11c0002c */ 	beqz	$t6,.L0f163428
/*  f163378:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16337c:	904f0007 */ 	lbu	$t7,0x7($v0)
/*  f163380:	3c0c800a */ 	lui	$t4,%hi(var800a4cf0)
/*  f163384:	258c4cf0 */ 	addiu	$t4,$t4,%lo(var800a4cf0)
/*  f163388:	11e00027 */ 	beqz	$t7,.L0f163428
/*  f16338c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163390:	85860004 */ 	lh	$a2,0x4($t4)
/*  f163394:	85890002 */ 	lh	$t1,0x2($t4)
/*  f163398:	240b00fa */ 	addiu	$t3,$zero,0xfa
/*  f16339c:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f1633a0:	0306c023 */ 	subu	$t8,$t8,$a2
/*  f1633a4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f1633a8:	01983821 */ 	addu	$a3,$t4,$t8
/*  f1633ac:	10c9001e */ 	beq	$a2,$t1,.L0f163428
/*  f1633b0:	24e70010 */ 	addiu	$a3,$a3,0x10
/*  f1633b4:	3c0a800a */ 	lui	$t2,%hi(var800a4d00)
/*  f1633b8:	254a4d00 */ 	addiu	$t2,$t2,%lo(var800a4d00)
/*  f1633bc:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f1633c0:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f1633c4:	84f90000 */ 	lh	$t9,0x0($a3)
.L0f1633c8:
/*  f1633c8:	00001825 */ 	or	$v1,$zero,$zero
/*  f1633cc:	00e01025 */ 	or	$v0,$a3,$zero
/*  f1633d0:	1619000f */ 	bne	$s0,$t9,.L0f163410
/*  f1633d4:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f1633d8:
/*  f1633d8:	844e0002 */ 	lh	$t6,0x2($v0)
/*  f1633dc:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f1633e0:	14ae0009 */ 	bne	$a1,$t6,.L0f163408
/*  f1633e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1633e8:	24e40010 */ 	addiu	$a0,$a3,0x10
/*  f1633ec:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f1633f0:	0fc5758f */ 	jal	func0f15d63c
/*  f1633f4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f1633f8:	8fa20024 */ 	lw	$v0,0x24($sp)
/*  f1633fc:	87af0042 */ 	lh	$t7,0x42($sp)
/*  f163400:	10000044 */ 	beqz	$zero,.L0f163514
/*  f163404:	a44f0002 */ 	sh	$t7,0x2($v0)
.L0f163408:
/*  f163408:	1464fff3 */ 	bne	$v1,$a0,.L0f1633d8
/*  f16340c:	24420002 */ 	addiu	$v0,$v0,0x2
.L0f163410:
/*  f163410:	14cb0003 */ 	bne	$a2,$t3,.L0f163420
/*  f163414:	24e70018 */ 	addiu	$a3,$a3,0x18
/*  f163418:	00003025 */ 	or	$a2,$zero,$zero
/*  f16341c:	01403825 */ 	or	$a3,$t2,$zero
.L0f163420:
/*  f163420:	54c9ffe9 */ 	bnel	$a2,$t1,.L0f1633c8
/*  f163424:	84f90000 */ 	lh	$t9,0x0($a3)
.L0f163428:
/*  f163428:	3c0c800a */ 	lui	$t4,%hi(var800a4cf0)
/*  f16342c:	258c4cf0 */ 	addiu	$t4,$t4,%lo(var800a4cf0)
/*  f163430:	85980002 */ 	lh	$t8,0x2($t4)
/*  f163434:	87ae0042 */ 	lh	$t6,0x42($sp)
/*  f163438:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f16343c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f163440:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f163444:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f163448:	01993821 */ 	addu	$a3,$t4,$t9
/*  f16344c:	a4f00010 */ 	sh	$s0,0x10($a3)
/*  f163450:	a4ee0012 */ 	sh	$t6,0x12($a3)
/*  f163454:	87af004a */ 	lh	$t7,0x4a($sp)
/*  f163458:	240b00fa */ 	addiu	$t3,$zero,0xfa
/*  f16345c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f163460:	a0ef001c */ 	sb	$t7,0x1c($a3)
/*  f163464:	8ff80000 */ 	lw	$t8,0x0($ra)
/*  f163468:	24030005 */ 	addiu	$v1,$zero,0x5
/*  f16346c:	030dc821 */ 	addu	$t9,$t8,$t5
/*  f163470:	872e000e */ 	lh	$t6,0xe($t9)
/*  f163474:	a4ee001e */ 	sh	$t6,0x1e($a3)
/*  f163478:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f16347c:	01edc021 */ 	addu	$t8,$t7,$t5
/*  f163480:	83190005 */ 	lb	$t9,0x5($t8)
/*  f163484:	a0f9001d */ 	sb	$t9,0x1d($a3)
/*  f163488:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f16348c:	85cf0000 */ 	lh	$t7,0x0($t6)
/*  f163490:	a4ef0020 */ 	sh	$t7,0x20($a3)
/*  f163494:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f163498:	87190002 */ 	lh	$t9,0x2($t8)
/*  f16349c:	a4f90022 */ 	sh	$t9,0x22($a3)
/*  f1634a0:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f1634a4:	85cf0004 */ 	lh	$t7,0x4($t6)
/*  f1634a8:	a4ef0024 */ 	sh	$t7,0x24($a3)
/*  f1634ac:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f1634b0:	87190006 */ 	lh	$t9,0x6($t8)
/*  f1634b4:	a4f90026 */ 	sh	$t9,0x26($a3)
/*  f1634b8:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f1634bc:	01cd1021 */ 	addu	$v0,$t6,$t5
/*  f1634c0:	904f0006 */ 	lbu	$t7,0x6($v0)
/*  f1634c4:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f1634c8:	a0580006 */ 	sb	$t8,0x6($v0)
/*  f1634cc:	24e20012 */ 	addiu	$v0,$a3,0x12
.L0f1634d0:
/*  f1634d0:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1634d4:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f1634d8:	14c3fffd */ 	bne	$a2,$v1,.L0f1634d0
/*  f1634dc:	a4450000 */ 	sh	$a1,0x0($v0)
/*  f1634e0:	85990002 */ 	lh	$t9,0x2($t4)
/*  f1634e4:	272e0001 */ 	addiu	$t6,$t9,0x1
/*  f1634e8:	a58e0002 */ 	sh	$t6,0x2($t4)
/*  f1634ec:	85890002 */ 	lh	$t1,0x2($t4)
/*  f1634f0:	55690004 */ 	bnel	$t3,$t1,.L0f163504
/*  f1634f4:	858f0004 */ 	lh	$t7,0x4($t4)
/*  f1634f8:	a5800002 */ 	sh	$zero,0x2($t4)
/*  f1634fc:	85890002 */ 	lh	$t1,0x2($t4)
/*  f163500:	858f0004 */ 	lh	$t7,0x4($t4)
.L0f163504:
/*  f163504:	2538ffff */ 	addiu	$t8,$t1,-1
/*  f163508:	55e90003 */ 	bnel	$t7,$t1,.L0f163518
/*  f16350c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f163510:	a5980002 */ 	sh	$t8,0x2($t4)
.L0f163514:
/*  f163514:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f163518:
/*  f163518:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f16351c:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f163520:	03e00008 */ 	jr	$ra
/*  f163524:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f163528
/*  f163528:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f16352c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f163530:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f163534:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f163538:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f16353c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f163540:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f163544:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f163548:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f16354c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f163550:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f163554:	848f0000 */ 	lh	$t7,0x0($a0)
/*  f163558:	3c0e800a */ 	lui	$t6,%hi(g_RoomPtrs)
/*  f16355c:	8dce4928 */ 	lw	$t6,%lo(g_RoomPtrs)($t6)
/*  f163560:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f163564:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f163568:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f16356c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f163570:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f163574:	01d81021 */ 	addu	$v0,$t6,$t8
/*  f163578:	90590006 */ 	lbu	$t9,0x6($v0)
/*  f16357c:	3c05800a */ 	lui	$a1,%hi(var800a4cf0)
/*  f163580:	24a54cf0 */ 	addiu	$a1,$a1,%lo(var800a4cf0)
/*  f163584:	2728ffff */ 	addiu	$t0,$t9,-1
/*  f163588:	a0480006 */ 	sb	$t0,0x6($v0)
/*  f16358c:	84a90000 */ 	lh	$t1,0x0($a1)
/*  f163590:	3c17800a */ 	lui	$s7,%hi(g_Vars+0x284)
/*  f163594:	00808825 */ 	or	$s1,$a0,$zero
/*  f163598:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f16359c:	a4aa0000 */ 	sh	$t2,0x0($a1)
/*  f1635a0:	908b000d */ 	lbu	$t3,0xd($a0)
/*  f1635a4:	8ef7a244 */ 	lw	$s7,%lo(g_Vars+0x284)($s7)
/*  f1635a8:	0000a025 */ 	or	$s4,$zero,$zero
/*  f1635ac:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f1635b0:	196000b9 */ 	blez	$t3,.L0f163898
/*  f1635b4:	26f71bb0 */ 	addiu	$s7,$s7,7088
/*  f1635b8:	0000a825 */ 	or	$s5,$zero,$zero
/*  f1635bc:	27be0054 */ 	addiu	$s8,$sp,0x54
/*  f1635c0:	862d000e */ 	lh	$t5,0xe($s1)
.L0f1635c4:
/*  f1635c4:	3c0c800a */ 	lui	$t4,%hi(var800a4ce0)
/*  f1635c8:	8d8c4ce0 */ 	lw	$t4,%lo(var800a4ce0)($t4)
/*  f1635cc:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f1635d0:	3c06800a */ 	lui	$a2,%hi(g_Portals)
/*  f1635d4:	018f7021 */ 	addu	$t6,$t4,$t7
/*  f1635d8:	01d5c021 */ 	addu	$t8,$t6,$s5
/*  f1635dc:	87130000 */ 	lh	$s3,0x0($t8)
/*  f1635e0:	24c64cec */ 	addiu	$a2,$a2,%lo(g_Portals)
/*  f1635e4:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f1635e8:	3c058008 */ 	lui	$a1,%hi(var8007fc3c)
/*  f1635ec:	00132100 */ 	sll	$a0,$s3,0x4
/*  f1635f0:	24a5fc3c */ 	addiu	$a1,$a1,%lo(var8007fc3c)
/*  f1635f4:	03241821 */ 	addu	$v1,$t9,$a0
/*  f1635f8:	94690000 */ 	lhu	$t1,0x0($v1)
/*  f1635fc:	94a80000 */ 	lhu	$t0,0x0($a1)
/*  f163600:	00135080 */ 	sll	$t2,$s3,0x2
/*  f163604:	3c0b800a */ 	lui	$t3,%hi(var800a4ccc)
/*  f163608:	11090026 */ 	beq	$t0,$t1,.L0f1636a4
/*  f16360c:	01535021 */ 	addu	$t2,$t2,$s3
/*  f163610:	8d6b4ccc */ 	lw	$t3,%lo(var800a4ccc)($t3)
/*  f163614:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f163618:	c6e60000 */ 	lwc1	$f6,0x0($s7)
/*  f16361c:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f163620:	c4440000 */ 	lwc1	$f4,0x0($v0)
/*  f163624:	c44a0004 */ 	lwc1	$f10,0x4($v0)
/*  f163628:	c6f00004 */ 	lwc1	$f16,0x4($s7)
/*  f16362c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f163630:	c6e60008 */ 	lwc1	$f6,0x8($s7)
/*  f163634:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f163638:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f16363c:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f163640:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f163644:	46124100 */ 	add.s	$f4,$f8,$f18
/*  f163648:	c448000c */ 	lwc1	$f8,0xc($v0)
/*  f16364c:	46048000 */ 	add.s	$f0,$f16,$f4
/*  f163650:	4608003c */ 	c.lt.s	$f0,$f8
/*  f163654:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163658:	45020004 */ 	bc1fl	.L0f16366c
/*  f16365c:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f163660:	1000000a */ 	beqz	$zero,.L0f16368c
/*  f163664:	a46d0002 */ 	sh	$t5,0x2($v1)
/*  f163668:	c4520010 */ 	lwc1	$f18,0x10($v0)
.L0f16366c:
/*  f16366c:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f163670:	4600903c */ 	c.lt.s	$f18,$f0
/*  f163674:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163678:	45020004 */ 	bc1fl	.L0f16368c
/*  f16367c:	a46c0002 */ 	sh	$t4,0x2($v1)
/*  f163680:	10000002 */ 	beqz	$zero,.L0f16368c
/*  f163684:	a4600002 */ 	sh	$zero,0x2($v1)
/*  f163688:	a46c0002 */ 	sh	$t4,0x2($v1)
.L0f16368c:
/*  f16368c:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f163690:	94af0000 */ 	lhu	$t7,0x0($a1)
/*  f163694:	01c4c021 */ 	addu	$t8,$t6,$a0
/*  f163698:	a70f0000 */ 	sh	$t7,0x0($t8)
/*  f16369c:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f1636a0:	03241821 */ 	addu	$v1,$t9,$a0
.L0f1636a4:
/*  f1636a4:	3c08800a */ 	lui	$t0,%hi(g_PortalSomethings)
/*  f1636a8:	8d084cc8 */ 	lw	$t0,%lo(g_PortalSomethings)($t0)
/*  f1636ac:	001390c0 */ 	sll	$s2,$s3,0x3
/*  f1636b0:	86290000 */ 	lh	$t1,0x0($s1)
/*  f1636b4:	01122821 */ 	addu	$a1,$t0,$s2
/*  f1636b8:	84a20002 */ 	lh	$v0,0x2($a1)
/*  f1636bc:	84640002 */ 	lh	$a0,0x2($v1)
/*  f1636c0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1636c4:	15220008 */ 	bne	$t1,$v0,.L0f1636e8
/*  f1636c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1636cc:	14800004 */ 	bnez	$a0,.L0f1636e0
/*  f1636d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1636d4:	9222000d */ 	lbu	$v0,0xd($s1)
/*  f1636d8:	1000006b */ 	beqz	$zero,.L0f163888
/*  f1636dc:	00021840 */ 	sll	$v1,$v0,0x1
.L0f1636e0:
/*  f1636e0:	10000008 */ 	beqz	$zero,.L0f163704
/*  f1636e4:	84b00004 */ 	lh	$s0,0x4($a1)
.L0f1636e8:
/*  f1636e8:	14810004 */ 	bne	$a0,$at,.L0f1636fc
/*  f1636ec:	00028400 */ 	sll	$s0,$v0,0x10
/*  f1636f0:	9222000d */ 	lbu	$v0,0xd($s1)
/*  f1636f4:	10000064 */ 	beqz	$zero,.L0f163888
/*  f1636f8:	00021840 */ 	sll	$v1,$v0,0x1
.L0f1636fc:
/*  f1636fc:	00105403 */ 	sra	$t2,$s0,0x10
/*  f163700:	01408025 */ 	or	$s0,$t2,$zero
.L0f163704:
/*  f163704:	12d00017 */ 	beq	$s6,$s0,.L0f163764
/*  f163708:	0014102b */ 	sltu	$v0,$zero,$s4
/*  f16370c:	10400012 */ 	beqz	$v0,.L0f163758
/*  f163710:	0000a025 */ 	or	$s4,$zero,$zero
/*  f163714:	02c02025 */ 	or	$a0,$s6,$zero
/*  f163718:	9225000c */ 	lbu	$a1,0xc($s1)
/*  f16371c:	0fc55fa5 */ 	jal	func0f157e94
/*  f163720:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f163724:	9226000c */ 	lbu	$a2,0xc($s1)
/*  f163728:	00162c00 */ 	sll	$a1,$s6,0x10
/*  f16372c:	00055c03 */ 	sra	$t3,$a1,0x10
/*  f163730:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f163734:	00066c00 */ 	sll	$t5,$a2,0x10
/*  f163738:	000d3403 */ 	sra	$a2,$t5,0x10
/*  f16373c:	01602825 */ 	or	$a1,$t3,$zero
/*  f163740:	86240000 */ 	lh	$a0,0x0($s1)
/*  f163744:	0fc58cb5 */ 	jal	func0f1632d4
/*  f163748:	27a7005c */ 	addiu	$a3,$sp,0x5c
/*  f16374c:	3c0e800a */ 	lui	$t6,%hi(g_PortalSomethings)
/*  f163750:	8dce4cc8 */ 	lw	$t6,%lo(g_PortalSomethings)($t6)
/*  f163754:	01d22821 */ 	addu	$a1,$t6,$s2
.L0f163758:
/*  f163758:	0010b400 */ 	sll	$s6,$s0,0x10
/*  f16375c:	00167c03 */ 	sra	$t7,$s6,0x10
/*  f163760:	01e0b025 */ 	or	$s6,$t7,$zero
.L0f163764:
/*  f163764:	90a20006 */ 	lbu	$v0,0x6($a1)
/*  f163768:	30580001 */ 	andi	$t8,$v0,0x1
/*  f16376c:	13000006 */ 	beqz	$t8,.L0f163788
/*  f163770:	30590004 */ 	andi	$t9,$v0,0x4
/*  f163774:	57200005 */ 	bnezl	$t9,.L0f16378c
/*  f163778:	86280002 */ 	lh	$t0,0x2($s1)
/*  f16377c:	9222000d */ 	lbu	$v0,0xd($s1)
/*  f163780:	10000041 */ 	beqz	$zero,.L0f163888
/*  f163784:	00021840 */ 	sll	$v1,$v0,0x1
.L0f163788:
/*  f163788:	86280002 */ 	lh	$t0,0x2($s1)
.L0f16378c:
/*  f16378c:	5208000f */ 	beql	$s0,$t0,.L0f1637cc
/*  f163790:	9222000d */ 	lbu	$v0,0xd($s1)
/*  f163794:	86290004 */ 	lh	$t1,0x4($s1)
/*  f163798:	5209000c */ 	beql	$s0,$t1,.L0f1637cc
/*  f16379c:	9222000d */ 	lbu	$v0,0xd($s1)
/*  f1637a0:	862a0006 */ 	lh	$t2,0x6($s1)
/*  f1637a4:	520a0009 */ 	beql	$s0,$t2,.L0f1637cc
/*  f1637a8:	9222000d */ 	lbu	$v0,0xd($s1)
/*  f1637ac:	862b0008 */ 	lh	$t3,0x8($s1)
/*  f1637b0:	520b0006 */ 	beql	$s0,$t3,.L0f1637cc
/*  f1637b4:	9222000d */ 	lbu	$v0,0xd($s1)
/*  f1637b8:	862d000a */ 	lh	$t5,0xa($s1)
/*  f1637bc:	304c0002 */ 	andi	$t4,$v0,0x2
/*  f1637c0:	160d0004 */ 	bne	$s0,$t5,.L0f1637d4
/*  f1637c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1637c8:	9222000d */ 	lbu	$v0,0xd($s1)
.L0f1637cc:
/*  f1637cc:	1000002e */ 	beqz	$zero,.L0f163888
/*  f1637d0:	00021840 */ 	sll	$v1,$v0,0x1
.L0f1637d4:
/*  f1637d4:	1180000b */ 	beqz	$t4,.L0f163804
/*  f1637d8:	02602025 */ 	or	$a0,$s3,$zero
/*  f1637dc:	862e0010 */ 	lh	$t6,0x10($s1)
/*  f1637e0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1637e4:	a7ae0054 */ 	sh	$t6,0x54($sp)
/*  f1637e8:	862f0012 */ 	lh	$t7,0x12($s1)
/*  f1637ec:	a7af0056 */ 	sh	$t7,0x56($sp)
/*  f1637f0:	86380014 */ 	lh	$t8,0x14($s1)
/*  f1637f4:	a7b80058 */ 	sh	$t8,0x58($sp)
/*  f1637f8:	86390016 */ 	lh	$t9,0x16($s1)
/*  f1637fc:	10000006 */ 	beqz	$zero,.L0f163818
/*  f163800:	a7b9005a */ 	sh	$t9,0x5a($sp)
.L0f163804:
/*  f163804:	0fc57443 */ 	jal	func0f15d10c
/*  f163808:	03c02825 */ 	or	$a1,$s8,$zero
/*  f16380c:	00022400 */ 	sll	$a0,$v0,0x10
/*  f163810:	00044403 */ 	sra	$t0,$a0,0x10
/*  f163814:	01002025 */ 	or	$a0,$t0,$zero
.L0f163818:
/*  f163818:	10800019 */ 	beqz	$a0,.L0f163880
/*  f16381c:	26250010 */ 	addiu	$a1,$s1,0x10
/*  f163820:	0fc5755c */ 	jal	func0f15d570
/*  f163824:	03c02025 */ 	or	$a0,$s8,$zero
/*  f163828:	87a30054 */ 	lh	$v1,0x54($sp)
/*  f16382c:	87a40058 */ 	lh	$a0,0x58($sp)
/*  f163830:	87a20056 */ 	lh	$v0,0x56($sp)
/*  f163834:	87a5005a */ 	lh	$a1,0x5a($sp)
/*  f163838:	0064082a */ 	slt	$at,$v1,$a0
/*  f16383c:	10200010 */ 	beqz	$at,.L0f163880
/*  f163840:	0045082a */ 	slt	$at,$v0,$a1
/*  f163844:	5020000f */ 	beqzl	$at,.L0f163884
/*  f163848:	9222000d */ 	lbu	$v0,0xd($s1)
/*  f16384c:	56800007 */ 	bnezl	$s4,.L0f16386c
/*  f163850:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*  f163854:	a7a3005c */ 	sh	$v1,0x5c($sp)
/*  f163858:	a7a2005e */ 	sh	$v0,0x5e($sp)
/*  f16385c:	a7a40060 */ 	sh	$a0,0x60($sp)
/*  f163860:	10000004 */ 	beqz	$zero,.L0f163874
/*  f163864:	a7a50062 */ 	sh	$a1,0x62($sp)
/*  f163868:	27a4005c */ 	addiu	$a0,$sp,0x5c
.L0f16386c:
/*  f16386c:	0fc5758f */ 	jal	func0f15d63c
/*  f163870:	03c02825 */ 	or	$a1,$s8,$zero
.L0f163874:
/*  f163874:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f163878:	00144c00 */ 	sll	$t1,$s4,0x10
/*  f16387c:	0009a403 */ 	sra	$s4,$t1,0x10
.L0f163880:
/*  f163880:	9222000d */ 	lbu	$v0,0xd($s1)
.L0f163884:
/*  f163884:	00021840 */ 	sll	$v1,$v0,0x1
.L0f163888:
/*  f163888:	26b50002 */ 	addiu	$s5,$s5,0x2
/*  f16388c:	02a3082a */ 	slt	$at,$s5,$v1
/*  f163890:	5420ff4c */ 	bnezl	$at,.L0f1635c4
/*  f163894:	862d000e */ 	lh	$t5,0xe($s1)
.L0f163898:
/*  f163898:	1280000e */ 	beqz	$s4,.L0f1638d4
/*  f16389c:	02c02025 */ 	or	$a0,$s6,$zero
/*  f1638a0:	9225000c */ 	lbu	$a1,0xc($s1)
/*  f1638a4:	0fc55fa5 */ 	jal	func0f157e94
/*  f1638a8:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f1638ac:	9226000c */ 	lbu	$a2,0xc($s1)
/*  f1638b0:	00162c00 */ 	sll	$a1,$s6,0x10
/*  f1638b4:	00055c03 */ 	sra	$t3,$a1,0x10
/*  f1638b8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1638bc:	00066c00 */ 	sll	$t5,$a2,0x10
/*  f1638c0:	000d3403 */ 	sra	$a2,$t5,0x10
/*  f1638c4:	01602825 */ 	or	$a1,$t3,$zero
/*  f1638c8:	86240000 */ 	lh	$a0,0x0($s1)
/*  f1638cc:	0fc58cb5 */ 	jal	func0f1632d4
/*  f1638d0:	27a7005c */ 	addiu	$a3,$sp,0x5c
.L0f1638d4:
/*  f1638d4:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f1638d8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1638dc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1638e0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1638e4:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f1638e8:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f1638ec:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f1638f0:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f1638f4:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f1638f8:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f1638fc:	03e00008 */ 	jr	$ra
/*  f163900:	27bd0080 */ 	addiu	$sp,$sp,0x80
);

GLOBAL_ASM(
glabel func0f163904
/*  f163904:	3c02800a */ 	lui	$v0,%hi(var800a4cf0)
/*  f163908:	24424cf0 */ 	addiu	$v0,$v0,%lo(var800a4cf0)
/*  f16390c:	84430004 */ 	lh	$v1,0x4($v0)
/*  f163910:	844e0002 */ 	lh	$t6,0x2($v0)
/*  f163914:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f163918:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f16391c:	15c30003 */ 	bne	$t6,$v1,.L0f16392c
/*  f163920:	00037880 */ 	sll	$t7,$v1,0x2
/*  f163924:	10000011 */ 	beqz	$zero,.L0f16396c
/*  f163928:	00001025 */ 	or	$v0,$zero,$zero
.L0f16392c:
/*  f16392c:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f163930:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f163934:	004f2021 */ 	addu	$a0,$v0,$t7
/*  f163938:	0fc58d4a */ 	jal	func0f163528
/*  f16393c:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f163940:	3c02800a */ 	lui	$v0,%hi(var800a4cf0)
/*  f163944:	24424cf0 */ 	addiu	$v0,$v0,%lo(var800a4cf0)
/*  f163948:	84580004 */ 	lh	$t8,0x4($v0)
/*  f16394c:	240100fa */ 	addiu	$at,$zero,0xfa
/*  f163950:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f163954:	a4590004 */ 	sh	$t9,0x4($v0)
/*  f163958:	84480004 */ 	lh	$t0,0x4($v0)
/*  f16395c:	55010003 */ 	bnel	$t0,$at,.L0f16396c
/*  f163960:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f163964:	a4400004 */ 	sh	$zero,0x4($v0)
/*  f163968:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f16396c:
/*  f16396c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f163970:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f163974:	03e00008 */ 	jr	$ra
/*  f163978:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f16397c
/*  f16397c:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f163980:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f163984:	3c17800a */ 	lui	$s7,%hi(g_PortalSomethings)
/*  f163988:	26f74cc8 */ 	addiu	$s7,$s7,%lo(g_PortalSomethings)
/*  f16398c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f163990:	8eea0000 */ 	lw	$t2,0x0($s7)
/*  f163994:	3c108008 */ 	lui	$s0,%hi(var8007fc38)
/*  f163998:	2610fc38 */ 	addiu	$s0,$s0,%lo(var8007fc38)
/*  f16399c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f1639a0:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f1639a4:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f1639a8:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f1639ac:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f1639b0:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f1639b4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1639b8:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f1639bc:	954e0000 */ 	lhu	$t6,0x0($t2)
/*  f1639c0:	0000a825 */ 	or	$s5,$zero,$zero
/*  f1639c4:	3c16800a */ 	lui	$s6,%hi(g_RoomPtrs)
/*  f1639c8:	11c000d0 */ 	beqz	$t6,.L0f163d0c
/*  f1639cc:	01401825 */ 	or	$v1,$t2,$zero
/*  f1639d0:	3c14800a */ 	lui	$s4,%hi(var800a4ce0)
/*  f1639d4:	26944ce0 */ 	addiu	$s4,$s4,%lo(var800a4ce0)
/*  f1639d8:	26d64928 */ 	addiu	$s6,$s6,%lo(g_RoomPtrs)
/*  f1639dc:	2411008c */ 	addiu	$s1,$zero,0x8c
/*  f1639e0:	906f0006 */ 	lbu	$t7,0x6($v1)
.L0f1639e4:
/*  f1639e4:	31f80008 */ 	andi	$t8,$t7,0x8
/*  f1639e8:	570000c4 */ 	bnezl	$t8,.L0f163cfc
/*  f1639ec:	946e0008 */ 	lhu	$t6,0x8($v1)
/*  f1639f0:	84730002 */ 	lh	$s3,0x2($v1)
/*  f1639f4:	8ec50000 */ 	lw	$a1,0x0($s6)
/*  f1639f8:	84720004 */ 	lh	$s2,0x4($v1)
/*  f1639fc:	02710019 */ 	multu	$s3,$s1
/*  f163a00:	00006012 */ 	mflo	$t4
/*  f163a04:	00ac4021 */ 	addu	$t0,$a1,$t4
/*  f163a08:	95020000 */ 	lhu	$v0,0x0($t0)
/*  f163a0c:	30440004 */ 	andi	$a0,$v0,0x4
/*  f163a10:	1080005b */ 	beqz	$a0,.L0f163b80
/*  f163a14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163a18:	02510019 */ 	multu	$s2,$s1
/*  f163a1c:	00005812 */ 	mflo	$t3
/*  f163a20:	00ab3021 */ 	addu	$a2,$a1,$t3
/*  f163a24:	94c70000 */ 	lhu	$a3,0x0($a2)
/*  f163a28:	30f90004 */ 	andi	$t9,$a3,0x4
/*  f163a2c:	17200054 */ 	bnez	$t9,.L0f163b80
/*  f163a30:	34ed0008 */ 	ori	$t5,$a3,0x8
/*  f163a34:	a4cd0000 */ 	sh	$t5,0x0($a2)
/*  f163a38:	8ece0000 */ 	lw	$t6,0x0($s6)
/*  f163a3c:	02402025 */ 	or	$a0,$s2,$zero
/*  f163a40:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f163a44:	01cb3021 */ 	addu	$a2,$t6,$t3
/*  f163a48:	84cf0002 */ 	lh	$t7,0x2($a2)
/*  f163a4c:	15e00007 */ 	bnez	$t7,.L0f163a6c
/*  f163a50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163a54:	94d80000 */ 	lhu	$t8,0x0($a2)
/*  f163a58:	37190020 */ 	ori	$t9,$t8,0x20
/*  f163a5c:	a4d90000 */ 	sh	$t9,0x0($a2)
/*  f163a60:	8e0d0000 */ 	lw	$t5,0x0($s0)
/*  f163a64:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f163a68:	ae0e0000 */ 	sw	$t6,0x0($s0)
.L0f163a6c:
/*  f163a6c:	0fc55f6c */ 	jal	func0f157db0
/*  f163a70:	afab003c */ 	sw	$t3,0x3c($sp)
/*  f163a74:	8eea0000 */ 	lw	$t2,0x0($s7)
/*  f163a78:	8fab003c */ 	lw	$t3,0x3c($sp)
/*  f163a7c:	01551821 */ 	addu	$v1,$t2,$s5
/*  f163a80:	90620006 */ 	lbu	$v0,0x6($v1)
/*  f163a84:	304f0001 */ 	andi	$t7,$v0,0x1
/*  f163a88:	11e0009b */ 	beqz	$t7,.L0f163cf8
/*  f163a8c:	30580004 */ 	andi	$t8,$v0,0x4
/*  f163a90:	5700009a */ 	bnezl	$t8,.L0f163cfc
/*  f163a94:	946e0008 */ 	lhu	$t6,0x8($v1)
/*  f163a98:	8ec50000 */ 	lw	$a1,0x0($s6)
/*  f163a9c:	00004825 */ 	or	$t1,$zero,$zero
/*  f163aa0:	00003825 */ 	or	$a3,$zero,$zero
/*  f163aa4:	00ab3021 */ 	addu	$a2,$a1,$t3
/*  f163aa8:	80c80005 */ 	lb	$t0,0x5($a2)
/*  f163aac:	59000093 */ 	blezl	$t0,.L0f163cfc
/*  f163ab0:	946e0008 */ 	lhu	$t6,0x8($v1)
.L0f163ab4:
/*  f163ab4:	84cd000e */ 	lh	$t5,0xe($a2)
/*  f163ab8:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f163abc:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f163ac0:	000d7040 */ 	sll	$t6,$t5,0x1
/*  f163ac4:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f163ac8:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f163acc:	87020000 */ 	lh	$v0,0x0($t8)
/*  f163ad0:	000268c0 */ 	sll	$t5,$v0,0x3
/*  f163ad4:	014d2021 */ 	addu	$a0,$t2,$t5
/*  f163ad8:	84830002 */ 	lh	$v1,0x2($a0)
/*  f163adc:	16430013 */ 	bne	$s2,$v1,.L0f163b2c
/*  f163ae0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163ae4:	84990004 */ 	lh	$t9,0x4($a0)
/*  f163ae8:	03310019 */ 	multu	$t9,$s1
/*  f163aec:	00007012 */ 	mflo	$t6
/*  f163af0:	00ae1021 */ 	addu	$v0,$a1,$t6
/*  f163af4:	844f0002 */ 	lh	$t7,0x2($v0)
/*  f163af8:	55e0001d */ 	bnezl	$t7,.L0f163b70
/*  f163afc:	0128082a */ 	slt	$at,$t1,$t0
/*  f163b00:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f163b04:	370d0020 */ 	ori	$t5,$t8,0x20
/*  f163b08:	a44d0000 */ 	sh	$t5,0x0($v0)
/*  f163b0c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f163b10:	8ec50000 */ 	lw	$a1,0x0($s6)
/*  f163b14:	8eea0000 */ 	lw	$t2,0x0($s7)
/*  f163b18:	272e0001 */ 	addiu	$t6,$t9,0x1
/*  f163b1c:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f163b20:	00ab3021 */ 	addu	$a2,$a1,$t3
/*  f163b24:	10000011 */ 	beqz	$zero,.L0f163b6c
/*  f163b28:	80c80005 */ 	lb	$t0,0x5($a2)
.L0f163b2c:
/*  f163b2c:	00710019 */ 	multu	$v1,$s1
/*  f163b30:	00007812 */ 	mflo	$t7
/*  f163b34:	00af1021 */ 	addu	$v0,$a1,$t7
/*  f163b38:	84580002 */ 	lh	$t8,0x2($v0)
/*  f163b3c:	5700000c */ 	bnezl	$t8,.L0f163b70
/*  f163b40:	0128082a */ 	slt	$at,$t1,$t0
/*  f163b44:	944d0000 */ 	lhu	$t5,0x0($v0)
/*  f163b48:	35b90020 */ 	ori	$t9,$t5,0x20
/*  f163b4c:	a4590000 */ 	sh	$t9,0x0($v0)
/*  f163b50:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f163b54:	8ec50000 */ 	lw	$a1,0x0($s6)
/*  f163b58:	8eea0000 */ 	lw	$t2,0x0($s7)
/*  f163b5c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f163b60:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f163b64:	00ab3021 */ 	addu	$a2,$a1,$t3
/*  f163b68:	80c80005 */ 	lb	$t0,0x5($a2)
.L0f163b6c:
/*  f163b6c:	0128082a */ 	slt	$at,$t1,$t0
.L0f163b70:
/*  f163b70:	1420ffd0 */ 	bnez	$at,.L0f163ab4
/*  f163b74:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f163b78:	1000005f */ 	beqz	$zero,.L0f163cf8
/*  f163b7c:	01551821 */ 	addu	$v1,$t2,$s5
.L0f163b80:
/*  f163b80:	02510019 */ 	multu	$s2,$s1
/*  f163b84:	0000c012 */ 	mflo	$t8
/*  f163b88:	00b86821 */ 	addu	$t5,$a1,$t8
/*  f163b8c:	95b90000 */ 	lhu	$t9,0x0($t5)
/*  f163b90:	332e0004 */ 	andi	$t6,$t9,0x4
/*  f163b94:	51c00059 */ 	beqzl	$t6,.L0f163cfc
/*  f163b98:	946e0008 */ 	lhu	$t6,0x8($v1)
/*  f163b9c:	14800056 */ 	bnez	$a0,.L0f163cf8
/*  f163ba0:	344f0008 */ 	ori	$t7,$v0,0x8
/*  f163ba4:	a50f0000 */ 	sh	$t7,0x0($t0)
/*  f163ba8:	8ed80000 */ 	lw	$t8,0x0($s6)
/*  f163bac:	02602025 */ 	or	$a0,$s3,$zero
/*  f163bb0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f163bb4:	030c4021 */ 	addu	$t0,$t8,$t4
/*  f163bb8:	850d0002 */ 	lh	$t5,0x2($t0)
/*  f163bbc:	15a00007 */ 	bnez	$t5,.L0f163bdc
/*  f163bc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163bc4:	95190000 */ 	lhu	$t9,0x0($t0)
/*  f163bc8:	372e0020 */ 	ori	$t6,$t9,0x20
/*  f163bcc:	a50e0000 */ 	sh	$t6,0x0($t0)
/*  f163bd0:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f163bd4:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f163bd8:	ae180000 */ 	sw	$t8,0x0($s0)
.L0f163bdc:
/*  f163bdc:	0fc55f6c */ 	jal	func0f157db0
/*  f163be0:	afac0048 */ 	sw	$t4,0x48($sp)
/*  f163be4:	8eea0000 */ 	lw	$t2,0x0($s7)
/*  f163be8:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f163bec:	01551821 */ 	addu	$v1,$t2,$s5
/*  f163bf0:	90620006 */ 	lbu	$v0,0x6($v1)
/*  f163bf4:	304d0001 */ 	andi	$t5,$v0,0x1
/*  f163bf8:	11a0003f */ 	beqz	$t5,.L0f163cf8
/*  f163bfc:	30590004 */ 	andi	$t9,$v0,0x4
/*  f163c00:	5720003e */ 	bnezl	$t9,.L0f163cfc
/*  f163c04:	946e0008 */ 	lhu	$t6,0x8($v1)
/*  f163c08:	8ec50000 */ 	lw	$a1,0x0($s6)
/*  f163c0c:	00004825 */ 	or	$t1,$zero,$zero
/*  f163c10:	00003825 */ 	or	$a3,$zero,$zero
/*  f163c14:	00ac4021 */ 	addu	$t0,$a1,$t4
/*  f163c18:	81060005 */ 	lb	$a2,0x5($t0)
/*  f163c1c:	58c00037 */ 	blezl	$a2,.L0f163cfc
/*  f163c20:	946e0008 */ 	lhu	$t6,0x8($v1)
.L0f163c24:
/*  f163c24:	850f000e */ 	lh	$t7,0xe($t0)
/*  f163c28:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*  f163c2c:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f163c30:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f163c34:	01d86821 */ 	addu	$t5,$t6,$t8
/*  f163c38:	01a7c821 */ 	addu	$t9,$t5,$a3
/*  f163c3c:	87220000 */ 	lh	$v0,0x0($t9)
/*  f163c40:	000278c0 */ 	sll	$t7,$v0,0x3
/*  f163c44:	014f2021 */ 	addu	$a0,$t2,$t7
/*  f163c48:	84830002 */ 	lh	$v1,0x2($a0)
/*  f163c4c:	16630012 */ 	bne	$s3,$v1,.L0f163c98
/*  f163c50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163c54:	00710019 */ 	multu	$v1,$s1
/*  f163c58:	00007012 */ 	mflo	$t6
/*  f163c5c:	00ae1021 */ 	addu	$v0,$a1,$t6
/*  f163c60:	84580002 */ 	lh	$t8,0x2($v0)
/*  f163c64:	57000021 */ 	bnezl	$t8,.L0f163cec
/*  f163c68:	0126082a */ 	slt	$at,$t1,$a2
/*  f163c6c:	944d0000 */ 	lhu	$t5,0x0($v0)
/*  f163c70:	35b90020 */ 	ori	$t9,$t5,0x20
/*  f163c74:	a4590000 */ 	sh	$t9,0x0($v0)
/*  f163c78:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f163c7c:	8ec50000 */ 	lw	$a1,0x0($s6)
/*  f163c80:	8eea0000 */ 	lw	$t2,0x0($s7)
/*  f163c84:	25ee0001 */ 	addiu	$t6,$t7,0x1
/*  f163c88:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f163c8c:	00ac4021 */ 	addu	$t0,$a1,$t4
/*  f163c90:	10000015 */ 	beqz	$zero,.L0f163ce8
/*  f163c94:	81060005 */ 	lb	$a2,0x5($t0)
.L0f163c98:
/*  f163c98:	00710019 */ 	multu	$v1,$s1
/*  f163c9c:	0000c012 */ 	mflo	$t8
/*  f163ca0:	00b86821 */ 	addu	$t5,$a1,$t8
/*  f163ca4:	85b90002 */ 	lh	$t9,0x2($t5)
/*  f163ca8:	57200010 */ 	bnezl	$t9,.L0f163cec
/*  f163cac:	0126082a */ 	slt	$at,$t1,$a2
/*  f163cb0:	848f0004 */ 	lh	$t7,0x4($a0)
/*  f163cb4:	01f10019 */ 	multu	$t7,$s1
/*  f163cb8:	00007012 */ 	mflo	$t6
/*  f163cbc:	00ae1021 */ 	addu	$v0,$a1,$t6
/*  f163cc0:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f163cc4:	370d0020 */ 	ori	$t5,$t8,0x20
/*  f163cc8:	a44d0000 */ 	sh	$t5,0x0($v0)
/*  f163ccc:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f163cd0:	8ec50000 */ 	lw	$a1,0x0($s6)
/*  f163cd4:	8eea0000 */ 	lw	$t2,0x0($s7)
/*  f163cd8:	272f0001 */ 	addiu	$t7,$t9,0x1
/*  f163cdc:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f163ce0:	00ac4021 */ 	addu	$t0,$a1,$t4
/*  f163ce4:	81060005 */ 	lb	$a2,0x5($t0)
.L0f163ce8:
/*  f163ce8:	0126082a */ 	slt	$at,$t1,$a2
.L0f163cec:
/*  f163cec:	1420ffcd */ 	bnez	$at,.L0f163c24
/*  f163cf0:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f163cf4:	01551821 */ 	addu	$v1,$t2,$s5
.L0f163cf8:
/*  f163cf8:	946e0008 */ 	lhu	$t6,0x8($v1)
.L0f163cfc:
/*  f163cfc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f163d00:	24630008 */ 	addiu	$v1,$v1,0x8
/*  f163d04:	55c0ff37 */ 	bnezl	$t6,.L0f1639e4
/*  f163d08:	906f0006 */ 	lbu	$t7,0x6($v1)
.L0f163d0c:
/*  f163d0c:	3c08800a */ 	lui	$t0,%hi(g_Vars)
/*  f163d10:	25089fc0 */ 	addiu	$t0,$t0,%lo(g_Vars)
/*  f163d14:	8d180314 */ 	lw	$t8,0x314($t0)
/*  f163d18:	3c16800a */ 	lui	$s6,%hi(g_RoomPtrs)
/*  f163d1c:	26d64928 */ 	addiu	$s6,$s6,%lo(g_RoomPtrs)
/*  f163d20:	13000039 */ 	beqz	$t8,.L0f163e08
/*  f163d24:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f163d28:	8d02028c */ 	lw	$v0,0x28c($t0)
/*  f163d2c:	8d1802bc */ 	lw	$t8,0x2bc($t0)
/*  f163d30:	240f0010 */ 	addiu	$t7,$zero,0x10
/*  f163d34:	004d2804 */ 	sllv	$a1,$t5,$v0
/*  f163d38:	004f4804 */ 	sllv	$t1,$t7,$v0
/*  f163d3c:	30b900ff */ 	andi	$t9,$a1,0xff
/*  f163d40:	312e00ff */ 	andi	$t6,$t1,0xff
/*  f163d44:	1b000030 */ 	blez	$t8,.L0f163e08
/*  f163d48:	00001825 */ 	or	$v1,$zero,$zero
/*  f163d4c:	3c05800a */ 	lui	$a1,%hi(g_MpRoomVisibility)
/*  f163d50:	24a5492c */ 	addiu	$a1,$a1,%lo(g_MpRoomVisibility)
/*  f163d54:	00002025 */ 	or	$a0,$zero,$zero
/*  f163d58:	03203025 */ 	or	$a2,$t9,$zero
/*  f163d5c:	01c03825 */ 	or	$a3,$t6,$zero
/*  f163d60:	8ecd0000 */ 	lw	$t5,0x0($s6)
.L0f163d64:
/*  f163d64:	01a4c821 */ 	addu	$t9,$t5,$a0
/*  f163d68:	972f0000 */ 	lhu	$t7,0x0($t9)
/*  f163d6c:	31ee0004 */ 	andi	$t6,$t7,0x4
/*  f163d70:	51c00008 */ 	beqzl	$t6,.L0f163d94
/*  f163d74:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f163d78:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f163d7c:	03031021 */ 	addu	$v0,$t8,$v1
/*  f163d80:	904d0000 */ 	lbu	$t5,0x0($v0)
/*  f163d84:	01a6c825 */ 	or	$t9,$t5,$a2
/*  f163d88:	10000007 */ 	beqz	$zero,.L0f163da8
/*  f163d8c:	a0590000 */ 	sb	$t9,0x0($v0)
/*  f163d90:	8caf0000 */ 	lw	$t7,0x0($a1)
.L0f163d94:
/*  f163d94:	00c0c027 */ 	nor	$t8,$a2,$zero
/*  f163d98:	01e31021 */ 	addu	$v0,$t7,$v1
/*  f163d9c:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f163da0:	01d86824 */ 	and	$t5,$t6,$t8
/*  f163da4:	a04d0000 */ 	sb	$t5,0x0($v0)
.L0f163da8:
/*  f163da8:	8ed90000 */ 	lw	$t9,0x0($s6)
/*  f163dac:	03247821 */ 	addu	$t7,$t9,$a0
/*  f163db0:	95ee0000 */ 	lhu	$t6,0x0($t7)
/*  f163db4:	31d80008 */ 	andi	$t8,$t6,0x8
/*  f163db8:	53000008 */ 	beqzl	$t8,.L0f163ddc
/*  f163dbc:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f163dc0:	8cad0000 */ 	lw	$t5,0x0($a1)
/*  f163dc4:	01a31021 */ 	addu	$v0,$t5,$v1
/*  f163dc8:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f163dcc:	03277825 */ 	or	$t7,$t9,$a3
/*  f163dd0:	10000007 */ 	beqz	$zero,.L0f163df0
/*  f163dd4:	a04f0000 */ 	sb	$t7,0x0($v0)
/*  f163dd8:	8cae0000 */ 	lw	$t6,0x0($a1)
.L0f163ddc:
/*  f163ddc:	00e06827 */ 	nor	$t5,$a3,$zero
/*  f163de0:	01c31021 */ 	addu	$v0,$t6,$v1
/*  f163de4:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f163de8:	030dc824 */ 	and	$t9,$t8,$t5
/*  f163dec:	a0590000 */ 	sb	$t9,0x0($v0)
.L0f163df0:
/*  f163df0:	8d0f02bc */ 	lw	$t7,0x2bc($t0)
/*  f163df4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f163df8:	2484008c */ 	addiu	$a0,$a0,0x8c
/*  f163dfc:	006f082a */ 	slt	$at,$v1,$t7
/*  f163e00:	5420ffd8 */ 	bnezl	$at,.L0f163d64
/*  f163e04:	8ecd0000 */ 	lw	$t5,0x0($s6)
.L0f163e08:
/*  f163e08:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f163e0c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f163e10:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f163e14:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f163e18:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f163e1c:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f163e20:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f163e24:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f163e28:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f163e2c:	03e00008 */ 	jr	$ra
/*  f163e30:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0f163e34
/*  f163e34:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f163e38:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f163e3c:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f163e40:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f163e44:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f163e48:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f163e4c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f163e50:	0fc591d2 */ 	jal	func0f164748
/*  f163e54:	8e500284 */ 	lw	$s0,0x284($s2)
/*  f163e58:	c6041794 */ 	lwc1	$f4,0x1794($s0)
/*  f163e5c:	3c04800a */ 	lui	$a0,%hi(var800a4cf8)
/*  f163e60:	24844cf8 */ 	addiu	$a0,$a0,%lo(var800a4cf8)
/*  f163e64:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f163e68:	440f3000 */ 	mfc1	$t7,$f6
/*  f163e6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163e70:	a7af0038 */ 	sh	$t7,0x38($sp)
/*  f163e74:	c6081798 */ 	lwc1	$f8,0x1798($s0)
/*  f163e78:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f163e7c:	44195000 */ 	mfc1	$t9,$f10
/*  f163e80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163e84:	a7b9003a */ 	sh	$t9,0x3a($sp)
/*  f163e88:	c610179c */ 	lwc1	$f16,0x179c($s0)
/*  f163e8c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f163e90:	440a9000 */ 	mfc1	$t2,$f18
/*  f163e94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163e98:	a7aa003c */ 	sh	$t2,0x3c($sp)
/*  f163e9c:	c60417a0 */ 	lwc1	$f4,0x17a0($s0)
/*  f163ea0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f163ea4:	440c3000 */ 	mfc1	$t4,$f6
/*  f163ea8:	0c002fb8 */ 	jal	func0000bee0
/*  f163eac:	a7ac003e */ 	sh	$t4,0x3e($sp)
/*  f163eb0:	8e4d0288 */ 	lw	$t5,0x288($s2)
/*  f163eb4:	3c08800a */ 	lui	$t0,%hi(var800a4cf0)
/*  f163eb8:	25084cf0 */ 	addiu	$t0,$t0,%lo(var800a4cf0)
/*  f163ebc:	c508000c */ 	lwc1	$f8,0xc($t0)
/*  f163ec0:	c5aa0074 */ 	lwc1	$f10,0x74($t5)
/*  f163ec4:	8e4e02bc */ 	lw	$t6,0x2bc($s2)
/*  f163ec8:	3c02800a */ 	lui	$v0,%hi(g_RoomPtrs)
/*  f163ecc:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f163ed0:	24424928 */ 	addiu	$v0,$v0,%lo(g_RoomPtrs)
/*  f163ed4:	00002825 */ 	or	$a1,$zero,$zero
/*  f163ed8:	00001825 */ 	or	$v1,$zero,$zero
/*  f163edc:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f163ee0:	2406ffd2 */ 	addiu	$a2,$zero,-46
/*  f163ee4:	19c00015 */ 	blez	$t6,.L0f163f3c
/*  f163ee8:	e510000c */ 	swc1	$f16,0xc($t0)
/*  f163eec:	8c4f0000 */ 	lw	$t7,0x0($v0)
.L0f163ef0:
/*  f163ef0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f163ef4:	01e32021 */ 	addu	$a0,$t7,$v1
/*  f163ef8:	94980000 */ 	lhu	$t8,0x0($a0)
/*  f163efc:	0306c824 */ 	and	$t9,$t8,$a2
/*  f163f00:	a4990000 */ 	sh	$t9,0x0($a0)
/*  f163f04:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f163f08:	01235021 */ 	addu	$t2,$t1,$v1
/*  f163f0c:	a1400004 */ 	sb	$zero,0x4($t2)
/*  f163f10:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f163f14:	01636021 */ 	addu	$t4,$t3,$v1
/*  f163f18:	a1800006 */ 	sb	$zero,0x6($t4)
/*  f163f1c:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f163f20:	01a37021 */ 	addu	$t6,$t5,$v1
/*  f163f24:	a1c70007 */ 	sb	$a3,0x7($t6)
/*  f163f28:	8e4f02bc */ 	lw	$t7,0x2bc($s2)
/*  f163f2c:	2463008c */ 	addiu	$v1,$v1,0x8c
/*  f163f30:	00af082a */ 	slt	$at,$a1,$t7
/*  f163f34:	5420ffee */ 	bnezl	$at,.L0f163ef0
/*  f163f38:	8c4f0000 */ 	lw	$t7,0x0($v0)
.L0f163f3c:
/*  f163f3c:	96180010 */ 	lhu	$t8,0x10($s0)
/*  f163f40:	24010001 */ 	addiu	$at,$zero,0x1
/*  f163f44:	3c038008 */ 	lui	$v1,%hi(var8007fc34)
/*  f163f48:	17010005 */ 	bne	$t8,$at,.L0f163f60
/*  f163f4c:	2463fc34 */ 	addiu	$v1,$v1,%lo(var8007fc34)
/*  f163f50:	0fc58b67 */ 	jal	func0f162d9c
/*  f163f54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f163f58:	10000078 */ 	beqz	$zero,.L0f16413c
/*  f163f5c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f163f60:
/*  f163f60:	3c058008 */ 	lui	$a1,%hi(var8007fc30)
/*  f163f64:	24a5fc30 */ 	addiu	$a1,$a1,%lo(var8007fc30)
/*  f163f68:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f163f6c:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f163f70:	3c10800a */ 	lui	$s0,%hi(var800a65b8)
/*  f163f74:	261065b8 */ 	addiu	$s0,$s0,%lo(var800a65b8)
/*  f163f78:	0322082a */ 	slt	$at,$t9,$v0
/*  f163f7c:	10200002 */ 	beqz	$at,.L0f163f88
/*  f163f80:	24097fff */ 	addiu	$t1,$zero,0x7fff
/*  f163f84:	ac620000 */ 	sw	$v0,0x0($v1)
.L0f163f88:
/*  f163f88:	3c018008 */ 	lui	$at,%hi(var8007fc2c)
/*  f163f8c:	ac20fc2c */ 	sw	$zero,%lo(var8007fc2c)($at)
/*  f163f90:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f163f94:	3c01800a */ 	lui	$at,%hi(var800a4ce4+0x2)
/*  f163f98:	a4204ce6 */ 	sh	$zero,%lo(var800a4ce4+0x2)($at)
/*  f163f9c:	3c01800a */ 	lui	$at,%hi(var800a4ce4)
/*  f163fa0:	a4294ce4 */ 	sh	$t1,%lo(var800a4ce4)($at)
/*  f163fa4:	3c02800a */ 	lui	$v0,%hi(var800a4640)
/*  f163fa8:	24424640 */ 	addiu	$v0,$v0,%lo(var800a4640)
/*  f163fac:	87ac0038 */ 	lh	$t4,0x38($sp)
/*  f163fb0:	87ad003a */ 	lh	$t5,0x3a($sp)
/*  f163fb4:	87ae003c */ 	lh	$t6,0x3c($sp)
/*  f163fb8:	87af003e */ 	lh	$t7,0x3e($sp)
/*  f163fbc:	240affff */ 	addiu	$t2,$zero,-1
/*  f163fc0:	240b00ff */ 	addiu	$t3,$zero,0xff
/*  f163fc4:	a44a02d0 */ 	sh	$t2,0x2d0($v0)
/*  f163fc8:	a04b02d3 */ 	sb	$t3,0x2d3($v0)
/*  f163fcc:	a5000000 */ 	sh	$zero,0x0($t0)
/*  f163fd0:	a5000002 */ 	sh	$zero,0x2($t0)
/*  f163fd4:	a5000004 */ 	sh	$zero,0x4($t0)
/*  f163fd8:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f163fdc:	3c04800a */ 	lui	$a0,%hi(var800a4cd4)
/*  f163fe0:	a44c02d4 */ 	sh	$t4,0x2d4($v0)
/*  f163fe4:	a44d02d6 */ 	sh	$t5,0x2d6($v0)
/*  f163fe8:	a44e02d8 */ 	sh	$t6,0x2d8($v0)
/*  f163fec:	a44f02da */ 	sh	$t7,0x2da($v0)
/*  f163ff0:	0fc58b3c */ 	jal	func0f162cf0
/*  f163ff4:	8c844cd4 */ 	lw	$a0,%lo(var800a4cd4)($a0)
/*  f163ff8:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f163ffc:	3c19800a */ 	lui	$t9,%hi(g_PortalSomethings)
/*  f164000:	1700004b */ 	bnez	$t8,.L0f164130
/*  f164004:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164008:	8f394cc8 */ 	lw	$t9,%lo(g_PortalSomethings)($t9)
/*  f16400c:	3c108008 */ 	lui	$s0,%hi(var8007fc20)
/*  f164010:	27b10038 */ 	addiu	$s1,$sp,0x38
/*  f164014:	97290000 */ 	lhu	$t1,0x0($t9)
/*  f164018:	2610fc20 */ 	addiu	$s0,$s0,%lo(var8007fc20)
/*  f16401c:	02203025 */ 	or	$a2,$s1,$zero
/*  f164020:	1520002d */ 	bnez	$t1,.L0f1640d8
/*  f164024:	00002825 */ 	or	$a1,$zero,$zero
/*  f164028:	8e4a02bc */ 	lw	$t2,0x2bc($s2)
/*  f16402c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f164030:	27b10038 */ 	addiu	$s1,$sp,0x38
/*  f164034:	29410002 */ 	slti	$at,$t2,0x2
/*  f164038:	1420003d */ 	bnez	$at,.L0f164130
/*  f16403c:	02002025 */ 	or	$a0,$s0,$zero
.L0f164040:
/*  f164040:	0fc57364 */ 	jal	func0f15cd90
/*  f164044:	02202825 */ 	or	$a1,$s1,$zero
/*  f164048:	1040001c */ 	beqz	$v0,.L0f1640bc
/*  f16404c:	3c028008 */ 	lui	$v0,%hi(g_StageIndex)
/*  f164050:	8c42fc00 */ 	lw	$v0,%lo(g_StageIndex)($v0)
/*  f164054:	2401001b */ 	addiu	$at,$zero,0x1b
/*  f164058:	10410004 */ 	beq	$v0,$at,.L0f16406c
/*  f16405c:	24010021 */ 	addiu	$at,$zero,0x21
/*  f164060:	10410002 */ 	beq	$v0,$at,.L0f16406c
/*  f164064:	24010005 */ 	addiu	$at,$zero,0x5
/*  f164068:	14410002 */ 	bne	$v0,$at,.L0f164074
.L0f16406c:
/*  f16406c:	2401000f */ 	addiu	$at,$zero,0xf
/*  f164070:	12010012 */ 	beq	$s0,$at,.L0f1640bc
.L0f164074:
/*  f164074:	24010016 */ 	addiu	$at,$zero,0x16
/*  f164078:	14410002 */ 	bne	$v0,$at,.L0f164084
/*  f16407c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f164080:	1201000e */ 	beq	$s0,$at,.L0f1640bc
.L0f164084:
/*  f164084:	2401001c */ 	addiu	$at,$zero,0x1c
/*  f164088:	10410002 */ 	beq	$v0,$at,.L0f164094
/*  f16408c:	2401000e */ 	addiu	$at,$zero,0xe
/*  f164090:	14410002 */ 	bne	$v0,$at,.L0f16409c
.L0f164094:
/*  f164094:	24010001 */ 	addiu	$at,$zero,0x1
/*  f164098:	12010008 */ 	beq	$s0,$at,.L0f1640bc
.L0f16409c:
/*  f16409c:	24010020 */ 	addiu	$at,$zero,0x20
/*  f1640a0:	14410003 */ 	bne	$v0,$at,.L0f1640b0
/*  f1640a4:	02002025 */ 	or	$a0,$s0,$zero
/*  f1640a8:	24010071 */ 	addiu	$at,$zero,0x71
/*  f1640ac:	12010003 */ 	beq	$s0,$at,.L0f1640bc
.L0f1640b0:
/*  f1640b0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1640b4:	0fc55fa5 */ 	jal	func0f157e94
/*  f1640b8:	02203025 */ 	or	$a2,$s1,$zero
.L0f1640bc:
/*  f1640bc:	8e4b02bc */ 	lw	$t3,0x2bc($s2)
/*  f1640c0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1640c4:	020b082a */ 	slt	$at,$s0,$t3
/*  f1640c8:	5420ffdd */ 	bnezl	$at,.L0f164040
/*  f1640cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f1640d0:	10000017 */ 	beqz	$zero,.L0f164130
/*  f1640d4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1640d8:
/*  f1640d8:	0fc55fa5 */ 	jal	func0f157e94
/*  f1640dc:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f1640e0:	86040002 */ 	lh	$a0,0x2($s0)
/*  f1640e4:	3c08800a */ 	lui	$t0,%hi(var800a4cf0)
/*  f1640e8:	25084cf0 */ 	addiu	$t0,$t0,%lo(var800a4cf0)
/*  f1640ec:	00042c00 */ 	sll	$a1,$a0,0x10
/*  f1640f0:	00056403 */ 	sra	$t4,$a1,0x10
/*  f1640f4:	a5000000 */ 	sh	$zero,0x0($t0)
/*  f1640f8:	a5000002 */ 	sh	$zero,0x2($t0)
/*  f1640fc:	a5000004 */ 	sh	$zero,0x4($t0)
/*  f164100:	01802825 */ 	or	$a1,$t4,$zero
/*  f164104:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f164108:	0fc58cb5 */ 	jal	func0f1632d4
/*  f16410c:	02203825 */ 	or	$a3,$s1,$zero
/*  f164110:	0fc58e41 */ 	jal	func0f163904
/*  f164114:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164118:	10400005 */ 	beqz	$v0,.L0f164130
/*  f16411c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f164120:
/*  f164120:	0fc58e41 */ 	jal	func0f163904
/*  f164124:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164128:	1440fffd */ 	bnez	$v0,.L0f164120
/*  f16412c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f164130:
/*  f164130:	0fc58e5f */ 	jal	func0f16397c
/*  f164134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164138:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f16413c:
/*  f16413c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f164140:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f164144:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f164148:	03e00008 */ 	jr	$ra
/*  f16414c:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f164150
.late_rodata
glabel var7f1b76c0
.word 0x7f7fffff
.text
/*  f164150:	27bdff38 */ 	addiu	$sp,$sp,-200
/*  f164154:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f164158:	f7be0038 */ 	sdc1	$f30,0x38($sp)
/*  f16415c:	f7bc0030 */ 	sdc1	$f28,0x30($sp)
/*  f164160:	f7ba0028 */ 	sdc1	$f26,0x28($sp)
/*  f164164:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f164168:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f16416c:	0fc569bd */ 	jal	func0f15a6f4
/*  f164170:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f164174:	0fc572dd */ 	jal	func0f15cb74
/*  f164178:	00402025 */ 	or	$a0,$v0,$zero
/*  f16417c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f164180:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f164184:	8c6e0290 */ 	lw	$t6,0x290($v1)
/*  f164188:	3c0a8008 */ 	lui	$t2,%hi(var8007fc28)
/*  f16418c:	00405825 */ 	or	$t3,$v0,$zero
/*  f164190:	15c00005 */ 	bnez	$t6,.L0f1641a8
/*  f164194:	254afc28 */ 	addiu	$t2,$t2,%lo(var8007fc28)
/*  f164198:	8d4f0000 */ 	lw	$t7,0x0($t2)
/*  f16419c:	8c780034 */ 	lw	$t8,0x34($v1)
/*  f1641a0:	01f8c823 */ 	subu	$t9,$t7,$t8
/*  f1641a4:	ad590000 */ 	sw	$t9,0x0($t2)
.L0f1641a8:
/*  f1641a8:	3c0a8008 */ 	lui	$t2,%hi(var8007fc28)
/*  f1641ac:	254afc28 */ 	addiu	$t2,$t2,%lo(var8007fc28)
/*  f1641b0:	8d420000 */ 	lw	$v0,0x0($t2)
/*  f1641b4:	3c0c8008 */ 	lui	$t4,%hi(var8007fc10)
/*  f1641b8:	04410003 */ 	bgez	$v0,.L0f1641c8
/*  f1641bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1641c0:	ad400000 */ 	sw	$zero,0x0($t2)
/*  f1641c4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1641c8:
/*  f1641c8:	544000d1 */ 	bnezl	$v0,.L0f164510
/*  f1641cc:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f1641d0:	858cfc10 */ 	lh	$t4,%lo(var8007fc10)($t4)
/*  f1641d4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1641d8:	558100cd */ 	bnel	$t4,$at,.L0f164510
/*  f1641dc:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f1641e0:	8c6d02ac */ 	lw	$t5,0x2ac($v1)
/*  f1641e4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1641e8:	3c0e8009 */ 	lui	$t6,%hi(g_Is4Mb)
/*  f1641ec:	544d00c8 */ 	bnel	$v0,$t5,.L0f164510
/*  f1641f0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f1641f4:	91ce0af0 */ 	lbu	$t6,%lo(g_Is4Mb)($t6)
/*  f1641f8:	3c017f1b */ 	lui	$at,%hi(var7f1b76c0)
/*  f1641fc:	3c0f8008 */ 	lui	$t7,%hi(var8007fc38)
/*  f164200:	504e00c3 */ 	beql	$v0,$t6,.L0f164510
/*  f164204:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f164208:	8deffc38 */ 	lw	$t7,%lo(var8007fc38)($t7)
/*  f16420c:	8c650284 */ 	lw	$a1,0x284($v1)
/*  f164210:	c42476c0 */ 	lwc1	$f4,%lo(var7f1b76c0)($at)
/*  f164214:	00003825 */ 	or	$a3,$zero,$zero
/*  f164218:	00a04825 */ 	or	$t1,$a1,$zero
/*  f16421c:	11e000b2 */ 	beqz	$t7,.L0f1644e8
/*  f164220:	e7a400ac */ 	swc1	$f4,0xac($sp)
/*  f164224:	8c6602bc */ 	lw	$a2,0x2bc($v1)
/*  f164228:	3c03800a */ 	lui	$v1,%hi(g_RoomPtrs)
/*  f16422c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f164230:	28c10002 */ 	slti	$at,$a2,0x2
/*  f164234:	142000ac */ 	bnez	$at,.L0f1644e8
/*  f164238:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16423c:	8c634928 */ 	lw	$v1,%lo(g_RoomPtrs)($v1)
/*  f164240:	3c08800a */ 	lui	$t0,%hi(var8009dd6c)
/*  f164244:	2508dd6c */ 	addiu	$t0,$t0,%lo(var8009dd6c)
/*  f164248:	2463008c */ 	addiu	$v1,$v1,140
.L0f16424c:
/*  f16424c:	84780002 */ 	lh	$t8,0x2($v1)
/*  f164250:	570000a2 */ 	bnezl	$t8,.L0f1644dc
/*  f164254:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f164258:	94790000 */ 	lhu	$t9,0x0($v1)
/*  f16425c:	332c0020 */ 	andi	$t4,$t9,0x20
/*  f164260:	5180009e */ 	beqzl	$t4,.L0f1644dc
/*  f164264:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f164268:	8cad00bc */ 	lw	$t5,0xbc($a1)
/*  f16426c:	c4680030 */ 	lwc1	$f8,0x30($v1)
/*  f164270:	3c01800a */ 	lui	$at,0x800a
/*  f164274:	c5a60008 */ 	lwc1	$f6,0x8($t5)
/*  f164278:	c434dd4c */ 	lwc1	$f20,-0x22b4($at)
/*  f16427c:	3c01800a */ 	lui	$at,0x800a
/*  f164280:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f164284:	c436dd48 */ 	lwc1	$f22,-0x22b8($at)
/*  f164288:	3c01800a */ 	lui	$at,0x800a
/*  f16428c:	c438dd40 */ 	lwc1	$f24,-0x22c0($at)
/*  f164290:	e7aa00b0 */ 	swc1	$f10,0xb0($sp)
/*  f164294:	8cae00bc */ 	lw	$t6,0xbc($a1)
/*  f164298:	c4660034 */ 	lwc1	$f6,0x34($v1)
/*  f16429c:	3c01800a */ 	lui	$at,0x800a
/*  f1642a0:	c5c4000c */ 	lwc1	$f4,0xc($t6)
/*  f1642a4:	c43add44 */ 	lwc1	$f26,-0x22bc($at)
/*  f1642a8:	3c01800a */ 	lui	$at,0x800a
/*  f1642ac:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f1642b0:	c43cdd5c */ 	lwc1	$f28,-0x22a4($at)
/*  f1642b4:	3c01800a */ 	lui	$at,0x800a
/*  f1642b8:	c43edd58 */ 	lwc1	$f30,-0x22a8($at)
/*  f1642bc:	e7a800b4 */ 	swc1	$f8,0xb4($sp)
/*  f1642c0:	8caf00bc */ 	lw	$t7,0xbc($a1)
/*  f1642c4:	c4640038 */ 	lwc1	$f4,0x38($v1)
/*  f1642c8:	c7a800b0 */ 	lwc1	$f8,0xb0($sp)
/*  f1642cc:	c5ea0010 */ 	lwc1	$f10,0x10($t7)
/*  f1642d0:	3c01800a */ 	lui	$at,0x800a
/*  f1642d4:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f1642d8:	46084282 */ 	mul.s	$f10,$f8,$f8
/*  f1642dc:	c7a400b4 */ 	lwc1	$f4,0xb4($sp)
/*  f1642e0:	e7a600b8 */ 	swc1	$f6,0xb8($sp)
/*  f1642e4:	46042182 */ 	mul.s	$f6,$f4,$f4
/*  f1642e8:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f1642ec:	c470003c */ 	lwc1	$f16,0x3c($v1)
/*  f1642f0:	c46c0034 */ 	lwc1	$f12,0x34($v1)
/*  f1642f4:	c4620030 */ 	lwc1	$f2,0x30($v1)
/*  f1642f8:	8d22174c */ 	lw	$v0,0x174c($t1)
/*  f1642fc:	c46e0038 */ 	lwc1	$f14,0x38($v1)
/*  f164300:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f164304:	46042282 */ 	mul.s	$f10,$f4,$f4
/*  f164308:	c426dd50 */ 	lwc1	$f6,-0x22b0($at)
/*  f16430c:	3c01800a */ 	lui	$at,0x800a
/*  f164310:	c424dd54 */ 	lwc1	$f4,-0x22ac($at)
/*  f164314:	3c01800a */ 	lui	$at,0x800a
/*  f164318:	e7a6006c */ 	swc1	$f6,0x6c($sp)
/*  f16431c:	e7a40068 */ 	swc1	$f4,0x68($sp)
/*  f164320:	46085480 */ 	add.s	$f18,$f10,$f8
/*  f164324:	c42add2c */ 	lwc1	$f10,-0x22d4($at)
/*  f164328:	3c01800a */ 	lui	$at,0x800a
/*  f16432c:	c428dd28 */ 	lwc1	$f8,-0x22d8($at)
/*  f164330:	3c01800a */ 	lui	$at,0x800a
/*  f164334:	c426dd20 */ 	lwc1	$f6,-0x22e0($at)
/*  f164338:	3c01800a */ 	lui	$at,0x800a
/*  f16433c:	c424dd24 */ 	lwc1	$f4,-0x22dc($at)
/*  f164340:	3c01800a */ 	lui	$at,0x800a
/*  f164344:	e7aa0064 */ 	swc1	$f10,0x64($sp)
/*  f164348:	c42add3c */ 	lwc1	$f10,-0x22c4($at)
/*  f16434c:	3c01800a */ 	lui	$at,0x800a
/*  f164350:	e7a80060 */ 	swc1	$f8,0x60($sp)
/*  f164354:	c428dd38 */ 	lwc1	$f8,-0x22c8($at)
/*  f164358:	3c01800a */ 	lui	$at,0x800a
/*  f16435c:	e7a6005c */ 	swc1	$f6,0x5c($sp)
/*  f164360:	c426dd30 */ 	lwc1	$f6,-0x22d0($at)
/*  f164364:	3c01800a */ 	lui	$at,0x800a
/*  f164368:	e7a40058 */ 	swc1	$f4,0x58($sp)
/*  f16436c:	c424dd34 */ 	lwc1	$f4,-0x22cc($at)
/*  f164370:	e7aa0054 */ 	swc1	$f10,0x54($sp)
/*  f164374:	c50a0000 */ 	lwc1	$f10,0x0($t0)
/*  f164378:	e7a80050 */ 	swc1	$f8,0x50($sp)
/*  f16437c:	e7a6004c */ 	swc1	$f6,0x4c($sp)
/*  f164380:	e7a40048 */ 	swc1	$f4,0x48($sp)
/*  f164384:	c4460020 */ 	lwc1	$f6,0x20($v0)
/*  f164388:	46105200 */ 	add.s	$f8,$f10,$f16
/*  f16438c:	c44a0024 */ 	lwc1	$f10,0x24($v0)
/*  f164390:	46023102 */ 	mul.s	$f4,$f6,$f2
/*  f164394:	46009006 */ 	mov.s	$f0,$f18
/*  f164398:	3c014040 */ 	lui	$at,0x4040
/*  f16439c:	460c5182 */ 	mul.s	$f6,$f10,$f12
/*  f1643a0:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f1643a4:	c4440028 */ 	lwc1	$f4,0x28($v0)
/*  f1643a8:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f1643ac:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f1643b0:	4604403c */ 	c.lt.s	$f8,$f4
/*  f1643b4:	4602c202 */ 	mul.s	$f8,$f24,$f2
/*  f1643b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1643bc:	460cd102 */ 	mul.s	$f4,$f26,$f12
/*  f1643c0:	45000005 */ 	bc1f	.L0f1643d8
/*  f1643c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1643c8:	44813000 */ 	mtc1	$at,$f6
/*  f1643cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1643d0:	46069002 */ 	mul.s	$f0,$f18,$f6
/*  f1643d4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1643d8:
/*  f1643d8:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f1643dc:	46167202 */ 	mul.s	$f8,$f14,$f22
/*  f1643e0:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f1643e4:	4610a280 */ 	add.s	$f10,$f20,$f16
/*  f1643e8:	46064100 */ 	add.s	$f4,$f8,$f6
/*  f1643ec:	4604503c */ 	c.lt.s	$f10,$f4
/*  f1643f0:	c7aa006c */ 	lwc1	$f10,0x6c($sp)
/*  f1643f4:	45000005 */ 	bc1f	.L0f16440c
/*  f1643f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1643fc:	44814000 */ 	mtc1	$at,$f8
/*  f164400:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164404:	46080002 */ 	mul.s	$f0,$f0,$f8
/*  f164408:	00000000 */ 	sll	$zero,$zero,0x0
.L0f16440c:
/*  f16440c:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f164410:	c7a80068 */ 	lwc1	$f8,0x68($sp)
/*  f164414:	4610e180 */ 	add.s	$f6,$f28,$f16
/*  f164418:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f16441c:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f164420:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f164424:	461e7102 */ 	mul.s	$f4,$f14,$f30
/*  f164428:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f16442c:	c7a80064 */ 	lwc1	$f8,0x64($sp)
/*  f164430:	460a303c */ 	c.lt.s	$f6,$f10
/*  f164434:	c7aa005c */ 	lwc1	$f10,0x5c($sp)
/*  f164438:	45020006 */ 	bc1fl	.L0f164454
/*  f16443c:	46104180 */ 	add.s	$f6,$f8,$f16
/*  f164440:	44812000 */ 	mtc1	$at,$f4
/*  f164444:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164448:	46040002 */ 	mul.s	$f0,$f0,$f4
/*  f16444c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164450:	46104180 */ 	add.s	$f6,$f8,$f16
.L0f164454:
/*  f164454:	46025102 */ 	mul.s	$f4,$f10,$f2
/*  f164458:	c7a80058 */ 	lwc1	$f8,0x58($sp)
/*  f16445c:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f164460:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f164464:	c7a40060 */ 	lwc1	$f4,0x60($sp)
/*  f164468:	46047282 */ 	mul.s	$f10,$f14,$f4
/*  f16446c:	46085100 */ 	add.s	$f4,$f10,$f8
/*  f164470:	c7aa0054 */ 	lwc1	$f10,0x54($sp)
/*  f164474:	4604303c */ 	c.lt.s	$f6,$f4
/*  f164478:	c7a6004c */ 	lwc1	$f6,0x4c($sp)
/*  f16447c:	45020003 */ 	bc1fl	.L0f16448c
/*  f164480:	46105200 */ 	add.s	$f8,$f10,$f16
/*  f164484:	46000000 */ 	add.s	$f0,$f0,$f0
/*  f164488:	46105200 */ 	add.s	$f8,$f10,$f16
.L0f16448c:
/*  f16448c:	46023102 */ 	mul.s	$f4,$f6,$f2
/*  f164490:	c7aa0048 */ 	lwc1	$f10,0x48($sp)
/*  f164494:	460c5182 */ 	mul.s	$f6,$f10,$f12
/*  f164498:	46062280 */ 	add.s	$f10,$f4,$f6
/*  f16449c:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f1644a0:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f1644a4:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f1644a8:	c7a600ac */ 	lwc1	$f6,0xac($sp)
/*  f1644ac:	4604403c */ 	c.lt.s	$f8,$f4
/*  f1644b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1644b4:	45020003 */ 	bc1fl	.L0f1644c4
/*  f1644b8:	4606003c */ 	c.lt.s	$f0,$f6
/*  f1644bc:	46000000 */ 	add.s	$f0,$f0,$f0
/*  f1644c0:	4606003c */ 	c.lt.s	$f0,$f6
.L0f1644c4:
/*  f1644c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1644c8:	45020004 */ 	bc1fl	.L0f1644dc
/*  f1644cc:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f1644d0:	e7a000ac */ 	swc1	$f0,0xac($sp)
/*  f1644d4:	00803825 */ 	or	$a3,$a0,$zero
/*  f1644d8:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f1644dc:
/*  f1644dc:	0086082a */ 	slt	$at,$a0,$a2
/*  f1644e0:	1420ff5a */ 	bnez	$at,.L0f16424c
/*  f1644e4:	2463008c */ 	addiu	$v1,$v1,0x8c
.L0f1644e8:
/*  f1644e8:	10e00008 */ 	beqz	$a3,.L0f16450c
/*  f1644ec:	00e02025 */ 	or	$a0,$a3,$zero
/*  f1644f0:	0fc57716 */ 	jal	func0f15dc58
/*  f1644f4:	afab00c8 */ 	sw	$t3,0xc8($sp)
/*  f1644f8:	3c0a8008 */ 	lui	$t2,%hi(var8007fc28)
/*  f1644fc:	254afc28 */ 	addiu	$t2,$t2,%lo(var8007fc28)
/*  f164500:	24180040 */ 	addiu	$t8,$zero,0x40
/*  f164504:	8fab00c8 */ 	lw	$t3,0xc8($sp)
/*  f164508:	ad580000 */ 	sw	$t8,0x0($t2)
.L0f16450c:
/*  f16450c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f164510:
/*  f164510:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f164514:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f164518:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f16451c:	d7ba0028 */ 	ldc1	$f26,0x28($sp)
/*  f164520:	d7bc0030 */ 	ldc1	$f28,0x30($sp)
/*  f164524:	d7be0038 */ 	ldc1	$f30,0x38($sp)
/*  f164528:	27bd00c8 */ 	addiu	$sp,$sp,0xc8
/*  f16452c:	03e00008 */ 	jr	$ra
/*  f164530:	01601025 */ 	or	$v0,$t3,$zero
);

GLOBAL_ASM(
glabel func0f164534
/*  f164534:	3c08800a */ 	lui	$t0,%hi(var800a4bec)
/*  f164538:	25084bec */ 	addiu	$t0,$t0,%lo(var800a4bec)
/*  f16453c:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f164540:	00001825 */ 	or	$v1,$zero,$zero
/*  f164544:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f164548:	59c00013 */ 	blezl	$t6,.L0f164598
/*  f16454c:	00035040 */ 	sll	$t2,$v1,0x1
/*  f164550:	18a00010 */ 	blez	$a1,.L0f164594
/*  f164554:	00001040 */ 	sll	$v0,$zero,0x1
/*  f164558:	3c0f800a */ 	lui	$t7,%hi(var800a4930)
/*  f16455c:	25ef4930 */ 	addiu	$t7,$t7,%lo(var800a4930)
/*  f164560:	004f3821 */ 	addu	$a3,$v0,$t7
/*  f164564:	00823021 */ 	addu	$a2,$a0,$v0
/*  f164568:	84f80000 */ 	lh	$t8,0x0($a3)
.L0f16456c:
/*  f16456c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f164570:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f164574:	a4d8fffe */ 	sh	$t8,-0x2($a2)
/*  f164578:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f16457c:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f164580:	0079082a */ 	slt	$at,$v1,$t9
/*  f164584:	10200003 */ 	beqz	$at,.L0f164594
/*  f164588:	0065082a */ 	slt	$at,$v1,$a1
/*  f16458c:	5420fff7 */ 	bnezl	$at,.L0f16456c
/*  f164590:	84f80000 */ 	lh	$t8,0x0($a3)
.L0f164594:
/*  f164594:	00035040 */ 	sll	$t2,$v1,0x1
.L0f164598:
/*  f164598:	008a5821 */ 	addu	$t3,$a0,$t2
/*  f16459c:	a5690000 */ 	sh	$t1,0x0($t3)
/*  f1645a0:	03e00008 */ 	jr	$ra
/*  f1645a4:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f1645a8
/*  f1645a8:	000438c0 */ 	sll	$a3,$a0,0x3
/*  f1645ac:	00e43821 */ 	addu	$a3,$a3,$a0
/*  f1645b0:	3c0e800a */ 	lui	$t6,%hi(g_RoomPtrs)
/*  f1645b4:	8dce4928 */ 	lw	$t6,%lo(g_RoomPtrs)($t6)
/*  f1645b8:	00073880 */ 	sll	$a3,$a3,0x2
/*  f1645bc:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*  f1645c0:	00e43823 */ 	subu	$a3,$a3,$a0
/*  f1645c4:	00073880 */ 	sll	$a3,$a3,0x2
/*  f1645c8:	afb1000c */ 	sw	$s1,0xc($sp)
/*  f1645cc:	afb00008 */ 	sw	$s0,0x8($sp)
/*  f1645d0:	01c74021 */ 	addu	$t0,$t6,$a3
/*  f1645d4:	81090005 */ 	lb	$t1,0x5($t0)
/*  f1645d8:	00a08025 */ 	or	$s0,$a1,$zero
/*  f1645dc:	00c08825 */ 	or	$s1,$a2,$zero
/*  f1645e0:	1920002c */ 	blez	$t1,.L0f164694
/*  f1645e4:	00001825 */ 	or	$v1,$zero,$zero
/*  f1645e8:	3c0d800a */ 	lui	$t5,%hi(g_PortalSomethings)
/*  f1645ec:	3c0c800a */ 	lui	$t4,%hi(var800a4ce0)
/*  f1645f0:	258c4ce0 */ 	addiu	$t4,$t4,%lo(var800a4ce0)
/*  f1645f4:	25ad4cc8 */ 	addiu	$t5,$t5,%lo(g_PortalSomethings)
/*  f1645f8:	00002825 */ 	or	$a1,$zero,$zero
/*  f1645fc:	8518000e */ 	lh	$t8,0xe($t0)
.L0f164600:
/*  f164600:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f164604:	00005825 */ 	or	$t3,$zero,$zero
/*  f164608:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f16460c:	01f97021 */ 	addu	$t6,$t7,$t9
/*  f164610:	01c5c021 */ 	addu	$t8,$t6,$a1
/*  f164614:	87020000 */ 	lh	$v0,0x0($t8)
/*  f164618:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f16461c:	0003c040 */ 	sll	$t8,$v1,0x1
/*  f164620:	0002c8c0 */ 	sll	$t9,$v0,0x3
/*  f164624:	01f95021 */ 	addu	$t2,$t7,$t9
/*  f164628:	85460002 */ 	lh	$a2,0x2($t2)
/*  f16462c:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f164630:	02001025 */ 	or	$v0,$s0,$zero
/*  f164634:	14c40002 */ 	bne	$a2,$a0,.L0f164640
/*  f164638:	02187821 */ 	addu	$t7,$s0,$t8
/*  f16463c:	85460004 */ 	lh	$a2,0x4($t2)
.L0f164640:
/*  f164640:	18600009 */ 	blez	$v1,.L0f164668
/*  f164644:	3c19800a */ 	lui	$t9,%hi(g_RoomPtrs)
.L0f164648:
/*  f164648:	844e0000 */ 	lh	$t6,0x0($v0)
/*  f16464c:	256b0001 */ 	addiu	$t3,$t3,0x1
/*  f164650:	14ce0003 */ 	bne	$a2,$t6,.L0f164660
/*  f164654:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164658:	1000000b */ 	beqz	$zero,.L0f164688
/*  f16465c:	00091040 */ 	sll	$v0,$t1,0x1
.L0f164660:
/*  f164660:	1563fff9 */ 	bne	$t3,$v1,.L0f164648
/*  f164664:	24420002 */ 	addiu	$v0,$v0,0x2
.L0f164668:
/*  f164668:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f16466c:	0071082a */ 	slt	$at,$v1,$s1
/*  f164670:	10200008 */ 	beqz	$at,.L0f164694
/*  f164674:	a5e60000 */ 	sh	$a2,0x0($t7)
/*  f164678:	8f394928 */ 	lw	$t9,%lo(g_RoomPtrs)($t9)
/*  f16467c:	03274021 */ 	addu	$t0,$t9,$a3
/*  f164680:	81090005 */ 	lb	$t1,0x5($t0)
/*  f164684:	00091040 */ 	sll	$v0,$t1,0x1
.L0f164688:
/*  f164688:	00a2082a */ 	slt	$at,$a1,$v0
/*  f16468c:	5420ffdc */ 	bnezl	$at,.L0f164600
/*  f164690:	8518000e */ 	lh	$t8,0xe($t0)
.L0f164694:
/*  f164694:	0003c040 */ 	sll	$t8,$v1,0x1
/*  f164698:	02187821 */ 	addu	$t7,$s0,$t8
/*  f16469c:	240effff */ 	addiu	$t6,$zero,-1
/*  f1646a0:	a5ee0000 */ 	sh	$t6,0x0($t7)
/*  f1646a4:	8fb1000c */ 	lw	$s1,0xc($sp)
/*  f1646a8:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f1646ac:	27bd0010 */ 	addiu	$sp,$sp,0x10
/*  f1646b0:	03e00008 */ 	jr	$ra
/*  f1646b4:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f1646b8
/*  f1646b8:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f1646bc:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f1646c0:	3c0e800a */ 	lui	$t6,%hi(g_RoomPtrs)
/*  f1646c4:	8dce4928 */ 	lw	$t6,%lo(g_RoomPtrs)($t6)
/*  f1646c8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1646cc:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f1646d0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1646d4:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f1646d8:	80660005 */ 	lb	$a2,0x5($v1)
/*  f1646dc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1646e0:	3c18800a */ 	lui	$t8,%hi(var800a4ce0)
/*  f1646e4:	18c00015 */ 	blez	$a2,.L0f16473c
/*  f1646e8:	3c07800a */ 	lui	$a3,%hi(g_PortalSomethings)
/*  f1646ec:	8479000e */ 	lh	$t9,0xe($v1)
/*  f1646f0:	8f184ce0 */ 	lw	$t8,%lo(var800a4ce0)($t8)
/*  f1646f4:	8ce74cc8 */ 	lw	$a3,%lo(g_PortalSomethings)($a3)
/*  f1646f8:	00194840 */ 	sll	$t1,$t9,0x1
/*  f1646fc:	03092021 */ 	addu	$a0,$t8,$t1
.L0f164700:
/*  f164700:	84830000 */ 	lh	$v1,0x0($a0)
/*  f164704:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f164708:	0046082a */ 	slt	$at,$v0,$a2
/*  f16470c:	000350c0 */ 	sll	$t2,$v1,0x3
/*  f164710:	00ea4021 */ 	addu	$t0,$a3,$t2
/*  f164714:	850b0002 */ 	lh	$t3,0x2($t0)
/*  f164718:	10ab0004 */ 	beq	$a1,$t3,.L0f16472c
/*  f16471c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164720:	850c0004 */ 	lh	$t4,0x4($t0)
/*  f164724:	14ac0003 */ 	bne	$a1,$t4,.L0f164734
/*  f164728:	00000000 */ 	sll	$zero,$zero,0x0
.L0f16472c:
/*  f16472c:	03e00008 */ 	jr	$ra
/*  f164730:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f164734:
/*  f164734:	1420fff2 */ 	bnez	$at,.L0f164700
/*  f164738:	24840002 */ 	addiu	$a0,$a0,0x2
.L0f16473c:
/*  f16473c:	00001025 */ 	or	$v0,$zero,$zero
/*  f164740:	03e00008 */ 	jr	$ra
/*  f164744:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f164748
/*  f164748:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f16474c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f164750:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f164754:	3c10800a */ 	lui	$s0,%hi(g_Vars+0x284)
/*  f164758:	0c002f02 */ 	jal	func0000bc08
/*  f16475c:	8e10a244 */ 	lw	$s0,%lo(g_Vars+0x284)($s0)
/*  f164760:	44822000 */ 	mtc1	$v0,$f4
/*  f164764:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164768:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f16476c:	0c002f06 */ 	jal	func0000bc18
/*  f164770:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f164774:	44824000 */ 	mtc1	$v0,$f8
/*  f164778:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16477c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f164780:	0c002f40 */ 	jal	func0000bd00
/*  f164784:	e7aa0028 */ 	swc1	$f10,0x28($sp)
/*  f164788:	44828000 */ 	mtc1	$v0,$f16
/*  f16478c:	44801000 */ 	mtc1	$zero,$f2
/*  f164790:	46808020 */ 	cvt.s.w	$f0,$f16
/*  f164794:	4602003c */ 	c.lt.s	$f0,$f2
/*  f164798:	e6001794 */ 	swc1	$f0,0x1794($s0)
/*  f16479c:	45020003 */ 	bc1fl	.L0f1647ac
/*  f1647a0:	c7a00030 */ 	lwc1	$f0,0x30($sp)
/*  f1647a4:	e6021794 */ 	swc1	$f2,0x1794($s0)
/*  f1647a8:	c7a00030 */ 	lwc1	$f0,0x30($sp)
.L0f1647ac:
/*  f1647ac:	c6121794 */ 	lwc1	$f18,0x1794($s0)
/*  f1647b0:	4612003c */ 	c.lt.s	$f0,$f18
/*  f1647b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1647b8:	45000002 */ 	bc1f	.L0f1647c4
/*  f1647bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1647c0:	e6001794 */ 	swc1	$f0,0x1794($s0)
.L0f1647c4:
/*  f1647c4:	0c002f44 */ 	jal	func0000bd10
/*  f1647c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1647cc:	44822000 */ 	mtc1	$v0,$f4
/*  f1647d0:	44801000 */ 	mtc1	$zero,$f2
/*  f1647d4:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f1647d8:	4602003c */ 	c.lt.s	$f0,$f2
/*  f1647dc:	e6001798 */ 	swc1	$f0,0x1798($s0)
/*  f1647e0:	45020003 */ 	bc1fl	.L0f1647f0
/*  f1647e4:	c7a00028 */ 	lwc1	$f0,0x28($sp)
/*  f1647e8:	e6021798 */ 	swc1	$f2,0x1798($s0)
/*  f1647ec:	c7a00028 */ 	lwc1	$f0,0x28($sp)
.L0f1647f0:
/*  f1647f0:	c6061798 */ 	lwc1	$f6,0x1798($s0)
/*  f1647f4:	4606003c */ 	c.lt.s	$f0,$f6
/*  f1647f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1647fc:	45000002 */ 	bc1f	.L0f164808
/*  f164800:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164804:	e6001798 */ 	swc1	$f0,0x1798($s0)
.L0f164808:
/*  f164808:	0c002f40 */ 	jal	func0000bd00
/*  f16480c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164810:	0c002f22 */ 	jal	func0000bc88
/*  f164814:	a7a20022 */ 	sh	$v0,0x22($sp)
/*  f164818:	87ae0022 */ 	lh	$t6,0x22($sp)
/*  f16481c:	44801000 */ 	mtc1	$zero,$f2
/*  f164820:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f164824:	448f4000 */ 	mtc1	$t7,$f8
/*  f164828:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16482c:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f164830:	4602003c */ 	c.lt.s	$f0,$f2
/*  f164834:	e600179c */ 	swc1	$f0,0x179c($s0)
/*  f164838:	45020003 */ 	bc1fl	.L0f164848
/*  f16483c:	c7aa0030 */ 	lwc1	$f10,0x30($sp)
/*  f164840:	e602179c */ 	swc1	$f2,0x179c($s0)
/*  f164844:	c7aa0030 */ 	lwc1	$f10,0x30($sp)
.L0f164848:
/*  f164848:	c610179c */ 	lwc1	$f16,0x179c($s0)
/*  f16484c:	4610503c */ 	c.lt.s	$f10,$f16
/*  f164850:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164854:	45000002 */ 	bc1f	.L0f164860
/*  f164858:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16485c:	e60a179c */ 	swc1	$f10,0x179c($s0)
.L0f164860:
/*  f164860:	0c002f44 */ 	jal	func0000bd10
/*  f164864:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164868:	0c002f26 */ 	jal	func0000bc98
/*  f16486c:	a7a20022 */ 	sh	$v0,0x22($sp)
/*  f164870:	87b80022 */ 	lh	$t8,0x22($sp)
/*  f164874:	44801000 */ 	mtc1	$zero,$f2
/*  f164878:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f16487c:	44999000 */ 	mtc1	$t9,$f18
/*  f164880:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164884:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f164888:	4602003c */ 	c.lt.s	$f0,$f2
/*  f16488c:	e60017a0 */ 	swc1	$f0,0x17a0($s0)
/*  f164890:	45020003 */ 	bc1fl	.L0f1648a0
/*  f164894:	c7a40028 */ 	lwc1	$f4,0x28($sp)
/*  f164898:	e60217a0 */ 	swc1	$f2,0x17a0($s0)
/*  f16489c:	c7a40028 */ 	lwc1	$f4,0x28($sp)
.L0f1648a0:
/*  f1648a0:	c60617a0 */ 	lwc1	$f6,0x17a0($s0)
/*  f1648a4:	4606203c */ 	c.lt.s	$f4,$f6
/*  f1648a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1648ac:	45020003 */ 	bc1fl	.L0f1648bc
/*  f1648b0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1648b4:	e60417a0 */ 	swc1	$f4,0x17a0($s0)
/*  f1648b8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f1648bc:
/*  f1648bc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1648c0:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f1648c4:	03e00008 */ 	jr	$ra
/*  f1648c8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1648cc
/*  f1648cc:	000430c0 */ 	sll	$a2,$a0,0x3
/*  f1648d0:	00c43021 */ 	addu	$a2,$a2,$a0
/*  f1648d4:	3c02800a */ 	lui	$v0,%hi(g_RoomPtrs)
/*  f1648d8:	8c424928 */ 	lw	$v0,%lo(g_RoomPtrs)($v0)
/*  f1648dc:	27bdfff0 */ 	addiu	$sp,$sp,-16
/*  f1648e0:	00063080 */ 	sll	$a2,$a2,0x2
/*  f1648e4:	00c43023 */ 	subu	$a2,$a2,$a0
/*  f1648e8:	00063080 */ 	sll	$a2,$a2,0x2
/*  f1648ec:	afb2000c */ 	sw	$s2,0xc($sp)
/*  f1648f0:	afb10008 */ 	sw	$s1,0x8($sp)
/*  f1648f4:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f1648f8:	00463821 */ 	addu	$a3,$v0,$a2
/*  f1648fc:	80e80005 */ 	lb	$t0,0x5($a3)
/*  f164900:	00001825 */ 	or	$v1,$zero,$zero
/*  f164904:	00002825 */ 	or	$a1,$zero,$zero
/*  f164908:	19000047 */ 	blez	$t0,.L0f164a28
/*  f16490c:	00005025 */ 	or	$t2,$zero,$zero
/*  f164910:	3c11800a */ 	lui	$s1,%hi(g_PortalSomethings)
/*  f164914:	3c10800a */ 	lui	$s0,%hi(var800a4ce0)
/*  f164918:	26104ce0 */ 	addiu	$s0,$s0,%lo(var800a4ce0)
/*  f16491c:	26314cc8 */ 	addiu	$s1,$s1,%lo(g_PortalSomethings)
/*  f164920:	2412000c */ 	addiu	$s2,$zero,0xc
.L0f164924:
/*  f164924:	84ef000e */ 	lh	$t7,0xe($a3)
/*  f164928:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f16492c:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f164930:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f164934:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f164938:	032a7821 */ 	addu	$t7,$t9,$t2
/*  f16493c:	85e90000 */ 	lh	$t1,0x0($t7)
/*  f164940:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f164944:	00006825 */ 	or	$t5,$zero,$zero
/*  f164948:	000970c0 */ 	sll	$t6,$t1,0x3
/*  f16494c:	018ec021 */ 	addu	$t8,$t4,$t6
/*  f164950:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f164954:	032c5821 */ 	addu	$t3,$t9,$t4
/*  f164958:	916f0000 */ 	lbu	$t7,0x0($t3)
/*  f16495c:	59e00030 */ 	blezl	$t7,.L0f164a20
/*  f164960:	00a8082a */ 	slt	$at,$a1,$t0
/*  f164964:	01604025 */ 	or	$t0,$t3,$zero
/*  f164968:	00004825 */ 	or	$t1,$zero,$zero
.L0f16496c:
/*  f16496c:	01006025 */ 	or	$t4,$t0,$zero
.L0f164970:
/*  f164970:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f164974:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f164978:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f16497c:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f164980:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f164984:	004ec021 */ 	addu	$t8,$v0,$t6
/*  f164988:	03093821 */ 	addu	$a3,$t8,$t1
/*  f16498c:	c5800004 */ 	lwc1	$f0,0x4($t4)
/*  f164990:	c4e40018 */ 	lwc1	$f4,0x18($a3)
/*  f164994:	0004c8c0 */ 	sll	$t9,$a0,0x3
/*  f164998:	0324c821 */ 	addu	$t9,$t9,$a0
/*  f16499c:	4604003c */ 	c.lt.s	$f0,$f4
/*  f1649a0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1649a4:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f1649a8:	45020009 */ 	bc1fl	.L0f1649d0
/*  f1649ac:	c4e60024 */ 	lwc1	$f6,0x24($a3)
/*  f1649b0:	e4e00018 */ 	swc1	$f0,0x18($a3)
/*  f1649b4:	3c02800a */ 	lui	$v0,%hi(g_RoomPtrs)
/*  f1649b8:	8c424928 */ 	lw	$v0,%lo(g_RoomPtrs)($v0)
/*  f1649bc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1649c0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1649c4:	00597821 */ 	addu	$t7,$v0,$t9
/*  f1649c8:	01e93821 */ 	addu	$a3,$t7,$t1
/*  f1649cc:	c4e60024 */ 	lwc1	$f6,0x24($a3)
.L0f1649d0:
/*  f1649d0:	25290004 */ 	addiu	$t1,$t1,0x4
/*  f1649d4:	4600303c */ 	c.lt.s	$f6,$f0
/*  f1649d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1649dc:	45000005 */ 	bc1f	.L0f1649f4
/*  f1649e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1649e4:	e4e00024 */ 	swc1	$f0,0x24($a3)
/*  f1649e8:	3c02800a */ 	lui	$v0,%hi(g_RoomPtrs)
/*  f1649ec:	8c424928 */ 	lw	$v0,%lo(g_RoomPtrs)($v0)
/*  f1649f0:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f1649f4:
/*  f1649f4:	1532ffde */ 	bne	$t1,$s2,.L0f164970
/*  f1649f8:	258c0004 */ 	addiu	$t4,$t4,0x4
/*  f1649fc:	91670000 */ 	lbu	$a3,0x0($t3)
/*  f164a00:	25ad0001 */ 	addiu	$t5,$t5,0x1
/*  f164a04:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f164a08:	01a7082a */ 	slt	$at,$t5,$a3
/*  f164a0c:	5420ffd7 */ 	bnezl	$at,.L0f16496c
/*  f164a10:	00004825 */ 	or	$t1,$zero,$zero
/*  f164a14:	00463821 */ 	addu	$a3,$v0,$a2
/*  f164a18:	80e80005 */ 	lb	$t0,0x5($a3)
/*  f164a1c:	00a8082a */ 	slt	$at,$a1,$t0
.L0f164a20:
/*  f164a20:	1420ffc0 */ 	bnez	$at,.L0f164924
/*  f164a24:	254a0002 */ 	addiu	$t2,$t2,0x2
.L0f164a28:
/*  f164a28:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f164a2c:	8fb10008 */ 	lw	$s1,0x8($sp)
/*  f164a30:	8fb2000c */ 	lw	$s2,0xc($sp)
/*  f164a34:	03e00008 */ 	jr	$ra
/*  f164a38:	27bd0010 */ 	addiu	$sp,$sp,0x10
/*  f164a3c:	3c03800a */ 	lui	$v1,%hi(g_PortalSomethings)
/*  f164a40:	8c634cc8 */ 	lw	$v1,%lo(g_PortalSomethings)($v1)
/*  f164a44:	00001025 */ 	or	$v0,$zero,$zero
/*  f164a48:	946e0000 */ 	lhu	$t6,0x0($v1)
/*  f164a4c:	51c0000c */ 	beqzl	$t6,.L0f164a80
/*  f164a50:	00001025 */ 	or	$v0,$zero,$zero
.L0f164a54:
/*  f164a54:	54440004 */ 	bnel	$v0,$a0,.L0f164a68
/*  f164a58:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f164a5c:	03e00008 */ 	jr	$ra
/*  f164a60:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f164a64:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f164a68:
/*  f164a68:	000278c0 */ 	sll	$t7,$v0,0x3
/*  f164a6c:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f164a70:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f164a74:	1720fff7 */ 	bnez	$t9,.L0f164a54
/*  f164a78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164a7c:	00001025 */ 	or	$v0,$zero,$zero
.L0f164a80:
/*  f164a80:	03e00008 */ 	jr	$ra
/*  f164a84:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f164a88
/*  f164a88:	3c06800a */ 	lui	$a2,%hi(g_PortalSomethings)
/*  f164a8c:	24c64cc8 */ 	addiu	$a2,$a2,%lo(g_PortalSomethings)
/*  f164a90:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f164a94:	000418c0 */ 	sll	$v1,$a0,0x3
/*  f164a98:	01c32821 */ 	addu	$a1,$t6,$v1
/*  f164a9c:	84af0004 */ 	lh	$t7,0x4($a1)
/*  f164aa0:	84a20002 */ 	lh	$v0,0x2($a1)
/*  f164aa4:	a4af0002 */ 	sh	$t7,0x2($a1)
/*  f164aa8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f164aac:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f164ab0:	03e00008 */ 	jr	$ra
/*  f164ab4:	a7220004 */ 	sh	$v0,0x4($t9)
);

GLOBAL_ASM(
glabel func0f164ab8
/*  f164ab8:	3c0e800a */ 	lui	$t6,%hi(g_PortalSomethings)
/*  f164abc:	8dce4cc8 */ 	lw	$t6,%lo(g_PortalSomethings)($t6)
/*  f164ac0:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f164ac4:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f164ac8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f164acc:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f164ad0:	84c80002 */ 	lh	$t0,0x2($a2)
/*  f164ad4:	240a008c */ 	addiu	$t2,$zero,0x8c
/*  f164ad8:	3c07800a */ 	lui	$a3,%hi(g_RoomPtrs)
/*  f164adc:	010a0019 */ 	multu	$t0,$t2
/*  f164ae0:	8ce74928 */ 	lw	$a3,%lo(g_RoomPtrs)($a3)
/*  f164ae4:	84c90004 */ 	lh	$t1,0x4($a2)
/*  f164ae8:	3c0c800a */ 	lui	$t4,%hi(var800a4ccc)
/*  f164aec:	8d8c4ccc */ 	lw	$t4,%lo(var800a4ccc)($t4)
/*  f164af0:	00045880 */ 	sll	$t3,$a0,0x2
/*  f164af4:	01645821 */ 	addu	$t3,$t3,$a0
/*  f164af8:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f164afc:	016c1021 */ 	addu	$v0,$t3,$t4
/*  f164b00:	0000c012 */ 	mflo	$t8
/*  f164b04:	00f81821 */ 	addu	$v1,$a3,$t8
/*  f164b08:	c4640030 */ 	lwc1	$f4,0x30($v1)
/*  f164b0c:	012a0019 */ 	multu	$t1,$t2
/*  f164b10:	e7a4004c */ 	swc1	$f4,0x4c($sp)
/*  f164b14:	c4660034 */ 	lwc1	$f6,0x34($v1)
/*  f164b18:	e7a60050 */ 	swc1	$f6,0x50($sp)
/*  f164b1c:	c4680038 */ 	lwc1	$f8,0x38($v1)
/*  f164b20:	0000c812 */ 	mflo	$t9
/*  f164b24:	00f92821 */ 	addu	$a1,$a3,$t9
/*  f164b28:	e7a80054 */ 	swc1	$f8,0x54($sp)
/*  f164b2c:	c4aa0030 */ 	lwc1	$f10,0x30($a1)
/*  f164b30:	e7aa0040 */ 	swc1	$f10,0x40($sp)
/*  f164b34:	c4b00034 */ 	lwc1	$f16,0x34($a1)
/*  f164b38:	e7b00044 */ 	swc1	$f16,0x44($sp)
/*  f164b3c:	c4b20038 */ 	lwc1	$f18,0x38($a1)
/*  f164b40:	e7b20048 */ 	swc1	$f18,0x48($sp)
/*  f164b44:	c4440000 */ 	lwc1	$f4,0x0($v0)
/*  f164b48:	e7a40028 */ 	swc1	$f4,0x28($sp)
/*  f164b4c:	c4460004 */ 	lwc1	$f6,0x4($v0)
/*  f164b50:	c7b20028 */ 	lwc1	$f18,0x28($sp)
/*  f164b54:	c7a4004c */ 	lwc1	$f4,0x4c($sp)
/*  f164b58:	e7a6002c */ 	swc1	$f6,0x2c($sp)
/*  f164b5c:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f164b60:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f164b64:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f164b68:	e7a80030 */ 	swc1	$f8,0x30($sp)
/*  f164b6c:	c44a000c */ 	lwc1	$f10,0xc($v0)
/*  f164b70:	c7a8002c */ 	lwc1	$f8,0x2c($sp)
/*  f164b74:	e7aa0034 */ 	swc1	$f10,0x34($sp)
/*  f164b78:	c4500010 */ 	lwc1	$f16,0x10($v0)
/*  f164b7c:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*  f164b80:	00001025 */ 	or	$v0,$zero,$zero
/*  f164b84:	e7b00038 */ 	swc1	$f16,0x38($sp)
/*  f164b88:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f164b8c:	c7a80030 */ 	lwc1	$f8,0x30($sp)
/*  f164b90:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f164b94:	46103480 */ 	add.s	$f18,$f6,$f16
/*  f164b98:	c7a60038 */ 	lwc1	$f6,0x38($sp)
/*  f164b9c:	46125080 */ 	add.s	$f2,$f10,$f18
/*  f164ba0:	4602303c */ 	c.lt.s	$f6,$f2
/*  f164ba4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164ba8:	45020017 */ 	bc1fl	.L0f164c08
/*  f164bac:	c7aa0028 */ 	lwc1	$f10,0x28($sp)
/*  f164bb0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f164bb4:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f164bb8:	0fc592a2 */ 	jal	func0f164a88
/*  f164bbc:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f164bc0:	c7b00028 */ 	lwc1	$f16,0x28($sp)
/*  f164bc4:	c7a8002c */ 	lwc1	$f8,0x2c($sp)
/*  f164bc8:	c7b20030 */ 	lwc1	$f18,0x30($sp)
/*  f164bcc:	46008107 */ 	neg.s	$f4,$f16
/*  f164bd0:	c7a00034 */ 	lwc1	$f0,0x34($sp)
/*  f164bd4:	c7b00038 */ 	lwc1	$f16,0x38($sp)
/*  f164bd8:	46004287 */ 	neg.s	$f10,$f8
/*  f164bdc:	e7a40028 */ 	swc1	$f4,0x28($sp)
/*  f164be0:	46009187 */ 	neg.s	$f6,$f18
/*  f164be4:	46000207 */ 	neg.s	$f8,$f0
/*  f164be8:	46008107 */ 	neg.s	$f4,$f16
/*  f164bec:	8fa20018 */ 	lw	$v0,0x18($sp)
/*  f164bf0:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f164bf4:	e7aa002c */ 	swc1	$f10,0x2c($sp)
/*  f164bf8:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f164bfc:	e7a40034 */ 	swc1	$f4,0x34($sp)
/*  f164c00:	e7a80038 */ 	swc1	$f8,0x38($sp)
/*  f164c04:	c7aa0028 */ 	lwc1	$f10,0x28($sp)
.L0f164c08:
/*  f164c08:	c7b20040 */ 	lwc1	$f18,0x40($sp)
/*  f164c0c:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*  f164c10:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f164c14:	46125182 */ 	mul.s	$f6,$f10,$f18
/*  f164c18:	c7b20048 */ 	lwc1	$f18,0x48($sp)
/*  f164c1c:	46048202 */ 	mul.s	$f8,$f16,$f4
/*  f164c20:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*  f164c24:	46109102 */ 	mul.s	$f4,$f18,$f16
/*  f164c28:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f164c2c:	c7a60034 */ 	lwc1	$f6,0x34($sp)
/*  f164c30:	460a2000 */ 	add.s	$f0,$f4,$f10
/*  f164c34:	4606003e */ 	c.le.s	$f0,$f6
/*  f164c38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164c3c:	45020006 */ 	bc1fl	.L0f164c58
/*  f164c40:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f164c44:	50400004 */ 	beqzl	$v0,.L0f164c58
/*  f164c48:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f164c4c:	0fc592a2 */ 	jal	func0f164a88
/*  f164c50:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f164c54:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f164c58:
/*  f164c58:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f164c5c:	03e00008 */ 	jr	$ra
/*  f164c60:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f164c64
/*  f164c64:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f164c68:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f164c6c:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f164c70:	3c0e800a */ 	lui	$t6,%hi(g_RoomPtrs)
/*  f164c74:	8dce4928 */ 	lw	$t6,%lo(g_RoomPtrs)($t6)
/*  f164c78:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f164c7c:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f164c80:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f164c84:	afb30014 */ 	sw	$s3,0x14($sp)
/*  f164c88:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f164c8c:	afb1000c */ 	sw	$s1,0xc($sp)
/*  f164c90:	afb00008 */ 	sw	$s0,0x8($sp)
/*  f164c94:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f164c98:	80780005 */ 	lb	$t8,0x5($v1)
/*  f164c9c:	00001025 */ 	or	$v0,$zero,$zero
/*  f164ca0:	3c07800a */ 	lui	$a3,%hi(var800a4ce0)
/*  f164ca4:	1b000062 */ 	blez	$t8,.L0f164e30
/*  f164ca8:	00004025 */ 	or	$t0,$zero,$zero
/*  f164cac:	3c09800a */ 	lui	$t1,%hi(var800a4ccc)
/*  f164cb0:	3c0a800a */ 	lui	$t2,%hi(g_PortalSomethings)
/*  f164cb4:	8d4a4cc8 */ 	lw	$t2,%lo(g_PortalSomethings)($t2)
/*  f164cb8:	8d294ccc */ 	lw	$t1,%lo(var800a4ccc)($t1)
/*  f164cbc:	8ce74ce0 */ 	lw	$a3,%lo(var800a4ce0)($a3)
/*  f164cc0:	24130014 */ 	addiu	$s3,$zero,0x14
.L0f164cc4:
/*  f164cc4:	8479000e */ 	lh	$t9,0xe($v1)
/*  f164cc8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f164ccc:	00197040 */ 	sll	$t6,$t9,0x1
/*  f164cd0:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f164cd4:	01e8c021 */ 	addu	$t8,$t7,$t0
/*  f164cd8:	87060000 */ 	lh	$a2,0x0($t8)
/*  f164cdc:	00d30019 */ 	multu	$a2,$s3
/*  f164ce0:	000670c0 */ 	sll	$t6,$a2,0x3
/*  f164ce4:	014e7821 */ 	addu	$t7,$t2,$t6
/*  f164ce8:	0000c812 */ 	mflo	$t9
/*  f164cec:	03292821 */ 	addu	$a1,$t9,$t1
/*  f164cf0:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*  f164cf4:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f164cf8:	c4a60004 */ 	lwc1	$f6,0x4($a1)
/*  f164cfc:	c7b2001c */ 	lwc1	$f18,0x1c($sp)
/*  f164d00:	e7a60020 */ 	swc1	$f6,0x20($sp)
/*  f164d04:	c4a80008 */ 	lwc1	$f8,0x8($a1)
/*  f164d08:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f164d0c:	c4aa000c */ 	lwc1	$f10,0xc($a1)
/*  f164d10:	e7aa0028 */ 	swc1	$f10,0x28($sp)
/*  f164d14:	c4b00010 */ 	lwc1	$f16,0x10($a1)
/*  f164d18:	e7b0002c */ 	swc1	$f16,0x2c($sp)
/*  f164d1c:	85f80002 */ 	lh	$t8,0x2($t7)
/*  f164d20:	54980010 */ 	bnel	$a0,$t8,.L0f164d64
/*  f164d24:	80650005 */ 	lb	$a1,0x5($v1)
/*  f164d28:	c7a60020 */ 	lwc1	$f6,0x20($sp)
/*  f164d2c:	46009107 */ 	neg.s	$f4,$f18
/*  f164d30:	c7aa0024 */ 	lwc1	$f10,0x24($sp)
/*  f164d34:	c7a00028 */ 	lwc1	$f0,0x28($sp)
/*  f164d38:	c7b2002c */ 	lwc1	$f18,0x2c($sp)
/*  f164d3c:	46003207 */ 	neg.s	$f8,$f6
/*  f164d40:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f164d44:	46005407 */ 	neg.s	$f16,$f10
/*  f164d48:	46000187 */ 	neg.s	$f6,$f0
/*  f164d4c:	46009107 */ 	neg.s	$f4,$f18
/*  f164d50:	e7a80020 */ 	swc1	$f8,0x20($sp)
/*  f164d54:	e7b00024 */ 	swc1	$f16,0x24($sp)
/*  f164d58:	e7a40028 */ 	swc1	$f4,0x28($sp)
/*  f164d5c:	e7a6002c */ 	swc1	$f6,0x2c($sp)
/*  f164d60:	80650005 */ 	lb	$a1,0x5($v1)
.L0f164d64:
/*  f164d64:	58a00030 */ 	blezl	$a1,.L0f164e28
/*  f164d68:	0045082a */ 	slt	$at,$v0,$a1
/*  f164d6c:	8479000e */ 	lh	$t9,0xe($v1)
/*  f164d70:	00006025 */ 	or	$t4,$zero,$zero
/*  f164d74:	00197040 */ 	sll	$t6,$t9,0x1
/*  f164d78:	00ee6821 */ 	addu	$t5,$a3,$t6
.L0f164d7c:
/*  f164d7c:	85ab0000 */ 	lh	$t3,0x0($t5)
/*  f164d80:	258c0002 */ 	addiu	$t4,$t4,0x2
/*  f164d84:	15660003 */ 	bne	$t3,$a2,.L0f164d94
/*  f164d88:	000b78c0 */ 	sll	$t7,$t3,0x3
/*  f164d8c:	10000022 */ 	beqz	$zero,.L0f164e18
/*  f164d90:	00055840 */ 	sll	$t3,$a1,0x1
.L0f164d94:
/*  f164d94:	014fc021 */ 	addu	$t8,$t2,$t7
/*  f164d98:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f164d9c:	00008825 */ 	or	$s1,$zero,$zero
/*  f164da0:	032a8021 */ 	addu	$s0,$t9,$t2
/*  f164da4:	92120000 */ 	lbu	$s2,0x0($s0)
/*  f164da8:	02005825 */ 	or	$t3,$s0,$zero
/*  f164dac:	5a40001a */ 	blezl	$s2,.L0f164e18
/*  f164db0:	00055840 */ 	sll	$t3,$a1,0x1
.L0f164db4:
/*  f164db4:	c7a8001c */ 	lwc1	$f8,0x1c($sp)
/*  f164db8:	c56a0004 */ 	lwc1	$f10,0x4($t3)
/*  f164dbc:	c7b20020 */ 	lwc1	$f18,0x20($sp)
/*  f164dc0:	c5640008 */ 	lwc1	$f4,0x8($t3)
/*  f164dc4:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f164dc8:	c56a000c */ 	lwc1	$f10,0xc($t3)
/*  f164dcc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f164dd0:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f164dd4:	c7b20024 */ 	lwc1	$f18,0x24($sp)
/*  f164dd8:	0232082a */ 	slt	$at,$s1,$s2
/*  f164ddc:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f164de0:	46068200 */ 	add.s	$f8,$f16,$f6
/*  f164de4:	c7b00028 */ 	lwc1	$f16,0x28($sp)
/*  f164de8:	46082000 */ 	add.s	$f0,$f4,$f8
/*  f164dec:	4610003c */ 	c.lt.s	$f0,$f16
/*  f164df0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164df4:	45000005 */ 	bc1f	.L0f164e0c
/*  f164df8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164dfc:	946e0000 */ 	lhu	$t6,0x0($v1)
/*  f164e00:	35cf0010 */ 	ori	$t7,$t6,0x10
/*  f164e04:	1000000a */ 	beqz	$zero,.L0f164e30
/*  f164e08:	a46f0000 */ 	sh	$t7,0x0($v1)
.L0f164e0c:
/*  f164e0c:	1420ffe9 */ 	bnez	$at,.L0f164db4
/*  f164e10:	256b000c */ 	addiu	$t3,$t3,0xc
/*  f164e14:	00055840 */ 	sll	$t3,$a1,0x1
.L0f164e18:
/*  f164e18:	018b082a */ 	slt	$at,$t4,$t3
/*  f164e1c:	1420ffd7 */ 	bnez	$at,.L0f164d7c
/*  f164e20:	25ad0002 */ 	addiu	$t5,$t5,0x2
/*  f164e24:	0045082a */ 	slt	$at,$v0,$a1
.L0f164e28:
/*  f164e28:	1420ffa6 */ 	bnez	$at,.L0f164cc4
/*  f164e2c:	25080002 */ 	addiu	$t0,$t0,0x2
.L0f164e30:
/*  f164e30:	8fb00008 */ 	lw	$s0,0x8($sp)
/*  f164e34:	8fb1000c */ 	lw	$s1,0xc($sp)
/*  f164e38:	8fb20010 */ 	lw	$s2,0x10($sp)
/*  f164e3c:	8fb30014 */ 	lw	$s3,0x14($sp)
/*  f164e40:	03e00008 */ 	jr	$ra
/*  f164e44:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel portalSetEnabled
/*  f164e48:	3c0e800a */ 	lui	$t6,%hi(g_PortalSomethings)
/*  f164e4c:	8dce4cc8 */ 	lw	$t6,%lo(g_PortalSomethings)($t6)
/*  f164e50:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f164e54:	0005402b */ 	sltu	$t0,$zero,$a1
/*  f164e58:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f164e5c:	90580006 */ 	lbu	$t8,0x6($v0)
/*  f164e60:	37190001 */ 	ori	$t9,$t8,0x1
/*  f164e64:	03284826 */ 	xor	$t1,$t9,$t0
/*  f164e68:	03e00008 */ 	jr	$ra
/*  f164e6c:	a0490006 */ 	sb	$t1,0x6($v0)
/*  f164e70:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f164e74:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f164e78:	03e00008 */ 	jr	$ra
/*  f164e7c:	00801025 */ 	or	$v0,$a0,$zero
/*  f164e80:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f164e84:	03e00008 */ 	jr	$ra
/*  f164e88:	afa50004 */ 	sw	$a1,0x4($sp)
);

GLOBAL_ASM(
glabel func0f164e8c
.late_rodata
glabel var7f1b76c4
.word 0x7f7fffff
.text
/*  f164e8c:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f164e90:	afb6003c */ 	sw	$s6,0x3c($sp)
/*  f164e94:	3c16800a */ 	lui	$s6,%hi(g_PortalSomethings)
/*  f164e98:	26d64cc8 */ 	addiu	$s6,$s6,%lo(g_PortalSomethings)
/*  f164e9c:	8ece0000 */ 	lw	$t6,0x0($s6)
/*  f164ea0:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f164ea4:	afb70040 */ 	sw	$s7,0x40($sp)
/*  f164ea8:	afb50038 */ 	sw	$s5,0x38($sp)
/*  f164eac:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f164eb0:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f164eb4:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f164eb8:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f164ebc:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f164ec0:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f164ec4:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f164ec8:	95cf0000 */ 	lhu	$t7,0x0($t6)
/*  f164ecc:	3c017f1b */ 	lui	$at,%hi(var7f1b76c4)
/*  f164ed0:	0080a025 */ 	or	$s4,$a0,$zero
/*  f164ed4:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f164ed8:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f164edc:	00008825 */ 	or	$s1,$zero,$zero
/*  f164ee0:	c43476c4 */ 	lwc1	$f20,%lo(var7f1b76c4)($at)
/*  f164ee4:	11e0001f */ 	beqz	$t7,.L0f164f64
/*  f164ee8:	00008025 */ 	or	$s0,$zero,$zero
/*  f164eec:	3c178008 */ 	lui	$s7,%hi(var8007fcb4)
/*  f164ef0:	4480b000 */ 	mtc1	$zero,$f22
/*  f164ef4:	26f7fcb4 */ 	addiu	$s7,$s7,%lo(var8007fcb4)
/*  f164ef8:	00009025 */ 	or	$s2,$zero,$zero
/*  f164efc:	02002025 */ 	or	$a0,$s0,$zero
.L0f164f00:
/*  f164f00:	02802825 */ 	or	$a1,$s4,$zero
/*  f164f04:	0c005f8c */ 	jal	func00017e30
/*  f164f08:	02a03025 */ 	or	$a2,$s5,$zero
/*  f164f0c:	5040000f */ 	beqzl	$v0,.L0f164f4c
/*  f164f10:	8ed80000 */ 	lw	$t8,0x0($s6)
/*  f164f14:	c6e00000 */ 	lwc1	$f0,0x0($s7)
/*  f164f18:	4616003c */ 	c.lt.s	$f0,$f22
/*  f164f1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164f20:	45020003 */ 	bc1fl	.L0f164f30
/*  f164f24:	4614003c */ 	c.lt.s	$f0,$f20
/*  f164f28:	46000007 */ 	neg.s	$f0,$f0
/*  f164f2c:	4614003c */ 	c.lt.s	$f0,$f20
.L0f164f30:
/*  f164f30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164f34:	45020005 */ 	bc1fl	.L0f164f4c
/*  f164f38:	8ed80000 */ 	lw	$t8,0x0($s6)
/*  f164f3c:	02009825 */ 	or	$s3,$s0,$zero
/*  f164f40:	46000506 */ 	mov.s	$f20,$f0
/*  f164f44:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f164f48:	8ed80000 */ 	lw	$t8,0x0($s6)
.L0f164f4c:
/*  f164f4c:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f164f50:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f164f54:	0312c821 */ 	addu	$t9,$t8,$s2
/*  f164f58:	97280000 */ 	lhu	$t0,0x0($t9)
/*  f164f5c:	5500ffe8 */ 	bnezl	$t0,.L0f164f00
/*  f164f60:	02002025 */ 	or	$a0,$s0,$zero
.L0f164f64:
/*  f164f64:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f164f68:	02601025 */ 	or	$v0,$s3,$zero
/*  f164f6c:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f164f70:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f164f74:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f164f78:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f164f7c:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f164f80:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f164f84:	8fb40034 */ 	lw	$s4,0x34($sp)
/*  f164f88:	8fb50038 */ 	lw	$s5,0x38($sp)
/*  f164f8c:	8fb6003c */ 	lw	$s6,0x3c($sp)
/*  f164f90:	8fb70040 */ 	lw	$s7,0x40($sp)
/*  f164f94:	03e00008 */ 	jr	$ra
/*  f164f98:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f164f9c
/*  f164f9c:	00001825 */ 	or	$v1,$zero,$zero
/*  f164fa0:	00a04025 */ 	or	$t0,$a1,$zero
/*  f164fa4:	00c04825 */ 	or	$t1,$a2,$zero
/*  f164fa8:	2402000c */ 	addiu	$v0,$zero,0xc
.L0f164fac:
/*  f164fac:	c5040000 */ 	lwc1	$f4,0x0($t0)
/*  f164fb0:	c5260000 */ 	lwc1	$f6,0x0($t1)
/*  f164fb4:	00e37021 */ 	addu	$t6,$a3,$v1
/*  f164fb8:	00837821 */ 	addu	$t7,$a0,$v1
/*  f164fbc:	4606203c */ 	c.lt.s	$f4,$f6
/*  f164fc0:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f164fc4:	25080004 */ 	addiu	$t0,$t0,0x4
/*  f164fc8:	45010007 */ 	bc1t	.L0f164fe8
/*  f164fcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164fd0:	c5c80000 */ 	lwc1	$f8,0x0($t6)
/*  f164fd4:	c5ea0000 */ 	lwc1	$f10,0x0($t7)
/*  f164fd8:	460a403c */ 	c.lt.s	$f8,$f10
/*  f164fdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f164fe0:	45000003 */ 	bc1f	.L0f164ff0
/*  f164fe4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f164fe8:
/*  f164fe8:	03e00008 */ 	jr	$ra
/*  f164fec:	00001025 */ 	or	$v0,$zero,$zero
.L0f164ff0:
/*  f164ff0:	1462ffee */ 	bne	$v1,$v0,.L0f164fac
/*  f164ff4:	25290004 */ 	addiu	$t1,$t1,0x4
/*  f164ff8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f164ffc:	03e00008 */ 	jr	$ra
/*  f165000:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f165004
.late_rodata
glabel var7f1b76c8
.word 0x7f7fffff
glabel var7f1b76cc
.word 0xff7fffff
.text
/*  f165004:	3c017f1b */ 	lui	$at,%hi(var7f1b76c8)
/*  f165008:	c42076c8 */ 	lwc1	$f0,%lo(var7f1b76c8)($at)
/*  f16500c:	3c017f1b */ 	lui	$at,%hi(var7f1b76cc)
/*  f165010:	c42276cc */ 	lwc1	$f2,%lo(var7f1b76cc)($at)
/*  f165014:	e4a00000 */ 	swc1	$f0,0x0($a1)
/*  f165018:	e4a00004 */ 	swc1	$f0,0x4($a1)
/*  f16501c:	e4a00008 */ 	swc1	$f0,0x8($a1)
/*  f165020:	3c03800a */ 	lui	$v1,%hi(g_PortalSomethings)
/*  f165024:	e4c20000 */ 	swc1	$f2,0x0($a2)
/*  f165028:	e4c20004 */ 	swc1	$f2,0x4($a2)
/*  f16502c:	e4c20008 */ 	swc1	$f2,0x8($a2)
/*  f165030:	8c634cc8 */ 	lw	$v1,%lo(g_PortalSomethings)($v1)
/*  f165034:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f165038:	00003825 */ 	or	$a3,$zero,$zero
/*  f16503c:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f165040:	95f80000 */ 	lhu	$t8,0x0($t7)
/*  f165044:	240c000c */ 	addiu	$t4,$zero,0xc
/*  f165048:	03031021 */ 	addu	$v0,$t8,$v1
/*  f16504c:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f165050:	00402025 */ 	or	$a0,$v0,$zero
/*  f165054:	1b20001c */ 	blez	$t9,.L0f1650c8
/*  f165058:	00004025 */ 	or	$t0,$zero,$zero
.L0f16505c:
/*  f16505c:	00804825 */ 	or	$t1,$a0,$zero
/*  f165060:	00a05025 */ 	or	$t2,$a1,$zero
/*  f165064:	00c05825 */ 	or	$t3,$a2,$zero
.L0f165068:
/*  f165068:	c5200004 */ 	lwc1	$f0,0x4($t1)
/*  f16506c:	c5440000 */ 	lwc1	$f4,0x0($t2)
/*  f165070:	25080004 */ 	addiu	$t0,$t0,0x4
/*  f165074:	25290004 */ 	addiu	$t1,$t1,0x4
/*  f165078:	4604003c */ 	c.lt.s	$f0,$f4
/*  f16507c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165080:	45020003 */ 	bc1fl	.L0f165090
/*  f165084:	c5660000 */ 	lwc1	$f6,0x0($t3)
/*  f165088:	e5400000 */ 	swc1	$f0,0x0($t2)
/*  f16508c:	c5660000 */ 	lwc1	$f6,0x0($t3)
.L0f165090:
/*  f165090:	254a0004 */ 	addiu	$t2,$t2,0x4
/*  f165094:	4600303c */ 	c.lt.s	$f6,$f0
/*  f165098:	00000000 */ 	sll	$zero,$zero,0x0
/*  f16509c:	45000002 */ 	bc1f	.L0f1650a8
/*  f1650a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1650a4:	e5600000 */ 	swc1	$f0,0x0($t3)
.L0f1650a8:
/*  f1650a8:	150cffef */ 	bne	$t0,$t4,.L0f165068
/*  f1650ac:	256b0004 */ 	addiu	$t3,$t3,0x4
/*  f1650b0:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f1650b4:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f1650b8:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f1650bc:	00e3082a */ 	slt	$at,$a3,$v1
/*  f1650c0:	5420ffe6 */ 	bnezl	$at,.L0f16505c
/*  f1650c4:	00004025 */ 	or	$t0,$zero,$zero
.L0f1650c8:
/*  f1650c8:	03e00008 */ 	jr	$ra
/*  f1650cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1650d0
/*  f1650d0:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f1650d4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1650d8:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f1650dc:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f1650e0:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f1650e4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f1650e8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1650ec:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f1650f0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1650f4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1650f8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1650fc:	afa600b8 */ 	sw	$a2,0xb8($sp)
/*  f165100:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f165104:	2401ffff */ 	addiu	$at,$zero,-1
/*  f165108:	3c14800a */ 	lui	$s4,%hi(g_PortalSomethings)
/*  f16510c:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*  f165110:	c4860004 */ 	lwc1	$f6,0x4($a0)
/*  f165114:	00e0b825 */ 	or	$s7,$a3,$zero
/*  f165118:	00004025 */ 	or	$t0,$zero,$zero
/*  f16511c:	e7a600a0 */ 	swc1	$f6,0xa0($sp)
/*  f165120:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f165124:	00008025 */ 	or	$s0,$zero,$zero
/*  f165128:	00c09825 */ 	or	$s3,$a2,$zero
/*  f16512c:	e7a800a4 */ 	swc1	$f8,0xa4($sp)
/*  f165130:	c4aa0000 */ 	lwc1	$f10,0x0($a1)
/*  f165134:	26944cc8 */ 	addiu	$s4,$s4,%lo(g_PortalSomethings)
/*  f165138:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*  f16513c:	e7aa0090 */ 	swc1	$f10,0x90($sp)
/*  f165140:	c4b00004 */ 	lwc1	$f16,0x4($a1)
/*  f165144:	27b50070 */ 	addiu	$s5,$sp,0x70
/*  f165148:	27b60064 */ 	addiu	$s6,$sp,0x64
/*  f16514c:	e7b00094 */ 	swc1	$f16,0x94($sp)
/*  f165150:	c4b20008 */ 	lwc1	$f18,0x8($a1)
/*  f165154:	e7b20098 */ 	swc1	$f18,0x98($sp)
/*  f165158:	84cf0000 */ 	lh	$t7,0x0($a2)
/*  f16515c:	51e10007 */ 	beql	$t7,$at,.L0f16517c
/*  f165160:	00104840 */ 	sll	$t1,$s0,0x1
.L0f165164:
/*  f165164:	86780002 */ 	lh	$t8,0x2($s3)
/*  f165168:	2401ffff */ 	addiu	$at,$zero,-1
/*  f16516c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f165170:	1701fffc */ 	bne	$t8,$at,.L0f165164
/*  f165174:	26730002 */ 	addiu	$s3,$s3,0x2
/*  f165178:	00104840 */ 	sll	$t1,$s0,0x1
.L0f16517c:
/*  f16517c:	03299821 */ 	addu	$s3,$t9,$t1
/*  f165180:	afb0007c */ 	sw	$s0,0x7c($sp)
.L0f165184:
/*  f165184:	0110082a */ 	slt	$at,$t0,$s0
/*  f165188:	10200061 */ 	beqz	$at,.L0f165310
/*  f16518c:	8faa00b8 */ 	lw	$t2,0xb8($sp)
/*  f165190:	00085840 */ 	sll	$t3,$t0,0x1
/*  f165194:	3c05800a */ 	lui	$a1,%hi(g_RoomPtrs)
/*  f165198:	8ca54928 */ 	lw	$a1,%lo(g_RoomPtrs)($a1)
/*  f16519c:	014b3821 */ 	addu	$a3,$t2,$t3
/*  f1651a0:	84fe0000 */ 	lh	$s8,0x0($a3)
.L0f1651a4:
/*  f1651a4:	00009025 */ 	or	$s2,$zero,$zero
/*  f1651a8:	001e30c0 */ 	sll	$a2,$s8,0x3
/*  f1651ac:	00de3021 */ 	addu	$a2,$a2,$s8
/*  f1651b0:	00063080 */ 	sll	$a2,$a2,0x2
/*  f1651b4:	00de3023 */ 	subu	$a2,$a2,$s8
/*  f1651b8:	00063080 */ 	sll	$a2,$a2,0x2
/*  f1651bc:	00a61821 */ 	addu	$v1,$a1,$a2
/*  f1651c0:	80640005 */ 	lb	$a0,0x5($v1)
/*  f1651c4:	5880004d */ 	blezl	$a0,.L0f1652fc
/*  f1651c8:	8faa007c */ 	lw	$t2,0x7c($sp)
/*  f1651cc:	afa80088 */ 	sw	$t0,0x88($sp)
/*  f1651d0:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f1651d4:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f1651d8:	846d000e */ 	lh	$t5,0xe($v1)
.L0f1651dc:
/*  f1651dc:	3c0c800a */ 	lui	$t4,%hi(var800a4ce0)
/*  f1651e0:	8d8c4ce0 */ 	lw	$t4,%lo(var800a4ce0)($t4)
/*  f1651e4:	8fb900c0 */ 	lw	$t9,0xc0($sp)
/*  f1651e8:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f1651ec:	018f7021 */ 	addu	$t6,$t4,$t7
/*  f1651f0:	01d2c021 */ 	addu	$t8,$t6,$s2
/*  f1651f4:	1320000c */ 	beqz	$t9,.L0f165228
/*  f1651f8:	87110000 */ 	lh	$s1,0x0($t8)
/*  f1651fc:	8e890000 */ 	lw	$t1,0x0($s4)
/*  f165200:	001150c0 */ 	sll	$t2,$s1,0x3
/*  f165204:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f165208:	91620006 */ 	lbu	$v0,0x6($t3)
/*  f16520c:	304d0001 */ 	andi	$t5,$v0,0x1
/*  f165210:	11a00005 */ 	beqz	$t5,.L0f165228
/*  f165214:	304c0004 */ 	andi	$t4,$v0,0x4
/*  f165218:	55800004 */ 	bnezl	$t4,.L0f16522c
/*  f16521c:	02202025 */ 	or	$a0,$s1,$zero
/*  f165220:	1000002f */ 	beqz	$zero,.L0f1652e0
/*  f165224:	00041040 */ 	sll	$v0,$a0,0x1
.L0f165228:
/*  f165228:	02202025 */ 	or	$a0,$s1,$zero
.L0f16522c:
/*  f16522c:	02a02825 */ 	or	$a1,$s5,$zero
/*  f165230:	0fc59401 */ 	jal	func0f165004
/*  f165234:	02c03025 */ 	or	$a2,$s6,$zero
/*  f165238:	02a02025 */ 	or	$a0,$s5,$zero
/*  f16523c:	02c02825 */ 	or	$a1,$s6,$zero
/*  f165240:	27a6009c */ 	addiu	$a2,$sp,0x9c
/*  f165244:	0fc593e7 */ 	jal	func0f164f9c
/*  f165248:	27a70090 */ 	addiu	$a3,$sp,0x90
/*  f16524c:	1040001e */ 	beqz	$v0,.L0f1652c8
/*  f165250:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165254:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f165258:	001170c0 */ 	sll	$t6,$s1,0x3
/*  f16525c:	00001825 */ 	or	$v1,$zero,$zero
/*  f165260:	01ee1021 */ 	addu	$v0,$t7,$t6
/*  f165264:	84450002 */ 	lh	$a1,0x2($v0)
/*  f165268:	0217082a */ 	slt	$at,$s0,$s7
/*  f16526c:	17c50003 */ 	bne	$s8,$a1,.L0f16527c
/*  f165270:	00052400 */ 	sll	$a0,$a1,0x10
/*  f165274:	10000003 */ 	beqz	$zero,.L0f165284
/*  f165278:	84440004 */ 	lh	$a0,0x4($v0)
.L0f16527c:
/*  f16527c:	0004c403 */ 	sra	$t8,$a0,0x10
/*  f165280:	03002025 */ 	or	$a0,$t8,$zero
.L0f165284:
/*  f165284:	1a000007 */ 	blez	$s0,.L0f1652a4
/*  f165288:	8fa200b8 */ 	lw	$v0,0xb8($sp)
.L0f16528c:
/*  f16528c:	84590000 */ 	lh	$t9,0x0($v0)
/*  f165290:	10990004 */ 	beq	$a0,$t9,.L0f1652a4
/*  f165294:	00000000 */ 	sll	$zero,$zero,0x0
/*  f165298:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f16529c:	1470fffb */ 	bne	$v1,$s0,.L0f16528c
/*  f1652a0:	24420002 */ 	addiu	$v0,$v0,0x2
.L0f1652a4:
/*  f1652a4:	14700008 */ 	bne	$v1,$s0,.L0f1652c8
/*  f1652a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1652ac:	50200005 */ 	beqzl	$at,.L0f1652c4
/*  f1652b0:	0217082a */ 	slt	$at,$s0,$s7
/*  f1652b4:	a6640000 */ 	sh	$a0,0x0($s3)
/*  f1652b8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1652bc:	26730002 */ 	addiu	$s3,$s3,0x2
/*  f1652c0:	0217082a */ 	slt	$at,$s0,$s7
.L0f1652c4:
/*  f1652c4:	10200017 */ 	beqz	$at,.L0f165324
.L0f1652c8:
/*  f1652c8:	3c05800a */ 	lui	$a1,%hi(g_RoomPtrs)
/*  f1652cc:	8ca54928 */ 	lw	$a1,%lo(g_RoomPtrs)($a1)
/*  f1652d0:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f1652d4:	00a91821 */ 	addu	$v1,$a1,$t1
/*  f1652d8:	80640005 */ 	lb	$a0,0x5($v1)
/*  f1652dc:	00041040 */ 	sll	$v0,$a0,0x1
.L0f1652e0:
/*  f1652e0:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f1652e4:	0242082a */ 	slt	$at,$s2,$v0
/*  f1652e8:	5420ffbc */ 	bnezl	$at,.L0f1651dc
/*  f1652ec:	846d000e */ 	lh	$t5,0xe($v1)
/*  f1652f0:	8fa80088 */ 	lw	$t0,0x88($sp)
/*  f1652f4:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f1652f8:	8faa007c */ 	lw	$t2,0x7c($sp)
.L0f1652fc:
/*  f1652fc:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f165300:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f165304:	010a082a */ 	slt	$at,$t0,$t2
/*  f165308:	5420ffa6 */ 	bnezl	$at,.L0f1651a4
/*  f16530c:	84fe0000 */ 	lh	$s8,0x0($a3)
.L0f165310:
/*  f165310:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f165314:	520b0004 */ 	beql	$s0,$t3,.L0f165328
/*  f165318:	240dffff */ 	addiu	$t5,$zero,-1
/*  f16531c:	1000ff99 */ 	beqz	$zero,.L0f165184
/*  f165320:	afb0007c */ 	sw	$s0,0x7c($sp)
.L0f165324:
/*  f165324:	240dffff */ 	addiu	$t5,$zero,-1
.L0f165328:
/*  f165328:	a66d0000 */ 	sh	$t5,0x0($s3)
/*  f16532c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f165330:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f165334:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f165338:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f16533c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f165340:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f165344:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f165348:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f16534c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f165350:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f165354:	03e00008 */ 	jr	$ra
/*  f165358:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
/*  f16535c:	00000000 */ 	sll	$zero,$zero,0x0
);
