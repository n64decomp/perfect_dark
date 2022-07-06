#include <ultra64.h>
#include "constants.h"
#include "constants.h"
#include "game/propsnd.h"
#include "game/game_0b0fd0.h"
#include "game/player.h"
#include "game/savebuffer.h"
#include "game/hudmsg.h"
#include "game/menugfx.h"
#include "game/playermgr.h"
#include "game/game_1531a0.h"
#include "game/lv.h"
#include "game/mplayer/mplayer.h"
#include "game/options.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/snd.h"
#include "lib/memp.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

u32 g_NextHudMessageId;

u8 g_HudmsgsActive = 0;

u32 g_HudmsgColours[] = {
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

#if VERSION < VERSION_NTSC_1_0
struct sndstate *var800736b0nb = NULL;
#endif

struct hudmsgtype g_HudmsgTypes[] = {
	/* 0*/ { 1, 1, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 80  },
	/* 1*/ { 0, 1, 0, &g_CharsHandelGothicMd, &g_FontHandelGothicMd, 0x00ff0000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_YMIDDLE,       0, 0, 120 },
#if VERSION == VERSION_JPN_FINAL
	/* 2*/ { 0, 0, 1, &g_CharsHandelGothicMd, &g_FontHandelGothicMd, 0xff999900, 0xffffffa0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_YMIDDLE,       0, 0, 120 },
#else
	/* 2*/ { 0, 0, 1, &g_CharsHandelGothicMd, &g_FontHandelGothicMd, 0xff000000, 0xffffffa0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_YMIDDLE,       0, 0, 120 },
#endif
	/* 3*/ { 0, 1, 0, &g_CharsHandelGothicMd, &g_FontHandelGothicMd, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 120 },
	/* 4*/ { 1, 1, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ffc000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 40  },
	/* 5*/ { 0, 0, 0, &g_CharsHandelGothicMd, &g_FontHandelGothicMd, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_TOP,           0, 0, 120 },
	/* 6*/ { 1, 0, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ff0000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_TOP,           0, 0, 120 },
	/* 7*/ { 1, 1, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ff0000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_TOP,           0, 0, -1  },
	/* 8*/ { 1, 1, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ffc000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_BOTTOM,        0, 0, 500 },
#if VERSION == VERSION_JPN_FINAL
	/* 9*/ { 1, 1, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 120 },
#else
	/* 9*/ { 1, 1, 0, &g_CharsHandelGothicXs, &g_FontHandelGothicXs, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 120 },
#endif
	/*10*/ { 1, 1, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ff0000, 0x000000a0, HUDMSGALIGN_LEFT,    HUDMSGALIGN_BOTTOM,        0, 0, 240 },
#if VERSION >= VERSION_NTSC_1_0
	/*11*/ { 0, 0, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ff0000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_BELOWVIEWPORT, 0, 0, 120 },
#else
	/*11*/ { 1, 0, 0, &g_CharsHandelGothicSm, &g_FontHandelGothicSm, 0x00ff0000, 0x000000a0, HUDMSGALIGN_XMIDDLE, HUDMSGALIGN_BELOWVIEWPORT, 0, 0, 120 },
#endif
};

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
/*  f0dd208:	0fc3089f */ 	jal	playerGetMissionTime
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
/*  f0dd24c:	3c0d8008 */ 	lui	$t5,%hi(g_CharsNumeric)
/*  f0dd250:	3c0e8008 */ 	lui	$t6,%hi(g_FontNumeric)
/*  f0dd254:	8dcefafc */ 	lw	$t6,%lo(g_FontNumeric)($t6)
/*  f0dd258:	8dadfb00 */ 	lw	$t5,%lo(g_CharsNumeric)($t5)
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

// Mismatch: Regalloc. Seems like something's optimised out before PLAYERCOUNT().
//Gfx *hudmsgRenderMissionTimer(Gfx *gdl, u32 alpha)
//{
//	s32 x; // 8c
//	s32 y; // 88
//	s32 viewleft; // 84
//	s32 timery; // 80
//	char buffer[24]; // 68
//	u32 textcolour; // 64
//	s32 viewheight;
//	s32 playercount;
//	s32 playernum; // 58
//	s16 viewtop; // 56
//
//	textcolour = alpha;
//
//	viewleft = viGetViewLeft() / g_ScaleX;
//	viewtop = viGetViewTop();
//	viewheight = viGetViewHeight();
//	playercount = PLAYERCOUNT();
//	playernum = g_Vars.currentplayernum;
//
//	timery = viewtop + viewheight - g_HudPaddingY - 8;
//
//	// fe0
//	if ((IS4MB() || optionsGetScreenSplit() == SCREENSPLIT_VERTICAL) && countdownTimerIsVisible()) {
//		timery -= 8;
//	}
//
//	// 054
//	if ((IS4MB() || optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || playercount >= 3) && hudmsgIsZoomRangeVisible()) {
//		timery -= 8;
//	}
//
//	// 0d8
//	if (playercount == 2) {
//		// 0e4
//		if (IS4MB() || (optionsGetScreenSplit() != SCREENSPLIT_VERTICAL && playernum == 0)) {
//			// 118
//			timery += 10;
//		} else {
//			// 120
//			timery += 2;
//		}
//	} else /*128*/ if (playercount >= 3) {
//		if (playernum < 2) {
//			timery += 10;
//		} else {
//			timery += 2;
//		}
//	} else {
//		// 150
//		if (optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
//			timery += 8;
//		}
//	}
//
//	// 170
//	// If this is a second player with their viewport on the right side of the
//	// screen, move the timer left a bit as the safe zone doesn't need to be
//	// considered.
//	if (playercount == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB()) && playernum == 1) {
//		viewleft -= 14;
//	} else if (playercount >= 3 && (playernum & 1) == 1) {
//		viewleft -= 14;
//	}
//
//	// 1e0
//	textcolour = (textcolour * 160 / 255) | 0x00ff0000;
//
//	// 208
//	formatTime(buffer, playerGetMissionTime(), TIMEPRECISION_HUNDREDTHS);
//
//	x = viewleft + g_HudPaddingX + 3;
//	y = timery;
//
//	gdl = textRender(gdl, &x, &y, buffer, g_CharsNumeric, g_FontNumeric, textcolour, 0x000000a0, viGetWidth(), viGetHeight(), 0, 0);
//
//	return gdl;
//}

Gfx *hudmsgRenderZoomRange(Gfx *gdl, u32 alpha)
{
	s32 viewtop;
	s32 viewleft;
	s32 viewhalfwidth;
	s32 viewheight;
	f32 zoominfovy;
	f32 zoomfov;
	s32 playercount;
	f32 curzoom;
	f32 maxzoom;
	char text[24];
	s32 weaponnum;
	s32 texty;
	s32 x;
	s32 y;
	s32 textwidth;
	s32 textheight;
	s32 x2;
	s32 y2;
	u32 colour;

	colour = (alpha * 0xa0 / 255) | 0x00ff0000;
	viewtop = viGetViewTop();
	viewleft = viGetViewLeft() / g_ScaleX;
	viewhalfwidth = (viGetViewWidth() / g_ScaleX) >> 1;
	viewheight = viGetViewHeight();
	texty = viewheight + viewtop - 1;
	maxzoom = 1.0f;
	weaponnum = g_Vars.currentplayer->hands[0].gset.weaponnum;
	playercount = PLAYERCOUNT();

	texty -= 17;

	if (countdownTimerIsVisible()) {
		texty -= 8;
	}

	if (playercount == 2) {
		if (IS4MB() || (optionsGetScreenSplit() != SCREENSPLIT_VERTICAL && g_Vars.currentplayernum == 0)) {
			texty += 10;
		} else {
			texty += 2;
		}
	} else if (playercount >= 3) {
		if (g_Vars.currentplayernum < 2) {
			texty += 10;
		} else {
			texty += 2;
		}
	} else if (optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
		texty += 8;
	}

	// Left side - current zoom level
	zoomfov = currentPlayerGetGunZoomFov();
	zoominfovy = g_Vars.currentplayer->zoominfovy;

	if (zoomfov == 0.0f || zoomfov == 60.0f) {
		if (weaponnum == WEAPON_SNIPERRIFLE) {
			curzoom = 1.0f;
		} else {
			return gdl;
		}
	} else {
		maxzoom = 60.0f / zoomfov;
		curzoom = maxzoom - 1.0f / (zoomfov / zoominfovy) + 1;
	}

	sprintf(text, "%s%s%4.2fX", "", "", curzoom);
	textMeasure(&textheight, &textwidth, text, g_CharsNumeric, g_FontNumeric, 0);

	x = viewleft + viewhalfwidth - textwidth - 5;
	y = texty;
	x2 = x + textwidth;
	y2 = y + textheight;

	gdl = text0f1538e4(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, colour, 0x000000a0, viGetWidth(), viGetHeight(), 0, 0);

	// Divider
	sprintf(text, "/");
	textMeasure(&textheight, &textwidth, text, g_CharsNumeric, g_FontNumeric, 0);

	x = viewleft + viewhalfwidth - (textwidth >> 1);
	y = texty;
	x2 = x + textwidth;
	y2 = y + textheight;

	gdl = text0f1538e4(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, colour, 0x000000a0, viGetWidth(), viGetHeight(), 0, 0);

	// Right side - max zoom level
	sprintf(text, "%s%s%4.2fX", "", "", maxzoom);
	textMeasure(&textheight, &textwidth, text, g_CharsNumeric, g_FontNumeric, 0);

	x = viewleft + viewhalfwidth + 5;
	y = texty;
	x2 = x + textwidth;
	y2 = y + textheight;

	gdl = text0f1538e4(gdl, &x, &y, &x2, &y2);
	gdl = textRender(gdl, &x, &y, text, g_CharsNumeric, g_FontNumeric, colour, 0x000000a0, viGetWidth(), viGetHeight(), 0, 0);

	return gdl;
}

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

	gdl = menugfxDrawFilledRect(gdl, x1, y1, x2, y1 + 1, bordercolour, bordercolour);
	gdl = menugfxDrawFilledRect(gdl, x1, y2, x2, y2 + 1, bordercolour, bordercolour);
	gdl = menugfxDrawFilledRect(gdl, x1, y1 + 1, x1 + 1, y2, bordercolour, bordercolour);
	gdl = menugfxDrawFilledRect(gdl, x2, y1, x2 + 1, y2 + 1, bordercolour, bordercolour);

	gdl = func0f0d49c8(gdl);

	if (textopacity > 0.0f) {
		f32 width = (x1 + x2) * 0.5f;
		f32 height = (y1 + y2) * 0.5f;

		gdl = text0f153a34(gdl,
				(s32)((width - f22) + 1.0f) * g_ScaleX,
				(height - f20) + 1.0f,
				(s32)(width + f22) * g_ScaleX,
				height + f20,
				128.0f * textopacity);
	}

	return gdl;
}

s32 hudmsg0f0ddb1c(s32 *arg0, s32 arg1)
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

#if VERSION < VERSION_JPN_FINAL
		if (g_ViRes == VIRES_HI) {
			result -= 16;
		}
#endif
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

void hudmsgsReset(void)
{
	s32 i;

	g_NumHudMessages = g_Vars.mplayerisrunning ? 20 : 8;
	g_HudMessages = mempAlloc(ALIGN64(sizeof(struct hudmessage) * g_NumHudMessages), MEMPOOL_STAGE);

	for (i = 0; i < g_NumHudMessages; i++) {
		g_HudMessages[i].state = HUDMSGSTATE_FREE;
	}

	g_NextHudMessageId = 0;

#if VERSION < VERSION_NTSC_1_0
	var800736b0nb = NULL;
#endif
}

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
	g_HudmsgTypes[type].colour = g_HudmsgColours[colournum];

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

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel hudmsgCreateAsSubtitle
/*  f0df2b4:	27bdfe38 */ 	addiu	$sp,$sp,-456
/*  f0df2b8:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f0df2bc:	00809825 */ 	move	$s3,$a0
/*  f0df2c0:	afbf006c */ 	sw	$ra,0x6c($sp)
/*  f0df2c4:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f0df2c8:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f0df2cc:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f0df2d0:	00e09025 */ 	move	$s2,$a3
/*  f0df2d4:	30d400ff */ 	andi	$s4,$a2,0xff
/*  f0df2d8:	00a0b025 */ 	move	$s6,$a1
/*  f0df2dc:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f0df2e0:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f0df2e4:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f0df2e8:	f7b40048 */ 	sdc1	$f20,0x48($sp)
/*  f0df2ec:	afa601d0 */ 	sw	$a2,0x1d0($sp)
/*  f0df2f0:	0fc257fe */ 	jal	propsndGetDuration60
/*  f0df2f4:	00e02025 */ 	move	$a0,$a3
/*  f0df2f8:	24100006 */ 	li	$s0,0x6
/*  f0df2fc:	16d0000e */ 	bne	$s6,$s0,.JF0f0df338
/*  f0df300:	00408825 */ 	move	$s1,$v0
/*  f0df304:	3c0e800a */ 	lui	$t6,0x800a
/*  f0df308:	8dcea8dc */ 	lw	$t6,-0x5724($t6)
/*  f0df30c:	160e0007 */ 	bne	$s0,$t6,.JF0f0df32c
/*  f0df310:	00000000 */ 	nop
/*  f0df314:	0fc547ce */ 	jal	optionsGetCutsceneSubtitles
/*  f0df318:	00000000 */ 	nop
/*  f0df31c:	5040006b */ 	beqzl	$v0,.JF0f0df4cc
/*  f0df320:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f0df324:	10000004 */ 	b	.JF0f0df338
/*  f0df328:	2416000b */ 	li	$s6,0xb
.JF0f0df32c:
/*  f0df32c:	0fc547cb */ 	jal	optionsGetInGameSubtitles
/*  f0df330:	00000000 */ 	nop
/*  f0df334:	10400064 */ 	beqz	$v0,.JF0f0df4c8
.JF0f0df338:
/*  f0df338:	0014c880 */ 	sll	$t9,$s4,0x2
/*  f0df33c:	3c098007 */ 	lui	$t1,0x8007
/*  f0df340:	01394821 */ 	addu	$t1,$t1,$t9
/*  f0df344:	8d291504 */ 	lw	$t1,0x1504($t1)
/*  f0df348:	3c188007 */ 	lui	$t8,0x8007
/*  f0df34c:	27181540 */ 	addiu	$t8,$t8,0x1540
/*  f0df350:	00167940 */ 	sll	$t7,$s6,0x5
/*  f0df354:	01f8a821 */ 	addu	$s5,$t7,$t8
/*  f0df358:	3c0a800a */ 	lui	$t2,0x800a
/*  f0df35c:	aea9000c */ 	sw	$t1,0xc($s5)
/*  f0df360:	8d4aa8dc */ 	lw	$t2,-0x5724($t2)
/*  f0df364:	560a0040 */ 	bnel	$s0,$t2,.JF0f0df468
/*  f0df368:	92b80002 */ 	lbu	$t8,0x2($s5)
/*  f0df36c:	0622003e */ 	bltzl	$s1,.JF0f0df468
/*  f0df370:	92b80002 */ 	lbu	$t8,0x2($s5)
/*  f0df374:	0c012847 */ 	jal	strlen
/*  f0df378:	02602025 */ 	move	$a0,$s3
/*  f0df37c:	304bffff */ 	andi	$t3,$v0,0xffff
/*  f0df380:	448b4000 */ 	mtc1	$t3,$f8
/*  f0df384:	44912000 */ 	mtc1	$s1,$f4
/*  f0df388:	00009025 */ 	move	$s2,$zero
/*  f0df38c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0df390:	05610005 */ 	bgez	$t3,.JF0f0df3a8
/*  f0df394:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0df398:	3c014f80 */ 	lui	$at,0x4f80
/*  f0df39c:	44818000 */ 	mtc1	$at,$f16
/*  f0df3a0:	00000000 */ 	nop
/*  f0df3a4:	46105280 */ 	add.s	$f10,$f10,$f16
.JF0f0df3a8:
/*  f0df3a8:	02608025 */ 	move	$s0,$s3
/*  f0df3ac:	460a3503 */ 	div.s	$f20,$f6,$f10
/*  f0df3b0:	24130050 */ 	li	$s3,0x50
/*  f0df3b4:	24140070 */ 	li	$s4,0x70
/*  f0df3b8:	27b10088 */ 	addiu	$s1,$sp,0x88
/*  f0df3bc:	00004025 */ 	move	$t0,$zero
.JF0f0df3c0:
/*  f0df3c0:	00002025 */ 	move	$a0,$zero
/*  f0df3c4:	92030000 */ 	lbu	$v1,0x0($s0)
.JF0f0df3c8:
/*  f0df3c8:	14600004 */ 	bnez	$v1,.JF0f0df3dc
/*  f0df3cc:	00601025 */ 	move	$v0,$v1
/*  f0df3d0:	24120001 */ 	li	$s2,0x1
/*  f0df3d4:	1000000b */ 	b	.JF0f0df404
/*  f0df3d8:	24040001 */ 	li	$a0,0x1
.JF0f0df3dc:
/*  f0df3dc:	12620003 */ 	beq	$s3,$v0,.JF0f0df3ec
/*  f0df3e0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0df3e4:	16820003 */ 	bne	$s4,$v0,.JF0f0df3f4
/*  f0df3e8:	02286021 */ 	addu	$t4,$s1,$t0
.JF0f0df3ec:
/*  f0df3ec:	10000005 */ 	b	.JF0f0df404
/*  f0df3f0:	24040001 */ 	li	$a0,0x1
.JF0f0df3f4:
/*  f0df3f4:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f0df3f8:	310d00ff */ 	andi	$t5,$t0,0xff
/*  f0df3fc:	a1830000 */ 	sb	$v1,0x0($t4)
/*  f0df400:	01a04025 */ 	move	$t0,$t5
.JF0f0df404:
/*  f0df404:	5080fff0 */ 	beqzl	$a0,.JF0f0df3c8
/*  f0df408:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f0df40c:	02287021 */ 	addu	$t6,$s1,$t0
/*  f0df410:	11000010 */ 	beqz	$t0,.JF0f0df454
/*  f0df414:	a1c00000 */ 	sb	$zero,0x0($t6)
/*  f0df418:	44889000 */ 	mtc1	$t0,$f18
/*  f0df41c:	02202025 */ 	move	$a0,$s1
/*  f0df420:	02c02825 */ 	move	$a1,$s6
/*  f0df424:	02a03025 */ 	move	$a2,$s5
/*  f0df428:	05010005 */ 	bgez	$t0,.JF0f0df440
/*  f0df42c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0df430:	3c014f80 */ 	lui	$at,0x4f80
/*  f0df434:	44814000 */ 	mtc1	$at,$f8
/*  f0df438:	00000000 */ 	nop
/*  f0df43c:	46082100 */ 	add.s	$f4,$f4,$f8
.JF0f0df440:
/*  f0df440:	46142402 */ 	mul.s	$f16,$f4,$f20
/*  f0df444:	4600818d */ 	trunc.w.s	$f6,$f16
/*  f0df448:	44073000 */ 	mfc1	$a3,$f6
/*  f0df44c:	0fc37c8a */ 	jal	hudmsgCreateWithDuration
/*  f0df450:	00000000 */ 	nop
.JF0f0df454:
/*  f0df454:	5240ffda */ 	beqzl	$s2,.JF0f0df3c0
/*  f0df458:	00004025 */ 	move	$t0,$zero
/*  f0df45c:	1000001b */ 	b	.JF0f0df4cc
/*  f0df460:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f0df464:	92b80002 */ 	lbu	$t8,0x2($s5)
.JF0f0df468:
/*  f0df468:	92a60000 */ 	lbu	$a2,0x0($s5)
/*  f0df46c:	92a70001 */ 	lbu	$a3,0x1($s5)
/*  f0df470:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0df474:	8eb90004 */ 	lw	$t9,0x4($s5)
/*  f0df478:	02602025 */ 	move	$a0,$s3
/*  f0df47c:	02c02825 */ 	move	$a1,$s6
/*  f0df480:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0df484:	8ea90008 */ 	lw	$t1,0x8($s5)
/*  f0df488:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f0df48c:	8eaa000c */ 	lw	$t2,0xc($s5)
/*  f0df490:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0df494:	8eab0010 */ 	lw	$t3,0x10($s5)
/*  f0df498:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f0df49c:	92ac0014 */ 	lbu	$t4,0x14($s5)
/*  f0df4a0:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f0df4a4:	86ad0016 */ 	lh	$t5,0x16($s5)
/*  f0df4a8:	afad0028 */ 	sw	$t5,0x28($sp)
/*  f0df4ac:	92ae0015 */ 	lbu	$t6,0x15($s5)
/*  f0df4b0:	afae002c */ 	sw	$t6,0x2c($sp)
/*  f0df4b4:	86af0018 */ 	lh	$t7,0x18($s5)
/*  f0df4b8:	afa00038 */ 	sw	$zero,0x38($sp)
/*  f0df4bc:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f0df4c0:	0fc37f11 */ 	jal	hudmsgCreateFromArgs
/*  f0df4c4:	afaf0030 */ 	sw	$t7,0x30($sp)
.JF0f0df4c8:
/*  f0df4c8:	8fbf006c */ 	lw	$ra,0x6c($sp)
.JF0f0df4cc:
/*  f0df4cc:	d7b40048 */ 	ldc1	$f20,0x48($sp)
/*  f0df4d0:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f0df4d4:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f0df4d8:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f0df4dc:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f0df4e0:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f0df4e4:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f0df4e8:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f0df4ec:	03e00008 */ 	jr	$ra
/*  f0df4f0:	27bd01c8 */ 	addiu	$sp,$sp,0x1c8
);
#else
/**
 * Create a hudmsg that is tied to the given audio channel. When the audio
 * finishes the hudmsg is removed.
 *
 * This function is used for both in-game subtitles and cutscene subtitles.
 * If a cutscene is in progress, the function forces the type to cutscene.
 * This allows the caller to specify the type as in-game unconditionally
 * and it will do the right thing.
 *
 * For cutscene subtitles, a dynamic width is used which means the source text
 * has to be re-wrapped. There is also a limit of two lines at a time.
 *
 * The source text is split into individual messages. These splits are
 * usually at the end of each sentence, but they also occur after commas and
 * semi-colons.
 *
 * Each message is wrapped and appended to an accumulator. Every time the
 * accumulator would exceed two lines, the accumulator is queued as a hudmsg
 * and then cleared prior to appending the new message.
 *
 * Each hudmsg is assigned a duration according to its character length relative
 * to the entire string and the audio duration.
 */
