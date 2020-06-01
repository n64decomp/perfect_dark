#include <ultra64.h>
#include "constants.h"
#include "game/bondmove.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "game/game_096b20.h"
#include "game/game_113220.h"
#include "gvars/gvars.h"
#include "lib/lib_12dc0.h"
#include "lib/lib_159b0.h"
#include "lib/lib_1a500.h"
#include "lib/lib_233c0.h"
#include "types.h"

struct var80075c00 var80075c00[] = {
	{ 43, 9.5, 27, 0, 0,   1.5 },
	{ 41, 7.5, 17, 0, 1.5, 100 },
};

u32 var80075c30 = 0x00000000;
u32 var80075c34 = 0x00000000;
u32 var80075c38 = 0x00000000;
u32 var80075c3c = 0x00000000;
u32 var80075c40 = 0x00000000;
u32 var80075c44 = 0x3f800000;
u32 var80075c48 = 0x00000000;
u32 var80075c4c = 0x3f800000;
u32 var80075c50 = 0x00000000;
u32 var80075c54 = 0x00000000;
u32 var80075c58 = 0x00000001;
u32 var80075c5c = 0x00000003;
u32 var80075c60 = 0x00000000;
u32 var80075c64 = 0x00000000;
u32 var80075c68 = 0x00000000;
u32 var80075c6c = 0x00000000;
u32 var80075c70 = 0x00000000;
u32 var80075c74 = 0x00000000;
u32 var80075c78 = 0x00000000;
u32 var80075c7c = 0x00000000;
u32 var80075c80 = 0x00000000;
u32 var80075c84 = 0x00000000;
u32 var80075c88 = 0x00000000;
u32 var80075c8c = 0x00000000;
u32 var80075c90 = 0x00000000;
u32 var80075c94 = 0x00000000;
u32 var80075c98 = 0x00000000;
u32 var80075c9c = 0x00000000;

void currentPlayerFlipAnimation(void)
{
	g_Vars.currentplayer->model.anim->flip = !g_Vars.currentplayer->model.anim->flip;
}

void currentPlayerUpdateIdleHeadRoll(void)
{
	f32 mult = 1.0f / U32_MAX;

	g_Vars.currentplayer->standlook[g_Vars.currentplayer->standcnt].x = ((f32)random() * mult - 0.5f) * 0.02f;
	g_Vars.currentplayer->standlook[g_Vars.currentplayer->standcnt].z = 1;
	g_Vars.currentplayer->standup[g_Vars.currentplayer->standcnt].x = ((f32)random() * mult - 0.5f) * 0.02f;
	g_Vars.currentplayer->standup[g_Vars.currentplayer->standcnt].y = 1;

	if (g_Vars.currentplayer->standcnt) {
		g_Vars.currentplayer->standlook[g_Vars.currentplayer->standcnt].y = (f32)random() * mult * 0.01f;
		g_Vars.currentplayer->standup[g_Vars.currentplayer->standcnt].z = (f32)random() * mult * -0.01f;
	} else {
		g_Vars.currentplayer->standlook[g_Vars.currentplayer->standcnt].y = (f32)random() * mult * -0.01f;
		g_Vars.currentplayer->standup[g_Vars.currentplayer->standcnt].z = (f32)random() * mult * 0.01f;
	}

	g_Vars.currentplayer->standcnt = 1 - g_Vars.currentplayer->standcnt;
}

void currentPlayerUpdateHeadPos(struct coord *vel)
{
	s32 i;

	if (g_Vars.currentplayer->resetheadpos) {
		g_Vars.currentplayer->headpossum.x = 0;
		g_Vars.currentplayer->headpossum.y = vel->y / 0.018000006f;
		g_Vars.currentplayer->headpossum.z = 0;

		g_Vars.currentplayer->resetheadpos = false;
	}

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		g_Vars.currentplayer->headpossum.x = vel->x + 0.982f * g_Vars.currentplayer->headpossum.x;
		g_Vars.currentplayer->headpossum.y = vel->y + 0.982f * g_Vars.currentplayer->headpossum.y;
		g_Vars.currentplayer->headpossum.z = vel->z + 0.982f * g_Vars.currentplayer->headpossum.z;
	}

	g_Vars.currentplayer->headpos.x = g_Vars.currentplayer->headpossum.x * 0.018000006f;
	g_Vars.currentplayer->headpos.y = g_Vars.currentplayer->headpossum.y * 0.018000006f;
	g_Vars.currentplayer->headpos.z = g_Vars.currentplayer->headpossum.z * 0.018000006f;
}

void currentPlayerUpdateHeadRot(struct coord *lookvel, struct coord *upvel)
{
	s32 i;

	if (g_Vars.currentplayer->resetheadrot) {
		g_Vars.currentplayer->headlooksum.x = lookvel->x / (1.0f - g_Vars.currentplayer->headamp);
		g_Vars.currentplayer->headlooksum.y = lookvel->y / (1.0f - g_Vars.currentplayer->headamp);
		g_Vars.currentplayer->headlooksum.z = lookvel->z / (1.0f - g_Vars.currentplayer->headamp);
		g_Vars.currentplayer->headupsum.x = upvel->x / (1.0f - g_Vars.currentplayer->headamp);
		g_Vars.currentplayer->headupsum.y = upvel->y / (1.0f - g_Vars.currentplayer->headamp);
		g_Vars.currentplayer->headupsum.z = upvel->z / (1.0f - g_Vars.currentplayer->headamp);

		g_Vars.currentplayer->resetheadrot = false;
	}

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		g_Vars.currentplayer->headlooksum.x = lookvel->x + g_Vars.currentplayer->headamp * g_Vars.currentplayer->headlooksum.x;
		g_Vars.currentplayer->headlooksum.y = lookvel->y + g_Vars.currentplayer->headamp * g_Vars.currentplayer->headlooksum.y;
		g_Vars.currentplayer->headlooksum.z = lookvel->z + g_Vars.currentplayer->headamp * g_Vars.currentplayer->headlooksum.z;
		g_Vars.currentplayer->headupsum.x = upvel->x + g_Vars.currentplayer->headamp * g_Vars.currentplayer->headupsum.x;
		g_Vars.currentplayer->headupsum.y = upvel->y + g_Vars.currentplayer->headamp * g_Vars.currentplayer->headupsum.y;
		g_Vars.currentplayer->headupsum.z = upvel->z + g_Vars.currentplayer->headamp * g_Vars.currentplayer->headupsum.z;
	}

	g_Vars.currentplayer->headlook.x = g_Vars.currentplayer->headlooksum.x * (1.0f - g_Vars.currentplayer->headamp);
	g_Vars.currentplayer->headlook.y = g_Vars.currentplayer->headlooksum.y * (1.0f - g_Vars.currentplayer->headamp);
	g_Vars.currentplayer->headlook.z = g_Vars.currentplayer->headlooksum.z * (1.0f - g_Vars.currentplayer->headamp);
	g_Vars.currentplayer->headup.x = g_Vars.currentplayer->headupsum.x * (1.0f - g_Vars.currentplayer->headamp);
	g_Vars.currentplayer->headup.y = g_Vars.currentplayer->headupsum.y * (1.0f - g_Vars.currentplayer->headamp);
	g_Vars.currentplayer->headup.z = g_Vars.currentplayer->headupsum.z * (1.0f - g_Vars.currentplayer->headamp);
}

