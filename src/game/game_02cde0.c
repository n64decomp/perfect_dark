#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/chr/chraction.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_01e250.h"
#include "game/game_02cde0.h"
#include "game/game_0601b0.h"
#include "game/game_066310.h"
#include "game/game_096750.h"
#include "game/game_0b28d0.h"
#include "game/game_167ae0.h"
#include "game/game_187770.h"
#include "game/game_1a3340.h"
#include "game/pad.h"
#include "gvars/gvars.h"
#include "lib/lib_121e0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_16110.h"
#include "lib/lib_1a500.h"
#include "lib/lib_233c0.h"
#include "types.h"

const u32 var7f1a8990[] = {0x7f02ce04};
const u32 var7f1a8994[] = {0x7f02ce24};
const u32 var7f1a8998[] = {0x7f02ce24};
const u32 var7f1a899c[] = {0x7f02ce24};
const u32 var7f1a89a0[] = {0x7f02ce24};
const u32 var7f1a89a4[] = {0x7f02ce24};
const u32 var7f1a89a8[] = {0x7f02ce24};
const u32 var7f1a89ac[] = {0x7f02ce24};
const u32 var7f1a89b0[] = {0x7f02ce24};
const u32 var7f1a89b4[] = {0x7f02ce24};
const u32 var7f1a89b8[] = {0x7f02ce24};
const u32 var7f1a89bc[] = {0x7f02ce24};
const u32 var7f1a89c0[] = {0x7f02ce24};
const u32 var7f1a89c4[] = {0x7f02ce24};
const u32 var7f1a89c8[] = {0x7f02ce24};
const u32 var7f1a89cc[] = {0x7f02ce0c};
const u32 var7f1a89d0[] = {0x7f02ce14};
const u32 var7f1a89d4[] = {0x7f02ce24};
const u32 var7f1a89d8[] = {0x7f02ce24};
const u32 var7f1a89dc[] = {0x7f02ce24};
const u32 var7f1a89e0[] = {0x7f02ce24};
const u32 var7f1a89e4[] = {0x7f02ce24};
const u32 var7f1a89e8[] = {0x7f02ce24};
const u32 var7f1a89ec[] = {0x7f02ce24};
const u32 var7f1a89f0[] = {0x7f02ce24};
const u32 var7f1a89f4[] = {0x7f02ce24};
const u32 var7f1a89f8[] = {0x7f02ce1c};
const u32 var7f1a89fc[] = {0x7f02ce24};
const u32 var7f1a8a00[] = {0x7f02ce24};
const u32 var7f1a8a04[] = {0x7f02ce24};
const u32 var7f1a8a08[] = {0x7f02ce24};
const u32 var7f1a8a0c[] = {0x7f02ce04};
const u32 var7f1a8a10[] = {0x7f02ce24};
const u32 var7f1a8a14[] = {0x7f02ce24};
const u32 var7f1a8a18[] = {0x7f02ce24};
const u32 var7f1a8a1c[] = {0x7f02ce24};
const u32 var7f1a8a20[] = {0x7f02ce24};
const u32 var7f1a8a24[] = {0x7f02ce24};
const u32 var7f1a8a28[] = {0x7f02ce24};
const u32 var7f1a8a2c[] = {0x7f02ce24};
const u32 var7f1a8a30[] = {0x7f02ce24};
const u32 var7f1a8a34[] = {0x7f02ce24};
const u32 var7f1a8a38[] = {0x7f02ce24};
const u32 var7f1a8a3c[] = {0x7f02ce24};
const u32 var7f1a8a40[] = {0x7f02ce24};
const u32 var7f1a8a44[] = {0x7f02ce24};
const u32 var7f1a8a48[] = {0x7f02ce24};
const u32 var7f1a8a4c[] = {0x7f02ce24};
const u32 var7f1a8a50[] = {0x7f02ce24};
const u32 var7f1a8a54[] = {0x7f02ce24};
const u32 var7f1a8a58[] = {0x7f02ce24};
const u32 var7f1a8a5c[] = {0x7f02ce24};
const u32 var7f1a8a60[] = {0x7f02ce24};
const u32 var7f1a8a64[] = {0x7f02ce24};
const u32 var7f1a8a68[] = {0x7f02ce24};
const u32 var7f1a8a6c[] = {0x7f02ce04};
const u32 var7f1a8a70[] = {0x3dccccce};
const u32 var7f1a8a74[] = {0x3f4ccccd};
const u32 var7f1a8a78[] = {0x3d4ccccd};
const u32 var7f1a8a7c[] = {0x3ecccccd};
const u32 var7f1a8a80[] = {0x3ecccccd};
const u32 var7f1a8a84[] = {0x3dcccccd};
const u32 var7f1a8a88[] = {0x7f02de50};
const u32 var7f1a8a8c[] = {0x7f02de40};
const u32 var7f1a8a90[] = {0x7f02de68};
const u32 var7f1a8a94[] = {0x7f02de48};
const u32 var7f1a8a98[] = {0x7f02de60};
const u32 var7f1a8a9c[] = {0x7f02de58};
const u32 var7f1a8aa0[] = {0x7f02de94};
const u32 var7f1a8aa4[] = {0x7f02dea8};
const u32 var7f1a8aa8[] = {0x7f02dea4};
const u32 var7f1a8aac[] = {0x7f02de8c};
const u32 var7f1a8ab0[] = {0x7f02de9c};
const u32 var7f1a8ab4[] = {0x7f02dea8};
const u32 var7f1a8ab8[] = {0x00000000};
const u32 var7f1a8abc[] = {0x00000000};

GLOBAL_ASM(
glabel func0f02cde0
/*  f02cde0:	248effa4 */ 	addiu	$t6,$a0,-92
/*  f02cde4:	2dc10038 */ 	sltiu	$at,$t6,0x38
/*  f02cde8:	1020000e */ 	beqz	$at,.L0f02ce24
/*  f02cdec:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f02cdf0:	3c017f1b */ 	lui	$at,%hi(var7f1a8990)
/*  f02cdf4:	002e0821 */ 	addu	$at,$at,$t6
/*  f02cdf8:	8c2e8990 */ 	lw	$t6,%lo(var7f1a8990)($at)
/*  f02cdfc:	01c00008 */ 	jr	$t6
/*  f02ce00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02ce04:	03e00008 */ 	jr	$ra
/*  f02ce08:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f02ce0c:	03e00008 */ 	jr	$ra
/*  f02ce10:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f02ce14:	03e00008 */ 	jr	$ra
/*  f02ce18:	24020003 */ 	addiu	$v0,$zero,0x3
/*  f02ce1c:	03e00008 */ 	jr	$ra
/*  f02ce20:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f02ce24:
/*  f02ce24:	00001025 */ 	or	$v0,$zero,$zero
/*  f02ce28:	03e00008 */ 	jr	$ra
/*  f02ce2c:	00000000 */ 	sll	$zero,$zero,0x0
);

bool bodyLoad(u32 bodynum)
{
	if (!g_Bodies[bodynum].unk0c) {
		g_Bodies[bodynum].unk0c = fileLoad(g_Bodies[bodynum].bodyfileid);
		return true;
	}

	return false;
}

