#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraicommands.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/dlights.h"
#include "game/game_092610.h"
#include "game/game_096750.h"
#include "game/game_0dcdb0.h"
#include "game/game_166e40.h"
#include "game/core.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "gvars/gvars.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_16110.h"
#include "lib/lib_317f0.h"
#include "lib/lib_48830.h"
#include "lib/lib_4a360.h"
#include "types.h"

const char var7f1ab400[] = "Propsnd : USING TIME 60\n";
const char var7f1ab41c[] = "PS_AUTO : Un-Pausing %d\n";
const char var7f1ab438[] = "Propsnd : Using %d of %d (Peek = %d of %d)";
const char var7f1ab464[] = "AISOUND: aisoundnewtypeflags - Channel %d -> Playing sound number id=%d(%x)\n";
const char var7f1ab4b4[] = "AISOUND: PSTYPE_MARKER - Channel %d -> Playing sound number id=%d(%x)\n";
const char var7f1ab4fc[] = "AISOUND: PSTYPE_MARKER - Channel %d -> Playing sound number id=%d(%x)\n";
const char var7f1ab544[] = "AISOUND: CUTSCENE -> Playing sound number id=%d(%x))\n";
const char var7f1ab57c[] = "AISOUND: Channel %d -> Playing sound number id=%d(%x), Prop=%x, Flags=%x, Type=%d, Zero=%d\n";
const char var7f1ab5d8[] = "AISOUND: Channel %d -> Playing sound number id=%d(%x), Prop=%x, Flags=%x, Type=%d\n";
const char var7f1ab62c[] = "AISOUND: CUTSCENE -> Stopping all cutscene sounds\n";
const char var7f1ab660[] = "AISOUND: Stop sound channel %d\n";
const char var7f1ab680[] = "AISOUND: Channel %d -> Setting params : Vol=%d, Pad=%d, Prop=%x, Time=%d, Far=%d, Silence=%d, Flags=%u\n";
const char var7f1ab6e8[] = "AISOUND : This channel has a marker -> Shall start and use ID = %d(%x)\n";

const u32 var7f1ab730[] = {0x45abe800};
const u32 var7f1ab734[] = {0x45b54800};
const u32 var7f1ab738[] = {0x45bb8000};
const u32 var7f1ab73c[] = {0x392ec33e};
const u32 var7f1ab740[] = {0x3c23d70a};
const u32 var7f1ab744[] = {0x451c4000};
const u32 var7f1ab748[] = {0x453b8000};
const u32 var7f1ab74c[] = {0x3f2aaaab};
const u32 var7f1ab750[] = {0x3f333333};
const u32 var7f1ab754[] = {0x3f333333};
const u32 var7f1ab758[] = {0x40490fdb};
const u32 var7f1ab75c[] = {0x3c8efa35};
const u32 var7f1ab760[] = {0x40490fdb};
const u32 var7f1ab764[] = {0x40490fdb};
const u32 var7f1ab768[] = {0x42652ee0};
const u32 var7f1ab76c[] = {0x451c4000};
const u32 var7f1ab770[] = {0x453b8000};
const u32 var7f1ab774[] = {0x45abe800};
const u32 var7f1ab778[] = {0x45b54800};
const u32 var7f1ab77c[] = {0x451c4000};
const u32 var7f1ab780[] = {0x453b8000};
const u32 var7f1ab784[] = {0x4b18967f};
const u32 var7f1ab788[] = {0x4b18967f};
const u32 var7f1ab78c[] = {0x00000000};

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