void currentPlayerSetHeadAmp(f32 headamp)
{
	if (headamp != g_Vars.currentplayer->headamp) {
		f32 divisor = 1.0f - headamp;
		g_Vars.currentplayer->headlooksum.x = (g_Vars.currentplayer->headlooksum.x * (1.0f - g_Vars.currentplayer->headamp)) / divisor;
		g_Vars.currentplayer->headlooksum.y = (g_Vars.currentplayer->headlooksum.y * (1.0f - g_Vars.currentplayer->headamp)) / divisor;
		g_Vars.currentplayer->headlooksum.z = (g_Vars.currentplayer->headlooksum.z * (1.0f - g_Vars.currentplayer->headamp)) / divisor;
		g_Vars.currentplayer->headupsum.x = (g_Vars.currentplayer->headupsum.x * (1.0f - g_Vars.currentplayer->headamp)) / divisor;
		g_Vars.currentplayer->headupsum.y = (g_Vars.currentplayer->headupsum.y * (1.0f - g_Vars.currentplayer->headamp)) / divisor;
		g_Vars.currentplayer->headupsum.z = (g_Vars.currentplayer->headupsum.z * (1.0f - g_Vars.currentplayer->headamp)) / divisor;
		g_Vars.currentplayer->headamp = headamp;
	}
}

GLOBAL_ASM(
glabel func0f1138a4
.late_rodata
glabel var7f1b3a44
.word 0x3f333333
glabel var7f1b3a48
.word 0x3dcccccd
glabel var7f1b3a4c
.word 0x3f19999a
glabel var7f1b3a50
.word 0x3f199999
glabel var7f1b3a54
.word 0x3ecccccd
glabel var7f1b3a58
.word 0x3ecccccd
glabel var7f1b3a5c
.word 0x3f666666
glabel var7f1b3a60
.word 0x3f7b645a
glabel var7f1b3a64
.word 0x3f7f5b81
glabel var7f1b3a68
.word 0x3f75c28f
glabel var7f1b3a6c
.word 0x3f7f5b81
glabel var7f1b3a70
.word 0x3cccccce
glabel var7f1b3a74
.word 0x3c088889
.text
/*  f1138a4:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f1138a8:	3c0f8007 */ 	lui	$t7,%hi(var80075c30)
/*  f1138ac:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1138b0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1138b4:	e7ac00e8 */ 	swc1	$f12,0xe8($sp)
/*  f1138b8:	e7ae00ec */ 	swc1	$f14,0xec($sp)
/*  f1138bc:	25ef5c30 */ 	addiu	$t7,$t7,%lo(var80075c30)
/*  f1138c0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1138c4:	27ae00dc */ 	addiu	$t6,$sp,0xdc
/*  f1138c8:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1138cc:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1138d0:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1138d4:	3c0a8007 */ 	lui	$t2,%hi(var80075c3c)
/*  f1138d8:	254a5c3c */ 	addiu	$t2,$t2,%lo(var80075c3c)
/*  f1138dc:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1138e0:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1138e4:	8d410000 */ 	lw	$at,0x0($t2)
/*  f1138e8:	27a900d0 */ 	addiu	$t1,$sp,0xd0
/*  f1138ec:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*  f1138f0:	ad210000 */ 	sw	$at,0x0($t1)
/*  f1138f4:	8d410008 */ 	lw	$at,0x8($t2)
/*  f1138f8:	3c188007 */ 	lui	$t8,%hi(var80075c48)
/*  f1138fc:	27185c48 */ 	addiu	$t8,$t8,%lo(var80075c48)
/*  f113900:	ad2d0004 */ 	sw	$t5,0x4($t1)
/*  f113904:	ad210008 */ 	sw	$at,0x8($t1)
/*  f113908:	8f010000 */ 	lw	$at,0x0($t8)
/*  f11390c:	27b900c4 */ 	addiu	$t9,$sp,0xc4
/*  f113910:	8f080004 */ 	lw	$t0,0x4($t8)
/*  f113914:	af210000 */ 	sw	$at,0x0($t9)
/*  f113918:	8f010008 */ 	lw	$at,0x8($t8)
/*  f11391c:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f113920:	44802000 */ 	mtc1	$zero,$f4
/*  f113924:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f113928:	af280004 */ 	sw	$t0,0x4($t9)
/*  f11392c:	af210008 */ 	sw	$at,0x8($t9)
/*  f113930:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f113934:	e7a400c0 */ 	swc1	$f4,0xc0($sp)
/*  f113938:	8d8b047c */ 	lw	$t3,0x47c($t4)
/*  f11393c:	0c008de5 */ 	jal	func00023794
/*  f113940:	85640000 */ 	lh	$a0,0x0($t3)
/*  f113944:	50400088 */ 	beqzl	$v0,.L0f113b68
/*  f113948:	44800000 */ 	mtc1	$zero,$f0
/*  f11394c:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f113950:	0c0074a2 */ 	jal	func0001d288
/*  f113954:	2484045c */ 	addiu	$a0,$a0,0x45c
/*  f113958:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f11395c:	e7a000c0 */ 	swc1	$f0,0xc0($sp)
/*  f113960:	3c0d8007 */ 	lui	$t5,%hi(var80075c54)
/*  f113964:	8c4303ac */ 	lw	$v1,0x3ac($v0)
/*  f113968:	25ad5c54 */ 	addiu	$t5,$t5,%lo(var80075c54)
/*  f11396c:	25ae003c */ 	addiu	$t6,$t5,0x3c
/*  f113970:	14600024 */ 	bnez	$v1,.L0f113a04
/*  f113974:	27aa0080 */ 	addiu	$t2,$sp,0x80
/*  f113978:	3c017f1b */ 	lui	$at,%hi(var7f1b3a44)
/*  f11397c:	c4263a44 */ 	lwc1	$f6,%lo(var7f1b3a44)($at)
/*  f113980:	3c017f1b */ 	lui	$at,%hi(var7f1b3a48)
/*  f113984:	4600303c */ 	c.lt.s	$f6,$f0
/*  f113988:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11398c:	45000005 */ 	bc1f	.L0f1139a4
/*  f113990:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113994:	3c013f80 */ 	lui	$at,0x3f80
/*  f113998:	44814000 */ 	mtc1	$at,$f8
/*  f11399c:	10000015 */ 	beqz	$zero,.L0f1139f4
/*  f1139a0:	e44803b8 */ 	swc1	$f8,0x3b8($v0)
.L0f1139a4:
/*  f1139a4:	c4223a48 */ 	lwc1	$f2,%lo(var7f1b3a48)($at)
/*  f1139a8:	3c017f1b */ 	lui	$at,%hi(var7f1b3a58)
/*  f1139ac:	4600103c */ 	c.lt.s	$f2,$f0
/*  f1139b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1139b4:	4500000d */ 	bc1f	.L0f1139ec
/*  f1139b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1139bc:	46020281 */ 	sub.s	$f10,$f0,$f2
/*  f1139c0:	3c017f1b */ 	lui	$at,%hi(var7f1b3a4c)
/*  f1139c4:	c4303a4c */ 	lwc1	$f16,%lo(var7f1b3a4c)($at)
/*  f1139c8:	3c017f1b */ 	lui	$at,%hi(var7f1b3a50)
/*  f1139cc:	c4243a50 */ 	lwc1	$f4,%lo(var7f1b3a50)($at)
/*  f1139d0:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f1139d4:	3c017f1b */ 	lui	$at,%hi(var7f1b3a54)
/*  f1139d8:	c4283a54 */ 	lwc1	$f8,%lo(var7f1b3a54)($at)
/*  f1139dc:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f1139e0:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f1139e4:	10000003 */ 	beqz	$zero,.L0f1139f4
/*  f1139e8:	e44a03b8 */ 	swc1	$f10,0x3b8($v0)
.L0f1139ec:
/*  f1139ec:	c4303a58 */ 	lwc1	$f16,%lo(var7f1b3a58)($at)
/*  f1139f0:	e45003b8 */ 	swc1	$f16,0x3b8($v0)
.L0f1139f4:
/*  f1139f4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f1139f8:	c45203b8 */ 	lwc1	$f18,0x3b8($v0)
/*  f1139fc:	10000012 */ 	beqz	$zero,.L0f113a48
/*  f113a00:	e45203bc */ 	swc1	$f18,0x3bc($v0)
.L0f113a04:
/*  f113a04:	24010001 */ 	addiu	$at,$zero,0x1
/*  f113a08:	14610008 */ 	bne	$v1,$at,.L0f113a2c
/*  f113a0c:	3c017f1b */ 	lui	$at,%hi(var7f1b3a5c)
/*  f113a10:	c4243a5c */ 	lwc1	$f4,%lo(var7f1b3a5c)($at)
/*  f113a14:	3c013f00 */ 	lui	$at,0x3f00
/*  f113a18:	44813000 */ 	mtc1	$at,$f6
/*  f113a1c:	e44403b8 */ 	swc1	$f4,0x3b8($v0)
/*  f113a20:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f113a24:	10000008 */ 	beqz	$zero,.L0f113a48
/*  f113a28:	e52603bc */ 	swc1	$f6,0x3bc($t1)
.L0f113a2c:
/*  f113a2c:	3c013f80 */ 	lui	$at,0x3f80
/*  f113a30:	44814000 */ 	mtc1	$at,$f8
/*  f113a34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113a38:	e44803b8 */ 	swc1	$f8,0x3b8($v0)
/*  f113a3c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113a40:	c44a03b8 */ 	lwc1	$f10,0x3b8($v0)
/*  f113a44:	e44a03bc */ 	swc1	$f10,0x3bc($v0)
.L0f113a48:
/*  f113a48:	8da10000 */ 	lw	$at,0x0($t5)
/*  f113a4c:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f113a50:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f113a54:	ad41fff4 */ 	sw	$at,-0xc($t2)
/*  f113a58:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*  f113a5c:	ad41fff8 */ 	sw	$at,-0x8($t2)
/*  f113a60:	8da1fffc */ 	lw	$at,-0x4($t5)
/*  f113a64:	15aefff8 */ 	bne	$t5,$t6,.L0f113a48
/*  f113a68:	ad41fffc */ 	sw	$at,-0x4($t2)
/*  f113a6c:	8da10000 */ 	lw	$at,0x0($t5)
/*  f113a70:	3c188007 */ 	lui	$t8,%hi(var80075c94)
/*  f113a74:	27185c94 */ 	addiu	$t8,$t8,%lo(var80075c94)
/*  f113a78:	ad410000 */ 	sw	$at,0x0($t2)
/*  f113a7c:	8f010000 */ 	lw	$at,0x0($t8)
/*  f113a80:	27b90034 */ 	addiu	$t9,$sp,0x34
/*  f113a84:	8f0c0004 */ 	lw	$t4,0x4($t8)
/*  f113a88:	af210000 */ 	sw	$at,0x0($t9)
/*  f113a8c:	8f010008 */ 	lw	$at,0x8($t8)
/*  f113a90:	af2c0004 */ 	sw	$t4,0x4($t9)
/*  f113a94:	0c0078aa */ 	jal	func0001e2a8
/*  f113a98:	af210008 */ 	sw	$at,0x8($t9)
/*  f113a9c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f113aa0:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f113aa4:	00002025 */ 	or	$a0,$zero,$zero
/*  f113aa8:	0c0078a7 */ 	jal	func0001e29c
/*  f113aac:	ad6003a8 */ 	sw	$zero,0x3a8($t3)
/*  f113ab0:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f113ab4:	8e050034 */ 	lw	$a1,0x34($s0)
/*  f113ab8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f113abc:	0c007b86 */ 	jal	func0001ee18
/*  f113ac0:	2484045c */ 	addiu	$a0,$a0,0x45c
/*  f113ac4:	0c0078a7 */ 	jal	func0001e29c
/*  f113ac8:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f113acc:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f113ad0:	0c006cef */ 	jal	func0001b3bc
/*  f113ad4:	2484045c */ 	addiu	$a0,$a0,0x45c
/*  f113ad8:	0c00566c */ 	jal	func000159b0
/*  f113adc:	27a40040 */ 	addiu	$a0,$sp,0x40
/*  f113ae0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113ae4:	27a90040 */ 	addiu	$t1,$sp,0x40
/*  f113ae8:	afa90080 */ 	sw	$t1,0x80($sp)
/*  f113aec:	244f0510 */ 	addiu	$t7,$v0,0x510
/*  f113af0:	afaf0090 */ 	sw	$t7,0x90($sp)
/*  f113af4:	27a40080 */ 	addiu	$a0,$sp,0x80
/*  f113af8:	0c0073af */ 	jal	func0001cebc
/*  f113afc:	2445045c */ 	addiu	$a1,$v0,0x45c
/*  f113b00:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113b04:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f113b08:	c4500418 */ 	lwc1	$f16,0x418($v0)
/*  f113b0c:	e4500408 */ 	swc1	$f16,0x408($v0)
/*  f113b10:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113b14:	c452041c */ 	lwc1	$f18,0x41c($v0)
/*  f113b18:	e452040c */ 	swc1	$f18,0x40c($v0)
/*  f113b1c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113b20:	c4440420 */ 	lwc1	$f4,0x420($v0)
/*  f113b24:	e4440410 */ 	swc1	$f4,0x410($v0)
/*  f113b28:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f113b2c:	0c006b43 */ 	jal	func0001ad0c
/*  f113b30:	2484045c */ 	addiu	$a0,$a0,0x45c
/*  f113b34:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113b38:	c7a60034 */ 	lwc1	$f6,0x34($sp)
/*  f113b3c:	c7b0003c */ 	lwc1	$f16,0x3c($sp)
/*  f113b40:	c4480540 */ 	lwc1	$f8,0x540($v0)
/*  f113b44:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f113b48:	2444045c */ 	addiu	$a0,$v0,0x45c
/*  f113b4c:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f113b50:	e7aa0034 */ 	swc1	$f10,0x34($sp)
/*  f113b54:	c4520548 */ 	lwc1	$f18,0x548($v0)
/*  f113b58:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f113b5c:	0c006b4d */ 	jal	func0001ad34
/*  f113b60:	e7a4003c */ 	swc1	$f4,0x3c($sp)
/*  f113b64:	44800000 */ 	mtc1	$zero,$f0
.L0f113b68:
/*  f113b68:	c7a600c0 */ 	lwc1	$f6,0xc0($sp)
/*  f113b6c:	4606003c */ 	c.lt.s	$f0,$f6
/*  f113b70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113b74:	4502006d */ 	bc1fl	.L0f113d2c
/*  f113b78:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113b7c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113b80:	c7aa00ec */ 	lwc1	$f10,0xec($sp)
/*  f113b84:	c4480540 */ 	lwc1	$f8,0x540($v0)
/*  f113b88:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f113b8c:	e4500540 */ 	swc1	$f16,0x540($v0)
/*  f113b90:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113b94:	c7a400e8 */ 	lwc1	$f4,0xe8($sp)
/*  f113b98:	c4520548 */ 	lwc1	$f18,0x548($v0)
/*  f113b9c:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f113ba0:	e4460548 */ 	swc1	$f6,0x548($v0)
/*  f113ba4:	8e0e0034 */ 	lw	$t6,0x34($s0)
/*  f113ba8:	59c0000c */ 	blezl	$t6,.L0f113bdc
/*  f113bac:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113bb0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113bb4:	c60a004c */ 	lwc1	$f10,0x4c($s0)
/*  f113bb8:	c4480540 */ 	lwc1	$f8,0x540($v0)
/*  f113bbc:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f113bc0:	e4500540 */ 	swc1	$f16,0x540($v0)
/*  f113bc4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113bc8:	c604004c */ 	lwc1	$f4,0x4c($s0)
/*  f113bcc:	c4520548 */ 	lwc1	$f18,0x548($v0)
/*  f113bd0:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f113bd4:	e4460548 */ 	swc1	$f6,0x548($v0)
/*  f113bd8:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f113bdc:
/*  f113bdc:	c4480540 */ 	lwc1	$f8,0x540($v0)
/*  f113be0:	c44a03b8 */ 	lwc1	$f10,0x3b8($v0)
/*  f113be4:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f113be8:	e7b000dc */ 	swc1	$f16,0xdc($sp)
/*  f113bec:	c4520544 */ 	lwc1	$f18,0x544($v0)
/*  f113bf0:	c4400414 */ 	lwc1	$f0,0x414($v0)
/*  f113bf4:	c44603b8 */ 	lwc1	$f6,0x3b8($v0)
/*  f113bf8:	46009101 */ 	sub.s	$f4,$f18,$f0
/*  f113bfc:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f113c00:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f113c04:	e7aa00e0 */ 	swc1	$f10,0xe0($sp)
/*  f113c08:	c45203b8 */ 	lwc1	$f18,0x3b8($v0)
/*  f113c0c:	c4500548 */ 	lwc1	$f16,0x548($v0)
/*  f113c10:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f113c14:	e7a400e4 */ 	swc1	$f4,0xe4($sp)
/*  f113c18:	8c4d03ac */ 	lw	$t5,0x3ac($v0)
/*  f113c1c:	05a20032 */ 	bltzl	$t5,.L0f113ce8
/*  f113c20:	c4520530 */ 	lwc1	$f18,0x530($v0)
/*  f113c24:	c4460530 */ 	lwc1	$f6,0x530($v0)
/*  f113c28:	c44803bc */ 	lwc1	$f8,0x3bc($v0)
/*  f113c2c:	3c013f80 */ 	lui	$at,0x3f80
/*  f113c30:	44810000 */ 	mtc1	$at,$f0
/*  f113c34:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f113c38:	8e080038 */ 	lw	$t0,0x38($s0)
/*  f113c3c:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
/*  f113c40:	c45203b8 */ 	lwc1	$f18,0x3b8($v0)
/*  f113c44:	c4500534 */ 	lwc1	$f16,0x534($v0)
/*  f113c48:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f113c4c:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
/*  f113c50:	c4460538 */ 	lwc1	$f6,0x538($v0)
/*  f113c54:	c44a03b8 */ 	lwc1	$f10,0x3b8($v0)
/*  f113c58:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f113c5c:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f113c60:	46008480 */ 	add.s	$f18,$f16,$f0
/*  f113c64:	e7b200d8 */ 	swc1	$f18,0xd8($sp)
/*  f113c68:	c44603b8 */ 	lwc1	$f6,0x3b8($v0)
/*  f113c6c:	c4440520 */ 	lwc1	$f4,0x520($v0)
/*  f113c70:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f113c74:	e7a800c4 */ 	swc1	$f8,0xc4($sp)
/*  f113c78:	c44a0524 */ 	lwc1	$f10,0x524($v0)
/*  f113c7c:	c45203b8 */ 	lwc1	$f18,0x3b8($v0)
/*  f113c80:	46005401 */ 	sub.s	$f16,$f10,$f0
/*  f113c84:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f113c88:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f113c8c:	e7a600c8 */ 	swc1	$f6,0xc8($sp)
/*  f113c90:	c44a03b8 */ 	lwc1	$f10,0x3b8($v0)
/*  f113c94:	c4480528 */ 	lwc1	$f8,0x528($v0)
/*  f113c98:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f113c9c:	e7b000cc */ 	swc1	$f16,0xcc($sp)
/*  f113ca0:	8c4a03b4 */ 	lw	$t2,0x3b4($v0)
/*  f113ca4:	0148c821 */ 	addu	$t9,$t2,$t0
/*  f113ca8:	ac5903b4 */ 	sw	$t9,0x3b4($v0)
/*  f113cac:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f113cb0:	8f0c03b4 */ 	lw	$t4,0x3b4($t8)
/*  f113cb4:	2981003d */ 	slti	$at,$t4,0x3d
/*  f113cb8:	14200005 */ 	bnez	$at,.L0f113cd0
/*  f113cbc:	3c017f1b */ 	lui	$at,%hi(var7f1b3a60)
/*  f113cc0:	0fc44df2 */ 	jal	currentPlayerSetHeadAmp
/*  f113cc4:	c42c3a60 */ 	lwc1	$f12,%lo(var7f1b3a60)($at)
/*  f113cc8:	10000087 */ 	beqz	$zero,.L0f113ee8
/*  f113ccc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f113cd0:
/*  f113cd0:	3c017f1b */ 	lui	$at,%hi(var7f1b3a64)
/*  f113cd4:	0fc44df2 */ 	jal	currentPlayerSetHeadAmp
/*  f113cd8:	c42c3a64 */ 	lwc1	$f12,%lo(var7f1b3a64)($at)
/*  f113cdc:	10000082 */ 	beqz	$zero,.L0f113ee8
/*  f113ce0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113ce4:	c4520530 */ 	lwc1	$f18,0x530($v0)
.L0f113ce8:
/*  f113ce8:	3c017f1b */ 	lui	$at,%hi(var7f1b3a68)
/*  f113cec:	c42c3a68 */ 	lwc1	$f12,%lo(var7f1b3a68)($at)
/*  f113cf0:	e7b200d0 */ 	swc1	$f18,0xd0($sp)
/*  f113cf4:	c4440534 */ 	lwc1	$f4,0x534($v0)
/*  f113cf8:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
/*  f113cfc:	c4460538 */ 	lwc1	$f6,0x538($v0)
/*  f113d00:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
/*  f113d04:	c4480520 */ 	lwc1	$f8,0x520($v0)
/*  f113d08:	e7a800c4 */ 	swc1	$f8,0xc4($sp)
/*  f113d0c:	c44a0524 */ 	lwc1	$f10,0x524($v0)
/*  f113d10:	e7aa00c8 */ 	swc1	$f10,0xc8($sp)
/*  f113d14:	c4500528 */ 	lwc1	$f16,0x528($v0)
/*  f113d18:	0fc44df2 */ 	jal	currentPlayerSetHeadAmp
/*  f113d1c:	e7b000cc */ 	swc1	$f16,0xcc($sp)
/*  f113d20:	10000071 */ 	beqz	$zero,.L0f113ee8
/*  f113d24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113d28:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f113d2c:
/*  f113d2c:	3c017f1b */ 	lui	$at,%hi(var7f1b3a6c)
/*  f113d30:	c4520418 */ 	lwc1	$f18,0x418($v0)
/*  f113d34:	e4520408 */ 	swc1	$f18,0x408($v0)
/*  f113d38:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113d3c:	c444041c */ 	lwc1	$f4,0x41c($v0)
/*  f113d40:	e444040c */ 	swc1	$f4,0x40c($v0)
/*  f113d44:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113d48:	c4460420 */ 	lwc1	$f6,0x420($v0)
/*  f113d4c:	e4460410 */ 	swc1	$f6,0x410($v0)
/*  f113d50:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113d54:	e7a000dc */ 	swc1	$f0,0xdc($sp)
/*  f113d58:	c4480414 */ 	lwc1	$f8,0x414($v0)
/*  f113d5c:	e7a000e4 */ 	swc1	$f0,0xe4($sp)
/*  f113d60:	e7a800e0 */ 	swc1	$f8,0xe0($sp)
/*  f113d64:	ac4003b4 */ 	sw	$zero,0x3b4($v0)
/*  f113d68:	0fc44df2 */ 	jal	currentPlayerSetHeadAmp
/*  f113d6c:	c42c3a6c */ 	lwc1	$f12,%lo(var7f1b3a6c)($at)
/*  f113d70:	0fc331a0 */ 	jal	currentPlayerGetCrouchPos
/*  f113d74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113d78:	1040005b */ 	beqz	$v0,.L0f113ee8
/*  f113d7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113d80:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113d84:	3c017f1b */ 	lui	$at,%hi(var7f1b3a70)
/*  f113d88:	c42a3a70 */ 	lwc1	$f10,%lo(var7f1b3a70)($at)
/*  f113d8c:	c4500198 */ 	lwc1	$f16,0x198($v0)
/*  f113d90:	3c017f1b */ 	lui	$at,%hi(var7f1b3a74)
/*  f113d94:	c4243a74 */ 	lwc1	$f4,%lo(var7f1b3a74)($at)
/*  f113d98:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f113d9c:	c608004c */ 	lwc1	$f8,0x4c($s0)
/*  f113da0:	c4500424 */ 	lwc1	$f16,0x424($v0)
/*  f113da4:	3c013f80 */ 	lui	$at,0x3f80
/*  f113da8:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f113dac:	44819000 */ 	mtc1	$at,$f18
/*  f113db0:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f113db4:	460a8100 */ 	add.s	$f4,$f16,$f10
/*  f113db8:	e4440424 */ 	swc1	$f4,0x424($v0)
/*  f113dbc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113dc0:	c4400424 */ 	lwc1	$f0,0x424($v0)
/*  f113dc4:	4600903e */ 	c.le.s	$f18,$f0
/*  f113dc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113dcc:	4502000c */ 	bc1fl	.L0f113e00
/*  f113dd0:	8c430458 */ 	lw	$v1,0x458($v0)
/*  f113dd4:	0fc44c8f */ 	jal	currentPlayerUpdateIdleHeadRoll
/*  f113dd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113ddc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113de0:	3c013f80 */ 	lui	$at,0x3f80
/*  f113de4:	44814000 */ 	mtc1	$at,$f8
/*  f113de8:	c4460424 */ 	lwc1	$f6,0x424($v0)
/*  f113dec:	46083401 */ 	sub.s	$f16,$f6,$f8
/*  f113df0:	e4500424 */ 	swc1	$f16,0x424($v0)
/*  f113df4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113df8:	c4400424 */ 	lwc1	$f0,0x424($v0)
/*  f113dfc:	8c430458 */ 	lw	$v1,0x458($v0)
.L0f113e00:
/*  f113e00:	44060000 */ 	mfc1	$a2,$f0
/*  f113e04:	27a700d0 */ 	addiu	$a3,$sp,0xd0
/*  f113e08:	00035880 */ 	sll	$t3,$v1,0x2
/*  f113e0c:	01635823 */ 	subu	$t3,$t3,$v1
/*  f113e10:	000b1880 */ 	sll	$v1,$t3,0x2
/*  f113e14:	00034823 */ 	negu	$t1,$v1
/*  f113e18:	00492821 */ 	addu	$a1,$v0,$t1
/*  f113e1c:	00432021 */ 	addu	$a0,$v0,$v1
/*  f113e20:	24840428 */ 	addiu	$a0,$a0,0x428
/*  f113e24:	0fc25ac8 */ 	jal	func0f096b20
/*  f113e28:	24a50434 */ 	addiu	$a1,$a1,0x434
/*  f113e2c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113e30:	3c0140a0 */ 	lui	$at,0x40a0
/*  f113e34:	44810000 */ 	mtc1	$at,$f0
/*  f113e38:	c4440198 */ 	lwc1	$f4,0x198($v0)
/*  f113e3c:	3c013f80 */ 	lui	$at,0x3f80
/*  f113e40:	44811000 */ 	mtc1	$at,$f2
/*  f113e44:	46040482 */ 	mul.s	$f18,$f0,$f4
/*  f113e48:	c7aa00d0 */ 	lwc1	$f10,0xd0($sp)
/*  f113e4c:	c7b000d4 */ 	lwc1	$f16,0xd4($sp)
/*  f113e50:	27a700c4 */ 	addiu	$a3,$sp,0xc4
/*  f113e54:	46121180 */ 	add.s	$f6,$f2,$f18
/*  f113e58:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f113e5c:	e7a800d0 */ 	swc1	$f8,0xd0($sp)
/*  f113e60:	c4440198 */ 	lwc1	$f4,0x198($v0)
/*  f113e64:	46040482 */ 	mul.s	$f18,$f0,$f4
/*  f113e68:	46121280 */ 	add.s	$f10,$f2,$f18
/*  f113e6c:	460a8182 */ 	mul.s	$f6,$f16,$f10
/*  f113e70:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f113e74:	8c430458 */ 	lw	$v1,0x458($v0)
/*  f113e78:	8c460424 */ 	lw	$a2,0x424($v0)
/*  f113e7c:	00037880 */ 	sll	$t7,$v1,0x2
/*  f113e80:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f113e84:	000f1880 */ 	sll	$v1,$t7,0x2
/*  f113e88:	00037023 */ 	negu	$t6,$v1
/*  f113e8c:	004e2821 */ 	addu	$a1,$v0,$t6
/*  f113e90:	00432021 */ 	addu	$a0,$v0,$v1
/*  f113e94:	24840440 */ 	addiu	$a0,$a0,0x440
/*  f113e98:	0fc25ac8 */ 	jal	func0f096b20
/*  f113e9c:	24a5044c */ 	addiu	$a1,$a1,0x44c
/*  f113ea0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113ea4:	3c0140a0 */ 	lui	$at,0x40a0
/*  f113ea8:	44810000 */ 	mtc1	$at,$f0
/*  f113eac:	c4440198 */ 	lwc1	$f4,0x198($v0)
/*  f113eb0:	3c013f80 */ 	lui	$at,0x3f80
/*  f113eb4:	44814000 */ 	mtc1	$at,$f8
/*  f113eb8:	46040482 */ 	mul.s	$f18,$f0,$f4
/*  f113ebc:	c7aa00c4 */ 	lwc1	$f10,0xc4($sp)
/*  f113ec0:	44812000 */ 	mtc1	$at,$f4
/*  f113ec4:	46124400 */ 	add.s	$f16,$f8,$f18
/*  f113ec8:	46105182 */ 	mul.s	$f6,$f10,$f16
/*  f113ecc:	c7b000cc */ 	lwc1	$f16,0xcc($sp)
/*  f113ed0:	e7a600c4 */ 	swc1	$f6,0xc4($sp)
/*  f113ed4:	c4480198 */ 	lwc1	$f8,0x198($v0)
/*  f113ed8:	46080482 */ 	mul.s	$f18,$f0,$f8
/*  f113edc:	46122280 */ 	add.s	$f10,$f4,$f18
/*  f113ee0:	460a8182 */ 	mul.s	$f6,$f16,$f10
/*  f113ee4:	e7a600cc */ 	swc1	$f6,0xcc($sp)
.L0f113ee8:
/*  f113ee8:	0fc44d2f */ 	jal	currentPlayerUpdateHeadPos
/*  f113eec:	27a400dc */ 	addiu	$a0,$sp,0xdc
/*  f113ef0:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f113ef4:	0fc44d6c */ 	jal	currentPlayerUpdateHeadRot
/*  f113ef8:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f113efc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f113f00:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f113f04:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f113f08:	03e00008 */ 	jr	$ra
/*  f113f0c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f113f10
/*  f113f10:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x284)
/*  f113f14:	8d08a244 */ 	lw	$t0,%lo(g_Vars+0x284)($t0)
/*  f113f18:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f113f1c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f113f20:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f113f24:	8d0e00bc */ 	lw	$t6,0xbc($t0)
/*  f113f28:	3c058007 */ 	lui	$a1,%hi(var80075c00)
/*  f113f2c:	24a55c00 */ 	addiu	$a1,$a1,%lo(var80075c00)
/*  f113f30:	c4a40024 */ 	lwc1	$f4,0x24($a1)
/*  f113f34:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f113f38:	3c108007 */ 	lui	$s0,%hi(var80075c00)
/*  f113f3c:	46046302 */ 	mul.s	$f12,$f12,$f4
/*  f113f40:	26105c00 */ 	addiu	$s0,$s0,%lo(var80075c00)
/*  f113f44:	00001025 */ 	or	$v0,$zero,$zero
/*  f113f48:	24030002 */ 	addiu	$v1,$zero,0x2
/*  f113f4c:	afaf002c */ 	sw	$t7,0x2c($sp)
.L0f113f50:
/*  f113f50:	c600000c */ 	lwc1	$f0,0xc($s0)
/*  f113f54:	c6060014 */ 	lwc1	$f6,0x14($s0)
/*  f113f58:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f113f5c:	4608603e */ 	c.le.s	$f12,$f8
/*  f113f60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113f64:	4502004a */ 	bc1fl	.L0f114090
/*  f113f68:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f113f6c:	8d0403ac */ 	lw	$a0,0x3ac($t0)
/*  f113f70:	3c013f00 */ 	lui	$at,0x3f00
/*  f113f74:	5044003a */ 	beql	$v0,$a0,.L0f114060
/*  f113f78:	46006303 */ 	div.s	$f12,$f12,$f0
/*  f113f7c:	44807000 */ 	mtc1	$zero,$f14
/*  f113f80:	04800010 */ 	bltz	$a0,.L0f113fc4
/*  f113f84:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f113f88:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f113f8c:	8d19047c */ 	lw	$t9,0x47c($t0)
/*  f113f90:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f113f94:	00b81821 */ 	addu	$v1,$a1,$t8
/*  f113f98:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f113f9c:	c4720008 */ 	lwc1	$f18,0x8($v1)
/*  f113fa0:	c72a000c */ 	lwc1	$f10,0xc($t9)
/*  f113fa4:	c6020004 */ 	lwc1	$f2,0x4($s0)
/*  f113fa8:	46009101 */ 	sub.s	$f4,$f18,$f0
/*  f113fac:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f113fb0:	46005401 */ 	sub.s	$f16,$f10,$f0
/*  f113fb4:	46023201 */ 	sub.s	$f8,$f6,$f2
/*  f113fb8:	46048383 */ 	div.s	$f14,$f16,$f4
/*  f113fbc:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f113fc0:	46025380 */ 	add.s	$f14,$f10,$f2
.L0f113fc4:
/*  f113fc4:	8d09047c */ 	lw	$t1,0x47c($t0)
/*  f113fc8:	44819000 */ 	mtc1	$at,$f18
/*  f113fcc:	3c014140 */ 	lui	$at,0x4140
/*  f113fd0:	81260008 */ 	lb	$a2,0x8($t1)
/*  f113fd4:	44818000 */ 	mtc1	$at,$f16
/*  f113fd8:	44077000 */ 	mfc1	$a3,$f14
/*  f113fdc:	e7ac0030 */ 	swc1	$f12,0x30($sp)
/*  f113fe0:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f113fe4:	2504045c */ 	addiu	$a0,$t0,0x45c
/*  f113fe8:	86050000 */ 	lh	$a1,0x0($s0)
/*  f113fec:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f113ff0:	0c007733 */ 	jal	func0001dccc
/*  f113ff4:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f113ff8:	3c04800a */ 	lui	$a0,%hi(g_Vars+0x284)
/*  f113ffc:	8c84a244 */ 	lw	$a0,%lo(g_Vars+0x284)($a0)
/*  f114000:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f114004:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f114008:	0c00777b */ 	jal	func0001ddec
/*  f11400c:	2484045c */ 	addiu	$a0,$a0,1116
/*  f114010:	3c04800a */ 	lui	$a0,%hi(g_Vars+0x284)
/*  f114014:	8c84a244 */ 	lw	$a0,%lo(g_Vars+0x284)($a0)
/*  f114018:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f11401c:	0c007787 */ 	jal	func0001de1c
/*  f114020:	2484045c */ 	addiu	$a0,$a0,1116
/*  f114024:	3c04800a */ 	lui	$a0,%hi(g_Vars+0x284)
/*  f114028:	8c84a244 */ 	lw	$a0,%lo(g_Vars+0x284)($a0)
/*  f11402c:	3c057f11 */ 	lui	$a1,%hi(currentPlayerFlipAnimation)
/*  f114030:	24a53220 */ 	addiu	$a1,$a1,%lo(currentPlayerFlipAnimation)
/*  f114034:	0c0077a6 */ 	jal	func0001de98
/*  f114038:	2484045c */ 	addiu	$a0,$a0,1116
/*  f11403c:	3c0a800a */ 	lui	$t2,%hi(g_Vars+0x284)
/*  f114040:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f114044:	8d4aa244 */ 	lw	$t2,%lo(g_Vars+0x284)($t2)
/*  f114048:	c7ac0030 */ 	lwc1	$f12,0x30($sp)
/*  f11404c:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x284)
/*  f114050:	ad4203ac */ 	sw	$v0,0x3ac($t2)
/*  f114054:	c600000c */ 	lwc1	$f0,0xc($s0)
/*  f114058:	8d08a244 */ 	lw	$t0,%lo(g_Vars+0x284)($t0)
/*  f11405c:	46006303 */ 	div.s	$f12,$f12,$f0
.L0f114060:
/*  f114060:	3c013f00 */ 	lui	$at,0x3f00
/*  f114064:	44812000 */ 	mtc1	$at,$f4
/*  f114068:	2504045c */ 	addiu	$a0,$t0,0x45c
/*  f11406c:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f114070:	46046182 */ 	mul.s	$f6,$f12,$f4
/*  f114074:	44053000 */ 	mfc1	$a1,$f6
/*  f114078:	0c0077ac */ 	jal	func0001deb0
/*  f11407c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f114080:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x284)
/*  f114084:	10000004 */ 	beqz	$zero,.L0f114098
/*  f114088:	8d08a244 */ 	lw	$t0,%lo(g_Vars+0x284)($t0)
/*  f11408c:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f114090:
/*  f114090:	1443ffaf */ 	bne	$v0,$v1,.L0f113f50
/*  f114094:	26100018 */ 	addiu	$s0,$s0,0x18
.L0f114098:
/*  f114098:	8d0b047c */ 	lw	$t3,0x47c($t0)
/*  f11409c:	8fac002c */ 	lw	$t4,0x2c($sp)
/*  f1140a0:	c568000c */ 	lwc1	$f8,0xc($t3)
/*  f1140a4:	e588018c */ 	swc1	$f8,0x18c($t4)
/*  f1140a8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1140ac:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f1140b0:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1140b4:	03e00008 */ 	jr	$ra
/*  f1140b8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1140bc
/*  f1140bc:	3c013f00 */ 	lui	$at,0x3f00
/*  f1140c0:	44877000 */ 	mtc1	$a3,$f14
/*  f1140c4:	44812000 */ 	mtc1	$at,$f4
/*  f1140c8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1140cc:	44866000 */ 	mtc1	$a2,$f12
/*  f1140d0:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f1140d4:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f1140d8:	3c04800a */ 	lui	$a0,%hi(g_Vars+0x284)
/*  f1140dc:	3c014140 */ 	lui	$at,0x4140
/*  f1140e0:	44814000 */ 	mtc1	$at,$f8
/*  f1140e4:	8c84a244 */ 	lw	$a0,%lo(g_Vars+0x284)($a0)
/*  f1140e8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1140ec:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f1140f0:	44076000 */ 	mfc1	$a3,$f12
/*  f1140f4:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f1140f8:	87a50022 */ 	lh	$a1,0x22($sp)
/*  f1140fc:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f114100:	2484045c */ 	addiu	$a0,$a0,1116
/*  f114104:	0c007733 */ 	jal	func0001dccc
/*  f114108:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f11410c:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f114110:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f114114:	240effff */ 	addiu	$t6,$zero,-1
/*  f114118:	adee03ac */ 	sw	$t6,0x3ac($t7)
/*  f11411c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f114120:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f114124:	03e00008 */ 	jr	$ra
/*  f114128:	00000000 */ 	sll	$zero,$zero,0x0
);

void func0f11412c(f32 speed)
{
	func0001deb0(&g_Vars.currentplayer->model, speed * 0.5f, 0);
}

f32 func0f11416c(void)
{
	if (g_Vars.currentplayer->unk03ac >= 0) {
		f32 a = g_Vars.currentplayer->unk0198 * 0.012500001f + 0.004166667f;
		f32 b = func0001d288(&g_Vars.currentplayer->model);

		if (b > 0) {
			f32 c = b / (var80075c00[g_Vars.currentplayer->unk03ac].unk08 - var80075c00[g_Vars.currentplayer->unk03ac].unk04);

			if (c < a) {
				c = a;
			}

			return c;
		}

		return a;
	}

	return 0;
}
