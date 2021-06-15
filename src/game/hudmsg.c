#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/game_092610.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b69d0.h"
#include "game/game_0d4690.h"
#include "game/hudmsg.h"
#include "game/game_0e0770.h"
#include "game/game_127910.h"
#include "game/game_1531a0.h"
#include "game/lv.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/lib_09a80.h"
#include "lib/snd.h"
#include "lib/memory.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

const char var7f1ade80[] = "%s%s%4.2fX";
const char var7f1ade8c[] = "";
const char var7f1ade90[] = "";
const char var7f1ade94[] = "/";
const char var7f1ade98[] = "%s%s%4.2fX";
const char var7f1adea4[] = "";
const char var7f1adea8[] = "";

u32 g_NextHudMessageId;

u8 g_HudmsgsActive = 0;

u32 g_Colours[] = {
	/* 0*/ 0x00ff0000, // green
	/* 1*/ 0x9999ff00, // pastel blue
	/* 2*/ 0xffffff00, // white
	/* 3*/ 0xff777700, // pastel red
	/* 4*/ 0xffff5500, // yellow
	/* 5*/ 0x00ff0000, // green
	/* 6*/ 0xcccccc00, // gray
	/* 7*/ 0xff888800, // pastel red
	/* 8*/ 0xffaa5500, // orange
	/* 9*/ 0x55aaff00, // sky blue
	/*10*/ 0xaa55ff00, // purple
};

s32 g_HudPaddingY = 10;
s32 g_HudPaddingX = 24;
s32 g_NumHudMessages = 0;
struct hudmessage *g_HudMessages = NULL;

struct hudmsgtype g_HudmsgTypes[] = {
	/* 0*/ { 1, 1, 0, (void *) &g_FontHandelGothicSm1, (void *) &g_FontHandelGothicSm2, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 80  },
	/* 1*/ { 0, 1, 0, (void *) &g_FontHandelGothicMd1, (void *) &g_FontHandelGothicMd2, 0x00ff0000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_YMIDDLE,       0, 0, 120 },
	/* 2*/ { 0, 0, 1, (void *) &g_FontHandelGothicMd1, (void *) &g_FontHandelGothicMd2, 0xff000000, 0xffffffa0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_YMIDDLE,       0, 0, 120 },
	/* 3*/ { 0, 1, 0, (void *) &g_FontHandelGothicMd1, (void *) &g_FontHandelGothicMd2, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 120 },
	/* 4*/ { 1, 1, 0, (void *) &g_FontHandelGothicSm1, (void *) &g_FontHandelGothicSm2, 0x00ffc000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 40  },
	/* 5*/ { 0, 0, 0, (void *) &g_FontHandelGothicMd1, (void *) &g_FontHandelGothicMd2, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_TOP,           0, 0, 120 },
	/* 6*/ { 1, 0, 0, (void *) &g_FontHandelGothicSm1, (void *) &g_FontHandelGothicSm2, 0x00ff0000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_TOP,           0, 0, 120 },
	/* 7*/ { 1, 1, 0, (void *) &g_FontHandelGothicSm1, (void *) &g_FontHandelGothicSm2, 0x00ff0000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_TOP,           0, 0, -1  },
	/* 8*/ { 1, 1, 0, (void *) &g_FontHandelGothicSm1, (void *) &g_FontHandelGothicSm2, 0x00ffc000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_BOTTOM,        0, 0, 500 },
	/* 9*/ { 1, 1, 0, (void *) &g_FontHandelGothicXs1, (void *) &g_FontHandelGothicXs2, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 120 },
	/*10*/ { 1, 1, 0, (void *) &g_FontHandelGothicSm1, (void *) &g_FontHandelGothicSm2, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 240 },
	/*11*/ { 0, 0, 0, (void *) &g_FontHandelGothicSm1, (void *) &g_FontHandelGothicSm2, 0x00ff0000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_BELOWVIEWPORT, 0, 0, 120 },
};

u32 var80071170 = 0x2e3b213f;
u32 var80071174 = 0x2c000000;
u32 var80071178 = 0x00000000;
u32 var8007117c = 0x00000000;
u32 var80071180 = 0x00000001;
u32 var80071184 = 0x00000000;
u32 var80071188 = 0x00000000;
u32 var8007118c = 0x00000000;

u8 hudmsgsAreActive(void)
{
	return g_HudmsgsActive;
}

s32 hudmsgIsZoomRangeVisible(void)
{
	return optionsGetShowZoomRange(g_Vars.currentplayerstats->mpindex)
		&& (PLAYERCOUNT() == 1
				|| !g_Vars.mplayerisrunning
				|| g_Vars.coopplayernum >= 0
				|| g_Vars.antiplayernum >= 0)
		&& var80075d60 == 2
		&& currentPlayerGetSight() == SIGHT_ZOOM
		&& g_Vars.currentplayer->cameramode != CAMERAMODE_EYESPY
		&& g_Vars.currentplayer->cameramode != CAMERAMODE_THIRDPERSON;
}

GLOBAL_ASM(
glabel hudmsgRenderMissionTimer
/*  f0dcef4:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f0dcef8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0dcefc:	afa40090 */ 	sw	$a0,0x90($sp)
/*  f0dcf00:	0c002f40 */ 	jal	viGetViewLeft
/*  f0dcf04:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f0dcf08:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f0dcf0c:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f0dcf10:	004e001a */ 	div	$zero,$v0,$t6
/*  f0dcf14:	00007812 */ 	mflo	$t7
/*  f0dcf18:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f0dcf1c:	15c00002 */ 	bnez	$t6,.L0f0dcf28
/*  f0dcf20:	00000000 */ 	nop
/*  f0dcf24:	0007000d */ 	break	0x7
.L0f0dcf28:
/*  f0dcf28:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0dcf2c:	15c10004 */ 	bne	$t6,$at,.L0f0dcf40
/*  f0dcf30:	3c018000 */ 	lui	$at,0x8000
/*  f0dcf34:	14410002 */ 	bne	$v0,$at,.L0f0dcf40
/*  f0dcf38:	00000000 */ 	nop
/*  f0dcf3c:	0006000d */ 	break	0x6
.L0f0dcf40:
/*  f0dcf40:	0c002f44 */ 	jal	viGetViewTop
/*  f0dcf44:	00000000 */ 	nop
/*  f0dcf48:	0c002f26 */ 	jal	viGetViewHeight
/*  f0dcf4c:	a7a20056 */ 	sh	$v0,0x56($sp)
/*  f0dcf50:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0dcf54:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0dcf58:	8c98006c */ 	lw	$t8,0x6c($a0)
/*  f0dcf5c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0dcf60:	53000004 */ 	beqzl	$t8,.L0f0dcf74
/*  f0dcf64:	00005025 */ 	or	$t2,$zero,$zero
/*  f0dcf68:	10000002 */ 	b	.L0f0dcf74
/*  f0dcf6c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0dcf70:	00005025 */ 	or	$t2,$zero,$zero
.L0f0dcf74:
/*  f0dcf74:	8c990068 */ 	lw	$t9,0x68($a0)
/*  f0dcf78:	3c188007 */ 	lui	$t8,%hi(g_HudPaddingY)
/*  f0dcf7c:	53200004 */ 	beqzl	$t9,.L0f0dcf90
/*  f0dcf80:	00004025 */ 	or	$t0,$zero,$zero
/*  f0dcf84:	10000002 */ 	b	.L0f0dcf90
/*  f0dcf88:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0dcf8c:	00004025 */ 	or	$t0,$zero,$zero
.L0f0dcf90:
/*  f0dcf90:	8c8b0064 */ 	lw	$t3,0x64($a0)
/*  f0dcf94:	3c198009 */ 	lui	$t9,%hi(g_Is4Mb)
/*  f0dcf98:	51600004 */ 	beqzl	$t3,.L0f0dcfac
/*  f0dcf9c:	00004825 */ 	or	$t1,$zero,$zero
/*  f0dcfa0:	10000002 */ 	b	.L0f0dcfac
/*  f0dcfa4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0dcfa8:	00004825 */ 	or	$t1,$zero,$zero
.L0f0dcfac:
/*  f0dcfac:	8c8c0070 */ 	lw	$t4,0x70($a0)
/*  f0dcfb0:	00003025 */ 	or	$a2,$zero,$zero
/*  f0dcfb4:	11800003 */ 	beqz	$t4,.L0f0dcfc4
/*  f0dcfb8:	00000000 */ 	nop
/*  f0dcfbc:	10000001 */ 	b	.L0f0dcfc4
/*  f0dcfc0:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0dcfc4:
/*  f0dcfc4:	87ae0056 */ 	lh	$t6,0x56($sp)
/*  f0dcfc8:	8f180fe0 */ 	lw	$t8,%lo(g_HudPaddingY)($t8)
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
/*  f0dd02c:	0fc24211 */ 	jal	countdownTimerIsVisible
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
/*  f0dd0bc:	0fc3736f */ 	jal	hudmsgIsZoomRangeVisible
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
/*  f0dd0ec:	00000000 */ 	nop
/*  f0dd0f0:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f0dd0f4:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0dd0f8:	afa70080 */ 	sw	$a3,0x80($sp)
/*  f0dd0fc:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0dd100:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f0dd104:	10a20006 */ 	beq	$a1,$v0,.L0f0dd120
/*  f0dd108:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0dd10c:	8fb90058 */ 	lw	$t9,0x58($sp)
/*  f0dd110:	17200003 */ 	bnez	$t9,.L0f0dd120
/*  f0dd114:	00000000 */ 	nop
.L0f0dd118:
/*  f0dd118:	10000015 */ 	b	.L0f0dd170
/*  f0dd11c:	24e7000a */ 	addiu	$a3,$a3,0xa
.L0f0dd120:
/*  f0dd120:	10000013 */ 	b	.L0f0dd170
/*  f0dd124:	24e70002 */ 	addiu	$a3,$a3,0x2
.L0f0dd128:
/*  f0dd128:	28610003 */ 	slti	$at,$v1,0x3
/*  f0dd12c:	14200008 */ 	bnez	$at,.L0f0dd150
/*  f0dd130:	8fab0058 */ 	lw	$t3,0x58($sp)
/*  f0dd134:	29610002 */ 	slti	$at,$t3,0x2
/*  f0dd138:	10200003 */ 	beqz	$at,.L0f0dd148
/*  f0dd13c:	00000000 */ 	nop
/*  f0dd140:	1000000b */ 	b	.L0f0dd170
/*  f0dd144:	24e7000a */ 	addiu	$a3,$a3,0xa
.L0f0dd148:
/*  f0dd148:	10000009 */ 	b	.L0f0dd170
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
/*  f0dd1b8:	10000009 */ 	b	.L0f0dd1e0
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
/*  f0dd220:	3c198007 */ 	lui	$t9,%hi(g_HudPaddingX)
/*  f0dd224:	8f390fe4 */ 	lw	$t9,%lo(g_HudPaddingX)($t9)
/*  f0dd228:	8fb80084 */ 	lw	$t8,0x84($sp)
/*  f0dd22c:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f0dd230:	03195821 */ 	addu	$t3,$t8,$t9
/*  f0dd234:	256c0003 */ 	addiu	$t4,$t3,0x3
/*  f0dd238:	afac008c */ 	sw	$t4,0x8c($sp)
/*  f0dd23c:	0c002f02 */ 	jal	viGetWidth
/*  f0dd240:	afa70088 */ 	sw	$a3,0x88($sp)
/*  f0dd244:	0c002f06 */ 	jal	viGetHeight
/*  f0dd248:	a7a20042 */ 	sh	$v0,0x42($sp)
/*  f0dd24c:	3c0d8008 */ 	lui	$t5,%hi(g_FontNumeric1)
/*  f0dd250:	3c0e8008 */ 	lui	$t6,%hi(g_FontNumeric2)
/*  f0dd254:	8dcefafc */ 	lw	$t6,%lo(g_FontNumeric2)($t6)
/*  f0dd258:	8dadfb00 */ 	lw	$t5,%lo(g_FontNumeric1)($t5)
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
/*  f0dd294:	0fc55b92 */ 	jal	textRender
/*  f0dd298:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0dd29c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0dd2a0:	27bd0090 */ 	addiu	$sp,$sp,0x90
/*  f0dd2a4:	03e00008 */ 	jr	$ra
/*  f0dd2a8:	00000000 */ 	nop
);

//Gfx *hudmsgRenderMissionTimer(Gfx *gdl, u32 arg1)
//{
//	s32 sp8c;
//	s32 sp88;
//	s32 sp84;
//	s32 sp80;
//	char buffer[24];
//	u32 textcolour;
//	u32 alpha;
//	s32 viewy;
//	s32 playernum;
//	s16 top;
//	s32 playercount;
//
//	sp84 = viGetViewLeft() / g_ScaleX;
//	top = viGetViewTop();
//	viewy = viGetViewHeight();
//	playercount = PLAYERCOUNT();
//	playernum = g_Vars.currentplayernum;
//
//	sp80 = (top + viewy) - g_HudPaddingY;
//	sp80 -= 8;
//
//	// fe0
//	if ((IS4MB() || optionsGetScreenSplit() == SCREENSPLIT_VERTICAL)
//			&& countdownTimerIsVisible()) {
//		sp80 -= 8;
//	}
//
//	// 054
//	if ((IS4MB() || optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || playercount >= 3)
//			&& hudmsgIsZoomRangeVisible()) {
//		sp80 -= 8;
//	}
//
//	// 0d8
//	if (playercount == 2) {
//		// 0e4
//		if (IS4MB() || (optionsGetScreenSplit() != SCREENSPLIT_VERTICAL && playernum == 0)) {
//			// 118
//			sp80 += 10;
//		} else {
//			// 120
//			sp80 += 2;
//		}
//	} else /*128*/ if (playercount >= 3) {
//		if (playernum < 2) {
//			sp80 += 10;
//		} else {
//			sp80 += 2;
//		}
//	} else {
//		// 150
//		if (optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
//			sp80 += 8;
//		}
//	}
//
//	// 170
//	// If this is a second player with their viewport on the right side of the
//	// screen, move the timer left a bit as the safe zone doesn't need to be
//	// considered.
//	if (playercount == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB()) && playernum == 1) {
//		sp84 -= 14;
//	} else if (playercount >= 3 && (playernum & 1) == 1) {
//		sp84 -= 14;
//	}
//
//	// 1e0
//	sp8c = sp84 + g_HudPaddingX + 3;
//
//	alpha = (arg1 * 160) / 255;
//	textcolour = alpha | 0x00ff0000;
//
//	// 208
//	formatTime(buffer, getMissionTime(), 4);
//
//	return textRender(gdl, &sp8c, &sp88, buffer, g_FontNumeric1, g_FontNumeric2, textcolour, 0x000000a0, viGetWidth(), viGetHeight(), 0, 0);
//}

#if VERSION >= VERSION_NTSC_FINAL
GLOBAL_ASM(
glabel hudmsgRenderZoomRange
/*  f0dd2ac:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f0dd2b0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0dd2b4:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0dd2b8:	afa400c0 */ 	sw	$a0,0xc0($sp)
/*  f0dd2bc:	0c002f44 */ 	jal	viGetViewTop
/*  f0dd2c0:	afa500c4 */ 	sw	$a1,0xc4($sp)
/*  f0dd2c4:	0c002f40 */ 	jal	viGetViewLeft
/*  f0dd2c8:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f0dd2cc:	3c108008 */ 	lui	$s0,%hi(g_ScaleX)
/*  f0dd2d0:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScaleX)
/*  f0dd2d4:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0dd2d8:	004e001a */ 	div	$zero,$v0,$t6
/*  f0dd2dc:	00007812 */ 	mflo	$t7
/*  f0dd2e0:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f0dd2e4:	15c00002 */ 	bnez	$t6,.L0f0dd2f0
/*  f0dd2e8:	00000000 */ 	nop
/*  f0dd2ec:	0007000d */ 	break	0x7
.L0f0dd2f0:
/*  f0dd2f0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0dd2f4:	15c10004 */ 	bne	$t6,$at,.L0f0dd308
/*  f0dd2f8:	3c018000 */ 	lui	$at,0x8000
/*  f0dd2fc:	14410002 */ 	bne	$v0,$at,.L0f0dd308
/*  f0dd300:	00000000 */ 	nop
/*  f0dd304:	0006000d */ 	break	0x6
.L0f0dd308:
/*  f0dd308:	0c002f22 */ 	jal	viGetViewWidth
/*  f0dd30c:	00000000 */ 	nop
/*  f0dd310:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0dd314:	0058001a */ 	div	$zero,$v0,$t8
/*  f0dd318:	0000c812 */ 	mflo	$t9
/*  f0dd31c:	00194843 */ 	sra	$t1,$t9,0x1
/*  f0dd320:	17000002 */ 	bnez	$t8,.L0f0dd32c
/*  f0dd324:	00000000 */ 	nop
/*  f0dd328:	0007000d */ 	break	0x7
.L0f0dd32c:
/*  f0dd32c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0dd330:	17010004 */ 	bne	$t8,$at,.L0f0dd344
/*  f0dd334:	3c018000 */ 	lui	$at,0x8000
/*  f0dd338:	14410002 */ 	bne	$v0,$at,.L0f0dd344
/*  f0dd33c:	00000000 */ 	nop
/*  f0dd340:	0006000d */ 	break	0x6
.L0f0dd344:
/*  f0dd344:	afa900b4 */ 	sw	$t1,0xb4($sp)
/*  f0dd348:	0c002f26 */ 	jal	viGetViewHeight
/*  f0dd34c:	00000000 */ 	nop
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
/*  f0dd384:	10000002 */ 	b	.L0f0dd390
/*  f0dd388:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0dd38c:
/*  f0dd38c:	00003825 */ 	or	$a3,$zero,$zero
.L0f0dd390:
/*  f0dd390:	8cce0068 */ 	lw	$t6,0x68($a2)
/*  f0dd394:	00002825 */ 	or	$a1,$zero,$zero
/*  f0dd398:	00001825 */ 	or	$v1,$zero,$zero
/*  f0dd39c:	11c00003 */ 	beqz	$t6,.L0f0dd3ac
/*  f0dd3a0:	2610ffef */ 	addiu	$s0,$s0,-17
/*  f0dd3a4:	10000001 */ 	b	.L0f0dd3ac
/*  f0dd3a8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0dd3ac:
/*  f0dd3ac:	8ccf0064 */ 	lw	$t7,0x64($a2)
/*  f0dd3b0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0dd3b4:	11e00003 */ 	beqz	$t7,.L0f0dd3c4
/*  f0dd3b8:	00000000 */ 	nop
/*  f0dd3bc:	10000001 */ 	b	.L0f0dd3c4
/*  f0dd3c0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0dd3c4:
/*  f0dd3c4:	8cd80070 */ 	lw	$t8,0x70($a2)
/*  f0dd3c8:	13000003 */ 	beqz	$t8,.L0f0dd3d8
/*  f0dd3cc:	00000000 */ 	nop
/*  f0dd3d0:	10000001 */ 	b	.L0f0dd3d8
/*  f0dd3d4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0dd3d8:
/*  f0dd3d8:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f0dd3dc:	afa4005c */ 	sw	$a0,0x5c($sp)
/*  f0dd3e0:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0dd3e4:	0fc24211 */ 	jal	countdownTimerIsVisible
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
/*  f0dd430:	00000000 */ 	nop
/*  f0dd434:	0fc54bcd */ 	jal	optionsGetScreenSplit
/*  f0dd438:	00000000 */ 	nop
/*  f0dd43c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0dd440:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0dd444:	10410006 */ 	beq	$v0,$at,.L0f0dd460
/*  f0dd448:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0dd44c:	8ccb028c */ 	lw	$t3,0x28c($a2)
/*  f0dd450:	15600003 */ 	bnez	$t3,.L0f0dd460
/*  f0dd454:	00000000 */ 	nop
.L0f0dd458:
/*  f0dd458:	10000013 */ 	b	.L0f0dd4a8
/*  f0dd45c:	2610000a */ 	addiu	$s0,$s0,0xa
.L0f0dd460:
/*  f0dd460:	10000011 */ 	b	.L0f0dd4a8
/*  f0dd464:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f0dd468:
/*  f0dd468:	28410003 */ 	slti	$at,$v0,0x3
/*  f0dd46c:	14200009 */ 	bnez	$at,.L0f0dd494
/*  f0dd470:	00000000 */ 	nop
/*  f0dd474:	8ccc028c */ 	lw	$t4,0x28c($a2)
/*  f0dd478:	29810002 */ 	slti	$at,$t4,0x2
/*  f0dd47c:	10200003 */ 	beqz	$at,.L0f0dd48c
/*  f0dd480:	00000000 */ 	nop
/*  f0dd484:	10000008 */ 	b	.L0f0dd4a8
/*  f0dd488:	2610000a */ 	addiu	$s0,$s0,0xa
.L0f0dd48c:
/*  f0dd48c:	10000006 */ 	b	.L0f0dd4a8
/*  f0dd490:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f0dd494:
/*  f0dd494:	0fc54b60 */ 	jal	optionsGetEffectiveScreenSize
/*  f0dd498:	00000000 */ 	nop
/*  f0dd49c:	10400002 */ 	beqz	$v0,.L0f0dd4a8
/*  f0dd4a0:	00000000 */ 	nop
/*  f0dd4a4:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f0dd4a8:
/*  f0dd4a8:	0fc2c536 */ 	jal	currentPlayerGetGunZoomFov
/*  f0dd4ac:	00000000 */ 	nop
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
/*  f0dd4d8:	00000000 */ 	nop
/*  f0dd4dc:	46100032 */ 	c.eq.s	$f0,$f16
/*  f0dd4e0:	00000000 */ 	nop
/*  f0dd4e4:	45000008 */ 	bc1f	.L0f0dd508
.L0f0dd4e8:
/*  f0dd4e8:	24010015 */ 	addiu	$at,$zero,0x15
/*  f0dd4ec:	15c10004 */ 	bne	$t6,$at,.L0f0dd500
/*  f0dd4f0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0dd4f4:	44816000 */ 	mtc1	$at,$f12
/*  f0dd4f8:	1000000d */ 	b	.L0f0dd530
/*  f0dd4fc:	46006221 */ 	cvt.d.s	$f8,$f12
.L0f0dd500:
/*  f0dd500:	100000cc */ 	b	.L0f0dd834
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
/*  f0dd538:	3c077f1b */ 	lui	$a3,%hi(var7f1ade90)
/*  f0dd53c:	24e7de90 */ 	addiu	$a3,$a3,%lo(var7f1ade90)
/*  f0dd540:	24c6de8c */ 	addiu	$a2,$a2,%lo(var7f1ade8c)
/*  f0dd544:	24a5de80 */ 	addiu	$a1,$a1,%lo(var7f1ade80)
/*  f0dd548:	f7a80010 */ 	sdc1	$f8,0x10($sp)
/*  f0dd54c:	0c004dad */ 	jal	sprintf
/*  f0dd550:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0dd554:	3c0f8008 */ 	lui	$t7,%hi(g_FontNumeric2)
/*  f0dd558:	8deffafc */ 	lw	$t7,%lo(g_FontNumeric2)($t7)
/*  f0dd55c:	3c078008 */ 	lui	$a3,%hi(g_FontNumeric1)
/*  f0dd560:	8ce7fb00 */ 	lw	$a3,%lo(g_FontNumeric1)($a3)
/*  f0dd564:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0dd568:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0dd56c:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0dd570:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0dd574:	0fc55cbe */ 	jal	textMeasure
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
/*  f0dd5d0:	0c002f02 */ 	jal	viGetWidth
/*  f0dd5d4:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0dd5d8:	0c002f06 */ 	jal	viGetHeight
/*  f0dd5dc:	a7a2004c */ 	sh	$v0,0x4c($sp)
/*  f0dd5e0:	8fa300c4 */ 	lw	$v1,0xc4($sp)
/*  f0dd5e4:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0dd5e8:	3c0d8008 */ 	lui	$t5,%hi(g_FontNumeric1)
/*  f0dd5ec:	00037880 */ 	sll	$t7,$v1,0x2
/*  f0dd5f0:	01e37821 */ 	addu	$t7,$t7,$v1
/*  f0dd5f4:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f0dd5f8:	01e1001b */ 	divu	$zero,$t7,$at
/*  f0dd5fc:	3c0e8008 */ 	lui	$t6,%hi(g_FontNumeric2)
/*  f0dd600:	8dcefafc */ 	lw	$t6,%lo(g_FontNumeric2)($t6)
/*  f0dd604:	8dadfb00 */ 	lw	$t5,%lo(g_FontNumeric1)($t5)
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
/*  f0dd64c:	0fc55b92 */ 	jal	textRender
/*  f0dd650:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f0dd654:	3c057f1b */ 	lui	$a1,%hi(var7f1ade94)
/*  f0dd658:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0dd65c:	24a5de94 */ 	addiu	$a1,$a1,%lo(var7f1ade94)
/*  f0dd660:	0c004dad */ 	jal	sprintf
/*  f0dd664:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0dd668:	3c0b8008 */ 	lui	$t3,%hi(g_FontNumeric2)
/*  f0dd66c:	8d6bfafc */ 	lw	$t3,%lo(g_FontNumeric2)($t3)
/*  f0dd670:	3c078008 */ 	lui	$a3,%hi(g_FontNumeric1)
/*  f0dd674:	8ce7fb00 */ 	lw	$a3,%lo(g_FontNumeric1)($a3)
/*  f0dd678:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0dd67c:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0dd680:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0dd684:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0dd688:	0fc55cbe */ 	jal	textMeasure
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
/*  f0dd6d8:	0c002f02 */ 	jal	viGetWidth
/*  f0dd6dc:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0dd6e0:	0c002f06 */ 	jal	viGetHeight
/*  f0dd6e4:	a7a2004c */ 	sh	$v0,0x4c($sp)
/*  f0dd6e8:	3c098008 */ 	lui	$t1,%hi(g_FontNumeric1)
/*  f0dd6ec:	3c0a8008 */ 	lui	$t2,%hi(g_FontNumeric2)
/*  f0dd6f0:	8d4afafc */ 	lw	$t2,%lo(g_FontNumeric2)($t2)
/*  f0dd6f4:	8d29fb00 */ 	lw	$t1,%lo(g_FontNumeric1)($t1)
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
/*  f0dd730:	0fc55b92 */ 	jal	textRender
/*  f0dd734:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f0dd738:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f0dd73c:	3c057f1b */ 	lui	$a1,%hi(var7f1ade98)
/*  f0dd740:	3c067f1b */ 	lui	$a2,%hi(var7f1adea4)
/*  f0dd744:	460054a1 */ 	cvt.d.s	$f18,$f10
/*  f0dd748:	3c077f1b */ 	lui	$a3,%hi(var7f1adea8)
/*  f0dd74c:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0dd750:	24e7dea8 */ 	addiu	$a3,$a3,%lo(var7f1adea8)
/*  f0dd754:	f7b20010 */ 	sdc1	$f18,0x10($sp)
/*  f0dd758:	24c6dea4 */ 	addiu	$a2,$a2,%lo(var7f1adea4)
/*  f0dd75c:	24a5de98 */ 	addiu	$a1,$a1,%lo(var7f1ade98)
/*  f0dd760:	0c004dad */ 	jal	sprintf
/*  f0dd764:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0dd768:	3c0e8008 */ 	lui	$t6,%hi(g_FontNumeric2)
/*  f0dd76c:	8dcefafc */ 	lw	$t6,%lo(g_FontNumeric2)($t6)
/*  f0dd770:	3c078008 */ 	lui	$a3,%hi(g_FontNumeric1)
/*  f0dd774:	8ce7fb00 */ 	lw	$a3,%lo(g_FontNumeric1)($a3)
/*  f0dd778:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0dd77c:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0dd780:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0dd784:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0dd788:	0fc55cbe */ 	jal	textMeasure
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
/*  f0dd7d4:	0c002f02 */ 	jal	viGetWidth
/*  f0dd7d8:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0dd7dc:	0c002f06 */ 	jal	viGetHeight
/*  f0dd7e0:	a7a2004c */ 	sh	$v0,0x4c($sp)
/*  f0dd7e4:	3c0a8008 */ 	lui	$t2,%hi(g_FontNumeric1)
/*  f0dd7e8:	3c0b8008 */ 	lui	$t3,%hi(g_FontNumeric2)
/*  f0dd7ec:	8d6bfafc */ 	lw	$t3,%lo(g_FontNumeric2)($t3)
/*  f0dd7f0:	8d4afb00 */ 	lw	$t2,%lo(g_FontNumeric1)($t2)
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
/*  f0dd82c:	0fc55b92 */ 	jal	textRender
/*  f0dd830:	afae0020 */ 	sw	$t6,0x20($sp)
.L0f0dd834:
/*  f0dd834:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0dd838:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0dd83c:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
/*  f0dd840:	03e00008 */ 	jr	$ra
/*  f0dd844:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel hudmsgRenderZoomRange
/*  f0dd28c:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f0dd290:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0dd294:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f0dd298:	afa400c0 */ 	sw	$a0,0xc0($sp)
/*  f0dd29c:	0c002f44 */ 	jal	viGetViewTop
/*  f0dd2a0:	afa500c4 */ 	sw	$a1,0xc4($sp)
/*  f0dd2a4:	0c002f40 */ 	jal	viGetViewLeft
/*  f0dd2a8:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f0dd2ac:	3c108008 */ 	lui	$s0,%hi(g_ScaleX)
/*  f0dd2b0:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScaleX)
/*  f0dd2b4:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0dd2b8:	004e001a */ 	div	$zero,$v0,$t6
/*  f0dd2bc:	00007812 */ 	mflo	$t7
/*  f0dd2c0:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f0dd2c4:	15c00002 */ 	bnez	$t6,.L0f0dd2d0_2
/*  f0dd2c8:	00000000 */ 	nop
/*  f0dd2cc:	0007000d */ 	break	0x7
.L0f0dd2d0_2:
/*  f0dd2d0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0dd2d4:	15c10004 */ 	bne	$t6,$at,.L0f0dd2e8_2
/*  f0dd2d8:	3c018000 */ 	lui	$at,0x8000
/*  f0dd2dc:	14410002 */ 	bne	$v0,$at,.L0f0dd2e8_2
/*  f0dd2e0:	00000000 */ 	nop
/*  f0dd2e4:	0006000d */ 	break	0x6
.L0f0dd2e8_2:
/*  f0dd2e8:	0c002f22 */ 	jal	viGetViewWidth
/*  f0dd2ec:	00000000 */ 	nop
/*  f0dd2f0:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0dd2f4:	0058001a */ 	div	$zero,$v0,$t8
/*  f0dd2f8:	0000c812 */ 	mflo	$t9
/*  f0dd2fc:	00194843 */ 	sra	$t1,$t9,0x1
/*  f0dd300:	17000002 */ 	bnez	$t8,.L0f0dd30c_2
/*  f0dd304:	00000000 */ 	nop
/*  f0dd308:	0007000d */ 	break	0x7
.L0f0dd30c_2:
/*  f0dd30c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0dd310:	17010004 */ 	bne	$t8,$at,.L0f0dd324_2
/*  f0dd314:	3c018000 */ 	lui	$at,0x8000
/*  f0dd318:	14410002 */ 	bne	$v0,$at,.L0f0dd324_2
/*  f0dd31c:	00000000 */ 	nop
/*  f0dd320:	0006000d */ 	break	0x6
.L0f0dd324_2:
/*  f0dd324:	afa900b4 */ 	sw	$t1,0xb4($sp)
/*  f0dd328:	0c002f26 */ 	jal	viGetViewHeight
/*  f0dd32c:	00000000 */ 	nop
/*  f0dd330:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0dd334:	3c013f80 */ 	lui	$at,0x3f80
/*  f0dd338:	44812000 */ 	mtc1	$at,$f4
/*  f0dd33c:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0dd340:	8ccb0284 */ 	lw	$t3,0x284($a2)
/*  f0dd344:	8faa00bc */ 	lw	$t2,0xbc($sp)
/*  f0dd348:	8ccd006c */ 	lw	$t5,0x6c($a2)
/*  f0dd34c:	e7a4009c */ 	swc1	$f4,0x9c($sp)
/*  f0dd350:	916c0638 */ 	lbu	$t4,0x638($t3)
/*  f0dd354:	004a8021 */ 	addu	$s0,$v0,$t2
/*  f0dd358:	2610ffff */ 	addiu	$s0,$s0,-1
/*  f0dd35c:	11a00003 */ 	beqz	$t5,.L0f0dd36c_2
/*  f0dd360:	afac0080 */ 	sw	$t4,0x80($sp)
/*  f0dd364:	10000002 */ 	b	.L0f0dd370_2
/*  f0dd368:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f0dd36c_2:
/*  f0dd36c:	00003825 */ 	or	$a3,$zero,$zero
.L0f0dd370_2:
/*  f0dd370:	8cce0068 */ 	lw	$t6,0x68($a2)
/*  f0dd374:	00002825 */ 	or	$a1,$zero,$zero
/*  f0dd378:	00001825 */ 	or	$v1,$zero,$zero
/*  f0dd37c:	11c00003 */ 	beqz	$t6,.L0f0dd38c_2
/*  f0dd380:	2610ffef */ 	addiu	$s0,$s0,-17
/*  f0dd384:	10000001 */ 	b	.L0f0dd38c_2
/*  f0dd388:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0dd38c_2:
/*  f0dd38c:	8ccf0064 */ 	lw	$t7,0x64($a2)
/*  f0dd390:	00002025 */ 	or	$a0,$zero,$zero
/*  f0dd394:	11e00003 */ 	beqz	$t7,.L0f0dd3a4_2
/*  f0dd398:	00000000 */ 	nop
/*  f0dd39c:	10000001 */ 	b	.L0f0dd3a4_2
/*  f0dd3a0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0dd3a4_2:
/*  f0dd3a4:	8cd80070 */ 	lw	$t8,0x70($a2)
/*  f0dd3a8:	13000003 */ 	beqz	$t8,.L0f0dd3b8_2
/*  f0dd3ac:	00000000 */ 	nop
/*  f0dd3b0:	10000001 */ 	b	.L0f0dd3b8_2
/*  f0dd3b4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0dd3b8_2:
/*  f0dd3b8:	afa30058 */ 	sw	$v1,0x58($sp)
/*  f0dd3bc:	afa4005c */ 	sw	$a0,0x5c($sp)
/*  f0dd3c0:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0dd3c4:	0fc24211 */ 	jal	countdownTimerIsVisible
/*  f0dd3c8:	afa70050 */ 	sw	$a3,0x50($sp)
/*  f0dd3cc:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0dd3d0:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0dd3d4:	8fa30058 */ 	lw	$v1,0x58($sp)
/*  f0dd3d8:	8fa4005c */ 	lw	$a0,0x5c($sp)
/*  f0dd3dc:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0dd3e0:	10400002 */ 	beqz	$v0,.L0f0dd3ec_2
/*  f0dd3e4:	8fa70050 */ 	lw	$a3,0x50($sp)
/*  f0dd3e8:	2610fff8 */ 	addiu	$s0,$s0,-8
.L0f0dd3ec_2:
/*  f0dd3ec:	0083c821 */ 	addu	$t9,$a0,$v1
/*  f0dd3f0:	03254821 */ 	addu	$t1,$t9,$a1
/*  f0dd3f4:	01271021 */ 	addu	$v0,$t1,$a3
/*  f0dd3f8:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0dd3fc:	14410012 */ 	bne	$v0,$at,.L0f0dd448_2
/*  f0dd400:	3c0a8009 */ 	lui	$t2,%hi(g_Is4Mb)
/*  f0dd404:	914a0af0 */ 	lbu	$t2,%lo(g_Is4Mb)($t2)
/*  f0dd408:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0dd40c:	1141000a */ 	beq	$t2,$at,.L0f0dd438_2
/*  f0dd410:	00000000 */ 	nop
/*  f0dd414:	0fc54b41 */ 	jal	optionsGetScreenSplit
/*  f0dd418:	00000000 */ 	nop
/*  f0dd41c:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0dd420:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0dd424:	10410006 */ 	beq	$v0,$at,.L0f0dd440_2
/*  f0dd428:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0dd42c:	8ccb028c */ 	lw	$t3,0x28c($a2)
/*  f0dd430:	15600003 */ 	bnez	$t3,.L0f0dd440_2
/*  f0dd434:	00000000 */ 	nop
.L0f0dd438_2:
/*  f0dd438:	10000013 */ 	b	.L0f0dd488_2
/*  f0dd43c:	2610000a */ 	addiu	$s0,$s0,0xa
.L0f0dd440_2:
/*  f0dd440:	10000011 */ 	b	.L0f0dd488_2
/*  f0dd444:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f0dd448_2:
/*  f0dd448:	28410003 */ 	slti	$at,$v0,0x3
/*  f0dd44c:	14200009 */ 	bnez	$at,.L0f0dd474_2
/*  f0dd450:	00000000 */ 	nop
/*  f0dd454:	8ccc028c */ 	lw	$t4,0x28c($a2)
/*  f0dd458:	29810002 */ 	slti	$at,$t4,0x2
/*  f0dd45c:	10200003 */ 	beqz	$at,.L0f0dd46c_2
/*  f0dd460:	00000000 */ 	nop
/*  f0dd464:	10000008 */ 	b	.L0f0dd488_2
/*  f0dd468:	2610000a */ 	addiu	$s0,$s0,0xa
.L0f0dd46c_2:
/*  f0dd46c:	10000006 */ 	b	.L0f0dd488_2
/*  f0dd470:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f0dd474_2:
/*  f0dd474:	0fc54ad4 */ 	jal	optionsGetEffectiveScreenSize
/*  f0dd478:	00000000 */ 	nop
/*  f0dd47c:	10400002 */ 	beqz	$v0,.L0f0dd488_2
/*  f0dd480:	00000000 */ 	nop
/*  f0dd484:	26100008 */ 	addiu	$s0,$s0,0x8
.L0f0dd488_2:
/*  f0dd488:	0fc2c536 */ 	jal	currentPlayerGetGunZoomFov
/*  f0dd48c:	00000000 */ 	nop
/*  f0dd490:	44803000 */ 	mtc1	$zero,$f6
/*  f0dd494:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f0dd498:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f0dd49c:	46060032 */ 	c.eq.s	$f0,$f6
/*  f0dd4a0:	8ccd0284 */ 	lw	$t5,0x284($a2)
/*  f0dd4a4:	3c014270 */ 	lui	$at,0x4270
/*  f0dd4a8:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f0dd4ac:	45010006 */ 	bc1t	.L0f0dd4c8_2
/*  f0dd4b0:	c5ae1848 */ 	lwc1	$f14,0x1848($t5)
/*  f0dd4b4:	44818000 */ 	mtc1	$at,$f16
/*  f0dd4b8:	00000000 */ 	nop
/*  f0dd4bc:	46100032 */ 	c.eq.s	$f0,$f16
/*  f0dd4c0:	00000000 */ 	nop
/*  f0dd4c4:	45000008 */ 	bc1f	.L0f0dd4e8_2
.L0f0dd4c8_2:
/*  f0dd4c8:	24010015 */ 	addiu	$at,$zero,0x15
/*  f0dd4cc:	15c10004 */ 	bne	$t6,$at,.L0f0dd4e0_2
/*  f0dd4d0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0dd4d4:	44816000 */ 	mtc1	$at,$f12
/*  f0dd4d8:	1000000d */ 	b	.L0f0dd510_2
/*  f0dd4dc:	46006221 */ 	cvt.d.s	$f8,$f12
.L0f0dd4e0_2:
/*  f0dd4e0:	100000cc */ 	b	.L0f0dd814_2
/*  f0dd4e4:	8fa200c0 */ 	lw	$v0,0xc0($sp)
.L0f0dd4e8_2:
/*  f0dd4e8:	460e0283 */ 	div.s	$f10,$f0,$f14
/*  f0dd4ec:	3c013f80 */ 	lui	$at,0x3f80
/*  f0dd4f0:	44814000 */ 	mtc1	$at,$f8
/*  f0dd4f4:	44813000 */ 	mtc1	$at,$f6
/*  f0dd4f8:	46008083 */ 	div.s	$f2,$f16,$f0
/*  f0dd4fc:	460a4483 */ 	div.s	$f18,$f8,$f10
/*  f0dd500:	e7a2009c */ 	swc1	$f2,0x9c($sp)
/*  f0dd504:	46121101 */ 	sub.s	$f4,$f2,$f18
/*  f0dd508:	46062300 */ 	add.s	$f12,$f4,$f6
/*  f0dd50c:	46006221 */ 	cvt.d.s	$f8,$f12
.L0f0dd510_2:
/*  f0dd510:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0dd514:	3c067f1b */ 	lui	$a2,0x7f1b
/*  f0dd518:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f0dd51c:	24e7dc50 */ 	addiu	$a3,$a3,-9136
/*  f0dd520:	24c6dc4c */ 	addiu	$a2,$a2,-9140
/*  f0dd524:	24a5dc40 */ 	addiu	$a1,$a1,-9152
/*  f0dd528:	f7a80010 */ 	sdc1	$f8,0x10($sp)
/*  f0dd52c:	0c004dad */ 	jal	sprintf
/*  f0dd530:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0dd534:	3c0f8008 */ 	lui	$t7,%hi(g_FontNumeric2)
/*  f0dd538:	8deffafc */ 	lw	$t7,%lo(g_FontNumeric2)($t7)
/*  f0dd53c:	3c078008 */ 	lui	$a3,%hi(g_FontNumeric1)
/*  f0dd540:	8ce7fb00 */ 	lw	$a3,%lo(g_FontNumeric1)($a3)
/*  f0dd544:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0dd548:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0dd54c:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0dd550:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0dd554:	0fc55c32 */ 	jal	textMeasure
/*  f0dd558:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0dd55c:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*  f0dd560:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*  f0dd564:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0dd568:	8faa006c */ 	lw	$t2,0x6c($sp)
/*  f0dd56c:	03191821 */ 	addu	$v1,$t8,$t9
/*  f0dd570:	00681023 */ 	subu	$v0,$v1,$t0
/*  f0dd574:	2442fffb */ 	addiu	$v0,$v0,-5
/*  f0dd578:	27ac0064 */ 	addiu	$t4,$sp,0x64
/*  f0dd57c:	00484821 */ 	addu	$t1,$v0,$t0
/*  f0dd580:	020a5821 */ 	addu	$t3,$s0,$t2
/*  f0dd584:	afb00074 */ 	sw	$s0,0x74($sp)
/*  f0dd588:	afa90068 */ 	sw	$t1,0x68($sp)
/*  f0dd58c:	afab0064 */ 	sw	$t3,0x64($sp)
/*  f0dd590:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0dd594:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0dd598:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0dd59c:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f0dd5a0:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0dd5a4:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0dd5a8:	0fc54dad */ 	jal	func0f1538e4
/*  f0dd5ac:	27a70068 */ 	addiu	$a3,$sp,0x68
/*  f0dd5b0:	0c002f02 */ 	jal	viGetWidth
/*  f0dd5b4:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0dd5b8:	0c002f06 */ 	jal	viGetHeight
/*  f0dd5bc:	a7a2004c */ 	sh	$v0,0x4c($sp)
/*  f0dd5c0:	8fa300c4 */ 	lw	$v1,0xc4($sp)
/*  f0dd5c4:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0dd5c8:	3c0d8008 */ 	lui	$t5,%hi(g_FontNumeric1)
/*  f0dd5cc:	00037880 */ 	sll	$t7,$v1,0x2
/*  f0dd5d0:	01e37821 */ 	addu	$t7,$t7,$v1
/*  f0dd5d4:	000f7940 */ 	sll	$t7,$t7,0x5
/*  f0dd5d8:	01e1001b */ 	divu	$zero,$t7,$at
/*  f0dd5dc:	3c0e8008 */ 	lui	$t6,%hi(g_FontNumeric2)
/*  f0dd5e0:	8dcefafc */ 	lw	$t6,%lo(g_FontNumeric2)($t6)
/*  f0dd5e4:	8dadfb00 */ 	lw	$t5,%lo(g_FontNumeric1)($t5)
/*  f0dd5e8:	87aa004c */ 	lh	$t2,0x4c($sp)
/*  f0dd5ec:	0000c012 */ 	mflo	$t8
/*  f0dd5f0:	3c0100ff */ 	lui	$at,0xff
/*  f0dd5f4:	03011825 */ 	or	$v1,$t8,$at
/*  f0dd5f8:	240900a0 */ 	addiu	$t1,$zero,0xa0
/*  f0dd5fc:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0dd600:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0dd604:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f0dd608:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f0dd60c:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0dd610:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0dd614:	27a70084 */ 	addiu	$a3,$sp,0x84
/*  f0dd618:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0dd61c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0dd620:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0dd624:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0dd628:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0dd62c:	0fc55b06 */ 	jal	textRender
/*  f0dd630:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f0dd634:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0dd638:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0dd63c:	24a5dc54 */ 	addiu	$a1,$a1,-9132
/*  f0dd640:	0c004dad */ 	jal	sprintf
/*  f0dd644:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0dd648:	3c0b8008 */ 	lui	$t3,%hi(g_FontNumeric2)
/*  f0dd64c:	8d6bfafc */ 	lw	$t3,%lo(g_FontNumeric2)($t3)
/*  f0dd650:	3c078008 */ 	lui	$a3,%hi(g_FontNumeric1)
/*  f0dd654:	8ce7fb00 */ 	lw	$a3,%lo(g_FontNumeric1)($a3)
/*  f0dd658:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0dd65c:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0dd660:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0dd664:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0dd668:	0fc55c32 */ 	jal	textMeasure
/*  f0dd66c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0dd670:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0dd674:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f0dd678:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f0dd67c:	00086843 */ 	sra	$t5,$t0,0x1
/*  f0dd680:	018d1023 */ 	subu	$v0,$t4,$t5
/*  f0dd684:	27b90064 */ 	addiu	$t9,$sp,0x64
/*  f0dd688:	00487021 */ 	addu	$t6,$v0,$t0
/*  f0dd68c:	020fc021 */ 	addu	$t8,$s0,$t7
/*  f0dd690:	afb00074 */ 	sw	$s0,0x74($sp)
/*  f0dd694:	afae0068 */ 	sw	$t6,0x68($sp)
/*  f0dd698:	afb80064 */ 	sw	$t8,0x64($sp)
/*  f0dd69c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0dd6a0:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0dd6a4:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f0dd6a8:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0dd6ac:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0dd6b0:	0fc54dad */ 	jal	func0f1538e4
/*  f0dd6b4:	27a70068 */ 	addiu	$a3,$sp,0x68
/*  f0dd6b8:	0c002f02 */ 	jal	viGetWidth
/*  f0dd6bc:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0dd6c0:	0c002f06 */ 	jal	viGetHeight
/*  f0dd6c4:	a7a2004c */ 	sh	$v0,0x4c($sp)
/*  f0dd6c8:	3c098008 */ 	lui	$t1,%hi(g_FontNumeric1)
/*  f0dd6cc:	3c0a8008 */ 	lui	$t2,%hi(g_FontNumeric2)
/*  f0dd6d0:	8d4afafc */ 	lw	$t2,%lo(g_FontNumeric2)($t2)
/*  f0dd6d4:	8d29fb00 */ 	lw	$t1,%lo(g_FontNumeric1)($t1)
/*  f0dd6d8:	8fab0048 */ 	lw	$t3,0x48($sp)
/*  f0dd6dc:	87ad004c */ 	lh	$t5,0x4c($sp)
/*  f0dd6e0:	240c00a0 */ 	addiu	$t4,$zero,0xa0
/*  f0dd6e4:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0dd6e8:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f0dd6ec:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0dd6f0:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0dd6f4:	27a70084 */ 	addiu	$a3,$sp,0x84
/*  f0dd6f8:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0dd6fc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0dd700:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0dd704:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0dd708:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0dd70c:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0dd710:	0fc55b06 */ 	jal	textRender
/*  f0dd714:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f0dd718:	c7aa009c */ 	lwc1	$f10,0x9c($sp)
/*  f0dd71c:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0dd720:	3c067f1b */ 	lui	$a2,0x7f1b
/*  f0dd724:	460054a1 */ 	cvt.d.s	$f18,$f10
/*  f0dd728:	3c077f1b */ 	lui	$a3,0x7f1b
/*  f0dd72c:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0dd730:	24e7dc68 */ 	addiu	$a3,$a3,-9112
/*  f0dd734:	f7b20010 */ 	sdc1	$f18,0x10($sp)
/*  f0dd738:	24c6dc64 */ 	addiu	$a2,$a2,-9116
/*  f0dd73c:	24a5dc58 */ 	addiu	$a1,$a1,-9128
/*  f0dd740:	0c004dad */ 	jal	sprintf
/*  f0dd744:	27a40084 */ 	addiu	$a0,$sp,0x84
/*  f0dd748:	3c0e8008 */ 	lui	$t6,%hi(g_FontNumeric2)
/*  f0dd74c:	8dcefafc */ 	lw	$t6,%lo(g_FontNumeric2)($t6)
/*  f0dd750:	3c078008 */ 	lui	$a3,%hi(g_FontNumeric1)
/*  f0dd754:	8ce7fb00 */ 	lw	$a3,%lo(g_FontNumeric1)($a3)
/*  f0dd758:	27a4006c */ 	addiu	$a0,$sp,0x6c
/*  f0dd75c:	27a50070 */ 	addiu	$a1,$sp,0x70
/*  f0dd760:	27a60084 */ 	addiu	$a2,$sp,0x84
/*  f0dd764:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0dd768:	0fc55c32 */ 	jal	textMeasure
/*  f0dd76c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0dd770:	8fa20044 */ 	lw	$v0,0x44($sp)
/*  f0dd774:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f0dd778:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f0dd77c:	24420005 */ 	addiu	$v0,$v0,0x5
/*  f0dd780:	27a90064 */ 	addiu	$t1,$sp,0x64
/*  f0dd784:	00487821 */ 	addu	$t7,$v0,$t0
/*  f0dd788:	0218c821 */ 	addu	$t9,$s0,$t8
/*  f0dd78c:	afb00074 */ 	sw	$s0,0x74($sp)
/*  f0dd790:	afaf0068 */ 	sw	$t7,0x68($sp)
/*  f0dd794:	afb90064 */ 	sw	$t9,0x64($sp)
/*  f0dd798:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0dd79c:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0dd7a0:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f0dd7a4:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0dd7a8:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0dd7ac:	0fc54dad */ 	jal	func0f1538e4
/*  f0dd7b0:	27a70068 */ 	addiu	$a3,$sp,0x68
/*  f0dd7b4:	0c002f02 */ 	jal	viGetWidth
/*  f0dd7b8:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f0dd7bc:	0c002f06 */ 	jal	viGetHeight
/*  f0dd7c0:	a7a2004c */ 	sh	$v0,0x4c($sp)
/*  f0dd7c4:	3c0a8008 */ 	lui	$t2,%hi(g_FontNumeric1)
/*  f0dd7c8:	3c0b8008 */ 	lui	$t3,%hi(g_FontNumeric2)
/*  f0dd7cc:	8d6bfafc */ 	lw	$t3,%lo(g_FontNumeric2)($t3)
/*  f0dd7d0:	8d4afb00 */ 	lw	$t2,%lo(g_FontNumeric1)($t2)
/*  f0dd7d4:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f0dd7d8:	87ae004c */ 	lh	$t6,0x4c($sp)
/*  f0dd7dc:	240d00a0 */ 	addiu	$t5,$zero,0xa0
/*  f0dd7e0:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0dd7e4:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f0dd7e8:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0dd7ec:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0dd7f0:	27a70084 */ 	addiu	$a3,$sp,0x84
/*  f0dd7f4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0dd7f8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0dd7fc:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0dd800:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0dd804:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0dd808:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0dd80c:	0fc55b06 */ 	jal	textRender
/*  f0dd810:	afae0020 */ 	sw	$t6,0x20($sp)
.L0f0dd814_2:
/*  f0dd814:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0dd818:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0dd81c:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
/*  f0dd820:	03e00008 */ 	jr	$ra
/*  f0dd824:	00000000 */ 	nop
);
#endif

