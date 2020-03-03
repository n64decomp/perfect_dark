#include <ultra64.h>
#include "constants.h"
#include "game/cheats.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_005fd0.h"
#include "game/game_016100.h"
#include "game/game_01b0a0.h"
#include "game/game_092610.h"
#include "game/game_097ba0.h"
#include "game/game_0b0420.h"
#include "game/game_0b63b0.h"
#include "game/game_0d4690.h"
#include "game/game_0dcdb0.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/game_107fb0.h"
#include "game/game_10ccd0.h"
#include "game/game_1165d0.h"
#include "game/game_148b80.h"
#include "game/game_157db0.h"
#include "game/game_1655c0.h"
#include "game/game_167ae0.h"
#include "game/game_176d70.h"
#include "game/game_187770.h"
#include "game/game_19aa80.h"
#include "game/game_19c990.h"
#include "game/lang.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0bfb0.h"
#include "lib/lib_0d520.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_126b0.h"
#include "lib/lib_13130.h"
#include "lib/lib_13900.h"
#include "lib/lib_4b170.h"
#include "types.h"

const char var7f1b3860[] = "%s: %s\n";
const char var7f1b3868[] = "%s: %s\n";
const char var7f1b3870[] = "%d";
const char var7f1b3874[] = "%d";
const char var7f1b3878[] = "%d";
const char var7f1b387c[] = "%d";
const char var7f1b3880[] = "%d";
const char var7f1b3884[] = "%d";
const char var7f1b3888[] = "%s%s%.1f%%";
const char var7f1b3894[] = "";
const char var7f1b3898[] = "";
const char var7f1b389c[] = "%s: %s\n";
const char var7f1b38a4[] = "%s\n";
const char var7f1b38a8[] = "%s: %s\n";
//const char var7f1b38b0[] = "\n";

s32 menuhandlerDeclineMission(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();
		menuPopDialog();
	}

	return 0;
}

GLOBAL_ASM(
glabel menudialog0010cd0c
/*  f10cd0c:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f10cd10:	24010066 */ 	addiu	$at,$zero,0x66
/*  f10cd14:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10cd18:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f10cd1c:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f10cd20:	1481004c */ 	bne	$a0,$at,.L0f10ce54
/*  f10cd24:	00a03825 */ 	or	$a3,$a1,$zero
/*  f10cd28:	3c0f8007 */ 	lui	$t7,0x8007
/*  f10cd2c:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f10cd30:	3c02800a */ 	lui	$v0,0x800a
/*  f10cd34:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f10cd38:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10cd3c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f10cd40:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f10cd44:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f10cd48:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10cd4c:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f10cd50:	00581021 */ 	addu	$v0,$v0,$t8
/*  f10cd54:	8c42e4f8 */ 	lw	$v0,-0x1b08($v0)
/*  f10cd58:	5040003f */ 	beqzl	$v0,.L0f10ce58
/*  f10cd5c:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f10cd60:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f10cd64:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f10cd68:	50a40007 */ 	beql	$a1,$a0,.L0f10cd88
/*  f10cd6c:	8f240000 */ 	lw	$a0,0x0($t9)
/*  f10cd70:	8ca30014 */ 	lw	$v1,0x14($a1)
/*  f10cd74:	50600038 */ 	beqzl	$v1,.L0f10ce58
/*  f10cd78:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f10cd7c:	54640036 */ 	bnel	$v1,$a0,.L0f10ce58
/*  f10cd80:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f10cd84:	8f240000 */ 	lw	$a0,0x0($t9)
.L0f10cd88:
/*  f10cd88:	00002825 */ 	or	$a1,$zero,$zero
/*  f10cd8c:	90880003 */ 	lbu	$t0,0x3($a0)
/*  f10cd90:	5100000b */ 	beqzl	$t0,.L0f10cdc0
/*  f10cd94:	8089000a */ 	lb	$t1,0xa($a0)
/*  f10cd98:	afa4003c */ 	sw	$a0,0x3c($sp)
/*  f10cd9c:	afa00038 */ 	sw	$zero,0x38($sp)
/*  f10cda0:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10cda4:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f10cda8:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10cdac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10cdb0:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f10cdb4:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f10cdb8:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f10cdbc:	8089000a */ 	lb	$t1,0xa($a0)
.L0f10cdc0:
/*  f10cdc0:	a0800003 */ 	sb	$zero,0x3($a0)
/*  f10cdc4:	3c0b8007 */ 	lui	$t3,0x8007
/*  f10cdc8:	11200002 */ 	beqz	$t1,.L0f10cdd4
/*  f10cdcc:	27a60028 */ 	addiu	$a2,$sp,0x28
/*  f10cdd0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f10cdd4:
/*  f10cdd4:	908a0002 */ 	lbu	$t2,0x2($a0)
/*  f10cdd8:	a080000a */ 	sb	$zero,0xa($a0)
/*  f10cddc:	11400016 */ 	beqz	$t2,.L0f10ce38
/*  f10cde0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10cde4:	8d6b1448 */ 	lw	$t3,0x1448($t3)
/*  f10cde8:	3c02800a */ 	lui	$v0,0x800a
/*  f10cdec:	000b60c0 */ 	sll	$t4,$t3,0x3
/*  f10cdf0:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f10cdf4:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f10cdf8:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f10cdfc:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f10ce00:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f10ce04:	000c6100 */ 	sll	$t4,$t4,0x4
/*  f10ce08:	004c1021 */ 	addu	$v0,$v0,$t4
/*  f10ce0c:	8c42e4f8 */ 	lw	$v0,-0x1b08($v0)
/*  f10ce10:	10400009 */ 	beqz	$v0,.L0f10ce38
/*  f10ce14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ce18:	8ce30014 */ 	lw	$v1,0x14($a3)
/*  f10ce1c:	10600006 */ 	beqz	$v1,.L0f10ce38
/*  f10ce20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ce24:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f10ce28:	146d0003 */ 	bne	$v1,$t5,.L0f10ce38
/*  f10ce2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ce30:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f10ce34:	a0800002 */ 	sb	$zero,0x2($a0)
.L0f10ce38:
/*  f10ce38:	10a00006 */ 	beqz	$a1,.L0f10ce54
/*  f10ce3c:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f10ce40:	8ce50008 */ 	lw	$a1,0x8($a3)
/*  f10ce44:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f10ce48:	0fc40cfe */ 	jal	menuhandlerAcceptMission
/*  f10ce4c:	24a50014 */ 	addiu	$a1,$a1,0x14
/*  f10ce50:	8fa70044 */ 	lw	$a3,0x44($sp)
.L0f10ce54:
/*  f10ce54:	8fa40040 */ 	lw	$a0,0x40($sp)
.L0f10ce58:
/*  f10ce58:	00e02825 */ 	or	$a1,$a3,$zero
/*  f10ce5c:	0fc40d82 */ 	jal	menudialog00103608
/*  f10ce60:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f10ce64:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10ce68:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f10ce6c:	03e00008 */ 	jr	$ra
/*  f10ce70:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10ce74
/*  f10ce74:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10ce78:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10ce7c:	3c18800a */ 	lui	$t8,0x800a
/*  f10ce80:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10ce84:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10ce88:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10ce8c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10ce90:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10ce94:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10ce98:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10ce9c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10cea0:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f10cea4:	8f18e4f8 */ 	lw	$t8,-0x1b08($t8)
/*  f10cea8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10ceac:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f10ceb0:	10990005 */ 	beq	$a0,$t9,.L0f10cec8
/*  f10ceb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ceb8:	0fc5b9f1 */ 	jal	langGet
/*  f10cebc:	2404572c */ 	addiu	$a0,$zero,0x572c
/*  f10cec0:	10000017 */ 	beqz	$zero,.L0f10cf20
/*  f10cec4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10cec8:
/*  f10cec8:	0fc5b9f1 */ 	jal	langGet
/*  f10cecc:	24045728 */ 	addiu	$a0,$zero,0x5728
/*  f10ced0:	3c08800a */ 	lui	$t0,0x800a
/*  f10ced4:	9108dfea */ 	lbu	$t0,-0x2016($t0)
/*  f10ced8:	3c048007 */ 	lui	$a0,0x8007
/*  f10cedc:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f10cee0:	00084880 */ 	sll	$t1,$t0,0x2
/*  f10cee4:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10cee8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f10ceec:	00892021 */ 	addu	$a0,$a0,$t1
/*  f10cef0:	0fc5b9f1 */ 	jal	langGet
/*  f10cef4:	94841e76 */ 	lhu	$a0,0x1e76($a0)
/*  f10cef8:	3c048007 */ 	lui	$a0,0x8007
/*  f10cefc:	3c057f1b */ 	lui	$a1,%hi(var7f1b3860)
/*  f10cf00:	24a53860 */ 	addiu	$a1,$a1,%lo(var7f1b3860)
/*  f10cf04:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10cf08:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f10cf0c:	0c004dad */ 	jal	sprintf
/*  f10cf10:	00403825 */ 	or	$a3,$v0,$zero
/*  f10cf14:	3c028007 */ 	lui	$v0,0x8007
/*  f10cf18:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f10cf1c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10cf20:
/*  f10cf20:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10cf24:	03e00008 */ 	jr	$ra
/*  f10cf28:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10cf2c
/*  f10cf2c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10cf30:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10cf34:	3c18800a */ 	lui	$t8,0x800a
/*  f10cf38:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10cf3c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10cf40:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10cf44:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10cf48:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10cf4c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10cf50:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10cf54:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10cf58:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f10cf5c:	8f18e4f8 */ 	lw	$t8,-0x1b08($t8)
/*  f10cf60:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10cf64:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f10cf68:	10990005 */ 	beq	$a0,$t9,.L0f10cf80
/*  f10cf6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10cf70:	0fc5b9f1 */ 	jal	langGet
/*  f10cf74:	2404572c */ 	addiu	$a0,$zero,0x572c
/*  f10cf78:	10000017 */ 	beqz	$zero,.L0f10cfd8
/*  f10cf7c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10cf80:
/*  f10cf80:	0fc5b9f1 */ 	jal	langGet
/*  f10cf84:	24045729 */ 	addiu	$a0,$zero,0x5729
/*  f10cf88:	3c08800a */ 	lui	$t0,0x800a
/*  f10cf8c:	9108dfea */ 	lbu	$t0,-0x2016($t0)
/*  f10cf90:	3c048007 */ 	lui	$a0,0x8007
/*  f10cf94:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f10cf98:	00084880 */ 	sll	$t1,$t0,0x2
/*  f10cf9c:	01284823 */ 	subu	$t1,$t1,$t0
/*  f10cfa0:	00094880 */ 	sll	$t1,$t1,0x2
/*  f10cfa4:	00892021 */ 	addu	$a0,$a0,$t1
/*  f10cfa8:	0fc5b9f1 */ 	jal	langGet
/*  f10cfac:	94841e76 */ 	lhu	$a0,0x1e76($a0)
/*  f10cfb0:	3c048007 */ 	lui	$a0,0x8007
/*  f10cfb4:	3c057f1b */ 	lui	$a1,%hi(var7f1b3868)
/*  f10cfb8:	24a53868 */ 	addiu	$a1,$a1,%lo(var7f1b3868)
/*  f10cfbc:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10cfc0:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f10cfc4:	0c004dad */ 	jal	sprintf
/*  f10cfc8:	00403825 */ 	or	$a3,$v0,$zero
/*  f10cfcc:	3c028007 */ 	lui	$v0,0x8007
/*  f10cfd0:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f10cfd4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10cfd8:
/*  f10cfd8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10cfdc:	03e00008 */ 	jr	$ra
/*  f10cfe0:	00000000 */ 	sll	$zero,$zero,0x0
);

s32 menuhandlerReplayPreviousMission(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		g_MissionConfig.stageindex--;
		g_MissionConfig.stagenum = g_StageNames[g_MissionConfig.stageindex].stage_id;
	}

	return menuhandlerAcceptMission(operation, NULL, value);
}

GLOBAL_ASM(
glabel func0f10d044
/*  f10d044:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10d048:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d04c:	0fc2c1cf */ 	jal	func0f0b073c
/*  f10d050:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10d054:	3c048007 */ 	lui	$a0,0x8007
/*  f10d058:	3c057f1b */ 	lui	$a1,%hi(var7f1b3870)
/*  f10d05c:	24a53870 */ 	addiu	$a1,$a1,%lo(var7f1b3870)
/*  f10d060:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10d064:	0c004dad */ 	jal	sprintf
/*  f10d068:	00403025 */ 	or	$a2,$v0,$zero
/*  f10d06c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d070:	3c028007 */ 	lui	$v0,0x8007
/*  f10d074:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f10d078:	03e00008 */ 	jr	$ra
/*  f10d07c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f10d080
/*  f10d080:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10d084:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d088:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10d08c:	0fc2c14b */ 	jal	func0f0b052c
/*  f10d090:	00002025 */ 	or	$a0,$zero,$zero
/*  f10d094:	3c048007 */ 	lui	$a0,0x8007
/*  f10d098:	3c057f1b */ 	lui	$a1,%hi(var7f1b3874)
/*  f10d09c:	24a53874 */ 	addiu	$a1,$a1,%lo(var7f1b3874)
/*  f10d0a0:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10d0a4:	0c004dad */ 	jal	sprintf
/*  f10d0a8:	00403025 */ 	or	$a2,$v0,$zero
/*  f10d0ac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d0b0:	3c028007 */ 	lui	$v0,0x8007
/*  f10d0b4:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f10d0b8:	03e00008 */ 	jr	$ra
/*  f10d0bc:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f10d0c0
/*  f10d0c0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10d0c4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d0c8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10d0cc:	0fc2c14b */ 	jal	func0f0b052c
/*  f10d0d0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10d0d4:	3c048007 */ 	lui	$a0,0x8007
/*  f10d0d8:	3c057f1b */ 	lui	$a1,%hi(var7f1b3878)
/*  f10d0dc:	24a53878 */ 	addiu	$a1,$a1,%lo(var7f1b3878)
/*  f10d0e0:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10d0e4:	0c004dad */ 	jal	sprintf
/*  f10d0e8:	00403025 */ 	or	$a2,$v0,$zero
/*  f10d0ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d0f0:	3c028007 */ 	lui	$v0,0x8007
/*  f10d0f4:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f10d0f8:	03e00008 */ 	jr	$ra
/*  f10d0fc:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f10d100
/*  f10d100:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10d104:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d108:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10d10c:	0fc2c14b */ 	jal	func0f0b052c
/*  f10d110:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f10d114:	3c048007 */ 	lui	$a0,0x8007
/*  f10d118:	3c057f1b */ 	lui	$a1,%hi(var7f1b387c)
/*  f10d11c:	24a5387c */ 	addiu	$a1,$a1,%lo(var7f1b387c)
/*  f10d120:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10d124:	0c004dad */ 	jal	sprintf
/*  f10d128:	00403025 */ 	or	$a2,$v0,$zero
/*  f10d12c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d130:	3c028007 */ 	lui	$v0,0x8007
/*  f10d134:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f10d138:	03e00008 */ 	jr	$ra
/*  f10d13c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f10d140
/*  f10d140:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10d144:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d148:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10d14c:	0fc2c14b */ 	jal	func0f0b052c
/*  f10d150:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f10d154:	3c048007 */ 	lui	$a0,0x8007
/*  f10d158:	3c057f1b */ 	lui	$a1,%hi(var7f1b3880)
/*  f10d15c:	24a53880 */ 	addiu	$a1,$a1,%lo(var7f1b3880)
/*  f10d160:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10d164:	0c004dad */ 	jal	sprintf
/*  f10d168:	00403025 */ 	or	$a2,$v0,$zero
/*  f10d16c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d170:	3c028007 */ 	lui	$v0,0x8007
/*  f10d174:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f10d178:	03e00008 */ 	jr	$ra
/*  f10d17c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f10d180
/*  f10d180:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10d184:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d188:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f10d18c:	0fc2c14b */ 	jal	func0f0b052c
/*  f10d190:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f10d194:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f10d198:	0fc2c14b */ 	jal	func0f0b052c
/*  f10d19c:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f10d1a0:	8fae0018 */ 	lw	$t6,0x18($sp)
/*  f10d1a4:	3c048007 */ 	lui	$a0,0x8007
/*  f10d1a8:	3c057f1b */ 	lui	$a1,%hi(var7f1b3884)
/*  f10d1ac:	24a53884 */ 	addiu	$a1,$a1,%lo(var7f1b3884)
/*  f10d1b0:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10d1b4:	0c004dad */ 	jal	sprintf
/*  f10d1b8:	004e3021 */ 	addu	$a2,$v0,$t6
/*  f10d1bc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d1c0:	3c028007 */ 	lui	$v0,0x8007
/*  f10d1c4:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f10d1c8:	03e00008 */ 	jr	$ra
/*  f10d1cc:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f10d1d0
/*  f10d1d0:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f10d1d4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f10d1d8:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f10d1dc:	0fc2c14b */ 	jal	func0f0b052c
/*  f10d1e0:	00002025 */ 	or	$a0,$zero,$zero
/*  f10d1e4:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f10d1e8:	0fc2c14b */ 	jal	func0f0b052c
/*  f10d1ec:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10d1f0:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f10d1f4:	0fc2c14b */ 	jal	func0f0b052c
/*  f10d1f8:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f10d1fc:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f10d200:	0fc2c14b */ 	jal	func0f0b052c
/*  f10d204:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f10d208:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f10d20c:	0fc2c14b */ 	jal	func0f0b052c
/*  f10d210:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f10d214:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f10d218:	0fc2c14b */ 	jal	func0f0b052c
/*  f10d21c:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f10d220:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f10d224:	0fc2c14b */ 	jal	func0f0b052c
/*  f10d228:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f10d22c:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f10d230:	3c057f1b */ 	lui	$a1,%hi(var7f1b3888)
/*  f10d234:	24a53888 */ 	addiu	$a1,$a1,%lo(var7f1b3888)
/*  f10d238:	18600015 */ 	blez	$v1,.L0f10d290
/*  f10d23c:	3c048007 */ 	lui	$a0,0x8007
/*  f10d240:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f10d244:	8faf002c */ 	lw	$t7,0x2c($sp)
/*  f10d248:	8fb90028 */ 	lw	$t9,0x28($sp)
/*  f10d24c:	8fa90024 */ 	lw	$t1,0x24($sp)
/*  f10d250:	8fab0020 */ 	lw	$t3,0x20($sp)
/*  f10d254:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f10d258:	03194021 */ 	addu	$t0,$t8,$t9
/*  f10d25c:	01095021 */ 	addu	$t2,$t0,$t1
/*  f10d260:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f10d264:	01826821 */ 	addu	$t5,$t4,$v0
/*  f10d268:	448d2000 */ 	mtc1	$t5,$f4
/*  f10d26c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f10d270:	44811000 */ 	mtc1	$at,$f2
/*  f10d274:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f10d278:	44835000 */ 	mtc1	$v1,$f10
/*  f10d27c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d280:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f10d284:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f10d288:	10000005 */ 	beqz	$zero,.L0f10d2a0
/*  f10d28c:	46104003 */ 	div.s	$f0,$f8,$f16
.L0f10d290:
/*  f10d290:	3c0142c8 */ 	lui	$at,0x42c8
/*  f10d294:	44811000 */ 	mtc1	$at,$f2
/*  f10d298:	44800000 */ 	mtc1	$zero,$f0
/*  f10d29c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10d2a0:
/*  f10d2a0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f10d2a4:	3c067f1b */ 	lui	$a2,%hi(var7f1b3894)
/*  f10d2a8:	3c077f1b */ 	lui	$a3,%hi(var7f1b3898)
/*  f10d2ac:	24e73898 */ 	addiu	$a3,$a3,%lo(var7f1b3898)
/*  f10d2b0:	45000002 */ 	bc1f	.L0f10d2bc
/*  f10d2b4:	24c63894 */ 	addiu	$a2,$a2,%lo(var7f1b3894)
/*  f10d2b8:	46001006 */ 	mov.s	$f0,$f2
.L0f10d2bc:
/*  f10d2bc:	460004a1 */ 	cvt.d.s	$f18,$f0
/*  f10d2c0:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10d2c4:	0c004dad */ 	jal	sprintf
/*  f10d2c8:	f7b20010 */ 	sdc1	$f18,0x10($sp)
/*  f10d2cc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f10d2d0:	3c028007 */ 	lui	$v0,0x8007
/*  f10d2d4:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f10d2d8:	03e00008 */ 	jr	$ra
/*  f10d2dc:	27bd0038 */ 	addiu	$sp,$sp,0x38
);

GLOBAL_ASM(
glabel func0f10d2e0
/*  f10d2e0:	3c0e800a */ 	lui	$t6,0x800a
/*  f10d2e4:	8dce21d0 */ 	lw	$t6,0x21d0($t6)
/*  f10d2e8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10d2ec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d2f0:	15c00007 */ 	bnez	$t6,.L0f10d310
/*  f10d2f4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10d2f8:	3c0f800a */ 	lui	$t7,0x800a
/*  f10d2fc:	8def21d4 */ 	lw	$t7,0x21d4($t7)
/*  f10d300:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10d304:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f10d308:	51e00006 */ 	beqzl	$t7,.L0f10d324
/*  f10d30c:	8c780298 */ 	lw	$t8,0x298($v1)
.L0f10d310:
/*  f10d310:	0fc5b9f1 */ 	jal	langGet
/*  f10d314:	24045487 */ 	addiu	$a0,$zero,0x5487
/*  f10d318:	1000006b */ 	beqz	$zero,.L0f10d4c8
/*  f10d31c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d320:	8c780298 */ 	lw	$t8,0x298($v1)
.L0f10d324:
/*  f10d324:	07020018 */ 	bltzl	$t8,.L0f10d388
/*  f10d328:	8c6b029c */ 	lw	$t3,0x29c($v1)
/*  f10d32c:	8c6202a0 */ 	lw	$v0,0x2a0($v1)
/*  f10d330:	8c59048c */ 	lw	$t9,0x48c($v0)
/*  f10d334:	17200005 */ 	bnez	$t9,.L0f10d34c
/*  f10d338:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d33c:	8c6402a4 */ 	lw	$a0,0x2a4($v1)
/*  f10d340:	8c88048c */ 	lw	$t0,0x48c($a0)
/*  f10d344:	51000006 */ 	beqzl	$t0,.L0f10d360
/*  f10d348:	8c4900d8 */ 	lw	$t1,0xd8($v0)
.L0f10d34c:
/*  f10d34c:	0fc5b9f1 */ 	jal	langGet
/*  f10d350:	24045727 */ 	addiu	$a0,$zero,0x5727
/*  f10d354:	1000005c */ 	beqz	$zero,.L0f10d4c8
/*  f10d358:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d35c:	8c4900d8 */ 	lw	$t1,0xd8($v0)
.L0f10d360:
/*  f10d360:	11200046 */ 	beqz	$t1,.L0f10d47c
/*  f10d364:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d368:	8c8a00d8 */ 	lw	$t2,0xd8($a0)
/*  f10d36c:	11400043 */ 	beqz	$t2,.L0f10d47c
/*  f10d370:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d374:	0fc5b9f1 */ 	jal	langGet
/*  f10d378:	24045725 */ 	addiu	$a0,$zero,0x5725
/*  f10d37c:	10000052 */ 	beqz	$zero,.L0f10d4c8
/*  f10d380:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d384:	8c6b029c */ 	lw	$t3,0x29c($v1)
.L0f10d388:
/*  f10d388:	0562002e */ 	bltzl	$t3,.L0f10d444
/*  f10d38c:	8c6202a0 */ 	lw	$v0,0x2a0($v1)
/*  f10d390:	8c6202a0 */ 	lw	$v0,0x2a0($v1)
/*  f10d394:	8c6c0284 */ 	lw	$t4,0x284($v1)
/*  f10d398:	544c0018 */ 	bnel	$v0,$t4,.L0f10d3fc
/*  f10d39c:	8c7902a8 */ 	lw	$t9,0x2a8($v1)
/*  f10d3a0:	8c4d048c */ 	lw	$t5,0x48c($v0)
/*  f10d3a4:	51a00006 */ 	beqzl	$t5,.L0f10d3c0
/*  f10d3a8:	8c6e02a8 */ 	lw	$t6,0x2a8($v1)
/*  f10d3ac:	0fc5b9f1 */ 	jal	langGet
/*  f10d3b0:	24045727 */ 	addiu	$a0,$zero,0x5727
/*  f10d3b4:	10000044 */ 	beqz	$zero,.L0f10d4c8
/*  f10d3b8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d3bc:	8c6e02a8 */ 	lw	$t6,0x2a8($v1)
.L0f10d3c0:
/*  f10d3c0:	8dcf048c */ 	lw	$t7,0x48c($t6)
/*  f10d3c4:	51e00006 */ 	beqzl	$t7,.L0f10d3e0
/*  f10d3c8:	8c5800d8 */ 	lw	$t8,0xd8($v0)
/*  f10d3cc:	0fc5b9f1 */ 	jal	langGet
/*  f10d3d0:	24045727 */ 	addiu	$a0,$zero,0x5727
/*  f10d3d4:	1000003c */ 	beqz	$zero,.L0f10d4c8
/*  f10d3d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d3dc:	8c5800d8 */ 	lw	$t8,0xd8($v0)
.L0f10d3e0:
/*  f10d3e0:	13000026 */ 	beqz	$t8,.L0f10d47c
/*  f10d3e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d3e8:	0fc5b9f1 */ 	jal	langGet
/*  f10d3ec:	24045725 */ 	addiu	$a0,$zero,0x5725
/*  f10d3f0:	10000035 */ 	beqz	$zero,.L0f10d4c8
/*  f10d3f4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d3f8:	8c7902a8 */ 	lw	$t9,0x2a8($v1)
.L0f10d3fc:
/*  f10d3fc:	8f28048c */ 	lw	$t0,0x48c($t9)
/*  f10d400:	51000006 */ 	beqzl	$t0,.L0f10d41c
/*  f10d404:	8c49048c */ 	lw	$t1,0x48c($v0)
/*  f10d408:	0fc5b9f1 */ 	jal	langGet
/*  f10d40c:	24045727 */ 	addiu	$a0,$zero,0x5727
/*  f10d410:	1000002d */ 	beqz	$zero,.L0f10d4c8
/*  f10d414:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d418:	8c49048c */ 	lw	$t1,0x48c($v0)
.L0f10d41c:
/*  f10d41c:	15200017 */ 	bnez	$t1,.L0f10d47c
/*  f10d420:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d424:	8c4a00d8 */ 	lw	$t2,0xd8($v0)
/*  f10d428:	15400014 */ 	bnez	$t2,.L0f10d47c
/*  f10d42c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d430:	0fc5b9f1 */ 	jal	langGet
/*  f10d434:	24045725 */ 	addiu	$a0,$zero,0x5725
/*  f10d438:	10000023 */ 	beqz	$zero,.L0f10d4c8
/*  f10d43c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d440:	8c6202a0 */ 	lw	$v0,0x2a0($v1)
.L0f10d444:
/*  f10d444:	8c4b048c */ 	lw	$t3,0x48c($v0)
/*  f10d448:	51600006 */ 	beqzl	$t3,.L0f10d464
/*  f10d44c:	8c4c00d8 */ 	lw	$t4,0xd8($v0)
/*  f10d450:	0fc5b9f1 */ 	jal	langGet
/*  f10d454:	24045727 */ 	addiu	$a0,$zero,0x5727
/*  f10d458:	1000001b */ 	beqz	$zero,.L0f10d4c8
/*  f10d45c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d460:	8c4c00d8 */ 	lw	$t4,0xd8($v0)
.L0f10d464:
/*  f10d464:	11800005 */ 	beqz	$t4,.L0f10d47c
/*  f10d468:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d46c:	0fc5b9f1 */ 	jal	langGet
/*  f10d470:	24045725 */ 	addiu	$a0,$zero,0x5725
/*  f10d474:	10000014 */ 	beqz	$zero,.L0f10d4c8
/*  f10d478:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10d47c:
/*  f10d47c:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f10d480:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d484:	14400005 */ 	bnez	$v0,.L0f10d49c
/*  f10d488:	3c0d8008 */ 	lui	$t5,0x8008
/*  f10d48c:	0fc5b9f1 */ 	jal	langGet
/*  f10d490:	24045725 */ 	addiu	$a0,$zero,0x5725
/*  f10d494:	1000000c */ 	beqz	$zero,.L0f10d4c8
/*  f10d498:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10d49c:
/*  f10d49c:	8dadfc00 */ 	lw	$t5,-0x400($t5)
/*  f10d4a0:	24010019 */ 	addiu	$at,$zero,0x19
/*  f10d4a4:	15a10005 */ 	bne	$t5,$at,.L0f10d4bc
/*  f10d4a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d4ac:	0fc5b9f1 */ 	jal	langGet
/*  f10d4b0:	2404543e */ 	addiu	$a0,$zero,0x543e
/*  f10d4b4:	10000004 */ 	beqz	$zero,.L0f10d4c8
/*  f10d4b8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10d4bc:
/*  f10d4bc:	0fc5b9f1 */ 	jal	langGet
/*  f10d4c0:	24045726 */ 	addiu	$a0,$zero,0x5726
/*  f10d4c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10d4c8:
/*  f10d4c8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10d4cc:	03e00008 */ 	jr	$ra
/*  f10d4d0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10d4d4
/*  f10d4d4:	3c0e800a */ 	lui	$t6,0x800a
/*  f10d4d8:	8dce21d0 */ 	lw	$t6,0x21d0($t6)
/*  f10d4dc:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10d4e0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d4e4:	15c00006 */ 	bnez	$t6,.L0f10d500
/*  f10d4e8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10d4ec:	3c0f800a */ 	lui	$t7,0x800a
/*  f10d4f0:	8def21d4 */ 	lw	$t7,0x21d4($t7)
/*  f10d4f4:	3c02800a */ 	lui	$v0,0x800a
/*  f10d4f8:	11e00005 */ 	beqz	$t7,.L0f10d510
/*  f10d4fc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10d500:
/*  f10d500:	0fc5b9f1 */ 	jal	langGet
/*  f10d504:	24045486 */ 	addiu	$a0,$zero,0x5486
/*  f10d508:	1000001c */ 	beqz	$zero,.L0f10d57c
/*  f10d50c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10d510:
/*  f10d510:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f10d514:	8c58048c */ 	lw	$t8,0x48c($v0)
/*  f10d518:	53000006 */ 	beqzl	$t8,.L0f10d534
/*  f10d51c:	8c5900d8 */ 	lw	$t9,0xd8($v0)
/*  f10d520:	0fc5b9f1 */ 	jal	langGet
/*  f10d524:	24045724 */ 	addiu	$a0,$zero,0x5724
/*  f10d528:	10000014 */ 	beqz	$zero,.L0f10d57c
/*  f10d52c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d530:	8c5900d8 */ 	lw	$t9,0xd8($v0)
.L0f10d534:
/*  f10d534:	3c088008 */ 	lui	$t0,0x8008
/*  f10d538:	13200005 */ 	beqz	$t9,.L0f10d550
/*  f10d53c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d540:	0fc5b9f1 */ 	jal	langGet
/*  f10d544:	24045722 */ 	addiu	$a0,$zero,0x5722
/*  f10d548:	1000000c */ 	beqz	$zero,.L0f10d57c
/*  f10d54c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10d550:
/*  f10d550:	8d08fc00 */ 	lw	$t0,-0x400($t0)
/*  f10d554:	24010019 */ 	addiu	$at,$zero,0x19
/*  f10d558:	15010005 */ 	bne	$t0,$at,.L0f10d570
/*  f10d55c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d560:	0fc5b9f1 */ 	jal	langGet
/*  f10d564:	2404543f */ 	addiu	$a0,$zero,0x543f
/*  f10d568:	10000004 */ 	beqz	$zero,.L0f10d57c
/*  f10d56c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10d570:
/*  f10d570:	0fc5b9f1 */ 	jal	langGet
/*  f10d574:	24045723 */ 	addiu	$a0,$zero,0x5723
/*  f10d578:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10d57c:
/*  f10d57c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10d580:	03e00008 */ 	jr	$ra
/*  f10d584:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10d588
/*  f10d588:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10d58c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10d590:	3c18800a */ 	lui	$t8,0x800a
/*  f10d594:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10d598:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10d59c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10d5a0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10d5a4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10d5a8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10d5ac:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10d5b0:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10d5b4:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f10d5b8:	8f18ee2c */ 	lw	$t8,-0x11d4($t8)
/*  f10d5bc:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f10d5c0:	3c048007 */ 	lui	$a0,0x8007
/*  f10d5c4:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f10d5c8:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10d5cc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10d5d0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d5d4:	00992021 */ 	addu	$a0,$a0,$t9
/*  f10d5d8:	0fc5b9f1 */ 	jal	langGet
/*  f10d5dc:	94841e76 */ 	lhu	$a0,0x1e76($a0)
/*  f10d5e0:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f10d5e4:	0fc5b9f1 */ 	jal	langGet
/*  f10d5e8:	24045714 */ 	addiu	$a0,$zero,0x5714
/*  f10d5ec:	3c048007 */ 	lui	$a0,0x8007
/*  f10d5f0:	3c057f1b */ 	lui	$a1,%hi(var7f1b389c)
/*  f10d5f4:	24a5389c */ 	addiu	$a1,$a1,%lo(var7f1b389c)
/*  f10d5f8:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10d5fc:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f10d600:	0c004dad */ 	jal	sprintf
/*  f10d604:	00403825 */ 	or	$a3,$v0,$zero
/*  f10d608:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d60c:	3c028007 */ 	lui	$v0,0x8007
/*  f10d610:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f10d614:	03e00008 */ 	jr	$ra
/*  f10d618:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f10d61c
/*  f10d61c:	3c0e800a */ 	lui	$t6,0x800a
/*  f10d620:	91cedfea */ 	lbu	$t6,-0x2016($t6)
/*  f10d624:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10d628:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10d62c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f10d630:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10d634:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10d638:	3c048007 */ 	lui	$a0,0x8007
/*  f10d63c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d640:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f10d644:	0fc5b9f1 */ 	jal	langGet
/*  f10d648:	94841e76 */ 	lhu	$a0,0x1e76($a0)
/*  f10d64c:	3c048007 */ 	lui	$a0,0x8007
/*  f10d650:	3c057f1b */ 	lui	$a1,%hi(var7f1b38a4)
/*  f10d654:	24a538a4 */ 	addiu	$a1,$a1,%lo(var7f1b38a4)
/*  f10d658:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10d65c:	0c004dad */ 	jal	sprintf
/*  f10d660:	00403025 */ 	or	$a2,$v0,$zero
/*  f10d664:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d668:	3c028007 */ 	lui	$v0,0x8007
/*  f10d66c:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f10d670:	03e00008 */ 	jr	$ra
/*  f10d674:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

GLOBAL_ASM(
glabel func0f10d678
/*  f10d678:	3c0e800a */ 	lui	$t6,0x800a
/*  f10d67c:	91cedfea */ 	lbu	$t6,-0x2016($t6)
/*  f10d680:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10d684:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f10d688:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f10d68c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10d690:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10d694:	3c048007 */ 	lui	$a0,0x8007
/*  f10d698:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d69c:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f10d6a0:	0fc5b9f1 */ 	jal	langGet
/*  f10d6a4:	94841e76 */ 	lhu	$a0,0x1e76($a0)
/*  f10d6a8:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f10d6ac:	0fc5b9f1 */ 	jal	langGet
/*  f10d6b0:	24045715 */ 	addiu	$a0,$zero,0x5715
/*  f10d6b4:	3c048007 */ 	lui	$a0,0x8007
/*  f10d6b8:	3c057f1b */ 	lui	$a1,%hi(var7f1b38a8)
/*  f10d6bc:	24a538a8 */ 	addiu	$a1,$a1,%lo(var7f1b38a8)
/*  f10d6c0:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10d6c4:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f10d6c8:	0c004dad */ 	jal	sprintf
/*  f10d6cc:	00403825 */ 	or	$a3,$v0,$zero
/*  f10d6d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d6d4:	3c028007 */ 	lui	$v0,0x8007
/*  f10d6d8:	8c421440 */ 	lw	$v0,0x1440($v0)
/*  f10d6dc:	03e00008 */ 	jr	$ra
/*  f10d6e0:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

char *menutextMissionTime(s32 arg0)
{
	formatTime(g_StringPointer, getMissionTime(), 3);
	strcat(g_StringPointer, "\n");

	return g_StringPointer;
}

GLOBAL_ASM(
glabel func0f10d730
/*  f10d730:	3c03800a */ 	lui	$v1,%hi(g_MissionConfig)
/*  f10d734:	2463dfe8 */ 	addiu	$v1,$v1,%lo(g_MissionConfig)
/*  f10d738:	906e0002 */ 	lbu	$t6,0x2($v1)
/*  f10d73c:	3c088007 */ 	lui	$t0,0x8007
/*  f10d740:	3c028007 */ 	lui	$v0,%hi(menudialog_promptnextmission)
/*  f10d744:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f10d748:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f10d74c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f10d750:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10d754:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10d758:	a06f0002 */ 	sb	$t7,0x2($v1)
/*  f10d75c:	01194021 */ 	addu	$t0,$t0,$t9
/*  f10d760:	8d081e6c */ 	lw	$t0,0x1e6c($t0)
/*  f10d764:	24425630 */ 	addiu	$v0,$v0,%lo(menudialog_promptnextmission)
/*  f10d768:	03e00008 */ 	jr	$ra
/*  f10d76c:	a0680001 */ 	sb	$t0,0x1($v1)
);

