#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/propobj.h"
#include "game/game_092610.h"
#include "game/game_0b0420.h"
#include "game/game_0b63b0.h"
#include "game/game_0d4690.h"
#include "game/game_0dcdb0.h"
#include "game/game_0e0770.h"
#include "game/game_127910.h"
#include "game/game_1531a0.h"
#include "game/game_167ae0.h"
#include "game/mplayer.h"
#include "game/pdoptions.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_121e0.h"
#include "lib/lib_13130.h"
#include "lib/lib_16110.h"
#include "lib/lib_4a360.h"
#include "lib/lib_4a5e0.h"
#include "types.h"

const char var7f1ade80[] = "%s%s%4.2fX";
const char var7f1ade8c[] = "";
const char var7f1ade90[] = "";
const char var7f1ade94[] = "/";
const char var7f1ade98[] = "%s%s%4.2fX";
const char var7f1adea4[] = "";
const char var7f1adea8[] = "";

GLOBAL_ASM(
glabel func0f0dcdb0
/*  f0dcdb0:	3c028007 */ 	lui	$v0,%hi(var80070fb0)
/*  f0dcdb4:	03e00008 */ 	jr	$ra
/*  f0dcdb8:	90420fb0 */ 	lbu	$v0,%lo(var80070fb0)($v0)
);