GLOBAL_ASM(
glabel func0f02ce8c
/*  f02ce8c:	00047880 */ 	sll	$t7,$a0,0x2
/*  f02ce90:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f02ce94:	3c188008 */ 	lui	$t8,%hi(g_Bodies)
/*  f02ce98:	2718cf04 */ 	addiu	$t8,$t8,%lo(g_Bodies)
/*  f02ce9c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f02cea0:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f02cea4:	3c017f1b */ 	lui	$at,%hi(var7f1a8a70)
/*  f02cea8:	c4268a70 */ 	lwc1	$f6,%lo(var7f1a8a70)($at)
/*  f02ceac:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f02ceb0:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f02ceb4:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f02ceb8:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f02cebc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f02cec0:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f02cec4:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f02cec8:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f02cecc:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f02ced0:	afa0003c */ 	sw	$zero,0x3c($sp)
/*  f02ced4:	e7a80044 */ 	swc1	$f8,0x44($sp)
/*  f02ced8:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f02cedc:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f02cee0:	0fc41b99 */ 	jal	cheatIsActive
/*  f02cee4:	e7aa0040 */ 	swc1	$f10,0x40($sp)
/*  f02cee8:	10400005 */ 	beqz	$v0,.L0f02cf00
/*  f02ceec:	c7b00044 */ 	lwc1	$f16,0x44($sp)
/*  f02cef0:	3c017f1b */ 	lui	$at,%hi(var7f1a8a74)
/*  f02cef4:	c4328a74 */ 	lwc1	$f18,%lo(var7f1a8a74)($at)
/*  f02cef8:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f02cefc:	e7a40044 */ 	swc1	$f4,0x44($sp)
.L0f02cf00:
/*  f02cf00:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f02cf04:	8fa8001c */ 	lw	$t0,0x1c($sp)
/*  f02cf08:	1720000a */ 	bnez	$t9,.L0f02cf34
/*  f02cf0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02cf10:	8d03000c */ 	lw	$v1,0xc($t0)
/*  f02cf14:	54600007 */ 	bnezl	$v1,.L0f02cf34
/*  f02cf18:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f02cf1c:	0fc69e11 */ 	jal	fileLoad
/*  f02cf20:	95040002 */ 	lhu	$a0,0x2($t0)
/*  f02cf24:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f02cf28:	00401825 */ 	or	$v1,$v0,$zero
/*  f02cf2c:	ac82000c */ 	sw	$v0,0xc($a0)
/*  f02cf30:	afa30050 */ 	sw	$v1,0x50($sp)
.L0f02cf34:
/*  f02cf34:	0c008b49 */ 	jal	func00022d24
/*  f02cf38:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f02cf3c:	8fa9001c */ 	lw	$t1,0x1c($sp)
/*  f02cf40:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f02cf44:	8d220000 */ 	lw	$v0,0x0($t1)
/*  f02cf48:	00025840 */ 	sll	$t3,$v0,0x1
/*  f02cf4c:	056200b9 */ 	bltzl	$t3,.L0f02d234
/*  f02cf50:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f02cf54:	8d830004 */ 	lw	$v1,0x4($t4)
/*  f02cf58:	3c0d8008 */ 	lui	$t5,%hi(stagethinglist_22e60)
/*  f02cf5c:	25adce40 */ 	addiu	$t5,$t5,%lo(stagethinglist_22e60)
/*  f02cf60:	15a30090 */ 	bne	$t5,$v1,.L0f02d1a4
/*  f02cf64:	01802025 */ 	or	$a0,$t4,$zero
/*  f02cf68:	0c006a47 */ 	jal	func0001a91c
/*  f02cf6c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f02cf70:	104000af */ 	beqz	$v0,.L0f02d230
/*  f02cf74:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f02cf78:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f02cf7c:	240effff */ 	addiu	$t6,$zero,-1
/*  f02cf80:	04e1000a */ 	bgez	$a3,.L0f02cfac
/*  f02cf84:	01c72023 */ 	subu	$a0,$t6,$a3
/*  f02cf88:	0fc6395f */ 	jal	func0f18e57c
/*  f02cf8c:	27a5004c */ 	addiu	$a1,$sp,0x4c
/*  f02cf90:	8faf0050 */ 	lw	$t7,0x50($sp)
/*  f02cf94:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f02cf98:	84590014 */ 	lh	$t9,0x14($v0)
/*  f02cf9c:	85f80014 */ 	lh	$t8,0x14($t7)
/*  f02cfa0:	03194021 */ 	addu	$t0,$t8,$t9
/*  f02cfa4:	10000061 */ 	beqz	$zero,.L0f02d12c
/*  f02cfa8:	a5e80014 */ 	sh	$t0,0x14($t7)
.L0f02cfac:
/*  f02cfac:	18e0005f */ 	blez	$a3,.L0f02d12c
/*  f02cfb0:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f02cfb4:	15200036 */ 	bnez	$t1,.L0f02d090
/*  f02cfb8:	3c0a800a */ 	lui	$t2,0x800a
/*  f02cfbc:	8d4aa2d8 */ 	lw	$t2,-0x5d28($t2)
/*  f02cfc0:	00074080 */ 	sll	$t0,$a3,0x2
/*  f02cfc4:	3c0b8009 */ 	lui	$t3,%hi(g_Is4Mb)
/*  f02cfc8:	1140001e */ 	beqz	$t2,.L0f02d044
/*  f02cfcc:	01074021 */ 	addu	$t0,$t0,$a3
/*  f02cfd0:	916b0af0 */ 	lbu	$t3,%lo(g_Is4Mb)($t3)
/*  f02cfd4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f02cfd8:	00076880 */ 	sll	$t5,$a3,0x2
/*  f02cfdc:	11610019 */ 	beq	$t3,$at,.L0f02d044
/*  f02cfe0:	01a76821 */ 	addu	$t5,$t5,$a3
/*  f02cfe4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f02cfe8:	3c048008 */ 	lui	$a0,0x8008
/*  f02cfec:	008d2021 */ 	addu	$a0,$a0,$t5
/*  f02cff0:	0fc69e11 */ 	jal	fileLoad
/*  f02cff4:	9484cf06 */ 	lhu	$a0,-0x30fa($a0)
/*  f02cff8:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f02cffc:	3c0e8008 */ 	lui	$t6,%hi(g_Bodies)
/*  f02d000:	25cecf04 */ 	addiu	$t6,$t6,%lo(g_Bodies)
/*  f02d004:	00056080 */ 	sll	$t4,$a1,0x2
/*  f02d008:	01856021 */ 	addu	$t4,$t4,$a1
/*  f02d00c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f02d010:	018e1821 */ 	addu	$v1,$t4,$t6
/*  f02d014:	94780002 */ 	lhu	$t8,0x2($v1)
/*  f02d018:	3c01800a */ 	lui	$at,0x800a
/*  f02d01c:	ac62000c */ 	sw	$v0,0xc($v1)
/*  f02d020:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f02d024:	00390821 */ 	addu	$at,$at,$t9
/*  f02d028:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f02d02c:	ac206680 */ 	sw	$zero,0x6680($at)
/*  f02d030:	00402025 */ 	or	$a0,$v0,$zero
/*  f02d034:	0fc0b76f */ 	jal	func0f02ddbc
/*  f02d038:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f02d03c:	10000014 */ 	beqz	$zero,.L0f02d090
/*  f02d040:	00000000 */ 	sll	$zero,$zero,0x0
.L0f02d044:
/*  f02d044:	3c0f8008 */ 	lui	$t7,%hi(g_Bodies)
/*  f02d048:	25efcf04 */ 	addiu	$t7,$t7,%lo(g_Bodies)
/*  f02d04c:	00084080 */ 	sll	$t0,$t0,0x2
/*  f02d050:	010f1821 */ 	addu	$v1,$t0,$t7
/*  f02d054:	8c64000c */ 	lw	$a0,0xc($v1)
/*  f02d058:	5480000d */ 	bnezl	$a0,.L0f02d090
/*  f02d05c:	afa40054 */ 	sw	$a0,0x54($sp)
/*  f02d060:	0fc69e11 */ 	jal	fileLoad
/*  f02d064:	94640002 */ 	lhu	$a0,0x2($v1)
/*  f02d068:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f02d06c:	3c0a8008 */ 	lui	$t2,%hi(g_Bodies)
/*  f02d070:	254acf04 */ 	addiu	$t2,$t2,%lo(g_Bodies)
/*  f02d074:	00074880 */ 	sll	$t1,$a3,0x2
/*  f02d078:	01274821 */ 	addu	$t1,$t1,$a3
/*  f02d07c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f02d080:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f02d084:	ac62000c */ 	sw	$v0,0xc($v1)
/*  f02d088:	00402025 */ 	or	$a0,$v0,$zero
/*  f02d08c:	afa40054 */ 	sw	$a0,0x54($sp)
.L0f02d090:
/*  f02d090:	0c008b49 */ 	jal	func00022d24
/*  f02d094:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f02d098:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f02d09c:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f02d0a0:	856d0014 */ 	lh	$t5,0x14($t3)
/*  f02d0a4:	858e0014 */ 	lh	$t6,0x14($t4)
/*  f02d0a8:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f02d0ac:	a5780014 */ 	sh	$t8,0x14($t3)
/*  f02d0b0:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*  f02d0b4:	93aa0067 */ 	lbu	$t2,0x67($sp)
/*  f02d0b8:	8f280000 */ 	lw	$t0,0x0($t9)
/*  f02d0bc:	00084880 */ 	sll	$t1,$t0,0x2
/*  f02d0c0:	0523001b */ 	bgezl	$t1,.L0f02d130
/*  f02d0c4:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f02d0c8:	51400019 */ 	beqzl	$t2,.L0f02d130
/*  f02d0cc:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f02d0d0:	0c004b70 */ 	jal	random
/*  f02d0d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02d0d8:	44823000 */ 	mtc1	$v0,$f6
/*  f02d0dc:	3c017f1b */ 	lui	$at,%hi(var7f1a8a78)
/*  f02d0e0:	c4228a78 */ 	lwc1	$f2,%lo(var7f1a8a78)($at)
/*  f02d0e4:	04410005 */ 	bgez	$v0,.L0f02d0fc
/*  f02d0e8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f02d0ec:	3c014f80 */ 	lui	$at,0x4f80
/*  f02d0f0:	44815000 */ 	mtc1	$at,$f10
/*  f02d0f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02d0f8:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f02d0fc:
/*  f02d0fc:	3c012f80 */ 	lui	$at,0x2f80
/*  f02d100:	44818000 */ 	mtc1	$at,$f16
/*  f02d104:	3c013f80 */ 	lui	$at,0x3f80
/*  f02d108:	44815000 */ 	mtc1	$at,$f10
/*  f02d10c:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f02d110:	c7b00044 */ 	lwc1	$f16,0x44($sp)
/*  f02d114:	46029002 */ 	mul.s	$f0,$f18,$f2
/*  f02d118:	46000100 */ 	add.s	$f4,$f0,$f0
/*  f02d11c:	46022181 */ 	sub.s	$f6,$f4,$f2
/*  f02d120:	460a3200 */ 	add.s	$f8,$f6,$f10
/*  f02d124:	46088482 */ 	mul.s	$f18,$f16,$f8
/*  f02d128:	e7b20044 */ 	swc1	$f18,0x44($sp)
.L0f02d12c:
/*  f02d12c:	8fac0060 */ 	lw	$t4,0x60($sp)
.L0f02d130:
/*  f02d130:	15800013 */ 	bnez	$t4,.L0f02d180
/*  f02d134:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02d138:	0fc41b99 */ 	jal	cheatIsActive
/*  f02d13c:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f02d140:	10400005 */ 	beqz	$v0,.L0f02d158
/*  f02d144:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f02d148:	3c017f1b */ 	lui	$at,%hi(var7f1a8a7c)
/*  f02d14c:	c4268a7c */ 	lwc1	$f6,%lo(var7f1a8a7c)($at)
/*  f02d150:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f02d154:	e7aa0044 */ 	swc1	$f10,0x44($sp)
.L0f02d158:
/*  f02d158:	0fc41b99 */ 	jal	cheatIsActive
/*  f02d15c:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f02d160:	10400033 */ 	beqz	$v0,.L0f02d230
/*  f02d164:	c7b00044 */ 	lwc1	$f16,0x44($sp)
/*  f02d168:	3c013fa0 */ 	lui	$at,0x3fa0
/*  f02d16c:	44814000 */ 	mtc1	$at,$f8
/*  f02d170:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02d174:	46088482 */ 	mul.s	$f18,$f16,$f8
/*  f02d178:	1000002d */ 	beqz	$zero,.L0f02d230
/*  f02d17c:	e7b20044 */ 	swc1	$f18,0x44($sp)
.L0f02d180:
/*  f02d180:	0fc41b99 */ 	jal	cheatIsActive
/*  f02d184:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f02d188:	10400029 */ 	beqz	$v0,.L0f02d230
/*  f02d18c:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f02d190:	3c017f1b */ 	lui	$at,%hi(var7f1a8a80)
/*  f02d194:	c4268a80 */ 	lwc1	$f6,%lo(var7f1a8a80)($at)
/*  f02d198:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f02d19c:	10000024 */ 	beqz	$zero,.L0f02d230
/*  f02d1a0:	e7aa0044 */ 	swc1	$f10,0x44($sp)
.L0f02d1a4:
/*  f02d1a4:	3c0d8008 */ 	lui	$t5,%hi(stagethinglist_22eb8)
/*  f02d1a8:	25adce98 */ 	addiu	$t5,$t5,%lo(stagethinglist_22eb8)
/*  f02d1ac:	15a30020 */ 	bne	$t5,$v1,.L0f02d230
/*  f02d1b0:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f02d1b4:	0701001e */ 	bgez	$t8,.L0f02d230
/*  f02d1b8:	93ab0067 */ 	lbu	$t3,0x67($sp)
/*  f02d1bc:	1160001c */ 	beqz	$t3,.L0f02d230
/*  f02d1c0:	8fb9001c */ 	lw	$t9,0x1c($sp)
/*  f02d1c4:	3c088008 */ 	lui	$t0,0x8008
/*  f02d1c8:	2508d634 */ 	addiu	$t0,$t0,-10700
/*  f02d1cc:	57280019 */ 	bnel	$t9,$t0,.L0f02d234
/*  f02d1d0:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f02d1d4:	0c004b70 */ 	jal	random
/*  f02d1d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02d1dc:	44828000 */ 	mtc1	$v0,$f16
/*  f02d1e0:	3c017f1b */ 	lui	$at,%hi(var7f1a8a84)
/*  f02d1e4:	c4228a84 */ 	lwc1	$f2,%lo(var7f1a8a84)($at)
/*  f02d1e8:	04410005 */ 	bgez	$v0,.L0f02d200
/*  f02d1ec:	46808220 */ 	cvt.s.w	$f8,$f16
/*  f02d1f0:	3c014f80 */ 	lui	$at,0x4f80
/*  f02d1f4:	44819000 */ 	mtc1	$at,$f18
/*  f02d1f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02d1fc:	46124200 */ 	add.s	$f8,$f8,$f18
.L0f02d200:
/*  f02d200:	3c012f80 */ 	lui	$at,0x2f80
/*  f02d204:	44812000 */ 	mtc1	$at,$f4
/*  f02d208:	3c013f40 */ 	lui	$at,0x3f40
/*  f02d20c:	44819000 */ 	mtc1	$at,$f18
/*  f02d210:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f02d214:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f02d218:	46061002 */ 	mul.s	$f0,$f2,$f6
/*  f02d21c:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f02d220:	46025401 */ 	sub.s	$f16,$f10,$f2
/*  f02d224:	46128200 */ 	add.s	$f8,$f16,$f18
/*  f02d228:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f02d22c:	e7a60044 */ 	swc1	$f6,0x44($sp)
.L0f02d230:
/*  f02d230:	8fa2005c */ 	lw	$v0,0x5c($sp)
.L0f02d234:
/*  f02d234:	8fa90050 */ 	lw	$t1,0x50($sp)
/*  f02d238:	10400008 */ 	beqz	$v0,.L0f02d25c
/*  f02d23c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02d240:	844f0002 */ 	lh	$t7,0x2($v0)
/*  f02d244:	852a0014 */ 	lh	$t2,0x14($t1)
/*  f02d248:	01ea082a */ 	slt	$at,$t7,$t2
/*  f02d24c:	50200007 */ 	beqzl	$at,.L0f02d26c
/*  f02d250:	8fac005c */ 	lw	$t4,0x5c($sp)
/*  f02d254:	10000005 */ 	beqz	$zero,.L0f02d26c
/*  f02d258:	8fac005c */ 	lw	$t4,0x5c($sp)
.L0f02d25c:
/*  f02d25c:	0fc2cca0 */ 	jal	func0f0b3280
/*  f02d260:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f02d264:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f02d268:	8fac005c */ 	lw	$t4,0x5c($sp)
.L0f02d26c:
/*  f02d26c:	1180002d */ 	beqz	$t4,.L0f02d324
/*  f02d270:	01802025 */ 	or	$a0,$t4,$zero
/*  f02d274:	0c006bd6 */ 	jal	func0001af58
/*  f02d278:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f02d27c:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f02d280:	0c006bd9 */ 	jal	func0001af64
/*  f02d284:	8fa50040 */ 	lw	$a1,0x40($sp)
/*  f02d288:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f02d28c:	8fad001c */ 	lw	$t5,0x1c($sp)
/*  f02d290:	50c00025 */ 	beqzl	$a2,.L0f02d328
/*  f02d294:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f02d298:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f02d29c:	8fb90050 */ 	lw	$t9,0x50($sp)
/*  f02d2a0:	000e5840 */ 	sll	$t3,$t6,0x1
/*  f02d2a4:	05620020 */ 	bltzl	$t3,.L0f02d328
/*  f02d2a8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f02d2ac:	87280014 */ 	lh	$t0,0x14($t9)
/*  f02d2b0:	84c90014 */ 	lh	$t1,0x14($a2)
/*  f02d2b4:	01097823 */ 	subu	$t7,$t0,$t1
/*  f02d2b8:	a72f0014 */ 	sh	$t7,0x14($t9)
/*  f02d2bc:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f02d2c0:	0fc2cca8 */ 	jal	func0f0b32a0
/*  f02d2c4:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f02d2c8:	8faa0054 */ 	lw	$t2,0x54($sp)
/*  f02d2cc:	2401000d */ 	addiu	$at,$zero,0xd
/*  f02d2d0:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f02d2d4:	854c0006 */ 	lh	$t4,0x6($t2)
/*  f02d2d8:	55810013 */ 	bnel	$t4,$at,.L0f02d328
/*  f02d2dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f02d2e0:	15a00008 */ 	bnez	$t5,.L0f02d304
/*  f02d2e4:	01402025 */ 	or	$a0,$t2,$zero
/*  f02d2e8:	0c006a47 */ 	jal	func0001a91c
/*  f02d2ec:	00002825 */ 	or	$a1,$zero,$zero
/*  f02d2f0:	10400004 */ 	beqz	$v0,.L0f02d304
/*  f02d2f4:	00402825 */ 	or	$a1,$v0,$zero
/*  f02d2f8:	0c006a87 */ 	jal	func0001aa1c
/*  f02d2fc:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f02d300:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f02d304:
/*  f02d304:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f02d308:	0c006a47 */ 	jal	func0001a91c
/*  f02d30c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f02d310:	10400004 */ 	beqz	$v0,.L0f02d324
/*  f02d314:	00402825 */ 	or	$a1,$v0,$zero
/*  f02d318:	0c006a87 */ 	jal	func0001aa1c
/*  f02d31c:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f02d320:	ac400000 */ 	sw	$zero,0x0($v0)
.L0f02d324:
/*  f02d324:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f02d328:
/*  f02d328:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f02d32c:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f02d330:	03e00008 */ 	jr	$ra
/*  f02d334:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f02d338
/*  f02d338:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f02d33c:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f02d340:	93af003f */ 	lbu	$t7,0x3f($sp)
/*  f02d344:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f02d348:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f02d34c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f02d350:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f02d354:	0fc0b3a3 */ 	jal	func0f02ce8c
/*  f02d358:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f02d35c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f02d360:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f02d364:	03e00008 */ 	jr	$ra
/*  f02d368:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f02d36c
/*  f02d36c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f02d370:	30ce0001 */ 	andi	$t6,$a2,0x1
/*  f02d374:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f02d378:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f02d37c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f02d380:	00001825 */ 	or	$v1,$zero,$zero
/*  f02d384:	11c00003 */ 	beqz	$t6,.L0f02d394
/*  f02d388:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f02d38c:	1000000c */ 	beqz	$zero,.L0f02d3c0
/*  f02d390:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f02d394:
/*  f02d394:	30cf0002 */ 	andi	$t7,$a2,0x2
/*  f02d398:	51e0000a */ 	beqzl	$t7,.L0f02d3c4
/*  f02d39c:	30d94000 */ 	andi	$t9,$a2,0x4000
/*  f02d3a0:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f02d3a4:	0c004b70 */ 	jal	random
/*  f02d3a8:	a3a80023 */ 	sb	$t0,0x23($sp)
/*  f02d3ac:	30430001 */ 	andi	$v1,$v0,0x1
/*  f02d3b0:	2c780001 */ 	sltiu	$t8,$v1,0x1
/*  f02d3b4:	03001825 */ 	or	$v1,$t8,$zero
/*  f02d3b8:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f02d3bc:	93a80023 */ 	lbu	$t0,0x23($sp)
.L0f02d3c0:
/*  f02d3c0:	30d94000 */ 	andi	$t9,$a2,0x4000
.L0f02d3c4:
/*  f02d3c4:	13200002 */ 	beqz	$t9,.L0f02d3d0
/*  f02d3c8:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f02d3cc:	00004025 */ 	or	$t0,$zero,$zero
.L0f02d3d0:
/*  f02d3d0:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f02d3d4:	00003025 */ 	or	$a2,$zero,$zero
/*  f02d3d8:	00003825 */ 	or	$a3,$zero,$zero
/*  f02d3dc:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f02d3e0:	0fc0b4ce */ 	jal	func0f02d338
/*  f02d3e4:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f02d3e8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f02d3ec:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f02d3f0:	03e00008 */ 	jr	$ra
/*  f02d3f4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f02d3f8
/*  f02d3f8:	3c0e8006 */ 	lui	$t6,%hi(var80062c80)
/*  f02d3fc:	8dce2c80 */ 	lw	$t6,%lo(var80062c80)($t6)
/*  f02d400:	3c028006 */ 	lui	$v0,%hi(var80062b1c)
/*  f02d404:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f02d408:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f02d40c:	03e00008 */ 	jr	$ra
/*  f02d410:	8c422b1c */ 	lw	$v0,%lo(var80062b1c)($v0)
);