GLOBAL_ASM(
glabel func0f0927d4
/*  f0927d4:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0927d8:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f0927dc:	4487b000 */ 	mtc1	$a3,$f22
/*  f0927e0:	f7b80020 */ 	sdc1	$f24,0x20($sp)
/*  f0927e4:	4486c000 */ 	mtc1	$a2,$f24
/*  f0927e8:	4616603c */ 	c.lt.s	$f12,$f22
/*  f0927ec:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f0927f0:	46006506 */ 	mov.s	$f20,$f12
/*  f0927f4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0927f8:	45000038 */ 	bc1f	.L0f0928dc
/*  f0927fc:	00001825 */ 	or	$v1,$zero,$zero
/*  f092800:	3c017f1b */ 	lui	$at,%hi(var7f1ab730)
/*  f092804:	c420b730 */ 	lwc1	$f0,%lo(var7f1ab730)($at)
/*  f092808:	3c017f1b */ 	lui	$at,%hi(var7f1ab734)
/*  f09280c:	460e003c */ 	c.lt.s	$f0,$f14
/*  f092810:	00000000 */ 	nop
/*  f092814:	45000002 */ 	bc1f	.L0f092820
/*  f092818:	00000000 */ 	nop
/*  f09281c:	46000386 */ 	mov.s	$f14,$f0
.L0f092820:
/*  f092820:	c420b734 */ 	lwc1	$f0,%lo(var7f1ab734)($at)
/*  f092824:	3c017f1b */ 	lui	$at,%hi(var7f1ab738)
/*  f092828:	4618003c */ 	c.lt.s	$f0,$f24
/*  f09282c:	00000000 */ 	nop
/*  f092830:	45000002 */ 	bc1f	.L0f09283c
/*  f092834:	00000000 */ 	nop
/*  f092838:	46000606 */ 	mov.s	$f24,$f0
.L0f09283c:
/*  f09283c:	c420b738 */ 	lwc1	$f0,%lo(var7f1ab738)($at)
/*  f092840:	4616003c */ 	c.lt.s	$f0,$f22
/*  f092844:	00000000 */ 	nop
/*  f092848:	45020003 */ 	bc1fl	.L0f092858
/*  f09284c:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f092850:	46000586 */ 	mov.s	$f22,$f0
/*  f092854:	460ea03c */ 	c.lt.s	$f20,$f14
.L0f092858:
/*  f092858:	00000000 */ 	nop
/*  f09285c:	45020004 */ 	bc1fl	.L0f092870
/*  f092860:	4618a03c */ 	c.lt.s	$f20,$f24
/*  f092864:	1000001d */ 	b	.L0f0928dc
/*  f092868:	8fa30040 */ 	lw	$v1,0x40($sp)
/*  f09286c:	4618a03c */ 	c.lt.s	$f20,$f24
.L0f092870:
/*  f092870:	3c01447a */ 	lui	$at,0x447a
/*  f092874:	45020012 */ 	bc1fl	.L0f0928c0
/*  f092878:	4614b201 */ 	sub.s	$f8,$f22,$f20
/*  f09287c:	460ea101 */ 	sub.s	$f4,$f20,$f14
/*  f092880:	460ec181 */ 	sub.s	$f6,$f24,$f14
/*  f092884:	0c012974 */ 	jal	sqrtf
/*  f092888:	46062303 */ 	div.s	$f12,$f4,$f6
/*  f09288c:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f092890:	3c01447a */ 	lui	$at,0x447a
/*  f092894:	44818000 */ 	mtc1	$at,$f16
/*  f092898:	44824000 */ 	mtc1	$v0,$f8
/*  f09289c:	00000000 */ 	nop
/*  f0928a0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0928a4:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0928a8:	46120102 */ 	mul.s	$f4,$f0,$f18
/*  f0928ac:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0928b0:	440f3000 */ 	mfc1	$t7,$f6
/*  f0928b4:	10000009 */ 	b	.L0f0928dc
/*  f0928b8:	004f1823 */ 	subu	$v1,$v0,$t7
/*  f0928bc:	4614b201 */ 	sub.s	$f8,$f22,$f20
.L0f0928c0:
/*  f0928c0:	44815000 */ 	mtc1	$at,$f10
/*  f0928c4:	4618b481 */ 	sub.s	$f18,$f22,$f24
/*  f0928c8:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0928cc:	46128103 */ 	div.s	$f4,$f16,$f18
/*  f0928d0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0928d4:	44033000 */ 	mfc1	$v1,$f6
/*  f0928d8:	00000000 */ 	nop
.L0f0928dc:
/*  f0928dc:	34018000 */ 	dli	$at,0x8000
/*  f0928e0:	0061082a */ 	slt	$at,$v1,$at
/*  f0928e4:	14200002 */ 	bnez	$at,.L0f0928f0
/*  f0928e8:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f0928ec:	24037fff */ 	addiu	$v1,$zero,0x7fff
.L0f0928f0:
/*  f0928f0:	28610028 */ 	slti	$at,$v1,0x28
/*  f0928f4:	10200002 */ 	beqz	$at,.L0f092900
/*  f0928f8:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f0928fc:	00001825 */ 	or	$v1,$zero,$zero
.L0f092900:
/*  f092900:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f092904:	d7b80020 */ 	ldc1	$f24,0x20($sp)
/*  f092908:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f09290c:	03e00008 */ 	jr	$ra
/*  f092910:	00601025 */ 	or	$v0,$v1,$zero
);

s32 channelGetUnk06(s32 channelnum)
{
	return (channelnum >= 0 && channelnum <= 7) ? g_AudioChannels[channelnum].unk06 : 0;
}

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

GLOBAL_ASM(
glabel func0f092a98
/*  f092a98:	3c0f8007 */ 	lui	$t7,%hi(g_AudioChannels)
/*  f092a9c:	8defae10 */ 	lw	$t7,%lo(g_AudioChannels)($t7)
/*  f092aa0:	00047100 */ 	sll	$t6,$a0,0x4
/*  f092aa4:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f092aa8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f092aac:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f092ab0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f092ab4:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f092ab8:	94780032 */ 	lhu	$t8,0x32($v1)
/*  f092abc:	94620030 */ 	lhu	$v0,0x30($v1)
/*  f092ac0:	37190080 */ 	ori	$t9,$t8,0x80
/*  f092ac4:	30480200 */ 	andi	$t0,$v0,0x200
/*  f092ac8:	11000005 */ 	beqz	$t0,.L0f092ae0
/*  f092acc:	a4790032 */ 	sh	$t9,0x32($v1)
/*  f092ad0:	0fc37751 */ 	jal	func0f0ddd44
/*  f092ad4:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f092ad8:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f092adc:	94620030 */ 	lhu	$v0,0x30($v1)
.L0f092ae0:
/*  f092ae0:	30490008 */ 	andi	$t1,$v0,0x8
/*  f092ae4:	51200007 */ 	beqzl	$t1,.L0f092b04
/*  f092ae8:	304a0010 */ 	andi	$t2,$v0,0x10
/*  f092aec:	8c640050 */ 	lw	$a0,0x50($v1)
/*  f092af0:	0fc16af7 */ 	jal	func0f05abdc
/*  f092af4:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f092af8:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f092afc:	94620030 */ 	lhu	$v0,0x30($v1)
/*  f092b00:	304a0010 */ 	andi	$t2,$v0,0x10
.L0f092b04:
/*  f092b04:	51400006 */ 	beqzl	$t2,.L0f092b20
/*  f092b08:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f092b0c:	0c003ef1 */ 	jal	func0000fbc4
/*  f092b10:	84640026 */ 	lh	$a0,0x26($v1)
/*  f092b14:	1000000b */ 	b	.L0f092b44
/*  f092b18:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f092b1c:	8c640000 */ 	lw	$a0,0x0($v1)
.L0f092b20:
/*  f092b20:	50800008 */ 	beqzl	$a0,.L0f092b44
/*  f092b24:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f092b28:	0c00cdfc */ 	jal	audioIsPlaying
/*  f092b2c:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f092b30:	10400003 */ 	beqz	$v0,.L0f092b40
/*  f092b34:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f092b38:	0c00cec9 */ 	jal	audioStop
/*  f092b3c:	8c640000 */ 	lw	$a0,0x0($v1)
.L0f092b40:
/*  f092b40:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f092b44:
/*  f092b44:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f092b48:	03e00008 */ 	jr	$ra
/*  f092b4c:	00000000 */ 	nop
);

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