GLOBAL_ASM(
glabel func0f0dcdbc
/*  f0dcdbc:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0dcdc0:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0dcdc4:	8cae0288 */ 	lw	$t6,0x288($a1)
/*  f0dcdc8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0dcdcc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0dcdd0:	0fc54a28 */ 	jal	optionsGetShowZoomRange
/*  f0dcdd4:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0dcdd8:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0dcddc:	0002782b */ 	sltu	$t7,$zero,$v0
/*  f0dcde0:	01e01025 */ 	or	$v0,$t7,$zero
/*  f0dcde4:	11e0003f */ 	beqz	$t7,.L0f0dcee4
/*  f0dcde8:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0dcdec:	8cb8006c */ 	lw	$t8,0x6c($a1)
/*  f0dcdf0:	00003825 */ 	or	$a3,$zero,$zero
/*  f0dcdf4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0dcdf8:	13000003 */ 	beqz	$t8,.L0f0dce08
/*  f0dcdfc:	00003025 */ 	or	$a2,$zero,$zero
/*  f0dce00:	10000001 */ 	beqz	$zero,.L0f0dce08
/*  f0dce04:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0dce08:
/*  f0dce08:	8cb90068 */ 	lw	$t9,0x68($a1)
/*  f0dce0c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0dce10:	13200003 */ 	beqz	$t9,.L0f0dce20
/*  f0dce14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dce18:	10000001 */ 	beqz	$zero,.L0f0dce20
/*  f0dce1c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0dce20:
/*  f0dce20:	8ca80064 */ 	lw	$t0,0x64($a1)
/*  f0dce24:	11000003 */ 	beqz	$t0,.L0f0dce34
/*  f0dce28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dce2c:	10000001 */ 	beqz	$zero,.L0f0dce34
/*  f0dce30:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0dce34:
/*  f0dce34:	8ca90070 */ 	lw	$t1,0x70($a1)
/*  f0dce38:	11200003 */ 	beqz	$t1,.L0f0dce48
/*  f0dce3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dce40:	10000001 */ 	beqz	$zero,.L0f0dce48
/*  f0dce44:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0dce48:
/*  f0dce48:	00665021 */ 	addu	$t2,$v1,$a2
/*  f0dce4c:	01445821 */ 	addu	$t3,$t2,$a0
/*  f0dce50:	01671021 */ 	addu	$v0,$t3,$a3
/*  f0dce54:	384c0001 */ 	xori	$t4,$v0,0x1
/*  f0dce58:	1180000d */ 	beqz	$t4,.L0f0dce90
/*  f0dce5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dce60:	8ca20314 */ 	lw	$v0,0x314($a1)
/*  f0dce64:	2c4d0001 */ 	sltiu	$t5,$v0,0x1
/*  f0dce68:	15a00009 */ 	bnez	$t5,.L0f0dce90
/*  f0dce6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dce70:	8ca20298 */ 	lw	$v0,0x298($a1)
/*  f0dce74:	04410006 */ 	bgez	$v0,.L0f0dce90
/*  f0dce78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dce7c:	8ca2029c */ 	lw	$v0,0x29c($a1)
/*  f0dce80:	284f0000 */ 	slti	$t7,$v0,0x0
/*  f0dce84:	39e20001 */ 	xori	$v0,$t7,0x1
/*  f0dce88:	50400017 */ 	beqzl	$v0,.L0f0dcee8
/*  f0dce8c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0dce90:
/*  f0dce90:	3c028007 */ 	lui	$v0,%hi(var80075d60)
/*  f0dce94:	8c425d60 */ 	lw	$v0,%lo(var80075d60)($v0)
/*  f0dce98:	38580002 */ 	xori	$t8,$v0,0x2
/*  f0dce9c:	2f020001 */ 	sltiu	$v0,$t8,0x1
/*  f0dcea0:	50400011 */ 	beqzl	$v0,.L0f0dcee8
/*  f0dcea4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0dcea8:	0fc2c7d6 */ 	jal	currentPlayerGetSight
/*  f0dceac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dceb0:	38590005 */ 	xori	$t9,$v0,0x5
/*  f0dceb4:	2f220001 */ 	sltiu	$v0,$t9,0x1
/*  f0dceb8:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f0dcebc:	10400009 */ 	beqz	$v0,.L0f0dcee4
/*  f0dcec0:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f0dcec4:	8ca80284 */ 	lw	$t0,0x284($a1)
/*  f0dcec8:	8d030000 */ 	lw	$v1,0x0($t0)
/*  f0dcecc:	38620002 */ 	xori	$v0,$v1,0x2
/*  f0dced0:	0002102b */ 	sltu	$v0,$zero,$v0
/*  f0dced4:	50400004 */ 	beqzl	$v0,.L0f0dcee8
/*  f0dced8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0dcedc:	38620001 */ 	xori	$v0,$v1,0x1
/*  f0dcee0:	0002102b */ 	sltu	$v0,$zero,$v0
.L0f0dcee4:
/*  f0dcee4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f0dcee8:
/*  f0dcee8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0dceec:	03e00008 */ 	jr	$ra
/*  f0dcef0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0dcef4
/*  f0dcef4:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f0dcef8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0dcefc:	afa40090 */ 	sw	$a0,0x90($sp)
/*  f0dcf00:	0c002f40 */ 	jal	func0000bd00
/*  f0dcf04:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f0dcf08:	3c0e8008 */ 	lui	$t6,%hi(var8007fac0)
/*  f0dcf0c:	8dcefac0 */ 	lw	$t6,%lo(var8007fac0)($t6)
/*  f0dcf10:	004e001a */ 	div	$zero,$v0,$t6
/*  f0dcf14:	00007812 */ 	mflo	$t7
/*  f0dcf18:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f0dcf1c:	15c00002 */ 	bnez	$t6,.L0f0dcf28
/*  f0dcf20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcf24:	0007000d */ 	break	0x7
.L0f0dcf28:
/*  f0dcf28:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0dcf2c:	15c10004 */ 	bne	$t6,$at,.L0f0dcf40
/*  f0dcf30:	3c018000 */ 	lui	$at,0x8000
/*  f0dcf34:	14410002 */ 	bne	$v0,$at,.L0f0dcf40
/*  f0dcf38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcf3c:	0006000d */ 	break	0x6
.L0f0dcf40:
/*  f0dcf40:	0c002f44 */ 	jal	func0000bd10
/*  f0dcf44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcf48:	0c002f26 */ 	jal	func0000bc98
/*  f0dcf4c:	a7a20056 */ 	sh	$v0,0x56($sp)
/*  f0dcf50:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0dcf54:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0dcf58:	8c98006c */ 	lw	$t8,0x6c($a0)
/*  f0dcf5c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0dcf60:	53000004 */ 	beqzl	$t8,.L0f0dcf74
/*  f0dcf64:	00005025 */ 	or	$t2,$zero,$zero
/*  f0dcf68:	10000002 */ 	beqz	$zero,.L0f0dcf74
/*  f0dcf6c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0dcf70:	00005025 */ 	or	$t2,$zero,$zero
.L0f0dcf74:
/*  f0dcf74:	8c990068 */ 	lw	$t9,0x68($a0)
/*  f0dcf78:	3c188007 */ 	lui	$t8,%hi(var80070fe0)
/*  f0dcf7c:	53200004 */ 	beqzl	$t9,.L0f0dcf90
/*  f0dcf80:	00004025 */ 	or	$t0,$zero,$zero
/*  f0dcf84:	10000002 */ 	beqz	$zero,.L0f0dcf90
/*  f0dcf88:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0dcf8c:	00004025 */ 	or	$t0,$zero,$zero
.L0f0dcf90:
/*  f0dcf90:	8c8b0064 */ 	lw	$t3,0x64($a0)
/*  f0dcf94:	3c198009 */ 	lui	$t9,%hi(g_Is4Mb)
/*  f0dcf98:	51600004 */ 	beqzl	$t3,.L0f0dcfac
/*  f0dcf9c:	00004825 */ 	or	$t1,$zero,$zero
/*  f0dcfa0:	10000002 */ 	beqz	$zero,.L0f0dcfac
/*  f0dcfa4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0dcfa8:	00004825 */ 	or	$t1,$zero,$zero
.L0f0dcfac:
/*  f0dcfac:	8c8c0070 */ 	lw	$t4,0x70($a0)
/*  f0dcfb0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0dcfb4:	11800003 */ 	beqz	$t4,.L0f0dcfc4
/*  f0dcfb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcfbc:	10000001 */ 	beqz	$zero,.L0f0dcfc4
/*  f0dcfc0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0dcfc4:
/*  f0dcfc4:	87ae0056 */ 	lh	$t6,0x56($sp)
/*  f0dcfc8:	8f180fe0 */ 	lw	$t8,%lo(var80070fe0)($t8)
/*  f0dcfcc:	93390af0 */ 	lbu	$t9,%lo(g_Is4Mb)($t9)
/*  f0dcfd0:	8c8d028c */ 	lw	$t5,0x28c($a0)
/*  f0dcfd4:	004e7821 */ 	addu	$t7,$v0,$t6
/*  f0dcfd8:	01f83823 */ 	subu	$a3,$t7,$t8
/*  f0dcfdc:	24e7fff8 */ 	addiu	$a3,$a3,-8
/*  f0dcfe0:	10b9000e */ 	beq	$a1,$t9,.L0f0dd01c
/*  f0dcfe4:	afad0058 */ 	sw	$t5,0x58($sp)
/*  f0dcfe8:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0dcfec:	afa70080 */ 	sw	$a3,0x80($sp)
/*  f0dcff0:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0dcff4:	afa9004c */ 	sw	$t1,0x4c($sp)
/*  f0dcff8:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0dcffc:	afaa0044 */ 	sw	$t2,0x44($sp)
/*  f0dd000:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0dd004:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0dd008:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0dd00c:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0dd010:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f0dd014:	14a2000f */ 	bne	$a1,$v0,.L0f0dd054
/*  f0dd018:	8faa0044 */ 	lw	$t2,0x44($sp)
.L0f0dd01c:
/*  f0dd01c:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0dd020:	afa70080 */ 	sw	$a3,0x80($sp)
/*  f0dd024:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0dd028:	afa9004c */ 	sw	$t1,0x4c($sp)
/*  f0dd02c:	0fc24211 */ 	jal	countdownTimerIsHidden
/*  f0dd030:	afaa0044 */ 	sw	$t2,0x44($sp)
/*  f0dd034:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0dd038:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0dd03c:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0dd040:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0dd044:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f0dd048:	10400002 */ 	beqz	$v0,.L0f0dd054
/*  f0dd04c:	8faa0044 */ 	lw	$t2,0x44($sp)
/*  f0dd050:	24e7fff8 */ 	addiu	$a3,$a3,-8
.L0f0dd054:
/*  f0dd054:	3c0b8009 */ 	lui	$t3,%hi(g_Is4Mb)
/*  f0dd058:	916b0af0 */ 	lbu	$t3,%lo(g_Is4Mb)($t3)
/*  f0dd05c:	50ab0014 */ 	beql	$a1,$t3,.L0f0dd0b0
/*  f0dd060:	00c97021 */ 	addu	$t6,$a2,$t1
/*  f0dd064:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0dd068:	afa70080 */ 	sw	$a3,0x80($sp)
/*  f0dd06c:	afa80048 */ 	sw	$t0,0x48($sp)
/*  f0dd070:	afa9004c */ 	sw	$t1,0x4c($sp)
/*  f0dd074:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0dd078:	afaa0044 */ 	sw	$t2,0x44($sp)
/*  f0dd07c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0dd080:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0dd084:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0dd088:	8fa80048 */ 	lw	$t0,0x48($sp)
/*  f0dd08c:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f0dd090:	10a20006 */ 	beq	$a1,$v0,.L0f0dd0ac
/*  f0dd094:	8faa0044 */ 	lw	$t2,0x44($sp)
/*  f0dd098:	00c96021 */ 	addu	$t4,$a2,$t1
/*  f0dd09c:	01886821 */ 	addu	$t5,$t4,$t0
/*  f0dd0a0:	01aa1821 */ 	addu	$v1,$t5,$t2
/*  f0dd0a4:	28610003 */ 	slti	$at,$v1,0x3
/*  f0dd0a8:	1420000b */ 	bnez	$at,.L0f0dd0d8
.L0f0dd0ac:
/*  f0dd0ac:	00c97021 */ 	addu	$t6,$a2,$t1
.L0f0dd0b0:
/*  f0dd0b0:	01c87821 */ 	addu	$t7,$t6,$t0
/*  f0dd0b4:	01ea1821 */ 	addu	$v1,$t7,$t2
/*  f0dd0b8:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f0dd0bc:	0fc3736f */ 	jal	func0f0dcdbc
/*  f0dd0c0:	afa70080 */ 	sw	$a3,0x80($sp)
/*  f0dd0c4:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f0dd0c8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0dd0cc:	10400002 */ 	beqz	$v0,.L0f0dd0d8
/*  f0dd0d0:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0dd0d4:	24e7fff8 */ 	addiu	$a3,$a3,-8
.L0f0dd0d8:
/*  f0dd0d8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0dd0dc:	14610012 */ 	bne	$v1,$at,.L0f0dd128
/*  f0dd0e0:	3c188009 */ 	lui	$t8,%hi(g_Is4Mb)
/*  f0dd0e4:	93180af0 */ 	lbu	$t8,%lo(g_Is4Mb)($t8)
/*  f0dd0e8:	10b8000b */ 	beq	$a1,$t8,.L0f0dd118
/*  f0dd0ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd0f0:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f0dd0f4:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0dd0f8:	afa70080 */ 	sw	$a3,0x80($sp)
/*  f0dd0fc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0dd100:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f0dd104:	10a20006 */ 	beq	$a1,$v0,.L0f0dd120
/*  f0dd108:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0dd10c:	8fb90058 */ 	lw	$t9,0x58($sp)
/*  f0dd110:	17200003 */ 	bnez	$t9,.L0f0dd120
/*  f0dd114:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0dd118:
/*  f0dd118:	10000015 */ 	beqz	$zero,.L0f0dd170
/*  f0dd11c:	24e7000a */ 	addiu	$a3,$a3,0xa
.L0f0dd120:
/*  f0dd120:	10000013 */ 	beqz	$zero,.L0f0dd170
/*  f0dd124:	24e70002 */ 	addiu	$a3,$a3,0x2
.L0f0dd128:
/*  f0dd128:	28610003 */ 	slti	$at,$v1,0x3
/*  f0dd12c:	14200008 */ 	bnez	$at,.L0f0dd150
/*  f0dd130:	8fab0058 */ 	lw	$t3,0x58($sp)
/*  f0dd134:	29610002 */ 	slti	$at,$t3,0x2
/*  f0dd138:	10200003 */ 	beqz	$at,.L0f0dd148
/*  f0dd13c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd140:	1000000b */ 	beqz	$zero,.L0f0dd170
/*  f0dd144:	24e7000a */ 	addiu	$a3,$a3,0xa
.L0f0dd148:
/*  f0dd148:	10000009 */ 	beqz	$zero,.L0f0dd170
/*  f0dd14c:	24e70002 */ 	addiu	$a3,$a3,0x2
.L0f0dd150:
/*  f0dd150:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f0dd154:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f0dd158:	afa70080 */ 	sw	$a3,0x80($sp)
/*  f0dd15c:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f0dd160:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0dd164:	10400002 */ 	beqz	$v0,.L0f0dd170
/*  f0dd168:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0dd16c:	24e70008 */ 	addiu	$a3,$a3,0x8
.L0f0dd170:
/*  f0dd170:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0dd174:	54610013 */ 	bnel	$v1,$at,.L0f0dd1c4
/*  f0dd178:	28610003 */ 	slti	$at,$v1,0x3
/*  f0dd17c:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f0dd180:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0dd184:	afa70080 */ 	sw	$a3,0x80($sp)
/*  f0dd188:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0dd18c:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f0dd190:	10a20005 */ 	beq	$a1,$v0,.L0f0dd1a8
/*  f0dd194:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0dd198:	3c0c8009 */ 	lui	$t4,%hi(g_Is4Mb)
/*  f0dd19c:	918c0af0 */ 	lbu	$t4,%lo(g_Is4Mb)($t4)
/*  f0dd1a0:	54ac0008 */ 	bnel	$a1,$t4,.L0f0dd1c4
/*  f0dd1a4:	28610003 */ 	slti	$at,$v1,0x3
.L0f0dd1a8:
/*  f0dd1a8:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f0dd1ac:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f0dd1b0:	15a50003 */ 	bne	$t5,$a1,.L0f0dd1c0
/*  f0dd1b4:	25cffff2 */ 	addiu	$t7,$t6,-14
/*  f0dd1b8:	10000009 */ 	beqz	$zero,.L0f0dd1e0
/*  f0dd1bc:	afaf0084 */ 	sw	$t7,0x84($sp)
.L0f0dd1c0:
/*  f0dd1c0:	28610003 */ 	slti	$at,$v1,0x3
.L0f0dd1c4:
/*  f0dd1c4:	14200006 */ 	bnez	$at,.L0f0dd1e0
/*  f0dd1c8:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f0dd1cc:	33190001 */ 	andi	$t9,$t8,0x1
/*  f0dd1d0:	14b90003 */ 	bne	$a1,$t9,.L0f0dd1e0
/*  f0dd1d4:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f0dd1d8:	256cfff2 */ 	addiu	$t4,$t3,-14
/*  f0dd1dc:	afac0084 */ 	sw	$t4,0x84($sp)
.L0f0dd1e0:
/*  f0dd1e0:	8fa30094 */ 	lw	$v1,0x94($sp)
/*  f0dd1e4:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0dd1e8:	afa70080 */ 	sw	$a3,0x80($sp)
/*  f0dd1ec:	00036880 */ 	sll	$t5,$v1,0x2
/*  f0dd1f0:	01a36821 */ 	addu	$t5,$t5,$v1
/*  f0dd1f4:	000d6940 */ 	sll	$t5,$t5,0x5
/*  f0dd1f8:	01a1001b */ 	divu	$zero,$t5,$at
/*  f0dd1fc:	00007012 */ 	mflo	$t6
/*  f0dd200:	3c0100ff */ 	lui	$at,0xff
/*  f0dd204:	01c17825 */ 	or	$t7,$t6,$at
/*  f0dd208:	0fc3089f */ 	jal	getMissionTime
/*  f0dd20c:	afaf0064 */ 	sw	$t7,0x64($sp)
/*  f0dd210:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0dd214:	00402825 */ 	or	$a1,$v0,$zero
/*  f0dd218:	0fc355f8 */ 	jal	formatTime
/*  f0dd21c:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f0dd220:	3c198007 */ 	lui	$t9,%hi(var80070fe4)
/*  f0dd224:	8f390fe4 */ 	lw	$t9,%lo(var80070fe4)($t9)
/*  f0dd228:	8fb80084 */ 	lw	$t8,0x84($sp)
/*  f0dd22c:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0dd230:	03195821 */ 	addu	$t3,$t8,$t9
/*  f0dd234:	256c0003 */ 	addiu	$t4,$t3,0x3
/*  f0dd238:	afac008c */ 	sw	$t4,0x8c($sp)
/*  f0dd23c:	0c002f02 */ 	jal	func0000bc08
/*  f0dd240:	afa70088 */ 	sw	$a3,0x88($sp)
/*  f0dd244:	0c002f06 */ 	jal	func0000bc18
/*  f0dd248:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f0dd24c:	3c0d8008 */ 	lui	$t5,%hi(var8007fb00)
/*  f0dd250:	3c0e8008 */ 	lui	$t6,%hi(var8007fafc)
/*  f0dd254:	8dcefafc */ 	lw	$t6,%lo(var8007fafc)($t6)
/*  f0dd258:	8dadfb00 */ 	lw	$t5,%lo(var8007fb00)($t5)
/*  f0dd25c:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f0dd260:	87b90042 */ 	lh	$t9,0x42($sp)
/*  f0dd264:	241800a0 */ 	addiu	$t8,$zero,0xa0
/*  f0dd268:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0dd26c:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f0dd270:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f0dd274:	27a60088 */ 	addiu	$a2,$sp,0x88
/*  f0dd278:	27a70068 */ 	addiu	$a3,$sp,0x68
/*  f0dd27c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0dd280:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0dd284:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0dd288:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0dd28c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0dd290:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0dd294:	0fc55b92 */ 	jal	func0f156e48
/*  f0dd298:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0dd29c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0dd2a0:	27bd0090 */ 	addiu	$sp,$sp,0x90
/*  f0dd2a4:	03e00008 */ 	jr	$ra
/*  f0dd2a8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0dd2ac
/*  f0dd2ac:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f0dd2b0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0dd2b4:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0dd2b8:	afa400c0 */ 	sw	$a0,0xc0($sp)
/*  f0dd2bc:	0c002f44 */ 	jal	func0000bd10
/*  f0dd2c0:	afa500c4 */ 	sw	$a1,0xc4($sp)
/*  f0dd2c4:	0c002f40 */ 	jal	func0000bd00
/*  f0dd2c8:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f0dd2cc:	3c108008 */ 	lui	$s0,%hi(var8007fac0)
/*  f0dd2d0:	2610fac0 */ 	addiu	$s0,$s0,%lo(var8007fac0)
/*  f0dd2d4:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0dd2d8:	004e001a */ 	div	$zero,$v0,$t6
/*  f0dd2dc:	00007812 */ 	mflo	$t7
/*  f0dd2e0:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f0dd2e4:	15c00002 */ 	bnez	$t6,.L0f0dd2f0
/*  f0dd2e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd2ec:	0007000d */ 	break	0x7
.L0f0dd2f0:
/*  f0dd2f0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0dd2f4:	15c10004 */ 	bne	$t6,$at,.L0f0dd308
/*  f0dd2f8:	3c018000 */ 	lui	$at,0x8000
/*  f0dd2fc:	14410002 */ 	bne	$v0,$at,.L0f0dd308
/*  f0dd300:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd304:	0006000d */ 	break	0x6
.L0f0dd308:
/*  f0dd308:	0c002f22 */ 	jal	func0000bc88
/*  f0dd30c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd310:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0dd314:	0058001a */ 	div	$zero,$v0,$t8
/*  f0dd318:	0000c812 */ 	mflo	$t9
/*  f0dd31c:	00194843 */ 	sra	$t1,$t9,0x1
/*  f0dd320:	17000002 */ 	bnez	$t8,.L0f0dd32c
/*  f0dd324:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd328:	0007000d */ 	break	0x7
.L0f0dd32c:
/*  f0dd32c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0dd330:	17010004 */ 	bne	$t8,$at,.L0f0dd344
/*  f0dd334:	3c018000 */ 	lui	$at,0x8000
/*  f0dd338:	14410002 */ 	bne	$v0,$at,.L0f0dd344
/*  f0dd33c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd340:	0006000d */ 	break	0x6
.L0f0dd344:
/*  f0dd344:	afa900b4 */ 	sw	$t1,0xb4($sp)
/*  f0dd348:	0c002f26 */ 	jal	func0000bc98
/*  f0dd34c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd350:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0dd354:	3c013f80 */ 	lui	$at,0x3f80
/*  f0dd358:	44812000 */ 	mtc1	$at,$f4
/*  f0dd35c:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0dd360:	8ccb0284 */ 	lw	$t3,0x284($a2)
/*  f0dd364:	8faa00bc */ 	lw	$t2,0xbc($sp)
/*  f0dd368:	8ccd006c */ 	lw	$t5,0x6c($a2)
/*  f0dd36c:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*  f0dd370:	916c0638 */ 	lbu	$t4,0x638($t3)
/*  f0dd374:	004a8021 */ 	addu	$s0,$v0,$t2
/*  f0dd378:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f0dd37c:	11a00003 */ 	beqz	$t5,.L0f0dd38c
/*  f0dd380:	afac0080 */ 	sw	$t4,0x80($sp)
/*  f0dd384:	10000002 */ 	beqz	$zero,.L0f0dd390
/*  f0dd388:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0dd38c:
/*  f0dd38c:	00003825 */ 	or	$a3,$zero,$zero
.L0f0dd390:
/*  f0dd390:	8cce0068 */ 	lw	$t6,0x68($a2)
/*  f0dd394:	00002825 */ 	or	$a1,$zero,$zero
/*  f0dd398:	00001825 */ 	or	$v1,$zero,$zero
/*  f0dd39c:	11c00003 */ 	beqz	$t6,.L0f0dd3ac
/*  f0dd3a0:	2610ffef */ 	addiu	$s0,$s0,-17
/*  f0dd3a4:	10000001 */ 	beqz	$zero,.L0f0dd3ac
/*  f0dd3a8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0dd3ac:
/*  f0dd3ac:	8ccf0064 */ 	lw	$t7,0x64($a2)
/*  f0dd3b0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0dd3b4:	11e00003 */ 	beqz	$t7,.L0f0dd3c4
/*  f0dd3b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd3bc:	10000001 */ 	beqz	$zero,.L0f0dd3c4
/*  f0dd3c0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0dd3c4:
/*  f0dd3c4:	8cd80070 */ 	lw	$t8,0x70($a2)
/*  f0dd3c8:	13000003 */ 	beqz	$t8,.L0f0dd3d8
/*  f0dd3cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd3d0:	10000001 */ 	beqz	$zero,.L0f0dd3d8
/*  f0dd3d4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0dd3d8:
/*  f0dd3d8:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f0dd3dc:	afa4005c */ 	sw	$a0,0x5c($sp)
/*  f0dd3e0:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0dd3e4:	0fc24211 */ 	jal	countdownTimerIsHidden
/*  f0dd3e8:	afa70050 */ 	sw	$a3,0x50($sp)
/*  f0dd3ec:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0dd3f0:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0dd3f4:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f0dd3f8:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f0dd3fc:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0dd400:	10400002 */ 	beqz	$v0,.L0f0dd40c
/*  f0dd404:	8fa70050 */ 	lw	$a3,0x50($sp)
/*  f0dd408:	2610fff8 */ 	addiu	$s0,$s0,-8
.L0f0dd40c:
/*  f0dd40c:	0083c821 */ 	addu	$t9,$a0,$v1
/*  f0dd410:	03254821 */ 	addu	$t1,$t9,$a1
/*  f0dd414:	01271021 */ 	addu	$v0,$t1,$a3
/*  f0dd418:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0dd41c:	14410012 */ 	bne	$v0,$at,.L0f0dd468
/*  f0dd420:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0dd424:	914a0af0 */ 	lbu	$t2,%lo(g_Is4Mb)($t2)
/*  f0dd428:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0dd42c:	1141000a */ 	beq	$t2,$at,.L0f0dd458
/*  f0dd430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd434:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0dd438:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd43c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0dd440:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0dd444:	10410006 */ 	beq	$v0,$at,.L0f0dd460
/*  f0dd448:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0dd44c:	8ccb028c */ 	lw	$t3,0x28c($a2)
/*  f0dd450:	15600003 */ 	bnez	$t3,.L0f0dd460
/*  f0dd454:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0dd458:
/*  f0dd458:	10000013 */ 	beqz	$zero,.L0f0dd4a8
/*  f0dd45c:	2610000a */ 	addiu	$s0,$s0,0xa
.L0f0dd460:
/*  f0dd460:	10000011 */ 	beqz	$zero,.L0f0dd4a8
/*  f0dd464:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f0dd468:
/*  f0dd468:	28410003 */ 	slti	$at,$v0,0x3
/*  f0dd46c:	14200009 */ 	bnez	$at,.L0f0dd494
/*  f0dd470:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd474:	8ccc028c */ 	lw	$t4,0x28c($a2)
/*  f0dd478:	29810002 */ 	slti	$at,$t4,0x2
/*  f0dd47c:	10200003 */ 	beqz	$at,.L0f0dd48c
/*  f0dd480:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd484:	10000008 */ 	beqz	$zero,.L0f0dd4a8
/*  f0dd488:	2610000a */ 	addiu	$s0,$s0,0xa
.L0f0dd48c:
/*  f0dd48c:	10000006 */ 	beqz	$zero,.L0f0dd4a8
/*  f0dd490:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f0dd494:
/*  f0dd494:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f0dd498:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd49c:	10400002 */ 	beqz	$v0,.L0f0dd4a8
/*  f0dd4a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd4a4:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f0dd4a8:
/*  f0dd4a8:	0fc2c536 */ 	jal	func0f0b14d8
/*  f0dd4ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd4b0:	44803000 */ 	mtc1	$zero,$f6
/*  f0dd4b4:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0dd4b8:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0dd4bc:	46060032 */ 	c.eq.s	$f0,$f6
/*  f0dd4c0:	8ccd0284 */ 	lw	$t5,0x284($a2)
/*  f0dd4c4:	3c014270 */ 	lui	$at,0x4270
/*  f0dd4c8:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f0dd4cc:	45010006 */ 	bc1t	.L0f0dd4e8
/*  f0dd4d0:	c5ae1848 */ 	lwc1	$f14,0x1848($t5)
/*  f0dd4d4:	44818000 */ 	mtc1	$at,$f16
/*  f0dd4d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd4dc:	46100032 */ 	c.eq.s	$f0,$f16
/*  f0dd4e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd4e4:	45000008 */ 	bc1f	.L0f0dd508
.L0f0dd4e8:
/*  f0dd4e8:	24010015 */ 	addiu	$at,$zero,0x15
/*  f0dd4ec:	15c10004 */ 	bne	$t6,$at,.L0f0dd500
/*  f0dd4f0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0dd4f4:	44816000 */ 	mtc1	$at,$f12
/*  f0dd4f8:	1000000d */ 	beqz	$zero,.L0f0dd530
/*  f0dd4fc:	46006221 */ 	cvt.d.s	$f8,$f12
.L0f0dd500:
/*  f0dd500:	100000cc */ 	beqz	$zero,.L0f0dd834
/*  f0dd504:	8fa200c0 */ 	lw	$v0,0xc0($sp)
.L0f0dd508:
/*  f0dd508:	460e0283 */ 	div.s	$f10,$f0,$f14
/*  f0dd50c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0dd510:	44814000 */ 	mtc1	$at,$f8
/*  f0dd514:	44813000 */ 	mtc1	$at,$f6
/*  f0dd518:	46008083 */ 	div.s	$f2,$f16,$f0
/*  f0dd51c:	460a4483 */ 	div.s	$f18,$f8,$f10
/*  f0dd520:	e7a2009c */ 	swc1	$f2,0x9c($sp)
/*  f0dd524:	46121101 */ 	sub.s	$f4,$f2,$f18
/*  f0dd528:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f0dd52c:	46006221 */ 	cvt.d.s	$f8,$f12
.L0f0dd530:
/*  f0dd530:	3c057f1b */ 	lui	$a1,%hi(var7f1ade80)
/*  f0dd534:	3c067f1b */ 	lui	$a2,%hi(var7f1ade8c)
/*  f0dd538:	3c077f1b */ 	lui	$a3,%hi(var7f1afb00)
/*  f0dd53c:	24e7de90 */ 	addiu	$a3,$a3,-8560
/*  f0dd540:	24c6de8c */ 	addiu	$a2,$a2,%lo(var7f1ade8c)
/*  f0dd544:	24a5de80 */ 	addiu	$a1,$a1,%lo(var7f1ade80)
/*  f0dd548:	f7a80010 */ 	sdc1	$f8,0x10($sp)
/*  f0dd54c:	0c004dad */ 	jal	sprintf
/*  f0dd550:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0dd554:	3c0f8008 */ 	lui	$t7,%hi(var8007fafc)
/*  f0dd558:	8deffafc */ 	lw	$t7,%lo(var8007fafc)($t7)
/*  f0dd55c:	3c078008 */ 	lui	$a3,%hi(var8007dea8)
/*  f0dd560:	8ce7fb00 */ 	lw	$a3,%lo(var7f1afb00)($a3)
/*  f0dd564:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0dd568:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0dd56c:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0dd570:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0dd574:	0fc55cbe */ 	jal	func0f1572f8
/*  f0dd578:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0dd57c:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*  f0dd580:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*  f0dd584:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0dd588:	8faa006c */ 	lw	$t2,0x6c($sp)
/*  f0dd58c:	03191821 */ 	addu	$v1,$t8,$t9
/*  f0dd590:	00681023 */ 	subu	$v0,$v1,$t0
/*  f0dd594:	2442fffb */ 	addiu	$v0,$v0,-5
/*  f0dd598:	27ac0064 */ 	addiu	$t4,$sp,0x64
/*  f0dd59c:	00484821 */ 	addu	$t1,$v0,$t0
/*  f0dd5a0:	020a5821 */ 	addu	$t3,$s0,$t2
/*  f0dd5a4:	afb00074 */ 	sw	$s0,0x74($sp)
/*  f0dd5a8:	afa90068 */ 	sw	$t1,0x68($sp)
/*  f0dd5ac:	afab0064 */ 	sw	$t3,0x64($sp)
/*  f0dd5b0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0dd5b4:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0dd5b8:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0dd5bc:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f0dd5c0:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0dd5c4:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0dd5c8:	0fc54e39 */ 	jal	func0f1538e4
/*  f0dd5cc:	27a70068 */ 	addiu	$a3,$sp,0x68
/*  f0dd5d0:	0c002f02 */ 	jal	func0000bc08
/*  f0dd5d4:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0dd5d8:	0c002f06 */ 	jal	func0000bc18
/*  f0dd5dc:	a7a2004c */ 	sh	$v0,0x4c($sp)
/*  f0dd5e0:	8fa300c4 */ 	lw	$v1,0xc4($sp)
/*  f0dd5e4:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0dd5e8:	3c0d8008 */ 	lui	$t5,%hi(var8007fb00)
/*  f0dd5ec:	00037880 */ 	sll	$t7,$v1,0x2
/*  f0dd5f0:	01e37821 */ 	addu	$t7,$t7,$v1
/*  f0dd5f4:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f0dd5f8:	01e1001b */ 	divu	$zero,$t7,$at
/*  f0dd5fc:	3c0e8008 */ 	lui	$t6,%hi(var8007fafc)
/*  f0dd600:	8dcefafc */ 	lw	$t6,%lo(var8007fafc)($t6)
/*  f0dd604:	8dadfb00 */ 	lw	$t5,%lo(var8007fb00)($t5)
/*  f0dd608:	87aa004c */ 	lh	$t2,0x4c($sp)
/*  f0dd60c:	0000c012 */ 	mflo	$t8
/*  f0dd610:	3c0100ff */ 	lui	$at,0xff
/*  f0dd614:	03011825 */ 	or	$v1,$t8,$at
/*  f0dd618:	240900a0 */ 	addiu	$t1,$zero,0xa0
/*  f0dd61c:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0dd620:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0dd624:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f0dd628:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f0dd62c:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0dd630:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0dd634:	27a70084 */ 	addiu	$a3,$sp,0x84
/*  f0dd638:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0dd63c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0dd640:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0dd644:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0dd648:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0dd64c:	0fc55b92 */ 	jal	func0f156e48
/*  f0dd650:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f0dd654:	3c057f1b */ 	lui	$a1,%hi(var7f1ade94)
/*  f0dd658:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0dd65c:	24a5de94 */ 	addiu	$a1,$a1,%lo(var7f1ade94)
/*  f0dd660:	0c004dad */ 	jal	sprintf
/*  f0dd664:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0dd668:	3c0b8008 */ 	lui	$t3,%hi(var8007fafc)
/*  f0dd66c:	8d6bfafc */ 	lw	$t3,%lo(var8007fafc)($t3)
/*  f0dd670:	3c078008 */ 	lui	$a3,%hi(var8007fb00)
/*  f0dd674:	8ce7fb00 */ 	lw	$a3,%lo(var8007fb00)($a3)
/*  f0dd678:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0dd67c:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0dd680:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0dd684:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0dd688:	0fc55cbe */ 	jal	func0f1572f8
/*  f0dd68c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0dd690:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0dd694:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f0dd698:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f0dd69c:	00086843 */ 	sra	$t5,$t0,0x1
/*  f0dd6a0:	018d1023 */ 	subu	$v0,$t4,$t5
/*  f0dd6a4:	27b90064 */ 	addiu	$t9,$sp,0x64
/*  f0dd6a8:	00487021 */ 	addu	$t6,$v0,$t0
/*  f0dd6ac:	020fc021 */ 	addu	$t8,$s0,$t7
/*  f0dd6b0:	afb00074 */ 	sw	$s0,0x74($sp)
/*  f0dd6b4:	afae0068 */ 	sw	$t6,0x68($sp)
/*  f0dd6b8:	afb80064 */ 	sw	$t8,0x64($sp)
/*  f0dd6bc:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0dd6c0:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0dd6c4:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f0dd6c8:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0dd6cc:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0dd6d0:	0fc54e39 */ 	jal	func0f1538e4
/*  f0dd6d4:	27a70068 */ 	addiu	$a3,$sp,0x68
/*  f0dd6d8:	0c002f02 */ 	jal	func0000bc08
/*  f0dd6dc:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0dd6e0:	0c002f06 */ 	jal	func0000bc18
/*  f0dd6e4:	a7a2004c */ 	sh	$v0,0x4c($sp)
/*  f0dd6e8:	3c098008 */ 	lui	$t1,%hi(var8007fb00)
/*  f0dd6ec:	3c0a8008 */ 	lui	$t2,%hi(var8007fafc)
/*  f0dd6f0:	8d4afafc */ 	lw	$t2,%lo(var8007fafc)($t2)
/*  f0dd6f4:	8d29fb00 */ 	lw	$t1,%lo(var8007fb00)($t1)
/*  f0dd6f8:	8fab0048 */ 	lw	$t3,0x48($sp)
/*  f0dd6fc:	87ad004c */ 	lh	$t5,0x4c($sp)
/*  f0dd700:	240c00a0 */ 	addiu	$t4,$zero,0xa0
/*  f0dd704:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0dd708:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f0dd70c:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0dd710:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0dd714:	27a70084 */ 	addiu	$a3,$sp,0x84
/*  f0dd718:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0dd71c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0dd720:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0dd724:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0dd728:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0dd72c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0dd730:	0fc55b92 */ 	jal	func0f156e48
/*  f0dd734:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f0dd738:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f0dd73c:	3c057f1b */ 	lui	$a1,%hi(var7f1ade98)
/*  f0dd740:	3c067f1b */ 	lui	$a2,%hi(var7f1adea4)
/*  f0dd744:	460054a1 */ 	cvt.d.s	$f18,$f10
/*  f0dd748:	3c077f1b */ 	lui	$a3,%hi(var7f1afb00)
/*  f0dd74c:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0dd750:	24e7dea8 */ 	addiu	$a3,$a3,%lo(var8007dea8)
/*  f0dd754:	f7b20010 */ 	sdc1	$f18,0x10($sp)
/*  f0dd758:	24c6dea4 */ 	addiu	$a2,$a2,%lo(var7f1adea4)
/*  f0dd75c:	24a5de98 */ 	addiu	$a1,$a1,%lo(var7f1ade98)
/*  f0dd760:	0c004dad */ 	jal	sprintf
/*  f0dd764:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0dd768:	3c0e8008 */ 	lui	$t6,%hi(var8007fafc)
/*  f0dd76c:	8dcefafc */ 	lw	$t6,%lo(var8007fafc)($t6)
/*  f0dd770:	3c078008 */ 	lui	$a3,0x8008
/*  f0dd774:	8ce7fb00 */ 	lw	$a3,%lo(var7f1afb00)($a3)
/*  f0dd778:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0dd77c:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0dd780:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0dd784:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0dd788:	0fc55cbe */ 	jal	func0f1572f8
/*  f0dd78c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0dd790:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f0dd794:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0dd798:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f0dd79c:	24420005 */ 	addiu	$v0,$v0,0x5
/*  f0dd7a0:	27a90064 */ 	addiu	$t1,$sp,0x64
/*  f0dd7a4:	00487821 */ 	addu	$t7,$v0,$t0
/*  f0dd7a8:	0218c821 */ 	addu	$t9,$s0,$t8
/*  f0dd7ac:	afb00074 */ 	sw	$s0,0x74($sp)
/*  f0dd7b0:	afaf0068 */ 	sw	$t7,0x68($sp)
/*  f0dd7b4:	afb90064 */ 	sw	$t9,0x64($sp)
/*  f0dd7b8:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0dd7bc:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0dd7c0:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f0dd7c4:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0dd7c8:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0dd7cc:	0fc54e39 */ 	jal	func0f1538e4
/*  f0dd7d0:	27a70068 */ 	addiu	$a3,$sp,0x68
/*  f0dd7d4:	0c002f02 */ 	jal	func0000bc08
/*  f0dd7d8:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0dd7dc:	0c002f06 */ 	jal	func0000bc18
/*  f0dd7e0:	a7a2004c */ 	sh	$v0,0x4c($sp)
/*  f0dd7e4:	3c0a8008 */ 	lui	$t2,%hi(var8007fb00)
/*  f0dd7e8:	3c0b8008 */ 	lui	$t3,%hi(var8007fafc)
/*  f0dd7ec:	8d6bfafc */ 	lw	$t3,%lo(var8007fafc)($t3)
/*  f0dd7f0:	8d4afb00 */ 	lw	$t2,%lo(var8007fb00)($t2)
/*  f0dd7f4:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f0dd7f8:	87ae004c */ 	lh	$t6,0x4c($sp)
/*  f0dd7fc:	240d00a0 */ 	addiu	$t5,$zero,0xa0
/*  f0dd800:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0dd804:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f0dd808:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0dd80c:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0dd810:	27a70084 */ 	addiu	$a3,$sp,0x84
/*  f0dd814:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0dd818:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0dd81c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0dd820:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0dd824:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0dd828:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0dd82c:	0fc55b92 */ 	jal	func0f156e48
/*  f0dd830:	afae0020 */ 	sw	$t6,0x20($sp)
.L0f0dd834:
/*  f0dd834:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0dd838:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0dd83c:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
/*  f0dd840:	03e00008 */ 	jr	$ra
/*  f0dd844:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0dd848
.late_rodata
glabel var7f1adeac
.word 0x40490fdb
.text
/*  f0dd848:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dd84c:	3c018007 */ 	lui	$at,0x8007
/*  f0dd850:	a02e0fb0 */ 	sb	$t6,0xfb0($at)
/*  f0dd854:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f0dd858:	3c0142b4 */ 	lui	$at,0x42b4
/*  f0dd85c:	44812000 */ 	mtc1	$at,$f4
/*  f0dd860:	c7a60084 */ 	lwc1	$f6,0x84($sp)
/*  f0dd864:	3c017f1b */ 	lui	$at,%hi(var7f1adeac)
/*  f0dd868:	c42adeac */ 	lwc1	$f10,%lo(var7f1adeac)($at)
/*  f0dd86c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0dd870:	3c014334 */ 	lui	$at,0x4334
/*  f0dd874:	44819000 */ 	mtc1	$at,$f18
/*  f0dd878:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0dd87c:	afb30048 */ 	sw	$s3,0x48($sp)
/*  f0dd880:	afb20044 */ 	sw	$s2,0x44($sp)
/*  f0dd884:	afb10040 */ 	sw	$s1,0x40($sp)
/*  f0dd888:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0dd88c:	afb0003c */ 	sw	$s0,0x3c($sp)
/*  f0dd890:	00808025 */ 	or	$s0,$a0,$zero
/*  f0dd894:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0dd898:	00e09025 */ 	or	$s2,$a3,$zero
/*  f0dd89c:	00c09825 */ 	or	$s3,$a2,$zero
/*  f0dd8a0:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*  f0dd8a4:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f0dd8a8:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f0dd8ac:	0c0068f7 */ 	jal	sinf
/*  f0dd8b0:	46128303 */ 	div.s	$f12,$f16,$f18
/*  f0dd8b4:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f0dd8b8:	02517823 */ 	subu	$t7,$s2,$s1
/*  f0dd8bc:	448f2000 */ 	mtc1	$t7,$f4
/*  f0dd8c0:	0313c823 */ 	subu	$t9,$t8,$s3
/*  f0dd8c4:	44994000 */ 	mtc1	$t9,$f8
/*  f0dd8c8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0dd8cc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0dd8d0:	4481c000 */ 	mtc1	$at,$f24
/*  f0dd8d4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0dd8d8:	46183582 */ 	mul.s	$f22,$f6,$f24
/*  f0dd8dc:	4618003c */ 	c.lt.s	$f0,$f24
/*  f0dd8e0:	46185502 */ 	mul.s	$f20,$f10,$f24
/*  f0dd8e4:	45020007 */ 	bc1fl	.L0f0dd904
/*  f0dd8e8:	46180081 */ 	sub.s	$f2,$f0,$f24
/*  f0dd8ec:	46000400 */ 	add.s	$f16,$f0,$f0
/*  f0dd8f0:	4480a000 */ 	mtc1	$zero,$f20
/*  f0dd8f4:	4610b582 */ 	mul.s	$f22,$f22,$f16
/*  f0dd8f8:	10000005 */ 	beqz	$zero,.L0f0dd910
/*  f0dd8fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd900:	46180081 */ 	sub.s	$f2,$f0,$f24
.L0f0dd904:
/*  f0dd904:	46021480 */ 	add.s	$f18,$f2,$f2
/*  f0dd908:	4612a502 */ 	mul.s	$f20,$f20,$f18
/*  f0dd90c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0dd910:
/*  f0dd910:	0fc351e7 */ 	jal	func0f0d479c
/*  f0dd914:	02002025 */ 	or	$a0,$s0,$zero
/*  f0dd918:	8fb00088 */ 	lw	$s0,0x88($sp)
/*  f0dd91c:	26630001 */ 	addiu	$v1,$s3,0x1
/*  f0dd920:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0dd924:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f0dd928:	00402025 */ 	or	$a0,$v0,$zero
/*  f0dd92c:	02202825 */ 	or	$a1,$s1,$zero
/*  f0dd930:	02603025 */ 	or	$a2,$s3,$zero
/*  f0dd934:	02403825 */ 	or	$a3,$s2,$zero
/*  f0dd938:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0dd93c:	0fc38bd7 */ 	jal	func0f0e2f5c
/*  f0dd940:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0dd944:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0dd948:	00402025 */ 	or	$a0,$v0,$zero
/*  f0dd94c:	02202825 */ 	or	$a1,$s1,$zero
/*  f0dd950:	24c30001 */ 	addiu	$v1,$a2,0x1
/*  f0dd954:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0dd958:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f0dd95c:	02403825 */ 	or	$a3,$s2,$zero
/*  f0dd960:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0dd964:	0fc38bd7 */ 	jal	func0f0e2f5c
/*  f0dd968:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0dd96c:	8fa80080 */ 	lw	$t0,0x80($sp)
/*  f0dd970:	00402025 */ 	or	$a0,$v0,$zero
/*  f0dd974:	02202825 */ 	or	$a1,$s1,$zero
/*  f0dd978:	8fa60058 */ 	lw	$a2,0x58($sp)
/*  f0dd97c:	26270001 */ 	addiu	$a3,$s1,0x1
/*  f0dd980:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0dd984:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0dd988:	0fc38bd7 */ 	jal	func0f0e2f5c
/*  f0dd98c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0dd990:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f0dd994:	00402025 */ 	or	$a0,$v0,$zero
/*  f0dd998:	02402825 */ 	or	$a1,$s2,$zero
/*  f0dd99c:	02603025 */ 	or	$a2,$s3,$zero
/*  f0dd9a0:	26470001 */ 	addiu	$a3,$s2,0x1
/*  f0dd9a4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0dd9a8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0dd9ac:	0fc38bd7 */ 	jal	func0f0e2f5c
/*  f0dd9b0:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0dd9b4:	0fc35272 */ 	jal	func0f0d49c8
/*  f0dd9b8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0dd9bc:	c7ae008c */ 	lwc1	$f14,0x8c($sp)
/*  f0dd9c0:	44802000 */ 	mtc1	$zero,$f4
/*  f0dd9c4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0dd9c8:	02325021 */ 	addu	$t2,$s1,$s2
/*  f0dd9cc:	460e203c */ 	c.lt.s	$f4,$f14
/*  f0dd9d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd9d4:	45020047 */ 	bc1fl	.L0f0ddaf4
/*  f0dd9d8:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0dd9dc:	448a3000 */ 	mtc1	$t2,$f6
/*  f0dd9e0:	8fad0080 */ 	lw	$t5,0x80($sp)
/*  f0dd9e4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0dd9e8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0dd9ec:	026d7021 */ 	addu	$t6,$s3,$t5
/*  f0dd9f0:	448e2000 */ 	mtc1	$t6,$f4
/*  f0dd9f4:	44816000 */ 	mtc1	$at,$f12
/*  f0dd9f8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0dd9fc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0dda00:	46184002 */ 	mul.s	$f0,$f8,$f24
/*  f0dda04:	3c028008 */ 	lui	$v0,%hi(var8007fac0)
/*  f0dda08:	8c42fac0 */ 	lw	$v0,%lo(var8007fac0)($v0)
/*  f0dda0c:	3c014300 */ 	lui	$at,0x4300
/*  f0dda10:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0dda14:	46183082 */ 	mul.s	$f2,$f6,$f24
/*  f0dda18:	46160281 */ 	sub.s	$f10,$f0,$f22
/*  f0dda1c:	460c5400 */ 	add.s	$f16,$f10,$f12
/*  f0dda20:	46141201 */ 	sub.s	$f8,$f2,$f20
/*  f0dda24:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0dda28:	460c4280 */ 	add.s	$f10,$f8,$f12
/*  f0dda2c:	440c9000 */ 	mfc1	$t4,$f18
/*  f0dda30:	46160480 */ 	add.s	$f18,$f0,$f22
/*  f0dda34:	01820019 */ 	multu	$t4,$v0
/*  f0dda38:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0dda3c:	44815000 */ 	mtc1	$at,$f10
/*  f0dda40:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dda44:	46141180 */ 	add.s	$f6,$f2,$f20
/*  f0dda48:	44068000 */ 	mfc1	$a2,$f16
/*  f0dda4c:	460e5402 */ 	mul.s	$f16,$f10,$f14
/*  f0dda50:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0dda54:	00002812 */ 	mflo	$a1
/*  f0dda58:	44192000 */ 	mfc1	$t9,$f4
/*  f0dda5c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0dda60:	03220019 */ 	multu	$t9,$v0
/*  f0dda64:	444af800 */ 	cfc1	$t2,$31
/*  f0dda68:	44cbf800 */ 	ctc1	$t3,$31
/*  f0dda6c:	44094000 */ 	mfc1	$t1,$f8
/*  f0dda70:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f0dda74:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0dda78:	444bf800 */ 	cfc1	$t3,$31
/*  f0dda7c:	00003812 */ 	mflo	$a3
/*  f0dda80:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0dda84:	51600013 */ 	beqzl	$t3,.L0f0ddad4
/*  f0dda88:	440b9000 */ 	mfc1	$t3,$f18
/*  f0dda8c:	44819000 */ 	mtc1	$at,$f18
/*  f0dda90:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0dda94:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f0dda98:	44cbf800 */ 	ctc1	$t3,$31
/*  f0dda9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddaa0:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f0ddaa4:	444bf800 */ 	cfc1	$t3,$31
/*  f0ddaa8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddaac:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0ddab0:	15600005 */ 	bnez	$t3,.L0f0ddac8
/*  f0ddab4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddab8:	440b9000 */ 	mfc1	$t3,$f18
/*  f0ddabc:	3c018000 */ 	lui	$at,0x8000
/*  f0ddac0:	10000007 */ 	beqz	$zero,.L0f0ddae0
/*  f0ddac4:	01615825 */ 	or	$t3,$t3,$at
.L0f0ddac8:
/*  f0ddac8:	10000005 */ 	beqz	$zero,.L0f0ddae0
/*  f0ddacc:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0ddad0:	440b9000 */ 	mfc1	$t3,$f18
.L0f0ddad4:
/*  f0ddad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddad8:	0560fffb */ 	bltz	$t3,.L0f0ddac8
/*  f0ddadc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ddae0:
/*  f0ddae0:	44caf800 */ 	ctc1	$t2,$31
/*  f0ddae4:	0fc54e8d */ 	jal	func0f153a34
/*  f0ddae8:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0ddaec:	00408025 */ 	or	$s0,$v0,$zero
/*  f0ddaf0:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f0ddaf4:
/*  f0ddaf4:	02001025 */ 	or	$v0,$s0,$zero
/*  f0ddaf8:	8fb0003c */ 	lw	$s0,0x3c($sp)
/*  f0ddafc:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f0ddb00:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f0ddb04:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*  f0ddb08:	8fb10040 */ 	lw	$s1,0x40($sp)
/*  f0ddb0c:	8fb20044 */ 	lw	$s2,0x44($sp)
/*  f0ddb10:	8fb30048 */ 	lw	$s3,0x48($sp)
/*  f0ddb14:	03e00008 */ 	jr	$ra
/*  f0ddb18:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

GLOBAL_ASM(
glabel func0f0ddb1c
/*  f0ddb1c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0ddb20:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0ddb24:	8cce0284 */ 	lw	$t6,0x284($a2)
/*  f0ddb28:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0ddb2c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ddb30:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f0ddb34:	3c188008 */ 	lui	$t8,%hi(var8007fac0)
/*  f0ddb38:	8f18fac0 */ 	lw	$t8,%lo(var8007fac0)($t8)
/*  f0ddb3c:	85cf0630 */ 	lh	$t7,0x630($t6)
/*  f0ddb40:	00803825 */ 	or	$a3,$a0,$zero
/*  f0ddb44:	24190018 */ 	addiu	$t9,$zero,0x18
/*  f0ddb48:	01f8001a */ 	div	$zero,$t7,$t8
/*  f0ddb4c:	acf90000 */ 	sw	$t9,0x0($a3)
/*  f0ddb50:	17000002 */ 	bnez	$t8,.L0f0ddb5c
/*  f0ddb54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddb58:	0007000d */ 	break	0x7
.L0f0ddb5c:
/*  f0ddb5c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ddb60:	17010004 */ 	bne	$t8,$at,.L0f0ddb74
/*  f0ddb64:	3c018000 */ 	lui	$at,0x8000
/*  f0ddb68:	15e10002 */ 	bne	$t7,$at,.L0f0ddb74
/*  f0ddb6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddb70:	0006000d */ 	break	0x6
.L0f0ddb74:
/*  f0ddb74:	8ccb006c */ 	lw	$t3,0x6c($a2)
/*  f0ddb78:	00005012 */ 	mflo	$t2
/*  f0ddb7c:	00004025 */ 	or	$t0,$zero,$zero
/*  f0ddb80:	11600003 */ 	beqz	$t3,.L0f0ddb90
/*  f0ddb84:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0ddb88:	10000002 */ 	beqz	$zero,.L0f0ddb94
/*  f0ddb8c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ddb90:
/*  f0ddb90:	00002825 */ 	or	$a1,$zero,$zero
.L0f0ddb94:
/*  f0ddb94:	8ccc0068 */ 	lw	$t4,0x68($a2)
/*  f0ddb98:	00002025 */ 	or	$a0,$zero,$zero
/*  f0ddb9c:	11800003 */ 	beqz	$t4,.L0f0ddbac
/*  f0ddba0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddba4:	10000001 */ 	beqz	$zero,.L0f0ddbac
/*  f0ddba8:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ddbac:
/*  f0ddbac:	8ccd0064 */ 	lw	$t5,0x64($a2)
/*  f0ddbb0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ddbb4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ddbb8:	11a00003 */ 	beqz	$t5,.L0f0ddbc8
/*  f0ddbbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddbc0:	10000001 */ 	beqz	$zero,.L0f0ddbc8
/*  f0ddbc4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ddbc8:
/*  f0ddbc8:	8cce0070 */ 	lw	$t6,0x70($a2)
/*  f0ddbcc:	11c00003 */ 	beqz	$t6,.L0f0ddbdc
/*  f0ddbd0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddbd4:	10000001 */ 	beqz	$zero,.L0f0ddbdc
/*  f0ddbd8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0ddbdc:
/*  f0ddbdc:	00437821 */ 	addu	$t7,$v0,$v1
/*  f0ddbe0:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f0ddbe4:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f0ddbe8:	57210032 */ 	bnel	$t9,$at,.L0f0ddcb4
/*  f0ddbec:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f0ddbf0:	afa70020 */ 	sw	$a3,0x20($sp)
/*  f0ddbf4:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0ddbf8:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0ddbfc:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0ddc00:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0ddc04:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ddc08:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0ddc0c:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f0ddc10:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f0ddc14:	14410026 */ 	bne	$v0,$at,.L0f0ddcb0
/*  f0ddc18:	8faa001c */ 	lw	$t2,0x1c($sp)
/*  f0ddc1c:	8ce20000 */ 	lw	$v0,0x0($a3)
/*  f0ddc20:	24030003 */ 	addiu	$v1,$zero,0x3
/*  f0ddc24:	8ccc028c */ 	lw	$t4,0x28c($a2)
/*  f0ddc28:	00025840 */ 	sll	$t3,$v0,0x1
/*  f0ddc2c:	0163001a */ 	div	$zero,$t3,$v1
/*  f0ddc30:	00004012 */ 	mflo	$t0
/*  f0ddc34:	00084023 */ 	negu	$t0,$t0
/*  f0ddc38:	14600002 */ 	bnez	$v1,.L0f0ddc44
/*  f0ddc3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddc40:	0007000d */ 	break	0x7
.L0f0ddc44:
/*  f0ddc44:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ddc48:	14610004 */ 	bne	$v1,$at,.L0f0ddc5c
/*  f0ddc4c:	3c018000 */ 	lui	$at,0x8000
/*  f0ddc50:	15610002 */ 	bne	$t3,$at,.L0f0ddc5c
/*  f0ddc54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddc58:	0006000d */ 	break	0x6
.L0f0ddc5c:
/*  f0ddc5c:	55800010 */ 	bnezl	$t4,.L0f0ddca0
/*  f0ddc60:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0ddc64:	0043001a */ 	div	$zero,$v0,$v1
/*  f0ddc68:	00006812 */ 	mflo	$t5
/*  f0ddc6c:	aced0000 */ 	sw	$t5,0x0($a3)
/*  f0ddc70:	14600002 */ 	bnez	$v1,.L0f0ddc7c
/*  f0ddc74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddc78:	0007000d */ 	break	0x7
.L0f0ddc7c:
/*  f0ddc7c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0ddc80:	14610004 */ 	bne	$v1,$at,.L0f0ddc94
/*  f0ddc84:	3c018000 */ 	lui	$at,0x8000
/*  f0ddc88:	14410002 */ 	bne	$v0,$at,.L0f0ddc94
/*  f0ddc8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddc90:	0006000d */ 	break	0x6
.L0f0ddc94:
/*  f0ddc94:	10000007 */ 	beqz	$zero,.L0f0ddcb4
/*  f0ddc98:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f0ddc9c:	24010006 */ 	addiu	$at,$zero,0x6
.L0f0ddca0:
/*  f0ddca0:	0041001a */ 	div	$zero,$v0,$at
/*  f0ddca4:	00007012 */ 	mflo	$t6
/*  f0ddca8:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f0ddcac:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ddcb0:
/*  f0ddcb0:	8cf80000 */ 	lw	$t8,0x0($a3)
.L0f0ddcb4:
/*  f0ddcb4:	8fab0024 */ 	lw	$t3,0x24($sp)
/*  f0ddcb8:	8ccc006c */ 	lw	$t4,0x6c($a2)
/*  f0ddcbc:	010a7821 */ 	addu	$t7,$t0,$t2
/*  f0ddcc0:	01f8c823 */ 	subu	$t9,$t7,$t8
/*  f0ddcc4:	032b4023 */ 	subu	$t0,$t9,$t3
/*  f0ddcc8:	2508fff5 */ 	addiu	$t0,$t0,-11
/*  f0ddccc:	8cc20068 */ 	lw	$v0,0x68($a2)
/*  f0ddcd0:	8cc30064 */ 	lw	$v1,0x64($a2)
/*  f0ddcd4:	11800003 */ 	beqz	$t4,.L0f0ddce4
/*  f0ddcd8:	8cc90070 */ 	lw	$t1,0x70($a2)
/*  f0ddcdc:	10000002 */ 	beqz	$zero,.L0f0ddce8
/*  f0ddce0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0ddce4:
/*  f0ddce4:	00002825 */ 	or	$a1,$zero,$zero
.L0f0ddce8:
/*  f0ddce8:	10400003 */ 	beqz	$v0,.L0f0ddcf8
/*  f0ddcec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0ddcf0:	10000002 */ 	beqz	$zero,.L0f0ddcfc
/*  f0ddcf4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0ddcf8:
/*  f0ddcf8:	00002025 */ 	or	$a0,$zero,$zero
.L0f0ddcfc:
/*  f0ddcfc:	10600003 */ 	beqz	$v1,.L0f0ddd0c
/*  f0ddd00:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ddd04:	10000002 */ 	beqz	$zero,.L0f0ddd10
/*  f0ddd08:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0ddd0c:
/*  f0ddd0c:	00001825 */ 	or	$v1,$zero,$zero
.L0f0ddd10:
/*  f0ddd10:	11200003 */ 	beqz	$t1,.L0f0ddd20
/*  f0ddd14:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f0ddd18:	10000002 */ 	beqz	$zero,.L0f0ddd24
/*  f0ddd1c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0ddd20:
/*  f0ddd20:	00001025 */ 	or	$v0,$zero,$zero
.L0f0ddd24:
/*  f0ddd24:	00436821 */ 	addu	$t5,$v0,$v1
/*  f0ddd28:	01a47021 */ 	addu	$t6,$t5,$a0
/*  f0ddd2c:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f0ddd30:	15e10002 */ 	bne	$t7,$at,.L0f0ddd3c
/*  f0ddd34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddd38:	2508fff0 */ 	addiu	$t0,$t0,-16
.L0f0ddd3c:
/*  f0ddd3c:	03e00008 */ 	jr	$ra
/*  f0ddd40:	01001025 */ 	or	$v0,$t0,$zero
);