GLOBAL_ASM(
glabel func0f10d770
/*  f10d770:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10d774:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f10d778:	0fc2777f */ 	jal	func0f09ddfc
/*  f10d77c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f10d780:	0fc393f8 */ 	jal	func0f0e4fe0
/*  f10d784:	00408025 */ 	or	$s0,$v0,$zero
/*  f10d788:	3c04800a */ 	lui	$a0,0x800a
/*  f10d78c:	2484e840 */ 	addiu	$a0,$a0,-6080
/*  f10d790:	02022823 */ 	subu	$a1,$s0,$v0
/*  f10d794:	0fc3e2ed */ 	jal	func0f0f8bb4
/*  f10d798:	00003025 */ 	or	$a2,$zero,$zero
/*  f10d79c:	0fc2777b */ 	jal	func0f09ddec
/*  f10d7a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d7a4:	0fc393f8 */ 	jal	func0f0e4fe0
/*  f10d7a8:	00408025 */ 	or	$s0,$v0,$zero
/*  f10d7ac:	00507021 */ 	addu	$t6,$v0,$s0
/*  f10d7b0:	3c01800a */ 	lui	$at,0x800a
/*  f10d7b4:	0fc2777f */ 	jal	func0f09ddfc
/*  f10d7b8:	ac2ee844 */ 	sw	$t6,-0x17bc($at)
/*  f10d7bc:	0fc393f8 */ 	jal	func0f0e4fe0
/*  f10d7c0:	00408025 */ 	or	$s0,$v0,$zero
/*  f10d7c4:	3c04800a */ 	lui	$a0,%hi(var8009f6b0)
/*  f10d7c8:	2484f6b0 */ 	addiu	$a0,$a0,%lo(var8009f6b0)
/*  f10d7cc:	02022823 */ 	subu	$a1,$s0,$v0
/*  f10d7d0:	0fc3e2ed */ 	jal	func0f0f8bb4
/*  f10d7d4:	00003025 */ 	or	$a2,$zero,$zero
/*  f10d7d8:	0fc2777b */ 	jal	func0f09ddec
/*  f10d7dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d7e0:	0fc393f8 */ 	jal	func0f0e4fe0
/*  f10d7e4:	00408025 */ 	or	$s0,$v0,$zero
/*  f10d7e8:	00507821 */ 	addu	$t7,$v0,$s0
/*  f10d7ec:	3c01800a */ 	lui	$at,0x800a
/*  f10d7f0:	0fc2777f */ 	jal	func0f09ddfc
/*  f10d7f4:	ac2ff6b4 */ 	sw	$t7,-0x94c($at)
/*  f10d7f8:	0fc393f8 */ 	jal	func0f0e4fe0
/*  f10d7fc:	00408025 */ 	or	$s0,$v0,$zero
/*  f10d800:	3c04800a */ 	lui	$a0,%hi(var800a0520)
/*  f10d804:	24840520 */ 	addiu	$a0,$a0,%lo(var800a0520)
/*  f10d808:	02022823 */ 	subu	$a1,$s0,$v0
/*  f10d80c:	0fc3e2ed */ 	jal	func0f0f8bb4
/*  f10d810:	00003025 */ 	or	$a2,$zero,$zero
/*  f10d814:	0fc2777b */ 	jal	func0f09ddec
/*  f10d818:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d81c:	0fc393f8 */ 	jal	func0f0e4fe0
/*  f10d820:	00408025 */ 	or	$s0,$v0,$zero
/*  f10d824:	0050c021 */ 	addu	$t8,$v0,$s0
/*  f10d828:	3c01800a */ 	lui	$at,0x800a
/*  f10d82c:	0fc2777f */ 	jal	func0f09ddfc
/*  f10d830:	ac380524 */ 	sw	$t8,0x524($at)
/*  f10d834:	0fc393f8 */ 	jal	func0f0e4fe0
/*  f10d838:	00408025 */ 	or	$s0,$v0,$zero
/*  f10d83c:	3c04800a */ 	lui	$a0,%hi(var800a1390)
/*  f10d840:	24841390 */ 	addiu	$a0,$a0,%lo(var800a1390)
/*  f10d844:	02022823 */ 	subu	$a1,$s0,$v0
/*  f10d848:	0fc3e2ed */ 	jal	func0f0f8bb4
/*  f10d84c:	00003025 */ 	or	$a2,$zero,$zero
/*  f10d850:	0fc2777b */ 	jal	func0f09ddec
/*  f10d854:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d858:	0fc393f8 */ 	jal	func0f0e4fe0
/*  f10d85c:	00408025 */ 	or	$s0,$v0,$zero
/*  f10d860:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f10d864:	0050c821 */ 	addu	$t9,$v0,$s0
/*  f10d868:	3c01800a */ 	lui	$at,0x800a
/*  f10d86c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f10d870:	ac391394 */ 	sw	$t9,0x1394($at)
/*  f10d874:	03e00008 */ 	jr	$ra
/*  f10d878:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

s32 menuhandlerReplayLastLevel(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		g_MissionConfig.stagenum = g_StageNames[g_MissionConfig.stageindex].stage_id;
		return menuhandlerAcceptMission(operation, NULL, value);
	}

	return 0;
}

/**
 * Displayed after Defense and Skedar Ruins completion screens.
 */
s32 menuhandlerContinueMission(u32 operation, struct menu_item *item, s32 *value)
{
	if (operation == MENUOP_SET) {
		func0f10d910(2);
	}

	return 0;
}

GLOBAL_ASM(
glabel func0f10d910
/*  f10d910:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10d914:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f10d918:	8c6e029c */ 	lw	$t6,0x29c($v1)
/*  f10d91c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10d920:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10d924:	05c00005 */ 	bltz	$t6,.L0f10d93c
/*  f10d928:	00803825 */ 	or	$a3,$a0,$zero
/*  f10d92c:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10d930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d934:	100000f9 */ 	beqz	$zero,.L0f10dd1c
/*  f10d938:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10d93c:
/*  f10d93c:	8c6f0298 */ 	lw	$t7,0x298($v1)
/*  f10d940:	05e20025 */ 	bltzl	$t7,.L0f10d9d8
/*  f10d944:	8c6204b4 */ 	lw	$v0,0x4b4($v1)
/*  f10d948:	8c78006c */ 	lw	$t8,0x6c($v1)
/*  f10d94c:	00003025 */ 	or	$a2,$zero,$zero
/*  f10d950:	00002025 */ 	or	$a0,$zero,$zero
/*  f10d954:	13000003 */ 	beqz	$t8,.L0f10d964
/*  f10d958:	00002825 */ 	or	$a1,$zero,$zero
/*  f10d95c:	10000001 */ 	beqz	$zero,.L0f10d964
/*  f10d960:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f10d964:
/*  f10d964:	8c790068 */ 	lw	$t9,0x68($v1)
/*  f10d968:	00001025 */ 	or	$v0,$zero,$zero
/*  f10d96c:	13200003 */ 	beqz	$t9,.L0f10d97c
/*  f10d970:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d974:	10000001 */ 	beqz	$zero,.L0f10d97c
/*  f10d978:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f10d97c:
/*  f10d97c:	8c680064 */ 	lw	$t0,0x64($v1)
/*  f10d980:	11000003 */ 	beqz	$t0,.L0f10d990
/*  f10d984:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d988:	10000001 */ 	beqz	$zero,.L0f10d990
/*  f10d98c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f10d990:
/*  f10d990:	8c690070 */ 	lw	$t1,0x70($v1)
/*  f10d994:	11200003 */ 	beqz	$t1,.L0f10d9a4
/*  f10d998:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d99c:	10000001 */ 	beqz	$zero,.L0f10d9a4
/*  f10d9a0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10d9a4:
/*  f10d9a4:	00455021 */ 	addu	$t2,$v0,$a1
/*  f10d9a8:	01445821 */ 	addu	$t3,$t2,$a0
/*  f10d9ac:	01666021 */ 	addu	$t4,$t3,$a2
/*  f10d9b0:	29810002 */ 	slti	$at,$t4,0x2
/*  f10d9b4:	54200008 */ 	bnezl	$at,.L0f10d9d8
/*  f10d9b8:	8c6204b4 */ 	lw	$v0,0x4b4($v1)
/*  f10d9bc:	54e00006 */ 	bnezl	$a3,.L0f10d9d8
/*  f10d9c0:	8c6204b4 */ 	lw	$v0,0x4b4($v1)
/*  f10d9c4:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10d9c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10d9cc:	100000d3 */ 	beqz	$zero,.L0f10dd1c
/*  f10d9d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10d9d4:	8c6204b4 */ 	lw	$v0,0x4b4($v1)
.L0f10d9d8:
/*  f10d9d8:	24040038 */ 	addiu	$a0,$zero,0x38
/*  f10d9dc:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f10d9e0:	50820003 */ 	beql	$a0,$v0,.L0f10d9f0
/*  f10d9e4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f10d9e8:	1441007f */ 	bne	$v0,$at,.L0f10dbe8
/*  f10d9ec:	24010002 */ 	addiu	$at,$zero,0x2
.L0f10d9f0:
/*  f10d9f0:	10e1000f */ 	beq	$a3,$at,.L0f10da30
/*  f10d9f4:	3c0d8007 */ 	lui	$t5,0x8007
/*  f10d9f8:	8dad1448 */ 	lw	$t5,0x1448($t5)
/*  f10d9fc:	3c0f800a */ 	lui	$t7,0x800a
/*  f10da00:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10da04:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f10da08:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f10da0c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f10da10:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f10da14:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f10da18:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f10da1c:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f10da20:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10da24:	8defee24 */ 	lw	$t7,-0x11dc($t7)
/*  f10da28:	11e00063 */ 	beqz	$t7,.L0f10dbb8
/*  f10da2c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10da30:
/*  f10da30:	1482004c */ 	bne	$a0,$v0,.L0f10db64
/*  f10da34:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f10da38:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig)
/*  f10da3c:	2442dfe8 */ 	addiu	$v0,$v0,%lo(g_MissionConfig)
/*  f10da40:	8c450000 */ 	lw	$a1,0x0($v0)
/*  f10da44:	90440002 */ 	lbu	$a0,0x2($v0)
/*  f10da48:	0005c642 */ 	srl	$t8,$a1,0x19
/*  f10da4c:	03002825 */ 	or	$a1,$t8,$zero
/*  f10da50:	0fc40e3b */ 	jal	isStageDifficultyUnlocked
/*  f10da54:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f10da58:	14400007 */ 	bnez	$v0,.L0f10da78
/*  f10da5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10da60:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10da64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10da68:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10da6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10da70:	100000aa */ 	beqz	$zero,.L0f10dd1c
/*  f10da74:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10da78:
/*  f10da78:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig)
/*  f10da7c:	2442dfe8 */ 	addiu	$v0,$v0,%lo(g_MissionConfig)
/*  f10da80:	90590002 */ 	lbu	$t9,0x2($v0)
/*  f10da84:	3c0b8007 */ 	lui	$t3,0x8007
/*  f10da88:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f10da8c:	310900ff */ 	andi	$t1,$t0,0xff
/*  f10da90:	00095080 */ 	sll	$t2,$t1,0x2
/*  f10da94:	01495023 */ 	subu	$t2,$t2,$t1
/*  f10da98:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f10da9c:	a0480002 */ 	sb	$t0,0x2($v0)
/*  f10daa0:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f10daa4:	8d6b1e6c */ 	lw	$t3,0x1e6c($t3)
/*  f10daa8:	a04b0001 */ 	sb	$t3,0x1($v0)
/*  f10daac:	0fc06c55 */ 	jal	func0f01b154
/*  f10dab0:	316400ff */ 	andi	$a0,$t3,0xff
/*  f10dab4:	3c0c800a */ 	lui	$t4,0x800a
/*  f10dab8:	818ddfeb */ 	lb	$t5,-0x2015($t4)
/*  f10dabc:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10dac0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f10dac4:	05a10014 */ 	bgez	$t5,.L0f10db18
/*  f10dac8:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f10dacc:	8c6e0474 */ 	lw	$t6,0x474($v1)
/*  f10dad0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f10dad4:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f10dad8:	15c00009 */ 	bnez	$t6,.L0f10db00
/*  f10dadc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10dae0:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f10dae4:	ac600294 */ 	sw	$zero,0x294($v1)
/*  f10dae8:	ac6f0298 */ 	sw	$t7,0x298($v1)
/*  f10daec:	ac62029c */ 	sw	$v0,0x29c($v1)
/*  f10daf0:	0fc068d5 */ 	jal	setNumPlayers
/*  f10daf4:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f10daf8:	1000000c */ 	beqz	$zero,.L0f10db2c
/*  f10dafc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10db00:
/*  f10db00:	ac600294 */ 	sw	$zero,0x294($v1)
/*  f10db04:	ac620298 */ 	sw	$v0,0x298($v1)
/*  f10db08:	0fc068d5 */ 	jal	setNumPlayers
/*  f10db0c:	ac62029c */ 	sw	$v0,0x29c($v1)
/*  f10db10:	10000006 */ 	beqz	$zero,.L0f10db2c
/*  f10db14:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10db18:
/*  f10db18:	ac600294 */ 	sw	$zero,0x294($v1)
/*  f10db1c:	ac620298 */ 	sw	$v0,0x298($v1)
/*  f10db20:	ac62029c */ 	sw	$v0,0x29c($v1)
/*  f10db24:	0fc068d5 */ 	jal	setNumPlayers
/*  f10db28:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f10db2c:
/*  f10db2c:	3c04800a */ 	lui	$a0,0x800a
/*  f10db30:	8c84dfe8 */ 	lw	$a0,-0x2018($a0)
/*  f10db34:	0004c642 */ 	srl	$t8,$a0,0x19
/*  f10db38:	0fc5b36a */ 	jal	setDifficulty
/*  f10db3c:	03002025 */ 	or	$a0,$t8,$zero
/*  f10db40:	0fc069f9 */ 	jal	func0f01a7e4
/*  f10db44:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f10db48:	3c04800a */ 	lui	$a0,0x800a
/*  f10db4c:	0c003a57 */ 	jal	func0000e95c
/*  f10db50:	9084dfe9 */ 	lbu	$a0,-0x2017($a0)
/*  f10db54:	0c0027b1 */ 	jal	func00009ec4
/*  f10db58:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10db5c:	1000006f */ 	beqz	$zero,.L0f10dd1c
/*  f10db60:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10db64:
/*  f10db64:	1441006c */ 	bne	$v0,$at,.L0f10dd18
/*  f10db68:	2419005c */ 	addiu	$t9,$zero,0x5c
/*  f10db6c:	3c02800a */ 	lui	$v0,%hi(g_MissionConfig)
/*  f10db70:	2442dfe8 */ 	addiu	$v0,$v0,%lo(g_MissionConfig)
/*  f10db74:	a0590001 */ 	sb	$t9,0x1($v0)
/*  f10db78:	0fc06c55 */ 	jal	func0f01b154
/*  f10db7c:	332400ff */ 	andi	$a0,$t9,0xff
/*  f10db80:	3c04800a */ 	lui	$a0,0x800a
/*  f10db84:	8c84dfe8 */ 	lw	$a0,-0x2018($a0)
/*  f10db88:	00044642 */ 	srl	$t0,$a0,0x19
/*  f10db8c:	0fc5b36a */ 	jal	setDifficulty
/*  f10db90:	01002025 */ 	or	$a0,$t0,$zero
/*  f10db94:	0fc069f9 */ 	jal	func0f01a7e4
/*  f10db98:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f10db9c:	3c04800a */ 	lui	$a0,0x800a
/*  f10dba0:	0c003a57 */ 	jal	func0000e95c
/*  f10dba4:	9084dfe9 */ 	lbu	$a0,-0x2017($a0)
/*  f10dba8:	0c0027b1 */ 	jal	func00009ec4
/*  f10dbac:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10dbb0:	1000005a */ 	beqz	$zero,.L0f10dd1c
/*  f10dbb4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dbb8:
/*  f10dbb8:	14e10007 */ 	bne	$a3,$at,.L0f10dbd8
/*  f10dbbc:	3c048007 */ 	lui	$a0,%hi(menudialog_1b7a4)
/*  f10dbc0:	3c048007 */ 	lui	$a0,%hi(menudialog_1b7a4)
/*  f10dbc4:	24845784 */ 	addiu	$a0,$a0,%lo(menudialog_1b7a4)
/*  f10dbc8:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10dbcc:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f10dbd0:	10000052 */ 	beqz	$zero,.L0f10dd1c
/*  f10dbd4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dbd8:
/*  f10dbd8:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10dbdc:	24845784 */ 	addiu	$a0,$a0,%lo(menudialog_1b7a4)
/*  f10dbe0:	1000004e */ 	beqz	$zero,.L0f10dd1c
/*  f10dbe4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dbe8:
/*  f10dbe8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f10dbec:	14e10004 */ 	bne	$a3,$at,.L0f10dc00
/*  f10dbf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dbf4:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10dbf8:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f10dbfc:	8fa70018 */ 	lw	$a3,0x18($sp)
.L0f10dc00:
/*  f10dc00:	3c05800a */ 	lui	$a1,0x800a
/*  f10dc04:	8ca5dfe8 */ 	lw	$a1,-0x2018($a1)
/*  f10dc08:	3c04800a */ 	lui	$a0,0x800a
/*  f10dc0c:	9084dfea */ 	lbu	$a0,-0x2016($a0)
/*  f10dc10:	00054e42 */ 	srl	$t1,$a1,0x19
/*  f10dc14:	01202825 */ 	or	$a1,$t1,$zero
/*  f10dc18:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f10dc1c:	0fc40e3b */ 	jal	isStageDifficultyUnlocked
/*  f10dc20:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f10dc24:	1440000e */ 	bnez	$v0,.L0f10dc60
/*  f10dc28:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f10dc2c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f10dc30:	14e10007 */ 	bne	$a3,$at,.L0f10dc50
/*  f10dc34:	3c048007 */ 	lui	$a0,%hi(menudialog_1b7a4)
/*  f10dc38:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10dc3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dc40:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10dc44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dc48:	10000034 */ 	beqz	$zero,.L0f10dd1c
/*  f10dc4c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dc50:
/*  f10dc50:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10dc54:	24845784 */ 	addiu	$a0,$a0,%lo(menudialog_1b7a4)
/*  f10dc58:	10000030 */ 	beqz	$zero,.L0f10dd1c
/*  f10dc5c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dc60:
/*  f10dc60:	3c04800a */ 	lui	$a0,0x800a
/*  f10dc64:	9084dfe9 */ 	lbu	$a0,-0x2017($a0)
/*  f10dc68:	0fc59585 */ 	jal	stageGetIndex
/*  f10dc6c:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f10dc70:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10dc74:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f10dc78:	04400009 */ 	bltz	$v0,.L0f10dca0
/*  f10dc7c:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f10dc80:	8c6a04b4 */ 	lw	$t2,0x4b4($v1)
/*  f10dc84:	24010026 */ 	addiu	$at,$zero,0x26
/*  f10dc88:	3c0b800a */ 	lui	$t3,0x800a
/*  f10dc8c:	51410005 */ 	beql	$t2,$at,.L0f10dca4
/*  f10dc90:	24010002 */ 	addiu	$at,$zero,0x2
/*  f10dc94:	916bdfea */ 	lbu	$t3,-0x2016($t3)
/*  f10dc98:	29610011 */ 	slti	$at,$t3,0x11
/*  f10dc9c:	1420000d */ 	bnez	$at,.L0f10dcd4
.L0f10dca0:
/*  f10dca0:	24010002 */ 	addiu	$at,$zero,0x2
.L0f10dca4:
/*  f10dca4:	14e10007 */ 	bne	$a3,$at,.L0f10dcc4
/*  f10dca8:	3c048007 */ 	lui	$a0,%hi(menudialog_1b7a4)
/*  f10dcac:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10dcb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dcb4:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10dcb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dcbc:	10000017 */ 	beqz	$zero,.L0f10dd1c
/*  f10dcc0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dcc4:
/*  f10dcc4:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10dcc8:	24845784 */ 	addiu	$a0,$a0,%lo(menudialog_1b7a4)
/*  f10dccc:	10000013 */ 	beqz	$zero,.L0f10dd1c
/*  f10dcd0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dcd4:
/*  f10dcd4:	0fc435dc */ 	jal	func0f10d770
/*  f10dcd8:	afa70018 */ 	sw	$a3,0x18($sp)
/*  f10dcdc:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f10dce0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10dce4:	14e10008 */ 	bne	$a3,$at,.L0f10dd08
/*  f10dce8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dcec:	0fc435cc */ 	jal	func0f10d730
/*  f10dcf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dcf4:	00402025 */ 	or	$a0,$v0,$zero
/*  f10dcf8:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10dcfc:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f10dd00:	10000006 */ 	beqz	$zero,.L0f10dd1c
/*  f10dd04:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dd08:
/*  f10dd08:	0fc435cc */ 	jal	func0f10d730
/*  f10dd0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dd10:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10dd14:	00402025 */ 	or	$a0,$v0,$zero
.L0f10dd18:
/*  f10dd18:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10dd1c:
/*  f10dd1c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10dd20:	03e00008 */ 	jr	$ra
/*  f10dd24:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog0010dd28
/*  f10dd28:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10dd2c:	24010064 */ 	addiu	$at,$zero,0x64
/*  f10dd30:	1481000d */ 	bne	$a0,$at,.L0f10dd68
/*  f10dd34:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10dd38:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10dd3c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10dd40:	3c01800a */ 	lui	$at,0x800a
/*  f10dd44:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10dd48:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10dd4c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10dd50:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10dd54:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10dd58:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10dd5c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10dd60:	002f0821 */ 	addu	$at,$at,$t7
/*  f10dd64:	ac20ee1c */ 	sw	$zero,-0x11e4($at)
.L0f10dd68:
/*  f10dd68:	24010066 */ 	addiu	$at,$zero,0x66
/*  f10dd6c:	14810035 */ 	bne	$a0,$at,.L0f10de44
/*  f10dd70:	3c188007 */ 	lui	$t8,0x8007
/*  f10dd74:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f10dd78:	3c08800a */ 	lui	$t0,%hi(var8009e000)
/*  f10dd7c:	2508e000 */ 	addiu	$t0,$t0,%lo(var8009e000)
/*  f10dd80:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f10dd84:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10dd88:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10dd8c:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f10dd90:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f10dd94:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10dd98:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f10dd9c:	03282021 */ 	addu	$a0,$t9,$t0
/*  f10dda0:	8c8204f8 */ 	lw	$v0,0x4f8($a0)
/*  f10dda4:	50400028 */ 	beqzl	$v0,.L0f10de48
/*  f10dda8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10ddac:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f10ddb0:	50a30007 */ 	beql	$a1,$v1,.L0f10ddd0
/*  f10ddb4:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f10ddb8:	8ca20014 */ 	lw	$v0,0x14($a1)
/*  f10ddbc:	50400022 */ 	beqzl	$v0,.L0f10de48
/*  f10ddc0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10ddc4:	54430020 */ 	bnel	$v0,$v1,.L0f10de48
/*  f10ddc8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10ddcc:	8cc30000 */ 	lw	$v1,0x0($a2)
.L0f10ddd0:
/*  f10ddd0:	240c0006 */ 	addiu	$t4,$zero,0x6
/*  f10ddd4:	3c0d800a */ 	lui	$t5,0x800a
/*  f10ddd8:	90690002 */ 	lbu	$t1,0x2($v1)
/*  f10dddc:	55200008 */ 	bnezl	$t1,.L0f10de00
/*  f10dde0:	ac8c0e1c */ 	sw	$t4,0xe1c($a0)
/*  f10dde4:	906a0003 */ 	lbu	$t2,0x3($v1)
/*  f10dde8:	55400005 */ 	bnezl	$t2,.L0f10de00
/*  f10ddec:	ac8c0e1c */ 	sw	$t4,0xe1c($a0)
/*  f10ddf0:	806b000a */ 	lb	$t3,0xa($v1)
/*  f10ddf4:	51600003 */ 	beqzl	$t3,.L0f10de04
/*  f10ddf8:	8c820e1c */ 	lw	$v0,0xe1c($a0)
/*  f10ddfc:	ac8c0e1c */ 	sw	$t4,0xe1c($a0)
.L0f10de00:
/*  f10de00:	8c820e1c */ 	lw	$v0,0xe1c($a0)
.L0f10de04:
/*  f10de04:	5040000d */ 	beqzl	$v0,.L0f10de3c
/*  f10de08:	a060000a */ 	sb	$zero,0xa($v1)
/*  f10de0c:	8daddfc0 */ 	lw	$t5,-0x2040($t5)
/*  f10de10:	244effff */ 	addiu	$t6,$v0,-1
/*  f10de14:	11a00003 */ 	beqz	$t5,.L0f10de24
/*  f10de18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10de1c:	ac8e0e1c */ 	sw	$t6,0xe1c($a0)
/*  f10de20:	01c01025 */ 	or	$v0,$t6,$zero
.L0f10de24:
/*  f10de24:	14400004 */ 	bnez	$v0,.L0f10de38
/*  f10de28:	00002025 */ 	or	$a0,$zero,$zero
/*  f10de2c:	0fc43644 */ 	jal	func0f10d910
/*  f10de30:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f10de34:	8fa3001c */ 	lw	$v1,0x1c($sp)
.L0f10de38:
/*  f10de38:	a060000a */ 	sb	$zero,0xa($v1)
.L0f10de3c:
/*  f10de3c:	a0600003 */ 	sb	$zero,0x3($v1)
/*  f10de40:	a0600002 */ 	sb	$zero,0x2($v1)
.L0f10de44:
/*  f10de44:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10de48:
/*  f10de48:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10de4c:	00001025 */ 	or	$v0,$zero,$zero
/*  f10de50:	03e00008 */ 	jr	$ra
/*  f10de54:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menudialog0010de58
/*  f10de58:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10de5c:	24010064 */ 	addiu	$at,$zero,0x64
/*  f10de60:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10de64:	1481000d */ 	bne	$a0,$at,.L0f10de9c
/*  f10de68:	00c03825 */ 	or	$a3,$a2,$zero
/*  f10de6c:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10de70:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10de74:	3c01800a */ 	lui	$at,0x800a
/*  f10de78:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10de7c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10de80:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10de84:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10de88:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10de8c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10de90:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10de94:	002f0821 */ 	addu	$at,$at,$t7
/*  f10de98:	ac20ee1c */ 	sw	$zero,-0x11e4($at)
.L0f10de9c:
/*  f10de9c:	24010066 */ 	addiu	$at,$zero,0x66
/*  f10dea0:	1481006b */ 	bne	$a0,$at,.L0f10e050
/*  f10dea4:	3c188007 */ 	lui	$t8,0x8007
/*  f10dea8:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f10deac:	3c08800a */ 	lui	$t0,%hi(var8009e000)
/*  f10deb0:	2508e000 */ 	addiu	$t0,$t0,%lo(var8009e000)
/*  f10deb4:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f10deb8:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10debc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10dec0:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f10dec4:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f10dec8:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10decc:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f10ded0:	03281821 */ 	addu	$v1,$t9,$t0
/*  f10ded4:	8c6204f8 */ 	lw	$v0,0x4f8($v1)
/*  f10ded8:	5040005e */ 	beqzl	$v0,.L0f10e054
/*  f10dedc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10dee0:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f10dee4:	50a40007 */ 	beql	$a1,$a0,.L0f10df04
/*  f10dee8:	8ce60000 */ 	lw	$a2,0x0($a3)
/*  f10deec:	8ca20014 */ 	lw	$v0,0x14($a1)
/*  f10def0:	50400058 */ 	beqzl	$v0,.L0f10e054
/*  f10def4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10def8:	54440056 */ 	bnel	$v0,$a0,.L0f10e054
/*  f10defc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10df00:	8ce60000 */ 	lw	$a2,0x0($a3)
.L0f10df04:
/*  f10df04:	240c0006 */ 	addiu	$t4,$zero,0x6
/*  f10df08:	3c0d800a */ 	lui	$t5,0x800a
/*  f10df0c:	90c90002 */ 	lbu	$t1,0x2($a2)
/*  f10df10:	55200008 */ 	bnezl	$t1,.L0f10df34
/*  f10df14:	ac6c0e1c */ 	sw	$t4,0xe1c($v1)
/*  f10df18:	90ca0003 */ 	lbu	$t2,0x3($a2)
/*  f10df1c:	55400005 */ 	bnezl	$t2,.L0f10df34
/*  f10df20:	ac6c0e1c */ 	sw	$t4,0xe1c($v1)
/*  f10df24:	80cb000a */ 	lb	$t3,0xa($a2)
/*  f10df28:	51600003 */ 	beqzl	$t3,.L0f10df38
/*  f10df2c:	8c620e1c */ 	lw	$v0,0xe1c($v1)
/*  f10df30:	ac6c0e1c */ 	sw	$t4,0xe1c($v1)
.L0f10df34:
/*  f10df34:	8c620e1c */ 	lw	$v0,0xe1c($v1)
.L0f10df38:
/*  f10df38:	50400043 */ 	beqzl	$v0,.L0f10e048
/*  f10df3c:	a0c0000a */ 	sb	$zero,0xa($a2)
/*  f10df40:	8daddfc0 */ 	lw	$t5,-0x2040($t5)
/*  f10df44:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f10df48:	244effff */ 	addiu	$t6,$v0,-1
/*  f10df4c:	11a00003 */ 	beqz	$t5,.L0f10df5c
/*  f10df50:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f10df54:	ac6e0e1c */ 	sw	$t6,0xe1c($v1)
/*  f10df58:	01c01025 */ 	or	$v0,$t6,$zero
.L0f10df5c:
/*  f10df5c:	5440003a */ 	bnezl	$v0,.L0f10e048
/*  f10df60:	a0c0000a */ 	sb	$zero,0xa($a2)
/*  f10df64:	8caf029c */ 	lw	$t7,0x29c($a1)
/*  f10df68:	05e1002c */ 	bgez	$t7,.L0f10e01c
/*  f10df6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10df70:	8cb80298 */ 	lw	$t8,0x298($a1)
/*  f10df74:	0700001d */ 	bltz	$t8,.L0f10dfec
/*  f10df78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10df7c:	8cb9006c */ 	lw	$t9,0x6c($a1)
/*  f10df80:	00003825 */ 	or	$a3,$zero,$zero
/*  f10df84:	00001825 */ 	or	$v1,$zero,$zero
/*  f10df88:	13200003 */ 	beqz	$t9,.L0f10df98
/*  f10df8c:	00002025 */ 	or	$a0,$zero,$zero
/*  f10df90:	10000001 */ 	beqz	$zero,.L0f10df98
/*  f10df94:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f10df98:
/*  f10df98:	8ca80068 */ 	lw	$t0,0x68($a1)
/*  f10df9c:	00001025 */ 	or	$v0,$zero,$zero
/*  f10dfa0:	11000003 */ 	beqz	$t0,.L0f10dfb0
/*  f10dfa4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dfa8:	10000001 */ 	beqz	$zero,.L0f10dfb0
/*  f10dfac:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f10dfb0:
/*  f10dfb0:	8ca90064 */ 	lw	$t1,0x64($a1)
/*  f10dfb4:	11200003 */ 	beqz	$t1,.L0f10dfc4
/*  f10dfb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dfbc:	10000001 */ 	beqz	$zero,.L0f10dfc4
/*  f10dfc0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f10dfc4:
/*  f10dfc4:	8caa0070 */ 	lw	$t2,0x70($a1)
/*  f10dfc8:	11400003 */ 	beqz	$t2,.L0f10dfd8
/*  f10dfcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10dfd0:	10000001 */ 	beqz	$zero,.L0f10dfd8
/*  f10dfd4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10dfd8:
/*  f10dfd8:	00445821 */ 	addu	$t3,$v0,$a0
/*  f10dfdc:	01636021 */ 	addu	$t4,$t3,$v1
/*  f10dfe0:	01876821 */ 	addu	$t5,$t4,$a3
/*  f10dfe4:	29a10002 */ 	slti	$at,$t5,0x2
/*  f10dfe8:	1020000c */ 	beqz	$at,.L0f10e01c
.L0f10dfec:
/*  f10dfec:	3c04800a */ 	lui	$a0,0x800a
/*  f10dff0:	9084dfe9 */ 	lbu	$a0,-0x2017($a0)
/*  f10dff4:	0fc59585 */ 	jal	stageGetIndex
/*  f10dff8:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f10dffc:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f10e000:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f10e004:	04400005 */ 	bltz	$v0,.L0f10e01c
/*  f10e008:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f10e00c:	8cae04b4 */ 	lw	$t6,0x4b4($a1)
/*  f10e010:	24010026 */ 	addiu	$at,$zero,0x26
/*  f10e014:	15c10005 */ 	bne	$t6,$at,.L0f10e02c
/*  f10e018:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10e01c:
/*  f10e01c:	0fc3cdb7 */ 	jal	menuPopDialog
/*  f10e020:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f10e024:	10000007 */ 	beqz	$zero,.L0f10e044
/*  f10e028:	8fa6001c */ 	lw	$a2,0x1c($sp)
.L0f10e02c:
/*  f10e02c:	0fc435dc */ 	jal	func0f10d770
/*  f10e030:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f10e034:	3c048007 */ 	lui	$a0,%hi(menudialog_1b5c0)
/*  f10e038:	0fc3cbd3 */ 	jal	menuPushDialog
/*  f10e03c:	248455a0 */ 	addiu	$a0,$a0,%lo(menudialog_1b5c0)
/*  f10e040:	8fa6001c */ 	lw	$a2,0x1c($sp)
.L0f10e044:
/*  f10e044:	a0c0000a */ 	sb	$zero,0xa($a2)
.L0f10e048:
/*  f10e048:	a0c00003 */ 	sb	$zero,0x3($a2)
/*  f10e04c:	a0c00002 */ 	sb	$zero,0x2($a2)
.L0f10e050:
/*  f10e050:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10e054:
/*  f10e054:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10e058:	00001025 */ 	or	$v0,$zero,$zero
/*  f10e05c:	03e00008 */ 	jr	$ra
/*  f10e060:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel menuhandler0010e064
/*  f10e064:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10e068:	24010016 */ 	addiu	$at,$zero,0x16
/*  f10e06c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10e070:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f10e074:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f10e078:	14810076 */ 	bne	$a0,$at,.L0f10e254
/*  f10e07c:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f10e080:	3c058007 */ 	lui	$a1,%hi(g_MpPlayerNum)
/*  f10e084:	24a51448 */ 	addiu	$a1,$a1,%lo(g_MpPlayerNum)
/*  f10e088:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f10e08c:	24060e70 */ 	addiu	$a2,$zero,0xe70
/*  f10e090:	3c04800a */ 	lui	$a0,%hi(var8009e000)
/*  f10e094:	01e60019 */ 	multu	$t7,$a2
/*  f10e098:	2484e000 */ 	addiu	$a0,$a0,%lo(var8009e000)
/*  f10e09c:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f10e0a0:	0000c012 */ 	mflo	$t8
/*  f10e0a4:	0098c821 */ 	addu	$t9,$a0,$t8
/*  f10e0a8:	8f280e20 */ 	lw	$t0,0xe20($t9)
/*  f10e0ac:	31090200 */ 	andi	$t1,$t0,0x200
/*  f10e0b0:	55200005 */ 	bnezl	$t1,.L0f10e0c8
/*  f10e0b4:	3c014220 */ 	lui	$at,0x4220
/*  f10e0b8:	914b0001 */ 	lbu	$t3,0x1($t2)
/*  f10e0bc:	24010005 */ 	addiu	$at,$zero,0x5
/*  f10e0c0:	15610064 */ 	bne	$t3,$at,.L0f10e254
/*  f10e0c4:	3c014220 */ 	lui	$at,0x4220
.L0f10e0c8:
/*  f10e0c8:	44816000 */ 	mtc1	$at,$f12
/*  f10e0cc:	0fc01ac2 */ 	jal	func0f006b08
/*  f10e0d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e0d4:	3c01437f */ 	lui	$at,0x437f
/*  f10e0d8:	44812000 */ 	mtc1	$at,$f4
/*  f10e0dc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f10e0e0:	3c047f1b */ 	lui	$a0,%hi(var7f1b38b4)
/*  f10e0e4:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f10e0e8:	3c058007 */ 	lui	$a1,%hi(var80075968)
/*  f10e0ec:	3c014f00 */ 	lui	$at,0x4f00
/*  f10e0f0:	24a55968 */ 	addiu	$a1,$a1,%lo(var80075968)
/*  f10e0f4:	248438b4 */ 	addiu	$a0,$a0,%lo(var7f1b38b4)
/*  f10e0f8:	444cf800 */ 	cfc1	$t4,$31
/*  f10e0fc:	44cdf800 */ 	ctc1	$t5,$31
/*  f10e100:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e104:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f10e108:	444df800 */ 	cfc1	$t5,$31
/*  f10e10c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e110:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f10e114:	51a00013 */ 	beqzl	$t5,.L0f10e164
/*  f10e118:	440d4000 */ 	mfc1	$t5,$f8
/*  f10e11c:	44814000 */ 	mtc1	$at,$f8
/*  f10e120:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f10e124:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f10e128:	44cdf800 */ 	ctc1	$t5,$31
/*  f10e12c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e130:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f10e134:	444df800 */ 	cfc1	$t5,$31
/*  f10e138:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e13c:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f10e140:	15a00005 */ 	bnez	$t5,.L0f10e158
/*  f10e144:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e148:	440d4000 */ 	mfc1	$t5,$f8
/*  f10e14c:	3c018000 */ 	lui	$at,0x8000
/*  f10e150:	10000007 */ 	beqz	$zero,.L0f10e170
/*  f10e154:	01a16825 */ 	or	$t5,$t5,$at
.L0f10e158:
/*  f10e158:	10000005 */ 	beqz	$zero,.L0f10e170
/*  f10e15c:	240dffff */ 	addiu	$t5,$zero,-1
/*  f10e160:	440d4000 */ 	mfc1	$t5,$f8
.L0f10e164:
/*  f10e164:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e168:	05a0fffb */ 	bltz	$t5,.L0f10e158
/*  f10e16c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10e170:
/*  f10e170:	44ccf800 */ 	ctc1	$t4,$31
/*  f10e174:	0c0036cc */ 	jal	func0000db30
/*  f10e178:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f10e17c:	8fae0024 */ 	lw	$t6,0x24($sp)
/*  f10e180:	3c188007 */ 	lui	$t8,0x8007
/*  f10e184:	91cf0001 */ 	lbu	$t7,0x1($t6)
/*  f10e188:	55e00014 */ 	bnezl	$t7,.L0f10e1dc
/*  f10e18c:	8fa90028 */ 	lw	$t1,0x28($sp)
/*  f10e190:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f10e194:	3c04800a */ 	lui	$a0,0x800a
/*  f10e198:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f10e19c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10e1a0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10e1a4:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f10e1a8:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f10e1ac:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10e1b0:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f10e1b4:	00992021 */ 	addu	$a0,$a0,$t9
/*  f10e1b8:	8c84ee20 */ 	lw	$a0,-0x11e0($a0)
/*  f10e1bc:	308800ff */ 	andi	$t0,$a0,0xff
/*  f10e1c0:	0fc41fd9 */ 	jal	cheatGetTime
/*  f10e1c4:	01002025 */ 	or	$a0,$t0,$zero
/*  f10e1c8:	54400004 */ 	bnezl	$v0,.L0f10e1dc
/*  f10e1cc:	8fa90028 */ 	lw	$t1,0x28($sp)
/*  f10e1d0:	10000086 */ 	beqz	$zero,.L0f10e3ec
/*  f10e1d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f10e1d8:	8fa90028 */ 	lw	$t1,0x28($sp)
.L0f10e1dc:
/*  f10e1dc:	3c058007 */ 	lui	$a1,0x8007
/*  f10e1e0:	8ca55968 */ 	lw	$a1,0x5968($a1)
/*  f10e1e4:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f10e1e8:	0fc01a40 */ 	jal	func0f006900
/*  f10e1ec:	8d240004 */ 	lw	$a0,0x4($t1)
/*  f10e1f0:	8fa70028 */ 	lw	$a3,0x28($sp)
/*  f10e1f4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f10e1f8:	3c058007 */ 	lui	$a1,0x8007
/*  f10e1fc:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f10e200:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f10e204:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f10e208:	91430001 */ 	lbu	$v1,0x1($t2)
/*  f10e20c:	54610009 */ 	bnel	$v1,$at,.L0f10e234
/*  f10e210:	24010005 */ 	addiu	$at,$zero,0x5
/*  f10e214:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f10e218:	0fc01a40 */ 	jal	func0f006900
/*  f10e21c:	8ca55968 */ 	lw	$a1,0x5968($a1)
/*  f10e220:	8fa70028 */ 	lw	$a3,0x28($sp)
/*  f10e224:	ace20000 */ 	sw	$v0,0x0($a3)
/*  f10e228:	8fac0024 */ 	lw	$t4,0x24($sp)
/*  f10e22c:	91830001 */ 	lbu	$v1,0x1($t4)
/*  f10e230:	24010005 */ 	addiu	$at,$zero,0x5
.L0f10e234:
/*  f10e234:	14610007 */ 	bne	$v1,$at,.L0f10e254
/*  f10e238:	3c058007 */ 	lui	$a1,0x8007
/*  f10e23c:	8ce40000 */ 	lw	$a0,0x0($a3)
/*  f10e240:	8ca55968 */ 	lw	$a1,0x5968($a1)
/*  f10e244:	0fc01a40 */ 	jal	func0f006900
/*  f10e248:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f10e24c:	8fad0028 */ 	lw	$t5,0x28($sp)
/*  f10e250:	ada20000 */ 	sw	$v0,0x0($t5)
.L0f10e254:
/*  f10e254:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f10e258:	3c04800a */ 	lui	$a0,%hi(var8009e000)
/*  f10e25c:	3c058007 */ 	lui	$a1,%hi(g_MpPlayerNum)
/*  f10e260:	24010018 */ 	addiu	$at,$zero,0x18
/*  f10e264:	24a51448 */ 	addiu	$a1,$a1,%lo(g_MpPlayerNum)
/*  f10e268:	2484e000 */ 	addiu	$a0,$a0,%lo(var8009e000)
/*  f10e26c:	15c1005e */ 	bne	$t6,$at,.L0f10e3e8
/*  f10e270:	24060e70 */ 	addiu	$a2,$zero,0xe70
/*  f10e274:	8faf0024 */ 	lw	$t7,0x24($sp)
/*  f10e278:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10e27c:	91e30001 */ 	lbu	$v1,0x1($t7)
/*  f10e280:	54610018 */ 	bnel	$v1,$at,.L0f10e2e4
/*  f10e284:	24010002 */ 	addiu	$at,$zero,0x2
/*  f10e288:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f10e28c:	03060019 */ 	multu	$t8,$a2
/*  f10e290:	0000c812 */ 	mflo	$t9
/*  f10e294:	00994021 */ 	addu	$t0,$a0,$t9
/*  f10e298:	8d020e20 */ 	lw	$v0,0xe20($t0)
/*  f10e29c:	30490800 */ 	andi	$t1,$v0,0x800
/*  f10e2a0:	11200003 */ 	beqz	$t1,.L0f10e2b0
/*  f10e2a4:	304a0100 */ 	andi	$t2,$v0,0x100
/*  f10e2a8:	10000050 */ 	beqz	$zero,.L0f10e3ec
/*  f10e2ac:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10e2b0:
/*  f10e2b0:	11400009 */ 	beqz	$t2,.L0f10e2d8
/*  f10e2b4:	304c0600 */ 	andi	$t4,$v0,0x600
/*  f10e2b8:	15800007 */ 	bnez	$t4,.L0f10e2d8
/*  f10e2bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e2c0:	0fc41fd9 */ 	jal	cheatGetTime
/*  f10e2c4:	304400ff */ 	andi	$a0,$v0,0xff
/*  f10e2c8:	18400003 */ 	blez	$v0,.L0f10e2d8
/*  f10e2cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e2d0:	10000046 */ 	beqz	$zero,.L0f10e3ec
/*  f10e2d4:	00001025 */ 	or	$v0,$zero,$zero
.L0f10e2d8:
/*  f10e2d8:	10000044 */ 	beqz	$zero,.L0f10e3ec
/*  f10e2dc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f10e2e0:	24010002 */ 	addiu	$at,$zero,0x2
.L0f10e2e4:
/*  f10e2e4:	5461000c */ 	bnel	$v1,$at,.L0f10e318
/*  f10e2e8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f10e2ec:	8cab0000 */ 	lw	$t3,0x0($a1)
/*  f10e2f0:	01660019 */ 	multu	$t3,$a2
/*  f10e2f4:	00006812 */ 	mflo	$t5
/*  f10e2f8:	008d7021 */ 	addu	$t6,$a0,$t5
/*  f10e2fc:	8dcf0e20 */ 	lw	$t7,0xe20($t6)
/*  f10e300:	31f80a00 */ 	andi	$t8,$t7,0xa00
/*  f10e304:	57000004 */ 	bnezl	$t8,.L0f10e318
/*  f10e308:	24010003 */ 	addiu	$at,$zero,0x3
/*  f10e30c:	10000037 */ 	beqz	$zero,.L0f10e3ec
/*  f10e310:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f10e314:	24010003 */ 	addiu	$at,$zero,0x3
.L0f10e318:
/*  f10e318:	5461000c */ 	bnel	$v1,$at,.L0f10e34c
/*  f10e31c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f10e320:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f10e324:	03260019 */ 	multu	$t9,$a2
/*  f10e328:	00004012 */ 	mflo	$t0
/*  f10e32c:	00884821 */ 	addu	$t1,$a0,$t0
/*  f10e330:	8d2a0e20 */ 	lw	$t2,0xe20($t1)
/*  f10e334:	314c0200 */ 	andi	$t4,$t2,0x200
/*  f10e338:	55800004 */ 	bnezl	$t4,.L0f10e34c
/*  f10e33c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f10e340:	1000002a */ 	beqz	$zero,.L0f10e3ec
/*  f10e344:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f10e348:	24010004 */ 	addiu	$at,$zero,0x4
.L0f10e34c:
/*  f10e34c:	5461000c */ 	bnel	$v1,$at,.L0f10e380
/*  f10e350:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10e354:	8cab0000 */ 	lw	$t3,0x0($a1)
/*  f10e358:	01660019 */ 	multu	$t3,$a2
/*  f10e35c:	00006812 */ 	mflo	$t5
/*  f10e360:	008d7021 */ 	addu	$t6,$a0,$t5
/*  f10e364:	8dcf0e20 */ 	lw	$t7,0xe20($t6)
/*  f10e368:	31f80a00 */ 	andi	$t8,$t7,0xa00
/*  f10e36c:	53000004 */ 	beqzl	$t8,.L0f10e380
/*  f10e370:	24010006 */ 	addiu	$at,$zero,0x6
/*  f10e374:	1000001d */ 	beqz	$zero,.L0f10e3ec
/*  f10e378:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f10e37c:	24010006 */ 	addiu	$at,$zero,0x6
.L0f10e380:
/*  f10e380:	5461000d */ 	bnel	$v1,$at,.L0f10e3b8
/*  f10e384:	24010005 */ 	addiu	$at,$zero,0x5
/*  f10e388:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f10e38c:	24010a00 */ 	addiu	$at,$zero,0xa00
/*  f10e390:	03260019 */ 	multu	$t9,$a2
/*  f10e394:	00004012 */ 	mflo	$t0
/*  f10e398:	00884821 */ 	addu	$t1,$a0,$t0
/*  f10e39c:	8d2a0e20 */ 	lw	$t2,0xe20($t1)
/*  f10e3a0:	314c0a00 */ 	andi	$t4,$t2,0xa00
/*  f10e3a4:	55810004 */ 	bnel	$t4,$at,.L0f10e3b8
/*  f10e3a8:	24010005 */ 	addiu	$at,$zero,0x5
/*  f10e3ac:	1000000f */ 	beqz	$zero,.L0f10e3ec
/*  f10e3b0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f10e3b4:	24010005 */ 	addiu	$at,$zero,0x5
.L0f10e3b8:
/*  f10e3b8:	5461000c */ 	bnel	$v1,$at,.L0f10e3ec
/*  f10e3bc:	00001025 */ 	or	$v0,$zero,$zero
/*  f10e3c0:	8cab0000 */ 	lw	$t3,0x0($a1)
/*  f10e3c4:	01660019 */ 	multu	$t3,$a2
/*  f10e3c8:	00006812 */ 	mflo	$t5
/*  f10e3cc:	008d7021 */ 	addu	$t6,$a0,$t5
/*  f10e3d0:	8dcf0e20 */ 	lw	$t7,0xe20($t6)
/*  f10e3d4:	31f80800 */ 	andi	$t8,$t7,0x800
/*  f10e3d8:	57000004 */ 	bnezl	$t8,.L0f10e3ec
/*  f10e3dc:	00001025 */ 	or	$v0,$zero,$zero
/*  f10e3e0:	10000002 */ 	beqz	$zero,.L0f10e3ec
/*  f10e3e4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f10e3e8:
/*  f10e3e8:	00001025 */ 	or	$v0,$zero,$zero
.L0f10e3ec:
/*  f10e3ec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10e3f0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10e3f4:	03e00008 */ 	jr	$ra
/*  f10e3f8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10e3fc
/*  f10e3fc:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10e400:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10e404:	3c02800a */ 	lui	$v0,0x800a
/*  f10e408:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10e40c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10e410:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e414:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10e418:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10e41c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10e420:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e424:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10e428:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f10e42c:	8c42ee20 */ 	lw	$v0,-0x11e0($v0)
/*  f10e430:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10e434:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10e438:	30580300 */ 	andi	$t8,$v0,0x300
/*  f10e43c:	53000006 */ 	beqzl	$t8,.L0f10e458
/*  f10e440:	00001025 */ 	or	$v0,$zero,$zero
/*  f10e444:	0fc41fde */ 	jal	cheatGetName
/*  f10e448:	304400ff */ 	andi	$a0,$v0,0xff
/*  f10e44c:	10000003 */ 	beqz	$zero,.L0f10e45c
/*  f10e450:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10e454:	00001025 */ 	or	$v0,$zero,$zero
.L0f10e458:
/*  f10e458:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10e45c:
/*  f10e45c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10e460:	03e00008 */ 	jr	$ra
/*  f10e464:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10e468
/*  f10e468:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10e46c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10e470:	3c02800a */ 	lui	$v0,0x800a
/*  f10e474:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10e478:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10e47c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e480:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10e484:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10e488:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10e48c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e490:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10e494:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f10e498:	8c42ee20 */ 	lw	$v0,-0x11e0($v0)
/*  f10e49c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10e4a0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10e4a4:	30580800 */ 	andi	$t8,$v0,0x800
/*  f10e4a8:	13000006 */ 	beqz	$t8,.L0f10e4c4
/*  f10e4ac:	00022402 */ 	srl	$a0,$v0,0x10
/*  f10e4b0:	309900ff */ 	andi	$t9,$a0,0xff
/*  f10e4b4:	0fc41fde */ 	jal	cheatGetName
/*  f10e4b8:	03202025 */ 	or	$a0,$t9,$zero
/*  f10e4bc:	10000003 */ 	beqz	$zero,.L0f10e4cc
/*  f10e4c0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10e4c4:
/*  f10e4c4:	00001025 */ 	or	$v0,$zero,$zero
/*  f10e4c8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10e4cc:
/*  f10e4cc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10e4d0:	03e00008 */ 	jr	$ra
/*  f10e4d4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10e4d8
/*  f10e4d8:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10e4dc:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10e4e0:	3c02800a */ 	lui	$v0,0x800a
/*  f10e4e4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f10e4e8:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10e4ec:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e4f0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10e4f4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10e4f8:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10e4fc:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e500:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10e504:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f10e508:	8c42ee20 */ 	lw	$v0,-0x11e0($v0)
/*  f10e50c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10e510:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f10e514:	30580100 */ 	andi	$t8,$v0,0x100
/*  f10e518:	17000003 */ 	bnez	$t8,.L0f10e528
/*  f10e51c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e520:	10000015 */ 	beqz	$zero,.L0f10e578
/*  f10e524:	00001025 */ 	or	$v0,$zero,$zero
.L0f10e528:
/*  f10e528:	0fc41fd9 */ 	jal	cheatGetTime
/*  f10e52c:	304400ff */ 	andi	$a0,$v0,0xff
/*  f10e530:	14400003 */ 	bnez	$v0,.L0f10e540
/*  f10e534:	00403825 */ 	or	$a3,$v0,$zero
/*  f10e538:	1000000f */ 	beqz	$zero,.L0f10e578
/*  f10e53c:	00001025 */ 	or	$v0,$zero,$zero
.L0f10e540:
/*  f10e540:	00072900 */ 	sll	$a1,$a3,0x4
/*  f10e544:	00a72823 */ 	subu	$a1,$a1,$a3
/*  f10e548:	3c048007 */ 	lui	$a0,0x8007
/*  f10e54c:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10e550:	00052880 */ 	sll	$a1,$a1,0x2
/*  f10e554:	0fc355f8 */ 	jal	formatTime
/*  f10e558:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f10e55c:	3c048007 */ 	lui	$a0,0x8007
/*  f10e560:	3c057f1b */ 	lui	$a1,%hi(var7f1b38bc)
/*  f10e564:	24a538bc */ 	addiu	$a1,$a1,%lo(var7f1b38bc)
/*  f10e568:	0c004c89 */ 	jal	strcat
/*  f10e56c:	8c841440 */ 	lw	$a0,0x1440($a0)
/*  f10e570:	3c028007 */ 	lui	$v0,0x8007
/*  f10e574:	8c421440 */ 	lw	$v0,0x1440($v0)
.L0f10e578:
/*  f10e578:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10e57c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f10e580:	03e00008 */ 	jr	$ra
/*  f10e584:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10e588
/*  f10e588:	3c0e800a */ 	lui	$t6,0x800a
/*  f10e58c:	8dce21d0 */ 	lw	$t6,0x21d0($t6)
/*  f10e590:	3c0f800a */ 	lui	$t7,0x800a
/*  f10e594:	15c00020 */ 	bnez	$t6,.L0f10e618
/*  f10e598:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e59c:	8def21d4 */ 	lw	$t7,0x21d4($t7)
/*  f10e5a0:	3c05800a */ 	lui	$a1,%hi(g_MissionConfig)
/*  f10e5a4:	24a5dfe8 */ 	addiu	$a1,$a1,%lo(g_MissionConfig)
/*  f10e5a8:	15e0001b */ 	bnez	$t7,.L0f10e618
/*  f10e5ac:	3c09800a */ 	lui	$t1,0x800a
/*  f10e5b0:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f10e5b4:	25292200 */ 	addiu	$t1,$t1,0x2200
/*  f10e5b8:	90aa0002 */ 	lbu	$t2,0x2($a1)
/*  f10e5bc:	0018ce42 */ 	srl	$t9,$t8,0x19
/*  f10e5c0:	00194080 */ 	sll	$t0,$t9,0x2
/*  f10e5c4:	01091021 */ 	addu	$v0,$t0,$t1
/*  f10e5c8:	8c4300a0 */ 	lw	$v1,0xa0($v0)
/*  f10e5cc:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f10e5d0:	014b2004 */ 	sllv	$a0,$t3,$t2
/*  f10e5d4:	00646024 */ 	and	$t4,$v1,$a0
/*  f10e5d8:	1180000e */ 	beqz	$t4,.L0f10e614
/*  f10e5dc:	0064c025 */ 	or	$t8,$v1,$a0
/*  f10e5e0:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10e5e4:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10e5e8:	3c01800a */ 	lui	$at,0x800a
/*  f10e5ec:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f10e5f0:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10e5f4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e5f8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10e5fc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10e600:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10e604:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e608:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10e60c:	002f0821 */ 	addu	$at,$at,$t7
/*  f10e610:	ac2dee24 */ 	sw	$t5,-0x11dc($at)
.L0f10e614:
/*  f10e614:	ac5800a0 */ 	sw	$t8,0xa0($v0)
.L0f10e618:
/*  f10e618:	03e00008 */ 	jr	$ra
/*  f10e61c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10e620
/*  f10e620:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10e624:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10e628:	3c07800a */ 	lui	$a3,%hi(g_MissionConfig)
/*  f10e62c:	24e7dfe8 */ 	addiu	$a3,$a3,%lo(g_MissionConfig)
/*  f10e630:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10e634:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e638:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10e63c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10e640:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10e644:	90e60002 */ 	lbu	$a2,0x2($a3)
/*  f10e648:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f10e64c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10e650:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10e654:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f10e658:	01f84021 */ 	addu	$t0,$t7,$t8
/*  f10e65c:	3c03800a */ 	lui	$v1,0x800a
/*  f10e660:	ad060e2c */ 	sw	$a2,0xe2c($t0)
/*  f10e664:	8c6319c4 */ 	lw	$v1,0x19c4($v1)
/*  f10e668:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f10e66c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10e670:	10610183 */ 	beq	$v1,$at,.L0f10ec80
/*  f10e674:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10e678:	3c19800a */ 	lui	$t9,0x800a
/*  f10e67c:	8f39a2d4 */ 	lw	$t9,-0x5d2c($t9)
/*  f10e680:	57200180 */ 	bnezl	$t9,.L0f10ec84
/*  f10e684:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10e688:	80ea0003 */ 	lb	$t2,0x3($a3)
/*  f10e68c:	ad000e20 */ 	sw	$zero,0xe20($t0)
/*  f10e690:	ad000e24 */ 	sw	$zero,0xe24($t0)
/*  f10e694:	05400033 */ 	bltz	$t2,.L0f10e764
/*  f10e698:	a100083b */ 	sb	$zero,0x83b($t0)
/*  f10e69c:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f10e6a0:	00026640 */ 	sll	$t4,$v0,0x19
/*  f10e6a4:	0580002f */ 	bltz	$t4,.L0f10e764
/*  f10e6a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e6ac:	90ed0000 */ 	lbu	$t5,0x0($a3)
/*  f10e6b0:	00c02025 */ 	or	$a0,$a2,$zero
/*  f10e6b4:	31ae0001 */ 	andi	$t6,$t5,0x1
/*  f10e6b8:	15c0002a */ 	bnez	$t6,.L0f10e764
/*  f10e6bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e6c0:	0fc41fae */ 	jal	cheatGetByTimedStageIndex
/*  f10e6c4:	00022e42 */ 	srl	$a1,$v0,0x19
/*  f10e6c8:	3c04800a */ 	lui	$a0,0x800a
/*  f10e6cc:	9084dfea */ 	lbu	$a0,-0x2016($a0)
/*  f10e6d0:	0fc41fc6 */ 	jal	cheatGetByCompletedStageIndex
/*  f10e6d4:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f10e6d8:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f10e6dc:	3c188007 */ 	lui	$t8,0x8007
/*  f10e6e0:	3c098007 */ 	lui	$t1,0x8007
/*  f10e6e4:	0460000d */ 	bltz	$v1,.L0f10e71c
/*  f10e6e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e6ec:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f10e6f0:	3c01800a */ 	lui	$at,0x800a
/*  f10e6f4:	346f0100 */ 	ori	$t7,$v1,0x100
/*  f10e6f8:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f10e6fc:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10e700:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f10e704:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f10e708:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f10e70c:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f10e710:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f10e714:	00390821 */ 	addu	$at,$at,$t9
/*  f10e718:	ac2fee20 */ 	sw	$t7,-0x11e0($at)
.L0f10e71c:
/*  f10e71c:	04400011 */ 	bltz	$v0,.L0f10e764
/*  f10e720:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e724:	8d291448 */ 	lw	$t1,0x1448($t1)
/*  f10e728:	3c0b800a */ 	lui	$t3,%hi(var8009e000)
/*  f10e72c:	256be000 */ 	addiu	$t3,$t3,%lo(var8009e000)
/*  f10e730:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f10e734:	01495023 */ 	subu	$t2,$t2,$t1
/*  f10e738:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f10e73c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f10e740:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f10e744:	01495023 */ 	subu	$t2,$t2,$t1
/*  f10e748:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f10e74c:	014b4021 */ 	addu	$t0,$t2,$t3
/*  f10e750:	8d0c0e20 */ 	lw	$t4,0xe20($t0)
/*  f10e754:	00026c00 */ 	sll	$t5,$v0,0x10
/*  f10e758:	35ae1000 */ 	ori	$t6,$t5,0x1000
/*  f10e75c:	018ec025 */ 	or	$t8,$t4,$t6
/*  f10e760:	ad180e20 */ 	sw	$t8,0xe20($t0)
.L0f10e764:
/*  f10e764:	3c02800a */ 	lui	$v0,0x800a
/*  f10e768:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f10e76c:	8c4f00d8 */ 	lw	$t7,0xd8($v0)
/*  f10e770:	15e00008 */ 	bnez	$t7,.L0f10e794
/*  f10e774:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e778:	8c59048c */ 	lw	$t9,0x48c($v0)
/*  f10e77c:	17200005 */ 	bnez	$t9,.L0f10e794
/*  f10e780:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e784:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f10e788:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e78c:	1440000a */ 	bnez	$v0,.L0f10e7b8
/*  f10e790:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb44)
.L0f10e794:
/*  f10e794:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb5c)
/*  f10e798:	24845b3c */ 	addiu	$a0,$a0,%lo(menudialog_1bb5c)
/*  f10e79c:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10e7a0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f10e7a4:	3c02800a */ 	lui	$v0,0x800a
/*  f10e7a8:	9042dfeb */ 	lbu	$v0,-0x2015($v0)
/*  f10e7ac:	000249c2 */ 	srl	$t1,$v0,0x7
/*  f10e7b0:	1000000f */ 	beqz	$zero,.L0f10e7f0
/*  f10e7b4:	01201025 */ 	or	$v0,$t1,$zero
.L0f10e7b8:
/*  f10e7b8:	24845b24 */ 	addiu	$a0,$a0,%lo(menudialog_1bb44)
/*  f10e7bc:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10e7c0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f10e7c4:	3c02800a */ 	lui	$v0,0x800a
/*  f10e7c8:	9042dfeb */ 	lbu	$v0,-0x2015($v0)
/*  f10e7cc:	000251c2 */ 	srl	$t2,$v0,0x7
/*  f10e7d0:	11400007 */ 	beqz	$t2,.L0f10e7f0
/*  f10e7d4:	01401025 */ 	or	$v0,$t2,$zero
/*  f10e7d8:	0fc43962 */ 	jal	func0f10e588
/*  f10e7dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e7e0:	3c02800a */ 	lui	$v0,0x800a
/*  f10e7e4:	9042dfeb */ 	lbu	$v0,-0x2015($v0)
/*  f10e7e8:	000259c2 */ 	srl	$t3,$v0,0x7
/*  f10e7ec:	01601025 */ 	or	$v0,$t3,$zero
.L0f10e7f0:
/*  f10e7f0:	1440011c */ 	bnez	$v0,.L0f10ec64
/*  f10e7f4:	3c0d800a */ 	lui	$t5,0x800a
/*  f10e7f8:	8daddfe8 */ 	lw	$t5,-0x2018($t5)
/*  f10e7fc:	3c188007 */ 	lui	$t8,0x8007
/*  f10e800:	000d7640 */ 	sll	$t6,$t5,0x19
/*  f10e804:	05c00117 */ 	bltz	$t6,.L0f10ec64
/*  f10e808:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e80c:	8f181448 */ 	lw	$t8,0x1448($t8)
/*  f10e810:	3c02800a */ 	lui	$v0,0x800a
/*  f10e814:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f10e818:	001878c0 */ 	sll	$t7,$t8,0x3
/*  f10e81c:	01f87823 */ 	subu	$t7,$t7,$t8
/*  f10e820:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10e824:	01f87821 */ 	addu	$t7,$t7,$t8
/*  f10e828:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10e82c:	01f87823 */ 	subu	$t7,$t7,$t8
/*  f10e830:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10e834:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f10e838:	8c42ee20 */ 	lw	$v0,-0x11e0($v0)
/*  f10e83c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f10e840:	30590100 */ 	andi	$t9,$v0,0x100
/*  f10e844:	13200014 */ 	beqz	$t9,.L0f10e898
/*  f10e848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e84c:	0fc41b50 */ 	jal	cheatIsUnlocked
/*  f10e850:	304400ff */ 	andi	$a0,$v0,0xff
/*  f10e854:	10400010 */ 	beqz	$v0,.L0f10e898
/*  f10e858:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f10e85c:	3c098007 */ 	lui	$t1,0x8007
/*  f10e860:	8d291448 */ 	lw	$t1,0x1448($t1)
/*  f10e864:	3c0b800a */ 	lui	$t3,%hi(var8009e000)
/*  f10e868:	256be000 */ 	addiu	$t3,$t3,%lo(var8009e000)
/*  f10e86c:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f10e870:	01495023 */ 	subu	$t2,$t2,$t1
/*  f10e874:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f10e878:	01495021 */ 	addu	$t2,$t2,$t1
/*  f10e87c:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f10e880:	01495023 */ 	subu	$t2,$t2,$t1
/*  f10e884:	000a5100 */ 	sll	$t2,$t2,0x4
/*  f10e888:	014b4021 */ 	addu	$t0,$t2,$t3
/*  f10e88c:	8d0d0e20 */ 	lw	$t5,0xe20($t0)
/*  f10e890:	35ac0400 */ 	ori	$t4,$t5,0x400
/*  f10e894:	ad0c0e20 */ 	sw	$t4,0xe20($t0)
.L0f10e898:
/*  f10e898:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10e89c:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10e8a0:	3c02800a */ 	lui	$v0,0x800a
/*  f10e8a4:	000ec0c0 */ 	sll	$t8,$t6,0x3
/*  f10e8a8:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f10e8ac:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f10e8b0:	030ec021 */ 	addu	$t8,$t8,$t6
/*  f10e8b4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f10e8b8:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f10e8bc:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f10e8c0:	00581021 */ 	addu	$v0,$v0,$t8
/*  f10e8c4:	8c42ee20 */ 	lw	$v0,-0x11e0($v0)
/*  f10e8c8:	304f1000 */ 	andi	$t7,$v0,0x1000
/*  f10e8cc:	11e00005 */ 	beqz	$t7,.L0f10e8e4
/*  f10e8d0:	00022402 */ 	srl	$a0,$v0,0x10
/*  f10e8d4:	309900ff */ 	andi	$t9,$a0,0xff
/*  f10e8d8:	0fc41b50 */ 	jal	cheatIsUnlocked
/*  f10e8dc:	03202025 */ 	or	$a0,$t9,$zero
/*  f10e8e0:	afa2001c */ 	sw	$v0,0x1c($sp)
.L0f10e8e4:
/*  f10e8e4:	0fc3089f */ 	jal	getMissionTime
/*  f10e8e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e8ec:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f10e8f0:	0041001a */ 	div	$zero,$v0,$at
/*  f10e8f4:	00001812 */ 	mflo	$v1
/*  f10e8f8:	3c047fff */ 	lui	$a0,0x7fff
/*  f10e8fc:	10600010 */ 	beqz	$v1,.L0f10e940
/*  f10e900:	3484ffff */ 	ori	$a0,$a0,0xffff
/*  f10e904:	0064082b */ 	sltu	$at,$v1,$a0
/*  f10e908:	10200007 */ 	beqz	$at,.L0f10e928
/*  f10e90c:	3c05800a */ 	lui	$a1,0x800a
/*  f10e910:	24a52200 */ 	addiu	$a1,$a1,0x2200
/*  f10e914:	8ca20010 */ 	lw	$v0,0x10($a1)
/*  f10e918:	00834823 */ 	subu	$t1,$a0,$v1
/*  f10e91c:	0049082b */ 	sltu	$at,$v0,$t1
/*  f10e920:	14200005 */ 	bnez	$at,.L0f10e938
/*  f10e924:	00435021 */ 	addu	$t2,$v0,$v1
.L0f10e928:
/*  f10e928:	3c05800a */ 	lui	$a1,0x800a
/*  f10e92c:	24a52200 */ 	addiu	$a1,$a1,0x2200
/*  f10e930:	10000003 */ 	beqz	$zero,.L0f10e940
/*  f10e934:	aca40010 */ 	sw	$a0,0x10($a1)
.L0f10e938:
/*  f10e938:	3c01800a */ 	lui	$at,0x800a
/*  f10e93c:	ac2a2210 */ 	sw	$t2,0x2210($at)
.L0f10e940:
/*  f10e940:	3c03800a */ 	lui	$v1,%hi(g_MissionConfig)
/*  f10e944:	2463dfe8 */ 	addiu	$v1,$v1,%lo(g_MissionConfig)
/*  f10e948:	3c05800a */ 	lui	$a1,0x800a
/*  f10e94c:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f10e950:	24a52200 */ 	addiu	$a1,$a1,0x2200
/*  f10e954:	90af000b */ 	lbu	$t7,0xb($a1)
/*  f10e958:	906b0002 */ 	lbu	$t3,0x2($v1)
/*  f10e95c:	000d7642 */ 	srl	$t6,$t5,0x19
/*  f10e960:	31d80007 */ 	andi	$t8,$t6,0x7
/*  f10e964:	31f9fff8 */ 	andi	$t9,$t7,0xfff8
/*  f10e968:	03194825 */ 	or	$t1,$t8,$t9
/*  f10e96c:	a0a9000b */ 	sb	$t1,0xb($a1)
/*  f10e970:	3c0a800a */ 	lui	$t2,0x800a
/*  f10e974:	a0ab000c */ 	sb	$t3,0xc($a1)
/*  f10e978:	8d4a21d0 */ 	lw	$t2,0x21d0($t2)
/*  f10e97c:	3c0b800a */ 	lui	$t3,0x800a
/*  f10e980:	154000b8 */ 	bnez	$t2,.L0f10ec64
/*  f10e984:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e988:	8d6b21d4 */ 	lw	$t3,0x21d4($t3)
/*  f10e98c:	156000b5 */ 	bnez	$t3,.L0f10ec64
/*  f10e990:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e994:	906d0000 */ 	lbu	$t5,0x0($v1)
/*  f10e998:	3c02800a */ 	lui	$v0,0x800a
/*  f10e99c:	31ac0001 */ 	andi	$t4,$t5,0x1
/*  f10e9a0:	158000b0 */ 	bnez	$t4,.L0f10ec64
/*  f10e9a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e9a8:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f10e9ac:	8c4e00d8 */ 	lw	$t6,0xd8($v0)
/*  f10e9b0:	15c000ac */ 	bnez	$t6,.L0f10ec64
/*  f10e9b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e9b8:	8c4f048c */ 	lw	$t7,0x48c($v0)
/*  f10e9bc:	15e000a9 */ 	bnez	$t7,.L0f10ec64
/*  f10e9c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e9c4:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f10e9c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e9cc:	104000a5 */ 	beqz	$v0,.L0f10ec64
/*  f10e9d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e9d4:	0fc3089f */ 	jal	getMissionTime
/*  f10e9d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10e9dc:	2401003c */ 	addiu	$at,$zero,0x3c
/*  f10e9e0:	0041001a */ 	div	$zero,$v0,$at
/*  f10e9e4:	00002012 */ 	mflo	$a0
/*  f10e9e8:	3c05800a */ 	lui	$a1,0x800a
/*  f10e9ec:	2c811000 */ 	sltiu	$at,$a0,0x1000
/*  f10e9f0:	14200002 */ 	bnez	$at,.L0f10e9fc
/*  f10e9f4:	24a52200 */ 	addiu	$a1,$a1,0x2200
/*  f10e9f8:	24040fff */ 	addiu	$a0,$zero,0xfff
.L0f10e9fc:
/*  f10e9fc:	14800002 */ 	bnez	$a0,.L0f10ea08
/*  f10ea00:	3c06800a */ 	lui	$a2,0x800a
/*  f10ea04:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f10ea08:
/*  f10ea08:	90c6dfea */ 	lbu	$a2,-0x2016($a2)
/*  f10ea0c:	3c09800a */ 	lui	$t1,0x800a
/*  f10ea10:	8d29dfe8 */ 	lw	$t1,-0x2018($t1)
/*  f10ea14:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f10ea18:	0306c023 */ 	subu	$t8,$t8,$a2
/*  f10ea1c:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f10ea20:	00095642 */ 	srl	$t2,$t1,0x19
/*  f10ea24:	000a5840 */ 	sll	$t3,$t2,0x1
/*  f10ea28:	00b8c821 */ 	addu	$t9,$a1,$t8
/*  f10ea2c:	032b3821 */ 	addu	$a3,$t9,$t3
/*  f10ea30:	94e30020 */ 	lhu	$v1,0x20($a3)
/*  f10ea34:	3c0c8007 */ 	lui	$t4,0x8007
/*  f10ea38:	3c09800a */ 	lui	$t1,%hi(var8009e000)
/*  f10ea3c:	1460000d */ 	bnez	$v1,.L0f10ea74
/*  f10ea40:	3c0f8007 */ 	lui	$t7,0x8007
/*  f10ea44:	8d8c1448 */ 	lw	$t4,0x1448($t4)
/*  f10ea48:	3c01800a */ 	lui	$at,0x800a
/*  f10ea4c:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f10ea50:	000c70c0 */ 	sll	$t6,$t4,0x3
/*  f10ea54:	01cc7023 */ 	subu	$t6,$t6,$t4
/*  f10ea58:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f10ea5c:	01cc7021 */ 	addu	$t6,$t6,$t4
/*  f10ea60:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f10ea64:	01cc7023 */ 	subu	$t6,$t6,$t4
/*  f10ea68:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f10ea6c:	002e0821 */ 	addu	$at,$at,$t6
/*  f10ea70:	ac2dee24 */ 	sw	$t5,-0x11dc($at)
.L0f10ea74:
/*  f10ea74:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f10ea78:	2529e000 */ 	addiu	$t1,$t1,%lo(var8009e000)
/*  f10ea7c:	0083082b */ 	sltu	$at,$a0,$v1
/*  f10ea80:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f10ea84:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10ea88:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f10ea8c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f10ea90:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f10ea94:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10ea98:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f10ea9c:	14200003 */ 	bnez	$at,.L0f10eaac
/*  f10eaa0:	03094021 */ 	addu	$t0,$t8,$t1
/*  f10eaa4:	54600003 */ 	bnezl	$v1,.L0f10eab4
/*  f10eaa8:	28c10011 */ 	slti	$at,$a2,0x11
.L0f10eaac:
/*  f10eaac:	a4e40020 */ 	sh	$a0,0x20($a3)
/*  f10eab0:	28c10011 */ 	slti	$at,$a2,0x11
.L0f10eab4:
/*  f10eab4:	1020001d */ 	beqz	$at,.L0f10eb2c
/*  f10eab8:	24ca0001 */ 	addiu	$t2,$a2,0x1
/*  f10eabc:	315900ff */ 	andi	$t9,$t2,0xff
/*  f10eac0:	2b210011 */ 	slti	$at,$t9,0x11
/*  f10eac4:	14200003 */ 	bnez	$at,.L0f10ead4
/*  f10eac8:	a0aa000c */ 	sb	$t2,0xc($a1)
/*  f10eacc:	240b0010 */ 	addiu	$t3,$zero,0x10
/*  f10ead0:	a0ab000c */ 	sb	$t3,0xc($a1)
.L0f10ead4:
/*  f10ead4:	00003025 */ 	or	$a2,$zero,$zero
/*  f10ead8:	24070006 */ 	addiu	$a3,$zero,0x6
/*  f10eadc:	24040011 */ 	addiu	$a0,$zero,0x11
.L0f10eae0:
/*  f10eae0:	3c0c800a */ 	lui	$t4,0x800a
/*  f10eae4:	258c2200 */ 	addiu	$t4,$t4,0x2200
/*  f10eae8:	00cc1821 */ 	addu	$v1,$a2,$t4
/*  f10eaec:	00001025 */ 	or	$v0,$zero,$zero
.L0f10eaf0:
/*  f10eaf0:	946d0020 */ 	lhu	$t5,0x20($v1)
/*  f10eaf4:	51a00008 */ 	beqzl	$t5,.L0f10eb18
/*  f10eaf8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10eafc:	90aa000b */ 	lbu	$t2,0xb($a1)
/*  f10eb00:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f10eb04:	000f48c0 */ 	sll	$t1,$t7,0x3
/*  f10eb08:	3159ff07 */ 	andi	$t9,$t2,0xff07
/*  f10eb0c:	01395825 */ 	or	$t3,$t1,$t9
/*  f10eb10:	a0ab000b */ 	sb	$t3,0xb($a1)
/*  f10eb14:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f10eb18:
/*  f10eb18:	1444fff5 */ 	bne	$v0,$a0,.L0f10eaf0
/*  f10eb1c:	24630006 */ 	addiu	$v1,$v1,0x6
/*  f10eb20:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f10eb24:	14c7ffee */ 	bne	$a2,$a3,.L0f10eae0
/*  f10eb28:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10eb2c:
/*  f10eb2c:	8d020e20 */ 	lw	$v0,0xe20($t0)
/*  f10eb30:	304c0100 */ 	andi	$t4,$v0,0x100
/*  f10eb34:	11800016 */ 	beqz	$t4,.L0f10eb90
/*  f10eb38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10eb3c:	0fc41b50 */ 	jal	cheatIsUnlocked
/*  f10eb40:	304400ff */ 	andi	$a0,$v0,0xff
/*  f10eb44:	8fad0020 */ 	lw	$t5,0x20($sp)
/*  f10eb48:	15a00011 */ 	bnez	$t5,.L0f10eb90
/*  f10eb4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10eb50:	1040000f */ 	beqz	$v0,.L0f10eb90
/*  f10eb54:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10eb58:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10eb5c:	3c18800a */ 	lui	$t8,%hi(var8009e000)
/*  f10eb60:	2718e000 */ 	addiu	$t8,$t8,%lo(var8009e000)
/*  f10eb64:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f10eb68:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10eb6c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f10eb70:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f10eb74:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f10eb78:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f10eb7c:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f10eb80:	01f84021 */ 	addu	$t0,$t7,$t8
/*  f10eb84:	8d0a0e20 */ 	lw	$t2,0xe20($t0)
/*  f10eb88:	35490200 */ 	ori	$t1,$t2,0x200
/*  f10eb8c:	ad090e20 */ 	sw	$t1,0xe20($t0)
.L0f10eb90:
/*  f10eb90:	3c198007 */ 	lui	$t9,0x8007
/*  f10eb94:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f10eb98:	3c02800a */ 	lui	$v0,0x800a
/*  f10eb9c:	001958c0 */ 	sll	$t3,$t9,0x3
/*  f10eba0:	01795823 */ 	subu	$t3,$t3,$t9
/*  f10eba4:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f10eba8:	01795821 */ 	addu	$t3,$t3,$t9
/*  f10ebac:	000b58c0 */ 	sll	$t3,$t3,0x3
/*  f10ebb0:	01795823 */ 	subu	$t3,$t3,$t9
/*  f10ebb4:	000b5900 */ 	sll	$t3,$t3,0x4
/*  f10ebb8:	004b1021 */ 	addu	$v0,$v0,$t3
/*  f10ebbc:	8c42ee20 */ 	lw	$v0,-0x11e0($v0)
/*  f10ebc0:	304c1000 */ 	andi	$t4,$v0,0x1000
/*  f10ebc4:	11800017 */ 	beqz	$t4,.L0f10ec24
/*  f10ebc8:	00022402 */ 	srl	$a0,$v0,0x10
/*  f10ebcc:	308d00ff */ 	andi	$t5,$a0,0xff
/*  f10ebd0:	0fc41b50 */ 	jal	cheatIsUnlocked
/*  f10ebd4:	01a02025 */ 	or	$a0,$t5,$zero
/*  f10ebd8:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f10ebdc:	15c00011 */ 	bnez	$t6,.L0f10ec24
/*  f10ebe0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ebe4:	1040000f */ 	beqz	$v0,.L0f10ec24
/*  f10ebe8:	3c0f8007 */ 	lui	$t7,0x8007
/*  f10ebec:	8def1448 */ 	lw	$t7,0x1448($t7)
/*  f10ebf0:	3c0a800a */ 	lui	$t2,%hi(var8009e000)
/*  f10ebf4:	254ae000 */ 	addiu	$t2,$t2,%lo(var8009e000)
/*  f10ebf8:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f10ebfc:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10ec00:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f10ec04:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f10ec08:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f10ec0c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f10ec10:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f10ec14:	030a4021 */ 	addu	$t0,$t8,$t2
/*  f10ec18:	8d090e20 */ 	lw	$t1,0xe20($t0)
/*  f10ec1c:	35390800 */ 	ori	$t9,$t1,0x800
/*  f10ec20:	ad190e20 */ 	sw	$t9,0xe20($t0)
.L0f10ec24:
/*  f10ec24:	0fc66bf7 */ 	jal	func0f19afdc
/*  f10ec28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ec2c:	3c0b800a */ 	lui	$t3,0x800a
/*  f10ec30:	916bdfe9 */ 	lbu	$t3,-0x2017($t3)
/*  f10ec34:	2401002a */ 	addiu	$at,$zero,0x2a
/*  f10ec38:	3c02800a */ 	lui	$v0,0x800a
/*  f10ec3c:	15610009 */ 	bne	$t3,$at,.L0f10ec64
/*  f10ec40:	2442232b */ 	addiu	$v0,$v0,0x232b
/*  f10ec44:	904c0000 */ 	lbu	$t4,0x0($v0)
/*  f10ec48:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f10ec4c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f10ec50:	15800004 */ 	bnez	$t4,.L0f10ec64
/*  f10ec54:	3c01800a */ 	lui	$at,0x800a
/*  f10ec58:	a04d0000 */ 	sb	$t5,0x0($v0)
/*  f10ec5c:	0fc44270 */ 	jal	func0f1109c0
/*  f10ec60:	a02e232c */ 	sb	$t6,0x232c($at)
.L0f10ec64:
/*  f10ec64:	3c04800a */ 	lui	$a0,%hi(var800a22c0)
/*  f10ec68:	248422c0 */ 	addiu	$a0,$a0,%lo(var800a22c0)
/*  f10ec6c:	00002825 */ 	or	$a1,$zero,$zero
/*  f10ec70:	0fc42539 */ 	jal	func0f1094e4
/*  f10ec74:	00003025 */ 	or	$a2,$zero,$zero
/*  f10ec78:	3c03800a */ 	lui	$v1,0x800a
/*  f10ec7c:	8c6319c4 */ 	lw	$v1,0x19c4($v1)
.L0f10ec80:
/*  f10ec80:	24010001 */ 	addiu	$at,$zero,0x1
.L0f10ec84:
/*  f10ec84:	54610008 */ 	bnel	$v1,$at,.L0f10eca8
/*  f10ec88:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10ec8c:	0fc5b350 */ 	jal	func0f16cd40
/*  f10ec90:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10ec94:	3c18800a */ 	lui	$t8,0x800a
/*  f10ec98:	8f18a244 */ 	lw	$t8,-0x5dbc($t8)
/*  f10ec9c:	240f0003 */ 	addiu	$t7,$zero,0x3
/*  f10eca0:	af0f1a24 */ 	sw	$t7,0x1a24($t8)
/*  f10eca4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10eca8:
/*  f10eca8:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f10ecac:	03e00008 */ 	jr	$ra
/*  f10ecb0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10ecb4
/*  f10ecb4:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10ecb8:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10ecbc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10ecc0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10ecc4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10ecc8:	0fc5b350 */ 	jal	func0f16cd40
/*  f10eccc:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f10ecd0:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f10ecd4:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f10ecd8:	8c8f0288 */ 	lw	$t7,0x288($a0)
/*  f10ecdc:	3c018007 */ 	lui	$at,0x8007
/*  f10ece0:	3c198007 */ 	lui	$t9,0x8007
/*  f10ece4:	8df80070 */ 	lw	$t8,0x70($t7)
/*  f10ece8:	3c09800a */ 	lui	$t1,%hi(var8009e000)
/*  f10ecec:	2529e000 */ 	addiu	$t1,$t1,%lo(var8009e000)
/*  f10ecf0:	ac381448 */ 	sw	$t8,0x1448($at)
/*  f10ecf4:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f10ecf8:	3c0a800a */ 	lui	$t2,0x800a
/*  f10ecfc:	8c8b028c */ 	lw	$t3,0x28c($a0)
/*  f10ed00:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f10ed04:	01194023 */ 	subu	$t0,$t0,$t9
/*  f10ed08:	00084080 */ 	sll	$t0,$t0,0x2
/*  f10ed0c:	01194021 */ 	addu	$t0,$t0,$t9
/*  f10ed10:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f10ed14:	01194023 */ 	subu	$t0,$t0,$t9
/*  f10ed18:	00084100 */ 	sll	$t0,$t0,0x4
/*  f10ed1c:	01091021 */ 	addu	$v0,$t0,$t1
/*  f10ed20:	ac400e20 */ 	sw	$zero,0xe20($v0)
/*  f10ed24:	ac400e24 */ 	sw	$zero,0xe24($v0)
/*  f10ed28:	914adfea */ 	lbu	$t2,-0x2016($t2)
/*  f10ed2c:	8c8302a0 */ 	lw	$v1,0x2a0($a0)
/*  f10ed30:	a04b083b */ 	sb	$t3,0x83b($v0)
/*  f10ed34:	ac4a0e2c */ 	sw	$t2,0xe2c($v0)
/*  f10ed38:	8c6c00d8 */ 	lw	$t4,0xd8($v1)
/*  f10ed3c:	51800006 */ 	beqzl	$t4,.L0f10ed58
/*  f10ed40:	8c6f048c */ 	lw	$t7,0x48c($v1)
/*  f10ed44:	8c8d02a4 */ 	lw	$t5,0x2a4($a0)
/*  f10ed48:	8dae00d8 */ 	lw	$t6,0xd8($t5)
/*  f10ed4c:	15c0000c */ 	bnez	$t6,.L0f10ed80
/*  f10ed50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ed54:	8c6f048c */ 	lw	$t7,0x48c($v1)
.L0f10ed58:
/*  f10ed58:	15e00009 */ 	bnez	$t7,.L0f10ed80
/*  f10ed5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ed60:	8c9802a4 */ 	lw	$t8,0x2a4($a0)
/*  f10ed64:	8f19048c */ 	lw	$t9,0x48c($t8)
/*  f10ed68:	17200005 */ 	bnez	$t9,.L0f10ed80
/*  f10ed6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ed70:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f10ed74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ed78:	14400011 */ 	bnez	$v0,.L0f10edc0
/*  f10ed7c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10ed80:
/*  f10ed80:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f10ed84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10ed88:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10ed8c:	14410007 */ 	bne	$v0,$at,.L0f10edac
/*  f10ed90:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb8c)
/*  f10ed94:	3c048007 */ 	lui	$a0,%hi(menudialog_1bbbc)
/*  f10ed98:	24845b9c */ 	addiu	$a0,$a0,%lo(menudialog_1bbbc)
/*  f10ed9c:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10eda0:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10eda4:	10000016 */ 	beqz	$zero,.L0f10ee00
/*  f10eda8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10edac:
/*  f10edac:	24845b6c */ 	addiu	$a0,$a0,%lo(menudialog_1bb8c)
/*  f10edb0:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10edb4:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10edb8:	10000011 */ 	beqz	$zero,.L0f10ee00
/*  f10edbc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10edc0:
/*  f10edc0:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f10edc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10edc8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10edcc:	14410007 */ 	bne	$v0,$at,.L0f10edec
/*  f10edd0:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb74)
/*  f10edd4:	3c048007 */ 	lui	$a0,%hi(menudialog_1bba4)
/*  f10edd8:	24845b84 */ 	addiu	$a0,$a0,%lo(menudialog_1bba4)
/*  f10eddc:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10ede0:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10ede4:	10000004 */ 	beqz	$zero,.L0f10edf8
/*  f10ede8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10edec:
/*  f10edec:	24845b54 */ 	addiu	$a0,$a0,%lo(menudialog_1bb74)
/*  f10edf0:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10edf4:	24050005 */ 	addiu	$a1,$zero,0x5
.L0f10edf8:
/*  f10edf8:	0fc43962 */ 	jal	func0f10e588
/*  f10edfc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10ee00:
/*  f10ee00:	3c08800a */ 	lui	$t0,0x800a
/*  f10ee04:	3c09800a */ 	lui	$t1,0x800a
/*  f10ee08:	8d29a244 */ 	lw	$t1,-0x5dbc($t1)
/*  f10ee0c:	8d08a260 */ 	lw	$t0,-0x5da0($t0)
/*  f10ee10:	3c04800a */ 	lui	$a0,%hi(var800a22c0)
/*  f10ee14:	248422c0 */ 	addiu	$a0,$a0,%lo(var800a22c0)
/*  f10ee18:	15090003 */ 	bne	$t0,$t1,.L0f10ee28
/*  f10ee1c:	00002825 */ 	or	$a1,$zero,$zero
/*  f10ee20:	0fc42539 */ 	jal	func0f1094e4
/*  f10ee24:	00003025 */ 	or	$a2,$zero,$zero
.L0f10ee28:
/*  f10ee28:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f10ee2c:	8faa001c */ 	lw	$t2,0x1c($sp)
/*  f10ee30:	3c018007 */ 	lui	$at,0x8007
/*  f10ee34:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10ee38:	03e00008 */ 	jr	$ra
/*  f10ee3c:	ac2a1448 */ 	sw	$t2,0x1448($at)
);

GLOBAL_ASM(
glabel func0f10ee40
/*  f10ee40:	0000c0c0 */ 	sll	$t8,$zero,0x3
/*  f10ee44:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f10ee48:	3c048007 */ 	lui	$a0,%hi(g_MpPlayerNum)
/*  f10ee4c:	0018c140 */ 	sll	$t8,$t8,0x5
/*  f10ee50:	24841448 */ 	addiu	$a0,$a0,%lo(g_MpPlayerNum)
/*  f10ee54:	0300c023 */ 	subu	$t8,$t8,$zero
/*  f10ee58:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f10ee5c:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f10ee60:	3c01800a */ 	lui	$at,0x800a
/*  f10ee64:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10ee68:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f10ee6c:	00380821 */ 	addu	$at,$at,$t8
/*  f10ee70:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f10ee74:	a020e83b */ 	sb	$zero,-0x17c5($at)
/*  f10ee78:	8c6202a0 */ 	lw	$v0,0x2a0($v1)
/*  f10ee7c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10ee80:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10ee84:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f10ee88:	8c5900d8 */ 	lw	$t9,0xd8($v0)
/*  f10ee8c:	53200006 */ 	beqzl	$t9,.L0f10eea8
/*  f10ee90:	8c4a048c */ 	lw	$t2,0x48c($v0)
/*  f10ee94:	8c6802a4 */ 	lw	$t0,0x2a4($v1)
/*  f10ee98:	8d0900d8 */ 	lw	$t1,0xd8($t0)
/*  f10ee9c:	1520000c */ 	bnez	$t1,.L0f10eed0
/*  f10eea0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10eea4:	8c4a048c */ 	lw	$t2,0x48c($v0)
.L0f10eea8:
/*  f10eea8:	15400009 */ 	bnez	$t2,.L0f10eed0
/*  f10eeac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10eeb0:	8c6b02a4 */ 	lw	$t3,0x2a4($v1)
/*  f10eeb4:	8d6c048c */ 	lw	$t4,0x48c($t3)
/*  f10eeb8:	15800005 */ 	bnez	$t4,.L0f10eed0
/*  f10eebc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10eec0:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f10eec4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10eec8:	14400009 */ 	bnez	$v0,.L0f10eef0
/*  f10eecc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10eed0:
/*  f10eed0:	0fc435dc */ 	jal	func0f10d770
/*  f10eed4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10eed8:	3c048007 */ 	lui	$a0,%hi(menudialog_1b5c0)
/*  f10eedc:	248455a0 */ 	addiu	$a0,$a0,%lo(menudialog_1b5c0)
/*  f10eee0:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10eee4:	24050009 */ 	addiu	$a1,$zero,0x9
/*  f10eee8:	10000004 */ 	beqz	$zero,.L0f10eefc
/*  f10eeec:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10eef0:
/*  f10eef0:	0fc43644 */ 	jal	func0f10d910
/*  f10eef4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10eef8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10eefc:
/*  f10eefc:	8fad001c */ 	lw	$t5,0x1c($sp)
/*  f10ef00:	3c018007 */ 	lui	$at,0x8007
/*  f10ef04:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10ef08:	03e00008 */ 	jr	$ra
/*  f10ef0c:	ac2d1448 */ 	sw	$t5,0x1448($at)
);

GLOBAL_ASM(
glabel func0f10ef10
/*  f10ef10:	3c0e8007 */ 	lui	$t6,0x8007
/*  f10ef14:	8dce1448 */ 	lw	$t6,0x1448($t6)
/*  f10ef18:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f10ef1c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f10ef20:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10ef24:	0fc5b350 */ 	jal	func0f16cd40
/*  f10ef28:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f10ef2c:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10ef30:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f10ef34:	8c6f0288 */ 	lw	$t7,0x288($v1)
/*  f10ef38:	3c018007 */ 	lui	$at,0x8007
/*  f10ef3c:	3c198007 */ 	lui	$t9,0x8007
/*  f10ef40:	8df80070 */ 	lw	$t8,0x70($t7)
/*  f10ef44:	3c09800a */ 	lui	$t1,%hi(var8009e000)
/*  f10ef48:	2529e000 */ 	addiu	$t1,$t1,%lo(var8009e000)
/*  f10ef4c:	ac381448 */ 	sw	$t8,0x1448($at)
/*  f10ef50:	8f391448 */ 	lw	$t9,0x1448($t9)
/*  f10ef54:	8c6c0284 */ 	lw	$t4,0x284($v1)
/*  f10ef58:	8c6402a0 */ 	lw	$a0,0x2a0($v1)
/*  f10ef5c:	001940c0 */ 	sll	$t0,$t9,0x3
/*  f10ef60:	01194023 */ 	subu	$t0,$t0,$t9
/*  f10ef64:	00084080 */ 	sll	$t0,$t0,0x2
/*  f10ef68:	01194021 */ 	addu	$t0,$t0,$t9
/*  f10ef6c:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f10ef70:	01194023 */ 	subu	$t0,$t0,$t9
/*  f10ef74:	00084100 */ 	sll	$t0,$t0,0x4
/*  f10ef78:	01091021 */ 	addu	$v0,$t0,$t1
/*  f10ef7c:	ac400e20 */ 	sw	$zero,0xe20($v0)
/*  f10ef80:	ac400e24 */ 	sw	$zero,0xe24($v0)
/*  f10ef84:	3c0a800a */ 	lui	$t2,0x800a
/*  f10ef88:	914adfea */ 	lbu	$t2,-0x2016($t2)
/*  f10ef8c:	8c6b028c */ 	lw	$t3,0x28c($v1)
/*  f10ef90:	ac4a0e2c */ 	sw	$t2,0xe2c($v0)
/*  f10ef94:	148c0034 */ 	bne	$a0,$t4,.L0f10f068
/*  f10ef98:	a04b083b */ 	sb	$t3,0x83b($v0)
/*  f10ef9c:	8c6d02a8 */ 	lw	$t5,0x2a8($v1)
/*  f10efa0:	8dae048c */ 	lw	$t6,0x48c($t5)
/*  f10efa4:	15c0001b */ 	bnez	$t6,.L0f10f014
/*  f10efa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10efac:	8c8f00d8 */ 	lw	$t7,0xd8($a0)
/*  f10efb0:	15e00008 */ 	bnez	$t7,.L0f10efd4
/*  f10efb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10efb8:	8c98048c */ 	lw	$t8,0x48c($a0)
/*  f10efbc:	17000005 */ 	bnez	$t8,.L0f10efd4
/*  f10efc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10efc4:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f10efc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10efcc:	14400011 */ 	bnez	$v0,.L0f10f014
/*  f10efd0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10efd4:
/*  f10efd4:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f10efd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10efdc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10efe0:	14410007 */ 	bne	$v0,$at,.L0f10f000
/*  f10efe4:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb8c)
/*  f10efe8:	3c048007 */ 	lui	$a0,%hi(menudialog_1bbbc)
/*  f10efec:	24845b9c */ 	addiu	$a0,$a0,%lo(menudialog_1bbbc)
/*  f10eff0:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10eff4:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10eff8:	10000014 */ 	beqz	$zero,.L0f10f04c
/*  f10effc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10f000:
/*  f10f000:	24845b6c */ 	addiu	$a0,$a0,%lo(menudialog_1bb8c)
/*  f10f004:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10f008:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10f00c:	1000000f */ 	beqz	$zero,.L0f10f04c
/*  f10f010:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10f014:
/*  f10f014:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f10f018:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f01c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10f020:	14410007 */ 	bne	$v0,$at,.L0f10f040
/*  f10f024:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb74)
/*  f10f028:	3c048007 */ 	lui	$a0,%hi(menudialog_1bba4)
/*  f10f02c:	24845b84 */ 	addiu	$a0,$a0,%lo(menudialog_1bba4)
/*  f10f030:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10f034:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10f038:	10000004 */ 	beqz	$zero,.L0f10f04c
/*  f10f03c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10f040:
/*  f10f040:	24845b54 */ 	addiu	$a0,$a0,%lo(menudialog_1bb74)
/*  f10f044:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10f048:	24050005 */ 	addiu	$a1,$zero,0x5
.L0f10f04c:
/*  f10f04c:	3c04800a */ 	lui	$a0,%hi(var800a22c0)
/*  f10f050:	248422c0 */ 	addiu	$a0,$a0,%lo(var800a22c0)
/*  f10f054:	00002825 */ 	or	$a1,$zero,$zero
/*  f10f058:	0fc42539 */ 	jal	func0f1094e4
/*  f10f05c:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f060:	1000002e */ 	beqz	$zero,.L0f10f11c
/*  f10f064:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10f068:
/*  f10f068:	8c7902a8 */ 	lw	$t9,0x2a8($v1)
/*  f10f06c:	8f28048c */ 	lw	$t0,0x48c($t9)
/*  f10f070:	1500001b */ 	bnez	$t0,.L0f10f0e0
/*  f10f074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f078:	8c8900d8 */ 	lw	$t1,0xd8($a0)
/*  f10f07c:	15200008 */ 	bnez	$t1,.L0f10f0a0
/*  f10f080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f084:	8c8a048c */ 	lw	$t2,0x48c($a0)
/*  f10f088:	15400005 */ 	bnez	$t2,.L0f10f0a0
/*  f10f08c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f090:	0fc256d9 */ 	jal	objectiveIsAllComplete
/*  f10f094:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f098:	14400011 */ 	bnez	$v0,.L0f10f0e0
/*  f10f09c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10f0a0:
/*  f10f0a0:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f10f0a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f0a8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10f0ac:	14410007 */ 	bne	$v0,$at,.L0f10f0cc
/*  f10f0b0:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb74)
/*  f10f0b4:	3c048007 */ 	lui	$a0,%hi(menudialog_1bba4)
/*  f10f0b8:	24845b84 */ 	addiu	$a0,$a0,%lo(menudialog_1bba4)
/*  f10f0bc:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10f0c0:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10f0c4:	10000015 */ 	beqz	$zero,.L0f10f11c
/*  f10f0c8:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10f0cc:
/*  f10f0cc:	24845b54 */ 	addiu	$a0,$a0,%lo(menudialog_1bb74)
/*  f10f0d0:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10f0d4:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10f0d8:	10000010 */ 	beqz	$zero,.L0f10f11c
/*  f10f0dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10f0e0:
/*  f10f0e0:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f10f0e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f0e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10f0ec:	14410007 */ 	bne	$v0,$at,.L0f10f10c
/*  f10f0f0:	3c048007 */ 	lui	$a0,%hi(menudialog_1bb8c)
/*  f10f0f4:	3c048007 */ 	lui	$a0,%hi(menudialog_1bbbc)
/*  f10f0f8:	24845b9c */ 	addiu	$a0,$a0,%lo(menudialog_1bbbc)
/*  f10f0fc:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10f100:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10f104:	10000005 */ 	beqz	$zero,.L0f10f11c
/*  f10f108:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10f10c:
/*  f10f10c:	24845b6c */ 	addiu	$a0,$a0,%lo(menudialog_1bb8c)
/*  f10f110:	0fc3e0cc */ 	jal	func0f0f8330
/*  f10f114:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10f118:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f10f11c:
/*  f10f11c:	8fab001c */ 	lw	$t3,0x1c($sp)
/*  f10f120:	3c018007 */ 	lui	$at,0x8007
/*  f10f124:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f10f128:	03e00008 */ 	jr	$ra
/*  f10f12c:	ac2b1448 */ 	sw	$t3,0x1448($at)
/*  f10f130:	3c02800a */ 	lui	$v0,0x800a
/*  f10f134:	03e00008 */ 	jr	$ra
/*  f10f138:	24422214 */ 	addiu	$v0,$v0,0x2214
);

void savefileSetFlag(u32 value)
{
	func0f11e530(value, &g_SoloSaveFile.flags, true);
}

void savefileUnsetFlag(u32 value)
{
	func0f11e530(value, &g_SoloSaveFile.flags, false);
}

u32 savefileHasFlag(u32 value)
{
	return func0f11e584(value, &g_SoloSaveFile.flags);
}

GLOBAL_ASM(
glabel func0f10f1b0
/*  f10f1b0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f10f1b4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f10f1b8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f10f1bc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f10f1c0:	3c11800a */ 	lui	$s1,0x800a
/*  f10f1c4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f10f1c8:	26312214 */ 	addiu	$s1,$s1,0x2214
/*  f10f1cc:	24100023 */ 	addiu	$s0,$zero,0x23
/*  f10f1d0:	2412004f */ 	addiu	$s2,$zero,0x4f
/*  f10f1d4:	02002025 */ 	or	$a0,$s0,$zero
.L0f10f1d8:
/*  f10f1d8:	0fc47961 */ 	jal	func0f11e584
/*  f10f1dc:	02202825 */ 	or	$a1,$s1,$zero
/*  f10f1e0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10f1e4:	5612fffc */ 	bnel	$s0,$s2,.L0f10f1d8
/*  f10f1e8:	02002025 */ 	or	$a0,$s0,$zero
/*  f10f1ec:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f10f1f0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f10f1f4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f10f1f8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f10f1fc:	03e00008 */ 	jr	$ra
/*  f10f200:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f10f204
/*  f10f204:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10f208:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f10f20c:	8c620298 */ 	lw	$v0,0x298($v1)
/*  f10f210:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f10f214:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f10f218:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f10f21c:	04410005 */ 	bgez	$v0,.L0f10f234
/*  f10f220:	00803025 */ 	or	$a2,$a0,$zero
/*  f10f224:	8c6e029c */ 	lw	$t6,0x29c($v1)
/*  f10f228:	240f0004 */ 	addiu	$t7,$zero,0x4
/*  f10f22c:	05c20004 */ 	bltzl	$t6,.L0f10f240
/*  f10f230:	afaf0024 */ 	sw	$t7,0x24($sp)
.L0f10f234:
/*  f10f234:	10000002 */ 	beqz	$zero,.L0f10f240
/*  f10f238:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f10f23c:	afaf0024 */ 	sw	$t7,0x24($sp)
.L0f10f240:
/*  f10f240:	04410004 */ 	bgez	$v0,.L0f10f254
/*  f10f244:	00002025 */ 	or	$a0,$zero,$zero
/*  f10f248:	8c78029c */ 	lw	$t8,0x29c($v1)
/*  f10f24c:	24080005 */ 	addiu	$t0,$zero,0x5
/*  f10f250:	07000003 */ 	bltz	$t8,.L0f10f260
.L0f10f254:
/*  f10f254:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f10f258:	10000002 */ 	beqz	$zero,.L0f10f264
/*  f10f25c:	afb90020 */ 	sw	$t9,0x20($sp)
.L0f10f260:
/*  f10f260:	afa80020 */ 	sw	$t0,0x20($sp)
.L0f10f264:
/*  f10f264:	24d00014 */ 	addiu	$s0,$a2,0x14
/*  f10f268:	0fc47961 */ 	jal	func0f11e584
/*  f10f26c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f270:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10f274:	0fc54a52 */ 	jal	optionsSetForwardPitch
/*  f10f278:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f27c:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10f280:	0fc47961 */ 	jal	func0f11e584
/*  f10f284:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f288:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10f28c:	0fc54a68 */ 	jal	optionsSetAutoAim
/*  f10f290:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f294:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f10f298:	0fc47961 */ 	jal	func0f11e584
/*  f10f29c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f2a0:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10f2a4:	0fc54a94 */ 	jal	optionsSetAimControl
/*  f10f2a8:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f2ac:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f10f2b0:	0fc47961 */ 	jal	func0f11e584
/*  f10f2b4:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f2b8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10f2bc:	0fc54aaa */ 	jal	optionsSetSightOnScreen
/*  f10f2c0:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f2c4:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f10f2c8:	0fc47961 */ 	jal	func0f11e584
/*  f10f2cc:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f2d0:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10f2d4:	0fc54a7e */ 	jal	optionsSetLookAhead
/*  f10f2d8:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f2dc:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f10f2e0:	0fc47961 */ 	jal	func0f11e584
/*  f10f2e4:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f2e8:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10f2ec:	0fc54ac0 */ 	jal	optionsSetAmmoOnScreen
/*  f10f2f0:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f2f4:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f10f2f8:	0fc47961 */ 	jal	func0f11e584
/*  f10f2fc:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f300:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10f304:	0fc54b4a */ 	jal	optionsSetHeadRoll
/*  f10f308:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f30c:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f10f310:	0fc47961 */ 	jal	func0f11e584
/*  f10f314:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f318:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10f31c:	0fc54ad6 */ 	jal	optionsSetShowGunFunction
/*  f10f320:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f324:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f10f328:	0fc47961 */ 	jal	func0f11e584
/*  f10f32c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f330:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10f334:	0fc54aec */ 	jal	optionsSetAlwaysShowTarget
/*  f10f338:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f33c:	24040017 */ 	addiu	$a0,$zero,0x17
/*  f10f340:	0fc47961 */ 	jal	func0f11e584
/*  f10f344:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f348:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10f34c:	0fc54b02 */ 	jal	optionsSetShowZoomRange
/*  f10f350:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f354:	2404001a */ 	addiu	$a0,$zero,0x1a
/*  f10f358:	0fc47961 */ 	jal	func0f11e584
/*  f10f35c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f360:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10f364:	0fc54b2e */ 	jal	optionsSetShowMissionTime
/*  f10f368:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f36c:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f10f370:	0fc47961 */ 	jal	func0f11e584
/*  f10f374:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f378:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f10f37c:	0fc54b18 */ 	jal	optionsSetPaintball
/*  f10f380:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f384:	2404000c */ 	addiu	$a0,$zero,0xc
/*  f10f388:	0fc47961 */ 	jal	func0f11e584
/*  f10f38c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f390:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10f394:	0fc54a52 */ 	jal	optionsSetForwardPitch
/*  f10f398:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f39c:	2404000d */ 	addiu	$a0,$zero,0xd
/*  f10f3a0:	0fc47961 */ 	jal	func0f11e584
/*  f10f3a4:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f3a8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10f3ac:	0fc54a68 */ 	jal	optionsSetAutoAim
/*  f10f3b0:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f3b4:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f10f3b8:	0fc47961 */ 	jal	func0f11e584
/*  f10f3bc:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f3c0:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10f3c4:	0fc54a94 */ 	jal	optionsSetAimControl
/*  f10f3c8:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f3cc:	2404000f */ 	addiu	$a0,$zero,0xf
/*  f10f3d0:	0fc47961 */ 	jal	func0f11e584
/*  f10f3d4:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f3d8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10f3dc:	0fc54aaa */ 	jal	optionsSetSightOnScreen
/*  f10f3e0:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f3e4:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f10f3e8:	0fc47961 */ 	jal	func0f11e584
/*  f10f3ec:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f3f0:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10f3f4:	0fc54a7e */ 	jal	optionsSetLookAhead
/*  f10f3f8:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f3fc:	24040011 */ 	addiu	$a0,$zero,0x11
/*  f10f400:	0fc47961 */ 	jal	func0f11e584
/*  f10f404:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f408:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10f40c:	0fc54ac0 */ 	jal	optionsSetAmmoOnScreen
/*  f10f410:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f414:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f10f418:	0fc47961 */ 	jal	func0f11e584
/*  f10f41c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f420:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10f424:	0fc54b4a */ 	jal	optionsSetHeadRoll
/*  f10f428:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f42c:	24040013 */ 	addiu	$a0,$zero,0x13
/*  f10f430:	0fc47961 */ 	jal	func0f11e584
/*  f10f434:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f438:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10f43c:	0fc54ad6 */ 	jal	optionsSetShowGunFunction
/*  f10f440:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f444:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f10f448:	0fc47961 */ 	jal	func0f11e584
/*  f10f44c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f450:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10f454:	0fc54aec */ 	jal	optionsSetAlwaysShowTarget
/*  f10f458:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f45c:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f10f460:	0fc47961 */ 	jal	func0f11e584
/*  f10f464:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f468:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10f46c:	0fc54b02 */ 	jal	optionsSetShowZoomRange
/*  f10f470:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f474:	2404001b */ 	addiu	$a0,$zero,0x1b
/*  f10f478:	0fc47961 */ 	jal	func0f11e584
/*  f10f47c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f480:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10f484:	0fc54b2e */ 	jal	optionsSetShowMissionTime
/*  f10f488:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f48c:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f10f490:	0fc47961 */ 	jal	func0f11e584
/*  f10f494:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f498:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10f49c:	0fc54b18 */ 	jal	optionsSetPaintball
/*  f10f4a0:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f4a4:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f10f4a8:	0fc47961 */ 	jal	func0f11e584
/*  f10f4ac:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f4b0:	0fc54b44 */ 	jal	optionsSetInGameSubtitles
/*  f10f4b4:	00402025 */ 	or	$a0,$v0,$zero
/*  f10f4b8:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f10f4bc:	0fc47961 */ 	jal	func0f11e584
/*  f10f4c0:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f4c4:	0fc54b47 */ 	jal	optionsSetCutsceneSubtitles
/*  f10f4c8:	00402025 */ 	or	$a0,$v0,$zero
/*  f10f4cc:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f10f4d0:	0fc47961 */ 	jal	func0f11e584
/*  f10f4d4:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f4d8:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f10f4dc:	0fc54b18 */ 	jal	optionsSetPaintball
/*  f10f4e0:	00402825 */ 	or	$a1,$v0,$zero
/*  f10f4e4:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f10f4e8:	0fc47961 */ 	jal	func0f11e584
/*  f10f4ec:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f4f0:	3c01800a */ 	lui	$at,0x800a
/*  f10f4f4:	a022a4a3 */ 	sb	$v0,-0x5b5d($at)
/*  f10f4f8:	24040022 */ 	addiu	$a0,$zero,0x22
/*  f10f4fc:	0fc47961 */ 	jal	func0f11e584
/*  f10f500:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f504:	1040000d */ 	beqz	$v0,.L0f10f53c
/*  f10f508:	3c098009 */ 	lui	$t1,0x8009
/*  f10f50c:	91290af0 */ 	lbu	$t1,0xaf0($t1)
/*  f10f510:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10f514:	15210005 */ 	bne	$t1,$at,.L0f10f52c
/*  f10f518:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f51c:	0fc2f110 */ 	jal	optionsSetHiRes
/*  f10f520:	00002025 */ 	or	$a0,$zero,$zero
/*  f10f524:	10000007 */ 	beqz	$zero,.L0f10f544
/*  f10f528:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10f52c:
/*  f10f52c:	0fc2f110 */ 	jal	optionsSetHiRes
/*  f10f530:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10f534:	10000003 */ 	beqz	$zero,.L0f10f544
/*  f10f538:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10f53c:
/*  f10f53c:	0fc2f110 */ 	jal	optionsSetHiRes
/*  f10f540:	00002025 */ 	or	$a0,$zero,$zero
.L0f10f544:
/*  f10f544:	3c0a8009 */ 	lui	$t2,0x8009
/*  f10f548:	914a0af0 */ 	lbu	$t2,0xaf0($t2)
/*  f10f54c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f10f550:	55410008 */ 	bnel	$t2,$at,.L0f10f574
/*  f10f554:	24040019 */ 	addiu	$a0,$zero,0x19
/*  f10f558:	0fc54bd0 */ 	jal	optionsSetScreenSplit
/*  f10f55c:	00002025 */ 	or	$a0,$zero,$zero
/*  f10f560:	0fc54bca */ 	jal	optionsSetScreenRatio
/*  f10f564:	00002025 */ 	or	$a0,$zero,$zero
/*  f10f568:	1000000c */ 	beqz	$zero,.L0f10f59c
/*  f10f56c:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f10f570:	24040019 */ 	addiu	$a0,$zero,0x19
.L0f10f574:
/*  f10f574:	0fc47961 */ 	jal	func0f11e584
/*  f10f578:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f57c:	0fc54bd0 */ 	jal	optionsSetScreenSplit
/*  f10f580:	304400ff */ 	andi	$a0,$v0,0xff
/*  f10f584:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f10f588:	0fc47961 */ 	jal	func0f11e584
/*  f10f58c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f590:	0fc54bca */ 	jal	optionsSetScreenRatio
/*  f10f594:	00402025 */ 	or	$a0,$v0,$zero
/*  f10f598:	24040008 */ 	addiu	$a0,$zero,0x8
.L0f10f59c:
/*  f10f59c:	0fc47961 */ 	jal	func0f11e584
/*  f10f5a0:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f5a4:	10400005 */ 	beqz	$v0,.L0f10f5bc
/*  f10f5a8:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f10f5ac:	0fc54bc4 */ 	jal	optionsSetScreenSize
/*  f10f5b0:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f10f5b4:	1000000c */ 	beqz	$zero,.L0f10f5e8
/*  f10f5b8:	2404001f */ 	addiu	$a0,$zero,0x1f
.L0f10f5bc:
/*  f10f5bc:	0fc47961 */ 	jal	func0f11e584
/*  f10f5c0:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f5c4:	10400005 */ 	beqz	$v0,.L0f10f5dc
/*  f10f5c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10f5cc:	0fc54bc4 */ 	jal	optionsSetScreenSize
/*  f10f5d0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10f5d4:	10000004 */ 	beqz	$zero,.L0f10f5e8
/*  f10f5d8:	2404001f */ 	addiu	$a0,$zero,0x1f
.L0f10f5dc:
/*  f10f5dc:	0fc54bc4 */ 	jal	optionsSetScreenSize
/*  f10f5e0:	00002025 */ 	or	$a0,$zero,$zero
/*  f10f5e4:	2404001f */ 	addiu	$a0,$zero,0x1f
.L0f10f5e8:
/*  f10f5e8:	0fc47961 */ 	jal	func0f11e584
/*  f10f5ec:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f5f0:	10400005 */ 	beqz	$v0,.L0f10f608
/*  f10f5f4:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f10f5f8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f10f5fc:	3c01800a */ 	lui	$at,0x800a
/*  f10f600:	10000003 */ 	beqz	$zero,.L0f10f610
/*  f10f604:	ac2ba410 */ 	sw	$t3,-0x5bf0($at)
.L0f10f608:
/*  f10f608:	3c01800a */ 	lui	$at,0x800a
/*  f10f60c:	ac20a410 */ 	sw	$zero,-0x5bf0($at)
.L0f10f610:
/*  f10f610:	0fc47961 */ 	jal	func0f11e584
/*  f10f614:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f618:	10400005 */ 	beqz	$v0,.L0f10f630
/*  f10f61c:	2404001d */ 	addiu	$a0,$zero,0x1d
/*  f10f620:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f10f624:	3c01800a */ 	lui	$at,0x800a
/*  f10f628:	10000003 */ 	beqz	$zero,.L0f10f638
/*  f10f62c:	ac2ca408 */ 	sw	$t4,-0x5bf8($at)
.L0f10f630:
/*  f10f630:	3c01800a */ 	lui	$at,0x800a
/*  f10f634:	ac20a408 */ 	sw	$zero,-0x5bf8($at)
.L0f10f638:
/*  f10f638:	0fc47961 */ 	jal	func0f11e584
/*  f10f63c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f640:	10400005 */ 	beqz	$v0,.L0f10f658
/*  f10f644:	2404001e */ 	addiu	$a0,$zero,0x1e
/*  f10f648:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f10f64c:	3c01800a */ 	lui	$at,0x800a
/*  f10f650:	10000003 */ 	beqz	$zero,.L0f10f660
/*  f10f654:	ac2da414 */ 	sw	$t5,-0x5bec($at)
.L0f10f658:
/*  f10f658:	3c01800a */ 	lui	$at,0x800a
/*  f10f65c:	ac20a414 */ 	sw	$zero,-0x5bec($at)
.L0f10f660:
/*  f10f660:	0fc47961 */ 	jal	func0f11e584
/*  f10f664:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f668:	10400005 */ 	beqz	$v0,.L0f10f680
/*  f10f66c:	3c01800a */ 	lui	$at,0x800a
/*  f10f670:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f10f674:	3c01800a */ 	lui	$at,0x800a
/*  f10f678:	10000002 */ 	beqz	$zero,.L0f10f684
/*  f10f67c:	ac2ea40c */ 	sw	$t6,-0x5bf4($at)
.L0f10f680:
/*  f10f680:	ac20a40c */ 	sw	$zero,-0x5bf4($at)
.L0f10f684:
/*  f10f684:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f10f688:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f10f68c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f10f690:	03e00008 */ 	jr	$ra
/*  f10f694:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f10f698
/*  f10f698:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10f69c:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f10f6a0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f10f6a4:	8c620298 */ 	lw	$v0,0x298($v1)
/*  f10f6a8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f10f6ac:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f10f6b0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f10f6b4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f10f6b8:	04410005 */ 	bgez	$v0,.L0f10f6d0
/*  f10f6bc:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f10f6c0:	8c6e029c */ 	lw	$t6,0x29c($v1)
/*  f10f6c4:	24110004 */ 	addiu	$s1,$zero,0x4
/*  f10f6c8:	05c00003 */ 	bltz	$t6,.L0f10f6d8
/*  f10f6cc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10f6d0:
/*  f10f6d0:	10000001 */ 	beqz	$zero,.L0f10f6d8
/*  f10f6d4:	00008825 */ 	or	$s1,$zero,$zero
.L0f10f6d8:
/*  f10f6d8:	04410005 */ 	bgez	$v0,.L0f10f6f0
/*  f10f6dc:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f10f6e0:	8c6f029c */ 	lw	$t7,0x29c($v1)
/*  f10f6e4:	24100005 */ 	addiu	$s0,$zero,0x5
/*  f10f6e8:	05e00003 */ 	bltz	$t7,.L0f10f6f8
/*  f10f6ec:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10f6f0:
/*  f10f6f0:	10000001 */ 	beqz	$zero,.L0f10f6f8
/*  f10f6f4:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f10f6f8:
/*  f10f6f8:	3c057f1b */ 	lui	$a1,%hi(var7f1b38e0)
/*  f10f6fc:	0c004c4c */ 	jal	strcpy
/*  f10f700:	24a538e0 */ 	addiu	$a1,$a1,%lo(var7f1b38e0)
/*  f10f704:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f10f708:	24045000 */ 	addiu	$a0,$zero,0x5000
/*  f10f70c:	9058000b */ 	lbu	$t8,0xb($v0)
/*  f10f710:	a040000c */ 	sb	$zero,0xc($v0)
/*  f10f714:	ac400010 */ 	sw	$zero,0x10($v0)
/*  f10f718:	3308ff07 */ 	andi	$t0,$t8,0xff07
/*  f10f71c:	310900f8 */ 	andi	$t1,$t0,0xf8
/*  f10f720:	a048000b */ 	sb	$t0,0xb($v0)
/*  f10f724:	0c003a87 */ 	jal	audioSetSfxVolume
/*  f10f728:	a049000b */ 	sb	$t1,0xb($v0)
/*  f10f72c:	0fc54bdc */ 	jal	optionsSetMusicVolume
/*  f10f730:	24045000 */ 	addiu	$a0,$zero,0x5000
/*  f10f734:	0c003ce3 */ 	jal	audioSetSoundMode
/*  f10f738:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10f73c:	02202025 */ 	or	$a0,$s1,$zero
/*  f10f740:	0fc549cb */ 	jal	optionsSetControlMode
/*  f10f744:	00002825 */ 	or	$a1,$zero,$zero
/*  f10f748:	02002025 */ 	or	$a0,$s0,$zero
/*  f10f74c:	0fc549cb */ 	jal	optionsSetControlMode
/*  f10f750:	00002825 */ 	or	$a1,$zero,$zero
/*  f10f754:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f10f758:	26100014 */ 	addiu	$s0,$s0,0x14
/*  f10f75c:	0fc4796f */ 	jal	func0f11e5bc
/*  f10f760:	02002025 */ 	or	$a0,$s0,$zero
/*  f10f764:	00002025 */ 	or	$a0,$zero,$zero
/*  f10f768:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f76c:	0fc4794c */ 	jal	func0f11e530
/*  f10f770:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f774:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f10f778:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f77c:	0fc4794c */ 	jal	func0f11e530
/*  f10f780:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f784:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f10f788:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f78c:	0fc4794c */ 	jal	func0f11e530
/*  f10f790:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f794:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f10f798:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f79c:	0fc4794c */ 	jal	func0f11e530
/*  f10f7a0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f7a4:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f10f7a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f7ac:	0fc4794c */ 	jal	func0f11e530
/*  f10f7b0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f7b4:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f10f7b8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f7bc:	0fc4794c */ 	jal	func0f11e530
/*  f10f7c0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f7c4:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f10f7c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f7cc:	0fc4794c */ 	jal	func0f11e530
/*  f10f7d0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f7d4:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f10f7d8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f7dc:	0fc4794c */ 	jal	func0f11e530
/*  f10f7e0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f7e4:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f10f7e8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f7ec:	0fc4794c */ 	jal	func0f11e530
/*  f10f7f0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f7f4:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f10f7f8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f7fc:	0fc4794c */ 	jal	func0f11e530
/*  f10f800:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f804:	24040017 */ 	addiu	$a0,$zero,0x17
/*  f10f808:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f80c:	0fc4794c */ 	jal	func0f11e530
/*  f10f810:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f814:	2404001a */ 	addiu	$a0,$zero,0x1a
/*  f10f818:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f81c:	0fc4794c */ 	jal	func0f11e530
/*  f10f820:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f824:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f10f828:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f82c:	0fc4794c */ 	jal	func0f11e530
/*  f10f830:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f834:	2404000c */ 	addiu	$a0,$zero,0xc
/*  f10f838:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f83c:	0fc4794c */ 	jal	func0f11e530
/*  f10f840:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f844:	2404000d */ 	addiu	$a0,$zero,0xd
/*  f10f848:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f84c:	0fc4794c */ 	jal	func0f11e530
/*  f10f850:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f854:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f10f858:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f85c:	0fc4794c */ 	jal	func0f11e530
/*  f10f860:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f864:	2404000f */ 	addiu	$a0,$zero,0xf
/*  f10f868:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f86c:	0fc4794c */ 	jal	func0f11e530
/*  f10f870:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f874:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f10f878:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f87c:	0fc4794c */ 	jal	func0f11e530
/*  f10f880:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f884:	24040011 */ 	addiu	$a0,$zero,0x11
/*  f10f888:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f88c:	0fc4794c */ 	jal	func0f11e530
/*  f10f890:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f894:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f10f898:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f89c:	0fc4794c */ 	jal	func0f11e530
/*  f10f8a0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f8a4:	24040013 */ 	addiu	$a0,$zero,0x13
/*  f10f8a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f8ac:	0fc4794c */ 	jal	func0f11e530
/*  f10f8b0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f8b4:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f10f8b8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f8bc:	0fc4794c */ 	jal	func0f11e530
/*  f10f8c0:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f8c4:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f10f8c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f8cc:	0fc4794c */ 	jal	func0f11e530
/*  f10f8d0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f8d4:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f10f8d8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f8dc:	0fc4794c */ 	jal	func0f11e530
/*  f10f8e0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f8e4:	2404001b */ 	addiu	$a0,$zero,0x1b
/*  f10f8e8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f8ec:	0fc4794c */ 	jal	func0f11e530
/*  f10f8f0:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f8f4:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f10f8f8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f8fc:	0fc4794c */ 	jal	func0f11e530
/*  f10f900:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f904:	24040019 */ 	addiu	$a0,$zero,0x19
/*  f10f908:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f90c:	0fc4794c */ 	jal	func0f11e530
/*  f10f910:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f914:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f10f918:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f91c:	0fc4794c */ 	jal	func0f11e530
/*  f10f920:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f924:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f10f928:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f92c:	0fc4794c */ 	jal	func0f11e530
/*  f10f930:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f934:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f10f938:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f93c:	0fc4794c */ 	jal	func0f11e530
/*  f10f940:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f944:	24040022 */ 	addiu	$a0,$zero,0x22
/*  f10f948:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f94c:	0fc4794c */ 	jal	func0f11e530
/*  f10f950:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f954:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f10f958:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f95c:	0fc4794c */ 	jal	func0f11e530
/*  f10f960:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f964:	24040041 */ 	addiu	$a0,$zero,0x41
/*  f10f968:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f96c:	0fc4794c */ 	jal	func0f11e530
/*  f10f970:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f974:	24040042 */ 	addiu	$a0,$zero,0x42
/*  f10f978:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f97c:	0fc4794c */ 	jal	func0f11e530
/*  f10f980:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f984:	24040043 */ 	addiu	$a0,$zero,0x43
/*  f10f988:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f98c:	0fc4794c */ 	jal	func0f11e530
/*  f10f990:	00003025 */ 	or	$a2,$zero,$zero
/*  f10f994:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f10f998:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f99c:	0fc4794c */ 	jal	func0f11e530
/*  f10f9a0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f9a4:	2404001d */ 	addiu	$a0,$zero,0x1d
/*  f10f9a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f9ac:	0fc4794c */ 	jal	func0f11e530
/*  f10f9b0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f9b4:	2404001e */ 	addiu	$a0,$zero,0x1e
/*  f10f9b8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f9bc:	0fc4794c */ 	jal	func0f11e530
/*  f10f9c0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f9c4:	2404001f */ 	addiu	$a0,$zero,0x1f
/*  f10f9c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f10f9cc:	0fc4794c */ 	jal	func0f11e530
/*  f10f9d0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f10f9d4:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f10f9d8:	00009025 */ 	or	$s2,$zero,$zero
/*  f10f9dc:	24030003 */ 	addiu	$v1,$zero,0x3
/*  f10f9e0:	a480001e */ 	sh	$zero,0x1e($a0)
.L0f10f9e4:
/*  f10f9e4:	00008025 */ 	or	$s0,$zero,$zero
/*  f10f9e8:	00801025 */ 	or	$v0,$a0,$zero
.L0f10f9ec:
/*  f10f9ec:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10f9f0:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f10f9f4:	1603fffd */ 	bne	$s0,$v1,.L0f10f9ec
/*  f10f9f8:	a440001e */ 	sh	$zero,0x1e($v0)
/*  f10f9fc:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f10fa00:	2a410015 */ 	slti	$at,$s2,0x15
/*  f10fa04:	1420fff7 */ 	bnez	$at,.L0f10f9e4
/*  f10fa08:	24840006 */ 	addiu	$a0,$a0,0x6
/*  f10fa0c:	00009025 */ 	or	$s2,$zero,$zero
/*  f10fa10:	24110005 */ 	addiu	$s1,$zero,0x5
/*  f10fa14:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f10fa18:
/*  f10fa18:	02402025 */ 	or	$a0,$s2,$zero
.L0f10fa1c:
/*  f10fa1c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10fa20:	0fc67103 */ 	jal	mpSetChallengeCompletedByAnyChrWithNumPlayers
/*  f10fa24:	00003025 */ 	or	$a2,$zero,$zero
/*  f10fa28:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10fa2c:	5611fffb */ 	bnel	$s0,$s1,.L0f10fa1c
/*  f10fa30:	02402025 */ 	or	$a0,$s2,$zero
/*  f10fa34:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f10fa38:	2a41001e */ 	slti	$at,$s2,0x1e
/*  f10fa3c:	5420fff6 */ 	bnezl	$at,.L0f10fa18
/*  f10fa40:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f10fa44:	0fc66bf7 */ 	jal	func0f19afdc
/*  f10fa48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10fa4c:	3c02800a */ 	lui	$v0,0x800a
/*  f10fa50:	3c03800a */ 	lui	$v1,0x800a
/*  f10fa54:	2463220c */ 	addiu	$v1,$v1,0x220c
/*  f10fa58:	24422200 */ 	addiu	$v0,$v0,0x2200
.L0f10fa5c:
/*  f10fa5c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f10fa60:	0043082b */ 	sltu	$at,$v0,$v1
/*  f10fa64:	1420fffd */ 	bnez	$at,.L0f10fa5c
/*  f10fa68:	ac40009c */ 	sw	$zero,0x9c($v0)
/*  f10fa6c:	3c02800a */ 	lui	$v0,0x800a
/*  f10fa70:	3c03800a */ 	lui	$v1,0x800a
/*  f10fa74:	24632209 */ 	addiu	$v1,$v1,0x2209
/*  f10fa78:	24422200 */ 	addiu	$v0,$v0,0x2200
.L0f10fa7c:
/*  f10fa7c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10fa80:	0043082b */ 	sltu	$at,$v0,$v1
/*  f10fa84:	1420fffd */ 	bnez	$at,.L0f10fa7c
/*  f10fa88:	a04000ab */ 	sb	$zero,0xab($v0)
/*  f10fa8c:	3c02800a */ 	lui	$v0,0x800a
/*  f10fa90:	3c03800a */ 	lui	$v1,0x800a
/*  f10fa94:	24632206 */ 	addiu	$v1,$v1,0x2206
/*  f10fa98:	24422200 */ 	addiu	$v0,$v0,0x2200
.L0f10fa9c:
/*  f10fa9c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f10faa0:	1443fffe */ 	bne	$v0,$v1,.L0f10fa9c
/*  f10faa4:	a04000b4 */ 	sb	$zero,0xb4($v0)
/*  f10faa8:	0fc43c81 */ 	jal	func0f10f204
/*  f10faac:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f10fab0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f10fab4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f10fab8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f10fabc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f10fac0:	03e00008 */ 	jr	$ra
/*  f10fac4:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f10fac8
/*  f10fac8:	27bdfec0 */ 	addiu	$sp,$sp,-320
/*  f10facc:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f10fad0:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f10fad4:	8c620298 */ 	lw	$v0,0x298($v1)
/*  f10fad8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f10fadc:	00808025 */ 	or	$s0,$a0,$zero
/*  f10fae0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f10fae4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f10fae8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f10faec:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f10faf0:	04410005 */ 	bgez	$v0,.L0f10fb08
/*  f10faf4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f10faf8:	8c6e029c */ 	lw	$t6,0x29c($v1)
/*  f10fafc:	24110004 */ 	addiu	$s1,$zero,0x4
/*  f10fb00:	05c00003 */ 	bltz	$t6,.L0f10fb10
/*  f10fb04:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10fb08:
/*  f10fb08:	10000001 */ 	beqz	$zero,.L0f10fb10
/*  f10fb0c:	00008825 */ 	or	$s1,$zero,$zero
.L0f10fb10:
/*  f10fb10:	04410005 */ 	bgez	$v0,.L0f10fb28
/*  f10fb14:	27b4004c */ 	addiu	$s4,$sp,0x4c
/*  f10fb18:	8c6f029c */ 	lw	$t7,0x29c($v1)
/*  f10fb1c:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f10fb20:	05e00003 */ 	bltz	$t7,.L0f10fb30
/*  f10fb24:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10fb28:
/*  f10fb28:	10000001 */ 	beqz	$zero,.L0f10fb30
/*  f10fb2c:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f10fb30:
/*  f10fb30:	060000d6 */ 	bltz	$s0,.L0f10fe8c
/*  f10fb34:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f10fb38:	0fc35517 */ 	jal	func0f0d545c
/*  f10fb3c:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fb40:	00102600 */ 	sll	$a0,$s0,0x18
/*  f10fb44:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f10fb48:	3c05800a */ 	lui	$a1,0x800a
/*  f10fb4c:	8ca522c0 */ 	lw	$a1,0x22c0($a1)
/*  f10fb50:	03002025 */ 	or	$a0,$t8,$zero
/*  f10fb54:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f10fb58:	0fc45a00 */ 	jal	func0f116800
/*  f10fb5c:	00003825 */ 	or	$a3,$zero,$zero
/*  f10fb60:	3c01800a */ 	lui	$at,0x800a
/*  f10fb64:	144000c7 */ 	bnez	$v0,.L0f10fe84
/*  f10fb68:	ac2221f8 */ 	sw	$v0,0x21f8($at)
/*  f10fb6c:	0fc41d3b */ 	jal	cheatsDisableAll
/*  f10fb70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10fb74:	3c05800a */ 	lui	$a1,0x800a
/*  f10fb78:	24a52200 */ 	addiu	$a1,$a1,0x2200
/*  f10fb7c:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fb80:	0fc35539 */ 	jal	func0f0d54e4
/*  f10fb84:	00003025 */ 	or	$a2,$zero,$zero
/*  f10fb88:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fb8c:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fb90:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10fb94:	3c03800a */ 	lui	$v1,0x800a
/*  f10fb98:	24632200 */ 	addiu	$v1,$v1,0x2200
/*  f10fb9c:	906a000b */ 	lbu	$t2,0xb($v1)
/*  f10fba0:	000248c0 */ 	sll	$t1,$v0,0x3
/*  f10fba4:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fba8:	314bff07 */ 	andi	$t3,$t2,0xff07
/*  f10fbac:	012b6025 */ 	or	$t4,$t1,$t3
/*  f10fbb0:	a06c000b */ 	sb	$t4,0xb($v1)
/*  f10fbb4:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fbb8:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f10fbbc:	3c01800a */ 	lui	$at,0x800a
/*  f10fbc0:	ac222210 */ 	sw	$v0,0x2210($at)
/*  f10fbc4:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fbc8:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fbcc:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f10fbd0:	3c03800a */ 	lui	$v1,0x800a
/*  f10fbd4:	24632200 */ 	addiu	$v1,$v1,0x2200
/*  f10fbd8:	906f000b */ 	lbu	$t7,0xb($v1)
/*  f10fbdc:	304e0007 */ 	andi	$t6,$v0,0x7
/*  f10fbe0:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fbe4:	31f8fff8 */ 	andi	$t8,$t7,0xfff8
/*  f10fbe8:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f10fbec:	a079000b */ 	sb	$t9,0xb($v1)
/*  f10fbf0:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fbf4:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f10fbf8:	3c01800a */ 	lui	$at,0x800a
/*  f10fbfc:	a022220c */ 	sb	$v0,0x220c($at)
/*  f10fc00:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fc04:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fc08:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f10fc0c:	00022880 */ 	sll	$a1,$v0,0x2
/*  f10fc10:	2ca100fc */ 	sltiu	$at,$a1,0xfc
/*  f10fc14:	54200003 */ 	bnezl	$at,.L0f10fc24
/*  f10fc18:	00a02025 */ 	or	$a0,$a1,$zero
/*  f10fc1c:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f10fc20:	00a02025 */ 	or	$a0,$a1,$zero
.L0f10fc24:
/*  f10fc24:	000441c0 */ 	sll	$t0,$a0,0x7
/*  f10fc28:	0c003a87 */ 	jal	audioSetSfxVolume
/*  f10fc2c:	3104ffff */ 	andi	$a0,$t0,0xffff
/*  f10fc30:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fc34:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fc38:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f10fc3c:	00022880 */ 	sll	$a1,$v0,0x2
/*  f10fc40:	2ca100fc */ 	sltiu	$at,$a1,0xfc
/*  f10fc44:	54200003 */ 	bnezl	$at,.L0f10fc54
/*  f10fc48:	00a02025 */ 	or	$a0,$a1,$zero
/*  f10fc4c:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f10fc50:	00a02025 */ 	or	$a0,$a1,$zero
.L0f10fc54:
/*  f10fc54:	000449c0 */ 	sll	$t1,$a0,0x7
/*  f10fc58:	0fc54bdc */ 	jal	optionsSetMusicVolume
/*  f10fc5c:	3124ffff */ 	andi	$a0,$t1,0xffff
/*  f10fc60:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fc64:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fc68:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f10fc6c:	0c003ce3 */ 	jal	audioSetSoundMode
/*  f10fc70:	00402025 */ 	or	$a0,$v0,$zero
/*  f10fc74:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fc78:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fc7c:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f10fc80:	02202025 */ 	or	$a0,$s1,$zero
/*  f10fc84:	0fc549cb */ 	jal	optionsSetControlMode
/*  f10fc88:	00402825 */ 	or	$a1,$v0,$zero
/*  f10fc8c:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fc90:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fc94:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f10fc98:	02402025 */ 	or	$a0,$s2,$zero
/*  f10fc9c:	0fc549cb */ 	jal	optionsSetControlMode
/*  f10fca0:	00402825 */ 	or	$a1,$v0,$zero
/*  f10fca4:	3c10800a */ 	lui	$s0,0x800a
/*  f10fca8:	3c11800a */ 	lui	$s1,0x800a
/*  f10fcac:	2631220a */ 	addiu	$s1,$s1,0x220a
/*  f10fcb0:	26102200 */ 	addiu	$s0,$s0,0x2200
.L0f10fcb4:
/*  f10fcb4:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fcb8:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fcbc:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f10fcc0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10fcc4:	0211082b */ 	sltu	$at,$s0,$s1
/*  f10fcc8:	1420fffa */ 	bnez	$at,.L0f10fcb4
/*  f10fccc:	a2020013 */ 	sb	$v0,0x13($s0)
/*  f10fcd0:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fcd4:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fcd8:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f10fcdc:	3c01800a */ 	lui	$at,0x800a
/*  f10fce0:	3c13800a */ 	lui	$s3,0x800a
/*  f10fce4:	a422221e */ 	sh	$v0,0x221e($at)
/*  f10fce8:	26732200 */ 	addiu	$s3,$s3,0x2200
/*  f10fcec:	24120003 */ 	addiu	$s2,$zero,0x3
/*  f10fcf0:	00008025 */ 	or	$s0,$zero,$zero
.L0f10fcf4:
/*  f10fcf4:	02608825 */ 	or	$s1,$s3,$zero
.L0f10fcf8:
/*  f10fcf8:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fcfc:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fd00:	2405000c */ 	addiu	$a1,$zero,0xc
/*  f10fd04:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10fd08:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f10fd0c:	1612fffa */ 	bne	$s0,$s2,.L0f10fcf8
/*  f10fd10:	a622001e */ 	sh	$v0,0x1e($s1)
/*  f10fd14:	3c0c800a */ 	lui	$t4,0x800a
/*  f10fd18:	258c227e */ 	addiu	$t4,$t4,0x227e
/*  f10fd1c:	26730006 */ 	addiu	$s3,$s3,0x6
/*  f10fd20:	026c082b */ 	sltu	$at,$s3,$t4
/*  f10fd24:	5420fff3 */ 	bnezl	$at,.L0f10fcf4
/*  f10fd28:	00008025 */ 	or	$s0,$zero,$zero
/*  f10fd2c:	00008825 */ 	or	$s1,$zero,$zero
/*  f10fd30:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f10fd34:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f10fd38:
/*  f10fd38:	02802025 */ 	or	$a0,$s4,$zero
.L0f10fd3c:
/*  f10fd3c:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fd40:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f10fd44:	02202025 */ 	or	$a0,$s1,$zero
/*  f10fd48:	02002825 */ 	or	$a1,$s0,$zero
/*  f10fd4c:	0fc67103 */ 	jal	mpSetChallengeCompletedByAnyChrWithNumPlayers
/*  f10fd50:	00403025 */ 	or	$a2,$v0,$zero
/*  f10fd54:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10fd58:	5612fff8 */ 	bnel	$s0,$s2,.L0f10fd3c
/*  f10fd5c:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fd60:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f10fd64:	2a21001e */ 	slti	$at,$s1,0x1e
/*  f10fd68:	5420fff3 */ 	bnezl	$at,.L0f10fd38
/*  f10fd6c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f10fd70:	0fc66bf7 */ 	jal	func0f19afdc
/*  f10fd74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10fd78:	3c10800a */ 	lui	$s0,0x800a
/*  f10fd7c:	3c11800a */ 	lui	$s1,0x800a
/*  f10fd80:	2631220c */ 	addiu	$s1,$s1,0x220c
/*  f10fd84:	26102200 */ 	addiu	$s0,$s0,0x2200
.L0f10fd88:
/*  f10fd88:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fd8c:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fd90:	24050015 */ 	addiu	$a1,$zero,0x15
/*  f10fd94:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f10fd98:	0211082b */ 	sltu	$at,$s0,$s1
/*  f10fd9c:	1420fffa */ 	bnez	$at,.L0f10fd88
/*  f10fda0:	ae02009c */ 	sw	$v0,0x9c($s0)
/*  f10fda4:	3c10800a */ 	lui	$s0,0x800a
/*  f10fda8:	3c12800a */ 	lui	$s2,0x800a
/*  f10fdac:	3c11800a */ 	lui	$s1,0x800a
/*  f10fdb0:	26312208 */ 	addiu	$s1,$s1,0x2208
/*  f10fdb4:	26522209 */ 	addiu	$s2,$s2,0x2209
/*  f10fdb8:	26102200 */ 	addiu	$s0,$s0,0x2200
.L0f10fdbc:
/*  f10fdbc:	16110003 */ 	bne	$s0,$s1,.L0f10fdcc
/*  f10fdc0:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f10fdc4:	10000001 */ 	beqz	$zero,.L0f10fdcc
/*  f10fdc8:	24050002 */ 	addiu	$a1,$zero,0x2
.L0f10fdcc:
/*  f10fdcc:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fdd0:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fdd4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10fdd8:	0212082b */ 	sltu	$at,$s0,$s2
/*  f10fddc:	1420fff7 */ 	bnez	$at,.L0f10fdbc
/*  f10fde0:	a20200ab */ 	sb	$v0,0xab($s0)
/*  f10fde4:	3c10800a */ 	lui	$s0,0x800a
/*  f10fde8:	3c11800a */ 	lui	$s1,0x800a
/*  f10fdec:	26312204 */ 	addiu	$s1,$s1,0x2204
/*  f10fdf0:	26102200 */ 	addiu	$s0,$s0,0x2200
.L0f10fdf4:
/*  f10fdf4:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fdf8:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f10fdfc:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f10fe00:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f10fe04:	1611fffb */ 	bne	$s0,$s1,.L0f10fdf4
/*  f10fe08:	a20200b4 */ 	sb	$v0,0xb4($s0)
/*  f10fe0c:	3c10800a */ 	lui	$s0,0x800a
/*  f10fe10:	26102214 */ 	addiu	$s0,$s0,0x2214
/*  f10fe14:	02002825 */ 	or	$a1,$s0,$zero
/*  f10fe18:	0fc47961 */ 	jal	func0f11e584
/*  f10fe1c:	24040041 */ 	addiu	$a0,$zero,0x41
/*  f10fe20:	50400004 */ 	beqzl	$v0,.L0f10fe34
/*  f10fe24:	24040042 */ 	addiu	$a0,$zero,0x42
/*  f10fe28:	0fc672ce */ 	jal	func0f19cb38
/*  f10fe2c:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f10fe30:	24040042 */ 	addiu	$a0,$zero,0x42
.L0f10fe34:
/*  f10fe34:	0fc47961 */ 	jal	func0f11e584
/*  f10fe38:	02002825 */ 	or	$a1,$s0,$zero
/*  f10fe3c:	50400004 */ 	beqzl	$v0,.L0f10fe50
/*  f10fe40:	24040043 */ 	addiu	$a0,$zero,0x43
/*  f10fe44:	0fc672ce */ 	jal	func0f19cb38
/*  f10fe48:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f10fe4c:	24040043 */ 	addiu	$a0,$zero,0x43
.L0f10fe50:
/*  f10fe50:	0fc47961 */ 	jal	func0f11e584
/*  f10fe54:	02002825 */ 	or	$a1,$s0,$zero
/*  f10fe58:	10400003 */ 	beqz	$v0,.L0f10fe68
/*  f10fe5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f10fe60:	0fc672ce */ 	jal	func0f19cb38
/*  f10fe64:	24040022 */ 	addiu	$a0,$zero,0x22
.L0f10fe68:
/*  f10fe68:	0fc35531 */ 	jal	func0f0d54c4
/*  f10fe6c:	02802025 */ 	or	$a0,$s4,$zero
/*  f10fe70:	3c04800a */ 	lui	$a0,0x800a
/*  f10fe74:	0fc43c81 */ 	jal	func0f10f204
/*  f10fe78:	24842200 */ 	addiu	$a0,$a0,0x2200
/*  f10fe7c:	10000003 */ 	beqz	$zero,.L0f10fe8c
/*  f10fe80:	00001025 */ 	or	$v0,$zero,$zero
.L0f10fe84:
/*  f10fe84:	10000001 */ 	beqz	$zero,.L0f10fe8c
/*  f10fe88:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f10fe8c:
/*  f10fe8c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f10fe90:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f10fe94:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f10fe98:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f10fe9c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f10fea0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f10fea4:	03e00008 */ 	jr	$ra
/*  f10fea8:	27bd0140 */ 	addiu	$sp,$sp,0x140
);

GLOBAL_ASM(
glabel func0f10feac
/*  f10feac:	27bdfeb8 */ 	addiu	$sp,$sp,-328
/*  f10feb0:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f10feb4:	3c14800a */ 	lui	$s4,%hi(g_Vars)
/*  f10feb8:	26949fc0 */ 	addiu	$s4,$s4,%lo(g_Vars)
/*  f10febc:	8e820298 */ 	lw	$v0,0x298($s4)
/*  f10fec0:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f10fec4:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f10fec8:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f10fecc:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f10fed0:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f10fed4:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f10fed8:	afa40148 */ 	sw	$a0,0x148($sp)
/*  f10fedc:	afa5014c */ 	sw	$a1,0x14c($sp)
/*  f10fee0:	04410005 */ 	bgez	$v0,.L0f10fef8
/*  f10fee4:	afa60150 */ 	sw	$a2,0x150($sp)
/*  f10fee8:	8e8e029c */ 	lw	$t6,0x29c($s4)
/*  f10feec:	24130004 */ 	addiu	$s3,$zero,0x4
/*  f10fef0:	05c00003 */ 	bltz	$t6,.L0f10ff00
/*  f10fef4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10fef8:
/*  f10fef8:	10000001 */ 	beqz	$zero,.L0f10ff00
/*  f10fefc:	00009825 */ 	or	$s3,$zero,$zero
.L0f10ff00:
/*  f10ff00:	04410005 */ 	bgez	$v0,.L0f10ff18
/*  f10ff04:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f10ff08:	8e8f029c */ 	lw	$t7,0x29c($s4)
/*  f10ff0c:	24110005 */ 	addiu	$s1,$zero,0x5
/*  f10ff10:	05e00003 */ 	bltz	$t7,.L0f10ff20
/*  f10ff14:	00000000 */ 	sll	$zero,$zero,0x0
.L0f10ff18:
/*  f10ff18:	10000001 */ 	beqz	$zero,.L0f10ff20
/*  f10ff1c:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f10ff20:
/*  f10ff20:	3c018007 */ 	lui	$at,0x8007
/*  f10ff24:	ac325bd0 */ 	sw	$s2,0x5bd0($at)
/*  f10ff28:	0fc549e0 */ 	jal	optionsGetForwardPitch
/*  f10ff2c:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ff30:	3c10800a */ 	lui	$s0,0x800a
/*  f10ff34:	26102214 */ 	addiu	$s0,$s0,0x2214
/*  f10ff38:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ff3c:	00002025 */ 	or	$a0,$zero,$zero
/*  f10ff40:	0fc4794c */ 	jal	func0f11e530
/*  f10ff44:	00403025 */ 	or	$a2,$v0,$zero
/*  f10ff48:	0fc549e9 */ 	jal	optionsGetAutoAim
/*  f10ff4c:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ff50:	02402025 */ 	or	$a0,$s2,$zero
/*  f10ff54:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ff58:	0fc4794c */ 	jal	func0f11e530
/*  f10ff5c:	00403025 */ 	or	$a2,$v0,$zero
/*  f10ff60:	0fc549fb */ 	jal	optionsGetAimControl
/*  f10ff64:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ff68:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f10ff6c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ff70:	0fc4794c */ 	jal	func0f11e530
/*  f10ff74:	00403025 */ 	or	$a2,$v0,$zero
/*  f10ff78:	0fc54a04 */ 	jal	optionsGetSightOnScreen
/*  f10ff7c:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ff80:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f10ff84:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ff88:	0fc4794c */ 	jal	func0f11e530
/*  f10ff8c:	00403025 */ 	or	$a2,$v0,$zero
/*  f10ff90:	0fc549f2 */ 	jal	optionsGetLookAhead
/*  f10ff94:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ff98:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f10ff9c:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ffa0:	0fc4794c */ 	jal	func0f11e530
/*  f10ffa4:	00403025 */ 	or	$a2,$v0,$zero
/*  f10ffa8:	0fc54a0d */ 	jal	optionsGetAmmoOnScreen
/*  f10ffac:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ffb0:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f10ffb4:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ffb8:	0fc4794c */ 	jal	func0f11e530
/*  f10ffbc:	00403025 */ 	or	$a2,$v0,$zero
/*  f10ffc0:	0fc54a49 */ 	jal	optionsGetHeadRoll
/*  f10ffc4:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ffc8:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f10ffcc:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ffd0:	0fc4794c */ 	jal	func0f11e530
/*  f10ffd4:	00403025 */ 	or	$a2,$v0,$zero
/*  f10ffd8:	0fc54a16 */ 	jal	optionsGetShowGunFunction
/*  f10ffdc:	02602025 */ 	or	$a0,$s3,$zero
/*  f10ffe0:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f10ffe4:	02002825 */ 	or	$a1,$s0,$zero
/*  f10ffe8:	0fc4794c */ 	jal	func0f11e530
/*  f10ffec:	00403025 */ 	or	$a2,$v0,$zero
/*  f10fff0:	0fc54a1f */ 	jal	optionsGetAlwaysShowTarget
/*  f10fff4:	02602025 */ 	or	$a0,$s3,$zero
/*  f10fff8:	24040015 */ 	addiu	$a0,$zero,0x15
/*  f10fffc:	02002825 */ 	or	$a1,$s0,$zero
/*  f110000:	0fc4794c */ 	jal	func0f11e530
/*  f110004:	00403025 */ 	or	$a2,$v0,$zero
/*  f110008:	0fc54a28 */ 	jal	optionsGetShowZoomRange
/*  f11000c:	02602025 */ 	or	$a0,$s3,$zero
/*  f110010:	24040017 */ 	addiu	$a0,$zero,0x17
/*  f110014:	02002825 */ 	or	$a1,$s0,$zero
/*  f110018:	0fc4794c */ 	jal	func0f11e530
/*  f11001c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110020:	0fc54a3a */ 	jal	optionsGetShowMissionTime
/*  f110024:	02602025 */ 	or	$a0,$s3,$zero
/*  f110028:	2404001a */ 	addiu	$a0,$zero,0x1a
/*  f11002c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110030:	0fc4794c */ 	jal	func0f11e530
/*  f110034:	00403025 */ 	or	$a2,$v0,$zero
/*  f110038:	0fc54a31 */ 	jal	optionsGetPaintball
/*  f11003c:	02602025 */ 	or	$a0,$s3,$zero
/*  f110040:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f110044:	02002825 */ 	or	$a1,$s0,$zero
/*  f110048:	0fc4794c */ 	jal	func0f11e530
/*  f11004c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110050:	0fc549e0 */ 	jal	optionsGetForwardPitch
/*  f110054:	02202025 */ 	or	$a0,$s1,$zero
/*  f110058:	2404000c */ 	addiu	$a0,$zero,0xc
/*  f11005c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110060:	0fc4794c */ 	jal	func0f11e530
/*  f110064:	00403025 */ 	or	$a2,$v0,$zero
/*  f110068:	0fc549e9 */ 	jal	optionsGetAutoAim
/*  f11006c:	02202025 */ 	or	$a0,$s1,$zero
/*  f110070:	2404000d */ 	addiu	$a0,$zero,0xd
/*  f110074:	02002825 */ 	or	$a1,$s0,$zero
/*  f110078:	0fc4794c */ 	jal	func0f11e530
/*  f11007c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110080:	0fc549fb */ 	jal	optionsGetAimControl
/*  f110084:	02202025 */ 	or	$a0,$s1,$zero
/*  f110088:	2404000e */ 	addiu	$a0,$zero,0xe
/*  f11008c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110090:	0fc4794c */ 	jal	func0f11e530
/*  f110094:	00403025 */ 	or	$a2,$v0,$zero
/*  f110098:	0fc54a04 */ 	jal	optionsGetSightOnScreen
/*  f11009c:	02202025 */ 	or	$a0,$s1,$zero
/*  f1100a0:	2404000f */ 	addiu	$a0,$zero,0xf
/*  f1100a4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1100a8:	0fc4794c */ 	jal	func0f11e530
/*  f1100ac:	00403025 */ 	or	$a2,$v0,$zero
/*  f1100b0:	0fc549f2 */ 	jal	optionsGetLookAhead
/*  f1100b4:	02202025 */ 	or	$a0,$s1,$zero
/*  f1100b8:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f1100bc:	02002825 */ 	or	$a1,$s0,$zero
/*  f1100c0:	0fc4794c */ 	jal	func0f11e530
/*  f1100c4:	00403025 */ 	or	$a2,$v0,$zero
/*  f1100c8:	0fc54a0d */ 	jal	optionsGetAmmoOnScreen
/*  f1100cc:	02202025 */ 	or	$a0,$s1,$zero
/*  f1100d0:	24040011 */ 	addiu	$a0,$zero,0x11
/*  f1100d4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1100d8:	0fc4794c */ 	jal	func0f11e530
/*  f1100dc:	00403025 */ 	or	$a2,$v0,$zero
/*  f1100e0:	0fc54a49 */ 	jal	optionsGetHeadRoll
/*  f1100e4:	02202025 */ 	or	$a0,$s1,$zero
/*  f1100e8:	24040012 */ 	addiu	$a0,$zero,0x12
/*  f1100ec:	02002825 */ 	or	$a1,$s0,$zero
/*  f1100f0:	0fc4794c */ 	jal	func0f11e530
/*  f1100f4:	00403025 */ 	or	$a2,$v0,$zero
/*  f1100f8:	0fc54a16 */ 	jal	optionsGetShowGunFunction
/*  f1100fc:	02202025 */ 	or	$a0,$s1,$zero
/*  f110100:	24040013 */ 	addiu	$a0,$zero,0x13
/*  f110104:	02002825 */ 	or	$a1,$s0,$zero
/*  f110108:	0fc4794c */ 	jal	func0f11e530
/*  f11010c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110110:	0fc54a1f */ 	jal	optionsGetAlwaysShowTarget
/*  f110114:	02202025 */ 	or	$a0,$s1,$zero
/*  f110118:	24040016 */ 	addiu	$a0,$zero,0x16
/*  f11011c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110120:	0fc4794c */ 	jal	func0f11e530
/*  f110124:	00403025 */ 	or	$a2,$v0,$zero
/*  f110128:	0fc54a28 */ 	jal	optionsGetShowZoomRange
/*  f11012c:	02202025 */ 	or	$a0,$s1,$zero
/*  f110130:	24040018 */ 	addiu	$a0,$zero,0x18
/*  f110134:	02002825 */ 	or	$a1,$s0,$zero
/*  f110138:	0fc4794c */ 	jal	func0f11e530
/*  f11013c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110140:	0fc54a3a */ 	jal	optionsGetShowMissionTime
/*  f110144:	02202025 */ 	or	$a0,$s1,$zero
/*  f110148:	2404001b */ 	addiu	$a0,$zero,0x1b
/*  f11014c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110150:	0fc4794c */ 	jal	func0f11e530
/*  f110154:	00403025 */ 	or	$a2,$v0,$zero
/*  f110158:	0fc54a31 */ 	jal	optionsGetPaintball
/*  f11015c:	02202025 */ 	or	$a0,$s1,$zero
/*  f110160:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f110164:	02002825 */ 	or	$a1,$s0,$zero
/*  f110168:	0fc4794c */ 	jal	func0f11e530
/*  f11016c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110170:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f110174:	00000000 */ 	sll	$zero,$zero,0x0
/*  f110178:	24040019 */ 	addiu	$a0,$zero,0x19
/*  f11017c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110180:	0fc4794c */ 	jal	func0f11e530
/*  f110184:	00403025 */ 	or	$a2,$v0,$zero
/*  f110188:	0fc54bc7 */ 	jal	optionsGetScreenRatio
/*  f11018c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f110190:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f110194:	02002825 */ 	or	$a1,$s0,$zero
/*  f110198:	0fc4794c */ 	jal	func0f11e530
/*  f11019c:	00403025 */ 	or	$a2,$v0,$zero
/*  f1101a0:	0fc54bc1 */ 	jal	optionsGetScreenSize
/*  f1101a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1101a8:	00523026 */ 	xor	$a2,$v0,$s2
/*  f1101ac:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f1101b0:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f1101b4:	0fc4794c */ 	jal	func0f11e530
/*  f1101b8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1101bc:	0fc54bc1 */ 	jal	optionsGetScreenSize
/*  f1101c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1101c4:	24150002 */ 	addiu	$s5,$zero,0x2
/*  f1101c8:	00553026 */ 	xor	$a2,$v0,$s5
/*  f1101cc:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f1101d0:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f1101d4:	0fc4794c */ 	jal	func0f11e530
/*  f1101d8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1101dc:	3c188007 */ 	lui	$t8,0x8007
/*  f1101e0:	8f1806c8 */ 	lw	$t8,0x6c8($t8)
/*  f1101e4:	24040022 */ 	addiu	$a0,$zero,0x22
/*  f1101e8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1101ec:	02583026 */ 	xor	$a2,$s2,$t8
/*  f1101f0:	0fc4794c */ 	jal	func0f11e530
/*  f1101f4:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f1101f8:	0fc54a43 */ 	jal	optionsGetInGameSubtitles
/*  f1101fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f110200:	2404000b */ 	addiu	$a0,$zero,0xb
/*  f110204:	02002825 */ 	or	$a1,$s0,$zero
/*  f110208:	0fc4794c */ 	jal	func0f11e530
/*  f11020c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110210:	0fc54a46 */ 	jal	optionsGetCutsceneSubtitles
/*  f110214:	00000000 */ 	sll	$zero,$zero,0x0
/*  f110218:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f11021c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110220:	0fc4794c */ 	jal	func0f11e530
/*  f110224:	00403025 */ 	or	$a2,$v0,$zero
/*  f110228:	24040040 */ 	addiu	$a0,$zero,0x40
/*  f11022c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110230:	0fc4794c */ 	jal	func0f11e530
/*  f110234:	928604e3 */ 	lbu	$a2,0x4e3($s4)
/*  f110238:	0fc672b5 */ 	jal	func0f19cad4
/*  f11023c:	24040020 */ 	addiu	$a0,$zero,0x20
/*  f110240:	24040041 */ 	addiu	$a0,$zero,0x41
/*  f110244:	02002825 */ 	or	$a1,$s0,$zero
/*  f110248:	0fc4794c */ 	jal	func0f11e530
/*  f11024c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110250:	0fc672b5 */ 	jal	func0f19cad4
/*  f110254:	24040021 */ 	addiu	$a0,$zero,0x21
/*  f110258:	24040042 */ 	addiu	$a0,$zero,0x42
/*  f11025c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110260:	0fc4794c */ 	jal	func0f11e530
/*  f110264:	00403025 */ 	or	$a2,$v0,$zero
/*  f110268:	0fc672b5 */ 	jal	func0f19cad4
/*  f11026c:	24040022 */ 	addiu	$a0,$zero,0x22
/*  f110270:	24040043 */ 	addiu	$a0,$zero,0x43
/*  f110274:	02002825 */ 	or	$a1,$s0,$zero
/*  f110278:	0fc4794c */ 	jal	func0f11e530
/*  f11027c:	00403025 */ 	or	$a2,$v0,$zero
/*  f110280:	0fc54bc1 */ 	jal	optionsGetScreenSize
/*  f110284:	00000000 */ 	sll	$zero,$zero,0x0
/*  f110288:	50400002 */ 	beqzl	$v0,.L0f110294
/*  f11028c:	8e990450 */ 	lw	$t9,0x450($s4)
/*  f110290:	8e990450 */ 	lw	$t9,0x450($s4)
.L0f110294:
/*  f110294:	2404001f */ 	addiu	$a0,$zero,0x1f
/*  f110298:	02002825 */ 	or	$a1,$s0,$zero
/*  f11029c:	02593026 */ 	xor	$a2,$s2,$t9
/*  f1102a0:	0fc4794c */ 	jal	func0f11e530
/*  f1102a4:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f1102a8:	8e880448 */ 	lw	$t0,0x448($s4)
/*  f1102ac:	2404001c */ 	addiu	$a0,$zero,0x1c
/*  f1102b0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1102b4:	02483026 */ 	xor	$a2,$s2,$t0
/*  f1102b8:	0fc4794c */ 	jal	func0f11e530
/*  f1102bc:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f1102c0:	8e890454 */ 	lw	$t1,0x454($s4)
/*  f1102c4:	2404001d */ 	addiu	$a0,$zero,0x1d
/*  f1102c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1102cc:	02493026 */ 	xor	$a2,$s2,$t1
/*  f1102d0:	0fc4794c */ 	jal	func0f11e530
/*  f1102d4:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f1102d8:	8e8a044c */ 	lw	$t2,0x44c($s4)
/*  f1102dc:	2404001e */ 	addiu	$a0,$zero,0x1e
/*  f1102e0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1102e4:	024a3026 */ 	xor	$a2,$s2,$t2
/*  f1102e8:	0fc4794c */ 	jal	func0f11e530
/*  f1102ec:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f1102f0:	8fab0148 */ 	lw	$t3,0x148($sp)
/*  f1102f4:	27b4004c */ 	addiu	$s4,$sp,0x4c
/*  f1102f8:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f1102fc:	056000b6 */ 	bltz	$t3,.L0f1105d8
/*  f110300:	00000000 */ 	sll	$zero,$zero,0x0
/*  f110304:	0fc35517 */ 	jal	func0f0d545c
/*  f110308:	02802025 */ 	or	$a0,$s4,$zero
/*  f11030c:	3c12800a */ 	lui	$s2,0x800a
/*  f110310:	26522200 */ 	addiu	$s2,$s2,0x2200
/*  f110314:	02402825 */ 	or	$a1,$s2,$zero
/*  f110318:	0fc35569 */ 	jal	func0f0d55a4
/*  f11031c:	02802025 */ 	or	$a0,$s4,$zero
/*  f110320:	9245000b */ 	lbu	$a1,0xb($s2)
/*  f110324:	02802025 */ 	or	$a0,$s4,$zero
/*  f110328:	24060005 */ 	addiu	$a2,$zero,0x5
/*  f11032c:	000560c2 */ 	srl	$t4,$a1,0x3
/*  f110330:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f110334:	01802825 */ 	or	$a1,$t4,$zero
/*  f110338:	02802025 */ 	or	$a0,$s4,$zero
/*  f11033c:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f110340:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f110344:	24060020 */ 	addiu	$a2,$zero,0x20
/*  f110348:	8e450008 */ 	lw	$a1,0x8($s2)
/*  f11034c:	02802025 */ 	or	$a0,$s4,$zero
/*  f110350:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f110354:	30ad0007 */ 	andi	$t5,$a1,0x7
/*  f110358:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f11035c:	01a02825 */ 	or	$a1,$t5,$zero
/*  f110360:	02802025 */ 	or	$a0,$s4,$zero
/*  f110364:	9245000c */ 	lbu	$a1,0xc($s2)
/*  f110368:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f11036c:	24060005 */ 	addiu	$a2,$zero,0x5
/*  f110370:	3c028006 */ 	lui	$v0,0x8006
/*  f110374:	9442ddc8 */ 	lhu	$v0,-0x2238($v0)
/*  f110378:	02802025 */ 	or	$a0,$s4,$zero
/*  f11037c:	24060006 */ 	addiu	$a2,$zero,0x6
/*  f110380:	28415001 */ 	slti	$at,$v0,0x5001
/*  f110384:	54200004 */ 	bnezl	$at,.L0f110398
/*  f110388:	00403825 */ 	or	$a3,$v0,$zero
/*  f11038c:	10000002 */ 	beqz	$zero,.L0f110398
/*  f110390:	24075000 */ 	addiu	$a3,$zero,0x5000
/*  f110394:	00403825 */ 	or	$a3,$v0,$zero
.L0f110398:
/*  f110398:	000729c3 */ 	sra	$a1,$a3,0x7
/*  f11039c:	00057082 */ 	srl	$t6,$a1,0x2
/*  f1103a0:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f1103a4:	01c02825 */ 	or	$a1,$t6,$zero
/*  f1103a8:	0fc54bd4 */ 	jal	optionsGetMusicVolume
/*  f1103ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1103b0:	000229c3 */ 	sra	$a1,$v0,0x7
/*  f1103b4:	00057882 */ 	srl	$t7,$a1,0x2
/*  f1103b8:	01e02825 */ 	or	$a1,$t7,$zero
/*  f1103bc:	02802025 */ 	or	$a0,$s4,$zero
/*  f1103c0:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f1103c4:	24060006 */ 	addiu	$a2,$zero,0x6
/*  f1103c8:	3c058006 */ 	lui	$a1,0x8006
/*  f1103cc:	8ca5ddcc */ 	lw	$a1,-0x2234($a1)
/*  f1103d0:	02802025 */ 	or	$a0,$s4,$zero
/*  f1103d4:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f1103d8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f1103dc:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f1103e0:	02602025 */ 	or	$a0,$s3,$zero
/*  f1103e4:	02802025 */ 	or	$a0,$s4,$zero
/*  f1103e8:	00402825 */ 	or	$a1,$v0,$zero
/*  f1103ec:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f1103f0:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f1103f4:	0fc549c4 */ 	jal	optionsGetControlMode
/*  f1103f8:	02202025 */ 	or	$a0,$s1,$zero
/*  f1103fc:	02802025 */ 	or	$a0,$s4,$zero
/*  f110400:	00402825 */ 	or	$a1,$v0,$zero
/*  f110404:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f110408:	24060003 */ 	addiu	$a2,$zero,0x3
/*  f11040c:	3c10800a */ 	lui	$s0,0x800a
/*  f110410:	3c11800a */ 	lui	$s1,0x800a
/*  f110414:	2631220a */ 	addiu	$s1,$s1,0x220a
/*  f110418:	26102200 */ 	addiu	$s0,$s0,0x2200
/*  f11041c:	02802025 */ 	or	$a0,$s4,$zero
.L0f110420:
/*  f110420:	92050014 */ 	lbu	$a1,0x14($s0)
/*  f110424:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f110428:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f11042c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f110430:	0211082b */ 	sltu	$at,$s0,$s1
/*  f110434:	5420fffa */ 	bnezl	$at,.L0f110420
/*  f110438:	02802025 */ 	or	$a0,$s4,$zero
/*  f11043c:	02802025 */ 	or	$a0,$s4,$zero
/*  f110440:	9645001e */ 	lhu	$a1,0x1e($s2)
/*  f110444:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f110448:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f11044c:	3c15800a */ 	lui	$s5,0x800a
/*  f110450:	26b52200 */ 	addiu	$s5,$s5,0x2200
/*  f110454:	24130006 */ 	addiu	$s3,$zero,0x6
/*  f110458:	00008825 */ 	or	$s1,$zero,$zero
.L0f11045c:
/*  f11045c:	02a09025 */ 	or	$s2,$s5,$zero
.L0f110460:
/*  f110460:	02802025 */ 	or	$a0,$s4,$zero
/*  f110464:	96450020 */ 	lhu	$a1,0x20($s2)
/*  f110468:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f11046c:	2406000c */ 	addiu	$a2,$zero,0xc
/*  f110470:	26310002 */ 	addiu	$s1,$s1,0x2
/*  f110474:	1633fffa */ 	bne	$s1,$s3,.L0f110460
/*  f110478:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f11047c:	3c18800a */ 	lui	$t8,0x800a
/*  f110480:	2718227e */ 	addiu	$t8,$t8,0x227e
/*  f110484:	26b50006 */ 	addiu	$s5,$s5,0x6
/*  f110488:	02b8082b */ 	sltu	$at,$s5,$t8
/*  f11048c:	5420fff3 */ 	bnezl	$at,.L0f11045c
/*  f110490:	00008825 */ 	or	$s1,$zero,$zero
/*  f110494:	00008825 */ 	or	$s1,$zero,$zero
/*  f110498:	24120005 */ 	addiu	$s2,$zero,0x5
/*  f11049c:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f1104a0:
/*  f1104a0:	02202025 */ 	or	$a0,$s1,$zero
.L0f1104a4:
/*  f1104a4:	0fc670f7 */ 	jal	mpIsChallengeCompletedByAnyChrWithNumPlayers
/*  f1104a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1104ac:	02802025 */ 	or	$a0,$s4,$zero
/*  f1104b0:	00402825 */ 	or	$a1,$v0,$zero
/*  f1104b4:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f1104b8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1104bc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1104c0:	5612fff8 */ 	bnel	$s0,$s2,.L0f1104a4
/*  f1104c4:	02202025 */ 	or	$a0,$s1,$zero
/*  f1104c8:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1104cc:	2a21001e */ 	slti	$at,$s1,0x1e
/*  f1104d0:	5420fff3 */ 	bnezl	$at,.L0f1104a0
/*  f1104d4:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f1104d8:	3c10800a */ 	lui	$s0,0x800a
/*  f1104dc:	3c11800a */ 	lui	$s1,0x800a
/*  f1104e0:	2631220c */ 	addiu	$s1,$s1,0x220c
/*  f1104e4:	26102200 */ 	addiu	$s0,$s0,0x2200
/*  f1104e8:	02802025 */ 	or	$a0,$s4,$zero
.L0f1104ec:
/*  f1104ec:	8e0500a0 */ 	lw	$a1,0xa0($s0)
/*  f1104f0:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f1104f4:	24060015 */ 	addiu	$a2,$zero,0x15
/*  f1104f8:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f1104fc:	0211082b */ 	sltu	$at,$s0,$s1
/*  f110500:	5420fffa */ 	bnezl	$at,.L0f1104ec
/*  f110504:	02802025 */ 	or	$a0,$s4,$zero
/*  f110508:	3c10800a */ 	lui	$s0,0x800a
/*  f11050c:	3c12800a */ 	lui	$s2,0x800a
/*  f110510:	3c11800a */ 	lui	$s1,0x800a
/*  f110514:	26312208 */ 	addiu	$s1,$s1,0x2208
/*  f110518:	26522209 */ 	addiu	$s2,$s2,0x2209
/*  f11051c:	26102200 */ 	addiu	$s0,$s0,0x2200
.L0f110520:
/*  f110520:	16110003 */ 	bne	$s0,$s1,.L0f110530
/*  f110524:	02802025 */ 	or	$a0,$s4,$zero
/*  f110528:	10000002 */ 	beqz	$zero,.L0f110534
/*  f11052c:	24070002 */ 	addiu	$a3,$zero,0x2
.L0f110530:
/*  f110530:	24070008 */ 	addiu	$a3,$zero,0x8
.L0f110534:
/*  f110534:	920500ac */ 	lbu	$a1,0xac($s0)
/*  f110538:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f11053c:	00e03025 */ 	or	$a2,$a3,$zero
/*  f110540:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f110544:	0212082b */ 	sltu	$at,$s0,$s2
/*  f110548:	1420fff5 */ 	bnez	$at,.L0f110520
/*  f11054c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f110550:	3c10800a */ 	lui	$s0,0x800a
/*  f110554:	3c11800a */ 	lui	$s1,0x800a
/*  f110558:	26312204 */ 	addiu	$s1,$s1,0x2204
/*  f11055c:	26102200 */ 	addiu	$s0,$s0,0x2200
/*  f110560:	02802025 */ 	or	$a0,$s4,$zero
.L0f110564:
/*  f110564:	920500b5 */ 	lbu	$a1,0xb5($s0)
/*  f110568:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f11056c:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f110570:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f110574:	5611fffb */ 	bnel	$s0,$s1,.L0f110564
/*  f110578:	02802025 */ 	or	$a0,$s4,$zero
/*  f11057c:	0fc35531 */ 	jal	func0f0d54c4
/*  f110580:	02802025 */ 	or	$a0,$s4,$zero
/*  f110584:	27b90140 */ 	addiu	$t9,$sp,0x140
/*  f110588:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f11058c:	83a4014b */ 	lb	$a0,0x14b($sp)
/*  f110590:	8fa5014c */ 	lw	$a1,0x14c($sp)
/*  f110594:	24060080 */ 	addiu	$a2,$zero,0x80
/*  f110598:	27a70050 */ 	addiu	$a3,$sp,0x50
/*  f11059c:	0fc45a0a */ 	jal	func0f116828
/*  f1105a0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1105a4:	3c01800a */ 	lui	$at,0x800a
/*  f1105a8:	14400009 */ 	bnez	$v0,.L0f1105d0
/*  f1105ac:	ac2221f8 */ 	sw	$v0,0x21f8($at)
/*  f1105b0:	8fa80140 */ 	lw	$t0,0x140($sp)
/*  f1105b4:	97a90152 */ 	lhu	$t1,0x152($sp)
/*  f1105b8:	3c03800a */ 	lui	$v1,%hi(var800a22c0)
/*  f1105bc:	246322c0 */ 	addiu	$v1,$v1,%lo(var800a22c0)
/*  f1105c0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1105c4:	ac680000 */ 	sw	$t0,0x0($v1)
/*  f1105c8:	10000003 */ 	beqz	$zero,.L0f1105d8
/*  f1105cc:	a4690004 */ 	sh	$t1,0x4($v1)
.L0f1105d0:
/*  f1105d0:	10000001 */ 	beqz	$zero,.L0f1105d8
/*  f1105d4:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f1105d8:
/*  f1105d8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1105dc:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f1105e0:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f1105e4:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f1105e8:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f1105ec:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f1105f0:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f1105f4:	03e00008 */ 	jr	$ra
/*  f1105f8:	27bd0148 */ 	addiu	$sp,$sp,0x148
);

GLOBAL_ASM(
glabel func0f1105fc
/*  f1105fc:	27bdff08 */ 	addiu	$sp,$sp,-248
/*  f110600:	afa500fc */ 	sw	$a1,0xfc($sp)
/*  f110604:	00802825 */ 	or	$a1,$a0,$zero
/*  f110608:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11060c:	afa400f8 */ 	sw	$a0,0xf8($sp)
/*  f110610:	afa60100 */ 	sw	$a2,0x100($sp)
/*  f110614:	afa70104 */ 	sw	$a3,0x104($sp)
/*  f110618:	2406000f */ 	addiu	$a2,$zero,0xf
/*  f11061c:	0fc35521 */ 	jal	func0f0d5484
/*  f110620:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f110624:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f110628:	8fa500fc */ 	lw	$a1,0xfc($sp)
/*  f11062c:	0fc35539 */ 	jal	func0f0d54e4
/*  f110630:	00003025 */ 	or	$a2,$zero,$zero
/*  f110634:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f110638:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f11063c:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f110640:	8fae0100 */ 	lw	$t6,0x100($sp)
/*  f110644:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f110648:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f11064c:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f110650:	a1c20000 */ 	sb	$v0,0x0($t6)
/*  f110654:	8faf0108 */ 	lw	$t7,0x108($sp)
/*  f110658:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f11065c:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f110660:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f110664:	ade20000 */ 	sw	$v0,0x0($t7)
/*  f110668:	8fb80104 */ 	lw	$t8,0x104($sp)
/*  f11066c:	a3020000 */ 	sb	$v0,0x0($t8)
/*  f110670:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f110674:	27bd00f8 */ 	addiu	$sp,$sp,0xf8
/*  f110678:	03e00008 */ 	jr	$ra
/*  f11067c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f110680:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f110684:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f110688:	0fc442da */ 	jal	func0f110b68
/*  f11068c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f110690:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f110694:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f110698:	03e00008 */ 	jr	$ra
/*  f11069c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1106a0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1106a4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1106a8:	0fc442da */ 	jal	func0f110b68
/*  f1106ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1106b0:	0fc44270 */ 	jal	func0f1109c0
/*  f1106b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1106b8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1106bc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1106c0:	03e00008 */ 	jr	$ra
/*  f1106c4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1106c8
/*  f1106c8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1106cc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1106d0:	0fc44203 */ 	jal	func0f11080c
/*  f1106d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1106d8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1106dc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1106e0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1106e4:	03e00008 */ 	jr	$ra
/*  f1106e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1106ec:	03e00008 */ 	jr	$ra
/*  f1106f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1106f4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1106f8:	00802825 */ 	or	$a1,$a0,$zero
/*  f1106fc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f110700:	3c04800a */ 	lui	$a0,%hi(var800a22d0)
/*  f110704:	248422d0 */ 	addiu	$a0,$a0,%lo(var800a22d0)
/*  f110708:	0c012c5c */ 	jal	func0004b170
/*  f11070c:	2406005b */ 	addiu	$a2,$zero,0x5b
/*  f110710:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f110714:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f110718:	03e00008 */ 	jr	$ra
/*  f11071c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f110720
/*  f110720:	27bdf7b0 */ 	addiu	$sp,$sp,-2128
/*  f110724:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f110728:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f11072c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f110730:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f110734:	afa00038 */ 	sw	$zero,0x38($sp)
/*  f110738:	27a6003c */ 	addiu	$a2,$sp,0x3c
/*  f11073c:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f110740:	0fc459ec */ 	jal	func0f1167b0
/*  f110744:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f110748:	14400029 */ 	bnez	$v0,.L0f1107f0
/*  f11074c:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f110750:	11c00013 */ 	beqz	$t6,.L0f1107a0
/*  f110754:	00008825 */ 	or	$s1,$zero,$zero
/*  f110758:	27b0003c */ 	addiu	$s0,$sp,0x3c
/*  f11075c:	8e050000 */ 	lw	$a1,0x0($s0)
/*  f110760:	27b20840 */ 	addiu	$s2,$sp,0x840
/*  f110764:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f110768:
/*  f110768:	0fc464da */ 	jal	func0f119368
/*  f11076c:	02403025 */ 	or	$a2,$s2,$zero
/*  f110770:	8fb8084c */ 	lw	$t8,0x84c($sp)
/*  f110774:	00184740 */ 	sll	$t0,$t8,0x1d
/*  f110778:	05020005 */ 	bltzl	$t0,.L0f110790
/*  f11077c:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f110780:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f110784:	10000006 */ 	beqz	$zero,.L0f1107a0
/*  f110788:	afa90038 */ 	sw	$t1,0x38($sp)
/*  f11078c:	8e050004 */ 	lw	$a1,0x4($s0)
.L0f110790:
/*  f110790:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f110794:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f110798:	54a0fff3 */ 	bnezl	$a1,.L0f110768
/*  f11079c:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f1107a0:
/*  f1107a0:	8faa003c */ 	lw	$t2,0x3c($sp)
/*  f1107a4:	27b20840 */ 	addiu	$s2,$sp,0x840
/*  f1107a8:	27b0003c */ 	addiu	$s0,$sp,0x3c
/*  f1107ac:	51400011 */ 	beqzl	$t2,.L0f1107f4
/*  f1107b0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1107b4:	8e050000 */ 	lw	$a1,0x0($s0)
/*  f1107b8:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f1107bc:
/*  f1107bc:	0fc464da */ 	jal	func0f119368
/*  f1107c0:	02403025 */ 	or	$a2,$s2,$zero
/*  f1107c4:	8fac084c */ 	lw	$t4,0x84c($sp)
/*  f1107c8:	000c7740 */ 	sll	$t6,$t4,0x1d
/*  f1107cc:	05c30005 */ 	bgezl	$t6,.L0f1107e4
/*  f1107d0:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f1107d4:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f1107d8:	10000005 */ 	beqz	$zero,.L0f1107f0
/*  f1107dc:	afaf0038 */ 	sw	$t7,0x38($sp)
/*  f1107e0:	8e050004 */ 	lw	$a1,0x4($s0)
.L0f1107e4:
/*  f1107e4:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f1107e8:	54a0fff4 */ 	bnezl	$a1,.L0f1107bc
/*  f1107ec:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f1107f0:
/*  f1107f0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f1107f4:
/*  f1107f4:	8fa20038 */ 	lw	$v0,0x38($sp)
/*  f1107f8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1107fc:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f110800:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f110804:	03e00008 */ 	jr	$ra
/*  f110808:	27bd0850 */ 	addiu	$sp,$sp,0x850
);

GLOBAL_ASM(
glabel func0f11080c
/*  f11080c:	27bdfed8 */ 	addiu	$sp,$sp,-296
/*  f110810:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f110814:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f110818:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f11081c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f110820:	0fc441c8 */ 	jal	func0f110720
/*  f110824:	afa00124 */ 	sw	$zero,0x124($sp)
/*  f110828:	14400005 */ 	bnez	$v0,.L0f110840
/*  f11082c:	00408025 */ 	or	$s0,$v0,$zero
/*  f110830:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f110834:	afae0124 */ 	sw	$t6,0x124($sp)
/*  f110838:	1000000c */ 	beqz	$zero,.L0f11086c
/*  f11083c:	27b20044 */ 	addiu	$s2,$sp,0x44
.L0f110840:
/*  f110840:	27b20044 */ 	addiu	$s2,$sp,0x44
/*  f110844:	0fc35517 */ 	jal	func0f0d545c
/*  f110848:	02402025 */ 	or	$a0,$s2,$zero
/*  f11084c:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f110850:	02002825 */ 	or	$a1,$s0,$zero
/*  f110854:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f110858:	0fc45a00 */ 	jal	func0f116800
/*  f11085c:	00003825 */ 	or	$a3,$zero,$zero
/*  f110860:	10400002 */ 	beqz	$v0,.L0f11086c
/*  f110864:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f110868:	afaf0124 */ 	sw	$t7,0x124($sp)
.L0f11086c:
/*  f11086c:	8fb80124 */ 	lw	$t8,0x124($sp)
/*  f110870:	02402025 */ 	or	$a0,$s2,$zero
/*  f110874:	57000046 */ 	bnezl	$t8,.L0f110990
/*  f110878:	8faa0124 */ 	lw	$t2,0x124($sp)
/*  f11087c:	0fc355e7 */ 	jal	func0f0d579c
/*  f110880:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f110884:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f110888:	97a80038 */ 	lhu	$t0,0x38($sp)
/*  f11088c:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f110890:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f110894:	02402025 */ 	or	$a0,$s2,$zero
/*  f110898:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11089c:	ae39047c */ 	sw	$t9,0x47c($s1)
/*  f1108a0:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f1108a4:	a6280480 */ 	sh	$t0,0x480($s1)
/*  f1108a8:	3c01800b */ 	lui	$at,0x800b
/*  f1108ac:	a022cc11 */ 	sb	$v0,-0x33ef($at)
/*  f1108b0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1108b4:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f1108b8:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f1108bc:	a6220482 */ 	sh	$v0,0x482($s1)
/*  f1108c0:	3c11800b */ 	lui	$s1,0x800b
/*  f1108c4:	3c10800b */ 	lui	$s0,0x800b
/*  f1108c8:	2610cbb0 */ 	addiu	$s0,$s0,-13392
/*  f1108cc:	2631cc10 */ 	addiu	$s1,$s1,-13296
/*  f1108d0:	02402025 */ 	or	$a0,$s2,$zero
.L0f1108d4:
/*  f1108d4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1108d8:	0fc35539 */ 	jal	func0f0d54e4
/*  f1108dc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1108e0:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f1108e4:	0211082b */ 	sltu	$at,$s0,$s1
/*  f1108e8:	5420fffa */ 	bnezl	$at,.L0f1108d4
/*  f1108ec:	02402025 */ 	or	$a0,$s2,$zero
/*  f1108f0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1108f4:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f1108f8:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f1108fc:	304300ff */ 	andi	$v1,$v0,0xff
/*  f110900:	240100ff */ 	addiu	$at,$zero,0xff
/*  f110904:	14610005 */ 	bne	$v1,$at,.L0f11091c
/*  f110908:	3c10800b */ 	lui	$s0,0x800b
/*  f11090c:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f110910:	3c01800b */ 	lui	$at,0x800b
/*  f110914:	10000003 */ 	beqz	$zero,.L0f110924
/*  f110918:	a029cc14 */ 	sb	$t1,-0x33ec($at)
.L0f11091c:
/*  f11091c:	3c01800b */ 	lui	$at,0x800b
/*  f110920:	a023cc14 */ 	sb	$v1,-0x33ec($at)
.L0f110924:
/*  f110924:	3c11800b */ 	lui	$s1,0x800b
/*  f110928:	2631cbb6 */ 	addiu	$s1,$s1,-13386
/*  f11092c:	2610cbb0 */ 	addiu	$s0,$s0,-13392
.L0f110930:
/*  f110930:	02402025 */ 	or	$a0,$s2,$zero
/*  f110934:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f110938:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f11093c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f110940:	1611fffb */ 	bne	$s0,$s1,.L0f110930
/*  f110944:	a2020064 */ 	sb	$v0,0x64($s0)
/*  f110948:	02402025 */ 	or	$a0,$s2,$zero
/*  f11094c:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f110950:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f110954:	3c01800b */ 	lui	$at,0x800b
/*  f110958:	a022cc12 */ 	sb	$v0,-0x33ee($at)
/*  f11095c:	02402025 */ 	or	$a0,$s2,$zero
/*  f110960:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f110964:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f110968:	3c01800a */ 	lui	$at,0x800a
/*  f11096c:	a022232b */ 	sb	$v0,0x232b($at)
/*  f110970:	02402025 */ 	or	$a0,$s2,$zero
/*  f110974:	0fc354fe */ 	jal	scenarioDefaultCallback40
/*  f110978:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11097c:	3c01800a */ 	lui	$at,0x800a
/*  f110980:	a022232c */ 	sb	$v0,0x232c($at)
/*  f110984:	0fc35531 */ 	jal	func0f0d54c4
/*  f110988:	02402025 */ 	or	$a0,$s2,$zero
/*  f11098c:	8faa0124 */ 	lw	$t2,0x124($sp)
.L0f110990:
/*  f110990:	51400006 */ 	beqzl	$t2,.L0f1109ac
/*  f110994:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f110998:	0fc442da */ 	jal	func0f110b68
/*  f11099c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1109a0:	0fc44270 */ 	jal	func0f1109c0
/*  f1109a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1109a8:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f1109ac:
/*  f1109ac:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1109b0:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1109b4:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1109b8:	03e00008 */ 	jr	$ra
/*  f1109bc:	27bd0128 */ 	addiu	$sp,$sp,0x128
);

GLOBAL_ASM(
glabel func0f1109c0
/*  f1109c0:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f1109c4:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f1109c8:	27b2004c */ 	addiu	$s2,$sp,0x4c
/*  f1109cc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f1109d0:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f1109d4:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1109d8:	afa0012c */ 	sw	$zero,0x12c($sp)
/*  f1109dc:	0fc35517 */ 	jal	func0f0d545c
/*  f1109e0:	02402025 */ 	or	$a0,$s2,$zero
/*  f1109e4:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f1109e8:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f1109ec:	8e0e047c */ 	lw	$t6,0x47c($s0)
/*  f1109f0:	960f0480 */ 	lhu	$t7,0x480($s0)
/*  f1109f4:	02402025 */ 	or	$a0,$s2,$zero
/*  f1109f8:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f1109fc:	afae0044 */ 	sw	$t6,0x44($sp)
/*  f110a00:	0fc355d7 */ 	jal	func0f0d575c
/*  f110a04:	a7af0048 */ 	sh	$t7,0x48($sp)
/*  f110a08:	3c05800b */ 	lui	$a1,0x800b
/*  f110a0c:	90a5cc11 */ 	lbu	$a1,-0x33ef($a1)
/*  f110a10:	02402025 */ 	or	$a0,$s2,$zero
/*  f110a14:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f110a18:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f110a1c:	02402025 */ 	or	$a0,$s2,$zero
/*  f110a20:	96050482 */ 	lhu	$a1,0x482($s0)
/*  f110a24:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f110a28:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f110a2c:	3c10800b */ 	lui	$s0,0x800b
/*  f110a30:	3c11800b */ 	lui	$s1,0x800b
/*  f110a34:	2631cc10 */ 	addiu	$s1,$s1,-13296
/*  f110a38:	2610cbb0 */ 	addiu	$s0,$s0,-13392
/*  f110a3c:	02402025 */ 	or	$a0,$s2,$zero
.L0f110a40:
/*  f110a40:	0fc35569 */ 	jal	func0f0d55a4
/*  f110a44:	02002825 */ 	or	$a1,$s0,$zero
/*  f110a48:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f110a4c:	0211082b */ 	sltu	$at,$s0,$s1
/*  f110a50:	5420fffb */ 	bnezl	$at,.L0f110a40
/*  f110a54:	02402025 */ 	or	$a0,$s2,$zero
/*  f110a58:	3c02800b */ 	lui	$v0,0x800b
/*  f110a5c:	8042cc14 */ 	lb	$v0,-0x33ec($v0)
/*  f110a60:	2401ffff */ 	addiu	$at,$zero,-1
/*  f110a64:	02402025 */ 	or	$a0,$s2,$zero
/*  f110a68:	14410007 */ 	bne	$v0,$at,.L0f110a88
/*  f110a6c:	00402825 */ 	or	$a1,$v0,$zero
/*  f110a70:	02402025 */ 	or	$a0,$s2,$zero
/*  f110a74:	240500ff */ 	addiu	$a1,$zero,0xff
/*  f110a78:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f110a7c:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f110a80:	10000003 */ 	beqz	$zero,.L0f110a90
/*  f110a84:	00000000 */ 	sll	$zero,$zero,0x0
.L0f110a88:
/*  f110a88:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f110a8c:	24060008 */ 	addiu	$a2,$zero,0x8
.L0f110a90:
/*  f110a90:	3c10800b */ 	lui	$s0,0x800b
/*  f110a94:	3c11800b */ 	lui	$s1,0x800b
/*  f110a98:	2631cbb6 */ 	addiu	$s1,$s1,-13386
/*  f110a9c:	2610cbb0 */ 	addiu	$s0,$s0,-13392
/*  f110aa0:	02402025 */ 	or	$a0,$s2,$zero
.L0f110aa4:
/*  f110aa4:	92050065 */ 	lbu	$a1,0x65($s0)
/*  f110aa8:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f110aac:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f110ab0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f110ab4:	5611fffb */ 	bnel	$s0,$s1,.L0f110aa4
/*  f110ab8:	02402025 */ 	or	$a0,$s2,$zero
/*  f110abc:	3c05800b */ 	lui	$a1,0x800b
/*  f110ac0:	90a5cc12 */ 	lbu	$a1,-0x33ee($a1)
/*  f110ac4:	02402025 */ 	or	$a0,$s2,$zero
/*  f110ac8:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f110acc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f110ad0:	3c05800a */ 	lui	$a1,0x800a
/*  f110ad4:	90a5232b */ 	lbu	$a1,0x232b($a1)
/*  f110ad8:	02402025 */ 	or	$a0,$s2,$zero
/*  f110adc:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f110ae0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f110ae4:	3c05800a */ 	lui	$a1,0x800a
/*  f110ae8:	90a5232c */ 	lbu	$a1,0x232c($a1)
/*  f110aec:	02402025 */ 	or	$a0,$s2,$zero
/*  f110af0:	0fc354be */ 	jal	scenarioDefaultCallback44
/*  f110af4:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f110af8:	0fc35531 */ 	jal	func0f0d54c4
/*  f110afc:	02402025 */ 	or	$a0,$s2,$zero
/*  f110b00:	0fc441c8 */ 	jal	func0f110720
/*  f110b04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f110b08:	14400007 */ 	bnez	$v0,.L0f110b28
/*  f110b0c:	00408025 */ 	or	$s0,$v0,$zero
/*  f110b10:	3c047f1b */ 	lui	$a0,%hi(var7f1b39b0)
/*  f110b14:	3c057f1b */ 	lui	$a1,%hi(var7f1b39bc)
/*  f110b18:	24a539bc */ 	addiu	$a1,$a1,%lo(var7f1b39bc)
/*  f110b1c:	248439b0 */ 	addiu	$a0,$a0,%lo(var7f1b39b0)
/*  f110b20:	0c002ff4 */ 	jal	func0000bfd0
/*  f110b24:	24060177 */ 	addiu	$a2,$zero,0x177
.L0f110b28:
/*  f110b28:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f110b2c:	02002825 */ 	or	$a1,$s0,$zero
/*  f110b30:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f110b34:	27a70050 */ 	addiu	$a3,$sp,0x50
/*  f110b38:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f110b3c:	0fc45a0a */ 	jal	func0f116828
/*  f110b40:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f110b44:	10400002 */ 	beqz	$v0,.L0f110b50
/*  f110b48:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f110b4c:	afb8012c */ 	sw	$t8,0x12c($sp)
.L0f110b50:
/*  f110b50:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f110b54:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f110b58:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f110b5c:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f110b60:	03e00008 */ 	jr	$ra
/*  f110b64:	27bd0130 */ 	addiu	$sp,$sp,0x130
);

GLOBAL_ASM(
glabel func0f110b68
/*  f110b68:	3c02800b */ 	lui	$v0,0x800b
/*  f110b6c:	2442cbb0 */ 	addiu	$v0,$v0,-13392
/*  f110b70:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f110b74:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f110b78:	240effff */ 	addiu	$t6,$zero,-1
/*  f110b7c:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f110b80:	a040000c */ 	sb	$zero,0xc($v0)
/*  f110b84:	a0400018 */ 	sb	$zero,0x18($v0)
/*  f110b88:	a0400024 */ 	sb	$zero,0x24($v0)
/*  f110b8c:	a0400030 */ 	sb	$zero,0x30($v0)
/*  f110b90:	a040003c */ 	sb	$zero,0x3c($v0)
/*  f110b94:	a0400048 */ 	sb	$zero,0x48($v0)
/*  f110b98:	a0400054 */ 	sb	$zero,0x54($v0)
/*  f110b9c:	0fc630f9 */ 	jal	func0f18c3e4
/*  f110ba0:	a04e0064 */ 	sb	$t6,0x64($v0)
/*  f110ba4:	3c02800b */ 	lui	$v0,0x800b
/*  f110ba8:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f110bac:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f110bb0:	2442cbb0 */ 	addiu	$v0,$v0,-13392
/*  f110bb4:	a0400062 */ 	sb	$zero,0x62($v0)
/*  f110bb8:	a0400061 */ 	sb	$zero,0x61($v0)
/*  f110bbc:	a0400060 */ 	sb	$zero,0x60($v0)
/*  f110bc0:	ac60047c */ 	sw	$zero,0x47c($v1)
/*  f110bc4:	a4600480 */ 	sh	$zero,0x480($v1)
/*  f110bc8:	a4600482 */ 	sh	$zero,0x482($v1)
/*  f110bcc:	3c01800a */ 	lui	$at,0x800a
/*  f110bd0:	a020232b */ 	sb	$zero,0x232b($at)
/*  f110bd4:	3c01800a */ 	lui	$at,0x800a
/*  f110bd8:	0fc44270 */ 	jal	func0f1109c0
/*  f110bdc:	a020232c */ 	sb	$zero,0x232c($at)
/*  f110be0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f110be4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f110be8:	03e00008 */ 	jr	$ra
/*  f110bec:	00000000 */ 	sll	$zero,$zero,0x0
);

void func0f110bf0(void)
{
	// empty
}

GLOBAL_ASM(
glabel func0f110bf8
/*  f110bf8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f110bfc:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f110c00:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f110c04:	3c108007 */ 	lui	$s0,%hi(g_SaveLocations)
/*  f110c08:	3c118007 */ 	lui	$s1,%hi(var80075bd0)
/*  f110c0c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f110c10:	26315bd0 */ 	addiu	$s1,$s1,%lo(var80075bd0)
/*  f110c14:	26105bc0 */ 	addiu	$s0,$s0,%lo(g_SaveLocations)
/*  f110c18:	8e0e0000 */ 	lw	$t6,0x0($s0)
.L0f110c1c:
/*  f110c1c:	51c00008 */ 	beqzl	$t6,.L0f110c40
/*  f110c20:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f110c24:	0fc5db69 */ 	jal	func0f176da4
/*  f110c28:	24040310 */ 	addiu	$a0,$zero,0x310
/*  f110c2c:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f110c30:	0c004b2d */ 	jal	func00012cb4
/*  f110c34:	00402825 */ 	or	$a1,$v0,$zero
/*  f110c38:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f110c3c:	26100004 */ 	addiu	$s0,$s0,0x4
.L0f110c40:
/*  f110c40:	5611fff6 */ 	bnel	$s0,$s1,.L0f110c1c
/*  f110c44:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f110c48:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f110c4c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f110c50:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f110c54:	03e00008 */ 	jr	$ra
/*  f110c58:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f110c5c
/*  f110c5c:	3c0f8007 */ 	lui	$t7,%hi(g_SaveLocations)
/*  f110c60:	25ef5bc0 */ 	addiu	$t7,$t7,%lo(g_SaveLocations)
/*  f110c64:	00047080 */ 	sll	$t6,$a0,0x2
/*  f110c68:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f110c6c:	8cc30000 */ 	lw	$v1,0x0($a2)
/*  f110c70:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f110c74:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f110c78:	1460000e */ 	bnez	$v1,.L0f110cb4
/*  f110c7c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f110c80:	24040310 */ 	addiu	$a0,$zero,0x310
/*  f110c84:	0fc5db69 */ 	jal	func0f176da4
/*  f110c88:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f110c8c:	00402025 */ 	or	$a0,$v0,$zero
/*  f110c90:	0fc5796e */ 	jal	func0f15e5b8
/*  f110c94:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f110c98:	0fc5db69 */ 	jal	func0f176da4
/*  f110c9c:	24040310 */ 	addiu	$a0,$zero,0x310
/*  f110ca0:	0c004aac */ 	jal	func00012ab0
/*  f110ca4:	00402025 */ 	or	$a0,$v0,$zero
/*  f110ca8:	8fa60018 */ 	lw	$a2,0x18($sp)
/*  f110cac:	00401825 */ 	or	$v1,$v0,$zero
/*  f110cb0:	acc20000 */ 	sw	$v0,0x0($a2)
.L0f110cb4:
/*  f110cb4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f110cb8:	a078030c */ 	sb	$t8,0x30c($v1)
/*  f110cbc:	8cc80000 */ 	lw	$t0,0x0($a2)
/*  f110cc0:	93b90027 */ 	lbu	$t9,0x27($sp)
/*  f110cc4:	3c098006 */ 	lui	$t1,0x8006
/*  f110cc8:	a119030b */ 	sb	$t9,0x30b($t0)
/*  f110ccc:	91292944 */ 	lbu	$t1,0x2944($t1)
/*  f110cd0:	55200004 */ 	bnezl	$t1,.L0f110ce4
/*  f110cd4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f110cd8:	0c004e63 */ 	jal	func0001398c
/*  f110cdc:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f110ce0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f110ce4:
/*  f110ce4:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f110ce8:	3c018006 */ 	lui	$at,0x8006
/*  f110cec:	a02a2944 */ 	sb	$t2,0x2944($at)
/*  f110cf0:	03e00008 */ 	jr	$ra
/*  f110cf4:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f110cf8
/*  f110cf8:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f110cfc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f110d00:	309000ff */ 	andi	$s0,$a0,0xff
/*  f110d04:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f110d08:	3c058007 */ 	lui	$a1,%hi(g_SaveLocations)
/*  f110d0c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f110d10:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f110d14:	24a55bc0 */ 	addiu	$a1,$a1,%lo(g_SaveLocations)
/*  f110d18:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f110d1c:	00001825 */ 	or	$v1,$zero,$zero
/*  f110d20:	2407ffff */ 	addiu	$a3,$zero,-1
.L0f110d24:
/*  f110d24:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f110d28:	10400006 */ 	beqz	$v0,.L0f110d44
/*  f110d2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f110d30:	904e030b */ 	lbu	$t6,0x30b($v0)
/*  f110d34:	560e0007 */ 	bnel	$s0,$t6,.L0f110d54
/*  f110d38:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f110d3c:	1000000f */ 	beqz	$zero,.L0f110d7c
/*  f110d40:	00601025 */ 	or	$v0,$v1,$zero
.L0f110d44:
/*  f110d44:	54c70003 */ 	bnel	$a2,$a3,.L0f110d54
/*  f110d48:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f110d4c:	00603025 */ 	or	$a2,$v1,$zero
/*  f110d50:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f110d54:
/*  f110d54:	1464fff3 */ 	bne	$v1,$a0,.L0f110d24
/*  f110d58:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f110d5c:	04c00007 */ 	bltz	$a2,.L0f110d7c
/*  f110d60:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f110d64:	00c02025 */ 	or	$a0,$a2,$zero
/*  f110d68:	320500ff */ 	andi	$a1,$s0,0xff
/*  f110d6c:	0fc44317 */ 	jal	func0f110c5c
/*  f110d70:	afa60024 */ 	sw	$a2,0x24($sp)
/*  f110d74:	10000001 */ 	beqz	$zero,.L0f110d7c
/*  f110d78:	8fa20024 */ 	lw	$v0,0x24($sp)
.L0f110d7c:
/*  f110d7c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f110d80:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f110d84:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f110d88:	03e00008 */ 	jr	$ra
/*  f110d8c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f110d90
/*  f110d90:	00047880 */ 	sll	$t7,$a0,0x2
/*  f110d94:	3c01800a */ 	lui	$at,0x800a
/*  f110d98:	002f0821 */ 	addu	$at,$at,$t7
/*  f110d9c:	240effff */ 	addiu	$t6,$zero,-1
/*  f110da0:	03e00008 */ 	jr	$ra
/*  f110da4:	ac2e2330 */ 	sw	$t6,0x2330($at)
);

GLOBAL_ASM(
glabel func0f110da8
/*  f110da8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f110dac:	3c0e8007 */ 	lui	$t6,0x8007
/*  f110db0:	8dce5bf4 */ 	lw	$t6,0x5bf4($t6)
/*  f110db4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f110db8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f110dbc:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f110dc0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f110dc4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f110dc8:	15c0000c */ 	bnez	$t6,.L0f110dfc
/*  f110dcc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f110dd0:	3c10800a */ 	lui	$s0,%hi(var800a2330)
/*  f110dd4:	3c03800a */ 	lui	$v1,%hi(var800a2344)
/*  f110dd8:	24632344 */ 	addiu	$v1,$v1,%lo(var800a2344)
/*  f110ddc:	26102330 */ 	addiu	$s0,$s0,%lo(var800a2330)
/*  f110de0:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f110de4:
/*  f110de4:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f110de8:	1603fffe */ 	bne	$s0,$v1,.L0f110de4
/*  f110dec:	ae02fffc */ 	sw	$v0,-0x4($s0)
/*  f110df0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f110df4:	3c018007 */ 	lui	$at,0x8007
/*  f110df8:	ac2f5bf4 */ 	sw	$t7,0x5bf4($at)
.L0f110dfc:
/*  f110dfc:	00009025 */ 	or	$s2,$zero,$zero
/*  f110e00:	00009825 */ 	or	$s3,$zero,$zero
/*  f110e04:	00128e00 */ 	sll	$s1,$s2,0x18
.L0f110e08:
/*  f110e08:	0011c603 */ 	sra	$t8,$s1,0x18
/*  f110e0c:	00182600 */ 	sll	$a0,$t8,0x18
/*  f110e10:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f110e14:	03202025 */ 	or	$a0,$t9,$zero
/*  f110e18:	0fc459f6 */ 	jal	func0f1167d8
/*  f110e1c:	03008825 */ 	or	$s1,$t8,$zero
/*  f110e20:	10400010 */ 	beqz	$v0,.L0f110e64
/*  f110e24:	00112600 */ 	sll	$a0,$s1,0x18
/*  f110e28:	3c0a800a */ 	lui	$t2,%hi(var800a2330)
/*  f110e2c:	254a2330 */ 	addiu	$t2,$t2,%lo(var800a2330)
/*  f110e30:	00044603 */ 	sra	$t0,$a0,0x18
/*  f110e34:	00124880 */ 	sll	$t1,$s2,0x2
/*  f110e38:	012a8021 */ 	addu	$s0,$t1,$t2
/*  f110e3c:	0fc45c0b */ 	jal	func0f11702c
/*  f110e40:	01002025 */ 	or	$a0,$t0,$zero
/*  f110e44:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f110e48:	00112600 */ 	sll	$a0,$s1,0x18
/*  f110e4c:	00046603 */ 	sra	$t4,$a0,0x18
/*  f110e50:	104b0004 */ 	beq	$v0,$t3,.L0f110e64
/*  f110e54:	01802025 */ 	or	$a0,$t4,$zero
/*  f110e58:	0fc45c0b */ 	jal	func0f11702c
/*  f110e5c:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f110e60:	ae020000 */ 	sw	$v0,0x0($s0)
.L0f110e64:
/*  f110e64:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f110e68:	2a410005 */ 	slti	$at,$s2,0x5
/*  f110e6c:	5420ffe6 */ 	bnezl	$at,.L0f110e08
/*  f110e70:	00128e00 */ 	sll	$s1,$s2,0x18
/*  f110e74:	3c108007 */ 	lui	$s0,%hi(g_SaveLocations)
/*  f110e78:	3c148007 */ 	lui	$s4,%hi(var80075bd0)
/*  f110e7c:	3c118007 */ 	lui	$s1,%hi(var80075bd0)
/*  f110e80:	26315bd0 */ 	addiu	$s1,$s1,%lo(var80075bd0)
/*  f110e84:	26945bd0 */ 	addiu	$s4,$s4,%lo(var80075bd0)
/*  f110e88:	26105bc0 */ 	addiu	$s0,$s0,%lo(g_SaveLocations)
/*  f110e8c:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f110e90:	8e040000 */ 	lw	$a0,0x0($s0)
.L0f110e94:
/*  f110e94:	5080001b */ 	beqzl	$a0,.L0f110f04
/*  f110e98:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f110e9c:	a080030e */ 	sb	$zero,0x30e($a0)
/*  f110ea0:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f110ea4:	02601825 */ 	or	$v1,$s3,$zero
/*  f110ea8:	9082030c */ 	lbu	$v0,0x30c($a0)
/*  f110eac:	18400007 */ 	blez	$v0,.L0f110ecc
/*  f110eb0:	244dffff */ 	addiu	$t5,$v0,-1
/*  f110eb4:	a08d030c */ 	sb	$t5,0x30c($a0)
/*  f110eb8:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f110ebc:	908e030c */ 	lbu	$t6,0x30c($a0)
/*  f110ec0:	55c00003 */ 	bnezl	$t6,.L0f110ed0
/*  f110ec4:	908f030b */ 	lbu	$t7,0x30b($a0)
/*  f110ec8:	02401825 */ 	or	$v1,$s2,$zero
.L0f110ecc:
/*  f110ecc:	908f030b */ 	lbu	$t7,0x30b($a0)
.L0f110ed0:
/*  f110ed0:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f110ed4:	0238c821 */ 	addu	$t9,$s1,$t8
/*  f110ed8:	8f280000 */ 	lw	$t0,0x0($t9)
/*  f110edc:	11000002 */ 	beqz	$t0,.L0f110ee8
/*  f110ee0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f110ee4:	02401825 */ 	or	$v1,$s2,$zero
.L0f110ee8:
/*  f110ee8:	50600006 */ 	beqzl	$v1,.L0f110f04
/*  f110eec:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f110ef0:	0fc443d3 */ 	jal	func0f110f4c
/*  f110ef4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f110ef8:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f110efc:	a132030e */ 	sb	$s2,0x30e($t1)
/*  f110f00:	26100004 */ 	addiu	$s0,$s0,0x4
.L0f110f04:
/*  f110f04:	0214082b */ 	sltu	$at,$s0,$s4
/*  f110f08:	5420ffe2 */ 	bnezl	$at,.L0f110e94
/*  f110f0c:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f110f10:	3c028007 */ 	lui	$v0,%hi(var80075bd0)
/*  f110f14:	3c038007 */ 	lui	$v1,%hi(var80075be0)
/*  f110f18:	24635be0 */ 	addiu	$v1,$v1,%lo(var80075be0)
/*  f110f1c:	24425bd0 */ 	addiu	$v0,$v0,%lo(var80075bd0)
.L0f110f20:
/*  f110f20:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f110f24:	1443fffe */ 	bne	$v0,$v1,.L0f110f20
/*  f110f28:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f110f2c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f110f30:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f110f34:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f110f38:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f110f3c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f110f40:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f110f44:	03e00008 */ 	jr	$ra
/*  f110f48:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f110f4c
/*  f110f4c:	27bdc568 */ 	addiu	$sp,$sp,-15000
/*  f110f50:	3c0e7f1b */ 	lui	$t6,%hi(var7f1b39e8)
/*  f110f54:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f110f58:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f110f5c:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f110f60:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f110f64:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f110f68:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f110f6c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f110f70:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f110f74:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f110f78:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f110f7c:	25ce39e8 */ 	addiu	$t6,$t6,%lo(var7f1b39e8)
/*  f110f80:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f110f84:	27b43a88 */ 	addiu	$s4,$sp,0x3a88
/*  f110f88:	3c097f1b */ 	lui	$t1,%hi(var7f1b39f8)
/*  f110f8c:	ae810000 */ 	sw	$at,0x0($s4)
/*  f110f90:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f110f94:	252939f8 */ 	addiu	$t1,$t1,%lo(var7f1b39f8)
/*  f110f98:	27a80070 */ 	addiu	$t0,$sp,0x70
/*  f110f9c:	ae990004 */ 	sw	$t9,0x4($s4)
/*  f110fa0:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f110fa4:	3c0d7f1b */ 	lui	$t5,%hi(var7f1b3a00)
/*  f110fa8:	25ad3a00 */ 	addiu	$t5,$t5,%lo(var7f1b3a00)
/*  f110fac:	ae810008 */ 	sw	$at,0x8($s4)
/*  f110fb0:	8dd9000c */ 	lw	$t9,0xc($t6)
/*  f110fb4:	27b70068 */ 	addiu	$s7,$sp,0x68
/*  f110fb8:	00809025 */ 	or	$s2,$a0,$zero
/*  f110fbc:	ae99000c */ 	sw	$t9,0xc($s4)
/*  f110fc0:	8d210000 */ 	lw	$at,0x0($t1)
/*  f110fc4:	27b00070 */ 	addiu	$s0,$sp,0x70
/*  f110fc8:	00008825 */ 	or	$s1,$zero,$zero
/*  f110fcc:	ad010000 */ 	sw	$at,0x0($t0)
/*  f110fd0:	91210004 */ 	lbu	$at,0x4($t1)
/*  f110fd4:	00809825 */ 	or	$s3,$a0,$zero
/*  f110fd8:	27b50a88 */ 	addiu	$s5,$sp,0xa88
/*  f110fdc:	a1010004 */ 	sb	$at,0x4($t0)
/*  f110fe0:	8da10000 */ 	lw	$at,0x0($t5)
/*  f110fe4:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f110fe8:	241e0003 */ 	addiu	$s8,$zero,0x3
/*  f110fec:	aee10000 */ 	sw	$at,0x0($s7)
/*  f110ff0:	91a10004 */ 	lbu	$at,0x4($t5)
/*  f110ff4:	a2e10004 */ 	sb	$at,0x4($s7)
/*  f110ff8:	a080030a */ 	sb	$zero,0x30a($a0)
.L0f110ffc:
/*  f110ffc:	82190000 */ 	lb	$t9,0x0($s0)
/*  f111000:	02a03025 */ 	or	$a2,$s5,$zero
/*  f111004:	02595821 */ 	addu	$t3,$s2,$t9
/*  f111008:	a1600305 */ 	sb	$zero,0x305($t3)
/*  f11100c:	a2760300 */ 	sb	$s6,0x300($s3)
/*  f111010:	924a030b */ 	lbu	$t2,0x30b($s2)
/*  f111014:	82040000 */ 	lb	$a0,0x0($s0)
/*  f111018:	000a4080 */ 	sll	$t0,$t2,0x2
/*  f11101c:	02884821 */ 	addu	$t1,$s4,$t0
/*  f111020:	0fc459ec */ 	jal	func0f1167b0
/*  f111024:	8d250000 */ 	lw	$a1,0x0($t1)
/*  f111028:	14400028 */ 	bnez	$v0,.L0f1110cc
/*  f11102c:	8fac0a88 */ 	lw	$t4,0xa88($sp)
/*  f111030:	11800010 */ 	beqz	$t4,.L0f111074
/*  f111034:	00117880 */ 	sll	$t7,$s1,0x2
/*  f111038:	27b81288 */ 	addiu	$t8,$sp,0x1288
/*  f11103c:	27a30a88 */ 	addiu	$v1,$sp,0xa88
/*  f111040:	27ae0088 */ 	addiu	$t6,$sp,0x88
/*  f111044:	022e2821 */ 	addu	$a1,$s1,$t6
/*  f111048:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f11104c:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f111050:	82060000 */ 	lb	$a2,0x0($s0)
.L0f111054:
/*  f111054:	ac440000 */ 	sw	$a0,0x0($v0)
/*  f111058:	8c640004 */ 	lw	$a0,0x4($v1)
/*  f11105c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f111060:	a0a60000 */ 	sb	$a2,0x0($a1)
/*  f111064:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f111068:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f11106c:	1480fff9 */ 	bnez	$a0,.L0f111054
/*  f111070:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f111074:
/*  f111074:	82190000 */ 	lb	$t9,0x0($s0)
/*  f111078:	02595821 */ 	addu	$t3,$s2,$t9
/*  f11107c:	a16002d2 */ 	sb	$zero,0x2d2($t3)
/*  f111080:	924a030b */ 	lbu	$t2,0x30b($s2)
/*  f111084:	57ca0007 */ 	bnel	$s8,$t2,.L0f1110a4
/*  f111088:	820c0000 */ 	lb	$t4,0x0($s0)
/*  f11108c:	0fc46052 */ 	jal	func0f118148
/*  f111090:	82040000 */ 	lb	$a0,0x0($s0)
/*  f111094:	82080000 */ 	lb	$t0,0x0($s0)
/*  f111098:	02484821 */ 	addu	$t1,$s2,$t0
/*  f11109c:	a12202d2 */ 	sb	$v0,0x2d2($t1)
/*  f1110a0:	820c0000 */ 	lb	$t4,0x0($s0)
.L0f1110a4:
/*  f1110a4:	000c78c0 */ 	sll	$t7,$t4,0x3
/*  f1110a8:	024fc021 */ 	addu	$t8,$s2,$t7
/*  f1110ac:	af0002d8 */ 	sw	$zero,0x2d8($t8)
/*  f1110b0:	0fc45a4f */ 	jal	func0f11693c
/*  f1110b4:	82040000 */ 	lb	$a0,0x0($s0)
/*  f1110b8:	820d0000 */ 	lb	$t5,0x0($s0)
/*  f1110bc:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f1110c0:	024ec821 */ 	addu	$t9,$s2,$t6
/*  f1110c4:	10000008 */ 	beqz	$zero,.L0f1110e8
/*  f1110c8:	a72202dc */ 	sh	$v0,0x2dc($t9)
.L0f1110cc:
/*  f1110cc:	820b0000 */ 	lb	$t3,0x0($s0)
/*  f1110d0:	2401000d */ 	addiu	$at,$zero,0xd
/*  f1110d4:	24080005 */ 	addiu	$t0,$zero,0x5
/*  f1110d8:	024b5021 */ 	addu	$t2,$s2,$t3
/*  f1110dc:	14410002 */ 	bne	$v0,$at,.L0f1110e8
/*  f1110e0:	a15602d2 */ 	sb	$s6,0x2d2($t2)
/*  f1110e4:	a248030c */ 	sb	$t0,0x30c($s2)
.L0f1110e8:
/*  f1110e8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1110ec:	27a90075 */ 	addiu	$t1,$sp,0x75
/*  f1110f0:	0209082b */ 	sltu	$at,$s0,$t1
/*  f1110f4:	1420ffc1 */ 	bnez	$at,.L0f110ffc
/*  f1110f8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f1110fc:	a64002d0 */ 	sh	$zero,0x2d0($s2)
/*  f111100:	1a20004b */ 	blez	$s1,.L0f111230
/*  f111104:	0000a825 */ 	or	$s5,$zero,$zero
/*  f111108:	27b00088 */ 	addiu	$s0,$sp,0x88
/*  f11110c:	27b41288 */ 	addiu	$s4,$sp,0x1288
/*  f111110:	241e0018 */ 	addiu	$s8,$zero,0x18
.L0f111114:
/*  f111114:	864c02d0 */ 	lh	$t4,0x2d0($s2)
/*  f111118:	82040000 */ 	lb	$a0,0x0($s0)
/*  f11111c:	8e850000 */ 	lw	$a1,0x0($s4)
/*  f111120:	019e0019 */ 	multu	$t4,$s8
/*  f111124:	24070010 */ 	addiu	$a3,$zero,0x10
/*  f111128:	00007812 */ 	mflo	$t7
/*  f11112c:	024f9821 */ 	addu	$s3,$s2,$t7
/*  f111130:	0fc45a00 */ 	jal	func0f116800
/*  f111134:	26660006 */ 	addiu	$a2,$s3,0x6
/*  f111138:	1440001b */ 	bnez	$v0,.L0f1111a8
/*  f11113c:	2401000a */ 	addiu	$at,$zero,0xa
/*  f111140:	82040000 */ 	lb	$a0,0x0($s0)
/*  f111144:	02e4c021 */ 	addu	$t8,$s7,$a0
/*  f111148:	830d0000 */ 	lb	$t5,0x0($t8)
/*  f11114c:	024d7021 */ 	addu	$t6,$s2,$t5
/*  f111150:	81d90300 */ 	lb	$t9,0x300($t6)
/*  f111154:	16d9000b */ 	bne	$s6,$t9,.L0f111184
/*  f111158:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11115c:	924b030a */ 	lbu	$t3,0x30a($s2)
/*  f111160:	864802d0 */ 	lh	$t0,0x2d0($s2)
/*  f111164:	256a0001 */ 	addiu	$t2,$t3,0x1
/*  f111168:	a24a030a */ 	sb	$t2,0x30a($s2)
/*  f11116c:	82090000 */ 	lb	$t1,0x0($s0)
/*  f111170:	02e96021 */ 	addu	$t4,$s7,$t1
/*  f111174:	818f0000 */ 	lb	$t7,0x0($t4)
/*  f111178:	024fc021 */ 	addu	$t8,$s2,$t7
/*  f11117c:	a3080300 */ 	sb	$t0,0x300($t8)
/*  f111180:	82040000 */ 	lb	$a0,0x0($s0)
.L0f111184:
/*  f111184:	0fc45a4f */ 	jal	func0f11693c
/*  f111188:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11118c:	a6620004 */ 	sh	$v0,0x4($s3)
/*  f111190:	8e8d0000 */ 	lw	$t5,0x0($s4)
/*  f111194:	ae6d0000 */ 	sw	$t5,0x0($s3)
/*  f111198:	864e02d0 */ 	lh	$t6,0x2d0($s2)
/*  f11119c:	25d90001 */ 	addiu	$t9,$t6,0x1
/*  f1111a0:	1000001f */ 	beqz	$zero,.L0f111220
/*  f1111a4:	a65902d0 */ 	sh	$t9,0x2d0($s2)
.L0f1111a8:
/*  f1111a8:	5441001e */ 	bnel	$v0,$at,.L0f111224
/*  f1111ac:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f1111b0:	820b0000 */ 	lb	$t3,0x0($s0)
/*  f1111b4:	024b1021 */ 	addu	$v0,$s2,$t3
/*  f1111b8:	804a0305 */ 	lb	$t2,0x305($v0)
/*  f1111bc:	25490001 */ 	addiu	$t1,$t2,0x1
/*  f1111c0:	a0490305 */ 	sb	$t1,0x305($v0)
/*  f1111c4:	820c0000 */ 	lb	$t4,0x0($s0)
/*  f1111c8:	024c1021 */ 	addu	$v0,$s2,$t4
/*  f1111cc:	804f0305 */ 	lb	$t7,0x305($v0)
/*  f1111d0:	29e10002 */ 	slti	$at,$t7,0x2
/*  f1111d4:	54200013 */ 	bnezl	$at,.L0f111224
/*  f1111d8:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f1111dc:	804802d2 */ 	lb	$t0,0x2d2($v0)
/*  f1111e0:	25180001 */ 	addiu	$t8,$t0,0x1
/*  f1111e4:	a05802d2 */ 	sb	$t8,0x2d2($v0)
/*  f1111e8:	820d0000 */ 	lb	$t5,0x0($s0)
/*  f1111ec:	000d70c0 */ 	sll	$t6,$t5,0x3
/*  f1111f0:	024e1821 */ 	addu	$v1,$s2,$t6
/*  f1111f4:	8c7902d8 */ 	lw	$t9,0x2d8($v1)
/*  f1111f8:	5720000a */ 	bnezl	$t9,.L0f111224
/*  f1111fc:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f111200:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f111204:	ac6b02d8 */ 	sw	$t3,0x2d8($v1)
/*  f111208:	0fc45a4f */ 	jal	func0f11693c
/*  f11120c:	82040000 */ 	lb	$a0,0x0($s0)
/*  f111210:	820a0000 */ 	lb	$t2,0x0($s0)
/*  f111214:	000a48c0 */ 	sll	$t1,$t2,0x3
/*  f111218:	02496021 */ 	addu	$t4,$s2,$t1
/*  f11121c:	a58202dc */ 	sh	$v0,0x2dc($t4)
.L0f111220:
/*  f111220:	26b50001 */ 	addiu	$s5,$s5,0x1
.L0f111224:
/*  f111224:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f111228:	16b1ffba */ 	bne	$s5,$s1,.L0f111114
/*  f11122c:	26940004 */ 	addiu	$s4,$s4,0x4
.L0f111230:
/*  f111230:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f111234:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f111238:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f11123c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f111240:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f111244:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f111248:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f11124c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f111250:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f111254:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f111258:	03e00008 */ 	jr	$ra
/*  f11125c:	27bd3a98 */ 	addiu	$sp,$sp,0x3a98
/*  f111260:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f111264:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f111268:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11126c:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f111270:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f111274:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f111278:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f11127c:	3c0f800a */ 	lui	$t7,%hi(var8009e000)
/*  f111280:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f111284:	25efe000 */ 	addiu	$t7,$t7,%lo(var8009e000)
/*  f111288:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f11128c:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f111290:	8e030e68 */ 	lw	$v1,0xe68($s0)
/*  f111294:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f111298:	14600017 */ 	bnez	$v1,.L0f1112f8
/*  f11129c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1112a0:	54a00011 */ 	bnezl	$a1,.L0f1112e8
/*  f1112a4:	92090e40 */ 	lbu	$t1,0xe40($s0)
/*  f1112a8:	92190e40 */ 	lbu	$t9,0xe40($s0)
/*  f1112ac:	24040890 */ 	addiu	$a0,$zero,0x890
/*  f1112b0:	37280040 */ 	ori	$t0,$t9,0x40
/*  f1112b4:	0fc5db69 */ 	jal	func0f176da4
/*  f1112b8:	a2080e40 */ 	sb	$t0,0xe40($s0)
/*  f1112bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f1112c0:	0fc5796e */ 	jal	func0f15e5b8
/*  f1112c4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f1112c8:	0fc5db69 */ 	jal	func0f176da4
/*  f1112cc:	24040890 */ 	addiu	$a0,$zero,0x890
/*  f1112d0:	0c004aac */ 	jal	func00012ab0
/*  f1112d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f1112d8:	ae020e68 */ 	sw	$v0,0xe68($s0)
/*  f1112dc:	10000006 */ 	beqz	$zero,.L0f1112f8
/*  f1112e0:	00401825 */ 	or	$v1,$v0,$zero
/*  f1112e4:	92090e40 */ 	lbu	$t1,0xe40($s0)
.L0f1112e8:
/*  f1112e8:	ae050e68 */ 	sw	$a1,0xe68($s0)
/*  f1112ec:	00a01825 */ 	or	$v1,$a1,$zero
/*  f1112f0:	312affbf */ 	andi	$t2,$t1,0xffbf
/*  f1112f4:	a20a0e40 */ 	sb	$t2,0xe40($s0)
.L0f1112f8:
/*  f1112f8:	14600006 */ 	bnez	$v1,.L0f111314
/*  f1112fc:	3c047f1b */ 	lui	$a0,%hi(var7f1b3a08)
/*  f111300:	3c057f1b */ 	lui	$a1,%hi(var7f1b3a14)
/*  f111304:	24a53a14 */ 	addiu	$a1,$a1,%lo(var7f1b3a14)
/*  f111308:	24843a08 */ 	addiu	$a0,$a0,%lo(var7f1b3a08)
/*  f11130c:	0c002ff4 */ 	jal	func0000bfd0
/*  f111310:	240601ca */ 	addiu	$a2,$zero,0x1ca
.L0f111314:
/*  f111314:	00001025 */ 	or	$v0,$zero,$zero
/*  f111318:	24030080 */ 	addiu	$v1,$zero,0x80
.L0f11131c:
/*  f11131c:	8e0b0e68 */ 	lw	$t3,0xe68($s0)
/*  f111320:	01626021 */ 	addu	$t4,$t3,$v0
/*  f111324:	ad800800 */ 	sw	$zero,0x800($t4)
/*  f111328:	8e0d0e68 */ 	lw	$t5,0xe68($s0)
/*  f11132c:	01a27021 */ 	addu	$t6,$t5,$v0
/*  f111330:	24420008 */ 	addiu	$v0,$v0,0x8
/*  f111334:	1443fff9 */ 	bne	$v0,$v1,.L0f11131c
/*  f111338:	a5c00804 */ 	sh	$zero,0x804($t6)
/*  f11133c:	8e0f0e68 */ 	lw	$t7,0xe68($s0)
/*  f111340:	24020010 */ 	addiu	$v0,$zero,0x10
/*  f111344:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f111348:	ade00880 */ 	sw	$zero,0x880($t7)
/*  f11134c:	8e180e68 */ 	lw	$t8,0xe68($s0)
/*  f111350:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f111354:	00001825 */ 	or	$v1,$zero,$zero
/*  f111358:	a3020888 */ 	sb	$v0,0x888($t8)
/*  f11135c:	8e190e68 */ 	lw	$t9,0xe68($s0)
/*  f111360:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f111364:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f111368:	a3220889 */ 	sb	$v0,0x889($t9)
/*  f11136c:	8e080e68 */ 	lw	$t0,0xe68($s0)
/*  f111370:	a100088a */ 	sb	$zero,0x88a($t0)
/*  f111374:	8e0a0e68 */ 	lw	$t2,0xe68($s0)
/*  f111378:	a149088b */ 	sb	$t1,0x88b($t2)
/*  f11137c:	8e0b0e68 */ 	lw	$t3,0xe68($s0)
/*  f111380:	a160088c */ 	sb	$zero,0x88c($t3)
/*  f111384:	8e0c0e68 */ 	lw	$t4,0xe68($s0)
/*  f111388:	a180088d */ 	sb	$zero,0x88d($t4)
/*  f11138c:	8e0e0e68 */ 	lw	$t6,0xe68($s0)
/*  f111390:	a1cd088e */ 	sb	$t5,0x88e($t6)
/*  f111394:	8e0f0e68 */ 	lw	$t7,0xe68($s0)
/*  f111398:	a1e0088f */ 	sb	$zero,0x88f($t7)
/*  f11139c:	00001025 */ 	or	$v0,$zero,$zero
.L0f1113a0:
/*  f1113a0:	8e190e68 */ 	lw	$t9,0xe68($s0)
/*  f1113a4:	000341c0 */ 	sll	$t0,$v1,0x7
/*  f1113a8:	0040c025 */ 	or	$t8,$v0,$zero
/*  f1113ac:	03284821 */ 	addu	$t1,$t9,$t0
/*  f1113b0:	01225021 */ 	addu	$t2,$t1,$v0
/*  f1113b4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1113b8:	1444fff9 */ 	bne	$v0,$a0,.L0f1113a0
/*  f1113bc:	a1580000 */ 	sb	$t8,0x0($t2)
/*  f1113c0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1113c4:	5465fff6 */ 	bnel	$v1,$a1,.L0f1113a0
/*  f1113c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1113cc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1113d0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1113d4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1113d8:	03e00008 */ 	jr	$ra
/*  f1113dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1113e0:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f1113e4:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f1113e8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1113ec:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f1113f0:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f1113f4:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f1113f8:	3c0f800a */ 	lui	$t7,%hi(var8009e000)
/*  f1113fc:	25efe000 */ 	addiu	$t7,$t7,%lo(var8009e000)
/*  f111400:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f111404:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f111408:	8c780e68 */ 	lw	$t8,0xe68($v1)
/*  f11140c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f111410:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f111414:	5300000f */ 	beqzl	$t8,.L0f111454
/*  f111418:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11141c:	8c790e40 */ 	lw	$t9,0xe40($v1)
/*  f111420:	24040890 */ 	addiu	$a0,$zero,0x890
/*  f111424:	00194840 */ 	sll	$t1,$t9,0x1
/*  f111428:	05230009 */ 	bgezl	$t1,.L0f111450
/*  f11142c:	ac600e68 */ 	sw	$zero,0xe68($v1)
/*  f111430:	0fc5db69 */ 	jal	func0f176da4
/*  f111434:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f111438:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f11143c:	00402825 */ 	or	$a1,$v0,$zero
/*  f111440:	0c004b2d */ 	jal	func00012cb4
/*  f111444:	8c640e68 */ 	lw	$a0,0xe68($v1)
/*  f111448:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f11144c:	ac600e68 */ 	sw	$zero,0xe68($v1)
.L0f111450:
/*  f111450:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f111454:
/*  f111454:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f111458:	03e00008 */ 	jr	$ra
/*  f11145c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f111460
/*  f111460:	000470c0 */ 	sll	$t6,$a0,0x3
/*  f111464:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f111468:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11146c:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f111470:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f111474:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f111478:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f11147c:	3c0f800a */ 	lui	$t7,%hi(var8009e000)
/*  f111480:	25efe000 */ 	addiu	$t7,$t7,%lo(var8009e000)
/*  f111484:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f111488:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11148c:	01cf5021 */ 	addu	$t2,$t6,$t7
/*  f111490:	30d0ffff */ 	andi	$s0,$a2,0xffff
/*  f111494:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f111498:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f11149c:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f1114a0:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f1114a4:	8d420e68 */ 	lw	$v0,0xe68($t2)
/*  f1114a8:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f1114ac:	00003825 */ 	or	$a3,$zero,$zero
.L0f1114b0:
/*  f1114b0:	8c430800 */ 	lw	$v1,0x800($v0)
/*  f1114b4:	14a30006 */ 	bne	$a1,$v1,.L0f1114d0
/*  f1114b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1114bc:	94580804 */ 	lhu	$t8,0x804($v0)
/*  f1114c0:	16180003 */ 	bne	$s0,$t8,.L0f1114d0
/*  f1114c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1114c8:	1000000a */ 	beqz	$zero,.L0f1114f4
/*  f1114cc:	00e04825 */ 	or	$t1,$a3,$zero
.L0f1114d0:
/*  f1114d0:	54600006 */ 	bnezl	$v1,.L0f1114ec
/*  f1114d4:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f1114d8:	94590804 */ 	lhu	$t9,0x804($v0)
/*  f1114dc:	57200003 */ 	bnezl	$t9,.L0f1114ec
/*  f1114e0:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f1114e4:	00e04025 */ 	or	$t0,$a3,$zero
/*  f1114e8:	24e70001 */ 	addiu	$a3,$a3,0x1
.L0f1114ec:
/*  f1114ec:	14e4fff0 */ 	bne	$a3,$a0,.L0f1114b0
/*  f1114f0:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f1114f4:
/*  f1114f4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1114f8:	1521002f */ 	bne	$t1,$at,.L0f1115b8
/*  f1114fc:	02002025 */ 	or	$a0,$s0,$zero
/*  f111500:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f111504:	afa80030 */ 	sw	$t0,0x30($sp)
/*  f111508:	0fc479ac */ 	jal	func0f11e6b0
/*  f11150c:	afaa0024 */ 	sw	$t2,0x24($sp)
/*  f111510:	00022600 */ 	sll	$a0,$v0,0x18
/*  f111514:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f111518:	01602025 */ 	or	$a0,$t3,$zero
/*  f11151c:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f111520:	8fa80030 */ 	lw	$t0,0x30($sp)
/*  f111524:	04410003 */ 	bgez	$v0,.L0f111534
/*  f111528:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f11152c:	1000002d */ 	beqz	$zero,.L0f1115e4
/*  f111530:	00001025 */ 	or	$v0,$zero,$zero
.L0f111534:
/*  f111534:	2401ffff */ 	addiu	$at,$zero,-1
/*  f111538:	55010004 */ 	bnel	$t0,$at,.L0f11154c
/*  f11153c:	8d430e68 */ 	lw	$v1,0xe68($t2)
/*  f111540:	10000028 */ 	beqz	$zero,.L0f1115e4
/*  f111544:	00001025 */ 	or	$v0,$zero,$zero
/*  f111548:	8d430e68 */ 	lw	$v1,0xe68($t2)
.L0f11154c:
/*  f11154c:	3c02800a */ 	lui	$v0,%hi(var800a0884)
/*  f111550:	8c42a018 */ 	lw	$v0,-0x5fe8($v0)
/*  f111554:	8c6c0880 */ 	lw	$t4,0x880($v1)
/*  f111558:	000879c0 */ 	sll	$t7,$t0,0x7
/*  f11155c:	004c6823 */ 	subu	$t5,$v0,$t4
/*  f111560:	29a10014 */ 	slti	$at,$t5,0x14
/*  f111564:	50200004 */ 	beqzl	$at,.L0f111578
/*  f111568:	ac620880 */ 	sw	$v0,0x880($v1)
/*  f11156c:	1000001d */ 	beqz	$zero,.L0f1115e4
/*  f111570:	00001025 */ 	or	$v0,$zero,$zero
/*  f111574:	ac620880 */ 	sw	$v0,0x880($v1)
.L0f111578:
/*  f111578:	8d4e0e68 */ 	lw	$t6,0xe68($t2)
/*  f11157c:	afaa0024 */ 	sw	$t2,0x24($sp)
/*  f111580:	afa80030 */ 	sw	$t0,0x30($sp)
/*  f111584:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f111588:	0fc54057 */ 	jal	func0f15015c
/*  f11158c:	01cf3021 */ 	addu	$a2,$t6,$t7
/*  f111590:	8faa0024 */ 	lw	$t2,0x24($sp)
/*  f111594:	8fa90030 */ 	lw	$t1,0x30($sp)
/*  f111598:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f11159c:	8d580e68 */ 	lw	$t8,0xe68($t2)
/*  f1115a0:	000918c0 */ 	sll	$v1,$t1,0x3
/*  f1115a4:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f1115a8:	af250800 */ 	sw	$a1,0x800($t9)
/*  f1115ac:	8d4b0e68 */ 	lw	$t3,0xe68($t2)
/*  f1115b0:	01636021 */ 	addu	$t4,$t3,$v1
/*  f1115b4:	a5900804 */ 	sh	$s0,0x804($t4)
.L0f1115b8:
/*  f1115b8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1115bc:	55210004 */ 	bnel	$t1,$at,.L0f1115d0
/*  f1115c0:	8d430e68 */ 	lw	$v1,0xe68($t2)
/*  f1115c4:	10000007 */ 	beqz	$zero,.L0f1115e4
/*  f1115c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1115cc:	8d430e68 */ 	lw	$v1,0xe68($t2)
.L0f1115d0:
/*  f1115d0:	000969c0 */ 	sll	$t5,$t1,0x7
/*  f1115d4:	006d7021 */ 	addu	$t6,$v1,$t5
/*  f1115d8:	ac6e0884 */ 	sw	$t6,0x884($v1)
/*  f1115dc:	8d420e68 */ 	lw	$v0,0xe68($t2)
/*  f1115e0:	24420884 */ 	addiu	$v0,$v0,%lo(var800a0884)
.L0f1115e4:
/*  f1115e4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1115e8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1115ec:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f1115f0:	03e00008 */ 	jr	$ra
/*  f1115f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1115f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1115fc:	00000000 */ 	sll	$zero,$zero,0x0
);

const char var7f1b38b4[] = "ctcol";
const char var7f1b38bc[] = "\n";
const char var7f1b38c0[] = "Flag %d = %s";
const char var7f1b38d0[] = "TRUE";
const char var7f1b38d8[] = "FALSE";
const char var7f1b38e0[] = "Dark";
const char var7f1b38e8[] = "MAX_FUDGE_DATA_SIZE>=sizeof(PakFileTypeGameSetup_s)";
const char var7f1b391c[] = "pdoptions.c";
const char var7f1b3928[] = "MAX_FUDGE_DATA_SIZE>=sizeof(PakFileTypeGameSetup_s)";
const char var7f1b395c[] = "pdoptions.c";
const char var7f1b3968[] = "MAX_FUDGE_DATA_SIZE>=sizeof(PakFileTypeGameSetup_s)";
const char var7f1b399c[] = "pdoptions.c";
const char var7f1b39a8[] = "";
const char var7f1b39ac[] = "";
const char var7f1b39b0[] = "fileGuid";
const char var7f1b39bc[] = "bossfile.c";
const char var7f1b39c8[] = "";
const char var7f1b39cc[] = "";
const char var7f1b39d0[] = "Rebuilding pakWad %d:\n";

const u32 var7f1b39e8[] = {0x00000080};
const u32 var7f1b39ec[] = {0x00000040};
const u32 var7f1b39f0[] = {0x00000020};
const u32 var7f1b39f4[] = {0x00000008};
const u32 var7f1b39f8[] = {0x04000102};
const u32 var7f1b39fc[] = {0x03000000};
const u32 var7f1b3a00[] = {0x01020304};
const u32 var7f1b3a04[] = {0x00000000};

const char var7f1b3a08[] = "tc != NULL";
const char var7f1b3a14[] = "gamefile.c";
