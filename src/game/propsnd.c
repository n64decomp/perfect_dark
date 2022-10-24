#include <ultra64.h>
#include "constants.h"
#include "game/chraicommands.h"
#include "game/dlights.h"
#include "game/propsnd.h"
#include "game/atan2f.h"
#include "game/hudmsg.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

#if VERSION < VERSION_NTSC_1_0
const char var7f1a5720nb[] = "SND : Stop -> Prop=%x, Id=%d\n";
#endif

const char var7f1ab400[] = "Propsnd : USING TIME 60\n";
const char var7f1ab41c[] = "PS_AUTO : Un-Pausing %d\n";

#if VERSION < VERSION_NTSC_1_0
const char var7f1a5778nb[] = "PS_AUTO : Pausing %d\n";
const char var7f1a5790nb[] = "SND : Propsound needs play : Id %d is flaged g\n";
const char var7f1a57c0nb[] = "AISND : Channel %d - %s";
const char var7f1a57d8nb[] = "FREE";
const char var7f1a57e0nb[] = "IN USE";
#endif

const char var7f1ab438[] = "Propsnd : Using %d of %d (Peek = %d of %d)";

#if VERSION >= VERSION_NTSC_1_0
const char var7f1ab464[] = "AISOUND: aisoundnewtypeflags - Channel %d -> Playing sound number id=%d(%x)\n";
const char var7f1ab4b4[] = "AISOUND: PSTYPE_MARKER - Channel %d -> Playing sound number id=%d(%x)\n";
const char var7f1ab4fc[] = "AISOUND: PSTYPE_MARKER - Channel %d -> Playing sound number id=%d(%x)\n";
#else
const char var7f1a5814nb[] = "SND : Start -> Prop=%x, Id=%d, Vol=%d, Flags=%d, Type=%d\n";
const char var7f1a5850nb[] = "AISOUND: Channel %d -> Playing sound number id=%d(%x))\n";
#endif

const char var7f1ab544[] = "AISOUND: CUTSCENE -> Playing sound number id=%d(%x))\n";

#if VERSION >= VERSION_NTSC_1_0
const char var7f1ab57c[] = "AISOUND: Channel %d -> Playing sound number id=%d(%x), Prop=%x, Flags=%x, Type=%d, Zero=%d\n";
const char var7f1ab5d8[] = "AISOUND: Channel %d -> Playing sound number id=%d(%x), Prop=%x, Flags=%x, Type=%d\n";
#else
const char var7f1ab58c0nb[] = "AISOUND: DONTCARE -> Playing sound number id=%d(%x))\n";
const char var7f1ab58f8nb[] = "AISOUND: Channel %d -> Playing sound number id=%d(%x), Prop=%x\n";
const char var7f1ab5938nb[] = "SERIOUS: Existing ai sound number %d (Sound id=%d(%x)) : KILLING\n";
#endif

const char var7f1ab62c[] = "AISOUND: CUTSCENE -> Stopping all cutscene sounds\n";
const char var7f1ab660[] = "AISOUND: Stop sound channel %d\n";
const char var7f1ab680[] = "AISOUND: Channel %d -> Setting params : Vol=%d, Pad=%d, Prop=%x, Time=%d, Far=%d, Silence=%d, Flags=%u\n";
const char var7f1ab6e8[] = "AISOUND : This channel has a marker -> Shall start and use ID = %d(%x)\n";

struct audiochannel *g_AudioChannels = NULL;

#if VERSION >= VERSION_NTSC_1_0
u32 g_AudioPrevUuid = 0x00000000;
#endif

s8 var8006ae18 = 0;
s8 var8006ae1c = 0;
s8 var8006ae20 = 0;
s8 var8006ae24 = 0;
s8 var8006ae28 = 0;
u32 var8006ae2c = 0x00000000;
u32 var8006ae30 = 0x00000000;
u32 var8006ae34 = 0x00000000;
u32 var8006ae38 = 0x00000000;
bool g_PropsndPrintChannels = false;

u32 var8006ae40 = 0x00000000;
bool var8006ae44 = false;
u32 var8006ae48 = 0x00000001;
u32 var8006ae4c = 0x00000000;
s16 var8006ae50 = -1;
u32 var8006ae54 = 0x000003e7;

bool func0f092610(struct prop *prop, s32 arg1)
{
	s32 i;

	for (i = 0; i < (IS4MB() ? 30 : 40); i++) {
		if ((g_AudioChannels[i].flags & AUDIOCHANNELFLAG_IDLE) == 0
				&& prop == g_AudioChannels[i].prop
				&& (arg1 == g_AudioChannels[i].unk28 || arg1 == 1)) {
			return true;
		}
	}

	return false;
}

void func0f0926bc(struct prop *prop, s32 arg1, u16 arg2)
{
	s32 i;

	for (i = 0; i < (IS4MB() ? 30 : 40); i++) {
		struct audiochannel *channel = &g_AudioChannels[i];

		if ((channel->flags & AUDIOCHANNELFLAG_IDLE) == 0 && channel->prop == prop) {
			if (!channel->flags || !arg2 || (arg2 & channel->flags)) {
				if (channel->unk28 == arg1 || arg1 == 1) {
					func0f092a98(i);
				}
			}
		}
	}
}