void hudmsgCreateAsSubtitle(char *srctext, s32 type, u8 colourindex, s32 audiochannelnum)
{
	s32 audioduration60;
	struct hudmsgtype *config;

	audioduration60 = propsndGetDuration60(audiochannelnum);

	if (type == HUDMSGTYPE_INGAMESUBTITLE) {
		if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
			if (!optionsGetCutsceneSubtitles()) {
				return;
			}

			type = HUDMSGTYPE_CUTSCENESUBTITLE;
		} else if (!optionsGetInGameSubtitles()) {
			return;
		}
	}

	config = &g_HudmsgTypes[type];
	config->colour = g_HudmsgColours[colourindex];

	if (g_Vars.tickmode == TICKMODE_CUTSCENE && audioduration60 >= 0) {
		char puncchars[] = { '.', ';', '!', '?', ',' };
		u16 srclen;
		s32 sp4a8;
		s32 wrapwidth;
		char accum[250];
		char prewrap[250];
		char postwrap[250];
		char msg[250];
		s32 msglen;
		bool split;
		s32 accumlen;
		s32 linecount;
		f32 time60perchar;
		s32 i;
		s32 j;
		bool append;
		bool foundpunctuation;

		srclen = strlen(srctext);
		wrapwidth = hudmsg0f0ddb1c(&sp4a8, config->unk16);

		accumlen = 0;
		i = 0;
		time60perchar = (f32)audioduration60 / srclen;

		// These two loops both work with the i iterator.
		// The inner loop increments i and is looking for places to split the
		// text, while the outer loop iterates once per split until the srctext
		// has been completely scanned.
		while (srctext[i] != '\0') {
			msglen = 0;
			foundpunctuation = false;
			split = false;

			while (srctext[i] != '\0' && (!foundpunctuation || !split || i > srclen - 10)) {
				// Check if the current char is punctuation
				for (j = 0; j < ARRAYCOUNT(puncchars); j++) {
					if (puncchars[j] == srctext[i]) {
						foundpunctuation = true;
					}
				}

				// Avoid splitting in the middle of trailing dots,
				// and also avoid splitting after "Dr." or "Mr."
				if (foundpunctuation && srctext[i] == '.') {
					if (srctext[i + 1] == '.') {
						foundpunctuation = false;
					}

					if (i >= 2) {
						if ((srctext[i - 2] == 'D' || srctext[i - 2] == 'd')
								&& (srctext[i - 1] == 'r' || srctext[i - 1] == 'R')) {
							foundpunctuation = false;
						}

						if ((srctext[i - 2] == 'M' || srctext[i - 2] == 'm')
								&& (srctext[i - 1] == 'r' || srctext[i - 1] == 'R')) {
							foundpunctuation = false;
						}
					}
				}

				// Copy the the character from srctext to msg, except:
				// - if it's a space at the start of the string
				// - if it's a consecutive space
				// - if it's a line break (sometimes copy a space instead)
				if (msglen < 249) {
					bool ignore = false;

					if (srctext[i] == ' ') {
						if (msglen == 0) {
							ignore = true;
						} else if (msg[msglen - 1] == ' ') {
							ignore = true;
						}
					}

					if (srctext[i] == '\n') {
						ignore = true;

						if (msglen != 0 && msg[msglen - 1] != ' ' && srctext[i + 1] != ' ') {
							msg[msglen] = ' ';
							msglen++;
						}
					}

					if (foundpunctuation && srctext[i] == ' ') {
						split = true;
					}

					if (!ignore) {
						msg[msglen] = srctext[i];
						msglen++;
					}
				}

				if (1);

				i++;
			} // end of inner loop

			// At this point the string in msg is a single sentence,
			// free of line breaks. It still needs to be wrapped.

			// Make sure msg ends in a space
			if (msglen > 0 && msg[msglen - 1] != ' ') {
				msg[msglen] = ' ';
				msglen++;
			}

			// Rebuild prewrap by concatenating the accumulator and msg.
			// prewrap will be everything that's been read so far and has yet to
			// be queued.
			for (j = 0; j < accumlen; j++) {
				prewrap[j] = accum[j];
			}

			for (j = 0; j < msglen; j++) {
				prewrap[j + accumlen] = msg[j];
			}

			prewrap[accumlen + msglen] = '\n';
			prewrap[accumlen + msglen + 1] = '\0';

			// Apply text wrapping to prewrap
			textWrap(wrapwidth, prewrap, postwrap, g_CharsHandelGothicSm, g_FontHandelGothicSm);

			// Next, count the number of lines in the wrapped message.
			// If it's more than two, send the accumulator out as a hudmsg and
			// then put msg in the accumulator. Otherwise, just append msg to
			// the accumulator.

			// Note that these strings always end in a line break, so counting
			// the line breaks is the same as counting visual lines
			linecount = 0;

			for (j = 0; postwrap[j] != '\0'; j++) {
				if (postwrap[j] == '\n') {
					linecount++;
				}
			}

			append = true;

			if (linecount >= 3) {
				if (accumlen == 0) {
					// Nothing is in the accumulator, so just queue the message
					msg[msglen] = '\n';
					msglen++;

					msg[msglen] = '\0';

					hudmsgCreateWithDuration(msg, type, config, msglen * time60perchar);
					append = false;
				} else {
					// Queue the accumulator and then clear it.
					// The current message will be copied into the accumulator
					// for the next iteration.
					accum[accumlen] = '\n';
					accumlen++;

					accum[accumlen] = '\0';

					hudmsgCreateWithDuration(accum, type, config, accumlen * time60perchar);
					accumlen = 0;
				}
			}

			if (append) {
				for (j = 0; j < msglen; j++) {
					accum[accumlen + j] = msg[j];
				}

				accumlen += msglen;
			}

			msg[msglen] = '\0';
		} // end of outer loop

		// If there's anything remaining in the accumulator, queue it
		if (accumlen != 0) {
			accum[accumlen] = '\n';
			accumlen++;

			accum[accumlen] = '\0';

			hudmsgCreateWithDuration(accum, type, config, accumlen * time60perchar);
		}
	} else {
		hudmsgCreateFromArgs(srctext, type, config->unk00, config->unk01, config->unk02,
				config->unk04, config->unk08, config->colour, config->unk10, config->alignh,
				config->unk16, config->alignv, config->unk18, audiochannelnum, 0);
	}
}
#endif

void hudmsgCreateFromArgsWithoutFlags(char *text, s32 type, s32 conf00, s32 conf01, s32 conf02, struct fontchar **conf04, struct font **conf08, u32 textcolour, u32 shadowcolour, u32 alignh, s32 conf16, u32 alignv, s32 conf18, s32 arg14)
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

