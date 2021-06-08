#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraicommands.h"
#include "game/dlights.h"
#include "game/game_092610.h"
#include "game/atan2f.h"
#include "game/hudmsg.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/rng.h"
#include "lib/lib_16110.h"
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
u32 g_AudioPrevUuid = 0x00000000;
s8 var8006ae18 = 0;
s8 var8006ae1c = 0;
s8 var8006ae20 = 0;
s8 var8006ae24 = 0;
s8 var8006ae28 = 0;
u32 var8006ae2c = 0x00000000;
u32 var8006ae30 = 0x00000000;
u32 var8006ae34 = 0x00000000;
u32 var8006ae38 = 0x00000000;
u32 var8006ae3c = 0x00000000;
u32 var8006ae40 = 0x00000000;
u32 var8006ae44 = 0x00000000;
u32 var8006ae48 = 0x00000001;
u32 var8006ae4c = 0x00000000;
u32 var8006ae50 = 0xffff0000;
u32 var8006ae54 = 0x000003e7;
u32 var8006ae58 = 0x00000000;
u32 var8006ae5c = 0x80b080b1;
u32 var8006ae60 = 0x80b280b3;
u32 var8006ae64 = 0x80b480b5;
u32 var8006ae68 = 0x00000000;
u32 var8006ae6c = 0x00000000;

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

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f09294c
/*  f09294c:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f092950:	afb10048 */ 	sw	$s1,0x48($sp)
/*  f092954:	afb00044 */ 	sw	$s0,0x44($sp)
/*  f092958:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f09295c:	87af0056 */ 	lh	$t7,0x56($sp)
/*  f092960:	00808025 */ 	or	$s0,$a0,$zero
/*  f092964:	00c08825 */ 	or	$s1,$a2,$zero
/*  f092968:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f09296c:	3c06451c */ 	lui	$a2,0x451c
/*  f092970:	260e0028 */ 	addiu	$t6,$s0,0x28
/*  f092974:	3c07453b */ 	lui	$a3,0x453b
/*  f092978:	24187fff */ 	addiu	$t8,$zero,0x7fff
/*  f09297c:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f092980:	34e78000 */ 	ori	$a3,$a3,0x8000
/*  f092984:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f092988:	34c64000 */ 	ori	$a2,$a2,0x4000
/*  f09298c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f092990:	3c0543c8 */ 	lui	$a1,0x43c8
/*  f092994:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f092998:	0fc251ac */ 	jal	func0f0946b0
/*  f09299c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0929a0:	10400038 */ 	beqz	$v0,.L0f092a84
/*  f0929a4:	3c058009 */ 	lui	$a1,%hi(g_Is4Mb)
/*  f0929a8:	90a50af0 */ 	lbu	$a1,%lo(g_Is4Mb)($a1)
/*  f0929ac:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0929b0:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f0929b4:	14c50003 */ 	bne	$a2,$a1,.L0f0929c4
/*  f0929b8:	24030028 */ 	addiu	$v1,$zero,0x28
/*  f0929bc:	10000001 */ 	b	.L0f0929c4
/*  f0929c0:	2403001e */ 	addiu	$v1,$zero,0x1e
.L0f0929c4:
/*  f0929c4:	28610009 */ 	slti	$at,$v1,0x9
/*  f0929c8:	14200019 */ 	bnez	$at,.L0f092a30
/*  f0929cc:	3c198007 */ 	lui	$t9,%hi(g_AudioChannels)
/*  f0929d0:	8f39ae10 */ 	lw	$t9,%lo(g_AudioChannels)($t9)
/*  f0929d4:	00044100 */ 	sll	$t0,$a0,0x4
/*  f0929d8:	01044023 */ 	subu	$t0,$t0,$a0
/*  f0929dc:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f0929e0:	03281021 */ 	addu	$v0,$t9,$t0
/*  f0929e4:	94490030 */ 	lhu	$t1,0x30($v0)
.L0f0929e8:
/*  f0929e8:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f0929ec:	312a0001 */ 	andi	$t2,$t1,0x1
/*  f0929f0:	15400007 */ 	bnez	$t2,.L0f092a10
/*  f0929f4:	00000000 */ 	nop
/*  f0929f8:	8c4b0050 */ 	lw	$t3,0x50($v0)
/*  f0929fc:	160b0004 */ 	bne	$s0,$t3,.L0f092a10
/*  f092a00:	00000000 */ 	nop
/*  f092a04:	844c0028 */ 	lh	$t4,0x28($v0)
/*  f092a08:	522c001f */ 	beql	$s1,$t4,.L0f092a88
/*  f092a0c:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f092a10:
/*  f092a10:	14c50003 */ 	bne	$a2,$a1,.L0f092a20
/*  f092a14:	24420078 */ 	addiu	$v0,$v0,0x78
/*  f092a18:	10000002 */ 	b	.L0f092a24
/*  f092a1c:	2403001e */ 	addiu	$v1,$zero,0x1e
.L0f092a20:
/*  f092a20:	24030028 */ 	addiu	$v1,$zero,0x28
.L0f092a24:
/*  f092a24:	0083082a */ 	slt	$at,$a0,$v1
/*  f092a28:	5420ffef */ 	bnezl	$at,.L0f0929e8
/*  f092a2c:	94490030 */ 	lhu	$t1,0x30($v0)
.L0f092a30:
/*  f092a30:	3c01bf80 */ 	lui	$at,0xbf80
/*  f092a34:	44810000 */ 	mtc1	$at,$f0
/*  f092a38:	240dffff */ 	addiu	$t5,$zero,-1
/*  f092a3c:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f092a40:	240fffff */ 	addiu	$t7,$zero,-1
/*  f092a44:	afaf002c */ 	sw	$t7,0x2c($sp)
/*  f092a48:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f092a4c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f092a50:	00002025 */ 	or	$a0,$zero,$zero
/*  f092a54:	02002825 */ 	or	$a1,$s0,$zero
/*  f092a58:	87a60056 */ 	lh	$a2,0x56($sp)
/*  f092a5c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f092a60:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f092a64:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f092a68:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f092a6c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f092a70:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f092a74:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f092a78:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f092a7c:	0fc24e7e */ 	jal	func0f0939f8
/*  f092a80:	e7a00038 */ 	swc1	$f0,0x38($sp)
.L0f092a84:
/*  f092a84:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f092a88:
/*  f092a88:	8fb00044 */ 	lw	$s0,0x44($sp)
/*  f092a8c:	8fb10048 */ 	lw	$s1,0x48($sp)
/*  f092a90:	03e00008 */ 	jr	$ra
/*  f092a94:	27bd0050 */ 	addiu	$sp,$sp,0x50
);
#else
GLOBAL_ASM(
glabel func0f09294c
/*  f090f88:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f090f8c:	afb10048 */ 	sw	$s1,0x48($sp)
/*  f090f90:	afb00044 */ 	sw	$s0,0x44($sp)
/*  f090f94:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f090f98:	87af0056 */ 	lh	$t7,0x56($sp)
/*  f090f9c:	00808025 */ 	or	$s0,$a0,$zero
/*  f090fa0:	00c08825 */ 	or	$s1,$a2,$zero
/*  f090fa4:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f090fa8:	3c06451c */ 	lui	$a2,0x451c
/*  f090fac:	260e0028 */ 	addiu	$t6,$s0,0x28
/*  f090fb0:	3c07453b */ 	lui	$a3,0x453b
/*  f090fb4:	24187fff */ 	addiu	$t8,$zero,0x7fff
/*  f090fb8:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f090fbc:	34e78000 */ 	ori	$a3,$a3,0x8000
/*  f090fc0:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f090fc4:	34c64000 */ 	ori	$a2,$a2,0x4000
/*  f090fc8:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f090fcc:	3c0543c8 */ 	lui	$a1,0x43c8
/*  f090fd0:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f090fd4:	0fc24a76 */ 	jal	func0f0946b0
/*  f090fd8:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f090fdc:	1040003a */ 	beqz	$v0,.NB0f0910c8
/*  f090fe0:	3c058009 */ 	lui	$a1,0x8009
/*  f090fe4:	90a530e0 */ 	lbu	$a1,0x30e0($a1)
/*  f090fe8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f090fec:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f090ff0:	14c50003 */ 	bne	$a2,$a1,.NB0f091000
/*  f090ff4:	24030028 */ 	addiu	$v1,$zero,0x28
/*  f090ff8:	10000001 */ 	beqz	$zero,.NB0f091000
/*  f090ffc:	2403001e */ 	addiu	$v1,$zero,0x1e
.NB0f091000:
/*  f091000:	28610009 */ 	slti	$at,$v1,0x9
/*  f091004:	1420001b */ 	bnez	$at,.NB0f091074
/*  f091008:	3c198007 */ 	lui	$t9,0x8007
/*  f09100c:	000440c0 */ 	sll	$t0,$a0,0x3
/*  f091010:	01044023 */ 	subu	$t0,$t0,$a0
/*  f091014:	8f39d520 */ 	lw	$t9,-0x2ae0($t9)
/*  f091018:	00084080 */ 	sll	$t0,$t0,0x2
/*  f09101c:	01044021 */ 	addu	$t0,$t0,$a0
/*  f091020:	00084080 */ 	sll	$t0,$t0,0x2
/*  f091024:	03281021 */ 	addu	$v0,$t9,$t0
/*  f091028:	94490030 */ 	lhu	$t1,0x30($v0)
.NB0f09102c:
/*  f09102c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f091030:	312a0001 */ 	andi	$t2,$t1,0x1
/*  f091034:	15400007 */ 	bnez	$t2,.NB0f091054
/*  f091038:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09103c:	8c4b0050 */ 	lw	$t3,0x50($v0)
/*  f091040:	160b0004 */ 	bne	$s0,$t3,.NB0f091054
/*  f091044:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091048:	844c0028 */ 	lh	$t4,0x28($v0)
/*  f09104c:	522c001f */ 	beql	$s1,$t4,.NB0f0910cc
/*  f091050:	8fbf004c */ 	lw	$ra,0x4c($sp)
.NB0f091054:
/*  f091054:	14c50003 */ 	bne	$a2,$a1,.NB0f091064
/*  f091058:	24420074 */ 	addiu	$v0,$v0,0x74
/*  f09105c:	10000002 */ 	beqz	$zero,.NB0f091068
/*  f091060:	2403001e */ 	addiu	$v1,$zero,0x1e
.NB0f091064:
/*  f091064:	24030028 */ 	addiu	$v1,$zero,0x28
.NB0f091068:
/*  f091068:	0083082a */ 	slt	$at,$a0,$v1
/*  f09106c:	5420ffef */ 	bnezl	$at,.NB0f09102c
/*  f091070:	94490030 */ 	lhu	$t1,0x30($v0)
.NB0f091074:
/*  f091074:	3c01bf80 */ 	lui	$at,0xbf80
/*  f091078:	44810000 */ 	mtc1	$at,$f0
/*  f09107c:	240dffff */ 	addiu	$t5,$zero,-1
/*  f091080:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f091084:	240fffff */ 	addiu	$t7,$zero,-1
/*  f091088:	afaf002c */ 	sw	$t7,0x2c($sp)
/*  f09108c:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f091090:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f091094:	00002025 */ 	or	$a0,$zero,$zero
/*  f091098:	02002825 */ 	or	$a1,$s0,$zero
/*  f09109c:	87a60056 */ 	lh	$a2,0x56($sp)
/*  f0910a0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0910a4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0910a8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0910ac:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0910b0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0910b4:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0910b8:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0910bc:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0910c0:	0fc24762 */ 	jal	func0f0939f8
/*  f0910c4:	e7a00038 */ 	swc1	$f0,0x38($sp)
.NB0f0910c8:
/*  f0910c8:	8fbf004c */ 	lw	$ra,0x4c($sp)
.NB0f0910cc:
/*  f0910cc:	8fb00044 */ 	lw	$s0,0x44($sp)
/*  f0910d0:	8fb10048 */ 	lw	$s1,0x48($sp)
/*  f0910d4:	03e00008 */ 	jr	$ra
/*  f0910d8:	27bd0050 */ 	addiu	$sp,$sp,0x50
);
#endif

void func0f092a98(s32 channelnum)
{
	struct audiochannel *channel = &g_AudioChannels[channelnum];

#if VERSION >= VERSION_NTSC_1_0
	channel->flags2 |= 0x80;
#endif

	if (channel->flags & AUDIOCHANNELFLAG_0200) {
		hudmsgsHideByChannel(channelnum);
	}

	if (channel->flags & AUDIOCHANNELFLAG_0008) {
		func0f05abdc(channel->prop);
	}

	if ((channel->flags & AUDIOCHANNELFLAG_0010)) {
		snd0000fbc4(channel->soundnum26);
	} else if (channel->audiohandle && audioIsPlaying(channel->audiohandle)) {
		audioStop(channel->audiohandle);
	}

#if VERSION < VERSION_NTSC_1_0
	channel->flags = AUDIOCHANNELFLAG_IDLE;
#endif
}