s32 func0f0927d4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4)
{
	s32 result = 0;

	if (arg0 < arg3) {
		if (arg1 > 5501) {
			arg1 = 5501;
		}

		if (arg2 > 5801) {
			arg2 = 5801;
		}

		if (arg3 > 6000) {
			arg3 = 6000;
		}

		if (arg1 > arg0) {
			result = arg4;
		} else {
			if (arg2 > arg0) {
				result = arg4 - (s32)(sqrtf((arg0 - arg1) / (arg2 - arg1)) * (arg4 - 1000.0f));
			} else {
				result = (((arg3 - arg0) * 1000.0f) / (arg3 - arg2));
			}
		}
	}

	if (result > 0x7fff) {
		result = 0x7fff;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (result < 40) {
		result = 0;
	}
#endif

	return result;
}

s32 channelGetUnk06(s32 channelnum)
{
	return (channelnum >= 0 && channelnum <= 7) ? g_AudioChannels[channelnum].unk06 : 0;
}

void propsnd0f09294c(struct prop *prop, s16 soundnum, s32 arg2)
{
	s32 i;

	if (propsnd0f0946b0(&prop->pos, 400, 2500, 3000, prop->rooms, soundnum, 0x7fff, 0)) {
		// Return if this prop is already playing a sound
		for (i = 8; i < (IS4MB() ? 30 : 40); i++) {
			if ((g_AudioChannels[i].flags & AUDIOCHANNELFLAG_IDLE) == 0
					&& g_AudioChannels[i].prop == prop
					&& g_AudioChannels[i].unk28 == arg2) {
				return;
			}
		}

		propsnd0f0939f8(NULL, prop, soundnum, -1, -1, 2, 0, arg2, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
	}
}

void func0f092a98(s32 channelnum)
{
	struct audiochannel *channel = &g_AudioChannels[channelnum];

#if VERSION >= VERSION_NTSC_1_0
	channel->flags2 |= 0x80;
#endif

	if (channel->flags & AUDIOCHANNELFLAG_FORHUDMSG) {
		hudmsgsHideByChannel(channelnum);
	}

	if (channel->flags & AUDIOCHANNELFLAG_FORPROP) {
		propDecrementSoundCount(channel->prop);
	}

	if ((channel->flags & AUDIOCHANNELFLAG_ISMP3)) {
		snd0000fbc4(channel->soundnum26);
	} else if (channel->audiohandle && sndGetState(channel->audiohandle) != AL_STOPPED) {
		audioStop(channel->audiohandle);
	}

#if VERSION < VERSION_NTSC_1_0
	channel->flags = AUDIOCHANNELFLAG_IDLE;
#endif
}

void propsndPrintChannel(struct audiochannel *channel)
{
	s32 i;

	for (i = 0; channel->rooms[i] != -1; i++) {
		// empty
	}
}

s32 propsndGetSubtitleOpacity(s32 channelnum)
{
	if (channelnum == -1) {
		return 1;
	}

	if ((g_AudioChannels[channelnum].flags & AUDIOCHANNELFLAG_IDLE) == 0) {
		s32 value = g_AudioChannels[channelnum].unk06;

		if (value == -1 || value > 200) {
			s32 tmp = g_AudioChannels[channelnum].unk06 - 200;
			s32 opacity = tmp * 255 / 15800;

			if (opacity > 255) {
				opacity = 255;
			}

			return opacity;
		}
	}

	return 0;
}

#if MATCHING
#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel propsndTickChannel
.late_rodata
glabel var7f1ab73c
.word 0x392ec33e
glabel var7f1ab740
.word 0x3c23d70a
.text
/*  f093994:	3c188007 */ 	lui	$t8,0x8007
/*  f093998:	8f18b410 */ 	lw	$t8,-0x4bf0($t8)
/*  f09399c:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f0939a0:	00047900 */ 	sll	$t7,$a0,0x4
/*  f0939a4:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f0939a8:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f0939ac:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0939b0:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0939b4:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f0939b8:	01f88021 */ 	addu	$s0,$t7,$t8
/*  f0939bc:	96190032 */ 	lhu	$t9,0x32($s0)
/*  f0939c0:	00807025 */ 	move	$t6,$a0
/*  f0939c4:	332a0080 */ 	andi	$t2,$t9,0x80
/*  f0939c8:	554001f7 */ 	bnezl	$t2,.JF0f0941a8
/*  f0939cc:	860e0028 */ 	lh	$t6,0x28($s0)
/*  f0939d0:	860b0028 */ 	lh	$t3,0x28($s0)
/*  f0939d4:	2401000b */ 	li	$at,0xb
/*  f0939d8:	516101f3 */ 	beql	$t3,$at,.JF0f0941a8
/*  f0939dc:	860e0028 */ 	lh	$t6,0x28($s0)
/*  f0939e0:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f0939e4:	50800006 */ 	beqzl	$a0,.JF0f093a00
/*  f0939e8:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f0939ec:	0c00ccc0 */ 	jal	sndGetState
/*  f0939f0:	00000000 */ 	nop
/*  f0939f4:	54400010 */ 	bnezl	$v0,.JF0f093a38
/*  f0939f8:	8e020050 */ 	lw	$v0,0x50($s0)
/*  f0939fc:	96030030 */ 	lhu	$v1,0x30($s0)
.JF0f093a00:
/*  f093a00:	306c0002 */ 	andi	$t4,$v1,0x2
/*  f093a04:	5580000c */ 	bnezl	$t4,.JF0f093a38
/*  f093a08:	8e020050 */ 	lw	$v0,0x50($s0)
/*  f093a0c:	306d1000 */ 	andi	$t5,$v1,0x1000
/*  f093a10:	55a00009 */ 	bnezl	$t5,.JF0f093a38
/*  f093a14:	8e020050 */ 	lw	$v0,0x50($s0)
/*  f093a18:	306e0010 */ 	andi	$t6,$v1,0x10
/*  f093a1c:	51c001e2 */ 	beqzl	$t6,.JF0f0941a8
/*  f093a20:	860e0028 */ 	lh	$t6,0x28($s0)
/*  f093a24:	0c003a5c */ 	jal	sndIsPlayingMp3
/*  f093a28:	00000000 */ 	nop
/*  f093a2c:	504001de */ 	beqzl	$v0,.JF0f0941a8
/*  f093a30:	860e0028 */ 	lh	$t6,0x28($s0)
/*  f093a34:	8e020050 */ 	lw	$v0,0x50($s0)
.JF0f093a38:
/*  f093a38:	00002025 */ 	move	$a0,$zero
/*  f093a3c:	00004025 */ 	move	$t0,$zero
/*  f093a40:	10400004 */ 	beqz	$v0,.JF0f093a54
/*  f093a44:	96050032 */ 	lhu	$a1,0x32($s0)
/*  f093a48:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f093a4c:	10000006 */ 	b	.JF0f093a68
/*  f093a50:	24480028 */ 	addiu	$t0,$v0,0x28
.JF0f093a54:
/*  f093a54:	860f0064 */ 	lh	$t7,0x64($s0)
/*  f093a58:	2401ffff */ 	li	$at,-1
/*  f093a5c:	51e10003 */ 	beql	$t7,$at,.JF0f093a6c
/*  f093a60:	8e020054 */ 	lw	$v0,0x54($s0)
/*  f093a64:	26080064 */ 	addiu	$t0,$s0,0x64
.JF0f093a68:
/*  f093a68:	8e020054 */ 	lw	$v0,0x54($s0)
.JF0f093a6c:
/*  f093a6c:	3c09800a */ 	lui	$t1,0x800a
/*  f093a70:	2529a630 */ 	addiu	$t1,$t1,-22992
/*  f093a74:	10400002 */ 	beqz	$v0,.JF0f093a80
/*  f093a78:	30aa0010 */ 	andi	$t2,$a1,0x10
/*  f093a7c:	00402025 */ 	move	$a0,$v0
.JF0f093a80:
/*  f093a80:	913804e3 */ 	lbu	$t8,0x4e3($t1)
/*  f093a84:	13000006 */ 	beqz	$t8,.JF0f093aa0
/*  f093a88:	00000000 */ 	nop
/*  f093a8c:	30b90020 */ 	andi	$t9,$a1,0x20
/*  f093a90:	13200003 */ 	beqz	$t9,.JF0f093aa0
/*  f093a94:	00000000 */ 	nop
/*  f093a98:	10000039 */ 	b	.JF0f093b80
/*  f093a9c:	a6000004 */ 	sh	$zero,0x4($s0)
.JF0f093aa0:
/*  f093aa0:	11400007 */ 	beqz	$t2,.JF0f093ac0
/*  f093aa4:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f093aa8:	306b1000 */ 	andi	$t3,$v1,0x1000
/*  f093aac:	516001f2 */ 	beqzl	$t3,.JF0f094278
/*  f093ab0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f093ab4:	860c0010 */ 	lh	$t4,0x10($s0)
/*  f093ab8:	10000031 */ 	b	.JF0f093b80
/*  f093abc:	a60c0004 */ 	sh	$t4,0x4($s0)
.JF0f093ac0:
/*  f093ac0:	5080001f */ 	beqzl	$a0,.JF0f093b40
/*  f093ac4:	306a0020 */ 	andi	$t2,$v1,0x20
/*  f093ac8:	5100001d */ 	beqzl	$t0,.JF0f093b40
/*  f093acc:	306a0020 */ 	andi	$t2,$v1,0x20
/*  f093ad0:	306d8000 */ 	andi	$t5,$v1,0x8000
/*  f093ad4:	11a00003 */ 	beqz	$t5,.JF0f093ae4
/*  f093ad8:	01001025 */ 	move	$v0,$t0
/*  f093adc:	10000001 */ 	b	.JF0f093ae4
/*  f093ae0:	00001025 */ 	move	$v0,$zero
.JF0f093ae4:
/*  f093ae4:	860e002c */ 	lh	$t6,0x2c($s0)
/*  f093ae8:	3c018007 */ 	lui	$at,0x8007
/*  f093aec:	2619004c */ 	addiu	$t9,$s0,0x4c
/*  f093af0:	a42eb450 */ 	sh	$t6,-0x4bb0($at)
/*  f093af4:	8e07003c */ 	lw	$a3,0x3c($s0)
/*  f093af8:	8e060038 */ 	lw	$a2,0x38($s0)
/*  f093afc:	8e050034 */ 	lw	$a1,0x34($s0)
/*  f093b00:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f093b04:	860f0026 */ 	lh	$t7,0x26($s0)
/*  f093b08:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f093b0c:	86180010 */ 	lh	$t8,0x10($s0)
/*  f093b10:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f093b14:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f093b18:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f093b1c:	0fc2550c */ 	jal	propsnd0f0946b0
/*  f093b20:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f093b24:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f093b28:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f093b2c:	3c09800a */ 	lui	$t1,0x800a
/*  f093b30:	2529a630 */ 	addiu	$t1,$t1,-22992
/*  f093b34:	a6020004 */ 	sh	$v0,0x4($s0)
/*  f093b38:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f093b3c:	306a0020 */ 	andi	$t2,$v1,0x20
.JF0f093b40:
/*  f093b40:	1540000f */ 	bnez	$t2,.JF0f093b80
/*  f093b44:	00000000 */ 	nop
/*  f093b48:	c604004c */ 	lwc1	$f4,0x4c($s0)
/*  f093b4c:	8e050034 */ 	lw	$a1,0x34($s0)
/*  f093b50:	8e060038 */ 	lw	$a2,0x38($s0)
/*  f093b54:	8e07003c */ 	lw	$a3,0x3c($s0)
/*  f093b58:	306b0800 */ 	andi	$t3,$v1,0x800
/*  f093b5c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f093b60:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f093b64:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f093b68:	0fc256be */ 	jal	propsnd0f094d78
/*  f093b6c:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f093b70:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f093b74:	3c09800a */ 	lui	$t1,0x800a
/*  f093b78:	2529a630 */ 	addiu	$t1,$t1,-22992
/*  f093b7c:	a602000a */ 	sh	$v0,0xa($s0)
.JF0f093b80:
/*  f093b80:	5100000a */ 	beqzl	$t0,.JF0f093bac
/*  f093b84:	240e0001 */ 	li	$t6,0x1
/*  f093b88:	850c0000 */ 	lh	$t4,0x0($t0)
/*  f093b8c:	2401ffff */ 	li	$at,-1
/*  f093b90:	51810006 */ 	beql	$t4,$at,.JF0f093bac
/*  f093b94:	240e0001 */ 	li	$t6,0x1
/*  f093b98:	240d0001 */ 	li	$t5,0x1
/*  f093b9c:	a600000c */ 	sh	$zero,0xc($s0)
/*  f093ba0:	10000004 */ 	b	.JF0f093bb4
/*  f093ba4:	a20d001a */ 	sb	$t5,0x1a($s0)
/*  f093ba8:	240e0001 */ 	li	$t6,0x1
.JF0f093bac:
/*  f093bac:	a600000c */ 	sh	$zero,0xc($s0)
/*  f093bb0:	a20e001a */ 	sb	$t6,0x1a($s0)
.JF0f093bb4:
/*  f093bb4:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f093bb8:	51e00026 */ 	beqzl	$t7,.JF0f093c54
/*  f093bbc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f093bc0:	c6000044 */ 	lwc1	$f0,0x44($s0)
/*  f093bc4:	44803000 */ 	mtc1	$zero,$f6
/*  f093bc8:	00000000 */ 	nop
/*  f093bcc:	4600303c */ 	c.lt.s	$f6,$f0
/*  f093bd0:	00000000 */ 	nop
/*  f093bd4:	4502001f */ 	bc1fl	.JF0f093c54
/*  f093bd8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f093bdc:	c6020048 */ 	lwc1	$f2,0x48($s0)
/*  f093be0:	44804000 */ 	mtc1	$zero,$f8
/*  f093be4:	00000000 */ 	nop
/*  f093be8:	4608103c */ 	c.lt.s	$f2,$f8
/*  f093bec:	00000000 */ 	nop
/*  f093bf0:	45020004 */ 	bc1fl	.JF0f093c04
/*  f093bf4:	8e180020 */ 	lw	$t8,0x20($s0)
/*  f093bf8:	10000018 */ 	b	.JF0f093c5c
/*  f093bfc:	46000486 */ 	mov.s	$f18,$f0
/*  f093c00:	8e180020 */ 	lw	$t8,0x20($s0)
.JF0f093c04:
/*  f093c04:	44802000 */ 	mtc1	$zero,$f4
/*  f093c08:	44985000 */ 	mtc1	$t8,$f10
/*  f093c0c:	00000000 */ 	nop
/*  f093c10:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f093c14:	460c203c */ 	c.lt.s	$f4,$f12
/*  f093c18:	00000000 */ 	nop
/*  f093c1c:	4500000a */ 	bc1f	.JF0f093c48
/*  f093c20:	00000000 */ 	nop
/*  f093c24:	8d390034 */ 	lw	$t9,0x34($t1)
/*  f093c28:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f093c2c:	44994000 */ 	mtc1	$t9,$f8
/*  f093c30:	00000000 */ 	nop
/*  f093c34:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f093c38:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f093c3c:	460c2203 */ 	div.s	$f8,$f4,$f12
/*  f093c40:	10000006 */ 	b	.JF0f093c5c
/*  f093c44:	46081480 */ 	add.s	$f18,$f2,$f8
.JF0f093c48:
/*  f093c48:	10000004 */ 	b	.JF0f093c5c
/*  f093c4c:	46000486 */ 	mov.s	$f18,$f0
/*  f093c50:	3c01bf80 */ 	lui	$at,0xbf80
.JF0f093c54:
/*  f093c54:	44819000 */ 	mtc1	$at,$f18
/*  f093c58:	00000000 */ 	nop
.JF0f093c5c:
/*  f093c5c:	86040006 */ 	lh	$a0,0x6($s0)
/*  f093c60:	2401ffff */ 	li	$at,-1
/*  f093c64:	8608000c */ 	lh	$t0,0xc($s0)
/*  f093c68:	14810003 */ 	bne	$a0,$at,.JF0f093c78
/*  f093c6c:	00802825 */ 	move	$a1,$a0
/*  f093c70:	10000050 */ 	b	.JF0f093db4
/*  f093c74:	86050004 */ 	lh	$a1,0x4($s0)
.JF0f093c78:
/*  f093c78:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f093c7c:	0442001a */ 	bltzl	$v0,.JF0f093ce8
/*  f093c80:	86030018 */ 	lh	$v1,0x18($s0)
/*  f093c84:	8d230038 */ 	lw	$v1,0x38($t1)
/*  f093c88:	0062082a */ 	slt	$at,$v1,$v0
/*  f093c8c:	10200013 */ 	beqz	$at,.JF0f093cdc
/*  f093c90:	00437023 */ 	subu	$t6,$v0,$v1
/*  f093c94:	860a0004 */ 	lh	$t2,0x4($s0)
/*  f093c98:	01445823 */ 	subu	$t3,$t2,$a0
/*  f093c9c:	01630019 */ 	multu	$t3,$v1
/*  f093ca0:	00006012 */ 	mflo	$t4
/*  f093ca4:	00000000 */ 	nop
/*  f093ca8:	00000000 */ 	nop
/*  f093cac:	0182001a */ 	div	$zero,$t4,$v0
/*  f093cb0:	00006812 */ 	mflo	$t5
/*  f093cb4:	008d2821 */ 	addu	$a1,$a0,$t5
/*  f093cb8:	14400002 */ 	bnez	$v0,.JF0f093cc4
/*  f093cbc:	00000000 */ 	nop
/*  f093cc0:	0007000d */ 	break	0x7
.JF0f093cc4:
/*  f093cc4:	2401ffff */ 	li	$at,-1
/*  f093cc8:	14410004 */ 	bne	$v0,$at,.JF0f093cdc
/*  f093ccc:	3c018000 */ 	lui	$at,0x8000
/*  f093cd0:	15810002 */ 	bne	$t4,$at,.JF0f093cdc
/*  f093cd4:	00000000 */ 	nop
/*  f093cd8:	0006000d */ 	break	0x6
.JF0f093cdc:
/*  f093cdc:	10000035 */ 	b	.JF0f093db4
/*  f093ce0:	ae0e001c */ 	sw	$t6,0x1c($s0)
/*  f093ce4:	86030018 */ 	lh	$v1,0x18($s0)
.JF0f093ce8:
/*  f093ce8:	50600032 */ 	beqzl	$v1,.JF0f093db4
/*  f093cec:	86050004 */ 	lh	$a1,0x4($s0)
/*  f093cf0:	86020004 */ 	lh	$v0,0x4($s0)
/*  f093cf4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f093cf8:	1044002d */ 	beq	$v0,$a0,.JF0f093db0
/*  f093cfc:	00447823 */ 	subu	$t7,$v0,$a0
/*  f093d00:	448f3000 */ 	mtc1	$t7,$f6
/*  f093d04:	c42ac3bc */ 	lwc1	$f10,-0x3c44($at)
/*  f093d08:	c524004c */ 	lwc1	$f4,0x4c($t1)
/*  f093d0c:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f093d10:	44833000 */ 	mtc1	$v1,$f6
/*  f093d14:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f093d18:	44802000 */ 	mtc1	$zero,$f4
/*  f093d1c:	3c013f80 */ 	lui	$at,0x3f80
/*  f093d20:	44818000 */ 	mtc1	$at,$f16
/*  f093d24:	460c203c */ 	c.lt.s	$f4,$f12
/*  f093d28:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f093d2c:	460a4382 */ 	mul.s	$f14,$f8,$f10
/*  f093d30:	45020004 */ 	bc1fl	.JF0f093d44
/*  f093d34:	46006007 */ 	neg.s	$f0,$f12
/*  f093d38:	10000002 */ 	b	.JF0f093d44
/*  f093d3c:	46006006 */ 	mov.s	$f0,$f12
/*  f093d40:	46006007 */ 	neg.s	$f0,$f12
.JF0f093d44:
/*  f093d44:	4600803c */ 	c.lt.s	$f16,$f0
/*  f093d48:	00000000 */ 	nop
/*  f093d4c:	4502001a */ 	bc1fl	.JF0f093db8
/*  f093d50:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f093d54:	460e803c */ 	c.lt.s	$f16,$f14
/*  f093d58:	00000000 */ 	nop
/*  f093d5c:	45000002 */ 	bc1f	.JF0f093d68
/*  f093d60:	00000000 */ 	nop
/*  f093d64:	46008386 */ 	mov.s	$f14,$f16
.JF0f093d68:
/*  f093d68:	460c7082 */ 	mul.s	$f2,$f14,$f12
/*  f093d6c:	44803000 */ 	mtc1	$zero,$f6
/*  f093d70:	00000000 */ 	nop
/*  f093d74:	4602303c */ 	c.lt.s	$f6,$f2
/*  f093d78:	00000000 */ 	nop
/*  f093d7c:	45020004 */ 	bc1fl	.JF0f093d90
/*  f093d80:	46001007 */ 	neg.s	$f0,$f2
/*  f093d84:	10000002 */ 	b	.JF0f093d90
/*  f093d88:	46001006 */ 	mov.s	$f0,$f2
/*  f093d8c:	46001007 */ 	neg.s	$f0,$f2
.JF0f093d90:
/*  f093d90:	4600803c */ 	c.lt.s	$f16,$f0
/*  f093d94:	00000000 */ 	nop
/*  f093d98:	45020007 */ 	bc1fl	.JF0f093db8
/*  f093d9c:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f093da0:	4600120d */ 	trunc.w.s	$f8,$f2
/*  f093da4:	44194000 */ 	mfc1	$t9,$f8
/*  f093da8:	10000002 */ 	b	.JF0f093db4
/*  f093dac:	00992821 */ 	addu	$a1,$a0,$t9
.JF0f093db0:
/*  f093db0:	86050004 */ 	lh	$a1,0x4($s0)
.JF0f093db4:
/*  f093db4:	afa50048 */ 	sw	$a1,0x48($sp)
.JF0f093db8:
/*  f093db8:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f093dbc:	0fc5b3cc */ 	jal	lvIsPaused
/*  f093dc0:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f093dc4:	3c09800a */ 	lui	$t1,0x800a
/*  f093dc8:	2529a630 */ 	addiu	$t1,$t1,-22992
/*  f093dcc:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f093dd0:	14400031 */ 	bnez	$v0,.JF0f093e98
/*  f093dd4:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f093dd8:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f093ddc:	0fc6279d */ 	jal	mpIsPaused
/*  f093de0:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f093de4:	3c09800a */ 	lui	$t1,0x800a
/*  f093de8:	2529a630 */ 	addiu	$t1,$t1,-22992
/*  f093dec:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f093df0:	10400005 */ 	beqz	$v0,.JF0f093e08
/*  f093df4:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f093df8:	960a0032 */ 	lhu	$t2,0x32($s0)
/*  f093dfc:	314b0002 */ 	andi	$t3,$t2,0x2
/*  f093e00:	55600026 */ 	bnezl	$t3,.JF0f093e9c
/*  f093e04:	240bffff */ 	li	$t3,-1
.JF0f093e08:
/*  f093e08:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f093e0c:	0fc6279d */ 	jal	mpIsPaused
/*  f093e10:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f093e14:	3c09800a */ 	lui	$t1,0x800a
/*  f093e18:	2529a630 */ 	addiu	$t1,$t1,-22992
/*  f093e1c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f093e20:	10400020 */ 	beqz	$v0,.JF0f093ea4
/*  f093e24:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f093e28:	8d2c006c */ 	lw	$t4,0x6c($t1)
/*  f093e2c:	24010001 */ 	li	$at,0x1
/*  f093e30:	00002025 */ 	move	$a0,$zero
/*  f093e34:	11800003 */ 	beqz	$t4,.JF0f093e44
/*  f093e38:	00001025 */ 	move	$v0,$zero
/*  f093e3c:	10000001 */ 	b	.JF0f093e44
/*  f093e40:	24040001 */ 	li	$a0,0x1
.JF0f093e44:
/*  f093e44:	8d2d0068 */ 	lw	$t5,0x68($t1)
/*  f093e48:	00001825 */ 	move	$v1,$zero
/*  f093e4c:	00003825 */ 	move	$a3,$zero
/*  f093e50:	11a00003 */ 	beqz	$t5,.JF0f093e60
/*  f093e54:	00000000 */ 	nop
/*  f093e58:	10000001 */ 	b	.JF0f093e60
/*  f093e5c:	24020001 */ 	li	$v0,0x1
.JF0f093e60:
/*  f093e60:	8d2e0064 */ 	lw	$t6,0x64($t1)
/*  f093e64:	11c00003 */ 	beqz	$t6,.JF0f093e74
/*  f093e68:	00000000 */ 	nop
/*  f093e6c:	10000001 */ 	b	.JF0f093e74
/*  f093e70:	24030001 */ 	li	$v1,0x1
.JF0f093e74:
/*  f093e74:	8d2f0070 */ 	lw	$t7,0x70($t1)
/*  f093e78:	11e00003 */ 	beqz	$t7,.JF0f093e88
/*  f093e7c:	00000000 */ 	nop
/*  f093e80:	10000001 */ 	b	.JF0f093e88
/*  f093e84:	24070001 */ 	li	$a3,0x1
.JF0f093e88:
/*  f093e88:	00e3c021 */ 	addu	$t8,$a3,$v1
/*  f093e8c:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f093e90:	03245021 */ 	addu	$t2,$t9,$a0
/*  f093e94:	15410003 */ 	bne	$t2,$at,.JF0f093ea4
.JF0f093e98:
/*  f093e98:	240bffff */ 	li	$t3,-1
.JF0f093e9c:
/*  f093e9c:	a60b0006 */ 	sh	$t3,0x6($s0)
/*  f093ea0:	afa00048 */ 	sw	$zero,0x48($sp)
.JF0f093ea4:
/*  f093ea4:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f093ea8:	860d0006 */ 	lh	$t5,0x6($s0)
/*  f093eac:	44805000 */ 	mtc1	$zero,$f10
/*  f093eb0:	518d0004 */ 	beql	$t4,$t5,.JF0f093ec4
/*  f093eb4:	240effff */ 	li	$t6,-1
/*  f093eb8:	10000003 */ 	b	.JF0f093ec8
/*  f093ebc:	a60c0006 */ 	sh	$t4,0x6($s0)
/*  f093ec0:	240effff */ 	li	$t6,-1
.JF0f093ec4:
/*  f093ec4:	afae0048 */ 	sw	$t6,0x48($sp)
.JF0f093ec8:
/*  f093ec8:	86040008 */ 	lh	$a0,0x8($s0)
/*  f093ecc:	8602000a */ 	lh	$v0,0xa($s0)
/*  f093ed0:	50820028 */ 	beql	$a0,$v0,.JF0f093f74
/*  f093ed4:	2419ffff */ 	li	$t9,-1
/*  f093ed8:	960f0030 */ 	lhu	$t7,0x30($s0)
/*  f093edc:	31f81000 */ 	andi	$t8,$t7,0x1000
/*  f093ee0:	53000006 */ 	beqzl	$t8,.JF0f093efc
/*  f093ee4:	8d250034 */ 	lw	$a1,0x34($t1)
/*  f093ee8:	a6020008 */ 	sh	$v0,0x8($s0)
/*  f093eec:	86190008 */ 	lh	$t9,0x8($s0)
/*  f093ef0:	1000001b */ 	b	.JF0f093f60
/*  f093ef4:	afb90044 */ 	sw	$t9,0x44($sp)
/*  f093ef8:	8d250034 */ 	lw	$a1,0x34($t1)
.JF0f093efc:
/*  f093efc:	240100f0 */ 	li	$at,0xf0
/*  f093f00:	00441823 */ 	subu	$v1,$v0,$a0
/*  f093f04:	00055240 */ 	sll	$t2,$a1,0x9
/*  f093f08:	0141001a */ 	div	$zero,$t2,$at
/*  f093f0c:	00002812 */ 	mflo	$a1
/*  f093f10:	24060001 */ 	li	$a2,0x1
/*  f093f14:	04610003 */ 	bgez	$v1,.JF0f093f24
/*  f093f18:	00031023 */ 	negu	$v0,$v1
/*  f093f1c:	10000001 */ 	b	.JF0f093f24
/*  f093f20:	2406ffff */ 	li	$a2,-1
.JF0f093f24:
/*  f093f24:	18600003 */ 	blez	$v1,.JF0f093f34
/*  f093f28:	00000000 */ 	nop
/*  f093f2c:	10000001 */ 	b	.JF0f093f34
/*  f093f30:	00601025 */ 	move	$v0,$v1
.JF0f093f34:
/*  f093f34:	0045082a */ 	slt	$at,$v0,$a1
/*  f093f38:	10200003 */ 	beqz	$at,.JF0f093f48
/*  f093f3c:	00a01825 */ 	move	$v1,$a1
/*  f093f40:	10000001 */ 	b	.JF0f093f48
/*  f093f44:	00401825 */ 	move	$v1,$v0
.JF0f093f48:
/*  f093f48:	00660019 */ 	multu	$v1,$a2
/*  f093f4c:	00006812 */ 	mflo	$t5
/*  f093f50:	008d6021 */ 	addu	$t4,$a0,$t5
/*  f093f54:	a60c0008 */ 	sh	$t4,0x8($s0)
/*  f093f58:	860e0008 */ 	lh	$t6,0x8($s0)
/*  f093f5c:	afae0044 */ 	sw	$t6,0x44($sp)
.JF0f093f60:
/*  f093f60:	960f0030 */ 	lhu	$t7,0x30($s0)
/*  f093f64:	35f84000 */ 	ori	$t8,$t7,0x4000
/*  f093f68:	10000003 */ 	b	.JF0f093f78
/*  f093f6c:	a6180030 */ 	sh	$t8,0x30($s0)
/*  f093f70:	2419ffff */ 	li	$t9,-1
.JF0f093f74:
/*  f093f74:	afb90044 */ 	sw	$t9,0x44($sp)
.JF0f093f78:
/*  f093f78:	860a000e */ 	lh	$t2,0xe($s0)
/*  f093f7c:	510a0004 */ 	beql	$t0,$t2,.JF0f093f90
/*  f093f80:	2408ffff */ 	li	$t0,-1
/*  f093f84:	10000002 */ 	b	.JF0f093f90
/*  f093f88:	a608000e */ 	sh	$t0,0xe($s0)
/*  f093f8c:	2408ffff */ 	li	$t0,-1
.JF0f093f90:
/*  f093f90:	4612503c */ 	c.lt.s	$f10,$f18
/*  f093f94:	00000000 */ 	nop
/*  f093f98:	45020013 */ 	bc1fl	.JF0f093fe8
/*  f093f9c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f093fa0:	c6020048 */ 	lwc1	$f2,0x48($s0)
/*  f093fa4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f093fa8:	4612103c */ 	c.lt.s	$f2,$f18
/*  f093fac:	00000000 */ 	nop
/*  f093fb0:	45020004 */ 	bc1fl	.JF0f093fc4
/*  f093fb4:	46029001 */ 	sub.s	$f0,$f18,$f2
/*  f093fb8:	10000003 */ 	b	.JF0f093fc8
/*  f093fbc:	46029001 */ 	sub.s	$f0,$f18,$f2
/*  f093fc0:	46029001 */ 	sub.s	$f0,$f18,$f2
.JF0f093fc4:
/*  f093fc4:	46000007 */ 	neg.s	$f0,$f0
.JF0f093fc8:
/*  f093fc8:	c424c3c0 */ 	lwc1	$f4,-0x3c40($at)
/*  f093fcc:	4600203c */ 	c.lt.s	$f4,$f0
/*  f093fd0:	00000000 */ 	nop
/*  f093fd4:	45020004 */ 	bc1fl	.JF0f093fe8
/*  f093fd8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f093fdc:	10000004 */ 	b	.JF0f093ff0
/*  f093fe0:	e6120048 */ 	swc1	$f18,0x48($s0)
/*  f093fe4:	3c01bf80 */ 	lui	$at,0xbf80
.JF0f093fe8:
/*  f093fe8:	44819000 */ 	mtc1	$at,$f18
/*  f093fec:	00000000 */ 	nop
.JF0f093ff0:
/*  f093ff0:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f093ff4:	306b0002 */ 	andi	$t3,$v1,0x2
/*  f093ff8:	51600026 */ 	beqzl	$t3,.JF0f094094
/*  f093ffc:	306c2000 */ 	andi	$t4,$v1,0x2000
/*  f094000:	860d0006 */ 	lh	$t5,0x6($s0)
/*  f094004:	306c2000 */ 	andi	$t4,$v1,0x2000
/*  f094008:	30792000 */ 	andi	$t9,$v1,0x2000
/*  f09400c:	19a00008 */ 	blez	$t5,.JF0f094030
/*  f094010:	00000000 */ 	nop
/*  f094014:	1180001e */ 	beqz	$t4,.JF0f094090
/*  f094018:	306fdfff */ 	andi	$t7,$v1,0xdfff
/*  f09401c:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f094020:	35f81000 */ 	ori	$t8,$t7,0x1000
/*  f094024:	a6180030 */ 	sh	$t8,0x30($s0)
/*  f094028:	10000019 */ 	b	.JF0f094090
/*  f09402c:	3303ffff */ 	andi	$v1,$t8,0xffff
.JF0f094030:
/*  f094030:	57200015 */ 	bnezl	$t9,.JF0f094088
/*  f094034:	306defff */ 	andi	$t5,$v1,0xefff
/*  f094038:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f09403c:	5080000e */ 	beqzl	$a0,.JF0f094078
/*  f094040:	960a0030 */ 	lhu	$t2,0x30($s0)
/*  f094044:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f094048:	0c00ccc0 */ 	jal	sndGetState
/*  f09404c:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f094050:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f094054:	10400007 */ 	beqz	$v0,.JF0f094074
/*  f094058:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f09405c:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f094060:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f094064:	0c00cd8d */ 	jal	audioStop
/*  f094068:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f09406c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f094070:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
.JF0f094074:
/*  f094074:	960a0030 */ 	lhu	$t2,0x30($s0)
.JF0f094078:
/*  f094078:	354b2000 */ 	ori	$t3,$t2,0x2000
/*  f09407c:	a60b0030 */ 	sh	$t3,0x30($s0)
/*  f094080:	3163ffff */ 	andi	$v1,$t3,0xffff
/*  f094084:	306defff */ 	andi	$t5,$v1,0xefff
.JF0f094088:
/*  f094088:	a60d0030 */ 	sh	$t5,0x30($s0)
/*  f09408c:	31a3ffff */ 	andi	$v1,$t5,0xffff
.JF0f094090:
/*  f094090:	306c2000 */ 	andi	$t4,$v1,0x2000
.JF0f094094:
/*  f094094:	15800068 */ 	bnez	$t4,.JF0f094238
/*  f094098:	306e1000 */ 	andi	$t6,$v1,0x1000
/*  f09409c:	11c00033 */ 	beqz	$t6,.JF0f09416c
/*  f0940a0:	02002025 */ 	move	$a0,$s0
/*  f0940a4:	30650010 */ 	andi	$a1,$v1,0x10
/*  f0940a8:	10a0000d */ 	beqz	$a1,.JF0f0940e0
/*  f0940ac:	30790400 */ 	andi	$t9,$v1,0x400
/*  f0940b0:	960f0032 */ 	lhu	$t7,0x32($s0)
/*  f0940b4:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f0940b8:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f0940bc:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f0940c0:	13000003 */ 	beqz	$t8,.JF0f0940d0
/*  f0940c4:	00003825 */ 	move	$a3,$zero
/*  f0940c8:	10000001 */ 	b	.JF0f0940d0
/*  f0940cc:	24070001 */ 	li	$a3,0x1
.JF0f0940d0:
/*  f0940d0:	0c0042a8 */ 	jal	sndStartMp3
/*  f0940d4:	86040026 */ 	lh	$a0,0x26($s0)
/*  f0940d8:	10000021 */ 	b	.JF0f094160
/*  f0940dc:	96030030 */ 	lhu	$v1,0x30($s0)
.JF0f0940e0:
/*  f0940e0:	13200011 */ 	beqz	$t9,.JF0f094128
/*  f0940e4:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f0940e8:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f0940ec:	02002025 */ 	move	$a0,$s0
/*  f0940f0:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f0940f4:	1140001a */ 	beqz	$t2,.JF0f094160
/*  f0940f8:	01403025 */ 	move	$a2,$t2
/*  f0940fc:	860b0026 */ 	lh	$t3,0x26($s0)
/*  f094100:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f094104:	240c0001 */ 	li	$t4,0x1
/*  f094108:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f09410c:	920d001a */ 	lbu	$t5,0x1a($s0)
/*  f094110:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f094114:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f094118:	0c0041b5 */ 	jal	snd00010718
/*  f09411c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f094120:	1000000f */ 	b	.JF0f094160
/*  f094124:	96030030 */ 	lhu	$v1,0x30($s0)
.JF0f094128:
/*  f094128:	11c0000d */ 	beqz	$t6,.JF0f094160
/*  f09412c:	02002025 */ 	move	$a0,$s0
/*  f094130:	860f0026 */ 	lh	$t7,0x26($s0)
/*  f094134:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f094138:	24190001 */ 	li	$t9,0x1
/*  f09413c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f094140:	9218001a */ 	lbu	$t8,0x1a($s0)
/*  f094144:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f094148:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f09414c:	01c03025 */ 	move	$a2,$t6
/*  f094150:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f094154:	0c0041b5 */ 	jal	snd00010718
/*  f094158:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f09415c:	96030030 */ 	lhu	$v1,0x30($s0)
.JF0f094160:
/*  f094160:	306aefff */ 	andi	$t2,$v1,0xefff
/*  f094164:	10000034 */ 	b	.JF0f094238
/*  f094168:	a60a0030 */ 	sh	$t2,0x30($s0)
.JF0f09416c:
/*  f09416c:	860b0026 */ 	lh	$t3,0x26($s0)
/*  f094170:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f094174:	306c4000 */ 	andi	$t4,$v1,0x4000
/*  f094178:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f09417c:	920d001a */ 	lbu	$t5,0x1a($s0)
/*  f094180:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f094184:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f094188:	30650010 */ 	andi	$a1,$v1,0x10
/*  f09418c:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f094190:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f094194:	0c004117 */ 	jal	sndAdjust
/*  f094198:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f09419c:	10000026 */ 	b	.JF0f094238
/*  f0941a0:	00000000 */ 	nop
/*  f0941a4:	860e0028 */ 	lh	$t6,0x28($s0)
.JF0f0941a8:
/*  f0941a8:	2401000b */ 	li	$at,0xb
/*  f0941ac:	11c10022 */ 	beq	$t6,$at,.JF0f094238
/*  f0941b0:	00000000 */ 	nop
/*  f0941b4:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f0941b8:	306f0010 */ 	andi	$t7,$v1,0x10
/*  f0941bc:	51e00015 */ 	beqzl	$t7,.JF0f094214
/*  f0941c0:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f0941c4:	0c003a5c */ 	jal	sndIsPlayingMp3
/*  f0941c8:	00000000 */ 	nop
/*  f0941cc:	5440000e */ 	bnezl	$v0,.JF0f094208
/*  f0941d0:	240a0001 */ 	li	$t2,0x1
/*  f0941d4:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f0941d8:	30780008 */ 	andi	$t8,$v1,0x8
/*  f0941dc:	53000005 */ 	beqzl	$t8,.JF0f0941f4
/*  f0941e0:	30790200 */ 	andi	$t9,$v1,0x200
/*  f0941e4:	0fc16f3f */ 	jal	propDecrementSoundCount
/*  f0941e8:	8e040050 */ 	lw	$a0,0x50($s0)
/*  f0941ec:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f0941f0:	30790200 */ 	andi	$t9,$v1,0x200
.JF0f0941f4:
/*  f0941f4:	53200004 */ 	beqzl	$t9,.JF0f094208
/*  f0941f8:	240a0001 */ 	li	$t2,0x1
/*  f0941fc:	0fc37ba6 */ 	jal	hudmsgsHideByChannel
/*  f094200:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f094204:	240a0001 */ 	li	$t2,0x1
.JF0f094208:
/*  f094208:	1000000b */ 	b	.JF0f094238
/*  f09420c:	a60a0030 */ 	sh	$t2,0x30($s0)
/*  f094210:	8e0b0000 */ 	lw	$t3,0x0($s0)
.JF0f094214:
/*  f094214:	306d0008 */ 	andi	$t5,$v1,0x8
/*  f094218:	15600007 */ 	bnez	$t3,.JF0f094238
/*  f09421c:	00000000 */ 	nop
/*  f094220:	51a00004 */ 	beqzl	$t5,.JF0f094234
/*  f094224:	240c0001 */ 	li	$t4,0x1
/*  f094228:	0fc16f3f */ 	jal	propDecrementSoundCount
/*  f09422c:	8e040050 */ 	lw	$a0,0x50($s0)
/*  f094230:	240c0001 */ 	li	$t4,0x1
.JF0f094234:
/*  f094234:	a60c0030 */ 	sh	$t4,0x30($s0)
.JF0f094238:
/*  f094238:	3c0e8007 */ 	lui	$t6,0x8007
/*  f09423c:	8dceb444 */ 	lw	$t6,-0x4bbc($t6)
/*  f094240:	51c00008 */ 	beqzl	$t6,.JF0f094264
/*  f094244:	96190030 */ 	lhu	$t9,0x30($s0)
/*  f094248:	960f0032 */ 	lhu	$t7,0x32($s0)
/*  f09424c:	31f80004 */ 	andi	$t8,$t7,0x4
/*  f094250:	53000004 */ 	beqzl	$t8,.JF0f094264
/*  f094254:	96190030 */ 	lhu	$t9,0x30($s0)
/*  f094258:	0fc24e38 */ 	jal	propsndPrintChannel
/*  f09425c:	02002025 */ 	move	$a0,$s0
/*  f094260:	96190030 */ 	lhu	$t9,0x30($s0)
.JF0f094264:
/*  f094264:	332befff */ 	andi	$t3,$t9,0xefff
/*  f094268:	a60b0030 */ 	sh	$t3,0x30($s0)
/*  f09426c:	316dbfff */ 	andi	$t5,$t3,0xbfff
/*  f094270:	a60d0030 */ 	sh	$t5,0x30($s0)
/*  f094274:	8fbf0034 */ 	lw	$ra,0x34($sp)
.JF0f094278:
/*  f094278:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f09427c:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f094280:	03e00008 */ 	jr	$ra
/*  f094284:	00000000 */ 	nop
);
#elif VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel propsndTickChannel
.late_rodata
glabel var7f1ab73c
.word 0x392ec33e
glabel var7f1ab740
.word 0x3c23d70a
.text
/*  f092b04:	3c188007 */ 	lui	$t8,0x8007
/*  f092b08:	8f18b1a0 */ 	lw	$t8,-0x4e60($t8)
/*  f092b0c:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f092b10:	00047900 */ 	sll	$t7,$a0,0x4
/*  f092b14:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f092b18:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f092b1c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f092b20:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f092b24:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f092b28:	01f88021 */ 	addu	$s0,$t7,$t8
/*  f092b2c:	96190032 */ 	lhu	$t9,0x32($s0)
/*  f092b30:	00807025 */ 	move	$t6,$a0
/*  f092b34:	332a0080 */ 	andi	$t2,$t9,0x80
/*  f092b38:	554001f7 */ 	bnezl	$t2,.PF0f093318
/*  f092b3c:	860e0028 */ 	lh	$t6,0x28($s0)
/*  f092b40:	860b0028 */ 	lh	$t3,0x28($s0)
/*  f092b44:	2401000b */ 	li	$at,0xb
/*  f092b48:	516101f3 */ 	beql	$t3,$at,.PF0f093318
/*  f092b4c:	860e0028 */ 	lh	$t6,0x28($s0)
/*  f092b50:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f092b54:	50800006 */ 	beqzl	$a0,.PF0f092b70
/*  f092b58:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f092b5c:	0c00cc3c */ 	jal	sndGetState
/*  f092b60:	00000000 */ 	nop
/*  f092b64:	54400010 */ 	bnezl	$v0,.PF0f092ba8
/*  f092b68:	8e020050 */ 	lw	$v0,0x50($s0)
/*  f092b6c:	96030030 */ 	lhu	$v1,0x30($s0)
.PF0f092b70:
/*  f092b70:	306c0002 */ 	andi	$t4,$v1,0x2
/*  f092b74:	5580000c */ 	bnezl	$t4,.PF0f092ba8
/*  f092b78:	8e020050 */ 	lw	$v0,0x50($s0)
/*  f092b7c:	306d1000 */ 	andi	$t5,$v1,0x1000
/*  f092b80:	55a00009 */ 	bnezl	$t5,.PF0f092ba8
/*  f092b84:	8e020050 */ 	lw	$v0,0x50($s0)
/*  f092b88:	306e0010 */ 	andi	$t6,$v1,0x10
/*  f092b8c:	51c001e2 */ 	beqzl	$t6,.PF0f093318
/*  f092b90:	860e0028 */ 	lh	$t6,0x28($s0)
/*  f092b94:	0c0039cc */ 	jal	sndIsPlayingMp3
/*  f092b98:	00000000 */ 	nop
/*  f092b9c:	504001de */ 	beqzl	$v0,.PF0f093318
/*  f092ba0:	860e0028 */ 	lh	$t6,0x28($s0)
/*  f092ba4:	8e020050 */ 	lw	$v0,0x50($s0)
.PF0f092ba8:
/*  f092ba8:	00002025 */ 	move	$a0,$zero
/*  f092bac:	00004025 */ 	move	$t0,$zero
/*  f092bb0:	10400004 */ 	beqz	$v0,.PF0f092bc4
/*  f092bb4:	96050032 */ 	lhu	$a1,0x32($s0)
/*  f092bb8:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f092bbc:	10000006 */ 	b	.PF0f092bd8
/*  f092bc0:	24480028 */ 	addiu	$t0,$v0,0x28
.PF0f092bc4:
/*  f092bc4:	860f0064 */ 	lh	$t7,0x64($s0)
/*  f092bc8:	2401ffff */ 	li	$at,-1
/*  f092bcc:	51e10003 */ 	beql	$t7,$at,.PF0f092bdc
/*  f092bd0:	8e020054 */ 	lw	$v0,0x54($s0)
/*  f092bd4:	26080064 */ 	addiu	$t0,$s0,0x64
.PF0f092bd8:
/*  f092bd8:	8e020054 */ 	lw	$v0,0x54($s0)
.PF0f092bdc:
/*  f092bdc:	3c09800a */ 	lui	$t1,0x800a
/*  f092be0:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f092be4:	10400002 */ 	beqz	$v0,.PF0f092bf0
/*  f092be8:	30aa0010 */ 	andi	$t2,$a1,0x10
/*  f092bec:	00402025 */ 	move	$a0,$v0
.PF0f092bf0:
/*  f092bf0:	913804e3 */ 	lbu	$t8,0x4e3($t1)
/*  f092bf4:	13000006 */ 	beqz	$t8,.PF0f092c10
/*  f092bf8:	00000000 */ 	nop
/*  f092bfc:	30b90020 */ 	andi	$t9,$a1,0x20
/*  f092c00:	13200003 */ 	beqz	$t9,.PF0f092c10
/*  f092c04:	00000000 */ 	nop
/*  f092c08:	10000039 */ 	b	.PF0f092cf0
/*  f092c0c:	a6000004 */ 	sh	$zero,0x4($s0)
.PF0f092c10:
/*  f092c10:	11400007 */ 	beqz	$t2,.PF0f092c30
/*  f092c14:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f092c18:	306b1000 */ 	andi	$t3,$v1,0x1000
/*  f092c1c:	516001f2 */ 	beqzl	$t3,.PF0f0933e8
/*  f092c20:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f092c24:	860c0010 */ 	lh	$t4,0x10($s0)
/*  f092c28:	10000031 */ 	b	.PF0f092cf0
/*  f092c2c:	a60c0004 */ 	sh	$t4,0x4($s0)
.PF0f092c30:
/*  f092c30:	5080001f */ 	beqzl	$a0,.PF0f092cb0
/*  f092c34:	306a0020 */ 	andi	$t2,$v1,0x20
/*  f092c38:	5100001d */ 	beqzl	$t0,.PF0f092cb0
/*  f092c3c:	306a0020 */ 	andi	$t2,$v1,0x20
/*  f092c40:	306d8000 */ 	andi	$t5,$v1,0x8000
/*  f092c44:	11a00003 */ 	beqz	$t5,.PF0f092c54
/*  f092c48:	01001025 */ 	move	$v0,$t0
/*  f092c4c:	10000001 */ 	b	.PF0f092c54
/*  f092c50:	00001025 */ 	move	$v0,$zero
.PF0f092c54:
/*  f092c54:	860e002c */ 	lh	$t6,0x2c($s0)
/*  f092c58:	3c018007 */ 	lui	$at,0x8007
/*  f092c5c:	2619004c */ 	addiu	$t9,$s0,0x4c
/*  f092c60:	a42eb1e0 */ 	sh	$t6,-0x4e20($at)
/*  f092c64:	8e07003c */ 	lw	$a3,0x3c($s0)
/*  f092c68:	8e060038 */ 	lw	$a2,0x38($s0)
/*  f092c6c:	8e050034 */ 	lw	$a1,0x34($s0)
/*  f092c70:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f092c74:	860f0026 */ 	lh	$t7,0x26($s0)
/*  f092c78:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f092c7c:	86180010 */ 	lh	$t8,0x10($s0)
/*  f092c80:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f092c84:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f092c88:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f092c8c:	0fc25171 */ 	jal	propsnd0f0946b0
/*  f092c90:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f092c94:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f092c98:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f092c9c:	3c09800a */ 	lui	$t1,0x800a
/*  f092ca0:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f092ca4:	a6020004 */ 	sh	$v0,0x4($s0)
/*  f092ca8:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f092cac:	306a0020 */ 	andi	$t2,$v1,0x20
.PF0f092cb0:
/*  f092cb0:	1540000f */ 	bnez	$t2,.PF0f092cf0
/*  f092cb4:	00000000 */ 	nop
/*  f092cb8:	c604004c */ 	lwc1	$f4,0x4c($s0)
/*  f092cbc:	8e050034 */ 	lw	$a1,0x34($s0)
/*  f092cc0:	8e060038 */ 	lw	$a2,0x38($s0)
/*  f092cc4:	8e07003c */ 	lw	$a3,0x3c($s0)
/*  f092cc8:	306b0800 */ 	andi	$t3,$v1,0x800
/*  f092ccc:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f092cd0:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f092cd4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f092cd8:	0fc25323 */ 	jal	propsnd0f094d78
/*  f092cdc:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f092ce0:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f092ce4:	3c09800a */ 	lui	$t1,0x800a
/*  f092ce8:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f092cec:	a602000a */ 	sh	$v0,0xa($s0)
.PF0f092cf0:
/*  f092cf0:	5100000a */ 	beqzl	$t0,.PF0f092d1c
/*  f092cf4:	240e0001 */ 	li	$t6,0x1
/*  f092cf8:	850c0000 */ 	lh	$t4,0x0($t0)
/*  f092cfc:	2401ffff */ 	li	$at,-1
/*  f092d00:	51810006 */ 	beql	$t4,$at,.PF0f092d1c
/*  f092d04:	240e0001 */ 	li	$t6,0x1
/*  f092d08:	240d0001 */ 	li	$t5,0x1
/*  f092d0c:	a600000c */ 	sh	$zero,0xc($s0)
/*  f092d10:	10000004 */ 	b	.PF0f092d24
/*  f092d14:	a20d001a */ 	sb	$t5,0x1a($s0)
/*  f092d18:	240e0001 */ 	li	$t6,0x1
.PF0f092d1c:
/*  f092d1c:	a600000c */ 	sh	$zero,0xc($s0)
/*  f092d20:	a20e001a */ 	sb	$t6,0x1a($s0)
.PF0f092d24:
/*  f092d24:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f092d28:	51e00026 */ 	beqzl	$t7,.PF0f092dc4
/*  f092d2c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f092d30:	c6000044 */ 	lwc1	$f0,0x44($s0)
/*  f092d34:	44803000 */ 	mtc1	$zero,$f6
/*  f092d38:	00000000 */ 	nop
/*  f092d3c:	4600303c */ 	c.lt.s	$f6,$f0
/*  f092d40:	00000000 */ 	nop
/*  f092d44:	4502001f */ 	bc1fl	.PF0f092dc4
/*  f092d48:	3c01bf80 */ 	lui	$at,0xbf80
/*  f092d4c:	c6020048 */ 	lwc1	$f2,0x48($s0)
/*  f092d50:	44804000 */ 	mtc1	$zero,$f8
/*  f092d54:	00000000 */ 	nop
/*  f092d58:	4608103c */ 	c.lt.s	$f2,$f8
/*  f092d5c:	00000000 */ 	nop
/*  f092d60:	45020004 */ 	bc1fl	.PF0f092d74
/*  f092d64:	8e180020 */ 	lw	$t8,0x20($s0)
/*  f092d68:	10000018 */ 	b	.PF0f092dcc
/*  f092d6c:	46000486 */ 	mov.s	$f18,$f0
/*  f092d70:	8e180020 */ 	lw	$t8,0x20($s0)
.PF0f092d74:
/*  f092d74:	44802000 */ 	mtc1	$zero,$f4
/*  f092d78:	44985000 */ 	mtc1	$t8,$f10
/*  f092d7c:	00000000 */ 	nop
/*  f092d80:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f092d84:	460c203c */ 	c.lt.s	$f4,$f12
/*  f092d88:	00000000 */ 	nop
/*  f092d8c:	4500000a */ 	bc1f	.PF0f092db8
/*  f092d90:	00000000 */ 	nop
/*  f092d94:	8d390034 */ 	lw	$t9,0x34($t1)
/*  f092d98:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f092d9c:	44994000 */ 	mtc1	$t9,$f8
/*  f092da0:	00000000 */ 	nop
/*  f092da4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f092da8:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f092dac:	460c2203 */ 	div.s	$f8,$f4,$f12
/*  f092db0:	10000006 */ 	b	.PF0f092dcc
/*  f092db4:	46081480 */ 	add.s	$f18,$f2,$f8
.PF0f092db8:
/*  f092db8:	10000004 */ 	b	.PF0f092dcc
/*  f092dbc:	46000486 */ 	mov.s	$f18,$f0
/*  f092dc0:	3c01bf80 */ 	lui	$at,0xbf80
.PF0f092dc4:
/*  f092dc4:	44819000 */ 	mtc1	$at,$f18
/*  f092dc8:	00000000 */ 	nop
.PF0f092dcc:
/*  f092dcc:	86040006 */ 	lh	$a0,0x6($s0)
/*  f092dd0:	2401ffff */ 	li	$at,-1
/*  f092dd4:	8608000c */ 	lh	$t0,0xc($s0)
/*  f092dd8:	14810003 */ 	bne	$a0,$at,.PF0f092de8
/*  f092ddc:	00802825 */ 	move	$a1,$a0
/*  f092de0:	10000050 */ 	b	.PF0f092f24
/*  f092de4:	86050004 */ 	lh	$a1,0x4($s0)
.PF0f092de8:
/*  f092de8:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f092dec:	0442001a */ 	bltzl	$v0,.PF0f092e58
/*  f092df0:	86030018 */ 	lh	$v1,0x18($s0)
/*  f092df4:	8d230038 */ 	lw	$v1,0x38($t1)
/*  f092df8:	0062082a */ 	slt	$at,$v1,$v0
/*  f092dfc:	10200013 */ 	beqz	$at,.PF0f092e4c
/*  f092e00:	00437023 */ 	subu	$t6,$v0,$v1
/*  f092e04:	860a0004 */ 	lh	$t2,0x4($s0)
/*  f092e08:	01445823 */ 	subu	$t3,$t2,$a0
/*  f092e0c:	01630019 */ 	multu	$t3,$v1
/*  f092e10:	00006012 */ 	mflo	$t4
/*  f092e14:	00000000 */ 	nop
/*  f092e18:	00000000 */ 	nop
/*  f092e1c:	0182001a */ 	div	$zero,$t4,$v0
/*  f092e20:	00006812 */ 	mflo	$t5
/*  f092e24:	008d2821 */ 	addu	$a1,$a0,$t5
/*  f092e28:	14400002 */ 	bnez	$v0,.PF0f092e34
/*  f092e2c:	00000000 */ 	nop
/*  f092e30:	0007000d */ 	break	0x7
.PF0f092e34:
/*  f092e34:	2401ffff */ 	li	$at,-1
/*  f092e38:	14410004 */ 	bne	$v0,$at,.PF0f092e4c
/*  f092e3c:	3c018000 */ 	lui	$at,0x8000
/*  f092e40:	15810002 */ 	bne	$t4,$at,.PF0f092e4c
/*  f092e44:	00000000 */ 	nop
/*  f092e48:	0006000d */ 	break	0x6
.PF0f092e4c:
/*  f092e4c:	10000035 */ 	b	.PF0f092f24
/*  f092e50:	ae0e001c */ 	sw	$t6,0x1c($s0)
/*  f092e54:	86030018 */ 	lh	$v1,0x18($s0)
.PF0f092e58:
/*  f092e58:	50600032 */ 	beqzl	$v1,.PF0f092f24
/*  f092e5c:	86050004 */ 	lh	$a1,0x4($s0)
/*  f092e60:	86020004 */ 	lh	$v0,0x4($s0)
/*  f092e64:	3c017f1b */ 	lui	$at,0x7f1b
/*  f092e68:	1044002d */ 	beq	$v0,$a0,.PF0f092f20
/*  f092e6c:	00447823 */ 	subu	$t7,$v0,$a0
/*  f092e70:	448f3000 */ 	mtc1	$t7,$f6
/*  f092e74:	c42ac92c */ 	lwc1	$f10,-0x36d4($at)
/*  f092e78:	c524004c */ 	lwc1	$f4,0x4c($t1)
/*  f092e7c:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f092e80:	44833000 */ 	mtc1	$v1,$f6
/*  f092e84:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f092e88:	44802000 */ 	mtc1	$zero,$f4
/*  f092e8c:	3c013f80 */ 	lui	$at,0x3f80
/*  f092e90:	44818000 */ 	mtc1	$at,$f16
/*  f092e94:	460c203c */ 	c.lt.s	$f4,$f12
/*  f092e98:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f092e9c:	460a4382 */ 	mul.s	$f14,$f8,$f10
/*  f092ea0:	45020004 */ 	bc1fl	.PF0f092eb4
/*  f092ea4:	46006007 */ 	neg.s	$f0,$f12
/*  f092ea8:	10000002 */ 	b	.PF0f092eb4
/*  f092eac:	46006006 */ 	mov.s	$f0,$f12
/*  f092eb0:	46006007 */ 	neg.s	$f0,$f12
.PF0f092eb4:
/*  f092eb4:	4600803c */ 	c.lt.s	$f16,$f0
/*  f092eb8:	00000000 */ 	nop
/*  f092ebc:	4502001a */ 	bc1fl	.PF0f092f28
/*  f092ec0:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f092ec4:	460e803c */ 	c.lt.s	$f16,$f14
/*  f092ec8:	00000000 */ 	nop
/*  f092ecc:	45000002 */ 	bc1f	.PF0f092ed8
/*  f092ed0:	00000000 */ 	nop
/*  f092ed4:	46008386 */ 	mov.s	$f14,$f16
.PF0f092ed8:
/*  f092ed8:	460c7082 */ 	mul.s	$f2,$f14,$f12
/*  f092edc:	44803000 */ 	mtc1	$zero,$f6
/*  f092ee0:	00000000 */ 	nop
/*  f092ee4:	4602303c */ 	c.lt.s	$f6,$f2
/*  f092ee8:	00000000 */ 	nop
/*  f092eec:	45020004 */ 	bc1fl	.PF0f092f00
/*  f092ef0:	46001007 */ 	neg.s	$f0,$f2
/*  f092ef4:	10000002 */ 	b	.PF0f092f00
/*  f092ef8:	46001006 */ 	mov.s	$f0,$f2
/*  f092efc:	46001007 */ 	neg.s	$f0,$f2
.PF0f092f00:
/*  f092f00:	4600803c */ 	c.lt.s	$f16,$f0
/*  f092f04:	00000000 */ 	nop
/*  f092f08:	45020007 */ 	bc1fl	.PF0f092f28
/*  f092f0c:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f092f10:	4600120d */ 	trunc.w.s	$f8,$f2
/*  f092f14:	44194000 */ 	mfc1	$t9,$f8
/*  f092f18:	10000002 */ 	b	.PF0f092f24
/*  f092f1c:	00992821 */ 	addu	$a1,$a0,$t9
.PF0f092f20:
/*  f092f20:	86050004 */ 	lh	$a1,0x4($s0)
.PF0f092f24:
/*  f092f24:	afa50048 */ 	sw	$a1,0x48($sp)
.PF0f092f28:
/*  f092f28:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f092f2c:	0fc5b6f7 */ 	jal	lvIsPaused
/*  f092f30:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f092f34:	3c09800a */ 	lui	$t1,0x800a
/*  f092f38:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f092f3c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f092f40:	14400031 */ 	bnez	$v0,.PF0f093008
/*  f092f44:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f092f48:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f092f4c:	0fc629b9 */ 	jal	mpIsPaused
/*  f092f50:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f092f54:	3c09800a */ 	lui	$t1,0x800a
/*  f092f58:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f092f5c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f092f60:	10400005 */ 	beqz	$v0,.PF0f092f78
/*  f092f64:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f092f68:	960a0032 */ 	lhu	$t2,0x32($s0)
/*  f092f6c:	314b0002 */ 	andi	$t3,$t2,0x2
/*  f092f70:	55600026 */ 	bnezl	$t3,.PF0f09300c
/*  f092f74:	240bffff */ 	li	$t3,-1
.PF0f092f78:
/*  f092f78:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f092f7c:	0fc629b9 */ 	jal	mpIsPaused
/*  f092f80:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f092f84:	3c09800a */ 	lui	$t1,0x800a
/*  f092f88:	2529a510 */ 	addiu	$t1,$t1,-23280
/*  f092f8c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f092f90:	10400020 */ 	beqz	$v0,.PF0f093014
/*  f092f94:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f092f98:	8d2c006c */ 	lw	$t4,0x6c($t1)
/*  f092f9c:	24010001 */ 	li	$at,0x1
/*  f092fa0:	00002025 */ 	move	$a0,$zero
/*  f092fa4:	11800003 */ 	beqz	$t4,.PF0f092fb4
/*  f092fa8:	00001025 */ 	move	$v0,$zero
/*  f092fac:	10000001 */ 	b	.PF0f092fb4
/*  f092fb0:	24040001 */ 	li	$a0,0x1
.PF0f092fb4:
/*  f092fb4:	8d2d0068 */ 	lw	$t5,0x68($t1)
/*  f092fb8:	00001825 */ 	move	$v1,$zero
/*  f092fbc:	00003825 */ 	move	$a3,$zero
/*  f092fc0:	11a00003 */ 	beqz	$t5,.PF0f092fd0
/*  f092fc4:	00000000 */ 	nop
/*  f092fc8:	10000001 */ 	b	.PF0f092fd0
/*  f092fcc:	24020001 */ 	li	$v0,0x1
.PF0f092fd0:
/*  f092fd0:	8d2e0064 */ 	lw	$t6,0x64($t1)
/*  f092fd4:	11c00003 */ 	beqz	$t6,.PF0f092fe4
/*  f092fd8:	00000000 */ 	nop
/*  f092fdc:	10000001 */ 	b	.PF0f092fe4
/*  f092fe0:	24030001 */ 	li	$v1,0x1
.PF0f092fe4:
/*  f092fe4:	8d2f0070 */ 	lw	$t7,0x70($t1)
/*  f092fe8:	11e00003 */ 	beqz	$t7,.PF0f092ff8
/*  f092fec:	00000000 */ 	nop
/*  f092ff0:	10000001 */ 	b	.PF0f092ff8
/*  f092ff4:	24070001 */ 	li	$a3,0x1
.PF0f092ff8:
/*  f092ff8:	00e3c021 */ 	addu	$t8,$a3,$v1
/*  f092ffc:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f093000:	03245021 */ 	addu	$t2,$t9,$a0
/*  f093004:	15410003 */ 	bne	$t2,$at,.PF0f093014
.PF0f093008:
/*  f093008:	240bffff */ 	li	$t3,-1
.PF0f09300c:
/*  f09300c:	a60b0006 */ 	sh	$t3,0x6($s0)
/*  f093010:	afa00048 */ 	sw	$zero,0x48($sp)
.PF0f093014:
/*  f093014:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f093018:	860d0006 */ 	lh	$t5,0x6($s0)
/*  f09301c:	44805000 */ 	mtc1	$zero,$f10
/*  f093020:	518d0004 */ 	beql	$t4,$t5,.PF0f093034
/*  f093024:	240effff */ 	li	$t6,-1
/*  f093028:	10000003 */ 	b	.PF0f093038
/*  f09302c:	a60c0006 */ 	sh	$t4,0x6($s0)
/*  f093030:	240effff */ 	li	$t6,-1
.PF0f093034:
/*  f093034:	afae0048 */ 	sw	$t6,0x48($sp)
.PF0f093038:
/*  f093038:	86040008 */ 	lh	$a0,0x8($s0)
/*  f09303c:	8602000a */ 	lh	$v0,0xa($s0)
/*  f093040:	50820028 */ 	beql	$a0,$v0,.PF0f0930e4
/*  f093044:	2419ffff */ 	li	$t9,-1
/*  f093048:	960f0030 */ 	lhu	$t7,0x30($s0)
/*  f09304c:	31f81000 */ 	andi	$t8,$t7,0x1000
/*  f093050:	53000006 */ 	beqzl	$t8,.PF0f09306c
/*  f093054:	8d250034 */ 	lw	$a1,0x34($t1)
/*  f093058:	a6020008 */ 	sh	$v0,0x8($s0)
/*  f09305c:	86190008 */ 	lh	$t9,0x8($s0)
/*  f093060:	1000001b */ 	b	.PF0f0930d0
/*  f093064:	afb90044 */ 	sw	$t9,0x44($sp)
/*  f093068:	8d250034 */ 	lw	$a1,0x34($t1)
.PF0f09306c:
/*  f09306c:	240100f0 */ 	li	$at,0xf0
/*  f093070:	00441823 */ 	subu	$v1,$v0,$a0
/*  f093074:	00055240 */ 	sll	$t2,$a1,0x9
/*  f093078:	0141001a */ 	div	$zero,$t2,$at
/*  f09307c:	00002812 */ 	mflo	$a1
/*  f093080:	24060001 */ 	li	$a2,0x1
/*  f093084:	04610003 */ 	bgez	$v1,.PF0f093094
/*  f093088:	00031023 */ 	negu	$v0,$v1
/*  f09308c:	10000001 */ 	b	.PF0f093094
/*  f093090:	2406ffff */ 	li	$a2,-1
.PF0f093094:
/*  f093094:	18600003 */ 	blez	$v1,.PF0f0930a4
/*  f093098:	00000000 */ 	nop
/*  f09309c:	10000001 */ 	b	.PF0f0930a4
/*  f0930a0:	00601025 */ 	move	$v0,$v1
.PF0f0930a4:
/*  f0930a4:	0045082a */ 	slt	$at,$v0,$a1
/*  f0930a8:	10200003 */ 	beqz	$at,.PF0f0930b8
/*  f0930ac:	00a01825 */ 	move	$v1,$a1
/*  f0930b0:	10000001 */ 	b	.PF0f0930b8
/*  f0930b4:	00401825 */ 	move	$v1,$v0
.PF0f0930b8:
/*  f0930b8:	00660019 */ 	multu	$v1,$a2
/*  f0930bc:	00006812 */ 	mflo	$t5
/*  f0930c0:	008d6021 */ 	addu	$t4,$a0,$t5
/*  f0930c4:	a60c0008 */ 	sh	$t4,0x8($s0)
/*  f0930c8:	860e0008 */ 	lh	$t6,0x8($s0)
/*  f0930cc:	afae0044 */ 	sw	$t6,0x44($sp)
.PF0f0930d0:
/*  f0930d0:	960f0030 */ 	lhu	$t7,0x30($s0)
/*  f0930d4:	35f84000 */ 	ori	$t8,$t7,0x4000
/*  f0930d8:	10000003 */ 	b	.PF0f0930e8
/*  f0930dc:	a6180030 */ 	sh	$t8,0x30($s0)
/*  f0930e0:	2419ffff */ 	li	$t9,-1
.PF0f0930e4:
/*  f0930e4:	afb90044 */ 	sw	$t9,0x44($sp)
.PF0f0930e8:
/*  f0930e8:	860a000e */ 	lh	$t2,0xe($s0)
/*  f0930ec:	510a0004 */ 	beql	$t0,$t2,.PF0f093100
/*  f0930f0:	2408ffff */ 	li	$t0,-1
/*  f0930f4:	10000002 */ 	b	.PF0f093100
/*  f0930f8:	a608000e */ 	sh	$t0,0xe($s0)
/*  f0930fc:	2408ffff */ 	li	$t0,-1
.PF0f093100:
/*  f093100:	4612503c */ 	c.lt.s	$f10,$f18
/*  f093104:	00000000 */ 	nop
/*  f093108:	45020013 */ 	bc1fl	.PF0f093158
/*  f09310c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f093110:	c6020048 */ 	lwc1	$f2,0x48($s0)
/*  f093114:	3c017f1b */ 	lui	$at,0x7f1b
/*  f093118:	4612103c */ 	c.lt.s	$f2,$f18
/*  f09311c:	00000000 */ 	nop
/*  f093120:	45020004 */ 	bc1fl	.PF0f093134
/*  f093124:	46029001 */ 	sub.s	$f0,$f18,$f2
/*  f093128:	10000003 */ 	b	.PF0f093138
/*  f09312c:	46029001 */ 	sub.s	$f0,$f18,$f2
/*  f093130:	46029001 */ 	sub.s	$f0,$f18,$f2
.PF0f093134:
/*  f093134:	46000007 */ 	neg.s	$f0,$f0
.PF0f093138:
/*  f093138:	c424c930 */ 	lwc1	$f4,-0x36d0($at)
/*  f09313c:	4600203c */ 	c.lt.s	$f4,$f0
/*  f093140:	00000000 */ 	nop
/*  f093144:	45020004 */ 	bc1fl	.PF0f093158
/*  f093148:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09314c:	10000004 */ 	b	.PF0f093160
/*  f093150:	e6120048 */ 	swc1	$f18,0x48($s0)
/*  f093154:	3c01bf80 */ 	lui	$at,0xbf80
.PF0f093158:
/*  f093158:	44819000 */ 	mtc1	$at,$f18
/*  f09315c:	00000000 */ 	nop
.PF0f093160:
/*  f093160:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f093164:	306b0002 */ 	andi	$t3,$v1,0x2
/*  f093168:	51600026 */ 	beqzl	$t3,.PF0f093204
/*  f09316c:	306c2000 */ 	andi	$t4,$v1,0x2000
/*  f093170:	860d0006 */ 	lh	$t5,0x6($s0)
/*  f093174:	306c2000 */ 	andi	$t4,$v1,0x2000
/*  f093178:	30792000 */ 	andi	$t9,$v1,0x2000
/*  f09317c:	19a00008 */ 	blez	$t5,.PF0f0931a0
/*  f093180:	00000000 */ 	nop
/*  f093184:	1180001e */ 	beqz	$t4,.PF0f093200
/*  f093188:	306fdfff */ 	andi	$t7,$v1,0xdfff
/*  f09318c:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f093190:	35f81000 */ 	ori	$t8,$t7,0x1000
/*  f093194:	a6180030 */ 	sh	$t8,0x30($s0)
/*  f093198:	10000019 */ 	b	.PF0f093200
/*  f09319c:	3303ffff */ 	andi	$v1,$t8,0xffff
.PF0f0931a0:
/*  f0931a0:	57200015 */ 	bnezl	$t9,.PF0f0931f8
/*  f0931a4:	306defff */ 	andi	$t5,$v1,0xefff
/*  f0931a8:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f0931ac:	5080000e */ 	beqzl	$a0,.PF0f0931e8
/*  f0931b0:	960a0030 */ 	lhu	$t2,0x30($s0)
/*  f0931b4:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f0931b8:	0c00cc3c */ 	jal	sndGetState
/*  f0931bc:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f0931c0:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f0931c4:	10400007 */ 	beqz	$v0,.PF0f0931e4
/*  f0931c8:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f0931cc:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f0931d0:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f0931d4:	0c00cd09 */ 	jal	audioStop
/*  f0931d8:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f0931dc:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f0931e0:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
.PF0f0931e4:
/*  f0931e4:	960a0030 */ 	lhu	$t2,0x30($s0)
.PF0f0931e8:
/*  f0931e8:	354b2000 */ 	ori	$t3,$t2,0x2000
/*  f0931ec:	a60b0030 */ 	sh	$t3,0x30($s0)
/*  f0931f0:	3163ffff */ 	andi	$v1,$t3,0xffff
/*  f0931f4:	306defff */ 	andi	$t5,$v1,0xefff
.PF0f0931f8:
/*  f0931f8:	a60d0030 */ 	sh	$t5,0x30($s0)
/*  f0931fc:	31a3ffff */ 	andi	$v1,$t5,0xffff
.PF0f093200:
/*  f093200:	306c2000 */ 	andi	$t4,$v1,0x2000
.PF0f093204:
/*  f093204:	15800068 */ 	bnez	$t4,.PF0f0933a8
/*  f093208:	306e1000 */ 	andi	$t6,$v1,0x1000
/*  f09320c:	11c00033 */ 	beqz	$t6,.PF0f0932dc
/*  f093210:	02002025 */ 	move	$a0,$s0
/*  f093214:	30650010 */ 	andi	$a1,$v1,0x10
/*  f093218:	10a0000d */ 	beqz	$a1,.PF0f093250
/*  f09321c:	30790400 */ 	andi	$t9,$v1,0x400
/*  f093220:	960f0032 */ 	lhu	$t7,0x32($s0)
/*  f093224:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f093228:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f09322c:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f093230:	13000003 */ 	beqz	$t8,.PF0f093240
/*  f093234:	00003825 */ 	move	$a3,$zero
/*  f093238:	10000001 */ 	b	.PF0f093240
/*  f09323c:	24070001 */ 	li	$a3,0x1
.PF0f093240:
/*  f093240:	0c004218 */ 	jal	sndStartMp3
/*  f093244:	86040026 */ 	lh	$a0,0x26($s0)
/*  f093248:	10000021 */ 	b	.PF0f0932d0
/*  f09324c:	96030030 */ 	lhu	$v1,0x30($s0)
.PF0f093250:
/*  f093250:	13200011 */ 	beqz	$t9,.PF0f093298
/*  f093254:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f093258:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f09325c:	02002025 */ 	move	$a0,$s0
/*  f093260:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f093264:	1140001a */ 	beqz	$t2,.PF0f0932d0
/*  f093268:	01403025 */ 	move	$a2,$t2
/*  f09326c:	860b0026 */ 	lh	$t3,0x26($s0)
/*  f093270:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f093274:	240c0001 */ 	li	$t4,0x1
/*  f093278:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f09327c:	920d001a */ 	lbu	$t5,0x1a($s0)
/*  f093280:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f093284:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f093288:	0c004125 */ 	jal	snd00010718
/*  f09328c:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f093290:	1000000f */ 	b	.PF0f0932d0
/*  f093294:	96030030 */ 	lhu	$v1,0x30($s0)
.PF0f093298:
/*  f093298:	11c0000d */ 	beqz	$t6,.PF0f0932d0
/*  f09329c:	02002025 */ 	move	$a0,$s0
/*  f0932a0:	860f0026 */ 	lh	$t7,0x26($s0)
/*  f0932a4:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0932a8:	24190001 */ 	li	$t9,0x1
/*  f0932ac:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0932b0:	9218001a */ 	lbu	$t8,0x1a($s0)
/*  f0932b4:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0932b8:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0932bc:	01c03025 */ 	move	$a2,$t6
/*  f0932c0:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f0932c4:	0c004125 */ 	jal	snd00010718
/*  f0932c8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0932cc:	96030030 */ 	lhu	$v1,0x30($s0)
.PF0f0932d0:
/*  f0932d0:	306aefff */ 	andi	$t2,$v1,0xefff
/*  f0932d4:	10000034 */ 	b	.PF0f0933a8
/*  f0932d8:	a60a0030 */ 	sh	$t2,0x30($s0)
.PF0f0932dc:
/*  f0932dc:	860b0026 */ 	lh	$t3,0x26($s0)
/*  f0932e0:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0932e4:	306c4000 */ 	andi	$t4,$v1,0x4000
/*  f0932e8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0932ec:	920d001a */ 	lbu	$t5,0x1a($s0)
/*  f0932f0:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0932f4:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0932f8:	30650010 */ 	andi	$a1,$v1,0x10
/*  f0932fc:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f093300:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f093304:	0c004087 */ 	jal	sndAdjust
/*  f093308:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f09330c:	10000026 */ 	b	.PF0f0933a8
/*  f093310:	00000000 */ 	nop
/*  f093314:	860e0028 */ 	lh	$t6,0x28($s0)
.PF0f093318:
/*  f093318:	2401000b */ 	li	$at,0xb
/*  f09331c:	11c10022 */ 	beq	$t6,$at,.PF0f0933a8
/*  f093320:	00000000 */ 	nop
/*  f093324:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f093328:	306f0010 */ 	andi	$t7,$v1,0x10
/*  f09332c:	51e00015 */ 	beqzl	$t7,.PF0f093384
/*  f093330:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f093334:	0c0039cc */ 	jal	sndIsPlayingMp3
/*  f093338:	00000000 */ 	nop
/*  f09333c:	5440000e */ 	bnezl	$v0,.PF0f093378
/*  f093340:	240a0001 */ 	li	$t2,0x1
/*  f093344:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f093348:	30780008 */ 	andi	$t8,$v1,0x8
/*  f09334c:	53000005 */ 	beqzl	$t8,.PF0f093364
/*  f093350:	30790200 */ 	andi	$t9,$v1,0x200
/*  f093354:	0fc16b78 */ 	jal	propDecrementSoundCount
/*  f093358:	8e040050 */ 	lw	$a0,0x50($s0)
/*  f09335c:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f093360:	30790200 */ 	andi	$t9,$v1,0x200
.PF0f093364:
/*  f093364:	53200004 */ 	beqzl	$t9,.PF0f093378
/*  f093368:	240a0001 */ 	li	$t2,0x1
/*  f09336c:	0fc378de */ 	jal	hudmsgsHideByChannel
/*  f093370:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f093374:	240a0001 */ 	li	$t2,0x1
.PF0f093378:
/*  f093378:	1000000b */ 	b	.PF0f0933a8
/*  f09337c:	a60a0030 */ 	sh	$t2,0x30($s0)
/*  f093380:	8e0b0000 */ 	lw	$t3,0x0($s0)
.PF0f093384:
/*  f093384:	306d0008 */ 	andi	$t5,$v1,0x8
/*  f093388:	15600007 */ 	bnez	$t3,.PF0f0933a8
/*  f09338c:	00000000 */ 	nop
/*  f093390:	51a00004 */ 	beqzl	$t5,.PF0f0933a4
/*  f093394:	240c0001 */ 	li	$t4,0x1
/*  f093398:	0fc16b78 */ 	jal	propDecrementSoundCount
/*  f09339c:	8e040050 */ 	lw	$a0,0x50($s0)
/*  f0933a0:	240c0001 */ 	li	$t4,0x1
.PF0f0933a4:
/*  f0933a4:	a60c0030 */ 	sh	$t4,0x30($s0)
.PF0f0933a8:
/*  f0933a8:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0933ac:	8dceb1d4 */ 	lw	$t6,-0x4e2c($t6)
/*  f0933b0:	51c00008 */ 	beqzl	$t6,.PF0f0933d4
/*  f0933b4:	96190030 */ 	lhu	$t9,0x30($s0)
/*  f0933b8:	960f0032 */ 	lhu	$t7,0x32($s0)
/*  f0933bc:	31f80004 */ 	andi	$t8,$t7,0x4
/*  f0933c0:	53000004 */ 	beqzl	$t8,.PF0f0933d4
/*  f0933c4:	96190030 */ 	lhu	$t9,0x30($s0)
/*  f0933c8:	0fc24a94 */ 	jal	propsndPrintChannel
/*  f0933cc:	02002025 */ 	move	$a0,$s0
/*  f0933d0:	96190030 */ 	lhu	$t9,0x30($s0)
.PF0f0933d4:
/*  f0933d4:	332befff */ 	andi	$t3,$t9,0xefff
/*  f0933d8:	a60b0030 */ 	sh	$t3,0x30($s0)
/*  f0933dc:	316dbfff */ 	andi	$t5,$t3,0xbfff
/*  f0933e0:	a60d0030 */ 	sh	$t5,0x30($s0)
/*  f0933e4:	8fbf0034 */ 	lw	$ra,0x34($sp)
.PF0f0933e8:
/*  f0933e8:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f0933ec:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f0933f0:	03e00008 */ 	jr	$ra
/*  f0933f4:	00000000 */ 	nop
);
#elif VERSION >= VERSION_PAL_BETA
GLOBAL_ASM(
glabel propsndTickChannel
.late_rodata
glabel var7f1ab73c
.word 0x392ec33e
glabel var7f1ab740
.word 0x3c23d70a
.text
/*  f092a54:	3c188007 */ 	lui	$t8,0x8007
/*  f092a58:	8f18cb90 */ 	lw	$t8,-0x3470($t8)
/*  f092a5c:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f092a60:	00047900 */ 	sll	$t7,$a0,0x4
/*  f092a64:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f092a68:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f092a6c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f092a70:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f092a74:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f092a78:	01f88021 */ 	addu	$s0,$t7,$t8
/*  f092a7c:	96190032 */ 	lhu	$t9,0x32($s0)
/*  f092a80:	00807025 */ 	move	$t6,$a0
/*  f092a84:	332a0080 */ 	andi	$t2,$t9,0x80
/*  f092a88:	554001f7 */ 	bnezl	$t2,.PB0f093268
/*  f092a8c:	860e0028 */ 	lh	$t6,0x28($s0)
/*  f092a90:	860b0028 */ 	lh	$t3,0x28($s0)
/*  f092a94:	2401000b */ 	li	$at,0xb
/*  f092a98:	516101f3 */ 	beql	$t3,$at,.PB0f093268
/*  f092a9c:	860e0028 */ 	lh	$t6,0x28($s0)
/*  f092aa0:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f092aa4:	50800006 */ 	beqzl	$a0,.PB0f092ac0
/*  f092aa8:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f092aac:	0c00cf6c */ 	jal	sndGetState
/*  f092ab0:	00000000 */ 	nop
/*  f092ab4:	54400010 */ 	bnezl	$v0,.PB0f092af8
/*  f092ab8:	8e020050 */ 	lw	$v0,0x50($s0)
/*  f092abc:	96030030 */ 	lhu	$v1,0x30($s0)
.PB0f092ac0:
/*  f092ac0:	306c0002 */ 	andi	$t4,$v1,0x2
/*  f092ac4:	5580000c */ 	bnezl	$t4,.PB0f092af8
/*  f092ac8:	8e020050 */ 	lw	$v0,0x50($s0)
/*  f092acc:	306d1000 */ 	andi	$t5,$v1,0x1000
/*  f092ad0:	55a00009 */ 	bnezl	$t5,.PB0f092af8
/*  f092ad4:	8e020050 */ 	lw	$v0,0x50($s0)
/*  f092ad8:	306e0010 */ 	andi	$t6,$v1,0x10
/*  f092adc:	51c001e2 */ 	beqzl	$t6,.PB0f093268
/*  f092ae0:	860e0028 */ 	lh	$t6,0x28($s0)
/*  f092ae4:	0c003a80 */ 	jal	sndIsPlayingMp3
/*  f092ae8:	00000000 */ 	nop
/*  f092aec:	504001de */ 	beqzl	$v0,.PB0f093268
/*  f092af0:	860e0028 */ 	lh	$t6,0x28($s0)
/*  f092af4:	8e020050 */ 	lw	$v0,0x50($s0)
.PB0f092af8:
/*  f092af8:	00002025 */ 	move	$a0,$zero
/*  f092afc:	00004025 */ 	move	$t0,$zero
/*  f092b00:	10400004 */ 	beqz	$v0,.PB0f092b14
/*  f092b04:	96050032 */ 	lhu	$a1,0x32($s0)
/*  f092b08:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f092b0c:	10000006 */ 	b	.PB0f092b28
/*  f092b10:	24480028 */ 	addiu	$t0,$v0,0x28
.PB0f092b14:
/*  f092b14:	860f0064 */ 	lh	$t7,0x64($s0)
/*  f092b18:	2401ffff */ 	li	$at,-1
/*  f092b1c:	51e10003 */ 	beql	$t7,$at,.PB0f092b2c
/*  f092b20:	8e020054 */ 	lw	$v0,0x54($s0)
/*  f092b24:	26080064 */ 	addiu	$t0,$s0,0x64
.PB0f092b28:
/*  f092b28:	8e020054 */ 	lw	$v0,0x54($s0)
.PB0f092b2c:
/*  f092b2c:	3c09800a */ 	lui	$t1,0x800a
/*  f092b30:	2529e4d0 */ 	addiu	$t1,$t1,-6960
/*  f092b34:	10400002 */ 	beqz	$v0,.PB0f092b40
/*  f092b38:	30aa0010 */ 	andi	$t2,$a1,0x10
/*  f092b3c:	00402025 */ 	move	$a0,$v0
.PB0f092b40:
/*  f092b40:	913804e3 */ 	lbu	$t8,0x4e3($t1)
/*  f092b44:	13000006 */ 	beqz	$t8,.PB0f092b60
/*  f092b48:	00000000 */ 	nop
/*  f092b4c:	30b90020 */ 	andi	$t9,$a1,0x20
/*  f092b50:	13200003 */ 	beqz	$t9,.PB0f092b60
/*  f092b54:	00000000 */ 	nop
/*  f092b58:	10000039 */ 	b	.PB0f092c40
/*  f092b5c:	a6000004 */ 	sh	$zero,0x4($s0)
.PB0f092b60:
/*  f092b60:	11400007 */ 	beqz	$t2,.PB0f092b80
/*  f092b64:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f092b68:	306b1000 */ 	andi	$t3,$v1,0x1000
/*  f092b6c:	516001f2 */ 	beqzl	$t3,.PB0f093338
/*  f092b70:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f092b74:	860c0010 */ 	lh	$t4,0x10($s0)
/*  f092b78:	10000031 */ 	b	.PB0f092c40
/*  f092b7c:	a60c0004 */ 	sh	$t4,0x4($s0)
.PB0f092b80:
/*  f092b80:	5080001f */ 	beqzl	$a0,.PB0f092c00
/*  f092b84:	306a0020 */ 	andi	$t2,$v1,0x20
/*  f092b88:	5100001d */ 	beqzl	$t0,.PB0f092c00
/*  f092b8c:	306a0020 */ 	andi	$t2,$v1,0x20
/*  f092b90:	306d8000 */ 	andi	$t5,$v1,0x8000
/*  f092b94:	11a00003 */ 	beqz	$t5,.PB0f092ba4
/*  f092b98:	01001025 */ 	move	$v0,$t0
/*  f092b9c:	10000001 */ 	b	.PB0f092ba4
/*  f092ba0:	00001025 */ 	move	$v0,$zero
.PB0f092ba4:
/*  f092ba4:	860e002c */ 	lh	$t6,0x2c($s0)
/*  f092ba8:	3c018007 */ 	lui	$at,0x8007
/*  f092bac:	2619004c */ 	addiu	$t9,$s0,0x4c
/*  f092bb0:	a42ecbd0 */ 	sh	$t6,-0x3430($at)
/*  f092bb4:	8e07003c */ 	lw	$a3,0x3c($s0)
/*  f092bb8:	8e060038 */ 	lw	$a2,0x38($s0)
/*  f092bbc:	8e050034 */ 	lw	$a1,0x34($s0)
/*  f092bc0:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f092bc4:	860f0026 */ 	lh	$t7,0x26($s0)
/*  f092bc8:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f092bcc:	86180010 */ 	lh	$t8,0x10($s0)
/*  f092bd0:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f092bd4:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f092bd8:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f092bdc:	0fc25145 */ 	jal	propsnd0f0946b0
/*  f092be0:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f092be4:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f092be8:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f092bec:	3c09800a */ 	lui	$t1,0x800a
/*  f092bf0:	2529e4d0 */ 	addiu	$t1,$t1,-6960
/*  f092bf4:	a6020004 */ 	sh	$v0,0x4($s0)
/*  f092bf8:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f092bfc:	306a0020 */ 	andi	$t2,$v1,0x20
.PB0f092c00:
/*  f092c00:	1540000f */ 	bnez	$t2,.PB0f092c40
/*  f092c04:	00000000 */ 	nop
/*  f092c08:	c604004c */ 	lwc1	$f4,0x4c($s0)
/*  f092c0c:	8e050034 */ 	lw	$a1,0x34($s0)
/*  f092c10:	8e060038 */ 	lw	$a2,0x38($s0)
/*  f092c14:	8e07003c */ 	lw	$a3,0x3c($s0)
/*  f092c18:	306b0800 */ 	andi	$t3,$v1,0x800
/*  f092c1c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f092c20:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f092c24:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f092c28:	0fc252f7 */ 	jal	propsnd0f094d78
/*  f092c2c:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f092c30:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f092c34:	3c09800a */ 	lui	$t1,0x800a
/*  f092c38:	2529e4d0 */ 	addiu	$t1,$t1,-6960
/*  f092c3c:	a602000a */ 	sh	$v0,0xa($s0)
.PB0f092c40:
/*  f092c40:	5100000a */ 	beqzl	$t0,.PB0f092c6c
/*  f092c44:	240e0001 */ 	li	$t6,0x1
/*  f092c48:	850c0000 */ 	lh	$t4,0x0($t0)
/*  f092c4c:	2401ffff */ 	li	$at,-1
/*  f092c50:	51810006 */ 	beql	$t4,$at,.PB0f092c6c
/*  f092c54:	240e0001 */ 	li	$t6,0x1
/*  f092c58:	240d0001 */ 	li	$t5,0x1
/*  f092c5c:	a600000c */ 	sh	$zero,0xc($s0)
/*  f092c60:	10000004 */ 	b	.PB0f092c74
/*  f092c64:	a20d001a */ 	sb	$t5,0x1a($s0)
/*  f092c68:	240e0001 */ 	li	$t6,0x1
.PB0f092c6c:
/*  f092c6c:	a600000c */ 	sh	$zero,0xc($s0)
/*  f092c70:	a20e001a */ 	sb	$t6,0x1a($s0)
.PB0f092c74:
/*  f092c74:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f092c78:	51e00026 */ 	beqzl	$t7,.PB0f092d14
/*  f092c7c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f092c80:	c6000044 */ 	lwc1	$f0,0x44($s0)
/*  f092c84:	44803000 */ 	mtc1	$zero,$f6
/*  f092c88:	00000000 */ 	nop
/*  f092c8c:	4600303c */ 	c.lt.s	$f6,$f0
/*  f092c90:	00000000 */ 	nop
/*  f092c94:	4502001f */ 	bc1fl	.PB0f092d14
/*  f092c98:	3c01bf80 */ 	lui	$at,0xbf80
/*  f092c9c:	c6020048 */ 	lwc1	$f2,0x48($s0)
/*  f092ca0:	44804000 */ 	mtc1	$zero,$f8
/*  f092ca4:	00000000 */ 	nop
/*  f092ca8:	4608103c */ 	c.lt.s	$f2,$f8
/*  f092cac:	00000000 */ 	nop
/*  f092cb0:	45020004 */ 	bc1fl	.PB0f092cc4
/*  f092cb4:	8e180020 */ 	lw	$t8,0x20($s0)
/*  f092cb8:	10000018 */ 	b	.PB0f092d1c
/*  f092cbc:	46000486 */ 	mov.s	$f18,$f0
/*  f092cc0:	8e180020 */ 	lw	$t8,0x20($s0)
.PB0f092cc4:
/*  f092cc4:	44802000 */ 	mtc1	$zero,$f4
/*  f092cc8:	44985000 */ 	mtc1	$t8,$f10
/*  f092ccc:	00000000 */ 	nop
/*  f092cd0:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f092cd4:	460c203c */ 	c.lt.s	$f4,$f12
/*  f092cd8:	00000000 */ 	nop
/*  f092cdc:	4500000a */ 	bc1f	.PB0f092d08
/*  f092ce0:	00000000 */ 	nop
/*  f092ce4:	8d390034 */ 	lw	$t9,0x34($t1)
/*  f092ce8:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f092cec:	44994000 */ 	mtc1	$t9,$f8
/*  f092cf0:	00000000 */ 	nop
/*  f092cf4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f092cf8:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f092cfc:	460c2203 */ 	div.s	$f8,$f4,$f12
/*  f092d00:	10000006 */ 	b	.PB0f092d1c
/*  f092d04:	46081480 */ 	add.s	$f18,$f2,$f8
.PB0f092d08:
/*  f092d08:	10000004 */ 	b	.PB0f092d1c
/*  f092d0c:	46000486 */ 	mov.s	$f18,$f0
/*  f092d10:	3c01bf80 */ 	lui	$at,0xbf80
.PB0f092d14:
/*  f092d14:	44819000 */ 	mtc1	$at,$f18
/*  f092d18:	00000000 */ 	nop
.PB0f092d1c:
/*  f092d1c:	86040006 */ 	lh	$a0,0x6($s0)
/*  f092d20:	2401ffff */ 	li	$at,-1
/*  f092d24:	8608000c */ 	lh	$t0,0xc($s0)
/*  f092d28:	14810003 */ 	bne	$a0,$at,.PB0f092d38
/*  f092d2c:	00802825 */ 	move	$a1,$a0
/*  f092d30:	10000050 */ 	b	.PB0f092e74
/*  f092d34:	86050004 */ 	lh	$a1,0x4($s0)
.PB0f092d38:
/*  f092d38:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f092d3c:	0442001a */ 	bltzl	$v0,.PB0f092da8
/*  f092d40:	86030018 */ 	lh	$v1,0x18($s0)
/*  f092d44:	8d230038 */ 	lw	$v1,0x38($t1)
/*  f092d48:	0062082a */ 	slt	$at,$v1,$v0
/*  f092d4c:	10200013 */ 	beqz	$at,.PB0f092d9c
/*  f092d50:	00437023 */ 	subu	$t6,$v0,$v1
/*  f092d54:	860a0004 */ 	lh	$t2,0x4($s0)
/*  f092d58:	01445823 */ 	subu	$t3,$t2,$a0
/*  f092d5c:	01630019 */ 	multu	$t3,$v1
/*  f092d60:	00006012 */ 	mflo	$t4
/*  f092d64:	00000000 */ 	nop
/*  f092d68:	00000000 */ 	nop
/*  f092d6c:	0182001a */ 	div	$zero,$t4,$v0
/*  f092d70:	00006812 */ 	mflo	$t5
/*  f092d74:	008d2821 */ 	addu	$a1,$a0,$t5
/*  f092d78:	14400002 */ 	bnez	$v0,.PB0f092d84
/*  f092d7c:	00000000 */ 	nop
/*  f092d80:	0007000d */ 	break	0x7
.PB0f092d84:
/*  f092d84:	2401ffff */ 	li	$at,-1
/*  f092d88:	14410004 */ 	bne	$v0,$at,.PB0f092d9c
/*  f092d8c:	3c018000 */ 	lui	$at,0x8000
/*  f092d90:	15810002 */ 	bne	$t4,$at,.PB0f092d9c
/*  f092d94:	00000000 */ 	nop
/*  f092d98:	0006000d */ 	break	0x6
.PB0f092d9c:
/*  f092d9c:	10000035 */ 	b	.PB0f092e74
/*  f092da0:	ae0e001c */ 	sw	$t6,0x1c($s0)
/*  f092da4:	86030018 */ 	lh	$v1,0x18($s0)
.PB0f092da8:
/*  f092da8:	50600032 */ 	beqzl	$v1,.PB0f092e74
/*  f092dac:	86050004 */ 	lh	$a1,0x4($s0)
/*  f092db0:	86020004 */ 	lh	$v0,0x4($s0)
/*  f092db4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f092db8:	1044002d */ 	beq	$v0,$a0,.PB0f092e70
/*  f092dbc:	00447823 */ 	subu	$t7,$v0,$a0
/*  f092dc0:	448f3000 */ 	mtc1	$t7,$f6
/*  f092dc4:	c42ad37c */ 	lwc1	$f10,-0x2c84($at)
/*  f092dc8:	c524004c */ 	lwc1	$f4,0x4c($t1)
/*  f092dcc:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f092dd0:	44833000 */ 	mtc1	$v1,$f6
/*  f092dd4:	46045202 */ 	mul.s	$f8,$f10,$f4
/*  f092dd8:	44802000 */ 	mtc1	$zero,$f4
/*  f092ddc:	3c013f80 */ 	lui	$at,0x3f80
/*  f092de0:	44818000 */ 	mtc1	$at,$f16
/*  f092de4:	460c203c */ 	c.lt.s	$f4,$f12
/*  f092de8:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f092dec:	460a4382 */ 	mul.s	$f14,$f8,$f10
/*  f092df0:	45020004 */ 	bc1fl	.PB0f092e04
/*  f092df4:	46006007 */ 	neg.s	$f0,$f12
/*  f092df8:	10000002 */ 	b	.PB0f092e04
/*  f092dfc:	46006006 */ 	mov.s	$f0,$f12
/*  f092e00:	46006007 */ 	neg.s	$f0,$f12
.PB0f092e04:
/*  f092e04:	4600803c */ 	c.lt.s	$f16,$f0
/*  f092e08:	00000000 */ 	nop
/*  f092e0c:	4502001a */ 	bc1fl	.PB0f092e78
/*  f092e10:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f092e14:	460e803c */ 	c.lt.s	$f16,$f14
/*  f092e18:	00000000 */ 	nop
/*  f092e1c:	45000002 */ 	bc1f	.PB0f092e28
/*  f092e20:	00000000 */ 	nop
/*  f092e24:	46008386 */ 	mov.s	$f14,$f16
.PB0f092e28:
/*  f092e28:	460c7082 */ 	mul.s	$f2,$f14,$f12
/*  f092e2c:	44803000 */ 	mtc1	$zero,$f6
/*  f092e30:	00000000 */ 	nop
/*  f092e34:	4602303c */ 	c.lt.s	$f6,$f2
/*  f092e38:	00000000 */ 	nop
/*  f092e3c:	45020004 */ 	bc1fl	.PB0f092e50
/*  f092e40:	46001007 */ 	neg.s	$f0,$f2
/*  f092e44:	10000002 */ 	b	.PB0f092e50
/*  f092e48:	46001006 */ 	mov.s	$f0,$f2
/*  f092e4c:	46001007 */ 	neg.s	$f0,$f2
.PB0f092e50:
/*  f092e50:	4600803c */ 	c.lt.s	$f16,$f0
/*  f092e54:	00000000 */ 	nop
/*  f092e58:	45020007 */ 	bc1fl	.PB0f092e78
/*  f092e5c:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f092e60:	4600120d */ 	trunc.w.s	$f8,$f2
/*  f092e64:	44194000 */ 	mfc1	$t9,$f8
/*  f092e68:	10000002 */ 	b	.PB0f092e74
/*  f092e6c:	00992821 */ 	addu	$a1,$a0,$t9
.PB0f092e70:
/*  f092e70:	86050004 */ 	lh	$a1,0x4($s0)
.PB0f092e74:
/*  f092e74:	afa50048 */ 	sw	$a1,0x48($sp)
.PB0f092e78:
/*  f092e78:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f092e7c:	0fc5b9b8 */ 	jal	lvIsPaused
/*  f092e80:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f092e84:	3c09800a */ 	lui	$t1,0x800a
/*  f092e88:	2529e4d0 */ 	addiu	$t1,$t1,-6960
/*  f092e8c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f092e90:	14400031 */ 	bnez	$v0,.PB0f092f58
/*  f092e94:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f092e98:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f092e9c:	0fc62c79 */ 	jal	mpIsPaused
/*  f092ea0:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f092ea4:	3c09800a */ 	lui	$t1,0x800a
/*  f092ea8:	2529e4d0 */ 	addiu	$t1,$t1,-6960
/*  f092eac:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f092eb0:	10400005 */ 	beqz	$v0,.PB0f092ec8
/*  f092eb4:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f092eb8:	960a0032 */ 	lhu	$t2,0x32($s0)
/*  f092ebc:	314b0002 */ 	andi	$t3,$t2,0x2
/*  f092ec0:	55600026 */ 	bnezl	$t3,.PB0f092f5c
/*  f092ec4:	240bffff */ 	li	$t3,-1
.PB0f092ec8:
/*  f092ec8:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f092ecc:	0fc62c79 */ 	jal	mpIsPaused
/*  f092ed0:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f092ed4:	3c09800a */ 	lui	$t1,0x800a
/*  f092ed8:	2529e4d0 */ 	addiu	$t1,$t1,-6960
/*  f092edc:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f092ee0:	10400020 */ 	beqz	$v0,.PB0f092f64
/*  f092ee4:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f092ee8:	8d2c006c */ 	lw	$t4,0x6c($t1)
/*  f092eec:	24010001 */ 	li	$at,0x1
/*  f092ef0:	00002025 */ 	move	$a0,$zero
/*  f092ef4:	11800003 */ 	beqz	$t4,.PB0f092f04
/*  f092ef8:	00001025 */ 	move	$v0,$zero
/*  f092efc:	10000001 */ 	b	.PB0f092f04
/*  f092f00:	24040001 */ 	li	$a0,0x1
.PB0f092f04:
/*  f092f04:	8d2d0068 */ 	lw	$t5,0x68($t1)
/*  f092f08:	00001825 */ 	move	$v1,$zero
/*  f092f0c:	00003825 */ 	move	$a3,$zero
/*  f092f10:	11a00003 */ 	beqz	$t5,.PB0f092f20
/*  f092f14:	00000000 */ 	nop
/*  f092f18:	10000001 */ 	b	.PB0f092f20
/*  f092f1c:	24020001 */ 	li	$v0,0x1
.PB0f092f20:
/*  f092f20:	8d2e0064 */ 	lw	$t6,0x64($t1)
/*  f092f24:	11c00003 */ 	beqz	$t6,.PB0f092f34
/*  f092f28:	00000000 */ 	nop
/*  f092f2c:	10000001 */ 	b	.PB0f092f34
/*  f092f30:	24030001 */ 	li	$v1,0x1
.PB0f092f34:
/*  f092f34:	8d2f0070 */ 	lw	$t7,0x70($t1)
/*  f092f38:	11e00003 */ 	beqz	$t7,.PB0f092f48
/*  f092f3c:	00000000 */ 	nop
/*  f092f40:	10000001 */ 	b	.PB0f092f48
/*  f092f44:	24070001 */ 	li	$a3,0x1
.PB0f092f48:
/*  f092f48:	00e3c021 */ 	addu	$t8,$a3,$v1
/*  f092f4c:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f092f50:	03245021 */ 	addu	$t2,$t9,$a0
/*  f092f54:	15410003 */ 	bne	$t2,$at,.PB0f092f64
.PB0f092f58:
/*  f092f58:	240bffff */ 	li	$t3,-1
.PB0f092f5c:
/*  f092f5c:	a60b0006 */ 	sh	$t3,0x6($s0)
/*  f092f60:	afa00048 */ 	sw	$zero,0x48($sp)
.PB0f092f64:
/*  f092f64:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f092f68:	860d0006 */ 	lh	$t5,0x6($s0)
/*  f092f6c:	44805000 */ 	mtc1	$zero,$f10
/*  f092f70:	518d0004 */ 	beql	$t4,$t5,.PB0f092f84
/*  f092f74:	240effff */ 	li	$t6,-1
/*  f092f78:	10000003 */ 	b	.PB0f092f88
/*  f092f7c:	a60c0006 */ 	sh	$t4,0x6($s0)
/*  f092f80:	240effff */ 	li	$t6,-1
.PB0f092f84:
/*  f092f84:	afae0048 */ 	sw	$t6,0x48($sp)
.PB0f092f88:
/*  f092f88:	86040008 */ 	lh	$a0,0x8($s0)
/*  f092f8c:	8602000a */ 	lh	$v0,0xa($s0)
/*  f092f90:	50820028 */ 	beql	$a0,$v0,.PB0f093034
/*  f092f94:	2419ffff */ 	li	$t9,-1
/*  f092f98:	960f0030 */ 	lhu	$t7,0x30($s0)
/*  f092f9c:	31f81000 */ 	andi	$t8,$t7,0x1000
/*  f092fa0:	53000006 */ 	beqzl	$t8,.PB0f092fbc
/*  f092fa4:	8d250034 */ 	lw	$a1,0x34($t1)
/*  f092fa8:	a6020008 */ 	sh	$v0,0x8($s0)
/*  f092fac:	86190008 */ 	lh	$t9,0x8($s0)
/*  f092fb0:	1000001b */ 	b	.PB0f093020
/*  f092fb4:	afb90044 */ 	sw	$t9,0x44($sp)
/*  f092fb8:	8d250034 */ 	lw	$a1,0x34($t1)
.PB0f092fbc:
/*  f092fbc:	240100f0 */ 	li	$at,0xf0
/*  f092fc0:	00441823 */ 	subu	$v1,$v0,$a0
/*  f092fc4:	00055240 */ 	sll	$t2,$a1,0x9
/*  f092fc8:	0141001a */ 	div	$zero,$t2,$at
/*  f092fcc:	00002812 */ 	mflo	$a1
/*  f092fd0:	24060001 */ 	li	$a2,0x1
/*  f092fd4:	04610003 */ 	bgez	$v1,.PB0f092fe4
/*  f092fd8:	00031023 */ 	negu	$v0,$v1
/*  f092fdc:	10000001 */ 	b	.PB0f092fe4
/*  f092fe0:	2406ffff */ 	li	$a2,-1
.PB0f092fe4:
/*  f092fe4:	18600003 */ 	blez	$v1,.PB0f092ff4
/*  f092fe8:	00000000 */ 	nop
/*  f092fec:	10000001 */ 	b	.PB0f092ff4
/*  f092ff0:	00601025 */ 	move	$v0,$v1
.PB0f092ff4:
/*  f092ff4:	0045082a */ 	slt	$at,$v0,$a1
/*  f092ff8:	10200003 */ 	beqz	$at,.PB0f093008
/*  f092ffc:	00a01825 */ 	move	$v1,$a1
/*  f093000:	10000001 */ 	b	.PB0f093008
/*  f093004:	00401825 */ 	move	$v1,$v0
.PB0f093008:
/*  f093008:	00660019 */ 	multu	$v1,$a2
/*  f09300c:	00006812 */ 	mflo	$t5
/*  f093010:	008d6021 */ 	addu	$t4,$a0,$t5
/*  f093014:	a60c0008 */ 	sh	$t4,0x8($s0)
/*  f093018:	860e0008 */ 	lh	$t6,0x8($s0)
/*  f09301c:	afae0044 */ 	sw	$t6,0x44($sp)
.PB0f093020:
/*  f093020:	960f0030 */ 	lhu	$t7,0x30($s0)
/*  f093024:	35f84000 */ 	ori	$t8,$t7,0x4000
/*  f093028:	10000003 */ 	b	.PB0f093038
/*  f09302c:	a6180030 */ 	sh	$t8,0x30($s0)
/*  f093030:	2419ffff */ 	li	$t9,-1
.PB0f093034:
/*  f093034:	afb90044 */ 	sw	$t9,0x44($sp)
.PB0f093038:
/*  f093038:	860a000e */ 	lh	$t2,0xe($s0)
/*  f09303c:	510a0004 */ 	beql	$t0,$t2,.PB0f093050
/*  f093040:	2408ffff */ 	li	$t0,-1
/*  f093044:	10000002 */ 	b	.PB0f093050
/*  f093048:	a608000e */ 	sh	$t0,0xe($s0)
/*  f09304c:	2408ffff */ 	li	$t0,-1
.PB0f093050:
/*  f093050:	4612503c */ 	c.lt.s	$f10,$f18
/*  f093054:	00000000 */ 	nop
/*  f093058:	45020013 */ 	bc1fl	.PB0f0930a8
/*  f09305c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f093060:	c6020048 */ 	lwc1	$f2,0x48($s0)
/*  f093064:	3c017f1b */ 	lui	$at,0x7f1b
/*  f093068:	4612103c */ 	c.lt.s	$f2,$f18
/*  f09306c:	00000000 */ 	nop
/*  f093070:	45020004 */ 	bc1fl	.PB0f093084
/*  f093074:	46029001 */ 	sub.s	$f0,$f18,$f2
/*  f093078:	10000003 */ 	b	.PB0f093088
/*  f09307c:	46029001 */ 	sub.s	$f0,$f18,$f2
/*  f093080:	46029001 */ 	sub.s	$f0,$f18,$f2
.PB0f093084:
/*  f093084:	46000007 */ 	neg.s	$f0,$f0
.PB0f093088:
/*  f093088:	c424d380 */ 	lwc1	$f4,-0x2c80($at)
/*  f09308c:	4600203c */ 	c.lt.s	$f4,$f0
/*  f093090:	00000000 */ 	nop
/*  f093094:	45020004 */ 	bc1fl	.PB0f0930a8
/*  f093098:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09309c:	10000004 */ 	b	.PB0f0930b0
/*  f0930a0:	e6120048 */ 	swc1	$f18,0x48($s0)
/*  f0930a4:	3c01bf80 */ 	lui	$at,0xbf80
.PB0f0930a8:
/*  f0930a8:	44819000 */ 	mtc1	$at,$f18
/*  f0930ac:	00000000 */ 	nop
.PB0f0930b0:
/*  f0930b0:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f0930b4:	306b0002 */ 	andi	$t3,$v1,0x2
/*  f0930b8:	51600026 */ 	beqzl	$t3,.PB0f093154
/*  f0930bc:	306c2000 */ 	andi	$t4,$v1,0x2000
/*  f0930c0:	860d0006 */ 	lh	$t5,0x6($s0)
/*  f0930c4:	306c2000 */ 	andi	$t4,$v1,0x2000
/*  f0930c8:	30792000 */ 	andi	$t9,$v1,0x2000
/*  f0930cc:	19a00008 */ 	blez	$t5,.PB0f0930f0
/*  f0930d0:	00000000 */ 	nop
/*  f0930d4:	1180001e */ 	beqz	$t4,.PB0f093150
/*  f0930d8:	306fdfff */ 	andi	$t7,$v1,0xdfff
/*  f0930dc:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f0930e0:	35f81000 */ 	ori	$t8,$t7,0x1000
/*  f0930e4:	a6180030 */ 	sh	$t8,0x30($s0)
/*  f0930e8:	10000019 */ 	b	.PB0f093150
/*  f0930ec:	3303ffff */ 	andi	$v1,$t8,0xffff
.PB0f0930f0:
/*  f0930f0:	57200015 */ 	bnezl	$t9,.PB0f093148
/*  f0930f4:	306defff */ 	andi	$t5,$v1,0xefff
/*  f0930f8:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f0930fc:	5080000e */ 	beqzl	$a0,.PB0f093138
/*  f093100:	960a0030 */ 	lhu	$t2,0x30($s0)
/*  f093104:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f093108:	0c00cf6c */ 	jal	sndGetState
/*  f09310c:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f093110:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f093114:	10400007 */ 	beqz	$v0,.PB0f093134
/*  f093118:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f09311c:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f093120:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f093124:	0c00d039 */ 	jal	audioStop
/*  f093128:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f09312c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f093130:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
.PB0f093134:
/*  f093134:	960a0030 */ 	lhu	$t2,0x30($s0)
.PB0f093138:
/*  f093138:	354b2000 */ 	ori	$t3,$t2,0x2000
/*  f09313c:	a60b0030 */ 	sh	$t3,0x30($s0)
/*  f093140:	3163ffff */ 	andi	$v1,$t3,0xffff
/*  f093144:	306defff */ 	andi	$t5,$v1,0xefff
.PB0f093148:
/*  f093148:	a60d0030 */ 	sh	$t5,0x30($s0)
/*  f09314c:	31a3ffff */ 	andi	$v1,$t5,0xffff
.PB0f093150:
/*  f093150:	306c2000 */ 	andi	$t4,$v1,0x2000
.PB0f093154:
/*  f093154:	15800068 */ 	bnez	$t4,.PB0f0932f8
/*  f093158:	306e1000 */ 	andi	$t6,$v1,0x1000
/*  f09315c:	11c00033 */ 	beqz	$t6,.PB0f09322c
/*  f093160:	02002025 */ 	move	$a0,$s0
/*  f093164:	30650010 */ 	andi	$a1,$v1,0x10
/*  f093168:	10a0000d */ 	beqz	$a1,.PB0f0931a0
/*  f09316c:	30790400 */ 	andi	$t9,$v1,0x400
/*  f093170:	960f0032 */ 	lhu	$t7,0x32($s0)
/*  f093174:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f093178:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f09317c:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f093180:	13000003 */ 	beqz	$t8,.PB0f093190
/*  f093184:	00003825 */ 	move	$a3,$zero
/*  f093188:	10000001 */ 	b	.PB0f093190
/*  f09318c:	24070001 */ 	li	$a3,0x1
.PB0f093190:
/*  f093190:	0c0042cc */ 	jal	sndStartMp3
/*  f093194:	86040026 */ 	lh	$a0,0x26($s0)
/*  f093198:	10000021 */ 	b	.PB0f093220
/*  f09319c:	96030030 */ 	lhu	$v1,0x30($s0)
.PB0f0931a0:
/*  f0931a0:	13200011 */ 	beqz	$t9,.PB0f0931e8
/*  f0931a4:	8fae0048 */ 	lw	$t6,0x48($sp)
/*  f0931a8:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f0931ac:	02002025 */ 	move	$a0,$s0
/*  f0931b0:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f0931b4:	1140001a */ 	beqz	$t2,.PB0f093220
/*  f0931b8:	01403025 */ 	move	$a2,$t2
/*  f0931bc:	860b0026 */ 	lh	$t3,0x26($s0)
/*  f0931c0:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0931c4:	240c0001 */ 	li	$t4,0x1
/*  f0931c8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0931cc:	920d001a */ 	lbu	$t5,0x1a($s0)
/*  f0931d0:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0931d4:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0931d8:	0c0041d9 */ 	jal	snd00010718
/*  f0931dc:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0931e0:	1000000f */ 	b	.PB0f093220
/*  f0931e4:	96030030 */ 	lhu	$v1,0x30($s0)
.PB0f0931e8:
/*  f0931e8:	11c0000d */ 	beqz	$t6,.PB0f093220
/*  f0931ec:	02002025 */ 	move	$a0,$s0
/*  f0931f0:	860f0026 */ 	lh	$t7,0x26($s0)
/*  f0931f4:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0931f8:	24190001 */ 	li	$t9,0x1
/*  f0931fc:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f093200:	9218001a */ 	lbu	$t8,0x1a($s0)
/*  f093204:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f093208:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f09320c:	01c03025 */ 	move	$a2,$t6
/*  f093210:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f093214:	0c0041d9 */ 	jal	snd00010718
/*  f093218:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f09321c:	96030030 */ 	lhu	$v1,0x30($s0)
.PB0f093220:
/*  f093220:	306aefff */ 	andi	$t2,$v1,0xefff
/*  f093224:	10000034 */ 	b	.PB0f0932f8
/*  f093228:	a60a0030 */ 	sh	$t2,0x30($s0)
.PB0f09322c:
/*  f09322c:	860b0026 */ 	lh	$t3,0x26($s0)
/*  f093230:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f093234:	306c4000 */ 	andi	$t4,$v1,0x4000
/*  f093238:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f09323c:	920d001a */ 	lbu	$t5,0x1a($s0)
/*  f093240:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f093244:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f093248:	30650010 */ 	andi	$a1,$v1,0x10
/*  f09324c:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f093250:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f093254:	0c00413b */ 	jal	sndAdjust
/*  f093258:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f09325c:	10000026 */ 	b	.PB0f0932f8
/*  f093260:	00000000 */ 	nop
/*  f093264:	860e0028 */ 	lh	$t6,0x28($s0)
.PB0f093268:
/*  f093268:	2401000b */ 	li	$at,0xb
/*  f09326c:	11c10022 */ 	beq	$t6,$at,.PB0f0932f8
/*  f093270:	00000000 */ 	nop
/*  f093274:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f093278:	306f0010 */ 	andi	$t7,$v1,0x10
/*  f09327c:	51e00015 */ 	beqzl	$t7,.PB0f0932d4
/*  f093280:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f093284:	0c003a80 */ 	jal	sndIsPlayingMp3
/*  f093288:	00000000 */ 	nop
/*  f09328c:	5440000e */ 	bnezl	$v0,.PB0f0932c8
/*  f093290:	240a0001 */ 	li	$t2,0x1
/*  f093294:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f093298:	30780008 */ 	andi	$t8,$v1,0x8
/*  f09329c:	53000005 */ 	beqzl	$t8,.PB0f0932b4
/*  f0932a0:	30790200 */ 	andi	$t9,$v1,0x200
/*  f0932a4:	0fc16b4d */ 	jal	propDecrementSoundCount
/*  f0932a8:	8e040050 */ 	lw	$a0,0x50($s0)
/*  f0932ac:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f0932b0:	30790200 */ 	andi	$t9,$v1,0x200
.PB0f0932b4:
/*  f0932b4:	53200004 */ 	beqzl	$t9,.PB0f0932c8
/*  f0932b8:	240a0001 */ 	li	$t2,0x1
/*  f0932bc:	0fc37875 */ 	jal	hudmsgsHideByChannel
/*  f0932c0:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f0932c4:	240a0001 */ 	li	$t2,0x1
.PB0f0932c8:
/*  f0932c8:	1000000b */ 	b	.PB0f0932f8
/*  f0932cc:	a60a0030 */ 	sh	$t2,0x30($s0)
/*  f0932d0:	8e0b0000 */ 	lw	$t3,0x0($s0)
.PB0f0932d4:
/*  f0932d4:	306d0008 */ 	andi	$t5,$v1,0x8
/*  f0932d8:	15600007 */ 	bnez	$t3,.PB0f0932f8
/*  f0932dc:	00000000 */ 	nop
/*  f0932e0:	51a00004 */ 	beqzl	$t5,.PB0f0932f4
/*  f0932e4:	240c0001 */ 	li	$t4,0x1
/*  f0932e8:	0fc16b4d */ 	jal	propDecrementSoundCount
/*  f0932ec:	8e040050 */ 	lw	$a0,0x50($s0)
/*  f0932f0:	240c0001 */ 	li	$t4,0x1
.PB0f0932f4:
/*  f0932f4:	a60c0030 */ 	sh	$t4,0x30($s0)
.PB0f0932f8:
/*  f0932f8:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0932fc:	8dcecbc4 */ 	lw	$t6,-0x343c($t6)
/*  f093300:	51c00008 */ 	beqzl	$t6,.PB0f093324
/*  f093304:	96190030 */ 	lhu	$t9,0x30($s0)
/*  f093308:	960f0032 */ 	lhu	$t7,0x32($s0)
/*  f09330c:	31f80004 */ 	andi	$t8,$t7,0x4
/*  f093310:	53000004 */ 	beqzl	$t8,.PB0f093324
/*  f093314:	96190030 */ 	lhu	$t9,0x30($s0)
/*  f093318:	0fc24a68 */ 	jal	propsndPrintChannel
/*  f09331c:	02002025 */ 	move	$a0,$s0
/*  f093320:	96190030 */ 	lhu	$t9,0x30($s0)
.PB0f093324:
/*  f093324:	332befff */ 	andi	$t3,$t9,0xefff
/*  f093328:	a60b0030 */ 	sh	$t3,0x30($s0)
/*  f09332c:	316dbfff */ 	andi	$t5,$t3,0xbfff
/*  f093330:	a60d0030 */ 	sh	$t5,0x30($s0)
/*  f093334:	8fbf0034 */ 	lw	$ra,0x34($sp)
.PB0f093338:
/*  f093338:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f09333c:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f093340:	03e00008 */ 	jr	$ra
/*  f093344:	00000000 */ 	nop
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel propsndTickChannel
.late_rodata
glabel var7f1ab73c
.word 0x392ec33e
glabel var7f1ab740
.word 0x3c23d70a
.text
/*  f092c04:	3c188007 */ 	lui	$t8,%hi(g_AudioChannels)
/*  f092c08:	8f18ae10 */ 	lw	$t8,%lo(g_AudioChannels)($t8)
/*  f092c0c:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f092c10:	00047900 */ 	sll	$t7,$a0,0x4
/*  f092c14:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f092c18:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f092c1c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f092c20:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f092c24:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f092c28:	01f88021 */ 	addu	$s0,$t7,$t8
/*  f092c2c:	96190032 */ 	lhu	$t9,0x32($s0)
/*  f092c30:	00807025 */ 	or	$t6,$a0,$zero
/*  f092c34:	332a0080 */ 	andi	$t2,$t9,0x80
/*  f092c38:	554001fb */ 	bnezl	$t2,.L0f093428
/*  f092c3c:	860f0028 */ 	lh	$t7,0x28($s0)
/*  f092c40:	860b0028 */ 	lh	$t3,0x28($s0)
/*  f092c44:	2401000b */ 	addiu	$at,$zero,0xb
/*  f092c48:	516101f7 */ 	beql	$t3,$at,.L0f093428
/*  f092c4c:	860f0028 */ 	lh	$t7,0x28($s0)
/*  f092c50:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f092c54:	50800006 */ 	beqzl	$a0,.L0f092c70
/*  f092c58:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f092c5c:	0c00cdfc */ 	jal	sndGetState
/*  f092c60:	00000000 */ 	nop
/*  f092c64:	54400010 */ 	bnezl	$v0,.L0f092ca8
/*  f092c68:	8e020050 */ 	lw	$v0,0x50($s0)
/*  f092c6c:	96030030 */ 	lhu	$v1,0x30($s0)
.L0f092c70:
/*  f092c70:	306c0002 */ 	andi	$t4,$v1,0x2
/*  f092c74:	5580000c */ 	bnezl	$t4,.L0f092ca8
/*  f092c78:	8e020050 */ 	lw	$v0,0x50($s0)
/*  f092c7c:	306d1000 */ 	andi	$t5,$v1,0x1000
/*  f092c80:	55a00009 */ 	bnezl	$t5,.L0f092ca8
/*  f092c84:	8e020050 */ 	lw	$v0,0x50($s0)
/*  f092c88:	306e0010 */ 	andi	$t6,$v1,0x10
/*  f092c8c:	51c001e6 */ 	beqzl	$t6,.L0f093428
/*  f092c90:	860f0028 */ 	lh	$t7,0x28($s0)
/*  f092c94:	0c003a74 */ 	jal	sndIsPlayingMp3
/*  f092c98:	00000000 */ 	nop
/*  f092c9c:	504001e2 */ 	beqzl	$v0,.L0f093428
/*  f092ca0:	860f0028 */ 	lh	$t7,0x28($s0)
/*  f092ca4:	8e020050 */ 	lw	$v0,0x50($s0)
.L0f092ca8:
/*  f092ca8:	00002025 */ 	or	$a0,$zero,$zero
/*  f092cac:	00004025 */ 	or	$t0,$zero,$zero
/*  f092cb0:	10400004 */ 	beqz	$v0,.L0f092cc4
/*  f092cb4:	96050032 */ 	lhu	$a1,0x32($s0)
/*  f092cb8:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f092cbc:	10000006 */ 	b	.L0f092cd8
/*  f092cc0:	24480028 */ 	addiu	$t0,$v0,0x28
.L0f092cc4:
/*  f092cc4:	860f0064 */ 	lh	$t7,0x64($s0)
/*  f092cc8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f092ccc:	51e10003 */ 	beql	$t7,$at,.L0f092cdc
/*  f092cd0:	8e020054 */ 	lw	$v0,0x54($s0)
/*  f092cd4:	26080064 */ 	addiu	$t0,$s0,0x64
.L0f092cd8:
/*  f092cd8:	8e020054 */ 	lw	$v0,0x54($s0)
.L0f092cdc:
/*  f092cdc:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f092ce0:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f092ce4:	10400002 */ 	beqz	$v0,.L0f092cf0
/*  f092ce8:	30aa0010 */ 	andi	$t2,$a1,0x10
/*  f092cec:	00402025 */ 	or	$a0,$v0,$zero
.L0f092cf0:
/*  f092cf0:	913804e3 */ 	lbu	$t8,0x4e3($t1)
/*  f092cf4:	13000006 */ 	beqz	$t8,.L0f092d10
/*  f092cf8:	00000000 */ 	nop
/*  f092cfc:	30b90020 */ 	andi	$t9,$a1,0x20
/*  f092d00:	13200003 */ 	beqz	$t9,.L0f092d10
/*  f092d04:	00000000 */ 	nop
/*  f092d08:	10000039 */ 	b	.L0f092df0
/*  f092d0c:	a6000004 */ 	sh	$zero,0x4($s0)
.L0f092d10:
/*  f092d10:	11400007 */ 	beqz	$t2,.L0f092d30
/*  f092d14:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f092d18:	306b1000 */ 	andi	$t3,$v1,0x1000
/*  f092d1c:	516001f6 */ 	beqzl	$t3,.L0f0934f8
/*  f092d20:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f092d24:	860c0010 */ 	lh	$t4,0x10($s0)
/*  f092d28:	10000031 */ 	b	.L0f092df0
/*  f092d2c:	a60c0004 */ 	sh	$t4,0x4($s0)
.L0f092d30:
/*  f092d30:	5080001f */ 	beqzl	$a0,.L0f092db0
/*  f092d34:	306a0020 */ 	andi	$t2,$v1,0x20
/*  f092d38:	5100001d */ 	beqzl	$t0,.L0f092db0
/*  f092d3c:	306a0020 */ 	andi	$t2,$v1,0x20
/*  f092d40:	306d8000 */ 	andi	$t5,$v1,0x8000
/*  f092d44:	11a00003 */ 	beqz	$t5,.L0f092d54
/*  f092d48:	01001025 */ 	or	$v0,$t0,$zero
/*  f092d4c:	10000001 */ 	b	.L0f092d54
/*  f092d50:	00001025 */ 	or	$v0,$zero,$zero
.L0f092d54:
/*  f092d54:	860e002c */ 	lh	$t6,0x2c($s0)
/*  f092d58:	3c018007 */ 	lui	$at,%hi(var8006ae50)
/*  f092d5c:	2619004c */ 	addiu	$t9,$s0,0x4c
/*  f092d60:	a42eae50 */ 	sh	$t6,%lo(var8006ae50)($at)
/*  f092d64:	8e07003c */ 	lw	$a3,0x3c($s0)
/*  f092d68:	8e060038 */ 	lw	$a2,0x38($s0)
/*  f092d6c:	8e050034 */ 	lw	$a1,0x34($s0)
/*  f092d70:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f092d74:	860f0026 */ 	lh	$t7,0x26($s0)
/*  f092d78:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f092d7c:	86180010 */ 	lh	$t8,0x10($s0)
/*  f092d80:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f092d84:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f092d88:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f092d8c:	0fc251ac */ 	jal	propsnd0f0946b0
/*  f092d90:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f092d94:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f092d98:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f092d9c:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f092da0:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f092da4:	a6020004 */ 	sh	$v0,0x4($s0)
/*  f092da8:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f092dac:	306a0020 */ 	andi	$t2,$v1,0x20
.L0f092db0:
/*  f092db0:	1540000f */ 	bnez	$t2,.L0f092df0
/*  f092db4:	00000000 */ 	nop
/*  f092db8:	c604004c */ 	lwc1	$f4,0x4c($s0)
/*  f092dbc:	8e050034 */ 	lw	$a1,0x34($s0)
/*  f092dc0:	8e060038 */ 	lw	$a2,0x38($s0)
/*  f092dc4:	8e07003c */ 	lw	$a3,0x3c($s0)
/*  f092dc8:	306b0800 */ 	andi	$t3,$v1,0x800
/*  f092dcc:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f092dd0:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f092dd4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f092dd8:	0fc2535e */ 	jal	propsnd0f094d78
/*  f092ddc:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f092de0:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f092de4:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f092de8:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f092dec:	a602000a */ 	sh	$v0,0xa($s0)
.L0f092df0:
/*  f092df0:	5100000a */ 	beqzl	$t0,.L0f092e1c
/*  f092df4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f092df8:	850c0000 */ 	lh	$t4,0x0($t0)
/*  f092dfc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f092e00:	51810006 */ 	beql	$t4,$at,.L0f092e1c
/*  f092e04:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f092e08:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f092e0c:	a600000c */ 	sh	$zero,0xc($s0)
/*  f092e10:	10000004 */ 	b	.L0f092e24
/*  f092e14:	a20d001a */ 	sb	$t5,0x1a($s0)
/*  f092e18:	240e0001 */ 	addiu	$t6,$zero,0x1
.L0f092e1c:
/*  f092e1c:	a600000c */ 	sh	$zero,0xc($s0)
/*  f092e20:	a20e001a */ 	sb	$t6,0x1a($s0)
.L0f092e24:
/*  f092e24:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f092e28:	51e00026 */ 	beqzl	$t7,.L0f092ec4
/*  f092e2c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f092e30:	c6000044 */ 	lwc1	$f0,0x44($s0)
/*  f092e34:	44803000 */ 	mtc1	$zero,$f6
/*  f092e38:	00000000 */ 	nop
/*  f092e3c:	4600303c */ 	c.lt.s	$f6,$f0
/*  f092e40:	00000000 */ 	nop
/*  f092e44:	4502001f */ 	bc1fl	.L0f092ec4
/*  f092e48:	3c01bf80 */ 	lui	$at,0xbf80
/*  f092e4c:	c6020048 */ 	lwc1	$f2,0x48($s0)
/*  f092e50:	44804000 */ 	mtc1	$zero,$f8
/*  f092e54:	00000000 */ 	nop
/*  f092e58:	4608103c */ 	c.lt.s	$f2,$f8
/*  f092e5c:	00000000 */ 	nop
/*  f092e60:	45020004 */ 	bc1fl	.L0f092e74
/*  f092e64:	8e180020 */ 	lw	$t8,0x20($s0)
/*  f092e68:	10000018 */ 	b	.L0f092ecc
/*  f092e6c:	46000486 */ 	mov.s	$f18,$f0
/*  f092e70:	8e180020 */ 	lw	$t8,0x20($s0)
.L0f092e74:
/*  f092e74:	44802000 */ 	mtc1	$zero,$f4
/*  f092e78:	44985000 */ 	mtc1	$t8,$f10
/*  f092e7c:	00000000 */ 	nop
/*  f092e80:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f092e84:	460c203c */ 	c.lt.s	$f4,$f12
/*  f092e88:	00000000 */ 	nop
/*  f092e8c:	4500000a */ 	bc1f	.L0f092eb8
/*  f092e90:	00000000 */ 	nop
/*  f092e94:	8d390034 */ 	lw	$t9,0x34($t1)
/*  f092e98:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f092e9c:	44994000 */ 	mtc1	$t9,$f8
/*  f092ea0:	00000000 */ 	nop
/*  f092ea4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f092ea8:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f092eac:	460c2203 */ 	div.s	$f8,$f4,$f12
/*  f092eb0:	10000006 */ 	b	.L0f092ecc
/*  f092eb4:	46081480 */ 	add.s	$f18,$f2,$f8
.L0f092eb8:
/*  f092eb8:	10000004 */ 	b	.L0f092ecc
/*  f092ebc:	46000486 */ 	mov.s	$f18,$f0
/*  f092ec0:	3c01bf80 */ 	lui	$at,0xbf80
.L0f092ec4:
/*  f092ec4:	44819000 */ 	mtc1	$at,$f18
/*  f092ec8:	00000000 */ 	nop
.L0f092ecc:
/*  f092ecc:	86040006 */ 	lh	$a0,0x6($s0)
/*  f092ed0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f092ed4:	8608000c */ 	lh	$t0,0xc($s0)
/*  f092ed8:	14810003 */ 	bne	$a0,$at,.L0f092ee8
/*  f092edc:	00802825 */ 	or	$a1,$a0,$zero
/*  f092ee0:	10000054 */ 	b	.L0f093034
/*  f092ee4:	86050004 */ 	lh	$a1,0x4($s0)
.L0f092ee8:
/*  f092ee8:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f092eec:	0442001a */ 	bltzl	$v0,.L0f092f58
/*  f092ef0:	86030018 */ 	lh	$v1,0x18($s0)
/*  f092ef4:	8d230038 */ 	lw	$v1,0x38($t1)
/*  f092ef8:	0062082a */ 	slt	$at,$v1,$v0
/*  f092efc:	10200013 */ 	beqz	$at,.L0f092f4c
/*  f092f00:	00437023 */ 	subu	$t6,$v0,$v1
/*  f092f04:	860a0004 */ 	lh	$t2,0x4($s0)
/*  f092f08:	01445823 */ 	subu	$t3,$t2,$a0
/*  f092f0c:	01630019 */ 	multu	$t3,$v1
/*  f092f10:	00006012 */ 	mflo	$t4
/*  f092f14:	00000000 */ 	nop
/*  f092f18:	00000000 */ 	nop
/*  f092f1c:	0182001a */ 	div	$zero,$t4,$v0
/*  f092f20:	00006812 */ 	mflo	$t5
/*  f092f24:	008d2821 */ 	addu	$a1,$a0,$t5
/*  f092f28:	14400002 */ 	bnez	$v0,.L0f092f34
/*  f092f2c:	00000000 */ 	nop
/*  f092f30:	0007000d */ 	break	0x7
.L0f092f34:
/*  f092f34:	2401ffff */ 	addiu	$at,$zero,-1
/*  f092f38:	14410004 */ 	bne	$v0,$at,.L0f092f4c
/*  f092f3c:	3c018000 */ 	lui	$at,0x8000
/*  f092f40:	15810002 */ 	bne	$t4,$at,.L0f092f4c
/*  f092f44:	00000000 */ 	nop
/*  f092f48:	0006000d */ 	break	0x6
.L0f092f4c:
/*  f092f4c:	10000039 */ 	b	.L0f093034
/*  f092f50:	ae0e001c */ 	sw	$t6,0x1c($s0)
/*  f092f54:	86030018 */ 	lh	$v1,0x18($s0)
.L0f092f58:
/*  f092f58:	50600036 */ 	beqzl	$v1,.L0f093034
/*  f092f5c:	86050004 */ 	lh	$a1,0x4($s0)
/*  f092f60:	86020004 */ 	lh	$v0,0x4($s0)
/*  f092f64:	50440033 */ 	beql	$v0,$a0,.L0f093034
/*  f092f68:	86050004 */ 	lh	$a1,0x4($s0)
/*  f092f6c:	8d380038 */ 	lw	$t8,0x38($t1)
/*  f092f70:	00447823 */ 	subu	$t7,$v0,$a0
/*  f092f74:	448f3000 */ 	mtc1	$t7,$f6
/*  f092f78:	44985000 */ 	mtc1	$t8,$f10
/*  f092f7c:	3c017f1b */ 	lui	$at,%hi(var7f1ab73c)
/*  f092f80:	c428b73c */ 	lwc1	$f8,%lo(var7f1ab73c)($at)
/*  f092f84:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f092f88:	44835000 */ 	mtc1	$v1,$f10
/*  f092f8c:	3c013f80 */ 	lui	$at,0x3f80
/*  f092f90:	44818000 */ 	mtc1	$at,$f16
/*  f092f94:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f092f98:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f092f9c:	44804000 */ 	mtc1	$zero,$f8
/*  f092fa0:	00000000 */ 	nop
/*  f092fa4:	460c403c */ 	c.lt.s	$f8,$f12
/*  f092fa8:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f092fac:	46043382 */ 	mul.s	$f14,$f6,$f4
/*  f092fb0:	45020004 */ 	bc1fl	.L0f092fc4
/*  f092fb4:	46006007 */ 	neg.s	$f0,$f12
/*  f092fb8:	10000002 */ 	b	.L0f092fc4
/*  f092fbc:	46006006 */ 	mov.s	$f0,$f12
/*  f092fc0:	46006007 */ 	neg.s	$f0,$f12
.L0f092fc4:
/*  f092fc4:	4600803c */ 	c.lt.s	$f16,$f0
/*  f092fc8:	00000000 */ 	nop
/*  f092fcc:	4502001a */ 	bc1fl	.L0f093038
/*  f092fd0:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f092fd4:	460e803c */ 	c.lt.s	$f16,$f14
/*  f092fd8:	00000000 */ 	nop
/*  f092fdc:	45000002 */ 	bc1f	.L0f092fe8
/*  f092fe0:	00000000 */ 	nop
/*  f092fe4:	46008386 */ 	mov.s	$f14,$f16
.L0f092fe8:
/*  f092fe8:	460c7082 */ 	mul.s	$f2,$f14,$f12
/*  f092fec:	44805000 */ 	mtc1	$zero,$f10
/*  f092ff0:	00000000 */ 	nop
/*  f092ff4:	4602503c */ 	c.lt.s	$f10,$f2
/*  f092ff8:	00000000 */ 	nop
/*  f092ffc:	45020004 */ 	bc1fl	.L0f093010
/*  f093000:	46001007 */ 	neg.s	$f0,$f2
/*  f093004:	10000002 */ 	b	.L0f093010
/*  f093008:	46001006 */ 	mov.s	$f0,$f2
/*  f09300c:	46001007 */ 	neg.s	$f0,$f2
.L0f093010:
/*  f093010:	4600803c */ 	c.lt.s	$f16,$f0
/*  f093014:	00000000 */ 	nop
/*  f093018:	45020007 */ 	bc1fl	.L0f093038
/*  f09301c:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f093020:	4600118d */ 	trunc.w.s	$f6,$f2
/*  f093024:	440a3000 */ 	mfc1	$t2,$f6
/*  f093028:	10000002 */ 	b	.L0f093034
/*  f09302c:	008a2821 */ 	addu	$a1,$a0,$t2
/*  f093030:	86050004 */ 	lh	$a1,0x4($s0)
.L0f093034:
/*  f093034:	afa50048 */ 	sw	$a1,0x48($sp)
.L0f093038:
/*  f093038:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f09303c:	0fc5b364 */ 	jal	lvIsPaused
/*  f093040:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f093044:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f093048:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f09304c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f093050:	14400031 */ 	bnez	$v0,.L0f093118
/*  f093054:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f093058:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f09305c:	0fc62590 */ 	jal	mpIsPaused
/*  f093060:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f093064:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f093068:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f09306c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f093070:	10400005 */ 	beqz	$v0,.L0f093088
/*  f093074:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f093078:	960b0032 */ 	lhu	$t3,0x32($s0)
/*  f09307c:	316c0002 */ 	andi	$t4,$t3,0x2
/*  f093080:	55800026 */ 	bnezl	$t4,.L0f09311c
/*  f093084:	240cffff */ 	addiu	$t4,$zero,-1
.L0f093088:
/*  f093088:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f09308c:	0fc62590 */ 	jal	mpIsPaused
/*  f093090:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f093094:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f093098:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f09309c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f0930a0:	10400020 */ 	beqz	$v0,.L0f093124
/*  f0930a4:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f0930a8:	8d2d006c */ 	lw	$t5,0x6c($t1)
/*  f0930ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0930b0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0930b4:	11a00003 */ 	beqz	$t5,.L0f0930c4
/*  f0930b8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0930bc:	10000001 */ 	b	.L0f0930c4
/*  f0930c0:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0930c4:
/*  f0930c4:	8d2e0068 */ 	lw	$t6,0x68($t1)
/*  f0930c8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0930cc:	00003825 */ 	or	$a3,$zero,$zero
/*  f0930d0:	11c00003 */ 	beqz	$t6,.L0f0930e0
/*  f0930d4:	00000000 */ 	nop
/*  f0930d8:	10000001 */ 	b	.L0f0930e0
/*  f0930dc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0930e0:
/*  f0930e0:	8d2f0064 */ 	lw	$t7,0x64($t1)
/*  f0930e4:	11e00003 */ 	beqz	$t7,.L0f0930f4
/*  f0930e8:	00000000 */ 	nop
/*  f0930ec:	10000001 */ 	b	.L0f0930f4
/*  f0930f0:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0930f4:
/*  f0930f4:	8d380070 */ 	lw	$t8,0x70($t1)
/*  f0930f8:	13000003 */ 	beqz	$t8,.L0f093108
/*  f0930fc:	00000000 */ 	nop
/*  f093100:	10000001 */ 	b	.L0f093108
/*  f093104:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f093108:
/*  f093108:	00e3c821 */ 	addu	$t9,$a3,$v1
/*  f09310c:	03225021 */ 	addu	$t2,$t9,$v0
/*  f093110:	01445821 */ 	addu	$t3,$t2,$a0
/*  f093114:	15610003 */ 	bne	$t3,$at,.L0f093124
.L0f093118:
/*  f093118:	240cffff */ 	addiu	$t4,$zero,-1
.L0f09311c:
/*  f09311c:	a60c0006 */ 	sh	$t4,0x6($s0)
/*  f093120:	afa00048 */ 	sw	$zero,0x48($sp)
.L0f093124:
/*  f093124:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f093128:	860e0006 */ 	lh	$t6,0x6($s0)
/*  f09312c:	44802000 */ 	mtc1	$zero,$f4
/*  f093130:	51ae0004 */ 	beql	$t5,$t6,.L0f093144
/*  f093134:	240fffff */ 	addiu	$t7,$zero,-1
/*  f093138:	10000003 */ 	b	.L0f093148
/*  f09313c:	a60d0006 */ 	sh	$t5,0x6($s0)
/*  f093140:	240fffff */ 	addiu	$t7,$zero,-1
.L0f093144:
/*  f093144:	afaf0048 */ 	sw	$t7,0x48($sp)
.L0f093148:
/*  f093148:	86040008 */ 	lh	$a0,0x8($s0)
/*  f09314c:	8602000a */ 	lh	$v0,0xa($s0)
/*  f093150:	50820028 */ 	beql	$a0,$v0,.L0f0931f4
/*  f093154:	240affff */ 	addiu	$t2,$zero,-1
/*  f093158:	96180030 */ 	lhu	$t8,0x30($s0)
/*  f09315c:	33191000 */ 	andi	$t9,$t8,0x1000
/*  f093160:	53200006 */ 	beqzl	$t9,.L0f09317c
/*  f093164:	8d250034 */ 	lw	$a1,0x34($t1)
/*  f093168:	a6020008 */ 	sh	$v0,0x8($s0)
/*  f09316c:	860a0008 */ 	lh	$t2,0x8($s0)
/*  f093170:	1000001b */ 	b	.L0f0931e0
/*  f093174:	afaa0044 */ 	sw	$t2,0x44($sp)
/*  f093178:	8d250034 */ 	lw	$a1,0x34($t1)
.L0f09317c:
/*  f09317c:	240100f0 */ 	addiu	$at,$zero,0xf0
/*  f093180:	00441823 */ 	subu	$v1,$v0,$a0
/*  f093184:	00055a40 */ 	sll	$t3,$a1,0x9
/*  f093188:	0161001a */ 	div	$zero,$t3,$at
/*  f09318c:	00002812 */ 	mflo	$a1
/*  f093190:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f093194:	04610003 */ 	bgez	$v1,.L0f0931a4
/*  f093198:	00031023 */ 	negu	$v0,$v1
/*  f09319c:	10000001 */ 	b	.L0f0931a4
/*  f0931a0:	2406ffff */ 	addiu	$a2,$zero,-1
.L0f0931a4:
/*  f0931a4:	18600003 */ 	blez	$v1,.L0f0931b4
/*  f0931a8:	00000000 */ 	nop
/*  f0931ac:	10000001 */ 	b	.L0f0931b4
/*  f0931b0:	00601025 */ 	or	$v0,$v1,$zero
.L0f0931b4:
/*  f0931b4:	0045082a */ 	slt	$at,$v0,$a1
/*  f0931b8:	10200003 */ 	beqz	$at,.L0f0931c8
/*  f0931bc:	00a01825 */ 	or	$v1,$a1,$zero
/*  f0931c0:	10000001 */ 	b	.L0f0931c8
/*  f0931c4:	00401825 */ 	or	$v1,$v0,$zero
.L0f0931c8:
/*  f0931c8:	00660019 */ 	multu	$v1,$a2
/*  f0931cc:	00007012 */ 	mflo	$t6
/*  f0931d0:	008e6821 */ 	addu	$t5,$a0,$t6
/*  f0931d4:	a60d0008 */ 	sh	$t5,0x8($s0)
/*  f0931d8:	860f0008 */ 	lh	$t7,0x8($s0)
/*  f0931dc:	afaf0044 */ 	sw	$t7,0x44($sp)
.L0f0931e0:
/*  f0931e0:	96180030 */ 	lhu	$t8,0x30($s0)
/*  f0931e4:	37194000 */ 	ori	$t9,$t8,0x4000
/*  f0931e8:	10000003 */ 	b	.L0f0931f8
/*  f0931ec:	a6190030 */ 	sh	$t9,0x30($s0)
/*  f0931f0:	240affff */ 	addiu	$t2,$zero,-1
.L0f0931f4:
/*  f0931f4:	afaa0044 */ 	sw	$t2,0x44($sp)
.L0f0931f8:
/*  f0931f8:	860b000e */ 	lh	$t3,0xe($s0)
/*  f0931fc:	510b0004 */ 	beql	$t0,$t3,.L0f093210
/*  f093200:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f093204:	10000002 */ 	b	.L0f093210
/*  f093208:	a608000e */ 	sh	$t0,0xe($s0)
/*  f09320c:	2408ffff */ 	addiu	$t0,$zero,-1
.L0f093210:
/*  f093210:	4612203c */ 	c.lt.s	$f4,$f18
/*  f093214:	00000000 */ 	nop
/*  f093218:	45020013 */ 	bc1fl	.L0f093268
/*  f09321c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f093220:	c6020048 */ 	lwc1	$f2,0x48($s0)
/*  f093224:	3c017f1b */ 	lui	$at,%hi(var7f1ab740)
/*  f093228:	4612103c */ 	c.lt.s	$f2,$f18
/*  f09322c:	00000000 */ 	nop
/*  f093230:	45020004 */ 	bc1fl	.L0f093244
/*  f093234:	46029001 */ 	sub.s	$f0,$f18,$f2
/*  f093238:	10000003 */ 	b	.L0f093248
/*  f09323c:	46029001 */ 	sub.s	$f0,$f18,$f2
/*  f093240:	46029001 */ 	sub.s	$f0,$f18,$f2
.L0f093244:
/*  f093244:	46000007 */ 	neg.s	$f0,$f0
.L0f093248:
/*  f093248:	c428b740 */ 	lwc1	$f8,%lo(var7f1ab740)($at)
/*  f09324c:	4600403c */ 	c.lt.s	$f8,$f0
/*  f093250:	00000000 */ 	nop
/*  f093254:	45020004 */ 	bc1fl	.L0f093268
/*  f093258:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09325c:	10000004 */ 	b	.L0f093270
/*  f093260:	e6120048 */ 	swc1	$f18,0x48($s0)
/*  f093264:	3c01bf80 */ 	lui	$at,0xbf80
.L0f093268:
/*  f093268:	44819000 */ 	mtc1	$at,$f18
/*  f09326c:	00000000 */ 	nop
.L0f093270:
/*  f093270:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f093274:	306c0002 */ 	andi	$t4,$v1,0x2
/*  f093278:	51800026 */ 	beqzl	$t4,.L0f093314
/*  f09327c:	306d2000 */ 	andi	$t5,$v1,0x2000
/*  f093280:	860e0006 */ 	lh	$t6,0x6($s0)
/*  f093284:	306d2000 */ 	andi	$t5,$v1,0x2000
/*  f093288:	306a2000 */ 	andi	$t2,$v1,0x2000
/*  f09328c:	19c00008 */ 	blez	$t6,.L0f0932b0
/*  f093290:	00000000 */ 	nop
/*  f093294:	11a0001e */ 	beqz	$t5,.L0f093310
/*  f093298:	3078dfff */ 	andi	$t8,$v1,0xdfff
/*  f09329c:	a6180030 */ 	sh	$t8,0x30($s0)
/*  f0932a0:	37191000 */ 	ori	$t9,$t8,0x1000
/*  f0932a4:	a6190030 */ 	sh	$t9,0x30($s0)
/*  f0932a8:	10000019 */ 	b	.L0f093310
/*  f0932ac:	3323ffff */ 	andi	$v1,$t9,0xffff
.L0f0932b0:
/*  f0932b0:	55400015 */ 	bnezl	$t2,.L0f093308
/*  f0932b4:	306eefff */ 	andi	$t6,$v1,0xefff
/*  f0932b8:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f0932bc:	5080000e */ 	beqzl	$a0,.L0f0932f8
/*  f0932c0:	960b0030 */ 	lhu	$t3,0x30($s0)
/*  f0932c4:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f0932c8:	0c00cdfc */ 	jal	sndGetState
/*  f0932cc:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f0932d0:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f0932d4:	10400007 */ 	beqz	$v0,.L0f0932f4
/*  f0932d8:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f0932dc:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f0932e0:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f0932e4:	0c00cec9 */ 	jal	audioStop
/*  f0932e8:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f0932ec:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f0932f0:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
.L0f0932f4:
/*  f0932f4:	960b0030 */ 	lhu	$t3,0x30($s0)
.L0f0932f8:
/*  f0932f8:	356c2000 */ 	ori	$t4,$t3,0x2000
/*  f0932fc:	a60c0030 */ 	sh	$t4,0x30($s0)
/*  f093300:	3183ffff */ 	andi	$v1,$t4,0xffff
/*  f093304:	306eefff */ 	andi	$t6,$v1,0xefff
.L0f093308:
/*  f093308:	a60e0030 */ 	sh	$t6,0x30($s0)
/*  f09330c:	31c3ffff */ 	andi	$v1,$t6,0xffff
.L0f093310:
/*  f093310:	306d2000 */ 	andi	$t5,$v1,0x2000
.L0f093314:
/*  f093314:	15a00068 */ 	bnez	$t5,.L0f0934b8
/*  f093318:	306f1000 */ 	andi	$t7,$v1,0x1000
/*  f09331c:	11e00033 */ 	beqz	$t7,.L0f0933ec
/*  f093320:	02002025 */ 	or	$a0,$s0,$zero
/*  f093324:	30650010 */ 	andi	$a1,$v1,0x10
/*  f093328:	10a0000d */ 	beqz	$a1,.L0f093360
/*  f09332c:	306a0400 */ 	andi	$t2,$v1,0x400
/*  f093330:	96180032 */ 	lhu	$t8,0x32($s0)
/*  f093334:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f093338:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f09333c:	33190001 */ 	andi	$t9,$t8,0x1
/*  f093340:	13200003 */ 	beqz	$t9,.L0f093350
/*  f093344:	00003825 */ 	or	$a3,$zero,$zero
/*  f093348:	10000001 */ 	b	.L0f093350
/*  f09334c:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f093350:
/*  f093350:	0c0042b9 */ 	jal	sndStartMp3
/*  f093354:	86040026 */ 	lh	$a0,0x26($s0)
/*  f093358:	10000021 */ 	b	.L0f0933e0
/*  f09335c:	96030030 */ 	lhu	$v1,0x30($s0)
.L0f093360:
/*  f093360:	11400011 */ 	beqz	$t2,.L0f0933a8
/*  f093364:	8faf0048 */ 	lw	$t7,0x48($sp)
/*  f093368:	8fab0048 */ 	lw	$t3,0x48($sp)
/*  f09336c:	02002025 */ 	or	$a0,$s0,$zero
/*  f093370:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f093374:	1160001a */ 	beqz	$t3,.L0f0933e0
/*  f093378:	01603025 */ 	or	$a2,$t3,$zero
/*  f09337c:	860c0026 */ 	lh	$t4,0x26($s0)
/*  f093380:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f093384:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f093388:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f09338c:	920e001a */ 	lbu	$t6,0x1a($s0)
/*  f093390:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f093394:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f093398:	0c0041c6 */ 	jal	snd00010718
/*  f09339c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0933a0:	1000000f */ 	b	.L0f0933e0
/*  f0933a4:	96030030 */ 	lhu	$v1,0x30($s0)
.L0f0933a8:
/*  f0933a8:	11e0000d */ 	beqz	$t7,.L0f0933e0
/*  f0933ac:	02002025 */ 	or	$a0,$s0,$zero
/*  f0933b0:	86180026 */ 	lh	$t8,0x26($s0)
/*  f0933b4:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0933b8:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0933bc:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0933c0:	9219001a */ 	lbu	$t9,0x1a($s0)
/*  f0933c4:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f0933c8:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f0933cc:	01e03025 */ 	or	$a2,$t7,$zero
/*  f0933d0:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f0933d4:	0c0041c6 */ 	jal	snd00010718
/*  f0933d8:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0933dc:	96030030 */ 	lhu	$v1,0x30($s0)
.L0f0933e0:
/*  f0933e0:	306befff */ 	andi	$t3,$v1,0xefff
/*  f0933e4:	10000034 */ 	b	.L0f0934b8
/*  f0933e8:	a60b0030 */ 	sh	$t3,0x30($s0)
.L0f0933ec:
/*  f0933ec:	860c0026 */ 	lh	$t4,0x26($s0)
/*  f0933f0:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f0933f4:	306d4000 */ 	andi	$t5,$v1,0x4000
/*  f0933f8:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0933fc:	920e001a */ 	lbu	$t6,0x1a($s0)
/*  f093400:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f093404:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f093408:	30650010 */ 	andi	$a1,$v1,0x10
/*  f09340c:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f093410:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f093414:	0c004128 */ 	jal	sndAdjust
/*  f093418:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f09341c:	10000026 */ 	b	.L0f0934b8
/*  f093420:	00000000 */ 	nop
/*  f093424:	860f0028 */ 	lh	$t7,0x28($s0)
.L0f093428:
/*  f093428:	2401000b */ 	addiu	$at,$zero,0xb
/*  f09342c:	11e10022 */ 	beq	$t7,$at,.L0f0934b8
/*  f093430:	00000000 */ 	nop
/*  f093434:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f093438:	30780010 */ 	andi	$t8,$v1,0x10
/*  f09343c:	53000015 */ 	beqzl	$t8,.L0f093494
/*  f093440:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f093444:	0c003a74 */ 	jal	sndIsPlayingMp3
/*  f093448:	00000000 */ 	nop
/*  f09344c:	5440000e */ 	bnezl	$v0,.L0f093488
/*  f093450:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f093454:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f093458:	30790008 */ 	andi	$t9,$v1,0x8
/*  f09345c:	53200005 */ 	beqzl	$t9,.L0f093474
/*  f093460:	306a0200 */ 	andi	$t2,$v1,0x200
/*  f093464:	0fc16af7 */ 	jal	propDecrementSoundCount
/*  f093468:	8e040050 */ 	lw	$a0,0x50($s0)
/*  f09346c:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f093470:	306a0200 */ 	andi	$t2,$v1,0x200
.L0f093474:
/*  f093474:	51400004 */ 	beqzl	$t2,.L0f093488
/*  f093478:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f09347c:	0fc37751 */ 	jal	hudmsgsHideByChannel
/*  f093480:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f093484:	240b0001 */ 	addiu	$t3,$zero,0x1
.L0f093488:
/*  f093488:	1000000b */ 	b	.L0f0934b8
/*  f09348c:	a60b0030 */ 	sh	$t3,0x30($s0)
/*  f093490:	8e0c0000 */ 	lw	$t4,0x0($s0)
.L0f093494:
/*  f093494:	306e0008 */ 	andi	$t6,$v1,0x8
/*  f093498:	15800007 */ 	bnez	$t4,.L0f0934b8
/*  f09349c:	00000000 */ 	nop
/*  f0934a0:	51c00004 */ 	beqzl	$t6,.L0f0934b4
/*  f0934a4:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0934a8:	0fc16af7 */ 	jal	propDecrementSoundCount
/*  f0934ac:	8e040050 */ 	lw	$a0,0x50($s0)
/*  f0934b0:	240d0001 */ 	addiu	$t5,$zero,0x1
.L0f0934b4:
/*  f0934b4:	a60d0030 */ 	sh	$t5,0x30($s0)
.L0f0934b8:
/*  f0934b8:	3c0f8007 */ 	lui	$t7,%hi(var8006ae44)
/*  f0934bc:	8defae44 */ 	lw	$t7,%lo(var8006ae44)($t7)
/*  f0934c0:	51e00008 */ 	beqzl	$t7,.L0f0934e4
/*  f0934c4:	960a0030 */ 	lhu	$t2,0x30($s0)
/*  f0934c8:	96180032 */ 	lhu	$t8,0x32($s0)
/*  f0934cc:	33190004 */ 	andi	$t9,$t8,0x4
/*  f0934d0:	53200004 */ 	beqzl	$t9,.L0f0934e4
/*  f0934d4:	960a0030 */ 	lhu	$t2,0x30($s0)
/*  f0934d8:	0fc24ad4 */ 	jal	propsndPrintChannel
/*  f0934dc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0934e0:	960a0030 */ 	lhu	$t2,0x30($s0)
.L0f0934e4:
/*  f0934e4:	314cefff */ 	andi	$t4,$t2,0xefff
/*  f0934e8:	a60c0030 */ 	sh	$t4,0x30($s0)
/*  f0934ec:	318ebfff */ 	andi	$t6,$t4,0xbfff
/*  f0934f0:	a60e0030 */ 	sh	$t6,0x30($s0)
/*  f0934f4:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0934f8:
/*  f0934f8:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f0934fc:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f093500:	03e00008 */ 	jr	$ra
/*  f093504:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel propsndTickChannel
.late_rodata
glabel var7f1ab73c
.word 0x392ec33e
glabel var7f1ab740
.word 0x3c23d70a
.text
/*  f091254:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f091258:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f09125c:	3c188007 */ 	lui	$t8,0x8007
/*  f091260:	8f18d520 */ 	lw	$t8,-0x2ae0($t8)
/*  f091264:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f091268:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f09126c:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f091270:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f091274:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f091278:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f09127c:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f091280:	01f88021 */ 	addu	$s0,$t7,$t8
/*  f091284:	8e050000 */ 	lw	$a1,0x0($s0)
/*  f091288:	50a00006 */ 	beqzl	$a1,.NB0f0912a4
/*  f09128c:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f091290:	0c00d360 */ 	jal	sndGetState
/*  f091294:	00a02025 */ 	or	$a0,$a1,$zero
/*  f091298:	5440000e */ 	bnezl	$v0,.NB0f0912d4
/*  f09129c:	8e020050 */ 	lw	$v0,0x50($s0)
/*  f0912a0:	96030030 */ 	lhu	$v1,0x30($s0)
.NB0f0912a4:
/*  f0912a4:	30790002 */ 	andi	$t9,$v1,0x2
/*  f0912a8:	17200009 */ 	bnez	$t9,.NB0f0912d0
/*  f0912ac:	306a1000 */ 	andi	$t2,$v1,0x1000
/*  f0912b0:	15400007 */ 	bnez	$t2,.NB0f0912d0
/*  f0912b4:	306b0010 */ 	andi	$t3,$v1,0x10
/*  f0912b8:	516001af */ 	beqzl	$t3,.NB0f091978
/*  f0912bc:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f0912c0:	0c003c6c */ 	jal	sndIsPlayingMp3
/*  f0912c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0912c8:	504001ab */ 	beqzl	$v0,.NB0f091978
/*  f0912cc:	96030030 */ 	lhu	$v1,0x30($s0)
.NB0f0912d0:
/*  f0912d0:	8e020050 */ 	lw	$v0,0x50($s0)
.NB0f0912d4:
/*  f0912d4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0912d8:	00004025 */ 	or	$t0,$zero,$zero
/*  f0912dc:	10400004 */ 	beqz	$v0,.NB0f0912f0
/*  f0912e0:	3c09800a */ 	lui	$t1,0x800a
/*  f0912e4:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0912e8:	10000006 */ 	beqz	$zero,.NB0f091304
/*  f0912ec:	24480028 */ 	addiu	$t0,$v0,0x28
.NB0f0912f0:
/*  f0912f0:	860c0064 */ 	lh	$t4,0x64($s0)
/*  f0912f4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0912f8:	51810003 */ 	beql	$t4,$at,.NB0f091308
/*  f0912fc:	8e020054 */ 	lw	$v0,0x54($s0)
/*  f091300:	26080064 */ 	addiu	$t0,$s0,0x64
.NB0f091304:
/*  f091304:	8e020054 */ 	lw	$v0,0x54($s0)
.NB0f091308:
/*  f091308:	2529e6c0 */ 	addiu	$t1,$t1,-6464
/*  f09130c:	50400003 */ 	beqzl	$v0,.NB0f09131c
/*  f091310:	912d04e3 */ 	lbu	$t5,0x4e3($t1)
/*  f091314:	00402025 */ 	or	$a0,$v0,$zero
/*  f091318:	912d04e3 */ 	lbu	$t5,0x4e3($t1)
.NB0f09131c:
/*  f09131c:	51a00008 */ 	beqzl	$t5,.NB0f091340
/*  f091320:	96180032 */ 	lhu	$t8,0x32($s0)
/*  f091324:	960e0032 */ 	lhu	$t6,0x32($s0)
/*  f091328:	31cf0020 */ 	andi	$t7,$t6,0x20
/*  f09132c:	51e00004 */ 	beqzl	$t7,.NB0f091340
/*  f091330:	96180032 */ 	lhu	$t8,0x32($s0)
/*  f091334:	1000003a */ 	beqz	$zero,.NB0f091420
/*  f091338:	a6000004 */ 	sh	$zero,0x4($s0)
/*  f09133c:	96180032 */ 	lhu	$t8,0x32($s0)
.NB0f091340:
/*  f091340:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f091344:	33190010 */ 	andi	$t9,$t8,0x10
/*  f091348:	13200006 */ 	beqz	$t9,.NB0f091364
/*  f09134c:	306a1000 */ 	andi	$t2,$v1,0x1000
/*  f091350:	514001b6 */ 	beqzl	$t2,.NB0f091a2c
/*  f091354:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f091358:	860b0010 */ 	lh	$t3,0x10($s0)
/*  f09135c:	10000030 */ 	beqz	$zero,.NB0f091420
/*  f091360:	a60b0004 */ 	sh	$t3,0x4($s0)
.NB0f091364:
/*  f091364:	5080001e */ 	beqzl	$a0,.NB0f0913e0
/*  f091368:	30790020 */ 	andi	$t9,$v1,0x20
/*  f09136c:	1100001b */ 	beqz	$t0,.NB0f0913dc
/*  f091370:	306c8000 */ 	andi	$t4,$v1,0x8000
/*  f091374:	11800003 */ 	beqz	$t4,.NB0f091384
/*  f091378:	01001025 */ 	or	$v0,$t0,$zero
/*  f09137c:	10000001 */ 	beqz	$zero,.NB0f091384
/*  f091380:	00001025 */ 	or	$v0,$zero,$zero
.NB0f091384:
/*  f091384:	860d002c */ 	lh	$t5,0x2c($s0)
/*  f091388:	3c018007 */ 	lui	$at,0x8007
/*  f09138c:	2618004c */ 	addiu	$t8,$s0,0x4c
/*  f091390:	a42dd55c */ 	sh	$t5,-0x2aa4($at)
/*  f091394:	8e07003c */ 	lw	$a3,0x3c($s0)
/*  f091398:	8e060038 */ 	lw	$a2,0x38($s0)
/*  f09139c:	8e050034 */ 	lw	$a1,0x34($s0)
/*  f0913a0:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0913a4:	860e0026 */ 	lh	$t6,0x26($s0)
/*  f0913a8:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0913ac:	860f0010 */ 	lh	$t7,0x10($s0)
/*  f0913b0:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f0913b4:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0913b8:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0913bc:	0fc24a76 */ 	jal	propsnd0f0946b0
/*  f0913c0:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f0913c4:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f0913c8:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f0913cc:	3c09800a */ 	lui	$t1,0x800a
/*  f0913d0:	2529e6c0 */ 	addiu	$t1,$t1,-6464
/*  f0913d4:	a6020004 */ 	sh	$v0,0x4($s0)
/*  f0913d8:	96030030 */ 	lhu	$v1,0x30($s0)
.NB0f0913dc:
/*  f0913dc:	30790020 */ 	andi	$t9,$v1,0x20
.NB0f0913e0:
/*  f0913e0:	1720000f */ 	bnez	$t9,.NB0f091420
/*  f0913e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0913e8:	c604004c */ 	lwc1	$f4,0x4c($s0)
/*  f0913ec:	8e050034 */ 	lw	$a1,0x34($s0)
/*  f0913f0:	8e060038 */ 	lw	$a2,0x38($s0)
/*  f0913f4:	8e07003c */ 	lw	$a3,0x3c($s0)
/*  f0913f8:	306a0800 */ 	andi	$t2,$v1,0x800
/*  f0913fc:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f091400:	afa8004c */ 	sw	$t0,0x4c($sp)
/*  f091404:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f091408:	0fc24c2f */ 	jal	propsnd0f094d78
/*  f09140c:	e7a40010 */ 	swc1	$f4,0x10($sp)
/*  f091410:	8fa8004c */ 	lw	$t0,0x4c($sp)
/*  f091414:	3c09800a */ 	lui	$t1,0x800a
/*  f091418:	2529e6c0 */ 	addiu	$t1,$t1,-6464
/*  f09141c:	a602000a */ 	sh	$v0,0xa($s0)
.NB0f091420:
/*  f091420:	5100000a */ 	beqzl	$t0,.NB0f09144c
/*  f091424:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f091428:	850b0000 */ 	lh	$t3,0x0($t0)
/*  f09142c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f091430:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f091434:	51610005 */ 	beql	$t3,$at,.NB0f09144c
/*  f091438:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f09143c:	a600000c */ 	sh	$zero,0xc($s0)
/*  f091440:	10000004 */ 	beqz	$zero,.NB0f091454
/*  f091444:	a20c001a */ 	sb	$t4,0x1a($s0)
/*  f091448:	240d0001 */ 	addiu	$t5,$zero,0x1
.NB0f09144c:
/*  f09144c:	a600000c */ 	sh	$zero,0xc($s0)
/*  f091450:	a20d001a */ 	sb	$t5,0x1a($s0)
.NB0f091454:
/*  f091454:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f091458:	51c00026 */ 	beqzl	$t6,.NB0f0914f4
/*  f09145c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f091460:	c6000044 */ 	lwc1	$f0,0x44($s0)
/*  f091464:	44803000 */ 	mtc1	$zero,$f6
/*  f091468:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09146c:	4600303c */ 	c.lt.s	$f6,$f0
/*  f091470:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091474:	4502001f */ 	bc1fl	.NB0f0914f4
/*  f091478:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09147c:	c6020048 */ 	lwc1	$f2,0x48($s0)
/*  f091480:	44804000 */ 	mtc1	$zero,$f8
/*  f091484:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091488:	4608103c */ 	c.lt.s	$f2,$f8
/*  f09148c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091490:	45020004 */ 	bc1fl	.NB0f0914a4
/*  f091494:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f091498:	10000018 */ 	beqz	$zero,.NB0f0914fc
/*  f09149c:	46000486 */ 	mov.s	$f18,$f0
/*  f0914a0:	8e0f0020 */ 	lw	$t7,0x20($s0)
.NB0f0914a4:
/*  f0914a4:	44802000 */ 	mtc1	$zero,$f4
/*  f0914a8:	448f5000 */ 	mtc1	$t7,$f10
/*  f0914ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0914b0:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f0914b4:	460c203c */ 	c.lt.s	$f4,$f12
/*  f0914b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0914bc:	4500000a */ 	bc1f	.NB0f0914e8
/*  f0914c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0914c4:	8d380034 */ 	lw	$t8,0x34($t1)
/*  f0914c8:	46020181 */ 	sub.s	$f6,$f0,$f2
/*  f0914cc:	44984000 */ 	mtc1	$t8,$f8
/*  f0914d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0914d4:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0914d8:	460a3102 */ 	mul.s	$f4,$f6,$f10
/*  f0914dc:	460c2203 */ 	div.s	$f8,$f4,$f12
/*  f0914e0:	10000006 */ 	beqz	$zero,.NB0f0914fc
/*  f0914e4:	46081480 */ 	add.s	$f18,$f2,$f8
.NB0f0914e8:
/*  f0914e8:	10000004 */ 	beqz	$zero,.NB0f0914fc
/*  f0914ec:	46000486 */ 	mov.s	$f18,$f0
/*  f0914f0:	3c01bf80 */ 	lui	$at,0xbf80
.NB0f0914f4:
/*  f0914f4:	44819000 */ 	mtc1	$at,$f18
/*  f0914f8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0914fc:
/*  f0914fc:	8619000a */ 	lh	$t9,0xa($s0)
/*  f091500:	2401ffff */ 	addiu	$at,$zero,-1
/*  f091504:	afb90044 */ 	sw	$t9,0x44($sp)
/*  f091508:	86040006 */ 	lh	$a0,0x6($s0)
/*  f09150c:	8608000c */ 	lh	$t0,0xc($s0)
/*  f091510:	14810003 */ 	bne	$a0,$at,.NB0f091520
/*  f091514:	00802825 */ 	or	$a1,$a0,$zero
/*  f091518:	10000054 */ 	beqz	$zero,.NB0f09166c
/*  f09151c:	86050004 */ 	lh	$a1,0x4($s0)
.NB0f091520:
/*  f091520:	8e02001c */ 	lw	$v0,0x1c($s0)
/*  f091524:	0442001a */ 	bltzl	$v0,.NB0f091590
/*  f091528:	86030018 */ 	lh	$v1,0x18($s0)
/*  f09152c:	8d230038 */ 	lw	$v1,0x38($t1)
/*  f091530:	0062082a */ 	slt	$at,$v1,$v0
/*  f091534:	10200013 */ 	beqz	$at,.NB0f091584
/*  f091538:	00437023 */ 	subu	$t6,$v0,$v1
/*  f09153c:	860a0004 */ 	lh	$t2,0x4($s0)
/*  f091540:	01445823 */ 	subu	$t3,$t2,$a0
/*  f091544:	01630019 */ 	multu	$t3,$v1
/*  f091548:	00006012 */ 	mflo	$t4
/*  f09154c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091550:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091554:	0182001a */ 	div	$zero,$t4,$v0
/*  f091558:	00006812 */ 	mflo	$t5
/*  f09155c:	008d2821 */ 	addu	$a1,$a0,$t5
/*  f091560:	14400002 */ 	bnez	$v0,.NB0f09156c
/*  f091564:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091568:	0007000d */ 	break	0x7
.NB0f09156c:
/*  f09156c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f091570:	14410004 */ 	bne	$v0,$at,.NB0f091584
/*  f091574:	3c018000 */ 	lui	$at,0x8000
/*  f091578:	15810002 */ 	bne	$t4,$at,.NB0f091584
/*  f09157c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091580:	0006000d */ 	break	0x6
.NB0f091584:
/*  f091584:	10000039 */ 	beqz	$zero,.NB0f09166c
/*  f091588:	ae0e001c */ 	sw	$t6,0x1c($s0)
/*  f09158c:	86030018 */ 	lh	$v1,0x18($s0)
.NB0f091590:
/*  f091590:	50600036 */ 	beqzl	$v1,.NB0f09166c
/*  f091594:	86050004 */ 	lh	$a1,0x4($s0)
/*  f091598:	86020004 */ 	lh	$v0,0x4($s0)
/*  f09159c:	50440033 */ 	beql	$v0,$a0,.NB0f09166c
/*  f0915a0:	86050004 */ 	lh	$a1,0x4($s0)
/*  f0915a4:	8d380038 */ 	lw	$t8,0x38($t1)
/*  f0915a8:	00447823 */ 	subu	$t7,$v0,$a0
/*  f0915ac:	448f3000 */ 	mtc1	$t7,$f6
/*  f0915b0:	44985000 */ 	mtc1	$t8,$f10
/*  f0915b4:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0915b8:	c4285a8c */ 	lwc1	$f8,0x5a8c($at)
/*  f0915bc:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0915c0:	44835000 */ 	mtc1	$v1,$f10
/*  f0915c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0915c8:	44818000 */ 	mtc1	$at,$f16
/*  f0915cc:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f0915d0:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0915d4:	44804000 */ 	mtc1	$zero,$f8
/*  f0915d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0915dc:	460c403c */ 	c.lt.s	$f8,$f12
/*  f0915e0:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0915e4:	46043382 */ 	mul.s	$f14,$f6,$f4
/*  f0915e8:	45020004 */ 	bc1fl	.NB0f0915fc
/*  f0915ec:	46006007 */ 	neg.s	$f0,$f12
/*  f0915f0:	10000002 */ 	beqz	$zero,.NB0f0915fc
/*  f0915f4:	46006006 */ 	mov.s	$f0,$f12
/*  f0915f8:	46006007 */ 	neg.s	$f0,$f12
.NB0f0915fc:
/*  f0915fc:	4600803c */ 	c.lt.s	$f16,$f0
/*  f091600:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091604:	4502001a */ 	bc1fl	.NB0f091670
/*  f091608:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f09160c:	460e803c */ 	c.lt.s	$f16,$f14
/*  f091610:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091614:	45000002 */ 	bc1f	.NB0f091620
/*  f091618:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09161c:	46008386 */ 	mov.s	$f14,$f16
.NB0f091620:
/*  f091620:	460c7082 */ 	mul.s	$f2,$f14,$f12
/*  f091624:	44805000 */ 	mtc1	$zero,$f10
/*  f091628:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09162c:	4602503c */ 	c.lt.s	$f10,$f2
/*  f091630:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091634:	45020004 */ 	bc1fl	.NB0f091648
/*  f091638:	46001007 */ 	neg.s	$f0,$f2
/*  f09163c:	10000002 */ 	beqz	$zero,.NB0f091648
/*  f091640:	46001006 */ 	mov.s	$f0,$f2
/*  f091644:	46001007 */ 	neg.s	$f0,$f2
.NB0f091648:
/*  f091648:	4600803c */ 	c.lt.s	$f16,$f0
/*  f09164c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091650:	45020007 */ 	bc1fl	.NB0f091670
/*  f091654:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f091658:	4600118d */ 	trunc.w.s	$f6,$f2
/*  f09165c:	440a3000 */ 	mfc1	$t2,$f6
/*  f091660:	10000002 */ 	beqz	$zero,.NB0f09166c
/*  f091664:	008a2821 */ 	addu	$a1,$a0,$t2
/*  f091668:	86050004 */ 	lh	$a1,0x4($s0)
.NB0f09166c:
/*  f09166c:	afa50048 */ 	sw	$a1,0x48($sp)
.NB0f091670:
/*  f091670:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f091674:	0fc59ed0 */ 	jal	lvIsPaused
/*  f091678:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f09167c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f091680:	1440002f */ 	bnez	$v0,.NB0f091740
/*  f091684:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f091688:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f09168c:	0fc60e8c */ 	jal	mpIsPaused
/*  f091690:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f091694:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f091698:	10400005 */ 	beqz	$v0,.NB0f0916b0
/*  f09169c:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f0916a0:	960b0032 */ 	lhu	$t3,0x32($s0)
/*  f0916a4:	316c0002 */ 	andi	$t4,$t3,0x2
/*  f0916a8:	55800026 */ 	bnezl	$t4,.NB0f091744
/*  f0916ac:	240cffff */ 	addiu	$t4,$zero,-1
.NB0f0916b0:
/*  f0916b0:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f0916b4:	0fc60e8c */ 	jal	mpIsPaused
/*  f0916b8:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f0916bc:	3c09800a */ 	lui	$t1,0x800a
/*  f0916c0:	2529e6c0 */ 	addiu	$t1,$t1,-6464
/*  f0916c4:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f0916c8:	10400020 */ 	beqz	$v0,.NB0f09174c
/*  f0916cc:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f0916d0:	8d2d006c */ 	lw	$t5,0x6c($t1)
/*  f0916d4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0916d8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0916dc:	11a00003 */ 	beqz	$t5,.NB0f0916ec
/*  f0916e0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0916e4:	10000001 */ 	beqz	$zero,.NB0f0916ec
/*  f0916e8:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f0916ec:
/*  f0916ec:	8d2e0068 */ 	lw	$t6,0x68($t1)
/*  f0916f0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0916f4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0916f8:	11c00003 */ 	beqz	$t6,.NB0f091708
/*  f0916fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091700:	10000001 */ 	beqz	$zero,.NB0f091708
/*  f091704:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f091708:
/*  f091708:	8d2f0064 */ 	lw	$t7,0x64($t1)
/*  f09170c:	11e00003 */ 	beqz	$t7,.NB0f09171c
/*  f091710:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091714:	10000001 */ 	beqz	$zero,.NB0f09171c
/*  f091718:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f09171c:
/*  f09171c:	8d380070 */ 	lw	$t8,0x70($t1)
/*  f091720:	13000003 */ 	beqz	$t8,.NB0f091730
/*  f091724:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091728:	10000001 */ 	beqz	$zero,.NB0f091730
/*  f09172c:	24070001 */ 	addiu	$a3,$zero,0x1
.NB0f091730:
/*  f091730:	00e3c821 */ 	addu	$t9,$a3,$v1
/*  f091734:	03225021 */ 	addu	$t2,$t9,$v0
/*  f091738:	01445821 */ 	addu	$t3,$t2,$a0
/*  f09173c:	15610003 */ 	bne	$t3,$at,.NB0f09174c
.NB0f091740:
/*  f091740:	240cffff */ 	addiu	$t4,$zero,-1
.NB0f091744:
/*  f091744:	a60c0006 */ 	sh	$t4,0x6($s0)
/*  f091748:	afa00048 */ 	sw	$zero,0x48($sp)
.NB0f09174c:
/*  f09174c:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f091750:	860e0006 */ 	lh	$t6,0x6($s0)
/*  f091754:	44802000 */ 	mtc1	$zero,$f4
/*  f091758:	51ae0004 */ 	beql	$t5,$t6,.NB0f09176c
/*  f09175c:	240fffff */ 	addiu	$t7,$zero,-1
/*  f091760:	10000003 */ 	beqz	$zero,.NB0f091770
/*  f091764:	a60d0006 */ 	sh	$t5,0x6($s0)
/*  f091768:	240fffff */ 	addiu	$t7,$zero,-1
.NB0f09176c:
/*  f09176c:	afaf0048 */ 	sw	$t7,0x48($sp)
.NB0f091770:
/*  f091770:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f091774:	86190008 */ 	lh	$t9,0x8($s0)
/*  f091778:	53190008 */ 	beql	$t8,$t9,.NB0f09179c
/*  f09177c:	240effff */ 	addiu	$t6,$zero,-1
/*  f091780:	960a0030 */ 	lhu	$t2,0x30($s0)
/*  f091784:	354b4000 */ 	ori	$t3,$t2,0x4000
/*  f091788:	a60b0030 */ 	sh	$t3,0x30($s0)
/*  f09178c:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f091790:	10000003 */ 	beqz	$zero,.NB0f0917a0
/*  f091794:	a60c0008 */ 	sh	$t4,0x8($s0)
/*  f091798:	240effff */ 	addiu	$t6,$zero,-1
.NB0f09179c:
/*  f09179c:	afae0044 */ 	sw	$t6,0x44($sp)
.NB0f0917a0:
/*  f0917a0:	860d000e */ 	lh	$t5,0xe($s0)
/*  f0917a4:	510d0004 */ 	beql	$t0,$t5,.NB0f0917b8
/*  f0917a8:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f0917ac:	10000002 */ 	beqz	$zero,.NB0f0917b8
/*  f0917b0:	a608000e */ 	sh	$t0,0xe($s0)
/*  f0917b4:	2408ffff */ 	addiu	$t0,$zero,-1
.NB0f0917b8:
/*  f0917b8:	4612203c */ 	c.lt.s	$f4,$f18
/*  f0917bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0917c0:	45020013 */ 	bc1fl	.NB0f091810
/*  f0917c4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0917c8:	c6020048 */ 	lwc1	$f2,0x48($s0)
/*  f0917cc:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0917d0:	4612103c */ 	c.lt.s	$f2,$f18
/*  f0917d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0917d8:	45020004 */ 	bc1fl	.NB0f0917ec
/*  f0917dc:	46029001 */ 	sub.s	$f0,$f18,$f2
/*  f0917e0:	10000003 */ 	beqz	$zero,.NB0f0917f0
/*  f0917e4:	46029001 */ 	sub.s	$f0,$f18,$f2
/*  f0917e8:	46029001 */ 	sub.s	$f0,$f18,$f2
.NB0f0917ec:
/*  f0917ec:	46000007 */ 	neg.s	$f0,$f0
.NB0f0917f0:
/*  f0917f0:	c4285a90 */ 	lwc1	$f8,0x5a90($at)
/*  f0917f4:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0917f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0917fc:	45020004 */ 	bc1fl	.NB0f091810
/*  f091800:	3c01bf80 */ 	lui	$at,0xbf80
/*  f091804:	10000004 */ 	beqz	$zero,.NB0f091818
/*  f091808:	e6120048 */ 	swc1	$f18,0x48($s0)
/*  f09180c:	3c01bf80 */ 	lui	$at,0xbf80
.NB0f091810:
/*  f091810:	44819000 */ 	mtc1	$at,$f18
/*  f091814:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f091818:
/*  f091818:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f09181c:	306f0002 */ 	andi	$t7,$v1,0x2
/*  f091820:	51e00024 */ 	beqzl	$t7,.NB0f0918b4
/*  f091824:	30782000 */ 	andi	$t8,$v1,0x2000
/*  f091828:	86180006 */ 	lh	$t8,0x6($s0)
/*  f09182c:	30792000 */ 	andi	$t9,$v1,0x2000
/*  f091830:	306e2000 */ 	andi	$t6,$v1,0x2000
/*  f091834:	1b000008 */ 	blez	$t8,.NB0f091858
/*  f091838:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09183c:	1320001c */ 	beqz	$t9,.NB0f0918b0
/*  f091840:	306bdfff */ 	andi	$t3,$v1,0xdfff
/*  f091844:	a60b0030 */ 	sh	$t3,0x30($s0)
/*  f091848:	356c1000 */ 	ori	$t4,$t3,0x1000
/*  f09184c:	a60c0030 */ 	sh	$t4,0x30($s0)
/*  f091850:	10000017 */ 	beqz	$zero,.NB0f0918b0
/*  f091854:	3183ffff */ 	andi	$v1,$t4,0xffff
.NB0f091858:
/*  f091858:	55c00016 */ 	bnezl	$t6,.NB0f0918b4
/*  f09185c:	30782000 */ 	andi	$t8,$v1,0x2000
/*  f091860:	8e050000 */ 	lw	$a1,0x0($s0)
/*  f091864:	10a0000e */ 	beqz	$a1,.NB0f0918a0
/*  f091868:	00a02025 */ 	or	$a0,$a1,$zero
/*  f09186c:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f091870:	0c00d360 */ 	jal	sndGetState
/*  f091874:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f091878:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f09187c:	10400008 */ 	beqz	$v0,.NB0f0918a0
/*  f091880:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f091884:	8e040000 */ 	lw	$a0,0x0($s0)
/*  f091888:	e7b2003c */ 	swc1	$f18,0x3c($sp)
/*  f09188c:	0c00d428 */ 	jal	audioStop
/*  f091890:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f091894:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f091898:	c7b2003c */ 	lwc1	$f18,0x3c($sp)
/*  f09189c:	ae000000 */ 	sw	$zero,0x0($s0)
.NB0f0918a0:
/*  f0918a0:	960d0030 */ 	lhu	$t5,0x30($s0)
/*  f0918a4:	35af2000 */ 	ori	$t7,$t5,0x2000
/*  f0918a8:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f0918ac:	31e3ffff */ 	andi	$v1,$t7,0xffff
.NB0f0918b0:
/*  f0918b0:	30782000 */ 	andi	$t8,$v1,0x2000
.NB0f0918b4:
/*  f0918b4:	1700004f */ 	bnez	$t8,.NB0f0919f4
/*  f0918b8:	30791000 */ 	andi	$t9,$v1,0x1000
/*  f0918bc:	1320001f */ 	beqz	$t9,.NB0f09193c
/*  f0918c0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0918c4:	30650010 */ 	andi	$a1,$v1,0x10
/*  f0918c8:	10a0000d */ 	beqz	$a1,.NB0f091900
/*  f0918cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0918d0:	960a0032 */ 	lhu	$t2,0x32($s0)
/*  f0918d4:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f0918d8:	8fa60044 */ 	lw	$a2,0x44($sp)
/*  f0918dc:	314b0001 */ 	andi	$t3,$t2,0x1
/*  f0918e0:	11600003 */ 	beqz	$t3,.NB0f0918f0
/*  f0918e4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0918e8:	10000001 */ 	beqz	$zero,.NB0f0918f0
/*  f0918ec:	24070001 */ 	addiu	$a3,$zero,0x1
.NB0f0918f0:
/*  f0918f0:	0c0043a9 */ 	jal	sndStartMp3
/*  f0918f4:	86040026 */ 	lh	$a0,0x26($s0)
/*  f0918f8:	1000000d */ 	beqz	$zero,.NB0f091930
/*  f0918fc:	960f0030 */ 	lhu	$t7,0x30($s0)
.NB0f091900:
/*  f091900:	860c0026 */ 	lh	$t4,0x26($s0)
/*  f091904:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f091908:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f09190c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f091910:	920e001a */ 	lbu	$t6,0x1a($s0)
/*  f091914:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f091918:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f09191c:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f091920:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f091924:	0c0042bf */ 	jal	snd00010718
/*  f091928:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f09192c:	960f0030 */ 	lhu	$t7,0x30($s0)
.NB0f091930:
/*  f091930:	31f8efff */ 	andi	$t8,$t7,0xefff
/*  f091934:	1000002f */ 	beqz	$zero,.NB0f0919f4
/*  f091938:	a6180030 */ 	sh	$t8,0x30($s0)
.NB0f09193c:
/*  f09193c:	86190026 */ 	lh	$t9,0x26($s0)
/*  f091940:	e7b20014 */ 	swc1	$f18,0x14($sp)
/*  f091944:	306b4000 */ 	andi	$t3,$v1,0x4000
/*  f091948:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f09194c:	920a001a */ 	lbu	$t2,0x1a($s0)
/*  f091950:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f091954:	afa8001c */ 	sw	$t0,0x1c($sp)
/*  f091958:	30650010 */ 	andi	$a1,$v1,0x10
/*  f09195c:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f091960:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f091964:	0c004224 */ 	jal	sndAdjust
/*  f091968:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f09196c:	10000021 */ 	beqz	$zero,.NB0f0919f4
/*  f091970:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091974:	96030030 */ 	lhu	$v1,0x30($s0)
.NB0f091978:
/*  f091978:	306c0010 */ 	andi	$t4,$v1,0x10
/*  f09197c:	51800014 */ 	beqzl	$t4,.NB0f0919d0
/*  f091980:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f091984:	0c003c6c */ 	jal	sndIsPlayingMp3
/*  f091988:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09198c:	54400018 */ 	bnezl	$v0,.NB0f0919f0
/*  f091990:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f091994:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f091998:	306e0008 */ 	andi	$t6,$v1,0x8
/*  f09199c:	51c00005 */ 	beqzl	$t6,.NB0f0919b4
/*  f0919a0:	306d0200 */ 	andi	$t5,$v1,0x200
/*  f0919a4:	0fc16805 */ 	jal	propDecrementSoundCount
/*  f0919a8:	8e040050 */ 	lw	$a0,0x50($s0)
/*  f0919ac:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f0919b0:	306d0200 */ 	andi	$t5,$v1,0x200
.NB0f0919b4:
/*  f0919b4:	51a0000e */ 	beqzl	$t5,.NB0f0919f0
/*  f0919b8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0919bc:	0fc36cd5 */ 	jal	hudmsgsHideByChannel
/*  f0919c0:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f0919c4:	1000000a */ 	beqz	$zero,.NB0f0919f0
/*  f0919c8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0919cc:	8e0f0000 */ 	lw	$t7,0x0($s0)
.NB0f0919d0:
/*  f0919d0:	30780008 */ 	andi	$t8,$v1,0x8
/*  f0919d4:	55e00006 */ 	bnezl	$t7,.NB0f0919f0
/*  f0919d8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0919dc:	53000004 */ 	beqzl	$t8,.NB0f0919f0
/*  f0919e0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0919e4:	0fc16805 */ 	jal	propDecrementSoundCount
/*  f0919e8:	8e040050 */ 	lw	$a0,0x50($s0)
/*  f0919ec:	24190001 */ 	addiu	$t9,$zero,0x1
.NB0f0919f0:
/*  f0919f0:	a6190030 */ 	sh	$t9,0x30($s0)
.NB0f0919f4:
/*  f0919f4:	3c0a8007 */ 	lui	$t2,0x8007
/*  f0919f8:	8d4ad550 */ 	lw	$t2,-0x2ab0($t2)
/*  f0919fc:	51400008 */ 	beqzl	$t2,.NB0f091a20
/*  f091a00:	960e0030 */ 	lhu	$t6,0x30($s0)
/*  f091a04:	960b0032 */ 	lhu	$t3,0x32($s0)
/*  f091a08:	316c0004 */ 	andi	$t4,$t3,0x4
/*  f091a0c:	51800004 */ 	beqzl	$t4,.NB0f091a20
/*  f091a10:	960e0030 */ 	lhu	$t6,0x30($s0)
/*  f091a14:	0fc24466 */ 	jal	propsndPrintChannel
/*  f091a18:	02002025 */ 	or	$a0,$s0,$zero
/*  f091a1c:	960e0030 */ 	lhu	$t6,0x30($s0)
.NB0f091a20:
/*  f091a20:	31cdbfff */ 	andi	$t5,$t6,0xbfff
/*  f091a24:	a60d0030 */ 	sh	$t5,0x30($s0)
/*  f091a28:	8fbf0034 */ 	lw	$ra,0x34($sp)
.NB0f091a2c:
/*  f091a2c:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f091a30:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f091a34:	03e00008 */ 	jr	$ra
/*  f091a38:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif
#else
// Mismatch: Some reordered instructions
void propsndTickChannel(s32 channelnum)
{
	struct audiochannel *channel = &g_AudioChannels[channelnum];

#if VERSION >= VERSION_NTSC_1_0
	if ((channel->flags2 & AUDIOCHANNELFLAG2_0080) == 0
			&& channel->unk28 != 11
			&& ((channel->audiohandle != NULL && sndGetState(channel->audiohandle) != AL_STOPPED)
				|| (channel->flags & AUDIOCHANNELFLAG_0002)
				|| (channel->flags & AUDIOCHANNELFLAG_1000)
				|| ((channel->flags & AUDIOCHANNELFLAG_ISMP3) && sndIsPlayingMp3())))
#else
	if ((channel->audiohandle != NULL && sndGetState(channel->audiohandle) != AL_STOPPED)
			|| (channel->flags & AUDIOCHANNELFLAG_0002)
			|| (channel->flags & AUDIOCHANNELFLAG_1000)
			|| ((channel->flags & AUDIOCHANNELFLAG_ISMP3) && sndIsPlayingMp3()))
#endif
	{
		struct coord *pos = NULL; // 50
		s16 *rooms = NULL; // 4c
		s32 sp48;
		s32 sp44;
		s32 sp40;
		f32 sp3c;

		if (channel->prop) {
			pos = &channel->prop->pos;
			rooms = channel->prop->rooms;
		} else if (channel->rooms[0] != -1) {
			rooms = channel->rooms;
		}

		if (channel->posptr != NULL) {
			pos = channel->posptr;
		}

		if (1);

		if (g_Vars.langfilteron && (channel->flags2 & AUDIOCHANNELFLAG2_OFFENSIVE)) {
			channel->unk04 = 0;
		} else if (channel->flags2 & AUDIOCHANNELFLAG2_0010) {
			if ((channel->flags & AUDIOCHANNELFLAG_1000) == 0) {
				return;
			}

			channel->unk04 = channel->unk10;
		} else {
			if (pos && rooms) {
				s16 *tmprooms;

				if (channel->flags & AUDIOCHANNELFLAG_8000) {
					tmprooms = NULL;
				} else {
					tmprooms = rooms;
				}

				var8006ae50 = channel->unk2c;

				channel->unk04 = propsnd0f0946b0(pos, channel->unk34, channel->unk38, channel->unk3c,
						tmprooms, channel->soundnum26, channel->unk10, &channel->unk4c);
			}

			if ((channel->flags & AUDIOCHANNELFLAG_0020) == 0) {
				channel->unk0a = propsnd0f094d78(pos, channel->unk34, channel->unk38, channel->unk3c,
						channel->unk4c, channel->flags & AUDIOCHANNELFLAG_0800, channel);
			}
		}

		if (rooms != NULL && rooms[0] != -1) {
			channel->unk0c = 0;
			channel->unk1a = 1;
		} else {
			channel->unk0c = 0;
			channel->unk1a = 1;
		}

		if (channel->audiohandle != NULL && channel->unk44 > 0.0f) {
			if (channel->unk48 < 0.0f) {
				sp3c = channel->unk44;
			} else if (channel->unk20 > 0.0f) {
				sp3c = channel->unk48 + (channel->unk44 - channel->unk48) * g_Vars.lvupdate240 / channel->unk20;
			} else {
				sp3c = channel->unk44;
			}
		} else {
			sp3c = -1.0f;
		}

		sp44 = channel->unk0a;
		sp48 = channel->unk06;
		sp40 = channel->unk0c;

		if (channel->unk06 == -1) {
			sp48 = channel->unk04;
		} else if (channel->unk1c >= 0) {
			if (channel->unk1c > g_Vars.lvupdate60) {
				sp48 = channel->unk06 + (channel->unk04 - channel->unk06) * g_Vars.lvupdate60 / channel->unk1c;
			}

			channel->unk1c -= g_Vars.lvupdate60;
		} else if (channel->unk18 && channel->unk06 != channel->unk04) {
			f32 f12 = channel->unk04 - channel->unk06;
#if VERSION >= VERSION_PAL_BETA
			f32 f14 = g_Vars.lvupdate60freal * (1.0f / 6000.0f) * channel->unk18;
#else
			f32 f14 = g_Vars.lvupdate60 * (1.0f / 6000.0f) * channel->unk18;
#endif

			if (ABS(f12) > 1.0f) {
				if (f14 > 1.0f) {
					f14 = 1.0f;
				}

				if (ABS(f14 * f12) > 1.0f) {
					sp48 = channel->unk06 + (s32) (f14 * f12);
				}
			}
		} else {
			sp48 = channel->unk04;
		}

		if (lvIsPaused()
				|| (mpIsPaused() && (channel->flags2 & AUDIOCHANNELFLAG2_0002))
				|| (mpIsPaused() && PLAYERCOUNT() == 1)) {
			channel->unk06 = -1;
			sp48 = 0;
		}

		if (sp48 != channel->unk06) {
			channel->unk06 = sp48;
		} else {
			sp48 = -1;
		}

#if VERSION >= VERSION_NTSC_1_0
		if (channel->unk0a != channel->unk08) {
			if (channel->flags & AUDIOCHANNELFLAG_1000) {
				channel->unk08 = channel->unk0a;
				sp44 = channel->unk08;
			} else {
				s32 diff = channel->unk0a - channel->unk08;
				s32 lvupdate = g_Vars.lvupdate240 * 512 / 240;
				s32 dir = diff < 0 ? -1 : 1;
				s32 absdiff = ABS(diff);
				s32 amount = absdiff < lvupdate ? absdiff : lvupdate;

				channel->unk08 += amount * dir;
				sp44 = channel->unk08;
			}

			channel->flags |= AUDIOCHANNELFLAG_4000;
		} else {
			sp44 = -1;
		}
#else
		if (sp44 != channel->unk08) {
			channel->flags |= AUDIOCHANNELFLAG_4000;
			channel->unk08 = sp44;
		} else {
			sp44 = -1;
		}
#endif

		if (sp40 != channel->unk0e) {
			channel->unk0e = sp40;
		} else {
			sp40 = -1;
		}

		if (sp3c > 0.0f && ABS(sp3c - channel->unk48) > 0.01f) {
			channel->unk48 = sp3c;
		} else {
			sp3c = -1.0f;
		}

		if (channel->flags & AUDIOCHANNELFLAG_0002) {
			if (channel->unk06 > 0) {
				if (channel->flags & AUDIOCHANNELFLAG_2000) {
					channel->flags &= ~AUDIOCHANNELFLAG_2000;
					channel->flags |= AUDIOCHANNELFLAG_1000;
				}
			} else {
				if ((channel->flags & AUDIOCHANNELFLAG_2000) == 0) {
					if (channel->audiohandle != NULL && sndGetState(channel->audiohandle) != AL_STOPPED) {
						audioStop(channel->audiohandle);
#if VERSION < VERSION_NTSC_1_0
						channel->audiohandle = NULL;
#endif
					}

					channel->flags |= AUDIOCHANNELFLAG_2000;
				}

#if VERSION >= VERSION_NTSC_1_0
				channel->flags &= ~AUDIOCHANNELFLAG_1000;
#endif
			}
		}

		if ((channel->flags & AUDIOCHANNELFLAG_2000) == 0) {
			if (channel->flags & AUDIOCHANNELFLAG_1000) {
				if (channel->flags & AUDIOCHANNELFLAG_ISMP3) {
					sndStartMp3(channel->soundnum26, sp48, sp44, (channel->flags2 & AUDIOCHANNELFLAG2_0001) ? 1 : 0);
				} else {
#if VERSION >= VERSION_NTSC_1_0
					if (channel->flags & AUDIOCHANNELFLAG_0400) {
						if (sp48) {
							snd00010718(&channel->audiohandle, channel->flags & AUDIOCHANNELFLAG_ISMP3, sp48, sp44,
									channel->soundnum26, sp3c, channel->unk1a, sp40, 1);
						}
					} else {
						if (sp48) {
							snd00010718(&channel->audiohandle, channel->flags & AUDIOCHANNELFLAG_ISMP3, sp48, sp44,
									channel->soundnum26, sp3c, channel->unk1a, sp40, 1);
						}
					}
#else
					snd00010718(&channel->audiohandle, channel->flags & AUDIOCHANNELFLAG_ISMP3, sp48, sp44,
							channel->soundnum26, sp3c, channel->unk1a, sp40, 1);
#endif
				}

				channel->flags &= ~AUDIOCHANNELFLAG_1000;
			} else {
				sndAdjust(&channel->audiohandle, channel->flags & AUDIOCHANNELFLAG_ISMP3, sp48, sp44,
						channel->soundnum26, sp3c, channel->unk1a, sp40, channel->flags & AUDIOCHANNELFLAG_4000);
			}
		}
	} else {
#if VERSION >= VERSION_NTSC_1_0
		if (channel->unk28 != 11) {
			if (channel->flags & AUDIOCHANNELFLAG_ISMP3) {
				if (!sndIsPlayingMp3()) {
					if (channel->flags & AUDIOCHANNELFLAG_FORPROP) {
						propDecrementSoundCount(channel->prop);
					}

					if (channel->flags & AUDIOCHANNELFLAG_FORHUDMSG) {
						hudmsgsHideByChannel(channelnum);
					}
				}

				channel->flags = AUDIOCHANNELFLAG_IDLE;
			} else if (channel->audiohandle == NULL) {
				if (channel->flags & AUDIOCHANNELFLAG_FORPROP) {
					propDecrementSoundCount(channel->prop);
				}

				channel->flags = AUDIOCHANNELFLAG_IDLE;
			}
		}
#else
		if (channel->flags & AUDIOCHANNELFLAG_ISMP3) {
			if (!sndIsPlayingMp3()) {
				if (channel->flags & AUDIOCHANNELFLAG_FORPROP) {
					propDecrementSoundCount(channel->prop);
				}

				if (channel->flags & AUDIOCHANNELFLAG_FORHUDMSG) {
					hudmsgsHideByChannel(channelnum);
				}
			}
		} else if (channel->audiohandle == NULL) {
			if (channel->flags & AUDIOCHANNELFLAG_FORPROP) {
				propDecrementSoundCount(channel->prop);
			}
		}

		channel->flags = AUDIOCHANNELFLAG_IDLE;
#endif
	}

	if (var8006ae44 && (channel->flags2 & AUDIOCHANNELFLAG2_0004)) {
		propsndPrintChannel(channel);
	}

#if VERSION >= VERSION_NTSC_1_0
	channel->flags &= ~AUDIOCHANNELFLAG_1000;
#endif
	channel->flags &= ~AUDIOCHANNELFLAG_4000;
}
#endif

void propsndTick(void)
{
	static s32 g_PropsndMaxActiveChannels = 0;
	s32 count = 0;
	s32 i;

	for (i = 0; i < (IS4MB() ? 30 : 40); i++) {
		struct audiochannel *channel = &g_AudioChannels[i];

		if ((channel->flags & AUDIOCHANNELFLAG_IDLE) == 0) {
			propsndTickChannel(i);
			count++;

#if VERSION >= VERSION_NTSC_1_0
			if (g_PropsndPrintChannels) {
				propsndPrintChannel(&g_AudioChannels[i]);
			}
#endif
		}
	}

#if VERSION >= VERSION_NTSC_1_0
	if (g_PropsndPrintChannels) {
		g_PropsndPrintChannels = false;
	}

	if (IS4MB());
#endif

	if (g_PropsndMaxActiveChannels < count) {
		g_PropsndMaxActiveChannels = count;
	}
}

void func0f093630(struct prop *prop, f32 arg1, s32 arg2)
{
	OSPri prevpri;
	s32 i;

	for (i = 0; i < (IS4MB() ? 30 : 40); i++) {
		if ((g_AudioChannels[i].flags & AUDIOCHANNELFLAG_IDLE) == 0 && g_AudioChannels[i].prop == prop) {
			g_AudioChannels[i].unk44 = arg1;

			if (arg2 > 0) {
				g_AudioChannels[i].unk20 = arg2 * 4;
			} else {
				g_AudioChannels[i].unk20 = -1;
			}

#if VERSION >= VERSION_NTSC_1_0
			prevpri = osGetThreadPri(0);
			osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
			propsndTickChannel(i);
			osSetThreadPri(0, prevpri);
#else
			propsndTickChannel(i);
#endif
		}
	}
}

void func0f093790(struct prop *prop, s32 arg1)
{
	OSPri prevpri;
	s32 i;

	for (i = 0; i < (IS4MB() ? 30 : 40); i++) {
		if ((g_AudioChannels[i].flags & AUDIOCHANNELFLAG_IDLE) == 0 && prop == g_AudioChannels[i].prop) {
#if VERSION >= VERSION_NTSC_1_0
			if (arg1 > 100) {
				arg1 = 100;
			}

			prevpri = osGetThreadPri(0);
			osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);

			g_AudioChannels[i].unk10 = arg1 * 32767 / 100;
			propsndTickChannel(i);

			osSetThreadPri(0, prevpri);
#else
			g_AudioChannels[i].unk10 = arg1 * 32767 / 100;
			propsndTickChannel(i);
#endif
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
void func0f0938ec(struct prop *prop)
{
	s32 lowestuuid = -1;
	s32 count = 0;
	s32 bestindex = -1;
	s32 i;

	for (i = 0; i < (IS4MB() ? 30 : 40); i++) {
		struct audiochannel *channel = &g_AudioChannels[i];

		if ((channel->flags & AUDIOCHANNELFLAG_IDLE) == 0
				&& (channel->flags2 & AUDIOCHANNELFLAG2_0080) == 0
				&& prop == channel->prop
				&& channel->unk28 == 0x11) {
			count++;

			if (channel->uuid < lowestuuid) {
				lowestuuid = channel->uuid;
				bestindex = i;
			}
		}
	}

	if (1);

	if (count >= 2 && bestindex != -1) {
		func0f092a98(bestindex);
	}
}
#endif

s16 propsnd0f0939f8(
		struct audiochannel *channel,
		struct prop *prop,
		s16 soundnum,
		s16 padnum,
		s32 arg4,
		u16 flags,
		u16 flags2,
		s32 arg7,
		struct coord *pos,
		f32 arg9,
		s16 *rooms,
		s32 room,
		f32 arg12,
		f32 arg13,
		f32 arg14)
{
	union soundnumhack spac;
	OSPri prevpri;
	u32 stack[2];
	s32 tmp;

#if VERSION >= VERSION_NTSC_1_0
	struct pad pad;
	s32 i;
	s32 j;

	if (arg7 == 0x11) {
		func0f0938ec(prop);
	}

	spac.packed = soundnum;

	if (channel == NULL) {
		if (arg7 != 16 && var8005ddd4 > 12) {
			return -1;
		}

		for (i = 8; i < (IS4MB() ? 30 : 40); i++) {
			if (g_AudioChannels[i].flags & AUDIOCHANNELFLAG_IDLE) {
				channel = &g_AudioChannels[i];
				channel->channelnum = i;
				break;
			}
		}
	}
#else
	s32 t4 = -1;
	struct pad pad;
	s32 i;
	s32 j;
	s32 count = 0;

	spac.packed = soundnum;

	if (channel == NULL) {
		for (i = 8; i < (IS4MB() ? 30 : 40); i++) {
			if (g_AudioChannels[i].flags & AUDIOCHANNELFLAG_IDLE) {
				channel = &g_AudioChannels[i];
				if (i);

				if (arg7 != 16) {
					channel->channelnum = i;
				} else {
					t4 = i;
				}
				break;
			}

			if (arg7 == 16) {
				count++;
			}
		}
	}

	if (arg7 == 16) {
		if (count >= 12) {
			return -1;
		}

		if (t4 != -1) {
			channel = &g_AudioChannels[t4];
			channel->channelnum = t4;
		} else {
			return -1;
		}
	}
#endif

	if (padnum >= 0) {
		pos = &g_Pads[padnum].pos;
		room = g_Pads[padnum].room;
		prop = NULL;
	}

	if (channel == NULL) {
		return -1;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (g_AudioPrevUuid < 0xffffffff) {
		g_AudioPrevUuid++;
	} else {
		g_AudioPrevUuid = 0;
	}
#endif

	channel->flags = flags;
	channel->flags2 = flags2;
	channel->audiohandle = NULL;
	channel->unk06 = -1;
	channel->unk08 = -1;
	channel->unk0e = -1;
	channel->unk04 = (arg4 != -1) ? arg4 : -1;
	channel->unk0a = 64;
	channel->unk0c = 0;
	channel->unk10 = 0x7fff;
	channel->unk1a = 1;
	channel->unk44 = (arg9 > 0) ? arg9 : -1;
	channel->unk48 = channel->unk44;
	channel->unk20 = -1;
	channel->unk1c = -1;
	channel->padnum = padnum;
	channel->prop = prop;
	channel->unk28 = arg7;
	channel->unk12 = arg4;
	channel->unk40 = -1;
	channel->unk34 = (arg12 > 0) ? arg12 : 400;
	channel->unk38 = (arg13 > 0) ? arg13 : 2500;
	channel->unk3c = (arg14 > 0) ? arg14 : 3000;
	channel->unk18 = 0;
#if VERSION >= VERSION_NTSC_1_0
	channel->uuid = g_AudioPrevUuid;
#endif

	if (spac.hasconfig) {
		s32 id = spac.confignum;
		s32 confignum = g_AudioRussMappings[id].audioconfig_index;
		s32 newid = g_AudioRussMappings[id].soundnum;

		channel->unk34 = g_AudioConfigs[confignum].unk00;
		channel->unk38 = g_AudioConfigs[confignum].unk04;
		channel->unk3c = g_AudioConfigs[confignum].unk08;
		channel->unk18 = g_AudioConfigs[confignum].unk18;

		if (g_AudioConfigs[confignum].unk10 != 100) {
			channel->unk10 = g_AudioConfigs[confignum].unk10 * 327;
		}

		if (g_AudioConfigs[confignum].unk0c > 0) {
			channel->unk44 = g_AudioConfigs[confignum].unk0c;
		}

		tmp = g_AudioConfigs[confignum].unk14;

		if (tmp != -1) {
			channel->unk0a = tmp;
			channel->flags |= AUDIOCHANNELFLAG_0020;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_01) {
			channel->flags |= AUDIOCHANNELFLAG_0800;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_04) {
			channel->flags2 |= AUDIOCHANNELFLAG2_0001;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_08) {
			if (channel->unk04 == -1) {
				channel->unk04 = channel->unk10;
			}

			channel->flags |= AUDIOCHANNELFLAG_8000;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_OFFENSIVE) {
			channel->flags2 |= AUDIOCHANNELFLAG2_OFFENSIVE;
		}

		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_20) {
			channel->flags2 |= AUDIOCHANNELFLAG2_0010;
		}

#if VERSION >= VERSION_NTSC_1_0
		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_40) {
			channel->flags2 |= AUDIOCHANNELFLAG2_0040;
		}
#endif

		channel->flags |= AUDIOCHANNELFLAG_0040;

		spac.packed = newid;
		spac.hasconfig = false;
		soundnum = spac.packed;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (channel->unk18) {
		channel->flags |= AUDIOCHANNELFLAG_0002;
	}
#endif

	channel->soundnum26 = spac.packed;
	channel->unk2c = spac.id;

#if VERSION >= VERSION_NTSC_1_0
	if (sndIsFiltered(channel->unk2c)) {
		channel->flags2 |= AUDIOCHANNELFLAG2_OFFENSIVE;
	}
#endif

	if (spac.unk02) {
		channel->flags2 |= AUDIOCHANNELFLAG2_0010;
	}

#if VERSION < VERSION_NTSC_1_0
	if (channel->flags2 & AUDIOCHANNELFLAG2_0010) {
		if (channel->unk04 == -1) {
			channel->unk04 = channel->unk10;
		}
	}
#endif

	if (pos) {
		channel->pos.x = pos->x;
		channel->pos.y = pos->y;
		channel->pos.z = pos->z;
		channel->posptr = &channel->pos;
	} else {
		channel->posptr = NULL;
	}

	if (rooms) {
		// @dangerous: Array overflow will occur if rooms has more than 8 elements
		for (j = 0; rooms[j] != -1; j++) {
			channel->rooms[j] = rooms[j];
		}

		channel->rooms[j] = -1;
	} else if (room != -1) {
		channel->rooms[0] = room;
		channel->rooms[1] = -1;
	} else {
		channel->rooms[0] = -1;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (!pos && !channel->prop) {
		channel->flags2 |= AUDIOCHANNELFLAG2_0010;
	}

	if ((channel->flags2 & AUDIOCHANNELFLAG2_0010) && channel->unk04 == -1) {
		channel->unk04 = channel->unk10;
	}
#endif

	channel->flags |= AUDIOCHANNELFLAG_1000;

	if (sndIsMp3(soundnum)) {
		channel->flags |= AUDIOCHANNELFLAG_ISMP3;

#if VERSION >= VERSION_NTSC_1_0
		prevpri = osGetThreadPri(0);
		osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
		propsndTickChannel(channel->channelnum);
		osSetThreadPri(0, prevpri);
#else
		propsndTickChannel(channel->channelnum);
#endif
	} else {
		prevpri = osGetThreadPri(0);
		osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
		propsndTickChannel(channel->channelnum);
		osSetThreadPri(0, prevpri);
	}

#if VERSION >= VERSION_NTSC_1_0
	if (channel->flags & AUDIOCHANNELFLAG_0400) {
		channel->flags &= ~AUDIOCHANNELFLAG_0400;
		channel->flags2 |= AUDIOCHANNELFLAG2_0010;
	}

	channel->flags &= ~AUDIOCHANNELFLAG_1000;
#else
	if (channel->flags & AUDIOCHANNELFLAG_0400) {
		channel->flags = AUDIOCHANNELFLAG_IDLE;
	} else {
		channel->flags &= ~AUDIOCHANNELFLAG_1000;
	}
#endif

	return channel->channelnum;
}

s32 audioPlayFromProp(s32 channelnum, s16 soundnum, s32 arg2, struct prop *prop, s16 arg4, u16 arg5)
{
	s32 retchannelnum = -1;

	if (arg4 == 11) {
		if (channelnum >= 0 && channelnum <= 7) {
#if VERSION >= VERSION_NTSC_1_0
			if (g_AudioChannels[channelnum].flags & AUDIOCHANNELFLAG_IDLE) {
				g_AudioChannels[channelnum].soundnum26 = soundnum;
				g_AudioChannels[channelnum].unk28 = 11;
				g_AudioChannels[channelnum].flags &= ~AUDIOCHANNELFLAG_IDLE;
				retchannelnum = channelnum;
			} else {
				g_AudioChannels[channelnum].soundnum26 = soundnum;
				g_AudioChannels[channelnum].unk28 = 11;
				g_AudioChannels[channelnum].flags &= ~AUDIOCHANNELFLAG_IDLE;
				retchannelnum = channelnum;
			}
#else
			g_AudioChannels[channelnum].soundnum26 = soundnum;
			g_AudioChannels[channelnum].unk28 = 11;
			g_AudioChannels[channelnum].flags &= ~AUDIOCHANNELFLAG_IDLE;
			retchannelnum = channelnum;
#endif
		} else {
			// empty
		}
	} else if (channelnum == 10) {
		retchannelnum = propsnd0f0939f8(NULL, prop, soundnum, -1,
				(arg2 ? 0 : -1), arg5 | 0x0080, 0, arg4, 0, -1, 0, -1, -1, -1, -1);
#if VERSION >= VERSION_NTSC_1_0
	} else if (channelnum < 0 || channelnum >= 8 || channelnum == 9) {
		retchannelnum = propsnd0f0939f8(NULL, prop, soundnum, -1,
			(arg2 ? 0 : -1), arg5, 0, arg4, 0, -1, 0, -1, -1, -1, -1);
#else
	} else if (channelnum == 9) {
		retchannelnum = propsnd0f0939f8(NULL, prop, soundnum, -1,
			(arg2 ? 0 : -1), arg5, 0, arg4, 0, -1, 0, -1, -1, -1, -1);
	} else if (channelnum < 0 || channelnum >= 8) {
		retchannelnum = propsnd0f0939f8(NULL, prop, soundnum, -1,
			(arg2 ? 0 : -1), arg5, 0, arg4, 0, -1, 0, -1, -1, -1, -1);
#endif
	} else {
		if ((g_AudioChannels[channelnum].flags & AUDIOCHANNELFLAG_IDLE) == 0) {
			func0f092a98(channelnum);
		}

		g_AudioChannels[channelnum].channelnum = channelnum;

		propsnd0f0939f8(&g_AudioChannels[channelnum], prop, soundnum, -1,
			(arg2 ? 0 : -1), arg5, 0, arg4, 0, -1, 0, -1, -1, -1, -1);

		retchannelnum = channelnum;
	}

	return retchannelnum;
}

void audioMuteChannel(s32 channelnum)
{
	if (channelnum == 10) {
		s32 i;

		for (i = 8; i < (IS4MB() ? 30 : 40); i++) {
			if ((g_AudioChannels[i].flags & AUDIOCHANNELFLAG_IDLE) == 0
					&& (g_AudioChannels[i].flags & AUDIOCHANNELFLAG_0080)) {
				func0f092a98(i);
			}
		}
	} else if (channelnum >= 0 && channelnum <= 7) {
		func0f092a98(channelnum);
	}
}

bool audioIsChannelIdle(s32 channelnum)
{
	if (channelnum >= 0 && channelnum <= 7) {
		return (g_AudioChannels[channelnum].flags & AUDIOCHANNELFLAG_IDLE) ? true : false;
	}

	if (channelnum == 10) {
		s32 i;

		for (i = 8; i < (IS4MB() ? 30 : 40); i++) {
			if (g_AudioChannels[i].flags & AUDIOCHANNELFLAG_0080) {
				return false;
			}
		}
	}

	return true;
}

void audioPlayFromProp2(s32 channelnum, s32 arg1, s16 padnum, struct prop *prop, s32 arg4, s32 arg5, s32 arg6, u16 arg7)
{
	struct audiochannel *channel = &g_AudioChannels[channelnum];
	bool a1 = (arg4 >= 6) ? true : false;
	bool a0 = (arg7 & 2) ? true : false;

	if (channelnum >= 0 && channelnum <= 7) {
		if (channel->unk28 == 11) {
			g_AudioChannels[channelnum].channelnum = (u16)channelnum;

			propsnd0f0939f8(&g_AudioChannels[channelnum], prop, channel->soundnum26, -1,
					-1, arg7, 0, 0, 0, -1, 0, -1, 400, arg5, arg6);
		} else {
			if ((channel->flags & AUDIOCHANNELFLAG_2000) == 0 && arg1 >= 0) {
				channel->unk04 = arg1;
			}

			if (a1) {
				channel->unk1c = TICKS(arg4);
			}

			if (padnum != -1) {
				channel->padnum = padnum;
			}

			if (prop) {
				channel->prop = prop;
			}

			if (a0) {
				channel->flags |= AUDIOCHANNELFLAG_0002;
			}

			if ((channel->flags & AUDIOCHANNELFLAG_0040) == 0) {
				channel->unk34 = 400;
				channel->unk38 = arg5;
				channel->unk3c = arg6;
				channel->unk18 = 0;
			}

			if (!a1 || channel->unk1c == 0) {
#if VERSION >= VERSION_NTSC_1_0
				OSPri prevpri = osGetThreadPri(0);
				osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
				propsndTickChannel(channelnum);
				osSetThreadPri(0, prevpri);
#else
				propsndTickChannel(channelnum);
#endif
			}
		}
	}
}

s32 propsnd0f0946b0(struct coord *pos, f32 arg1, f32 arg2, f32 arg3, s16 *rooms, s16 soundnum, s32 arg6, f32 *arg7)
{
	union soundnumhack sp6c;
	union soundnumhack sp68;
	f32 sp64;
	s16 sp62;
	s32 s0;
	s32 i;

	sp64 = arg3 + 10.0f;

	if (rooms != NULL) {
		sp62 = *rooms;
	} else {
		sp62 = -1;
	}

	sp68.packed = soundnum;
	sp6c.packed = soundnum;

#if VERSION < VERSION_NTSC_1_0
	if (g_PropsndPrintChannels) {
		sp64 = 9999999;
	}
#endif

	if (sp68.hasconfig) {
		s32 confignum = sp68.confignum;
		s32 index = g_AudioRussMappings[confignum].audioconfig_index;

		sp6c.packed = g_AudioRussMappings[confignum].soundnum;

		arg1 = g_AudioConfigs[index].unk00;
		arg2 = g_AudioConfigs[index].unk04;
		arg3 = g_AudioConfigs[index].unk08;

		if (arg3 < sp64) {
			sp64 = arg3;
		}
	}

	if (var8006ae34 && var8006ae2c == sp6c.id) {
		s0 = 1;
	} else {
		s0 = 0;
	}

	for (i = 0; i < PLAYERCOUNT(); i++) {
		struct player *player = g_Vars.players[i];
		s32 camroom;

		if (sp6c.unk02 == 0) {
			camroom = player->cam_room;
		} else {
			camroom = -1;
		}

		func0f0056f4(camroom, &player->cam_pos, sp62, pos, 0, &sp64, s0);
	}

	if (arg7 != NULL) {
		*arg7 = sp64;
	}

	return func0f0927d4(sp64, arg1, arg2, arg3, arg6);
}

s32 propsnd0f094940(s32 degrees, f32 arg1, struct audiochannel *channel)
{
	s32 result;

	while (degrees >= 180) {
		degrees -= 360;
	}

	while (degrees < -180) {
		degrees += 360;
	}

	switch (g_SoundMode) {
	default:
		{
			s32 absdegrees = degrees > 0 ? degrees : -degrees;
			s32 dir;
			s32 v1;

			if (absdegrees > 90) {
				absdegrees = 180 - absdegrees;
			}

			v1 = absdegrees && absdegrees;
			dir = (degrees > 0) ? (1) : (-1);

			if (v1);

			degrees = dir * absdegrees;
		}
		break;
	case SOUNDMODE_SURROUND:
		if (degrees > -45 && degrees < 45) {
			degrees *= 2;
		} else {
			s32 dir = degrees > 0 ? 1 : -1;
			s32 v1 = dir && dir;
			s32 absdegrees = degrees > 0 ? degrees : -degrees;
			s32 t4 = (180 - absdegrees) * 0.6666667f;

			if (v1);

			degrees = (180 - t4) * dir;
		}
		break;
	}

	if (degrees >= -90 && degrees <= 90) {
		result = degrees * 0.7f + 64.0f;
	} else {
		s32 v0;
		s32 dir = degrees > 0 ? 1 : -1;
		s32 absdegrees = ABS(degrees);

		result = (s32) ((180 - absdegrees) * dir * 0.7f + 64.0f) + 128;
	}

	if (channel != NULL) {
		channel->unk14 = degrees;
		channel->unk16 = 100.0f * arg1;
	}

	return result;
}

s32 propsnd0f094b1c(struct coord *pos, s32 arg1, f32 arg2, struct audiochannel *channel)
{
	s32 result = 64;
	u32 stack[4];
	s32 a0;
	f32 f2;

	if (PLAYERCOUNT() < 2) {
		struct coord *campos = &g_Vars.currentplayer->cam_pos;
		f32 sp3c;
		f32 sp38;

		f2 = -(atan2f(pos->x - campos->x, pos->z - campos->z) * 180.0f / M_PI + g_Vars.currentplayer->vv_theta);

		if (arg2 >= 0.0f) {
			sp3c = sinf(0.017453292f * f2);
			sp38 = cosf(0.017453292f * f2);

			sp3c *= arg2;

			f2 = atan2f(ABSF(sp3c), ABSF(sp38));

			if (!(sp3c >= 0.0f) || !(sp38 >= 0.0f)) {
				if (sp3c >= 0.0f) {
					f2 = M_PI - f2;
				} else if (sp38 >= 0.0f) {
					f2 = -f2;
				} else {
					f2 = -(M_PI - f2);
				}
			}

			a0 = (f2 * 57.295776f);
		} else {
			a0 = f2;
		}

		if (channel != NULL) {
			channel->unk14 = a0;
			channel->unk16 = 100.0f * arg2;
		}

		result = propsnd0f094940(a0, arg2, channel);
	}

	return result;
}

s32 propsnd0f094d78(struct coord *pos, f32 arg1, f32 arg2, f32 arg3, f32 arg4, bool arg5, struct audiochannel *channel)
{
	s32 result = 0x40;

	if (pos != NULL && arg4 > 0) {
		if (arg1 < 0) {
			arg1 = 400;
		}

		if (arg2 < 0) {
			arg2 = 2500;
		}

		if (arg3 < 0) {
			arg3 = 3000;
		}

		if (arg4 < arg3) {
			if (arg1 > 5501) {
				arg1 = 5501;
			}

			if (arg2 > 5801) {
				arg2 = 5801;
			}

			if (arg5 != 0) {
				if (!(arg4 < arg1)) {
					if (arg4 < arg2) {
						f32 f2 = (arg4 - arg1) / (arg2 - arg1);

						if (f2 < 0) {
							f2 = 0;
						}

						if (f2 > 1) {
							f2 = 1;
						}

						result = propsnd0f094b1c(pos, 0, f2, channel);
					} else {
						result = propsnd0f094b1c(pos, 0, -1, NULL);
					}
				}
			} else {
				result = propsnd0f094b1c(pos, 0, -1, channel);
			}
		}
	}

	return result;
}

#if VERSION >= VERSION_NTSC_1_0
void propsnd0f094ef4(struct coord *pos, s16 *rooms, s16 soundnum, s32 *arg3, s32 *arg4)
{
	f32 sp5c;
	f32 sp58;
	f32 sp54;
	struct audiorussmapping *russ;
	struct audioconfig *config;
	union soundnumhack sp48;
	union soundnumhack sp44;
	f32 sp40;
	bool sp3c;
	s32 index;
	s32 confignum;
	s32 zero = 0;

	sp5c = 400;
	sp58 = 2500;
	sp54 = 3000;
	if (1);
	sp44.packed = soundnum;
	sp40 = 9999999;
	sp3c = false;

	// To make this match, sp40 must be reloaded from the stack rather than
	// reuse its register. Calling a function invalidates the register, thus
	// forcing the compiler to emit code that reloads it from stack. Then an
	// optimisation pass in the compiler removes this branch and function call,
	// leaving the reload from stack in place.
	if (zero) {
		random();
	}

	if (sp44.hasconfig) {
		confignum = sp44.confignum;
		russ = &g_AudioRussMappings[confignum];
		index = russ->audioconfig_index;
		config = &g_AudioConfigs[index];
		sp5c = config->unk00;
		sp58 = config->unk04;
		sp54 = config->unk08;
		sp48.packed = russ->soundnum;

		if (config->flags & AUDIOCONFIGFLAG_01) {
			sp3c = true;
		}

		if (sp54 < sp40) {
			sp40 = sp54;
		}

		sp48.hasconfig = false;
		soundnum = sp48.packed;
	}

	*arg3 = propsnd0f0946b0(pos, sp5c, sp58, sp54, rooms, soundnum, 0x7fff, &sp40);
	*arg4 = propsnd0f094d78(pos, sp5c, sp58, sp54, sp40, sp3c, 0);
}
#endif

void func0f09505c(struct sndstate *handle, struct coord *pos, f32 arg2, f32 arg3, f32 arg4, s16 *rooms, s16 soundnum, s32 arg7, f32 *arg8)
{
	union soundnumhack sp5c;
	union soundnumhack sp58;
	f32 sp54;
	bool sp50;
	s32 sp4c;
	s32 pan;

	sp50 = false;
	sp54 = 9999999;
	sp58.packed = soundnum;

	if (arg8 == NULL) {
		arg8 = &sp54;
	}

	if (sp58.hasconfig) {
		s32 confignum = sp58.confignum;
		s32 index = g_AudioRussMappings[confignum].audioconfig_index;

		arg2 = g_AudioConfigs[index].unk00;
		arg3 = g_AudioConfigs[index].unk04;
		arg4 = g_AudioConfigs[index].unk08;
		sp5c.packed = g_AudioRussMappings[confignum].soundnum;

		if (g_AudioConfigs[index].flags & AUDIOCONFIGFLAG_01) {
			sp50 = true;
		}

		if (arg4 < *arg8) {
			*arg8 = arg4;
		}

		sp5c.hasconfig = false;
		soundnum = sp5c.packed;
	}

	sp4c = propsnd0f0946b0(pos, arg2, arg3, arg4, rooms, soundnum, arg7, arg8);
	pan = propsnd0f094d78(pos, arg2, arg3, arg4, *arg8, sp50, 0);
	sndAdjust(&handle, sndIsMp3(soundnum), sp4c, pan, soundnum, 1.0f, 1, -1, 1);
}

s32 propsndGetRandomSparkSound(void)
{
	s32 index = random() % 6;

	s16 sounds[] = {
		SFX_80B0,
		SFX_80B1,
		SFX_80B2,
		SFX_80B3,
		SFX_80B4,
		SFX_80B5,
	};

	return sounds[index];
}

u32 propsnd0f095258(u32 arg0, u32 arg1)
{
	return arg0;
}

u32 propsnd0f095264(u32 arg0, u32 arg1)
{
	return arg0;
}

void propsnd0f095270(void)
{
	// empty
}

/**
 * Get the duration for an MP3 file by channel number.
 *
 * All MP3 files are 24 kilobits per second
 * so this is just math based on the filesize.
 */
s32 propsndGetDuration60(s32 channelnum)
{
	struct audiochannel *channel = &g_AudioChannels[channelnum];

	if (channelnum >= 0 && channelnum < (IS4MB() ? 30 : 40)
			&& (channel->flags & AUDIOCHANNELFLAG_IDLE) == 0
			&& (channel->flags & AUDIOCHANNELFLAG_ISMP3)) {
		union soundnumhack soundnum;
		soundnum.packed = channel->soundnum26;

		return fileGetRomSize(soundnum.id) * 60 / (1024 * 24 / 8);
	}

	return -1;
}