GLOBAL_ASM(
glabel func0f092c04
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
/*  f092c94:	0c003a74 */ 	jal	func0000e9d0
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
/*  f09303c:	0fc5b364 */ 	jal	coreIsPaused
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
/*  f093350:	0c0042b9 */ 	jal	func00010ae4
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
/*  f093398:	0c0041c6 */ 	jal	func00010718
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
/*  f0933d4:	0c0041c6 */ 	jal	func00010718
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
/*  f093414:	0c004128 */ 	jal	audioAdjust
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
/*  f093444:	0c003a74 */ 	jal	func0000e9d0
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
/*  f09347c:	0fc37751 */ 	jal	func0f0ddd44
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
/*  f093698:	3c158009 */ 	lui	$s5,%hi(g_AudioThread)
/*  f09369c:	3c138007 */ 	lui	$s3,%hi(g_AudioChannels)
/*  f0936a0:	2673ae10 */ 	addiu	$s3,$s3,%lo(g_AudioChannels)
/*  f0936a4:	26b515e0 */ 	addiu	$s5,$s5,%lo(g_AudioThread)
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
/*  f0937f0:	3c168009 */ 	lui	$s6,%hi(g_AudioThread)
/*  f0937f4:	3c158007 */ 	lui	$s5,%hi(g_AudioChannels)
/*  f0937f8:	26b5ae10 */ 	addiu	$s5,$s5,%lo(g_AudioChannels)
/*  f0937fc:	26d615e0 */ 	addiu	$s6,$s6,%lo(g_AudioThread)
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

GLOBAL_ASM(
glabel func0f0939f8
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
/*  f093b1c:	3c038007 */ 	lui	$v1,%hi(var8006ae14)
/*  f093b20:	2463ae14 */ 	addiu	$v1,$v1,%lo(var8006ae14)
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
/*  f093c88:	3c0c8006 */ 	lui	$t4,%hi(audiodefinitions)
/*  f093c8c:	258cdde4 */ 	addiu	$t4,$t4,%lo(audiodefinitions)
/*  f093c90:	308a7fff */ 	andi	$t2,$a0,0x7fff
/*  f093c94:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f093c98:	016c1021 */ 	addu	$v0,$t3,$t4
/*  f093c9c:	94450002 */ 	lhu	$a1,0x2($v0)
/*  f093ca0:	3c0e8006 */ 	lui	$t6,%hi(audioconfigs)
/*  f093ca4:	25cee4d8 */ 	addiu	$t6,$t6,%lo(audioconfigs)
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
/*  f093e40:	0c004103 */ 	jal	audioIsFiltered
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
/*  f093f68:	0c003ee8 */ 	jal	func0000fba0
/*  f093f6c:	87a400ba */ 	lh	$a0,0xba($sp)
/*  f093f70:	10400014 */ 	beqz	$v0,.L0f093fc4
/*  f093f74:	00000000 */ 	nop
/*  f093f78:	960e0030 */ 	lhu	$t6,0x30($s0)
/*  f093f7c:	00002025 */ 	or	$a0,$zero,$zero
/*  f093f80:	35cf0010 */ 	ori	$t7,$t6,0x10
/*  f093f84:	0c012230 */ 	jal	osGetThreadPri
/*  f093f88:	a60f0030 */ 	sh	$t7,0x30($s0)
/*  f093f8c:	3c048009 */ 	lui	$a0,%hi(g_AudioThread)
/*  f093f90:	afa200a8 */ 	sw	$v0,0xa8($sp)
/*  f093f94:	0c012230 */ 	jal	osGetThreadPri
/*  f093f98:	248415e0 */ 	addiu	$a0,$a0,%lo(g_AudioThread)
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
/*  f093fcc:	3c048009 */ 	lui	$a0,%hi(g_AudioThread)
/*  f093fd0:	afa200a8 */ 	sw	$v0,0xa8($sp)
/*  f093fd4:	0c012230 */ 	jal	osGetThreadPri
/*  f093fd8:	248415e0 */ 	addiu	$a0,$a0,%lo(g_AudioThread)
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

GLOBAL_ASM(
glabel audioPlayFromProp
/*  f094040:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f094044:	87ae0072 */ 	lh	$t6,0x72($sp)
/*  f094048:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f09404c:	240a000b */ 	addiu	$t2,$zero,0xb
/*  f094050:	00808025 */ 	or	$s0,$a0,$zero
/*  f094054:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f094058:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f09405c:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f094060:	15ca0027 */ 	bne	$t6,$t2,.L0f094100
/*  f094064:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f094068:	04800094 */ 	bltz	$a0,.L0f0942bc
/*  f09406c:	28810008 */ 	slti	$at,$a0,0x8
/*  f094070:	10200092 */ 	beqz	$at,.L0f0942bc
/*  f094074:	3c098007 */ 	lui	$t1,%hi(g_AudioChannels)
/*  f094078:	2529ae10 */ 	addiu	$t1,$t1,%lo(g_AudioChannels)
/*  f09407c:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f094080:	00041900 */ 	sll	$v1,$a0,0x4
/*  f094084:	00641823 */ 	subu	$v1,$v1,$a0
/*  f094088:	000318c0 */ 	sll	$v1,$v1,0x3
/*  f09408c:	01e31021 */ 	addu	$v0,$t7,$v1
/*  f094090:	94580030 */ 	lhu	$t8,0x30($v0)
/*  f094094:	87ab0066 */ 	lh	$t3,0x66($sp)
/*  f094098:	33190001 */ 	andi	$t9,$t8,0x1
/*  f09409c:	5320000d */ 	beqzl	$t9,.L0f0940d4
/*  f0940a0:	87b90066 */ 	lh	$t9,0x66($sp)
/*  f0940a4:	a44b0026 */ 	sh	$t3,0x26($v0)
/*  f0940a8:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f0940ac:	00804025 */ 	or	$t0,$a0,$zero
/*  f0940b0:	01836821 */ 	addu	$t5,$t4,$v1
/*  f0940b4:	a5aa0028 */ 	sh	$t2,0x28($t5)
/*  f0940b8:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f0940bc:	01c31021 */ 	addu	$v0,$t6,$v1
/*  f0940c0:	944f0030 */ 	lhu	$t7,0x30($v0)
/*  f0940c4:	31f8fffe */ 	andi	$t8,$t7,0xfffe
/*  f0940c8:	1000007c */ 	b	.L0f0942bc
/*  f0940cc:	a4580030 */ 	sh	$t8,0x30($v0)
/*  f0940d0:	87b90066 */ 	lh	$t9,0x66($sp)
.L0f0940d4:
/*  f0940d4:	02004025 */ 	or	$t0,$s0,$zero
/*  f0940d8:	a4590026 */ 	sh	$t9,0x26($v0)
/*  f0940dc:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*  f0940e0:	01636021 */ 	addu	$t4,$t3,$v1
/*  f0940e4:	a58a0028 */ 	sh	$t2,0x28($t4)
/*  f0940e8:	8d2d0000 */ 	lw	$t5,0x0($t1)
/*  f0940ec:	01a31021 */ 	addu	$v0,$t5,$v1
/*  f0940f0:	944e0030 */ 	lhu	$t6,0x30($v0)
/*  f0940f4:	31cffffe */ 	andi	$t7,$t6,0xfffe
/*  f0940f8:	10000070 */ 	b	.L0f0942bc
/*  f0940fc:	a44f0030 */ 	sh	$t7,0x30($v0)
.L0f094100:
/*  f094100:	2401000a */ 	addiu	$at,$zero,0xa
/*  f094104:	1601001c */ 	bne	$s0,$at,.L0f094178
/*  f094108:	00002025 */ 	or	$a0,$zero,$zero
/*  f09410c:	10c00003 */ 	beqz	$a2,.L0f09411c
/*  f094110:	3c01bf80 */ 	lui	$at,0xbf80
/*  f094114:	10000002 */ 	b	.L0f094120
/*  f094118:	00001025 */ 	or	$v0,$zero,$zero
.L0f09411c:
/*  f09411c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f094120:
/*  f094120:	44810000 */ 	mtc1	$at,$f0
/*  f094124:	97b80076 */ 	lhu	$t8,0x76($sp)
/*  f094128:	87ab0072 */ 	lh	$t3,0x72($sp)
/*  f09412c:	240cffff */ 	addiu	$t4,$zero,-1
/*  f094130:	37190080 */ 	ori	$t9,$t8,0x80
/*  f094134:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f094138:	afac002c */ 	sw	$t4,0x2c($sp)
/*  f09413c:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f094140:	87a60066 */ 	lh	$a2,0x66($sp)
/*  f094144:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f094148:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f09414c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f094150:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f094154:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f094158:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f09415c:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f094160:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f094164:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f094168:	0fc24e7e */ 	jal	func0f0939f8
/*  f09416c:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f094170:	10000052 */ 	b	.L0f0942bc
/*  f094174:	00404025 */ 	or	$t0,$v0,$zero
.L0f094178:
/*  f094178:	06000005 */ 	bltz	$s0,.L0f094190
/*  f09417c:	2a010008 */ 	slti	$at,$s0,0x8
/*  f094180:	10200003 */ 	beqz	$at,.L0f094190
/*  f094184:	24010009 */ 	addiu	$at,$zero,0x9
/*  f094188:	1601001c */ 	bne	$s0,$at,.L0f0941fc
/*  f09418c:	3c098007 */ 	lui	$t1,%hi(g_AudioChannels)
.L0f094190:
/*  f094190:	10c00003 */ 	beqz	$a2,.L0f0941a0
/*  f094194:	3c01bf80 */ 	lui	$at,0xbf80
/*  f094198:	10000002 */ 	b	.L0f0941a4
/*  f09419c:	00001025 */ 	or	$v0,$zero,$zero
.L0f0941a0:
/*  f0941a0:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f0941a4:
/*  f0941a4:	44810000 */ 	mtc1	$at,$f0
/*  f0941a8:	97ad0076 */ 	lhu	$t5,0x76($sp)
/*  f0941ac:	87ae0072 */ 	lh	$t6,0x72($sp)
/*  f0941b0:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0941b4:	afaf002c */ 	sw	$t7,0x2c($sp)
/*  f0941b8:	00002025 */ 	or	$a0,$zero,$zero
/*  f0941bc:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f0941c0:	87a60066 */ 	lh	$a2,0x66($sp)
/*  f0941c4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f0941c8:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0941cc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0941d0:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0941d4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0941d8:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0941dc:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0941e0:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0941e4:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0941e8:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f0941ec:	0fc24e7e */ 	jal	func0f0939f8
/*  f0941f0:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0941f4:	10000031 */ 	b	.L0f0942bc
/*  f0941f8:	00404025 */ 	or	$t0,$v0,$zero
.L0f0941fc:
/*  f0941fc:	2529ae10 */ 	addiu	$t1,$t1,%lo(g_AudioChannels)
/*  f094200:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f094204:	00101900 */ 	sll	$v1,$s0,0x4
/*  f094208:	00701823 */ 	subu	$v1,$v1,$s0
/*  f09420c:	000318c0 */ 	sll	$v1,$v1,0x3
/*  f094210:	03031021 */ 	addu	$v0,$t8,$v1
/*  f094214:	94590030 */ 	lhu	$t9,0x30($v0)
/*  f094218:	02002025 */ 	or	$a0,$s0,$zero
/*  f09421c:	332b0001 */ 	andi	$t3,$t9,0x1
/*  f094220:	1560000a */ 	bnez	$t3,.L0f09424c
/*  f094224:	00000000 */ 	nop
/*  f094228:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f09422c:	0fc24aa6 */ 	jal	func0f092a98
/*  f094230:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f094234:	3c098007 */ 	lui	$t1,%hi(g_AudioChannels)
/*  f094238:	2529ae10 */ 	addiu	$t1,$t1,%lo(g_AudioChannels)
/*  f09423c:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*  f094240:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f094244:	8fa60068 */ 	lw	$a2,0x68($sp)
/*  f094248:	01831021 */ 	addu	$v0,$t4,$v1
.L0f09424c:
/*  f09424c:	10c00003 */ 	beqz	$a2,.L0f09425c
/*  f094250:	a450002e */ 	sh	$s0,0x2e($v0)
/*  f094254:	10000002 */ 	b	.L0f094260
/*  f094258:	00001025 */ 	or	$v0,$zero,$zero
.L0f09425c:
/*  f09425c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f094260:
/*  f094260:	3c01bf80 */ 	lui	$at,0xbf80
/*  f094264:	44810000 */ 	mtc1	$at,$f0
/*  f094268:	8d2d0000 */ 	lw	$t5,0x0($t1)
/*  f09426c:	97ae0076 */ 	lhu	$t6,0x76($sp)
/*  f094270:	87af0072 */ 	lh	$t7,0x72($sp)
/*  f094274:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f094278:	afb8002c */ 	sw	$t8,0x2c($sp)
/*  f09427c:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f094280:	87a60066 */ 	lh	$a2,0x66($sp)
/*  f094284:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f094288:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f09428c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f094290:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f094294:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f094298:	006d2021 */ 	addu	$a0,$v1,$t5
/*  f09429c:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f0942a0:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f0942a4:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f0942a8:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f0942ac:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0942b0:	0fc24e7e */ 	jal	func0f0939f8
/*  f0942b4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0942b8:	02004025 */ 	or	$t0,$s0,$zero
.L0f0942bc:
/*  f0942bc:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0942c0:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f0942c4:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f0942c8:	03e00008 */ 	jr	$ra
/*  f0942cc:	01001025 */ 	or	$v0,$t0,$zero
);

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

GLOBAL_ASM(
glabel audioPlayFromProp2
/*  f094494:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f094498:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f09449c:	3c0a8007 */ 	lui	$t2,%hi(g_AudioChannels)
/*  f0944a0:	254aae10 */ 	addiu	$t2,$t2,%lo(g_AudioChannels)
/*  f0944a4:	0004c100 */ 	sll	$t8,$a0,0x4
/*  f0944a8:	8d480000 */ 	lw	$t0,0x0($t2)
/*  f0944ac:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f0944b0:	afa60060 */ 	sw	$a2,0x60($sp)
/*  f0944b4:	00067400 */ 	sll	$t6,$a2,0x10
/*  f0944b8:	001818c0 */ 	sll	$v1,$t8,0x3
/*  f0944bc:	2b210006 */ 	slti	$at,$t9,0x6
/*  f0944c0:	000e3403 */ 	sra	$a2,$t6,0x10
/*  f0944c4:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0944c8:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f0944cc:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f0944d0:	afa70064 */ 	sw	$a3,0x64($sp)
/*  f0944d4:	14200003 */ 	bnez	$at,.L0f0944e4
/*  f0944d8:	00681021 */ 	addu	$v0,$v1,$t0
/*  f0944dc:	10000002 */ 	b	.L0f0944e8
/*  f0944e0:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0944e4:
/*  f0944e4:	00002825 */ 	or	$a1,$zero,$zero
.L0f0944e8:
/*  f0944e8:	97a90076 */ 	lhu	$t1,0x76($sp)
/*  f0944ec:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f0944f0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0944f4:	312b0002 */ 	andi	$t3,$t1,0x2
/*  f0944f8:	11600003 */ 	beqz	$t3,.L0f094508
/*  f0944fc:	29810008 */ 	slti	$at,$t4,0x8
/*  f094500:	10000001 */ 	b	.L0f094508
/*  f094504:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f094508:
/*  f094508:	05820066 */ 	bltzl	$t4,.L0f0946a4
/*  f09450c:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f094510:	50200064 */ 	beqzl	$at,.L0f0946a4
/*  f094514:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f094518:	844d0028 */ 	lh	$t5,0x28($v0)
/*  f09451c:	2401000b */ 	addiu	$at,$zero,0xb
/*  f094520:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f094524:	15a10021 */ 	bne	$t5,$at,.L0f0945ac
/*  f094528:	01037821 */ 	addu	$t7,$t0,$v1
/*  f09452c:	a5ee002e */ 	sh	$t6,0x2e($t7)
/*  f094530:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f094534:	8fac006c */ 	lw	$t4,0x6c($sp)
/*  f094538:	84460026 */ 	lh	$a2,0x26($v0)
/*  f09453c:	448d8000 */ 	mtc1	$t5,$f16
/*  f094540:	448c4000 */ 	mtc1	$t4,$f8
/*  f094544:	3c01bf80 */ 	lui	$at,0xbf80
/*  f094548:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f09454c:	44812000 */ 	mtc1	$at,$f4
/*  f094550:	3c0143c8 */ 	lui	$at,0x43c8
/*  f094554:	44813000 */ 	mtc1	$at,$f6
/*  f094558:	8d580000 */ 	lw	$t8,0x0($t2)
/*  f09455c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f094560:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f094564:	240bffff */ 	addiu	$t3,$zero,-1
/*  f094568:	afab002c */ 	sw	$t3,0x2c($sp)
/*  f09456c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f094570:	e7b20038 */ 	swc1	$f18,0x38($sp)
/*  f094574:	e7aa0034 */ 	swc1	$f10,0x34($sp)
/*  f094578:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f09457c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f094580:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f094584:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f094588:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f09458c:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f094590:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f094594:	e7a40024 */ 	swc1	$f4,0x24($sp)
/*  f094598:	00782021 */ 	addu	$a0,$v1,$t8
/*  f09459c:	0fc24e7e */ 	jal	func0f0939f8
/*  f0945a0:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f0945a4:	1000003f */ 	b	.L0f0946a4
/*  f0945a8:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f0945ac:
/*  f0945ac:	944e0030 */ 	lhu	$t6,0x30($v0)
/*  f0945b0:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*  f0945b4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0945b8:	31cf2000 */ 	andi	$t7,$t6,0x2000
/*  f0945bc:	15e00004 */ 	bnez	$t7,.L0f0945d0
/*  f0945c0:	00000000 */ 	nop
/*  f0945c4:	07000002 */ 	bltz	$t8,.L0f0945d0
/*  f0945c8:	00000000 */ 	nop
/*  f0945cc:	a4580004 */ 	sh	$t8,0x4($v0)
.L0f0945d0:
/*  f0945d0:	10a00002 */ 	beqz	$a1,.L0f0945dc
/*  f0945d4:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f0945d8:	ac59001c */ 	sw	$t9,0x1c($v0)
.L0f0945dc:
/*  f0945dc:	50c10003 */ 	beql	$a2,$at,.L0f0945ec
/*  f0945e0:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f0945e4:	a4460024 */ 	sh	$a2,0x24($v0)
/*  f0945e8:	8fab0064 */ 	lw	$t3,0x64($sp)
.L0f0945ec:
/*  f0945ec:	3c0143c8 */ 	lui	$at,0x43c8
/*  f0945f0:	11600002 */ 	beqz	$t3,.L0f0945fc
/*  f0945f4:	00000000 */ 	nop
/*  f0945f8:	ac4b0050 */ 	sw	$t3,0x50($v0)
.L0f0945fc:
/*  f0945fc:	10800004 */ 	beqz	$a0,.L0f094610
/*  f094600:	94430030 */ 	lhu	$v1,0x30($v0)
/*  f094604:	346c0002 */ 	ori	$t4,$v1,0x2
/*  f094608:	a44c0030 */ 	sh	$t4,0x30($v0)
/*  f09460c:	3183ffff */ 	andi	$v1,$t4,0xffff
.L0f094610:
/*  f094610:	306d0040 */ 	andi	$t5,$v1,0x40
/*  f094614:	15a0000f */ 	bnez	$t5,.L0f094654
/*  f094618:	00000000 */ 	nop
/*  f09461c:	44812000 */ 	mtc1	$at,$f4
/*  f094620:	00000000 */ 	nop
/*  f094624:	e4440034 */ 	swc1	$f4,0x34($v0)
/*  f094628:	8fae006c */ 	lw	$t6,0x6c($sp)
/*  f09462c:	448e3000 */ 	mtc1	$t6,$f6
/*  f094630:	00000000 */ 	nop
/*  f094634:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f094638:	e4480038 */ 	swc1	$f8,0x38($v0)
/*  f09463c:	8faf0070 */ 	lw	$t7,0x70($sp)
/*  f094640:	a4400018 */ 	sh	$zero,0x18($v0)
/*  f094644:	448f5000 */ 	mtc1	$t7,$f10
/*  f094648:	00000000 */ 	nop
/*  f09464c:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f094650:	e450003c */ 	swc1	$f16,0x3c($v0)
.L0f094654:
/*  f094654:	10a00004 */ 	beqz	$a1,.L0f094668
/*  f094658:	00000000 */ 	nop
/*  f09465c:	8c58001c */ 	lw	$t8,0x1c($v0)
/*  f094660:	57000010 */ 	bnezl	$t8,.L0f0946a4
/*  f094664:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f094668:
/*  f094668:	0c012230 */ 	jal	osGetThreadPri
/*  f09466c:	00002025 */ 	or	$a0,$zero,$zero
/*  f094670:	3c048009 */ 	lui	$a0,%hi(g_AudioThread)
/*  f094674:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f094678:	0c012230 */ 	jal	osGetThreadPri
/*  f09467c:	248415e0 */ 	addiu	$a0,$a0,%lo(g_AudioThread)
/*  f094680:	00002025 */ 	or	$a0,$zero,$zero
/*  f094684:	0c01210c */ 	jal	osSetThreadPri
/*  f094688:	24450001 */ 	addiu	$a1,$v0,0x1
/*  f09468c:	0fc24b01 */ 	jal	func0f092c04
/*  f094690:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f094694:	00002025 */ 	or	$a0,$zero,$zero
/*  f094698:	0c01210c */ 	jal	osSetThreadPri
/*  f09469c:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f0946a0:	8fbf0044 */ 	lw	$ra,0x44($sp)
.L0f0946a4:
/*  f0946a4:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f0946a8:	03e00008 */ 	jr	$ra
/*  f0946ac:	00000000 */ 	nop
);

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
/*  f094724:	3c0d8006 */ 	lui	$t5,%hi(audiodefinitions)
/*  f094728:	25addde4 */ 	addiu	$t5,$t5,%lo(audiodefinitions)
/*  f09472c:	000b6080 */ 	sll	$t4,$t3,0x2
/*  f094730:	018d1821 */ 	addu	$v1,$t4,$t5
/*  f094734:	94650002 */ 	lhu	$a1,0x2($v1)
/*  f094738:	3c188006 */ 	lui	$t8,%hi(audioconfigs)
/*  f09473c:	2718e4d8 */ 	addiu	$t8,$t8,%lo(audioconfigs)
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

GLOBAL_ASM(
glabel func0f094940
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
/*  f094bd0:	0fc259d4 */ 	jal	func0f096750
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
/*  f094c84:	0fc259d4 */ 	jal	func0f096750
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

GLOBAL_ASM(
glabel func0f094ef4
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
/*  f094f50:	3c0a8006 */ 	lui	$t2,%hi(audiodefinitions)
/*  f094f54:	254adde4 */ 	addiu	$t2,$t2,%lo(audiodefinitions)
/*  f094f58:	00194880 */ 	sll	$t1,$t9,0x2
/*  f094f5c:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f094f60:	94650002 */ 	lhu	$a1,0x2($v1)
/*  f094f64:	3c0c8006 */ 	lui	$t4,%hi(audioconfigs)
/*  f094f68:	258ce4d8 */ 	addiu	$t4,$t4,%lo(audioconfigs)
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

GLOBAL_ASM(
glabel func0f09505c
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
/*  f0950a4:	3c0a8006 */ 	lui	$t2,%hi(audiodefinitions)
/*  f0950a8:	000fc7c2 */ 	srl	$t8,$t7,0x1f
/*  f0950ac:	1300001e */ 	beqz	$t8,.L0f095128
/*  f0950b0:	30997fff */ 	andi	$t9,$a0,0x7fff
/*  f0950b4:	00194880 */ 	sll	$t1,$t9,0x2
/*  f0950b8:	254adde4 */ 	addiu	$t2,$t2,%lo(audiodefinitions)
/*  f0950bc:	012a1821 */ 	addu	$v1,$t1,$t2
/*  f0950c0:	94650002 */ 	lhu	$a1,0x2($v1)
/*  f0950c4:	3c0c8006 */ 	lui	$t4,%hi(audioconfigs)
/*  f0950c8:	258ce4d8 */ 	addiu	$t4,$t4,%lo(audioconfigs)
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
/*  f0951a4:	0c003ee8 */ 	jal	func0000fba0
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
/*  f0951e4:	0c004128 */ 	jal	audioAdjust
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

GLOBAL_ASM(
glabel func0f095278
/*  f095278:	00047100 */ 	sll	$t6,$a0,0x4
/*  f09527c:	3c0f8007 */ 	lui	$t7,%hi(g_AudioChannels)
/*  f095280:	8defae10 */ 	lw	$t7,%lo(g_AudioChannels)($t7)
/*  f095284:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f095288:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f09528c:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f095290:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f095294:	0480001d */ 	bltz	$a0,.L0f09530c
/*  f095298:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f09529c:	3c188009 */ 	lui	$t8,%hi(g_Is4Mb)
/*  f0952a0:	93180af0 */ 	lbu	$t8,%lo(g_Is4Mb)($t8)
/*  f0952a4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0952a8:	24020028 */ 	addiu	$v0,$zero,0x28
/*  f0952ac:	17010003 */ 	bne	$t8,$at,.L0f0952bc
/*  f0952b0:	00000000 */ 	nop
/*  f0952b4:	10000001 */ 	b	.L0f0952bc
/*  f0952b8:	2402001e */ 	addiu	$v0,$zero,0x1e
.L0f0952bc:
/*  f0952bc:	0082082a */ 	slt	$at,$a0,$v0
/*  f0952c0:	50200013 */ 	beqzl	$at,.L0f095310
/*  f0952c4:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0952c8:	94620030 */ 	lhu	$v0,0x30($v1)
/*  f0952cc:	30590001 */ 	andi	$t9,$v0,0x1
/*  f0952d0:	1720000e */ 	bnez	$t9,.L0f09530c
/*  f0952d4:	30480010 */ 	andi	$t0,$v0,0x10
/*  f0952d8:	5100000d */ 	beqzl	$t0,.L0f095310
/*  f0952dc:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0952e0:	84620026 */ 	lh	$v0,0x26($v1)
/*  f0952e4:	0fc59b9f */ 	jal	fileGetRomSizeByFileNum
/*  f0952e8:	304407ff */ 	andi	$a0,$v0,0x7ff
/*  f0952ec:	00024900 */ 	sll	$t1,$v0,0x4
/*  f0952f0:	01224823 */ 	subu	$t1,$t1,$v0
/*  f0952f4:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0952f8:	24010c00 */ 	addiu	$at,$zero,0xc00
/*  f0952fc:	0121001a */ 	div	$zero,$t1,$at
/*  f095300:	00001012 */ 	mflo	$v0
/*  f095304:	10000003 */ 	b	.L0f095314
/*  f095308:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f09530c:
/*  f09530c:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f095310:
/*  f095310:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f095314:
/*  f095314:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f095318:	03e00008 */ 	jr	$ra
/*  f09531c:	00000000 */ 	nop
);