void hudmsgCalculatePosition(struct hudmessage *msg)
{
	s32 x;
	s32 y;
	s32 viewleft = g_Vars.players[msg->playernum]->viewleft / g_ScaleX;
	s32 viewtop = g_Vars.players[msg->playernum]->viewtop;
	s32 viewwidth = g_Vars.players[msg->playernum]->viewwidth / g_ScaleX;
	s32 viewheight = g_Vars.players[msg->playernum]->viewheight;
	s32 v0;

#if VERSION >= VERSION_NTSC_1_0
	s32 offset = (msg->alignh == HUDMSGALIGN_XMIDDLE) ? 10 : 0;

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

void hudmsgCreateFromArgs(char *text, s32 type, s32 conf00, s32 conf01, s32 conf02,
		struct fontchar **conf04, struct font **conf08,
		u32 textcolour, u32 glowcolour,
		u32 alignh, s32 conf16, u32 alignv, s32 conf18, s32 arg14, u32 flags)
{
	s32 j;
	struct hudmessage *msg;
	s32 hash = 0;
	s32 i;
	s32 index;
	s32 textwidth;
	s32 textheight;
	s32 xmarginaextra;
	s32 wrapwidth;
	char stacktext[400];
	s32 writeindex;

	if (type == HUDMSGTYPE_INGAMESUBTITLE && !optionsGetInGameSubtitles()) {
		return;
	}

	for (j = 0; text[j] != '\0'; j++) {
		hash = hash + text[j];
	}

	if ((flags & HUDMSGFLAG_ONLYIFALIVE) == 0 || !g_Vars.currentplayer->isdead) {
		if ((flags & HUDMSGFLAG_ALLOWDUPES) == 0) {
			// Check for duplicate messages
			s32 dupeofindex = -1;

			for (index = 0; index < g_NumHudMessages; index++) {
				if (g_HudMessages[index].state != HUDMSGSTATE_FREE
						&& g_HudMessages[index].state != HUDMSGSTATE_FADINGOUT
						&& g_HudMessages[index].playernum == g_Vars.currentplayernum
						&& g_HudMessages[index].hash == hash) {
					dupeofindex = index;
				}
			}

			if (dupeofindex >= 0) {
				return;
			}
		}

#if PAL
		g_ScaleX = 1;
#else
		g_ScaleX = g_ViRes == VIRES_HI ? 2 : 1;
#endif

		// Find an unused index for the new message
		for (index = 0; index < g_NumHudMessages; index++) {
			if (g_HudMessages[index].state == HUDMSGSTATE_FREE) {
				break;
			}
		}

		if (index >= g_NumHudMessages
				&& (type == HUDMSGTYPE_OBJECTIVECOMPLETE
					|| type == HUDMSGTYPE_OBJECTIVEFAILED
					|| type == HUDMSGTYPE_INGAMESUBTITLE)) {
			// Out of space - Check if an existing message can be replaced
			index = hudmsgGetNext(-1);

			while (index >= 0) {
				if (g_HudMessages[index].state == HUDMSGSTATE_QUEUED) {
					if (g_HudMessages[index].type == HUDMSGTYPE_DEFAULT
							|| g_HudMessages[index].type == HUDMSGTYPE_3
							|| g_HudMessages[index].type == HUDMSGTYPE_4) {
						// Good to replace this one
						break;
					}
				}

				// Can't replace - try and find another
				index = hudmsgGetNext(g_HudMessages[index].id);
			}
		}

		if (index >= 0 && index < g_NumHudMessages) {
			xmarginaextra = 0;
			msg = &g_HudMessages[index];
			wrapwidth = hudmsg0f0ddb1c(&xmarginaextra, conf16);
			textMeasure(&textheight, &textwidth, text, *conf04, *conf08, 0);

#if VERSION >= VERSION_JPN_FINAL
			if (textwidth > wrapwidth && (flags & HUDMSGFLAG_NOWRAP) == 0)
#else
			if (textwidth > wrapwidth)
#endif
			{
				i = 0;
				writeindex = 0;

				while (i < 400 && text[i] != '\0') {
					if (text[i] != '\n') {
						stacktext[writeindex++] = text[i];
					}

					i++;
				}

				stacktext[writeindex++] = '\n';
				stacktext[writeindex++] = '\0';

				textWrap(wrapwidth, stacktext, msg->text, *conf04, *conf08);
				textMeasure(&textheight, &textwidth, msg->text, *conf04, *conf08, 0);
			} else {
				strncpy(msg->text, text, 399);
				msg->text[399] = '\0';
			}

			msg->flags = flags;
			msg->playernum = g_Vars.currentplayernum;
			msg->type = type;
			msg->id = g_NextHudMessageId++;
			msg->state = HUDMSGSTATE_QUEUED;
			msg->timer = 0;
			msg->boxed = conf00;
			msg->allowfadein = conf01;
			msg->flash = conf02;
			msg->font1 = *conf04;
			msg->font2 = *conf08;
			msg->textcolour = textcolour;
			msg->glowcolour = glowcolour;
			msg->alignh = alignh;
			msg->alignv = alignv;
			msg->width = textwidth;
			msg->height = textheight;
			msg->xmarginextra = xmarginaextra;
			msg->xmargin = conf16;
			msg->ymargin = conf18;
			msg->hash = hash;

			hudmsgCalculatePosition(msg);

			if (flags & HUDMSGFLAG_NOCHANNEL) {
				msg->showduration = TICKS(arg14);
				msg->channelnum = -1;
			} else {
				msg->showduration = TICKS(g_HudmsgTypes[type].duration);
				msg->channelnum = arg14;
			}
		}

		g_ScaleX = 1;
	}
}

void hudmsgsTick(void)
{
	s32 k;
	s32 previd;
	bool show;
	struct hudmessage *msg;
#if VERSION >= VERSION_NTSC_1_0
	s32 prevplayernum;
#endif
	s32 i;
	s32 j;
#if VERSION >= VERSION_NTSC_1_0
	s32 index;
	bool hide;
#else
	bool hide;
	s32 index;
#endif
	f32 fadeintime;
	f32 fadeouttime;

	g_HudmsgsActive = false;

#if PAL
	g_ScaleX = 1;
#else
	g_ScaleX = (g_ViRes == VIRES_HI) ? 2 : 1;
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

	previd = -1; \
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

void hudmsgsSetOn(u32 reason)
{
	g_Vars.currentplayer->hudmessoff &= ~reason;
}

void hudmsgsSetOff(u32 reason)
{
	g_Vars.currentplayer->hudmessoff |= reason;
}

void hudmsgsRemoveForDeadPlayer(s32 playernum)
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

#if VERSION == VERSION_JPN_FINAL
GLOBAL_ASM(
glabel hudmsgsRender
.late_rodata
glabel var7f1adedc
.word 0x40490fdb
glabel var7f1adee0
.word hudmsgsRender+0xa34 # f0e0504
.word hudmsgsRender+0xa34 # f0e0504
.word hudmsgsRender+0xa34 # f0e0504
.word hudmsgsRender+0x3ec # f0dfebc
.word hudmsgsRender+0x644 # f0e0114
.word hudmsgsRender+0x7c8 # f0e0298
.text
/*  f0e0864:	27bdff00 */ 	addiu	$sp,$sp,-256
/*  f0e0868:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0e086c:	8def0c18 */ 	lw	$t7,0xc18($t7)
/*  f0e0870:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0e0874:	24020001 */ 	li	$v0,0x1
/*  f0e0878:	240e00ff */ 	li	$t6,0xff
/*  f0e087c:	00809025 */ 	move	$s2,$a0
/*  f0e0880:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f0e0884:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f0e0888:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f0e088c:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f0e0890:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f0e0894:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f0e0898:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f0e089c:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f0e08a0:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f0e08a4:	f7ba0050 */ 	sdc1	$f26,0x50($sp)
/*  f0e08a8:	f7b80048 */ 	sdc1	$f24,0x48($sp)
/*  f0e08ac:	f7b60040 */ 	sdc1	$f22,0x40($sp)
/*  f0e08b0:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f0e08b4:	afae00e0 */ 	sw	$t6,0xe0($sp)
/*  f0e08b8:	144f0005 */ 	bne	$v0,$t7,.JF0f0e08d0
/*  f0e08bc:	afa200dc */ 	sw	$v0,0xdc($sp)
/*  f0e08c0:	24180002 */ 	li	$t8,0x2
/*  f0e08c4:	3c018008 */ 	lui	$at,0x8008
/*  f0e08c8:	10000003 */ 	b	.JF0f0e08d8
/*  f0e08cc:	ac3800f4 */ 	sw	$t8,0xf4($at)
.JF0f0e08d0:
/*  f0e08d0:	3c018008 */ 	lui	$at,0x8008
/*  f0e08d4:	ac2200f4 */ 	sw	$v0,0xf4($at)
.JF0f0e08d8:
/*  f0e08d8:	0fc54b55 */ 	jal	text0f153628
/*  f0e08dc:	02402025 */ 	move	$a0,$s2
/*  f0e08e0:	3c19800a */ 	lui	$t9,0x800a
/*  f0e08e4:	8f39a8c8 */ 	lw	$t9,-0x5738($t9)
/*  f0e08e8:	00409025 */ 	move	$s2,$v0
/*  f0e08ec:	3c048007 */ 	lui	$a0,0x8007
/*  f0e08f0:	07210005 */ 	bgez	$t9,.JF0f0e0908
/*  f0e08f4:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0e08f8:	3c08800a */ 	lui	$t0,0x800a
/*  f0e08fc:	8d08a8cc */ 	lw	$t0,-0x5734($t0)
/*  f0e0900:	0500000e */ 	bltz	$t0,.JF0f0e093c
/*  f0e0904:	00000000 */ 	nop
.JF0f0e0908:
/*  f0e0908:	3c098007 */ 	lui	$t1,0x8007
/*  f0e090c:	8d290cb4 */ 	lw	$t1,0xcb4($t1)
/*  f0e0910:	1120000a */ 	beqz	$t1,.JF0f0e093c
/*  f0e0914:	00000000 */ 	nop
/*  f0e0918:	3c0a8006 */ 	lui	$t2,0x8006
/*  f0e091c:	8d4ad880 */ 	lw	$t2,-0x2780($t2)
/*  f0e0920:	15400006 */ 	bnez	$t2,.JF0f0e093c
/*  f0e0924:	00000000 */ 	nop
/*  f0e0928:	3c0b800a */ 	lui	$t3,0x800a
/*  f0e092c:	8d6ba8bc */ 	lw	$t3,-0x5744($t3)
/*  f0e0930:	15600002 */ 	bnez	$t3,.JF0f0e093c
/*  f0e0934:	00000000 */ 	nop
/*  f0e0938:	afa000dc */ 	sw	$zero,0xdc($sp)
.JF0f0e093c:
/*  f0e093c:	8c841538 */ 	lw	$a0,0x1538($a0)
/*  f0e0940:	27b700e4 */ 	addiu	$s7,$sp,0xe4
/*  f0e0944:	27b600e8 */ 	addiu	$s6,$sp,0xe8
/*  f0e0948:	1880029b */ 	blez	$a0,.JF0f0e13b8
/*  f0e094c:	2415ff00 */ 	li	$s5,-256
/*  f0e0950:	4481d000 */ 	mtc1	$at,$f26
/*  f0e0954:	3c0140e0 */ 	lui	$at,0x40e0
/*  f0e0958:	4481c000 */ 	mtc1	$at,$f24
/*  f0e095c:	3c014080 */ 	lui	$at,0x4080
/*  f0e0960:	4481b000 */ 	mtc1	$at,$f22
/*  f0e0964:	3c013f80 */ 	lui	$at,0x3f80
/*  f0e0968:	4481a000 */ 	mtc1	$at,$f20
/*  f0e096c:	afa00088 */ 	sw	$zero,0x88($sp)
/*  f0e0970:	241e00ff */ 	li	$s8,0xff
.JF0f0e0974:
/*  f0e0974:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0e0978:	8dad153c */ 	lw	$t5,0x153c($t5)
/*  f0e097c:	8fac0088 */ 	lw	$t4,0x88($sp)
/*  f0e0980:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0e0984:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e0988:	018d8021 */ 	addu	$s0,$t4,$t5
/*  f0e098c:	92030004 */ 	lbu	$v1,0x4($s0)
/*  f0e0990:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0e0994:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e0998:	54600004 */ 	bnezl	$v1,.JF0f0e09ac
/*  f0e099c:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0e09a0:	10000280 */ 	b	.JF0f0e13a4
/*  f0e09a4:	00021080 */ 	sll	$v0,$v0,0x2
/*  f0e09a8:	92020000 */ 	lbu	$v0,0x0($s0)
.JF0f0e09ac:
/*  f0e09ac:	24010001 */ 	li	$at,0x1
/*  f0e09b0:	5040000a */ 	beqzl	$v0,.JF0f0e09dc
/*  f0e09b4:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0e09b8:	10410007 */ 	beq	$v0,$at,.JF0f0e09d8
/*  f0e09bc:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f0e09c0:	51c0000c */ 	beqzl	$t6,.JF0f0e09f4
/*  f0e09c4:	92190003 */ 	lbu	$t9,0x3($s0)
/*  f0e09c8:	3c0f800a */ 	lui	$t7,0x800a
/*  f0e09cc:	8defa8bc */ 	lw	$t7,-0x5744($t7)
/*  f0e09d0:	8e1801c0 */ 	lw	$t8,0x1c0($s0)
/*  f0e09d4:	11f80006 */ 	beq	$t7,$t8,.JF0f0e09f0
.JF0f0e09d8:
/*  f0e09d8:	00041100 */ 	sll	$v0,$a0,0x4
.JF0f0e09dc:
/*  f0e09dc:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e09e0:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0e09e4:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e09e8:	1000026e */ 	b	.JF0f0e13a4
/*  f0e09ec:	00021080 */ 	sll	$v0,$v0,0x2
.JF0f0e09f0:
/*  f0e09f0:	92190003 */ 	lbu	$t9,0x3($s0)
.JF0f0e09f4:
/*  f0e09f4:	53200022 */ 	beqzl	$t9,.JF0f0e0a80
/*  f0e09f8:	8e130010 */ 	lw	$s3,0x10($s0)
/*  f0e09fc:	96080006 */ 	lhu	$t0,0x6($s0)
/*  f0e0a00:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e0a04:	44882000 */ 	mtc1	$t0,$f4
/*  f0e0a08:	05010004 */ 	bgez	$t0,.JF0f0e0a1c
/*  f0e0a0c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e0a10:	44814000 */ 	mtc1	$at,$f8
/*  f0e0a14:	00000000 */ 	nop
/*  f0e0a18:	46083180 */ 	add.s	$f6,$f6,$f8
.JF0f0e0a1c:
/*  f0e0a1c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0e0a20:	c42aec0c */ 	lwc1	$f10,-0x13f4($at)
/*  f0e0a24:	3c014270 */ 	lui	$at,0x4270
/*  f0e0a28:	44819000 */ 	mtc1	$at,$f18
/*  f0e0a2c:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0e0a30:	0c0068df */ 	jal	sinf
/*  f0e0a34:	46128303 */ 	div.s	$f12,$f16,$f18
/*  f0e0a38:	44802000 */ 	mtc1	$zero,$f4
/*  f0e0a3c:	3c014340 */ 	lui	$at,0x4340
/*  f0e0a40:	44814000 */ 	mtc1	$at,$f8
/*  f0e0a44:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0e0a48:	46000086 */ 	mov.s	$f2,$f0
/*  f0e0a4c:	45000002 */ 	bc1f	.JF0f0e0a58
/*  f0e0a50:	00000000 */ 	nop
/*  f0e0a54:	46000087 */ 	neg.s	$f2,$f0
.JF0f0e0a58:
/*  f0e0a58:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0e0a5c:	8e090010 */ 	lw	$t1,0x10($s0)
/*  f0e0a60:	8e140014 */ 	lw	$s4,0x14($s0)
/*  f0e0a64:	92030004 */ 	lbu	$v1,0x4($s0)
/*  f0e0a68:	01355024 */ 	and	$t2,$t1,$s5
/*  f0e0a6c:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f0e0a70:	440c5000 */ 	mfc1	$t4,$f10
/*  f0e0a74:	10000005 */ 	b	.JF0f0e0a8c
/*  f0e0a78:	014c9821 */ 	addu	$s3,$t2,$t4
/*  f0e0a7c:	8e130010 */ 	lw	$s3,0x10($s0)
.JF0f0e0a80:
/*  f0e0a80:	8e140014 */ 	lw	$s4,0x14($s0)
/*  f0e0a84:	366d00a0 */ 	ori	$t5,$s3,0xa0
/*  f0e0a88:	01a09825 */ 	move	$s3,$t5
.JF0f0e0a8c:
/*  f0e0a8c:	240100ff */ 	li	$at,0xff
/*  f0e0a90:	1061001c */ 	beq	$v1,$at,.JF0f0e0b04
/*  f0e0a94:	00601025 */ 	move	$v0,$v1
/*  f0e0a98:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f0e0a9c:	004e0019 */ 	multu	$v0,$t6
/*  f0e0aa0:	00401825 */ 	move	$v1,$v0
/*  f0e0aa4:	329800ff */ 	andi	$t8,$s4,0xff
/*  f0e0aa8:	02754024 */ 	and	$t0,$s3,$s5
/*  f0e0aac:	02955824 */ 	and	$t3,$s4,$s5
/*  f0e0ab0:	00007812 */ 	mflo	$t7
/*  f0e0ab4:	00000000 */ 	nop
/*  f0e0ab8:	00000000 */ 	nop
/*  f0e0abc:	01fe001b */ 	divu	$zero,$t7,$s8
/*  f0e0ac0:	00002012 */ 	mflo	$a0
/*  f0e0ac4:	308900ff */ 	andi	$t1,$a0,0xff
/*  f0e0ac8:	17c00002 */ 	bnez	$s8,.JF0f0e0ad4
/*  f0e0acc:	00000000 */ 	nop
/*  f0e0ad0:	0007000d */ 	break	0x7
.JF0f0e0ad4:
/*  f0e0ad4:	00780019 */ 	multu	$v1,$t8
/*  f0e0ad8:	01099821 */ 	addu	$s3,$t0,$t1
/*  f0e0adc:	0000c812 */ 	mflo	$t9
/*  f0e0ae0:	00000000 */ 	nop
/*  f0e0ae4:	00000000 */ 	nop
/*  f0e0ae8:	033e001b */ 	divu	$zero,$t9,$s8
/*  f0e0aec:	00002812 */ 	mflo	$a1
/*  f0e0af0:	30aa00ff */ 	andi	$t2,$a1,0xff
/*  f0e0af4:	17c00002 */ 	bnez	$s8,.JF0f0e0b00
/*  f0e0af8:	00000000 */ 	nop
/*  f0e0afc:	0007000d */ 	break	0x7
.JF0f0e0b00:
/*  f0e0b00:	016aa021 */ 	addu	$s4,$t3,$t2
.JF0f0e0b04:
/*  f0e0b04:	960c0018 */ 	lhu	$t4,0x18($s0)
/*  f0e0b08:	24010006 */ 	li	$at,0x6
/*  f0e0b0c:	afac00e8 */ 	sw	$t4,0xe8($sp)
/*  f0e0b10:	960d001a */ 	lhu	$t5,0x1a($s0)
/*  f0e0b14:	afad00e4 */ 	sw	$t5,0xe4($sp)
/*  f0e0b18:	8e0e01b4 */ 	lw	$t6,0x1b4($s0)
/*  f0e0b1c:	55c10011 */ 	bnel	$t6,$at,.JF0f0e0b64
/*  f0e0b20:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
/*  f0e0b24:	0fc30a21 */ 	jal	playerIsHealthVisible
/*  f0e0b28:	00000000 */ 	nop
/*  f0e0b2c:	5040000d */ 	beqzl	$v0,.JF0f0e0b64
/*  f0e0b30:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
/*  f0e0b34:	0fc309eb */ 	jal	playerGetHealthBarHeightFrac
/*  f0e0b38:	00000000 */ 	nop
/*  f0e0b3c:	3c014180 */ 	lui	$at,0x4180
/*  f0e0b40:	44818000 */ 	mtc1	$at,$f16
/*  f0e0b44:	8faf00e4 */ 	lw	$t7,0xe4($sp)
/*  f0e0b48:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0e0b4c:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e0b50:	44192000 */ 	mfc1	$t9,$f4
/*  f0e0b54:	00000000 */ 	nop
/*  f0e0b58:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f0e0b5c:	afa800e4 */ 	sw	$t0,0xe4($sp)
/*  f0e0b60:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
.JF0f0e0b64:
/*  f0e0b64:	2401000b */ 	li	$at,0xb
/*  f0e0b68:	55210031 */ 	bnel	$t1,$at,.JF0f0e0c30
/*  f0e0b6c:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f0e0b70:	8fab00e8 */ 	lw	$t3,0xe8($sp)
/*  f0e0b74:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0e0b78:	8d8c00f4 */ 	lw	$t4,0xf4($t4)
/*  f0e0b7c:	256afffc */ 	addiu	$t2,$t3,-4
/*  f0e0b80:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e0b84:	014c0019 */ 	multu	$t2,$t4
/*  f0e0b88:	02408825 */ 	move	$s1,$s2
/*  f0e0b8c:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e0b90:	00006812 */ 	mflo	$t5
/*  f0e0b94:	448d4000 */ 	mtc1	$t5,$f8
/*  f0e0b98:	00000000 */ 	nop
/*  f0e0b9c:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0e0ba0:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f0e0ba4:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e0ba8:	44188000 */ 	mfc1	$t8,$f16
/*  f0e0bac:	00000000 */ 	nop
/*  f0e0bb0:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f0e0bb4:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f0e0bb8:	03214025 */ 	or	$t0,$t9,$at
/*  f0e0bbc:	0c002ede */ 	jal	viGetBufHeight
/*  f0e0bc0:	ae280000 */ 	sw	$t0,0x0($s1)
/*  f0e0bc4:	8fa900e8 */ 	lw	$t1,0xe8($sp)
/*  f0e0bc8:	960b001c */ 	lhu	$t3,0x1c($s0)
/*  f0e0bcc:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0e0bd0:	8dad00f4 */ 	lw	$t5,0xf4($t5)
/*  f0e0bd4:	012b5021 */ 	addu	$t2,$t1,$t3
/*  f0e0bd8:	254c0003 */ 	addiu	$t4,$t2,0x3
/*  f0e0bdc:	018d0019 */ 	multu	$t4,$t5
/*  f0e0be0:	44825000 */ 	mtc1	$v0,$f10
/*  f0e0be4:	00000000 */ 	nop
/*  f0e0be8:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0e0bec:	00007012 */ 	mflo	$t6
/*  f0e0bf0:	448e9000 */ 	mtc1	$t6,$f18
/*  f0e0bf4:	00000000 */ 	nop
/*  f0e0bf8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0e0bfc:	46162202 */ 	mul.s	$f8,$f4,$f22
/*  f0e0c00:	00000000 */ 	nop
/*  f0e0c04:	46168482 */ 	mul.s	$f18,$f16,$f22
/*  f0e0c08:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f0e0c0c:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e0c10:	440f3000 */ 	mfc1	$t7,$f6
/*  f0e0c14:	440b2000 */ 	mfc1	$t3,$f4
/*  f0e0c18:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f0e0c1c:	00194300 */ 	sll	$t0,$t9,0xc
/*  f0e0c20:	316a0fff */ 	andi	$t2,$t3,0xfff
/*  f0e0c24:	01486025 */ 	or	$t4,$t2,$t0
/*  f0e0c28:	ae2c0004 */ 	sw	$t4,0x4($s1)
/*  f0e0c2c:	920d0000 */ 	lbu	$t5,0x0($s0)
.JF0f0e0c30:
/*  f0e0c30:	2da10006 */ 	sltiu	$at,$t5,0x6
/*  f0e0c34:	10200198 */ 	beqz	$at,.JF0f0e1298
/*  f0e0c38:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0e0c3c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0e0c40:	002d0821 */ 	addu	$at,$at,$t5
/*  f0e0c44:	8c2dec10 */ 	lw	$t5,-0x13f0($at)
/*  f0e0c48:	01a00008 */ 	jr	$t5
/*  f0e0c4c:	00000000 */ 	nop
/*  f0e0c50:	8e110010 */ 	lw	$s1,0x10($s0)
/*  f0e0c54:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0e0c58:	240100ff */ 	li	$at,0xff
/*  f0e0c5c:	362e0040 */ 	ori	$t6,$s1,0x40
/*  f0e0c60:	1041000e */ 	beq	$v0,$at,.JF0f0e0c9c
/*  f0e0c64:	01c08825 */ 	move	$s1,$t6
/*  f0e0c68:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f0e0c6c:	00580019 */ 	multu	$v0,$t8
/*  f0e0c70:	0235c824 */ 	and	$t9,$s1,$s5
/*  f0e0c74:	00007812 */ 	mflo	$t7
/*  f0e0c78:	00000000 */ 	nop
/*  f0e0c7c:	00000000 */ 	nop
/*  f0e0c80:	01fe001b */ 	divu	$zero,$t7,$s8
/*  f0e0c84:	00001812 */ 	mflo	$v1
/*  f0e0c88:	306900ff */ 	andi	$t1,$v1,0xff
/*  f0e0c8c:	17c00002 */ 	bnez	$s8,.JF0f0e0c98
/*  f0e0c90:	00000000 */ 	nop
/*  f0e0c94:	0007000d */ 	break	0x7
.JF0f0e0c98:
/*  f0e0c98:	03298821 */ 	addu	$s1,$t9,$t1
.JF0f0e0c9c:
/*  f0e0c9c:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0e0ca0:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0e0ca4:	00420019 */ 	multu	$v0,$v0
/*  f0e0ca8:	00005812 */ 	mflo	$t3
/*  f0e0cac:	00000000 */ 	nop
/*  f0e0cb0:	00000000 */ 	nop
/*  f0e0cb4:	00630019 */ 	multu	$v1,$v1
/*  f0e0cb8:	00005012 */ 	mflo	$t2
/*  f0e0cbc:	016a4021 */ 	addu	$t0,$t3,$t2
/*  f0e0cc0:	44884000 */ 	mtc1	$t0,$f8
/*  f0e0cc4:	0c012838 */ 	jal	sqrtf
/*  f0e0cc8:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f0e0ccc:	3c014304 */ 	lui	$at,0x4304
/*  f0e0cd0:	44813000 */ 	mtc1	$at,$f6
/*  f0e0cd4:	44802000 */ 	mtc1	$zero,$f4
/*  f0e0cd8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e0cdc:	46060280 */ 	add.s	$f10,$f0,$f6
/*  f0e0ce0:	46185083 */ 	div.s	$f2,$f10,$f24
/*  f0e0ce4:	4602d03c */ 	c.lt.s	$f26,$f2
/*  f0e0ce8:	00000000 */ 	nop
/*  f0e0cec:	45020003 */ 	bc1fl	.JF0f0e0cfc
/*  f0e0cf0:	960c0006 */ 	lhu	$t4,0x6($s0)
/*  f0e0cf4:	4600d086 */ 	mov.s	$f2,$f26
/*  f0e0cf8:	960c0006 */ 	lhu	$t4,0x6($s0)
.JF0f0e0cfc:
/*  f0e0cfc:	448c8000 */ 	mtc1	$t4,$f16
/*  f0e0d00:	05810004 */ 	bgez	$t4,.JF0f0e0d14
/*  f0e0d04:	46808320 */ 	cvt.s.w	$f12,$f16
/*  f0e0d08:	44819000 */ 	mtc1	$at,$f18
/*  f0e0d0c:	00000000 */ 	nop
/*  f0e0d10:	46126300 */ 	add.s	$f12,$f12,$f18
.JF0f0e0d14:
/*  f0e0d14:	46026083 */ 	div.s	$f2,$f12,$f2
/*  f0e0d18:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f0e0d1c:	8fa500e4 */ 	lw	$a1,0xe4($sp)
/*  f0e0d20:	00003825 */ 	move	$a3,$zero
/*  f0e0d24:	46186002 */ 	mul.s	$f0,$f12,$f24
/*  f0e0d28:	44060000 */ 	mfc1	$a2,$f0
/*  f0e0d2c:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f0e0d30:	00000000 */ 	nop
/*  f0e0d34:	45020003 */ 	bc1fl	.JF0f0e0d44
/*  f0e0d38:	4604103c */ 	c.lt.s	$f2,$f4
/*  f0e0d3c:	4600a086 */ 	mov.s	$f2,$f20
/*  f0e0d40:	4604103c */ 	c.lt.s	$f2,$f4
.JF0f0e0d44:
/*  f0e0d44:	00000000 */ 	nop
/*  f0e0d48:	45000003 */ 	bc1f	.JF0f0e0d58
/*  f0e0d4c:	00000000 */ 	nop
/*  f0e0d50:	44801000 */ 	mtc1	$zero,$f2
/*  f0e0d54:	00000000 */ 	nop
.JF0f0e0d58:
/*  f0e0d58:	0fc54ce3 */ 	jal	textSetDiagonalBlend
/*  f0e0d5c:	e7a200c0 */ 	swc1	$f2,0xc0($sp)
/*  f0e0d60:	920d0001 */ 	lbu	$t5,0x1($s0)
/*  f0e0d64:	c7a200c0 */ 	lwc1	$f2,0xc0($sp)
/*  f0e0d68:	02402025 */ 	move	$a0,$s2
/*  f0e0d6c:	11a00027 */ 	beqz	$t5,.JF0f0e0e0c
/*  f0e0d70:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0e0d74:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0e0d78:	9619001e */ 	lhu	$t9,0x1e($s0)
/*  f0e0d7c:	8fae00e8 */ 	lw	$t6,0xe8($sp)
/*  f0e0d80:	960f001c */ 	lhu	$t7,0x1c($s0)
/*  f0e0d84:	03384821 */ 	addu	$t1,$t9,$t8
/*  f0e0d88:	252bffff */ 	addiu	$t3,$t1,-1
/*  f0e0d8c:	01ee3821 */ 	addu	$a3,$t7,$t6
/*  f0e0d90:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f0e0d94:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e0d98:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f0e0d9c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e0da0:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0e0da4:	02402025 */ 	move	$a0,$s2
/*  f0e0da8:	2706fffd */ 	addiu	$a2,$t8,-3
/*  f0e0dac:	0fc37a42 */ 	jal	hudmsgRenderBox
/*  f0e0db0:	25c5fffd */ 	addiu	$a1,$t6,-3
/*  f0e0db4:	0c002eeb */ 	jal	viGetWidth
/*  f0e0db8:	00409025 */ 	move	$s2,$v0
/*  f0e0dbc:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e0dc0:	00115403 */ 	sra	$t2,$s1,0x10
/*  f0e0dc4:	0c002eef */ 	jal	viGetHeight
/*  f0e0dc8:	01408825 */ 	move	$s1,$t2
/*  f0e0dcc:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0e0dd0:	02402025 */ 	move	$a0,$s2
/*  f0e0dd4:	02c02825 */ 	move	$a1,$s6
/*  f0e0dd8:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e0ddc:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f0e0de0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e0de4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e0de8:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e0dec:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e0df0:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e0df4:	02e03025 */ 	move	$a2,$s7
/*  f0e0df8:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e0dfc:	0fc55886 */ 	jal	textRenderProjected
/*  f0e0e00:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e0e04:	1000001f */ 	b	.JF0f0e0e84
/*  f0e0e08:	00409025 */ 	move	$s2,$v0
.JF0f0e0e0c:
/*  f0e0e0c:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f0e0e10:	9619001e */ 	lhu	$t9,0x1e($s0)
/*  f0e0e14:	960e001c */ 	lhu	$t6,0x1c($s0)
/*  f0e0e18:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e0e1c:	0326c021 */ 	addu	$t8,$t9,$a2
/*  f0e0e20:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e0e24:	0fc54c68 */ 	jal	text0f153a34
/*  f0e0e28:	01c53821 */ 	addu	$a3,$t6,$a1
/*  f0e0e2c:	0c002eeb */ 	jal	viGetWidth
/*  f0e0e30:	00409025 */ 	move	$s2,$v0
/*  f0e0e34:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e0e38:	00114c03 */ 	sra	$t1,$s1,0x10
/*  f0e0e3c:	0c002eef */ 	jal	viGetHeight
/*  f0e0e40:	01208825 */ 	move	$s1,$t1
/*  f0e0e44:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*  f0e0e48:	02402025 */ 	move	$a0,$s2
/*  f0e0e4c:	02c02825 */ 	move	$a1,$s6
/*  f0e0e50:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e0e54:	8e0a000c */ 	lw	$t2,0xc($s0)
/*  f0e0e58:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0e0e5c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e0e60:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0e0e64:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0e0e68:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f0e0e6c:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e0e70:	02e03025 */ 	move	$a2,$s7
/*  f0e0e74:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e0e78:	0fc55d34 */ 	jal	func0f1574d0jf
/*  f0e0e7c:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0e0e80:	00409025 */ 	move	$s2,$v0
.JF0f0e0e84:
/*  f0e0e84:	920801c9 */ 	lbu	$t0,0x1c9($s0)
/*  f0e0e88:	24010006 */ 	li	$at,0x6
/*  f0e0e8c:	15010002 */ 	bne	$t0,$at,.JF0f0e0e98
/*  f0e0e90:	00000000 */ 	nop
/*  f0e0e94:	afa000e0 */ 	sw	$zero,0xe0($sp)
.JF0f0e0e98:
/*  f0e0e98:	0fc54d6e */ 	jal	textResetBlends
/*  f0e0e9c:	00000000 */ 	nop
/*  f0e0ea0:	100000fe */ 	b	.JF0f0e129c
/*  f0e0ea4:	8e0801b4 */ 	lw	$t0,0x1b4($s0)
/*  f0e0ea8:	920c0001 */ 	lbu	$t4,0x1($s0)
/*  f0e0eac:	8fa900e8 */ 	lw	$t1,0xe8($sp)
/*  f0e0eb0:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f0e0eb4:	11800037 */ 	beqz	$t4,.JF0f0e0f94
/*  f0e0eb8:	2525fffd */ 	addiu	$a1,$t1,-3
/*  f0e0ebc:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0e0ec0:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0e0ec4:	240100ff */ 	li	$at,0xff
/*  f0e0ec8:	346e0040 */ 	ori	$t6,$v1,0x40
/*  f0e0ecc:	1041000e */ 	beq	$v0,$at,.JF0f0e0f08
/*  f0e0ed0:	01c01825 */ 	move	$v1,$t6
/*  f0e0ed4:	31cd00ff */ 	andi	$t5,$t6,0xff
/*  f0e0ed8:	004d0019 */ 	multu	$v0,$t5
/*  f0e0edc:	00757824 */ 	and	$t7,$v1,$s5
/*  f0e0ee0:	0000c812 */ 	mflo	$t9
/*  f0e0ee4:	00000000 */ 	nop
/*  f0e0ee8:	00000000 */ 	nop
/*  f0e0eec:	033e001b */ 	divu	$zero,$t9,$s8
/*  f0e0ef0:	00002012 */ 	mflo	$a0
/*  f0e0ef4:	309800ff */ 	andi	$t8,$a0,0xff
/*  f0e0ef8:	17c00002 */ 	bnez	$s8,.JF0f0e0f04
/*  f0e0efc:	00000000 */ 	nop
/*  f0e0f00:	0007000d */ 	break	0x7
.JF0f0e0f04:
/*  f0e0f04:	01f81821 */ 	addu	$v1,$t7,$t8
.JF0f0e0f08:
/*  f0e0f08:	9608001e */ 	lhu	$t0,0x1e($s0)
/*  f0e0f0c:	960a001c */ 	lhu	$t2,0x1c($s0)
/*  f0e0f10:	e7b4001c */ 	swc1	$f20,0x1c($sp)
/*  f0e0f14:	010b6021 */ 	addu	$t4,$t0,$t3
/*  f0e0f18:	258effff */ 	addiu	$t6,$t4,-1
/*  f0e0f1c:	01493821 */ 	addu	$a3,$t2,$t1
/*  f0e0f20:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f0e0f24:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e0f28:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e0f2c:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0e0f30:	02402025 */ 	move	$a0,$s2
/*  f0e0f34:	0fc37a42 */ 	jal	hudmsgRenderBox
/*  f0e0f38:	2566fffd */ 	addiu	$a2,$t3,-3
/*  f0e0f3c:	0c002eeb */ 	jal	viGetWidth
/*  f0e0f40:	00409025 */ 	move	$s2,$v0
/*  f0e0f44:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e0f48:	00116c03 */ 	sra	$t5,$s1,0x10
/*  f0e0f4c:	0c002eef */ 	jal	viGetHeight
/*  f0e0f50:	01a08825 */ 	move	$s1,$t5
/*  f0e0f54:	8e190008 */ 	lw	$t9,0x8($s0)
/*  f0e0f58:	02402025 */ 	move	$a0,$s2
/*  f0e0f5c:	02c02825 */ 	move	$a1,$s6
/*  f0e0f60:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e0f64:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f0e0f68:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e0f6c:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e0f70:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e0f74:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e0f78:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e0f7c:	02e03025 */ 	move	$a2,$s7
/*  f0e0f80:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e0f84:	0fc55886 */ 	jal	textRenderProjected
/*  f0e0f88:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e0f8c:	10000021 */ 	b	.JF0f0e1014
/*  f0e0f90:	00409025 */ 	move	$s2,$v0
.JF0f0e0f94:
/*  f0e0f94:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f0e0f98:	9608001e */ 	lhu	$t0,0x1e($s0)
/*  f0e0f9c:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0e0fa0:	9609001c */ 	lhu	$t1,0x1c($s0)
/*  f0e0fa4:	01065821 */ 	addu	$t3,$t0,$a2
/*  f0e0fa8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e0fac:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e0fb0:	02402025 */ 	move	$a0,$s2
/*  f0e0fb4:	0fc54c68 */ 	jal	text0f153a34
/*  f0e0fb8:	01253821 */ 	addu	$a3,$t1,$a1
/*  f0e0fbc:	0c002eeb */ 	jal	viGetWidth
/*  f0e0fc0:	00409025 */ 	move	$s2,$v0
/*  f0e0fc4:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e0fc8:	00116403 */ 	sra	$t4,$s1,0x10
/*  f0e0fcc:	0c002eef */ 	jal	viGetHeight
/*  f0e0fd0:	01808825 */ 	move	$s1,$t4
/*  f0e0fd4:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*  f0e0fd8:	02402025 */ 	move	$a0,$s2
/*  f0e0fdc:	02c02825 */ 	move	$a1,$s6
/*  f0e0fe0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e0fe4:	8e0d000c */ 	lw	$t5,0xc($s0)
/*  f0e0fe8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0e0fec:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e0ff0:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0e0ff4:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0e0ff8:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f0e0ffc:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e1000:	02e03025 */ 	move	$a2,$s7
/*  f0e1004:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e1008:	0fc55d34 */ 	jal	func0f1574d0jf
/*  f0e100c:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e1010:	00409025 */ 	move	$s2,$v0
.JF0f0e1014:
/*  f0e1014:	921901c9 */ 	lbu	$t9,0x1c9($s0)
/*  f0e1018:	24010006 */ 	li	$at,0x6
/*  f0e101c:	5721009f */ 	bnel	$t9,$at,.JF0f0e129c
/*  f0e1020:	8e0801b4 */ 	lw	$t0,0x1b4($s0)
/*  f0e1024:	1000009c */ 	b	.JF0f0e1298
/*  f0e1028:	afa000e0 */ 	sw	$zero,0xe0($sp)
/*  f0e102c:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0e1030:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0e1034:	00420019 */ 	multu	$v0,$v0
/*  f0e1038:	00007812 */ 	mflo	$t7
/*  f0e103c:	00000000 */ 	nop
/*  f0e1040:	00000000 */ 	nop
/*  f0e1044:	00630019 */ 	multu	$v1,$v1
/*  f0e1048:	00004812 */ 	mflo	$t1
/*  f0e104c:	01e9c021 */ 	addu	$t8,$t7,$t1
/*  f0e1050:	44984000 */ 	mtc1	$t8,$f8
/*  f0e1054:	0c012838 */ 	jal	sqrtf
/*  f0e1058:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f0e105c:	3c0142b8 */ 	lui	$at,0x42b8
/*  f0e1060:	44813000 */ 	mtc1	$at,$f6
/*  f0e1064:	8e110010 */ 	lw	$s1,0x10($s0)
/*  f0e1068:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0e106c:	46060280 */ 	add.s	$f10,$f0,$f6
/*  f0e1070:	240100ff */ 	li	$at,0xff
/*  f0e1074:	36280040 */ 	ori	$t0,$s1,0x40
/*  f0e1078:	01008825 */ 	move	$s1,$t0
/*  f0e107c:	1041000e */ 	beq	$v0,$at,.JF0f0e10b8
/*  f0e1080:	46185083 */ 	div.s	$f2,$f10,$f24
/*  f0e1084:	310a00ff */ 	andi	$t2,$t0,0xff
/*  f0e1088:	004a0019 */ 	multu	$v0,$t2
/*  f0e108c:	02356024 */ 	and	$t4,$s1,$s5
/*  f0e1090:	00005812 */ 	mflo	$t3
/*  f0e1094:	00000000 */ 	nop
/*  f0e1098:	00000000 */ 	nop
/*  f0e109c:	017e001b */ 	divu	$zero,$t3,$s8
/*  f0e10a0:	00001812 */ 	mflo	$v1
/*  f0e10a4:	306e00ff */ 	andi	$t6,$v1,0xff
/*  f0e10a8:	17c00002 */ 	bnez	$s8,.JF0f0e10b4
/*  f0e10ac:	00000000 */ 	nop
/*  f0e10b0:	0007000d */ 	break	0x7
.JF0f0e10b4:
/*  f0e10b4:	018e8821 */ 	addu	$s1,$t4,$t6
.JF0f0e10b8:
/*  f0e10b8:	960d0006 */ 	lhu	$t5,0x6($s0)
/*  f0e10bc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e10c0:	448d8000 */ 	mtc1	$t5,$f16
/*  f0e10c4:	05a10004 */ 	bgez	$t5,.JF0f0e10d8
/*  f0e10c8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0e10cc:	44812000 */ 	mtc1	$at,$f4
/*  f0e10d0:	00000000 */ 	nop
/*  f0e10d4:	46049480 */ 	add.s	$f18,$f18,$f4
.JF0f0e10d8:
/*  f0e10d8:	46121201 */ 	sub.s	$f8,$f2,$f18
/*  f0e10dc:	9619001c */ 	lhu	$t9,0x1c($s0)
/*  f0e10e0:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f0e10e4:	9609001e */ 	lhu	$t1,0x1e($s0)
/*  f0e10e8:	46184002 */ 	mul.s	$f0,$f8,$f24
/*  f0e10ec:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0e10f0:	e7a200a8 */ 	swc1	$f2,0xa8($sp)
/*  f0e10f4:	24070002 */ 	li	$a3,0x2
/*  f0e10f8:	032f2021 */ 	addu	$a0,$t9,$t7
/*  f0e10fc:	01382821 */ 	addu	$a1,$t1,$t8
/*  f0e1100:	44060000 */ 	mfc1	$a2,$f0
/*  f0e1104:	0fc54ce3 */ 	jal	textSetDiagonalBlend
/*  f0e1108:	00000000 */ 	nop
/*  f0e110c:	c7a200a8 */ 	lwc1	$f2,0xa8($sp)
/*  f0e1110:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e1114:	8fab00e8 */ 	lw	$t3,0xe8($sp)
/*  f0e1118:	4602d03c */ 	c.lt.s	$f26,$f2
/*  f0e111c:	8fac00e4 */ 	lw	$t4,0xe4($sp)
/*  f0e1120:	02402025 */ 	move	$a0,$s2
/*  f0e1124:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0e1128:	45000002 */ 	bc1f	.JF0f0e1134
/*  f0e112c:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f0e1130:	4600d086 */ 	mov.s	$f2,$f26
.JF0f0e1134:
/*  f0e1134:	96080006 */ 	lhu	$t0,0x6($s0)
/*  f0e1138:	44883000 */ 	mtc1	$t0,$f6
/*  f0e113c:	05010004 */ 	bgez	$t0,.JF0f0e1150
/*  f0e1140:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0e1144:	44818000 */ 	mtc1	$at,$f16
/*  f0e1148:	00000000 */ 	nop
/*  f0e114c:	46105280 */ 	add.s	$f10,$f10,$f16
.JF0f0e1150:
/*  f0e1150:	46025083 */ 	div.s	$f2,$f10,$f2
/*  f0e1154:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f0e1158:	00000000 */ 	nop
/*  f0e115c:	45020003 */ 	bc1fl	.JF0f0e116c
/*  f0e1160:	920a0001 */ 	lbu	$t2,0x1($s0)
/*  f0e1164:	4600a086 */ 	mov.s	$f2,$f20
/*  f0e1168:	920a0001 */ 	lbu	$t2,0x1($s0)
.JF0f0e116c:
/*  f0e116c:	51400027 */ 	beqzl	$t2,.JF0f0e120c
/*  f0e1170:	960d001e */ 	lhu	$t5,0x1e($s0)
/*  f0e1174:	960d001e */ 	lhu	$t5,0x1e($s0)
/*  f0e1178:	960e001c */ 	lhu	$t6,0x1c($s0)
/*  f0e117c:	4602a101 */ 	sub.s	$f4,$f20,$f2
/*  f0e1180:	01acc821 */ 	addu	$t9,$t5,$t4
/*  f0e1184:	272fffff */ 	addiu	$t7,$t9,-1
/*  f0e1188:	01cb3821 */ 	addu	$a3,$t6,$t3
/*  f0e118c:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f0e1190:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e1194:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f0e1198:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e119c:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0e11a0:	02402025 */ 	move	$a0,$s2
/*  f0e11a4:	2565fffd */ 	addiu	$a1,$t3,-3
/*  f0e11a8:	0fc37a42 */ 	jal	hudmsgRenderBox
/*  f0e11ac:	2586fffd */ 	addiu	$a2,$t4,-3
/*  f0e11b0:	0c002eeb */ 	jal	viGetWidth
/*  f0e11b4:	00409025 */ 	move	$s2,$v0
/*  f0e11b8:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e11bc:	00114c03 */ 	sra	$t1,$s1,0x10
/*  f0e11c0:	0c002eef */ 	jal	viGetHeight
/*  f0e11c4:	01208825 */ 	move	$s1,$t1
/*  f0e11c8:	8e180008 */ 	lw	$t8,0x8($s0)
/*  f0e11cc:	02402025 */ 	move	$a0,$s2
/*  f0e11d0:	02c02825 */ 	move	$a1,$s6
/*  f0e11d4:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e11d8:	8e08000c */ 	lw	$t0,0xc($s0)
/*  f0e11dc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e11e0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e11e4:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e11e8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e11ec:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e11f0:	02e03025 */ 	move	$a2,$s7
/*  f0e11f4:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e11f8:	0fc55886 */ 	jal	textRenderProjected
/*  f0e11fc:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0e1200:	1000001e */ 	b	.JF0f0e127c
/*  f0e1204:	00409025 */ 	move	$s2,$v0
/*  f0e1208:	960d001e */ 	lhu	$t5,0x1e($s0)
.JF0f0e120c:
/*  f0e120c:	960b001c */ 	lhu	$t3,0x1c($s0)
/*  f0e1210:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e1214:	01a66021 */ 	addu	$t4,$t5,$a2
/*  f0e1218:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e121c:	0fc54c68 */ 	jal	text0f153a34
/*  f0e1220:	01653821 */ 	addu	$a3,$t3,$a1
/*  f0e1224:	0c002eeb */ 	jal	viGetWidth
/*  f0e1228:	00409025 */ 	move	$s2,$v0
/*  f0e122c:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e1230:	0011cc03 */ 	sra	$t9,$s1,0x10
/*  f0e1234:	0c002eef */ 	jal	viGetHeight
/*  f0e1238:	03208825 */ 	move	$s1,$t9
/*  f0e123c:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*  f0e1240:	02402025 */ 	move	$a0,$s2
/*  f0e1244:	02c02825 */ 	move	$a1,$s6
/*  f0e1248:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e124c:	8e09000c */ 	lw	$t1,0xc($s0)
/*  f0e1250:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0e1254:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e1258:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0e125c:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0e1260:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f0e1264:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e1268:	02e03025 */ 	move	$a2,$s7
/*  f0e126c:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e1270:	0fc55d34 */ 	jal	func0f1574d0jf
/*  f0e1274:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e1278:	00409025 */ 	move	$s2,$v0
.JF0f0e127c:
/*  f0e127c:	921801c9 */ 	lbu	$t8,0x1c9($s0)
/*  f0e1280:	24010006 */ 	li	$at,0x6
/*  f0e1284:	17010002 */ 	bne	$t8,$at,.JF0f0e1290
/*  f0e1288:	00000000 */ 	nop
/*  f0e128c:	afa000e0 */ 	sw	$zero,0xe0($sp)
.JF0f0e1290:
/*  f0e1290:	0fc54d6e */ 	jal	textResetBlends
/*  f0e1294:	00000000 */ 	nop
.JF0f0e1298:
/*  f0e1298:	8e0801b4 */ 	lw	$t0,0x1b4($s0)
.JF0f0e129c:
/*  f0e129c:	2401000b */ 	li	$at,0xb
/*  f0e12a0:	15010039 */ 	bne	$t0,$at,.JF0f0e1388
/*  f0e12a4:	00000000 */ 	nop
/*  f0e12a8:	afb2009c */ 	sw	$s2,0x9c($sp)
/*  f0e12ac:	0c002f29 */ 	jal	viGetViewLeft
/*  f0e12b0:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e12b4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e12b8:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f0e12bc:	01608025 */ 	move	$s0,$t3
/*  f0e12c0:	0c002f2d */ 	jal	viGetViewTop
/*  f0e12c4:	8fb3009c */ 	lw	$s3,0x9c($sp)
/*  f0e12c8:	44829000 */ 	mtc1	$v0,$f18
/*  f0e12cc:	44905000 */ 	mtc1	$s0,$f10
/*  f0e12d0:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e12d4:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f0e12d8:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0e12dc:	46164182 */ 	mul.s	$f6,$f8,$f22
/*  f0e12e0:	00000000 */ 	nop
/*  f0e12e4:	46162482 */ 	mul.s	$f18,$f4,$f22
/*  f0e12e8:	4600340d */ 	trunc.w.s	$f16,$f6
/*  f0e12ec:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e12f0:	440d8000 */ 	mfc1	$t5,$f16
/*  f0e12f4:	440f4000 */ 	mfc1	$t7,$f8
/*  f0e12f8:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f0e12fc:	01c16025 */ 	or	$t4,$t6,$at
/*  f0e1300:	31e90fff */ 	andi	$t1,$t7,0xfff
/*  f0e1304:	0009c300 */ 	sll	$t8,$t1,0xc
/*  f0e1308:	01984025 */ 	or	$t0,$t4,$t8
/*  f0e130c:	0c002f0b */ 	jal	viGetViewWidth
/*  f0e1310:	ae680000 */ 	sw	$t0,0x0($s3)
/*  f0e1314:	0c002f29 */ 	jal	viGetViewLeft
/*  f0e1318:	a7a20092 */ 	sh	$v0,0x92($sp)
/*  f0e131c:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e1320:	00115c03 */ 	sra	$t3,$s1,0x10
/*  f0e1324:	0c002f2d */ 	jal	viGetViewTop
/*  f0e1328:	01608825 */ 	move	$s1,$t3
/*  f0e132c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e1330:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0e1334:	0c002f0f */ 	jal	viGetViewHeight
/*  f0e1338:	01408025 */ 	move	$s0,$t2
/*  f0e133c:	87a90092 */ 	lh	$t1,0x92($sp)
/*  f0e1340:	00506821 */ 	addu	$t5,$v0,$s0
/*  f0e1344:	448d3000 */ 	mtc1	$t5,$f6
/*  f0e1348:	02296021 */ 	addu	$t4,$s1,$t1
/*  f0e134c:	448c9000 */ 	mtc1	$t4,$f18
/*  f0e1350:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f0e1354:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f0e1358:	46168282 */ 	mul.s	$f10,$f16,$f22
/*  f0e135c:	00000000 */ 	nop
/*  f0e1360:	46164182 */ 	mul.s	$f6,$f8,$f22
/*  f0e1364:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0e1368:	4600340d */ 	trunc.w.s	$f16,$f6
/*  f0e136c:	44192000 */ 	mfc1	$t9,$f4
/*  f0e1370:	44088000 */ 	mfc1	$t0,$f16
/*  f0e1374:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f0e1378:	310b0fff */ 	andi	$t3,$t0,0xfff
/*  f0e137c:	000b5300 */ 	sll	$t2,$t3,0xc
/*  f0e1380:	01ea6825 */ 	or	$t5,$t7,$t2
/*  f0e1384:	ae6d0004 */ 	sw	$t5,0x4($s3)
.JF0f0e1388:
/*  f0e1388:	3c048007 */ 	lui	$a0,0x8007
/*  f0e138c:	8c841538 */ 	lw	$a0,0x1538($a0)
/*  f0e1390:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0e1394:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e1398:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0e139c:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e13a0:	00021080 */ 	sll	$v0,$v0,0x2
.JF0f0e13a4:
/*  f0e13a4:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f0e13a8:	25d901dc */ 	addiu	$t9,$t6,0x1dc
/*  f0e13ac:	0322082a */ 	slt	$at,$t9,$v0
/*  f0e13b0:	1420fd70 */ 	bnez	$at,.JF0f0e0974
/*  f0e13b4:	afb90088 */ 	sw	$t9,0x88($sp)
.JF0f0e13b8:
/*  f0e13b8:	8fa900e0 */ 	lw	$t1,0xe0($sp)
/*  f0e13bc:	3c0c800a */ 	lui	$t4,0x800a
/*  f0e13c0:	11200028 */ 	beqz	$t1,.JF0f0e1464
/*  f0e13c4:	00000000 */ 	nop
/*  f0e13c8:	8d8ca8b8 */ 	lw	$t4,-0x5748($t4)
/*  f0e13cc:	0fc547c2 */ 	jal	optionsGetShowMissionTime
/*  f0e13d0:	8d840070 */ 	lw	$a0,0x70($t4)
/*  f0e13d4:	10400019 */ 	beqz	$v0,.JF0f0e143c
/*  f0e13d8:	3c188007 */ 	lui	$t8,0x8007
/*  f0e13dc:	8f186350 */ 	lw	$t8,0x6350($t8)
/*  f0e13e0:	24030002 */ 	li	$v1,0x2
/*  f0e13e4:	3c08800a */ 	lui	$t0,0x800a
/*  f0e13e8:	14780014 */ 	bne	$v1,$t8,.JF0f0e143c
/*  f0e13ec:	00000000 */ 	nop
/*  f0e13f0:	8d08a948 */ 	lw	$t0,-0x56b8($t0)
/*  f0e13f4:	3c0b800a */ 	lui	$t3,0x800a
/*  f0e13f8:	15000010 */ 	bnez	$t0,.JF0f0e143c
/*  f0e13fc:	00000000 */ 	nop
/*  f0e1400:	8d6baae4 */ 	lw	$t3,-0x551c($t3)
/*  f0e1404:	24010026 */ 	li	$at,0x26
/*  f0e1408:	3c0f800a */ 	lui	$t7,0x800a
/*  f0e140c:	1161000b */ 	beq	$t3,$at,.JF0f0e143c
/*  f0e1410:	00000000 */ 	nop
/*  f0e1414:	8defa8b4 */ 	lw	$t7,-0x574c($t7)
/*  f0e1418:	24010001 */ 	li	$at,0x1
/*  f0e141c:	8de20000 */ 	lw	$v0,0x0($t7)
/*  f0e1420:	10620006 */ 	beq	$v1,$v0,.JF0f0e143c
/*  f0e1424:	00000000 */ 	nop
/*  f0e1428:	10410004 */ 	beq	$v0,$at,.JF0f0e143c
/*  f0e142c:	02402025 */ 	move	$a0,$s2
/*  f0e1430:	0fc377ed */ 	jal	hudmsgRenderMissionTimer
/*  f0e1434:	8fa500e0 */ 	lw	$a1,0xe0($sp)
/*  f0e1438:	00409025 */ 	move	$s2,$v0
.JF0f0e143c:
/*  f0e143c:	0fc3779f */ 	jal	hudmsgIsZoomRangeVisible
/*  f0e1440:	00000000 */ 	nop
/*  f0e1444:	10400004 */ 	beqz	$v0,.JF0f0e1458
/*  f0e1448:	02402025 */ 	move	$a0,$s2
/*  f0e144c:	0fc378db */ 	jal	hudmsgRenderZoomRange
/*  f0e1450:	8fa500e0 */ 	lw	$a1,0xe0($sp)
/*  f0e1454:	00409025 */ 	move	$s2,$v0
.JF0f0e1458:
/*  f0e1458:	0fc2458f */ 	jal	countdownTimerRender
/*  f0e145c:	02402025 */ 	move	$a0,$s2
/*  f0e1460:	00409025 */ 	move	$s2,$v0
.JF0f0e1464:
/*  f0e1464:	0fc54bb7 */ 	jal	text0f153780
/*  f0e1468:	02402025 */ 	move	$a0,$s2
/*  f0e146c:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f0e1470:	240a0001 */ 	li	$t2,0x1
/*  f0e1474:	3c018008 */ 	lui	$at,0x8008
/*  f0e1478:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f0e147c:	d7b60040 */ 	ldc1	$f22,0x40($sp)
/*  f0e1480:	d7b80048 */ 	ldc1	$f24,0x48($sp)
/*  f0e1484:	d7ba0050 */ 	ldc1	$f26,0x50($sp)
/*  f0e1488:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f0e148c:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f0e1490:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0e1494:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f0e1498:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f0e149c:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f0e14a0:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f0e14a4:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f0e14a8:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f0e14ac:	ac2a00f4 */ 	sw	$t2,0xf4($at)
/*  f0e14b0:	03e00008 */ 	jr	$ra
/*  f0e14b4:	27bd0100 */ 	addiu	$sp,$sp,0x100
);
#elif VERSION == VERSION_PAL_FINAL
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
/*  f0e0180:	0fc550cf */ 	jal	text0f153628
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
/*  f0e03cc:	0fc3074e */ 	jal	playerIsHealthVisible
/*  f0e03d0:	00000000 */ 	nop
/*  f0e03d4:	5040000d */ 	beqzl	$v0,.PF0f0e040c
/*  f0e03d8:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
/*  f0e03dc:	0fc30718 */ 	jal	playerGetHealthBarHeightFrac
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
/*  f0e0464:	0c002e46 */ 	jal	viGetBufHeight
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
/*  f0e0600:	0fc5524d */ 	jal	textSetDiagonalBlend
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
/*  f0e06cc:	0fc551d2 */ 	jal	text0f153a34
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
/*  f0e0740:	0fc552d8 */ 	jal	textResetBlends
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
/*  f0e085c:	0fc551d2 */ 	jal	text0f153a34
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
/*  f0e09ac:	0fc5524d */ 	jal	textSetDiagonalBlend
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
/*  f0e0ac4:	0fc551d2 */ 	jal	text0f153a34
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
/*  f0e0b38:	0fc552d8 */ 	jal	textResetBlends
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
/*  f0e0d0c:	0fc55125 */ 	jal	text0f153780
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
#elif VERSION == VERSION_PAL_BETA
GLOBAL_ASM(
glabel hudmsgsRender
.late_rodata
glabel var7f1af1c4
.word 0x41066667
glabel var7f1af1c8
.word 0x40490fdb
glabel var7f1af1cc
.word 0x7f0e097c
.word 0x7f0e097c
.word 0x7f0e097c
.word 0x7f0e0334
.word 0x7f0e058c
.word 0x7f0e0710
.text
/*  f0dff68:	27bdff00 */ 	addiu	$sp,$sp,-256
/*  f0dff6c:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f0dff70:	240e00ff */ 	li	$t6,0xff
/*  f0dff74:	240f0001 */ 	li	$t7,0x1
/*  f0dff78:	24180001 */ 	li	$t8,0x1
/*  f0dff7c:	3c018008 */ 	lui	$at,0x8008
/*  f0dff80:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f0dff84:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f0dff88:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f0dff8c:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f0dff90:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f0dff94:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f0dff98:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0dff9c:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f0dffa0:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f0dffa4:	f7ba0050 */ 	sdc1	$f26,0x50($sp)
/*  f0dffa8:	f7b80048 */ 	sdc1	$f24,0x48($sp)
/*  f0dffac:	f7b60040 */ 	sdc1	$f22,0x40($sp)
/*  f0dffb0:	f7b40038 */ 	sdc1	$f20,0x38($sp)
/*  f0dffb4:	afae00e0 */ 	sw	$t6,0xe0($sp)
/*  f0dffb8:	afaf00dc */ 	sw	$t7,0xdc($sp)
/*  f0dffbc:	0fc5528f */ 	jal	text0f153628
/*  f0dffc0:	ac381f90 */ 	sw	$t8,0x1f90($at)
/*  f0dffc4:	3c19800a */ 	lui	$t9,0x800a
/*  f0dffc8:	8f39e768 */ 	lw	$t9,-0x1898($t9)
/*  f0dffcc:	00409025 */ 	move	$s2,$v0
/*  f0dffd0:	3c048007 */ 	lui	$a0,0x8007
/*  f0dffd4:	07210005 */ 	bgez	$t9,.PB0f0dffec
/*  f0dffd8:	3c0141f0 */ 	lui	$at,0x41f0
/*  f0dffdc:	3c08800a */ 	lui	$t0,0x800a
/*  f0dffe0:	8d08e76c */ 	lw	$t0,-0x1894($t0)
/*  f0dffe4:	0500000e */ 	bltz	$t0,.PB0f0e0020
/*  f0dffe8:	00000000 */ 	nop
.PB0f0dffec:
/*  f0dffec:	3c098007 */ 	lui	$t1,0x8007
/*  f0dfff0:	8d292434 */ 	lw	$t1,0x2434($t1)
/*  f0dfff4:	1120000a */ 	beqz	$t1,.PB0f0e0020
/*  f0dfff8:	00000000 */ 	nop
/*  f0dfffc:	3c0a8006 */ 	lui	$t2,0x8006
/*  f0e0000:	8d4ae4e0 */ 	lw	$t2,-0x1b20($t2)
/*  f0e0004:	15400006 */ 	bnez	$t2,.PB0f0e0020
/*  f0e0008:	00000000 */ 	nop
/*  f0e000c:	3c0b800a */ 	lui	$t3,0x800a
/*  f0e0010:	8d6be75c */ 	lw	$t3,-0x18a4($t3)
/*  f0e0014:	15600002 */ 	bnez	$t3,.PB0f0e0020
/*  f0e0018:	00000000 */ 	nop
/*  f0e001c:	afa000dc */ 	sw	$zero,0xdc($sp)
.PB0f0e0020:
/*  f0e0020:	8c842cb8 */ 	lw	$a0,0x2cb8($a0)
/*  f0e0024:	27b700e4 */ 	addiu	$s7,$sp,0xe4
/*  f0e0028:	27b600e8 */ 	addiu	$s6,$sp,0xe8
/*  f0e002c:	1880029b */ 	blez	$a0,.PB0f0e0a9c
/*  f0e0030:	2415ff00 */ 	li	$s5,-256
/*  f0e0034:	4481d000 */ 	mtc1	$at,$f26
/*  f0e0038:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0e003c:	c438fc14 */ 	lwc1	$f24,-0x3ec($at)
/*  f0e0040:	3c014080 */ 	lui	$at,0x4080
/*  f0e0044:	4481b000 */ 	mtc1	$at,$f22
/*  f0e0048:	3c013f80 */ 	lui	$at,0x3f80
/*  f0e004c:	4481a000 */ 	mtc1	$at,$f20
/*  f0e0050:	afa00088 */ 	sw	$zero,0x88($sp)
/*  f0e0054:	241e00ff */ 	li	$s8,0xff
.PB0f0e0058:
/*  f0e0058:	3c0d8007 */ 	lui	$t5,0x8007
/*  f0e005c:	8dad2cbc */ 	lw	$t5,0x2cbc($t5)
/*  f0e0060:	8fac0088 */ 	lw	$t4,0x88($sp)
/*  f0e0064:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0e0068:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e006c:	018d8021 */ 	addu	$s0,$t4,$t5
/*  f0e0070:	92030004 */ 	lbu	$v1,0x4($s0)
/*  f0e0074:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0e0078:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e007c:	54600004 */ 	bnezl	$v1,.PB0f0e0090
/*  f0e0080:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f0e0084:	10000280 */ 	b	.PB0f0e0a88
/*  f0e0088:	00021080 */ 	sll	$v0,$v0,0x2
/*  f0e008c:	92020000 */ 	lbu	$v0,0x0($s0)
.PB0f0e0090:
/*  f0e0090:	24010001 */ 	li	$at,0x1
/*  f0e0094:	5040000a */ 	beqzl	$v0,.PB0f0e00c0
/*  f0e0098:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0e009c:	10410007 */ 	beq	$v0,$at,.PB0f0e00bc
/*  f0e00a0:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f0e00a4:	51c0000c */ 	beqzl	$t6,.PB0f0e00d8
/*  f0e00a8:	92190003 */ 	lbu	$t9,0x3($s0)
/*  f0e00ac:	3c0f800a */ 	lui	$t7,0x800a
/*  f0e00b0:	8defe75c */ 	lw	$t7,-0x18a4($t7)
/*  f0e00b4:	8e1801c0 */ 	lw	$t8,0x1c0($s0)
/*  f0e00b8:	11f80006 */ 	beq	$t7,$t8,.PB0f0e00d4
.PB0f0e00bc:
/*  f0e00bc:	00041100 */ 	sll	$v0,$a0,0x4
.PB0f0e00c0:
/*  f0e00c0:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e00c4:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0e00c8:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e00cc:	1000026e */ 	b	.PB0f0e0a88
/*  f0e00d0:	00021080 */ 	sll	$v0,$v0,0x2
.PB0f0e00d4:
/*  f0e00d4:	92190003 */ 	lbu	$t9,0x3($s0)
.PB0f0e00d8:
/*  f0e00d8:	53200022 */ 	beqzl	$t9,.PB0f0e0164
/*  f0e00dc:	8e130010 */ 	lw	$s3,0x10($s0)
/*  f0e00e0:	96080006 */ 	lhu	$t0,0x6($s0)
/*  f0e00e4:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e00e8:	44882000 */ 	mtc1	$t0,$f4
/*  f0e00ec:	05010004 */ 	bgez	$t0,.PB0f0e0100
/*  f0e00f0:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e00f4:	44814000 */ 	mtc1	$at,$f8
/*  f0e00f8:	00000000 */ 	nop
/*  f0e00fc:	46083180 */ 	add.s	$f6,$f6,$f8
.PB0f0e0100:
/*  f0e0100:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0e0104:	c42afc18 */ 	lwc1	$f10,-0x3e8($at)
/*  f0e0108:	3c014270 */ 	lui	$at,0x4270
/*  f0e010c:	44819000 */ 	mtc1	$at,$f18
/*  f0e0110:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0e0114:	0c006b8b */ 	jal	sinf
/*  f0e0118:	46128303 */ 	div.s	$f12,$f16,$f18
/*  f0e011c:	44802000 */ 	mtc1	$zero,$f4
/*  f0e0120:	3c014340 */ 	lui	$at,0x4340
/*  f0e0124:	44814000 */ 	mtc1	$at,$f8
/*  f0e0128:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0e012c:	46000086 */ 	mov.s	$f2,$f0
/*  f0e0130:	45000002 */ 	bc1f	.PB0f0e013c
/*  f0e0134:	00000000 */ 	nop
/*  f0e0138:	46000087 */ 	neg.s	$f2,$f0
.PB0f0e013c:
/*  f0e013c:	46024182 */ 	mul.s	$f6,$f8,$f2
/*  f0e0140:	8e090010 */ 	lw	$t1,0x10($s0)
/*  f0e0144:	8e140014 */ 	lw	$s4,0x14($s0)
/*  f0e0148:	92030004 */ 	lbu	$v1,0x4($s0)
/*  f0e014c:	01355024 */ 	and	$t2,$t1,$s5
/*  f0e0150:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f0e0154:	440c5000 */ 	mfc1	$t4,$f10
/*  f0e0158:	10000005 */ 	b	.PB0f0e0170
/*  f0e015c:	014c9821 */ 	addu	$s3,$t2,$t4
/*  f0e0160:	8e130010 */ 	lw	$s3,0x10($s0)
.PB0f0e0164:
/*  f0e0164:	8e140014 */ 	lw	$s4,0x14($s0)
/*  f0e0168:	366d00a0 */ 	ori	$t5,$s3,0xa0
/*  f0e016c:	01a09825 */ 	move	$s3,$t5
.PB0f0e0170:
/*  f0e0170:	240100ff */ 	li	$at,0xff
/*  f0e0174:	1061001c */ 	beq	$v1,$at,.PB0f0e01e8
/*  f0e0178:	00601025 */ 	move	$v0,$v1
/*  f0e017c:	326e00ff */ 	andi	$t6,$s3,0xff
/*  f0e0180:	004e0019 */ 	multu	$v0,$t6
/*  f0e0184:	00401825 */ 	move	$v1,$v0
/*  f0e0188:	329800ff */ 	andi	$t8,$s4,0xff
/*  f0e018c:	02754024 */ 	and	$t0,$s3,$s5
/*  f0e0190:	02955824 */ 	and	$t3,$s4,$s5
/*  f0e0194:	00007812 */ 	mflo	$t7
/*  f0e0198:	00000000 */ 	nop
/*  f0e019c:	00000000 */ 	nop
/*  f0e01a0:	01fe001b */ 	divu	$zero,$t7,$s8
/*  f0e01a4:	00002012 */ 	mflo	$a0
/*  f0e01a8:	308900ff */ 	andi	$t1,$a0,0xff
/*  f0e01ac:	17c00002 */ 	bnez	$s8,.PB0f0e01b8
/*  f0e01b0:	00000000 */ 	nop
/*  f0e01b4:	0007000d */ 	break	0x7
.PB0f0e01b8:
/*  f0e01b8:	00780019 */ 	multu	$v1,$t8
/*  f0e01bc:	01099821 */ 	addu	$s3,$t0,$t1
/*  f0e01c0:	0000c812 */ 	mflo	$t9
/*  f0e01c4:	00000000 */ 	nop
/*  f0e01c8:	00000000 */ 	nop
/*  f0e01cc:	033e001b */ 	divu	$zero,$t9,$s8
/*  f0e01d0:	00002812 */ 	mflo	$a1
/*  f0e01d4:	30aa00ff */ 	andi	$t2,$a1,0xff
/*  f0e01d8:	17c00002 */ 	bnez	$s8,.PB0f0e01e4
/*  f0e01dc:	00000000 */ 	nop
/*  f0e01e0:	0007000d */ 	break	0x7
.PB0f0e01e4:
/*  f0e01e4:	016aa021 */ 	addu	$s4,$t3,$t2
.PB0f0e01e8:
/*  f0e01e8:	960c0018 */ 	lhu	$t4,0x18($s0)
/*  f0e01ec:	24010006 */ 	li	$at,0x6
/*  f0e01f0:	afac00e8 */ 	sw	$t4,0xe8($sp)
/*  f0e01f4:	960d001a */ 	lhu	$t5,0x1a($s0)
/*  f0e01f8:	afad00e4 */ 	sw	$t5,0xe4($sp)
/*  f0e01fc:	8e0e01b4 */ 	lw	$t6,0x1b4($s0)
/*  f0e0200:	55c10011 */ 	bnel	$t6,$at,.PB0f0e0248
/*  f0e0204:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
/*  f0e0208:	0fc30711 */ 	jal	playerIsHealthVisible
/*  f0e020c:	00000000 */ 	nop
/*  f0e0210:	5040000d */ 	beqzl	$v0,.PB0f0e0248
/*  f0e0214:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
/*  f0e0218:	0fc306db */ 	jal	playerGetHealthBarHeightFrac
/*  f0e021c:	00000000 */ 	nop
/*  f0e0220:	3c014180 */ 	lui	$at,0x4180
/*  f0e0224:	44818000 */ 	mtc1	$at,$f16
/*  f0e0228:	8faf00e4 */ 	lw	$t7,0xe4($sp)
/*  f0e022c:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0e0230:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e0234:	44192000 */ 	mfc1	$t9,$f4
/*  f0e0238:	00000000 */ 	nop
/*  f0e023c:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f0e0240:	afa800e4 */ 	sw	$t0,0xe4($sp)
/*  f0e0244:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
.PB0f0e0248:
/*  f0e0248:	2401000b */ 	li	$at,0xb
/*  f0e024c:	55210031 */ 	bnel	$t1,$at,.PB0f0e0314
/*  f0e0250:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f0e0254:	8fab00e8 */ 	lw	$t3,0xe8($sp)
/*  f0e0258:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0e025c:	8d8c1f90 */ 	lw	$t4,0x1f90($t4)
/*  f0e0260:	256afffc */ 	addiu	$t2,$t3,-4
/*  f0e0264:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e0268:	014c0019 */ 	multu	$t2,$t4
/*  f0e026c:	02408825 */ 	move	$s1,$s2
/*  f0e0270:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e0274:	00006812 */ 	mflo	$t5
/*  f0e0278:	448d4000 */ 	mtc1	$t5,$f8
/*  f0e027c:	00000000 */ 	nop
/*  f0e0280:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0e0284:	46163282 */ 	mul.s	$f10,$f6,$f22
/*  f0e0288:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e028c:	44188000 */ 	mfc1	$t8,$f16
/*  f0e0290:	00000000 */ 	nop
/*  f0e0294:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f0e0298:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f0e029c:	03214025 */ 	or	$t0,$t9,$at
/*  f0e02a0:	0c002e40 */ 	jal	viGetBufHeight
/*  f0e02a4:	ae280000 */ 	sw	$t0,0x0($s1)
/*  f0e02a8:	8fa900e8 */ 	lw	$t1,0xe8($sp)
/*  f0e02ac:	960b001c */ 	lhu	$t3,0x1c($s0)
/*  f0e02b0:	3c0d8008 */ 	lui	$t5,0x8008
/*  f0e02b4:	8dad1f90 */ 	lw	$t5,0x1f90($t5)
/*  f0e02b8:	012b5021 */ 	addu	$t2,$t1,$t3
/*  f0e02bc:	254c0003 */ 	addiu	$t4,$t2,0x3
/*  f0e02c0:	018d0019 */ 	multu	$t4,$t5
/*  f0e02c4:	44825000 */ 	mtc1	$v0,$f10
/*  f0e02c8:	00000000 */ 	nop
/*  f0e02cc:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0e02d0:	00007012 */ 	mflo	$t6
/*  f0e02d4:	448e9000 */ 	mtc1	$t6,$f18
/*  f0e02d8:	00000000 */ 	nop
/*  f0e02dc:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0e02e0:	46162202 */ 	mul.s	$f8,$f4,$f22
/*  f0e02e4:	00000000 */ 	nop
/*  f0e02e8:	46168482 */ 	mul.s	$f18,$f16,$f22
/*  f0e02ec:	4600418d */ 	trunc.w.s	$f6,$f8
/*  f0e02f0:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e02f4:	440f3000 */ 	mfc1	$t7,$f6
/*  f0e02f8:	440b2000 */ 	mfc1	$t3,$f4
/*  f0e02fc:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f0e0300:	00194300 */ 	sll	$t0,$t9,0xc
/*  f0e0304:	316a0fff */ 	andi	$t2,$t3,0xfff
/*  f0e0308:	01486025 */ 	or	$t4,$t2,$t0
/*  f0e030c:	ae2c0004 */ 	sw	$t4,0x4($s1)
/*  f0e0310:	920d0000 */ 	lbu	$t5,0x0($s0)
.PB0f0e0314:
/*  f0e0314:	2da10006 */ 	sltiu	$at,$t5,0x6
/*  f0e0318:	10200198 */ 	beqz	$at,.PB0f0e097c
/*  f0e031c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0e0320:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0e0324:	002d0821 */ 	addu	$at,$at,$t5
/*  f0e0328:	8c2dfc1c */ 	lw	$t5,-0x3e4($at)
/*  f0e032c:	01a00008 */ 	jr	$t5
/*  f0e0330:	00000000 */ 	nop
/*  f0e0334:	8e110010 */ 	lw	$s1,0x10($s0)
/*  f0e0338:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0e033c:	240100ff */ 	li	$at,0xff
/*  f0e0340:	362e0040 */ 	ori	$t6,$s1,0x40
/*  f0e0344:	1041000e */ 	beq	$v0,$at,.PB0f0e0380
/*  f0e0348:	01c08825 */ 	move	$s1,$t6
/*  f0e034c:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f0e0350:	00580019 */ 	multu	$v0,$t8
/*  f0e0354:	0235c824 */ 	and	$t9,$s1,$s5
/*  f0e0358:	00007812 */ 	mflo	$t7
/*  f0e035c:	00000000 */ 	nop
/*  f0e0360:	00000000 */ 	nop
/*  f0e0364:	01fe001b */ 	divu	$zero,$t7,$s8
/*  f0e0368:	00001812 */ 	mflo	$v1
/*  f0e036c:	306900ff */ 	andi	$t1,$v1,0xff
/*  f0e0370:	17c00002 */ 	bnez	$s8,.PB0f0e037c
/*  f0e0374:	00000000 */ 	nop
/*  f0e0378:	0007000d */ 	break	0x7
.PB0f0e037c:
/*  f0e037c:	03298821 */ 	addu	$s1,$t9,$t1
.PB0f0e0380:
/*  f0e0380:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0e0384:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0e0388:	00420019 */ 	multu	$v0,$v0
/*  f0e038c:	00005812 */ 	mflo	$t3
/*  f0e0390:	00000000 */ 	nop
/*  f0e0394:	00000000 */ 	nop
/*  f0e0398:	00630019 */ 	multu	$v1,$v1
/*  f0e039c:	00005012 */ 	mflo	$t2
/*  f0e03a0:	016a4021 */ 	addu	$t0,$t3,$t2
/*  f0e03a4:	44884000 */ 	mtc1	$t0,$f8
/*  f0e03a8:	0c012ae4 */ 	jal	sqrtf
/*  f0e03ac:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f0e03b0:	3c014304 */ 	lui	$at,0x4304
/*  f0e03b4:	44813000 */ 	mtc1	$at,$f6
/*  f0e03b8:	44802000 */ 	mtc1	$zero,$f4
/*  f0e03bc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e03c0:	46060280 */ 	add.s	$f10,$f0,$f6
/*  f0e03c4:	46185083 */ 	div.s	$f2,$f10,$f24
/*  f0e03c8:	4602d03c */ 	c.lt.s	$f26,$f2
/*  f0e03cc:	00000000 */ 	nop
/*  f0e03d0:	45020003 */ 	bc1fl	.PB0f0e03e0
/*  f0e03d4:	960c0006 */ 	lhu	$t4,0x6($s0)
/*  f0e03d8:	4600d086 */ 	mov.s	$f2,$f26
/*  f0e03dc:	960c0006 */ 	lhu	$t4,0x6($s0)
.PB0f0e03e0:
/*  f0e03e0:	448c8000 */ 	mtc1	$t4,$f16
/*  f0e03e4:	05810004 */ 	bgez	$t4,.PB0f0e03f8
/*  f0e03e8:	46808320 */ 	cvt.s.w	$f12,$f16
/*  f0e03ec:	44819000 */ 	mtc1	$at,$f18
/*  f0e03f0:	00000000 */ 	nop
/*  f0e03f4:	46126300 */ 	add.s	$f12,$f12,$f18
.PB0f0e03f8:
/*  f0e03f8:	46026083 */ 	div.s	$f2,$f12,$f2
/*  f0e03fc:	8fa400e8 */ 	lw	$a0,0xe8($sp)
/*  f0e0400:	8fa500e4 */ 	lw	$a1,0xe4($sp)
/*  f0e0404:	00003825 */ 	move	$a3,$zero
/*  f0e0408:	46186002 */ 	mul.s	$f0,$f12,$f24
/*  f0e040c:	44060000 */ 	mfc1	$a2,$f0
/*  f0e0410:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f0e0414:	00000000 */ 	nop
/*  f0e0418:	45020003 */ 	bc1fl	.PB0f0e0428
/*  f0e041c:	4604103c */ 	c.lt.s	$f2,$f4
/*  f0e0420:	4600a086 */ 	mov.s	$f2,$f20
/*  f0e0424:	4604103c */ 	c.lt.s	$f2,$f4
.PB0f0e0428:
/*  f0e0428:	00000000 */ 	nop
/*  f0e042c:	45000003 */ 	bc1f	.PB0f0e043c
/*  f0e0430:	00000000 */ 	nop
/*  f0e0434:	44801000 */ 	mtc1	$zero,$f2
/*  f0e0438:	00000000 */ 	nop
.PB0f0e043c:
/*  f0e043c:	0fc5540d */ 	jal	textSetDiagonalBlend
/*  f0e0440:	e7a200c0 */ 	swc1	$f2,0xc0($sp)
/*  f0e0444:	920d0001 */ 	lbu	$t5,0x1($s0)
/*  f0e0448:	c7a200c0 */ 	lwc1	$f2,0xc0($sp)
/*  f0e044c:	02402025 */ 	move	$a0,$s2
/*  f0e0450:	11a00027 */ 	beqz	$t5,.PB0f0e04f0
/*  f0e0454:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0e0458:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0e045c:	9619001e */ 	lhu	$t9,0x1e($s0)
/*  f0e0460:	8fae00e8 */ 	lw	$t6,0xe8($sp)
/*  f0e0464:	960f001c */ 	lhu	$t7,0x1c($s0)
/*  f0e0468:	03384821 */ 	addu	$t1,$t9,$t8
/*  f0e046c:	252b0002 */ 	addiu	$t3,$t1,0x2
/*  f0e0470:	01ee3821 */ 	addu	$a3,$t7,$t6
/*  f0e0474:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f0e0478:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e047c:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f0e0480:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e0484:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0e0488:	02402025 */ 	move	$a0,$s2
/*  f0e048c:	2706fffd */ 	addiu	$a2,$t8,-3
/*  f0e0490:	0fc37736 */ 	jal	hudmsgRenderBox
/*  f0e0494:	25c5fffd */ 	addiu	$a1,$t6,-3
/*  f0e0498:	0c002e4d */ 	jal	viGetWidth
/*  f0e049c:	00409025 */ 	move	$s2,$v0
/*  f0e04a0:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e04a4:	00115403 */ 	sra	$t2,$s1,0x10
/*  f0e04a8:	0c002e51 */ 	jal	viGetHeight
/*  f0e04ac:	01408825 */ 	move	$s1,$t2
/*  f0e04b0:	8e080008 */ 	lw	$t0,0x8($s0)
/*  f0e04b4:	02402025 */ 	move	$a0,$s2
/*  f0e04b8:	02c02825 */ 	move	$a1,$s6
/*  f0e04bc:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f0e04c0:	8e0c000c */ 	lw	$t4,0xc($s0)
/*  f0e04c4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e04c8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e04cc:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e04d0:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e04d4:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e04d8:	02e03025 */ 	move	$a2,$s7
/*  f0e04dc:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e04e0:	0fc55e10 */ 	jal	textRenderProjected
/*  f0e04e4:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e04e8:	1000001f */ 	b	.PB0f0e0568
/*  f0e04ec:	00409025 */ 	move	$s2,$v0
.PB0f0e04f0:
/*  f0e04f0:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f0e04f4:	9619001e */ 	lhu	$t9,0x1e($s0)
/*  f0e04f8:	960e001c */ 	lhu	$t6,0x1c($s0)
/*  f0e04fc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e0500:	0326c021 */ 	addu	$t8,$t9,$a2
/*  f0e0504:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e0508:	0fc55392 */ 	jal	text0f153a34
/*  f0e050c:	01c53821 */ 	addu	$a3,$t6,$a1
/*  f0e0510:	0c002e4d */ 	jal	viGetWidth
/*  f0e0514:	00409025 */ 	move	$s2,$v0
/*  f0e0518:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e051c:	00114c03 */ 	sra	$t1,$s1,0x10
/*  f0e0520:	0c002e51 */ 	jal	viGetHeight
/*  f0e0524:	01208825 */ 	move	$s1,$t1
/*  f0e0528:	8e0b0008 */ 	lw	$t3,0x8($s0)
/*  f0e052c:	02402025 */ 	move	$a0,$s2
/*  f0e0530:	02c02825 */ 	move	$a1,$s6
/*  f0e0534:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e0538:	8e0a000c */ 	lw	$t2,0xc($s0)
/*  f0e053c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0e0540:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e0544:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0e0548:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0e054c:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f0e0550:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e0554:	02e03025 */ 	move	$a2,$s7
/*  f0e0558:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e055c:	0fc56160 */ 	jal	textRender
/*  f0e0560:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0e0564:	00409025 */ 	move	$s2,$v0
.PB0f0e0568:
/*  f0e0568:	920801c9 */ 	lbu	$t0,0x1c9($s0)
/*  f0e056c:	24010006 */ 	li	$at,0x6
/*  f0e0570:	15010002 */ 	bne	$t0,$at,.PB0f0e057c
/*  f0e0574:	00000000 */ 	nop
/*  f0e0578:	afa000e0 */ 	sw	$zero,0xe0($sp)
.PB0f0e057c:
/*  f0e057c:	0fc55498 */ 	jal	textResetBlends
/*  f0e0580:	00000000 */ 	nop
/*  f0e0584:	100000fe */ 	b	.PB0f0e0980
/*  f0e0588:	8e0801b4 */ 	lw	$t0,0x1b4($s0)
/*  f0e058c:	920c0001 */ 	lbu	$t4,0x1($s0)
/*  f0e0590:	8fa900e8 */ 	lw	$t1,0xe8($sp)
/*  f0e0594:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f0e0598:	11800037 */ 	beqz	$t4,.PB0f0e0678
/*  f0e059c:	2525fffd */ 	addiu	$a1,$t1,-3
/*  f0e05a0:	8e030010 */ 	lw	$v1,0x10($s0)
/*  f0e05a4:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0e05a8:	240100ff */ 	li	$at,0xff
/*  f0e05ac:	346e0040 */ 	ori	$t6,$v1,0x40
/*  f0e05b0:	1041000e */ 	beq	$v0,$at,.PB0f0e05ec
/*  f0e05b4:	01c01825 */ 	move	$v1,$t6
/*  f0e05b8:	31cd00ff */ 	andi	$t5,$t6,0xff
/*  f0e05bc:	004d0019 */ 	multu	$v0,$t5
/*  f0e05c0:	00757824 */ 	and	$t7,$v1,$s5
/*  f0e05c4:	0000c812 */ 	mflo	$t9
/*  f0e05c8:	00000000 */ 	nop
/*  f0e05cc:	00000000 */ 	nop
/*  f0e05d0:	033e001b */ 	divu	$zero,$t9,$s8
/*  f0e05d4:	00002012 */ 	mflo	$a0
/*  f0e05d8:	309800ff */ 	andi	$t8,$a0,0xff
/*  f0e05dc:	17c00002 */ 	bnez	$s8,.PB0f0e05e8
/*  f0e05e0:	00000000 */ 	nop
/*  f0e05e4:	0007000d */ 	break	0x7
.PB0f0e05e8:
/*  f0e05e8:	01f81821 */ 	addu	$v1,$t7,$t8
.PB0f0e05ec:
/*  f0e05ec:	9608001e */ 	lhu	$t0,0x1e($s0)
/*  f0e05f0:	960a001c */ 	lhu	$t2,0x1c($s0)
/*  f0e05f4:	e7b4001c */ 	swc1	$f20,0x1c($sp)
/*  f0e05f8:	010b6021 */ 	addu	$t4,$t0,$t3
/*  f0e05fc:	258e0002 */ 	addiu	$t6,$t4,0x2
/*  f0e0600:	01493821 */ 	addu	$a3,$t2,$t1
/*  f0e0604:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f0e0608:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e060c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e0610:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0e0614:	02402025 */ 	move	$a0,$s2
/*  f0e0618:	0fc37736 */ 	jal	hudmsgRenderBox
/*  f0e061c:	2566fffd */ 	addiu	$a2,$t3,-3
/*  f0e0620:	0c002e4d */ 	jal	viGetWidth
/*  f0e0624:	00409025 */ 	move	$s2,$v0
/*  f0e0628:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e062c:	00116c03 */ 	sra	$t5,$s1,0x10
/*  f0e0630:	0c002e51 */ 	jal	viGetHeight
/*  f0e0634:	01a08825 */ 	move	$s1,$t5
/*  f0e0638:	8e190008 */ 	lw	$t9,0x8($s0)
/*  f0e063c:	02402025 */ 	move	$a0,$s2
/*  f0e0640:	02c02825 */ 	move	$a1,$s6
/*  f0e0644:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e0648:	8e0f000c */ 	lw	$t7,0xc($s0)
/*  f0e064c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e0650:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e0654:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e0658:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e065c:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e0660:	02e03025 */ 	move	$a2,$s7
/*  f0e0664:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e0668:	0fc55e10 */ 	jal	textRenderProjected
/*  f0e066c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e0670:	10000021 */ 	b	.PB0f0e06f8
/*  f0e0674:	00409025 */ 	move	$s2,$v0
.PB0f0e0678:
/*  f0e0678:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f0e067c:	9608001e */ 	lhu	$t0,0x1e($s0)
/*  f0e0680:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0e0684:	9609001c */ 	lhu	$t1,0x1c($s0)
/*  f0e0688:	01065821 */ 	addu	$t3,$t0,$a2
/*  f0e068c:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e0690:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e0694:	02402025 */ 	move	$a0,$s2
/*  f0e0698:	0fc55392 */ 	jal	text0f153a34
/*  f0e069c:	01253821 */ 	addu	$a3,$t1,$a1
/*  f0e06a0:	0c002e4d */ 	jal	viGetWidth
/*  f0e06a4:	00409025 */ 	move	$s2,$v0
/*  f0e06a8:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e06ac:	00116403 */ 	sra	$t4,$s1,0x10
/*  f0e06b0:	0c002e51 */ 	jal	viGetHeight
/*  f0e06b4:	01808825 */ 	move	$s1,$t4
/*  f0e06b8:	8e0e0008 */ 	lw	$t6,0x8($s0)
/*  f0e06bc:	02402025 */ 	move	$a0,$s2
/*  f0e06c0:	02c02825 */ 	move	$a1,$s6
/*  f0e06c4:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e06c8:	8e0d000c */ 	lw	$t5,0xc($s0)
/*  f0e06cc:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0e06d0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e06d4:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0e06d8:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0e06dc:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f0e06e0:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e06e4:	02e03025 */ 	move	$a2,$s7
/*  f0e06e8:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e06ec:	0fc56160 */ 	jal	textRender
/*  f0e06f0:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e06f4:	00409025 */ 	move	$s2,$v0
.PB0f0e06f8:
/*  f0e06f8:	921901c9 */ 	lbu	$t9,0x1c9($s0)
/*  f0e06fc:	24010006 */ 	li	$at,0x6
/*  f0e0700:	5721009f */ 	bnel	$t9,$at,.PB0f0e0980
/*  f0e0704:	8e0801b4 */ 	lw	$t0,0x1b4($s0)
/*  f0e0708:	1000009c */ 	b	.PB0f0e097c
/*  f0e070c:	afa000e0 */ 	sw	$zero,0xe0($sp)
/*  f0e0710:	9602001c */ 	lhu	$v0,0x1c($s0)
/*  f0e0714:	9603001e */ 	lhu	$v1,0x1e($s0)
/*  f0e0718:	00420019 */ 	multu	$v0,$v0
/*  f0e071c:	00007812 */ 	mflo	$t7
/*  f0e0720:	00000000 */ 	nop
/*  f0e0724:	00000000 */ 	nop
/*  f0e0728:	00630019 */ 	multu	$v1,$v1
/*  f0e072c:	00004812 */ 	mflo	$t1
/*  f0e0730:	01e9c021 */ 	addu	$t8,$t7,$t1
/*  f0e0734:	44984000 */ 	mtc1	$t8,$f8
/*  f0e0738:	0c012ae4 */ 	jal	sqrtf
/*  f0e073c:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f0e0740:	3c0142b8 */ 	lui	$at,0x42b8
/*  f0e0744:	44813000 */ 	mtc1	$at,$f6
/*  f0e0748:	8e110010 */ 	lw	$s1,0x10($s0)
/*  f0e074c:	92020004 */ 	lbu	$v0,0x4($s0)
/*  f0e0750:	46060280 */ 	add.s	$f10,$f0,$f6
/*  f0e0754:	240100ff */ 	li	$at,0xff
/*  f0e0758:	36280040 */ 	ori	$t0,$s1,0x40
/*  f0e075c:	01008825 */ 	move	$s1,$t0
/*  f0e0760:	1041000e */ 	beq	$v0,$at,.PB0f0e079c
/*  f0e0764:	46185083 */ 	div.s	$f2,$f10,$f24
/*  f0e0768:	310a00ff */ 	andi	$t2,$t0,0xff
/*  f0e076c:	004a0019 */ 	multu	$v0,$t2
/*  f0e0770:	02356024 */ 	and	$t4,$s1,$s5
/*  f0e0774:	00005812 */ 	mflo	$t3
/*  f0e0778:	00000000 */ 	nop
/*  f0e077c:	00000000 */ 	nop
/*  f0e0780:	017e001b */ 	divu	$zero,$t3,$s8
/*  f0e0784:	00001812 */ 	mflo	$v1
/*  f0e0788:	306e00ff */ 	andi	$t6,$v1,0xff
/*  f0e078c:	17c00002 */ 	bnez	$s8,.PB0f0e0798
/*  f0e0790:	00000000 */ 	nop
/*  f0e0794:	0007000d */ 	break	0x7
.PB0f0e0798:
/*  f0e0798:	018e8821 */ 	addu	$s1,$t4,$t6
.PB0f0e079c:
/*  f0e079c:	960d0006 */ 	lhu	$t5,0x6($s0)
/*  f0e07a0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e07a4:	448d8000 */ 	mtc1	$t5,$f16
/*  f0e07a8:	05a10004 */ 	bgez	$t5,.PB0f0e07bc
/*  f0e07ac:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0e07b0:	44812000 */ 	mtc1	$at,$f4
/*  f0e07b4:	00000000 */ 	nop
/*  f0e07b8:	46049480 */ 	add.s	$f18,$f18,$f4
.PB0f0e07bc:
/*  f0e07bc:	46121201 */ 	sub.s	$f8,$f2,$f18
/*  f0e07c0:	9619001c */ 	lhu	$t9,0x1c($s0)
/*  f0e07c4:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f0e07c8:	9609001e */ 	lhu	$t1,0x1e($s0)
/*  f0e07cc:	46184002 */ 	mul.s	$f0,$f8,$f24
/*  f0e07d0:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f0e07d4:	e7a200a8 */ 	swc1	$f2,0xa8($sp)
/*  f0e07d8:	24070002 */ 	li	$a3,0x2
/*  f0e07dc:	032f2021 */ 	addu	$a0,$t9,$t7
/*  f0e07e0:	01382821 */ 	addu	$a1,$t1,$t8
/*  f0e07e4:	44060000 */ 	mfc1	$a2,$f0
/*  f0e07e8:	0fc5540d */ 	jal	textSetDiagonalBlend
/*  f0e07ec:	00000000 */ 	nop
/*  f0e07f0:	c7a200a8 */ 	lwc1	$f2,0xa8($sp)
/*  f0e07f4:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e07f8:	8fab00e8 */ 	lw	$t3,0xe8($sp)
/*  f0e07fc:	4602d03c */ 	c.lt.s	$f26,$f2
/*  f0e0800:	8fac00e4 */ 	lw	$t4,0xe4($sp)
/*  f0e0804:	02402025 */ 	move	$a0,$s2
/*  f0e0808:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0e080c:	45000002 */ 	bc1f	.PB0f0e0818
/*  f0e0810:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f0e0814:	4600d086 */ 	mov.s	$f2,$f26
.PB0f0e0818:
/*  f0e0818:	96080006 */ 	lhu	$t0,0x6($s0)
/*  f0e081c:	44883000 */ 	mtc1	$t0,$f6
/*  f0e0820:	05010004 */ 	bgez	$t0,.PB0f0e0834
/*  f0e0824:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0e0828:	44818000 */ 	mtc1	$at,$f16
/*  f0e082c:	00000000 */ 	nop
/*  f0e0830:	46105280 */ 	add.s	$f10,$f10,$f16
.PB0f0e0834:
/*  f0e0834:	46025083 */ 	div.s	$f2,$f10,$f2
/*  f0e0838:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f0e083c:	00000000 */ 	nop
/*  f0e0840:	45020003 */ 	bc1fl	.PB0f0e0850
/*  f0e0844:	920a0001 */ 	lbu	$t2,0x1($s0)
/*  f0e0848:	4600a086 */ 	mov.s	$f2,$f20
/*  f0e084c:	920a0001 */ 	lbu	$t2,0x1($s0)
.PB0f0e0850:
/*  f0e0850:	51400027 */ 	beqzl	$t2,.PB0f0e08f0
/*  f0e0854:	960d001e */ 	lhu	$t5,0x1e($s0)
/*  f0e0858:	960d001e */ 	lhu	$t5,0x1e($s0)
/*  f0e085c:	960e001c */ 	lhu	$t6,0x1c($s0)
/*  f0e0860:	4602a101 */ 	sub.s	$f4,$f20,$f2
/*  f0e0864:	01acc821 */ 	addu	$t9,$t5,$t4
/*  f0e0868:	272f0002 */ 	addiu	$t7,$t9,0x2
/*  f0e086c:	01cb3821 */ 	addu	$a3,$t6,$t3
/*  f0e0870:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f0e0874:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e0878:	e7a4001c */ 	swc1	$f4,0x1c($sp)
/*  f0e087c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e0880:	e7b40014 */ 	swc1	$f20,0x14($sp)
/*  f0e0884:	02402025 */ 	move	$a0,$s2
/*  f0e0888:	2565fffd */ 	addiu	$a1,$t3,-3
/*  f0e088c:	0fc37736 */ 	jal	hudmsgRenderBox
/*  f0e0890:	2586fffd */ 	addiu	$a2,$t4,-3
/*  f0e0894:	0c002e4d */ 	jal	viGetWidth
/*  f0e0898:	00409025 */ 	move	$s2,$v0
/*  f0e089c:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e08a0:	00114c03 */ 	sra	$t1,$s1,0x10
/*  f0e08a4:	0c002e51 */ 	jal	viGetHeight
/*  f0e08a8:	01208825 */ 	move	$s1,$t1
/*  f0e08ac:	8e180008 */ 	lw	$t8,0x8($s0)
/*  f0e08b0:	02402025 */ 	move	$a0,$s2
/*  f0e08b4:	02c02825 */ 	move	$a1,$s6
/*  f0e08b8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e08bc:	8e08000c */ 	lw	$t0,0xc($s0)
/*  f0e08c0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e08c4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0e08c8:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0e08cc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e08d0:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e08d4:	02e03025 */ 	move	$a2,$s7
/*  f0e08d8:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e08dc:	0fc55e10 */ 	jal	textRenderProjected
/*  f0e08e0:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0e08e4:	1000001e */ 	b	.PB0f0e0960
/*  f0e08e8:	00409025 */ 	move	$s2,$v0
/*  f0e08ec:	960d001e */ 	lhu	$t5,0x1e($s0)
.PB0f0e08f0:
/*  f0e08f0:	960b001c */ 	lhu	$t3,0x1c($s0)
/*  f0e08f4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0e08f8:	01a66021 */ 	addu	$t4,$t5,$a2
/*  f0e08fc:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e0900:	0fc55392 */ 	jal	text0f153a34
/*  f0e0904:	01653821 */ 	addu	$a3,$t3,$a1
/*  f0e0908:	0c002e4d */ 	jal	viGetWidth
/*  f0e090c:	00409025 */ 	move	$s2,$v0
/*  f0e0910:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e0914:	0011cc03 */ 	sra	$t9,$s1,0x10
/*  f0e0918:	0c002e51 */ 	jal	viGetHeight
/*  f0e091c:	03208825 */ 	move	$s1,$t9
/*  f0e0920:	8e0f0008 */ 	lw	$t7,0x8($s0)
/*  f0e0924:	02402025 */ 	move	$a0,$s2
/*  f0e0928:	02c02825 */ 	move	$a1,$s6
/*  f0e092c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e0930:	8e09000c */ 	lw	$t1,0xc($s0)
/*  f0e0934:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0e0938:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0e093c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0e0940:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0e0944:	afb4001c */ 	sw	$s4,0x1c($sp)
/*  f0e0948:	afb30018 */ 	sw	$s3,0x18($sp)
/*  f0e094c:	02e03025 */ 	move	$a2,$s7
/*  f0e0950:	26070020 */ 	addiu	$a3,$s0,0x20
/*  f0e0954:	0fc56160 */ 	jal	textRender
/*  f0e0958:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e095c:	00409025 */ 	move	$s2,$v0
.PB0f0e0960:
/*  f0e0960:	921801c9 */ 	lbu	$t8,0x1c9($s0)
/*  f0e0964:	24010006 */ 	li	$at,0x6
/*  f0e0968:	17010002 */ 	bne	$t8,$at,.PB0f0e0974
/*  f0e096c:	00000000 */ 	nop
/*  f0e0970:	afa000e0 */ 	sw	$zero,0xe0($sp)
.PB0f0e0974:
/*  f0e0974:	0fc55498 */ 	jal	textResetBlends
/*  f0e0978:	00000000 */ 	nop
.PB0f0e097c:
/*  f0e097c:	8e0801b4 */ 	lw	$t0,0x1b4($s0)
.PB0f0e0980:
/*  f0e0980:	2401000b */ 	li	$at,0xb
/*  f0e0984:	15010039 */ 	bne	$t0,$at,.PB0f0e0a6c
/*  f0e0988:	00000000 */ 	nop
/*  f0e098c:	afb2009c */ 	sw	$s2,0x9c($sp)
/*  f0e0990:	0c002e8b */ 	jal	viGetViewLeft
/*  f0e0994:	26520008 */ 	addiu	$s2,$s2,0x8
/*  f0e0998:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e099c:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f0e09a0:	01608025 */ 	move	$s0,$t3
/*  f0e09a4:	0c002e8f */ 	jal	viGetViewTop
/*  f0e09a8:	8fb3009c */ 	lw	$s3,0x9c($sp)
/*  f0e09ac:	44829000 */ 	mtc1	$v0,$f18
/*  f0e09b0:	44905000 */ 	mtc1	$s0,$f10
/*  f0e09b4:	3c01ed00 */ 	lui	$at,0xed00
/*  f0e09b8:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f0e09bc:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0e09c0:	46164182 */ 	mul.s	$f6,$f8,$f22
/*  f0e09c4:	00000000 */ 	nop
/*  f0e09c8:	46162482 */ 	mul.s	$f18,$f4,$f22
/*  f0e09cc:	4600340d */ 	trunc.w.s	$f16,$f6
/*  f0e09d0:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e09d4:	440d8000 */ 	mfc1	$t5,$f16
/*  f0e09d8:	440f4000 */ 	mfc1	$t7,$f8
/*  f0e09dc:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f0e09e0:	01c16025 */ 	or	$t4,$t6,$at
/*  f0e09e4:	31e90fff */ 	andi	$t1,$t7,0xfff
/*  f0e09e8:	0009c300 */ 	sll	$t8,$t1,0xc
/*  f0e09ec:	01984025 */ 	or	$t0,$t4,$t8
/*  f0e09f0:	0c002e6d */ 	jal	viGetViewWidth
/*  f0e09f4:	ae680000 */ 	sw	$t0,0x0($s3)
/*  f0e09f8:	0c002e8b */ 	jal	viGetViewLeft
/*  f0e09fc:	a7a20092 */ 	sh	$v0,0x92($sp)
/*  f0e0a00:	00028c00 */ 	sll	$s1,$v0,0x10
/*  f0e0a04:	00115c03 */ 	sra	$t3,$s1,0x10
/*  f0e0a08:	0c002e8f */ 	jal	viGetViewTop
/*  f0e0a0c:	01608825 */ 	move	$s1,$t3
/*  f0e0a10:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e0a14:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0e0a18:	0c002e71 */ 	jal	viGetViewHeight
/*  f0e0a1c:	01408025 */ 	move	$s0,$t2
/*  f0e0a20:	87a90092 */ 	lh	$t1,0x92($sp)
/*  f0e0a24:	00506821 */ 	addu	$t5,$v0,$s0
/*  f0e0a28:	448d3000 */ 	mtc1	$t5,$f6
/*  f0e0a2c:	02296021 */ 	addu	$t4,$s1,$t1
/*  f0e0a30:	448c9000 */ 	mtc1	$t4,$f18
/*  f0e0a34:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f0e0a38:	46809220 */ 	cvt.s.w	$f8,$f18
/*  f0e0a3c:	46168282 */ 	mul.s	$f10,$f16,$f22
/*  f0e0a40:	00000000 */ 	nop
/*  f0e0a44:	46164182 */ 	mul.s	$f6,$f8,$f22
/*  f0e0a48:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0e0a4c:	4600340d */ 	trunc.w.s	$f16,$f6
/*  f0e0a50:	44192000 */ 	mfc1	$t9,$f4
/*  f0e0a54:	44088000 */ 	mfc1	$t0,$f16
/*  f0e0a58:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f0e0a5c:	310b0fff */ 	andi	$t3,$t0,0xfff
/*  f0e0a60:	000b5300 */ 	sll	$t2,$t3,0xc
/*  f0e0a64:	01ea6825 */ 	or	$t5,$t7,$t2
/*  f0e0a68:	ae6d0004 */ 	sw	$t5,0x4($s3)
.PB0f0e0a6c:
/*  f0e0a6c:	3c048007 */ 	lui	$a0,0x8007
/*  f0e0a70:	8c842cb8 */ 	lw	$a0,0x2cb8($a0)
/*  f0e0a74:	00041100 */ 	sll	$v0,$a0,0x4
/*  f0e0a78:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e0a7c:	000210c0 */ 	sll	$v0,$v0,0x3
/*  f0e0a80:	00441023 */ 	subu	$v0,$v0,$a0
/*  f0e0a84:	00021080 */ 	sll	$v0,$v0,0x2
.PB0f0e0a88:
/*  f0e0a88:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f0e0a8c:	25d901dc */ 	addiu	$t9,$t6,0x1dc
/*  f0e0a90:	0322082a */ 	slt	$at,$t9,$v0
/*  f0e0a94:	1420fd70 */ 	bnez	$at,.PB0f0e0058
/*  f0e0a98:	afb90088 */ 	sw	$t9,0x88($sp)
.PB0f0e0a9c:
/*  f0e0a9c:	8fa900e0 */ 	lw	$t1,0xe0($sp)
/*  f0e0aa0:	3c0c800a */ 	lui	$t4,0x800a
/*  f0e0aa4:	11200028 */ 	beqz	$t1,.PB0f0e0b48
/*  f0e0aa8:	00000000 */ 	nop
/*  f0e0aac:	8d8ce758 */ 	lw	$t4,-0x18a8($t4)
/*  f0e0ab0:	0fc54f26 */ 	jal	optionsGetShowMissionTime
/*  f0e0ab4:	8d840070 */ 	lw	$a0,0x70($t4)
/*  f0e0ab8:	10400019 */ 	beqz	$v0,.PB0f0e0b20
/*  f0e0abc:	3c188007 */ 	lui	$t8,0x8007
/*  f0e0ac0:	8f187b70 */ 	lw	$t8,0x7b70($t8)
/*  f0e0ac4:	24030002 */ 	li	$v1,0x2
/*  f0e0ac8:	3c08800a */ 	lui	$t0,0x800a
/*  f0e0acc:	14780014 */ 	bne	$v1,$t8,.PB0f0e0b20
/*  f0e0ad0:	00000000 */ 	nop
/*  f0e0ad4:	8d08e7e8 */ 	lw	$t0,-0x1818($t0)
/*  f0e0ad8:	3c0b800a */ 	lui	$t3,0x800a
/*  f0e0adc:	15000010 */ 	bnez	$t0,.PB0f0e0b20
/*  f0e0ae0:	00000000 */ 	nop
/*  f0e0ae4:	8d6be984 */ 	lw	$t3,-0x167c($t3)
/*  f0e0ae8:	24010026 */ 	li	$at,0x26
/*  f0e0aec:	3c0f800a */ 	lui	$t7,0x800a
/*  f0e0af0:	1161000b */ 	beq	$t3,$at,.PB0f0e0b20
/*  f0e0af4:	00000000 */ 	nop
/*  f0e0af8:	8defe754 */ 	lw	$t7,-0x18ac($t7)
/*  f0e0afc:	24010001 */ 	li	$at,0x1
/*  f0e0b00:	8de20000 */ 	lw	$v0,0x0($t7)
/*  f0e0b04:	10620006 */ 	beq	$v1,$v0,.PB0f0e0b20
/*  f0e0b08:	00000000 */ 	nop
/*  f0e0b0c:	10410004 */ 	beq	$v0,$at,.PB0f0e0b20
/*  f0e0b10:	02402025 */ 	move	$a0,$s2
/*  f0e0b14:	0fc374e1 */ 	jal	hudmsgRenderMissionTimer
/*  f0e0b18:	8fa500e0 */ 	lw	$a1,0xe0($sp)
/*  f0e0b1c:	00409025 */ 	move	$s2,$v0
.PB0f0e0b20:
/*  f0e0b20:	0fc37493 */ 	jal	hudmsgIsZoomRangeVisible
/*  f0e0b24:	00000000 */ 	nop
/*  f0e0b28:	10400004 */ 	beqz	$v0,.PB0f0e0b3c
/*  f0e0b2c:	02402025 */ 	move	$a0,$s2
/*  f0e0b30:	0fc375cf */ 	jal	hudmsgRenderZoomRange
/*  f0e0b34:	8fa500e0 */ 	lw	$a1,0xe0($sp)
/*  f0e0b38:	00409025 */ 	move	$s2,$v0
.PB0f0e0b3c:
/*  f0e0b3c:	0fc241cd */ 	jal	countdownTimerRender
/*  f0e0b40:	02402025 */ 	move	$a0,$s2
/*  f0e0b44:	00409025 */ 	move	$s2,$v0
.PB0f0e0b48:
/*  f0e0b48:	0fc552e5 */ 	jal	text0f153780
/*  f0e0b4c:	02402025 */ 	move	$a0,$s2
/*  f0e0b50:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f0e0b54:	240a0001 */ 	li	$t2,0x1
/*  f0e0b58:	3c018008 */ 	lui	$at,0x8008
/*  f0e0b5c:	d7b40038 */ 	ldc1	$f20,0x38($sp)
/*  f0e0b60:	d7b60040 */ 	ldc1	$f22,0x40($sp)
/*  f0e0b64:	d7b80048 */ 	ldc1	$f24,0x48($sp)
/*  f0e0b68:	d7ba0050 */ 	ldc1	$f26,0x50($sp)
/*  f0e0b6c:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f0e0b70:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f0e0b74:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0e0b78:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f0e0b7c:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f0e0b80:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f0e0b84:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f0e0b88:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f0e0b8c:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f0e0b90:	ac2a1f90 */ 	sw	$t2,0x1f90($at)
/*  f0e0b94:	03e00008 */ 	jr	$ra
/*  f0e0b98:	27bd0100 */ 	addiu	$sp,$sp,0x100
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
/*  f0dfad4:	3c0f8007 */ 	lui	$t7,%hi(g_ViRes)
/*  f0dfad8:	8def06c8 */ 	lw	$t7,%lo(g_ViRes)($t7)
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
/*  f0dfb44:	0fc54d8a */ 	jal	text0f153628
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
/*  f0dfd90:	0fc305f3 */ 	jal	playerIsHealthVisible
/*  f0dfd94:	00000000 */ 	nop
/*  f0dfd98:	5040000d */ 	beqzl	$v0,.L0f0dfdd0
/*  f0dfd9c:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
/*  f0dfda0:	0fc305bd */ 	jal	playerGetHealthBarHeightFrac
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
/*  f0dfe28:	0c002ef5 */ 	jal	viGetBufHeight
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
/*  f0dffc4:	0fc54f08 */ 	jal	textSetDiagonalBlend
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
/*  f0e0090:	0fc54e8d */ 	jal	text0f153a34
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
/*  f0e0104:	0fc54f93 */ 	jal	textResetBlends
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
/*  f0e0220:	0fc54e8d */ 	jal	text0f153a34
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
/*  f0e0370:	0fc54f08 */ 	jal	textSetDiagonalBlend
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
/*  f0e0488:	0fc54e8d */ 	jal	text0f153a34
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
/*  f0e04fc:	0fc54f93 */ 	jal	textResetBlends
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
/*  f0e06d0:	0fc54de0 */ 	jal	text0f153780
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
/*  f0dcf24:	0fc5374a */ 	jal	text0f153628
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
/*  f0dd170:	0fc2fcea */ 	jal	playerIsHealthVisible
/*  f0dd174:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0dd178:	5040000d */ 	beqzl	$v0,.NB0f0dd1b0
/*  f0dd17c:	8e0901b4 */ 	lw	$t1,0x1b4($s0)
/*  f0dd180:	0fc2fcb4 */ 	jal	playerGetHealthBarHeightFrac
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
/*  f0dd3cc:	0fc5389f */ 	jal	textSetDiagonalBlend
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
/*  f0dd498:	0fc53824 */ 	jal	text0f153a34
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
/*  f0dd50c:	0fc5392a */ 	jal	textResetBlends
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
/*  f0dd628:	0fc53824 */ 	jal	text0f153a34
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
/*  f0dd778:	0fc5389f */ 	jal	textSetDiagonalBlend
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
/*  f0dd890:	0fc53824 */ 	jal	text0f153a34
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
/*  f0dd904:	0fc5392a */ 	jal	textResetBlends
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
/*  f0ddad8:	0fc537a0 */ 	jal	text0f153780
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
//	if (g_ViRes == VIRES_HI) {
//		g_ScaleX = 2;
//	} else {
//		g_ScaleX = 1;
//	}
//
//	// b44
//	gdl = text0f153628(gdl);
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
//		if (msg->type == HUDMSGTYPE_INGAMESUBTITLE && playerIsHealthVisible()) {
//			y += (s32)(16.0f * playerGetHealthBarHeightFrac());
//		}
//
//		// dd0
//		if (msg->type == HUDMSGTYPE_CUTSCENESUBTITLE) {
//			gDPSetScissor(gdl++, 0,
//					(x - 4) * g_ScaleX, 0,
//					(x + msg->width + 3) * g_ScaleX, viGetBufHeight());
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
//				textSetDiagonalBlend(x, y, tmp, DIAGMODE_FADEIN);
//
//				// fd8
//				if (msg->boxed) {
//					// fe0
//					gdl = hudmsgRenderBox(gdl, x - 3, y - 3, x + msg->width + 2, y + msg->height + 2, 1.0f, bordercolour, spc0);
//					// 020
//					gdl = textRenderProjected(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, viGetWidth(), viGetHeight(), 0, 0);
//				} else {
//					// 078
//					gdl = text0f153a34(gdl, x, y, x + msg->width, y + msg->height, 0);
//					// 0e4
//					gdl = textRender(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, glowcolour, viGetWidth(), viGetHeight(), 0, 0);
//				}
//
//				if (msg->alignv == 6) {
//					timerthing = 0;
//				}
//
//				textResetBlends();
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
//				gdl = text0f153a34(gdl, x, y, x + msg->width, y + msg->height, 0);
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
//				textSetDiagonalBlend(x + msg->width, y + msg->height, tmp, DIAGMODE_FADEOUT);
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
//					gdl = text0f153a34(gdl, x, y, x + msg->width, y + msg->height, 0);
//					// 4dc
//					gdl = textRender(gdl, &x, &y, msg->text, msg->font1, msg->font2, textcolour, glowcolour, viGetWidth(), viGetHeight(), 0, 0);
//				}
//
//				if (msg->alignv == 6) {
//					timerthing = 0;
//				}
//
//				textResetBlends();
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
//	gdl = text0f153780(gdl);
//
//	g_ScaleX = 1;
//
//	return gdl;
//}

void hudmsgsStop(void)
{
	s32 i;

	for (i = 0; i < g_NumHudMessages; i++) {
		g_HudMessages[i].state = HUDMSGSTATE_FREE;
	}

#if VERSION < VERSION_NTSC_1_0
	if (var800736b0nb && sndGetState(var800736b0nb) != AL_STOPPED) {
		audioStop(var800736b0nb);
	}
#endif
}
