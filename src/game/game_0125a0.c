#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_0125a0.h"
#include "game/game_013ee0.h"
#include "game/bondhead.h"
#include "game/game_157db0.h"
#include "game/pad.h"
#include "gvars/gvars.h"
#include "lib/lib_159b0.h"
#include "lib/lib_1a500.h"
#include "lib/lib_233c0.h"
#include "types.h"

GLOBAL_ASM(
glabel func0f0125a0
/*  f0125a0:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f0125a4:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f0125a8:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f0125ac:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f0125b0:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f0125b4:	00049c00 */ 	sll	$s3,$a0,0x10
/*  f0125b8:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0125bc:	afb50038 */ 	sw	$s5,0x38($sp)
/*  f0125c0:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f0125c4:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f0125c8:	00137403 */ 	sra	$t6,$s3,0x10
/*  f0125cc:	00a6082a */ 	slt	$at,$a1,$a2
/*  f0125d0:	01c09825 */ 	or	$s3,$t6,$zero
/*  f0125d4:	00e08025 */ 	or	$s0,$a3,$zero
/*  f0125d8:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0125dc:	00c09025 */ 	or	$s2,$a2,$zero
/*  f0125e0:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f0125e4:	ace00004 */ 	sw	$zero,0x4($a3)
/*  f0125e8:	1020001d */ 	beqz	$at,.L0f012660
/*  f0125ec:	ace00008 */ 	sw	$zero,0x8($a3)
/*  f0125f0:	3c148008 */ 	lui	$s4,%hi(stagethinglist_22e60)
/*  f0125f4:	2694ce40 */ 	addiu	$s4,$s4,%lo(stagethinglist_22e60)
/*  f0125f8:	27b50048 */ 	addiu	$s5,$sp,0x48
.L0f0125fc:
/*  f0125fc:	00133c00 */ 	sll	$a3,$s3,0x10
/*  f012600:	00077c03 */ 	sra	$t7,$a3,0x10
/*  f012604:	01e03825 */ 	or	$a3,$t7,$zero
/*  f012608:	00002025 */ 	or	$a0,$zero,$zero
/*  f01260c:	00002825 */ 	or	$a1,$zero,$zero
/*  f012610:	02803025 */ 	or	$a2,$s4,$zero
/*  f012614:	afb10010 */ 	sw	$s1,0x10($sp)
/*  f012618:	afb50014 */ 	sw	$s5,0x14($sp)
/*  f01261c:	0c009217 */ 	jal	func0002485c
/*  f012620:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f012624:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f012628:	87b90048 */ 	lh	$t9,0x48($sp)
/*  f01262c:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f012630:	8e0c0008 */ 	lw	$t4,0x8($s0)
/*  f012634:	03194021 */ 	addu	$t0,$t8,$t9
/*  f012638:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f01263c:	87aa004a */ 	lh	$t2,0x4a($sp)
/*  f012640:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f012644:	0232082a */ 	slt	$at,$s1,$s2
/*  f012648:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f01264c:	ae0b0004 */ 	sw	$t3,0x4($s0)
/*  f012650:	87ad004c */ 	lh	$t5,0x4c($sp)
/*  f012654:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f012658:	1420ffe8 */ 	bnez	$at,.L0f0125fc
/*  f01265c:	ae0e0008 */ 	sw	$t6,0x8($s0)
.L0f012660:
/*  f012660:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f012664:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f012668:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f01266c:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f012670:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f012674:	8fb40034 */ 	lw	$s4,0x34($sp)
/*  f012678:	8fb50038 */ 	lw	$s5,0x38($sp)
/*  f01267c:	03e00008 */ 	jr	$ra
/*  f012680:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

void currentPlayerInitAnimation(void)
{
	s32 i;

	func00022fa4(&g_Vars.currentplayer->model, &var8007c0c0, &g_Vars.currentplayer->unk0494, 0);
	animInitialise(g_Vars.currentplayer->model.anim);
	modelSetUnk14(&g_Vars.currentplayer->model, 0.1000000089407f);
	modelSetAnimPlaySpeed(&g_Vars.currentplayer->model, 1, 0);

	g_Vars.currentplayer->headanim = 0;
	g_Vars.currentplayer->headdamp = 0.93f;
	g_Vars.currentplayer->headwalkingtime60 = 0;
	g_Vars.currentplayer->headamplitude = 1;
	g_Vars.currentplayer->sideamplitude = 1;
	g_Vars.currentplayer->headpos.x = 0;
	g_Vars.currentplayer->headpos.y = 0;
	g_Vars.currentplayer->headpos.z = 0;
	g_Vars.currentplayer->headlook.x = 0;
	g_Vars.currentplayer->headlook.y = 0;
	g_Vars.currentplayer->headlook.z = 0;
	g_Vars.currentplayer->headup.x = 0;
	g_Vars.currentplayer->headup.y = 0;
	g_Vars.currentplayer->headup.z = 0;
	g_Vars.currentplayer->headpossum.x = 0;
	g_Vars.currentplayer->headpossum.y = 0;
	g_Vars.currentplayer->headpossum.z = 0;
	g_Vars.currentplayer->headlooksum.x = 0;
	g_Vars.currentplayer->headlooksum.y = 0;
	g_Vars.currentplayer->headlooksum.z = 14.285716056824f;
	g_Vars.currentplayer->headupsum.x = 0;
	g_Vars.currentplayer->headupsum.y = 14.285716056824f;
	g_Vars.currentplayer->headupsum.z = 0;
	g_Vars.currentplayer->resetheadpos = true;
	g_Vars.currentplayer->resetheadrot = true;
	g_Vars.currentplayer->unk03a8 = true;
	g_Vars.currentplayer->headbodyoffset.x = 0;
	g_Vars.currentplayer->headbodyoffset.y = 0;
	g_Vars.currentplayer->headbodyoffset.z = 0;
	g_Vars.currentplayer->standheight = 0;
	g_Vars.currentplayer->standbodyoffset.x = 0;
	g_Vars.currentplayer->standbodyoffset.y = 0;
	g_Vars.currentplayer->standbodyoffset.z = 0;
	g_Vars.currentplayer->standfrac = 0;
	g_Vars.currentplayer->standlook[0].x = 0;
	g_Vars.currentplayer->standlook[0].y = 0;
	g_Vars.currentplayer->standlook[0].z = 1;
	g_Vars.currentplayer->standlook[1].x = 0;
	g_Vars.currentplayer->standlook[1].y = 0;
	g_Vars.currentplayer->standlook[1].z = 1;
	g_Vars.currentplayer->standup[0].x = 0;
	g_Vars.currentplayer->standup[0].y = 1;
	g_Vars.currentplayer->standup[0].z = 0;
	g_Vars.currentplayer->standup[1].x = 0;
	g_Vars.currentplayer->standup[1].y = 1;
	g_Vars.currentplayer->standup[1].z = 0;
	g_Vars.currentplayer->standcnt = 0;

	for (i = 0; i < 2; i++) {
		s32 spc8[3];
		func0f0125a0(var80075c00[i].animnum, var80075c00[i].loopframe, var80075c00[i].endframe, spc8);
		var80075c00[i].unk0c = (spc8[2] * 0.1000000089407f) / (var80075c00[i].endframe - var80075c00[i].loopframe);
	}

	{
		struct objticksp476 sp88 = {NULL, 1, 3};
		Mtxf sp48;

		modelSetAnimation(&g_Vars.currentplayer->model, 1, 0, 0, 0.5f, 0);

		func0001b3bc(&g_Vars.currentplayer->model);
		func000159b0(&sp48);
		sp88.matrix = &sp48;
		sp88.unk10 = &g_Vars.currentplayer->unk0510;
		func0001cebc(&sp88, &g_Vars.currentplayer->model);

		g_Vars.currentplayer->standheight = g_Vars.currentplayer->unk0510.m[3][1];

		g_Vars.currentplayer->standbodyoffset.x = 0;
		g_Vars.currentplayer->standbodyoffset.y = g_Vars.currentplayer->unk0550.m[3][1] - g_Vars.currentplayer->unk0510.m[3][1];
		g_Vars.currentplayer->standbodyoffset.z = g_Vars.currentplayer->unk0550.m[3][2] - g_Vars.currentplayer->unk0510.m[3][2];

		modelSetAnimation(&g_Vars.currentplayer->model,
				var80075c00[g_Vars.currentplayer->headanim].animnum,
				0,
				var80075c00[g_Vars.currentplayer->headanim].loopframe,
				0.5f, 0);

		modelSetAnimLooping(&g_Vars.currentplayer->model,
				var80075c00[g_Vars.currentplayer->headanim].loopframe, 0);

		modelSetAnimEndFrame(&g_Vars.currentplayer->model,
				var80075c00[g_Vars.currentplayer->headanim].endframe);

		modelSetAnimFlipFunction(&g_Vars.currentplayer->model, currentPlayerFlipAnimation);

		currentPlayerUpdateIdleHeadRoll();
	}
}

GLOBAL_ASM(
glabel func0f012aa0
/*  f012aa0:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f012aa4:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f012aa8:	3c15800a */ 	lui	$s5,%hi(g_StageSetup)
/*  f012aac:	26b5d030 */ 	addiu	$s5,$s5,%lo(g_StageSetup)
/*  f012ab0:	8ea2001c */ 	lw	$v0,0x1c($s5)
/*  f012ab4:	3c04800a */ 	lui	$a0,%hi(g_PadsFile)
/*  f012ab8:	3c07800a */ 	lui	$a3,%hi(g_PadOffsets)
/*  f012abc:	24e72354 */ 	addiu	$a3,$a3,%lo(g_PadOffsets)
/*  f012ac0:	24842350 */ 	addiu	$a0,$a0,%lo(g_PadsFile)
/*  f012ac4:	244e0014 */ 	addiu	$t6,$v0,0x14
/*  f012ac8:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f012acc:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f012ad0:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f012ad4:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f012ad8:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f012adc:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f012ae0:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f012ae4:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f012ae8:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f012aec:	f7b40020 */ 	sdc1	$f20,0x20($sp)
/*  f012af0:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f012af4:	ac820000 */ 	sw	$v0,0x0($a0)
/*  f012af8:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f012afc:	00009025 */ 	or	$s2,$zero,$zero
/*  f012b00:	0000a025 */ 	or	$s4,$zero,$zero
/*  f012b04:	1900005e */ 	blez	$t0,.L0f012c80
/*  f012b08:	00401825 */ 	or	$v1,$v0,$zero
/*  f012b0c:	3c013f80 */ 	lui	$at,0x3f80
/*  f012b10:	4481a000 */ 	mtc1	$at,$f20
/*  f012b14:	afa80120 */ 	sw	$t0,0x120($sp)
/*  f012b18:	241effff */ 	addiu	$s8,$zero,-1
/*  f012b1c:	27b70064 */ 	addiu	$s7,$sp,0x64
/*  f012b20:	27b60090 */ 	addiu	$s6,$sp,0x90
/*  f012b24:	27b300c8 */ 	addiu	$s3,$sp,0xc8
.L0f012b28:
/*  f012b28:	3c07800a */ 	lui	$a3,%hi(g_PadOffsets)
/*  f012b2c:	24e72354 */ 	addiu	$a3,$a3,%lo(g_PadOffsets)
/*  f012b30:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f012b34:	8eb9001c */ 	lw	$t9,0x1c($s5)
/*  f012b38:	02402025 */ 	or	$a0,$s2,$zero
/*  f012b3c:	01f4c021 */ 	addu	$t8,$t7,$s4
/*  f012b40:	97020000 */ 	lhu	$v0,0x0($t8)
/*  f012b44:	24050022 */ 	addiu	$a1,$zero,0x22
/*  f012b48:	02603025 */ 	or	$a2,$s3,$zero
/*  f012b4c:	0fc456ac */ 	jal	padUnpack
/*  f012b50:	03228821 */ 	addu	$s1,$t9,$v0
/*  f012b54:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f012b58:	00008025 */ 	or	$s0,$zero,$zero
/*  f012b5c:	02602025 */ 	or	$a0,$s3,$zero
/*  f012b60:	00095480 */ 	sll	$t2,$t1,0x12
/*  f012b64:	000a5d83 */ 	sra	$t3,$t2,0x16
/*  f012b68:	05610023 */ 	bgez	$t3,.L0f012bf8
/*  f012b6c:	02c02825 */ 	or	$a1,$s6,$zero
/*  f012b70:	02e03025 */ 	or	$a2,$s7,$zero
/*  f012b74:	24070014 */ 	addiu	$a3,$zero,0x14
/*  f012b78:	0fc58865 */ 	jal	func0f162194
/*  f012b7c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f012b80:	87ac0090 */ 	lh	$t4,0x90($sp)
/*  f012b84:	87ad0064 */ 	lh	$t5,0x64($sp)
/*  f012b88:	02602025 */ 	or	$a0,$s3,$zero
/*  f012b8c:	13cc0003 */ 	beq	$s8,$t4,.L0f012b9c
/*  f012b90:	00000000 */ 	nop
/*  f012b94:	10000004 */ 	b	.L0f012ba8
/*  f012b98:	02c08025 */ 	or	$s0,$s6,$zero
.L0f012b9c:
/*  f012b9c:	13cd0002 */ 	beq	$s8,$t5,.L0f012ba8
/*  f012ba0:	00000000 */ 	nop
/*  f012ba4:	02e08025 */ 	or	$s0,$s7,$zero
.L0f012ba8:
/*  f012ba8:	52000014 */ 	beqzl	$s0,.L0f012bfc
/*  f012bac:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f012bb0:	0c00a900 */ 	jal	func0002a400
/*  f012bb4:	02002825 */ 	or	$a1,$s0,$zero
/*  f012bb8:	58400009 */ 	blezl	$v0,.L0f012be0
/*  f012bbc:	860e0000 */ 	lh	$t6,0x0($s0)
/*  f012bc0:	86290002 */ 	lh	$t1,0x2($s1)
/*  f012bc4:	0002c100 */ 	sll	$t8,$v0,0x4
/*  f012bc8:	33193ff0 */ 	andi	$t9,$t8,0x3ff0
/*  f012bcc:	312ac00f */ 	andi	$t2,$t1,0xc00f
/*  f012bd0:	032a5825 */ 	or	$t3,$t9,$t2
/*  f012bd4:	10000008 */ 	b	.L0f012bf8
/*  f012bd8:	a62b0002 */ 	sh	$t3,0x2($s1)
/*  f012bdc:	860e0000 */ 	lh	$t6,0x0($s0)
.L0f012be0:
/*  f012be0:	86290002 */ 	lh	$t1,0x2($s1)
/*  f012be4:	000e7900 */ 	sll	$t7,$t6,0x4
/*  f012be8:	31f83ff0 */ 	andi	$t8,$t7,0x3ff0
/*  f012bec:	3139c00f */ 	andi	$t9,$t1,0xc00f
/*  f012bf0:	03195025 */ 	or	$t2,$t8,$t9
/*  f012bf4:	a62a0002 */ 	sh	$t2,0x2($s1)
.L0f012bf8:
/*  f012bf8:	8e2b0000 */ 	lw	$t3,0x0($s1)
.L0f012bfc:
/*  f012bfc:	c7a400f8 */ 	lwc1	$f4,0xf8($sp)
/*  f012c00:	000b6382 */ 	srl	$t4,$t3,0xe
/*  f012c04:	318d0200 */ 	andi	$t5,$t4,0x200
/*  f012c08:	51a00016 */ 	beqzl	$t5,.L0f012c64
/*  f012c0c:	8fae0120 */ 	lw	$t6,0x120($sp)
/*  f012c10:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f012c14:	c7a800fc */ 	lwc1	$f8,0xfc($sp)
/*  f012c18:	c7b00100 */ 	lwc1	$f16,0x100($sp)
/*  f012c1c:	c7a40104 */ 	lwc1	$f4,0x104($sp)
/*  f012c20:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f012c24:	c7a80108 */ 	lwc1	$f8,0x108($sp)
/*  f012c28:	02402025 */ 	or	$a0,$s2,$zero
/*  f012c2c:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f012c30:	e7a600f8 */ 	swc1	$f6,0xf8($sp)
/*  f012c34:	c7b0010c */ 	lwc1	$f16,0x10c($sp)
/*  f012c38:	46142182 */ 	mul.s	$f6,$f4,$f20
/*  f012c3c:	e7aa00fc */ 	swc1	$f10,0xfc($sp)
/*  f012c40:	02602825 */ 	or	$a1,$s3,$zero
/*  f012c44:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f012c48:	e7b20100 */ 	swc1	$f18,0x100($sp)
/*  f012c4c:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f012c50:	e7a60104 */ 	swc1	$f6,0x104($sp)
/*  f012c54:	e7aa0108 */ 	swc1	$f10,0x108($sp)
/*  f012c58:	0fc45864 */ 	jal	padCopyBboxFromPad
/*  f012c5c:	e7b2010c */ 	swc1	$f18,0x10c($sp)
/*  f012c60:	8fae0120 */ 	lw	$t6,0x120($sp)
.L0f012c64:
/*  f012c64:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f012c68:	26940002 */ 	addiu	$s4,$s4,0x2
/*  f012c6c:	164effae */ 	bne	$s2,$t6,.L0f012b28
/*  f012c70:	00000000 */ 	nop
/*  f012c74:	3c03800a */ 	lui	$v1,%hi(g_PadsFile)
/*  f012c78:	8c632350 */ 	lw	$v1,%lo(g_PadsFile)($v1)
/*  f012c7c:	8ea2001c */ 	lw	$v0,0x1c($s5)
.L0f012c80:
/*  f012c80:	8c6f0008 */ 	lw	$t7,0x8($v1)
/*  f012c84:	004f4821 */ 	addu	$t1,$v0,$t7
/*  f012c88:	aea90000 */ 	sw	$t1,0x0($s5)
/*  f012c8c:	8c78000c */ 	lw	$t8,0xc($v1)
/*  f012c90:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f012c94:	aeb90004 */ 	sw	$t9,0x4($s5)
/*  f012c98:	8c6a0010 */ 	lw	$t2,0x10($v1)
/*  f012c9c:	004a5821 */ 	addu	$t3,$v0,$t2
/*  f012ca0:	11600003 */ 	beqz	$t3,.L0f012cb0
/*  f012ca4:	aeab0008 */ 	sw	$t3,0x8($s5)
/*  f012ca8:	0fc050ba */ 	jal	func0f0142e8
/*  f012cac:	00000000 */ 	nop
.L0f012cb0:
/*  f012cb0:	8ea20000 */ 	lw	$v0,0x0($s5)
/*  f012cb4:	8c4d0000 */ 	lw	$t5,0x0($v0)
/*  f012cb8:	05a20009 */ 	bltzl	$t5,.L0f012ce0
/*  f012cbc:	8ea20004 */ 	lw	$v0,0x4($s5)
.L0f012cc0:
/*  f012cc0:	8eae001c */ 	lw	$t6,0x1c($s5)
/*  f012cc4:	8c4f0004 */ 	lw	$t7,0x4($v0)
/*  f012cc8:	8c580010 */ 	lw	$t8,0x10($v0)
/*  f012ccc:	24420010 */ 	addiu	$v0,$v0,0x10
/*  f012cd0:	01cf4821 */ 	addu	$t1,$t6,$t7
/*  f012cd4:	0701fffa */ 	bgez	$t8,.L0f012cc0
/*  f012cd8:	ac49fff4 */ 	sw	$t1,-0xc($v0)
/*  f012cdc:	8ea20004 */ 	lw	$v0,0x4($s5)
.L0f012ce0:
/*  f012ce0:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f012ce4:	5060000c */ 	beqzl	$v1,.L0f012d18
/*  f012ce8:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f012cec:
/*  f012cec:	8eb9001c */ 	lw	$t9,0x1c($s5)
/*  f012cf0:	8c4c0004 */ 	lw	$t4,0x4($v0)
/*  f012cf4:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f012cf8:	03235021 */ 	addu	$t2,$t9,$v1
/*  f012cfc:	ac4afff4 */ 	sw	$t2,-0xc($v0)
/*  f012d00:	8eab001c */ 	lw	$t3,0x1c($s5)
/*  f012d04:	8c430000 */ 	lw	$v1,0x0($v0)
/*  f012d08:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f012d0c:	1460fff7 */ 	bnez	$v1,.L0f012cec
/*  f012d10:	ac4dfff8 */ 	sw	$t5,-0x8($v0)
/*  f012d14:	8fbf004c */ 	lw	$ra,0x4c($sp)
.L0f012d18:
/*  f012d18:	d7b40020 */ 	ldc1	$f20,0x20($sp)
/*  f012d1c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f012d20:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f012d24:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f012d28:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f012d2c:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f012d30:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f012d34:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f012d38:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f012d3c:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f012d40:	03e00008 */ 	jr	$ra
/*  f012d44:	27bd0130 */ 	addiu	$sp,$sp,0x130
/*  f012d48:	00000000 */ 	nop
/*  f012d4c:	00000000 */ 	nop
);
