#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_005fd0.h"
#include "game/game_097ba0.h"
#include "game/game_0b3350.h"
#include "game/game_0d4690.h"
#include "game/game_0e0770.h"
#include "game/game_1531a0.h"
#include "game/game_166e40.h"
#include "game/utils.h"
#include "gvars/gvars.h"
#include "lib/lib_09660.h"
#include "lib/main.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "types.h"

const u32 var7f1adf00[] = {0x63636363};
const u32 var7f1adf04[] = {0x00000000};

const u32 var7f1adf08[] = {0x40c907a9};
const u32 var7f1adf0c[] = {0x3e4ccccd};
const u32 var7f1adf10[] = {0x3f666666};
const u32 var7f1adf14[] = {0x3dcccccd};
const u32 var7f1adf18[] = {0x3dcccccd};
const u32 var7f1adf1c[] = {0x40c90fdb};
const u32 var7f1adf20[] = {0x40490fdb};
const u32 var7f1adf24[] = {0x3f060a92};
const u32 var7f1adf28[] = {0x3f060a92};
const u32 var7f1adf2c[] = {0x3e32b8c3};
const u32 var7f1adf30[] = {0x3dcc40de};
const u32 var7f1adf34[] = {0x40490fdb};
const u32 var7f1adf38[] = {0x3e32b8c3};
const u32 var7f1adf3c[] = {0x3dcc40de};
const u32 var7f1adf40[] = {0x40c90fdb};
const u32 var7f1adf44[] = {0x3f490fdb};
const u32 var7f1adf48[] = {0x40490fdb};
const u32 var7f1adf4c[] = {0x40c90fdb};
const u32 var7f1adf50[] = {0x40c90fdb};
const u32 var7f1adf54[] = {0x40490fdb};
const u32 var7f1adf58[] = {0x3f060a92};
const u32 var7f1adf5c[] = {0x3f060a92};
const u32 var7f1adf60[] = {0x3e32b8c3};
const u32 var7f1adf64[] = {0x3dcc40de};
const u32 var7f1adf68[] = {0x40490fdb};
const u32 var7f1adf6c[] = {0x3e32b8c3};
const u32 var7f1adf70[] = {0x3dcc40de};
const u32 var7f1adf74[] = {0x459c4000};
const u32 var7f1adf78[] = {0x461c4000};
const u32 var7f1adf7c[] = {0x461c4000};
const u32 var7f1adf80[] = {0x459c4000};
const u32 var7f1adf84[] = {0x40c907a9};
const u32 var7f1adf88[] = {0xc5ce4000};
const u32 var7f1adf8c[] = {0x40c907a9};
const u32 var7f1adf90[] = {0x45ce4000};
const u32 var7f1adf94[] = {0x00000000};
const u32 var7f1adf98[] = {0x00000000};
const u32 var7f1adf9c[] = {0x00000000};

GLOBAL_ASM(
glabel func0f0e0770
/*  f0e0770:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f0e0774:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0e0778:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0e077c:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0e0780:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0e0784:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0e0788:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0e078c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0e0790:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0e0794:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0e0798:	0c002acb */ 	jal	vi2GetUnk28
/*  f0e079c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e07a0:	0c002f02 */ 	jal	viGetX
/*  f0e07a4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e07a8:	3c0e8007 */ 	lui	$t6,%hi(g_HiResActive)
/*  f0e07ac:	8dce06c8 */ 	lw	$t6,%lo(g_HiResActive)($t6)
/*  f0e07b0:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f0e07b4:	0002f840 */ 	sll	$ra,$v0,0x1
/*  f0e07b8:	162e0005 */ 	bne	$s1,$t6,.L0f0e07d0
/*  f0e07bc:	3c188007 */ 	lui	$t8,%hi(var80071180)
/*  f0e07c0:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0e07c4:	3c018008 */ 	lui	$at,%hi(g_ScreenWidthMultiplier)
/*  f0e07c8:	10000003 */ 	b	.L0f0e07d8
/*  f0e07cc:	ac2ffac0 */ 	sw	$t7,%lo(g_ScreenWidthMultiplier)($at)
.L0f0e07d0:
/*  f0e07d0:	3c018008 */ 	lui	$at,%hi(g_ScreenWidthMultiplier)
/*  f0e07d4:	ac31fac0 */ 	sw	$s1,%lo(g_ScreenWidthMultiplier)($at)
.L0f0e07d8:
/*  f0e07d8:	8f181180 */ 	lw	$t8,%lo(var80071180)($t8)
/*  f0e07dc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e07e0:	17010006 */ 	bne	$t8,$at,.L0f0e07fc
/*  f0e07e4:	00000000 */ 	nop
/*  f0e07e8:	afbf0070 */ 	sw	$ra,0x70($sp)
/*  f0e07ec:	0c002acb */ 	jal	vi2GetUnk28
/*  f0e07f0:	00000000 */ 	nop
/*  f0e07f4:	8fbf0070 */ 	lw	$ra,0x70($sp)
/*  f0e07f8:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e07fc:
/*  f0e07fc:	3c047f1b */ 	lui	$a0,%hi(var7f1adf00)
/*  f0e0800:	3c058007 */ 	lui	$a1,%hi(var80071180)
/*  f0e0804:	afbf0070 */ 	sw	$ra,0x70($sp)
/*  f0e0808:	24a51180 */ 	addiu	$a1,$a1,%lo(var80071180)
/*  f0e080c:	0c0036cc */ 	jal	func0000db30
/*  f0e0810:	2484df00 */ 	addiu	$a0,$a0,%lo(var7f1adf00)
/*  f0e0814:	8fbf0070 */ 	lw	$ra,0x70($sp)
/*  f0e0818:	3c17800a */ 	lui	$s7,%hi(var8009dfbc)
/*  f0e081c:	26f7dfbc */ 	addiu	$s7,$s7,%lo(var8009dfbc)
/*  f0e0820:	001fc8c0 */ 	sll	$t9,$ra,0x3
/*  f0e0824:	afb90048 */ 	sw	$t9,0x48($sp)
/*  f0e0828:	afa00074 */ 	sw	$zero,0x74($sp)
/*  f0e082c:	0000f025 */ 	or	$s8,$zero,$zero
/*  f0e0830:	afa00044 */ 	sw	$zero,0x44($sp)
/*  f0e0834:	24130010 */ 	addiu	$s3,$zero,0x10
/*  f0e0838:	240c0008 */ 	addiu	$t4,$zero,0x8
.L0f0e083c:
/*  f0e083c:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f0e0840:	0000a025 */ 	or	$s4,$zero,$zero
.L0f0e0844:
/*  f0e0844:	3c118008 */ 	lui	$s1,%hi(g_ScreenWidthMultiplier)
/*  f0e0848:	8e31fac0 */ 	lw	$s1,%lo(g_ScreenWidthMultiplier)($s1)
/*  f0e084c:	02a0b025 */ 	or	$s6,$s5,$zero
/*  f0e0850:	26b50002 */ 	addiu	$s5,$s5,0x2
/*  f0e0854:	02910019 */ 	multu	$s4,$s1
/*  f0e0858:	00004825 */ 	or	$t1,$zero,$zero
/*  f0e085c:	00004025 */ 	or	$t0,$zero,$zero
/*  f0e0860:	00005025 */ 	or	$t2,$zero,$zero
/*  f0e0864:	00006825 */ 	or	$t5,$zero,$zero
/*  f0e0868:	00007012 */ 	mflo	$t6
/*  f0e086c:	01de9021 */ 	addu	$s2,$t6,$s8
/*  f0e0870:	00000000 */ 	nop
.L0f0e0874:
/*  f0e0874:	01b10019 */ 	multu	$t5,$s1
/*  f0e0878:	25ad0002 */ 	addiu	$t5,$t5,0x2
/*  f0e087c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0e0880:	00003825 */ 	or	$a3,$zero,$zero
/*  f0e0884:	00007812 */ 	mflo	$t7
/*  f0e0888:	01f25821 */ 	addu	$t3,$t7,$s2
/*  f0e088c:	00000000 */ 	nop
.L0f0e0890:
/*  f0e0890:	01672021 */ 	addu	$a0,$t3,$a3
/*  f0e0894:	00901821 */ 	addu	$v1,$a0,$s0
/*  f0e0898:	90790000 */ 	lbu	$t9,0x0($v1)
/*  f0e089c:	90780001 */ 	lbu	$t8,0x1($v1)
/*  f0e08a0:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f0e08a4:	00197200 */ 	sll	$t6,$t9,0x8
/*  f0e08a8:	030e1025 */ 	or	$v0,$t8,$t6
/*  f0e08ac:	0002cac3 */ 	sra	$t9,$v0,0xb
/*  f0e08b0:	3338001f */ 	andi	$t8,$t9,0x1f
/*  f0e08b4:	030a5021 */ 	addu	$t2,$t8,$t2
/*  f0e08b8:	00027183 */ 	sra	$t6,$v0,0x6
/*  f0e08bc:	0002c843 */ 	sra	$t9,$v0,0x1
/*  f0e08c0:	31cf001f */ 	andi	$t7,$t6,0x1f
/*  f0e08c4:	3338001f */ 	andi	$t8,$t9,0x1f
/*  f0e08c8:	00ff3821 */ 	addu	$a3,$a3,$ra
/*  f0e08cc:	01e84021 */ 	addu	$t0,$t7,$t0
/*  f0e08d0:	14ccffef */ 	bne	$a2,$t4,.L0f0e0890
/*  f0e08d4:	03094821 */ 	addu	$t1,$t8,$t1
/*  f0e08d8:	15b3ffe6 */ 	bne	$t5,$s3,.L0f0e0874
/*  f0e08dc:	00000000 */ 	nop
/*  f0e08e0:	000a7182 */ 	srl	$t6,$t2,0x6
/*  f0e08e4:	00087982 */ 	srl	$t7,$t0,0x6
/*  f0e08e8:	0009c982 */ 	srl	$t9,$t1,0x6
/*  f0e08ec:	000ec0c0 */ 	sll	$t8,$t6,0x3
/*  f0e08f0:	03204825 */ 	or	$t1,$t9,$zero
/*  f0e08f4:	000f7082 */ 	srl	$t6,$t7,0x2
/*  f0e08f8:	030ec825 */ 	or	$t9,$t8,$t6
/*  f0e08fc:	8ef80000 */ 	lw	$t8,0x0($s7)
/*  f0e0900:	01e04025 */ 	or	$t0,$t7,$zero
/*  f0e0904:	00087980 */ 	sll	$t7,$t0,0x6
/*  f0e0908:	03167021 */ 	addu	$t6,$t8,$s6
/*  f0e090c:	a1d90000 */ 	sb	$t9,0x0($t6)
/*  f0e0910:	3138001f */ 	andi	$t8,$t1,0x1f
/*  f0e0914:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f0e0918:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f0e091c:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0e0920:	26940010 */ 	addiu	$s4,$s4,0x10
/*  f0e0924:	24010280 */ 	addiu	$at,$zero,0x280
/*  f0e0928:	01f6c821 */ 	addu	$t9,$t7,$s6
/*  f0e092c:	1681ffc5 */ 	bne	$s4,$at,.L0f0e0844
/*  f0e0930:	a3380001 */ 	sb	$t8,0x1($t9)
/*  f0e0934:	8fae0044 */ 	lw	$t6,0x44($sp)
/*  f0e0938:	8fa20074 */ 	lw	$v0,0x74($sp)
/*  f0e093c:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f0e0940:	2401001e */ 	addiu	$at,$zero,0x1e
/*  f0e0944:	25cf0050 */ 	addiu	$t7,$t6,0x50
/*  f0e0948:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0e094c:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0e0950:	afaf0044 */ 	sw	$t7,0x44($sp)
/*  f0e0954:	1441ffb9 */ 	bne	$v0,$at,.L0f0e083c
/*  f0e0958:	03d8f021 */ 	addu	$s8,$s8,$t8
/*  f0e095c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0e0960:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0e0964:	3c018008 */ 	lui	$at,%hi(g_ScreenWidthMultiplier)
/*  f0e0968:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0e096c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0e0970:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0e0974:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0e0978:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0e097c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0e0980:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0e0984:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0e0988:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0e098c:	ac39fac0 */ 	sw	$t9,%lo(g_ScreenWidthMultiplier)($at)
/*  f0e0990:	03e00008 */ 	jr	$ra
/*  f0e0994:	27bd0080 */ 	addiu	$sp,$sp,0x80
);

GLOBAL_ASM(
glabel func0f0e0998
/*  f0e0998:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f0e099c:	3c0e8009 */ 	lui	$t6,%hi(g_Is4Mb)
/*  f0e09a0:	91ce0af0 */ 	lbu	$t6,%lo(g_Is4Mb)($t6)
/*  f0e09a4:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0e09a8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e09ac:	00808025 */ 	or	$s0,$a0,$zero
/*  f0e09b0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e09b4:	afa5008c */ 	sw	$a1,0x8c($sp)
/*  f0e09b8:	afa60090 */ 	sw	$a2,0x90($sp)
/*  f0e09bc:	15c10013 */ 	bne	$t6,$at,.L0f0e0a0c
/*  f0e09c0:	afa70094 */ 	sw	$a3,0x94($sp)
/*  f0e09c4:	0c002f02 */ 	jal	viGetX
/*  f0e09c8:	00000000 */ 	nop
/*  f0e09cc:	0c002f06 */ 	jal	viGetY
/*  f0e09d0:	a7a20030 */ 	sh	$v0,0x30($sp)
/*  f0e09d4:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f0e09d8:	241800ff */ 	addiu	$t8,$zero,0xff
/*  f0e09dc:	241900ff */ 	addiu	$t9,$zero,0xff
/*  f0e09e0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e09e4:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0e09e8:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e09ec:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e09f0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e09f4:	00003025 */ 	or	$a2,$zero,$zero
/*  f0e09f8:	87a70030 */ 	lh	$a3,0x30($sp)
/*  f0e09fc:	0fc3873a */ 	jal	func0f0e1ce8
/*  f0e0a00:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f0e0a04:	100000a9 */ 	b	.L0f0e0cac
/*  f0e0a08:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0e0a0c:
/*  f0e0a0c:	0fc59e73 */ 	jal	func0f1679cc
/*  f0e0a10:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0e0a14:	afa20084 */ 	sw	$v0,0x84($sp)
/*  f0e0a18:	0fc59e59 */ 	jal	func0f167964
/*  f0e0a1c:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0e0a20:	02001825 */ 	or	$v1,$s0,$zero
/*  f0e0a24:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f0e0a28:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0a2c:	3c09e700 */ 	lui	$t1,0xe700
/*  f0e0a30:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e0a34:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f0e0a38:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0e0a3c:	3c0abb00 */ 	lui	$t2,0xbb00
/*  f0e0a40:	354a0001 */ 	ori	$t2,$t2,0x1
/*  f0e0a44:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0a48:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0e0a4c:	ac8b0004 */ 	sw	$t3,0x4($a0)
/*  f0e0a50:	ac8a0000 */ 	sw	$t2,0x0($a0)
/*  f0e0a54:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e0a58:	3c0cfd10 */ 	lui	$t4,0xfd10
/*  f0e0a5c:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f0e0a60:	3c0d800a */ 	lui	$t5,%hi(var8009dfbc)
/*  f0e0a64:	8daddfbc */ 	lw	$t5,%lo(var8009dfbc)($t5)
/*  f0e0a68:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0a6c:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e0a70:	3c0f0708 */ 	lui	$t7,0x708
/*  f0e0a74:	acad0004 */ 	sw	$t5,0x4($a1)
/*  f0e0a78:	35ef0200 */ 	ori	$t7,$t7,0x200
/*  f0e0a7c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0a80:	3c0ef510 */ 	lui	$t6,0xf510
/*  f0e0a84:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f0e0a88:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e0a8c:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f0e0a90:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0a94:	02001825 */ 	or	$v1,$s0,$zero
/*  f0e0a98:	3c18e600 */ 	lui	$t8,0xe600
/*  f0e0a9c:	acf80000 */ 	sw	$t8,0x0($a3)
/*  f0e0aa0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0aa4:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f0e0aa8:	3c0a074a */ 	lui	$t2,0x74a
/*  f0e0aac:	354af0cd */ 	ori	$t2,$t2,0xf0cd
/*  f0e0ab0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e0ab4:	3c19f300 */ 	lui	$t9,0xf300
/*  f0e0ab8:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0e0abc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0ac0:	ac6a0004 */ 	sw	$t2,0x4($v1)
/*  f0e0ac4:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e0ac8:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f0e0acc:	ac890000 */ 	sw	$t1,0x0($a0)
/*  f0e0ad0:	3c0c0008 */ 	lui	$t4,0x8
/*  f0e0ad4:	3c0bf510 */ 	lui	$t3,0xf510
/*  f0e0ad8:	356b1400 */ 	ori	$t3,$t3,0x1400
/*  f0e0adc:	358c0200 */ 	ori	$t4,$t4,0x200
/*  f0e0ae0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0ae4:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e0ae8:	acac0004 */ 	sw	$t4,0x4($a1)
/*  f0e0aec:	acab0000 */ 	sw	$t3,0x0($a1)
/*  f0e0af0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0af4:	3c0e0009 */ 	lui	$t6,0x9
/*  f0e0af8:	35cec074 */ 	ori	$t6,$t6,0xc074
/*  f0e0afc:	3c0df200 */ 	lui	$t5,0xf200
/*  f0e0b00:	02004025 */ 	or	$t0,$s0,$zero
/*  f0e0b04:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f0e0b08:	acce0004 */ 	sw	$t6,0x4($a2)
/*  f0e0b0c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0b10:	02001825 */ 	or	$v1,$s0,$zero
/*  f0e0b14:	ad000004 */ 	sw	$zero,0x4($t0)
/*  f0e0b18:	ad090000 */ 	sw	$t1,0x0($t0)
/*  f0e0b1c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0b20:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0e0b24:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f0e0b28:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e0b2c:	3c18b900 */ 	lui	$t8,0xb900
/*  f0e0b30:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0e0b34:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f0e0b38:	37180002 */ 	ori	$t8,$t8,0x2
/*  f0e0b3c:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f0e0b40:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0b44:	ac800004 */ 	sw	$zero,0x4($a0)
/*  f0e0b48:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e0b4c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0b50:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f0e0b54:	37397e24 */ 	ori	$t9,$t9,0x7e24
/*  f0e0b58:	240af9fc */ 	addiu	$t2,$zero,-1540
/*  f0e0b5c:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e0b60:	acaa0004 */ 	sw	$t2,0x4($a1)
/*  f0e0b64:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f0e0b68:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0b6c:	3c0bb600 */ 	lui	$t3,0xb600
/*  f0e0b70:	240c3000 */ 	addiu	$t4,$zero,0x3000
/*  f0e0b74:	02003825 */ 	or	$a3,$s0,$zero
/*  f0e0b78:	accc0004 */ 	sw	$t4,0x4($a2)
/*  f0e0b7c:	accb0000 */ 	sw	$t3,0x0($a2)
/*  f0e0b80:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0e0b84:	35ad0c02 */ 	ori	$t5,$t5,0xc02
/*  f0e0b88:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0b8c:	240e2000 */ 	addiu	$t6,$zero,0x2000
/*  f0e0b90:	acee0004 */ 	sw	$t6,0x4($a3)
/*  f0e0b94:	aced0000 */ 	sw	$t5,0x0($a3)
/*  f0e0b98:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e0b9c:	3c180050 */ 	lui	$t8,0x50
/*  f0e0ba0:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0e0ba4:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f0e0ba8:	37184240 */ 	ori	$t8,$t8,0x4240
/*  f0e0bac:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f0e0bb0:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f0e0bb4:	87a60092 */ 	lh	$a2,0x92($sp)
/*  f0e0bb8:	2409fff6 */ 	addiu	$t1,$zero,-10
/*  f0e0bbc:	24040500 */ 	addiu	$a0,$zero,0x500
/*  f0e0bc0:	a4460000 */ 	sh	$a2,0x0($v0)
/*  f0e0bc4:	87a30096 */ 	lh	$v1,0x96($sp)
/*  f0e0bc8:	24c50ca8 */ 	addiu	$a1,$a2,0xca8
/*  f0e0bcc:	a4490004 */ 	sh	$t1,0x4($v0)
/*  f0e0bd0:	24680992 */ 	addiu	$t0,$v1,0x992
/*  f0e0bd4:	a445000c */ 	sh	$a1,0xc($v0)
/*  f0e0bd8:	a4490010 */ 	sh	$t1,0x10($v0)
/*  f0e0bdc:	a4450018 */ 	sh	$a1,0x18($v0)
/*  f0e0be0:	a448001a */ 	sh	$t0,0x1a($v0)
/*  f0e0be4:	a449001c */ 	sh	$t1,0x1c($v0)
/*  f0e0be8:	a4430002 */ 	sh	$v1,0x2($v0)
/*  f0e0bec:	a443000e */ 	sh	$v1,0xe($v0)
/*  f0e0bf0:	8fa70084 */ 	lw	$a3,0x84($sp)
/*  f0e0bf4:	240503c0 */ 	addiu	$a1,$zero,0x3c0
/*  f0e0bf8:	a4480026 */ 	sh	$t0,0x26($v0)
/*  f0e0bfc:	a4490028 */ 	sh	$t1,0x28($v0)
/*  f0e0c00:	a4400008 */ 	sh	$zero,0x8($v0)
/*  f0e0c04:	a440000a */ 	sh	$zero,0xa($v0)
/*  f0e0c08:	a4440014 */ 	sh	$a0,0x14($v0)
/*  f0e0c0c:	a4400016 */ 	sh	$zero,0x16($v0)
/*  f0e0c10:	a4440020 */ 	sh	$a0,0x20($v0)
/*  f0e0c14:	a4450022 */ 	sh	$a1,0x22($v0)
/*  f0e0c18:	a440002c */ 	sh	$zero,0x2c($v0)
/*  f0e0c1c:	a445002e */ 	sh	$a1,0x2e($v0)
/*  f0e0c20:	a0400007 */ 	sb	$zero,0x7($v0)
/*  f0e0c24:	a0400013 */ 	sb	$zero,0x13($v0)
/*  f0e0c28:	a040001f */ 	sb	$zero,0x1f($v0)
/*  f0e0c2c:	a040002b */ 	sb	$zero,0x2b($v0)
/*  f0e0c30:	a4460024 */ 	sh	$a2,0x24($v0)
/*  f0e0c34:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f0e0c38:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0c3c:	3c0a0700 */ 	lui	$t2,0x700
/*  f0e0c40:	354a0004 */ 	ori	$t2,$t2,0x4
/*  f0e0c44:	02001825 */ 	or	$v1,$s0,$zero
/*  f0e0c48:	acf90000 */ 	sw	$t9,0x0($a3)
/*  f0e0c4c:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f0e0c50:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f0e0c54:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0c58:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e0c5c:	00e02025 */ 	or	$a0,$a3,$zero
/*  f0e0c60:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f0e0c64:	3c0b0430 */ 	lui	$t3,0x430
/*  f0e0c68:	356b0030 */ 	ori	$t3,$t3,0x30
/*  f0e0c6c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e0c70:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0e0c74:	acab0000 */ 	sw	$t3,0x0($a1)
/*  f0e0c78:	afa50038 */ 	sw	$a1,0x38($sp)
/*  f0e0c7c:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f0e0c80:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e0c84:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e0c88:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f0e0c8c:	3c0cb100 */ 	lui	$t4,0xb100
/*  f0e0c90:	358c0002 */ 	ori	$t4,$t4,0x2
/*  f0e0c94:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0e0c98:	240d3210 */ 	addiu	$t5,$zero,0x3210
/*  f0e0c9c:	ae0d0004 */ 	sw	$t5,0x4($s0)
/*  f0e0ca0:	ae0c0000 */ 	sw	$t4,0x0($s0)
/*  f0e0ca4:	26020008 */ 	addiu	$v0,$s0,0x8
/*  f0e0ca8:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f0e0cac:
/*  f0e0cac:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0e0cb0:	27bd0088 */ 	addiu	$sp,$sp,0x88
/*  f0e0cb4:	03e00008 */ 	jr	$ra
/*  f0e0cb8:	00000000 */ 	nop
/*  f0e0cbc:	00067400 */ 	sll	$t6,$a2,0x10
/*  f0e0cc0:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f0e0cc4:	2402000a */ 	addiu	$v0,$zero,0xa
/*  f0e0cc8:	01e44823 */ 	subu	$t1,$t7,$a0
/*  f0e0ccc:	01e20019 */ 	multu	$t7,$v0
/*  f0e0cd0:	0007c400 */ 	sll	$t8,$a3,0x10
/*  f0e0cd4:	252a0064 */ 	addiu	$t2,$t1,0x64
/*  f0e0cd8:	448a2000 */ 	mtc1	$t2,$f4
/*  f0e0cdc:	0018cc03 */ 	sra	$t9,$t8,0x10
/*  f0e0ce0:	03256023 */ 	subu	$t4,$t9,$a1
/*  f0e0ce4:	258d0064 */ 	addiu	$t5,$t4,0x64
/*  f0e0ce8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e0cec:	448d5000 */ 	mtc1	$t5,$f10
/*  f0e0cf0:	3c013e80 */ 	lui	$at,0x3e80
/*  f0e0cf4:	44810000 */ 	mtc1	$at,$f0
/*  f0e0cf8:	00007012 */ 	mflo	$t6
/*  f0e0cfc:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0e0d00:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0e0d04:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0e0d08:	03220019 */ 	multu	$t9,$v0
/*  f0e0d0c:	44802000 */ 	mtc1	$zero,$f4
/*  f0e0d10:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e0d14:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0e0d18:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f0e0d1c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0e0d20:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f0e0d24:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f0e0d28:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f0e0d2c:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f0e0d30:	e7a80024 */ 	swc1	$f8,0x24($sp)
/*  f0e0d34:	e7b20028 */ 	swc1	$f18,0x28($sp)
/*  f0e0d38:	e7a4002c */ 	swc1	$f4,0x2c($sp)
/*  f0e0d3c:	00007812 */ 	mflo	$t7
/*  f0e0d40:	2418fff6 */ 	addiu	$t8,$zero,-10
/*  f0e0d44:	a60e0000 */ 	sh	$t6,0x0($s0)
/*  f0e0d48:	a60f0002 */ 	sh	$t7,0x2($s0)
/*  f0e0d4c:	a6180004 */ 	sh	$t8,0x4($s0)
/*  f0e0d50:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0e0d54:	8fa40044 */ 	lw	$a0,0x44($sp)
/*  f0e0d58:	0c0056d9 */ 	jal	func00015b64
/*  f0e0d5c:	27a50024 */ 	addiu	$a1,$sp,0x24
/*  f0e0d60:	3c014200 */ 	lui	$at,0x4200
/*  f0e0d64:	44810000 */ 	mtc1	$at,$f0
/*  f0e0d68:	c7a60024 */ 	lwc1	$f6,0x24($sp)
/*  f0e0d6c:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0e0d70:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e0d74:	44085000 */ 	mfc1	$t0,$f10
/*  f0e0d78:	00000000 */ 	nop
/*  f0e0d7c:	a6080008 */ 	sh	$t0,0x8($s0)
/*  f0e0d80:	c7b00028 */ 	lwc1	$f16,0x28($sp)
/*  f0e0d84:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f0e0d88:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e0d8c:	440a2000 */ 	mfc1	$t2,$f4
/*  f0e0d90:	00000000 */ 	nop
/*  f0e0d94:	a60a000a */ 	sh	$t2,0xa($s0)
/*  f0e0d98:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0e0d9c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0e0da0:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f0e0da4:	03e00008 */ 	jr	$ra
/*  f0e0da8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0e0dac
/*  f0e0dac:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0e0db0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0e0db4:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0e0db8:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f0e0dbc:	afa70044 */ 	sw	$a3,0x44($sp)
/*  f0e0dc0:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0e0dc4:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0e0dc8:	3c038008 */ 	lui	$v1,%hi(g_ScreenWidthMultiplier)
/*  f0e0dcc:	2463fac0 */ 	addiu	$v1,$v1,%lo(g_ScreenWidthMultiplier)
/*  f0e0dd0:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0e0dd4:	8fae0044 */ 	lw	$t6,0x44($sp)
/*  f0e0dd8:	8fab0048 */ 	lw	$t3,0x48($sp)
/*  f0e0ddc:	3c01f600 */ 	lui	$at,0xf600
/*  f0e0de0:	01cf0019 */ 	multu	$t6,$t7
/*  f0e0de4:	316c03ff */ 	andi	$t4,$t3,0x3ff
/*  f0e0de8:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f0e0dec:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0e0df0:	0000c012 */ 	mflo	$t8
/*  f0e0df4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0e0df8:	00194b80 */ 	sll	$t1,$t9,0xe
/*  f0e0dfc:	01215025 */ 	or	$t2,$t1,$at
/*  f0e0e00:	014d7025 */ 	or	$t6,$t2,$t5
/*  f0e0e04:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0e0e08:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0e0e0c:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f0e0e10:	8fac0040 */ 	lw	$t4,0x40($sp)
/*  f0e0e14:	01f80019 */ 	multu	$t7,$t8
/*  f0e0e18:	318a03ff */ 	andi	$t2,$t4,0x3ff
/*  f0e0e1c:	000a6880 */ 	sll	$t5,$t2,0x2
/*  f0e0e20:	0000c812 */ 	mflo	$t9
/*  f0e0e24:	332903ff */ 	andi	$t1,$t9,0x3ff
/*  f0e0e28:	00095b80 */ 	sll	$t3,$t1,0xe
/*  f0e0e2c:	016d7025 */ 	or	$t6,$t3,$t5
/*  f0e0e30:	0fc54e0e */ 	jal	func0f153838
/*  f0e0e34:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0e0e38:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0e0e3c:	afa20038 */ 	sw	$v0,0x38($sp)
/*  f0e0e40:	44802000 */ 	mtc1	$zero,$f4
/*  f0e0e44:	c4600040 */ 	lwc1	$f0,0x40($v1)
/*  f0e0e48:	4604003c */ 	c.lt.s	$f0,$f4
/*  f0e0e4c:	00000000 */ 	nop
/*  f0e0e50:	4502000b */ 	bc1fl	.L0f0e0e80
/*  f0e0e54:	9069003d */ 	lbu	$t1,0x3d($v1)
/*  f0e0e58:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0e0e5c:	3c197f1b */ 	lui	$t9,%hi(g_MenuColourPalettes)
/*  f0e0e60:	27391fb0 */ 	addiu	$t9,$t9,%lo(g_MenuColourPalettes)
/*  f0e0e64:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f0e0e68:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0e0e6c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0e0e70:	03193821 */ 	addu	$a3,$t8,$t9
/*  f0e0e74:	1000001a */ 	b	.L0f0e0ee0
/*  f0e0e78:	8ce80000 */ 	lw	$t0,0x0($a3)
/*  f0e0e7c:	9069003d */ 	lbu	$t1,0x3d($v1)
.L0f0e0e80:
/*  f0e0e80:	2407003c */ 	addiu	$a3,$zero,0x3c
/*  f0e0e84:	906b003c */ 	lbu	$t3,0x3c($v1)
/*  f0e0e88:	01270019 */ 	multu	$t1,$a3
/*  f0e0e8c:	3c027f1b */ 	lui	$v0,%hi(g_MenuColourPalettes)
/*  f0e0e90:	24421fb0 */ 	addiu	$v0,$v0,%lo(g_MenuColourPalettes)
/*  f0e0e94:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e0e98:	00006012 */ 	mflo	$t4
/*  f0e0e9c:	004c5021 */ 	addu	$t2,$v0,$t4
/*  f0e0ea0:	8d440000 */ 	lw	$a0,0x0($t2)
/*  f0e0ea4:	01670019 */ 	multu	$t3,$a3
/*  f0e0ea8:	00006812 */ 	mflo	$t5
/*  f0e0eac:	004d7021 */ 	addu	$t6,$v0,$t5
/*  f0e0eb0:	0fc01a40 */ 	jal	colourBlend
/*  f0e0eb4:	8dc50000 */ 	lw	$a1,0x0($t6)
/*  f0e0eb8:	8fa3004c */ 	lw	$v1,0x4c($sp)
/*  f0e0ebc:	3c197f1b */ 	lui	$t9,%hi(g_MenuColourPalettes)
/*  f0e0ec0:	27391fb0 */ 	addiu	$t9,$t9,%lo(g_MenuColourPalettes)
/*  f0e0ec4:	906f003c */ 	lbu	$t7,0x3c($v1)
/*  f0e0ec8:	00404025 */ 	or	$t0,$v0,$zero
/*  f0e0ecc:	c4600040 */ 	lwc1	$f0,0x40($v1)
/*  f0e0ed0:	000fc100 */ 	sll	$t8,$t7,0x4
/*  f0e0ed4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0e0ed8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0e0edc:	03193821 */ 	addu	$a3,$t8,$t9
.L0f0e0ee0:
/*  f0e0ee0:	44803000 */ 	mtc1	$zero,$f6
/*  f0e0ee4:	3c047f1b */ 	lui	$a0,%hi(g_MenuColourPalettes+0x8)
/*  f0e0ee8:	4606003c */ 	c.lt.s	$f0,$f6
/*  f0e0eec:	00000000 */ 	nop
/*  f0e0ef0:	45020004 */ 	bc1fl	.L0f0e0f04
/*  f0e0ef4:	9069003d */ 	lbu	$t1,0x3d($v1)
/*  f0e0ef8:	1000000d */ 	b	.L0f0e0f30
/*  f0e0efc:	8ce30008 */ 	lw	$v1,0x8($a3)
/*  f0e0f00:	9069003d */ 	lbu	$t1,0x3d($v1)
.L0f0e0f04:
/*  f0e0f04:	8c660044 */ 	lw	$a2,0x44($v1)
/*  f0e0f08:	afa80030 */ 	sw	$t0,0x30($sp)
/*  f0e0f0c:	00096100 */ 	sll	$t4,$t1,0x4
/*  f0e0f10:	01896023 */ 	subu	$t4,$t4,$t1
/*  f0e0f14:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0e0f18:	008c2021 */ 	addu	$a0,$a0,$t4
/*  f0e0f1c:	8c841fb8 */ 	lw	$a0,%lo(g_MenuColourPalettes+0x8)($a0)
/*  f0e0f20:	0fc01a40 */ 	jal	colourBlend
/*  f0e0f24:	8ce50008 */ 	lw	$a1,0x8($a3)
/*  f0e0f28:	8fa80030 */ 	lw	$t0,0x30($sp)
/*  f0e0f2c:	00401825 */ 	or	$v1,$v0,$zero
.L0f0e0f30:
/*  f0e0f30:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f0e0f34:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f0e0f38:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0e0f3c:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0e0f40:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e0f44:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e0f48:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f0e0f4c:	afa80030 */ 	sw	$t0,0x30($sp)
/*  f0e0f50:	24e5ffff */ 	addiu	$a1,$a3,-1
/*  f0e0f54:	0fc38bba */ 	jal	func0f0e2ee8
/*  f0e0f58:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e0f5c:	8fa80030 */ 	lw	$t0,0x30($sp)
/*  f0e0f60:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0e0f64:	8fab0048 */ 	lw	$t3,0x48($sp)
/*  f0e0f68:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e0f6c:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0e0f70:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0e0f74:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0e0f78:	24a70001 */ 	addiu	$a3,$a1,0x1
/*  f0e0f7c:	0fc38bba */ 	jal	func0f0e2ee8
/*  f0e0f80:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e0f84:	8fad0048 */ 	lw	$t5,0x48($sp)
/*  f0e0f88:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f0e0f8c:	8fa80030 */ 	lw	$t0,0x30($sp)
/*  f0e0f90:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e0f94:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0e0f98:	8fa70044 */ 	lw	$a3,0x44($sp)
/*  f0e0f9c:	25a6ffff */ 	addiu	$a2,$t5,-1
/*  f0e0fa0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e0fa4:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e0fa8:	0fc38bba */ 	jal	func0f0e2ee8
/*  f0e0fac:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0e0fb0:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0e0fb4:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0e0fb8:	03e00008 */ 	jr	$ra
/*  f0e0fbc:	00000000 */ 	nop
/*  f0e0fc0:	27bdfee8 */ 	addiu	$sp,$sp,-280
/*  f0e0fc4:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f0e0fc8:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f0e0fcc:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0e0fd0:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f0e0fd4:	afa40118 */ 	sw	$a0,0x118($sp)
/*  f0e0fd8:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0e0fdc:	00c09025 */ 	or	$s2,$a2,$zero
/*  f0e0fe0:	00e09825 */ 	or	$s3,$a3,$zero
/*  f0e0fe4:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f0e0fe8:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f0e0fec:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f0e0ff0:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f0e0ff4:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f0e0ff8:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f0e0ffc:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f0e1000:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f0e1004:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f0e1008:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f0e100c:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f0e1010:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f0e1014:	0fc59e73 */ 	jal	func0f1679cc
/*  f0e1018:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0e101c:	afa20110 */ 	sw	$v0,0x110($sp)
/*  f0e1020:	0fc59e59 */ 	jal	func0f167964
/*  f0e1024:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f0e1028:	8fae0118 */ 	lw	$t6,0x118($sp)
/*  f0e102c:	3c18e700 */ 	lui	$t8,0xe700
/*  f0e1030:	3c0aba00 */ 	lui	$t2,0xba00
/*  f0e1034:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e1038:	afaf0118 */ 	sw	$t7,0x118($sp)
/*  f0e103c:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0e1040:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e1044:	8fb90118 */ 	lw	$t9,0x118($sp)
/*  f0e1048:	354a1402 */ 	ori	$t2,$t2,0x1402
/*  f0e104c:	3c0db900 */ 	lui	$t5,0xb900
/*  f0e1050:	27290008 */ 	addiu	$t1,$t9,0x8
/*  f0e1054:	afa90118 */ 	sw	$t1,0x118($sp)
/*  f0e1058:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0e105c:	af2a0000 */ 	sw	$t2,0x0($t9)
/*  f0e1060:	8fab0118 */ 	lw	$t3,0x118($sp)
/*  f0e1064:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f0e1068:	3c18fc12 */ 	lui	$t8,0xfc12
/*  f0e106c:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f0e1070:	afac0118 */ 	sw	$t4,0x118($sp)
/*  f0e1074:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f0e1078:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f0e107c:	8fae0118 */ 	lw	$t6,0x118($sp)
/*  f0e1080:	37187e24 */ 	ori	$t8,$t8,0x7e24
/*  f0e1084:	2419f9fc */ 	addiu	$t9,$zero,-1540
/*  f0e1088:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e108c:	afaf0118 */ 	sw	$t7,0x118($sp)
/*  f0e1090:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0e1094:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e1098:	8fa90118 */ 	lw	$t1,0x118($sp)
/*  f0e109c:	3c0bb600 */ 	lui	$t3,0xb600
/*  f0e10a0:	240c3000 */ 	addiu	$t4,$zero,0x3000
/*  f0e10a4:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f0e10a8:	afaa0118 */ 	sw	$t2,0x118($sp)
/*  f0e10ac:	ad2c0004 */ 	sw	$t4,0x4($t1)
/*  f0e10b0:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f0e10b4:	8fad0118 */ 	lw	$t5,0x118($sp)
/*  f0e10b8:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0e10bc:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f0e10c0:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0e10c4:	afae0118 */ 	sw	$t6,0x118($sp)
/*  f0e10c8:	24182000 */ 	addiu	$t8,$zero,0x2000
/*  f0e10cc:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f0e10d0:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f0e10d4:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0e10d8:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
/*  f0e10dc:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0e10e0:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0e10e4:	0040b825 */ 	or	$s7,$v0,$zero
/*  f0e10e8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e10ec:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e10f0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e10f4:	27a40118 */ 	addiu	$a0,$sp,0x118
/*  f0e10f8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0e10fc:	00003825 */ 	or	$a3,$zero,$zero
/*  f0e1100:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0e1104:	24a50048 */ 	addiu	$a1,$a1,0x0048
/*  f0e1108:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f0e110c:	02060019 */ 	multu	$s0,$a2
/*  f0e1110:	8faa0118 */ 	lw	$t2,0x118($sp)
/*  f0e1114:	3c0cb900 */ 	lui	$t4,0xb900
/*  f0e1118:	358c031d */ 	ori	$t4,$t4,0x31d
/*  f0e111c:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0e1120:	afab0118 */ 	sw	$t3,0x118($sp)
/*  f0e1124:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f0e1128:	3c0d0050 */ 	lui	$t5,0x50
/*  f0e112c:	35ad4240 */ 	ori	$t5,$t5,0x4240
/*  f0e1130:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0e1134:	00002012 */ 	mflo	$a0
/*  f0e1138:	2407fff6 */ 	addiu	$a3,$zero,-10
/*  f0e113c:	a6e70004 */ 	sh	$a3,0x4($s7)
/*  f0e1140:	02460019 */ 	multu	$s2,$a2
/*  f0e1144:	86ee0004 */ 	lh	$t6,0x4($s7)
/*  f0e1148:	a6e40000 */ 	sh	$a0,0x0($s7)
/*  f0e114c:	a6e40030 */ 	sh	$a0,0x30($s7)
/*  f0e1150:	a6e70010 */ 	sh	$a3,0x10($s7)
/*  f0e1154:	a6ee0034 */ 	sh	$t6,0x34($s7)
/*  f0e1158:	02704823 */ 	subu	$t1,$s3,$s0
/*  f0e115c:	86ef0010 */ 	lh	$t7,0x10($s7)
/*  f0e1160:	0000b025 */ 	or	$s6,$zero,$zero
/*  f0e1164:	27b40104 */ 	addiu	$s4,$sp,0x104
/*  f0e1168:	00001012 */ 	mflo	$v0
/*  f0e116c:	a6e20002 */ 	sh	$v0,0x2($s7)
/*  f0e1170:	a6e20032 */ 	sh	$v0,0x32($s7)
/*  f0e1174:	02660019 */ 	multu	$s3,$a2
/*  f0e1178:	a6e2000e */ 	sh	$v0,0xe($s7)
/*  f0e117c:	a6e2003e */ 	sh	$v0,0x3e($s7)
/*  f0e1180:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0e1184:	02e08825 */ 	or	$s1,$s7,$zero
/*  f0e1188:	241e0030 */ 	addiu	$s8,$zero,0x30
/*  f0e118c:	00002812 */ 	mflo	$a1
/*  f0e1190:	a6e5000c */ 	sh	$a1,0xc($s7)
/*  f0e1194:	a6e5003c */ 	sh	$a1,0x3c($s7)
/*  f0e1198:	8fa30128 */ 	lw	$v1,0x128($sp)
/*  f0e119c:	a6e7001c */ 	sh	$a3,0x1c($s7)
/*  f0e11a0:	a6e70028 */ 	sh	$a3,0x28($s7)
/*  f0e11a4:	00660019 */ 	multu	$v1,$a2
/*  f0e11a8:	00725823 */ 	subu	$t3,$v1,$s2
/*  f0e11ac:	86f8001c */ 	lh	$t8,0x1c($s7)
/*  f0e11b0:	86f90028 */ 	lh	$t9,0x28($s7)
/*  f0e11b4:	a6e50048 */ 	sh	$a1,0x48($s7)
/*  f0e11b8:	a6e50018 */ 	sh	$a1,0x18($s7)
/*  f0e11bc:	a6e40054 */ 	sh	$a0,0x54($s7)
/*  f0e11c0:	a6e40024 */ 	sh	$a0,0x24($s7)
/*  f0e11c4:	a6ef0040 */ 	sh	$t7,0x40($s7)
/*  f0e11c8:	a6f8004c */ 	sh	$t8,0x4c($s7)
/*  f0e11cc:	00001012 */ 	mflo	$v0
/*  f0e11d0:	a6e2001a */ 	sh	$v0,0x1a($s7)
/*  f0e11d4:	a6e2004a */ 	sh	$v0,0x4a($s7)
/*  f0e11d8:	a6e20026 */ 	sh	$v0,0x26($s7)
/*  f0e11dc:	a6e20056 */ 	sh	$v0,0x56($s7)
/*  f0e11e0:	a6f90058 */ 	sh	$t9,0x58($s7)
/*  f0e11e4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0e11e8:	05210003 */ 	bgez	$t1,.L0f0e11f8
/*  f0e11ec:	00095043 */ 	sra	$t2,$t1,0x1
/*  f0e11f0:	25210001 */ 	addiu	$at,$t1,0x1
/*  f0e11f4:	00015043 */ 	sra	$t2,$at,0x1
.L0f0e11f8:
/*  f0e11f8:	448a2000 */ 	mtc1	$t2,$f4
/*  f0e11fc:	00000000 */ 	nop
/*  f0e1200:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e1204:	e7a6009c */ 	swc1	$f6,0x9c($sp)
/*  f0e1208:	05610003 */ 	bgez	$t3,.L0f0e1218
/*  f0e120c:	000b6043 */ 	sra	$t4,$t3,0x1
/*  f0e1210:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0e1214:	00016043 */ 	sra	$t4,$at,0x1
.L0f0e1218:
/*  f0e1218:	448c4000 */ 	mtc1	$t4,$f8
/*  f0e121c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0e1220:	4481f000 */ 	mtc1	$at,$f30
/*  f0e1224:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0e1228:	e7aa0098 */ 	swc1	$f10,0x98($sp)
.L0f0e122c:
/*  f0e122c:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f0e1230:	c4201630 */ 	lwc1	$f0,%lo(var80061630)($at)
/*  f0e1234:	3c017f1b */ 	lui	$at,%hi(var7f1adf08)
/*  f0e1238:	c430df08 */ 	lwc1	$f16,%lo(var7f1adf08)($at)
/*  f0e123c:	24010030 */ 	addiu	$at,$zero,0x30
/*  f0e1240:	46008682 */ 	mul.s	$f26,$f16,$f0
/*  f0e1244:	16be0002 */ 	bne	$s5,$s8,.L0f0e1250
/*  f0e1248:	00000000 */ 	nop
/*  f0e124c:	4600d687 */ 	neg.s	$f26,$f26
.L0f0e1250:
/*  f0e1250:	16a10004 */ 	bne	$s5,$at,.L0f0e1264
/*  f0e1254:	3c013f00 */ 	lui	$at,0x3f00
/*  f0e1258:	44819000 */ 	mtc1	$at,$f18
/*  f0e125c:	00000000 */ 	nop
/*  f0e1260:	46120000 */ 	add.s	$f0,$f0,$f18
.L0f0e1264:
/*  f0e1264:	4600f03c */ 	c.lt.s	$f30,$f0
/*  f0e1268:	3c017f1b */ 	lui	$at,%hi(var7f1adf0c)
/*  f0e126c:	45000002 */ 	bc1f	.L0f0e1278
/*  f0e1270:	00000000 */ 	nop
/*  f0e1274:	461e0001 */ 	sub.s	$f0,$f0,$f30
.L0f0e1278:
/*  f0e1278:	c42cdf0c */ 	lwc1	$f12,%lo(var7f1adf0c)($at)
/*  f0e127c:	3c017f1b */ 	lui	$at,%hi(var7f1adf10)
/*  f0e1280:	460c003c */ 	c.lt.s	$f0,$f12
/*  f0e1284:	00000000 */ 	nop
/*  f0e1288:	45000029 */ 	bc1f	.L0f0e1330
/*  f0e128c:	00000000 */ 	nop
/*  f0e1290:	460c0103 */ 	div.s	$f4,$f0,$f12
/*  f0e1294:	3c0142fe */ 	lui	$at,0x42fe
/*  f0e1298:	44813000 */ 	mtc1	$at,$f6
/*  f0e129c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0e12a0:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e12a4:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e12a8:	444df800 */ 	cfc1	$t5,$31
/*  f0e12ac:	44cef800 */ 	ctc1	$t6,$31
/*  f0e12b0:	00000000 */ 	nop
/*  f0e12b4:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0e12b8:	444ef800 */ 	cfc1	$t6,$31
/*  f0e12bc:	00000000 */ 	nop
/*  f0e12c0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0e12c4:	51c00013 */ 	beqzl	$t6,.L0f0e1314
/*  f0e12c8:	440e5000 */ 	mfc1	$t6,$f10
/*  f0e12cc:	44815000 */ 	mtc1	$at,$f10
/*  f0e12d0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0e12d4:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0e12d8:	44cef800 */ 	ctc1	$t6,$31
/*  f0e12dc:	00000000 */ 	nop
/*  f0e12e0:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0e12e4:	444ef800 */ 	cfc1	$t6,$31
/*  f0e12e8:	00000000 */ 	nop
/*  f0e12ec:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0e12f0:	15c00005 */ 	bnez	$t6,.L0f0e1308
/*  f0e12f4:	00000000 */ 	nop
/*  f0e12f8:	440e5000 */ 	mfc1	$t6,$f10
/*  f0e12fc:	3c018000 */ 	lui	$at,0x8000
/*  f0e1300:	10000007 */ 	b	.L0f0e1320
/*  f0e1304:	01c17025 */ 	or	$t6,$t6,$at
.L0f0e1308:
/*  f0e1308:	10000005 */ 	b	.L0f0e1320
/*  f0e130c:	240effff */ 	addiu	$t6,$zero,-1
/*  f0e1310:	440e5000 */ 	mfc1	$t6,$f10
.L0f0e1314:
/*  f0e1314:	00000000 */ 	nop
/*  f0e1318:	05c0fffb */ 	bltz	$t6,.L0f0e1308
/*  f0e131c:	00000000 */ 	nop
.L0f0e1320:
/*  f0e1320:	44cdf800 */ 	ctc1	$t5,$31
/*  f0e1324:	ae8e0000 */ 	sw	$t6,0x0($s4)
/*  f0e1328:	10000033 */ 	b	.L0f0e13f8
/*  f0e132c:	4600f081 */ 	sub.s	$f2,$f30,$f0
.L0f0e1330:
/*  f0e1330:	c430df10 */ 	lwc1	$f16,%lo(var7f1adf10)($at)
/*  f0e1334:	3c017f1b */ 	lui	$at,%hi(var7f1adf14)
/*  f0e1338:	2419007f */ 	addiu	$t9,$zero,0x7f
/*  f0e133c:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0e1340:	00000000 */ 	nop
/*  f0e1344:	4502002b */ 	bc1fl	.L0f0e13f4
/*  f0e1348:	ae990000 */ 	sw	$t9,0x0($s4)
/*  f0e134c:	4600f081 */ 	sub.s	$f2,$f30,$f0
/*  f0e1350:	c432df14 */ 	lwc1	$f18,%lo(var7f1adf14)($at)
/*  f0e1354:	3c0142fe */ 	lui	$at,0x42fe
/*  f0e1358:	44813000 */ 	mtc1	$at,$f6
/*  f0e135c:	46121103 */ 	div.s	$f4,$f2,$f18
/*  f0e1360:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0e1364:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e1368:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e136c:	444ff800 */ 	cfc1	$t7,$31
/*  f0e1370:	44d8f800 */ 	ctc1	$t8,$31
/*  f0e1374:	00000000 */ 	nop
/*  f0e1378:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0e137c:	4458f800 */ 	cfc1	$t8,$31
/*  f0e1380:	00000000 */ 	nop
/*  f0e1384:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0e1388:	53000013 */ 	beqzl	$t8,.L0f0e13d8
/*  f0e138c:	44185000 */ 	mfc1	$t8,$f10
/*  f0e1390:	44815000 */ 	mtc1	$at,$f10
/*  f0e1394:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0e1398:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0e139c:	44d8f800 */ 	ctc1	$t8,$31
/*  f0e13a0:	00000000 */ 	nop
/*  f0e13a4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0e13a8:	4458f800 */ 	cfc1	$t8,$31
/*  f0e13ac:	00000000 */ 	nop
/*  f0e13b0:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0e13b4:	17000005 */ 	bnez	$t8,.L0f0e13cc
/*  f0e13b8:	00000000 */ 	nop
/*  f0e13bc:	44185000 */ 	mfc1	$t8,$f10
/*  f0e13c0:	3c018000 */ 	lui	$at,0x8000
/*  f0e13c4:	10000007 */ 	b	.L0f0e13e4
/*  f0e13c8:	0301c025 */ 	or	$t8,$t8,$at
.L0f0e13cc:
/*  f0e13cc:	10000005 */ 	b	.L0f0e13e4
/*  f0e13d0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0e13d4:	44185000 */ 	mfc1	$t8,$f10
.L0f0e13d8:
/*  f0e13d8:	00000000 */ 	nop
/*  f0e13dc:	0700fffb */ 	bltz	$t8,.L0f0e13cc
/*  f0e13e0:	00000000 */ 	nop
.L0f0e13e4:
/*  f0e13e4:	44cff800 */ 	ctc1	$t7,$31
/*  f0e13e8:	10000003 */ 	b	.L0f0e13f8
/*  f0e13ec:	ae980000 */ 	sw	$t8,0x0($s4)
/*  f0e13f0:	ae990000 */ 	sw	$t9,0x0($s4)
.L0f0e13f4:
/*  f0e13f4:	4600f081 */ 	sub.s	$f2,$f30,$f0
.L0f0e13f8:
/*  f0e13f8:	3c017f1b */ 	lui	$at,%hi(var7f1adf18)
/*  f0e13fc:	c430df18 */ 	lwc1	$f16,%lo(var7f1adf18)($at)
/*  f0e1400:	3c014170 */ 	lui	$at,0x4170
/*  f0e1404:	44812000 */ 	mtc1	$at,$f4
/*  f0e1408:	46101480 */ 	add.s	$f18,$f2,$f16
/*  f0e140c:	c7a60098 */ 	lwc1	$f6,0x98($sp)
/*  f0e1410:	4600d306 */ 	mov.s	$f12,$f26
/*  f0e1414:	46049502 */ 	mul.s	$f20,$f18,$f4
/*  f0e1418:	00000000 */ 	nop
/*  f0e141c:	46143602 */ 	mul.s	$f24,$f6,$f20
/*  f0e1420:	0c0068f7 */ 	jal	sinf
/*  f0e1424:	4600c706 */ 	mov.s	$f28,$f24
/*  f0e1428:	c7a8009c */ 	lwc1	$f8,0x9c($sp)
/*  f0e142c:	4600d306 */ 	mov.s	$f12,$f26
/*  f0e1430:	46144582 */ 	mul.s	$f22,$f8,$f20
/*  f0e1434:	00000000 */ 	nop
/*  f0e1438:	46160282 */ 	mul.s	$f10,$f0,$f22
/*  f0e143c:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e1440:	44128000 */ 	mfc1	$s2,$f16
/*  f0e1444:	00000000 */ 	nop
/*  f0e1448:	00125400 */ 	sll	$t2,$s2,0x10
/*  f0e144c:	0c0068f4 */ 	jal	cosf
/*  f0e1450:	000a9403 */ 	sra	$s2,$t2,0x10
/*  f0e1454:	46180482 */ 	mul.s	$f18,$f0,$f24
/*  f0e1458:	4600d306 */ 	mov.s	$f12,$f26
/*  f0e145c:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e1460:	44132000 */ 	mfc1	$s3,$f4
/*  f0e1464:	00000000 */ 	nop
/*  f0e1468:	00136c00 */ 	sll	$t5,$s3,0x10
/*  f0e146c:	0c0068f4 */ 	jal	cosf
/*  f0e1470:	000d9c03 */ 	sra	$s3,$t5,0x10
/*  f0e1474:	46160182 */ 	mul.s	$f6,$f0,$f22
/*  f0e1478:	4600d306 */ 	mov.s	$f12,$f26
/*  f0e147c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0e1480:	44104000 */ 	mfc1	$s0,$f8
/*  f0e1484:	00000000 */ 	nop
/*  f0e1488:	0010c400 */ 	sll	$t8,$s0,0x10
/*  f0e148c:	0c0068f7 */ 	jal	sinf
/*  f0e1490:	00188403 */ 	sra	$s0,$t8,0x10
/*  f0e1494:	46000287 */ 	neg.s	$f10,$f0
/*  f0e1498:	02d23023 */ 	subu	$a2,$s6,$s2
/*  f0e149c:	461c5402 */ 	mul.s	$f16,$f10,$f28
/*  f0e14a0:	00d05023 */ 	subu	$t2,$a2,$s0
/*  f0e14a4:	02d33823 */ 	subu	$a3,$s6,$s3
/*  f0e14a8:	02d22021 */ 	addu	$a0,$s6,$s2
/*  f0e14ac:	02d32821 */ 	addu	$a1,$s6,$s3
/*  f0e14b0:	a62a0008 */ 	sh	$t2,0x8($s1)
/*  f0e14b4:	26b50030 */ 	addiu	$s5,$s5,0x30
/*  f0e14b8:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e14bc:	24010060 */ 	addiu	$at,$zero,0x60
/*  f0e14c0:	00907823 */ 	subu	$t7,$a0,$s0
/*  f0e14c4:	0090c821 */ 	addu	$t9,$a0,$s0
/*  f0e14c8:	440d9000 */ 	mfc1	$t5,$f18
/*  f0e14cc:	00d05021 */ 	addu	$t2,$a2,$s0
/*  f0e14d0:	26d60100 */ 	addiu	$s6,$s6,0x100
/*  f0e14d4:	00ed7023 */ 	subu	$t6,$a3,$t5
/*  f0e14d8:	00adc023 */ 	subu	$t8,$a1,$t5
/*  f0e14dc:	00ad4821 */ 	addu	$t1,$a1,$t5
/*  f0e14e0:	00ed5821 */ 	addu	$t3,$a3,$t5
/*  f0e14e4:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f0e14e8:	26310030 */ 	addiu	$s1,$s1,0x30
/*  f0e14ec:	a62effda */ 	sh	$t6,-0x26($s1)
/*  f0e14f0:	a62fffe4 */ 	sh	$t7,-0x1c($s1)
/*  f0e14f4:	a638ffe6 */ 	sh	$t8,-0x1a($s1)
/*  f0e14f8:	a639fff0 */ 	sh	$t9,-0x10($s1)
/*  f0e14fc:	a629fff2 */ 	sh	$t1,-0xe($s1)
/*  f0e1500:	a62afffc */ 	sh	$t2,-0x4($s1)
/*  f0e1504:	16a1ff49 */ 	bne	$s5,$at,.L0f0e122c
/*  f0e1508:	a62bfffe */ 	sh	$t3,-0x2($s1)
/*  f0e150c:	8fa40110 */ 	lw	$a0,0x110($sp)
/*  f0e1510:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f0e1514:	2403000c */ 	addiu	$v1,$zero,0xc
/*  f0e1518:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0e151c:	a2e00007 */ 	sb	$zero,0x7($s7)
/*  f0e1520:	a2e00013 */ 	sb	$zero,0x13($s7)
/*  f0e1524:	a2e2001f */ 	sb	$v0,0x1f($s7)
/*  f0e1528:	a2e2002b */ 	sb	$v0,0x2b($s7)
/*  f0e152c:	a2e30037 */ 	sb	$v1,0x37($s7)
/*  f0e1530:	a2e30043 */ 	sb	$v1,0x43($s7)
/*  f0e1534:	a2e5004f */ 	sb	$a1,0x4f($s7)
/*  f0e1538:	a2e5005b */ 	sb	$a1,0x5b($s7)
/*  f0e153c:	8fac0104 */ 	lw	$t4,0x104($sp)
/*  f0e1540:	3c0600af */ 	lui	$a2,0xaf
/*  f0e1544:	3c07ffff */ 	lui	$a3,0xffff
/*  f0e1548:	01866825 */ 	or	$t5,$t4,$a2
/*  f0e154c:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f0e1550:	8fae0104 */ 	lw	$t6,0x104($sp)
/*  f0e1554:	3c0d070c */ 	lui	$t5,0x70c
/*  f0e1558:	35ad0010 */ 	ori	$t5,$t5,0x10
/*  f0e155c:	01c77825 */ 	or	$t7,$t6,$a3
/*  f0e1560:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0e1564:	8fb80108 */ 	lw	$t8,0x108($sp)
/*  f0e1568:	0306c825 */ 	or	$t9,$t8,$a2
/*  f0e156c:	ac990008 */ 	sw	$t9,0x8($a0)
/*  f0e1570:	8fa90108 */ 	lw	$t1,0x108($sp)
/*  f0e1574:	01275025 */ 	or	$t2,$t1,$a3
/*  f0e1578:	ac8a000c */ 	sw	$t2,0xc($a0)
/*  f0e157c:	8fb00118 */ 	lw	$s0,0x118($sp)
/*  f0e1580:	260c0008 */ 	addiu	$t4,$s0,0x8
/*  f0e1584:	afac0118 */ 	sw	$t4,0x118($sp)
/*  f0e1588:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e158c:	ae0d0000 */ 	sw	$t5,0x0($s0)
/*  f0e1590:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f0e1594:	8fb10118 */ 	lw	$s1,0x118($sp)
/*  f0e1598:	3c180470 */ 	lui	$t8,0x470
/*  f0e159c:	37180060 */ 	ori	$t8,$t8,0x60
/*  f0e15a0:	262f0008 */ 	addiu	$t7,$s1,0x8
/*  f0e15a4:	afaf0118 */ 	sw	$t7,0x118($sp)
/*  f0e15a8:	02e02025 */ 	or	$a0,$s7,$zero
/*  f0e15ac:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e15b0:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f0e15b4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0e15b8:	44812000 */ 	mtc1	$at,$f4
/*  f0e15bc:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0e15c0:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f0e15c4:	c4261630 */ 	lwc1	$f6,%lo(var80061630)($at)
/*  f0e15c8:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f0e15cc:	3c0eb100 */ 	lui	$t6,0xb100
/*  f0e15d0:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e15d4:	3c0f7654 */ 	lui	$t7,0x7654
/*  f0e15d8:	35ef3210 */ 	ori	$t7,$t7,0x3210
/*  f0e15dc:	35ce4602 */ 	ori	$t6,$t6,0x4602
/*  f0e15e0:	4500000b */ 	bc1f	.L0f0e1610
/*  f0e15e4:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f0e15e8:	8fb90118 */ 	lw	$t9,0x118($sp)
/*  f0e15ec:	3c0ab100 */ 	lui	$t2,0xb100
/*  f0e15f0:	3c0b3210 */ 	lui	$t3,0x3210
/*  f0e15f4:	27290008 */ 	addiu	$t1,$t9,0x8
/*  f0e15f8:	afa90118 */ 	sw	$t1,0x118($sp)
/*  f0e15fc:	356b7654 */ 	ori	$t3,$t3,0x7654
/*  f0e1600:	354a0246 */ 	ori	$t2,$t2,0x246
/*  f0e1604:	af2a0000 */ 	sw	$t2,0x0($t9)
/*  f0e1608:	10000004 */ 	b	.L0f0e161c
/*  f0e160c:	af2b0004 */ 	sw	$t3,0x4($t9)
.L0f0e1610:
/*  f0e1610:	afad0118 */ 	sw	$t5,0x118($sp)
/*  f0e1614:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f0e1618:	ad8e0000 */ 	sw	$t6,0x0($t4)
.L0f0e161c:
/*  f0e161c:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f0e1620:	8fa20118 */ 	lw	$v0,0x118($sp)
/*  f0e1624:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f0e1628:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f0e162c:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f0e1630:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f0e1634:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f0e1638:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f0e163c:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f0e1640:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f0e1644:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0e1648:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f0e164c:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f0e1650:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f0e1654:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f0e1658:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f0e165c:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f0e1660:	03e00008 */ 	jr	$ra
/*  f0e1664:	27bd0118 */ 	addiu	$sp,$sp,0x118
);

GLOBAL_ASM(
glabel func0f0e1668
/*  f0e1668:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f0e166c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e1670:	afa40078 */ 	sw	$a0,0x78($sp)
/*  f0e1674:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0e1678:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0e167c:	afa5007c */ 	sw	$a1,0x7c($sp)
/*  f0e1680:	afa60080 */ 	sw	$a2,0x80($sp)
/*  f0e1684:	afa70084 */ 	sw	$a3,0x84($sp)
/*  f0e1688:	0fc59e73 */ 	jal	func0f1679cc
/*  f0e168c:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e1690:	00408825 */ 	or	$s1,$v0,$zero
/*  f0e1694:	0fc59e59 */ 	jal	func0f167964
/*  f0e1698:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f0e169c:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f0e16a0:	3c18e700 */ 	lui	$t8,0xe700
/*  f0e16a4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e16a8:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e16ac:	afaf0078 */ 	sw	$t7,0x78($sp)
/*  f0e16b0:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0e16b4:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e16b8:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f0e16bc:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0e16c0:	35ef1402 */ 	ori	$t7,$t7,0x1402
/*  f0e16c4:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0e16c8:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f0e16cc:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0e16d0:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f0e16d4:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f0e16d8:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0e16dc:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f0e16e0:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e16e4:	afb90078 */ 	sw	$t9,0x78($sp)
/*  f0e16e8:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0e16ec:	af0e0000 */ 	sw	$t6,0x0($t8)
/*  f0e16f0:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f0e16f4:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f0e16f8:	37397e24 */ 	ori	$t9,$t9,0x7e24
/*  f0e16fc:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e1700:	afb80078 */ 	sw	$t8,0x78($sp)
/*  f0e1704:	240ef9fc */ 	addiu	$t6,$zero,-1540
/*  f0e1708:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f0e170c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e1710:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f0e1714:	3c19b600 */ 	lui	$t9,0xb600
/*  f0e1718:	240e3000 */ 	addiu	$t6,$zero,0x3000
/*  f0e171c:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e1720:	afb80078 */ 	sw	$t8,0x78($sp)
/*  f0e1724:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f0e1728:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e172c:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f0e1730:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0e1734:	37390c02 */ 	ori	$t9,$t9,0xc02
/*  f0e1738:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e173c:	afb80078 */ 	sw	$t8,0x78($sp)
/*  f0e1740:	240e2000 */ 	addiu	$t6,$zero,0x2000
/*  f0e1744:	adee0004 */ 	sw	$t6,0x4($t7)
/*  f0e1748:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e174c:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0e1750:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0e1754:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e1758:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e175c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e1760:	27a40078 */ 	addiu	$a0,$sp,0x78
/*  f0e1764:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e1768:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0e176c:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0e1770:	00003825 */ 	or	$a3,$zero,$zero
/*  f0e1774:	8fac007c */ 	lw	$t4,0x7c($sp)
/*  f0e1778:	2408000a */ 	addiu	$t0,$zero,0xa
/*  f0e177c:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f0e1780:	01880019 */ 	multu	$t4,$t0
/*  f0e1784:	8fad0084 */ 	lw	$t5,0x84($sp)
/*  f0e1788:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f0e178c:	8faa0088 */ 	lw	$t2,0x88($sp)
/*  f0e1790:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0e1794:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0e1798:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f0e179c:	3c180050 */ 	lui	$t8,0x50
/*  f0e17a0:	37184240 */ 	ori	$t8,$t8,0x4240
/*  f0e17a4:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f0e17a8:	00002812 */ 	mflo	$a1
/*  f0e17ac:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f0e17b0:	af380004 */ 	sw	$t8,0x4($t9)
/*  f0e17b4:	01680019 */ 	multu	$t3,$t0
/*  f0e17b8:	03201025 */ 	or	$v0,$t9,$zero
/*  f0e17bc:	014b3821 */ 	addu	$a3,$t2,$t3
/*  f0e17c0:	2404fff6 */ 	addiu	$a0,$zero,-10
/*  f0e17c4:	a6040004 */ 	sh	$a0,0x4($s0)
/*  f0e17c8:	a6040010 */ 	sh	$a0,0x10($s0)
/*  f0e17cc:	a604001c */ 	sh	$a0,0x1c($s0)
/*  f0e17d0:	a6040028 */ 	sh	$a0,0x28($s0)
/*  f0e17d4:	a6040034 */ 	sh	$a0,0x34($s0)
/*  f0e17d8:	a6040040 */ 	sh	$a0,0x40($s0)
/*  f0e17dc:	00001812 */ 	mflo	$v1
/*  f0e17e0:	a6030002 */ 	sh	$v1,0x2($s0)
/*  f0e17e4:	a603000e */ 	sh	$v1,0xe($s0)
/*  f0e17e8:	01a80019 */ 	multu	$t5,$t0
/*  f0e17ec:	018d2021 */ 	addu	$a0,$t4,$t5
/*  f0e17f0:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f0e17f4:	a6050000 */ 	sh	$a1,0x0($s0)
/*  f0e17f8:	a6050018 */ 	sh	$a1,0x18($s0)
/*  f0e17fc:	a6050030 */ 	sh	$a1,0x30($s0)
/*  f0e1800:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0e1804:	a2000013 */ 	sb	$zero,0x13($s0)
/*  f0e1808:	a203001f */ 	sb	$v1,0x1f($s0)
/*  f0e180c:	a203002b */ 	sb	$v1,0x2b($s0)
/*  f0e1810:	00003012 */ 	mflo	$a2
/*  f0e1814:	a606000c */ 	sh	$a2,0xc($s0)
/*  f0e1818:	04e10003 */ 	bgez	$a3,.L0f0e1828
/*  f0e181c:	0007c843 */ 	sra	$t9,$a3,0x1
/*  f0e1820:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f0e1824:	0001c843 */ 	sra	$t9,$at,0x1
.L0f0e1828:
/*  f0e1828:	03280019 */ 	multu	$t9,$t0
/*  f0e182c:	a6060024 */ 	sh	$a2,0x24($s0)
/*  f0e1830:	a606003c */ 	sh	$a2,0x3c($s0)
/*  f0e1834:	03203825 */ 	or	$a3,$t9,$zero
/*  f0e1838:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0e183c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0e1840:	00004812 */ 	mflo	$t1
/*  f0e1844:	a609001a */ 	sh	$t1,0x1a($s0)
/*  f0e1848:	a6090026 */ 	sh	$t1,0x26($s0)
/*  f0e184c:	01480019 */ 	multu	$t2,$t0
/*  f0e1850:	00001012 */ 	mflo	$v0
/*  f0e1854:	a6020032 */ 	sh	$v0,0x32($s0)
/*  f0e1858:	a602003e */ 	sh	$v0,0x3e($s0)
/*  f0e185c:	24020008 */ 	addiu	$v0,$zero,0x8
/*  f0e1860:	a2020037 */ 	sb	$v0,0x37($s0)
/*  f0e1864:	a2020043 */ 	sb	$v0,0x43($s0)
/*  f0e1868:	04810003 */ 	bgez	$a0,.L0f0e1878
/*  f0e186c:	00047043 */ 	sra	$t6,$a0,0x1
/*  f0e1870:	24810001 */ 	addiu	$at,$a0,0x1
/*  f0e1874:	00017043 */ 	sra	$t6,$at,0x1
.L0f0e1878:
/*  f0e1878:	01c02025 */ 	or	$a0,$t6,$zero
/*  f0e187c:	afae003c */ 	sw	$t6,0x3c($sp)
/*  f0e1880:	0fc550eb */ 	jal	func0f1543ac
/*  f0e1884:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f0e1888:	304300ff */ 	andi	$v1,$v0,0xff
/*  f0e188c:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0e1890:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f0e1894:	afa3006c */ 	sw	$v1,0x6c($sp)
/*  f0e1898:	0fc550eb */ 	jal	func0f1543ac
/*  f0e189c:	2406ff7f */ 	addiu	$a2,$zero,-129
/*  f0e18a0:	8fa3006c */ 	lw	$v1,0x6c($sp)
/*  f0e18a4:	305800ff */ 	andi	$t8,$v0,0xff
/*  f0e18a8:	37196f00 */ 	ori	$t9,$t8,0x6f00
/*  f0e18ac:	346f6f00 */ 	ori	$t7,$v1,0x6f00
/*  f0e18b0:	346e3f00 */ 	ori	$t6,$v1,0x3f00
/*  f0e18b4:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f0e18b8:	ae390004 */ 	sw	$t9,0x4($s1)
/*  f0e18bc:	ae2e0008 */ 	sw	$t6,0x8($s1)
/*  f0e18c0:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f0e18c4:	3c190708 */ 	lui	$t9,0x708
/*  f0e18c8:	3739000c */ 	ori	$t9,$t9,0xc
/*  f0e18cc:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e18d0:	afb80078 */ 	sw	$t8,0x78($sp)
/*  f0e18d4:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e18d8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e18dc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e18e0:	afaf0048 */ 	sw	$t7,0x48($sp)
/*  f0e18e4:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f0e18e8:	3c180450 */ 	lui	$t8,0x450
/*  f0e18ec:	37180048 */ 	ori	$t8,$t8,0x48
/*  f0e18f0:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0e18f4:	8fb10078 */ 	lw	$s1,0x78($sp)
/*  f0e18f8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e18fc:	262f0008 */ 	addiu	$t7,$s1,0x8
/*  f0e1900:	afaf0078 */ 	sw	$t7,0x78($sp)
/*  f0e1904:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e1908:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f0e190c:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0e1910:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f0e1914:	3c0fb100 */ 	lui	$t7,0xb100
/*  f0e1918:	3c183432 */ 	lui	$t8,0x3432
/*  f0e191c:	272e0008 */ 	addiu	$t6,$t9,0x8
/*  f0e1920:	afae0078 */ 	sw	$t6,0x78($sp)
/*  f0e1924:	37182310 */ 	ori	$t8,$t8,0x2310
/*  f0e1928:	35ef5403 */ 	ori	$t7,$t7,0x5403
/*  f0e192c:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f0e1930:	af380004 */ 	sw	$t8,0x4($t9)
/*  f0e1934:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0e1938:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f0e193c:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f0e1940:	8fa20078 */ 	lw	$v0,0x78($sp)
/*  f0e1944:	03e00008 */ 	jr	$ra
/*  f0e1948:	27bd0078 */ 	addiu	$sp,$sp,0x78
);

GLOBAL_ASM(
glabel func0f0e194c
/*  f0e194c:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0e1950:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0e1954:	afa40068 */ 	sw	$a0,0x68($sp)
/*  f0e1958:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f0e195c:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f0e1960:	afa5006c */ 	sw	$a1,0x6c($sp)
/*  f0e1964:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f0e1968:	afa70074 */ 	sw	$a3,0x74($sp)
/*  f0e196c:	0fc59e73 */ 	jal	func0f1679cc
/*  f0e1970:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f0e1974:	00408825 */ 	or	$s1,$v0,$zero
/*  f0e1978:	0fc59e59 */ 	jal	func0f167964
/*  f0e197c:	24040009 */ 	addiu	$a0,$zero,0x9
/*  f0e1980:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f0e1984:	3c18e700 */ 	lui	$t8,0xe700
/*  f0e1988:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0e198c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e1990:	afaf0068 */ 	sw	$t7,0x68($sp)
/*  f0e1994:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0e1998:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e199c:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f0e19a0:	35ad1402 */ 	ori	$t5,$t5,0x1402
/*  f0e19a4:	3c18b900 */ 	lui	$t8,0xb900
/*  f0e19a8:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0e19ac:	afac0068 */ 	sw	$t4,0x68($sp)
/*  f0e19b0:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0e19b4:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0e19b8:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f0e19bc:	37180002 */ 	ori	$t8,$t8,0x2
/*  f0e19c0:	3c0dfc12 */ 	lui	$t5,0xfc12
/*  f0e19c4:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e19c8:	afaf0068 */ 	sw	$t7,0x68($sp)
/*  f0e19cc:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0e19d0:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e19d4:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f0e19d8:	240ef9fc */ 	addiu	$t6,$zero,-1540
/*  f0e19dc:	35ad7e24 */ 	ori	$t5,$t5,0x7e24
/*  f0e19e0:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0e19e4:	afac0068 */ 	sw	$t4,0x68($sp)
/*  f0e19e8:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f0e19ec:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0e19f0:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f0e19f4:	3c19b600 */ 	lui	$t9,0xb600
/*  f0e19f8:	240c3000 */ 	addiu	$t4,$zero,0x3000
/*  f0e19fc:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e1a00:	afb80068 */ 	sw	$t8,0x68($sp)
/*  f0e1a04:	adec0004 */ 	sw	$t4,0x4($t7)
/*  f0e1a08:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e1a0c:	8fad0068 */ 	lw	$t5,0x68($sp)
/*  f0e1a10:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0e1a14:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f0e1a18:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0e1a1c:	afae0068 */ 	sw	$t6,0x68($sp)
/*  f0e1a20:	24182000 */ 	addiu	$t8,$zero,0x2000
/*  f0e1a24:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f0e1a28:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0e1a2c:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0e1a30:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0e1a34:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e1a38:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0e1a3c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e1a40:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e1a44:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0e1a48:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e1a4c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0e1a50:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0e1a54:	00003825 */ 	or	$a3,$zero,$zero
/*  f0e1a58:	8fa30068 */ 	lw	$v1,0x68($sp)
/*  f0e1a5c:	8faa0078 */ 	lw	$t2,0x78($sp)
/*  f0e1a60:	8fab0070 */ 	lw	$t3,0x70($sp)
/*  f0e1a64:	246e0008 */ 	addiu	$t6,$v1,0x8
/*  f0e1a68:	afae0068 */ 	sw	$t6,0x68($sp)
/*  f0e1a6c:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0e1a70:	3c180050 */ 	lui	$t8,0x50
/*  f0e1a74:	37184240 */ 	ori	$t8,$t8,0x4240
/*  f0e1a78:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f0e1a7c:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0e1a80:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f0e1a84:	8fb9006c */ 	lw	$t9,0x6c($sp)
/*  f0e1a88:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0e1a8c:	2402fff6 */ 	addiu	$v0,$zero,-10
/*  f0e1a90:	03240019 */ 	multu	$t9,$a0
/*  f0e1a94:	a6020004 */ 	sh	$v0,0x4($s0)
/*  f0e1a98:	014b6821 */ 	addu	$t5,$t2,$t3
/*  f0e1a9c:	24180018 */ 	addiu	$t8,$zero,0x18
/*  f0e1aa0:	2419000c */ 	addiu	$t9,$zero,0xc
/*  f0e1aa4:	00002812 */ 	mflo	$a1
/*  f0e1aa8:	a6050000 */ 	sh	$a1,0x0($s0)
/*  f0e1aac:	00000000 */ 	nop
/*  f0e1ab0:	01640019 */ 	multu	$t3,$a0
/*  f0e1ab4:	00003012 */ 	mflo	$a2
/*  f0e1ab8:	a6060002 */ 	sh	$a2,0x2($s0)
/*  f0e1abc:	8fac0074 */ 	lw	$t4,0x74($sp)
/*  f0e1ac0:	a606000e */ 	sh	$a2,0xe($s0)
/*  f0e1ac4:	a6020010 */ 	sh	$v0,0x10($s0)
/*  f0e1ac8:	01840019 */ 	multu	$t4,$a0
/*  f0e1acc:	a6050018 */ 	sh	$a1,0x18($s0)
/*  f0e1ad0:	a602001c */ 	sh	$v0,0x1c($s0)
/*  f0e1ad4:	a6020028 */ 	sh	$v0,0x28($s0)
/*  f0e1ad8:	a6050030 */ 	sh	$a1,0x30($s0)
/*  f0e1adc:	a6020034 */ 	sh	$v0,0x34($s0)
/*  f0e1ae0:	a6020040 */ 	sh	$v0,0x40($s0)
/*  f0e1ae4:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f0e1ae8:	240c0010 */ 	addiu	$t4,$zero,0x10
/*  f0e1aec:	00003812 */ 	mflo	$a3
/*  f0e1af0:	a607000c */ 	sh	$a3,0xc($s0)
/*  f0e1af4:	05a10003 */ 	bgez	$t5,.L0f0e1b04
/*  f0e1af8:	000d7043 */ 	sra	$t6,$t5,0x1
/*  f0e1afc:	25a10001 */ 	addiu	$at,$t5,0x1
/*  f0e1b00:	00017043 */ 	sra	$t6,$at,0x1
.L0f0e1b04:
/*  f0e1b04:	01c40019 */ 	multu	$t6,$a0
/*  f0e1b08:	a6070024 */ 	sh	$a3,0x24($s0)
/*  f0e1b0c:	a607003c */ 	sh	$a3,0x3c($s0)
/*  f0e1b10:	240d0014 */ 	addiu	$t5,$zero,0x14
/*  f0e1b14:	3c016f6f */ 	lui	$at,0x6f6f
/*  f0e1b18:	34216f00 */ 	ori	$at,$at,0x6f00
/*  f0e1b1c:	00004012 */ 	mflo	$t0
/*  f0e1b20:	a608001a */ 	sh	$t0,0x1a($s0)
/*  f0e1b24:	a6080026 */ 	sh	$t0,0x26($s0)
/*  f0e1b28:	01440019 */ 	multu	$t2,$a0
/*  f0e1b2c:	00001812 */ 	mflo	$v1
/*  f0e1b30:	a6030032 */ 	sh	$v1,0x32($s0)
/*  f0e1b34:	a603003e */ 	sh	$v1,0x3e($s0)
/*  f0e1b38:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f0e1b3c:	a606004a */ 	sh	$a2,0x4a($s0)
/*  f0e1b40:	a602004c */ 	sh	$v0,0x4c($s0)
/*  f0e1b44:	01e40019 */ 	multu	$t7,$a0
/*  f0e1b48:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0e1b4c:	a6080056 */ 	sh	$t0,0x56($s0)
/*  f0e1b50:	a6020058 */ 	sh	$v0,0x58($s0)
/*  f0e1b54:	a6030062 */ 	sh	$v1,0x62($s0)
/*  f0e1b58:	a6020064 */ 	sh	$v0,0x64($s0)
/*  f0e1b5c:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0e1b60:	a2180013 */ 	sb	$t8,0x13($s0)
/*  f0e1b64:	a204001f */ 	sb	$a0,0x1f($s0)
/*  f0e1b68:	a204002b */ 	sb	$a0,0x2b($s0)
/*  f0e1b6c:	00004812 */ 	mflo	$t1
/*  f0e1b70:	a6090048 */ 	sh	$t1,0x48($s0)
/*  f0e1b74:	a6090054 */ 	sh	$t1,0x54($s0)
/*  f0e1b78:	a6090060 */ 	sh	$t1,0x60($s0)
/*  f0e1b7c:	a2050037 */ 	sb	$a1,0x37($s0)
/*  f0e1b80:	a2050043 */ 	sb	$a1,0x43($s0)
/*  f0e1b84:	a219004f */ 	sb	$t9,0x4f($s0)
/*  f0e1b88:	a20c005b */ 	sb	$t4,0x5b($s0)
/*  f0e1b8c:	93a50083 */ 	lbu	$a1,0x83($sp)
/*  f0e1b90:	a20d0067 */ 	sb	$t5,0x67($s0)
/*  f0e1b94:	2406ff00 */ 	addiu	$a2,$zero,-256
/*  f0e1b98:	34a26f00 */ 	ori	$v0,$a1,0x6f00
/*  f0e1b9c:	34a33f00 */ 	ori	$v1,$a1,0x3f00
/*  f0e1ba0:	00467024 */ 	and	$t6,$v0,$a2
/*  f0e1ba4:	00667824 */ 	and	$t7,$v1,$a2
/*  f0e1ba8:	00a1c025 */ 	or	$t8,$a1,$at
/*  f0e1bac:	ae220000 */ 	sw	$v0,0x0($s1)
/*  f0e1bb0:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0e1bb4:	ae230008 */ 	sw	$v1,0x8($s1)
/*  f0e1bb8:	ae26000c */ 	sw	$a2,0xc($s1)
/*  f0e1bbc:	ae2e0010 */ 	sw	$t6,0x10($s1)
/*  f0e1bc0:	ae2f0014 */ 	sw	$t7,0x14($s1)
/*  f0e1bc4:	ae380018 */ 	sw	$t8,0x18($s1)
/*  f0e1bc8:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f0e1bcc:	3c0d0718 */ 	lui	$t5,0x718
/*  f0e1bd0:	35ad001c */ 	ori	$t5,$t5,0x1c
/*  f0e1bd4:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0e1bd8:	afac0068 */ 	sw	$t4,0x68($sp)
/*  f0e1bdc:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0e1be0:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e1be4:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e1be8:	afb90038 */ 	sw	$t9,0x38($sp)
/*  f0e1bec:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f0e1bf0:	3c180480 */ 	lui	$t8,0x480
/*  f0e1bf4:	3718006c */ 	ori	$t8,$t8,0x6c
/*  f0e1bf8:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f0e1bfc:	8fb10068 */ 	lw	$s1,0x68($sp)
/*  f0e1c00:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e1c04:	262f0008 */ 	addiu	$t7,$s1,0x8
/*  f0e1c08:	afaf0068 */ 	sw	$t7,0x68($sp)
/*  f0e1c0c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e1c10:	ae380000 */ 	sw	$t8,0x0($s1)
/*  f0e1c14:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0e1c18:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f0e1c1c:	3c0db100 */ 	lui	$t5,0xb100
/*  f0e1c20:	3c0e3432 */ 	lui	$t6,0x3432
/*  f0e1c24:	272c0008 */ 	addiu	$t4,$t9,0x8
/*  f0e1c28:	afac0068 */ 	sw	$t4,0x68($sp)
/*  f0e1c2c:	35ce2310 */ 	ori	$t6,$t6,0x2310
/*  f0e1c30:	35ad5403 */ 	ori	$t5,$t5,0x5403
/*  f0e1c34:	af2d0000 */ 	sw	$t5,0x0($t9)
/*  f0e1c38:	af2e0004 */ 	sw	$t6,0x4($t9)
/*  f0e1c3c:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f0e1c40:	3c19b100 */ 	lui	$t9,0xb100
/*  f0e1c44:	3c0c5873 */ 	lui	$t4,0x5873
/*  f0e1c48:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e1c4c:	afb80068 */ 	sw	$t8,0x68($sp)
/*  f0e1c50:	358c3761 */ 	ori	$t4,$t4,0x3761
/*  f0e1c54:	37393817 */ 	ori	$t9,$t9,0x3817
/*  f0e1c58:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e1c5c:	adec0004 */ 	sw	$t4,0x4($t7)
/*  f0e1c60:	93af0083 */ 	lbu	$t7,0x83($sp)
/*  f0e1c64:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f0e1c68:	240c0028 */ 	addiu	$t4,$zero,0x28
/*  f0e1c6c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0e1c70:	000f8082 */ 	srl	$s0,$t7,0x2
/*  f0e1c74:	24ce0001 */ 	addiu	$t6,$a2,0x1
/*  f0e1c78:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e1c7c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e1c80:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0e1c84:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0e1c88:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0e1c8c:	8fa70074 */ 	lw	$a3,0x74($sp)
/*  f0e1c90:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f0e1c94:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0e1c98:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f0e1c9c:	8fa60078 */ 	lw	$a2,0x78($sp)
/*  f0e1ca0:	240e0028 */ 	addiu	$t6,$zero,0x28
/*  f0e1ca4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e1ca8:	24cd0001 */ 	addiu	$t5,$a2,0x1
/*  f0e1cac:	afa20068 */ 	sw	$v0,0x68($sp)
/*  f0e1cb0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e1cb4:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0e1cb8:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0e1cbc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e1cc0:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f0e1cc4:	8fa70074 */ 	lw	$a3,0x74($sp)
/*  f0e1cc8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e1ccc:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0e1cd0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e1cd4:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0e1cd8:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f0e1cdc:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f0e1ce0:	03e00008 */ 	jr	$ra
/*  f0e1ce4:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel func0f0e1ce8
/*  f0e1ce8:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0e1cec:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e1cf0:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f0e1cf4:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0e1cf8:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0e1cfc:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f0e1d00:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f0e1d04:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f0e1d08:	0fc59e73 */ 	jal	func0f1679cc
/*  f0e1d0c:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e1d10:	00408825 */ 	or	$s1,$v0,$zero
/*  f0e1d14:	0fc59e59 */ 	jal	func0f167964
/*  f0e1d18:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f0e1d1c:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f0e1d20:	3c18e700 */ 	lui	$t8,0xe700
/*  f0e1d24:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e1d28:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e1d2c:	afaf0060 */ 	sw	$t7,0x60($sp)
/*  f0e1d30:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0e1d34:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e1d38:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0e1d3c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0e1d40:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f0e1d44:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0e1d48:	afad0060 */ 	sw	$t5,0x60($sp)
/*  f0e1d4c:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0e1d50:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0e1d54:	8faf0060 */ 	lw	$t7,0x60($sp)
/*  f0e1d58:	3c19b900 */ 	lui	$t9,0xb900
/*  f0e1d5c:	37390002 */ 	ori	$t9,$t9,0x2
/*  f0e1d60:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e1d64:	afb80060 */ 	sw	$t8,0x60($sp)
/*  f0e1d68:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f0e1d6c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e1d70:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0e1d74:	3c0ffc12 */ 	lui	$t7,0xfc12
/*  f0e1d78:	35ef7e24 */ 	ori	$t7,$t7,0x7e24
/*  f0e1d7c:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0e1d80:	afae0060 */ 	sw	$t6,0x60($sp)
/*  f0e1d84:	2418f9fc */ 	addiu	$t8,$zero,-1540
/*  f0e1d88:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f0e1d8c:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0e1d90:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0e1d94:	240f3000 */ 	addiu	$t7,$zero,0x3000
/*  f0e1d98:	3c0eb600 */ 	lui	$t6,0xb600
/*  f0e1d9c:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0e1da0:	afad0060 */ 	sw	$t5,0x60($sp)
/*  f0e1da4:	af2f0004 */ 	sw	$t7,0x4($t9)
/*  f0e1da8:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0e1dac:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0e1db0:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0e1db4:	35ad0c02 */ 	ori	$t5,$t5,0xc02
/*  f0e1db8:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e1dbc:	afb90060 */ 	sw	$t9,0x60($sp)
/*  f0e1dc0:	240e2000 */ 	addiu	$t6,$zero,0x2000
/*  f0e1dc4:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f0e1dc8:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0e1dcc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0e1dd0:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0e1dd4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e1dd8:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e1ddc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e1de0:	27a40060 */ 	addiu	$a0,$sp,0x60
/*  f0e1de4:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e1de8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0e1dec:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0e1df0:	00003825 */ 	or	$a3,$zero,$zero
/*  f0e1df4:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0e1df8:	8fab0070 */ 	lw	$t3,0x70($sp)
/*  f0e1dfc:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f0e1e00:	8fa9006c */ 	lw	$t1,0x6c($sp)
/*  f0e1e04:	8faa0064 */ 	lw	$t2,0x64($sp)
/*  f0e1e08:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0e1e0c:	afad0060 */ 	sw	$t5,0x60($sp)
/*  f0e1e10:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0e1e14:	3c0f0050 */ 	lui	$t7,0x50
/*  f0e1e18:	018b4021 */ 	addu	$t0,$t4,$t3
/*  f0e1e1c:	35ef4240 */ 	ori	$t7,$t7,0x4240
/*  f0e1e20:	35ce031d */ 	ori	$t6,$t6,0x31d
/*  f0e1e24:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0e1e28:	af2f0004 */ 	sw	$t7,0x4($t9)
/*  f0e1e2c:	03201025 */ 	or	$v0,$t9,$zero
/*  f0e1e30:	05010003 */ 	bgez	$t0,.L0f0e1e40
/*  f0e1e34:	0008c043 */ 	sra	$t8,$t0,0x1
/*  f0e1e38:	25010001 */ 	addiu	$at,$t0,0x1
/*  f0e1e3c:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0e1e40:
/*  f0e1e40:	0018c840 */ 	sll	$t9,$t8,0x1
/*  f0e1e44:	012a2023 */ 	subu	$a0,$t1,$t2
/*  f0e1e48:	0099082a */ 	slt	$at,$a0,$t9
/*  f0e1e4c:	10200001 */ 	beqz	$at,.L0f0e1e54
/*  f0e1e50:	03004025 */ 	or	$t0,$t8,$zero
.L0f0e1e54:
/*  f0e1e54:	2406000a */ 	addiu	$a2,$zero,0xa
/*  f0e1e58:	01460019 */ 	multu	$t2,$a2
/*  f0e1e5c:	2407fff6 */ 	addiu	$a3,$zero,-10
/*  f0e1e60:	a6070004 */ 	sh	$a3,0x4($s0)
/*  f0e1e64:	a6070010 */ 	sh	$a3,0x10($s0)
/*  f0e1e68:	a607001c */ 	sh	$a3,0x1c($s0)
/*  f0e1e6c:	a6070028 */ 	sh	$a3,0x28($s0)
/*  f0e1e70:	a6070034 */ 	sh	$a3,0x34($s0)
/*  f0e1e74:	a6070040 */ 	sh	$a3,0x40($s0)
/*  f0e1e78:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0e1e7c:	a2000013 */ 	sb	$zero,0x13($s0)
/*  f0e1e80:	00001012 */ 	mflo	$v0
/*  f0e1e84:	a6020000 */ 	sh	$v0,0x0($s0)
/*  f0e1e88:	a6020024 */ 	sh	$v0,0x24($s0)
/*  f0e1e8c:	01860019 */ 	multu	$t4,$a2
/*  f0e1e90:	00001812 */ 	mflo	$v1
/*  f0e1e94:	a6030002 */ 	sh	$v1,0x2($s0)
/*  f0e1e98:	a603000e */ 	sh	$v1,0xe($s0)
/*  f0e1e9c:	01260019 */ 	multu	$t1,$a2
/*  f0e1ea0:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f0e1ea4:	a203001f */ 	sb	$v1,0x1f($s0)
/*  f0e1ea8:	a203002b */ 	sb	$v1,0x2b($s0)
/*  f0e1eac:	00002012 */ 	mflo	$a0
/*  f0e1eb0:	a604000c */ 	sh	$a0,0xc($s0)
/*  f0e1eb4:	a6040018 */ 	sh	$a0,0x18($s0)
/*  f0e1eb8:	01660019 */ 	multu	$t3,$a2
/*  f0e1ebc:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f0e1ec0:	a2040037 */ 	sb	$a0,0x37($s0)
/*  f0e1ec4:	a2040043 */ 	sb	$a0,0x43($s0)
/*  f0e1ec8:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e1ecc:	00002812 */ 	mflo	$a1
/*  f0e1ed0:	a605001a */ 	sh	$a1,0x1a($s0)
/*  f0e1ed4:	a6050026 */ 	sh	$a1,0x26($s0)
/*  f0e1ed8:	01460019 */ 	multu	$t2,$a2
/*  f0e1edc:	00006812 */ 	mflo	$t5
/*  f0e1ee0:	a60d0030 */ 	sh	$t5,0x30($s0)
/*  f0e1ee4:	00000000 */ 	nop
/*  f0e1ee8:	01060019 */ 	multu	$t0,$a2
/*  f0e1eec:	00001012 */ 	mflo	$v0
/*  f0e1ef0:	a6020032 */ 	sh	$v0,0x32($s0)
/*  f0e1ef4:	a602003e */ 	sh	$v0,0x3e($s0)
/*  f0e1ef8:	01260019 */ 	multu	$t1,$a2
/*  f0e1efc:	00007012 */ 	mflo	$t6
/*  f0e1f00:	a60e003c */ 	sh	$t6,0x3c($s0)
/*  f0e1f04:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0e1f08:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f0e1f0c:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f0e1f10:	3c0f0708 */ 	lui	$t7,0x708
/*  f0e1f14:	35ef000c */ 	ori	$t7,$t7,0xc
/*  f0e1f18:	ae380008 */ 	sw	$t8,0x8($s1)
/*  f0e1f1c:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*  f0e1f20:	ae390004 */ 	sw	$t9,0x4($s1)
/*  f0e1f24:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0e1f28:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0e1f2c:	afae0060 */ 	sw	$t6,0x60($sp)
/*  f0e1f30:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0e1f34:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e1f38:	afad0034 */ 	sw	$t5,0x34($sp)
/*  f0e1f3c:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f0e1f40:	3c0d0450 */ 	lui	$t5,0x450
/*  f0e1f44:	35ad0048 */ 	ori	$t5,$t5,0x48
/*  f0e1f48:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0e1f4c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0e1f50:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e1f54:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e1f58:	afb90060 */ 	sw	$t9,0x60($sp)
/*  f0e1f5c:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0e1f60:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e1f64:	afb80030 */ 	sw	$t8,0x30($sp)
/*  f0e1f68:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f0e1f6c:	3c18b100 */ 	lui	$t8,0xb100
/*  f0e1f70:	3c195432 */ 	lui	$t9,0x5432
/*  f0e1f74:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0e1f78:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f0e1f7c:	37394510 */ 	ori	$t9,$t9,0x4510
/*  f0e1f80:	37182405 */ 	ori	$t8,$t8,0x2405
/*  f0e1f84:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e1f88:	afaf0060 */ 	sw	$t7,0x60($sp)
/*  f0e1f8c:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0e1f90:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e1f94:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0e1f98:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f0e1f9c:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f0e1fa0:	8fa20060 */ 	lw	$v0,0x60($sp)
/*  f0e1fa4:	03e00008 */ 	jr	$ra
/*  f0e1fa8:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f0e1fac
/*  f0e1fac:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0e1fb0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e1fb4:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f0e1fb8:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0e1fbc:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0e1fc0:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f0e1fc4:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f0e1fc8:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f0e1fcc:	0fc59e73 */ 	jal	func0f1679cc
/*  f0e1fd0:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e1fd4:	00408825 */ 	or	$s1,$v0,$zero
/*  f0e1fd8:	0fc59e59 */ 	jal	func0f167964
/*  f0e1fdc:	24040006 */ 	addiu	$a0,$zero,0x6
/*  f0e1fe0:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f0e1fe4:	3c18e700 */ 	lui	$t8,0xe700
/*  f0e1fe8:	3c0cba00 */ 	lui	$t4,0xba00
/*  f0e1fec:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e1ff0:	afaf0060 */ 	sw	$t7,0x60($sp)
/*  f0e1ff4:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0e1ff8:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e1ffc:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0e2000:	358c1402 */ 	ori	$t4,$t4,0x1402
/*  f0e2004:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0e2008:	272b0008 */ 	addiu	$t3,$t9,0x8
/*  f0e200c:	afab0060 */ 	sw	$t3,0x60($sp)
/*  f0e2010:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0e2014:	af2c0000 */ 	sw	$t4,0x0($t9)
/*  f0e2018:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0e201c:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f0e2020:	3c0bfc12 */ 	lui	$t3,0xfc12
/*  f0e2024:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0e2028:	afae0060 */ 	sw	$t6,0x60($sp)
/*  f0e202c:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f0e2030:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0e2034:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0e2038:	356b7e24 */ 	ori	$t3,$t3,0x7e24
/*  f0e203c:	240cf9fc */ 	addiu	$t4,$zero,-1540
/*  f0e2040:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e2044:	afb90060 */ 	sw	$t9,0x60($sp)
/*  f0e2048:	af0c0004 */ 	sw	$t4,0x4($t8)
/*  f0e204c:	af0b0000 */ 	sw	$t3,0x0($t8)
/*  f0e2050:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0e2054:	24183000 */ 	addiu	$t8,$zero,0x3000
/*  f0e2058:	3c0fb600 */ 	lui	$t7,0xb600
/*  f0e205c:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0e2060:	afae0060 */ 	sw	$t6,0x60($sp)
/*  f0e2064:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f0e2068:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0e206c:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0e2070:	3c0cba00 */ 	lui	$t4,0xba00
/*  f0e2074:	358c0c02 */ 	ori	$t4,$t4,0xc02
/*  f0e2078:	272b0008 */ 	addiu	$t3,$t9,0x8
/*  f0e207c:	afab0060 */ 	sw	$t3,0x60($sp)
/*  f0e2080:	240d2000 */ 	addiu	$t5,$zero,0x2000
/*  f0e2084:	af2d0004 */ 	sw	$t5,0x4($t9)
/*  f0e2088:	af2c0000 */ 	sw	$t4,0x0($t9)
/*  f0e208c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e2090:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f0e2094:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e2098:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e209c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e20a0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e20a4:	27a40060 */ 	addiu	$a0,$sp,0x60
/*  f0e20a8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e20ac:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0e20b0:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0e20b4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0e20b8:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0e20bc:	3c09b900 */ 	lui	$t1,0xb900
/*  f0e20c0:	3c0b0050 */ 	lui	$t3,0x50
/*  f0e20c4:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e20c8:	afb90060 */ 	sw	$t9,0x60($sp)
/*  f0e20cc:	3529031d */ 	ori	$t1,$t1,0x31d
/*  f0e20d0:	356b41c8 */ 	ori	$t3,$t3,0x41c8
/*  f0e20d4:	af0b0004 */ 	sw	$t3,0x4($t8)
/*  f0e20d8:	af090000 */ 	sw	$t1,0x0($t8)
/*  f0e20dc:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f0e20e0:	3c0e0050 */ 	lui	$t6,0x50
/*  f0e20e4:	35ce4240 */ 	ori	$t6,$t6,0x4240
/*  f0e20e8:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f0e20ec:	afad0060 */ 	sw	$t5,0x60($sp)
/*  f0e20f0:	ad8e0004 */ 	sw	$t6,0x4($t4)
/*  f0e20f4:	ad890000 */ 	sw	$t1,0x0($t4)
/*  f0e20f8:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0e20fc:	2408000a */ 	addiu	$t0,$zero,0xa
/*  f0e2100:	2407fff6 */ 	addiu	$a3,$zero,-10
/*  f0e2104:	01e80019 */ 	multu	$t7,$t0
/*  f0e2108:	240d0004 */ 	addiu	$t5,$zero,0x4
/*  f0e210c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e2110:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e2114:	00001012 */ 	mflo	$v0
/*  f0e2118:	2458ffd8 */ 	addiu	$t8,$v0,-40
/*  f0e211c:	a6180000 */ 	sh	$t8,0x0($s0)
/*  f0e2120:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f0e2124:	244b0028 */ 	addiu	$t3,$v0,0x28
/*  f0e2128:	a6070004 */ 	sh	$a3,0x4($s0)
/*  f0e212c:	03280019 */ 	multu	$t9,$t0
/*  f0e2130:	a60b000c */ 	sh	$t3,0xc($s0)
/*  f0e2134:	a6070010 */ 	sh	$a3,0x10($s0)
/*  f0e2138:	a6020018 */ 	sh	$v0,0x18($s0)
/*  f0e213c:	a607001c */ 	sh	$a3,0x1c($s0)
/*  f0e2140:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0e2144:	a2000013 */ 	sb	$zero,0x13($s0)
/*  f0e2148:	a20d001f */ 	sb	$t5,0x1f($s0)
/*  f0e214c:	00003012 */ 	mflo	$a2
/*  f0e2150:	24c5ffb0 */ 	addiu	$a1,$a2,-80
/*  f0e2154:	24cc000a */ 	addiu	$t4,$a2,0xa
/*  f0e2158:	a6050002 */ 	sh	$a1,0x2($s0)
/*  f0e215c:	a605000e */ 	sh	$a1,0xe($s0)
/*  f0e2160:	a60c001a */ 	sh	$t4,0x1a($s0)
/*  f0e2164:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f0e2168:	a6060026 */ 	sh	$a2,0x26($s0)
/*  f0e216c:	a6070028 */ 	sh	$a3,0x28($s0)
/*  f0e2170:	01c80019 */ 	multu	$t6,$t0
/*  f0e2174:	00007812 */ 	mflo	$t7
/*  f0e2178:	a60f0024 */ 	sh	$t7,0x24($s0)
/*  f0e217c:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f0e2180:	03080019 */ 	multu	$t8,$t0
/*  f0e2184:	00001012 */ 	mflo	$v0
/*  f0e2188:	00405825 */ 	or	$t3,$v0,$zero
/*  f0e218c:	256cffd8 */ 	addiu	$t4,$t3,-40
/*  f0e2190:	a60c0030 */ 	sh	$t4,0x30($s0)
/*  f0e2194:	8fad0068 */ 	lw	$t5,0x68($sp)
/*  f0e2198:	a602003c */ 	sh	$v0,0x3c($s0)
/*  f0e219c:	24020008 */ 	addiu	$v0,$zero,0x8
/*  f0e21a0:	01a80019 */ 	multu	$t5,$t0
/*  f0e21a4:	a6070034 */ 	sh	$a3,0x34($s0)
/*  f0e21a8:	a606003e */ 	sh	$a2,0x3e($s0)
/*  f0e21ac:	a6070040 */ 	sh	$a3,0x40($s0)
/*  f0e21b0:	a202002b */ 	sb	$v0,0x2b($s0)
/*  f0e21b4:	a2020037 */ 	sb	$v0,0x37($s0)
/*  f0e21b8:	a2020043 */ 	sb	$v0,0x43($s0)
/*  f0e21bc:	240bffff */ 	addiu	$t3,$zero,-1
/*  f0e21c0:	340cff4f */ 	dli	$t4,0xff4f
/*  f0e21c4:	00007012 */ 	mflo	$t6
/*  f0e21c8:	a60e0032 */ 	sh	$t6,0x32($s0)
/*  f0e21cc:	8faf0078 */ 	lw	$t7,0x78($sp)
/*  f0e21d0:	ae2b0004 */ 	sw	$t3,0x4($s1)
/*  f0e21d4:	ae2c0008 */ 	sw	$t4,0x8($s1)
/*  f0e21d8:	01e1c024 */ 	and	$t8,$t7,$at
/*  f0e21dc:	3719004f */ 	ori	$t9,$t8,0x4f
/*  f0e21e0:	ae390000 */ 	sw	$t9,0x0($s1)
/*  f0e21e4:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0e21e8:	3c0f0708 */ 	lui	$t7,0x708
/*  f0e21ec:	35ef000c */ 	ori	$t7,$t7,0xc
/*  f0e21f0:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0e21f4:	afae0060 */ 	sw	$t6,0x60($sp)
/*  f0e21f8:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0e21fc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e2200:	afad0034 */ 	sw	$t5,0x34($sp)
/*  f0e2204:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f0e2208:	3c0b0450 */ 	lui	$t3,0x450
/*  f0e220c:	356b0048 */ 	ori	$t3,$t3,0x48
/*  f0e2210:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0e2214:	8fb10060 */ 	lw	$s1,0x60($sp)
/*  f0e2218:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e221c:	26390008 */ 	addiu	$t9,$s1,0x8
/*  f0e2220:	afb90060 */ 	sw	$t9,0x60($sp)
/*  f0e2224:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e2228:	ae2b0000 */ 	sw	$t3,0x0($s1)
/*  f0e222c:	ae220004 */ 	sw	$v0,0x4($s1)
/*  f0e2230:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f0e2234:	3c0eb100 */ 	lui	$t6,0xb100
/*  f0e2238:	35ce0005 */ 	ori	$t6,$t6,0x5
/*  f0e223c:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f0e2240:	afad0060 */ 	sw	$t5,0x60($sp)
/*  f0e2244:	240f0043 */ 	addiu	$t7,$zero,0x43
/*  f0e2248:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f0e224c:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f0e2250:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0e2254:	3c0ae700 */ 	lui	$t2,0xe700
/*  f0e2258:	3c09b900 */ 	lui	$t1,0xb900
/*  f0e225c:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e2260:	afb90060 */ 	sw	$t9,0x60($sp)
/*  f0e2264:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0e2268:	af0a0000 */ 	sw	$t2,0x0($t8)
/*  f0e226c:	8fab0060 */ 	lw	$t3,0x60($sp)
/*  f0e2270:	3c0d0050 */ 	lui	$t5,0x50
/*  f0e2274:	3529031d */ 	ori	$t1,$t1,0x31d
/*  f0e2278:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f0e227c:	afac0060 */ 	sw	$t4,0x60($sp)
/*  f0e2280:	35ad41c8 */ 	ori	$t5,$t5,0x41c8
/*  f0e2284:	ad6d0004 */ 	sw	$t5,0x4($t3)
/*  f0e2288:	ad690000 */ 	sw	$t1,0x0($t3)
/*  f0e228c:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f0e2290:	3c18b100 */ 	lui	$t8,0xb100
/*  f0e2294:	37180002 */ 	ori	$t8,$t8,0x2
/*  f0e2298:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e229c:	afaf0060 */ 	sw	$t7,0x60($sp)
/*  f0e22a0:	24190010 */ 	addiu	$t9,$zero,0x10
/*  f0e22a4:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0e22a8:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e22ac:	8fab0060 */ 	lw	$t3,0x60($sp)
/*  f0e22b0:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f0e22b4:	3c0f0050 */ 	lui	$t7,0x50
/*  f0e22b8:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f0e22bc:	afac0060 */ 	sw	$t4,0x60($sp)
/*  f0e22c0:	ad600004 */ 	sw	$zero,0x4($t3)
/*  f0e22c4:	ad6a0000 */ 	sw	$t2,0x0($t3)
/*  f0e22c8:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0e22cc:	35ef4240 */ 	ori	$t7,$t7,0x4240
/*  f0e22d0:	3418ffff */ 	dli	$t8,0xffff
/*  f0e22d4:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0e22d8:	afae0060 */ 	sw	$t6,0x60($sp)
/*  f0e22dc:	adaf0004 */ 	sw	$t7,0x4($t5)
/*  f0e22e0:	ada90000 */ 	sw	$t1,0x0($t5)
/*  f0e22e4:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0e22e8:	24d00001 */ 	addiu	$s0,$a2,0x1
/*  f0e22ec:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0e22f0:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0e22f4:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e22f8:	8fa70074 */ 	lw	$a3,0x74($sp)
/*  f0e22fc:	8fa50064 */ 	lw	$a1,0x64($sp)
/*  f0e2300:	0fc389bb */ 	jal	renderLine
/*  f0e2304:	8fa40060 */ 	lw	$a0,0x60($sp)
/*  f0e2308:	340bffff */ 	dli	$t3,0xffff
/*  f0e230c:	340cffff */ 	dli	$t4,0xffff
/*  f0e2310:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f0e2314:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0e2318:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0e231c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e2320:	8fa50074 */ 	lw	$a1,0x74($sp)
/*  f0e2324:	8fa60070 */ 	lw	$a2,0x70($sp)
/*  f0e2328:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f0e232c:	0fc389bb */ 	jal	renderLine
/*  f0e2330:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0e2334:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0e2338:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f0e233c:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f0e2340:	03e00008 */ 	jr	$ra
/*  f0e2344:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

Gfx *func0f0e2348(Gfx *gdl)
{
	gSPSetGeometryMode(gdl++, G_CULL_BACK);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPPipelineMode(gdl++, G_PM_1PRIMITIVE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureLUT(gdl++, G_TT_NONE);
	gDPSetTextureDetail(gdl++, G_TD_CLAMP);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
	gDPSetCombineKey(gdl++, G_CK_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetRenderMode(gdl++, G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2);
	gDPSetColorDither(gdl++, G_CD_MAGICSQ);
	gSPSetGeometryMode(gdl++, G_ZBUFFER);

	return gdl;
}

Gfx *func0f0e2498(Gfx *gdl)
{
	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
	gSPClearGeometryMode(gdl++, G_CULL_BOTH)

	func0f0b39c0(&gdl, 0, 2, 0, 2, 1, 0);

	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

	return gdl;
}

GLOBAL_ASM(
glabel func0f0e258c
/*  f0e258c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0e2590:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e2594:	00808025 */ 	or	$s0,$a0,$zero
/*  f0e2598:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0e259c:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f0e25a0:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f0e25a4:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f0e25a8:	0fc59e73 */ 	jal	func0f1679cc
/*  f0e25ac:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0e25b0:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f0e25b4:	0fc59e59 */ 	jal	func0f167964
/*  f0e25b8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0e25bc:	8fae0034 */ 	lw	$t6,0x34($sp)
/*  f0e25c0:	2407000a */ 	addiu	$a3,$zero,0xa
/*  f0e25c4:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f0e25c8:	01c70019 */ 	multu	$t6,$a3
/*  f0e25cc:	2408fff6 */ 	addiu	$t0,$zero,-10
/*  f0e25d0:	00001812 */ 	mflo	$v1
/*  f0e25d4:	a4430000 */ 	sh	$v1,0x0($v0)
/*  f0e25d8:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f0e25dc:	a4480004 */ 	sh	$t0,0x4($v0)
/*  f0e25e0:	01e70019 */ 	multu	$t7,$a3
/*  f0e25e4:	00002012 */ 	mflo	$a0
/*  f0e25e8:	a4440002 */ 	sh	$a0,0x2($v0)
/*  f0e25ec:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f0e25f0:	a444000e */ 	sh	$a0,0xe($v0)
/*  f0e25f4:	a4480010 */ 	sh	$t0,0x10($v0)
/*  f0e25f8:	03070019 */ 	multu	$t8,$a3
/*  f0e25fc:	00002812 */ 	mflo	$a1
/*  f0e2600:	a445000c */ 	sh	$a1,0xc($v0)
/*  f0e2604:	a4450018 */ 	sh	$a1,0x18($v0)
/*  f0e2608:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f0e260c:	a448001c */ 	sh	$t0,0x1c($v0)
/*  f0e2610:	a4430024 */ 	sh	$v1,0x24($v0)
/*  f0e2614:	03270019 */ 	multu	$t9,$a3
/*  f0e2618:	a4480028 */ 	sh	$t0,0x28($v0)
/*  f0e261c:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f0e2620:	00003012 */ 	mflo	$a2
/*  f0e2624:	a446001a */ 	sh	$a2,0x1a($v0)
/*  f0e2628:	a4460026 */ 	sh	$a2,0x26($v0)
/*  f0e262c:	8fa9004c */ 	lw	$t1,0x4c($sp)
/*  f0e2630:	55200008 */ 	bnezl	$t1,.L0f0e2654
/*  f0e2634:	a0400007 */ 	sb	$zero,0x7($v0)
/*  f0e2638:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f0e263c:	a0400007 */ 	sb	$zero,0x7($v0)
/*  f0e2640:	a0430013 */ 	sb	$v1,0x13($v0)
/*  f0e2644:	a043001f */ 	sb	$v1,0x1f($v0)
/*  f0e2648:	10000005 */ 	b	.L0f0e2660
/*  f0e264c:	a040002b */ 	sb	$zero,0x2b($v0)
/*  f0e2650:	a0400007 */ 	sb	$zero,0x7($v0)
.L0f0e2654:
/*  f0e2654:	a0400013 */ 	sb	$zero,0x13($v0)
/*  f0e2658:	a043001f */ 	sb	$v1,0x1f($v0)
/*  f0e265c:	a043002b */ 	sb	$v1,0x2b($v0)
.L0f0e2660:
/*  f0e2660:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f0e2664:	8faa0044 */ 	lw	$t2,0x44($sp)
/*  f0e2668:	3c0c0704 */ 	lui	$t4,0x704
/*  f0e266c:	358c0008 */ 	ori	$t4,$t4,0x8
/*  f0e2670:	ac8a0000 */ 	sw	$t2,0x0($a0)
/*  f0e2674:	8fab0048 */ 	lw	$t3,0x48($sp)
/*  f0e2678:	02001825 */ 	or	$v1,$s0,$zero
/*  f0e267c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e2680:	ac8b0004 */ 	sw	$t3,0x4($a0)
/*  f0e2684:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f0e2688:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e268c:	afa30024 */ 	sw	$v1,0x24($sp)
/*  f0e2690:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f0e2694:	3c0d0430 */ 	lui	$t5,0x430
/*  f0e2698:	35ad0030 */ 	ori	$t5,$t5,0x30
/*  f0e269c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0e26a0:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0e26a4:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f0e26a8:	afa50020 */ 	sw	$a1,0x20($sp)
/*  f0e26ac:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f0e26b0:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e26b4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0e26b8:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f0e26bc:	02001825 */ 	or	$v1,$s0,$zero
/*  f0e26c0:	3c0eb100 */ 	lui	$t6,0xb100
/*  f0e26c4:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0e26c8:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f0e26cc:	240f3210 */ 	addiu	$t7,$zero,0x3210
/*  f0e26d0:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f0e26d4:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0e26d8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0e26dc:	26020008 */ 	addiu	$v0,$s0,0x8
/*  f0e26e0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0e26e4:	03e00008 */ 	jr	$ra
/*  f0e26e8:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

Gfx *renderLine(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, s32 arg5, s32 arg6)
{
	gdl = func0f0e2498(gdl);
	gdl = func0f0e258c(gdl, x1, y1, x2, y2, arg5, arg6, 0);

	return gdl;
}

GLOBAL_ASM(
glabel func0f0e2744
/*  f0e2744:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0e2748:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0e274c:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f0e2750:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f0e2754:	00c0b025 */ 	or	$s6,$a2,$zero
/*  f0e2758:	00e0f025 */ 	or	$s8,$a3,$zero
/*  f0e275c:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f0e2760:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f0e2764:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f0e2768:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f0e276c:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f0e2770:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f0e2774:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0e2778:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0e277c:	0fc54f96 */ 	jal	func0f153e58
/*  f0e2780:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f0e2784:	104000ae */ 	beqz	$v0,.L0f0e2a40
/*  f0e2788:	8fb500b0 */ 	lw	$s5,0xb0($sp)
/*  f0e278c:	8fa4009c */ 	lw	$a0,0x9c($sp)
/*  f0e2790:	8fb700a8 */ 	lw	$s7,0xa8($sp)
/*  f0e2794:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e2798:	03c41023 */ 	subu	$v0,$s8,$a0
/*  f0e279c:	02f61823 */ 	subu	$v1,$s7,$s6
/*  f0e27a0:	0043082a */ 	slt	$at,$v0,$v1
/*  f0e27a4:	10200053 */ 	beqz	$at,.L0f0e28f4
/*  f0e27a8:	2401000f */ 	addiu	$at,$zero,0xf
/*  f0e27ac:	0061001a */ 	div	$zero,$v1,$at
/*  f0e27b0:	00008012 */ 	mflo	$s0
/*  f0e27b4:	afb00094 */ 	sw	$s0,0x94($sp)
/*  f0e27b8:	afb60080 */ 	sw	$s6,0x80($sp)
/*  f0e27bc:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e27c0:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e27c4:	0fc54fa5 */ 	jal	func0f153e94
/*  f0e27c8:	afa30050 */ 	sw	$v1,0x50($sp)
/*  f0e27cc:	afa2008c */ 	sw	$v0,0x8c($sp)
/*  f0e27d0:	1a000038 */ 	blez	$s0,.L0f0e28b4
/*  f0e27d4:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0e27d8:	02c08825 */ 	or	$s1,$s6,$zero
/*  f0e27dc:	02f69823 */ 	subu	$s3,$s7,$s6
/*  f0e27e0:	8fb500b0 */ 	lw	$s5,0xb0($sp)
.L0f0e27e4:
/*  f0e27e4:	2a610003 */ 	slti	$at,$s3,0x3
/*  f0e27e8:	10200008 */ 	beqz	$at,.L0f0e280c
/*  f0e27ec:	02209025 */ 	or	$s2,$s1,$zero
/*  f0e27f0:	02e09025 */ 	or	$s2,$s7,$zero
/*  f0e27f4:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0e27f8:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0e27fc:	0fc54fa5 */ 	jal	func0f153e94
/*  f0e2800:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0e2804:	10000019 */ 	b	.L0f0e286c
/*  f0e2808:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e280c:
/*  f0e280c:	02367023 */ 	subu	$t6,$s1,$s6
/*  f0e2810:	000e7a00 */ 	sll	$t7,$t6,0x8
/*  f0e2814:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f0e2818:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0e281c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0e2820:	01f8001a */ 	div	$zero,$t7,$t8
/*  f0e2824:	00003012 */ 	mflo	$a2
/*  f0e2828:	8fa500ac */ 	lw	$a1,0xac($sp)
/*  f0e282c:	17000002 */ 	bnez	$t8,.L0f0e2838
/*  f0e2830:	00000000 */ 	nop
/*  f0e2834:	0007000d */ 	break	0x7
.L0f0e2838:
/*  f0e2838:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e283c:	17010004 */ 	bne	$t8,$at,.L0f0e2850
/*  f0e2840:	3c018000 */ 	lui	$at,0x8000
/*  f0e2844:	15e10002 */ 	bne	$t7,$at,.L0f0e2850
/*  f0e2848:	00000000 */ 	nop
/*  f0e284c:	0006000d */ 	break	0x6
.L0f0e2850:
/*  f0e2850:	0fc01a40 */ 	jal	colourBlend
/*  f0e2854:	00000000 */ 	nop
/*  f0e2858:	02c02025 */ 	or	$a0,$s6,$zero
/*  f0e285c:	02202825 */ 	or	$a1,$s1,$zero
/*  f0e2860:	0fc54fa5 */ 	jal	func0f153e94
/*  f0e2864:	00403025 */ 	or	$a2,$v0,$zero
/*  f0e2868:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e286c:
/*  f0e286c:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f0e2870:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0e2874:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*  f0e2878:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0e287c:	03c03825 */ 	or	$a3,$s8,$zero
/*  f0e2880:	afb20010 */ 	sw	$s2,0x10($sp)
/*  f0e2884:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e2888:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0e288c:	0fc38963 */ 	jal	func0f0e258c
/*  f0e2890:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0e2894:	8fa80094 */ 	lw	$t0,0x94($sp)
/*  f0e2898:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0e289c:	2631000f */ 	addiu	$s1,$s1,0xf
/*  f0e28a0:	2673fff1 */ 	addiu	$s3,$s3,-15
/*  f0e28a4:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0e28a8:	afb20080 */ 	sw	$s2,0x80($sp)
/*  f0e28ac:	1688ffcd */ 	bne	$s4,$t0,.L0f0e27e4
/*  f0e28b0:	afb0008c */ 	sw	$s0,0x8c($sp)
.L0f0e28b4:
/*  f0e28b4:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e28b8:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0e28bc:	0fc54fa5 */ 	jal	func0f153e94
/*  f0e28c0:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0e28c4:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f0e28c8:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0e28cc:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*  f0e28d0:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0e28d4:	03c03825 */ 	or	$a3,$s8,$zero
/*  f0e28d8:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0e28dc:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0e28e0:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0e28e4:	0fc38963 */ 	jal	func0f0e258c
/*  f0e28e8:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f0e28ec:	10000060 */ 	b	.L0f0e2a70
/*  f0e28f0:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0e28f4:
/*  f0e28f4:	2401000f */ 	addiu	$at,$zero,0xf
/*  f0e28f8:	0041001a */ 	div	$zero,$v0,$at
/*  f0e28fc:	00008012 */ 	mflo	$s0
/*  f0e2900:	afb00074 */ 	sw	$s0,0x74($sp)
/*  f0e2904:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f0e2908:	8fa600ac */ 	lw	$a2,0xac($sp)
/*  f0e290c:	0fc54fa5 */ 	jal	func0f153e94
/*  f0e2910:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f0e2914:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f0e2918:	1a000039 */ 	blez	$s0,.L0f0e2a00
/*  f0e291c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0e2920:	8fb1009c */ 	lw	$s1,0x9c($sp)
/*  f0e2924:	8fb500b0 */ 	lw	$s5,0xb0($sp)
/*  f0e2928:	03d19823 */ 	subu	$s3,$s8,$s1
.L0f0e292c:
/*  f0e292c:	2a610003 */ 	slti	$at,$s3,0x3
/*  f0e2930:	10200008 */ 	beqz	$at,.L0f0e2954
/*  f0e2934:	02209025 */ 	or	$s2,$s1,$zero
/*  f0e2938:	03c09025 */ 	or	$s2,$s8,$zero
/*  f0e293c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0e2940:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0e2944:	0fc54fa5 */ 	jal	func0f153e94
/*  f0e2948:	02a03025 */ 	or	$a2,$s5,$zero
/*  f0e294c:	1000001a */ 	b	.L0f0e29b8
/*  f0e2950:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e2954:
/*  f0e2954:	8faa009c */ 	lw	$t2,0x9c($sp)
/*  f0e2958:	8fad0054 */ 	lw	$t5,0x54($sp)
/*  f0e295c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0e2960:	022a5823 */ 	subu	$t3,$s1,$t2
/*  f0e2964:	000b6200 */ 	sll	$t4,$t3,0x8
/*  f0e2968:	018b6023 */ 	subu	$t4,$t4,$t3
/*  f0e296c:	018d001a */ 	div	$zero,$t4,$t5
/*  f0e2970:	00003012 */ 	mflo	$a2
/*  f0e2974:	8fa500ac */ 	lw	$a1,0xac($sp)
/*  f0e2978:	15a00002 */ 	bnez	$t5,.L0f0e2984
/*  f0e297c:	00000000 */ 	nop
/*  f0e2980:	0007000d */ 	break	0x7
.L0f0e2984:
/*  f0e2984:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e2988:	15a10004 */ 	bne	$t5,$at,.L0f0e299c
/*  f0e298c:	3c018000 */ 	lui	$at,0x8000
/*  f0e2990:	15810002 */ 	bne	$t4,$at,.L0f0e299c
/*  f0e2994:	00000000 */ 	nop
/*  f0e2998:	0006000d */ 	break	0x6
.L0f0e299c:
/*  f0e299c:	0fc01a40 */ 	jal	colourBlend
/*  f0e29a0:	00000000 */ 	nop
/*  f0e29a4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0e29a8:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e29ac:	0fc54fa5 */ 	jal	func0f153e94
/*  f0e29b0:	00403025 */ 	or	$a2,$v0,$zero
/*  f0e29b4:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e29b8:
/*  f0e29b8:	8fae006c */ 	lw	$t6,0x6c($sp)
/*  f0e29bc:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0e29c0:	8fa50060 */ 	lw	$a1,0x60($sp)
/*  f0e29c4:	02c03025 */ 	or	$a2,$s6,$zero
/*  f0e29c8:	02403825 */ 	or	$a3,$s2,$zero
/*  f0e29cc:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0e29d0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0e29d4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0e29d8:	0fc38963 */ 	jal	func0f0e258c
/*  f0e29dc:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e29e0:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f0e29e4:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0e29e8:	2631000f */ 	addiu	$s1,$s1,0xf
/*  f0e29ec:	2673fff1 */ 	addiu	$s3,$s3,-15
/*  f0e29f0:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0e29f4:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0e29f8:	168fffcc */ 	bne	$s4,$t7,.L0f0e292c
/*  f0e29fc:	afb0006c */ 	sw	$s0,0x6c($sp)
.L0f0e2a00:
/*  f0e2a00:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f0e2a04:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0e2a08:	0fc54fa5 */ 	jal	func0f153e94
/*  f0e2a0c:	02e02825 */ 	or	$a1,$s7,$zero
/*  f0e2a10:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f0e2a14:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0e2a18:	8fa50060 */ 	lw	$a1,0x60($sp)
/*  f0e2a1c:	02c03025 */ 	or	$a2,$s6,$zero
/*  f0e2a20:	03c03825 */ 	or	$a3,$s8,$zero
/*  f0e2a24:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0e2a28:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0e2a2c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0e2a30:	0fc38963 */ 	jal	func0f0e258c
/*  f0e2a34:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e2a38:	1000000d */ 	b	.L0f0e2a70
/*  f0e2a3c:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0e2a40:
/*  f0e2a40:	8fb700a8 */ 	lw	$s7,0xa8($sp)
/*  f0e2a44:	8fb900ac */ 	lw	$t9,0xac($sp)
/*  f0e2a48:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0e2a4c:	8fa5009c */ 	lw	$a1,0x9c($sp)
/*  f0e2a50:	02c03025 */ 	or	$a2,$s6,$zero
/*  f0e2a54:	03c03825 */ 	or	$a3,$s8,$zero
/*  f0e2a58:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f0e2a5c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0e2a60:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0e2a64:	0fc38963 */ 	jal	func0f0e258c
/*  f0e2a68:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0e2a6c:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0e2a70:
/*  f0e2a70:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0e2a74:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0e2a78:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0e2a7c:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f0e2a80:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f0e2a84:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f0e2a88:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f0e2a8c:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f0e2a90:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f0e2a94:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f0e2a98:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f0e2a9c:	03e00008 */ 	jr	$ra
/*  f0e2aa0:	27bd0098 */ 	addiu	$sp,$sp,0x98
);

GLOBAL_ASM(
glabel func0f0e2aa4
/*  f0e2aa4:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0e2aa8:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f0e2aac:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0e2ab0:	00808025 */ 	or	$s0,$a0,$zero
/*  f0e2ab4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e2ab8:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0e2abc:	00004025 */ 	or	$t0,$zero,$zero
/*  f0e2ac0:	11c0000e */ 	beqz	$t6,.L0f0e2afc
/*  f0e2ac4:	00004825 */ 	or	$t1,$zero,$zero
/*  f0e2ac8:	3c0140c0 */ 	lui	$at,0x40c0
/*  f0e2acc:	44812000 */ 	mtc1	$at,$f4
/*  f0e2ad0:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f0e2ad4:	c4261630 */ 	lwc1	$f6,%lo(var80061630)($at)
/*  f0e2ad8:	3c014416 */ 	lui	$at,0x4416
/*  f0e2adc:	44815000 */ 	mtc1	$at,$f10
/*  f0e2ae0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e2ae4:	00000000 */ 	nop
/*  f0e2ae8:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0e2aec:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e2af0:	44029000 */ 	mfc1	$v0,$f18
/*  f0e2af4:	10000010 */ 	b	.L0f0e2b38
/*  f0e2af8:	00000000 */ 	nop
.L0f0e2afc:
/*  f0e2afc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0e2b00:	44812000 */ 	mtc1	$at,$f4
/*  f0e2b04:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f0e2b08:	c4261630 */ 	lwc1	$f6,%lo(var80061630)($at)
/*  f0e2b0c:	3c0140c0 */ 	lui	$at,0x40c0
/*  f0e2b10:	44815000 */ 	mtc1	$at,$f10
/*  f0e2b14:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0e2b18:	3c014416 */ 	lui	$at,0x4416
/*  f0e2b1c:	44819000 */ 	mtc1	$at,$f18
/*  f0e2b20:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f0e2b24:	00000000 */ 	nop
/*  f0e2b28:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0e2b2c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e2b30:	44023000 */ 	mfc1	$v0,$f6
/*  f0e2b34:	00000000 */ 	nop
.L0f0e2b38:
/*  f0e2b38:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f0e2b3c:	8fad0054 */ 	lw	$t5,0x54($sp)
/*  f0e2b40:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f0e2b44:	0186c823 */ 	subu	$t9,$t4,$a2
/*  f0e2b48:	01a57023 */ 	subu	$t6,$t5,$a1
/*  f0e2b4c:	032e082a */ 	slt	$at,$t9,$t6
/*  f0e2b50:	10200072 */ 	beqz	$at,.L0f0e2d1c
/*  f0e2b54:	00c57821 */ 	addu	$t7,$a2,$a1
/*  f0e2b58:	00c57821 */ 	addu	$t7,$a2,$a1
/*  f0e2b5c:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f0e2b60:	24010258 */ 	addiu	$at,$zero,0x258
/*  f0e2b64:	0041001a */ 	div	$zero,$v0,$at
/*  f0e2b68:	8fab0064 */ 	lw	$t3,0x64($sp)
/*  f0e2b6c:	0000c010 */ 	mfhi	$t8
/*  f0e2b70:	00b86821 */ 	addu	$t5,$a1,$t8
/*  f0e2b74:	01ab1823 */ 	subu	$v1,$t5,$t3
/*  f0e2b78:	0065082a */ 	slt	$at,$v1,$a1
/*  f0e2b7c:	006b2021 */ 	addu	$a0,$v1,$t3
/*  f0e2b80:	03001025 */ 	or	$v0,$t8,$zero
/*  f0e2b84:	afa30044 */ 	sw	$v1,0x44($sp)
/*  f0e2b88:	10200003 */ 	beqz	$at,.L0f0e2b98
/*  f0e2b8c:	00803825 */ 	or	$a3,$a0,$zero
/*  f0e2b90:	00a34023 */ 	subu	$t0,$a1,$v1
/*  f0e2b94:	afa50044 */ 	sw	$a1,0x44($sp)
.L0f0e2b98:
/*  f0e2b98:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f0e2b9c:	240300ff */ 	addiu	$v1,$zero,0xff
/*  f0e2ba0:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f0e2ba4:	0324082a */ 	slt	$at,$t9,$a0
/*  f0e2ba8:	10200003 */ 	beqz	$at,.L0f0e2bb8
/*  f0e2bac:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f0e2bb0:	00994823 */ 	subu	$t1,$a0,$t9
/*  f0e2bb4:	03203825 */ 	or	$a3,$t9,$zero
.L0f0e2bb8:
/*  f0e2bb8:	0109082a */ 	slt	$at,$t0,$t1
/*  f0e2bbc:	10200002 */ 	beqz	$at,.L0f0e2bc8
/*  f0e2bc0:	00000000 */ 	nop
/*  f0e2bc4:	01204025 */ 	or	$t0,$t1,$zero
.L0f0e2bc8:
/*  f0e2bc8:	01030019 */ 	multu	$t0,$v1
/*  f0e2bcc:	00007012 */ 	mflo	$t6
/*  f0e2bd0:	00000000 */ 	nop
/*  f0e2bd4:	00000000 */ 	nop
/*  f0e2bd8:	01cb001a */ 	div	$zero,$t6,$t3
/*  f0e2bdc:	15600002 */ 	bnez	$t3,.L0f0e2be8
/*  f0e2be0:	00000000 */ 	nop
/*  f0e2be4:	0007000d */ 	break	0x7
.L0f0e2be8:
/*  f0e2be8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e2bec:	15610004 */ 	bne	$t3,$at,.L0f0e2c00
/*  f0e2bf0:	3c018000 */ 	lui	$at,0x8000
/*  f0e2bf4:	15c10002 */ 	bne	$t6,$at,.L0f0e2c00
/*  f0e2bf8:	00000000 */ 	nop
/*  f0e2bfc:	0006000d */ 	break	0x6
.L0f0e2c00:
/*  f0e2c00:	00004012 */ 	mflo	$t0
/*  f0e2c04:	29010100 */ 	slti	$at,$t0,0x100
/*  f0e2c08:	54200003 */ 	bnezl	$at,.L0f0e2c18
/*  f0e2c0c:	00e5082a */ 	slt	$at,$a3,$a1
/*  f0e2c10:	00604025 */ 	or	$t0,$v1,$zero
/*  f0e2c14:	00e5082a */ 	slt	$at,$a3,$a1
.L0f0e2c18:
/*  f0e2c18:	142000ae */ 	bnez	$at,.L0f0e2ed4
/*  f0e2c1c:	01f8082a */ 	slt	$at,$t7,$t8
/*  f0e2c20:	142000ac */ 	bnez	$at,.L0f0e2ed4
/*  f0e2c24:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0e2c28:	11a0000b */ 	beqz	$t5,.L0f0e2c58
/*  f0e2c2c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e2c30:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0e2c34:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f0e2c38:	0fc38926 */ 	jal	func0f0e2498
/*  f0e2c3c:	afa80030 */ 	sw	$t0,0x30($sp)
/*  f0e2c40:	240300ff */ 	addiu	$v1,$zero,0xff
/*  f0e2c44:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0e2c48:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f0e2c4c:	8fa80030 */ 	lw	$t0,0x30($sp)
/*  f0e2c50:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f0e2c54:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e2c58:
/*  f0e2c58:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f0e2c5c:	53200019 */ 	beqzl	$t9,.L0f0e2cc4
/*  f0e2c60:	8fad005c */ 	lw	$t5,0x5c($sp)
/*  f0e2c64:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f0e2c68:	00686823 */ 	subu	$t5,$v1,$t0
/*  f0e2c6c:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0e2c70:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0e2c74:	030d0019 */ 	multu	$t8,$t5
/*  f0e2c78:	240eff00 */ 	addiu	$t6,$zero,-256
/*  f0e2c7c:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e2c80:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e2c84:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0e2c88:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e2c8c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0e2c90:	0000c812 */ 	mflo	$t9
/*  f0e2c94:	00000000 */ 	nop
/*  f0e2c98:	00000000 */ 	nop
/*  f0e2c9c:	0321001b */ 	divu	$zero,$t9,$at
/*  f0e2ca0:	00007012 */ 	mflo	$t6
/*  f0e2ca4:	31cf00ff */ 	andi	$t7,$t6,0xff
/*  f0e2ca8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e2cac:	01e1c025 */ 	or	$t8,$t7,$at
/*  f0e2cb0:	0fc38963 */ 	jal	func0f0e258c
/*  f0e2cb4:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0e2cb8:	10000086 */ 	b	.L0f0e2ed4
/*  f0e2cbc:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e2cc0:	8fad005c */ 	lw	$t5,0x5c($sp)
.L0f0e2cc4:
/*  f0e2cc4:	00687023 */ 	subu	$t6,$v1,$t0
/*  f0e2cc8:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0e2ccc:	31b900ff */ 	andi	$t9,$t5,0xff
/*  f0e2cd0:	032e0019 */ 	multu	$t9,$t6
/*  f0e2cd4:	240eff00 */ 	addiu	$t6,$zero,-256
/*  f0e2cd8:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0e2cdc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e2ce0:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f0e2ce4:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e2ce8:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f0e2cec:	00007812 */ 	mflo	$t7
/*  f0e2cf0:	00000000 */ 	nop
/*  f0e2cf4:	00000000 */ 	nop
/*  f0e2cf8:	01e1001b */ 	divu	$zero,$t7,$at
/*  f0e2cfc:	0000c012 */ 	mflo	$t8
/*  f0e2d00:	330d00ff */ 	andi	$t5,$t8,0xff
/*  f0e2d04:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e2d08:	01a1c825 */ 	or	$t9,$t5,$at
/*  f0e2d0c:	0fc38963 */ 	jal	func0f0e258c
/*  f0e2d10:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0e2d14:	1000006f */ 	b	.L0f0e2ed4
/*  f0e2d18:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e2d1c:
/*  f0e2d1c:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f0e2d20:	24010258 */ 	addiu	$at,$zero,0x258
/*  f0e2d24:	0041001a */ 	div	$zero,$v0,$at
/*  f0e2d28:	0000c010 */ 	mfhi	$t8
/*  f0e2d2c:	00d86821 */ 	addu	$t5,$a2,$t8
/*  f0e2d30:	01ab1823 */ 	subu	$v1,$t5,$t3
/*  f0e2d34:	006b2021 */ 	addu	$a0,$v1,$t3
/*  f0e2d38:	0066082a */ 	slt	$at,$v1,$a2
/*  f0e2d3c:	03001025 */ 	or	$v0,$t8,$zero
/*  f0e2d40:	afa30040 */ 	sw	$v1,0x40($sp)
/*  f0e2d44:	10200003 */ 	beqz	$at,.L0f0e2d54
/*  f0e2d48:	00805025 */ 	or	$t2,$a0,$zero
/*  f0e2d4c:	00c34023 */ 	subu	$t0,$a2,$v1
/*  f0e2d50:	afa60040 */ 	sw	$a2,0x40($sp)
.L0f0e2d54:
/*  f0e2d54:	0184082a */ 	slt	$at,$t4,$a0
/*  f0e2d58:	10200003 */ 	beqz	$at,.L0f0e2d68
/*  f0e2d5c:	240300ff */ 	addiu	$v1,$zero,0xff
/*  f0e2d60:	008c4823 */ 	subu	$t1,$a0,$t4
/*  f0e2d64:	01805025 */ 	or	$t2,$t4,$zero
.L0f0e2d68:
/*  f0e2d68:	0109082a */ 	slt	$at,$t0,$t1
/*  f0e2d6c:	10200002 */ 	beqz	$at,.L0f0e2d78
/*  f0e2d70:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0e2d74:	01204025 */ 	or	$t0,$t1,$zero
.L0f0e2d78:
/*  f0e2d78:	01030019 */ 	multu	$t0,$v1
/*  f0e2d7c:	0000c812 */ 	mflo	$t9
/*  f0e2d80:	00000000 */ 	nop
/*  f0e2d84:	00000000 */ 	nop
/*  f0e2d88:	032b001a */ 	div	$zero,$t9,$t3
/*  f0e2d8c:	15600002 */ 	bnez	$t3,.L0f0e2d98
/*  f0e2d90:	00000000 */ 	nop
/*  f0e2d94:	0007000d */ 	break	0x7
.L0f0e2d98:
/*  f0e2d98:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e2d9c:	15610004 */ 	bne	$t3,$at,.L0f0e2db0
/*  f0e2da0:	3c018000 */ 	lui	$at,0x8000
/*  f0e2da4:	17210002 */ 	bne	$t9,$at,.L0f0e2db0
/*  f0e2da8:	00000000 */ 	nop
/*  f0e2dac:	0006000d */ 	break	0x6
.L0f0e2db0:
/*  f0e2db0:	00004012 */ 	mflo	$t0
/*  f0e2db4:	29010100 */ 	slti	$at,$t0,0x100
/*  f0e2db8:	54200003 */ 	bnezl	$at,.L0f0e2dc8
/*  f0e2dbc:	0146082a */ 	slt	$at,$t2,$a2
/*  f0e2dc0:	00604025 */ 	or	$t0,$v1,$zero
/*  f0e2dc4:	0146082a */ 	slt	$at,$t2,$a2
.L0f0e2dc8:
/*  f0e2dc8:	14200042 */ 	bnez	$at,.L0f0e2ed4
/*  f0e2dcc:	018e082a */ 	slt	$at,$t4,$t6
/*  f0e2dd0:	14200040 */ 	bnez	$at,.L0f0e2ed4
/*  f0e2dd4:	8faf0060 */ 	lw	$t7,0x60($sp)
/*  f0e2dd8:	11e0000a */ 	beqz	$t7,.L0f0e2e04
/*  f0e2ddc:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e2de0:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f0e2de4:	afa80030 */ 	sw	$t0,0x30($sp)
/*  f0e2de8:	0fc38926 */ 	jal	func0f0e2498
/*  f0e2dec:	afaa0038 */ 	sw	$t2,0x38($sp)
/*  f0e2df0:	240300ff */ 	addiu	$v1,$zero,0xff
/*  f0e2df4:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f0e2df8:	8fa80030 */ 	lw	$t0,0x30($sp)
/*  f0e2dfc:	8faa0038 */ 	lw	$t2,0x38($sp)
/*  f0e2e00:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e2e04:
/*  f0e2e04:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f0e2e08:	5300001b */ 	beqzl	$t8,.L0f0e2e78
/*  f0e2e0c:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*  f0e2e10:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*  f0e2e14:	00687823 */ 	subu	$t7,$v1,$t0
/*  f0e2e18:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0e2e1c:	332e00ff */ 	andi	$t6,$t9,0xff
/*  f0e2e20:	01cf0019 */ 	multu	$t6,$t7
/*  f0e2e24:	240dff00 */ 	addiu	$t5,$zero,-256
/*  f0e2e28:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e2e2c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e2e30:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0e2e34:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e2e38:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0e2e3c:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e2e40:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e2e44:	0000c012 */ 	mflo	$t8
/*  f0e2e48:	00000000 */ 	nop
/*  f0e2e4c:	00000000 */ 	nop
/*  f0e2e50:	0301001b */ 	divu	$zero,$t8,$at
/*  f0e2e54:	00006812 */ 	mflo	$t5
/*  f0e2e58:	31b900ff */ 	andi	$t9,$t5,0xff
/*  f0e2e5c:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e2e60:	03217025 */ 	or	$t6,$t9,$at
/*  f0e2e64:	0fc38963 */ 	jal	func0f0e258c
/*  f0e2e68:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0e2e6c:	10000019 */ 	b	.L0f0e2ed4
/*  f0e2e70:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e2e74:	8fb8005c */ 	lw	$t8,0x5c($sp)
.L0f0e2e78:
/*  f0e2e78:	0068c823 */ 	subu	$t9,$v1,$t0
/*  f0e2e7c:	240100ff */ 	addiu	$at,$zero,0xff
/*  f0e2e80:	330d00ff */ 	andi	$t5,$t8,0xff
/*  f0e2e84:	01b90019 */ 	multu	$t5,$t9
/*  f0e2e88:	2419ff00 */ 	addiu	$t9,$zero,-256
/*  f0e2e8c:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f0e2e90:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e2e94:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f0e2e98:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e2e9c:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e2ea0:	00007012 */ 	mflo	$t6
/*  f0e2ea4:	00000000 */ 	nop
/*  f0e2ea8:	00000000 */ 	nop
/*  f0e2eac:	01c1001b */ 	divu	$zero,$t6,$at
/*  f0e2eb0:	00007812 */ 	mflo	$t7
/*  f0e2eb4:	31f800ff */ 	andi	$t8,$t7,0xff
/*  f0e2eb8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e2ebc:	03016825 */ 	or	$t5,$t8,$at
/*  f0e2ec0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0e2ec4:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0e2ec8:	0fc38963 */ 	jal	func0f0e258c
/*  f0e2ecc:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e2ed0:	00408025 */ 	or	$s0,$v0,$zero
.L0f0e2ed4:
/*  f0e2ed4:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0e2ed8:	02001025 */ 	or	$v0,$s0,$zero
/*  f0e2edc:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0e2ee0:	03e00008 */ 	jr	$ra
/*  f0e2ee4:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f0e2ee8
/*  f0e2ee8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f0e2eec:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f0e2ef0:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0e2ef4:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f0e2ef8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e2efc:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f0e2f00:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f0e2f04:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f0e2f08:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e2f0c:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e2f10:	0fc389bb */ 	jal	renderLine
/*  f0e2f14:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0e2f18:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f0e2f1c:	8fa80044 */ 	lw	$t0,0x44($sp)
/*  f0e2f20:	2409000a */ 	addiu	$t1,$zero,0xa
/*  f0e2f24:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0e2f28:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e2f2c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f0e2f30:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f0e2f34:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f0e2f38:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e2f3c:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f0e2f40:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0e2f44:	0fc38aa9 */ 	jal	func0f0e2aa4
/*  f0e2f48:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f0e2f4c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0e2f50:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f0e2f54:	03e00008 */ 	jr	$ra
/*  f0e2f58:	00000000 */ 	nop
);

Gfx *renderFilledRect(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colourleft, u32 colourright)
{
	gdl = func0f0e2498(gdl);
	gdl = func0f0e2744(gdl, x1, y1, x2, y2, colourleft, colourright);
	gdl = func0f0e2aa4(gdl, x1, y1, x2, y2, colourleft, 0, 10, 0);

	return gdl;
}

GLOBAL_ASM(
glabel menuRenderCarouselArrow
/*  f0e2fe4:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f0e2fe8:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f0e2fec:	8fa40070 */ 	lw	$a0,0x70($sp)
/*  f0e2ff0:	00077080 */ 	sll	$t6,$a3,0x2
/*  f0e2ff4:	01c77021 */ 	addu	$t6,$t6,$a3
/*  f0e2ff8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e2ffc:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0e3000:	afa50064 */ 	sw	$a1,0x64($sp)
/*  f0e3004:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f0e3008:	00005825 */ 	or	$t3,$zero,$zero
/*  f0e300c:	00006025 */ 	or	$t4,$zero,$zero
/*  f0e3010:	00004825 */ 	or	$t1,$zero,$zero
/*  f0e3014:	00005025 */ 	or	$t2,$zero,$zero
/*  f0e3018:	1080000a */ 	beqz	$a0,.L0f0e3044
/*  f0e301c:	000e3840 */ 	sll	$a3,$t6,0x1
/*  f0e3020:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e3024:	10810012 */ 	beq	$a0,$at,.L0f0e3070
/*  f0e3028:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0e302c:	1081001b */ 	beq	$a0,$at,.L0f0e309c
/*  f0e3030:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0e3034:	50810024 */ 	beql	$a0,$at,.L0f0e30c8
/*  f0e3038:	00075823 */ 	negu	$t3,$a3
/*  f0e303c:	1000002c */ 	b	.L0f0e30f0
/*  f0e3040:	24040002 */ 	addiu	$a0,$zero,0x2
.L0f0e3044:
/*  f0e3044:	00071023 */ 	negu	$v0,$a3
/*  f0e3048:	00026400 */ 	sll	$t4,$v0,0x10
/*  f0e304c:	000c7c03 */ 	sra	$t7,$t4,0x10
/*  f0e3050:	01e06025 */ 	or	$t4,$t7,$zero
/*  f0e3054:	04410003 */ 	bgez	$v0,.L0f0e3064
/*  f0e3058:	00024843 */ 	sra	$t1,$v0,0x1
/*  f0e305c:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0e3060:	00014843 */ 	sra	$t1,$at,0x1
.L0f0e3064:
/*  f0e3064:	0009c400 */ 	sll	$t8,$t1,0x10
/*  f0e3068:	10000020 */ 	b	.L0f0e30ec
/*  f0e306c:	00184c03 */ 	sra	$t1,$t8,0x10
.L0f0e3070:
/*  f0e3070:	00075023 */ 	negu	$t2,$a3
/*  f0e3074:	00075c00 */ 	sll	$t3,$a3,0x10
/*  f0e3078:	000b6c03 */ 	sra	$t5,$t3,0x10
/*  f0e307c:	01a05825 */ 	or	$t3,$t5,$zero
/*  f0e3080:	05410003 */ 	bgez	$t2,.L0f0e3090
/*  f0e3084:	000a7043 */ 	sra	$t6,$t2,0x1
/*  f0e3088:	25410001 */ 	addiu	$at,$t2,0x1
/*  f0e308c:	00017043 */ 	sra	$t6,$at,0x1
.L0f0e3090:
/*  f0e3090:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f0e3094:	10000015 */ 	b	.L0f0e30ec
/*  f0e3098:	000f5403 */ 	sra	$t2,$t7,0x10
.L0f0e309c:
/*  f0e309c:	00076400 */ 	sll	$t4,$a3,0x10
/*  f0e30a0:	000ccc03 */ 	sra	$t9,$t4,0x10
/*  f0e30a4:	03206025 */ 	or	$t4,$t9,$zero
/*  f0e30a8:	04e10003 */ 	bgez	$a3,.L0f0e30b8
/*  f0e30ac:	00074843 */ 	sra	$t1,$a3,0x1
/*  f0e30b0:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f0e30b4:	00014843 */ 	sra	$t1,$at,0x1
.L0f0e30b8:
/*  f0e30b8:	00096c00 */ 	sll	$t5,$t1,0x10
/*  f0e30bc:	1000000b */ 	b	.L0f0e30ec
/*  f0e30c0:	000d4c03 */ 	sra	$t1,$t5,0x10
/*  f0e30c4:	00075823 */ 	negu	$t3,$a3
.L0f0e30c8:
/*  f0e30c8:	000b7c00 */ 	sll	$t7,$t3,0x10
/*  f0e30cc:	000fc403 */ 	sra	$t8,$t7,0x10
/*  f0e30d0:	03005825 */ 	or	$t3,$t8,$zero
/*  f0e30d4:	04e10003 */ 	bgez	$a3,.L0f0e30e4
/*  f0e30d8:	00075043 */ 	sra	$t2,$a3,0x1
/*  f0e30dc:	24e10001 */ 	addiu	$at,$a3,0x1
/*  f0e30e0:	00015043 */ 	sra	$t2,$at,0x1
.L0f0e30e4:
/*  f0e30e4:	000acc00 */ 	sll	$t9,$t2,0x10
/*  f0e30e8:	00195403 */ 	sra	$t2,$t9,0x10
.L0f0e30ec:
/*  f0e30ec:	24040002 */ 	addiu	$a0,$zero,0x2
.L0f0e30f0:
/*  f0e30f0:	a7a90056 */ 	sh	$t1,0x56($sp)
/*  f0e30f4:	a7aa0054 */ 	sh	$t2,0x54($sp)
/*  f0e30f8:	a7ab0052 */ 	sh	$t3,0x52($sp)
/*  f0e30fc:	0fc59e73 */ 	jal	func0f1679cc
/*  f0e3100:	a7ac0050 */ 	sh	$t4,0x50($sp)
/*  f0e3104:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f0e3108:	0fc59e59 */ 	jal	func0f167964
/*  f0e310c:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0e3110:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f0e3114:	87a90056 */ 	lh	$t1,0x56($sp)
/*  f0e3118:	87aa0054 */ 	lh	$t2,0x54($sp)
/*  f0e311c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e3120:	87ab0052 */ 	lh	$t3,0x52($sp)
/*  f0e3124:	87ac0050 */ 	lh	$t4,0x50($sp)
/*  f0e3128:	afaf0060 */ 	sw	$t7,0x60($sp)
/*  f0e312c:	3c18e700 */ 	lui	$t8,0xe700
/*  f0e3130:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e3134:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0e3138:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0e313c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0e3140:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f0e3144:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0e3148:	afad0060 */ 	sw	$t5,0x60($sp)
/*  f0e314c:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0e3150:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0e3154:	8faf0060 */ 	lw	$t7,0x60($sp)
/*  f0e3158:	3c19b900 */ 	lui	$t9,0xb900
/*  f0e315c:	37390002 */ 	ori	$t9,$t9,0x2
/*  f0e3160:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e3164:	afb80060 */ 	sw	$t8,0x60($sp)
/*  f0e3168:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f0e316c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e3170:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0e3174:	3c0ffc12 */ 	lui	$t7,0xfc12
/*  f0e3178:	35ef7e24 */ 	ori	$t7,$t7,0x7e24
/*  f0e317c:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0e3180:	afae0060 */ 	sw	$t6,0x60($sp)
/*  f0e3184:	2418f9fc */ 	addiu	$t8,$zero,-1540
/*  f0e3188:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f0e318c:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0e3190:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0e3194:	240f3000 */ 	addiu	$t7,$zero,0x3000
/*  f0e3198:	3c0eb600 */ 	lui	$t6,0xb600
/*  f0e319c:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0e31a0:	afad0060 */ 	sw	$t5,0x60($sp)
/*  f0e31a4:	af2f0004 */ 	sw	$t7,0x4($t9)
/*  f0e31a8:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0e31ac:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0e31b0:	24180002 */ 	addiu	$t8,$zero,0x2
/*  f0e31b4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e31b8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e31bc:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0e31c0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e31c4:	27a40060 */ 	addiu	$a0,$sp,0x60
/*  f0e31c8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e31cc:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0e31d0:	00003825 */ 	or	$a3,$zero,$zero
/*  f0e31d4:	a7a90056 */ 	sh	$t1,0x56($sp)
/*  f0e31d8:	a7aa0054 */ 	sh	$t2,0x54($sp)
/*  f0e31dc:	a7ab0052 */ 	sh	$t3,0x52($sp)
/*  f0e31e0:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0e31e4:	a7ac0050 */ 	sh	$t4,0x50($sp)
/*  f0e31e8:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0e31ec:	87a90056 */ 	lh	$t1,0x56($sp)
/*  f0e31f0:	87aa0054 */ 	lh	$t2,0x54($sp)
/*  f0e31f4:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0e31f8:	87ab0052 */ 	lh	$t3,0x52($sp)
/*  f0e31fc:	87ac0050 */ 	lh	$t4,0x50($sp)
/*  f0e3200:	afae0060 */ 	sw	$t6,0x60($sp)
/*  f0e3204:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0e3208:	3c180050 */ 	lui	$t8,0x50
/*  f0e320c:	37184240 */ 	ori	$t8,$t8,0x4240
/*  f0e3210:	35ef031d */ 	ori	$t7,$t7,0x31d
/*  f0e3214:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0e3218:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f0e321c:	8fb90064 */ 	lw	$t9,0x64($sp)
/*  f0e3220:	2408000a */ 	addiu	$t0,$zero,0xa
/*  f0e3224:	2407fff6 */ 	addiu	$a3,$zero,-10
/*  f0e3228:	03280019 */ 	multu	$t9,$t0
/*  f0e322c:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f0e3230:	00001812 */ 	mflo	$v1
/*  f0e3234:	a6030000 */ 	sh	$v1,0x0($s0)
/*  f0e3238:	8fad0068 */ 	lw	$t5,0x68($sp)
/*  f0e323c:	006b2821 */ 	addu	$a1,$v1,$t3
/*  f0e3240:	00a97021 */ 	addu	$t6,$a1,$t1
/*  f0e3244:	01a80019 */ 	multu	$t5,$t0
/*  f0e3248:	00a9c023 */ 	subu	$t8,$a1,$t1
/*  f0e324c:	a6070004 */ 	sh	$a3,0x4($s0)
/*  f0e3250:	a60e000c */ 	sh	$t6,0xc($s0)
/*  f0e3254:	a6070010 */ 	sh	$a3,0x10($s0)
/*  f0e3258:	a6180018 */ 	sh	$t8,0x18($s0)
/*  f0e325c:	00002012 */ 	mflo	$a0
/*  f0e3260:	008c3021 */ 	addu	$a2,$a0,$t4
/*  f0e3264:	00ca7821 */ 	addu	$t7,$a2,$t2
/*  f0e3268:	a6040002 */ 	sh	$a0,0x2($s0)
/*  f0e326c:	a60f000e */ 	sh	$t7,0xe($s0)
/*  f0e3270:	8fa40058 */ 	lw	$a0,0x58($sp)
/*  f0e3274:	00cac823 */ 	subu	$t9,$a2,$t2
/*  f0e3278:	a619001a */ 	sh	$t9,0x1a($s0)
/*  f0e327c:	a607001c */ 	sh	$a3,0x1c($s0)
/*  f0e3280:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0e3284:	a2020013 */ 	sb	$v0,0x13($s0)
/*  f0e3288:	a202001f */ 	sb	$v0,0x1f($s0)
/*  f0e328c:	8fad0074 */ 	lw	$t5,0x74($sp)
/*  f0e3290:	3c190704 */ 	lui	$t9,0x704
/*  f0e3294:	37390008 */ 	ori	$t9,$t9,0x8
/*  f0e3298:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f0e329c:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f0e32a0:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f0e32a4:	8faf0060 */ 	lw	$t7,0x60($sp)
/*  f0e32a8:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e32ac:	afb80060 */ 	sw	$t8,0x60($sp)
/*  f0e32b0:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e32b4:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e32b8:	afaf0034 */ 	sw	$t7,0x34($sp)
/*  f0e32bc:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f0e32c0:	3c0f0420 */ 	lui	$t7,0x420
/*  f0e32c4:	35ef0024 */ 	ori	$t7,$t7,0x24
/*  f0e32c8:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0e32cc:	8fad0060 */ 	lw	$t5,0x60($sp)
/*  f0e32d0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e32d4:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0e32d8:	afae0060 */ 	sw	$t6,0x60($sp)
/*  f0e32dc:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0e32e0:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e32e4:	afad0030 */ 	sw	$t5,0x30($sp)
/*  f0e32e8:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f0e32ec:	3c0db100 */ 	lui	$t5,0xb100
/*  f0e32f0:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f0e32f4:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0e32f8:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0e32fc:	240e0010 */ 	addiu	$t6,$zero,0x10
/*  f0e3300:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e3304:	afb90060 */ 	sw	$t9,0x60($sp)
/*  f0e3308:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f0e330c:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0e3310:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0e3314:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0e3318:	8fa20060 */ 	lw	$v0,0x60($sp)
/*  f0e331c:	03e00008 */ 	jr	$ra
/*  f0e3320:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

GLOBAL_ASM(
glabel func0f0e3324
/*  f0e3324:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0e3328:	afa40068 */ 	sw	$a0,0x68($sp)
/*  f0e332c:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f0e3330:	00077080 */ 	sll	$t6,$a3,0x2
/*  f0e3334:	01c77021 */ 	addu	$t6,$t6,$a3
/*  f0e3338:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e333c:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0e3340:	afa5006c */ 	sw	$a1,0x6c($sp)
/*  f0e3344:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f0e3348:	00004825 */ 	or	$t1,$zero,$zero
/*  f0e334c:	00005025 */ 	or	$t2,$zero,$zero
/*  f0e3350:	00005825 */ 	or	$t3,$zero,$zero
/*  f0e3354:	00006025 */ 	or	$t4,$zero,$zero
/*  f0e3358:	1080000a */ 	beqz	$a0,.L0f0e3384
/*  f0e335c:	000e3840 */ 	sll	$a3,$t6,0x1
/*  f0e3360:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0e3364:	1081001f */ 	beq	$a0,$at,.L0f0e33e4
/*  f0e3368:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0e336c:	10810034 */ 	beq	$a0,$at,.L0f0e3440
/*  f0e3370:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0e3374:	50810049 */ 	beql	$a0,$at,.L0f0e349c
/*  f0e3378:	44873000 */ 	mtc1	$a3,$f6
/*  f0e337c:	1000005d */ 	b	.L0f0e34f4
/*  f0e3380:	24040002 */ 	addiu	$a0,$zero,0x2
.L0f0e3384:
/*  f0e3384:	44872000 */ 	mtc1	$a3,$f4
/*  f0e3388:	c7a80084 */ 	lwc1	$f8,0x84($sp)
/*  f0e338c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0e3390:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e3394:	44819000 */ 	mtc1	$at,$f18
/*  f0e3398:	00075023 */ 	negu	$t2,$a3
/*  f0e339c:	000a7c00 */ 	sll	$t7,$t2,0x10
/*  f0e33a0:	000fc403 */ 	sra	$t8,$t7,0x10
/*  f0e33a4:	03005025 */ 	or	$t2,$t8,$zero
/*  f0e33a8:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0e33ac:	00000000 */ 	nop
/*  f0e33b0:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f0e33b4:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e33b8:	440d3000 */ 	mfc1	$t5,$f6
/*  f0e33bc:	00000000 */ 	nop
/*  f0e33c0:	01a75821 */ 	addu	$t3,$t5,$a3
/*  f0e33c4:	000b5823 */ 	negu	$t3,$t3
/*  f0e33c8:	05610003 */ 	bgez	$t3,.L0f0e33d8
/*  f0e33cc:	000b7043 */ 	sra	$t6,$t3,0x1
/*  f0e33d0:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0e33d4:	00017043 */ 	sra	$t6,$at,0x1
.L0f0e33d8:
/*  f0e33d8:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f0e33dc:	10000044 */ 	b	.L0f0e34f0
/*  f0e33e0:	000f5c03 */ 	sra	$t3,$t7,0x10
.L0f0e33e4:
/*  f0e33e4:	44874000 */ 	mtc1	$a3,$f8
/*  f0e33e8:	c7b20084 */ 	lwc1	$f18,0x84($sp)
/*  f0e33ec:	3c013f00 */ 	lui	$at,0x3f00
/*  f0e33f0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0e33f4:	44813000 */ 	mtc1	$at,$f6
/*  f0e33f8:	00074c00 */ 	sll	$t1,$a3,0x10
/*  f0e33fc:	0009cc03 */ 	sra	$t9,$t1,0x10
/*  f0e3400:	03204825 */ 	or	$t1,$t9,$zero
/*  f0e3404:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f0e3408:	00000000 */ 	nop
/*  f0e340c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e3410:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e3414:	440e5000 */ 	mfc1	$t6,$f10
/*  f0e3418:	00000000 */ 	nop
/*  f0e341c:	01c76021 */ 	addu	$t4,$t6,$a3
/*  f0e3420:	000c6023 */ 	negu	$t4,$t4
/*  f0e3424:	05810003 */ 	bgez	$t4,.L0f0e3434
/*  f0e3428:	000c7843 */ 	sra	$t7,$t4,0x1
/*  f0e342c:	25810001 */ 	addiu	$at,$t4,0x1
/*  f0e3430:	00017843 */ 	sra	$t7,$at,0x1
.L0f0e3434:
/*  f0e3434:	000fc400 */ 	sll	$t8,$t7,0x10
/*  f0e3438:	1000002d */ 	b	.L0f0e34f0
/*  f0e343c:	00186403 */ 	sra	$t4,$t8,0x10
.L0f0e3440:
/*  f0e3440:	44879000 */ 	mtc1	$a3,$f18
/*  f0e3444:	c7a60084 */ 	lwc1	$f6,0x84($sp)
/*  f0e3448:	3c013f00 */ 	lui	$at,0x3f00
/*  f0e344c:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0e3450:	44815000 */ 	mtc1	$at,$f10
/*  f0e3454:	00075400 */ 	sll	$t2,$a3,0x10
/*  f0e3458:	000a6c03 */ 	sra	$t5,$t2,0x10
/*  f0e345c:	01a05025 */ 	or	$t2,$t5,$zero
/*  f0e3460:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e3464:	00000000 */ 	nop
/*  f0e3468:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f0e346c:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e3470:	440f2000 */ 	mfc1	$t7,$f4
/*  f0e3474:	00000000 */ 	nop
/*  f0e3478:	01e75821 */ 	addu	$t3,$t7,$a3
/*  f0e347c:	05610003 */ 	bgez	$t3,.L0f0e348c
/*  f0e3480:	000bc043 */ 	sra	$t8,$t3,0x1
/*  f0e3484:	25610001 */ 	addiu	$at,$t3,0x1
/*  f0e3488:	0001c043 */ 	sra	$t8,$at,0x1
.L0f0e348c:
/*  f0e348c:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f0e3490:	10000017 */ 	b	.L0f0e34f0
/*  f0e3494:	00195c03 */ 	sra	$t3,$t9,0x10
/*  f0e3498:	44873000 */ 	mtc1	$a3,$f6
.L0f0e349c:
/*  f0e349c:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*  f0e34a0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0e34a4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0e34a8:	44812000 */ 	mtc1	$at,$f4
/*  f0e34ac:	00074823 */ 	negu	$t1,$a3
/*  f0e34b0:	00097400 */ 	sll	$t6,$t1,0x10
/*  f0e34b4:	000e7c03 */ 	sra	$t7,$t6,0x10
/*  f0e34b8:	01e04825 */ 	or	$t1,$t7,$zero
/*  f0e34bc:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f0e34c0:	00000000 */ 	nop
/*  f0e34c4:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0e34c8:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0e34cc:	44194000 */ 	mfc1	$t9,$f8
/*  f0e34d0:	00000000 */ 	nop
/*  f0e34d4:	03276021 */ 	addu	$t4,$t9,$a3
/*  f0e34d8:	05810003 */ 	bgez	$t4,.L0f0e34e8
/*  f0e34dc:	000c6843 */ 	sra	$t5,$t4,0x1
/*  f0e34e0:	25810001 */ 	addiu	$at,$t4,0x1
/*  f0e34e4:	00016843 */ 	sra	$t5,$at,0x1
.L0f0e34e8:
/*  f0e34e8:	000d7400 */ 	sll	$t6,$t5,0x10
/*  f0e34ec:	000e6403 */ 	sra	$t4,$t6,0x10
.L0f0e34f0:
/*  f0e34f0:	24040002 */ 	addiu	$a0,$zero,0x2
.L0f0e34f4:
/*  f0e34f4:	a7a90056 */ 	sh	$t1,0x56($sp)
/*  f0e34f8:	a7aa0054 */ 	sh	$t2,0x54($sp)
/*  f0e34fc:	a7ab005a */ 	sh	$t3,0x5a($sp)
/*  f0e3500:	0fc59e73 */ 	jal	func0f1679cc
/*  f0e3504:	a7ac0058 */ 	sh	$t4,0x58($sp)
/*  f0e3508:	afa20060 */ 	sw	$v0,0x60($sp)
/*  f0e350c:	0fc59e59 */ 	jal	func0f167964
/*  f0e3510:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f0e3514:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f0e3518:	87a90056 */ 	lh	$t1,0x56($sp)
/*  f0e351c:	87aa0054 */ 	lh	$t2,0x54($sp)
/*  f0e3520:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e3524:	87ab005a */ 	lh	$t3,0x5a($sp)
/*  f0e3528:	87ac0058 */ 	lh	$t4,0x58($sp)
/*  f0e352c:	afb90068 */ 	sw	$t9,0x68($sp)
/*  f0e3530:	3c0de700 */ 	lui	$t5,0xe700
/*  f0e3534:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0e3538:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0e353c:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f0e3540:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0e3544:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f0e3548:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e354c:	afaf0068 */ 	sw	$t7,0x68($sp)
/*  f0e3550:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0e3554:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e3558:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f0e355c:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0e3560:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f0e3564:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0e3568:	afad0068 */ 	sw	$t5,0x68($sp)
/*  f0e356c:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0e3570:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0e3574:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f0e3578:	3c19fc12 */ 	lui	$t9,0xfc12
/*  f0e357c:	37397e24 */ 	ori	$t9,$t9,0x7e24
/*  f0e3580:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e3584:	afb80068 */ 	sw	$t8,0x68($sp)
/*  f0e3588:	240df9fc */ 	addiu	$t5,$zero,-1540
/*  f0e358c:	aded0004 */ 	sw	$t5,0x4($t7)
/*  f0e3590:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e3594:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f0e3598:	24193000 */ 	addiu	$t9,$zero,0x3000
/*  f0e359c:	3c18b600 */ 	lui	$t8,0xb600
/*  f0e35a0:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e35a4:	afaf0068 */ 	sw	$t7,0x68($sp)
/*  f0e35a8:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0e35ac:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e35b0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0e35b4:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f0e35b8:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e35bc:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e35c0:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e35c4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e35c8:	27a40068 */ 	addiu	$a0,$sp,0x68
/*  f0e35cc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e35d0:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0e35d4:	00003825 */ 	or	$a3,$zero,$zero
/*  f0e35d8:	a7a90056 */ 	sh	$t1,0x56($sp)
/*  f0e35dc:	a7aa0054 */ 	sh	$t2,0x54($sp)
/*  f0e35e0:	a7ab005a */ 	sh	$t3,0x5a($sp)
/*  f0e35e4:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0e35e8:	a7ac0058 */ 	sh	$t4,0x58($sp)
/*  f0e35ec:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f0e35f0:	87a90056 */ 	lh	$t1,0x56($sp)
/*  f0e35f4:	87aa0054 */ 	lh	$t2,0x54($sp)
/*  f0e35f8:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e35fc:	87ab005a */ 	lh	$t3,0x5a($sp)
/*  f0e3600:	87ac0058 */ 	lh	$t4,0x58($sp)
/*  f0e3604:	afb80068 */ 	sw	$t8,0x68($sp)
/*  f0e3608:	3c19b900 */ 	lui	$t9,0xb900
/*  f0e360c:	3c0d0050 */ 	lui	$t5,0x50
/*  f0e3610:	35ad41c8 */ 	ori	$t5,$t5,0x41c8
/*  f0e3614:	3739031d */ 	ori	$t9,$t9,0x31d
/*  f0e3618:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e361c:	aded0004 */ 	sw	$t5,0x4($t7)
/*  f0e3620:	8fae006c */ 	lw	$t6,0x6c($sp)
/*  f0e3624:	2408000a */ 	addiu	$t0,$zero,0xa
/*  f0e3628:	44895000 */ 	mtc1	$t1,$f10
/*  f0e362c:	01c80019 */ 	multu	$t6,$t0
/*  f0e3630:	3c014040 */ 	lui	$at,0x4040
/*  f0e3634:	46805020 */ 	cvt.s.w	$f0,$f10
/*  f0e3638:	44817000 */ 	mtc1	$at,$f14
/*  f0e363c:	2407fff6 */ 	addiu	$a3,$zero,-10
/*  f0e3640:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f0e3644:	44818000 */ 	mtc1	$at,$f16
/*  f0e3648:	3c013f80 */ 	lui	$at,0x3f80
/*  f0e364c:	44819000 */ 	mtc1	$at,$f18
/*  f0e3650:	46100202 */ 	mul.s	$f8,$f0,$f16
/*  f0e3654:	00002012 */ 	mflo	$a0
/*  f0e3658:	a6040000 */ 	sh	$a0,0x0($s0)
/*  f0e365c:	8faf0070 */ 	lw	$t7,0x70($sp)
/*  f0e3660:	00891821 */ 	addu	$v1,$a0,$t1
/*  f0e3664:	006bc021 */ 	addu	$t8,$v1,$t3
/*  f0e3668:	01e80019 */ 	multu	$t7,$t0
/*  f0e366c:	006b6823 */ 	subu	$t5,$v1,$t3
/*  f0e3670:	a6070004 */ 	sh	$a3,0x4($s0)
/*  f0e3674:	a618000c */ 	sh	$t8,0xc($s0)
/*  f0e3678:	a6070010 */ 	sh	$a3,0x10($s0)
/*  f0e367c:	a60d0018 */ 	sh	$t5,0x18($s0)
/*  f0e3680:	a607001c */ 	sh	$a3,0x1c($s0)
/*  f0e3684:	460e0183 */ 	div.s	$f6,$f0,$f14
/*  f0e3688:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f0e368c:	00002812 */ 	mflo	$a1
/*  f0e3690:	00aa3021 */ 	addu	$a2,$a1,$t2
/*  f0e3694:	00ccc821 */ 	addu	$t9,$a2,$t4
/*  f0e3698:	00cc7023 */ 	subu	$t6,$a2,$t4
/*  f0e369c:	a6050002 */ 	sh	$a1,0x2($s0)
/*  f0e36a0:	a619000e */ 	sh	$t9,0xe($s0)
/*  f0e36a4:	a60e001a */ 	sh	$t6,0x1a($s0)
/*  f0e36a8:	c7a40084 */ 	lwc1	$f4,0x84($sp)
/*  f0e36ac:	a6070028 */ 	sh	$a3,0x28($s0)
/*  f0e36b0:	a2000007 */ 	sb	$zero,0x7($s0)
/*  f0e36b4:	a2020013 */ 	sb	$v0,0x13($s0)
/*  f0e36b8:	46049081 */ 	sub.s	$f2,$f18,$f4
/*  f0e36bc:	46024282 */ 	mul.s	$f10,$f8,$f2
/*  f0e36c0:	460e5483 */ 	div.s	$f18,$f10,$f14
/*  f0e36c4:	448a5000 */ 	mtc1	$t2,$f10
/*  f0e36c8:	00000000 */ 	nop
/*  f0e36cc:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f0e36d0:	46123100 */ 	add.s	$f4,$f6,$f18
/*  f0e36d4:	46106482 */ 	mul.s	$f18,$f12,$f16
/*  f0e36d8:	4600220d */ 	trunc.w.s	$f8,$f4
/*  f0e36dc:	46029102 */ 	mul.s	$f4,$f18,$f2
/*  f0e36e0:	44194000 */ 	mfc1	$t9,$f8
/*  f0e36e4:	460e6183 */ 	div.s	$f6,$f12,$f14
/*  f0e36e8:	0099c021 */ 	addu	$t8,$a0,$t9
/*  f0e36ec:	a6180024 */ 	sh	$t8,0x24($s0)
/*  f0e36f0:	460e2203 */ 	div.s	$f8,$f4,$f14
/*  f0e36f4:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f0e36f8:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f0e36fc:	440f9000 */ 	mfc1	$t7,$f18
/*  f0e3700:	00000000 */ 	nop
/*  f0e3704:	00afc821 */ 	addu	$t9,$a1,$t7
/*  f0e3708:	a6190026 */ 	sh	$t9,0x26($s0)
/*  f0e370c:	8fa40060 */ 	lw	$a0,0x60($sp)
/*  f0e3710:	a202001f */ 	sb	$v0,0x1f($s0)
/*  f0e3714:	a202002b */ 	sb	$v0,0x2b($s0)
/*  f0e3718:	8fad007c */ 	lw	$t5,0x7c($sp)
/*  f0e371c:	3c190704 */ 	lui	$t9,0x704
/*  f0e3720:	37390008 */ 	ori	$t9,$t9,0x8
/*  f0e3724:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f0e3728:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f0e372c:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f0e3730:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f0e3734:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e3738:	afb80068 */ 	sw	$t8,0x68($sp)
/*  f0e373c:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e3740:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e3744:	afaf0038 */ 	sw	$t7,0x38($sp)
/*  f0e3748:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f0e374c:	3c0f0430 */ 	lui	$t7,0x430
/*  f0e3750:	35ef0030 */ 	ori	$t7,$t7,0x30
/*  f0e3754:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0e3758:	8fad0068 */ 	lw	$t5,0x68($sp)
/*  f0e375c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e3760:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0e3764:	afae0068 */ 	sw	$t6,0x68($sp)
/*  f0e3768:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0e376c:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e3770:	afad0034 */ 	sw	$t5,0x34($sp)
/*  f0e3774:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f0e3778:	3c0db100 */ 	lui	$t5,0xb100
/*  f0e377c:	35ad0003 */ 	ori	$t5,$t5,0x3
/*  f0e3780:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0e3784:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f0e3788:	240e2310 */ 	addiu	$t6,$zero,0x2310
/*  f0e378c:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e3790:	afb90068 */ 	sw	$t9,0x68($sp)
/*  f0e3794:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f0e3798:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0e379c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0e37a0:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0e37a4:	8fa20068 */ 	lw	$v0,0x68($sp)
/*  f0e37a8:	03e00008 */ 	jr	$ra
/*  f0e37ac:	27bd0068 */ 	addiu	$sp,$sp,0x68
);

GLOBAL_ASM(
glabel renderCheckbox
/*  f0e37b0:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f0e37b4:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f0e37b8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0e37bc:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0e37c0:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0e37c4:	00c08825 */ 	or	$s1,$a2,$zero
/*  f0e37c8:	11c00021 */ 	beqz	$t6,.L0f0e3850
/*  f0e37cc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0e37d0:	8fa50060 */ 	lw	$a1,0x60($sp)
/*  f0e37d4:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0e37d8:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f0e37dc:	3c068008 */ 	lui	$a2,%hi(g_ScreenWidthMultiplier)
/*  f0e37e0:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e37e4:	24c6fac0 */ 	addiu	$a2,$a2,%lo(g_ScreenWidthMultiplier)
/*  f0e37e8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f0e37ec:	02077821 */ 	addu	$t7,$s0,$a3
/*  f0e37f0:	3c01f600 */ 	lui	$at,0xf600
/*  f0e37f4:	01f80019 */ 	multu	$t7,$t8
/*  f0e37f8:	02277821 */ 	addu	$t7,$s1,$a3
/*  f0e37fc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0e3800:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0e3804:	0000c812 */ 	mflo	$t9
/*  f0e3808:	332c03ff */ 	andi	$t4,$t9,0x3ff
/*  f0e380c:	000c6b80 */ 	sll	$t5,$t4,0xe
/*  f0e3810:	01a17025 */ 	or	$t6,$t5,$at
/*  f0e3814:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0e3818:	01d96025 */ 	or	$t4,$t6,$t9
/*  f0e381c:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0e3820:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f0e3824:	323903ff */ 	andi	$t9,$s1,0x3ff
/*  f0e3828:	00196080 */ 	sll	$t4,$t9,0x2
/*  f0e382c:	020d0019 */ 	multu	$s0,$t5
/*  f0e3830:	00007812 */ 	mflo	$t7
/*  f0e3834:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0e3838:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0e383c:	01cc6825 */ 	or	$t5,$t6,$t4
/*  f0e3840:	0fc54e0e */ 	jal	func0f153838
/*  f0e3844:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f0e3848:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f0e384c:	00402025 */ 	or	$a0,$v0,$zero
.L0f0e3850:
/*  f0e3850:	02275021 */ 	addu	$t2,$s1,$a3
/*  f0e3854:	314803ff */ 	andi	$t0,$t2,0x3ff
/*  f0e3858:	323803ff */ 	andi	$t8,$s1,0x3ff
/*  f0e385c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0e3860:	00087880 */ 	sll	$t7,$t0,0x2
/*  f0e3864:	02074821 */ 	addu	$t1,$s0,$a3
/*  f0e3868:	afa90030 */ 	sw	$t1,0x30($sp)
/*  f0e386c:	01e04025 */ 	or	$t0,$t7,$zero
/*  f0e3870:	afaf0028 */ 	sw	$t7,0x28($sp)
/*  f0e3874:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f0e3878:	afaa002c */ 	sw	$t2,0x2c($sp)
/*  f0e387c:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0e3880:	8fa5005c */ 	lw	$a1,0x5c($sp)
/*  f0e3884:	3c068008 */ 	lui	$a2,%hi(g_ScreenWidthMultiplier)
/*  f0e3888:	8fa90030 */ 	lw	$t1,0x30($sp)
/*  f0e388c:	24c6fac0 */ 	addiu	$a2,$a2,%lo(g_ScreenWidthMultiplier)
/*  f0e3890:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f0e3894:	25230001 */ 	addiu	$v1,$t1,0x1
/*  f0e3898:	26250001 */ 	addiu	$a1,$s1,0x1
/*  f0e389c:	006d0019 */ 	multu	$v1,$t5
/*  f0e38a0:	30ae03ff */ 	andi	$t6,$a1,0x3ff
/*  f0e38a4:	3c0bf600 */ 	lui	$t3,0xf600
/*  f0e38a8:	000e2880 */ 	sll	$a1,$t6,0x2
/*  f0e38ac:	8fa80028 */ 	lw	$t0,0x28($sp)
/*  f0e38b0:	8faa002c */ 	lw	$t2,0x2c($sp)
/*  f0e38b4:	24470018 */ 	addiu	$a3,$v0,0x18
/*  f0e38b8:	24440020 */ 	addiu	$a0,$v0,0x20
/*  f0e38bc:	00007812 */ 	mflo	$t7
/*  f0e38c0:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0e38c4:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0e38c8:	032b7025 */ 	or	$t6,$t9,$t3
/*  f0e38cc:	01c56025 */ 	or	$t4,$t6,$a1
/*  f0e38d0:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0e38d4:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f0e38d8:	8fae0024 */ 	lw	$t6,0x24($sp)
/*  f0e38dc:	020d0019 */ 	multu	$s0,$t5
/*  f0e38e0:	00007812 */ 	mflo	$t7
/*  f0e38e4:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0e38e8:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0e38ec:	032e6025 */ 	or	$t4,$t9,$t6
/*  f0e38f0:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f0e38f4:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f0e38f8:	254c0001 */ 	addiu	$t4,$t2,0x1
/*  f0e38fc:	006d0019 */ 	multu	$v1,$t5
/*  f0e3900:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f0e3904:	00007812 */ 	mflo	$t7
/*  f0e3908:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0e390c:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0e3910:	032b7025 */ 	or	$t6,$t9,$t3
/*  f0e3914:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f0e3918:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f0e391c:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f0e3920:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f0e3924:	26180001 */ 	addiu	$t8,$s0,0x1
/*  f0e3928:	02190019 */ 	multu	$s0,$t9
/*  f0e392c:	00006012 */ 	mflo	$t4
/*  f0e3930:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f0e3934:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f0e3938:	01c87825 */ 	or	$t7,$t6,$t0
/*  f0e393c:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f0e3940:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f0e3944:	03190019 */ 	multu	$t8,$t9
/*  f0e3948:	00006012 */ 	mflo	$t4
/*  f0e394c:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f0e3950:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f0e3954:	01cb7825 */ 	or	$t7,$t6,$t3
/*  f0e3958:	01e8c025 */ 	or	$t8,$t7,$t0
/*  f0e395c:	ac580010 */ 	sw	$t8,0x10($v0)
/*  f0e3960:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f0e3964:	02190019 */ 	multu	$s0,$t9
/*  f0e3968:	00006012 */ 	mflo	$t4
/*  f0e396c:	318d03ff */ 	andi	$t5,$t4,0x3ff
/*  f0e3970:	000d7380 */ 	sll	$t6,$t5,0xe
/*  f0e3974:	01c57825 */ 	or	$t7,$t6,$a1
/*  f0e3978:	ac4f0014 */ 	sw	$t7,0x14($v0)
/*  f0e397c:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f0e3980:	00780019 */ 	multu	$v1,$t8
/*  f0e3984:	0000c812 */ 	mflo	$t9
/*  f0e3988:	332c03ff */ 	andi	$t4,$t9,0x3ff
/*  f0e398c:	000c6b80 */ 	sll	$t5,$t4,0xe
/*  f0e3990:	01ab7025 */ 	or	$t6,$t5,$t3
/*  f0e3994:	01c87825 */ 	or	$t7,$t6,$t0
/*  f0e3998:	ac4f0018 */ 	sw	$t7,0x18($v0)
/*  f0e399c:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f0e39a0:	01380019 */ 	multu	$t1,$t8
/*  f0e39a4:	0000c812 */ 	mflo	$t9
/*  f0e39a8:	332c03ff */ 	andi	$t4,$t9,0x3ff
/*  f0e39ac:	000c6b80 */ 	sll	$t5,$t4,0xe
/*  f0e39b0:	01a57025 */ 	or	$t6,$t5,$a1
/*  f0e39b4:	0fc54e0e */ 	jal	func0f153838
/*  f0e39b8:	acee0004 */ 	sw	$t6,0x4($a3)
/*  f0e39bc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0e39c0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0e39c4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0e39c8:	03e00008 */ 	jr	$ra
/*  f0e39cc:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f0e39d0
/*  f0e39d0:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f0e39d4:	3c017f1b */ 	lui	$at,%hi(var7f1adf1c)
/*  f0e39d8:	c424df1c */ 	lwc1	$f4,%lo(var7f1adf1c)($at)
/*  f0e39dc:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f0e39e0:	c4261630 */ 	lwc1	$f6,%lo(var80061630)($at)
/*  f0e39e4:	3c02800a */ 	lui	$v0,%hi(var8009de9c)
/*  f0e39e8:	2442de9c */ 	addiu	$v0,$v0,%lo(var8009de9c)
/*  f0e39ec:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e39f0:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f0e39f4:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f0e39f8:	3c01800a */ 	lui	$at,%hi(var8009de98)
/*  f0e39fc:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f0e3a00:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f0e3a04:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f0e3a08:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f0e3a0c:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f0e3a10:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f0e3a14:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0e3a18:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f0e3a1c:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f0e3a20:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f0e3a24:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f0e3a28:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f0e3a2c:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f0e3a30:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f0e3a34:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f0e3a38:	e7a800b4 */ 	swc1	$f8,0xb4($sp)
/*  f0e3a3c:	ac20de98 */ 	sw	$zero,%lo(var8009de98)($at)
/*  f0e3a40:	0fc3528f */ 	jal	func0f0d4a3c
/*  f0e3a44:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e3a48:	3c0ffffe */ 	lui	$t7,0xfffe
/*  f0e3a4c:	35ef7960 */ 	ori	$t7,$t7,0x7960
/*  f0e3a50:	3c01800a */ 	lui	$at,%hi(var8009de90)
/*  f0e3a54:	ac2fde90 */ 	sw	$t7,%lo(var8009de90)($at)
/*  f0e3a58:	3c180001 */ 	lui	$t8,0x1
/*  f0e3a5c:	371886a0 */ 	ori	$t8,$t8,0x86a0
/*  f0e3a60:	3c01800a */ 	lui	$at,%hi(var8009de94)
/*  f0e3a64:	24197f7f */ 	addiu	$t9,$zero,0x7f7f
/*  f0e3a68:	24087f7f */ 	addiu	$t0,$zero,0x7f7f
/*  f0e3a6c:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f0e3a70:	ac38de94 */ 	sw	$t8,%lo(var8009de94)($at)
/*  f0e3a74:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0e3a78:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0e3a7c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0e3a80:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e3a84:	2405d8f0 */ 	addiu	$a1,$zero,-10000
/*  f0e3a88:	00003025 */ 	or	$a2,$zero,$zero
/*  f0e3a8c:	24072710 */ 	addiu	$a3,$zero,0x2710
/*  f0e3a90:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e3a94:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0e3a98:	240a012c */ 	addiu	$t2,$zero,0x12c
/*  f0e3a9c:	240b7f7f */ 	addiu	$t3,$zero,0x7f7f
/*  f0e3aa0:	240c7f7f */ 	addiu	$t4,$zero,0x7f7f
/*  f0e3aa4:	240d0004 */ 	addiu	$t5,$zero,0x4
/*  f0e3aa8:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e3aac:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0e3ab0:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0e3ab4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e3ab8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e3abc:	2405d8f0 */ 	addiu	$a1,$zero,-10000
/*  f0e3ac0:	2406012c */ 	addiu	$a2,$zero,0x12c
/*  f0e3ac4:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e3ac8:	24072710 */ 	addiu	$a3,$zero,0x2710
/*  f0e3acc:	3c01c000 */ 	lui	$at,0xc000
/*  f0e3ad0:	c7a200b4 */ 	lwc1	$f2,0xb4($sp)
/*  f0e3ad4:	44815000 */ 	mtc1	$at,$f10
/*  f0e3ad8:	3c014080 */ 	lui	$at,0x4080
/*  f0e3adc:	4481f000 */ 	mtc1	$at,$f30
/*  f0e3ae0:	46025402 */ 	mul.s	$f16,$f10,$f2
/*  f0e3ae4:	3c014416 */ 	lui	$at,0x4416
/*  f0e3ae8:	4481c000 */ 	mtc1	$at,$f24
/*  f0e3aec:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f0e3af0:	afa000b0 */ 	sw	$zero,0xb0($sp)
/*  f0e3af4:	e7b00080 */ 	swc1	$f16,0x80($sp)
.L0f0e3af8:
/*  f0e3af8:	8fa300b0 */ 	lw	$v1,0xb0($sp)
/*  f0e3afc:	3c017f1b */ 	lui	$at,%hi(var7f1adf20)
/*  f0e3b00:	c426df20 */ 	lwc1	$f6,%lo(var7f1adf20)($at)
/*  f0e3b04:	44839000 */ 	mtc1	$v1,$f18
/*  f0e3b08:	3c014040 */ 	lui	$at,0x4040
/*  f0e3b0c:	44815000 */ 	mtc1	$at,$f10
/*  f0e3b10:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f0e3b14:	c7a200b4 */ 	lwc1	$f2,0xb4($sp)
/*  f0e3b18:	46000100 */ 	add.s	$f4,$f0,$f0
/*  f0e3b1c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e3b20:	460a4703 */ 	div.s	$f28,$f8,$f10
/*  f0e3b24:	4602e580 */ 	add.s	$f22,$f28,$f2
/*  f0e3b28:	0c0068f7 */ 	jal	sinf
/*  f0e3b2c:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e3b30:	46180402 */ 	mul.s	$f16,$f0,$f24
/*  f0e3b34:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e3b38:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e3b3c:	44169000 */ 	mfc1	$s6,$f18
/*  f0e3b40:	0c0068f4 */ 	jal	cosf
/*  f0e3b44:	00000000 */ 	nop
/*  f0e3b48:	46180102 */ 	mul.s	$f4,$f0,$f24
/*  f0e3b4c:	3c017f1b */ 	lui	$at,%hi(var7f1adf24)
/*  f0e3b50:	c428df24 */ 	lwc1	$f8,%lo(var7f1adf24)($at)
/*  f0e3b54:	4608b500 */ 	add.s	$f20,$f22,$f8
/*  f0e3b58:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e3b5c:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e3b60:	44133000 */ 	mfc1	$s3,$f6
/*  f0e3b64:	0c0068f7 */ 	jal	sinf
/*  f0e3b68:	00000000 */ 	nop
/*  f0e3b6c:	46180282 */ 	mul.s	$f10,$f0,$f24
/*  f0e3b70:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e3b74:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e3b78:	44128000 */ 	mfc1	$s2,$f16
/*  f0e3b7c:	0c0068f4 */ 	jal	cosf
/*  f0e3b80:	00000000 */ 	nop
/*  f0e3b84:	46180482 */ 	mul.s	$f18,$f0,$f24
/*  f0e3b88:	3c017f1b */ 	lui	$at,%hi(var7f1adf28)
/*  f0e3b8c:	c426df28 */ 	lwc1	$f6,%lo(var7f1adf28)($at)
/*  f0e3b90:	4606a500 */ 	add.s	$f20,$f20,$f6
/*  f0e3b94:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e3b98:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e3b9c:	44102000 */ 	mfc1	$s0,$f4
/*  f0e3ba0:	0c0068f7 */ 	jal	sinf
/*  f0e3ba4:	00000000 */ 	nop
/*  f0e3ba8:	46180202 */ 	mul.s	$f8,$f0,$f24
/*  f0e3bac:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e3bb0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e3bb4:	44115000 */ 	mfc1	$s1,$f10
/*  f0e3bb8:	0c0068f4 */ 	jal	cosf
/*  f0e3bbc:	00000000 */ 	nop
/*  f0e3bc0:	46180402 */ 	mul.s	$f16,$f0,$f24
/*  f0e3bc4:	3c0aff00 */ 	lui	$t2,0xff00
/*  f0e3bc8:	3c0bff00 */ 	lui	$t3,0xff00
/*  f0e3bcc:	265200a0 */ 	addiu	$s2,$s2,0xa0
/*  f0e3bd0:	26100078 */ 	addiu	$s0,$s0,0x78
/*  f0e3bd4:	356b007f */ 	ori	$t3,$t3,0x7f
/*  f0e3bd8:	354a0040 */ 	ori	$t2,$t2,0x40
/*  f0e3bdc:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e3be0:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f0e3be4:	26c500a0 */ 	addiu	$a1,$s6,0xa0
/*  f0e3be8:	263100a0 */ 	addiu	$s1,$s1,0xa0
/*  f0e3bec:	44179000 */ 	mfc1	$s7,$f18
/*  f0e3bf0:	26660078 */ 	addiu	$a2,$s3,0x78
/*  f0e3bf4:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0e3bf8:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0e3bfc:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0e3c00:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0e3c04:	02403825 */ 	or	$a3,$s2,$zero
/*  f0e3c08:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*  f0e3c0c:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e3c10:	26f70078 */ 	addiu	$s7,$s7,0x78
/*  f0e3c14:	3c0dff00 */ 	lui	$t5,0xff00
/*  f0e3c18:	3c0eff00 */ 	lui	$t6,0xff00
/*  f0e3c1c:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f0e3c20:	35ad007f */ 	ori	$t5,$t5,0x7f
/*  f0e3c24:	240f0003 */ 	addiu	$t7,$zero,0x3
/*  f0e3c28:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0e3c2c:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e3c30:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0e3c34:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e3c38:	02402825 */ 	or	$a1,$s2,$zero
/*  f0e3c3c:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e3c40:	02203825 */ 	or	$a3,$s1,$zero
/*  f0e3c44:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e3c48:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0e3c4c:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f0e3c50:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f0e3c54:	461c2680 */ 	add.s	$f26,$f4,$f28
/*  f0e3c58:	0c0068f7 */ 	jal	sinf
/*  f0e3c5c:	4600d306 */ 	mov.s	$f12,$f26
/*  f0e3c60:	46180182 */ 	mul.s	$f6,$f0,$f24
/*  f0e3c64:	4600d306 */ 	mov.s	$f12,$f26
/*  f0e3c68:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0e3c6c:	44164000 */ 	mfc1	$s6,$f8
/*  f0e3c70:	0c0068f4 */ 	jal	cosf
/*  f0e3c74:	00000000 */ 	nop
/*  f0e3c78:	46180282 */ 	mul.s	$f10,$f0,$f24
/*  f0e3c7c:	3c017f1b */ 	lui	$at,%hi(var7f1adf2c)
/*  f0e3c80:	c432df2c */ 	lwc1	$f18,%lo(var7f1adf2c)($at)
/*  f0e3c84:	4612d500 */ 	add.s	$f20,$f26,$f18
/*  f0e3c88:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e3c8c:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e3c90:	44138000 */ 	mfc1	$s3,$f16
/*  f0e3c94:	0c0068f7 */ 	jal	sinf
/*  f0e3c98:	00000000 */ 	nop
/*  f0e3c9c:	46180102 */ 	mul.s	$f4,$f0,$f24
/*  f0e3ca0:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e3ca4:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e3ca8:	44123000 */ 	mfc1	$s2,$f6
/*  f0e3cac:	0c0068f4 */ 	jal	cosf
/*  f0e3cb0:	00000000 */ 	nop
/*  f0e3cb4:	46180202 */ 	mul.s	$f8,$f0,$f24
/*  f0e3cb8:	3c017f1b */ 	lui	$at,%hi(var7f1adf30)
/*  f0e3cbc:	c430df30 */ 	lwc1	$f16,%lo(var7f1adf30)($at)
/*  f0e3cc0:	4610a500 */ 	add.s	$f20,$f20,$f16
/*  f0e3cc4:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e3cc8:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e3ccc:	44105000 */ 	mfc1	$s0,$f10
/*  f0e3cd0:	0c0068f7 */ 	jal	sinf
/*  f0e3cd4:	00000000 */ 	nop
/*  f0e3cd8:	46180482 */ 	mul.s	$f18,$f0,$f24
/*  f0e3cdc:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e3ce0:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e3ce4:	44112000 */ 	mfc1	$s1,$f4
/*  f0e3ce8:	0c0068f4 */ 	jal	cosf
/*  f0e3cec:	00000000 */ 	nop
/*  f0e3cf0:	46180182 */ 	mul.s	$f6,$f0,$f24
/*  f0e3cf4:	26d600a0 */ 	addiu	$s6,$s6,0xa0
/*  f0e3cf8:	265200a0 */ 	addiu	$s2,$s2,0xa0
/*  f0e3cfc:	263100a0 */ 	addiu	$s1,$s1,0xa0
/*  f0e3d00:	26730078 */ 	addiu	$s3,$s3,0x78
/*  f0e3d04:	26100078 */ 	addiu	$s0,$s0,0x78
/*  f0e3d08:	4600f306 */ 	mov.s	$f12,$f30
/*  f0e3d0c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0e3d10:	44174000 */ 	mfc1	$s7,$f8
/*  f0e3d14:	0fc01ad5 */ 	jal	func0f006b54
/*  f0e3d18:	26f70078 */ 	addiu	$s7,$s7,0x78
/*  f0e3d1c:	3c0142fe */ 	lui	$at,0x42fe
/*  f0e3d20:	44815000 */ 	mtc1	$at,$f10
/*  f0e3d24:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0e3d28:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e3d2c:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f0e3d30:	444cf800 */ 	cfc1	$t4,$31
/*  f0e3d34:	44d4f800 */ 	ctc1	$s4,$31
/*  f0e3d38:	00000000 */ 	nop
/*  f0e3d3c:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f0e3d40:	4454f800 */ 	cfc1	$s4,$31
/*  f0e3d44:	00000000 */ 	nop
/*  f0e3d48:	32940078 */ 	andi	$s4,$s4,0x78
/*  f0e3d4c:	52800013 */ 	beqzl	$s4,.L0f0e3d9c
/*  f0e3d50:	44149000 */ 	mfc1	$s4,$f18
/*  f0e3d54:	44819000 */ 	mtc1	$at,$f18
/*  f0e3d58:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0e3d5c:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f0e3d60:	44d4f800 */ 	ctc1	$s4,$31
/*  f0e3d64:	00000000 */ 	nop
/*  f0e3d68:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f0e3d6c:	4454f800 */ 	cfc1	$s4,$31
/*  f0e3d70:	00000000 */ 	nop
/*  f0e3d74:	32940078 */ 	andi	$s4,$s4,0x78
/*  f0e3d78:	16800005 */ 	bnez	$s4,.L0f0e3d90
/*  f0e3d7c:	00000000 */ 	nop
/*  f0e3d80:	44149000 */ 	mfc1	$s4,$f18
/*  f0e3d84:	3c018000 */ 	lui	$at,0x8000
/*  f0e3d88:	10000007 */ 	b	.L0f0e3da8
/*  f0e3d8c:	0281a025 */ 	or	$s4,$s4,$at
.L0f0e3d90:
/*  f0e3d90:	10000005 */ 	b	.L0f0e3da8
/*  f0e3d94:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f0e3d98:	44149000 */ 	mfc1	$s4,$f18
.L0f0e3d9c:
/*  f0e3d9c:	00000000 */ 	nop
/*  f0e3da0:	0680fffb */ 	bltz	$s4,.L0f0e3d90
/*  f0e3da4:	00000000 */ 	nop
.L0f0e3da8:
/*  f0e3da8:	44ccf800 */ 	ctc1	$t4,$31
/*  f0e3dac:	0fc01ad5 */ 	jal	func0f006b54
/*  f0e3db0:	4600f306 */ 	mov.s	$f12,$f30
/*  f0e3db4:	3c01425c */ 	lui	$at,0x425c
/*  f0e3db8:	44812000 */ 	mtc1	$at,$f4
/*  f0e3dbc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0e3dc0:	3c03ffff */ 	lui	$v1,0xffff
/*  f0e3dc4:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0e3dc8:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e3dcc:	0074f025 */ 	or	$s8,$v1,$s4
/*  f0e3dd0:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*  f0e3dd4:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e3dd8:	02603025 */ 	or	$a2,$s3,$zero
/*  f0e3ddc:	02403825 */ 	or	$a3,$s2,$zero
/*  f0e3de0:	444df800 */ 	cfc1	$t5,$31
/*  f0e3de4:	44c2f800 */ 	ctc1	$v0,$31
/*  f0e3de8:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0e3dec:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0e3df0:	4442f800 */ 	cfc1	$v0,$31
/*  f0e3df4:	00000000 */ 	nop
/*  f0e3df8:	30420078 */ 	andi	$v0,$v0,0x78
/*  f0e3dfc:	50400013 */ 	beqzl	$v0,.L0f0e3e4c
/*  f0e3e00:	44024000 */ 	mfc1	$v0,$f8
/*  f0e3e04:	44814000 */ 	mtc1	$at,$f8
/*  f0e3e08:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0e3e0c:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0e3e10:	44c2f800 */ 	ctc1	$v0,$31
/*  f0e3e14:	00000000 */ 	nop
/*  f0e3e18:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0e3e1c:	4442f800 */ 	cfc1	$v0,$31
/*  f0e3e20:	00000000 */ 	nop
/*  f0e3e24:	30420078 */ 	andi	$v0,$v0,0x78
/*  f0e3e28:	14400005 */ 	bnez	$v0,.L0f0e3e40
/*  f0e3e2c:	00000000 */ 	nop
/*  f0e3e30:	44024000 */ 	mfc1	$v0,$f8
/*  f0e3e34:	3c018000 */ 	lui	$at,0x8000
/*  f0e3e38:	10000007 */ 	b	.L0f0e3e58
/*  f0e3e3c:	00411025 */ 	or	$v0,$v0,$at
.L0f0e3e40:
/*  f0e3e40:	10000005 */ 	b	.L0f0e3e58
/*  f0e3e44:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0e3e48:	44024000 */ 	mfc1	$v0,$f8
.L0f0e3e4c:
/*  f0e3e4c:	00000000 */ 	nop
/*  f0e3e50:	0440fffb */ 	bltz	$v0,.L0f0e3e40
/*  f0e3e54:	00000000 */ 	nop
.L0f0e3e58:
/*  f0e3e58:	44cdf800 */ 	ctc1	$t5,$31
/*  f0e3e5c:	00627025 */ 	or	$t6,$v1,$v0
/*  f0e3e60:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0e3e64:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e3e68:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0e3e6c:	afbe0018 */ 	sw	$s8,0x18($sp)
/*  f0e3e70:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e3e74:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0e3e78:	3c01ffff */ 	lui	$at,0xffff
/*  f0e3e7c:	02a1c025 */ 	or	$t8,$s5,$at
/*  f0e3e80:	24190003 */ 	addiu	$t9,$zero,0x3
/*  f0e3e84:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e3e88:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0e3e8c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e3e90:	02402825 */ 	or	$a1,$s2,$zero
/*  f0e3e94:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e3e98:	02203825 */ 	or	$a3,$s1,$zero
/*  f0e3e9c:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0e3ea0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e3ea4:	afbe0014 */ 	sw	$s8,0x14($sp)
/*  f0e3ea8:	3c017f1b */ 	lui	$at,%hi(var7f1adf34)
/*  f0e3eac:	c42adf34 */ 	lwc1	$f10,%lo(var7f1adf34)($at)
/*  f0e3eb0:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f0e3eb4:	460ad580 */ 	add.s	$f22,$f26,$f10
/*  f0e3eb8:	0c0068f7 */ 	jal	sinf
/*  f0e3ebc:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e3ec0:	46180402 */ 	mul.s	$f16,$f0,$f24
/*  f0e3ec4:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e3ec8:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e3ecc:	44169000 */ 	mfc1	$s6,$f18
/*  f0e3ed0:	0c0068f4 */ 	jal	cosf
/*  f0e3ed4:	00000000 */ 	nop
/*  f0e3ed8:	46180102 */ 	mul.s	$f4,$f0,$f24
/*  f0e3edc:	3c017f1b */ 	lui	$at,%hi(var7f1adf38)
/*  f0e3ee0:	c428df38 */ 	lwc1	$f8,%lo(var7f1adf38)($at)
/*  f0e3ee4:	4608b500 */ 	add.s	$f20,$f22,$f8
/*  f0e3ee8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e3eec:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e3ef0:	44133000 */ 	mfc1	$s3,$f6
/*  f0e3ef4:	0c0068f7 */ 	jal	sinf
/*  f0e3ef8:	00000000 */ 	nop
/*  f0e3efc:	46180282 */ 	mul.s	$f10,$f0,$f24
/*  f0e3f00:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e3f04:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e3f08:	44128000 */ 	mfc1	$s2,$f16
/*  f0e3f0c:	0c0068f4 */ 	jal	cosf
/*  f0e3f10:	00000000 */ 	nop
/*  f0e3f14:	46180482 */ 	mul.s	$f18,$f0,$f24
/*  f0e3f18:	3c017f1b */ 	lui	$at,%hi(var7f1adf3c)
/*  f0e3f1c:	c426df3c */ 	lwc1	$f6,%lo(var7f1adf3c)($at)
/*  f0e3f20:	4606a500 */ 	add.s	$f20,$f20,$f6
/*  f0e3f24:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e3f28:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e3f2c:	44102000 */ 	mfc1	$s0,$f4
/*  f0e3f30:	0c0068f7 */ 	jal	sinf
/*  f0e3f34:	00000000 */ 	nop
/*  f0e3f38:	46180202 */ 	mul.s	$f8,$f0,$f24
/*  f0e3f3c:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e3f40:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e3f44:	44115000 */ 	mfc1	$s1,$f10
/*  f0e3f48:	0c0068f4 */ 	jal	cosf
/*  f0e3f4c:	00000000 */ 	nop
/*  f0e3f50:	46180402 */ 	mul.s	$f16,$f0,$f24
/*  f0e3f54:	26d600a0 */ 	addiu	$s6,$s6,0xa0
/*  f0e3f58:	265200a0 */ 	addiu	$s2,$s2,0xa0
/*  f0e3f5c:	263100a0 */ 	addiu	$s1,$s1,0xa0
/*  f0e3f60:	26730078 */ 	addiu	$s3,$s3,0x78
/*  f0e3f64:	26100078 */ 	addiu	$s0,$s0,0x78
/*  f0e3f68:	4600f306 */ 	mov.s	$f12,$f30
/*  f0e3f6c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e3f70:	44179000 */ 	mfc1	$s7,$f18
/*  f0e3f74:	0fc01ad5 */ 	jal	func0f006b54
/*  f0e3f78:	26f70078 */ 	addiu	$s7,$s7,0x78
/*  f0e3f7c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0e3f80:	44812000 */ 	mtc1	$at,$f4
/*  f0e3f84:	3c0142c6 */ 	lui	$at,0x42c6
/*  f0e3f88:	44814000 */ 	mtc1	$at,$f8
/*  f0e3f8c:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0e3f90:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0e3f94:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e3f98:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0e3f9c:	444ef800 */ 	cfc1	$t6,$31
/*  f0e3fa0:	44d4f800 */ 	ctc1	$s4,$31
/*  f0e3fa4:	00000000 */ 	nop
/*  f0e3fa8:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0e3fac:	4454f800 */ 	cfc1	$s4,$31
/*  f0e3fb0:	00000000 */ 	nop
/*  f0e3fb4:	32940078 */ 	andi	$s4,$s4,0x78
/*  f0e3fb8:	52800013 */ 	beqzl	$s4,.L0f0e4008
/*  f0e3fbc:	44148000 */ 	mfc1	$s4,$f16
/*  f0e3fc0:	44818000 */ 	mtc1	$at,$f16
/*  f0e3fc4:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0e3fc8:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0e3fcc:	44d4f800 */ 	ctc1	$s4,$31
/*  f0e3fd0:	00000000 */ 	nop
/*  f0e3fd4:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0e3fd8:	4454f800 */ 	cfc1	$s4,$31
/*  f0e3fdc:	00000000 */ 	nop
/*  f0e3fe0:	32940078 */ 	andi	$s4,$s4,0x78
/*  f0e3fe4:	16800005 */ 	bnez	$s4,.L0f0e3ffc
/*  f0e3fe8:	00000000 */ 	nop
/*  f0e3fec:	44148000 */ 	mfc1	$s4,$f16
/*  f0e3ff0:	3c018000 */ 	lui	$at,0x8000
/*  f0e3ff4:	10000007 */ 	b	.L0f0e4014
/*  f0e3ff8:	0281a025 */ 	or	$s4,$s4,$at
.L0f0e3ffc:
/*  f0e3ffc:	10000005 */ 	b	.L0f0e4014
/*  f0e4000:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f0e4004:	44148000 */ 	mfc1	$s4,$f16
.L0f0e4008:
/*  f0e4008:	00000000 */ 	nop
/*  f0e400c:	0680fffb */ 	bltz	$s4,.L0f0e3ffc
/*  f0e4010:	00000000 */ 	nop
.L0f0e4014:
/*  f0e4014:	44cef800 */ 	ctc1	$t6,$31
/*  f0e4018:	0fc01ad5 */ 	jal	func0f006b54
/*  f0e401c:	4600f306 */ 	mov.s	$f12,$f30
/*  f0e4020:	3c013f80 */ 	lui	$at,0x3f80
/*  f0e4024:	44819000 */ 	mtc1	$at,$f18
/*  f0e4028:	3c014204 */ 	lui	$at,0x4204
/*  f0e402c:	44813000 */ 	mtc1	$at,$f6
/*  f0e4030:	46009101 */ 	sub.s	$f4,$f18,$f0
/*  f0e4034:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0e4038:	2403ff00 */ 	addiu	$v1,$zero,-256
/*  f0e403c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e4040:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e4044:	0074f025 */ 	or	$s8,$v1,$s4
/*  f0e4048:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*  f0e404c:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e4050:	02603025 */ 	or	$a2,$s3,$zero
/*  f0e4054:	02403825 */ 	or	$a3,$s2,$zero
/*  f0e4058:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0e405c:	444ff800 */ 	cfc1	$t7,$31
/*  f0e4060:	44c2f800 */ 	ctc1	$v0,$31
/*  f0e4064:	00000000 */ 	nop
/*  f0e4068:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0e406c:	4442f800 */ 	cfc1	$v0,$31
/*  f0e4070:	00000000 */ 	nop
/*  f0e4074:	30420078 */ 	andi	$v0,$v0,0x78
/*  f0e4078:	50400013 */ 	beqzl	$v0,.L0f0e40c8
/*  f0e407c:	44025000 */ 	mfc1	$v0,$f10
/*  f0e4080:	44815000 */ 	mtc1	$at,$f10
/*  f0e4084:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0e4088:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0e408c:	44c2f800 */ 	ctc1	$v0,$31
/*  f0e4090:	00000000 */ 	nop
/*  f0e4094:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0e4098:	4442f800 */ 	cfc1	$v0,$31
/*  f0e409c:	00000000 */ 	nop
/*  f0e40a0:	30420078 */ 	andi	$v0,$v0,0x78
/*  f0e40a4:	14400005 */ 	bnez	$v0,.L0f0e40bc
/*  f0e40a8:	00000000 */ 	nop
/*  f0e40ac:	44025000 */ 	mfc1	$v0,$f10
/*  f0e40b0:	3c018000 */ 	lui	$at,0x8000
/*  f0e40b4:	10000007 */ 	b	.L0f0e40d4
/*  f0e40b8:	00411025 */ 	or	$v0,$v0,$at
.L0f0e40bc:
/*  f0e40bc:	10000005 */ 	b	.L0f0e40d4
/*  f0e40c0:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0e40c4:	44025000 */ 	mfc1	$v0,$f10
.L0f0e40c8:
/*  f0e40c8:	00000000 */ 	nop
/*  f0e40cc:	0440fffb */ 	bltz	$v0,.L0f0e40bc
/*  f0e40d0:	00000000 */ 	nop
.L0f0e40d4:
/*  f0e40d4:	44cff800 */ 	ctc1	$t7,$31
/*  f0e40d8:	0062c025 */ 	or	$t8,$v1,$v0
/*  f0e40dc:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0e40e0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e40e4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0e40e8:	afbe0018 */ 	sw	$s8,0x18($sp)
/*  f0e40ec:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e40f0:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e40f4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e40f8:	02a14025 */ 	or	$t0,$s5,$at
/*  f0e40fc:	24090003 */ 	addiu	$t1,$zero,0x3
/*  f0e4100:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0e4104:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0e4108:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e410c:	02402825 */ 	or	$a1,$s2,$zero
/*  f0e4110:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e4114:	02203825 */ 	or	$a3,$s1,$zero
/*  f0e4118:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0e411c:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e4120:	afbe0014 */ 	sw	$s8,0x14($sp)
/*  f0e4124:	8fa300b0 */ 	lw	$v1,0xb0($sp)
/*  f0e4128:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0e412c:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f0e4130:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e4134:	afa300b0 */ 	sw	$v1,0xb0($sp)
/*  f0e4138:	1461fe6f */ 	bne	$v1,$at,.L0f0e3af8
/*  f0e413c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e4140:	0fc35320 */ 	jal	func0f0d4c80
/*  f0e4144:	00000000 */ 	nop
/*  f0e4148:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f0e414c:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f0e4150:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f0e4154:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f0e4158:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f0e415c:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f0e4160:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f0e4164:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f0e4168:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f0e416c:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0e4170:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f0e4174:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f0e4178:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f0e417c:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f0e4180:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f0e4184:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f0e4188:	03e00008 */ 	jr	$ra
/*  f0e418c:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);

GLOBAL_ASM(
glabel func0f0e4190
/*  f0e4190:	27bdff60 */ 	addiu	$sp,$sp,-160
/*  f0e4194:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f0e4198:	3c168006 */ 	lui	$s6,%hi(var80061630)
/*  f0e419c:	26d61630 */ 	addiu	$s6,$s6,%lo(var80061630)
/*  f0e41a0:	3c017f1b */ 	lui	$at,%hi(var7f1adf40)
/*  f0e41a4:	c424df40 */ 	lwc1	$f4,%lo(var7f1adf40)($at)
/*  f0e41a8:	c6c60000 */ 	lwc1	$f6,0x0($s6)
/*  f0e41ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f0e41b0:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f0e41b4:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f0e41b8:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f0e41bc:	44816000 */ 	mtc1	$at,$f12
/*  f0e41c0:	0080a825 */ 	or	$s5,$a0,$zero
/*  f0e41c4:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f0e41c8:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f0e41cc:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0e41d0:	46000200 */ 	add.s	$f8,$f0,$f0
/*  f0e41d4:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f0e41d8:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f0e41dc:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f0e41e0:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f0e41e4:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f0e41e8:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f0e41ec:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f0e41f0:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f0e41f4:	0fc01ac2 */ 	jal	func0f006b08
/*  f0e41f8:	e7a8009c */ 	swc1	$f8,0x9c($sp)
/*  f0e41fc:	3c01437f */ 	lui	$at,0x437f
/*  f0e4200:	44815000 */ 	mtc1	$at,$f10
/*  f0e4204:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0e4208:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e420c:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f0e4210:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0e4214:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e4218:	444ef800 */ 	cfc1	$t6,$31
/*  f0e421c:	44d0f800 */ 	ctc1	$s0,$31
/*  f0e4220:	00000000 */ 	nop
/*  f0e4224:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f0e4228:	4450f800 */ 	cfc1	$s0,$31
/*  f0e422c:	00000000 */ 	nop
/*  f0e4230:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0e4234:	52000013 */ 	beqzl	$s0,.L0f0e4284
/*  f0e4238:	44109000 */ 	mfc1	$s0,$f18
/*  f0e423c:	44819000 */ 	mtc1	$at,$f18
/*  f0e4240:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0e4244:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f0e4248:	44d0f800 */ 	ctc1	$s0,$31
/*  f0e424c:	00000000 */ 	nop
/*  f0e4250:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f0e4254:	4450f800 */ 	cfc1	$s0,$31
/*  f0e4258:	00000000 */ 	nop
/*  f0e425c:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0e4260:	16000005 */ 	bnez	$s0,.L0f0e4278
/*  f0e4264:	00000000 */ 	nop
/*  f0e4268:	44109000 */ 	mfc1	$s0,$f18
/*  f0e426c:	3c018000 */ 	lui	$at,0x8000
/*  f0e4270:	10000007 */ 	b	.L0f0e4290
/*  f0e4274:	02018025 */ 	or	$s0,$s0,$at
.L0f0e4278:
/*  f0e4278:	10000005 */ 	b	.L0f0e4290
/*  f0e427c:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f0e4280:	44109000 */ 	mfc1	$s0,$f18
.L0f0e4284:
/*  f0e4284:	00000000 */ 	nop
/*  f0e4288:	0600fffb */ 	bltz	$s0,.L0f0e4278
/*  f0e428c:	00000000 */ 	nop
.L0f0e4290:
/*  f0e4290:	44cef800 */ 	ctc1	$t6,$31
/*  f0e4294:	00107c00 */ 	sll	$t7,$s0,0x10
/*  f0e4298:	0fc3528f */ 	jal	func0f0d4a3c
/*  f0e429c:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0e42a0:	3c18fffe */ 	lui	$t8,0xfffe
/*  f0e42a4:	37187960 */ 	ori	$t8,$t8,0x7960
/*  f0e42a8:	3c01800a */ 	lui	$at,%hi(var8009de90)
/*  f0e42ac:	ac38de90 */ 	sw	$t8,%lo(var8009de90)($at)
/*  f0e42b0:	3c190001 */ 	lui	$t9,0x1
/*  f0e42b4:	373986a0 */ 	ori	$t9,$t9,0x86a0
/*  f0e42b8:	3c01800a */ 	lui	$at,%hi(var8009de94)
/*  f0e42bc:	ac39de94 */ 	sw	$t9,%lo(var8009de94)($at)
/*  f0e42c0:	3c01ff00 */ 	lui	$at,0xff00
/*  f0e42c4:	3421007f */ 	ori	$at,$at,0x7f
/*  f0e42c8:	0201a025 */ 	or	$s4,$s0,$at
/*  f0e42cc:	3c017f1b */ 	lui	$at,%hi(var7f1adf44)
/*  f0e42d0:	c43edf44 */ 	lwc1	$f30,%lo(var7f1adf44)($at)
/*  f0e42d4:	3c013e00 */ 	lui	$at,0x3e00
/*  f0e42d8:	4481e000 */ 	mtc1	$at,$f28
/*  f0e42dc:	3c017f1b */ 	lui	$at,%hi(var7f1adf48)
/*  f0e42e0:	c43adf48 */ 	lwc1	$f26,%lo(var7f1adf48)($at)
/*  f0e42e4:	3c014416 */ 	lui	$at,0x4416
/*  f0e42e8:	4481c000 */ 	mtc1	$at,$f24
/*  f0e42ec:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0e42f0:	00009825 */ 	or	$s3,$zero,$zero
.L0f0e42f4:
/*  f0e42f4:	44932000 */ 	mtc1	$s3,$f4
/*  f0e42f8:	c7b0009c */ 	lwc1	$f16,0x9c($sp)
/*  f0e42fc:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0e4300:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f0e4304:	461a3202 */ 	mul.s	$f8,$f6,$f26
/*  f0e4308:	00000000 */ 	nop
/*  f0e430c:	461c4282 */ 	mul.s	$f10,$f8,$f28
/*  f0e4310:	46105500 */ 	add.s	$f20,$f10,$f16
/*  f0e4314:	0c0068f7 */ 	jal	sinf
/*  f0e4318:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e431c:	46180482 */ 	mul.s	$f18,$f0,$f24
/*  f0e4320:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e4324:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e4328:	44112000 */ 	mfc1	$s1,$f4
/*  f0e432c:	0c0068f4 */ 	jal	cosf
/*  f0e4330:	00000000 */ 	nop
/*  f0e4334:	46180182 */ 	mul.s	$f6,$f0,$f24
/*  f0e4338:	461ea580 */ 	add.s	$f22,$f20,$f30
/*  f0e433c:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e4340:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0e4344:	44124000 */ 	mfc1	$s2,$f8
/*  f0e4348:	0c0068f7 */ 	jal	sinf
/*  f0e434c:	00000000 */ 	nop
/*  f0e4350:	46180282 */ 	mul.s	$f10,$f0,$f24
/*  f0e4354:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e4358:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e435c:	44108000 */ 	mfc1	$s0,$f16
/*  f0e4360:	0c0068f4 */ 	jal	cosf
/*  f0e4364:	00000000 */ 	nop
/*  f0e4368:	46180482 */ 	mul.s	$f18,$f0,$f24
/*  f0e436c:	240e0008 */ 	addiu	$t6,$zero,0x8
/*  f0e4370:	262500a0 */ 	addiu	$a1,$s1,0xa0
/*  f0e4374:	260700a0 */ 	addiu	$a3,$s0,0xa0
/*  f0e4378:	26460078 */ 	addiu	$a2,$s2,0x78
/*  f0e437c:	afae001c */ 	sw	$t6,0x1c($sp)
/*  f0e4380:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0e4384:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e4388:	afb40014 */ 	sw	$s4,0x14($sp)
/*  f0e438c:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f0e4390:	440c2000 */ 	mfc1	$t4,$f4
/*  f0e4394:	00000000 */ 	nop
/*  f0e4398:	258d0078 */ 	addiu	$t5,$t4,0x78
/*  f0e439c:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e43a0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e43a4:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0e43a8:	2a610008 */ 	slti	$at,$s3,0x8
/*  f0e43ac:	1420ffd1 */ 	bnez	$at,.L0f0e42f4
/*  f0e43b0:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0e43b4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0e43b8:	44816000 */ 	mtc1	$at,$f12
/*  f0e43bc:	0fc01ad5 */ 	jal	func0f006b54
/*  f0e43c0:	00000000 */ 	nop
/*  f0e43c4:	3c01437f */ 	lui	$at,0x437f
/*  f0e43c8:	44816000 */ 	mtc1	$at,$f12
/*  f0e43cc:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0e43d0:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e43d4:	460c0182 */ 	mul.s	$f6,$f0,$f12
/*  f0e43d8:	46066201 */ 	sub.s	$f8,$f12,$f6
/*  f0e43dc:	444ff800 */ 	cfc1	$t7,$31
/*  f0e43e0:	44d0f800 */ 	ctc1	$s0,$31
/*  f0e43e4:	00000000 */ 	nop
/*  f0e43e8:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0e43ec:	4450f800 */ 	cfc1	$s0,$31
/*  f0e43f0:	00000000 */ 	nop
/*  f0e43f4:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0e43f8:	52000013 */ 	beqzl	$s0,.L0f0e4448
/*  f0e43fc:	44105000 */ 	mfc1	$s0,$f10
/*  f0e4400:	44815000 */ 	mtc1	$at,$f10
/*  f0e4404:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f0e4408:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0e440c:	44d0f800 */ 	ctc1	$s0,$31
/*  f0e4410:	00000000 */ 	nop
/*  f0e4414:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0e4418:	4450f800 */ 	cfc1	$s0,$31
/*  f0e441c:	00000000 */ 	nop
/*  f0e4420:	32100078 */ 	andi	$s0,$s0,0x78
/*  f0e4424:	16000005 */ 	bnez	$s0,.L0f0e443c
/*  f0e4428:	00000000 */ 	nop
/*  f0e442c:	44105000 */ 	mfc1	$s0,$f10
/*  f0e4430:	3c018000 */ 	lui	$at,0x8000
/*  f0e4434:	10000007 */ 	b	.L0f0e4454
/*  f0e4438:	02018025 */ 	or	$s0,$s0,$at
.L0f0e443c:
/*  f0e443c:	10000005 */ 	b	.L0f0e4454
/*  f0e4440:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f0e4444:	44105000 */ 	mfc1	$s0,$f10
.L0f0e4448:
/*  f0e4448:	00000000 */ 	nop
/*  f0e444c:	0600fffb */ 	bltz	$s0,.L0f0e443c
/*  f0e4450:	00000000 */ 	nop
.L0f0e4454:
/*  f0e4454:	3c017f1b */ 	lui	$at,%hi(var7f1adf4c)
/*  f0e4458:	44cff800 */ 	ctc1	$t7,$31
/*  f0e445c:	c430df4c */ 	lwc1	$f16,%lo(var7f1adf4c)($at)
/*  f0e4460:	c6d20000 */ 	lwc1	$f18,0x0($s6)
/*  f0e4464:	3c01ff00 */ 	lui	$at,0xff00
/*  f0e4468:	0010c400 */ 	sll	$t8,$s0,0x10
/*  f0e446c:	46128082 */ 	mul.s	$f2,$f16,$f18
/*  f0e4470:	3421007f */ 	ori	$at,$at,0x7f
/*  f0e4474:	0301a025 */ 	or	$s4,$t8,$at
/*  f0e4478:	24160008 */ 	addiu	$s6,$zero,0x8
/*  f0e447c:	00009825 */ 	or	$s3,$zero,$zero
/*  f0e4480:	46001107 */ 	neg.s	$f4,$f2
/*  f0e4484:	e7a40078 */ 	swc1	$f4,0x78($sp)
.L0f0e4488:
/*  f0e4488:	44933000 */ 	mtc1	$s3,$f6
/*  f0e448c:	c7a80078 */ 	lwc1	$f8,0x78($sp)
/*  f0e4490:	46803020 */ 	cvt.s.w	$f0,$f6
/*  f0e4494:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f0e4498:	461a5402 */ 	mul.s	$f16,$f10,$f26
/*  f0e449c:	00000000 */ 	nop
/*  f0e44a0:	461c8482 */ 	mul.s	$f18,$f16,$f28
/*  f0e44a4:	46124500 */ 	add.s	$f20,$f8,$f18
/*  f0e44a8:	0c0068f7 */ 	jal	sinf
/*  f0e44ac:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e44b0:	46180102 */ 	mul.s	$f4,$f0,$f24
/*  f0e44b4:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e44b8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e44bc:	44113000 */ 	mfc1	$s1,$f6
/*  f0e44c0:	0c0068f4 */ 	jal	cosf
/*  f0e44c4:	00000000 */ 	nop
/*  f0e44c8:	46180282 */ 	mul.s	$f10,$f0,$f24
/*  f0e44cc:	461ea580 */ 	add.s	$f22,$f20,$f30
/*  f0e44d0:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e44d4:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e44d8:	44128000 */ 	mfc1	$s2,$f16
/*  f0e44dc:	0c0068f7 */ 	jal	sinf
/*  f0e44e0:	00000000 */ 	nop
/*  f0e44e4:	46180202 */ 	mul.s	$f8,$f0,$f24
/*  f0e44e8:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e44ec:	4600448d */ 	trunc.w.s	$f18,$f8
/*  f0e44f0:	44109000 */ 	mfc1	$s0,$f18
/*  f0e44f4:	0c0068f4 */ 	jal	cosf
/*  f0e44f8:	00000000 */ 	nop
/*  f0e44fc:	46180102 */ 	mul.s	$f4,$f0,$f24
/*  f0e4500:	240d0009 */ 	addiu	$t5,$zero,0x9
/*  f0e4504:	262500a0 */ 	addiu	$a1,$s1,0xa0
/*  f0e4508:	260700a0 */ 	addiu	$a3,$s0,0xa0
/*  f0e450c:	26460078 */ 	addiu	$a2,$s2,0x78
/*  f0e4510:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e4514:	02a02025 */ 	or	$a0,$s5,$zero
/*  f0e4518:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e451c:	afb40014 */ 	sw	$s4,0x14($sp)
/*  f0e4520:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f0e4524:	440b3000 */ 	mfc1	$t3,$f6
/*  f0e4528:	00000000 */ 	nop
/*  f0e452c:	256c0078 */ 	addiu	$t4,$t3,0x78
/*  f0e4530:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e4534:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e4538:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0e453c:	1676ffd2 */ 	bne	$s3,$s6,.L0f0e4488
/*  f0e4540:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0e4544:	0fc35320 */ 	jal	func0f0d4c80
/*  f0e4548:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e454c:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f0e4550:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f0e4554:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f0e4558:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f0e455c:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f0e4560:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f0e4564:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f0e4568:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f0e456c:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f0e4570:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0e4574:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f0e4578:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f0e457c:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f0e4580:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f0e4584:	03e00008 */ 	jr	$ra
/*  f0e4588:	27bd00a0 */ 	addiu	$sp,$sp,0xa0
/*  f0e458c:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0e4590:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e4594:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0e4598:	3c01800a */ 	lui	$at,%hi(var8009de98)
/*  f0e459c:	00808025 */ 	or	$s0,$a0,$zero
/*  f0e45a0:	0c002f06 */ 	jal	viGetY
/*  f0e45a4:	ac20de98 */ 	sw	$zero,%lo(var8009de98)($at)
/*  f0e45a8:	04410003 */ 	bgez	$v0,.L0f0e45b8
/*  f0e45ac:	00027043 */ 	sra	$t6,$v0,0x1
/*  f0e45b0:	24410001 */ 	addiu	$at,$v0,0x1
/*  f0e45b4:	00017043 */ 	sra	$t6,$at,0x1
.L0f0e45b8:
/*  f0e45b8:	240fffec */ 	addiu	$t7,$zero,-20
/*  f0e45bc:	01eec023 */ 	subu	$t8,$t7,$t6
/*  f0e45c0:	3c01800a */ 	lui	$at,%hi(var8009de9c)
/*  f0e45c4:	ac38de9c */ 	sw	$t8,%lo(var8009de9c)($at)
/*  f0e45c8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e45cc:	0fc3528f */ 	jal	func0f0d4a3c
/*  f0e45d0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e45d4:	3c19fffe */ 	lui	$t9,0xfffe
/*  f0e45d8:	37397960 */ 	ori	$t9,$t9,0x7960
/*  f0e45dc:	3c01800a */ 	lui	$at,%hi(var8009de90)
/*  f0e45e0:	ac39de90 */ 	sw	$t9,%lo(var8009de90)($at)
/*  f0e45e4:	3c080001 */ 	lui	$t0,0x1
/*  f0e45e8:	350886a0 */ 	ori	$t0,$t0,0x86a0
/*  f0e45ec:	3c01800a */ 	lui	$at,%hi(var8009de94)
/*  f0e45f0:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e45f4:	0c002f06 */ 	jal	viGetY
/*  f0e45f8:	ac28de94 */ 	sw	$t0,%lo(var8009de94)($at)
/*  f0e45fc:	0c002f06 */ 	jal	viGetY
/*  f0e4600:	a7a20034 */ 	sh	$v0,0x34($sp)
/*  f0e4604:	87a60034 */ 	lh	$a2,0x34($sp)
/*  f0e4608:	3c0300ff */ 	lui	$v1,0xff
/*  f0e460c:	346300bf */ 	ori	$v1,$v1,0xbf
/*  f0e4610:	2449000a */ 	addiu	$t1,$v0,0xa
/*  f0e4614:	240a0006 */ 	addiu	$t2,$zero,0x6
/*  f0e4618:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0e461c:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0e4620:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e4624:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e4628:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e462c:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e4630:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e4634:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e4638:	24c6000a */ 	addiu	$a2,$a2,0xa
/*  f0e463c:	0c002f06 */ 	jal	viGetY
/*  f0e4640:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e4644:	0c002f06 */ 	jal	viGetY
/*  f0e4648:	a7a20034 */ 	sh	$v0,0x34($sp)
/*  f0e464c:	87a60034 */ 	lh	$a2,0x34($sp)
/*  f0e4650:	3c03ffff */ 	lui	$v1,0xffff
/*  f0e4654:	346300af */ 	ori	$v1,$v1,0xaf
/*  f0e4658:	244b000a */ 	addiu	$t3,$v0,0xa
/*  f0e465c:	240c0005 */ 	addiu	$t4,$zero,0x5
/*  f0e4660:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0e4664:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f0e4668:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e466c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e4670:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e4674:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e4678:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e467c:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e4680:	24c6000a */ 	addiu	$a2,$a2,0xa
/*  f0e4684:	0fc35320 */ 	jal	func0f0d4c80
/*  f0e4688:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e468c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0e4690:	3c03800a */ 	lui	$v1,%hi(var8009de9c)
/*  f0e4694:	2463de9c */ 	addiu	$v1,$v1,%lo(var8009de9c)
/*  f0e4698:	ac600000 */ 	sw	$zero,0x0($v1)
/*  f0e469c:	3c01800a */ 	lui	$at,%hi(var8009de98)
/*  f0e46a0:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0e46a4:	ac20de98 */ 	sw	$zero,%lo(var8009de98)($at)
/*  f0e46a8:	03e00008 */ 	jr	$ra
/*  f0e46ac:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0e46b0:	3c0e800a */ 	lui	$t6,%hi(var8009de9c)
/*  f0e46b4:	8dcede9c */ 	lw	$t6,%lo(var8009de9c)($t6)
/*  f0e46b8:	44803000 */ 	mtc1	$zero,$f6
/*  f0e46bc:	3c014370 */ 	lui	$at,0x4370
/*  f0e46c0:	25cf0078 */ 	addiu	$t7,$t6,0x78
/*  f0e46c4:	448f2000 */ 	mtc1	$t7,$f4
/*  f0e46c8:	44856000 */ 	mtc1	$a1,$f12
/*  f0e46cc:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f0e46d0:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0e46d4:	44812000 */ 	mtc1	$at,$f4
/*  f0e46d8:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0e46dc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f0e46e0:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e46e4:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f0e46e8:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0e46ec:	46086282 */ 	mul.s	$f10,$f12,$f8
/*  f0e46f0:	00000000 */ 	nop
/*  f0e46f4:	46066202 */ 	mul.s	$f8,$f12,$f6
/*  f0e46f8:	460a0400 */ 	add.s	$f16,$f0,$f10
/*  f0e46fc:	46080280 */ 	add.s	$f10,$f0,$f8
/*  f0e4700:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e4704:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e4708:	44069000 */ 	mfc1	$a2,$f18
/*  f0e470c:	44108000 */ 	mfc1	$s0,$f16
/*  f0e4710:	0fc3528f */ 	jal	func0f0d4a3c
/*  f0e4714:	afa60034 */ 	sw	$a2,0x34($sp)
/*  f0e4718:	3c08fffe */ 	lui	$t0,0xfffe
/*  f0e471c:	35087960 */ 	ori	$t0,$t0,0x7960
/*  f0e4720:	3c01800a */ 	lui	$at,%hi(var8009de90)
/*  f0e4724:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f0e4728:	3c03ffff */ 	lui	$v1,0xffff
/*  f0e472c:	ac28de90 */ 	sw	$t0,%lo(var8009de90)($at)
/*  f0e4730:	3c090001 */ 	lui	$t1,0x1
/*  f0e4734:	3463007f */ 	ori	$v1,$v1,0x7f
/*  f0e4738:	352986a0 */ 	ori	$t1,$t1,0x86a0
/*  f0e473c:	3c01800a */ 	lui	$at,%hi(var8009de94)
/*  f0e4740:	240a0005 */ 	addiu	$t2,$zero,0x5
/*  f0e4744:	ac29de94 */ 	sw	$t1,%lo(var8009de94)($at)
/*  f0e4748:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0e474c:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e4750:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e4754:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e4758:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e475c:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e4760:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e4764:	afa60010 */ 	sw	$a2,0x10($sp)
/*  f0e4768:	8fa60034 */ 	lw	$a2,0x34($sp)
/*  f0e476c:	3c0300aa */ 	lui	$v1,0xaa
/*  f0e4770:	3463007f */ 	ori	$v1,$v1,0x7f
/*  f0e4774:	240b0006 */ 	addiu	$t3,$zero,0x6
/*  f0e4778:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0e477c:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e4780:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e4784:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e4788:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e478c:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e4790:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e4794:	afa60010 */ 	sw	$a2,0x10($sp)
/*  f0e4798:	3c03ffff */ 	lui	$v1,0xffff
/*  f0e479c:	3463007f */ 	ori	$v1,$v1,0x7f
/*  f0e47a0:	240c0005 */ 	addiu	$t4,$zero,0x5
/*  f0e47a4:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0e47a8:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e47ac:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e47b0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e47b4:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e47b8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e47bc:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e47c0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e47c4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0e47c8:	3c0300aa */ 	lui	$v1,0xaa
/*  f0e47cc:	3463007f */ 	ori	$v1,$v1,0x7f
/*  f0e47d0:	240d0006 */ 	addiu	$t5,$zero,0x6
/*  f0e47d4:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e47d8:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e47dc:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e47e0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e47e4:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e47e8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e47ec:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e47f0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e47f4:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0e47f8:	0fc35320 */ 	jal	func0f0d4c80
/*  f0e47fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e4800:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f0e4804:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f0e4808:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f0e480c:	03e00008 */ 	jr	$ra
/*  f0e4810:	00000000 */ 	nop
/*  f0e4814:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f0e4818:	3c017f1b */ 	lui	$at,%hi(var7f1adf50)
/*  f0e481c:	c424df50 */ 	lwc1	$f4,%lo(var7f1adf50)($at)
/*  f0e4820:	3c018006 */ 	lui	$at,%hi(var80061630)
/*  f0e4824:	c4261630 */ 	lwc1	$f6,%lo(var80061630)($at)
/*  f0e4828:	3c02800a */ 	lui	$v0,%hi(var8009de9c)
/*  f0e482c:	2442de9c */ 	addiu	$v0,$v0,%lo(var8009de9c)
/*  f0e4830:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e4834:	afbf007c */ 	sw	$ra,0x7c($sp)
/*  f0e4838:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f0e483c:	3c01800a */ 	lui	$at,%hi(var8009de98)
/*  f0e4840:	afbe0078 */ 	sw	$s8,0x78($sp)
/*  f0e4844:	afb70074 */ 	sw	$s7,0x74($sp)
/*  f0e4848:	afb60070 */ 	sw	$s6,0x70($sp)
/*  f0e484c:	afb5006c */ 	sw	$s5,0x6c($sp)
/*  f0e4850:	afb40068 */ 	sw	$s4,0x68($sp)
/*  f0e4854:	afb30064 */ 	sw	$s3,0x64($sp)
/*  f0e4858:	afb20060 */ 	sw	$s2,0x60($sp)
/*  f0e485c:	afb1005c */ 	sw	$s1,0x5c($sp)
/*  f0e4860:	afb00058 */ 	sw	$s0,0x58($sp)
/*  f0e4864:	f7be0050 */ 	sdc1	$f30,0x50($sp)
/*  f0e4868:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f0e486c:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f0e4870:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f0e4874:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f0e4878:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f0e487c:	e7a800b4 */ 	swc1	$f8,0xb4($sp)
/*  f0e4880:	ac20de98 */ 	sw	$zero,%lo(var8009de98)($at)
/*  f0e4884:	0fc3528f */ 	jal	func0f0d4a3c
/*  f0e4888:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e488c:	3c0ffffe */ 	lui	$t7,0xfffe
/*  f0e4890:	35ef7960 */ 	ori	$t7,$t7,0x7960
/*  f0e4894:	3c01800a */ 	lui	$at,%hi(var8009de90)
/*  f0e4898:	ac2fde90 */ 	sw	$t7,%lo(var8009de90)($at)
/*  f0e489c:	3c180001 */ 	lui	$t8,0x1
/*  f0e48a0:	371886a0 */ 	ori	$t8,$t8,0x86a0
/*  f0e48a4:	3c01800a */ 	lui	$at,%hi(var8009de94)
/*  f0e48a8:	24197f7f */ 	addiu	$t9,$zero,0x7f7f
/*  f0e48ac:	24087f7f */ 	addiu	$t0,$zero,0x7f7f
/*  f0e48b0:	24090004 */ 	addiu	$t1,$zero,0x4
/*  f0e48b4:	ac38de94 */ 	sw	$t8,%lo(var8009de94)($at)
/*  f0e48b8:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0e48bc:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0e48c0:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0e48c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e48c8:	2405d8f0 */ 	addiu	$a1,$zero,-10000
/*  f0e48cc:	00003025 */ 	or	$a2,$zero,$zero
/*  f0e48d0:	24072710 */ 	addiu	$a3,$zero,0x2710
/*  f0e48d4:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e48d8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0e48dc:	240a012c */ 	addiu	$t2,$zero,0x12c
/*  f0e48e0:	240b7f7f */ 	addiu	$t3,$zero,0x7f7f
/*  f0e48e4:	240c7f7f */ 	addiu	$t4,$zero,0x7f7f
/*  f0e48e8:	240d0004 */ 	addiu	$t5,$zero,0x4
/*  f0e48ec:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e48f0:	afac0018 */ 	sw	$t4,0x18($sp)
/*  f0e48f4:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0e48f8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0e48fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e4900:	2405d8f0 */ 	addiu	$a1,$zero,-10000
/*  f0e4904:	2406012c */ 	addiu	$a2,$zero,0x12c
/*  f0e4908:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e490c:	24072710 */ 	addiu	$a3,$zero,0x2710
/*  f0e4910:	3c01c000 */ 	lui	$at,0xc000
/*  f0e4914:	c7a200b4 */ 	lwc1	$f2,0xb4($sp)
/*  f0e4918:	44815000 */ 	mtc1	$at,$f10
/*  f0e491c:	3c014080 */ 	lui	$at,0x4080
/*  f0e4920:	4481f000 */ 	mtc1	$at,$f30
/*  f0e4924:	46025402 */ 	mul.s	$f16,$f10,$f2
/*  f0e4928:	3c014416 */ 	lui	$at,0x4416
/*  f0e492c:	4481c000 */ 	mtc1	$at,$f24
/*  f0e4930:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f0e4934:	afa000b0 */ 	sw	$zero,0xb0($sp)
/*  f0e4938:	e7b00080 */ 	swc1	$f16,0x80($sp)
.L0f0e493c:
/*  f0e493c:	8fa300b0 */ 	lw	$v1,0xb0($sp)
/*  f0e4940:	3c017f1b */ 	lui	$at,%hi(var7f1adf54)
/*  f0e4944:	c426df54 */ 	lwc1	$f6,%lo(var7f1adf54)($at)
/*  f0e4948:	44839000 */ 	mtc1	$v1,$f18
/*  f0e494c:	3c014040 */ 	lui	$at,0x4040
/*  f0e4950:	44815000 */ 	mtc1	$at,$f10
/*  f0e4954:	46809020 */ 	cvt.s.w	$f0,$f18
/*  f0e4958:	c7a200b4 */ 	lwc1	$f2,0xb4($sp)
/*  f0e495c:	46000100 */ 	add.s	$f4,$f0,$f0
/*  f0e4960:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e4964:	460a4703 */ 	div.s	$f28,$f8,$f10
/*  f0e4968:	4602e580 */ 	add.s	$f22,$f28,$f2
/*  f0e496c:	0c0068f7 */ 	jal	sinf
/*  f0e4970:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e4974:	46180402 */ 	mul.s	$f16,$f0,$f24
/*  f0e4978:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e497c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e4980:	44169000 */ 	mfc1	$s6,$f18
/*  f0e4984:	0c0068f4 */ 	jal	cosf
/*  f0e4988:	00000000 */ 	nop
/*  f0e498c:	46180102 */ 	mul.s	$f4,$f0,$f24
/*  f0e4990:	3c017f1b */ 	lui	$at,%hi(var7f1adf58)
/*  f0e4994:	c428df58 */ 	lwc1	$f8,%lo(var7f1adf58)($at)
/*  f0e4998:	4608b500 */ 	add.s	$f20,$f22,$f8
/*  f0e499c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e49a0:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e49a4:	44133000 */ 	mfc1	$s3,$f6
/*  f0e49a8:	0c0068f7 */ 	jal	sinf
/*  f0e49ac:	00000000 */ 	nop
/*  f0e49b0:	46180282 */ 	mul.s	$f10,$f0,$f24
/*  f0e49b4:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e49b8:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e49bc:	44128000 */ 	mfc1	$s2,$f16
/*  f0e49c0:	0c0068f4 */ 	jal	cosf
/*  f0e49c4:	00000000 */ 	nop
/*  f0e49c8:	46180482 */ 	mul.s	$f18,$f0,$f24
/*  f0e49cc:	3c017f1b */ 	lui	$at,%hi(var7f1adf5c)
/*  f0e49d0:	c426df5c */ 	lwc1	$f6,%lo(var7f1adf5c)($at)
/*  f0e49d4:	4606a500 */ 	add.s	$f20,$f20,$f6
/*  f0e49d8:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e49dc:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e49e0:	44102000 */ 	mfc1	$s0,$f4
/*  f0e49e4:	0c0068f7 */ 	jal	sinf
/*  f0e49e8:	00000000 */ 	nop
/*  f0e49ec:	46180202 */ 	mul.s	$f8,$f0,$f24
/*  f0e49f0:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e49f4:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e49f8:	44115000 */ 	mfc1	$s1,$f10
/*  f0e49fc:	0c0068f4 */ 	jal	cosf
/*  f0e4a00:	00000000 */ 	nop
/*  f0e4a04:	46180402 */ 	mul.s	$f16,$f0,$f24
/*  f0e4a08:	3c0aff00 */ 	lui	$t2,0xff00
/*  f0e4a0c:	3c0bff00 */ 	lui	$t3,0xff00
/*  f0e4a10:	265200a0 */ 	addiu	$s2,$s2,0xa0
/*  f0e4a14:	26100078 */ 	addiu	$s0,$s0,0x78
/*  f0e4a18:	356b007f */ 	ori	$t3,$t3,0x7f
/*  f0e4a1c:	354a0040 */ 	ori	$t2,$t2,0x40
/*  f0e4a20:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e4a24:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f0e4a28:	26c500a0 */ 	addiu	$a1,$s6,0xa0
/*  f0e4a2c:	263100a0 */ 	addiu	$s1,$s1,0xa0
/*  f0e4a30:	44179000 */ 	mfc1	$s7,$f18
/*  f0e4a34:	26660078 */ 	addiu	$a2,$s3,0x78
/*  f0e4a38:	afac001c */ 	sw	$t4,0x1c($sp)
/*  f0e4a3c:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0e4a40:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f0e4a44:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0e4a48:	02403825 */ 	or	$a3,$s2,$zero
/*  f0e4a4c:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*  f0e4a50:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e4a54:	26f70078 */ 	addiu	$s7,$s7,0x78
/*  f0e4a58:	3c0dff00 */ 	lui	$t5,0xff00
/*  f0e4a5c:	3c0eff00 */ 	lui	$t6,0xff00
/*  f0e4a60:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f0e4a64:	35ad007f */ 	ori	$t5,$t5,0x7f
/*  f0e4a68:	240f0003 */ 	addiu	$t7,$zero,0x3
/*  f0e4a6c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0e4a70:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0e4a74:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0e4a78:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e4a7c:	02402825 */ 	or	$a1,$s2,$zero
/*  f0e4a80:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e4a84:	02203825 */ 	or	$a3,$s1,$zero
/*  f0e4a88:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e4a8c:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0e4a90:	c7a40080 */ 	lwc1	$f4,0x80($sp)
/*  f0e4a94:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f0e4a98:	461c2680 */ 	add.s	$f26,$f4,$f28
/*  f0e4a9c:	0c0068f7 */ 	jal	sinf
/*  f0e4aa0:	4600d306 */ 	mov.s	$f12,$f26
/*  f0e4aa4:	46180182 */ 	mul.s	$f6,$f0,$f24
/*  f0e4aa8:	4600d306 */ 	mov.s	$f12,$f26
/*  f0e4aac:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0e4ab0:	44164000 */ 	mfc1	$s6,$f8
/*  f0e4ab4:	0c0068f4 */ 	jal	cosf
/*  f0e4ab8:	00000000 */ 	nop
/*  f0e4abc:	46180282 */ 	mul.s	$f10,$f0,$f24
/*  f0e4ac0:	3c017f1b */ 	lui	$at,%hi(var7f1adf60)
/*  f0e4ac4:	c432df60 */ 	lwc1	$f18,%lo(var7f1adf60)($at)
/*  f0e4ac8:	4612d500 */ 	add.s	$f20,$f26,$f18
/*  f0e4acc:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e4ad0:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e4ad4:	44138000 */ 	mfc1	$s3,$f16
/*  f0e4ad8:	0c0068f7 */ 	jal	sinf
/*  f0e4adc:	00000000 */ 	nop
/*  f0e4ae0:	46180102 */ 	mul.s	$f4,$f0,$f24
/*  f0e4ae4:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e4ae8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e4aec:	44123000 */ 	mfc1	$s2,$f6
/*  f0e4af0:	0c0068f4 */ 	jal	cosf
/*  f0e4af4:	00000000 */ 	nop
/*  f0e4af8:	46180202 */ 	mul.s	$f8,$f0,$f24
/*  f0e4afc:	3c017f1b */ 	lui	$at,%hi(var7f1adf64)
/*  f0e4b00:	c430df64 */ 	lwc1	$f16,%lo(var7f1adf64)($at)
/*  f0e4b04:	4610a500 */ 	add.s	$f20,$f20,$f16
/*  f0e4b08:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e4b0c:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e4b10:	44105000 */ 	mfc1	$s0,$f10
/*  f0e4b14:	0c0068f7 */ 	jal	sinf
/*  f0e4b18:	00000000 */ 	nop
/*  f0e4b1c:	46180482 */ 	mul.s	$f18,$f0,$f24
/*  f0e4b20:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e4b24:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e4b28:	44112000 */ 	mfc1	$s1,$f4
/*  f0e4b2c:	0c0068f4 */ 	jal	cosf
/*  f0e4b30:	00000000 */ 	nop
/*  f0e4b34:	46180182 */ 	mul.s	$f6,$f0,$f24
/*  f0e4b38:	26d600a0 */ 	addiu	$s6,$s6,0xa0
/*  f0e4b3c:	265200a0 */ 	addiu	$s2,$s2,0xa0
/*  f0e4b40:	263100a0 */ 	addiu	$s1,$s1,0xa0
/*  f0e4b44:	26730078 */ 	addiu	$s3,$s3,0x78
/*  f0e4b48:	26100078 */ 	addiu	$s0,$s0,0x78
/*  f0e4b4c:	4600f306 */ 	mov.s	$f12,$f30
/*  f0e4b50:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0e4b54:	44174000 */ 	mfc1	$s7,$f8
/*  f0e4b58:	0fc01ad5 */ 	jal	func0f006b54
/*  f0e4b5c:	26f70078 */ 	addiu	$s7,$s7,0x78
/*  f0e4b60:	3c0142fe */ 	lui	$at,0x42fe
/*  f0e4b64:	44815000 */ 	mtc1	$at,$f10
/*  f0e4b68:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0e4b6c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e4b70:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f0e4b74:	444cf800 */ 	cfc1	$t4,$31
/*  f0e4b78:	44d4f800 */ 	ctc1	$s4,$31
/*  f0e4b7c:	00000000 */ 	nop
/*  f0e4b80:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f0e4b84:	4454f800 */ 	cfc1	$s4,$31
/*  f0e4b88:	00000000 */ 	nop
/*  f0e4b8c:	32940078 */ 	andi	$s4,$s4,0x78
/*  f0e4b90:	52800013 */ 	beqzl	$s4,.L0f0e4be0
/*  f0e4b94:	44149000 */ 	mfc1	$s4,$f18
/*  f0e4b98:	44819000 */ 	mtc1	$at,$f18
/*  f0e4b9c:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0e4ba0:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f0e4ba4:	44d4f800 */ 	ctc1	$s4,$31
/*  f0e4ba8:	00000000 */ 	nop
/*  f0e4bac:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f0e4bb0:	4454f800 */ 	cfc1	$s4,$31
/*  f0e4bb4:	00000000 */ 	nop
/*  f0e4bb8:	32940078 */ 	andi	$s4,$s4,0x78
/*  f0e4bbc:	16800005 */ 	bnez	$s4,.L0f0e4bd4
/*  f0e4bc0:	00000000 */ 	nop
/*  f0e4bc4:	44149000 */ 	mfc1	$s4,$f18
/*  f0e4bc8:	3c018000 */ 	lui	$at,0x8000
/*  f0e4bcc:	10000007 */ 	b	.L0f0e4bec
/*  f0e4bd0:	0281a025 */ 	or	$s4,$s4,$at
.L0f0e4bd4:
/*  f0e4bd4:	10000005 */ 	b	.L0f0e4bec
/*  f0e4bd8:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f0e4bdc:	44149000 */ 	mfc1	$s4,$f18
.L0f0e4be0:
/*  f0e4be0:	00000000 */ 	nop
/*  f0e4be4:	0680fffb */ 	bltz	$s4,.L0f0e4bd4
/*  f0e4be8:	00000000 */ 	nop
.L0f0e4bec:
/*  f0e4bec:	44ccf800 */ 	ctc1	$t4,$31
/*  f0e4bf0:	0fc01ad5 */ 	jal	func0f006b54
/*  f0e4bf4:	4600f306 */ 	mov.s	$f12,$f30
/*  f0e4bf8:	3c01425c */ 	lui	$at,0x425c
/*  f0e4bfc:	44812000 */ 	mtc1	$at,$f4
/*  f0e4c00:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0e4c04:	3c03ffff */ 	lui	$v1,0xffff
/*  f0e4c08:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f0e4c0c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e4c10:	0074f025 */ 	or	$s8,$v1,$s4
/*  f0e4c14:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*  f0e4c18:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e4c1c:	02603025 */ 	or	$a2,$s3,$zero
/*  f0e4c20:	02403825 */ 	or	$a3,$s2,$zero
/*  f0e4c24:	444df800 */ 	cfc1	$t5,$31
/*  f0e4c28:	44c2f800 */ 	ctc1	$v0,$31
/*  f0e4c2c:	240f0002 */ 	addiu	$t7,$zero,0x2
/*  f0e4c30:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0e4c34:	4442f800 */ 	cfc1	$v0,$31
/*  f0e4c38:	00000000 */ 	nop
/*  f0e4c3c:	30420078 */ 	andi	$v0,$v0,0x78
/*  f0e4c40:	50400013 */ 	beqzl	$v0,.L0f0e4c90
/*  f0e4c44:	44024000 */ 	mfc1	$v0,$f8
/*  f0e4c48:	44814000 */ 	mtc1	$at,$f8
/*  f0e4c4c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0e4c50:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0e4c54:	44c2f800 */ 	ctc1	$v0,$31
/*  f0e4c58:	00000000 */ 	nop
/*  f0e4c5c:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0e4c60:	4442f800 */ 	cfc1	$v0,$31
/*  f0e4c64:	00000000 */ 	nop
/*  f0e4c68:	30420078 */ 	andi	$v0,$v0,0x78
/*  f0e4c6c:	14400005 */ 	bnez	$v0,.L0f0e4c84
/*  f0e4c70:	00000000 */ 	nop
/*  f0e4c74:	44024000 */ 	mfc1	$v0,$f8
/*  f0e4c78:	3c018000 */ 	lui	$at,0x8000
/*  f0e4c7c:	10000007 */ 	b	.L0f0e4c9c
/*  f0e4c80:	00411025 */ 	or	$v0,$v0,$at
.L0f0e4c84:
/*  f0e4c84:	10000005 */ 	b	.L0f0e4c9c
/*  f0e4c88:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0e4c8c:	44024000 */ 	mfc1	$v0,$f8
.L0f0e4c90:
/*  f0e4c90:	00000000 */ 	nop
/*  f0e4c94:	0440fffb */ 	bltz	$v0,.L0f0e4c84
/*  f0e4c98:	00000000 */ 	nop
.L0f0e4c9c:
/*  f0e4c9c:	44cdf800 */ 	ctc1	$t5,$31
/*  f0e4ca0:	00627025 */ 	or	$t6,$v1,$v0
/*  f0e4ca4:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0e4ca8:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0e4cac:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0e4cb0:	afbe0018 */ 	sw	$s8,0x18($sp)
/*  f0e4cb4:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e4cb8:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0e4cbc:	3c01ffff */ 	lui	$at,0xffff
/*  f0e4cc0:	02a1c025 */ 	or	$t8,$s5,$at
/*  f0e4cc4:	24190003 */ 	addiu	$t9,$zero,0x3
/*  f0e4cc8:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e4ccc:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0e4cd0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e4cd4:	02402825 */ 	or	$a1,$s2,$zero
/*  f0e4cd8:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e4cdc:	02203825 */ 	or	$a3,$s1,$zero
/*  f0e4ce0:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0e4ce4:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e4ce8:	afbe0014 */ 	sw	$s8,0x14($sp)
/*  f0e4cec:	3c017f1b */ 	lui	$at,%hi(var7f1adf68)
/*  f0e4cf0:	c42adf68 */ 	lwc1	$f10,%lo(var7f1adf68)($at)
/*  f0e4cf4:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f0e4cf8:	460ad580 */ 	add.s	$f22,$f26,$f10
/*  f0e4cfc:	0c0068f7 */ 	jal	sinf
/*  f0e4d00:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e4d04:	46180402 */ 	mul.s	$f16,$f0,$f24
/*  f0e4d08:	4600b306 */ 	mov.s	$f12,$f22
/*  f0e4d0c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e4d10:	44169000 */ 	mfc1	$s6,$f18
/*  f0e4d14:	0c0068f4 */ 	jal	cosf
/*  f0e4d18:	00000000 */ 	nop
/*  f0e4d1c:	46180102 */ 	mul.s	$f4,$f0,$f24
/*  f0e4d20:	3c017f1b */ 	lui	$at,%hi(var7f1adf6c)
/*  f0e4d24:	c428df6c */ 	lwc1	$f8,%lo(var7f1adf6c)($at)
/*  f0e4d28:	4608b500 */ 	add.s	$f20,$f22,$f8
/*  f0e4d2c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0e4d30:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e4d34:	44133000 */ 	mfc1	$s3,$f6
/*  f0e4d38:	0c0068f7 */ 	jal	sinf
/*  f0e4d3c:	00000000 */ 	nop
/*  f0e4d40:	46180282 */ 	mul.s	$f10,$f0,$f24
/*  f0e4d44:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e4d48:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0e4d4c:	44128000 */ 	mfc1	$s2,$f16
/*  f0e4d50:	0c0068f4 */ 	jal	cosf
/*  f0e4d54:	00000000 */ 	nop
/*  f0e4d58:	46180482 */ 	mul.s	$f18,$f0,$f24
/*  f0e4d5c:	3c017f1b */ 	lui	$at,%hi(var7f1adf70)
/*  f0e4d60:	c426df70 */ 	lwc1	$f6,%lo(var7f1adf70)($at)
/*  f0e4d64:	4606a500 */ 	add.s	$f20,$f20,$f6
/*  f0e4d68:	4600910d */ 	trunc.w.s	$f4,$f18
/*  f0e4d6c:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e4d70:	44102000 */ 	mfc1	$s0,$f4
/*  f0e4d74:	0c0068f7 */ 	jal	sinf
/*  f0e4d78:	00000000 */ 	nop
/*  f0e4d7c:	46180202 */ 	mul.s	$f8,$f0,$f24
/*  f0e4d80:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e4d84:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e4d88:	44115000 */ 	mfc1	$s1,$f10
/*  f0e4d8c:	0c0068f4 */ 	jal	cosf
/*  f0e4d90:	00000000 */ 	nop
/*  f0e4d94:	46180402 */ 	mul.s	$f16,$f0,$f24
/*  f0e4d98:	26d600a0 */ 	addiu	$s6,$s6,0xa0
/*  f0e4d9c:	265200a0 */ 	addiu	$s2,$s2,0xa0
/*  f0e4da0:	263100a0 */ 	addiu	$s1,$s1,0xa0
/*  f0e4da4:	26730078 */ 	addiu	$s3,$s3,0x78
/*  f0e4da8:	26100078 */ 	addiu	$s0,$s0,0x78
/*  f0e4dac:	4600f306 */ 	mov.s	$f12,$f30
/*  f0e4db0:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0e4db4:	44179000 */ 	mfc1	$s7,$f18
/*  f0e4db8:	0fc01ad5 */ 	jal	func0f006b54
/*  f0e4dbc:	26f70078 */ 	addiu	$s7,$s7,0x78
/*  f0e4dc0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0e4dc4:	44812000 */ 	mtc1	$at,$f4
/*  f0e4dc8:	3c0142c6 */ 	lui	$at,0x42c6
/*  f0e4dcc:	44814000 */ 	mtc1	$at,$f8
/*  f0e4dd0:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f0e4dd4:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0e4dd8:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e4ddc:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0e4de0:	444ef800 */ 	cfc1	$t6,$31
/*  f0e4de4:	44d4f800 */ 	ctc1	$s4,$31
/*  f0e4de8:	00000000 */ 	nop
/*  f0e4dec:	46005424 */ 	cvt.w.s	$f16,$f10
/*  f0e4df0:	4454f800 */ 	cfc1	$s4,$31
/*  f0e4df4:	00000000 */ 	nop
/*  f0e4df8:	32940078 */ 	andi	$s4,$s4,0x78
/*  f0e4dfc:	52800013 */ 	beqzl	$s4,.L0f0e4e4c
/*  f0e4e00:	44148000 */ 	mfc1	$s4,$f16
/*  f0e4e04:	44818000 */ 	mtc1	$at,$f16
/*  f0e4e08:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f0e4e0c:	46105401 */ 	sub.s	$f16,$f10,$f16
/*  f0e4e10:	44d4f800 */ 	ctc1	$s4,$31
/*  f0e4e14:	00000000 */ 	nop
/*  f0e4e18:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f0e4e1c:	4454f800 */ 	cfc1	$s4,$31
/*  f0e4e20:	00000000 */ 	nop
/*  f0e4e24:	32940078 */ 	andi	$s4,$s4,0x78
/*  f0e4e28:	16800005 */ 	bnez	$s4,.L0f0e4e40
/*  f0e4e2c:	00000000 */ 	nop
/*  f0e4e30:	44148000 */ 	mfc1	$s4,$f16
/*  f0e4e34:	3c018000 */ 	lui	$at,0x8000
/*  f0e4e38:	10000007 */ 	b	.L0f0e4e58
/*  f0e4e3c:	0281a025 */ 	or	$s4,$s4,$at
.L0f0e4e40:
/*  f0e4e40:	10000005 */ 	b	.L0f0e4e58
/*  f0e4e44:	2414ffff */ 	addiu	$s4,$zero,-1
/*  f0e4e48:	44148000 */ 	mfc1	$s4,$f16
.L0f0e4e4c:
/*  f0e4e4c:	00000000 */ 	nop
/*  f0e4e50:	0680fffb */ 	bltz	$s4,.L0f0e4e40
/*  f0e4e54:	00000000 */ 	nop
.L0f0e4e58:
/*  f0e4e58:	44cef800 */ 	ctc1	$t6,$31
/*  f0e4e5c:	0fc01ad5 */ 	jal	func0f006b54
/*  f0e4e60:	4600f306 */ 	mov.s	$f12,$f30
/*  f0e4e64:	3c013f80 */ 	lui	$at,0x3f80
/*  f0e4e68:	44819000 */ 	mtc1	$at,$f18
/*  f0e4e6c:	3c014204 */ 	lui	$at,0x4204
/*  f0e4e70:	44813000 */ 	mtc1	$at,$f6
/*  f0e4e74:	46009101 */ 	sub.s	$f4,$f18,$f0
/*  f0e4e78:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0e4e7c:	2403ff00 */ 	addiu	$v1,$zero,-256
/*  f0e4e80:	3c014f00 */ 	lui	$at,0x4f00
/*  f0e4e84:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e4e88:	0074f025 */ 	or	$s8,$v1,$s4
/*  f0e4e8c:	8fa400b8 */ 	lw	$a0,0xb8($sp)
/*  f0e4e90:	02c02825 */ 	or	$a1,$s6,$zero
/*  f0e4e94:	02603025 */ 	or	$a2,$s3,$zero
/*  f0e4e98:	02403825 */ 	or	$a3,$s2,$zero
/*  f0e4e9c:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f0e4ea0:	444ff800 */ 	cfc1	$t7,$31
/*  f0e4ea4:	44c2f800 */ 	ctc1	$v0,$31
/*  f0e4ea8:	00000000 */ 	nop
/*  f0e4eac:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0e4eb0:	4442f800 */ 	cfc1	$v0,$31
/*  f0e4eb4:	00000000 */ 	nop
/*  f0e4eb8:	30420078 */ 	andi	$v0,$v0,0x78
/*  f0e4ebc:	50400013 */ 	beqzl	$v0,.L0f0e4f0c
/*  f0e4ec0:	44025000 */ 	mfc1	$v0,$f10
/*  f0e4ec4:	44815000 */ 	mtc1	$at,$f10
/*  f0e4ec8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0e4ecc:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0e4ed0:	44c2f800 */ 	ctc1	$v0,$31
/*  f0e4ed4:	00000000 */ 	nop
/*  f0e4ed8:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0e4edc:	4442f800 */ 	cfc1	$v0,$31
/*  f0e4ee0:	00000000 */ 	nop
/*  f0e4ee4:	30420078 */ 	andi	$v0,$v0,0x78
/*  f0e4ee8:	14400005 */ 	bnez	$v0,.L0f0e4f00
/*  f0e4eec:	00000000 */ 	nop
/*  f0e4ef0:	44025000 */ 	mfc1	$v0,$f10
/*  f0e4ef4:	3c018000 */ 	lui	$at,0x8000
/*  f0e4ef8:	10000007 */ 	b	.L0f0e4f18
/*  f0e4efc:	00411025 */ 	or	$v0,$v0,$at
.L0f0e4f00:
/*  f0e4f00:	10000005 */ 	b	.L0f0e4f18
/*  f0e4f04:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f0e4f08:	44025000 */ 	mfc1	$v0,$f10
.L0f0e4f0c:
/*  f0e4f0c:	00000000 */ 	nop
/*  f0e4f10:	0440fffb */ 	bltz	$v0,.L0f0e4f00
/*  f0e4f14:	00000000 */ 	nop
.L0f0e4f18:
/*  f0e4f18:	44cff800 */ 	ctc1	$t7,$31
/*  f0e4f1c:	0062c025 */ 	or	$t8,$v1,$v0
/*  f0e4f20:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0e4f24:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0e4f28:	afb00010 */ 	sw	$s0,0x10($sp)
/*  f0e4f2c:	afbe0018 */ 	sw	$s8,0x18($sp)
/*  f0e4f30:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e4f34:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f0e4f38:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f0e4f3c:	02a14025 */ 	or	$t0,$s5,$at
/*  f0e4f40:	24090003 */ 	addiu	$t1,$zero,0x3
/*  f0e4f44:	afa9001c */ 	sw	$t1,0x1c($sp)
/*  f0e4f48:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f0e4f4c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e4f50:	02402825 */ 	or	$a1,$s2,$zero
/*  f0e4f54:	02003025 */ 	or	$a2,$s0,$zero
/*  f0e4f58:	02203825 */ 	or	$a3,$s1,$zero
/*  f0e4f5c:	afb70010 */ 	sw	$s7,0x10($sp)
/*  f0e4f60:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e4f64:	afbe0014 */ 	sw	$s8,0x14($sp)
/*  f0e4f68:	8fa300b0 */ 	lw	$v1,0xb0($sp)
/*  f0e4f6c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0e4f70:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f0e4f74:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e4f78:	afa300b0 */ 	sw	$v1,0xb0($sp)
/*  f0e4f7c:	1461fe6f */ 	bne	$v1,$at,.L0f0e493c
/*  f0e4f80:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e4f84:	0fc35320 */ 	jal	func0f0d4c80
/*  f0e4f88:	00000000 */ 	nop
/*  f0e4f8c:	8fbf007c */ 	lw	$ra,0x7c($sp)
/*  f0e4f90:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f0e4f94:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f0e4f98:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f0e4f9c:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f0e4fa0:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f0e4fa4:	d7be0050 */ 	ldc1	$f30,0x50($sp)
/*  f0e4fa8:	8fb00058 */ 	lw	$s0,0x58($sp)
/*  f0e4fac:	8fb1005c */ 	lw	$s1,0x5c($sp)
/*  f0e4fb0:	8fb20060 */ 	lw	$s2,0x60($sp)
/*  f0e4fb4:	8fb30064 */ 	lw	$s3,0x64($sp)
/*  f0e4fb8:	8fb40068 */ 	lw	$s4,0x68($sp)
/*  f0e4fbc:	8fb5006c */ 	lw	$s5,0x6c($sp)
/*  f0e4fc0:	8fb60070 */ 	lw	$s6,0x70($sp)
/*  f0e4fc4:	8fb70074 */ 	lw	$s7,0x74($sp)
/*  f0e4fc8:	8fbe0078 */ 	lw	$s8,0x78($sp)
/*  f0e4fcc:	03e00008 */ 	jr	$ra
/*  f0e4fd0:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);

void func0f0e4fd4(void)
{
	var80071184 = 0;
}

GLOBAL_ASM(
glabel func0f0e4fe0
/*  f0e4fe0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f0e4fe4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0e4fe8:	0fc5db69 */ 	jal	align16
/*  f0e4fec:	24040d20 */ 	addiu	$a0,$zero,0xd20
/*  f0e4ff0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0e4ff4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f0e4ff8:	03e00008 */ 	jr	$ra
/*  f0e4ffc:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f0e5000
/*  f0e5000:	27bdfeb0 */ 	addiu	$sp,$sp,-336
/*  f0e5004:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0e5008:	3c0e8008 */ 	lui	$t6,%hi(g_StageIndex)
/*  f0e500c:	44812000 */ 	mtc1	$at,$f4
/*  f0e5010:	8dcefc00 */ 	lw	$t6,%lo(g_StageIndex)($t6)
/*  f0e5014:	24010019 */ 	addiu	$at,$zero,0x19
/*  f0e5018:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f0e501c:	afb30060 */ 	sw	$s3,0x60($sp)
/*  f0e5020:	afb2005c */ 	sw	$s2,0x5c($sp)
/*  f0e5024:	afb10058 */ 	sw	$s1,0x58($sp)
/*  f0e5028:	afb00054 */ 	sw	$s0,0x54($sp)
/*  f0e502c:	f7be0048 */ 	sdc1	$f30,0x48($sp)
/*  f0e5030:	f7bc0040 */ 	sdc1	$f28,0x40($sp)
/*  f0e5034:	f7ba0038 */ 	sdc1	$f26,0x38($sp)
/*  f0e5038:	f7b80030 */ 	sdc1	$f24,0x30($sp)
/*  f0e503c:	f7b60028 */ 	sdc1	$f22,0x28($sp)
/*  f0e5040:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f0e5044:	afa40150 */ 	sw	$a0,0x150($sp)
/*  f0e5048:	afa000f0 */ 	sw	$zero,0xf0($sp)
/*  f0e504c:	15c10006 */ 	bne	$t6,$at,.L0f0e5068
/*  f0e5050:	e7a400f4 */ 	swc1	$f4,0xf4($sp)
/*  f0e5054:	3c014000 */ 	lui	$at,0x4000
/*  f0e5058:	44813000 */ 	mtc1	$at,$f6
/*  f0e505c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e5060:	afaf00f0 */ 	sw	$t7,0xf0($sp)
/*  f0e5064:	e7a600f4 */ 	swc1	$f6,0xf4($sp)
.L0f0e5068:
/*  f0e5068:	3c118007 */ 	lui	$s1,%hi(var80071184)
/*  f0e506c:	26311184 */ 	addiu	$s1,$s1,%lo(var80071184)
/*  f0e5070:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0e5074:	5700005d */ 	bnezl	$t8,.L0f0e51ec
/*  f0e5078:	3c012f80 */ 	lui	$at,0x2f80
/*  f0e507c:	0fc2777b */ 	jal	func0f09ddec
/*  f0e5080:	00000000 */ 	nop
/*  f0e5084:	14400003 */ 	bnez	$v0,.L0f0e5094
/*  f0e5088:	ae220000 */ 	sw	$v0,0x0($s1)
/*  f0e508c:	10000304 */ 	b	.L0f0e5ca0
/*  f0e5090:	8fa20150 */ 	lw	$v0,0x150($sp)
.L0f0e5094:
/*  f0e5094:	3c0143f0 */ 	lui	$at,0x43f0
/*  f0e5098:	4481f000 */ 	mtc1	$at,$f30
/*  f0e509c:	3c01c420 */ 	lui	$at,0xc420
/*  f0e50a0:	4481e000 */ 	mtc1	$at,$f28
/*  f0e50a4:	3c014420 */ 	lui	$at,0x4420
/*  f0e50a8:	4481d000 */ 	mtc1	$at,$f26
/*  f0e50ac:	3c017f1b */ 	lui	$at,%hi(var7f1adf74)
/*  f0e50b0:	c438df74 */ 	lwc1	$f24,%lo(var7f1adf74)($at)
/*  f0e50b4:	3c017f1b */ 	lui	$at,%hi(var7f1adf78)
/*  f0e50b8:	c436df78 */ 	lwc1	$f22,%lo(var7f1adf78)($at)
/*  f0e50bc:	3c012f80 */ 	lui	$at,0x2f80
/*  f0e50c0:	4481a000 */ 	mtc1	$at,$f20
/*  f0e50c4:	00008025 */ 	or	$s0,$zero,$zero
/*  f0e50c8:	24120d20 */ 	addiu	$s2,$zero,0xd20
.L0f0e50cc:
/*  f0e50cc:	0c004b70 */ 	jal	random
/*  f0e50d0:	00000000 */ 	nop
/*  f0e50d4:	44824000 */ 	mtc1	$v0,$f8
/*  f0e50d8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e50dc:	04410004 */ 	bgez	$v0,.L0f0e50f0
/*  f0e50e0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0e50e4:	44818000 */ 	mtc1	$at,$f16
/*  f0e50e8:	00000000 */ 	nop
/*  f0e50ec:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f0e50f0:
/*  f0e50f0:	46145482 */ 	mul.s	$f18,$f10,$f20
/*  f0e50f4:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f0e50f8:	01305021 */ 	addu	$t2,$t1,$s0
/*  f0e50fc:	46169102 */ 	mul.s	$f4,$f18,$f22
/*  f0e5100:	46182181 */ 	sub.s	$f6,$f4,$f24
/*  f0e5104:	0c004b70 */ 	jal	random
/*  f0e5108:	e5460000 */ 	swc1	$f6,0x0($t2)
/*  f0e510c:	44824000 */ 	mtc1	$v0,$f8
/*  f0e5110:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e5114:	04410004 */ 	bgez	$v0,.L0f0e5128
/*  f0e5118:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f0e511c:	44815000 */ 	mtc1	$at,$f10
/*  f0e5120:	00000000 */ 	nop
/*  f0e5124:	460a8400 */ 	add.s	$f16,$f16,$f10
.L0f0e5128:
/*  f0e5128:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f0e512c:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f0e5130:	3c01c3f0 */ 	lui	$at,0xc3f0
/*  f0e5134:	01706021 */ 	addu	$t4,$t3,$s0
/*  f0e5138:	46169102 */ 	mul.s	$f4,$f18,$f22
/*  f0e513c:	46182181 */ 	sub.s	$f6,$f4,$f24
/*  f0e5140:	e5860004 */ 	swc1	$f6,0x4($t4)
/*  f0e5144:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f0e5148:	01b01821 */ 	addu	$v1,$t5,$s0
/*  f0e514c:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f0e5150:	461a003c */ 	c.lt.s	$f0,$f26
/*  f0e5154:	00000000 */ 	nop
/*  f0e5158:	45000010 */ 	bc1f	.L0f0e519c
/*  f0e515c:	00000000 */ 	nop
/*  f0e5160:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f0e5164:	00000000 */ 	nop
/*  f0e5168:	4500000c */ 	bc1f	.L0f0e519c
/*  f0e516c:	00000000 */ 	nop
/*  f0e5170:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f0e5174:	461e003c */ 	c.lt.s	$f0,$f30
/*  f0e5178:	00000000 */ 	nop
/*  f0e517c:	45000007 */ 	bc1f	.L0f0e519c
/*  f0e5180:	00000000 */ 	nop
/*  f0e5184:	44814000 */ 	mtc1	$at,$f8
/*  f0e5188:	00000000 */ 	nop
/*  f0e518c:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0e5190:	00000000 */ 	nop
/*  f0e5194:	4501ffcd */ 	bc1t	.L0f0e50cc
/*  f0e5198:	00000000 */ 	nop
.L0f0e519c:
/*  f0e519c:	0c004b70 */ 	jal	random
/*  f0e51a0:	00000000 */ 	nop
/*  f0e51a4:	44825000 */ 	mtc1	$v0,$f10
/*  f0e51a8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e51ac:	04410004 */ 	bgez	$v0,.L0f0e51c0
/*  f0e51b0:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0e51b4:	44819000 */ 	mtc1	$at,$f18
/*  f0e51b8:	00000000 */ 	nop
/*  f0e51bc:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f0e51c0:
/*  f0e51c0:	46148102 */ 	mul.s	$f4,$f16,$f20
/*  f0e51c4:	3c0145fa */ 	lui	$at,0x45fa
/*  f0e51c8:	44814000 */ 	mtc1	$at,$f8
/*  f0e51cc:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0e51d0:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f0e51d4:	46002187 */ 	neg.s	$f6,$f4
/*  f0e51d8:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f0e51dc:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0e51e0:	1612ffba */ 	bne	$s0,$s2,.L0f0e50cc
/*  f0e51e4:	e5ea0008 */ 	swc1	$f10,0x8($t7)
/*  f0e51e8:	3c012f80 */ 	lui	$at,0x2f80
.L0f0e51ec:
/*  f0e51ec:	4481a000 */ 	mtc1	$at,$f20
/*  f0e51f0:	3c017f1b */ 	lui	$at,%hi(var7f1adf7c)
/*  f0e51f4:	c436df7c */ 	lwc1	$f22,%lo(var7f1adf7c)($at)
/*  f0e51f8:	3c017f1b */ 	lui	$at,%hi(var7f1adf80)
/*  f0e51fc:	c438df80 */ 	lwc1	$f24,%lo(var7f1adf80)($at)
/*  f0e5200:	3c014420 */ 	lui	$at,0x4420
/*  f0e5204:	4481d000 */ 	mtc1	$at,$f26
/*  f0e5208:	3c01c420 */ 	lui	$at,0xc420
/*  f0e520c:	4481e000 */ 	mtc1	$at,$f28
/*  f0e5210:	3c0143f0 */ 	lui	$at,0x43f0
/*  f0e5214:	4481f000 */ 	mtc1	$at,$f30
/*  f0e5218:	00009025 */ 	or	$s2,$zero,$zero
/*  f0e521c:	00008025 */ 	or	$s0,$zero,$zero
/*  f0e5220:	24130005 */ 	addiu	$s3,$zero,0x5
.L0f0e5224:
/*  f0e5224:	0253001a */ 	div	$zero,$s2,$s3
/*  f0e5228:	0000c810 */ 	mfhi	$t9
/*  f0e522c:	27290001 */ 	addiu	$t1,$t9,0x1
/*  f0e5230:	44899000 */ 	mtc1	$t1,$f18
/*  f0e5234:	c7a800f4 */ 	lwc1	$f8,0xf4($sp)
/*  f0e5238:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0e523c:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f0e5240:	03101821 */ 	addu	$v1,$t8,$s0
/*  f0e5244:	16600002 */ 	bnez	$s3,.L0f0e5250
/*  f0e5248:	00000000 */ 	nop
/*  f0e524c:	0007000d */ 	break	0x7
.L0f0e5250:
/*  f0e5250:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0e5254:	16610004 */ 	bne	$s3,$at,.L0f0e5268
/*  f0e5258:	3c018000 */ 	lui	$at,0x8000
/*  f0e525c:	16410002 */ 	bne	$s2,$at,.L0f0e5268
/*  f0e5260:	00000000 */ 	nop
/*  f0e5264:	0006000d */ 	break	0x6
.L0f0e5268:
/*  f0e5268:	3c01800a */ 	lui	$at,%hi(g_Vars+0x48)
/*  f0e526c:	c424a008 */ 	lwc1	$f4,%lo(g_Vars+0x48)($at)
/*  f0e5270:	c4720008 */ 	lwc1	$f18,0x8($v1)
/*  f0e5274:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f0e5278:	44802000 */ 	mtc1	$zero,$f4
/*  f0e527c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0e5280:	460a9400 */ 	add.s	$f16,$f18,$f10
/*  f0e5284:	e4700008 */ 	swc1	$f16,0x8($v1)
/*  f0e5288:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*  f0e528c:	01505821 */ 	addu	$t3,$t2,$s0
/*  f0e5290:	c5660008 */ 	lwc1	$f6,0x8($t3)
/*  f0e5294:	4606203c */ 	c.lt.s	$f4,$f6
/*  f0e5298:	00000000 */ 	nop
/*  f0e529c:	45020049 */ 	bc1fl	.L0f0e53c4
/*  f0e52a0:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f0e52a4:
/*  f0e52a4:	0c004b70 */ 	jal	random
/*  f0e52a8:	00000000 */ 	nop
/*  f0e52ac:	44824000 */ 	mtc1	$v0,$f8
/*  f0e52b0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e52b4:	04410004 */ 	bgez	$v0,.L0f0e52c8
/*  f0e52b8:	468044a0 */ 	cvt.s.w	$f18,$f8
/*  f0e52bc:	44815000 */ 	mtc1	$at,$f10
/*  f0e52c0:	00000000 */ 	nop
/*  f0e52c4:	460a9480 */ 	add.s	$f18,$f18,$f10
.L0f0e52c8:
/*  f0e52c8:	46149402 */ 	mul.s	$f16,$f18,$f20
/*  f0e52cc:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f0e52d0:	01906821 */ 	addu	$t5,$t4,$s0
/*  f0e52d4:	46168102 */ 	mul.s	$f4,$f16,$f22
/*  f0e52d8:	46182181 */ 	sub.s	$f6,$f4,$f24
/*  f0e52dc:	0c004b70 */ 	jal	random
/*  f0e52e0:	e5a60000 */ 	swc1	$f6,0x0($t5)
/*  f0e52e4:	44824000 */ 	mtc1	$v0,$f8
/*  f0e52e8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e52ec:	04410004 */ 	bgez	$v0,.L0f0e5300
/*  f0e52f0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0e52f4:	44819000 */ 	mtc1	$at,$f18
/*  f0e52f8:	00000000 */ 	nop
/*  f0e52fc:	46125280 */ 	add.s	$f10,$f10,$f18
.L0f0e5300:
/*  f0e5300:	46145402 */ 	mul.s	$f16,$f10,$f20
/*  f0e5304:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0e5308:	3c01c3f0 */ 	lui	$at,0xc3f0
/*  f0e530c:	01d07821 */ 	addu	$t7,$t6,$s0
/*  f0e5310:	46168102 */ 	mul.s	$f4,$f16,$f22
/*  f0e5314:	46182181 */ 	sub.s	$f6,$f4,$f24
/*  f0e5318:	e5e60004 */ 	swc1	$f6,0x4($t7)
/*  f0e531c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0e5320:	03101821 */ 	addu	$v1,$t8,$s0
/*  f0e5324:	c4600000 */ 	lwc1	$f0,0x0($v1)
/*  f0e5328:	461a003c */ 	c.lt.s	$f0,$f26
/*  f0e532c:	00000000 */ 	nop
/*  f0e5330:	45000010 */ 	bc1f	.L0f0e5374
/*  f0e5334:	00000000 */ 	nop
/*  f0e5338:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f0e533c:	00000000 */ 	nop
/*  f0e5340:	4500000c */ 	bc1f	.L0f0e5374
/*  f0e5344:	00000000 */ 	nop
/*  f0e5348:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f0e534c:	461e003c */ 	c.lt.s	$f0,$f30
/*  f0e5350:	00000000 */ 	nop
/*  f0e5354:	45000007 */ 	bc1f	.L0f0e5374
/*  f0e5358:	00000000 */ 	nop
/*  f0e535c:	44814000 */ 	mtc1	$at,$f8
/*  f0e5360:	00000000 */ 	nop
/*  f0e5364:	4600403c */ 	c.lt.s	$f8,$f0
/*  f0e5368:	00000000 */ 	nop
/*  f0e536c:	4501ffcd */ 	bc1t	.L0f0e52a4
/*  f0e5370:	00000000 */ 	nop
.L0f0e5374:
/*  f0e5374:	0c004b70 */ 	jal	random
/*  f0e5378:	00000000 */ 	nop
/*  f0e537c:	44829000 */ 	mtc1	$v0,$f18
/*  f0e5380:	3c014f80 */ 	lui	$at,0x4f80
/*  f0e5384:	04410004 */ 	bgez	$v0,.L0f0e5398
/*  f0e5388:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f0e538c:	44818000 */ 	mtc1	$at,$f16
/*  f0e5390:	00000000 */ 	nop
/*  f0e5394:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f0e5398:
/*  f0e5398:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0e539c:	3c0143fa */ 	lui	$at,0x43fa
/*  f0e53a0:	44813000 */ 	mtc1	$at,$f6
/*  f0e53a4:	3c01c5fa */ 	lui	$at,0xc5fa
/*  f0e53a8:	44819000 */ 	mtc1	$at,$f18
/*  f0e53ac:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f0e53b0:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0e53b4:	03304821 */ 	addu	$t1,$t9,$s0
/*  f0e53b8:	46089401 */ 	sub.s	$f16,$f18,$f8
/*  f0e53bc:	e5300008 */ 	swc1	$f16,0x8($t1)
/*  f0e53c0:	26520001 */ 	addiu	$s2,$s2,0x1
.L0f0e53c4:
/*  f0e53c4:	2a410118 */ 	slti	$at,$s2,0x118
/*  f0e53c8:	1420ff96 */ 	bnez	$at,.L0f0e5224
/*  f0e53cc:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f0e53d0:	3c014120 */ 	lui	$at,0x4120
/*  f0e53d4:	44816000 */ 	mtc1	$at,$f12
/*  f0e53d8:	0fc01ae8 */ 	jal	func0f006ba0
/*  f0e53dc:	00000000 */ 	nop
/*  f0e53e0:	3c01800a */ 	lui	$at,%hi(var8009de98)
/*  f0e53e4:	ac20de98 */ 	sw	$zero,%lo(var8009de98)($at)
/*  f0e53e8:	3c01800a */ 	lui	$at,%hi(var8009de9c)
/*  f0e53ec:	8fa40150 */ 	lw	$a0,0x150($sp)
/*  f0e53f0:	46000506 */ 	mov.s	$f20,$f0
/*  f0e53f4:	ac20de9c */ 	sw	$zero,%lo(var8009de9c)($at)
/*  f0e53f8:	0fc3528f */ 	jal	func0f0d4a3c
/*  f0e53fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0e5400:	3c0afffe */ 	lui	$t2,0xfffe
/*  f0e5404:	8fac00f0 */ 	lw	$t4,0xf0($sp)
/*  f0e5408:	354a7960 */ 	ori	$t2,$t2,0x7960
/*  f0e540c:	3c01800a */ 	lui	$at,%hi(var8009de90)
/*  f0e5410:	ac2ade90 */ 	sw	$t2,%lo(var8009de90)($at)
/*  f0e5414:	3c0b0001 */ 	lui	$t3,0x1
/*  f0e5418:	356b86a0 */ 	ori	$t3,$t3,0x86a0
/*  f0e541c:	3c01800a */ 	lui	$at,%hi(var8009de94)
/*  f0e5420:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e5424:	11800022 */ 	beqz	$t4,.L0f0e54b0
/*  f0e5428:	ac2bde94 */ 	sw	$t3,%lo(var8009de94)($at)
/*  f0e542c:	3c026060 */ 	lui	$v0,0x6060
/*  f0e5430:	3442607f */ 	ori	$v0,$v0,0x607f
/*  f0e5434:	240dfff6 */ 	addiu	$t5,$zero,-10
/*  f0e5438:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f0e543c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f0e5440:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f0e5444:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e5448:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e544c:	2406fff6 */ 	addiu	$a2,$zero,-10
/*  f0e5450:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e5454:	afb3001c */ 	sw	$s3,0x1c($sp)
/*  f0e5458:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e545c:	afb20150 */ 	sw	$s2,0x150($sp)
/*  f0e5460:	0c002f06 */ 	jal	viGetY
/*  f0e5464:	afa20150 */ 	sw	$v0,0x150($sp)
/*  f0e5468:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e546c:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0e5470:	0c002f06 */ 	jal	viGetY
/*  f0e5474:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0e5478:	3c039090 */ 	lui	$v1,0x9090
/*  f0e547c:	3463907f */ 	ori	$v1,$v1,0x907f
/*  f0e5480:	244f000a */ 	addiu	$t7,$v0,0xa
/*  f0e5484:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0e5488:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e548c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e5490:	8fa40150 */ 	lw	$a0,0x150($sp)
/*  f0e5494:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e5498:	2606000a */ 	addiu	$a2,$s0,0xa
/*  f0e549c:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e54a0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e54a4:	afb3001c */ 	sw	$s3,0x1c($sp)
/*  f0e54a8:	10000023 */ 	b	.L0f0e5538
/*  f0e54ac:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e54b0:
/*  f0e54b0:	2418fff6 */ 	addiu	$t8,$zero,-10
/*  f0e54b4:	3419947f */ 	dli	$t9,0x947f
/*  f0e54b8:	3409947f */ 	dli	$t1,0x947f
/*  f0e54bc:	240a000a */ 	addiu	$t2,$zero,0xa
/*  f0e54c0:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f0e54c4:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f0e54c8:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0e54cc:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f0e54d0:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e54d4:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e54d8:	2406fff6 */ 	addiu	$a2,$zero,-10
/*  f0e54dc:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e54e0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e54e4:	afb20150 */ 	sw	$s2,0x150($sp)
/*  f0e54e8:	0c002f06 */ 	jal	viGetY
/*  f0e54ec:	afa20150 */ 	sw	$v0,0x150($sp)
/*  f0e54f0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0e54f4:	00105c03 */ 	sra	$t3,$s0,0x10
/*  f0e54f8:	0c002f06 */ 	jal	viGetY
/*  f0e54fc:	01608025 */ 	or	$s0,$t3,$zero
/*  f0e5500:	3c036200 */ 	lui	$v1,0x6200
/*  f0e5504:	3463947f */ 	ori	$v1,$v1,0x947f
/*  f0e5508:	244c000a */ 	addiu	$t4,$v0,0xa
/*  f0e550c:	240d0006 */ 	addiu	$t5,$zero,0x6
/*  f0e5510:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0e5514:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0e5518:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f0e551c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0e5520:	8fa40150 */ 	lw	$a0,0x150($sp)
/*  f0e5524:	2405fc18 */ 	addiu	$a1,$zero,-1000
/*  f0e5528:	2606000a */ 	addiu	$a2,$s0,0xa
/*  f0e552c:	0fc35343 */ 	jal	func0f0d4d0c
/*  f0e5530:	240707d0 */ 	addiu	$a3,$zero,0x7d0
/*  f0e5534:	00409025 */ 	or	$s2,$v0,$zero
.L0f0e5538:
/*  f0e5538:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e553c:	0fc35320 */ 	jal	func0f0d4c80
/*  f0e5540:	afb20150 */ 	sw	$s2,0x150($sp)
/*  f0e5544:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e5548:	0fc35272 */ 	jal	func0f0d49c8
/*  f0e554c:	afa20150 */ 	sw	$v0,0x150($sp)
/*  f0e5550:	3c05800b */ 	lui	$a1,%hi(var800ab5a8)
/*  f0e5554:	8ca5b5a8 */ 	lw	$a1,%lo(var800ab5a8)($a1)
/*  f0e5558:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f0e555c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0e5560:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f0e5564:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f0e5568:	27a40150 */ 	addiu	$a0,$sp,0x150
/*  f0e556c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0e5570:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0e5574:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0e5578:	afa20150 */ 	sw	$v0,0x150($sp)
/*  f0e557c:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0e5580:	24a5000c */ 	addiu	$a1,$a1,0x000c
/*  f0e5584:	8fb80150 */ 	lw	$t8,0x150($sp)
/*  f0e5588:	3c09ba00 */ 	lui	$t1,0xba00
/*  f0e558c:	35291402 */ 	ori	$t1,$t1,0x1402
/*  f0e5590:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e5594:	afb90150 */ 	sw	$t9,0x150($sp)
/*  f0e5598:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0e559c:	af090000 */ 	sw	$t1,0x0($t8)
/*  f0e55a0:	8faa0150 */ 	lw	$t2,0x150($sp)
/*  f0e55a4:	3c0cba00 */ 	lui	$t4,0xba00
/*  f0e55a8:	358c0602 */ 	ori	$t4,$t4,0x602
/*  f0e55ac:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0e55b0:	afab0150 */ 	sw	$t3,0x150($sp)
/*  f0e55b4:	240d00c0 */ 	addiu	$t5,$zero,0xc0
/*  f0e55b8:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0e55bc:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f0e55c0:	8fae0150 */ 	lw	$t6,0x150($sp)
/*  f0e55c4:	3c18b900 */ 	lui	$t8,0xb900
/*  f0e55c8:	3c190050 */ 	lui	$t9,0x50
/*  f0e55cc:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e55d0:	afaf0150 */ 	sw	$t7,0x150($sp)
/*  f0e55d4:	373949d8 */ 	ori	$t9,$t9,0x49d8
/*  f0e55d8:	3718031d */ 	ori	$t8,$t8,0x31d
/*  f0e55dc:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e55e0:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0e55e4:	8fa90150 */ 	lw	$t1,0x150($sp)
/*  f0e55e8:	3c0bb900 */ 	lui	$t3,0xb900
/*  f0e55ec:	356b0002 */ 	ori	$t3,$t3,0x2
/*  f0e55f0:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f0e55f4:	afaa0150 */ 	sw	$t2,0x150($sp)
/*  f0e55f8:	ad200004 */ 	sw	$zero,0x4($t1)
/*  f0e55fc:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f0e5600:	8fac0150 */ 	lw	$t4,0x150($sp)
/*  f0e5604:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0e5608:	35ce1001 */ 	ori	$t6,$t6,0x1001
/*  f0e560c:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f0e5610:	afad0150 */ 	sw	$t5,0x150($sp)
/*  f0e5614:	ad800004 */ 	sw	$zero,0x4($t4)
/*  f0e5618:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f0e561c:	8faf0150 */ 	lw	$t7,0x150($sp)
/*  f0e5620:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0e5624:	37390903 */ 	ori	$t9,$t9,0x903
/*  f0e5628:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0e562c:	afb80150 */ 	sw	$t8,0x150($sp)
/*  f0e5630:	24090c00 */ 	addiu	$t1,$zero,0xc00
/*  f0e5634:	ade90004 */ 	sw	$t1,0x4($t7)
/*  f0e5638:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0e563c:	8faa0150 */ 	lw	$t2,0x150($sp)
/*  f0e5640:	3c0cfcff */ 	lui	$t4,0xfcff
/*  f0e5644:	3c0dff32 */ 	lui	$t5,0xff32
/*  f0e5648:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0e564c:	afab0150 */ 	sw	$t3,0x150($sp)
/*  f0e5650:	35ad7f3f */ 	ori	$t5,$t5,0x7f3f
/*  f0e5654:	358c99ff */ 	ori	$t4,$t4,0x99ff
/*  f0e5658:	ad4c0000 */ 	sw	$t4,0x0($t2)
/*  f0e565c:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0e5660:	8fae0150 */ 	lw	$t6,0x150($sp)
/*  f0e5664:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0e5668:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f0e566c:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0e5670:	afaf0150 */ 	sw	$t7,0x150($sp)
/*  f0e5674:	24192000 */ 	addiu	$t9,$zero,0x2000
/*  f0e5678:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0e567c:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0e5680:	8fa90150 */ 	lw	$t1,0x150($sp)
/*  f0e5684:	3c0bba00 */ 	lui	$t3,0xba00
/*  f0e5688:	27b00110 */ 	addiu	$s0,$sp,0x110
/*  f0e568c:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f0e5690:	afaa0150 */ 	sw	$t2,0x150($sp)
/*  f0e5694:	356b1301 */ 	ori	$t3,$t3,0x1301
/*  f0e5698:	3c0c0008 */ 	lui	$t4,0x8
/*  f0e569c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e56a0:	ad2c0004 */ 	sw	$t4,0x4($t1)
/*  f0e56a4:	0c00566c */ 	jal	func000159b0
/*  f0e56a8:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f0e56ac:	0fc59e66 */ 	jal	func0f167998
/*  f0e56b0:	00000000 */ 	nop
/*  f0e56b4:	00409025 */ 	or	$s2,$v0,$zero
/*  f0e56b8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e56bc:	0c005815 */ 	jal	func00016054
/*  f0e56c0:	00402825 */ 	or	$a1,$v0,$zero
/*  f0e56c4:	8fb00150 */ 	lw	$s0,0x150($sp)
/*  f0e56c8:	3c0f0102 */ 	lui	$t7,0x102
/*  f0e56cc:	35ef0040 */ 	ori	$t7,$t7,0x40
/*  f0e56d0:	260e0008 */ 	addiu	$t6,$s0,0x8
/*  f0e56d4:	afae0150 */ 	sw	$t6,0x150($sp)
/*  f0e56d8:	02402025 */ 	or	$a0,$s2,$zero
/*  f0e56dc:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e56e0:	ae0f0000 */ 	sw	$t7,0x0($s0)
/*  f0e56e4:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f0e56e8:	0fc59e73 */ 	jal	func0f1679cc
/*  f0e56ec:	24040014 */ 	addiu	$a0,$zero,0x14
/*  f0e56f0:	8fb800f0 */ 	lw	$t8,0xf0($sp)
/*  f0e56f4:	00408025 */ 	or	$s0,$v0,$zero
/*  f0e56f8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e56fc:	1300004b */ 	beqz	$t8,.L0f0e582c
/*  f0e5700:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e5704:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e5708:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e570c:	2408ff00 */ 	addiu	$t0,$zero,-256
/*  f0e5710:	2407007f */ 	addiu	$a3,$zero,0x7f
/*  f0e5714:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f0e5718:	0263c823 */ 	subu	$t9,$s3,$v1
.L0f0e571c:
/*  f0e571c:	03270019 */ 	multu	$t9,$a3
/*  f0e5720:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e5724:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e5728:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e572c:	00004812 */ 	mflo	$t1
/*  f0e5730:	00000000 */ 	nop
/*  f0e5734:	00000000 */ 	nop
/*  f0e5738:	0125001b */ 	divu	$zero,$t1,$a1
/*  f0e573c:	00005012 */ 	mflo	$t2
/*  f0e5740:	01485825 */ 	or	$t3,$t2,$t0
/*  f0e5744:	14a00002 */ 	bnez	$a1,.L0f0e5750
/*  f0e5748:	00000000 */ 	nop
/*  f0e574c:	0007000d */ 	break	0x7
.L0f0e5750:
/*  f0e5750:	ac8bfff0 */ 	sw	$t3,-0x10($a0)
/*  f0e5754:	5420fff1 */ 	bnezl	$at,.L0f0e571c
/*  f0e5758:	0263c823 */ 	subu	$t9,$s3,$v1
/*  f0e575c:	3c06aaaa */ 	lui	$a2,0xaaaa
/*  f0e5760:	34c6aa00 */ 	ori	$a2,$a2,0xaa00
/*  f0e5764:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e5768:	00402025 */ 	or	$a0,$v0,$zero
.L0f0e576c:
/*  f0e576c:	02636023 */ 	subu	$t4,$s3,$v1
/*  f0e5770:	000c6900 */ 	sll	$t5,$t4,0x4
/*  f0e5774:	01a5001b */ 	divu	$zero,$t5,$a1
/*  f0e5778:	00007012 */ 	mflo	$t6
/*  f0e577c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e5780:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e5784:	01c67825 */ 	or	$t7,$t6,$a2
/*  f0e5788:	14a00002 */ 	bnez	$a1,.L0f0e5794
/*  f0e578c:	00000000 */ 	nop
/*  f0e5790:	0007000d */ 	break	0x7
.L0f0e5794:
/*  f0e5794:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0e5798:	1420fff4 */ 	bnez	$at,.L0f0e576c
/*  f0e579c:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e57a0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e57a4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e57a8:	0263c023 */ 	subu	$t8,$s3,$v1
.L0f0e57ac:
/*  f0e57ac:	03070019 */ 	multu	$t8,$a3
/*  f0e57b0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e57b4:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e57b8:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e57bc:	0000c812 */ 	mflo	$t9
/*  f0e57c0:	00000000 */ 	nop
/*  f0e57c4:	00000000 */ 	nop
/*  f0e57c8:	0325001b */ 	divu	$zero,$t9,$a1
/*  f0e57cc:	00004812 */ 	mflo	$t1
/*  f0e57d0:	01285025 */ 	or	$t2,$t1,$t0
/*  f0e57d4:	14a00002 */ 	bnez	$a1,.L0f0e57e0
/*  f0e57d8:	00000000 */ 	nop
/*  f0e57dc:	0007000d */ 	break	0x7
.L0f0e57e0:
/*  f0e57e0:	ac8afff8 */ 	sw	$t2,-0x8($a0)
/*  f0e57e4:	5420fff1 */ 	bnezl	$at,.L0f0e57ac
/*  f0e57e8:	0263c023 */ 	subu	$t8,$s3,$v1
/*  f0e57ec:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e57f0:	00402025 */ 	or	$a0,$v0,$zero
.L0f0e57f4:
/*  f0e57f4:	02635823 */ 	subu	$t3,$s3,$v1
/*  f0e57f8:	000b6100 */ 	sll	$t4,$t3,0x4
/*  f0e57fc:	0185001b */ 	divu	$zero,$t4,$a1
/*  f0e5800:	00006812 */ 	mflo	$t5
/*  f0e5804:	01a67025 */ 	or	$t6,$t5,$a2
/*  f0e5808:	14a00002 */ 	bnez	$a1,.L0f0e5814
/*  f0e580c:	00000000 */ 	nop
/*  f0e5810:	0007000d */ 	break	0x7
.L0f0e5814:
/*  f0e5814:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e5818:	ac8e000c */ 	sw	$t6,0xc($a0)
/*  f0e581c:	1473fff5 */ 	bne	$v1,$s3,.L0f0e57f4
/*  f0e5820:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e5824:	1000004a */ 	b	.L0f0e5950
/*  f0e5828:	8fb30150 */ 	lw	$s3,0x150($sp)
.L0f0e582c:
/*  f0e582c:	2408ff00 */ 	addiu	$t0,$zero,-256
/*  f0e5830:	2407007f */ 	addiu	$a3,$zero,0x7f
/*  f0e5834:	24050005 */ 	addiu	$a1,$zero,0x5
/*  f0e5838:	02637823 */ 	subu	$t7,$s3,$v1
.L0f0e583c:
/*  f0e583c:	01e70019 */ 	multu	$t7,$a3
/*  f0e5840:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e5844:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e5848:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e584c:	0000c012 */ 	mflo	$t8
/*  f0e5850:	00000000 */ 	nop
/*  f0e5854:	00000000 */ 	nop
/*  f0e5858:	0305001b */ 	divu	$zero,$t8,$a1
/*  f0e585c:	0000c812 */ 	mflo	$t9
/*  f0e5860:	03284825 */ 	or	$t1,$t9,$t0
/*  f0e5864:	14a00002 */ 	bnez	$a1,.L0f0e5870
/*  f0e5868:	00000000 */ 	nop
/*  f0e586c:	0007000d */ 	break	0x7
.L0f0e5870:
/*  f0e5870:	ac89fff0 */ 	sw	$t1,-0x10($a0)
/*  f0e5874:	5420fff1 */ 	bnezl	$at,.L0f0e583c
/*  f0e5878:	02637823 */ 	subu	$t7,$s3,$v1
/*  f0e587c:	3c06aaaa */ 	lui	$a2,0xaaaa
/*  f0e5880:	34c6ff00 */ 	ori	$a2,$a2,0xff00
/*  f0e5884:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e5888:	00402025 */ 	or	$a0,$v0,$zero
.L0f0e588c:
/*  f0e588c:	02635023 */ 	subu	$t2,$s3,$v1
/*  f0e5890:	000a5900 */ 	sll	$t3,$t2,0x4
/*  f0e5894:	0165001b */ 	divu	$zero,$t3,$a1
/*  f0e5898:	00006012 */ 	mflo	$t4
/*  f0e589c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e58a0:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e58a4:	01866825 */ 	or	$t5,$t4,$a2
/*  f0e58a8:	14a00002 */ 	bnez	$a1,.L0f0e58b4
/*  f0e58ac:	00000000 */ 	nop
/*  f0e58b0:	0007000d */ 	break	0x7
.L0f0e58b4:
/*  f0e58b4:	ac8d0004 */ 	sw	$t5,0x4($a0)
/*  f0e58b8:	1420fff4 */ 	bnez	$at,.L0f0e588c
/*  f0e58bc:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e58c0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e58c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e58c8:	02637023 */ 	subu	$t6,$s3,$v1
.L0f0e58cc:
/*  f0e58cc:	01c70019 */ 	multu	$t6,$a3
/*  f0e58d0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e58d4:	28610005 */ 	slti	$at,$v1,0x5
/*  f0e58d8:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e58dc:	00007812 */ 	mflo	$t7
/*  f0e58e0:	00000000 */ 	nop
/*  f0e58e4:	00000000 */ 	nop
/*  f0e58e8:	01e5001b */ 	divu	$zero,$t7,$a1
/*  f0e58ec:	0000c012 */ 	mflo	$t8
/*  f0e58f0:	0308c825 */ 	or	$t9,$t8,$t0
/*  f0e58f4:	14a00002 */ 	bnez	$a1,.L0f0e5900
/*  f0e58f8:	00000000 */ 	nop
/*  f0e58fc:	0007000d */ 	break	0x7
.L0f0e5900:
/*  f0e5900:	ac99fff8 */ 	sw	$t9,-0x8($a0)
/*  f0e5904:	5420fff1 */ 	bnezl	$at,.L0f0e58cc
/*  f0e5908:	02637023 */ 	subu	$t6,$s3,$v1
/*  f0e590c:	3c06ffaa */ 	lui	$a2,0xffaa
/*  f0e5910:	34c6ff00 */ 	ori	$a2,$a2,0xff00
/*  f0e5914:	00001825 */ 	or	$v1,$zero,$zero
/*  f0e5918:	00402025 */ 	or	$a0,$v0,$zero
.L0f0e591c:
/*  f0e591c:	02634823 */ 	subu	$t1,$s3,$v1
/*  f0e5920:	00095100 */ 	sll	$t2,$t1,0x4
/*  f0e5924:	0145001b */ 	divu	$zero,$t2,$a1
/*  f0e5928:	00005812 */ 	mflo	$t3
/*  f0e592c:	01666025 */ 	or	$t4,$t3,$a2
/*  f0e5930:	14a00002 */ 	bnez	$a1,.L0f0e593c
/*  f0e5934:	00000000 */ 	nop
/*  f0e5938:	0007000d */ 	break	0x7
.L0f0e593c:
/*  f0e593c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0e5940:	ac8c000c */ 	sw	$t4,0xc($a0)
/*  f0e5944:	1473fff5 */ 	bne	$v1,$s3,.L0f0e591c
/*  f0e5948:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f0e594c:	8fb30150 */ 	lw	$s3,0x150($sp)
.L0f0e5950:
/*  f0e5950:	3c0f074c */ 	lui	$t7,0x74c
/*  f0e5954:	35ef0050 */ 	ori	$t7,$t7,0x50
/*  f0e5958:	266e0008 */ 	addiu	$t6,$s3,0x8
/*  f0e595c:	afae0150 */ 	sw	$t6,0x150($sp)
/*  f0e5960:	02002025 */ 	or	$a0,$s0,$zero
/*  f0e5964:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e5968:	ae6f0000 */ 	sw	$t7,0x0($s3)
/*  f0e596c:	ae620004 */ 	sw	$v0,0x4($s3)
/*  f0e5970:	3c017f1b */ 	lui	$at,%hi(var7f1adf84)
/*  f0e5974:	c42adf84 */ 	lwc1	$f10,%lo(var7f1adf84)($at)
/*  f0e5978:	3c017f1b */ 	lui	$at,%hi(var7f1adf88)
/*  f0e597c:	c43edf88 */ 	lwc1	$f30,%lo(var7f1adf88)($at)
/*  f0e5980:	460aa002 */ 	mul.s	$f0,$f20,$f10
/*  f0e5984:	3c014170 */ 	lui	$at,0x4170
/*  f0e5988:	4481e000 */ 	mtc1	$at,$f28
/*  f0e598c:	3c017f1b */ 	lui	$at,%hi(var7f1adf8c)
/*  f0e5990:	c43adf8c */ 	lwc1	$f26,%lo(var7f1adf8c)($at)
/*  f0e5994:	3c0141c8 */ 	lui	$at,0x41c8
/*  f0e5998:	4481b000 */ 	mtc1	$at,$f22
/*  f0e599c:	e7a00070 */ 	swc1	$f0,0x70($sp)
/*  f0e59a0:	24120117 */ 	addiu	$s2,$zero,0x117
/*  f0e59a4:	24100d14 */ 	addiu	$s0,$zero,0xd14
.L0f0e59a8:
/*  f0e59a8:	44922000 */ 	mtc1	$s2,$f4
/*  f0e59ac:	c7a00070 */ 	lwc1	$f0,0x70($sp)
/*  f0e59b0:	00009825 */ 	or	$s3,$zero,$zero
/*  f0e59b4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0e59b8:	461c3483 */ 	div.s	$f18,$f6,$f28
/*  f0e59bc:	4612d202 */ 	mul.s	$f8,$f26,$f18
/*  f0e59c0:	46080500 */ 	add.s	$f20,$f0,$f8
/*  f0e59c4:	0c0068f7 */ 	jal	sinf
/*  f0e59c8:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e59cc:	46000606 */ 	mov.s	$f24,$f0
/*  f0e59d0:	0c0068f4 */ 	jal	cosf
/*  f0e59d4:	4600a306 */ 	mov.s	$f12,$f20
/*  f0e59d8:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0e59dc:	46000506 */ 	mov.s	$f20,$f0
/*  f0e59e0:	3c017f1b */ 	lui	$at,%hi(var7f1adf90)
/*  f0e59e4:	03101821 */ 	addu	$v1,$t8,$s0
/*  f0e59e8:	c4700000 */ 	lwc1	$f16,0x0($v1)
/*  f0e59ec:	e7b000b8 */ 	swc1	$f16,0xb8($sp)
/*  f0e59f0:	c46a0004 */ 	lwc1	$f10,0x4($v1)
/*  f0e59f4:	e7aa00bc */ 	swc1	$f10,0xbc($sp)
/*  f0e59f8:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f0e59fc:	e7a400c0 */ 	swc1	$f4,0xc0($sp)
/*  f0e5a00:	c7a600c0 */ 	lwc1	$f6,0xc0($sp)
/*  f0e5a04:	c7a000c0 */ 	lwc1	$f0,0xc0($sp)
/*  f0e5a08:	461e303c */ 	c.lt.s	$f6,$f30
/*  f0e5a0c:	00000000 */ 	nop
/*  f0e5a10:	4502000e */ 	bc1fl	.L0f0e5a4c
/*  f0e5a14:	44808000 */ 	mtc1	$zero,$f16
/*  f0e5a18:	c432df90 */ 	lwc1	$f18,%lo(var7f1adf90)($at)
/*  f0e5a1c:	3c0144af */ 	lui	$at,0x44af
/*  f0e5a20:	44815000 */ 	mtc1	$at,$f10
/*  f0e5a24:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f0e5a28:	3c0140a0 */ 	lui	$at,0x40a0
/*  f0e5a2c:	44813000 */ 	mtc1	$at,$f6
/*  f0e5a30:	46004407 */ 	neg.s	$f16,$f8
/*  f0e5a34:	460a8103 */ 	div.s	$f4,$f16,$f10
/*  f0e5a38:	46062482 */ 	mul.s	$f18,$f4,$f6
/*  f0e5a3c:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e5a40:	44134000 */ 	mfc1	$s3,$f8
/*  f0e5a44:	00000000 */ 	nop
/*  f0e5a48:	44808000 */ 	mtc1	$zero,$f16
.L0f0e5a4c:
/*  f0e5a4c:	2a610006 */ 	slti	$at,$s3,0x6
/*  f0e5a50:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0e5a54:	00000000 */ 	nop
/*  f0e5a58:	4502008d */ 	bc1fl	.L0f0e5c90
/*  f0e5a5c:	2652ffff */ 	addiu	$s2,$s2,-1
/*  f0e5a60:	5020008b */ 	beqzl	$at,.L0f0e5c90
/*  f0e5a64:	2652ffff */ 	addiu	$s2,$s2,-1
/*  f0e5a68:	0fc59e59 */ 	jal	func0f167964
/*  f0e5a6c:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f0e5a70:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f0e5a74:	4600c007 */ 	neg.s	$f0,$f24
/*  f0e5a78:	4600a087 */ 	neg.s	$f2,$f20
/*  f0e5a7c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0e5a80:	00402025 */ 	or	$a0,$v0,$zero
/*  f0e5a84:	440a2000 */ 	mfc1	$t2,$f4
/*  f0e5a88:	4614c100 */ 	add.s	$f4,$f24,$f20
/*  f0e5a8c:	a44a0000 */ 	sh	$t2,0x0($v0)
/*  f0e5a90:	c7a600bc */ 	lwc1	$f6,0xbc($sp)
/*  f0e5a94:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0e5a98:	4604b182 */ 	mul.s	$f6,$f22,$f4
/*  f0e5a9c:	4600a100 */ 	add.s	$f4,$f20,$f0
/*  f0e5aa0:	440c9000 */ 	mfc1	$t4,$f18
/*  f0e5aa4:	00000000 */ 	nop
/*  f0e5aa8:	a44c0002 */ 	sh	$t4,0x2($v0)
/*  f0e5aac:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0e5ab0:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f0e5ab4:	440e8000 */ 	mfc1	$t6,$f16
/*  f0e5ab8:	00000000 */ 	nop
/*  f0e5abc:	a44e0004 */ 	sh	$t6,0x4($v0)
/*  f0e5ac0:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f0e5ac4:	46065480 */ 	add.s	$f18,$f10,$f6
/*  f0e5ac8:	4604b282 */ 	mul.s	$f10,$f22,$f4
/*  f0e5acc:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e5ad0:	44184000 */ 	mfc1	$t8,$f8
/*  f0e5ad4:	00000000 */ 	nop
/*  f0e5ad8:	a458000c */ 	sh	$t8,0xc($v0)
/*  f0e5adc:	c7b000bc */ 	lwc1	$f16,0xbc($sp)
/*  f0e5ae0:	460a8180 */ 	add.s	$f6,$f16,$f10
/*  f0e5ae4:	4614c281 */ 	sub.s	$f10,$f24,$f20
/*  f0e5ae8:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0e5aec:	460ab182 */ 	mul.s	$f6,$f22,$f10
/*  f0e5af0:	4600a281 */ 	sub.s	$f10,$f20,$f0
/*  f0e5af4:	44099000 */ 	mfc1	$t1,$f18
/*  f0e5af8:	00000000 */ 	nop
/*  f0e5afc:	a449000e */ 	sh	$t1,0xe($v0)
/*  f0e5b00:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0e5b04:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f0e5b08:	440b2000 */ 	mfc1	$t3,$f4
/*  f0e5b0c:	00000000 */ 	nop
/*  f0e5b10:	a44b0010 */ 	sh	$t3,0x10($v0)
/*  f0e5b14:	c7b000b8 */ 	lwc1	$f16,0xb8($sp)
/*  f0e5b18:	46068480 */ 	add.s	$f18,$f16,$f6
/*  f0e5b1c:	460ab402 */ 	mul.s	$f16,$f22,$f10
/*  f0e5b20:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e5b24:	440d4000 */ 	mfc1	$t5,$f8
/*  f0e5b28:	00000000 */ 	nop
/*  f0e5b2c:	a44d0018 */ 	sh	$t5,0x18($v0)
/*  f0e5b30:	c7a400bc */ 	lwc1	$f4,0xbc($sp)
/*  f0e5b34:	46102180 */ 	add.s	$f6,$f4,$f16
/*  f0e5b38:	46140401 */ 	sub.s	$f16,$f0,$f20
/*  f0e5b3c:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0e5b40:	4610b182 */ 	mul.s	$f6,$f22,$f16
/*  f0e5b44:	46001401 */ 	sub.s	$f16,$f2,$f0
/*  f0e5b48:	440f9000 */ 	mfc1	$t7,$f18
/*  f0e5b4c:	00000000 */ 	nop
/*  f0e5b50:	a44f001a */ 	sh	$t7,0x1a($v0)
/*  f0e5b54:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0e5b58:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0e5b5c:	44195000 */ 	mfc1	$t9,$f10
/*  f0e5b60:	00000000 */ 	nop
/*  f0e5b64:	a459001c */ 	sh	$t9,0x1c($v0)
/*  f0e5b68:	c7a400b8 */ 	lwc1	$f4,0xb8($sp)
/*  f0e5b6c:	46062480 */ 	add.s	$f18,$f4,$f6
/*  f0e5b70:	4610b102 */ 	mul.s	$f4,$f22,$f16
/*  f0e5b74:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e5b78:	440a4000 */ 	mfc1	$t2,$f8
/*  f0e5b7c:	00000000 */ 	nop
/*  f0e5b80:	a44a0024 */ 	sh	$t2,0x24($v0)
/*  f0e5b84:	c7aa00bc */ 	lwc1	$f10,0xbc($sp)
/*  f0e5b88:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f0e5b8c:	46140100 */ 	add.s	$f4,$f0,$f20
/*  f0e5b90:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0e5b94:	4604b182 */ 	mul.s	$f6,$f22,$f4
/*  f0e5b98:	46001100 */ 	add.s	$f4,$f2,$f0
/*  f0e5b9c:	440c9000 */ 	mfc1	$t4,$f18
/*  f0e5ba0:	00000000 */ 	nop
/*  f0e5ba4:	a44c0026 */ 	sh	$t4,0x26($v0)
/*  f0e5ba8:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0e5bac:	00136080 */ 	sll	$t4,$s3,0x2
/*  f0e5bb0:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f0e5bb4:	440e8000 */ 	mfc1	$t6,$f16
/*  f0e5bb8:	00000000 */ 	nop
/*  f0e5bbc:	a44e0028 */ 	sh	$t6,0x28($v0)
/*  f0e5bc0:	c7aa00b8 */ 	lwc1	$f10,0xb8($sp)
/*  f0e5bc4:	46065480 */ 	add.s	$f18,$f10,$f6
/*  f0e5bc8:	4604b282 */ 	mul.s	$f10,$f22,$f4
/*  f0e5bcc:	4600920d */ 	trunc.w.s	$f8,$f18
/*  f0e5bd0:	44184000 */ 	mfc1	$t8,$f8
/*  f0e5bd4:	00000000 */ 	nop
/*  f0e5bd8:	a4580030 */ 	sh	$t8,0x30($v0)
/*  f0e5bdc:	c7b000bc */ 	lwc1	$f16,0xbc($sp)
/*  f0e5be0:	460a8180 */ 	add.s	$f6,$f16,$f10
/*  f0e5be4:	4600348d */ 	trunc.w.s	$f18,$f6
/*  f0e5be8:	44099000 */ 	mfc1	$t1,$f18
/*  f0e5bec:	00000000 */ 	nop
/*  f0e5bf0:	a4490032 */ 	sh	$t1,0x32($v0)
/*  f0e5bf4:	c7a800c0 */ 	lwc1	$f8,0xc0($sp)
/*  f0e5bf8:	3c090440 */ 	lui	$t1,0x440
/*  f0e5bfc:	3529003c */ 	ori	$t1,$t1,0x3c
/*  f0e5c00:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f0e5c04:	440b2000 */ 	mfc1	$t3,$f4
/*  f0e5c08:	00000000 */ 	nop
/*  f0e5c0c:	a44b0034 */ 	sh	$t3,0x34($v0)
/*  f0e5c10:	06410004 */ 	bgez	$s2,.L0f0e5c24
/*  f0e5c14:	324d0001 */ 	andi	$t5,$s2,0x1
/*  f0e5c18:	11a00002 */ 	beqz	$t5,.L0f0e5c24
/*  f0e5c1c:	00000000 */ 	nop
/*  f0e5c20:	25adfffe */ 	addiu	$t5,$t5,-2
.L0f0e5c24:
/*  f0e5c24:	000d7040 */ 	sll	$t6,$t5,0x1
/*  f0e5c28:	018e1821 */ 	addu	$v1,$t4,$t6
/*  f0e5c2c:	00037880 */ 	sll	$t7,$v1,0x2
/*  f0e5c30:	25e50004 */ 	addiu	$a1,$t7,0x4
/*  f0e5c34:	a04f0007 */ 	sb	$t7,0x7($v0)
/*  f0e5c38:	a0450013 */ 	sb	$a1,0x13($v0)
/*  f0e5c3c:	a085001f */ 	sb	$a1,0x1f($a0)
/*  f0e5c40:	a085002b */ 	sb	$a1,0x2b($a0)
/*  f0e5c44:	a0850037 */ 	sb	$a1,0x37($a0)
/*  f0e5c48:	8fb80150 */ 	lw	$t8,0x150($sp)
/*  f0e5c4c:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0e5c50:	afb90150 */ 	sw	$t9,0x150($sp)
/*  f0e5c54:	af090000 */ 	sw	$t1,0x0($t8)
/*  f0e5c58:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f0e5c5c:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f0e5c60:	8fa60080 */ 	lw	$a2,0x80($sp)
/*  f0e5c64:	3c0db100 */ 	lui	$t5,0xb100
/*  f0e5c68:	3c0c4030 */ 	lui	$t4,0x4030
/*  f0e5c6c:	acc20004 */ 	sw	$v0,0x4($a2)
/*  f0e5c70:	8faa0150 */ 	lw	$t2,0x150($sp)
/*  f0e5c74:	358c2010 */ 	ori	$t4,$t4,0x2010
/*  f0e5c78:	35ad1432 */ 	ori	$t5,$t5,0x1432
/*  f0e5c7c:	254b0008 */ 	addiu	$t3,$t2,0x8
/*  f0e5c80:	afab0150 */ 	sw	$t3,0x150($sp)
/*  f0e5c84:	ad4c0004 */ 	sw	$t4,0x4($t2)
/*  f0e5c88:	ad4d0000 */ 	sw	$t5,0x0($t2)
/*  f0e5c8c:	2652ffff */ 	addiu	$s2,$s2,-1
.L0f0e5c90:
/*  f0e5c90:	0641ff45 */ 	bgez	$s2,.L0f0e59a8
/*  f0e5c94:	2610fff4 */ 	addiu	$s0,$s0,-12
/*  f0e5c98:	0fc351e7 */ 	jal	func0f0d479c
/*  f0e5c9c:	8fa40150 */ 	lw	$a0,0x150($sp)
.L0f0e5ca0:
/*  f0e5ca0:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f0e5ca4:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f0e5ca8:	d7b60028 */ 	ldc1	$f22,0x28($sp)
/*  f0e5cac:	d7b80030 */ 	ldc1	$f24,0x30($sp)
/*  f0e5cb0:	d7ba0038 */ 	ldc1	$f26,0x38($sp)
/*  f0e5cb4:	d7bc0040 */ 	ldc1	$f28,0x40($sp)
/*  f0e5cb8:	d7be0048 */ 	ldc1	$f30,0x48($sp)
/*  f0e5cbc:	8fb00054 */ 	lw	$s0,0x54($sp)
/*  f0e5cc0:	8fb10058 */ 	lw	$s1,0x58($sp)
/*  f0e5cc4:	8fb2005c */ 	lw	$s2,0x5c($sp)
/*  f0e5cc8:	8fb30060 */ 	lw	$s3,0x60($sp)
/*  f0e5ccc:	03e00008 */ 	jr	$ra
/*  f0e5cd0:	27bd0150 */ 	addiu	$sp,$sp,0x150
/*  f0e5cd4:	00000000 */ 	nop
/*  f0e5cd8:	00000000 */ 	nop
/*  f0e5cdc:	00000000 */ 	nop
);