GLOBAL_ASM(
glabel func0f0ddd44
/*  f0ddd44:	3c038007 */ 	lui	$v1,%hi(g_NumHudMessages)
/*  f0ddd48:	8c630fe8 */ 	lw	$v1,%lo(g_NumHudMessages)($v1)
/*  f0ddd4c:	00802825 */ 	or	$a1,$a0,$zero
/*  f0ddd50:	3c048007 */ 	lui	$a0,%hi(var800701dc)
/*  f0ddd54:	18600010 */ 	blez	$v1,.L0f0ddd98
/*  f0ddd58:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ddd5c:	8c840fec */ 	lw	$a0,0xfec($a0)
.L0f0ddd60:
/*  f0ddd60:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f0ddd64:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0ddd68:	0043082a */ 	slt	$at,$v0,$v1
/*  f0ddd6c:	11c00008 */ 	beqz	$t6,.L0f0ddd90
/*  f0ddd70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddd74:	8c8f01b0 */ 	lw	$t7,0x1b0($a0)
/*  f0ddd78:	14af0005 */ 	bne	$a1,$t7,.L0f0ddd90
/*  f0ddd7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddd80:	8c9801c4 */ 	lw	$t8,0x1c4($a0)
/*  f0ddd84:	37190002 */ 	ori	$t9,$t8,0x2
/*  f0ddd88:	03e00008 */ 	jr	$ra
/*  f0ddd8c:	ac9901c4 */ 	sw	$t9,0x1c4($a0)
.L0f0ddd90:
/*  f0ddd90:	1420fff3 */ 	bnez	$at,.L0f0ddd60
/*  f0ddd94:	248401dc */ 	addiu	$a0,$a0,%lo(var800701dc)
.L0f0ddd98:
/*  f0ddd98:	03e00008 */ 	jr	$ra
/*  f0ddd9c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0ddda0
/*  f0ddda0:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x314)
/*  f0ddda4:	8dcea2d4 */ 	lw	$t6,%lo(g_Vars+0x314)($t6)
/*  f0ddda8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0dddac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0dddb0:	11c00006 */ 	beqz	$t6,.L0f0dddcc
/*  f0dddb4:	3c068007 */ 	lui	$a2,%hi(g_NumHudMessages)
/*  f0dddb8:	3c068007 */ 	lui	$a2,%hi(g_NumHudMessages)
/*  f0dddbc:	24c60fe8 */ 	addiu	$a2,$a2,%lo(g_NumHudMessages)
/*  f0dddc0:	240f0014 */ 	addiu	$t7,$zero,0x14
/*  f0dddc4:	10000004 */ 	beqz	$zero,.L0f0dddd8
/*  f0dddc8:	accf0000 */ 	sw	$t7,0x0($a2)
.L0f0dddcc:
/*  f0dddcc:	24c60fe8 */ 	addiu	$a2,$a2,%lo(g_NumHudMessages)
/*  f0dddd0:	24180008 */ 	addiu	$t8,$zero,0x8
/*  f0dddd4:	acd80000 */ 	sw	$t8,0x0($a2)
.L0f0dddd8:
/*  f0dddd8:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f0ddddc:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0ddde0:	0004c900 */ 	sll	$t9,$a0,0x4
/*  f0ddde4:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f0ddde8:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0dddec:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f0dddf0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0dddf4:	2724003f */ 	addiu	$a0,$t9,0x3f
/*  f0dddf8:	3488003f */ 	ori	$t0,$a0,0x3f
/*  f0dddfc:	0c0048f2 */ 	jal	malloc
/*  f0dde00:	3904003f */ 	xori	$a0,$t0,0x3f
/*  f0dde04:	3c068007 */ 	lui	$a2,%hi(g_NumHudMessages)
/*  f0dde08:	24c60fe8 */ 	addiu	$a2,$a2,%lo(g_NumHudMessages)
/*  f0dde0c:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f0dde10:	3c048007 */ 	lui	$a0,%hi(g_HudMessages)
/*  f0dde14:	24840fec */ 	addiu	$a0,$a0,%lo(g_HudMessages)
/*  f0dde18:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f0dde1c:	1940000b */ 	blez	$t2,.L0f0dde4c
/*  f0dde20:	00001825 */ 	or	$v1,$zero,$zero
/*  f0dde24:	00001025 */ 	or	$v0,$zero,$zero
/*  f0dde28:	8c8b0000 */ 	lw	$t3,0x0($a0)
.L0f0dde2c:
/*  f0dde2c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0dde30:	01626021 */ 	addu	$t4,$t3,$v0
/*  f0dde34:	a1800000 */ 	sb	$zero,0x0($t4)
/*  f0dde38:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f0dde3c:	244201dc */ 	addiu	$v0,$v0,0x1dc
/*  f0dde40:	006d082a */ 	slt	$at,$v1,$t5
/*  f0dde44:	5420fff9 */ 	bnezl	$at,.L0f0dde2c
/*  f0dde48:	8c8b0000 */ 	lw	$t3,0x0($a0)
.L0f0dde4c:
/*  f0dde4c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0dde50:	3c01800a */ 	lui	$at,%hi(var8009dea0)
/*  f0dde54:	ac20dea0 */ 	sw	$zero,%lo(var8009dea0)($at)
/*  f0dde58:	03e00008 */ 	jr	$ra
/*  f0dde5c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);

void hudmsgRemoveAll(void)
{
	s32 i;

	for (i = 0; i < g_NumHudMessages; i++) {
		g_HudMessages[i].unk000 = 0;
	}
}

GLOBAL_ASM(
glabel func0f0ddeac
/*  f0ddeac:	3c068007 */ 	lui	$a2,%hi(g_NumHudMessages)
/*  f0ddeb0:	8cc60fe8 */ 	lw	$a2,%lo(g_NumHudMessages)($a2)
/*  f0ddeb4:	00803825 */ 	or	$a3,$a0,$zero
/*  f0ddeb8:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0ddebc:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f0ddec0:	18c00014 */ 	blez	$a2,.L0f0ddf14
/*  f0ddec4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0ddec8:	3c048007 */ 	lui	$a0,%hi(var800701dc)
/*  f0ddecc:	8c840fec */ 	lw	$a0,0xfec($a0)
.L0f0dded0:
/*  f0dded0:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f0dded4:	51c0000c */ 	beqzl	$t6,.L0f0ddf08
/*  f0dded8:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0ddedc:	8c8801b8 */ 	lw	$t0,0x1b8($a0)
/*  f0ddee0:	00e8082a */ 	slt	$at,$a3,$t0
/*  f0ddee4:	50200008 */ 	beqzl	$at,.L0f0ddf08
/*  f0ddee8:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0ddeec:	04400003 */ 	bltz	$v0,.L0f0ddefc
/*  f0ddef0:	0102082a */ 	slt	$at,$t0,$v0
/*  f0ddef4:	50200004 */ 	beqzl	$at,.L0f0ddf08
/*  f0ddef8:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f0ddefc:
/*  f0ddefc:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0ddf00:	01001025 */ 	or	$v0,$t0,$zero
/*  f0ddf04:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f0ddf08:
/*  f0ddf08:	00a6082a */ 	slt	$at,$a1,$a2
/*  f0ddf0c:	1420fff0 */ 	bnez	$at,.L0f0dded0
/*  f0ddf10:	248401dc */ 	addiu	$a0,$a0,%lo(var800701dc)
.L0f0ddf14:
/*  f0ddf14:	03e00008 */ 	jr	$ra
/*  f0ddf18:	00601025 */ 	or	$v0,$v1,$zero
);

void currentPlayerQueueMessage(char *text, s32 confignum)
{
	func0f0deebc(text, confignum,
			g_HudMessageConfigs[confignum].unk00,
			g_HudMessageConfigs[confignum].unk01,
			g_HudMessageConfigs[confignum].unk02,
			g_HudMessageConfigs[confignum].unk04,
			g_HudMessageConfigs[confignum].unk08,
			g_HudMessageConfigs[confignum].colour,
			g_HudMessageConfigs[confignum].unk10,
			g_HudMessageConfigs[confignum].alignh,
			g_HudMessageConfigs[confignum].unk16,
			g_HudMessageConfigs[confignum].alignv,
			g_HudMessageConfigs[confignum].unk18,
			-1, 0);
}

void func0f0ddfa4(char *text, s32 confignum, s32 arg2)
{
	func0f0deebc(text, confignum,
			g_HudMessageConfigs[confignum].unk00,
			g_HudMessageConfigs[confignum].unk01,
			g_HudMessageConfigs[confignum].unk02,
			g_HudMessageConfigs[confignum].unk04,
			g_HudMessageConfigs[confignum].unk08,
			g_HudMessageConfigs[confignum].colour,
			g_HudMessageConfigs[confignum].unk10,
			g_HudMessageConfigs[confignum].alignh,
			g_HudMessageConfigs[confignum].unk16,
			g_HudMessageConfigs[confignum].alignv,
			g_HudMessageConfigs[confignum].unk18,
			-1, arg2);
}

void func0f0de034(char *text, s32 confignum, u8 colournum)
{
	g_HudMessageConfigs[confignum].colour = g_Colours[colournum];

	func0f0deebc(text, confignum,
			g_HudMessageConfigs[confignum].unk00,
			g_HudMessageConfigs[confignum].unk01,
			g_HudMessageConfigs[confignum].unk02,
			g_HudMessageConfigs[confignum].unk04,
			g_HudMessageConfigs[confignum].unk08,
			g_HudMessageConfigs[confignum].colour,
			g_HudMessageConfigs[confignum].unk10,
			g_HudMessageConfigs[confignum].alignh,
			g_HudMessageConfigs[confignum].unk16,
			g_HudMessageConfigs[confignum].alignv,
			g_HudMessageConfigs[confignum].unk18,
			-1, 0);
}

void func0f0de0d4(char *text, s32 confignum, struct hudmessageconfig *config, s32 arg3)
{
	func0f0deebc(text, confignum,
			config->unk00,
			config->unk01,
			config->unk02,
			config->unk04,
			config->unk08,
			config->colour,
			config->unk10,
			config->alignh,
			config->unk16,
			config->alignv,
			config->unk18,
			arg3, 4);
}