u32 bodyGetHead(u32 bodynum)
{
	u32 head;

	if (g_Bodies[bodynum].headbank) {
		head = g_HeadsA[g_HeadsAIndex++];

		if (g_HeadsAIndex == g_MaxHeadsPerBank) {
			g_HeadsAIndex = 0;
		}
	} else if (bodynum == BODY_FEM_GUARD) {
		head = g_FemaleHeads[random() % 3];
	} else {
		head = g_HeadsB[g_HeadsBIndex++];

		if (g_HeadsBIndex == g_MaxHeadsPerBank) {
			g_HeadsBIndex = 0;
		}
	}

	return head;
}

GLOBAL_ASM(
glabel func0f02d4fc
/*  f02d4fc:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f02d500:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f02d504:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f02d508:	afa400b8 */ 	sw	$a0,0xb8($sp)
/*  f02d50c:	afa600c0 */ 	sw	$a2,0xc0($sp)
/*  f02d510:	00a08025 */ 	or	$s0,$a1,$zero
/*  f02d514:	94a4000a */ 	lhu	$a0,0xa($a1)
/*  f02d518:	24050046 */ 	addiu	$a1,$zero,0x46
/*  f02d51c:	0fc456ac */ 	jal	padUnpack
/*  f02d520:	27a60064 */ 	addiu	$a2,$sp,0x64
/*  f02d524:	3c014348 */ 	lui	$at,0x4348
/*  f02d528:	44812000 */ 	mtc1	$at,$f4
/*  f02d52c:	3c01c348 */ 	lui	$at,0xc348
/*  f02d530:	8fae00ac */ 	lw	$t6,0xac($sp)
/*  f02d534:	44813000 */ 	mtc1	$at,$f6
/*  f02d538:	240fffff */ 	addiu	$t7,$zero,-1
/*  f02d53c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f02d540:	a7af0062 */ 	sh	$t7,0x62($sp)
/*  f02d544:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f02d548:	27a40064 */ 	addiu	$a0,$sp,0x64
/*  f02d54c:	3c0541a0 */ 	lui	$a1,0x41a0
/*  f02d550:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f02d554:	2407003f */ 	addiu	$a3,$zero,0x3f
/*  f02d558:	e7a40014 */ 	swc1	$f4,0x14($sp)
/*  f02d55c:	a7ae0060 */ 	sh	$t6,0x60($sp)
/*  f02d560:	0c00a9a1 */ 	jal	func0002a684
/*  f02d564:	e7a60018 */ 	swc1	$f6,0x18($sp)
/*  f02d568:	5440000a */ 	bnezl	$v0,.L0f02d594
/*  f02d56c:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f02d570:	86190022 */ 	lh	$t9,0x22($s0)
/*  f02d574:	2401ffff */ 	addiu	$at,$zero,-1
/*  f02d578:	57210006 */ 	bnel	$t9,$at,.L0f02d594
/*  f02d57c:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f02d580:	8e080004 */ 	lw	$t0,0x4($s0)
/*  f02d584:	31090100 */ 	andi	$t1,$t0,0x100
/*  f02d588:	51200184 */ 	beqzl	$t1,.L0f02db9c
/*  f02d58c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f02d590:	8e020004 */ 	lw	$v0,0x4($s0)
.L0f02d594:
/*  f02d594:	304300e0 */ 	andi	$v1,$v0,0xe0
/*  f02d598:	5060001b */ 	beqzl	$v1,.L0f02d608
/*  f02d59c:	3c0dffff */ 	lui	$t5,0xffff
/*  f02d5a0:	1060017d */ 	beqz	$v1,.L0f02db98
/*  f02d5a4:	304a0020 */ 	andi	$t2,$v0,0x20
/*  f02d5a8:	51400007 */ 	beqzl	$t2,.L0f02d5c8
/*  f02d5ac:	304b0040 */ 	andi	$t3,$v0,0x40
/*  f02d5b0:	0fc5b367 */ 	jal	getDifficulty
/*  f02d5b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02d5b8:	50400013 */ 	beqzl	$v0,.L0f02d608
/*  f02d5bc:	3c0dffff */ 	lui	$t5,0xffff
/*  f02d5c0:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f02d5c4:	304b0040 */ 	andi	$t3,$v0,0x40
.L0f02d5c8:
/*  f02d5c8:	51600008 */ 	beqzl	$t3,.L0f02d5ec
/*  f02d5cc:	304c0080 */ 	andi	$t4,$v0,0x80
/*  f02d5d0:	0fc5b367 */ 	jal	getDifficulty
/*  f02d5d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02d5d8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f02d5dc:	5041000a */ 	beql	$v0,$at,.L0f02d608
/*  f02d5e0:	3c0dffff */ 	lui	$t5,0xffff
/*  f02d5e4:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f02d5e8:	304c0080 */ 	andi	$t4,$v0,0x80
.L0f02d5ec:
/*  f02d5ec:	5180016b */ 	beqzl	$t4,.L0f02db9c
/*  f02d5f0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f02d5f4:	0fc5b367 */ 	jal	getDifficulty
/*  f02d5f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02d5fc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f02d600:	14410165 */ 	bne	$v0,$at,.L0f02db98
/*  f02d604:	3c0dffff */ 	lui	$t5,0xffff
.L0f02d608:
/*  f02d608:	35ad26fd */ 	ori	$t5,$t5,0x26fd
/*  f02d60c:	afad0048 */ 	sw	$t5,0x48($sp)
/*  f02d610:	9202000c */ 	lbu	$v0,0xc($s0)
/*  f02d614:	240100ff */ 	addiu	$at,$zero,0xff
/*  f02d618:	00003825 */ 	or	$a3,$zero,$zero
/*  f02d61c:	54410007 */ 	bnel	$v0,$at,.L0f02d63c
/*  f02d620:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f02d624:	0fc0b4fe */ 	jal	func0f02d3f8
/*  f02d628:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f02d62c:	8fa70058 */ 	lw	$a3,0x58($sp)
/*  f02d630:	10000002 */ 	beqz	$zero,.L0f02d63c
/*  f02d634:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f02d638:	afa2004c */ 	sw	$v0,0x4c($sp)
.L0f02d63c:
/*  f02d63c:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f02d640:	3c188008 */ 	lui	$t8,%hi(g_Bodies)
/*  f02d644:	2718cf04 */ 	addiu	$t8,$t8,%lo(g_Bodies)
/*  f02d648:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f02d64c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f02d650:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f02d654:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f02d658:	afb90038 */ 	sw	$t9,0x38($sp)
/*  f02d65c:	8f280000 */ 	lw	$t0,0x0($t9)
/*  f02d660:	00085040 */ 	sll	$t2,$t0,0x1
/*  f02d664:	0542000f */ 	bltzl	$t2,.L0f02d6a4
/*  f02d668:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f02d66c:	8202000d */ 	lb	$v0,0xd($s0)
/*  f02d670:	3c01ffff */ 	lui	$at,0xffff
/*  f02d674:	342126fd */ 	ori	$at,$at,0x26fd
/*  f02d678:	04400003 */ 	bltz	$v0,.L0f02d688
/*  f02d67c:	8fab0048 */ 	lw	$t3,0x48($sp)
/*  f02d680:	10000007 */ 	beqz	$zero,.L0f02d6a0
/*  f02d684:	afa20048 */ 	sw	$v0,0x48($sp)
.L0f02d688:
/*  f02d688:	15610005 */ 	bne	$t3,$at,.L0f02d6a0
/*  f02d68c:	8fa4004c */ 	lw	$a0,0x4c($sp)
/*  f02d690:	0fc0b505 */ 	jal	bodyGetHead
/*  f02d694:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f02d698:	8fa70058 */ 	lw	$a3,0x58($sp)
/*  f02d69c:	afa20048 */ 	sw	$v0,0x48($sp)
.L0f02d6a0:
/*  f02d6a0:	8fac0048 */ 	lw	$t4,0x48($sp)
.L0f02d6a4:
/*  f02d6a4:	240dffff */ 	addiu	$t5,$zero,-1
/*  f02d6a8:	8fa4004c */ 	lw	$a0,0x4c($sp)
/*  f02d6ac:	05810014 */ 	bgez	$t4,.L0f02d700
/*  f02d6b0:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f02d6b4:	01ac1023 */ 	subu	$v0,$t5,$t4
/*  f02d6b8:	04400007 */ 	bltz	$v0,.L0f02d6d8
/*  f02d6bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f02d6c0:	28410016 */ 	slti	$at,$v0,0x16
/*  f02d6c4:	50200005 */ 	beqzl	$at,.L0f02d6dc
/*  f02d6c8:	8fa4004c */ 	lw	$a0,0x4c($sp)
/*  f02d6cc:	0fc6395f */ 	jal	func0f18e57c
/*  f02d6d0:	27a50048 */ 	addiu	$a1,$sp,0x48
/*  f02d6d4:	00403825 */ 	or	$a3,$v0,$zero
.L0f02d6d8:
/*  f02d6d8:	8fa4004c */ 	lw	$a0,0x4c($sp)
.L0f02d6dc:
/*  f02d6dc:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f02d6e0:	00003025 */ 	or	$a2,$zero,$zero
/*  f02d6e4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f02d6e8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f02d6ec:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f02d6f0:	0fc0b3a3 */ 	jal	func0f02ce8c
/*  f02d6f4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f02d6f8:	10000004 */ 	beqz	$zero,.L0f02d70c
/*  f02d6fc:	afa20054 */ 	sw	$v0,0x54($sp)
.L0f02d700:
/*  f02d700:	0fc0b4db */ 	jal	func0f02d36c
/*  f02d704:	8e060004 */ 	lw	$a2,0x4($s0)
/*  f02d708:	afa20054 */ 	sw	$v0,0x54($sp)
.L0f02d70c:
/*  f02d70c:	10400122 */ 	beqz	$v0,.L0f02db98
/*  f02d710:	c7ac0070 */ 	lwc1	$f12,0x70($sp)
/*  f02d714:	0fc259d4 */ 	jal	func0f096750
/*  f02d718:	c7ae0078 */ 	lwc1	$f14,0x78($sp)
/*  f02d71c:	e7a00044 */ 	swc1	$f0,0x44($sp)
/*  f02d720:	0c006134 */ 	jal	ailistFindById
/*  f02d724:	9604000e */ 	lhu	$a0,0xe($s0)
/*  f02d728:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f02d72c:	27a50064 */ 	addiu	$a1,$sp,0x64
/*  f02d730:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f02d734:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f02d738:	0fc08332 */ 	jal	func0f020cc8
/*  f02d73c:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f02d740:	10400115 */ 	beqz	$v0,.L0f02db98
/*  f02d744:	00402025 */ 	or	$a0,$v0,$zero
/*  f02d748:	0fc1812f */ 	jal	func0f0604bc
/*  f02d74c:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f02d750:	0fc180bc */ 	jal	propHide
/*  f02d754:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f02d758:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f02d75c:	86050008 */ 	lh	$a1,0x8($s0)
/*  f02d760:	8dc40004 */ 	lw	$a0,0x4($t6)
/*  f02d764:	0fc07937 */ 	jal	chrSetChrnum
/*  f02d768:	afa4005c */ 	sw	$a0,0x5c($sp)
/*  f02d76c:	960f0014 */ 	lhu	$t7,0x14($s0)
/*  f02d770:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f02d774:	448f4000 */ 	mtc1	$t7,$f8
/*  f02d778:	05e10005 */ 	bgez	$t7,.L0f02d790
/*  f02d77c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f02d780:	3c014f80 */ 	lui	$at,0x4f80
/*  f02d784:	44818000 */ 	mtc1	$at,$f16
/*  f02d788:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02d78c:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f02d790:
/*  f02d790:	3c01447a */ 	lui	$at,0x447a
/*  f02d794:	44819000 */ 	mtc1	$at,$f18
/*  f02d798:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02d79c:	46125103 */ 	div.s	$f4,$f10,$f18
/*  f02d7a0:	e4c400f0 */ 	swc1	$f4,0xf0($a2)
/*  f02d7a4:	96180016 */ 	lhu	$t8,0x16($s0)
/*  f02d7a8:	44983000 */ 	mtc1	$t8,$f6
/*  f02d7ac:	07010005 */ 	bgez	$t8,.L0f02d7c4
/*  f02d7b0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f02d7b4:	3c014f80 */ 	lui	$at,0x4f80
/*  f02d7b8:	44818000 */ 	mtc1	$at,$f16
/*  f02d7bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02d7c0:	46104200 */ 	add.s	$f8,$f8,$f16
.L0f02d7c4:
/*  f02d7c4:	e4c800dc */ 	swc1	$f8,0xdc($a2)
/*  f02d7c8:	96190010 */ 	lhu	$t9,0x10($s0)
/*  f02d7cc:	a4d90128 */ 	sh	$t9,0x128($a2)
/*  f02d7d0:	96080012 */ 	lhu	$t0,0x12($s0)
/*  f02d7d4:	a4c8012a */ 	sh	$t0,0x12a($a2)
/*  f02d7d8:	8fa90048 */ 	lw	$t1,0x48($sp)
/*  f02d7dc:	a0c90006 */ 	sb	$t1,0x6($a2)
/*  f02d7e0:	8faa004c */ 	lw	$t2,0x4c($sp)
/*  f02d7e4:	a4ca0010 */ 	sh	$t2,0x10($a2)
/*  f02d7e8:	0fc0b378 */ 	jal	func0f02cde0
/*  f02d7ec:	84c40010 */ 	lh	$a0,0x10($a2)
/*  f02d7f0:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f02d7f4:	3c0e8008 */ 	lui	$t6,0x8008
/*  f02d7f8:	25ced760 */ 	addiu	$t6,$t6,-10400
/*  f02d7fc:	90cb032e */ 	lbu	$t3,0x32e($a2)
/*  f02d800:	a0c202fe */ 	sb	$v0,0x2fe($a2)
/*  f02d804:	316dfff7 */ 	andi	$t5,$t3,0xfff7
/*  f02d808:	a0cd032e */ 	sb	$t5,0x32e($a2)
/*  f02d80c:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f02d810:	558e000e */ 	bnel	$t4,$t6,.L0f02d84c
/*  f02d814:	8fa90038 */ 	lw	$t1,0x38($sp)
/*  f02d818:	90cf0362 */ 	lbu	$t7,0x362($a2)
/*  f02d81c:	3c014339 */ 	lui	$at,0x4339
/*  f02d820:	44815000 */ 	mtc1	$at,$f10
/*  f02d824:	3c0141f0 */ 	lui	$at,0x41f0
/*  f02d828:	31f9ff0f */ 	andi	$t9,$t7,0xff0f
/*  f02d82c:	44819000 */ 	mtc1	$at,$f18
/*  f02d830:	a0d90362 */ 	sb	$t9,0x362($a2)
/*  f02d834:	332800f0 */ 	andi	$t0,$t9,0xf0
/*  f02d838:	a0c80362 */ 	sb	$t0,0x362($a2)
/*  f02d83c:	e4ca0028 */ 	swc1	$f10,0x28($a2)
/*  f02d840:	1000002a */ 	beqz	$zero,.L0f02d8ec
/*  f02d844:	e4d20024 */ 	swc1	$f18,0x24($a2)
/*  f02d848:	8fa90038 */ 	lw	$t1,0x38($sp)
.L0f02d84c:
/*  f02d84c:	3c0a8008 */ 	lui	$t2,0x8008
/*  f02d850:	254ad83c */ 	addiu	$t2,$t2,-10180
/*  f02d854:	152a0025 */ 	bne	$t1,$t2,.L0f02d8ec
/*  f02d858:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f02d85c:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f02d860:	0c0048f2 */ 	jal	malloc
/*  f02d864:	afa6005c */ 	sw	$a2,0x5c($sp)
/*  f02d868:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f02d86c:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f02d870:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f02d874:	0c0048f2 */ 	jal	malloc
/*  f02d878:	acc20348 */ 	sw	$v0,0x348($a2)
/*  f02d87c:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f02d880:	24040030 */ 	addiu	$a0,$zero,0x30
/*  f02d884:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f02d888:	0c0048f2 */ 	jal	malloc
/*  f02d88c:	acc2034c */ 	sw	$v0,0x34c($a2)
/*  f02d890:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f02d894:	24040030 */ 	addiu	$a0,$zero,0x30
/*  f02d898:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f02d89c:	8ccb0348 */ 	lw	$t3,0x348($a2)
/*  f02d8a0:	0c0048f2 */ 	jal	malloc
/*  f02d8a4:	ad620004 */ 	sw	$v0,0x4($t3)
/*  f02d8a8:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f02d8ac:	240cffff */ 	addiu	$t4,$zero,-1
/*  f02d8b0:	3c014348 */ 	lui	$at,0x4348
/*  f02d8b4:	8ccd034c */ 	lw	$t5,0x34c($a2)
/*  f02d8b8:	44812000 */ 	mtc1	$at,$f4
/*  f02d8bc:	3c014228 */ 	lui	$at,0x4228
/*  f02d8c0:	ada20004 */ 	sw	$v0,0x4($t5)
/*  f02d8c4:	8cce0348 */ 	lw	$t6,0x348($a2)
/*  f02d8c8:	44813000 */ 	mtc1	$at,$f6
/*  f02d8cc:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f02d8d0:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f02d8d4:	a1ec0000 */ 	sb	$t4,0x0($t7)
/*  f02d8d8:	8cd9034c */ 	lw	$t9,0x34c($a2)
/*  f02d8dc:	8f280004 */ 	lw	$t0,0x4($t9)
/*  f02d8e0:	a1180000 */ 	sb	$t8,0x0($t0)
/*  f02d8e4:	e4c40028 */ 	swc1	$f4,0x28($a2)
/*  f02d8e8:	e4c60024 */ 	swc1	$f6,0x24($a2)
.L0f02d8ec:
/*  f02d8ec:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f02d8f0:	30490008 */ 	andi	$t1,$v0,0x8
/*  f02d8f4:	51200006 */ 	beqzl	$t1,.L0f02d910
/*  f02d8f8:	304d0200 */ 	andi	$t5,$v0,0x200
/*  f02d8fc:	8cca0018 */ 	lw	$t2,0x18($a2)
/*  f02d900:	354b0010 */ 	ori	$t3,$t2,0x10
/*  f02d904:	accb0018 */ 	sw	$t3,0x18($a2)
/*  f02d908:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f02d90c:	304d0200 */ 	andi	$t5,$v0,0x200
.L0f02d910:
/*  f02d910:	51a00007 */ 	beqzl	$t5,.L0f02d930
/*  f02d914:	304f0400 */ 	andi	$t7,$v0,0x400
/*  f02d918:	8cce0014 */ 	lw	$t6,0x14($a2)
/*  f02d91c:	3c010040 */ 	lui	$at,0x40
/*  f02d920:	01c16025 */ 	or	$t4,$t6,$at
/*  f02d924:	accc0014 */ 	sw	$t4,0x14($a2)
/*  f02d928:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f02d92c:	304f0400 */ 	andi	$t7,$v0,0x400
.L0f02d930:
/*  f02d930:	51e00007 */ 	beqzl	$t7,.L0f02d950
/*  f02d934:	30480800 */ 	andi	$t0,$v0,0x800
/*  f02d938:	8cd90014 */ 	lw	$t9,0x14($a2)
/*  f02d93c:	3c014000 */ 	lui	$at,0x4000
/*  f02d940:	0321c025 */ 	or	$t8,$t9,$at
/*  f02d944:	acd80014 */ 	sw	$t8,0x14($a2)
/*  f02d948:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f02d94c:	30480800 */ 	andi	$t0,$v0,0x800
.L0f02d950:
/*  f02d950:	51000007 */ 	beqzl	$t0,.L0f02d970
/*  f02d954:	304b1000 */ 	andi	$t3,$v0,0x1000
/*  f02d958:	8cc90014 */ 	lw	$t1,0x14($a2)
/*  f02d95c:	3c010800 */ 	lui	$at,0x800
/*  f02d960:	01215025 */ 	or	$t2,$t1,$at
/*  f02d964:	acca0014 */ 	sw	$t2,0x14($a2)
/*  f02d968:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f02d96c:	304b1000 */ 	andi	$t3,$v0,0x1000
.L0f02d970:
/*  f02d970:	51600006 */ 	beqzl	$t3,.L0f02d98c
/*  f02d974:	304c8000 */ 	andi	$t4,$v0,0x8000
/*  f02d978:	8ccd0018 */ 	lw	$t5,0x18($a2)
/*  f02d97c:	35ae0400 */ 	ori	$t6,$t5,0x400
/*  f02d980:	acce0018 */ 	sw	$t6,0x18($a2)
/*  f02d984:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f02d988:	304c8000 */ 	andi	$t4,$v0,0x8000
.L0f02d98c:
/*  f02d98c:	51800006 */ 	beqzl	$t4,.L0f02d9a8
/*  f02d990:	30482000 */ 	andi	$t0,$v0,0x2000
/*  f02d994:	90d9032e */ 	lbu	$t9,0x32e($a2)
/*  f02d998:	37380008 */ 	ori	$t8,$t9,0x8
/*  f02d99c:	a0d8032e */ 	sb	$t8,0x32e($a2)
/*  f02d9a0:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f02d9a4:	30482000 */ 	andi	$t0,$v0,0x2000
.L0f02d9a8:
/*  f02d9a8:	51000006 */ 	beqzl	$t0,.L0f02d9c4
/*  f02d9ac:	00026bc0 */ 	sll	$t5,$v0,0xf
/*  f02d9b0:	90ca032e */ 	lbu	$t2,0x32e($a2)
/*  f02d9b4:	354b0010 */ 	ori	$t3,$t2,0x10
/*  f02d9b8:	a0cb032e */ 	sb	$t3,0x32e($a2)
/*  f02d9bc:	8e020004 */ 	lw	$v0,0x4($s0)
/*  f02d9c0:	00026bc0 */ 	sll	$t5,$v0,0xf
.L0f02d9c4:
/*  f02d9c4:	05a30005 */ 	bgezl	$t5,.L0f02d9dc
/*  f02d9c8:	8e0f0018 */ 	lw	$t7,0x18($s0)
/*  f02d9cc:	94ce0192 */ 	lhu	$t6,0x192($a2)
/*  f02d9d0:	35cc0008 */ 	ori	$t4,$t6,0x8
/*  f02d9d4:	a4cc0192 */ 	sh	$t4,0x192($a2)
/*  f02d9d8:	8e0f0018 */ 	lw	$t7,0x18($s0)
.L0f02d9dc:
/*  f02d9dc:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f02d9e0:	accf0114 */ 	sw	$t7,0x114($a2)
/*  f02d9e4:	8e19001c */ 	lw	$t9,0x1c($s0)
/*  f02d9e8:	acd90118 */ 	sw	$t9,0x118($a2)
/*  f02d9ec:	0fc41b99 */ 	jal	cheatIsActive
/*  f02d9f0:	afa6005c */ 	sw	$a2,0x5c($sp)
/*  f02d9f4:	10400007 */ 	beqz	$v0,.L0f02da14
/*  f02d9f8:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f02d9fc:	8cd80118 */ 	lw	$t8,0x118($a2)
/*  f02da00:	2401efff */ 	addiu	$at,$zero,-4097
/*  f02da04:	03014024 */ 	and	$t0,$t8,$at
/*  f02da08:	acc80118 */ 	sw	$t0,0x118($a2)
/*  f02da0c:	350a0001 */ 	ori	$t2,$t0,0x1
/*  f02da10:	acca0118 */ 	sw	$t2,0x118($a2)
.L0f02da14:
/*  f02da14:	920b0020 */ 	lbu	$t3,0x20($s0)
/*  f02da18:	24010004 */ 	addiu	$at,$zero,0x4
/*  f02da1c:	a0cb0125 */ 	sb	$t3,0x125($a2)
/*  f02da20:	920d0021 */ 	lbu	$t5,0x21($s0)
/*  f02da24:	acc002d4 */ 	sw	$zero,0x2d4($a2)
/*  f02da28:	a0cd02a2 */ 	sb	$t5,0x2a2($a2)
/*  f02da2c:	92020028 */ 	lbu	$v0,0x28($s0)
/*  f02da30:	10410003 */ 	beq	$v0,$at,.L0f02da40
/*  f02da34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02da38:	10000006 */ 	beqz	$zero,.L0f02da54
/*  f02da3c:	a0c202b0 */ 	sb	$v0,0x2b0($a2)
.L0f02da40:
/*  f02da40:	0c004b70 */ 	jal	random
/*  f02da44:	afa6005c */ 	sw	$a2,0x5c($sp)
/*  f02da48:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f02da4c:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f02da50:	a0ce02b0 */ 	sb	$t6,0x2b0($a2)
.L0f02da54:
/*  f02da54:	0c004b70 */ 	jal	random
/*  f02da58:	afa6005c */ 	sw	$a2,0x5c($sp)
/*  f02da5c:	24030003 */ 	addiu	$v1,$zero,0x3
/*  f02da60:	0043001b */ 	divu	$zero,$v0,$v1
/*  f02da64:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f02da68:	00006010 */ 	mfhi	$t4
/*  f02da6c:	3c188008 */ 	lui	$t8,%hi(g_Bodies)
/*  f02da70:	84cf0010 */ 	lh	$t7,0x10($a2)
/*  f02da74:	a0cc02b1 */ 	sb	$t4,0x2b1($a2)
/*  f02da78:	14600002 */ 	bnez	$v1,.L0f02da84
/*  f02da7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02da80:	0007000d */ 	break	0x7
.L0f02da84:
/*  f02da84:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f02da88:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f02da8c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f02da90:	0319c021 */ 	addu	$t8,$t8,$t9
/*  f02da94:	8f18cf04 */ 	lw	$t8,%lo(g_Bodies)($t8)
/*  f02da98:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f02da9c:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f02daa0:	001847c2 */ 	srl	$t0,$t8,0x1f
/*  f02daa4:	55000003 */ 	bnezl	$t0,.L0f02dab4
/*  f02daa8:	92090029 */ 	lbu	$t1,0x29($s0)
/*  f02daac:	a0c302b1 */ 	sb	$v1,0x2b1($a2)
/*  f02dab0:	92090029 */ 	lbu	$t1,0x29($s0)
.L0f02dab4:
/*  f02dab4:	3c0d8006 */ 	lui	$t5,%hi(g_ChrsA)
/*  f02dab8:	24010368 */ 	addiu	$at,$zero,0x368
/*  f02dabc:	a0c902e3 */ 	sb	$t1,0x2e3($a2)
/*  f02dac0:	860a0022 */ 	lh	$t2,0x22($s0)
/*  f02dac4:	acca02e4 */ 	sw	$t2,0x2e4($a2)
/*  f02dac8:	920b002a */ 	lbu	$t3,0x2a($s0)
/*  f02dacc:	a0cb02fc */ 	sb	$t3,0x2fc($a2)
/*  f02dad0:	8dad2988 */ 	lw	$t5,%lo(g_ChrsA)($t5)
/*  f02dad4:	920f002b */ 	lbu	$t7,0x2b($s0)
/*  f02dad8:	00cd7023 */ 	subu	$t6,$a2,$t5
/*  f02dadc:	01c1001a */ 	div	$zero,$t6,$at
/*  f02dae0:	00006012 */ 	mflo	$t4
/*  f02dae4:	a60c0000 */ 	sh	$t4,0x0($s0)
/*  f02dae8:	8cd80114 */ 	lw	$t8,0x114($a2)
/*  f02daec:	a0cf02e2 */ 	sb	$t7,0x2e2($a2)
/*  f02daf0:	8e190024 */ 	lw	$t9,0x24($s0)
/*  f02daf4:	00184080 */ 	sll	$t0,$t8,0x2
/*  f02daf8:	05010004 */ 	bgez	$t0,.L0f02db0c
/*  f02dafc:	acd902a4 */ 	sw	$t9,0x2a4($a2)
/*  f02db00:	8cc90018 */ 	lw	$t1,0x18($a2)
/*  f02db04:	352a0002 */ 	ori	$t2,$t1,0x2
/*  f02db08:	acca0018 */ 	sw	$t2,0x18($a2)
.L0f02db0c:
/*  f02db0c:	8c4b0318 */ 	lw	$t3,0x318($v0)
/*  f02db10:	3c0d800a */ 	lui	$t5,0x800a
/*  f02db14:	1560000b */ 	bnez	$t3,.L0f02db44
/*  f02db18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02db1c:	81aedfeb */ 	lb	$t6,-0x2015($t5)
/*  f02db20:	05c10008 */ 	bgez	$t6,.L0f02db44
/*  f02db24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02db28:	8c4c0474 */ 	lw	$t4,0x474($v0)
/*  f02db2c:	19800005 */ 	blez	$t4,.L0f02db44
/*  f02db30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02db34:	8ccf0114 */ 	lw	$t7,0x114($a2)
/*  f02db38:	3c010001 */ 	lui	$at,0x1
/*  f02db3c:	01e1c825 */ 	or	$t9,$t7,$at
/*  f02db40:	acd90114 */ 	sw	$t9,0x114($a2)
.L0f02db44:
/*  f02db44:	0c004b70 */ 	jal	random
/*  f02db48:	afa6005c */ 	sw	$a2,0x5c($sp)
/*  f02db4c:	24010005 */ 	addiu	$at,$zero,0x5
/*  f02db50:	0041001b */ 	divu	$zero,$v0,$at
/*  f02db54:	0000c010 */ 	mfhi	$t8
/*  f02db58:	8fa6005c */ 	lw	$a2,0x5c($sp)
/*  f02db5c:	17000004 */ 	bnez	$t8,.L0f02db70
/*  f02db60:	24010001 */ 	addiu	$at,$zero,0x1
/*  f02db64:	8cc80118 */ 	lw	$t0,0x118($a2)
/*  f02db68:	35090080 */ 	ori	$t1,$t0,0x80
/*  f02db6c:	acc90118 */ 	sw	$t1,0x118($a2)
.L0f02db70:
/*  f02db70:	10c00003 */ 	beqz	$a2,.L0f02db80
/*  f02db74:	00001025 */ 	or	$v0,$zero,$zero
/*  f02db78:	10000001 */ 	beqz	$zero,.L0f02db80
/*  f02db7c:	90c202fe */ 	lbu	$v0,0x2fe($a2)
.L0f02db80:
/*  f02db80:	54410006 */ 	bnel	$v0,$at,.L0f02db9c
/*  f02db84:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f02db88:	8cca0018 */ 	lw	$t2,0x18($a2)
/*  f02db8c:	3c010002 */ 	lui	$at,0x2
/*  f02db90:	01415825 */ 	or	$t3,$t2,$at
/*  f02db94:	accb0018 */ 	sw	$t3,0x18($a2)
.L0f02db98:
/*  f02db98:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f02db9c:
/*  f02db9c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f02dba0:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
/*  f02dba4:	03e00008 */ 	jr	$ra
/*  f02dba8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f02dbac
/*  f02dbac:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f02dbb0:	3c077f16 */ 	lui	$a3,%hi(func0f167e7c)
/*  f02dbb4:	3c087f17 */ 	lui	$t0,%hi(fadeConfigure)
/*  f02dbb8:	24e37e7c */ 	addiu	$v1,$a3,%lo(func0f167e7c)
/*  f02dbbc:	2506856c */ 	addiu	$a2,$t0,%lo(fadeConfigure)
/*  f02dbc0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f02dbc4:	0066082b */ 	sltu	$at,$v1,$a2
/*  f02dbc8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f02dbcc:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f02dbd0:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f02dbd4:	afa50084 */ 	sw	$a1,0x84($sp)
/*  f02dbd8:	a7a5007c */ 	sh	$a1,0x7c($sp)
/*  f02dbdc:	a7b8007e */ 	sh	$t8,0x7e($sp)
/*  f02dbe0:	10200007 */ 	beqz	$at,.L0f02dc00
/*  f02dbe4:	00001025 */ 	or	$v0,$zero,$zero
.L0f02dbe8:
/*  f02dbe8:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f02dbec:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f02dbf0:	0002c840 */ 	sll	$t9,$v0,0x1
/*  f02dbf4:	0066082b */ 	sltu	$at,$v1,$a2
/*  f02dbf8:	1420fffb */ 	bnez	$at,.L0f02dbe8
/*  f02dbfc:	03291026 */ 	xor	$v0,$t9,$t1
.L0f02dc00:
/*  f02dc00:	3c01a7be */ 	lui	$at,0xa7be
/*  f02dc04:	34211bf0 */ 	ori	$at,$at,0x1bf0
/*  f02dc08:	1041000b */ 	beq	$v0,$at,.L0f02dc38
/*  f02dc0c:	00003025 */ 	or	$a2,$zero,$zero
/*  f02dc10:	3c047001 */ 	lui	$a0,%hi(func00012914)
/*  f02dc14:	3c057001 */ 	lui	$a1,%hi(func00012a0c)
/*  f02dc18:	24822914 */ 	addiu	$v0,$a0,%lo(func00012914)
/*  f02dc1c:	24a32a0c */ 	addiu	$v1,$a1,%lo(func00012a0c)
/*  f02dc20:	0043082b */ 	sltu	$at,$v0,$v1
/*  f02dc24:	10200004 */ 	beqz	$at,.L0f02dc38
.L0f02dc28:
/*  f02dc28:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f02dc2c:	0043082b */ 	sltu	$at,$v0,$v1
/*  f02dc30:	1420fffd */ 	bnez	$at,.L0f02dc28
/*  f02dc34:	ac40fffc */ 	sw	$zero,-0x4($v0)
.L0f02dc38:
/*  f02dc38:	2404006c */ 	addiu	$a0,$zero,0x6c
/*  f02dc3c:	0fc0b4db */ 	jal	func0f02d36c
/*  f02dc40:	00002825 */ 	or	$a1,$zero,$zero
/*  f02dc44:	10400055 */ 	beqz	$v0,.L0f02dd9c
/*  f02dc48:	00408025 */ 	or	$s0,$v0,$zero
/*  f02dc4c:	0c006134 */ 	jal	ailistFindById
/*  f02dc50:	00002025 */ 	or	$a0,$zero,$zero
/*  f02dc54:	02002025 */ 	or	$a0,$s0,$zero
/*  f02dc58:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f02dc5c:	27a6007c */ 	addiu	$a2,$sp,0x7c
/*  f02dc60:	24070000 */ 	addiu	$a3,$zero,0x0
/*  f02dc64:	0fc08332 */ 	jal	func0f020cc8
/*  f02dc68:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f02dc6c:	1040004b */ 	beqz	$v0,.L0f02dd9c
/*  f02dc70:	00402025 */ 	or	$a0,$v0,$zero
/*  f02dc74:	0fc1812f */ 	jal	func0f0604bc
/*  f02dc78:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f02dc7c:	0fc180bc */ 	jal	propHide
/*  f02dc80:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f02dc84:	8faa0078 */ 	lw	$t2,0x78($sp)
/*  f02dc88:	0fc0817b */ 	jal	getLowestUnusedChrId
/*  f02dc8c:	8d500004 */ 	lw	$s0,0x4($t2)
/*  f02dc90:	00022c00 */ 	sll	$a1,$v0,0x10
/*  f02dc94:	00055c03 */ 	sra	$t3,$a1,0x10
/*  f02dc98:	01602825 */ 	or	$a1,$t3,$zero
/*  f02dc9c:	0fc07937 */ 	jal	chrSetChrnum
/*  f02dca0:	02002025 */ 	or	$a0,$s0,$zero
/*  f02dca4:	44800000 */ 	mtc1	$zero,$f0
/*  f02dca8:	240c006c */ 	addiu	$t4,$zero,0x6c
/*  f02dcac:	a60c0010 */ 	sh	$t4,0x10($s0)
/*  f02dcb0:	a6000128 */ 	sh	$zero,0x128($s0)
/*  f02dcb4:	a600012a */ 	sh	$zero,0x12a($s0)
/*  f02dcb8:	a2000006 */ 	sb	$zero,0x6($s0)
/*  f02dcbc:	86040010 */ 	lh	$a0,0x10($s0)
/*  f02dcc0:	e60000f0 */ 	swc1	$f0,0xf0($s0)
/*  f02dcc4:	0fc0b378 */ 	jal	func0f02cde0
/*  f02dcc8:	e60000dc */ 	swc1	$f0,0xdc($s0)
/*  f02dccc:	a20202fe */ 	sb	$v0,0x2fe($s0)
/*  f02dcd0:	27ad006c */ 	addiu	$t5,$sp,0x6c
/*  f02dcd4:	27ae0068 */ 	addiu	$t6,$sp,0x68
/*  f02dcd8:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f02dcdc:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f02dce0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f02dce4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f02dce8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f02dcec:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f02dcf0:	3c0541f0 */ 	lui	$a1,0x41f0
/*  f02dcf4:	27a6007c */ 	addiu	$a2,$sp,0x7c
/*  f02dcf8:	0c00a86c */ 	jal	func0002a1b0
/*  f02dcfc:	00003825 */ 	or	$a3,$zero,$zero
/*  f02dd00:	3c014000 */ 	lui	$at,0x4000
/*  f02dd04:	44812000 */ 	mtc1	$at,$f4
/*  f02dd08:	e60000b8 */ 	swc1	$f0,0xb8($s0)
/*  f02dd0c:	e60000b4 */ 	swc1	$f0,0xb4($s0)
/*  f02dd10:	ae000114 */ 	sw	$zero,0x114($s0)
/*  f02dd14:	ae000118 */ 	sw	$zero,0x118($s0)
/*  f02dd18:	a2000125 */ 	sb	$zero,0x125($s0)
/*  f02dd1c:	a20002a2 */ 	sb	$zero,0x2a2($s0)
/*  f02dd20:	0c004b70 */ 	jal	random
/*  f02dd24:	e6040104 */ 	swc1	$f4,0x104($s0)
/*  f02dd28:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f02dd2c:	0c004b70 */ 	jal	random
/*  f02dd30:	a20f02b0 */ 	sb	$t7,0x2b0($s0)
/*  f02dd34:	24010003 */ 	addiu	$at,$zero,0x3
/*  f02dd38:	0041001b */ 	divu	$zero,$v0,$at
/*  f02dd3c:	3c0141d0 */ 	lui	$at,0x41d0
/*  f02dd40:	44813000 */ 	mtc1	$at,$f6
/*  f02dd44:	3c014348 */ 	lui	$at,0x4348
/*  f02dd48:	44814000 */ 	mtc1	$at,$f8
/*  f02dd4c:	0000c010 */ 	mfhi	$t8
/*  f02dd50:	a21802b1 */ 	sb	$t8,0x2b1($s0)
/*  f02dd54:	a20002e3 */ 	sb	$zero,0x2e3($s0)
/*  f02dd58:	ae0002e4 */ 	sw	$zero,0x2e4($s0)
/*  f02dd5c:	a20002fc */ 	sb	$zero,0x2fc($s0)
/*  f02dd60:	a20002e2 */ 	sb	$zero,0x2e2($s0)
/*  f02dd64:	ae0002a4 */ 	sw	$zero,0x2a4($s0)
/*  f02dd68:	02002025 */ 	or	$a0,$s0,$zero
/*  f02dd6c:	24050000 */ 	addiu	$a1,$zero,0x0
/*  f02dd70:	e6060024 */ 	swc1	$f6,0x24($s0)
/*  f02dd74:	0fc0ba68 */ 	jal	func0f02e9a0
/*  f02dd78:	e6080028 */ 	swc1	$f8,0x28($s0)
/*  f02dd7c:	8e190018 */ 	lw	$t9,0x18($s0)
/*  f02dd80:	960a0192 */ 	lhu	$t2,0x192($s0)
/*  f02dd84:	37290400 */ 	ori	$t1,$t9,0x400
/*  f02dd88:	354b0040 */ 	ori	$t3,$t2,0x40
/*  f02dd8c:	ae090018 */ 	sw	$t1,0x18($s0)
/*  f02dd90:	a60b0192 */ 	sh	$t3,0x192($s0)
/*  f02dd94:	10000002 */ 	beqz	$zero,.L0f02dda0
/*  f02dd98:	8fa20078 */ 	lw	$v0,0x78($sp)
.L0f02dd9c:
/*  f02dd9c:	00001025 */ 	or	$v0,$zero,$zero
.L0f02dda0:
/*  f02dda0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f02dda4:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f02dda8:	27bd0080 */ 	addiu	$sp,$sp,0x80
/*  f02ddac:	03e00008 */ 	jr	$ra
/*  f02ddb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02ddb4:	03e00008 */ 	jr	$ra
/*  f02ddb8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f02ddbc
/*  f02ddbc:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f02ddc0:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f02ddc4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f02ddc8:	848e0006 */ 	lh	$t6,0x6($a0)
/*  f02ddcc:	00a03825 */ 	or	$a3,$a1,$zero
/*  f02ddd0:	2401000d */ 	addiu	$at,$zero,0xd
/*  f02ddd4:	15c10081 */ 	bne	$t6,$at,.L0f02dfdc
/*  f02ddd8:	24050014 */ 	addiu	$a1,$zero,0x14
/*  f02dddc:	00e50019 */ 	multu	$a3,$a1
/*  f02dde0:	3c038008 */ 	lui	$v1,%hi(g_Bodies)
/*  f02dde4:	2463cf04 */ 	addiu	$v1,$v1,%lo(g_Bodies)
/*  f02dde8:	00007812 */ 	mflo	$t7
/*  f02ddec:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f02ddf0:	8f020000 */ 	lw	$v0,0x0($t8)
/*  f02ddf4:	00c50019 */ 	multu	$a2,$a1
/*  f02ddf8:	0002c8c0 */ 	sll	$t9,$v0,0x3
/*  f02ddfc:	00194742 */ 	srl	$t0,$t9,0x1d
/*  f02de00:	01001025 */ 	or	$v0,$t0,$zero
/*  f02de04:	2d010006 */ 	sltiu	$at,$t0,0x6
/*  f02de08:	00004812 */ 	mflo	$t1
/*  f02de0c:	00695021 */ 	addu	$t2,$v1,$t1
/*  f02de10:	8d460000 */ 	lw	$a2,0x0($t2)
/*  f02de14:	000658c0 */ 	sll	$t3,$a2,0x3
/*  f02de18:	000b3742 */ 	srl	$a2,$t3,0x1d
/*  f02de1c:	51060070 */ 	beql	$t0,$a2,.L0f02dfe0
/*  f02de20:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f02de24:	10200006 */ 	beqz	$at,.L0f02de40
/*  f02de28:	00086880 */ 	sll	$t5,$t0,0x2
/*  f02de2c:	3c017f1b */ 	lui	$at,%hi(var7f1a8a88)
/*  f02de30:	002d0821 */ 	addu	$at,$at,$t5
/*  f02de34:	8c2d8a88 */ 	lw	$t5,%lo(var7f1a8a88)($at)
/*  f02de38:	01a00008 */ 	jr	$t5
/*  f02de3c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f02de40:
/*  f02de40:	1000000a */ 	beqz	$zero,.L0f02de6c
/*  f02de44:	00003825 */ 	or	$a3,$zero,$zero
/*  f02de48:	10000008 */ 	beqz	$zero,.L0f02de6c
/*  f02de4c:	00003825 */ 	or	$a3,$zero,$zero
/*  f02de50:	10000006 */ 	beqz	$zero,.L0f02de6c
/*  f02de54:	2407ffdd */ 	addiu	$a3,$zero,-35
/*  f02de58:	10000004 */ 	beqz	$zero,.L0f02de6c
/*  f02de5c:	00003825 */ 	or	$a3,$zero,$zero
/*  f02de60:	10000002 */ 	beqz	$zero,.L0f02de6c
/*  f02de64:	2407ffec */ 	addiu	$a3,$zero,-20
/*  f02de68:	2407ffd8 */ 	addiu	$a3,$zero,-40
.L0f02de6c:
/*  f02de6c:	2cc10006 */ 	sltiu	$at,$a2,0x6
/*  f02de70:	1020000d */ 	beqz	$at,.L0f02dea8
/*  f02de74:	00067080 */ 	sll	$t6,$a2,0x2
/*  f02de78:	3c017f1b */ 	lui	$at,%hi(var7f1a8aa0)
/*  f02de7c:	002e0821 */ 	addu	$at,$at,$t6
/*  f02de80:	8c2e8aa0 */ 	lw	$t6,%lo(var7f1a8aa0)($at)
/*  f02de84:	01c00008 */ 	jr	$t6
/*  f02de88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02de8c:	10000006 */ 	beqz	$zero,.L0f02dea8
/*  f02de90:	24e7ffe2 */ 	addiu	$a3,$a3,-30
/*  f02de94:	10000004 */ 	beqz	$zero,.L0f02dea8
/*  f02de98:	24e70023 */ 	addiu	$a3,$a3,0x23
/*  f02de9c:	10000002 */ 	beqz	$zero,.L0f02dea8
/*  f02dea0:	24e70014 */ 	addiu	$a3,$a3,0x14
/*  f02dea4:	24e70028 */ 	addiu	$a3,$a3,0x28
.L0f02dea8:
/*  f02dea8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f02deac:	54c1000f */ 	bnel	$a2,$at,.L0f02deec
/*  f02deb0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f02deb4:	10400003 */ 	beqz	$v0,.L0f02dec4
/*  f02deb8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f02debc:	54410004 */ 	bnel	$v0,$at,.L0f02ded0
/*  f02dec0:	24010004 */ 	addiu	$at,$zero,0x4
.L0f02dec4:
/*  f02dec4:	10000010 */ 	beqz	$zero,.L0f02df08
/*  f02dec8:	24e7fff6 */ 	addiu	$a3,$a3,-10
/*  f02decc:	24010004 */ 	addiu	$at,$zero,0x4
.L0f02ded0:
/*  f02ded0:	10410003 */ 	beq	$v0,$at,.L0f02dee0
/*  f02ded4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f02ded8:	1441000b */ 	bne	$v0,$at,.L0f02df08
/*  f02dedc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f02dee0:
/*  f02dee0:	10000009 */ 	beqz	$zero,.L0f02df08
/*  f02dee4:	24e7fffb */ 	addiu	$a3,$a3,-5
/*  f02dee8:	24010004 */ 	addiu	$at,$zero,0x4
.L0f02deec:
/*  f02deec:	14c10006 */ 	bne	$a2,$at,.L0f02df08
/*  f02def0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f02def4:	10400003 */ 	beqz	$v0,.L0f02df04
/*  f02def8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f02defc:	14410002 */ 	bne	$v0,$at,.L0f02df08
/*  f02df00:	00000000 */ 	sll	$zero,$zero,0x0
.L0f02df04:
/*  f02df04:	24e7fffb */ 	addiu	$a3,$a3,-5
.L0f02df08:
/*  f02df08:	50e00035 */ 	beqzl	$a3,.L0f02dfe0
/*  f02df0c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f02df10:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f02df14:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f02df18:	8fa40048 */ 	lw	$a0,0x48($sp)
.L0f02df1c:
/*  f02df1c:	8fb00044 */ 	lw	$s0,0x44($sp)
/*  f02df20:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f02df24:	27a6003c */ 	addiu	$a2,$sp,0x3c
/*  f02df28:	0c008c67 */ 	jal	func0002319c
/*  f02df2c:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f02df30:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f02df34:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f02df38:	51e00019 */ 	beqzl	$t7,.L0f02dfa0
/*  f02df3c:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f02df40:	51f00017 */ 	beql	$t7,$s0,.L0f02dfa0
/*  f02df44:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f02df48:	95f80000 */ 	lhu	$t8,0x0($t7)
/*  f02df4c:	24010018 */ 	addiu	$at,$zero,0x18
/*  f02df50:	57010013 */ 	bnel	$t8,$at,.L0f02dfa0
/*  f02df54:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f02df58:	8de50004 */ 	lw	$a1,0x4($t7)
/*  f02df5c:	00001825 */ 	or	$v1,$zero,$zero
/*  f02df60:	00002025 */ 	or	$a0,$zero,$zero
/*  f02df64:	84b90010 */ 	lh	$t9,0x10($a1)
/*  f02df68:	5b20000d */ 	blezl	$t9,.L0f02dfa0
/*  f02df6c:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f02df70:	8ca8000c */ 	lw	$t0,0xc($a1)
.L0f02df74:
/*  f02df74:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f02df78:	01041021 */ 	addu	$v0,$t0,$a0
/*  f02df7c:	84490002 */ 	lh	$t1,0x2($v0)
/*  f02df80:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f02df84:	01275021 */ 	addu	$t2,$t1,$a3
/*  f02df88:	a44a0002 */ 	sh	$t2,0x2($v0)
/*  f02df8c:	84ab0010 */ 	lh	$t3,0x10($a1)
/*  f02df90:	006b082a */ 	slt	$at,$v1,$t3
/*  f02df94:	5420fff7 */ 	bnezl	$at,.L0f02df74
/*  f02df98:	8ca8000c */ 	lw	$t0,0xc($a1)
/*  f02df9c:	8fac0044 */ 	lw	$t4,0x44($sp)
.L0f02dfa0:
/*  f02dfa0:	5580ffde */ 	bnezl	$t4,.L0f02df1c
/*  f02dfa4:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f02dfa8:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f02dfac:	0fc1a25b */ 	jal	func0f06896c
/*  f02dfb0:	afa70038 */ 	sw	$a3,0x38($sp)
/*  f02dfb4:	10400009 */ 	beqz	$v0,.L0f02dfdc
/*  f02dfb8:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f02dfbc:	44872000 */ 	mtc1	$a3,$f4
/*  f02dfc0:	c446000c */ 	lwc1	$f6,0xc($v0)
/*  f02dfc4:	c44a0010 */ 	lwc1	$f10,0x10($v0)
/*  f02dfc8:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f02dfcc:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f02dfd0:	46005400 */ 	add.s	$f16,$f10,$f0
/*  f02dfd4:	e448000c */ 	swc1	$f8,0xc($v0)
/*  f02dfd8:	e4500010 */ 	swc1	$f16,0x10($v0)
.L0f02dfdc:
/*  f02dfdc:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f02dfe0:
/*  f02dfe0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f02dfe4:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f02dfe8:	03e00008 */ 	jr	$ra
/*  f02dfec:	00000000 */ 	sll	$zero,$zero,0x0
);
