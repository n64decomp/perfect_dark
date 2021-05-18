#include <ultra64.h>
#include "constants.h"
#include "game/chr/chraction.h"
#include "game/game_097ba0.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b2150.h"
#include "game/game_0b3350.h"
#include "game/game_0d4690.h"
#include "game/sight.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/gfxmemory.h"
#include "game/lang.h"
#include "game/options.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/lib_09a80.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "data.h"
#include "types.h"

const char var7f1adda0[] = "sight";

u32 var80070f80 = 0x310a0000;
u32 var80070f84 = 0x43200000;
u32 var80070f88 = 0x42f00000;
u32 var80070f8c = 0x00000000;
u32 var80070f90 = 0x00000000;
u32 var80070f94 = 0x00000000;
u32 var80070f98 = 0x00000000;

/**
 * Return true if the prop is considered friendly (blue sight).
 */
bool sightIsPropFriendly(struct prop *prop)
{
	if (prop == NULL) {
		prop = g_Vars.currentplayer->lookingatprop.prop;
	}

	if (prop == NULL) {
		return false;
	}

	if (prop->type != PROPTYPE_CHR && prop->type != PROPTYPE_PLAYER) {
		return false;
	}

	if (g_Vars.coopplayernum >= 0 && prop->type == PROPTYPE_PLAYER) {
		return true;
	}

	if (g_Vars.antiplayernum >= 0 && prop->type == PROPTYPE_PLAYER) {
		return false;
	}

	if (g_Vars.normmplayerisrunning == false
			&& prop->chr
			&& (prop->chr->hidden2 & CHRH2FLAG_BLUESIGHT)) {
		return true;
	}

	return chrCompareTeams(g_Vars.currentplayer->prop->chr, prop->chr, COMPARE_FRIENDS);
}

GLOBAL_ASM(
glabel func0f0d715c
/*  f0d715c:	03e00008 */ 	jr	$ra
/*  f0d7160:	00000000 */ 	nop
/*  f0d7164:	03e00008 */ 	jr	$ra
/*  f0d7168:	00801025 */ 	or	$v0,$a0,$zero
);

/**
 * Return true if the given prop can be added to the target list.
 */
bool sightCanTargetProp(struct prop *prop, s32 max)
{
	s32 i;

	for (i = 0; i < max; i++) {
		if (prop == g_Vars.currentplayer->cmpfollowprops[i].prop) {
			return false;
		}
	}

	if (prop->type == PROPTYPE_CHR) {
		return true;
	}

	if (prop->type == PROPTYPE_PLAYER) {
		return true;
	}

	if ((prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_DOOR)
			&& prop->obj && (prop->obj->flags3 & OBJFLAG3_00008000)) {
		return true;
	}

	if (handGetWeaponNum(HAND_RIGHT) == WEAPON_ROCKETLAUNCHER) {
		return true;
	}

	return false;
}

/**
 * Return true if the sight should change colour when aiming at the given prop.
 */
bool sightIsReactiveToProp(struct prop *prop)
{
	if (prop->obj == NULL) {
		return false;
	}

	if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_DOOR) {
		struct defaultobj *obj = prop->obj;

		if (g_Vars.stagenum == STAGE_CITRAINING
				&& (obj->modelnum == MODEL_COMHUB || obj->modelnum == MODEL_CIHUB || obj->modelnum == MODEL_TARGET)) {
			return true;
		}

		if (func0f0687b8(obj) > 0) {
			return false;
		}
	} else if (prop->type == PROPTYPE_CHR) {
		struct chrdata *chr = prop->chr;

		if (chr && chr->race == RACE_EYESPY) {
			struct eyespy *eyespy = chrToEyespy(chr);

			if (!eyespy || !eyespy->initialised) {
				return false;
			}
		}
	}

	return true;
}

s32 sightFindFreeTargetIndex(s32 max)
{
	s32 i;

	for (i = 0; i < max; i++) {
		if (g_Vars.currentplayer->cmpfollowprops[i].prop == NULL) {
			return i;
		}
	}

	return -1;
}

void func0f0d7364(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->cmpfollowprops); i++) {
		g_Vars.currentplayer->cmpfollowprops[i].prop = NULL;
	}
}

void sightTick(bool sighton)
{
	struct threat *threat;
	u8 newtarget;
	s32 i;
	s32 index;
	struct inventory_class *thing = func0f0b11bc(&g_Vars.currentplayer->hands[0].base);
	struct weaponfunc *func = weaponGetFunctionById(g_Vars.currentplayer->hands[0].base.weaponnum,
			g_Vars.currentplayer->hands[0].base.weaponfunc);

	g_Vars.currentplayer->sighttimer240 += g_Vars.lvupdate240;

	for (i = 0; i < 4; i++) {
		if (g_Vars.currentplayer->targetset[i] > PALDOWN(512)) {
			if (g_Vars.currentplayer->targetset[i] < (PAL ? 850 : 1024) - g_Vars.lvupdate240) {
				g_Vars.currentplayer->targetset[i] += g_Vars.lvupdate240;
			} else {
				g_Vars.currentplayer->targetset[i] = PALDOWN(1020);
			}
		} else {
			if (g_Vars.currentplayer->targetset[i] < (PAL ? 426 : 516) - g_Vars.lvupdate240) {
				g_Vars.currentplayer->targetset[i] += g_Vars.lvupdate240;
			} else {
				g_Vars.currentplayer->targetset[i] = PALDOWN(512);
			}
		}
	}

	newtarget = thing->unk18 >> 28;

	if (handHasFunctionFlags(&g_Vars.currentplayer->hands[0].base, FUNCFLAG_THREATDETECTOR)) {
		newtarget = 5;
	}

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE) {
		newtarget = 0;
	}

	if (newtarget != g_Vars.currentplayer->target) {
		if (newtarget == 5) {
			for (i = 0; i < 4; i++) {
				g_Vars.currentplayer->cmpfollowprops[i].prop = NULL;
			}
		}

		g_Vars.currentplayer->target = newtarget;

		switch (newtarget) {
		case SIGHTTARGET_0:
		case SIGHTTARGET_1:
		case SIGHTTARGET_2:
		case SIGHTTARGET_3:
		case SIGHTTARGET_4:
			break;
		}
	}

	if (sighton && g_Vars.currentplayer->lastsighton == false && newtarget != 5) {
		for (i = 0; i < 4; i++) {
			g_Vars.currentplayer->cmpfollowprops[i].prop = NULL;
		}
	}

	for (i = 0; i < 4; i++) {
		threat = &g_Vars.currentplayer->cmpfollowprops[i];

		if (threat->prop && !sightIsReactiveToProp(threat->prop)) {
			threat->prop = NULL;
		}
	}

	threat = &g_Vars.currentplayer->lookingatprop;

	if (threat->prop && !sightIsReactiveToProp(threat->prop)) {
		threat->prop = NULL;
	}

	switch (g_Vars.currentplayer->target) {
	case SIGHTTARGET_1:
	case SIGHTTARGET_2:
		// Conditionally copy lookingatprop to cmpfollowprops[0], overwriting anything that's there
		if (sighton) {
			if (g_Vars.currentplayer->lookingatprop.prop) {
				if (g_Vars.currentplayer->lookingatprop.prop != g_Vars.currentplayer->cmpfollowprops[0].prop) {
					struct audiohandle *handle;

					handle = snd00010718(&handle, 0, 0x7fff, 0x40, 7, 1, 1, -1, 1);

					threat = &g_Vars.currentplayer->cmpfollowprops[0];

					threat->prop = g_Vars.currentplayer->lookingatprop.prop;
					threat->x1 = g_Vars.currentplayer->lookingatprop.x1;
					threat->y1 = g_Vars.currentplayer->lookingatprop.y1;
					threat->x2 = g_Vars.currentplayer->lookingatprop.x2;
					threat->y2 = g_Vars.currentplayer->lookingatprop.y2;

					g_Vars.currentplayer->targetset[0] = 0;
				}
			} else {
				g_Vars.currentplayer->cmpfollowprops[0].prop = NULL;
			}
		}
		break;
	case SIGHTTARGET_3:
		// Conditionally copy lookingatprop to cmpfollowprops[0], but only if that slot is empty
		if (sighton && g_Vars.currentplayer->lookingatprop.prop
				&& sightCanTargetProp(g_Vars.currentplayer->lookingatprop.prop, 1)) {
			index = sightFindFreeTargetIndex(1);

			if (index >= 0) {
				struct audiohandle *handle;

				handle = snd00010718(&handle, 0, 0x7fff, 0x40, 7, 1, 1, -1, 1);

				threat = &g_Vars.currentplayer->cmpfollowprops[index];

				threat->prop = g_Vars.currentplayer->lookingatprop.prop;
				threat->x1 = g_Vars.currentplayer->lookingatprop.x1;
				threat->y1 = g_Vars.currentplayer->lookingatprop.y1;
				threat->x2 = g_Vars.currentplayer->lookingatprop.x2;
				threat->y2 = g_Vars.currentplayer->lookingatprop.y2;

				g_Vars.currentplayer->targetset[index] = 0;
			}
		}
		break;
	case SIGHTTARGET_4:
		// Conditionally copy lookingatprop to any cmpfollowprops slot, but only if the slot is empty
		if (sighton && g_Vars.currentplayer->lookingatprop.prop
				&& sightCanTargetProp(g_Vars.currentplayer->lookingatprop.prop, 4)) {
			index = sightFindFreeTargetIndex(4);

			if (index >= 0) {
				struct audiohandle *handle;

				handle = snd00010718(&handle, 0, 0x7fff, 0x40, 7, 1, 1, -1, 1);

				threat = &g_Vars.currentplayer->cmpfollowprops[index];

				threat->prop = g_Vars.currentplayer->lookingatprop.prop;
				threat->x1 = g_Vars.currentplayer->lookingatprop.x1;
				threat->y1 = g_Vars.currentplayer->lookingatprop.y1;
				threat->x2 = g_Vars.currentplayer->lookingatprop.x2;
				threat->y2 = g_Vars.currentplayer->lookingatprop.y2;

				g_Vars.currentplayer->targetset[index] = 0;
			}
		}
		break;
	case SIGHTTARGET_0:
	case SIGHTTARGET_5:
		break;
	}

	g_Vars.currentplayer->lastsighton = sighton;
}

s32 func0f0d789c(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
	s32 value;

	if (arg3 < arg2) {
		arg2 = arg3;
	}

	value = (arg0 - arg1) * arg2;

	return value / arg3 + arg1;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel sightRenderTargetBox
/*  f0d78f4:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0d78f8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0d78fc:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0d7900:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f0d7904:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f0d7908:	0c002f40 */ 	jal	viGetViewLeft
/*  f0d790c:	afa700a4 */ 	sw	$a3,0xa4($sp)
/*  f0d7910:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f0d7914:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f0d7918:	004e001a */ 	div	$zero,$v0,$t6
/*  f0d791c:	00007812 */ 	mflo	$t7
/*  f0d7920:	afaf0094 */ 	sw	$t7,0x94($sp)
/*  f0d7924:	15c00002 */ 	bnez	$t6,.L0f0d7930
/*  f0d7928:	00000000 */ 	nop
/*  f0d792c:	0007000d */ 	break	0x7
.L0f0d7930:
/*  f0d7930:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d7934:	15c10004 */ 	bne	$t6,$at,.L0f0d7948
/*  f0d7938:	3c018000 */ 	lui	$at,0x8000
/*  f0d793c:	14410002 */ 	bne	$v0,$at,.L0f0d7948
/*  f0d7940:	00000000 */ 	nop
/*  f0d7944:	0006000d */ 	break	0x6
.L0f0d7948:
/*  f0d7948:	0c002f44 */ 	jal	viGetViewTop
/*  f0d794c:	00000000 */ 	nop
/*  f0d7950:	0c002f22 */ 	jal	viGetViewWidth
/*  f0d7954:	afa20090 */ 	sw	$v0,0x90($sp)
/*  f0d7958:	3c188008 */ 	lui	$t8,%hi(g_ScaleX)
/*  f0d795c:	8f18fac0 */ 	lw	$t8,%lo(g_ScaleX)($t8)
/*  f0d7960:	8fad0090 */ 	lw	$t5,0x90($sp)
/*  f0d7964:	0058001a */ 	div	$zero,$v0,$t8
/*  f0d7968:	0000c812 */ 	mflo	$t9
/*  f0d796c:	afb9008c */ 	sw	$t9,0x8c($sp)
/*  f0d7970:	17000002 */ 	bnez	$t8,.L0f0d797c
/*  f0d7974:	00000000 */ 	nop
/*  f0d7978:	0007000d */ 	break	0x7
.L0f0d797c:
/*  f0d797c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d7980:	17010004 */ 	bne	$t8,$at,.L0f0d7994
/*  f0d7984:	3c018000 */ 	lui	$at,0x8000
/*  f0d7988:	14410002 */ 	bne	$v0,$at,.L0f0d7994
/*  f0d798c:	00000000 */ 	nop
/*  f0d7990:	0006000d */ 	break	0x6
.L0f0d7994:
/*  f0d7994:	0c002f26 */ 	jal	viGetViewHeight
/*  f0d7998:	00000000 */ 	nop
/*  f0d799c:	8fae0090 */ 	lw	$t6,0x90($sp)
/*  f0d79a0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0d79a4:	afb90068 */ 	sw	$t9,0x68($sp)
/*  f0d79a8:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f0d79ac:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f0d79b0:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f0d79b4:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f0d79b8:	29c10201 */ 	slti	$at,$t6,0x1ab
/*  f0d79bc:	54200004 */ 	bnezl	$at,.L0f0d79d0
/*  f0d79c0:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f0d79c4:	240f0200 */ 	addiu	$t7,$zero,0x1aa
/*  f0d79c8:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f0d79cc:	8fb8009c */ 	lw	$t8,0x9c($sp)
.L0f0d79d0:
/*  f0d79d0:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f0d79d4:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f0d79d8:	87190004 */ 	lh	$t9,0x4($t8)
/*  f0d79dc:	8fa50094 */ 	lw	$a1,0x94($sp)
/*  f0d79e0:	8fa600a4 */ 	lw	$a2,0xa4($sp)
/*  f0d79e4:	032e001a */ 	div	$zero,$t9,$t6
/*  f0d79e8:	00002012 */ 	mflo	$a0
/*  f0d79ec:	24070050 */ 	addiu	$a3,$zero,0x42
/*  f0d79f0:	15c00002 */ 	bnez	$t6,.L0f0d79fc
/*  f0d79f4:	00000000 */ 	nop
/*  f0d79f8:	0007000d */ 	break	0x7
.L0f0d79fc:
/*  f0d79fc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d7a00:	15c10004 */ 	bne	$t6,$at,.L0f0d7a14
/*  f0d7a04:	3c018000 */ 	lui	$at,0x8000
/*  f0d7a08:	17210002 */ 	bne	$t9,$at,.L0f0d7a14
/*  f0d7a0c:	00000000 */ 	nop
/*  f0d7a10:	0006000d */ 	break	0x6
.L0f0d7a14:
/*  f0d7a14:	0fc35e27 */ 	jal	func0f0d789c
/*  f0d7a18:	00000000 */ 	nop
/*  f0d7a1c:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f0d7a20:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f0d7a24:	8fa600a4 */ 	lw	$a2,0xa4($sp)
/*  f0d7a28:	85e40006 */ 	lh	$a0,0x6($t7)
/*  f0d7a2c:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0d7a30:	0fc35e27 */ 	jal	func0f0d789c
/*  f0d7a34:	24070050 */ 	addiu	$a3,$zero,0x42
/*  f0d7a38:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f0d7a3c:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f0d7a40:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f0d7a44:	87190008 */ 	lh	$t9,0x8($t8)
/*  f0d7a48:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f0d7a4c:	8faf0094 */ 	lw	$t7,0x94($sp)
/*  f0d7a50:	032e001a */ 	div	$zero,$t9,$t6
/*  f0d7a54:	01f82821 */ 	addu	$a1,$t7,$t8
/*  f0d7a58:	00405025 */ 	or	$t2,$v0,$zero
/*  f0d7a5c:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f0d7a60:	00002012 */ 	mflo	$a0
/*  f0d7a64:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0d7a68:	8fac0080 */ 	lw	$t4,0x80($sp)
/*  f0d7a6c:	8fad0090 */ 	lw	$t5,0x90($sp)
/*  f0d7a70:	15c00002 */ 	bnez	$t6,.L0f0d7a7c
/*  f0d7a74:	00000000 */ 	nop
/*  f0d7a78:	0007000d */ 	break	0x7
.L0f0d7a7c:
/*  f0d7a7c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d7a80:	15c10004 */ 	bne	$t6,$at,.L0f0d7a94
/*  f0d7a84:	3c018000 */ 	lui	$at,0x8000
/*  f0d7a88:	17210002 */ 	bne	$t9,$at,.L0f0d7a94
/*  f0d7a8c:	00000000 */ 	nop
/*  f0d7a90:	0006000d */ 	break	0x6
.L0f0d7a94:
/*  f0d7a94:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0d7a98:	afaa0070 */ 	sw	$t2,0x70($sp)
/*  f0d7a9c:	8fa600a4 */ 	lw	$a2,0xa4($sp)
/*  f0d7aa0:	0fc35e27 */ 	jal	func0f0d789c
/*  f0d7aa4:	24070050 */ 	addiu	$a3,$zero,0x42
/*  f0d7aa8:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f0d7aac:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0d7ab0:	8fa600a4 */ 	lw	$a2,0xa4($sp)
/*  f0d7ab4:	8724000a */ 	lh	$a0,0xa($t9)
/*  f0d7ab8:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0d7abc:	0fc35e27 */ 	jal	func0f0d789c
/*  f0d7ac0:	24070050 */ 	addiu	$a3,$zero,0x42
/*  f0d7ac4:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f0d7ac8:	8fa80074 */ 	lw	$t0,0x74($sp)
/*  f0d7acc:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0d7ad0:	8dc40000 */ 	lw	$a0,0x0($t6)
/*  f0d7ad4:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0d7ad8:	5080011a */ 	beqzl	$a0,.L0f0d7f44
/*  f0d7adc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0d7ae0:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f0d7ae4:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f0d7ae8:	afa90078 */ 	sw	$t1,0x78($sp)
/*  f0d7aec:	0fc35c1c */ 	jal	sightIsPropFriendly
/*  f0d7af0:	afaa0070 */ 	sw	$t2,0x70($sp)
/*  f0d7af4:	8fa6006c */ 	lw	$a2,0x6c($sp)
/*  f0d7af8:	8fa80074 */ 	lw	$t0,0x74($sp)
/*  f0d7afc:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0d7b00:	10400003 */ 	beqz	$v0,.L0f0d7b10
/*  f0d7b04:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0d7b08:	10000003 */ 	b	.L0f0d7b18
/*  f0d7b0c:	3405ff60 */ 	dli	$a1,0xff60
.L0f0d7b10:
/*  f0d7b10:	3c05ff00 */ 	lui	$a1,0xff00
/*  f0d7b14:	34a50060 */ 	ori	$a1,$a1,0x60
.L0f0d7b18:
/*  f0d7b18:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0d7b1c:	afa6006c */ 	sw	$a2,0x6c($sp)
/*  f0d7b20:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f0d7b24:	afa90078 */ 	sw	$t1,0x78($sp)
/*  f0d7b28:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0d7b2c:	afaa0070 */ 	sw	$t2,0x70($sp)
/*  f0d7b30:	8fa50094 */ 	lw	$a1,0x94($sp)
/*  f0d7b34:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0d7b38:	8fa6006c */ 	lw	$a2,0x6c($sp)
/*  f0d7b3c:	8fa80074 */ 	lw	$t0,0x74($sp)
/*  f0d7b40:	0125082a */ 	slt	$at,$t1,$a1
/*  f0d7b44:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0d7b48:	8fab003c */ 	lw	$t3,0x3c($sp)
/*  f0d7b4c:	8fac0080 */ 	lw	$t4,0x80($sp)
/*  f0d7b50:	8fad0090 */ 	lw	$t5,0x90($sp)
/*  f0d7b54:	1420002b */ 	bnez	$at,.L0f0d7c04
/*  f0d7b58:	00402025 */ 	or	$a0,$v0,$zero
/*  f0d7b5c:	0169082a */ 	slt	$at,$t3,$t1
/*  f0d7b60:	14200028 */ 	bnez	$at,.L0f0d7c04
/*  f0d7b64:	018a082a */ 	slt	$at,$t4,$t2
/*  f0d7b68:	14200026 */ 	bnez	$at,.L0f0d7c04
/*  f0d7b6c:	00cd082a */ 	slt	$at,$a2,$t5
/*  f0d7b70:	14200024 */ 	bnez	$at,.L0f0d7c04
/*  f0d7b74:	00401825 */ 	or	$v1,$v0,$zero
/*  f0d7b78:	00cc082a */ 	slt	$at,$a2,$t4
/*  f0d7b7c:	10200003 */ 	beqz	$at,.L0f0d7b8c
/*  f0d7b80:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0d7b84:	10000002 */ 	b	.L0f0d7b90
/*  f0d7b88:	00c01025 */ 	or	$v0,$a2,$zero
.L0f0d7b8c:
/*  f0d7b8c:	01801025 */ 	or	$v0,$t4,$zero
.L0f0d7b90:
/*  f0d7b90:	3c078008 */ 	lui	$a3,%hi(g_ScaleX)
/*  f0d7b94:	24e7fac0 */ 	addiu	$a3,$a3,%lo(g_ScaleX)
/*  f0d7b98:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f0d7b9c:	252f0001 */ 	addiu	$t7,$t1,0x1
/*  f0d7ba0:	3c1ff600 */ 	lui	$ra,0xf600
/*  f0d7ba4:	01f80019 */ 	multu	$t7,$t8
/*  f0d7ba8:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f0d7bac:	01aa082a */ 	slt	$at,$t5,$t2
/*  f0d7bb0:	01a01025 */ 	or	$v0,$t5,$zero
/*  f0d7bb4:	0000c812 */ 	mflo	$t9
/*  f0d7bb8:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0d7bbc:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0d7bc0:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d7bc4:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0d7bc8:	01dfc025 */ 	or	$t8,$t6,$ra
/*  f0d7bcc:	030fc825 */ 	or	$t9,$t8,$t7
/*  f0d7bd0:	10200003 */ 	beqz	$at,.L0f0d7be0
/*  f0d7bd4:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0d7bd8:	10000001 */ 	b	.L0f0d7be0
/*  f0d7bdc:	01401025 */ 	or	$v0,$t2,$zero
.L0f0d7be0:
/*  f0d7be0:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f0d7be4:	304e03ff */ 	andi	$t6,$v0,0x3ff
/*  f0d7be8:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f0d7bec:	012f0019 */ 	multu	$t1,$t7
/*  f0d7bf0:	0000c812 */ 	mflo	$t9
/*  f0d7bf4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0d7bf8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0d7bfc:	030fc825 */ 	or	$t9,$t8,$t7
/*  f0d7c00:	ac790004 */ 	sw	$t9,0x4($v1)
.L0f0d7c04:
/*  f0d7c04:	3c078008 */ 	lui	$a3,%hi(g_ScaleX)
/*  f0d7c08:	0105082a */ 	slt	$at,$t0,$a1
/*  f0d7c0c:	24e7fac0 */ 	addiu	$a3,$a3,%lo(g_ScaleX)
/*  f0d7c10:	14200029 */ 	bnez	$at,.L0f0d7cb8
/*  f0d7c14:	3c1ff600 */ 	lui	$ra,0xf600
/*  f0d7c18:	0168082a */ 	slt	$at,$t3,$t0
/*  f0d7c1c:	14200026 */ 	bnez	$at,.L0f0d7cb8
/*  f0d7c20:	018a082a */ 	slt	$at,$t4,$t2
/*  f0d7c24:	14200024 */ 	bnez	$at,.L0f0d7cb8
/*  f0d7c28:	00cd082a */ 	slt	$at,$a2,$t5
/*  f0d7c2c:	14200022 */ 	bnez	$at,.L0f0d7cb8
/*  f0d7c30:	00801825 */ 	or	$v1,$a0,$zero
/*  f0d7c34:	00cc082a */ 	slt	$at,$a2,$t4
/*  f0d7c38:	10200003 */ 	beqz	$at,.L0f0d7c48
/*  f0d7c3c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d7c40:	10000002 */ 	b	.L0f0d7c4c
/*  f0d7c44:	00c01025 */ 	or	$v0,$a2,$zero
.L0f0d7c48:
/*  f0d7c48:	01801025 */ 	or	$v0,$t4,$zero
.L0f0d7c4c:
/*  f0d7c4c:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f0d7c50:	250e0001 */ 	addiu	$t6,$t0,0x1
/*  f0d7c54:	01aa082a */ 	slt	$at,$t5,$t2
/*  f0d7c58:	01d80019 */ 	multu	$t6,$t8
/*  f0d7c5c:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f0d7c60:	01a01025 */ 	or	$v0,$t5,$zero
/*  f0d7c64:	00007812 */ 	mflo	$t7
/*  f0d7c68:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f0d7c6c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0d7c70:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0d7c74:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f0d7c78:	033fc025 */ 	or	$t8,$t9,$ra
/*  f0d7c7c:	030e7825 */ 	or	$t7,$t8,$t6
/*  f0d7c80:	10200003 */ 	beqz	$at,.L0f0d7c90
/*  f0d7c84:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0d7c88:	10000001 */ 	b	.L0f0d7c90
/*  f0d7c8c:	01401025 */ 	or	$v0,$t2,$zero
.L0f0d7c90:
/*  f0d7c90:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0d7c94:	305903ff */ 	andi	$t9,$v0,0x3ff
/*  f0d7c98:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f0d7c9c:	010e0019 */ 	multu	$t0,$t6
/*  f0d7ca0:	00007812 */ 	mflo	$t7
/*  f0d7ca4:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f0d7ca8:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0d7cac:	030e7825 */ 	or	$t7,$t8,$t6
/*  f0d7cb0:	10000002 */ 	b	.L0f0d7cbc
/*  f0d7cb4:	ac6f0004 */ 	sw	$t7,0x4($v1)
.L0f0d7cb8:
/*  f0d7cb8:	afa00068 */ 	sw	$zero,0x68($sp)
.L0f0d7cbc:
/*  f0d7cbc:	014d082a */ 	slt	$at,$t2,$t5
/*  f0d7cc0:	14200028 */ 	bnez	$at,.L0f0d7d64
/*  f0d7cc4:	018a082a */ 	slt	$at,$t4,$t2
/*  f0d7cc8:	14200026 */ 	bnez	$at,.L0f0d7d64
/*  f0d7ccc:	0169082a */ 	slt	$at,$t3,$t1
/*  f0d7cd0:	14200024 */ 	bnez	$at,.L0f0d7d64
/*  f0d7cd4:	0105082a */ 	slt	$at,$t0,$a1
/*  f0d7cd8:	14200022 */ 	bnez	$at,.L0f0d7d64
/*  f0d7cdc:	00801825 */ 	or	$v1,$a0,$zero
/*  f0d7ce0:	010b082a */ 	slt	$at,$t0,$t3
/*  f0d7ce4:	10200003 */ 	beqz	$at,.L0f0d7cf4
/*  f0d7ce8:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d7cec:	10000002 */ 	b	.L0f0d7cf8
/*  f0d7cf0:	01001025 */ 	or	$v0,$t0,$zero
.L0f0d7cf4:
/*  f0d7cf4:	01601025 */ 	or	$v0,$t3,$zero
.L0f0d7cf8:
/*  f0d7cf8:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f0d7cfc:	24590001 */ 	addiu	$t9,$v0,0x1
/*  f0d7d00:	00a9082a */ 	slt	$at,$a1,$t1
/*  f0d7d04:	03380019 */ 	multu	$t9,$t8
/*  f0d7d08:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d7d0c:	00007012 */ 	mflo	$t6
/*  f0d7d10:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d7d14:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f0d7d18:	254e0001 */ 	addiu	$t6,$t2,0x1
/*  f0d7d1c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d7d20:	033fc025 */ 	or	$t8,$t9,$ra
/*  f0d7d24:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f0d7d28:	03197025 */ 	or	$t6,$t8,$t9
/*  f0d7d2c:	10200003 */ 	beqz	$at,.L0f0d7d3c
/*  f0d7d30:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0d7d34:	10000001 */ 	b	.L0f0d7d3c
/*  f0d7d38:	01201025 */ 	or	$v0,$t1,$zero
.L0f0d7d3c:
/*  f0d7d3c:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f0d7d40:	004f0019 */ 	multu	$v0,$t7
/*  f0d7d44:	314f03ff */ 	andi	$t7,$t2,0x3ff
/*  f0d7d48:	0000c012 */ 	mflo	$t8
/*  f0d7d4c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d7d50:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0d7d54:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0d7d58:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0d7d5c:	10000002 */ 	b	.L0f0d7d68
/*  f0d7d60:	ac790004 */ 	sw	$t9,0x4($v1)
.L0f0d7d64:
/*  f0d7d64:	afa00068 */ 	sw	$zero,0x68($sp)
.L0f0d7d68:
/*  f0d7d68:	00cd082a */ 	slt	$at,$a2,$t5
/*  f0d7d6c:	14200027 */ 	bnez	$at,.L0f0d7e0c
/*  f0d7d70:	0186082a */ 	slt	$at,$t4,$a2
/*  f0d7d74:	14200025 */ 	bnez	$at,.L0f0d7e0c
/*  f0d7d78:	0169082a */ 	slt	$at,$t3,$t1
/*  f0d7d7c:	14200023 */ 	bnez	$at,.L0f0d7e0c
/*  f0d7d80:	0105082a */ 	slt	$at,$t0,$a1
/*  f0d7d84:	14200021 */ 	bnez	$at,.L0f0d7e0c
/*  f0d7d88:	00801825 */ 	or	$v1,$a0,$zero
/*  f0d7d8c:	010b082a */ 	slt	$at,$t0,$t3
/*  f0d7d90:	10200003 */ 	beqz	$at,.L0f0d7da0
/*  f0d7d94:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d7d98:	10000002 */ 	b	.L0f0d7da4
/*  f0d7d9c:	01001025 */ 	or	$v0,$t0,$zero
.L0f0d7da0:
/*  f0d7da0:	01601025 */ 	or	$v0,$t3,$zero
.L0f0d7da4:
/*  f0d7da4:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0d7da8:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f0d7dac:	00a9082a */ 	slt	$at,$a1,$t1
/*  f0d7db0:	01ee0019 */ 	multu	$t7,$t6
/*  f0d7db4:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d7db8:	0000c012 */ 	mflo	$t8
/*  f0d7dbc:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d7dc0:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0d7dc4:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0d7dc8:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d7dcc:	01ff7025 */ 	or	$t6,$t7,$ra
/*  f0d7dd0:	00197880 */ 	sll	$t7,$t9,0x2
/*  f0d7dd4:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f0d7dd8:	10200003 */ 	beqz	$at,.L0f0d7de8
/*  f0d7ddc:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0d7de0:	10000001 */ 	b	.L0f0d7de8
/*  f0d7de4:	01201025 */ 	or	$v0,$t1,$zero
.L0f0d7de8:
/*  f0d7de8:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f0d7dec:	00590019 */ 	multu	$v0,$t9
/*  f0d7df0:	30d903ff */ 	andi	$t9,$a2,0x3ff
/*  f0d7df4:	00007012 */ 	mflo	$t6
/*  f0d7df8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d7dfc:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d7e00:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0d7e04:	030e7825 */ 	or	$t7,$t8,$t6
/*  f0d7e08:	ac6f0004 */ 	sw	$t7,0x4($v1)
.L0f0d7e0c:
/*  f0d7e0c:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f0d7e10:	0fc54e0e */ 	jal	func0f153838
/*  f0d7e14:	afaa0070 */ 	sw	$t2,0x70($sp)
/*  f0d7e18:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0d7e1c:	8fa80074 */ 	lw	$t0,0x74($sp)
/*  f0d7e20:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0d7e24:	10800046 */ 	beqz	$a0,.L0f0d7f40
/*  f0d7e28:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0d7e2c:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f0d7e30:	25180003 */ 	addiu	$t8,$t0,0x3
/*  f0d7e34:	254e0003 */ 	addiu	$t6,$t2,0x3
/*  f0d7e38:	13200041 */ 	beqz	$t9,.L0f0d7f40
/*  f0d7e3c:	28810007 */ 	slti	$at,$a0,0x7
/*  f0d7e40:	afb80054 */ 	sw	$t8,0x54($sp)
/*  f0d7e44:	10200022 */ 	beqz	$at,.L0f0d7ed0
/*  f0d7e48:	afae0050 */ 	sw	$t6,0x50($sp)
/*  f0d7e4c:	3c198007 */ 	lui	$t9,%hi(var80070f80)
/*  f0d7e50:	27390f80 */ 	addiu	$t9,$t9,%lo(var80070f80)
/*  f0d7e54:	9b210002 */ 	lwr	$at,0x2($t9)
/*  f0d7e58:	27af004c */ 	addiu	$t7,$sp,0x4c
/*  f0d7e5c:	2498002f */ 	addiu	$t8,$a0,0x2f
/*  f0d7e60:	b9e10002 */ 	swr	$at,0x2($t7)
/*  f0d7e64:	0c002f02 */ 	jal	viGetWidth
/*  f0d7e68:	a3b8004c */ 	sb	$t8,0x4c($sp)
/*  f0d7e6c:	0c002f06 */ 	jal	viGetHeight
/*  f0d7e70:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f0d7e74:	3c0f8008 */ 	lui	$t7,%hi(g_FontNumeric1)
/*  f0d7e78:	8deffb00 */ 	lw	$t7,%lo(g_FontNumeric1)($t7)
/*  f0d7e7c:	3c198008 */ 	lui	$t9,%hi(g_FontNumeric2)
/*  f0d7e80:	8f39fafc */ 	lw	$t9,%lo(g_FontNumeric2)($t9)
/*  f0d7e84:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0d7e88:	87af0040 */ 	lh	$t7,0x40($sp)
/*  f0d7e8c:	3c0e00ff */ 	lui	$t6,0xff
/*  f0d7e90:	35ce00a0 */ 	ori	$t6,$t6,0xa0
/*  f0d7e94:	241800a0 */ 	addiu	$t8,$zero,0xa0
/*  f0d7e98:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0d7e9c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0d7ea0:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0d7ea4:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f0d7ea8:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f0d7eac:	27a7004c */ 	addiu	$a3,$sp,0x4c
/*  f0d7eb0:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0d7eb4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0d7eb8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0d7ebc:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0d7ec0:	0fc55b92 */ 	jal	textRender
/*  f0d7ec4:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0d7ec8:	1000001d */ 	b	.L0f0d7f40
/*  f0d7ecc:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0d7ed0:
/*  f0d7ed0:	0fc5b9f1 */ 	jal	langGet
/*  f0d7ed4:	00000000 */ 	nop
/*  f0d7ed8:	0c002f02 */ 	jal	viGetWidth
/*  f0d7edc:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f0d7ee0:	0c002f06 */ 	jal	viGetHeight
/*  f0d7ee4:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f0d7ee8:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicXs1)
/*  f0d7eec:	8f39fb08 */ 	lw	$t9,%lo(g_FontHandelGothicXs1)($t9)
/*  f0d7ef0:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicXs2)
/*  f0d7ef4:	8dcefb04 */ 	lw	$t6,%lo(g_FontHandelGothicXs2)($t6)
/*  f0d7ef8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0d7efc:	87b90040 */ 	lh	$t9,0x40($sp)
/*  f0d7f00:	3c1800ff */ 	lui	$t8,0xff
/*  f0d7f04:	371800a0 */ 	ori	$t8,$t8,0xa0
/*  f0d7f08:	240f00a0 */ 	addiu	$t7,$zero,0xa0
/*  f0d7f0c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0d7f10:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0d7f14:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0d7f18:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f0d7f1c:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f0d7f20:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0d7f24:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0d7f28:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0d7f2c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0d7f30:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0d7f34:	0fc55b92 */ 	jal	textRender
/*  f0d7f38:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0d7f3c:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0d7f40:
/*  f0d7f40:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0d7f44:
/*  f0d7f44:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0d7f48:	27bd0098 */ 	addiu	$sp,$sp,0x98
/*  f0d7f4c:	03e00008 */ 	jr	$ra
/*  f0d7f50:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel sightRenderTargetBox
/*  f0d78f4:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0d78f8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0d78fc:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f0d7900:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f0d7904:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f0d7908:	0c002f40 */ 	jal	viGetViewLeft
/*  f0d790c:	afa700a4 */ 	sw	$a3,0xa4($sp)
/*  f0d7910:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f0d7914:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f0d7918:	004e001a */ 	div	$zero,$v0,$t6
/*  f0d791c:	00007812 */ 	mflo	$t7
/*  f0d7920:	afaf0094 */ 	sw	$t7,0x94($sp)
/*  f0d7924:	15c00002 */ 	bnez	$t6,.L0f0d7930
/*  f0d7928:	00000000 */ 	nop
/*  f0d792c:	0007000d */ 	break	0x7
.L0f0d7930:
/*  f0d7930:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d7934:	15c10004 */ 	bne	$t6,$at,.L0f0d7948
/*  f0d7938:	3c018000 */ 	lui	$at,0x8000
/*  f0d793c:	14410002 */ 	bne	$v0,$at,.L0f0d7948
/*  f0d7940:	00000000 */ 	nop
/*  f0d7944:	0006000d */ 	break	0x6
.L0f0d7948:
/*  f0d7948:	0c002f44 */ 	jal	viGetViewTop
/*  f0d794c:	00000000 */ 	nop
/*  f0d7950:	0c002f22 */ 	jal	viGetViewWidth
/*  f0d7954:	afa20090 */ 	sw	$v0,0x90($sp)
/*  f0d7958:	3c188008 */ 	lui	$t8,%hi(g_ScaleX)
/*  f0d795c:	8f18fac0 */ 	lw	$t8,%lo(g_ScaleX)($t8)
/*  f0d7960:	8fad0090 */ 	lw	$t5,0x90($sp)
/*  f0d7964:	0058001a */ 	div	$zero,$v0,$t8
/*  f0d7968:	0000c812 */ 	mflo	$t9
/*  f0d796c:	afb9008c */ 	sw	$t9,0x8c($sp)
/*  f0d7970:	17000002 */ 	bnez	$t8,.L0f0d797c
/*  f0d7974:	00000000 */ 	nop
/*  f0d7978:	0007000d */ 	break	0x7
.L0f0d797c:
/*  f0d797c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d7980:	17010004 */ 	bne	$t8,$at,.L0f0d7994
/*  f0d7984:	3c018000 */ 	lui	$at,0x8000
/*  f0d7988:	14410002 */ 	bne	$v0,$at,.L0f0d7994
/*  f0d798c:	00000000 */ 	nop
/*  f0d7990:	0006000d */ 	break	0x6
.L0f0d7994:
/*  f0d7994:	0c002f26 */ 	jal	viGetViewHeight
/*  f0d7998:	00000000 */ 	nop
/*  f0d799c:	8fae0090 */ 	lw	$t6,0x90($sp)
/*  f0d79a0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0d79a4:	afb90068 */ 	sw	$t9,0x68($sp)
/*  f0d79a8:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f0d79ac:	8fae00a4 */ 	lw	$t6,0xa4($sp)
/*  f0d79b0:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f0d79b4:	afb80080 */ 	sw	$t8,0x80($sp)
/*  f0d79b8:	29c10201 */ 	slti	$at,$t6,0x201
/*  f0d79bc:	54200004 */ 	bnezl	$at,.L0f0d79d0
/*  f0d79c0:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f0d79c4:	240f0200 */ 	addiu	$t7,$zero,0x200
/*  f0d79c8:	afaf00a4 */ 	sw	$t7,0xa4($sp)
/*  f0d79cc:	8fb8009c */ 	lw	$t8,0x9c($sp)
.L0f0d79d0:
/*  f0d79d0:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f0d79d4:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f0d79d8:	87190004 */ 	lh	$t9,0x4($t8)
/*  f0d79dc:	8fa50094 */ 	lw	$a1,0x94($sp)
/*  f0d79e0:	8fa600a4 */ 	lw	$a2,0xa4($sp)
/*  f0d79e4:	032e001a */ 	div	$zero,$t9,$t6
/*  f0d79e8:	00002012 */ 	mflo	$a0
/*  f0d79ec:	24070050 */ 	addiu	$a3,$zero,0x50
/*  f0d79f0:	15c00002 */ 	bnez	$t6,.L0f0d79fc
/*  f0d79f4:	00000000 */ 	nop
/*  f0d79f8:	0007000d */ 	break	0x7
.L0f0d79fc:
/*  f0d79fc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d7a00:	15c10004 */ 	bne	$t6,$at,.L0f0d7a14
/*  f0d7a04:	3c018000 */ 	lui	$at,0x8000
/*  f0d7a08:	17210002 */ 	bne	$t9,$at,.L0f0d7a14
/*  f0d7a0c:	00000000 */ 	nop
/*  f0d7a10:	0006000d */ 	break	0x6
.L0f0d7a14:
/*  f0d7a14:	0fc35e27 */ 	jal	func0f0d789c
/*  f0d7a18:	00000000 */ 	nop
/*  f0d7a1c:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f0d7a20:	8fa50090 */ 	lw	$a1,0x90($sp)
/*  f0d7a24:	8fa600a4 */ 	lw	$a2,0xa4($sp)
/*  f0d7a28:	85e40006 */ 	lh	$a0,0x6($t7)
/*  f0d7a2c:	afa20078 */ 	sw	$v0,0x78($sp)
/*  f0d7a30:	0fc35e27 */ 	jal	func0f0d789c
/*  f0d7a34:	24070050 */ 	addiu	$a3,$zero,0x50
/*  f0d7a38:	8fb8009c */ 	lw	$t8,0x9c($sp)
/*  f0d7a3c:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f0d7a40:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f0d7a44:	87190008 */ 	lh	$t9,0x8($t8)
/*  f0d7a48:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f0d7a4c:	8faf0094 */ 	lw	$t7,0x94($sp)
/*  f0d7a50:	032e001a */ 	div	$zero,$t9,$t6
/*  f0d7a54:	01f82821 */ 	addu	$a1,$t7,$t8
/*  f0d7a58:	00405025 */ 	or	$t2,$v0,$zero
/*  f0d7a5c:	24a5ffff */ 	addiu	$a1,$a1,-1
/*  f0d7a60:	00002012 */ 	mflo	$a0
/*  f0d7a64:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0d7a68:	8fac0080 */ 	lw	$t4,0x80($sp)
/*  f0d7a6c:	8fad0090 */ 	lw	$t5,0x90($sp)
/*  f0d7a70:	15c00002 */ 	bnez	$t6,.L0f0d7a7c
/*  f0d7a74:	00000000 */ 	nop
/*  f0d7a78:	0007000d */ 	break	0x7
.L0f0d7a7c:
/*  f0d7a7c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d7a80:	15c10004 */ 	bne	$t6,$at,.L0f0d7a94
/*  f0d7a84:	3c018000 */ 	lui	$at,0x8000
/*  f0d7a88:	17210002 */ 	bne	$t9,$at,.L0f0d7a94
/*  f0d7a8c:	00000000 */ 	nop
/*  f0d7a90:	0006000d */ 	break	0x6
.L0f0d7a94:
/*  f0d7a94:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f0d7a98:	afaa0070 */ 	sw	$t2,0x70($sp)
/*  f0d7a9c:	8fa600a4 */ 	lw	$a2,0xa4($sp)
/*  f0d7aa0:	0fc35e27 */ 	jal	func0f0d789c
/*  f0d7aa4:	24070050 */ 	addiu	$a3,$zero,0x50
/*  f0d7aa8:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f0d7aac:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f0d7ab0:	8fa600a4 */ 	lw	$a2,0xa4($sp)
/*  f0d7ab4:	8724000a */ 	lh	$a0,0xa($t9)
/*  f0d7ab8:	afa20074 */ 	sw	$v0,0x74($sp)
/*  f0d7abc:	0fc35e27 */ 	jal	func0f0d789c
/*  f0d7ac0:	24070050 */ 	addiu	$a3,$zero,0x50
/*  f0d7ac4:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f0d7ac8:	8fa80074 */ 	lw	$t0,0x74($sp)
/*  f0d7acc:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0d7ad0:	8dc40000 */ 	lw	$a0,0x0($t6)
/*  f0d7ad4:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0d7ad8:	5080011a */ 	beqzl	$a0,.L0f0d7f44
/*  f0d7adc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f0d7ae0:	afa2006c */ 	sw	$v0,0x6c($sp)
/*  f0d7ae4:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f0d7ae8:	afa90078 */ 	sw	$t1,0x78($sp)
/*  f0d7aec:	0fc35c1c */ 	jal	sightIsPropFriendly
/*  f0d7af0:	afaa0070 */ 	sw	$t2,0x70($sp)
/*  f0d7af4:	8fa6006c */ 	lw	$a2,0x6c($sp)
/*  f0d7af8:	8fa80074 */ 	lw	$t0,0x74($sp)
/*  f0d7afc:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0d7b00:	10400003 */ 	beqz	$v0,.L0f0d7b10
/*  f0d7b04:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0d7b08:	10000003 */ 	b	.L0f0d7b18
/*  f0d7b0c:	3405ff60 */ 	dli	$a1,0xff60
.L0f0d7b10:
/*  f0d7b10:	3c05ff00 */ 	lui	$a1,0xff00
/*  f0d7b14:	34a50060 */ 	ori	$a1,$a1,0x60
.L0f0d7b18:
/*  f0d7b18:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0d7b1c:	afa6006c */ 	sw	$a2,0x6c($sp)
/*  f0d7b20:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f0d7b24:	afa90078 */ 	sw	$t1,0x78($sp)
/*  f0d7b28:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0d7b2c:	afaa0070 */ 	sw	$t2,0x70($sp)
/*  f0d7b30:	8fa50094 */ 	lw	$a1,0x94($sp)
/*  f0d7b34:	8fa90078 */ 	lw	$t1,0x78($sp)
/*  f0d7b38:	8fa6006c */ 	lw	$a2,0x6c($sp)
/*  f0d7b3c:	8fa80074 */ 	lw	$t0,0x74($sp)
/*  f0d7b40:	0125082a */ 	slt	$at,$t1,$a1
/*  f0d7b44:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0d7b48:	8fab003c */ 	lw	$t3,0x3c($sp)
/*  f0d7b4c:	8fac0080 */ 	lw	$t4,0x80($sp)
/*  f0d7b50:	8fad0090 */ 	lw	$t5,0x90($sp)
/*  f0d7b54:	1420002b */ 	bnez	$at,.L0f0d7c04
/*  f0d7b58:	00402025 */ 	or	$a0,$v0,$zero
/*  f0d7b5c:	0169082a */ 	slt	$at,$t3,$t1
/*  f0d7b60:	14200028 */ 	bnez	$at,.L0f0d7c04
/*  f0d7b64:	018a082a */ 	slt	$at,$t4,$t2
/*  f0d7b68:	14200026 */ 	bnez	$at,.L0f0d7c04
/*  f0d7b6c:	00cd082a */ 	slt	$at,$a2,$t5
/*  f0d7b70:	14200024 */ 	bnez	$at,.L0f0d7c04
/*  f0d7b74:	00401825 */ 	or	$v1,$v0,$zero
/*  f0d7b78:	00cc082a */ 	slt	$at,$a2,$t4
/*  f0d7b7c:	10200003 */ 	beqz	$at,.L0f0d7b8c
/*  f0d7b80:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0d7b84:	10000002 */ 	b	.L0f0d7b90
/*  f0d7b88:	00c01025 */ 	or	$v0,$a2,$zero
.L0f0d7b8c:
/*  f0d7b8c:	01801025 */ 	or	$v0,$t4,$zero
.L0f0d7b90:
/*  f0d7b90:	3c078008 */ 	lui	$a3,%hi(g_ScaleX)
/*  f0d7b94:	24e7fac0 */ 	addiu	$a3,$a3,%lo(g_ScaleX)
/*  f0d7b98:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f0d7b9c:	252f0001 */ 	addiu	$t7,$t1,0x1
/*  f0d7ba0:	3c1ff600 */ 	lui	$ra,0xf600
/*  f0d7ba4:	01f80019 */ 	multu	$t7,$t8
/*  f0d7ba8:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f0d7bac:	01aa082a */ 	slt	$at,$t5,$t2
/*  f0d7bb0:	01a01025 */ 	or	$v0,$t5,$zero
/*  f0d7bb4:	0000c812 */ 	mflo	$t9
/*  f0d7bb8:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0d7bbc:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0d7bc0:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d7bc4:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0d7bc8:	01dfc025 */ 	or	$t8,$t6,$ra
/*  f0d7bcc:	030fc825 */ 	or	$t9,$t8,$t7
/*  f0d7bd0:	10200003 */ 	beqz	$at,.L0f0d7be0
/*  f0d7bd4:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f0d7bd8:	10000001 */ 	b	.L0f0d7be0
/*  f0d7bdc:	01401025 */ 	or	$v0,$t2,$zero
.L0f0d7be0:
/*  f0d7be0:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f0d7be4:	304e03ff */ 	andi	$t6,$v0,0x3ff
/*  f0d7be8:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f0d7bec:	012f0019 */ 	multu	$t1,$t7
/*  f0d7bf0:	0000c812 */ 	mflo	$t9
/*  f0d7bf4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0d7bf8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0d7bfc:	030fc825 */ 	or	$t9,$t8,$t7
/*  f0d7c00:	ac790004 */ 	sw	$t9,0x4($v1)
.L0f0d7c04:
/*  f0d7c04:	3c078008 */ 	lui	$a3,%hi(g_ScaleX)
/*  f0d7c08:	0105082a */ 	slt	$at,$t0,$a1
/*  f0d7c0c:	24e7fac0 */ 	addiu	$a3,$a3,%lo(g_ScaleX)
/*  f0d7c10:	14200029 */ 	bnez	$at,.L0f0d7cb8
/*  f0d7c14:	3c1ff600 */ 	lui	$ra,0xf600
/*  f0d7c18:	0168082a */ 	slt	$at,$t3,$t0
/*  f0d7c1c:	14200026 */ 	bnez	$at,.L0f0d7cb8
/*  f0d7c20:	018a082a */ 	slt	$at,$t4,$t2
/*  f0d7c24:	14200024 */ 	bnez	$at,.L0f0d7cb8
/*  f0d7c28:	00cd082a */ 	slt	$at,$a2,$t5
/*  f0d7c2c:	14200022 */ 	bnez	$at,.L0f0d7cb8
/*  f0d7c30:	00801825 */ 	or	$v1,$a0,$zero
/*  f0d7c34:	00cc082a */ 	slt	$at,$a2,$t4
/*  f0d7c38:	10200003 */ 	beqz	$at,.L0f0d7c48
/*  f0d7c3c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d7c40:	10000002 */ 	b	.L0f0d7c4c
/*  f0d7c44:	00c01025 */ 	or	$v0,$a2,$zero
.L0f0d7c48:
/*  f0d7c48:	01801025 */ 	or	$v0,$t4,$zero
.L0f0d7c4c:
/*  f0d7c4c:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f0d7c50:	250e0001 */ 	addiu	$t6,$t0,0x1
/*  f0d7c54:	01aa082a */ 	slt	$at,$t5,$t2
/*  f0d7c58:	01d80019 */ 	multu	$t6,$t8
/*  f0d7c5c:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f0d7c60:	01a01025 */ 	or	$v0,$t5,$zero
/*  f0d7c64:	00007812 */ 	mflo	$t7
/*  f0d7c68:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f0d7c6c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0d7c70:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0d7c74:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f0d7c78:	033fc025 */ 	or	$t8,$t9,$ra
/*  f0d7c7c:	030e7825 */ 	or	$t7,$t8,$t6
/*  f0d7c80:	10200003 */ 	beqz	$at,.L0f0d7c90
/*  f0d7c84:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f0d7c88:	10000001 */ 	b	.L0f0d7c90
/*  f0d7c8c:	01401025 */ 	or	$v0,$t2,$zero
.L0f0d7c90:
/*  f0d7c90:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0d7c94:	305903ff */ 	andi	$t9,$v0,0x3ff
/*  f0d7c98:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f0d7c9c:	010e0019 */ 	multu	$t0,$t6
/*  f0d7ca0:	00007812 */ 	mflo	$t7
/*  f0d7ca4:	31f903ff */ 	andi	$t9,$t7,0x3ff
/*  f0d7ca8:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0d7cac:	030e7825 */ 	or	$t7,$t8,$t6
/*  f0d7cb0:	10000002 */ 	b	.L0f0d7cbc
/*  f0d7cb4:	ac6f0004 */ 	sw	$t7,0x4($v1)
.L0f0d7cb8:
/*  f0d7cb8:	afa00068 */ 	sw	$zero,0x68($sp)
.L0f0d7cbc:
/*  f0d7cbc:	014d082a */ 	slt	$at,$t2,$t5
/*  f0d7cc0:	14200028 */ 	bnez	$at,.L0f0d7d64
/*  f0d7cc4:	018a082a */ 	slt	$at,$t4,$t2
/*  f0d7cc8:	14200026 */ 	bnez	$at,.L0f0d7d64
/*  f0d7ccc:	0169082a */ 	slt	$at,$t3,$t1
/*  f0d7cd0:	14200024 */ 	bnez	$at,.L0f0d7d64
/*  f0d7cd4:	0105082a */ 	slt	$at,$t0,$a1
/*  f0d7cd8:	14200022 */ 	bnez	$at,.L0f0d7d64
/*  f0d7cdc:	00801825 */ 	or	$v1,$a0,$zero
/*  f0d7ce0:	010b082a */ 	slt	$at,$t0,$t3
/*  f0d7ce4:	10200003 */ 	beqz	$at,.L0f0d7cf4
/*  f0d7ce8:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d7cec:	10000002 */ 	b	.L0f0d7cf8
/*  f0d7cf0:	01001025 */ 	or	$v0,$t0,$zero
.L0f0d7cf4:
/*  f0d7cf4:	01601025 */ 	or	$v0,$t3,$zero
.L0f0d7cf8:
/*  f0d7cf8:	8cf80000 */ 	lw	$t8,0x0($a3)
/*  f0d7cfc:	24590001 */ 	addiu	$t9,$v0,0x1
/*  f0d7d00:	00a9082a */ 	slt	$at,$a1,$t1
/*  f0d7d04:	03380019 */ 	multu	$t9,$t8
/*  f0d7d08:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d7d0c:	00007012 */ 	mflo	$t6
/*  f0d7d10:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d7d14:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f0d7d18:	254e0001 */ 	addiu	$t6,$t2,0x1
/*  f0d7d1c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d7d20:	033fc025 */ 	or	$t8,$t9,$ra
/*  f0d7d24:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f0d7d28:	03197025 */ 	or	$t6,$t8,$t9
/*  f0d7d2c:	10200003 */ 	beqz	$at,.L0f0d7d3c
/*  f0d7d30:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f0d7d34:	10000001 */ 	b	.L0f0d7d3c
/*  f0d7d38:	01201025 */ 	or	$v0,$t1,$zero
.L0f0d7d3c:
/*  f0d7d3c:	8cef0000 */ 	lw	$t7,0x0($a3)
/*  f0d7d40:	004f0019 */ 	multu	$v0,$t7
/*  f0d7d44:	314f03ff */ 	andi	$t7,$t2,0x3ff
/*  f0d7d48:	0000c012 */ 	mflo	$t8
/*  f0d7d4c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d7d50:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0d7d54:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0d7d58:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0d7d5c:	10000002 */ 	b	.L0f0d7d68
/*  f0d7d60:	ac790004 */ 	sw	$t9,0x4($v1)
.L0f0d7d64:
/*  f0d7d64:	afa00068 */ 	sw	$zero,0x68($sp)
.L0f0d7d68:
/*  f0d7d68:	00cd082a */ 	slt	$at,$a2,$t5
/*  f0d7d6c:	14200027 */ 	bnez	$at,.L0f0d7e0c
/*  f0d7d70:	0186082a */ 	slt	$at,$t4,$a2
/*  f0d7d74:	14200025 */ 	bnez	$at,.L0f0d7e0c
/*  f0d7d78:	0169082a */ 	slt	$at,$t3,$t1
/*  f0d7d7c:	14200023 */ 	bnez	$at,.L0f0d7e0c
/*  f0d7d80:	0105082a */ 	slt	$at,$t0,$a1
/*  f0d7d84:	14200021 */ 	bnez	$at,.L0f0d7e0c
/*  f0d7d88:	00801825 */ 	or	$v1,$a0,$zero
/*  f0d7d8c:	010b082a */ 	slt	$at,$t0,$t3
/*  f0d7d90:	10200003 */ 	beqz	$at,.L0f0d7da0
/*  f0d7d94:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d7d98:	10000002 */ 	b	.L0f0d7da4
/*  f0d7d9c:	01001025 */ 	or	$v0,$t0,$zero
.L0f0d7da0:
/*  f0d7da0:	01601025 */ 	or	$v0,$t3,$zero
.L0f0d7da4:
/*  f0d7da4:	8cee0000 */ 	lw	$t6,0x0($a3)
/*  f0d7da8:	244f0001 */ 	addiu	$t7,$v0,0x1
/*  f0d7dac:	00a9082a */ 	slt	$at,$a1,$t1
/*  f0d7db0:	01ee0019 */ 	multu	$t7,$t6
/*  f0d7db4:	00a01025 */ 	or	$v0,$a1,$zero
/*  f0d7db8:	0000c012 */ 	mflo	$t8
/*  f0d7dbc:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d7dc0:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0d7dc4:	24d80001 */ 	addiu	$t8,$a2,0x1
/*  f0d7dc8:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d7dcc:	01ff7025 */ 	or	$t6,$t7,$ra
/*  f0d7dd0:	00197880 */ 	sll	$t7,$t9,0x2
/*  f0d7dd4:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f0d7dd8:	10200003 */ 	beqz	$at,.L0f0d7de8
/*  f0d7ddc:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f0d7de0:	10000001 */ 	b	.L0f0d7de8
/*  f0d7de4:	01201025 */ 	or	$v0,$t1,$zero
.L0f0d7de8:
/*  f0d7de8:	8cf90000 */ 	lw	$t9,0x0($a3)
/*  f0d7dec:	00590019 */ 	multu	$v0,$t9
/*  f0d7df0:	30d903ff */ 	andi	$t9,$a2,0x3ff
/*  f0d7df4:	00007012 */ 	mflo	$t6
/*  f0d7df8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d7dfc:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d7e00:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0d7e04:	030e7825 */ 	or	$t7,$t8,$t6
/*  f0d7e08:	ac6f0004 */ 	sw	$t7,0x4($v1)
.L0f0d7e0c:
/*  f0d7e0c:	afa80074 */ 	sw	$t0,0x74($sp)
/*  f0d7e10:	0fc54e0e */ 	jal	func0f153838
/*  f0d7e14:	afaa0070 */ 	sw	$t2,0x70($sp)
/*  f0d7e18:	8fa400a0 */ 	lw	$a0,0xa0($sp)
/*  f0d7e1c:	8fa80074 */ 	lw	$t0,0x74($sp)
/*  f0d7e20:	8faa0070 */ 	lw	$t2,0x70($sp)
/*  f0d7e24:	10800046 */ 	beqz	$a0,.L0f0d7f40
/*  f0d7e28:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0d7e2c:	8fb90068 */ 	lw	$t9,0x68($sp)
/*  f0d7e30:	25180003 */ 	addiu	$t8,$t0,0x3
/*  f0d7e34:	254e0003 */ 	addiu	$t6,$t2,0x3
/*  f0d7e38:	13200041 */ 	beqz	$t9,.L0f0d7f40
/*  f0d7e3c:	28810007 */ 	slti	$at,$a0,0x7
/*  f0d7e40:	afb80054 */ 	sw	$t8,0x54($sp)
/*  f0d7e44:	10200022 */ 	beqz	$at,.L0f0d7ed0
/*  f0d7e48:	afae0050 */ 	sw	$t6,0x50($sp)
/*  f0d7e4c:	3c198007 */ 	lui	$t9,%hi(var80070f80)
/*  f0d7e50:	27390f80 */ 	addiu	$t9,$t9,%lo(var80070f80)
/*  f0d7e54:	9b210002 */ 	lwr	$at,0x2($t9)
/*  f0d7e58:	27af004c */ 	addiu	$t7,$sp,0x4c
/*  f0d7e5c:	2498002f */ 	addiu	$t8,$a0,0x2f
/*  f0d7e60:	b9e10002 */ 	swr	$at,0x2($t7)
/*  f0d7e64:	0c002f02 */ 	jal	viGetWidth
/*  f0d7e68:	a3b8004c */ 	sb	$t8,0x4c($sp)
/*  f0d7e6c:	0c002f06 */ 	jal	viGetHeight
/*  f0d7e70:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f0d7e74:	3c0f8008 */ 	lui	$t7,%hi(g_FontNumeric1)
/*  f0d7e78:	8deffb00 */ 	lw	$t7,%lo(g_FontNumeric1)($t7)
/*  f0d7e7c:	3c198008 */ 	lui	$t9,%hi(g_FontNumeric2)
/*  f0d7e80:	8f39fafc */ 	lw	$t9,%lo(g_FontNumeric2)($t9)
/*  f0d7e84:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0d7e88:	87af0040 */ 	lh	$t7,0x40($sp)
/*  f0d7e8c:	3c0e00ff */ 	lui	$t6,0xff
/*  f0d7e90:	35ce00a0 */ 	ori	$t6,$t6,0xa0
/*  f0d7e94:	241800a0 */ 	addiu	$t8,$zero,0xa0
/*  f0d7e98:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f0d7e9c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0d7ea0:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0d7ea4:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f0d7ea8:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f0d7eac:	27a7004c */ 	addiu	$a3,$sp,0x4c
/*  f0d7eb0:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0d7eb4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0d7eb8:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0d7ebc:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f0d7ec0:	0fc55b92 */ 	jal	textRender
/*  f0d7ec4:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0d7ec8:	1000001d */ 	b	.L0f0d7f40
/*  f0d7ecc:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0d7ed0:
/*  f0d7ed0:	0fc5b9f1 */ 	jal	langGet
/*  f0d7ed4:	00000000 */ 	nop
/*  f0d7ed8:	0c002f02 */ 	jal	viGetWidth
/*  f0d7edc:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f0d7ee0:	0c002f06 */ 	jal	viGetHeight
/*  f0d7ee4:	a7a20040 */ 	sh	$v0,0x40($sp)
/*  f0d7ee8:	3c198008 */ 	lui	$t9,%hi(g_FontHandelGothicXs1)
/*  f0d7eec:	8f39fb08 */ 	lw	$t9,%lo(g_FontHandelGothicXs1)($t9)
/*  f0d7ef0:	3c0e8008 */ 	lui	$t6,%hi(g_FontHandelGothicXs2)
/*  f0d7ef4:	8dcefb04 */ 	lw	$t6,%lo(g_FontHandelGothicXs2)($t6)
/*  f0d7ef8:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0d7efc:	87b90040 */ 	lh	$t9,0x40($sp)
/*  f0d7f00:	3c1800ff */ 	lui	$t8,0xff
/*  f0d7f04:	371800a0 */ 	ori	$t8,$t8,0xa0
/*  f0d7f08:	240f00a0 */ 	addiu	$t7,$zero,0xa0
/*  f0d7f0c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0d7f10:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f0d7f14:	8fa40098 */ 	lw	$a0,0x98($sp)
/*  f0d7f18:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f0d7f1c:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f0d7f20:	8fa70048 */ 	lw	$a3,0x48($sp)
/*  f0d7f24:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0d7f28:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0d7f2c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0d7f30:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0d7f34:	0fc55b92 */ 	jal	textRender
/*  f0d7f38:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f0d7f3c:	afa20098 */ 	sw	$v0,0x98($sp)
.L0f0d7f40:
/*  f0d7f40:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0d7f44:
/*  f0d7f44:	8fa20098 */ 	lw	$v0,0x98($sp)
/*  f0d7f48:	27bd0098 */ 	addiu	$sp,$sp,0x98
/*  f0d7f4c:	03e00008 */ 	jr	$ra
/*  f0d7f50:	00000000 */ 	nop
);
#endif

GLOBAL_ASM(
glabel func0f0d7f54
/*  f0d7f54:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f0d7f58:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0d7f5c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0d7f60:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0d7f64:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0d7f68:	00a08825 */ 	or	$s1,$a1,$zero
/*  f0d7f6c:	00c09025 */ 	or	$s2,$a2,$zero
/*  f0d7f70:	00e09825 */ 	or	$s3,$a3,$zero
/*  f0d7f74:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d7f78:	0c002f40 */ 	jal	viGetViewLeft
/*  f0d7f7c:	afa400d0 */ 	sw	$a0,0xd0($sp)
/*  f0d7f80:	3c108008 */ 	lui	$s0,%hi(g_ScaleX)
/*  f0d7f84:	2610fac0 */ 	addiu	$s0,$s0,%lo(g_ScaleX)
/*  f0d7f88:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0d7f8c:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*  f0d7f90:	004e001a */ 	div	$zero,$v0,$t6
/*  f0d7f94:	00007812 */ 	mflo	$t7
/*  f0d7f98:	afaf00cc */ 	sw	$t7,0xcc($sp)
/*  f0d7f9c:	15c00002 */ 	bnez	$t6,.L0f0d7fa8
/*  f0d7fa0:	00000000 */ 	nop
/*  f0d7fa4:	0007000d */ 	break	0x7
.L0f0d7fa8:
/*  f0d7fa8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d7fac:	15c10004 */ 	bne	$t6,$at,.L0f0d7fc0
/*  f0d7fb0:	3c018000 */ 	lui	$at,0x8000
/*  f0d7fb4:	14410002 */ 	bne	$v0,$at,.L0f0d7fc0
/*  f0d7fb8:	00000000 */ 	nop
/*  f0d7fbc:	0006000d */ 	break	0x6
.L0f0d7fc0:
/*  f0d7fc0:	0c002f44 */ 	jal	viGetViewTop
/*  f0d7fc4:	00000000 */ 	nop
/*  f0d7fc8:	0c002f22 */ 	jal	viGetViewWidth
/*  f0d7fcc:	afa200c8 */ 	sw	$v0,0xc8($sp)
/*  f0d7fd0:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0d7fd4:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*  f0d7fd8:	0058001a */ 	div	$zero,$v0,$t8
/*  f0d7fdc:	0000c812 */ 	mflo	$t9
/*  f0d7fe0:	afb900c4 */ 	sw	$t9,0xc4($sp)
/*  f0d7fe4:	17000002 */ 	bnez	$t8,.L0f0d7ff0
/*  f0d7fe8:	00000000 */ 	nop
/*  f0d7fec:	0007000d */ 	break	0x7
.L0f0d7ff0:
/*  f0d7ff0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d7ff4:	17010004 */ 	bne	$t8,$at,.L0f0d8008
/*  f0d7ff8:	3c018000 */ 	lui	$at,0x8000
/*  f0d7ffc:	14410002 */ 	bne	$v0,$at,.L0f0d8008
/*  f0d8000:	00000000 */ 	nop
/*  f0d8004:	0006000d */ 	break	0x6
.L0f0d8008:
/*  f0d8008:	0c002f26 */ 	jal	viGetViewHeight
/*  f0d800c:	00000000 */ 	nop
/*  f0d8010:	8fae00c8 */ 	lw	$t6,0xc8($sp)
/*  f0d8014:	3c0500ff */ 	lui	$a1,0xff
/*  f0d8018:	8fa400d0 */ 	lw	$a0,0xd0($sp)
/*  f0d801c:	01c26821 */ 	addu	$t5,$t6,$v0
/*  f0d8020:	25adffff */ 	addiu	$t5,$t5,-1
/*  f0d8024:	afad00b8 */ 	sw	$t5,0xb8($sp)
/*  f0d8028:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0d802c:	34a50028 */ 	ori	$a1,$a1,0x28
/*  f0d8030:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0d8034:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0d8038:	8c6f006c */ 	lw	$t7,0x6c($v1)
/*  f0d803c:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*  f0d8040:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0d8044:	11e00003 */ 	beqz	$t7,.L0f0d8054
/*  f0d8048:	00003025 */ 	or	$a2,$zero,$zero
/*  f0d804c:	10000001 */ 	b	.L0f0d8054
/*  f0d8050:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f0d8054:
/*  f0d8054:	8c780068 */ 	lw	$t8,0x68($v1)
/*  f0d8058:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d805c:	00002825 */ 	or	$a1,$zero,$zero
/*  f0d8060:	13000003 */ 	beqz	$t8,.L0f0d8070
/*  f0d8064:	00000000 */ 	nop
/*  f0d8068:	10000001 */ 	b	.L0f0d8070
/*  f0d806c:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0d8070:
/*  f0d8070:	8c790064 */ 	lw	$t9,0x64($v1)
/*  f0d8074:	13200003 */ 	beqz	$t9,.L0f0d8084
/*  f0d8078:	00000000 */ 	nop
/*  f0d807c:	10000001 */ 	b	.L0f0d8084
/*  f0d8080:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0d8084:
/*  f0d8084:	8c6e0070 */ 	lw	$t6,0x70($v1)
/*  f0d8088:	00001825 */ 	or	$v1,$zero,$zero
/*  f0d808c:	11c00003 */ 	beqz	$t6,.L0f0d809c
/*  f0d8090:	00000000 */ 	nop
/*  f0d8094:	10000001 */ 	b	.L0f0d809c
/*  f0d8098:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0d809c:
/*  f0d809c:	00657821 */ 	addu	$t7,$v1,$a1
/*  f0d80a0:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f0d80a4:	0306c821 */ 	addu	$t9,$t8,$a2
/*  f0d80a8:	57210066 */ 	bnel	$t9,$at,.L0f0d8244
/*  f0d80ac:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0d80b0:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0d80b4:	02333023 */ 	subu	$a2,$s1,$s3
/*  f0d80b8:	24d80003 */ 	addiu	$t8,$a2,0x3
/*  f0d80bc:	03190019 */ 	multu	$t8,$t9
/*  f0d80c0:	26470001 */ 	addiu	$a3,$s2,0x1
/*  f0d80c4:	30ee03ff */ 	andi	$t6,$a3,0x3ff
/*  f0d80c8:	000e3880 */ 	sll	$a3,$t6,0x2
/*  f0d80cc:	3c03f600 */ 	lui	$v1,0xf600
/*  f0d80d0:	8fab00cc */ 	lw	$t3,0xcc($sp)
/*  f0d80d4:	324803ff */ 	andi	$t0,$s2,0x3ff
/*  f0d80d8:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0d80dc:	00804825 */ 	or	$t1,$a0,$zero
/*  f0d80e0:	02335021 */ 	addu	$t2,$s1,$s3
/*  f0d80e4:	00007012 */ 	mflo	$t6
/*  f0d80e8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d80ec:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d80f0:	0303c825 */ 	or	$t9,$t8,$v1
/*  f0d80f4:	03277025 */ 	or	$t6,$t9,$a3
/*  f0d80f8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0d80fc:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0d8100:	25780030 */ 	addiu	$t8,$t3,0x30
/*  f0d8104:	00087880 */ 	sll	$t7,$t0,0x2
/*  f0d8108:	03190019 */ 	multu	$t8,$t9
/*  f0d810c:	01e04025 */ 	or	$t0,$t7,$zero
/*  f0d8110:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d8114:	00806025 */ 	or	$t4,$a0,$zero
/*  f0d8118:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d811c:	00802825 */ 	or	$a1,$a0,$zero
/*  f0d8120:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d8124:	00007012 */ 	mflo	$t6
/*  f0d8128:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d812c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d8130:	0308c825 */ 	or	$t9,$t8,$t0
/*  f0d8134:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0d8138:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f0d813c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0d8140:	26220001 */ 	addiu	$v0,$s1,0x1
/*  f0d8144:	016e7821 */ 	addu	$t7,$t3,$t6
/*  f0d8148:	25f8ffcf */ 	addiu	$t8,$t7,-49
/*  f0d814c:	03190019 */ 	multu	$t8,$t9
/*  f0d8150:	02535821 */ 	addu	$t3,$s2,$s3
/*  f0d8154:	00007012 */ 	mflo	$t6
/*  f0d8158:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d815c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d8160:	0303c825 */ 	or	$t9,$t8,$v1
/*  f0d8164:	03277025 */ 	or	$t6,$t9,$a3
/*  f0d8168:	ad2e0000 */ 	sw	$t6,0x0($t1)
/*  f0d816c:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0d8170:	254ffffe */ 	addiu	$t7,$t2,-2
/*  f0d8174:	02533823 */ 	subu	$a3,$s2,$s3
/*  f0d8178:	01f80019 */ 	multu	$t7,$t8
/*  f0d817c:	0000c812 */ 	mflo	$t9
/*  f0d8180:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0d8184:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0d8188:	01e8c025 */ 	or	$t8,$t7,$t0
/*  f0d818c:	ad380004 */ 	sw	$t8,0x4($t1)
/*  f0d8190:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0d8194:	00590019 */ 	multu	$v0,$t9
/*  f0d8198:	00007012 */ 	mflo	$t6
/*  f0d819c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d81a0:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d81a4:	24ee0003 */ 	addiu	$t6,$a3,0x3
/*  f0d81a8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d81ac:	0303c825 */ 	or	$t9,$t8,$v1
/*  f0d81b0:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0d81b4:	03387025 */ 	or	$t6,$t9,$t8
/*  f0d81b8:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f0d81bc:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0d81c0:	022f0019 */ 	multu	$s1,$t7
/*  f0d81c4:	8faf00c8 */ 	lw	$t7,0xc8($sp)
/*  f0d81c8:	0000c812 */ 	mflo	$t9
/*  f0d81cc:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0d81d0:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0d81d4:	25f9000a */ 	addiu	$t9,$t7,0xa
/*  f0d81d8:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0d81dc:	00187880 */ 	sll	$t7,$t8,0x2
/*  f0d81e0:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f0d81e4:	ad990004 */ 	sw	$t9,0x4($t4)
/*  f0d81e8:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0d81ec:	00580019 */ 	multu	$v0,$t8
/*  f0d81f0:	00007012 */ 	mflo	$t6
/*  f0d81f4:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d81f8:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f0d81fc:	25aefff7 */ 	addiu	$t6,$t5,-9
/*  f0d8200:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d8204:	0323c025 */ 	or	$t8,$t9,$v1
/*  f0d8208:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f0d820c:	03197025 */ 	or	$t6,$t8,$t9
/*  f0d8210:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f0d8214:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0d8218:	022f0019 */ 	multu	$s1,$t7
/*  f0d821c:	256ffffe */ 	addiu	$t7,$t3,-2
/*  f0d8220:	0000c012 */ 	mflo	$t8
/*  f0d8224:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d8228:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0d822c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0d8230:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0d8234:	01d97825 */ 	or	$t7,$t6,$t9
/*  f0d8238:	10000061 */ 	b	.L0f0d83c0
/*  f0d823c:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f0d8240:	8e0f0000 */ 	lw	$t7,0x0($s0)
.L0f0d8244:
/*  f0d8244:	02333023 */ 	subu	$a2,$s1,$s3
/*  f0d8248:	24d90003 */ 	addiu	$t9,$a2,0x3
/*  f0d824c:	032f0019 */ 	multu	$t9,$t7
/*  f0d8250:	26470001 */ 	addiu	$a3,$s2,0x1
/*  f0d8254:	30f803ff */ 	andi	$t8,$a3,0x3ff
/*  f0d8258:	00183880 */ 	sll	$a3,$t8,0x2
/*  f0d825c:	3c03f600 */ 	lui	$v1,0xf600
/*  f0d8260:	8fab00cc */ 	lw	$t3,0xcc($sp)
/*  f0d8264:	324803ff */ 	andi	$t0,$s2,0x3ff
/*  f0d8268:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f0d826c:	00804825 */ 	or	$t1,$a0,$zero
/*  f0d8270:	02335021 */ 	addu	$t2,$s1,$s3
/*  f0d8274:	0000c012 */ 	mflo	$t8
/*  f0d8278:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0d827c:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0d8280:	03237825 */ 	or	$t7,$t9,$v1
/*  f0d8284:	01e7c025 */ 	or	$t8,$t7,$a3
/*  f0d8288:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0d828c:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0d8290:	00087080 */ 	sll	$t6,$t0,0x2
/*  f0d8294:	01c04025 */ 	or	$t0,$t6,$zero
/*  f0d8298:	01790019 */ 	multu	$t3,$t9
/*  f0d829c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d82a0:	00806025 */ 	or	$t4,$a0,$zero
/*  f0d82a4:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d82a8:	00802825 */ 	or	$a1,$a0,$zero
/*  f0d82ac:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d82b0:	00007812 */ 	mflo	$t7
/*  f0d82b4:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0d82b8:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0d82bc:	01c8c825 */ 	or	$t9,$t6,$t0
/*  f0d82c0:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0d82c4:	8faf00c4 */ 	lw	$t7,0xc4($sp)
/*  f0d82c8:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0d82cc:	26220001 */ 	addiu	$v0,$s1,0x1
/*  f0d82d0:	016fc021 */ 	addu	$t8,$t3,$t7
/*  f0d82d4:	030e0019 */ 	multu	$t8,$t6
/*  f0d82d8:	02535821 */ 	addu	$t3,$s2,$s3
/*  f0d82dc:	0000c812 */ 	mflo	$t9
/*  f0d82e0:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0d82e4:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d82e8:	03037025 */ 	or	$t6,$t8,$v1
/*  f0d82ec:	01c7c825 */ 	or	$t9,$t6,$a3
/*  f0d82f0:	ad390000 */ 	sw	$t9,0x0($t1)
/*  f0d82f4:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0d82f8:	254ffffe */ 	addiu	$t7,$t2,-2
/*  f0d82fc:	02533823 */ 	subu	$a3,$s2,$s3
/*  f0d8300:	01f80019 */ 	multu	$t7,$t8
/*  f0d8304:	00007012 */ 	mflo	$t6
/*  f0d8308:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0d830c:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0d8310:	01e8c025 */ 	or	$t8,$t7,$t0
/*  f0d8314:	ad380004 */ 	sw	$t8,0x4($t1)
/*  f0d8318:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0d831c:	004e0019 */ 	multu	$v0,$t6
/*  f0d8320:	0000c812 */ 	mflo	$t9
/*  f0d8324:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0d8328:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d832c:	24f90003 */ 	addiu	$t9,$a3,0x3
/*  f0d8330:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0d8334:	03037025 */ 	or	$t6,$t8,$v1
/*  f0d8338:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0d833c:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0d8340:	ad990000 */ 	sw	$t9,0x0($t4)
/*  f0d8344:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0d8348:	022f0019 */ 	multu	$s1,$t7
/*  f0d834c:	8faf00c8 */ 	lw	$t7,0xc8($sp)
/*  f0d8350:	00007012 */ 	mflo	$t6
/*  f0d8354:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0d8358:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d835c:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0d8360:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f0d8364:	03387825 */ 	or	$t7,$t9,$t8
/*  f0d8368:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f0d836c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0d8370:	004e0019 */ 	multu	$v0,$t6
/*  f0d8374:	0000c812 */ 	mflo	$t9
/*  f0d8378:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0d837c:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f0d8380:	25b90001 */ 	addiu	$t9,$t5,0x1
/*  f0d8384:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0d8388:	01e37025 */ 	or	$t6,$t7,$v1
/*  f0d838c:	00187880 */ 	sll	$t7,$t8,0x2
/*  f0d8390:	01cfc825 */ 	or	$t9,$t6,$t7
/*  f0d8394:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f0d8398:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0d839c:	02380019 */ 	multu	$s1,$t8
/*  f0d83a0:	2578fffe */ 	addiu	$t8,$t3,-2
/*  f0d83a4:	00007012 */ 	mflo	$t6
/*  f0d83a8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d83ac:	000fcb80 */ 	sll	$t9,$t7,0xe
/*  f0d83b0:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0d83b4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0d83b8:	032fc025 */ 	or	$t8,$t9,$t7
/*  f0d83bc:	acb80004 */ 	sw	$t8,0x4($a1)
.L0f0d83c0:
/*  f0d83c0:	afa60054 */ 	sw	$a2,0x54($sp)
/*  f0d83c4:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0d83c8:	afaa0050 */ 	sw	$t2,0x50($sp)
/*  f0d83cc:	0fc54e0e */ 	jal	func0f153838
/*  f0d83d0:	afab0048 */ 	sw	$t3,0x48($sp)
/*  f0d83d4:	00402025 */ 	or	$a0,$v0,$zero
/*  f0d83d8:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0d83dc:	8fa500e4 */ 	lw	$a1,0xe4($sp)
/*  f0d83e0:	8fa60054 */ 	lw	$a2,0x54($sp)
/*  f0d83e4:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0d83e8:	8fab0048 */ 	lw	$t3,0x48($sp)
/*  f0d83ec:	24cc0001 */ 	addiu	$t4,$a2,0x1
/*  f0d83f0:	018f0019 */ 	multu	$t4,$t7
/*  f0d83f4:	25680001 */ 	addiu	$t0,$t3,0x1
/*  f0d83f8:	310e03ff */ 	andi	$t6,$t0,0x3ff
/*  f0d83fc:	000e4080 */ 	sll	$t0,$t6,0x2
/*  f0d8400:	3c03f600 */ 	lui	$v1,0xf600
/*  f0d8404:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0d8408:	8faa0050 */ 	lw	$t2,0x50($sp)
/*  f0d840c:	244d0018 */ 	addiu	$t5,$v0,0x18
/*  f0d8410:	30e503ff */ 	andi	$a1,$a3,0x3ff
/*  f0d8414:	25490001 */ 	addiu	$t1,$t2,0x1
/*  f0d8418:	0000c012 */ 	mflo	$t8
/*  f0d841c:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0d8420:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0d8424:	03237825 */ 	or	$t7,$t9,$v1
/*  f0d8428:	01e8c025 */ 	or	$t8,$t7,$t0
/*  f0d842c:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0d8430:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0d8434:	00057080 */ 	sll	$t6,$a1,0x2
/*  f0d8438:	01c02825 */ 	or	$a1,$t6,$zero
/*  f0d843c:	00d90019 */ 	multu	$a2,$t9
/*  f0d8440:	24ff0001 */ 	addiu	$ra,$a3,0x1
/*  f0d8444:	317303ff */ 	andi	$s3,$t3,0x3ff
/*  f0d8448:	25a40008 */ 	addiu	$a0,$t5,0x8
/*  f0d844c:	00007812 */ 	mflo	$t7
/*  f0d8450:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0d8454:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0d8458:	01c5c825 */ 	or	$t9,$t6,$a1
/*  f0d845c:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0d8460:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0d8464:	012f0019 */ 	multu	$t1,$t7
/*  f0d8468:	0000c012 */ 	mflo	$t8
/*  f0d846c:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0d8470:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0d8474:	03237825 */ 	or	$t7,$t9,$v1
/*  f0d8478:	01e8c025 */ 	or	$t8,$t7,$t0
/*  f0d847c:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f0d8480:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0d8484:	014e0019 */ 	multu	$t2,$t6
/*  f0d8488:	0000c812 */ 	mflo	$t9
/*  f0d848c:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0d8490:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d8494:	03057025 */ 	or	$t6,$t8,$a1
/*  f0d8498:	ac4e000c */ 	sw	$t6,0xc($v0)
/*  f0d849c:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0d84a0:	33f903ff */ 	andi	$t9,$ra,0x3ff
/*  f0d84a4:	0019f880 */ 	sll	$ra,$t9,0x2
/*  f0d84a8:	01380019 */ 	multu	$t1,$t8
/*  f0d84ac:	00007012 */ 	mflo	$t6
/*  f0d84b0:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0d84b4:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0d84b8:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0d84bc:	031f7025 */ 	or	$t6,$t8,$ra
/*  f0d84c0:	ac4e0010 */ 	sw	$t6,0x10($v0)
/*  f0d84c4:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0d84c8:	00d90019 */ 	multu	$a2,$t9
/*  f0d84cc:	00007812 */ 	mflo	$t7
/*  f0d84d0:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0d84d4:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0d84d8:	01c5c825 */ 	or	$t9,$t6,$a1
/*  f0d84dc:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f0d84e0:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0d84e4:	012f0019 */ 	multu	$t1,$t7
/*  f0d84e8:	0000c012 */ 	mflo	$t8
/*  f0d84ec:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0d84f0:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0d84f4:	03237825 */ 	or	$t7,$t9,$v1
/*  f0d84f8:	01e8c025 */ 	or	$t8,$t7,$t0
/*  f0d84fc:	adb80000 */ 	sw	$t8,0x0($t5)
/*  f0d8500:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0d8504:	00137080 */ 	sll	$t6,$s3,0x2
/*  f0d8508:	01c09825 */ 	or	$s3,$t6,$zero
/*  f0d850c:	00d90019 */ 	multu	$a2,$t9
/*  f0d8510:	00007812 */ 	mflo	$t7
/*  f0d8514:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0d8518:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0d851c:	01d3c825 */ 	or	$t9,$t6,$s3
/*  f0d8520:	adb90004 */ 	sw	$t9,0x4($t5)
/*  f0d8524:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f0d8528:	afa40084 */ 	sw	$a0,0x84($sp)
/*  f0d852c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d8530:	024fc023 */ 	subu	$t8,$s2,$t7
/*  f0d8534:	270e0001 */ 	addiu	$t6,$t8,0x1
/*  f0d8538:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0d853c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0d8540:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f0d8544:	afb8002c */ 	sw	$t8,0x2c($sp)
/*  f0d8548:	018e0019 */ 	multu	$t4,$t6
/*  f0d854c:	00801025 */ 	or	$v0,$a0,$zero
/*  f0d8550:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d8554:	00805825 */ 	or	$t3,$a0,$zero
/*  f0d8558:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d855c:	0000c812 */ 	mflo	$t9
/*  f0d8560:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0d8564:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0d8568:	03237025 */ 	or	$t6,$t9,$v1
/*  f0d856c:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0d8570:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f0d8574:	add90000 */ 	sw	$t9,0x0($t6)
/*  f0d8578:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0d857c:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f0d8580:	01e09825 */ 	or	$s3,$t7,$zero
/*  f0d8584:	00d80019 */ 	multu	$a2,$t8
/*  f0d8588:	02533821 */ 	addu	$a3,$s2,$s3
/*  f0d858c:	02336823 */ 	subu	$t5,$s1,$s3
/*  f0d8590:	25ad0001 */ 	addiu	$t5,$t5,0x1
/*  f0d8594:	0000c812 */ 	mflo	$t9
/*  f0d8598:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0d859c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d85a0:	0305c825 */ 	or	$t9,$t8,$a1
/*  f0d85a4:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0d85a8:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0d85ac:	018f0019 */ 	multu	$t4,$t7
/*  f0d85b0:	0000c012 */ 	mflo	$t8
/*  f0d85b4:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d85b8:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0d85bc:	01c37825 */ 	or	$t7,$t6,$v1
/*  f0d85c0:	01e8c025 */ 	or	$t8,$t7,$t0
/*  f0d85c4:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0d85c8:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0d85cc:	30f903ff */ 	andi	$t9,$a3,0x3ff
/*  f0d85d0:	00193880 */ 	sll	$a3,$t9,0x2
/*  f0d85d4:	00cf0019 */ 	multu	$a2,$t7
/*  f0d85d8:	0000c012 */ 	mflo	$t8
/*  f0d85dc:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d85e0:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0d85e4:	01c77825 */ 	or	$t7,$t6,$a3
/*  f0d85e8:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0d85ec:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0d85f0:	00801025 */ 	or	$v0,$a0,$zero
/*  f0d85f4:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d85f8:	01380019 */ 	multu	$t1,$t8
/*  f0d85fc:	00806025 */ 	or	$t4,$a0,$zero
/*  f0d8600:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d8604:	0000c812 */ 	mflo	$t9
/*  f0d8608:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0d860c:	8fb9002c */ 	lw	$t9,0x2c($sp)
/*  f0d8610:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0d8614:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0d8618:	03197025 */ 	or	$t6,$t8,$t9
/*  f0d861c:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f0d8620:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0d8624:	014f0019 */ 	multu	$t2,$t7
/*  f0d8628:	0000c012 */ 	mflo	$t8
/*  f0d862c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d8630:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0d8634:	01c57825 */ 	or	$t7,$t6,$a1
/*  f0d8638:	ad6f0004 */ 	sw	$t7,0x4($t3)
/*  f0d863c:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0d8640:	01380019 */ 	multu	$t1,$t8
/*  f0d8644:	0000c812 */ 	mflo	$t9
/*  f0d8648:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0d864c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0d8650:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0d8654:	0308c825 */ 	or	$t9,$t8,$t0
/*  f0d8658:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0d865c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0d8660:	014e0019 */ 	multu	$t2,$t6
/*  f0d8664:	00007812 */ 	mflo	$t7
/*  f0d8668:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0d866c:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d8670:	03277025 */ 	or	$t6,$t9,$a3
/*  f0d8674:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0d8678:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0d867c:	00801025 */ 	or	$v0,$a0,$zero
/*  f0d8680:	02333821 */ 	addu	$a3,$s1,$s3
/*  f0d8684:	01af0019 */ 	multu	$t5,$t7
/*  f0d8688:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d868c:	00805025 */ 	or	$t2,$a0,$zero
/*  f0d8690:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d8694:	0000c012 */ 	mflo	$t8
/*  f0d8698:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d869c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0d86a0:	01c37825 */ 	or	$t7,$t6,$v1
/*  f0d86a4:	01ffc025 */ 	or	$t8,$t7,$ra
/*  f0d86a8:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0d86ac:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0d86b0:	00d90019 */ 	multu	$a2,$t9
/*  f0d86b4:	00007012 */ 	mflo	$t6
/*  f0d86b8:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d86bc:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d86c0:	0305c825 */ 	or	$t9,$t8,$a1
/*  f0d86c4:	ad990004 */ 	sw	$t9,0x4($t4)
/*  f0d86c8:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0d86cc:	012e0019 */ 	multu	$t1,$t6
/*  f0d86d0:	00007812 */ 	mflo	$t7
/*  f0d86d4:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0d86d8:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d86dc:	03237025 */ 	or	$t6,$t9,$v1
/*  f0d86e0:	01df7825 */ 	or	$t7,$t6,$ra
/*  f0d86e4:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0d86e8:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0d86ec:	00f80019 */ 	multu	$a3,$t8
/*  f0d86f0:	0000c812 */ 	mflo	$t9
/*  f0d86f4:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0d86f8:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0d86fc:	01e5c025 */ 	or	$t8,$t7,$a1
/*  f0d8700:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0d8704:	8e190000 */ 	lw	$t9,0x0($s0)
/*  f0d8708:	00801025 */ 	or	$v0,$a0,$zero
/*  f0d870c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f0d8710:	01b90019 */ 	multu	$t5,$t9
/*  f0d8714:	00007012 */ 	mflo	$t6
/*  f0d8718:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d871c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d8720:	0303c825 */ 	or	$t9,$t8,$v1
/*  f0d8724:	03287025 */ 	or	$t6,$t9,$t0
/*  f0d8728:	ad4e0000 */ 	sw	$t6,0x0($t2)
/*  f0d872c:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f0d8730:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f0d8734:	00cf0019 */ 	multu	$a2,$t7
/*  f0d8738:	0000c012 */ 	mflo	$t8
/*  f0d873c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d8740:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0d8744:	01c57825 */ 	or	$t7,$t6,$a1
/*  f0d8748:	ad4f0004 */ 	sw	$t7,0x4($t2)
/*  f0d874c:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f0d8750:	01380019 */ 	multu	$t1,$t8
/*  f0d8754:	0000c812 */ 	mflo	$t9
/*  f0d8758:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0d875c:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0d8760:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0d8764:	0308c825 */ 	or	$t9,$t8,$t0
/*  f0d8768:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0d876c:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f0d8770:	00ee0019 */ 	multu	$a3,$t6
/*  f0d8774:	00007812 */ 	mflo	$t7
/*  f0d8778:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0d877c:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d8780:	03257025 */ 	or	$t6,$t9,$a1
/*  f0d8784:	0fc54e0e */ 	jal	func0f153838
/*  f0d8788:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0d878c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0d8790:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0d8794:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0d8798:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f0d879c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f0d87a0:	03e00008 */ 	jr	$ra
/*  f0d87a4:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f0d87a8
.late_rodata
glabel var7f1adde0
.word 0xc019999a
glabel var7f1adde4
.word 0x4019999a
glabel var7f1adde8
.word 0x3d4ccccd
glabel var7f1af0bcpf
.word 0x3d75c290
glabel var7f1af0c0pf
.word 0xbd75c290
glabel var7f1af0c4pf
.word 0x3d4ccccd
glabel var7f1af0c8pf
.word 0x3d75c290
glabel var7f1af0ccpf
.word 0xbd75c290
.text
/*  f0d8d48:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f0d8d4c:	3c03800a */ 	lui	$v1,0x800a
/*  f0d8d50:	8c63a548 */ 	lw	$v1,-0x5ab8($v1)
/*  f0d8d54:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f0d8d58:	00808025 */ 	move	$s0,$a0
/*  f0d8d5c:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0d8d60:	f7be0040 */ 	sdc1	$f30,0x40($sp)
/*  f0d8d64:	f7bc0038 */ 	sdc1	$f28,0x38($sp)
/*  f0d8d68:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f0d8d6c:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f0d8d70:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f0d8d74:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0d8d78:	afa500d4 */ 	sw	$a1,0xd4($sp)
/*  f0d8d7c:	afa600d8 */ 	sw	$a2,0xd8($sp)
/*  f0d8d80:	afa700dc */ 	sw	$a3,0xdc($sp)
/*  f0d8d84:	1860008c */ 	blez	$v1,.PF0f0d8fb8
/*  f0d8d88:	00001025 */ 	move	$v0,$zero
/*  f0d8d8c:	3c01bf00 */ 	lui	$at,0xbf00
/*  f0d8d90:	4481f000 */ 	mtc1	$at,$f30
/*  f0d8d94:	3c013f00 */ 	lui	$at,0x3f00
/*  f0d8d98:	4481e000 */ 	mtc1	$at,$f28
/*  f0d8d9c:	3c018007 */ 	lui	$at,0x8007
/*  f0d8da0:	c43a1268 */ 	lwc1	$f26,0x1268($at)
/*  f0d8da4:	44852000 */ 	mtc1	$a1,$f4
/*  f0d8da8:	44864000 */ 	mtc1	$a2,$f8
/*  f0d8dac:	3c018007 */ 	lui	$at,0x8007
/*  f0d8db0:	c4381264 */ 	lwc1	$f24,0x1264($at)
/*  f0d8db4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d8db8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d8dbc:	c434f0b0 */ 	lwc1	$f20,-0xf50($at)
/*  f0d8dc0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d8dc4:	c432f0b4 */ 	lwc1	$f18,-0xf4c($at)
/*  f0d8dc8:	3c018007 */ 	lui	$at,0x8007
/*  f0d8dcc:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d8dd0:	c4301270 */ 	lwc1	$f16,0x1270($at)
/*  f0d8dd4:	3c018007 */ 	lui	$at,0x8007
/*  f0d8dd8:	4480b000 */ 	mtc1	$zero,$f22
/*  f0d8ddc:	c42e126c */ 	lwc1	$f14,0x126c($at)
/*  f0d8de0:	e7a60074 */ 	swc1	$f6,0x74($sp)
/*  f0d8de4:	e7aa006c */ 	swc1	$f10,0x6c($sp)
/*  f0d8de8:	c7a40074 */ 	lwc1	$f4,0x74($sp)
.PF0f0d8dec:
/*  f0d8dec:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d8df0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d8df4:	46182301 */ 	sub.s	$f12,$f4,$f24
/*  f0d8df8:	c7a8006c */ 	lwc1	$f8,0x6c($sp)
/*  f0d8dfc:	460ce03c */ 	c.lt.s	$f28,$f12
/*  f0d8e00:	00000000 */ 	nop
/*  f0d8e04:	45010005 */ 	bc1t	.PF0f0d8e1c
/*  f0d8e08:	00000000 */ 	nop
/*  f0d8e0c:	461e603c */ 	c.lt.s	$f12,$f30
/*  f0d8e10:	00000000 */ 	nop
/*  f0d8e14:	45020029 */ 	bc1fl	.PF0f0d8ebc
/*  f0d8e18:	c7b80074 */ 	lwc1	$f24,0x74($sp)
.PF0f0d8e1c:
/*  f0d8e1c:	c426f0b8 */ 	lwc1	$f6,-0xf48($at)
/*  f0d8e20:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d8e24:	46066002 */ 	mul.s	$f0,$f12,$f6
/*  f0d8e28:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0d8e2c:	00000000 */ 	nop
/*  f0d8e30:	45020003 */ 	bc1fl	.PF0f0d8e40
/*  f0d8e34:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0d8e38:	46009006 */ 	mov.s	$f0,$f18
/*  f0d8e3c:	4614003c */ 	c.lt.s	$f0,$f20
.PF0f0d8e40:
/*  f0d8e40:	00000000 */ 	nop
/*  f0d8e44:	45020003 */ 	bc1fl	.PF0f0d8e54
/*  f0d8e48:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0d8e4c:	4600a006 */ 	mov.s	$f0,$f20
/*  f0d8e50:	4600703c */ 	c.lt.s	$f14,$f0
.PF0f0d8e54:
/*  f0d8e54:	00000000 */ 	nop
/*  f0d8e58:	45020004 */ 	bc1fl	.PF0f0d8e6c
/*  f0d8e5c:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0d8e60:	10000008 */ 	b	.PF0f0d8e84
/*  f0d8e64:	c420f0bc */ 	lwc1	$f0,-0xf44($at)
/*  f0d8e68:	460e003c */ 	c.lt.s	$f0,$f14
.PF0f0d8e6c:
/*  f0d8e6c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d8e70:	45020004 */ 	bc1fl	.PF0f0d8e84
/*  f0d8e74:	4600b006 */ 	mov.s	$f0,$f22
/*  f0d8e78:	10000002 */ 	b	.PF0f0d8e84
/*  f0d8e7c:	c420f0c0 */ 	lwc1	$f0,-0xf40($at)
/*  f0d8e80:	4600b006 */ 	mov.s	$f0,$f22
.PF0f0d8e84:
/*  f0d8e84:	46007380 */ 	add.s	$f14,$f14,$f0
/*  f0d8e88:	460e903c */ 	c.lt.s	$f18,$f14
/*  f0d8e8c:	00000000 */ 	nop
/*  f0d8e90:	45020003 */ 	bc1fl	.PF0f0d8ea0
/*  f0d8e94:	4614703c */ 	c.lt.s	$f14,$f20
/*  f0d8e98:	46009386 */ 	mov.s	$f14,$f18
/*  f0d8e9c:	4614703c */ 	c.lt.s	$f14,$f20
.PF0f0d8ea0:
/*  f0d8ea0:	00000000 */ 	nop
/*  f0d8ea4:	45000002 */ 	bc1f	.PF0f0d8eb0
/*  f0d8ea8:	00000000 */ 	nop
/*  f0d8eac:	4600a386 */ 	mov.s	$f14,$f20
.PF0f0d8eb0:
/*  f0d8eb0:	10000003 */ 	b	.PF0f0d8ec0
/*  f0d8eb4:	460ec600 */ 	add.s	$f24,$f24,$f14
/*  f0d8eb8:	c7b80074 */ 	lwc1	$f24,0x74($sp)
.PF0f0d8ebc:
/*  f0d8ebc:	4600b386 */ 	mov.s	$f14,$f22
.PF0f0d8ec0:
/*  f0d8ec0:	461a4301 */ 	sub.s	$f12,$f8,$f26
/*  f0d8ec4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d8ec8:	460ce03c */ 	c.lt.s	$f28,$f12
/*  f0d8ecc:	00000000 */ 	nop
/*  f0d8ed0:	45010005 */ 	bc1t	.PF0f0d8ee8
/*  f0d8ed4:	00000000 */ 	nop
/*  f0d8ed8:	461e603c */ 	c.lt.s	$f12,$f30
/*  f0d8edc:	00000000 */ 	nop
/*  f0d8ee0:	45020029 */ 	bc1fl	.PF0f0d8f88
/*  f0d8ee4:	c7ba006c */ 	lwc1	$f26,0x6c($sp)
.PF0f0d8ee8:
/*  f0d8ee8:	c42af0c4 */ 	lwc1	$f10,-0xf3c($at)
/*  f0d8eec:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d8ef0:	460a6002 */ 	mul.s	$f0,$f12,$f10
/*  f0d8ef4:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0d8ef8:	00000000 */ 	nop
/*  f0d8efc:	45020003 */ 	bc1fl	.PF0f0d8f0c
/*  f0d8f00:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0d8f04:	46009006 */ 	mov.s	$f0,$f18
/*  f0d8f08:	4614003c */ 	c.lt.s	$f0,$f20
.PF0f0d8f0c:
/*  f0d8f0c:	00000000 */ 	nop
/*  f0d8f10:	45020003 */ 	bc1fl	.PF0f0d8f20
/*  f0d8f14:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0d8f18:	4600a006 */ 	mov.s	$f0,$f20
/*  f0d8f1c:	4600803c */ 	c.lt.s	$f16,$f0
.PF0f0d8f20:
/*  f0d8f20:	00000000 */ 	nop
/*  f0d8f24:	45020004 */ 	bc1fl	.PF0f0d8f38
/*  f0d8f28:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0d8f2c:	10000008 */ 	b	.PF0f0d8f50
/*  f0d8f30:	c420f0c8 */ 	lwc1	$f0,-0xf38($at)
/*  f0d8f34:	4610003c */ 	c.lt.s	$f0,$f16
.PF0f0d8f38:
/*  f0d8f38:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0d8f3c:	45020004 */ 	bc1fl	.PF0f0d8f50
/*  f0d8f40:	4600b006 */ 	mov.s	$f0,$f22
/*  f0d8f44:	10000002 */ 	b	.PF0f0d8f50
/*  f0d8f48:	c420f0cc */ 	lwc1	$f0,-0xf34($at)
/*  f0d8f4c:	4600b006 */ 	mov.s	$f0,$f22
.PF0f0d8f50:
/*  f0d8f50:	46008400 */ 	add.s	$f16,$f16,$f0
/*  f0d8f54:	4610903c */ 	c.lt.s	$f18,$f16
/*  f0d8f58:	00000000 */ 	nop
/*  f0d8f5c:	45020003 */ 	bc1fl	.PF0f0d8f6c
/*  f0d8f60:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0d8f64:	46009406 */ 	mov.s	$f16,$f18
/*  f0d8f68:	4614803c */ 	c.lt.s	$f16,$f20
.PF0f0d8f6c:
/*  f0d8f6c:	00000000 */ 	nop
/*  f0d8f70:	45000002 */ 	bc1f	.PF0f0d8f7c
/*  f0d8f74:	00000000 */ 	nop
/*  f0d8f78:	4600a406 */ 	mov.s	$f16,$f20
.PF0f0d8f7c:
/*  f0d8f7c:	10000003 */ 	b	.PF0f0d8f8c
/*  f0d8f80:	4610d680 */ 	add.s	$f26,$f26,$f16
/*  f0d8f84:	c7ba006c */ 	lwc1	$f26,0x6c($sp)
.PF0f0d8f88:
/*  f0d8f88:	4600b406 */ 	mov.s	$f16,$f22
.PF0f0d8f8c:
/*  f0d8f8c:	0043082a */ 	slt	$at,$v0,$v1
/*  f0d8f90:	5420ff96 */ 	bnezl	$at,.PF0f0d8dec
/*  f0d8f94:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f0d8f98:	3c018007 */ 	lui	$at,0x8007
/*  f0d8f9c:	e4301270 */ 	swc1	$f16,0x1270($at)
/*  f0d8fa0:	3c018007 */ 	lui	$at,0x8007
/*  f0d8fa4:	e42e126c */ 	swc1	$f14,0x126c($at)
/*  f0d8fa8:	3c018007 */ 	lui	$at,0x8007
/*  f0d8fac:	e4381264 */ 	swc1	$f24,0x1264($at)
/*  f0d8fb0:	3c018007 */ 	lui	$at,0x8007
/*  f0d8fb4:	e43a1268 */ 	swc1	$f26,0x1268($at)
.PF0f0d8fb8:
/*  f0d8fb8:	3c018007 */ 	lui	$at,0x8007
/*  f0d8fbc:	c4381264 */ 	lwc1	$f24,0x1264($at)
/*  f0d8fc0:	3c018007 */ 	lui	$at,0x8007
/*  f0d8fc4:	c43a1268 */ 	lwc1	$f26,0x1268($at)
/*  f0d8fc8:	4600c10d */ 	trunc.w.s	$f4,$f24
/*  f0d8fcc:	3c0500ff */ 	lui	$a1,0xff
/*  f0d8fd0:	34a50028 */ 	ori	$a1,$a1,0x28
/*  f0d8fd4:	4600d18d */ 	trunc.w.s	$f6,$f26
/*  f0d8fd8:	44192000 */ 	mfc1	$t9,$f4
/*  f0d8fdc:	02002025 */ 	move	$a0,$s0
/*  f0d8fe0:	440f3000 */ 	mfc1	$t7,$f6
/*  f0d8fe4:	afb900cc */ 	sw	$t9,0xcc($sp)
/*  f0d8fe8:	0fc5513c */ 	jal	gfxSetPrimColour
/*  f0d8fec:	afaf00c8 */ 	sw	$t7,0xc8($sp)
/*  f0d8ff0:	3c038008 */ 	lui	$v1,0x8008
/*  f0d8ff4:	8fab00d4 */ 	lw	$t3,0xd4($sp)
/*  f0d8ff8:	24630020 */ 	addiu	$v1,$v1,0x20
/*  f0d8ffc:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d9000:	25650002 */ 	addiu	$a1,$t3,0x2
/*  f0d9004:	8faa00d8 */ 	lw	$t2,0xd8($sp)
/*  f0d9008:	00b90019 */ 	multu	$a1,$t9
/*  f0d900c:	3c06f600 */ 	lui	$a2,0xf600
/*  f0d9010:	314803ff */ 	andi	$t0,$t2,0x3ff
/*  f0d9014:	0008c080 */ 	sll	$t8,$t0,0x2
/*  f0d9018:	03004025 */ 	move	$t0,$t8
/*  f0d901c:	2567ffff */ 	addiu	$a3,$t3,-1
/*  f0d9020:	25490001 */ 	addiu	$t1,$t2,0x1
/*  f0d9024:	24440018 */ 	addiu	$a0,$v0,0x18
/*  f0d9028:	00007012 */ 	mflo	$t6
/*  f0d902c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d9030:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d9034:	0306c825 */ 	or	$t9,$t8,$a2
/*  f0d9038:	03287025 */ 	or	$t6,$t9,$t0
/*  f0d903c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0d9040:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0d9044:	00ef0019 */ 	multu	$a3,$t7
/*  f0d9048:	254fffff */ 	addiu	$t7,$t2,-1
/*  f0d904c:	0000c012 */ 	mflo	$t8
/*  f0d9050:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d9054:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0d9058:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0d905c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0d9060:	01d97825 */ 	or	$t7,$t6,$t9
/*  f0d9064:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0d9068:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d906c:	313803ff */ 	andi	$t8,$t1,0x3ff
/*  f0d9070:	00184880 */ 	sll	$t1,$t8,0x2
/*  f0d9074:	00b90019 */ 	multu	$a1,$t9
/*  f0d9078:	00007812 */ 	mflo	$t7
/*  f0d907c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0d9080:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0d9084:	01c6c825 */ 	or	$t9,$t6,$a2
/*  f0d9088:	03297825 */ 	or	$t7,$t9,$t1
/*  f0d908c:	ac4f0008 */ 	sw	$t7,0x8($v0)
/*  f0d9090:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0d9094:	00f80019 */ 	multu	$a3,$t8
/*  f0d9098:	00007012 */ 	mflo	$t6
/*  f0d909c:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0d90a0:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0d90a4:	01e8c025 */ 	or	$t8,$t7,$t0
/*  f0d90a8:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f0d90ac:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0d90b0:	00ae0019 */ 	multu	$a1,$t6
/*  f0d90b4:	0000c812 */ 	mflo	$t9
/*  f0d90b8:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0d90bc:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d90c0:	25590002 */ 	addiu	$t9,$t2,0x2
/*  f0d90c4:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0d90c8:	03067025 */ 	or	$t6,$t8,$a2
/*  f0d90cc:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0d90d0:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0d90d4:	ac590010 */ 	sw	$t9,0x10($v0)
/*  f0d90d8:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0d90dc:	00ef0019 */ 	multu	$a3,$t7
/*  f0d90e0:	00007012 */ 	mflo	$t6
/*  f0d90e4:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0d90e8:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d90ec:	03297825 */ 	or	$t7,$t9,$t1
/*  f0d90f0:	0fc55153 */ 	jal	func0f153838
/*  f0d90f4:	ac4f0014 */ 	sw	$t7,0x14($v0)
/*  f0d90f8:	00402025 */ 	move	$a0,$v0
/*  f0d90fc:	0fc5513c */ 	jal	gfxSetPrimColour
/*  f0d9100:	8fa500e4 */ 	lw	$a1,0xe4($sp)
/*  f0d9104:	8fb800dc */ 	lw	$t8,0xdc($sp)
/*  f0d9108:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*  f0d910c:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*  f0d9110:	3c038008 */ 	lui	$v1,0x8008
/*  f0d9114:	24630020 */ 	addiu	$v1,$v1,0x20
/*  f0d9118:	0338f821 */ 	addu	$ra,$t9,$t8
/*  f0d911c:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d9120:	01d82823 */ 	subu	$a1,$t6,$t8
/*  f0d9124:	24ac0001 */ 	addiu	$t4,$a1,0x1
/*  f0d9128:	01990019 */ 	multu	$t4,$t9
/*  f0d912c:	27e80001 */ 	addiu	$t0,$ra,0x1
/*  f0d9130:	310f03ff */ 	andi	$t7,$t0,0x3ff
/*  f0d9134:	000f4080 */ 	sll	$t0,$t7,0x2
/*  f0d9138:	3c06f600 */ 	lui	$a2,0xf600
/*  f0d913c:	244b0018 */ 	addiu	$t3,$v0,0x18
/*  f0d9140:	25700008 */ 	addiu	$s0,$t3,0x8
/*  f0d9144:	0000c012 */ 	mflo	$t8
/*  f0d9148:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0d914c:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0d9150:	01c6c825 */ 	or	$t9,$t6,$a2
/*  f0d9154:	0328c025 */ 	or	$t8,$t9,$t0
/*  f0d9158:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0d915c:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0d9160:	8faf00c8 */ 	lw	$t7,0xc8($sp)
/*  f0d9164:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f0d9168:	00b80019 */ 	multu	$a1,$t8
/*  f0d916c:	01ee3823 */ 	subu	$a3,$t7,$t6
/*  f0d9170:	30e403ff */ 	andi	$a0,$a3,0x3ff
/*  f0d9174:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f0d9178:	03202025 */ 	move	$a0,$t9
/*  f0d917c:	24ed0001 */ 	addiu	$t5,$a3,0x1
/*  f0d9180:	00007812 */ 	mflo	$t7
/*  f0d9184:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0d9188:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0d918c:	0324c025 */ 	or	$t8,$t9,$a0
/*  f0d9190:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0d9194:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*  f0d9198:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f0d919c:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d91a0:	01ee5021 */ 	addu	$t2,$t7,$t6
/*  f0d91a4:	25490001 */ 	addiu	$t1,$t2,0x1
/*  f0d91a8:	01390019 */ 	multu	$t1,$t9
/*  f0d91ac:	0000c012 */ 	mflo	$t8
/*  f0d91b0:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0d91b4:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0d91b8:	01c6c825 */ 	or	$t9,$t6,$a2
/*  f0d91bc:	0328c025 */ 	or	$t8,$t9,$t0
/*  f0d91c0:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f0d91c4:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0d91c8:	014f0019 */ 	multu	$t2,$t7
/*  f0d91cc:	00007012 */ 	mflo	$t6
/*  f0d91d0:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0d91d4:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f0d91d8:	03047825 */ 	or	$t7,$t8,$a0
/*  f0d91dc:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f0d91e0:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0d91e4:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f0d91e8:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f0d91ec:	01380019 */ 	multu	$t1,$t8
/*  f0d91f0:	00007812 */ 	mflo	$t7
/*  f0d91f4:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0d91f8:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0d91fc:	0326c025 */ 	or	$t8,$t9,$a2
/*  f0d9200:	030d7825 */ 	or	$t7,$t8,$t5
/*  f0d9204:	ac4f0010 */ 	sw	$t7,0x10($v0)
/*  f0d9208:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0d920c:	afbf006c */ 	sw	$ra,0x6c($sp)
/*  f0d9210:	00ae0019 */ 	multu	$a1,$t6
/*  f0d9214:	0000c812 */ 	mflo	$t9
/*  f0d9218:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0d921c:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f0d9220:	01e47025 */ 	or	$t6,$t7,$a0
/*  f0d9224:	ac4e0014 */ 	sw	$t6,0x14($v0)
/*  f0d9228:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d922c:	01390019 */ 	multu	$t1,$t9
/*  f0d9230:	0000c012 */ 	mflo	$t8
/*  f0d9234:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0d9238:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0d923c:	01c6c825 */ 	or	$t9,$t6,$a2
/*  f0d9240:	0328c025 */ 	or	$t8,$t9,$t0
/*  f0d9244:	ad780000 */ 	sw	$t8,0x0($t3)
/*  f0d9248:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d924c:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f0d9250:	00b90019 */ 	multu	$a1,$t9
/*  f0d9254:	33ef03ff */ 	andi	$t7,$ra,0x3ff
/*  f0d9258:	000ff880 */ 	sll	$ra,$t7,0x2
/*  f0d925c:	0000c012 */ 	mflo	$t8
/*  f0d9260:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0d9264:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0d9268:	01dfc825 */ 	or	$t9,$t6,$ra
/*  f0d926c:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f0d9270:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f0d9274:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*  f0d9278:	afb00098 */ 	sw	$s0,0x98($sp)
/*  f0d927c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0d9280:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f0d9284:	25d90001 */ 	addiu	$t9,$t6,0x1
/*  f0d9288:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0d928c:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0d9290:	00187880 */ 	sll	$t7,$t8,0x2
/*  f0d9294:	018e0019 */ 	multu	$t4,$t6
/*  f0d9298:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f0d929c:	02001025 */ 	move	$v0,$s0
/*  f0d92a0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0d92a4:	02005825 */ 	move	$t3,$s0
/*  f0d92a8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0d92ac:	0000c812 */ 	mflo	$t9
/*  f0d92b0:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0d92b4:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0d92b8:	01c6c825 */ 	or	$t9,$t6,$a2
/*  f0d92bc:	8fae0098 */ 	lw	$t6,0x98($sp)
/*  f0d92c0:	032fc025 */ 	or	$t8,$t9,$t7
/*  f0d92c4:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0d92c8:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d92cc:	00b90019 */ 	multu	$a1,$t9
/*  f0d92d0:	00007812 */ 	mflo	$t7
/*  f0d92d4:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0d92d8:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d92dc:	03247825 */ 	or	$t7,$t9,$a0
/*  f0d92e0:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f0d92e4:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0d92e8:	01980019 */ 	multu	$t4,$t8
/*  f0d92ec:	0000c812 */ 	mflo	$t9
/*  f0d92f0:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0d92f4:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0d92f8:	01c6c025 */ 	or	$t8,$t6,$a2
/*  f0d92fc:	0308c825 */ 	or	$t9,$t8,$t0
/*  f0d9300:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0d9304:	8fae00e0 */ 	lw	$t6,0xe0($sp)
/*  f0d9308:	8faf00c8 */ 	lw	$t7,0xc8($sp)
/*  f0d930c:	01ee3821 */ 	addu	$a3,$t7,$t6
/*  f0d9310:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0d9314:	30f803ff */ 	andi	$t8,$a3,0x3ff
/*  f0d9318:	00183880 */ 	sll	$a3,$t8,0x2
/*  f0d931c:	00af0019 */ 	multu	$a1,$t7
/*  f0d9320:	00007012 */ 	mflo	$t6
/*  f0d9324:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0d9328:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d932c:	03277825 */ 	or	$t7,$t9,$a3
/*  f0d9330:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0d9334:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0d9338:	02001025 */ 	move	$v0,$s0
/*  f0d933c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0d9340:	012e0019 */ 	multu	$t1,$t6
/*  f0d9344:	02006025 */ 	move	$t4,$s0
/*  f0d9348:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0d934c:	0000c012 */ 	mflo	$t8
/*  f0d9350:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d9354:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f0d9358:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0d935c:	01e67025 */ 	or	$t6,$t7,$a2
/*  f0d9360:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0d9364:	ad790000 */ 	sw	$t9,0x0($t3)
/*  f0d9368:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0d936c:	014f0019 */ 	multu	$t2,$t7
/*  f0d9370:	00007012 */ 	mflo	$t6
/*  f0d9374:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0d9378:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d937c:	03247825 */ 	or	$t7,$t9,$a0
/*  f0d9380:	ad6f0004 */ 	sw	$t7,0x4($t3)
/*  f0d9384:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0d9388:	012e0019 */ 	multu	$t1,$t6
/*  f0d938c:	0000c012 */ 	mflo	$t8
/*  f0d9390:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d9394:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0d9398:	01e67025 */ 	or	$t6,$t7,$a2
/*  f0d939c:	01c8c025 */ 	or	$t8,$t6,$t0
/*  f0d93a0:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0d93a4:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d93a8:	01590019 */ 	multu	$t2,$t9
/*  f0d93ac:	00007812 */ 	mflo	$t7
/*  f0d93b0:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0d93b4:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f0d93b8:	0307c825 */ 	or	$t9,$t8,$a3
/*  f0d93bc:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0d93c0:	8fae00e0 */ 	lw	$t6,0xe0($sp)
/*  f0d93c4:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*  f0d93c8:	02001025 */ 	move	$v0,$s0
/*  f0d93cc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0d93d0:	01eec023 */ 	subu	$t8,$t7,$t6
/*  f0d93d4:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0d93d8:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0d93dc:	afb90070 */ 	sw	$t9,0x70($sp)
/*  f0d93e0:	032f0019 */ 	multu	$t9,$t7
/*  f0d93e4:	02005025 */ 	move	$t2,$s0
/*  f0d93e8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0d93ec:	00007012 */ 	mflo	$t6
/*  f0d93f0:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0d93f4:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d93f8:	03267825 */ 	or	$t7,$t9,$a2
/*  f0d93fc:	01ed7025 */ 	or	$t6,$t7,$t5
/*  f0d9400:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f0d9404:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0d9408:	00b80019 */ 	multu	$a1,$t8
/*  f0d940c:	0000c812 */ 	mflo	$t9
/*  f0d9410:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0d9414:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0d9418:	01c4c025 */ 	or	$t8,$t6,$a0
/*  f0d941c:	ad980004 */ 	sw	$t8,0x4($t4)
/*  f0d9420:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d9424:	01390019 */ 	multu	$t1,$t9
/*  f0d9428:	00007812 */ 	mflo	$t7
/*  f0d942c:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0d9430:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f0d9434:	0306c825 */ 	or	$t9,$t8,$a2
/*  f0d9438:	032d7825 */ 	or	$t7,$t9,$t5
/*  f0d943c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0d9440:	8fb800e0 */ 	lw	$t8,0xe0($sp)
/*  f0d9444:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*  f0d9448:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d944c:	01d83821 */ 	addu	$a3,$t6,$t8
/*  f0d9450:	00f90019 */ 	multu	$a3,$t9
/*  f0d9454:	00007812 */ 	mflo	$t7
/*  f0d9458:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0d945c:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f0d9460:	0304c825 */ 	or	$t9,$t8,$a0
/*  f0d9464:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0d9468:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0d946c:	8faf0070 */ 	lw	$t7,0x70($sp)
/*  f0d9470:	01ee0019 */ 	multu	$t7,$t6
/*  f0d9474:	0000c012 */ 	mflo	$t8
/*  f0d9478:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d947c:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0d9480:	01e67025 */ 	or	$t6,$t7,$a2
/*  f0d9484:	01c8c025 */ 	or	$t8,$t6,$t0
/*  f0d9488:	ad580000 */ 	sw	$t8,0x0($t2)
/*  f0d948c:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d9490:	00b90019 */ 	multu	$a1,$t9
/*  f0d9494:	00007812 */ 	mflo	$t7
/*  f0d9498:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0d949c:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f0d94a0:	031fc825 */ 	or	$t9,$t8,$ra
/*  f0d94a4:	ad590004 */ 	sw	$t9,0x4($t2)
/*  f0d94a8:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0d94ac:	02001025 */ 	move	$v0,$s0
/*  f0d94b0:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f0d94b4:	012f0019 */ 	multu	$t1,$t7
/*  f0d94b8:	00007012 */ 	mflo	$t6
/*  f0d94bc:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0d94c0:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d94c4:	03267825 */ 	or	$t7,$t9,$a2
/*  f0d94c8:	01e87025 */ 	or	$t6,$t7,$t0
/*  f0d94cc:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0d94d0:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0d94d4:	00f80019 */ 	multu	$a3,$t8
/*  f0d94d8:	0000c812 */ 	mflo	$t9
/*  f0d94dc:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0d94e0:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0d94e4:	01dfc025 */ 	or	$t8,$t6,$ra
/*  f0d94e8:	0fc55153 */ 	jal	func0f153838
/*  f0d94ec:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0d94f0:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0d94f4:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0d94f8:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f0d94fc:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f0d9500:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f0d9504:	d7bc0038 */ 	ldc1	$f28,0x38($sp)
/*  f0d9508:	d7be0040 */ 	ldc1	$f30,0x40($sp)
/*  f0d950c:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f0d9510:	03e00008 */ 	jr	$ra
/*  f0d9514:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);
#else
GLOBAL_ASM(
glabel func0f0d87a8
.late_rodata
glabel var7f1adde0
.word 0x3d4ccccd
glabel var7f1adde4
.word 0xbd4ccccd
glabel var7f1adde8
.word 0xbd4ccccd
.text
/*  f0d87a8:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f0d87ac:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x38)
/*  f0d87b0:	8c639ff8 */ 	lw	$v1,%lo(g_Vars+0x38)($v1)
/*  f0d87b4:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f0d87b8:	00808025 */ 	or	$s0,$a0,$zero
/*  f0d87bc:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f0d87c0:	f7be0040 */ 	sdc1	$f30,0x40($sp)
/*  f0d87c4:	f7bc0038 */ 	sdc1	$f28,0x38($sp)
/*  f0d87c8:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f0d87cc:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f0d87d0:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f0d87d4:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0d87d8:	afa500d4 */ 	sw	$a1,0xd4($sp)
/*  f0d87dc:	afa600d8 */ 	sw	$a2,0xd8($sp)
/*  f0d87e0:	afa700dc */ 	sw	$a3,0xdc($sp)
/*  f0d87e4:	1860008c */ 	blez	$v1,.L0f0d8a18
/*  f0d87e8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0d87ec:	3c013f00 */ 	lui	$at,0x3f00
/*  f0d87f0:	4481f000 */ 	mtc1	$at,$f30
/*  f0d87f4:	3c018007 */ 	lui	$at,%hi(var80070f88)
/*  f0d87f8:	c43c0f88 */ 	lwc1	$f28,%lo(var80070f88)($at)
/*  f0d87fc:	3c018007 */ 	lui	$at,%hi(var80070f84)
/*  f0d8800:	c43a0f84 */ 	lwc1	$f26,%lo(var80070f84)($at)
/*  f0d8804:	44852000 */ 	mtc1	$a1,$f4
/*  f0d8808:	44864000 */ 	mtc1	$a2,$f8
/*  f0d880c:	3c017f1b */ 	lui	$at,%hi(var7f1adde0)
/*  f0d8810:	c436dde0 */ 	lwc1	$f22,%lo(var7f1adde0)($at)
/*  f0d8814:	3c01c000 */ 	lui	$at,0xc000
/*  f0d8818:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d881c:	4481a000 */ 	mtc1	$at,$f20
/*  f0d8820:	3c014000 */ 	lui	$at,0x4000
/*  f0d8824:	44819000 */ 	mtc1	$at,$f18
/*  f0d8828:	3c018007 */ 	lui	$at,%hi(var80070f90)
/*  f0d882c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d8830:	c4300f90 */ 	lwc1	$f16,%lo(var80070f90)($at)
/*  f0d8834:	3c018007 */ 	lui	$at,%hi(var80070f8c)
/*  f0d8838:	4480c000 */ 	mtc1	$zero,$f24
/*  f0d883c:	c42e0f8c */ 	lwc1	$f14,%lo(var80070f8c)($at)
/*  f0d8840:	e7a60074 */ 	swc1	$f6,0x74($sp)
/*  f0d8844:	e7aa006c */ 	swc1	$f10,0x6c($sp)
/*  f0d8848:	c7a40074 */ 	lwc1	$f4,0x74($sp)
.L0f0d884c:
/*  f0d884c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0d8850:	3c01bf00 */ 	lui	$at,0xbf00
/*  f0d8854:	461a2301 */ 	sub.s	$f12,$f4,$f26
/*  f0d8858:	c7a8006c */ 	lwc1	$f8,0x6c($sp)
/*  f0d885c:	460cf03c */ 	c.lt.s	$f30,$f12
/*  f0d8860:	00000000 */ 	nop
/*  f0d8864:	45010007 */ 	bc1t	.L0f0d8884
/*  f0d8868:	00000000 */ 	nop
/*  f0d886c:	44813000 */ 	mtc1	$at,$f6
/*  f0d8870:	00000000 */ 	nop
/*  f0d8874:	4606603c */ 	c.lt.s	$f12,$f6
/*  f0d8878:	00000000 */ 	nop
/*  f0d887c:	45020027 */ 	bc1fl	.L0f0d891c
/*  f0d8880:	c7ba0074 */ 	lwc1	$f26,0x74($sp)
.L0f0d8884:
/*  f0d8884:	46166002 */ 	mul.s	$f0,$f12,$f22
/*  f0d8888:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0d888c:	00000000 */ 	nop
/*  f0d8890:	45020003 */ 	bc1fl	.L0f0d88a0
/*  f0d8894:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0d8898:	46009006 */ 	mov.s	$f0,$f18
/*  f0d889c:	4614003c */ 	c.lt.s	$f0,$f20
.L0f0d88a0:
/*  f0d88a0:	00000000 */ 	nop
/*  f0d88a4:	45020003 */ 	bc1fl	.L0f0d88b4
/*  f0d88a8:	4600703c */ 	c.lt.s	$f14,$f0
/*  f0d88ac:	4600a006 */ 	mov.s	$f0,$f20
/*  f0d88b0:	4600703c */ 	c.lt.s	$f14,$f0
.L0f0d88b4:
/*  f0d88b4:	00000000 */ 	nop
/*  f0d88b8:	45020004 */ 	bc1fl	.L0f0d88cc
/*  f0d88bc:	460e003c */ 	c.lt.s	$f0,$f14
/*  f0d88c0:	10000008 */ 	b	.L0f0d88e4
/*  f0d88c4:	4600b006 */ 	mov.s	$f0,$f22
/*  f0d88c8:	460e003c */ 	c.lt.s	$f0,$f14
.L0f0d88cc:
/*  f0d88cc:	3c017f1b */ 	lui	$at,%hi(var7f1adde4)
/*  f0d88d0:	45020004 */ 	bc1fl	.L0f0d88e4
/*  f0d88d4:	4600c006 */ 	mov.s	$f0,$f24
/*  f0d88d8:	10000002 */ 	b	.L0f0d88e4
/*  f0d88dc:	c420dde4 */ 	lwc1	$f0,%lo(var7f1adde4)($at)
/*  f0d88e0:	4600c006 */ 	mov.s	$f0,$f24
.L0f0d88e4:
/*  f0d88e4:	46007380 */ 	add.s	$f14,$f14,$f0
/*  f0d88e8:	460e903c */ 	c.lt.s	$f18,$f14
/*  f0d88ec:	00000000 */ 	nop
/*  f0d88f0:	45020003 */ 	bc1fl	.L0f0d8900
/*  f0d88f4:	4614703c */ 	c.lt.s	$f14,$f20
/*  f0d88f8:	46009386 */ 	mov.s	$f14,$f18
/*  f0d88fc:	4614703c */ 	c.lt.s	$f14,$f20
.L0f0d8900:
/*  f0d8900:	00000000 */ 	nop
/*  f0d8904:	45000002 */ 	bc1f	.L0f0d8910
/*  f0d8908:	00000000 */ 	nop
/*  f0d890c:	4600a386 */ 	mov.s	$f14,$f20
.L0f0d8910:
/*  f0d8910:	10000003 */ 	b	.L0f0d8920
/*  f0d8914:	460ed680 */ 	add.s	$f26,$f26,$f14
/*  f0d8918:	c7ba0074 */ 	lwc1	$f26,0x74($sp)
.L0f0d891c:
/*  f0d891c:	4600c386 */ 	mov.s	$f14,$f24
.L0f0d8920:
/*  f0d8920:	461c4301 */ 	sub.s	$f12,$f8,$f28
/*  f0d8924:	3c01bf00 */ 	lui	$at,0xbf00
/*  f0d8928:	460cf03c */ 	c.lt.s	$f30,$f12
/*  f0d892c:	00000000 */ 	nop
/*  f0d8930:	45010007 */ 	bc1t	.L0f0d8950
/*  f0d8934:	00000000 */ 	nop
/*  f0d8938:	44815000 */ 	mtc1	$at,$f10
/*  f0d893c:	00000000 */ 	nop
/*  f0d8940:	460a603c */ 	c.lt.s	$f12,$f10
/*  f0d8944:	00000000 */ 	nop
/*  f0d8948:	45020027 */ 	bc1fl	.L0f0d89e8
/*  f0d894c:	c7bc006c */ 	lwc1	$f28,0x6c($sp)
.L0f0d8950:
/*  f0d8950:	46166002 */ 	mul.s	$f0,$f12,$f22
/*  f0d8954:	4600903c */ 	c.lt.s	$f18,$f0
/*  f0d8958:	00000000 */ 	nop
/*  f0d895c:	45020003 */ 	bc1fl	.L0f0d896c
/*  f0d8960:	4614003c */ 	c.lt.s	$f0,$f20
/*  f0d8964:	46009006 */ 	mov.s	$f0,$f18
/*  f0d8968:	4614003c */ 	c.lt.s	$f0,$f20
.L0f0d896c:
/*  f0d896c:	00000000 */ 	nop
/*  f0d8970:	45020003 */ 	bc1fl	.L0f0d8980
/*  f0d8974:	4600803c */ 	c.lt.s	$f16,$f0
/*  f0d8978:	4600a006 */ 	mov.s	$f0,$f20
/*  f0d897c:	4600803c */ 	c.lt.s	$f16,$f0
.L0f0d8980:
/*  f0d8980:	00000000 */ 	nop
/*  f0d8984:	45020004 */ 	bc1fl	.L0f0d8998
/*  f0d8988:	4610003c */ 	c.lt.s	$f0,$f16
/*  f0d898c:	10000008 */ 	b	.L0f0d89b0
/*  f0d8990:	4600b006 */ 	mov.s	$f0,$f22
/*  f0d8994:	4610003c */ 	c.lt.s	$f0,$f16
.L0f0d8998:
/*  f0d8998:	3c017f1b */ 	lui	$at,%hi(var7f1adde8)
/*  f0d899c:	45020004 */ 	bc1fl	.L0f0d89b0
/*  f0d89a0:	4600c006 */ 	mov.s	$f0,$f24
/*  f0d89a4:	10000002 */ 	b	.L0f0d89b0
/*  f0d89a8:	c420dde8 */ 	lwc1	$f0,%lo(var7f1adde8)($at)
/*  f0d89ac:	4600c006 */ 	mov.s	$f0,$f24
.L0f0d89b0:
/*  f0d89b0:	46008400 */ 	add.s	$f16,$f16,$f0
/*  f0d89b4:	4610903c */ 	c.lt.s	$f18,$f16
/*  f0d89b8:	00000000 */ 	nop
/*  f0d89bc:	45020003 */ 	bc1fl	.L0f0d89cc
/*  f0d89c0:	4614803c */ 	c.lt.s	$f16,$f20
/*  f0d89c4:	46009406 */ 	mov.s	$f16,$f18
/*  f0d89c8:	4614803c */ 	c.lt.s	$f16,$f20
.L0f0d89cc:
/*  f0d89cc:	00000000 */ 	nop
/*  f0d89d0:	45000002 */ 	bc1f	.L0f0d89dc
/*  f0d89d4:	00000000 */ 	nop
/*  f0d89d8:	4600a406 */ 	mov.s	$f16,$f20
.L0f0d89dc:
/*  f0d89dc:	10000003 */ 	b	.L0f0d89ec
/*  f0d89e0:	4610e700 */ 	add.s	$f28,$f28,$f16
/*  f0d89e4:	c7bc006c */ 	lwc1	$f28,0x6c($sp)
.L0f0d89e8:
/*  f0d89e8:	4600c406 */ 	mov.s	$f16,$f24
.L0f0d89ec:
/*  f0d89ec:	0043082a */ 	slt	$at,$v0,$v1
/*  f0d89f0:	5420ff96 */ 	bnezl	$at,.L0f0d884c
/*  f0d89f4:	c7a40074 */ 	lwc1	$f4,0x74($sp)
/*  f0d89f8:	3c018007 */ 	lui	$at,%hi(var80070f90)
/*  f0d89fc:	e4300f90 */ 	swc1	$f16,%lo(var80070f90)($at)
/*  f0d8a00:	3c018007 */ 	lui	$at,%hi(var80070f8c)
/*  f0d8a04:	e42e0f8c */ 	swc1	$f14,%lo(var80070f8c)($at)
/*  f0d8a08:	3c018007 */ 	lui	$at,%hi(var80070f84)
/*  f0d8a0c:	e43a0f84 */ 	swc1	$f26,%lo(var80070f84)($at)
/*  f0d8a10:	3c018007 */ 	lui	$at,%hi(var80070f88)
/*  f0d8a14:	e43c0f88 */ 	swc1	$f28,%lo(var80070f88)($at)
.L0f0d8a18:
/*  f0d8a18:	3c018007 */ 	lui	$at,%hi(var80070f84)
/*  f0d8a1c:	c43a0f84 */ 	lwc1	$f26,%lo(var80070f84)($at)
/*  f0d8a20:	3c018007 */ 	lui	$at,%hi(var80070f88)
/*  f0d8a24:	c43c0f88 */ 	lwc1	$f28,%lo(var80070f88)($at)
/*  f0d8a28:	4600d10d */ 	trunc.w.s	$f4,$f26
/*  f0d8a2c:	3c0500ff */ 	lui	$a1,0xff
/*  f0d8a30:	34a50028 */ 	ori	$a1,$a1,0x28
/*  f0d8a34:	4600e18d */ 	trunc.w.s	$f6,$f28
/*  f0d8a38:	44192000 */ 	mfc1	$t9,$f4
/*  f0d8a3c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0d8a40:	440f3000 */ 	mfc1	$t7,$f6
/*  f0d8a44:	afb900cc */ 	sw	$t9,0xcc($sp)
/*  f0d8a48:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0d8a4c:	afaf00c8 */ 	sw	$t7,0xc8($sp)
/*  f0d8a50:	3c038008 */ 	lui	$v1,%hi(g_ScaleX)
/*  f0d8a54:	8fab00d4 */ 	lw	$t3,0xd4($sp)
/*  f0d8a58:	2463fac0 */ 	addiu	$v1,$v1,%lo(g_ScaleX)
/*  f0d8a5c:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d8a60:	25650002 */ 	addiu	$a1,$t3,0x2
/*  f0d8a64:	8faa00d8 */ 	lw	$t2,0xd8($sp)
/*  f0d8a68:	00b90019 */ 	multu	$a1,$t9
/*  f0d8a6c:	3c06f600 */ 	lui	$a2,0xf600
/*  f0d8a70:	314803ff */ 	andi	$t0,$t2,0x3ff
/*  f0d8a74:	0008c080 */ 	sll	$t8,$t0,0x2
/*  f0d8a78:	03004025 */ 	or	$t0,$t8,$zero
/*  f0d8a7c:	2567ffff */ 	addiu	$a3,$t3,-1
/*  f0d8a80:	25490001 */ 	addiu	$t1,$t2,0x1
/*  f0d8a84:	24440018 */ 	addiu	$a0,$v0,0x18
/*  f0d8a88:	00007012 */ 	mflo	$t6
/*  f0d8a8c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0d8a90:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d8a94:	0306c825 */ 	or	$t9,$t8,$a2
/*  f0d8a98:	03287025 */ 	or	$t6,$t9,$t0
/*  f0d8a9c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0d8aa0:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0d8aa4:	00ef0019 */ 	multu	$a3,$t7
/*  f0d8aa8:	254fffff */ 	addiu	$t7,$t2,-1
/*  f0d8aac:	0000c012 */ 	mflo	$t8
/*  f0d8ab0:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d8ab4:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0d8ab8:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0d8abc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0d8ac0:	01d97825 */ 	or	$t7,$t6,$t9
/*  f0d8ac4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0d8ac8:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d8acc:	313803ff */ 	andi	$t8,$t1,0x3ff
/*  f0d8ad0:	00184880 */ 	sll	$t1,$t8,0x2
/*  f0d8ad4:	00b90019 */ 	multu	$a1,$t9
/*  f0d8ad8:	00007812 */ 	mflo	$t7
/*  f0d8adc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0d8ae0:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0d8ae4:	01c6c825 */ 	or	$t9,$t6,$a2
/*  f0d8ae8:	03297825 */ 	or	$t7,$t9,$t1
/*  f0d8aec:	ac4f0008 */ 	sw	$t7,0x8($v0)
/*  f0d8af0:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0d8af4:	00f80019 */ 	multu	$a3,$t8
/*  f0d8af8:	00007012 */ 	mflo	$t6
/*  f0d8afc:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0d8b00:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0d8b04:	01e8c025 */ 	or	$t8,$t7,$t0
/*  f0d8b08:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f0d8b0c:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0d8b10:	00ae0019 */ 	multu	$a1,$t6
/*  f0d8b14:	0000c812 */ 	mflo	$t9
/*  f0d8b18:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0d8b1c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d8b20:	25590002 */ 	addiu	$t9,$t2,0x2
/*  f0d8b24:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0d8b28:	03067025 */ 	or	$t6,$t8,$a2
/*  f0d8b2c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f0d8b30:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0d8b34:	ac590010 */ 	sw	$t9,0x10($v0)
/*  f0d8b38:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0d8b3c:	00ef0019 */ 	multu	$a3,$t7
/*  f0d8b40:	00007012 */ 	mflo	$t6
/*  f0d8b44:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0d8b48:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d8b4c:	03297825 */ 	or	$t7,$t9,$t1
/*  f0d8b50:	0fc54e0e */ 	jal	func0f153838
/*  f0d8b54:	ac4f0014 */ 	sw	$t7,0x14($v0)
/*  f0d8b58:	00402025 */ 	or	$a0,$v0,$zero
/*  f0d8b5c:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0d8b60:	8fa500e4 */ 	lw	$a1,0xe4($sp)
/*  f0d8b64:	8fb800dc */ 	lw	$t8,0xdc($sp)
/*  f0d8b68:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*  f0d8b6c:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*  f0d8b70:	3c038008 */ 	lui	$v1,%hi(g_ScaleX)
/*  f0d8b74:	2463fac0 */ 	addiu	$v1,$v1,%lo(g_ScaleX)
/*  f0d8b78:	0338f821 */ 	addu	$ra,$t9,$t8
/*  f0d8b7c:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d8b80:	01d82823 */ 	subu	$a1,$t6,$t8
/*  f0d8b84:	24ac0001 */ 	addiu	$t4,$a1,0x1
/*  f0d8b88:	01990019 */ 	multu	$t4,$t9
/*  f0d8b8c:	27e80001 */ 	addiu	$t0,$ra,0x1
/*  f0d8b90:	310f03ff */ 	andi	$t7,$t0,0x3ff
/*  f0d8b94:	000f4080 */ 	sll	$t0,$t7,0x2
/*  f0d8b98:	3c06f600 */ 	lui	$a2,0xf600
/*  f0d8b9c:	244b0018 */ 	addiu	$t3,$v0,0x18
/*  f0d8ba0:	25700008 */ 	addiu	$s0,$t3,0x8
/*  f0d8ba4:	0000c012 */ 	mflo	$t8
/*  f0d8ba8:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0d8bac:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0d8bb0:	01c6c825 */ 	or	$t9,$t6,$a2
/*  f0d8bb4:	0328c025 */ 	or	$t8,$t9,$t0
/*  f0d8bb8:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0d8bbc:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0d8bc0:	8faf00c8 */ 	lw	$t7,0xc8($sp)
/*  f0d8bc4:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f0d8bc8:	00b80019 */ 	multu	$a1,$t8
/*  f0d8bcc:	01ee3823 */ 	subu	$a3,$t7,$t6
/*  f0d8bd0:	30e403ff */ 	andi	$a0,$a3,0x3ff
/*  f0d8bd4:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f0d8bd8:	03202025 */ 	or	$a0,$t9,$zero
/*  f0d8bdc:	24ed0001 */ 	addiu	$t5,$a3,0x1
/*  f0d8be0:	00007812 */ 	mflo	$t7
/*  f0d8be4:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0d8be8:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0d8bec:	0324c025 */ 	or	$t8,$t9,$a0
/*  f0d8bf0:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0d8bf4:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*  f0d8bf8:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f0d8bfc:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d8c00:	01ee5021 */ 	addu	$t2,$t7,$t6
/*  f0d8c04:	25490001 */ 	addiu	$t1,$t2,0x1
/*  f0d8c08:	01390019 */ 	multu	$t1,$t9
/*  f0d8c0c:	0000c012 */ 	mflo	$t8
/*  f0d8c10:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0d8c14:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0d8c18:	01c6c825 */ 	or	$t9,$t6,$a2
/*  f0d8c1c:	0328c025 */ 	or	$t8,$t9,$t0
/*  f0d8c20:	ac580008 */ 	sw	$t8,0x8($v0)
/*  f0d8c24:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0d8c28:	014f0019 */ 	multu	$t2,$t7
/*  f0d8c2c:	00007012 */ 	mflo	$t6
/*  f0d8c30:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0d8c34:	0019c380 */ 	sll	$t8,$t9,0xe
/*  f0d8c38:	03047825 */ 	or	$t7,$t8,$a0
/*  f0d8c3c:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f0d8c40:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0d8c44:	31ae03ff */ 	andi	$t6,$t5,0x3ff
/*  f0d8c48:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f0d8c4c:	01380019 */ 	multu	$t1,$t8
/*  f0d8c50:	00007812 */ 	mflo	$t7
/*  f0d8c54:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0d8c58:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0d8c5c:	0326c025 */ 	or	$t8,$t9,$a2
/*  f0d8c60:	030d7825 */ 	or	$t7,$t8,$t5
/*  f0d8c64:	ac4f0010 */ 	sw	$t7,0x10($v0)
/*  f0d8c68:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0d8c6c:	afbf006c */ 	sw	$ra,0x6c($sp)
/*  f0d8c70:	00ae0019 */ 	multu	$a1,$t6
/*  f0d8c74:	0000c812 */ 	mflo	$t9
/*  f0d8c78:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0d8c7c:	00187b80 */ 	sll	$t7,$t8,0xe
/*  f0d8c80:	01e47025 */ 	or	$t6,$t7,$a0
/*  f0d8c84:	ac4e0014 */ 	sw	$t6,0x14($v0)
/*  f0d8c88:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d8c8c:	01390019 */ 	multu	$t1,$t9
/*  f0d8c90:	0000c012 */ 	mflo	$t8
/*  f0d8c94:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0d8c98:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0d8c9c:	01c6c825 */ 	or	$t9,$t6,$a2
/*  f0d8ca0:	0328c025 */ 	or	$t8,$t9,$t0
/*  f0d8ca4:	ad780000 */ 	sw	$t8,0x0($t3)
/*  f0d8ca8:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d8cac:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f0d8cb0:	00b90019 */ 	multu	$a1,$t9
/*  f0d8cb4:	33ef03ff */ 	andi	$t7,$ra,0x3ff
/*  f0d8cb8:	000ff880 */ 	sll	$ra,$t7,0x2
/*  f0d8cbc:	0000c012 */ 	mflo	$t8
/*  f0d8cc0:	330f03ff */ 	andi	$t7,$t8,0x3ff
/*  f0d8cc4:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0d8cc8:	01dfc825 */ 	or	$t9,$t6,$ra
/*  f0d8ccc:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f0d8cd0:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f0d8cd4:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*  f0d8cd8:	afb00098 */ 	sw	$s0,0x98($sp)
/*  f0d8cdc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0d8ce0:	030f7023 */ 	subu	$t6,$t8,$t7
/*  f0d8ce4:	25d90001 */ 	addiu	$t9,$t6,0x1
/*  f0d8ce8:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0d8cec:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0d8cf0:	00187880 */ 	sll	$t7,$t8,0x2
/*  f0d8cf4:	018e0019 */ 	multu	$t4,$t6
/*  f0d8cf8:	afaf0050 */ 	sw	$t7,0x50($sp)
/*  f0d8cfc:	02001025 */ 	or	$v0,$s0,$zero
/*  f0d8d00:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0d8d04:	02005825 */ 	or	$t3,$s0,$zero
/*  f0d8d08:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0d8d0c:	0000c812 */ 	mflo	$t9
/*  f0d8d10:	333803ff */ 	andi	$t8,$t9,0x3ff
/*  f0d8d14:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0d8d18:	01c6c825 */ 	or	$t9,$t6,$a2
/*  f0d8d1c:	8fae0098 */ 	lw	$t6,0x98($sp)
/*  f0d8d20:	032fc025 */ 	or	$t8,$t9,$t7
/*  f0d8d24:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0d8d28:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d8d2c:	00b90019 */ 	multu	$a1,$t9
/*  f0d8d30:	00007812 */ 	mflo	$t7
/*  f0d8d34:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0d8d38:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d8d3c:	03247825 */ 	or	$t7,$t9,$a0
/*  f0d8d40:	adcf0004 */ 	sw	$t7,0x4($t6)
/*  f0d8d44:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0d8d48:	01980019 */ 	multu	$t4,$t8
/*  f0d8d4c:	0000c812 */ 	mflo	$t9
/*  f0d8d50:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0d8d54:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0d8d58:	01c6c025 */ 	or	$t8,$t6,$a2
/*  f0d8d5c:	0308c825 */ 	or	$t9,$t8,$t0
/*  f0d8d60:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0d8d64:	8fae00e0 */ 	lw	$t6,0xe0($sp)
/*  f0d8d68:	8faf00c8 */ 	lw	$t7,0xc8($sp)
/*  f0d8d6c:	01ee3821 */ 	addu	$a3,$t7,$t6
/*  f0d8d70:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0d8d74:	30f803ff */ 	andi	$t8,$a3,0x3ff
/*  f0d8d78:	00183880 */ 	sll	$a3,$t8,0x2
/*  f0d8d7c:	00af0019 */ 	multu	$a1,$t7
/*  f0d8d80:	00007012 */ 	mflo	$t6
/*  f0d8d84:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0d8d88:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d8d8c:	03277825 */ 	or	$t7,$t9,$a3
/*  f0d8d90:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0d8d94:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0d8d98:	02001025 */ 	or	$v0,$s0,$zero
/*  f0d8d9c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0d8da0:	012e0019 */ 	multu	$t1,$t6
/*  f0d8da4:	02006025 */ 	or	$t4,$s0,$zero
/*  f0d8da8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0d8dac:	0000c012 */ 	mflo	$t8
/*  f0d8db0:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d8db4:	8fb80050 */ 	lw	$t8,0x50($sp)
/*  f0d8db8:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0d8dbc:	01e67025 */ 	or	$t6,$t7,$a2
/*  f0d8dc0:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f0d8dc4:	ad790000 */ 	sw	$t9,0x0($t3)
/*  f0d8dc8:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0d8dcc:	014f0019 */ 	multu	$t2,$t7
/*  f0d8dd0:	00007012 */ 	mflo	$t6
/*  f0d8dd4:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0d8dd8:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d8ddc:	03247825 */ 	or	$t7,$t9,$a0
/*  f0d8de0:	ad6f0004 */ 	sw	$t7,0x4($t3)
/*  f0d8de4:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0d8de8:	012e0019 */ 	multu	$t1,$t6
/*  f0d8dec:	0000c012 */ 	mflo	$t8
/*  f0d8df0:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d8df4:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0d8df8:	01e67025 */ 	or	$t6,$t7,$a2
/*  f0d8dfc:	01c8c025 */ 	or	$t8,$t6,$t0
/*  f0d8e00:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0d8e04:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d8e08:	01590019 */ 	multu	$t2,$t9
/*  f0d8e0c:	00007812 */ 	mflo	$t7
/*  f0d8e10:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0d8e14:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f0d8e18:	0307c825 */ 	or	$t9,$t8,$a3
/*  f0d8e1c:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0d8e20:	8fae00e0 */ 	lw	$t6,0xe0($sp)
/*  f0d8e24:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*  f0d8e28:	02001025 */ 	or	$v0,$s0,$zero
/*  f0d8e2c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0d8e30:	01eec023 */ 	subu	$t8,$t7,$t6
/*  f0d8e34:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0d8e38:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0d8e3c:	afb90070 */ 	sw	$t9,0x70($sp)
/*  f0d8e40:	032f0019 */ 	multu	$t9,$t7
/*  f0d8e44:	02005025 */ 	or	$t2,$s0,$zero
/*  f0d8e48:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f0d8e4c:	00007012 */ 	mflo	$t6
/*  f0d8e50:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0d8e54:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d8e58:	03267825 */ 	or	$t7,$t9,$a2
/*  f0d8e5c:	01ed7025 */ 	or	$t6,$t7,$t5
/*  f0d8e60:	ad8e0000 */ 	sw	$t6,0x0($t4)
/*  f0d8e64:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0d8e68:	00b80019 */ 	multu	$a1,$t8
/*  f0d8e6c:	0000c812 */ 	mflo	$t9
/*  f0d8e70:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0d8e74:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0d8e78:	01c4c025 */ 	or	$t8,$t6,$a0
/*  f0d8e7c:	ad980004 */ 	sw	$t8,0x4($t4)
/*  f0d8e80:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d8e84:	01390019 */ 	multu	$t1,$t9
/*  f0d8e88:	00007812 */ 	mflo	$t7
/*  f0d8e8c:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0d8e90:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f0d8e94:	0306c825 */ 	or	$t9,$t8,$a2
/*  f0d8e98:	032d7825 */ 	or	$t7,$t9,$t5
/*  f0d8e9c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f0d8ea0:	8fb800e0 */ 	lw	$t8,0xe0($sp)
/*  f0d8ea4:	8fae00cc */ 	lw	$t6,0xcc($sp)
/*  f0d8ea8:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d8eac:	01d83821 */ 	addu	$a3,$t6,$t8
/*  f0d8eb0:	00f90019 */ 	multu	$a3,$t9
/*  f0d8eb4:	00007812 */ 	mflo	$t7
/*  f0d8eb8:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0d8ebc:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f0d8ec0:	0304c825 */ 	or	$t9,$t8,$a0
/*  f0d8ec4:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0d8ec8:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f0d8ecc:	8faf0070 */ 	lw	$t7,0x70($sp)
/*  f0d8ed0:	01ee0019 */ 	multu	$t7,$t6
/*  f0d8ed4:	0000c012 */ 	mflo	$t8
/*  f0d8ed8:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0d8edc:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0d8ee0:	01e67025 */ 	or	$t6,$t7,$a2
/*  f0d8ee4:	01c8c025 */ 	or	$t8,$t6,$t0
/*  f0d8ee8:	ad580000 */ 	sw	$t8,0x0($t2)
/*  f0d8eec:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f0d8ef0:	00b90019 */ 	multu	$a1,$t9
/*  f0d8ef4:	00007812 */ 	mflo	$t7
/*  f0d8ef8:	31ee03ff */ 	andi	$t6,$t7,0x3ff
/*  f0d8efc:	000ec380 */ 	sll	$t8,$t6,0xe
/*  f0d8f00:	031fc825 */ 	or	$t9,$t8,$ra
/*  f0d8f04:	ad590004 */ 	sw	$t9,0x4($t2)
/*  f0d8f08:	8c6f0000 */ 	lw	$t7,0x0($v1)
/*  f0d8f0c:	02001025 */ 	or	$v0,$s0,$zero
/*  f0d8f10:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f0d8f14:	012f0019 */ 	multu	$t1,$t7
/*  f0d8f18:	00007012 */ 	mflo	$t6
/*  f0d8f1c:	31d803ff */ 	andi	$t8,$t6,0x3ff
/*  f0d8f20:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0d8f24:	03267825 */ 	or	$t7,$t9,$a2
/*  f0d8f28:	01e87025 */ 	or	$t6,$t7,$t0
/*  f0d8f2c:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0d8f30:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f0d8f34:	00f80019 */ 	multu	$a3,$t8
/*  f0d8f38:	0000c812 */ 	mflo	$t9
/*  f0d8f3c:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0d8f40:	000f7380 */ 	sll	$t6,$t7,0xe
/*  f0d8f44:	01dfc025 */ 	or	$t8,$t6,$ra
/*  f0d8f48:	0fc54e0e */ 	jal	func0f153838
/*  f0d8f4c:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0d8f50:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0d8f54:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0d8f58:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f0d8f5c:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f0d8f60:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f0d8f64:	d7bc0038 */ 	ldc1	$f28,0x38($sp)
/*  f0d8f68:	d7be0040 */ 	ldc1	$f30,0x40($sp)
/*  f0d8f6c:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f0d8f70:	03e00008 */ 	jr	$ra
/*  f0d8f74:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);
#endif

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel sightRenderDefault
.late_rodata
glabel var7f1addec
.word sightRenderDefault+0xbc # f0d9034
glabel var7f1addf0
.word sightRenderDefault+0xf4 # f0d906c
glabel var7f1addf4
.word sightRenderDefault+0x1c4 # f0d913c
glabel var7f1addf8
.word sightRenderDefault+0x310 # f0d9288
glabel var7f1addfc
.word sightRenderDefault+0x3d8 # f0d9350
glabel var7f1ade00
.word sightRenderDefault+0x3d8 # f0d9350
glabel var7f1ade04
.word sightRenderDefault+0x4d8 # f0d9450
glabel var7f1ade08
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade0c
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade10
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade14
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade18
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade1c
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade20
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade24
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade28
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade2c
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade30
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade34
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade38
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade3c
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade40
.word sightRenderDefault+0x488 # f0d9400
glabel var7f1ade44
.word sightRenderDefault+0x4a4 # f0d941c
glabel var7f1ade48
.word sightRenderDefault+0x4c0 # f0d9438
glabel var7f1ade4c
.word sightRenderDefault+0x4c8 # f0d9440
glabel var7f1ade50
.word sightRenderDefault+0x4d0 # f0d9448
.text
/*  f0d8f78:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0d8f7c:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x284)
/*  f0d8f80:	8d08a244 */ 	lw	$t0,%lo(g_Vars+0x284)($t0)
/*  f0d8f84:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0d8f88:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f0d8f8c:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f0d8f90:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0d8f94:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0d8f98:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f0d8f9c:	c5041660 */ 	lwc1	$f4,0x1660($t0)
/*  f0d8fa0:	3c188008 */ 	lui	$t8,%hi(g_ScaleX)
/*  f0d8fa4:	8f18fac0 */ 	lw	$t8,%lo(g_ScaleX)($t8)
/*  f0d8fa8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d8fac:	00809825 */ 	or	$s3,$a0,$zero
/*  f0d8fb0:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d8fb4:	440f3000 */ 	mfc1	$t7,$f6
/*  f0d8fb8:	00000000 */ 	nop
/*  f0d8fbc:	01f8001a */ 	div	$zero,$t7,$t8
/*  f0d8fc0:	0000c812 */ 	mflo	$t9
/*  f0d8fc4:	afb90088 */ 	sw	$t9,0x88($sp)
/*  f0d8fc8:	c5081664 */ 	lwc1	$f8,0x1664($t0)
/*  f0d8fcc:	17000002 */ 	bnez	$t8,.L0f0d8fd8
/*  f0d8fd0:	00000000 */ 	nop
/*  f0d8fd4:	0007000d */ 	break	0x7
.L0f0d8fd8:
/*  f0d8fd8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d8fdc:	17010004 */ 	bne	$t8,$at,.L0f0d8ff0
/*  f0d8fe0:	3c018000 */ 	lui	$at,0x8000
/*  f0d8fe4:	15e10002 */ 	bne	$t7,$at,.L0f0d8ff0
/*  f0d8fe8:	00000000 */ 	nop
/*  f0d8fec:	0006000d */ 	break	0x6
.L0f0d8ff0:
/*  f0d8ff0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0d8ff4:	440c5000 */ 	mfc1	$t4,$f10
/*  f0d8ff8:	0fc54d8a */ 	jal	func0f153628
/*  f0d8ffc:	afac0084 */ 	sw	$t4,0x84($sp)
/*  f0d9000:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0d9004:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0d9008:	8d480284 */ 	lw	$t0,0x284($t2)
/*  f0d900c:	00409825 */ 	or	$s3,$v0,$zero
/*  f0d9010:	910d1b98 */ 	lbu	$t5,0x1b98($t0)
/*  f0d9014:	2da10006 */ 	sltiu	$at,$t5,0x6
/*  f0d9018:	10200141 */ 	beqz	$at,.L0f0d9520
/*  f0d901c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0d9020:	3c017f1b */ 	lui	$at,%hi(var7f1addec)
/*  f0d9024:	002d0821 */ 	addu	$at,$at,$t5
/*  f0d9028:	8c2dddec */ 	lw	$t5,%lo(var7f1addec)($at)
/*  f0d902c:	01a00008 */ 	jr	$t5
/*  f0d9030:	00000000 */ 	nop
/*  f0d9034:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f0d9038:	11c00139 */ 	beqz	$t6,.L0f0d9520
/*  f0d903c:	3c1800ff */ 	lui	$t8,0xff
/*  f0d9040:	37180028 */ 	ori	$t8,$t8,0x28
/*  f0d9044:	240f0005 */ 	addiu	$t7,$zero,0x5
/*  f0d9048:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0d904c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0d9050:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d9054:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0d9058:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0d905c:	0fc35fd5 */ 	jal	func0f0d7f54
/*  f0d9060:	24070008 */ 	addiu	$a3,$zero,0x8
/*  f0d9064:	1000012e */ 	b	.L0f0d9520
/*  f0d9068:	00409825 */ 	or	$s3,$v0,$zero
/*  f0d906c:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f0d9070:	1320012b */ 	beqz	$t9,.L0f0d9520
/*  f0d9074:	00000000 */ 	nop
/*  f0d9078:	8d0b1624 */ 	lw	$t3,0x1624($t0)
/*  f0d907c:	3c1000ff */ 	lui	$s0,0xff
/*  f0d9080:	36100028 */ 	ori	$s0,$s0,0x28
/*  f0d9084:	15600003 */ 	bnez	$t3,.L0f0d9094
/*  f0d9088:	24110008 */ 	addiu	$s1,$zero,0x8
/*  f0d908c:	1000000a */ 	b	.L0f0d90b8
/*  f0d9090:	24030005 */ 	addiu	$v1,$zero,0x5
.L0f0d9094:
/*  f0d9094:	0fc35c1c */ 	jal	sightIsPropFriendly
/*  f0d9098:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d909c:	10400003 */ 	beqz	$v0,.L0f0d90ac
/*  f0d90a0:	24110006 */ 	addiu	$s1,$zero,0x6
/*  f0d90a4:	10000003 */ 	b	.L0f0d90b4
/*  f0d90a8:	3410ff60 */ 	dli	$s0,0xff60
.L0f0d90ac:
/*  f0d90ac:	3c10ff00 */ 	lui	$s0,0xff00
/*  f0d90b0:	36100060 */ 	ori	$s0,$s0,0x60
.L0f0d90b4:
/*  f0d90b4:	24030003 */ 	addiu	$v1,$zero,0x3
.L0f0d90b8:
/*  f0d90b8:	3c047f1b */ 	lui	$a0,%hi(var7f1adda0)
/*  f0d90bc:	3c058007 */ 	lui	$a1,%hi(var80070f94)
/*  f0d90c0:	24a50f94 */ 	addiu	$a1,$a1,%lo(var80070f94)
/*  f0d90c4:	2484dda0 */ 	addiu	$a0,$a0,%lo(var7f1adda0)
/*  f0d90c8:	0c0036cc */ 	jal	func0000db30
/*  f0d90cc:	afa30090 */ 	sw	$v1,0x90($sp)
/*  f0d90d0:	3c028007 */ 	lui	$v0,%hi(var80070f94)
/*  f0d90d4:	8c420f94 */ 	lw	$v0,%lo(var80070f94)($v0)
/*  f0d90d8:	8fa30090 */ 	lw	$v1,0x90($sp)
/*  f0d90dc:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d90e0:	10400006 */ 	beqz	$v0,.L0f0d90fc
/*  f0d90e4:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0d90e8:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0d90ec:	1052000a */ 	beq	$v0,$s2,.L0f0d9118
/*  f0d90f0:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d90f4:	1000010a */ 	b	.L0f0d9520
/*  f0d90f8:	00000000 */ 	nop
.L0f0d90fc:
/*  f0d90fc:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0d9100:	02203825 */ 	or	$a3,$s1,$zero
/*  f0d9104:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0d9108:	0fc35fd5 */ 	jal	func0f0d7f54
/*  f0d910c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d9110:	10000103 */ 	b	.L0f0d9520
/*  f0d9114:	00409825 */ 	or	$s3,$v0,$zero
.L0f0d9118:
/*  f0d9118:	00036040 */ 	sll	$t4,$v1,0x1
/*  f0d911c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0d9120:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0d9124:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0d9128:	00113840 */ 	sll	$a3,$s1,0x1
/*  f0d912c:	0fc361ea */ 	jal	func0f0d87a8
/*  f0d9130:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d9134:	100000fa */ 	b	.L0f0d9520
/*  f0d9138:	00409825 */ 	or	$s3,$v0,$zero
/*  f0d913c:	8fad009c */ 	lw	$t5,0x9c($sp)
/*  f0d9140:	11a000f7 */ 	beqz	$t5,.L0f0d9520
/*  f0d9144:	00000000 */ 	nop
/*  f0d9148:	8d0e1624 */ 	lw	$t6,0x1624($t0)
/*  f0d914c:	3c1000ff */ 	lui	$s0,0xff
/*  f0d9150:	36100028 */ 	ori	$s0,$s0,0x28
/*  f0d9154:	15c00003 */ 	bnez	$t6,.L0f0d9164
/*  f0d9158:	24110008 */ 	addiu	$s1,$zero,0x8
/*  f0d915c:	1000000c */ 	b	.L0f0d9190
/*  f0d9160:	24030005 */ 	addiu	$v1,$zero,0x5
.L0f0d9164:
/*  f0d9164:	0fc35c1c */ 	jal	sightIsPropFriendly
/*  f0d9168:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d916c:	10400003 */ 	beqz	$v0,.L0f0d917c
/*  f0d9170:	24110006 */ 	addiu	$s1,$zero,0x6
/*  f0d9174:	10000003 */ 	b	.L0f0d9184
/*  f0d9178:	3410ff60 */ 	dli	$s0,0xff60
.L0f0d917c:
/*  f0d917c:	3c10ff00 */ 	lui	$s0,0xff00
/*  f0d9180:	36100060 */ 	ori	$s0,$s0,0x60
.L0f0d9184:
/*  f0d9184:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0d9188:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0d918c:	24030003 */ 	addiu	$v1,$zero,0x3
.L0f0d9190:
/*  f0d9190:	3c028007 */ 	lui	$v0,%hi(var80070f98)
/*  f0d9194:	8c420f98 */ 	lw	$v0,%lo(var80070f98)($v0)
/*  f0d9198:	8d590034 */ 	lw	$t9,0x34($t2)
/*  f0d919c:	240f0087 */ 	addiu	$t7,$zero,0x87
/*  f0d91a0:	241800c8 */ 	addiu	$t8,$zero,0xc8
/*  f0d91a4:	00591021 */ 	addu	$v0,$v0,$t9
/*  f0d91a8:	304b0080 */ 	andi	$t3,$v0,0x80
/*  f0d91ac:	3c018007 */ 	lui	$at,%hi(var80070f98)
/*  f0d91b0:	afaf0078 */ 	sw	$t7,0x78($sp)
/*  f0d91b4:	afb80074 */ 	sw	$t8,0x74($sp)
/*  f0d91b8:	1160001f */ 	beqz	$t3,.L0f0d9238
/*  f0d91bc:	ac220f98 */ 	sw	$v0,%lo(var80070f98)($at)
/*  f0d91c0:	240459b7 */ 	addiu	$a0,$zero,0x58b4
/*  f0d91c4:	0fc5b9f1 */ 	jal	langGet
/*  f0d91c8:	afa30090 */ 	sw	$v1,0x90($sp)
/*  f0d91cc:	0c002f02 */ 	jal	viGetWidth
/*  f0d91d0:	00409025 */ 	or	$s2,$v0,$zero
/*  f0d91d4:	0c002f06 */ 	jal	viGetHeight
/*  f0d91d8:	a7a20060 */ 	sh	$v0,0x60($sp)
/*  f0d91dc:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicXs1)
/*  f0d91e0:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicXs2)
/*  f0d91e4:	8dadfb04 */ 	lw	$t5,%lo(g_FontHandelGothicXs2)($t5)
/*  f0d91e8:	8d8cfb08 */ 	lw	$t4,%lo(g_FontHandelGothicXs1)($t4)
/*  f0d91ec:	87b80060 */ 	lh	$t8,0x60($sp)
/*  f0d91f0:	3c0e00ff */ 	lui	$t6,0xff
/*  f0d91f4:	35ce00a0 */ 	ori	$t6,$t6,0xa0
/*  f0d91f8:	240f00a0 */ 	addiu	$t7,$zero,0xa0
/*  f0d91fc:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0d9200:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0d9204:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d9208:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0d920c:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0d9210:	02403825 */ 	or	$a3,$s2,$zero
/*  f0d9214:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0d9218:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0d921c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0d9220:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0d9224:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0d9228:	0fc55b92 */ 	jal	textRender
/*  f0d922c:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0d9230:	8fa30090 */ 	lw	$v1,0x90($sp)
/*  f0d9234:	00409825 */ 	or	$s3,$v0,$zero
.L0f0d9238:
/*  f0d9238:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d923c:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0d9240:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0d9244:	02203825 */ 	or	$a3,$s1,$zero
/*  f0d9248:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0d924c:	0fc35fd5 */ 	jal	func0f0d7f54
/*  f0d9250:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d9254:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x284)
/*  f0d9258:	8d08a244 */ 	lw	$t0,%lo(g_Vars+0x284)($t0)
/*  f0d925c:	00409825 */ 	or	$s3,$v0,$zero
/*  f0d9260:	00402025 */ 	or	$a0,$v0,$zero
/*  f0d9264:	8d191624 */ 	lw	$t9,0x1624($t0)
/*  f0d9268:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0d926c:	25051624 */ 	addiu	$a1,$t0,0x1624
/*  f0d9270:	132000ab */ 	beqz	$t9,.L0f0d9520
/*  f0d9274:	00000000 */ 	nop
/*  f0d9278:	0fc35e3d */ 	jal	sightRenderTargetBox
/*  f0d927c:	95071b90 */ 	lhu	$a3,0x1b90($t0)
/*  f0d9280:	100000a7 */ 	b	.L0f0d9520
/*  f0d9284:	00409825 */ 	or	$s3,$v0,$zero
/*  f0d9288:	00008025 */ 	or	$s0,$zero,$zero
/*  f0d928c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0d9290:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f0d9294:
/*  f0d9294:	8d480284 */ 	lw	$t0,0x284($t2)
/*  f0d9298:	00106040 */ 	sll	$t4,$s0,0x1
/*  f0d929c:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d92a0:	01112821 */ 	addu	$a1,$t0,$s1
/*  f0d92a4:	8cab1630 */ 	lw	$t3,0x1630($a1)
/*  f0d92a8:	24a51630 */ 	addiu	$a1,$a1,0x1630
/*  f0d92ac:	00003025 */ 	or	$a2,$zero,$zero
/*  f0d92b0:	11600006 */ 	beqz	$t3,.L0f0d92cc
/*  f0d92b4:	010c6821 */ 	addu	$t5,$t0,$t4
/*  f0d92b8:	0fc35e3d */ 	jal	sightRenderTargetBox
/*  f0d92bc:	95a71b90 */ 	lhu	$a3,0x1b90($t5)
/*  f0d92c0:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0d92c4:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0d92c8:	00409825 */ 	or	$s3,$v0,$zero
.L0f0d92cc:
/*  f0d92cc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0d92d0:	1612fff0 */ 	bne	$s0,$s2,.L0f0d9294
/*  f0d92d4:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f0d92d8:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f0d92dc:	11c00090 */ 	beqz	$t6,.L0f0d9520
/*  f0d92e0:	00000000 */ 	nop
/*  f0d92e4:	8d4f0284 */ 	lw	$t7,0x284($t2)
/*  f0d92e8:	3c1000ff */ 	lui	$s0,0xff
/*  f0d92ec:	36100028 */ 	ori	$s0,$s0,0x28
/*  f0d92f0:	8df81624 */ 	lw	$t8,0x1624($t7)
/*  f0d92f4:	24110008 */ 	addiu	$s1,$zero,0x8
/*  f0d92f8:	17000003 */ 	bnez	$t8,.L0f0d9308
/*  f0d92fc:	00000000 */ 	nop
/*  f0d9300:	1000000a */ 	b	.L0f0d932c
/*  f0d9304:	24030005 */ 	addiu	$v1,$zero,0x5
.L0f0d9308:
/*  f0d9308:	0fc35c1c */ 	jal	sightIsPropFriendly
/*  f0d930c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d9310:	10400003 */ 	beqz	$v0,.L0f0d9320
/*  f0d9314:	24110006 */ 	addiu	$s1,$zero,0x6
/*  f0d9318:	10000003 */ 	b	.L0f0d9328
/*  f0d931c:	3410ff60 */ 	dli	$s0,0xff60
.L0f0d9320:
/*  f0d9320:	3c10ff00 */ 	lui	$s0,0xff00
/*  f0d9324:	36100060 */ 	ori	$s0,$s0,0x60
.L0f0d9328:
/*  f0d9328:	24030003 */ 	addiu	$v1,$zero,0x3
.L0f0d932c:
/*  f0d932c:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d9330:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0d9334:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0d9338:	02203825 */ 	or	$a3,$s1,$zero
/*  f0d933c:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0d9340:	0fc35fd5 */ 	jal	func0f0d7f54
/*  f0d9344:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d9348:	10000075 */ 	b	.L0f0d9520
/*  f0d934c:	00409825 */ 	or	$s3,$v0,$zero
/*  f0d9350:	00008025 */ 	or	$s0,$zero,$zero
/*  f0d9354:	00008825 */ 	or	$s1,$zero,$zero
/*  f0d9358:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f0d935c:
/*  f0d935c:	8d480284 */ 	lw	$t0,0x284($t2)
/*  f0d9360:	01112821 */ 	addu	$a1,$t0,$s1
/*  f0d9364:	8ca31630 */ 	lw	$v1,0x1630($a1)
/*  f0d9368:	24a51630 */ 	addiu	$a1,$a1,0x1630
/*  f0d936c:	5060004c */ 	beqzl	$v1,.L0f0d94a0
/*  f0d9370:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0d9374:	91191b98 */ 	lbu	$t9,0x1b98($t0)
/*  f0d9378:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0d937c:	00104840 */ 	sll	$t1,$s0,0x1
/*  f0d9380:	1721003f */ 	bne	$t9,$at,.L0f0d9480
/*  f0d9384:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d9388:	8c640004 */ 	lw	$a0,0x4($v1)
/*  f0d938c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0d9390:	1080000b */ 	beqz	$a0,.L0f0d93c0
/*  f0d9394:	00801025 */ 	or	$v0,$a0,$zero
/*  f0d9398:	904b0003 */ 	lbu	$t3,0x3($v0)
/*  f0d939c:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0d93a0:	15610007 */ 	bne	$t3,$at,.L0f0d93c0
/*  f0d93a4:	00000000 */ 	nop
/*  f0d93a8:	8c4c000c */ 	lw	$t4,0xc($v0)
/*  f0d93ac:	3c01a000 */ 	lui	$at,0xa000
/*  f0d93b0:	01816824 */ 	and	$t5,$t4,$at
/*  f0d93b4:	15a00002 */ 	bnez	$t5,.L0f0d93c0
/*  f0d93b8:	00000000 */ 	nop
/*  f0d93bc:	24064cd7 */ 	addiu	$a2,$zero,0x4cd7
.L0f0d93c0:
/*  f0d93c0:	10800027 */ 	beqz	$a0,.L0f0d9460
/*  f0d93c4:	00801025 */ 	or	$v0,$a0,$zero
/*  f0d93c8:	908e0003 */ 	lbu	$t6,0x3($a0)
/*  f0d93cc:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0d93d0:	55c10024 */ 	bnel	$t6,$at,.L0f0d9464
/*  f0d93d4:	01096821 */ 	addu	$t5,$t0,$t1
/*  f0d93d8:	908f005c */ 	lbu	$t7,0x5c($a0)
/*  f0d93dc:	25f8fff1 */ 	addiu	$t8,$t7,-15
/*  f0d93e0:	2f010014 */ 	sltiu	$at,$t8,0x14
/*  f0d93e4:	1020001e */ 	beqz	$at,.L0f0d9460
/*  f0d93e8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0d93ec:	3c017f1b */ 	lui	$at,%hi(var7f1ade04)
/*  f0d93f0:	00380821 */ 	addu	$at,$at,$t8
/*  f0d93f4:	8c38de04 */ 	lw	$t8,%lo(var7f1ade04)($at)
/*  f0d93f8:	03000008 */ 	jr	$t8
/*  f0d93fc:	00000000 */ 	nop
/*  f0d9400:	9059005f */ 	lbu	$t9,0x5f($v0)
/*  f0d9404:	16590003 */ 	bne	$s2,$t9,.L0f0d9414
/*  f0d9408:	00000000 */ 	nop
/*  f0d940c:	10000014 */ 	b	.L0f0d9460
/*  f0d9410:	24064cd4 */ 	addiu	$a2,$zero,0x4cd4
.L0f0d9414:
/*  f0d9414:	10000012 */ 	b	.L0f0d9460
/*  f0d9418:	24064cd5 */ 	addiu	$a2,$zero,0x4cd5
/*  f0d941c:	904b005f */ 	lbu	$t3,0x5f($v0)
/*  f0d9420:	164b0003 */ 	bne	$s2,$t3,.L0f0d9430
/*  f0d9424:	00000000 */ 	nop
/*  f0d9428:	1000000d */ 	b	.L0f0d9460
/*  f0d942c:	24064cd4 */ 	addiu	$a2,$zero,0x4cd4
.L0f0d9430:
/*  f0d9430:	1000000b */ 	b	.L0f0d9460
/*  f0d9434:	24064cd8 */ 	addiu	$a2,$zero,0x4cd8
/*  f0d9438:	10000009 */ 	b	.L0f0d9460
/*  f0d943c:	24064cd5 */ 	addiu	$a2,$zero,0x4cd5
/*  f0d9440:	10000007 */ 	b	.L0f0d9460
/*  f0d9444:	24064cd4 */ 	addiu	$a2,$zero,0x4cd4
/*  f0d9448:	10000005 */ 	b	.L0f0d9460
/*  f0d944c:	24064cd6 */ 	addiu	$a2,$zero,0x4cd6
/*  f0d9450:	904c005f */ 	lbu	$t4,0x5f($v0)
/*  f0d9454:	564c0003 */ 	bnel	$s2,$t4,.L0f0d9464
/*  f0d9458:	01096821 */ 	addu	$t5,$t0,$t1
/*  f0d945c:	24064cd4 */ 	addiu	$a2,$zero,0x4cd4
.L0f0d9460:
/*  f0d9460:	01096821 */ 	addu	$t5,$t0,$t1
.L0f0d9464:
/*  f0d9464:	95a71b90 */ 	lhu	$a3,0x1b90($t5)
/*  f0d9468:	0fc35e3d */ 	jal	sightRenderTargetBox
/*  f0d946c:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d9470:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0d9474:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0d9478:	10000008 */ 	b	.L0f0d949c
/*  f0d947c:	00409825 */ 	or	$s3,$v0,$zero
.L0f0d9480:
/*  f0d9480:	01097021 */ 	addu	$t6,$t0,$t1
/*  f0d9484:	95c71b90 */ 	lhu	$a3,0x1b90($t6)
/*  f0d9488:	0fc35e3d */ 	jal	sightRenderTargetBox
/*  f0d948c:	26060002 */ 	addiu	$a2,$s0,0x2
/*  f0d9490:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0d9494:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0d9498:	00409825 */ 	or	$s3,$v0,$zero
.L0f0d949c:
/*  f0d949c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0d94a0:
/*  f0d94a0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0d94a4:	1601ffad */ 	bne	$s0,$at,.L0f0d935c
/*  f0d94a8:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f0d94ac:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f0d94b0:	11e0001b */ 	beqz	$t7,.L0f0d9520
/*  f0d94b4:	00000000 */ 	nop
/*  f0d94b8:	8d580284 */ 	lw	$t8,0x284($t2)
/*  f0d94bc:	3c1000ff */ 	lui	$s0,0xff
/*  f0d94c0:	36100028 */ 	ori	$s0,$s0,0x28
/*  f0d94c4:	8f191624 */ 	lw	$t9,0x1624($t8)
/*  f0d94c8:	24110008 */ 	addiu	$s1,$zero,0x8
/*  f0d94cc:	17200003 */ 	bnez	$t9,.L0f0d94dc
/*  f0d94d0:	00000000 */ 	nop
/*  f0d94d4:	1000000a */ 	b	.L0f0d9500
/*  f0d94d8:	24030005 */ 	addiu	$v1,$zero,0x5
.L0f0d94dc:
/*  f0d94dc:	0fc35c1c */ 	jal	sightIsPropFriendly
/*  f0d94e0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d94e4:	10400003 */ 	beqz	$v0,.L0f0d94f4
/*  f0d94e8:	24110006 */ 	addiu	$s1,$zero,0x6
/*  f0d94ec:	10000003 */ 	b	.L0f0d94fc
/*  f0d94f0:	3410ff60 */ 	dli	$s0,0xff60
.L0f0d94f4:
/*  f0d94f4:	3c10ff00 */ 	lui	$s0,0xff00
/*  f0d94f8:	36100060 */ 	ori	$s0,$s0,0x60
.L0f0d94fc:
/*  f0d94fc:	24030003 */ 	addiu	$v1,$zero,0x3
.L0f0d9500:
/*  f0d9500:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d9504:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0d9508:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0d950c:	02203825 */ 	or	$a3,$s1,$zero
/*  f0d9510:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0d9514:	0fc35fd5 */ 	jal	func0f0d7f54
/*  f0d9518:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d951c:	00409825 */ 	or	$s3,$v0,$zero
.L0f0d9520:
/*  f0d9520:	0fc54de0 */ 	jal	func0f153780
/*  f0d9524:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d9528:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0d952c:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0d9530:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0d9534:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f0d9538:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f0d953c:	03e00008 */ 	jr	$ra
/*  f0d9540:	27bd0098 */ 	addiu	$sp,$sp,0x98
);
#else
GLOBAL_ASM(
glabel sightRenderDefault
.late_rodata
glabel var7f1addec
.word sightRenderDefault+0xbc # f0d9034
glabel var7f1addf0
.word sightRenderDefault+0xf4 # f0d906c
glabel var7f1addf4
.word sightRenderDefault+0x1c4 # f0d913c
glabel var7f1addf8
.word sightRenderDefault+0x310 # f0d9288
glabel var7f1addfc
.word sightRenderDefault+0x3d8 # f0d9350
glabel var7f1ade00
.word sightRenderDefault+0x3d8 # f0d9350
glabel var7f1ade04
.word sightRenderDefault+0x4d8 # f0d9450
glabel var7f1ade08
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade0c
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade10
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade14
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade18
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade1c
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade20
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade24
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade28
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade2c
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade30
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade34
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade38
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade3c
.word sightRenderDefault+0x4e8 # f0d9460
glabel var7f1ade40
.word sightRenderDefault+0x488 # f0d9400
glabel var7f1ade44
.word sightRenderDefault+0x4a4 # f0d941c
glabel var7f1ade48
.word sightRenderDefault+0x4c0 # f0d9438
glabel var7f1ade4c
.word sightRenderDefault+0x4c8 # f0d9440
glabel var7f1ade50
.word sightRenderDefault+0x4d0 # f0d9448
.text
/*  f0d8f78:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f0d8f7c:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x284)
/*  f0d8f80:	8d08a244 */ 	lw	$t0,%lo(g_Vars+0x284)($t0)
/*  f0d8f84:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0d8f88:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f0d8f8c:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f0d8f90:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0d8f94:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0d8f98:	afa5009c */ 	sw	$a1,0x9c($sp)
/*  f0d8f9c:	c5041660 */ 	lwc1	$f4,0x1660($t0)
/*  f0d8fa0:	3c188008 */ 	lui	$t8,%hi(g_ScaleX)
/*  f0d8fa4:	8f18fac0 */ 	lw	$t8,%lo(g_ScaleX)($t8)
/*  f0d8fa8:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d8fac:	00809825 */ 	or	$s3,$a0,$zero
/*  f0d8fb0:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d8fb4:	440f3000 */ 	mfc1	$t7,$f6
/*  f0d8fb8:	00000000 */ 	nop
/*  f0d8fbc:	01f8001a */ 	div	$zero,$t7,$t8
/*  f0d8fc0:	0000c812 */ 	mflo	$t9
/*  f0d8fc4:	afb90088 */ 	sw	$t9,0x88($sp)
/*  f0d8fc8:	c5081664 */ 	lwc1	$f8,0x1664($t0)
/*  f0d8fcc:	17000002 */ 	bnez	$t8,.L0f0d8fd8
/*  f0d8fd0:	00000000 */ 	nop
/*  f0d8fd4:	0007000d */ 	break	0x7
.L0f0d8fd8:
/*  f0d8fd8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d8fdc:	17010004 */ 	bne	$t8,$at,.L0f0d8ff0
/*  f0d8fe0:	3c018000 */ 	lui	$at,0x8000
/*  f0d8fe4:	15e10002 */ 	bne	$t7,$at,.L0f0d8ff0
/*  f0d8fe8:	00000000 */ 	nop
/*  f0d8fec:	0006000d */ 	break	0x6
.L0f0d8ff0:
/*  f0d8ff0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0d8ff4:	440c5000 */ 	mfc1	$t4,$f10
/*  f0d8ff8:	0fc54d8a */ 	jal	func0f153628
/*  f0d8ffc:	afac0084 */ 	sw	$t4,0x84($sp)
/*  f0d9000:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0d9004:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0d9008:	8d480284 */ 	lw	$t0,0x284($t2)
/*  f0d900c:	00409825 */ 	or	$s3,$v0,$zero
/*  f0d9010:	910d1b98 */ 	lbu	$t5,0x1b98($t0)
/*  f0d9014:	2da10006 */ 	sltiu	$at,$t5,0x6
/*  f0d9018:	10200141 */ 	beqz	$at,.L0f0d9520
/*  f0d901c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0d9020:	3c017f1b */ 	lui	$at,%hi(var7f1addec)
/*  f0d9024:	002d0821 */ 	addu	$at,$at,$t5
/*  f0d9028:	8c2dddec */ 	lw	$t5,%lo(var7f1addec)($at)
/*  f0d902c:	01a00008 */ 	jr	$t5
/*  f0d9030:	00000000 */ 	nop
/*  f0d9034:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f0d9038:	11c00139 */ 	beqz	$t6,.L0f0d9520
/*  f0d903c:	3c1800ff */ 	lui	$t8,0xff
/*  f0d9040:	37180028 */ 	ori	$t8,$t8,0x28
/*  f0d9044:	240f0005 */ 	addiu	$t7,$zero,0x5
/*  f0d9048:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0d904c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0d9050:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d9054:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0d9058:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0d905c:	0fc35fd5 */ 	jal	func0f0d7f54
/*  f0d9060:	24070008 */ 	addiu	$a3,$zero,0x8
/*  f0d9064:	1000012e */ 	b	.L0f0d9520
/*  f0d9068:	00409825 */ 	or	$s3,$v0,$zero
/*  f0d906c:	8fb9009c */ 	lw	$t9,0x9c($sp)
/*  f0d9070:	1320012b */ 	beqz	$t9,.L0f0d9520
/*  f0d9074:	00000000 */ 	nop
/*  f0d9078:	8d0b1624 */ 	lw	$t3,0x1624($t0)
/*  f0d907c:	3c1000ff */ 	lui	$s0,0xff
/*  f0d9080:	36100028 */ 	ori	$s0,$s0,0x28
/*  f0d9084:	15600003 */ 	bnez	$t3,.L0f0d9094
/*  f0d9088:	24110008 */ 	addiu	$s1,$zero,0x8
/*  f0d908c:	1000000a */ 	b	.L0f0d90b8
/*  f0d9090:	24030005 */ 	addiu	$v1,$zero,0x5
.L0f0d9094:
/*  f0d9094:	0fc35c1c */ 	jal	sightIsPropFriendly
/*  f0d9098:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d909c:	10400003 */ 	beqz	$v0,.L0f0d90ac
/*  f0d90a0:	24110006 */ 	addiu	$s1,$zero,0x6
/*  f0d90a4:	10000003 */ 	b	.L0f0d90b4
/*  f0d90a8:	3410ff60 */ 	dli	$s0,0xff60
.L0f0d90ac:
/*  f0d90ac:	3c10ff00 */ 	lui	$s0,0xff00
/*  f0d90b0:	36100060 */ 	ori	$s0,$s0,0x60
.L0f0d90b4:
/*  f0d90b4:	24030003 */ 	addiu	$v1,$zero,0x3
.L0f0d90b8:
/*  f0d90b8:	3c047f1b */ 	lui	$a0,%hi(var7f1adda0)
/*  f0d90bc:	3c058007 */ 	lui	$a1,%hi(var80070f94)
/*  f0d90c0:	24a50f94 */ 	addiu	$a1,$a1,%lo(var80070f94)
/*  f0d90c4:	2484dda0 */ 	addiu	$a0,$a0,%lo(var7f1adda0)
/*  f0d90c8:	0c0036cc */ 	jal	func0000db30
/*  f0d90cc:	afa30090 */ 	sw	$v1,0x90($sp)
/*  f0d90d0:	3c028007 */ 	lui	$v0,%hi(var80070f94)
/*  f0d90d4:	8c420f94 */ 	lw	$v0,%lo(var80070f94)($v0)
/*  f0d90d8:	8fa30090 */ 	lw	$v1,0x90($sp)
/*  f0d90dc:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d90e0:	10400006 */ 	beqz	$v0,.L0f0d90fc
/*  f0d90e4:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0d90e8:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f0d90ec:	1052000a */ 	beq	$v0,$s2,.L0f0d9118
/*  f0d90f0:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d90f4:	1000010a */ 	b	.L0f0d9520
/*  f0d90f8:	00000000 */ 	nop
.L0f0d90fc:
/*  f0d90fc:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0d9100:	02203825 */ 	or	$a3,$s1,$zero
/*  f0d9104:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0d9108:	0fc35fd5 */ 	jal	func0f0d7f54
/*  f0d910c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d9110:	10000103 */ 	b	.L0f0d9520
/*  f0d9114:	00409825 */ 	or	$s3,$v0,$zero
.L0f0d9118:
/*  f0d9118:	00036040 */ 	sll	$t4,$v1,0x1
/*  f0d911c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0d9120:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0d9124:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0d9128:	00113840 */ 	sll	$a3,$s1,0x1
/*  f0d912c:	0fc361ea */ 	jal	func0f0d87a8
/*  f0d9130:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d9134:	100000fa */ 	b	.L0f0d9520
/*  f0d9138:	00409825 */ 	or	$s3,$v0,$zero
/*  f0d913c:	8fad009c */ 	lw	$t5,0x9c($sp)
/*  f0d9140:	11a000f7 */ 	beqz	$t5,.L0f0d9520
/*  f0d9144:	00000000 */ 	nop
/*  f0d9148:	8d0e1624 */ 	lw	$t6,0x1624($t0)
/*  f0d914c:	3c1000ff */ 	lui	$s0,0xff
/*  f0d9150:	36100028 */ 	ori	$s0,$s0,0x28
/*  f0d9154:	15c00003 */ 	bnez	$t6,.L0f0d9164
/*  f0d9158:	24110008 */ 	addiu	$s1,$zero,0x8
/*  f0d915c:	1000000c */ 	b	.L0f0d9190
/*  f0d9160:	24030005 */ 	addiu	$v1,$zero,0x5
.L0f0d9164:
/*  f0d9164:	0fc35c1c */ 	jal	sightIsPropFriendly
/*  f0d9168:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d916c:	10400003 */ 	beqz	$v0,.L0f0d917c
/*  f0d9170:	24110006 */ 	addiu	$s1,$zero,0x6
/*  f0d9174:	10000003 */ 	b	.L0f0d9184
/*  f0d9178:	3410ff60 */ 	dli	$s0,0xff60
.L0f0d917c:
/*  f0d917c:	3c10ff00 */ 	lui	$s0,0xff00
/*  f0d9180:	36100060 */ 	ori	$s0,$s0,0x60
.L0f0d9184:
/*  f0d9184:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0d9188:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0d918c:	24030003 */ 	addiu	$v1,$zero,0x3
.L0f0d9190:
/*  f0d9190:	3c028007 */ 	lui	$v0,%hi(var80070f98)
/*  f0d9194:	8c420f98 */ 	lw	$v0,%lo(var80070f98)($v0)
/*  f0d9198:	8d590034 */ 	lw	$t9,0x34($t2)
/*  f0d919c:	240f0087 */ 	addiu	$t7,$zero,0x87
/*  f0d91a0:	241800c8 */ 	addiu	$t8,$zero,0xc8
/*  f0d91a4:	00591021 */ 	addu	$v0,$v0,$t9
/*  f0d91a8:	304b0080 */ 	andi	$t3,$v0,0x80
/*  f0d91ac:	3c018007 */ 	lui	$at,%hi(var80070f98)
/*  f0d91b0:	afaf0078 */ 	sw	$t7,0x78($sp)
/*  f0d91b4:	afb80074 */ 	sw	$t8,0x74($sp)
/*  f0d91b8:	1160001f */ 	beqz	$t3,.L0f0d9238
/*  f0d91bc:	ac220f98 */ 	sw	$v0,%lo(var80070f98)($at)
/*  f0d91c0:	240459b7 */ 	addiu	$a0,$zero,0x59b7
/*  f0d91c4:	0fc5b9f1 */ 	jal	langGet
/*  f0d91c8:	afa30090 */ 	sw	$v1,0x90($sp)
/*  f0d91cc:	0c002f02 */ 	jal	viGetWidth
/*  f0d91d0:	00409025 */ 	or	$s2,$v0,$zero
/*  f0d91d4:	0c002f06 */ 	jal	viGetHeight
/*  f0d91d8:	a7a20060 */ 	sh	$v0,0x60($sp)
/*  f0d91dc:	3c0c8008 */ 	lui	$t4,%hi(g_FontHandelGothicXs1)
/*  f0d91e0:	3c0d8008 */ 	lui	$t5,%hi(g_FontHandelGothicXs2)
/*  f0d91e4:	8dadfb04 */ 	lw	$t5,%lo(g_FontHandelGothicXs2)($t5)
/*  f0d91e8:	8d8cfb08 */ 	lw	$t4,%lo(g_FontHandelGothicXs1)($t4)
/*  f0d91ec:	87b80060 */ 	lh	$t8,0x60($sp)
/*  f0d91f0:	3c0e00ff */ 	lui	$t6,0xff
/*  f0d91f4:	35ce00a0 */ 	ori	$t6,$t6,0xa0
/*  f0d91f8:	240f00a0 */ 	addiu	$t7,$zero,0xa0
/*  f0d91fc:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f0d9200:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f0d9204:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d9208:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f0d920c:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f0d9210:	02403825 */ 	or	$a3,$s2,$zero
/*  f0d9214:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0d9218:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0d921c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f0d9220:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f0d9224:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0d9228:	0fc55b92 */ 	jal	textRender
/*  f0d922c:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f0d9230:	8fa30090 */ 	lw	$v1,0x90($sp)
/*  f0d9234:	00409825 */ 	or	$s3,$v0,$zero
.L0f0d9238:
/*  f0d9238:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d923c:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0d9240:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0d9244:	02203825 */ 	or	$a3,$s1,$zero
/*  f0d9248:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0d924c:	0fc35fd5 */ 	jal	func0f0d7f54
/*  f0d9250:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d9254:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x284)
/*  f0d9258:	8d08a244 */ 	lw	$t0,%lo(g_Vars+0x284)($t0)
/*  f0d925c:	00409825 */ 	or	$s3,$v0,$zero
/*  f0d9260:	00402025 */ 	or	$a0,$v0,$zero
/*  f0d9264:	8d191624 */ 	lw	$t9,0x1624($t0)
/*  f0d9268:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0d926c:	25051624 */ 	addiu	$a1,$t0,0x1624
/*  f0d9270:	132000ab */ 	beqz	$t9,.L0f0d9520
/*  f0d9274:	00000000 */ 	nop
/*  f0d9278:	0fc35e3d */ 	jal	sightRenderTargetBox
/*  f0d927c:	95071b90 */ 	lhu	$a3,0x1b90($t0)
/*  f0d9280:	100000a7 */ 	b	.L0f0d9520
/*  f0d9284:	00409825 */ 	or	$s3,$v0,$zero
/*  f0d9288:	00008025 */ 	or	$s0,$zero,$zero
/*  f0d928c:	00008825 */ 	or	$s1,$zero,$zero
/*  f0d9290:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f0d9294:
/*  f0d9294:	8d480284 */ 	lw	$t0,0x284($t2)
/*  f0d9298:	00106040 */ 	sll	$t4,$s0,0x1
/*  f0d929c:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d92a0:	01112821 */ 	addu	$a1,$t0,$s1
/*  f0d92a4:	8cab1630 */ 	lw	$t3,0x1630($a1)
/*  f0d92a8:	24a51630 */ 	addiu	$a1,$a1,0x1630
/*  f0d92ac:	00003025 */ 	or	$a2,$zero,$zero
/*  f0d92b0:	11600006 */ 	beqz	$t3,.L0f0d92cc
/*  f0d92b4:	010c6821 */ 	addu	$t5,$t0,$t4
/*  f0d92b8:	0fc35e3d */ 	jal	sightRenderTargetBox
/*  f0d92bc:	95a71b90 */ 	lhu	$a3,0x1b90($t5)
/*  f0d92c0:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0d92c4:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0d92c8:	00409825 */ 	or	$s3,$v0,$zero
.L0f0d92cc:
/*  f0d92cc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0d92d0:	1612fff0 */ 	bne	$s0,$s2,.L0f0d9294
/*  f0d92d4:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f0d92d8:	8fae009c */ 	lw	$t6,0x9c($sp)
/*  f0d92dc:	11c00090 */ 	beqz	$t6,.L0f0d9520
/*  f0d92e0:	00000000 */ 	nop
/*  f0d92e4:	8d4f0284 */ 	lw	$t7,0x284($t2)
/*  f0d92e8:	3c1000ff */ 	lui	$s0,0xff
/*  f0d92ec:	36100028 */ 	ori	$s0,$s0,0x28
/*  f0d92f0:	8df81624 */ 	lw	$t8,0x1624($t7)
/*  f0d92f4:	24110008 */ 	addiu	$s1,$zero,0x8
/*  f0d92f8:	17000003 */ 	bnez	$t8,.L0f0d9308
/*  f0d92fc:	00000000 */ 	nop
/*  f0d9300:	1000000a */ 	b	.L0f0d932c
/*  f0d9304:	24030005 */ 	addiu	$v1,$zero,0x5
.L0f0d9308:
/*  f0d9308:	0fc35c1c */ 	jal	sightIsPropFriendly
/*  f0d930c:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d9310:	10400003 */ 	beqz	$v0,.L0f0d9320
/*  f0d9314:	24110006 */ 	addiu	$s1,$zero,0x6
/*  f0d9318:	10000003 */ 	b	.L0f0d9328
/*  f0d931c:	3410ff60 */ 	dli	$s0,0xff60
.L0f0d9320:
/*  f0d9320:	3c10ff00 */ 	lui	$s0,0xff00
/*  f0d9324:	36100060 */ 	ori	$s0,$s0,0x60
.L0f0d9328:
/*  f0d9328:	24030003 */ 	addiu	$v1,$zero,0x3
.L0f0d932c:
/*  f0d932c:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d9330:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0d9334:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0d9338:	02203825 */ 	or	$a3,$s1,$zero
/*  f0d933c:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0d9340:	0fc35fd5 */ 	jal	func0f0d7f54
/*  f0d9344:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d9348:	10000075 */ 	b	.L0f0d9520
/*  f0d934c:	00409825 */ 	or	$s3,$v0,$zero
/*  f0d9350:	00008025 */ 	or	$s0,$zero,$zero
/*  f0d9354:	00008825 */ 	or	$s1,$zero,$zero
/*  f0d9358:	24120001 */ 	addiu	$s2,$zero,0x1
.L0f0d935c:
/*  f0d935c:	8d480284 */ 	lw	$t0,0x284($t2)
/*  f0d9360:	01112821 */ 	addu	$a1,$t0,$s1
/*  f0d9364:	8ca31630 */ 	lw	$v1,0x1630($a1)
/*  f0d9368:	24a51630 */ 	addiu	$a1,$a1,0x1630
/*  f0d936c:	5060004c */ 	beqzl	$v1,.L0f0d94a0
/*  f0d9370:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0d9374:	91191b98 */ 	lbu	$t9,0x1b98($t0)
/*  f0d9378:	24010005 */ 	addiu	$at,$zero,0x5
/*  f0d937c:	00104840 */ 	sll	$t1,$s0,0x1
/*  f0d9380:	1721003f */ 	bne	$t9,$at,.L0f0d9480
/*  f0d9384:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d9388:	8c640004 */ 	lw	$a0,0x4($v1)
/*  f0d938c:	00003025 */ 	or	$a2,$zero,$zero
/*  f0d9390:	1080000b */ 	beqz	$a0,.L0f0d93c0
/*  f0d9394:	00801025 */ 	or	$v0,$a0,$zero
/*  f0d9398:	904b0003 */ 	lbu	$t3,0x3($v0)
/*  f0d939c:	2401000d */ 	addiu	$at,$zero,0xd
/*  f0d93a0:	15610007 */ 	bne	$t3,$at,.L0f0d93c0
/*  f0d93a4:	00000000 */ 	nop
/*  f0d93a8:	8c4c000c */ 	lw	$t4,0xc($v0)
/*  f0d93ac:	3c01a000 */ 	lui	$at,0xa000
/*  f0d93b0:	01816824 */ 	and	$t5,$t4,$at
/*  f0d93b4:	15a00002 */ 	bnez	$t5,.L0f0d93c0
/*  f0d93b8:	00000000 */ 	nop
/*  f0d93bc:	24064cd7 */ 	addiu	$a2,$zero,0x4cd7
.L0f0d93c0:
/*  f0d93c0:	10800027 */ 	beqz	$a0,.L0f0d9460
/*  f0d93c4:	00801025 */ 	or	$v0,$a0,$zero
/*  f0d93c8:	908e0003 */ 	lbu	$t6,0x3($a0)
/*  f0d93cc:	24010008 */ 	addiu	$at,$zero,0x8
/*  f0d93d0:	55c10024 */ 	bnel	$t6,$at,.L0f0d9464
/*  f0d93d4:	01096821 */ 	addu	$t5,$t0,$t1
/*  f0d93d8:	908f005c */ 	lbu	$t7,0x5c($a0)
/*  f0d93dc:	25f8fff1 */ 	addiu	$t8,$t7,-15
/*  f0d93e0:	2f010014 */ 	sltiu	$at,$t8,0x14
/*  f0d93e4:	1020001e */ 	beqz	$at,.L0f0d9460
/*  f0d93e8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0d93ec:	3c017f1b */ 	lui	$at,%hi(var7f1ade04)
/*  f0d93f0:	00380821 */ 	addu	$at,$at,$t8
/*  f0d93f4:	8c38de04 */ 	lw	$t8,%lo(var7f1ade04)($at)
/*  f0d93f8:	03000008 */ 	jr	$t8
/*  f0d93fc:	00000000 */ 	nop
/*  f0d9400:	9059005f */ 	lbu	$t9,0x5f($v0)
/*  f0d9404:	16590003 */ 	bne	$s2,$t9,.L0f0d9414
/*  f0d9408:	00000000 */ 	nop
/*  f0d940c:	10000014 */ 	b	.L0f0d9460
/*  f0d9410:	24064cd4 */ 	addiu	$a2,$zero,0x4cd4
.L0f0d9414:
/*  f0d9414:	10000012 */ 	b	.L0f0d9460
/*  f0d9418:	24064cd5 */ 	addiu	$a2,$zero,0x4cd5
/*  f0d941c:	904b005f */ 	lbu	$t3,0x5f($v0)
/*  f0d9420:	164b0003 */ 	bne	$s2,$t3,.L0f0d9430
/*  f0d9424:	00000000 */ 	nop
/*  f0d9428:	1000000d */ 	b	.L0f0d9460
/*  f0d942c:	24064cd4 */ 	addiu	$a2,$zero,0x4cd4
.L0f0d9430:
/*  f0d9430:	1000000b */ 	b	.L0f0d9460
/*  f0d9434:	24064cd8 */ 	addiu	$a2,$zero,0x4cd8
/*  f0d9438:	10000009 */ 	b	.L0f0d9460
/*  f0d943c:	24064cd5 */ 	addiu	$a2,$zero,0x4cd5
/*  f0d9440:	10000007 */ 	b	.L0f0d9460
/*  f0d9444:	24064cd4 */ 	addiu	$a2,$zero,0x4cd4
/*  f0d9448:	10000005 */ 	b	.L0f0d9460
/*  f0d944c:	24064cd6 */ 	addiu	$a2,$zero,0x4cd6
/*  f0d9450:	904c005f */ 	lbu	$t4,0x5f($v0)
/*  f0d9454:	564c0003 */ 	bnel	$s2,$t4,.L0f0d9464
/*  f0d9458:	01096821 */ 	addu	$t5,$t0,$t1
/*  f0d945c:	24064cd4 */ 	addiu	$a2,$zero,0x4cd4
.L0f0d9460:
/*  f0d9460:	01096821 */ 	addu	$t5,$t0,$t1
.L0f0d9464:
/*  f0d9464:	95a71b90 */ 	lhu	$a3,0x1b90($t5)
/*  f0d9468:	0fc35e3d */ 	jal	sightRenderTargetBox
/*  f0d946c:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d9470:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0d9474:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0d9478:	10000008 */ 	b	.L0f0d949c
/*  f0d947c:	00409825 */ 	or	$s3,$v0,$zero
.L0f0d9480:
/*  f0d9480:	01097021 */ 	addu	$t6,$t0,$t1
/*  f0d9484:	95c71b90 */ 	lhu	$a3,0x1b90($t6)
/*  f0d9488:	0fc35e3d */ 	jal	sightRenderTargetBox
/*  f0d948c:	26060002 */ 	addiu	$a2,$s0,0x2
/*  f0d9490:	3c0a800a */ 	lui	$t2,%hi(g_Vars)
/*  f0d9494:	254a9fc0 */ 	addiu	$t2,$t2,%lo(g_Vars)
/*  f0d9498:	00409825 */ 	or	$s3,$v0,$zero
.L0f0d949c:
/*  f0d949c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f0d94a0:
/*  f0d94a0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f0d94a4:	1601ffad */ 	bne	$s0,$at,.L0f0d935c
/*  f0d94a8:	2631000c */ 	addiu	$s1,$s1,0xc
/*  f0d94ac:	8faf009c */ 	lw	$t7,0x9c($sp)
/*  f0d94b0:	11e0001b */ 	beqz	$t7,.L0f0d9520
/*  f0d94b4:	00000000 */ 	nop
/*  f0d94b8:	8d580284 */ 	lw	$t8,0x284($t2)
/*  f0d94bc:	3c1000ff */ 	lui	$s0,0xff
/*  f0d94c0:	36100028 */ 	ori	$s0,$s0,0x28
/*  f0d94c4:	8f191624 */ 	lw	$t9,0x1624($t8)
/*  f0d94c8:	24110008 */ 	addiu	$s1,$zero,0x8
/*  f0d94cc:	17200003 */ 	bnez	$t9,.L0f0d94dc
/*  f0d94d0:	00000000 */ 	nop
/*  f0d94d4:	1000000a */ 	b	.L0f0d9500
/*  f0d94d8:	24030005 */ 	addiu	$v1,$zero,0x5
.L0f0d94dc:
/*  f0d94dc:	0fc35c1c */ 	jal	sightIsPropFriendly
/*  f0d94e0:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d94e4:	10400003 */ 	beqz	$v0,.L0f0d94f4
/*  f0d94e8:	24110006 */ 	addiu	$s1,$zero,0x6
/*  f0d94ec:	10000003 */ 	b	.L0f0d94fc
/*  f0d94f0:	3410ff60 */ 	dli	$s0,0xff60
.L0f0d94f4:
/*  f0d94f4:	3c10ff00 */ 	lui	$s0,0xff00
/*  f0d94f8:	36100060 */ 	ori	$s0,$s0,0x60
.L0f0d94fc:
/*  f0d94fc:	24030003 */ 	addiu	$v1,$zero,0x3
.L0f0d9500:
/*  f0d9500:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d9504:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f0d9508:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f0d950c:	02203825 */ 	or	$a3,$s1,$zero
/*  f0d9510:	afa30010 */ 	sw	$v1,0x10($sp)
/*  f0d9514:	0fc35fd5 */ 	jal	func0f0d7f54
/*  f0d9518:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d951c:	00409825 */ 	or	$s3,$v0,$zero
.L0f0d9520:
/*  f0d9520:	0fc54de0 */ 	jal	func0f153780
/*  f0d9524:	02602025 */ 	or	$a0,$s3,$zero
/*  f0d9528:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0d952c:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0d9530:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0d9534:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f0d9538:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f0d953c:	03e00008 */ 	jr	$ra
/*  f0d9540:	27bd0098 */ 	addiu	$sp,$sp,0x98
);
#endif

// Mismatch: Goal loads g_Vars.lvupdate240 differently for add to var80070f98.
//Gfx *sightRenderDefault(Gfx *gdl, bool sighton)
//{
//	s32 s1;
//	s32 sp90;
//	u32 colour;
//	s32 x = (s32)g_Vars.currentplayer->crosspos[0] / g_ScaleX; // 88
//	s32 y = g_Vars.currentplayer->crosspos[1]; // 84
//	s32 i;
//
//	gdl = func0f153628(gdl);
//
//	switch (g_Vars.currentplayer->target) {
//	case SIGHTTARGET_0: // f0d9034
//		if (sighton) {
//			gdl = func0f0d7f54(gdl, x, y, 8, 5, 0x00ff0028);
//		}
//		break;
//	case SIGHTTARGET_1: // f0d906c
//		if (sighton) {
//			// 084
//			if (g_Vars.currentplayer->lookingatprop.prop == NULL) {
//				colour = 0x00ff0028;
//				s1 = 8;
//				sp90 = 5;
//			} else {
//				// 094
//				colour = sightIsPropFriendly(NULL) ? 0x0000ff60 : 0xff000060;
//				s1 = 6;
//				sp90 = 3;
//			}
//
//			// 0b8
//			func0000db30("sight", &var80070f94);
//
//			switch (var80070f94) {
//			case 0:
//				gdl = func0f0d7f54(gdl, x, y, s1, sp90, colour);
//				break;
//			case 1:
//				gdl = func0f0d87a8(gdl, x, y, s1 * 2, sp90 * 2, colour);
//				break;
//			}
//		}
//		break;
//	case SIGHTTARGET_2: // f0d913c
//		if (sighton) {
//			s32 textx; // 78
//			s32 texty; // 74
//
//			// 154
//			if (g_Vars.currentplayer->lookingatprop.prop == NULL) {
//				colour = 0x00ff0028;
//				s1 = 8;
//				sp90 = 5;
//			} else {
//				// 164
//				colour = sightIsPropFriendly(NULL) ? 0x0000ff60 : 0xff000060;
//				s1 = 6;
//				sp90 = 3;
//			}
//
//			var80070f98 += g_Vars.lvupdate240;
//
//			textx = 135;
//			texty = 200;
//
//			if (var80070f98 & 0x80) {
//				// "Identify"
//				gdl = textRender(gdl, &textx, &texty, langGet(L_MISC_439),
//						g_FontHandelGothicXs1, g_FontHandelGothicXs2, 0x00ff00a0, 0x000000a0,
//						viGetWidth(), viGetHeight(), 0, 0);
//			}
//
//			gdl = func0f0d7f54(gdl, x, y, s1, sp90, colour);
//
//			if (g_Vars.currentplayer->lookingatprop.prop) {
//				gdl = sightRenderTargetBox(gdl, &g_Vars.currentplayer->lookingatprop, 1, g_Vars.currentplayer->targetset[0]);
//			}
//		}
//		break;
//	case SIGHTTARGET_3: // f0d9288
//		for (i = 0; i < 1; i++) {
//			if (g_Vars.currentplayer->cmpfollowprops[i].prop) {
//				gdl = sightRenderTargetBox(gdl, &g_Vars.currentplayer->cmpfollowprops[i], 0,
//						g_Vars.currentplayer->targetset[i]);
//			}
//		}
//
//		if (sighton) {
//			if (g_Vars.currentplayer->lookingatprop.prop == NULL) {
//				colour = 0x00ff0028;
//				s1 = 8;
//				sp90 = 5;
//			} else {
//				colour = sightIsPropFriendly(NULL) ? 0x0000ff60 : 0xff000060;
//				s1 = 6;
//				sp90 = 3;
//			}
//
//			gdl = func0f0d7f54(gdl, x, y, s1, sp90, colour);
//		}
//		break;
//	case SIGHTTARGET_4: // f0d9350
//	case SIGHTTARGET_5: // f0d9350
//		for (i = 0; i < 4; i++) {
//			struct threat *threat = &g_Vars.currentplayer->cmpfollowprops[i];
//			struct prop *prop = threat->prop;
//
//			// 36c
//			if (prop) {
//				// 380
//				if (g_Vars.currentplayer->target == SIGHTTARGET_5) {
//					struct defaultobj *obj = prop->obj;
//					struct weaponobj *weapon;
//					u32 textid = 0;
//
//					// @dangerous: There is no check here to see if the prop
//					// type is obj. However, it's likely that only objs can be
//					// in the cmdfollowprops list at this point, so it's
//					// probably OK.
//					if (obj && obj->type == OBJTYPE_AUTOGUN
//							&& (obj->flags2 & (OBJFLAG2_AICANNOTUSE | OBJFLAG2_80000000)) == 0) {
//						textid = L_GUN_215; // "AUTOGUN"
//					}
//
//					weapon = prop->weapon;
//
//					if (weapon && weapon->base.type == OBJTYPE_WEAPON) {
//						switch (weapon->weaponnum) {
//						case WEAPON_GRENADE:
//							if (weapon->gunfunc == FUNC_SECONDARY) {
//								textid = L_GUN_212; // "PROXY"
//							} else {
//								textid = L_GUN_213; // "TIMED"
//							}
//							break;
//						case WEAPON_NBOMB:
//							if (weapon->gunfunc == FUNC_SECONDARY) {
//								textid = L_GUN_212; // "PROXY"
//							} else {
//								textid = L_GUN_216; // "IMPACT"
//							}
//							break;
//						case WEAPON_TIMEDMINE:
//							textid = L_GUN_213; // "TIMED"
//							break;
//						case WEAPON_PROXIMITYMINE:
//							textid = L_GUN_212; // "PROXY"
//							break;
//						case WEAPON_REMOTEMINE:
//							textid = L_GUN_214; // "REMOTE"
//							break;
//						case WEAPON_DRAGON:
//							if (weapon->gunfunc == FUNC_SECONDARY) {
//								textid = L_GUN_212; // "PROXY"
//							}
//							break;
//						}
//					}
//
//					gdl = sightRenderTargetBox(gdl, &g_Vars.currentplayer->cmpfollowprops[i], textid,
//							g_Vars.currentplayer->targetset[i]);
//				} else {
//					// CMP150-tracked prop - render with index number
//					// For some reason i + 2 is passed instead of i + 1,
//					// but this is compensated for in sightRenderTargetBox.
//					gdl = sightRenderTargetBox(gdl, &g_Vars.currentplayer->cmpfollowprops[i], i + 2,
//							g_Vars.currentplayer->targetset[i]);
//				}
//			}
//		}
//
//		if (sighton) {
//			if (g_Vars.currentplayer->lookingatprop.prop == NULL) {
//				colour = 0x00ff0028;
//				s1 = 8;
//				sp90 = 5;
//			} else {
//				colour = sightIsPropFriendly(NULL) ? 0x0000ff60 : 0xff000060;
//				s1 = 6;
//				sp90 = 3;
//			}
//
//			gdl = func0f0d7f54(gdl, x, y, s1, sp90, colour);
//		}
//		break;
//	}
//
//	gdl = func0f153780(gdl);
//
//	return gdl;
//}

u32 var80070f9c = 0x00ff00ff;
u32 var80070fa0 = 0x00ff0011;

GLOBAL_ASM(
glabel sightRenderClassic
/*  f0d9544:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f0d9548:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0d954c:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0d9550:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f0d9554:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f0d9558:	afa400d0 */ 	sw	$a0,0xd0($sp)
/*  f0d955c:	c4441660 */ 	lwc1	$f4,0x1660($v0)
/*  f0d9560:	c4481664 */ 	lwc1	$f8,0x1664($v0)
/*  f0d9564:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*  f0d9568:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0d956c:	3c10800b */ 	lui	$s0,%hi(var800ab580)
/*  f0d9570:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0d9574:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0d9578:	44083000 */ 	mfc1	$t0,$f6
/*  f0d957c:	8e10b580 */ 	lw	$s0,%lo(var800ab580)($s0)
/*  f0d9580:	35ad0602 */ 	ori	$t5,$t5,0x602
/*  f0d9584:	44095000 */ 	mfc1	$t1,$f10
/*  f0d9588:	14a00003 */ 	bnez	$a1,.L0f0d9598
/*  f0d958c:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0d9590:	100000e0 */ 	b	.L0f0d9914
/*  f0d9594:	00801025 */ 	or	$v0,$a0,$zero
.L0f0d9598:
/*  f0d9598:	afb900d0 */ 	sw	$t9,0xd0($sp)
/*  f0d959c:	240e00c0 */ 	addiu	$t6,$zero,0xc0
/*  f0d95a0:	af0e0004 */ 	sw	$t6,0x4($t8)
/*  f0d95a4:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0d95a8:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*  f0d95ac:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0d95b0:	37391301 */ 	ori	$t9,$t9,0x1301
/*  f0d95b4:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0d95b8:	afb800d0 */ 	sw	$t8,0xd0($sp)
/*  f0d95bc:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f0d95c0:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0d95c4:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*  f0d95c8:	3c0fb900 */ 	lui	$t7,0xb900
/*  f0d95cc:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f0d95d0:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0d95d4:	afae00d0 */ 	sw	$t6,0xd0($sp)
/*  f0d95d8:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f0d95dc:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0d95e0:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*  f0d95e4:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0d95e8:	35ad1001 */ 	ori	$t5,$t5,0x1001
/*  f0d95ec:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0d95f0:	afb900d0 */ 	sw	$t9,0xd0($sp)
/*  f0d95f4:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0d95f8:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0d95fc:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*  f0d9600:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0d9604:	37180c02 */ 	ori	$t8,$t8,0xc02
/*  f0d9608:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0d960c:	afaf00d0 */ 	sw	$t7,0xd0($sp)
/*  f0d9610:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0d9614:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0d9618:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*  f0d961c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0d9620:	35ce0903 */ 	ori	$t6,$t6,0x903
/*  f0d9624:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0d9628:	afad00d0 */ 	sw	$t5,0xd0($sp)
/*  f0d962c:	240f0c00 */ 	addiu	$t7,$zero,0xc00
/*  f0d9630:	af2f0004 */ 	sw	$t7,0x4($t9)
/*  f0d9634:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0d9638:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*  f0d963c:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0d9640:	35ad0e02 */ 	ori	$t5,$t5,0xe02
/*  f0d9644:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0d9648:	afb900d0 */ 	sw	$t9,0xd0($sp)
/*  f0d964c:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0d9650:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0d9654:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*  f0d9658:	3c18e700 */ 	lui	$t8,0xe700
/*  f0d965c:	44888000 */ 	mtc1	$t0,$f16
/*  f0d9660:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0d9664:	afaf00d0 */ 	sw	$t7,0xd0($sp)
/*  f0d9668:	adc00004 */ 	sw	$zero,0x4($t6)
/*  f0d966c:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0d9670:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*  f0d9674:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0d9678:	35ce1402 */ 	ori	$t6,$t6,0x1402
/*  f0d967c:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0d9680:	afad00d0 */ 	sw	$t5,0xd0($sp)
/*  f0d9684:	af200004 */ 	sw	$zero,0x4($t9)
/*  f0d9688:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0d968c:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*  f0d9690:	3c19b900 */ 	lui	$t9,0xb900
/*  f0d9694:	3c0d0050 */ 	lui	$t5,0x50
/*  f0d9698:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0d969c:	afb800d0 */ 	sw	$t8,0xd0($sp)
/*  f0d96a0:	35ad4240 */ 	ori	$t5,$t5,0x4240
/*  f0d96a4:	3739031d */ 	ori	$t9,$t9,0x31d
/*  f0d96a8:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0d96ac:	aded0004 */ 	sw	$t5,0x4($t7)
/*  f0d96b0:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*  f0d96b4:	3c19fffd */ 	lui	$t9,0xfffd
/*  f0d96b8:	3c18fcff */ 	lui	$t8,0xfcff
/*  f0d96bc:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0d96c0:	afaf00d0 */ 	sw	$t7,0xd0($sp)
/*  f0d96c4:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f0d96c8:	3739f6fb */ 	ori	$t9,$t9,0xf6fb
/*  f0d96cc:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0d96d0:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0d96d4:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*  f0d96d8:	3c0ffa00 */ 	lui	$t7,0xfa00
/*  f0d96dc:	44892000 */ 	mtc1	$t1,$f4
/*  f0d96e0:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0d96e4:	afae00d0 */ 	sw	$t6,0xd0($sp)
/*  f0d96e8:	ada00004 */ 	sw	$zero,0x4($t5)
/*  f0d96ec:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0d96f0:	92040004 */ 	lbu	$a0,0x4($s0)
/*  f0d96f4:	92050005 */ 	lbu	$a1,0x5($s0)
/*  f0d96f8:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*  f0d96fc:	0004c043 */ 	sra	$t8,$a0,0x1
/*  f0d9700:	03083021 */ 	addu	$a2,$t8,$t0
/*  f0d9704:	0005c843 */ 	sra	$t9,$a1,0x1
/*  f0d9708:	01185823 */ 	subu	$t3,$t0,$t8
/*  f0d970c:	03293821 */ 	addu	$a3,$t9,$t1
/*  f0d9710:	30cf03ff */ 	andi	$t7,$a2,0x3ff
/*  f0d9714:	254e0008 */ 	addiu	$t6,$t2,0x8
/*  f0d9718:	01396023 */ 	subu	$t4,$t1,$t9
/*  f0d971c:	afae00d0 */ 	sw	$t6,0xd0($sp)
/*  f0d9720:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0d9724:	30ed03ff */ 	andi	$t5,$a3,0x3ff
/*  f0d9728:	3c01f600 */ 	lui	$at,0xf600
/*  f0d972c:	0301c825 */ 	or	$t9,$t8,$at
/*  f0d9730:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f0d9734:	032e7825 */ 	or	$t7,$t9,$t6
/*  f0d9738:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0d973c:	319903ff */ 	andi	$t9,$t4,0x3ff
/*  f0d9740:	317803ff */ 	andi	$t8,$t3,0x3ff
/*  f0d9744:	00186b80 */ 	sll	$t5,$t8,0xe
/*  f0d9748:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0d974c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0d9750:	ad4f0000 */ 	sw	$t7,0x0($t2)
/*  f0d9754:	01ae7825 */ 	or	$t7,$t5,$t6
/*  f0d9758:	ad4f0004 */ 	sw	$t7,0x4($t2)
/*  f0d975c:	e7b200c4 */ 	swc1	$f18,0xc4($sp)
/*  f0d9760:	3c0d8008 */ 	lui	$t5,%hi(g_ScaleX)
/*  f0d9764:	e7a600c8 */ 	swc1	$f6,0xc8($sp)
/*  f0d9768:	92180004 */ 	lbu	$t8,0x4($s0)
/*  f0d976c:	8dadfac0 */ 	lw	$t5,%lo(g_ScaleX)($t5)
/*  f0d9770:	00003825 */ 	or	$a3,$zero,$zero
/*  f0d9774:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0d9778:	44994000 */ 	mtc1	$t9,$f8
/*  f0d977c:	448d8000 */ 	mtc1	$t5,$f16
/*  f0d9780:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0d9784:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0d9788:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f0d978c:	02002825 */ 	or	$a1,$s0,$zero
/*  f0d9790:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f0d9794:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0d9798:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f0d979c:	e7a400bc */ 	swc1	$f4,0xbc($sp)
/*  f0d97a0:	920e0005 */ 	lbu	$t6,0x5($s0)
/*  f0d97a4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0d97a8:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f0d97ac:	000e7843 */ 	sra	$t7,$t6,0x1
/*  f0d97b0:	448f3000 */ 	mtc1	$t7,$f6
/*  f0d97b4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0d97b8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d97bc:	0fc2ce70 */ 	jal	func0f0b39c0
/*  f0d97c0:	e7a800c0 */ 	swc1	$f8,0xc0($sp)
/*  f0d97c4:	92190005 */ 	lbu	$t9,0x5($s0)
/*  f0d97c8:	92070004 */ 	lbu	$a3,0x4($s0)
/*  f0d97cc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0d97d0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f0d97d4:	2419007f */ 	addiu	$t9,$zero,0x7f
/*  f0d97d8:	240e00ff */ 	addiu	$t6,$zero,0xff
/*  f0d97dc:	240f00ff */ 	addiu	$t7,$zero,0xff
/*  f0d97e0:	241800ff */ 	addiu	$t8,$zero,0xff
/*  f0d97e4:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f0d97e8:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f0d97ec:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f0d97f0:	afb9002c */ 	sw	$t9,0x2c($sp)
/*  f0d97f4:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f0d97f8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f0d97fc:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0d9800:	920d0006 */ 	lbu	$t5,0x6($s0)
/*  f0d9804:	afa00034 */ 	sw	$zero,0x34($sp)
/*  f0d9808:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f0d980c:	000d702a */ 	slt	$t6,$zero,$t5
/*  f0d9810:	afae0030 */ 	sw	$t6,0x30($sp)
/*  f0d9814:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f0d9818:	0fc2c9e3 */ 	jal	func0f0b278c
/*  f0d981c:	27a600bc */ 	addiu	$a2,$sp,0xbc
/*  f0d9820:	8faf00d0 */ 	lw	$t7,0xd0($sp)
/*  f0d9824:	3c19e700 */ 	lui	$t9,0xe700
/*  f0d9828:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f0d982c:	afb800d0 */ 	sw	$t8,0xd0($sp)
/*  f0d9830:	ade00004 */ 	sw	$zero,0x4($t7)
/*  f0d9834:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f0d9838:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*  f0d983c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0d9840:	35ef0602 */ 	ori	$t7,$t7,0x602
/*  f0d9844:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0d9848:	afae00d0 */ 	sw	$t6,0xd0($sp)
/*  f0d984c:	24180040 */ 	addiu	$t8,$zero,0x40
/*  f0d9850:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f0d9854:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0d9858:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*  f0d985c:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0d9860:	35ce1301 */ 	ori	$t6,$t6,0x1301
/*  f0d9864:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0d9868:	afad00d0 */ 	sw	$t5,0xd0($sp)
/*  f0d986c:	3c0f0008 */ 	lui	$t7,0x8
/*  f0d9870:	af2f0004 */ 	sw	$t7,0x4($t9)
/*  f0d9874:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0d9878:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*  f0d987c:	3c0db900 */ 	lui	$t5,0xb900
/*  f0d9880:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f0d9884:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0d9888:	afb900d0 */ 	sw	$t9,0xd0($sp)
/*  f0d988c:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0d9890:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0d9894:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*  f0d9898:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0d989c:	37181001 */ 	ori	$t8,$t8,0x1001
/*  f0d98a0:	25cf0008 */ 	addiu	$t7,$t6,0x8
/*  f0d98a4:	afaf00d0 */ 	sw	$t7,0xd0($sp)
/*  f0d98a8:	3c190001 */ 	lui	$t9,0x1
/*  f0d98ac:	add90004 */ 	sw	$t9,0x4($t6)
/*  f0d98b0:	add80000 */ 	sw	$t8,0x0($t6)
/*  f0d98b4:	8fad00d0 */ 	lw	$t5,0xd0($sp)
/*  f0d98b8:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0d98bc:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f0d98c0:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0d98c4:	afae00d0 */ 	sw	$t6,0xd0($sp)
/*  f0d98c8:	24182000 */ 	addiu	$t8,$zero,0x2000
/*  f0d98cc:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f0d98d0:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0d98d4:	8fb900d0 */ 	lw	$t9,0xd0($sp)
/*  f0d98d8:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0d98dc:	35ce0903 */ 	ori	$t6,$t6,0x903
/*  f0d98e0:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f0d98e4:	afad00d0 */ 	sw	$t5,0xd0($sp)
/*  f0d98e8:	240f0c00 */ 	addiu	$t7,$zero,0xc00
/*  f0d98ec:	af2f0004 */ 	sw	$t7,0x4($t9)
/*  f0d98f0:	af2e0000 */ 	sw	$t6,0x0($t9)
/*  f0d98f4:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*  f0d98f8:	3c0dba00 */ 	lui	$t5,0xba00
/*  f0d98fc:	35ad0e02 */ 	ori	$t5,$t5,0xe02
/*  f0d9900:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0d9904:	afb900d0 */ 	sw	$t9,0xd0($sp)
/*  f0d9908:	af000004 */ 	sw	$zero,0x4($t8)
/*  f0d990c:	af0d0000 */ 	sw	$t5,0x0($t8)
/*  f0d9910:	8fa200d0 */ 	lw	$v0,0xd0($sp)
.L0f0d9914:
/*  f0d9914:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f0d9918:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f0d991c:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
/*  f0d9920:	03e00008 */ 	jr	$ra
/*  f0d9924:	00000000 */ 	nop
);

// Mismatch: Arguments for gDPFillRectangle are calculated differently
//Gfx *sightRenderClassic(Gfx *gdl, bool sighton)
//{
//	struct textureconfig *tconfig = &var800ab580[0];
//
//	s32 x = g_Vars.currentplayer->crosspos[0];
//	s32 y = g_Vars.currentplayer->crosspos[1];
//
//	f32 spc4[2];
//	f32 spbc[2];
//
//	s32 xradius;
//	s32 yradius;
//
//	if (!sighton) {
//		return gdl;
//	}
//
//	gDPSetColorDither(gdl++, G_CD_DISABLE);
//	gDPSetTexturePersp(gdl++, G_TP_NONE);
//	gDPSetAlphaCompare(gdl++, G_AC_NONE);
//	gDPSetTextureLOD(gdl++, G_TL_TILE);
//	gDPSetTextureFilter(gdl++, G_TF_POINT);
//	gDPSetTextureConvert(gdl++, G_TC_FILT);
//	gDPSetTextureLUT(gdl++, G_TT_NONE);
//	gDPPipeSync(gdl++);
//	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
//	gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
//	gDPSetPrimColor(gdl++, 0, 0, 0x00, 0x00, 0x00, 0x00);
//
//	xradius = tconfig->width >> 1;
//	yradius = tconfig->height >> 1;
//
//	gDPFillRectangle(gdl++, x - xradius, y - yradius, x + xradius, y + yradius);
//
//	spc4[0] = x;
//	spc4[1] = y;
//
//	spbc[0] = (tconfig->width >> 1) * (f32)g_ScaleX;
//	spbc[1] = tconfig->height >> 1;
//
//	func0f0b39c0(&gdl, tconfig, 2, 0, 0, 1, 0);
//
//	func0f0b278c(&gdl, spc4, spbc, tconfig->width, tconfig->height,
//			0, 0, 1, 0xff, 0xff, 0xff, 0x7f, tconfig->level > 0, 0);
//
//	gDPPipeSync(gdl++);
//	gDPSetColorDither(gdl++, G_CD_BAYER);
//	gDPSetTexturePersp(gdl++, G_TP_PERSP);
//	gDPSetAlphaCompare(gdl++, G_AC_NONE);
//	gDPSetTextureLOD(gdl++, G_TL_LOD);
//	gDPSetTextureFilter(gdl++, G_TF_BILERP);
//	gDPSetTextureConvert(gdl++, G_TC_FILT);
//	gDPSetTextureLUT(gdl++, G_TT_NONE);
//
//	return gdl;
//}

Gfx *sightRenderType2(Gfx *gdl, bool sighton)
{
	return sightRenderClassic(gdl, sighton);
}

GLOBAL_ASM(
glabel func0f0d9948
/*  f0d9948:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0d994c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0d9950:	00808825 */ 	or	$s1,$a0,$zero
/*  f0d9954:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0d9958:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0d995c:	00a08025 */ 	or	$s0,$a1,$zero
/*  f0d9960:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f0d9964:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0d9968:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f0d996c:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0d9970:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0d9974:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f0d9978:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f0d997c:	8fa7004c */ 	lw	$a3,0x4c($sp)
/*  f0d9980:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f0d9984:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f0d9988:	10e0000c */ 	beqz	$a3,.L0f0d99bc
/*  f0d998c:	00404025 */ 	or	$t0,$v0,$zero
/*  f0d9990:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0d9994:	10e10013 */ 	beq	$a3,$at,.L0f0d99e4
/*  f0d9998:	26180005 */ 	addiu	$t8,$s0,0x5
/*  f0d999c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0d99a0:	10e10019 */ 	beq	$a3,$at,.L0f0d9a08
/*  f0d99a4:	26020007 */ 	addiu	$v0,$s0,0x7
/*  f0d99a8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f0d99ac:	10e1001f */ 	beq	$a3,$at,.L0f0d9a2c
/*  f0d99b0:	2602fff9 */ 	addiu	$v0,$s0,-7
/*  f0d99b4:	10000075 */ 	b	.L0f0d9b8c
/*  f0d99b8:	02201025 */ 	or	$v0,$s1,$zero
.L0f0d99bc:
/*  f0d99bc:	260e0005 */ 	addiu	$t6,$s0,0x5
/*  f0d99c0:	24c20007 */ 	addiu	$v0,$a2,0x7
/*  f0d99c4:	260ffffb */ 	addiu	$t7,$s0,-5
/*  f0d99c8:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0d99cc:	afa6002c */ 	sw	$a2,0x2c($sp)
/*  f0d99d0:	afae0030 */ 	sw	$t6,0x30($sp)
/*  f0d99d4:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f0d99d8:	afaf0038 */ 	sw	$t7,0x38($sp)
/*  f0d99dc:	1000001e */ 	b	.L0f0d9a58
/*  f0d99e0:	afa2003c */ 	sw	$v0,0x3c($sp)
.L0f0d99e4:
/*  f0d99e4:	24c2fff9 */ 	addiu	$v0,$a2,-7
/*  f0d99e8:	2619fffb */ 	addiu	$t9,$s0,-5
/*  f0d99ec:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0d99f0:	afa6002c */ 	sw	$a2,0x2c($sp)
/*  f0d99f4:	afb80030 */ 	sw	$t8,0x30($sp)
/*  f0d99f8:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f0d99fc:	afb90038 */ 	sw	$t9,0x38($sp)
/*  f0d9a00:	10000015 */ 	b	.L0f0d9a58
/*  f0d9a04:	afa2003c */ 	sw	$v0,0x3c($sp)
.L0f0d9a08:
/*  f0d9a08:	24c9fffb */ 	addiu	$t1,$a2,-5
/*  f0d9a0c:	24ca0005 */ 	addiu	$t2,$a2,0x5
/*  f0d9a10:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0d9a14:	afa6002c */ 	sw	$a2,0x2c($sp)
/*  f0d9a18:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f0d9a1c:	afa90034 */ 	sw	$t1,0x34($sp)
/*  f0d9a20:	afa20038 */ 	sw	$v0,0x38($sp)
/*  f0d9a24:	1000000c */ 	b	.L0f0d9a58
/*  f0d9a28:	afaa003c */ 	sw	$t2,0x3c($sp)
.L0f0d9a2c:
/*  f0d9a2c:	24cbfffb */ 	addiu	$t3,$a2,-5
/*  f0d9a30:	24cc0005 */ 	addiu	$t4,$a2,0x5
/*  f0d9a34:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f0d9a38:	afa6002c */ 	sw	$a2,0x2c($sp)
/*  f0d9a3c:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f0d9a40:	afab0034 */ 	sw	$t3,0x34($sp)
/*  f0d9a44:	afa20038 */ 	sw	$v0,0x38($sp)
/*  f0d9a48:	10000003 */ 	b	.L0f0d9a58
/*  f0d9a4c:	afac003c */ 	sw	$t4,0x3c($sp)
/*  f0d9a50:	1000004e */ 	b	.L0f0d9b8c
/*  f0d9a54:	02201025 */ 	or	$v0,$s1,$zero
.L0f0d9a58:
/*  f0d9a58:	2402000a */ 	addiu	$v0,$zero,0xa
/*  f0d9a5c:	02020019 */ 	multu	$s0,$v0
/*  f0d9a60:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0d9a64:	2403fff6 */ 	addiu	$v1,$zero,-10
/*  f0d9a68:	3c01ff00 */ 	lui	$at,0xff00
/*  f0d9a6c:	342100b2 */ 	ori	$at,$at,0xb2
/*  f0d9a70:	00002025 */ 	or	$a0,$zero,$zero
/*  f0d9a74:	00006812 */ 	mflo	$t5
/*  f0d9a78:	a4ad0000 */ 	sh	$t5,0x0($a1)
/*  f0d9a7c:	8fae002c */ 	lw	$t6,0x2c($sp)
/*  f0d9a80:	a4a30004 */ 	sh	$v1,0x4($a1)
/*  f0d9a84:	01c20019 */ 	multu	$t6,$v0
/*  f0d9a88:	00007812 */ 	mflo	$t7
/*  f0d9a8c:	a4af0002 */ 	sh	$t7,0x2($a1)
/*  f0d9a90:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f0d9a94:	03020019 */ 	multu	$t8,$v0
/*  f0d9a98:	0000c812 */ 	mflo	$t9
/*  f0d9a9c:	a4b9000c */ 	sh	$t9,0xc($a1)
/*  f0d9aa0:	8fa90034 */ 	lw	$t1,0x34($sp)
/*  f0d9aa4:	a4a30010 */ 	sh	$v1,0x10($a1)
/*  f0d9aa8:	01220019 */ 	multu	$t1,$v0
/*  f0d9aac:	00005012 */ 	mflo	$t2
/*  f0d9ab0:	a4aa000e */ 	sh	$t2,0xe($a1)
/*  f0d9ab4:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f0d9ab8:	01620019 */ 	multu	$t3,$v0
/*  f0d9abc:	00006012 */ 	mflo	$t4
/*  f0d9ac0:	a4ac0018 */ 	sh	$t4,0x18($a1)
/*  f0d9ac4:	8fad003c */ 	lw	$t5,0x3c($sp)
/*  f0d9ac8:	a4a3001c */ 	sh	$v1,0x1c($a1)
/*  f0d9acc:	01a20019 */ 	multu	$t5,$v0
/*  f0d9ad0:	00007012 */ 	mflo	$t6
/*  f0d9ad4:	a4ae001a */ 	sh	$t6,0x1a($a1)
/*  f0d9ad8:	54c1000b */ 	bnel	$a2,$at,.L0f0d9b08
/*  f0d9adc:	0006ce02 */ 	srl	$t9,$a2,0x18
/*  f0d9ae0:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f0d9ae4:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f0d9ae8:	0fc35c1c */ 	jal	sightIsPropFriendly
/*  f0d9aec:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f0d9af0:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f0d9af4:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f0d9af8:	10400002 */ 	beqz	$v0,.L0f0d9b04
/*  f0d9afc:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f0d9b00:	3406ff60 */ 	dli	$a2,0xff60
.L0f0d9b04:
/*  f0d9b04:	0006ce02 */ 	srl	$t9,$a2,0x18
.L0f0d9b08:
/*  f0d9b08:	00065c02 */ 	srl	$t3,$a2,0x10
/*  f0d9b0c:	316c00ff */ 	andi	$t4,$t3,0xff
/*  f0d9b10:	00194e00 */ 	sll	$t1,$t9,0x18
/*  f0d9b14:	0006c202 */ 	srl	$t8,$a2,0x8
/*  f0d9b18:	331900ff */ 	andi	$t9,$t8,0xff
/*  f0d9b1c:	000c6c00 */ 	sll	$t5,$t4,0x10
/*  f0d9b20:	012d7025 */ 	or	$t6,$t1,$t5
/*  f0d9b24:	00195200 */ 	sll	$t2,$t9,0x8
/*  f0d9b28:	01ca5825 */ 	or	$t3,$t6,$t2
/*  f0d9b2c:	356c0008 */ 	ori	$t4,$t3,0x8
/*  f0d9b30:	ad060000 */ 	sw	$a2,0x0($t0)
/*  f0d9b34:	ad0c0004 */ 	sw	$t4,0x4($t0)
/*  f0d9b38:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f0d9b3c:	a0a00007 */ 	sb	$zero,0x7($a1)
/*  f0d9b40:	a0a70013 */ 	sb	$a3,0x13($a1)
/*  f0d9b44:	a0a7001f */ 	sb	$a3,0x1f($a1)
/*  f0d9b48:	3c090704 */ 	lui	$t1,0x704
/*  f0d9b4c:	02201025 */ 	or	$v0,$s1,$zero
/*  f0d9b50:	35290008 */ 	ori	$t1,$t1,0x8
/*  f0d9b54:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f0d9b58:	ac480004 */ 	sw	$t0,0x4($v0)
/*  f0d9b5c:	26230008 */ 	addiu	$v1,$s1,0x8
/*  f0d9b60:	3c0d0420 */ 	lui	$t5,0x420
/*  f0d9b64:	35ad0024 */ 	ori	$t5,$t5,0x24
/*  f0d9b68:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f0d9b6c:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0d9b70:	ac650004 */ 	sw	$a1,0x4($v1)
/*  f0d9b74:	3c0fb100 */ 	lui	$t7,0xb100
/*  f0d9b78:	35ef0002 */ 	ori	$t7,$t7,0x2
/*  f0d9b7c:	24180010 */ 	addiu	$t8,$zero,0x10
/*  f0d9b80:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f0d9b84:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f0d9b88:	24820008 */ 	addiu	$v0,$a0,0x8
.L0f0d9b8c:
/*  f0d9b8c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0d9b90:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0d9b94:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0d9b98:	03e00008 */ 	jr	$ra
/*  f0d9b9c:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel sightRenderSkedar
/*  f0d9ba0:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f0d9ba4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0d9ba8:	afa40090 */ 	sw	$a0,0x90($sp)
/*  f0d9bac:	0c002f40 */ 	jal	viGetViewLeft
/*  f0d9bb0:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f0d9bb4:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f0d9bb8:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f0d9bbc:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f0d9bc0:	004e001a */ 	div	$zero,$v0,$t6
/*  f0d9bc4:	00007812 */ 	mflo	$t7
/*  f0d9bc8:	afaf008c */ 	sw	$t7,0x8c($sp)
/*  f0d9bcc:	15c00002 */ 	bnez	$t6,.L0f0d9bd8
/*  f0d9bd0:	00000000 */ 	nop
/*  f0d9bd4:	0007000d */ 	break	0x7
.L0f0d9bd8:
/*  f0d9bd8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d9bdc:	15c10004 */ 	bne	$t6,$at,.L0f0d9bf0
/*  f0d9be0:	3c018000 */ 	lui	$at,0x8000
/*  f0d9be4:	14410002 */ 	bne	$v0,$at,.L0f0d9bf0
/*  f0d9be8:	00000000 */ 	nop
/*  f0d9bec:	0006000d */ 	break	0x6
.L0f0d9bf0:
/*  f0d9bf0:	0c002f44 */ 	jal	viGetViewTop
/*  f0d9bf4:	00000000 */ 	nop
/*  f0d9bf8:	0c002f22 */ 	jal	viGetViewWidth
/*  f0d9bfc:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f0d9c00:	3c188008 */ 	lui	$t8,%hi(g_ScaleX)
/*  f0d9c04:	8f18fac0 */ 	lw	$t8,%lo(g_ScaleX)($t8)
/*  f0d9c08:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f0d9c0c:	0058001a */ 	div	$zero,$v0,$t8
/*  f0d9c10:	00005812 */ 	mflo	$t3
/*  f0d9c14:	afab0084 */ 	sw	$t3,0x84($sp)
/*  f0d9c18:	17000002 */ 	bnez	$t8,.L0f0d9c24
/*  f0d9c1c:	00000000 */ 	nop
/*  f0d9c20:	0007000d */ 	break	0x7
.L0f0d9c24:
/*  f0d9c24:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d9c28:	17010004 */ 	bne	$t8,$at,.L0f0d9c3c
/*  f0d9c2c:	3c018000 */ 	lui	$at,0x8000
/*  f0d9c30:	14410002 */ 	bne	$v0,$at,.L0f0d9c3c
/*  f0d9c34:	00000000 */ 	nop
/*  f0d9c38:	0006000d */ 	break	0x6
.L0f0d9c3c:
/*  f0d9c3c:	0c002f26 */ 	jal	viGetViewHeight
/*  f0d9c40:	00000000 */ 	nop
/*  f0d9c44:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f0d9c48:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f0d9c4c:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f0d9c50:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f0d9c54:	448e3000 */ 	mtc1	$t6,$f6
/*  f0d9c58:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f0d9c5c:	c4641660 */ 	lwc1	$f4,0x1660($v1)
/*  f0d9c60:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d9c64:	03226821 */ 	addu	$t5,$t9,$v0
/*  f0d9c68:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f0d9c6c:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f0d9c70:	25adffff */ 	addiu	$t5,$t5,-1
/*  f0d9c74:	04410003 */ 	bgez	$v0,.L0f0d9c84
/*  f0d9c78:	00025083 */ 	sra	$t2,$v0,0x2
/*  f0d9c7c:	24410003 */ 	addiu	$at,$v0,0x3
/*  f0d9c80:	00015083 */ 	sra	$t2,$at,0x2
.L0f0d9c84:
/*  f0d9c84:	46082283 */ 	div.s	$f10,$f4,$f8
/*  f0d9c88:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0d9c8c:	44188000 */ 	mfc1	$t8,$f16
/*  f0d9c90:	00000000 */ 	nop
/*  f0d9c94:	afb8006c */ 	sw	$t8,0x6c($sp)
/*  f0d9c98:	c4721664 */ 	lwc1	$f18,0x1664($v1)
/*  f0d9c9c:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f0d9ca0:	4600918d */ 	trunc.w.s	$f6,$f18
/*  f0d9ca4:	440e3000 */ 	mfc1	$t6,$f6
/*  f0d9ca8:	00000000 */ 	nop
/*  f0d9cac:	afae0060 */ 	sw	$t6,0x60($sp)
/*  f0d9cb0:	8c6c1624 */ 	lw	$t4,0x1624($v1)
/*  f0d9cb4:	000c782b */ 	sltu	$t7,$zero,$t4
/*  f0d9cb8:	17000003 */ 	bnez	$t8,.L0f0d9cc8
/*  f0d9cbc:	01e06025 */ 	or	$t4,$t7,$zero
/*  f0d9cc0:	10000182 */ 	b	.L0f0da2cc
/*  f0d9cc4:	00801025 */ 	or	$v0,$a0,$zero
.L0f0d9cc8:
/*  f0d9cc8:	55800003 */ 	bnezl	$t4,.L0f0d9cd8
/*  f0d9ccc:	afaa0074 */ 	sw	$t2,0x74($sp)
/*  f0d9cd0:	ac6019a8 */ 	sw	$zero,0x19a8($v1)
/*  f0d9cd4:	afaa0074 */ 	sw	$t2,0x74($sp)
.L0f0d9cd8:
/*  f0d9cd8:	afab0084 */ 	sw	$t3,0x84($sp)
/*  f0d9cdc:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f0d9ce0:	0fc351e7 */ 	jal	func0f0d479c
/*  f0d9ce4:	afad0078 */ 	sw	$t5,0x78($sp)
/*  f0d9ce8:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f0d9cec:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0d9cf0:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f0d9cf4:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f0d9cf8:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f0d9cfc:	3c19b600 */ 	lui	$t9,0xb600
/*  f0d9d00:	240e3000 */ 	addiu	$t6,$zero,0x3000
/*  f0d9d04:	3c0fb700 */ 	lui	$t7,0xb700
/*  f0d9d08:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0d9d0c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0d9d10:	ac4f0008 */ 	sw	$t7,0x8($v0)
/*  f0d9d14:	3c19fcff */ 	lui	$t9,0xfcff
/*  f0d9d18:	3c0efffe */ 	lui	$t6,0xfffe
/*  f0d9d1c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0d9d20:	35ce793c */ 	ori	$t6,$t6,0x793c
/*  f0d9d24:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f0d9d28:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f0d9d2c:	24180204 */ 	addiu	$t8,$zero,0x204
/*  f0d9d30:	ac590010 */ 	sw	$t9,0x10($v0)
/*  f0d9d34:	ac4e0014 */ 	sw	$t6,0x14($v0)
/*  f0d9d38:	ac4f0018 */ 	sw	$t7,0x18($v0)
/*  f0d9d3c:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f0d9d40:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0d9d44:	3c0f0050 */ 	lui	$t7,0x50
/*  f0d9d48:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0d9d4c:	24182000 */ 	addiu	$t8,$zero,0x2000
/*  f0d9d50:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f0d9d54:	35ce031d */ 	ori	$t6,$t6,0x31d
/*  f0d9d58:	35ef41c8 */ 	ori	$t7,$t7,0x41c8
/*  f0d9d5c:	ac58001c */ 	sw	$t8,0x1c($v0)
/*  f0d9d60:	ac590020 */ 	sw	$t9,0x20($v0)
/*  f0d9d64:	ac400024 */ 	sw	$zero,0x24($v0)
/*  f0d9d68:	ac4f002c */ 	sw	$t7,0x2c($v0)
/*  f0d9d6c:	ac4e0028 */ 	sw	$t6,0x28($v0)
/*  f0d9d70:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0d9d74:	24440030 */ 	addiu	$a0,$v0,0x30
/*  f0d9d78:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0d9d7c:	1180000d */ 	beqz	$t4,.L0f0d9db4
/*  f0d9d80:	afb8005c */ 	sw	$t8,0x5c($sp)
/*  f0d9d84:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x284)
/*  f0d9d88:	8f39a244 */ 	lw	$t9,%lo(g_Vars+0x284)($t9)
/*  f0d9d8c:	8f2219a8 */ 	lw	$v0,0x19a8($t9)
/*  f0d9d90:	28410030 */ 	slti	$at,$v0,0x28
/*  f0d9d94:	10200007 */ 	beqz	$at,.L0f0d9db4
/*  f0d9d98:	00000000 */ 	nop
/*  f0d9d9c:	44822000 */ 	mtc1	$v0,$f4
/*  f0d9da0:	3c014240 */ 	lui	$at,0x4220
/*  f0d9da4:	44815000 */ 	mtc1	$at,$f10
/*  f0d9da8:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0d9dac:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f0d9db0:	e7b00048 */ 	swc1	$f16,0x48($sp)
.L0f0d9db4:
/*  f0d9db4:	1580001f */ 	bnez	$t4,.L0f0d9e34
/*  f0d9db8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0d9dbc:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f0d9dc0:	3c1fff55 */ 	lui	$ra,0xff55
/*  f0d9dc4:	37ff5564 */ 	ori	$ra,$ra,0x5564
/*  f0d9dc8:	03e04825 */ 	or	$t1,$ra,$zero
/*  f0d9dcc:	05610003 */ 	bgez	$t3,.L0f0d9ddc
/*  f0d9dd0:	000b1083 */ 	sra	$v0,$t3,0x2
/*  f0d9dd4:	25610003 */ 	addiu	$at,$t3,0x3
/*  f0d9dd8:	00011083 */ 	sra	$v0,$at,0x2
.L0f0d9ddc:
/*  f0d9ddc:	01c21821 */ 	addu	$v1,$t6,$v0
/*  f0d9de0:	00e3082a */ 	slt	$at,$a3,$v1
/*  f0d9de4:	10200004 */ 	beqz	$at,.L0f0d9df8
/*  f0d9de8:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f0d9dec:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f0d9df0:	1000000e */ 	b	.L0f0d9e2c
/*  f0d9df4:	00602825 */ 	or	$a1,$v1,$zero
.L0f0d9df8:
/*  f0d9df8:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f0d9dfc:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0d9e00:	01ebc021 */ 	addu	$t8,$t7,$t3
/*  f0d9e04:	03021823 */ 	subu	$v1,$t8,$v0
/*  f0d9e08:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0d9e0c:	0067082a */ 	slt	$at,$v1,$a3
/*  f0d9e10:	50200005 */ 	beqzl	$at,.L0f0d9e28
/*  f0d9e14:	3c0955ff */ 	lui	$t1,0x55ff
/*  f0d9e18:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f0d9e1c:	10000003 */ 	b	.L0f0d9e2c
/*  f0d9e20:	00602825 */ 	or	$a1,$v1,$zero
/*  f0d9e24:	3c0955ff */ 	lui	$t1,0x55ff
.L0f0d9e28:
/*  f0d9e28:	35295564 */ 	ori	$t1,$t1,0x5564
.L0f0d9e2c:
/*  f0d9e2c:	10000021 */ 	b	.L0f0d9eb4
/*  f0d9e30:	032a3021 */ 	addu	$a2,$t9,$t2
.L0f0d9e34:
/*  f0d9e34:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0d9e38:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f0d9e3c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0d9e40:	8dcf19a8 */ 	lw	$t7,0x19a8($t6)
/*  f0d9e44:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f0d9e48:	3c09ff00 */ 	lui	$t1,0xff00
/*  f0d9e4c:	29e10030 */ 	slti	$at,$t7,0x28
/*  f0d9e50:	10200016 */ 	beqz	$at,.L0f0d9eac
/*  f0d9e54:	24c6fffe */ 	addiu	$a2,$a2,-2
/*  f0d9e58:	03197023 */ 	subu	$t6,$t8,$t9
/*  f0d9e5c:	01ca7823 */ 	subu	$t7,$t6,$t2
/*  f0d9e60:	25f8fffe */ 	addiu	$t8,$t7,-2
/*  f0d9e64:	44989000 */ 	mtc1	$t8,$f18
/*  f0d9e68:	c7a40048 */ 	lwc1	$f4,0x48($sp)
/*  f0d9e6c:	44995000 */ 	mtc1	$t9,$f10
/*  f0d9e70:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f0d9e74:	3c1fff55 */ 	lui	$ra,0xff55
/*  f0d9e78:	37e95564 */ 	ori	$t1,$ra,0x5564
/*  f0d9e7c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0d9e80:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0d9e84:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0d9e88:	448a3000 */ 	mtc1	$t2,$f6
/*  f0d9e8c:	00000000 */ 	nop
/*  f0d9e90:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0d9e94:	46104480 */ 	add.s	$f18,$f8,$f16
/*  f0d9e98:	46049280 */ 	add.s	$f10,$f18,$f4
/*  f0d9e9c:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f0d9ea0:	44064000 */ 	mfc1	$a2,$f8
/*  f0d9ea4:	10000004 */ 	b	.L0f0d9eb8
/*  f0d9ea8:	01003825 */ 	or	$a3,$t0,$zero
.L0f0d9eac:
/*  f0d9eac:	352900b2 */ 	ori	$t1,$t1,0xb2
/*  f0d9eb0:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0d9eb4:
/*  f0d9eb4:	01003825 */ 	or	$a3,$t0,$zero
.L0f0d9eb8:
/*  f0d9eb8:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0d9ebc:	afa50068 */ 	sw	$a1,0x68($sp)
/*  f0d9ec0:	afa8002c */ 	sw	$t0,0x2c($sp)
/*  f0d9ec4:	afaa0074 */ 	sw	$t2,0x74($sp)
/*  f0d9ec8:	afab0084 */ 	sw	$t3,0x84($sp)
/*  f0d9ecc:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f0d9ed0:	0fc36652 */ 	jal	func0f0d9948
/*  f0d9ed4:	afad0078 */ 	sw	$t5,0x78($sp)
/*  f0d9ed8:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0d9edc:	3c1fff55 */ 	lui	$ra,0xff55
/*  f0d9ee0:	37ff5564 */ 	ori	$ra,$ra,0x5564
/*  f0d9ee4:	8fa50068 */ 	lw	$a1,0x68($sp)
/*  f0d9ee8:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f0d9eec:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f0d9ef0:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f0d9ef4:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f0d9ef8:	15800009 */ 	bnez	$t4,.L0f0d9f20
/*  f0d9efc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0d9f00:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0d9f04:	14e10004 */ 	bne	$a3,$at,.L0f0d9f18
/*  f0d9f08:	03e04825 */ 	or	$t1,$ra,$zero
/*  f0d9f0c:	3c0955ff */ 	lui	$t1,0x55ff
/*  f0d9f10:	35295564 */ 	ori	$t1,$t1,0x5564
/*  f0d9f14:	00003825 */ 	or	$a3,$zero,$zero
.L0f0d9f18:
/*  f0d9f18:	10000020 */ 	b	.L0f0d9f9c
/*  f0d9f1c:	01aa3023 */ 	subu	$a2,$t5,$t2
.L0f0d9f20:
/*  f0d9f20:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f0d9f24:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f0d9f28:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f0d9f2c:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0d9f30:	8df819a8 */ 	lw	$t8,0x19a8($t7)
/*  f0d9f34:	3c09ff00 */ 	lui	$t1,0xff00
/*  f0d9f38:	00003825 */ 	or	$a3,$zero,$zero
/*  f0d9f3c:	2b010030 */ 	slti	$at,$t8,0x28
/*  f0d9f40:	10200015 */ 	beqz	$at,.L0f0d9f98
/*  f0d9f44:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f0d9f48:	032d7023 */ 	subu	$t6,$t9,$t5
/*  f0d9f4c:	01ca7821 */ 	addu	$t7,$t6,$t2
/*  f0d9f50:	25f80002 */ 	addiu	$t8,$t7,0x2
/*  f0d9f54:	44988000 */ 	mtc1	$t8,$f16
/*  f0d9f58:	c7b20048 */ 	lwc1	$f18,0x48($sp)
/*  f0d9f5c:	448d5000 */ 	mtc1	$t5,$f10
/*  f0d9f60:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0d9f64:	03e04825 */ 	or	$t1,$ra,$zero
/*  f0d9f68:	00003825 */ 	or	$a3,$zero,$zero
/*  f0d9f6c:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0d9f70:	46123102 */ 	mul.s	$f4,$f6,$f18
/*  f0d9f74:	448a3000 */ 	mtc1	$t2,$f6
/*  f0d9f78:	00000000 */ 	nop
/*  f0d9f7c:	468034a0 */ 	cvt.s.w	$f18,$f6
/*  f0d9f80:	46082400 */ 	add.s	$f16,$f4,$f8
/*  f0d9f84:	46128281 */ 	sub.s	$f10,$f16,$f18
/*  f0d9f88:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0d9f8c:	44062000 */ 	mfc1	$a2,$f4
/*  f0d9f90:	10000003 */ 	b	.L0f0d9fa0
/*  f0d9f94:	afa90010 */ 	sw	$t1,0x10($sp)
.L0f0d9f98:
/*  f0d9f98:	352900b2 */ 	ori	$t1,$t1,0xb2
.L0f0d9f9c:
/*  f0d9f9c:	afa90010 */ 	sw	$t1,0x10($sp)
.L0f0d9fa0:
/*  f0d9fa0:	afaa0074 */ 	sw	$t2,0x74($sp)
/*  f0d9fa4:	afab0084 */ 	sw	$t3,0x84($sp)
/*  f0d9fa8:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f0d9fac:	0fc36652 */ 	jal	func0f0d9948
/*  f0d9fb0:	afad0078 */ 	sw	$t5,0x78($sp)
/*  f0d9fb4:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0d9fb8:	3c1fff55 */ 	lui	$ra,0xff55
/*  f0d9fbc:	37ff5564 */ 	ori	$ra,$ra,0x5564
/*  f0d9fc0:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f0d9fc4:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f0d9fc8:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f0d9fcc:	15800020 */ 	bnez	$t4,.L0f0da050
/*  f0d9fd0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0d9fd4:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f0d9fd8:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f0d9fdc:	03e04825 */ 	or	$t1,$ra,$zero
/*  f0d9fe0:	01ca1021 */ 	addu	$v0,$t6,$t2
/*  f0d9fe4:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f0d9fe8:	01ebc021 */ 	addu	$t8,$t7,$t3
/*  f0d9fec:	05610003 */ 	bgez	$t3,.L0f0d9ffc
/*  f0d9ff0:	000bc883 */ 	sra	$t9,$t3,0x2
/*  f0d9ff4:	25610003 */ 	addiu	$at,$t3,0x3
/*  f0d9ff8:	0001c883 */ 	sra	$t9,$at,0x2
.L0f0d9ffc:
/*  f0d9ffc:	03191823 */ 	subu	$v1,$t8,$t9
/*  f0da000:	01c2082a */ 	slt	$at,$t6,$v0
/*  f0da004:	10200005 */ 	beqz	$at,.L0f0da01c
/*  f0da008:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0da00c:	00004025 */ 	or	$t0,$zero,$zero
/*  f0da010:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f0da014:	10000033 */ 	b	.L0f0da0e4
/*  f0da018:	00602825 */ 	or	$a1,$v1,$zero
.L0f0da01c:
/*  f0da01c:	8faf0060 */ 	lw	$t7,0x60($sp)
/*  f0da020:	01aa1023 */ 	subu	$v0,$t5,$t2
/*  f0da024:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f0da028:	004f082a */ 	slt	$at,$v0,$t7
/*  f0da02c:	10200004 */ 	beqz	$at,.L0f0da040
/*  f0da030:	00602825 */ 	or	$a1,$v1,$zero
/*  f0da034:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0da038:	1000002a */ 	b	.L0f0da0e4
/*  f0da03c:	afa2005c */ 	sw	$v0,0x5c($sp)
.L0f0da040:
/*  f0da040:	3c0955ff */ 	lui	$t1,0x55ff
/*  f0da044:	35295564 */ 	ori	$t1,$t1,0x5564
/*  f0da048:	10000026 */ 	b	.L0f0da0e4
/*  f0da04c:	00602825 */ 	or	$a1,$v1,$zero
.L0f0da050:
/*  f0da050:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x284)
/*  f0da054:	8f18a244 */ 	lw	$t8,%lo(g_Vars+0x284)($t8)
/*  f0da058:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f0da05c:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f0da060:	8f1919a8 */ 	lw	$t9,0x19a8($t8)
/*  f0da064:	03e04825 */ 	or	$t1,$ra,$zero
/*  f0da068:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f0da06c:	2b210030 */ 	slti	$at,$t9,0x28
/*  f0da070:	1020001a */ 	beqz	$at,.L0f0da0dc
/*  f0da074:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0da078:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f0da07c:	01cb1821 */ 	addu	$v1,$t6,$t3
/*  f0da080:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0da084:	05610003 */ 	bgez	$t3,.L0f0da094
/*  f0da088:	000b1083 */ 	sra	$v0,$t3,0x2
/*  f0da08c:	25610003 */ 	addiu	$at,$t3,0x3
/*  f0da090:	00011083 */ 	sra	$v0,$at,0x2
.L0f0da094:
/*  f0da094:	01e3c023 */ 	subu	$t8,$t7,$v1
/*  f0da098:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f0da09c:	272e0002 */ 	addiu	$t6,$t9,0x2
/*  f0da0a0:	448e4000 */ 	mtc1	$t6,$f8
/*  f0da0a4:	c7b00048 */ 	lwc1	$f16,0x48($sp)
/*  f0da0a8:	44835000 */ 	mtc1	$v1,$f10
/*  f0da0ac:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0da0b0:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0da0b4:	46103482 */ 	mul.s	$f18,$f6,$f16
/*  f0da0b8:	44823000 */ 	mtc1	$v0,$f6
/*  f0da0bc:	00000000 */ 	nop
/*  f0da0c0:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f0da0c4:	46049200 */ 	add.s	$f8,$f18,$f4
/*  f0da0c8:	46104281 */ 	sub.s	$f10,$f8,$f16
/*  f0da0cc:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f0da0d0:	44059000 */ 	mfc1	$a1,$f18
/*  f0da0d4:	10000004 */ 	b	.L0f0da0e8
/*  f0da0d8:	8fa6005c */ 	lw	$a2,0x5c($sp)
.L0f0da0dc:
/*  f0da0dc:	3c09ff00 */ 	lui	$t1,0xff00
/*  f0da0e0:	352900b2 */ 	ori	$t1,$t1,0xb2
.L0f0da0e4:
/*  f0da0e4:	8fa6005c */ 	lw	$a2,0x5c($sp)
.L0f0da0e8:
/*  f0da0e8:	01003825 */ 	or	$a3,$t0,$zero
/*  f0da0ec:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0da0f0:	afa8002c */ 	sw	$t0,0x2c($sp)
/*  f0da0f4:	afab0084 */ 	sw	$t3,0x84($sp)
/*  f0da0f8:	0fc36652 */ 	jal	func0f0d9948
/*  f0da0fc:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f0da100:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0da104:	3c1fff55 */ 	lui	$ra,0xff55
/*  f0da108:	37ff5564 */ 	ori	$ra,$ra,0x5564
/*  f0da10c:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f0da110:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f0da114:	1580000f */ 	bnez	$t4,.L0f0da154
/*  f0da118:	00402025 */ 	or	$a0,$v0,$zero
/*  f0da11c:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f0da120:	03e04825 */ 	or	$t1,$ra,$zero
/*  f0da124:	05610003 */ 	bgez	$t3,.L0f0da134
/*  f0da128:	000bc883 */ 	sra	$t9,$t3,0x2
/*  f0da12c:	25610003 */ 	addiu	$at,$t3,0x3
/*  f0da130:	0001c883 */ 	sra	$t9,$at,0x2
.L0f0da134:
/*  f0da134:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0da138:	14e10004 */ 	bne	$a3,$at,.L0f0da14c
/*  f0da13c:	03191821 */ 	addu	$v1,$t8,$t9
/*  f0da140:	3c0955ff */ 	lui	$t1,0x55ff
/*  f0da144:	35295564 */ 	ori	$t1,$t1,0x5564
/*  f0da148:	24070003 */ 	addiu	$a3,$zero,0x3
.L0f0da14c:
/*  f0da14c:	10000026 */ 	b	.L0f0da1e8
/*  f0da150:	00602825 */ 	or	$a1,$v1,$zero
.L0f0da154:
/*  f0da154:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0da158:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0da15c:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f0da160:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f0da164:	8dcf19a8 */ 	lw	$t7,0x19a8($t6)
/*  f0da168:	3c09ff00 */ 	lui	$t1,0xff00
/*  f0da16c:	24070003 */ 	addiu	$a3,$zero,0x3
/*  f0da170:	29e10030 */ 	slti	$at,$t7,0x28
/*  f0da174:	1020001b */ 	beqz	$at,.L0f0da1e4
/*  f0da178:	24a5fffe */ 	addiu	$a1,$a1,-2
/*  f0da17c:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f0da180:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f0da184:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f0da188:	03e04825 */ 	or	$t1,$ra,$zero
/*  f0da18c:	05610003 */ 	bgez	$t3,.L0f0da19c
/*  f0da190:	000b1083 */ 	sra	$v0,$t3,0x2
/*  f0da194:	25610003 */ 	addiu	$at,$t3,0x3
/*  f0da198:	00011083 */ 	sra	$v0,$at,0x2
.L0f0da19c:
/*  f0da19c:	03197023 */ 	subu	$t6,$t8,$t9
/*  f0da1a0:	01c27823 */ 	subu	$t7,$t6,$v0
/*  f0da1a4:	25f8fffe */ 	addiu	$t8,$t7,-2
/*  f0da1a8:	44982000 */ 	mtc1	$t8,$f4
/*  f0da1ac:	44995000 */ 	mtc1	$t9,$f10
/*  f0da1b0:	24070003 */ 	addiu	$a3,$zero,0x3
/*  f0da1b4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0da1b8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f0da1bc:	46083402 */ 	mul.s	$f16,$f6,$f8
/*  f0da1c0:	44823000 */ 	mtc1	$v0,$f6
/*  f0da1c4:	00000000 */ 	nop
/*  f0da1c8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0da1cc:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0da1d0:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0da1d4:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0da1d8:	44058000 */ 	mfc1	$a1,$f16
/*  f0da1dc:	10000003 */ 	b	.L0f0da1ec
/*  f0da1e0:	8fa6005c */ 	lw	$a2,0x5c($sp)
.L0f0da1e4:
/*  f0da1e4:	352900b2 */ 	ori	$t1,$t1,0xb2
.L0f0da1e8:
/*  f0da1e8:	8fa6005c */ 	lw	$a2,0x5c($sp)
.L0f0da1ec:
/*  f0da1ec:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0da1f0:	0fc36652 */ 	jal	func0f0d9948
/*  f0da1f4:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f0da1f8:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0da1fc:	3c1fff55 */ 	lui	$ra,0xff55
/*  f0da200:	37ff5564 */ 	ori	$ra,$ra,0x5564
/*  f0da204:	11800007 */ 	beqz	$t4,.L0f0da224
/*  f0da208:	00402025 */ 	or	$a0,$v0,$zero
/*  f0da20c:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f0da210:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f0da214:	8df819a8 */ 	lw	$t8,0x19a8($t7)
/*  f0da218:	2b010030 */ 	slti	$at,$t8,0x28
/*  f0da21c:	10200029 */ 	beqz	$at,.L0f0da2c4
/*  f0da220:	00000000 */ 	nop
.L0f0da224:
/*  f0da224:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f0da228:	8fa20060 */ 	lw	$v0,0x60($sp)
/*  f0da22c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0da230:	24ae0002 */ 	addiu	$t6,$a1,0x2
/*  f0da234:	24affffe */ 	addiu	$t7,$a1,-2
/*  f0da238:	24590002 */ 	addiu	$t9,$v0,0x2
/*  f0da23c:	afb90028 */ 	sw	$t9,0x28($sp)
/*  f0da240:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0da244:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f0da248:	11800003 */ 	beqz	$t4,.L0f0da258
/*  f0da24c:	2446fffe */ 	addiu	$a2,$v0,-2
/*  f0da250:	10000003 */ 	b	.L0f0da260
/*  f0da254:	03e04825 */ 	or	$t1,$ra,$zero
.L0f0da258:
/*  f0da258:	3c0955ff */ 	lui	$t1,0x55ff
/*  f0da25c:	35295564 */ 	ori	$t1,$t1,0x5564
.L0f0da260:
/*  f0da260:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0da264:	0fc36652 */ 	jal	func0f0d9948
/*  f0da268:	afa90054 */ 	sw	$t1,0x54($sp)
/*  f0da26c:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f0da270:	00402025 */ 	or	$a0,$v0,$zero
/*  f0da274:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f0da278:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f0da27c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0da280:	0fc36652 */ 	jal	func0f0d9948
/*  f0da284:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0da288:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f0da28c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0da290:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f0da294:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f0da298:	24070003 */ 	addiu	$a3,$zero,0x3
/*  f0da29c:	0fc36652 */ 	jal	func0f0d9948
/*  f0da2a0:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0da2a4:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f0da2a8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0da2ac:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f0da2b0:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f0da2b4:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f0da2b8:	0fc36652 */ 	jal	func0f0d9948
/*  f0da2bc:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0da2c0:	00402025 */ 	or	$a0,$v0,$zero
.L0f0da2c4:
/*  f0da2c4:	0fc35272 */ 	jal	func0f0d49c8
/*  f0da2c8:	00000000 */ 	nop
.L0f0da2cc:
/*  f0da2cc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0da2d0:	27bd0090 */ 	addiu	$sp,$sp,0x90
/*  f0da2d4:	03e00008 */ 	jr	$ra
/*  f0da2d8:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel sightRenderSkedar
/*  f0d9ba0:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f0d9ba4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0d9ba8:	afa40090 */ 	sw	$a0,0x90($sp)
/*  f0d9bac:	0c002f40 */ 	jal	viGetViewLeft
/*  f0d9bb0:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f0d9bb4:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f0d9bb8:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f0d9bbc:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f0d9bc0:	004e001a */ 	div	$zero,$v0,$t6
/*  f0d9bc4:	00007812 */ 	mflo	$t7
/*  f0d9bc8:	afaf008c */ 	sw	$t7,0x8c($sp)
/*  f0d9bcc:	15c00002 */ 	bnez	$t6,.L0f0d9bd8
/*  f0d9bd0:	00000000 */ 	nop
/*  f0d9bd4:	0007000d */ 	break	0x7
.L0f0d9bd8:
/*  f0d9bd8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d9bdc:	15c10004 */ 	bne	$t6,$at,.L0f0d9bf0
/*  f0d9be0:	3c018000 */ 	lui	$at,0x8000
/*  f0d9be4:	14410002 */ 	bne	$v0,$at,.L0f0d9bf0
/*  f0d9be8:	00000000 */ 	nop
/*  f0d9bec:	0006000d */ 	break	0x6
.L0f0d9bf0:
/*  f0d9bf0:	0c002f44 */ 	jal	viGetViewTop
/*  f0d9bf4:	00000000 */ 	nop
/*  f0d9bf8:	0c002f22 */ 	jal	viGetViewWidth
/*  f0d9bfc:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f0d9c00:	3c188008 */ 	lui	$t8,%hi(g_ScaleX)
/*  f0d9c04:	8f18fac0 */ 	lw	$t8,%lo(g_ScaleX)($t8)
/*  f0d9c08:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f0d9c0c:	0058001a */ 	div	$zero,$v0,$t8
/*  f0d9c10:	00005812 */ 	mflo	$t3
/*  f0d9c14:	afab0084 */ 	sw	$t3,0x84($sp)
/*  f0d9c18:	17000002 */ 	bnez	$t8,.L0f0d9c24
/*  f0d9c1c:	00000000 */ 	nop
/*  f0d9c20:	0007000d */ 	break	0x7
.L0f0d9c24:
/*  f0d9c24:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0d9c28:	17010004 */ 	bne	$t8,$at,.L0f0d9c3c
/*  f0d9c2c:	3c018000 */ 	lui	$at,0x8000
/*  f0d9c30:	14410002 */ 	bne	$v0,$at,.L0f0d9c3c
/*  f0d9c34:	00000000 */ 	nop
/*  f0d9c38:	0006000d */ 	break	0x6
.L0f0d9c3c:
/*  f0d9c3c:	0c002f26 */ 	jal	viGetViewHeight
/*  f0d9c40:	00000000 */ 	nop
/*  f0d9c44:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f0d9c48:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f0d9c4c:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f0d9c50:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f0d9c54:	448e3000 */ 	mtc1	$t6,$f6
/*  f0d9c58:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f0d9c5c:	c4641660 */ 	lwc1	$f4,0x1660($v1)
/*  f0d9c60:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0d9c64:	03226821 */ 	addu	$t5,$t9,$v0
/*  f0d9c68:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f0d9c6c:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f0d9c70:	25adffff */ 	addiu	$t5,$t5,-1
/*  f0d9c74:	04410003 */ 	bgez	$v0,.L0f0d9c84
/*  f0d9c78:	00025083 */ 	sra	$t2,$v0,0x2
/*  f0d9c7c:	24410003 */ 	addiu	$at,$v0,0x3
/*  f0d9c80:	00015083 */ 	sra	$t2,$at,0x2
.L0f0d9c84:
/*  f0d9c84:	46082283 */ 	div.s	$f10,$f4,$f8
/*  f0d9c88:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0d9c8c:	44188000 */ 	mfc1	$t8,$f16
/*  f0d9c90:	00000000 */ 	nop
/*  f0d9c94:	afb8006c */ 	sw	$t8,0x6c($sp)
/*  f0d9c98:	c4721664 */ 	lwc1	$f18,0x1664($v1)
/*  f0d9c9c:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f0d9ca0:	4600918d */ 	trunc.w.s	$f6,$f18
/*  f0d9ca4:	440e3000 */ 	mfc1	$t6,$f6
/*  f0d9ca8:	00000000 */ 	nop
/*  f0d9cac:	afae0060 */ 	sw	$t6,0x60($sp)
/*  f0d9cb0:	8c6c1624 */ 	lw	$t4,0x1624($v1)
/*  f0d9cb4:	000c782b */ 	sltu	$t7,$zero,$t4
/*  f0d9cb8:	17000003 */ 	bnez	$t8,.L0f0d9cc8
/*  f0d9cbc:	01e06025 */ 	or	$t4,$t7,$zero
/*  f0d9cc0:	10000182 */ 	b	.L0f0da2cc
/*  f0d9cc4:	00801025 */ 	or	$v0,$a0,$zero
.L0f0d9cc8:
/*  f0d9cc8:	55800003 */ 	bnezl	$t4,.L0f0d9cd8
/*  f0d9ccc:	afaa0074 */ 	sw	$t2,0x74($sp)
/*  f0d9cd0:	ac6019a8 */ 	sw	$zero,0x19a8($v1)
/*  f0d9cd4:	afaa0074 */ 	sw	$t2,0x74($sp)
.L0f0d9cd8:
/*  f0d9cd8:	afab0084 */ 	sw	$t3,0x84($sp)
/*  f0d9cdc:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f0d9ce0:	0fc351e7 */ 	jal	func0f0d479c
/*  f0d9ce4:	afad0078 */ 	sw	$t5,0x78($sp)
/*  f0d9ce8:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f0d9cec:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0d9cf0:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f0d9cf4:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f0d9cf8:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f0d9cfc:	3c19b600 */ 	lui	$t9,0xb600
/*  f0d9d00:	240e3000 */ 	addiu	$t6,$zero,0x3000
/*  f0d9d04:	3c0fb700 */ 	lui	$t7,0xb700
/*  f0d9d08:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0d9d0c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0d9d10:	ac4f0008 */ 	sw	$t7,0x8($v0)
/*  f0d9d14:	3c19fcff */ 	lui	$t9,0xfcff
/*  f0d9d18:	3c0efffe */ 	lui	$t6,0xfffe
/*  f0d9d1c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f0d9d20:	35ce793c */ 	ori	$t6,$t6,0x793c
/*  f0d9d24:	3739ffff */ 	ori	$t9,$t9,0xffff
/*  f0d9d28:	35ef0c02 */ 	ori	$t7,$t7,0xc02
/*  f0d9d2c:	24180204 */ 	addiu	$t8,$zero,0x204
/*  f0d9d30:	ac590010 */ 	sw	$t9,0x10($v0)
/*  f0d9d34:	ac4e0014 */ 	sw	$t6,0x14($v0)
/*  f0d9d38:	ac4f0018 */ 	sw	$t7,0x18($v0)
/*  f0d9d3c:	ac58000c */ 	sw	$t8,0xc($v0)
/*  f0d9d40:	3c19ba00 */ 	lui	$t9,0xba00
/*  f0d9d44:	3c0f0050 */ 	lui	$t7,0x50
/*  f0d9d48:	3c0eb900 */ 	lui	$t6,0xb900
/*  f0d9d4c:	24182000 */ 	addiu	$t8,$zero,0x2000
/*  f0d9d50:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f0d9d54:	35ce031d */ 	ori	$t6,$t6,0x31d
/*  f0d9d58:	35ef41c8 */ 	ori	$t7,$t7,0x41c8
/*  f0d9d5c:	ac58001c */ 	sw	$t8,0x1c($v0)
/*  f0d9d60:	ac590020 */ 	sw	$t9,0x20($v0)
/*  f0d9d64:	ac400024 */ 	sw	$zero,0x24($v0)
/*  f0d9d68:	ac4f002c */ 	sw	$t7,0x2c($v0)
/*  f0d9d6c:	ac4e0028 */ 	sw	$t6,0x28($v0)
/*  f0d9d70:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0d9d74:	24440030 */ 	addiu	$a0,$v0,0x30
/*  f0d9d78:	00e02825 */ 	or	$a1,$a3,$zero
/*  f0d9d7c:	1180000d */ 	beqz	$t4,.L0f0d9db4
/*  f0d9d80:	afb8005c */ 	sw	$t8,0x5c($sp)
/*  f0d9d84:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x284)
/*  f0d9d88:	8f39a244 */ 	lw	$t9,%lo(g_Vars+0x284)($t9)
/*  f0d9d8c:	8f2219a8 */ 	lw	$v0,0x19a8($t9)
/*  f0d9d90:	28410030 */ 	slti	$at,$v0,0x30
/*  f0d9d94:	10200007 */ 	beqz	$at,.L0f0d9db4
/*  f0d9d98:	00000000 */ 	nop
/*  f0d9d9c:	44822000 */ 	mtc1	$v0,$f4
/*  f0d9da0:	3c014240 */ 	lui	$at,0x4240
/*  f0d9da4:	44815000 */ 	mtc1	$at,$f10
/*  f0d9da8:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0d9dac:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f0d9db0:	e7b00048 */ 	swc1	$f16,0x48($sp)
.L0f0d9db4:
/*  f0d9db4:	1580001f */ 	bnez	$t4,.L0f0d9e34
/*  f0d9db8:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0d9dbc:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f0d9dc0:	3c1fff55 */ 	lui	$ra,0xff55
/*  f0d9dc4:	37ff5564 */ 	ori	$ra,$ra,0x5564
/*  f0d9dc8:	03e04825 */ 	or	$t1,$ra,$zero
/*  f0d9dcc:	05610003 */ 	bgez	$t3,.L0f0d9ddc
/*  f0d9dd0:	000b1083 */ 	sra	$v0,$t3,0x2
/*  f0d9dd4:	25610003 */ 	addiu	$at,$t3,0x3
/*  f0d9dd8:	00011083 */ 	sra	$v0,$at,0x2
.L0f0d9ddc:
/*  f0d9ddc:	01c21821 */ 	addu	$v1,$t6,$v0
/*  f0d9de0:	00e3082a */ 	slt	$at,$a3,$v1
/*  f0d9de4:	10200004 */ 	beqz	$at,.L0f0d9df8
/*  f0d9de8:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f0d9dec:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f0d9df0:	1000000e */ 	b	.L0f0d9e2c
/*  f0d9df4:	00602825 */ 	or	$a1,$v1,$zero
.L0f0d9df8:
/*  f0d9df8:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f0d9dfc:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0d9e00:	01ebc021 */ 	addu	$t8,$t7,$t3
/*  f0d9e04:	03021823 */ 	subu	$v1,$t8,$v0
/*  f0d9e08:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0d9e0c:	0067082a */ 	slt	$at,$v1,$a3
/*  f0d9e10:	50200005 */ 	beqzl	$at,.L0f0d9e28
/*  f0d9e14:	3c0955ff */ 	lui	$t1,0x55ff
/*  f0d9e18:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f0d9e1c:	10000003 */ 	b	.L0f0d9e2c
/*  f0d9e20:	00602825 */ 	or	$a1,$v1,$zero
/*  f0d9e24:	3c0955ff */ 	lui	$t1,0x55ff
.L0f0d9e28:
/*  f0d9e28:	35295564 */ 	ori	$t1,$t1,0x5564
.L0f0d9e2c:
/*  f0d9e2c:	10000021 */ 	b	.L0f0d9eb4
/*  f0d9e30:	032a3021 */ 	addu	$a2,$t9,$t2
.L0f0d9e34:
/*  f0d9e34:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0d9e38:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f0d9e3c:	8fb80060 */ 	lw	$t8,0x60($sp)
/*  f0d9e40:	8dcf19a8 */ 	lw	$t7,0x19a8($t6)
/*  f0d9e44:	8fb90088 */ 	lw	$t9,0x88($sp)
/*  f0d9e48:	3c09ff00 */ 	lui	$t1,0xff00
/*  f0d9e4c:	29e10030 */ 	slti	$at,$t7,0x30
/*  f0d9e50:	10200016 */ 	beqz	$at,.L0f0d9eac
/*  f0d9e54:	24c6fffe */ 	addiu	$a2,$a2,-2
/*  f0d9e58:	03197023 */ 	subu	$t6,$t8,$t9
/*  f0d9e5c:	01ca7823 */ 	subu	$t7,$t6,$t2
/*  f0d9e60:	25f8fffe */ 	addiu	$t8,$t7,-2
/*  f0d9e64:	44989000 */ 	mtc1	$t8,$f18
/*  f0d9e68:	c7a40048 */ 	lwc1	$f4,0x48($sp)
/*  f0d9e6c:	44995000 */ 	mtc1	$t9,$f10
/*  f0d9e70:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f0d9e74:	3c1fff55 */ 	lui	$ra,0xff55
/*  f0d9e78:	37e95564 */ 	ori	$t1,$ra,0x5564
/*  f0d9e7c:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0d9e80:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0d9e84:	46043202 */ 	mul.s	$f8,$f6,$f4
/*  f0d9e88:	448a3000 */ 	mtc1	$t2,$f6
/*  f0d9e8c:	00000000 */ 	nop
/*  f0d9e90:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0d9e94:	46104480 */ 	add.s	$f18,$f8,$f16
/*  f0d9e98:	46049280 */ 	add.s	$f10,$f18,$f4
/*  f0d9e9c:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f0d9ea0:	44064000 */ 	mfc1	$a2,$f8
/*  f0d9ea4:	10000004 */ 	b	.L0f0d9eb8
/*  f0d9ea8:	01003825 */ 	or	$a3,$t0,$zero
.L0f0d9eac:
/*  f0d9eac:	352900b2 */ 	ori	$t1,$t1,0xb2
/*  f0d9eb0:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f0d9eb4:
/*  f0d9eb4:	01003825 */ 	or	$a3,$t0,$zero
.L0f0d9eb8:
/*  f0d9eb8:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0d9ebc:	afa50068 */ 	sw	$a1,0x68($sp)
/*  f0d9ec0:	afa8002c */ 	sw	$t0,0x2c($sp)
/*  f0d9ec4:	afaa0074 */ 	sw	$t2,0x74($sp)
/*  f0d9ec8:	afab0084 */ 	sw	$t3,0x84($sp)
/*  f0d9ecc:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f0d9ed0:	0fc36652 */ 	jal	func0f0d9948
/*  f0d9ed4:	afad0078 */ 	sw	$t5,0x78($sp)
/*  f0d9ed8:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0d9edc:	3c1fff55 */ 	lui	$ra,0xff55
/*  f0d9ee0:	37ff5564 */ 	ori	$ra,$ra,0x5564
/*  f0d9ee4:	8fa50068 */ 	lw	$a1,0x68($sp)
/*  f0d9ee8:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f0d9eec:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f0d9ef0:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f0d9ef4:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f0d9ef8:	15800009 */ 	bnez	$t4,.L0f0d9f20
/*  f0d9efc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0d9f00:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0d9f04:	14e10004 */ 	bne	$a3,$at,.L0f0d9f18
/*  f0d9f08:	03e04825 */ 	or	$t1,$ra,$zero
/*  f0d9f0c:	3c0955ff */ 	lui	$t1,0x55ff
/*  f0d9f10:	35295564 */ 	ori	$t1,$t1,0x5564
/*  f0d9f14:	00003825 */ 	or	$a3,$zero,$zero
.L0f0d9f18:
/*  f0d9f18:	10000020 */ 	b	.L0f0d9f9c
/*  f0d9f1c:	01aa3023 */ 	subu	$a2,$t5,$t2
.L0f0d9f20:
/*  f0d9f20:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f0d9f24:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f0d9f28:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f0d9f2c:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f0d9f30:	8df819a8 */ 	lw	$t8,0x19a8($t7)
/*  f0d9f34:	3c09ff00 */ 	lui	$t1,0xff00
/*  f0d9f38:	00003825 */ 	or	$a3,$zero,$zero
/*  f0d9f3c:	2b010030 */ 	slti	$at,$t8,0x30
/*  f0d9f40:	10200015 */ 	beqz	$at,.L0f0d9f98
/*  f0d9f44:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f0d9f48:	032d7023 */ 	subu	$t6,$t9,$t5
/*  f0d9f4c:	01ca7821 */ 	addu	$t7,$t6,$t2
/*  f0d9f50:	25f80002 */ 	addiu	$t8,$t7,0x2
/*  f0d9f54:	44988000 */ 	mtc1	$t8,$f16
/*  f0d9f58:	c7b20048 */ 	lwc1	$f18,0x48($sp)
/*  f0d9f5c:	448d5000 */ 	mtc1	$t5,$f10
/*  f0d9f60:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0d9f64:	03e04825 */ 	or	$t1,$ra,$zero
/*  f0d9f68:	00003825 */ 	or	$a3,$zero,$zero
/*  f0d9f6c:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0d9f70:	46123102 */ 	mul.s	$f4,$f6,$f18
/*  f0d9f74:	448a3000 */ 	mtc1	$t2,$f6
/*  f0d9f78:	00000000 */ 	nop
/*  f0d9f7c:	468034a0 */ 	cvt.s.w	$f18,$f6
/*  f0d9f80:	46082400 */ 	add.s	$f16,$f4,$f8
/*  f0d9f84:	46128281 */ 	sub.s	$f10,$f16,$f18
/*  f0d9f88:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0d9f8c:	44062000 */ 	mfc1	$a2,$f4
/*  f0d9f90:	10000003 */ 	b	.L0f0d9fa0
/*  f0d9f94:	afa90010 */ 	sw	$t1,0x10($sp)
.L0f0d9f98:
/*  f0d9f98:	352900b2 */ 	ori	$t1,$t1,0xb2
.L0f0d9f9c:
/*  f0d9f9c:	afa90010 */ 	sw	$t1,0x10($sp)
.L0f0d9fa0:
/*  f0d9fa0:	afaa0074 */ 	sw	$t2,0x74($sp)
/*  f0d9fa4:	afab0084 */ 	sw	$t3,0x84($sp)
/*  f0d9fa8:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f0d9fac:	0fc36652 */ 	jal	func0f0d9948
/*  f0d9fb0:	afad0078 */ 	sw	$t5,0x78($sp)
/*  f0d9fb4:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0d9fb8:	3c1fff55 */ 	lui	$ra,0xff55
/*  f0d9fbc:	37ff5564 */ 	ori	$ra,$ra,0x5564
/*  f0d9fc0:	8faa0074 */ 	lw	$t2,0x74($sp)
/*  f0d9fc4:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f0d9fc8:	8fad0078 */ 	lw	$t5,0x78($sp)
/*  f0d9fcc:	15800020 */ 	bnez	$t4,.L0f0da050
/*  f0d9fd0:	00402025 */ 	or	$a0,$v0,$zero
/*  f0d9fd4:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f0d9fd8:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f0d9fdc:	03e04825 */ 	or	$t1,$ra,$zero
/*  f0d9fe0:	01ca1021 */ 	addu	$v0,$t6,$t2
/*  f0d9fe4:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f0d9fe8:	01ebc021 */ 	addu	$t8,$t7,$t3
/*  f0d9fec:	05610003 */ 	bgez	$t3,.L0f0d9ffc
/*  f0d9ff0:	000bc883 */ 	sra	$t9,$t3,0x2
/*  f0d9ff4:	25610003 */ 	addiu	$at,$t3,0x3
/*  f0d9ff8:	0001c883 */ 	sra	$t9,$at,0x2
.L0f0d9ffc:
/*  f0d9ffc:	03191823 */ 	subu	$v1,$t8,$t9
/*  f0da000:	01c2082a */ 	slt	$at,$t6,$v0
/*  f0da004:	10200005 */ 	beqz	$at,.L0f0da01c
/*  f0da008:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0da00c:	00004025 */ 	or	$t0,$zero,$zero
/*  f0da010:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f0da014:	10000033 */ 	b	.L0f0da0e4
/*  f0da018:	00602825 */ 	or	$a1,$v1,$zero
.L0f0da01c:
/*  f0da01c:	8faf0060 */ 	lw	$t7,0x60($sp)
/*  f0da020:	01aa1023 */ 	subu	$v0,$t5,$t2
/*  f0da024:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f0da028:	004f082a */ 	slt	$at,$v0,$t7
/*  f0da02c:	10200004 */ 	beqz	$at,.L0f0da040
/*  f0da030:	00602825 */ 	or	$a1,$v1,$zero
/*  f0da034:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f0da038:	1000002a */ 	b	.L0f0da0e4
/*  f0da03c:	afa2005c */ 	sw	$v0,0x5c($sp)
.L0f0da040:
/*  f0da040:	3c0955ff */ 	lui	$t1,0x55ff
/*  f0da044:	35295564 */ 	ori	$t1,$t1,0x5564
/*  f0da048:	10000026 */ 	b	.L0f0da0e4
/*  f0da04c:	00602825 */ 	or	$a1,$v1,$zero
.L0f0da050:
/*  f0da050:	3c18800a */ 	lui	$t8,%hi(g_Vars+0x284)
/*  f0da054:	8f18a244 */ 	lw	$t8,%lo(g_Vars+0x284)($t8)
/*  f0da058:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f0da05c:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f0da060:	8f1919a8 */ 	lw	$t9,0x19a8($t8)
/*  f0da064:	03e04825 */ 	or	$t1,$ra,$zero
/*  f0da068:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f0da06c:	2b210030 */ 	slti	$at,$t9,0x30
/*  f0da070:	1020001a */ 	beqz	$at,.L0f0da0dc
/*  f0da074:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f0da078:	8faf006c */ 	lw	$t7,0x6c($sp)
/*  f0da07c:	01cb1821 */ 	addu	$v1,$t6,$t3
/*  f0da080:	2463ffff */ 	addiu	$v1,$v1,-1
/*  f0da084:	05610003 */ 	bgez	$t3,.L0f0da094
/*  f0da088:	000b1083 */ 	sra	$v0,$t3,0x2
/*  f0da08c:	25610003 */ 	addiu	$at,$t3,0x3
/*  f0da090:	00011083 */ 	sra	$v0,$at,0x2
.L0f0da094:
/*  f0da094:	01e3c023 */ 	subu	$t8,$t7,$v1
/*  f0da098:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f0da09c:	272e0002 */ 	addiu	$t6,$t9,0x2
/*  f0da0a0:	448e4000 */ 	mtc1	$t6,$f8
/*  f0da0a4:	c7b00048 */ 	lwc1	$f16,0x48($sp)
/*  f0da0a8:	44835000 */ 	mtc1	$v1,$f10
/*  f0da0ac:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0da0b0:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0da0b4:	46103482 */ 	mul.s	$f18,$f6,$f16
/*  f0da0b8:	44823000 */ 	mtc1	$v0,$f6
/*  f0da0bc:	00000000 */ 	nop
/*  f0da0c0:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f0da0c4:	46049200 */ 	add.s	$f8,$f18,$f4
/*  f0da0c8:	46104281 */ 	sub.s	$f10,$f8,$f16
/*  f0da0cc:	4600548d */ 	trunc.w.s	$f18,$f10
/*  f0da0d0:	44059000 */ 	mfc1	$a1,$f18
/*  f0da0d4:	10000004 */ 	b	.L0f0da0e8
/*  f0da0d8:	8fa6005c */ 	lw	$a2,0x5c($sp)
.L0f0da0dc:
/*  f0da0dc:	3c09ff00 */ 	lui	$t1,0xff00
/*  f0da0e0:	352900b2 */ 	ori	$t1,$t1,0xb2
.L0f0da0e4:
/*  f0da0e4:	8fa6005c */ 	lw	$a2,0x5c($sp)
.L0f0da0e8:
/*  f0da0e8:	01003825 */ 	or	$a3,$t0,$zero
/*  f0da0ec:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0da0f0:	afa8002c */ 	sw	$t0,0x2c($sp)
/*  f0da0f4:	afab0084 */ 	sw	$t3,0x84($sp)
/*  f0da0f8:	0fc36652 */ 	jal	func0f0d9948
/*  f0da0fc:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f0da100:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0da104:	3c1fff55 */ 	lui	$ra,0xff55
/*  f0da108:	37ff5564 */ 	ori	$ra,$ra,0x5564
/*  f0da10c:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f0da110:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f0da114:	1580000f */ 	bnez	$t4,.L0f0da154
/*  f0da118:	00402025 */ 	or	$a0,$v0,$zero
/*  f0da11c:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f0da120:	03e04825 */ 	or	$t1,$ra,$zero
/*  f0da124:	05610003 */ 	bgez	$t3,.L0f0da134
/*  f0da128:	000bc883 */ 	sra	$t9,$t3,0x2
/*  f0da12c:	25610003 */ 	addiu	$at,$t3,0x3
/*  f0da130:	0001c883 */ 	sra	$t9,$at,0x2
.L0f0da134:
/*  f0da134:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0da138:	14e10004 */ 	bne	$a3,$at,.L0f0da14c
/*  f0da13c:	03191821 */ 	addu	$v1,$t8,$t9
/*  f0da140:	3c0955ff */ 	lui	$t1,0x55ff
/*  f0da144:	35295564 */ 	ori	$t1,$t1,0x5564
/*  f0da148:	24070003 */ 	addiu	$a3,$zero,0x3
.L0f0da14c:
/*  f0da14c:	10000026 */ 	b	.L0f0da1e8
/*  f0da150:	00602825 */ 	or	$a1,$v1,$zero
.L0f0da154:
/*  f0da154:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x284)
/*  f0da158:	8dcea244 */ 	lw	$t6,%lo(g_Vars+0x284)($t6)
/*  f0da15c:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f0da160:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f0da164:	8dcf19a8 */ 	lw	$t7,0x19a8($t6)
/*  f0da168:	3c09ff00 */ 	lui	$t1,0xff00
/*  f0da16c:	24070003 */ 	addiu	$a3,$zero,0x3
/*  f0da170:	29e10030 */ 	slti	$at,$t7,0x30
/*  f0da174:	1020001b */ 	beqz	$at,.L0f0da1e4
/*  f0da178:	24a5fffe */ 	addiu	$a1,$a1,-2
/*  f0da17c:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f0da180:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f0da184:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f0da188:	03e04825 */ 	or	$t1,$ra,$zero
/*  f0da18c:	05610003 */ 	bgez	$t3,.L0f0da19c
/*  f0da190:	000b1083 */ 	sra	$v0,$t3,0x2
/*  f0da194:	25610003 */ 	addiu	$at,$t3,0x3
/*  f0da198:	00011083 */ 	sra	$v0,$at,0x2
.L0f0da19c:
/*  f0da19c:	03197023 */ 	subu	$t6,$t8,$t9
/*  f0da1a0:	01c27823 */ 	subu	$t7,$t6,$v0
/*  f0da1a4:	25f8fffe */ 	addiu	$t8,$t7,-2
/*  f0da1a8:	44982000 */ 	mtc1	$t8,$f4
/*  f0da1ac:	44995000 */ 	mtc1	$t9,$f10
/*  f0da1b0:	24070003 */ 	addiu	$a3,$zero,0x3
/*  f0da1b4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0da1b8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f0da1bc:	46083402 */ 	mul.s	$f16,$f6,$f8
/*  f0da1c0:	44823000 */ 	mtc1	$v0,$f6
/*  f0da1c4:	00000000 */ 	nop
/*  f0da1c8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0da1cc:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f0da1d0:	46082280 */ 	add.s	$f10,$f4,$f8
/*  f0da1d4:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f0da1d8:	44058000 */ 	mfc1	$a1,$f16
/*  f0da1dc:	10000003 */ 	b	.L0f0da1ec
/*  f0da1e0:	8fa6005c */ 	lw	$a2,0x5c($sp)
.L0f0da1e4:
/*  f0da1e4:	352900b2 */ 	ori	$t1,$t1,0xb2
.L0f0da1e8:
/*  f0da1e8:	8fa6005c */ 	lw	$a2,0x5c($sp)
.L0f0da1ec:
/*  f0da1ec:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0da1f0:	0fc36652 */ 	jal	func0f0d9948
/*  f0da1f4:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f0da1f8:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f0da1fc:	3c1fff55 */ 	lui	$ra,0xff55
/*  f0da200:	37ff5564 */ 	ori	$ra,$ra,0x5564
/*  f0da204:	11800007 */ 	beqz	$t4,.L0f0da224
/*  f0da208:	00402025 */ 	or	$a0,$v0,$zero
/*  f0da20c:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f0da210:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f0da214:	8df819a8 */ 	lw	$t8,0x19a8($t7)
/*  f0da218:	2b010030 */ 	slti	$at,$t8,0x30
/*  f0da21c:	10200029 */ 	beqz	$at,.L0f0da2c4
/*  f0da220:	00000000 */ 	nop
.L0f0da224:
/*  f0da224:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f0da228:	8fa20060 */ 	lw	$v0,0x60($sp)
/*  f0da22c:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0da230:	24ae0002 */ 	addiu	$t6,$a1,0x2
/*  f0da234:	24affffe */ 	addiu	$t7,$a1,-2
/*  f0da238:	24590002 */ 	addiu	$t9,$v0,0x2
/*  f0da23c:	afb90028 */ 	sw	$t9,0x28($sp)
/*  f0da240:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f0da244:	afae0024 */ 	sw	$t6,0x24($sp)
/*  f0da248:	11800003 */ 	beqz	$t4,.L0f0da258
/*  f0da24c:	2446fffe */ 	addiu	$a2,$v0,-2
/*  f0da250:	10000003 */ 	b	.L0f0da260
/*  f0da254:	03e04825 */ 	or	$t1,$ra,$zero
.L0f0da258:
/*  f0da258:	3c0955ff */ 	lui	$t1,0x55ff
/*  f0da25c:	35295564 */ 	ori	$t1,$t1,0x5564
.L0f0da260:
/*  f0da260:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0da264:	0fc36652 */ 	jal	func0f0d9948
/*  f0da268:	afa90054 */ 	sw	$t1,0x54($sp)
/*  f0da26c:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f0da270:	00402025 */ 	or	$a0,$v0,$zero
/*  f0da274:	8fa5006c */ 	lw	$a1,0x6c($sp)
/*  f0da278:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f0da27c:	00003825 */ 	or	$a3,$zero,$zero
/*  f0da280:	0fc36652 */ 	jal	func0f0d9948
/*  f0da284:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0da288:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f0da28c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0da290:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f0da294:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f0da298:	24070003 */ 	addiu	$a3,$zero,0x3
/*  f0da29c:	0fc36652 */ 	jal	func0f0d9948
/*  f0da2a0:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0da2a4:	8fa90054 */ 	lw	$t1,0x54($sp)
/*  f0da2a8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0da2ac:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f0da2b0:	8fa60060 */ 	lw	$a2,0x60($sp)
/*  f0da2b4:	24070002 */ 	addiu	$a3,$zero,0x2
/*  f0da2b8:	0fc36652 */ 	jal	func0f0d9948
/*  f0da2bc:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0da2c0:	00402025 */ 	or	$a0,$v0,$zero
.L0f0da2c4:
/*  f0da2c4:	0fc35272 */ 	jal	func0f0d49c8
/*  f0da2c8:	00000000 */ 	nop
.L0f0da2cc:
/*  f0da2cc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0da2d0:	27bd0090 */ 	addiu	$sp,$sp,0x90
/*  f0da2d4:	03e00008 */ 	jr	$ra
/*  f0da2d8:	00000000 */ 	nop
);
#endif

GLOBAL_ASM(
glabel sightRenderZoom
.late_rodata
glabel var7f1ade54
.word 0x3e4ccccd
.text
/*  f0da2dc:	27bdff00 */ 	addiu	$sp,$sp,-256
/*  f0da2e0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0da2e4:	afa50104 */ 	sw	$a1,0x104($sp)
/*  f0da2e8:	0c002f40 */ 	jal	viGetViewLeft
/*  f0da2ec:	afa40100 */ 	sw	$a0,0x100($sp)
/*  f0da2f0:	3c088008 */ 	lui	$t0,%hi(g_ScaleX)
/*  f0da2f4:	2508fac0 */ 	addiu	$t0,$t0,%lo(g_ScaleX)
/*  f0da2f8:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0da2fc:	8fa60100 */ 	lw	$a2,0x100($sp)
/*  f0da300:	004e001a */ 	div	$zero,$v0,$t6
/*  f0da304:	00007812 */ 	mflo	$t7
/*  f0da308:	afaf00fc */ 	sw	$t7,0xfc($sp)
/*  f0da30c:	15c00002 */ 	bnez	$t6,.L0f0da318
/*  f0da310:	00000000 */ 	nop
/*  f0da314:	0007000d */ 	break	0x7
.L0f0da318:
/*  f0da318:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0da31c:	15c10004 */ 	bne	$t6,$at,.L0f0da330
/*  f0da320:	3c018000 */ 	lui	$at,0x8000
/*  f0da324:	14410002 */ 	bne	$v0,$at,.L0f0da330
/*  f0da328:	00000000 */ 	nop
/*  f0da32c:	0006000d */ 	break	0x6
.L0f0da330:
/*  f0da330:	0c002f44 */ 	jal	viGetViewTop
/*  f0da334:	00000000 */ 	nop
/*  f0da338:	0c002f22 */ 	jal	viGetViewWidth
/*  f0da33c:	afa200f8 */ 	sw	$v0,0xf8($sp)
/*  f0da340:	3c088008 */ 	lui	$t0,%hi(g_ScaleX)
/*  f0da344:	2508fac0 */ 	addiu	$t0,$t0,%lo(g_ScaleX)
/*  f0da348:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f0da34c:	8fa60100 */ 	lw	$a2,0x100($sp)
/*  f0da350:	0058001a */ 	div	$zero,$v0,$t8
/*  f0da354:	0000c812 */ 	mflo	$t9
/*  f0da358:	00197043 */ 	sra	$t6,$t9,0x1
/*  f0da35c:	17000002 */ 	bnez	$t8,.L0f0da368
/*  f0da360:	00000000 */ 	nop
/*  f0da364:	0007000d */ 	break	0x7
.L0f0da368:
/*  f0da368:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0da36c:	17010004 */ 	bne	$t8,$at,.L0f0da380
/*  f0da370:	3c018000 */ 	lui	$at,0x8000
/*  f0da374:	14410002 */ 	bne	$v0,$at,.L0f0da380
/*  f0da378:	00000000 */ 	nop
/*  f0da37c:	0006000d */ 	break	0x6
.L0f0da380:
/*  f0da380:	afae00f4 */ 	sw	$t6,0xf4($sp)
/*  f0da384:	0c002f26 */ 	jal	viGetViewHeight
/*  f0da388:	00000000 */ 	nop
/*  f0da38c:	8fb800f8 */ 	lw	$t8,0xf8($sp)
/*  f0da390:	00021843 */ 	sra	$v1,$v0,0x1
/*  f0da394:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0da398:	00037840 */ 	sll	$t7,$v1,0x1
/*  f0da39c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0da3a0:	44812000 */ 	mtc1	$at,$f4
/*  f0da3a4:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0da3a8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0da3ac:	8cef0284 */ 	lw	$t7,0x284($a3)
/*  f0da3b0:	2465fff6 */ 	addiu	$a1,$v1,-10
/*  f0da3b4:	272effff */ 	addiu	$t6,$t9,-1
/*  f0da3b8:	afa300f0 */ 	sw	$v1,0xf0($sp)
/*  f0da3bc:	afae00e8 */ 	sw	$t6,0xe8($sp)
/*  f0da3c0:	afa500e0 */ 	sw	$a1,0xe0($sp)
/*  f0da3c4:	afa500dc */ 	sw	$a1,0xdc($sp)
/*  f0da3c8:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f0da3cc:	91f80638 */ 	lbu	$t8,0x638($t7)
/*  f0da3d0:	8cf90288 */ 	lw	$t9,0x288($a3)
/*  f0da3d4:	00036843 */ 	sra	$t5,$v1,0x1
/*  f0da3d8:	afb800b0 */ 	sw	$t8,0xb0($sp)
/*  f0da3dc:	25adffea */ 	addiu	$t5,$t5,-22
/*  f0da3e0:	8f240070 */ 	lw	$a0,0x70($t9)
/*  f0da3e4:	0fc54a28 */ 	jal	optionsGetShowZoomRange
/*  f0da3e8:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f0da3ec:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f0da3f0:	8fa60100 */ 	lw	$a2,0x100($sp)
/*  f0da3f4:	1080000a */ 	beqz	$a0,.L0f0da420
/*  f0da3f8:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f0da3fc:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x288)
/*  f0da400:	8dcea248 */ 	lw	$t6,%lo(g_Vars+0x288)($t6)
/*  f0da404:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0da408:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f0da40c:	0fc54a04 */ 	jal	optionsGetSightOnScreen
/*  f0da410:	afa60100 */ 	sw	$a2,0x100($sp)
/*  f0da414:	8fa60100 */ 	lw	$a2,0x100($sp)
/*  f0da418:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f0da41c:	0002202b */ 	sltu	$a0,$zero,$v0
.L0f0da420:
/*  f0da420:	a3a400af */ 	sb	$a0,0xaf($sp)
/*  f0da424:	afa60100 */ 	sw	$a2,0x100($sp)
/*  f0da428:	0fc2c536 */ 	jal	currentPlayerGetGunZoomFov
/*  f0da42c:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f0da430:	44803000 */ 	mtc1	$zero,$f6
/*  f0da434:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f0da438:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f0da43c:	46060032 */ 	c.eq.s	$f0,$f6
/*  f0da440:	93a200af */ 	lbu	$v0,0xaf($sp)
/*  f0da444:	8fa60100 */ 	lw	$a2,0x100($sp)
/*  f0da448:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f0da44c:	45010008 */ 	bc1t	.L0f0da470
/*  f0da450:	c5e21848 */ 	lwc1	$f2,0x1848($t7)
/*  f0da454:	3c014270 */ 	lui	$at,0x4270
/*  f0da458:	44814000 */ 	mtc1	$at,$f8
/*  f0da45c:	00000000 */ 	nop
/*  f0da460:	46080032 */ 	c.eq.s	$f0,$f8
/*  f0da464:	00000000 */ 	nop
/*  f0da468:	45020008 */ 	bc1fl	.L0f0da48c
/*  f0da46c:	46020283 */ 	div.s	$f10,$f0,$f2
.L0f0da470:
/*  f0da470:	8fb800b0 */ 	lw	$t8,0xb0($sp)
/*  f0da474:	24010015 */ 	addiu	$at,$zero,0x15
/*  f0da478:	13010005 */ 	beq	$t8,$at,.L0f0da490
/*  f0da47c:	00000000 */ 	nop
/*  f0da480:	10000003 */ 	b	.L0f0da490
/*  f0da484:	00001025 */ 	or	$v0,$zero,$zero
/*  f0da488:	46020283 */ 	div.s	$f10,$f0,$f2
.L0f0da48c:
/*  f0da48c:	e7aa00cc */ 	swc1	$f10,0xcc($sp)
.L0f0da490:
/*  f0da490:	10400730 */ 	beqz	$v0,.L0f0dc154
/*  f0da494:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0da498:	0fc54d8a */ 	jal	func0f153628
/*  f0da49c:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f0da4a0:	3c0500ff */ 	lui	$a1,0xff
/*  f0da4a4:	34a50028 */ 	ori	$a1,$a1,0x28
/*  f0da4a8:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0da4ac:	00402025 */ 	or	$a0,$v0,$zero
/*  f0da4b0:	3c017f1b */ 	lui	$at,%hi(var7f1ade54)
/*  f0da4b4:	c420de54 */ 	lwc1	$f0,%lo(var7f1ade54)($at)
/*  f0da4b8:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0da4bc:	3c088008 */ 	lui	$t0,%hi(g_ScaleX)
/*  f0da4c0:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0da4c4:	4600203c */ 	c.lt.s	$f4,$f0
/*  f0da4c8:	2508fac0 */ 	addiu	$t0,$t0,%lo(g_ScaleX)
/*  f0da4cc:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f0da4d0:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0da4d4:	45020012 */ 	bc1fl	.L0f0da520
/*  f0da4d8:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f0da4dc:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f0da4e0:	0007c843 */ 	sra	$t9,$a3,0x1
/*  f0da4e4:	272effc4 */ 	addiu	$t6,$t9,-60
/*  f0da4e8:	448e3000 */ 	mtc1	$t6,$f6
/*  f0da4ec:	00000000 */ 	nop
/*  f0da4f0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0da4f4:	448d3000 */ 	mtc1	$t5,$f6
/*  f0da4f8:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0da4fc:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0da500:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0da504:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0da508:	441f2000 */ 	mfc1	$ra,$f4
/*  f0da50c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0da510:	440d2000 */ 	mfc1	$t5,$f4
/*  f0da514:	10000012 */ 	b	.L0f0da560
/*  f0da518:	8c8f006c */ 	lw	$t7,0x6c($a0)
/*  f0da51c:	8fa700f4 */ 	lw	$a3,0xf4($sp)
.L0f0da520:
/*  f0da520:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0da524:	00077043 */ 	sra	$t6,$a3,0x1
/*  f0da528:	25cfffc4 */ 	addiu	$t7,$t6,-60
/*  f0da52c:	448f3000 */ 	mtc1	$t7,$f6
/*  f0da530:	00000000 */ 	nop
/*  f0da534:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0da538:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0da53c:	448d4000 */ 	mtc1	$t5,$f8
/*  f0da540:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0da544:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0da548:	441f3000 */ 	mfc1	$ra,$f6
/*  f0da54c:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0da550:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0da554:	440d4000 */ 	mfc1	$t5,$f8
/*  f0da558:	00000000 */ 	nop
/*  f0da55c:	8c8f006c */ 	lw	$t7,0x6c($a0)
.L0f0da560:
/*  f0da560:	51e00004 */ 	beqzl	$t7,.L0f0da574
/*  f0da564:	00003025 */ 	or	$a2,$zero,$zero
/*  f0da568:	10000002 */ 	b	.L0f0da574
/*  f0da56c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0da570:	00003025 */ 	or	$a2,$zero,$zero
.L0f0da574:
/*  f0da574:	8c980068 */ 	lw	$t8,0x68($a0)
/*  f0da578:	53000004 */ 	beqzl	$t8,.L0f0da58c
/*  f0da57c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0da580:	10000002 */ 	b	.L0f0da58c
/*  f0da584:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0da588:	00001825 */ 	or	$v1,$zero,$zero
.L0f0da58c:
/*  f0da58c:	8c8e0064 */ 	lw	$t6,0x64($a0)
/*  f0da590:	51c00004 */ 	beqzl	$t6,.L0f0da5a4
/*  f0da594:	00002825 */ 	or	$a1,$zero,$zero
/*  f0da598:	10000002 */ 	b	.L0f0da5a4
/*  f0da59c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0da5a0:	00002825 */ 	or	$a1,$zero,$zero
.L0f0da5a4:
/*  f0da5a4:	8c990070 */ 	lw	$t9,0x70($a0)
/*  f0da5a8:	53200004 */ 	beqzl	$t9,.L0f0da5bc
/*  f0da5ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f0da5b0:	10000002 */ 	b	.L0f0da5bc
/*  f0da5b4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0da5b8:	00002025 */ 	or	$a0,$zero,$zero
.L0f0da5bc:
/*  f0da5bc:	00857821 */ 	addu	$t7,$a0,$a1
/*  f0da5c0:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f0da5c4:	03067021 */ 	addu	$t6,$t8,$a2
/*  f0da5c8:	29c10002 */ 	slti	$at,$t6,0x2
/*  f0da5cc:	14200003 */ 	bnez	$at,.L0f0da5dc
/*  f0da5d0:	24efffcf */ 	addiu	$t7,$a3,-49
/*  f0da5d4:	000dc840 */ 	sll	$t9,$t5,0x1
/*  f0da5d8:	03206825 */ 	or	$t5,$t9,$zero
.L0f0da5dc:
/*  f0da5dc:	448f5000 */ 	mtc1	$t7,$f10
/*  f0da5e0:	2be10005 */ 	slti	$at,$ra,0x5
/*  f0da5e4:	10200002 */ 	beqz	$at,.L0f0da5f0
/*  f0da5e8:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f0da5ec:	241f0005 */ 	addiu	$ra,$zero,0x5
.L0f0da5f0:
/*  f0da5f0:	29a10005 */ 	slti	$at,$t5,0x5
/*  f0da5f4:	50200003 */ 	beqzl	$at,.L0f0da604
/*  f0da5f8:	44872000 */ 	mtc1	$a3,$f4
/*  f0da5fc:	240d0005 */ 	addiu	$t5,$zero,0x5
/*  f0da600:	44872000 */ 	mtc1	$a3,$f4
.L0f0da604:
/*  f0da604:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0da608:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0da60c:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0da610:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f0da614:	0007c040 */ 	sll	$t8,$a3,0x1
/*  f0da618:	03037021 */ 	addu	$t6,$t8,$v1
/*  f0da61c:	25d9ffff */ 	addiu	$t9,$t6,-1
/*  f0da620:	44993000 */ 	mtc1	$t9,$f6
/*  f0da624:	24efffd0 */ 	addiu	$t7,$a3,-48
/*  f0da628:	8fb900dc */ 	lw	$t9,0xdc($sp)
/*  f0da62c:	46040281 */ 	sub.s	$f10,$f0,$f4
/*  f0da630:	3c013f80 */ 	lui	$at,0x3f80
/*  f0da634:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0da638:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f0da63c:	448f2000 */ 	mtc1	$t7,$f4
/*  f0da640:	00000000 */ 	nop
/*  f0da644:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0da648:	e7a60050 */ 	swc1	$f6,0x50($sp)
/*  f0da64c:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0da650:	44834000 */ 	mtc1	$v1,$f8
/*  f0da654:	46040281 */ 	sub.s	$f10,$f0,$f4
/*  f0da658:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0da65c:	449f4000 */ 	mtc1	$ra,$f8
/*  f0da660:	00000000 */ 	nop
/*  f0da664:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f0da668:	44994000 */ 	mtc1	$t9,$f8
/*  f0da66c:	460a2080 */ 	add.s	$f2,$f4,$f10
/*  f0da670:	46023381 */ 	sub.s	$f14,$f6,$f2
/*  f0da674:	460c703c */ 	c.lt.s	$f14,$f12
/*  f0da678:	00000000 */ 	nop
/*  f0da67c:	45020008 */ 	bc1fl	.L0f0da6a0
/*  f0da680:	8fae00f0 */ 	lw	$t6,0xf0($sp)
/*  f0da684:	4600710d */ 	trunc.w.s	$f4,$f14
/*  f0da688:	441f2000 */ 	mfc1	$ra,$f4
/*  f0da68c:	00000000 */ 	nop
/*  f0da690:	449f5000 */ 	mtc1	$ra,$f10
/*  f0da694:	00000000 */ 	nop
/*  f0da698:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f0da69c:	8fae00f0 */ 	lw	$t6,0xf0($sp)
.L0f0da6a0:
/*  f0da6a0:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0da6a4:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0da6a8:	448e3000 */ 	mtc1	$t6,$f6
/*  f0da6ac:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f0da6b0:	8fb800e0 */ 	lw	$t8,0xe0($sp)
/*  f0da6b4:	46803020 */ 	cvt.s.w	$f0,$f6
/*  f0da6b8:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0da6bc:	448f2000 */ 	mtc1	$t7,$f4
/*  f0da6c0:	8fae00f8 */ 	lw	$t6,0xf8($sp)
/*  f0da6c4:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f0da6c8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0da6cc:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f0da6d0:	44983000 */ 	mtc1	$t8,$f6
/*  f0da6d4:	00000000 */ 	nop
/*  f0da6d8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0da6dc:	e7a40048 */ 	swc1	$f4,0x48($sp)
/*  f0da6e0:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f0da6e4:	448e5000 */ 	mtc1	$t6,$f10
/*  f0da6e8:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f0da6ec:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f0da6f0:	448d5000 */ 	mtc1	$t5,$f10
/*  f0da6f4:	00000000 */ 	nop
/*  f0da6f8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f0da6fc:	46083380 */ 	add.s	$f14,$f6,$f8
/*  f0da700:	460e2401 */ 	sub.s	$f16,$f4,$f14
/*  f0da704:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0da708:	00000000 */ 	nop
/*  f0da70c:	45020008 */ 	bc1fl	.L0f0da730
/*  f0da710:	460c1100 */ 	add.s	$f4,$f2,$f12
/*  f0da714:	4600818d */ 	trunc.w.s	$f6,$f16
/*  f0da718:	440d3000 */ 	mfc1	$t5,$f6
/*  f0da71c:	00000000 */ 	nop
/*  f0da720:	448d4000 */ 	mtc1	$t5,$f8
/*  f0da724:	00000000 */ 	nop
/*  f0da728:	468044a0 */ 	cvt.s.w	$f18,$f8
/*  f0da72c:	460c1100 */ 	add.s	$f4,$f2,$f12
.L0f0da730:
/*  f0da730:	44810000 */ 	mtc1	$at,$f0
/*  f0da734:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0da738:	3c03f600 */ 	lui	$v1,0xf600
/*  f0da73c:	46002281 */ 	sub.s	$f10,$f4,$f0
/*  f0da740:	00402025 */ 	or	$a0,$v0,$zero
/*  f0da744:	24460008 */ 	addiu	$a2,$v0,0x8
/*  f0da748:	46007200 */ 	add.s	$f8,$f14,$f0
/*  f0da74c:	46005180 */ 	add.s	$f6,$f10,$f0
/*  f0da750:	444ff800 */ 	cfc1	$t7,$31
/*  f0da754:	44caf800 */ 	ctc1	$t2,$31
/*  f0da758:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f0da75c:	46004124 */ 	cvt.w.s	$f4,$f8
/*  f0da760:	444af800 */ 	cfc1	$t2,$31
/*  f0da764:	00000000 */ 	nop
/*  f0da768:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0da76c:	11400012 */ 	beqz	$t2,.L0f0da7b8
/*  f0da770:	3c014f00 */ 	lui	$at,0x4f00
/*  f0da774:	44812000 */ 	mtc1	$at,$f4
/*  f0da778:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0da77c:	46044101 */ 	sub.s	$f4,$f8,$f4
/*  f0da780:	44caf800 */ 	ctc1	$t2,$31
/*  f0da784:	00000000 */ 	nop
/*  f0da788:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0da78c:	444af800 */ 	cfc1	$t2,$31
/*  f0da790:	00000000 */ 	nop
/*  f0da794:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0da798:	15400005 */ 	bnez	$t2,.L0f0da7b0
/*  f0da79c:	00000000 */ 	nop
/*  f0da7a0:	440a2000 */ 	mfc1	$t2,$f4
/*  f0da7a4:	3c018000 */ 	lui	$at,0x8000
/*  f0da7a8:	10000007 */ 	b	.L0f0da7c8
/*  f0da7ac:	01415025 */ 	or	$t2,$t2,$at
.L0f0da7b0:
/*  f0da7b0:	10000005 */ 	b	.L0f0da7c8
/*  f0da7b4:	240affff */ 	addiu	$t2,$zero,-1
.L0f0da7b8:
/*  f0da7b8:	440a2000 */ 	mfc1	$t2,$f4
/*  f0da7bc:	00000000 */ 	nop
/*  f0da7c0:	0540fffb */ 	bltz	$t2,.L0f0da7b0
/*  f0da7c4:	00000000 */ 	nop
.L0f0da7c8:
/*  f0da7c8:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0da7cc:	44cff800 */ 	ctc1	$t7,$31
/*  f0da7d0:	315803ff */ 	andi	$t8,$t2,0x3ff
/*  f0da7d4:	44995000 */ 	mtc1	$t9,$f10
/*  f0da7d8:	00185080 */ 	sll	$t2,$t8,0x2
/*  f0da7dc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0da7e0:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0da7e4:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f0da7e8:	444ff800 */ 	cfc1	$t7,$31
/*  f0da7ec:	44d8f800 */ 	ctc1	$t8,$31
/*  f0da7f0:	00000000 */ 	nop
/*  f0da7f4:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0da7f8:	4458f800 */ 	cfc1	$t8,$31
/*  f0da7fc:	00000000 */ 	nop
/*  f0da800:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0da804:	13000012 */ 	beqz	$t8,.L0f0da850
/*  f0da808:	3c014f00 */ 	lui	$at,0x4f00
/*  f0da80c:	44815000 */ 	mtc1	$at,$f10
/*  f0da810:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0da814:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0da818:	44d8f800 */ 	ctc1	$t8,$31
/*  f0da81c:	00000000 */ 	nop
/*  f0da820:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0da824:	4458f800 */ 	cfc1	$t8,$31
/*  f0da828:	00000000 */ 	nop
/*  f0da82c:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0da830:	17000005 */ 	bnez	$t8,.L0f0da848
/*  f0da834:	00000000 */ 	nop
/*  f0da838:	44185000 */ 	mfc1	$t8,$f10
/*  f0da83c:	3c018000 */ 	lui	$at,0x8000
/*  f0da840:	10000007 */ 	b	.L0f0da860
/*  f0da844:	0301c025 */ 	or	$t8,$t8,$at
.L0f0da848:
/*  f0da848:	10000005 */ 	b	.L0f0da860
/*  f0da84c:	2418ffff */ 	addiu	$t8,$zero,-1
.L0f0da850:
/*  f0da850:	44185000 */ 	mfc1	$t8,$f10
/*  f0da854:	00000000 */ 	nop
/*  f0da858:	0700fffb */ 	bltz	$t8,.L0f0da848
/*  f0da85c:	00000000 */ 	nop
.L0f0da860:
/*  f0da860:	44cff800 */ 	ctc1	$t7,$31
/*  f0da864:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0da868:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0da86c:	46001400 */ 	add.s	$f16,$f2,$f0
/*  f0da870:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0da874:	03237825 */ 	or	$t7,$t9,$v1
/*  f0da878:	01eac025 */ 	or	$t8,$t7,$t2
/*  f0da87c:	444ef800 */ 	cfc1	$t6,$31
/*  f0da880:	44c7f800 */ 	ctc1	$a3,$31
/*  f0da884:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f0da888:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0da88c:	460071a4 */ 	cvt.w.s	$f6,$f14
/*  f0da890:	4447f800 */ 	cfc1	$a3,$31
/*  f0da894:	00000000 */ 	nop
/*  f0da898:	30e70078 */ 	andi	$a3,$a3,0x78
/*  f0da89c:	10e00012 */ 	beqz	$a3,.L0f0da8e8
/*  f0da8a0:	3c014f00 */ 	lui	$at,0x4f00
/*  f0da8a4:	44813000 */ 	mtc1	$at,$f6
/*  f0da8a8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0da8ac:	46067181 */ 	sub.s	$f6,$f14,$f6
/*  f0da8b0:	44c7f800 */ 	ctc1	$a3,$31
/*  f0da8b4:	00000000 */ 	nop
/*  f0da8b8:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0da8bc:	4447f800 */ 	cfc1	$a3,$31
/*  f0da8c0:	00000000 */ 	nop
/*  f0da8c4:	30e70078 */ 	andi	$a3,$a3,0x78
/*  f0da8c8:	14e00005 */ 	bnez	$a3,.L0f0da8e0
/*  f0da8cc:	00000000 */ 	nop
/*  f0da8d0:	44073000 */ 	mfc1	$a3,$f6
/*  f0da8d4:	3c018000 */ 	lui	$at,0x8000
/*  f0da8d8:	10000007 */ 	b	.L0f0da8f8
/*  f0da8dc:	00e13825 */ 	or	$a3,$a3,$at
.L0f0da8e0:
/*  f0da8e0:	10000005 */ 	b	.L0f0da8f8
/*  f0da8e4:	2407ffff */ 	addiu	$a3,$zero,-1
.L0f0da8e8:
/*  f0da8e8:	44073000 */ 	mfc1	$a3,$f6
/*  f0da8ec:	00000000 */ 	nop
/*  f0da8f0:	04e0fffb */ 	bltz	$a3,.L0f0da8e0
/*  f0da8f4:	00000000 */ 	nop
.L0f0da8f8:
/*  f0da8f8:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f0da8fc:	44cef800 */ 	ctc1	$t6,$31
/*  f0da900:	30f903ff */ 	andi	$t9,$a3,0x3ff
/*  f0da904:	44984000 */ 	mtc1	$t8,$f8
/*  f0da908:	00193880 */ 	sll	$a3,$t9,0x2
/*  f0da90c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0da910:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0da914:	46048282 */ 	mul.s	$f10,$f16,$f4
/*  f0da918:	444ef800 */ 	cfc1	$t6,$31
/*  f0da91c:	44d9f800 */ 	ctc1	$t9,$31
/*  f0da920:	00000000 */ 	nop
/*  f0da924:	460051a4 */ 	cvt.w.s	$f6,$f10
/*  f0da928:	4459f800 */ 	cfc1	$t9,$31
/*  f0da92c:	00000000 */ 	nop
/*  f0da930:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0da934:	13200012 */ 	beqz	$t9,.L0f0da980
/*  f0da938:	3c014f00 */ 	lui	$at,0x4f00
/*  f0da93c:	44813000 */ 	mtc1	$at,$f6
/*  f0da940:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0da944:	46065181 */ 	sub.s	$f6,$f10,$f6
/*  f0da948:	44d9f800 */ 	ctc1	$t9,$31
/*  f0da94c:	00000000 */ 	nop
/*  f0da950:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0da954:	4459f800 */ 	cfc1	$t9,$31
/*  f0da958:	00000000 */ 	nop
/*  f0da95c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0da960:	17200005 */ 	bnez	$t9,.L0f0da978
/*  f0da964:	00000000 */ 	nop
/*  f0da968:	44193000 */ 	mfc1	$t9,$f6
/*  f0da96c:	3c018000 */ 	lui	$at,0x8000
/*  f0da970:	10000007 */ 	b	.L0f0da990
/*  f0da974:	0321c825 */ 	or	$t9,$t9,$at
.L0f0da978:
/*  f0da978:	10000005 */ 	b	.L0f0da990
/*  f0da97c:	2419ffff */ 	addiu	$t9,$zero,-1
.L0f0da980:
/*  f0da980:	44193000 */ 	mfc1	$t9,$f6
/*  f0da984:	00000000 */ 	nop
/*  f0da988:	0720fffb */ 	bltz	$t9,.L0f0da978
/*  f0da98c:	00000000 */ 	nop
.L0f0da990:
/*  f0da990:	44cef800 */ 	ctc1	$t6,$31
/*  f0da994:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0da998:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0da99c:	46127200 */ 	add.s	$f8,$f14,$f18
/*  f0da9a0:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0da9a4:	03077025 */ 	or	$t6,$t8,$a3
/*  f0da9a8:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0da9ac:	46004101 */ 	sub.s	$f4,$f8,$f0
/*  f0da9b0:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f0da9b4:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0da9b8:	46002280 */ 	add.s	$f10,$f4,$f0
/*  f0da9bc:	4459f800 */ 	cfc1	$t9,$31
/*  f0da9c0:	44cbf800 */ 	ctc1	$t3,$31
/*  f0da9c4:	00000000 */ 	nop
/*  f0da9c8:	460051a4 */ 	cvt.w.s	$f6,$f10
/*  f0da9cc:	444bf800 */ 	cfc1	$t3,$31
/*  f0da9d0:	00000000 */ 	nop
/*  f0da9d4:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0da9d8:	11600012 */ 	beqz	$t3,.L0f0daa24
/*  f0da9dc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0da9e0:	44813000 */ 	mtc1	$at,$f6
/*  f0da9e4:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0da9e8:	46065181 */ 	sub.s	$f6,$f10,$f6
/*  f0da9ec:	44cbf800 */ 	ctc1	$t3,$31
/*  f0da9f0:	00000000 */ 	nop
/*  f0da9f4:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0da9f8:	444bf800 */ 	cfc1	$t3,$31
/*  f0da9fc:	00000000 */ 	nop
/*  f0daa00:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0daa04:	15600005 */ 	bnez	$t3,.L0f0daa1c
/*  f0daa08:	00000000 */ 	nop
/*  f0daa0c:	440b3000 */ 	mfc1	$t3,$f6
/*  f0daa10:	3c018000 */ 	lui	$at,0x8000
/*  f0daa14:	10000007 */ 	b	.L0f0daa34
/*  f0daa18:	01615825 */ 	or	$t3,$t3,$at
.L0f0daa1c:
/*  f0daa1c:	10000005 */ 	b	.L0f0daa34
/*  f0daa20:	240bffff */ 	addiu	$t3,$zero,-1
.L0f0daa24:
/*  f0daa24:	440b3000 */ 	mfc1	$t3,$f6
/*  f0daa28:	00000000 */ 	nop
/*  f0daa2c:	0560fffb */ 	bltz	$t3,.L0f0daa1c
/*  f0daa30:	00000000 */ 	nop
.L0f0daa34:
/*  f0daa34:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0daa38:	44d9f800 */ 	ctc1	$t9,$31
/*  f0daa3c:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f0daa40:	448e4000 */ 	mtc1	$t6,$f8
/*  f0daa44:	000f5880 */ 	sll	$t3,$t7,0x2
/*  f0daa48:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0daa4c:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0daa50:	46048282 */ 	mul.s	$f10,$f16,$f4
/*  f0daa54:	4459f800 */ 	cfc1	$t9,$31
/*  f0daa58:	44cff800 */ 	ctc1	$t7,$31
/*  f0daa5c:	00000000 */ 	nop
/*  f0daa60:	460051a4 */ 	cvt.w.s	$f6,$f10
/*  f0daa64:	444ff800 */ 	cfc1	$t7,$31
/*  f0daa68:	00000000 */ 	nop
/*  f0daa6c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0daa70:	11e00012 */ 	beqz	$t7,.L0f0daabc
/*  f0daa74:	3c014f00 */ 	lui	$at,0x4f00
/*  f0daa78:	44813000 */ 	mtc1	$at,$f6
/*  f0daa7c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0daa80:	46065181 */ 	sub.s	$f6,$f10,$f6
/*  f0daa84:	44cff800 */ 	ctc1	$t7,$31
/*  f0daa88:	00000000 */ 	nop
/*  f0daa8c:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0daa90:	444ff800 */ 	cfc1	$t7,$31
/*  f0daa94:	00000000 */ 	nop
/*  f0daa98:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0daa9c:	15e00005 */ 	bnez	$t7,.L0f0daab4
/*  f0daaa0:	00000000 */ 	nop
/*  f0daaa4:	440f3000 */ 	mfc1	$t7,$f6
/*  f0daaa8:	3c018000 */ 	lui	$at,0x8000
/*  f0daaac:	10000007 */ 	b	.L0f0daacc
/*  f0daab0:	01e17825 */ 	or	$t7,$t7,$at
.L0f0daab4:
/*  f0daab4:	10000005 */ 	b	.L0f0daacc
/*  f0daab8:	240fffff */ 	addiu	$t7,$zero,-1
.L0f0daabc:
/*  f0daabc:	440f3000 */ 	mfc1	$t7,$f6
/*  f0daac0:	00000000 */ 	nop
/*  f0daac4:	05e0fffb */ 	bltz	$t7,.L0f0daab4
/*  f0daac8:	00000000 */ 	nop
.L0f0daacc:
/*  f0daacc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0daad0:	44d9f800 */ 	ctc1	$t9,$31
/*  f0daad4:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0daad8:	01c3c825 */ 	or	$t9,$t6,$v1
/*  f0daadc:	032b7825 */ 	or	$t7,$t9,$t3
/*  f0daae0:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f0daae4:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f0daae8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0daaec:	44984000 */ 	mtc1	$t8,$f8
/*  f0daaf0:	00000000 */ 	nop
/*  f0daaf4:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0daaf8:	46041282 */ 	mul.s	$f10,$f2,$f4
/*  f0daafc:	444ef800 */ 	cfc1	$t6,$31
/*  f0dab00:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dab04:	00000000 */ 	nop
/*  f0dab08:	460051a4 */ 	cvt.w.s	$f6,$f10
/*  f0dab0c:	4459f800 */ 	cfc1	$t9,$31
/*  f0dab10:	00000000 */ 	nop
/*  f0dab14:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0dab18:	13200012 */ 	beqz	$t9,.L0f0dab64
/*  f0dab1c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dab20:	44813000 */ 	mtc1	$at,$f6
/*  f0dab24:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0dab28:	46065181 */ 	sub.s	$f6,$f10,$f6
/*  f0dab2c:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dab30:	00000000 */ 	nop
/*  f0dab34:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0dab38:	4459f800 */ 	cfc1	$t9,$31
/*  f0dab3c:	00000000 */ 	nop
/*  f0dab40:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0dab44:	17200005 */ 	bnez	$t9,.L0f0dab5c
/*  f0dab48:	00000000 */ 	nop
/*  f0dab4c:	44193000 */ 	mfc1	$t9,$f6
/*  f0dab50:	3c018000 */ 	lui	$at,0x8000
/*  f0dab54:	10000007 */ 	b	.L0f0dab74
/*  f0dab58:	0321c825 */ 	or	$t9,$t9,$at
.L0f0dab5c:
/*  f0dab5c:	10000005 */ 	b	.L0f0dab74
/*  f0dab60:	2419ffff */ 	addiu	$t9,$zero,-1
.L0f0dab64:
/*  f0dab64:	44193000 */ 	mfc1	$t9,$f6
/*  f0dab68:	00000000 */ 	nop
/*  f0dab6c:	0720fffb */ 	bltz	$t9,.L0f0dab5c
/*  f0dab70:	00000000 */ 	nop
.L0f0dab74:
/*  f0dab74:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0dab78:	44cef800 */ 	ctc1	$t6,$31
/*  f0dab7c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0dab80:	03077025 */ 	or	$t6,$t8,$a3
/*  f0dab84:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f0dab88:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0dab8c:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f0dab90:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dab94:	44993000 */ 	mtc1	$t9,$f6
/*  f0dab98:	46004101 */ 	sub.s	$f4,$f8,$f0
/*  f0dab9c:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0daba0:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0daba4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0daba8:	46002280 */ 	add.s	$f10,$f4,$f0
/*  f0dabac:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0dabb0:	e7aa0028 */ 	swc1	$f10,0x28($sp)
/*  f0dabb4:	444ff800 */ 	cfc1	$t7,$31
/*  f0dabb8:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dabbc:	00000000 */ 	nop
/*  f0dabc0:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f0dabc4:	4458f800 */ 	cfc1	$t8,$31
/*  f0dabc8:	00000000 */ 	nop
/*  f0dabcc:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dabd0:	13000012 */ 	beqz	$t8,.L0f0dac1c
/*  f0dabd4:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dabd8:	44813000 */ 	mtc1	$at,$f6
/*  f0dabdc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dabe0:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f0dabe4:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dabe8:	00000000 */ 	nop
/*  f0dabec:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0dabf0:	4458f800 */ 	cfc1	$t8,$31
/*  f0dabf4:	00000000 */ 	nop
/*  f0dabf8:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dabfc:	17000005 */ 	bnez	$t8,.L0f0dac14
/*  f0dac00:	00000000 */ 	nop
/*  f0dac04:	44183000 */ 	mfc1	$t8,$f6
/*  f0dac08:	3c018000 */ 	lui	$at,0x8000
/*  f0dac0c:	10000007 */ 	b	.L0f0dac2c
/*  f0dac10:	0301c025 */ 	or	$t8,$t8,$at
.L0f0dac14:
/*  f0dac14:	10000005 */ 	b	.L0f0dac2c
/*  f0dac18:	2418ffff */ 	addiu	$t8,$zero,-1
.L0f0dac1c:
/*  f0dac1c:	44183000 */ 	mfc1	$t8,$f6
/*  f0dac20:	00000000 */ 	nop
/*  f0dac24:	0700fffb */ 	bltz	$t8,.L0f0dac14
/*  f0dac28:	00000000 */ 	nop
.L0f0dac2c:
/*  f0dac2c:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0dac30:	44cff800 */ 	ctc1	$t7,$31
/*  f0dac34:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0dac38:	03237825 */ 	or	$t7,$t9,$v1
/*  f0dac3c:	01eac025 */ 	or	$t8,$t7,$t2
/*  f0dac40:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0dac44:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*  f0dac48:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0dac4c:	3c014000 */ 	lui	$at,0x4000
/*  f0dac50:	460c5201 */ 	sub.s	$f8,$f10,$f12
/*  f0dac54:	44812000 */ 	mtc1	$at,$f4
/*  f0dac58:	448e5000 */ 	mtc1	$t6,$f10
/*  f0dac5c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dac60:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0dac64:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0dac68:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f0dac6c:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f0dac70:	4459f800 */ 	cfc1	$t9,$31
/*  f0dac74:	44cff800 */ 	ctc1	$t7,$31
/*  f0dac78:	00000000 */ 	nop
/*  f0dac7c:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0dac80:	444ff800 */ 	cfc1	$t7,$31
/*  f0dac84:	00000000 */ 	nop
/*  f0dac88:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dac8c:	11e00012 */ 	beqz	$t7,.L0f0dacd8
/*  f0dac90:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dac94:	44815000 */ 	mtc1	$at,$f10
/*  f0dac98:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dac9c:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0daca0:	44cff800 */ 	ctc1	$t7,$31
/*  f0daca4:	00000000 */ 	nop
/*  f0daca8:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dacac:	444ff800 */ 	cfc1	$t7,$31
/*  f0dacb0:	00000000 */ 	nop
/*  f0dacb4:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dacb8:	15e00005 */ 	bnez	$t7,.L0f0dacd0
/*  f0dacbc:	00000000 */ 	nop
/*  f0dacc0:	440f5000 */ 	mfc1	$t7,$f10
/*  f0dacc4:	3c018000 */ 	lui	$at,0x8000
/*  f0dacc8:	10000007 */ 	b	.L0f0dace8
/*  f0daccc:	01e17825 */ 	or	$t7,$t7,$at
.L0f0dacd0:
/*  f0dacd0:	10000005 */ 	b	.L0f0dace8
/*  f0dacd4:	240fffff */ 	addiu	$t7,$zero,-1
.L0f0dacd8:
/*  f0dacd8:	440f5000 */ 	mfc1	$t7,$f10
/*  f0dacdc:	00000000 */ 	nop
/*  f0dace0:	05e0fffb */ 	bltz	$t7,.L0f0dacd0
/*  f0dace4:	00000000 */ 	nop
.L0f0dace8:
/*  f0dace8:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0dacec:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dacf0:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0dacf4:	01c7c825 */ 	or	$t9,$t6,$a3
/*  f0dacf8:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0dacfc:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0dad00:	c7a60050 */ 	lwc1	$f6,0x50($sp)
/*  f0dad04:	e7ae004c */ 	swc1	$f14,0x4c($sp)
/*  f0dad08:	448f4000 */ 	mtc1	$t7,$f8
/*  f0dad0c:	46003380 */ 	add.s	$f14,$f6,$f0
/*  f0dad10:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dad14:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0dad18:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0dad1c:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0dad20:	46047282 */ 	mul.s	$f10,$f14,$f4
/*  f0dad24:	4458f800 */ 	cfc1	$t8,$31
/*  f0dad28:	44cef800 */ 	ctc1	$t6,$31
/*  f0dad2c:	00000000 */ 	nop
/*  f0dad30:	460051a4 */ 	cvt.w.s	$f6,$f10
/*  f0dad34:	444ef800 */ 	cfc1	$t6,$31
/*  f0dad38:	00000000 */ 	nop
/*  f0dad3c:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dad40:	11c00012 */ 	beqz	$t6,.L0f0dad8c
/*  f0dad44:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dad48:	44813000 */ 	mtc1	$at,$f6
/*  f0dad4c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dad50:	46065181 */ 	sub.s	$f6,$f10,$f6
/*  f0dad54:	44cef800 */ 	ctc1	$t6,$31
/*  f0dad58:	00000000 */ 	nop
/*  f0dad5c:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0dad60:	444ef800 */ 	cfc1	$t6,$31
/*  f0dad64:	00000000 */ 	nop
/*  f0dad68:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dad6c:	15c00005 */ 	bnez	$t6,.L0f0dad84
/*  f0dad70:	00000000 */ 	nop
/*  f0dad74:	440e3000 */ 	mfc1	$t6,$f6
/*  f0dad78:	3c018000 */ 	lui	$at,0x8000
/*  f0dad7c:	10000007 */ 	b	.L0f0dad9c
/*  f0dad80:	01c17025 */ 	or	$t6,$t6,$at
.L0f0dad84:
/*  f0dad84:	10000005 */ 	b	.L0f0dad9c
/*  f0dad88:	240effff */ 	addiu	$t6,$zero,-1
.L0f0dad8c:
/*  f0dad8c:	440e3000 */ 	mfc1	$t6,$f6
/*  f0dad90:	00000000 */ 	nop
/*  f0dad94:	05c0fffb */ 	bltz	$t6,.L0f0dad84
/*  f0dad98:	00000000 */ 	nop
.L0f0dad9c:
/*  f0dad9c:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0dada0:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dada4:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0dada8:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0dadac:	030b7025 */ 	or	$t6,$t8,$t3
/*  f0dadb0:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f0dadb4:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0dadb8:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f0dadbc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dadc0:	44992000 */ 	mtc1	$t9,$f4
/*  f0dadc4:	00000000 */ 	nop
/*  f0dadc8:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0dadcc:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f0dadd0:	444ff800 */ 	cfc1	$t7,$31
/*  f0dadd4:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dadd8:	00000000 */ 	nop
/*  f0daddc:	46003124 */ 	cvt.w.s	$f4,$f6
/*  f0dade0:	4458f800 */ 	cfc1	$t8,$31
/*  f0dade4:	00000000 */ 	nop
/*  f0dade8:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dadec:	13000012 */ 	beqz	$t8,.L0f0dae38
/*  f0dadf0:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dadf4:	44812000 */ 	mtc1	$at,$f4
/*  f0dadf8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dadfc:	46043101 */ 	sub.s	$f4,$f6,$f4
/*  f0dae00:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dae04:	00000000 */ 	nop
/*  f0dae08:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0dae0c:	4458f800 */ 	cfc1	$t8,$31
/*  f0dae10:	00000000 */ 	nop
/*  f0dae14:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dae18:	17000005 */ 	bnez	$t8,.L0f0dae30
/*  f0dae1c:	00000000 */ 	nop
/*  f0dae20:	44182000 */ 	mfc1	$t8,$f4
/*  f0dae24:	3c018000 */ 	lui	$at,0x8000
/*  f0dae28:	10000007 */ 	b	.L0f0dae48
/*  f0dae2c:	0301c025 */ 	or	$t8,$t8,$at
.L0f0dae30:
/*  f0dae30:	10000005 */ 	b	.L0f0dae48
/*  f0dae34:	2418ffff */ 	addiu	$t8,$zero,-1
.L0f0dae38:
/*  f0dae38:	44182000 */ 	mfc1	$t8,$f4
/*  f0dae3c:	00000000 */ 	nop
/*  f0dae40:	0700fffb */ 	bltz	$t8,.L0f0dae30
/*  f0dae44:	00000000 */ 	nop
.L0f0dae48:
/*  f0dae48:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0dae4c:	44cff800 */ 	ctc1	$t7,$31
/*  f0dae50:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0dae54:	03277825 */ 	or	$t7,$t9,$a3
/*  f0dae58:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0dae5c:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f0dae60:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0dae64:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0dae68:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f0dae6c:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0dae70:	4458f800 */ 	cfc1	$t8,$31
/*  f0dae74:	44c5f800 */ 	ctc1	$a1,$31
/*  f0dae78:	00000000 */ 	nop
/*  f0dae7c:	460051a4 */ 	cvt.w.s	$f6,$f10
/*  f0dae80:	4445f800 */ 	cfc1	$a1,$31
/*  f0dae84:	00000000 */ 	nop
/*  f0dae88:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f0dae8c:	10a00012 */ 	beqz	$a1,.L0f0daed8
/*  f0dae90:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dae94:	44813000 */ 	mtc1	$at,$f6
/*  f0dae98:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0dae9c:	46065181 */ 	sub.s	$f6,$f10,$f6
/*  f0daea0:	44c5f800 */ 	ctc1	$a1,$31
/*  f0daea4:	00000000 */ 	nop
/*  f0daea8:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0daeac:	4445f800 */ 	cfc1	$a1,$31
/*  f0daeb0:	00000000 */ 	nop
/*  f0daeb4:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f0daeb8:	14a00005 */ 	bnez	$a1,.L0f0daed0
/*  f0daebc:	00000000 */ 	nop
/*  f0daec0:	44053000 */ 	mfc1	$a1,$f6
/*  f0daec4:	3c018000 */ 	lui	$at,0x8000
/*  f0daec8:	10000007 */ 	b	.L0f0daee8
/*  f0daecc:	00a12825 */ 	or	$a1,$a1,$at
.L0f0daed0:
/*  f0daed0:	10000005 */ 	b	.L0f0daee8
/*  f0daed4:	2405ffff */ 	addiu	$a1,$zero,-1
.L0f0daed8:
/*  f0daed8:	44053000 */ 	mfc1	$a1,$f6
/*  f0daedc:	00000000 */ 	nop
/*  f0daee0:	04a0fffb */ 	bltz	$a1,.L0f0daed0
/*  f0daee4:	00000000 */ 	nop
.L0f0daee8:
/*  f0daee8:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0daeec:	44d8f800 */ 	ctc1	$t8,$31
/*  f0daef0:	c7a4001c */ 	lwc1	$f4,0x1c($sp)
/*  f0daef4:	448f4000 */ 	mtc1	$t7,$f8
/*  f0daef8:	30ae03ff */ 	andi	$t6,$a1,0x3ff
/*  f0daefc:	000e2880 */ 	sll	$a1,$t6,0x2
/*  f0daf00:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0daf04:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0daf08:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0daf0c:	4458f800 */ 	cfc1	$t8,$31
/*  f0daf10:	44cef800 */ 	ctc1	$t6,$31
/*  f0daf14:	00000000 */ 	nop
/*  f0daf18:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0daf1c:	444ef800 */ 	cfc1	$t6,$31
/*  f0daf20:	00000000 */ 	nop
/*  f0daf24:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0daf28:	11c00012 */ 	beqz	$t6,.L0f0daf74
/*  f0daf2c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0daf30:	44814000 */ 	mtc1	$at,$f8
/*  f0daf34:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0daf38:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0daf3c:	44cef800 */ 	ctc1	$t6,$31
/*  f0daf40:	00000000 */ 	nop
/*  f0daf44:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0daf48:	444ef800 */ 	cfc1	$t6,$31
/*  f0daf4c:	00000000 */ 	nop
/*  f0daf50:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0daf54:	15c00005 */ 	bnez	$t6,.L0f0daf6c
/*  f0daf58:	00000000 */ 	nop
/*  f0daf5c:	440e4000 */ 	mfc1	$t6,$f8
/*  f0daf60:	3c018000 */ 	lui	$at,0x8000
/*  f0daf64:	10000007 */ 	b	.L0f0daf84
/*  f0daf68:	01c17025 */ 	or	$t6,$t6,$at
.L0f0daf6c:
/*  f0daf6c:	10000005 */ 	b	.L0f0daf84
/*  f0daf70:	240effff */ 	addiu	$t6,$zero,-1
.L0f0daf74:
/*  f0daf74:	440e4000 */ 	mfc1	$t6,$f8
/*  f0daf78:	00000000 */ 	nop
/*  f0daf7c:	05c0fffb */ 	bltz	$t6,.L0f0daf6c
/*  f0daf80:	00000000 */ 	nop
.L0f0daf84:
/*  f0daf84:	44d8f800 */ 	ctc1	$t8,$31
/*  f0daf88:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0daf8c:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0daf90:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0daf94:	03057025 */ 	or	$t6,$t8,$a1
/*  f0daf98:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0daf9c:	4459f800 */ 	cfc1	$t9,$31
/*  f0dafa0:	44c9f800 */ 	ctc1	$t1,$31
/*  f0dafa4:	c7a40048 */ 	lwc1	$f4,0x48($sp)
/*  f0dafa8:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0dafac:	4449f800 */ 	cfc1	$t1,$31
/*  f0dafb0:	00000000 */ 	nop
/*  f0dafb4:	31290078 */ 	andi	$t1,$t1,0x78
/*  f0dafb8:	11200012 */ 	beqz	$t1,.L0f0db004
/*  f0dafbc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dafc0:	44815000 */ 	mtc1	$at,$f10
/*  f0dafc4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0dafc8:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0dafcc:	44c9f800 */ 	ctc1	$t1,$31
/*  f0dafd0:	00000000 */ 	nop
/*  f0dafd4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dafd8:	4449f800 */ 	cfc1	$t1,$31
/*  f0dafdc:	00000000 */ 	nop
/*  f0dafe0:	31290078 */ 	andi	$t1,$t1,0x78
/*  f0dafe4:	15200005 */ 	bnez	$t1,.L0f0daffc
/*  f0dafe8:	00000000 */ 	nop
/*  f0dafec:	44095000 */ 	mfc1	$t1,$f10
/*  f0daff0:	3c018000 */ 	lui	$at,0x8000
/*  f0daff4:	10000007 */ 	b	.L0f0db014
/*  f0daff8:	01214825 */ 	or	$t1,$t1,$at
.L0f0daffc:
/*  f0daffc:	10000005 */ 	b	.L0f0db014
/*  f0db000:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f0db004:
/*  f0db004:	44095000 */ 	mfc1	$t1,$f10
/*  f0db008:	00000000 */ 	nop
/*  f0db00c:	0520fffb */ 	bltz	$t1,.L0f0daffc
/*  f0db010:	00000000 */ 	nop
.L0f0db014:
/*  f0db014:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0db018:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db01c:	312f03ff */ 	andi	$t7,$t1,0x3ff
/*  f0db020:	448e3000 */ 	mtc1	$t6,$f6
/*  f0db024:	000f4880 */ 	sll	$t1,$t7,0x2
/*  f0db028:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0db02c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0db030:	46088102 */ 	mul.s	$f4,$f16,$f8
/*  f0db034:	4459f800 */ 	cfc1	$t9,$31
/*  f0db038:	44cff800 */ 	ctc1	$t7,$31
/*  f0db03c:	00000000 */ 	nop
/*  f0db040:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0db044:	444ff800 */ 	cfc1	$t7,$31
/*  f0db048:	00000000 */ 	nop
/*  f0db04c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0db050:	11e00012 */ 	beqz	$t7,.L0f0db09c
/*  f0db054:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db058:	44815000 */ 	mtc1	$at,$f10
/*  f0db05c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0db060:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0db064:	44cff800 */ 	ctc1	$t7,$31
/*  f0db068:	00000000 */ 	nop
/*  f0db06c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0db070:	444ff800 */ 	cfc1	$t7,$31
/*  f0db074:	00000000 */ 	nop
/*  f0db078:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0db07c:	15e00005 */ 	bnez	$t7,.L0f0db094
/*  f0db080:	00000000 */ 	nop
/*  f0db084:	440f5000 */ 	mfc1	$t7,$f10
/*  f0db088:	3c018000 */ 	lui	$at,0x8000
/*  f0db08c:	10000007 */ 	b	.L0f0db0ac
/*  f0db090:	01e17825 */ 	or	$t7,$t7,$at
.L0f0db094:
/*  f0db094:	10000005 */ 	b	.L0f0db0ac
/*  f0db098:	240fffff */ 	addiu	$t7,$zero,-1
.L0f0db09c:
/*  f0db09c:	440f5000 */ 	mfc1	$t7,$f10
/*  f0db0a0:	00000000 */ 	nop
/*  f0db0a4:	05e0fffb */ 	bltz	$t7,.L0f0db094
/*  f0db0a8:	00000000 */ 	nop
.L0f0db0ac:
/*  f0db0ac:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0db0b0:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db0b4:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0db0b8:	01c9c825 */ 	or	$t9,$t6,$t1
/*  f0db0bc:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0db0c0:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0db0c4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db0c8:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0db0cc:	448f3000 */ 	mtc1	$t7,$f6
/*  f0db0d0:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0db0d4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0db0d8:	46088102 */ 	mul.s	$f4,$f16,$f8
/*  f0db0dc:	4458f800 */ 	cfc1	$t8,$31
/*  f0db0e0:	44cef800 */ 	ctc1	$t6,$31
/*  f0db0e4:	00000000 */ 	nop
/*  f0db0e8:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0db0ec:	444ef800 */ 	cfc1	$t6,$31
/*  f0db0f0:	00000000 */ 	nop
/*  f0db0f4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db0f8:	11c00012 */ 	beqz	$t6,.L0f0db144
/*  f0db0fc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db100:	44815000 */ 	mtc1	$at,$f10
/*  f0db104:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db108:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0db10c:	44cef800 */ 	ctc1	$t6,$31
/*  f0db110:	00000000 */ 	nop
/*  f0db114:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0db118:	444ef800 */ 	cfc1	$t6,$31
/*  f0db11c:	00000000 */ 	nop
/*  f0db120:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db124:	15c00005 */ 	bnez	$t6,.L0f0db13c
/*  f0db128:	00000000 */ 	nop
/*  f0db12c:	440e5000 */ 	mfc1	$t6,$f10
/*  f0db130:	3c018000 */ 	lui	$at,0x8000
/*  f0db134:	10000007 */ 	b	.L0f0db154
/*  f0db138:	01c17025 */ 	or	$t6,$t6,$at
.L0f0db13c:
/*  f0db13c:	10000005 */ 	b	.L0f0db154
/*  f0db140:	240effff */ 	addiu	$t6,$zero,-1
.L0f0db144:
/*  f0db144:	440e5000 */ 	mfc1	$t6,$f10
/*  f0db148:	00000000 */ 	nop
/*  f0db14c:	05c0fffb */ 	bltz	$t6,.L0f0db13c
/*  f0db150:	00000000 */ 	nop
.L0f0db154:
/*  f0db154:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0db158:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db15c:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0db160:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0db164:	03057025 */ 	or	$t6,$t8,$a1
/*  f0db168:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0db16c:	c7a60048 */ 	lwc1	$f6,0x48($sp)
/*  f0db170:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0db174:	46123201 */ 	sub.s	$f8,$f6,$f18
/*  f0db178:	46004100 */ 	add.s	$f4,$f8,$f0
/*  f0db17c:	4459f800 */ 	cfc1	$t9,$31
/*  f0db180:	44cbf800 */ 	ctc1	$t3,$31
/*  f0db184:	00000000 */ 	nop
/*  f0db188:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0db18c:	444bf800 */ 	cfc1	$t3,$31
/*  f0db190:	00000000 */ 	nop
/*  f0db194:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0db198:	11600012 */ 	beqz	$t3,.L0f0db1e4
/*  f0db19c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db1a0:	44815000 */ 	mtc1	$at,$f10
/*  f0db1a4:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0db1a8:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0db1ac:	44cbf800 */ 	ctc1	$t3,$31
/*  f0db1b0:	00000000 */ 	nop
/*  f0db1b4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0db1b8:	444bf800 */ 	cfc1	$t3,$31
/*  f0db1bc:	00000000 */ 	nop
/*  f0db1c0:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0db1c4:	15600005 */ 	bnez	$t3,.L0f0db1dc
/*  f0db1c8:	00000000 */ 	nop
/*  f0db1cc:	440b5000 */ 	mfc1	$t3,$f10
/*  f0db1d0:	3c018000 */ 	lui	$at,0x8000
/*  f0db1d4:	10000007 */ 	b	.L0f0db1f4
/*  f0db1d8:	01615825 */ 	or	$t3,$t3,$at
.L0f0db1dc:
/*  f0db1dc:	10000005 */ 	b	.L0f0db1f4
/*  f0db1e0:	240bffff */ 	addiu	$t3,$zero,-1
.L0f0db1e4:
/*  f0db1e4:	440b5000 */ 	mfc1	$t3,$f10
/*  f0db1e8:	00000000 */ 	nop
/*  f0db1ec:	0560fffb */ 	bltz	$t3,.L0f0db1dc
/*  f0db1f0:	00000000 */ 	nop
.L0f0db1f4:
/*  f0db1f4:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0db1f8:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db1fc:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f0db200:	448e3000 */ 	mtc1	$t6,$f6
/*  f0db204:	000f5880 */ 	sll	$t3,$t7,0x2
/*  f0db208:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0db20c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0db210:	46081102 */ 	mul.s	$f4,$f2,$f8
/*  f0db214:	4459f800 */ 	cfc1	$t9,$31
/*  f0db218:	44cff800 */ 	ctc1	$t7,$31
/*  f0db21c:	00000000 */ 	nop
/*  f0db220:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0db224:	444ff800 */ 	cfc1	$t7,$31
/*  f0db228:	00000000 */ 	nop
/*  f0db22c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0db230:	11e00012 */ 	beqz	$t7,.L0f0db27c
/*  f0db234:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db238:	44815000 */ 	mtc1	$at,$f10
/*  f0db23c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0db240:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0db244:	44cff800 */ 	ctc1	$t7,$31
/*  f0db248:	00000000 */ 	nop
/*  f0db24c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0db250:	444ff800 */ 	cfc1	$t7,$31
/*  f0db254:	00000000 */ 	nop
/*  f0db258:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0db25c:	15e00005 */ 	bnez	$t7,.L0f0db274
/*  f0db260:	00000000 */ 	nop
/*  f0db264:	440f5000 */ 	mfc1	$t7,$f10
/*  f0db268:	3c018000 */ 	lui	$at,0x8000
/*  f0db26c:	10000007 */ 	b	.L0f0db28c
/*  f0db270:	01e17825 */ 	or	$t7,$t7,$at
.L0f0db274:
/*  f0db274:	10000005 */ 	b	.L0f0db28c
/*  f0db278:	240fffff */ 	addiu	$t7,$zero,-1
.L0f0db27c:
/*  f0db27c:	440f5000 */ 	mfc1	$t7,$f10
/*  f0db280:	00000000 */ 	nop
/*  f0db284:	05e0fffb */ 	bltz	$t7,.L0f0db274
/*  f0db288:	00000000 */ 	nop
.L0f0db28c:
/*  f0db28c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0db290:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db294:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0db298:	01cbc825 */ 	or	$t9,$t6,$t3
/*  f0db29c:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0db2a0:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0db2a4:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*  f0db2a8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db2ac:	448f4000 */ 	mtc1	$t7,$f8
/*  f0db2b0:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0db2b4:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0db2b8:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0db2bc:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f0db2c0:	4458f800 */ 	cfc1	$t8,$31
/*  f0db2c4:	44cef800 */ 	ctc1	$t6,$31
/*  f0db2c8:	00000000 */ 	nop
/*  f0db2cc:	46005224 */ 	cvt.w.s	$f8,$f10
/*  f0db2d0:	444ef800 */ 	cfc1	$t6,$31
/*  f0db2d4:	00000000 */ 	nop
/*  f0db2d8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db2dc:	11c00012 */ 	beqz	$t6,.L0f0db328
/*  f0db2e0:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db2e4:	44814000 */ 	mtc1	$at,$f8
/*  f0db2e8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db2ec:	46085201 */ 	sub.s	$f8,$f10,$f8
/*  f0db2f0:	44cef800 */ 	ctc1	$t6,$31
/*  f0db2f4:	00000000 */ 	nop
/*  f0db2f8:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0db2fc:	444ef800 */ 	cfc1	$t6,$31
/*  f0db300:	00000000 */ 	nop
/*  f0db304:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db308:	15c00005 */ 	bnez	$t6,.L0f0db320
/*  f0db30c:	00000000 */ 	nop
/*  f0db310:	440e4000 */ 	mfc1	$t6,$f8
/*  f0db314:	3c018000 */ 	lui	$at,0x8000
/*  f0db318:	10000007 */ 	b	.L0f0db338
/*  f0db31c:	01c17025 */ 	or	$t6,$t6,$at
.L0f0db320:
/*  f0db320:	10000005 */ 	b	.L0f0db338
/*  f0db324:	240effff */ 	addiu	$t6,$zero,-1
.L0f0db328:
/*  f0db328:	440e4000 */ 	mfc1	$t6,$f8
/*  f0db32c:	00000000 */ 	nop
/*  f0db330:	05c0fffb */ 	bltz	$t6,.L0f0db320
/*  f0db334:	00000000 */ 	nop
.L0f0db338:
/*  f0db338:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0db33c:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db340:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0db344:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0db348:	03057025 */ 	or	$t6,$t8,$a1
/*  f0db34c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f0db350:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0db354:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*  f0db358:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0db35c:	44992000 */ 	mtc1	$t9,$f4
/*  f0db360:	00000000 */ 	nop
/*  f0db364:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0db368:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0db36c:	444ff800 */ 	cfc1	$t7,$31
/*  f0db370:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db374:	00000000 */ 	nop
/*  f0db378:	46004124 */ 	cvt.w.s	$f4,$f8
/*  f0db37c:	4458f800 */ 	cfc1	$t8,$31
/*  f0db380:	00000000 */ 	nop
/*  f0db384:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0db388:	13000012 */ 	beqz	$t8,.L0f0db3d4
/*  f0db38c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db390:	44812000 */ 	mtc1	$at,$f4
/*  f0db394:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0db398:	46044101 */ 	sub.s	$f4,$f8,$f4
/*  f0db39c:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db3a0:	00000000 */ 	nop
/*  f0db3a4:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0db3a8:	4458f800 */ 	cfc1	$t8,$31
/*  f0db3ac:	00000000 */ 	nop
/*  f0db3b0:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0db3b4:	17000005 */ 	bnez	$t8,.L0f0db3cc
/*  f0db3b8:	00000000 */ 	nop
/*  f0db3bc:	44182000 */ 	mfc1	$t8,$f4
/*  f0db3c0:	3c018000 */ 	lui	$at,0x8000
/*  f0db3c4:	10000007 */ 	b	.L0f0db3e4
/*  f0db3c8:	0301c025 */ 	or	$t8,$t8,$at
.L0f0db3cc:
/*  f0db3cc:	10000005 */ 	b	.L0f0db3e4
/*  f0db3d0:	2418ffff */ 	addiu	$t8,$zero,-1
.L0f0db3d4:
/*  f0db3d4:	44182000 */ 	mfc1	$t8,$f4
/*  f0db3d8:	00000000 */ 	nop
/*  f0db3dc:	0700fffb */ 	bltz	$t8,.L0f0db3cc
/*  f0db3e0:	00000000 */ 	nop
.L0f0db3e4:
/*  f0db3e4:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0db3e8:	44cff800 */ 	ctc1	$t7,$31
/*  f0db3ec:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0db3f0:	03297825 */ 	or	$t7,$t9,$t1
/*  f0db3f4:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0db3f8:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f0db3fc:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0db400:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0db404:	44983000 */ 	mtc1	$t8,$f6
/*  f0db408:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0db40c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0db410:	460a7202 */ 	mul.s	$f8,$f14,$f10
/*  f0db414:	444ef800 */ 	cfc1	$t6,$31
/*  f0db418:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db41c:	00000000 */ 	nop
/*  f0db420:	46004124 */ 	cvt.w.s	$f4,$f8
/*  f0db424:	4459f800 */ 	cfc1	$t9,$31
/*  f0db428:	00000000 */ 	nop
/*  f0db42c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0db430:	13200012 */ 	beqz	$t9,.L0f0db47c
/*  f0db434:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db438:	44812000 */ 	mtc1	$at,$f4
/*  f0db43c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0db440:	46044101 */ 	sub.s	$f4,$f8,$f4
/*  f0db444:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db448:	00000000 */ 	nop
/*  f0db44c:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0db450:	4459f800 */ 	cfc1	$t9,$31
/*  f0db454:	00000000 */ 	nop
/*  f0db458:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0db45c:	17200005 */ 	bnez	$t9,.L0f0db474
/*  f0db460:	00000000 */ 	nop
/*  f0db464:	44192000 */ 	mfc1	$t9,$f4
/*  f0db468:	3c018000 */ 	lui	$at,0x8000
/*  f0db46c:	10000007 */ 	b	.L0f0db48c
/*  f0db470:	0321c825 */ 	or	$t9,$t9,$at
.L0f0db474:
/*  f0db474:	10000005 */ 	b	.L0f0db48c
/*  f0db478:	2419ffff */ 	addiu	$t9,$zero,-1
.L0f0db47c:
/*  f0db47c:	44192000 */ 	mfc1	$t9,$f4
/*  f0db480:	00000000 */ 	nop
/*  f0db484:	0720fffb */ 	bltz	$t9,.L0f0db474
/*  f0db488:	00000000 */ 	nop
.L0f0db48c:
/*  f0db48c:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0db490:	44cef800 */ 	ctc1	$t6,$31
/*  f0db494:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0db498:	03037025 */ 	or	$t6,$t8,$v1
/*  f0db49c:	01c5c825 */ 	or	$t9,$t6,$a1
/*  f0db4a0:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0db4a4:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0db4a8:	c7a60050 */ 	lwc1	$f6,0x50($sp)
/*  f0db4ac:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db4b0:	448f5000 */ 	mtc1	$t7,$f10
/*  f0db4b4:	00000000 */ 	nop
/*  f0db4b8:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0db4bc:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f0db4c0:	4458f800 */ 	cfc1	$t8,$31
/*  f0db4c4:	44cef800 */ 	ctc1	$t6,$31
/*  f0db4c8:	00000000 */ 	nop
/*  f0db4cc:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0db4d0:	444ef800 */ 	cfc1	$t6,$31
/*  f0db4d4:	00000000 */ 	nop
/*  f0db4d8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db4dc:	11c00012 */ 	beqz	$t6,.L0f0db528
/*  f0db4e0:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db4e4:	44815000 */ 	mtc1	$at,$f10
/*  f0db4e8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db4ec:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0db4f0:	44cef800 */ 	ctc1	$t6,$31
/*  f0db4f4:	00000000 */ 	nop
/*  f0db4f8:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0db4fc:	444ef800 */ 	cfc1	$t6,$31
/*  f0db500:	00000000 */ 	nop
/*  f0db504:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db508:	15c00005 */ 	bnez	$t6,.L0f0db520
/*  f0db50c:	00000000 */ 	nop
/*  f0db510:	440e5000 */ 	mfc1	$t6,$f10
/*  f0db514:	3c018000 */ 	lui	$at,0x8000
/*  f0db518:	10000007 */ 	b	.L0f0db538
/*  f0db51c:	01c17025 */ 	or	$t6,$t6,$at
.L0f0db520:
/*  f0db520:	10000005 */ 	b	.L0f0db538
/*  f0db524:	240effff */ 	addiu	$t6,$zero,-1
.L0f0db528:
/*  f0db528:	440e5000 */ 	mfc1	$t6,$f10
/*  f0db52c:	00000000 */ 	nop
/*  f0db530:	05c0fffb */ 	bltz	$t6,.L0f0db520
/*  f0db534:	00000000 */ 	nop
.L0f0db538:
/*  f0db538:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0db53c:	001f7043 */ 	sra	$t6,$ra,0x1
/*  f0db540:	01c0f825 */ 	or	$ra,$t6,$zero
/*  f0db544:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db548:	449f3000 */ 	mtc1	$ra,$f6
/*  f0db54c:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0db550:	01ebc025 */ 	or	$t8,$t7,$t3
/*  f0db554:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f0db558:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0db55c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0db560:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db564:	000dc843 */ 	sra	$t9,$t5,0x1
/*  f0db568:	448f5000 */ 	mtc1	$t7,$f10
/*  f0db56c:	460c1200 */ 	add.s	$f8,$f2,$f12
/*  f0db570:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0db574:	03206825 */ 	or	$t5,$t9,$zero
/*  f0db578:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f0db57c:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0db580:	46004100 */ 	add.s	$f4,$f8,$f0
/*  f0db584:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0db588:	e7a40028 */ 	swc1	$f4,0x28($sp)
/*  f0db58c:	4458f800 */ 	cfc1	$t8,$31
/*  f0db590:	44cef800 */ 	ctc1	$t6,$31
/*  f0db594:	00000000 */ 	nop
/*  f0db598:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0db59c:	444ef800 */ 	cfc1	$t6,$31
/*  f0db5a0:	00000000 */ 	nop
/*  f0db5a4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db5a8:	11c00012 */ 	beqz	$t6,.L0f0db5f4
/*  f0db5ac:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db5b0:	44815000 */ 	mtc1	$at,$f10
/*  f0db5b4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db5b8:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0db5bc:	44cef800 */ 	ctc1	$t6,$31
/*  f0db5c0:	00000000 */ 	nop
/*  f0db5c4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0db5c8:	444ef800 */ 	cfc1	$t6,$31
/*  f0db5cc:	00000000 */ 	nop
/*  f0db5d0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db5d4:	15c00005 */ 	bnez	$t6,.L0f0db5ec
/*  f0db5d8:	00000000 */ 	nop
/*  f0db5dc:	440e5000 */ 	mfc1	$t6,$f10
/*  f0db5e0:	3c018000 */ 	lui	$at,0x8000
/*  f0db5e4:	10000007 */ 	b	.L0f0db604
/*  f0db5e8:	01c17025 */ 	or	$t6,$t6,$at
.L0f0db5ec:
/*  f0db5ec:	10000005 */ 	b	.L0f0db604
/*  f0db5f0:	240effff */ 	addiu	$t6,$zero,-1
.L0f0db5f4:
/*  f0db5f4:	440e5000 */ 	mfc1	$t6,$f10
/*  f0db5f8:	00000000 */ 	nop
/*  f0db5fc:	05c0fffb */ 	bltz	$t6,.L0f0db5ec
/*  f0db600:	00000000 */ 	nop
.L0f0db604:
/*  f0db604:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0db608:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db60c:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0db610:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0db614:	030a7025 */ 	or	$t6,$t8,$t2
/*  f0db618:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0db61c:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0db620:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0db624:	44992000 */ 	mtc1	$t9,$f4
/*  f0db628:	00000000 */ 	nop
/*  f0db62c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0db630:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f0db634:	444ff800 */ 	cfc1	$t7,$31
/*  f0db638:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db63c:	00000000 */ 	nop
/*  f0db640:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0db644:	4458f800 */ 	cfc1	$t8,$31
/*  f0db648:	00000000 */ 	nop
/*  f0db64c:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0db650:	13000012 */ 	beqz	$t8,.L0f0db69c
/*  f0db654:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db658:	44815000 */ 	mtc1	$at,$f10
/*  f0db65c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0db660:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0db664:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db668:	00000000 */ 	nop
/*  f0db66c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0db670:	4458f800 */ 	cfc1	$t8,$31
/*  f0db674:	00000000 */ 	nop
/*  f0db678:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0db67c:	17000005 */ 	bnez	$t8,.L0f0db694
/*  f0db680:	00000000 */ 	nop
/*  f0db684:	44185000 */ 	mfc1	$t8,$f10
/*  f0db688:	3c018000 */ 	lui	$at,0x8000
/*  f0db68c:	10000007 */ 	b	.L0f0db6ac
/*  f0db690:	0301c025 */ 	or	$t8,$t8,$at
.L0f0db694:
/*  f0db694:	10000005 */ 	b	.L0f0db6ac
/*  f0db698:	2418ffff */ 	addiu	$t8,$zero,-1
.L0f0db69c:
/*  f0db69c:	44185000 */ 	mfc1	$t8,$f10
/*  f0db6a0:	00000000 */ 	nop
/*  f0db6a4:	0700fffb */ 	bltz	$t8,.L0f0db694
/*  f0db6a8:	00000000 */ 	nop
.L0f0db6ac:
/*  f0db6ac:	44cff800 */ 	ctc1	$t7,$31
/*  f0db6b0:	448d2000 */ 	mtc1	$t5,$f4
/*  f0db6b4:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0db6b8:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0db6bc:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f0db6c0:	03277825 */ 	or	$t7,$t9,$a3
/*  f0db6c4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0db6c8:	c7a6004c */ 	lwc1	$f6,0x4c($sp)
/*  f0db6cc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0db6d0:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0db6d4:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f0db6d8:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0db6dc:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f0db6e0:	4458f800 */ 	cfc1	$t8,$31
/*  f0db6e4:	44ccf800 */ 	ctc1	$t4,$31
/*  f0db6e8:	00000000 */ 	nop
/*  f0db6ec:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0db6f0:	444cf800 */ 	cfc1	$t4,$31
/*  f0db6f4:	00000000 */ 	nop
/*  f0db6f8:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f0db6fc:	11800012 */ 	beqz	$t4,.L0f0db748
/*  f0db700:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db704:	44812000 */ 	mtc1	$at,$f4
/*  f0db708:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0db70c:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0db710:	44ccf800 */ 	ctc1	$t4,$31
/*  f0db714:	00000000 */ 	nop
/*  f0db718:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0db71c:	444cf800 */ 	cfc1	$t4,$31
/*  f0db720:	00000000 */ 	nop
/*  f0db724:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f0db728:	15800005 */ 	bnez	$t4,.L0f0db740
/*  f0db72c:	00000000 */ 	nop
/*  f0db730:	440c2000 */ 	mfc1	$t4,$f4
/*  f0db734:	3c018000 */ 	lui	$at,0x8000
/*  f0db738:	10000007 */ 	b	.L0f0db758
/*  f0db73c:	01816025 */ 	or	$t4,$t4,$at
.L0f0db740:
/*  f0db740:	10000005 */ 	b	.L0f0db758
/*  f0db744:	240cffff */ 	addiu	$t4,$zero,-1
.L0f0db748:
/*  f0db748:	440c2000 */ 	mfc1	$t4,$f4
/*  f0db74c:	00000000 */ 	nop
/*  f0db750:	0580fffb */ 	bltz	$t4,.L0f0db740
/*  f0db754:	00000000 */ 	nop
.L0f0db758:
/*  f0db758:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0db75c:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db760:	318e03ff */ 	andi	$t6,$t4,0x3ff
/*  f0db764:	448f3000 */ 	mtc1	$t7,$f6
/*  f0db768:	000e6080 */ 	sll	$t4,$t6,0x2
/*  f0db76c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db770:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0db774:	46088282 */ 	mul.s	$f10,$f16,$f8
/*  f0db778:	4458f800 */ 	cfc1	$t8,$31
/*  f0db77c:	44cef800 */ 	ctc1	$t6,$31
/*  f0db780:	00000000 */ 	nop
/*  f0db784:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0db788:	444ef800 */ 	cfc1	$t6,$31
/*  f0db78c:	00000000 */ 	nop
/*  f0db790:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db794:	11c00012 */ 	beqz	$t6,.L0f0db7e0
/*  f0db798:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db79c:	44812000 */ 	mtc1	$at,$f4
/*  f0db7a0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db7a4:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0db7a8:	44cef800 */ 	ctc1	$t6,$31
/*  f0db7ac:	00000000 */ 	nop
/*  f0db7b0:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0db7b4:	444ef800 */ 	cfc1	$t6,$31
/*  f0db7b8:	00000000 */ 	nop
/*  f0db7bc:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db7c0:	15c00005 */ 	bnez	$t6,.L0f0db7d8
/*  f0db7c4:	00000000 */ 	nop
/*  f0db7c8:	440e2000 */ 	mfc1	$t6,$f4
/*  f0db7cc:	3c018000 */ 	lui	$at,0x8000
/*  f0db7d0:	10000007 */ 	b	.L0f0db7f0
/*  f0db7d4:	01c17025 */ 	or	$t6,$t6,$at
.L0f0db7d8:
/*  f0db7d8:	10000005 */ 	b	.L0f0db7f0
/*  f0db7dc:	240effff */ 	addiu	$t6,$zero,-1
.L0f0db7e0:
/*  f0db7e0:	440e2000 */ 	mfc1	$t6,$f4
/*  f0db7e4:	00000000 */ 	nop
/*  f0db7e8:	05c0fffb */ 	bltz	$t6,.L0f0db7d8
/*  f0db7ec:	00000000 */ 	nop
.L0f0db7f0:
/*  f0db7f0:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0db7f4:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db7f8:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0db7fc:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0db800:	030c7025 */ 	or	$t6,$t8,$t4
/*  f0db804:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f0db808:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0db80c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0db810:	44993000 */ 	mtc1	$t9,$f6
/*  f0db814:	00000000 */ 	nop
/*  f0db818:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0db81c:	46081282 */ 	mul.s	$f10,$f2,$f8
/*  f0db820:	444ff800 */ 	cfc1	$t7,$31
/*  f0db824:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db828:	00000000 */ 	nop
/*  f0db82c:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0db830:	4458f800 */ 	cfc1	$t8,$31
/*  f0db834:	00000000 */ 	nop
/*  f0db838:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0db83c:	13000012 */ 	beqz	$t8,.L0f0db888
/*  f0db840:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db844:	44812000 */ 	mtc1	$at,$f4
/*  f0db848:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0db84c:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0db850:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db854:	00000000 */ 	nop
/*  f0db858:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0db85c:	4458f800 */ 	cfc1	$t8,$31
/*  f0db860:	00000000 */ 	nop
/*  f0db864:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0db868:	17000005 */ 	bnez	$t8,.L0f0db880
/*  f0db86c:	00000000 */ 	nop
/*  f0db870:	44182000 */ 	mfc1	$t8,$f4
/*  f0db874:	3c018000 */ 	lui	$at,0x8000
/*  f0db878:	10000007 */ 	b	.L0f0db898
/*  f0db87c:	0301c025 */ 	or	$t8,$t8,$at
.L0f0db880:
/*  f0db880:	10000005 */ 	b	.L0f0db898
/*  f0db884:	2418ffff */ 	addiu	$t8,$zero,-1
.L0f0db888:
/*  f0db888:	44182000 */ 	mfc1	$t8,$f4
/*  f0db88c:	00000000 */ 	nop
/*  f0db890:	0700fffb */ 	bltz	$t8,.L0f0db880
/*  f0db894:	00000000 */ 	nop
.L0f0db898:
/*  f0db898:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0db89c:	44cff800 */ 	ctc1	$t7,$31
/*  f0db8a0:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0db8a4:	03277825 */ 	or	$t7,$t9,$a3
/*  f0db8a8:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0db8ac:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f0db8b0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0db8b4:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0db8b8:	44983000 */ 	mtc1	$t8,$f6
/*  f0db8bc:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0db8c0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0db8c4:	46087282 */ 	mul.s	$f10,$f14,$f8
/*  f0db8c8:	444ef800 */ 	cfc1	$t6,$31
/*  f0db8cc:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db8d0:	00000000 */ 	nop
/*  f0db8d4:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0db8d8:	4459f800 */ 	cfc1	$t9,$31
/*  f0db8dc:	00000000 */ 	nop
/*  f0db8e0:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0db8e4:	13200012 */ 	beqz	$t9,.L0f0db930
/*  f0db8e8:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db8ec:	44812000 */ 	mtc1	$at,$f4
/*  f0db8f0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0db8f4:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0db8f8:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db8fc:	00000000 */ 	nop
/*  f0db900:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0db904:	4459f800 */ 	cfc1	$t9,$31
/*  f0db908:	00000000 */ 	nop
/*  f0db90c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0db910:	17200005 */ 	bnez	$t9,.L0f0db928
/*  f0db914:	00000000 */ 	nop
/*  f0db918:	44192000 */ 	mfc1	$t9,$f4
/*  f0db91c:	3c018000 */ 	lui	$at,0x8000
/*  f0db920:	10000007 */ 	b	.L0f0db940
/*  f0db924:	0321c825 */ 	or	$t9,$t9,$at
.L0f0db928:
/*  f0db928:	10000005 */ 	b	.L0f0db940
/*  f0db92c:	2419ffff */ 	addiu	$t9,$zero,-1
.L0f0db930:
/*  f0db930:	44192000 */ 	mfc1	$t9,$f4
/*  f0db934:	00000000 */ 	nop
/*  f0db938:	0720fffb */ 	bltz	$t9,.L0f0db928
/*  f0db93c:	00000000 */ 	nop
.L0f0db940:
/*  f0db940:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0db944:	44cef800 */ 	ctc1	$t6,$31
/*  f0db948:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0db94c:	03037025 */ 	or	$t6,$t8,$v1
/*  f0db950:	01cac825 */ 	or	$t9,$t6,$t2
/*  f0db954:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0db958:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0db95c:	c7a60050 */ 	lwc1	$f6,0x50($sp)
/*  f0db960:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db964:	448f4000 */ 	mtc1	$t7,$f8
/*  f0db968:	460c3001 */ 	sub.s	$f0,$f6,$f12
/*  f0db96c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0db970:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f0db974:	4458f800 */ 	cfc1	$t8,$31
/*  f0db978:	44cef800 */ 	ctc1	$t6,$31
/*  f0db97c:	00000000 */ 	nop
/*  f0db980:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f0db984:	444ef800 */ 	cfc1	$t6,$31
/*  f0db988:	00000000 */ 	nop
/*  f0db98c:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db990:	11c00012 */ 	beqz	$t6,.L0f0db9dc
/*  f0db994:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db998:	44813000 */ 	mtc1	$at,$f6
/*  f0db99c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db9a0:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f0db9a4:	44cef800 */ 	ctc1	$t6,$31
/*  f0db9a8:	00000000 */ 	nop
/*  f0db9ac:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0db9b0:	444ef800 */ 	cfc1	$t6,$31
/*  f0db9b4:	00000000 */ 	nop
/*  f0db9b8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db9bc:	15c00005 */ 	bnez	$t6,.L0f0db9d4
/*  f0db9c0:	00000000 */ 	nop
/*  f0db9c4:	440e3000 */ 	mfc1	$t6,$f6
/*  f0db9c8:	3c018000 */ 	lui	$at,0x8000
/*  f0db9cc:	10000007 */ 	b	.L0f0db9ec
/*  f0db9d0:	01c17025 */ 	or	$t6,$t6,$at
.L0f0db9d4:
/*  f0db9d4:	10000005 */ 	b	.L0f0db9ec
/*  f0db9d8:	240effff */ 	addiu	$t6,$zero,-1
.L0f0db9dc:
/*  f0db9dc:	440e3000 */ 	mfc1	$t6,$f6
/*  f0db9e0:	00000000 */ 	nop
/*  f0db9e4:	05c0fffb */ 	bltz	$t6,.L0f0db9d4
/*  f0db9e8:	00000000 */ 	nop
.L0f0db9ec:
/*  f0db9ec:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0db9f0:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db9f4:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0db9f8:	01e7c025 */ 	or	$t8,$t7,$a3
/*  f0db9fc:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0dba00:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0dba04:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dba08:	00c05825 */ 	or	$t3,$a2,$zero
/*  f0dba0c:	448e4000 */ 	mtc1	$t6,$f8
/*  f0dba10:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0dba14:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0dba18:	460a7102 */ 	mul.s	$f4,$f14,$f10
/*  f0dba1c:	4459f800 */ 	cfc1	$t9,$31
/*  f0dba20:	44cff800 */ 	ctc1	$t7,$31
/*  f0dba24:	00000000 */ 	nop
/*  f0dba28:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f0dba2c:	444ff800 */ 	cfc1	$t7,$31
/*  f0dba30:	00000000 */ 	nop
/*  f0dba34:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dba38:	11e00012 */ 	beqz	$t7,.L0f0dba84
/*  f0dba3c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dba40:	44813000 */ 	mtc1	$at,$f6
/*  f0dba44:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dba48:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f0dba4c:	44cff800 */ 	ctc1	$t7,$31
/*  f0dba50:	00000000 */ 	nop
/*  f0dba54:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0dba58:	444ff800 */ 	cfc1	$t7,$31
/*  f0dba5c:	00000000 */ 	nop
/*  f0dba60:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dba64:	15e00005 */ 	bnez	$t7,.L0f0dba7c
/*  f0dba68:	00000000 */ 	nop
/*  f0dba6c:	440f3000 */ 	mfc1	$t7,$f6
/*  f0dba70:	3c018000 */ 	lui	$at,0x8000
/*  f0dba74:	10000007 */ 	b	.L0f0dba94
/*  f0dba78:	01e17825 */ 	or	$t7,$t7,$at
.L0f0dba7c:
/*  f0dba7c:	10000005 */ 	b	.L0f0dba94
/*  f0dba80:	240fffff */ 	addiu	$t7,$zero,-1
.L0f0dba84:
/*  f0dba84:	440f3000 */ 	mfc1	$t7,$f6
/*  f0dba88:	00000000 */ 	nop
/*  f0dba8c:	05e0fffb */ 	bltz	$t7,.L0f0dba7c
/*  f0dba90:	00000000 */ 	nop
.L0f0dba94:
/*  f0dba94:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0dba98:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dba9c:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0dbaa0:	01c3c825 */ 	or	$t9,$t6,$v1
/*  f0dbaa4:	032c7825 */ 	or	$t7,$t9,$t4
/*  f0dbaa8:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0dbaac:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f0dbab0:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f0dbab4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0dbab8:	44985000 */ 	mtc1	$t8,$f10
/*  f0dbabc:	00000000 */ 	nop
/*  f0dbac0:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0dbac4:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0dbac8:	444ef800 */ 	cfc1	$t6,$31
/*  f0dbacc:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dbad0:	00000000 */ 	nop
/*  f0dbad4:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f0dbad8:	4459f800 */ 	cfc1	$t9,$31
/*  f0dbadc:	00000000 */ 	nop
/*  f0dbae0:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0dbae4:	13200012 */ 	beqz	$t9,.L0f0dbb30
/*  f0dbae8:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbaec:	44815000 */ 	mtc1	$at,$f10
/*  f0dbaf0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0dbaf4:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f0dbaf8:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dbafc:	00000000 */ 	nop
/*  f0dbb00:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dbb04:	4459f800 */ 	cfc1	$t9,$31
/*  f0dbb08:	00000000 */ 	nop
/*  f0dbb0c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0dbb10:	17200005 */ 	bnez	$t9,.L0f0dbb28
/*  f0dbb14:	00000000 */ 	nop
/*  f0dbb18:	44195000 */ 	mfc1	$t9,$f10
/*  f0dbb1c:	3c018000 */ 	lui	$at,0x8000
/*  f0dbb20:	10000007 */ 	b	.L0f0dbb40
/*  f0dbb24:	0321c825 */ 	or	$t9,$t9,$at
.L0f0dbb28:
/*  f0dbb28:	10000005 */ 	b	.L0f0dbb40
/*  f0dbb2c:	2419ffff */ 	addiu	$t9,$zero,-1
.L0f0dbb30:
/*  f0dbb30:	44195000 */ 	mfc1	$t9,$f10
/*  f0dbb34:	00000000 */ 	nop
/*  f0dbb38:	0720fffb */ 	bltz	$t9,.L0f0dbb28
/*  f0dbb3c:	00000000 */ 	nop
.L0f0dbb40:
/*  f0dbb40:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0dbb44:	44cef800 */ 	ctc1	$t6,$31
/*  f0dbb48:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0dbb4c:	03077025 */ 	or	$t6,$t8,$a3
/*  f0dbb50:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f0dbb54:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0dbb58:	c7a80028 */ 	lwc1	$f8,0x28($sp)
/*  f0dbb5c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dbb60:	44992000 */ 	mtc1	$t9,$f4
/*  f0dbb64:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0dbb68:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0dbb6c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0dbb70:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f0dbb74:	444ff800 */ 	cfc1	$t7,$31
/*  f0dbb78:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dbb7c:	00000000 */ 	nop
/*  f0dbb80:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0dbb84:	4458f800 */ 	cfc1	$t8,$31
/*  f0dbb88:	00000000 */ 	nop
/*  f0dbb8c:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dbb90:	13000012 */ 	beqz	$t8,.L0f0dbbdc
/*  f0dbb94:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbb98:	44812000 */ 	mtc1	$at,$f4
/*  f0dbb9c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dbba0:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0dbba4:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dbba8:	00000000 */ 	nop
/*  f0dbbac:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0dbbb0:	4458f800 */ 	cfc1	$t8,$31
/*  f0dbbb4:	00000000 */ 	nop
/*  f0dbbb8:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dbbbc:	17000005 */ 	bnez	$t8,.L0f0dbbd4
/*  f0dbbc0:	00000000 */ 	nop
/*  f0dbbc4:	44182000 */ 	mfc1	$t8,$f4
/*  f0dbbc8:	3c018000 */ 	lui	$at,0x8000
/*  f0dbbcc:	10000007 */ 	b	.L0f0dbbec
/*  f0dbbd0:	0301c025 */ 	or	$t8,$t8,$at
.L0f0dbbd4:
/*  f0dbbd4:	10000005 */ 	b	.L0f0dbbec
/*  f0dbbd8:	2418ffff */ 	addiu	$t8,$zero,-1
.L0f0dbbdc:
/*  f0dbbdc:	44182000 */ 	mfc1	$t8,$f4
/*  f0dbbe0:	00000000 */ 	nop
/*  f0dbbe4:	0700fffb */ 	bltz	$t8,.L0f0dbbd4
/*  f0dbbe8:	00000000 */ 	nop
.L0f0dbbec:
/*  f0dbbec:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0dbbf0:	44cff800 */ 	ctc1	$t7,$31
/*  f0dbbf4:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0dbbf8:	03237825 */ 	or	$t7,$t9,$v1
/*  f0dbbfc:	01e5c025 */ 	or	$t8,$t7,$a1
/*  f0dbc00:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0dbc04:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0dbc08:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dbc0c:	448e4000 */ 	mtc1	$t6,$f8
/*  f0dbc10:	00000000 */ 	nop
/*  f0dbc14:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0dbc18:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f0dbc1c:	4459f800 */ 	cfc1	$t9,$31
/*  f0dbc20:	44cff800 */ 	ctc1	$t7,$31
/*  f0dbc24:	00000000 */ 	nop
/*  f0dbc28:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0dbc2c:	444ff800 */ 	cfc1	$t7,$31
/*  f0dbc30:	00000000 */ 	nop
/*  f0dbc34:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dbc38:	11e00012 */ 	beqz	$t7,.L0f0dbc84
/*  f0dbc3c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbc40:	44812000 */ 	mtc1	$at,$f4
/*  f0dbc44:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dbc48:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0dbc4c:	44cff800 */ 	ctc1	$t7,$31
/*  f0dbc50:	00000000 */ 	nop
/*  f0dbc54:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0dbc58:	444ff800 */ 	cfc1	$t7,$31
/*  f0dbc5c:	00000000 */ 	nop
/*  f0dbc60:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dbc64:	15e00005 */ 	bnez	$t7,.L0f0dbc7c
/*  f0dbc68:	00000000 */ 	nop
/*  f0dbc6c:	440f2000 */ 	mfc1	$t7,$f4
/*  f0dbc70:	3c018000 */ 	lui	$at,0x8000
/*  f0dbc74:	10000007 */ 	b	.L0f0dbc94
/*  f0dbc78:	01e17825 */ 	or	$t7,$t7,$at
.L0f0dbc7c:
/*  f0dbc7c:	10000005 */ 	b	.L0f0dbc94
/*  f0dbc80:	240fffff */ 	addiu	$t7,$zero,-1
.L0f0dbc84:
/*  f0dbc84:	440f2000 */ 	mfc1	$t7,$f4
/*  f0dbc88:	00000000 */ 	nop
/*  f0dbc8c:	05e0fffb */ 	bltz	$t7,.L0f0dbc7c
/*  f0dbc90:	00000000 */ 	nop
.L0f0dbc94:
/*  f0dbc94:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0dbc98:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dbc9c:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0dbca0:	01c9c825 */ 	or	$t9,$t6,$t1
/*  f0dbca4:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0dbca8:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0dbcac:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dbcb0:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0dbcb4:	448f4000 */ 	mtc1	$t7,$f8
/*  f0dbcb8:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0dbcbc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbcc0:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0dbcc4:	46068282 */ 	mul.s	$f10,$f16,$f6
/*  f0dbcc8:	4458f800 */ 	cfc1	$t8,$31
/*  f0dbccc:	44cef800 */ 	ctc1	$t6,$31
/*  f0dbcd0:	00000000 */ 	nop
/*  f0dbcd4:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0dbcd8:	444ef800 */ 	cfc1	$t6,$31
/*  f0dbcdc:	00000000 */ 	nop
/*  f0dbce0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dbce4:	51c00013 */ 	beqzl	$t6,.L0f0dbd34
/*  f0dbce8:	440e2000 */ 	mfc1	$t6,$f4
/*  f0dbcec:	44812000 */ 	mtc1	$at,$f4
/*  f0dbcf0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dbcf4:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0dbcf8:	44cef800 */ 	ctc1	$t6,$31
/*  f0dbcfc:	00000000 */ 	nop
/*  f0dbd00:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0dbd04:	444ef800 */ 	cfc1	$t6,$31
/*  f0dbd08:	00000000 */ 	nop
/*  f0dbd0c:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dbd10:	15c00005 */ 	bnez	$t6,.L0f0dbd28
/*  f0dbd14:	00000000 */ 	nop
/*  f0dbd18:	440e2000 */ 	mfc1	$t6,$f4
/*  f0dbd1c:	3c018000 */ 	lui	$at,0x8000
/*  f0dbd20:	10000007 */ 	b	.L0f0dbd40
/*  f0dbd24:	01c17025 */ 	or	$t6,$t6,$at
.L0f0dbd28:
/*  f0dbd28:	10000005 */ 	b	.L0f0dbd40
/*  f0dbd2c:	240effff */ 	addiu	$t6,$zero,-1
/*  f0dbd30:	440e2000 */ 	mfc1	$t6,$f4
.L0f0dbd34:
/*  f0dbd34:	00000000 */ 	nop
/*  f0dbd38:	05c0fffb */ 	bltz	$t6,.L0f0dbd28
/*  f0dbd3c:	00000000 */ 	nop
.L0f0dbd40:
/*  f0dbd40:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0dbd44:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dbd48:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0dbd4c:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0dbd50:	03057025 */ 	or	$t6,$t8,$a1
/*  f0dbd54:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0dbd58:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f0dbd5c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0dbd60:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbd64:	46124181 */ 	sub.s	$f6,$f8,$f18
/*  f0dbd68:	4459f800 */ 	cfc1	$t9,$31
/*  f0dbd6c:	44caf800 */ 	ctc1	$t2,$31
/*  f0dbd70:	00000000 */ 	nop
/*  f0dbd74:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f0dbd78:	444af800 */ 	cfc1	$t2,$31
/*  f0dbd7c:	00000000 */ 	nop
/*  f0dbd80:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0dbd84:	51400013 */ 	beqzl	$t2,.L0f0dbdd4
/*  f0dbd88:	440a5000 */ 	mfc1	$t2,$f10
/*  f0dbd8c:	44815000 */ 	mtc1	$at,$f10
/*  f0dbd90:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0dbd94:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f0dbd98:	44caf800 */ 	ctc1	$t2,$31
/*  f0dbd9c:	00000000 */ 	nop
/*  f0dbda0:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dbda4:	444af800 */ 	cfc1	$t2,$31
/*  f0dbda8:	00000000 */ 	nop
/*  f0dbdac:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0dbdb0:	15400005 */ 	bnez	$t2,.L0f0dbdc8
/*  f0dbdb4:	00000000 */ 	nop
/*  f0dbdb8:	440a5000 */ 	mfc1	$t2,$f10
/*  f0dbdbc:	3c018000 */ 	lui	$at,0x8000
/*  f0dbdc0:	10000007 */ 	b	.L0f0dbde0
/*  f0dbdc4:	01415025 */ 	or	$t2,$t2,$at
.L0f0dbdc8:
/*  f0dbdc8:	10000005 */ 	b	.L0f0dbde0
/*  f0dbdcc:	240affff */ 	addiu	$t2,$zero,-1
/*  f0dbdd0:	440a5000 */ 	mfc1	$t2,$f10
.L0f0dbdd4:
/*  f0dbdd4:	00000000 */ 	nop
/*  f0dbdd8:	0540fffb */ 	bltz	$t2,.L0f0dbdc8
/*  f0dbddc:	00000000 */ 	nop
.L0f0dbde0:
/*  f0dbde0:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0dbde4:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dbde8:	314f03ff */ 	andi	$t7,$t2,0x3ff
/*  f0dbdec:	448e2000 */ 	mtc1	$t6,$f4
/*  f0dbdf0:	000f5080 */ 	sll	$t2,$t7,0x2
/*  f0dbdf4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dbdf8:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0dbdfc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbe00:	46081182 */ 	mul.s	$f6,$f2,$f8
/*  f0dbe04:	4459f800 */ 	cfc1	$t9,$31
/*  f0dbe08:	44cff800 */ 	ctc1	$t7,$31
/*  f0dbe0c:	00000000 */ 	nop
/*  f0dbe10:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f0dbe14:	444ff800 */ 	cfc1	$t7,$31
/*  f0dbe18:	00000000 */ 	nop
/*  f0dbe1c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dbe20:	51e00013 */ 	beqzl	$t7,.L0f0dbe70
/*  f0dbe24:	440f5000 */ 	mfc1	$t7,$f10
/*  f0dbe28:	44815000 */ 	mtc1	$at,$f10
/*  f0dbe2c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dbe30:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f0dbe34:	44cff800 */ 	ctc1	$t7,$31
/*  f0dbe38:	00000000 */ 	nop
/*  f0dbe3c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dbe40:	444ff800 */ 	cfc1	$t7,$31
/*  f0dbe44:	00000000 */ 	nop
/*  f0dbe48:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dbe4c:	15e00005 */ 	bnez	$t7,.L0f0dbe64
/*  f0dbe50:	00000000 */ 	nop
/*  f0dbe54:	440f5000 */ 	mfc1	$t7,$f10
/*  f0dbe58:	3c018000 */ 	lui	$at,0x8000
/*  f0dbe5c:	10000007 */ 	b	.L0f0dbe7c
/*  f0dbe60:	01e17825 */ 	or	$t7,$t7,$at
.L0f0dbe64:
/*  f0dbe64:	10000005 */ 	b	.L0f0dbe7c
/*  f0dbe68:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0dbe6c:	440f5000 */ 	mfc1	$t7,$f10
.L0f0dbe70:
/*  f0dbe70:	00000000 */ 	nop
/*  f0dbe74:	05e0fffb */ 	bltz	$t7,.L0f0dbe64
/*  f0dbe78:	00000000 */ 	nop
.L0f0dbe7c:
/*  f0dbe7c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0dbe80:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dbe84:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0dbe88:	01cac825 */ 	or	$t9,$t6,$t2
/*  f0dbe8c:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0dbe90:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0dbe94:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dbe98:	00c03825 */ 	or	$a3,$a2,$zero
/*  f0dbe9c:	448f2000 */ 	mtc1	$t7,$f4
/*  f0dbea0:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0dbea4:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbea8:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0dbeac:	46087182 */ 	mul.s	$f6,$f14,$f8
/*  f0dbeb0:	4458f800 */ 	cfc1	$t8,$31
/*  f0dbeb4:	44cef800 */ 	ctc1	$t6,$31
/*  f0dbeb8:	00000000 */ 	nop
/*  f0dbebc:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f0dbec0:	444ef800 */ 	cfc1	$t6,$31
/*  f0dbec4:	00000000 */ 	nop
/*  f0dbec8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dbecc:	51c00013 */ 	beqzl	$t6,.L0f0dbf1c
/*  f0dbed0:	440e5000 */ 	mfc1	$t6,$f10
/*  f0dbed4:	44815000 */ 	mtc1	$at,$f10
/*  f0dbed8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dbedc:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f0dbee0:	44cef800 */ 	ctc1	$t6,$31
/*  f0dbee4:	00000000 */ 	nop
/*  f0dbee8:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dbeec:	444ef800 */ 	cfc1	$t6,$31
/*  f0dbef0:	00000000 */ 	nop
/*  f0dbef4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dbef8:	15c00005 */ 	bnez	$t6,.L0f0dbf10
/*  f0dbefc:	00000000 */ 	nop
/*  f0dbf00:	440e5000 */ 	mfc1	$t6,$f10
/*  f0dbf04:	3c018000 */ 	lui	$at,0x8000
/*  f0dbf08:	10000007 */ 	b	.L0f0dbf28
/*  f0dbf0c:	01c17025 */ 	or	$t6,$t6,$at
.L0f0dbf10:
/*  f0dbf10:	10000005 */ 	b	.L0f0dbf28
/*  f0dbf14:	240effff */ 	addiu	$t6,$zero,-1
/*  f0dbf18:	440e5000 */ 	mfc1	$t6,$f10
.L0f0dbf1c:
/*  f0dbf1c:	00000000 */ 	nop
/*  f0dbf20:	05c0fffb */ 	bltz	$t6,.L0f0dbf10
/*  f0dbf24:	00000000 */ 	nop
.L0f0dbf28:
/*  f0dbf28:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0dbf2c:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dbf30:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0dbf34:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0dbf38:	03057025 */ 	or	$t6,$t8,$a1
/*  f0dbf3c:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f0dbf40:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0dbf44:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dbf48:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbf4c:	44992000 */ 	mtc1	$t9,$f4
/*  f0dbf50:	00000000 */ 	nop
/*  f0dbf54:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0dbf58:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f0dbf5c:	444ff800 */ 	cfc1	$t7,$31
/*  f0dbf60:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dbf64:	00000000 */ 	nop
/*  f0dbf68:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f0dbf6c:	4458f800 */ 	cfc1	$t8,$31
/*  f0dbf70:	00000000 */ 	nop
/*  f0dbf74:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dbf78:	53000013 */ 	beqzl	$t8,.L0f0dbfc8
/*  f0dbf7c:	44185000 */ 	mfc1	$t8,$f10
/*  f0dbf80:	44815000 */ 	mtc1	$at,$f10
/*  f0dbf84:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dbf88:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f0dbf8c:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dbf90:	00000000 */ 	nop
/*  f0dbf94:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dbf98:	4458f800 */ 	cfc1	$t8,$31
/*  f0dbf9c:	00000000 */ 	nop
/*  f0dbfa0:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dbfa4:	17000005 */ 	bnez	$t8,.L0f0dbfbc
/*  f0dbfa8:	00000000 */ 	nop
/*  f0dbfac:	44185000 */ 	mfc1	$t8,$f10
/*  f0dbfb0:	3c018000 */ 	lui	$at,0x8000
/*  f0dbfb4:	10000007 */ 	b	.L0f0dbfd4
/*  f0dbfb8:	0301c025 */ 	or	$t8,$t8,$at
.L0f0dbfbc:
/*  f0dbfbc:	10000005 */ 	b	.L0f0dbfd4
/*  f0dbfc0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0dbfc4:	44185000 */ 	mfc1	$t8,$f10
.L0f0dbfc8:
/*  f0dbfc8:	00000000 */ 	nop
/*  f0dbfcc:	0700fffb */ 	bltz	$t8,.L0f0dbfbc
/*  f0dbfd0:	00000000 */ 	nop
.L0f0dbfd4:
/*  f0dbfd4:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0dbfd8:	44cff800 */ 	ctc1	$t7,$31
/*  f0dbfdc:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0dbfe0:	03297825 */ 	or	$t7,$t9,$t1
/*  f0dbfe4:	acef0004 */ 	sw	$t7,0x4($a3)
/*  f0dbfe8:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f0dbfec:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0dbff0:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0dbff4:	44982000 */ 	mtc1	$t8,$f4
/*  f0dbff8:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0dbffc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dc000:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0dc004:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0dc008:	46087182 */ 	mul.s	$f6,$f14,$f8
/*  f0dc00c:	444ef800 */ 	cfc1	$t6,$31
/*  f0dc010:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dc014:	00000000 */ 	nop
/*  f0dc018:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f0dc01c:	4459f800 */ 	cfc1	$t9,$31
/*  f0dc020:	00000000 */ 	nop
/*  f0dc024:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0dc028:	53200013 */ 	beqzl	$t9,.L0f0dc078
/*  f0dc02c:	44195000 */ 	mfc1	$t9,$f10
/*  f0dc030:	44815000 */ 	mtc1	$at,$f10
/*  f0dc034:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0dc038:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f0dc03c:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dc040:	00000000 */ 	nop
/*  f0dc044:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dc048:	4459f800 */ 	cfc1	$t9,$31
/*  f0dc04c:	00000000 */ 	nop
/*  f0dc050:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0dc054:	17200005 */ 	bnez	$t9,.L0f0dc06c
/*  f0dc058:	00000000 */ 	nop
/*  f0dc05c:	44195000 */ 	mfc1	$t9,$f10
/*  f0dc060:	3c018000 */ 	lui	$at,0x8000
/*  f0dc064:	10000007 */ 	b	.L0f0dc084
/*  f0dc068:	0321c825 */ 	or	$t9,$t9,$at
.L0f0dc06c:
/*  f0dc06c:	10000005 */ 	b	.L0f0dc084
/*  f0dc070:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0dc074:	44195000 */ 	mfc1	$t9,$f10
.L0f0dc078:
/*  f0dc078:	00000000 */ 	nop
/*  f0dc07c:	0720fffb */ 	bltz	$t9,.L0f0dc06c
/*  f0dc080:	00000000 */ 	nop
.L0f0dc084:
/*  f0dc084:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0dc088:	44cef800 */ 	ctc1	$t6,$31
/*  f0dc08c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0dc090:	03037025 */ 	or	$t6,$t8,$v1
/*  f0dc094:	01c5c825 */ 	or	$t9,$t6,$a1
/*  f0dc098:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0dc09c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0dc0a0:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f0dc0a4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dc0a8:	448f4000 */ 	mtc1	$t7,$f8
/*  f0dc0ac:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dc0b0:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0dc0b4:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f0dc0b8:	4458f800 */ 	cfc1	$t8,$31
/*  f0dc0bc:	44cef800 */ 	ctc1	$t6,$31
/*  f0dc0c0:	00000000 */ 	nop
/*  f0dc0c4:	46005224 */ 	cvt.w.s	$f8,$f10
/*  f0dc0c8:	444ef800 */ 	cfc1	$t6,$31
/*  f0dc0cc:	00000000 */ 	nop
/*  f0dc0d0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dc0d4:	51c00013 */ 	beqzl	$t6,.L0f0dc124
/*  f0dc0d8:	440e4000 */ 	mfc1	$t6,$f8
/*  f0dc0dc:	44814000 */ 	mtc1	$at,$f8
/*  f0dc0e0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dc0e4:	46085201 */ 	sub.s	$f8,$f10,$f8
/*  f0dc0e8:	44cef800 */ 	ctc1	$t6,$31
/*  f0dc0ec:	00000000 */ 	nop
/*  f0dc0f0:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0dc0f4:	444ef800 */ 	cfc1	$t6,$31
/*  f0dc0f8:	00000000 */ 	nop
/*  f0dc0fc:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dc100:	15c00005 */ 	bnez	$t6,.L0f0dc118
/*  f0dc104:	00000000 */ 	nop
/*  f0dc108:	440e4000 */ 	mfc1	$t6,$f8
/*  f0dc10c:	3c018000 */ 	lui	$at,0x8000
/*  f0dc110:	10000007 */ 	b	.L0f0dc130
/*  f0dc114:	01c17025 */ 	or	$t6,$t6,$at
.L0f0dc118:
/*  f0dc118:	10000005 */ 	b	.L0f0dc130
/*  f0dc11c:	240effff */ 	addiu	$t6,$zero,-1
/*  f0dc120:	440e4000 */ 	mfc1	$t6,$f8
.L0f0dc124:
/*  f0dc124:	00000000 */ 	nop
/*  f0dc128:	05c0fffb */ 	bltz	$t6,.L0f0dc118
/*  f0dc12c:	00000000 */ 	nop
.L0f0dc130:
/*  f0dc130:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0dc134:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0dc138:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dc13c:	01eac025 */ 	or	$t8,$t7,$t2
/*  f0dc140:	0fc54e0e */ 	jal	func0f153838
/*  f0dc144:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0dc148:	0fc54de0 */ 	jal	func0f153780
/*  f0dc14c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0dc150:	00403025 */ 	or	$a2,$v0,$zero
.L0f0dc154:
/*  f0dc154:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0dc158:	0fc363de */ 	jal	sightRenderDefault
/*  f0dc15c:	8fa50104 */ 	lw	$a1,0x104($sp)
/*  f0dc160:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0dc164:	27bd0100 */ 	addiu	$sp,$sp,0x100
/*  f0dc168:	03e00008 */ 	jr	$ra
/*  f0dc16c:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel sightRenderMaian
/*  f0dc170:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f0dc174:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f0dc178:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f0dc17c:	00808025 */ 	or	$s0,$a0,$zero
/*  f0dc180:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f0dc184:	0c002f40 */ 	jal	viGetViewLeft
/*  f0dc188:	afa500b4 */ 	sw	$a1,0xb4($sp)
/*  f0dc18c:	3c118008 */ 	lui	$s1,%hi(g_ScaleX)
/*  f0dc190:	2631fac0 */ 	addiu	$s1,$s1,%lo(g_ScaleX)
/*  f0dc194:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0dc198:	004e001a */ 	div	$zero,$v0,$t6
/*  f0dc19c:	00007812 */ 	mflo	$t7
/*  f0dc1a0:	afaf00ac */ 	sw	$t7,0xac($sp)
/*  f0dc1a4:	15c00002 */ 	bnez	$t6,.L0f0dc1b0
/*  f0dc1a8:	00000000 */ 	nop
/*  f0dc1ac:	0007000d */ 	break	0x7
.L0f0dc1b0:
/*  f0dc1b0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0dc1b4:	15c10004 */ 	bne	$t6,$at,.L0f0dc1c8
/*  f0dc1b8:	3c018000 */ 	lui	$at,0x8000
/*  f0dc1bc:	14410002 */ 	bne	$v0,$at,.L0f0dc1c8
/*  f0dc1c0:	00000000 */ 	nop
/*  f0dc1c4:	0006000d */ 	break	0x6
.L0f0dc1c8:
/*  f0dc1c8:	0c002f44 */ 	jal	viGetViewTop
/*  f0dc1cc:	00000000 */ 	nop
/*  f0dc1d0:	0c002f22 */ 	jal	viGetViewWidth
/*  f0dc1d4:	afa200a8 */ 	sw	$v0,0xa8($sp)
/*  f0dc1d8:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0dc1dc:	0058001a */ 	div	$zero,$v0,$t8
/*  f0dc1e0:	0000c812 */ 	mflo	$t9
/*  f0dc1e4:	afb900a4 */ 	sw	$t9,0xa4($sp)
/*  f0dc1e8:	17000002 */ 	bnez	$t8,.L0f0dc1f4
/*  f0dc1ec:	00000000 */ 	nop
/*  f0dc1f0:	0007000d */ 	break	0x7
.L0f0dc1f4:
/*  f0dc1f4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0dc1f8:	17010004 */ 	bne	$t8,$at,.L0f0dc20c
/*  f0dc1fc:	3c018000 */ 	lui	$at,0x8000
/*  f0dc200:	14410002 */ 	bne	$v0,$at,.L0f0dc20c
/*  f0dc204:	00000000 */ 	nop
/*  f0dc208:	0006000d */ 	break	0x6
.L0f0dc20c:
/*  f0dc20c:	0c002f26 */ 	jal	viGetViewHeight
/*  f0dc210:	00000000 */ 	nop
/*  f0dc214:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f0dc218:	3c03800a */ 	lui	$v1,%hi(g_Vars+0x284)
/*  f0dc21c:	8c63a244 */ 	lw	$v1,%lo(g_Vars+0x284)($v1)
/*  f0dc220:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f0dc224:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f0dc228:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0dc22c:	afb80098 */ 	sw	$t8,0x98($sp)
/*  f0dc230:	c4641660 */ 	lwc1	$f4,0x1660($v1)
/*  f0dc234:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f0dc238:	3c19ff00 */ 	lui	$t9,0xff00
/*  f0dc23c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0dc240:	37390060 */ 	ori	$t9,$t9,0x60
/*  f0dc244:	440e3000 */ 	mfc1	$t6,$f6
/*  f0dc248:	00000000 */ 	nop
/*  f0dc24c:	01cf001a */ 	div	$zero,$t6,$t7
/*  f0dc250:	0000c012 */ 	mflo	$t8
/*  f0dc254:	afb80094 */ 	sw	$t8,0x94($sp)
/*  f0dc258:	c4681664 */ 	lwc1	$f8,0x1664($v1)
/*  f0dc25c:	15e00002 */ 	bnez	$t7,.L0f0dc268
/*  f0dc260:	00000000 */ 	nop
/*  f0dc264:	0007000d */ 	break	0x7
.L0f0dc268:
/*  f0dc268:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0dc26c:	15e10004 */ 	bne	$t7,$at,.L0f0dc280
/*  f0dc270:	3c018000 */ 	lui	$at,0x8000
/*  f0dc274:	15c10002 */ 	bne	$t6,$at,.L0f0dc280
/*  f0dc278:	00000000 */ 	nop
/*  f0dc27c:	0006000d */ 	break	0x6
.L0f0dc280:
/*  f0dc280:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0dc284:	440e5000 */ 	mfc1	$t6,$f10
/*  f0dc288:	00000000 */ 	nop
/*  f0dc28c:	afae0090 */ 	sw	$t6,0x90($sp)
/*  f0dc290:	8c6f1624 */ 	lw	$t7,0x1624($v1)
/*  f0dc294:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f0dc298:	afb90070 */ 	sw	$t9,0x70($sp)
/*  f0dc29c:	000fc02b */ 	sltu	$t8,$zero,$t7
/*  f0dc2a0:	15c00003 */ 	bnez	$t6,.L0f0dc2b0
/*  f0dc2a4:	afb80074 */ 	sw	$t8,0x74($sp)
/*  f0dc2a8:	10000109 */ 	b	.L0f0dc6d0
/*  f0dc2ac:	02001025 */ 	or	$v0,$s0,$zero
.L0f0dc2b0:
/*  f0dc2b0:	0fc35c1c */ 	jal	sightIsPropFriendly
/*  f0dc2b4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0dc2b8:	10400002 */ 	beqz	$v0,.L0f0dc2c4
/*  f0dc2bc:	340fff60 */ 	dli	$t7,0xff60
/*  f0dc2c0:	afaf0070 */ 	sw	$t7,0x70($sp)
.L0f0dc2c4:
/*  f0dc2c4:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f0dc2c8:	24040008 */ 	addiu	$a0,$zero,0x8
/*  f0dc2cc:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f0dc2d0:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f0dc2d4:	afa2008c */ 	sw	$v0,0x8c($sp)
/*  f0dc2d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0dc2dc:	0fc351e7 */ 	jal	func0f0d479c
/*  f0dc2e0:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f0dc2e4:	8fa3008c */ 	lw	$v1,0x8c($sp)
/*  f0dc2e8:	8fa70088 */ 	lw	$a3,0x88($sp)
/*  f0dc2ec:	8fa800ac */ 	lw	$t0,0xac($sp)
/*  f0dc2f0:	8fab00a4 */ 	lw	$t3,0xa4($sp)
/*  f0dc2f4:	3c18b600 */ 	lui	$t8,0xb600
/*  f0dc2f8:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0dc2fc:	3c18fcff */ 	lui	$t8,0xfcff
/*  f0dc300:	240f0204 */ 	addiu	$t7,$zero,0x204
/*  f0dc304:	3718ffff */ 	ori	$t8,$t8,0xffff
/*  f0dc308:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f0dc30c:	ac580010 */ 	sw	$t8,0x10($v0)
/*  f0dc310:	240f2000 */ 	addiu	$t7,$zero,0x2000
/*  f0dc314:	3c18ba00 */ 	lui	$t8,0xba00
/*  f0dc318:	ac4f001c */ 	sw	$t7,0x1c($v0)
/*  f0dc31c:	37181402 */ 	ori	$t8,$t8,0x1402
/*  f0dc320:	ac580020 */ 	sw	$t8,0x20($v0)
/*  f0dc324:	000b7843 */ 	sra	$t7,$t3,0x1
/*  f0dc328:	2404000a */ 	addiu	$a0,$zero,0xa
/*  f0dc32c:	01e8c021 */ 	addu	$t8,$t7,$t0
/*  f0dc330:	03040019 */ 	multu	$t8,$a0
/*  f0dc334:	24193000 */ 	addiu	$t9,$zero,0x3000
/*  f0dc338:	3c0eb700 */ 	lui	$t6,0xb700
/*  f0dc33c:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0dc340:	ac4e0008 */ 	sw	$t6,0x8($v0)
/*  f0dc344:	3c19fffe */ 	lui	$t9,0xfffe
/*  f0dc348:	3c0eba00 */ 	lui	$t6,0xba00
/*  f0dc34c:	3739793c */ 	ori	$t9,$t9,0x793c
/*  f0dc350:	35ce0c02 */ 	ori	$t6,$t6,0xc02
/*  f0dc354:	ac590014 */ 	sw	$t9,0x14($v0)
/*  f0dc358:	ac4e0018 */ 	sw	$t6,0x18($v0)
/*  f0dc35c:	3c0e0050 */ 	lui	$t6,0x50
/*  f0dc360:	3c19b900 */ 	lui	$t9,0xb900
/*  f0dc364:	3739031d */ 	ori	$t9,$t9,0x31d
/*  f0dc368:	35ce41c8 */ 	ori	$t6,$t6,0x41c8
/*  f0dc36c:	00003012 */ 	mflo	$a2
/*  f0dc370:	ac400024 */ 	sw	$zero,0x24($v0)
/*  f0dc374:	ac4e002c */ 	sw	$t6,0x2c($v0)
/*  f0dc378:	ac590028 */ 	sw	$t9,0x28($v0)
/*  f0dc37c:	a4660000 */ 	sh	$a2,0x0($v1)
/*  f0dc380:	8fb900a8 */ 	lw	$t9,0xa8($sp)
/*  f0dc384:	2405fff6 */ 	addiu	$a1,$zero,-10
/*  f0dc388:	a4650004 */ 	sh	$a1,0x4($v1)
/*  f0dc38c:	03240019 */ 	multu	$t9,$a0
/*  f0dc390:	a466000c */ 	sh	$a2,0xc($v1)
/*  f0dc394:	244a0030 */ 	addiu	$t2,$v0,0x30
/*  f0dc398:	25500008 */ 	addiu	$s0,$t2,0x8
/*  f0dc39c:	00007012 */ 	mflo	$t6
/*  f0dc3a0:	25cf0064 */ 	addiu	$t7,$t6,0x64
/*  f0dc3a4:	a46f0002 */ 	sh	$t7,0x2($v1)
/*  f0dc3a8:	8fb80098 */ 	lw	$t8,0x98($sp)
/*  f0dc3ac:	a4650010 */ 	sh	$a1,0x10($v1)
/*  f0dc3b0:	03040019 */ 	multu	$t8,$a0
/*  f0dc3b4:	0000c812 */ 	mflo	$t9
/*  f0dc3b8:	272eff9c */ 	addiu	$t6,$t9,-100
/*  f0dc3bc:	a46e000e */ 	sh	$t6,0xe($v1)
/*  f0dc3c0:	01040019 */ 	multu	$t0,$a0
/*  f0dc3c4:	00007812 */ 	mflo	$t7
/*  f0dc3c8:	25f801e0 */ 	addiu	$t8,$t7,0x1e0
/*  f0dc3cc:	a4780018 */ 	sh	$t8,0x18($v1)
/*  f0dc3d0:	8fb900a0 */ 	lw	$t9,0xa0($sp)
/*  f0dc3d4:	8faf00a8 */ 	lw	$t7,0xa8($sp)
/*  f0dc3d8:	a465001c */ 	sh	$a1,0x1c($v1)
/*  f0dc3dc:	00197043 */ 	sra	$t6,$t9,0x1
/*  f0dc3e0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f0dc3e4:	03040019 */ 	multu	$t8,$a0
/*  f0dc3e8:	010bc821 */ 	addu	$t9,$t0,$t3
/*  f0dc3ec:	272effff */ 	addiu	$t6,$t9,-1
/*  f0dc3f0:	00004812 */ 	mflo	$t1
/*  f0dc3f4:	a469001a */ 	sh	$t1,0x1a($v1)
/*  f0dc3f8:	00000000 */ 	nop
/*  f0dc3fc:	01c40019 */ 	multu	$t6,$a0
/*  f0dc400:	00007812 */ 	mflo	$t7
/*  f0dc404:	25f8fe16 */ 	addiu	$t8,$t7,-490
/*  f0dc408:	a4780024 */ 	sh	$t8,0x24($v1)
/*  f0dc40c:	8fa20094 */ 	lw	$v0,0x94($sp)
/*  f0dc410:	8fa60090 */ 	lw	$a2,0x90($sp)
/*  f0dc414:	a4690026 */ 	sh	$t1,0x26($v1)
/*  f0dc418:	2448fffc */ 	addiu	$t0,$v0,-4
/*  f0dc41c:	01040019 */ 	multu	$t0,$a0
/*  f0dc420:	a4650028 */ 	sh	$a1,0x28($v1)
/*  f0dc424:	244b0004 */ 	addiu	$t3,$v0,0x4
/*  f0dc428:	24cc0004 */ 	addiu	$t4,$a2,0x4
/*  f0dc42c:	24cdfffc */ 	addiu	$t5,$a2,-4
/*  f0dc430:	afab0078 */ 	sw	$t3,0x78($sp)
/*  f0dc434:	afa8007c */ 	sw	$t0,0x7c($sp)
/*  f0dc438:	afac0080 */ 	sw	$t4,0x80($sp)
/*  f0dc43c:	afad0084 */ 	sw	$t5,0x84($sp)
/*  f0dc440:	26060008 */ 	addiu	$a2,$s0,0x8
/*  f0dc444:	00007012 */ 	mflo	$t6
/*  f0dc448:	a46e0030 */ 	sh	$t6,0x30($v1)
/*  f0dc44c:	8faf0084 */ 	lw	$t7,0x84($sp)
/*  f0dc450:	a4650034 */ 	sh	$a1,0x34($v1)
/*  f0dc454:	01e40019 */ 	multu	$t7,$a0
/*  f0dc458:	0000c012 */ 	mflo	$t8
/*  f0dc45c:	a4780032 */ 	sh	$t8,0x32($v1)
/*  f0dc460:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f0dc464:	03240019 */ 	multu	$t9,$a0
/*  f0dc468:	00007012 */ 	mflo	$t6
/*  f0dc46c:	a46e003c */ 	sh	$t6,0x3c($v1)
/*  f0dc470:	8faf0084 */ 	lw	$t7,0x84($sp)
/*  f0dc474:	a4650040 */ 	sh	$a1,0x40($v1)
/*  f0dc478:	01e40019 */ 	multu	$t7,$a0
/*  f0dc47c:	0000c012 */ 	mflo	$t8
/*  f0dc480:	a478003e */ 	sh	$t8,0x3e($v1)
/*  f0dc484:	8fb90078 */ 	lw	$t9,0x78($sp)
/*  f0dc488:	03240019 */ 	multu	$t9,$a0
/*  f0dc48c:	00007012 */ 	mflo	$t6
/*  f0dc490:	a46e0048 */ 	sh	$t6,0x48($v1)
/*  f0dc494:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f0dc498:	a465004c */ 	sh	$a1,0x4c($v1)
/*  f0dc49c:	01e40019 */ 	multu	$t7,$a0
/*  f0dc4a0:	0000c012 */ 	mflo	$t8
/*  f0dc4a4:	a478004a */ 	sh	$t8,0x4a($v1)
/*  f0dc4a8:	8fb9007c */ 	lw	$t9,0x7c($sp)
/*  f0dc4ac:	03240019 */ 	multu	$t9,$a0
/*  f0dc4b0:	3c1900ff */ 	lui	$t9,0xff
/*  f0dc4b4:	3739000f */ 	ori	$t9,$t9,0xf
/*  f0dc4b8:	00007012 */ 	mflo	$t6
/*  f0dc4bc:	a46e0054 */ 	sh	$t6,0x54($v1)
/*  f0dc4c0:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f0dc4c4:	a4650058 */ 	sh	$a1,0x58($v1)
/*  f0dc4c8:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f0dc4cc:	01e40019 */ 	multu	$t7,$a0
/*  f0dc4d0:	02002025 */ 	or	$a0,$s0,$zero
/*  f0dc4d4:	0000c012 */ 	mflo	$t8
/*  f0dc4d8:	a4780056 */ 	sh	$t8,0x56($v1)
/*  f0dc4dc:	acf90000 */ 	sw	$t9,0x0($a3)
/*  f0dc4e0:	8fae0074 */ 	lw	$t6,0x74($sp)
/*  f0dc4e4:	3c190704 */ 	lui	$t9,0x704
/*  f0dc4e8:	3c1800ff */ 	lui	$t8,0xff
/*  f0dc4ec:	11c00004 */ 	beqz	$t6,.L0f0dc500
/*  f0dc4f0:	37390008 */ 	ori	$t9,$t9,0x8
/*  f0dc4f4:	8faf0070 */ 	lw	$t7,0x70($sp)
/*  f0dc4f8:	10000003 */ 	b	.L0f0dc508
/*  f0dc4fc:	acef0004 */ 	sw	$t7,0x4($a3)
.L0f0dc500:
/*  f0dc500:	37180044 */ 	ori	$t8,$t8,0x44
/*  f0dc504:	acf80004 */ 	sw	$t8,0x4($a3)
.L0f0dc508:
/*  f0dc508:	a0600007 */ 	sb	$zero,0x7($v1)
/*  f0dc50c:	a0600013 */ 	sb	$zero,0x13($v1)
/*  f0dc510:	a060001f */ 	sb	$zero,0x1f($v1)
/*  f0dc514:	a060002b */ 	sb	$zero,0x2b($v1)
/*  f0dc518:	a0650037 */ 	sb	$a1,0x37($v1)
/*  f0dc51c:	a0650043 */ 	sb	$a1,0x43($v1)
/*  f0dc520:	a065004f */ 	sb	$a1,0x4f($v1)
/*  f0dc524:	a065005b */ 	sb	$a1,0x5b($v1)
/*  f0dc528:	ad470004 */ 	sw	$a3,0x4($t2)
/*  f0dc52c:	ad590000 */ 	sw	$t9,0x0($t2)
/*  f0dc530:	3c0e0470 */ 	lui	$t6,0x470
/*  f0dc534:	35ce0060 */ 	ori	$t6,$t6,0x60
/*  f0dc538:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f0dc53c:	ac830004 */ 	sw	$v1,0x4($a0)
/*  f0dc540:	3c0fb100 */ 	lui	$t7,0xb100
/*  f0dc544:	3c187467 */ 	lui	$t8,0x7467
/*  f0dc548:	37183540 */ 	ori	$t8,$t8,0x3540
/*  f0dc54c:	35ef2165 */ 	ori	$t7,$t7,0x2165
/*  f0dc550:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f0dc554:	acd80004 */ 	sw	$t8,0x4($a2)
/*  f0dc558:	24c40008 */ 	addiu	$a0,$a2,0x8
/*  f0dc55c:	afad0024 */ 	sw	$t5,0x24($sp)
/*  f0dc560:	afac0028 */ 	sw	$t4,0x28($sp)
/*  f0dc564:	afab0030 */ 	sw	$t3,0x30($sp)
/*  f0dc568:	0fc35272 */ 	jal	func0f0d49c8
/*  f0dc56c:	afa8002c */ 	sw	$t0,0x2c($sp)
/*  f0dc570:	3c0500ff */ 	lui	$a1,0xff
/*  f0dc574:	34a50028 */ 	ori	$a1,$a1,0x28
/*  f0dc578:	0fc54df7 */ 	jal	gfxSetPrimColour
/*  f0dc57c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0dc580:	8fa30090 */ 	lw	$v1,0x90($sp)
/*  f0dc584:	8faf0094 */ 	lw	$t7,0x94($sp)
/*  f0dc588:	3c07f600 */ 	lui	$a3,0xf600
/*  f0dc58c:	24630005 */ 	addiu	$v1,$v1,0x5
/*  f0dc590:	307903ff */ 	andi	$t9,$v1,0x3ff
/*  f0dc594:	00191880 */ 	sll	$v1,$t9,0x2
/*  f0dc598:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f0dc59c:	25f8fffd */ 	addiu	$t8,$t7,-3
/*  f0dc5a0:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f0dc5a4:	03190019 */ 	multu	$t8,$t9
/*  f0dc5a8:	8fab0030 */ 	lw	$t3,0x30($sp)
/*  f0dc5ac:	8fac0028 */ 	lw	$t4,0x28($sp)
/*  f0dc5b0:	8fad0024 */ 	lw	$t5,0x24($sp)
/*  f0dc5b4:	24440020 */ 	addiu	$a0,$v0,0x20
/*  f0dc5b8:	31a503ff */ 	andi	$a1,$t5,0x3ff
/*  f0dc5bc:	00007012 */ 	mflo	$t6
/*  f0dc5c0:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0dc5c4:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0dc5c8:	0307c825 */ 	or	$t9,$t8,$a3
/*  f0dc5cc:	03237025 */ 	or	$t6,$t9,$v1
/*  f0dc5d0:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0dc5d4:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0dc5d8:	00057880 */ 	sll	$t7,$a1,0x2
/*  f0dc5dc:	01e02825 */ 	or	$a1,$t7,$zero
/*  f0dc5e0:	01180019 */ 	multu	$t0,$t8
/*  f0dc5e4:	0000c812 */ 	mflo	$t9
/*  f0dc5e8:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0dc5ec:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0dc5f0:	01e5c025 */ 	or	$t8,$t7,$a1
/*  f0dc5f4:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0dc5f8:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f0dc5fc:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f0dc600:	24c60005 */ 	addiu	$a2,$a2,0x5
/*  f0dc604:	00d90019 */ 	multu	$a2,$t9
/*  f0dc608:	00007012 */ 	mflo	$t6
/*  f0dc60c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0dc610:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0dc614:	0307c825 */ 	or	$t9,$t8,$a3
/*  f0dc618:	03237025 */ 	or	$t6,$t9,$v1
/*  f0dc61c:	ac4e0008 */ 	sw	$t6,0x8($v0)
/*  f0dc620:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f0dc624:	016f0019 */ 	multu	$t3,$t7
/*  f0dc628:	0000c012 */ 	mflo	$t8
/*  f0dc62c:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0dc630:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0dc634:	01c57825 */ 	or	$t7,$t6,$a1
/*  f0dc638:	ac4f000c */ 	sw	$t7,0xc($v0)
/*  f0dc63c:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0dc640:	00d80019 */ 	multu	$a2,$t8
/*  f0dc644:	0000c812 */ 	mflo	$t9
/*  f0dc648:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0dc64c:	8fb90090 */ 	lw	$t9,0x90($sp)
/*  f0dc650:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0dc654:	01e7c025 */ 	or	$t8,$t7,$a3
/*  f0dc658:	272efffd */ 	addiu	$t6,$t9,-3
/*  f0dc65c:	31cf03ff */ 	andi	$t7,$t6,0x3ff
/*  f0dc660:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f0dc664:	03197025 */ 	or	$t6,$t8,$t9
/*  f0dc668:	ac4e0010 */ 	sw	$t6,0x10($v0)
/*  f0dc66c:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f0dc670:	010f0019 */ 	multu	$t0,$t7
/*  f0dc674:	0000c012 */ 	mflo	$t8
/*  f0dc678:	331903ff */ 	andi	$t9,$t8,0x3ff
/*  f0dc67c:	00197380 */ 	sll	$t6,$t9,0xe
/*  f0dc680:	01c57825 */ 	or	$t7,$t6,$a1
/*  f0dc684:	ac4f0014 */ 	sw	$t7,0x14($v0)
/*  f0dc688:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0dc68c:	00d80019 */ 	multu	$a2,$t8
/*  f0dc690:	0000c812 */ 	mflo	$t9
/*  f0dc694:	332e03ff */ 	andi	$t6,$t9,0x3ff
/*  f0dc698:	000e7b80 */ 	sll	$t7,$t6,0xe
/*  f0dc69c:	01e7c025 */ 	or	$t8,$t7,$a3
/*  f0dc6a0:	0303c825 */ 	or	$t9,$t8,$v1
/*  f0dc6a4:	ac590018 */ 	sw	$t9,0x18($v0)
/*  f0dc6a8:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f0dc6ac:	010e0019 */ 	multu	$t0,$t6
/*  f0dc6b0:	318e03ff */ 	andi	$t6,$t4,0x3ff
/*  f0dc6b4:	00007812 */ 	mflo	$t7
/*  f0dc6b8:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0dc6bc:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f0dc6c0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0dc6c4:	032fc025 */ 	or	$t8,$t9,$t7
/*  f0dc6c8:	0fc54e0e */ 	jal	func0f153838
/*  f0dc6cc:	ac58001c */ 	sw	$t8,0x1c($v0)
.L0f0dc6d0:
/*  f0dc6d0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f0dc6d4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f0dc6d8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f0dc6dc:	03e00008 */ 	jr	$ra
/*  f0dc6e0:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);

// Mismatch: Many reordered instructions from around vertices[4] onwards
//Gfx *sightRenderMaian(Gfx *gdl, bool sighton)
//{
//	s32 viewleft = viGetViewLeft() / g_ScaleX; // ac
//	s32 viewtop = viGetViewTop(); // a8
//	s32 viewwidth = viGetViewWidth() / g_ScaleX; // a4
//	s32 viewheight = viGetViewHeight(); // a0
//	s32 viewright = viewleft + viewwidth - 1;
//	s32 viewbottom = viewtop + viewheight - 1; // 98
//
//	s32 x = (s32)g_Vars.currentplayer->crosspos[0] / g_ScaleX; // 94
//	s32 y = g_Vars.currentplayer->crosspos[1]; // 90
//
//	struct gfxvtx *vertices; // 8c
//	u32 *colours; // 88
//
//	s32 innertop = y - 4; // 84
//	s32 innerbottom = y + 4; // 80
//	s32 innerleft = x - 4; // 7c
//	s32 innerright = x + 4; // 78
//
//	bool hasprop = g_Vars.currentplayer->lookingatprop.prop != NULL; // 74
//	u32 colour = 0xff000060; // 70
//	u32 stack;
//	u32 stack2;
//
//	if (!sighton) {
//		return gdl;
//	}
//
//	if (sightIsPropFriendly(NULL)) {
//		colour = 0x0000ff60;
//	}
//
//	vertices = gfxAllocateVertices(8);
//	colours = gfxAllocateColours(2);
//	gdl = func0f0d479c(gdl);
//
//	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
//	gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);
//	gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
//	gDPSetTextureFilter(gdl++, G_TF_BILERP);
//	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
//	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
//
//	vertices[0].x = (viewleft + (viewwidth >> 1)) * 10;
//	vertices[0].y = (viewtop + 10) * 10;
//	vertices[0].z = -10;
//
//	vertices[1].x = (viewleft + (viewwidth >> 1)) * 10;
//	vertices[1].y = (viewbottom - 10) * 10;
//	vertices[1].z = -10;
//
//	vertices[2].x = (viewleft + 48) * 10;
//	vertices[2].y = (viewtop + (viewheight >> 1)) * 10;
//	vertices[2].z = -10;
//
//	vertices[3].x = (viewright - 48) * 10;
//	vertices[3].y = (viewtop + (viewheight >> 1)) * 10;
//	vertices[3].z = -10;
//
//	vertices[4].x = innerleft * 10;
//	vertices[4].y = innertop * 10;
//	vertices[4].z = -10;
//
//	vertices[5].x = innerright * 10;
//	vertices[5].y = innertop * 10;
//	vertices[5].z = -10;
//
//	vertices[6].x = innerright * 10;
//	vertices[6].y = innerbottom * 10;
//	vertices[6].z = -10;
//
//	vertices[7].x = innerleft * 10;
//	vertices[7].y = innerbottom * 10;
//	vertices[7].z = -10;
//
//	vertices[0].s = 0;
//	vertices[1].s = 0;
//	vertices[2].s = 0;
//	vertices[3].s = 0;
//	vertices[4].s = 4;
//	vertices[5].s = 4;
//	vertices[6].s = 4;
//	vertices[7].s = 4;
//
//	colours[0] = 0x00ff000f;
//	colours[1] = hasprop ? colour : 0x00ff0044;
//
//	// Draw the main 4 triangles
//	gDPSetColorArray(gdl++, colours, 2);
//	gDPSetVerticeArray(gdl++, vertices, 8);
//	gDPTri4(gdl++, 0, 4, 5, 5, 3, 6, 7, 6, 1, 4, 7, 2);
//
//	gdl = func0f0d49c8(gdl);
//	gdl = gfxSetPrimColour(gdl, 0x00ff0028);
//
//	// 580
//	// Draw border over inner points
//	gDPFillRectangleScaled(gdl++, x - 4, y - 4, x - 3, y + 5); // left
//	gDPFillRectangleScaled(gdl++, x + 4, y - 4, x + 5, y + 5); // right
//	gDPFillRectangleScaled(gdl++, x - 4, y - 4, x + 5, y - 3); // top
//	gDPFillRectangleScaled(gdl++, x - 4, y + 4, x + 5, y + 5); // bottom
//
//	gdl = func0f153838(gdl);
//
//	return gdl;
//}

Gfx *sightRenderTarget(Gfx *gdl)
{
	s32 x = (s32)g_Vars.currentplayer->crosspos[0] / g_ScaleX;
	s32 y = g_Vars.currentplayer->crosspos[1];

	func0000db30("sout", &var80070f9c);
	func0000db30("sin", &var80070fa0);

	gdl = gfxSetPrimColour(gdl, 0x00ff0028);

	gDPFillRectangleScaled(gdl++, x + 2, y + 0, x + 7, y + 1);
	gDPFillRectangleScaled(gdl++, x + 2, y + 0, x + 5, y + 1);
	gDPFillRectangleScaled(gdl++, x - 6, y + 0, x - 1, y + 1);
	gDPFillRectangleScaled(gdl++, x - 4, y + 0, x - 1, y + 1);
	gDPFillRectangleScaled(gdl++, x + 0, y + 2, x + 1, y + 7);
	gDPFillRectangleScaled(gdl++, x + 0, y + 2, x + 1, y + 5);
	gDPFillRectangleScaled(gdl++, x + 0, y - 6, x + 1, y - 1);
	gDPFillRectangleScaled(gdl++, x + 0, y - 4, x + 1, y - 1);

	gdl = func0f153838(gdl);

	return gdl;
}

bool sightHasTargetWhileAiming(s32 sight)
{
	if (sight == SIGHT_DEFAULT || sight == SIGHT_ZOOM) {
		return true;
	}

	return false;
}

Gfx *sightRender(Gfx *gdl, bool sighton, s32 sight)
{
	if (sight);

	if (g_Vars.currentplayer->activemenumode != AMMODE_CLOSED) {
		return gdl;
	}

	if (g_Vars.currentplayer->gunctrl.passivemode) {
		return gdl;
	}

#if PAL
	g_ScaleX = 1;
#else
	if (g_ViMode == VIMODE_HIRES) {
		g_ScaleX = 2;
	} else {
		g_ScaleX = 1;
	}
#endif

	if (PLAYERCOUNT() >= 2 && g_Vars.coopplayernum < 0 && g_Vars.antiplayernum < 0) {
		sight = SIGHT_DEFAULT;
	}

	sightTick(sighton);

	switch (sight) {
	case SIGHT_DEFAULT:
		gdl = sightRenderDefault(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	case SIGHT_CLASSIC:
		gdl = sightRenderClassic(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	case SIGHT_2:
		gdl = sightRenderType2(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	case SIGHT_3:
		gdl = sightRenderDefault(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	case SIGHT_SKEDAR:
		gdl = sightRenderSkedar(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	case SIGHT_ZOOM:
		gdl = sightRenderZoom(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	case SIGHT_MAIAN:
		gdl = sightRenderMaian(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	default:
		gdl = sightRenderDefault(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	case SIGHT_NONE:
		break;
	}

	if (sight != SIGHT_NONE && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex)) {
		if ((optionsGetAlwaysShowTarget(g_Vars.currentplayerstats->mpindex) && !sighton)
				|| (sighton && sightHasTargetWhileAiming(sight))) {
			gdl = sightRenderTarget(gdl);
		}
	}

	g_ScaleX = 1;

	return gdl;
}