GLOBAL_ASM(
glabel func0f0de160
/*  f0de160:	27bdfb40 */ 	addiu	$sp,$sp,-1216
/*  f0de164:	afb1004c */ 	sw	$s1,0x4c($sp)
/*  f0de168:	00808825 */ 	or	$s1,$a0,$zero
/*  f0de16c:	afbf006c */ 	sw	$ra,0x6c($sp)
/*  f0de170:	afb5005c */ 	sw	$s5,0x5c($sp)
/*  f0de174:	afb40058 */ 	sw	$s4,0x58($sp)
/*  f0de178:	00e0a025 */ 	or	$s4,$a3,$zero
/*  f0de17c:	30d500ff */ 	andi	$s5,$a2,0xff
/*  f0de180:	afbe0068 */ 	sw	$s8,0x68($sp)
/*  f0de184:	afb70064 */ 	sw	$s7,0x64($sp)
/*  f0de188:	afb60060 */ 	sw	$s6,0x60($sp)
/*  f0de18c:	afb30054 */ 	sw	$s3,0x54($sp)
/*  f0de190:	afb20050 */ 	sw	$s2,0x50($sp)
/*  f0de194:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f0de198:	afa504c4 */ 	sw	$a1,0x4c4($sp)
/*  f0de19c:	afa604c8 */ 	sw	$a2,0x4c8($sp)
/*  f0de1a0:	0fc2549e */ 	jal	func0f095278
/*  f0de1a4:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0de1a8:	8fae04c4 */ 	lw	$t6,0x4c4($sp)
/*  f0de1ac:	24130006 */ 	addiu	$s3,$zero,0x6
/*  f0de1b0:	00409025 */ 	or	$s2,$v0,$zero
/*  f0de1b4:	15d3000e */ 	bne	$t6,$s3,.L0f0de1f0
/*  f0de1b8:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x2ac)
/*  f0de1bc:	8defa26c */ 	lw	$t7,%lo(g_Vars+0x2ac)($t7)
/*  f0de1c0:	166f0007 */ 	bne	$s3,$t7,.L0f0de1e0
/*  f0de1c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de1c8:	0fc54a46 */ 	jal	optionsGetCutsceneSubtitles
/*  f0de1cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de1d0:	10400162 */ 	beqz	$v0,.L0f0de75c
/*  f0de1d4:	2418000b */ 	addiu	$t8,$zero,0xb
/*  f0de1d8:	10000005 */ 	beqz	$zero,.L0f0de1f0
/*  f0de1dc:	afb804c4 */ 	sw	$t8,0x4c4($sp)
.L0f0de1e0:
/*  f0de1e0:	0fc54a43 */ 	jal	optionsGetInGameSubtitles
/*  f0de1e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de1e8:	5040015d */ 	beqzl	$v0,.L0f0de760
/*  f0de1ec:	8fbf006c */ 	lw	$ra,0x6c($sp)
.L0f0de1f0:
/*  f0de1f0:	8fb904c4 */ 	lw	$t9,0x4c4($sp)
/*  f0de1f4:	0015c080 */ 	sll	$t8,$s5,0x2
/*  f0de1f8:	3c0f8007 */ 	lui	$t7,%hi(g_HudMessageConfigs)
/*  f0de1fc:	00197140 */ 	sll	$t6,$t9,0x5
/*  f0de200:	3c198007 */ 	lui	$t9,%hi(g_Colours)
/*  f0de204:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0de208:	8f390fb4 */ 	lw	$t9,%lo(g_Colours)($t9)
/*  f0de20c:	25ef0ff0 */ 	addiu	$t7,$t7,%lo(g_HudMessageConfigs)
/*  f0de210:	01cf8021 */ 	addu	$s0,$t6,$t7
/*  f0de214:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x2ac)
/*  f0de218:	ae19000c */ 	sw	$t9,0xc($s0)
/*  f0de21c:	8dcea26c */ 	lw	$t6,%lo(g_Vars+0x2ac)($t6)
/*  f0de220:	566e0136 */ 	bnel	$s3,$t6,.L0f0de6fc
/*  f0de224:	920f0002 */ 	lbu	$t7,0x2($s0)
/*  f0de228:	06400133 */ 	bltz	$s2,.L0f0de6f8
/*  f0de22c:	3c188007 */ 	lui	$t8,%hi(var80071170)
/*  f0de230:	27181170 */ 	addiu	$t8,$t8,%lo(var80071170)
/*  f0de234:	8f010000 */ 	lw	$at,0x0($t8)
/*  f0de238:	27af04b0 */ 	addiu	$t7,$sp,0x4b0
/*  f0de23c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0de240:	ade10000 */ 	sw	$at,0x0($t7)
/*  f0de244:	93010004 */ 	lbu	$at,0x4($t8)
/*  f0de248:	0c012983 */ 	jal	func0004a60c
/*  f0de24c:	a1e10004 */ 	sb	$at,0x4($t7)
/*  f0de250:	27a404a8 */ 	addiu	$a0,$sp,0x4a8
/*  f0de254:	86050016 */ 	lh	$a1,0x16($s0)
/*  f0de258:	0fc376c7 */ 	jal	func0f0ddb1c
/*  f0de25c:	a7a204ae */ 	sh	$v0,0x4ae($sp)
/*  f0de260:	97ad04ae */ 	lhu	$t5,0x4ae($sp)
/*  f0de264:	44922000 */ 	mtc1	$s2,$f4
/*  f0de268:	afa204a4 */ 	sw	$v0,0x4a4($sp)
/*  f0de26c:	448d4000 */ 	mtc1	$t5,$f8
/*  f0de270:	0000b825 */ 	or	$s7,$zero,$zero
/*  f0de274:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0de278:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0de27c:	05a10005 */ 	bgez	$t5,.L0f0de294
/*  f0de280:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0de284:	3c014f80 */ 	lui	$at,0x4f80
/*  f0de288:	44818000 */ 	mtc1	$at,$f16
/*  f0de28c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de290:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f0de294:
/*  f0de294:	460a3483 */ 	div.s	$f18,$f6,$f10
/*  f0de298:	02209025 */ 	or	$s2,$s1,$zero
/*  f0de29c:	27b600b4 */ 	addiu	$s6,$sp,0xb4
/*  f0de2a0:	24140020 */ 	addiu	$s4,$zero,0x20
/*  f0de2a4:	27b304b5 */ 	addiu	$s3,$sp,0x4b5
/*  f0de2a8:	241f0044 */ 	addiu	$ra,$zero,0x44
/*  f0de2ac:	240c0020 */ 	addiu	$t4,$zero,0x20
/*  f0de2b0:	240b000a */ 	addiu	$t3,$zero,0xa
/*  f0de2b4:	240a0052 */ 	addiu	$t2,$zero,0x52
/*  f0de2b8:	24090072 */ 	addiu	$t1,$zero,0x72
/*  f0de2bc:	e7b200a0 */ 	swc1	$f18,0xa0($sp)
/*  f0de2c0:	92390000 */ 	lbu	$t9,0x0($s1)
/*  f0de2c4:	132000f8 */ 	beqz	$t9,.L0f0de6a8
/*  f0de2c8:	332400ff */ 	andi	$a0,$t9,0xff
/*  f0de2cc:	afb00088 */ 	sw	$s0,0x88($sp)
/*  f0de2d0:	241e002e */ 	addiu	$s8,$zero,0x2e
/*  f0de2d4:	27af02ac */ 	addiu	$t7,$sp,0x2ac
.L0f0de2d8:
/*  f0de2d8:	02efc021 */ 	addu	$t8,$s7,$t7
/*  f0de2dc:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0de2e0:	00008025 */ 	or	$s0,$zero,$zero
/*  f0de2e4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0de2e8:	00003025 */ 	or	$a2,$zero,$zero
/*  f0de2ec:	afae0094 */ 	sw	$t6,0x94($sp)
/*  f0de2f0:	afb80074 */ 	sw	$t8,0x74($sp)
/*  f0de2f4:	10800063 */ 	beqz	$a0,.L0f0de484
/*  f0de2f8:	00004025 */ 	or	$t0,$zero,$zero
/*  f0de2fc:	10000006 */ 	beqz	$zero,.L0f0de318
/*  f0de300:	27a204b0 */ 	addiu	$v0,$sp,0x4b0
/*  f0de304:	10000003 */ 	beqz	$zero,.L0f0de314
/*  f0de308:	25b9fff6 */ 	addiu	$t9,$t5,-10
/*  f0de30c:	0335082a */ 	slt	$at,$t9,$s5
/*  f0de310:	1020005c */ 	beqz	$at,.L0f0de484
.L0f0de314:
/*  f0de314:	27a204b0 */ 	addiu	$v0,$sp,0x4b0
.L0f0de318:
/*  f0de318:	904f0000 */ 	lbu	$t7,0x0($v0)
.L0f0de31c:
/*  f0de31c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0de320:	15e40002 */ 	bne	$t7,$a0,.L0f0de32c
/*  f0de324:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de328:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0de32c:
/*  f0de32c:	5453fffb */ 	bnel	$v0,$s3,.L0f0de31c
/*  f0de330:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f0de334:	50a00021 */ 	beqzl	$a1,.L0f0de3bc
/*  f0de338:	2a0100f9 */ 	slti	$at,$s0,0xf9
/*  f0de33c:	17c4001e */ 	bne	$s8,$a0,.L0f0de3b8
/*  f0de340:	2aa10002 */ 	slti	$at,$s5,0x2
/*  f0de344:	92580001 */ 	lbu	$t8,0x1($s2)
/*  f0de348:	17d80002 */ 	bne	$s8,$t8,.L0f0de354
/*  f0de34c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de350:	00002825 */ 	or	$a1,$zero,$zero
.L0f0de354:
/*  f0de354:	54200019 */ 	bnezl	$at,.L0f0de3bc
/*  f0de358:	2a0100f9 */ 	slti	$at,$s0,0xf9
/*  f0de35c:	9243fffe */ 	lbu	$v1,-0x2($s2)
/*  f0de360:	24010064 */ 	addiu	$at,$zero,0x64
/*  f0de364:	53e30004 */ 	beql	$ra,$v1,.L0f0de378
/*  f0de368:	9242ffff */ 	lbu	$v0,-0x1($s2)
/*  f0de36c:	54610008 */ 	bnel	$v1,$at,.L0f0de390
/*  f0de370:	2401004d */ 	addiu	$at,$zero,0x4d
/*  f0de374:	9242ffff */ 	lbu	$v0,-0x1($s2)
.L0f0de378:
/*  f0de378:	51220004 */ 	beql	$t1,$v0,.L0f0de38c
/*  f0de37c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0de380:	55420003 */ 	bnel	$t2,$v0,.L0f0de390
/*  f0de384:	2401004d */ 	addiu	$at,$zero,0x4d
/*  f0de388:	00002825 */ 	or	$a1,$zero,$zero
.L0f0de38c:
/*  f0de38c:	2401004d */ 	addiu	$at,$zero,0x4d
.L0f0de390:
/*  f0de390:	10610003 */ 	beq	$v1,$at,.L0f0de3a0
/*  f0de394:	2401006d */ 	addiu	$at,$zero,0x6d
/*  f0de398:	54610008 */ 	bnel	$v1,$at,.L0f0de3bc
/*  f0de39c:	2a0100f9 */ 	slti	$at,$s0,0xf9
.L0f0de3a0:
/*  f0de3a0:	9242ffff */ 	lbu	$v0,-0x1($s2)
/*  f0de3a4:	51220004 */ 	beql	$t1,$v0,.L0f0de3b8
/*  f0de3a8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0de3ac:	55420003 */ 	bnel	$t2,$v0,.L0f0de3bc
/*  f0de3b0:	2a0100f9 */ 	slti	$at,$s0,0xf9
/*  f0de3b4:	00002825 */ 	or	$a1,$zero,$zero
.L0f0de3b8:
/*  f0de3b8:	2a0100f9 */ 	slti	$at,$s0,0xf9
.L0f0de3bc:
/*  f0de3bc:	50200025 */ 	beqzl	$at,.L0f0de454
/*  f0de3c0:	92440001 */ 	lbu	$a0,0x1($s2)
/*  f0de3c4:	16840009 */ 	bne	$s4,$a0,.L0f0de3ec
/*  f0de3c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0de3cc:	16000003 */ 	bnez	$s0,.L0f0de3dc
/*  f0de3d0:	02d07021 */ 	addu	$t6,$s6,$s0
/*  f0de3d4:	10000005 */ 	beqz	$zero,.L0f0de3ec
/*  f0de3d8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0de3dc:
/*  f0de3dc:	91d9ffff */ 	lbu	$t9,-0x1($t6)
/*  f0de3e0:	16990002 */ 	bne	$s4,$t9,.L0f0de3ec
/*  f0de3e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de3e8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0de3ec:
/*  f0de3ec:	1564000c */ 	bne	$t3,$a0,.L0f0de420
/*  f0de3f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de3f4:	1200000a */ 	beqz	$s0,.L0f0de420
/*  f0de3f8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0de3fc:	02d08821 */ 	addu	$s1,$s6,$s0
/*  f0de400:	922fffff */ 	lbu	$t7,-0x1($s1)
/*  f0de404:	128f0006 */ 	beq	$s4,$t7,.L0f0de420
/*  f0de408:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de40c:	92580001 */ 	lbu	$t8,0x1($s2)
/*  f0de410:	12980003 */ 	beq	$s4,$t8,.L0f0de420
/*  f0de414:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de418:	a22c0000 */ 	sb	$t4,0x0($s1)
/*  f0de41c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0de420:
/*  f0de420:	10a00005 */ 	beqz	$a1,.L0f0de438
/*  f0de424:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de428:	924e0000 */ 	lbu	$t6,0x0($s2)
/*  f0de42c:	168e0002 */ 	bne	$s4,$t6,.L0f0de438
/*  f0de430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de434:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0de438:
/*  f0de438:	54400006 */ 	bnezl	$v0,.L0f0de454
/*  f0de43c:	92440001 */ 	lbu	$a0,0x1($s2)
/*  f0de440:	92590000 */ 	lbu	$t9,0x0($s2)
/*  f0de444:	02d07821 */ 	addu	$t7,$s6,$s0
/*  f0de448:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0de44c:	a1f90000 */ 	sb	$t9,0x0($t7)
/*  f0de450:	92440001 */ 	lbu	$a0,0x1($s2)
.L0f0de454:
/*  f0de454:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f0de458:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0de45c:	5080000a */ 	beqzl	$a0,.L0f0de488
/*  f0de460:	00001825 */ 	or	$v1,$zero,$zero
/*  f0de464:	50a0ffac */ 	beqzl	$a1,.L0f0de318
/*  f0de468:	27a204b0 */ 	addiu	$v0,$sp,0x4b0
/*  f0de46c:	50c0ffaa */ 	beqzl	$a2,.L0f0de318
/*  f0de470:	27a204b0 */ 	addiu	$v0,$sp,0x4b0
/*  f0de474:	25b8fff6 */ 	addiu	$t8,$t5,-10
/*  f0de478:	0315082a */ 	slt	$at,$t8,$s5
/*  f0de47c:	5420ffa6 */ 	bnezl	$at,.L0f0de318
/*  f0de480:	27a204b0 */ 	addiu	$v0,$sp,0x4b0
.L0f0de484:
/*  f0de484:	00001825 */ 	or	$v1,$zero,$zero
.L0f0de488:
/*  f0de488:	1a000007 */ 	blez	$s0,.L0f0de4a8
/*  f0de48c:	02d08821 */ 	addu	$s1,$s6,$s0
/*  f0de490:	922effff */ 	lbu	$t6,-0x1($s1)
/*  f0de494:	128e0004 */ 	beq	$s4,$t6,.L0f0de4a8
/*  f0de498:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de49c:	a22c0000 */ 	sb	$t4,0x0($s1)
/*  f0de4a0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0de4a4:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f0de4a8:
/*  f0de4a8:	1ae0000a */ 	blez	$s7,.L0f0de4d4
/*  f0de4ac:	27a502ac */ 	addiu	$a1,$sp,0x2ac
/*  f0de4b0:	27a202ac */ 	addiu	$v0,$sp,0x2ac
/*  f0de4b4:	27a403a8 */ 	addiu	$a0,$sp,0x3a8
.L0f0de4b8:
/*  f0de4b8:	90990000 */ 	lbu	$t9,0x0($a0)
/*  f0de4bc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0de4c0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0de4c4:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f0de4c8:	1477fffb */ 	bne	$v1,$s7,.L0f0de4b8
/*  f0de4cc:	a059ffff */ 	sb	$t9,-0x1($v0)
/*  f0de4d0:	00001825 */ 	or	$v1,$zero,$zero
.L0f0de4d4:
/*  f0de4d4:	1a00000a */ 	blez	$s0,.L0f0de500
/*  f0de4d8:	2419000a */ 	addiu	$t9,$zero,0xa
/*  f0de4dc:	27af02ac */ 	addiu	$t7,$sp,0x2ac
/*  f0de4e0:	02ef2021 */ 	addu	$a0,$s7,$t7
/*  f0de4e4:	27a200b4 */ 	addiu	$v0,$sp,0xb4
.L0f0de4e8:
/*  f0de4e8:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f0de4ec:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0de4f0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f0de4f4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0de4f8:	1470fffb */ 	bne	$v1,$s0,.L0f0de4e8
/*  f0de4fc:	a098ffff */ 	sb	$t8,-0x1($a0)
.L0f0de500:
/*  f0de500:	8fae0074 */ 	lw	$t6,0x74($sp)
/*  f0de504:	3c0f8008 */ 	lui	$t7,%hi(var8007fb0c)
/*  f0de508:	3c078008 */ 	lui	$a3,%hi(var8007fb10)
/*  f0de50c:	01d01021 */ 	addu	$v0,$t6,$s0
/*  f0de510:	a0590000 */ 	sb	$t9,0x0($v0)
/*  f0de514:	a0400001 */ 	sb	$zero,0x1($v0)
/*  f0de518:	8deffb0c */ 	lw	$t7,%lo(var8007fb0c)($t7)
/*  f0de51c:	a7ad04ae */ 	sh	$t5,0x4ae($sp)
/*  f0de520:	afa800a4 */ 	sw	$t0,0xa4($sp)
/*  f0de524:	8ce7fb10 */ 	lw	$a3,%lo(var8007fb10)($a3)
/*  f0de528:	8fa404a4 */ 	lw	$a0,0x4a4($sp)
/*  f0de52c:	27a601b0 */ 	addiu	$a2,$sp,0x1b0
/*  f0de530:	0fc55d48 */ 	jal	func0f157520
/*  f0de534:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0de538:	93b801b0 */ 	lbu	$t8,0x1b0($sp)
/*  f0de53c:	8fa800a4 */ 	lw	$t0,0xa4($sp)
/*  f0de540:	24090072 */ 	addiu	$t1,$zero,0x72
/*  f0de544:	240a0052 */ 	addiu	$t2,$zero,0x52
/*  f0de548:	240b000a */ 	addiu	$t3,$zero,0xa
/*  f0de54c:	240c0020 */ 	addiu	$t4,$zero,0x20
/*  f0de550:	97ad04ae */ 	lhu	$t5,0x4ae($sp)
/*  f0de554:	1300000a */ 	beqz	$t8,.L0f0de580
/*  f0de558:	241f0044 */ 	addiu	$ra,$zero,0x44
/*  f0de55c:	27a201b0 */ 	addiu	$v0,$sp,0x1b0
/*  f0de560:	90430000 */ 	lbu	$v1,0x0($v0)
.L0f0de564:
/*  f0de564:	55630003 */ 	bnel	$t3,$v1,.L0f0de574
/*  f0de568:	90430001 */ 	lbu	$v1,0x1($v0)
/*  f0de56c:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f0de570:	90430001 */ 	lbu	$v1,0x1($v0)
.L0f0de574:
/*  f0de574:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0de578:	1460fffa */ 	bnez	$v1,.L0f0de564
/*  f0de57c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0de580:
/*  f0de580:	29010003 */ 	slti	$at,$t0,0x3
/*  f0de584:	54200035 */ 	bnezl	$at,.L0f0de65c
/*  f0de588:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f0de58c:	16e0001a */ 	bnez	$s7,.L0f0de5f8
/*  f0de590:	27a403a8 */ 	addiu	$a0,$sp,0x3a8
/*  f0de594:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0de598:	44902000 */ 	mtc1	$s0,$f4
/*  f0de59c:	2419000a */ 	addiu	$t9,$zero,0xa
/*  f0de5a0:	a2390000 */ 	sb	$t9,0x0($s1)
/*  f0de5a4:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0de5a8:	a2200001 */ 	sb	$zero,0x1($s1)
/*  f0de5ac:	c7b000a0 */ 	lwc1	$f16,0xa0($sp)
/*  f0de5b0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0de5b4:	a7ad04ae */ 	sh	$t5,0x4ae($sp)
/*  f0de5b8:	8fa60088 */ 	lw	$a2,0x88($sp)
/*  f0de5bc:	46104182 */ 	mul.s	$f6,$f8,$f16
/*  f0de5c0:	8fa504c4 */ 	lw	$a1,0x4c4($sp)
/*  f0de5c4:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0de5c8:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f0de5cc:	44075000 */ 	mfc1	$a3,$f10
/*  f0de5d0:	0fc37835 */ 	jal	func0f0de0d4
/*  f0de5d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de5d8:	24090072 */ 	addiu	$t1,$zero,0x72
/*  f0de5dc:	240a0052 */ 	addiu	$t2,$zero,0x52
/*  f0de5e0:	240b000a */ 	addiu	$t3,$zero,0xa
/*  f0de5e4:	240c0020 */ 	addiu	$t4,$zero,0x20
/*  f0de5e8:	97ad04ae */ 	lhu	$t5,0x4ae($sp)
/*  f0de5ec:	241f0044 */ 	addiu	$ra,$zero,0x44
/*  f0de5f0:	10000019 */ 	beqz	$zero,.L0f0de658
/*  f0de5f4:	afa00094 */ 	sw	$zero,0x94($sp)
.L0f0de5f8:
/*  f0de5f8:	00977021 */ 	addu	$t6,$a0,$s7
/*  f0de5fc:	26f70001 */ 	addiu	$s7,$s7,0x1
/*  f0de600:	44979000 */ 	mtc1	$s7,$f18
/*  f0de604:	2418000a */ 	addiu	$t8,$zero,0xa
/*  f0de608:	a1d80000 */ 	sb	$t8,0x0($t6)
/*  f0de60c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0de610:	0097c821 */ 	addu	$t9,$a0,$s7
/*  f0de614:	a3200000 */ 	sb	$zero,0x0($t9)
/*  f0de618:	c7a800a0 */ 	lwc1	$f8,0xa0($sp)
/*  f0de61c:	a7ad04ae */ 	sh	$t5,0x4ae($sp)
/*  f0de620:	8fa60088 */ 	lw	$a2,0x88($sp)
/*  f0de624:	46082402 */ 	mul.s	$f16,$f4,$f8
/*  f0de628:	8fa504c4 */ 	lw	$a1,0x4c4($sp)
/*  f0de62c:	4600818d */ 	trunc.w.s	$f6,$f16
/*  f0de630:	44073000 */ 	mfc1	$a3,$f6
/*  f0de634:	0fc37835 */ 	jal	func0f0de0d4
/*  f0de638:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de63c:	24090072 */ 	addiu	$t1,$zero,0x72
/*  f0de640:	240a0052 */ 	addiu	$t2,$zero,0x52
/*  f0de644:	240b000a */ 	addiu	$t3,$zero,0xa
/*  f0de648:	240c0020 */ 	addiu	$t4,$zero,0x20
/*  f0de64c:	97ad04ae */ 	lhu	$t5,0x4ae($sp)
/*  f0de650:	241f0044 */ 	addiu	$ra,$zero,0x44
/*  f0de654:	0000b825 */ 	or	$s7,$zero,$zero
.L0f0de658:
/*  f0de658:	8fb80094 */ 	lw	$t8,0x94($sp)
.L0f0de65c:
/*  f0de65c:	5300000e */ 	beqzl	$t8,.L0f0de698
/*  f0de660:	a2200000 */ 	sb	$zero,0x0($s1)
/*  f0de664:	1a00000a */ 	blez	$s0,.L0f0de690
/*  f0de668:	00001825 */ 	or	$v1,$zero,$zero
/*  f0de66c:	27ae03a8 */ 	addiu	$t6,$sp,0x3a8
/*  f0de670:	02ee2021 */ 	addu	$a0,$s7,$t6
/*  f0de674:	27a200b4 */ 	addiu	$v0,$sp,0xb4
.L0f0de678:
/*  f0de678:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f0de67c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0de680:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0de684:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f0de688:	1470fffb */ 	bne	$v1,$s0,.L0f0de678
/*  f0de68c:	a099ffff */ 	sb	$t9,-0x1($a0)
.L0f0de690:
/*  f0de690:	02f0b821 */ 	addu	$s7,$s7,$s0
/*  f0de694:	a2200000 */ 	sb	$zero,0x0($s1)
.L0f0de698:
/*  f0de698:	92440000 */ 	lbu	$a0,0x0($s2)
/*  f0de69c:	5480ff0e */ 	bnezl	$a0,.L0f0de2d8
/*  f0de6a0:	27af02ac */ 	addiu	$t7,$sp,0x2ac
/*  f0de6a4:	8fb00088 */ 	lw	$s0,0x88($sp)
.L0f0de6a8:
/*  f0de6a8:	12e0002c */ 	beqz	$s7,.L0f0de75c
/*  f0de6ac:	27a403a8 */ 	addiu	$a0,$sp,0x3a8
/*  f0de6b0:	0097c021 */ 	addu	$t8,$a0,$s7
/*  f0de6b4:	26f70001 */ 	addiu	$s7,$s7,0x1
/*  f0de6b8:	44975000 */ 	mtc1	$s7,$f10
/*  f0de6bc:	240f000a */ 	addiu	$t7,$zero,0xa
/*  f0de6c0:	a30f0000 */ 	sb	$t7,0x0($t8)
/*  f0de6c4:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f0de6c8:	00977021 */ 	addu	$t6,$a0,$s7
/*  f0de6cc:	a1c00000 */ 	sb	$zero,0x0($t6)
/*  f0de6d0:	c7a400a0 */ 	lwc1	$f4,0xa0($sp)
/*  f0de6d4:	8fa504c4 */ 	lw	$a1,0x4c4($sp)
/*  f0de6d8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0de6dc:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f0de6e0:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f0de6e4:	44078000 */ 	mfc1	$a3,$f16
/*  f0de6e8:	0fc37835 */ 	jal	func0f0de0d4
/*  f0de6ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de6f0:	1000001b */ 	beqz	$zero,.L0f0de760
/*  f0de6f4:	8fbf006c */ 	lw	$ra,0x6c($sp)
.L0f0de6f8:
/*  f0de6f8:	920f0002 */ 	lbu	$t7,0x2($s0)
.L0f0de6fc:
/*  f0de6fc:	92060000 */ 	lbu	$a2,0x0($s0)
/*  f0de700:	92070001 */ 	lbu	$a3,0x1($s0)
/*  f0de704:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0de708:	8e180004 */ 	lw	$t8,0x4($s0)
/*  f0de70c:	02202025 */ 	or	$a0,$s1,$zero
/*  f0de710:	8fa504c4 */ 	lw	$a1,0x4c4($sp)
/*  f0de714:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0de718:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*  f0de71c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0de720:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f0de724:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0de728:	8e0f0010 */ 	lw	$t7,0x10($s0)
/*  f0de72c:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0de730:	92180014 */ 	lbu	$t8,0x14($s0)
/*  f0de734:	afb80024 */ 	sw	$t8,0x24($sp)
/*  f0de738:	860e0016 */ 	lh	$t6,0x16($s0)
/*  f0de73c:	afae0028 */ 	sw	$t6,0x28($sp)
/*  f0de740:	92190015 */ 	lbu	$t9,0x15($s0)
/*  f0de744:	afb9002c */ 	sw	$t9,0x2c($sp)
/*  f0de748:	860f0018 */ 	lh	$t7,0x18($s0)
/*  f0de74c:	afa00038 */ 	sw	$zero,0x38($sp)
/*  f0de750:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f0de754:	0fc37baf */ 	jal	func0f0deebc
/*  f0de758:	afaf0030 */ 	sw	$t7,0x30($sp)
.L0f0de75c:
/*  f0de75c:	8fbf006c */ 	lw	$ra,0x6c($sp)
.L0f0de760:
/*  f0de760:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f0de764:	8fb1004c */ 	lw	$s1,0x4c($sp)
/*  f0de768:	8fb20050 */ 	lw	$s2,0x50($sp)
/*  f0de76c:	8fb30054 */ 	lw	$s3,0x54($sp)
/*  f0de770:	8fb40058 */ 	lw	$s4,0x58($sp)
/*  f0de774:	8fb5005c */ 	lw	$s5,0x5c($sp)
/*  f0de778:	8fb60060 */ 	lw	$s6,0x60($sp)
/*  f0de77c:	8fb70064 */ 	lw	$s7,0x64($sp)
/*  f0de780:	8fbe0068 */ 	lw	$s8,0x68($sp)
/*  f0de784:	03e00008 */ 	jr	$ra
/*  f0de788:	27bd04c0 */ 	addiu	$sp,$sp,0x4c0
/*  f0de78c:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0de790:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f0de794:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f0de798:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0de79c:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0de7a0:	8fa80068 */ 	lw	$t0,0x68($sp)
/*  f0de7a4:	8fa9006c */ 	lw	$t1,0x6c($sp)
/*  f0de7a8:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0de7ac:	8fab0074 */ 	lw	$t3,0x74($sp)
/*  f0de7b0:	8fac0078 */ 	lw	$t4,0x78($sp)
/*  f0de7b4:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f0de7b8:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0de7bc:	afa00038 */ 	sw	$zero,0x38($sp)
/*  f0de7c0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0de7c4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0de7c8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0de7cc:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0de7d0:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f0de7d4:	afa90024 */ 	sw	$t1,0x24($sp)
/*  f0de7d8:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f0de7dc:	afab002c */ 	sw	$t3,0x2c($sp)
/*  f0de7e0:	afac0030 */ 	sw	$t4,0x30($sp)
/*  f0de7e4:	0fc37baf */ 	jal	func0f0deebc
/*  f0de7e8:	afad0034 */ 	sw	$t5,0x34($sp)
/*  f0de7ec:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0de7f0:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f0de7f4:	03e00008 */ 	jr	$ra
/*  f0de7f8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0de7fc
.late_rodata
glabel var7f1adeb0
.word func0f0de7fc+0x490 # f0dec8c
glabel var7f1adeb4
.word func0f0de7fc+0x498 # f0dec94
glabel var7f1adeb8
.word func0f0de7fc+0x4ac # f0deca8
glabel var7f1adebc
.word func0f0de7fc+0x648 # f0dee44
glabel var7f1adec0
.word func0f0de7fc+0x678 # f0dee74
.text
/*  f0de7fc:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0de800:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0de804:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0de808:	8c8f01c0 */ 	lw	$t7,0x1c0($a0)
/*  f0de80c:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f0de810:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f0de814:	3c038008 */ 	lui	$v1,%hi(var8007fac0)
/*  f0de818:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0de81c:	8c63fac0 */ 	lw	$v1,%lo(var8007fac0)($v1)
/*  f0de820:	0138c821 */ 	addu	$t9,$t1,$t8
/*  f0de824:	8f220064 */ 	lw	$v0,0x64($t9)
/*  f0de828:	00807025 */ 	or	$t6,$a0,$zero
/*  f0de82c:	844f0634 */ 	lh	$t7,0x634($v0)
/*  f0de830:	84580636 */ 	lh	$t8,0x636($v0)
/*  f0de834:	01e3001a */ 	div	$zero,$t7,$v1
/*  f0de838:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f0de83c:	84590630 */ 	lh	$t9,0x630($v0)
/*  f0de840:	00006012 */ 	mflo	$t4
/*  f0de844:	14600002 */ 	bnez	$v1,.L0f0de850
/*  f0de848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de84c:	0007000d */ 	break	0x7
.L0f0de850:
/*  f0de850:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0de854:	14610004 */ 	bne	$v1,$at,.L0f0de868
/*  f0de858:	3c018000 */ 	lui	$at,0x8000
/*  f0de85c:	15e10002 */ 	bne	$t7,$at,.L0f0de868
/*  f0de860:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de864:	0006000d */ 	break	0x6
.L0f0de868:
/*  f0de868:	0323001a */ 	div	$zero,$t9,$v1
/*  f0de86c:	844f0632 */ 	lh	$t7,0x632($v0)
/*  f0de870:	14600002 */ 	bnez	$v1,.L0f0de87c
/*  f0de874:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de878:	0007000d */ 	break	0x7
.L0f0de87c:
/*  f0de87c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0de880:	14610004 */ 	bne	$v1,$at,.L0f0de894
/*  f0de884:	3c018000 */ 	lui	$at,0x8000
/*  f0de888:	17210002 */ 	bne	$t9,$at,.L0f0de894
/*  f0de88c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de890:	0006000d */ 	break	0x6
.L0f0de894:
/*  f0de894:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0de898:	91d801c8 */ 	lbu	$t8,0x1c8($t6)
/*  f0de89c:	00005812 */ 	mflo	$t3
/*  f0de8a0:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0de8a4:	57010004 */ 	bnel	$t8,$at,.L0f0de8b8
/*  f0de8a8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0de8ac:	10000002 */ 	beqz	$zero,.L0f0de8b8
/*  f0de8b0:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0de8b4:	00002025 */ 	or	$a0,$zero,$zero
.L0f0de8b8:
/*  f0de8b8:	8d28006c */ 	lw	$t0,0x6c($t1)
/*  f0de8bc:	00003025 */ 	or	$a2,$zero,$zero
/*  f0de8c0:	11000003 */ 	beqz	$t0,.L0f0de8d0
/*  f0de8c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de8c8:	10000001 */ 	beqz	$zero,.L0f0de8d0
/*  f0de8cc:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0de8d0:
/*  f0de8d0:	8d270068 */ 	lw	$a3,0x68($t1)
/*  f0de8d4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0de8d8:	10e00003 */ 	beqz	$a3,.L0f0de8e8
/*  f0de8dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de8e0:	10000001 */ 	beqz	$zero,.L0f0de8e8
/*  f0de8e4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0de8e8:
/*  f0de8e8:	8d2a0064 */ 	lw	$t2,0x64($t1)
/*  f0de8ec:	00001825 */ 	or	$v1,$zero,$zero
/*  f0de8f0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0de8f4:	11400003 */ 	beqz	$t2,.L0f0de904
/*  f0de8f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de8fc:	10000001 */ 	beqz	$zero,.L0f0de904
/*  f0de900:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0de904:
/*  f0de904:	8d2d0070 */ 	lw	$t5,0x70($t1)
/*  f0de908:	11a00003 */ 	beqz	$t5,.L0f0de918
/*  f0de90c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de910:	10000001 */ 	beqz	$zero,.L0f0de918
/*  f0de914:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0de918:
/*  f0de918:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f0de91c:	03257821 */ 	addu	$t7,$t9,$a1
/*  f0de920:	01e67021 */ 	addu	$t6,$t7,$a2
/*  f0de924:	29c10003 */ 	slti	$at,$t6,0x3
/*  f0de928:	14200009 */ 	bnez	$at,.L0f0de950
/*  f0de92c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0de930:	8d22028c */ 	lw	$v0,0x28c($t1)
/*  f0de934:	01645823 */ 	subu	$t3,$t3,$a0
/*  f0de938:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0de93c:	50400004 */ 	beqzl	$v0,.L0f0de950
/*  f0de940:	01846021 */ 	addu	$t4,$t4,$a0
/*  f0de944:	14410002 */ 	bne	$v0,$at,.L0f0de950
/*  f0de948:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0de94c:	01846021 */ 	addu	$t4,$t4,$a0
.L0f0de950:
/*  f0de950:	11000003 */ 	beqz	$t0,.L0f0de960
/*  f0de954:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0de958:	10000001 */ 	beqz	$zero,.L0f0de960
/*  f0de95c:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0de960:
/*  f0de960:	10e00003 */ 	beqz	$a3,.L0f0de970
/*  f0de964:	00002825 */ 	or	$a1,$zero,$zero
/*  f0de968:	10000001 */ 	beqz	$zero,.L0f0de970
/*  f0de96c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0de970:
/*  f0de970:	11400003 */ 	beqz	$t2,.L0f0de980
/*  f0de974:	00001825 */ 	or	$v1,$zero,$zero
/*  f0de978:	10000001 */ 	beqz	$zero,.L0f0de980
/*  f0de97c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0de980:
/*  f0de980:	11a00003 */ 	beqz	$t5,.L0f0de990
/*  f0de984:	00001025 */ 	or	$v0,$zero,$zero
/*  f0de988:	10000001 */ 	beqz	$zero,.L0f0de990
/*  f0de98c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0de990:
/*  f0de990:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f0de994:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f0de998:	03267821 */ 	addu	$t7,$t9,$a2
/*  f0de99c:	55e10014 */ 	bnel	$t7,$at,.L0f0de9f0
/*  f0de9a0:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f0de9a4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f0de9a8:	afab0024 */ 	sw	$t3,0x24($sp)
/*  f0de9ac:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0de9b0:	afac002c */ 	sw	$t4,0x2c($sp)
/*  f0de9b4:	241f0001 */ 	addiu	$ra,$zero,0x1
/*  f0de9b8:	8fa40018 */ 	lw	$a0,0x18($sp)
/*  f0de9bc:	8fab0024 */ 	lw	$t3,0x24($sp)
/*  f0de9c0:	13e20004 */ 	beq	$ra,$v0,.L0f0de9d4
/*  f0de9c4:	8fac002c */ 	lw	$t4,0x2c($sp)
/*  f0de9c8:	3c0e8009 */ 	lui	$t6,%hi(g_Is4Mb)
/*  f0de9cc:	91ce0af0 */ 	lbu	$t6,%lo(g_Is4Mb)($t6)
/*  f0de9d0:	17ee0006 */ 	bne	$ra,$t6,.L0f0de9ec
.L0f0de9d4:
/*  f0de9d4:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x28c)
/*  f0de9d8:	8f18a24c */ 	lw	$t8,%lo(g_Vars+0x28c)($t8)
/*  f0de9dc:	01645823 */ 	subu	$t3,$t3,$a0
/*  f0de9e0:	57000003 */ 	bnezl	$t8,.L0f0de9f0
/*  f0de9e4:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f0de9e8:	01846021 */ 	addu	$t4,$t4,$a0
.L0f0de9ec:
/*  f0de9ec:	8fa30038 */ 	lw	$v1,0x38($sp)
.L0f0de9f0:
/*  f0de9f0:	241f0001 */ 	addiu	$ra,$zero,0x1
/*  f0de9f4:	906201c8 */ 	lbu	$v0,0x1c8($v1)
/*  f0de9f8:	1040000a */ 	beqz	$v0,.L0f0dea24
/*  f0de9fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dea00:	105f000a */ 	beq	$v0,$ra,.L0f0dea2c
/*  f0dea04:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x6c)
/*  f0dea08:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0dea0c:	10410085 */ 	beq	$v0,$at,.L0f0dec24
/*  f0dea10:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0dea14:	5041008b */ 	beql	$v0,$at,.L0f0dec44
/*  f0dea18:	9479001c */ 	lhu	$t9,0x1c($v1)
/*  f0dea1c:	10000091 */ 	beqz	$zero,.L0f0dec64
/*  f0dea20:	8c6901d0 */ 	lw	$t1,0x1d0($v1)
.L0f0dea24:
/*  f0dea24:	1000008f */ 	beqz	$zero,.L0f0dec64
/*  f0dea28:	8c6901d0 */ 	lw	$t1,0x1d0($v1)
.L0f0dea2c:
/*  f0dea2c:	3c198007 */ 	lui	$t9,%hi(var80070764)
/*  f0dea30:	8f390764 */ 	lw	$t9,%lo(var80070764)($t9)
/*  f0dea34:	3c07800a */ 	lui	$a3,%hi(g_Vars+0x68)
/*  f0dea38:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x64)
/*  f0dea3c:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x70)
/*  f0dea40:	8dada030 */ 	lw	$t5,%lo(g_Vars+0x70)($t5)
/*  f0dea44:	8d4aa024 */ 	lw	$t2,%lo(g_Vars+0x64)($t2)
/*  f0dea48:	8ce7a028 */ 	lw	$a3,%lo(g_Vars+0x68)($a3)
/*  f0dea4c:	13200007 */ 	beqz	$t9,.L0f0dea6c
/*  f0dea50:	8d08a02c */ 	lw	$t0,%lo(g_Vars+0x6c)($t0)
/*  f0dea54:	3c0f8006 */ 	lui	$t7,%hi(var8005d9d0)
/*  f0dea58:	8defd9d0 */ 	lw	$t7,%lo(var8005d9d0)($t7)
/*  f0dea5c:	55e00004 */ 	bnezl	$t7,.L0f0dea70
/*  f0dea60:	8c6201cc */ 	lw	$v0,0x1cc($v1)
/*  f0dea64:	10000002 */ 	beqz	$zero,.L0f0dea70
/*  f0dea68:	24020018 */ 	addiu	$v0,$zero,0x18
.L0f0dea6c:
/*  f0dea6c:	8c6201cc */ 	lw	$v0,0x1cc($v1)
.L0f0dea70:
/*  f0dea70:	8c7801d0 */ 	lw	$t8,0x1d0($v1)
/*  f0dea74:	01827021 */ 	addu	$t6,$t4,$v0
/*  f0dea78:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0dea7c:	01d84821 */ 	addu	$t1,$t6,$t8
/*  f0dea80:	11000003 */ 	beqz	$t0,.L0f0dea90
/*  f0dea84:	25290003 */ 	addiu	$t1,$t1,0x3
/*  f0dea88:	10000002 */ 	beqz	$zero,.L0f0dea94
/*  f0dea8c:	03e03025 */ 	or	$a2,$ra,$zero
.L0f0dea90:
/*  f0dea90:	00003025 */ 	or	$a2,$zero,$zero
.L0f0dea94:
/*  f0dea94:	10e00003 */ 	beqz	$a3,.L0f0deaa4
/*  f0dea98:	00002825 */ 	or	$a1,$zero,$zero
/*  f0dea9c:	10000001 */ 	beqz	$zero,.L0f0deaa4
/*  f0deaa0:	03e02825 */ 	or	$a1,$ra,$zero
.L0f0deaa4:
/*  f0deaa4:	11400003 */ 	beqz	$t2,.L0f0deab4
/*  f0deaa8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0deaac:	10000001 */ 	beqz	$zero,.L0f0deab4
/*  f0deab0:	03e01825 */ 	or	$v1,$ra,$zero
.L0f0deab4:
/*  f0deab4:	11a00003 */ 	beqz	$t5,.L0f0deac4
/*  f0deab8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0deabc:	10000001 */ 	beqz	$zero,.L0f0deac4
/*  f0deac0:	03e01025 */ 	or	$v0,$ra,$zero
.L0f0deac4:
/*  f0deac4:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f0deac8:	03257821 */ 	addu	$t7,$t9,$a1
/*  f0deacc:	01e67021 */ 	addu	$t6,$t7,$a2
/*  f0dead0:	15c10029 */ 	bne	$t6,$at,.L0f0deb78
/*  f0dead4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dead8:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0deadc:	afa90034 */ 	sw	$t1,0x34($sp)
/*  f0deae0:	3c038009 */ 	lui	$v1,%hi(g_Is4Mb)
/*  f0deae4:	241f0001 */ 	addiu	$ra,$zero,0x1
/*  f0deae8:	24630af0 */ 	addiu	$v1,$v1,%lo(g_Is4Mb)
/*  f0deaec:	13e20003 */ 	beq	$ra,$v0,.L0f0deafc
/*  f0deaf0:	8fa90034 */ 	lw	$t1,0x34($sp)
/*  f0deaf4:	90780000 */ 	lbu	$t8,0x0($v1)
/*  f0deaf8:	17f8001f */ 	bne	$ra,$t8,.L0f0deb78
.L0f0deafc:
/*  f0deafc:	3c198007 */ 	lui	$t9,%hi(var80070764)
/*  f0deb00:	8f390764 */ 	lw	$t9,%lo(var80070764)($t9)
/*  f0deb04:	3c0f8006 */ 	lui	$t7,%hi(var8005d9d0)
/*  f0deb08:	53200005 */ 	beqzl	$t9,.L0f0deb20
/*  f0deb0c:	906e0000 */ 	lbu	$t6,0x0($v1)
/*  f0deb10:	8defd9d0 */ 	lw	$t7,%lo(var8005d9d0)($t7)
/*  f0deb14:	11e00018 */ 	beqz	$t7,.L0f0deb78
/*  f0deb18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0deb1c:	906e0000 */ 	lbu	$t6,0x0($v1)
.L0f0deb20:
/*  f0deb20:	8fb80038 */ 	lw	$t8,0x38($sp)
/*  f0deb24:	8fb90038 */ 	lw	$t9,0x38($sp)
/*  f0deb28:	57ee000b */ 	bnel	$ra,$t6,.L0f0deb58
/*  f0deb2c:	8f2201c0 */ 	lw	$v0,0x1c0($t9)
/*  f0deb30:	8f0201c0 */ 	lw	$v0,0x1c0($t8)
/*  f0deb34:	14400003 */ 	bnez	$v0,.L0f0deb44
/*  f0deb38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0deb3c:	10000037 */ 	beqz	$zero,.L0f0dec1c
/*  f0deb40:	2529ffff */ 	addiu	$t1,$t1,-1
.L0f0deb44:
/*  f0deb44:	17e20035 */ 	bne	$ra,$v0,.L0f0dec1c
/*  f0deb48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0deb4c:	10000033 */ 	beqz	$zero,.L0f0dec1c
/*  f0deb50:	2529fff0 */ 	addiu	$t1,$t1,-16
/*  f0deb54:	8f2201c0 */ 	lw	$v0,0x1c0($t9)
.L0f0deb58:
/*  f0deb58:	14400003 */ 	bnez	$v0,.L0f0deb68
/*  f0deb5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0deb60:	1000002e */ 	beqz	$zero,.L0f0dec1c
/*  f0deb64:	2529000f */ 	addiu	$t1,$t1,0xf
.L0f0deb68:
/*  f0deb68:	17e2002c */ 	bne	$ra,$v0,.L0f0dec1c
/*  f0deb6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0deb70:	1000002a */ 	beqz	$zero,.L0f0dec1c
/*  f0deb74:	25290004 */ 	addiu	$t1,$t1,0x4
.L0f0deb78:
/*  f0deb78:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x6c)
/*  f0deb7c:	8defa02c */ 	lw	$t7,%lo(g_Vars+0x6c)($t7)
/*  f0deb80:	3c07800a */ 	lui	$a3,%hi(g_Vars+0x68)
/*  f0deb84:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x64)
/*  f0deb88:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x70)
/*  f0deb8c:	8dada030 */ 	lw	$t5,%lo(g_Vars+0x70)($t5)
/*  f0deb90:	8d4aa024 */ 	lw	$t2,%lo(g_Vars+0x64)($t2)
/*  f0deb94:	11e00003 */ 	beqz	$t7,.L0f0deba4
/*  f0deb98:	8ce7a028 */ 	lw	$a3,%lo(g_Vars+0x68)($a3)
/*  f0deb9c:	10000002 */ 	beqz	$zero,.L0f0deba8
/*  f0deba0:	03e03025 */ 	or	$a2,$ra,$zero
.L0f0deba4:
/*  f0deba4:	00003025 */ 	or	$a2,$zero,$zero
.L0f0deba8:
/*  f0deba8:	50e00004 */ 	beqzl	$a3,.L0f0debbc
/*  f0debac:	00002825 */ 	or	$a1,$zero,$zero
/*  f0debb0:	10000002 */ 	beqz	$zero,.L0f0debbc
/*  f0debb4:	03e02825 */ 	or	$a1,$ra,$zero
/*  f0debb8:	00002825 */ 	or	$a1,$zero,$zero
.L0f0debbc:
/*  f0debbc:	51400004 */ 	beqzl	$t2,.L0f0debd0
/*  f0debc0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0debc4:	10000002 */ 	beqz	$zero,.L0f0debd0
/*  f0debc8:	03e01825 */ 	or	$v1,$ra,$zero
/*  f0debcc:	00001825 */ 	or	$v1,$zero,$zero
.L0f0debd0:
/*  f0debd0:	51a00004 */ 	beqzl	$t5,.L0f0debe4
/*  f0debd4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0debd8:	10000002 */ 	beqz	$zero,.L0f0debe4
/*  f0debdc:	03e01025 */ 	or	$v0,$ra,$zero
/*  f0debe0:	00001025 */ 	or	$v0,$zero,$zero
.L0f0debe4:
/*  f0debe4:	00437021 */ 	addu	$t6,$v0,$v1
/*  f0debe8:	01c5c021 */ 	addu	$t8,$t6,$a1
/*  f0debec:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f0debf0:	2b210003 */ 	slti	$at,$t9,0x3
/*  f0debf4:	14200009 */ 	bnez	$at,.L0f0dec1c
/*  f0debf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0debfc:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f0dec00:	8dee01c0 */ 	lw	$t6,0x1c0($t7)
/*  f0dec04:	31d80001 */ 	andi	$t8,$t6,0x1
/*  f0dec08:	57000004 */ 	bnezl	$t8,.L0f0dec1c
/*  f0dec0c:	2529fff0 */ 	addiu	$t1,$t1,-16
/*  f0dec10:	10000002 */ 	beqz	$zero,.L0f0dec1c
/*  f0dec14:	2529ffff */ 	addiu	$t1,$t1,-1
/*  f0dec18:	2529fff0 */ 	addiu	$t1,$t1,-16
.L0f0dec1c:
/*  f0dec1c:	10000011 */ 	beqz	$zero,.L0f0dec64
/*  f0dec20:	8fa30038 */ 	lw	$v1,0x38($sp)
.L0f0dec24:
/*  f0dec24:	946f001c */ 	lhu	$t7,0x1c($v1)
/*  f0dec28:	8c7801d0 */ 	lw	$t8,0x1d0($v1)
/*  f0dec2c:	018bc821 */ 	addu	$t9,$t4,$t3
/*  f0dec30:	032f7023 */ 	subu	$t6,$t9,$t7
/*  f0dec34:	01d84823 */ 	subu	$t1,$t6,$t8
/*  f0dec38:	1000000a */ 	beqz	$zero,.L0f0dec64
/*  f0dec3c:	2529ffc7 */ 	addiu	$t1,$t1,-57
/*  f0dec40:	9479001c */ 	lhu	$t9,0x1c($v1)
.L0f0dec44:
/*  f0dec44:	01797823 */ 	subu	$t7,$t3,$t9
/*  f0dec48:	8c7901d0 */ 	lw	$t9,0x1d0($v1)
/*  f0dec4c:	05e10003 */ 	bgez	$t7,.L0f0dec5c
/*  f0dec50:	000f7043 */ 	sra	$t6,$t7,0x1
/*  f0dec54:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0dec58:	00017043 */ 	sra	$t6,$at,0x1
.L0f0dec5c:
/*  f0dec5c:	01ccc021 */ 	addu	$t8,$t6,$t4
/*  f0dec60:	03194821 */ 	addu	$t1,$t8,$t9
.L0f0dec64:
/*  f0dec64:	906f01c9 */ 	lbu	$t7,0x1c9($v1)
/*  f0dec68:	25eefffc */ 	addiu	$t6,$t7,-4
/*  f0dec6c:	2dc10005 */ 	sltiu	$at,$t6,0x5
/*  f0dec70:	1020008b */ 	beqz	$at,.L0f0deea0
/*  f0dec74:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0dec78:	3c017f1b */ 	lui	$at,%hi(var7f1adeb0)
/*  f0dec7c:	002e0821 */ 	addu	$at,$at,$t6
/*  f0dec80:	8c2edeb0 */ 	lw	$t6,%lo(var7f1adeb0)($at)
/*  f0dec84:	01c00008 */ 	jr	$t6
/*  f0dec88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dec8c:	10000085 */ 	beqz	$zero,.L0f0deea4
/*  f0dec90:	8c6401d4 */ 	lw	$a0,0x1d4($v1)
/*  f0dec94:	8fb80028 */ 	lw	$t8,0x28($sp)
/*  f0dec98:	8c7901d4 */ 	lw	$t9,0x1d4($v1)
/*  f0dec9c:	03192021 */ 	addu	$a0,$t8,$t9
/*  f0deca0:	10000080 */ 	beqz	$zero,.L0f0deea4
/*  f0deca4:	2484000d */ 	addiu	$a0,$a0,0xd
/*  f0deca8:	8faf0028 */ 	lw	$t7,0x28($sp)
/*  f0decac:	8fae0020 */ 	lw	$t6,0x20($sp)
/*  f0decb0:	9479001e */ 	lhu	$t9,0x1e($v1)
/*  f0decb4:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x6c)
/*  f0decb8:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f0decbc:	8c6e01d4 */ 	lw	$t6,0x1d4($v1)
/*  f0decc0:	8d08a02c */ 	lw	$t0,%lo(g_Vars+0x6c)($t0)
/*  f0decc4:	03197823 */ 	subu	$t7,$t8,$t9
/*  f0decc8:	3c07800a */ 	lui	$a3,%hi(g_Vars+0x68)
/*  f0deccc:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x64)
/*  f0decd0:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x70)
/*  f0decd4:	01ee2023 */ 	subu	$a0,$t7,$t6
/*  f0decd8:	2484fff2 */ 	addiu	$a0,$a0,-14
/*  f0decdc:	8dada030 */ 	lw	$t5,%lo(g_Vars+0x70)($t5)
/*  f0dece0:	8d4aa024 */ 	lw	$t2,%lo(g_Vars+0x64)($t2)
/*  f0dece4:	11000003 */ 	beqz	$t0,.L0f0decf4
/*  f0dece8:	8ce7a028 */ 	lw	$a3,%lo(g_Vars+0x68)($a3)
/*  f0decec:	10000002 */ 	beqz	$zero,.L0f0decf8
/*  f0decf0:	03e03025 */ 	or	$a2,$ra,$zero
.L0f0decf4:
/*  f0decf4:	00003025 */ 	or	$a2,$zero,$zero
.L0f0decf8:
/*  f0decf8:	10e00003 */ 	beqz	$a3,.L0f0ded08
/*  f0decfc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0ded00:	10000002 */ 	beqz	$zero,.L0f0ded0c
/*  f0ded04:	03e02825 */ 	or	$a1,$ra,$zero
.L0f0ded08:
/*  f0ded08:	00002825 */ 	or	$a1,$zero,$zero
.L0f0ded0c:
/*  f0ded0c:	11400003 */ 	beqz	$t2,.L0f0ded1c
/*  f0ded10:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ded14:	10000001 */ 	beqz	$zero,.L0f0ded1c
/*  f0ded18:	03e01825 */ 	or	$v1,$ra,$zero
.L0f0ded1c:
/*  f0ded1c:	11a00003 */ 	beqz	$t5,.L0f0ded2c
/*  f0ded20:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ded24:	10000001 */ 	beqz	$zero,.L0f0ded2c
/*  f0ded28:	03e01025 */ 	or	$v0,$ra,$zero
.L0f0ded2c:
/*  f0ded2c:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f0ded30:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f0ded34:	03267821 */ 	addu	$t7,$t9,$a2
/*  f0ded38:	15e1001b */ 	bne	$t7,$at,.L0f0deda8
/*  f0ded3c:	3c0e8007 */ 	lui	$t6,%hi(var80070764)
/*  f0ded40:	8dce0764 */ 	lw	$t6,%lo(var80070764)($t6)
/*  f0ded44:	3c188006 */ 	lui	$t8,%hi(var8005d9d0)
/*  f0ded48:	3c198009 */ 	lui	$t9,%hi(g_Is4Mb)
/*  f0ded4c:	11c00004 */ 	beqz	$t6,.L0f0ded60
/*  f0ded50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ded54:	8f18d9d0 */ 	lw	$t8,%lo(var8005d9d0)($t8)
/*  f0ded58:	13000013 */ 	beqz	$t8,.L0f0deda8
/*  f0ded5c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ded60:
/*  f0ded60:	93390af0 */ 	lbu	$t9,%lo(g_Is4Mb)($t9)
/*  f0ded64:	13f9000c */ 	beq	$ra,$t9,.L0f0ded98
/*  f0ded68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ded6c:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f0ded70:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0ded74:	afa90034 */ 	sw	$t1,0x34($sp)
/*  f0ded78:	241f0001 */ 	addiu	$ra,$zero,0x1
/*  f0ded7c:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f0ded80:	13e20007 */ 	beq	$ra,$v0,.L0f0deda0
/*  f0ded84:	8fa90034 */ 	lw	$t1,0x34($sp)
/*  f0ded88:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f0ded8c:	8dee01c0 */ 	lw	$t6,0x1c0($t7)
/*  f0ded90:	15c00003 */ 	bnez	$t6,.L0f0deda0
/*  f0ded94:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0ded98:
/*  f0ded98:	10000028 */ 	beqz	$zero,.L0f0dee3c
/*  f0ded9c:	24840008 */ 	addiu	$a0,$a0,0x8
.L0f0deda0:
/*  f0deda0:	10000026 */ 	beqz	$zero,.L0f0dee3c
/*  f0deda4:	24840003 */ 	addiu	$a0,$a0,0x3
.L0f0deda8:
/*  f0deda8:	11000003 */ 	beqz	$t0,.L0f0dedb8
/*  f0dedac:	00003025 */ 	or	$a2,$zero,$zero
/*  f0dedb0:	10000001 */ 	beqz	$zero,.L0f0dedb8
/*  f0dedb4:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0dedb8:
/*  f0dedb8:	10e00003 */ 	beqz	$a3,.L0f0dedc8
/*  f0dedbc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0dedc0:	10000001 */ 	beqz	$zero,.L0f0dedc8
/*  f0dedc4:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0dedc8:
/*  f0dedc8:	11400003 */ 	beqz	$t2,.L0f0dedd8
/*  f0dedcc:	00001825 */ 	or	$v1,$zero,$zero
/*  f0dedd0:	10000001 */ 	beqz	$zero,.L0f0dedd8
/*  f0dedd4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0dedd8:
/*  f0dedd8:	11a00003 */ 	beqz	$t5,.L0f0dede8
/*  f0deddc:	00001025 */ 	or	$v0,$zero,$zero
/*  f0dede0:	10000001 */ 	beqz	$zero,.L0f0dede8
/*  f0dede4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0dede8:
/*  f0dede8:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f0dedec:	0305c821 */ 	addu	$t9,$t8,$a1
/*  f0dedf0:	03267821 */ 	addu	$t7,$t9,$a2
/*  f0dedf4:	29e10003 */ 	slti	$at,$t7,0x3
/*  f0dedf8:	14200009 */ 	bnez	$at,.L0f0dee20
/*  f0dedfc:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f0dee00:	8dd801c0 */ 	lw	$t8,0x1c0($t6)
/*  f0dee04:	2b010002 */ 	slti	$at,$t8,0x2
/*  f0dee08:	10200003 */ 	beqz	$at,.L0f0dee18
/*  f0dee0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dee10:	1000000a */ 	beqz	$zero,.L0f0dee3c
/*  f0dee14:	24840008 */ 	addiu	$a0,$a0,0x8
.L0f0dee18:
/*  f0dee18:	10000008 */ 	beqz	$zero,.L0f0dee3c
/*  f0dee1c:	24840003 */ 	addiu	$a0,$a0,0x3
.L0f0dee20:
/*  f0dee20:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f0dee24:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f0dee28:	afa90034 */ 	sw	$t1,0x34($sp)
/*  f0dee2c:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f0dee30:	10400002 */ 	beqz	$v0,.L0f0dee3c
/*  f0dee34:	8fa90034 */ 	lw	$t1,0x34($sp)
/*  f0dee38:	24840008 */ 	addiu	$a0,$a0,0x8
.L0f0dee3c:
/*  f0dee3c:	10000019 */ 	beqz	$zero,.L0f0deea4
/*  f0dee40:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f0dee44:	8fb90020 */ 	lw	$t9,0x20($sp)
/*  f0dee48:	946f001e */ 	lhu	$t7,0x1e($v1)
/*  f0dee4c:	032f7023 */ 	subu	$t6,$t9,$t7
/*  f0dee50:	8fb90028 */ 	lw	$t9,0x28($sp)
/*  f0dee54:	05c10003 */ 	bgez	$t6,.L0f0dee64
/*  f0dee58:	000ec043 */ 	sra	$t8,$t6,0x1
/*  f0dee5c:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f0dee60:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0dee64:
/*  f0dee64:	8c6e01d4 */ 	lw	$t6,0x1d4($v1)
/*  f0dee68:	03197821 */ 	addu	$t7,$t8,$t9
/*  f0dee6c:	1000000d */ 	beqz	$zero,.L0f0deea4
/*  f0dee70:	01ee2021 */ 	addu	$a0,$t7,$t6
/*  f0dee74:	8fb80028 */ 	lw	$t8,0x28($sp)
/*  f0dee78:	8fb90020 */ 	lw	$t9,0x20($sp)
/*  f0dee7c:	946e001e */ 	lhu	$t6,0x1e($v1)
/*  f0dee80:	03197821 */ 	addu	$t7,$t8,$t9
/*  f0dee84:	05c10003 */ 	bgez	$t6,.L0f0dee94
/*  f0dee88:	000ec043 */ 	sra	$t8,$t6,0x1
/*  f0dee8c:	25c10001 */ 	addiu	$at,$t6,0x1
/*  f0dee90:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0dee94:
/*  f0dee94:	01f82023 */ 	subu	$a0,$t7,$t8
/*  f0dee98:	10000002 */ 	beqz	$zero,.L0f0deea4
/*  f0dee9c:	24840012 */ 	addiu	$a0,$a0,0x12
.L0f0deea0:
/*  f0deea0:	8c6401d4 */ 	lw	$a0,0x1d4($v1)
.L0f0deea4:
/*  f0deea4:	a4690018 */ 	sh	$t1,0x18($v1)
/*  f0deea8:	a464001a */ 	sh	$a0,0x1a($v1)
/*  f0deeac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0deeb0:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0deeb4:	03e00008 */ 	jr	$ra
/*  f0deeb8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0deebc
/*  f0deebc:	27bdfe08 */ 	addiu	$sp,$sp,-504
/*  f0deec0:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0deec4:	24110006 */ 	addiu	$s1,$zero,0x6
/*  f0deec8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0deecc:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0deed0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0deed4:	afa401f8 */ 	sw	$a0,0x1f8($sp)
/*  f0deed8:	afa501fc */ 	sw	$a1,0x1fc($sp)
/*  f0deedc:	afa60200 */ 	sw	$a2,0x200($sp)
/*  f0deee0:	afa70204 */ 	sw	$a3,0x204($sp)
/*  f0deee4:	14b10005 */ 	bne	$a1,$s1,.L0f0deefc
/*  f0deee8:	00004825 */ 	or	$t1,$zero,$zero
/*  f0deeec:	0fc54a43 */ 	jal	optionsGetInGameSubtitles
/*  f0deef0:	afa001ec */ 	sw	$zero,0x1ec($sp)
/*  f0deef4:	10400115 */ 	beqz	$v0,.L0f0df34c
/*  f0deef8:	8fa901ec */ 	lw	$t1,0x1ec($sp)
.L0f0deefc:
/*  f0deefc:	8faf01f8 */ 	lw	$t7,0x1f8($sp)
/*  f0def00:	8fb90230 */ 	lw	$t9,0x230($sp)
/*  f0def04:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0def08:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f0def0c:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0def10:	01e01025 */ 	or	$v0,$t7,$zero
/*  f0def14:	13000007 */ 	beqz	$t8,.L0f0def34
/*  f0def18:	332a0001 */ 	andi	$t2,$t9,0x1
/*  f0def1c:	91e30000 */ 	lbu	$v1,0x0($t7)
/*  f0def20:	00694821 */ 	addu	$t1,$v1,$t1
.L0f0def24:
/*  f0def24:	90430001 */ 	lbu	$v1,0x1($v0)
/*  f0def28:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0def2c:	5460fffd */ 	bnezl	$v1,.L0f0def24
/*  f0def30:	00694821 */ 	addu	$t1,$v1,$t1
.L0f0def34:
/*  f0def34:	11400004 */ 	beqz	$t2,.L0f0def48
/*  f0def38:	8fad0230 */ 	lw	$t5,0x230($sp)
/*  f0def3c:	8ceb0284 */ 	lw	$t3,0x284($a3)
/*  f0def40:	8d6c00d8 */ 	lw	$t4,0xd8($t3)
/*  f0def44:	15800101 */ 	bnez	$t4,.L0f0df34c
.L0f0def48:
/*  f0def48:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0def4c:	31ae0008 */ 	andi	$t6,$t5,0x8
/*  f0def50:	15c0001b */ 	bnez	$t6,.L0f0defc0
/*  f0def54:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0def58:	3c048007 */ 	lui	$a0,%hi(g_NumHudMessages)
/*  f0def5c:	8c840fe8 */ 	lw	$a0,%lo(g_NumHudMessages)($a0)
/*  f0def60:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0def64:	00008025 */ 	or	$s0,$zero,$zero
/*  f0def68:	18800014 */ 	blez	$a0,.L0f0defbc
/*  f0def6c:	3c028007 */ 	lui	$v0,%hi(var800701dc)
/*  f0def70:	8c420fec */ 	lw	$v0,0xfec($v0)
/*  f0def74:	24050005 */ 	addiu	$a1,$zero,0x5
.L0f0def78:
/*  f0def78:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f0def7c:	5060000c */ 	beqzl	$v1,.L0f0defb0
/*  f0def80:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0def84:	50a3000a */ 	beql	$a1,$v1,.L0f0defb0
/*  f0def88:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0def8c:	8cf8028c */ 	lw	$t8,0x28c($a3)
/*  f0def90:	8c4f01c0 */ 	lw	$t7,0x1c0($v0)
/*  f0def94:	570f0006 */ 	bnel	$t8,$t7,.L0f0defb0
/*  f0def98:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0def9c:	8c5901d8 */ 	lw	$t9,0x1d8($v0)
/*  f0defa0:	55390003 */ 	bnel	$t1,$t9,.L0f0defb0
/*  f0defa4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0defa8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0defac:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0defb0:
/*  f0defb0:	0204082a */ 	slt	$at,$s0,$a0
/*  f0defb4:	1420fff0 */ 	bnez	$at,.L0f0def78
/*  f0defb8:	244201dc */ 	addiu	$v0,$v0,%lo(var800701dc)
.L0f0defbc:
/*  f0defbc:	04c100e3 */ 	bgez	$a2,.L0f0df34c
.L0f0defc0:
/*  f0defc0:	3c0a8007 */ 	lui	$t2,%hi(var800706c8)
/*  f0defc4:	8d4a06c8 */ 	lw	$t2,%lo(var800706c8)($t2)
/*  f0defc8:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0defcc:	3c048007 */ 	lui	$a0,%hi(g_NumHudMessages)
/*  f0defd0:	8c840fe8 */ 	lw	$a0,%lo(g_NumHudMessages)($a0)
/*  f0defd4:	146a0005 */ 	bne	$v1,$t2,.L0f0defec
/*  f0defd8:	00008025 */ 	or	$s0,$zero,$zero
/*  f0defdc:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f0defe0:	3c018008 */ 	lui	$at,0x8008
/*  f0defe4:	10000003 */ 	beqz	$zero,.L0f0deff4
/*  f0defe8:	ac2bfac0 */ 	sw	$t3,-0x540($at)
.L0f0defec:
/*  f0defec:	3c018008 */ 	lui	$at,0x8008
/*  f0deff0:	ac23fac0 */ 	sw	$v1,-0x540($at)
.L0f0deff4:
/*  f0deff4:	18800009 */ 	blez	$a0,.L0f0df01c
/*  f0deff8:	3c028007 */ 	lui	$v0,%hi(var800701dc)
/*  f0deffc:	8c420fec */ 	lw	$v0,0xfec($v0)
.L0f0df000:
/*  f0df000:	904c0000 */ 	lbu	$t4,0x0($v0)
/*  f0df004:	51800006 */ 	beqzl	$t4,.L0f0df020
/*  f0df008:	0204082a */ 	slt	$at,$s0,$a0
/*  f0df00c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0df010:	0204082a */ 	slt	$at,$s0,$a0
/*  f0df014:	1420fffa */ 	bnez	$at,.L0f0df000
/*  f0df018:	244201dc */ 	addiu	$v0,$v0,%lo(var800701dc)
.L0f0df01c:
/*  f0df01c:	0204082a */ 	slt	$at,$s0,$a0
.L0f0df020:
/*  f0df020:	14200028 */ 	bnez	$at,.L0f0df0c4
/*  f0df024:	8fad01fc */ 	lw	$t5,0x1fc($sp)
/*  f0df028:	11a30004 */ 	beq	$t5,$v1,.L0f0df03c
/*  f0df02c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0df030:	51a10003 */ 	beql	$t5,$at,.L0f0df040
/*  f0df034:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0df038:	15b10022 */ 	bne	$t5,$s1,.L0f0df0c4
.L0f0df03c:
/*  f0df03c:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f0df040:
/*  f0df040:	0fc377ab */ 	jal	func0f0ddeac
/*  f0df044:	afa901ec */ 	sw	$t1,0x1ec($sp)
/*  f0df048:	8fa901ec */ 	lw	$t1,0x1ec($sp)
/*  f0df04c:	0440001d */ 	bltz	$v0,.L0f0df0c4
/*  f0df050:	00408025 */ 	or	$s0,$v0,$zero
/*  f0df054:	241201dc */ 	addiu	$s2,$zero,0x1dc
/*  f0df058:	24110003 */ 	addiu	$s1,$zero,0x3
.L0f0df05c:
/*  f0df05c:	00520019 */ 	multu	$v0,$s2
/*  f0df060:	3c058007 */ 	lui	$a1,%hi(g_HudMessages)
/*  f0df064:	8ca50fec */ 	lw	$a1,%lo(g_HudMessages)($a1)
/*  f0df068:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0df06c:	00007012 */ 	mflo	$t6
/*  f0df070:	00ae2021 */ 	addu	$a0,$a1,$t6
/*  f0df074:	90980000 */ 	lbu	$t8,0x0($a0)
/*  f0df078:	17010009 */ 	bne	$t8,$at,.L0f0df0a0
/*  f0df07c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df080:	8c8301b4 */ 	lw	$v1,0x1b4($a0)
/*  f0df084:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0df088:	5060000f */ 	beqzl	$v1,.L0f0df0c8
/*  f0df08c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0df090:	5223000d */ 	beql	$s1,$v1,.L0f0df0c8
/*  f0df094:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0df098:	5061000b */ 	beql	$v1,$at,.L0f0df0c8
/*  f0df09c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0df0a0:
/*  f0df0a0:	02120019 */ 	multu	$s0,$s2
/*  f0df0a4:	00007812 */ 	mflo	$t7
/*  f0df0a8:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f0df0ac:	8f2401b8 */ 	lw	$a0,0x1b8($t9)
/*  f0df0b0:	0fc377ab */ 	jal	func0f0ddeac
/*  f0df0b4:	afa901ec */ 	sw	$t1,0x1ec($sp)
/*  f0df0b8:	8fa901ec */ 	lw	$t1,0x1ec($sp)
/*  f0df0bc:	0441ffe7 */ 	bgez	$v0,.L0f0df05c
/*  f0df0c0:	00408025 */ 	or	$s0,$v0,$zero
.L0f0df0c4:
/*  f0df0c4:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0df0c8:
/*  f0df0c8:	0600009e */ 	bltz	$s0,.L0f0df344
/*  f0df0cc:	241201dc */ 	addiu	$s2,$zero,0x1dc
/*  f0df0d0:	3c0a8007 */ 	lui	$t2,%hi(g_NumHudMessages)
/*  f0df0d4:	8d4a0fe8 */ 	lw	$t2,%lo(g_NumHudMessages)($t2)
/*  f0df0d8:	020a082a */ 	slt	$at,$s0,$t2
/*  f0df0dc:	10200099 */ 	beqz	$at,.L0f0df344
/*  f0df0e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df0e4:	02120019 */ 	multu	$s0,$s2
/*  f0df0e8:	3c0c8007 */ 	lui	$t4,%hi(g_HudMessages)
/*  f0df0ec:	8d8c0fec */ 	lw	$t4,%lo(g_HudMessages)($t4)
/*  f0df0f0:	afa001d8 */ 	sw	$zero,0x1d8($sp)
/*  f0df0f4:	27a401d8 */ 	addiu	$a0,$sp,0x1d8
/*  f0df0f8:	8fa50220 */ 	lw	$a1,0x220($sp)
/*  f0df0fc:	afa901ec */ 	sw	$t1,0x1ec($sp)
/*  f0df100:	00005812 */ 	mflo	$t3
/*  f0df104:	016c8821 */ 	addu	$s1,$t3,$t4
/*  f0df108:	0fc376c7 */ 	jal	func0f0ddb1c
/*  f0df10c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df110:	8fae0210 */ 	lw	$t6,0x210($sp)
/*  f0df114:	8fad020c */ 	lw	$t5,0x20c($sp)
/*  f0df118:	afa201d4 */ 	sw	$v0,0x1d4($sp)
/*  f0df11c:	8dd80000 */ 	lw	$t8,0x0($t6)
/*  f0df120:	8da70000 */ 	lw	$a3,0x0($t5)
/*  f0df124:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0df128:	27a401dc */ 	addiu	$a0,$sp,0x1dc
/*  f0df12c:	27a501e0 */ 	addiu	$a1,$sp,0x1e0
/*  f0df130:	8fa601f8 */ 	lw	$a2,0x1f8($sp)
/*  f0df134:	0fc55cbe */ 	jal	func0f1572f8
/*  f0df138:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0df13c:	8faf01d4 */ 	lw	$t7,0x1d4($sp)
/*  f0df140:	8fb901e0 */ 	lw	$t9,0x1e0($sp)
/*  f0df144:	8fa901ec */ 	lw	$t1,0x1ec($sp)
/*  f0df148:	26240020 */ 	addiu	$a0,$s1,0x20
/*  f0df14c:	01f9082a */ 	slt	$at,$t7,$t9
/*  f0df150:	10200033 */ 	beqz	$at,.L0f0df220
/*  f0df154:	8fa501f8 */ 	lw	$a1,0x1f8($sp)
/*  f0df158:	8faa01f8 */ 	lw	$t2,0x1f8($sp)
/*  f0df15c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0df160:	00004025 */ 	or	$t0,$zero,$zero
/*  f0df164:	914b0000 */ 	lbu	$t3,0x0($t2)
/*  f0df168:	240d000a */ 	addiu	$t5,$zero,0xa
/*  f0df16c:	26320020 */ 	addiu	$s2,$s1,0x20
/*  f0df170:	11600010 */ 	beqz	$t3,.L0f0df1b4
/*  f0df174:	01401021 */ 	addu	$v0,$t2,$zero
/*  f0df178:	91430000 */ 	lbu	$v1,0x0($t2)
/*  f0df17c:	27b00044 */ 	addiu	$s0,$sp,0x44
/*  f0df180:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f0df184:	00602025 */ 	or	$a0,$v1,$zero
.L0f0df188:
/*  f0df188:	10c40004 */ 	beq	$a2,$a0,.L0f0df19c
/*  f0df18c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0df190:	02086021 */ 	addu	$t4,$s0,$t0
/*  f0df194:	a1830000 */ 	sb	$v1,0x0($t4)
/*  f0df198:	25080001 */ 	addiu	$t0,$t0,0x1
.L0f0df19c:
/*  f0df19c:	28a10190 */ 	slti	$at,$a1,0x190
/*  f0df1a0:	10200004 */ 	beqz	$at,.L0f0df1b4
/*  f0df1a4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0df1a8:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f0df1ac:	1460fff6 */ 	bnez	$v1,.L0f0df188
/*  f0df1b0:	00602025 */ 	or	$a0,$v1,$zero
.L0f0df1b4:
/*  f0df1b4:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0df1b8:	00a87021 */ 	addu	$t6,$a1,$t0
/*  f0df1bc:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f0df1c0:	a1cd0000 */ 	sb	$t5,0x0($t6)
/*  f0df1c4:	00a8c021 */ 	addu	$t8,$a1,$t0
/*  f0df1c8:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f0df1cc:	8fb90210 */ 	lw	$t9,0x210($sp)
/*  f0df1d0:	8faf020c */ 	lw	$t7,0x20c($sp)
/*  f0df1d4:	8fa401d4 */ 	lw	$a0,0x1d4($sp)
/*  f0df1d8:	8f2b0000 */ 	lw	$t3,0x0($t9)
/*  f0df1dc:	8de70000 */ 	lw	$a3,0x0($t7)
/*  f0df1e0:	afa901ec */ 	sw	$t1,0x1ec($sp)
/*  f0df1e4:	02403025 */ 	or	$a2,$s2,$zero
/*  f0df1e8:	0fc55d48 */ 	jal	func0f157520
/*  f0df1ec:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0df1f0:	8fac0210 */ 	lw	$t4,0x210($sp)
/*  f0df1f4:	8faa020c */ 	lw	$t2,0x20c($sp)
/*  f0df1f8:	27a401dc */ 	addiu	$a0,$sp,0x1dc
/*  f0df1fc:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f0df200:	8d470000 */ 	lw	$a3,0x0($t2)
/*  f0df204:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0df208:	27a501e0 */ 	addiu	$a1,$sp,0x1e0
/*  f0df20c:	02403025 */ 	or	$a2,$s2,$zero
/*  f0df210:	0fc55cbe */ 	jal	func0f1572f8
/*  f0df214:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0df218:	10000006 */ 	beqz	$zero,.L0f0df234
/*  f0df21c:	8fa901ec */ 	lw	$t1,0x1ec($sp)
.L0f0df220:
/*  f0df220:	2406018f */ 	addiu	$a2,$zero,0x18f
/*  f0df224:	0c004c72 */ 	jal	func000131c8
/*  f0df228:	afa901ec */ 	sw	$t1,0x1ec($sp)
/*  f0df22c:	8fa901ec */ 	lw	$t1,0x1ec($sp)
/*  f0df230:	a22001af */ 	sb	$zero,0x1af($s1)
.L0f0df234:
/*  f0df234:	8fae0230 */ 	lw	$t6,0x230($sp)
/*  f0df238:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x28c)
/*  f0df23c:	3c02800a */ 	lui	$v0,%hi(var8009dea0)
/*  f0df240:	ae2e01c4 */ 	sw	$t6,0x1c4($s1)
/*  f0df244:	8f18a24c */ 	lw	$t8,%lo(g_Vars+0x28c)($t8)
/*  f0df248:	2442dea0 */ 	addiu	$v0,$v0,%lo(var8009dea0)
/*  f0df24c:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0df250:	ae3801c0 */ 	sw	$t8,0x1c0($s1)
/*  f0df254:	8faf01fc */ 	lw	$t7,0x1fc($sp)
/*  f0df258:	02202025 */ 	or	$a0,$s1,$zero
/*  f0df25c:	ae2f01b4 */ 	sw	$t7,0x1b4($s1)
/*  f0df260:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f0df264:	ae3901b8 */ 	sw	$t9,0x1b8($s1)
/*  f0df268:	8c4b0000 */ 	lw	$t3,0x0($v0)
/*  f0df26c:	256a0001 */ 	addiu	$t2,$t3,0x1
/*  f0df270:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f0df274:	a22c0000 */ 	sb	$t4,0x0($s1)
/*  f0df278:	a6200006 */ 	sh	$zero,0x6($s1)
/*  f0df27c:	8fad0200 */ 	lw	$t5,0x200($sp)
/*  f0df280:	a22d0001 */ 	sb	$t5,0x1($s1)
/*  f0df284:	8fae0204 */ 	lw	$t6,0x204($sp)
/*  f0df288:	a22e0002 */ 	sb	$t6,0x2($s1)
/*  f0df28c:	8fb80208 */ 	lw	$t8,0x208($sp)
/*  f0df290:	a2380003 */ 	sb	$t8,0x3($s1)
/*  f0df294:	8faf020c */ 	lw	$t7,0x20c($sp)
/*  f0df298:	8df90000 */ 	lw	$t9,0x0($t7)
/*  f0df29c:	ae390008 */ 	sw	$t9,0x8($s1)
/*  f0df2a0:	8fab0210 */ 	lw	$t3,0x210($sp)
/*  f0df2a4:	8d6a0000 */ 	lw	$t2,0x0($t3)
/*  f0df2a8:	ae2a000c */ 	sw	$t2,0xc($s1)
/*  f0df2ac:	8fac0214 */ 	lw	$t4,0x214($sp)
/*  f0df2b0:	ae2c0010 */ 	sw	$t4,0x10($s1)
/*  f0df2b4:	8fad0218 */ 	lw	$t5,0x218($sp)
/*  f0df2b8:	ae2d0014 */ 	sw	$t5,0x14($s1)
/*  f0df2bc:	8fae021c */ 	lw	$t6,0x21c($sp)
/*  f0df2c0:	a22e01c8 */ 	sb	$t6,0x1c8($s1)
/*  f0df2c4:	8fb80224 */ 	lw	$t8,0x224($sp)
/*  f0df2c8:	a23801c9 */ 	sb	$t8,0x1c9($s1)
/*  f0df2cc:	8faf01e0 */ 	lw	$t7,0x1e0($sp)
/*  f0df2d0:	a62f001c */ 	sh	$t7,0x1c($s1)
/*  f0df2d4:	8fb901dc */ 	lw	$t9,0x1dc($sp)
/*  f0df2d8:	a639001e */ 	sh	$t9,0x1e($s1)
/*  f0df2dc:	8fab01d8 */ 	lw	$t3,0x1d8($sp)
/*  f0df2e0:	ae2b01cc */ 	sw	$t3,0x1cc($s1)
/*  f0df2e4:	8faa0220 */ 	lw	$t2,0x220($sp)
/*  f0df2e8:	ae2a01d0 */ 	sw	$t2,0x1d0($s1)
/*  f0df2ec:	8fac0228 */ 	lw	$t4,0x228($sp)
/*  f0df2f0:	ae2901d8 */ 	sw	$t1,0x1d8($s1)
/*  f0df2f4:	0fc379ff */ 	jal	func0f0de7fc
/*  f0df2f8:	ae2c01d4 */ 	sw	$t4,0x1d4($s1)
/*  f0df2fc:	8fad0230 */ 	lw	$t5,0x230($sp)
/*  f0df300:	8fb901fc */ 	lw	$t9,0x1fc($sp)
/*  f0df304:	3c0a8007 */ 	lui	$t2,%hi(g_HudMessageConfigs+0x1c)
/*  f0df308:	31ae0004 */ 	andi	$t6,$t5,0x4
/*  f0df30c:	11c00007 */ 	beqz	$t6,.L0f0df32c
/*  f0df310:	00195940 */ 	sll	$t3,$t9,0x5
/*  f0df314:	8fb8022c */ 	lw	$t8,0x22c($sp)
/*  f0df318:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0df31c:	ae2f01b0 */ 	sw	$t7,0x1b0($s1)
/*  f0df320:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0df324:	10000007 */ 	beqz	$zero,.L0f0df344
/*  f0df328:	ae3801bc */ 	sw	$t8,0x1bc($s1)
.L0f0df32c:
/*  f0df32c:	014b5021 */ 	addu	$t2,$t2,$t3
/*  f0df330:	8d4a100c */ 	lw	$t2,%lo(g_HudMessageConfigs+0x1c)($t2)
/*  f0df334:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0df338:	ae2a01bc */ 	sw	$t2,0x1bc($s1)
/*  f0df33c:	8fac022c */ 	lw	$t4,0x22c($sp)
/*  f0df340:	ae2c01b0 */ 	sw	$t4,0x1b0($s1)
.L0f0df344:
/*  f0df344:	3c018008 */ 	lui	$at,0x8008
/*  f0df348:	ac23fac0 */ 	sw	$v1,-0x540($at)
.L0f0df34c:
/*  f0df34c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0df350:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0df354:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0df358:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0df35c:	03e00008 */ 	jr	$ra
/*  f0df360:	27bd01f8 */ 	addiu	$sp,$sp,0x1f8
);