Gfx *hudmsgRenderBox(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, f32 bgopacity, u32 bordercolour, f32 textopacity)
{
	f32 f0;
	f32 f20;
	f32 f22;

	if (x1);

	g_HudmsgsActive = true;

	f0 = sinf(90 * bgopacity * M_PI / 180.0f);
	f22 = (x2 - x1) * 0.5f;
	f20 = (y2 - y1) * 0.5f;

	if (f0 < 0.5f) {
		f20 = 0.0f;
		f22 *= f0 + f0;
	} else {
		f20 *= (f0 - 0.5f) + (f0 - 0.5f);
	}

	gdl = func0f0d479c(gdl);

	gdl = renderFilledRect(gdl, x1, y1, x2, y1 + 1, bordercolour, bordercolour);
	gdl = renderFilledRect(gdl, x1, y2, x2, y2 + 1, bordercolour, bordercolour);
	gdl = renderFilledRect(gdl, x1, y1 + 1, x1 + 1, y2, bordercolour, bordercolour);
	gdl = renderFilledRect(gdl, x2, y1, x2 + 1, y2 + 1, bordercolour, bordercolour);

	gdl = func0f0d49c8(gdl);

	if (textopacity > 0.0f) {
		f32 width = (x1 + x2) * 0.5f;
		f32 height = (y1 + y2) * 0.5f;

		gdl = func0f153a34(gdl,
				(s32)((width - f22) + 1.0f) * g_ScaleX,
				(height - f20) + 1.0f,
				(s32)(width + f22) * g_ScaleX,
				height + f20,
				128.0f * textopacity);
	}

	return gdl;
}

s32 func0f0ddb1c(s32 *arg0, s32 arg1)
{
#if VERSION >= VERSION_PAL_FINAL
	s32 viewwidth = viGetViewWidth() / g_ScaleX;
	s32 result = 0;

	*arg0 = 24;

	if (PLAYERCOUNT() == 2
			&& optionsGetScreenSplit() == SCREENSPLIT_VERTICAL
			&& (!g_InCutscene || g_MainIsEndscreen)) {
		result -= *arg0 * 2 / 3;

		if (g_Vars.currentplayernum == 0) {
			*arg0 /= 3;
		} else {
			*arg0 /= 6;
		}
	}

	result = result + viewwidth - *arg0 - arg1 - 11;

	if (PLAYERCOUNT() == 1 || (PLAYERCOUNT() == 2 && g_InCutscene && !g_MainIsEndscreen)) {
		result -= 16;

		if (g_ViMode == VIMODE_HIRES) {
			result -= 16;
		}
	}
#else
	s32 viewwidth = g_Vars.currentplayer->viewwidth / g_ScaleX;
	s32 result = 0;

	*arg0 = 24;

	if (PLAYERCOUNT() == 2 && optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) {
		result -= *arg0 * 2 / 3;

		if (g_Vars.currentplayernum == 0) {
			*arg0 /= 3;
		} else {
			*arg0 /= 6;
		}
	}

	result = result + viewwidth - *arg0 - arg1 - 11;

	if (PLAYERCOUNT() == 1) {
		result -= 16;
	}
#endif

	return result;
}