GLOBAL_ASM(
glabel func0f092b50
/*  f092b50:	848e0064 */ 	lh	$t6,0x64($a0)
/*  f092b54:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f092b58:	00801025 */ 	or	$v0,$a0,$zero
/*  f092b5c:	106e0005 */ 	beq	$v1,$t6,.L0f092b74
/*  f092b60:	00000000 */ 	nop
/*  f092b64:	844f0066 */ 	lh	$t7,0x66($v0)
.L0f092b68:
/*  f092b68:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f092b6c:	546ffffe */ 	bnel	$v1,$t7,.L0f092b68
/*  f092b70:	844f0066 */ 	lh	$t7,0x66($v0)
.L0f092b74:
/*  f092b74:	03e00008 */ 	jr	$ra
/*  f092b78:	00000000 */ 	nop
);

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f092b7c
/*  f092b7c:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f092b80:	14850003 */ 	bne	$a0,$a1,.L0f092b90
/*  f092b84:	3c0e8007 */ 	lui	$t6,%hi(g_AudioChannels)
/*  f092b88:	03e00008 */ 	jr	$ra
/*  f092b8c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f092b90:
/*  f092b90:	8dceae10 */ 	lw	$t6,%lo(g_AudioChannels)($t6)
/*  f092b94:	00047900 */ 	sll	$t7,$a0,0x4
/*  f092b98:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f092b9c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f092ba0:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f092ba4:	94580030 */ 	lhu	$t8,0x30($v0)
/*  f092ba8:	33190001 */ 	andi	$t9,$t8,0x1
/*  f092bac:	57200013 */ 	bnezl	$t9,.L0f092bfc
/*  f092bb0:	00001025 */ 	or	$v0,$zero,$zero
/*  f092bb4:	84440006 */ 	lh	$a0,0x6($v0)
/*  f092bb8:	10850003 */ 	beq	$a0,$a1,.L0f092bc8
/*  f092bbc:	00801825 */ 	or	$v1,$a0,$zero
/*  f092bc0:	286100c9 */ 	slti	$at,$v1,0xc9
/*  f092bc4:	1420000c */ 	bnez	$at,.L0f092bf8
.L0f092bc8:
/*  f092bc8:	2482ff38 */ 	addiu	$v0,$a0,-200
/*  f092bcc:	00022a00 */ 	sll	$a1,$v0,0x8
/*  f092bd0:	00a22823 */ 	subu	$a1,$a1,$v0
/*  f092bd4:	24013db8 */ 	addiu	$at,$zero,0x3db8
/*  f092bd8:	00a1001a */ 	div	$zero,$a1,$at
/*  f092bdc:	00001812 */ 	mflo	$v1
/*  f092be0:	28610100 */ 	slti	$at,$v1,0x100
/*  f092be4:	14200002 */ 	bnez	$at,.L0f092bf0
/*  f092be8:	00000000 */ 	nop
/*  f092bec:	240300ff */ 	addiu	$v1,$zero,0xff
.L0f092bf0:
/*  f092bf0:	03e00008 */ 	jr	$ra
/*  f092bf4:	00601025 */ 	or	$v0,$v1,$zero
.L0f092bf8:
/*  f092bf8:	00001025 */ 	or	$v0,$zero,$zero
.L0f092bfc:
/*  f092bfc:	03e00008 */ 	jr	$ra
/*  f092c00:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func0f092b7c
/*  f0911c4:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0911c8:	14850003 */ 	bne	$a0,$a1,.NB0f0911d8
/*  f0911cc:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0911d0:	03e00008 */ 	jr	$ra
/*  f0911d4:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f0911d8:
/*  f0911d8:	000478c0 */ 	sll	$t7,$a0,0x3
/*  f0911dc:	01e47823 */ 	subu	$t7,$t7,$a0
/*  f0911e0:	8dced520 */ 	lw	$t6,-0x2ae0($t6)
/*  f0911e4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0911e8:	01e47821 */ 	addu	$t7,$t7,$a0
/*  f0911ec:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0911f0:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f0911f4:	94580030 */ 	lhu	$t8,0x30($v0)
/*  f0911f8:	33190001 */ 	andi	$t9,$t8,0x1
/*  f0911fc:	57200013 */ 	bnezl	$t9,.NB0f09124c
/*  f091200:	00001025 */ 	or	$v0,$zero,$zero
/*  f091204:	84440006 */ 	lh	$a0,0x6($v0)
/*  f091208:	10850003 */ 	beq	$a0,$a1,.NB0f091218
/*  f09120c:	00801825 */ 	or	$v1,$a0,$zero
/*  f091210:	286100c9 */ 	slti	$at,$v1,0xc9
/*  f091214:	1420000c */ 	bnez	$at,.NB0f091248
.NB0f091218:
/*  f091218:	2482ff38 */ 	addiu	$v0,$a0,-200
/*  f09121c:	00022a00 */ 	sll	$a1,$v0,0x8
/*  f091220:	00a22823 */ 	subu	$a1,$a1,$v0
/*  f091224:	24013db8 */ 	addiu	$at,$zero,0x3db8
/*  f091228:	00a1001a */ 	div	$zero,$a1,$at
/*  f09122c:	00001812 */ 	mflo	$v1
/*  f091230:	28610100 */ 	slti	$at,$v1,0x100
/*  f091234:	14200002 */ 	bnez	$at,.NB0f091240
/*  f091238:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09123c:	240300ff */ 	addiu	$v1,$zero,0xff
.NB0f091240:
/*  f091240:	03e00008 */ 	jr	$ra
/*  f091244:	00601025 */ 	or	$v0,$v1,$zero
.NB0f091248:
/*  f091248:	00001025 */ 	or	$v0,$zero,$zero
.NB0f09124c:
/*  f09124c:	03e00008 */ 	jr	$ra
/*  f091250:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f092c04
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
/*  f092b5c:	0c00cc3c */ 	jal	audioIsPlaying
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
/*  f092b94:	0c0039cc */ 	jal	snd0000e9d0
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
/*  f092c8c:	0fc25171 */ 	jal	func0f0946b0
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
/*  f092cd8:	0fc25323 */ 	jal	func0f094d78
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
/*  f0931b8:	0c00cc3c */ 	jal	audioIsPlaying
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
/*  f093240:	0c004218 */ 	jal	snd00010ae4
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
/*  f093334:	0c0039cc */ 	jal	snd0000e9d0
/*  f093338:	00000000 */ 	nop
/*  f09333c:	5440000e */ 	bnezl	$v0,.PF0f093378
/*  f093340:	240a0001 */ 	li	$t2,0x1
/*  f093344:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f093348:	30780008 */ 	andi	$t8,$v1,0x8
/*  f09334c:	53000005 */ 	beqzl	$t8,.PF0f093364
/*  f093350:	30790200 */ 	andi	$t9,$v1,0x200
/*  f093354:	0fc16b78 */ 	jal	func0f05abdc
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
/*  f093398:	0fc16b78 */ 	jal	func0f05abdc
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
/*  f0933c8:	0fc24a94 */ 	jal	func0f092b50
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
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f092c04
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
/*  f092c5c:	0c00cdfc */ 	jal	audioIsPlaying
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
/*  f092c94:	0c003a74 */ 	jal	snd0000e9d0
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
/*  f092d8c:	0fc251ac */ 	jal	func0f0946b0
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
/*  f092dd8:	0fc2535e */ 	jal	func0f094d78
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
/*  f0932c8:	0c00cdfc */ 	jal	audioIsPlaying
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
/*  f093350:	0c0042b9 */ 	jal	snd00010ae4
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
/*  f093444:	0c003a74 */ 	jal	snd0000e9d0
/*  f093448:	00000000 */ 	nop
/*  f09344c:	5440000e */ 	bnezl	$v0,.L0f093488
/*  f093450:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f093454:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f093458:	30790008 */ 	andi	$t9,$v1,0x8
/*  f09345c:	53200005 */ 	beqzl	$t9,.L0f093474
/*  f093460:	306a0200 */ 	andi	$t2,$v1,0x200
/*  f093464:	0fc16af7 */ 	jal	func0f05abdc
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
/*  f0934a8:	0fc16af7 */ 	jal	func0f05abdc
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
/*  f0934d8:	0fc24ad4 */ 	jal	func0f092b50
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
glabel func0f092c04
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
/*  f091290:	0c00d360 */ 	jal	audioIsPlaying
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
/*  f0912c0:	0c003c6c */ 	jal	snd0000e9d0
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
/*  f0913bc:	0fc24a76 */ 	jal	func0f0946b0
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
/*  f091408:	0fc24c2f */ 	jal	func0f094d78
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
/*  f091870:	0c00d360 */ 	jal	audioIsPlaying
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
/*  f0918f0:	0c0043a9 */ 	jal	snd00010ae4
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
/*  f091984:	0c003c6c */ 	jal	snd0000e9d0
/*  f091988:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09198c:	54400018 */ 	bnezl	$v0,.NB0f0919f0
/*  f091990:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f091994:	96030030 */ 	lhu	$v1,0x30($s0)
/*  f091998:	306e0008 */ 	andi	$t6,$v1,0x8
/*  f09199c:	51c00005 */ 	beqzl	$t6,.NB0f0919b4
/*  f0919a0:	306d0200 */ 	andi	$t5,$v1,0x200
/*  f0919a4:	0fc16805 */ 	jal	func0f05abdc
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
/*  f0919e4:	0fc16805 */ 	jal	func0f05abdc
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
/*  f091a14:	0fc24466 */ 	jal	func0f092b50
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

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f093508
/*  f093508:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f09350c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f093510:	3c158009 */ 	lui	$s5,%hi(g_Is4Mb)
/*  f093514:	26b50af0 */ 	addiu	$s5,$s5,%lo(g_Is4Mb)
/*  f093518:	92a30000 */ 	lbu	$v1,0x0($s5)
/*  f09351c:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f093520:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f093524:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f093528:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f09352c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f093530:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f093534:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f093538:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f09353c:	00009825 */ 	or	$s3,$zero,$zero
/*  f093540:	16c30003 */ 	bne	$s6,$v1,.L0f093550
/*  f093544:	00008825 */ 	or	$s1,$zero,$zero
/*  f093548:	10000002 */ 	b	.L0f093554
/*  f09354c:	2402001e */ 	addiu	$v0,$zero,0x1e
.L0f093550:
/*  f093550:	24020028 */ 	addiu	$v0,$zero,0x28
.L0f093554:
/*  f093554:	18400020 */ 	blez	$v0,.L0f0935d8
/*  f093558:	00118100 */ 	sll	$s0,$s1,0x4
/*  f09355c:	02118023 */ 	subu	$s0,$s0,$s1
/*  f093560:	3c148007 */ 	lui	$s4,%hi(var8006ae3c)
/*  f093564:	3c128007 */ 	lui	$s2,%hi(g_AudioChannels)
/*  f093568:	2652ae10 */ 	addiu	$s2,$s2,%lo(g_AudioChannels)
/*  f09356c:	2694ae3c */ 	addiu	$s4,$s4,%lo(var8006ae3c)
/*  f093570:	001080c0 */ 	sll	$s0,$s0,0x3
/*  f093574:	8e4e0000 */ 	lw	$t6,0x0($s2)
.L0f093578:
/*  f093578:	020e1021 */ 	addu	$v0,$s0,$t6
/*  f09357c:	944f0030 */ 	lhu	$t7,0x30($v0)
/*  f093580:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f093584:	5700000b */ 	bnezl	$t8,.L0f0935b4
/*  f093588:	92a30000 */ 	lbu	$v1,0x0($s5)
/*  f09358c:	0fc24b01 */ 	jal	func0f092c04
/*  f093590:	02202025 */ 	or	$a0,$s1,$zero
/*  f093594:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f093598:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f09359c:	53200005 */ 	beqzl	$t9,.L0f0935b4
/*  f0935a0:	92a30000 */ 	lbu	$v1,0x0($s5)
/*  f0935a4:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f0935a8:	0fc24ad4 */ 	jal	func0f092b50
/*  f0935ac:	02082021 */ 	addu	$a0,$s0,$t0
/*  f0935b0:	92a30000 */ 	lbu	$v1,0x0($s5)
.L0f0935b4:
/*  f0935b4:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f0935b8:	26100078 */ 	addiu	$s0,$s0,0x78
/*  f0935bc:	16c30003 */ 	bne	$s6,$v1,.L0f0935cc
/*  f0935c0:	24020028 */ 	addiu	$v0,$zero,0x28
/*  f0935c4:	10000001 */ 	b	.L0f0935cc
/*  f0935c8:	2402001e */ 	addiu	$v0,$zero,0x1e
.L0f0935cc:
/*  f0935cc:	0222082a */ 	slt	$at,$s1,$v0
/*  f0935d0:	5420ffe9 */ 	bnezl	$at,.L0f093578
/*  f0935d4:	8e4e0000 */ 	lw	$t6,0x0($s2)
.L0f0935d8:
/*  f0935d8:	3c148007 */ 	lui	$s4,%hi(var8006ae3c)
/*  f0935dc:	2694ae3c */ 	addiu	$s4,$s4,%lo(var8006ae3c)
/*  f0935e0:	8e890000 */ 	lw	$t1,0x0($s4)
/*  f0935e4:	3c0a8007 */ 	lui	$t2,%hi(var8006ae58)
/*  f0935e8:	11200002 */ 	beqz	$t1,.L0f0935f4
/*  f0935ec:	00000000 */ 	nop
/*  f0935f0:	ae800000 */ 	sw	$zero,0x0($s4)
.L0f0935f4:
/*  f0935f4:	8d4aae58 */ 	lw	$t2,%lo(var8006ae58)($t2)
/*  f0935f8:	0153082a */ 	slt	$at,$t2,$s3
/*  f0935fc:	10200002 */ 	beqz	$at,.L0f093608
/*  f093600:	3c018007 */ 	lui	$at,%hi(var8006ae58)
/*  f093604:	ac33ae58 */ 	sw	$s3,%lo(var8006ae58)($at)
.L0f093608:
/*  f093608:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f09360c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f093610:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f093614:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f093618:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f09361c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f093620:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f093624:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f093628:	03e00008 */ 	jr	$ra
/*  f09362c:	27bd0038 */ 	addiu	$sp,$sp,0x38
);
#else
GLOBAL_ASM(
glabel func0f093508
/*  f091a3c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f091a40:	3c038009 */ 	lui	$v1,0x8009
/*  f091a44:	906330e0 */ 	lbu	$v1,0x30e0($v1)
/*  f091a48:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f091a4c:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f091a50:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f091a54:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f091a58:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f091a5c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f091a60:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f091a64:	00009025 */ 	or	$s2,$zero,$zero
/*  f091a68:	16830003 */ 	bne	$s4,$v1,.NB0f091a78
/*  f091a6c:	00008025 */ 	or	$s0,$zero,$zero
/*  f091a70:	10000002 */ 	beqz	$zero,.NB0f091a7c
/*  f091a74:	2402001e */ 	addiu	$v0,$zero,0x1e
.NB0f091a78:
/*  f091a78:	24020028 */ 	addiu	$v0,$zero,0x28
.NB0f091a7c:
/*  f091a7c:	1840001b */ 	blez	$v0,.NB0f091aec
/*  f091a80:	001088c0 */ 	sll	$s1,$s0,0x3
/*  f091a84:	02308823 */ 	subu	$s1,$s1,$s0
/*  f091a88:	00118880 */ 	sll	$s1,$s1,0x2
/*  f091a8c:	02308821 */ 	addu	$s1,$s1,$s0
/*  f091a90:	3c138007 */ 	lui	$s3,0x8007
/*  f091a94:	2673d520 */ 	addiu	$s3,$s3,-10976
/*  f091a98:	00118880 */ 	sll	$s1,$s1,0x2
/*  f091a9c:	8e6e0000 */ 	lw	$t6,0x0($s3)
.NB0f091aa0:
/*  f091aa0:	022e1021 */ 	addu	$v0,$s1,$t6
/*  f091aa4:	944f0030 */ 	lhu	$t7,0x30($v0)
/*  f091aa8:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f091aac:	57000007 */ 	bnezl	$t8,.NB0f091acc
/*  f091ab0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f091ab4:	0fc24495 */ 	jal	func0f092c04
/*  f091ab8:	02002025 */ 	or	$a0,$s0,$zero
/*  f091abc:	3c038009 */ 	lui	$v1,0x8009
/*  f091ac0:	906330e0 */ 	lbu	$v1,0x30e0($v1)
/*  f091ac4:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f091ac8:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0f091acc:
/*  f091acc:	16830003 */ 	bne	$s4,$v1,.NB0f091adc
/*  f091ad0:	26310074 */ 	addiu	$s1,$s1,0x74
/*  f091ad4:	10000002 */ 	beqz	$zero,.NB0f091ae0
/*  f091ad8:	2402001e */ 	addiu	$v0,$zero,0x1e
.NB0f091adc:
/*  f091adc:	24020028 */ 	addiu	$v0,$zero,0x28
.NB0f091ae0:
/*  f091ae0:	0202082a */ 	slt	$at,$s0,$v0
/*  f091ae4:	5420ffee */ 	bnezl	$at,.NB0f091aa0
/*  f091ae8:	8e6e0000 */ 	lw	$t6,0x0($s3)
.NB0f091aec:
/*  f091aec:	3c198007 */ 	lui	$t9,0x8007
/*  f091af0:	8f39d564 */ 	lw	$t9,-0x2a9c($t9)
/*  f091af4:	0332082a */ 	slt	$at,$t9,$s2
/*  f091af8:	10200002 */ 	beqz	$at,.NB0f091b04
/*  f091afc:	3c018007 */ 	lui	$at,0x8007
/*  f091b00:	ac32d564 */ 	sw	$s2,-0x2a9c($at)
.NB0f091b04:
/*  f091b04:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f091b08:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f091b0c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f091b10:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f091b14:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f091b18:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f091b1c:	03e00008 */ 	jr	$ra
/*  f091b20:	27bd0030 */ 	addiu	$sp,$sp,0x30
);
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f093630
/*  f093630:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f093634:	3c038009 */ 	lui	$v1,%hi(g_Is4Mb)
/*  f093638:	90630af0 */ 	lbu	$v1,%lo(g_Is4Mb)($v1)
/*  f09363c:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f093640:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f093644:	4485a000 */ 	mtc1	$a1,$f20
/*  f093648:	241e0001 */ 	addiu	$s8,$zero,0x1
/*  f09364c:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f093650:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f093654:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f093658:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f09365c:	0080b825 */ 	or	$s7,$a0,$zero
/*  f093660:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f093664:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f093668:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f09366c:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f093670:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f093674:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f093678:	17c30003 */ 	bne	$s8,$v1,.L0f093688
/*  f09367c:	00009025 */ 	or	$s2,$zero,$zero
/*  f093680:	10000002 */ 	b	.L0f09368c
/*  f093684:	2402001e */ 	addiu	$v0,$zero,0x1e
.L0f093688:
/*  f093688:	24020028 */ 	addiu	$v0,$zero,0x28
.L0f09368c:
/*  f09368c:	18400033 */ 	blez	$v0,.L0f09375c
/*  f093690:	00128100 */ 	sll	$s0,$s2,0x4
/*  f093694:	02128023 */ 	subu	$s0,$s0,$s2
/*  f093698:	3c158009 */ 	lui	$s5,%hi(g_AudioManager+0x18)
/*  f09369c:	3c138007 */ 	lui	$s3,%hi(g_AudioChannels)
/*  f0936a0:	2673ae10 */ 	addiu	$s3,$s3,%lo(g_AudioChannels)
/*  f0936a4:	26b515e0 */ 	addiu	$s5,$s5,%lo(g_AudioManager+0x18)
/*  f0936a8:	001080c0 */ 	sll	$s0,$s0,0x3
/*  f0936ac:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f0936b0:	8e6e0000 */ 	lw	$t6,0x0($s3)
.L0f0936b4:
/*  f0936b4:	01d01021 */ 	addu	$v0,$t6,$s0
/*  f0936b8:	944f0030 */ 	lhu	$t7,0x30($v0)
/*  f0936bc:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f0936c0:	5700001e */ 	bnezl	$t8,.L0f09373c
/*  f0936c4:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0936c8:	8c590050 */ 	lw	$t9,0x50($v0)
/*  f0936cc:	56f9001b */ 	bnel	$s7,$t9,.L0f09373c
/*  f0936d0:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0936d4:	1a800006 */ 	blez	$s4,.L0f0936f0
/*  f0936d8:	e4540044 */ 	swc1	$f20,0x44($v0)
/*  f0936dc:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f0936e0:	00144080 */ 	sll	$t0,$s4,0x2
/*  f0936e4:	01305021 */ 	addu	$t2,$t1,$s0
/*  f0936e8:	10000004 */ 	b	.L0f0936fc
/*  f0936ec:	ad480020 */ 	sw	$t0,0x20($t2)
.L0f0936f0:
/*  f0936f0:	8e6b0000 */ 	lw	$t3,0x0($s3)
/*  f0936f4:	01706021 */ 	addu	$t4,$t3,$s0
/*  f0936f8:	ad960020 */ 	sw	$s6,0x20($t4)
.L0f0936fc:
/*  f0936fc:	0c012230 */ 	jal	osGetThreadPri
/*  f093700:	00002025 */ 	or	$a0,$zero,$zero
/*  f093704:	00408825 */ 	or	$s1,$v0,$zero
/*  f093708:	0c012230 */ 	jal	osGetThreadPri
/*  f09370c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f093710:	00002025 */ 	or	$a0,$zero,$zero
/*  f093714:	0c01210c */ 	jal	osSetThreadPri
/*  f093718:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f09371c:	0fc24b01 */ 	jal	func0f092c04
/*  f093720:	02402025 */ 	or	$a0,$s2,$zero
/*  f093724:	00002025 */ 	or	$a0,$zero,$zero
/*  f093728:	0c01210c */ 	jal	osSetThreadPri
/*  f09372c:	02202825 */ 	or	$a1,$s1,$zero
/*  f093730:	3c038009 */ 	lui	$v1,%hi(g_Is4Mb)
/*  f093734:	90630af0 */ 	lbu	$v1,%lo(g_Is4Mb)($v1)
/*  f093738:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f09373c:
/*  f09373c:	17c30003 */ 	bne	$s8,$v1,.L0f09374c
/*  f093740:	26100078 */ 	addiu	$s0,$s0,0x78
/*  f093744:	10000002 */ 	b	.L0f093750
/*  f093748:	2402001e */ 	addiu	$v0,$zero,0x1e
.L0f09374c:
/*  f09374c:	24020028 */ 	addiu	$v0,$zero,0x28
.L0f093750:
/*  f093750:	0242082a */ 	slt	$at,$s2,$v0
/*  f093754:	5420ffd7 */ 	bnezl	$at,.L0f0936b4
/*  f093758:	8e6e0000 */ 	lw	$t6,0x0($s3)
.L0f09375c:
/*  f09375c:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f093760:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f093764:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f093768:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f09376c:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f093770:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f093774:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f093778:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f09377c:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f093780:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f093784:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f093788:	03e00008 */ 	jr	$ra
/*  f09378c:	27bd0048 */ 	addiu	$sp,$sp,0x48
);
#else
GLOBAL_ASM(
glabel func0f093630
/*  f091b24:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f091b28:	3c038009 */ 	lui	$v1,0x8009
/*  f091b2c:	906330e0 */ 	lbu	$v1,0x30e0($v1)
/*  f091b30:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f091b34:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f091b38:	4485a000 */ 	mtc1	$a1,$f20
/*  f091b3c:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f091b40:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f091b44:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f091b48:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f091b4c:	00c09825 */ 	or	$s3,$a2,$zero
/*  f091b50:	0080a825 */ 	or	$s5,$a0,$zero
/*  f091b54:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f091b58:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f091b5c:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f091b60:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f091b64:	16c30003 */ 	bne	$s6,$v1,.NB0f091b74
/*  f091b68:	00008825 */ 	or	$s1,$zero,$zero
/*  f091b6c:	10000002 */ 	beqz	$zero,.NB0f091b78
/*  f091b70:	2402001e */ 	addiu	$v0,$zero,0x1e
.NB0f091b74:
/*  f091b74:	24020028 */ 	addiu	$v0,$zero,0x28
.NB0f091b78:
/*  f091b78:	18400028 */ 	blez	$v0,.NB0f091c1c
/*  f091b7c:	001180c0 */ 	sll	$s0,$s1,0x3
/*  f091b80:	02118023 */ 	subu	$s0,$s0,$s1
/*  f091b84:	00108080 */ 	sll	$s0,$s0,0x2
/*  f091b88:	02118021 */ 	addu	$s0,$s0,$s1
/*  f091b8c:	3c128007 */ 	lui	$s2,0x8007
/*  f091b90:	2652d520 */ 	addiu	$s2,$s2,-10976
/*  f091b94:	00108080 */ 	sll	$s0,$s0,0x2
/*  f091b98:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f091b9c:	8e4e0000 */ 	lw	$t6,0x0($s2)
.NB0f091ba0:
/*  f091ba0:	01d01021 */ 	addu	$v0,$t6,$s0
/*  f091ba4:	944f0030 */ 	lhu	$t7,0x30($v0)
/*  f091ba8:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f091bac:	57000013 */ 	bnezl	$t8,.NB0f091bfc
/*  f091bb0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f091bb4:	8c590050 */ 	lw	$t9,0x50($v0)
/*  f091bb8:	56b90010 */ 	bnel	$s5,$t9,.NB0f091bfc
/*  f091bbc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f091bc0:	1a600006 */ 	blez	$s3,.NB0f091bdc
/*  f091bc4:	e4540044 */ 	swc1	$f20,0x44($v0)
/*  f091bc8:	8e490000 */ 	lw	$t1,0x0($s2)
/*  f091bcc:	00134080 */ 	sll	$t0,$s3,0x2
/*  f091bd0:	01305021 */ 	addu	$t2,$t1,$s0
/*  f091bd4:	10000004 */ 	beqz	$zero,.NB0f091be8
/*  f091bd8:	ad480020 */ 	sw	$t0,0x20($t2)
.NB0f091bdc:
/*  f091bdc:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f091be0:	01706021 */ 	addu	$t4,$t3,$s0
/*  f091be4:	ad940020 */ 	sw	$s4,0x20($t4)
.NB0f091be8:
/*  f091be8:	0fc24495 */ 	jal	func0f092c04
/*  f091bec:	02202025 */ 	or	$a0,$s1,$zero
/*  f091bf0:	3c038009 */ 	lui	$v1,0x8009
/*  f091bf4:	906330e0 */ 	lbu	$v1,0x30e0($v1)
/*  f091bf8:	26310001 */ 	addiu	$s1,$s1,0x1
.NB0f091bfc:
/*  f091bfc:	16c30003 */ 	bne	$s6,$v1,.NB0f091c0c
/*  f091c00:	26100074 */ 	addiu	$s0,$s0,0x74
/*  f091c04:	10000002 */ 	beqz	$zero,.NB0f091c10
/*  f091c08:	2402001e */ 	addiu	$v0,$zero,0x1e
.NB0f091c0c:
/*  f091c0c:	24020028 */ 	addiu	$v0,$zero,0x28
.NB0f091c10:
/*  f091c10:	0222082a */ 	slt	$at,$s1,$v0
/*  f091c14:	5420ffe2 */ 	bnezl	$at,.NB0f091ba0
/*  f091c18:	8e4e0000 */ 	lw	$t6,0x0($s2)
.NB0f091c1c:
/*  f091c1c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f091c20:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f091c24:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f091c28:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f091c2c:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f091c30:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f091c34:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f091c38:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f091c3c:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f091c40:	03e00008 */ 	jr	$ra
/*  f091c44:	27bd0040 */ 	addiu	$sp,$sp,0x40
);
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f093790
/*  f093790:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f093794:	3c038009 */ 	lui	$v1,%hi(g_Is4Mb)
/*  f093798:	90630af0 */ 	lbu	$v1,%lo(g_Is4Mb)($v1)
/*  f09379c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0937a0:	241e0001 */ 	addiu	$s8,$zero,0x1
/*  f0937a4:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0937a8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0937ac:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0937b0:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f0937b4:	0080b825 */ 	or	$s7,$a0,$zero
/*  f0937b8:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0937bc:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0937c0:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0937c4:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0937c8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0937cc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0937d0:	17c30003 */ 	bne	$s8,$v1,.L0f0937e0
/*  f0937d4:	00009825 */ 	or	$s3,$zero,$zero
/*  f0937d8:	10000002 */ 	b	.L0f0937e4
/*  f0937dc:	2402001e */ 	addiu	$v0,$zero,0x1e
.L0f0937e0:
/*  f0937e0:	24020028 */ 	addiu	$v0,$zero,0x28
.L0f0937e4:
/*  f0937e4:	18400035 */ 	blez	$v0,.L0f0938bc
/*  f0937e8:	00139100 */ 	sll	$s2,$s3,0x4
/*  f0937ec:	02539023 */ 	subu	$s2,$s2,$s3
/*  f0937f0:	3c168009 */ 	lui	$s6,%hi(g_AudioManager+0x18)
/*  f0937f4:	3c158007 */ 	lui	$s5,%hi(g_AudioChannels)
/*  f0937f8:	26b5ae10 */ 	addiu	$s5,$s5,%lo(g_AudioChannels)
/*  f0937fc:	26d615e0 */ 	addiu	$s6,$s6,%lo(g_AudioManager+0x18)
/*  f093800:	001290c0 */ 	sll	$s2,$s2,0x3
/*  f093804:	8eae0000 */ 	lw	$t6,0x0($s5)
.L0f093808:
/*  f093808:	01d21021 */ 	addu	$v0,$t6,$s2
/*  f09380c:	944f0030 */ 	lhu	$t7,0x30($v0)
/*  f093810:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f093814:	57000021 */ 	bnezl	$t8,.L0f09389c
/*  f093818:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f09381c:	8c590050 */ 	lw	$t9,0x50($v0)
/*  f093820:	2a810065 */ 	slti	$at,$s4,0x65
/*  f093824:	56f9001d */ 	bnel	$s7,$t9,.L0f09389c
/*  f093828:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f09382c:	54200003 */ 	bnezl	$at,.L0f09383c
/*  f093830:	00148bc0 */ 	sll	$s1,$s4,0xf
/*  f093834:	24140064 */ 	addiu	$s4,$zero,0x64
/*  f093838:	00148bc0 */ 	sll	$s1,$s4,0xf
.L0f09383c:
/*  f09383c:	02348823 */ 	subu	$s1,$s1,$s4
/*  f093840:	24010064 */ 	addiu	$at,$zero,0x64
/*  f093844:	0221001a */ 	div	$zero,$s1,$at
/*  f093848:	00008812 */ 	mflo	$s1
/*  f09384c:	00002025 */ 	or	$a0,$zero,$zero
/*  f093850:	0c012230 */ 	jal	osGetThreadPri
/*  f093854:	00000000 */ 	nop
/*  f093858:	00408025 */ 	or	$s0,$v0,$zero
/*  f09385c:	0c012230 */ 	jal	osGetThreadPri
/*  f093860:	02c02025 */ 	or	$a0,$s6,$zero
/*  f093864:	00002025 */ 	or	$a0,$zero,$zero
/*  f093868:	0c01210c */ 	jal	osSetThreadPri
/*  f09386c:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f093870:	8ea90000 */ 	lw	$t1,0x0($s5)
/*  f093874:	02602025 */ 	or	$a0,$s3,$zero
/*  f093878:	01325021 */ 	addu	$t2,$t1,$s2
/*  f09387c:	0fc24b01 */ 	jal	func0f092c04
/*  f093880:	a5510010 */ 	sh	$s1,0x10($t2)
/*  f093884:	00002025 */ 	or	$a0,$zero,$zero
/*  f093888:	0c01210c */ 	jal	osSetThreadPri
/*  f09388c:	02002825 */ 	or	$a1,$s0,$zero
/*  f093890:	3c038009 */ 	lui	$v1,%hi(g_Is4Mb)
/*  f093894:	90630af0 */ 	lbu	$v1,%lo(g_Is4Mb)($v1)
/*  f093898:	26730001 */ 	addiu	$s3,$s3,0x1
.L0f09389c:
/*  f09389c:	17c30003 */ 	bne	$s8,$v1,.L0f0938ac
/*  f0938a0:	26520078 */ 	addiu	$s2,$s2,0x78
/*  f0938a4:	10000002 */ 	b	.L0f0938b0
/*  f0938a8:	2402001e */ 	addiu	$v0,$zero,0x1e
.L0f0938ac:
/*  f0938ac:	24020028 */ 	addiu	$v0,$zero,0x28
.L0f0938b0:
/*  f0938b0:	0262082a */ 	slt	$at,$s3,$v0
/*  f0938b4:	5420ffd4 */ 	bnezl	$at,.L0f093808
/*  f0938b8:	8eae0000 */ 	lw	$t6,0x0($s5)
.L0f0938bc:
/*  f0938bc:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0938c0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0938c4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0938c8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0938cc:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0938d0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0938d4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0938d8:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0938dc:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0938e0:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0938e4:	03e00008 */ 	jr	$ra
/*  f0938e8:	27bd0040 */ 	addiu	$sp,$sp,0x40
);
#else
GLOBAL_ASM(
glabel func0f093790
/*  f091c48:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f091c4c:	3c038009 */ 	lui	$v1,0x8009
/*  f091c50:	906330e0 */ 	lbu	$v1,0x30e0($v1)
/*  f091c54:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f091c58:	24170001 */ 	addiu	$s7,$zero,0x1
/*  f091c5c:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f091c60:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f091c64:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f091c68:	0080a825 */ 	or	$s5,$a0,$zero
/*  f091c6c:	00a0b025 */ 	or	$s6,$a1,$zero
/*  f091c70:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f091c74:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f091c78:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f091c7c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f091c80:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f091c84:	16e30003 */ 	bne	$s7,$v1,.NB0f091c94
/*  f091c88:	00008025 */ 	or	$s0,$zero,$zero
/*  f091c8c:	10000002 */ 	beqz	$zero,.NB0f091c98
/*  f091c90:	2402001e */ 	addiu	$v0,$zero,0x1e
.NB0f091c94:
/*  f091c94:	24020028 */ 	addiu	$v0,$zero,0x28
.NB0f091c98:
/*  f091c98:	18400030 */ 	blez	$v0,.NB0f091d5c
/*  f091c9c:	001088c0 */ 	sll	$s1,$s0,0x3
/*  f091ca0:	02308823 */ 	subu	$s1,$s1,$s0
/*  f091ca4:	00118880 */ 	sll	$s1,$s1,0x2
/*  f091ca8:	02308821 */ 	addu	$s1,$s1,$s0
/*  f091cac:	3c128007 */ 	lui	$s2,0x8007
/*  f091cb0:	2652d520 */ 	addiu	$s2,$s2,-10976
/*  f091cb4:	00118880 */ 	sll	$s1,$s1,0x2
/*  f091cb8:	24140064 */ 	addiu	$s4,$zero,0x64
/*  f091cbc:	24137fff */ 	addiu	$s3,$zero,0x7fff
/*  f091cc0:	8e4e0000 */ 	lw	$t6,0x0($s2)
.NB0f091cc4:
/*  f091cc4:	01d11021 */ 	addu	$v0,$t6,$s1
/*  f091cc8:	944f0030 */ 	lhu	$t7,0x30($v0)
/*  f091ccc:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f091cd0:	5700001a */ 	bnezl	$t8,.NB0f091d3c
/*  f091cd4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f091cd8:	8c590050 */ 	lw	$t9,0x50($v0)
/*  f091cdc:	56b90017 */ 	bnel	$s5,$t9,.NB0f091d3c
/*  f091ce0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f091ce4:	02d30019 */ 	multu	$s6,$s3
/*  f091ce8:	02002025 */ 	or	$a0,$s0,$zero
/*  f091cec:	00004012 */ 	mflo	$t0
/*  f091cf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091cf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091cf8:	0114001a */ 	div	$zero,$t0,$s4
/*  f091cfc:	00004812 */ 	mflo	$t1
/*  f091d00:	a4490010 */ 	sh	$t1,0x10($v0)
/*  f091d04:	16800002 */ 	bnez	$s4,.NB0f091d10
/*  f091d08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091d0c:	0007000d */ 	break	0x7
.NB0f091d10:
/*  f091d10:	2401ffff */ 	addiu	$at,$zero,-1
/*  f091d14:	16810004 */ 	bne	$s4,$at,.NB0f091d28
/*  f091d18:	3c018000 */ 	lui	$at,0x8000
/*  f091d1c:	15010002 */ 	bne	$t0,$at,.NB0f091d28
/*  f091d20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091d24:	0006000d */ 	break	0x6
.NB0f091d28:
/*  f091d28:	0fc24495 */ 	jal	func0f092c04
/*  f091d2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091d30:	3c038009 */ 	lui	$v1,0x8009
/*  f091d34:	906330e0 */ 	lbu	$v1,0x30e0($v1)
/*  f091d38:	26100001 */ 	addiu	$s0,$s0,0x1
.NB0f091d3c:
/*  f091d3c:	16e30003 */ 	bne	$s7,$v1,.NB0f091d4c
/*  f091d40:	26310074 */ 	addiu	$s1,$s1,0x74
/*  f091d44:	10000002 */ 	beqz	$zero,.NB0f091d50
/*  f091d48:	2402001e */ 	addiu	$v0,$zero,0x1e
.NB0f091d4c:
/*  f091d4c:	24020028 */ 	addiu	$v0,$zero,0x28
.NB0f091d50:
/*  f091d50:	0202082a */ 	slt	$at,$s0,$v0
/*  f091d54:	5420ffdb */ 	bnezl	$at,.NB0f091cc4
/*  f091d58:	8e4e0000 */ 	lw	$t6,0x0($s2)
.NB0f091d5c:
/*  f091d5c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f091d60:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f091d64:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f091d68:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f091d6c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f091d70:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f091d74:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f091d78:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f091d7c:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f091d80:	03e00008 */ 	jr	$ra
/*  f091d84:	27bd0038 */ 	addiu	$sp,$sp,0x38
);
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f0938ec
/*  f0938ec:	3c098009 */ 	lui	$t1,%hi(g_Is4Mb)
/*  f0938f0:	91290af0 */ 	lbu	$t1,%lo(g_Is4Mb)($t1)
/*  f0938f4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f0938f8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0938fc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f093900:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f093904:	00808825 */ 	or	$s1,$a0,$zero
/*  f093908:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f09390c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f093910:	00003825 */ 	or	$a3,$zero,$zero
/*  f093914:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f093918:	15490003 */ 	bne	$t2,$t1,.L0f093928
/*  f09391c:	00002825 */ 	or	$a1,$zero,$zero
/*  f093920:	10000002 */ 	b	.L0f09392c
/*  f093924:	2402001e */ 	addiu	$v0,$zero,0x1e
.L0f093928:
/*  f093928:	24020028 */ 	addiu	$v0,$zero,0x28
.L0f09392c:
/*  f09392c:	18400026 */ 	blez	$v0,.L0f0939c8
/*  f093930:	00057100 */ 	sll	$t6,$a1,0x4
/*  f093934:	3c0f8007 */ 	lui	$t7,%hi(g_AudioChannels)
/*  f093938:	8defae10 */ 	lw	$t7,%lo(g_AudioChannels)($t7)
/*  f09393c:	01c57023 */ 	subu	$t6,$t6,$a1
/*  f093940:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f093944:	24080011 */ 	addiu	$t0,$zero,0x11
/*  f093948:	01cf2021 */ 	addu	$a0,$t6,$t7
/*  f09394c:	94980030 */ 	lhu	$t8,0x30($a0)
.L0f093950:
/*  f093950:	00801025 */ 	or	$v0,$a0,$zero
/*  f093954:	24840078 */ 	addiu	$a0,$a0,0x78
/*  f093958:	33190001 */ 	andi	$t9,$t8,0x1
/*  f09395c:	17200012 */ 	bnez	$t9,.L0f0939a8
/*  f093960:	00000000 */ 	nop
/*  f093964:	944b0032 */ 	lhu	$t3,0x32($v0)
/*  f093968:	316c0080 */ 	andi	$t4,$t3,0x80
/*  f09396c:	1580000e */ 	bnez	$t4,.L0f0939a8
/*  f093970:	00000000 */ 	nop
/*  f093974:	8c4d0050 */ 	lw	$t5,0x50($v0)
/*  f093978:	162d000b */ 	bne	$s1,$t5,.L0f0939a8
/*  f09397c:	00000000 */ 	nop
/*  f093980:	844e0028 */ 	lh	$t6,0x28($v0)
/*  f093984:	150e0008 */ 	bne	$t0,$t6,.L0f0939a8
/*  f093988:	00000000 */ 	nop
/*  f09398c:	8c430074 */ 	lw	$v1,0x74($v0)
/*  f093990:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f093994:	0066082b */ 	sltu	$at,$v1,$a2
/*  f093998:	10200003 */ 	beqz	$at,.L0f0939a8
/*  f09399c:	00000000 */ 	nop
/*  f0939a0:	00603025 */ 	or	$a2,$v1,$zero
/*  f0939a4:	00a08025 */ 	or	$s0,$a1,$zero
.L0f0939a8:
/*  f0939a8:	15490003 */ 	bne	$t2,$t1,.L0f0939b8
/*  f0939ac:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0939b0:	10000002 */ 	b	.L0f0939bc
/*  f0939b4:	2402001e */ 	addiu	$v0,$zero,0x1e
.L0f0939b8:
/*  f0939b8:	24020028 */ 	addiu	$v0,$zero,0x28
.L0f0939bc:
/*  f0939bc:	00a2082a */ 	slt	$at,$a1,$v0
/*  f0939c0:	5420ffe3 */ 	bnezl	$at,.L0f093950
/*  f0939c4:	94980030 */ 	lhu	$t8,0x30($a0)
.L0f0939c8:
/*  f0939c8:	28e10002 */ 	slti	$at,$a3,0x2
/*  f0939cc:	14200005 */ 	bnez	$at,.L0f0939e4
/*  f0939d0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0939d4:	52010004 */ 	beql	$s0,$at,.L0f0939e8
/*  f0939d8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0939dc:	0fc24aa6 */ 	jal	func0f092a98
/*  f0939e0:	02002025 */ 	or	$a0,$s0,$zero
.L0f0939e4:
/*  f0939e4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f0939e8:
/*  f0939e8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0939ec:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0939f0:	03e00008 */ 	jr	$ra
/*  f0939f4:	27bd0020 */ 	addiu	$sp,$sp,0x20
);
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f0939f8
.late_rodata
glabel var7f1ab744
.word 0x451c4000
glabel var7f1ab748
.word 0x453b8000
.text
/*  f0939f8:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f0939fc:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*  f093a00:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f093a04:	24010011 */ 	addiu	$at,$zero,0x11
/*  f093a08:	00808025 */ 	or	$s0,$a0,$zero
/*  f093a0c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f093a10:	afa500b4 */ 	sw	$a1,0xb4($sp)
/*  f093a14:	afa600b8 */ 	sw	$a2,0xb8($sp)
/*  f093a18:	15c10003 */ 	bne	$t6,$at,.L0f093a28
/*  f093a1c:	afa700bc */ 	sw	$a3,0xbc($sp)
/*  f093a20:	0fc24e3b */ 	jal	func0f0938ec
/*  f093a24:	00a02025 */ 	or	$a0,$a1,$zero
.L0f093a28:
/*  f093a28:	87af00ba */ 	lh	$t7,0xba($sp)
/*  f093a2c:	8fb800cc */ 	lw	$t8,0xcc($sp)
/*  f093a30:	1600002b */ 	bnez	$s0,.L0f093ae0
/*  f093a34:	a7af00ac */ 	sh	$t7,0xac($sp)
/*  f093a38:	24010010 */ 	addiu	$at,$zero,0x10
/*  f093a3c:	13010007 */ 	beq	$t8,$at,.L0f093a5c
/*  f093a40:	3c198006 */ 	lui	$t9,%hi(var8005ddd4)
/*  f093a44:	8f39ddd4 */ 	lw	$t9,%lo(var8005ddd4)($t9)
/*  f093a48:	2b21000d */ 	slti	$at,$t9,0xd
/*  f093a4c:	14200003 */ 	bnez	$at,.L0f093a5c
/*  f093a50:	00000000 */ 	nop
/*  f093a54:	10000175 */ 	b	.L0f09402c
/*  f093a58:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f093a5c:
/*  f093a5c:	3c068009 */ 	lui	$a2,%hi(g_Is4Mb)
/*  f093a60:	90c60af0 */ 	lbu	$a2,%lo(g_Is4Mb)($a2)
/*  f093a64:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f093a68:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f093a6c:	14e60003 */ 	bne	$a3,$a2,.L0f093a7c
/*  f093a70:	24020028 */ 	addiu	$v0,$zero,0x28
/*  f093a74:	10000001 */ 	b	.L0f093a7c
/*  f093a78:	2402001e */ 	addiu	$v0,$zero,0x1e
.L0f093a7c:
/*  f093a7c:	28410009 */ 	slti	$at,$v0,0x9
/*  f093a80:	14200017 */ 	bnez	$at,.L0f093ae0
/*  f093a84:	3c088007 */ 	lui	$t0,%hi(g_AudioChannels)
/*  f093a88:	8d08ae10 */ 	lw	$t0,%lo(g_AudioChannels)($t0)
/*  f093a8c:	00042900 */ 	sll	$a1,$a0,0x4
/*  f093a90:	00a42823 */ 	subu	$a1,$a1,$a0
/*  f093a94:	000528c0 */ 	sll	$a1,$a1,0x3
/*  f093a98:	01051821 */ 	addu	$v1,$t0,$a1
/*  f093a9c:	946a0030 */ 	lhu	$t2,0x30($v1)
.L0f093aa0:
/*  f093aa0:	24630078 */ 	addiu	$v1,$v1,0x78
/*  f093aa4:	24020028 */ 	addiu	$v0,$zero,0x28
/*  f093aa8:	314b0001 */ 	andi	$t3,$t2,0x1
/*  f093aac:	51600005 */ 	beqzl	$t3,.L0f093ac4
/*  f093ab0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f093ab4:	00a88021 */ 	addu	$s0,$a1,$t0
/*  f093ab8:	10000009 */ 	b	.L0f093ae0
/*  f093abc:	a604002e */ 	sh	$a0,0x2e($s0)
/*  f093ac0:	24840001 */ 	addiu	$a0,$a0,0x1
.L0f093ac4:
/*  f093ac4:	14e60003 */ 	bne	$a3,$a2,.L0f093ad4
/*  f093ac8:	24a50078 */ 	addiu	$a1,$a1,0x78
/*  f093acc:	10000001 */ 	b	.L0f093ad4
/*  f093ad0:	2402001e */ 	addiu	$v0,$zero,0x1e
.L0f093ad4:
/*  f093ad4:	0082082a */ 	slt	$at,$a0,$v0
/*  f093ad8:	5420fff1 */ 	bnezl	$at,.L0f093aa0
/*  f093adc:	946a0030 */ 	lhu	$t2,0x30($v1)
.L0f093ae0:
/*  f093ae0:	87ac00be */ 	lh	$t4,0xbe($sp)
/*  f093ae4:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f093ae8:	05800008 */ 	bltz	$t4,.L0f093b0c
/*  f093aec:	01802025 */ 	or	$a0,$t4,$zero
/*  f093af0:	0fc456ac */ 	jal	padUnpack
/*  f093af4:	27a60048 */ 	addiu	$a2,$sp,0x48
/*  f093af8:	8fad0090 */ 	lw	$t5,0x90($sp)
/*  f093afc:	27a90048 */ 	addiu	$t1,$sp,0x48
/*  f093b00:	afa900d0 */ 	sw	$t1,0xd0($sp)
/*  f093b04:	afa000b4 */ 	sw	$zero,0xb4($sp)
/*  f093b08:	afad00dc */ 	sw	$t5,0xdc($sp)
.L0f093b0c:
/*  f093b0c:	16000003 */ 	bnez	$s0,.L0f093b1c
/*  f093b10:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*  f093b14:	10000145 */ 	b	.L0f09402c
/*  f093b18:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f093b1c:
/*  f093b1c:	3c038007 */ 	lui	$v1,%hi(g_AudioPrevUuid)
/*  f093b20:	2463ae14 */ 	addiu	$v1,$v1,%lo(g_AudioPrevUuid)
/*  f093b24:	8c620000 */ 	lw	$v0,0x0($v1)
/*  f093b28:	44801000 */ 	mtc1	$zero,$f2
/*  f093b2c:	24190040 */ 	addiu	$t9,$zero,0x40
/*  f093b30:	2c41ffff */ 	sltiu	$at,$v0,-1
/*  f093b34:	10200003 */ 	beqz	$at,.L0f093b44
/*  f093b38:	244e0001 */ 	addiu	$t6,$v0,0x1
/*  f093b3c:	10000002 */ 	b	.L0f093b48
/*  f093b40:	ac6e0000 */ 	sw	$t6,0x0($v1)
.L0f093b44:
/*  f093b44:	ac600000 */ 	sw	$zero,0x0($v1)
.L0f093b48:
/*  f093b48:	97af00c6 */ 	lhu	$t7,0xc6($sp)
/*  f093b4c:	8fa200c0 */ 	lw	$v0,0xc0($sp)
/*  f093b50:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f093b54:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f093b58:	97b800ca */ 	lhu	$t8,0xca($sp)
/*  f093b5c:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f093b60:	a6070006 */ 	sh	$a3,0x6($s0)
/*  f093b64:	a6070008 */ 	sh	$a3,0x8($s0)
/*  f093b68:	a607000e */ 	sh	$a3,0xe($s0)
/*  f093b6c:	10470003 */ 	beq	$v0,$a3,.L0f093b7c
/*  f093b70:	a6180032 */ 	sh	$t8,0x32($s0)
/*  f093b74:	10000002 */ 	b	.L0f093b80
/*  f093b78:	a6020004 */ 	sh	$v0,0x4($s0)
.L0f093b7c:
/*  f093b7c:	a6070004 */ 	sh	$a3,0x4($s0)
.L0f093b80:
/*  f093b80:	c7a000d4 */ 	lwc1	$f0,0xd4($sp)
/*  f093b84:	240a7fff */ 	addiu	$t2,$zero,0x7fff
/*  f093b88:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f093b8c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f093b90:	a619000a */ 	sh	$t9,0xa($s0)
/*  f093b94:	a600000c */ 	sh	$zero,0xc($s0)
/*  f093b98:	a60a0010 */ 	sh	$t2,0x10($s0)
/*  f093b9c:	45000003 */ 	bc1f	.L0f093bac
/*  f093ba0:	a20b001a */ 	sb	$t3,0x1a($s0)
/*  f093ba4:	10000005 */ 	b	.L0f093bbc
/*  f093ba8:	e6000044 */ 	swc1	$f0,0x44($s0)
.L0f093bac:
/*  f093bac:	3c01bf80 */ 	lui	$at,0xbf80
/*  f093bb0:	44812000 */ 	mtc1	$at,$f4
/*  f093bb4:	00000000 */ 	nop
/*  f093bb8:	e6040044 */ 	swc1	$f4,0x44($s0)
.L0f093bbc:
/*  f093bbc:	c7a000e0 */ 	lwc1	$f0,0xe0($sp)
/*  f093bc0:	c6060044 */ 	lwc1	$f6,0x44($s0)
/*  f093bc4:	ae070020 */ 	sw	$a3,0x20($s0)
/*  f093bc8:	ae07001c */ 	sw	$a3,0x1c($s0)
/*  f093bcc:	e6060048 */ 	swc1	$f6,0x48($s0)
/*  f093bd0:	87ac00be */ 	lh	$t4,0xbe($sp)
/*  f093bd4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f093bd8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f093bdc:	a60c0024 */ 	sh	$t4,0x24($s0)
/*  f093be0:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f093be4:	44814000 */ 	mtc1	$at,$f8
/*  f093be8:	ae0d0050 */ 	sw	$t5,0x50($s0)
/*  f093bec:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*  f093bf0:	a6020012 */ 	sh	$v0,0x12($s0)
/*  f093bf4:	e6080040 */ 	swc1	$f8,0x40($s0)
/*  f093bf8:	45000003 */ 	bc1f	.L0f093c08
/*  f093bfc:	a60e0028 */ 	sh	$t6,0x28($s0)
/*  f093c00:	10000005 */ 	b	.L0f093c18
/*  f093c04:	e6000034 */ 	swc1	$f0,0x34($s0)
.L0f093c08:
/*  f093c08:	3c0143c8 */ 	lui	$at,0x43c8
/*  f093c0c:	44815000 */ 	mtc1	$at,$f10
/*  f093c10:	00000000 */ 	nop
/*  f093c14:	e60a0034 */ 	swc1	$f10,0x34($s0)
.L0f093c18:
/*  f093c18:	c7a000e4 */ 	lwc1	$f0,0xe4($sp)
/*  f093c1c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f093c20:	00000000 */ 	nop
/*  f093c24:	45000003 */ 	bc1f	.L0f093c34
/*  f093c28:	00000000 */ 	nop
/*  f093c2c:	10000004 */ 	b	.L0f093c40
/*  f093c30:	e6000038 */ 	swc1	$f0,0x38($s0)
.L0f093c34:
/*  f093c34:	3c017f1b */ 	lui	$at,%hi(var7f1ab744)
/*  f093c38:	c430b744 */ 	lwc1	$f16,%lo(var7f1ab744)($at)
/*  f093c3c:	e6100038 */ 	swc1	$f16,0x38($s0)
.L0f093c40:
/*  f093c40:	c7a000e8 */ 	lwc1	$f0,0xe8($sp)
/*  f093c44:	4600103c */ 	c.lt.s	$f2,$f0
/*  f093c48:	00000000 */ 	nop
/*  f093c4c:	45000003 */ 	bc1f	.L0f093c5c
/*  f093c50:	00000000 */ 	nop
/*  f093c54:	10000004 */ 	b	.L0f093c68
/*  f093c58:	e600003c */ 	swc1	$f0,0x3c($s0)
.L0f093c5c:
/*  f093c5c:	3c017f1b */ 	lui	$at,%hi(var7f1ab748)
/*  f093c60:	c432b748 */ 	lwc1	$f18,%lo(var7f1ab748)($at)
/*  f093c64:	e612003c */ 	swc1	$f18,0x3c($s0)
.L0f093c68:
/*  f093c68:	a6000018 */ 	sh	$zero,0x18($s0)
/*  f093c6c:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f093c70:	ae0f0074 */ 	sw	$t7,0x74($s0)
/*  f093c74:	8fb800ac */ 	lw	$t8,0xac($sp)
/*  f093c78:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f093c7c:	53200065 */ 	beqzl	$t9,.L0f093e14
/*  f093c80:	860c0018 */ 	lh	$t4,0x18($s0)
/*  f093c84:	97a400ac */ 	lhu	$a0,0xac($sp)
/*  f093c88:	3c0c8006 */ 	lui	$t4,%hi(g_AudioRussMappings)
/*  f093c8c:	258cdde4 */ 	addiu	$t4,$t4,%lo(g_AudioRussMappings)
/*  f093c90:	308a7fff */ 	andi	$t2,$a0,0x7fff
/*  f093c94:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f093c98:	016c1021 */ 	addu	$v0,$t3,$t4
/*  f093c9c:	94450002 */ 	lhu	$a1,0x2($v0)
/*  f093ca0:	3c0e8006 */ 	lui	$t6,%hi(g_AudioConfigs)
/*  f093ca4:	25cee4d8 */ 	addiu	$t6,$t6,%lo(g_AudioConfigs)
/*  f093ca8:	00056940 */ 	sll	$t5,$a1,0x5
/*  f093cac:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f093cb0:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f093cb4:	84480000 */ 	lh	$t0,0x0($v0)
/*  f093cb8:	24010064 */ 	addiu	$at,$zero,0x64
/*  f093cbc:	e6040034 */ 	swc1	$f4,0x34($s0)
/*  f093cc0:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f093cc4:	e6060038 */ 	swc1	$f6,0x38($s0)
/*  f093cc8:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f093ccc:	e608003c */ 	swc1	$f8,0x3c($s0)
/*  f093cd0:	8c6f0018 */ 	lw	$t7,0x18($v1)
/*  f093cd4:	a60f0018 */ 	sh	$t7,0x18($s0)
/*  f093cd8:	8c660010 */ 	lw	$a2,0x10($v1)
/*  f093cdc:	10c10007 */ 	beq	$a2,$at,.L0f093cfc
/*  f093ce0:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f093ce4:	0306c021 */ 	addu	$t8,$t8,$a2
/*  f093ce8:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f093cec:	0306c021 */ 	addu	$t8,$t8,$a2
/*  f093cf0:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f093cf4:	0306c023 */ 	subu	$t8,$t8,$a2
/*  f093cf8:	a6180010 */ 	sh	$t8,0x10($s0)
.L0f093cfc:
/*  f093cfc:	c460000c */ 	lwc1	$f0,0xc($v1)
/*  f093d00:	4600103c */ 	c.lt.s	$f2,$f0
/*  f093d04:	00000000 */ 	nop
/*  f093d08:	45020003 */ 	bc1fl	.L0f093d18
/*  f093d0c:	8c620014 */ 	lw	$v0,0x14($v1)
/*  f093d10:	e6000044 */ 	swc1	$f0,0x44($s0)
/*  f093d14:	8c620014 */ 	lw	$v0,0x14($v1)
.L0f093d18:
/*  f093d18:	50470006 */ 	beql	$v0,$a3,.L0f093d34
/*  f093d1c:	8c62001c */ 	lw	$v0,0x1c($v1)
/*  f093d20:	96190030 */ 	lhu	$t9,0x30($s0)
/*  f093d24:	a602000a */ 	sh	$v0,0xa($s0)
/*  f093d28:	372a0020 */ 	ori	$t2,$t9,0x20
/*  f093d2c:	a60a0030 */ 	sh	$t2,0x30($s0)
/*  f093d30:	8c62001c */ 	lw	$v0,0x1c($v1)
.L0f093d34:
/*  f093d34:	304b0001 */ 	andi	$t3,$v0,0x1
/*  f093d38:	51600006 */ 	beqzl	$t3,.L0f093d54
/*  f093d3c:	304e0004 */ 	andi	$t6,$v0,0x4
/*  f093d40:	960c0030 */ 	lhu	$t4,0x30($s0)
/*  f093d44:	358d0800 */ 	ori	$t5,$t4,0x800
/*  f093d48:	a60d0030 */ 	sh	$t5,0x30($s0)
/*  f093d4c:	8c62001c */ 	lw	$v0,0x1c($v1)
/*  f093d50:	304e0004 */ 	andi	$t6,$v0,0x4
.L0f093d54:
/*  f093d54:	51c00006 */ 	beqzl	$t6,.L0f093d70
/*  f093d58:	30590008 */ 	andi	$t9,$v0,0x8
/*  f093d5c:	960f0032 */ 	lhu	$t7,0x32($s0)
/*  f093d60:	35f80001 */ 	ori	$t8,$t7,0x1
/*  f093d64:	a6180032 */ 	sh	$t8,0x32($s0)
/*  f093d68:	8c62001c */ 	lw	$v0,0x1c($v1)
/*  f093d6c:	30590008 */ 	andi	$t9,$v0,0x8
.L0f093d70:
/*  f093d70:	5320000b */ 	beqzl	$t9,.L0f093da0
/*  f093d74:	304e0010 */ 	andi	$t6,$v0,0x10
/*  f093d78:	860a0004 */ 	lh	$t2,0x4($s0)
/*  f093d7c:	54ea0004 */ 	bnel	$a3,$t2,.L0f093d90
/*  f093d80:	960c0030 */ 	lhu	$t4,0x30($s0)
/*  f093d84:	860b0010 */ 	lh	$t3,0x10($s0)
/*  f093d88:	a60b0004 */ 	sh	$t3,0x4($s0)
/*  f093d8c:	960c0030 */ 	lhu	$t4,0x30($s0)
.L0f093d90:
/*  f093d90:	358d8000 */ 	ori	$t5,$t4,0x8000
/*  f093d94:	a60d0030 */ 	sh	$t5,0x30($s0)
/*  f093d98:	8c62001c */ 	lw	$v0,0x1c($v1)
/*  f093d9c:	304e0010 */ 	andi	$t6,$v0,0x10
.L0f093da0:
/*  f093da0:	51c00006 */ 	beqzl	$t6,.L0f093dbc
/*  f093da4:	30590020 */ 	andi	$t9,$v0,0x20
/*  f093da8:	960f0032 */ 	lhu	$t7,0x32($s0)
/*  f093dac:	35f80020 */ 	ori	$t8,$t7,0x20
/*  f093db0:	a6180032 */ 	sh	$t8,0x32($s0)
/*  f093db4:	8c62001c */ 	lw	$v0,0x1c($v1)
/*  f093db8:	30590020 */ 	andi	$t9,$v0,0x20
.L0f093dbc:
/*  f093dbc:	53200006 */ 	beqzl	$t9,.L0f093dd8
/*  f093dc0:	304c0040 */ 	andi	$t4,$v0,0x40
/*  f093dc4:	960a0032 */ 	lhu	$t2,0x32($s0)
/*  f093dc8:	354b0010 */ 	ori	$t3,$t2,0x10
/*  f093dcc:	a60b0032 */ 	sh	$t3,0x32($s0)
/*  f093dd0:	8c62001c */ 	lw	$v0,0x1c($v1)
/*  f093dd4:	304c0040 */ 	andi	$t4,$v0,0x40
.L0f093dd8:
/*  f093dd8:	51800005 */ 	beqzl	$t4,.L0f093df0
/*  f093ddc:	960f0030 */ 	lhu	$t7,0x30($s0)
/*  f093de0:	960d0032 */ 	lhu	$t5,0x32($s0)
/*  f093de4:	35ae0040 */ 	ori	$t6,$t5,0x40
/*  f093de8:	a60e0032 */ 	sh	$t6,0x32($s0)
/*  f093dec:	960f0030 */ 	lhu	$t7,0x30($s0)
.L0f093df0:
/*  f093df0:	35f80040 */ 	ori	$t8,$t7,0x40
/*  f093df4:	a6180030 */ 	sh	$t8,0x30($s0)
/*  f093df8:	a7a800ac */ 	sh	$t0,0xac($sp)
/*  f093dfc:	93b900ac */ 	lbu	$t9,0xac($sp)
/*  f093e00:	332aff7f */ 	andi	$t2,$t9,0xff7f
/*  f093e04:	a3aa00ac */ 	sb	$t2,0xac($sp)
/*  f093e08:	87ab00ac */ 	lh	$t3,0xac($sp)
/*  f093e0c:	a7ab00ba */ 	sh	$t3,0xba($sp)
/*  f093e10:	860c0018 */ 	lh	$t4,0x18($s0)
.L0f093e14:
/*  f093e14:	51800005 */ 	beqzl	$t4,.L0f093e2c
/*  f093e18:	87af00ac */ 	lh	$t7,0xac($sp)
/*  f093e1c:	960d0030 */ 	lhu	$t5,0x30($s0)
/*  f093e20:	35ae0002 */ 	ori	$t6,$t5,0x2
/*  f093e24:	a60e0030 */ 	sh	$t6,0x30($s0)
/*  f093e28:	87af00ac */ 	lh	$t7,0xac($sp)
.L0f093e2c:
/*  f093e2c:	a60f0026 */ 	sh	$t7,0x26($s0)
/*  f093e30:	97b800ac */ 	lhu	$t8,0xac($sp)
/*  f093e34:	331907ff */ 	andi	$t9,$t8,0x7ff
/*  f093e38:	a619002c */ 	sh	$t9,0x2c($s0)
/*  f093e3c:	8604002c */ 	lh	$a0,0x2c($s0)
/*  f093e40:	0c004103 */ 	jal	sndIsFiltered
/*  f093e44:	afa900d0 */ 	sw	$t1,0xd0($sp)
/*  f093e48:	8fa300dc */ 	lw	$v1,0xdc($sp)
/*  f093e4c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f093e50:	10400004 */ 	beqz	$v0,.L0f093e64
/*  f093e54:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*  f093e58:	960a0032 */ 	lhu	$t2,0x32($s0)
/*  f093e5c:	354b0020 */ 	ori	$t3,$t2,0x20
/*  f093e60:	a60b0032 */ 	sh	$t3,0x32($s0)
.L0f093e64:
/*  f093e64:	8fac00ac */ 	lw	$t4,0xac($sp)
/*  f093e68:	000c6840 */ 	sll	$t5,$t4,0x1
/*  f093e6c:	000d7782 */ 	srl	$t6,$t5,0x1e
/*  f093e70:	11c00004 */ 	beqz	$t6,.L0f093e84
/*  f093e74:	00000000 */ 	nop
/*  f093e78:	960f0032 */ 	lhu	$t7,0x32($s0)
/*  f093e7c:	35f80010 */ 	ori	$t8,$t7,0x10
/*  f093e80:	a6180032 */ 	sh	$t8,0x32($s0)
.L0f093e84:
/*  f093e84:	5120000b */ 	beqzl	$t1,.L0f093eb4
/*  f093e88:	ae000054 */ 	sw	$zero,0x54($s0)
/*  f093e8c:	c52a0000 */ 	lwc1	$f10,0x0($t1)
/*  f093e90:	26190058 */ 	addiu	$t9,$s0,0x58
/*  f093e94:	e60a0058 */ 	swc1	$f10,0x58($s0)
/*  f093e98:	c5300004 */ 	lwc1	$f16,0x4($t1)
/*  f093e9c:	e610005c */ 	swc1	$f16,0x5c($s0)
/*  f093ea0:	c5320008 */ 	lwc1	$f18,0x8($t1)
/*  f093ea4:	ae190054 */ 	sw	$t9,0x54($s0)
/*  f093ea8:	10000002 */ 	b	.L0f093eb4
/*  f093eac:	e6120060 */ 	swc1	$f18,0x60($s0)
/*  f093eb0:	ae000054 */ 	sw	$zero,0x54($s0)
.L0f093eb4:
/*  f093eb4:	8fa600d8 */ 	lw	$a2,0xd8($sp)
/*  f093eb8:	10c00011 */ 	beqz	$a2,.L0f093f00
/*  f093ebc:	00000000 */ 	nop
/*  f093ec0:	84ca0000 */ 	lh	$t2,0x0($a2)
/*  f093ec4:	00002825 */ 	or	$a1,$zero,$zero
/*  f093ec8:	02001825 */ 	or	$v1,$s0,$zero
/*  f093ecc:	10ea0008 */ 	beq	$a3,$t2,.L0f093ef0
/*  f093ed0:	00c01025 */ 	or	$v0,$a2,$zero
/*  f093ed4:	84c40000 */ 	lh	$a0,0x0($a2)
.L0f093ed8:
/*  f093ed8:	a4640064 */ 	sh	$a0,0x64($v1)
/*  f093edc:	84440002 */ 	lh	$a0,0x2($v0)
/*  f093ee0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f093ee4:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f093ee8:	14e4fffb */ 	bne	$a3,$a0,.L0f093ed8
/*  f093eec:	24420002 */ 	addiu	$v0,$v0,0x2
.L0f093ef0:
/*  f093ef0:	00055840 */ 	sll	$t3,$a1,0x1
/*  f093ef4:	020b6021 */ 	addu	$t4,$s0,$t3
/*  f093ef8:	10000007 */ 	b	.L0f093f18
/*  f093efc:	a5870064 */ 	sh	$a3,0x64($t4)
.L0f093f00:
/*  f093f00:	50670005 */ 	beql	$v1,$a3,.L0f093f18
/*  f093f04:	a6070064 */ 	sh	$a3,0x64($s0)
/*  f093f08:	a6030064 */ 	sh	$v1,0x64($s0)
/*  f093f0c:	10000002 */ 	b	.L0f093f18
/*  f093f10:	a6070066 */ 	sh	$a3,0x66($s0)
/*  f093f14:	a6070064 */ 	sh	$a3,0x64($s0)
.L0f093f18:
/*  f093f18:	55200008 */ 	bnezl	$t1,.L0f093f3c
/*  f093f1c:	96180032 */ 	lhu	$t8,0x32($s0)
/*  f093f20:	8e0d0050 */ 	lw	$t5,0x50($s0)
/*  f093f24:	55a00005 */ 	bnezl	$t5,.L0f093f3c
/*  f093f28:	96180032 */ 	lhu	$t8,0x32($s0)
/*  f093f2c:	960e0032 */ 	lhu	$t6,0x32($s0)
/*  f093f30:	35cf0010 */ 	ori	$t7,$t6,0x10
/*  f093f34:	a60f0032 */ 	sh	$t7,0x32($s0)
/*  f093f38:	96180032 */ 	lhu	$t8,0x32($s0)
.L0f093f3c:
/*  f093f3c:	33190010 */ 	andi	$t9,$t8,0x10
/*  f093f40:	53200007 */ 	beqzl	$t9,.L0f093f60
/*  f093f44:	960c0030 */ 	lhu	$t4,0x30($s0)
/*  f093f48:	860a0004 */ 	lh	$t2,0x4($s0)
/*  f093f4c:	54ea0004 */ 	bnel	$a3,$t2,.L0f093f60
/*  f093f50:	960c0030 */ 	lhu	$t4,0x30($s0)
/*  f093f54:	860b0010 */ 	lh	$t3,0x10($s0)
/*  f093f58:	a60b0004 */ 	sh	$t3,0x4($s0)
/*  f093f5c:	960c0030 */ 	lhu	$t4,0x30($s0)
.L0f093f60:
/*  f093f60:	358d1000 */ 	ori	$t5,$t4,0x1000
/*  f093f64:	a60d0030 */ 	sh	$t5,0x30($s0)
/*  f093f68:	0c003ee8 */ 	jal	sndIsMp3
/*  f093f6c:	87a400ba */ 	lh	$a0,0xba($sp)
/*  f093f70:	10400014 */ 	beqz	$v0,.L0f093fc4
/*  f093f74:	00000000 */ 	nop
/*  f093f78:	960e0030 */ 	lhu	$t6,0x30($s0)
/*  f093f7c:	00002025 */ 	or	$a0,$zero,$zero
/*  f093f80:	35cf0010 */ 	ori	$t7,$t6,0x10
/*  f093f84:	0c012230 */ 	jal	osGetThreadPri
/*  f093f88:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f093f8c:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x18)
/*  f093f90:	afa200a8 */ 	sw	$v0,0xa8($sp)
/*  f093f94:	0c012230 */ 	jal	osGetThreadPri
/*  f093f98:	248415e0 */ 	addiu	$a0,$a0,%lo(g_AudioManager+0x18)
/*  f093f9c:	00002025 */ 	or	$a0,$zero,$zero
/*  f093fa0:	0c01210c */ 	jal	osSetThreadPri
/*  f093fa4:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f093fa8:	0fc24b01 */ 	jal	func0f092c04
/*  f093fac:	8604002e */ 	lh	$a0,0x2e($s0)
/*  f093fb0:	00002025 */ 	or	$a0,$zero,$zero
/*  f093fb4:	0c01210c */ 	jal	osSetThreadPri
/*  f093fb8:	8fa500a8 */ 	lw	$a1,0xa8($sp)
/*  f093fbc:	10000010 */ 	b	.L0f094000
/*  f093fc0:	96030030 */ 	lhu	$v1,0x30($s0)
.L0f093fc4:
/*  f093fc4:	0c012230 */ 	jal	osGetThreadPri
/*  f093fc8:	00002025 */ 	or	$a0,$zero,$zero
/*  f093fcc:	3c048009 */ 	lui	$a0,%hi(g_AudioManager+0x18)
/*  f093fd0:	afa200a8 */ 	sw	$v0,0xa8($sp)
/*  f093fd4:	0c012230 */ 	jal	osGetThreadPri
/*  f093fd8:	248415e0 */ 	addiu	$a0,$a0,%lo(g_AudioManager+0x18)
/*  f093fdc:	00002025 */ 	or	$a0,$zero,$zero
/*  f093fe0:	0c01210c */ 	jal	osSetThreadPri
/*  f093fe4:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f093fe8:	0fc24b01 */ 	jal	func0f092c04
/*  f093fec:	8604002e */ 	lh	$a0,0x2e($s0)
/*  f093ff0:	00002025 */ 	or	$a0,$zero,$zero
/*  f093ff4:	0c01210c */ 	jal	osSetThreadPri
/*  f093ff8:	8fa500a8 */ 	lw	$a1,0xa8($sp)
/*  f093ffc:	96030030 */ 	lhu	$v1,0x30($s0)
.L0f094000:
/*  f094000:	30780400 */ 	andi	$t8,$v1,0x400
/*  f094004:	13000006 */ 	beqz	$t8,.L0f094020
/*  f094008:	3079fbff */ 	andi	$t9,$v1,0xfbff
/*  f09400c:	960a0032 */ 	lhu	$t2,0x32($s0)
/*  f094010:	a6190030 */ 	sh	$t9,0x30($s0)
/*  f094014:	3323ffff */ 	andi	$v1,$t9,0xffff
/*  f094018:	354b0010 */ 	ori	$t3,$t2,0x10
/*  f09401c:	a60b0032 */ 	sh	$t3,0x32($s0)
.L0f094020:
/*  f094020:	306cefff */ 	andi	$t4,$v1,0xefff
/*  f094024:	a60c0030 */ 	sh	$t4,0x30($s0)
/*  f094028:	8602002e */ 	lh	$v0,0x2e($s0)
.L0f09402c:
/*  f09402c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f094030:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f094034:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
/*  f094038:	03e00008 */ 	jr	$ra
/*  f09403c:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func0f0939f8
.late_rodata
glabel var7f1ab744
.word 0x451c4000
glabel var7f1ab748
.word 0x453b8000
glabel var7f1a5a9cnb
.word 0x4b18967f
.text
/*  f091d88:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f091d8c:	afa600c0 */ 	sw	$a2,0xc0($sp)
/*  f091d90:	87ae00c2 */ 	lh	$t6,0xc2($sp)
/*  f091d94:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f091d98:	00808025 */ 	or	$s0,$a0,$zero
/*  f091d9c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f091da0:	afa500bc */ 	sw	$a1,0xbc($sp)
/*  f091da4:	afa700c4 */ 	sw	$a3,0xc4($sp)
/*  f091da8:	240cffff */ 	addiu	$t4,$zero,-1
/*  f091dac:	00004025 */ 	or	$t0,$zero,$zero
/*  f091db0:	1480002b */ 	bnez	$a0,.NB0f091e60
/*  f091db4:	a7ae00b4 */ 	sh	$t6,0xb4($sp)
/*  f091db8:	3c068009 */ 	lui	$a2,0x8009
/*  f091dbc:	90c630e0 */ 	lbu	$a2,0x30e0($a2)
/*  f091dc0:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f091dc4:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f091dc8:	14e60003 */ 	bne	$a3,$a2,.NB0f091dd8
/*  f091dcc:	24020028 */ 	addiu	$v0,$zero,0x28
/*  f091dd0:	10000001 */ 	beqz	$zero,.NB0f091dd8
/*  f091dd4:	2402001e */ 	addiu	$v0,$zero,0x1e
.NB0f091dd8:
/*  f091dd8:	28410009 */ 	slti	$at,$v0,0x9
/*  f091ddc:	14200020 */ 	bnez	$at,.NB0f091e60
/*  f091de0:	3c0b8007 */ 	lui	$t3,0x8007
/*  f091de4:	000520c0 */ 	sll	$a0,$a1,0x3
/*  f091de8:	00852023 */ 	subu	$a0,$a0,$a1
/*  f091dec:	8d6bd520 */ 	lw	$t3,-0x2ae0($t3)
/*  f091df0:	00042080 */ 	sll	$a0,$a0,0x2
/*  f091df4:	00852021 */ 	addu	$a0,$a0,$a1
/*  f091df8:	00042080 */ 	sll	$a0,$a0,0x2
/*  f091dfc:	8faa00d4 */ 	lw	$t2,0xd4($sp)
/*  f091e00:	24090010 */ 	addiu	$t1,$zero,0x10
/*  f091e04:	01641821 */ 	addu	$v1,$t3,$a0
/*  f091e08:	946f0030 */ 	lhu	$t7,0x30($v1)
.NB0f091e0c:
/*  f091e0c:	24630074 */ 	addiu	$v1,$v1,0x74
/*  f091e10:	24020028 */ 	addiu	$v0,$zero,0x28
/*  f091e14:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f091e18:	13000007 */ 	beqz	$t8,.NB0f091e38
/*  f091e1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091e20:	11490003 */ 	beq	$t2,$t1,.NB0f091e30
/*  f091e24:	008b8021 */ 	addu	$s0,$a0,$t3
/*  f091e28:	1000000d */ 	beqz	$zero,.NB0f091e60
/*  f091e2c:	a605002e */ 	sh	$a1,0x2e($s0)
.NB0f091e30:
/*  f091e30:	1000000b */ 	beqz	$zero,.NB0f091e60
/*  f091e34:	00a06025 */ 	or	$t4,$a1,$zero
.NB0f091e38:
/*  f091e38:	15490002 */ 	bne	$t2,$t1,.NB0f091e44
/*  f091e3c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f091e40:	25080001 */ 	addiu	$t0,$t0,0x1
.NB0f091e44:
/*  f091e44:	14e60003 */ 	bne	$a3,$a2,.NB0f091e54
/*  f091e48:	24840074 */ 	addiu	$a0,$a0,0x74
/*  f091e4c:	10000001 */ 	beqz	$zero,.NB0f091e54
/*  f091e50:	2402001e */ 	addiu	$v0,$zero,0x1e
.NB0f091e54:
/*  f091e54:	00a2082a */ 	slt	$at,$a1,$v0
/*  f091e58:	5420ffec */ 	bnezl	$at,.NB0f091e0c
/*  f091e5c:	946f0030 */ 	lhu	$t7,0x30($v1)
.NB0f091e60:
/*  f091e60:	8faa00d4 */ 	lw	$t2,0xd4($sp)
/*  f091e64:	24090010 */ 	addiu	$t1,$zero,0x10
/*  f091e68:	2901000c */ 	slti	$at,$t0,0xc
/*  f091e6c:	55490013 */ 	bnel	$t2,$t1,.NB0f091ebc
/*  f091e70:	87ae00c6 */ 	lh	$t6,0xc6($sp)
/*  f091e74:	14200003 */ 	bnez	$at,.NB0f091e84
/*  f091e78:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f091e7c:	10000129 */ 	beqz	$zero,.NB0f092324
/*  f091e80:	2402ffff */ 	addiu	$v0,$zero,-1
.NB0f091e84:
/*  f091e84:	1187000a */ 	beq	$t4,$a3,.NB0f091eb0
/*  f091e88:	000cc8c0 */ 	sll	$t9,$t4,0x3
/*  f091e8c:	032cc823 */ 	subu	$t9,$t9,$t4
/*  f091e90:	3c0d8007 */ 	lui	$t5,0x8007
/*  f091e94:	8dadd520 */ 	lw	$t5,-0x2ae0($t5)
/*  f091e98:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f091e9c:	032cc821 */ 	addu	$t9,$t9,$t4
/*  f091ea0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f091ea4:	032d8021 */ 	addu	$s0,$t9,$t5
/*  f091ea8:	10000003 */ 	beqz	$zero,.NB0f091eb8
/*  f091eac:	a60c002e */ 	sh	$t4,0x2e($s0)
.NB0f091eb0:
/*  f091eb0:	1000011c */ 	beqz	$zero,.NB0f092324
/*  f091eb4:	2402ffff */ 	addiu	$v0,$zero,-1
.NB0f091eb8:
/*  f091eb8:	87ae00c6 */ 	lh	$t6,0xc6($sp)
.NB0f091ebc:
/*  f091ebc:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f091ec0:	24050042 */ 	addiu	$a1,$zero,0x42
/*  f091ec4:	05c0000a */ 	bltz	$t6,.NB0f091ef0
/*  f091ec8:	01c02025 */ 	or	$a0,$t6,$zero
/*  f091ecc:	0fc43fc4 */ 	jal	padUnpack
/*  f091ed0:	27a6004c */ 	addiu	$a2,$sp,0x4c
/*  f091ed4:	8fab0094 */ 	lw	$t3,0x94($sp)
/*  f091ed8:	27a9004c */ 	addiu	$t1,$sp,0x4c
/*  f091edc:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f091ee0:	8faa00d4 */ 	lw	$t2,0xd4($sp)
/*  f091ee4:	afa900d8 */ 	sw	$t1,0xd8($sp)
/*  f091ee8:	afa000bc */ 	sw	$zero,0xbc($sp)
/*  f091eec:	afab00e4 */ 	sw	$t3,0xe4($sp)
.NB0f091ef0:
/*  f091ef0:	8fa900d8 */ 	lw	$t1,0xd8($sp)
/*  f091ef4:	16000003 */ 	bnez	$s0,.NB0f091f04
/*  f091ef8:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f091efc:	10000109 */ 	beqz	$zero,.NB0f092324
/*  f091f00:	2402ffff */ 	addiu	$v0,$zero,-1
.NB0f091f04:
/*  f091f04:	97af00ce */ 	lhu	$t7,0xce($sp)
/*  f091f08:	8fa200c8 */ 	lw	$v0,0xc8($sp)
/*  f091f0c:	44801000 */ 	mtc1	$zero,$f2
/*  f091f10:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f091f14:	97b800d2 */ 	lhu	$t8,0xd2($sp)
/*  f091f18:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f091f1c:	a6070006 */ 	sh	$a3,0x6($s0)
/*  f091f20:	a6070008 */ 	sh	$a3,0x8($s0)
/*  f091f24:	a607000e */ 	sh	$a3,0xe($s0)
/*  f091f28:	10470003 */ 	beq	$v0,$a3,.NB0f091f38
/*  f091f2c:	a6180032 */ 	sh	$t8,0x32($s0)
/*  f091f30:	10000002 */ 	beqz	$zero,.NB0f091f3c
/*  f091f34:	a6020004 */ 	sh	$v0,0x4($s0)
.NB0f091f38:
/*  f091f38:	a6070004 */ 	sh	$a3,0x4($s0)
.NB0f091f3c:
/*  f091f3c:	c7a000dc */ 	lwc1	$f0,0xdc($sp)
/*  f091f40:	24190040 */ 	addiu	$t9,$zero,0x40
/*  f091f44:	240d7fff */ 	addiu	$t5,$zero,0x7fff
/*  f091f48:	4600103c */ 	c.lt.s	$f2,$f0
/*  f091f4c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f091f50:	a619000a */ 	sh	$t9,0xa($s0)
/*  f091f54:	a600000c */ 	sh	$zero,0xc($s0)
/*  f091f58:	a60d0010 */ 	sh	$t5,0x10($s0)
/*  f091f5c:	45000003 */ 	bc1f	.NB0f091f6c
/*  f091f60:	a20e001a */ 	sb	$t6,0x1a($s0)
/*  f091f64:	10000005 */ 	beqz	$zero,.NB0f091f7c
/*  f091f68:	e6000044 */ 	swc1	$f0,0x44($s0)
.NB0f091f6c:
/*  f091f6c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f091f70:	44812000 */ 	mtc1	$at,$f4
/*  f091f74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091f78:	e6040044 */ 	swc1	$f4,0x44($s0)
.NB0f091f7c:
/*  f091f7c:	c7a000e8 */ 	lwc1	$f0,0xe8($sp)
/*  f091f80:	c6060044 */ 	lwc1	$f6,0x44($s0)
/*  f091f84:	ae070020 */ 	sw	$a3,0x20($s0)
/*  f091f88:	ae07001c */ 	sw	$a3,0x1c($s0)
/*  f091f8c:	e6060048 */ 	swc1	$f6,0x48($s0)
/*  f091f90:	87af00c6 */ 	lh	$t7,0xc6($sp)
/*  f091f94:	4600103c */ 	c.lt.s	$f2,$f0
/*  f091f98:	3c01bf80 */ 	lui	$at,0xbf80
/*  f091f9c:	a60f0024 */ 	sh	$t7,0x24($s0)
/*  f091fa0:	8fb800bc */ 	lw	$t8,0xbc($sp)
/*  f091fa4:	44814000 */ 	mtc1	$at,$f8
/*  f091fa8:	a60a0028 */ 	sh	$t2,0x28($s0)
/*  f091fac:	a6020012 */ 	sh	$v0,0x12($s0)
/*  f091fb0:	ae180050 */ 	sw	$t8,0x50($s0)
/*  f091fb4:	45000003 */ 	bc1f	.NB0f091fc4
/*  f091fb8:	e6080040 */ 	swc1	$f8,0x40($s0)
/*  f091fbc:	10000005 */ 	beqz	$zero,.NB0f091fd4
/*  f091fc0:	e6000034 */ 	swc1	$f0,0x34($s0)
.NB0f091fc4:
/*  f091fc4:	3c0143c8 */ 	lui	$at,0x43c8
/*  f091fc8:	44815000 */ 	mtc1	$at,$f10
/*  f091fcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091fd0:	e60a0034 */ 	swc1	$f10,0x34($s0)
.NB0f091fd4:
/*  f091fd4:	c7a000ec */ 	lwc1	$f0,0xec($sp)
/*  f091fd8:	3c017f1a */ 	lui	$at,0x7f1a
/*  f091fdc:	4600103c */ 	c.lt.s	$f2,$f0
/*  f091fe0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091fe4:	45000003 */ 	bc1f	.NB0f091ff4
/*  f091fe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f091fec:	10000003 */ 	beqz	$zero,.NB0f091ffc
/*  f091ff0:	e6000038 */ 	swc1	$f0,0x38($s0)
.NB0f091ff4:
/*  f091ff4:	c4305a94 */ 	lwc1	$f16,0x5a94($at)
/*  f091ff8:	e6100038 */ 	swc1	$f16,0x38($s0)
.NB0f091ffc:
/*  f091ffc:	c7a000f0 */ 	lwc1	$f0,0xf0($sp)
/*  f092000:	3c017f1a */ 	lui	$at,0x7f1a
/*  f092004:	4600103c */ 	c.lt.s	$f2,$f0
/*  f092008:	00000000 */ 	sll	$zero,$zero,0x0
/*  f09200c:	45000003 */ 	bc1f	.NB0f09201c
/*  f092010:	00000000 */ 	sll	$zero,$zero,0x0
/*  f092014:	10000003 */ 	beqz	$zero,.NB0f092024
/*  f092018:	e600003c */ 	swc1	$f0,0x3c($s0)
.NB0f09201c:
/*  f09201c:	c4325a98 */ 	lwc1	$f18,0x5a98($at)
/*  f092020:	e612003c */ 	swc1	$f18,0x3c($s0)
.NB0f092024:
/*  f092024:	a6000018 */ 	sh	$zero,0x18($s0)
/*  f092028:	8fb900b4 */ 	lw	$t9,0xb4($sp)
/*  f09202c:	97a400b4 */ 	lhu	$a0,0xb4($sp)
/*  f092030:	3c188006 */ 	lui	$t8,0x8006
/*  f092034:	00196fc2 */ 	srl	$t5,$t9,0x1f
/*  f092038:	11a0005a */ 	beqz	$t5,.NB0f0921a4
/*  f09203c:	308e7fff */ 	andi	$t6,$a0,0x7fff
/*  f092040:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f092044:	2718f6f8 */ 	addiu	$t8,$t8,-2312
/*  f092048:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f09204c:	94450002 */ 	lhu	$a1,0x2($v0)
/*  f092050:	3c0d8006 */ 	lui	$t5,0x8006
/*  f092054:	25adfdd0 */ 	addiu	$t5,$t5,-560
/*  f092058:	0005c940 */ 	sll	$t9,$a1,0x5
/*  f09205c:	032d1821 */ 	addu	$v1,$t9,$t5
/*  f092060:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f092064:	84480000 */ 	lh	$t0,0x0($v0)
/*  f092068:	24010064 */ 	addiu	$at,$zero,0x64
/*  f09206c:	e6040034 */ 	swc1	$f4,0x34($s0)
/*  f092070:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f092074:	e6060038 */ 	swc1	$f6,0x38($s0)
/*  f092078:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f09207c:	e608003c */ 	swc1	$f8,0x3c($s0)
/*  f092080:	8c6e0018 */ 	lw	$t6,0x18($v1)
/*  f092084:	a60e0018 */ 	sh	$t6,0x18($s0)
/*  f092088:	8c660010 */ 	lw	$a2,0x10($v1)
/*  f09208c:	10c10007 */ 	beq	$a2,$at,.NB0f0920ac
/*  f092090:	00067880 */ 	sll	$t7,$a2,0x2
/*  f092094:	01e67821 */ 	addu	$t7,$t7,$a2
/*  f092098:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f09209c:	01e67821 */ 	addu	$t7,$t7,$a2
/*  f0920a0:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0920a4:	01e67823 */ 	subu	$t7,$t7,$a2
/*  f0920a8:	a60f0010 */ 	sh	$t7,0x10($s0)
.NB0f0920ac:
/*  f0920ac:	c460000c */ 	lwc1	$f0,0xc($v1)
/*  f0920b0:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0920b4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0920b8:	45020003 */ 	bc1fl	.NB0f0920c8
/*  f0920bc:	8c620014 */ 	lw	$v0,0x14($v1)
/*  f0920c0:	e6000044 */ 	swc1	$f0,0x44($s0)
/*  f0920c4:	8c620014 */ 	lw	$v0,0x14($v1)
.NB0f0920c8:
/*  f0920c8:	50470006 */ 	beql	$v0,$a3,.NB0f0920e4
/*  f0920cc:	8c62001c */ 	lw	$v0,0x1c($v1)
/*  f0920d0:	96180030 */ 	lhu	$t8,0x30($s0)
/*  f0920d4:	a602000a */ 	sh	$v0,0xa($s0)
/*  f0920d8:	37190020 */ 	ori	$t9,$t8,0x20
/*  f0920dc:	a6190030 */ 	sh	$t9,0x30($s0)
/*  f0920e0:	8c62001c */ 	lw	$v0,0x1c($v1)
.NB0f0920e4:
/*  f0920e4:	304d0001 */ 	andi	$t5,$v0,0x1
/*  f0920e8:	51a00006 */ 	beqzl	$t5,.NB0f092104
/*  f0920ec:	30580004 */ 	andi	$t8,$v0,0x4
/*  f0920f0:	960e0030 */ 	lhu	$t6,0x30($s0)
/*  f0920f4:	35cf0800 */ 	ori	$t7,$t6,0x800
/*  f0920f8:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f0920fc:	8c62001c */ 	lw	$v0,0x1c($v1)
/*  f092100:	30580004 */ 	andi	$t8,$v0,0x4
.NB0f092104:
/*  f092104:	53000006 */ 	beqzl	$t8,.NB0f092120
/*  f092108:	304e0008 */ 	andi	$t6,$v0,0x8
/*  f09210c:	96190032 */ 	lhu	$t9,0x32($s0)
/*  f092110:	372d0001 */ 	ori	$t5,$t9,0x1
/*  f092114:	a60d0032 */ 	sh	$t5,0x32($s0)
/*  f092118:	8c62001c */ 	lw	$v0,0x1c($v1)
/*  f09211c:	304e0008 */ 	andi	$t6,$v0,0x8
.NB0f092120:
/*  f092120:	51c0000b */ 	beqzl	$t6,.NB0f092150
/*  f092124:	304e0010 */ 	andi	$t6,$v0,0x10
/*  f092128:	860f0004 */ 	lh	$t7,0x4($s0)
/*  f09212c:	54ef0004 */ 	bnel	$a3,$t7,.NB0f092140
/*  f092130:	96190030 */ 	lhu	$t9,0x30($s0)
/*  f092134:	86180010 */ 	lh	$t8,0x10($s0)
/*  f092138:	a6180004 */ 	sh	$t8,0x4($s0)
/*  f09213c:	96190030 */ 	lhu	$t9,0x30($s0)
.NB0f092140:
/*  f092140:	372d8000 */ 	ori	$t5,$t9,0x8000
/*  f092144:	a60d0030 */ 	sh	$t5,0x30($s0)
/*  f092148:	8c62001c */ 	lw	$v0,0x1c($v1)
/*  f09214c:	304e0010 */ 	andi	$t6,$v0,0x10
.NB0f092150:
/*  f092150:	51c00006 */ 	beqzl	$t6,.NB0f09216c
/*  f092154:	30590020 */ 	andi	$t9,$v0,0x20
/*  f092158:	960f0032 */ 	lhu	$t7,0x32($s0)
/*  f09215c:	35f80020 */ 	ori	$t8,$t7,0x20
/*  f092160:	a6180032 */ 	sh	$t8,0x32($s0)
/*  f092164:	8c62001c */ 	lw	$v0,0x1c($v1)
/*  f092168:	30590020 */ 	andi	$t9,$v0,0x20
.NB0f09216c:
/*  f09216c:	53200005 */ 	beqzl	$t9,.NB0f092184
/*  f092170:	960f0030 */ 	lhu	$t7,0x30($s0)
/*  f092174:	960d0032 */ 	lhu	$t5,0x32($s0)
/*  f092178:	35ae0010 */ 	ori	$t6,$t5,0x10
/*  f09217c:	a60e0032 */ 	sh	$t6,0x32($s0)
/*  f092180:	960f0030 */ 	lhu	$t7,0x30($s0)
.NB0f092184:
/*  f092184:	35f80040 */ 	ori	$t8,$t7,0x40
/*  f092188:	a6180030 */ 	sh	$t8,0x30($s0)
/*  f09218c:	a7a800b4 */ 	sh	$t0,0xb4($sp)
/*  f092190:	93b900b4 */ 	lbu	$t9,0xb4($sp)
/*  f092194:	332dff7f */ 	andi	$t5,$t9,0xff7f
/*  f092198:	a3ad00b4 */ 	sb	$t5,0xb4($sp)
/*  f09219c:	87ae00b4 */ 	lh	$t6,0xb4($sp)
/*  f0921a0:	a7ae00c2 */ 	sh	$t6,0xc2($sp)
.NB0f0921a4:
/*  f0921a4:	87af00b4 */ 	lh	$t7,0xb4($sp)
/*  f0921a8:	a60f0026 */ 	sh	$t7,0x26($s0)
/*  f0921ac:	97b800b4 */ 	lhu	$t8,0xb4($sp)
/*  f0921b0:	331907ff */ 	andi	$t9,$t8,0x7ff
/*  f0921b4:	a619002c */ 	sh	$t9,0x2c($s0)
/*  f0921b8:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f0921bc:	000d7040 */ 	sll	$t6,$t5,0x1
/*  f0921c0:	000e7f82 */ 	srl	$t7,$t6,0x1e
/*  f0921c4:	51e00005 */ 	beqzl	$t7,.NB0f0921dc
/*  f0921c8:	960d0032 */ 	lhu	$t5,0x32($s0)
/*  f0921cc:	96180032 */ 	lhu	$t8,0x32($s0)
/*  f0921d0:	37190010 */ 	ori	$t9,$t8,0x10
/*  f0921d4:	a6190032 */ 	sh	$t9,0x32($s0)
/*  f0921d8:	960d0032 */ 	lhu	$t5,0x32($s0)
.NB0f0921dc:
/*  f0921dc:	31ae0010 */ 	andi	$t6,$t5,0x10
/*  f0921e0:	11c00006 */ 	beqz	$t6,.NB0f0921fc
/*  f0921e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0921e8:	860f0004 */ 	lh	$t7,0x4($s0)
/*  f0921ec:	14ef0003 */ 	bne	$a3,$t7,.NB0f0921fc
/*  f0921f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0921f4:	86180010 */ 	lh	$t8,0x10($s0)
/*  f0921f8:	a6180004 */ 	sh	$t8,0x4($s0)
.NB0f0921fc:
/*  f0921fc:	5120000b */ 	beqzl	$t1,.NB0f09222c
/*  f092200:	ae000054 */ 	sw	$zero,0x54($s0)
/*  f092204:	c52a0000 */ 	lwc1	$f10,0x0($t1)
/*  f092208:	26190058 */ 	addiu	$t9,$s0,0x58
/*  f09220c:	e60a0058 */ 	swc1	$f10,0x58($s0)
/*  f092210:	c5300004 */ 	lwc1	$f16,0x4($t1)
/*  f092214:	e610005c */ 	swc1	$f16,0x5c($s0)
/*  f092218:	c5320008 */ 	lwc1	$f18,0x8($t1)
/*  f09221c:	ae190054 */ 	sw	$t9,0x54($s0)
/*  f092220:	10000002 */ 	beqz	$zero,.NB0f09222c
/*  f092224:	e6120060 */ 	swc1	$f18,0x60($s0)
/*  f092228:	ae000054 */ 	sw	$zero,0x54($s0)
.NB0f09222c:
/*  f09222c:	8fa600e0 */ 	lw	$a2,0xe0($sp)
/*  f092230:	10c00011 */ 	beqz	$a2,.NB0f092278
/*  f092234:	00000000 */ 	sll	$zero,$zero,0x0
/*  f092238:	84cd0000 */ 	lh	$t5,0x0($a2)
/*  f09223c:	00002825 */ 	or	$a1,$zero,$zero
/*  f092240:	02001825 */ 	or	$v1,$s0,$zero
/*  f092244:	10ed0008 */ 	beq	$a3,$t5,.NB0f092268
/*  f092248:	00c01025 */ 	or	$v0,$a2,$zero
/*  f09224c:	84c40000 */ 	lh	$a0,0x0($a2)
.NB0f092250:
/*  f092250:	a4640064 */ 	sh	$a0,0x64($v1)
/*  f092254:	84440002 */ 	lh	$a0,0x2($v0)
/*  f092258:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f09225c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f092260:	14e4fffb */ 	bne	$a3,$a0,.NB0f092250
/*  f092264:	24420002 */ 	addiu	$v0,$v0,0x2
.NB0f092268:
/*  f092268:	00057040 */ 	sll	$t6,$a1,0x1
/*  f09226c:	020e7821 */ 	addu	$t7,$s0,$t6
/*  f092270:	10000007 */ 	beqz	$zero,.NB0f092290
/*  f092274:	a5e70064 */ 	sh	$a3,0x64($t7)
.NB0f092278:
/*  f092278:	51670005 */ 	beql	$t3,$a3,.NB0f092290
/*  f09227c:	a6070064 */ 	sh	$a3,0x64($s0)
/*  f092280:	a60b0064 */ 	sh	$t3,0x64($s0)
/*  f092284:	10000002 */ 	beqz	$zero,.NB0f092290
/*  f092288:	a6070066 */ 	sh	$a3,0x66($s0)
/*  f09228c:	a6070064 */ 	sh	$a3,0x64($s0)
.NB0f092290:
/*  f092290:	96180030 */ 	lhu	$t8,0x30($s0)
/*  f092294:	37191000 */ 	ori	$t9,$t8,0x1000
/*  f092298:	a6190030 */ 	sh	$t9,0x30($s0)
/*  f09229c:	0c00400e */ 	jal	sndIsMp3
/*  f0922a0:	87a400c2 */ 	lh	$a0,0xc2($sp)
/*  f0922a4:	10400008 */ 	beqz	$v0,.NB0f0922c8
/*  f0922a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0922ac:	960d0030 */ 	lhu	$t5,0x30($s0)
/*  f0922b0:	8604002e */ 	lh	$a0,0x2e($s0)
/*  f0922b4:	35ae0010 */ 	ori	$t6,$t5,0x10
/*  f0922b8:	0fc24495 */ 	jal	func0f092c04
/*  f0922bc:	a60e0030 */ 	sh	$t6,0x30($s0)
/*  f0922c0:	10000010 */ 	beqz	$zero,.NB0f092304
/*  f0922c4:	96020030 */ 	lhu	$v0,0x30($s0)
.NB0f0922c8:
/*  f0922c8:	0c012724 */ 	jal	osGetThreadPri
/*  f0922cc:	00002025 */ 	or	$a0,$zero,$zero
/*  f0922d0:	3c048009 */ 	lui	$a0,0x8009
/*  f0922d4:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f0922d8:	0c012724 */ 	jal	osGetThreadPri
/*  f0922dc:	24843bd0 */ 	addiu	$a0,$a0,0x3bd0
/*  f0922e0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0922e4:	0c012600 */ 	jal	osSetThreadPri
/*  f0922e8:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f0922ec:	0fc24495 */ 	jal	func0f092c04
/*  f0922f0:	8604002e */ 	lh	$a0,0x2e($s0)
/*  f0922f4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0922f8:	0c012600 */ 	jal	osSetThreadPri
/*  f0922fc:	8fa500b0 */ 	lw	$a1,0xb0($sp)
/*  f092300:	96020030 */ 	lhu	$v0,0x30($s0)
.NB0f092304:
/*  f092304:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f092308:	304f0400 */ 	andi	$t7,$v0,0x400
/*  f09230c:	11e00003 */ 	beqz	$t7,.NB0f09231c
/*  f092310:	3059efff */ 	andi	$t9,$v0,0xefff
/*  f092314:	10000002 */ 	beqz	$zero,.NB0f092320
/*  f092318:	a6180030 */ 	sh	$t8,0x30($s0)
.NB0f09231c:
/*  f09231c:	a6190030 */ 	sh	$t9,0x30($s0)
.NB0f092320:
/*  f092320:	8602002e */ 	lh	$v0,0x2e($s0)
.NB0f092324:
/*  f092324:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f092328:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f09232c:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
/*  f092330:	03e00008 */ 	jr	$ra
/*  f092334:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

// Mismatch: Two beq operators are swapped in this expression:
//     g_AudioConfigs[confignum].unk14 != -1
//s16 func0f0939f8(
//		struct audiochannel *channel,
//		struct prop *prop,
//		s16 soundnum,
//		s16 padnum,
//		s32 arg4,
//		u16 flags,
//		u16 flags2,
//		s32 arg7,
//		struct coord *pos,
//		f32 arg9,
//		s16 *rooms,
//		s32 room,
//		f32 arg12,
//		f32 arg13,
//		f32 arg14)
//{
//	union soundnumhack spac;
//	OSPri prevpri;
//	u32 stack[3];
//	struct pad pad;
//	s32 i;
//	s32 j;
//
//	if (arg7 == 0x11) {
//		func0f0938ec(prop);
//	}
//
//	spac.packed = soundnum;
//
//	if (channel == NULL) {
//		if (arg7 != 16 && var8005ddd4 > 12) {
//			return -1;
//		}
//
//		for (i = 8; i < (IS4MB() ? 30 : 40); i++) {
//			if (g_AudioChannels[i].flags & AUDIOCHANNELFLAG_IDLE) {
//				channel = &g_AudioChannels[i];
//				channel->channelnum = i;
//				break;
//			}
//		}
//	}
//
//	if (padnum >= 0) {
//		padUnpack(padnum, PADFIELD_POS | PADFIELD_ROOM, &pad);
//		pos = &pad.pos;
//		room = pad.room;
//		prop = NULL;
//	}
//
//	if (channel == NULL) {
//		return -1;
//	}
//
//	if (g_AudioPrevUuid < 0xffffffff) {
//		g_AudioPrevUuid++;
//	} else {
//		g_AudioPrevUuid = 0;
//	}
//
//	channel->flags = flags;
//	channel->flags2 = flags2;
//	channel->audiohandle = NULL;
//	channel->unk06 = -1;
//	channel->unk08 = -1;
//	channel->unk0e = -1;
//	channel->soundnum04 = (arg4 != -1) ? arg4 : -1;
//	channel->unk0a = 64;
//	channel->unk0c = 0;
//	channel->unk10 = 0x7fff;
//	channel->unk1a = 1;
//	channel->unk44 = (arg9 > 0) ? arg9 : -1;
//	channel->unk48 = channel->unk44;
//	channel->unk20 = -1;
//	channel->unk1c = -1;
//	channel->padnum = padnum;
//	channel->prop = prop;
//	channel->unk28 = arg7;
//	channel->unk12 = arg4;
//	channel->unk40 = -1;
//	channel->unk34 = (arg12 > 0) ? arg12 : 400;
//	channel->unk38 = (arg13 > 0) ? arg13 : 2500;
//	channel->unk3c = (arg14 > 0) ? arg14 : 3000;
//	channel->unk18 = 0;
//	channel->uuid = g_AudioPrevUuid;
//
//	if (spac.bits2.isruss) {
//		s32 id = spac.bits.id;
//		s32 confignum = g_AudioRussMappings[id].audioconfig_index;
//		s32 newid = g_AudioRussMappings[id].soundnum;
//
//		channel->unk34 = g_AudioConfigs[confignum].unk00;
//		channel->unk38 = g_AudioConfigs[confignum].unk04;
//		channel->unk3c = g_AudioConfigs[confignum].unk08;
//		channel->unk18 = g_AudioConfigs[confignum].unk18;
//
//		if (g_AudioConfigs[confignum].unk10 != 100) {
//			channel->unk10 = g_AudioConfigs[confignum].unk10 * 327;
//		}
//
//		if (g_AudioConfigs[confignum].unk0c > 0) {
//			channel->unk44 = g_AudioConfigs[confignum].unk0c;
//		}
//
//		if (g_AudioConfigs[confignum].unk14 != -1) {
//			channel->unk0a = g_AudioConfigs[confignum].unk14;
//			channel->flags |= AUDIOCHANNELFLAG_0020;
//		}
//
//		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_01) {
//			channel->flags |= AUDIOCHANNELFLAG_0800;
//		}
//
//		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_04) {
//			channel->flags2 |= AUDIOCHANNELFLAG2_0001;
//		}
//
//		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_08) {
//			if (channel->soundnum04 == -1) {
//				channel->soundnum04 = channel->unk10;
//			}
//
//			channel->flags |= AUDIOCHANNELFLAG_8000;
//		}
//
//		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_10) {
//			channel->flags2 |= AUDIOCHANNELFLAG2_0020;
//		}
//
//		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_20) {
//			channel->flags2 |= AUDIOCHANNELFLAG2_0010;
//		}
//
//		if (g_AudioConfigs[confignum].flags & AUDIOCONFIGFLAG_40) {
//			channel->flags2 |= AUDIOCHANNELFLAG2_0040;
//		}
//
//		channel->flags |= AUDIOCHANNELFLAG_0040;
//
//		spac.packed = newid;
//		spac.bits2.isruss = false;
//		soundnum = spac.packed;
//	}
//
//	if (channel->unk18) {
//		channel->flags |= AUDIOCHANNELFLAG_0002;
//	}
//
//	channel->soundnum26 = spac.packed;
//	channel->unk2c = spac.bits3.id;
//
//	if (sndIsFiltered(channel->unk2c)) {
//		channel->flags2 |= AUDIOCHANNELFLAG2_0020;
//	}
//
//	if (spac.bits2.unk02) {
//		channel->flags2 |= AUDIOCHANNELFLAG2_0010;
//	}
//
//	if (pos) {
//		channel->pos.x = pos->x;
//		channel->pos.y = pos->y;
//		channel->pos.z = pos->z;
//		channel->posptr = &channel->pos;
//	} else {
//		channel->posptr = NULL;
//	}
//
//	if (rooms) {
//		// @dangerous: Array overflow will occur if rooms has more than 8 elements
//		for (j = 0; rooms[j] != -1; j++) {
//			channel->rooms[j] = rooms[j];
//		}
//
//		channel->rooms[j] = -1;
//	} else if (room != -1) {
//		channel->rooms[0] = room;
//		channel->rooms[1] = -1;
//	} else {
//		channel->rooms[0] = -1;
//	}
//
//	if (!pos && !channel->prop) {
//		channel->flags2 |= AUDIOCHANNELFLAG2_0010;
//	}
//
//	if ((channel->flags2 & AUDIOCHANNELFLAG2_0010) && channel->soundnum04 == -1) {
//		channel->soundnum04 = channel->unk10;
//	}
//
//	channel->flags |= AUDIOCHANNELFLAG_1000;
//
//	if (sndIsMp3(soundnum)) {
//		channel->flags |= AUDIOCHANNELFLAG_0010;
//
//		prevpri = osGetThreadPri(0);
//		osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
//		func0f092c04(channel->channelnum);
//		osSetThreadPri(0, prevpri);
//	} else {
//		prevpri = osGetThreadPri(0);
//		osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
//		func0f092c04(channel->channelnum);
//		osSetThreadPri(0, prevpri);
//	}
//
//	if (channel->flags & AUDIOCHANNELFLAG_0400) {
//		channel->flags &= ~AUDIOCHANNELFLAG_0400;
//		channel->flags2 |= AUDIOCHANNELFLAG2_0010;
//	}
//
//	channel->flags &= ~AUDIOCHANNELFLAG_1000;
//
//	return channel->channelnum;
//}

#if VERSION >= VERSION_NTSC_1_0
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
		}
	} else if (channelnum == 10) {
		retchannelnum = func0f0939f8(NULL, prop, soundnum, -1,
				(arg2 ? 0 : -1), arg5 | 0x0080, 0, arg4, 0, -1, 0, -1, -1, -1, -1);
#if VERSION >= VERSION_NTSC_1_0
	} else if (channelnum < 0 || channelnum >= 8 || channelnum == 9) {
		retchannelnum = func0f0939f8(NULL, prop, soundnum, -1,
			(arg2 ? 0 : -1), arg5, 0, arg4, 0, -1, 0, -1, -1, -1, -1);
#else
	} else if (channelnum == 9) {
		retchannelnum = func0f0939f8(NULL, prop, soundnum, -1,
			(arg2 ? 0 : -1), arg5, 0, arg4, 0, -1, 0, -1, -1, -1, -1);
	} else if (channelnum < 0 || channelnum >= 8) {
		retchannelnum = func0f0939f8(NULL, prop, soundnum, -1,
			(arg2 ? 0 : -1), arg5, 0, arg4, 0, -1, 0, -1, -1, -1, -1);
#endif
	} else {
		if ((g_AudioChannels[channelnum].flags & AUDIOCHANNELFLAG_IDLE) == 0) {
			func0f092a98(channelnum);
		}

		g_AudioChannels[channelnum].channelnum = channelnum;

		func0f0939f8(&g_AudioChannels[channelnum], prop, soundnum, -1,
			(arg2 ? 0 : -1), arg5, 0, arg4, 0, -1, 0, -1, -1, -1, -1);

		retchannelnum = channelnum;
	}

	return retchannelnum;
}
#else
GLOBAL_ASM(
glabel audioPlayFromProp
/*  f092338:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f09233c:	87ae0072 */ 	lh	$t6,0x72($sp)
/*  f092340:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f092344:	240a000b */ 	addiu	$t2,$zero,0xb
/*  f092348:	00808025 */ 	or	$s0,$a0,$zero
/*  f09234c:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f092350:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f092354:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f092358:	15ca0019 */ 	bne	$t6,$t2,.NB0f0923c0
/*  f09235c:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f092360:	048000a4 */ 	bltz	$a0,.NB0f0925f4
/*  f092364:	28810008 */ 	slti	$at,$a0,0x8
/*  f092368:	102000a2 */ 	beqz	$at,.NB0f0925f4
/*  f09236c:	3c098007 */ 	lui	$t1,0x8007
/*  f092370:	000418c0 */ 	sll	$v1,$a0,0x3
/*  f092374:	2529d520 */ 	addiu	$t1,$t1,-10976
/*  f092378:	00641823 */ 	subu	$v1,$v1,$a0
/*  f09237c:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f092380:	00031880 */ 	sll	$v1,$v1,0x2
/*  f092384:	87af0066 */ 	lh	$t7,0x66($sp)
/*  f092388:	00641821 */ 	addu	$v1,$v1,$a0
/*  f09238c:	00031880 */ 	sll	$v1,$v1,0x2
/*  f092390:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f092394:	a72f0026 */ 	sh	$t7,0x26($t9)
/*  f092398:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*  f09239c:	00804025 */ 	or	$t0,$a0,$zero
/*  f0923a0:	01636021 */ 	addu	$t4,$t3,$v1
/*  f0923a4:	a58a0028 */ 	sh	$t2,0x28($t4)
/*  f0923a8:	8d2d0000 */ 	lw	$t5,0x0($t1)
/*  f0923ac:	01a31021 */ 	addu	$v0,$t5,$v1
/*  f0923b0:	944e0030 */ 	lhu	$t6,0x30($v0)
/*  f0923b4:	31d8fffe */ 	andi	$t8,$t6,0xfffe
/*  f0923b8:	1000008e */ 	beqz	$zero,.NB0f0925f4
/*  f0923bc:	a4580030 */ 	sh	$t8,0x30($v0)
.NB0f0923c0:
/*  f0923c0:	2401000a */ 	addiu	$at,$zero,0xa
/*  f0923c4:	5601001e */ 	bnel	$s0,$at,.NB0f092440
/*  f0923c8:	24010009 */ 	addiu	$at,$zero,0x9
/*  f0923cc:	10c00003 */ 	beqz	$a2,.NB0f0923dc
/*  f0923d0:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0923d4:	10000002 */ 	beqz	$zero,.NB0f0923e0
/*  f0923d8:	00001025 */ 	or	$v0,$zero,$zero
.NB0f0923dc:
/*  f0923dc:	2402ffff */ 	addiu	$v0,$zero,-1
.NB0f0923e0:
/*  f0923e0:	44810000 */ 	mtc1	$at,$f0
/*  f0923e4:	97af0076 */ 	lhu	$t7,0x76($sp)
/*  f0923e8:	87ab0072 */ 	lh	$t3,0x72($sp)
/*  f0923ec:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0923f0:	35f90080 */ 	ori	$t9,$t7,0x80
/*  f0923f4:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0923f8:	afac002c */ 	sw	$t4,0x2c($sp)
/*  f0923fc:	00002025 */ 	or	$a0,$zero,$zero
/*  f092400:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f092404:	87a60066 */ 	lh	$a2,0x66($sp)
/*  f092408:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09240c:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f092410:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f092414:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f092418:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f09241c:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f092420:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f092424:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f092428:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f09242c:	0fc24762 */ 	jal	func0f0939f8
/*  f092430:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f092434:	1000006f */ 	beqz	$zero,.NB0f0925f4
/*  f092438:	00404025 */ 	or	$t0,$v0,$zero
/*  f09243c:	24010009 */ 	addiu	$at,$zero,0x9
.NB0f092440:
/*  f092440:	1601001b */ 	bne	$s0,$at,.NB0f0924b0
/*  f092444:	00002025 */ 	or	$a0,$zero,$zero
/*  f092448:	10c00003 */ 	beqz	$a2,.NB0f092458
/*  f09244c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f092450:	10000002 */ 	beqz	$zero,.NB0f09245c
/*  f092454:	00001025 */ 	or	$v0,$zero,$zero
.NB0f092458:
/*  f092458:	2402ffff */ 	addiu	$v0,$zero,-1
.NB0f09245c:
/*  f09245c:	44810000 */ 	mtc1	$at,$f0
/*  f092460:	97ad0076 */ 	lhu	$t5,0x76($sp)
/*  f092464:	87ae0072 */ 	lh	$t6,0x72($sp)
/*  f092468:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f09246c:	afb8002c */ 	sw	$t8,0x2c($sp)
/*  f092470:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f092474:	87a60066 */ 	lh	$a2,0x66($sp)
/*  f092478:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f09247c:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f092480:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f092484:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f092488:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f09248c:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f092490:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f092494:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f092498:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f09249c:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f0924a0:	0fc24762 */ 	jal	func0f0939f8
/*  f0924a4:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0924a8:	10000052 */ 	beqz	$zero,.NB0f0925f4
/*  f0924ac:	00404025 */ 	or	$t0,$v0,$zero
.NB0f0924b0:
/*  f0924b0:	06000003 */ 	bltz	$s0,.NB0f0924c0
/*  f0924b4:	2a010008 */ 	slti	$at,$s0,0x8
/*  f0924b8:	1420001c */ 	bnez	$at,.NB0f09252c
/*  f0924bc:	3c098007 */ 	lui	$t1,0x8007
.NB0f0924c0:
/*  f0924c0:	10c00003 */ 	beqz	$a2,.NB0f0924d0
/*  f0924c4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f0924c8:	10000002 */ 	beqz	$zero,.NB0f0924d4
/*  f0924cc:	00001025 */ 	or	$v0,$zero,$zero
.NB0f0924d0:
/*  f0924d0:	2402ffff */ 	addiu	$v0,$zero,-1
.NB0f0924d4:
/*  f0924d4:	44810000 */ 	mtc1	$at,$f0
/*  f0924d8:	97af0076 */ 	lhu	$t7,0x76($sp)
/*  f0924dc:	87b90072 */ 	lh	$t9,0x72($sp)
/*  f0924e0:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0924e4:	afab002c */ 	sw	$t3,0x2c($sp)
/*  f0924e8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0924ec:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f0924f0:	87a60066 */ 	lh	$a2,0x66($sp)
/*  f0924f4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0924f8:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0924fc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f092500:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f092504:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f092508:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f09250c:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f092510:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f092514:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f092518:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f09251c:	0fc24762 */ 	jal	func0f0939f8
/*  f092520:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f092524:	10000033 */ 	beqz	$zero,.NB0f0925f4
/*  f092528:	00404025 */ 	or	$t0,$v0,$zero
.NB0f09252c:
/*  f09252c:	001018c0 */ 	sll	$v1,$s0,0x3
/*  f092530:	2529d520 */ 	addiu	$t1,$t1,-10976
/*  f092534:	00701823 */ 	subu	$v1,$v1,$s0
/*  f092538:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f09253c:	00031880 */ 	sll	$v1,$v1,0x2
/*  f092540:	00701821 */ 	addu	$v1,$v1,$s0
/*  f092544:	00031880 */ 	sll	$v1,$v1,0x2
/*  f092548:	01831021 */ 	addu	$v0,$t4,$v1
/*  f09254c:	944d0030 */ 	lhu	$t5,0x30($v0)
/*  f092550:	02002025 */ 	or	$a0,$s0,$zero
/*  f092554:	31ae0001 */ 	andi	$t6,$t5,0x1
/*  f092558:	15c0000a */ 	bnez	$t6,.NB0f092584
/*  f09255c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f092560:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f092564:	0fc24437 */ 	jal	func0f092a98
/*  f092568:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f09256c:	3c098007 */ 	lui	$t1,0x8007
/*  f092570:	2529d520 */ 	addiu	$t1,$t1,-10976
/*  f092574:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f092578:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f09257c:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f092580:	03031021 */ 	addu	$v0,$t8,$v1
.NB0f092584:
/*  f092584:	10c00003 */ 	beqz	$a2,.NB0f092594
/*  f092588:	a450002e */ 	sh	$s0,0x2e($v0)
/*  f09258c:	10000002 */ 	beqz	$zero,.NB0f092598
/*  f092590:	00001025 */ 	or	$v0,$zero,$zero
.NB0f092594:
/*  f092594:	2402ffff */ 	addiu	$v0,$zero,-1
.NB0f092598:
/*  f092598:	3c01bf80 */ 	lui	$at,0xbf80
/*  f09259c:	44810000 */ 	mtc1	$at,$f0
/*  f0925a0:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f0925a4:	97b90076 */ 	lhu	$t9,0x76($sp)
/*  f0925a8:	87ab0072 */ 	lh	$t3,0x72($sp)
/*  f0925ac:	240cffff */ 	addiu	$t4,$zero,-1
/*  f0925b0:	afac002c */ 	sw	$t4,0x2c($sp)
/*  f0925b4:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f0925b8:	87a60066 */ 	lh	$a2,0x66($sp)
/*  f0925bc:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0925c0:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0925c4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0925c8:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0925cc:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0925d0:	006f2021 */ 	addu	$a0,$v1,$t7
/*  f0925d4:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0925d8:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0925dc:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0925e0:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f0925e4:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0925e8:	0fc24762 */ 	jal	func0f0939f8
/*  f0925ec:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0925f0:	02004025 */ 	or	$t0,$s0,$zero
.NB0f0925f4:
/*  f0925f4:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0925f8:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f0925fc:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f092600:	03e00008 */ 	jr	$ra
/*  f092604:	01001025 */ 	or	$v0,$t0,$zero
);
#endif

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

void audioPlayFromProp2(s32 channelnum, s32 soundnum, s16 padnum, struct prop *prop, s32 arg4, s32 arg5, s32 arg6, u16 arg7)
{
	struct audiochannel *channel = &g_AudioChannels[channelnum];
	bool a1 = (arg4 >= 6) ? true : false;
	bool a0 = (arg7 & 2) ? true : false;

	if (channelnum >= 0 && channelnum <= 7) {
		if (channel->unk28 == 11) {
			g_AudioChannels[channelnum].channelnum = (u16)channelnum;

			func0f0939f8(&g_AudioChannels[channelnum], prop, channel->soundnum26, -1,
					-1, arg7, 0, 0, 0, -1, 0, -1, 400, arg5, arg6);
		} else {
			if ((channel->flags & AUDIOCHANNELFLAG_2000) == 0 && soundnum >= 0) {
				channel->soundnum04 = soundnum;
			}

			if (a1) {
				channel->unk1c = PALDOWN(arg4);
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
				func0f092c04(channelnum);
				osSetThreadPri(0, prevpri);
#else
				func0f092c04(channelnum);
#endif
			}
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f0946b0
/*  f0946b0:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f0946b4:	afa7007c */ 	sw	$a3,0x7c($sp)
/*  f0946b8:	3c014120 */ 	lui	$at,0x4120
/*  f0946bc:	44813000 */ 	mtc1	$at,$f6
/*  f0946c0:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*  f0946c4:	afa50074 */ 	sw	$a1,0x74($sp)
/*  f0946c8:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0946cc:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0946d0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0946d4:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0946d8:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f0946dc:	afa60078 */ 	sw	$a2,0x78($sp)
/*  f0946e0:	10a00004 */ 	beqz	$a1,.L0f0946f4
/*  f0946e4:	e7a80064 */ 	swc1	$f8,0x64($sp)
/*  f0946e8:	84ae0000 */ 	lh	$t6,0x0($a1)
/*  f0946ec:	10000003 */ 	b	.L0f0946fc
/*  f0946f0:	a7ae0062 */ 	sh	$t6,0x62($sp)
.L0f0946f4:
/*  f0946f4:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0946f8:	a7af0062 */ 	sh	$t7,0x62($sp)
.L0f0946fc:
/*  f0946fc:	87a20086 */ 	lh	$v0,0x86($sp)
/*  f094700:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f094704:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f094708:	a7a20068 */ 	sh	$v0,0x68($sp)
/*  f09470c:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f094710:	00402025 */ 	or	$a0,$v0,$zero
/*  f094714:	308b7fff */ 	andi	$t3,$a0,0x7fff
/*  f094718:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f09471c:	13200018 */ 	beqz	$t9,.L0f094780
/*  f094720:	a7a2006c */ 	sh	$v0,0x6c($sp)
/*  f094724:	3c0d8006 */ 	lui	$t5,%hi(g_AudioRussMappings)
/*  f094728:	25addde4 */ 	addiu	$t5,$t5,%lo(g_AudioRussMappings)
/*  f09472c:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f094730:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f094734:	94650002 */ 	lhu	$a1,0x2($v1)
/*  f094738:	3c188006 */ 	lui	$t8,%hi(g_AudioConfigs)
/*  f09473c:	2718e4d8 */ 	addiu	$t8,$t8,%lo(g_AudioConfigs)
/*  f094740:	00057940 */ 	sll	$t7,$a1,0x5
/*  f094744:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f094748:	c4520008 */ 	lwc1	$f18,0x8($v0)
/*  f09474c:	c7a60064 */ 	lwc1	$f6,0x64($sp)
/*  f094750:	846e0000 */ 	lh	$t6,0x0($v1)
/*  f094754:	e7b2007c */ 	swc1	$f18,0x7c($sp)
/*  f094758:	c7a4007c */ 	lwc1	$f4,0x7c($sp)
/*  f09475c:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f094760:	c4500004 */ 	lwc1	$f16,0x4($v0)
/*  f094764:	4606203c */ 	c.lt.s	$f4,$f6
/*  f094768:	a7ae006c */ 	sh	$t6,0x6c($sp)
/*  f09476c:	e7aa0074 */ 	swc1	$f10,0x74($sp)
/*  f094770:	e7b00078 */ 	swc1	$f16,0x78($sp)
/*  f094774:	45000002 */ 	bc1f	.L0f094780
/*  f094778:	00000000 */ 	nop
/*  f09477c:	e7a40064 */ 	swc1	$f4,0x64($sp)
.L0f094780:
/*  f094780:	3c198007 */ 	lui	$t9,%hi(var8006ae34)
/*  f094784:	8f39ae34 */ 	lw	$t9,%lo(var8006ae34)($t9)
/*  f094788:	3c0b8007 */ 	lui	$t3,%hi(var8006ae2c)
/*  f09478c:	97ac006c */ 	lhu	$t4,0x6c($sp)
/*  f094790:	13200007 */ 	beqz	$t9,.L0f0947b0
/*  f094794:	00008025 */ 	or	$s0,$zero,$zero
/*  f094798:	8d6bae2c */ 	lw	$t3,%lo(var8006ae2c)($t3)
/*  f09479c:	318d07ff */ 	andi	$t5,$t4,0x7ff
/*  f0947a0:	156d0003 */ 	bne	$t3,$t5,.L0f0947b0
/*  f0947a4:	00000000 */ 	nop
/*  f0947a8:	10000001 */ 	b	.L0f0947b0
/*  f0947ac:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f0947b0:
/*  f0947b0:	8d2e006c */ 	lw	$t6,0x6c($t1)
/*  f0947b4:	00005025 */ 	or	$t2,$zero,$zero
/*  f0947b8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0947bc:	11c00003 */ 	beqz	$t6,.L0f0947cc
/*  f0947c0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0947c4:	10000001 */ 	b	.L0f0947cc
/*  f0947c8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0947cc:
/*  f0947cc:	8d2f0068 */ 	lw	$t7,0x68($t1)
/*  f0947d0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0947d4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0947d8:	11e00003 */ 	beqz	$t7,.L0f0947e8
/*  f0947dc:	00000000 */ 	nop
/*  f0947e0:	10000001 */ 	b	.L0f0947e8
/*  f0947e4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0947e8:
/*  f0947e8:	8d380064 */ 	lw	$t8,0x64($t1)
/*  f0947ec:	000a7080 */ 	sll	$t6,$t2,0x2
/*  f0947f0:	012e4021 */ 	addu	$t0,$t1,$t6
/*  f0947f4:	13000003 */ 	beqz	$t8,.L0f094804
/*  f0947f8:	00000000 */ 	nop
/*  f0947fc:	10000001 */ 	b	.L0f094804
/*  f094800:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f094804:
/*  f094804:	8d390070 */ 	lw	$t9,0x70($t1)
/*  f094808:	13200003 */ 	beqz	$t9,.L0f094818
/*  f09480c:	00000000 */ 	nop
/*  f094810:	10000001 */ 	b	.L0f094818
/*  f094814:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f094818:
/*  f094818:	00436021 */ 	addu	$t4,$v0,$v1
/*  f09481c:	01845821 */ 	addu	$t3,$t4,$a0
/*  f094820:	01656821 */ 	addu	$t5,$t3,$a1
/*  f094824:	59a00036 */ 	blezl	$t5,.L0f094900
/*  f094828:	8fa2008c */ 	lw	$v0,0x8c($sp)
/*  f09482c:	8faf006c */ 	lw	$t7,0x6c($sp)
.L0f094830:
/*  f094830:	8d020064 */ 	lw	$v0,0x64($t0)
/*  f094834:	87a60062 */ 	lh	$a2,0x62($sp)
/*  f094838:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f09483c:	0018cf82 */ 	srl	$t9,$t8,0x1e
/*  f094840:	17200003 */ 	bnez	$t9,.L0f094850
/*  f094844:	24451bb0 */ 	addiu	$a1,$v0,0x1bb0
/*  f094848:	10000002 */ 	b	.L0f094854
/*  f09484c:	8c441ba0 */ 	lw	$a0,0x1ba0($v0)
.L0f094850:
/*  f094850:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f094854:
/*  f094854:	27ac0064 */ 	addiu	$t4,$sp,0x64
/*  f094858:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f09485c:	8fa70070 */ 	lw	$a3,0x70($sp)
/*  f094860:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f094864:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f094868:	afa80034 */ 	sw	$t0,0x34($sp)
/*  f09486c:	0fc015bd */ 	jal	func0f0056f4
/*  f094870:	afaa0058 */ 	sw	$t2,0x58($sp)
/*  f094874:	3c09800a */ 	lui	$t1,%hi(g_Vars)
/*  f094878:	25299fc0 */ 	addiu	$t1,$t1,%lo(g_Vars)
/*  f09487c:	8d2b006c */ 	lw	$t3,0x6c($t1)
/*  f094880:	8fa80034 */ 	lw	$t0,0x34($sp)
/*  f094884:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f094888:	00002825 */ 	or	$a1,$zero,$zero
/*  f09488c:	25080004 */ 	addiu	$t0,$t0,0x4
/*  f094890:	11600003 */ 	beqz	$t3,.L0f0948a0
/*  f094894:	254a0001 */ 	addiu	$t2,$t2,0x1
/*  f094898:	10000001 */ 	b	.L0f0948a0
/*  f09489c:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0948a0:
/*  f0948a0:	8d2d0068 */ 	lw	$t5,0x68($t1)
/*  f0948a4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0948a8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0948ac:	11a00003 */ 	beqz	$t5,.L0f0948bc
/*  f0948b0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0948b4:	10000001 */ 	b	.L0f0948bc
/*  f0948b8:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0948bc:
/*  f0948bc:	8d2e0064 */ 	lw	$t6,0x64($t1)
/*  f0948c0:	11c00003 */ 	beqz	$t6,.L0f0948d0
/*  f0948c4:	00000000 */ 	nop
/*  f0948c8:	10000001 */ 	b	.L0f0948d0
/*  f0948cc:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0948d0:
/*  f0948d0:	8d2f0070 */ 	lw	$t7,0x70($t1)
/*  f0948d4:	11e00003 */ 	beqz	$t7,.L0f0948e4
/*  f0948d8:	00000000 */ 	nop
/*  f0948dc:	10000001 */ 	b	.L0f0948e4
/*  f0948e0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0948e4:
/*  f0948e4:	0043c021 */ 	addu	$t8,$v0,$v1
/*  f0948e8:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f0948ec:	03256021 */ 	addu	$t4,$t9,$a1
/*  f0948f0:	014c082a */ 	slt	$at,$t2,$t4
/*  f0948f4:	5420ffce */ 	bnezl	$at,.L0f094830
/*  f0948f8:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f0948fc:	8fa2008c */ 	lw	$v0,0x8c($sp)
.L0f094900:
/*  f094900:	c7a80064 */ 	lwc1	$f8,0x64($sp)
/*  f094904:	50400003 */ 	beqzl	$v0,.L0f094914
/*  f094908:	8fab0088 */ 	lw	$t3,0x88($sp)
/*  f09490c:	e4480000 */ 	swc1	$f8,0x0($v0)
/*  f094910:	8fab0088 */ 	lw	$t3,0x88($sp)
.L0f094914:
/*  f094914:	c7ac0064 */ 	lwc1	$f12,0x64($sp)
/*  f094918:	c7ae0074 */ 	lwc1	$f14,0x74($sp)
/*  f09491c:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f094920:	8fa7007c */ 	lw	$a3,0x7c($sp)
/*  f094924:	0fc249f5 */ 	jal	func0f0927d4
/*  f094928:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f09492c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f094930:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f094934:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f094938:	03e00008 */ 	jr	$ra
/*  f09493c:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel func0f0946b0
/*  f0929d8:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0929dc:	afa70074 */ 	sw	$a3,0x74($sp)
/*  f0929e0:	3c014120 */ 	lui	$at,0x4120
/*  f0929e4:	44813000 */ 	mtc1	$at,$f6
/*  f0929e8:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f0929ec:	afa5006c */ 	sw	$a1,0x6c($sp)
/*  f0929f0:	8fa50078 */ 	lw	$a1,0x78($sp)
/*  f0929f4:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f0929f8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0929fc:	afa40068 */ 	sw	$a0,0x68($sp)
/*  f092a00:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f092a04:	10a00004 */ 	beqz	$a1,.NB0f092a18
/*  f092a08:	e7a8005c */ 	swc1	$f8,0x5c($sp)
/*  f092a0c:	84ae0000 */ 	lh	$t6,0x0($a1)
/*  f092a10:	10000003 */ 	beqz	$zero,.NB0f092a20
/*  f092a14:	a7ae005a */ 	sh	$t6,0x5a($sp)
.NB0f092a18:
/*  f092a18:	240fffff */ 	addiu	$t7,$zero,-1
/*  f092a1c:	a7af005a */ 	sh	$t7,0x5a($sp)
.NB0f092a20:
/*  f092a20:	3c188007 */ 	lui	$t8,0x8007
/*  f092a24:	87a2007e */ 	lh	$v0,0x7e($sp)
/*  f092a28:	8f18d548 */ 	lw	$t8,-0x2ab8($t8)
/*  f092a2c:	3c09800a */ 	lui	$t1,0x800a
/*  f092a30:	a7a20060 */ 	sh	$v0,0x60($sp)
/*  f092a34:	13000004 */ 	beqz	$t8,.NB0f092a48
/*  f092a38:	a7a20064 */ 	sh	$v0,0x64($sp)
/*  f092a3c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f092a40:	c42a5a9c */ 	lwc1	$f10,0x5a9c($at)
/*  f092a44:	e7aa005c */ 	swc1	$f10,0x5c($sp)
.NB0f092a48:
/*  f092a48:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f092a4c:	97a40060 */ 	lhu	$a0,0x60($sp)
/*  f092a50:	2529e6c0 */ 	addiu	$t1,$t1,-6464
/*  f092a54:	00195fc2 */ 	srl	$t3,$t9,0x1f
/*  f092a58:	11600018 */ 	beqz	$t3,.NB0f092abc
/*  f092a5c:	308c7fff */ 	andi	$t4,$a0,0x7fff
/*  f092a60:	3c0e8006 */ 	lui	$t6,0x8006
/*  f092a64:	25cef6f8 */ 	addiu	$t6,$t6,-2312
/*  f092a68:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f092a6c:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f092a70:	94650002 */ 	lhu	$a1,0x2($v1)
/*  f092a74:	3c198006 */ 	lui	$t9,0x8006
/*  f092a78:	2739fdd0 */ 	addiu	$t9,$t9,-560
/*  f092a7c:	0005c140 */ 	sll	$t8,$a1,0x5
/*  f092a80:	03191021 */ 	addu	$v0,$t8,$t9
/*  f092a84:	c4440008 */ 	lwc1	$f4,0x8($v0)
/*  f092a88:	c7a8005c */ 	lwc1	$f8,0x5c($sp)
/*  f092a8c:	846f0000 */ 	lh	$t7,0x0($v1)
/*  f092a90:	e7a40074 */ 	swc1	$f4,0x74($sp)
/*  f092a94:	c7a60074 */ 	lwc1	$f6,0x74($sp)
/*  f092a98:	c4500000 */ 	lwc1	$f16,0x0($v0)
/*  f092a9c:	c4520004 */ 	lwc1	$f18,0x4($v0)
/*  f092aa0:	4608303c */ 	c.lt.s	$f6,$f8
/*  f092aa4:	a7af0064 */ 	sh	$t7,0x64($sp)
/*  f092aa8:	e7b0006c */ 	swc1	$f16,0x6c($sp)
/*  f092aac:	e7b20070 */ 	swc1	$f18,0x70($sp)
/*  f092ab0:	45000002 */ 	bc1f	.NB0f092abc
/*  f092ab4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f092ab8:	e7a6005c */ 	swc1	$f6,0x5c($sp)
.NB0f092abc:
/*  f092abc:	3c0b8007 */ 	lui	$t3,0x8007
/*  f092ac0:	8d6bd540 */ 	lw	$t3,-0x2ac0($t3)
/*  f092ac4:	3c0c8007 */ 	lui	$t4,0x8007
/*  f092ac8:	97ad0064 */ 	lhu	$t5,0x64($sp)
/*  f092acc:	11600008 */ 	beqz	$t3,.NB0f092af0
/*  f092ad0:	00002825 */ 	or	$a1,$zero,$zero
/*  f092ad4:	8d8cd538 */ 	lw	$t4,-0x2ac8($t4)
/*  f092ad8:	31ae07ff */ 	andi	$t6,$t5,0x7ff
/*  f092adc:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f092ae0:	558e0004 */ 	bnel	$t4,$t6,.NB0f092af4
/*  f092ae4:	afa00054 */ 	sw	$zero,0x54($sp)
/*  f092ae8:	10000002 */ 	beqz	$zero,.NB0f092af4
/*  f092aec:	afaf0054 */ 	sw	$t7,0x54($sp)
.NB0f092af0:
/*  f092af0:	afa00054 */ 	sw	$zero,0x54($sp)
.NB0f092af4:
/*  f092af4:	8d38006c */ 	lw	$t8,0x6c($t1)
/*  f092af8:	00005025 */ 	or	$t2,$zero,$zero
/*  f092afc:	00002025 */ 	or	$a0,$zero,$zero
/*  f092b00:	13000003 */ 	beqz	$t8,.NB0f092b10
/*  f092b04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f092b08:	10000001 */ 	beqz	$zero,.NB0f092b10
/*  f092b0c:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f092b10:
/*  f092b10:	8d390068 */ 	lw	$t9,0x68($t1)
/*  f092b14:	00001825 */ 	or	$v1,$zero,$zero
/*  f092b18:	00001025 */ 	or	$v0,$zero,$zero
/*  f092b1c:	13200003 */ 	beqz	$t9,.NB0f092b2c
/*  f092b20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f092b24:	10000001 */ 	beqz	$zero,.NB0f092b2c
/*  f092b28:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f092b2c:
/*  f092b2c:	8d2b0064 */ 	lw	$t3,0x64($t1)
/*  f092b30:	000ac080 */ 	sll	$t8,$t2,0x2
/*  f092b34:	01384021 */ 	addu	$t0,$t1,$t8
/*  f092b38:	11600003 */ 	beqz	$t3,.NB0f092b48
/*  f092b3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f092b40:	10000001 */ 	beqz	$zero,.NB0f092b48
/*  f092b44:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f092b48:
/*  f092b48:	8d2d0070 */ 	lw	$t5,0x70($t1)
/*  f092b4c:	11a00003 */ 	beqz	$t5,.NB0f092b5c
/*  f092b50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f092b54:	10000001 */ 	beqz	$zero,.NB0f092b5c
/*  f092b58:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f092b5c:
/*  f092b5c:	00436021 */ 	addu	$t4,$v0,$v1
/*  f092b60:	01847021 */ 	addu	$t6,$t4,$a0
/*  f092b64:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f092b68:	59e00037 */ 	blezl	$t7,.NB0f092c48
/*  f092b6c:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f092b70:	8fb90064 */ 	lw	$t9,0x64($sp)
.NB0f092b74:
/*  f092b74:	8d020064 */ 	lw	$v0,0x64($t0)
/*  f092b78:	87a6005a */ 	lh	$a2,0x5a($sp)
/*  f092b7c:	00195840 */ 	sll	$t3,$t9,0x1
/*  f092b80:	000b6f82 */ 	srl	$t5,$t3,0x1e
/*  f092b84:	15a00003 */ 	bnez	$t5,.NB0f092b94
/*  f092b88:	24451bb0 */ 	addiu	$a1,$v0,0x1bb0
/*  f092b8c:	10000002 */ 	beqz	$zero,.NB0f092b98
/*  f092b90:	8c441ba0 */ 	lw	$a0,0x1ba0($v0)
.NB0f092b94:
/*  f092b94:	2404ffff */ 	addiu	$a0,$zero,-1
.NB0f092b98:
/*  f092b98:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f092b9c:	27ac005c */ 	addiu	$t4,$sp,0x5c
/*  f092ba0:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f092ba4:	8fa70068 */ 	lw	$a3,0x68($sp)
/*  f092ba8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f092bac:	afa8002c */ 	sw	$t0,0x2c($sp)
/*  f092bb0:	afaa0050 */ 	sw	$t2,0x50($sp)
/*  f092bb4:	0fc0150f */ 	jal	func0f0056f4
/*  f092bb8:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f092bbc:	3c09800a */ 	lui	$t1,0x800a
/*  f092bc0:	2529e6c0 */ 	addiu	$t1,$t1,-6464
/*  f092bc4:	8d2f006c */ 	lw	$t7,0x6c($t1)
/*  f092bc8:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f092bcc:	8faa0050 */ 	lw	$t2,0x50($sp)
/*  f092bd0:	00002825 */ 	or	$a1,$zero,$zero
/*  f092bd4:	25080004 */ 	addiu	$t0,$t0,0x4
/*  f092bd8:	11e00003 */ 	beqz	$t7,.NB0f092be8
/*  f092bdc:	254a0001 */ 	addiu	$t2,$t2,0x1
/*  f092be0:	10000001 */ 	beqz	$zero,.NB0f092be8
/*  f092be4:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f092be8:
/*  f092be8:	8d380068 */ 	lw	$t8,0x68($t1)
/*  f092bec:	00002025 */ 	or	$a0,$zero,$zero
/*  f092bf0:	00001825 */ 	or	$v1,$zero,$zero
/*  f092bf4:	13000003 */ 	beqz	$t8,.NB0f092c04
/*  f092bf8:	00001025 */ 	or	$v0,$zero,$zero
/*  f092bfc:	10000001 */ 	beqz	$zero,.NB0f092c04
/*  f092c00:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f092c04:
/*  f092c04:	8d390064 */ 	lw	$t9,0x64($t1)
/*  f092c08:	13200003 */ 	beqz	$t9,.NB0f092c18
/*  f092c0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f092c10:	10000001 */ 	beqz	$zero,.NB0f092c18
/*  f092c14:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f092c18:
/*  f092c18:	8d2b0070 */ 	lw	$t3,0x70($t1)
/*  f092c1c:	11600003 */ 	beqz	$t3,.NB0f092c2c
/*  f092c20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f092c24:	10000001 */ 	beqz	$zero,.NB0f092c2c
/*  f092c28:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f092c2c:
/*  f092c2c:	00436821 */ 	addu	$t5,$v0,$v1
/*  f092c30:	01a46021 */ 	addu	$t4,$t5,$a0
/*  f092c34:	01857021 */ 	addu	$t6,$t4,$a1
/*  f092c38:	014e082a */ 	slt	$at,$t2,$t6
/*  f092c3c:	5420ffcd */ 	bnezl	$at,.NB0f092b74
/*  f092c40:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f092c44:	8fa20084 */ 	lw	$v0,0x84($sp)
.NB0f092c48:
/*  f092c48:	c7aa005c */ 	lwc1	$f10,0x5c($sp)
/*  f092c4c:	50400003 */ 	beqzl	$v0,.NB0f092c5c
/*  f092c50:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f092c54:	e44a0000 */ 	swc1	$f10,0x0($v0)
/*  f092c58:	8faf0080 */ 	lw	$t7,0x80($sp)
.NB0f092c5c:
/*  f092c5c:	c7ac005c */ 	lwc1	$f12,0x5c($sp)
/*  f092c60:	c7ae006c */ 	lwc1	$f14,0x6c($sp)
/*  f092c64:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f092c68:	8fa70074 */ 	lw	$a3,0x74($sp)
/*  f092c6c:	0fc24385 */ 	jal	func0f0927d4
/*  f092c70:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f092c74:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f092c78:	27bd0068 */ 	addiu	$sp,$sp,0x68
/*  f092c7c:	03e00008 */ 	jr	$ra
/*  f092c80:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

GLOBAL_ASM(
glabel func0f094940
.late_rodata
glabel var7f1ab74c
.word 0x3f2aaaab
glabel var7f1ab750
.word 0x3f333333
glabel var7f1ab754
.word 0x3f333333
.text
/*  f094940:	44856000 */ 	mtc1	$a1,$f12
/*  f094944:	288100b4 */ 	slti	$at,$a0,0xb4
/*  f094948:	14200005 */ 	bnez	$at,.L0f094960
/*  f09494c:	3c0e8006 */ 	lui	$t6,%hi(g_SoundMode)
/*  f094950:	2484fe98 */ 	addiu	$a0,$a0,-360
.L0f094954:
/*  f094954:	288100b4 */ 	slti	$at,$a0,0xb4
/*  f094958:	5020fffe */ 	beqzl	$at,.L0f094954
/*  f09495c:	2484fe98 */ 	addiu	$a0,$a0,-360
.L0f094960:
/*  f094960:	2881ff4c */ 	slti	$at,$a0,-180
/*  f094964:	10200005 */ 	beqz	$at,.L0f09497c
/*  f094968:	00000000 */ 	nop
/*  f09496c:	24840168 */ 	addiu	$a0,$a0,0x168
.L0f094970:
/*  f094970:	2881ff4c */ 	slti	$at,$a0,-180
/*  f094974:	5420fffe */ 	bnezl	$at,.L0f094970
/*  f094978:	24840168 */ 	addiu	$a0,$a0,0x168
.L0f09497c:
/*  f09497c:	8dceddcc */ 	lw	$t6,%lo(g_SoundMode)($t6)
/*  f094980:	24010003 */ 	addiu	$at,$zero,0x3
/*  f094984:	51c10012 */ 	beql	$t6,$at,.L0f0949d0
/*  f094988:	2881ffd4 */ 	slti	$at,$a0,-44
/*  f09498c:	18800003 */ 	blez	$a0,.L0f09499c
/*  f094990:	00041023 */ 	negu	$v0,$a0
/*  f094994:	10000001 */ 	b	.L0f09499c
/*  f094998:	00801025 */ 	or	$v0,$a0,$zero
.L0f09499c:
/*  f09499c:	2841005b */ 	slti	$at,$v0,0x5b
/*  f0949a0:	14200002 */ 	bnez	$at,.L0f0949ac
/*  f0949a4:	240f00b4 */ 	addiu	$t7,$zero,0xb4
/*  f0949a8:	01e21023 */ 	subu	$v0,$t7,$v0
.L0f0949ac:
/*  f0949ac:	18800003 */ 	blez	$a0,.L0f0949bc
/*  f0949b0:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f0949b4:	10000001 */ 	b	.L0f0949bc
/*  f0949b8:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0949bc:
/*  f0949bc:	00a20019 */ 	multu	$a1,$v0
/*  f0949c0:	00002012 */ 	mflo	$a0
/*  f0949c4:	10000021 */ 	b	.L0f094a4c
/*  f0949c8:	2881ffa6 */ 	slti	$at,$a0,-90
/*  f0949cc:	2881ffd4 */ 	slti	$at,$a0,-44
.L0f0949d0:
/*  f0949d0:	14200006 */ 	bnez	$at,.L0f0949ec
/*  f0949d4:	241900b4 */ 	addiu	$t9,$zero,0xb4
/*  f0949d8:	2881002d */ 	slti	$at,$a0,0x2d
/*  f0949dc:	10200003 */ 	beqz	$at,.L0f0949ec
/*  f0949e0:	0004c040 */ 	sll	$t8,$a0,0x1
/*  f0949e4:	10000018 */ 	b	.L0f094a48
/*  f0949e8:	03002025 */ 	or	$a0,$t8,$zero
.L0f0949ec:
/*  f0949ec:	18800003 */ 	blez	$a0,.L0f0949fc
/*  f0949f0:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0949f4:	10000001 */ 	b	.L0f0949fc
/*  f0949f8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0949fc:
/*  f0949fc:	18800003 */ 	blez	$a0,.L0f094a0c
/*  f094a00:	00042823 */ 	negu	$a1,$a0
/*  f094a04:	10000001 */ 	b	.L0f094a0c
/*  f094a08:	00802825 */ 	or	$a1,$a0,$zero
.L0f094a0c:
/*  f094a0c:	03254023 */ 	subu	$t0,$t9,$a1
/*  f094a10:	44882000 */ 	mtc1	$t0,$f4
/*  f094a14:	3c017f1b */ 	lui	$at,%hi(var7f1ab74c)
/*  f094a18:	c428b74c */ 	lwc1	$f8,%lo(var7f1ab74c)($at)
/*  f094a1c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f094a20:	240b00b4 */ 	addiu	$t3,$zero,0xb4
/*  f094a24:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f094a28:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f094a2c:	440a8000 */ 	mfc1	$t2,$f16
/*  f094a30:	00000000 */ 	nop
/*  f094a34:	016a6023 */ 	subu	$t4,$t3,$t2
/*  f094a38:	01820019 */ 	multu	$t4,$v0
/*  f094a3c:	00002012 */ 	mflo	$a0
/*  f094a40:	00000000 */ 	nop
/*  f094a44:	00000000 */ 	nop
.L0f094a48:
/*  f094a48:	2881ffa6 */ 	slti	$at,$a0,-90
.L0f094a4c:
/*  f094a4c:	14200010 */ 	bnez	$at,.L0f094a90
/*  f094a50:	240e00b4 */ 	addiu	$t6,$zero,0xb4
/*  f094a54:	2881005b */ 	slti	$at,$a0,0x5b
/*  f094a58:	1020000d */ 	beqz	$at,.L0f094a90
/*  f094a5c:	00000000 */ 	nop
/*  f094a60:	44849000 */ 	mtc1	$a0,$f18
/*  f094a64:	3c017f1b */ 	lui	$at,%hi(var7f1ab750)
/*  f094a68:	c426b750 */ 	lwc1	$f6,%lo(var7f1ab750)($at)
/*  f094a6c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f094a70:	3c014280 */ 	lui	$at,0x4280
/*  f094a74:	44815000 */ 	mtc1	$at,$f10
/*  f094a78:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f094a7c:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f094a80:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f094a84:	44039000 */ 	mfc1	$v1,$f18
/*  f094a88:	10000019 */ 	b	.L0f094af0
/*  f094a8c:	00000000 */ 	nop
.L0f094a90:
/*  f094a90:	18800003 */ 	blez	$a0,.L0f094aa0
/*  f094a94:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f094a98:	10000001 */ 	b	.L0f094aa0
/*  f094a9c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f094aa0:
/*  f094aa0:	18800003 */ 	blez	$a0,.L0f094ab0
/*  f094aa4:	00042823 */ 	negu	$a1,$a0
/*  f094aa8:	10000001 */ 	b	.L0f094ab0
/*  f094aac:	00802825 */ 	or	$a1,$a0,$zero
.L0f094ab0:
/*  f094ab0:	01c57823 */ 	subu	$t7,$t6,$a1
/*  f094ab4:	01e20019 */ 	multu	$t7,$v0
/*  f094ab8:	3c017f1b */ 	lui	$at,%hi(var7f1ab754)
/*  f094abc:	c428b754 */ 	lwc1	$f8,%lo(var7f1ab754)($at)
/*  f094ac0:	3c014280 */ 	lui	$at,0x4280
/*  f094ac4:	44818000 */ 	mtc1	$at,$f16
/*  f094ac8:	0000c012 */ 	mflo	$t8
/*  f094acc:	44982000 */ 	mtc1	$t8,$f4
/*  f094ad0:	00000000 */ 	nop
/*  f094ad4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f094ad8:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f094adc:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f094ae0:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f094ae4:	44032000 */ 	mfc1	$v1,$f4
/*  f094ae8:	00000000 */ 	nop
/*  f094aec:	24630080 */ 	addiu	$v1,$v1,0x80
.L0f094af0:
/*  f094af0:	10c00008 */ 	beqz	$a2,.L0f094b14
/*  f094af4:	3c0142c8 */ 	lui	$at,0x42c8
/*  f094af8:	44813000 */ 	mtc1	$at,$f6
/*  f094afc:	a4c40014 */ 	sh	$a0,0x14($a2)
/*  f094b00:	460c3202 */ 	mul.s	$f8,$f6,$f12
/*  f094b04:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f094b08:	44095000 */ 	mfc1	$t1,$f10
/*  f094b0c:	00000000 */ 	nop
/*  f094b10:	a4c90016 */ 	sh	$t1,0x16($a2)
.L0f094b14:
/*  f094b14:	03e00008 */ 	jr	$ra
/*  f094b18:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f094b1c
.late_rodata
glabel var7f1ab758
.word 0x40490fdb
glabel var7f1ab75c
.word 0x3c8efa35
glabel var7f1ab760
.word 0x40490fdb
glabel var7f1ab764
.word 0x40490fdb
glabel var7f1ab768
.word 0x42652ee0
.text
/*  f094b1c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f094b20:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f094b24:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f094b28:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f094b2c:	8cae006c */ 	lw	$t6,0x6c($a1)
/*  f094b30:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f094b34:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f094b38:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f094b3c:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f094b40:	11c00003 */ 	beqz	$t6,.L0f094b50
/*  f094b44:	24080040 */ 	addiu	$t0,$zero,0x40
/*  f094b48:	10000002 */ 	b	.L0f094b54
/*  f094b4c:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f094b50:
/*  f094b50:	00003025 */ 	or	$a2,$zero,$zero
.L0f094b54:
/*  f094b54:	8caf0068 */ 	lw	$t7,0x68($a1)
/*  f094b58:	00001825 */ 	or	$v1,$zero,$zero
/*  f094b5c:	00002025 */ 	or	$a0,$zero,$zero
/*  f094b60:	11e00003 */ 	beqz	$t7,.L0f094b70
/*  f094b64:	00001025 */ 	or	$v0,$zero,$zero
/*  f094b68:	10000001 */ 	b	.L0f094b70
/*  f094b6c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f094b70:
/*  f094b70:	8cb80064 */ 	lw	$t8,0x64($a1)
/*  f094b74:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f094b78:	13000003 */ 	beqz	$t8,.L0f094b88
/*  f094b7c:	00000000 */ 	nop
/*  f094b80:	10000001 */ 	b	.L0f094b88
/*  f094b84:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f094b88:
/*  f094b88:	8cb90070 */ 	lw	$t9,0x70($a1)
/*  f094b8c:	13200003 */ 	beqz	$t9,.L0f094b9c
/*  f094b90:	00000000 */ 	nop
/*  f094b94:	10000001 */ 	b	.L0f094b9c
/*  f094b98:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f094b9c:
/*  f094b9c:	00444821 */ 	addu	$t1,$v0,$a0
/*  f094ba0:	01235021 */ 	addu	$t2,$t1,$v1
/*  f094ba4:	01465821 */ 	addu	$t3,$t2,$a2
/*  f094ba8:	29610002 */ 	slti	$at,$t3,0x2
/*  f094bac:	5020006e */ 	beqzl	$at,.L0f094d68
/*  f094bb0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f094bb4:	8ca20284 */ 	lw	$v0,0x284($a1)
/*  f094bb8:	c5840000 */ 	lwc1	$f4,0x0($t4)
/*  f094bbc:	c5880008 */ 	lwc1	$f8,0x8($t4)
/*  f094bc0:	c44a1bb8 */ 	lwc1	$f10,0x1bb8($v0)
/*  f094bc4:	c4461bb0 */ 	lwc1	$f6,0x1bb0($v0)
/*  f094bc8:	24421bb0 */ 	addiu	$v0,$v0,0x1bb0
/*  f094bcc:	460a4381 */ 	sub.s	$f14,$f8,$f10
/*  f094bd0:	0fc259d4 */ 	jal	atan2f
/*  f094bd4:	46062301 */ 	sub.s	$f12,$f4,$f6
/*  f094bd8:	3c014334 */ 	lui	$at,0x4334
/*  f094bdc:	44812000 */ 	mtc1	$at,$f4
/*  f094be0:	3c017f1b */ 	lui	$at,%hi(var7f1ab758)
/*  f094be4:	c428b758 */ 	lwc1	$f8,%lo(var7f1ab758)($at)
/*  f094be8:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f094bec:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f094bf0:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f094bf4:	8cad0284 */ 	lw	$t5,0x284($a1)
/*  f094bf8:	c7ae0068 */ 	lwc1	$f14,0x68($sp)
/*  f094bfc:	44809000 */ 	mtc1	$zero,$f18
/*  f094c00:	c5a40144 */ 	lwc1	$f4,0x144($t5)
/*  f094c04:	46083283 */ 	div.s	$f10,$f6,$f8
/*  f094c08:	3c017f1b */ 	lui	$at,%hi(var7f1ab75c)
/*  f094c0c:	460e903e */ 	c.le.s	$f18,$f14
/*  f094c10:	46045080 */ 	add.s	$f2,$f10,$f4
/*  f094c14:	45000041 */ 	bc1f	.L0f094d1c
/*  f094c18:	46001087 */ 	neg.s	$f2,$f2
/*  f094c1c:	c426b75c */ 	lwc1	$f6,%lo(var7f1ab75c)($at)
/*  f094c20:	46023302 */ 	mul.s	$f12,$f6,$f2
/*  f094c24:	0c0068f7 */ 	jal	sinf
/*  f094c28:	e7ac001c */ 	swc1	$f12,0x1c($sp)
/*  f094c2c:	c7ac001c */ 	lwc1	$f12,0x1c($sp)
/*  f094c30:	0c0068f4 */ 	jal	cosf
/*  f094c34:	e7a0003c */ 	swc1	$f0,0x3c($sp)
/*  f094c38:	c7b0003c */ 	lwc1	$f16,0x3c($sp)
/*  f094c3c:	c7a80068 */ 	lwc1	$f8,0x68($sp)
/*  f094c40:	44809000 */ 	mtc1	$zero,$f18
/*  f094c44:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f094c48:	46088402 */ 	mul.s	$f16,$f16,$f8
/*  f094c4c:	4610903c */ 	c.lt.s	$f18,$f16
/*  f094c50:	00000000 */ 	nop
/*  f094c54:	45020004 */ 	bc1fl	.L0f094c68
/*  f094c58:	46008307 */ 	neg.s	$f12,$f16
/*  f094c5c:	10000002 */ 	b	.L0f094c68
/*  f094c60:	46008306 */ 	mov.s	$f12,$f16
/*  f094c64:	46008307 */ 	neg.s	$f12,$f16
.L0f094c68:
/*  f094c68:	4600903c */ 	c.lt.s	$f18,$f0
/*  f094c6c:	00000000 */ 	nop
/*  f094c70:	45020004 */ 	bc1fl	.L0f094c84
/*  f094c74:	46000387 */ 	neg.s	$f14,$f0
/*  f094c78:	10000002 */ 	b	.L0f094c84
/*  f094c7c:	46000386 */ 	mov.s	$f14,$f0
/*  f094c80:	46000387 */ 	neg.s	$f14,$f0
.L0f094c84:
/*  f094c84:	0fc259d4 */ 	jal	atan2f
/*  f094c88:	e7b0003c */ 	swc1	$f16,0x3c($sp)
/*  f094c8c:	c7b0003c */ 	lwc1	$f16,0x3c($sp)
/*  f094c90:	44809000 */ 	mtc1	$zero,$f18
/*  f094c94:	c7ac0038 */ 	lwc1	$f12,0x38($sp)
/*  f094c98:	46000086 */ 	mov.s	$f2,$f0
/*  f094c9c:	4610903e */ 	c.le.s	$f18,$f16
/*  f094ca0:	00000000 */ 	nop
/*  f094ca4:	45020006 */ 	bc1fl	.L0f094cc0
/*  f094ca8:	4610903e */ 	c.le.s	$f18,$f16
/*  f094cac:	460c903e */ 	c.le.s	$f18,$f12
/*  f094cb0:	00000000 */ 	nop
/*  f094cb4:	45010011 */ 	bc1t	.L0f094cfc
/*  f094cb8:	00000000 */ 	nop
/*  f094cbc:	4610903e */ 	c.le.s	$f18,$f16
.L0f094cc0:
/*  f094cc0:	3c017f1b */ 	lui	$at,%hi(var7f1ab760)
/*  f094cc4:	45020005 */ 	bc1fl	.L0f094cdc
/*  f094cc8:	460c903e */ 	c.le.s	$f18,$f12
/*  f094ccc:	c42ab760 */ 	lwc1	$f10,%lo(var7f1ab760)($at)
/*  f094cd0:	1000000a */ 	b	.L0f094cfc
/*  f094cd4:	46005081 */ 	sub.s	$f2,$f10,$f0
/*  f094cd8:	460c903e */ 	c.le.s	$f18,$f12
.L0f094cdc:
/*  f094cdc:	3c017f1b */ 	lui	$at,%hi(var7f1ab764)
/*  f094ce0:	45000003 */ 	bc1f	.L0f094cf0
/*  f094ce4:	00000000 */ 	nop
/*  f094ce8:	10000004 */ 	b	.L0f094cfc
/*  f094cec:	46000087 */ 	neg.s	$f2,$f0
.L0f094cf0:
/*  f094cf0:	c424b764 */ 	lwc1	$f4,%lo(var7f1ab764)($at)
/*  f094cf4:	46002081 */ 	sub.s	$f2,$f4,$f0
/*  f094cf8:	46001087 */ 	neg.s	$f2,$f2
.L0f094cfc:
/*  f094cfc:	3c017f1b */ 	lui	$at,%hi(var7f1ab768)
/*  f094d00:	c426b768 */ 	lwc1	$f6,%lo(var7f1ab768)($at)
/*  f094d04:	c7ae0068 */ 	lwc1	$f14,0x68($sp)
/*  f094d08:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f094d0c:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f094d10:	44045000 */ 	mfc1	$a0,$f10
/*  f094d14:	10000005 */ 	b	.L0f094d2c
/*  f094d18:	8fa6006c */ 	lw	$a2,0x6c($sp)
.L0f094d1c:
/*  f094d1c:	4600110d */ 	trunc.w.s	$f4,$f2
/*  f094d20:	44042000 */ 	mfc1	$a0,$f4
/*  f094d24:	00000000 */ 	nop
/*  f094d28:	8fa6006c */ 	lw	$a2,0x6c($sp)
.L0f094d2c:
/*  f094d2c:	44057000 */ 	mfc1	$a1,$f14
/*  f094d30:	3c0142c8 */ 	lui	$at,0x42c8
/*  f094d34:	10c00008 */ 	beqz	$a2,.L0f094d58
/*  f094d38:	00000000 */ 	nop
/*  f094d3c:	44813000 */ 	mtc1	$at,$f6
/*  f094d40:	a4c40014 */ 	sh	$a0,0x14($a2)
/*  f094d44:	460e3202 */ 	mul.s	$f8,$f6,$f14
/*  f094d48:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f094d4c:	44195000 */ 	mfc1	$t9,$f10
/*  f094d50:	00000000 */ 	nop
/*  f094d54:	a4d90016 */ 	sh	$t9,0x16($a2)
.L0f094d58:
/*  f094d58:	0fc25250 */ 	jal	func0f094940
/*  f094d5c:	00000000 */ 	nop
/*  f094d60:	00404025 */ 	or	$t0,$v0,$zero
/*  f094d64:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f094d68:
/*  f094d68:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f094d6c:	01001025 */ 	or	$v0,$t0,$zero
/*  f094d70:	03e00008 */ 	jr	$ra
/*  f094d74:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f094d78
.late_rodata
glabel var7f1ab76c
.word 0x451c4000
glabel var7f1ab770
.word 0x453b8000
glabel var7f1ab774
.word 0x45abe800
glabel var7f1ab778
.word 0x45b54800
.text
/*  f094d78:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f094d7c:	44856000 */ 	mtc1	$a1,$f12
/*  f094d80:	44867000 */ 	mtc1	$a2,$f14
/*  f094d84:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f094d88:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f094d8c:	10800054 */ 	beqz	$a0,.L0f094ee0
/*  f094d90:	24030040 */ 	addiu	$v1,$zero,0x40
/*  f094d94:	44808000 */ 	mtc1	$zero,$f16
/*  f094d98:	c7b20028 */ 	lwc1	$f18,0x28($sp)
/*  f094d9c:	c7a40024 */ 	lwc1	$f4,0x24($sp)
/*  f094da0:	4612803c */ 	c.lt.s	$f16,$f18
/*  f094da4:	00000000 */ 	nop
/*  f094da8:	4502004e */ 	bc1fl	.L0f094ee4
/*  f094dac:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f094db0:	4610603c */ 	c.lt.s	$f12,$f16
/*  f094db4:	3c0143c8 */ 	lui	$at,0x43c8
/*  f094db8:	45020004 */ 	bc1fl	.L0f094dcc
/*  f094dbc:	4610703c */ 	c.lt.s	$f14,$f16
/*  f094dc0:	44816000 */ 	mtc1	$at,$f12
/*  f094dc4:	00000000 */ 	nop
/*  f094dc8:	4610703c */ 	c.lt.s	$f14,$f16
.L0f094dcc:
/*  f094dcc:	3c017f1b */ 	lui	$at,%hi(var7f1ab76c)
/*  f094dd0:	45020003 */ 	bc1fl	.L0f094de0
/*  f094dd4:	4610203c */ 	c.lt.s	$f4,$f16
/*  f094dd8:	c42eb76c */ 	lwc1	$f14,%lo(var7f1ab76c)($at)
/*  f094ddc:	4610203c */ 	c.lt.s	$f4,$f16
.L0f094de0:
/*  f094de0:	3c017f1b */ 	lui	$at,%hi(var7f1ab770)
/*  f094de4:	45020004 */ 	bc1fl	.L0f094df8
/*  f094de8:	c7a80024 */ 	lwc1	$f8,0x24($sp)
/*  f094dec:	c426b770 */ 	lwc1	$f6,%lo(var7f1ab770)($at)
/*  f094df0:	e7a60024 */ 	swc1	$f6,0x24($sp)
/*  f094df4:	c7a80024 */ 	lwc1	$f8,0x24($sp)
.L0f094df8:
/*  f094df8:	3c017f1b */ 	lui	$at,%hi(var7f1ab774)
/*  f094dfc:	8fae002c */ 	lw	$t6,0x2c($sp)
/*  f094e00:	4608903c */ 	c.lt.s	$f18,$f8
/*  f094e04:	00000000 */ 	nop
/*  f094e08:	45020036 */ 	bc1fl	.L0f094ee4
/*  f094e0c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f094e10:	c420b774 */ 	lwc1	$f0,%lo(var7f1ab774)($at)
/*  f094e14:	3c017f1b */ 	lui	$at,%hi(var7f1ab778)
/*  f094e18:	00002825 */ 	or	$a1,$zero,$zero
/*  f094e1c:	460c003c */ 	c.lt.s	$f0,$f12
/*  f094e20:	3c06bf80 */ 	lui	$a2,0xbf80
/*  f094e24:	45000002 */ 	bc1f	.L0f094e30
/*  f094e28:	00000000 */ 	nop
/*  f094e2c:	46000306 */ 	mov.s	$f12,$f0
.L0f094e30:
/*  f094e30:	c420b778 */ 	lwc1	$f0,%lo(var7f1ab778)($at)
/*  f094e34:	460e003c */ 	c.lt.s	$f0,$f14
/*  f094e38:	00000000 */ 	nop
/*  f094e3c:	45000002 */ 	bc1f	.L0f094e48
/*  f094e40:	00000000 */ 	nop
/*  f094e44:	46000386 */ 	mov.s	$f14,$f0
.L0f094e48:
/*  f094e48:	11c00022 */ 	beqz	$t6,.L0f094ed4
/*  f094e4c:	00000000 */ 	nop
/*  f094e50:	460c903c */ 	c.lt.s	$f18,$f12
/*  f094e54:	00000000 */ 	nop
/*  f094e58:	45030022 */ 	bc1tl	.L0f094ee4
/*  f094e5c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f094e60:	460e903c */ 	c.lt.s	$f18,$f14
/*  f094e64:	3c013f80 */ 	lui	$at,0x3f80
/*  f094e68:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f094e6c:	00002825 */ 	or	$a1,$zero,$zero
/*  f094e70:	45000014 */ 	bc1f	.L0f094ec4
/*  f094e74:	3c06bf80 */ 	lui	$a2,0xbf80
/*  f094e78:	460c9281 */ 	sub.s	$f10,$f18,$f12
/*  f094e7c:	44810000 */ 	mtc1	$at,$f0
/*  f094e80:	460c7101 */ 	sub.s	$f4,$f14,$f12
/*  f094e84:	46045083 */ 	div.s	$f2,$f10,$f4
/*  f094e88:	4610103c */ 	c.lt.s	$f2,$f16
/*  f094e8c:	00000000 */ 	nop
/*  f094e90:	45020003 */ 	bc1fl	.L0f094ea0
/*  f094e94:	4602003c */ 	c.lt.s	$f0,$f2
/*  f094e98:	46008086 */ 	mov.s	$f2,$f16
/*  f094e9c:	4602003c */ 	c.lt.s	$f0,$f2
.L0f094ea0:
/*  f094ea0:	00000000 */ 	nop
/*  f094ea4:	45020003 */ 	bc1fl	.L0f094eb4
/*  f094ea8:	44061000 */ 	mfc1	$a2,$f2
/*  f094eac:	46000086 */ 	mov.s	$f2,$f0
/*  f094eb0:	44061000 */ 	mfc1	$a2,$f2
.L0f094eb4:
/*  f094eb4:	0fc252c7 */ 	jal	func0f094b1c
/*  f094eb8:	00002825 */ 	or	$a1,$zero,$zero
/*  f094ebc:	10000008 */ 	b	.L0f094ee0
/*  f094ec0:	00401825 */ 	or	$v1,$v0,$zero
.L0f094ec4:
/*  f094ec4:	0fc252c7 */ 	jal	func0f094b1c
/*  f094ec8:	00003825 */ 	or	$a3,$zero,$zero
/*  f094ecc:	10000004 */ 	b	.L0f094ee0
/*  f094ed0:	00401825 */ 	or	$v1,$v0,$zero
.L0f094ed4:
/*  f094ed4:	0fc252c7 */ 	jal	func0f094b1c
/*  f094ed8:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f094edc:	00401825 */ 	or	$v1,$v0,$zero
.L0f094ee0:
/*  f094ee0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f094ee4:
/*  f094ee4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f094ee8:	00601025 */ 	or	$v0,$v1,$zero
/*  f094eec:	03e00008 */ 	jr	$ra
/*  f094ef0:	00000000 */ 	nop
);

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func0f094ef4
.late_rodata
glabel var7f1ab77c
.word 0x451c4000
glabel var7f1ab780
.word 0x453b8000
glabel var7f1ab784
.word 0x4b18967f
.text
/*  f094ef4:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f094ef8:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f094efc:	3c0143c8 */ 	lui	$at,0x43c8
/*  f094f00:	87ae006a */ 	lh	$t6,0x6a($sp)
/*  f094f04:	44811000 */ 	mtc1	$at,$f2
/*  f094f08:	3c017f1b */ 	lui	$at,%hi(var7f1ab77c)
/*  f094f0c:	c42cb77c */ 	lwc1	$f12,%lo(var7f1ab77c)($at)
/*  f094f10:	3c017f1b */ 	lui	$at,%hi(var7f1ab780)
/*  f094f14:	a7ae0044 */ 	sh	$t6,0x44($sp)
/*  f094f18:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f094f1c:	c420b780 */ 	lwc1	$f0,%lo(var7f1ab780)($at)
/*  f094f20:	3c017f1b */ 	lui	$at,%hi(var7f1ab784)
/*  f094f24:	c424b784 */ 	lwc1	$f4,%lo(var7f1ab784)($at)
/*  f094f28:	000fc7c2 */ 	srl	$t8,$t7,0x1f
/*  f094f2c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f094f30:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f094f34:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f094f38:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f094f3c:	00004025 */ 	or	$t0,$zero,$zero
/*  f094f40:	13000020 */ 	beqz	$t8,.L0f094fc4
/*  f094f44:	e7a40040 */ 	swc1	$f4,0x40($sp)
/*  f094f48:	01c02025 */ 	or	$a0,$t6,$zero
/*  f094f4c:	30997fff */ 	andi	$t9,$a0,0x7fff
/*  f094f50:	3c0a8006 */ 	lui	$t2,%hi(g_AudioRussMappings)
/*  f094f54:	254adde4 */ 	addiu	$t2,$t2,%lo(g_AudioRussMappings)
/*  f094f58:	00194880 */ 	sll	$t1,$t9,0x2
/*  f094f5c:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f094f60:	94650002 */ 	lhu	$a1,0x2($v1)
/*  f094f64:	3c0c8006 */ 	lui	$t4,%hi(g_AudioConfigs)
/*  f094f68:	258ce4d8 */ 	addiu	$t4,$t4,%lo(g_AudioConfigs)
/*  f094f6c:	00055940 */ 	sll	$t3,$a1,0x5
/*  f094f70:	016c1021 */ 	addu	$v0,$t3,$t4
/*  f094f74:	8c4e001c */ 	lw	$t6,0x1c($v0)
/*  f094f78:	846d0000 */ 	lh	$t5,0x0($v1)
/*  f094f7c:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f094f80:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f094f84:	c44c0004 */ 	lwc1	$f12,0x4($v0)
/*  f094f88:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f094f8c:	11e00002 */ 	beqz	$t7,.L0f094f98
/*  f094f90:	a7ad0048 */ 	sh	$t5,0x48($sp)
/*  f094f94:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f094f98:
/*  f094f98:	c7a60040 */ 	lwc1	$f6,0x40($sp)
/*  f094f9c:	4606003c */ 	c.lt.s	$f0,$f6
/*  f094fa0:	00000000 */ 	nop
/*  f094fa4:	45020003 */ 	bc1fl	.L0f094fb4
/*  f094fa8:	93b80048 */ 	lbu	$t8,0x48($sp)
/*  f094fac:	e7a00040 */ 	swc1	$f0,0x40($sp)
/*  f094fb0:	93b80048 */ 	lbu	$t8,0x48($sp)
.L0f094fb4:
/*  f094fb4:	3319ff7f */ 	andi	$t9,$t8,0xff7f
/*  f094fb8:	a3b90048 */ 	sb	$t9,0x48($sp)
/*  f094fbc:	87a90048 */ 	lh	$t1,0x48($sp)
/*  f094fc0:	a7a9006a */ 	sh	$t1,0x6a($sp)
.L0f094fc4:
/*  f094fc4:	8faa0064 */ 	lw	$t2,0x64($sp)
/*  f094fc8:	87ab006a */ 	lh	$t3,0x6a($sp)
/*  f094fcc:	44051000 */ 	mfc1	$a1,$f2
/*  f094fd0:	44066000 */ 	mfc1	$a2,$f12
/*  f094fd4:	44070000 */ 	mfc1	$a3,$f0
/*  f094fd8:	240c7fff */ 	addiu	$t4,$zero,0x7fff
/*  f094fdc:	27ad0040 */ 	addiu	$t5,$sp,0x40
/*  f094fe0:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f094fe4:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f094fe8:	8fa40060 */ 	lw	$a0,0x60($sp)
/*  f094fec:	afa8003c */ 	sw	$t0,0x3c($sp)
/*  f094ff0:	e7a00054 */ 	swc1	$f0,0x54($sp)
/*  f094ff4:	e7a2005c */ 	swc1	$f2,0x5c($sp)
/*  f094ff8:	e7ac0058 */ 	swc1	$f12,0x58($sp)
/*  f094ffc:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f095000:	0fc251ac */ 	jal	func0f0946b0
/*  f095004:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f095008:	8fae006c */ 	lw	$t6,0x6c($sp)
/*  f09500c:	8fa8003c */ 	lw	$t0,0x3c($sp)
/*  f095010:	c7a00054 */ 	lwc1	$f0,0x54($sp)
/*  f095014:	c7a2005c */ 	lwc1	$f2,0x5c($sp)
/*  f095018:	c7ac0058 */ 	lwc1	$f12,0x58($sp)
/*  f09501c:	adc20000 */ 	sw	$v0,0x0($t6)
/*  f095020:	c7a80040 */ 	lwc1	$f8,0x40($sp)
/*  f095024:	44070000 */ 	mfc1	$a3,$f0
/*  f095028:	44051000 */ 	mfc1	$a1,$f2
/*  f09502c:	44066000 */ 	mfc1	$a2,$f12
/*  f095030:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f095034:	8fa40060 */ 	lw	$a0,0x60($sp)
/*  f095038:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f09503c:	0fc2535e */ 	jal	func0f094d78
/*  f095040:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f095044:	8faf0070 */ 	lw	$t7,0x70($sp)
/*  f095048:	ade20000 */ 	sw	$v0,0x0($t7)
/*  f09504c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f095050:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f095054:	03e00008 */ 	jr	$ra
/*  f095058:	00000000 */ 	nop
);
#endif

GLOBAL_ASM(
glabel func0f09505c
.late_rodata
glabel var7f1ab788
.word 0x4b18967f
.text
/*  f09505c:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f095060:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f095064:	8fb00080 */ 	lw	$s0,0x80($sp)
/*  f095068:	3c017f1b */ 	lui	$at,%hi(var7f1ab788)
/*  f09506c:	c424b788 */ 	lwc1	$f4,%lo(var7f1ab788)($at)
/*  f095070:	87ae007a */ 	lh	$t6,0x7a($sp)
/*  f095074:	44866000 */ 	mtc1	$a2,$f12
/*  f095078:	44877000 */ 	mtc1	$a3,$f14
/*  f09507c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f095080:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f095084:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f095088:	00004025 */ 	or	$t0,$zero,$zero
/*  f09508c:	e7a40054 */ 	swc1	$f4,0x54($sp)
/*  f095090:	16000002 */ 	bnez	$s0,.L0f09509c
/*  f095094:	a7ae0058 */ 	sh	$t6,0x58($sp)
/*  f095098:	27b00054 */ 	addiu	$s0,$sp,0x54
.L0f09509c:
/*  f09509c:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f0950a0:	97a40058 */ 	lhu	$a0,0x58($sp)
/*  f0950a4:	3c0a8006 */ 	lui	$t2,%hi(g_AudioRussMappings)
/*  f0950a8:	000fc7c2 */ 	srl	$t8,$t7,0x1f
/*  f0950ac:	1300001e */ 	beqz	$t8,.L0f095128
/*  f0950b0:	30997fff */ 	andi	$t9,$a0,0x7fff
/*  f0950b4:	00194880 */ 	sll	$t1,$t9,0x2
/*  f0950b8:	254adde4 */ 	addiu	$t2,$t2,%lo(g_AudioRussMappings)
/*  f0950bc:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f0950c0:	94650002 */ 	lhu	$a1,0x2($v1)
/*  f0950c4:	3c0c8006 */ 	lui	$t4,%hi(g_AudioConfigs)
/*  f0950c8:	258ce4d8 */ 	addiu	$t4,$t4,%lo(g_AudioConfigs)
/*  f0950cc:	00055940 */ 	sll	$t3,$a1,0x5
/*  f0950d0:	016c1021 */ 	addu	$v0,$t3,$t4
/*  f0950d4:	8c4e001c */ 	lw	$t6,0x1c($v0)
/*  f0950d8:	846d0000 */ 	lh	$t5,0x0($v1)
/*  f0950dc:	c44c0000 */ 	lwc1	$f12,0x0($v0)
/*  f0950e0:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f0950e4:	c44e0004 */ 	lwc1	$f14,0x4($v0)
/*  f0950e8:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f0950ec:	11e00002 */ 	beqz	$t7,.L0f0950f8
/*  f0950f0:	a7ad005c */ 	sh	$t5,0x5c($sp)
/*  f0950f4:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0950f8:
/*  f0950f8:	c6060000 */ 	lwc1	$f6,0x0($s0)
/*  f0950fc:	4606003c */ 	c.lt.s	$f0,$f6
/*  f095100:	00000000 */ 	nop
/*  f095104:	45020003 */ 	bc1fl	.L0f095114
/*  f095108:	93b8005c */ 	lbu	$t8,0x5c($sp)
/*  f09510c:	e6000000 */ 	swc1	$f0,0x0($s0)
/*  f095110:	93b8005c */ 	lbu	$t8,0x5c($sp)
.L0f095114:
/*  f095114:	e7a00070 */ 	swc1	$f0,0x70($sp)
/*  f095118:	3319ff7f */ 	andi	$t9,$t8,0xff7f
/*  f09511c:	a3b9005c */ 	sb	$t9,0x5c($sp)
/*  f095120:	87a9005c */ 	lh	$t1,0x5c($sp)
/*  f095124:	a7a9007a */ 	sh	$t1,0x7a($sp)
.L0f095128:
/*  f095128:	c7a00070 */ 	lwc1	$f0,0x70($sp)
/*  f09512c:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f095130:	87ab007a */ 	lh	$t3,0x7a($sp)
/*  f095134:	8fac007c */ 	lw	$t4,0x7c($sp)
/*  f095138:	44056000 */ 	mfc1	$a1,$f12
/*  f09513c:	44067000 */ 	mfc1	$a2,$f14
/*  f095140:	44070000 */ 	mfc1	$a3,$f0
/*  f095144:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f095148:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f09514c:	afa80050 */ 	sw	$t0,0x50($sp)
/*  f095150:	e7ac0068 */ 	swc1	$f12,0x68($sp)
/*  f095154:	e7ae006c */ 	swc1	$f14,0x6c($sp)
/*  f095158:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f09515c:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f095160:	0fc251ac */ 	jal	func0f0946b0
/*  f095164:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f095168:	c7a00070 */ 	lwc1	$f0,0x70($sp)
/*  f09516c:	c7ac0068 */ 	lwc1	$f12,0x68($sp)
/*  f095170:	c7ae006c */ 	lwc1	$f14,0x6c($sp)
/*  f095174:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f095178:	8fa80050 */ 	lw	$t0,0x50($sp)
/*  f09517c:	c6080000 */ 	lwc1	$f8,0x0($s0)
/*  f095180:	44070000 */ 	mfc1	$a3,$f0
/*  f095184:	44056000 */ 	mfc1	$a1,$f12
/*  f095188:	44067000 */ 	mfc1	$a2,$f14
/*  f09518c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f095190:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f095194:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f095198:	0fc2535e */ 	jal	func0f094d78
/*  f09519c:	e7a80010 */ 	swc1	$f8,0x10($sp)
/*  f0951a0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0951a4:	0c003ee8 */ 	jal	sndIsMp3
/*  f0951a8:	87a4007a */ 	lh	$a0,0x7a($sp)
/*  f0951ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0951b0:	44815000 */ 	mtc1	$at,$f10
/*  f0951b4:	87ad007a */ 	lh	$t5,0x7a($sp)
/*  f0951b8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0951bc:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0951c0:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0951c4:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0951c8:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0951cc:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0951d0:	27a40060 */ 	addiu	$a0,$sp,0x60
/*  f0951d4:	00402825 */ 	or	$a1,$v0,$zero
/*  f0951d8:	8fa6004c */ 	lw	$a2,0x4c($sp)
/*  f0951dc:	02003825 */ 	or	$a3,$s0,$zero
/*  f0951e0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0951e4:	0c004128 */ 	jal	sndAdjust
/*  f0951e8:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f0951ec:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0951f0:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f0951f4:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f0951f8:	03e00008 */ 	jr	$ra
/*  f0951fc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f095200
/*  f095200:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f095204:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f095208:	0c004b70 */ 	jal	random
/*  f09520c:	00000000 */ 	nop
/*  f095210:	3c0e8007 */ 	lui	$t6,%hi(var8006ae5c)
/*  f095214:	25ceae5c */ 	addiu	$t6,$t6,%lo(var8006ae5c)
/*  f095218:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f09521c:	27a30018 */ 	addiu	$v1,$sp,0x18
/*  f095220:	ac610000 */ 	sw	$at,0x0($v1)
/*  f095224:	8dd90004 */ 	lw	$t9,0x4($t6)
/*  f095228:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f09522c:	8dc10008 */ 	lw	$at,0x8($t6)
/*  f095230:	ac610008 */ 	sw	$at,0x8($v1)
/*  f095234:	24010006 */ 	addiu	$at,$zero,0x6
/*  f095238:	0041001b */ 	divu	$zero,$v0,$at
/*  f09523c:	00004010 */ 	mfhi	$t0
/*  f095240:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f095244:	00084840 */ 	sll	$t1,$t0,0x1
/*  f095248:	00695021 */ 	addu	$t2,$v1,$t1
/*  f09524c:	85420000 */ 	lh	$v0,0x0($t2)
/*  f095250:	03e00008 */ 	jr	$ra
/*  f095254:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f095258:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f09525c:	03e00008 */ 	jr	$ra
/*  f095260:	00801025 */ 	or	$v0,$a0,$zero
/*  f095264:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f095268:	03e00008 */ 	jr	$ra
/*  f09526c:	00801025 */ 	or	$v0,$a0,$zero
/*  f095270:	03e00008 */ 	jr	$ra
/*  f095274:	00000000 */ 	nop
);

s32 func0f095278(s32 channelnum)
{
	struct audiochannel *channel = &g_AudioChannels[channelnum];

	if (channelnum >= 0 && channelnum < (IS4MB() ? 30 : 40)
			&& (channel->flags & AUDIOCHANNELFLAG_IDLE) == 0
			&& (channel->flags & AUDIOCHANNELFLAG_0010)) {
		s32 soundnum = channel->soundnum26;
		return fileGetRomSizeByFileNum(soundnum & 0x7ff) * 60 / 3072;
	}

	return -1;
}