GLOBAL_ASM(
glabel func0f0df364
.late_rodata
glabel var7f1adec4
.word func0f0df364+0x680 # f0df9e4
glabel var7f1adec8
.word func0f0df364+0x1e4 # f0df548
glabel var7f1adecc
.word func0f0df364+0x39c # f0df700
glabel var7f1aded0
.word func0f0df364+0x3dc # f0df740
glabel var7f1aded4
.word func0f0df364+0x564 # f0df8c8
glabel var7f1aded8
.word func0f0df364+0x604 # f0df968
.text
/*  f0df364:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f0df368:	3c0e8007 */ 	lui	$t6,%hi(var800706c8)
/*  f0df36c:	8dce06c8 */ 	lw	$t6,%lo(var800706c8)($t6)
/*  f0df370:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f0df374:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0df378:	3c018007 */ 	lui	$at,0x8007
/*  f0df37c:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0df380:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f0df384:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f0df388:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f0df38c:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f0df390:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f0df394:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0df398:	164e0005 */ 	bne	$s2,$t6,.L0f0df3b0
/*  f0df39c:	a0200fb0 */ 	sb	$zero,0xfb0($at)
/*  f0df3a0:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0df3a4:	3c018008 */ 	lui	$at,0x8008
/*  f0df3a8:	10000003 */ 	beqz	$zero,.L0f0df3b8
/*  f0df3ac:	ac2ffac0 */ 	sw	$t7,-0x540($at)
.L0f0df3b0:
/*  f0df3b0:	3c018008 */ 	lui	$at,0x8008
/*  f0df3b4:	ac32fac0 */ 	sw	$s2,-0x540($at)
.L0f0df3b8:
/*  f0df3b8:	3c088007 */ 	lui	$t0,%hi(g_NumHudMessages)
/*  f0df3bc:	8d080fe8 */ 	lw	$t0,%lo(g_NumHudMessages)($t0)
/*  f0df3c0:	3c13800a */ 	lui	$s3,%hi(g_Vars)
/*  f0df3c4:	26739fc0 */ 	addiu	$s3,$s3,%lo(g_Vars)
/*  f0df3c8:	8e74028c */ 	lw	$s4,0x28c($s3)
/*  f0df3cc:	19000032 */ 	blez	$t0,.L0f0df498
/*  f0df3d0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0df3d4:	3c168007 */ 	lui	$s6,%hi(g_HudMessages)
/*  f0df3d8:	26d60fec */ 	addiu	$s6,$s6,%lo(g_HudMessages)
/*  f0df3dc:	00008025 */ 	or	$s0,$zero,$zero
/*  f0df3e0:	241101dc */ 	addiu	$s1,$zero,0x1dc
.L0f0df3e4:
/*  f0df3e4:	8ec40000 */ 	lw	$a0,0x0($s6)
/*  f0df3e8:	00902821 */ 	addu	$a1,$a0,$s0
/*  f0df3ec:	90b80000 */ 	lbu	$t8,0x0($a1)
/*  f0df3f0:	53000026 */ 	beqzl	$t8,.L0f0df48c
/*  f0df3f4:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0df3f8:	8e7902ac */ 	lw	$t9,0x2ac($s3)
/*  f0df3fc:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0df400:	57210019 */ 	bnel	$t9,$at,.L0f0df468
/*  f0df404:	8ca401c0 */ 	lw	$a0,0x1c0($a1)
/*  f0df408:	19000016 */ 	blez	$t0,.L0f0df464
/*  f0df40c:	00001825 */ 	or	$v1,$zero,$zero
.L0f0df410:
/*  f0df410:	50c30011 */ 	beql	$a2,$v1,.L0f0df458
/*  f0df414:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0df418:	00710019 */ 	multu	$v1,$s1
/*  f0df41c:	00005012 */ 	mflo	$t2
/*  f0df420:	008a1021 */ 	addu	$v0,$a0,$t2
/*  f0df424:	904b0000 */ 	lbu	$t3,0x0($v0)
/*  f0df428:	5160000b */ 	beqzl	$t3,.L0f0df458
/*  f0df42c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0df430:	8c4c01d8 */ 	lw	$t4,0x1d8($v0)
/*  f0df434:	8cad01d8 */ 	lw	$t5,0x1d8($a1)
/*  f0df438:	558d0007 */ 	bnel	$t4,$t5,.L0f0df458
/*  f0df43c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0df440:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f0df444:	8ec40000 */ 	lw	$a0,0x0($s6)
/*  f0df448:	3c088007 */ 	lui	$t0,%hi(g_NumHudMessages)
/*  f0df44c:	8d080fe8 */ 	lw	$t0,%lo(g_NumHudMessages)($t0)
/*  f0df450:	00902821 */ 	addu	$a1,$a0,$s0
/*  f0df454:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f0df458:
/*  f0df458:	0068082a */ 	slt	$at,$v1,$t0
/*  f0df45c:	1420ffec */ 	bnez	$at,.L0f0df410
/*  f0df460:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0df464:
/*  f0df464:	8ca401c0 */ 	lw	$a0,0x1c0($a1)
.L0f0df468:
/*  f0df468:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0df46c:	afa6006c */ 	sw	$a2,0x6c($sp)
/*  f0df470:	8ece0000 */ 	lw	$t6,0x0($s6)
/*  f0df474:	0fc379ff */ 	jal	func0f0de7fc
/*  f0df478:	020e2021 */ 	addu	$a0,$s0,$t6
/*  f0df47c:	3c088007 */ 	lui	$t0,%hi(g_NumHudMessages)
/*  f0df480:	8d080fe8 */ 	lw	$t0,%lo(g_NumHudMessages)($t0)
/*  f0df484:	8fa6006c */ 	lw	$a2,0x6c($sp)
/*  f0df488:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f0df48c:
/*  f0df48c:	00c8082a */ 	slt	$at,$a2,$t0
/*  f0df490:	1420ffd4 */ 	bnez	$at,.L0f0df3e4
/*  f0df494:	261001dc */ 	addiu	$s0,$s0,0x1dc
.L0f0df498:
/*  f0df498:	3c168007 */ 	lui	$s6,%hi(g_HudMessages)
/*  f0df49c:	26d60fec */ 	addiu	$s6,$s6,%lo(g_HudMessages)
/*  f0df4a0:	241101dc */ 	addiu	$s1,$zero,0x1dc
/*  f0df4a4:	0fc4a24b */ 	jal	setCurrentPlayerNum
/*  f0df4a8:	02802025 */ 	or	$a0,$s4,$zero
/*  f0df4ac:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0df4b0:	24150004 */ 	addiu	$s5,$zero,0x4
/*  f0df4b4:	2414000b */ 	addiu	$s4,$zero,0xb
.L0f0df4b8:
/*  f0df4b8:	0fc377ab */ 	jal	func0f0ddeac
/*  f0df4bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df4c0:	0440014a */ 	bltz	$v0,.L0f0df9ec
/*  f0df4c4:	240a00ff */ 	addiu	$t2,$zero,0xff
/*  f0df4c8:	00510019 */ 	multu	$v0,$s1
/*  f0df4cc:	8ed80000 */ 	lw	$t8,0x0($s6)
/*  f0df4d0:	00007812 */ 	mflo	$t7
/*  f0df4d4:	01f88021 */ 	addu	$s0,$t7,$t8
/*  f0df4d8:	8e1901b8 */ 	lw	$t9,0x1b8($s0)
/*  f0df4dc:	afb90068 */ 	sw	$t9,0x68($sp)
/*  f0df4e0:	8e0401b0 */ 	lw	$a0,0x1b0($s0)
/*  f0df4e4:	04820006 */ 	bltzl	$a0,.L0f0df500
/*  f0df4e8:	a20a0004 */ 	sb	$t2,0x4($s0)
/*  f0df4ec:	0fc24adf */ 	jal	func0f092b7c
/*  f0df4f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df4f4:	10000002 */ 	beqz	$zero,.L0f0df500
/*  f0df4f8:	a2020004 */ 	sb	$v0,0x4($s0)
/*  f0df4fc:	a20a0004 */ 	sb	$t2,0x4($s0)
.L0f0df500:
/*  f0df500:	8e0b01b4 */ 	lw	$t3,0x1b4($s0)
/*  f0df504:	568b0008 */ 	bnel	$s4,$t3,.L0f0df528
/*  f0df508:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f0df50c:	8e6c02ac */ 	lw	$t4,0x2ac($s3)
/*  f0df510:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0df514:	51810004 */ 	beql	$t4,$at,.L0f0df528
/*  f0df518:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f0df51c:	a2000000 */ 	sb	$zero,0x0($s0)
/*  f0df520:	a6000006 */ 	sh	$zero,0x6($s0)
/*  f0df524:	920d0000 */ 	lbu	$t5,0x0($s0)
.L0f0df528:
/*  f0df528:	2da10006 */ 	sltiu	$at,$t5,0x6
/*  f0df52c:	1020012d */ 	beqz	$at,.L0f0df9e4
/*  f0df530:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0df534:	3c017f1b */ 	lui	$at,%hi(var7f1adec4)
/*  f0df538:	002d0821 */ 	addu	$at,$at,$t5
/*  f0df53c:	8c2ddec4 */ 	lw	$t5,%lo(var7f1adec4)($at)
/*  f0df540:	01a00008 */ 	jr	$t5
/*  f0df544:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df548:	8e0e01c4 */ 	lw	$t6,0x1c4($s0)
/*  f0df54c:	31cf0010 */ 	andi	$t7,$t6,0x10
/*  f0df550:	51e0000d */ 	beqzl	$t7,.L0f0df588
/*  f0df554:	8e0d01c0 */ 	lw	$t5,0x1c0($s0)
/*  f0df558:	96180006 */ 	lhu	$t8,0x6($s0)
/*  f0df55c:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0df560:	332affff */ 	andi	$t2,$t9,0xffff
/*  f0df564:	29410004 */ 	slti	$at,$t2,0x4
/*  f0df568:	1420011e */ 	bnez	$at,.L0f0df9e4
/*  f0df56c:	a6190006 */ 	sh	$t9,0x6($s0)
/*  f0df570:	8e0b01c4 */ 	lw	$t3,0x1c4($s0)
/*  f0df574:	2401ffef */ 	addiu	$at,$zero,-17
/*  f0df578:	01616024 */ 	and	$t4,$t3,$at
/*  f0df57c:	10000119 */ 	beqz	$zero,.L0f0df9e4
/*  f0df580:	ae0c01c4 */ 	sw	$t4,0x1c4($s0)
/*  f0df584:	8e0d01c0 */ 	lw	$t5,0x1c0($s0)
.L0f0df588:
/*  f0df588:	02404825 */ 	or	$t1,$s2,$zero
/*  f0df58c:	3c088007 */ 	lui	$t0,%hi(g_NumHudMessages)
/*  f0df590:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f0df594:	026e7821 */ 	addu	$t7,$s3,$t6
/*  f0df598:	8df80064 */ 	lw	$t8,0x64($t7)
/*  f0df59c:	8f1900d8 */ 	lw	$t9,0xd8($t8)
/*  f0df5a0:	13200002 */ 	beqz	$t9,.L0f0df5ac
/*  f0df5a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df5a8:	00004825 */ 	or	$t1,$zero,$zero
.L0f0df5ac:
/*  f0df5ac:	1120003f */ 	beqz	$t1,.L0f0df6ac
/*  f0df5b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df5b4:	8d080fe8 */ 	lw	$t0,%lo(g_NumHudMessages)($t0)
/*  f0df5b8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0df5bc:	00003825 */ 	or	$a3,$zero,$zero
/*  f0df5c0:	1900003a */ 	blez	$t0,.L0f0df6ac
/*  f0df5c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df5c8:	8ec20000 */ 	lw	$v0,0x0($s6)
.L0f0df5cc:
/*  f0df5cc:	90460000 */ 	lbu	$a2,0x0($v0)
/*  f0df5d0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0df5d4:	50c00032 */ 	beqzl	$a2,.L0f0df6a0
/*  f0df5d8:	00a8082a */ 	slt	$at,$a1,$t0
/*  f0df5dc:	52460030 */ 	beql	$s2,$a2,.L0f0df6a0
/*  f0df5e0:	00a8082a */ 	slt	$at,$a1,$t0
/*  f0df5e4:	94430018 */ 	lhu	$v1,0x18($v0)
/*  f0df5e8:	944a001c */ 	lhu	$t2,0x1c($v0)
/*  f0df5ec:	96040018 */ 	lhu	$a0,0x18($s0)
/*  f0df5f0:	01435821 */ 	addu	$t3,$t2,$v1
/*  f0df5f4:	0164082a */ 	slt	$at,$t3,$a0
/*  f0df5f8:	54200029 */ 	bnezl	$at,.L0f0df6a0
/*  f0df5fc:	00a8082a */ 	slt	$at,$a1,$t0
/*  f0df600:	960c001c */ 	lhu	$t4,0x1c($s0)
/*  f0df604:	008c6821 */ 	addu	$t5,$a0,$t4
/*  f0df608:	01a3082a */ 	slt	$at,$t5,$v1
/*  f0df60c:	54200024 */ 	bnezl	$at,.L0f0df6a0
/*  f0df610:	00a8082a */ 	slt	$at,$a1,$t0
/*  f0df614:	9443001a */ 	lhu	$v1,0x1a($v0)
/*  f0df618:	944e001e */ 	lhu	$t6,0x1e($v0)
/*  f0df61c:	9604001a */ 	lhu	$a0,0x1a($s0)
/*  f0df620:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f0df624:	01e4082a */ 	slt	$at,$t7,$a0
/*  f0df628:	5420001d */ 	bnezl	$at,.L0f0df6a0
/*  f0df62c:	00a8082a */ 	slt	$at,$a1,$t0
/*  f0df630:	9618001e */ 	lhu	$t8,0x1e($s0)
/*  f0df634:	0098c821 */ 	addu	$t9,$a0,$t8
/*  f0df638:	0323082a */ 	slt	$at,$t9,$v1
/*  f0df63c:	54200018 */ 	bnezl	$at,.L0f0df6a0
/*  f0df640:	00a8082a */ 	slt	$at,$a1,$t0
/*  f0df644:	8e0a01b4 */ 	lw	$t2,0x1b4($s0)
/*  f0df648:	8c4b01b4 */ 	lw	$t3,0x1b4($v0)
/*  f0df64c:	00004825 */ 	or	$t1,$zero,$zero
/*  f0df650:	154b0016 */ 	bne	$t2,$t3,.L0f0df6ac
/*  f0df654:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df658:	920c0001 */ 	lbu	$t4,0x1($s0)
/*  f0df65c:	11800013 */ 	beqz	$t4,.L0f0df6ac
/*  f0df660:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df664:	904d0001 */ 	lbu	$t5,0x1($v0)
/*  f0df668:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0df66c:	11a0000f */ 	beqz	$t5,.L0f0df6ac
/*  f0df670:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df674:	14c1000d */ 	bne	$a2,$at,.L0f0df6ac
/*  f0df678:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df67c:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f0df680:	8ece0000 */ 	lw	$t6,0x0($s6)
/*  f0df684:	24180003 */ 	addiu	$t8,$zero,0x3
/*  f0df688:	01c77821 */ 	addu	$t7,$t6,$a3
/*  f0df68c:	a5e00006 */ 	sh	$zero,0x6($t7)
/*  f0df690:	a2180000 */ 	sb	$t8,0x0($s0)
/*  f0df694:	10000005 */ 	beqz	$zero,.L0f0df6ac
/*  f0df698:	a6000006 */ 	sh	$zero,0x6($s0)
/*  f0df69c:	00a8082a */ 	slt	$at,$a1,$t0
.L0f0df6a0:
/*  f0df6a0:	24e701dc */ 	addiu	$a3,$a3,0x1dc
/*  f0df6a4:	1420ffc9 */ 	bnez	$at,.L0f0df5cc
/*  f0df6a8:	244201dc */ 	addiu	$v0,$v0,0x1dc
.L0f0df6ac:
/*  f0df6ac:	112000cd */ 	beqz	$t1,.L0f0df9e4
/*  f0df6b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df6b4:	92190001 */ 	lbu	$t9,0x1($s0)
/*  f0df6b8:	240a0002 */ 	addiu	$t2,$zero,0x2
/*  f0df6bc:	53200004 */ 	beqzl	$t9,.L0f0df6d0
/*  f0df6c0:	920b0002 */ 	lbu	$t3,0x2($s0)
/*  f0df6c4:	10000008 */ 	beqz	$zero,.L0f0df6e8
/*  f0df6c8:	a20a0000 */ 	sb	$t2,0x0($s0)
/*  f0df6cc:	920b0002 */ 	lbu	$t3,0x2($s0)
.L0f0df6d0:
/*  f0df6d0:	240c0003 */ 	addiu	$t4,$zero,0x3
/*  f0df6d4:	51600004 */ 	beqzl	$t3,.L0f0df6e8
/*  f0df6d8:	a2150000 */ 	sb	$s5,0x0($s0)
/*  f0df6dc:	10000002 */ 	beqz	$zero,.L0f0df6e8
/*  f0df6e0:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f0df6e4:	a2150000 */ 	sb	$s5,0x0($s0)
.L0f0df6e8:
/*  f0df6e8:	8e0d01b4 */ 	lw	$t5,0x1b4($s0)
/*  f0df6ec:	a6000006 */ 	sh	$zero,0x6($s0)
/*  f0df6f0:	168d00bc */ 	bne	$s4,$t5,.L0f0df9e4
/*  f0df6f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df6f8:	100000ba */ 	beqz	$zero,.L0f0df9e4
/*  f0df6fc:	a2150000 */ 	sb	$s5,0x0($s0)
/*  f0df700:	920e0001 */ 	lbu	$t6,0x1($s0)
/*  f0df704:	51c00008 */ 	beqzl	$t6,.L0f0df728
/*  f0df708:	a2150000 */ 	sb	$s5,0x0($s0)
/*  f0df70c:	920f0002 */ 	lbu	$t7,0x2($s0)
/*  f0df710:	24180003 */ 	addiu	$t8,$zero,0x3
/*  f0df714:	51e00004 */ 	beqzl	$t7,.L0f0df728
/*  f0df718:	a2150000 */ 	sb	$s5,0x0($s0)
/*  f0df71c:	10000002 */ 	beqz	$zero,.L0f0df728
/*  f0df720:	a2180000 */ 	sb	$t8,0x0($s0)
/*  f0df724:	a2150000 */ 	sb	$s5,0x0($s0)
.L0f0df728:
/*  f0df728:	8e1901b4 */ 	lw	$t9,0x1b4($s0)
/*  f0df72c:	16990002 */ 	bne	$s4,$t9,.L0f0df738
/*  f0df730:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df734:	a2150000 */ 	sb	$s5,0x0($s0)
.L0f0df738:
/*  f0df738:	100000aa */ 	beqz	$zero,.L0f0df9e4
/*  f0df73c:	a6000006 */ 	sh	$zero,0x6($s0)
/*  f0df740:	8e0a01b4 */ 	lw	$t2,0x1b4($s0)
/*  f0df744:	568a0005 */ 	bnel	$s4,$t2,.L0f0df75c
/*  f0df748:	960b0006 */ 	lhu	$t3,0x6($s0)
/*  f0df74c:	a2150000 */ 	sb	$s5,0x0($s0)
/*  f0df750:	100000a4 */ 	beqz	$zero,.L0f0df9e4
/*  f0df754:	a6000006 */ 	sh	$zero,0x6($s0)
/*  f0df758:	960b0006 */ 	lhu	$t3,0x6($s0)
.L0f0df75c:
/*  f0df75c:	55600038 */ 	bnezl	$t3,.L0f0df840
/*  f0df760:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0df764:	0fc5b364 */ 	jal	getVar80084014
/*  f0df768:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df76c:	54400034 */ 	bnezl	$v0,.L0f0df840
/*  f0df770:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0df774:	0fc62590 */ 	jal	mpIsPaused
/*  f0df778:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df77c:	54400030 */ 	bnezl	$v0,.L0f0df840
/*  f0df780:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0df784:	8e0201b4 */ 	lw	$v0,0x1b4($s0)
/*  f0df788:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0df78c:	5282002c */ 	beql	$s4,$v0,.L0f0df840
/*  f0df790:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0df794:	5041002a */ 	beql	$v0,$at,.L0f0df840
/*  f0df798:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0df79c:	8e6c006c */ 	lw	$t4,0x6c($s3)
/*  f0df7a0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0df7a4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0df7a8:	11800003 */ 	beqz	$t4,.L0f0df7b8
/*  f0df7ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f0df7b0:	10000001 */ 	beqz	$zero,.L0f0df7b8
/*  f0df7b4:	02402825 */ 	or	$a1,$s2,$zero
.L0f0df7b8:
/*  f0df7b8:	8e6d0068 */ 	lw	$t5,0x68($s3)
/*  f0df7bc:	00001025 */ 	or	$v0,$zero,$zero
/*  f0df7c0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0df7c4:	11a00003 */ 	beqz	$t5,.L0f0df7d4
/*  f0df7c8:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0df7cc:	10000001 */ 	beqz	$zero,.L0f0df7d4
/*  f0df7d0:	02401825 */ 	or	$v1,$s2,$zero
.L0f0df7d4:
/*  f0df7d4:	8e6e0064 */ 	lw	$t6,0x64($s3)
/*  f0df7d8:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0df7dc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0df7e0:	11c00003 */ 	beqz	$t6,.L0f0df7f0
/*  f0df7e4:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0df7e8:	10000001 */ 	beqz	$zero,.L0f0df7f0
/*  f0df7ec:	02402025 */ 	or	$a0,$s2,$zero
.L0f0df7f0:
/*  f0df7f0:	8e6f0070 */ 	lw	$t7,0x70($s3)
/*  f0df7f4:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0df7f8:	11e00003 */ 	beqz	$t7,.L0f0df808
/*  f0df7fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df800:	10000001 */ 	beqz	$zero,.L0f0df808
/*  f0df804:	02401025 */ 	or	$v0,$s2,$zero
.L0f0df808:
/*  f0df808:	0044c021 */ 	addu	$t8,$v0,$a0
/*  f0df80c:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f0df810:	03255021 */ 	addu	$t2,$t9,$a1
/*  f0df814:	164a0009 */ 	bne	$s2,$t2,.L0f0df83c
/*  f0df818:	3c048009 */ 	lui	$a0,%hi(var80095200)
/*  f0df81c:	44812000 */ 	mtc1	$at,$f4
/*  f0df820:	8c845200 */ 	lw	$a0,%lo(var80095200)($a0)
/*  f0df824:	2405003e */ 	addiu	$a1,$zero,0x3e
/*  f0df828:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0df82c:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0df830:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0df834:	0c004241 */ 	jal	func00010904
/*  f0df838:	e7a40014 */ 	swc1	$f4,0x14($sp)
.L0f0df83c:
/*  f0df83c:	9602001c */ 	lhu	$v0,0x1c($s0)
.L0f0df840:
/*  f0df840:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0df844:	00420019 */ 	multu	$v0,$v0
/*  f0df848:	00007012 */ 	mflo	$t6
/*  f0df84c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df850:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df854:	00630019 */ 	multu	$v1,$v1
/*  f0df858:	00007812 */ 	mflo	$t7
/*  f0df85c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0df860:	44983000 */ 	mtc1	$t8,$f6
/*  f0df864:	0c012974 */ 	jal	sqrtf
/*  f0df868:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f0df86c:	3c014304 */ 	lui	$at,0x4304
/*  f0df870:	44814000 */ 	mtc1	$at,$f8
/*  f0df874:	3c0140e0 */ 	lui	$at,0x40e0
/*  f0df878:	44818000 */ 	mtc1	$at,$f16
/*  f0df87c:	46080280 */ 	add.s	$f10,$f0,$f8
/*  f0df880:	96190006 */ 	lhu	$t9,0x6($s0)
/*  f0df884:	8e6a0038 */ 	lw	$t2,0x38($s3)
/*  f0df888:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f0df88c:	032a5821 */ 	addu	$t3,$t9,$t2
/*  f0df890:	316cffff */ 	andi	$t4,$t3,0xffff
/*  f0df894:	a60b0006 */ 	sh	$t3,0x6($s0)
/*  f0df898:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0df89c:	440e2000 */ 	mfc1	$t6,$f4
/*  f0df8a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df8a4:	018e082a */ 	slt	$at,$t4,$t6
/*  f0df8a8:	50200005 */ 	beqzl	$at,.L0f0df8c0
/*  f0df8ac:	a2150000 */ 	sb	$s5,0x0($s0)
/*  f0df8b0:	8e0f01b4 */ 	lw	$t7,0x1b4($s0)
/*  f0df8b4:	168f004b */ 	bne	$s4,$t7,.L0f0df9e4
/*  f0df8b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df8bc:	a2150000 */ 	sb	$s5,0x0($s0)
.L0f0df8c0:
/*  f0df8c0:	10000048 */ 	beqz	$zero,.L0f0df9e4
/*  f0df8c4:	a6000006 */ 	sh	$zero,0x6($s0)
/*  f0df8c8:	96180006 */ 	lhu	$t8,0x6($s0)
/*  f0df8cc:	8e790038 */ 	lw	$t9,0x38($s3)
/*  f0df8d0:	8e0401b0 */ 	lw	$a0,0x1b0($s0)
/*  f0df8d4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0df8d8:	03195021 */ 	addu	$t2,$t8,$t9
/*  f0df8dc:	0480000f */ 	bltz	$a0,.L0f0df91c
/*  f0df8e0:	a60a0006 */ 	sh	$t2,0x6($s0)
/*  f0df8e4:	0fc250ef */ 	jal	audioIfChannelIdle
/*  f0df8e8:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f0df8ec:	10400003 */ 	beqz	$v0,.L0f0df8fc
/*  f0df8f0:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0df8f4:	10000011 */ 	beqz	$zero,.L0f0df93c
/*  f0df8f8:	02401825 */ 	or	$v1,$s2,$zero
.L0f0df8fc:
/*  f0df8fc:	8e0201c4 */ 	lw	$v0,0x1c4($s0)
/*  f0df900:	2401fffd */ 	addiu	$at,$zero,-3
/*  f0df904:	304b0002 */ 	andi	$t3,$v0,0x2
/*  f0df908:	1160000c */ 	beqz	$t3,.L0f0df93c
/*  f0df90c:	00416824 */ 	and	$t5,$v0,$at
/*  f0df910:	ae0d01c4 */ 	sw	$t5,0x1c4($s0)
/*  f0df914:	10000009 */ 	beqz	$zero,.L0f0df93c
/*  f0df918:	02401825 */ 	or	$v1,$s2,$zero
.L0f0df91c:
/*  f0df91c:	8e0201bc */ 	lw	$v0,0x1bc($s0)
/*  f0df920:	960c0006 */ 	lhu	$t4,0x6($s0)
/*  f0df924:	0182082a */ 	slt	$at,$t4,$v0
/*  f0df928:	14200004 */ 	bnez	$at,.L0f0df93c
/*  f0df92c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0df930:	10410002 */ 	beq	$v0,$at,.L0f0df93c
/*  f0df934:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df938:	02401825 */ 	or	$v1,$s2,$zero
.L0f0df93c:
/*  f0df93c:	10600029 */ 	beqz	$v1,.L0f0df9e4
/*  f0df940:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df944:	920e0001 */ 	lbu	$t6,0x1($s0)
/*  f0df948:	240f0005 */ 	addiu	$t7,$zero,0x5
/*  f0df94c:	51c00004 */ 	beqzl	$t6,.L0f0df960
/*  f0df950:	a2000000 */ 	sb	$zero,0x0($s0)
/*  f0df954:	10000002 */ 	beqz	$zero,.L0f0df960
/*  f0df958:	a20f0000 */ 	sb	$t7,0x0($s0)
/*  f0df95c:	a2000000 */ 	sb	$zero,0x0($s0)
.L0f0df960:
/*  f0df960:	10000020 */ 	beqz	$zero,.L0f0df9e4
/*  f0df964:	a6000006 */ 	sh	$zero,0x6($s0)
/*  f0df968:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0df96c:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0df970:	00420019 */ 	multu	$v0,$v0
/*  f0df974:	0000c012 */ 	mflo	$t8
/*  f0df978:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df97c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df980:	00630019 */ 	multu	$v1,$v1
/*  f0df984:	0000c812 */ 	mflo	$t9
/*  f0df988:	03195021 */ 	addu	$t2,$t8,$t9
/*  f0df98c:	448a3000 */ 	mtc1	$t2,$f6
/*  f0df990:	0c012974 */ 	jal	sqrtf
/*  f0df994:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f0df998:	3c0142b8 */ 	lui	$at,0x42b8
/*  f0df99c:	44814000 */ 	mtc1	$at,$f8
/*  f0df9a0:	3c0140e0 */ 	lui	$at,0x40e0
/*  f0df9a4:	44818000 */ 	mtc1	$at,$f16
/*  f0df9a8:	46080280 */ 	add.s	$f10,$f0,$f8
/*  f0df9ac:	960b0006 */ 	lhu	$t3,0x6($s0)
/*  f0df9b0:	8e6d0038 */ 	lw	$t5,0x38($s3)
/*  f0df9b4:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f0df9b8:	016d6021 */ 	addu	$t4,$t3,$t5
/*  f0df9bc:	318effff */ 	andi	$t6,$t4,0xffff
/*  f0df9c0:	a60c0006 */ 	sh	$t4,0x6($s0)
/*  f0df9c4:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0df9c8:	44182000 */ 	mfc1	$t8,$f4
/*  f0df9cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df9d0:	01d8082a */ 	slt	$at,$t6,$t8
/*  f0df9d4:	14200003 */ 	bnez	$at,.L0f0df9e4
/*  f0df9d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0df9dc:	a2000000 */ 	sb	$zero,0x0($s0)
/*  f0df9e0:	a6000006 */ 	sh	$zero,0x6($s0)
.L0f0df9e4:
/*  f0df9e4:	1000feb4 */ 	beqz	$zero,.L0f0df4b8
/*  f0df9e8:	8fa40068 */ 	lw	$a0,0x68($sp)
.L0f0df9ec:
/*  f0df9ec:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0df9f0:	3c018008 */ 	lui	$at,0x8008
/*  f0df9f4:	ac32fac0 */ 	sw	$s2,-0x540($at)
/*  f0df9f8:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f0df9fc:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0dfa00:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f0dfa04:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f0dfa08:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f0dfa0c:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f0dfa10:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f0dfa14:	03e00008 */ 	jr	$ra
/*  f0dfa18:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

void currentPlayerUnsetFlag(u32 flag)
{
	g_Vars.currentplayer->flags &= ~flag;
}

void currentPlayerSetFlag(u32 flag)
{
	g_Vars.currentplayer->flags |= flag;
}

GLOBAL_ASM(
glabel func0f0dfa50
/*  f0dfa50:	3c038007 */ 	lui	$v1,%hi(g_NumHudMessages)
/*  f0dfa54:	8c630fe8 */ 	lw	$v1,%lo(g_NumHudMessages)($v1)
/*  f0dfa58:	00803025 */ 	or	$a2,$a0,$zero
/*  f0dfa5c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0dfa60:	18600019 */ 	blez	$v1,.L0f0dfac8
/*  f0dfa64:	00001025 */ 	or	$v0,$zero,$zero
/*  f0dfa68:	3c078007 */ 	lui	$a3,%hi(g_HudMessages)
/*  f0dfa6c:	24e70fec */ 	addiu	$a3,$a3,%lo(g_HudMessages)
.L0f0dfa70:
/*  f0dfa70:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0dfa74:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0dfa78:	01c42821 */ 	addu	$a1,$t6,$a0
/*  f0dfa7c:	90af0000 */ 	lbu	$t7,0x0($a1)
/*  f0dfa80:	51e0000f */ 	beqzl	$t7,.L0f0dfac0
/*  f0dfa84:	0043082a */ 	slt	$at,$v0,$v1
/*  f0dfa88:	8cb801c0 */ 	lw	$t8,0x1c0($a1)
/*  f0dfa8c:	54d8000c */ 	bnel	$a2,$t8,.L0f0dfac0
/*  f0dfa90:	0043082a */ 	slt	$at,$v0,$v1
/*  f0dfa94:	8cb901c4 */ 	lw	$t9,0x1c4($a1)
/*  f0dfa98:	33280001 */ 	andi	$t0,$t9,0x1
/*  f0dfa9c:	51000008 */ 	beqzl	$t0,.L0f0dfac0
/*  f0dfaa0:	0043082a */ 	slt	$at,$v0,$v1
/*  f0dfaa4:	a0a00000 */ 	sb	$zero,0x0($a1)
/*  f0dfaa8:	8ce90000 */ 	lw	$t1,0x0($a3)
/*  f0dfaac:	3c038007 */ 	lui	$v1,%hi(g_NumHudMessages)
/*  f0dfab0:	01245021 */ 	addu	$t2,$t1,$a0
/*  f0dfab4:	a5400006 */ 	sh	$zero,0x6($t2)
/*  f0dfab8:	8c630fe8 */ 	lw	$v1,%lo(g_NumHudMessages)($v1)
/*  f0dfabc:	0043082a */ 	slt	$at,$v0,$v1
.L0f0dfac0:
/*  f0dfac0:	1420ffeb */ 	bnez	$at,.L0f0dfa70
/*  f0dfac4:	248401dc */ 	addiu	$a0,$a0,0x1dc
.L0f0dfac8:
/*  f0dfac8:	03e00008 */ 	jr	$ra
/*  f0dfacc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f0dfad0
.late_rodata
glabel var7f1adedc
.word 0x40490fdb
glabel var7f1adee0
.word func0f0dfad0+0xa34 # f0e0504
glabel var7f1adee4
.word func0f0dfad0+0xa34 # f0e0504
glabel var7f1adee8
.word func0f0dfad0+0xa34 # f0e0504
glabel var7f1adeec
.word func0f0dfad0+0x3ec # f0dfebc
glabel var7f1adef0
.word func0f0dfad0+0x644 # f0e0114
glabel var7f1adef4
.word func0f0dfad0+0x7c8 # f0e0298
.text
/*  f0dfad0:	27bdff00 */ 	addiu	$sp,$sp,-256
/*  f0dfad4:	3c0f8007 */ 	lui	$t7,%hi(var800706c8)
/*  f0dfad8:	8def06c8 */ 	lw	$t7,%lo(var800706c8)($t7)
/*  f0dfadc:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0dfae0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0dfae4:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f0dfae8:	00809025 */ 	or	$s2,$a0,$zero
/*  f0dfaec:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f0dfaf0:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f0dfaf4:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f0dfaf8:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f0dfafc:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f0dfb00:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f0dfb04:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f0dfb08:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f0dfb0c:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f0dfb10:	f7ba0050 */ 	sdc1	$f26,0x50($sp)
/*  f0dfb14:	f7b80048 */ 	sdc1	$f24,0x48($sp)
/*  f0dfb18:	f7b60040 */ 	sdc1	$f22,0x40($sp)
/*  f0dfb1c:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f0dfb20:	afae00e0 */ 	sw	$t6,0xe0($sp)
/*  f0dfb24:	144f0005 */ 	bne	$v0,$t7,.L0f0dfb3c
/*  f0dfb28:	afa200dc */ 	sw	$v0,0xdc($sp)
/*  f0dfb2c:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f0dfb30:	3c018008 */ 	lui	$at,0x8008
/*  f0dfb34:	10000003 */ 	beqz	$zero,.L0f0dfb44
/*  f0dfb38:	ac38fac0 */ 	sw	$t8,-0x540($at)
.L0f0dfb3c:
/*  f0dfb3c:	3c018008 */ 	lui	$at,0x8008
/*  f0dfb40:	ac22fac0 */ 	sw	$v0,-0x540($at)
.L0f0dfb44:
/*  f0dfb44:	0fc54d8a */ 	jal	func0f153628
/*  f0dfb48:	02402025 */ 	or	$a0,$s2,$zero
/*  f0dfb4c:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x298)
/*  f0dfb50:	8f39a258 */ 	lw	$t9,%lo(g_Vars+0x298)($t9)
/*  f0dfb54:	00409025 */ 	or	$s2,$v0,$zero
/*  f0dfb58:	3c048007 */ 	lui	$a0,%hi(g_NumHudMessages)
/*  f0dfb5c:	07210005 */ 	bgez	$t9,.L0f0dfb74
/*  f0dfb60:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0dfb64:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x29c)
/*  f0dfb68:	8d08a25c */ 	lw	$t0,%lo(g_Vars+0x29c)($t0)
/*  f0dfb6c:	0500000e */ 	bltz	$t0,.L0f0dfba8
/*  f0dfb70:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0dfb74:
/*  f0dfb74:	3c098007 */ 	lui	$t1,%hi(var80070764)
/*  f0dfb78:	8d290764 */ 	lw	$t1,%lo(var80070764)($t1)
/*  f0dfb7c:	1120000a */ 	beqz	$t1,.L0f0dfba8
/*  f0dfb80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfb84:	3c0a8006 */ 	lui	$t2,%hi(var8005d9d0)
/*  f0dfb88:	8d4ad9d0 */ 	lw	$t2,%lo(var8005d9d0)($t2)
/*  f0dfb8c:	15400006 */ 	bnez	$t2,.L0f0dfba8
/*  f0dfb90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfb94:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x28c)
/*  f0dfb98:	8d6ba24c */ 	lw	$t3,%lo(g_Vars+0x28c)($t3)
/*  f0dfb9c:	15600002 */ 	bnez	$t3,.L0f0dfba8
/*  f0dfba0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfba4:	afa000dc */ 	sw	$zero,0xdc($sp)
.L0f0dfba8:
/*  f0dfba8:	8c840fe8 */ 	lw	$a0,%lo(g_NumHudMessages)($a0)
/*  f0dfbac:	27b700e4 */ 	addiu	$s7,$sp,0xe4
/*  f0dfbb0:	27b600e8 */ 	addiu	$s6,$sp,0xe8
/*  f0dfbb4:	1880029b */ 	blez	$a0,.L0f0e0624
/*  f0dfbb8:	2415ff00 */ 	addiu	$s5,$zero,-256
/*  f0dfbbc:	4481d000 */ 	mtc1	$at,$f26
/*  f0dfbc0:	3c0140e0 */ 	lui	$at,0x40e0
/*  f0dfbc4:	4481c000 */ 	mtc1	$at,$f24
/*  f0dfbc8:	3c014080 */ 	lui	$at,0x4080
/*  f0dfbcc:	4481b000 */ 	mtc1	$at,$f22
/*  f0dfbd0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0dfbd4:	4481a000 */ 	mtc1	$at,$f20
/*  f0dfbd8:	afa00088 */ 	sw	$zero,0x88($sp)
/*  f0dfbdc:	241e00ff */ 	addiu	$s8,$zero,0xff
.L0f0dfbe0:
/*  f0dfbe0:	3c0d8007 */ 	lui	$t5,%hi(g_HudMessages)
/*  f0dfbe4:	8dad0fec */ 	lw	$t5,%lo(g_HudMessages)($t5)
/*  f0dfbe8:	8fac0088 */ 	lw	$t4,0x88($sp)
/*  f0dfbec:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0dfbf0:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0dfbf4:	018d8021 */ 	addu	$s0,$t4,$t5
/*  f0dfbf8:	92030004 */ 	lbu	$v1,0x4($s0)
/*  f0dfbfc:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0dfc00:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0dfc04:	54600004 */ 	bnezl	$v1,.L0f0dfc18
/*  f0dfc08:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0dfc0c:	10000280 */ 	beqz	$zero,.L0f0e0610
/*  f0dfc10:	00021080 */ 	sll	$v0,$v0,0x2
/*  f0dfc14:	92020000 */ 	lbu	$v0,0x0($s0)
.L0f0dfc18:
/*  f0dfc18:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0dfc1c:	5040000a */ 	beqzl	$v0,.L0f0dfc48
/*  f0dfc20:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0dfc24:	10410007 */ 	beq	$v0,$at,.L0f0dfc44
/*  f0dfc28:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f0dfc2c:	51c0000c */ 	beqzl	$t6,.L0f0dfc60
/*  f0dfc30:	92190003 */ 	lbu	$t9,0x3($s0)
/*  f0dfc34:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x28c)
/*  f0dfc38:	8defa24c */ 	lw	$t7,%lo(g_Vars+0x28c)($t7)
/*  f0dfc3c:	8e1801c0 */ 	lw	$t8,0x1c0($s0)
/*  f0dfc40:	11f80006 */ 	beq	$t7,$t8,.L0f0dfc5c
.L0f0dfc44:
/*  f0dfc44:	00041100 */ 	sll	$v0,$a0,0x4
.L0f0dfc48:
/*  f0dfc48:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0dfc4c:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0dfc50:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0dfc54:	1000026e */ 	beqz	$zero,.L0f0e0610
/*  f0dfc58:	00021080 */ 	sll	$v0,$v0,0x2
.L0f0dfc5c:
/*  f0dfc5c:	92190003 */ 	lbu	$t9,0x3($s0)
.L0f0dfc60:
/*  f0dfc60:	53200022 */ 	beqzl	$t9,.L0f0dfcec
/*  f0dfc64:	8e130010 */ 	lw	$s3,0x10($s0)
/*  f0dfc68:	96080006 */ 	lhu	$t0,0x6($s0)
/*  f0dfc6c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0dfc70:	44882000 */ 	mtc1	$t0,$f4
/*  f0dfc74:	05010004 */ 	bgez	$t0,.L0f0dfc88
/*  f0dfc78:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0dfc7c:	44814000 */ 	mtc1	$at,$f8
/*  f0dfc80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfc84:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0dfc88:
/*  f0dfc88:	3c017f1b */ 	lui	$at,%hi(var7f1adedc)
/*  f0dfc8c:	c42adedc */ 	lwc1	$f10,%lo(var7f1adedc)($at)
/*  f0dfc90:	3c014270 */ 	lui	$at,0x4270
/*  f0dfc94:	44819000 */ 	mtc1	$at,$f18
/*  f0dfc98:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0dfc9c:	0c0068f7 */ 	jal	sinf
/*  f0dfca0:	46128303 */ 	div.s	$f12,$f16,$f18
/*  f0dfca4:	44802000 */ 	mtc1	$zero,$f4
/*  f0dfca8:	3c014340 */ 	lui	$at,0x4340
/*  f0dfcac:	44814000 */ 	mtc1	$at,$f8
/*  f0dfcb0:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0dfcb4:	46000086 */ 	mov.s	$f2,$f0
/*  f0dfcb8:	45000002 */ 	bc1f	.L0f0dfcc4
/*  f0dfcbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfcc0:	46000087 */ 	neg.s	$f2,$f0
.L0f0dfcc4:
/*  f0dfcc4:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0dfcc8:	8e090010 */ 	lw	$t1,0x10($s0)
/*  f0dfccc:	8e140014 */ 	lw	$s4,0x14($s0)
/*  f0dfcd0:	92030004 */ 	lbu	$v1,0x4($s0)
/*  f0dfcd4:	01355024 */ 	and	$t2,$t1,$s5
/*  f0dfcd8:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f0dfcdc:	440c5000 */ 	mfc1	$t4,$f10
/*  f0dfce0:	10000005 */ 	beqz	$zero,.L0f0dfcf8
/*  f0dfce4:	014c9821 */ 	addu	$s3,$t2,$t4
/*  f0dfce8:	8e130010 */ 	lw	$s3,0x10($s0)
.L0f0dfcec:
/*  f0dfcec:	8e140014 */ 	lw	$s4,0x14($s0)
/*  f0dfcf0:	366d00a0 */ 	ori	$t5,$s3,0xa0
/*  f0dfcf4:	01a09825 */ 	or	$s3,$t5,$zero
.L0f0dfcf8:
/*  f0dfcf8:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0dfcfc:	1061001c */ 	beq	$v1,$at,.L0f0dfd70
/*  f0dfd00:	00601025 */ 	or	$v0,$v1,$zero
/*  f0dfd04:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f0dfd08:	004e0019 */ 	multu	$v0,$t6
/*  f0dfd0c:	00401825 */ 	or	$v1,$v0,$zero
/*  f0dfd10:	329800ff */ 	andi	$t8,$s4,0xff
/*  f0dfd14:	02754024 */ 	and	$t0,$s3,$s5
/*  f0dfd18:	02955824 */ 	and	$t3,$s4,$s5
/*  f0dfd1c:	00007812 */ 	mflo	$t7
/*  f0dfd20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfd24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfd28:	01fe001b */ 	divu	$zero,$t7,$s8
/*  f0dfd2c:	00002012 */ 	mflo	$a0
/*  f0dfd30:	308900ff */ 	andi	$t1,$a0,0xff
/*  f0dfd34:	17c00002 */ 	bnez	$s8,.L0f0dfd40
/*  f0dfd38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfd3c:	0007000d */ 	break	0x7
.L0f0dfd40:
/*  f0dfd40:	00780019 */ 	multu	$v1,$t8
/*  f0dfd44:	01099821 */ 	addu	$s3,$t0,$t1
/*  f0dfd48:	0000c812 */ 	mflo	$t9
/*  f0dfd4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfd50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfd54:	033e001b */ 	divu	$zero,$t9,$s8
/*  f0dfd58:	00002812 */ 	mflo	$a1
/*  f0dfd5c:	30aa00ff */ 	andi	$t2,$a1,0xff
/*  f0dfd60:	17c00002 */ 	bnez	$s8,.L0f0dfd6c
/*  f0dfd64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfd68:	0007000d */ 	break	0x7
.L0f0dfd6c:
/*  f0dfd6c:	016aa021 */ 	addu	$s4,$t3,$t2
.L0f0dfd70:
/*  f0dfd70:	960c0018 */ 	lhu	$t4,0x18($s0)
/*  f0dfd74:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0dfd78:	afac00e8 */ 	sw	$t4,0xe8($sp)
/*  f0dfd7c:	960d001a */ 	lhu	$t5,0x1a($s0)
/*  f0dfd80:	afad00e4 */ 	sw	$t5,0xe4($sp)
/*  f0dfd84:	8e0e01b4 */ 	lw	$t6,0x1b4($s0)
/*  f0dfd88:	55c10011 */ 	bnel	$t6,$at,.L0f0dfdd0
/*  f0dfd8c:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
/*  f0dfd90:	0fc305f3 */ 	jal	currentPlayerGet00fc
/*  f0dfd94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfd98:	5040000d */ 	beqzl	$v0,.L0f0dfdd0
/*  f0dfd9c:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
/*  f0dfda0:	0fc305bd */ 	jal	func0f0c16f4
/*  f0dfda4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfda8:	3c014180 */ 	lui	$at,0x4180
/*  f0dfdac:	44818000 */ 	mtc1	$at,$f16
/*  f0dfdb0:	8faf00e4 */ 	lw	$t7,0xe4($sp)
/*  f0dfdb4:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0dfdb8:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0dfdbc:	44192000 */ 	mfc1	$t9,$f4
/*  f0dfdc0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfdc4:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f0dfdc8:	afa800e4 */ 	sw	$t0,0xe4($sp)
/*  f0dfdcc:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
.L0f0dfdd0:
/*  f0dfdd0:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0dfdd4:	55210031 */ 	bnel	$t1,$at,.L0f0dfe9c
/*  f0dfdd8:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f0dfddc:	8fab00e8 */ 	lw	$t3,0xe8($sp)
/*  f0dfde0:	3c0c8008 */ 	lui	$t4,%hi(var8007fac0)
/*  f0dfde4:	8d8cfac0 */ 	lw	$t4,%lo(var8007fac0)($t4)
/*  f0dfde8:	256afffc */ 	addiu	$t2,$t3,-4
/*  f0dfdec:	3c01ed00 */ 	lui	$at,0xed00
/*  f0dfdf0:	014c0019 */ 	multu	$t2,$t4
/*  f0dfdf4:	02408825 */ 	or	$s1,$s2,$zero
/*  f0dfdf8:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0dfdfc:	00006812 */ 	mflo	$t5
/*  f0dfe00:	448d4000 */ 	mtc1	$t5,$f8
/*  f0dfe04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfe08:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0dfe0c:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f0dfe10:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0dfe14:	44188000 */ 	mfc1	$t8,$f16
/*  f0dfe18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfe1c:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f0dfe20:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f0dfe24:	03214025 */ 	or	$t0,$t9,$at
/*  f0dfe28:	0c002ef5 */ 	jal	func0000bbd4
/*  f0dfe2c:	ae280000 */ 	sw	$t0,0x0($s1)
/*  f0dfe30:	8fa900e8 */ 	lw	$t1,0xe8($sp)
/*  f0dfe34:	960b001c */ 	lhu	$t3,0x1c($s0)
/*  f0dfe38:	3c0d8008 */ 	lui	$t5,%hi(var8007fac0)
/*  f0dfe3c:	8dadfac0 */ 	lw	$t5,%lo(var8007fac0)($t5)
/*  f0dfe40:	012b5021 */ 	addu	$t2,$t1,$t3
/*  f0dfe44:	254c0003 */ 	addiu	$t4,$t2,0x3
/*  f0dfe48:	018d0019 */ 	multu	$t4,$t5
/*  f0dfe4c:	44825000 */ 	mtc1	$v0,$f10
/*  f0dfe50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfe54:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0dfe58:	00007012 */ 	mflo	$t6
/*  f0dfe5c:	448e9000 */ 	mtc1	$t6,$f18
/*  f0dfe60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfe64:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0dfe68:	46162202 */ 	mul.s	$f8,$f4,$f22
/*  f0dfe6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfe70:	46168482 */ 	mul.s	$f18,$f16,$f22
/*  f0dfe74:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f0dfe78:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0dfe7c:	440f3000 */ 	mfc1	$t7,$f6
/*  f0dfe80:	440b2000 */ 	mfc1	$t3,$f4
/*  f0dfe84:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f0dfe88:	00194300 */ 	sll	$t0,$t9,0xc
/*  f0dfe8c:	316a0fff */ 	andi	$t2,$t3,0xfff
/*  f0dfe90:	01486025 */ 	or	$t4,$t2,$t0
/*  f0dfe94:	ae2c0004 */ 	sw	$t4,0x4($s1)
/*  f0dfe98:	920d0000 */ 	lbu	$t5,0x0($s0)
.L0f0dfe9c:
/*  f0dfe9c:	2da10006 */ 	sltiu	$at,$t5,0x6
/*  f0dfea0:	10200198 */ 	beqz	$at,.L0f0e0504
/*  f0dfea4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0dfea8:	3c017f1b */ 	lui	$at,%hi(var7f1adee0)
/*  f0dfeac:	002d0821 */ 	addu	$at,$at,$t5
/*  f0dfeb0:	8c2ddee0 */ 	lw	$t5,%lo(var7f1adee0)($at)
/*  f0dfeb4:	01a00008 */ 	jr	$t5
/*  f0dfeb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfebc:	8e110010 */ 	lw	$s1,0x10($s0)
/*  f0dfec0:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0dfec4:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0dfec8:	362e0040 */ 	ori	$t6,$s1,0x40
/*  f0dfecc:	1041000e */ 	beq	$v0,$at,.L0f0dff08
/*  f0dfed0:	01c08825 */ 	or	$s1,$t6,$zero
/*  f0dfed4:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f0dfed8:	00580019 */ 	multu	$v0,$t8
/*  f0dfedc:	0235c824 */ 	and	$t9,$s1,$s5
/*  f0dfee0:	00007812 */ 	mflo	$t7
/*  f0dfee4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfee8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dfeec:	01fe001b */ 	divu	$zero,$t7,$s8
/*  f0dfef0:	00001812 */ 	mflo	$v1
/*  f0dfef4:	306900ff */ 	andi	$t1,$v1,0xff
/*  f0dfef8:	17c00002 */ 	bnez	$s8,.L0f0dff04
/*  f0dfefc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dff00:	0007000d */ 	break	0x7
.L0f0dff04:
/*  f0dff04:	03298821 */ 	addu	$s1,$t9,$t1
.L0f0dff08:
/*  f0dff08:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0dff0c:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0dff10:	00420019 */ 	multu	$v0,$v0
/*  f0dff14:	00005812 */ 	mflo	$t3
/*  f0dff18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dff1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dff20:	00630019 */ 	multu	$v1,$v1
/*  f0dff24:	00005012 */ 	mflo	$t2
/*  f0dff28:	016a4021 */ 	addu	$t0,$t3,$t2
/*  f0dff2c:	44884000 */ 	mtc1	$t0,$f8
/*  f0dff30:	0c012974 */ 	jal	sqrtf
/*  f0dff34:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f0dff38:	3c014304 */ 	lui	$at,0x4304
/*  f0dff3c:	44813000 */ 	mtc1	$at,$f6
/*  f0dff40:	44802000 */ 	mtc1	$zero,$f4
/*  f0dff44:	3c014f80 */ 	lui	$at,0x4f80
/*  f0dff48:	46060280 */ 	add.s	$f10,$f0,$f6
/*  f0dff4c:	46185083 */ 	div.s	$f2,$f10,$f24
/*  f0dff50:	4602d03c */ 	c.lt.s	$f26,$f2
/*  f0dff54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dff58:	45020003 */ 	bc1fl	.L0f0dff68
/*  f0dff5c:	960c0006 */ 	lhu	$t4,0x6($s0)
/*  f0dff60:	4600d086 */ 	mov.s	$f2,$f26
/*  f0dff64:	960c0006 */ 	lhu	$t4,0x6($s0)
.L0f0dff68:
/*  f0dff68:	448c8000 */ 	mtc1	$t4,$f16
/*  f0dff6c:	05810004 */ 	bgez	$t4,.L0f0dff80
/*  f0dff70:	46808320 */ 	cvt.s.w	$f12,$f16
/*  f0dff74:	44819000 */ 	mtc1	$at,$f18
/*  f0dff78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dff7c:	46126300 */ 	add.s	$f12,$f12,$f18
.L0f0dff80:
/*  f0dff80:	46026083 */ 	div.s	$f2,$f12,$f2
/*  f0dff84:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f0dff88:	8fa500e4 */ 	lw	$a1,0xe4($sp)
/*  f0dff8c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0dff90:	46186002 */ 	mul.s	$f0,$f12,$f24
/*  f0dff94:	44060000 */ 	mfc1	$a2,$f0
/*  f0dff98:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f0dff9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dffa0:	45020003 */ 	bc1fl	.L0f0dffb0
/*  f0dffa4:	4604103c */ 	c.lt.s	$f2,$f4
/*  f0dffa8:	4600a086 */ 	mov.s	$f2,$f20
/*  f0dffac:	4604103c */ 	c.lt.s	$f2,$f4
.L0f0dffb0:
/*  f0dffb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dffb4:	45000003 */ 	bc1f	.L0f0dffc4
/*  f0dffb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dffbc:	44801000 */ 	mtc1	$zero,$f2
/*  f0dffc0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0dffc4:
/*  f0dffc4:	0fc54f08 */ 	jal	func0f153c20
/*  f0dffc8:	e7a200c0 */ 	swc1	$f2,0xc0($sp)
/*  f0dffcc:	920d0001 */ 	lbu	$t5,0x1($s0)
/*  f0dffd0:	c7a200c0 */ 	lwc1	$f2,0xc0($sp)
/*  f0dffd4:	02402025 */ 	or	$a0,$s2,$zero
/*  f0dffd8:	11a00027 */ 	beqz	$t5,.L0f0e0078
/*  f0dffdc:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0dffe0:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0dffe4:	9619001e */ 	lhu	$t9,0x1e($s0)
/*  f0dffe8:	8fae00e8 */ 	lw	$t6,0xe8($sp)
/*  f0dffec:	960f001c */ 	lhu	$t7,0x1c($s0)
/*  f0dfff0:	03384821 */ 	addu	$t1,$t9,$t8
/*  f0dfff4:	252b0002 */ 	addiu	$t3,$t1,0x2
/*  f0dfff8:	01ee3821 */ 	addu	$a3,$t7,$t6
/*  f0dfffc:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f0e0000:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e0004:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f0e0008:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e000c:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0e0010:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e0014:	2706fffd */ 	addiu	$a2,$t8,-3
/*  f0e0018:	0fc37612 */ 	jal	func0f0dd848
/*  f0e001c:	25c5fffd */ 	addiu	$a1,$t6,-3
/*  f0e0020:	0c002f02 */ 	jal	func0000bc08
/*  f0e0024:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e0028:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e002c:	00115403 */ 	sra	$t2,$s1,0x10
/*  f0e0030:	0c002f06 */ 	jal	func0000bc18
/*  f0e0034:	01408825 */ 	or	$s1,$t2,$zero
/*  f0e0038:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0e003c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e0040:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e0044:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e0048:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f0e004c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e0050:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e0054:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e0058:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e005c:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e0060:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0e0064:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e0068:	0fc5580f */ 	jal	func0f15603c
/*  f0e006c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e0070:	1000001f */ 	beqz	$zero,.L0f0e00f0
/*  f0e0074:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e0078:
/*  f0e0078:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f0e007c:	9619001e */ 	lhu	$t9,0x1e($s0)
/*  f0e0080:	960e001c */ 	lhu	$t6,0x1c($s0)
/*  f0e0084:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e0088:	0326c021 */ 	addu	$t8,$t9,$a2
/*  f0e008c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e0090:	0fc54e8d */ 	jal	func0f153a34
/*  f0e0094:	01c53821 */ 	addu	$a3,$t6,$a1
/*  f0e0098:	0c002f02 */ 	jal	func0000bc08
/*  f0e009c:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e00a0:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e00a4:	00114c03 */ 	sra	$t1,$s1,0x10
/*  f0e00a8:	0c002f06 */ 	jal	func0000bc18
/*  f0e00ac:	01208825 */ 	or	$s1,$t1,$zero
/*  f0e00b0:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*  f0e00b4:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e00b8:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e00bc:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e00c0:	8e0a000c */ 	lw	$t2,0xc($s0)
/*  f0e00c4:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0e00c8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e00cc:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0e00d0:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0e00d4:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f0e00d8:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e00dc:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0e00e0:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e00e4:	0fc55b92 */ 	jal	func0f156e48
/*  f0e00e8:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0e00ec:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e00f0:
/*  f0e00f0:	920801c9 */ 	lbu	$t0,0x1c9($s0)
/*  f0e00f4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0e00f8:	15010002 */ 	bne	$t0,$at,.L0f0e0104
/*  f0e00fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e0100:	afa000e0 */ 	sw	$zero,0xe0($sp)
.L0f0e0104:
/*  f0e0104:	0fc54f93 */ 	jal	func0f153e4c
/*  f0e0108:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e010c:	100000fe */ 	beqz	$zero,.L0f0e0508
/*  f0e0110:	8e0801b4 */ 	lw	$t0,0x1b4($s0)
/*  f0e0114:	920c0001 */ 	lbu	$t4,0x1($s0)
/*  f0e0118:	8fa900e8 */ 	lw	$t1,0xe8($sp)
/*  f0e011c:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f0e0120:	11800037 */ 	beqz	$t4,.L0f0e0200
/*  f0e0124:	2525fffd */ 	addiu	$a1,$t1,-3
/*  f0e0128:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0e012c:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0e0130:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0e0134:	346e0040 */ 	ori	$t6,$v1,0x40
/*  f0e0138:	1041000e */ 	beq	$v0,$at,.L0f0e0174
/*  f0e013c:	01c01825 */ 	or	$v1,$t6,$zero
/*  f0e0140:	31cd00ff */ 	andi	$t5,$t6,0xff
/*  f0e0144:	004d0019 */ 	multu	$v0,$t5
/*  f0e0148:	00757824 */ 	and	$t7,$v1,$s5
/*  f0e014c:	0000c812 */ 	mflo	$t9
/*  f0e0150:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e0154:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e0158:	033e001b */ 	divu	$zero,$t9,$s8
/*  f0e015c:	00002012 */ 	mflo	$a0
/*  f0e0160:	309800ff */ 	andi	$t8,$a0,0xff
/*  f0e0164:	17c00002 */ 	bnez	$s8,.L0f0e0170
/*  f0e0168:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e016c:	0007000d */ 	break	0x7
.L0f0e0170:
/*  f0e0170:	01f81821 */ 	addu	$v1,$t7,$t8
.L0f0e0174:
/*  f0e0174:	9608001e */ 	lhu	$t0,0x1e($s0)
/*  f0e0178:	960a001c */ 	lhu	$t2,0x1c($s0)
/*  f0e017c:	e7b4001c */ 	swc1	$f20,0x1c($sp)
/*  f0e0180:	010b6021 */ 	addu	$t4,$t0,$t3
/*  f0e0184:	258e0002 */ 	addiu	$t6,$t4,0x2
/*  f0e0188:	01493821 */ 	addu	$a3,$t2,$t1
/*  f0e018c:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f0e0190:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e0194:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e0198:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0e019c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e01a0:	0fc37612 */ 	jal	func0f0dd848
/*  f0e01a4:	2566fffd */ 	addiu	$a2,$t3,-3
/*  f0e01a8:	0c002f02 */ 	jal	func0000bc08
/*  f0e01ac:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e01b0:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e01b4:	00116c03 */ 	sra	$t5,$s1,0x10
/*  f0e01b8:	0c002f06 */ 	jal	func0000bc18
/*  f0e01bc:	01a08825 */ 	or	$s1,$t5,$zero
/*  f0e01c0:	8e190008 */ 	lw	$t9,0x8($s0)
/*  f0e01c4:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e01c8:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e01cc:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e01d0:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f0e01d4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e01d8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e01dc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e01e0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e01e4:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e01e8:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0e01ec:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e01f0:	0fc5580f */ 	jal	func0f15603c
/*  f0e01f4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e01f8:	10000021 */ 	beqz	$zero,.L0f0e0280
/*  f0e01fc:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e0200:
/*  f0e0200:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f0e0204:	9608001e */ 	lhu	$t0,0x1e($s0)
/*  f0e0208:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0e020c:	9609001c */ 	lhu	$t1,0x1c($s0)
/*  f0e0210:	01065821 */ 	addu	$t3,$t0,$a2
/*  f0e0214:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e0218:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e021c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e0220:	0fc54e8d */ 	jal	func0f153a34
/*  f0e0224:	01253821 */ 	addu	$a3,$t1,$a1
/*  f0e0228:	0c002f02 */ 	jal	func0000bc08
/*  f0e022c:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e0230:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e0234:	00116403 */ 	sra	$t4,$s1,0x10
/*  f0e0238:	0c002f06 */ 	jal	func0000bc18
/*  f0e023c:	01808825 */ 	or	$s1,$t4,$zero
/*  f0e0240:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*  f0e0244:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e0248:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e024c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e0250:	8e0d000c */ 	lw	$t5,0xc($s0)
/*  f0e0254:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0e0258:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e025c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0e0260:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0e0264:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f0e0268:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e026c:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0e0270:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e0274:	0fc55b92 */ 	jal	func0f156e48
/*  f0e0278:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e027c:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e0280:
/*  f0e0280:	921901c9 */ 	lbu	$t9,0x1c9($s0)
/*  f0e0284:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0e0288:	5721009f */ 	bnel	$t9,$at,.L0f0e0508
/*  f0e028c:	8e0801b4 */ 	lw	$t0,0x1b4($s0)
/*  f0e0290:	1000009c */ 	beqz	$zero,.L0f0e0504
/*  f0e0294:	afa000e0 */ 	sw	$zero,0xe0($sp)
/*  f0e0298:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0e029c:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0e02a0:	00420019 */ 	multu	$v0,$v0
/*  f0e02a4:	00007812 */ 	mflo	$t7
/*  f0e02a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e02ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e02b0:	00630019 */ 	multu	$v1,$v1
/*  f0e02b4:	00004812 */ 	mflo	$t1
/*  f0e02b8:	01e9c021 */ 	addu	$t8,$t7,$t1
/*  f0e02bc:	44984000 */ 	mtc1	$t8,$f8
/*  f0e02c0:	0c012974 */ 	jal	sqrtf
/*  f0e02c4:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f0e02c8:	3c0142b8 */ 	lui	$at,0x42b8
/*  f0e02cc:	44813000 */ 	mtc1	$at,$f6
/*  f0e02d0:	8e110010 */ 	lw	$s1,0x10($s0)
/*  f0e02d4:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0e02d8:	46060280 */ 	add.s	$f10,$f0,$f6
/*  f0e02dc:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0e02e0:	36280040 */ 	ori	$t0,$s1,0x40
/*  f0e02e4:	01008825 */ 	or	$s1,$t0,$zero
/*  f0e02e8:	1041000e */ 	beq	$v0,$at,.L0f0e0324
/*  f0e02ec:	46185083 */ 	div.s	$f2,$f10,$f24
/*  f0e02f0:	310a00ff */ 	andi	$t2,$t0,0xff
/*  f0e02f4:	004a0019 */ 	multu	$v0,$t2
/*  f0e02f8:	02356024 */ 	and	$t4,$s1,$s5
/*  f0e02fc:	00005812 */ 	mflo	$t3
/*  f0e0300:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e0304:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e0308:	017e001b */ 	divu	$zero,$t3,$s8
/*  f0e030c:	00001812 */ 	mflo	$v1
/*  f0e0310:	306e00ff */ 	andi	$t6,$v1,0xff
/*  f0e0314:	17c00002 */ 	bnez	$s8,.L0f0e0320
/*  f0e0318:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e031c:	0007000d */ 	break	0x7
.L0f0e0320:
/*  f0e0320:	018e8821 */ 	addu	$s1,$t4,$t6
.L0f0e0324:
/*  f0e0324:	960d0006 */ 	lhu	$t5,0x6($s0)
/*  f0e0328:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e032c:	448d8000 */ 	mtc1	$t5,$f16
/*  f0e0330:	05a10004 */ 	bgez	$t5,.L0f0e0344
/*  f0e0334:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0e0338:	44812000 */ 	mtc1	$at,$f4
/*  f0e033c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e0340:	46049480 */ 	add.s	$f18,$f18,$f4
.L0f0e0344:
/*  f0e0344:	46121201 */ 	sub.s	$f8,$f2,$f18
/*  f0e0348:	9619001c */ 	lhu	$t9,0x1c($s0)
/*  f0e034c:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f0e0350:	9609001e */ 	lhu	$t1,0x1e($s0)
/*  f0e0354:	46184002 */ 	mul.s	$f0,$f8,$f24
/*  f0e0358:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0e035c:	e7a200a8 */ 	swc1	$f2,0xa8($sp)
/*  f0e0360:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f0e0364:	032f2021 */ 	addu	$a0,$t9,$t7
/*  f0e0368:	01382821 */ 	addu	$a1,$t1,$t8
/*  f0e036c:	44060000 */ 	mfc1	$a2,$f0
/*  f0e0370:	0fc54f08 */ 	jal	func0f153c20
/*  f0e0374:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e0378:	c7a200a8 */ 	lwc1	$f2,0xa8($sp)
/*  f0e037c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e0380:	8fab00e8 */ 	lw	$t3,0xe8($sp)
/*  f0e0384:	4602d03c */ 	c.lt.s	$f26,$f2
/*  f0e0388:	8fac00e4 */ 	lw	$t4,0xe4($sp)
/*  f0e038c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e0390:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0e0394:	45000002 */ 	bc1f	.L0f0e03a0
/*  f0e0398:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f0e039c:	4600d086 */ 	mov.s	$f2,$f26
.L0f0e03a0:
/*  f0e03a0:	96080006 */ 	lhu	$t0,0x6($s0)
/*  f0e03a4:	44883000 */ 	mtc1	$t0,$f6
/*  f0e03a8:	05010004 */ 	bgez	$t0,.L0f0e03bc
/*  f0e03ac:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0e03b0:	44818000 */ 	mtc1	$at,$f16
/*  f0e03b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e03b8:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f0e03bc:
/*  f0e03bc:	46025083 */ 	div.s	$f2,$f10,$f2
/*  f0e03c0:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f0e03c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e03c8:	45020003 */ 	bc1fl	.L0f0e03d8
/*  f0e03cc:	920a0001 */ 	lbu	$t2,0x1($s0)
/*  f0e03d0:	4600a086 */ 	mov.s	$f2,$f20
/*  f0e03d4:	920a0001 */ 	lbu	$t2,0x1($s0)
.L0f0e03d8:
/*  f0e03d8:	51400027 */ 	beqzl	$t2,.L0f0e0478
/*  f0e03dc:	960d001e */ 	lhu	$t5,0x1e($s0)
/*  f0e03e0:	960d001e */ 	lhu	$t5,0x1e($s0)
/*  f0e03e4:	960e001c */ 	lhu	$t6,0x1c($s0)
/*  f0e03e8:	4602a101 */ 	sub.s	$f4,$f20,$f2
/*  f0e03ec:	01acc821 */ 	addu	$t9,$t5,$t4
/*  f0e03f0:	272f0002 */ 	addiu	$t7,$t9,0x2
/*  f0e03f4:	01cb3821 */ 	addu	$a3,$t6,$t3
/*  f0e03f8:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f0e03fc:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e0400:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f0e0404:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e0408:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0e040c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e0410:	2565fffd */ 	addiu	$a1,$t3,-3
/*  f0e0414:	0fc37612 */ 	jal	func0f0dd848
/*  f0e0418:	2586fffd */ 	addiu	$a2,$t4,-3
/*  f0e041c:	0c002f02 */ 	jal	func0000bc08
/*  f0e0420:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e0424:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e0428:	00114c03 */ 	sra	$t1,$s1,0x10
/*  f0e042c:	0c002f06 */ 	jal	func0000bc18
/*  f0e0430:	01208825 */ 	or	$s1,$t1,$zero
/*  f0e0434:	8e180008 */ 	lw	$t8,0x8($s0)
/*  f0e0438:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e043c:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e0440:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e0444:	8e08000c */ 	lw	$t0,0xc($s0)
/*  f0e0448:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e044c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e0450:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e0454:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e0458:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e045c:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0e0460:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e0464:	0fc5580f */ 	jal	func0f15603c
/*  f0e0468:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0e046c:	1000001e */ 	beqz	$zero,.L0f0e04e8
/*  f0e0470:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e0474:	960d001e */ 	lhu	$t5,0x1e($s0)
.L0f0e0478:
/*  f0e0478:	960b001c */ 	lhu	$t3,0x1c($s0)
/*  f0e047c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e0480:	01a66021 */ 	addu	$t4,$t5,$a2
/*  f0e0484:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e0488:	0fc54e8d */ 	jal	func0f153a34
/*  f0e048c:	01653821 */ 	addu	$a3,$t3,$a1
/*  f0e0490:	0c002f02 */ 	jal	func0000bc08
/*  f0e0494:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e0498:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e049c:	0011cc03 */ 	sra	$t9,$s1,0x10
/*  f0e04a0:	0c002f06 */ 	jal	func0000bc18
/*  f0e04a4:	03208825 */ 	or	$s1,$t9,$zero
/*  f0e04a8:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*  f0e04ac:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e04b0:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e04b4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e04b8:	8e09000c */ 	lw	$t1,0xc($s0)
/*  f0e04bc:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0e04c0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e04c4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0e04c8:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0e04cc:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f0e04d0:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e04d4:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0e04d8:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e04dc:	0fc55b92 */ 	jal	func0f156e48
/*  f0e04e0:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e04e4:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e04e8:
/*  f0e04e8:	921801c9 */ 	lbu	$t8,0x1c9($s0)
/*  f0e04ec:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0e04f0:	17010002 */ 	bne	$t8,$at,.L0f0e04fc
/*  f0e04f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e04f8:	afa000e0 */ 	sw	$zero,0xe0($sp)
.L0f0e04fc:
/*  f0e04fc:	0fc54f93 */ 	jal	func0f153e4c
/*  f0e0500:	00000000 */ 	sll	$zero,$zero,0x0
.L0f0e0504:
/*  f0e0504:	8e0801b4 */ 	lw	$t0,0x1b4($s0)
.L0f0e0508:
/*  f0e0508:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0e050c:	15010039 */ 	bne	$t0,$at,.L0f0e05f4
/*  f0e0510:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e0514:	afb2009c */ 	sw	$s2,0x9c($sp)
/*  f0e0518:	0c002f40 */ 	jal	func0000bd00
/*  f0e051c:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e0520:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e0524:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f0e0528:	01608025 */ 	or	$s0,$t3,$zero
/*  f0e052c:	0c002f44 */ 	jal	func0000bd10
/*  f0e0530:	8fb3009c */ 	lw	$s3,0x9c($sp)
/*  f0e0534:	44829000 */ 	mtc1	$v0,$f18
/*  f0e0538:	44905000 */ 	mtc1	$s0,$f10
/*  f0e053c:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e0540:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f0e0544:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0e0548:	46164182 */ 	mul.s	$f6,$f8,$f22
/*  f0e054c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e0550:	46162482 */ 	mul.s	$f18,$f4,$f22
/*  f0e0554:	4600340d */ 	trunc.w.s	$f16,$f6
/*  f0e0558:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e055c:	440d8000 */ 	mfc1	$t5,$f16
/*  f0e0560:	440f4000 */ 	mfc1	$t7,$f8
/*  f0e0564:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f0e0568:	01c16025 */ 	or	$t4,$t6,$at
/*  f0e056c:	31e90fff */ 	andi	$t1,$t7,0xfff
/*  f0e0570:	0009c300 */ 	sll	$t8,$t1,0xc
/*  f0e0574:	01984025 */ 	or	$t0,$t4,$t8
/*  f0e0578:	0c002f22 */ 	jal	func0000bc88
/*  f0e057c:	ae680000 */ 	sw	$t0,0x0($s3)
/*  f0e0580:	0c002f40 */ 	jal	func0000bd00
/*  f0e0584:	a7a20092 */ 	sh	$v0,0x92($sp)
/*  f0e0588:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e058c:	00115c03 */ 	sra	$t3,$s1,0x10
/*  f0e0590:	0c002f44 */ 	jal	func0000bd10
/*  f0e0594:	01608825 */ 	or	$s1,$t3,$zero
/*  f0e0598:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e059c:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0e05a0:	0c002f26 */ 	jal	func0000bc98
/*  f0e05a4:	01408025 */ 	or	$s0,$t2,$zero
/*  f0e05a8:	87a90092 */ 	lh	$t1,0x92($sp)
/*  f0e05ac:	00506821 */ 	addu	$t5,$v0,$s0
/*  f0e05b0:	448d3000 */ 	mtc1	$t5,$f6
/*  f0e05b4:	02296021 */ 	addu	$t4,$s1,$t1
/*  f0e05b8:	448c9000 */ 	mtc1	$t4,$f18
/*  f0e05bc:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f0e05c0:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f0e05c4:	46168282 */ 	mul.s	$f10,$f16,$f22
/*  f0e05c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e05cc:	46164182 */ 	mul.s	$f6,$f8,$f22
/*  f0e05d0:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0e05d4:	4600340d */ 	trunc.w.s	$f16,$f6
/*  f0e05d8:	44192000 */ 	mfc1	$t9,$f4
/*  f0e05dc:	44088000 */ 	mfc1	$t0,$f16
/*  f0e05e0:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f0e05e4:	310b0fff */ 	andi	$t3,$t0,0xfff
/*  f0e05e8:	000b5300 */ 	sll	$t2,$t3,0xc
/*  f0e05ec:	01ea6825 */ 	or	$t5,$t7,$t2
/*  f0e05f0:	ae6d0004 */ 	sw	$t5,0x4($s3)
.L0f0e05f4:
/*  f0e05f4:	3c048007 */ 	lui	$a0,%hi(g_NumHudMessages)
/*  f0e05f8:	8c840fe8 */ 	lw	$a0,%lo(g_NumHudMessages)($a0)
/*  f0e05fc:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0e0600:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e0604:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0e0608:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e060c:	00021080 */ 	sll	$v0,$v0,0x2
.L0f0e0610:
/*  f0e0610:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f0e0614:	25d901dc */ 	addiu	$t9,$t6,0x1dc
/*  f0e0618:	0322082a */ 	slt	$at,$t9,$v0
/*  f0e061c:	1420fd70 */ 	bnez	$at,.L0f0dfbe0
/*  f0e0620:	afb90088 */ 	sw	$t9,0x88($sp)
.L0f0e0624:
/*  f0e0624:	8fa900e0 */ 	lw	$t1,0xe0($sp)
/*  f0e0628:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x288)
/*  f0e062c:	11200028 */ 	beqz	$t1,.L0f0e06d0
/*  f0e0630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e0634:	8d8ca248 */ 	lw	$t4,%lo(g_Vars+0x288)($t4)
/*  f0e0638:	0fc54a3a */ 	jal	optionsGetShowMissionTime
/*  f0e063c:	8d840070 */ 	lw	$a0,0x70($t4)
/*  f0e0640:	10400019 */ 	beqz	$v0,.L0f0e06a8
/*  f0e0644:	3c188007 */ 	lui	$t8,%hi(var80075d60)
/*  f0e0648:	8f185d60 */ 	lw	$t8,%lo(var80075d60)($t8)
/*  f0e064c:	24030002 */ 	addiu	$v1,$zero,0x2
/*  f0e0650:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x318)
/*  f0e0654:	14780014 */ 	bne	$v1,$t8,.L0f0e06a8
/*  f0e0658:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e065c:	8d08a2d8 */ 	lw	$t0,%lo(g_Vars+0x318)($t0)
/*  f0e0660:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x4b4)
/*  f0e0664:	15000010 */ 	bnez	$t0,.L0f0e06a8
/*  f0e0668:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e066c:	8d6ba474 */ 	lw	$t3,%lo(g_Vars+0x4b4)($t3)
/*  f0e0670:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0e0674:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f0e0678:	1161000b */ 	beq	$t3,$at,.L0f0e06a8
/*  f0e067c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e0680:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f0e0684:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e0688:	8de20000 */ 	lw	$v0,0x0($t7)
/*  f0e068c:	10620006 */ 	beq	$v1,$v0,.L0f0e06a8
/*  f0e0690:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e0694:	10410004 */ 	beq	$v0,$at,.L0f0e06a8
/*  f0e0698:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e069c:	0fc373bd */ 	jal	func0f0dcef4
/*  f0e06a0:	8fa500e0 */ 	lw	$a1,0xe0($sp)
/*  f0e06a4:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e06a8:
/*  f0e06a8:	0fc3736f */ 	jal	func0f0dcdbc
/*  f0e06ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0e06b0:	10400004 */ 	beqz	$v0,.L0f0e06c4
/*  f0e06b4:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e06b8:	0fc374ab */ 	jal	func0f0dd2ac
/*  f0e06bc:	8fa500e0 */ 	lw	$a1,0xe0($sp)
/*  f0e06c0:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e06c4:
/*  f0e06c4:	0fc2422e */ 	jal	func0f0908b8
/*  f0e06c8:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e06cc:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e06d0:
/*  f0e06d0:	0fc54de0 */ 	jal	func0f153780
/*  f0e06d4:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e06d8:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f0e06dc:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0e06e0:	3c018008 */ 	lui	$at,0x8008
/*  f0e06e4:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f0e06e8:	d7b60040 */ 	ldc1	$f22,0x40($sp)
/*  f0e06ec:	d7b80048 */ 	ldc1	$f24,0x48($sp)
/*  f0e06f0:	d7ba0050 */ 	ldc1	$f26,0x50($sp)
/*  f0e06f4:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f0e06f8:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f0e06fc:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0e0700:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f0e0704:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f0e0708:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f0e070c:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f0e0710:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f0e0714:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f0e0718:	ac2afac0 */ 	sw	$t2,-0x540($at)
/*  f0e071c:	03e00008 */ 	jr	$ra
/*  f0e0720:	27bd0100 */ 	addiu	$sp,$sp,0x100
);

GLOBAL_ASM(
glabel func0f0e0724
/*  f0e0724:	3c048007 */ 	lui	$a0,%hi(g_NumHudMessages)
/*  f0e0728:	24840fe8 */ 	addiu	$a0,$a0,%lo(g_NumHudMessages)
/*  f0e072c:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f0e0730:	00001025 */ 	or	$v0,$zero,$zero
/*  f0e0734:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e0738:	19c0000b */ 	blez	$t6,.L0f0e0768
/*  f0e073c:	3c058007 */ 	lui	$a1,%hi(g_HudMessages)
/*  f0e0740:	24a50fec */ 	addiu	$a1,$a1,%lo(g_HudMessages)
/*  f0e0744:	8caf0000 */ 	lw	$t7,0x0($a1)
.L0f0e0748:
/*  f0e0748:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0e074c:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f0e0750:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f0e0754:	8c990000 */ 	lw	$t9,0x0($a0)
/*  f0e0758:	246301dc */ 	addiu	$v1,$v1,0x1dc
/*  f0e075c:	0059082a */ 	slt	$at,$v0,$t9
/*  f0e0760:	5420fff9 */ 	bnezl	$at,.L0f0e0748
/*  f0e0764:	8caf0000 */ 	lw	$t7,0x0($a1)
.L0f0e0768:
/*  f0e0768:	03e00008 */ 	jr	$ra
/*  f0e076c:	00000000 */ 	sll	$zero,$zero,0x0
);