void hudmsgsHideByChannel(s32 channelnum)
{
	s32 i;

	for (i = 0; i < g_NumHudMessages; i++) {
		if (g_HudMessages[i].state != HUDMSGSTATE_FREE && g_HudMessages[i].channelnum == channelnum) {
			g_HudMessages[i].flags |= HUDMSGFLAG_FORCEOFF;
			break;
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
void hudmsgsInit(void)
{
	s32 i;

	g_NumHudMessages = g_Vars.mplayerisrunning ? 20 : 8;
	g_HudMessages = malloc((sizeof(struct hudmessage) * g_NumHudMessages + 0x3f | 0x3f) ^ 0x3f, MEMPOOL_STAGE);

	for (i = 0; i < g_NumHudMessages; i++) {
		g_HudMessages[i].state = HUDMSGSTATE_FREE;
	}

	g_NextHudMessageId = 0;
}
#else
GLOBAL_ASM(
glabel hudmsgsInit
/*  f0db3b0:	3c0e800a */ 	lui	$t6,0x800a
/*  f0db3b4:	8dcee9d4 */ 	lw	$t6,-0x162c($t6)
/*  f0db3b8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0db3bc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0db3c0:	11c00006 */ 	beqz	$t6,.NB0f0db3dc
/*  f0db3c4:	3c068007 */ 	lui	$a2,0x8007
/*  f0db3c8:	3c068007 */ 	lui	$a2,0x8007
/*  f0db3cc:	24c636a8 */ 	addiu	$a2,$a2,0x36a8
/*  f0db3d0:	240f0014 */ 	addiu	$t7,$zero,0x14
/*  f0db3d4:	10000004 */ 	beqz	$zero,.NB0f0db3e8
/*  f0db3d8:	accf0000 */ 	sw	$t7,0x0($a2)
.NB0f0db3dc:
/*  f0db3dc:	24c636a8 */ 	addiu	$a2,$a2,0x36a8
/*  f0db3e0:	24180008 */ 	addiu	$t8,$zero,0x8
/*  f0db3e4:	acd80000 */ 	sw	$t8,0x0($a2)
.NB0f0db3e8:
/*  f0db3e8:	8cc40000 */ 	lw	$a0,0x0($a2)
/*  f0db3ec:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0db3f0:	0004c900 */ 	sll	$t9,$a0,0x4
/*  f0db3f4:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f0db3f8:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0db3fc:	0324c823 */ 	subu	$t9,$t9,$a0
/*  f0db400:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0db404:	2724003f */ 	addiu	$a0,$t9,0x3f
/*  f0db408:	3488003f */ 	ori	$t0,$a0,0x3f
/*  f0db40c:	0c004a0e */ 	jal	malloc
/*  f0db410:	3904003f */ 	xori	$a0,$t0,0x3f
/*  f0db414:	3c068007 */ 	lui	$a2,0x8007
/*  f0db418:	24c636a8 */ 	addiu	$a2,$a2,0x36a8
/*  f0db41c:	8cca0000 */ 	lw	$t2,0x0($a2)
/*  f0db420:	3c048007 */ 	lui	$a0,0x8007
/*  f0db424:	248436ac */ 	addiu	$a0,$a0,0x36ac
/*  f0db428:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f0db42c:	1940000b */ 	blez	$t2,.NB0f0db45c
/*  f0db430:	00001825 */ 	or	$v1,$zero,$zero
/*  f0db434:	00001025 */ 	or	$v0,$zero,$zero
/*  f0db438:	8c8b0000 */ 	lw	$t3,0x0($a0)
.NB0f0db43c:
/*  f0db43c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0db440:	01626021 */ 	addu	$t4,$t3,$v0
/*  f0db444:	a1800000 */ 	sb	$zero,0x0($t4)
/*  f0db448:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f0db44c:	244201dc */ 	addiu	$v0,$v0,0x1dc
/*  f0db450:	006d082a */ 	slt	$at,$v1,$t5
/*  f0db454:	5420fff9 */ 	bnezl	$at,.NB0f0db43c
/*  f0db458:	8c8b0000 */ 	lw	$t3,0x0($a0)
.NB0f0db45c:
/*  f0db45c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0db460:	3c01800a */ 	lui	$at,0x800a
/*  f0db464:	ac202690 */ 	sw	$zero,0x2690($at)
/*  f0db468:	3c018007 */ 	lui	$at,0x8007
/*  f0db46c:	ac2036b0 */ 	sw	$zero,0x36b0($at)
/*  f0db470:	03e00008 */ 	jr	$ra
/*  f0db474:	27bd0018 */ 	addiu	$sp,$sp,0x18
);
#endif

void hudmsgRemoveAll(void)
{
	s32 i;

	for (i = 0; i < g_NumHudMessages; i++) {
		g_HudMessages[i].state = HUDMSGSTATE_FREE;
	}
}

s32 hudmsgGetNext(s32 refid)
{
	s32 bestid = -1;
	s32 bestindex = -1;
	s32 i;

	// Finding the smallest ID that is greater than refid
	for (i = 0; i < g_NumHudMessages; i++) {
		if (g_HudMessages[i].state && g_HudMessages[i].id > refid) {
			if (bestid < 0 || g_HudMessages[i].id < bestid) {
				bestindex = i;
				bestid = g_HudMessages[i].id;
			}
		}
	}

	return bestindex;
}

void hudmsgCreate(char *text, s32 type)
{
	hudmsgCreateFromArgs(text, type,
			g_HudmsgTypes[type].unk00,
			g_HudmsgTypes[type].unk01,
			g_HudmsgTypes[type].unk02,
			g_HudmsgTypes[type].unk04,
			g_HudmsgTypes[type].unk08,
			g_HudmsgTypes[type].colour,
			g_HudmsgTypes[type].unk10,
			g_HudmsgTypes[type].alignh,
			g_HudmsgTypes[type].unk16,
			g_HudmsgTypes[type].alignv,
			g_HudmsgTypes[type].unk18,
			-1, 0);
}

void hudmsgCreateWithFlags(char *text, s32 type, u32 flags)
{
	hudmsgCreateFromArgs(text, type,
			g_HudmsgTypes[type].unk00,
			g_HudmsgTypes[type].unk01,
			g_HudmsgTypes[type].unk02,
			g_HudmsgTypes[type].unk04,
			g_HudmsgTypes[type].unk08,
			g_HudmsgTypes[type].colour,
			g_HudmsgTypes[type].unk10,
			g_HudmsgTypes[type].alignh,
			g_HudmsgTypes[type].unk16,
			g_HudmsgTypes[type].alignv,
			g_HudmsgTypes[type].unk18,
			-1, flags);
}

void hudmsgCreateWithColour(char *text, s32 type, u8 colournum)
{
	g_HudmsgTypes[type].colour = g_Colours[colournum];

	hudmsgCreateFromArgs(text, type,
			g_HudmsgTypes[type].unk00,
			g_HudmsgTypes[type].unk01,
			g_HudmsgTypes[type].unk02,
			g_HudmsgTypes[type].unk04,
			g_HudmsgTypes[type].unk08,
			g_HudmsgTypes[type].colour,
			g_HudmsgTypes[type].unk10,
			g_HudmsgTypes[type].alignh,
			g_HudmsgTypes[type].unk16,
			g_HudmsgTypes[type].alignv,
			g_HudmsgTypes[type].unk18,
			-1, 0);
}

void hudmsgCreateWithDuration(char *text, s32 type, struct hudmsgtype *config, s32 duration60)
{
	hudmsgCreateFromArgs(text, type,
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
			duration60, HUDMSGFLAG_NOCHANNEL);
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
/*  f0de1c4:	00000000 */ 	nop
/*  f0de1c8:	0fc54a46 */ 	jal	optionsGetCutsceneSubtitles
/*  f0de1cc:	00000000 */ 	nop
/*  f0de1d0:	10400162 */ 	beqz	$v0,.L0f0de75c
/*  f0de1d4:	2418000b */ 	addiu	$t8,$zero,0xb
/*  f0de1d8:	10000005 */ 	b	.L0f0de1f0
/*  f0de1dc:	afb804c4 */ 	sw	$t8,0x4c4($sp)
.L0f0de1e0:
/*  f0de1e0:	0fc54a43 */ 	jal	optionsGetInGameSubtitles
/*  f0de1e4:	00000000 */ 	nop
/*  f0de1e8:	5040015d */ 	beqzl	$v0,.L0f0de760
/*  f0de1ec:	8fbf006c */ 	lw	$ra,0x6c($sp)
.L0f0de1f0:
/*  f0de1f0:	8fb904c4 */ 	lw	$t9,0x4c4($sp)
/*  f0de1f4:	0015c080 */ 	sll	$t8,$s5,0x2
/*  f0de1f8:	3c0f8007 */ 	lui	$t7,%hi(g_HudmsgTypes)
/*  f0de1fc:	00197140 */ 	sll	$t6,$t9,0x5
/*  f0de200:	3c198007 */ 	lui	$t9,%hi(g_Colours)
/*  f0de204:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0de208:	8f390fb4 */ 	lw	$t9,%lo(g_Colours)($t9)
/*  f0de20c:	25ef0ff0 */ 	addiu	$t7,$t7,%lo(g_HudmsgTypes)
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
/*  f0de248:	0c012983 */ 	jal	strlen
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
/*  f0de28c:	00000000 */ 	nop
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
/*  f0de2fc:	10000006 */ 	b	.L0f0de318
/*  f0de300:	27a204b0 */ 	addiu	$v0,$sp,0x4b0
/*  f0de304:	10000003 */ 	b	.L0f0de314
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
/*  f0de324:	00000000 */ 	nop
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
/*  f0de34c:	00000000 */ 	nop
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
/*  f0de3d4:	10000005 */ 	b	.L0f0de3ec
/*  f0de3d8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0de3dc:
/*  f0de3dc:	91d9ffff */ 	lbu	$t9,-0x1($t6)
/*  f0de3e0:	16990002 */ 	bne	$s4,$t9,.L0f0de3ec
/*  f0de3e4:	00000000 */ 	nop
/*  f0de3e8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0de3ec:
/*  f0de3ec:	1564000c */ 	bne	$t3,$a0,.L0f0de420
/*  f0de3f0:	00000000 */ 	nop
/*  f0de3f4:	1200000a */ 	beqz	$s0,.L0f0de420
/*  f0de3f8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0de3fc:	02d08821 */ 	addu	$s1,$s6,$s0
/*  f0de400:	922fffff */ 	lbu	$t7,-0x1($s1)
/*  f0de404:	128f0006 */ 	beq	$s4,$t7,.L0f0de420
/*  f0de408:	00000000 */ 	nop
/*  f0de40c:	92580001 */ 	lbu	$t8,0x1($s2)
/*  f0de410:	12980003 */ 	beq	$s4,$t8,.L0f0de420
/*  f0de414:	00000000 */ 	nop
/*  f0de418:	a22c0000 */ 	sb	$t4,0x0($s1)
/*  f0de41c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0de420:
/*  f0de420:	10a00005 */ 	beqz	$a1,.L0f0de438
/*  f0de424:	00000000 */ 	nop
/*  f0de428:	924e0000 */ 	lbu	$t6,0x0($s2)
/*  f0de42c:	168e0002 */ 	bne	$s4,$t6,.L0f0de438
/*  f0de430:	00000000 */ 	nop
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
/*  f0de498:	00000000 */ 	nop
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
/*  f0de504:	3c0f8008 */ 	lui	$t7,%hi(g_FontHandelGothicSm2)
/*  f0de508:	3c078008 */ 	lui	$a3,%hi(g_FontHandelGothicSm1)
/*  f0de50c:	01d01021 */ 	addu	$v0,$t6,$s0
/*  f0de510:	a0590000 */ 	sb	$t9,0x0($v0)
/*  f0de514:	a0400001 */ 	sb	$zero,0x1($v0)
/*  f0de518:	8deffb0c */ 	lw	$t7,%lo(g_FontHandelGothicSm2)($t7)
/*  f0de51c:	a7ad04ae */ 	sh	$t5,0x4ae($sp)
/*  f0de520:	afa800a4 */ 	sw	$t0,0xa4($sp)
/*  f0de524:	8ce7fb10 */ 	lw	$a3,%lo(g_FontHandelGothicSm1)($a3)
/*  f0de528:	8fa404a4 */ 	lw	$a0,0x4a4($sp)
/*  f0de52c:	27a601b0 */ 	addiu	$a2,$sp,0x1b0
/*  f0de530:	0fc55d48 */ 	jal	textWrap
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
/*  f0de57c:	00000000 */ 	nop
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
/*  f0de5d0:	0fc37835 */ 	jal	hudmsgCreateWithDuration
/*  f0de5d4:	00000000 */ 	nop
/*  f0de5d8:	24090072 */ 	addiu	$t1,$zero,0x72
/*  f0de5dc:	240a0052 */ 	addiu	$t2,$zero,0x52
/*  f0de5e0:	240b000a */ 	addiu	$t3,$zero,0xa
/*  f0de5e4:	240c0020 */ 	addiu	$t4,$zero,0x20
/*  f0de5e8:	97ad04ae */ 	lhu	$t5,0x4ae($sp)
/*  f0de5ec:	241f0044 */ 	addiu	$ra,$zero,0x44
/*  f0de5f0:	10000019 */ 	b	.L0f0de658
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
/*  f0de634:	0fc37835 */ 	jal	hudmsgCreateWithDuration
/*  f0de638:	00000000 */ 	nop
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
/*  f0de6e8:	0fc37835 */ 	jal	hudmsgCreateWithDuration
/*  f0de6ec:	00000000 */ 	nop
/*  f0de6f0:	1000001b */ 	b	.L0f0de760
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
/*  f0de754:	0fc37baf */ 	jal	hudmsgCreateFromArgs
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
);

void hudmsgCreateFromArgsWithoutFlags(char *text, s32 type, s32 conf00, s32 conf01, s32 conf02, struct hudmessagething *conf04, struct hudmessagething *conf08, u32 textcolour, u32 shadowcolour, u32 alignh, s32 conf16, u32 alignv, s32 conf18, s32 arg14)
{
	hudmsgCreateFromArgs(text, type,
			conf00,
			conf01,
			conf02,
			conf04,
			conf08,
			textcolour,
			shadowcolour,
			alignh,
			conf16,
			alignv,
			conf18,
			arg14, 0);
}

#if VERSION >= VERSION_NTSC_1_0
void hudmsgCalculatePosition(struct hudmessage *msg)
{
	s32 x;
	s32 y;
	s32 viewleft = g_Vars.players[msg->playernum]->viewleft / g_ScaleX;
	s32 viewtop = g_Vars.players[msg->playernum]->viewtop;
	s32 viewwidth = g_Vars.players[msg->playernum]->viewwidth / g_ScaleX;
	s32 viewheight = g_Vars.players[msg->playernum]->viewheight;
	s32 v0;
	s32 offset = (msg->alignh == HUDMSGALIGN_XMIDDLE) ? 10 : 0;

#if VERSION >= VERSION_NTSC_1_0
	if (PLAYERCOUNT() >= 3) {
		viewwidth -= offset;

		if (g_Vars.currentplayernum == 0 || g_Vars.currentplayernum == 2) {
			viewleft += offset;
		}
	}

	if (PLAYERCOUNT() == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB())) {
#if VERSION >= VERSION_PAL_FINAL
		if (!g_InCutscene || g_MainIsEndscreen)
#endif
		{
			viewwidth -= offset;

			if (g_Vars.currentplayernum == 0) {
				viewleft += offset;
			}
		}
	}
#endif

	switch (msg->alignh) {
	case HUDMSGALIGN_SCREENLEFT:
		x = msg->xmargin;
		break;
	case HUDMSGALIGN_LEFT:
		v0 = (g_InCutscene && !g_MainIsEndscreen) ? 24 : msg->xmarginextra;

		x = viewleft + v0 + msg->xmargin + 3;

		if (PLAYERCOUNT() == 2
				&& (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB())
				&& (!g_InCutscene || g_MainIsEndscreen)) {
			if (IS4MB()) {
				if (msg->playernum == 0) {
					x--;
				} else if (msg->playernum == 1) {
					x -= 16;
				}
			} else {
				if (msg->playernum == 0) {
					x += 15;
				} else if (msg->playernum == 1) {
					x += 4;
				}
			}
		} else if (PLAYERCOUNT() >= 3) {
			if ((msg->playernum % 2) == 0) {
				x--;
			} else {
				x -= 16;
			}
		}
		break;
	case HUDMSGALIGN_RIGHT:
		x = viewleft + viewwidth - msg->width - msg->xmargin - 57;
		break;
	case HUDMSGALIGN_XMIDDLE:
		x = (viewwidth - msg->width) / 2 + viewleft + msg->xmargin;
		break;
	default:
		x = msg->xmargin;
		break;
	}

	switch (msg->alignv) {
	case HUDMSGALIGN_SCREENTOP:
		y = msg->ymargin;
		break;
	case HUDMSGALIGN_TOP:
		y = viewtop + msg->ymargin + 13;
		break;
	case HUDMSGALIGN_BOTTOM:
		y = viewtop + viewheight - msg->height - msg->ymargin - 14;

		if (PLAYERCOUNT() == 2 && (g_InCutscene == 0 || g_MainIsEndscreen)) {
			if (IS4MB() || (optionsGetScreenSplit() != SCREENSPLIT_VERTICAL && msg->playernum == 0)) {
				y += 8;
			} else {
				y += 3;
			}
		} else if (PLAYERCOUNT() >= 3) {
			if (msg->playernum <= 1) {
				y += 8;
			} else {
				y += 3;
			}
		} else {
			if (optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
				y += 8;
			}
		}
		break;
	case HUDMSGALIGN_YMIDDLE:
		y = (viewheight - msg->height) / 2 + viewtop + msg->ymargin;
		break;
	case HUDMSGALIGN_BELOWVIEWPORT:
		y = viewtop + viewheight - (msg->height / 2) + 18;
		break;
	default:
		y = msg->ymargin;
		break;
	}

	msg->x = x;
	msg->y = y;
}
#else
GLOBAL_ASM(
glabel hudmsgCalculatePosition
.late_rodata
glabel var7f1adeb0
.word hudmsgCalculatePosition+0x33c
glabel var7f1adeb4
.word hudmsgCalculatePosition+0x348
glabel var7f1adeb8
.word hudmsgCalculatePosition+0x35c
glabel var7f1adebc
.word hudmsgCalculatePosition+0x4e4
glabel var7f1adec0
.word hudmsgCalculatePosition+0x514
.text
/*  f0dbe14:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0dbe18:	3c058008 */ 	lui	$a1,0x8008
/*  f0dbe1c:	8ca52320 */ 	lw	$a1,0x2320($a1)
/*  f0dbe20:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0dbe24:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f0dbe28:	8c8f01c0 */ 	lw	$t7,0x1c0($a0)
/*  f0dbe2c:	3c0c800a */ 	lui	$t4,0x800a
/*  f0dbe30:	258ce6c0 */ 	addiu	$t4,$t4,-6464
/*  f0dbe34:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0dbe38:	0198c821 */ 	addu	$t9,$t4,$t8
/*  f0dbe3c:	8f220064 */ 	lw	$v0,0x64($t9)
/*  f0dbe40:	00807025 */ 	or	$t6,$a0,$zero
/*  f0dbe44:	241f0001 */ 	addiu	$ra,$zero,0x1
/*  f0dbe48:	844f0634 */ 	lh	$t7,0x634($v0)
/*  f0dbe4c:	84580630 */ 	lh	$t8,0x630($v0)
/*  f0dbe50:	84590632 */ 	lh	$t9,0x632($v0)
/*  f0dbe54:	01e5001a */ 	div	$zero,$t7,$a1
/*  f0dbe58:	00003012 */ 	mflo	$a2
/*  f0dbe5c:	844d0636 */ 	lh	$t5,0x636($v0)
/*  f0dbe60:	14a00002 */ 	bnez	$a1,.NB0f0dbe6c
/*  f0dbe64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dbe68:	0007000d */ 	break	0x7
.NB0f0dbe6c:
/*  f0dbe6c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0dbe70:	14a10004 */ 	bne	$a1,$at,.NB0f0dbe84
/*  f0dbe74:	3c018000 */ 	lui	$at,0x8000
/*  f0dbe78:	15e10002 */ 	bne	$t7,$at,.NB0f0dbe84
/*  f0dbe7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dbe80:	0006000d */ 	break	0x6
.NB0f0dbe84:
/*  f0dbe84:	0305001a */ 	div	$zero,$t8,$a1
/*  f0dbe88:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0dbe8c:	91c301c8 */ 	lbu	$v1,0x1c8($t6)
/*  f0dbe90:	00003812 */ 	mflo	$a3
/*  f0dbe94:	8faf0030 */ 	lw	$t7,0x30($sp)
/*  f0dbe98:	14a00002 */ 	bnez	$a1,.NB0f0dbea4
/*  f0dbe9c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dbea0:	0007000d */ 	break	0x7
.NB0f0dbea4:
/*  f0dbea4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0dbea8:	14a10004 */ 	bne	$a1,$at,.NB0f0dbebc
/*  f0dbeac:	3c018000 */ 	lui	$at,0x8000
/*  f0dbeb0:	17010002 */ 	bne	$t8,$at,.NB0f0dbebc
/*  f0dbeb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dbeb8:	0006000d */ 	break	0x6
.NB0f0dbebc:
/*  f0dbebc:	1060000c */ 	beqz	$v1,.NB0f0dbef0
/*  f0dbec0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dbec4:	241f0001 */ 	addiu	$ra,$zero,0x1
/*  f0dbec8:	107f000b */ 	beq	$v1,$ra,.NB0f0dbef8
/*  f0dbecc:	3c188007 */ 	lui	$t8,0x8007
/*  f0dbed0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0dbed4:	10610082 */ 	beq	$v1,$at,.NB0f0dc0e0
/*  f0dbed8:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f0dbedc:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0dbee0:	10610086 */ 	beq	$v1,$at,.NB0f0dc0fc
/*  f0dbee4:	8faf0030 */ 	lw	$t7,0x30($sp)
/*  f0dbee8:	1000008d */ 	beqz	$zero,.NB0f0dc120
/*  f0dbeec:	8dc801d0 */ 	lw	$t0,0x1d0($t6)
.NB0f0dbef0:
/*  f0dbef0:	1000008b */ 	beqz	$zero,.NB0f0dc120
/*  f0dbef4:	8de801d0 */ 	lw	$t0,0x1d0($t7)
.NB0f0dbef8:
/*  f0dbef8:	8f182e24 */ 	lw	$t8,0x2e24($t8)
/*  f0dbefc:	3c198006 */ 	lui	$t9,0x8006
/*  f0dbf00:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f0dbf04:	13000006 */ 	beqz	$t8,.NB0f0dbf20
/*  f0dbf08:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0dbf0c:	8f39f2f0 */ 	lw	$t9,-0xd10($t9)
/*  f0dbf10:	57200004 */ 	bnezl	$t9,.NB0f0dbf24
/*  f0dbf14:	8dc201cc */ 	lw	$v0,0x1cc($t6)
/*  f0dbf18:	10000002 */ 	beqz	$zero,.NB0f0dbf24
/*  f0dbf1c:	24020018 */ 	addiu	$v0,$zero,0x18
.NB0f0dbf20:
/*  f0dbf20:	8dc201cc */ 	lw	$v0,0x1cc($t6)
.NB0f0dbf24:
/*  f0dbf24:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f0dbf28:	8d8e006c */ 	lw	$t6,0x6c($t4)
/*  f0dbf2c:	00c27821 */ 	addu	$t7,$a2,$v0
/*  f0dbf30:	8f1901d0 */ 	lw	$t9,0x1d0($t8)
/*  f0dbf34:	00003025 */ 	or	$a2,$zero,$zero
/*  f0dbf38:	00002825 */ 	or	$a1,$zero,$zero
/*  f0dbf3c:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f0dbf40:	11c00003 */ 	beqz	$t6,.NB0f0dbf50
/*  f0dbf44:	25080003 */ 	addiu	$t0,$t0,0x3
/*  f0dbf48:	10000001 */ 	beqz	$zero,.NB0f0dbf50
/*  f0dbf4c:	03e03025 */ 	or	$a2,$ra,$zero
.NB0f0dbf50:
/*  f0dbf50:	8d980068 */ 	lw	$t8,0x68($t4)
/*  f0dbf54:	00001025 */ 	or	$v0,$zero,$zero
/*  f0dbf58:	00001825 */ 	or	$v1,$zero,$zero
/*  f0dbf5c:	13000003 */ 	beqz	$t8,.NB0f0dbf6c
/*  f0dbf60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dbf64:	10000001 */ 	beqz	$zero,.NB0f0dbf6c
/*  f0dbf68:	03e02825 */ 	or	$a1,$ra,$zero
.NB0f0dbf6c:
/*  f0dbf6c:	8d8f0064 */ 	lw	$t7,0x64($t4)
/*  f0dbf70:	11e00003 */ 	beqz	$t7,.NB0f0dbf80
/*  f0dbf74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dbf78:	10000001 */ 	beqz	$zero,.NB0f0dbf80
/*  f0dbf7c:	03e01025 */ 	or	$v0,$ra,$zero
.NB0f0dbf80:
/*  f0dbf80:	8d990070 */ 	lw	$t9,0x70($t4)
/*  f0dbf84:	13200003 */ 	beqz	$t9,.NB0f0dbf94
/*  f0dbf88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dbf8c:	10000001 */ 	beqz	$zero,.NB0f0dbf94
/*  f0dbf90:	03e01825 */ 	or	$v1,$ra,$zero
.NB0f0dbf94:
/*  f0dbf94:	00627021 */ 	addu	$t6,$v1,$v0
/*  f0dbf98:	01c5c021 */ 	addu	$t8,$t6,$a1
/*  f0dbf9c:	03067821 */ 	addu	$t7,$t8,$a2
/*  f0dbfa0:	55e1002e */ 	bnel	$t7,$at,.NB0f0dc05c
/*  f0dbfa4:	8d98006c */ 	lw	$t8,0x6c($t4)
/*  f0dbfa8:	afa8002c */ 	sw	$t0,0x2c($sp)
/*  f0dbfac:	0fc53588 */ 	jal	optionsGetScreenSplit
/*  f0dbfb0:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f0dbfb4:	3c0c800a */ 	lui	$t4,0x800a
/*  f0dbfb8:	241f0001 */ 	addiu	$ra,$zero,0x1
/*  f0dbfbc:	258ce6c0 */ 	addiu	$t4,$t4,-6464
/*  f0dbfc0:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f0dbfc4:	13e20004 */ 	beq	$ra,$v0,.NB0f0dbfd8
/*  f0dbfc8:	8fad0020 */ 	lw	$t5,0x20($sp)
/*  f0dbfcc:	3c198009 */ 	lui	$t9,0x8009
/*  f0dbfd0:	933930e0 */ 	lbu	$t9,0x30e0($t9)
/*  f0dbfd4:	17f90020 */ 	bne	$ra,$t9,.NB0f0dc058
.NB0f0dbfd8:
/*  f0dbfd8:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0dbfdc:	8dce2e24 */ 	lw	$t6,0x2e24($t6)
/*  f0dbfe0:	3c188006 */ 	lui	$t8,0x8006
/*  f0dbfe4:	3c0f8009 */ 	lui	$t7,0x8009
/*  f0dbfe8:	11c00004 */ 	beqz	$t6,.NB0f0dbffc
/*  f0dbfec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dbff0:	8f18f2f0 */ 	lw	$t8,-0xd10($t8)
/*  f0dbff4:	53000019 */ 	beqzl	$t8,.NB0f0dc05c
/*  f0dbff8:	8d98006c */ 	lw	$t8,0x6c($t4)
.NB0f0dbffc:
/*  f0dbffc:	91ef30e0 */ 	lbu	$t7,0x30e0($t7)
/*  f0dc000:	8fb90030 */ 	lw	$t9,0x30($sp)
/*  f0dc004:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f0dc008:	57ef000b */ 	bnel	$ra,$t7,.NB0f0dc038
/*  f0dc00c:	8dc201c0 */ 	lw	$v0,0x1c0($t6)
/*  f0dc010:	8f2201c0 */ 	lw	$v0,0x1c0($t9)
/*  f0dc014:	14400003 */ 	bnez	$v0,.NB0f0dc024
/*  f0dc018:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dc01c:	10000040 */ 	beqz	$zero,.NB0f0dc120
/*  f0dc020:	2508ffff */ 	addiu	$t0,$t0,-1
.NB0f0dc024:
/*  f0dc024:	57e2003f */ 	bnel	$ra,$v0,.NB0f0dc124
/*  f0dc028:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f0dc02c:	1000003c */ 	beqz	$zero,.NB0f0dc120
/*  f0dc030:	2508fff0 */ 	addiu	$t0,$t0,-16
/*  f0dc034:	8dc201c0 */ 	lw	$v0,0x1c0($t6)
.NB0f0dc038:
/*  f0dc038:	14400003 */ 	bnez	$v0,.NB0f0dc048
/*  f0dc03c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dc040:	10000037 */ 	beqz	$zero,.NB0f0dc120
/*  f0dc044:	2508000f */ 	addiu	$t0,$t0,0xf
.NB0f0dc048:
/*  f0dc048:	57e20036 */ 	bnel	$ra,$v0,.NB0f0dc124
/*  f0dc04c:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f0dc050:	10000033 */ 	beqz	$zero,.NB0f0dc120
/*  f0dc054:	25080004 */ 	addiu	$t0,$t0,0x4
.NB0f0dc058:
/*  f0dc058:	8d98006c */ 	lw	$t8,0x6c($t4)
.NB0f0dc05c:
/*  f0dc05c:	8d870068 */ 	lw	$a3,0x68($t4)
/*  f0dc060:	8d890064 */ 	lw	$t1,0x64($t4)
/*  f0dc064:	13000003 */ 	beqz	$t8,.NB0f0dc074
/*  f0dc068:	8d8b0070 */ 	lw	$t3,0x70($t4)
/*  f0dc06c:	10000002 */ 	beqz	$zero,.NB0f0dc078
/*  f0dc070:	03e03025 */ 	or	$a2,$ra,$zero
.NB0f0dc074:
/*  f0dc074:	00003025 */ 	or	$a2,$zero,$zero
.NB0f0dc078:
/*  f0dc078:	10e00003 */ 	beqz	$a3,.NB0f0dc088
/*  f0dc07c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0dc080:	10000001 */ 	beqz	$zero,.NB0f0dc088
/*  f0dc084:	03e02825 */ 	or	$a1,$ra,$zero
.NB0f0dc088:
/*  f0dc088:	11200003 */ 	beqz	$t1,.NB0f0dc098
/*  f0dc08c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0dc090:	10000001 */ 	beqz	$zero,.NB0f0dc098
/*  f0dc094:	03e01025 */ 	or	$v0,$ra,$zero
.NB0f0dc098:
/*  f0dc098:	11600003 */ 	beqz	$t3,.NB0f0dc0a8
/*  f0dc09c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0dc0a0:	10000001 */ 	beqz	$zero,.NB0f0dc0a8
/*  f0dc0a4:	03e01825 */ 	or	$v1,$ra,$zero
.NB0f0dc0a8:
/*  f0dc0a8:	00627821 */ 	addu	$t7,$v1,$v0
/*  f0dc0ac:	01e5c821 */ 	addu	$t9,$t7,$a1
/*  f0dc0b0:	03267021 */ 	addu	$t6,$t9,$a2
/*  f0dc0b4:	29c10003 */ 	slti	$at,$t6,0x3
/*  f0dc0b8:	14200019 */ 	bnez	$at,.NB0f0dc120
/*  f0dc0bc:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f0dc0c0:	8f0f01c0 */ 	lw	$t7,0x1c0($t8)
/*  f0dc0c4:	31f90001 */ 	andi	$t9,$t7,0x1
/*  f0dc0c8:	17200003 */ 	bnez	$t9,.NB0f0dc0d8
/*  f0dc0cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dc0d0:	10000013 */ 	beqz	$zero,.NB0f0dc120
/*  f0dc0d4:	2508ffff */ 	addiu	$t0,$t0,-1
.NB0f0dc0d8:
/*  f0dc0d8:	10000011 */ 	beqz	$zero,.NB0f0dc120
/*  f0dc0dc:	2508fff0 */ 	addiu	$t0,$t0,-16
.NB0f0dc0e0:
/*  f0dc0e0:	970f001c */ 	lhu	$t7,0x1c($t8)
/*  f0dc0e4:	00c77021 */ 	addu	$t6,$a2,$a3
/*  f0dc0e8:	01cfc823 */ 	subu	$t9,$t6,$t7
/*  f0dc0ec:	8f0e01d0 */ 	lw	$t6,0x1d0($t8)
/*  f0dc0f0:	032e4023 */ 	subu	$t0,$t9,$t6
/*  f0dc0f4:	1000000a */ 	beqz	$zero,.NB0f0dc120
/*  f0dc0f8:	2508ffc7 */ 	addiu	$t0,$t0,-57
.NB0f0dc0fc:
/*  f0dc0fc:	95f8001c */ 	lhu	$t8,0x1c($t7)
/*  f0dc100:	00f8c823 */ 	subu	$t9,$a3,$t8
/*  f0dc104:	07210003 */ 	bgez	$t9,.NB0f0dc114
/*  f0dc108:	00197043 */ 	sra	$t6,$t9,0x1
/*  f0dc10c:	27210001 */ 	addiu	$at,$t9,0x1
/*  f0dc110:	00017043 */ 	sra	$t6,$at,0x1
.NB0f0dc114:
/*  f0dc114:	8df901d0 */ 	lw	$t9,0x1d0($t7)
/*  f0dc118:	01c6c021 */ 	addu	$t8,$t6,$a2
/*  f0dc11c:	03194021 */ 	addu	$t0,$t8,$t9
.NB0f0dc120:
/*  f0dc120:	8fae0030 */ 	lw	$t6,0x30($sp)
.NB0f0dc124:
/*  f0dc124:	8fb90030 */ 	lw	$t9,0x30($sp)
/*  f0dc128:	91cf01c9 */ 	lbu	$t7,0x1c9($t6)
/*  f0dc12c:	25f8fffc */ 	addiu	$t8,$t7,-4
/*  f0dc130:	2f010005 */ 	sltiu	$at,$t8,0x5
/*  f0dc134:	10200087 */ 	beqz	$at,.NB0f0dc354
/*  f0dc138:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0dc13c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0dc140:	00380821 */ 	addu	$at,$at,$t8
/*  f0dc144:	8c3881e0 */ 	lw	$t8,-0x7e20($at)
/*  f0dc148:	03000008 */ 	jr	$t8
/*  f0dc14c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dc150:	8fb90030 */ 	lw	$t9,0x30($sp)
/*  f0dc154:	10000080 */ 	beqz	$zero,.NB0f0dc358
/*  f0dc158:	8f2401d4 */ 	lw	$a0,0x1d4($t9)
/*  f0dc15c:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f0dc160:	8dcf01d4 */ 	lw	$t7,0x1d4($t6)
/*  f0dc164:	01af2021 */ 	addu	$a0,$t5,$t7
/*  f0dc168:	1000007b */ 	beqz	$zero,.NB0f0dc358
/*  f0dc16c:	2484000d */ 	addiu	$a0,$a0,0xd
/*  f0dc170:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f0dc174:	8fb80018 */ 	lw	$t8,0x18($sp)
/*  f0dc178:	8d8a006c */ 	lw	$t2,0x6c($t4)
/*  f0dc17c:	95cf001e */ 	lhu	$t7,0x1e($t6)
/*  f0dc180:	01b8c821 */ 	addu	$t9,$t5,$t8
/*  f0dc184:	8d870068 */ 	lw	$a3,0x68($t4)
/*  f0dc188:	032fc023 */ 	subu	$t8,$t9,$t7
/*  f0dc18c:	8dd901d4 */ 	lw	$t9,0x1d4($t6)
/*  f0dc190:	8d890064 */ 	lw	$t1,0x64($t4)
/*  f0dc194:	8d8b0070 */ 	lw	$t3,0x70($t4)
/*  f0dc198:	03192023 */ 	subu	$a0,$t8,$t9
/*  f0dc19c:	11400003 */ 	beqz	$t2,.NB0f0dc1ac
/*  f0dc1a0:	2484fff2 */ 	addiu	$a0,$a0,-14
/*  f0dc1a4:	10000002 */ 	beqz	$zero,.NB0f0dc1b0
/*  f0dc1a8:	03e03025 */ 	or	$a2,$ra,$zero
.NB0f0dc1ac:
/*  f0dc1ac:	00003025 */ 	or	$a2,$zero,$zero
.NB0f0dc1b0:
/*  f0dc1b0:	10e00003 */ 	beqz	$a3,.NB0f0dc1c0
/*  f0dc1b4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0dc1b8:	10000002 */ 	beqz	$zero,.NB0f0dc1c4
/*  f0dc1bc:	03e02825 */ 	or	$a1,$ra,$zero
.NB0f0dc1c0:
/*  f0dc1c0:	00002825 */ 	or	$a1,$zero,$zero
.NB0f0dc1c4:
/*  f0dc1c4:	11200003 */ 	beqz	$t1,.NB0f0dc1d4
/*  f0dc1c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0dc1cc:	10000001 */ 	beqz	$zero,.NB0f0dc1d4
/*  f0dc1d0:	03e01025 */ 	or	$v0,$ra,$zero
.NB0f0dc1d4:
/*  f0dc1d4:	11600003 */ 	beqz	$t3,.NB0f0dc1e4
/*  f0dc1d8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0dc1dc:	10000001 */ 	beqz	$zero,.NB0f0dc1e4
/*  f0dc1e0:	03e01825 */ 	or	$v1,$ra,$zero
.NB0f0dc1e4:
/*  f0dc1e4:	00627821 */ 	addu	$t7,$v1,$v0
/*  f0dc1e8:	01e57021 */ 	addu	$t6,$t7,$a1
/*  f0dc1ec:	01c6c021 */ 	addu	$t8,$t6,$a2
/*  f0dc1f0:	1701001b */ 	bne	$t8,$at,.NB0f0dc260
/*  f0dc1f4:	3c198007 */ 	lui	$t9,0x8007
/*  f0dc1f8:	8f392e24 */ 	lw	$t9,0x2e24($t9)
/*  f0dc1fc:	3c0f8006 */ 	lui	$t7,0x8006
/*  f0dc200:	3c0e8009 */ 	lui	$t6,0x8009
/*  f0dc204:	13200004 */ 	beqz	$t9,.NB0f0dc218
/*  f0dc208:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dc20c:	8deff2f0 */ 	lw	$t7,-0xd10($t7)
/*  f0dc210:	11e00013 */ 	beqz	$t7,.NB0f0dc260
/*  f0dc214:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0dc218:
/*  f0dc218:	91ce30e0 */ 	lbu	$t6,0x30e0($t6)
/*  f0dc21c:	13ee000c */ 	beq	$ra,$t6,.NB0f0dc250
/*  f0dc220:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dc224:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f0dc228:	0fc53588 */ 	jal	optionsGetScreenSplit
/*  f0dc22c:	afa8002c */ 	sw	$t0,0x2c($sp)
/*  f0dc230:	241f0001 */ 	addiu	$ra,$zero,0x1
/*  f0dc234:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f0dc238:	13e20007 */ 	beq	$ra,$v0,.NB0f0dc258
/*  f0dc23c:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f0dc240:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f0dc244:	8f1901c0 */ 	lw	$t9,0x1c0($t8)
/*  f0dc248:	17200003 */ 	bnez	$t9,.NB0f0dc258
/*  f0dc24c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0dc250:
/*  f0dc250:	10000041 */ 	beqz	$zero,.NB0f0dc358
/*  f0dc254:	24840008 */ 	addiu	$a0,$a0,0x8
.NB0f0dc258:
/*  f0dc258:	1000003f */ 	beqz	$zero,.NB0f0dc358
/*  f0dc25c:	24840003 */ 	addiu	$a0,$a0,0x3
.NB0f0dc260:
/*  f0dc260:	11400003 */ 	beqz	$t2,.NB0f0dc270
/*  f0dc264:	00003025 */ 	or	$a2,$zero,$zero
/*  f0dc268:	10000001 */ 	beqz	$zero,.NB0f0dc270
/*  f0dc26c:	24060001 */ 	addiu	$a2,$zero,0x1
.NB0f0dc270:
/*  f0dc270:	10e00003 */ 	beqz	$a3,.NB0f0dc280
/*  f0dc274:	00002825 */ 	or	$a1,$zero,$zero
/*  f0dc278:	10000001 */ 	beqz	$zero,.NB0f0dc280
/*  f0dc27c:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f0dc280:
/*  f0dc280:	11200003 */ 	beqz	$t1,.NB0f0dc290
/*  f0dc284:	00001025 */ 	or	$v0,$zero,$zero
/*  f0dc288:	10000001 */ 	beqz	$zero,.NB0f0dc290
/*  f0dc28c:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f0dc290:
/*  f0dc290:	11600003 */ 	beqz	$t3,.NB0f0dc2a0
/*  f0dc294:	00001825 */ 	or	$v1,$zero,$zero
/*  f0dc298:	10000001 */ 	beqz	$zero,.NB0f0dc2a0
/*  f0dc29c:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f0dc2a0:
/*  f0dc2a0:	00627821 */ 	addu	$t7,$v1,$v0
/*  f0dc2a4:	01e57021 */ 	addu	$t6,$t7,$a1
/*  f0dc2a8:	01c6c021 */ 	addu	$t8,$t6,$a2
/*  f0dc2ac:	2b010003 */ 	slti	$at,$t8,0x3
/*  f0dc2b0:	14200009 */ 	bnez	$at,.NB0f0dc2d8
/*  f0dc2b4:	8fb90030 */ 	lw	$t9,0x30($sp)
/*  f0dc2b8:	8f2f01c0 */ 	lw	$t7,0x1c0($t9)
/*  f0dc2bc:	29e10002 */ 	slti	$at,$t7,0x2
/*  f0dc2c0:	10200003 */ 	beqz	$at,.NB0f0dc2d0
/*  f0dc2c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dc2c8:	10000023 */ 	beqz	$zero,.NB0f0dc358
/*  f0dc2cc:	24840008 */ 	addiu	$a0,$a0,0x8
.NB0f0dc2d0:
/*  f0dc2d0:	10000021 */ 	beqz	$zero,.NB0f0dc358
/*  f0dc2d4:	24840003 */ 	addiu	$a0,$a0,0x3
.NB0f0dc2d8:
/*  f0dc2d8:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f0dc2dc:	0fc5351c */ 	jal	optionsGetEffectiveScreenSize
/*  f0dc2e0:	afa8002c */ 	sw	$t0,0x2c($sp)
/*  f0dc2e4:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f0dc2e8:	1040001b */ 	beqz	$v0,.NB0f0dc358
/*  f0dc2ec:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f0dc2f0:	10000019 */ 	beqz	$zero,.NB0f0dc358
/*  f0dc2f4:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0dc2f8:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f0dc2fc:	8fae0018 */ 	lw	$t6,0x18($sp)
/*  f0dc300:	9719001e */ 	lhu	$t9,0x1e($t8)
/*  f0dc304:	01d97823 */ 	subu	$t7,$t6,$t9
/*  f0dc308:	05e10003 */ 	bgez	$t7,.NB0f0dc318
/*  f0dc30c:	000f7043 */ 	sra	$t6,$t7,0x1
/*  f0dc310:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0dc314:	00017043 */ 	sra	$t6,$at,0x1
.NB0f0dc318:
/*  f0dc318:	8f0f01d4 */ 	lw	$t7,0x1d4($t8)
/*  f0dc31c:	01cdc821 */ 	addu	$t9,$t6,$t5
/*  f0dc320:	1000000d */ 	beqz	$zero,.NB0f0dc358
/*  f0dc324:	032f2021 */ 	addu	$a0,$t9,$t7
/*  f0dc328:	8fae0018 */ 	lw	$t6,0x18($sp)
/*  f0dc32c:	8fb90030 */ 	lw	$t9,0x30($sp)
/*  f0dc330:	01aec021 */ 	addu	$t8,$t5,$t6
/*  f0dc334:	972f001e */ 	lhu	$t7,0x1e($t9)
/*  f0dc338:	05e10003 */ 	bgez	$t7,.NB0f0dc348
/*  f0dc33c:	000f7043 */ 	sra	$t6,$t7,0x1
/*  f0dc340:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0dc344:	00017043 */ 	sra	$t6,$at,0x1
.NB0f0dc348:
/*  f0dc348:	030e2023 */ 	subu	$a0,$t8,$t6
/*  f0dc34c:	10000002 */ 	beqz	$zero,.NB0f0dc358
/*  f0dc350:	24840012 */ 	addiu	$a0,$a0,0x12
.NB0f0dc354:
/*  f0dc354:	8f2401d4 */ 	lw	$a0,0x1d4($t9)
.NB0f0dc358:
/*  f0dc358:	8faf0030 */ 	lw	$t7,0x30($sp)
/*  f0dc35c:	a5e80018 */ 	sh	$t0,0x18($t7)
/*  f0dc360:	a5e4001a */ 	sh	$a0,0x1a($t7)
/*  f0dc364:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0dc368:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f0dc36c:	03e00008 */ 	jr	$ra
/*  f0dc370:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel hudmsgCreateFromArgs
/*  f0df510:	27bdfe08 */ 	addiu	$sp,$sp,-504
/*  f0df514:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f0df518:	24110006 */ 	li	$s1,0x6
/*  f0df51c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0df520:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f0df524:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0df528:	afa401f8 */ 	sw	$a0,0x1f8($sp)
/*  f0df52c:	afa501fc */ 	sw	$a1,0x1fc($sp)
/*  f0df530:	afa60200 */ 	sw	$a2,0x200($sp)
/*  f0df534:	afa70204 */ 	sw	$a3,0x204($sp)
/*  f0df538:	14b10005 */ 	bne	$a1,$s1,.PF0f0df550
/*  f0df53c:	00004825 */ 	move	$t1,$zero
/*  f0df540:	0fc54d6f */ 	jal	optionsGetInGameSubtitles
/*  f0df544:	afa001ec */ 	sw	$zero,0x1ec($sp)
/*  f0df548:	1040011e */ 	beqz	$v0,.PF0f0df9c4
/*  f0df54c:	8fa901ec */ 	lw	$t1,0x1ec($sp)
.PF0f0df550:
/*  f0df550:	8faf01f8 */ 	lw	$t7,0x1f8($sp)
/*  f0df554:	8fb90230 */ 	lw	$t9,0x230($sp)
/*  f0df558:	3c07800a */ 	lui	$a3,0x800a
/*  f0df55c:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f0df560:	24e7a510 */ 	addiu	$a3,$a3,-23280
/*  f0df564:	01e01025 */ 	move	$v0,$t7
/*  f0df568:	13000007 */ 	beqz	$t8,.PF0f0df588
/*  f0df56c:	332a0001 */ 	andi	$t2,$t9,0x1
/*  f0df570:	91e30000 */ 	lbu	$v1,0x0($t7)
/*  f0df574:	00694821 */ 	addu	$t1,$v1,$t1
.PF0f0df578:
/*  f0df578:	90430001 */ 	lbu	$v1,0x1($v0)
/*  f0df57c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0df580:	5460fffd */ 	bnezl	$v1,.PF0f0df578
/*  f0df584:	00694821 */ 	addu	$t1,$v1,$t1
.PF0f0df588:
/*  f0df588:	11400004 */ 	beqz	$t2,.PF0f0df59c
/*  f0df58c:	8fad0230 */ 	lw	$t5,0x230($sp)
/*  f0df590:	8ceb0284 */ 	lw	$t3,0x284($a3)
/*  f0df594:	8d6c00d8 */ 	lw	$t4,0xd8($t3)
/*  f0df598:	1580010a */ 	bnez	$t4,.PF0f0df9c4
.PF0f0df59c:
/*  f0df59c:	3c07800a */ 	lui	$a3,0x800a
/*  f0df5a0:	31ae0008 */ 	andi	$t6,$t5,0x8
/*  f0df5a4:	15c0001b */ 	bnez	$t6,.PF0f0df614
/*  f0df5a8:	24e7a510 */ 	addiu	$a3,$a3,-23280
/*  f0df5ac:	3c048007 */ 	lui	$a0,0x8007
/*  f0df5b0:	8c8412c8 */ 	lw	$a0,0x12c8($a0)
/*  f0df5b4:	2406ffff */ 	li	$a2,-1
/*  f0df5b8:	00008025 */ 	move	$s0,$zero
/*  f0df5bc:	18800014 */ 	blez	$a0,.PF0f0df610
/*  f0df5c0:	3c028007 */ 	lui	$v0,0x8007
/*  f0df5c4:	8c4212cc */ 	lw	$v0,0x12cc($v0)
/*  f0df5c8:	24050005 */ 	li	$a1,0x5
.PF0f0df5cc:
/*  f0df5cc:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f0df5d0:	5060000c */ 	beqzl	$v1,.PF0f0df604
/*  f0df5d4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0df5d8:	50a3000a */ 	beql	$a1,$v1,.PF0f0df604
/*  f0df5dc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0df5e0:	8cf8028c */ 	lw	$t8,0x28c($a3)
/*  f0df5e4:	8c4f01c0 */ 	lw	$t7,0x1c0($v0)
/*  f0df5e8:	570f0006 */ 	bnel	$t8,$t7,.PF0f0df604
/*  f0df5ec:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0df5f0:	8c5901d8 */ 	lw	$t9,0x1d8($v0)
/*  f0df5f4:	55390003 */ 	bnel	$t1,$t9,.PF0f0df604
/*  f0df5f8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0df5fc:	02003025 */ 	move	$a2,$s0
/*  f0df600:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0f0df604:
/*  f0df604:	0204082a */ 	slt	$at,$s0,$a0
/*  f0df608:	1420fff0 */ 	bnez	$at,.PF0f0df5cc
/*  f0df60c:	244201dc */ 	addiu	$v0,$v0,0x1dc
.PF0f0df610:
/*  f0df610:	04c100ec */ 	bgez	$a2,.PF0f0df9c4
.PF0f0df614:
/*  f0df614:	3c048007 */ 	lui	$a0,0x8007
/*  f0df618:	8c8412c8 */ 	lw	$a0,0x12c8($a0)
/*  f0df61c:	240a0001 */ 	li	$t2,0x1
/*  f0df620:	3c018008 */ 	lui	$at,0x8008
/*  f0df624:	ac2a0020 */ 	sw	$t2,0x20($at)
/*  f0df628:	1880000a */ 	blez	$a0,.PF0f0df654
/*  f0df62c:	00008025 */ 	move	$s0,$zero
/*  f0df630:	3c028007 */ 	lui	$v0,0x8007
/*  f0df634:	8c4212cc */ 	lw	$v0,0x12cc($v0)
.PF0f0df638:
/*  f0df638:	904b0000 */ 	lbu	$t3,0x0($v0)
/*  f0df63c:	51600006 */ 	beqzl	$t3,.PF0f0df658
/*  f0df640:	0204082a */ 	slt	$at,$s0,$a0
/*  f0df644:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0df648:	0204082a */ 	slt	$at,$s0,$a0
/*  f0df64c:	1420fffa */ 	bnez	$at,.PF0f0df638
/*  f0df650:	244201dc */ 	addiu	$v0,$v0,0x1dc
.PF0f0df654:
/*  f0df654:	0204082a */ 	slt	$at,$s0,$a0
.PF0f0df658:
/*  f0df658:	1420002a */ 	bnez	$at,.PF0f0df704
/*  f0df65c:	8fac01fc */ 	lw	$t4,0x1fc($sp)
/*  f0df660:	24010001 */ 	li	$at,0x1
/*  f0df664:	11810006 */ 	beq	$t4,$at,.PF0f0df680
/*  f0df668:	2404ffff */ 	li	$a0,-1
/*  f0df66c:	24010002 */ 	li	$at,0x2
/*  f0df670:	11810003 */ 	beq	$t4,$at,.PF0f0df680
/*  f0df674:	00000000 */ 	nop
/*  f0df678:	15910022 */ 	bne	$t4,$s1,.PF0f0df704
/*  f0df67c:	00000000 */ 	nop
.PF0f0df680:
/*  f0df680:	0fc37938 */ 	jal	hudmsgGetNext
/*  f0df684:	afa901ec */ 	sw	$t1,0x1ec($sp)
/*  f0df688:	8fa901ec */ 	lw	$t1,0x1ec($sp)
/*  f0df68c:	0440001d */ 	bltz	$v0,.PF0f0df704
/*  f0df690:	00408025 */ 	move	$s0,$v0
/*  f0df694:	241201dc */ 	li	$s2,0x1dc
/*  f0df698:	24110003 */ 	li	$s1,0x3
.PF0f0df69c:
/*  f0df69c:	00520019 */ 	multu	$v0,$s2
/*  f0df6a0:	3c058007 */ 	lui	$a1,0x8007
/*  f0df6a4:	8ca512cc */ 	lw	$a1,0x12cc($a1)
/*  f0df6a8:	24010001 */ 	li	$at,0x1
/*  f0df6ac:	00006812 */ 	mflo	$t5
/*  f0df6b0:	00ad2021 */ 	addu	$a0,$a1,$t5
/*  f0df6b4:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f0df6b8:	15c10009 */ 	bne	$t6,$at,.PF0f0df6e0
/*  f0df6bc:	00000000 */ 	nop
/*  f0df6c0:	8c8301b4 */ 	lw	$v1,0x1b4($a0)
/*  f0df6c4:	24010004 */ 	li	$at,0x4
/*  f0df6c8:	1060000e */ 	beqz	$v1,.PF0f0df704
/*  f0df6cc:	00000000 */ 	nop
/*  f0df6d0:	1223000c */ 	beq	$s1,$v1,.PF0f0df704
/*  f0df6d4:	00000000 */ 	nop
/*  f0df6d8:	1061000a */ 	beq	$v1,$at,.PF0f0df704
/*  f0df6dc:	00000000 */ 	nop
.PF0f0df6e0:
/*  f0df6e0:	02120019 */ 	multu	$s0,$s2
/*  f0df6e4:	0000c012 */ 	mflo	$t8
/*  f0df6e8:	00b87821 */ 	addu	$t7,$a1,$t8
/*  f0df6ec:	8de401b8 */ 	lw	$a0,0x1b8($t7)
/*  f0df6f0:	0fc37938 */ 	jal	hudmsgGetNext
/*  f0df6f4:	afa901ec */ 	sw	$t1,0x1ec($sp)
/*  f0df6f8:	8fa901ec */ 	lw	$t1,0x1ec($sp)
/*  f0df6fc:	0441ffe7 */ 	bgez	$v0,.PF0f0df69c
/*  f0df700:	00408025 */ 	move	$s0,$v0
.PF0f0df704:
/*  f0df704:	060000ac */ 	bltz	$s0,.PF0f0df9b8
/*  f0df708:	241201dc */ 	li	$s2,0x1dc
/*  f0df70c:	3c198007 */ 	lui	$t9,0x8007
/*  f0df710:	8f3912c8 */ 	lw	$t9,0x12c8($t9)
/*  f0df714:	0219082a */ 	slt	$at,$s0,$t9
/*  f0df718:	502000a8 */ 	beqzl	$at,.PF0f0df9bc
/*  f0df71c:	240f0001 */ 	li	$t7,0x1
/*  f0df720:	02120019 */ 	multu	$s0,$s2
/*  f0df724:	3c0b8007 */ 	lui	$t3,0x8007
/*  f0df728:	8d6b12cc */ 	lw	$t3,0x12cc($t3)
/*  f0df72c:	afa001d8 */ 	sw	$zero,0x1d8($sp)
/*  f0df730:	27a401d8 */ 	addiu	$a0,$sp,0x1d8
/*  f0df734:	8fa50220 */ 	lw	$a1,0x220($sp)
/*  f0df738:	afa901ec */ 	sw	$t1,0x1ec($sp)
/*  f0df73c:	00005012 */ 	mflo	$t2
/*  f0df740:	014b8821 */ 	addu	$s1,$t2,$t3
/*  f0df744:	0fc3782b */ 	jal	func0f0ddb1c
/*  f0df748:	00000000 */ 	nop
/*  f0df74c:	8fad0210 */ 	lw	$t5,0x210($sp)
/*  f0df750:	8fac020c */ 	lw	$t4,0x20c($sp)
/*  f0df754:	afa201d4 */ 	sw	$v0,0x1d4($sp)
/*  f0df758:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f0df75c:	8d870000 */ 	lw	$a3,0x0($t4)
/*  f0df760:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0df764:	27a401dc */ 	addiu	$a0,$sp,0x1dc
/*  f0df768:	27a501e0 */ 	addiu	$a1,$sp,0x1e0
/*  f0df76c:	8fa601f8 */ 	lw	$a2,0x1f8($sp)
/*  f0df770:	0fc5609a */ 	jal	textMeasure
/*  f0df774:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0df778:	8fb801d4 */ 	lw	$t8,0x1d4($sp)
/*  f0df77c:	8faf01e0 */ 	lw	$t7,0x1e0($sp)
/*  f0df780:	8fa901ec */ 	lw	$t1,0x1ec($sp)
/*  f0df784:	26240020 */ 	addiu	$a0,$s1,0x20
/*  f0df788:	030f082a */ 	slt	$at,$t8,$t7
/*  f0df78c:	10200033 */ 	beqz	$at,.PF0f0df85c
/*  f0df790:	8fa501f8 */ 	lw	$a1,0x1f8($sp)
/*  f0df794:	8fb901f8 */ 	lw	$t9,0x1f8($sp)
/*  f0df798:	00002825 */ 	move	$a1,$zero
/*  f0df79c:	00004025 */ 	move	$t0,$zero
/*  f0df7a0:	932a0000 */ 	lbu	$t2,0x0($t9)
/*  f0df7a4:	240c000a */ 	li	$t4,0xa
/*  f0df7a8:	26320020 */ 	addiu	$s2,$s1,0x20
/*  f0df7ac:	11400010 */ 	beqz	$t2,.PF0f0df7f0
/*  f0df7b0:	03201021 */ 	addu	$v0,$t9,$zero
/*  f0df7b4:	93230000 */ 	lbu	$v1,0x0($t9)
/*  f0df7b8:	27b00044 */ 	addiu	$s0,$sp,0x44
/*  f0df7bc:	2406000a */ 	li	$a2,0xa
/*  f0df7c0:	00602025 */ 	move	$a0,$v1
.PF0f0df7c4:
/*  f0df7c4:	10c40004 */ 	beq	$a2,$a0,.PF0f0df7d8
/*  f0df7c8:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0df7cc:	02085821 */ 	addu	$t3,$s0,$t0
/*  f0df7d0:	a1630000 */ 	sb	$v1,0x0($t3)
/*  f0df7d4:	25080001 */ 	addiu	$t0,$t0,0x1
.PF0f0df7d8:
/*  f0df7d8:	28a10190 */ 	slti	$at,$a1,0x190
/*  f0df7dc:	10200004 */ 	beqz	$at,.PF0f0df7f0
/*  f0df7e0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0df7e4:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f0df7e8:	1460fff6 */ 	bnez	$v1,.PF0f0df7c4
/*  f0df7ec:	00602025 */ 	move	$a0,$v1
.PF0f0df7f0:
/*  f0df7f0:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0df7f4:	00a86821 */ 	addu	$t5,$a1,$t0
/*  f0df7f8:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f0df7fc:	a1ac0000 */ 	sb	$t4,0x0($t5)
/*  f0df800:	00a87021 */ 	addu	$t6,$a1,$t0
/*  f0df804:	a1c00000 */ 	sb	$zero,0x0($t6)
/*  f0df808:	8faf0210 */ 	lw	$t7,0x210($sp)
/*  f0df80c:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0df810:	8fa401d4 */ 	lw	$a0,0x1d4($sp)
/*  f0df814:	8dea0000 */ 	lw	$t2,0x0($t7)
/*  f0df818:	8f070000 */ 	lw	$a3,0x0($t8)
/*  f0df81c:	afa901ec */ 	sw	$t1,0x1ec($sp)
/*  f0df820:	02403025 */ 	move	$a2,$s2
/*  f0df824:	0fc56123 */ 	jal	textWrap
/*  f0df828:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0df82c:	8fab0210 */ 	lw	$t3,0x210($sp)
/*  f0df830:	8fb9020c */ 	lw	$t9,0x20c($sp)
/*  f0df834:	27a401dc */ 	addiu	$a0,$sp,0x1dc
/*  f0df838:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*  f0df83c:	8f270000 */ 	lw	$a3,0x0($t9)
/*  f0df840:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0df844:	27a501e0 */ 	addiu	$a1,$sp,0x1e0
/*  f0df848:	02403025 */ 	move	$a2,$s2
/*  f0df84c:	0fc5609a */ 	jal	textMeasure
/*  f0df850:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0df854:	10000006 */ 	b	.PF0f0df870
/*  f0df858:	8fa901ec */ 	lw	$t1,0x1ec($sp)
.PF0f0df85c:
/*  f0df85c:	2406018f */ 	li	$a2,0x18f
/*  f0df860:	0c004bd6 */ 	jal	strncpy
/*  f0df864:	afa901ec */ 	sw	$t1,0x1ec($sp)
/*  f0df868:	8fa901ec */ 	lw	$t1,0x1ec($sp)
/*  f0df86c:	a22001af */ 	sb	$zero,0x1af($s1)
.PF0f0df870:
/*  f0df870:	8fad0230 */ 	lw	$t5,0x230($sp)
/*  f0df874:	3c0e800a */ 	lui	$t6,0x800a
/*  f0df878:	3c02800a */ 	lui	$v0,0x800a
/*  f0df87c:	ae2d01c4 */ 	sw	$t5,0x1c4($s1)
/*  f0df880:	8dcea79c */ 	lw	$t6,-0x5864($t6)
/*  f0df884:	2442e410 */ 	addiu	$v0,$v0,-7152
/*  f0df888:	240b0001 */ 	li	$t3,0x1
/*  f0df88c:	ae2e01c0 */ 	sw	$t6,0x1c0($s1)
/*  f0df890:	8fb801fc */ 	lw	$t8,0x1fc($sp)
/*  f0df894:	02202025 */ 	move	$a0,$s1
/*  f0df898:	ae3801b4 */ 	sw	$t8,0x1b4($s1)
/*  f0df89c:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f0df8a0:	ae2f01b8 */ 	sw	$t7,0x1b8($s1)
/*  f0df8a4:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*  f0df8a8:	25590001 */ 	addiu	$t9,$t2,0x1
/*  f0df8ac:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0df8b0:	a22b0000 */ 	sb	$t3,0x0($s1)
/*  f0df8b4:	a6200006 */ 	sh	$zero,0x6($s1)
/*  f0df8b8:	8fac0200 */ 	lw	$t4,0x200($sp)
/*  f0df8bc:	a22c0001 */ 	sb	$t4,0x1($s1)
/*  f0df8c0:	8fad0204 */ 	lw	$t5,0x204($sp)
/*  f0df8c4:	a22d0002 */ 	sb	$t5,0x2($s1)
/*  f0df8c8:	8fae0208 */ 	lw	$t6,0x208($sp)
/*  f0df8cc:	a22e0003 */ 	sb	$t6,0x3($s1)
/*  f0df8d0:	8fb8020c */ 	lw	$t8,0x20c($sp)
/*  f0df8d4:	8f0f0000 */ 	lw	$t7,0x0($t8)
/*  f0df8d8:	ae2f0008 */ 	sw	$t7,0x8($s1)
/*  f0df8dc:	8faa0210 */ 	lw	$t2,0x210($sp)
/*  f0df8e0:	8d590000 */ 	lw	$t9,0x0($t2)
/*  f0df8e4:	ae39000c */ 	sw	$t9,0xc($s1)
/*  f0df8e8:	8fab0214 */ 	lw	$t3,0x214($sp)
/*  f0df8ec:	ae2b0010 */ 	sw	$t3,0x10($s1)
/*  f0df8f0:	8fac0218 */ 	lw	$t4,0x218($sp)
/*  f0df8f4:	ae2c0014 */ 	sw	$t4,0x14($s1)
/*  f0df8f8:	8fad021c */ 	lw	$t5,0x21c($sp)
/*  f0df8fc:	a22d01c8 */ 	sb	$t5,0x1c8($s1)
/*  f0df900:	8fae0224 */ 	lw	$t6,0x224($sp)
/*  f0df904:	a22e01c9 */ 	sb	$t6,0x1c9($s1)
/*  f0df908:	8fb801e0 */ 	lw	$t8,0x1e0($sp)
/*  f0df90c:	a638001c */ 	sh	$t8,0x1c($s1)
/*  f0df910:	8faf01dc */ 	lw	$t7,0x1dc($sp)
/*  f0df914:	a62f001e */ 	sh	$t7,0x1e($s1)
/*  f0df918:	8faa01d8 */ 	lw	$t2,0x1d8($sp)
/*  f0df91c:	ae2a01cc */ 	sw	$t2,0x1cc($s1)
/*  f0df920:	8fb90220 */ 	lw	$t9,0x220($sp)
/*  f0df924:	ae3901d0 */ 	sw	$t9,0x1d0($s1)
/*  f0df928:	8fab0228 */ 	lw	$t3,0x228($sp)
/*  f0df92c:	ae2901d8 */ 	sw	$t1,0x1d8($s1)
/*  f0df930:	0fc37b8c */ 	jal	hudmsgCalculatePosition
/*  f0df934:	ae2b01d4 */ 	sw	$t3,0x1d4($s1)
/*  f0df938:	8fac0230 */ 	lw	$t4,0x230($sp)
/*  f0df93c:	8fb901fc */ 	lw	$t9,0x1fc($sp)
/*  f0df940:	8fae022c */ 	lw	$t6,0x22c($sp)
/*  f0df944:	318d0004 */ 	andi	$t5,$t4,0x4
/*  f0df948:	11a0000d */ 	beqz	$t5,.PF0f0df980
/*  f0df94c:	00195940 */ 	sll	$t3,$t9,0x5
/*  f0df950:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f0df954:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f0df958:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0df95c:	030ec021 */ 	addu	$t8,$t8,$t6
/*  f0df960:	0018c040 */ 	sll	$t8,$t8,0x1
/*  f0df964:	2401003c */ 	li	$at,0x3c
/*  f0df968:	0301001a */ 	div	$zero,$t8,$at
/*  f0df96c:	00007812 */ 	mflo	$t7
/*  f0df970:	240affff */ 	li	$t2,-1
/*  f0df974:	ae2f01bc */ 	sw	$t7,0x1bc($s1)
/*  f0df978:	1000000f */ 	b	.PF0f0df9b8
/*  f0df97c:	ae2a01b0 */ 	sw	$t2,0x1b0($s1)
.PF0f0df980:
/*  f0df980:	3c0c8007 */ 	lui	$t4,0x8007
/*  f0df984:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f0df988:	8d8c12ec */ 	lw	$t4,0x12ec($t4)
/*  f0df98c:	2401003c */ 	li	$at,0x3c
/*  f0df990:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0df994:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f0df998:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f0df99c:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f0df9a0:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f0df9a4:	01a1001a */ 	div	$zero,$t5,$at
/*  f0df9a8:	00007012 */ 	mflo	$t6
/*  f0df9ac:	ae2e01bc */ 	sw	$t6,0x1bc($s1)
/*  f0df9b0:	8fb8022c */ 	lw	$t8,0x22c($sp)
/*  f0df9b4:	ae3801b0 */ 	sw	$t8,0x1b0($s1)
.PF0f0df9b8:
/*  f0df9b8:	240f0001 */ 	li	$t7,0x1
.PF0f0df9bc:
/*  f0df9bc:	3c018008 */ 	lui	$at,0x8008
/*  f0df9c0:	ac2f0020 */ 	sw	$t7,0x20($at)
.PF0f0df9c4:
/*  f0df9c4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0df9c8:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0df9cc:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0df9d0:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0df9d4:	03e00008 */ 	jr	$ra
/*  f0df9d8:	27bd01f8 */ 	addiu	$sp,$sp,0x1f8
);
#else
GLOBAL_ASM(
glabel hudmsgCreateFromArgs
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
/*  f0def6c:	3c028007 */ 	lui	$v0,%hi(g_HudMessages)
/*  f0def70:	8c420fec */ 	lw	$v0,%lo(g_HudMessages)($v0)
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
/*  f0defb8:	244201dc */ 	addiu	$v0,$v0,476
.L0f0defbc:
/*  f0defbc:	04c100e3 */ 	bgez	$a2,.L0f0df34c
.L0f0defc0:
/*  f0defc0:	3c0a8007 */ 	lui	$t2,%hi(g_ViMode)
/*  f0defc4:	8d4a06c8 */ 	lw	$t2,%lo(g_ViMode)($t2)
/*  f0defc8:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0defcc:	3c048007 */ 	lui	$a0,%hi(g_NumHudMessages)
/*  f0defd0:	8c840fe8 */ 	lw	$a0,%lo(g_NumHudMessages)($a0)
/*  f0defd4:	146a0005 */ 	bne	$v1,$t2,.L0f0defec
/*  f0defd8:	00008025 */ 	or	$s0,$zero,$zero
/*  f0defdc:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f0defe0:	3c018008 */ 	lui	$at,%hi(g_ScaleX)
/*  f0defe4:	10000003 */ 	b	.L0f0deff4
/*  f0defe8:	ac2bfac0 */ 	sw	$t3,%lo(g_ScaleX)($at)
.L0f0defec:
/*  f0defec:	3c018008 */ 	lui	$at,%hi(g_ScaleX)
/*  f0deff0:	ac23fac0 */ 	sw	$v1,%lo(g_ScaleX)($at)
.L0f0deff4:
/*  f0deff4:	18800009 */ 	blez	$a0,.L0f0df01c
/*  f0deff8:	3c028007 */ 	lui	$v0,%hi(g_HudMessages)
/*  f0deffc:	8c420fec */ 	lw	$v0,%lo(g_HudMessages)($v0)
.L0f0df000:
/*  f0df000:	904c0000 */ 	lbu	$t4,0x0($v0)
/*  f0df004:	51800006 */ 	beqzl	$t4,.L0f0df020
/*  f0df008:	0204082a */ 	slt	$at,$s0,$a0
/*  f0df00c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0df010:	0204082a */ 	slt	$at,$s0,$a0
/*  f0df014:	1420fffa */ 	bnez	$at,.L0f0df000
/*  f0df018:	244201dc */ 	addiu	$v0,$v0,476
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
/*  f0df040:	0fc377ab */ 	jal	hudmsgGetNext
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
/*  f0df07c:	00000000 */ 	nop
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
/*  f0df0b0:	0fc377ab */ 	jal	hudmsgGetNext
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
/*  f0df0e0:	00000000 */ 	nop
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
/*  f0df10c:	00000000 */ 	nop
/*  f0df110:	8fae0210 */ 	lw	$t6,0x210($sp)
/*  f0df114:	8fad020c */ 	lw	$t5,0x20c($sp)
/*  f0df118:	afa201d4 */ 	sw	$v0,0x1d4($sp)
/*  f0df11c:	8dd80000 */ 	lw	$t8,0x0($t6)
/*  f0df120:	8da70000 */ 	lw	$a3,0x0($t5)
/*  f0df124:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0df128:	27a401dc */ 	addiu	$a0,$sp,0x1dc
/*  f0df12c:	27a501e0 */ 	addiu	$a1,$sp,0x1e0
/*  f0df130:	8fa601f8 */ 	lw	$a2,0x1f8($sp)
/*  f0df134:	0fc55cbe */ 	jal	textMeasure
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
/*  f0df1e8:	0fc55d48 */ 	jal	textWrap
/*  f0df1ec:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0df1f0:	8fac0210 */ 	lw	$t4,0x210($sp)
/*  f0df1f4:	8faa020c */ 	lw	$t2,0x20c($sp)
/*  f0df1f8:	27a401dc */ 	addiu	$a0,$sp,0x1dc
/*  f0df1fc:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f0df200:	8d470000 */ 	lw	$a3,0x0($t2)
/*  f0df204:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0df208:	27a501e0 */ 	addiu	$a1,$sp,0x1e0
/*  f0df20c:	02403025 */ 	or	$a2,$s2,$zero
/*  f0df210:	0fc55cbe */ 	jal	textMeasure
/*  f0df214:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0df218:	10000006 */ 	b	.L0f0df234
/*  f0df21c:	8fa901ec */ 	lw	$t1,0x1ec($sp)
.L0f0df220:
/*  f0df220:	2406018f */ 	addiu	$a2,$zero,0x18f
/*  f0df224:	0c004c72 */ 	jal	strncpy
/*  f0df228:	afa901ec */ 	sw	$t1,0x1ec($sp)
/*  f0df22c:	8fa901ec */ 	lw	$t1,0x1ec($sp)
/*  f0df230:	a22001af */ 	sb	$zero,0x1af($s1)
.L0f0df234:
/*  f0df234:	8fae0230 */ 	lw	$t6,0x230($sp)
/*  f0df238:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x28c)
/*  f0df23c:	3c02800a */ 	lui	$v0,%hi(g_NextHudMessageId)
/*  f0df240:	ae2e01c4 */ 	sw	$t6,0x1c4($s1)
/*  f0df244:	8f18a24c */ 	lw	$t8,%lo(g_Vars+0x28c)($t8)
/*  f0df248:	2442dea0 */ 	addiu	$v0,$v0,%lo(g_NextHudMessageId)
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
/*  f0df2f4:	0fc379ff */ 	jal	hudmsgCalculatePosition
/*  f0df2f8:	ae2c01d4 */ 	sw	$t4,0x1d4($s1)
/*  f0df2fc:	8fad0230 */ 	lw	$t5,0x230($sp)
/*  f0df300:	8fb901fc */ 	lw	$t9,0x1fc($sp)
/*  f0df304:	3c0a8007 */ 	lui	$t2,%hi(g_HudmsgTypes+0x1c)
/*  f0df308:	31ae0004 */ 	andi	$t6,$t5,0x4
/*  f0df30c:	11c00007 */ 	beqz	$t6,.L0f0df32c
/*  f0df310:	00195940 */ 	sll	$t3,$t9,0x5
/*  f0df314:	8fb8022c */ 	lw	$t8,0x22c($sp)
/*  f0df318:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0df31c:	ae2f01b0 */ 	sw	$t7,0x1b0($s1)
/*  f0df320:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0df324:	10000007 */ 	b	.L0f0df344
/*  f0df328:	ae3801bc */ 	sw	$t8,0x1bc($s1)
.L0f0df32c:
/*  f0df32c:	014b5021 */ 	addu	$t2,$t2,$t3
/*  f0df330:	8d4a100c */ 	lw	$t2,%lo(g_HudmsgTypes+0x1c)($t2)
/*  f0df334:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0df338:	ae2a01bc */ 	sw	$t2,0x1bc($s1)
/*  f0df33c:	8fac022c */ 	lw	$t4,0x22c($sp)
/*  f0df340:	ae2c01b0 */ 	sw	$t4,0x1b0($s1)
.L0f0df344:
/*  f0df344:	3c018008 */ 	lui	$at,%hi(g_ScaleX)
/*  f0df348:	ac23fac0 */ 	sw	$v1,%lo(g_ScaleX)($at)
.L0f0df34c:
/*  f0df34c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0df350:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0df354:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f0df358:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f0df35c:	03e00008 */ 	jr	$ra
/*  f0df360:	27bd01f8 */ 	addiu	$sp,$sp,0x1f8
);
#endif

// Mismatch due to regalloc in duplicate check near:
// g_HudMessages[index].playernum == g_Vars.currentplayernum
//void hudmsgCreateFromArgs(char *text, s32 type, s32 conf00, s32 conf01, s32 conf02,
//		struct hudmessagething *conf04, struct hudmessagething *conf08,
//		u32 textcolour, u32 glowcolour,
//		u32 alignh, s32 conf16, u32 alignv, s32 conf18, s32 arg14, u32 flags)
//{
//	char *pos;
//	struct hudmessage *msg;
//	s32 hash = 0;
//	s32 i;
//	s32 index;
//	s32 uStack24;
//	u32 uStack28;
//	u32 uStack32;
//	s32 iStack36;
//	char stacktext[400];
//	s32 writeindex;
//
//	if (type == HUDMSGTYPE_INGAMESUBTITLE && !optionsGetInGameSubtitles()) {
//		return;
//	}
//
//	pos = text;
//
//	while (*pos) {
//		hash = hash + *pos;
//		pos++;
//	}
//
//	if ((flags & HUDMSGFLAG_ONLYIFALIVE) == 0 || !g_Vars.currentplayer->isdead) {
//		if ((flags & HUDMSGFLAG_ALLOWDUPES) == 0) {
//			// Check for duplicate messages
//			s32 dupeofindex = -1;
//
//			for (index = 0; index < g_NumHudMessages; index++) {
//				if (g_HudMessages[index].state != HUDMSGSTATE_FREE
//						&& g_HudMessages[index].state != HUDMSGSTATE_FADINGOUT
//						&& g_HudMessages[index].playernum == g_Vars.currentplayernum
//						&& g_HudMessages[index].hash == hash) {
//					dupeofindex = index;
//				}
//			}
//
//			if (dupeofindex >= 0) {
//				return;
//			}
//		}
//
//		g_ScaleX = g_ViMode == VIMODE_HIRES ? 2 : 1;
//
//		// Find an unused index for the new message
//		for (index = 0; index < g_NumHudMessages; index++) {
//			if (g_HudMessages[index].state == HUDMSGSTATE_FREE) {
//				break;
//			}
//		}
//
//		if (index >= g_NumHudMessages
//				&& (type == HUDMSGTYPE_OBJECTIVECOMPLETE
//					|| type == HUDMSGTYPE_OBJECTIVEFAILED
//					|| type == HUDMSGTYPE_INGAMESUBTITLE)) {
//			// Out of space - Check if an existing message can be replaced
//			index = hudmsgGetNext(-1);
//
//			while (index >= 0) {
//				if (g_HudMessages[index].state == HUDMSGSTATE_QUEUED) {
//					if (g_HudMessages[index].type == HUDMSGTYPE_DEFAULT
//							|| g_HudMessages[index].type == HUDMSGTYPE_3
//							|| g_HudMessages[index].type == HUDMSGTYPE_4) {
//						// Good to replace this one
//						break;
//					}
//				}
//
//				// Can't replace - try and find another
//				index = hudmsgGetNext(g_HudMessages[index].id);
//			}
//		}
//
//		if (index >= 0 && index < g_NumHudMessages) {
//			uStack32 = 0;
//			msg = &g_HudMessages[index];
//			iStack36 = func0f0ddb1c(&uStack32, conf16);
//			textMeasure(&uStack28, &uStack24, text, conf04->unk00, conf08->unk00, 0);
//
//			if (iStack36 < uStack24) {
//				i = 0;
//				writeindex = 0;
//
//				while (i < 400 && text[i] != '\0') {
//					if (text[i] != '\n') {
//						stacktext[writeindex++] = text[i];
//					}
//
//					i++;
//				}
//
//				stacktext[writeindex++] = '\n';
//				stacktext[writeindex++] = '\0';
//
//				textWrap(iStack36, stacktext, msg->text, conf04->unk00, conf08->unk00);
//				textMeasure(&uStack28, &uStack24, msg->text, conf04->unk00, conf08->unk00, 0);
//			} else {
//				strncpy(msg->text, text, 399);
//				msg->text[399] = '\0';
//			}
//
//			msg->flags = flags;
//			msg->playernum = g_Vars.currentplayernum;
//			msg->type = type;
//			msg->id = g_NextHudMessageId++;
//			msg->state = HUDMSGSTATE_QUEUED;
//			msg->timer = 0;
//			msg->boxed = conf00;
//			msg->allowfadein = conf01;
//			msg->flash = conf02;
//			msg->font1 = conf04->unk00;
//			msg->font2 = conf08->unk00;
//			msg->textcolour = textcolour;
//			msg->glowcolour = glowcolour;
//			msg->alignh = alignh;
//			msg->alignv = alignv;
//			msg->width = uStack24;
//			msg->height = uStack28;
//			msg->xmarginextra = uStack32;
//			msg->xmargin = conf16;
//			msg->ymargin = conf18;
//			msg->hash = hash;
//
//			hudmsgCalculatePosition(msg);
//
//			if (flags & HUDMSGFLAG_NOCHANNEL) {
//				msg->showduration = arg14;
//				msg->channelnum = -1;
//			} else {
//				msg->showduration = g_HudmsgTypes[type].duration;
//				msg->channelnum = arg14;
//			}
//		}
//
//		g_ScaleX = 1;
//	}
//}

#if VERSION >= VERSION_NTSC_1_0
void hudmsgsTick(void)
{
	s32 k;
	s32 previd;
	bool show;
	struct hudmessage *msg;
	s32 prevplayernum;
	s32 i;
	s32 j;
	s32 index;
	bool hide;
	f32 fadeintime;
	f32 fadeouttime;

	g_HudmsgsActive = false;

#if PAL
	g_ScaleX = 1;
#else
	g_ScaleX = (g_ViMode == VIMODE_HIRES) ? 2 : 1;
#endif

#if VERSION >= VERSION_NTSC_1_0
	prevplayernum = g_Vars.currentplayernum;

	for (k = 0; k < g_NumHudMessages; k++) {
		if (g_HudMessages[k].state != HUDMSGSTATE_FREE) {
			if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
				for (j = 0; j < g_NumHudMessages; j++) {
					if (k != j
							&& g_HudMessages[j].state != HUDMSGSTATE_FREE
							&& g_HudMessages[j].hash == g_HudMessages[k].hash) {
						g_HudMessages[j].state = HUDMSGSTATE_FREE;
					}
				}
			}

			setCurrentPlayerNum(g_HudMessages[k].playernum);
			hudmsgCalculatePosition(&g_HudMessages[k]);
		}
	}

	setCurrentPlayerNum(prevplayernum);
#else
	for (k = 0; k < g_NumHudMessages; k++) {
		if (g_HudMessages[k].state != HUDMSGSTATE_FREE) {
			hudmsgCalculatePosition(&g_HudMessages[k]);
		}
	}
#endif

	previd = -1;

	while (true) {
		index = hudmsgGetNext(previd);

		if (index < 0) {
			break;
		}

		msg = &g_HudMessages[index];
		previd = msg->id;

		if (msg->channelnum >= 0) {
			msg->opacity = propsndGetSubtitleOpacity(msg->channelnum);
		} else {
			msg->opacity = 0xff;
		}

		if (msg->type == HUDMSGTYPE_CUTSCENESUBTITLE && g_Vars.tickmode != TICKMODE_CUTSCENE) {
			msg->state = HUDMSGSTATE_FREE;
			msg->timer = 0;
		}

		switch (msg->state) {
		case HUDMSGSTATE_QUEUED:
#if VERSION >= VERSION_NTSC_1_0
			if (msg->flags & HUDMSGFLAG_DELAY) {
				msg->timer++;

				if (msg->timer > 3) {
					msg->flags &= ~HUDMSGFLAG_DELAY;
				}
			} else
#endif
			{
				show = true;

				if (g_Vars.players[msg->playernum]->isdead) {
					show = false;
				}

				if (show) {
					// Check if any other message is occupying our space
					for (i = 0; i < g_NumHudMessages; i++) {
						if (g_HudMessages[i].state != HUDMSGSTATE_FREE
								&& g_HudMessages[i].state != HUDMSGSTATE_QUEUED
								&& g_HudMessages[i].x + g_HudMessages[i].width >= msg->x
								&& g_HudMessages[i].x <= msg->x + msg->width
								&& g_HudMessages[i].y + g_HudMessages[i].height >= msg->y
								&& g_HudMessages[i].y <= msg->y + msg->height) {
							show = false;

							// Consider booting the previous message out earlier
							if (g_HudMessages[i].type == msg->type
									&& msg->boxed
									&& g_HudMessages[i].boxed
									&& g_HudMessages[i].state == HUDMSGSTATE_FADINGOUT) {
								g_HudMessages[i].state = HUDMSGSTATE_FREE;
								g_HudMessages[i].timer = 0;
								msg->state = HUDMSGSTATE_FADINGIN;
								msg->timer = 0;
							}

							break;
						}
					}
				}

				if (show) {
					if (msg->boxed) {
						msg->state = HUDMSGSTATE_CHOOSETRANSITION;
					} else if (msg->allowfadein) {
						msg->state = HUDMSGSTATE_FADINGIN;
					} else {
						msg->state = HUDMSGSTATE_ONSCREEN;
					}

					msg->timer = 0;

					if (msg->type == HUDMSGTYPE_CUTSCENESUBTITLE) {
						msg->state = HUDMSGSTATE_ONSCREEN;
					}
				}
			}
			break;
		case HUDMSGSTATE_CHOOSETRANSITION:
			if (msg->boxed && msg->allowfadein) {
				msg->state = HUDMSGSTATE_FADINGIN;
			} else {
				msg->state = HUDMSGSTATE_ONSCREEN;
			}

			if (msg->type == HUDMSGTYPE_CUTSCENESUBTITLE) {
				msg->state = HUDMSGSTATE_ONSCREEN;
			}

			msg->timer = 0;
			break;
		case HUDMSGSTATE_FADINGIN:
			if (msg->type == HUDMSGTYPE_CUTSCENESUBTITLE) {
				// Cutscene subtitles appear immediately
				msg->state = HUDMSGSTATE_ONSCREEN;
				msg->timer = 0;
			} else {
				// Most HUD messages play a swish sound effect
				if (msg->timer == 0
						&& !lvIsPaused()
						&& !mpIsPaused()
#if VERSION >= VERSION_NTSC_1_0
						&& msg->type != HUDMSGTYPE_CUTSCENESUBTITLE
						&& msg->type != HUDMSGTYPE_INGAMESUBTITLE
#endif
						&& PLAYERCOUNT() == 1) {
#if VERSION >= VERSION_NTSC_1_0
					sndStart(var80095200, SFX_HUDMSG, NULL, -1, -1, -1, -1, -1);
#else
					// Probable mismatch here for ntsc-beta
					static struct audiohandle *var800736b0nb = NULL;
					sndStart(var80095200, SFX_HUDMSG, &var800736b0nb, -1, -1, -1, -1, -1);
#endif
				}

				fadeintime = (sqrtf(msg->width * msg->width + msg->height * msg->height) + 132) / PALUPF(7.0f);

				msg->timer += g_Vars.lvupdate240_60;

				if (msg->timer >= (s32)fadeintime || msg->type == HUDMSGTYPE_CUTSCENESUBTITLE) {
					msg->state = HUDMSGSTATE_ONSCREEN;
					msg->timer = 0;
				}
			}
			break;
		case HUDMSGSTATE_ONSCREEN:
			msg->timer += g_Vars.lvupdate240_60;

			hide = false;

			// Subtitles have an audio channel number and are hidden when the audio stops
			if (msg->channelnum >= 0) {
				if (audioIsChannelIdle(msg->channelnum)) {
					hide = true;
				} else if (msg->flags & HUDMSGFLAG_FORCEOFF) {
					msg->flags &= ~HUDMSGFLAG_FORCEOFF;
					hide = true;
				}
			} else if (msg->timer >= msg->showduration && msg->showduration != -1) {
				hide = true;
			}

			if (hide) {
				if (msg->boxed) {
					msg->state = HUDMSGSTATE_FADINGOUT;
				} else {
					msg->state = HUDMSGSTATE_FREE;
				}

				msg->timer = 0;
			}
			break;
		case HUDMSGSTATE_FADINGOUT:
			fadeouttime = (sqrtf(msg->width * msg->width + msg->height * msg->height) + 92) / PALUPF(7.0f);

			msg->timer += g_Vars.lvupdate240_60;

			if (msg->timer >= (s32)fadeouttime) {
				msg->state = HUDMSGSTATE_FREE;
				msg->timer = 0;
			}
			break;
		case HUDMSGSTATE_FREE:
			break;
		}
	}

	g_ScaleX = 1;
}
#else
GLOBAL_ASM(
glabel hudmsgsTick
.late_rodata
glabel var7f1adec4
.word hudmsgsTick+0x5a8
glabel var7f1adec8
.word hudmsgsTick+0x168
glabel var7f1adecc
.word hudmsgsTick+0x2dc
glabel var7f1aded0
.word hudmsgsTick+0x318
glabel var7f1aded4
.word hudmsgsTick+0x48c
glabel var7f1aded8
.word hudmsgsTick+0x52c
.text
/*  f0dc81c:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0dc820:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0dc824:	8dce2d88 */ 	lw	$t6,0x2d88($t6)
/*  f0dc828:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f0dc82c:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f0dc830:	3c018007 */ 	lui	$at,0x8007
/*  f0dc834:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0dc838:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f0dc83c:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f0dc840:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f0dc844:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f0dc848:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f0dc84c:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0dc850:	162e0005 */ 	bne	$s1,$t6,.NB0f0dc868
/*  f0dc854:	a0203670 */ 	sb	$zero,0x3670($at)
/*  f0dc858:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0dc85c:	3c018008 */ 	lui	$at,0x8008
/*  f0dc860:	10000003 */ 	beqz	$zero,.NB0f0dc870
/*  f0dc864:	ac2f2320 */ 	sw	$t7,0x2320($at)
.NB0f0dc868:
/*  f0dc868:	3c018008 */ 	lui	$at,0x8008
/*  f0dc86c:	ac312320 */ 	sw	$s1,0x2320($at)
.NB0f0dc870:
/*  f0dc870:	3c088007 */ 	lui	$t0,0x8007
/*  f0dc874:	8d0836a8 */ 	lw	$t0,0x36a8($t0)
/*  f0dc878:	00001825 */ 	or	$v1,$zero,$zero
/*  f0dc87c:	00008025 */ 	or	$s0,$zero,$zero
/*  f0dc880:	19000011 */ 	blez	$t0,.NB0f0dc8c8
/*  f0dc884:	3c168007 */ 	lui	$s6,0x8007
/*  f0dc888:	26d636ac */ 	addiu	$s6,$s6,0x36ac
.NB0f0dc88c:
/*  f0dc88c:	8ec20000 */ 	lw	$v0,0x0($s6)
/*  f0dc890:	0050c021 */ 	addu	$t8,$v0,$s0
/*  f0dc894:	93190000 */ 	lbu	$t9,0x0($t8)
/*  f0dc898:	02022021 */ 	addu	$a0,$s0,$v0
/*  f0dc89c:	53200007 */ 	beqzl	$t9,.NB0f0dc8bc
/*  f0dc8a0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0dc8a4:	0fc36f85 */ 	jal	hudmsgCalculatePosition
/*  f0dc8a8:	afa30064 */ 	sw	$v1,0x64($sp)
/*  f0dc8ac:	3c088007 */ 	lui	$t0,0x8007
/*  f0dc8b0:	8d0836a8 */ 	lw	$t0,0x36a8($t0)
/*  f0dc8b4:	8fa30064 */ 	lw	$v1,0x64($sp)
/*  f0dc8b8:	24630001 */ 	addiu	$v1,$v1,0x1
.NB0f0dc8bc:
/*  f0dc8bc:	0068082a */ 	slt	$at,$v1,$t0
/*  f0dc8c0:	1420fff2 */ 	bnez	$at,.NB0f0dc88c
/*  f0dc8c4:	261001dc */ 	addiu	$s0,$s0,0x1dc
.NB0f0dc8c8:
/*  f0dc8c8:	3c168007 */ 	lui	$s6,0x8007
/*  f0dc8cc:	3c12800a */ 	lui	$s2,0x800a
/*  f0dc8d0:	26d636ac */ 	addiu	$s6,$s6,0x36ac
/*  f0dc8d4:	2652e6c0 */ 	addiu	$s2,$s2,-6464
/*  f0dc8d8:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f0dc8dc:	24150003 */ 	addiu	$s5,$zero,0x3
/*  f0dc8e0:	2414000b */ 	addiu	$s4,$zero,0xb
/*  f0dc8e4:	24130004 */ 	addiu	$s3,$zero,0x4
.NB0f0dc8e8:
/*  f0dc8e8:	0fc36d31 */ 	jal	hudmsgGetNext
/*  f0dc8ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dc8f0:	04400136 */ 	bltz	$v0,.NB0f0dcdcc
/*  f0dc8f4:	00025100 */ 	sll	$t2,$v0,0x4
/*  f0dc8f8:	01425023 */ 	subu	$t2,$t2,$v0
/*  f0dc8fc:	8ecb0000 */ 	lw	$t3,0x0($s6)
/*  f0dc900:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f0dc904:	01425023 */ 	subu	$t2,$t2,$v0
/*  f0dc908:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0dc90c:	014b8021 */ 	addu	$s0,$t2,$t3
/*  f0dc910:	8e0c01b8 */ 	lw	$t4,0x1b8($s0)
/*  f0dc914:	240d00ff */ 	addiu	$t5,$zero,0xff
/*  f0dc918:	afac0060 */ 	sw	$t4,0x60($sp)
/*  f0dc91c:	8e0401b0 */ 	lw	$a0,0x1b0($s0)
/*  f0dc920:	04820006 */ 	bltzl	$a0,.NB0f0dc93c
/*  f0dc924:	a20d0004 */ 	sb	$t5,0x4($s0)
/*  f0dc928:	0fc24471 */ 	jal	propsndGetSubtitleOpacity
/*  f0dc92c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dc930:	10000002 */ 	beqz	$zero,.NB0f0dc93c
/*  f0dc934:	a2020004 */ 	sb	$v0,0x4($s0)
/*  f0dc938:	a20d0004 */ 	sb	$t5,0x4($s0)
.NB0f0dc93c:
/*  f0dc93c:	8e0e01b4 */ 	lw	$t6,0x1b4($s0)
/*  f0dc940:	568e0008 */ 	bnel	$s4,$t6,.NB0f0dc964
/*  f0dc944:	92180000 */ 	lbu	$t8,0x0($s0)
/*  f0dc948:	8e4f02ac */ 	lw	$t7,0x2ac($s2)
/*  f0dc94c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0dc950:	51e10004 */ 	beql	$t7,$at,.NB0f0dc964
/*  f0dc954:	92180000 */ 	lbu	$t8,0x0($s0)
/*  f0dc958:	a2000000 */ 	sb	$zero,0x0($s0)
/*  f0dc95c:	a6000006 */ 	sh	$zero,0x6($s0)
/*  f0dc960:	92180000 */ 	lbu	$t8,0x0($s0)
.NB0f0dc964:
/*  f0dc964:	2f010006 */ 	sltiu	$at,$t8,0x6
/*  f0dc968:	10200116 */ 	beqz	$at,.NB0f0dcdc4
/*  f0dc96c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0dc970:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0dc974:	00380821 */ 	addu	$at,$at,$t8
/*  f0dc978:	8c3881f4 */ 	lw	$t8,-0x7e0c($at)
/*  f0dc97c:	03000008 */ 	jr	$t8
/*  f0dc980:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dc984:	8e1901c0 */ 	lw	$t9,0x1c0($s0)
/*  f0dc988:	02204825 */ 	or	$t1,$s1,$zero
/*  f0dc98c:	3c088007 */ 	lui	$t0,0x8007
/*  f0dc990:	00195080 */ 	sll	$t2,$t9,0x2
/*  f0dc994:	024a5821 */ 	addu	$t3,$s2,$t2
/*  f0dc998:	8d6c0064 */ 	lw	$t4,0x64($t3)
/*  f0dc99c:	8d8d00d8 */ 	lw	$t5,0xd8($t4)
/*  f0dc9a0:	11a00002 */ 	beqz	$t5,.NB0f0dc9ac
/*  f0dc9a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dc9a8:	00004825 */ 	or	$t1,$zero,$zero
.NB0f0dc9ac:
/*  f0dc9ac:	1120003e */ 	beqz	$t1,.NB0f0dcaa8
/*  f0dc9b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dc9b4:	8d0836a8 */ 	lw	$t0,0x36a8($t0)
/*  f0dc9b8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0dc9bc:	00003825 */ 	or	$a3,$zero,$zero
/*  f0dc9c0:	19000039 */ 	blez	$t0,.NB0f0dcaa8
/*  f0dc9c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dc9c8:	8ec20000 */ 	lw	$v0,0x0($s6)
.NB0f0dc9cc:
/*  f0dc9cc:	90460000 */ 	lbu	$a2,0x0($v0)
/*  f0dc9d0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0dc9d4:	50c00031 */ 	beqzl	$a2,.NB0f0dca9c
/*  f0dc9d8:	00a8082a */ 	slt	$at,$a1,$t0
/*  f0dc9dc:	5226002f */ 	beql	$s1,$a2,.NB0f0dca9c
/*  f0dc9e0:	00a8082a */ 	slt	$at,$a1,$t0
/*  f0dc9e4:	94430018 */ 	lhu	$v1,0x18($v0)
/*  f0dc9e8:	944e001c */ 	lhu	$t6,0x1c($v0)
/*  f0dc9ec:	96040018 */ 	lhu	$a0,0x18($s0)
/*  f0dc9f0:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f0dc9f4:	01e4082a */ 	slt	$at,$t7,$a0
/*  f0dc9f8:	54200028 */ 	bnezl	$at,.NB0f0dca9c
/*  f0dc9fc:	00a8082a */ 	slt	$at,$a1,$t0
/*  f0dca00:	9618001c */ 	lhu	$t8,0x1c($s0)
/*  f0dca04:	0098c821 */ 	addu	$t9,$a0,$t8
/*  f0dca08:	0323082a */ 	slt	$at,$t9,$v1
/*  f0dca0c:	54200023 */ 	bnezl	$at,.NB0f0dca9c
/*  f0dca10:	00a8082a */ 	slt	$at,$a1,$t0
/*  f0dca14:	9443001a */ 	lhu	$v1,0x1a($v0)
/*  f0dca18:	944a001e */ 	lhu	$t2,0x1e($v0)
/*  f0dca1c:	9604001a */ 	lhu	$a0,0x1a($s0)
/*  f0dca20:	01435821 */ 	addu	$t3,$t2,$v1
/*  f0dca24:	0164082a */ 	slt	$at,$t3,$a0
/*  f0dca28:	5420001c */ 	bnezl	$at,.NB0f0dca9c
/*  f0dca2c:	00a8082a */ 	slt	$at,$a1,$t0
/*  f0dca30:	960c001e */ 	lhu	$t4,0x1e($s0)
/*  f0dca34:	008c6821 */ 	addu	$t5,$a0,$t4
/*  f0dca38:	01a3082a */ 	slt	$at,$t5,$v1
/*  f0dca3c:	54200017 */ 	bnezl	$at,.NB0f0dca9c
/*  f0dca40:	00a8082a */ 	slt	$at,$a1,$t0
/*  f0dca44:	8e0e01b4 */ 	lw	$t6,0x1b4($s0)
/*  f0dca48:	8c4f01b4 */ 	lw	$t7,0x1b4($v0)
/*  f0dca4c:	00004825 */ 	or	$t1,$zero,$zero
/*  f0dca50:	15cf0015 */ 	bne	$t6,$t7,.NB0f0dcaa8
/*  f0dca54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dca58:	92180001 */ 	lbu	$t8,0x1($s0)
/*  f0dca5c:	13000012 */ 	beqz	$t8,.NB0f0dcaa8
/*  f0dca60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dca64:	90590001 */ 	lbu	$t9,0x1($v0)
/*  f0dca68:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0dca6c:	1320000e */ 	beqz	$t9,.NB0f0dcaa8
/*  f0dca70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dca74:	14c1000c */ 	bne	$a2,$at,.NB0f0dcaa8
/*  f0dca78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dca7c:	a0400000 */ 	sb	$zero,0x0($v0)
/*  f0dca80:	8eca0000 */ 	lw	$t2,0x0($s6)
/*  f0dca84:	01475821 */ 	addu	$t3,$t2,$a3
/*  f0dca88:	a5600006 */ 	sh	$zero,0x6($t3)
/*  f0dca8c:	a2150000 */ 	sb	$s5,0x0($s0)
/*  f0dca90:	10000005 */ 	beqz	$zero,.NB0f0dcaa8
/*  f0dca94:	a6000006 */ 	sh	$zero,0x6($s0)
/*  f0dca98:	00a8082a */ 	slt	$at,$a1,$t0
.NB0f0dca9c:
/*  f0dca9c:	24e701dc */ 	addiu	$a3,$a3,0x1dc
/*  f0dcaa0:	1420ffca */ 	bnez	$at,.NB0f0dc9cc
/*  f0dcaa4:	244201dc */ 	addiu	$v0,$v0,0x1dc
.NB0f0dcaa8:
/*  f0dcaa8:	112000c6 */ 	beqz	$t1,.NB0f0dcdc4
/*  f0dcaac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcab0:	920c0001 */ 	lbu	$t4,0x1($s0)
/*  f0dcab4:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f0dcab8:	51800004 */ 	beqzl	$t4,.NB0f0dcacc
/*  f0dcabc:	920e0002 */ 	lbu	$t6,0x2($s0)
/*  f0dcac0:	10000007 */ 	beqz	$zero,.NB0f0dcae0
/*  f0dcac4:	a20d0000 */ 	sb	$t5,0x0($s0)
/*  f0dcac8:	920e0002 */ 	lbu	$t6,0x2($s0)
.NB0f0dcacc:
/*  f0dcacc:	51c00004 */ 	beqzl	$t6,.NB0f0dcae0
/*  f0dcad0:	a2130000 */ 	sb	$s3,0x0($s0)
/*  f0dcad4:	10000002 */ 	beqz	$zero,.NB0f0dcae0
/*  f0dcad8:	a2150000 */ 	sb	$s5,0x0($s0)
/*  f0dcadc:	a2130000 */ 	sb	$s3,0x0($s0)
.NB0f0dcae0:
/*  f0dcae0:	8e0f01b4 */ 	lw	$t7,0x1b4($s0)
/*  f0dcae4:	a6000006 */ 	sh	$zero,0x6($s0)
/*  f0dcae8:	168f00b6 */ 	bne	$s4,$t7,.NB0f0dcdc4
/*  f0dcaec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcaf0:	100000b4 */ 	beqz	$zero,.NB0f0dcdc4
/*  f0dcaf4:	a2130000 */ 	sb	$s3,0x0($s0)
/*  f0dcaf8:	92180001 */ 	lbu	$t8,0x1($s0)
/*  f0dcafc:	53000007 */ 	beqzl	$t8,.NB0f0dcb1c
/*  f0dcb00:	a2130000 */ 	sb	$s3,0x0($s0)
/*  f0dcb04:	92190002 */ 	lbu	$t9,0x2($s0)
/*  f0dcb08:	53200004 */ 	beqzl	$t9,.NB0f0dcb1c
/*  f0dcb0c:	a2130000 */ 	sb	$s3,0x0($s0)
/*  f0dcb10:	10000002 */ 	beqz	$zero,.NB0f0dcb1c
/*  f0dcb14:	a2150000 */ 	sb	$s5,0x0($s0)
/*  f0dcb18:	a2130000 */ 	sb	$s3,0x0($s0)
.NB0f0dcb1c:
/*  f0dcb1c:	8e0a01b4 */ 	lw	$t2,0x1b4($s0)
/*  f0dcb20:	168a0002 */ 	bne	$s4,$t2,.NB0f0dcb2c
/*  f0dcb24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcb28:	a2130000 */ 	sb	$s3,0x0($s0)
.NB0f0dcb2c:
/*  f0dcb2c:	100000a5 */ 	beqz	$zero,.NB0f0dcdc4
/*  f0dcb30:	a6000006 */ 	sh	$zero,0x6($s0)
/*  f0dcb34:	8e0b01b4 */ 	lw	$t3,0x1b4($s0)
/*  f0dcb38:	568b0005 */ 	bnel	$s4,$t3,.NB0f0dcb50
/*  f0dcb3c:	960c0006 */ 	lhu	$t4,0x6($s0)
/*  f0dcb40:	a2130000 */ 	sb	$s3,0x0($s0)
/*  f0dcb44:	1000009f */ 	beqz	$zero,.NB0f0dcdc4
/*  f0dcb48:	a6000006 */ 	sh	$zero,0x6($s0)
/*  f0dcb4c:	960c0006 */ 	lhu	$t4,0x6($s0)
.NB0f0dcb50:
/*  f0dcb50:	55800033 */ 	bnezl	$t4,.NB0f0dcc20
/*  f0dcb54:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0dcb58:	0fc59ed0 */ 	jal	lvIsPaused
/*  f0dcb5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcb60:	5440002f */ 	bnezl	$v0,.NB0f0dcc20
/*  f0dcb64:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0dcb68:	0fc60e8c */ 	jal	mpIsPaused
/*  f0dcb6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcb70:	5440002b */ 	bnezl	$v0,.NB0f0dcc20
/*  f0dcb74:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0dcb78:	8e4d006c */ 	lw	$t5,0x6c($s2)
/*  f0dcb7c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0dcb80:	00001825 */ 	or	$v1,$zero,$zero
/*  f0dcb84:	11a00003 */ 	beqz	$t5,.NB0f0dcb94
/*  f0dcb88:	00002025 */ 	or	$a0,$zero,$zero
/*  f0dcb8c:	10000001 */ 	beqz	$zero,.NB0f0dcb94
/*  f0dcb90:	02202825 */ 	or	$a1,$s1,$zero
.NB0f0dcb94:
/*  f0dcb94:	8e4e0068 */ 	lw	$t6,0x68($s2)
/*  f0dcb98:	3c068007 */ 	lui	$a2,0x8007
/*  f0dcb9c:	00001025 */ 	or	$v0,$zero,$zero
/*  f0dcba0:	11c00003 */ 	beqz	$t6,.NB0f0dcbb0
/*  f0dcba4:	24c636b0 */ 	addiu	$a2,$a2,0x36b0
/*  f0dcba8:	10000001 */ 	beqz	$zero,.NB0f0dcbb0
/*  f0dcbac:	02201825 */ 	or	$v1,$s1,$zero
.NB0f0dcbb0:
/*  f0dcbb0:	8e4f0064 */ 	lw	$t7,0x64($s2)
/*  f0dcbb4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0dcbb8:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0dcbbc:	11e00003 */ 	beqz	$t7,.NB0f0dcbcc
/*  f0dcbc0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0dcbc4:	10000001 */ 	beqz	$zero,.NB0f0dcbcc
/*  f0dcbc8:	02202025 */ 	or	$a0,$s1,$zero
.NB0f0dcbcc:
/*  f0dcbcc:	8e580070 */ 	lw	$t8,0x70($s2)
/*  f0dcbd0:	240dffff */ 	addiu	$t5,$zero,-1
/*  f0dcbd4:	240effff */ 	addiu	$t6,$zero,-1
/*  f0dcbd8:	13000003 */ 	beqz	$t8,.NB0f0dcbe8
/*  f0dcbdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcbe0:	10000001 */ 	beqz	$zero,.NB0f0dcbe8
/*  f0dcbe4:	02201025 */ 	or	$v0,$s1,$zero
.NB0f0dcbe8:
/*  f0dcbe8:	0044c821 */ 	addu	$t9,$v0,$a0
/*  f0dcbec:	03235021 */ 	addu	$t2,$t9,$v1
/*  f0dcbf0:	01455821 */ 	addu	$t3,$t2,$a1
/*  f0dcbf4:	162b0009 */ 	bne	$s1,$t3,.NB0f0dcc1c
/*  f0dcbf8:	3c04800a */ 	lui	$a0,0x800a
/*  f0dcbfc:	44812000 */ 	mtc1	$at,$f4
/*  f0dcc00:	8c848180 */ 	lw	$a0,-0x7e80($a0)
/*  f0dcc04:	2405003e */ 	addiu	$a1,$zero,0x3e
/*  f0dcc08:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0dcc0c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0dcc10:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0dcc14:	0c004338 */ 	jal	sndStart
/*  f0dcc18:	e7a40014 */ 	swc1	$f4,0x14($sp)
.NB0f0dcc1c:
/*  f0dcc1c:	9602001c */ 	lhu	$v0,0x1c($s0)
.NB0f0dcc20:
/*  f0dcc20:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0dcc24:	00420019 */ 	multu	$v0,$v0
/*  f0dcc28:	00007812 */ 	mflo	$t7
/*  f0dcc2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcc30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcc34:	00630019 */ 	multu	$v1,$v1
/*  f0dcc38:	0000c012 */ 	mflo	$t8
/*  f0dcc3c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0dcc40:	44993000 */ 	mtc1	$t9,$f6
/*  f0dcc44:	0c012e84 */ 	jal	sqrtf
/*  f0dcc48:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f0dcc4c:	3c014304 */ 	lui	$at,0x4304
/*  f0dcc50:	44814000 */ 	mtc1	$at,$f8
/*  f0dcc54:	3c0140e0 */ 	lui	$at,0x40e0
/*  f0dcc58:	44818000 */ 	mtc1	$at,$f16
/*  f0dcc5c:	46080280 */ 	add.s	$f10,$f0,$f8
/*  f0dcc60:	960a0006 */ 	lhu	$t2,0x6($s0)
/*  f0dcc64:	8e4b0038 */ 	lw	$t3,0x38($s2)
/*  f0dcc68:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f0dcc6c:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f0dcc70:	318dffff */ 	andi	$t5,$t4,0xffff
/*  f0dcc74:	a60c0006 */ 	sh	$t4,0x6($s0)
/*  f0dcc78:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0dcc7c:	440f2000 */ 	mfc1	$t7,$f4
/*  f0dcc80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcc84:	01af082a */ 	slt	$at,$t5,$t7
/*  f0dcc88:	50200005 */ 	beqzl	$at,.NB0f0dcca0
/*  f0dcc8c:	a2130000 */ 	sb	$s3,0x0($s0)
/*  f0dcc90:	8e1801b4 */ 	lw	$t8,0x1b4($s0)
/*  f0dcc94:	1698004b */ 	bne	$s4,$t8,.NB0f0dcdc4
/*  f0dcc98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcc9c:	a2130000 */ 	sb	$s3,0x0($s0)
.NB0f0dcca0:
/*  f0dcca0:	10000048 */ 	beqz	$zero,.NB0f0dcdc4
/*  f0dcca4:	a6000006 */ 	sh	$zero,0x6($s0)
/*  f0dcca8:	96190006 */ 	lhu	$t9,0x6($s0)
/*  f0dccac:	8e4a0038 */ 	lw	$t2,0x38($s2)
/*  f0dccb0:	8e0401b0 */ 	lw	$a0,0x1b0($s0)
/*  f0dccb4:	00001825 */ 	or	$v1,$zero,$zero
/*  f0dccb8:	032a5821 */ 	addu	$t3,$t9,$t2
/*  f0dccbc:	0480000f */ 	bltz	$a0,.NB0f0dccfc
/*  f0dccc0:	a60b0006 */ 	sh	$t3,0x6($s0)
/*  f0dccc4:	0fc249bf */ 	jal	audioIsChannelIdle
/*  f0dccc8:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f0dcccc:	10400003 */ 	beqz	$v0,.NB0f0dccdc
/*  f0dccd0:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0dccd4:	10000011 */ 	beqz	$zero,.NB0f0dcd1c
/*  f0dccd8:	02201825 */ 	or	$v1,$s1,$zero
.NB0f0dccdc:
/*  f0dccdc:	8e0201c4 */ 	lw	$v0,0x1c4($s0)
/*  f0dcce0:	2401fffd */ 	addiu	$at,$zero,-3
/*  f0dcce4:	304c0002 */ 	andi	$t4,$v0,0x2
/*  f0dcce8:	1180000c */ 	beqz	$t4,.NB0f0dcd1c
/*  f0dccec:	00417024 */ 	and	$t6,$v0,$at
/*  f0dccf0:	ae0e01c4 */ 	sw	$t6,0x1c4($s0)
/*  f0dccf4:	10000009 */ 	beqz	$zero,.NB0f0dcd1c
/*  f0dccf8:	02201825 */ 	or	$v1,$s1,$zero
.NB0f0dccfc:
/*  f0dccfc:	8e0201bc */ 	lw	$v0,0x1bc($s0)
/*  f0dcd00:	960d0006 */ 	lhu	$t5,0x6($s0)
/*  f0dcd04:	01a2082a */ 	slt	$at,$t5,$v0
/*  f0dcd08:	14200004 */ 	bnez	$at,.NB0f0dcd1c
/*  f0dcd0c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0dcd10:	10410002 */ 	beq	$v0,$at,.NB0f0dcd1c
/*  f0dcd14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcd18:	02201825 */ 	or	$v1,$s1,$zero
.NB0f0dcd1c:
/*  f0dcd1c:	10600029 */ 	beqz	$v1,.NB0f0dcdc4
/*  f0dcd20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcd24:	920f0001 */ 	lbu	$t7,0x1($s0)
/*  f0dcd28:	24180005 */ 	addiu	$t8,$zero,0x5
/*  f0dcd2c:	51e00004 */ 	beqzl	$t7,.NB0f0dcd40
/*  f0dcd30:	a2000000 */ 	sb	$zero,0x0($s0)
/*  f0dcd34:	10000002 */ 	beqz	$zero,.NB0f0dcd40
/*  f0dcd38:	a2180000 */ 	sb	$t8,0x0($s0)
/*  f0dcd3c:	a2000000 */ 	sb	$zero,0x0($s0)
.NB0f0dcd40:
/*  f0dcd40:	10000020 */ 	beqz	$zero,.NB0f0dcdc4
/*  f0dcd44:	a6000006 */ 	sh	$zero,0x6($s0)
/*  f0dcd48:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0dcd4c:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0dcd50:	00420019 */ 	multu	$v0,$v0
/*  f0dcd54:	0000c812 */ 	mflo	$t9
/*  f0dcd58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcd5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcd60:	00630019 */ 	multu	$v1,$v1
/*  f0dcd64:	00005012 */ 	mflo	$t2
/*  f0dcd68:	032a5821 */ 	addu	$t3,$t9,$t2
/*  f0dcd6c:	448b3000 */ 	mtc1	$t3,$f6
/*  f0dcd70:	0c012e84 */ 	jal	sqrtf
/*  f0dcd74:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f0dcd78:	3c0142b8 */ 	lui	$at,0x42b8
/*  f0dcd7c:	44814000 */ 	mtc1	$at,$f8
/*  f0dcd80:	3c0140e0 */ 	lui	$at,0x40e0
/*  f0dcd84:	44818000 */ 	mtc1	$at,$f16
/*  f0dcd88:	46080280 */ 	add.s	$f10,$f0,$f8
/*  f0dcd8c:	960c0006 */ 	lhu	$t4,0x6($s0)
/*  f0dcd90:	8e4e0038 */ 	lw	$t6,0x38($s2)
/*  f0dcd94:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f0dcd98:	018e6821 */ 	addu	$t5,$t4,$t6
/*  f0dcd9c:	31afffff */ 	andi	$t7,$t5,0xffff
/*  f0dcda0:	a60d0006 */ 	sh	$t5,0x6($s0)
/*  f0dcda4:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0dcda8:	44192000 */ 	mfc1	$t9,$f4
/*  f0dcdac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcdb0:	01f9082a */ 	slt	$at,$t7,$t9
/*  f0dcdb4:	14200003 */ 	bnez	$at,.NB0f0dcdc4
/*  f0dcdb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcdbc:	a2000000 */ 	sb	$zero,0x0($s0)
/*  f0dcdc0:	a6000006 */ 	sh	$zero,0x6($s0)
.NB0f0dcdc4:
/*  f0dcdc4:	1000fec8 */ 	beqz	$zero,.NB0f0dc8e8
/*  f0dcdc8:	8fa40060 */ 	lw	$a0,0x60($sp)
.NB0f0dcdcc:
/*  f0dcdcc:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0dcdd0:	3c018008 */ 	lui	$at,0x8008
/*  f0dcdd4:	ac312320 */ 	sw	$s1,0x2320($at)
/*  f0dcdd8:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f0dcddc:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0dcde0:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f0dcde4:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f0dcde8:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f0dcdec:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f0dcdf0:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f0dcdf4:	03e00008 */ 	jr	$ra
/*  f0dcdf8:	27bd0068 */ 	addiu	$sp,$sp,0x68
);
#endif

void currentPlayerSetHudmsgsOn(u32 reason)
{
	g_Vars.currentplayer->hudmessoff &= ~reason;
}

void currentPlayerSetHudmsgsOff(u32 reason)
{
	g_Vars.currentplayer->hudmessoff |= reason;
}

void hudmsgRemoveForDeadPlayer(s32 playernum)
{
	s32 i;

	for (i = 0; i < g_NumHudMessages; i++) {
		if (g_HudMessages[i].state
				&& g_HudMessages[i].playernum == playernum
				&& (g_HudMessages[i].flags & HUDMSGFLAG_ONLYIFALIVE)) {
			g_HudMessages[i].state = HUDMSGSTATE_FREE;
			g_HudMessages[i].timer = 0;
		}
	}
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel hudmsgsRender
.late_rodata
glabel var7f1af1c4
.word 0x41066667
glabel var7f1af1c8
.word 0x40490fdb
glabel var7f1af1cc
.word 0x7f0e0b40
glabel var7f1af1d0
.word 0x7f0e0b40
glabel var7f1af1d4
.word 0x7f0e0b40
glabel var7f1af1d8
.word 0x7f0e04f8
glabel var7f1af1dc
.word 0x7f0e0750
glabel var7f1af1e0
.word 0x7f0e08d4
.text
/*  f0e012c:	27bdff00 */ 	addiu	$sp,$sp,-256
/*  f0e0130:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f0e0134:	240e00ff */ 	li	$t6,0xff
/*  f0e0138:	240f0001 */ 	li	$t7,0x1
/*  f0e013c:	24180001 */ 	li	$t8,0x1
/*  f0e0140:	3c018008 */ 	lui	$at,0x8008
/*  f0e0144:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f0e0148:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f0e014c:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f0e0150:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f0e0154:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f0e0158:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f0e015c:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0e0160:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f0e0164:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f0e0168:	f7ba0050 */ 	sdc1	$f26,0x50($sp)
/*  f0e016c:	f7b80048 */ 	sdc1	$f24,0x48($sp)
/*  f0e0170:	f7b60040 */ 	sdc1	$f22,0x40($sp)
/*  f0e0174:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f0e0178:	afae00e0 */ 	sw	$t6,0xe0($sp)
/*  f0e017c:	afaf00dc */ 	sw	$t7,0xdc($sp)
/*  f0e0180:	0fc550cf */ 	jal	func0f153628
/*  f0e0184:	ac380020 */ 	sw	$t8,0x20($at)
/*  f0e0188:	3c19800a */ 	lui	$t9,0x800a
/*  f0e018c:	8f39a7a8 */ 	lw	$t9,-0x5858($t9)
/*  f0e0190:	00409025 */ 	move	$s2,$v0
/*  f0e0194:	3c048007 */ 	lui	$a0,0x8007
/*  f0e0198:	07210005 */ 	bgez	$t9,.PF0f0e01b0
/*  f0e019c:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0e01a0:	3c08800a */ 	lui	$t0,0x800a
/*  f0e01a4:	8d08a7ac */ 	lw	$t0,-0x5854($t0)
/*  f0e01a8:	0500000e */ 	bltz	$t0,.PF0f0e01e4
/*  f0e01ac:	00000000 */ 	nop
.PF0f0e01b0:
/*  f0e01b0:	3c098007 */ 	lui	$t1,0x8007
/*  f0e01b4:	8d290a44 */ 	lw	$t1,0xa44($t1)
/*  f0e01b8:	1120000a */ 	beqz	$t1,.PF0f0e01e4
/*  f0e01bc:	00000000 */ 	nop
/*  f0e01c0:	3c0a8006 */ 	lui	$t2,0x8006
/*  f0e01c4:	8d4ad670 */ 	lw	$t2,-0x2990($t2)
/*  f0e01c8:	15400006 */ 	bnez	$t2,.PF0f0e01e4
/*  f0e01cc:	00000000 */ 	nop
/*  f0e01d0:	3c0b800a */ 	lui	$t3,0x800a
/*  f0e01d4:	8d6ba79c */ 	lw	$t3,-0x5864($t3)
/*  f0e01d8:	15600002 */ 	bnez	$t3,.PF0f0e01e4
/*  f0e01dc:	00000000 */ 	nop
/*  f0e01e0:	afa000dc */ 	sw	$zero,0xdc($sp)
.PF0f0e01e4:
/*  f0e01e4:	8c8412c8 */ 	lw	$a0,0x12c8($a0)
/*  f0e01e8:	27b700e4 */ 	addiu	$s7,$sp,0xe4
/*  f0e01ec:	27b600e8 */ 	addiu	$s6,$sp,0xe8
/*  f0e01f0:	1880029b */ 	blez	$a0,.PF0f0e0c60
/*  f0e01f4:	2415ff00 */ 	li	$s5,-256
/*  f0e01f8:	4481d000 */ 	mtc1	$at,$f26
/*  f0e01fc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0e0200:	c438f1c4 */ 	lwc1	$f24,-0xe3c($at)
/*  f0e0204:	3c014080 */ 	lui	$at,0x4080
/*  f0e0208:	4481b000 */ 	mtc1	$at,$f22
/*  f0e020c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0e0210:	4481a000 */ 	mtc1	$at,$f20
/*  f0e0214:	afa00088 */ 	sw	$zero,0x88($sp)
/*  f0e0218:	241e00ff */ 	li	$s8,0xff
.PF0f0e021c:
/*  f0e021c:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0e0220:	8dad12cc */ 	lw	$t5,0x12cc($t5)
/*  f0e0224:	8fac0088 */ 	lw	$t4,0x88($sp)
/*  f0e0228:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0e022c:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e0230:	018d8021 */ 	addu	$s0,$t4,$t5
/*  f0e0234:	92030004 */ 	lbu	$v1,0x4($s0)
/*  f0e0238:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0e023c:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e0240:	54600004 */ 	bnezl	$v1,.PF0f0e0254
/*  f0e0244:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0e0248:	10000280 */ 	b	.PF0f0e0c4c
/*  f0e024c:	00021080 */ 	sll	$v0,$v0,0x2
/*  f0e0250:	92020000 */ 	lbu	$v0,0x0($s0)
.PF0f0e0254:
/*  f0e0254:	24010001 */ 	li	$at,0x1
/*  f0e0258:	5040000a */ 	beqzl	$v0,.PF0f0e0284
/*  f0e025c:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0e0260:	10410007 */ 	beq	$v0,$at,.PF0f0e0280
/*  f0e0264:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f0e0268:	51c0000c */ 	beqzl	$t6,.PF0f0e029c
/*  f0e026c:	92190003 */ 	lbu	$t9,0x3($s0)
/*  f0e0270:	3c0f800a */ 	lui	$t7,0x800a
/*  f0e0274:	8defa79c */ 	lw	$t7,-0x5864($t7)
/*  f0e0278:	8e1801c0 */ 	lw	$t8,0x1c0($s0)
/*  f0e027c:	11f80006 */ 	beq	$t7,$t8,.PF0f0e0298
.PF0f0e0280:
/*  f0e0280:	00041100 */ 	sll	$v0,$a0,0x4
.PF0f0e0284:
/*  f0e0284:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e0288:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0e028c:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e0290:	1000026e */ 	b	.PF0f0e0c4c
/*  f0e0294:	00021080 */ 	sll	$v0,$v0,0x2
.PF0f0e0298:
/*  f0e0298:	92190003 */ 	lbu	$t9,0x3($s0)
.PF0f0e029c:
/*  f0e029c:	53200022 */ 	beqzl	$t9,.PF0f0e0328
/*  f0e02a0:	8e130010 */ 	lw	$s3,0x10($s0)
/*  f0e02a4:	96080006 */ 	lhu	$t0,0x6($s0)
/*  f0e02a8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e02ac:	44882000 */ 	mtc1	$t0,$f4
/*  f0e02b0:	05010004 */ 	bgez	$t0,.PF0f0e02c4
/*  f0e02b4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e02b8:	44814000 */ 	mtc1	$at,$f8
/*  f0e02bc:	00000000 */ 	nop
/*  f0e02c0:	46083180 */ 	add.s	$f6,$f6,$f8
.PF0f0e02c4:
/*  f0e02c4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0e02c8:	c42af1c8 */ 	lwc1	$f10,-0xe38($at)
/*  f0e02cc:	3c014270 */ 	lui	$at,0x4270
/*  f0e02d0:	44819000 */ 	mtc1	$at,$f18
/*  f0e02d4:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0e02d8:	0c00685b */ 	jal	sinf
/*  f0e02dc:	46128303 */ 	div.s	$f12,$f16,$f18
/*  f0e02e0:	44802000 */ 	mtc1	$zero,$f4
/*  f0e02e4:	3c014340 */ 	lui	$at,0x4340
/*  f0e02e8:	44814000 */ 	mtc1	$at,$f8
/*  f0e02ec:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0e02f0:	46000086 */ 	mov.s	$f2,$f0
/*  f0e02f4:	45000002 */ 	bc1f	.PF0f0e0300
/*  f0e02f8:	00000000 */ 	nop
/*  f0e02fc:	46000087 */ 	neg.s	$f2,$f0
.PF0f0e0300:
/*  f0e0300:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0e0304:	8e090010 */ 	lw	$t1,0x10($s0)
/*  f0e0308:	8e140014 */ 	lw	$s4,0x14($s0)
/*  f0e030c:	92030004 */ 	lbu	$v1,0x4($s0)
/*  f0e0310:	01355024 */ 	and	$t2,$t1,$s5
/*  f0e0314:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f0e0318:	440c5000 */ 	mfc1	$t4,$f10
/*  f0e031c:	10000005 */ 	b	.PF0f0e0334
/*  f0e0320:	014c9821 */ 	addu	$s3,$t2,$t4
/*  f0e0324:	8e130010 */ 	lw	$s3,0x10($s0)
.PF0f0e0328:
/*  f0e0328:	8e140014 */ 	lw	$s4,0x14($s0)
/*  f0e032c:	366d00a0 */ 	ori	$t5,$s3,0xa0
/*  f0e0330:	01a09825 */ 	move	$s3,$t5
.PF0f0e0334:
/*  f0e0334:	240100ff */ 	li	$at,0xff
/*  f0e0338:	1061001c */ 	beq	$v1,$at,.PF0f0e03ac
/*  f0e033c:	00601025 */ 	move	$v0,$v1
/*  f0e0340:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f0e0344:	004e0019 */ 	multu	$v0,$t6
/*  f0e0348:	00401825 */ 	move	$v1,$v0
/*  f0e034c:	329800ff */ 	andi	$t8,$s4,0xff
/*  f0e0350:	02754024 */ 	and	$t0,$s3,$s5
/*  f0e0354:	02955824 */ 	and	$t3,$s4,$s5
/*  f0e0358:	00007812 */ 	mflo	$t7
/*  f0e035c:	00000000 */ 	nop
/*  f0e0360:	00000000 */ 	nop
/*  f0e0364:	01fe001b */ 	divu	$zero,$t7,$s8
/*  f0e0368:	00002012 */ 	mflo	$a0
/*  f0e036c:	308900ff */ 	andi	$t1,$a0,0xff
/*  f0e0370:	17c00002 */ 	bnez	$s8,.PF0f0e037c
/*  f0e0374:	00000000 */ 	nop
/*  f0e0378:	0007000d */ 	break	0x7
.PF0f0e037c:
/*  f0e037c:	00780019 */ 	multu	$v1,$t8
/*  f0e0380:	01099821 */ 	addu	$s3,$t0,$t1
/*  f0e0384:	0000c812 */ 	mflo	$t9
/*  f0e0388:	00000000 */ 	nop
/*  f0e038c:	00000000 */ 	nop
/*  f0e0390:	033e001b */ 	divu	$zero,$t9,$s8
/*  f0e0394:	00002812 */ 	mflo	$a1
/*  f0e0398:	30aa00ff */ 	andi	$t2,$a1,0xff
/*  f0e039c:	17c00002 */ 	bnez	$s8,.PF0f0e03a8
/*  f0e03a0:	00000000 */ 	nop
/*  f0e03a4:	0007000d */ 	break	0x7
.PF0f0e03a8:
/*  f0e03a8:	016aa021 */ 	addu	$s4,$t3,$t2
.PF0f0e03ac:
/*  f0e03ac:	960c0018 */ 	lhu	$t4,0x18($s0)
/*  f0e03b0:	24010006 */ 	li	$at,0x6
/*  f0e03b4:	afac00e8 */ 	sw	$t4,0xe8($sp)
/*  f0e03b8:	960d001a */ 	lhu	$t5,0x1a($s0)
/*  f0e03bc:	afad00e4 */ 	sw	$t5,0xe4($sp)
/*  f0e03c0:	8e0e01b4 */ 	lw	$t6,0x1b4($s0)
/*  f0e03c4:	55c10011 */ 	bnel	$t6,$at,.PF0f0e040c
/*  f0e03c8:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
/*  f0e03cc:	0fc3074e */ 	jal	currentPlayerIsHealthVisible
/*  f0e03d0:	00000000 */ 	nop
/*  f0e03d4:	5040000d */ 	beqzl	$v0,.PF0f0e040c
/*  f0e03d8:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
/*  f0e03dc:	0fc30718 */ 	jal	currentPlayerGetHealthBarHeightFrac
/*  f0e03e0:	00000000 */ 	nop
/*  f0e03e4:	3c014180 */ 	lui	$at,0x4180
/*  f0e03e8:	44818000 */ 	mtc1	$at,$f16
/*  f0e03ec:	8faf00e4 */ 	lw	$t7,0xe4($sp)
/*  f0e03f0:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0e03f4:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e03f8:	44192000 */ 	mfc1	$t9,$f4
/*  f0e03fc:	00000000 */ 	nop
/*  f0e0400:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f0e0404:	afa800e4 */ 	sw	$t0,0xe4($sp)
/*  f0e0408:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
.PF0f0e040c:
/*  f0e040c:	2401000b */ 	li	$at,0xb
/*  f0e0410:	55210031 */ 	bnel	$t1,$at,.PF0f0e04d8
/*  f0e0414:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f0e0418:	8fab00e8 */ 	lw	$t3,0xe8($sp)
/*  f0e041c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0e0420:	8d8c0020 */ 	lw	$t4,0x20($t4)
/*  f0e0424:	256afffc */ 	addiu	$t2,$t3,-4
/*  f0e0428:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e042c:	014c0019 */ 	multu	$t2,$t4
/*  f0e0430:	02408825 */ 	move	$s1,$s2
/*  f0e0434:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e0438:	00006812 */ 	mflo	$t5
/*  f0e043c:	448d4000 */ 	mtc1	$t5,$f8
/*  f0e0440:	00000000 */ 	nop
/*  f0e0444:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0e0448:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f0e044c:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e0450:	44188000 */ 	mfc1	$t8,$f16
/*  f0e0454:	00000000 */ 	nop
/*  f0e0458:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f0e045c:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f0e0460:	03214025 */ 	or	$t0,$t9,$at
/*  f0e0464:	0c002e46 */ 	jal	viGetBufY
/*  f0e0468:	ae280000 */ 	sw	$t0,0x0($s1)
/*  f0e046c:	8fa900e8 */ 	lw	$t1,0xe8($sp)
/*  f0e0470:	960b001c */ 	lhu	$t3,0x1c($s0)
/*  f0e0474:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0e0478:	8dad0020 */ 	lw	$t5,0x20($t5)
/*  f0e047c:	012b5021 */ 	addu	$t2,$t1,$t3
/*  f0e0480:	254c0003 */ 	addiu	$t4,$t2,0x3
/*  f0e0484:	018d0019 */ 	multu	$t4,$t5
/*  f0e0488:	44825000 */ 	mtc1	$v0,$f10
/*  f0e048c:	00000000 */ 	nop
/*  f0e0490:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0e0494:	00007012 */ 	mflo	$t6
/*  f0e0498:	448e9000 */ 	mtc1	$t6,$f18
/*  f0e049c:	00000000 */ 	nop
/*  f0e04a0:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0e04a4:	46162202 */ 	mul.s	$f8,$f4,$f22
/*  f0e04a8:	00000000 */ 	nop
/*  f0e04ac:	46168482 */ 	mul.s	$f18,$f16,$f22
/*  f0e04b0:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f0e04b4:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e04b8:	440f3000 */ 	mfc1	$t7,$f6
/*  f0e04bc:	440b2000 */ 	mfc1	$t3,$f4
/*  f0e04c0:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f0e04c4:	00194300 */ 	sll	$t0,$t9,0xc
/*  f0e04c8:	316a0fff */ 	andi	$t2,$t3,0xfff
/*  f0e04cc:	01486025 */ 	or	$t4,$t2,$t0
/*  f0e04d0:	ae2c0004 */ 	sw	$t4,0x4($s1)
/*  f0e04d4:	920d0000 */ 	lbu	$t5,0x0($s0)
.PF0f0e04d8:
/*  f0e04d8:	2da10006 */ 	sltiu	$at,$t5,0x6
/*  f0e04dc:	10200198 */ 	beqz	$at,.PF0f0e0b40
/*  f0e04e0:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0e04e4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0e04e8:	002d0821 */ 	addu	$at,$at,$t5
/*  f0e04ec:	8c2df1cc */ 	lw	$t5,-0xe34($at)
/*  f0e04f0:	01a00008 */ 	jr	$t5
/*  f0e04f4:	00000000 */ 	nop
/*  f0e04f8:	8e110010 */ 	lw	$s1,0x10($s0)
/*  f0e04fc:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0e0500:	240100ff */ 	li	$at,0xff
/*  f0e0504:	362e0040 */ 	ori	$t6,$s1,0x40
/*  f0e0508:	1041000e */ 	beq	$v0,$at,.PF0f0e0544
/*  f0e050c:	01c08825 */ 	move	$s1,$t6
/*  f0e0510:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f0e0514:	00580019 */ 	multu	$v0,$t8
/*  f0e0518:	0235c824 */ 	and	$t9,$s1,$s5
/*  f0e051c:	00007812 */ 	mflo	$t7
/*  f0e0520:	00000000 */ 	nop
/*  f0e0524:	00000000 */ 	nop
/*  f0e0528:	01fe001b */ 	divu	$zero,$t7,$s8
/*  f0e052c:	00001812 */ 	mflo	$v1
/*  f0e0530:	306900ff */ 	andi	$t1,$v1,0xff
/*  f0e0534:	17c00002 */ 	bnez	$s8,.PF0f0e0540
/*  f0e0538:	00000000 */ 	nop
/*  f0e053c:	0007000d */ 	break	0x7
.PF0f0e0540:
/*  f0e0540:	03298821 */ 	addu	$s1,$t9,$t1
.PF0f0e0544:
/*  f0e0544:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0e0548:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0e054c:	00420019 */ 	multu	$v0,$v0
/*  f0e0550:	00005812 */ 	mflo	$t3
/*  f0e0554:	00000000 */ 	nop
/*  f0e0558:	00000000 */ 	nop
/*  f0e055c:	00630019 */ 	multu	$v1,$v1
/*  f0e0560:	00005012 */ 	mflo	$t2
/*  f0e0564:	016a4021 */ 	addu	$t0,$t3,$t2
/*  f0e0568:	44884000 */ 	mtc1	$t0,$f8
/*  f0e056c:	0c0127b4 */ 	jal	sqrtf
/*  f0e0570:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f0e0574:	3c014304 */ 	lui	$at,0x4304
/*  f0e0578:	44813000 */ 	mtc1	$at,$f6
/*  f0e057c:	44802000 */ 	mtc1	$zero,$f4
/*  f0e0580:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e0584:	46060280 */ 	add.s	$f10,$f0,$f6
/*  f0e0588:	46185083 */ 	div.s	$f2,$f10,$f24
/*  f0e058c:	4602d03c */ 	c.lt.s	$f26,$f2
/*  f0e0590:	00000000 */ 	nop
/*  f0e0594:	45020003 */ 	bc1fl	.PF0f0e05a4
/*  f0e0598:	960c0006 */ 	lhu	$t4,0x6($s0)
/*  f0e059c:	4600d086 */ 	mov.s	$f2,$f26
/*  f0e05a0:	960c0006 */ 	lhu	$t4,0x6($s0)
.PF0f0e05a4:
/*  f0e05a4:	448c8000 */ 	mtc1	$t4,$f16
/*  f0e05a8:	05810004 */ 	bgez	$t4,.PF0f0e05bc
/*  f0e05ac:	46808320 */ 	cvt.s.w	$f12,$f16
/*  f0e05b0:	44819000 */ 	mtc1	$at,$f18
/*  f0e05b4:	00000000 */ 	nop
/*  f0e05b8:	46126300 */ 	add.s	$f12,$f12,$f18
.PF0f0e05bc:
/*  f0e05bc:	46026083 */ 	div.s	$f2,$f12,$f2
/*  f0e05c0:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f0e05c4:	8fa500e4 */ 	lw	$a1,0xe4($sp)
/*  f0e05c8:	00003825 */ 	move	$a3,$zero
/*  f0e05cc:	46186002 */ 	mul.s	$f0,$f12,$f24
/*  f0e05d0:	44060000 */ 	mfc1	$a2,$f0
/*  f0e05d4:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f0e05d8:	00000000 */ 	nop
/*  f0e05dc:	45020003 */ 	bc1fl	.PF0f0e05ec
/*  f0e05e0:	4604103c */ 	c.lt.s	$f2,$f4
/*  f0e05e4:	4600a086 */ 	mov.s	$f2,$f20
/*  f0e05e8:	4604103c */ 	c.lt.s	$f2,$f4
.PF0f0e05ec:
/*  f0e05ec:	00000000 */ 	nop
/*  f0e05f0:	45000003 */ 	bc1f	.PF0f0e0600
/*  f0e05f4:	00000000 */ 	nop
/*  f0e05f8:	44801000 */ 	mtc1	$zero,$f2
/*  f0e05fc:	00000000 */ 	nop
.PF0f0e0600:
/*  f0e0600:	0fc5524d */ 	jal	func0f153c20
/*  f0e0604:	e7a200c0 */ 	swc1	$f2,0xc0($sp)
/*  f0e0608:	920d0001 */ 	lbu	$t5,0x1($s0)
/*  f0e060c:	c7a200c0 */ 	lwc1	$f2,0xc0($sp)
/*  f0e0610:	02402025 */ 	move	$a0,$s2
/*  f0e0614:	11a00027 */ 	beqz	$t5,.PF0f0e06b4
/*  f0e0618:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0e061c:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0e0620:	9619001e */ 	lhu	$t9,0x1e($s0)
/*  f0e0624:	8fae00e8 */ 	lw	$t6,0xe8($sp)
/*  f0e0628:	960f001c */ 	lhu	$t7,0x1c($s0)
/*  f0e062c:	03384821 */ 	addu	$t1,$t9,$t8
/*  f0e0630:	252b0002 */ 	addiu	$t3,$t1,0x2
/*  f0e0634:	01ee3821 */ 	addu	$a3,$t7,$t6
/*  f0e0638:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f0e063c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e0640:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f0e0644:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e0648:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0e064c:	02402025 */ 	move	$a0,$s2
/*  f0e0650:	2706fffd */ 	addiu	$a2,$t8,-3
/*  f0e0654:	0fc37776 */ 	jal	hudmsgRenderBox
/*  f0e0658:	25c5fffd */ 	addiu	$a1,$t6,-3
/*  f0e065c:	0c002e53 */ 	jal	viGetWidth
/*  f0e0660:	00409025 */ 	move	$s2,$v0
/*  f0e0664:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e0668:	00115403 */ 	sra	$t2,$s1,0x10
/*  f0e066c:	0c002e57 */ 	jal	viGetHeight
/*  f0e0670:	01408825 */ 	move	$s1,$t2
/*  f0e0674:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0e0678:	02402025 */ 	move	$a0,$s2
/*  f0e067c:	02c02825 */ 	move	$a1,$s6
/*  f0e0680:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e0684:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f0e0688:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e068c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e0690:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e0694:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e0698:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e069c:	02e03025 */ 	move	$a2,$s7
/*  f0e06a0:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e06a4:	0fc55c50 */ 	jal	textRenderProjected
/*  f0e06a8:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e06ac:	1000001f */ 	b	.PF0f0e072c
/*  f0e06b0:	00409025 */ 	move	$s2,$v0
.PF0f0e06b4:
/*  f0e06b4:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f0e06b8:	9619001e */ 	lhu	$t9,0x1e($s0)
/*  f0e06bc:	960e001c */ 	lhu	$t6,0x1c($s0)
/*  f0e06c0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e06c4:	0326c021 */ 	addu	$t8,$t9,$a2
/*  f0e06c8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e06cc:	0fc551d2 */ 	jal	func0f153a34
/*  f0e06d0:	01c53821 */ 	addu	$a3,$t6,$a1
/*  f0e06d4:	0c002e53 */ 	jal	viGetWidth
/*  f0e06d8:	00409025 */ 	move	$s2,$v0
/*  f0e06dc:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e06e0:	00114c03 */ 	sra	$t1,$s1,0x10
/*  f0e06e4:	0c002e57 */ 	jal	viGetHeight
/*  f0e06e8:	01208825 */ 	move	$s1,$t1
/*  f0e06ec:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*  f0e06f0:	02402025 */ 	move	$a0,$s2
/*  f0e06f4:	02c02825 */ 	move	$a1,$s6
/*  f0e06f8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e06fc:	8e0a000c */ 	lw	$t2,0xc($s0)
/*  f0e0700:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0e0704:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e0708:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0e070c:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0e0710:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f0e0714:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e0718:	02e03025 */ 	move	$a2,$s7
/*  f0e071c:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e0720:	0fc55fa0 */ 	jal	textRender
/*  f0e0724:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0e0728:	00409025 */ 	move	$s2,$v0
.PF0f0e072c:
/*  f0e072c:	920801c9 */ 	lbu	$t0,0x1c9($s0)
/*  f0e0730:	24010006 */ 	li	$at,0x6
/*  f0e0734:	15010002 */ 	bne	$t0,$at,.PF0f0e0740
/*  f0e0738:	00000000 */ 	nop
/*  f0e073c:	afa000e0 */ 	sw	$zero,0xe0($sp)
.PF0f0e0740:
/*  f0e0740:	0fc552d8 */ 	jal	func0f153e4c
/*  f0e0744:	00000000 */ 	nop
/*  f0e0748:	100000fe */ 	b	.PF0f0e0b44
/*  f0e074c:	8e0801b4 */ 	lw	$t0,0x1b4($s0)
/*  f0e0750:	920c0001 */ 	lbu	$t4,0x1($s0)
/*  f0e0754:	8fa900e8 */ 	lw	$t1,0xe8($sp)
/*  f0e0758:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f0e075c:	11800037 */ 	beqz	$t4,.PF0f0e083c
/*  f0e0760:	2525fffd */ 	addiu	$a1,$t1,-3
/*  f0e0764:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0e0768:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0e076c:	240100ff */ 	li	$at,0xff
/*  f0e0770:	346e0040 */ 	ori	$t6,$v1,0x40
/*  f0e0774:	1041000e */ 	beq	$v0,$at,.PF0f0e07b0
/*  f0e0778:	01c01825 */ 	move	$v1,$t6
/*  f0e077c:	31cd00ff */ 	andi	$t5,$t6,0xff
/*  f0e0780:	004d0019 */ 	multu	$v0,$t5
/*  f0e0784:	00757824 */ 	and	$t7,$v1,$s5
/*  f0e0788:	0000c812 */ 	mflo	$t9
/*  f0e078c:	00000000 */ 	nop
/*  f0e0790:	00000000 */ 	nop
/*  f0e0794:	033e001b */ 	divu	$zero,$t9,$s8
/*  f0e0798:	00002012 */ 	mflo	$a0
/*  f0e079c:	309800ff */ 	andi	$t8,$a0,0xff
/*  f0e07a0:	17c00002 */ 	bnez	$s8,.PF0f0e07ac
/*  f0e07a4:	00000000 */ 	nop
/*  f0e07a8:	0007000d */ 	break	0x7
.PF0f0e07ac:
/*  f0e07ac:	01f81821 */ 	addu	$v1,$t7,$t8
.PF0f0e07b0:
/*  f0e07b0:	9608001e */ 	lhu	$t0,0x1e($s0)
/*  f0e07b4:	960a001c */ 	lhu	$t2,0x1c($s0)
/*  f0e07b8:	e7b4001c */ 	swc1	$f20,0x1c($sp)
/*  f0e07bc:	010b6021 */ 	addu	$t4,$t0,$t3
/*  f0e07c0:	258e0002 */ 	addiu	$t6,$t4,0x2
/*  f0e07c4:	01493821 */ 	addu	$a3,$t2,$t1
/*  f0e07c8:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f0e07cc:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e07d0:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e07d4:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0e07d8:	02402025 */ 	move	$a0,$s2
/*  f0e07dc:	0fc37776 */ 	jal	hudmsgRenderBox
/*  f0e07e0:	2566fffd */ 	addiu	$a2,$t3,-3
/*  f0e07e4:	0c002e53 */ 	jal	viGetWidth
/*  f0e07e8:	00409025 */ 	move	$s2,$v0
/*  f0e07ec:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e07f0:	00116c03 */ 	sra	$t5,$s1,0x10
/*  f0e07f4:	0c002e57 */ 	jal	viGetHeight
/*  f0e07f8:	01a08825 */ 	move	$s1,$t5
/*  f0e07fc:	8e190008 */ 	lw	$t9,0x8($s0)
/*  f0e0800:	02402025 */ 	move	$a0,$s2
/*  f0e0804:	02c02825 */ 	move	$a1,$s6
/*  f0e0808:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e080c:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f0e0810:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e0814:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e0818:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e081c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e0820:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e0824:	02e03025 */ 	move	$a2,$s7
/*  f0e0828:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e082c:	0fc55c50 */ 	jal	textRenderProjected
/*  f0e0830:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e0834:	10000021 */ 	b	.PF0f0e08bc
/*  f0e0838:	00409025 */ 	move	$s2,$v0
.PF0f0e083c:
/*  f0e083c:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f0e0840:	9608001e */ 	lhu	$t0,0x1e($s0)
/*  f0e0844:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0e0848:	9609001c */ 	lhu	$t1,0x1c($s0)
/*  f0e084c:	01065821 */ 	addu	$t3,$t0,$a2
/*  f0e0850:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e0854:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e0858:	02402025 */ 	move	$a0,$s2
/*  f0e085c:	0fc551d2 */ 	jal	func0f153a34
/*  f0e0860:	01253821 */ 	addu	$a3,$t1,$a1
/*  f0e0864:	0c002e53 */ 	jal	viGetWidth
/*  f0e0868:	00409025 */ 	move	$s2,$v0
/*  f0e086c:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e0870:	00116403 */ 	sra	$t4,$s1,0x10
/*  f0e0874:	0c002e57 */ 	jal	viGetHeight
/*  f0e0878:	01808825 */ 	move	$s1,$t4
/*  f0e087c:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*  f0e0880:	02402025 */ 	move	$a0,$s2
/*  f0e0884:	02c02825 */ 	move	$a1,$s6
/*  f0e0888:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e088c:	8e0d000c */ 	lw	$t5,0xc($s0)
/*  f0e0890:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0e0894:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e0898:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0e089c:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0e08a0:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f0e08a4:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e08a8:	02e03025 */ 	move	$a2,$s7
/*  f0e08ac:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e08b0:	0fc55fa0 */ 	jal	textRender
/*  f0e08b4:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e08b8:	00409025 */ 	move	$s2,$v0
.PF0f0e08bc:
/*  f0e08bc:	921901c9 */ 	lbu	$t9,0x1c9($s0)
/*  f0e08c0:	24010006 */ 	li	$at,0x6
/*  f0e08c4:	5721009f */ 	bnel	$t9,$at,.PF0f0e0b44
/*  f0e08c8:	8e0801b4 */ 	lw	$t0,0x1b4($s0)
/*  f0e08cc:	1000009c */ 	b	.PF0f0e0b40
/*  f0e08d0:	afa000e0 */ 	sw	$zero,0xe0($sp)
/*  f0e08d4:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0e08d8:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0e08dc:	00420019 */ 	multu	$v0,$v0
/*  f0e08e0:	00007812 */ 	mflo	$t7
/*  f0e08e4:	00000000 */ 	nop
/*  f0e08e8:	00000000 */ 	nop
/*  f0e08ec:	00630019 */ 	multu	$v1,$v1
/*  f0e08f0:	00004812 */ 	mflo	$t1
/*  f0e08f4:	01e9c021 */ 	addu	$t8,$t7,$t1
/*  f0e08f8:	44984000 */ 	mtc1	$t8,$f8
/*  f0e08fc:	0c0127b4 */ 	jal	sqrtf
/*  f0e0900:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f0e0904:	3c0142b8 */ 	lui	$at,0x42b8
/*  f0e0908:	44813000 */ 	mtc1	$at,$f6
/*  f0e090c:	8e110010 */ 	lw	$s1,0x10($s0)
/*  f0e0910:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0e0914:	46060280 */ 	add.s	$f10,$f0,$f6
/*  f0e0918:	240100ff */ 	li	$at,0xff
/*  f0e091c:	36280040 */ 	ori	$t0,$s1,0x40
/*  f0e0920:	01008825 */ 	move	$s1,$t0
/*  f0e0924:	1041000e */ 	beq	$v0,$at,.PF0f0e0960
/*  f0e0928:	46185083 */ 	div.s	$f2,$f10,$f24
/*  f0e092c:	310a00ff */ 	andi	$t2,$t0,0xff
/*  f0e0930:	004a0019 */ 	multu	$v0,$t2
/*  f0e0934:	02356024 */ 	and	$t4,$s1,$s5
/*  f0e0938:	00005812 */ 	mflo	$t3
/*  f0e093c:	00000000 */ 	nop
/*  f0e0940:	00000000 */ 	nop
/*  f0e0944:	017e001b */ 	divu	$zero,$t3,$s8
/*  f0e0948:	00001812 */ 	mflo	$v1
/*  f0e094c:	306e00ff */ 	andi	$t6,$v1,0xff
/*  f0e0950:	17c00002 */ 	bnez	$s8,.PF0f0e095c
/*  f0e0954:	00000000 */ 	nop
/*  f0e0958:	0007000d */ 	break	0x7
.PF0f0e095c:
/*  f0e095c:	018e8821 */ 	addu	$s1,$t4,$t6
.PF0f0e0960:
/*  f0e0960:	960d0006 */ 	lhu	$t5,0x6($s0)
/*  f0e0964:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e0968:	448d8000 */ 	mtc1	$t5,$f16
/*  f0e096c:	05a10004 */ 	bgez	$t5,.PF0f0e0980
/*  f0e0970:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0e0974:	44812000 */ 	mtc1	$at,$f4
/*  f0e0978:	00000000 */ 	nop
/*  f0e097c:	46049480 */ 	add.s	$f18,$f18,$f4
.PF0f0e0980:
/*  f0e0980:	46121201 */ 	sub.s	$f8,$f2,$f18
/*  f0e0984:	9619001c */ 	lhu	$t9,0x1c($s0)
/*  f0e0988:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f0e098c:	9609001e */ 	lhu	$t1,0x1e($s0)
/*  f0e0990:	46184002 */ 	mul.s	$f0,$f8,$f24
/*  f0e0994:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0e0998:	e7a200a8 */ 	swc1	$f2,0xa8($sp)
/*  f0e099c:	24070002 */ 	li	$a3,0x2
/*  f0e09a0:	032f2021 */ 	addu	$a0,$t9,$t7
/*  f0e09a4:	01382821 */ 	addu	$a1,$t1,$t8
/*  f0e09a8:	44060000 */ 	mfc1	$a2,$f0
/*  f0e09ac:	0fc5524d */ 	jal	func0f153c20
/*  f0e09b0:	00000000 */ 	nop
/*  f0e09b4:	c7a200a8 */ 	lwc1	$f2,0xa8($sp)
/*  f0e09b8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e09bc:	8fab00e8 */ 	lw	$t3,0xe8($sp)
/*  f0e09c0:	4602d03c */ 	c.lt.s	$f26,$f2
/*  f0e09c4:	8fac00e4 */ 	lw	$t4,0xe4($sp)
/*  f0e09c8:	02402025 */ 	move	$a0,$s2
/*  f0e09cc:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0e09d0:	45000002 */ 	bc1f	.PF0f0e09dc
/*  f0e09d4:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f0e09d8:	4600d086 */ 	mov.s	$f2,$f26
.PF0f0e09dc:
/*  f0e09dc:	96080006 */ 	lhu	$t0,0x6($s0)
/*  f0e09e0:	44883000 */ 	mtc1	$t0,$f6
/*  f0e09e4:	05010004 */ 	bgez	$t0,.PF0f0e09f8
/*  f0e09e8:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0e09ec:	44818000 */ 	mtc1	$at,$f16
/*  f0e09f0:	00000000 */ 	nop
/*  f0e09f4:	46105280 */ 	add.s	$f10,$f10,$f16
.PF0f0e09f8:
/*  f0e09f8:	46025083 */ 	div.s	$f2,$f10,$f2
/*  f0e09fc:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f0e0a00:	00000000 */ 	nop
/*  f0e0a04:	45020003 */ 	bc1fl	.PF0f0e0a14
/*  f0e0a08:	920a0001 */ 	lbu	$t2,0x1($s0)
/*  f0e0a0c:	4600a086 */ 	mov.s	$f2,$f20
/*  f0e0a10:	920a0001 */ 	lbu	$t2,0x1($s0)
.PF0f0e0a14:
/*  f0e0a14:	51400027 */ 	beqzl	$t2,.PF0f0e0ab4
/*  f0e0a18:	960d001e */ 	lhu	$t5,0x1e($s0)
/*  f0e0a1c:	960d001e */ 	lhu	$t5,0x1e($s0)
/*  f0e0a20:	960e001c */ 	lhu	$t6,0x1c($s0)
/*  f0e0a24:	4602a101 */ 	sub.s	$f4,$f20,$f2
/*  f0e0a28:	01acc821 */ 	addu	$t9,$t5,$t4
/*  f0e0a2c:	272f0002 */ 	addiu	$t7,$t9,0x2
/*  f0e0a30:	01cb3821 */ 	addu	$a3,$t6,$t3
/*  f0e0a34:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f0e0a38:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e0a3c:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f0e0a40:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e0a44:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0e0a48:	02402025 */ 	move	$a0,$s2
/*  f0e0a4c:	2565fffd */ 	addiu	$a1,$t3,-3
/*  f0e0a50:	0fc37776 */ 	jal	hudmsgRenderBox
/*  f0e0a54:	2586fffd */ 	addiu	$a2,$t4,-3
/*  f0e0a58:	0c002e53 */ 	jal	viGetWidth
/*  f0e0a5c:	00409025 */ 	move	$s2,$v0
/*  f0e0a60:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e0a64:	00114c03 */ 	sra	$t1,$s1,0x10
/*  f0e0a68:	0c002e57 */ 	jal	viGetHeight
/*  f0e0a6c:	01208825 */ 	move	$s1,$t1
/*  f0e0a70:	8e180008 */ 	lw	$t8,0x8($s0)
/*  f0e0a74:	02402025 */ 	move	$a0,$s2
/*  f0e0a78:	02c02825 */ 	move	$a1,$s6
/*  f0e0a7c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e0a80:	8e08000c */ 	lw	$t0,0xc($s0)
/*  f0e0a84:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e0a88:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e0a8c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e0a90:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e0a94:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e0a98:	02e03025 */ 	move	$a2,$s7
/*  f0e0a9c:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e0aa0:	0fc55c50 */ 	jal	textRenderProjected
/*  f0e0aa4:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0e0aa8:	1000001e */ 	b	.PF0f0e0b24
/*  f0e0aac:	00409025 */ 	move	$s2,$v0
/*  f0e0ab0:	960d001e */ 	lhu	$t5,0x1e($s0)
.PF0f0e0ab4:
/*  f0e0ab4:	960b001c */ 	lhu	$t3,0x1c($s0)
/*  f0e0ab8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e0abc:	01a66021 */ 	addu	$t4,$t5,$a2
/*  f0e0ac0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e0ac4:	0fc551d2 */ 	jal	func0f153a34
/*  f0e0ac8:	01653821 */ 	addu	$a3,$t3,$a1
/*  f0e0acc:	0c002e53 */ 	jal	viGetWidth
/*  f0e0ad0:	00409025 */ 	move	$s2,$v0
/*  f0e0ad4:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e0ad8:	0011cc03 */ 	sra	$t9,$s1,0x10
/*  f0e0adc:	0c002e57 */ 	jal	viGetHeight
/*  f0e0ae0:	03208825 */ 	move	$s1,$t9
/*  f0e0ae4:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*  f0e0ae8:	02402025 */ 	move	$a0,$s2
/*  f0e0aec:	02c02825 */ 	move	$a1,$s6
/*  f0e0af0:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e0af4:	8e09000c */ 	lw	$t1,0xc($s0)
/*  f0e0af8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0e0afc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e0b00:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0e0b04:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0e0b08:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f0e0b0c:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e0b10:	02e03025 */ 	move	$a2,$s7
/*  f0e0b14:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e0b18:	0fc55fa0 */ 	jal	textRender
/*  f0e0b1c:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e0b20:	00409025 */ 	move	$s2,$v0
.PF0f0e0b24:
/*  f0e0b24:	921801c9 */ 	lbu	$t8,0x1c9($s0)
/*  f0e0b28:	24010006 */ 	li	$at,0x6
/*  f0e0b2c:	17010002 */ 	bne	$t8,$at,.PF0f0e0b38
/*  f0e0b30:	00000000 */ 	nop
/*  f0e0b34:	afa000e0 */ 	sw	$zero,0xe0($sp)
.PF0f0e0b38:
/*  f0e0b38:	0fc552d8 */ 	jal	func0f153e4c
/*  f0e0b3c:	00000000 */ 	nop
.PF0f0e0b40:
/*  f0e0b40:	8e0801b4 */ 	lw	$t0,0x1b4($s0)
.PF0f0e0b44:
/*  f0e0b44:	2401000b */ 	li	$at,0xb
/*  f0e0b48:	15010039 */ 	bne	$t0,$at,.PF0f0e0c30
/*  f0e0b4c:	00000000 */ 	nop
/*  f0e0b50:	afb2009c */ 	sw	$s2,0x9c($sp)
/*  f0e0b54:	0c002e91 */ 	jal	viGetViewLeft
/*  f0e0b58:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e0b5c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e0b60:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f0e0b64:	01608025 */ 	move	$s0,$t3
/*  f0e0b68:	0c002e95 */ 	jal	viGetViewTop
/*  f0e0b6c:	8fb3009c */ 	lw	$s3,0x9c($sp)
/*  f0e0b70:	44829000 */ 	mtc1	$v0,$f18
/*  f0e0b74:	44905000 */ 	mtc1	$s0,$f10
/*  f0e0b78:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e0b7c:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f0e0b80:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0e0b84:	46164182 */ 	mul.s	$f6,$f8,$f22
/*  f0e0b88:	00000000 */ 	nop
/*  f0e0b8c:	46162482 */ 	mul.s	$f18,$f4,$f22
/*  f0e0b90:	4600340d */ 	trunc.w.s	$f16,$f6
/*  f0e0b94:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e0b98:	440d8000 */ 	mfc1	$t5,$f16
/*  f0e0b9c:	440f4000 */ 	mfc1	$t7,$f8
/*  f0e0ba0:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f0e0ba4:	01c16025 */ 	or	$t4,$t6,$at
/*  f0e0ba8:	31e90fff */ 	andi	$t1,$t7,0xfff
/*  f0e0bac:	0009c300 */ 	sll	$t8,$t1,0xc
/*  f0e0bb0:	01984025 */ 	or	$t0,$t4,$t8
/*  f0e0bb4:	0c002e73 */ 	jal	viGetViewWidth
/*  f0e0bb8:	ae680000 */ 	sw	$t0,0x0($s3)
/*  f0e0bbc:	0c002e91 */ 	jal	viGetViewLeft
/*  f0e0bc0:	a7a20092 */ 	sh	$v0,0x92($sp)
/*  f0e0bc4:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e0bc8:	00115c03 */ 	sra	$t3,$s1,0x10
/*  f0e0bcc:	0c002e95 */ 	jal	viGetViewTop
/*  f0e0bd0:	01608825 */ 	move	$s1,$t3
/*  f0e0bd4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e0bd8:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0e0bdc:	0c002e77 */ 	jal	viGetViewHeight
/*  f0e0be0:	01408025 */ 	move	$s0,$t2
/*  f0e0be4:	87a90092 */ 	lh	$t1,0x92($sp)
/*  f0e0be8:	00506821 */ 	addu	$t5,$v0,$s0
/*  f0e0bec:	448d3000 */ 	mtc1	$t5,$f6
/*  f0e0bf0:	02296021 */ 	addu	$t4,$s1,$t1
/*  f0e0bf4:	448c9000 */ 	mtc1	$t4,$f18
/*  f0e0bf8:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f0e0bfc:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f0e0c00:	46168282 */ 	mul.s	$f10,$f16,$f22
/*  f0e0c04:	00000000 */ 	nop
/*  f0e0c08:	46164182 */ 	mul.s	$f6,$f8,$f22
/*  f0e0c0c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0e0c10:	4600340d */ 	trunc.w.s	$f16,$f6
/*  f0e0c14:	44192000 */ 	mfc1	$t9,$f4
/*  f0e0c18:	44088000 */ 	mfc1	$t0,$f16
/*  f0e0c1c:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f0e0c20:	310b0fff */ 	andi	$t3,$t0,0xfff
/*  f0e0c24:	000b5300 */ 	sll	$t2,$t3,0xc
/*  f0e0c28:	01ea6825 */ 	or	$t5,$t7,$t2
/*  f0e0c2c:	ae6d0004 */ 	sw	$t5,0x4($s3)
.PF0f0e0c30:
/*  f0e0c30:	3c048007 */ 	lui	$a0,0x8007
/*  f0e0c34:	8c8412c8 */ 	lw	$a0,0x12c8($a0)
/*  f0e0c38:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0e0c3c:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e0c40:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0e0c44:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e0c48:	00021080 */ 	sll	$v0,$v0,0x2
.PF0f0e0c4c:
/*  f0e0c4c:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f0e0c50:	25d901dc */ 	addiu	$t9,$t6,0x1dc
/*  f0e0c54:	0322082a */ 	slt	$at,$t9,$v0
/*  f0e0c58:	1420fd70 */ 	bnez	$at,.PF0f0e021c
/*  f0e0c5c:	afb90088 */ 	sw	$t9,0x88($sp)
.PF0f0e0c60:
/*  f0e0c60:	8fa900e0 */ 	lw	$t1,0xe0($sp)
/*  f0e0c64:	3c0c800a */ 	lui	$t4,0x800a
/*  f0e0c68:	11200028 */ 	beqz	$t1,.PF0f0e0d0c
/*  f0e0c6c:	00000000 */ 	nop
/*  f0e0c70:	8d8ca798 */ 	lw	$t4,-0x5868($t4)
/*  f0e0c74:	0fc54d66 */ 	jal	optionsGetShowMissionTime
/*  f0e0c78:	8d840070 */ 	lw	$a0,0x70($t4)
/*  f0e0c7c:	10400019 */ 	beqz	$v0,.PF0f0e0ce4
/*  f0e0c80:	3c188007 */ 	lui	$t8,0x8007
/*  f0e0c84:	8f186230 */ 	lw	$t8,0x6230($t8)
/*  f0e0c88:	24030002 */ 	li	$v1,0x2
/*  f0e0c8c:	3c08800a */ 	lui	$t0,0x800a
/*  f0e0c90:	14780014 */ 	bne	$v1,$t8,.PF0f0e0ce4
/*  f0e0c94:	00000000 */ 	nop
/*  f0e0c98:	8d08a828 */ 	lw	$t0,-0x57d8($t0)
/*  f0e0c9c:	3c0b800a */ 	lui	$t3,0x800a
/*  f0e0ca0:	15000010 */ 	bnez	$t0,.PF0f0e0ce4
/*  f0e0ca4:	00000000 */ 	nop
/*  f0e0ca8:	8d6ba9c4 */ 	lw	$t3,-0x563c($t3)
/*  f0e0cac:	24010026 */ 	li	$at,0x26
/*  f0e0cb0:	3c0f800a */ 	lui	$t7,0x800a
/*  f0e0cb4:	1161000b */ 	beq	$t3,$at,.PF0f0e0ce4
/*  f0e0cb8:	00000000 */ 	nop
/*  f0e0cbc:	8defa794 */ 	lw	$t7,-0x586c($t7)
/*  f0e0cc0:	24010001 */ 	li	$at,0x1
/*  f0e0cc4:	8de20000 */ 	lw	$v0,0x0($t7)
/*  f0e0cc8:	10620006 */ 	beq	$v1,$v0,.PF0f0e0ce4
/*  f0e0ccc:	00000000 */ 	nop
/*  f0e0cd0:	10410004 */ 	beq	$v0,$at,.PF0f0e0ce4
/*  f0e0cd4:	02402025 */ 	move	$a0,$s2
/*  f0e0cd8:	0fc37521 */ 	jal	hudmsgRenderMissionTimer
/*  f0e0cdc:	8fa500e0 */ 	lw	$a1,0xe0($sp)
/*  f0e0ce0:	00409025 */ 	move	$s2,$v0
.PF0f0e0ce4:
/*  f0e0ce4:	0fc374d3 */ 	jal	hudmsgIsZoomRangeVisible
/*  f0e0ce8:	00000000 */ 	nop
/*  f0e0cec:	10400004 */ 	beqz	$v0,.PF0f0e0d00
/*  f0e0cf0:	02402025 */ 	move	$a0,$s2
/*  f0e0cf4:	0fc3760f */ 	jal	hudmsgRenderZoomRange
/*  f0e0cf8:	8fa500e0 */ 	lw	$a1,0xe0($sp)
/*  f0e0cfc:	00409025 */ 	move	$s2,$v0
.PF0f0e0d00:
/*  f0e0d00:	0fc241f9 */ 	jal	countdownTimerRender
/*  f0e0d04:	02402025 */ 	move	$a0,$s2
/*  f0e0d08:	00409025 */ 	move	$s2,$v0
.PF0f0e0d0c:
/*  f0e0d0c:	0fc55125 */ 	jal	func0f153780
/*  f0e0d10:	02402025 */ 	move	$a0,$s2
/*  f0e0d14:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f0e0d18:	240a0001 */ 	li	$t2,0x1
/*  f0e0d1c:	3c018008 */ 	lui	$at,0x8008
/*  f0e0d20:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f0e0d24:	d7b60040 */ 	ldc1	$f22,0x40($sp)
/*  f0e0d28:	d7b80048 */ 	ldc1	$f24,0x48($sp)
/*  f0e0d2c:	d7ba0050 */ 	ldc1	$f26,0x50($sp)
/*  f0e0d30:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f0e0d34:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f0e0d38:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0e0d3c:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f0e0d40:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f0e0d44:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f0e0d48:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f0e0d4c:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f0e0d50:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f0e0d54:	ac2a0020 */ 	sw	$t2,0x20($at)
/*  f0e0d58:	03e00008 */ 	jr	$ra
/*  f0e0d5c:	27bd0100 */ 	addiu	$sp,$sp,0x100
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel hudmsgsRender
.late_rodata
glabel var7f1adedc
.word 0x40490fdb
glabel var7f1adee0
.word hudmsgsRender+0xa34 # f0e0504
glabel var7f1adee4
.word hudmsgsRender+0xa34 # f0e0504
glabel var7f1adee8
.word hudmsgsRender+0xa34 # f0e0504
glabel var7f1adeec
.word hudmsgsRender+0x3ec # f0dfebc
glabel var7f1adef0
.word hudmsgsRender+0x644 # f0e0114
glabel var7f1adef4
.word hudmsgsRender+0x7c8 # f0e0298
.text
/*  f0dfad0:	27bdff00 */ 	addiu	$sp,$sp,-256
/*  f0dfad4:	3c0f8007 */ 	lui	$t7,%hi(g_ViMode)
/*  f0dfad8:	8def06c8 */ 	lw	$t7,%lo(g_ViMode)($t7)
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
/*  f0dfb30:	3c018008 */ 	lui	$at,%hi(g_ScaleX)
/*  f0dfb34:	10000003 */ 	b	.L0f0dfb44
/*  f0dfb38:	ac38fac0 */ 	sw	$t8,%lo(g_ScaleX)($at)
.L0f0dfb3c:
/*  f0dfb3c:	3c018008 */ 	lui	$at,%hi(g_ScaleX)
/*  f0dfb40:	ac22fac0 */ 	sw	$v0,%lo(g_ScaleX)($at)
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
/*  f0dfb70:	00000000 */ 	nop
.L0f0dfb74:
/*  f0dfb74:	3c098007 */ 	lui	$t1,%hi(g_InCutscene)
/*  f0dfb78:	8d290764 */ 	lw	$t1,%lo(g_InCutscene)($t1)
/*  f0dfb7c:	1120000a */ 	beqz	$t1,.L0f0dfba8
/*  f0dfb80:	00000000 */ 	nop
/*  f0dfb84:	3c0a8006 */ 	lui	$t2,%hi(g_MainIsEndscreen)
/*  f0dfb88:	8d4ad9d0 */ 	lw	$t2,%lo(g_MainIsEndscreen)($t2)
/*  f0dfb8c:	15400006 */ 	bnez	$t2,.L0f0dfba8
/*  f0dfb90:	00000000 */ 	nop
/*  f0dfb94:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x28c)
/*  f0dfb98:	8d6ba24c */ 	lw	$t3,%lo(g_Vars+0x28c)($t3)
/*  f0dfb9c:	15600002 */ 	bnez	$t3,.L0f0dfba8
/*  f0dfba0:	00000000 */ 	nop
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
/*  f0dfc0c:	10000280 */ 	b	.L0f0e0610
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
/*  f0dfc54:	1000026e */ 	b	.L0f0e0610
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
/*  f0dfc80:	00000000 */ 	nop
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
/*  f0dfcbc:	00000000 */ 	nop
/*  f0dfcc0:	46000087 */ 	neg.s	$f2,$f0
.L0f0dfcc4:
/*  f0dfcc4:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0dfcc8:	8e090010 */ 	lw	$t1,0x10($s0)
/*  f0dfccc:	8e140014 */ 	lw	$s4,0x14($s0)
/*  f0dfcd0:	92030004 */ 	lbu	$v1,0x4($s0)
/*  f0dfcd4:	01355024 */ 	and	$t2,$t1,$s5
/*  f0dfcd8:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f0dfcdc:	440c5000 */ 	mfc1	$t4,$f10
/*  f0dfce0:	10000005 */ 	b	.L0f0dfcf8
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
/*  f0dfd20:	00000000 */ 	nop
/*  f0dfd24:	00000000 */ 	nop
/*  f0dfd28:	01fe001b */ 	divu	$zero,$t7,$s8
/*  f0dfd2c:	00002012 */ 	mflo	$a0
/*  f0dfd30:	308900ff */ 	andi	$t1,$a0,0xff
/*  f0dfd34:	17c00002 */ 	bnez	$s8,.L0f0dfd40
/*  f0dfd38:	00000000 */ 	nop
/*  f0dfd3c:	0007000d */ 	break	0x7
.L0f0dfd40:
/*  f0dfd40:	00780019 */ 	multu	$v1,$t8
/*  f0dfd44:	01099821 */ 	addu	$s3,$t0,$t1
/*  f0dfd48:	0000c812 */ 	mflo	$t9
/*  f0dfd4c:	00000000 */ 	nop
/*  f0dfd50:	00000000 */ 	nop
/*  f0dfd54:	033e001b */ 	divu	$zero,$t9,$s8
/*  f0dfd58:	00002812 */ 	mflo	$a1
/*  f0dfd5c:	30aa00ff */ 	andi	$t2,$a1,0xff
/*  f0dfd60:	17c00002 */ 	bnez	$s8,.L0f0dfd6c
/*  f0dfd64:	00000000 */ 	nop
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
/*  f0dfd90:	0fc305f3 */ 	jal	currentPlayerIsHealthVisible
/*  f0dfd94:	00000000 */ 	nop
/*  f0dfd98:	5040000d */ 	beqzl	$v0,.L0f0dfdd0
/*  f0dfd9c:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
/*  f0dfda0:	0fc305bd */ 	jal	currentPlayerGetHealthBarHeightFrac
/*  f0dfda4:	00000000 */ 	nop
/*  f0dfda8:	3c014180 */ 	lui	$at,0x4180
/*  f0dfdac:	44818000 */ 	mtc1	$at,$f16
/*  f0dfdb0:	8faf00e4 */ 	lw	$t7,0xe4($sp)
/*  f0dfdb4:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0dfdb8:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0dfdbc:	44192000 */ 	mfc1	$t9,$f4
/*  f0dfdc0:	00000000 */ 	nop
/*  f0dfdc4:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f0dfdc8:	afa800e4 */ 	sw	$t0,0xe4($sp)
/*  f0dfdcc:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
.L0f0dfdd0:
/*  f0dfdd0:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0dfdd4:	55210031 */ 	bnel	$t1,$at,.L0f0dfe9c
/*  f0dfdd8:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f0dfddc:	8fab00e8 */ 	lw	$t3,0xe8($sp)
/*  f0dfde0:	3c0c8008 */ 	lui	$t4,%hi(g_ScaleX)
/*  f0dfde4:	8d8cfac0 */ 	lw	$t4,%lo(g_ScaleX)($t4)
/*  f0dfde8:	256afffc */ 	addiu	$t2,$t3,-4
/*  f0dfdec:	3c01ed00 */ 	lui	$at,0xed00
/*  f0dfdf0:	014c0019 */ 	multu	$t2,$t4
/*  f0dfdf4:	02408825 */ 	or	$s1,$s2,$zero
/*  f0dfdf8:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0dfdfc:	00006812 */ 	mflo	$t5
/*  f0dfe00:	448d4000 */ 	mtc1	$t5,$f8
/*  f0dfe04:	00000000 */ 	nop
/*  f0dfe08:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0dfe0c:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f0dfe10:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0dfe14:	44188000 */ 	mfc1	$t8,$f16
/*  f0dfe18:	00000000 */ 	nop
/*  f0dfe1c:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f0dfe20:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f0dfe24:	03214025 */ 	or	$t0,$t9,$at
/*  f0dfe28:	0c002ef5 */ 	jal	viGetBufY
/*  f0dfe2c:	ae280000 */ 	sw	$t0,0x0($s1)
/*  f0dfe30:	8fa900e8 */ 	lw	$t1,0xe8($sp)
/*  f0dfe34:	960b001c */ 	lhu	$t3,0x1c($s0)
/*  f0dfe38:	3c0d8008 */ 	lui	$t5,%hi(g_ScaleX)
/*  f0dfe3c:	8dadfac0 */ 	lw	$t5,%lo(g_ScaleX)($t5)
/*  f0dfe40:	012b5021 */ 	addu	$t2,$t1,$t3
/*  f0dfe44:	254c0003 */ 	addiu	$t4,$t2,0x3
/*  f0dfe48:	018d0019 */ 	multu	$t4,$t5
/*  f0dfe4c:	44825000 */ 	mtc1	$v0,$f10
/*  f0dfe50:	00000000 */ 	nop
/*  f0dfe54:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0dfe58:	00007012 */ 	mflo	$t6
/*  f0dfe5c:	448e9000 */ 	mtc1	$t6,$f18
/*  f0dfe60:	00000000 */ 	nop
/*  f0dfe64:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0dfe68:	46162202 */ 	mul.s	$f8,$f4,$f22
/*  f0dfe6c:	00000000 */ 	nop
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
/*  f0dfeb8:	00000000 */ 	nop
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
/*  f0dfee4:	00000000 */ 	nop
/*  f0dfee8:	00000000 */ 	nop
/*  f0dfeec:	01fe001b */ 	divu	$zero,$t7,$s8
/*  f0dfef0:	00001812 */ 	mflo	$v1
/*  f0dfef4:	306900ff */ 	andi	$t1,$v1,0xff
/*  f0dfef8:	17c00002 */ 	bnez	$s8,.L0f0dff04
/*  f0dfefc:	00000000 */ 	nop
/*  f0dff00:	0007000d */ 	break	0x7
.L0f0dff04:
/*  f0dff04:	03298821 */ 	addu	$s1,$t9,$t1
.L0f0dff08:
/*  f0dff08:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0dff0c:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0dff10:	00420019 */ 	multu	$v0,$v0
/*  f0dff14:	00005812 */ 	mflo	$t3
/*  f0dff18:	00000000 */ 	nop
/*  f0dff1c:	00000000 */ 	nop
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
/*  f0dff54:	00000000 */ 	nop
/*  f0dff58:	45020003 */ 	bc1fl	.L0f0dff68
/*  f0dff5c:	960c0006 */ 	lhu	$t4,0x6($s0)
/*  f0dff60:	4600d086 */ 	mov.s	$f2,$f26
/*  f0dff64:	960c0006 */ 	lhu	$t4,0x6($s0)
.L0f0dff68:
/*  f0dff68:	448c8000 */ 	mtc1	$t4,$f16
/*  f0dff6c:	05810004 */ 	bgez	$t4,.L0f0dff80
/*  f0dff70:	46808320 */ 	cvt.s.w	$f12,$f16
/*  f0dff74:	44819000 */ 	mtc1	$at,$f18
/*  f0dff78:	00000000 */ 	nop
/*  f0dff7c:	46126300 */ 	add.s	$f12,$f12,$f18
.L0f0dff80:
/*  f0dff80:	46026083 */ 	div.s	$f2,$f12,$f2
/*  f0dff84:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f0dff88:	8fa500e4 */ 	lw	$a1,0xe4($sp)
/*  f0dff8c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0dff90:	46186002 */ 	mul.s	$f0,$f12,$f24
/*  f0dff94:	44060000 */ 	mfc1	$a2,$f0
/*  f0dff98:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f0dff9c:	00000000 */ 	nop
/*  f0dffa0:	45020003 */ 	bc1fl	.L0f0dffb0
/*  f0dffa4:	4604103c */ 	c.lt.s	$f2,$f4
/*  f0dffa8:	4600a086 */ 	mov.s	$f2,$f20
/*  f0dffac:	4604103c */ 	c.lt.s	$f2,$f4
.L0f0dffb0:
/*  f0dffb0:	00000000 */ 	nop
/*  f0dffb4:	45000003 */ 	bc1f	.L0f0dffc4
/*  f0dffb8:	00000000 */ 	nop
/*  f0dffbc:	44801000 */ 	mtc1	$zero,$f2
/*  f0dffc0:	00000000 */ 	nop
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
/*  f0e0018:	0fc37612 */ 	jal	hudmsgRenderBox
/*  f0e001c:	25c5fffd */ 	addiu	$a1,$t6,-3
/*  f0e0020:	0c002f02 */ 	jal	viGetWidth
/*  f0e0024:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e0028:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e002c:	00115403 */ 	sra	$t2,$s1,0x10
/*  f0e0030:	0c002f06 */ 	jal	viGetHeight
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
/*  f0e0068:	0fc5580f */ 	jal	textRenderProjected
/*  f0e006c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e0070:	1000001f */ 	b	.L0f0e00f0
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
/*  f0e0098:	0c002f02 */ 	jal	viGetWidth
/*  f0e009c:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e00a0:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e00a4:	00114c03 */ 	sra	$t1,$s1,0x10
/*  f0e00a8:	0c002f06 */ 	jal	viGetHeight
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
/*  f0e00e4:	0fc55b92 */ 	jal	textRender
/*  f0e00e8:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0e00ec:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e00f0:
/*  f0e00f0:	920801c9 */ 	lbu	$t0,0x1c9($s0)
/*  f0e00f4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0e00f8:	15010002 */ 	bne	$t0,$at,.L0f0e0104
/*  f0e00fc:	00000000 */ 	nop
/*  f0e0100:	afa000e0 */ 	sw	$zero,0xe0($sp)
.L0f0e0104:
/*  f0e0104:	0fc54f93 */ 	jal	func0f153e4c
/*  f0e0108:	00000000 */ 	nop
/*  f0e010c:	100000fe */ 	b	.L0f0e0508
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
/*  f0e0150:	00000000 */ 	nop
/*  f0e0154:	00000000 */ 	nop
/*  f0e0158:	033e001b */ 	divu	$zero,$t9,$s8
/*  f0e015c:	00002012 */ 	mflo	$a0
/*  f0e0160:	309800ff */ 	andi	$t8,$a0,0xff
/*  f0e0164:	17c00002 */ 	bnez	$s8,.L0f0e0170
/*  f0e0168:	00000000 */ 	nop
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
/*  f0e01a0:	0fc37612 */ 	jal	hudmsgRenderBox
/*  f0e01a4:	2566fffd */ 	addiu	$a2,$t3,-3
/*  f0e01a8:	0c002f02 */ 	jal	viGetWidth
/*  f0e01ac:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e01b0:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e01b4:	00116c03 */ 	sra	$t5,$s1,0x10
/*  f0e01b8:	0c002f06 */ 	jal	viGetHeight
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
/*  f0e01f0:	0fc5580f */ 	jal	textRenderProjected
/*  f0e01f4:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e01f8:	10000021 */ 	b	.L0f0e0280
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
/*  f0e0228:	0c002f02 */ 	jal	viGetWidth
/*  f0e022c:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e0230:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e0234:	00116403 */ 	sra	$t4,$s1,0x10
/*  f0e0238:	0c002f06 */ 	jal	viGetHeight
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
/*  f0e0274:	0fc55b92 */ 	jal	textRender
/*  f0e0278:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e027c:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e0280:
/*  f0e0280:	921901c9 */ 	lbu	$t9,0x1c9($s0)
/*  f0e0284:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0e0288:	5721009f */ 	bnel	$t9,$at,.L0f0e0508
/*  f0e028c:	8e0801b4 */ 	lw	$t0,0x1b4($s0)
/*  f0e0290:	1000009c */ 	b	.L0f0e0504
/*  f0e0294:	afa000e0 */ 	sw	$zero,0xe0($sp)
/*  f0e0298:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0e029c:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0e02a0:	00420019 */ 	multu	$v0,$v0
/*  f0e02a4:	00007812 */ 	mflo	$t7
/*  f0e02a8:	00000000 */ 	nop
/*  f0e02ac:	00000000 */ 	nop
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
/*  f0e0300:	00000000 */ 	nop
/*  f0e0304:	00000000 */ 	nop
/*  f0e0308:	017e001b */ 	divu	$zero,$t3,$s8
/*  f0e030c:	00001812 */ 	mflo	$v1
/*  f0e0310:	306e00ff */ 	andi	$t6,$v1,0xff
/*  f0e0314:	17c00002 */ 	bnez	$s8,.L0f0e0320
/*  f0e0318:	00000000 */ 	nop
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
/*  f0e033c:	00000000 */ 	nop
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
/*  f0e0374:	00000000 */ 	nop
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
/*  f0e03b4:	00000000 */ 	nop
/*  f0e03b8:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f0e03bc:
/*  f0e03bc:	46025083 */ 	div.s	$f2,$f10,$f2
/*  f0e03c0:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f0e03c4:	00000000 */ 	nop
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
/*  f0e0414:	0fc37612 */ 	jal	hudmsgRenderBox
/*  f0e0418:	2586fffd */ 	addiu	$a2,$t4,-3
/*  f0e041c:	0c002f02 */ 	jal	viGetWidth
/*  f0e0420:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e0424:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e0428:	00114c03 */ 	sra	$t1,$s1,0x10
/*  f0e042c:	0c002f06 */ 	jal	viGetHeight
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
/*  f0e0464:	0fc5580f */ 	jal	textRenderProjected
/*  f0e0468:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0e046c:	1000001e */ 	b	.L0f0e04e8
/*  f0e0470:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e0474:	960d001e */ 	lhu	$t5,0x1e($s0)
.L0f0e0478:
/*  f0e0478:	960b001c */ 	lhu	$t3,0x1c($s0)
/*  f0e047c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e0480:	01a66021 */ 	addu	$t4,$t5,$a2
/*  f0e0484:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e0488:	0fc54e8d */ 	jal	func0f153a34
/*  f0e048c:	01653821 */ 	addu	$a3,$t3,$a1
/*  f0e0490:	0c002f02 */ 	jal	viGetWidth
/*  f0e0494:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e0498:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e049c:	0011cc03 */ 	sra	$t9,$s1,0x10
/*  f0e04a0:	0c002f06 */ 	jal	viGetHeight
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
/*  f0e04dc:	0fc55b92 */ 	jal	textRender
/*  f0e04e0:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e04e4:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e04e8:
/*  f0e04e8:	921801c9 */ 	lbu	$t8,0x1c9($s0)
/*  f0e04ec:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0e04f0:	17010002 */ 	bne	$t8,$at,.L0f0e04fc
/*  f0e04f4:	00000000 */ 	nop
/*  f0e04f8:	afa000e0 */ 	sw	$zero,0xe0($sp)
.L0f0e04fc:
/*  f0e04fc:	0fc54f93 */ 	jal	func0f153e4c
/*  f0e0500:	00000000 */ 	nop
.L0f0e0504:
/*  f0e0504:	8e0801b4 */ 	lw	$t0,0x1b4($s0)
.L0f0e0508:
/*  f0e0508:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0e050c:	15010039 */ 	bne	$t0,$at,.L0f0e05f4
/*  f0e0510:	00000000 */ 	nop
/*  f0e0514:	afb2009c */ 	sw	$s2,0x9c($sp)
/*  f0e0518:	0c002f40 */ 	jal	viGetViewLeft
/*  f0e051c:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e0520:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e0524:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f0e0528:	01608025 */ 	or	$s0,$t3,$zero
/*  f0e052c:	0c002f44 */ 	jal	viGetViewTop
/*  f0e0530:	8fb3009c */ 	lw	$s3,0x9c($sp)
/*  f0e0534:	44829000 */ 	mtc1	$v0,$f18
/*  f0e0538:	44905000 */ 	mtc1	$s0,$f10
/*  f0e053c:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e0540:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f0e0544:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0e0548:	46164182 */ 	mul.s	$f6,$f8,$f22
/*  f0e054c:	00000000 */ 	nop
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
/*  f0e0578:	0c002f22 */ 	jal	viGetViewWidth
/*  f0e057c:	ae680000 */ 	sw	$t0,0x0($s3)
/*  f0e0580:	0c002f40 */ 	jal	viGetViewLeft
/*  f0e0584:	a7a20092 */ 	sh	$v0,0x92($sp)
/*  f0e0588:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e058c:	00115c03 */ 	sra	$t3,$s1,0x10
/*  f0e0590:	0c002f44 */ 	jal	viGetViewTop
/*  f0e0594:	01608825 */ 	or	$s1,$t3,$zero
/*  f0e0598:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e059c:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0e05a0:	0c002f26 */ 	jal	viGetViewHeight
/*  f0e05a4:	01408025 */ 	or	$s0,$t2,$zero
/*  f0e05a8:	87a90092 */ 	lh	$t1,0x92($sp)
/*  f0e05ac:	00506821 */ 	addu	$t5,$v0,$s0
/*  f0e05b0:	448d3000 */ 	mtc1	$t5,$f6
/*  f0e05b4:	02296021 */ 	addu	$t4,$s1,$t1
/*  f0e05b8:	448c9000 */ 	mtc1	$t4,$f18
/*  f0e05bc:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f0e05c0:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f0e05c4:	46168282 */ 	mul.s	$f10,$f16,$f22
/*  f0e05c8:	00000000 */ 	nop
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
/*  f0e0630:	00000000 */ 	nop
/*  f0e0634:	8d8ca248 */ 	lw	$t4,%lo(g_Vars+0x288)($t4)
/*  f0e0638:	0fc54a3a */ 	jal	optionsGetShowMissionTime
/*  f0e063c:	8d840070 */ 	lw	$a0,0x70($t4)
/*  f0e0640:	10400019 */ 	beqz	$v0,.L0f0e06a8
/*  f0e0644:	3c188007 */ 	lui	$t8,%hi(var80075d60)
/*  f0e0648:	8f185d60 */ 	lw	$t8,%lo(var80075d60)($t8)
/*  f0e064c:	24030002 */ 	addiu	$v1,$zero,0x2
/*  f0e0650:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x318)
/*  f0e0654:	14780014 */ 	bne	$v1,$t8,.L0f0e06a8
/*  f0e0658:	00000000 */ 	nop
/*  f0e065c:	8d08a2d8 */ 	lw	$t0,%lo(g_Vars+0x318)($t0)
/*  f0e0660:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x4b4)
/*  f0e0664:	15000010 */ 	bnez	$t0,.L0f0e06a8
/*  f0e0668:	00000000 */ 	nop
/*  f0e066c:	8d6ba474 */ 	lw	$t3,%lo(g_Vars+0x4b4)($t3)
/*  f0e0670:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0e0674:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f0e0678:	1161000b */ 	beq	$t3,$at,.L0f0e06a8
/*  f0e067c:	00000000 */ 	nop
/*  f0e0680:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f0e0684:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e0688:	8de20000 */ 	lw	$v0,0x0($t7)
/*  f0e068c:	10620006 */ 	beq	$v1,$v0,.L0f0e06a8
/*  f0e0690:	00000000 */ 	nop
/*  f0e0694:	10410004 */ 	beq	$v0,$at,.L0f0e06a8
/*  f0e0698:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e069c:	0fc373bd */ 	jal	hudmsgRenderMissionTimer
/*  f0e06a0:	8fa500e0 */ 	lw	$a1,0xe0($sp)
/*  f0e06a4:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e06a8:
/*  f0e06a8:	0fc3736f */ 	jal	hudmsgIsZoomRangeVisible
/*  f0e06ac:	00000000 */ 	nop
/*  f0e06b0:	10400004 */ 	beqz	$v0,.L0f0e06c4
/*  f0e06b4:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e06b8:	0fc374ab */ 	jal	hudmsgRenderZoomRange
/*  f0e06bc:	8fa500e0 */ 	lw	$a1,0xe0($sp)
/*  f0e06c0:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e06c4:
/*  f0e06c4:	0fc2422e */ 	jal	countdownTimerRender
/*  f0e06c8:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e06cc:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e06d0:
/*  f0e06d0:	0fc54de0 */ 	jal	func0f153780
/*  f0e06d4:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e06d8:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f0e06dc:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0e06e0:	3c018008 */ 	lui	$at,%hi(g_ScaleX)
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
/*  f0e0718:	ac2afac0 */ 	sw	$t2,%lo(g_ScaleX)($at)
/*  f0e071c:	03e00008 */ 	jr	$ra
/*  f0e0720:	27bd0100 */ 	addiu	$sp,$sp,0x100
);
#else
GLOBAL_ASM(
glabel hudmsgsRender
.late_rodata
glabel var7f1adedc
.word 0x40490fdb
glabel var7f1adee0
.word hudmsgsRender+0xa5c
glabel var7f1adee4
.word hudmsgsRender+0xa5c
glabel var7f1adee8
.word hudmsgsRender+0xa5c
glabel var7f1adeec
.word hudmsgsRender+0x414
glabel var7f1adef0
.word hudmsgsRender+0x66c
glabel var7f1adef4
.word hudmsgsRender+0x7f0
.text
/*  f0dceb0:	27bdff00 */ 	addiu	$sp,$sp,-256
/*  f0dceb4:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0dceb8:	8def2d88 */ 	lw	$t7,0x2d88($t7)
/*  f0dcebc:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0dcec0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0dcec4:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f0dcec8:	00809025 */ 	or	$s2,$a0,$zero
/*  f0dcecc:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f0dced0:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f0dced4:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f0dced8:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f0dcedc:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f0dcee0:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f0dcee4:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f0dcee8:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f0dceec:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f0dcef0:	f7ba0050 */ 	sdc1	$f26,0x50($sp)
/*  f0dcef4:	f7b80048 */ 	sdc1	$f24,0x48($sp)
/*  f0dcef8:	f7b60040 */ 	sdc1	$f22,0x40($sp)
/*  f0dcefc:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f0dcf00:	afae00e0 */ 	sw	$t6,0xe0($sp)
/*  f0dcf04:	144f0005 */ 	bne	$v0,$t7,.NB0f0dcf1c
/*  f0dcf08:	afa200dc */ 	sw	$v0,0xdc($sp)
/*  f0dcf0c:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f0dcf10:	3c018008 */ 	lui	$at,0x8008
/*  f0dcf14:	10000003 */ 	beqz	$zero,.NB0f0dcf24
/*  f0dcf18:	ac382320 */ 	sw	$t8,0x2320($at)
.NB0f0dcf1c:
/*  f0dcf1c:	3c018008 */ 	lui	$at,0x8008
/*  f0dcf20:	ac222320 */ 	sw	$v0,0x2320($at)
.NB0f0dcf24:
/*  f0dcf24:	0fc5374a */ 	jal	func0f153628
/*  f0dcf28:	02402025 */ 	or	$a0,$s2,$zero
/*  f0dcf2c:	3c19800a */ 	lui	$t9,0x800a
/*  f0dcf30:	8f39e958 */ 	lw	$t9,-0x16a8($t9)
/*  f0dcf34:	00409025 */ 	or	$s2,$v0,$zero
/*  f0dcf38:	3c048007 */ 	lui	$a0,0x8007
/*  f0dcf3c:	07210005 */ 	bgez	$t9,.NB0f0dcf54
/*  f0dcf40:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0dcf44:	3c08800a */ 	lui	$t0,0x800a
/*  f0dcf48:	8d08e95c */ 	lw	$t0,-0x16a4($t0)
/*  f0dcf4c:	0500000e */ 	bltz	$t0,.NB0f0dcf88
/*  f0dcf50:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0dcf54:
/*  f0dcf54:	3c098007 */ 	lui	$t1,0x8007
/*  f0dcf58:	8d292e24 */ 	lw	$t1,0x2e24($t1)
/*  f0dcf5c:	1120000a */ 	beqz	$t1,.NB0f0dcf88
/*  f0dcf60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcf64:	3c0a8006 */ 	lui	$t2,0x8006
/*  f0dcf68:	8d4af2f0 */ 	lw	$t2,-0xd10($t2)
/*  f0dcf6c:	15400006 */ 	bnez	$t2,.NB0f0dcf88
/*  f0dcf70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcf74:	3c0b800a */ 	lui	$t3,0x800a
/*  f0dcf78:	8d6be94c */ 	lw	$t3,-0x16b4($t3)
/*  f0dcf7c:	15600002 */ 	bnez	$t3,.NB0f0dcf88
/*  f0dcf80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dcf84:	afa000dc */ 	sw	$zero,0xdc($sp)
.NB0f0dcf88:
/*  f0dcf88:	8c8436a8 */ 	lw	$a0,0x36a8($a0)
/*  f0dcf8c:	27b700e4 */ 	addiu	$s7,$sp,0xe4
/*  f0dcf90:	27b600e8 */ 	addiu	$s6,$sp,0xe8
/*  f0dcf94:	188002a5 */ 	blez	$a0,.NB0f0dda2c
/*  f0dcf98:	2415ff00 */ 	addiu	$s5,$zero,-256
/*  f0dcf9c:	4481d000 */ 	mtc1	$at,$f26
/*  f0dcfa0:	3c0140e0 */ 	lui	$at,0x40e0
/*  f0dcfa4:	4481c000 */ 	mtc1	$at,$f24
/*  f0dcfa8:	3c014080 */ 	lui	$at,0x4080
/*  f0dcfac:	4481b000 */ 	mtc1	$at,$f22
/*  f0dcfb0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0dcfb4:	4481a000 */ 	mtc1	$at,$f20
/*  f0dcfb8:	afa00088 */ 	sw	$zero,0x88($sp)
/*  f0dcfbc:	241e00ff */ 	addiu	$s8,$zero,0xff
.NB0f0dcfc0:
/*  f0dcfc0:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0dcfc4:	8dad36ac */ 	lw	$t5,0x36ac($t5)
/*  f0dcfc8:	8fac0088 */ 	lw	$t4,0x88($sp)
/*  f0dcfcc:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0dcfd0:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0dcfd4:	018d8021 */ 	addu	$s0,$t4,$t5
/*  f0dcfd8:	92030004 */ 	lbu	$v1,0x4($s0)
/*  f0dcfdc:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0dcfe0:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0dcfe4:	54600004 */ 	bnezl	$v1,.NB0f0dcff8
/*  f0dcfe8:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0dcfec:	1000028a */ 	beqz	$zero,.NB0f0dda18
/*  f0dcff0:	00021080 */ 	sll	$v0,$v0,0x2
/*  f0dcff4:	92020000 */ 	lbu	$v0,0x0($s0)
.NB0f0dcff8:
/*  f0dcff8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0dcffc:	5040000a */ 	beqzl	$v0,.NB0f0dd028
/*  f0dd000:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0dd004:	10410007 */ 	beq	$v0,$at,.NB0f0dd024
/*  f0dd008:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f0dd00c:	51c0000c */ 	beqzl	$t6,.NB0f0dd040
/*  f0dd010:	92190003 */ 	lbu	$t9,0x3($s0)
/*  f0dd014:	3c0f800a */ 	lui	$t7,0x800a
/*  f0dd018:	8defe94c */ 	lw	$t7,-0x16b4($t7)
/*  f0dd01c:	8e1801c0 */ 	lw	$t8,0x1c0($s0)
/*  f0dd020:	11f80006 */ 	beq	$t7,$t8,.NB0f0dd03c
.NB0f0dd024:
/*  f0dd024:	00041100 */ 	sll	$v0,$a0,0x4
.NB0f0dd028:
/*  f0dd028:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0dd02c:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0dd030:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0dd034:	10000278 */ 	beqz	$zero,.NB0f0dda18
/*  f0dd038:	00021080 */ 	sll	$v0,$v0,0x2
.NB0f0dd03c:
/*  f0dd03c:	92190003 */ 	lbu	$t9,0x3($s0)
.NB0f0dd040:
/*  f0dd040:	53200022 */ 	beqzl	$t9,.NB0f0dd0cc
/*  f0dd044:	8e130010 */ 	lw	$s3,0x10($s0)
/*  f0dd048:	96080006 */ 	lhu	$t0,0x6($s0)
/*  f0dd04c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0dd050:	44882000 */ 	mtc1	$t0,$f4
/*  f0dd054:	05010004 */ 	bgez	$t0,.NB0f0dd068
/*  f0dd058:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0dd05c:	44814000 */ 	mtc1	$at,$f8
/*  f0dd060:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd064:	46083180 */ 	add.s	$f6,$f6,$f8
.NB0f0dd068:
/*  f0dd068:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0dd06c:	c42a820c */ 	lwc1	$f10,-0x7df4($at)
/*  f0dd070:	3c014270 */ 	lui	$at,0x4270
/*  f0dd074:	44819000 */ 	mtc1	$at,$f18
/*  f0dd078:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0dd07c:	0c006d55 */ 	jal	sinf
/*  f0dd080:	46128303 */ 	div.s	$f12,$f16,$f18
/*  f0dd084:	44802000 */ 	mtc1	$zero,$f4
/*  f0dd088:	3c014340 */ 	lui	$at,0x4340
/*  f0dd08c:	44814000 */ 	mtc1	$at,$f8
/*  f0dd090:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0dd094:	46000086 */ 	mov.s	$f2,$f0
/*  f0dd098:	45000002 */ 	bc1f	.NB0f0dd0a4
/*  f0dd09c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd0a0:	46000087 */ 	neg.s	$f2,$f0
.NB0f0dd0a4:
/*  f0dd0a4:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0dd0a8:	8e090010 */ 	lw	$t1,0x10($s0)
/*  f0dd0ac:	8e140014 */ 	lw	$s4,0x14($s0)
/*  f0dd0b0:	92030004 */ 	lbu	$v1,0x4($s0)
/*  f0dd0b4:	01355024 */ 	and	$t2,$t1,$s5
/*  f0dd0b8:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f0dd0bc:	440c5000 */ 	mfc1	$t4,$f10
/*  f0dd0c0:	10000005 */ 	beqz	$zero,.NB0f0dd0d8
/*  f0dd0c4:	014c9821 */ 	addu	$s3,$t2,$t4
/*  f0dd0c8:	8e130010 */ 	lw	$s3,0x10($s0)
.NB0f0dd0cc:
/*  f0dd0cc:	8e140014 */ 	lw	$s4,0x14($s0)
/*  f0dd0d0:	366d00a0 */ 	ori	$t5,$s3,0xa0
/*  f0dd0d4:	01a09825 */ 	or	$s3,$t5,$zero
.NB0f0dd0d8:
/*  f0dd0d8:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0dd0dc:	1061001c */ 	beq	$v1,$at,.NB0f0dd150
/*  f0dd0e0:	00601025 */ 	or	$v0,$v1,$zero
/*  f0dd0e4:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f0dd0e8:	004e0019 */ 	multu	$v0,$t6
/*  f0dd0ec:	00401825 */ 	or	$v1,$v0,$zero
/*  f0dd0f0:	329800ff */ 	andi	$t8,$s4,0xff
/*  f0dd0f4:	02754024 */ 	and	$t0,$s3,$s5
/*  f0dd0f8:	02955824 */ 	and	$t3,$s4,$s5
/*  f0dd0fc:	00007812 */ 	mflo	$t7
/*  f0dd100:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd104:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd108:	01fe001b */ 	divu	$zero,$t7,$s8
/*  f0dd10c:	00002012 */ 	mflo	$a0
/*  f0dd110:	308900ff */ 	andi	$t1,$a0,0xff
/*  f0dd114:	17c00002 */ 	bnez	$s8,.NB0f0dd120
/*  f0dd118:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd11c:	0007000d */ 	break	0x7
.NB0f0dd120:
/*  f0dd120:	00780019 */ 	multu	$v1,$t8
/*  f0dd124:	01099821 */ 	addu	$s3,$t0,$t1
/*  f0dd128:	0000c812 */ 	mflo	$t9
/*  f0dd12c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd130:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd134:	033e001b */ 	divu	$zero,$t9,$s8
/*  f0dd138:	00002812 */ 	mflo	$a1
/*  f0dd13c:	30aa00ff */ 	andi	$t2,$a1,0xff
/*  f0dd140:	17c00002 */ 	bnez	$s8,.NB0f0dd14c
/*  f0dd144:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd148:	0007000d */ 	break	0x7
.NB0f0dd14c:
/*  f0dd14c:	016aa021 */ 	addu	$s4,$t3,$t2
.NB0f0dd150:
/*  f0dd150:	960c0018 */ 	lhu	$t4,0x18($s0)
/*  f0dd154:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0dd158:	afac00e8 */ 	sw	$t4,0xe8($sp)
/*  f0dd15c:	960d001a */ 	lhu	$t5,0x1a($s0)
/*  f0dd160:	afad00e4 */ 	sw	$t5,0xe4($sp)
/*  f0dd164:	8e0e01b4 */ 	lw	$t6,0x1b4($s0)
/*  f0dd168:	55c10011 */ 	bnel	$t6,$at,.NB0f0dd1b0
/*  f0dd16c:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
/*  f0dd170:	0fc2fcea */ 	jal	currentPlayerIsHealthVisible
/*  f0dd174:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd178:	5040000d */ 	beqzl	$v0,.NB0f0dd1b0
/*  f0dd17c:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
/*  f0dd180:	0fc2fcb4 */ 	jal	currentPlayerGetHealthBarHeightFrac
/*  f0dd184:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd188:	3c014180 */ 	lui	$at,0x4180
/*  f0dd18c:	44818000 */ 	mtc1	$at,$f16
/*  f0dd190:	8faf00e4 */ 	lw	$t7,0xe4($sp)
/*  f0dd194:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0dd198:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0dd19c:	44192000 */ 	mfc1	$t9,$f4
/*  f0dd1a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd1a4:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f0dd1a8:	afa800e4 */ 	sw	$t0,0xe4($sp)
/*  f0dd1ac:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
.NB0f0dd1b0:
/*  f0dd1b0:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0dd1b4:	5521003b */ 	bnel	$t1,$at,.NB0f0dd2a4
/*  f0dd1b8:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f0dd1bc:	8fab00e8 */ 	lw	$t3,0xe8($sp)
/*  f0dd1c0:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0dd1c4:	8d8c2320 */ 	lw	$t4,0x2320($t4)
/*  f0dd1c8:	256afffc */ 	addiu	$t2,$t3,-4
/*  f0dd1cc:	8fa900e4 */ 	lw	$t1,0xe4($sp)
/*  f0dd1d0:	014c0019 */ 	multu	$t2,$t4
/*  f0dd1d4:	3c01ed00 */ 	lui	$at,0xed00
/*  f0dd1d8:	252bfffc */ 	addiu	$t3,$t1,-4
/*  f0dd1dc:	448b9000 */ 	mtc1	$t3,$f18
/*  f0dd1e0:	02401025 */ 	or	$v0,$s2,$zero
/*  f0dd1e4:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0dd1e8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0dd1ec:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0dd1f0:	00006812 */ 	mflo	$t5
/*  f0dd1f4:	448d4000 */ 	mtc1	$t5,$f8
/*  f0dd1f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd1fc:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0dd200:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f0dd204:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd208:	46162202 */ 	mul.s	$f8,$f4,$f22
/*  f0dd20c:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0dd210:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f0dd214:	44188000 */ 	mfc1	$t8,$f16
/*  f0dd218:	440c3000 */ 	mfc1	$t4,$f6
/*  f0dd21c:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f0dd220:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f0dd224:	03214025 */ 	or	$t0,$t9,$at
/*  f0dd228:	318d0fff */ 	andi	$t5,$t4,0xfff
/*  f0dd22c:	010d7025 */ 	or	$t6,$t0,$t5
/*  f0dd230:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0dd234:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f0dd238:	9618001c */ 	lhu	$t8,0x1c($s0)
/*  f0dd23c:	8d6b2320 */ 	lw	$t3,0x2320($t3)
/*  f0dd240:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f0dd244:	27290003 */ 	addiu	$t1,$t9,0x3
/*  f0dd248:	012b0019 */ 	multu	$t1,$t3
/*  f0dd24c:	960f001e */ 	lhu	$t7,0x1e($s0)
/*  f0dd250:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0dd254:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f0dd258:	27290003 */ 	addiu	$t1,$t9,0x3
/*  f0dd25c:	44894000 */ 	mtc1	$t1,$f8
/*  f0dd260:	00005012 */ 	mflo	$t2
/*  f0dd264:	448a5000 */ 	mtc1	$t2,$f10
/*  f0dd268:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0dd26c:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0dd270:	46168482 */ 	mul.s	$f18,$f16,$f22
/*  f0dd274:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd278:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f0dd27c:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0dd280:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0dd284:	44082000 */ 	mfc1	$t0,$f4
/*  f0dd288:	440a8000 */ 	mfc1	$t2,$f16
/*  f0dd28c:	310d0fff */ 	andi	$t5,$t0,0xfff
/*  f0dd290:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f0dd294:	314c0fff */ 	andi	$t4,$t2,0xfff
/*  f0dd298:	01cc4025 */ 	or	$t0,$t6,$t4
/*  f0dd29c:	ac480004 */ 	sw	$t0,0x4($v0)
/*  f0dd2a0:	920d0000 */ 	lbu	$t5,0x0($s0)
.NB0f0dd2a4:
/*  f0dd2a4:	2da10006 */ 	sltiu	$at,$t5,0x6
/*  f0dd2a8:	10200198 */ 	beqz	$at,.NB0f0dd90c
/*  f0dd2ac:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0dd2b0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0dd2b4:	002d0821 */ 	addu	$at,$at,$t5
/*  f0dd2b8:	8c2d8210 */ 	lw	$t5,-0x7df0($at)
/*  f0dd2bc:	01a00008 */ 	jr	$t5
/*  f0dd2c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd2c4:	8e110010 */ 	lw	$s1,0x10($s0)
/*  f0dd2c8:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0dd2cc:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0dd2d0:	36380040 */ 	ori	$t8,$s1,0x40
/*  f0dd2d4:	1041000e */ 	beq	$v0,$at,.NB0f0dd310
/*  f0dd2d8:	03008825 */ 	or	$s1,$t8,$zero
/*  f0dd2dc:	330f00ff */ 	andi	$t7,$t8,0xff
/*  f0dd2e0:	004f0019 */ 	multu	$v0,$t7
/*  f0dd2e4:	02354824 */ 	and	$t1,$s1,$s5
/*  f0dd2e8:	0000c812 */ 	mflo	$t9
/*  f0dd2ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd2f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd2f4:	033e001b */ 	divu	$zero,$t9,$s8
/*  f0dd2f8:	00001812 */ 	mflo	$v1
/*  f0dd2fc:	306b00ff */ 	andi	$t3,$v1,0xff
/*  f0dd300:	17c00002 */ 	bnez	$s8,.NB0f0dd30c
/*  f0dd304:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd308:	0007000d */ 	break	0x7
.NB0f0dd30c:
/*  f0dd30c:	012b8821 */ 	addu	$s1,$t1,$t3
.NB0f0dd310:
/*  f0dd310:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0dd314:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0dd318:	00420019 */ 	multu	$v0,$v0
/*  f0dd31c:	00005012 */ 	mflo	$t2
/*  f0dd320:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd324:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd328:	00630019 */ 	multu	$v1,$v1
/*  f0dd32c:	00007012 */ 	mflo	$t6
/*  f0dd330:	014e6021 */ 	addu	$t4,$t2,$t6
/*  f0dd334:	448c9000 */ 	mtc1	$t4,$f18
/*  f0dd338:	0c012e84 */ 	jal	sqrtf
/*  f0dd33c:	46809320 */ 	cvt.s.w	$f12,$f18
/*  f0dd340:	3c014304 */ 	lui	$at,0x4304
/*  f0dd344:	44812000 */ 	mtc1	$at,$f4
/*  f0dd348:	44808000 */ 	mtc1	$zero,$f16
/*  f0dd34c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0dd350:	46040200 */ 	add.s	$f8,$f0,$f4
/*  f0dd354:	46184083 */ 	div.s	$f2,$f8,$f24
/*  f0dd358:	4602d03c */ 	c.lt.s	$f26,$f2
/*  f0dd35c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd360:	45020003 */ 	bc1fl	.NB0f0dd370
/*  f0dd364:	96080006 */ 	lhu	$t0,0x6($s0)
/*  f0dd368:	4600d086 */ 	mov.s	$f2,$f26
/*  f0dd36c:	96080006 */ 	lhu	$t0,0x6($s0)
.NB0f0dd370:
/*  f0dd370:	44883000 */ 	mtc1	$t0,$f6
/*  f0dd374:	05010004 */ 	bgez	$t0,.NB0f0dd388
/*  f0dd378:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f0dd37c:	44815000 */ 	mtc1	$at,$f10
/*  f0dd380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd384:	460a6300 */ 	add.s	$f12,$f12,$f10
.NB0f0dd388:
/*  f0dd388:	46026083 */ 	div.s	$f2,$f12,$f2
/*  f0dd38c:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f0dd390:	8fa500e4 */ 	lw	$a1,0xe4($sp)
/*  f0dd394:	00003825 */ 	or	$a3,$zero,$zero
/*  f0dd398:	46186002 */ 	mul.s	$f0,$f12,$f24
/*  f0dd39c:	44060000 */ 	mfc1	$a2,$f0
/*  f0dd3a0:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f0dd3a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd3a8:	45020003 */ 	bc1fl	.NB0f0dd3b8
/*  f0dd3ac:	4610103c */ 	c.lt.s	$f2,$f16
/*  f0dd3b0:	4600a086 */ 	mov.s	$f2,$f20
/*  f0dd3b4:	4610103c */ 	c.lt.s	$f2,$f16
.NB0f0dd3b8:
/*  f0dd3b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd3bc:	45000003 */ 	bc1f	.NB0f0dd3cc
/*  f0dd3c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd3c4:	44801000 */ 	mtc1	$zero,$f2
/*  f0dd3c8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0dd3cc:
/*  f0dd3cc:	0fc5389f */ 	jal	func0f153c20
/*  f0dd3d0:	e7a200c0 */ 	swc1	$f2,0xc0($sp)
/*  f0dd3d4:	920d0001 */ 	lbu	$t5,0x1($s0)
/*  f0dd3d8:	c7a200c0 */ 	lwc1	$f2,0xc0($sp)
/*  f0dd3dc:	02402025 */ 	or	$a0,$s2,$zero
/*  f0dd3e0:	11a00027 */ 	beqz	$t5,.NB0f0dd480
/*  f0dd3e4:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0dd3e8:	8faf00e4 */ 	lw	$t7,0xe4($sp)
/*  f0dd3ec:	9609001e */ 	lhu	$t1,0x1e($s0)
/*  f0dd3f0:	8fb800e8 */ 	lw	$t8,0xe8($sp)
/*  f0dd3f4:	9619001c */ 	lhu	$t9,0x1c($s0)
/*  f0dd3f8:	012f5821 */ 	addu	$t3,$t1,$t7
/*  f0dd3fc:	256a0002 */ 	addiu	$t2,$t3,0x2
/*  f0dd400:	03383821 */ 	addu	$a3,$t9,$t8
/*  f0dd404:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f0dd408:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0dd40c:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f0dd410:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0dd414:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0dd418:	02402025 */ 	or	$a0,$s2,$zero
/*  f0dd41c:	25e6fffd */ 	addiu	$a2,$t7,-3
/*  f0dd420:	0fc36b96 */ 	jal	hudmsgRenderBox
/*  f0dd424:	2705fffd */ 	addiu	$a1,$t8,-3
/*  f0dd428:	0c002f77 */ 	jal	viGetWidth
/*  f0dd42c:	00409025 */ 	or	$s2,$v0,$zero
/*  f0dd430:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0dd434:	00117403 */ 	sra	$t6,$s1,0x10
/*  f0dd438:	0c002f7b */ 	jal	viGetHeight
/*  f0dd43c:	01c08825 */ 	or	$s1,$t6,$zero
/*  f0dd440:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f0dd444:	02402025 */ 	or	$a0,$s2,$zero
/*  f0dd448:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0dd44c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0dd450:	8e08000c */ 	lw	$t0,0xc($s0)
/*  f0dd454:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0dd458:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0dd45c:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0dd460:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0dd464:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0dd468:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0dd46c:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0dd470:	0fc541a6 */ 	jal	textRenderProjected
/*  f0dd474:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0dd478:	1000001f */ 	beqz	$zero,.NB0f0dd4f8
/*  f0dd47c:	00409025 */ 	or	$s2,$v0,$zero
.NB0f0dd480:
/*  f0dd480:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f0dd484:	9609001e */ 	lhu	$t1,0x1e($s0)
/*  f0dd488:	9618001c */ 	lhu	$t8,0x1c($s0)
/*  f0dd48c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0dd490:	01267821 */ 	addu	$t7,$t1,$a2
/*  f0dd494:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0dd498:	0fc53824 */ 	jal	func0f153a34
/*  f0dd49c:	03053821 */ 	addu	$a3,$t8,$a1
/*  f0dd4a0:	0c002f77 */ 	jal	viGetWidth
/*  f0dd4a4:	00409025 */ 	or	$s2,$v0,$zero
/*  f0dd4a8:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0dd4ac:	00115c03 */ 	sra	$t3,$s1,0x10
/*  f0dd4b0:	0c002f7b */ 	jal	viGetHeight
/*  f0dd4b4:	01608825 */ 	or	$s1,$t3,$zero
/*  f0dd4b8:	8e0a0008 */ 	lw	$t2,0x8($s0)
/*  f0dd4bc:	02402025 */ 	or	$a0,$s2,$zero
/*  f0dd4c0:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0dd4c4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0dd4c8:	8e0e000c */ 	lw	$t6,0xc($s0)
/*  f0dd4cc:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0dd4d0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0dd4d4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0dd4d8:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0dd4dc:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f0dd4e0:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0dd4e4:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0dd4e8:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0dd4ec:	0fc54529 */ 	jal	textRender
/*  f0dd4f0:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0dd4f4:	00409025 */ 	or	$s2,$v0,$zero
.NB0f0dd4f8:
/*  f0dd4f8:	920c01c9 */ 	lbu	$t4,0x1c9($s0)
/*  f0dd4fc:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0dd500:	15810002 */ 	bne	$t4,$at,.NB0f0dd50c
/*  f0dd504:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd508:	afa000e0 */ 	sw	$zero,0xe0($sp)
.NB0f0dd50c:
/*  f0dd50c:	0fc5392a */ 	jal	func0f153e4c
/*  f0dd510:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd514:	100000fe */ 	beqz	$zero,.NB0f0dd910
/*  f0dd518:	8e0c01b4 */ 	lw	$t4,0x1b4($s0)
/*  f0dd51c:	92080001 */ 	lbu	$t0,0x1($s0)
/*  f0dd520:	8fab00e8 */ 	lw	$t3,0xe8($sp)
/*  f0dd524:	8faa00e4 */ 	lw	$t2,0xe4($sp)
/*  f0dd528:	11000037 */ 	beqz	$t0,.NB0f0dd608
/*  f0dd52c:	2565fffd */ 	addiu	$a1,$t3,-3
/*  f0dd530:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0dd534:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0dd538:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0dd53c:	34780040 */ 	ori	$t8,$v1,0x40
/*  f0dd540:	1041000e */ 	beq	$v0,$at,.NB0f0dd57c
/*  f0dd544:	03001825 */ 	or	$v1,$t8,$zero
/*  f0dd548:	330d00ff */ 	andi	$t5,$t8,0xff
/*  f0dd54c:	004d0019 */ 	multu	$v0,$t5
/*  f0dd550:	0075c824 */ 	and	$t9,$v1,$s5
/*  f0dd554:	00004812 */ 	mflo	$t1
/*  f0dd558:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd55c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd560:	013e001b */ 	divu	$zero,$t1,$s8
/*  f0dd564:	00002012 */ 	mflo	$a0
/*  f0dd568:	308f00ff */ 	andi	$t7,$a0,0xff
/*  f0dd56c:	17c00002 */ 	bnez	$s8,.NB0f0dd578
/*  f0dd570:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd574:	0007000d */ 	break	0x7
.NB0f0dd578:
/*  f0dd578:	032f1821 */ 	addu	$v1,$t9,$t7
.NB0f0dd57c:
/*  f0dd57c:	960c001e */ 	lhu	$t4,0x1e($s0)
/*  f0dd580:	960e001c */ 	lhu	$t6,0x1c($s0)
/*  f0dd584:	e7b4001c */ 	swc1	$f20,0x1c($sp)
/*  f0dd588:	018a4021 */ 	addu	$t0,$t4,$t2
/*  f0dd58c:	25180002 */ 	addiu	$t8,$t0,0x2
/*  f0dd590:	01cb3821 */ 	addu	$a3,$t6,$t3
/*  f0dd594:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f0dd598:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0dd59c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0dd5a0:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0dd5a4:	02402025 */ 	or	$a0,$s2,$zero
/*  f0dd5a8:	0fc36b96 */ 	jal	hudmsgRenderBox
/*  f0dd5ac:	2546fffd */ 	addiu	$a2,$t2,-3
/*  f0dd5b0:	0c002f77 */ 	jal	viGetWidth
/*  f0dd5b4:	00409025 */ 	or	$s2,$v0,$zero
/*  f0dd5b8:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0dd5bc:	00116c03 */ 	sra	$t5,$s1,0x10
/*  f0dd5c0:	0c002f7b */ 	jal	viGetHeight
/*  f0dd5c4:	01a08825 */ 	or	$s1,$t5,$zero
/*  f0dd5c8:	8e090008 */ 	lw	$t1,0x8($s0)
/*  f0dd5cc:	02402025 */ 	or	$a0,$s2,$zero
/*  f0dd5d0:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0dd5d4:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0dd5d8:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f0dd5dc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0dd5e0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0dd5e4:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0dd5e8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0dd5ec:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0dd5f0:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0dd5f4:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0dd5f8:	0fc541a6 */ 	jal	textRenderProjected
/*  f0dd5fc:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0dd600:	10000021 */ 	beqz	$zero,.NB0f0dd688
/*  f0dd604:	00409025 */ 	or	$s2,$v0,$zero
.NB0f0dd608:
/*  f0dd608:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f0dd60c:	960c001e */ 	lhu	$t4,0x1e($s0)
/*  f0dd610:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0dd614:	960b001c */ 	lhu	$t3,0x1c($s0)
/*  f0dd618:	01865021 */ 	addu	$t2,$t4,$a2
/*  f0dd61c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0dd620:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0dd624:	02402025 */ 	or	$a0,$s2,$zero
/*  f0dd628:	0fc53824 */ 	jal	func0f153a34
/*  f0dd62c:	01653821 */ 	addu	$a3,$t3,$a1
/*  f0dd630:	0c002f77 */ 	jal	viGetWidth
/*  f0dd634:	00409025 */ 	or	$s2,$v0,$zero
/*  f0dd638:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0dd63c:	00114403 */ 	sra	$t0,$s1,0x10
/*  f0dd640:	0c002f7b */ 	jal	viGetHeight
/*  f0dd644:	01008825 */ 	or	$s1,$t0,$zero
/*  f0dd648:	8e180008 */ 	lw	$t8,0x8($s0)
/*  f0dd64c:	02402025 */ 	or	$a0,$s2,$zero
/*  f0dd650:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0dd654:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0dd658:	8e0d000c */ 	lw	$t5,0xc($s0)
/*  f0dd65c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0dd660:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0dd664:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0dd668:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0dd66c:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f0dd670:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0dd674:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0dd678:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0dd67c:	0fc54529 */ 	jal	textRender
/*  f0dd680:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0dd684:	00409025 */ 	or	$s2,$v0,$zero
.NB0f0dd688:
/*  f0dd688:	920901c9 */ 	lbu	$t1,0x1c9($s0)
/*  f0dd68c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0dd690:	5521009f */ 	bnel	$t1,$at,.NB0f0dd910
/*  f0dd694:	8e0c01b4 */ 	lw	$t4,0x1b4($s0)
/*  f0dd698:	1000009c */ 	beqz	$zero,.NB0f0dd90c
/*  f0dd69c:	afa000e0 */ 	sw	$zero,0xe0($sp)
/*  f0dd6a0:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0dd6a4:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0dd6a8:	00420019 */ 	multu	$v0,$v0
/*  f0dd6ac:	0000c812 */ 	mflo	$t9
/*  f0dd6b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd6b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd6b8:	00630019 */ 	multu	$v1,$v1
/*  f0dd6bc:	00005812 */ 	mflo	$t3
/*  f0dd6c0:	032b7821 */ 	addu	$t7,$t9,$t3
/*  f0dd6c4:	448f9000 */ 	mtc1	$t7,$f18
/*  f0dd6c8:	0c012e84 */ 	jal	sqrtf
/*  f0dd6cc:	46809320 */ 	cvt.s.w	$f12,$f18
/*  f0dd6d0:	3c0142b8 */ 	lui	$at,0x42b8
/*  f0dd6d4:	44812000 */ 	mtc1	$at,$f4
/*  f0dd6d8:	8e110010 */ 	lw	$s1,0x10($s0)
/*  f0dd6dc:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0dd6e0:	46040200 */ 	add.s	$f8,$f0,$f4
/*  f0dd6e4:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0dd6e8:	362c0040 */ 	ori	$t4,$s1,0x40
/*  f0dd6ec:	01808825 */ 	or	$s1,$t4,$zero
/*  f0dd6f0:	1041000e */ 	beq	$v0,$at,.NB0f0dd72c
/*  f0dd6f4:	46184083 */ 	div.s	$f2,$f8,$f24
/*  f0dd6f8:	318e00ff */ 	andi	$t6,$t4,0xff
/*  f0dd6fc:	004e0019 */ 	multu	$v0,$t6
/*  f0dd700:	02354024 */ 	and	$t0,$s1,$s5
/*  f0dd704:	00005012 */ 	mflo	$t2
/*  f0dd708:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd70c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd710:	015e001b */ 	divu	$zero,$t2,$s8
/*  f0dd714:	00001812 */ 	mflo	$v1
/*  f0dd718:	307800ff */ 	andi	$t8,$v1,0xff
/*  f0dd71c:	17c00002 */ 	bnez	$s8,.NB0f0dd728
/*  f0dd720:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd724:	0007000d */ 	break	0x7
.NB0f0dd728:
/*  f0dd728:	01188821 */ 	addu	$s1,$t0,$t8
.NB0f0dd72c:
/*  f0dd72c:	960d0006 */ 	lhu	$t5,0x6($s0)
/*  f0dd730:	3c014f80 */ 	lui	$at,0x4f80
/*  f0dd734:	448d3000 */ 	mtc1	$t5,$f6
/*  f0dd738:	05a10004 */ 	bgez	$t5,.NB0f0dd74c
/*  f0dd73c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0dd740:	44818000 */ 	mtc1	$at,$f16
/*  f0dd744:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd748:	46105280 */ 	add.s	$f10,$f10,$f16
.NB0f0dd74c:
/*  f0dd74c:	460a1481 */ 	sub.s	$f18,$f2,$f10
/*  f0dd750:	9609001c */ 	lhu	$t1,0x1c($s0)
/*  f0dd754:	8fb900e8 */ 	lw	$t9,0xe8($sp)
/*  f0dd758:	960b001e */ 	lhu	$t3,0x1e($s0)
/*  f0dd75c:	46189002 */ 	mul.s	$f0,$f18,$f24
/*  f0dd760:	8faf00e4 */ 	lw	$t7,0xe4($sp)
/*  f0dd764:	e7a200a8 */ 	swc1	$f2,0xa8($sp)
/*  f0dd768:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f0dd76c:	01392021 */ 	addu	$a0,$t1,$t9
/*  f0dd770:	016f2821 */ 	addu	$a1,$t3,$t7
/*  f0dd774:	44060000 */ 	mfc1	$a2,$f0
/*  f0dd778:	0fc5389f */ 	jal	func0f153c20
/*  f0dd77c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd780:	c7a200a8 */ 	lwc1	$f2,0xa8($sp)
/*  f0dd784:	3c014f80 */ 	lui	$at,0x4f80
/*  f0dd788:	8faa00e8 */ 	lw	$t2,0xe8($sp)
/*  f0dd78c:	4602d03c */ 	c.lt.s	$f26,$f2
/*  f0dd790:	8fa800e4 */ 	lw	$t0,0xe4($sp)
/*  f0dd794:	02402025 */ 	or	$a0,$s2,$zero
/*  f0dd798:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0dd79c:	45000002 */ 	bc1f	.NB0f0dd7a8
/*  f0dd7a0:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f0dd7a4:	4600d086 */ 	mov.s	$f2,$f26
.NB0f0dd7a8:
/*  f0dd7a8:	960c0006 */ 	lhu	$t4,0x6($s0)
/*  f0dd7ac:	448c2000 */ 	mtc1	$t4,$f4
/*  f0dd7b0:	05810004 */ 	bgez	$t4,.NB0f0dd7c4
/*  f0dd7b4:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0dd7b8:	44813000 */ 	mtc1	$at,$f6
/*  f0dd7bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd7c0:	46064200 */ 	add.s	$f8,$f8,$f6
.NB0f0dd7c4:
/*  f0dd7c4:	46024083 */ 	div.s	$f2,$f8,$f2
/*  f0dd7c8:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f0dd7cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd7d0:	45020003 */ 	bc1fl	.NB0f0dd7e0
/*  f0dd7d4:	920e0001 */ 	lbu	$t6,0x1($s0)
/*  f0dd7d8:	4600a086 */ 	mov.s	$f2,$f20
/*  f0dd7dc:	920e0001 */ 	lbu	$t6,0x1($s0)
.NB0f0dd7e0:
/*  f0dd7e0:	51c00027 */ 	beqzl	$t6,.NB0f0dd880
/*  f0dd7e4:	960d001e */ 	lhu	$t5,0x1e($s0)
/*  f0dd7e8:	960d001e */ 	lhu	$t5,0x1e($s0)
/*  f0dd7ec:	9618001c */ 	lhu	$t8,0x1c($s0)
/*  f0dd7f0:	4602a401 */ 	sub.s	$f16,$f20,$f2
/*  f0dd7f4:	01a84821 */ 	addu	$t1,$t5,$t0
/*  f0dd7f8:	25390002 */ 	addiu	$t9,$t1,0x2
/*  f0dd7fc:	030a3821 */ 	addu	$a3,$t8,$t2
/*  f0dd800:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f0dd804:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0dd808:	e7b0001c */ 	swc1	$f16,0x1c($sp)
/*  f0dd80c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0dd810:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0dd814:	02402025 */ 	or	$a0,$s2,$zero
/*  f0dd818:	2545fffd */ 	addiu	$a1,$t2,-3
/*  f0dd81c:	0fc36b96 */ 	jal	hudmsgRenderBox
/*  f0dd820:	2506fffd */ 	addiu	$a2,$t0,-3
/*  f0dd824:	0c002f77 */ 	jal	viGetWidth
/*  f0dd828:	00409025 */ 	or	$s2,$v0,$zero
/*  f0dd82c:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0dd830:	00115c03 */ 	sra	$t3,$s1,0x10
/*  f0dd834:	0c002f7b */ 	jal	viGetHeight
/*  f0dd838:	01608825 */ 	or	$s1,$t3,$zero
/*  f0dd83c:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*  f0dd840:	02402025 */ 	or	$a0,$s2,$zero
/*  f0dd844:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0dd848:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0dd84c:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f0dd850:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0dd854:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0dd858:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0dd85c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0dd860:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0dd864:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0dd868:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0dd86c:	0fc541a6 */ 	jal	textRenderProjected
/*  f0dd870:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0dd874:	1000001e */ 	beqz	$zero,.NB0f0dd8f0
/*  f0dd878:	00409025 */ 	or	$s2,$v0,$zero
/*  f0dd87c:	960d001e */ 	lhu	$t5,0x1e($s0)
.NB0f0dd880:
/*  f0dd880:	960a001c */ 	lhu	$t2,0x1c($s0)
/*  f0dd884:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0dd888:	01a64021 */ 	addu	$t0,$t5,$a2
/*  f0dd88c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0dd890:	0fc53824 */ 	jal	func0f153a34
/*  f0dd894:	01453821 */ 	addu	$a3,$t2,$a1
/*  f0dd898:	0c002f77 */ 	jal	viGetWidth
/*  f0dd89c:	00409025 */ 	or	$s2,$v0,$zero
/*  f0dd8a0:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0dd8a4:	00114c03 */ 	sra	$t1,$s1,0x10
/*  f0dd8a8:	0c002f7b */ 	jal	viGetHeight
/*  f0dd8ac:	01208825 */ 	or	$s1,$t1,$zero
/*  f0dd8b0:	8e190008 */ 	lw	$t9,0x8($s0)
/*  f0dd8b4:	02402025 */ 	or	$a0,$s2,$zero
/*  f0dd8b8:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0dd8bc:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0dd8c0:	8e0b000c */ 	lw	$t3,0xc($s0)
/*  f0dd8c4:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0dd8c8:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0dd8cc:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0dd8d0:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0dd8d4:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f0dd8d8:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0dd8dc:	02e03025 */ 	or	$a2,$s7,$zero
/*  f0dd8e0:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0dd8e4:	0fc54529 */ 	jal	textRender
/*  f0dd8e8:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0dd8ec:	00409025 */ 	or	$s2,$v0,$zero
.NB0f0dd8f0:
/*  f0dd8f0:	920f01c9 */ 	lbu	$t7,0x1c9($s0)
/*  f0dd8f4:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0dd8f8:	15e10002 */ 	bne	$t7,$at,.NB0f0dd904
/*  f0dd8fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd900:	afa000e0 */ 	sw	$zero,0xe0($sp)
.NB0f0dd904:
/*  f0dd904:	0fc5392a */ 	jal	func0f153e4c
/*  f0dd908:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0dd90c:
/*  f0dd90c:	8e0c01b4 */ 	lw	$t4,0x1b4($s0)
.NB0f0dd910:
/*  f0dd910:	2401000b */ 	addiu	$at,$zero,0xb
/*  f0dd914:	15810039 */ 	bne	$t4,$at,.NB0f0dd9fc
/*  f0dd918:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd91c:	afb2009c */ 	sw	$s2,0x9c($sp)
/*  f0dd920:	0c002fb5 */ 	jal	viGetViewLeft
/*  f0dd924:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0dd928:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0dd92c:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0dd930:	01408025 */ 	or	$s0,$t2,$zero
/*  f0dd934:	0c002fb9 */ 	jal	viGetViewTop
/*  f0dd938:	8fb3009c */ 	lw	$s3,0x9c($sp)
/*  f0dd93c:	44825000 */ 	mtc1	$v0,$f10
/*  f0dd940:	44904000 */ 	mtc1	$s0,$f8
/*  f0dd944:	3c01ed00 */ 	lui	$at,0xed00
/*  f0dd948:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f0dd94c:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f0dd950:	46169102 */ 	mul.s	$f4,$f18,$f22
/*  f0dd954:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd958:	46168282 */ 	mul.s	$f10,$f16,$f22
/*  f0dd95c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0dd960:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f0dd964:	440d3000 */ 	mfc1	$t5,$f6
/*  f0dd968:	44199000 */ 	mfc1	$t9,$f18
/*  f0dd96c:	31b80fff */ 	andi	$t8,$t5,0xfff
/*  f0dd970:	03014025 */ 	or	$t0,$t8,$at
/*  f0dd974:	332b0fff */ 	andi	$t3,$t9,0xfff
/*  f0dd978:	000b7b00 */ 	sll	$t7,$t3,0xc
/*  f0dd97c:	010f6025 */ 	or	$t4,$t0,$t7
/*  f0dd980:	0c002f97 */ 	jal	viGetViewWidth
/*  f0dd984:	ae6c0000 */ 	sw	$t4,0x0($s3)
/*  f0dd988:	0c002fb5 */ 	jal	viGetViewLeft
/*  f0dd98c:	a7a20092 */ 	sh	$v0,0x92($sp)
/*  f0dd990:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0dd994:	00115403 */ 	sra	$t2,$s1,0x10
/*  f0dd998:	0c002fb9 */ 	jal	viGetViewTop
/*  f0dd99c:	01408825 */ 	or	$s1,$t2,$zero
/*  f0dd9a0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0dd9a4:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0dd9a8:	0c002f9b */ 	jal	viGetViewHeight
/*  f0dd9ac:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0dd9b0:	87ab0092 */ 	lh	$t3,0x92($sp)
/*  f0dd9b4:	00506821 */ 	addu	$t5,$v0,$s0
/*  f0dd9b8:	448d2000 */ 	mtc1	$t5,$f4
/*  f0dd9bc:	022b4021 */ 	addu	$t0,$s1,$t3
/*  f0dd9c0:	44885000 */ 	mtc1	$t0,$f10
/*  f0dd9c4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0dd9c8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f0dd9cc:	46163202 */ 	mul.s	$f8,$f6,$f22
/*  f0dd9d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd9d4:	46169102 */ 	mul.s	$f4,$f18,$f22
/*  f0dd9d8:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f0dd9dc:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0dd9e0:	44098000 */ 	mfc1	$t1,$f16
/*  f0dd9e4:	440c3000 */ 	mfc1	$t4,$f6
/*  f0dd9e8:	31390fff */ 	andi	$t9,$t1,0xfff
/*  f0dd9ec:	318a0fff */ 	andi	$t2,$t4,0xfff
/*  f0dd9f0:	000a7300 */ 	sll	$t6,$t2,0xc
/*  f0dd9f4:	032e6825 */ 	or	$t5,$t9,$t6
/*  f0dd9f8:	ae6d0004 */ 	sw	$t5,0x4($s3)
.NB0f0dd9fc:
/*  f0dd9fc:	3c048007 */ 	lui	$a0,0x8007
/*  f0dda00:	8c8436a8 */ 	lw	$a0,0x36a8($a0)
/*  f0dda04:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0dda08:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0dda0c:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0dda10:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0dda14:	00021080 */ 	sll	$v0,$v0,0x2
.NB0f0dda18:
/*  f0dda18:	8fb80088 */ 	lw	$t8,0x88($sp)
/*  f0dda1c:	270901dc */ 	addiu	$t1,$t8,0x1dc
/*  f0dda20:	0122082a */ 	slt	$at,$t1,$v0
/*  f0dda24:	1420fd66 */ 	bnez	$at,.NB0f0dcfc0
/*  f0dda28:	afa90088 */ 	sw	$t1,0x88($sp)
.NB0f0dda2c:
/*  f0dda2c:	8fab00e0 */ 	lw	$t3,0xe0($sp)
/*  f0dda30:	3c08800a */ 	lui	$t0,0x800a
/*  f0dda34:	11600028 */ 	beqz	$t3,.NB0f0ddad8
/*  f0dda38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dda3c:	8d08e948 */ 	lw	$t0,-0x16b8($t0)
/*  f0dda40:	0fc533f6 */ 	jal	optionsGetShowMissionTime
/*  f0dda44:	8d040070 */ 	lw	$a0,0x70($t0)
/*  f0dda48:	10400019 */ 	beqz	$v0,.NB0f0ddab0
/*  f0dda4c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0dda50:	8def86e8 */ 	lw	$t7,-0x7918($t7)
/*  f0dda54:	24030002 */ 	addiu	$v1,$zero,0x2
/*  f0dda58:	3c0c800a */ 	lui	$t4,0x800a
/*  f0dda5c:	146f0014 */ 	bne	$v1,$t7,.NB0f0ddab0
/*  f0dda60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dda64:	8d8ce9d8 */ 	lw	$t4,-0x1628($t4)
/*  f0dda68:	3c0a800a */ 	lui	$t2,0x800a
/*  f0dda6c:	15800010 */ 	bnez	$t4,.NB0f0ddab0
/*  f0dda70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dda74:	8d4aeb74 */ 	lw	$t2,-0x148c($t2)
/*  f0dda78:	24010026 */ 	addiu	$at,$zero,0x26
/*  f0dda7c:	3c19800a */ 	lui	$t9,0x800a
/*  f0dda80:	1141000b */ 	beq	$t2,$at,.NB0f0ddab0
/*  f0dda84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dda88:	8f39e944 */ 	lw	$t9,-0x16bc($t9)
/*  f0dda8c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0dda90:	8f220000 */ 	lw	$v0,0x0($t9)
/*  f0dda94:	10620006 */ 	beq	$v1,$v0,.NB0f0ddab0
/*  f0dda98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dda9c:	10410004 */ 	beq	$v0,$at,.NB0f0ddab0
/*  f0ddaa0:	02402025 */ 	or	$a0,$s2,$zero
/*  f0ddaa4:	0fc36941 */ 	jal	hudmsgRenderMissionTimer
/*  f0ddaa8:	8fa500e0 */ 	lw	$a1,0xe0($sp)
/*  f0ddaac:	00409025 */ 	or	$s2,$v0,$zero
.NB0f0ddab0:
/*  f0ddab0:	0fc368f3 */ 	jal	hudmsgIsZoomRangeVisible
/*  f0ddab4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddab8:	10400004 */ 	beqz	$v0,.NB0f0ddacc
/*  f0ddabc:	02402025 */ 	or	$a0,$s2,$zero
/*  f0ddac0:	0fc36a2f */ 	jal	hudmsgRenderZoomRange
/*  f0ddac4:	8fa500e0 */ 	lw	$a1,0xe0($sp)
/*  f0ddac8:	00409025 */ 	or	$s2,$v0,$zero
.NB0f0ddacc:
/*  f0ddacc:	0fc23bd4 */ 	jal	countdownTimerRender
/*  f0ddad0:	02402025 */ 	or	$a0,$s2,$zero
/*  f0ddad4:	00409025 */ 	or	$s2,$v0,$zero
.NB0f0ddad8:
/*  f0ddad8:	0fc537a0 */ 	jal	func0f153780
/*  f0ddadc:	02402025 */ 	or	$a0,$s2,$zero
/*  f0ddae0:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f0ddae4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0ddae8:	3c018008 */ 	lui	$at,0x8008
/*  f0ddaec:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f0ddaf0:	d7b60040 */ 	ldc1	$f22,0x40($sp)
/*  f0ddaf4:	d7b80048 */ 	ldc1	$f24,0x48($sp)
/*  f0ddaf8:	d7ba0050 */ 	ldc1	$f26,0x50($sp)
/*  f0ddafc:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f0ddb00:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f0ddb04:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0ddb08:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f0ddb0c:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f0ddb10:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f0ddb14:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f0ddb18:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f0ddb1c:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f0ddb20:	ac2e2320 */ 	sw	$t6,0x2320($at)
/*  f0ddb24:	03e00008 */ 	jr	$ra
/*  f0ddb28:	27bd0100 */ 	addiu	$sp,$sp,0x100
);
#endif

// Mismatch most likely due to variable re-use.
//Gfx *hudmsgsRender(Gfx *gdl)
//{
//	s32 i;
//	u32 textcolour; // s3
//	u32 glowcolour; // s4
//	u32 stack;
//	f32 sin;
//	s32 x; // e8
//	s32 y; // e4
//	s32 timerthing = 255; // e0
//	s32 spdc = true; // dc
//
//	// b24
//	if (g_ViMode == VIMODE_HIRES) {
//		g_ScaleX = 2;
//	} else {
//		g_ScaleX = 1;
//	}
//
//	// b44
//	gdl = func0f153628(gdl);
//
//	// b4c
//	if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
//			&& g_InCutscene
//			&& g_MainIsEndscreen == 0
//			&& g_Vars.currentplayernum == 0) {
//		// ba4
//		spdc = false;
//	}
//
//	// bac
//	for (i = 0; i < g_NumHudMessages; i++) {
//		// bbc
//		struct hudmessage *msg = &g_HudMessages[i];
//
//		// c04
//		if (msg->opacity == 0) {
//			continue;
//		}
//
//		// c14
//		if (msg->state == HUDMSGSTATE_FREE
//				|| msg->state == HUDMSGSTATE_QUEUED
//				|| (spdc && g_Vars.currentplayernum != msg->playernum)) {
//			continue;
//		}
//
//		// c60
//		if (msg->flash) {
//			s32 alpha;
//			sin = sinf((msg->timer * M_PI) / 60.0f);
//
//			if (sin < 0.0f) {
//				sin = -sin;
//			}
//
//			alpha = 192.0f * sin;
//
//			textcolour = (msg->textcolour & 0xffffff00) + alpha;
//			glowcolour = msg->glowcolour;
//		} else {
//			// ce8
//			textcolour = msg->textcolour | 0xa0;
//			glowcolour = msg->glowcolour;
//		}
//
//		// cf8
//		if (msg->opacity != 255) {
//			u32 alpha;
//			alpha = (msg->opacity * (textcolour & 0xff)) / 255;
//			textcolour = (textcolour & 0xffffff00) + (alpha & 0xff);
//			alpha = (msg->opacity * (glowcolour & 0xff)) / 255;
//			glowcolour = (glowcolour & 0xffffff00) + (alpha & 0xff);
//		}
//
//		// d70
//		x = msg->x;
//		y = msg->y;
//
//		if (msg->type == HUDMSGTYPE_INGAMESUBTITLE && currentPlayerIsHealthVisible()) {
//			y += (s32)(16.0f * currentPlayerGetHealthBarHeightFrac());
//		}
//
//		// dd0
//		if (msg->type == HUDMSGTYPE_CUTSCENESUBTITLE) {
//			gDPSetScissor(gdl++, 0,
//					(x - 4) * g_ScaleX, 0,
//					(x + msg->width + 3) * g_ScaleX, viGetBufY());
//		}
//
//		// e9c
//		switch (msg->state) {
//		case HUDMSGSTATE_FREE:
//		case HUDMSGSTATE_QUEUED:
//			break;
//		case HUDMSGSTATE_FADINGIN: // f0dfebc
//			{
//				u32 bordercolour = msg->textcolour | 0x40;
//				f32 tmp;
//				f32 spc0;
//
//				if (msg->opacity != 255) {
//					u32 alpha = (msg->opacity * (bordercolour & 0xff)) / 255;
//					bordercolour = (bordercolour & 0xffffff00) + (alpha & 0xff);
//				}
//
//				// f08
//				spc0 = (sqrtf(msg->width * msg->width + msg->height * msg->height) + 132.0f) / 7.0f;
//
//				// f58
//				if (spc0 > 30.0f) {
//					spc0 = 30.0f;
//				}
//
//				spc0 = msg->timer / spc0;
//
//				// fa0
//				if (spc0 > 1.0f) {
//					spc0 = 1.0f;
//				}
//
//				// fcc
//				if (spc0 < 0.0f) {
//					spc0 = 0.0f;
//				}
//
//				tmp = msg->timer * 7.0f;
//
//				func0f153c20(x, y, tmp, 0);
//
//				// fd8
//				if (msg->boxed) {
//					// fe0
//					gdl = hudmsgRenderBox(gdl, x - 3, y - 3, x + msg->width + 2, y + msg->height + 2, 1.0f, bordercolour, spc0);
//					// 020
//					gdl = textRenderProjected(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, viGetWidth(), viGetHeight(), 0, 0);
//				} else {
//					// 078
//					gdl = func0f153a34(gdl, x, y, x + msg->width, y + msg->height, 0);
//					// 0e4
//					gdl = textRender(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, glowcolour, viGetWidth(), viGetHeight(), 0, 0);
//				}
//
//				if (msg->alignv == 6) {
//					timerthing = 0;
//				}
//
//				func0f153e4c();
//			}
//			break;
//		case HUDMSGSTATE_ONSCREEN: // f0e0114
//			if (msg->boxed) {
//				u32 bordercolour = msg->textcolour | 0x40;
//
//				if (msg->opacity != 255) {
//					u32 alpha = (msg->opacity * (bordercolour & 0xff)) / 255;
//					bordercolour = (bordercolour & 0xffffff00) + (alpha & 0xff);
//				}
//
//				// 1a0
//				gdl = hudmsgRenderBox(gdl, x - 3, y - 3, x + msg->width + 2, y + msg->height + 2, 1.0f, bordercolour, 1.0f);
//				// 1f0
//				gdl = textRenderProjected(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, viGetWidth(), viGetHeight(), 0, 0);
//			} else {
//				// 200
//				gdl = func0f153a34(gdl, x, y, x + msg->width, y + msg->height, 0);
//				// 274
//				gdl = textRender(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, glowcolour, viGetWidth(), viGetHeight(), 0, 0);
//			}
//			if (msg->alignv == 6) {
//				timerthing = 0;
//			}
//			break;
//		case HUDMSGSTATE_FADINGOUT: // f0e0298
//			{
//				u32 bordercolour;
//				u32 stack;
//				f32 spa8 = (sqrtf(msg->width * msg->width + msg->height * msg->height) + 92.0f) / 7.0f;
//				f32 tmp;
//
//				bordercolour = msg->textcolour | 0x40;
//
//				if (msg->opacity != 255) {
//					u32 alpha = (msg->opacity * (bordercolour & 0xff)) / 255;
//					bordercolour = (bordercolour & 0xffffff00) + (alpha & 0xff);
//				}
//
//				tmp = (spa8 - msg->timer) * 7.0f;
//
//				// 370
//				func0f153c20(x + msg->width, y + msg->height, tmp, 2);
//
//				// 394
//				if (spa8 > 30.0f) {
//					spa8 = 30.0f;
//				}
//
//				// 3bc
//				spa8 = msg->timer / spa8;
//
//				if (spa8 > 1.0f) {
//					spa8 = 1.0f;
//				}
//
//				// 3d8
//				if (msg->boxed) {
//					// 414
//					gdl = hudmsgRenderBox(gdl, x - 3, y - 3, x + msg->width + 2, y + msg->height + 2, 1.0f, bordercolour, 1.0f - spa8);
//					// 464
//					gdl = textRenderProjected(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, viGetWidth(), viGetHeight(), 0, 0);
//				} else {
//					// 474
//					gdl = func0f153a34(gdl, x, y, x + msg->width, y + msg->height, 0);
//					// 4dc
//					gdl = textRender(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, glowcolour, viGetWidth(), viGetHeight(), 0, 0);
//				}
//
//				if (msg->alignv == 6) {
//					timerthing = 0;
//				}
//
//				func0f153e4c();
//			}
//			break;
//		}
//
//		if (msg->type == HUDMSGTYPE_CUTSCENESUBTITLE) {
//			gDPSetScissor(gdl++, 0,
//					viGetViewLeft(), viGetViewTop(),
//					viGetViewLeft() + viGetViewWidth(), viGetViewTop() + viGetViewHeight());
//		}
//	}
//
//	if (timerthing) {
//		if (optionsGetShowMissionTime(g_Vars.currentplayerstats->mpindex)
//				&& var80075d60 == 2
//				&& g_Vars.normmplayerisrunning == false
//				&& g_Vars.stagenum != STAGE_CITRAINING
//				&& g_Vars.currentplayer->cameramode != CAMERAMODE_EYESPY
//				&& g_Vars.currentplayer->cameramode != CAMERAMODE_THIRDPERSON) {
//			gdl = hudmsgRenderMissionTimer(gdl, timerthing);
//		}
//
//		if (hudmsgIsZoomRangeVisible()) {
//			gdl = hudmsgRenderZoomRange(gdl, timerthing);
//		}
//
//		gdl = countdownTimerRender(gdl);
//	}
//
//	gdl = func0f153780(gdl);
//
//	g_ScaleX = 1;
//
//	return gdl;
//}

#if VERSION >= VERSION_NTSC_1_0
void hudmsgsReset(void)
{
	s32 i;

	for (i = 0; i < g_NumHudMessages; i++) {
		g_HudMessages[i].state = HUDMSGSTATE_FREE;
	}
}
#else
GLOBAL_ASM(
glabel hudmsgsReset
/*  f0ddb2c:	3c058007 */ 	lui	$a1,0x8007
/*  f0ddb30:	24a536a8 */ 	addiu	$a1,$a1,0x36a8
/*  f0ddb34:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f0ddb38:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0ddb3c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0ddb40:	19c0000d */ 	blez	$t6,.NB0f0ddb78
/*  f0ddb44:	00001025 */ 	or	$v0,$zero,$zero
/*  f0ddb48:	3c048007 */ 	lui	$a0,0x8007
/*  f0ddb4c:	248436ac */ 	addiu	$a0,$a0,0x36ac
/*  f0ddb50:	00001825 */ 	or	$v1,$zero,$zero
/*  f0ddb54:	8c8f0000 */ 	lw	$t7,0x0($a0)
.NB0f0ddb58:
/*  f0ddb58:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0ddb5c:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f0ddb60:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f0ddb64:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f0ddb68:	246301dc */ 	addiu	$v1,$v1,0x1dc
/*  f0ddb6c:	0059082a */ 	slt	$at,$v0,$t9
/*  f0ddb70:	5420fff9 */ 	bnezl	$at,.NB0f0ddb58
/*  f0ddb74:	8c8f0000 */ 	lw	$t7,0x0($a0)
.NB0f0ddb78:
/*  f0ddb78:	3c048007 */ 	lui	$a0,0x8007
/*  f0ddb7c:	8c8436b0 */ 	lw	$a0,0x36b0($a0)
/*  f0ddb80:	50800008 */ 	beqzl	$a0,.NB0f0ddba4
/*  f0ddb84:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0ddb88:	0c00d360 */ 	jal	audioIsPlaying
/*  f0ddb8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0ddb90:	10400003 */ 	beqz	$v0,.NB0f0ddba0
/*  f0ddb94:	3c048007 */ 	lui	$a0,0x8007
/*  f0ddb98:	0c00d428 */ 	jal	audioStop
/*  f0ddb9c:	8c8436b0 */ 	lw	$a0,0x36b0($a0)
.NB0f0ddba0:
/*  f0ddba0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f0ddba4:
/*  f0ddba4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0ddba8:	03e00008 */ 	jr	$ra
/*  f0ddbac:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif
