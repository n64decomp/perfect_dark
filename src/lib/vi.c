#include <ultra64.h>
#include "constants.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/player.h"
#include "game/file.h"
#include "game/game_176080.h"
#include "game/gfxmemory.h"
#include "game/options.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/memp.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

#define TO_U16_A(x) ((u16)(x))
#define TO_U16_B(x) ((x) & 0xffff)
#define TO_U16_C(x) ((u16)((x) & 0xffff))

#define ADD_LOW_AND_HI_16_TRUNCATE(reg, add) ((TO_U16_B(TO_U16_A((reg) >> 16) + (add)) << 16) | TO_U16_B(TO_U16_A(reg) + (add)))
#define ADD_LOW_AND_HI_16_MOD(reg, add)      ((((((reg >> 16) & 0xffff) + (add)) % 0xffff) << 16) | (((((reg >> 0) & 0xffff) + (add)) % 0xffff) << 0))

Mtxf var80092830;
Mtx *var80092870;
u16 g_ViPerspScale;
u8 g_ViFrontIndex;
u8 g_ViBackIndex;

struct rend_vidat g_ViDataArray[] = {
	{
		0, 0, 0, 0,
		320, 220,         // x and y
		60,               // fovy
		1.4545454978943f, // aspect
		30,               // znear
		10000,            // zfar
		320, 220,         // bufx and bufy
		320, 220,         // viewx and viewy
		0, 0,             // viewleft and viewtop
		true,             // usezbuf
		0,
	}, {
		0, 0, 0, 0,
		320, 220,         // x and y
		60,               // fovy
		1.4545454978943f, // aspect
		30,               // znear
		10000,            // zfar
		320, 220,         // bufx and bufy
		320, 220,         // viewx and viewy
		0, 0,             // viewleft and viewtop
		true,             // usezbuf
		0,
	},
};

s32 var8005d588 = 0;
s32 var8005d58c = 0;
struct rend_vidat *g_ViFrontData = &g_ViDataArray[0];
struct rend_vidat *g_ViBackData = &g_ViDataArray[0];
bool g_ViIs16Bit = true;
bool g_ViReconfigured = false;
s32 g_ViSlot = 0;

void viConfigureForLogos(void)
{
	g_ViFrontIndex = 0;
	g_ViBackIndex = 1;

	g_ViFrontData = g_ViDataArray + g_ViFrontIndex;
	g_ViBackData = g_ViDataArray + g_ViBackIndex;

#if VERSION >= VERSION_PAL_FINAL
	if (IS4MB()) {
		g_ViDataArray[0].y = 220;
		g_ViDataArray[0].bufy = 220;
		g_ViDataArray[0].viewy = 220;

		g_ViDataArray[1].y = 220;
		g_ViDataArray[1].bufy = 220;
		g_ViDataArray[1].viewy = 220;

		var8005d588 = 0;
		var8005d58c = 0;
	} else {
		var8005d588 = 0;
		var8005d58c = VERSION >= VERSION_JPN_FINAL ? 0 : 12;
	}
#else
	var8005d588 = 0;
	var8005d58c = 0;

	if (IS4MB()) {
		g_ViDataArray[0].y = 220;
		g_ViDataArray[0].bufy = 220;
		g_ViDataArray[0].viewy = 220;

		g_ViDataArray[1].y = 220;
		g_ViDataArray[1].bufy = 220;
		g_ViDataArray[1].viewy = 220;
	}
#endif
}

/**
 * Configure the VI to display the copyright or accessingpak texture.
 *
 * The texture is the first thing displayed after power on.
 *
 * Both textures are 507 x 48, but the framebuffer width is 576.
 */
void viConfigureForCopyright(u16 *texturedata)
{
	s32 i;

	for (i = 0; i < 2; i++) {
		g_FrameBuffers[i] = texturedata;

		g_ViDataArray[i].x = 576;
		g_ViDataArray[i].bufx = 576;
		g_ViDataArray[i].viewx = (VERSION >= VERSION_NTSC_1_0 ? 576 : 480);

		g_ViDataArray[i].y = 48;
		g_ViDataArray[i].bufy = 48;
		g_ViDataArray[i].viewy = 48;
	}

	g_ViFrontData->fb = g_FrameBuffers[g_ViFrontIndex];
	g_ViBackData->fb = g_FrameBuffers[g_ViBackIndex];

	g_ViReconfigured = true;
	g_Vars.fourmeg2player = false;
}

/**
 * Configure the VI to display the legal screen.
 *
 * It's also used for the "check controllers" message
 * if controller 1 is not connected.
 */
void viConfigureForLegal(void)
{
	s32 i;

	for (i = 0; i < 2; i++) {
		g_ViDataArray[i].x = 320;
		g_ViDataArray[i].bufx = 320;
		g_ViDataArray[i].viewx = 320;

		g_ViDataArray[i].y = 220;
		g_ViDataArray[i].bufy = 220;
		g_ViDataArray[i].viewy = 220;
	}

	g_Vars.fourmeg2player = false;

#if PAL
	playerResetLoResIf4Mb();
#endif
}

const s16 g_ViModeWidths[] = {320, 320, 640};

#if PAL
const s16 g_ViModeHeights[] = {220, 220, 504};
#else
const s16 g_ViModeHeights[] = {220, 220, 440};
#endif

/**
 * Allocate the colour framebuffers for the given stage.
 *
 * Regardless of whether hi-res is being used or not, the buffers are allocated
 * for hi-res. This is because hi-res can be changed mid-stage, and the engine
 * cannot reallocate the frame buffer without clearing the stage's entire memory
 * pool.
 *
 * The same is probably true for wide and cinema modes.
 */
void viReset(s32 stagenum)
{
	s32 i;
	s32 fbsize;
	u8 *ptr;
	u8 *fb0;
	u8 *fb1;

	g_Vars.fourmeg2player = false;

	if (stagenum == STAGE_TITLE || stagenum == STAGE_TEST_OLD) {
		if (IS4MB()) {
			viSetMode(VIMODE_HI);
			fbsize = 640 * 440 * 2;
		} else {
			viSetMode(VIMODE_HI);
			fbsize = g_ViModeWidths[2] * g_ViModeHeights[2] * 2;
		}
	} else {
		viSetMode(VIMODE_LO);

		if (1);

		fbsize = IS4MB() ? 320 * 220 * 2 : 320 * 220 * 4;

		if (IS4MB() && PLAYERCOUNT() == 2) {
#if VERSION >= VERSION_NTSC_1_0
			fbsize = 320 * 220;
#else
			fbsize = 320 * 240;
#endif
			g_Vars.fourmeg2player = true;
		} else if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) && PLAYERCOUNT() == 2) {
#if VERSION >= VERSION_JPN_FINAL
			fbsize = 320 * 220 * 2;
#elif VERSION >= VERSION_PAL_FINAL
			fbsize = 320 * 266 * 2;
#elif VERSION >= VERSION_PAL_BETA
			fbsize = 320 * 252 * 2;
#else
			fbsize = 320 * 220 * 2;
#endif
		}
	}

	ptr = mempAlloc(fbsize * 2 + 0x40, MEMPOOL_STAGE);

	ptr = (u8 *)(((u32)ptr + 0x3f) & 0xffffffc0);

	g_FrameBuffers[0] = (u16 *) ptr;
	g_FrameBuffers[1] = (u16 *) (fbsize + ptr);

	g_ViFrontData->fb = g_FrameBuffers[g_ViFrontIndex];
	g_ViBackData->fb = g_FrameBuffers[g_ViBackIndex];

	fb0 = (u8 *) g_FrameBuffers[0];
	fb1 = (u8 *) g_FrameBuffers[1];

	for (i = 0; i < fbsize; i++) {
		fb0[i] = 0;
		fb1[i] = 0;
	}

	g_ViReconfigured = true;
}

/**
 * If black is true, set the video output to black indefinitely.
 * g_ViUnblackTimer is set to 3 which causes the timer to be paused.
 *
 * If black is false, set the timer to 2. This causes it to tick down once per
 * frame and unblack once it reaches 0.
 */
void viBlack(bool black)
{
	black += 2;
	g_ViUnblackTimer = black;
}

void vi00009ed4(void)
{
	s32 prevmask;
	s32 offset;
	s32 reg;

	if (g_ViShakeTimer != 0) {
		g_ViShakeTimer--;

		if (g_ViShakeTimer == 0) {
			g_ViShakeIntensity = 0;
		}
	}

	offset = g_ViShakeDirection * g_ViShakeIntensity;
	g_ViShakeDirection = -g_ViShakeDirection;

#if VERSION >= VERSION_NTSC_1_0
	prevmask = osSetIntMask(1);
#endif

	reg = var8008de0c;
	var8008dd60[1 - var8005ce74]->fldRegs[0].vStart = ADD_LOW_AND_HI_16_TRUNCATE(reg, offset);

	reg = var8008de10;
	var8008dd60[1 - var8005ce74]->fldRegs[1].vStart = ADD_LOW_AND_HI_16_TRUNCATE(reg, offset);

#if VERSION >= VERSION_NTSC_1_0
	osSetIntMask(prevmask);
#endif

	osViSetMode(var8008dd60[1 - var8005ce74]);
	osViBlack(g_ViUnblackTimer);
	osViSetXScale(g_ViXScalesBySlot[1 - var8005ce74]);
	osViSetYScale(g_ViYScalesBySlot[1 - var8005ce74]);
	osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_DITHER_FILTER_ON);
}

#if MATCHING && !PAL
GLOBAL_ASM(
glabel viUpdateMode
/*     a044:	3c098006 */ 	lui	$t1,%hi(g_ViBackData)
/*     a048:	3c0e8006 */ 	lui	$t6,%hi(g_ViFrontData)
/*     a04c:	8dced590 */ 	lw	$t6,%lo(g_ViFrontData)($t6)
/*     a050:	8d29d594 */ 	lw	$t1,%lo(g_ViBackData)($t1)
/*     a054:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*     a058:	afbf0014 */ 	sw	$ra,0x14($sp)
/*     a05c:	91cf0000 */ 	lbu	$t7,0x0($t6)
/*     a060:	91230000 */ 	lbu	$v1,0x0($t1)
/*     a064:	506f0014 */ 	beql	$v1,$t7,.L0000a0b8
/*     a068:	85380004 */ 	lh	$t8,0x4($t1)
/*     a06c:	10600008 */ 	beqz	$v1,.L0000a090
/*     a070:	00601025 */ 	or	$v0,$v1,$zero
/*     a074:	241f0001 */ 	addiu	$ra,$zero,0x1
/*     a078:	107f000e */ 	beq	$v1,$ra,.L0000a0b4
/*     a07c:	24040002 */ 	addiu	$a0,$zero,0x2
/*     a080:	5044000d */ 	beql	$v0,$a0,.L0000a0b8
/*     a084:	85380004 */ 	lh	$t8,0x4($t1)
/*     a088:	1000000b */ 	b	.L0000a0b8
/*     a08c:	85380004 */ 	lh	$t8,0x4($t1)
.L0000a090:
/*     a090:	3c013f80 */ 	lui	$at,0x3f80
/*     a094:	44816000 */ 	mtc1	$at,$f12
/*     a098:	0c0123bc */ 	jal	osViSetYScale
/*     a09c:	00000000 */ 	nop
/*     a0a0:	0c012338 */ 	jal	osViBlack
/*     a0a4:	24040001 */ 	addiu	$a0,$zero,0x1
/*     a0a8:	3c098006 */ 	lui	$t1,%hi(g_ViBackData)
/*     a0ac:	8d29d594 */ 	lw	$t1,%lo(g_ViBackData)($t1)
/*     a0b0:	91230000 */ 	lbu	$v1,0x0($t1)
.L0000a0b4:
/*     a0b4:	85380004 */ 	lh	$t8,0x4($t1)
.L0000a0b8:
/*     a0b8:	85390018 */ 	lh	$t9,0x18($t1)
/*     a0bc:	852e0006 */ 	lh	$t6,0x6($t1)
/*     a0c0:	44982000 */ 	mtc1	$t8,$f4
/*     a0c4:	852f001a */ 	lh	$t7,0x1a($t1)
/*     a0c8:	44994000 */ 	mtc1	$t9,$f8
/*     a0cc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*     a0d0:	448e8000 */ 	mtc1	$t6,$f16
/*     a0d4:	448f2000 */ 	mtc1	$t7,$f4
/*     a0d8:	24040002 */ 	addiu	$a0,$zero,0x2
/*     a0dc:	241f0001 */ 	addiu	$ra,$zero,0x1
/*     a0e0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*     a0e4:	3c0b8006 */ 	lui	$t3,%hi(g_ViSlot)
/*     a0e8:	3c013f80 */ 	lui	$at,0x3f80
/*     a0ec:	468084a0 */ 	cvt.s.w	$f18,$f16
/*     a0f0:	46802220 */ 	cvt.s.w	$f8,$f4
/*     a0f4:	460a3083 */ 	div.s	$f2,$f6,$f10
/*     a0f8:	14600003 */ 	bnez	$v1,.L0000a108
/*     a0fc:	46089003 */ 	div.s	$f0,$f18,$f8
/*     a100:	44810000 */ 	mtc1	$at,$f0
/*     a104:	00000000 */ 	nop
.L0000a108:
/*     a108:	8d6bd5a0 */ 	lw	$t3,%lo(g_ViSlot)($t3)
/*     a10c:	3c018006 */ 	lui	$at,%hi(g_ViXScalesBySlot)
/*     a110:	000b6080 */ 	sll	$t4,$t3,0x2
/*     a114:	002c0821 */ 	addu	$at,$at,$t4
/*     a118:	e422ce78 */ 	swc1	$f2,%lo(g_ViXScalesBySlot)($at)
/*     a11c:	3c018006 */ 	lui	$at,%hi(g_ViYScalesBySlot)
/*     a120:	002c0821 */ 	addu	$at,$at,$t4
/*     a124:	e420ce80 */ 	swc1	$f0,%lo(g_ViYScalesBySlot)($at)
/*     a128:	91230000 */ 	lbu	$v1,0x0($t1)
/*     a12c:	17e30101 */ 	bne	$ra,$v1,.L0000a534
/*     a130:	00000000 */ 	nop
/*     a134:	3c0a8006 */ 	lui	$t2,%hi(g_ViIs16Bit)
/*     a138:	8d4ad598 */ 	lw	$t2,%lo(g_ViIs16Bit)($t2)
/*     a13c:	3c188000 */ 	lui	$t8,%hi(osTvType)
/*     a140:	11400033 */ 	beqz	$t2,.L0000a210
/*     a144:	00000000 */ 	nop
/*     a148:	8f180300 */ 	lw	$t8,%lo(osTvType)($t8)
/*     a14c:	3c198009 */ 	lui	$t9,%hi(var8008dcc0)
/*     a150:	2739dcc0 */ 	addiu	$t9,$t9,%lo(var8008dcc0)
/*     a154:	14980019 */ 	bne	$a0,$t8,.L0000a1bc
/*     a158:	3c0f8006 */ 	lui	$t7,%hi(osViModeTable+0xa0)
/*     a15c:	000bc880 */ 	sll	$t9,$t3,0x2
/*     a160:	032bc821 */ 	addu	$t9,$t9,$t3
/*     a164:	3c0e8009 */ 	lui	$t6,%hi(var8008dcc0)
/*     a168:	25cedcc0 */ 	addiu	$t6,$t6,%lo(var8008dcc0)
/*     a16c:	0019c900 */ 	sll	$t9,$t9,0x4
/*     a170:	032e2021 */ 	addu	$a0,$t9,$t6
/*     a174:	3c0f8006 */ 	lui	$t7,%hi(osViModeTable+0x960)
/*     a178:	25ef0070 */ 	addiu	$t7,$t7,%lo(osViModeTable+0x960)
/*     a17c:	25f90048 */ 	addiu	$t9,$t7,0x48
/*     a180:	00807025 */ 	or	$t6,$a0,$zero
.L0000a184:
/*     a184:	8de10000 */ 	lw	$at,0x0($t7)
/*     a188:	25ef000c */ 	addiu	$t7,$t7,12
/*     a18c:	25ce000c */ 	addiu	$t6,$t6,12
/*     a190:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*     a194:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*     a198:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*     a19c:	8de1fffc */ 	lw	$at,-0x4($t7)
/*     a1a0:	15f9fff8 */ 	bne	$t7,$t9,.L0000a184
/*     a1a4:	adc1fffc */ 	sw	$at,-0x4($t6)
/*     a1a8:	8de10000 */ 	lw	$at,0x0($t7)
/*     a1ac:	adc10000 */ 	sw	$at,0x0($t6)
/*     a1b0:	8df90004 */ 	lw	$t9,0x4($t7)
/*     a1b4:	10000048 */ 	b	.L0000a2d8
/*     a1b8:	add90004 */ 	sw	$t9,0x4($t6)
.L0000a1bc:
/*     a1bc:	000bc080 */ 	sll	$t8,$t3,0x2
/*     a1c0:	030bc021 */ 	addu	$t8,$t8,$t3
/*     a1c4:	0018c100 */ 	sll	$t8,$t8,0x4
/*     a1c8:	03192021 */ 	addu	$a0,$t8,$t9
/*     a1cc:	25eff7b0 */ 	addiu	$t7,$t7,%lo(osViModeTable+0xa0)
/*     a1d0:	25f80048 */ 	addiu	$t8,$t7,0x48
/*     a1d4:	0080c825 */ 	or	$t9,$a0,$zero
.L0000a1d8:
/*     a1d8:	8de10000 */ 	lw	$at,0x0($t7)
/*     a1dc:	25ef000c */ 	addiu	$t7,$t7,0xc
/*     a1e0:	2739000c */ 	addiu	$t9,$t9,0xc
/*     a1e4:	af21fff4 */ 	sw	$at,-0xc($t9)
/*     a1e8:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*     a1ec:	af21fff8 */ 	sw	$at,-0x8($t9)
/*     a1f0:	8de1fffc */ 	lw	$at,-0x4($t7)
/*     a1f4:	15f8fff8 */ 	bne	$t7,$t8,.L0000a1d8
/*     a1f8:	af21fffc */ 	sw	$at,-0x4($t9)
/*     a1fc:	8de10000 */ 	lw	$at,0x0($t7)
/*     a200:	af210000 */ 	sw	$at,0x0($t9)
/*     a204:	8df80004 */ 	lw	$t8,0x4($t7)
/*     a208:	10000033 */ 	b	.L0000a2d8
/*     a20c:	af380004 */ 	sw	$t8,0x4($t9)
.L0000a210:
/*     a210:	3c0e8000 */ 	lui	$t6,%hi(osTvType)
/*     a214:	8dce0300 */ 	lw	$t6,%lo(osTvType)($t6)
/*     a218:	148e0018 */ 	bne	$a0,$t6,.L0000a27c
/*     a21c:	000bc080 */ 	sll	$t8,$t3,0x2
/*     a220:	030bc021 */ 	addu	$t8,$t8,$t3
/*     a224:	3c0f8009 */ 	lui	$t7,%hi(var8008dcc0)
/*     a228:	25efdcc0 */ 	addiu	$t7,$t7,%lo(var8008dcc0)
/*     a22c:	0018c100 */ 	sll	$t8,$t8,0x4
/*     a230:	030f2021 */ 	addu	$a0,$t8,$t7
/*     a234:	3c198006 */ 	lui	$t9,%hi(osViModeTable+0xaa0)
/*     a238:	273901b0 */ 	addiu	$t9,$t9,%lo(osViModeTable+0xaa0)
/*     a23c:	27380048 */ 	addiu	$t8,$t9,0x48
/*     a240:	00807825 */ 	or	$t7,$a0,$zero
.L0000a244:
/*     a244:	8f210000 */ 	lw	$at,0x0($t9)
/*     a248:	2739000c */ 	addiu	$t9,$t9,0xc
/*     a24c:	25ef000c */ 	addiu	$t7,$t7,0xc
/*     a250:	ade1fff4 */ 	sw	$at,-0xc($t7)
/*     a254:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*     a258:	ade1fff8 */ 	sw	$at,-0x8($t7)
/*     a25c:	8f21fffc */ 	lw	$at,-0x4($t9)
/*     a260:	1738fff8 */ 	bne	$t9,$t8,.L0000a244
/*     a264:	ade1fffc */ 	sw	$at,-0x4($t7)
/*     a268:	8f210000 */ 	lw	$at,0x0($t9)
/*     a26c:	ade10000 */ 	sw	$at,0x0($t7)
/*     a270:	8f380004 */ 	lw	$t8,0x4($t9)
/*     a274:	10000018 */ 	b	.L0000a2d8
/*     a278:	adf80004 */ 	sw	$t8,0x4($t7)
.L0000a27c:
/*     a27c:	000b7080 */ 	sll	$t6,$t3,0x2
/*     a280:	01cb7021 */ 	addu	$t6,$t6,$t3
/*     a284:	3c188009 */ 	lui	$t8,%hi(var8008dcc0)
/*     a288:	2718dcc0 */ 	addiu	$t8,$t8,%lo(var8008dcc0)
/*     a28c:	000e7100 */ 	sll	$t6,$t6,0x4
/*     a290:	01d82021 */ 	addu	$a0,$t6,$t8
/*     a294:	3c198006 */ 	lui	$t9,%hi(osViModeTable+0x1e0)
/*     a298:	2739f8f0 */ 	addiu	$t9,$t9,%lo(osViModeTable+0x1e0)
/*     a29c:	272e0048 */ 	addiu	$t6,$t9,0x48
/*     a2a0:	0080c025 */ 	or	$t8,$a0,$zero
.L0000a2a4:
/*     a2a4:	8f210000 */ 	lw	$at,0x0($t9)
/*     a2a8:	2739000c */ 	addiu	$t9,$t9,0xc
/*     a2ac:	2718000c */ 	addiu	$t8,$t8,0xc
/*     a2b0:	af01fff4 */ 	sw	$at,-0xc($t8)
/*     a2b4:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*     a2b8:	af01fff8 */ 	sw	$at,-0x8($t8)
/*     a2bc:	8f21fffc */ 	lw	$at,-0x4($t9)
/*     a2c0:	172efff8 */ 	bne	$t9,$t6,.L0000a2a4
/*     a2c4:	af01fffc */ 	sw	$at,-0x4($t8)
/*     a2c8:	8f210000 */ 	lw	$at,0x0($t9)
/*     a2cc:	af010000 */ 	sw	$at,0x0($t8)
/*     a2d0:	8f2e0004 */ 	lw	$t6,0x4($t9)
/*     a2d4:	af0e0004 */ 	sw	$t6,0x4($t8)
.L0000a2d8:
/*     a2d8:	852f0018 */ 	lh	$t7,0x18($t1)
/*     a2dc:	24010280 */ 	addiu	$at,$zero,0x280
/*     a2e0:	3c0d8009 */ 	lui	$t5,%hi(var8008de0c)
/*     a2e4:	ac8f0008 */ 	sw	$t7,0x8($a0)
/*     a2e8:	852e0018 */ 	lh	$t6,0x18($t1)
/*     a2ec:	3406ffff */ 	dli	$a2,0xffff
/*     a2f0:	25adde0c */ 	addiu	$t5,$t5,%lo(var8008de0c)
/*     a2f4:	000eca80 */ 	sll	$t9,$t6,0xa
/*     a2f8:	0321001a */ 	div	$zero,$t9,$at
/*     a2fc:	0000c012 */ 	mflo	$t8
/*     a300:	ac980020 */ 	sw	$t8,0x20($a0)
/*     a304:	852f0018 */ 	lh	$t7,0x18($t1)
/*     a308:	000f7040 */ 	sll	$t6,$t7,0x1
/*     a30c:	ac8e0028 */ 	sw	$t6,0x28($a0)
/*     a310:	85390018 */ 	lh	$t9,0x18($t1)
/*     a314:	3c0f8009 */ 	lui	$t7,%hi(g_Is4Mb)
/*     a318:	0019c040 */ 	sll	$t8,$t9,0x1
/*     a31c:	ac98003c */ 	sw	$t8,0x3c($a0)
/*     a320:	91ef0af0 */ 	lbu	$t7,%lo(g_Is4Mb)($t7)
/*     a324:	17ef0004 */ 	bne	$ra,$t7,.L0000a338
/*     a328:	24020400 */ 	addiu	$v0,$zero,0x400
/*     a32c:	ac82002c */ 	sw	$v0,0x2c($a0)
/*     a330:	1000001e */ 	b	.L0000a3ac
/*     a334:	ac820040 */ 	sw	$v0,0x40($a0)
.L0000a338:
/*     a338:	852e001a */ 	lh	$t6,0x1a($t1)
/*     a33c:	240201b8 */ 	addiu	$v0,$zero,0x1b8
/*     a340:	000ecac0 */ 	sll	$t9,$t6,0xb
/*     a344:	0322001a */ 	div	$zero,$t9,$v0
/*     a348:	0000c012 */ 	mflo	$t8
/*     a34c:	ac98002c */ 	sw	$t8,0x2c($a0)
/*     a350:	852f001a */ 	lh	$t7,0x1a($t1)
/*     a354:	14400002 */ 	bnez	$v0,.L0000a360
/*     a358:	00000000 */ 	nop
/*     a35c:	0007000d */ 	break	0x7
.L0000a360:
/*     a360:	2401ffff */ 	addiu	$at,$zero,-1
/*     a364:	14410004 */ 	bne	$v0,$at,.L0000a378
/*     a368:	3c018000 */ 	lui	$at,0x8000
/*     a36c:	17210002 */ 	bne	$t9,$at,.L0000a378
/*     a370:	00000000 */ 	nop
/*     a374:	0006000d */ 	break	0x6
.L0000a378:
/*     a378:	000f72c0 */ 	sll	$t6,$t7,0xb
/*     a37c:	01c2001a */ 	div	$zero,$t6,$v0
/*     a380:	0000c812 */ 	mflo	$t9
/*     a384:	ac990040 */ 	sw	$t9,0x40($a0)
/*     a388:	14400002 */ 	bnez	$v0,.L0000a394
/*     a38c:	00000000 */ 	nop
/*     a390:	0007000d */ 	break	0x7
.L0000a394:
/*     a394:	2401ffff */ 	addiu	$at,$zero,-1
/*     a398:	14410004 */ 	bne	$v0,$at,.L0000a3ac
/*     a39c:	3c018000 */ 	lui	$at,0x8000
/*     a3a0:	15c10002 */ 	bne	$t6,$at,.L0000a3ac
/*     a3a4:	00000000 */ 	nop
/*     a3a8:	0006000d */ 	break	0x6
.L0000a3ac:
/*     a3ac:	8c85001c */ 	lw	$a1,0x1c($a0)
/*     a3b0:	3c078006 */ 	lui	$a3,%hi(var8005d588)
/*     a3b4:	8ce7d588 */ 	lw	$a3,%lo(var8005d588)($a3)
/*     a3b8:	0005c403 */ 	sra	$t8,$a1,0x10
/*     a3bc:	330fffff */ 	andi	$t7,$t8,0xffff
/*     a3c0:	01e77021 */ 	addu	$t6,$t7,$a3
/*     a3c4:	01c6001a */ 	div	$zero,$t6,$a2
/*     a3c8:	14c00002 */ 	bnez	$a2,.L0000a3d4
/*     a3cc:	00000000 */ 	nop
/*     a3d0:	0007000d */ 	break	0x7
.L0000a3d4:
/*     a3d4:	2401ffff */ 	addiu	$at,$zero,-1
/*     a3d8:	14c10004 */ 	bne	$a2,$at,.L0000a3ec
/*     a3dc:	3c018000 */ 	lui	$at,0x8000
/*     a3e0:	15c10002 */ 	bne	$t6,$at,.L0000a3ec
/*     a3e4:	00000000 */ 	nop
/*     a3e8:	0006000d */ 	break	0x6
.L0000a3ec:
/*     a3ec:	30afffff */ 	andi	$t7,$a1,0xffff
/*     a3f0:	01e77021 */ 	addu	$t6,$t7,$a3
/*     a3f4:	0000c810 */ 	mfhi	$t9
/*     a3f8:	0019c400 */ 	sll	$t8,$t9,0x10
/*     a3fc:	3c1f8009 */ 	lui	$ra,%hi(var8008de10)
/*     a400:	01c6001a */ 	div	$zero,$t6,$a2
/*     a404:	14c00002 */ 	bnez	$a2,.L0000a410
/*     a408:	00000000 */ 	nop
/*     a40c:	0007000d */ 	break	0x7
.L0000a410:
/*     a410:	2401ffff */ 	addiu	$at,$zero,-1
/*     a414:	14c10004 */ 	bne	$a2,$at,.L0000a428
/*     a418:	3c018000 */ 	lui	$at,0x8000
/*     a41c:	15c10002 */ 	bne	$t6,$at,.L0000a428
/*     a420:	00000000 */ 	nop
/*     a424:	0006000d */ 	break	0x6
.L0000a428:
/*     a428:	0000c810 */ 	mfhi	$t9
/*     a42c:	03191025 */ 	or	$v0,$t8,$t9
/*     a430:	ac82001c */ 	sw	$v0,0x1c($a0)
/*     a434:	3c018009 */ 	lui	$at,%hi(var8008de08)
/*     a438:	ac22de08 */ 	sw	$v0,%lo(var8008de08)($at)
/*     a43c:	8523001a */ 	lh	$v1,0x1a($t1)
/*     a440:	8c8e002c */ 	lw	$t6,0x2c($a0)
/*     a444:	27ffde10 */ 	addiu	$ra,$ra,%lo(var8008de10)
/*     a448:	00037a80 */ 	sll	$t7,$v1,0xa
/*     a44c:	01ee001b */ 	divu	$zero,$t7,$t6
/*     a450:	00001812 */ 	mflo	$v1
/*     a454:	2861012d */ 	slti	$at,$v1,0x12d
/*     a458:	15c00002 */ 	bnez	$t6,.L0000a464
/*     a45c:	00000000 */ 	nop
/*     a460:	0007000d */ 	break	0x7
.L0000a464:
/*     a464:	24190115 */ 	addiu	$t9,$zero,0x115
/*     a468:	14200003 */ 	bnez	$at,.L0000a478
/*     a46c:	3c058006 */ 	lui	$a1,%hi(var8005d58c)
/*     a470:	0003c043 */ 	sra	$t8,$v1,0x1
/*     a474:	03001825 */ 	or	$v1,$t8,$zero
.L0000a478:
/*     a478:	03233823 */ 	subu	$a3,$t9,$v1
/*     a47c:	24ef0002 */ 	addiu	$t7,$a3,0x2
/*     a480:	2478fffe */ 	addiu	$t8,$v1,-2
/*     a484:	0018c840 */ 	sll	$t9,$t8,0x1
/*     a488:	000f7400 */ 	sll	$t6,$t7,0x10
/*     a48c:	00f97821 */ 	addu	$t7,$a3,$t9
/*     a490:	25f80002 */ 	addiu	$t8,$t7,0x2
/*     a494:	8ca5d58c */ 	lw	$a1,%lo(var8005d58c)($a1)
/*     a498:	01d84025 */ 	or	$t0,$t6,$t8
/*     a49c:	0008cc03 */ 	sra	$t9,$t0,0x10
/*     a4a0:	332fffff */ 	andi	$t7,$t9,0xffff
/*     a4a4:	01e57021 */ 	addu	$t6,$t7,$a1
/*     a4a8:	01c6001a */ 	div	$zero,$t6,$a2
/*     a4ac:	14c00002 */ 	bnez	$a2,.L0000a4b8
/*     a4b0:	00000000 */ 	nop
/*     a4b4:	0007000d */ 	break	0x7
.L0000a4b8:
/*     a4b8:	2401ffff */ 	addiu	$at,$zero,-1
/*     a4bc:	14c10004 */ 	bne	$a2,$at,.L0000a4d0
/*     a4c0:	3c018000 */ 	lui	$at,0x8000
/*     a4c4:	15c10002 */ 	bne	$t6,$at,.L0000a4d0
/*     a4c8:	00000000 */ 	nop
/*     a4cc:	0006000d */ 	break	0x6
.L0000a4d0:
/*     a4d0:	310fffff */ 	andi	$t7,$t0,0xffff
/*     a4d4:	01e57021 */ 	addu	$t6,$t7,$a1
/*     a4d8:	0000c010 */ 	mfhi	$t8
/*     a4dc:	0018cc00 */ 	sll	$t9,$t8,0x10
/*     a4e0:	240f0001 */ 	addiu	$t7,$zero,0x1
/*     a4e4:	01c6001a */ 	div	$zero,$t6,$a2
/*     a4e8:	14c00002 */ 	bnez	$a2,.L0000a4f4
/*     a4ec:	00000000 */ 	nop
/*     a4f0:	0007000d */ 	break	0x7
.L0000a4f4:
/*     a4f4:	2401ffff */ 	addiu	$at,$zero,-1
/*     a4f8:	14c10004 */ 	bne	$a2,$at,.L0000a50c
/*     a4fc:	3c018000 */ 	lui	$at,0x8000
/*     a500:	15c10002 */ 	bne	$t6,$at,.L0000a50c
/*     a504:	00000000 */ 	nop
/*     a508:	0006000d */ 	break	0x6
.L0000a50c:
/*     a50c:	0000c010 */ 	mfhi	$t8
/*     a510:	03381025 */ 	or	$v0,$t9,$t8
/*     a514:	3c018006 */ 	lui	$at,%hi(g_SchedViModesPending)
/*     a518:	ac820030 */ 	sw	$v0,0x30($a0)
/*     a51c:	ada20000 */ 	sw	$v0,0x0($t5)
/*     a520:	ac820044 */ 	sw	$v0,0x44($a0)
/*     a524:	afe20000 */ 	sw	$v0,0x0($ra)
/*     a528:	002c0821 */ 	addu	$at,$at,$t4
/*     a52c:	100000f6 */ 	b	.L0000a908
/*     a530:	ac2fce88 */ 	sw	$t7,%lo(g_SchedViModesPending)($at)
.L0000a534:
/*     a534:	148300ef */ 	bne	$a0,$v1,.L0000a8f4
/*     a538:	3c0e8000 */ 	lui	$t6,%hi(osTvType)
/*     a53c:	8dce0300 */ 	lw	$t6,%lo(osTvType)($t6)
/*     a540:	3406ffff */ 	dli	$a2,0xffff
/*     a544:	24080800 */ 	addiu	$t0,$zero,0x800
/*     a548:	148e0019 */ 	bne	$a0,$t6,.L0000a5b0
/*     a54c:	3c0d8009 */ 	lui	$t5,%hi(var8008de0c)
/*     a550:	000bc880 */ 	sll	$t9,$t3,0x2
/*     a554:	032bc821 */ 	addu	$t9,$t9,$t3
/*     a558:	3c188009 */ 	lui	$t8,%hi(var8008dcc0)
/*     a55c:	2718dcc0 */ 	addiu	$t8,$t8,%lo(var8008dcc0)
/*     a560:	0019c900 */ 	sll	$t9,$t9,0x4
/*     a564:	03382021 */ 	addu	$a0,$t9,$t8
/*     a568:	3c0f8006 */ 	lui	$t7,%hi(osViModeTable+0xc30)
/*     a56c:	25ef0340 */ 	addiu	$t7,$t7,%lo(osViModeTable+0xc30)
/*     a570:	25f90048 */ 	addiu	$t9,$t7,0x48
/*     a574:	0080c025 */ 	or	$t8,$a0,$zero
.L0000a578:
/*     a578:	8de10000 */ 	lw	$at,0x0($t7)
/*     a57c:	25ef000c */ 	addiu	$t7,$t7,12
/*     a580:	2718000c */ 	addiu	$t8,$t8,0xc
/*     a584:	af01fff4 */ 	sw	$at,-0xc($t8)
/*     a588:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*     a58c:	af01fff8 */ 	sw	$at,-0x8($t8)
/*     a590:	8de1fffc */ 	lw	$at,-0x4($t7)
/*     a594:	15f9fff8 */ 	bne	$t7,$t9,.L0000a578
/*     a598:	af01fffc */ 	sw	$at,-0x4($t8)
/*     a59c:	8de10000 */ 	lw	$at,0x0($t7)
/*     a5a0:	af010000 */ 	sw	$at,0x0($t8)
/*     a5a4:	8df90004 */ 	lw	$t9,0x4($t7)
/*     a5a8:	10000018 */ 	b	.L0000a60c
/*     a5ac:	af190004 */ 	sw	$t9,0x4($t8)
.L0000a5b0:
/*     a5b0:	000b7080 */ 	sll	$t6,$t3,0x2
/*     a5b4:	01cb7021 */ 	addu	$t6,$t6,$t3
/*     a5b8:	3c198009 */ 	lui	$t9,%hi(var8008dcc0)
/*     a5bc:	2739dcc0 */ 	addiu	$t9,$t9,%lo(var8008dcc0)
/*     a5c0:	000e7100 */ 	sll	$t6,$t6,0x4
/*     a5c4:	01d92021 */ 	addu	$a0,$t6,$t9
/*     a5c8:	3c0f8006 */ 	lui	$t7,%hi(osViModeTable+0x370)
/*     a5cc:	25effa80 */ 	addiu	$t7,$t7,%lo(osViModeTable+0x370)
/*     a5d0:	25ee0048 */ 	addiu	$t6,$t7,0x48
/*     a5d4:	0080c825 */ 	or	$t9,$a0,$zero
.L0000a5d8:
/*     a5d8:	8de10000 */ 	lw	$at,0x0($t7)
/*     a5dc:	25ef000c */ 	addiu	$t7,$t7,0xc
/*     a5e0:	2739000c */ 	addiu	$t9,$t9,0xc
/*     a5e4:	af21fff4 */ 	sw	$at,-0xc($t9)
/*     a5e8:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*     a5ec:	af21fff8 */ 	sw	$at,-0x8($t9)
/*     a5f0:	8de1fffc */ 	lw	$at,-0x4($t7)
/*     a5f4:	15eefff8 */ 	bne	$t7,$t6,.L0000a5d8
/*     a5f8:	af21fffc */ 	sw	$at,-0x4($t9)
/*     a5fc:	8de10000 */ 	lw	$at,0x0($t7)
/*     a600:	af210000 */ 	sw	$at,0x0($t9)
/*     a604:	8dee0004 */ 	lw	$t6,0x4($t7)
/*     a608:	af2e0004 */ 	sw	$t6,0x4($t9)
.L0000a60c:
/*     a60c:	85380018 */ 	lh	$t8,0x18($t1)
/*     a610:	24010280 */ 	addiu	$at,$zero,0x280
/*     a614:	8c83001c */ 	lw	$v1,0x1c($a0)
/*     a618:	ac980008 */ 	sw	$t8,0x8($a0)
/*     a61c:	852e0018 */ 	lh	$t6,0x18($t1)
/*     a620:	ac88002c */ 	sw	$t0,0x2c($a0)
/*     a624:	ac880040 */ 	sw	$t0,0x40($a0)
/*     a628:	000e7a80 */ 	sll	$t7,$t6,0xa
/*     a62c:	01e1001a */ 	div	$zero,$t7,$at
/*     a630:	0000c812 */ 	mflo	$t9
/*     a634:	ac990020 */ 	sw	$t9,0x20($a0)
/*     a638:	85380018 */ 	lh	$t8,0x18($t1)
/*     a63c:	3c078006 */ 	lui	$a3,%hi(var8005d588)
/*     a640:	3c058006 */ 	lui	$a1,%hi(var8005d58c)
/*     a644:	00187040 */ 	sll	$t6,$t8,0x1
/*     a648:	ac8e0028 */ 	sw	$t6,0x28($a0)
/*     a64c:	852f0018 */ 	lh	$t7,0x18($t1)
/*     a650:	0003c403 */ 	sra	$t8,$v1,0x10
/*     a654:	330effff */ 	andi	$t6,$t8,0xffff
/*     a658:	000fc880 */ 	sll	$t9,$t7,0x2
/*     a65c:	ac99003c */ 	sw	$t9,0x3c($a0)
/*     a660:	8ce7d588 */ 	lw	$a3,%lo(var8005d588)($a3)
/*     a664:	25adde0c */ 	addiu	$t5,$t5,%lo(var8008de0c)
/*     a668:	3c1f8009 */ 	lui	$ra,%hi(var8008de10)
/*     a66c:	01c77821 */ 	addu	$t7,$t6,$a3
/*     a670:	01e6001a */ 	div	$zero,$t7,$a2
/*     a674:	14c00002 */ 	bnez	$a2,.L0000a680
/*     a678:	00000000 */ 	nop
/*     a67c:	0007000d */ 	break	0x7
.L0000a680:
/*     a680:	2401ffff */ 	addiu	$at,$zero,-1
/*     a684:	14c10004 */ 	bne	$a2,$at,.L0000a698
/*     a688:	3c018000 */ 	lui	$at,0x8000
/*     a68c:	15e10002 */ 	bne	$t7,$at,.L0000a698
/*     a690:	00000000 */ 	nop
/*     a694:	0006000d */ 	break	0x6
.L0000a698:
/*     a698:	306effff */ 	andi	$t6,$v1,0xffff
/*     a69c:	0000c810 */ 	mfhi	$t9
/*     a6a0:	01c77821 */ 	addu	$t7,$t6,$a3
/*     a6a4:	0019c400 */ 	sll	$t8,$t9,0x10
/*     a6a8:	01e6001a */ 	div	$zero,$t7,$a2
/*     a6ac:	14c00002 */ 	bnez	$a2,.L0000a6b8
/*     a6b0:	00000000 */ 	nop
/*     a6b4:	0007000d */ 	break	0x7
.L0000a6b8:
/*     a6b8:	2401ffff */ 	addiu	$at,$zero,-1
/*     a6bc:	14c10004 */ 	bne	$a2,$at,.L0000a6d0
/*     a6c0:	3c018000 */ 	lui	$at,0x8000
/*     a6c4:	15e10002 */ 	bne	$t7,$at,.L0000a6d0
/*     a6c8:	00000000 */ 	nop
/*     a6cc:	0006000d */ 	break	0x6
.L0000a6d0:
/*     a6d0:	0000c810 */ 	mfhi	$t9
/*     a6d4:	03191025 */ 	or	$v0,$t8,$t9
/*     a6d8:	ac82001c */ 	sw	$v0,0x1c($a0)
/*     a6dc:	3c018009 */ 	lui	$at,%hi(var8008de08)
/*     a6e0:	ac22de08 */ 	sw	$v0,%lo(var8008de08)($at)
/*     a6e4:	8c830030 */ 	lw	$v1,0x30($a0)
/*     a6e8:	8ca5d58c */ 	lw	$a1,%lo(var8005d58c)($a1)
/*     a6ec:	27ffde10 */ 	addiu	$ra,$ra,%lo(var8008de10)
/*     a6f0:	00037403 */ 	sra	$t6,$v1,0x10
/*     a6f4:	31cfffff */ 	andi	$t7,$t6,0xffff
/*     a6f8:	01e5c021 */ 	addu	$t8,$t7,$a1
/*     a6fc:	0306001a */ 	div	$zero,$t8,$a2
/*     a700:	14c00002 */ 	bnez	$a2,.L0000a70c
/*     a704:	00000000 */ 	nop
/*     a708:	0007000d */ 	break	0x7
.L0000a70c:
/*     a70c:	2401ffff */ 	addiu	$at,$zero,-1
/*     a710:	14c10004 */ 	bne	$a2,$at,.L0000a724
/*     a714:	3c018000 */ 	lui	$at,0x8000
/*     a718:	17010002 */ 	bne	$t8,$at,.L0000a724
/*     a71c:	00000000 */ 	nop
/*     a720:	0006000d */ 	break	0x6
.L0000a724:
/*     a724:	306fffff */ 	andi	$t7,$v1,0xffff
/*     a728:	01e5c021 */ 	addu	$t8,$t7,$a1
/*     a72c:	0000c810 */ 	mfhi	$t9
/*     a730:	8c830044 */ 	lw	$v1,0x44($a0)
/*     a734:	00197400 */ 	sll	$t6,$t9,0x10
/*     a738:	0306001a */ 	div	$zero,$t8,$a2
/*     a73c:	14c00002 */ 	bnez	$a2,.L0000a748
/*     a740:	00000000 */ 	nop
/*     a744:	0007000d */ 	break	0x7
.L0000a748:
/*     a748:	2401ffff */ 	addiu	$at,$zero,-1
/*     a74c:	14c10004 */ 	bne	$a2,$at,.L0000a760
/*     a750:	3c018000 */ 	lui	$at,0x8000
/*     a754:	17010002 */ 	bne	$t8,$at,.L0000a760
/*     a758:	00000000 */ 	nop
/*     a75c:	0006000d */ 	break	0x6
.L0000a760:
/*     a760:	0000c810 */ 	mfhi	$t9
/*     a764:	00037c03 */ 	sra	$t7,$v1,0x10
/*     a768:	01d91025 */ 	or	$v0,$t6,$t9
/*     a76c:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*     a770:	03057021 */ 	addu	$t6,$t8,$a1
/*     a774:	01c6001a */ 	div	$zero,$t6,$a2
/*     a778:	3078ffff */ 	andi	$t8,$v1,0xffff
/*     a77c:	0000c810 */ 	mfhi	$t9
/*     a780:	00197c00 */ 	sll	$t7,$t9,0x10
/*     a784:	ac820030 */ 	sw	$v0,0x30($a0)
/*     a788:	ada20000 */ 	sw	$v0,0x0($t5)
/*     a78c:	14c00002 */ 	bnez	$a2,.L0000a798
/*     a790:	00000000 */ 	nop
/*     a794:	0007000d */ 	break	0x7
.L0000a798:
/*     a798:	2401ffff */ 	addiu	$at,$zero,-1
/*     a79c:	14c10004 */ 	bne	$a2,$at,.L0000a7b0
/*     a7a0:	3c018000 */ 	lui	$at,0x8000
/*     a7a4:	15c10002 */ 	bne	$t6,$at,.L0000a7b0
/*     a7a8:	00000000 */ 	nop
/*     a7ac:	0006000d */ 	break	0x6
.L0000a7b0:
/*     a7b0:	03057021 */ 	addu	$t6,$t8,$a1
/*     a7b4:	01c6001a */ 	div	$zero,$t6,$a2
/*     a7b8:	0000c810 */ 	mfhi	$t9
/*     a7bc:	01f91025 */ 	or	$v0,$t7,$t9
/*     a7c0:	ac820044 */ 	sw	$v0,0x44($a0)
/*     a7c4:	afe20000 */ 	sw	$v0,0x0($ra)
/*     a7c8:	3c188006 */ 	lui	$t8,%hi(var8005dd18)
/*     a7cc:	8f18dd18 */ 	lw	$t8,%lo(var8005dd18)($t8)
/*     a7d0:	14c00002 */ 	bnez	$a2,.L0000a7dc
/*     a7d4:	00000000 */ 	nop
/*     a7d8:	0007000d */ 	break	0x7
.L0000a7dc:
/*     a7dc:	2401ffff */ 	addiu	$at,$zero,-1
/*     a7e0:	14c10004 */ 	bne	$a2,$at,.L0000a7f4
/*     a7e4:	3c018000 */ 	lui	$at,0x8000
/*     a7e8:	15c10002 */ 	bne	$t6,$at,.L0000a7f4
/*     a7ec:	00000000 */ 	nop
/*     a7f0:	0006000d */ 	break	0x6
.L0000a7f4:
/*     a7f4:	3c0a8006 */ 	lui	$t2,%hi(g_ViIs16Bit)
/*     a7f8:	13000038 */ 	beqz	$t8,.L0000a8dc
/*     a7fc:	24ae01af */ 	addiu	$t6,$a1,0x1af
/*     a800:	01c6001a */ 	div	$zero,$t6,$a2
/*     a804:	00007810 */ 	mfhi	$t7
/*     a808:	24b8007b */ 	addiu	$t8,$a1,0x7b
/*     a80c:	14c00002 */ 	bnez	$a2,.L0000a818
/*     a810:	00000000 */ 	nop
/*     a814:	0007000d */ 	break	0x7
.L0000a818:
/*     a818:	2401ffff */ 	addiu	$at,$zero,-1
/*     a81c:	14c10004 */ 	bne	$a2,$at,.L0000a830
/*     a820:	3c018000 */ 	lui	$at,0x8000
/*     a824:	15c10002 */ 	bne	$t6,$at,.L0000a830
/*     a828:	00000000 */ 	nop
/*     a82c:	0006000d */ 	break	0x6
.L0000a830:
/*     a830:	0306001a */ 	div	$zero,$t8,$a2
/*     a834:	00007010 */ 	mfhi	$t6
/*     a838:	000fcc00 */ 	sll	$t9,$t7,0x10
/*     a83c:	24af01b1 */ 	addiu	$t7,$a1,0x1b1
/*     a840:	01e6001a */ 	div	$zero,$t7,$a2
/*     a844:	032e1025 */ 	or	$v0,$t9,$t6
/*     a848:	24ae0079 */ 	addiu	$t6,$a1,0x79
/*     a84c:	14c00002 */ 	bnez	$a2,.L0000a858
/*     a850:	00000000 */ 	nop
/*     a854:	0007000d */ 	break	0x7
.L0000a858:
/*     a858:	2401ffff */ 	addiu	$at,$zero,-1
/*     a85c:	14c10004 */ 	bne	$a2,$at,.L0000a870
/*     a860:	3c018000 */ 	lui	$at,0x8000
/*     a864:	17010002 */ 	bne	$t8,$at,.L0000a870
/*     a868:	00000000 */ 	nop
/*     a86c:	0006000d */ 	break	0x6
.L0000a870:
/*     a870:	0000c010 */ 	mfhi	$t8
/*     a874:	ac820030 */ 	sw	$v0,0x30($a0)
/*     a878:	ada20000 */ 	sw	$v0,0x0($t5)
/*     a87c:	01c6001a */ 	div	$zero,$t6,$a2
/*     a880:	14c00002 */ 	bnez	$a2,.L0000a88c
/*     a884:	00000000 */ 	nop
/*     a888:	0007000d */ 	break	0x7
.L0000a88c:
/*     a88c:	2401ffff */ 	addiu	$at,$zero,-1
/*     a890:	14c10004 */ 	bne	$a2,$at,.L0000a8a4
/*     a894:	3c018000 */ 	lui	$at,0x8000
/*     a898:	15e10002 */ 	bne	$t7,$at,.L0000a8a4
/*     a89c:	00000000 */ 	nop
/*     a8a0:	0006000d */ 	break	0x6
.L0000a8a4:
/*     a8a4:	00007810 */ 	mfhi	$t7
/*     a8a8:	0018cc00 */ 	sll	$t9,$t8,0x10
/*     a8ac:	032f1025 */ 	or	$v0,$t9,$t7
/*     a8b0:	ac820044 */ 	sw	$v0,0x44($a0)
/*     a8b4:	afe20000 */ 	sw	$v0,0x0($ra)
/*     a8b8:	14c00002 */ 	bnez	$a2,.L0000a8c4
/*     a8bc:	00000000 */ 	nop
/*     a8c0:	0007000d */ 	break	0x7
.L0000a8c4:
/*     a8c4:	2401ffff */ 	addiu	$at,$zero,-1
/*     a8c8:	14c10004 */ 	bne	$a2,$at,.L0000a8dc
/*     a8cc:	3c018000 */ 	lui	$at,0x8000
/*     a8d0:	15c10002 */ 	bne	$t6,$at,.L0000a8dc
/*     a8d4:	00000000 */ 	nop
/*     a8d8:	0006000d */ 	break	0x6
.L0000a8dc:
/*     a8dc:	3c018006 */ 	lui	$at,%hi(g_SchedViModesPending)
/*     a8e0:	002c0821 */ 	addu	$at,$at,$t4
/*     a8e4:	24180001 */ 	addiu	$t8,$zero,0x1
/*     a8e8:	ac38ce88 */ 	sw	$t8,%lo(g_SchedViModesPending)($at)
/*     a8ec:	10000006 */ 	b	.L0000a908
/*     a8f0:	8d4ad598 */ 	lw	$t2,%lo(g_ViIs16Bit)($t2)
.L0000a8f4:
/*     a8f4:	3c018006 */ 	lui	$at,%hi(g_SchedViModesPending)
/*     a8f8:	002c0821 */ 	addu	$at,$at,$t4
/*     a8fc:	3c0a8006 */ 	lui	$t2,%hi(g_ViIs16Bit)
/*     a900:	8d4ad598 */ 	lw	$t2,%lo(g_ViIs16Bit)($t2)
/*     a904:	ac20ce88 */ 	sw	$zero,%lo(g_SchedViModesPending)($at)
.L0000a908:
/*     a908:	256b0001 */ 	addiu	$t3,$t3,0x1
/*     a90c:	05610004 */ 	bgez	$t3,.L0000a920
/*     a910:	316e0001 */ 	andi	$t6,$t3,0x1
/*     a914:	11c00002 */ 	beqz	$t6,.L0000a920
/*     a918:	00000000 */ 	nop
/*     a91c:	25cefffe */ 	addiu	$t6,$t6,-2
.L0000a920:
/*     a920:	3c018006 */ 	lui	$at,%hi(g_ViSlot)
/*     a924:	11400006 */ 	beqz	$t2,.L0000a940
/*     a928:	ac2ed5a0 */ 	sw	$t6,%lo(g_ViSlot)($at)
/*     a92c:	3c0f8006 */ 	lui	$t7,%hi(g_RdpCurTask)
/*     a930:	8deff108 */ 	lw	$t7,%lo(g_RdpCurTask)($t7)
/*     a934:	8d390028 */ 	lw	$t9,0x28($t1)
/*     a938:	10000006 */ 	b	.L0000a954
/*     a93c:	adf90058 */ 	sw	$t9,0x58($t7)
.L0000a940:
/*     a940:	3c18800a */ 	lui	$t8,%hi(g_FrameBuffers)
/*     a944:	3c0e8006 */ 	lui	$t6,%hi(g_RdpCurTask)
/*     a948:	8dcef108 */ 	lw	$t6,%lo(g_RdpCurTask)($t6)
/*     a94c:	8f18cac0 */ 	lw	$t8,%lo(g_FrameBuffers)($t8)
/*     a950:	add80058 */ 	sw	$t8,0x58($t6)
.L0000a954:
/*     a954:	3c028009 */ 	lui	$v0,%hi(g_ViFrontIndex)
/*     a958:	24422876 */ 	addiu	$v0,$v0,%lo(g_ViFrontIndex)
/*     a95c:	90590000 */ 	lbu	$t9,0x0($v0)
/*     a960:	3c048006 */ 	lui	$a0,%hi(g_ViBackData)
/*     a964:	8c84d594 */ 	lw	$a0,%lo(g_ViBackData)($a0)
/*     a968:	272f0001 */ 	addiu	$t7,$t9,0x1
/*     a96c:	3c038009 */ 	lui	$v1,%hi(g_ViBackIndex)
/*     a970:	2408002c */ 	addiu	$t0,$zero,0x2c
/*     a974:	24632877 */ 	addiu	$v1,$v1,%lo(g_ViBackIndex)
/*     a978:	906e0000 */ 	lbu	$t6,0x0($v1)
/*     a97c:	3c078006 */ 	lui	$a3,%hi(g_ViDataArray)
/*     a980:	24e7d530 */ 	addiu	$a3,$a3,%lo(g_ViDataArray)
/*     a984:	05e10004 */ 	bgez	$t7,.L0000a998
/*     a988:	31f80001 */ 	andi	$t8,$t7,0x1
/*     a98c:	13000002 */ 	beqz	$t8,.L0000a998
/*     a990:	00000000 */ 	nop
/*     a994:	2718fffe */ 	addiu	$t8,$t8,-2
.L0000a998:
/*     a998:	a0580000 */ 	sb	$t8,0x0($v0)
/*     a99c:	90580000 */ 	lbu	$t8,0x0($v0)
/*     a9a0:	25d90001 */ 	addiu	$t9,$t6,0x1
/*     a9a4:	07210004 */ 	bgez	$t9,.L0000a9b8
/*     a9a8:	332f0001 */ 	andi	$t7,$t9,0x1
/*     a9ac:	11e00002 */ 	beqz	$t7,.L0000a9b8
/*     a9b0:	00000000 */ 	nop
/*     a9b4:	25effffe */ 	addiu	$t7,$t7,-2
.L0000a9b8:
/*     a9b8:	03080019 */ 	multu	$t8,$t0
/*     a9bc:	a06f0000 */ 	sb	$t7,0x0($v1)
/*     a9c0:	3c018006 */ 	lui	$at,%hi(g_ViFrontData)
/*     a9c4:	3c058006 */ 	lui	$a1,%hi(g_ViBackData)
/*     a9c8:	2406002c */ 	addiu	$a2,$zero,0x2c
/*     a9cc:	00007012 */ 	mflo	$t6
/*     a9d0:	00eec821 */ 	addu	$t9,$a3,$t6
/*     a9d4:	ac39d590 */ 	sw	$t9,%lo(g_ViFrontData)($at)
/*     a9d8:	906f0000 */ 	lbu	$t7,0x0($v1)
/*     a9dc:	3c018006 */ 	lui	$at,%hi(g_ViBackData)
/*     a9e0:	01e80019 */ 	multu	$t7,$t0
/*     a9e4:	0000c012 */ 	mflo	$t8
/*     a9e8:	00f87021 */ 	addu	$t6,$a3,$t8
/*     a9ec:	ac2ed594 */ 	sw	$t6,%lo(g_ViBackData)($at)
/*     a9f0:	0c012c5c */ 	jal	bcopy
/*     a9f4:	8ca5d594 */ 	lw	$a1,%lo(g_ViBackData)($a1)
/*     a9f8:	3c038009 */ 	lui	$v1,%hi(g_ViBackIndex)
/*     a9fc:	24632877 */ 	addiu	$v1,$v1,%lo(g_ViBackIndex)
/*     aa00:	90790000 */ 	lbu	$t9,0x0($v1)
/*     aa04:	3c18800a */ 	lui	$t8,%hi(g_FrameBuffers)
/*     aa08:	3c0e8006 */ 	lui	$t6,%hi(g_ViBackData)
/*     aa0c:	00197880 */ 	sll	$t7,$t9,0x2
/*     aa10:	030fc021 */ 	addu	$t8,$t8,$t7
/*     aa14:	8f18cac0 */ 	lw	$t8,%lo(g_FrameBuffers)($t8)
/*     aa18:	8dced594 */ 	lw	$t6,%lo(g_ViBackData)($t6)
/*     aa1c:	3c028006 */ 	lui	$v0,%hi(g_ViReconfigured)
/*     aa20:	2442d59c */ 	addiu	$v0,$v0,%lo(g_ViReconfigured)
/*     aa24:	add80028 */ 	sw	$t8,0x28($t6)
/*     aa28:	8c590000 */ 	lw	$t9,0x0($v0)
/*     aa2c:	53200005 */ 	beqzl	$t9,.L0000aa44
/*     aa30:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*     aa34:	ac400000 */ 	sw	$zero,0x0($v0)
/*     aa38:	0c0027b1 */ 	jal	viBlack
/*     aa3c:	00002025 */ 	or	$a0,$zero,$zero
/*     aa40:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0000aa44:
/*     aa44:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*     aa48:	03e00008 */ 	jr	$ra
/*     aa4c:	00000000 */ 	nop
);
#else
// Mismatch: t2/t3 swapped for slot and g_ViIs16Bit
void viUpdateMode(void)
{
	struct rend_vidat *prevdata;
	f32 x;
	f32 y;
	s32 reg;
	s32 v1;
	s32 tmp;
	s32 slot;
	s32 tmp2;

	if (g_ViFrontData->mode != g_ViBackData->mode) {
		switch (g_ViBackData->mode) {
		case 0:
			osViSetYScale(1);
			osViBlack(true);
			break;
		case 1:
			break;
		case 2:
			break;
		}
	}

	x = (f32)g_ViBackData->x / (f32)g_ViBackData->bufx;
	y = (f32)g_ViBackData->y / (f32)g_ViBackData->bufy;

	if (g_ViBackData->mode == VIMODE_NONE) { \
		y = 1; \
	} \
	slot = g_ViSlot;

#if PAL
	if (g_ViBackData->mode == VIMODE_LO);
	if (1);
	if (1);
	if (1);
#endif

	g_ViXScalesBySlot[slot] = x;
	g_ViYScalesBySlot[slot] = y;

	// 12c
	if (g_ViBackData->mode == VIMODE_LO) {
#if PAL
		if (g_ViIs16Bit) {
			var8008dcc0[slot] = osViModeTable[OS_VI_PAL_LAN1];
		} else {
			var8008dcc0[slot] = osViModeTable[OS_VI_PAL_LAN2];
		}
#else
		if (g_ViIs16Bit) {
			if (osTvType == OS_TV_MPAL) {
				var8008dcc0[slot] = osViModeTable[OS_VI_MPAL_LAN1];
			} else {
				var8008dcc0[slot] = osViModeTable[OS_VI_NTSC_LAN1];
			}
		} else {
			if (osTvType == OS_TV_MPAL) {
				var8008dcc0[slot] = osViModeTable[OS_VI_MPAL_LAN2];
			} else {
				var8008dcc0[slot] = osViModeTable[OS_VI_NTSC_LAN2];
			}
		}
#endif

		var8008dcc0[slot].comRegs.width = g_ViBackData->bufx;
		var8008dcc0[slot].comRegs.xScale = g_ViBackData->bufx * 1024 / 640;
		var8008dcc0[slot].fldRegs[0].origin = g_ViBackData->bufx * 2;
		var8008dcc0[slot].fldRegs[1].origin = g_ViBackData->bufx * 2;

		// 324
#if PAL
		var8008dcc0[slot].fldRegs[0].yScale = 1024;
		var8008dcc0[slot].fldRegs[1].yScale = 1024;
#else
		if (IS4MB()) {
			var8008dcc0[slot].fldRegs[0].yScale = 1024;
			var8008dcc0[slot].fldRegs[1].yScale = 1024;
		} else {
			var8008dcc0[slot].fldRegs[0].yScale = g_ViBackData->bufy * 2048 / 440;
			var8008dcc0[slot].fldRegs[1].yScale = g_ViBackData->bufy * 2048 / 440;
		}
#endif

		// 3ac
		tmp2 = var8008dcc0[slot].comRegs.hStart;
		reg = tmp2;
		var8008de08 = var8008dcc0[slot].comRegs.hStart = ADD_LOW_AND_HI_16_MOD(reg, var8005d588);

		v1 = g_ViBackData->bufy;
		v1 = v1 * 1024 / var8008dcc0[slot].fldRegs[0].yScale;

#if PAL
		if (1);
#endif

		// 458
		if (v1 > 300) {
			v1 >>= 1;
		}

		tmp = (PAL ? 320 : 277) - v1;
		reg = ((tmp + 2) << 16) | (tmp + ((v1 - 2) << 1) + 2);

#if PAL
		reg = ADD_LOW_AND_HI_16_MOD(reg, var8005d58c);
		var8008de0c = var8008dcc0[slot].fldRegs[0].vStart = reg;
		var8008de10 = var8008dcc0[slot].fldRegs[1].vStart = reg;
#else
		var8008de0c = var8008dcc0[slot].fldRegs[0].vStart = ADD_LOW_AND_HI_16_MOD(reg, var8005d58c);
		var8008de10 = var8008dcc0[slot].fldRegs[1].vStart = ADD_LOW_AND_HI_16_MOD(reg, var8005d58c);
#endif

		g_SchedViModesPending[slot] = true;
	} else if (g_ViBackData->mode == VIMODE_HI) {
#if PAL
		var8008dcc0[slot] = osViModeTable[OS_VI_PAL_HAF1];
#else
		if (osTvType == OS_TV_MPAL) {
			var8008dcc0[slot] = osViModeTable[OS_VI_MPAL_HAF1];
		} else {
			var8008dcc0[slot] = osViModeTable[OS_VI_NTSC_HAF1];
		}
#endif

		var8008dcc0[slot].comRegs.width = g_ViBackData->bufx;
		var8008dcc0[slot].comRegs.xScale = g_ViBackData->bufx * 1024 / 640;
		var8008dcc0[slot].fldRegs[0].yScale = 2048;
		var8008dcc0[slot].fldRegs[1].yScale = 2048;
		var8008dcc0[slot].fldRegs[0].origin = g_ViBackData->bufx * 2;
		var8008dcc0[slot].fldRegs[1].origin = g_ViBackData->bufx * 4;

		v1 = var8008dcc0[slot].comRegs.hStart;
		var8008de08 = var8008dcc0[slot].comRegs.hStart = ADD_LOW_AND_HI_16_MOD(v1, var8005d588);

		v1 = var8008dcc0[slot].fldRegs[0].vStart;
		var8008de0c = var8008dcc0[slot].fldRegs[0].vStart = ADD_LOW_AND_HI_16_MOD(v1, var8005d58c);

		v1 = var8008dcc0[slot].fldRegs[1].vStart;
		var8008de10 = var8008dcc0[slot].fldRegs[1].vStart = ADD_LOW_AND_HI_16_MOD(v1, var8005d58c);

		// 7f8
		if (var8005dd18) {
#if PAL
			var8008de0c = var8008dcc0[slot].fldRegs[0].vStart = ((var8005d58c + 506) % 0xffff) << 16 | (var8005d58c + 134) % 0xffff;
			var8008de10 = var8008dcc0[slot].fldRegs[1].vStart = ((var8005d58c + 508) % 0xffff) << 16 | (var8005d58c + 132) % 0xffff;
#else
			var8008de0c = var8008dcc0[slot].fldRegs[0].vStart = ((var8005d58c + 431) % 0xffff) << 16 | (var8005d58c + 123) % 0xffff;
			var8008de10 = var8008dcc0[slot].fldRegs[1].vStart = ((var8005d58c + 433) % 0xffff) << 16 | (var8005d58c + 121) % 0xffff;
#endif
		}

		g_SchedViModesPending[slot] = true;
	} else {
		// 8f4
		g_SchedViModesPending[slot] = false;
	}

	// 908
	slot = (slot + 1) % 2;
	g_ViSlot = slot;

	g_RdpCurTask->framebuffer = g_ViIs16Bit ? g_ViBackData->fb : g_FrameBuffers[0];

	prevdata = g_ViBackData;

	g_ViFrontIndex = (g_ViFrontIndex + 1) % 2;
	g_ViBackIndex = (g_ViBackIndex + 1) % 2;

	g_ViFrontData = g_ViDataArray + g_ViFrontIndex;
	g_ViBackData = g_ViDataArray + g_ViBackIndex;

	bcopy(prevdata, g_ViBackData, sizeof(struct rend_vidat));

	g_ViBackData->fb = g_FrameBuffers[g_ViBackIndex];

	if (g_ViReconfigured) {
		g_ViReconfigured = false;
		viBlack(false);
	}
}
#endif

void viShake(f32 intensity)
{
	if (intensity > 14) {
		intensity = 14;
	}

	if (intensity < 0) {
		intensity = 0;
	}

	g_ViShakeIntensity = intensity;
	g_ViShakeTimer = 10;
}

void viSetMode(s32 mode)
{
	g_ViBackData->mode = mode;

	g_ViBackData->x = g_ViBackData->bufx = g_ViModeWidths[mode];
	g_ViBackData->y = g_ViBackData->bufy = g_ViModeHeights[mode];
}

void viSet16Bit(void)
{
	g_ViIs16Bit = true;
}

void viSet32Bit(void)
{
	g_ViIs16Bit = false;
}

u16 *viGetBackBuffer(void)
{
	return g_ViBackData->fb;
}

u16 *viGetFrontBuffer(void)
{
	return g_ViFrontData->fb;
}

void viSetBackBuffer(u16 *fb)
{
	g_ViBackData->fb = fb;
}

Vp *viGetCurrentPlayerViewport(void)
{
	return &g_Vars.currentplayer->viewport[g_ViBackIndex];
}

u16 viGetPerspScale(void)
{
	return g_ViPerspScale;
}

Gfx *vi0000ab78(Gfx *gdl)
{
	Mtxf sp110;
	Mtxf spd0;
	Mtxf sp90;
	Mtxf sp50;
	Mtx *sp4c;
	Mtx *sp48;
	u16 sp46;

	guPerspectiveF(sp110.m, &sp46, g_ViBackData->fovy, g_ViBackData->aspect, g_ViBackData->znear, g_ViBackData->zfar + g_ViBackData->zfar, 1);
	mtx4Copy(camGetWorldToScreenMtxf(), &sp90);

	sp90.m[3][0] = 0;
	sp90.m[3][1] = 0;
	sp90.m[3][2] = 0;

	mtx4MultMtx4(&sp110, &sp90, &spd0);
	sp4c = gfxAllocateMatrix();
	guMtxF2L(spd0.m, sp4c);

	mtx4LoadIdentity(&sp50);
	sp48 = gfxAllocateMatrix();
	guMtxF2L(sp50.m, sp48);

	gSPMatrix(gdl++, OS_K0_TO_PHYSICAL(sp4c), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
	gSPMatrix(gdl++, OS_K0_TO_PHYSICAL(sp48), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	gSPPerspNormalize(gdl++, sp46);

	return gdl;
}

Gfx *vi0000aca4(Gfx *gdl, f32 znear, f32 zfar)
{
	u16 scale;
	Mtxf tmp;
	Mtx *mtx = gfxAllocateMatrix();

	guPerspectiveF(tmp.m, &scale, g_ViBackData->fovy, g_ViBackData->aspect, znear, zfar, 1);
	guMtxF2L(tmp.m, mtx);

	gSPMatrix(gdl++, OS_K0_TO_PHYSICAL(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
	gSPPerspNormalize(gdl++, scale);

	return gdl;
}

Gfx *vi0000ad5c(Gfx *gdl, Vp *vp)
{
	vp[g_ViBackIndex].vp.vscale[0] = g_ViBackData->viewx * 2;
	vp[g_ViBackIndex].vp.vtrans[0] = g_ViBackData->viewx * 2 + g_ViBackData->viewleft * 4;

	vp[g_ViBackIndex].vp.vscale[1] = g_ViBackData->viewy * 2;
	vp[g_ViBackIndex].vp.vtrans[1] = g_ViBackData->viewy * 2 + g_ViBackData->viewtop * 4;

	gSPViewport(gdl++, OS_K0_TO_PHYSICAL(&vp[g_ViBackIndex]));

	var80092870 = gfxAllocateMatrix();
	guPerspectiveF(var80092830.m, &g_ViPerspScale, g_ViBackData->fovy, g_ViBackData->aspect, g_ViBackData->znear, g_ViBackData->zfar, 1);
	guMtxF2L(var80092830.m, var80092870);

	gSPMatrix(gdl++, OS_K0_TO_PHYSICAL(var80092870), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
	gSPPerspNormalize(gdl++, g_ViPerspScale);

	camSetPerspectiveMtxL(var80092870);
	camSetMtxF1754(&var80092830);

	return gdl;
}

Gfx *vi0000af00(Gfx *gdl, Vp *vp)
{
	vp[g_ViBackIndex].vp.vscale[0] = g_ViBackData->viewx * 2;
	vp[g_ViBackIndex].vp.vtrans[0] = g_ViBackData->viewx * 2 + g_ViBackData->viewleft * 4;

	vp[g_ViBackIndex].vp.vscale[1] = g_ViBackData->viewy * 2;
	vp[g_ViBackIndex].vp.vtrans[1] = g_ViBackData->viewy * 2 + g_ViBackData->viewtop * 4;

	vp[g_ViBackIndex].vp.vscale[2] = 511;
	vp[g_ViBackIndex].vp.vtrans[2] = 511;

	vp[g_ViBackIndex].vp.vscale[3] = 0;
	vp[g_ViBackIndex].vp.vtrans[3] = 0;

	gSPViewport(gdl++, OS_K0_TO_PHYSICAL(&vp[g_ViBackIndex]));

	var80092870 = gfxAllocateMatrix();
	guPerspectiveF(var80092830.m, &g_ViPerspScale, g_ViBackData->fovy, g_ViBackData->aspect, g_ViBackData->znear, g_ViBackData->zfar, 1);
	guMtxF2L(var80092830.m, var80092870);

	gSPMatrix(gdl++, OS_K0_TO_PHYSICAL(var80092870), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
	gSPPerspNormalize(gdl++, g_ViPerspScale);

	camSetPerspectiveMtxL(var80092870);
	camSetMtxF1754(&var80092830);

	return gdl;
}

Gfx *vi0000b0e8(Gfx *gdl, f32 fovy, f32 aspect)
{
	Mtxf tmp;
	Mtx *mtx = gfxAllocateMatrix();

	guPerspectiveF(tmp.m, &g_ViPerspScale, fovy, aspect, g_ViBackData->znear, g_ViBackData->zfar, 1);
	guMtxF2L(tmp.m, mtx);

	gSPMatrix(gdl++, OS_K0_TO_PHYSICAL(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
	gSPPerspNormalize(gdl++, g_ViPerspScale);

	return gdl;
}

Gfx *vi0000b1a8(Gfx *gdl)
{
	return vi0000ad5c(gdl, &g_Vars.currentplayer->viewport[0]);
}

Gfx *vi0000b1d0(Gfx *gdl)
{
	gdl = vi0000b1a8(gdl);

	if (g_ViIs16Bit) {
		gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, g_ViBackData->bufx, OS_K0_TO_PHYSICAL(g_ViBackData->fb));
	} else {
		gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_32b, g_ViBackData->bufx, OS_K0_TO_PHYSICAL(g_FrameBuffers[0]));
	}

	return gdl;
}

Gfx *vi0000b280(Gfx *gdl)
{
	if (g_ViBackData->usezbuf) {
		gdl = mblur0f1762ac(gdl);
		gdl = mblur0f1763f4(gdl);
	}

	return gdl;
}

Gfx *viFillBuffer(Gfx *gdl)
{
	gDPSetCycleType(gdl++, G_CYC_FILL);
	gDPFillRectangle(gdl++, 0, 0, g_ViBackData->bufx - 1, g_ViBackData->bufy - 1);
	gDPPipeSync(gdl++);

	return gdl;
}

Gfx *viRenderViewportEdges(Gfx *gdl)
{
	gDPSetCycleType(gdl++, G_CYC_FILL);
	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, viGetWidth(), viGetHeight());
	gDPSetFillColor(gdl++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));

#if VERSION >= VERSION_NTSC_1_0
	if (PLAYERCOUNT() == 1
			|| ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
				&& playerHasSharedViewport() && g_Vars.currentplayernum == 0))
#else
	if (PLAYERCOUNT() == 1
			|| ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
				&& (
					(g_InCutscene && !g_MainIsEndscreen) || menuGetRoot() == MENUROOT_COOPCONTINUE
					) && g_Vars.currentplayernum == 0))
#endif
	{
		// Single viewport
		if (viGetViewTop() > 0) {
			// Fill above
			gDPFillRectangle(gdl++, 0, 0, viGetWidth() - 1, viGetViewTop() - 1);
			gDPPipeSync(gdl++);
		}

		if (viGetViewTop() + viGetViewHeight() < viGetHeight()) {
			// Fill below
			gDPFillRectangle(gdl++,
					0, viGetViewTop() + viGetViewHeight(),
					viGetWidth() - 1, viGetHeight() - 1);
			gDPPipeSync(gdl++);
		}
	} else {
		if (g_Vars.currentplayerindex == 0) {
			s32 topplayernum = 0;
			s32 bottomplayernum = 0;
			s32 tmpplayernum = 0;

			if (PLAYERCOUNT() == 2) {
				bottomplayernum = 1;
				tmpplayernum = 1;
			} else if (PLAYERCOUNT() >= 3) {
				bottomplayernum = 2;
				tmpplayernum = 2;
			}

			if (g_Vars.players[topplayernum]->viewtop > 0) {
				// Fill above all viewports - full width
				gDPFillRectangle(gdl++, 0, 0, viGetWidth() - 1, g_Vars.players[topplayernum]->viewtop - 1);
				gDPPipeSync(gdl++);
			}

			if (g_Vars.players[bottomplayernum]->viewtop + g_Vars.players[bottomplayernum]->viewheight < viGetHeight()) {
				// Fill below all viewports - full width
				gDPFillRectangle(gdl++,
						0, g_Vars.players[bottomplayernum]->viewtop + g_Vars.players[bottomplayernum]->viewheight,
						viGetWidth() - 1, viGetHeight() - 1);
				gDPPipeSync(gdl++);
			}

			// Horizontal middle line
			gDPFillRectangle(gdl++,
					0, g_Vars.players[tmpplayernum]->viewtop - 1,
					viGetWidth() - 1, g_Vars.players[tmpplayernum]->viewtop - 1);
			gDPPipeSync(gdl++);

			if (PLAYERCOUNT() >= 3 ||
					(PLAYERCOUNT() == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || g_Vars.fourmeg2player))) {
				if (PLAYERCOUNT() == 2) {
					tmpplayernum = 0;
				}

				// Vertical middle line
				gDPFillRectangle(gdl++,
						g_Vars.players[tmpplayernum]->viewleft + g_Vars.players[tmpplayernum]->viewwidth, 0,
						g_Vars.players[tmpplayernum]->viewleft + g_Vars.players[tmpplayernum]->viewwidth, viGetHeight() - 1);
				gDPPipeSync(gdl++);
			}

			if (PLAYERCOUNT() == 3) {
				// Blank square in P4 spot
				gDPFillRectangle(gdl++,
						g_Vars.players[tmpplayernum]->viewleft + g_Vars.players[tmpplayernum]->viewwidth + 1, g_Vars.players[tmpplayernum]->viewtop,
						viGetWidth() - 1, viGetHeight() - 1);
				gDPPipeSync(gdl++);
			}
		}
	}

	return gdl;
}

#if VERSION < VERSION_NTSC_1_0
void vi0000bd44nb(s32 arg0)
{
	var8005d58c = arg0;
}

s32 vi0000bd50nb(void)
{
	return var8005d58c;
}

void vi0000bd5cnb(s32 arg0)
{
	var8005d588 = arg0;
}

s32 vi0000bd68nb(void)
{
	return var8005d588;
}
#endif

void viSetBufSize(s16 width, s16 height)
{
	g_ViBackData->bufx = width;
	g_ViBackData->bufy = height;
}

s16 viGetBufWidth(void)
{
	return g_ViBackData->bufx;
}

s16 viGetBufHeight(void)
{
	return g_ViBackData->bufy;
}

void viSetSize(s16 width, s16 height)
{
	g_ViBackData->x = width;
	g_ViBackData->y = height;
}

s16 viGetWidth(void)
{
	return g_ViBackData->x;
}

s16 viGetHeight(void)
{
	return g_ViBackData->y;
}

void viSetViewSize(s16 width, s16 height)
{
	g_ViBackData->viewx = width;
	g_ViBackData->viewy = height;

	camSetScreenSize(g_ViBackData->viewx, g_ViBackData->viewy);
	camSetScale();
}

s16 viGetViewWidth(void)
{
	return g_ViBackData->viewx;
}

s16 viGetViewHeight(void)
{
	return g_ViBackData->viewy;
}

void viSetViewPosition(s16 left, s16 top)
{
	g_ViBackData->viewleft = left;
	g_ViBackData->viewtop = top;

	camSetScreenPosition(g_ViBackData->viewleft, g_ViBackData->viewtop);
}

s16 viGetViewLeft(void)
{
	return g_ViBackData->viewleft;
}

s16 viGetViewTop(void)
{
	return g_ViBackData->viewtop;
}

void viSetUseZBuf(bool use)
{
	g_ViBackData->usezbuf = use;
}

void viSetFovY(f32 fovy)
{
	g_ViBackData->fovy = fovy;

	camSetPerspective(g_ViBackData->znear, g_ViBackData->fovy, g_ViBackData->aspect);
	camSetScale();
}

void viSetAspect(f32 aspect)
{
	g_ViBackData->aspect = aspect;

	camSetPerspective(g_ViBackData->znear, g_ViBackData->fovy, g_ViBackData->aspect);
	camSetScale();
}

f32 viGetAspect(void)
{
	return g_ViBackData->aspect;
}

void viSetFovAspectAndSize(f32 fovy, f32 aspect, s16 width, s16 height)
{
	g_ViBackData->fovy = fovy;
	g_ViBackData->aspect = aspect;
	g_ViBackData->viewx = width;
	g_ViBackData->viewy = height;

	camSetScreenSize(g_ViBackData->viewx, g_ViBackData->viewy);
	camSetPerspective(g_ViBackData->znear, g_ViBackData->fovy, g_ViBackData->aspect);
	camSetScale();
}

f32 viGetFovY(void)
{
	return g_ViBackData->fovy;
}

void viSetZRange(f32 near, f32 far)
{
	g_ViBackData->znear = near;
	g_ViBackData->zfar = far;

	camSetPerspective(g_ViBackData->znear, g_ViBackData->fovy, g_ViBackData->aspect);
	camSetScale();
}

void viGetZRange(struct zrange *zrange)
{
	zrange->near = g_ViBackData->znear;
	zrange->far = g_ViBackData->zfar;
}

Gfx *viSetFillColour(Gfx *gdl, s32 r, s32 g, s32 b)
{
	if (g_ViIs16Bit) {
		gDPSetFillColor(gdl++, (GPACK_RGBA5551(r, g, b, 1) << 16) | GPACK_RGBA5551(r, g, b, 1));
	} else {
		gDPSetFillColor(gdl++, r << 24 | g << 16 | b << 8 | 0xff);
	}

	return gdl;
}

void viGrabJpg16(void)
{
	// empty
}

void viGrabJpg32(void)
{
	// empty
}

void viGrabRgb16(void)
{
	// empty
}

void viGrabRgb32(void)
{
	// empty
}
