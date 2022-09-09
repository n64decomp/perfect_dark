#include <ultra64.h>
#include "constants.h"
#include "game/bondmove.h"
#include "game/cheats.h"
#include "game/chraction.h"
#include "game/inv.h"
#include "game/game_006900.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/propsnd.h"
#include "game/game_096360.h"
#include "game/acosfasinf.h"
#include "game/game_096b20.h"
#include "game/quaternion.h"
#include "game/game_097aa0.h"
#include "game/bondgun.h"
#include "game/gunfx.h"
#include "game/game_0b0fd0.h"
#include "game/modelmgr.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/player.h"
#include "game/game_0c33f0.h"
#include "game/gfxmemory.h"
#include "game/sight.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/smoke.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/texdecompress.h"
#include "game/game_176080.h"
#include "game/training.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pak.h"
#include "game/options.h"
#include "game/propobj.h"
#include "game/objectives.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/joy.h"
#include "lib/main.h"
#include "lib/model.h"
#include "lib/snd.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

#define GUNLOADSTATE_FLUX     0
#define GUNLOADSTATE_MODEL    1
#define GUNLOADSTATE_TEXTURES 2
#define GUNLOADSTATE_DLS      3
#define GUNLOADSTATE_LOADED   4

#define MASTERLOADSTATE_FLUX   0
#define MASTERLOADSTATE_HANDS  1
#define MASTERLOADSTATE_GUN    2
#define MASTERLOADSTATE_CARTS  3
#define MASTERLOADSTATE_LOADED 4

#if VERSION >= VERSION_PAL_BETA
struct sndstate *g_CasingAudioHandles[2];
s32 var8009d0d8;
u32 fill2;
struct sndstate *g_BgunAudioHandles[4];
s32 var8009d0dc;
u32 fill2_2;
s32 var8009d0f0[3];
u32 var8009d0fc;
u32 var8009d100;
u32 var8009d104;
u32 var8009d108;
u32 var8009d10c;
u32 var8009d110;
u32 var8009d114;
u32 var8009d118;
u32 var8009d11c;
u32 var8009d120;
u32 var8009d124;
u32 var8009d128;
u32 var8009d12c;
u32 var8009d130;
u32 var8009d134;
u32 var8009d138;
u32 var8009d13c;
f32 var8009d140;
struct hand *var8009d144;
s32 var8009d148;
u32 var8009d14c;
struct fireslot g_Fireslots[NUM_FIRESLOTS];
#elif VERSION >= VERSION_NTSC_1_0
struct sndstate *g_CasingAudioHandles[2];
s32 var8009d0d8;
s32 var8009d0dc;
struct sndstate *g_BgunAudioHandles[4];
s32 var8009d0f0[3];
u32 var8009d0fc;
u32 var8009d100;
u32 var8009d104;
u32 var8009d108;
u32 var8009d10c;
u32 var8009d110;
u32 var8009d114;
u32 var8009d118;
u32 var8009d11c;
u32 var8009d120;
u32 var8009d124;
u32 var8009d128;
u32 var8009d12c;
u32 var8009d130;
u32 var8009d134;
u32 var8009d138;
u32 var8009d13c;
f32 var8009d140;
struct hand *var8009d144;
s32 var8009d148;
u32 var8009d14c;
struct fireslot g_Fireslots[NUM_FIRESLOTS];
#else
s32 var8009d0dc;
u32 var800a1800nb;
s32 var8009d0f0[3];
u32 var8009d0fc;
u32 var8009d100;
u32 var8009d104;
u32 var8009d108;
u32 var8009d10c;
u32 var8009d110;
u32 var8009d114;
u32 var8009d118;
u32 var8009d11c;
u32 var8009d120;
u32 var8009d124;
u32 var8009d128;
u32 var8009d12c;
u32 var8009d130;
u32 var8009d134;
u32 var8009d138;
u32 var8009d13c;
f32 var8009d140;
struct hand *var8009d144;
s32 var8009d148;
u32 var8009d14c;
struct sndstate *g_CasingAudioHandles[2];
s32 var8009d0d8;
struct sndstate *g_BgunAudioHandles[4];
struct fireslot g_Fireslots[NUM_FIRESLOTS];
u32 fill2[1];
#endif

u32 var80070090 = 0x96969600;
u32 var80070094 = 0x96969600;
u32 var80070098 = 0xffffff00;
u32 var8007009c = 0xffffff00;
u32 var800700a0 = 0xb24d2e00;
u32 var800700a4 = 0x00000000;
u32 var800700a8 = 0x00025800;
u32 var800700ac = 0x0001e000;

u16 g_CartFileNums[] = {
	FILE_GCARTRIDGE,
	FILE_GCARTRIFLE,
	FILE_GCARTBLUE,
	FILE_GCARTSHELL,
};

u32 var800700b8 = 0x00000000;

char var800700bc[][10] = {
	{ 'i','d','l','e'                     }, // "idle"
	{ 'p','r','e','p','a','r','e'         }, // "prepare"
	{ 'c','a','n','t','u','s','e'         }, // "cantuse"
	{ 'n','o','a','m','m','o'             }, // "noammo"
	{ 'u','s','e','2'                     }, // "use2"
	{ 'c','h','a','n','g','e'             }, // "change"
	{ 'u','p','g','r','a','d','e'         }, // "upgrade"
	{ 'c','h','a','n','g','e','f','n'     }, // "changefn"
	{ 'i','d','l','e','s','t','u','c','k' }, // "idlestuck"
	{ 'x','x','x'                         }, // "xxx"
};

#if VERSION >= VERSION_NTSC_1_0
void bgunRumble(s32 handnum, s32 weaponnum)
{
	u32 stack;
	s32 contpadtouse1;
	s32 contpadtouse2;
	bool singlewield = false;
	s32 contpad1;
	s32 contpad2;
	s32 contpad1hasrumble;
	s32 contpad2hasrumble;

	joyGetContpadNumsForPlayer(g_Vars.currentplayernum, &contpad1, &contpad2);

	if (optionsGetControlMode(g_Vars.currentplayerstats->mpindex) >= CONTROLMODE_21
			&& contpad1 >= 0 && contpad2 >= 0) {
		contpad1hasrumble = pakGetType(contpad1) == PAKTYPE_RUMBLE;
		contpad2hasrumble = pakGetType(contpad2) == PAKTYPE_RUMBLE;

		if (!weaponHasFlag(weaponnum, WEAPONFLAG_DUALWIELD)) {
			singlewield = true;
		}

		if (contpad1hasrumble && contpad2hasrumble) {
			if (singlewield) {
				pakRumble(contpad1, 0.2f, 2, 4);
				pakRumble(contpad2, 0.2f, 2, 4);
			} else {
				s32 contpadtouse1 = contpad1;

				if (handnum == HAND_LEFT) {
					contpadtouse1 = contpad2;
				}

				pakRumble(contpadtouse1, 0.2f, 2, 4);
			}
		} else {
			s32 contpadtouse2 = contpad1;

			if (contpad2hasrumble) {
				contpadtouse2 = contpad2;
			}

			pakRumble(contpadtouse2, 0.2f, 2, 4);
		}
	} else {
		if (contpad1 >= 0) {
			pakRumble(contpad1, 0.2f, 2, 4);
		}
	}
}
#else
GLOBAL_ASM(
glabel bgunRumble
/*  f095b30:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f095b34:	3c08800a */ 	lui	$t0,0x800a
/*  f095b38:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f095b3c:	8d0e0288 */ 	lw	$t6,0x288($t0)
/*  f095b40:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f095b44:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f095b48:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f095b4c:	0fc53380 */ 	jal	optionsGetControlMode
/*  f095b50:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f095b54:	3c08800a */ 	lui	$t0,0x800a
/*  f095b58:	28410004 */ 	slti	$at,$v0,0x4
/*  f095b5c:	1420007c */ 	bnez	$at,.NB0f095d50
/*  f095b60:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f095b64:	0fc44336 */ 	jal	pakGetType
/*  f095b68:	8104028f */ 	lb	$a0,0x28f($t0)
/*  f095b6c:	3c08800a */ 	lui	$t0,0x800a
/*  f095b70:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f095b74:	8d0f006c */ 	lw	$t7,0x6c($t0)
/*  f095b78:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f095b7c:	00453026 */ 	xor	$a2,$v0,$a1
/*  f095b80:	11e00003 */ 	beqz	$t7,.NB0f095b90
/*  f095b84:	2cc60001 */ 	sltiu	$a2,$a2,0x1
/*  f095b88:	10000002 */ 	beqz	$zero,.NB0f095b94
/*  f095b8c:	00a05025 */ 	or	$t2,$a1,$zero
.NB0f095b90:
/*  f095b90:	00005025 */ 	or	$t2,$zero,$zero
.NB0f095b94:
/*  f095b94:	8d180068 */ 	lw	$t8,0x68($t0)
/*  f095b98:	00004825 */ 	or	$t1,$zero,$zero
/*  f095b9c:	00001825 */ 	or	$v1,$zero,$zero
/*  f095ba0:	13000003 */ 	beqz	$t8,.NB0f095bb0
/*  f095ba4:	00001025 */ 	or	$v0,$zero,$zero
/*  f095ba8:	10000001 */ 	beqz	$zero,.NB0f095bb0
/*  f095bac:	00a04825 */ 	or	$t1,$a1,$zero
.NB0f095bb0:
/*  f095bb0:	8d190064 */ 	lw	$t9,0x64($t0)
/*  f095bb4:	13200003 */ 	beqz	$t9,.NB0f095bc4
/*  f095bb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095bbc:	10000001 */ 	beqz	$zero,.NB0f095bc4
/*  f095bc0:	00a01825 */ 	or	$v1,$a1,$zero
.NB0f095bc4:
/*  f095bc4:	8d0c0070 */ 	lw	$t4,0x70($t0)
/*  f095bc8:	11800003 */ 	beqz	$t4,.NB0f095bd8
/*  f095bcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095bd0:	10000001 */ 	beqz	$zero,.NB0f095bd8
/*  f095bd4:	00a01025 */ 	or	$v0,$a1,$zero
.NB0f095bd8:
/*  f095bd8:	8d18028c */ 	lw	$t8,0x28c($t0)
/*  f095bdc:	00436821 */ 	addu	$t5,$v0,$v1
/*  f095be0:	01a97021 */ 	addu	$t6,$t5,$t1
/*  f095be4:	01ca7821 */ 	addu	$t7,$t6,$t2
/*  f095be8:	01f82021 */ 	addu	$a0,$t7,$t8
/*  f095bec:	0004ce00 */ 	sll	$t9,$a0,0x18
/*  f095bf0:	00192603 */ 	sra	$a0,$t9,0x18
/*  f095bf4:	0fc44336 */ 	jal	pakGetType
/*  f095bf8:	afa6001c */ 	sw	$a2,0x1c($sp)
/*  f095bfc:	8fa6001c */ 	lw	$a2,0x1c($sp)
/*  f095c00:	3c08800a */ 	lui	$t0,0x800a
/*  f095c04:	2508e6c0 */ 	addiu	$t0,$t0,-6464
/*  f095c08:	10c0002a */ 	beqz	$a2,.NB0f095cb4
/*  f095c0c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f095c10:	14450028 */ 	bne	$v0,$a1,.NB0f095cb4
/*  f095c14:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f095c18:	15c5001c */ 	bne	$t6,$a1,.NB0f095c8c
/*  f095c1c:	8d0b028c */ 	lw	$t3,0x28c($t0)
/*  f095c20:	8d0f0070 */ 	lw	$t7,0x70($t0)
/*  f095c24:	00005025 */ 	or	$t2,$zero,$zero
/*  f095c28:	00004825 */ 	or	$t1,$zero,$zero
/*  f095c2c:	11e00003 */ 	beqz	$t7,.NB0f095c3c
/*  f095c30:	00001825 */ 	or	$v1,$zero,$zero
/*  f095c34:	10000001 */ 	beqz	$zero,.NB0f095c3c
/*  f095c38:	240a0001 */ 	addiu	$t2,$zero,0x1
.NB0f095c3c:
/*  f095c3c:	8d18006c */ 	lw	$t8,0x6c($t0)
/*  f095c40:	00001025 */ 	or	$v0,$zero,$zero
/*  f095c44:	13000003 */ 	beqz	$t8,.NB0f095c54
/*  f095c48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095c4c:	10000001 */ 	beqz	$zero,.NB0f095c54
/*  f095c50:	24090001 */ 	addiu	$t1,$zero,0x1
.NB0f095c54:
/*  f095c54:	8d190068 */ 	lw	$t9,0x68($t0)
/*  f095c58:	13200003 */ 	beqz	$t9,.NB0f095c68
/*  f095c5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095c60:	10000001 */ 	beqz	$zero,.NB0f095c68
/*  f095c64:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f095c68:
/*  f095c68:	8d0c0064 */ 	lw	$t4,0x64($t0)
/*  f095c6c:	11800003 */ 	beqz	$t4,.NB0f095c7c
/*  f095c70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095c74:	10000001 */ 	beqz	$zero,.NB0f095c7c
/*  f095c78:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f095c7c:
/*  f095c7c:	01626821 */ 	addu	$t5,$t3,$v0
/*  f095c80:	01a37021 */ 	addu	$t6,$t5,$v1
/*  f095c84:	01c97821 */ 	addu	$t7,$t6,$t1
/*  f095c88:	01ea5821 */ 	addu	$t3,$t7,$t2
.NB0f095c8c:
/*  f095c8c:	000b2600 */ 	sll	$a0,$t3,0x18
/*  f095c90:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f095c94:	3c053e4c */ 	lui	$a1,0x3e4c
/*  f095c98:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f095c9c:	03002025 */ 	or	$a0,$t8,$zero
/*  f095ca0:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f095ca4:	0fc45e2f */ 	jal	pakRumble
/*  f095ca8:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f095cac:	1000002f */ 	beqz	$zero,.NB0f095d6c
/*  f095cb0:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f095cb4:
/*  f095cb4:	1445001c */ 	bne	$v0,$a1,.NB0f095d28
/*  f095cb8:	8d0b028c */ 	lw	$t3,0x28c($t0)
/*  f095cbc:	8d0c0070 */ 	lw	$t4,0x70($t0)
/*  f095cc0:	00005025 */ 	or	$t2,$zero,$zero
/*  f095cc4:	00004825 */ 	or	$t1,$zero,$zero
/*  f095cc8:	11800003 */ 	beqz	$t4,.NB0f095cd8
/*  f095ccc:	00001825 */ 	or	$v1,$zero,$zero
/*  f095cd0:	10000001 */ 	beqz	$zero,.NB0f095cd8
/*  f095cd4:	240a0001 */ 	addiu	$t2,$zero,0x1
.NB0f095cd8:
/*  f095cd8:	8d0d006c */ 	lw	$t5,0x6c($t0)
/*  f095cdc:	00001025 */ 	or	$v0,$zero,$zero
/*  f095ce0:	11a00003 */ 	beqz	$t5,.NB0f095cf0
/*  f095ce4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095ce8:	10000001 */ 	beqz	$zero,.NB0f095cf0
/*  f095cec:	24090001 */ 	addiu	$t1,$zero,0x1
.NB0f095cf0:
/*  f095cf0:	8d0e0068 */ 	lw	$t6,0x68($t0)
/*  f095cf4:	11c00003 */ 	beqz	$t6,.NB0f095d04
/*  f095cf8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095cfc:	10000001 */ 	beqz	$zero,.NB0f095d04
/*  f095d00:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f095d04:
/*  f095d04:	8d0f0064 */ 	lw	$t7,0x64($t0)
/*  f095d08:	11e00003 */ 	beqz	$t7,.NB0f095d18
/*  f095d0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f095d10:	10000001 */ 	beqz	$zero,.NB0f095d18
/*  f095d14:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f095d18:
/*  f095d18:	0162c021 */ 	addu	$t8,$t3,$v0
/*  f095d1c:	0303c821 */ 	addu	$t9,$t8,$v1
/*  f095d20:	03296021 */ 	addu	$t4,$t9,$t1
/*  f095d24:	018a5821 */ 	addu	$t3,$t4,$t2
.NB0f095d28:
/*  f095d28:	000b2600 */ 	sll	$a0,$t3,0x18
/*  f095d2c:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f095d30:	3c053e4c */ 	lui	$a1,0x3e4c
/*  f095d34:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f095d38:	01a02025 */ 	or	$a0,$t5,$zero
/*  f095d3c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f095d40:	0fc45e2f */ 	jal	pakRumble
/*  f095d44:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f095d48:	10000008 */ 	beqz	$zero,.NB0f095d6c
/*  f095d4c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f095d50:
/*  f095d50:	3c053e4c */ 	lui	$a1,0x3e4c
/*  f095d54:	34a5cccd */ 	ori	$a1,$a1,0xcccd
/*  f095d58:	8104028f */ 	lb	$a0,0x28f($t0)
/*  f095d5c:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f095d60:	0fc45e2f */ 	jal	pakRumble
/*  f095d64:	24070004 */ 	addiu	$a3,$zero,0x4
/*  f095d68:	8fbf0014 */ 	lw	$ra,0x14($sp)
.NB0f095d6c:
/*  f095d6c:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f095d70:	03e00008 */ 	jr	$ra
/*  f095d74:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

s32 bgunGetUnequippedReloadIndex(s32 weaponnum)
{
	if (weaponnum == WEAPON_CROSSBOW) {
		return 0;
	}

	if (weaponnum == WEAPON_SHOTGUN) {
		return 1;
	}

	if (weaponnum == WEAPON_DY357MAGNUM) {
		return 2;
	}

	if (weaponnum == WEAPON_DY357LX) {
		return 3;
	}

	return -1;
}

/**
 * The magnums, shotgun and crossbow are special because that the game remembers
 * how much ammo is loaded in their clips when the weapon is not being used.
 * Their clips are gradually reloaded while the weapon is not in use, and that
 * gradual reloading is handled by this function.
 *
 * The gunroundsspent value is actually a countdown timer,
 * not the number of rounds as the name suggests.
 */
void bgunTickUnequippedReload(void)
{
	s32 i;
	s32 j;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 4; j++) {
			u16 spent = g_Vars.currentplayer->hands[i].gunroundsspent[j];

			if (spent > g_Vars.lvupdate240_60) {
				spent -= g_Vars.lvupdate240_60;
			} else {
				spent = 0;
			}

			g_Vars.currentplayer->hands[i].gunroundsspent[j] = spent;
		}
	}
}

bool bgun0f097df0(struct inventory_typef *arg0, struct hand *hand)
{
	bool result = true;

	switch (arg0->unk00) {
	case 4:
		if (((hand->gset.unk0639 >> arg0->unk02) & 1) == 0) {
			result = false;
		}
		break;
	case 5:
		if (hand != &g_Vars.currentplayer->hands[HAND_LEFT]) {
			result = false;
		}
		break;
	case 6:
		if (hand != &g_Vars.currentplayer->hands[HAND_RIGHT]) {
			result = false;
		}
		break;
	}

	return result;
}

void bgunSetPartVisible(s16 partnum, bool visible, struct hand *hand, struct modelfiledata *filedata)
{
	struct modelnode *node;

	if (partnum == MODELPART_0035 || partnum == MODELPART_0036) {
		if (g_Vars.currentplayer->gunctrl.handmodeldef) {
			node = modelGetPart(g_Vars.currentplayer->gunctrl.handmodeldef, partnum);

			if (node) {
				struct modelrodata_toggle *rodata = &node->rodata->toggle;
				u32 *ptr = &hand->handsavedata[rodata->rwdataindex];
				*ptr = visible;
			}
		}
	} else {
		node = modelGetPart(filedata, partnum);

		if (node) {
			struct modelrodata_toggle *rodata = &node->rodata->toggle;
			u32 *ptr = &hand->unk0a6c[rodata->rwdataindex];
			*ptr = visible;
		}
	}
}

void bgun0f097f28(struct hand *hand, struct modelfiledata *filedata, struct inventory_typef *arg2)
{
	struct inventory_typef *thing = arg2;
	bool done = false;

	if (thing == NULL) {
		return;
	}

	while (!done) {
		if (bgun0f097df0(thing, hand)) {
			if (thing->unk04 == 0) {
				bgunSetPartVisible(thing->partnum, true, hand, filedata);
			}

			if (thing->unk04 == 1) {
				bgunSetPartVisible(thing->partnum, false, hand, filedata);
			}

			if (thing->unk04 == 3) {
				bgunSetPartVisible(thing->partnum, true, hand, filedata);
			}
		} else {
			if (thing->unk04 == 3) {
				bgunSetPartVisible(thing->partnum, false, hand, filedata);
			}
		}

		thing++;

		if (thing->unk00 == 0) {
			done = true;
		}
	}
}

void bgun0f098030(struct hand *hand, struct modelfiledata *filedata)
{
	struct weapon *weapon = weaponFindById(hand->gset.weaponnum);
	s32 i;
	s32 j;

	bgun0f097f28(hand, filedata, weapon->fptr);
	bgunSetPartVisible(MODELPART_0042, false, hand, filedata);

	for (i = 0; i < 2; i++) {
		if (weapon->ammos[i] && (weapon->ammos[i]->flags & AMMOFLAG_QTYAFFECTSPARTVIS)) {
			for (j = 0; j < hand->clipsizes[i]; j++) {
				if (j >= hand->loadedammo[i]) {
					bgunSetPartVisible(j + 100, false, hand, filedata);
				} else {
					bgunSetPartVisible(j + 100, true, hand, filedata);
				}
			}
		}
	}
}

f32 bgun0f09815c(struct hand *hand)
{
	if (hand->animmode == HANDANIMMODE_BUSY && hand->unk0ce8 != NULL) {
		if (hand->unk0ce8->unk04 < 0) {
			return modelGetNumAnimFrames(&hand->gunmodel) - modelGetCurAnimFrame(&hand->gunmodel);
		}

		return modelGetCurAnimFrame(&hand->gunmodel);
	}

	return 0;
}

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel bgun0f0981e8
.late_rodata
glabel var7f1ac1a8
.word 0x461c4000
glabel var7f1ac1ac
.word 0x3f451eb8
glabel var7f1ac1b0
.word 0x3f333333
.text
/*  f098f88:	27bdfea0 */ 	addiu	$sp,$sp,-352
/*  f098f8c:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f098f90:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f098f94:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f098f98:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f098f9c:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f098fa0:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f098fa4:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f098fa8:	afa50164 */ 	sw	$a1,0x164($sp)
/*  f098fac:	908e0690 */ 	lbu	$t6,0x690($a0)
/*  f098fb0:	8c98068c */ 	lw	$t8,0x68c($a0)
/*  f098fb4:	24010002 */ 	li	$at,0x2
/*  f098fb8:	31cfffe3 */ 	andi	$t7,$t6,0xffe3
/*  f098fbc:	00809025 */ 	move	$s2,$a0
/*  f098fc0:	1701000f */ 	bne	$t8,$at,.JF0f099000
/*  f098fc4:	a08f0690 */ 	sb	$t7,0x690($a0)
/*  f098fc8:	0fc263bf */ 	jal	bgun0f09815c
/*  f098fcc:	00000000 */ 	nop
/*  f098fd0:	46000506 */ 	mov.s	$f20,$f0
/*  f098fd4:	0c00747e */ 	jal	modelGetNumAnimFrames
/*  f098fd8:	26440384 */ 	addiu	$a0,$s2,0x384
/*  f098fdc:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f098fe0:	44992000 */ 	mtc1	$t9,$f4
/*  f098fe4:	00000000 */ 	nop
/*  f098fe8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f098fec:	4614303e */ 	c.le.s	$f6,$f20
/*  f098ff0:	00000000 */ 	nop
/*  f098ff4:	45020003 */ 	bc1fl	.JF0f099004
/*  f098ff8:	8e480680 */ 	lw	$t0,0x680($s2)
/*  f098ffc:	ae40068c */ 	sw	$zero,0x68c($s2)
.JF0f099000:
/*  f099000:	8e480680 */ 	lw	$t0,0x680($s2)
.JF0f099004:
/*  f099004:	8e49068c */ 	lw	$t1,0x68c($s2)
/*  f099008:	29020000 */ 	slti	$v0,$t0,0x0
/*  f09900c:	392a0002 */ 	xori	$t2,$t1,0x2
/*  f099010:	2d4a0001 */ 	sltiu	$t2,$t2,0x1
/*  f099014:	38420001 */ 	xori	$v0,$v0,0x1
/*  f099018:	01425825 */ 	or	$t3,$t2,$v0
/*  f09901c:	516001c7 */ 	beqzl	$t3,.JF0f09973c
/*  f099020:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f099024:	44801000 */ 	mtc1	$zero,$f2
/*  f099028:	c64806d0 */ 	lwc1	$f8,0x6d0($s2)
/*  f09902c:	26540384 */ 	addiu	$s4,$s2,0x384
/*  f099030:	4608103c */ 	c.lt.s	$f2,$f8
/*  f099034:	00000000 */ 	nop
/*  f099038:	45000006 */ 	bc1f	.JF0f099054
/*  f09903c:	00000000 */ 	nop
/*  f099040:	8e480680 */ 	lw	$t0,0x680($s2)
/*  f099044:	ae400684 */ 	sw	$zero,0x684($s2)
/*  f099048:	e6420688 */ 	swc1	$f2,0x688($s2)
/*  f09904c:	29020000 */ 	slti	$v0,$t0,0x0
/*  f099050:	38420001 */ 	xori	$v0,$v0,0x1
.JF0f099054:
/*  f099054:	50400057 */ 	beqzl	$v0,.JF0f0991b4
/*  f099058:	8e4d0690 */ 	lw	$t5,0x690($s2)
/*  f09905c:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
/*  f099060:	3c013f80 */ 	lui	$at,0x3f80
/*  f099064:	924d06d6 */ 	lbu	$t5,0x6d6($s2)
/*  f099068:	8c6c0004 */ 	lw	$t4,0x4($v1)
/*  f09906c:	44810000 */ 	mtc1	$at,$f0
/*  f099070:	3c017f1b */ 	lui	$at,0x7f1b
/*  f099074:	448c5000 */ 	mtc1	$t4,$f10
/*  f099078:	c432ce28 */ 	lwc1	$f18,-0x31d8($at)
/*  f09907c:	31ae0001 */ 	andi	$t6,$t5,0x1
/*  f099080:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f099084:	3c0f800a */ 	lui	$t7,0x800a
/*  f099088:	11c0001a */ 	beqz	$t6,.JF0f0990f4
/*  f09908c:	46128503 */ 	div.s	$f20,$f16,$f18
/*  f099090:	8defa8b4 */ 	lw	$t7,-0x574c($t7)
/*  f099094:	81f80de4 */ 	lb	$t8,0xde4($t7)
/*  f099098:	13000016 */ 	beqz	$t8,.JF0f0990f4
/*  f09909c:	00000000 */ 	nop
/*  f0990a0:	0c004b60 */ 	jal	random
/*  f0990a4:	00000000 */ 	nop
/*  f0990a8:	44822000 */ 	mtc1	$v0,$f4
/*  f0990ac:	3c014f80 */ 	lui	$at,0x4f80
/*  f0990b0:	04410004 */ 	bgez	$v0,.JF0f0990c4
/*  f0990b4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0990b8:	44814000 */ 	mtc1	$at,$f8
/*  f0990bc:	00000000 */ 	nop
/*  f0990c0:	46083180 */ 	add.s	$f6,$f6,$f8
.JF0f0990c4:
/*  f0990c4:	3c012f80 */ 	lui	$at,0x2f80
/*  f0990c8:	44815000 */ 	mtc1	$at,$f10
/*  f0990cc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0990d0:	c432ce2c */ 	lwc1	$f18,-0x31d4($at)
/*  f0990d4:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0990d8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0990dc:	c428ce30 */ 	lwc1	$f8,-0x31d0($at)
/*  f0990e0:	44801000 */ 	mtc1	$zero,$f2
/*  f0990e4:	8e480680 */ 	lw	$t0,0x680($s2)
/*  f0990e8:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
/*  f0990ec:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0990f0:	46082000 */ 	add.s	$f0,$f4,$f8
.JF0f0990f4:
/*  f0990f4:	10600018 */ 	beqz	$v1,.JF0f099158
/*  f0990f8:	02802025 */ 	move	$a0,$s4
/*  f0990fc:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f099100:	00082c00 */ 	sll	$a1,$t0,0x10
/*  f099104:	0005cc03 */ 	sra	$t9,$a1,0x10
/*  f099108:	45000013 */ 	bc1f	.JF0f099158
/*  f09910c:	00000000 */ 	nop
/*  f099110:	46140182 */ 	mul.s	$f6,$f0,$f20
/*  f099114:	44071000 */ 	mfc1	$a3,$f2
/*  f099118:	02802025 */ 	move	$a0,$s4
/*  f09911c:	03202825 */ 	move	$a1,$t9
/*  f099120:	00003025 */ 	move	$a2,$zero
/*  f099124:	e7a20014 */ 	swc1	$f2,0x14($sp)
/*  f099128:	0c00772b */ 	jal	modelSetAnimation
/*  f09912c:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f099130:	0c00747e */ 	jal	modelGetNumAnimFrames
/*  f099134:	02802025 */ 	move	$a0,$s4
/*  f099138:	44825000 */ 	mtc1	$v0,$f10
/*  f09913c:	02802025 */ 	move	$a0,$s4
/*  f099140:	468052a0 */ 	cvt.s.w	$f10,$f10
/*  f099144:	44055000 */ 	mfc1	$a1,$f10
/*  f099148:	0c0077fe */ 	jal	model0001e018
/*  f09914c:	00000000 */ 	nop
/*  f099150:	1000000b */ 	b	.JF0f099180
/*  f099154:	240affff */ 	li	$t2,-1
.JF0f099158:
/*  f099158:	46140402 */ 	mul.s	$f16,$f0,$f20
/*  f09915c:	00082c00 */ 	sll	$a1,$t0,0x10
/*  f099160:	00054c03 */ 	sra	$t1,$a1,0x10
/*  f099164:	44071000 */ 	mfc1	$a3,$f2
/*  f099168:	01202825 */ 	move	$a1,$t1
/*  f09916c:	00003025 */ 	move	$a2,$zero
/*  f099170:	e7a20014 */ 	swc1	$f2,0x14($sp)
/*  f099174:	0c00772b */ 	jal	modelSetAnimation
/*  f099178:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f09917c:	240affff */ 	li	$t2,-1
.JF0f099180:
/*  f099180:	240b0002 */ 	li	$t3,0x2
/*  f099184:	ae4a0680 */ 	sw	$t2,0x680($s2)
/*  f099188:	ae4b068c */ 	sw	$t3,0x68c($s2)
/*  f09918c:	0c00749a */ 	jal	modelGetAbsAnimSpeed
/*  f099190:	02802025 */ 	move	$a0,$s4
/*  f099194:	8e4c0684 */ 	lw	$t4,0x684($s2)
/*  f099198:	44801000 */ 	mtc1	$zero,$f2
/*  f09919c:	448c9000 */ 	mtc1	$t4,$f18
/*  f0991a0:	00000000 */ 	nop
/*  f0991a4:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0991a8:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f0991ac:	e6480688 */ 	swc1	$f8,0x688($s2)
/*  f0991b0:	8e4d0690 */ 	lw	$t5,0x690($s2)
.JF0f0991b4:
/*  f0991b4:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f0991b8:	05e10003 */ 	bgez	$t7,.JF0f0991c8
/*  f0991bc:	00000000 */ 	nop
/*  f0991c0:	ae400684 */ 	sw	$zero,0x684($s2)
/*  f0991c4:	e6420688 */ 	swc1	$f2,0x688($s2)
.JF0f0991c8:
/*  f0991c8:	0fc263bf */ 	jal	bgun0f09815c
/*  f0991cc:	02402025 */ 	move	$a0,$s2
/*  f0991d0:	44805000 */ 	mtc1	$zero,$f10
/*  f0991d4:	c6460688 */ 	lwc1	$f6,0x688($s2)
/*  f0991d8:	46000506 */ 	mov.s	$f20,$f0
/*  f0991dc:	460a0032 */ 	c.eq.s	$f0,$f10
/*  f0991e0:	46003380 */ 	add.s	$f14,$f6,$f0
/*  f0991e4:	4502000b */ 	bc1fl	.JF0f099214
/*  f0991e8:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
/*  f0991ec:	44808000 */ 	mtc1	$zero,$f16
/*  f0991f0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0991f4:	460e803c */ 	c.lt.s	$f16,$f14
/*  f0991f8:	00000000 */ 	nop
/*  f0991fc:	45020005 */ 	bc1fl	.JF0f099214
/*  f099200:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
/*  f099204:	44819000 */ 	mtc1	$at,$f18
/*  f099208:	00000000 */ 	nop
/*  f09920c:	46120501 */ 	sub.s	$f20,$f0,$f18
/*  f099210:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
.JF0f099214:
/*  f099214:	106000d1 */ 	beqz	$v1,.JF0f09955c
/*  f099218:	00608825 */ 	move	$s1,$v1
/*  f09921c:	106000cf */ 	beqz	$v1,.JF0f09955c
/*  f099220:	afa0014c */ 	sw	$zero,0x14c($sp)
/*  f099224:	00008025 */ 	move	$s0,$zero
/*  f099228:	24130001 */ 	li	$s3,0x1
/*  f09922c:	92230000 */ 	lbu	$v1,0x0($s1)
.JF0f099230:
/*  f099230:	14600003 */ 	bnez	$v1,.JF0f099240
/*  f099234:	00000000 */ 	nop
/*  f099238:	100000af */ 	b	.JF0f0994f8
/*  f09923c:	afb3014c */ 	sw	$s3,0x14c($sp)
.JF0f099240:
/*  f099240:	12630003 */ 	beq	$s3,$v1,.JF0f099250
/*  f099244:	24010002 */ 	li	$at,0x2
/*  f099248:	54610036 */ 	bnel	$v1,$at,.JF0f099324
/*  f09924c:	24010003 */ 	li	$at,0x3
.JF0f099250:
/*  f099250:	96260002 */ 	lhu	$a2,0x2($s1)
/*  f099254:	3c014f80 */ 	lui	$at,0x4f80
/*  f099258:	2405ffff */ 	li	$a1,-1
/*  f09925c:	44862000 */ 	mtc1	$a2,$f4
/*  f099260:	27ab0094 */ 	addiu	$t3,$sp,0x94
/*  f099264:	04c10004 */ 	bgez	$a2,.JF0f099278
/*  f099268:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f09926c:	44813000 */ 	mtc1	$at,$f6
/*  f099270:	00000000 */ 	nop
/*  f099274:	46064200 */ 	add.s	$f8,$f8,$f6
.JF0f099278:
/*  f099278:	460e403e */ 	c.le.s	$f8,$f14
/*  f09927c:	2401ffff */ 	li	$at,-1
/*  f099280:	4502009e */ 	bc1fl	.JF0f0994fc
/*  f099284:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f099288:	1a00000a */ 	blez	$s0,.JF0f0992b4
/*  f09928c:	00001025 */ 	move	$v0,$zero
/*  f099290:	8e240004 */ 	lw	$a0,0x4($s1)
/*  f099294:	27a3010c */ 	addiu	$v1,$sp,0x10c
.JF0f099298:
/*  f099298:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f09929c:	54980003 */ 	bnel	$a0,$t8,.JF0f0992ac
/*  f0992a0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0992a4:	00402825 */ 	move	$a1,$v0
/*  f0992a8:	24420001 */ 	addiu	$v0,$v0,0x1
.JF0f0992ac:
/*  f0992ac:	1450fffa */ 	bne	$v0,$s0,.JF0f099298
/*  f0992b0:	24630004 */ 	addiu	$v1,$v1,0x4
.JF0f0992b4:
/*  f0992b4:	14a1000a */ 	bne	$a1,$at,.JF0f0992e0
/*  f0992b8:	2409ffff */ 	li	$t1,-1
/*  f0992bc:	8e240004 */ 	lw	$a0,0x4($s1)
/*  f0992c0:	02002825 */ 	move	$a1,$s0
/*  f0992c4:	00051080 */ 	sll	$v0,$a1,0x2
/*  f0992c8:	03a2c821 */ 	addu	$t9,$sp,$v0
/*  f0992cc:	03a25021 */ 	addu	$t2,$sp,$v0
/*  f0992d0:	af24010c */ 	sw	$a0,0x10c($t9)
/*  f0992d4:	ad490094 */ 	sw	$t1,0x94($t2)
/*  f0992d8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0992dc:	96260002 */ 	lhu	$a2,0x2($s1)
.JF0f0992e0:
/*  f0992e0:	00051080 */ 	sll	$v0,$a1,0x2
/*  f0992e4:	004b1821 */ 	addu	$v1,$v0,$t3
/*  f0992e8:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0992ec:	0186082a */ 	slt	$at,$t4,$a2
/*  f0992f0:	50200082 */ 	beqzl	$at,.JF0f0994fc
/*  f0992f4:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f0992f8:	ac660000 */ 	sw	$a2,0x0($v1)
/*  f0992fc:	922d0000 */ 	lbu	$t5,0x0($s1)
/*  f099300:	03a27821 */ 	addu	$t7,$sp,$v0
/*  f099304:	03a27021 */ 	addu	$t6,$sp,$v0
/*  f099308:	166d0003 */ 	bne	$s3,$t5,.JF0f099318
/*  f09930c:	00000000 */ 	nop
/*  f099310:	10000079 */ 	b	.JF0f0994f8
/*  f099314:	add300d0 */ 	sw	$s3,0xd0($t6)
.JF0f099318:
/*  f099318:	10000077 */ 	b	.JF0f0994f8
/*  f09931c:	ade000d0 */ 	sw	$zero,0xd0($t7)
/*  f099320:	24010003 */ 	li	$at,0x3
.JF0f099324:
/*  f099324:	10610005 */ 	beq	$v1,$at,.JF0f09933c
/*  f099328:	24010008 */ 	li	$at,0x8
/*  f09932c:	50610042 */ 	beql	$v1,$at,.JF0f099438
/*  f099330:	8e4e0690 */ 	lw	$t6,0x690($s2)
/*  f099334:	10000071 */ 	b	.JF0f0994fc
/*  f099338:	8fac014c */ 	lw	$t4,0x14c($sp)
.JF0f09933c:
/*  f09933c:	8e580690 */ 	lw	$t8,0x690($s2)
/*  f099340:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f099344:	5320006d */ 	beqzl	$t9,.JF0f0994fc
/*  f099348:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f09934c:	96290002 */ 	lhu	$t1,0x2($s1)
/*  f099350:	3c014f80 */ 	lui	$at,0x4f80
/*  f099354:	44895000 */ 	mtc1	$t1,$f10
/*  f099358:	05210004 */ 	bgez	$t1,.JF0f09936c
/*  f09935c:	468050a0 */ 	cvt.s.w	$f2,$f10
/*  f099360:	44818000 */ 	mtc1	$at,$f16
/*  f099364:	00000000 */ 	nop
/*  f099368:	46101080 */ 	add.s	$f2,$f2,$f16
.JF0f09936c:
/*  f09936c:	460e103e */ 	c.le.s	$f2,$f14
/*  f099370:	00000000 */ 	nop
/*  f099374:	45020061 */ 	bc1fl	.JF0f0994fc
/*  f099378:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f09937c:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f099380:	00000000 */ 	nop
/*  f099384:	4502005d */ 	bc1fl	.JF0f0994fc
/*  f099388:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f09938c:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f099390:	00000000 */ 	nop
/*  f099394:	45020059 */ 	bc1fl	.JF0f0994fc
/*  f099398:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f09939c:	0fc263bf */ 	jal	bgun0f09815c
/*  f0993a0:	02402025 */ 	move	$a0,$s2
/*  f0993a4:	962a0002 */ 	lhu	$t2,0x2($s1)
/*  f0993a8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0993ac:	02802025 */ 	move	$a0,$s4
/*  f0993b0:	448a9000 */ 	mtc1	$t2,$f18
/*  f0993b4:	05410004 */ 	bgez	$t2,.JF0f0993c8
/*  f0993b8:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0993bc:	44813000 */ 	mtc1	$at,$f6
/*  f0993c0:	00000000 */ 	nop
/*  f0993c4:	46062100 */ 	add.s	$f4,$f4,$f6
.JF0f0993c8:
/*  f0993c8:	46002081 */ 	sub.s	$f2,$f4,$f0
/*  f0993cc:	3c014000 */ 	lui	$at,0x4000
/*  f0993d0:	44814000 */ 	mtc1	$at,$f8
/*  f0993d4:	c64c0688 */ 	lwc1	$f12,0x688($s2)
/*  f0993d8:	46081083 */ 	div.s	$f2,$f2,$f8
/*  f0993dc:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0993e0:	00000000 */ 	nop
/*  f0993e4:	45000011 */ 	bc1f	.JF0f09942c
/*  f0993e8:	00000000 */ 	nop
/*  f0993ec:	0c00749a */ 	jal	modelGetAbsAnimSpeed
/*  f0993f0:	e7a20084 */ 	swc1	$f2,0x84($sp)
/*  f0993f4:	c7a20084 */ 	lwc1	$f2,0x84($sp)
/*  f0993f8:	02802025 */ 	move	$a0,$s4
/*  f0993fc:	46001283 */ 	div.s	$f10,$f2,$f0
/*  f099400:	4600540d */ 	trunc.w.s	$f16,$f10
/*  f099404:	440c8000 */ 	mfc1	$t4,$f16
/*  f099408:	0c00749a */ 	jal	modelGetAbsAnimSpeed
/*  f09940c:	ae4c0684 */ 	sw	$t4,0x684($s2)
/*  f099410:	8e4d0684 */ 	lw	$t5,0x684($s2)
/*  f099414:	448d9000 */ 	mtc1	$t5,$f18
/*  f099418:	00000000 */ 	nop
/*  f09941c:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f099420:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f099424:	e6440688 */ 	swc1	$f4,0x688($s2)
/*  f099428:	c64c0688 */ 	lwc1	$f12,0x688($s2)
.JF0f09942c:
/*  f09942c:	10000032 */ 	b	.JF0f0994f8
/*  f099430:	46146380 */ 	add.s	$f14,$f12,$f20
/*  f099434:	8e4e0690 */ 	lw	$t6,0x690($s2)
.JF0f099438:
/*  f099438:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f09943c:	0703002f */ 	bgezl	$t8,.JF0f0994fc
/*  f099440:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f099444:	96260002 */ 	lhu	$a2,0x2($s1)
/*  f099448:	3c014f80 */ 	lui	$at,0x4f80
/*  f09944c:	44864000 */ 	mtc1	$a2,$f8
/*  f099450:	04c10004 */ 	bgez	$a2,.JF0f099464
/*  f099454:	468040a0 */ 	cvt.s.w	$f2,$f8
/*  f099458:	44815000 */ 	mtc1	$at,$f10
/*  f09945c:	00000000 */ 	nop
/*  f099460:	460a1080 */ 	add.s	$f2,$f2,$f10
.JF0f099464:
/*  f099464:	460e103e */ 	c.le.s	$f2,$f14
/*  f099468:	00000000 */ 	nop
/*  f09946c:	45020023 */ 	bc1fl	.JF0f0994fc
/*  f099470:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f099474:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f099478:	00000000 */ 	nop
/*  f09947c:	4502001f */ 	bc1fl	.JF0f0994fc
/*  f099480:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f099484:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f099488:	02802025 */ 	move	$a0,$s4
/*  f09948c:	4502001b */ 	bc1fl	.JF0f0994fc
/*  f099490:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f099494:	460e103e */ 	c.le.s	$f2,$f14
/*  f099498:	44809000 */ 	mtc1	$zero,$f18
/*  f09949c:	46007006 */ 	mov.s	$f0,$f14
/*  f0994a0:	4502000c */ 	bc1fl	.JF0f0994d4
/*  f0994a4:	ae400684 */ 	sw	$zero,0x684($s2)
/*  f0994a8:	8e390004 */ 	lw	$t9,0x4($s1)
/*  f0994ac:	03264823 */ 	subu	$t1,$t9,$a2
/*  f0994b0:	44898000 */ 	mtc1	$t1,$f16
/*  f0994b4:	00000000 */ 	nop
/*  f0994b8:	46808320 */ 	cvt.s.w	$f12,$f16
/*  f0994bc:	460c0000 */ 	add.s	$f0,$f0,$f12
.JF0f0994c0:
/*  f0994c0:	4600103e */ 	c.le.s	$f2,$f0
/*  f0994c4:	00000000 */ 	nop
/*  f0994c8:	4503fffd */ 	bc1tl	.JF0f0994c0
/*  f0994cc:	460c0000 */ 	add.s	$f0,$f0,$f12
/*  f0994d0:	ae400684 */ 	sw	$zero,0x684($s2)
.JF0f0994d4:
/*  f0994d4:	e6520688 */ 	swc1	$f18,0x688($s2)
/*  f0994d8:	44050000 */ 	mfc1	$a1,$f0
/*  f0994dc:	46000506 */ 	mov.s	$f20,$f0
/*  f0994e0:	0c0077fe */ 	jal	model0001e018
/*  f0994e4:	e7a00080 */ 	swc1	$f0,0x80($sp)
/*  f0994e8:	924a0691 */ 	lbu	$t2,0x691($s2)
/*  f0994ec:	c7ae0080 */ 	lwc1	$f14,0x80($sp)
/*  f0994f0:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f0994f4:	a24b0691 */ 	sb	$t3,0x691($s2)
.JF0f0994f8:
/*  f0994f8:	8fac014c */ 	lw	$t4,0x14c($sp)
.JF0f0994fc:
/*  f0994fc:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f099500:	5180ff4b */ 	beqzl	$t4,.JF0f099230
/*  f099504:	92230000 */ 	lbu	$v1,0x0($s1)
/*  f099508:	5a000015 */ 	blezl	$s0,.JF0f099560
/*  f09950c:	02802025 */ 	move	$a0,$s4
/*  f099510:	1a000012 */ 	blez	$s0,.JF0f09955c
/*  f099514:	00001025 */ 	move	$v0,$zero
/*  f099518:	27a3010c */ 	addiu	$v1,$sp,0x10c
/*  f09951c:	27a800d0 */ 	addiu	$t0,$sp,0xd0
.JF0f099520:
/*  f099520:	84640002 */ 	lh	$a0,0x2($v1)
/*  f099524:	8d050000 */ 	lw	$a1,0x0($t0)
/*  f099528:	afa80058 */ 	sw	$t0,0x58($sp)
/*  f09952c:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f099530:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f099534:	02403025 */ 	move	$a2,$s2
/*  f099538:	0fc26305 */ 	jal	bgunSetPartVisible
/*  f09953c:	8fa70164 */ 	lw	$a3,0x164($sp)
/*  f099540:	8fa2007c */ 	lw	$v0,0x7c($sp)
/*  f099544:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f099548:	8fa80058 */ 	lw	$t0,0x58($sp)
/*  f09954c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f099550:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f099554:	1450fff2 */ 	bne	$v0,$s0,.JF0f099520
/*  f099558:	25080004 */ 	addiu	$t0,$t0,0x4
.JF0f09955c:
/*  f09955c:	02802025 */ 	move	$a0,$s4
.JF0f099560:
/*  f099560:	3c054080 */ 	lui	$a1,0x4080
/*  f099564:	0c0077e3 */ 	jal	modelSetAnimPlaySpeed
/*  f099568:	24060000 */ 	li	$a2,0x0
/*  f09956c:	02802025 */ 	move	$a0,$s4
/*  f099570:	8e450684 */ 	lw	$a1,0x684($s2)
/*  f099574:	0c007b7e */ 	jal	model0001ee18
/*  f099578:	24060001 */ 	li	$a2,0x1
/*  f09957c:	0fc263bf */ 	jal	bgun0f09815c
/*  f099580:	02402025 */ 	move	$a0,$s2
/*  f099584:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
/*  f099588:	46000386 */ 	mov.s	$f14,$f0
/*  f09958c:	00004025 */ 	move	$t0,$zero
/*  f099590:	10600069 */ 	beqz	$v1,.JF0f099738
/*  f099594:	00608025 */ 	move	$s0,$v1
/*  f099598:	3c013f80 */ 	lui	$at,0x3f80
/*  f09959c:	44813000 */ 	mtc1	$at,$f6
/*  f0995a0:	00008825 */ 	move	$s1,$zero
/*  f0995a4:	10600064 */ 	beqz	$v1,.JF0f099738
/*  f0995a8:	e7a60070 */ 	swc1	$f6,0x70($sp)
/*  f0995ac:	24140009 */ 	li	$s4,0x9
/*  f0995b0:	24130005 */ 	li	$s3,0x5
.JF0f0995b4:
/*  f0995b4:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f0995b8:	54600004 */ 	bnezl	$v1,.JF0f0995cc
/*  f0995bc:	960d0002 */ 	lhu	$t5,0x2($s0)
/*  f0995c0:	1000005b */ 	b	.JF0f099730
/*  f0995c4:	24080001 */ 	li	$t0,0x1
/*  f0995c8:	960d0002 */ 	lhu	$t5,0x2($s0)
.JF0f0995cc:
/*  f0995cc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0995d0:	448d2000 */ 	mtc1	$t5,$f4
/*  f0995d4:	05a10004 */ 	bgez	$t5,.JF0f0995e8
/*  f0995d8:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0995dc:	44814000 */ 	mtc1	$at,$f8
/*  f0995e0:	00000000 */ 	nop
/*  f0995e4:	46080000 */ 	add.s	$f0,$f0,$f8
.JF0f0995e8:
/*  f0995e8:	460e003e */ 	c.le.s	$f0,$f14
/*  f0995ec:	00000000 */ 	nop
/*  f0995f0:	4500004f */ 	bc1f	.JF0f099730
/*  f0995f4:	00000000 */ 	nop
/*  f0995f8:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f0995fc:	00000000 */ 	nop
/*  f099600:	4500004b */ 	bc1f	.JF0f099730
/*  f099604:	00000000 */ 	nop
/*  f099608:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f09960c:	00000000 */ 	nop
/*  f099610:	45000047 */ 	bc1f	.JF0f099730
/*  f099614:	00000000 */ 	nop
/*  f099618:	10730007 */ 	beq	$v1,$s3,.JF0f099638
/*  f09961c:	00000000 */ 	nop
/*  f099620:	10740039 */ 	beq	$v1,$s4,.JF0f099708
/*  f099624:	2401000b */ 	li	$at,0xb
/*  f099628:	5061002f */ 	beql	$v1,$at,.JF0f0996e8
/*  f09962c:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f099630:	1000003f */ 	b	.JF0f099730
/*  f099634:	00000000 */ 	nop
.JF0f099638:
/*  f099638:	12200016 */ 	beqz	$s1,.JF0f099694
/*  f09963c:	00002025 */ 	move	$a0,$zero
/*  f099640:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f099644:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f099648:	240f0001 */ 	li	$t7,0x1
/*  f09964c:	2418ffff */ 	li	$t8,-1
/*  f099650:	24190001 */ 	li	$t9,0x1
/*  f099654:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f099658:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f09965c:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f099660:	e7ae0158 */ 	swc1	$f14,0x158($sp)
/*  f099664:	afa80078 */ 	sw	$t0,0x78($sp)
/*  f099668:	00002025 */ 	move	$a0,$zero
/*  f09966c:	00002825 */ 	move	$a1,$zero
/*  f099670:	24067fff */ 	li	$a2,0x7fff
/*  f099674:	24070040 */ 	li	$a3,0x40
/*  f099678:	00008825 */ 	move	$s1,$zero
/*  f09967c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f099680:	0c0041b5 */ 	jal	snd00010718
/*  f099684:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f099688:	8fa80078 */ 	lw	$t0,0x78($sp)
/*  f09968c:	10000028 */ 	b	.JF0f099730
/*  f099690:	c7ae0158 */ 	lwc1	$f14,0x158($sp)
.JF0f099694:
/*  f099694:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f099698:	3c013f80 */ 	lui	$at,0x3f80
/*  f09969c:	44818000 */ 	mtc1	$at,$f16
/*  f0996a0:	240a0001 */ 	li	$t2,0x1
/*  f0996a4:	240bffff */ 	li	$t3,-1
/*  f0996a8:	240c0001 */ 	li	$t4,0x1
/*  f0996ac:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0996b0:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0996b4:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0996b8:	e7ae0158 */ 	swc1	$f14,0x158($sp)
/*  f0996bc:	afa80078 */ 	sw	$t0,0x78($sp)
/*  f0996c0:	00002825 */ 	move	$a1,$zero
/*  f0996c4:	24067fff */ 	li	$a2,0x7fff
/*  f0996c8:	24070040 */ 	li	$a3,0x40
/*  f0996cc:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0996d0:	0c0041b5 */ 	jal	snd00010718
/*  f0996d4:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f0996d8:	8fa80078 */ 	lw	$t0,0x78($sp)
/*  f0996dc:	10000014 */ 	b	.JF0f099730
/*  f0996e0:	c7ae0158 */ 	lwc1	$f14,0x158($sp)
/*  f0996e4:	8e0d0004 */ 	lw	$t5,0x4($s0)
.JF0f0996e8:
/*  f0996e8:	3c01447a */ 	lui	$at,0x447a
/*  f0996ec:	44812000 */ 	mtc1	$at,$f4
/*  f0996f0:	448d9000 */ 	mtc1	$t5,$f18
/*  f0996f4:	24110001 */ 	li	$s1,0x1
/*  f0996f8:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f0996fc:	46043203 */ 	div.s	$f8,$f6,$f4
/*  f099700:	1000000b */ 	b	.JF0f099730
/*  f099704:	e7a80070 */ 	swc1	$f8,0x70($sp)
.JF0f099708:
/*  f099708:	8e4e0690 */ 	lw	$t6,0x690($s2)
/*  f09970c:	924b0690 */ 	lbu	$t3,0x690($s2)
/*  f099710:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f099714:	000fc742 */ 	srl	$t8,$t7,0x1d
/*  f099718:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f09971c:	00194880 */ 	sll	$t1,$t9,0x2
/*  f099720:	312a001c */ 	andi	$t2,$t1,0x1c
/*  f099724:	316cffe3 */ 	andi	$t4,$t3,0xffe3
/*  f099728:	014c6825 */ 	or	$t5,$t2,$t4
/*  f09972c:	a24d0690 */ 	sb	$t5,0x690($s2)
.JF0f099730:
/*  f099730:	1100ffa0 */ 	beqz	$t0,.JF0f0995b4
/*  f099734:	26100008 */ 	addiu	$s0,$s0,0x8
.JF0f099738:
/*  f099738:	8fbf004c */ 	lw	$ra,0x4c($sp)
.JF0f09973c:
/*  f09973c:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f099740:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f099744:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f099748:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f09974c:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f099750:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f099754:	03e00008 */ 	jr	$ra
/*  f099758:	27bd0160 */ 	addiu	$sp,$sp,0x160
);
#elif VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel bgun0f0981e8
.late_rodata
glabel var7f1ad398pf
.word 0x461c4000
glabel var7f1ad39cpf
.word 0x3f451eb8
glabel var7f1ad3a0pf
.word 0x3f333333
glabel var7f1ad3a4pf
.word 0x3f99999a
glabel var7f1ad3a8pf
.word 0x3f555555
glabel var7f1ad3acpf
.word 0x3f99999a
.text
/*  f098108:	27bdfea0 */ 	addiu	$sp,$sp,-352
/*  f09810c:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f098110:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f098114:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f098118:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f09811c:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f098120:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f098124:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f098128:	afa50164 */ 	sw	$a1,0x164($sp)
/*  f09812c:	908e0690 */ 	lbu	$t6,0x690($a0)
/*  f098130:	8c98068c */ 	lw	$t8,0x68c($a0)
/*  f098134:	24010002 */ 	li	$at,0x2
/*  f098138:	31cfffe3 */ 	andi	$t7,$t6,0xffe3
/*  f09813c:	00809025 */ 	move	$s2,$a0
/*  f098140:	1701000f */ 	bne	$t8,$at,.PF0f098180
/*  f098144:	a08f0690 */ 	sb	$t7,0x690($a0)
/*  f098148:	0fc2601f */ 	jal	bgun0f09815c
/*  f09814c:	00000000 */ 	nop
/*  f098150:	46000506 */ 	mov.s	$f20,$f0
/*  f098154:	0c0073fa */ 	jal	modelGetNumAnimFrames
/*  f098158:	26440384 */ 	addiu	$a0,$s2,0x384
/*  f09815c:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f098160:	44992000 */ 	mtc1	$t9,$f4
/*  f098164:	00000000 */ 	nop
/*  f098168:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f09816c:	4614303e */ 	c.le.s	$f6,$f20
/*  f098170:	00000000 */ 	nop
/*  f098174:	45020003 */ 	bc1fl	.PF0f098184
/*  f098178:	8e480680 */ 	lw	$t0,0x680($s2)
/*  f09817c:	ae40068c */ 	sw	$zero,0x68c($s2)
.PF0f098180:
/*  f098180:	8e480680 */ 	lw	$t0,0x680($s2)
.PF0f098184:
/*  f098184:	8e49068c */ 	lw	$t1,0x68c($s2)
/*  f098188:	29020000 */ 	slti	$v0,$t0,0x0
/*  f09818c:	392a0002 */ 	xori	$t2,$t1,0x2
/*  f098190:	2d4a0001 */ 	sltiu	$t2,$t2,0x1
/*  f098194:	38420001 */ 	xori	$v0,$v0,0x1
/*  f098198:	01425825 */ 	or	$t3,$t2,$v0
/*  f09819c:	516001d2 */ 	beqzl	$t3,.PF0f0988e8
/*  f0981a0:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0981a4:	44801000 */ 	mtc1	$zero,$f2
/*  f0981a8:	c64806d0 */ 	lwc1	$f8,0x6d0($s2)
/*  f0981ac:	26540384 */ 	addiu	$s4,$s2,0x384
/*  f0981b0:	4608103c */ 	c.lt.s	$f2,$f8
/*  f0981b4:	00000000 */ 	nop
/*  f0981b8:	45000006 */ 	bc1f	.PF0f0981d4
/*  f0981bc:	00000000 */ 	nop
/*  f0981c0:	8e480680 */ 	lw	$t0,0x680($s2)
/*  f0981c4:	ae400684 */ 	sw	$zero,0x684($s2)
/*  f0981c8:	e6420688 */ 	swc1	$f2,0x688($s2)
/*  f0981cc:	29020000 */ 	slti	$v0,$t0,0x0
/*  f0981d0:	38420001 */ 	xori	$v0,$v0,0x1
.PF0f0981d4:
/*  f0981d4:	5040005a */ 	beqzl	$v0,.PF0f098340
/*  f0981d8:	8e4d0690 */ 	lw	$t5,0x690($s2)
/*  f0981dc:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
/*  f0981e0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0981e4:	924d06d6 */ 	lbu	$t5,0x6d6($s2)
/*  f0981e8:	8c6c0004 */ 	lw	$t4,0x4($v1)
/*  f0981ec:	44810000 */ 	mtc1	$at,$f0
/*  f0981f0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0981f4:	448c5000 */ 	mtc1	$t4,$f10
/*  f0981f8:	c432d398 */ 	lwc1	$f18,-0x2c68($at)
/*  f0981fc:	31ae0001 */ 	andi	$t6,$t5,0x1
/*  f098200:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f098204:	3c0f800a */ 	lui	$t7,0x800a
/*  f098208:	11c0001a */ 	beqz	$t6,.PF0f098274
/*  f09820c:	46128503 */ 	div.s	$f20,$f16,$f18
/*  f098210:	8defa794 */ 	lw	$t7,-0x586c($t7)
/*  f098214:	81f80de4 */ 	lb	$t8,0xde4($t7)
/*  f098218:	13000016 */ 	beqz	$t8,.PF0f098274
/*  f09821c:	00000000 */ 	nop
/*  f098220:	0c004ad4 */ 	jal	random
/*  f098224:	00000000 */ 	nop
/*  f098228:	44822000 */ 	mtc1	$v0,$f4
/*  f09822c:	3c014f80 */ 	lui	$at,0x4f80
/*  f098230:	04410004 */ 	bgez	$v0,.PF0f098244
/*  f098234:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f098238:	44814000 */ 	mtc1	$at,$f8
/*  f09823c:	00000000 */ 	nop
/*  f098240:	46083180 */ 	add.s	$f6,$f6,$f8
.PF0f098244:
/*  f098244:	3c012f80 */ 	lui	$at,0x2f80
/*  f098248:	44815000 */ 	mtc1	$at,$f10
/*  f09824c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f098250:	c432d39c */ 	lwc1	$f18,-0x2c64($at)
/*  f098254:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f098258:	3c017f1b */ 	lui	$at,0x7f1b
/*  f09825c:	c428d3a0 */ 	lwc1	$f8,-0x2c60($at)
/*  f098260:	44801000 */ 	mtc1	$zero,$f2
/*  f098264:	8e480680 */ 	lw	$t0,0x680($s2)
/*  f098268:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
/*  f09826c:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f098270:	46082000 */ 	add.s	$f0,$f4,$f8
.PF0f098274:
/*  f098274:	10600018 */ 	beqz	$v1,.PF0f0982d8
/*  f098278:	02802025 */ 	move	$a0,$s4
/*  f09827c:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f098280:	00082c00 */ 	sll	$a1,$t0,0x10
/*  f098284:	0005cc03 */ 	sra	$t9,$a1,0x10
/*  f098288:	45000013 */ 	bc1f	.PF0f0982d8
/*  f09828c:	00000000 */ 	nop
/*  f098290:	46140182 */ 	mul.s	$f6,$f0,$f20
/*  f098294:	44071000 */ 	mfc1	$a3,$f2
/*  f098298:	02802025 */ 	move	$a0,$s4
/*  f09829c:	03202825 */ 	move	$a1,$t9
/*  f0982a0:	00003025 */ 	move	$a2,$zero
/*  f0982a4:	e7a20014 */ 	swc1	$f2,0x14($sp)
/*  f0982a8:	0c0076a7 */ 	jal	modelSetAnimation
/*  f0982ac:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f0982b0:	0c0073fa */ 	jal	modelGetNumAnimFrames
/*  f0982b4:	02802025 */ 	move	$a0,$s4
/*  f0982b8:	44825000 */ 	mtc1	$v0,$f10
/*  f0982bc:	02802025 */ 	move	$a0,$s4
/*  f0982c0:	468052a0 */ 	cvt.s.w	$f10,$f10
/*  f0982c4:	44055000 */ 	mfc1	$a1,$f10
/*  f0982c8:	0c00777a */ 	jal	model0001e018
/*  f0982cc:	00000000 */ 	nop
/*  f0982d0:	1000000b */ 	b	.PF0f098300
/*  f0982d4:	240affff */ 	li	$t2,-1
.PF0f0982d8:
/*  f0982d8:	46140402 */ 	mul.s	$f16,$f0,$f20
/*  f0982dc:	00082c00 */ 	sll	$a1,$t0,0x10
/*  f0982e0:	00054c03 */ 	sra	$t1,$a1,0x10
/*  f0982e4:	44071000 */ 	mfc1	$a3,$f2
/*  f0982e8:	01202825 */ 	move	$a1,$t1
/*  f0982ec:	00003025 */ 	move	$a2,$zero
/*  f0982f0:	e7a20014 */ 	swc1	$f2,0x14($sp)
/*  f0982f4:	0c0076a7 */ 	jal	modelSetAnimation
/*  f0982f8:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f0982fc:	240affff */ 	li	$t2,-1
.PF0f098300:
/*  f098300:	240b0002 */ 	li	$t3,0x2
/*  f098304:	ae4a0680 */ 	sw	$t2,0x680($s2)
/*  f098308:	ae4b068c */ 	sw	$t3,0x68c($s2)
/*  f09830c:	0c007416 */ 	jal	modelGetAbsAnimSpeed
/*  f098310:	02802025 */ 	move	$a0,$s4
/*  f098314:	8e4c0684 */ 	lw	$t4,0x684($s2)
/*  f098318:	3c017f1b */ 	lui	$at,0x7f1b
/*  f09831c:	c428d3a4 */ 	lwc1	$f8,-0x2c5c($at)
/*  f098320:	448c9000 */ 	mtc1	$t4,$f18
/*  f098324:	44801000 */ 	mtc1	$zero,$f2
/*  f098328:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f09832c:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f098330:	00000000 */ 	nop
/*  f098334:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f098338:	e64a0688 */ 	swc1	$f10,0x688($s2)
/*  f09833c:	8e4d0690 */ 	lw	$t5,0x690($s2)
.PF0f098340:
/*  f098340:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f098344:	05e10003 */ 	bgez	$t7,.PF0f098354
/*  f098348:	00000000 */ 	nop
/*  f09834c:	ae400684 */ 	sw	$zero,0x684($s2)
/*  f098350:	e6420688 */ 	swc1	$f2,0x688($s2)
.PF0f098354:
/*  f098354:	0fc2601f */ 	jal	bgun0f09815c
/*  f098358:	02402025 */ 	move	$a0,$s2
/*  f09835c:	44809000 */ 	mtc1	$zero,$f18
/*  f098360:	c6500688 */ 	lwc1	$f16,0x688($s2)
/*  f098364:	46000506 */ 	mov.s	$f20,$f0
/*  f098368:	46120032 */ 	c.eq.s	$f0,$f18
/*  f09836c:	46008380 */ 	add.s	$f14,$f16,$f0
/*  f098370:	4502000b */ 	bc1fl	.PF0f0983a0
/*  f098374:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
/*  f098378:	44802000 */ 	mtc1	$zero,$f4
/*  f09837c:	3c013f80 */ 	lui	$at,0x3f80
/*  f098380:	460e203c */ 	c.lt.s	$f4,$f14
/*  f098384:	00000000 */ 	nop
/*  f098388:	45020005 */ 	bc1fl	.PF0f0983a0
/*  f09838c:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
/*  f098390:	44814000 */ 	mtc1	$at,$f8
/*  f098394:	00000000 */ 	nop
/*  f098398:	46080501 */ 	sub.s	$f20,$f0,$f8
/*  f09839c:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
.PF0f0983a0:
/*  f0983a0:	106000d8 */ 	beqz	$v1,.PF0f098704
/*  f0983a4:	00608825 */ 	move	$s1,$v1
/*  f0983a8:	106000d6 */ 	beqz	$v1,.PF0f098704
/*  f0983ac:	afa0014c */ 	sw	$zero,0x14c($sp)
/*  f0983b0:	00008025 */ 	move	$s0,$zero
/*  f0983b4:	24130001 */ 	li	$s3,0x1
/*  f0983b8:	92230000 */ 	lbu	$v1,0x0($s1)
.PF0f0983bc:
/*  f0983bc:	14600003 */ 	bnez	$v1,.PF0f0983cc
/*  f0983c0:	00000000 */ 	nop
/*  f0983c4:	100000b6 */ 	b	.PF0f0986a0
/*  f0983c8:	afb3014c */ 	sw	$s3,0x14c($sp)
.PF0f0983cc:
/*  f0983cc:	12630003 */ 	beq	$s3,$v1,.PF0f0983dc
/*  f0983d0:	24010002 */ 	li	$at,0x2
/*  f0983d4:	54610036 */ 	bnel	$v1,$at,.PF0f0984b0
/*  f0983d8:	24010003 */ 	li	$at,0x3
.PF0f0983dc:
/*  f0983dc:	96260002 */ 	lhu	$a2,0x2($s1)
/*  f0983e0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0983e4:	2405ffff */ 	li	$a1,-1
/*  f0983e8:	44863000 */ 	mtc1	$a2,$f6
/*  f0983ec:	27ab0094 */ 	addiu	$t3,$sp,0x94
/*  f0983f0:	04c10004 */ 	bgez	$a2,.PF0f098404
/*  f0983f4:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0983f8:	44818000 */ 	mtc1	$at,$f16
/*  f0983fc:	00000000 */ 	nop
/*  f098400:	46105280 */ 	add.s	$f10,$f10,$f16
.PF0f098404:
/*  f098404:	460e503e */ 	c.le.s	$f10,$f14
/*  f098408:	2401ffff */ 	li	$at,-1
/*  f09840c:	450200a5 */ 	bc1fl	.PF0f0986a4
/*  f098410:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f098414:	1a00000a */ 	blez	$s0,.PF0f098440
/*  f098418:	00001025 */ 	move	$v0,$zero
/*  f09841c:	8e240004 */ 	lw	$a0,0x4($s1)
/*  f098420:	27a3010c */ 	addiu	$v1,$sp,0x10c
.PF0f098424:
/*  f098424:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f098428:	54980003 */ 	bnel	$a0,$t8,.PF0f098438
/*  f09842c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f098430:	00402825 */ 	move	$a1,$v0
/*  f098434:	24420001 */ 	addiu	$v0,$v0,0x1
.PF0f098438:
/*  f098438:	1450fffa */ 	bne	$v0,$s0,.PF0f098424
/*  f09843c:	24630004 */ 	addiu	$v1,$v1,0x4
.PF0f098440:
/*  f098440:	14a1000a */ 	bne	$a1,$at,.PF0f09846c
/*  f098444:	2409ffff */ 	li	$t1,-1
/*  f098448:	8e240004 */ 	lw	$a0,0x4($s1)
/*  f09844c:	02002825 */ 	move	$a1,$s0
/*  f098450:	00051080 */ 	sll	$v0,$a1,0x2
/*  f098454:	03a2c821 */ 	addu	$t9,$sp,$v0
/*  f098458:	03a25021 */ 	addu	$t2,$sp,$v0
/*  f09845c:	af24010c */ 	sw	$a0,0x10c($t9)
/*  f098460:	ad490094 */ 	sw	$t1,0x94($t2)
/*  f098464:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f098468:	96260002 */ 	lhu	$a2,0x2($s1)
.PF0f09846c:
/*  f09846c:	00051080 */ 	sll	$v0,$a1,0x2
/*  f098470:	004b1821 */ 	addu	$v1,$v0,$t3
/*  f098474:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f098478:	0186082a */ 	slt	$at,$t4,$a2
/*  f09847c:	50200089 */ 	beqzl	$at,.PF0f0986a4
/*  f098480:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f098484:	ac660000 */ 	sw	$a2,0x0($v1)
/*  f098488:	922d0000 */ 	lbu	$t5,0x0($s1)
/*  f09848c:	03a27821 */ 	addu	$t7,$sp,$v0
/*  f098490:	03a27021 */ 	addu	$t6,$sp,$v0
/*  f098494:	166d0003 */ 	bne	$s3,$t5,.PF0f0984a4
/*  f098498:	00000000 */ 	nop
/*  f09849c:	10000080 */ 	b	.PF0f0986a0
/*  f0984a0:	add300d0 */ 	sw	$s3,0xd0($t6)
.PF0f0984a4:
/*  f0984a4:	1000007e */ 	b	.PF0f0986a0
/*  f0984a8:	ade000d0 */ 	sw	$zero,0xd0($t7)
/*  f0984ac:	24010003 */ 	li	$at,0x3
.PF0f0984b0:
/*  f0984b0:	10610005 */ 	beq	$v1,$at,.PF0f0984c8
/*  f0984b4:	24010008 */ 	li	$at,0x8
/*  f0984b8:	50610049 */ 	beql	$v1,$at,.PF0f0985e0
/*  f0984bc:	8e4e0690 */ 	lw	$t6,0x690($s2)
/*  f0984c0:	10000078 */ 	b	.PF0f0986a4
/*  f0984c4:	8fac014c */ 	lw	$t4,0x14c($sp)
.PF0f0984c8:
/*  f0984c8:	8e580690 */ 	lw	$t8,0x690($s2)
/*  f0984cc:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f0984d0:	53200074 */ 	beqzl	$t9,.PF0f0986a4
/*  f0984d4:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f0984d8:	96290002 */ 	lhu	$t1,0x2($s1)
/*  f0984dc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0984e0:	44899000 */ 	mtc1	$t1,$f18
/*  f0984e4:	05210004 */ 	bgez	$t1,.PF0f0984f8
/*  f0984e8:	468090a0 */ 	cvt.s.w	$f2,$f18
/*  f0984ec:	44812000 */ 	mtc1	$at,$f4
/*  f0984f0:	00000000 */ 	nop
/*  f0984f4:	46041080 */ 	add.s	$f2,$f2,$f4
.PF0f0984f8:
/*  f0984f8:	460e103e */ 	c.le.s	$f2,$f14
/*  f0984fc:	00000000 */ 	nop
/*  f098500:	45020068 */ 	bc1fl	.PF0f0986a4
/*  f098504:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f098508:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f09850c:	00000000 */ 	nop
/*  f098510:	45020064 */ 	bc1fl	.PF0f0986a4
/*  f098514:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f098518:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f09851c:	00000000 */ 	nop
/*  f098520:	45020060 */ 	bc1fl	.PF0f0986a4
/*  f098524:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f098528:	0fc2601f */ 	jal	bgun0f09815c
/*  f09852c:	02402025 */ 	move	$a0,$s2
/*  f098530:	962a0002 */ 	lhu	$t2,0x2($s1)
/*  f098534:	3c014f80 */ 	lui	$at,0x4f80
/*  f098538:	02802025 */ 	move	$a0,$s4
/*  f09853c:	448a4000 */ 	mtc1	$t2,$f8
/*  f098540:	05410004 */ 	bgez	$t2,.PF0f098554
/*  f098544:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f098548:	44818000 */ 	mtc1	$at,$f16
/*  f09854c:	00000000 */ 	nop
/*  f098550:	46103180 */ 	add.s	$f6,$f6,$f16
.PF0f098554:
/*  f098554:	46003081 */ 	sub.s	$f2,$f6,$f0
/*  f098558:	3c014000 */ 	lui	$at,0x4000
/*  f09855c:	44815000 */ 	mtc1	$at,$f10
/*  f098560:	c64c0688 */ 	lwc1	$f12,0x688($s2)
/*  f098564:	460a1083 */ 	div.s	$f2,$f2,$f10
/*  f098568:	460c103c */ 	c.lt.s	$f2,$f12
/*  f09856c:	00000000 */ 	nop
/*  f098570:	45000018 */ 	bc1f	.PF0f0985d4
/*  f098574:	00000000 */ 	nop
/*  f098578:	0c007416 */ 	jal	modelGetAbsAnimSpeed
/*  f09857c:	e7a20084 */ 	swc1	$f2,0x84($sp)
/*  f098580:	3c017f1b */ 	lui	$at,0x7f1b
/*  f098584:	c432d3a8 */ 	lwc1	$f18,-0x2c58($at)
/*  f098588:	c7a20084 */ 	lwc1	$f2,0x84($sp)
/*  f09858c:	02802025 */ 	move	$a0,$s4
/*  f098590:	46121102 */ 	mul.s	$f4,$f2,$f18
/*  f098594:	46002203 */ 	div.s	$f8,$f4,$f0
/*  f098598:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f09859c:	440c8000 */ 	mfc1	$t4,$f16
/*  f0985a0:	0c007416 */ 	jal	modelGetAbsAnimSpeed
/*  f0985a4:	ae4c0684 */ 	sw	$t4,0x684($s2)
/*  f0985a8:	8e4d0684 */ 	lw	$t5,0x684($s2)
/*  f0985ac:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0985b0:	c432d3ac */ 	lwc1	$f18,-0x2c54($at)
/*  f0985b4:	448d3000 */ 	mtc1	$t5,$f6
/*  f0985b8:	00000000 */ 	nop
/*  f0985bc:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0985c0:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f0985c4:	00000000 */ 	nop
/*  f0985c8:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f0985cc:	e6480688 */ 	swc1	$f8,0x688($s2)
/*  f0985d0:	c64c0688 */ 	lwc1	$f12,0x688($s2)
.PF0f0985d4:
/*  f0985d4:	10000032 */ 	b	.PF0f0986a0
/*  f0985d8:	46146380 */ 	add.s	$f14,$f12,$f20
/*  f0985dc:	8e4e0690 */ 	lw	$t6,0x690($s2)
.PF0f0985e0:
/*  f0985e0:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f0985e4:	0703002f */ 	bgezl	$t8,.PF0f0986a4
/*  f0985e8:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f0985ec:	96260002 */ 	lhu	$a2,0x2($s1)
/*  f0985f0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0985f4:	44868000 */ 	mtc1	$a2,$f16
/*  f0985f8:	04c10004 */ 	bgez	$a2,.PF0f09860c
/*  f0985fc:	468080a0 */ 	cvt.s.w	$f2,$f16
/*  f098600:	44813000 */ 	mtc1	$at,$f6
/*  f098604:	00000000 */ 	nop
/*  f098608:	46061080 */ 	add.s	$f2,$f2,$f6
.PF0f09860c:
/*  f09860c:	460e103e */ 	c.le.s	$f2,$f14
/*  f098610:	00000000 */ 	nop
/*  f098614:	45020023 */ 	bc1fl	.PF0f0986a4
/*  f098618:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f09861c:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f098620:	00000000 */ 	nop
/*  f098624:	4502001f */ 	bc1fl	.PF0f0986a4
/*  f098628:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f09862c:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f098630:	02802025 */ 	move	$a0,$s4
/*  f098634:	4502001b */ 	bc1fl	.PF0f0986a4
/*  f098638:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f09863c:	460e103e */ 	c.le.s	$f2,$f14
/*  f098640:	44809000 */ 	mtc1	$zero,$f18
/*  f098644:	46007006 */ 	mov.s	$f0,$f14
/*  f098648:	4502000c */ 	bc1fl	.PF0f09867c
/*  f09864c:	ae400684 */ 	sw	$zero,0x684($s2)
/*  f098650:	8e390004 */ 	lw	$t9,0x4($s1)
/*  f098654:	03264823 */ 	subu	$t1,$t9,$a2
/*  f098658:	44895000 */ 	mtc1	$t1,$f10
/*  f09865c:	00000000 */ 	nop
/*  f098660:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f098664:	460c0000 */ 	add.s	$f0,$f0,$f12
.PF0f098668:
/*  f098668:	4600103e */ 	c.le.s	$f2,$f0
/*  f09866c:	00000000 */ 	nop
/*  f098670:	4503fffd */ 	bc1tl	.PF0f098668
/*  f098674:	460c0000 */ 	add.s	$f0,$f0,$f12
/*  f098678:	ae400684 */ 	sw	$zero,0x684($s2)
.PF0f09867c:
/*  f09867c:	e6520688 */ 	swc1	$f18,0x688($s2)
/*  f098680:	44050000 */ 	mfc1	$a1,$f0
/*  f098684:	46000506 */ 	mov.s	$f20,$f0
/*  f098688:	0c00777a */ 	jal	model0001e018
/*  f09868c:	e7a00080 */ 	swc1	$f0,0x80($sp)
/*  f098690:	924a0691 */ 	lbu	$t2,0x691($s2)
/*  f098694:	c7ae0080 */ 	lwc1	$f14,0x80($sp)
/*  f098698:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f09869c:	a24b0691 */ 	sb	$t3,0x691($s2)
.PF0f0986a0:
/*  f0986a0:	8fac014c */ 	lw	$t4,0x14c($sp)
.PF0f0986a4:
/*  f0986a4:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f0986a8:	5180ff44 */ 	beqzl	$t4,.PF0f0983bc
/*  f0986ac:	92230000 */ 	lbu	$v1,0x0($s1)
/*  f0986b0:	5a000015 */ 	blezl	$s0,.PF0f098708
/*  f0986b4:	3c054099 */ 	lui	$a1,0x4099
/*  f0986b8:	1a000012 */ 	blez	$s0,.PF0f098704
/*  f0986bc:	00001025 */ 	move	$v0,$zero
/*  f0986c0:	27a3010c */ 	addiu	$v1,$sp,0x10c
/*  f0986c4:	27a800d0 */ 	addiu	$t0,$sp,0xd0
.PF0f0986c8:
/*  f0986c8:	84640002 */ 	lh	$a0,0x2($v1)
/*  f0986cc:	8d050000 */ 	lw	$a1,0x0($t0)
/*  f0986d0:	afa80058 */ 	sw	$t0,0x58($sp)
/*  f0986d4:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f0986d8:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f0986dc:	02403025 */ 	move	$a2,$s2
/*  f0986e0:	0fc25f65 */ 	jal	bgunSetPartVisible
/*  f0986e4:	8fa70164 */ 	lw	$a3,0x164($sp)
/*  f0986e8:	8fa2007c */ 	lw	$v0,0x7c($sp)
/*  f0986ec:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f0986f0:	8fa80058 */ 	lw	$t0,0x58($sp)
/*  f0986f4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0986f8:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f0986fc:	1450fff2 */ 	bne	$v0,$s0,.PF0f0986c8
/*  f098700:	25080004 */ 	addiu	$t0,$t0,0x4
.PF0f098704:
/*  f098704:	3c054099 */ 	lui	$a1,0x4099
.PF0f098708:
/*  f098708:	34a5999a */ 	ori	$a1,$a1,0x999a
/*  f09870c:	02802025 */ 	move	$a0,$s4
/*  f098710:	0c00775f */ 	jal	modelSetAnimPlaySpeed
/*  f098714:	24060000 */ 	li	$a2,0x0
/*  f098718:	02802025 */ 	move	$a0,$s4
/*  f09871c:	8e450684 */ 	lw	$a1,0x684($s2)
/*  f098720:	0c007afa */ 	jal	model0001ee18
/*  f098724:	24060001 */ 	li	$a2,0x1
/*  f098728:	0fc2601f */ 	jal	bgun0f09815c
/*  f09872c:	02402025 */ 	move	$a0,$s2
/*  f098730:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
/*  f098734:	46000386 */ 	mov.s	$f14,$f0
/*  f098738:	00004025 */ 	move	$t0,$zero
/*  f09873c:	10600069 */ 	beqz	$v1,.PF0f0988e4
/*  f098740:	00608025 */ 	move	$s0,$v1
/*  f098744:	3c013f80 */ 	lui	$at,0x3f80
/*  f098748:	44812000 */ 	mtc1	$at,$f4
/*  f09874c:	00008825 */ 	move	$s1,$zero
/*  f098750:	10600064 */ 	beqz	$v1,.PF0f0988e4
/*  f098754:	e7a40070 */ 	swc1	$f4,0x70($sp)
/*  f098758:	24140009 */ 	li	$s4,0x9
/*  f09875c:	24130005 */ 	li	$s3,0x5
.PF0f098760:
/*  f098760:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f098764:	54600004 */ 	bnezl	$v1,.PF0f098778
/*  f098768:	960d0002 */ 	lhu	$t5,0x2($s0)
/*  f09876c:	1000005b */ 	b	.PF0f0988dc
/*  f098770:	24080001 */ 	li	$t0,0x1
/*  f098774:	960d0002 */ 	lhu	$t5,0x2($s0)
.PF0f098778:
/*  f098778:	3c014f80 */ 	lui	$at,0x4f80
/*  f09877c:	448d4000 */ 	mtc1	$t5,$f8
/*  f098780:	05a10004 */ 	bgez	$t5,.PF0f098794
/*  f098784:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f098788:	44818000 */ 	mtc1	$at,$f16
/*  f09878c:	00000000 */ 	nop
/*  f098790:	46100000 */ 	add.s	$f0,$f0,$f16
.PF0f098794:
/*  f098794:	460e003e */ 	c.le.s	$f0,$f14
/*  f098798:	00000000 */ 	nop
/*  f09879c:	4500004f */ 	bc1f	.PF0f0988dc
/*  f0987a0:	00000000 */ 	nop
/*  f0987a4:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f0987a8:	00000000 */ 	nop
/*  f0987ac:	4500004b */ 	bc1f	.PF0f0988dc
/*  f0987b0:	00000000 */ 	nop
/*  f0987b4:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f0987b8:	00000000 */ 	nop
/*  f0987bc:	45000047 */ 	bc1f	.PF0f0988dc
/*  f0987c0:	00000000 */ 	nop
/*  f0987c4:	10730007 */ 	beq	$v1,$s3,.PF0f0987e4
/*  f0987c8:	00000000 */ 	nop
/*  f0987cc:	10740039 */ 	beq	$v1,$s4,.PF0f0988b4
/*  f0987d0:	2401000b */ 	li	$at,0xb
/*  f0987d4:	5061002f */ 	beql	$v1,$at,.PF0f098894
/*  f0987d8:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f0987dc:	1000003f */ 	b	.PF0f0988dc
/*  f0987e0:	00000000 */ 	nop
.PF0f0987e4:
/*  f0987e4:	12200016 */ 	beqz	$s1,.PF0f098840
/*  f0987e8:	00002025 */ 	move	$a0,$zero
/*  f0987ec:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f0987f0:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f0987f4:	240f0001 */ 	li	$t7,0x1
/*  f0987f8:	2418ffff */ 	li	$t8,-1
/*  f0987fc:	24190001 */ 	li	$t9,0x1
/*  f098800:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f098804:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f098808:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f09880c:	e7ae0158 */ 	swc1	$f14,0x158($sp)
/*  f098810:	afa80078 */ 	sw	$t0,0x78($sp)
/*  f098814:	00002025 */ 	move	$a0,$zero
/*  f098818:	00002825 */ 	move	$a1,$zero
/*  f09881c:	24067fff */ 	li	$a2,0x7fff
/*  f098820:	24070040 */ 	li	$a3,0x40
/*  f098824:	00008825 */ 	move	$s1,$zero
/*  f098828:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f09882c:	0c004125 */ 	jal	snd00010718
/*  f098830:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f098834:	8fa80078 */ 	lw	$t0,0x78($sp)
/*  f098838:	10000028 */ 	b	.PF0f0988dc
/*  f09883c:	c7ae0158 */ 	lwc1	$f14,0x158($sp)
.PF0f098840:
/*  f098840:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f098844:	3c013f80 */ 	lui	$at,0x3f80
/*  f098848:	44815000 */ 	mtc1	$at,$f10
/*  f09884c:	240a0001 */ 	li	$t2,0x1
/*  f098850:	240bffff */ 	li	$t3,-1
/*  f098854:	240c0001 */ 	li	$t4,0x1
/*  f098858:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f09885c:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f098860:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f098864:	e7ae0158 */ 	swc1	$f14,0x158($sp)
/*  f098868:	afa80078 */ 	sw	$t0,0x78($sp)
/*  f09886c:	00002825 */ 	move	$a1,$zero
/*  f098870:	24067fff */ 	li	$a2,0x7fff
/*  f098874:	24070040 */ 	li	$a3,0x40
/*  f098878:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f09887c:	0c004125 */ 	jal	snd00010718
/*  f098880:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f098884:	8fa80078 */ 	lw	$t0,0x78($sp)
/*  f098888:	10000014 */ 	b	.PF0f0988dc
/*  f09888c:	c7ae0158 */ 	lwc1	$f14,0x158($sp)
/*  f098890:	8e0d0004 */ 	lw	$t5,0x4($s0)
.PF0f098894:
/*  f098894:	3c01447a */ 	lui	$at,0x447a
/*  f098898:	44814000 */ 	mtc1	$at,$f8
/*  f09889c:	448d9000 */ 	mtc1	$t5,$f18
/*  f0988a0:	24110001 */ 	li	$s1,0x1
/*  f0988a4:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0988a8:	46082403 */ 	div.s	$f16,$f4,$f8
/*  f0988ac:	1000000b */ 	b	.PF0f0988dc
/*  f0988b0:	e7b00070 */ 	swc1	$f16,0x70($sp)
.PF0f0988b4:
/*  f0988b4:	8e4e0690 */ 	lw	$t6,0x690($s2)
/*  f0988b8:	924b0690 */ 	lbu	$t3,0x690($s2)
/*  f0988bc:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0988c0:	000fc742 */ 	srl	$t8,$t7,0x1d
/*  f0988c4:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f0988c8:	00194880 */ 	sll	$t1,$t9,0x2
/*  f0988cc:	312a001c */ 	andi	$t2,$t1,0x1c
/*  f0988d0:	316cffe3 */ 	andi	$t4,$t3,0xffe3
/*  f0988d4:	014c6825 */ 	or	$t5,$t2,$t4
/*  f0988d8:	a24d0690 */ 	sb	$t5,0x690($s2)
.PF0f0988dc:
/*  f0988dc:	1100ffa0 */ 	beqz	$t0,.PF0f098760
/*  f0988e0:	26100008 */ 	addiu	$s0,$s0,0x8
.PF0f0988e4:
/*  f0988e4:	8fbf004c */ 	lw	$ra,0x4c($sp)
.PF0f0988e8:
/*  f0988e8:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f0988ec:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f0988f0:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f0988f4:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f0988f8:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f0988fc:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f098900:	03e00008 */ 	jr	$ra
/*  f098904:	27bd0160 */ 	addiu	$sp,$sp,0x160
);
#elif VERSION >= VERSION_PAL_BETA
GLOBAL_ASM(
glabel bgun0f0981e8
.late_rodata
glabel var7f1ad398pf
.word 0x461c4000
glabel var7f1ad39cpf
.word 0x3f451eb8
glabel var7f1ad3a0pf
.word 0x3f333333
glabel var7f1ad3a4pf
.word 0x3f99999a
glabel var7f1ad3a8pf
.word 0x3f555555
glabel var7f1ad3acpf
.word 0x3f99999a
.text
/*  f098058:	27bdfea0 */ 	addiu	$sp,$sp,-352
/*  f09805c:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f098060:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f098064:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f098068:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f09806c:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f098070:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f098074:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f098078:	afa50164 */ 	sw	$a1,0x164($sp)
/*  f09807c:	908e0690 */ 	lbu	$t6,0x690($a0)
/*  f098080:	8c98068c */ 	lw	$t8,0x68c($a0)
/*  f098084:	24010002 */ 	li	$at,0x2
/*  f098088:	31cfffe3 */ 	andi	$t7,$t6,0xffe3
/*  f09808c:	00809025 */ 	move	$s2,$a0
/*  f098090:	1701000f */ 	bne	$t8,$at,.PB0f0980d0
/*  f098094:	a08f0690 */ 	sb	$t7,0x690($a0)
/*  f098098:	0fc25ff3 */ 	jal	bgun0f09815c
/*  f09809c:	00000000 */ 	nop
/*  f0980a0:	46000506 */ 	mov.s	$f20,$f0
/*  f0980a4:	0c00772a */ 	jal	modelGetNumAnimFrames
/*  f0980a8:	26440384 */ 	addiu	$a0,$s2,0x384
/*  f0980ac:	2459ffff */ 	addiu	$t9,$v0,-1
/*  f0980b0:	44992000 */ 	mtc1	$t9,$f4
/*  f0980b4:	00000000 */ 	nop
/*  f0980b8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0980bc:	4614303e */ 	c.le.s	$f6,$f20
/*  f0980c0:	00000000 */ 	nop
/*  f0980c4:	45020003 */ 	bc1fl	.PB0f0980d4
/*  f0980c8:	8e480680 */ 	lw	$t0,0x680($s2)
/*  f0980cc:	ae40068c */ 	sw	$zero,0x68c($s2)
.PB0f0980d0:
/*  f0980d0:	8e480680 */ 	lw	$t0,0x680($s2)
.PB0f0980d4:
/*  f0980d4:	8e49068c */ 	lw	$t1,0x68c($s2)
/*  f0980d8:	29020000 */ 	slti	$v0,$t0,0x0
/*  f0980dc:	392a0002 */ 	xori	$t2,$t1,0x2
/*  f0980e0:	2d4a0001 */ 	sltiu	$t2,$t2,0x1
/*  f0980e4:	38420001 */ 	xori	$v0,$v0,0x1
/*  f0980e8:	01425825 */ 	or	$t3,$t2,$v0
/*  f0980ec:	516001d2 */ 	beqzl	$t3,.PB0f098838
/*  f0980f0:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f0980f4:	44801000 */ 	mtc1	$zero,$f2
/*  f0980f8:	c64806d0 */ 	lwc1	$f8,0x6d0($s2)
/*  f0980fc:	26540384 */ 	addiu	$s4,$s2,0x384
/*  f098100:	4608103c */ 	c.lt.s	$f2,$f8
/*  f098104:	00000000 */ 	nop
/*  f098108:	45000006 */ 	bc1f	.PB0f098124
/*  f09810c:	00000000 */ 	nop
/*  f098110:	8e480680 */ 	lw	$t0,0x680($s2)
/*  f098114:	ae400684 */ 	sw	$zero,0x684($s2)
/*  f098118:	e6420688 */ 	swc1	$f2,0x688($s2)
/*  f09811c:	29020000 */ 	slti	$v0,$t0,0x0
/*  f098120:	38420001 */ 	xori	$v0,$v0,0x1
.PB0f098124:
/*  f098124:	5040005a */ 	beqzl	$v0,.PB0f098290
/*  f098128:	8e4d0690 */ 	lw	$t5,0x690($s2)
/*  f09812c:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
/*  f098130:	3c013f80 */ 	lui	$at,0x3f80
/*  f098134:	924d06d6 */ 	lbu	$t5,0x6d6($s2)
/*  f098138:	8c6c0004 */ 	lw	$t4,0x4($v1)
/*  f09813c:	44810000 */ 	mtc1	$at,$f0
/*  f098140:	3c017f1b */ 	lui	$at,0x7f1b
/*  f098144:	448c5000 */ 	mtc1	$t4,$f10
/*  f098148:	c432dde8 */ 	lwc1	$f18,-0x2218($at)
/*  f09814c:	31ae0001 */ 	andi	$t6,$t5,0x1
/*  f098150:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f098154:	3c0f800a */ 	lui	$t7,0x800a
/*  f098158:	11c0001a */ 	beqz	$t6,.PB0f0981c4
/*  f09815c:	46128503 */ 	div.s	$f20,$f16,$f18
/*  f098160:	8defe754 */ 	lw	$t7,-0x18ac($t7)
/*  f098164:	81f80de4 */ 	lb	$t8,0xde4($t7)
/*  f098168:	13000016 */ 	beqz	$t8,.PB0f0981c4
/*  f09816c:	00000000 */ 	nop
/*  f098170:	0c004be0 */ 	jal	random
/*  f098174:	00000000 */ 	nop
/*  f098178:	44822000 */ 	mtc1	$v0,$f4
/*  f09817c:	3c014f80 */ 	lui	$at,0x4f80
/*  f098180:	04410004 */ 	bgez	$v0,.PB0f098194
/*  f098184:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f098188:	44814000 */ 	mtc1	$at,$f8
/*  f09818c:	00000000 */ 	nop
/*  f098190:	46083180 */ 	add.s	$f6,$f6,$f8
.PB0f098194:
/*  f098194:	3c012f80 */ 	lui	$at,0x2f80
/*  f098198:	44815000 */ 	mtc1	$at,$f10
/*  f09819c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0981a0:	c432ddec */ 	lwc1	$f18,-0x2214($at)
/*  f0981a4:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0981a8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0981ac:	c428ddf0 */ 	lwc1	$f8,-0x2210($at)
/*  f0981b0:	44801000 */ 	mtc1	$zero,$f2
/*  f0981b4:	8e480680 */ 	lw	$t0,0x680($s2)
/*  f0981b8:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
/*  f0981bc:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0981c0:	46082000 */ 	add.s	$f0,$f4,$f8
.PB0f0981c4:
/*  f0981c4:	10600018 */ 	beqz	$v1,.PB0f098228
/*  f0981c8:	02802025 */ 	move	$a0,$s4
/*  f0981cc:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f0981d0:	00082c00 */ 	sll	$a1,$t0,0x10
/*  f0981d4:	0005cc03 */ 	sra	$t9,$a1,0x10
/*  f0981d8:	45000013 */ 	bc1f	.PB0f098228
/*  f0981dc:	00000000 */ 	nop
/*  f0981e0:	46140182 */ 	mul.s	$f6,$f0,$f20
/*  f0981e4:	44071000 */ 	mfc1	$a3,$f2
/*  f0981e8:	02802025 */ 	move	$a0,$s4
/*  f0981ec:	03202825 */ 	move	$a1,$t9
/*  f0981f0:	00003025 */ 	move	$a2,$zero
/*  f0981f4:	e7a20014 */ 	swc1	$f2,0x14($sp)
/*  f0981f8:	0c0079d7 */ 	jal	modelSetAnimation
/*  f0981fc:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f098200:	0c00772a */ 	jal	modelGetNumAnimFrames
/*  f098204:	02802025 */ 	move	$a0,$s4
/*  f098208:	44825000 */ 	mtc1	$v0,$f10
/*  f09820c:	02802025 */ 	move	$a0,$s4
/*  f098210:	468052a0 */ 	cvt.s.w	$f10,$f10
/*  f098214:	44055000 */ 	mfc1	$a1,$f10
/*  f098218:	0c007aaa */ 	jal	model0001e018
/*  f09821c:	00000000 */ 	nop
/*  f098220:	1000000b */ 	b	.PB0f098250
/*  f098224:	240affff */ 	li	$t2,-1
.PB0f098228:
/*  f098228:	46140402 */ 	mul.s	$f16,$f0,$f20
/*  f09822c:	00082c00 */ 	sll	$a1,$t0,0x10
/*  f098230:	00054c03 */ 	sra	$t1,$a1,0x10
/*  f098234:	44071000 */ 	mfc1	$a3,$f2
/*  f098238:	01202825 */ 	move	$a1,$t1
/*  f09823c:	00003025 */ 	move	$a2,$zero
/*  f098240:	e7a20014 */ 	swc1	$f2,0x14($sp)
/*  f098244:	0c0079d7 */ 	jal	modelSetAnimation
/*  f098248:	e7b00010 */ 	swc1	$f16,0x10($sp)
/*  f09824c:	240affff */ 	li	$t2,-1
.PB0f098250:
/*  f098250:	240b0002 */ 	li	$t3,0x2
/*  f098254:	ae4a0680 */ 	sw	$t2,0x680($s2)
/*  f098258:	ae4b068c */ 	sw	$t3,0x68c($s2)
/*  f09825c:	0c007746 */ 	jal	modelGetAbsAnimSpeed
/*  f098260:	02802025 */ 	move	$a0,$s4
/*  f098264:	8e4c0684 */ 	lw	$t4,0x684($s2)
/*  f098268:	3c017f1b */ 	lui	$at,0x7f1b
/*  f09826c:	c428ddf4 */ 	lwc1	$f8,-0x220c($at)
/*  f098270:	448c9000 */ 	mtc1	$t4,$f18
/*  f098274:	44801000 */ 	mtc1	$zero,$f2
/*  f098278:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f09827c:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f098280:	00000000 */ 	nop
/*  f098284:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f098288:	e64a0688 */ 	swc1	$f10,0x688($s2)
/*  f09828c:	8e4d0690 */ 	lw	$t5,0x690($s2)
.PB0f098290:
/*  f098290:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f098294:	05e10003 */ 	bgez	$t7,.PB0f0982a4
/*  f098298:	00000000 */ 	nop
/*  f09829c:	ae400684 */ 	sw	$zero,0x684($s2)
/*  f0982a0:	e6420688 */ 	swc1	$f2,0x688($s2)
.PB0f0982a4:
/*  f0982a4:	0fc25ff3 */ 	jal	bgun0f09815c
/*  f0982a8:	02402025 */ 	move	$a0,$s2
/*  f0982ac:	44809000 */ 	mtc1	$zero,$f18
/*  f0982b0:	c6500688 */ 	lwc1	$f16,0x688($s2)
/*  f0982b4:	46000506 */ 	mov.s	$f20,$f0
/*  f0982b8:	46120032 */ 	c.eq.s	$f0,$f18
/*  f0982bc:	46008380 */ 	add.s	$f14,$f16,$f0
/*  f0982c0:	4502000b */ 	bc1fl	.PB0f0982f0
/*  f0982c4:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
/*  f0982c8:	44802000 */ 	mtc1	$zero,$f4
/*  f0982cc:	3c013f80 */ 	lui	$at,0x3f80
/*  f0982d0:	460e203c */ 	c.lt.s	$f4,$f14
/*  f0982d4:	00000000 */ 	nop
/*  f0982d8:	45020005 */ 	bc1fl	.PB0f0982f0
/*  f0982dc:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
/*  f0982e0:	44814000 */ 	mtc1	$at,$f8
/*  f0982e4:	00000000 */ 	nop
/*  f0982e8:	46080501 */ 	sub.s	$f20,$f0,$f8
/*  f0982ec:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
.PB0f0982f0:
/*  f0982f0:	106000d8 */ 	beqz	$v1,.PB0f098654
/*  f0982f4:	00608825 */ 	move	$s1,$v1
/*  f0982f8:	106000d6 */ 	beqz	$v1,.PB0f098654
/*  f0982fc:	afa0014c */ 	sw	$zero,0x14c($sp)
/*  f098300:	00008025 */ 	move	$s0,$zero
/*  f098304:	24130001 */ 	li	$s3,0x1
/*  f098308:	92230000 */ 	lbu	$v1,0x0($s1)
.PB0f09830c:
/*  f09830c:	14600003 */ 	bnez	$v1,.PB0f09831c
/*  f098310:	00000000 */ 	nop
/*  f098314:	100000b6 */ 	b	.PB0f0985f0
/*  f098318:	afb3014c */ 	sw	$s3,0x14c($sp)
.PB0f09831c:
/*  f09831c:	12630003 */ 	beq	$s3,$v1,.PB0f09832c
/*  f098320:	24010002 */ 	li	$at,0x2
/*  f098324:	54610036 */ 	bnel	$v1,$at,.PB0f098400
/*  f098328:	24010003 */ 	li	$at,0x3
.PB0f09832c:
/*  f09832c:	96260002 */ 	lhu	$a2,0x2($s1)
/*  f098330:	3c014f80 */ 	lui	$at,0x4f80
/*  f098334:	2405ffff */ 	li	$a1,-1
/*  f098338:	44863000 */ 	mtc1	$a2,$f6
/*  f09833c:	27ab0094 */ 	addiu	$t3,$sp,0x94
/*  f098340:	04c10004 */ 	bgez	$a2,.PB0f098354
/*  f098344:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f098348:	44818000 */ 	mtc1	$at,$f16
/*  f09834c:	00000000 */ 	nop
/*  f098350:	46105280 */ 	add.s	$f10,$f10,$f16
.PB0f098354:
/*  f098354:	460e503e */ 	c.le.s	$f10,$f14
/*  f098358:	2401ffff */ 	li	$at,-1
/*  f09835c:	450200a5 */ 	bc1fl	.PB0f0985f4
/*  f098360:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f098364:	1a00000a */ 	blez	$s0,.PB0f098390
/*  f098368:	00001025 */ 	move	$v0,$zero
/*  f09836c:	8e240004 */ 	lw	$a0,0x4($s1)
/*  f098370:	27a3010c */ 	addiu	$v1,$sp,0x10c
.PB0f098374:
/*  f098374:	8c780000 */ 	lw	$t8,0x0($v1)
/*  f098378:	54980003 */ 	bnel	$a0,$t8,.PB0f098388
/*  f09837c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f098380:	00402825 */ 	move	$a1,$v0
/*  f098384:	24420001 */ 	addiu	$v0,$v0,0x1
.PB0f098388:
/*  f098388:	1450fffa */ 	bne	$v0,$s0,.PB0f098374
/*  f09838c:	24630004 */ 	addiu	$v1,$v1,0x4
.PB0f098390:
/*  f098390:	14a1000a */ 	bne	$a1,$at,.PB0f0983bc
/*  f098394:	2409ffff */ 	li	$t1,-1
/*  f098398:	8e240004 */ 	lw	$a0,0x4($s1)
/*  f09839c:	02002825 */ 	move	$a1,$s0
/*  f0983a0:	00051080 */ 	sll	$v0,$a1,0x2
/*  f0983a4:	03a2c821 */ 	addu	$t9,$sp,$v0
/*  f0983a8:	03a25021 */ 	addu	$t2,$sp,$v0
/*  f0983ac:	af24010c */ 	sw	$a0,0x10c($t9)
/*  f0983b0:	ad490094 */ 	sw	$t1,0x94($t2)
/*  f0983b4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0983b8:	96260002 */ 	lhu	$a2,0x2($s1)
.PB0f0983bc:
/*  f0983bc:	00051080 */ 	sll	$v0,$a1,0x2
/*  f0983c0:	004b1821 */ 	addu	$v1,$v0,$t3
/*  f0983c4:	8c6c0000 */ 	lw	$t4,0x0($v1)
/*  f0983c8:	0186082a */ 	slt	$at,$t4,$a2
/*  f0983cc:	50200089 */ 	beqzl	$at,.PB0f0985f4
/*  f0983d0:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f0983d4:	ac660000 */ 	sw	$a2,0x0($v1)
/*  f0983d8:	922d0000 */ 	lbu	$t5,0x0($s1)
/*  f0983dc:	03a27821 */ 	addu	$t7,$sp,$v0
/*  f0983e0:	03a27021 */ 	addu	$t6,$sp,$v0
/*  f0983e4:	166d0003 */ 	bne	$s3,$t5,.PB0f0983f4
/*  f0983e8:	00000000 */ 	nop
/*  f0983ec:	10000080 */ 	b	.PB0f0985f0
/*  f0983f0:	add300d0 */ 	sw	$s3,0xd0($t6)
.PB0f0983f4:
/*  f0983f4:	1000007e */ 	b	.PB0f0985f0
/*  f0983f8:	ade000d0 */ 	sw	$zero,0xd0($t7)
/*  f0983fc:	24010003 */ 	li	$at,0x3
.PB0f098400:
/*  f098400:	10610005 */ 	beq	$v1,$at,.PB0f098418
/*  f098404:	24010008 */ 	li	$at,0x8
/*  f098408:	50610049 */ 	beql	$v1,$at,.PB0f098530
/*  f09840c:	8e4e0690 */ 	lw	$t6,0x690($s2)
/*  f098410:	10000078 */ 	b	.PB0f0985f4
/*  f098414:	8fac014c */ 	lw	$t4,0x14c($sp)
.PB0f098418:
/*  f098418:	8e580690 */ 	lw	$t8,0x690($s2)
/*  f09841c:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f098420:	53200074 */ 	beqzl	$t9,.PB0f0985f4
/*  f098424:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f098428:	96290002 */ 	lhu	$t1,0x2($s1)
/*  f09842c:	3c014f80 */ 	lui	$at,0x4f80
/*  f098430:	44899000 */ 	mtc1	$t1,$f18
/*  f098434:	05210004 */ 	bgez	$t1,.PB0f098448
/*  f098438:	468090a0 */ 	cvt.s.w	$f2,$f18
/*  f09843c:	44812000 */ 	mtc1	$at,$f4
/*  f098440:	00000000 */ 	nop
/*  f098444:	46041080 */ 	add.s	$f2,$f2,$f4
.PB0f098448:
/*  f098448:	460e103e */ 	c.le.s	$f2,$f14
/*  f09844c:	00000000 */ 	nop
/*  f098450:	45020068 */ 	bc1fl	.PB0f0985f4
/*  f098454:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f098458:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f09845c:	00000000 */ 	nop
/*  f098460:	45020064 */ 	bc1fl	.PB0f0985f4
/*  f098464:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f098468:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f09846c:	00000000 */ 	nop
/*  f098470:	45020060 */ 	bc1fl	.PB0f0985f4
/*  f098474:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f098478:	0fc25ff3 */ 	jal	bgun0f09815c
/*  f09847c:	02402025 */ 	move	$a0,$s2
/*  f098480:	962a0002 */ 	lhu	$t2,0x2($s1)
/*  f098484:	3c014f80 */ 	lui	$at,0x4f80
/*  f098488:	02802025 */ 	move	$a0,$s4
/*  f09848c:	448a4000 */ 	mtc1	$t2,$f8
/*  f098490:	05410004 */ 	bgez	$t2,.PB0f0984a4
/*  f098494:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f098498:	44818000 */ 	mtc1	$at,$f16
/*  f09849c:	00000000 */ 	nop
/*  f0984a0:	46103180 */ 	add.s	$f6,$f6,$f16
.PB0f0984a4:
/*  f0984a4:	46003081 */ 	sub.s	$f2,$f6,$f0
/*  f0984a8:	3c014000 */ 	lui	$at,0x4000
/*  f0984ac:	44815000 */ 	mtc1	$at,$f10
/*  f0984b0:	c64c0688 */ 	lwc1	$f12,0x688($s2)
/*  f0984b4:	460a1083 */ 	div.s	$f2,$f2,$f10
/*  f0984b8:	460c103c */ 	c.lt.s	$f2,$f12
/*  f0984bc:	00000000 */ 	nop
/*  f0984c0:	45000018 */ 	bc1f	.PB0f098524
/*  f0984c4:	00000000 */ 	nop
/*  f0984c8:	0c007746 */ 	jal	modelGetAbsAnimSpeed
/*  f0984cc:	e7a20084 */ 	swc1	$f2,0x84($sp)
/*  f0984d0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0984d4:	c432ddf8 */ 	lwc1	$f18,-0x2208($at)
/*  f0984d8:	c7a20084 */ 	lwc1	$f2,0x84($sp)
/*  f0984dc:	02802025 */ 	move	$a0,$s4
/*  f0984e0:	46121102 */ 	mul.s	$f4,$f2,$f18
/*  f0984e4:	46002203 */ 	div.s	$f8,$f4,$f0
/*  f0984e8:	4600440d */ 	trunc.w.s	$f16,$f8
/*  f0984ec:	440c8000 */ 	mfc1	$t4,$f16
/*  f0984f0:	0c007746 */ 	jal	modelGetAbsAnimSpeed
/*  f0984f4:	ae4c0684 */ 	sw	$t4,0x684($s2)
/*  f0984f8:	8e4d0684 */ 	lw	$t5,0x684($s2)
/*  f0984fc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f098500:	c432ddfc */ 	lwc1	$f18,-0x2204($at)
/*  f098504:	448d3000 */ 	mtc1	$t5,$f6
/*  f098508:	00000000 */ 	nop
/*  f09850c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f098510:	46125102 */ 	mul.s	$f4,$f10,$f18
/*  f098514:	00000000 */ 	nop
/*  f098518:	46040202 */ 	mul.s	$f8,$f0,$f4
/*  f09851c:	e6480688 */ 	swc1	$f8,0x688($s2)
/*  f098520:	c64c0688 */ 	lwc1	$f12,0x688($s2)
.PB0f098524:
/*  f098524:	10000032 */ 	b	.PB0f0985f0
/*  f098528:	46146380 */ 	add.s	$f14,$f12,$f20
/*  f09852c:	8e4e0690 */ 	lw	$t6,0x690($s2)
.PB0f098530:
/*  f098530:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f098534:	0703002f */ 	bgezl	$t8,.PB0f0985f4
/*  f098538:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f09853c:	96260002 */ 	lhu	$a2,0x2($s1)
/*  f098540:	3c014f80 */ 	lui	$at,0x4f80
/*  f098544:	44868000 */ 	mtc1	$a2,$f16
/*  f098548:	04c10004 */ 	bgez	$a2,.PB0f09855c
/*  f09854c:	468080a0 */ 	cvt.s.w	$f2,$f16
/*  f098550:	44813000 */ 	mtc1	$at,$f6
/*  f098554:	00000000 */ 	nop
/*  f098558:	46061080 */ 	add.s	$f2,$f2,$f6
.PB0f09855c:
/*  f09855c:	460e103e */ 	c.le.s	$f2,$f14
/*  f098560:	00000000 */ 	nop
/*  f098564:	45020023 */ 	bc1fl	.PB0f0985f4
/*  f098568:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f09856c:	4602a03c */ 	c.lt.s	$f20,$f2
/*  f098570:	00000000 */ 	nop
/*  f098574:	4502001f */ 	bc1fl	.PB0f0985f4
/*  f098578:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f09857c:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f098580:	02802025 */ 	move	$a0,$s4
/*  f098584:	4502001b */ 	bc1fl	.PB0f0985f4
/*  f098588:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f09858c:	460e103e */ 	c.le.s	$f2,$f14
/*  f098590:	44809000 */ 	mtc1	$zero,$f18
/*  f098594:	46007006 */ 	mov.s	$f0,$f14
/*  f098598:	4502000c */ 	bc1fl	.PB0f0985cc
/*  f09859c:	ae400684 */ 	sw	$zero,0x684($s2)
/*  f0985a0:	8e390004 */ 	lw	$t9,0x4($s1)
/*  f0985a4:	03264823 */ 	subu	$t1,$t9,$a2
/*  f0985a8:	44895000 */ 	mtc1	$t1,$f10
/*  f0985ac:	00000000 */ 	nop
/*  f0985b0:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f0985b4:	460c0000 */ 	add.s	$f0,$f0,$f12
.PB0f0985b8:
/*  f0985b8:	4600103e */ 	c.le.s	$f2,$f0
/*  f0985bc:	00000000 */ 	nop
/*  f0985c0:	4503fffd */ 	bc1tl	.PB0f0985b8
/*  f0985c4:	460c0000 */ 	add.s	$f0,$f0,$f12
/*  f0985c8:	ae400684 */ 	sw	$zero,0x684($s2)
.PB0f0985cc:
/*  f0985cc:	e6520688 */ 	swc1	$f18,0x688($s2)
/*  f0985d0:	44050000 */ 	mfc1	$a1,$f0
/*  f0985d4:	46000506 */ 	mov.s	$f20,$f0
/*  f0985d8:	0c007aaa */ 	jal	model0001e018
/*  f0985dc:	e7a00080 */ 	swc1	$f0,0x80($sp)
/*  f0985e0:	924a0691 */ 	lbu	$t2,0x691($s2)
/*  f0985e4:	c7ae0080 */ 	lwc1	$f14,0x80($sp)
/*  f0985e8:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f0985ec:	a24b0691 */ 	sb	$t3,0x691($s2)
.PB0f0985f0:
/*  f0985f0:	8fac014c */ 	lw	$t4,0x14c($sp)
.PB0f0985f4:
/*  f0985f4:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f0985f8:	5180ff44 */ 	beqzl	$t4,.PB0f09830c
/*  f0985fc:	92230000 */ 	lbu	$v1,0x0($s1)
/*  f098600:	5a000015 */ 	blezl	$s0,.PB0f098658
/*  f098604:	3c054099 */ 	lui	$a1,0x4099
/*  f098608:	1a000012 */ 	blez	$s0,.PB0f098654
/*  f09860c:	00001025 */ 	move	$v0,$zero
/*  f098610:	27a3010c */ 	addiu	$v1,$sp,0x10c
/*  f098614:	27a800d0 */ 	addiu	$t0,$sp,0xd0
.PB0f098618:
/*  f098618:	84640002 */ 	lh	$a0,0x2($v1)
/*  f09861c:	8d050000 */ 	lw	$a1,0x0($t0)
/*  f098620:	afa80058 */ 	sw	$t0,0x58($sp)
/*  f098624:	afa3005c */ 	sw	$v1,0x5c($sp)
/*  f098628:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f09862c:	02403025 */ 	move	$a2,$s2
/*  f098630:	0fc25f39 */ 	jal	bgunSetPartVisible
/*  f098634:	8fa70164 */ 	lw	$a3,0x164($sp)
/*  f098638:	8fa2007c */ 	lw	$v0,0x7c($sp)
/*  f09863c:	8fa3005c */ 	lw	$v1,0x5c($sp)
/*  f098640:	8fa80058 */ 	lw	$t0,0x58($sp)
/*  f098644:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f098648:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f09864c:	1450fff2 */ 	bne	$v0,$s0,.PB0f098618
/*  f098650:	25080004 */ 	addiu	$t0,$t0,0x4
.PB0f098654:
/*  f098654:	3c054099 */ 	lui	$a1,0x4099
.PB0f098658:
/*  f098658:	34a5999a */ 	ori	$a1,$a1,0x999a
/*  f09865c:	02802025 */ 	move	$a0,$s4
/*  f098660:	0c007a8f */ 	jal	modelSetAnimPlaySpeed
/*  f098664:	24060000 */ 	li	$a2,0x0
/*  f098668:	02802025 */ 	move	$a0,$s4
/*  f09866c:	8e450684 */ 	lw	$a1,0x684($s2)
/*  f098670:	0c007e2a */ 	jal	model0001ee18
/*  f098674:	24060001 */ 	li	$a2,0x1
/*  f098678:	0fc25ff3 */ 	jal	bgun0f09815c
/*  f09867c:	02402025 */ 	move	$a0,$s2
/*  f098680:	8e4306b0 */ 	lw	$v1,0x6b0($s2)
/*  f098684:	46000386 */ 	mov.s	$f14,$f0
/*  f098688:	00004025 */ 	move	$t0,$zero
/*  f09868c:	10600069 */ 	beqz	$v1,.PB0f098834
/*  f098690:	00608025 */ 	move	$s0,$v1
/*  f098694:	3c013f80 */ 	lui	$at,0x3f80
/*  f098698:	44812000 */ 	mtc1	$at,$f4
/*  f09869c:	00008825 */ 	move	$s1,$zero
/*  f0986a0:	10600064 */ 	beqz	$v1,.PB0f098834
/*  f0986a4:	e7a40070 */ 	swc1	$f4,0x70($sp)
/*  f0986a8:	24140009 */ 	li	$s4,0x9
/*  f0986ac:	24130005 */ 	li	$s3,0x5
.PB0f0986b0:
/*  f0986b0:	92030000 */ 	lbu	$v1,0x0($s0)
/*  f0986b4:	54600004 */ 	bnezl	$v1,.PB0f0986c8
/*  f0986b8:	960d0002 */ 	lhu	$t5,0x2($s0)
/*  f0986bc:	1000005b */ 	b	.PB0f09882c
/*  f0986c0:	24080001 */ 	li	$t0,0x1
/*  f0986c4:	960d0002 */ 	lhu	$t5,0x2($s0)
.PB0f0986c8:
/*  f0986c8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0986cc:	448d4000 */ 	mtc1	$t5,$f8
/*  f0986d0:	05a10004 */ 	bgez	$t5,.PB0f0986e4
/*  f0986d4:	46804020 */ 	cvt.s.w	$f0,$f8
/*  f0986d8:	44818000 */ 	mtc1	$at,$f16
/*  f0986dc:	00000000 */ 	nop
/*  f0986e0:	46100000 */ 	add.s	$f0,$f0,$f16
.PB0f0986e4:
/*  f0986e4:	460e003e */ 	c.le.s	$f0,$f14
/*  f0986e8:	00000000 */ 	nop
/*  f0986ec:	4500004f */ 	bc1f	.PB0f09882c
/*  f0986f0:	00000000 */ 	nop
/*  f0986f4:	4600a03c */ 	c.lt.s	$f20,$f0
/*  f0986f8:	00000000 */ 	nop
/*  f0986fc:	4500004b */ 	bc1f	.PB0f09882c
/*  f098700:	00000000 */ 	nop
/*  f098704:	460ea03c */ 	c.lt.s	$f20,$f14
/*  f098708:	00000000 */ 	nop
/*  f09870c:	45000047 */ 	bc1f	.PB0f09882c
/*  f098710:	00000000 */ 	nop
/*  f098714:	10730007 */ 	beq	$v1,$s3,.PB0f098734
/*  f098718:	00000000 */ 	nop
/*  f09871c:	10740039 */ 	beq	$v1,$s4,.PB0f098804
/*  f098720:	2401000b */ 	li	$at,0xb
/*  f098724:	5061002f */ 	beql	$v1,$at,.PB0f0987e4
/*  f098728:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*  f09872c:	1000003f */ 	b	.PB0f09882c
/*  f098730:	00000000 */ 	nop
.PB0f098734:
/*  f098734:	12200016 */ 	beqz	$s1,.PB0f098790
/*  f098738:	00002025 */ 	move	$a0,$zero
/*  f09873c:	8e0e0004 */ 	lw	$t6,0x4($s0)
/*  f098740:	c7a60070 */ 	lwc1	$f6,0x70($sp)
/*  f098744:	240f0001 */ 	li	$t7,0x1
/*  f098748:	2418ffff */ 	li	$t8,-1
/*  f09874c:	24190001 */ 	li	$t9,0x1
/*  f098750:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f098754:	afb8001c */ 	sw	$t8,0x1c($sp)
/*  f098758:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f09875c:	e7ae0158 */ 	swc1	$f14,0x158($sp)
/*  f098760:	afa80078 */ 	sw	$t0,0x78($sp)
/*  f098764:	00002025 */ 	move	$a0,$zero
/*  f098768:	00002825 */ 	move	$a1,$zero
/*  f09876c:	24067fff */ 	li	$a2,0x7fff
/*  f098770:	24070040 */ 	li	$a3,0x40
/*  f098774:	00008825 */ 	move	$s1,$zero
/*  f098778:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f09877c:	0c0041d9 */ 	jal	snd00010718
/*  f098780:	e7a60014 */ 	swc1	$f6,0x14($sp)
/*  f098784:	8fa80078 */ 	lw	$t0,0x78($sp)
/*  f098788:	10000028 */ 	b	.PB0f09882c
/*  f09878c:	c7ae0158 */ 	lwc1	$f14,0x158($sp)
.PB0f098790:
/*  f098790:	8e090004 */ 	lw	$t1,0x4($s0)
/*  f098794:	3c013f80 */ 	lui	$at,0x3f80
/*  f098798:	44815000 */ 	mtc1	$at,$f10
/*  f09879c:	240a0001 */ 	li	$t2,0x1
/*  f0987a0:	240bffff */ 	li	$t3,-1
/*  f0987a4:	240c0001 */ 	li	$t4,0x1
/*  f0987a8:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f0987ac:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f0987b0:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0987b4:	e7ae0158 */ 	swc1	$f14,0x158($sp)
/*  f0987b8:	afa80078 */ 	sw	$t0,0x78($sp)
/*  f0987bc:	00002825 */ 	move	$a1,$zero
/*  f0987c0:	24067fff */ 	li	$a2,0x7fff
/*  f0987c4:	24070040 */ 	li	$a3,0x40
/*  f0987c8:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0987cc:	0c0041d9 */ 	jal	snd00010718
/*  f0987d0:	e7aa0014 */ 	swc1	$f10,0x14($sp)
/*  f0987d4:	8fa80078 */ 	lw	$t0,0x78($sp)
/*  f0987d8:	10000014 */ 	b	.PB0f09882c
/*  f0987dc:	c7ae0158 */ 	lwc1	$f14,0x158($sp)
/*  f0987e0:	8e0d0004 */ 	lw	$t5,0x4($s0)
.PB0f0987e4:
/*  f0987e4:	3c01447a */ 	lui	$at,0x447a
/*  f0987e8:	44814000 */ 	mtc1	$at,$f8
/*  f0987ec:	448d9000 */ 	mtc1	$t5,$f18
/*  f0987f0:	24110001 */ 	li	$s1,0x1
/*  f0987f4:	46809120 */ 	cvt.s.w	$f4,$f18
/*  f0987f8:	46082403 */ 	div.s	$f16,$f4,$f8
/*  f0987fc:	1000000b */ 	b	.PB0f09882c
/*  f098800:	e7b00070 */ 	swc1	$f16,0x70($sp)
.PB0f098804:
/*  f098804:	8e4e0690 */ 	lw	$t6,0x690($s2)
/*  f098808:	924b0690 */ 	lbu	$t3,0x690($s2)
/*  f09880c:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f098810:	000fc742 */ 	srl	$t8,$t7,0x1d
/*  f098814:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f098818:	00194880 */ 	sll	$t1,$t9,0x2
/*  f09881c:	312a001c */ 	andi	$t2,$t1,0x1c
/*  f098820:	316cffe3 */ 	andi	$t4,$t3,0xffe3
/*  f098824:	014c6825 */ 	or	$t5,$t2,$t4
/*  f098828:	a24d0690 */ 	sb	$t5,0x690($s2)
.PB0f09882c:
/*  f09882c:	1100ffa0 */ 	beqz	$t0,.PB0f0986b0
/*  f098830:	26100008 */ 	addiu	$s0,$s0,0x8
.PB0f098834:
/*  f098834:	8fbf004c */ 	lw	$ra,0x4c($sp)
.PB0f098838:
/*  f098838:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f09883c:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f098840:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f098844:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f098848:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f09884c:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f098850:	03e00008 */ 	jr	$ra
/*  f098854:	27bd0160 */ 	addiu	$sp,$sp,0x160
);
#else
void bgun0f0981e8(struct hand *hand, struct modelfiledata *modeldef)
{
	s32 s0;
	s32 index;
	struct guncmd *cmd;
	f32 animspeed;
	bool done;
	s32 s4;
	s32 partnums[15];
	bool partsvisible[15];
	s32 partframes[15];
	s32 s2;
	f32 animspeedmult;
	s32 tmp;
	s32 i;
	s32 sp78;

	hand->unk0cc8_04 = false;

	if (hand->animmode == HANDANIMMODE_BUSY && bgun0f09815c(hand) >= modelGetNumAnimFrames(&hand->gunmodel) - 1) {
		hand->animmode = HANDANIMMODE_IDLE;
	}

	// This condition looks like a bug (using | instead of ||), but it happens
	// to make no difference anyway. Brackets added for clarity.
	if ((hand->animmode == (u32)HANDANIMMODE_BUSY) | (hand->animload >= 0)) {
		if (hand->gangstarot > 0.0f) {
			hand->animframeinc = 0;
		}

		if (hand->animload >= 0) {
			animspeedmult = 1.0f;
			animspeed = hand->unk0ce8->unk04 / 10000.0f;

			if (hand->unk0d0e_07 && g_Vars.currentplayer->hands[HAND_LEFT].inuse) {
				animspeedmult = RANDOMFRAC() * 0.77f + 0.7f;
			}

			if (hand->unk0ce8 && animspeed < 0.0f) {
				modelSetAnimation(&hand->gunmodel, hand->animload, false, 0.0f, animspeedmult * animspeed, 0.0f);
				model0001e018(&hand->gunmodel, modelGetNumAnimFrames(&hand->gunmodel));
			} else {
				modelSetAnimation(&hand->gunmodel, hand->animload, false, 0.0f, animspeedmult * animspeed, 0.0f);
			}

			hand->animload = -1;
			hand->animmode = HANDANIMMODE_BUSY;
		}

		if (hand->unk0cc8_02) {
			hand->animframeinc = 0;
		}

		s4 = bgun0f09815c(hand);
		s2 = hand->animframeinc + s4;
		done = false;

		if (s4 == 0 && s2 > 0) {
			s4--;
		}

		if (hand->unk0ce8) {
			cmd = hand->unk0ce8;

			if (cmd) {
				s0 = 0;

				do {
					if (cmd->type == GUNCMD_END) {
						done = true;
					} else if (cmd->type == GUNCMD_SHOWPART || cmd->type == GUNCMD_HIDEPART) {
						if (s2 >= cmd->unk02) {
							index = -1;

							for (i = 0; i < s0; i++) {
								if (cmd->unk04 == partnums[i]) {
									index = i;
								}
							}

							if (index == -1) {
								index = s0;
								s0++;

								if (1);

								partnums[index] = cmd->unk04;
								partframes[index] = -1;
							}

							if (cmd->unk02 > partframes[index]) {
								partframes[index] = cmd->unk02;
								partsvisible[index] = cmd->type == GUNCMD_SHOWPART ? true : false;
							}
						}
					} else {
						switch (cmd->type) {
						case GUNCMD_WAITFORZRELEASED:
							if (hand->unk0cc8_01) {
								if (s2 >= cmd->unk02 && s4 < cmd->unk02 && s4 < s2) {
									tmp = cmd->unk02 - (s32)bgun0f09815c(hand);
									tmp /= 2;

									if (hand->animframeinc > tmp) {
										hand->animframeinc = tmp;
									}

									s2 = hand->animframeinc + s4;
								}
							}
							break;
						case GUNCMD_REPEATUNTILFULL:
							if (hand->unk0cc8_03 && s2 >= cmd->unk02 && s4 < cmd->unk02 && s4 < s2) {
								sp78 = cmd->unk04 + ((s2 - cmd->unk02) % ((cmd->unk02 - cmd->unk04) + 1));
								s4 = sp78;
								hand->animframeinc = 0;
								model0001e018(&hand->gunmodel, sp78);
								hand->animloopcount++;
								s2 = sp78;
							}
							break;
						}
					}

					cmd++;
				} while (!done);

				if (s0 > 0) {
					s32 i;

					for (i = 0; i < s0; i++) {
						bgunSetPartVisible(partnums[i], partsvisible[i], hand, modeldef);
					}
				}
			}
		}

		model0001f314(&hand->gunmodel, hand->animframeinc, true);

		s2 = bgun0f09815c(hand);

		if (hand->unk0ce8) {
			bool done = false;
			struct guncmd *cmd = hand->unk0ce8;
			f32 speed = 1.0f;
			bool hasspeed = false;
#if VERSION < VERSION_NTSC_1_0
			struct sndstate *audiohandle;
#endif

			if (cmd) {
				do {
					if (cmd->type == GUNCMD_END) {
						done = true;
					} else {
						tmp = cmd->unk02;

						if (s2 >= tmp && s4 < tmp && s4 < s2) {
							switch (cmd->type) {
							case GUNCMD_PLAYSOUND:
#if VERSION >= VERSION_NTSC_1_0
								if (hasspeed) {
									snd00010718(0, 0, 0x7fff, 0x40, cmd->unk04, speed, 1, -1, 1);
									hasspeed = false;
								} else {
									snd00010718(0, 0, 0x7fff, 0x40, cmd->unk04, 1.0f, 1, -1, 1);
								}
#else
								audiohandle = sndStart(var80095200, cmd->unk04, NULL, -1, -1, -1, -1, -1);

								if (hasspeed && audiohandle) {
									hasspeed = false;
									audioPostEvent(audiohandle, 16, *(s32 *)&speed);
								}
#endif
								break;
							case GUNCMD_SETSOUNDSPEED:
								speed = cmd->unk04 / 1000.0f;
								hasspeed = true;
								break;
							case GUNCMD_POPOUTSACKOFPILLS:
								hand->unk0cc8_04++;
								break;
							}
						}
					}

					cmd++;
				} while (!done);
			}
		}
	}
}
#endif

bool bgun0f098884(struct guncmd *cmd, struct gset *gset)
{
	s32 result = false;

	if (cmd->unk01 == 0) {
		return true;
	}

	if (cmd->unk01 == 1 && g_Vars.currentplayer->hands[HAND_LEFT].inuse == true) {
		result = true;
	}

	if (cmd->unk01 == 2 && gset->weaponfunc == FUNC_SECONDARY) {
		result = true;
	}

	return result;
}

void bgunStartAnimation(struct guncmd *cmd, s32 handnum, struct hand *hand)
{
	if (cmd->type != GUNCMD_PLAYANIMATION) {
		struct guncmd *loopcmd = cmd;
		s32 done = false;
		u32 rand = random() % 100;

		while (loopcmd->type != GUNCMD_END) {
			if (bgun0f098884(loopcmd, &hand->gset) && !done) {
				if (loopcmd->type == GUNCMD_INCLUDE) {
					done = true;
					bgunStartAnimation((struct guncmd *)loopcmd->unk04, handnum, hand);
				} else if (loopcmd->type == GUNCMD_RANDOM) {
					if ((struct guncmd *)loopcmd->unk04 != hand->unk0d80 && loopcmd->unk02 > rand) {
						done = true;
						bgunStartAnimation((struct guncmd *)loopcmd->unk04, handnum, hand);
					}
				}
			}

			loopcmd++;
		}
	} else {
		hand->animload = cmd->unk02;
		hand->animmode = HANDANIMMODE_IDLE;
		hand->unk0cc8_01 = 0;
		hand->unk0cc8_03 = false;
		hand->unk0ce8 = cmd;
		hand->animloopcount = 0;
		hand->unk0cc8_02 = 0;
		hand->unk0d0e_07 = false;
		hand->unk0d80 = cmd;
	}
}

bool bgun0f098a44(struct hand *hand, s32 time)
{
	struct guncmd *cmd = hand->unk0ce8;
	s32 waittimekeyframe = -1;
	s32 zreleasekeyframe = -1;

	if (hand->animmode == HANDANIMMODE_IDLE) {
		return (hand->animload == -1);
	}

	while (cmd->type != GUNCMD_END && waittimekeyframe == -1) {
		if (cmd->type == GUNCMD_WAITFORZRELEASED) {
			zreleasekeyframe = cmd->unk02;
		}

		if (cmd->type == GUNCMD_WAITTIME && time == cmd->unk04) {
			waittimekeyframe = cmd->unk02;
		}

		cmd++;
	}

	if (waittimekeyframe >= 0) {
#if VERSION >= VERSION_PAL_BETA
		if (hand->unk0cc8_01 && bgun0f09815c(hand) <= zreleasekeyframe) {
			return false;
		}

		return (bgun0f09815c(hand) + hand->animframeincfreal >= waittimekeyframe);
#else
		if (hand->unk0cc8_01 && (s32)bgun0f09815c(hand) <= zreleasekeyframe) {
			return false;
		}

		return (bgun0f09815c(hand) + hand->animframeinc >= waittimekeyframe);
#endif
	}

	return true;
}

s32 bgun0f098b80(struct hand *hand, s32 arg1)
{
	struct guncmd *cmd = hand->unk0ce8;
	s32 keyframe = -1;

	if (hand->animmode == HANDANIMMODE_IDLE) {
		return 0;
	}

	while (cmd->type != GUNCMD_END && keyframe == -1) {
		if (cmd->type == GUNCMD_WAITTIME) {
			if (cmd->unk04 == arg1) {
				keyframe = cmd->unk02;
			}
		}

		cmd++;
	}

	if (keyframe == -1) {
		keyframe = 0;
	}

	return keyframe;
}

bool bgunIsAnimBusy(struct hand *hand)
{
	return hand->animmode != HANDANIMMODE_IDLE;
}

void bgunResetAnim(struct hand *hand)
{
	hand->animload = -1;
	hand->animmode = HANDANIMMODE_IDLE;
	hand->unk0cc8_01 = false;
	hand->unk0cc8_03 = false;
	hand->unk0ce8 = NULL;
	hand->animloopcount = 0;
	hand->unk0cc8_02 = false;
	hand->unk0d0e_07 = false;
}

void bgunGetWeaponInfo(struct handweaponinfo *info, s32 handnum)
{
	s32 weaponnum = bgunGetWeaponNum2(handnum);

	info->weaponnum = weaponnum;
	info->definition = g_Weapons[weaponnum];
	info->gunctrl = &g_Vars.currentplayer->gunctrl;
}

/**
 * Return values:
 * -1 = gun function doesn't exist or ammo fully depleted
 * 0 = trigger reload
 * 1 = has ammo in clip and ammo in reserve
 * 2 = has ammo in clip but none in reserve
 * 3 = gun doesn't use ammo or clip is full
 */
s32 bgun0f098ca0(s32 funcnum, struct handweaponinfo *info, struct hand *hand)
{
	s32 result = 3;
	struct weaponfunc *func = weaponGetFunction(&hand->gset, funcnum);

	if (!func) {
		return -1;
	}

	if (func->ammoindex != -1) {
		s32 ammoindex = func->ammoindex;

		if (info->gunctrl->ammotypes[ammoindex] >= 0
				&& hand->loadedammo[ammoindex] < hand->clipsizes[ammoindex]) {
			s32 minqty = 1;

			if (info->weaponnum == WEAPON_SHOTGUN && funcnum == FUNC_SECONDARY) {
				minqty = 2;
			}

			if (info->weaponnum == WEAPON_TRANQUILIZER && funcnum == FUNC_SECONDARY) {
				minqty = bgunGetMinClipQty(WEAPON_TRANQUILIZER, FUNC_SECONDARY);
			}

			result = 1;

			if (hand->loadedammo[ammoindex] < minqty) {
				result = 0;

				if (g_Vars.currentplayer->ammoheldarr[info->gunctrl->ammotypes[ammoindex]] == 0) {
					result = -1;
				}
			} else {
				if (g_Vars.currentplayer->ammoheldarr[info->gunctrl->ammotypes[ammoindex]] == 0) {
					result = 2;
				}
			}
		}
	}

	return result;
}

void bgun0f098df8(s32 weaponfunc, struct handweaponinfo *info, struct hand *hand, u8 onebullet, u8 checkunequipped)
{
	struct weaponfunc *func = weaponGetFunction(&hand->gset, weaponfunc);

	if (func && func->ammoindex != -1) {
		s32 ammoindex = func->ammoindex;

		if (info->gunctrl->ammotypes[ammoindex] >= 0) {
			s32 amount = hand->clipsizes[ammoindex] - hand->loadedammo[ammoindex];

			s32 reloadindex = bgunGetUnequippedReloadIndex(info->weaponnum);

			if (g_FrIsValidWeapon) {
				reloadindex = -1;
			}

			if (checkunequipped && reloadindex >= 0) {
#if VERSION >= VERSION_PAL_BETA
				amount -= hand->gunroundsspent[reloadindex] / TICKS(256);
#else
				amount -= hand->gunroundsspent[reloadindex] >> 8;
#endif
			}

			if (onebullet) {
				amount = 1;
			}

			if (amount > g_Vars.currentplayer->ammoheldarr[info->gunctrl->ammotypes[ammoindex]]) {
				amount = g_Vars.currentplayer->ammoheldarr[info->gunctrl->ammotypes[ammoindex]];
			}

#if VERSION >= VERSION_JPN_FINAL
			// In most versions of the game, reloading the shotgun while going
			// through a teleport in Deep Sea will cause the shotgun to load
			// more ammo than its capacity. JPN Final fixes this here.
			if (amount > hand->clipsizes[ammoindex] - hand->loadedammo[ammoindex]) {
				amount = hand->clipsizes[ammoindex] - hand->loadedammo[ammoindex];
			}
#endif

			hand->loadedammo[ammoindex] += amount;
			g_Vars.currentplayer->ammoheldarr[info->gunctrl->ammotypes[ammoindex]] -= amount;

			if (info->definition->ammos[ammoindex]->flags & AMMOFLAG_NORESERVE) {
				g_Vars.currentplayer->ammoheldarr[info->gunctrl->ammotypes[ammoindex]] = 0;
			}

			if (func);
		}
	}
}

void bgun0f098f8c(struct handweaponinfo *info, struct hand *hand)
{
	s32 i;

	for (i = 0; i < 2; i++) {
		if (weaponGetFunction(&hand->gset, i)) {
			bgun0f098df8(i, info, hand, 0, 1);
		}
	}
}

bool bgun0f099008(s32 handnum)
{
	struct handweaponinfo info;

	bgunGetWeaponInfo(&info, handnum);

	if (bgun0f098ca0(0, &info, &g_Vars.currentplayer->hands[handnum]) > 0) {
		return true;
	}

	if (bgun0f098ca0(1, &info, &g_Vars.currentplayer->hands[handnum]) > 0) {
		return true;
	}

	return false;
}

bool bgun0f0990b0(struct weaponfunc *basefunc, struct weapon *weapon)
{
	if (!basefunc) {
		return true;
	}

	if (basefunc->type == INVENTORYFUNCTYPE_NONE) {
		return true;
	}

	if ((basefunc->type & 0xff) == INVENTORYFUNCTYPE_CLOSE) {
		return true;
	}

	if ((basefunc->type & 0xff) == INVENTORYFUNCTYPE_SPECIAL) {
		struct weaponfunc_special *func = (struct weaponfunc_special *)basefunc;

		if (func->specialfunc != HANDATTACKTYPE_DETONATE
				&& func->specialfunc != HANDATTACKTYPE_BOOST
				&& func->specialfunc != HANDATTACKTYPE_REVERTBOOST) {
			return true;
		}
	}

	if ((basefunc->type & 0xff) == INVENTORYFUNCTYPE_THROW) {
		if (basefunc->ammoindex <= -1) {
			return true;
		}
	}

	if (basefunc->ammoindex >= 0
			&& weapon->ammos[basefunc->ammoindex]
			&& bgunGetAmmoCount(weapon->ammos[basefunc->ammoindex]->type) <= 0) {
		return true;
	}

	return false;
}

bool bgun0f099188(struct hand *hand, s32 gunfunc)
{
	struct weaponfunc *func = weaponGetFunction(&hand->gset, gunfunc);
	struct weapon *weapon = weaponFindById(hand->gset.weaponnum);

	if (bgunIsUsingSecondaryFunction() == gunfunc) {
		return false;
	}

	return bgun0f0990b0(func, weapon);
}

s32 bgunTickIncIdle(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	bool usesec;
	s32 gunfunc = bgunIsUsingSecondaryFunction();
	s32 sp34;
	s32 sp30;
	bool changefunc;
	s32 next;
	struct hand *lhand;
	struct weaponfunc *func;

	hand->lastdirvalid = false;
	hand->burstbullets = 0;
#if VERSION < VERSION_PAL_BETA
	hand->animframeincfreal = hand->animframeinc;
#endif
	hand->shotremainder = 0;

	// If ready to change gun due to manual switch, just do that
	if (bgunIsReadyToSwitch(handnum) && bgunSetState(handnum, HANDSTATE_CHANGEGUN)) {
		return lvupdate;
	}

	if (gunfunc == hand->gset.weaponfunc) {
		hand->unk0cc8_07 = false;
	}

	hand->unk0cc8_08 = false;

	if (hand->inuse) {
		sp34 = bgun0f098ca0(hand->gset.weaponfunc, info, hand);

		// Handle changing gun function
		if (gunfunc != hand->gset.weaponfunc && hand->modenext != HANDMODE_RELOAD) {
			changefunc = true;

			if (hand->unk0cc8_07 && bgun0f098ca0(1 - hand->gset.weaponfunc, info, hand) < 0) {
				changefunc = false;
			}

			if (changefunc && info->weaponnum == WEAPON_COMBATKNIFE) {
				if (sp34 == 0) {
					hand->count60 = 0;
					hand->count = 0;
					hand->gset.weaponfunc = gunfunc;

					if (bgunSetState(handnum, HANDSTATE_RELOAD)) {
						return lvupdate;
					}
				} else {
					if (sp34 < 0) {
						changefunc = false;
					}
				}
			}

			if (changefunc) {
				hand->unk0cc8_07 = false;

				if (bgunSetState(handnum, HANDSTATE_CHANGEFUNC)) {
					return lvupdate;
				}
			}
		}

		if (sp34 < 0) {
			// Attempted to shoot with no ammo

			// Consider switching to another weapon
			if (weaponHasFlag(info->weaponnum, WEAPONFLAG_00000001)
					&& (info->weaponnum != WEAPON_REMOTEMINE || handnum != HAND_LEFT)
					&& bgunSetState(handnum, HANDSTATE_AUTOSWITCH)) {
				return lvupdate;
			}

			// Consider switching to other gun function
			usesec = g_Vars.currentplayer->gunctrl.weaponnum >= WEAPON_UNARMED
				&& g_Vars.currentplayer->gunctrl.weaponnum <= WEAPON_COMBATBOOST
				&& (g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].gunfuncs[(g_Vars.currentplayer->gunctrl.weaponnum - 1) >> 3] & (1 << (g_Vars.currentplayer->gunctrl.weaponnum - 1 & 7)));

			if (usesec == gunfunc) {
				sp30 = bgun0f098ca0(1 - hand->gset.weaponfunc, info, hand);

				if (bgun0f099188(hand, 1 - hand->gset.weaponfunc)
						&& info->weaponnum != WEAPON_REAPER) {
					if (info->gunctrl->wantammo) {
						func = weaponGetFunction(&hand->gset, 1 - hand->gset.weaponfunc);

						if ((func->type & 0xff) != INVENTORYFUNCTYPE_CLOSE) {
							sp30 = -1;
						}
					} else {
						sp30 = -1;
					}
				}

				if (sp30 < 0) {
					hand->unk0cc8_08 = true;
				} else {
					if (!weaponHasFlag(info->weaponnum, WEAPONFLAG_04000000)
							|| hand->gset.weaponfunc == FUNC_SECONDARY) {
						hand->unk0cc8_07 = true;

						if (bgunSetState(handnum, HANDSTATE_CHANGEFUNC)) {
							return lvupdate;
						}
					}
				}
			}
		} else if (sp34 == 0) {
			// Clip is empty
			if (hand->triggeron && info->weaponnum != WEAPON_NONE) {
				hand->unk0cc8_01 = false;

				if (bgunSetState(handnum, HANDSTATE_ATTACKEMPTY)) {
					return lvupdate;
				}
			} else {
				hand->count60 = 0;
				hand->count = 0;

				if (bgunSetState(handnum, HANDSTATE_RELOAD)) {
					return lvupdate;
				}
			}
		} else {
			// Clip has ammo
			if (hand->triggeron || (hand->activatesecondary && hand->gset.weaponfunc == FUNC_SECONDARY)) {
				if (info->weaponnum != WEAPON_NONE) {
					g_Vars.currentplayer->doautoselect = false;

					hand->mode = HANDMODE_1;
					hand->count = 0;
					hand->count60 = 0;
					hand->triggerreleased = false;
					hand->activatesecondary = false;

					if (bgunSetState(handnum, HANDSTATE_ATTACK)) {
						return lvupdate;
					}
				}
			}

			// Not attacking, but the player may have attempted
			// to change guns or reload while firing
			if (hand->modenext != HANDMODE_NONE) {
				next = hand->modenext;

				hand->mode = hand->modenext;
				hand->count60 = 0;
				hand->count = 0;
				hand->modenext = HANDMODE_NONE;

				if (next == HANDMODE_RELOAD && sp34 < 2 && sp34 >= 0) {
					if (bgunSetState(handnum, HANDSTATE_RELOAD)) {
						if (handnum && handnum && handnum);
						return lvupdate;
					}
				}
			}
		}
	}

	if (handnum == HAND_RIGHT) {
		if (info->gunctrl->wantammo) {
			bgunAutoSwitchWeapon();
		} else {
			lhand = &g_Vars.currentplayer->hands[1] - handnum;

			if ((hand->unk0cc8_08 || !hand->inuse)
					&& (lhand->unk0cc8_08 || !lhand->inuse)
					&& (hand->triggeron || lhand->triggeron)) {
				bgunAutoSwitchWeapon();
			}

			hand->unk0cc8_08 = lhand->unk0cc8_08 = false;
		}
	}

	return 0;
}

void bgun0f099780(struct hand *hand, f32 angle)
{
	hand->useposrot = true;

	mtx4LoadXRotation(angle, &hand->posrotmtx);

	hand->posrotmtx.m[3][0] = 0;
	hand->posrotmtx.m[3][1] = (1.0f - cosf(angle)) * -80.0f;
	hand->posrotmtx.m[3][2] = sinf(angle) * 15.0f;
}

s32 bgunTickIncAutoSwitch(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	u32 stack;
	s32 someval;
	s32 gunfunc = bgunIsUsingSecondaryFunction();

	if (!hand->inuse && bgunSetState(handnum, HANDSTATE_IDLE)) {
		return lvupdate;
	}

	if (hand->stateminor == 0) {
		s32 delay = TICKS(16);

		if (g_Vars.normmplayerisrunning) {
			delay = TICKS(12);
		}

		if (hand->stateframes >= delay) {
			hand->stateminor++;
		} else {
			bgun0f099780(hand, hand->stateframes * 0.87252569198608f / delay);
		}
	}

	if (hand->stateminor == 1) {
		hand->lastdirvalid = false;
#if VERSION < VERSION_PAL_BETA
		hand->animframeincfreal = hand->animframeinc;
#endif
		hand->shotremainder = 0;

		if (bgunIsReadyToSwitch(handnum) && bgunSetState(handnum, HANDSTATE_CHANGEGUN)) {
			if (g_Vars.mplayerisrunning && (IS8MB() || PLAYERCOUNT() != 1)) {
				playermgrDeleteWeapon(handnum);
			}

			bgunFreeHeldRocket(handnum);

			hand->mode = HANDMODE_6;
			hand->stateminor = 2;
			hand->count = 0;
			return 0;
		}

		if (hand->inuse) {
			someval = bgun0f098ca0(gunfunc, info, hand);

			if (info->weaponnum == WEAPON_TIMEDMINE || info->weaponnum == WEAPON_PROXIMITYMINE) {
				hand->gset.weaponfunc = gunfunc;
			}

			if (info->weaponnum == WEAPON_REMOTEMINE
					&& gunfunc != hand->gset.weaponfunc
					&& bgunSetState(handnum, HANDSTATE_CHANGEFUNC)) {
				return lvupdate;
			}

			if (g_Vars.currentplayer->doautoselect) {
				struct hand *otherhand = &g_Vars.currentplayer->hands[1 - handnum];
				struct handweaponinfo otherinfo;
				bool ready = true;

				bgunGetWeaponInfo(&otherinfo, 1 - handnum);

				if (otherhand->inuse) {
					if (bgun0f098ca0(0, &otherinfo, otherhand) >= 0) {
						ready = false;
					}

					if (bgun0f098ca0(1, &otherinfo, otherhand) >= 0) {
						ready = false;
					}

					if (bgun0f099188(otherhand, otherhand->gset.weaponfunc)) {
						ready = true;
					}
				}

				if (otherhand->state != HANDSTATE_IDLE && otherhand->state != HANDSTATE_AUTOSWITCH) {
					ready = false;
				}

				if (ready) {
					bgunAutoSwitchWeapon();
				}
			}

			if (someval <= 1 && someval >= 0) {
				if (g_Vars.currentplayer->hands[1 - handnum].state != HANDSTATE_RELOAD) {
					hand->count60 = 0;
					hand->count = 0;

					if (bgunSetState(handnum, HANDSTATE_RELOAD)) {
						if (info->weaponnum == WEAPON_COMBATKNIFE) {
							hand->mode = HANDMODE_11;
							hand->pausetime60 = TICKS(17);
							hand->count60 = 0;
							hand->count = -1;
							hand->stateminor = 2;
						}

						return lvupdate;
					}
				}
			}

			if (hand->modenext) {
				hand->mode = hand->modenext;
				hand->count60 = 0;
				hand->count = 0;
				hand->modenext = HANDMODE_NONE;
			}
		}

		bgun0f099780(hand, 0.87252569198608f);
	}

	return 0;
}

bool bgunIsReloading(struct hand *hand)
{
	if (hand->state == HANDSTATE_RELOAD) {
		return true;
	}

	return false;
}

s32 bgunTickIncReload(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	u32 stack;
	struct weaponfunc *func = gsetGetWeaponFunction(&hand->gset);

	if (g_Vars.currentplayer->isdead) {
		hand->animmode = HANDANIMMODE_IDLE;
		hand->animload = -1;

		if (bgunSetState(handnum, HANDSTATE_IDLE)) {
			return lvupdate;
		}
	}

	if (hand->statecycles == 0) {
		struct hand *hand2 = &g_Vars.currentplayer->hands[1 - handnum];

		hand->gs_int1 = -1;
		hand->gs_int2 = 0;

		if (hand2->state == HANDSTATE_RELOAD && hand2->stateframes < TICKS(20)) {
			hand->stateminor = 9;
		}
	}

	if (hand->stateminor == 9) {
		struct hand *hand2 = &g_Vars.currentplayer->hands[1 - handnum];

		if (hand2->state == HANDSTATE_RELOAD && hand2->stateframes < TICKS(20)) {
			return 0;
		}

		hand->stateframes = 0;
		hand->statecycles = 0;
		hand->stateminor = 0;
		hand->statelastframe = 0;
	}

	if (hand->stateminor == 0) {
		if (hand->statecycles == 0) {
			if (func && (func->ammoindex == 0 || func->ammoindex == 1)) {
				if (info->definition->ammos[func->ammoindex]->reload_animation
						&& info->weaponnum != WEAPON_COMBATKNIFE) {
					bgunStartAnimation(info->definition->ammos[func->ammoindex]->reload_animation, handnum, hand);

					hand->unk0d0e_07 = true;

					if (info->definition->ammos[func->ammoindex]->flags & AMMOFLAG_INCREMENTALRELOAD) {
						hand->unk0cc8_03 = true;
					}

					if (info->weaponnum == WEAPON_GRENADE || info->weaponnum == WEAPON_NBOMB) {
						hand->unk0d0e_00 = 0;
					}
				} else {
					hand->stateminor++;
				}
			} else {
				if (bgunSetState(handnum, HANDSTATE_IDLE)) {
					return lvupdate;
				}
			}
		} else {
			if (info->definition->ammos[func->ammoindex]->flags & AMMOFLAG_INCREMENTALRELOAD) {
				if (bgun0f098a44(hand, 1)) {
					if ((hand->stateflags & HANDSTATEFLAG_00000010) == 0) {
						s32 value;

						bgun0f098df8(hand->gset.weaponfunc, info, hand, 1, 0);
						hand->stateflags |= HANDSTATEFLAG_00000010;
						value = bgun0f098ca0(hand->gset.weaponfunc, info, hand);

						if (value >= 2) {
							hand->unk0cc8_03 = false;
						}

						if (value == -1) {
							hand->unk0cc8_03 = false;
						}
					}
				} else {
					hand->stateflags = 0;
				}

				if (hand->triggeron) {
					hand->unk0cc8_03 = false;
				}

#if VERSION >= VERSION_JPN_FINAL
				if (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY) {
					hand->unk0cc8_03 = false;
				}
#endif
			} else {
				if ((hand->stateflags & HANDSTATEFLAG_00000010) == 0) {
					if (bgun0f098a44(hand, 1)) {
						bgun0f098df8(hand->gset.weaponfunc, info, hand, 0, 0);
						hand->stateflags |= HANDSTATEFLAG_00000010;
					}
				}
			}

			if (hand->animmode != HANDANIMMODE_BUSY) {
				if (bgunSetState(handnum, HANDSTATE_IDLE)) {
					return lvupdate;
				}
			}

			if (1);
		}
	}

	if (hand->stateminor == 1) {
		if (hand->count60 > TICKS(15) || !hand->visible) {
			hand->mode = HANDMODE_11;
			hand->stateminor++;
			hand->pausetime60 = TICKS(17);
			hand->count60 = 0;
			hand->count = 0;
		} else {
			bgun0f099780(hand, (hand->count60 * 0.87252569198608f) / TICKS(16));
		}
	}

	if (hand->stateminor == 2) {
		if (hand->count == 0) {
			if (info->weaponnum == WEAPON_COMBATKNIFE
					&& func->ammoindex >= 0
					&& info->definition->ammos[func->ammoindex]->reload_animation) {
				bgunStartAnimation(info->definition->ammos[func->ammoindex]->reload_animation, handnum, hand);
				hand->unk0cc8_02 = true;
			}

			if ((hand->stateflags & HANDSTATEFLAG_00000010) == 0) {
				bgun0f098df8(hand->gset.weaponfunc, info, hand, 0, 0);
			}

			if (g_Vars.lvupdate240 > 0
					&& g_Vars.currentplayer->cameramode != CAMERAMODE_THIRDPERSON
					&& bgun0f09dd7c()
					&& !g_PlayerInvincible
					&& !g_Vars.currentplayer->isdead) {
				switch (info->weaponnum) {
				case WEAPON_NONE:
				case WEAPON_UNARMED:
				case WEAPON_COMBATKNIFE:
				case WEAPON_LASER:
				case WEAPON_GRENADE:
				case WEAPON_TIMEDMINE:
				case WEAPON_PROXIMITYMINE:
				case WEAPON_REMOTEMINE:
				case WEAPON_ECMMINE:
				case WEAPON_COMMSRIDER:
				case WEAPON_TRACERBUG:
				case WEAPON_TARGETAMPLIFIER:
				case WEAPON_BRIEFCASE2:
					// No reload sound
					break;
				default:
					sndStart(var80095200, SFX_RELOAD_DEFAULT, 0, -1, -1, -1, -1, -1);
					break;
				}
			}
		}

		if (hand->count60 >= hand->pausetime60 && hand->count >= 2) {
			hand->mode = HANDMODE_12;
			hand->stateminor++;
			hand->count60 = 0;
			hand->count = 0;
		} else {
			bgun0f099780(hand, 0.87252569198608f);
		}
	}

	if (hand->stateminor == 3) {
		if (info->weaponnum == WEAPON_COMBATKNIFE) {
			hand->animmode = HANDANIMMODE_IDLE;
		}

		if (hand->count == 0) {
			g_Vars.currentplayer->doautoselect = false;
		}

		if (hand->count60 >= TICKS(23)
				|| !weaponGetModelNum2(info->weaponnum)
				|| !weaponHasFlag(info->weaponnum, WEAPONFLAG_00000040)
				|| weaponHasFlag(info->weaponnum, WEAPONFLAG_00000080)) {
			hand->mode = HANDMODE_NONE;
			hand->count60 = 0;
			hand->count = 0;

			if (bgunSetState(handnum, HANDSTATE_IDLE)) {
				return lvupdate;
			}
		} else {
			bgun0f099780(hand, (TICKS(23) - hand->count60) * 0.87252569198608f / TICKS(23));
		}
	}

	return 0;
}

s32 bgunTickIncChangeFunc(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	struct guncmd *cmd;
	bool more = false;

	if (hand->statecycles == 0) {
		if (hand->gset.weaponfunc == FUNC_PRIMARY) {
			cmd = gsetGetPriToSecAnim(&hand->gset);
			hand->gset.weaponfunc = FUNC_SECONDARY;
		} else {
			cmd = gsetGetSecToPriAnim(&hand->gset);
			hand->gset.weaponfunc = FUNC_PRIMARY;
		}

		more = false;

		if (cmd != NULL) {
			bgunStartAnimation(cmd, handnum, hand);
			more = true;
			g_Vars.currentplayer->hands[HAND_RIGHT].unk0dd4 = -1;
		}
	} else {
		if (hand->animmode == HANDANIMMODE_BUSY) {
			more = true;
		}
	}

	if (!more && bgunSetState(handnum, HANDSTATE_IDLE)) {
		return lvupdate;
	}

	return 0;
}

s32 bgun0f09a3f8(struct hand *hand, struct weaponfunc *func)
{
	bool burst = false;
	bool smallburst = false;
	struct gunctrl *ctrl = &g_Vars.currentplayer->gunctrl;

	if ((func->flags & FUNCFLAG_BURST3) && hand->burstbullets < 3) {
		// Make automatics do single shot when holding aim
		if (!g_Vars.currentplayer->insightaimmode || (func->type & 0xff00) != 0x100) {
			// Not aiming and not an automatic weapon
			smallburst = true;
		}
	}

	if ((func->flags & FUNCFLAG_BURST2) && hand->burstbullets < 2) {
		smallburst = true;
	}

	if ((func->flags & FUNCFLAG_BURST5) && hand->burstbullets < 5) {
		smallburst = true;
	}

	if ((func->flags & FUNCFLAG_BURST50) && hand->burstbullets < 50) {
		burst = true;
	}

	if (smallburst) {
		burst = true;
	}

	if (hand->triggeron || (hand->stateflags & HANDSTATEFLAG_00000010) == 0 || burst) {
		if (func->ammoindex >= 0
				&& hand->loadedammo[func->ammoindex] == 0
				&& ctrl->ammotypes[func->ammoindex] >= 0) {
			// Clip is empty
			return -1;
		}

		if ((func->type & 0xff00) == 0x100) {
			struct weaponfunc_shootauto *autofunc = (struct weaponfunc_shootauto *) func;

			if (autofunc->unk50 > 0) {
				if (hand->gs_float1 < 1) {
					hand->gs_float1 += LVUPDATE240FREAL() / autofunc->unk50;

					if (hand->gs_float1 > 1) {
						hand->gs_float1 = 1;
						return 1;
					}
				}
			} else {
				hand->gs_float1 = 1;
			}

			return 1;
		}

		hand->gs_float1 = 1;

		if (smallburst) {
			if (hand->burstbullets > 0) {
				s32 delay = 3;

				if (hand->gset.weaponnum == WEAPON_SHOTGUN) {
					delay = TICKS(13);
				}

				if (hand->stateframes < delay) {
					return 0;
				}
			}

			hand->stateframes = 0;
		}

		if ((func->flags & FUNCFLAG_BURST3) && hand->burstbullets == 2) {
			smallburst = false;
		}

		if ((func->flags & FUNCFLAG_BURST2) && hand->burstbullets == 1) {
			smallburst = false;
		}

		if ((func->flags & FUNCFLAG_BURST5) && hand->burstbullets == 4) {
			smallburst = false;
		}

		if (smallburst) {
			return 1;
		}

		return 2;
	}

	if ((func->type & 0xff00) == 0x100) {
		// This is similar to the earlier code, but uses unk51
		// and subtracts the timer instead of adding to it.
		struct weaponfunc_shootauto *autofunc = (struct weaponfunc_shootauto *) func;

		if (autofunc->unk51 > 0) {
			if (hand->gs_float1 > 0) {
				hand->gs_float1 -= LVUPDATE240FREAL() / autofunc->unk51;

				if (hand->gs_float1 < 0) {
					hand->gs_float1 = 0;
					return -1;
				}

				return 1;
			}
		} else {
			hand->gs_float1 = 0;
		}

		return -1;
	}

	return -1;
}

void bgun0f09a6f8(struct handweaponinfo *info, s32 handnum, struct hand *hand, struct weaponfunc *func)
{
	bool usesammo = true;

	static u32 rontime = 2;
	static u32 rofftime = 4;

	mainOverrideVariable("rontime", &rontime);
	mainOverrideVariable("rofftime", &rofftime);

	hand->firing = true;

	if ((func->type & 0xff00) == 0x100) {
		struct weaponfunc_shootauto *autofunc = (struct weaponfunc_shootauto *) func;
		f32 tmp;
		f32 tmp2;

		tmp = autofunc->initialfirerate + (autofunc->maxfirerate - autofunc->initialfirerate) * hand->gs_float1;
		tmp2 = tmp / 60.0f * (LVUPDATE240FREAL() / 60.0f) + hand->shotremainder;

		hand->shotstotake = tmp2;
		hand->shotremainder = tmp2 - hand->shotstotake;

		if (hand->shotstotake <= 0) {
			if ((hand->stateflags & HANDSTATEFLAG_00000010) == 0) {
				hand->shotstotake++;
			} else {
				hand->firing = false;
			}
		}
	} else {
		hand->shotstotake = 1;

		if (hand->gset.weaponnum == WEAPON_LASER) {
			usesammo = false;
		}
	}

	hand->burstbullets += hand->shotstotake;

	if (func->flags & FUNCFLAG_NOMUZZLEFLASH) {
		hand->flashon = false;
	} else {
		hand->flashon = true;
	}

	bgunStartSlide(handnum);

	hand->loadslide = 0;

	if (hand->firing) {
		hand->statevar1 = hand->stateframes;
		hand->stateflags |= HANDSTATEFLAG_00000020;
		hand->stateflags |= HANDSTATEFLAG_00000010;

		bgunRumble(handnum, info->weaponnum);

		if (usesammo && func->ammoindex >= 0) {
			hand->loadedammo[func->ammoindex] -= hand->shotstotake;

			if (hand->loadedammo[func->ammoindex] < 0) {
				// Note: loadedammo is negative
				hand->shotstotake += hand->loadedammo[func->ammoindex];
				hand->loadedammo[func->ammoindex] = 0;
			}
		}

		switch (func->type & 0xff00) {
		case 0:
		case 0x100:
			hand->attacktype = HANDATTACKTYPE_SHOOT;
			break;
		case 0x200:
			hand->attacktype = HANDATTACKTYPE_SHOOTPROJECTILE;
			break;
		}
	}

	if (hand->firing) {
		bool playsound = false;

		if (gsetGetFireslotDuration(&hand->gset) > 0) {
			if (g_Vars.lvframe60 != g_Vars.currentplayer->hands[1 - handnum].lastshootframe60
					&& g_Vars.lvframe60 > hand->allowshootframe) {
				hand->allowshootframe = g_Vars.lvframe60 + gsetGetFireslotDuration(&hand->gset);
				playsound = true;
			}
		} else {
			if (hand->firing) {
				playsound = true;
			}
		}

		if (playsound) {
#if VERSION >= VERSION_NTSC_1_0
			OSPri prevpri = osGetThreadPri(0);
			osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
#endif

			if (hand->audiohandle2 && sndGetState(hand->audiohandle2) != AL_STOPPED) {
				audioStop(hand->audiohandle2);
			}

			if (hand->audiohandle3 && sndGetState(hand->audiohandle3) != AL_STOPPED) {
				audioStop(hand->audiohandle3);
			}

			if (gsetGetSingleShootSound(&hand->gset)) {
				struct sndstate *handle = NULL;

				if (hand->audiohandle2 == NULL) {
					handle = sndStart(var80095200, gsetGetSingleShootSound(&hand->gset), &hand->audiohandle2, -1, -1, -1, -1, -1);
				} else if (hand->audiohandle3 == NULL) {
					handle = sndStart(var80095200, gsetGetSingleShootSound(&hand->gset), &hand->audiohandle3, -1, -1, -1, -1, -1);
				}

				hand->lastshootframe60 = g_Vars.lvframe60;

				if (hand->gset.weaponnum == WEAPON_MAULER && handle) {
					s32 matmot = hand->matmot1;
					f32 tmp;
					f32 frac = matmot / 3.0f;

					if (frac > 1.0f) {
						frac = 1.0f;
					}

					tmp = 1.0f - frac * 0.4f;

					audioPostEvent(handle, 16, *(s32 *) &tmp);
				}

			}

#if VERSION >= VERSION_NTSC_1_0
			osSetThreadPri(0, prevpri);
#endif
		}
	}
}

bool bgun0f09aba4(struct hand *hand, struct handweaponinfo *info, s32 handnum, struct weaponfunc_shoot *func)
{
	s32 unk24;
	s32 unk25;
	s32 sum;
	s32 unk26;
	s32 unk27;
	s32 unk18;
	s32 frames;
	struct weapon *weapondef;
	f32 mult1;
	f32 recoil;
	f32 unk2c;
	f32 mult2;
	u32 stack;

#if PAL
	unk24 = func->unk24;
	unk25 = func->unk25;
	unk26 = func->unk26;
	unk27 = func->unk27;
	unk18 = func->unk18;
	weapondef = info->definition;

	if (unk24 >= 4) {
		unk24 = TICKS(unk24);
	}

	if (unk25 >= 4) {
		unk25 = TICKS(unk25);
	}

	if (unk26 >= 4) {
		unk26 = TICKS(unk26);
	}

	if (unk27 >= 4) {
		unk27 = TICKS(unk27);
	}

	if (unk18 >= 4) {
		unk18 = TICKS(unk18);
	}

	sum = unk24 + unk25;
#elif VERSION >= VERSION_JPN_FINAL
	unk24 = func->unk24;
	unk25 = func->unk25;
	unk26 = func->unk26;
	unk27 = func->unk27;
	unk18 = func->unk18;
	weapondef = info->definition;
	sum = unk24 + unk25;
#else
	unk24 = func->unk24;
	unk25 = func->unk25;
	sum = unk24 + unk25;
	unk26 = func->unk26;
	unk27 = func->unk27;
	unk18 = func->unk18;
	weapondef = info->definition;
#endif

	frames = hand->stateframes - hand->statevar1;

	if (sum < 1) {
		sum = 0;
	} else {
		if (hand->triggerreleased
				&& hand->triggeron
				&& frames >= unk26
				&& unk26 > 0
				&& unk27 >= 0
				&& (hand->stateflags & HANDSTATEFLAG_00000040) == 0
				&& frames + unk27 < sum) {
			hand->stateflags |= HANDSTATEFLAG_00000040;
			hand->statevar1 = frames;

			hand->rotxstart = hand->rotxoffset;
			hand->rotxend = 0;

			hand->posend.x = 0;
			hand->posend.y = 0;
			hand->posend.z = 0;

			hand->posstart.x = hand->posoffset.x;
			hand->posstart.y = hand->posoffset.y;
			hand->posstart.z = hand->posoffset.z;
		}

		if (hand->stateflags & HANDSTATEFLAG_00000040) {
			if (unk27 > frames - hand->statevar1) {
				mult1 = cosf((f32)(unk27 - frames + hand->statevar1) * 1.5707963705063f / (f32)unk27) * 0.5f + 0.5f;

				hand->rotxoffset = model0001afe8(hand->rotxstart, hand->rotxend, mult1);
				hand->useposrot = true;

				hand->posoffset.x = (hand->posend.x - hand->posstart.x) * mult1 + hand->posstart.x;
				hand->posoffset.y = (hand->posend.y - hand->posstart.y) * mult1 + hand->posstart.y;
				hand->posoffset.z = (hand->posend.z - hand->posstart.z) * mult1 + hand->posstart.z;

				mtx4LoadXRotation(hand->rotxoffset, &hand->posrotmtx);
				mtx4SetTranslation(&hand->posoffset, &hand->posrotmtx);
			} else {
				mtx4LoadIdentity(&hand->posrotmtx);
				hand->useposrot = false;
				return true;
			}
		}

		if (frames < sum && (hand->stateflags & HANDSTATEFLAG_00000040) == 0) {
			recoil = func->recoil;
			unk2c = func->unk2c;

			if ((hand->stateflags & HANDSTATEFLAG_00000080) == 0) {
				hand->stateflags |= HANDSTATEFLAG_00000080;
				hand->rotxstart = hand->rotxoffset;
				hand->posstart.x = hand->posoffset.x;
				hand->posstart.y = hand->posoffset.y;
				hand->posstart.z = hand->posoffset.z;
			}

			hand->rotxend = M_BADTAU - (unk2c * M_BADTAU) / 360.0f;

			hand->posend.x = (func0f0b131c(handnum) - hand->aimpos.x) * recoil / 1000.0f;
			hand->posend.y = 0;
			hand->posend.z = (weapondef->frontback - hand->aimpos.z) * recoil / 1000.0f;

			if (frames < unk24) {
				mult2 = sinf(frames * 1.5707963705063f / (f32)unk24);
			} else {
				mult2 = cosf((f32)(frames - unk24) * M_PI / (f32)unk25) * 0.5f + 0.5f;
			}

			hand->rotxoffset = model0001afe8(hand->rotxstart, hand->rotxend, mult2);
			hand->useposrot = true;

			hand->posoffset.x = (hand->posend.x - hand->posstart.x) * mult2 + hand->posstart.x;
			hand->posoffset.y = (hand->posend.y - hand->posstart.y) * mult2 + hand->posstart.y;
			hand->posoffset.z = (hand->posend.z - hand->posstart.z) * mult2 + hand->posstart.z;

			mtx4LoadXRotation(hand->rotxoffset, &hand->posrotmtx);
			mtx4SetTranslation(&hand->posoffset, &hand->posrotmtx);
		}
	}

	if (sum <= frames) {
		if (unk27 >= 0 && hand->triggerreleased && hand->triggeron) {
			return true;
		} else if (sum + unk18 <= frames) {
			return true;
		}
	}

	return false;
}

bool bgunTickIncAttackingShoot(struct handweaponinfo *info, s32 handnum, struct hand *hand)
{
	static u32 var80070128 = 99;

	struct weaponfunc *func = gsetGetWeaponFunction(&hand->gset);
	bool sp68;
	s32 sp64;
	s32 sp60;

	if (func == NULL) {
		return true;
	}

	if (hand->stateminor == 0) {
		sp64 = 1;

		mainOverrideVariable("gkef", &var80070128);

		if (hand->statecycles == 0) {
			hand->gs_float1 = 0;

			if (func->fire_animation) {
				bgunStartAnimation(func->fire_animation, handnum, hand);
				hand->unk0cc8_01 = true;
			}

			hand->burstbullets = 0;
		}

		if (!bgun0f098a44(hand, 2)) {
			sp64 = 0;
		}

		if (sp64) {
			hand->stateminor = 1;
		}

		hand->matmot2 = hand->gs_float1;
	}

	if (hand->stateminor == 1) {
		sp60 = bgun0f09a3f8(hand, func);

		if ((func->type & 0xff00) == 0x100) {
			struct weaponfunc_shootauto *autofunc = (struct weaponfunc_shootauto *) func;
			f32 auStack68[12];

			if (autofunc->unk48 != NULL && autofunc->unk4c != NULL) {
				func0f097b64(autofunc->unk48, autofunc->unk4c, hand->gs_float1, auStack68);
				func0f097b40(hand->upgrademult, auStack68, hand->finalmult);
			}
		}

		if (sp60 > 0) {
			bgun0f09a6f8(info, handnum, hand, func);
		}

		if (sp60 < 0 || sp60 == 2) {
			hand->stateminor = 2;
		}

		hand->matmot2 = hand->gs_float1;

		if (hand->triggeron && hand->matmot2 < 0.4f) {
			hand->matmot2 = 0.4f;
		}

		if (hand->triggerreleased) {
			hand->unk0cc8_01 = false;
		}

		return false;
	}

	if (hand->stateminor == 2) {
		if (hand->stateflags & HANDSTATEFLAG_00000020) {
			sp68 = bgun0f09aba4(hand, info, handnum, (struct weaponfunc_shoot *) func);
		} else {
			sp68 = true;
		}

		if (hand->gset.weaponnum == WEAPON_SHOTGUN && hand->animmode == HANDANIMMODE_BUSY) {
			sp68 = false;
		}

		hand->matmot2 = hand->gs_float1;

		if (sp68 && !hand->triggeron) {
			hand->matmot2 = 0;
		}

		if (hand->gset.weaponnum == WEAPON_MAULER) {
			hand->matmot1 = 0;
		}

		return sp68;
	}

	return false;
}

bool bgunTickIncAttackingThrow(s32 handnum, struct hand *hand)
{
	struct weaponfunc_throw *func = (struct weaponfunc_throw *) gsetGetWeaponFunction(&hand->gset);

	if (func == NULL) {
		return true;
	}

	if (hand->stateminor == 0) {
		if (hand->statecycles == 0) {
			if (func->base.flags & FUNCFLAG_DISCARDWEAPON) {
				invRemoveItemByNum(hand->gset.weaponnum);
				g_Vars.currentplayer->gunctrl.unk1583_04 = true;
#if VERSION >= VERSION_NTSC_1_0
				bgunSwitchToPrevious();
#else
				bgunAutoSwitchWeapon();
#endif
				hand->primetimer60 = 0;
				return true;
			}

			if (func->base.fire_animation) {
				bgunStartAnimation(func->base.fire_animation, handnum, hand);
				hand->unk0cc8_01 = true;
			}
		}

		if (func->base.fire_animation) {
			if (hand->triggerreleased) {
				hand->unk0cc8_01 = false;
			}

			if (bgun0f098a44(hand, 2)) {
				hand->stateminor = 1;
				hand->unk0cc8_01 = false;
			}
		} else {
			hand->stateminor = 1;
		}
	}

	if (hand->stateminor == 1) {
		hand->firing = true;
		hand->attacktype = HANDATTACKTYPE_THROWPROJECTILE;
		hand->loadedammo[func->base.ammoindex]--;
		hand->stateminor = 2;
		return false;
	}

	if (hand->stateminor == 2) {
		if (hand->stateframes > TICKS(func->recoverytime60)) {
			return true;
		}

		if (hand->gset.weaponnum == WEAPON_REMOTEMINE
				&& bgunIsUsingSecondaryFunction() == true
				&& hand->triggerreleased
				&& hand->triggeron) {
			return true;
		}

		return false;
	}

	// This state is only used after having a grenade explode in the player's
	// hand. It waits 4 seconds before finishing, which means the player won't
	// pull out another grenade until the flames have cleared.
	if (hand->stateminor == 55) {
		bgunResetAnim(hand);

		if (hand->stateframes > TICKS(func->activatetime60 + 240)) {
			return true;
		}

		return false;
	}

	hand->primetimer60 = hand->stateframes;

	// If held a grenade too long, force throw it and enter the wait state
	if (hand->gset.weaponnum == WEAPON_GRENADE
			&& hand->gset.weaponfunc == FUNC_PRIMARY
			&& hand->primetimer60 > TICKS(func->activatetime60)) {
		hand->firing = true;
		hand->attacktype = HANDATTACKTYPE_THROWPROJECTILE;
		hand->loadedammo[func->base.ammoindex]--;
		hand->stateminor = 55;

		return false;
	}

	return false;
}

s32 bgunGetMinClipQty(s32 weaponnum, s32 funcnum)
{
	if (weaponnum == WEAPON_TRANQUILIZER && funcnum == FUNC_SECONDARY) {
		return 4;
	}

	return 1;
}

const char var7f1ab8ac[] = "changegunmem type %d CurrentPlayer->gunctrl.gunmemtype %d\n";
const char var7f1ab8e8[] = "LockTimer: %d\n";
const char var7f1ab8f8[] = "BriGun: Releasing gunmem - current gunmemtype %d gunmemnew %d\n";
const char var7f1ab938[] = "GiveMem: %d\n";

u32 var8007012c = 0x00000000;
u32 var80070130 = 0x00000000;

bool bgunTickIncAttackingClose(s32 handnum, struct hand *hand)
{
	struct weaponfunc *func = gsetGetWeaponFunction(&hand->gset);

	if (func == NULL) {
		return true;
	}

	if (hand->gset.weaponnum == WEAPON_REAPER) {
		if (hand->statecycles == 0) {
			hand->matmot2 = 0.1f;
			hand->burstbullets = 0;
		}

		hand->firing = true;
		hand->attacktype = HANDATTACKTYPE_CLOSERANGE;
		hand->burstbullets++;

		if (hand->triggeron) {
			hand->matmot2 += 0.01f * LVUPDATE240FREAL();

			if (hand->matmot2 > 1) {
				hand->matmot2 = 1;
			}
		} else {
			hand->matmot2 = 0;
			return true;
		}

		return false;
	}

	if (hand->stateminor == 0) {
		if (hand->statecycles == 0) {
			hand->firing = true;
			hand->attacktype = HANDATTACKTYPE_CLOSERANGENOUNCLOAK;

			if (func->fire_animation) {
				bgunStartAnimation(func->fire_animation, handnum, hand);
				hand->unk0cc8_01 = true;
			}
		}

		if (func->fire_animation) {
			if (hand->triggerreleased) {
				hand->unk0cc8_01 = false;
			}

			if (bgun0f098a44(hand, 2)) {
				hand->stateminor = 1;
				hand->unk0cc8_01 = false;
			}
		} else {
			hand->stateminor = 1;
		}
	}

	if (hand->stateminor == 3 && bgun0f098a44(hand, 3)) {
		hand->stateminor = 1;
		hand->unk0cc8_01 = false;
	}

	if (hand->stateminor == 1) {
		hand->firing = true;
		hand->attacktype = HANDATTACKTYPE_CLOSERANGE;

		if (hand->gset.weaponnum == WEAPON_TRANQUILIZER && func->ammoindex >= 0) {
			if (hand->loadedammo[func->ammoindex] > bgunGetMinClipQty(WEAPON_TRANQUILIZER, FUNC_SECONDARY)) {
				hand->loadedammo[func->ammoindex] -= bgunGetMinClipQty(WEAPON_TRANQUILIZER, FUNC_SECONDARY);
			} else {
				hand->loadedammo[func->ammoindex] = 0;
			}
		}

		if (func->fire_animation) {
			if (func->fire_animation && !bgun0f098a44(hand, 3)) {
				hand->stateminor = 3;
			} else {
				hand->stateminor = 2;
			}
		}

		if (cheatIsActive(CHEAT_HURRICANEFISTS)) {
			hand->stateminor = 2;
		}

		return false;
	}

	if (hand->stateminor == 2) {
		if (!bgunIsAnimBusy(hand)) {
			return true;
		}

		if (cheatIsActive(CHEAT_HURRICANEFISTS) && hand->gset.weaponnum == WEAPON_UNARMED) {
			return true;
		}

		if (hand->stateframes > TICKS(60)) {
			return true;
		}

		return false;
	}

	return false;
}

bool bgunTickIncAttackingSpecial(struct hand *hand)
{
	struct weaponfunc_special *func = (struct weaponfunc_special *) gsetGetWeaponFunction(&hand->gset);

	if (!func) {
		return true;
	}

	if (hand->stateminor == 0) {
		hand->stateminor = 1;
	}

	if (hand->stateminor == 1) {
		hand->firing = true;
		hand->attacktype = func->specialfunc;

		if (func->base.ammoindex >= 0) {
			hand->loadedammo[func->base.ammoindex]--;
		}

		hand->stateminor = 2;
		return false;
	}

	if (hand->stateminor == 2) {
		if (hand->stateframes > TICKS(func->unk18)) {
			return true;
		}

		return false;
	}

	return false;
}

s32 bgunTickIncAttackEmpty(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	u32 stack;
	bool playsound = false;

	switch (info->weaponnum) {
	case WEAPON_FALCON2:
	case WEAPON_FALCON2_SILENCER:
	case WEAPON_FALCON2_SCOPE:
	case WEAPON_MAGSEC4:
	case WEAPON_MAULER:
	case WEAPON_PHOENIX:
	case WEAPON_DY357MAGNUM:
	case WEAPON_DY357LX:
	case WEAPON_CMP150:
	case WEAPON_CYCLONE:
	case WEAPON_CALLISTO:
	case WEAPON_RCP120:
	case WEAPON_LAPTOPGUN:
	case WEAPON_REAPER:
	case WEAPON_TRANQUILIZER:
	case WEAPON_PP9I:
	case WEAPON_CC13:
		// These weapons are weapons with visible finger trigger animations
		if (hand->stateframes > TICKS(25)) {
			hand->stateframes -= TICKS(25);
			hand->stateflags = 0;

			bgunResetAnim(hand);
		}

		if (hand->animmode != HANDANIMMODE_BUSY) {
			bool restartedanim = false;

			if ((hand->stateflags & HANDSTATEFLAG_00000010) == 0) {
				struct weaponfunc *func = NULL;

				if (info->definition) {
					func = gsetGetWeaponFunction(&hand->gset);
				}

				if (func && func->fire_animation) {
					bgunStartAnimation(func->fire_animation, handnum, hand);
					restartedanim = true;
				}
			}

			if (!restartedanim && hand->stateframes > TICKS(25)) {
				playsound = true;
			}
		} else if (bgun0f098a44(hand, 5)) {
			playsound = true;
		}
		break;
	default:
		// Weapons without visible trigger animations must
		// still play the click sound every 25 frames
		if (hand->stateframes > TICKS(25)) {
			playsound = true;

			hand->stateframes -= TICKS(25);
			hand->stateflags = 0;

			bgunResetAnim(hand);
		}
	}

	hand->mode = HANDMODE_13;
	hand->count60 = 0;
	hand->count = 0;

	if (playsound && (hand->stateflags & HANDSTATEFLAG_00000010) == 0) {
		hand->stateflags |= HANDSTATEFLAG_00000010;

		switch (info->weaponnum) {
		case WEAPON_PHOENIX:
		case WEAPON_CALLISTO:
		case WEAPON_FARSIGHT:
			{
				// Maian weapons have a wet sounding click effect
				f32 speed = 2.07f;

#if VERSION >= VERSION_NTSC_1_0
				OSPri prevpri = osGetThreadPri(0);
				struct sndstate *handle;
				osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
#else
				struct sndstate *handle;
#endif

				handle = sndStart(var80095200, SFX_HIT_WATER, NULL, -1, -1, -1, -1, -1);

				if (handle) {
					audioPostEvent(handle, 16, *(s32 *)&speed);
				}

#if VERSION >= VERSION_NTSC_1_0
				osSetThreadPri(0, prevpri);
#endif
			}
			// fall-through - unsure if intentional
		case WEAPON_TRANQUILIZER:
		case WEAPON_PSYCHOSISGUN:
			{
				// The tranquliser and psychosis gun use the standard click
				// effect but slightly faster.
				f32 speed = 1.5f;

#if VERSION >= VERSION_NTSC_1_0
				OSPri prevpri = osGetThreadPri(0);
				struct sndstate *handle;
				osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
#else
				struct sndstate *handle;
#endif

				handle = sndStart(var80095200, SFX_FIREEMPTY, NULL, -1, -1, -1, -1, -1);

				if (handle) {
					audioPostEvent(handle, 16, *(s32 *)&speed);
				}

#if VERSION >= VERSION_NTSC_1_0
				osSetThreadPri(0, prevpri);
#endif
			}
			break;
		case WEAPON_UNARMED:
		case WEAPON_COMBATKNIFE:
		case WEAPON_GRENADE:
		case WEAPON_NBOMB:
		case WEAPON_TIMEDMINE:
		case WEAPON_PROXIMITYMINE:
		case WEAPON_REMOTEMINE:
		case WEAPON_COMBATBOOST:
			// No sound effect
			break;
		default:
			// Default click sound effect
			sndStart(var80095200, SFX_FIREEMPTY, NULL, -1, -1, -1, -1, -1);
			break;
		}
	}

	// Handle releasing trigger
	if (!hand->triggeron) {
		hand->mode = HANDMODE_NONE;
		hand->count60 = 0;
		hand->count = 0;

		if (bgunSetState(handnum, HANDSTATE_IDLE)) {
			return lvupdate;
		}

		bgunResetAnim(hand);
	}

	return 0;
}

s32 bgunTickIncAttack(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	u32 stack;
	struct weaponfunc *func = NULL;
	bool finished = true;
	u32 stack2;

	if (info->definition) {
		func = gsetGetWeaponFunction(&hand->gset);
	}

	if (func != NULL) {
		switch (func->type & 0xff) {
		case INVENTORYFUNCTYPE_SHOOT:
			finished = bgunTickIncAttackingShoot(info, handnum, hand);
			break;
		case INVENTORYFUNCTYPE_THROW:
			finished = bgunTickIncAttackingThrow(handnum, hand);
			break;
		case INVENTORYFUNCTYPE_CLOSE:
			finished = bgunTickIncAttackingClose(handnum, hand);
			break;
		case INVENTORYFUNCTYPE_SPECIAL:
			finished = bgunTickIncAttackingSpecial(hand);
			break;
		}
	}

	if (finished) {
		if (hand->gset.weaponnum == WEAPON_REAPER && hand->triggeron) {
			hand->gset.weaponfunc = FUNC_SECONDARY;
			finished = false;
		}

		if (finished && bgunSetState(handnum, HANDSTATE_IDLE)) {
			return lvupdate;
		}
	}

	if (1);
	if (1);

	return 0;
}

bool bgunIsReadyToSwitch(s32 handnum)
{
	struct player *player = g_Vars.currentplayer;

	// Dont switch if... something firing range related
	if (g_FrIsValidWeapon
			&& frGetWeaponBySlot(frGetSlot()) == player->hands[HAND_RIGHT].gset.weaponnum
			&& g_Vars.currentplayer->gunctrl.unk1583_04 == false) {
		return false;
	}

	// Don't switch right hand if left hand is about to auto switch
	if (handnum == HAND_RIGHT
			&& player->hands[HAND_LEFT].inuse
			&& player->hands[HAND_LEFT].state == HANDSTATE_AUTOSWITCH
			&& player->hands[HAND_LEFT].stateminor == 0) {
		return false;
	}

	if (player->gunctrl.switchtoweaponnum >= 0) {
		return true;
	}

	if (handnum == HAND_LEFT) {
		if (handnum == HAND_LEFT) {
			if (player->hands[HAND_RIGHT].state == HANDSTATE_RELOAD) {
				return false;
			}

			if (player->hands[HAND_RIGHT].state == HANDSTATE_CHANGEFUNC) {
				return false;
			}

			if (player->hands[HAND_RIGHT].state == HANDSTATE_ATTACK) {
				return false;
			}
		}

		if (player->hands[handnum].inuse && !player->gunctrl.dualwielding) {
			return true;
		}

		if (!player->hands[handnum].inuse && player->gunctrl.dualwielding) {
			return true;
		}
	}

	return false;
}

bool bgunCanFreeWeapon(s32 handnum)
{
	struct player *player = g_Vars.currentplayer;

	if (player->hands[handnum].state == HANDSTATE_CHANGEGUN
			&& player->hands[handnum].stateminor == 2
			&& player->hands[handnum].count >= 3
			&& player->gunctrl.unk1583_04 == false) {
		return true;
	}

	return false;
}

bool bgun0f09bf44(s32 handnum)
{
	bool result = true;
	struct player *player = g_Vars.currentplayer;

	if (!bgun0f09dd7c()) {
		result = false;
	}

	if (player->gunctrl.switchtoweaponnum != -1) {
		result = false;
	}

	if (handnum == HAND_LEFT && player->gunctrl.dualwielding != player->hands[handnum].inuse) {
		result = false;
	}

	if (player->gunctrl.gunmemnew >= 0) {
		result = false;
	}

	if (player->hands[1 - handnum].state == HANDSTATE_RELOAD) {
		result = false;
	}

	return result;
}

s32 bgunTickIncChangeGun(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	u32 stack;
	struct weapon *weapon = info->definition;

	if (hand->statecycles == 0) {
		if (g_Vars.normmplayerisrunning == false) {
			hand->pausetime60 = 0;
		} else {
			hand->pausetime60 = 0;
		}
	}

	// Handle unequip animation
	if (hand->stateminor == 0) {
		bool skipanim = false;

		if (weaponHasFlag(info->weaponnum, WEAPONFLAG_00000001)
				&& (info->weaponnum != WEAPON_REMOTEMINE || handnum != HAND_LEFT)
				&& bgun0f098ca0(0, info, hand) < 0) {
			skipanim = true;
		}

		hand->count = 0;

		if (!skipanim) {
			if (weapon->unequip_animation
					&& hand->inuse == true
					&& (!hand->unk0d0e_00 || hand->unk0d0e_04)) {
				if (hand->statecycles == 0) {
					bgunStartAnimation(weapon->unequip_animation, handnum, hand);
				} else if (hand->animmode == HANDANIMMODE_IDLE) {
					hand->stateminor++;
				}
			} else {
				hand->stateflags |= HANDSTATEFLAG_00000001;

				if (hand->unk0d0e_00 == 1) {
					return 0;
				}

				hand->stateminor++;
			}
		} else {
			hand->stateminor++;
		}

		if (hand->stateminor == 1) {
			hand->stateframes = 0;
		}
	}

	// Handle possible delay between gun disappearing and new one equipping,
	// as well as throwing the gun if that's what we're doing
	if (hand->stateminor == 1) {
		s32 delay = TICKS(16);
		bool somebool = false;
		u32 stack2;

		hand->count = 0;

		if (g_Vars.normmplayerisrunning) {
			delay = TICKS(12);
		}

		if (weapon->unequip_animation && (hand->stateflags & HANDSTATEFLAG_00000001) == 0) {
			delay = 1;
		}

		if (!hand->inuse) {
			delay = 1;
		}

		if (hand->unk0d0e_04 == 0 && (hand->unk0d0e_00 == 1 || hand->unk0d0e_00 == 2)) {
			somebool = true;
		}

		if (g_Vars.currentplayer->gunctrl.unk1583_04 == 1) {
			somebool = true;
		}

		if (hand->stateframes >= delay) {
			if (!somebool) {
				if (g_Vars.mplayerisrunning && (IS8MB() || PLAYERCOUNT() != 1)) {
					playermgrDeleteWeapon(handnum);
				}

				bgunFreeHeldRocket(handnum);
				hand->mode = HANDMODE_6;
				hand->stateminor++;
			} else {
				bgun0f099780(hand, 0.87252569198608f);

				if (g_Vars.currentplayer->gunctrl.unk1583_04 == 1 && hand->inuse) {
					hand->firing = true;
					hand->attacktype = HANDATTACKTYPE_THROWPROJECTILE;
					hand->gset.weaponfunc = FUNC_SECONDARY;
				}
			}
		} else {
			bgun0f099780(hand, hand->stateframes * 0.87252569198608f / delay);
		}
	}

	// Handle equip animation
	if (hand->stateminor == 2) {
		hand->animmode = HANDANIMMODE_IDLE;

		if (hand->pausechange == 0 || hand->pausetime60 <= hand->count60) {
			if (hand->mode == HANDMODE_6) {
				if (bgun0f09bf44(handnum)) {
					hand->mode = HANDMODE_7;

					if (!hand->inuse && bgunSetState(handnum, HANDSTATE_IDLE)) {
						return lvupdate;
					}
				}
			} else {
				if (bgun0f09dd7c()) {
					if (info->definition->equip_animation) {
						bgunStartAnimation(info->definition->equip_animation, handnum, hand);
						hand->unk0cc8_02 = true;
					}

					hand->mode = HANDMODE_8;
					hand->stateminor++;
					hand->count60 = 0;
					hand->count = 0;
				}
			}
		}

		if (hand->mode == HANDMODE_6 || hand->mode == HANDMODE_7) {
			bgun0f099780(hand, 0.87252569198608f);
		}
	}

	// Handle delay if new weapon has no equip animation, and play sound
	if (hand->stateminor == 3) {
		s32 delay = TICKS(23);

		if (g_Vars.normmplayerisrunning) {
			delay = TICKS(12);
		}

		if (weaponHasFlag(hand->gset.weaponnum, WEAPONFLAG_00004000)) {
			hand->animmode = HANDANIMMODE_IDLE;
		} else if (weapon->equip_animation) {
			delay = 1;
		}

		if (hand->count == 0) {
			if (g_Vars.mplayerisrunning && (IS8MB() || PLAYERCOUNT() != 1)) {
				playermgrCreateWeapon(handnum);
			}

			bgun0f098f8c(info, hand);

			if (weaponHasFlag(info->weaponnum, WEAPONFLAG_00000001)
					&& (info->weaponnum != WEAPON_REMOTEMINE || handnum != HAND_LEFT)
					&& bgun0f098ca0(0, info, hand) < 0
					&& bgunSetState(handnum, HANDSTATE_AUTOSWITCH)) {
				hand->stateminor = 1;
				return lvupdate;
			}

			g_Vars.currentplayer->doautoselect = false;

			if (g_Vars.lvupdate240 > 0
					&& g_Vars.currentplayer->cameramode != CAMERAMODE_THIRDPERSON
					&& bgun0f09dd7c()
					&& !g_PlayerInvincible
					&& !g_Vars.currentplayer->isdead) {
#if VERSION >= VERSION_NTSC_1_0
				struct sndstate *handle1;
				f32 speed1;
				struct sndstate *handle2;
				OSPri prevpri1;
				f32 speed2;
				OSPri prevpri2;
				struct sndstate *handle3;
				f32 speed3;
				OSPri prevpri3;
#else
				struct sndstate *handle1;
				f32 speed1;
				struct sndstate *handle2;
				f32 speed2;
				struct sndstate *handle3;
				f32 speed3;
#endif

				switch (info->weaponnum) {
				case WEAPON_HORIZONSCANNER:
					speed1 = 3.5f;

#if VERSION >= VERSION_NTSC_1_0
					prevpri1 = osGetThreadPri(0);
					osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
#endif
					handle1 = sndStart(var80095200, SFX_EQUIP_HORIZONSCANNER, 0, -1, -1, -1, -1, -1);

					if (handle1) {
						audioPostEvent(handle1, 16, *(s32 *)&speed1);
					}

#if VERSION >= VERSION_NTSC_1_0
					osSetThreadPri(0, prevpri1);
#endif
					break;
				case WEAPON_LASER:
					sndStart(var80095200, SFX_PICKUP_LASER, 0, -1, -1, -1, -1, -1);
					break;
				case WEAPON_COMBATKNIFE:
					sndStart(var80095200, SFX_PICKUP_KNIFE, 0, -1, -1, -1, -1, -1);
					break;
				case WEAPON_REMOTEMINE:
					if (handnum == HAND_RIGHT) {
						sndStart(var80095200, SFX_PICKUP_MINE, 0, -1, -1, -1, -1, -1);
					}
					break;
				case WEAPON_TIMEDMINE:
				case WEAPON_PROXIMITYMINE:
				case WEAPON_ECMMINE:
				case WEAPON_DATAUPLINK:
				case WEAPON_RTRACKER:
				case WEAPON_PRESIDENTSCANNER:
				case WEAPON_DOORDECODER:
				case WEAPON_AUTOSURGEON:
				case WEAPON_COMMSRIDER:
				case WEAPON_TRACERBUG:
				case WEAPON_TARGETAMPLIFIER:
					sndStart(var80095200, SFX_PICKUP_MINE, 0, -1, -1, -1, -1, -1);
					break;
				case WEAPON_TRANQUILIZER:
				case WEAPON_PSYCHOSISGUN:
					speed2 = 1.5f;

#if VERSION >= VERSION_NTSC_1_0
					prevpri2 = osGetThreadPri(0);
					osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
#endif

					handle2 = sndStart(var80095200, SFX_PICKUP_GUN, 0, -1, -1, -1, -1, -1);

					if (handle2) {
						audioPostEvent(handle2, 16, *(s32 *)&speed2);
					}

#if VERSION >= VERSION_NTSC_1_0
					osSetThreadPri(0, prevpri2);
#endif
					break;
				case WEAPON_REAPER:
					speed3 = 0.85f;

#if VERSION >= VERSION_NTSC_1_0
					prevpri3 = osGetThreadPri(0);
					osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
#endif

					handle3 = sndStart(var80095200, SFX_PICKUP_GUN, 0, -1, -1, -1, -1, -1);

					if (handle3) {
						audioPostEvent(handle3, 16, *(s32 *)&speed3);
					}

#if VERSION >= VERSION_NTSC_1_0
					osSetThreadPri(0, prevpri3);
#endif
					break;
				case WEAPON_NONE:
				case WEAPON_UNARMED:
				case WEAPON_LAPTOPGUN:
				case WEAPON_CROSSBOW:
				case WEAPON_GRENADE:
				case WEAPON_NBOMB:
				case WEAPON_COMBATBOOST:
				case WEAPON_CLOAKINGDEVICE:
				case WEAPON_EXPLOSIVES:
				case WEAPON_SKEDARBOMB:
				case WEAPON_DISGUISE40:
				case WEAPON_DISGUISE41:
				case WEAPON_FLIGHTPLANS:
				case WEAPON_RESEARCHTAPE:
				case WEAPON_BACKUPDISK:
				case WEAPON_KEYCARD45:
				case WEAPON_KEYCARD46:
				case WEAPON_KEYCARD47:
				case WEAPON_KEYCARD48:
				case WEAPON_KEYCARD49:
				case WEAPON_KEYCARD4A:
				case WEAPON_KEYCARD4B:
				case WEAPON_KEYCARD4C:
				case WEAPON_SUITCASE:
				case WEAPON_BRIEFCASE:
				case WEAPON_NECKLACE:
				case WEAPON_BRIEFCASE2:
					// No equip sound
					break;
				default:
					sndStart(var80095200, SFX_PICKUP_GUN, 0, -1, -1, -1, -1, -1);
					break;
				}
			}
		}

		if (hand->count60 >= delay
				|| !weaponGetModelNum2(info->weaponnum)
				|| !weaponHasFlag(info->weaponnum, WEAPONFLAG_00000040)
				|| weaponHasFlag(info->weaponnum, WEAPONFLAG_00000080)) {
			hand->mode = HANDMODE_NONE;
			hand->stateminor++;

			if (weaponHasFlag(hand->gset.weaponnum, WEAPONFLAG_00004000) == 0) {
				hand->unk0cc8_02 = false;
			}

			hand->count60 = 0;
			hand->count = 0;
		} else {
			bgun0f099780(hand, (delay - hand->count60) * 0.87252569198608f / delay);
		}
	}

	// Wait for equip animation to finish then go to idle state
	if (hand->stateminor == 4) {
		if (info->definition->equip_animation && !weaponHasFlag(hand->gset.weaponnum, WEAPONFLAG_00004000)) {
			if (hand->animmode == HANDANIMMODE_IDLE) {
				if (bgunSetState(handnum, HANDSTATE_IDLE)) {
					return lvupdate;
				}
			}
		} else {
			if (bgunSetState(handnum, HANDSTATE_IDLE)) {
				return lvupdate;
			}
		}
	}

	return 0;
}

/**
 * This function may have implemented an early beta feature where the gun could
 * be held at the side of the screen, pointed upwards. The feature was shown in
 * a demo video but doesn't exist in any public version of the game.
 */
s32 bgunTickIncState2(struct handweaponinfo *info, s32 handnum, struct hand *hand, s32 lvupdate)
{
	return 0;
}

s32 bgunTickInc(struct handweaponinfo *info, s32 handnum, s32 lvupdate)
{
	s32 result = 0;
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];
	s32 prevstate = hand->state;

	hand->firing = false;
	hand->flashon = false;
	hand->stateframes += lvupdate;

	if (g_Vars.lvupdate240 > 0) {
		hand->count60 += g_Vars.lvupdate240_60;
		hand->count++;
	}

	hand->useposrot = false;

	switch (hand->state) {
	case HANDSTATE_IDLE:
		result = bgunTickIncIdle(info, handnum, hand, lvupdate);
		break;
	case HANDSTATE_RELOAD:
		result = bgunTickIncReload(info, handnum, hand, lvupdate);
		break;
	case HANDSTATE_ATTACK:
		result = bgunTickIncAttack(info, handnum, hand, lvupdate);
		break;
	case HANDSTATE_2:
		result = bgunTickIncState2(info, handnum, hand, lvupdate);
		break;
	case HANDSTATE_CHANGEGUN:
		result = bgunTickIncChangeGun(info, handnum, hand, lvupdate);
		break;
	case HANDSTATE_ATTACKEMPTY:
		result = bgunTickIncAttackEmpty(info, handnum, hand, lvupdate);
		break;
	case HANDSTATE_AUTOSWITCH:
		result = bgunTickIncAutoSwitch(info, handnum, hand, lvupdate);
		break;
	case HANDSTATE_CHANGEFUNC:
		result = bgunTickIncChangeFunc(info, handnum, hand, lvupdate);
		break;
	}

	hand->statelastframe = hand->stateframes;

	if (hand->state != prevstate) {
		hand->statelastframe = -result;
	} else {
		hand->stateframes -= result;
		hand->statecycles++;
	}

	return result;
}

bool bgunSetState(s32 handnum, s32 state)
{
	bool valid = true;
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];

	// Sanity check - don't allow changing function if there is no other
	if (state == HANDSTATE_CHANGEFUNC && weaponGetFunction(&hand->gset, 1 - hand->gset.weaponfunc) == NULL) {
		valid = false;
	}

	if (valid) {
		hand->state = state;
		hand->stateframes = 0;
		hand->stateflags = 0;
		hand->statecycles = 0;
		hand->stateminor = 0;
		hand->statelastframe = 0;
	}

	return valid;
}

void bgunTickHand(s32 handnum)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];
	struct handweaponinfo info;
	s32 lvupdate;
	s32 i = 20;

	if (handnum);
	if (handnum);
	if (handnum);
	if (handnum);

#if VERSION >= VERSION_PAL_BETA
	if (handnum);
#endif

	bgunGetWeaponInfo(&info, handnum);

	lvupdate = g_Vars.lvupdate240_60;

	hand->animframeinc = g_Vars.lvupdate240_60;
#if VERSION >= VERSION_PAL_BETA
	hand->animframeincfreal = modelGetAbsAnimSpeed(&hand->gunmodel) * PALUPF(hand->animframeinc);
#else
	hand->animframeincfreal += PALUPF(g_Vars.lvupdate240_60);
#endif

	while (i >= 0) {
		lvupdate = bgunTickInc(&info, handnum, lvupdate);
		i--;

		if (lvupdate <= 0) {
			break;
		}
	}
}

void bgunTickSwitch(void)
{
	bgunTickSwitch2();
}

void bgunInitHandAnims(void)
{
	struct hand *hand;
	s32 i;

	for (i = 0; i < 2; i++) {
		if (i == 0) {
			hand = &g_Vars.currentplayer->hands[1];
		} else {
			hand = &g_Vars.currentplayer->hands[0];
		}

		hand->gangstarot = 0;
		hand->state = HANDSTATE_IDLE;
		hand->animload = -1;
		hand->animmode = HANDANIMMODE_IDLE;

		animInit(&hand->anim);

		hand->gunmodel.anim = &hand->anim;
		hand->handmodel.anim = &hand->anim;
	}
}

f32 bgunGetNoiseRadius(s32 handnum)
{
	return g_Vars.currentplayer->hands[handnum].noiseradius;
}

void bgunDecreaseNoiseRadius(void)
{
	struct player *player = g_Vars.currentplayer;
	f32 consideramount;
	struct gset gsetleft;
	struct gset gsetright;
	struct noisesettings noisesettingsleft;
	struct noisesettings noisesettingsright;
	f32 subamount;

	gsetPopulateFromCurrentPlayer(HAND_LEFT, &gsetleft);
	gsetPopulateFromCurrentPlayer(HAND_RIGHT, &gsetright);

	gsetGetNoiseSettings(&gsetleft, &noisesettingsleft);
	gsetGetNoiseSettings(&gsetright, &noisesettingsright);

	// Right hand
	if (bgunIsFiring(HAND_RIGHT)) {
		player->hands[HAND_RIGHT].noiseradius += noisesettingsright.incradius;

		if (player->hands[HAND_RIGHT].noiseradius > noisesettingsright.maxradius) {
			player->hands[HAND_RIGHT].noiseradius = noisesettingsright.maxradius;
		}
	}

	subamount = g_Vars.lvupdate240freal * noisesettingsright.incradius / (noisesettingsright.unk0c * 60.0f);
	consideramount = (player->hands[HAND_RIGHT].noiseradius - noisesettingsright.minradius) * g_Vars.lvupdate240freal / (noisesettingsright.unk10 * 60.0f);

	if (consideramount > subamount) {
		subamount = consideramount;
	}

	player->hands[HAND_RIGHT].noiseradius -= subamount;

	if (player->hands[HAND_RIGHT].noiseradius < noisesettingsright.minradius) {
		player->hands[HAND_RIGHT].noiseradius = noisesettingsright.minradius;
	}

	// Left hand
	if (bgunIsFiring(HAND_LEFT)) {
		player->hands[HAND_LEFT].noiseradius += noisesettingsleft.incradius;

		if (player->hands[HAND_LEFT].noiseradius > noisesettingsleft.maxradius) {
			player->hands[HAND_LEFT].noiseradius = noisesettingsleft.maxradius;
		}
	}

	subamount = g_Vars.lvupdate240freal * noisesettingsleft.incradius / (noisesettingsleft.unk0c * 60.0f);
	consideramount = (player->hands[HAND_LEFT].noiseradius - noisesettingsleft.minradius) * g_Vars.lvupdate240freal / (noisesettingsleft.unk10 * 60.0f);

	if (consideramount > subamount) {
		subamount = consideramount;
	}

	player->hands[HAND_LEFT].noiseradius -= subamount;

	if (player->hands[HAND_LEFT].noiseradius < noisesettingsleft.minradius) {
		player->hands[HAND_LEFT].noiseradius = noisesettingsleft.minradius;
	}
}

void bgunCalculateBlend(s32 handnum)
{
	s32 sp60[2];
	s32 sp58[2];
	struct weapon *weapon = weaponFindById(bgunGetWeaponNum(handnum));
	f32 mult = weapon->unk38;
	struct player *player = g_Vars.currentplayer;

	sp60[handnum] = (player->hands[handnum].curblendpos + 2) % 4;
	sp58[handnum] = (player->hands[handnum].curblendpos + 1) % 4;
	player->hands[handnum].curblendpos = sp58[handnum];

	player->hands[handnum].blendlook[sp60[handnum]].x = (RANDOMFRAC() - 0.5f) * 0.08f * mult;
	player->hands[handnum].blendlook[sp60[handnum]].y = (RANDOMFRAC() - 0.5f) * 0.1f * mult;
	player->hands[handnum].blendlook[sp60[handnum]].z = -1;

	player->hands[handnum].blendup[sp60[handnum]].x = (RANDOMFRAC() - 0.5f) * 0.1f * mult;
	player->hands[handnum].blendup[sp60[handnum]].y = 1;
	player->hands[handnum].blendup[sp60[handnum]].z = (RANDOMFRAC() - 0.5f) * 0.1f * mult;

	player->hands[handnum].blendpos[sp60[handnum]].x = (RANDOMFRAC() * 0.75f) + 1.5f;
	player->hands[handnum].blendpos[sp60[handnum]].y = (2 + RANDOMFRAC()) * player->hands[handnum].blendscale1;
	player->hands[handnum].blendpos[sp60[handnum]].z = (RANDOMFRAC() - 0.5f) * 2.5f;

	if (player->hands[handnum].sideflag < 0) {
		player->hands[handnum].blendpos[sp60[handnum]].x *= -1;

		if (player->hands[handnum].sideflag == -2) {
			player->hands[handnum].sideflag = 1;
		} else {
			player->hands[handnum].sideflag = -2;
		}
	} else {
		if (player->hands[handnum].sideflag == 2) {
			player->hands[handnum].sideflag = -1;
		} else {
			player->hands[handnum].sideflag = 2;
		}
	}

	player->hands[handnum].blendscale1 = -player->hands[handnum].blendscale1;
}

void bgunUpdateBlend(struct hand *hand, s32 handnum)
{
	u32 stack[3];
	s32 i;
	struct coord sp5c = {0, 0, 0};
	struct coord sp50 = {0, 0, -1};
	struct coord sp44 = {0, 1, 0};
	s32 pos = hand->curblendpos;
	struct player *player = g_Vars.currentplayer;

	func0f096b70(&hand->blendpos[(pos + 3) % 4], &hand->blendpos[pos], &hand->blendpos[(pos + 1) % 4], &hand->blendpos[(pos + 2) % 4], hand->dampt, &sp5c);
	func0f096b70(&hand->blendlook[(pos + 3) % 4], &hand->blendlook[pos], &hand->blendlook[(pos + 1) % 4], &hand->blendlook[(pos + 2) % 4], hand->dampt, &sp50);
	func0f096b70(&hand->blendup[(pos + 3) % 4], &hand->blendup[pos], &hand->blendup[(pos + 1) % 4], &hand->blendup[(pos + 2) % 4], hand->dampt, &sp44);

	sp5c.x *= player->gunposamplitude;
	sp5c.y *= player->gunposamplitude;
	sp5c.z *= player->gunposamplitude;

	sp5c.x += hand->adjustdamp.x;
	sp5c.y += hand->adjustdamp.y;

	sp5c.x += handGetXShift(handnum);

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		hand->damppossum.x = (PAL ? 0.9847f : 0.9872f) * hand->damppossum.x + sp5c.f[0];
		hand->damppossum.y = (PAL ? 0.9847f : 0.9872f) * hand->damppossum.y + sp5c.f[1];
		hand->damppossum.z = (PAL ? 0.9847f : 0.9872f) * hand->damppossum.z + sp5c.f[2];

		hand->damplooksum.x = (PAL ? 0.9847f : 0.9872f) * hand->damplooksum.x + sp50.f[0];
		hand->damplooksum.y = (PAL ? 0.9847f : 0.9872f) * hand->damplooksum.y + sp50.f[1];
		hand->damplooksum.z = (PAL ? 0.9847f : 0.9872f) * hand->damplooksum.z + sp50.f[2];

		hand->dampupsum.x = (PAL ? 0.9847f : 0.9872f) * hand->dampupsum.x + sp44.f[0];
		hand->dampupsum.y = (PAL ? 0.9847f : 0.9872f) * hand->dampupsum.y + sp44.f[1];
		hand->dampupsum.z = (PAL ? 0.9847f : 0.9872f) * hand->dampupsum.z + sp44.f[2];
	}

	hand->damppos.x = hand->damppossum.x * (PAL ? 0.01529997587204f : 0.012799978f) * 2;
	hand->damppos.y = hand->damppossum.y * (PAL ? 0.01529997587204f : 0.012799978f) * 2;
	hand->damppos.z = hand->damppossum.z * (PAL ? 0.01529997587204f : 0.012799978f) * 2;

	hand->damplook.x = hand->damplooksum.x * (PAL ? 0.01529997587204f : 0.012799978f);
	hand->damplook.y = hand->damplooksum.y * (PAL ? 0.01529997587204f : 0.012799978f);
	hand->damplook.z = hand->damplooksum.z * (PAL ? 0.01529997587204f : 0.012799978f);

	hand->dampup.x = hand->dampupsum.x * (PAL ? 0.01529997587204f : 0.012799978f);
	hand->dampup.y = hand->dampupsum.y * (PAL ? 0.01529997587204f : 0.012799978f);
	hand->dampup.z = hand->dampupsum.z * (PAL ? 0.01529997587204f : 0.012799978f);
}

u32 var80070158 = 0x04e50764;
u32 var8007015c = 0x05360529;
u32 var80070160 = 0x0531052a;
u32 var80070164 = 0x052b052c;
u32 var80070168 = 0x052c052d;
u32 var8007016c = 0x052b052b;
u32 var80070170 = 0x052e052f;
u32 var80070174 = 0x052f0530;
u32 var80070178 = 0x05310532;
u32 var8007017c = 0x05320533;
u32 var80070180 = 0x05340535;
u32 var80070184 = 0x05360537;
u32 var80070188 = 0x05380530;
u32 var8007018c = 0x0539053a;
u32 var80070190 = 0x0532053b;
u32 var80070194 = 0x05310766;
u32 var80070198 = 0x07670768;
u32 var8007019c = 0x0769076a;
u32 var800701a0 = 0x076b076c;
u32 var800701a4 = 0x076d0000;
u32 var800701a8 = 0x0000ffff;

void bgun0f09d8dc(f32 breathing, f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
	f32 dampt[2];
	struct player *player = g_Vars.currentplayer;
	u32 stack;
	s32 i;
	f32 sp50 = arg2;
	f32 sp4c;
	u32 stack2;

	if (sp50 < 0.0f) {
		sp50 = -sp50;
	}

	if (arg1 > 0.8f) {
		player->gunposamplitude = 1.0f;
	} else {
		if (arg1 > 0.1f) {
			f32 tmp = 1.0f - cosf((arg1 - 0.1f) * M_BADTAU / 2.8f);
			player->gunposamplitude = 0.8f * tmp + 0.2f;
		} else {
			player->gunposamplitude = 0.1f;
		}
	}

	if (bmoveGetCrouchPos() != CROUCHPOS_SQUAT) {
		if (player->gunposamplitude < 0.3f * g_Vars.currentplayer->bondbreathing) {
			player->gunposamplitude = 0.3f * g_Vars.currentplayer->bondbreathing;
		}
	}

	if (player->gunposamplitude < 0.5f * sp50) {
		player->gunposamplitude = 0.5f * sp50;
	}

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		player->gunampsum = (PAL ? 0.9847f : 0.9872f) * player->gunampsum + player->gunposamplitude;
	}

	player->gunposamplitude = (PAL ? 0.01529997587204f : 0.012799978256226f) * player->gunampsum;

	if (breathing < 0.016666667535901f * sp50) {
		breathing = 0.016666667535901f * sp50;
	}

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		player->cyclesum = (PAL ? 0.9847f : 0.9872f) * player->cyclesum + breathing;
	}

	breathing = player->cyclesum * (PAL ? 0.01529997587204f : 0.012799978256226f);
	sp4c = breathing * g_Vars.lvupdate240freal;
	dampt[0] = player->hands[0].dampt + sp4c;

	while (dampt[0] >= 1.0f) {
		bgunCalculateBlend(HAND_RIGHT);
		dampt[0] -= 1.0f;
		player->syncoffset++;
	}

	player->synccount += g_Vars.lvupdate240freal;

	if (player->synccount > 60.0f) {
		player->synccount = 0.0f;
		player->syncchange = (RANDOMFRAC() - 0.5f) * 0.2f / 60.0f;
	}

	if (player->syncchange + sp4c > 0.0f) {
		player->gunsync += player->syncchange;
	}

	if (player->gunsync > 0.5f) {
		player->gunsync = 0.5f;
	} else if (player->gunsync < -0.5f) {
		player->gunsync = -0.5f;
	} else if (player->gunsync < 0.1f && player->gunsync > -0.1f) {
		if (player->gunsync > 0.0f) {
			player->gunsync = -0.1f;
		} else {
			player->gunsync = 0.1f;
		}
	}

	dampt[1] = dampt[0] + player->syncoffset + player->gunsync;

	while (dampt[1] >= 1.0f) {
		bgunCalculateBlend(HAND_LEFT);
		dampt[1] -= 1.0f;
		player->syncoffset--;
	}

	for (i = 0; i < 2; i++) {
		player->hands[i].dampt = dampt[i];
		player->hands[i].adjustdamp.x = -1.75f * arg3 + -0.8f * arg4;
		player->hands[i].adjustdamp.y = -2.0f * arg2;
	}
}

bool bgun0f09dd7c(void)
{
	if (g_Vars.currentplayer->gunctrl.gunmemowner) {
		return false;
	}

	return g_Vars.currentplayer->gunctrl.gunmemtype == 0
		|| (g_Vars.currentplayer->gunctrl.gunmemnew < 0
				&& g_Vars.currentplayer->gunctrl.masterloadstate == MASTERLOADSTATE_LOADED);
}

u32 bgunGetGunMemType(void)
{
	return g_Vars.currentplayer->gunctrl.gunmemtype;
}

struct modelfiledata *bgun0f09dddc(void)
{
	return g_Vars.currentplayer->gunctrl.gunmodeldef;
}

u8 *bgunGetGunMem(void)
{
	return g_Vars.currentplayer->gunctrl.gunmem;
}

u32 bgunCalculateGunMemCapacity(void)
{
	if (IS4MB() && PLAYERCOUNT() == 2) {
		return var800700ac;
	}

	if (PLAYERCOUNT() == 1) {
		switch (g_Vars.stagenum) {
		case STAGE_CHICAGO:
		case STAGE_AIRBASE:
		case STAGE_VILLA:
		case STAGE_AIRFORCEONE:
		case STAGE_ATTACKSHIP:
			 return var800700a8 + 0x6400;
		}
	}

	return var800700a8;
}

void bgunFreeGunMem(void)
{
	g_Vars.currentplayer->gunctrl.gunmemowner = GUNMEMOWNER_FREE;
}

void bgunSetGunMemWeapon(s32 weaponnum)
{
	struct player *player = g_Vars.currentplayer;

	if (player->gunctrl.gunmemowner == GUNMEMOWNER_BONDGUN) {
		player->gunctrl.masterloadstate = MASTERLOADSTATE_FLUX;
		player->gunctrl.gunloadstate = GUNLOADSTATE_FLUX;
		player->gunctrl.gunmemnew = weaponnum;
		player->gunctrl.gunlocktimer = -1;
	} else {
		player->gunctrl.gunmemnew = weaponnum;
	}
}

void bgun0f09df9c(void)
{
	s32 i;
	struct casing *end;
	struct casing *casing;

	g_Vars.currentplayer->gunctrl.handfilenum = 0xffff;
	g_Vars.currentplayer->gunctrl.handmodeldef = NULL;
	g_Vars.currentplayer->gunctrl.unk15a0 = 0;
	g_Vars.currentplayer->gunctrl.unk15a4 = 0;
	g_Vars.currentplayer->gunctrl.masterloadstate = MASTERLOADSTATE_FLUX;
	g_Vars.currentplayer->gunctrl.gunloadstate = GUNLOADSTATE_FLUX;

	end = g_Casings + ARRAYCOUNT(g_Casings);
	casing = g_Casings;

	while (casing < end) {
		casing->modeldef = NULL;
		casing++;
	}

	g_CasingsActive = false;
}

bool bgun0f09e004(s32 newowner)
{
	struct player *player = g_Vars.currentplayer;

	if (player->gunctrl.gunmemowner == newowner) {
		return true;
	}

	if (player->gunctrl.gunlocktimer < 0) {
		player->gunctrl.gunlocktimer--;

		if (player->gunctrl.gunlocktimer < -2) {
			player->gunctrl.gunlocktimer = 0;
			player->gunctrl.gunmemowner = newowner;
			return true;
		}
	} else {
		bool unlock = false;

		switch (player->gunctrl.gunmemowner) {
		case GUNMEMOWNER_BONDGUN:
			if (player->gunctrl.gunmemtype != -1) {
				player->gunctrl.gunmemnew = player->gunctrl.gunmemtype;
			}

			player->gunctrl.gunmemtype = -1;
			bgun0f09df9c();
			player->gunctrl.unk1583_06 = true;
			unlock = true;
			break;
		case GUNMEMOWNER_CHRBODY:
			if (g_Vars.mplayerisrunning) {
				unlock = true;
			}

			if (!player->haschrbody) {
				unlock = true;
			}

			if (newowner == GUNMEMOWNER_INVMENU && var8009dfc0 != 0) {
				unlock = true;
				playerRemoveChrBody();
			}
			break;
		case GUNMEMOWNER_3:
			unlock = true;
			break;
		case GUNMEMOWNER_CHANGING:
		case GUNMEMOWNER_FREE:
			unlock = true;
			break;
		}

		if (unlock) {
			player->gunctrl.gunlocktimer = -1;
			player->gunctrl.gunmemowner = GUNMEMOWNER_CHANGING;
		}
	}

	return false;
}

/**
 * This function loads resources for a gun change.
 *
 * The caller sets properties in the player's gunctrl struct which tell this
 * function what to load, where the gunmem is that it can use, and how much
 * gunmem there is. This function is then called a couple of times on subsequent
 * ticks, loading data incrementally to avoid a significant lag spike.
 *
 * The function keeps track of its progress in the gunloadstate property, and
 * updates the gunmem properties to reflect its usage.
 *
 * The first call loads the model definition from the ROM and decompresses it.
 * The second call loads and decompress to 3 textures.
 * This continues on further calls until all textures are loaded.
 * The final call does some one-off processing on the model's display lists.
 *
 * Although the name contains "Gun", it's used for more than just the gun model.
 * It's used for the hand model, the gun model and the cartridge model.
 */
void bgunTickGunLoad(void)
{
	s32 i;
	s32 numthistick;
	u32 remaining;
	s32 padding;
	u32 allocsize;
	u32 loadsize;
	u32 ptr;
	struct player *player = g_Vars.currentplayer;
	struct modelfiledata *modeldef;
	struct fileinfo *fileinfo;
	struct fileinfo *gunfileinfo;
	s32 newvalue;
	u32 end;
	u32 stack;
#if VERSION >= VERSION_NTSC_1_0
	u32 stack2;
#endif

	if (player->gunctrl.gunloadstate == GUNLOADSTATE_MODEL) {
		osSyncPrintf("BriGun:  BriGunLoadTick process GUN_LOADSTATE_LOAD_OBJ\n");

		ptr = *player->gunctrl.loadmemptr;
		remaining = *player->gunctrl.loadmemremaining;

		// Align ptr to the next 16 byte boundary
		if (ptr % 16) {
			padding = 16 - (ptr % 16);
			ptr += padding;
			remaining -= padding;
		}

		*player->gunctrl.loadmemptr = ptr;
		*player->gunctrl.loadmemremaining = remaining;

		loadsize = ALIGN64(fileGetInflatedSize(player->gunctrl.loadfilenum)) + 0x8000;

		osSyncPrintf("BriGun:  Loading - %s, pMem 0x%08x Size %d\n");

		if (loadsize > remaining) {
			osSyncPrintf("BriGun:  Warning: LoadSize > MemSize, clamping decomp. buffer from %d to %d (%d Bytes)\n", allocsize, remaining, remaining);
			loadsize = remaining;
		}

		// Load the model file to ptr
		g_LoadType = LOADTYPE_GUN;

		osSyncPrintf("BriGun:  obLoadto at 0x%08x, size %d\n", ptr, loadsize);

		modeldef = fileLoadToAddr(player->gunctrl.loadfilenum, FILELOADMETHOD_EXTRAMEM, (u8 *)ptr, loadsize);

		// Reserve some space for textures
		allocsize = fileGetLoadedSize(player->gunctrl.loadfilenum) + 0xe00;

		osSyncPrintf("BriGun:  Used size %d (Ob Size %d)\n");
		osSyncPrintf("BriGun:  block len %d usedsize %d\n");
		osSyncPrintf("BriGun:  obln ram_len %d block_len %d\n");
		osSyncPrintf("BriGun:  new used size %d\n");

		fileGetLoadedSize(player->gunctrl.loadfilenum);

		fileinfo = &g_FileInfo[player->gunctrl.loadfilenum];
		fileinfo->allocsize = allocsize;
		end = ALIGN16((s32)ptr + allocsize);
		allocsize = end - ptr;
		if (1);
		remaining -= allocsize;

		osSyncPrintf("BriGun:  Texture Block at 0x%08x size %d, endp 0x%08x\n");

		texInitPool(&player->gunctrl.unk15c0, (u8 *)end, remaining);

		// Tidy up the model
		modelPromoteTypeToPointer(modeldef);
		modelPromoteOffsetsToPointers(modeldef, 0x05000000, (u32)modeldef);

		*player->gunctrl.loadtomodeldef = modeldef;

		player->gunctrl.nexttexturetoload = 0;
		player->gunctrl.fileinfo = *fileinfo;

		osSyncPrintf("BriGun:  Set Load State: GUN_LOADSTATE_DECOMPRESS_TEXTURES\n");
		player->gunctrl.gunloadstate = GUNLOADSTATE_TEXTURES;
		return;
	}

	if (player->gunctrl.gunloadstate == GUNLOADSTATE_TEXTURES) {
		osSyncPrintf("BriGun:  BriGunLoadTick process GUN_LOADSTATE_DECOMPRESS_TEXTURES\n");

		gunfileinfo = &player->gunctrl.fileinfo;
		fileinfo = &g_FileInfo[player->gunctrl.loadfilenum];
		*fileinfo = *gunfileinfo;
		modeldef = *player->gunctrl.loadtomodeldef;

		// Load textures - up to 3 per call
		numthistick = 0;

		for (i = player->gunctrl.nexttexturetoload; i < modeldef->numtexconfigs; i++) {
			osSyncPrintf("BriGun:  at texture %d\n", i);

			if (modeldef->texconfigs[i].texturenum < NUM_TEXTURES) {
				osSyncPrintf("BriGun:  Uncompress %d of %d\n", i, modeldef->numtexconfigs);
				texLoad(&modeldef->texconfigs[i].texturenum, &player->gunctrl.unk15c0, true);
				modeldef->texconfigs[i].unk0b = 1;
			}

			numthistick++;

			if (numthistick == 3) {
				return;
			}

			// @bug: This should be incremented prior to the return, otherwise
			// subsequent ticks will waste time loading a texture that's already
			// been loaded.
			player->gunctrl.nexttexturetoload++;
		}

		*gunfileinfo = *fileinfo;

		osSyncPrintf("BriGun:  Set Load State: GUN_LOADSTATE_DECOMPRESS_DLS\n");
		player->gunctrl.gunloadstate = GUNLOADSTATE_DLS;
		return;
	}

	if (player->gunctrl.gunloadstate == GUNLOADSTATE_DLS) {
		osSyncPrintf("BriGun:  BriGunLoadTick process GUN_LOADSTATE_DECOMPRESS_DLS\n");

		fileinfo = &g_FileInfo[player->gunctrl.loadfilenum];
		*fileinfo = player->gunctrl.fileinfo;
		modeldef = *player->gunctrl.loadtomodeldef;

		modeldef0f1a7560(modeldef, player->gunctrl.loadfilenum, 0x05000000, modeldef, &player->gunctrl.unk15c0, false);

		fileGetInflatedSize(player->gunctrl.loadfilenum);
		fileGetLoadedSize(player->gunctrl.loadfilenum);
		fileGetLoadedSize(player->gunctrl.loadfilenum);
		fileGetLoadedSize(player->gunctrl.loadfilenum);

		modelCalculateRwDataLen(modeldef);

		osSyncPrintf("BriGun:  propgfx_decompress 0x%08x\n");
		osSyncPrintf("BriGun:  DL waste space %d from %d (Used %d, Ramlen %d, ObSize %d)\n");
		osSyncPrintf("Increase GUNSAVESIZE to %d!!!\n");

		newvalue = ALIGN64(texGetPoolLeftPos(&player->gunctrl.unk15c0));
		remaining = *player->gunctrl.loadmemremaining;
		remaining -= (s32)(newvalue - *player->gunctrl.loadmemptr);

		*player->gunctrl.loadmemptr = newvalue;
		*player->gunctrl.loadmemremaining = remaining;

		osSyncPrintf("BriGun:  Set Load State: GUN_LOADSTATE_LOADED\n");
		player->gunctrl.gunloadstate = GUNLOADSTATE_LOADED;

#if PIRACYCHECKS
		{
			s32 *ptr = (s32 *)&tagsReset;
			s32 *end = (s32 *)&tagFindById;
			u32 checksum = 0;

			while (ptr < end) {
				checksum -= ~*ptr;
				ptr++;
			}

			if (checksum != CHECKSUM_PLACEHOLDER) {
				ptr = (s32 *)&tagsReset + 3;

				if (1);
				end = &ptr[7];

				while (ptr < end) {
					*ptr |= 0xff;
					ptr++;
				}
			}
		}
#endif
	}
}

const char var7f1abcd8[] = "need a new gun loading (lock %d gunmemnew %d)\n";
const char var7f1abd08[] = "loading gun file: %d type: %d\n";
const char var7f1abd28[] = "BriGun: Process MASTER_GUN_LOADSTATE_FLUX\n";
const char var7f1abd54[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_HANDS\n";
const char var7f1abd8c[] = "BriGun: Process MASTER_GUN_LOADSTATE_HANDS\n";
const char var7f1abdb8[] = "BriGun: Setup Hand Load\n";
const char var7f1abdd4[] = "Hand  : Using cached hands\n";
const char var7f1abdf0[] = "Hand  : Look ma no hands!\n";
const char var7f1abe0c[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_GUN\n";
const char var7f1abe40[] = "BriGun: Process MASTER_GUN_LOADSTATE_GUN\n";
const char var7f1abe6c[] = "BriGun: Setup Gun Load\n";
const char var7f1abe84[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_CARTS\n";
const char var7f1abebc[] = "BriGun: Process MASTER_GUN_LOADSTATE_CARTS\n";
const char var7f1abee8[] = "BriGun: Cart Loaded setting GUN_LOADSTATE_FLUX\n";
const char var7f1abf18[] = "BriGun: Cart loading - looking for carts\n";
const char var7f1abf44[] = "BriGun: Loading cart %d\n";
const char var7f1abf60[] = "BriGun: Request for cart %d ignored - cart already loaded\n";
const char var7f1abf9c[] = "BriGun: Compile Hand 0x%08x Gun 0x%0x8\n";
const char var7f1abfc4[] = "Gun   : Compiled Gun 0x%08x\n";
const char var7f1abfe4[] = "Gun   : Compiled Size %d\n";
const char var7f1ac000[] = "Hand  : Compiled Hand 0x%08x\n";
const char var7f1ac020[] = "Hand  : Compiled Size %d\n";
const char var7f1ac03c[] = "Gun   : Compile overhead %d bytes\n";
const char var7f1ac060[] = "Hand  : Hand Obj 0x%08x Gun Obj 0x%08x \n";
const char var7f1ac08c[] = "Gun   : After Comp : Base 0x%08x Free %d\n";
const char var7f1ac0b8[] = "Gun   : After Cached Setup : Base 0x%08x Free %d\n";
const char var7f1ac0ec[] = "Gun   : TotalUsed %d, Free %d\n";
const char var7f1ac10c[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_LOADED\n";
const char var7f1ac144[] = "GunLockTimer: %d\n";

void bgunTickMasterLoad(void)
{
	s32 newweaponnum;
	struct player *player = g_Vars.currentplayer;
	bool hashands;
	u16 handfilenum;
	s32 sum;
	u16 filenum;
	s32 i;
	struct casing *casing;
	struct hand *hand;
	struct weaponfunc *func;
	struct weaponfunc *shootfunc;
	struct weapon *weapondef;
	s32 casingindex;
	struct inventory_ammo *ammodef;
	s32 value;
	s32 bodynum;
	s32 headnum;

	if ((player->gunctrl.gunmemowner == GUNMEMOWNER_BONDGUN || bgun0f09e004(GUNMEMOWNER_BONDGUN)) && player->gunctrl.gunmemnew >= 0) {
		if (player->gunctrl.gunlocktimer == 0) {
			newweaponnum = player->gunctrl.gunmemnew;

			playerChooseBodyAndHead(&bodynum, &headnum, NULL);

			handfilenum = g_HeadsAndBodies[bodynum].handfilenum;

			if (IS4MB()) {
				handfilenum = FILE_GCOMBATHANDSLOD;
			}

			filenum = weaponGetModelNum(newweaponnum);

			if (player->gunctrl.masterloadstate != MASTERLOADSTATE_LOADED || newweaponnum != player->gunctrl.gunmemtype) {
				if (filenum) {
					hashands = false;

					if (weaponHasFlag(newweaponnum, WEAPONFLAG_HASHANDS)) {
						hashands = true;
					}

					if (newweaponnum == WEAPON_UNARMED) {
						// For unarmed, the fists are implemented
						// as weapon models rather than hand models
						filenum = handfilenum;
						handfilenum = 0 * (player->gunctrl.gunloadstate == 4);
						hashands = false;
					}

					if (player->gunctrl.masterloadstate == MASTERLOADSTATE_FLUX) {
						casing = g_Casings;

						while (casing < &g_Casings[ARRAYCOUNT(g_Casings)]) {
							if (casing->modeldef == player->gunctrl.cartmodeldef) {
								casing->modeldef = NULL;
							}

							casing++;
						}

						g_CasingsActive = false;

						casing = g_Casings;

						while (casing < &g_Casings[ARRAYCOUNT(g_Casings)]) {
							if (casing->modeldef != NULL) {
								g_CasingsActive = true;
							}

							casing++;
						}

						player->gunctrl.cartmodeldef = NULL;
						player->gunctrl.masterloadstate = MASTERLOADSTATE_HANDS;
					} else if (player->gunctrl.masterloadstate == MASTERLOADSTATE_HANDS) {
						if (hashands) {
							if (handfilenum != player->gunctrl.handfilenum) {
								if (player->gunctrl.gunloadstate == GUNLOADSTATE_FLUX) {
									player->gunctrl.unk15a0 = bgunGetGunMem();
									player->gunctrl.unk15a4 = bgunCalculateGunMemCapacity();
									player->gunctrl.gunloadstate = GUNLOADSTATE_MODEL;
									player->gunctrl.loadfilenum = handfilenum;
									player->gunctrl.loadtomodeldef = &player->gunctrl.handmodeldef;
									player->gunctrl.loadmemptr = (u32 *) &player->gunctrl.unk15a0;
									player->gunctrl.loadmemremaining = (u32 *) &player->gunctrl.unk15a4;
								}

								bgunTickGunLoad();

								if (player->gunctrl.gunloadstate == GUNLOADSTATE_LOADED) {
									player->gunctrl.handfilenum = handfilenum;
								} else {
									return;
								}
							}
						} else {
							player->gunctrl.handfilenum = 0;
							player->gunctrl.handmodeldef = NULL;
							player->gunctrl.unk15a0 = bgunGetGunMem();
							player->gunctrl.unk15a4 = bgunCalculateGunMemCapacity();
						}

						player->gunctrl.masterloadstate = MASTERLOADSTATE_GUN;
						player->gunctrl.gunloadstate = GUNLOADSTATE_FLUX;
					} else if (player->gunctrl.masterloadstate == MASTERLOADSTATE_GUN) {
						if (player->gunctrl.gunloadstate == GUNLOADSTATE_FLUX) {
							player->gunctrl.unk15a8 = (u8 *) player->gunctrl.unk15a0;
							player->gunctrl.unk15ac = player->gunctrl.unk15a4;
							player->gunctrl.gunloadstate = GUNLOADSTATE_MODEL;
							player->gunctrl.loadfilenum = filenum;
							player->gunctrl.loadtomodeldef = &player->gunctrl.gunmodeldef;
							player->gunctrl.loadmemptr = (u32 *) &player->gunctrl.unk15a8;
							player->gunctrl.loadmemremaining = (u32 *) &player->gunctrl.unk15ac;
						}

						bgunTickGunLoad();

						if (player->gunctrl.gunloadstate == GUNLOADSTATE_LOADED) {
							player->gunctrl.masterloadstate = MASTERLOADSTATE_CARTS;
							player->gunctrl.gunloadstate = GUNLOADSTATE_FLUX;
						}
					} else if (player->gunctrl.masterloadstate == MASTERLOADSTATE_CARTS) {
						if (player->gunctrl.gunloadstate == GUNLOADSTATE_LOADED) {
							player->gunctrl.gunloadstate = GUNLOADSTATE_FLUX;
						}

						if (player->gunctrl.gunloadstate == GUNLOADSTATE_FLUX && player->gunctrl.cartmodeldef == NULL && PLAYERCOUNT() == 1) {
							for (i = 0; i < 2; i++) {
								hand = player->hands + i;
								func = gsetGetWeaponFunction2(&hand->gset);
								shootfunc = NULL;
								weapondef = weaponFindById(player->gunctrl.weaponnum);
								casingindex = -1;

								if (func != NULL) {
									if ((func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
										shootfunc = func;
									}

									if (weapondef && shootfunc) {
										ammodef = func->ammoindex >= 0 ? weapondef->ammos[func->ammoindex] : NULL;

										if (ammodef) {
											casingindex = ammodef->casingeject;
										}
									}

									if (casingindex >= 0) {
										if (player->gunctrl.cartmodeldef == NULL) {
											filenum = g_CartFileNums[casingindex];
											player->gunctrl.loadfilenum = filenum;
											player->gunctrl.gunloadstate = GUNLOADSTATE_MODEL;
											player->gunctrl.loadtomodeldef = &player->gunctrl.cartmodeldef;
											player->gunctrl.loadmemptr = (u32 *) &player->gunctrl.unk15a8;
											player->gunctrl.loadmemremaining = (u32 *) &player->gunctrl.unk15ac;
											break;
										}

										break;
									}
								}
							}
						}

						if (player->gunctrl.gunloadstate != GUNLOADSTATE_FLUX) {
							bgunTickGunLoad();
							return;
						}

						sum = 0;

						for (i = 0; i < 2; i++) {
							hand = &player->hands[i];

							modelInit(&hand->gunmodel, player->gunctrl.gunmodeldef, (union modelrwdata **)hand->unk0a6c, 0);

							if (player->gunctrl.handmodeldef != 0) {
								modelInit(&hand->handmodel, player->gunctrl.handmodeldef, (union modelrwdata **)hand->handsavedata, false);
							}

							hand->unk0dcc = (s32 *) player->gunctrl.unk15a8;

							value = bgunCreateModelCmdList(&hand->gunmodel, player->gunctrl.gunmodeldef->rootnode, (s32 *) player->gunctrl.unk15a8);

							sum += value;
							player->gunctrl.unk15a8 += value;
							player->gunctrl.unk15ac -= value;

							if (player->gunctrl.handmodeldef != 0) {
								hand->unk0dd0 = (s32 *) player->gunctrl.unk15a8;

								value = bgunCreateModelCmdList(&hand->handmodel, player->gunctrl.handmodeldef->rootnode, (s32 *) player->gunctrl.unk15a8);

								sum += value;
								player->gunctrl.unk15a8 += value;
								player->gunctrl.unk15ac -= value;
							}
						}

						hand = &player->hands[0];
						hand->unk0dd4 = -1;

						if (player->gunctrl.unk15ac > 3200) {
							hand->unk0dd8 = (Mtxf *) player->gunctrl.unk15a8;
							player->gunctrl.unk15a8 += 3200;
							player->gunctrl.unk15ac -= 3200;
						} else {
							hand->unk0dd8 = 0;
						}

						bgunCalculateGunMemCapacity();

						player->gunctrl.masterloadstate = MASTERLOADSTATE_LOADED;
						player->gunctrl.gunmemtype = newweaponnum;
						player->gunctrl.gunmemnew = -1;
					}
				}
#if VERSION >= VERSION_NTSC_1_0
				else {
					player->gunctrl.masterloadstate = MASTERLOADSTATE_LOADED;
					player->gunctrl.gunmemtype = newweaponnum;
					player->gunctrl.gunmemnew = -1;
				}
#endif
			}
		} else {
			player->gunctrl.gunlocktimer--;

			if (player->gunctrl.gunlocktimer < -2) {
				player->gunctrl.gunlocktimer = 0;
			}
		}
	}
}

void bgunTickLoad(void)
{
	s32 i;

	for (i = 0; i < g_Vars.lvupdate240; i += 8) {
		bgunTickMasterLoad();
	}
}

bool bgun0f09eae4(void)
{
	// PAL adds a check for the eyespy being used
#if VERSION >= VERSION_PAL_BETA
	if ((g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY)) {
		g_Vars.currentplayer->gunctrl.unk1583_06 = false;
		return false;
	}
#endif

	bgun0f09df9c();

	if (g_Vars.currentplayer->gunctrl.weaponnum != WEAPON_NONE) {
		g_Vars.currentplayer->gunctrl.gunmemnew = g_Vars.currentplayer->gunctrl.weaponnum;
	} else {
		return false;
	}

	if (g_Vars.currentplayer->gunctrl.gunmemtype != -1) {
		return false;
	}

	if (g_Vars.currentplayer->gunctrl.gunmemowner != GUNMEMOWNER_BONDGUN) {
		bgun0f09e004(GUNMEMOWNER_BONDGUN);

		if (g_Vars.currentplayer->gunctrl.gunmemowner != GUNMEMOWNER_BONDGUN) {
			g_Vars.lockscreen = true;
			return true;
		}
	}

	bgun0f09df9c();

	do {
		bgunTickMasterLoad();
	} while (!bgun0f09dd7c());

	g_Vars.currentplayer->gunctrl.unk1583_06 = false;

	return false;
}

struct modelfiledata *bgunGetCartModeldef(void)
{
	return g_Vars.currentplayer->gunctrl.cartmodeldef;
}

void bgun0f09ebcc(struct defaultobj *obj, struct coord *coord, s16 *rooms, Mtxf *matrix1, struct coord *velocity, Mtxf *matrix2, struct prop *prop, struct coord *pos)
{
	struct prop *objprop = obj->prop;

	if (objprop) {
		propActivate(objprop);
		propEnable(objprop);
		mtx00015f04(obj->model->scale, matrix1);
		func0f06a580(obj, coord, matrix1, rooms);

		if (obj->type == OBJTYPE_WEAPON && ((struct weaponobj *) obj)->weaponnum == WEAPON_BOLT) {
			s32 beamnum = boltbeamFindByProp(objprop);

			if (beamnum == -1) {
				beamnum = boltbeamCreate(objprop);
			}

			if (beamnum != -1) {
				boltbeamSetHeadPos(beamnum, pos);
				boltbeamSetTailPos(beamnum, pos);
			}
		}

		func0f0685e4(objprop);

		if (obj->hidden & OBJHFLAG_PROJECTILE) {
			obj->projectile->flags |= PROJECTILEFLAG_AIRBORNE;
			obj->projectile->ownerprop = prop;

			projectileSetSticky(objprop);
			mtx4Copy(matrix2, (Mtxf *)&obj->projectile->mtx);

			obj->projectile->speed.x = velocity->x;
			obj->projectile->speed.y = velocity->y;
			obj->projectile->speed.z = velocity->z;
			obj->projectile->obj = obj;
			obj->projectile->unk0d8 = g_Vars.lvframenum;
		}
	}
}

void bgun0f09ed2c(struct defaultobj *obj, struct coord *newpos, Mtxf *arg2, struct coord *velocity, Mtxf *arg4)
{
	struct prop *objprop = obj->prop;
	struct coord pos;
	s16 rooms[8];

	if (objprop) {
		struct prop *playerprop = g_Vars.currentplayer->prop;

		pos.x = playerprop->pos.x;
		pos.y = playerprop->pos.y;
		pos.z = playerprop->pos.z;

		roomsCopy(playerprop->rooms, rooms);

		bgun0f09ebcc(obj, &pos, rooms, arg2, velocity, arg4, playerprop, newpos);

		if (obj->hidden & OBJHFLAG_PROJECTILE) {
			obj->projectile->flags |= PROJECTILEFLAG_LAUNCHING;

			obj->projectile->nextsteppos.x = newpos->x;
			obj->projectile->nextsteppos.y = newpos->y;
			obj->projectile->nextsteppos.z = newpos->z;
		}
	}
}

struct defaultobj *bgunCreateThrownProjectile2(struct chrdata *chr, struct gset *gset, struct coord *pos, s16 *rooms, Mtxf *arg4, struct coord *velocity)
{
	struct defaultobj *obj = NULL;
	struct weaponfunc *basefunc;
	struct weaponfunc_throw *func;
	struct weapon *weapon = weaponFindById(gset->weaponnum);
	struct weaponobj *weaponobj;
	struct autogunobj *autogun;
	Mtxf mtx;
	s32 playernum;

	if (weapon == NULL) {
		return false;
	}

	basefunc = weapon->functions[gset->weaponfunc];
	func = (struct weaponfunc_throw *) basefunc;

	if (func == NULL) {
		return false;
	}

	if (gset->weaponnum == WEAPON_COMBATKNIFE) {
		guRotateF(mtx.m, 90.0f / (RANDOMFRAC() + 12.1f),
				arg4->m[1][0], arg4->m[1][1], arg4->m[1][2]);
	} else {
		mtxLoadRandomRotation(&mtx);
	}

	if (gset->weaponnum == WEAPON_LAPTOPGUN) {
		autogun = laptopDeploy(func->projectilemodelnum, gset, chr);

		if (autogun != NULL) {
			obj = &autogun->base;
		}
	} else {
		weaponobj = weaponCreateProjectileFromGset(func->projectilemodelnum, gset, chr);

		if (weaponobj != NULL) {
			obj = &weaponobj->base;

			// Note this timer is converted to 240 time immediately below
			weaponobj->timer240 = func->activatetime60;

			if (weaponobj->timer240 >= 2) {
				weaponobj->timer240 = TICKS(weaponobj->timer240 * 4);
			}

			if (weaponobj->weaponnum == WEAPON_GRENADE || weaponobj->weaponnum == WEAPON_NBOMB) {
				propSetDangerous(weaponobj->base.prop);
			}

			if (func->projectilemodelnum == MODEL_CHRREMOTEMINE
					|| func->projectilemodelnum == MODEL_CHRTIMEDMINE
					|| func->projectilemodelnum == MODEL_CHRPROXIMITYMINE
					|| func->projectilemodelnum == MODEL_CHRECMMINE) {
				weaponobj->base.flags3 |= OBJFLAG3_00000008;
			}
		}
	}

	if (obj != NULL) {
		bgun0f09ebcc(obj, pos, rooms, arg4, velocity, &mtx, chr->prop, pos);

		obj->hidden &= 0x0fffffff;

		if (g_Vars.normmplayerisrunning) {
			playernum = mpPlayerGetIndex(chr);
		} else {
			playernum = playermgrGetPlayerNumByProp(chr->prop);
		}

		obj->hidden |= playernum << 28;

		if (obj->hidden & OBJHFLAG_PROJECTILE) {
			obj->projectile->flags |= PROJECTILEFLAG_00000002;
			obj->projectile->unk08c = 0.1f;
			obj->projectile->pickuptimer240 = TICKS(240);

			propsnd0f0939f8(NULL, obj->prop, SFX_THROW, -1,
					-1, 0, 0, 0, NULL, -1, NULL, -1, -1, -1, -1);
		}
	}

	return obj;
}

/**
 * handnum supports some unusual values:
 *
 * 0 = right hand
 * 1 = left hand
 * 2 = fumbling grenade from right hand (due to nbomb)
 * 3 = fumbling grenade from left hand (actually not possible)
 */
void bgunCreateThrownProjectile(s32 handnum, struct gset *gset)
{
	struct coord velocity = {0, 0, 0};
	Mtxf sp1f4;
	struct coord sp1e8;
	struct coord sp1dc;
	struct prop *playerprop = g_Vars.currentplayer->prop;
	struct coord *prevpos = &g_Vars.currentplayer->bondprevpos;
	struct coord *extrapos = &g_Vars.currentplayer->bondextrapos;
	Mtxf sp190;
	struct defaultobj *obj;
	struct weaponobj *weapon;
	struct coord muzzlepos;
	struct coord spawnpos;
	s16 spawnrooms[8];
	bool droppinggrenade = false;
	struct hand *hand;
	struct coord aimpos;
	struct coord sp140;
	f32 frac;
	f32 radians;
	Mtxf spf8;
	Mtxf spb8;
	Mtxf sp78;
	f32 sp68[4];
	f32 sp58[4];
	f32 sp48[4];
	struct trainingdata *data;
	u32 stack;

	if (handnum >= 2) {
		droppinggrenade = true;
		handnum -= 2;
	}

	hand = g_Vars.currentplayer->hands + handnum;

	muzzlepos.x = g_Vars.currentplayer->hands[handnum].muzzlepos.x;
	muzzlepos.y = g_Vars.currentplayer->hands[handnum].muzzlepos.y;
	muzzlepos.z = g_Vars.currentplayer->hands[handnum].muzzlepos.z;

	mtx4LoadIdentity(&sp1f4);

	if (gset->weaponnum == WEAPON_COMBATKNIFE) {
		mtx4LoadZRotation(4.711639f, &sp1f4);
		mtx4LoadXRotation(3.1410925f, &sp190);
		mtx4MultMtx4InPlace(&sp190, &sp1f4);
	}

	mtx4Copy(&g_Vars.currentplayer->hands[handnum].muzzlemat, &sp190);

	guNormalize(&sp190.m[0][0], &sp190.m[0][1], &sp190.m[0][2]);
	guNormalize(&sp190.m[1][0], &sp190.m[1][1], &sp190.m[1][2]);
	guNormalize(&sp190.m[2][0], &sp190.m[2][1], &sp190.m[2][2]);

	sp190.m[3][0] = 0.0f;
	sp190.m[3][1] = 0.0f;
	sp190.m[3][2] = 0.0f;

	mtx4MultMtx4InPlace(&sp190, &sp1f4);

	playerSetPerimEnabled(playerprop, false);

	if (cd0002deac(&playerprop->pos, playerprop->rooms, &muzzlepos, spawnrooms, CDTYPE_ALL) != CDRESULT_COLLISION) {
		spawnpos.x = muzzlepos.x;
		spawnpos.y = muzzlepos.y;
		spawnpos.z = muzzlepos.z;
	} else {
		spawnpos.x = playerprop->pos.x;
		spawnpos.y = playerprop->pos.y;
		spawnpos.z = playerprop->pos.z;

		roomsCopy(playerprop->rooms, spawnrooms);
	}

	playerSetPerimEnabled(playerprop, true);

	bgunCalculatePlayerShotSpread(&sp1e8, &sp1dc, handnum, true);
	mtx4RotateVecInPlace(camGetProjectionMtxF(), &sp1dc);

	if (droppinggrenade) {
		// Dropping a grenade because player is in an nbomb storm
		velocity.x = sp1dc.x * 1.6666666f;
		velocity.y = sp1dc.y * 1.6666666f;
		velocity.z = sp1dc.z * 1.6666666f;
	} else if (gsetHasFunctionFlags(&hand->gset, FUNCFLAG_CALCULATETRAJECTORY)) {
		// Calculate the velocity based on the trajectory to the aimpos
		func0f061d54(0, 0, 0);

		if (hand->hasdotinfo) {
			aimpos.x = hand->dotpos.x;
			aimpos.y = hand->dotpos.y;
			aimpos.z = hand->dotpos.z;

			chrCalculateTrajectory(&spawnpos, 21.666666f, &aimpos, &sp140);

			radians = acosf(sp1dc.f[0] * sp140.f[0] + sp1dc.f[1] * sp140.f[1] + sp1dc.f[2] * sp140.f[2]);

			// Check within 20 degrees
			if (radians > 0.34901026f || radians < -0.34901026f) {
				mtx00016b58(&spf8, 0, 0, 0, sp1dc.x, sp1dc.y, sp1dc.z, 0, 1, 0);
				mtx00016b58(&spb8, 0, 0, 0, sp140.x, sp140.y, sp140.z, 0, 1, 0);

				quaternion0f097044(&spf8, sp68);
				quaternion0f097044(&spb8, sp58);
				quaternion0f0976c0(sp68, sp58);

				frac = 0.34901025891304f / radians;

				if (frac < 0.0f) {
					frac = -frac;
				}

				quaternionSlerp(sp68, sp58, frac, sp48);
				quaternionToMtx(sp48, &sp78);

				sp1dc.x = -sp78.m[2][0];
				sp1dc.y = -sp78.m[2][1];
				sp1dc.z = -sp78.m[2][2];
			} else {
				sp1dc.x = sp140.x;
				sp1dc.y = sp140.y;
				sp1dc.z = sp140.z;
			}
		}

		velocity.x = sp1dc.x * 21.666666f;
		velocity.y = sp1dc.y * 21.666666f;
		velocity.z = sp1dc.z * 21.666666f;
	} else {
		// Simple velocity
		velocity.x = sp1dc.x * 16.666666f;
		velocity.y = sp1dc.y * 16.666666f;
		velocity.z = sp1dc.z * 16.666666f;

		if (gset->weaponnum == WEAPON_GRENADE || gset->weaponnum == WEAPON_NBOMB) {
			velocity.y += 1.6666666f;
		} else {
			velocity.y += 5.0f;
		}
	}

	if (gset->weaponnum == WEAPON_LAPTOPGUN) {
		bgunFreeWeapon(handnum);
	}

	// Add player movement to velocity
	if (g_Vars.lvupdate240 > 0) {
		velocity.x += (playerprop->pos.x - prevpos->x + extrapos->x) / g_Vars.lvupdate240freal;
		velocity.y += (playerprop->pos.y - prevpos->y + extrapos->y) / g_Vars.lvupdate240freal;
		velocity.z += (playerprop->pos.z - prevpos->z + extrapos->z) / g_Vars.lvupdate240freal;
	}

	obj = bgunCreateThrownProjectile2(g_Vars.currentplayer->prop->chr, gset, &spawnpos, spawnrooms, &sp1f4, &velocity);

	if (obj) {
		if (obj->type == OBJTYPE_WEAPON) {
			weapon = (struct weaponobj *)obj;

			if (gset->weaponnum == WEAPON_GRENADE && gset->weaponfunc == FUNC_PRIMARY) {
				if (weapon->timer240 < hand->primetimer60 * 4) {
					weapon->timer240 = 0;
				} else {
					weapon->timer240 -= hand->primetimer60 * 4;
				}

				weapon->gunfunc = gset->weaponfunc;
			} else if (gset->weaponnum == WEAPON_ECMMINE && g_Vars.stagenum == STAGE_CITRAINING) {
				data = dtGetData();

				if (data->intraining) {
					data->obj = obj;
				}
			}
		}

		if (obj->hidden & OBJHFLAG_PROJECTILE) {
			obj->projectile->flags |= PROJECTILEFLAG_LAUNCHING;
			obj->projectile->nextsteppos.x = muzzlepos.x;
			obj->projectile->nextsteppos.y = muzzlepos.y;
			obj->projectile->nextsteppos.z = muzzlepos.z;

			if (gset->weaponnum == WEAPON_GRENADE && gset->weaponfunc == FUNC_SECONDARY) {
				obj->projectile->unk08c = 1.0f;
			}

			if (gset->weaponnum == WEAPON_COMBATKNIFE) {
				// In theory, weapon can be uninitialised here,
				// but in practice it's always set.
				weapon->base.projectile->flags |= PROJECTILEFLAG_00000002;
				weapon->base.projectile->unk08c = 0.1f;
				weapon->base.projectile->pickuptimer240 = TICKS(240);
				weapon->base.hidden |= OBJHFLAG_00000020;
			}
		}
	}
}

void bgunUpdateHeldRocket(s32 handnum)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];
	struct defaultobj *obj = &hand->rocket->base;

	if (obj) {
		struct prop *objprop = obj->prop;
		Mtxf mtx;

		if (objprop) {
			struct prop *playerprop = g_Vars.currentplayer->prop;
			struct model *model = obj->model;

			if (!hand->firedrocket) {
				mtx4Copy(&hand->posmtx, &mtx);

				mtx.m[3][0] = 0;
				mtx.m[3][1] = 0;
				mtx.m[3][2] = 0;

				mtx00015f04(obj->model->scale, &mtx);
				func0f06a580(obj, &hand->muzzlepos, &mtx, playerprop->rooms);
				propDeregisterRooms(objprop);
			}

			model->matrices = gfxAllocate(model->filedata->nummatrices * sizeof(Mtxf));

			mtx4Copy(&hand->muzzlemat, &model->matrices[0]);
			model0001cb0c(model, model->filedata->rootnode);

			objprop->flags |= PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONTHISSCREENTHISTICK;
			objprop->z = -model->matrices[0].m[3][2];
		}
	}
}

void bgunCreateHeldRocket(s32 handnum, struct weaponfunc_shootprojectile *func)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];
	struct weaponobj *obj;

	if (hand->rocket == NULL) {
#if VERSION >= VERSION_NTSC_1_0
		hand->firedrocket = false;
#endif

		obj = weaponCreateProjectileFromWeaponNum(func->projectilemodelnum, WEAPON_ROCKET, g_Vars.currentplayer->prop->chr);

		if (obj != NULL) {
			hand->rocket = obj;
			hand->firedrocket = false;

			obj->timer240 = 1;
#if VERSION >= VERSION_NTSC_1_0
			obj->base.flags |= OBJFLAG_00800000;
#endif
			obj->base.flags2 |= OBJFLAG2_THROWTHROUGH;
		}
	}
}

void bgunFreeHeldRocket(s32 handnum)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];

	if (hand->rocket) {
		objFreePermanently(&hand->rocket->base, true);
		hand->rocket = NULL;
	}
}

void bgunCreateFiredProjectile(s32 handnum)
{
	struct weapon *weapondef;
	struct hand *hand;
	Mtxf sp270;
	struct coord sp264;
	f32 sp260;
	f32 sp25c;
	struct coord sp250;
	Mtxf sp210;
	struct coord sp204;
	struct coord sp1f8;
	struct prop *playerprop;
	struct coord *prevpos;
	struct coord *extrapos;
	struct coord spawnpos;
	struct weaponobj *weapon;
	struct weaponfunc *tmp;
	struct weaponfunc_shootprojectile *funcdef;
	struct coord aimpos;
	struct coord sp1bc;
	f32 frac;
	f32 radians;
	Mtxf sp174;
	Mtxf sp134;
	Mtxf spf4;
	f32 spe4[4];
	f32 spd4[4];
	f32 spc4[4];

	hand = g_Vars.currentplayer->hands + handnum;

	playerprop = g_Vars.currentplayer->prop;
	prevpos = &g_Vars.currentplayer->bondprevpos;
	extrapos = &g_Vars.currentplayer->bondextrapos;

	weapondef = weaponFindById(hand->gset.weaponnum);

	if (weapondef) {
		tmp = weapondef->functions[hand->gset.weaponfunc];

		if (tmp && tmp->type == INVENTORYFUNCTYPE_SHOOT_PROJECTILE) {
			funcdef = (struct weaponfunc_shootprojectile *)tmp;

			mtx4LoadIdentity(&sp270);
			bgunCalculatePlayerShotSpread(&sp204, &sp1f8, handnum, true);
			mtx4RotateVecInPlace(camGetProjectionMtxF(), &sp1f8);

			spawnpos.x = hand->muzzlepos.x;
			spawnpos.y = hand->muzzlepos.y;
			spawnpos.z = hand->muzzlepos.z;

			if (hand->gset.weaponnum == WEAPON_SLAYER && hand->gset.weaponfunc == FUNC_SECONDARY) {
				spawnpos.x += 50.0f * sp1f8.x;
				spawnpos.y += 50.0f * sp1f8.y;
				spawnpos.z += 50.0f * sp1f8.z;
			}

			sp260 = funcdef->unk4c * 1.6666666f / 60.0f;
			sp25c = funcdef->unk54 * 1.6666666f;

			if (gsetHasFunctionFlags(&hand->gset, FUNCFLAG_CALCULATETRAJECTORY)) {
				func0f061d54(0, 0, 0);

				if (hand->hasdotinfo) {
					aimpos.x = hand->dotpos.x;
					aimpos.y = hand->dotpos.y;
					aimpos.z = hand->dotpos.z;

					chrCalculateTrajectory(&spawnpos, sp25c, &aimpos, &sp1bc);

					radians = acosf(sp1f8.f[0] * sp1bc.f[0] + sp1f8.f[1] * sp1bc.f[1] + sp1f8.f[2] * sp1bc.f[2]);

					if (radians > 0.17450513f || radians < -0.17450513f) {
						mtx00016b58(&sp174, 0.0f, 0.0f, 0.0f, sp1f8.x, sp1f8.y, sp1f8.z, 0.0f, 1.0f, 0.0f);
						mtx00016b58(&sp134, 0.0f, 0.0f, 0.0f, sp1bc.x, sp1bc.y, sp1bc.z, 0.0f, 1.0f, 0.0f);

						quaternion0f097044(&sp174, spe4);
						quaternion0f097044(&sp134, spd4);
						quaternion0f0976c0(spe4, spd4);

						frac = 0.17450513f / radians;

						if (frac < 0.0f) {
							frac = -frac;
						}

						quaternionSlerp(spe4, spd4, frac, spc4);
						quaternionToMtx(spc4, &spf4);

						sp1f8.x = -spf4.m[2][0];
						sp1f8.y = -spf4.m[2][1];
						sp1f8.z = -spf4.m[2][2];
					} else {
						sp1f8.x = sp1bc.x;
						sp1f8.y = sp1bc.y;
						sp1f8.z = sp1bc.z;
					}
				}
			}

			sp250.x = sp1f8.x * sp260;
			sp250.y = sp1f8.y * sp260;
			sp250.z = sp1f8.z * sp260;

			sp264.x = sp250.f[0] * g_Vars.lvupdate240freal + sp1f8.f[0] * sp25c;
			sp264.y = sp250.f[1] * g_Vars.lvupdate240freal + sp1f8.f[1] * sp25c;
			sp264.z = sp250.f[2] * g_Vars.lvupdate240freal + sp1f8.f[2] * sp25c;

			if ((funcdef->base.base.flags & FUNCFLAG_FLYBYWIRE) == 0 && g_Vars.lvupdate240 > 0) {
				sp264.x += (playerprop->pos.x - prevpos->x + extrapos->x) / g_Vars.lvupdate240freal;
				sp264.y += (playerprop->pos.y - prevpos->y + extrapos->y) / g_Vars.lvupdate240freal;
				sp264.z += (playerprop->pos.z - prevpos->z + extrapos->z) / g_Vars.lvupdate240freal;
			}

			mtx4Copy(&g_Vars.currentplayer->hands[handnum].posmtx, &sp210);

			sp210.m[3][0] = 0.0f;
			sp210.m[3][1] = 0.0f;
			sp210.m[3][2] = 0.0f;

			if (hand->rocket) {
				hand->firedrocket = true;

				weapon = hand->rocket;
				weapon->base.flags2 &= ~OBJFLAG2_THROWTHROUGH;
#if VERSION >= VERSION_NTSC_1_0
				weapon->base.flags &= ~OBJFLAG_00800000;
#endif

				if (funcdef->base.base.flags & FUNCFLAG_HOMINGROCKET) {
					weapon->weaponnum = WEAPON_HOMINGROCKET;
				}
			} else if (hand->gset.weaponnum == WEAPON_ROCKETLAUNCHER || hand->gset.weaponnum == WEAPON_SLAYER) {
				u32 stack;
				s32 weaponnum = WEAPON_ROCKET;

				if (funcdef->base.base.flags & FUNCFLAG_HOMINGROCKET) {
					weaponnum = WEAPON_HOMINGROCKET;
				}

				weapon = weaponCreateProjectileFromWeaponNum(funcdef->projectilemodelnum, weaponnum, g_Vars.currentplayer->prop->chr);
			} else if (hand->gset.weaponnum == WEAPON_CROSSBOW) {
				weapon = weaponCreateProjectileFromWeaponNum(funcdef->projectilemodelnum, WEAPON_BOLT, g_Vars.currentplayer->prop->chr);

				if (weapon) {
					weapon->gunfunc = hand->gset.weaponfunc;
				}
			} else if (hand->gset.weaponnum == WEAPON_DEVASTATOR) {
				weapon = weaponCreateProjectileFromWeaponNum(funcdef->projectilemodelnum, WEAPON_GRENADEROUND, g_Vars.currentplayer->prop->chr);

				if (weapon) {
					weapon->gunfunc = hand->gset.weaponfunc;
				}
			} else if (hand->gset.weaponnum == WEAPON_SUPERDRAGON) {
				weapon = weaponCreateProjectileFromWeaponNum(funcdef->projectilemodelnum, WEAPON_GRENADEROUND, g_Vars.currentplayer->prop->chr);

				if (weapon) {
					weapon->gunfunc = FUNC_2;
				}
			} else {
				weapon = weaponCreateProjectileFromGset(funcdef->projectilemodelnum, &hand->gset, g_Vars.currentplayer->prop->chr);
			}

			if (weapon) {
#if VERSION >= VERSION_NTSC_1_0
				bool failed = false;
				Mtxf sp78;
				struct coord sp6c;
				struct coord sp60;

				if (weapon->base.model && weapon->base.model->filedata) {
					weapon->timer240 = funcdef->timer60;

					if (weapon->timer240 != -1) {
						weapon->timer240 = TICKS(weapon->timer240 * 4);
					}

					weapon->base.hidden &= 0x0fffffff;
					weapon->base.hidden |= g_Vars.currentplayernum << 28;

					bgun0f09ed2c(&weapon->base, &spawnpos, &sp210, &sp264, &sp270);

					if (weapon->base.hidden & OBJHFLAG_PROJECTILE) {
						if (funcdef->base.base.flags & FUNCFLAG_PROJECTILE_LIGHTWEIGHT) {
							weapon->base.projectile->flags |= PROJECTILEFLAG_LIGHTWEIGHT;
						} else if (funcdef->base.base.flags & FUNCFLAG_PROJECTILE_POWERED) {
							weapon->base.projectile->flags |= PROJECTILEFLAG_POWERED;
						}

						weapon->base.projectile->targetprop = g_Vars.currentplayer->trackedprops[0].prop;

						if (funcdef->scale != 1.0f) {
							weapon->base.model->scale *= funcdef->scale;

							mtx3ToMtx4(weapon->base.realrot, &sp78);
							mtx00015f04(funcdef->scale, &sp78);
							mtx4ToMtx3(&sp78, weapon->base.realrot);
						}

						weapon->base.projectile->powerlimit240 = TICKS(1200);
						weapon->base.projectile->unk0a8 = weapon->base.prop->pos.y;
						weapon->base.projectile->unk0ac = weapon->base.projectile->speed.y;
						weapon->base.projectile->unk010 = sp250.x;
						weapon->base.projectile->unk014 = sp250.y;
						weapon->base.projectile->unk018 = sp250.z;
						weapon->base.projectile->pickuptimer240 = TICKS(240);
						weapon->base.projectile->unk08c = funcdef->unk5c;
						weapon->base.projectile->unk098 = funcdef->unk50 * 1.6666666f;

						if (funcdef->soundnum > 0) {
							propsnd0f0939f8(NULL, weapon->base.prop, funcdef->soundnum, -1, -1, 0, 0, 0, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
						}

						if (funcdef->base.base.flags & FUNCFLAG_FLYBYWIRE) {
							playerLaunchSlayerRocket(weapon);
						}

						if (weapon->base.projectile->flags & PROJECTILEFLAG_LAUNCHING) {
							projectileLaunch(&weapon->base, weapon->base.projectile, &sp6c, &sp60);
						}
					} else {
						failed = true;
					}
				} else {
					failed = true;
				}

				if (failed) {
					weapon->timer240 = -1;

					if (weapon->base.prop) {
						propFree(weapon->base.prop);
					}

					if (weapon->base.model) {
						modelmgrFreeModel(weapon->base.model);
					}

					weapon->base.prop = NULL;
					weapon->base.model = NULL;
				}
#else
				// NTSC beta doesn't have any of the failure checks
				Mtxf sp78;
				struct coord sp6c;
				struct coord sp60;

				weapon->timer240 = funcdef->timer60;

				if (weapon->timer240 != -1) {
					weapon->timer240 = TICKS(weapon->timer240 * 4);
				}

				weapon->base.hidden &= 0x0fffffff;
				weapon->base.hidden |= g_Vars.currentplayernum << 28;

				bgun0f09ed2c(&weapon->base, &spawnpos, &sp210, &sp264, &sp270);

				if (weapon->base.hidden & OBJHFLAG_PROJECTILE) {
					if (funcdef->base.base.flags & FUNCFLAG_PROJECTILE_LIGHTWEIGHT) {
						weapon->base.projectile->flags |= PROJECTILEFLAG_LIGHTWEIGHT;
					} else if (funcdef->base.base.flags & FUNCFLAG_PROJECTILE_POWERED) {
						weapon->base.projectile->flags |= PROJECTILEFLAG_POWERED;
					}

					weapon->base.projectile->targetprop = g_Vars.currentplayer->trackedprops[0].prop;

					if (funcdef->scale != 1.0f) {
						weapon->base.model->scale *= funcdef->scale;

						mtx3ToMtx4(weapon->base.realrot, &sp78);
						mtx00015f04(funcdef->scale, &sp78);
						mtx4ToMtx3(&sp78, weapon->base.realrot);
					}

					weapon->base.projectile->powerlimit240 = TICKS(1200);
					weapon->base.projectile->unk0a8 = weapon->base.prop->pos.y;
					weapon->base.projectile->unk0ac = weapon->base.projectile->speed.y;
					weapon->base.projectile->unk010 = sp250.x;
					weapon->base.projectile->unk014 = sp250.y;
					weapon->base.projectile->unk018 = sp250.z;
					weapon->base.projectile->pickuptimer240 = TICKS(240);
					weapon->base.projectile->unk08c = funcdef->unk5c;
					weapon->base.projectile->unk098 = funcdef->unk50 * 1.6666666f;

					if (funcdef->soundnum > 0) {
						propsnd0f0939f8(NULL, weapon->base.prop, funcdef->soundnum, -1, -1, 0, 0, 0, 0, -1.0f, 0, -1, -1.0f, -1.0f, -1.0f);
					}

					if (funcdef->base.base.flags & FUNCFLAG_FLYBYWIRE) {
						playerLaunchSlayerRocket(weapon);
					}

					if (weapon->base.projectile->flags & PROJECTILEFLAG_LAUNCHING) {
						projectileLaunch(&weapon->base, weapon->base.projectile, &sp6c, &sp60);
					}
				}
#endif
			}
		}
	}
}

void bgunSwivel(f32 screenx, f32 screeny, f32 crossdamp, f32 aimdamp)
{
	f32 screenwidth = camGetScreenWidth();
	f32 screenheight = camGetScreenHeight();
	struct player *player = g_Vars.currentplayer;
	struct coord aimpos;
	s32 l;
	s32 h;
	f32 x[2];
	f32 y[2];
	bool ignore[2] = {false, false};
	s32 numframes;
	struct hand *hand;
	struct coord sp94;
	f32 sp8c[2];

	x[HAND_RIGHT] = x[HAND_LEFT] = screenx;
	y[HAND_RIGHT] = y[HAND_LEFT] = screeny;

	ignore[HAND_LEFT] = !player->hands[HAND_LEFT].inuse;
	ignore[HAND_RIGHT] = !player->hands[HAND_RIGHT].inuse;

	// If using right hand only and reloading,
	// recentre until the reload animation is almost complete
	if (!player->hands[HAND_LEFT].inuse
			&& player->hands[HAND_RIGHT].state == HANDSTATE_RELOAD
			&& player->hands[HAND_RIGHT].unk0ce8) {
		numframes = 25;

		if (player->hands[HAND_RIGHT].gset.weaponnum == WEAPON_CROSSBOW) {
			numframes = 5;
		}

		if ((s32)bgun0f09815c(&player->hands[HAND_RIGHT]) < modelGetNumAnimFrames(&player->hands[HAND_RIGHT].gunmodel) - numframes) {
			x[HAND_RIGHT] = 0.0f;
			y[HAND_RIGHT] = 0.0f;
			ignore[HAND_RIGHT] = true;
		}
	}

	if (player->hands[HAND_LEFT].gset.weaponnum == WEAPON_REMOTEMINE) {
		x[HAND_LEFT] = g_Vars.currentplayer->speedtheta * 0.3f + g_Vars.currentplayer->gunextraaimx;
		y[HAND_LEFT] = -g_Vars.currentplayer->speedverta * 0.1f + g_Vars.currentplayer->gunextraaimy;
		ignore[HAND_LEFT] = true;
	}

	if (player->hands[HAND_RIGHT].gset.weaponnum == WEAPON_UNARMED) {
		x[HAND_RIGHT] = g_Vars.currentplayer->speedtheta * 0.3f + g_Vars.currentplayer->gunextraaimx;
		y[HAND_RIGHT] = -g_Vars.currentplayer->speedverta * 0.1f + g_Vars.currentplayer->gunextraaimy;
		ignore[HAND_RIGHT] = true;
	}

	if (g_Vars.currentplayer->teleportstate != TELEPORTSTATE_INACTIVE) {
		ignore[HAND_LEFT] = ignore[HAND_RIGHT] = true;
	}

	// This loop only iterates once
	for (h = 0; h < 1; h++) {
		if (!ignore[h]) {
			hand = &player->hands[h];

			if (hand->hasdotinfo && !g_Vars.mplayerisrunning) {
				sp94.x = hand->dotpos.x;
				sp94.y = hand->dotpos.y;
				sp94.z = hand->dotpos.z;

				mtx4TransformVecInPlace(camGetWorldToScreenMtxf(), &sp94);

				if (!(sp94.z < 0.0000001f) || !(sp94.z > -0.0000001f)) {
					if (sp94.z > -6000.0f) {
						cam0f0b4d04(&sp94, sp8c);

						x[h] = sp8c[0];
						y[h] = sp8c[1];

						x[h] = 2.0f * (x[h] / viGetViewWidth()) - 1.0f;
						y[h] = 2.0f * (y[h] / viGetViewHeight()) - 1.0f;
					}
				}
			}
		}
	}

	player->oldcrosspos[0] = player->crosspos[0];
	player->oldcrosspos[1] = player->crosspos[1];

	if (crossdamp != player->guncrossdamp) {
		player->crosspossum[0] = player->crosspossum[0] * (1.0f - player->guncrossdamp) / (1.0f - crossdamp);
		player->crosspossum[1] = player->crosspossum[1] * (1.0f - player->guncrossdamp) / (1.0f - crossdamp);
		player->guncrossdamp = crossdamp;
	}

	if (aimdamp != player->gunaimdamp) {
		player->crosssum2[0] = player->crosssum2[0] * (1.0f - player->gunaimdamp) / (1.0f - aimdamp);
		player->crosssum2[1] = player->crosssum2[1] * (1.0f - player->gunaimdamp) / (1.0f - aimdamp);
		player->gunaimdamp = aimdamp;
	}

	for (l = 0; l < g_Vars.lvupdate240; l++) {
		player->crosspossum[0] = player->crosspossum[0] * crossdamp + screenx;
		player->crosspossum[1] = player->crosspossum[1] * crossdamp + screeny;

		for (h = 0; h < 2; h++) {
			hand = &player->hands[h];
			hand->guncrosspossum[0] = (PAL ? 0.913f : 0.9269697f) * hand->guncrosspossum[0] + x[h];
			hand->guncrosspossum[1] = (PAL ? 0.913f : 0.9269697f) * hand->guncrosspossum[1] + y[h];
		}
	}

	player->crosspos[0] = player->crosspossum[0] * (1.0f - crossdamp) * screenwidth * 0.5f + screenwidth * 0.5f;
	player->crosspos[1] = player->crosspossum[1] * (1.0f - crossdamp) * screenheight * 0.5f + screenheight * 0.5f;

	if (player->crosspos[0] < 3.0f) {
		player->crosspos[0] = 3.0f;
	} else if (player->crosspos[0] > screenwidth - 4.0f) {
		player->crosspos[0] = screenwidth - 4.0f;
	}

	if (player->crosspos[1] < 3.0f) {
		player->crosspos[1] = 3.0f;
	} else if (player->crosspos[1] > screenheight - 4.0f) {
		player->crosspos[1] = screenheight - 4.0f;
	}

	player->crosspos[0] += camGetScreenLeft();
	player->crosspos[1] += camGetScreenTop();

	for (h = 0; h < 2; h++) {
		player->hands[h].crosspos[0] = player->hands[h].guncrosspossum[0] * (PAL ? 0.08700001f : 0.07303029f) * screenwidth * 0.5f + screenwidth * 0.5f;
		player->hands[h].crosspos[1] = player->hands[h].guncrosspossum[1] * (PAL ? 0.08700001f : 0.07303029f) * screenheight * 0.5f + screenheight * 0.5f;

		if (player->hands[h].crosspos[0] < 3.0f) {
			player->hands[h].crosspos[0] = 3.0f;
		} else if (player->hands[h].crosspos[0] > screenwidth - 4.0f) {
			player->hands[h].crosspos[0] = screenwidth - 4.0f;
		}

		if (player->hands[h].crosspos[1] < 3.0f) {
			player->hands[h].crosspos[1] = 3.0f;
		} else if (player->hands[h].crosspos[1] > screenheight - 4.0f) {
			player->hands[h].crosspos[1] = screenheight - 4.0f;
		}

		player->hands[h].crosspos[0] += camGetScreenLeft();
		player->hands[h].crosspos[1] += camGetScreenTop();
	}

	for (l = 0; l < g_Vars.lvupdate240; l++) {
		player->crosssum2[0] = player->crosssum2[0] * aimdamp + screenx;
		player->crosssum2[1] = player->crosssum2[1] * aimdamp + screeny;
	}

	player->crosspos2[0] = player->crosssum2[0] * (1.0f - aimdamp) * screenwidth * 0.5f + screenwidth * 0.5f;
	player->crosspos2[1] = player->crosssum2[1] * (1.0f - aimdamp) * screenheight * 0.5f + screenheight * 0.5f;
	player->crosspos2[0] += camGetScreenLeft();
	player->crosspos2[1] += camGetScreenTop();

	cam0f0b4c3c(player->crosspos2, &aimpos, 1000);

	bgunSetAimPos(&aimpos);
}

/**
 * Swivel the gun towards the given screen coordinates, dampening the movement
 * speed as it reaches the target.
 *
 * This is used for auto aim, the CMP's follow lock-on, and general turning.
 */
void bgunSwivelWithDamp(f32 screenx, f32 screeny, f32 crossdamp)
{
	struct weapon *weapon = weaponFindById(bgunGetWeaponNum(HAND_RIGHT));
	f32 aimdamp = PAL ? weapon->eptr->unk10 : weapon->eptr->unk14;

	if (aimdamp < crossdamp) {
		aimdamp = crossdamp;
	}

	bgunSwivel(screenx, screeny, crossdamp, aimdamp);
}

/**
 * Swivel the gun towards the given screen coordinates without slowing the speed
 * speed as it reaches the target.
 *
 * This is used when manual aiming.
 */
void bgunSwivelWithoutDamp(f32 screenx, f32 screeny)
{
	struct weapon *weapon = weaponFindById(bgunGetWeaponNum(HAND_RIGHT));
	f32 aimdamp = PAL ? weapon->eptr->unk10 : weapon->eptr->unk14;

	bgunSwivel(screenx, screeny, PAL ? 0.935f : 0.945f, aimdamp);
}

void bgunGetCrossPos(f32 *x, f32 *y)
{
	struct player *player = g_Vars.currentplayer;

	*x = player->crosspos[0];
	*y = player->crosspos[1];
}

void bgun0f0a0c08(struct coord *arg0, struct coord *arg1)
{
	arg0->x = 0;
	arg0->y = 0;
	arg0->z = 0;

	cam0f0b4c3c(g_Vars.currentplayer->crosspos, arg1, 1);
}

void bgun0f0a0c44(s32 handnum, struct coord *arg1, struct coord *arg2)
{
	arg1->x = 0;
	arg1->y = 0;
	arg1->z = 0;

	cam0f0b4c3c(g_Vars.currentplayer->hands[handnum].crosspos, arg2, 1);
}

void bgunCalculatePlayerShotSpread(struct coord *arg0, struct coord *arg1, s32 handnum, bool dorandom)
{
	f32 crosspos[2];
	f32 spread = 0;
	f32 scaledspread;
	f32 randfactor;
	struct weaponfunc *func = currentPlayerGetWeaponFunction(handnum);
	struct player *player = g_Vars.currentplayer;

	if (func != NULL && (func->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		struct weaponfunc_shoot *shootfunc = (struct weaponfunc_shoot *) func;
		spread = shootfunc->spread;
	}

	// Unsure what this is
	if (weaponHasClassFlag(bgunGetWeaponNum2(handnum), WEAPONCLASSFLAG_00000004)
			&& player->hands[handnum].burstbullets == 1) {
		spread *= 0.25f;
	}

	// Decrease spread if double crouched
	if (bmoveGetCrouchPos() == CROUCHPOS_SQUAT) {
		spread *= 0.5f;
	}

	// Increase spread if dual wielding
	if (player->hands[HAND_LEFT].inuse) {
		spread *= 1.5f;
	}

	scaledspread = 120.0f * spread / viGetFovY();

	if (dorandom) {
		randfactor = (RANDOMFRAC() - 0.5f) * RANDOMFRAC();
	} else {
		randfactor = 0;
	}

	crosspos[0] = player->crosspos[0] + randfactor * scaledspread * camGetScreenWidth()
		/ (viGetHeight() * camGetPerspAspect());

	if (dorandom) {
		randfactor = (RANDOMFRAC() - 0.5f) * RANDOMFRAC();
	} else {
		randfactor = 0;
	}

	crosspos[1] = player->crosspos[1] + (randfactor * scaledspread * camGetScreenHeight())
		/ viGetHeight();

	arg0->x = 0;
	arg0->y = 0;
	arg0->z = 0;

	cam0f0b4c3c(crosspos, arg1, 1);
}

void bgunCalculateBotShotSpread(struct coord *arg0, s32 weaponnum, s32 funcnum, bool arg3, s32 crouchpos, bool dual)
{
	f32 spread = 0.0f;
	f32 radius;
	struct weapon *weapondef = weaponFindById(weaponnum);
	f32 x;
	f32 y;
	Mtxf mtx;
	struct coord sp48;
	u32 stack;

	if (weapondef) {
		struct weaponfunc *funcdef = weapondef->functions[funcnum];

		if (funcdef && (funcdef->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
			struct weaponfunc_shoot *shootfunc = (struct weaponfunc_shoot *)funcdef;
			spread = shootfunc->spread;
		}
	}

	if (arg3 && weaponHasClassFlag(weaponnum, WEAPONCLASSFLAG_00000004)) {
		spread *= 0.25f;
	}

	if (crouchpos == CROUCHPOS_SQUAT) {
		spread *= 0.5f;
	}

	if (dual) {
		spread *= 1.5f;
	}

	radius = 120.0f * spread / viGetFovY();
	x = (RANDOMFRAC() - 0.5f) * RANDOMFRAC() * radius;
	y = (RANDOMFRAC() - 0.5f) * RANDOMFRAC() * radius;

	sp48.x = g_Vars.currentplayer->c_scalex * x;
	sp48.y = g_Vars.currentplayer->c_scaley * y;
	sp48.z = -1.0f;

	guNormalize(&sp48.x, &sp48.y, &sp48.z);
	mtx00016b58(&mtx, 0.0f, 0.0f, 0.0f, arg0->x, arg0->y, arg0->z, 0.0f, -1.0f, 0.0f);
	mtx4RotateVec(&mtx, &sp48, arg0);
}

bool bgunGetLastShootInfo(struct coord *pos, struct coord *dir, s32 handnum)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];

	if (!hand->lastdirvalid) {
		return false;
	}

	pos->x = hand->lastshootpos.x;
	pos->y = hand->lastshootpos.y;
	pos->z = hand->lastshootpos.z;

	dir->x = hand->lastshootdir.x;
	dir->y = hand->lastshootdir.y;
	dir->z = hand->lastshootdir.z;

	return true;
}

void bgunSetLastShootInfo(struct coord *pos, struct coord *dir, s32 handnum)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];

	hand->lastdirvalid = true;

	hand->lastshootpos.x = pos->x;
	hand->lastshootpos.y = pos->y;
	hand->lastshootpos.z = pos->z;

	hand->lastshootdir.x = dir->x;
	hand->lastshootdir.y = dir->y;
	hand->lastshootdir.z = dir->z;
}

s32 bgunGetShotsToTake(s32 handnum)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];

	return hand->shotstotake;
}

void bgunFreeWeapon(s32 handnum)
{
	struct player *player = g_Vars.currentplayer;
	s32 i;

	if (player->hands[handnum].inuse) {
		for (i = 0; i < 2; i++) {
			if (player->gunctrl.ammotypes[i] >= 0) {
				s32 spaceinclip = player->hands[handnum].clipsizes[i] - player->hands[handnum].loadedammo[i];
				s32 index = bgunGetUnequippedReloadIndex(player->gunctrl.weaponnum);

				if (index != -1) {
#if VERSION >= VERSION_JPN_FINAL
					player->hands[handnum].gunroundsspent[index] = (spaceinclip << 8) + 0xff;
#elif VERSION >= VERSION_PAL_BETA
					player->hands[handnum].gunroundsspent[index] = spaceinclip * 213 + 212;
#else
					player->hands[handnum].gunroundsspent[index] = (spaceinclip << 8) | 0xff;
#endif
				}

				if (player->hands[handnum].loadedammo[i] > 0) {
					player->ammoheldarr[player->gunctrl.ammotypes[i]] += player->hands[handnum].loadedammo[i];
				}

				player->hands[handnum].loadedammo[i] = 0;
			}
		}
	}

	if (g_Vars.mplayerisrunning && (IS8MB() || PLAYERCOUNT() != 1)) {
		playermgrDeleteWeapon(handnum);
	}

	bgunFreeHeldRocket(handnum);
}

void bgunTickSwitch2(void)
{
	struct player *player = g_Vars.currentplayer;
	struct gunctrl *ctrl = &g_Vars.currentplayer->gunctrl;
	s32 i;

	if (ctrl->switchtoweaponnum >= 0) {
		if (bgunCanFreeWeapon(HAND_RIGHT) && bgunCanFreeWeapon(HAND_LEFT)) {
			s32 weaponnum = player->gunctrl.weaponnum;
			s32 previnuse = player->hands[HAND_LEFT].inuse;
			struct hand *lefthand;
			struct hand *righthand;

			if (currentPlayerGetDeviceState(ctrl->switchtoweaponnum) != DEVICESTATE_UNEQUIPPED) {
				ctrl->switchtoweaponnum = WEAPON_UNARMED;
			}

#if VERSION == VERSION_JPN_FINAL
			if (ctrl->switchtoweaponnum == WEAPON_COMBATKNIFE) {
				ctrl->switchtoweaponnum = WEAPON_UNARMED;
			}
#endif

			if (ctrl->dualwielding && !invHasDoubleWeaponIncAllGuns(ctrl->switchtoweaponnum, ctrl->switchtoweaponnum)) {
				ctrl->dualwielding = false;
			}

			func0f0d7364();

			bgunFreeWeapon(HAND_LEFT);
			bgunFreeWeapon(HAND_RIGHT);

			if (weaponnum == WEAPON_HORIZONSCANNER) {
				g_Vars.currentplayer->insightaimmode = false;
			}

			if (weaponnum == WEAPON_RCP120) {
				s32 amount = player->hands[HAND_RIGHT].matmot1;

				if (amount > player->ammoheldarr[ctrl->ammotypes[0]]) {
					amount = player->ammoheldarr[ctrl->ammotypes[0]];
				}

				player->ammoheldarr[ctrl->ammotypes[0]] -= amount;
			}

			if (weaponnum == WEAPON_HORIZONSCANNER) {
				g_Vars.currentplayer->zoomintimemax = 0;
				g_Vars.currentplayer->zoomintime = g_Vars.currentplayer->zoomintimemax;
				g_Vars.currentplayer->zoominfovynew = 60;
				g_Vars.currentplayer->zoominfovy = g_Vars.currentplayer->zoominfovynew;
			}

			lefthand = &player->hands[HAND_LEFT];
			righthand = &player->hands[HAND_RIGHT];

			if (ctrl->switchtoweaponnum == WEAPON_NONE) {
				lefthand->inuse = false;
				righthand->inuse = false;
				ctrl->weaponnum = WEAPON_NONE;
			} else {
				bgunSetGunMemWeapon(ctrl->switchtoweaponnum);
				ctrl->weaponnum = ctrl->switchtoweaponnum;
				lefthand->inuse = true;
				righthand->inuse = true;
			}

			if (ctrl->weaponnum == WEAPON_REMOTEMINE) {
				ctrl->dualwielding = true;
			}

			if (!ctrl->dualwielding) {
				lefthand->inuse = false;
			}

			if (weaponnum <= WEAPON_PSYCHOSISGUN && weaponnum >= WEAPON_UNARMED) {
				player->gunctrl.prevweaponnum = weaponnum;
			}

			if (previnuse) {
				player->gunctrl.unk1583_01 = true;
			} else {
				player->gunctrl.unk1583_01 = false;
			}

			g_Vars.currentplayer->gunctrl.invertgunfunc = false;
			g_Vars.currentplayer->usedowntime = -1;

			for (i = 0; i < 2; i++) {
				player->hands[i].unk0d0e_00 = 0;
				player->hands[i].unk0d0e_04 = 0;
				player->hands[i].unk0d0f_02 = false;
				player->hands[i].activatesecondary = false;

				player->hands[i].matmot1 = 0.0f;
				player->hands[i].matmot2 = 0.0f;
				player->hands[i].matmot3 = 0.0f;
				player->hands[i].angledamper = 0.0f;
				player->hands[i].gunsmokepoint = 0.0f;
				player->hands[i].burstbullets = 0;
				player->hands[i].loadslide = 0.0f;
				player->hands[i].allowshootframe = 0;
				player->hands[i].lastshootframe60 = 0;
				player->hands[i].gset.weaponfunc = FUNC_PRIMARY;
				player->hands[i].gset.weaponnum = ctrl->weaponnum;
				player->hands[i].gset.unk0639 = (ctrl->upgradewant >> (i * 4)) & 0xf;
				player->hands[i].gangstarot = 0.0f;

				bgun0f0abd30(i);

				animInit(&player->hands[i].anim);

				if (player->hands[i].audiohandle && sndGetState(player->hands[i].audiohandle) != AL_STOPPED) {
					audioStop(player->hands[i].audiohandle);
				}
			}

			invCalculateCurrentIndex();

			ctrl->switchtoweaponnum = -1;
			ctrl->fnfader = 0;

			if (ctrl->weaponnum == WEAPON_DISGUISE40 || ctrl->weaponnum == WEAPON_DISGUISE41) {
				struct chrdata *chr = player->prop->chr;

				sndStart(var80095200, SFX_DISGUISE_ON, 0, -1, -1, -1, -1, -1);

				g_Vars.currentplayer->disguised = true;

				chr->hidden |= CHRHFLAG_DISGUISED;

				if (g_Vars.stagenum == STAGE_RESCUE) {
					chr->hidden |= CHRHFLAG_UNTARGETABLE;
				}

				invRemoveItemByNum(ctrl->weaponnum);
				bgunCycleBack();
			}

			ctrl->curfnstr = 0;
			ctrl->fnstrtimer = 0;
			ctrl->unk1583_04 = false;
		}
	} else {
		if (((player->hands[HAND_LEFT].inuse && !player->gunctrl.dualwielding)
					|| (!player->hands[HAND_LEFT].inuse && player->gunctrl.dualwielding))
				&& bgunCanFreeWeapon(HAND_LEFT)) {
			bgunFreeWeapon(HAND_LEFT);
			player->hands[HAND_LEFT].inuse = player->gunctrl.dualwielding;
		}
	}
}

void bgunEquipWeapon(s32 weaponnum)
{
	struct player *player = g_Vars.currentplayer;

	if (player->gunctrl.weaponnum == weaponnum && player->gunctrl.switchtoweaponnum == -1) {
		return;
	}

	player->gunctrl.switchtoweaponnum = weaponnum;
	player->gunctrl.wantammo = false;
}

s32 bgunGetWeaponNum(s32 handnum)
{
	if (!g_Vars.currentplayer->hands[handnum].inuse) {
		return WEAPON_NONE;
	}

	return g_Vars.currentplayer->gunctrl.weaponnum;
}

s32 bgunGetWeaponNum2(s32 handnum)
{
	return bgunGetWeaponNum(handnum);
}

bool bgun0f0a1a10(s32 weaponnum)
{
	if (weaponHasFlag(weaponnum, WEAPONFLAG_00000400)
			&& (bgunGetAmmoTypeForWeapon(weaponnum, FUNC_PRIMARY) == 0 || bgunGetAmmoQtyForWeapon(weaponnum, FUNC_PRIMARY) > 0)) {
		return true;
	}

	return false;
}

s32 bgunGetSwitchToWeapon(s32 handnum)
{
	s32 weaponnum;

	if (g_Vars.currentplayer->gunctrl.switchtoweaponnum >= 0) {
		weaponnum = g_Vars.currentplayer->gunctrl.switchtoweaponnum;
	} else {
		weaponnum = g_Vars.currentplayer->gunctrl.weaponnum;
	}

	if (!g_Vars.currentplayer->gunctrl.dualwielding && handnum == HAND_LEFT) {
		weaponnum = WEAPON_NONE;
	}

	return weaponnum;
}

void bgunSwitchToPrevious(void)
{
	if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
		struct player *player = g_Vars.currentplayer;
		s32 dualweaponnum;

#if VERSION >= VERSION_NTSC_1_0
		if (invHasSingleWeaponIncAllGuns(player->gunctrl.prevweaponnum)) {
			bgunEquipWeapon2(HAND_RIGHT, player->gunctrl.prevweaponnum);

			dualweaponnum = invHasDoubleWeaponIncAllGuns(player->gunctrl.prevweaponnum, player->gunctrl.prevweaponnum)
				* player->gunctrl.prevweaponnum * player->gunctrl.unk1583_01;
			bgunEquipWeapon2(HAND_LEFT, dualweaponnum);
		} else {
			bgunAutoSwitchWeapon();
		}
#else
		bgunEquipWeapon2(HAND_RIGHT, player->gunctrl.prevweaponnum);
		bgunEquipWeapon2(HAND_LEFT, player->gunctrl.prevweaponnum * player->gunctrl.unk1583_01);
#endif
	}
}

void bgunCycleForward(void)
{
	s32 weaponnum1;
	s32 weaponnum2;
	struct player *player = g_Vars.currentplayer;

	if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
		weaponnum1 = bgunGetSwitchToWeapon(HAND_RIGHT);
		weaponnum2 = bgunGetSwitchToWeapon(HAND_LEFT);

		if (weaponnum1 > WEAPON_PSYCHOSISGUN || weaponnum2 > WEAPON_PSYCHOSISGUN) {
			weaponnum1 = player->gunctrl.prevweaponnum;
			weaponnum2 = player->gunctrl.prevweaponnum * player->gunctrl.unk1583_01;
		} else {
			invChooseCycleForwardWeapon(&weaponnum1, &weaponnum2, false);
		}

		if (weaponnum2 != weaponnum1) {
			player->gunctrl.dualwielding = false;
		} else {
			player->gunctrl.dualwielding = true;
		}

		bgunEquipWeapon(weaponnum1);
	}
}

void bgunCycleBack(void)
{
	s32 weaponnum1;
	s32 weaponnum2;
	struct player *player = g_Vars.currentplayer;

	if (g_Vars.tickmode != TICKMODE_CUTSCENE) {
		weaponnum1 = bgunGetSwitchToWeapon(HAND_RIGHT);
		weaponnum2 = bgunGetSwitchToWeapon(HAND_LEFT);

		if (weaponnum2 == WEAPON_REMOTEMINE) {
			weaponnum2 = WEAPON_NONE;
		}

		if (weaponnum1 > WEAPON_PSYCHOSISGUN || weaponnum2 > WEAPON_PSYCHOSISGUN) {
			weaponnum1 = player->gunctrl.prevweaponnum;
			weaponnum2 = player->gunctrl.prevweaponnum * player->gunctrl.unk1583_01;
		} else {
			invChooseCycleBackWeapon(&weaponnum1, &weaponnum2, false);
		}

		if (weaponnum2 == WEAPON_NONE) {
			player->gunctrl.dualwielding = false;
		} else {
			player->gunctrl.dualwielding = true;
		}

		bgunEquipWeapon(weaponnum1);
	}
}

/**
 * Return true if the player has ammo for the given weapon (for either function)
 * or if the weapon doesn't support ammo.
 *
 * Used by the active menu to colour the slots.
 */
bool bgunHasAmmoForWeapon(s32 weaponnum)
{
	bool ammodefexists = false;
	bool hasammo = false;
	struct weapon *weapon = weaponFindById(weaponnum);
	s32 i;

	if (weapon == NULL) {
		return true;
	}

	for (i = 0; i < 2; i++) {
		struct weaponfunc *func = weaponGetFunctionById(weaponnum, i);

		if (func && func->ammoindex >= 0) {
			struct inventory_ammo *ammo = weapon->ammos[func->ammoindex];

			if (ammo) {
				ammodefexists = true;

				if (bgunGetAmmoCount(ammo->type) > 0) {
					hasammo = true;
				}
			}
		}
	}

	if (!ammodefexists) {
		return true;
	}

	if (hasammo == true) {
		return true;
	}

	return false;
}

u8 g_AutoSwitchWeaponsPrimary[] = {
	WEAPON_RCP120,
	WEAPON_SUPERDRAGON,
	WEAPON_K7AVENGER,
	WEAPON_AR34,
	WEAPON_CALLISTO,
	WEAPON_LAPTOPGUN,
	WEAPON_DRAGON,
	WEAPON_CMP150,
	WEAPON_CYCLONE,
	WEAPON_FARSIGHT,
	WEAPON_SHOTGUN,
	WEAPON_REAPER,
	WEAPON_DY357LX,
	WEAPON_MAULER,
	WEAPON_DY357MAGNUM,
	WEAPON_MAGSEC4,
	WEAPON_PHOENIX,
	WEAPON_FALCON2_SCOPE,
	WEAPON_FALCON2,
	WEAPON_FALCON2_SILENCER,
	WEAPON_SNIPERRIFLE,
	WEAPON_CROSSBOW,
	WEAPON_TRANQUILIZER,
	WEAPON_LASER,
	WEAPON_SUPERDRAGON, // duplicate
	WEAPON_DEVASTATOR,
	WEAPON_ROCKETLAUNCHER,
	WEAPON_SLAYER,
	WEAPON_GRENADE,
	WEAPON_NBOMB,
	WEAPON_PROXIMITYMINE,
	WEAPON_TIMEDMINE,
	WEAPON_REMOTEMINE,
	WEAPON_COMBATKNIFE,
	WEAPON_UNARMED,
};

u8 g_AutoSwitchWeaponsSecondary[] = {
	WEAPON_REAPER,
	WEAPON_DY357LX,
	WEAPON_DY357MAGNUM,
	WEAPON_FALCON2_SCOPE,
	WEAPON_FALCON2,
	WEAPON_FALCON2_SILENCER,
	WEAPON_UNARMED,
};

u32 var800701ec = 0x00000000;
u32 var800701f0 = 0x00000000;
u32 var800701f4 = 0x00000000;
u32 var800701f8 = 0x00000000;
u32 var800701fc = 0x00000000;

struct guncmd var80070200[2] = {
	{ GUNCMD_PLAYANIMATION, 0, ANIM_0434, 10000 },
	{ GUNCMD_END },
};

#if MATCHING
GLOBAL_ASM(
glabel bgunAutoSwitchWeapon
/*  f0a1df4:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f0a1df8:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0a1dfc:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0a1e00:	8c6f0284 */ 	lw	$t7,0x284($v1)
/*  f0a1e04:	240effff */ 	addiu	$t6,$zero,-1
/*  f0a1e08:	8c7902ac */ 	lw	$t9,0x2ac($v1)
/*  f0a1e0c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f0a1e10:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f0a1e14:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f0a1e18:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f0a1e1c:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f0a1e20:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f0a1e24:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f0a1e28:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f0a1e2c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f0a1e30:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f0a1e34:	afae0050 */ 	sw	$t6,0x50($sp)
/*  f0a1e38:	afa00048 */ 	sw	$zero,0x48($sp)
/*  f0a1e3c:	81f81580 */ 	lb	$t8,0x1580($t7)
/*  f0a1e40:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0a1e44:	241effff */ 	addiu	$s8,$zero,-1
/*  f0a1e48:	0000a825 */ 	or	$s5,$zero,$zero
/*  f0a1e4c:	afa00040 */ 	sw	$zero,0x40($sp)
/*  f0a1e50:	13210083 */ 	beq	$t9,$at,.L0f0a2060
/*  f0a1e54:	afb80044 */ 	sw	$t8,0x44($sp)
/*  f0a1e58:	3c138007 */ 	lui	$s3,%hi(g_AutoSwitchWeaponsPrimary)
/*  f0a1e5c:	267301c0 */ 	addiu	$s3,$s3,%lo(g_AutoSwitchWeaponsPrimary)
/*  f0a1e60:	3c170010 */ 	lui	$s7,0x10
/*  f0a1e64:	2416ffff */ 	addiu	$s6,$zero,-1
/*  f0a1e68:	0000a025 */ 	or	$s4,$zero,$zero
.L0f0a1e6c:
/*  f0a1e6c:	0fc44727 */ 	jal	invHasSingleWeaponIncAllGuns
/*  f0a1e70:	92640000 */ 	lbu	$a0,0x0($s3)
/*  f0a1e74:	10400031 */ 	beqz	$v0,.L0f0a1f3c
/*  f0a1e78:	00000000 */ 	nop
/*  f0a1e7c:	92700000 */ 	lbu	$s0,0x0($s3)
/*  f0a1e80:	0fc2c3f4 */ 	jal	weaponFindById
/*  f0a1e84:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a1e88:	00409025 */ 	or	$s2,$v0,$zero
/*  f0a1e8c:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a1e90:	0fc2c401 */ 	jal	weaponGetFunctionById
/*  f0a1e94:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a1e98:	00408825 */ 	or	$s1,$v0,$zero
/*  f0a1e9c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a1ea0:	0fc2642c */ 	jal	bgun0f0990b0
/*  f0a1ea4:	02402825 */ 	or	$a1,$s2,$zero
/*  f0a1ea8:	14400006 */ 	bnez	$v0,.L0f0a1ec4
/*  f0a1eac:	24010012 */ 	addiu	$at,$zero,0x12
/*  f0a1eb0:	8e280010 */ 	lw	$t0,0x10($s1)
/*  f0a1eb4:	01174824 */ 	and	$t1,$t0,$s7
/*  f0a1eb8:	15200002 */ 	bnez	$t1,.L0f0a1ec4
/*  f0a1ebc:	00000000 */ 	nop
/*  f0a1ec0:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f0a1ec4:
/*  f0a1ec4:	16010005 */ 	bne	$s0,$at,.L0f0a1edc
/*  f0a1ec8:	02002025 */ 	or	$a0,$s0,$zero
/*  f0a1ecc:	16a00003 */ 	bnez	$s5,.L0f0a1edc
/*  f0a1ed0:	00000000 */ 	nop
/*  f0a1ed4:	1000000e */ 	b	.L0f0a1f10
/*  f0a1ed8:	26b50001 */ 	addiu	$s5,$s5,0x1
.L0f0a1edc:
/*  f0a1edc:	0fc2c401 */ 	jal	weaponGetFunctionById
/*  f0a1ee0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0a1ee4:	00408825 */ 	or	$s1,$v0,$zero
/*  f0a1ee8:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a1eec:	0fc2642c */ 	jal	bgun0f0990b0
/*  f0a1ef0:	02402825 */ 	or	$a1,$s2,$zero
/*  f0a1ef4:	54400007 */ 	bnezl	$v0,.L0f0a1f14
/*  f0a1ef8:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f0a1efc:	8e2a0010 */ 	lw	$t2,0x10($s1)
/*  f0a1f00:	01575824 */ 	and	$t3,$t2,$s7
/*  f0a1f04:	55600003 */ 	bnezl	$t3,.L0f0a1f14
/*  f0a1f08:	8fac0044 */ 	lw	$t4,0x44($sp)
/*  f0a1f0c:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f0a1f10:
/*  f0a1f10:	8fac0044 */ 	lw	$t4,0x44($sp)
.L0f0a1f14:
/*  f0a1f14:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0a1f18:	160c0003 */ 	bne	$s0,$t4,.L0f0a1f28
/*  f0a1f1c:	00000000 */ 	nop
/*  f0a1f20:	10000006 */ 	b	.L0f0a1f3c
/*  f0a1f24:	afad0048 */ 	sw	$t5,0x48($sp)
.L0f0a1f28:
/*  f0a1f28:	12800004 */ 	beqz	$s4,.L0f0a1f3c
/*  f0a1f2c:	8fae0050 */ 	lw	$t6,0x50($sp)
/*  f0a1f30:	15d60002 */ 	bne	$t6,$s6,.L0f0a1f3c
/*  f0a1f34:	0200f025 */ 	or	$s8,$s0,$zero
/*  f0a1f38:	afb00050 */ 	sw	$s0,0x50($sp)
.L0f0a1f3c:
/*  f0a1f3c:	3c0f8007 */ 	lui	$t7,%hi(g_AutoSwitchWeaponsPrimary+0x23)
/*  f0a1f40:	25ef01e3 */ 	addiu	$t7,$t7,%lo(g_AutoSwitchWeaponsPrimary+0x23)
/*  f0a1f44:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f0a1f48:	026f082b */ 	sltu	$at,$s3,$t7
/*  f0a1f4c:	50200007 */ 	beqzl	$at,.L0f0a1f6c
/*  f0a1f50:	8fb90048 */ 	lw	$t9,0x48($sp)
/*  f0a1f54:	53d6ffc5 */ 	beql	$s8,$s6,.L0f0a1e6c
/*  f0a1f58:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0a1f5c:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f0a1f60:	5300ffc2 */ 	beqzl	$t8,.L0f0a1e6c
/*  f0a1f64:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0a1f68:	8fb90048 */ 	lw	$t9,0x48($sp)
.L0f0a1f6c:
/*  f0a1f6c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a1f70:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0a1f74:	17200002 */ 	bnez	$t9,.L0f0a1f80
/*  f0a1f78:	02c09025 */ 	or	$s2,$s6,$zero
/*  f0a1f7c:	8fbe0050 */ 	lw	$s8,0x50($sp)
.L0f0a1f80:
/*  f0a1f80:	17d60002 */ 	bne	$s8,$s6,.L0f0a1f8c
/*  f0a1f84:	3c108007 */ 	lui	$s0,%hi(g_AutoSwitchWeaponsSecondary)
/*  f0a1f88:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f0a1f8c:
/*  f0a1f8c:	17c10018 */ 	bne	$s8,$at,.L0f0a1ff0
/*  f0a1f90:	261001e4 */ 	addiu	$s0,$s0,%lo(g_AutoSwitchWeaponsSecondary)
/*  f0a1f94:	3c138007 */ 	lui	$s3,%hi(g_AutoSwitchWeaponsSecondary+0x7)
/*  f0a1f98:	267301eb */ 	addiu	$s3,$s3,%lo(g_AutoSwitchWeaponsSecondary+0x7)
/*  f0a1f9c:	92110000 */ 	lbu	$s1,0x0($s0)
.L0f0a1fa0:
/*  f0a1fa0:	0fc44727 */ 	jal	invHasSingleWeaponIncAllGuns
/*  f0a1fa4:	02202025 */ 	or	$a0,$s1,$zero
/*  f0a1fa8:	10400008 */ 	beqz	$v0,.L0f0a1fcc
/*  f0a1fac:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0a1fb0:	8fa80044 */ 	lw	$t0,0x44($sp)
/*  f0a1fb4:	16280002 */ 	bne	$s1,$t0,.L0f0a1fc0
/*  f0a1fb8:	00000000 */ 	nop
/*  f0a1fbc:	24140001 */ 	addiu	$s4,$zero,0x1
.L0f0a1fc0:
/*  f0a1fc0:	16560002 */ 	bne	$s2,$s6,.L0f0a1fcc
/*  f0a1fc4:	00000000 */ 	nop
/*  f0a1fc8:	02209025 */ 	or	$s2,$s1,$zero
.L0f0a1fcc:
/*  f0a1fcc:	5613fff4 */ 	bnel	$s0,$s3,.L0f0a1fa0
/*  f0a1fd0:	92110000 */ 	lbu	$s1,0x0($s0)
/*  f0a1fd4:	16560002 */ 	bne	$s2,$s6,.L0f0a1fe0
/*  f0a1fd8:	0240f025 */ 	or	$s8,$s2,$zero
/*  f0a1fdc:	241e0001 */ 	addiu	$s8,$zero,0x1
.L0f0a1fe0:
/*  f0a1fe0:	12800002 */ 	beqz	$s4,.L0f0a1fec
/*  f0a1fe4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0a1fe8:	241effff */ 	addiu	$s8,$zero,-1
.L0f0a1fec:
/*  f0a1fec:	afa90040 */ 	sw	$t1,0x40($sp)
.L0f0a1ff0:
/*  f0a1ff0:	07c0001b */ 	bltz	$s8,.L0f0a2060
/*  f0a1ff4:	8faa0044 */ 	lw	$t2,0x44($sp)
/*  f0a1ff8:	13ca0019 */ 	beq	$s8,$t2,.L0f0a2060
/*  f0a1ffc:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0a2000:	0fc4473e */ 	jal	invHasDoubleWeaponIncAllGuns
/*  f0a2004:	03c02825 */ 	or	$a1,$s8,$zero
/*  f0a2008:	10400006 */ 	beqz	$v0,.L0f0a2024
/*  f0a200c:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0a2010:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0a2014:	904c1583 */ 	lbu	$t4,0x1583($v0)
/*  f0a2018:	358d0080 */ 	ori	$t5,$t4,0x80
/*  f0a201c:	10000006 */ 	b	.L0f0a2038
/*  f0a2020:	a04d1583 */ 	sb	$t5,0x1583($v0)
.L0f0a2024:
/*  f0a2024:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0a2028:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0a202c:	904e1583 */ 	lbu	$t6,0x1583($v0)
/*  f0a2030:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f0a2034:	a04f1583 */ 	sb	$t7,0x1583($v0)
.L0f0a2038:
/*  f0a2038:	0fc2865b */ 	jal	bgunEquipWeapon
/*  f0a203c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f0a2040:	8fb80040 */ 	lw	$t8,0x40($sp)
/*  f0a2044:	3c02800a */ 	lui	$v0,%hi(g_Vars+0x284)
/*  f0a2048:	53000006 */ 	beqzl	$t8,.L0f0a2064
/*  f0a204c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f0a2050:	8c42a244 */ 	lw	$v0,%lo(g_Vars+0x284)($v0)
/*  f0a2054:	90481583 */ 	lbu	$t0,0x1583($v0)
/*  f0a2058:	35090004 */ 	ori	$t1,$t0,0x4
/*  f0a205c:	a0491583 */ 	sb	$t1,0x1583($v0)
.L0f0a2060:
/*  f0a2060:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f0a2064:
/*  f0a2064:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f0a2068:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f0a206c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f0a2070:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f0a2074:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f0a2078:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f0a207c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f0a2080:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f0a2084:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f0a2088:	03e00008 */ 	jr	$ra
/*  f0a208c:	27bd0068 */ 	addiu	$sp,$sp,0x68
);
#else
/**
 * Automatically choose and equip a new weapon after trying to fire a weapon
 * which is out of ammo.
 *
 * The weapon preference order is stored in two arrays; one for weapons which
 * should have their primary functions considered and which require ammo, and
 * another for weapons which should have their secondary functions considered
 * and don't require ammo for those functions. The second is only used if no
 * weapons are usable from the primary array.
 *
 * For the primary array, the weapon must not be out of ammo and must have a
 * certain flag. If the player's current weapon is not in the primary array then
 * the first available primary will be selected. If the player's current weapon
 * is in the primary array then the last available weapon earlier than their
 * current weapon will be selected. If there are no weapons earlier than their
 * current weapon then the first weapon after their current weapon is selected.
 *
 * In the primary array, the SuperDragon is a special case. It is prioritised
 * when the player's current weapon is not in the array, but otherwise has a
 * fairly low priority. The reasons for this are unknown.
 *
 * For the secondary array, the player's current weapon must not be in the
 * array. The first available weapon is selected. The player's "wantammo" flag
 * will be set which will force the weapon onto the second function.
 */
// Mismatch: First loop should store pointer to current item in s3 and do an
// address comparison for the end, but the below stores index in s4 and does an
// integer comparison. Variable refcounts affects this so might be related.
void bgunAutoSwitchWeapon(void)
{
	s32 i;
	bool foundcurrent2;
	s32 firstweaponnum2;
	bool usable;
	s32 firstweaponnum = -1; // 50
	s32 newweaponnum = -1;
	bool foundcurrent = false; // 48
	s32 curweaponnum = g_Vars.currentplayer->gunctrl.weaponnum; // 44
	s32 foundsuperdragon = 0;
	s32 wantammo = false; // 40
	s32 weaponnum;
	struct weapon *weapon;
	struct weaponfunc *func;
	s32 weaponnum2;

	if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
		return;
	}

	// Loop through g_AutoSwitchWeaponsPrimary, checking which weapons the
	// player has which are usable. Stop when both any usable weapon is found
	// and when the player's current weapon is found. Note the first and last
	// usable weapons.
	for (i = 0; i < ARRAYCOUNT(g_AutoSwitchWeaponsPrimary) && (newweaponnum == -1 || !foundcurrent); i++) {
		usable = false;

		if (invHasSingleWeaponIncAllGuns(g_AutoSwitchWeaponsPrimary[i])) {
			weaponnum = g_AutoSwitchWeaponsPrimary[i];
			weapon = weaponFindById(weaponnum);
			func = weaponGetFunctionById(weaponnum, FUNC_PRIMARY);

			if (!bgun0f0990b0(func, weapon) && (func->flags & FUNCFLAG_AUTOSWITCHUNSELECTABLE) == 0) {
				usable = true;
			}

			if (weaponnum == WEAPON_SUPERDRAGON && !foundsuperdragon) {
				foundsuperdragon++;
			} else {
				func = weaponGetFunctionById(weaponnum, FUNC_SECONDARY);

				if (!bgun0f0990b0(func, weapon) && (func->flags & FUNCFLAG_AUTOSWITCHUNSELECTABLE) == 0) {
					usable = true;
				}
			}

			if (weaponnum == curweaponnum) {
				foundcurrent = true;
			} else if (usable) {
				newweaponnum = weaponnum;

				if (firstweaponnum == -1) {
					firstweaponnum = weaponnum;
				}
			}
		}
	}

	foundcurrent2 = false;
	firstweaponnum2 = -1;

	if (!foundcurrent) {
		newweaponnum = firstweaponnum;
	}

	if (newweaponnum == -1) {
		newweaponnum = WEAPON_UNARMED;
	}

	if (newweaponnum == WEAPON_UNARMED) {
		// No usable weapon was found in the primary array,
		// so search the secondary array.
		for (i = 0; i < ARRAYCOUNT(g_AutoSwitchWeaponsSecondary); i++) {
			weaponnum2 = g_AutoSwitchWeaponsSecondary[i];

			if (invHasSingleWeaponIncAllGuns(weaponnum2)) {
				if (weaponnum2 == curweaponnum) {
					foundcurrent2 = true;
				}

				if (firstweaponnum2 == -1) {
					firstweaponnum2 = weaponnum2;
				}
			}
		}

		newweaponnum = firstweaponnum2;

		if (newweaponnum == -1) {
			newweaponnum = WEAPON_UNARMED;
		}

		if (foundcurrent2) {
			newweaponnum = -1;
		}

		wantammo = true;
	}

	// Switch to newweaponnum
	if (newweaponnum >= 0 && newweaponnum != curweaponnum) {
		if (invHasDoubleWeaponIncAllGuns(newweaponnum, newweaponnum)) {
			g_Vars.currentplayer->gunctrl.dualwielding = true;
		} else {
			g_Vars.currentplayer->gunctrl.dualwielding = false;
		}

		bgunEquipWeapon(newweaponnum);

		if (wantammo) {
			g_Vars.currentplayer->gunctrl.wantammo = true;
		}
	}
}
#endif

void bgunEquipWeapon2(s32 handnum, s32 weaponnum)
{
	if (handnum == HAND_LEFT) {
		if (weaponnum == WEAPON_NONE) {
			g_Vars.currentplayer->gunctrl.dualwielding = false;
		} else {
			g_Vars.currentplayer->gunctrl.dualwielding = true;
		}
	} else {
		if (weaponnum > WEAPON_SUICIDEPILL) {
			weaponnum = WEAPON_UNARMED;
		}

		bgunEquipWeapon(weaponnum);
	}
}

s32 bgunIsFiring(s32 handnum)
{
	return g_Vars.currentplayer->hands[handnum].firing;
}

s32 bgunGetAttackType(s32 handnum)
{
	return g_Vars.currentplayer->hands[handnum].attacktype;
}

char *bgunGetName(s32 weaponnum)
{
	struct weapon *weapon = g_Weapons[weaponnum];

	if (weapon) {
		return langGet(weapon->name);
	}

	return "** error\n";
}

u16 bgunGetNameId(s32 weaponnum)
{
	struct weapon *weapon = g_Weapons[weaponnum];

	if (weapon) {
		return weapon->name;
	}

	return 0;
}

char *bgunGetShortName(s32 weaponnum)
{
	struct weapon *weapon = g_Weapons[weaponnum];

	if (weapon) {
		return langGet(weapon->shortname);
	}

	return "** error\n";
}

const char var7f1ac170[] = "wantedfn %d tiggle %d\n";

void bgunReloadIfPossible(s32 handnum)
{
	struct player *player = g_Vars.currentplayer;

	if (bgunGetAmmoTypeForWeapon(bgunGetWeaponNum(handnum), FUNC_PRIMARY)
			&& player->hands[handnum].modenext == HANDMODE_NONE) {
		player->hands[handnum].modenext = HANDMODE_RELOAD;
	}
}

void bgunSetAdjustPos(f32 angle)
{
	struct player *player = g_Vars.currentplayer;

	player->hands[0].adjustpos.z = (1 - cosf(angle)) * 5;
	player->hands[1].adjustpos.z = (1 - cosf(angle)) * 5;
}

void bgunStartSlide(s32 handnum)
{
	g_Vars.currentplayer->hands[handnum].slideinc = true;
}

/**
 * Update the slide on weapons which have them (eg. Falcon 2).
 *
 * The slide moves back and then forward when firing. If the gun no longer has
 * any ammo loaded in it, the slide moves back and remains in the back position.
 */
void bgunUpdateSlide(s32 handnum)
{
	f32 slidemax = 0.0f;
	struct weaponfunc *funcdef = currentPlayerGetWeaponFunction(handnum);
	struct player *player = g_Vars.currentplayer;

	if (funcdef && ((funcdef->type & 0xff) == INVENTORYFUNCTYPE_SHOOT)) {
		struct weaponfunc_shoot *shootfunc = (struct weaponfunc_shoot *)funcdef;
		slidemax = shootfunc->slidemax;
	}

	if (player->hands[handnum].slideinc) {
		// Slide is moving backwards
		if (player->hands[handnum].slidetrans < slidemax) {
			player->hands[handnum].slidetrans += slidemax * 0.25f * g_Vars.lvupdate240freal;
		}

		if (player->hands[handnum].slidetrans >= slidemax) {
			player->hands[handnum].slidetrans = slidemax;
			player->hands[handnum].slideinc = false;
		}
	} else if (player->hands[handnum].loadedammo[FUNC_PRIMARY] > 0) {
		if (bgun0f098a44(&player->hands[handnum], 3)) {
			// Slide is moving forwards
			if (player->hands[handnum].slidetrans > 0.0f) {
				player->hands[handnum].slidetrans -= slidemax * 0.16666667f * g_Vars.lvupdate240freal;
			}

			if (player->hands[handnum].slidetrans < 0.0f) {
				player->hands[handnum].slidetrans = 0.0f;
			}
		}
	}
}

f32 bgun0f0a2498(f32 arg0, f32 arg1, f32 arg2, f32 arg3)
{
	f32 a = arg0 - arg2;

	return asinf(a / sqrtf(a * a + (arg1 - arg3) * (arg1 - arg3)));
}

void bgun0f0a24f0(struct coord *arg0, s32 handnum)
{
	struct coord b;
	struct coord a;

	bgun0f0a0c44(handnum, &a, &b);

	b.x *= 1000;
	b.y *= 1000;
	b.z *= 1000;

	arg0->x = b.x;
	arg0->y = b.y;
	arg0->z = b.z;
}

/**
 * This function is a callback that is passed to model code.
 */
void bgun0f0a256c(s32 mtxindex, Mtxf *mtx)
{
	Mtxf sp78;
	Mtxf sp38;
	struct coord rot;

	if (mtxindex == var8009d148) {
		if (var8009d144->unk0d0e_00 == 1) {
			var8009d144->unk0d14 = mtx->m[3][0];
			var8009d144->unk0d18 = mtx->m[3][1];
			var8009d144->unk0d1c = mtx->m[3][2];

			var8009d144->unk0d2c[0][0] = mtx->m[0][0];
			var8009d144->unk0d2c[0][1] = mtx->m[0][1];
			var8009d144->unk0d2c[0][2] = mtx->m[0][2];
			var8009d144->unk0d2c[1][0] = mtx->m[1][0];
			var8009d144->unk0d2c[1][1] = mtx->m[1][1];
			var8009d144->unk0d2c[1][2] = mtx->m[1][2];
			var8009d144->unk0d2c[2][0] = mtx->m[2][0];
			var8009d144->unk0d2c[2][1] = mtx->m[2][1];
			var8009d144->unk0d2c[2][2] = mtx->m[2][2];
		} else if (var8009d144->unk0d0e_00 >= 2) {
			mtx->m[3][0] = var8009d144->unk0d14;
			mtx->m[3][1] = var8009d144->unk0d18;
			mtx->m[3][2] = var8009d144->unk0d1c;

			mtx->m[0][0] = var8009d144->unk0d2c[0][0];
			mtx->m[0][1] = var8009d144->unk0d2c[0][1];
			mtx->m[0][2] = var8009d144->unk0d2c[0][2];
			mtx->m[1][0] = var8009d144->unk0d2c[1][0];
			mtx->m[1][1] = var8009d144->unk0d2c[1][1];
			mtx->m[1][2] = var8009d144->unk0d2c[1][2];
			mtx->m[2][0] = var8009d144->unk0d2c[2][0];
			mtx->m[2][1] = var8009d144->unk0d2c[2][1];
			mtx->m[2][2] = var8009d144->unk0d2c[2][2];
		}
	}

	if (mtxindex == var8009d0dc) {
		rot.x = 0.0f;
		rot.y = 0.0f;
		rot.z = var8009d140;

		mtx4LoadIdentity(&sp78);
		mtx4LoadRotation(&rot, &sp78);
		mtx4MultMtx4(mtx, &sp78, &sp38);
		mtx4Copy(&sp38, mtx);
	}

	if (mtxindex == var8009d0f0[0] || mtxindex == var8009d0f0[1] || mtxindex == var8009d0f0[2]) {
		rot.x = 0.0f;
		rot.y = 0.0f;
		rot.z = 2.0f * -var8009d140;

		mtx4LoadIdentity(&sp78);
		mtx4LoadRotation(&rot, &sp78);
		mtx4MultMtx4(mtx, &sp78, &sp38);
		mtx4Copy(&sp38, mtx);
	}
}

bool bgun0f0a27c8(void)
{
	struct hand *hand;
	struct weaponfunc *func;

	hand = &g_Vars.currentplayer->hands[HAND_RIGHT];
	func = gsetGetWeaponFunction2(&hand->gset);

	if (func
			&& (func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE
			&& hand->state == HANDSTATE_ATTACK
			&& hand->unk0ce8 != NULL
			&& hand->animmode == HANDANIMMODE_BUSY
			&& !bgun0f098a44(hand, 2)) {
		return true;
	}

	hand = &g_Vars.currentplayer->hands[HAND_LEFT];

	if (hand->inuse) {
		func = gsetGetWeaponFunction2(&hand->gset);

		if (func
				&& (func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE
				&& hand->state == HANDSTATE_ATTACK
				&& hand->unk0ce8 != NULL
				&& hand->animmode == HANDANIMMODE_BUSY
				&& !bgun0f098a44(hand, 2)) {
			return true;
		}
	}

	return false;
}

/**
 * This function is the same as above but it doesn't call bgun0f098a44().
 *
 * This function is unused.
 */
bool bgun0f0a28d8(void)
{
	struct hand *hand;
	struct weaponfunc *func;

	hand = &g_Vars.currentplayer->hands[HAND_RIGHT];
	func = gsetGetWeaponFunction2(&hand->gset);

	if (func
			&& (func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE
			&& hand->state == HANDSTATE_ATTACK
			&& hand->unk0ce8 != NULL
			&& hand->animmode == HANDANIMMODE_BUSY) {
		return true;
	}

	hand = &g_Vars.currentplayer->hands[HAND_LEFT];

	if (hand->inuse) {
		func = gsetGetWeaponFunction2(&hand->gset);

		if (func
				&& (func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE
				&& hand->state == HANDSTATE_ATTACK
				&& hand->unk0ce8 != NULL
				&& hand->animmode == HANDANIMMODE_BUSY) {
			return true;
		}
	}

	return false;
}

void bgunHandlePlayerDead(void)
{
	struct player *player = g_Vars.currentplayer;
	s32 i;

	if (player->gunctrl.weaponnum != WEAPON_NONE && player->gunctrl.switchtoweaponnum != WEAPON_NONE) {
		if (player->hands[HAND_LEFT].inuse) {
			player->hands[HAND_LEFT].unk0d0e_00 = 1;
			player->hands[HAND_LEFT].unk0d0e_04 = 0;
		}

		if (player->hands[HAND_RIGHT].inuse) {
			player->hands[HAND_RIGHT].unk0d0e_00 = 1;
			player->hands[HAND_RIGHT].unk0d0e_04 = 0;
		}

		for (i = 0; i < 2; i++) {
			player->hands[i].matmot1 = 0;
			player->hands[i].matmot2 = 0;
			player->hands[i].matmot3 = 0;

			bgunSetState(i, HANDSTATE_IDLE);
		}

		bgunEquipWeapon2(HAND_LEFT, WEAPON_NONE);
		bgunEquipWeapon2(HAND_RIGHT, WEAPON_NONE);
	}
}

#if VERSION >= VERSION_NTSC_1_0
bool bgunIsMissionCritical(s32 weaponnum)
{
	if (weaponnum == WEAPON_TIMEDMINE
			|| weaponnum == WEAPON_REMOTEMINE
			|| weaponnum == WEAPON_ECMMINE
			|| weaponnum == WEAPON_TRACERBUG) {
		return true;
	}

	return false;
}
#endif

void bgunDisarm(struct prop *attackerprop)
{
	struct player *player = g_Vars.currentplayer;
	s32 weaponnum = player->hands[0].gset.weaponnum;
	struct chrdata *chr;
	s32 modelnum;
	s32 i;
	bool drop;

	if (!weaponHasFlag(weaponnum, WEAPONFLAG_08000000) && weaponnum <= WEAPON_RCP45) {
#if VERSION >= VERSION_NTSC_1_0
		// Coop must not allow player to drop a mission critical weapon
		// because AI lists can fail the mission if the player has zero
		// quantity.
		if (g_Vars.coopplayernum >= 0
				&& (attackerprop == g_Vars.bond->prop || attackerprop == g_Vars.coop->prop)
				&& bgunIsMissionCritical(weaponnum)) {
			return;
		}
#endif

		if (weaponnum <= WEAPON_UNARMED || player->gunctrl.switchtoweaponnum != -1) {
			return;
		}

		chr = player->prop->chr;
		drop = true;

		// RC-P120 and cloaking device: turn off cloak if active
		if (weaponnum == WEAPON_RCP120) {
			g_Vars.currentplayer->devicesactive &= ~DEVICE_CLOAKRCP120;
		}

		if (weaponnum == WEAPON_CLOAKINGDEVICE) {
			g_Vars.currentplayer->devicesactive &= ~DEVICE_CLOAKDEVICE;
		}

		// Grenade and nbomb: if pin is pulled, throw it?
		// Or drop it at player's feet with the pin pulled maybe...
		if (weaponnum == WEAPON_GRENADE || weaponnum == WEAPON_NBOMB) {
			for (i = 0; i < 2; i++) {
				struct weaponfunc *func = gsetGetWeaponFunction(&player->hands[i].gset);

				if ((func->type & 0xff) == INVENTORYFUNCTYPE_THROW
						&& player->hands[i].state == HANDSTATE_ATTACK
						&& player->hands[i].stateminor == 0) {
					drop = false;
					bgunCreateThrownProjectile(i + 2, &player->hands[i].gset);
				}
			}
		}

		weaponDeleteFromChr(chr, HAND_RIGHT);
		weaponDeleteFromChr(chr, HAND_LEFT);

		// Actually drop the weapon
		modelnum = playermgrGetModelOfWeapon(weaponnum);

		if (modelnum >= 0 && drop) {
			struct prop *prop2 = weaponCreateForChr(chr, modelnum, weaponnum, OBJFLAG_WEAPON_AICANNOTUSE, NULL, NULL);

			if (prop2 && prop2->obj) {
				struct defaultobj *obj = prop2->obj;
				objSetDropped(prop2, DROPTYPE_DEFAULT);

				if (obj->hidden & OBJHFLAG_PROJECTILE) {
					obj->projectile->pickuptimer240 = TICKS(240);
					obj->projectile->pickupby = attackerprop;
				}

				objDrop(prop2, true);
			}
		}

		invRemoveItemByNum(weaponnum);

		player->hands[1].state = HANDSTATE_IDLE;
		player->hands[1].unk0d0e_00 = 1;
		player->hands[1].unk0d0e_04 = 0;
		player->hands[0].unk0d0e_00 = 1;
		player->hands[0].unk0d0e_04 = 0;
		player->hands[0].state = HANDSTATE_IDLE;

		// Exit slayer rocket mode if player was using it
		if (player->visionmode == VISIONMODE_SLAYERROCKET) {
			struct weaponobj *rocket = g_Vars.currentplayer->slayerrocket;

			if (rocket && rocket->base.prop) {
				rocket->timer240 = 0;
			}

			player->visionmode = VISIONMODE_NORMAL;
		}

		bgunEquipWeapon2(HAND_RIGHT, WEAPON_UNARMED);
		bgunEquipWeapon2(HAND_LEFT, WEAPON_NONE);
	}
}

/**
 * Execute some sort of command list that was generated by the function below.
 *
 * With this function stubbed, part of the CMP150 model does not render.
 */
void bgunExecuteModelCmdList(s32 *ptr)
{
	union modelrwdata *rwdata;
	struct modelnode *node;

	if (ptr != NULL) {
		while (*ptr != 6) {
			switch (*ptr) {
			case 0:
				rwdata = (union modelrwdata *)ptr[1];
				node = (struct modelnode *)ptr[2];
				rwdata->distance.visible = false;
				node->child = (struct modelnode *)ptr[3];
				ptr += 4;
				break;
			case 1:
				rwdata = (union modelrwdata *)ptr[1];
				node = (struct modelnode *)ptr[2];
				rwdata->toggle.visible = true;
				node->child = (struct modelnode *)ptr[3];
				ptr += 4;
				break;
			case 2:
				rwdata = (union modelrwdata *)ptr[1];
				rwdata->headspot.modelfiledata = NULL;
				rwdata->headspot.rwdatas = NULL;
				ptr += 2;
				break;
			case 3:
				rwdata = (union modelrwdata *)ptr[1];
				rwdata->type0b.unk00 = 0;
				ptr += 2;
				break;
			case 4:
				rwdata = (union modelrwdata *)ptr[1];
				rwdata->chrgunfire.visible = false;
				ptr += 2;
				break;
			case 5:
				rwdata = (union modelrwdata *)ptr[1];
				rwdata->dl.vertices = (struct gfxvtx *)ptr[2];
				rwdata->dl.gdl = (Gfx *)ptr[3];
				rwdata->dl.colours = (struct colour *)ptr[4];
				ptr += 5;
				break;
			}
		}
	}
}

/**
 * Generate some sort of command list to be executed by the function above.
 *
 * This appears to be a performance optimisation, so the tick code can quickly
 * iterate the command list to update part visibility rather than iterate the
 * full model tree.
 */
s32 bgunCreateModelCmdList(struct model *model, struct modelnode *nodearg, s32 *ptr)
{
	s32 len = 0;
	struct modelnode *node = nodearg;
	union modelrodata *rodata;
	union modelrwdata *rwdata;

	while (node) {
		u32 type = node->type;

		switch ((u8)type) {
		case MODELNODETYPE_DISTANCE:
			rodata = node->rodata;
			rwdata = modelGetNodeRwData(model, node);
			rwdata->distance.visible = false;
			node->child = rodata->distance.target;
			ptr[0] = 0;
			ptr[1] = (s32)rwdata;
			ptr[2] = (s32)node;
			ptr[3] = (s32)rodata->distance.target;
			ptr += 4;
			len += 16;
			break;
		case MODELNODETYPE_TOGGLE:
			rodata = node->rodata;
			rwdata = modelGetNodeRwData(model, node);
			rwdata->toggle.visible = true;
			node->child = rodata->toggle.target;
			ptr[0] = 1;
			ptr[1] = (s32)rwdata;
			ptr[2] = (s32)node;
			ptr[3] = (s32)rodata->toggle.target;
			ptr += 4;
			len += 16;
			break;
		case MODELNODETYPE_HEADSPOT:
			rwdata = modelGetNodeRwData(model, node);
			rwdata->headspot.modelfiledata = NULL;
			rwdata->headspot.rwdatas = NULL;
			ptr[0] = 2;
			ptr[1] = (s32)rwdata;
			ptr += 2;
			len += 8;
			break;
		case MODELNODETYPE_0B:
			rwdata = modelGetNodeRwData(model, node);
			rwdata->type0b.unk00 = 0;
			ptr[0] = 3;
			ptr[1] = (s32)rwdata;
			ptr += 2;
			len += 8;
			break;
		case MODELNODETYPE_CHRGUNFIRE:
			rwdata = modelGetNodeRwData(model, node);
			rwdata->chrgunfire.visible = false;
			ptr[0] = 4;
			ptr[1] = (s32)rwdata;
			ptr += 2;
			len += 8;
			break;
		case MODELNODETYPE_DL:
			rodata = node->rodata;
			rwdata = modelGetNodeRwData(model, node);
			rwdata->dl.vertices = rodata->dl.vertices;
			rwdata->dl.gdl = rodata->dl.primary;
			rwdata->dl.colours = (void *)ALIGN8((u32)&rodata->dl.vertices[rodata->dl.numvertices]);
			ptr[0] = 5;
			ptr[1] = (s32)rwdata;
			ptr[2] = (s32)rwdata->dl.vertices;
			ptr[3] = (s32)rwdata->dl.gdl;
			ptr[4] = (s32)rwdata->dl.colours;
			ptr += 5;
			len += 20;
			break;
		}

		if (node->child) {
			node = node->child;
		} else {
			while (node) {
				if (node == nodearg->parent) {
					node = NULL;
					break;
				}

				if (node->next) {
					node = node->next;
					break;
				}

				node = node->parent;
			}
		}
	}

	*ptr = 6;
	len += 4;

	return len;
}

void bgunStartDetonateAnimation(s32 playernum)
{
	s32 prevplayernum = g_Vars.currentplayernum;
	setCurrentPlayerNum(playernum);

	if (g_Vars.currentplayer->hands[HAND_LEFT].gset.weaponnum == WEAPON_REMOTEMINE) {
		bgunStartAnimation(var80070200, 1, &g_Vars.currentplayer->hands[HAND_LEFT]);
	}

	setCurrentPlayerNum(prevplayernum);
}

/**
 * Update the gangsta-style rotation of the player's gun.
 *
 * When close to an enemy and aiming at them with a pistol, the gun is rotated
 * sideways. The enemy and aiming check is done elsewhere (autoaim code) and
 * sets the gunctrl's gangsta property to true or false based on whether this
 * criteria is met on the current (or previous?) frame.
 *
 * bgunUpdateGangsta uses this property and increments the rotation of the gun
 * accordingly. It also checks that the gun is in a state that allows gangsta
 * rotation (reloading and equip/unequip do not). It also implements a delay on
 * reverting to the normal rotation.
 */
void bgunUpdateGangsta(struct hand *hand, s32 handnum, struct coord *arg2, struct weaponfunc *funcdef, Mtxf *arg4, Mtxf *arg5)
{
	f32 tmp;
	struct coord sp38 = {0, 0, 0};

	if (g_Vars.currentplayer->gunctrl.gangsta
			&& funcdef
			&& (funcdef->type & 0xff) == INVENTORYFUNCTYPE_SHOOT
			&& (hand->state == HANDSTATE_IDLE
				|| hand->state == HANDSTATE_2
				|| hand->state == HANDSTATE_ATTACKEMPTY
				|| hand->state == HANDSTATE_ATTACK)) {
		if (hand->gangstarot < 1.0f) {
			// Rotate into gangsta position
			hand->ispare1 += g_Vars.lvupdate240;

			if (hand->ispare1 > TICKS(60)) {
				hand->gangstarot += LVUPDATE240FREAL() / 30.0f;

				if (hand->gangstarot > 1.0f) {
					hand->gangstarot = 1.0f;
				}
			}
		} else {
			// Already in gangsta position
			hand->ispare1 = 0;
		}
	} else {
		// At this point we don't want the gun to be in the gangsta position.
		// However we don't want it to revert immediately, so a timer is used.
		f32 inversespeed = 30.0f;

		if (hand->animmode == HANDANIMMODE_BUSY) {
			// Revert faster
			inversespeed = 15.0f;
		}

		if (hand->gangstarot > 0.0f) {
			bool revert = false;

			hand->ispare1 += g_Vars.lvupdate240;

			if (hand->gangstarot < 1.0f) {
				hand->ispare1 = TICKS(244);
			}

			if (hand->ispare1 > TICKS(120)) {
				revert = true;
			}

			if (hand->animmode == HANDANIMMODE_BUSY && funcdef && (funcdef->type & 0xff) != INVENTORYFUNCTYPE_SHOOT) {
				revert = true;
			}

			if (hand->state != HANDSTATE_IDLE
					&& hand->state != HANDSTATE_2
					&& hand->state != HANDSTATE_ATTACKEMPTY
					&& hand->state != HANDSTATE_ATTACK) {
				revert = true;
			}

			if (revert) {
				hand->gangstarot -= LVUPDATE240FREAL() / inversespeed;
			}

			if (hand->gangstarot < 0.0f) {
				hand->gangstarot = 0.0f;
			}
		} else {
			// Not rotated
			hand->ispare1 = 0;
		}
	}

	tmp = -cosf(hand->gangstarot * M_PI) * 0.5f + 0.50f;
	sp38.z = (tmp * 66.6f * 0.017453292f) * (handnum != HAND_RIGHT ? 1.0f : -1.0f);

	mtx4LoadRotation(&sp38, arg4);
	mtx00015be0(arg4, arg5);

	arg2->y += 4.0f * hand->gangstarot;
	arg2->x += 2.0f * hand->gangstarot * (handnum != HAND_RIGHT ? 1.0f : -1.0f);
}

/**
 * Check if smoke needs to be created at the muzzle of the current weapon.
 *
 * gunsmokepoint is basically the temperature of the gun. It increases when
 * firing and cools down when idle. It's only used for pistols; automatics will
 * create smoke based on the number of shots in the current burst.
 *
 * createsmoke must be set to create any smoke at all.
 *
 * forcecreatesmoke controls whether smoke should be created while the gun is
 * still firing.
 */
void bgunUpdateSmoke(struct hand *hand, s32 handnum, s32 weaponnum, struct weaponfunc *funcdef)
{
	if (hand->firing) {
		if (weaponnum == WEAPON_DY357MAGNUM || weaponnum == WEAPON_DY357LX) {
			if ((funcdef->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
				hand->gunsmokepoint += 0.6f;
			}
		} else {
			hand->gunsmokepoint += 0.2f;
		}
	}

	hand->gunsmokepoint -= LVUPDATE240FREAL() / 120.0f;

	if (hand->gunsmokepoint < 0.0f) {
		hand->gunsmokepoint = 0.0f;
	}

	if (funcdef && (funcdef->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		f32 mult = 1.0f;

		if (g_Vars.currentplayer->hands[HAND_LEFT].inuse) {
			mult = 1.5f;
		}

		hand->forcecreatesmoke = false;

		switch (weaponnum) {
		case WEAPON_FALCON2:
		case WEAPON_FALCON2_SCOPE:
			if (hand->gunsmokepoint * mult > 0.66f) {
				hand->createsmoke = true;
			}
			break;
		case WEAPON_MAGSEC4:
		case WEAPON_MAULER:
			if (hand->gunsmokepoint * mult > 0.75f) {
				hand->createsmoke = true;
			}
			break;
		case WEAPON_DY357MAGNUM:
		case WEAPON_DY357LX:
			if (hand->gunsmokepoint * mult > 0.9f) {
				hand->createsmoke = true;
			}
			break;
		case WEAPON_CMP150:
		case WEAPON_DRAGON:
		case WEAPON_K7AVENGER:
		case WEAPON_AR34:
		case WEAPON_SUPERDRAGON:
			hand->forcecreatesmoke = true;

			if (hand->burstbullets > 14) {
				hand->createsmoke = true;
			}
			break;
		case WEAPON_CYCLONE:
		case WEAPON_LAPTOPGUN:
			if (hand->burstbullets > 20) {
				hand->createsmoke = true;
			}

			hand->forcecreatesmoke = true;
			break;
		case WEAPON_RCP120:
			hand->forcecreatesmoke = true;

			if (hand->burstbullets > 25) {
				hand->createsmoke = true;
			}
			break;
		case WEAPON_REAPER:
			hand->forcecreatesmoke = true;
			// fall-through
		case WEAPON_SHOTGUN:
			if (hand->firing) {
				hand->createsmoke = true;
			}
			break;
		}
	}

	if (hand->createsmoke && (hand->state != HANDSTATE_ATTACK || hand->forcecreatesmoke)) {
		struct coord smokepos;
		s16 smokerooms[2];
		s32 smoketype = SMOKETYPE_MUZZLE_AUTOMATIC;

		switch (weaponnum) {
		case WEAPON_FALCON2:
		case WEAPON_FALCON2_SCOPE:
		case WEAPON_MAGSEC4:
		case WEAPON_MAULER:
		case WEAPON_DY357MAGNUM:
		case WEAPON_DY357LX:
			smoketype = SMOKETYPE_MUZZLE_PISTOL;
			break;
		case WEAPON_REAPER:
			smoketype = SMOKETYPE_MUZZLE_REAPER;
			break;
		case WEAPON_SHOTGUN:
			smoketype = SMOKETYPE_MUZZLE_SHOTGUN;
			break;
		}

		smokerooms[0] = g_Vars.currentplayer->cam_room;
		smokerooms[1] = -1;

		smokepos.x = hand->muzzlepos.x;
		smokepos.y = hand->muzzlepos.y;
		smokepos.z = hand->muzzlepos.z;

		hand->gunsmokepoint = 0.0f;

		if (smokeCreateForHand(&smokepos, smokerooms, smoketype, handnum)) {
			hand->createsmoke = false;
		}
	}
}

/**
 * Update the red beam and dot (used by the Falcon 2 and its variants).
 */
void bgunUpdateLasersight(struct hand *hand, struct modelfiledata *modeldef, s32 handnum, u8 *allocation)
{
	struct modelnode *node;
	struct coord beamfar;
	struct coord dotpos;
	struct coord dotrot;
	struct coord beamnear;
	s32 mtxindex;
	struct coord sp54;
	struct coord sp48;
	struct coord sp3c;
	struct coord sp30;
	bool busy;

	node = modelGetPart(modeldef, MODELPART_FALCON2_0034);

	if (node) {
		mtxindex = model0001a524(node, 0);

		beamnear.x = ((Mtxf *)((u32)allocation + mtxindex * sizeof(Mtxf)))->m[3][0];
		beamnear.y = ((Mtxf *)((u32)allocation + mtxindex * sizeof(Mtxf)))->m[3][1];
		beamnear.z = ((Mtxf *)((u32)allocation + mtxindex * sizeof(Mtxf)))->m[3][2];

		mtx4TransformVecInPlace(camGetProjectionMtxF(), &beamnear);

		if (hand->useposrot
				|| (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_XRAYSCANNER)) {
			beamfar.x = 0.0f;
			beamfar.y = 0.0f;
			beamfar.z = 1.0f;

			mtx4RotateVecInPlace(&hand->cammtx, &beamfar);

			sp48.x = beamfar.x;
			sp48.y = beamfar.y;
			sp48.z = beamfar.z;

			sp3c.x = beamnear.x;
			sp3c.y = beamnear.y;
			sp3c.z = beamnear.z;

			mtx4TransformVec(camGetWorldToScreenMtxf(), &sp3c, &sp54);
			mtx4RotateVec(camGetProjectionMtxF(), &sp48, &sp30);

			beamfar.x *= 500.0f;
			beamfar.y *= 500.0f;
			beamfar.z *= 500.0f;

			mtx4RotateVecInPlace(camGetProjectionMtxF(), &beamfar);

			beamfar.x += beamnear.x;
			beamfar.y += beamnear.y;
			beamfar.z += beamnear.z;

			lasersightSetBeam(handnum, 1, &beamnear, &beamfar);
			return;
		}

		busy = false;

		if (hand->animmode == HANDANIMMODE_BUSY) {
			busy = true;
		}

		if (busy) {
			mtxindex = model0001a524(node, 0);

			beamfar.x = 0.0f;
			beamfar.y = 0.0f;
			beamfar.z = 500.0f;

			mtx4TransformVecInPlace((Mtxf *)((u32)allocation + mtxindex * sizeof(Mtxf)), &beamfar);
		} else {
			cam0f0b4c3c(g_Vars.currentplayer->crosspos, &beamfar, 1);

			beamfar.x *= 500.0f;
			beamfar.y *= 500.0f;
			beamfar.z *= 500.0f;
		}

		mtx4TransformVecInPlace(camGetProjectionMtxF(), &beamfar);
		lasersightSetBeam(handnum, 1, &beamnear, &beamfar);

		if (handnum == HAND_RIGHT && hand->hasdotinfo && !busy) {
			dotpos.x = hand->dotpos.x;
			dotpos.y = hand->dotpos.y;
			dotpos.z = hand->dotpos.z;

			dotrot.x = hand->dotrot.x;
			dotrot.y = hand->dotrot.y;
			dotrot.z = hand->dotrot.z;

			lasersightSetDot(handnum, &dotpos, &dotrot);
		}
	}
}

/**
 * Increment the main barrel spinning, play sounds and (probably) fire shots.
 */
void bgunUpdateReaper(struct hand *hand, struct modelfiledata *modeldef)
{
	struct modelnode *node;
	f32 f2;
	f32 f12;
	s32 tmp;

	node = modelGetPart(modeldef, MODELPART_REAPER_002C);

	if (hand->matmot3 <= hand->matmot2) {
		if (hand->matmot2 < 0.0f) {
			hand->matmot2 += 0.01f * LVUPDATE240FREAL();

			if (hand->matmot2 > 0.0f) {
				hand->matmot2 = 0.0f;
			}
		}

		hand->matmot3 = hand->matmot2;
	} else {
		f12 = LVUPDATE240FREAL() * 0.005;

		if (hand->matmot2 < 0.0000001f) {
			hand->matmot2 = -0.14f;

			if (hand->matmot3 < 0.15f) {
				f12 *= 4.0f;
			}
		}

		f2 = hand->matmot3 - hand->matmot2;

		if (f12 < f2) {
			f2 = f12;
		}

		hand->matmot3 -= f2;
	}

	if (hand->matmot3 < 0.0f) {
		hand->matmot1 = hand->matmot1 - (1.0f - cosf(hand->matmot3 * M_PI)) * 0.5f * LVUPDATE240FREAL() * 0.2f;
	} else {
		hand->matmot1 = hand->matmot1 + (1.0f - cosf(hand->matmot3 * M_PI)) * 0.5f * LVUPDATE240FREAL() * 0.2f;
	}

	tmp = hand->matmot1 / 6.2831802368164f;
	hand->matmot1 -= tmp * 6.2831802368164f;
	var8009d140 = hand->matmot1;

	if (hand->audiohandle == NULL && hand->matmot3 > 0.1f && g_Vars.lvupdate240 != 0) {
		sndStart(var80095200, SFX_805E, &hand->audiohandle, -1, -1, -1.0f, -1, -1);
	}

	if (hand->audiohandle != NULL) {
		f32 sp34 = hand->matmot3 / 0.50f + 0.4f;
		s32 a2 = 0x7fff;

		if (hand->matmot3 < 0.1f) {
			audioStop(hand->audiohandle);
		} else {
			if (hand->matmot3 < 0.6f) {
				a2 = (hand->matmot3 - 0.1f) * 32767.0f / 0.5f;
			}

			audioPostEvent(hand->audiohandle, 8, a2);
			audioPostEvent(hand->audiohandle, 0x10, *(s32 *)&sp34);
		}
	}

	if (node) {
		var8009d0dc = model0001a524(node, 0);
		g_ModelJointPositionedFunc = bgun0f0a256c;
		var8009d0f0[0] = var8009d0f0[1] = var8009d0f0[2] = -1;
	}

	node = modelGetPart(modeldef, MODELPART_REAPER_002D);

	if (node) {
		var8009d0f0[0] = model0001a524(node, 0);
	}

	node = modelGetPart(modeldef, MODELPART_REAPER_002E);

	if (node) {
		var8009d0f0[1] = model0001a524(node, 0);
	}

	node = modelGetPart(modeldef, MODELPART_REAPER_002F);

	if (node) {
		var8009d0f0[2] = model0001a524(node, 0);
	}
}

/**
 * Move/extend the scope on the gun model when the zoom function is used.
 */
void bgunUpdateSniperRifle(struct modelfiledata *modeldef, u8 *allocation)
{
	struct modelnode *nodes[4];
	f32 sp88[4] = {0, 0, 0, 0};
	s32 i;
	f32 f26;
	s32 mtxindex;
	struct coord sp70;

	f26 = 1.0f - (currentPlayerGetGunZoomFov() - 2.0f) / 58.0f;

	nodes[0] = modelGetPart(modeldef, MODELPART_SNIPERRIFLE_002A);
	nodes[1] = modelGetPart(modeldef, MODELPART_SNIPERRIFLE_002B);
	nodes[2] = modelGetPart(modeldef, MODELPART_SNIPERRIFLE_002C);
	nodes[3] = modelGetPart(modeldef, MODELPART_SNIPERRIFLE_002D);

	for (i = 0; i < 4; i++) {
		if (nodes[i]) {
			f32 f20 = f26 * 4.0f;
			mtxindex = model0001a524(nodes[i], 0);
			sp88[i] = f20 - i;

			if (f20 < i) {
				sp88[i] = 0.0f;
			}

			sp88[i] *= 100.0f;

			sp70.x = 0.0f;
			sp70.y = 0.0f;
			sp70.z = sp88[i];

			mtx4RotateVecInPlace((Mtxf *)((u32)allocation + mtxindex * sizeof(Mtxf)), &sp70);

			((Mtxf *)((u32)allocation + mtxindex * sizeof(Mtxf)))->m[3][0] += sp70.x;
			((Mtxf *)((u32)allocation + mtxindex * sizeof(Mtxf)))->m[3][1] += sp70.y;
			((Mtxf *)((u32)allocation + mtxindex * sizeof(Mtxf)))->m[3][2] += sp70.z;
		}
	}
}

/**
 * Animate the cartridge slider thing in the Devastator model.
 */
void bgunUpdateDevastator(struct hand *hand, u8 *allocation, struct modelfiledata *modeldef)
{
	struct modelnode *node = modelGetPart(modeldef, MODELPART_DEVASTATOR_0028);

	if (node) {
		s32 mtxindex = model0001a524(node, 0);
		struct coord sp24;

		hand->loadslide += 0.01f * LVUPDATE240FREAL();

		if (hand->loadslide > 1.0f) {
			hand->loadslide = 1.0f;
		}

		sp24.x = hand->loadslide * -10.0f * 1.636f;
		sp24.y = 0.0f;
		sp24.z = 0.0f;

		mtx4RotateVecInPlace((Mtxf *)((u32)allocation + mtxindex * sizeof(Mtxf)), &sp24);

		((Mtxf *)((u32)allocation + mtxindex * sizeof(Mtxf)))->m[3][0] += sp24.x;
		((Mtxf *)((u32)allocation + mtxindex * sizeof(Mtxf)))->m[3][1] += sp24.y;
		((Mtxf *)((u32)allocation + mtxindex * sizeof(Mtxf)))->m[3][2] += sp24.z;
	}
}

/**
 * Display the shotgun's starburst when appropriate.
 *
 * This logic is different to most guns, likely because most guns display the
 * starburst when the trigger is pressed while the shotgun has the double blast
 * function.
 */
void bgunUpdateShotgun(struct hand *hand, u8 *allocation, bool *arg2, struct modelfiledata *modeldef)
{
	if (hand->flashon) {
		hand->matmot1 = 1.0f;
	}

	if (hand->matmot1 > 0.0f) {
		hand->matmot1 -= LVUPDATE240FREAL() / 6.0f;

		if (hand->matmot1 < 0.01f) {
			hand->matmot1 = 0.0f;
		}
	}

	if (hand->matmot1 > 0.0f) {
		s32 sp34;
		s32 sp28[3] = {0, 0, 0};
		struct modelnode *node = modelGetPart(modeldef, MODELPART_SHOTGUN_0050);

		*arg2 = true;

		if (node) {
			sp34 = model0001a524(node, 0);

			mtx00015ea8((1.0f - hand->matmot1) * 8.0f + 0.5f, (Mtxf *)((u32)allocation + sp34 * sizeof(Mtxf)));
			mtx00015df0((1.0f - hand->matmot1) * 3.0f + 1.0f, (Mtxf *)((u32)allocation + sp34 * sizeof(Mtxf)));
			mtx00015e4c((1.0f - hand->matmot1) * 3.0f + 1.0f, (Mtxf *)((u32)allocation + sp34 * sizeof(Mtxf)));
		}
	}
}

void bgunUpdateLaser(struct hand *hand)
{
	if (hand->firing && hand->gset.weaponfunc == FUNC_SECONDARY) {
		if (hand->audiohandle == NULL && g_Vars.lvupdate240 != 0) {
			sndStart(var80095200, SFX_LASER_STREAM, &hand->audiohandle, -1, -1, -1, -1, -1);
		}

		hand->matmot1 = 1;
		return;
	}

	if (hand->matmot1 > 0) {
		hand->matmot1 -= LVUPDATE240FREAL() / 10.0f;
	} else if (hand->audiohandle != NULL && sndGetState(hand->audiohandle) != AL_STOPPED) {
		audioStop(hand->audiohandle);
	}
}

/**
 * Create ammo casing so they can be ejected during reload.
 */
void bgunUpdateMagnum(struct hand *hand, s32 handnum, struct modelfiledata *modeldef, Mtxf *mtx)
{
	f32 ground = g_Vars.currentplayer->vv_ground;
	s32 i;

	if (modeldef != NULL) {
		for (i = 0; i < hand->unk0cc8_04; i++) {
			struct modelnode *node = modelGetPart(modeldef, 0x0a + random() % 6);

			if (node) {
				s32 index = model0001a524(node, 0);
				Mtxf *tmp = mtx;
				Mtxf sp4c;

				tmp += index;

				mtx4Copy(tmp, &sp4c);
				mtx00015f04(9.999999f, &sp4c);
				mtx4MultMtx4InPlace(camGetProjectionMtxF(), &sp4c);

				casingCreateForHand(handnum, ground, &sp4c);
			}
		}
	}
}

/**
 * Create and/or update the rocket prop that sits inside the rocket launcher.
 */
void bgunUpdateRocketLauncher(struct hand *hand, s32 handnum, struct weaponfunc_shootprojectile *func)
{
	if (hand->rocket == NULL && hand->loadedammo[0] > 0) {
		bgunCreateHeldRocket(handnum, func);
	}

	if (hand->rocket) {
		bgunUpdateHeldRocket(handnum);
	}
}

void bgun0f0a45d0(struct hand *hand, struct modelfiledata *filedata, bool isdetonator)
{
	struct modelnode *node = NULL;

	switch (hand->unk0d0e_04) {
	case 0:
		if (isdetonator) {
			node = modelGetPart(filedata, 0x2a);
		} else {
			node = modelGetPart(filedata, 0x37);
		}
		break;
	case 1:
		node = modelGetPart(filedata, 0x2b);
		break;
	case 2:
		node = modelGetPart(filedata, 0x2b);
		break;
	}

	if (node) {
		var8009d148 = model0001a524(node, 0);
		g_ModelJointPositionedFunc = bgun0f0a256c;
	} else {
		var8009d148 = -1;
	}
}

#if MATCHING
#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel bgun0f0a46a4
.late_rodata
glabel var7f1ac8cc
.word 0x3f088888
.word 0x414907a9
.word 0x3d0bd8cf
.word 0x414907a9
.word 0x3d0bd8cf
.word 0x414907a9
.word 0x3d0bd8cf
.word 0x3f088888
.word 0x40c907a9
.word 0x414907a9
.word 0x3c3d3463
.word 0x414907a9
.word 0x3c3d3463
.word 0x40c907a9
.word 0x414907a9
.word 0x3bda10fd
.word 0x414907a9
.word 0x3bda10fd
.word 0x3e99999a
.word 0x3e8e38e4
.text
/*  f0a560c:	27bdff20 */ 	addiu	$sp,$sp,-224
/*  f0a5610:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0a5614:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0a5618:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0a561c:	afa500e4 */ 	sw	$a1,0xe4($sp)
/*  f0a5620:	afa600e8 */ 	sw	$a2,0xe8($sp)
/*  f0a5624:	948206d6 */ 	lhu	$v0,0x6d6($a0)
/*  f0a5628:	24030001 */ 	li	$v1,0x1
/*  f0a562c:	00808025 */ 	move	$s0,$a0
/*  f0a5630:	00027302 */ 	srl	$t6,$v0,0xc
/*  f0a5634:	11c30005 */ 	beq	$t6,$v1,.JF0f0a564c
/*  f0a5638:	24010002 */ 	li	$at,0x2
/*  f0a563c:	11c1018d */ 	beq	$t6,$at,.JF0f0a5c74
/*  f0a5640:	3c03800a */ 	lui	$v1,0x800a
/*  f0a5644:	100001ce */ 	b	.JF0f0a5d80
/*  f0a5648:	8fbf0024 */ 	lw	$ra,0x24($sp)
.JF0f0a564c:
/*  f0a564c:	8e0206d4 */ 	lw	$v0,0x6d4($s0)
/*  f0a5650:	00027d00 */ 	sll	$t7,$v0,0x14
/*  f0a5654:	000fc742 */ 	srl	$t8,$t7,0x1d
/*  f0a5658:	13000007 */ 	beqz	$t8,.JF0f0a5678
/*  f0a565c:	00000000 */ 	nop
/*  f0a5660:	1303006c */ 	beq	$t8,$v1,.JF0f0a5814
/*  f0a5664:	24010002 */ 	li	$at,0x2
/*  f0a5668:	530100e3 */ 	beql	$t8,$at,.JF0f0a59f8
/*  f0a566c:	44802000 */ 	mtc1	$zero,$f4
/*  f0a5670:	10000140 */ 	b	.JF0f0a5b74
/*  f0a5674:	3c014348 */ 	lui	$at,0x4348
.JF0f0a5678:
/*  f0a5678:	0c004b60 */ 	jal	random
/*  f0a567c:	00000000 */ 	nop
/*  f0a5680:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a5684:	c420d54c */ 	lwc1	$f0,-0x2ab4($at)
/*  f0a5688:	44822000 */ 	mtc1	$v0,$f4
/*  f0a568c:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a5690:	4481a000 */ 	mtc1	$at,$f20
/*  f0a5694:	04410005 */ 	bgez	$v0,.JF0f0a56ac
/*  f0a5698:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a569c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a56a0:	44814000 */ 	mtc1	$at,$f8
/*  f0a56a4:	00000000 */ 	nop
/*  f0a56a8:	46083180 */ 	add.s	$f6,$f6,$f8
.JF0f0a56ac:
/*  f0a56ac:	46143282 */ 	mul.s	$f10,$f6,$f20
/*  f0a56b0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a56b4:	44818000 */ 	mtc1	$at,$f16
/*  f0a56b8:	3c013d80 */ 	lui	$at,0x3d80
/*  f0a56bc:	44814000 */ 	mtc1	$at,$f8
/*  f0a56c0:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0a56c4:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0a56c8:	00000000 */ 	nop
/*  f0a56cc:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0a56d0:	46003280 */ 	add.s	$f10,$f6,$f0
/*  f0a56d4:	0c004b60 */ 	jal	random
/*  f0a56d8:	e60a06e8 */ 	swc1	$f10,0x6e8($s0)
/*  f0a56dc:	44828000 */ 	mtc1	$v0,$f16
/*  f0a56e0:	3c014020 */ 	lui	$at,0x4020
/*  f0a56e4:	44810000 */ 	mtc1	$at,$f0
/*  f0a56e8:	04410005 */ 	bgez	$v0,.JF0f0a5700
/*  f0a56ec:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0a56f0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a56f4:	44812000 */ 	mtc1	$at,$f4
/*  f0a56f8:	00000000 */ 	nop
/*  f0a56fc:	46049480 */ 	add.s	$f18,$f18,$f4
.JF0f0a5700:
/*  f0a5700:	46149202 */ 	mul.s	$f8,$f18,$f20
/*  f0a5704:	3c013d80 */ 	lui	$at,0x3d80
/*  f0a5708:	44815000 */ 	mtc1	$at,$f10
/*  f0a570c:	44809000 */ 	mtc1	$zero,$f18
/*  f0a5710:	00000000 */ 	nop
/*  f0a5714:	e61206f0 */ 	swc1	$f18,0x6f0($s0)
/*  f0a5718:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0a571c:	00000000 */ 	nop
/*  f0a5720:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0a5724:	46008100 */ 	add.s	$f4,$f16,$f0
/*  f0a5728:	0c004b60 */ 	jal	random
/*  f0a572c:	e60406ec */ 	swc1	$f4,0x6ec($s0)
/*  f0a5730:	44824000 */ 	mtc1	$v0,$f8
/*  f0a5734:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a5738:	04410004 */ 	bgez	$v0,.JF0f0a574c
/*  f0a573c:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0a5740:	44815000 */ 	mtc1	$at,$f10
/*  f0a5744:	00000000 */ 	nop
/*  f0a5748:	460a3180 */ 	add.s	$f6,$f6,$f10
.JF0f0a574c:
/*  f0a574c:	46143402 */ 	mul.s	$f16,$f6,$f20
/*  f0a5750:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a5754:	c424d550 */ 	lwc1	$f4,-0x2ab0($at)
/*  f0a5758:	3c014338 */ 	lui	$at,0x4338
/*  f0a575c:	44814000 */ 	mtc1	$at,$f8
/*  f0a5760:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a5764:	c426d554 */ 	lwc1	$f6,-0x2aac($at)
/*  f0a5768:	46048482 */ 	mul.s	$f18,$f16,$f4
/*  f0a576c:	46089283 */ 	div.s	$f10,$f18,$f8
/*  f0a5770:	46065401 */ 	sub.s	$f16,$f10,$f6
/*  f0a5774:	0c004b60 */ 	jal	random
/*  f0a5778:	e7b000d0 */ 	swc1	$f16,0xd0($sp)
/*  f0a577c:	44822000 */ 	mtc1	$v0,$f4
/*  f0a5780:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a5784:	04410004 */ 	bgez	$v0,.JF0f0a5798
/*  f0a5788:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f0a578c:	44814000 */ 	mtc1	$at,$f8
/*  f0a5790:	00000000 */ 	nop
/*  f0a5794:	46089480 */ 	add.s	$f18,$f18,$f8
.JF0f0a5798:
/*  f0a5798:	46149282 */ 	mul.s	$f10,$f18,$f20
/*  f0a579c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a57a0:	c426d558 */ 	lwc1	$f6,-0x2aa8($at)
/*  f0a57a4:	3c014338 */ 	lui	$at,0x4338
/*  f0a57a8:	44812000 */ 	mtc1	$at,$f4
/*  f0a57ac:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a57b0:	c432d55c */ 	lwc1	$f18,-0x2aa4($at)
/*  f0a57b4:	46065402 */ 	mul.s	$f16,$f10,$f6
/*  f0a57b8:	46048203 */ 	div.s	$f8,$f16,$f4
/*  f0a57bc:	46124281 */ 	sub.s	$f10,$f8,$f18
/*  f0a57c0:	0c004b60 */ 	jal	random
/*  f0a57c4:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0a57c8:	44823000 */ 	mtc1	$v0,$f6
/*  f0a57cc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a57d0:	04410004 */ 	bgez	$v0,.JF0f0a57e4
/*  f0a57d4:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f0a57d8:	44812000 */ 	mtc1	$at,$f4
/*  f0a57dc:	00000000 */ 	nop
/*  f0a57e0:	46048400 */ 	add.s	$f16,$f16,$f4
.JF0f0a57e4:
/*  f0a57e4:	46148202 */ 	mul.s	$f8,$f16,$f20
/*  f0a57e8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a57ec:	c432d560 */ 	lwc1	$f18,-0x2aa0($at)
/*  f0a57f0:	3c014338 */ 	lui	$at,0x4338
/*  f0a57f4:	44813000 */ 	mtc1	$at,$f6
/*  f0a57f8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a57fc:	c430d564 */ 	lwc1	$f16,-0x2a9c($at)
/*  f0a5800:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f0a5804:	46065103 */ 	div.s	$f4,$f10,$f6
/*  f0a5808:	46102201 */ 	sub.s	$f8,$f4,$f16
/*  f0a580c:	100000d8 */ 	b	.JF0f0a5b70
/*  f0a5810:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
.JF0f0a5814:
/*  f0a5814:	0c004b60 */ 	jal	random
/*  f0a5818:	00000000 */ 	nop
/*  f0a581c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a5820:	c420d568 */ 	lwc1	$f0,-0x2a98($at)
/*  f0a5824:	44829000 */ 	mtc1	$v0,$f18
/*  f0a5828:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a582c:	4481a000 */ 	mtc1	$at,$f20
/*  f0a5830:	04410005 */ 	bgez	$v0,.JF0f0a5848
/*  f0a5834:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f0a5838:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a583c:	44813000 */ 	mtc1	$at,$f6
/*  f0a5840:	00000000 */ 	nop
/*  f0a5844:	46065280 */ 	add.s	$f10,$f10,$f6
.JF0f0a5848:
/*  f0a5848:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0a584c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a5850:	44818000 */ 	mtc1	$at,$f16
/*  f0a5854:	3c013d80 */ 	lui	$at,0x3d80
/*  f0a5858:	44813000 */ 	mtc1	$at,$f6
/*  f0a585c:	3c014040 */ 	lui	$at,0x4040
/*  f0a5860:	46102201 */ 	sub.s	$f8,$f4,$f16
/*  f0a5864:	44812000 */ 	mtc1	$at,$f4
/*  f0a5868:	46004482 */ 	mul.s	$f18,$f8,$f0
/*  f0a586c:	00000000 */ 	nop
/*  f0a5870:	46069282 */ 	mul.s	$f10,$f18,$f6
/*  f0a5874:	00000000 */ 	nop
/*  f0a5878:	46002402 */ 	mul.s	$f16,$f4,$f0
/*  f0a587c:	46105200 */ 	add.s	$f8,$f10,$f16
/*  f0a5880:	46004487 */ 	neg.s	$f18,$f8
/*  f0a5884:	0c004b60 */ 	jal	random
/*  f0a5888:	e61206e8 */ 	swc1	$f18,0x6e8($s0)
/*  f0a588c:	44823000 */ 	mtc1	$v0,$f6
/*  f0a5890:	3c014020 */ 	lui	$at,0x4020
/*  f0a5894:	44810000 */ 	mtc1	$at,$f0
/*  f0a5898:	04410005 */ 	bgez	$v0,.JF0f0a58b0
/*  f0a589c:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0a58a0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a58a4:	44815000 */ 	mtc1	$at,$f10
/*  f0a58a8:	00000000 */ 	nop
/*  f0a58ac:	460a2100 */ 	add.s	$f4,$f4,$f10
.JF0f0a58b0:
/*  f0a58b0:	46142402 */ 	mul.s	$f16,$f4,$f20
/*  f0a58b4:	3c013e00 */ 	lui	$at,0x3e00
/*  f0a58b8:	44819000 */ 	mtc1	$at,$f18
/*  f0a58bc:	46008202 */ 	mul.s	$f8,$f16,$f0
/*  f0a58c0:	00000000 */ 	nop
/*  f0a58c4:	46124182 */ 	mul.s	$f6,$f8,$f18
/*  f0a58c8:	46003280 */ 	add.s	$f10,$f6,$f0
/*  f0a58cc:	0c004b60 */ 	jal	random
/*  f0a58d0:	e60a06ec */ 	swc1	$f10,0x6ec($s0)
/*  f0a58d4:	44822000 */ 	mtc1	$v0,$f4
/*  f0a58d8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a58dc:	04410004 */ 	bgez	$v0,.JF0f0a58f0
/*  f0a58e0:	46802420 */ 	cvt.s.w	$f16,$f4
/*  f0a58e4:	44814000 */ 	mtc1	$at,$f8
/*  f0a58e8:	00000000 */ 	nop
/*  f0a58ec:	46088400 */ 	add.s	$f16,$f16,$f8
.JF0f0a58f0:
/*  f0a58f0:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f0a58f4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a58f8:	44813000 */ 	mtc1	$at,$f6
/*  f0a58fc:	00000000 */ 	nop
/*  f0a5900:	46069280 */ 	add.s	$f10,$f18,$f6
/*  f0a5904:	46005107 */ 	neg.s	$f4,$f10
/*  f0a5908:	0c004b60 */ 	jal	random
/*  f0a590c:	e60406f0 */ 	swc1	$f4,0x6f0($s0)
/*  f0a5910:	44824000 */ 	mtc1	$v0,$f8
/*  f0a5914:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a5918:	04410004 */ 	bgez	$v0,.JF0f0a592c
/*  f0a591c:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f0a5920:	44819000 */ 	mtc1	$at,$f18
/*  f0a5924:	00000000 */ 	nop
/*  f0a5928:	46128400 */ 	add.s	$f16,$f16,$f18
.JF0f0a592c:
/*  f0a592c:	46148182 */ 	mul.s	$f6,$f16,$f20
/*  f0a5930:	3c014040 */ 	lui	$at,0x4040
/*  f0a5934:	44815000 */ 	mtc1	$at,$f10
/*  f0a5938:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a593c:	c428d56c */ 	lwc1	$f8,-0x2a94($at)
/*  f0a5940:	3c014350 */ 	lui	$at,0x4350
/*  f0a5944:	44818000 */ 	mtc1	$at,$f16
/*  f0a5948:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f0a594c:	46082482 */ 	mul.s	$f18,$f4,$f8
/*  f0a5950:	46109183 */ 	div.s	$f6,$f18,$f16
/*  f0a5954:	0c004b60 */ 	jal	random
/*  f0a5958:	e7a600d0 */ 	swc1	$f6,0xd0($sp)
/*  f0a595c:	44825000 */ 	mtc1	$v0,$f10
/*  f0a5960:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a5964:	04410004 */ 	bgez	$v0,.JF0f0a5978
/*  f0a5968:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0a596c:	44814000 */ 	mtc1	$at,$f8
/*  f0a5970:	00000000 */ 	nop
/*  f0a5974:	46082100 */ 	add.s	$f4,$f4,$f8
.JF0f0a5978:
/*  f0a5978:	46142482 */ 	mul.s	$f18,$f4,$f20
/*  f0a597c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a5980:	c430d570 */ 	lwc1	$f16,-0x2a90($at)
/*  f0a5984:	3c014408 */ 	lui	$at,0x4408
/*  f0a5988:	44815000 */ 	mtc1	$at,$f10
/*  f0a598c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a5990:	c424d574 */ 	lwc1	$f4,-0x2a8c($at)
/*  f0a5994:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f0a5998:	460a3203 */ 	div.s	$f8,$f6,$f10
/*  f0a599c:	46044481 */ 	sub.s	$f18,$f8,$f4
/*  f0a59a0:	0c004b60 */ 	jal	random
/*  f0a59a4:	e7b200d4 */ 	swc1	$f18,0xd4($sp)
/*  f0a59a8:	44828000 */ 	mtc1	$v0,$f16
/*  f0a59ac:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a59b0:	04410004 */ 	bgez	$v0,.JF0f0a59c4
/*  f0a59b4:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0a59b8:	44815000 */ 	mtc1	$at,$f10
/*  f0a59bc:	00000000 */ 	nop
/*  f0a59c0:	460a3180 */ 	add.s	$f6,$f6,$f10
.JF0f0a59c4:
/*  f0a59c4:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f0a59c8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a59cc:	c424d578 */ 	lwc1	$f4,-0x2a88($at)
/*  f0a59d0:	3c014408 */ 	lui	$at,0x4408
/*  f0a59d4:	44818000 */ 	mtc1	$at,$f16
/*  f0a59d8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a59dc:	c426d57c */ 	lwc1	$f6,-0x2a84($at)
/*  f0a59e0:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f0a59e4:	46109283 */ 	div.s	$f10,$f18,$f16
/*  f0a59e8:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f0a59ec:	10000060 */ 	b	.JF0f0a5b70
/*  f0a59f0:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
/*  f0a59f4:	44802000 */ 	mtc1	$zero,$f4
.JF0f0a59f8:
/*  f0a59f8:	0c004b60 */ 	jal	random
/*  f0a59fc:	e60406e8 */ 	swc1	$f4,0x6e8($s0)
/*  f0a5a00:	3c014020 */ 	lui	$at,0x4020
/*  f0a5a04:	44810000 */ 	mtc1	$at,$f0
/*  f0a5a08:	44829000 */ 	mtc1	$v0,$f18
/*  f0a5a0c:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a5a10:	4481a000 */ 	mtc1	$at,$f20
/*  f0a5a14:	04410005 */ 	bgez	$v0,.JF0f0a5a2c
/*  f0a5a18:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f0a5a1c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a5a20:	44815000 */ 	mtc1	$at,$f10
/*  f0a5a24:	00000000 */ 	nop
/*  f0a5a28:	460a8400 */ 	add.s	$f16,$f16,$f10
.JF0f0a5a2c:
/*  f0a5a2c:	46148182 */ 	mul.s	$f6,$f16,$f20
/*  f0a5a30:	3c013e00 */ 	lui	$at,0x3e00
/*  f0a5a34:	44812000 */ 	mtc1	$at,$f4
/*  f0a5a38:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a5a3c:	00000000 */ 	nop
/*  f0a5a40:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f0a5a44:	46009280 */ 	add.s	$f10,$f18,$f0
/*  f0a5a48:	0c004b60 */ 	jal	random
/*  f0a5a4c:	e60a06ec */ 	swc1	$f10,0x6ec($s0)
/*  f0a5a50:	44828000 */ 	mtc1	$v0,$f16
/*  f0a5a54:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a5a58:	04410004 */ 	bgez	$v0,.JF0f0a5a6c
/*  f0a5a5c:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0a5a60:	44814000 */ 	mtc1	$at,$f8
/*  f0a5a64:	00000000 */ 	nop
/*  f0a5a68:	46083180 */ 	add.s	$f6,$f6,$f8
.JF0f0a5a6c:
/*  f0a5a6c:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f0a5a70:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a5a74:	44819000 */ 	mtc1	$at,$f18
/*  f0a5a78:	3c013e80 */ 	lui	$at,0x3e80
/*  f0a5a7c:	44818000 */ 	mtc1	$at,$f16
/*  f0a5a80:	46122280 */ 	add.s	$f10,$f4,$f18
/*  f0a5a84:	46105202 */ 	mul.s	$f8,$f10,$f16
/*  f0a5a88:	0c004b60 */ 	jal	random
/*  f0a5a8c:	e60806f0 */ 	swc1	$f8,0x6f0($s0)
/*  f0a5a90:	44823000 */ 	mtc1	$v0,$f6
/*  f0a5a94:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a5a98:	04410004 */ 	bgez	$v0,.JF0f0a5aac
/*  f0a5a9c:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0a5aa0:	44819000 */ 	mtc1	$at,$f18
/*  f0a5aa4:	00000000 */ 	nop
/*  f0a5aa8:	46122100 */ 	add.s	$f4,$f4,$f18
.JF0f0a5aac:
/*  f0a5aac:	46142282 */ 	mul.s	$f10,$f4,$f20
/*  f0a5ab0:	3c014040 */ 	lui	$at,0x4040
/*  f0a5ab4:	44818000 */ 	mtc1	$at,$f16
/*  f0a5ab8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a5abc:	c426d580 */ 	lwc1	$f6,-0x2a80($at)
/*  f0a5ac0:	3c0143b8 */ 	lui	$at,0x43b8
/*  f0a5ac4:	44812000 */ 	mtc1	$at,$f4
/*  f0a5ac8:	46105200 */ 	add.s	$f8,$f10,$f16
/*  f0a5acc:	46064482 */ 	mul.s	$f18,$f8,$f6
/*  f0a5ad0:	46049283 */ 	div.s	$f10,$f18,$f4
/*  f0a5ad4:	0c004b60 */ 	jal	random
/*  f0a5ad8:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
/*  f0a5adc:	44828000 */ 	mtc1	$v0,$f16
/*  f0a5ae0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a5ae4:	04410004 */ 	bgez	$v0,.JF0f0a5af8
/*  f0a5ae8:	46808220 */ 	cvt.s.w	$f8,$f16
/*  f0a5aec:	44813000 */ 	mtc1	$at,$f6
/*  f0a5af0:	00000000 */ 	nop
/*  f0a5af4:	46064200 */ 	add.s	$f8,$f8,$f6
.JF0f0a5af8:
/*  f0a5af8:	46144482 */ 	mul.s	$f18,$f8,$f20
/*  f0a5afc:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a5b00:	c424d584 */ 	lwc1	$f4,-0x2a7c($at)
/*  f0a5b04:	3c01446c */ 	lui	$at,0x446c
/*  f0a5b08:	44818000 */ 	mtc1	$at,$f16
/*  f0a5b0c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a5b10:	c428d588 */ 	lwc1	$f8,-0x2a78($at)
/*  f0a5b14:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0a5b18:	46105183 */ 	div.s	$f6,$f10,$f16
/*  f0a5b1c:	46083481 */ 	sub.s	$f18,$f6,$f8
/*  f0a5b20:	0c004b60 */ 	jal	random
/*  f0a5b24:	e7b200d4 */ 	swc1	$f18,0xd4($sp)
/*  f0a5b28:	44822000 */ 	mtc1	$v0,$f4
/*  f0a5b2c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a5b30:	04410004 */ 	bgez	$v0,.JF0f0a5b44
/*  f0a5b34:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0a5b38:	44818000 */ 	mtc1	$at,$f16
/*  f0a5b3c:	00000000 */ 	nop
/*  f0a5b40:	46105280 */ 	add.s	$f10,$f10,$f16
.JF0f0a5b44:
/*  f0a5b44:	46145182 */ 	mul.s	$f6,$f10,$f20
/*  f0a5b48:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a5b4c:	c428d58c */ 	lwc1	$f8,-0x2a74($at)
/*  f0a5b50:	3c01446c */ 	lui	$at,0x446c
/*  f0a5b54:	44812000 */ 	mtc1	$at,$f4
/*  f0a5b58:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a5b5c:	c42ad590 */ 	lwc1	$f10,-0x2a70($at)
/*  f0a5b60:	46083482 */ 	mul.s	$f18,$f6,$f8
/*  f0a5b64:	46049403 */ 	div.s	$f16,$f18,$f4
/*  f0a5b68:	460a8181 */ 	sub.s	$f6,$f16,$f10
/*  f0a5b6c:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
.JF0f0a5b70:
/*  f0a5b70:	3c014348 */ 	lui	$at,0x4348
.JF0f0a5b74:
/*  f0a5b74:	44819000 */ 	mtc1	$at,$f18
/*  f0a5b78:	c60806dc */ 	lwc1	$f8,0x6dc($s0)
/*  f0a5b7c:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f0a5b80:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f0a5b84:	46124101 */ 	sub.s	$f4,$f8,$f18
/*  f0a5b88:	0c00590b */ 	jal	mtx4LoadRotation
/*  f0a5b8c:	e60406d8 */ 	swc1	$f4,0x6d8($s0)
/*  f0a5b90:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0a5b94:	0c005750 */ 	jal	mtx4ToMtx3
/*  f0a5b98:	26050718 */ 	addiu	$a1,$s0,0x718
/*  f0a5b9c:	3c03800a */ 	lui	$v1,0x800a
/*  f0a5ba0:	2463a630 */ 	addiu	$v1,$v1,-22992
/*  f0a5ba4:	8c790034 */ 	lw	$t9,0x34($v1)
/*  f0a5ba8:	5b20002e */ 	blezl	$t9,.JF0f0a5c64
/*  f0a5bac:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
/*  f0a5bb0:	8e0806d4 */ 	lw	$t0,0x6d4($s0)
/*  f0a5bb4:	00084d00 */ 	sll	$t1,$t0,0x14
/*  f0a5bb8:	00095742 */ 	srl	$t2,$t1,0x1d
/*  f0a5bbc:	51400029 */ 	beqzl	$t2,.JF0f0a5c64
/*  f0a5bc0:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
/*  f0a5bc4:	c6100324 */ 	lwc1	$f16,0x324($s0)
/*  f0a5bc8:	c60a0364 */ 	lwc1	$f10,0x364($s0)
/*  f0a5bcc:	c460004c */ 	lwc1	$f0,0x4c($v1)
/*  f0a5bd0:	260402f4 */ 	addiu	$a0,$s0,0x2f4
/*  f0a5bd4:	460a8181 */ 	sub.s	$f6,$f16,$f10
/*  f0a5bd8:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0a5bdc:	46003203 */ 	div.s	$f8,$f6,$f0
/*  f0a5be0:	e7a80084 */ 	swc1	$f8,0x84($sp)
/*  f0a5be4:	c6040368 */ 	lwc1	$f4,0x368($s0)
/*  f0a5be8:	c6120328 */ 	lwc1	$f18,0x328($s0)
/*  f0a5bec:	46049401 */ 	sub.s	$f16,$f18,$f4
/*  f0a5bf0:	46008283 */ 	div.s	$f10,$f16,$f0
/*  f0a5bf4:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f0a5bf8:	c608036c */ 	lwc1	$f8,0x36c($s0)
/*  f0a5bfc:	c606032c */ 	lwc1	$f6,0x32c($s0)
/*  f0a5c00:	46083481 */ 	sub.s	$f18,$f6,$f8
/*  f0a5c04:	46009103 */ 	div.s	$f4,$f18,$f0
/*  f0a5c08:	0c005d4a */ 	jal	mtx00017588
/*  f0a5c0c:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f0a5c10:	27a40044 */ 	addiu	$a0,$sp,0x44
/*  f0a5c14:	0c0056ac */ 	jal	mtx4RotateVecInPlace
/*  f0a5c18:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f0a5c1c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a5c20:	c420d594 */ 	lwc1	$f0,-0x2a6c($at)
/*  f0a5c24:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*  f0a5c28:	c61006e8 */ 	lwc1	$f16,0x6e8($s0)
/*  f0a5c2c:	c61206ec */ 	lwc1	$f18,0x6ec($s0)
/*  f0a5c30:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f0a5c34:	46068200 */ 	add.s	$f8,$f16,$f6
/*  f0a5c38:	c60606f0 */ 	lwc1	$f6,0x6f0($s0)
/*  f0a5c3c:	e60806e8 */ 	swc1	$f8,0x6e8($s0)
/*  f0a5c40:	c7a40088 */ 	lwc1	$f4,0x88($sp)
/*  f0a5c44:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0a5c48:	460a9400 */ 	add.s	$f16,$f18,$f10
/*  f0a5c4c:	e61006ec */ 	swc1	$f16,0x6ec($s0)
/*  f0a5c50:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*  f0a5c54:	46004102 */ 	mul.s	$f4,$f8,$f0
/*  f0a5c58:	46043480 */ 	add.s	$f18,$f6,$f4
/*  f0a5c5c:	e61206f0 */ 	swc1	$f18,0x6f0($s0)
/*  f0a5c60:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
.JF0f0a5c64:
/*  f0a5c64:	316cff0f */ 	andi	$t4,$t3,0xff0f
/*  f0a5c68:	358d0020 */ 	ori	$t5,$t4,0x20
/*  f0a5c6c:	10000043 */ 	b	.JF0f0a5d7c
/*  f0a5c70:	a20d06d6 */ 	sb	$t5,0x6d6($s0)
.JF0f0a5c74:
/*  f0a5c74:	2463a630 */ 	addiu	$v1,$v1,-22992
/*  f0a5c78:	8c6e0284 */ 	lw	$t6,0x284($v1)
/*  f0a5c7c:	c460004c */ 	lwc1	$f0,0x4c($v1)
/*  f0a5c80:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f0a5c84:	8dcf00d8 */ 	lw	$t7,0xd8($t6)
/*  f0a5c88:	11e00008 */ 	beqz	$t7,.JF0f0a5cac
/*  f0a5c8c:	00000000 */ 	nop
/*  f0a5c90:	44811000 */ 	mtc1	$at,$f2
/*  f0a5c94:	00000000 */ 	nop
/*  f0a5c98:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0a5c9c:	00000000 */ 	nop
/*  f0a5ca0:	45000002 */ 	bc1f	.JF0f0a5cac
/*  f0a5ca4:	00000000 */ 	nop
/*  f0a5ca8:	46001006 */ 	mov.s	$f0,$f2
.JF0f0a5cac:
/*  f0a5cac:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a5cb0:	c42ad598 */ 	lwc1	$f10,-0x2a68($at)
/*  f0a5cb4:	c60e06e0 */ 	lwc1	$f14,0x6e0($s0)
/*  f0a5cb8:	c60806d8 */ 	lwc1	$f8,0x6d8($s0)
/*  f0a5cbc:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f0a5cc0:	c60206ec */ 	lwc1	$f2,0x6ec($s0)
/*  f0a5cc4:	4608703c */ 	c.lt.s	$f14,$f8
/*  f0a5cc8:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a5ccc:	45000006 */ 	bc1f	.JF0f0a5ce8
/*  f0a5cd0:	46101301 */ 	sub.s	$f12,$f2,$f16
/*  f0a5cd4:	921806d6 */ 	lbu	$t8,0x6d6($s0)
/*  f0a5cd8:	3319ff0f */ 	andi	$t9,$t8,0xff0f
/*  f0a5cdc:	37280030 */ 	ori	$t0,$t9,0x30
/*  f0a5ce0:	10000026 */ 	b	.JF0f0a5d7c
/*  f0a5ce4:	a20806d6 */ 	sb	$t0,0x6d6($s0)
.JF0f0a5ce8:
/*  f0a5ce8:	44813000 */ 	mtc1	$at,$f6
/*  f0a5cec:	460c1480 */ 	add.s	$f18,$f2,$f12
/*  f0a5cf0:	c60806dc */ 	lwc1	$f8,0x6dc($s0)
/*  f0a5cf4:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0a5cf8:	c60606e8 */ 	lwc1	$f6,0x6e8($s0)
/*  f0a5cfc:	e60c06ec */ 	swc1	$f12,0x6ec($s0)
/*  f0a5d00:	00001025 */ 	move	$v0,$zero
/*  f0a5d04:	26040718 */ 	addiu	$a0,$s0,0x718
/*  f0a5d08:	260506f4 */ 	addiu	$a1,$s0,0x6f4
/*  f0a5d0c:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f0a5d10:	460a7400 */ 	add.s	$f16,$f14,$f10
/*  f0a5d14:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0a5d18:	c60a06e4 */ 	lwc1	$f10,0x6e4($s0)
/*  f0a5d1c:	e61006e0 */ 	swc1	$f16,0x6e0($s0)
/*  f0a5d20:	c61006f0 */ 	lwc1	$f16,0x6f0($s0)
/*  f0a5d24:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f0a5d28:	46044480 */ 	add.s	$f18,$f8,$f4
/*  f0a5d2c:	e61206dc */ 	swc1	$f18,0x6dc($s0)
/*  f0a5d30:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0a5d34:	e60806e4 */ 	swc1	$f8,0x6e4($s0)
/*  f0a5d38:	8c690034 */ 	lw	$t1,0x34($v1)
/*  f0a5d3c:	59200010 */ 	blezl	$t1,.JF0f0a5d80
/*  f0a5d40:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0a5d44:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f0a5d48:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f0a5d4c:	8fa40030 */ 	lw	$a0,0x30($sp)
.JF0f0a5d50:
/*  f0a5d50:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f0a5d54:	0c00582c */ 	jal	mtx00016110
/*  f0a5d58:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0a5d5c:	3c03800a */ 	lui	$v1,0x800a
/*  f0a5d60:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f0a5d64:	2463a630 */ 	addiu	$v1,$v1,-22992
/*  f0a5d68:	8c6a0034 */ 	lw	$t2,0x34($v1)
/*  f0a5d6c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0a5d70:	004a082a */ 	slt	$at,$v0,$t2
/*  f0a5d74:	5420fff6 */ 	bnezl	$at,.JF0f0a5d50
/*  f0a5d78:	8fa40030 */ 	lw	$a0,0x30($sp)
.JF0f0a5d7c:
/*  f0a5d7c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.JF0f0a5d80:
/*  f0a5d80:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0a5d84:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0a5d88:	03e00008 */ 	jr	$ra
/*  f0a5d8c:	27bd00e0 */ 	addiu	$sp,$sp,0xe0
);
#elif VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel bgun0f0a46a4
.late_rodata
glabel var7f1ac8cc
.word 0x3f088888
glabel var7f1ac8d0
.word 0x41713c65
glabel var7f1ac8d4
.word 0x3d0bd8cf
glabel var7f1ac8d8
.word 0x41713c65
glabel var7f1ac8dc
.word 0x3d0bd8cf
glabel var7f1ac8e0
.word 0x41713c65
glabel var7f1ac8e4
.word 0x3d0bd8cf
glabel var7f1ac8e8
.word 0x3f088888
glabel var7f1ac8ec
.word 0x40f13c65
glabel var7f1ac8f0
.word 0x41713c65
glabel var7f1ac8f4
.word 0x3c3d3463
glabel var7f1ac8f8
.word 0x41713c65
glabel var7f1ac8fc
.word 0x3c3d3463
glabel var7f1ac900
.word 0x40f13c65
glabel var7f1ac904
.word 0x41713c65
glabel var7f1ac908
.word 0x3bda10fd
glabel var7f1ac90c
.word 0x41713c65
glabel var7f1ac910
.word 0x3bda10fd
glabel var7f1ac914
.word 0x3e99999a
glabel var7f1ac918
.word 0x3e8e38e4
.text
/*  f0a49d8:	27bdff20 */ 	addiu	$sp,$sp,-224
/*  f0a49dc:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0a49e0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0a49e4:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0a49e8:	afa500e4 */ 	sw	$a1,0xe4($sp)
/*  f0a49ec:	afa600e8 */ 	sw	$a2,0xe8($sp)
/*  f0a49f0:	948206d6 */ 	lhu	$v0,0x6d6($a0)
/*  f0a49f4:	24030001 */ 	li	$v1,0x1
/*  f0a49f8:	00808025 */ 	move	$s0,$a0
/*  f0a49fc:	00027302 */ 	srl	$t6,$v0,0xc
/*  f0a4a00:	11c30005 */ 	beq	$t6,$v1,.PF0f0a4a18
/*  f0a4a04:	24010002 */ 	li	$at,0x2
/*  f0a4a08:	11c1018d */ 	beq	$t6,$at,.PF0f0a5040
/*  f0a4a0c:	3c03800a */ 	lui	$v1,0x800a
/*  f0a4a10:	100001ce */ 	b	.PF0f0a514c
/*  f0a4a14:	8fbf0024 */ 	lw	$ra,0x24($sp)
.PF0f0a4a18:
/*  f0a4a18:	8e0206d4 */ 	lw	$v0,0x6d4($s0)
/*  f0a4a1c:	00027d00 */ 	sll	$t7,$v0,0x14
/*  f0a4a20:	000fc742 */ 	srl	$t8,$t7,0x1d
/*  f0a4a24:	13000007 */ 	beqz	$t8,.PF0f0a4a44
/*  f0a4a28:	00000000 */ 	nop
/*  f0a4a2c:	1303006c */ 	beq	$t8,$v1,.PF0f0a4be0
/*  f0a4a30:	24010002 */ 	li	$at,0x2
/*  f0a4a34:	530100e3 */ 	beql	$t8,$at,.PF0f0a4dc4
/*  f0a4a38:	44802000 */ 	mtc1	$zero,$f4
/*  f0a4a3c:	10000140 */ 	b	.PF0f0a4f40
/*  f0a4a40:	3c014348 */ 	lui	$at,0x4348
.PF0f0a4a44:
/*  f0a4a44:	0c004ad4 */ 	jal	random
/*  f0a4a48:	00000000 */ 	nop
/*  f0a4a4c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4a50:	c420dacc */ 	lwc1	$f0,-0x2534($at)
/*  f0a4a54:	44822000 */ 	mtc1	$v0,$f4
/*  f0a4a58:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a4a5c:	4481a000 */ 	mtc1	$at,$f20
/*  f0a4a60:	04410005 */ 	bgez	$v0,.PF0f0a4a78
/*  f0a4a64:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a4a68:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4a6c:	44814000 */ 	mtc1	$at,$f8
/*  f0a4a70:	00000000 */ 	nop
/*  f0a4a74:	46083180 */ 	add.s	$f6,$f6,$f8
.PF0f0a4a78:
/*  f0a4a78:	46143282 */ 	mul.s	$f10,$f6,$f20
/*  f0a4a7c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a4a80:	44818000 */ 	mtc1	$at,$f16
/*  f0a4a84:	3c013d80 */ 	lui	$at,0x3d80
/*  f0a4a88:	44814000 */ 	mtc1	$at,$f8
/*  f0a4a8c:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0a4a90:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0a4a94:	00000000 */ 	nop
/*  f0a4a98:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0a4a9c:	46003280 */ 	add.s	$f10,$f6,$f0
/*  f0a4aa0:	0c004ad4 */ 	jal	random
/*  f0a4aa4:	e60a06e8 */ 	swc1	$f10,0x6e8($s0)
/*  f0a4aa8:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4aac:	3c014020 */ 	lui	$at,0x4020
/*  f0a4ab0:	44810000 */ 	mtc1	$at,$f0
/*  f0a4ab4:	04410005 */ 	bgez	$v0,.PF0f0a4acc
/*  f0a4ab8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0a4abc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4ac0:	44812000 */ 	mtc1	$at,$f4
/*  f0a4ac4:	00000000 */ 	nop
/*  f0a4ac8:	46049480 */ 	add.s	$f18,$f18,$f4
.PF0f0a4acc:
/*  f0a4acc:	46149202 */ 	mul.s	$f8,$f18,$f20
/*  f0a4ad0:	3c013d80 */ 	lui	$at,0x3d80
/*  f0a4ad4:	44815000 */ 	mtc1	$at,$f10
/*  f0a4ad8:	44809000 */ 	mtc1	$zero,$f18
/*  f0a4adc:	00000000 */ 	nop
/*  f0a4ae0:	e61206f0 */ 	swc1	$f18,0x6f0($s0)
/*  f0a4ae4:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0a4ae8:	00000000 */ 	nop
/*  f0a4aec:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0a4af0:	46008100 */ 	add.s	$f4,$f16,$f0
/*  f0a4af4:	0c004ad4 */ 	jal	random
/*  f0a4af8:	e60406ec */ 	swc1	$f4,0x6ec($s0)
/*  f0a4afc:	44824000 */ 	mtc1	$v0,$f8
/*  f0a4b00:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4b04:	04410004 */ 	bgez	$v0,.PF0f0a4b18
/*  f0a4b08:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0a4b0c:	44815000 */ 	mtc1	$at,$f10
/*  f0a4b10:	00000000 */ 	nop
/*  f0a4b14:	460a3180 */ 	add.s	$f6,$f6,$f10
.PF0f0a4b18:
/*  f0a4b18:	46143402 */ 	mul.s	$f16,$f6,$f20
/*  f0a4b1c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4b20:	c424dad0 */ 	lwc1	$f4,-0x2530($at)
/*  f0a4b24:	3c014338 */ 	lui	$at,0x4338
/*  f0a4b28:	44814000 */ 	mtc1	$at,$f8
/*  f0a4b2c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4b30:	c426dad4 */ 	lwc1	$f6,-0x252c($at)
/*  f0a4b34:	46048482 */ 	mul.s	$f18,$f16,$f4
/*  f0a4b38:	46089283 */ 	div.s	$f10,$f18,$f8
/*  f0a4b3c:	46065401 */ 	sub.s	$f16,$f10,$f6
/*  f0a4b40:	0c004ad4 */ 	jal	random
/*  f0a4b44:	e7b000d0 */ 	swc1	$f16,0xd0($sp)
/*  f0a4b48:	44822000 */ 	mtc1	$v0,$f4
/*  f0a4b4c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4b50:	04410004 */ 	bgez	$v0,.PF0f0a4b64
/*  f0a4b54:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f0a4b58:	44814000 */ 	mtc1	$at,$f8
/*  f0a4b5c:	00000000 */ 	nop
/*  f0a4b60:	46089480 */ 	add.s	$f18,$f18,$f8
.PF0f0a4b64:
/*  f0a4b64:	46149282 */ 	mul.s	$f10,$f18,$f20
/*  f0a4b68:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4b6c:	c426dad8 */ 	lwc1	$f6,-0x2528($at)
/*  f0a4b70:	3c014338 */ 	lui	$at,0x4338
/*  f0a4b74:	44812000 */ 	mtc1	$at,$f4
/*  f0a4b78:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4b7c:	c432dadc */ 	lwc1	$f18,-0x2524($at)
/*  f0a4b80:	46065402 */ 	mul.s	$f16,$f10,$f6
/*  f0a4b84:	46048203 */ 	div.s	$f8,$f16,$f4
/*  f0a4b88:	46124281 */ 	sub.s	$f10,$f8,$f18
/*  f0a4b8c:	0c004ad4 */ 	jal	random
/*  f0a4b90:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0a4b94:	44823000 */ 	mtc1	$v0,$f6
/*  f0a4b98:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4b9c:	04410004 */ 	bgez	$v0,.PF0f0a4bb0
/*  f0a4ba0:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f0a4ba4:	44812000 */ 	mtc1	$at,$f4
/*  f0a4ba8:	00000000 */ 	nop
/*  f0a4bac:	46048400 */ 	add.s	$f16,$f16,$f4
.PF0f0a4bb0:
/*  f0a4bb0:	46148202 */ 	mul.s	$f8,$f16,$f20
/*  f0a4bb4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4bb8:	c432dae0 */ 	lwc1	$f18,-0x2520($at)
/*  f0a4bbc:	3c014338 */ 	lui	$at,0x4338
/*  f0a4bc0:	44813000 */ 	mtc1	$at,$f6
/*  f0a4bc4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4bc8:	c430dae4 */ 	lwc1	$f16,-0x251c($at)
/*  f0a4bcc:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f0a4bd0:	46065103 */ 	div.s	$f4,$f10,$f6
/*  f0a4bd4:	46102201 */ 	sub.s	$f8,$f4,$f16
/*  f0a4bd8:	100000d8 */ 	b	.PF0f0a4f3c
/*  f0a4bdc:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
.PF0f0a4be0:
/*  f0a4be0:	0c004ad4 */ 	jal	random
/*  f0a4be4:	00000000 */ 	nop
/*  f0a4be8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4bec:	c420dae8 */ 	lwc1	$f0,-0x2518($at)
/*  f0a4bf0:	44829000 */ 	mtc1	$v0,$f18
/*  f0a4bf4:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a4bf8:	4481a000 */ 	mtc1	$at,$f20
/*  f0a4bfc:	04410005 */ 	bgez	$v0,.PF0f0a4c14
/*  f0a4c00:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f0a4c04:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4c08:	44813000 */ 	mtc1	$at,$f6
/*  f0a4c0c:	00000000 */ 	nop
/*  f0a4c10:	46065280 */ 	add.s	$f10,$f10,$f6
.PF0f0a4c14:
/*  f0a4c14:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0a4c18:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a4c1c:	44818000 */ 	mtc1	$at,$f16
/*  f0a4c20:	3c013d80 */ 	lui	$at,0x3d80
/*  f0a4c24:	44813000 */ 	mtc1	$at,$f6
/*  f0a4c28:	3c014040 */ 	lui	$at,0x4040
/*  f0a4c2c:	46102201 */ 	sub.s	$f8,$f4,$f16
/*  f0a4c30:	44812000 */ 	mtc1	$at,$f4
/*  f0a4c34:	46004482 */ 	mul.s	$f18,$f8,$f0
/*  f0a4c38:	00000000 */ 	nop
/*  f0a4c3c:	46069282 */ 	mul.s	$f10,$f18,$f6
/*  f0a4c40:	00000000 */ 	nop
/*  f0a4c44:	46002402 */ 	mul.s	$f16,$f4,$f0
/*  f0a4c48:	46105200 */ 	add.s	$f8,$f10,$f16
/*  f0a4c4c:	46004487 */ 	neg.s	$f18,$f8
/*  f0a4c50:	0c004ad4 */ 	jal	random
/*  f0a4c54:	e61206e8 */ 	swc1	$f18,0x6e8($s0)
/*  f0a4c58:	44823000 */ 	mtc1	$v0,$f6
/*  f0a4c5c:	3c014020 */ 	lui	$at,0x4020
/*  f0a4c60:	44810000 */ 	mtc1	$at,$f0
/*  f0a4c64:	04410005 */ 	bgez	$v0,.PF0f0a4c7c
/*  f0a4c68:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0a4c6c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4c70:	44815000 */ 	mtc1	$at,$f10
/*  f0a4c74:	00000000 */ 	nop
/*  f0a4c78:	460a2100 */ 	add.s	$f4,$f4,$f10
.PF0f0a4c7c:
/*  f0a4c7c:	46142402 */ 	mul.s	$f16,$f4,$f20
/*  f0a4c80:	3c013e00 */ 	lui	$at,0x3e00
/*  f0a4c84:	44819000 */ 	mtc1	$at,$f18
/*  f0a4c88:	46008202 */ 	mul.s	$f8,$f16,$f0
/*  f0a4c8c:	00000000 */ 	nop
/*  f0a4c90:	46124182 */ 	mul.s	$f6,$f8,$f18
/*  f0a4c94:	46003280 */ 	add.s	$f10,$f6,$f0
/*  f0a4c98:	0c004ad4 */ 	jal	random
/*  f0a4c9c:	e60a06ec */ 	swc1	$f10,0x6ec($s0)
/*  f0a4ca0:	44822000 */ 	mtc1	$v0,$f4
/*  f0a4ca4:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4ca8:	04410004 */ 	bgez	$v0,.PF0f0a4cbc
/*  f0a4cac:	46802420 */ 	cvt.s.w	$f16,$f4
/*  f0a4cb0:	44814000 */ 	mtc1	$at,$f8
/*  f0a4cb4:	00000000 */ 	nop
/*  f0a4cb8:	46088400 */ 	add.s	$f16,$f16,$f8
.PF0f0a4cbc:
/*  f0a4cbc:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f0a4cc0:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a4cc4:	44813000 */ 	mtc1	$at,$f6
/*  f0a4cc8:	00000000 */ 	nop
/*  f0a4ccc:	46069280 */ 	add.s	$f10,$f18,$f6
/*  f0a4cd0:	46005107 */ 	neg.s	$f4,$f10
/*  f0a4cd4:	0c004ad4 */ 	jal	random
/*  f0a4cd8:	e60406f0 */ 	swc1	$f4,0x6f0($s0)
/*  f0a4cdc:	44824000 */ 	mtc1	$v0,$f8
/*  f0a4ce0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4ce4:	04410004 */ 	bgez	$v0,.PF0f0a4cf8
/*  f0a4ce8:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f0a4cec:	44819000 */ 	mtc1	$at,$f18
/*  f0a4cf0:	00000000 */ 	nop
/*  f0a4cf4:	46128400 */ 	add.s	$f16,$f16,$f18
.PF0f0a4cf8:
/*  f0a4cf8:	46148182 */ 	mul.s	$f6,$f16,$f20
/*  f0a4cfc:	3c014040 */ 	lui	$at,0x4040
/*  f0a4d00:	44815000 */ 	mtc1	$at,$f10
/*  f0a4d04:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4d08:	c428daec */ 	lwc1	$f8,-0x2514($at)
/*  f0a4d0c:	3c014350 */ 	lui	$at,0x4350
/*  f0a4d10:	44818000 */ 	mtc1	$at,$f16
/*  f0a4d14:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f0a4d18:	46082482 */ 	mul.s	$f18,$f4,$f8
/*  f0a4d1c:	46109183 */ 	div.s	$f6,$f18,$f16
/*  f0a4d20:	0c004ad4 */ 	jal	random
/*  f0a4d24:	e7a600d0 */ 	swc1	$f6,0xd0($sp)
/*  f0a4d28:	44825000 */ 	mtc1	$v0,$f10
/*  f0a4d2c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4d30:	04410004 */ 	bgez	$v0,.PF0f0a4d44
/*  f0a4d34:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0a4d38:	44814000 */ 	mtc1	$at,$f8
/*  f0a4d3c:	00000000 */ 	nop
/*  f0a4d40:	46082100 */ 	add.s	$f4,$f4,$f8
.PF0f0a4d44:
/*  f0a4d44:	46142482 */ 	mul.s	$f18,$f4,$f20
/*  f0a4d48:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4d4c:	c430daf0 */ 	lwc1	$f16,-0x2510($at)
/*  f0a4d50:	3c014408 */ 	lui	$at,0x4408
/*  f0a4d54:	44815000 */ 	mtc1	$at,$f10
/*  f0a4d58:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4d5c:	c424daf4 */ 	lwc1	$f4,-0x250c($at)
/*  f0a4d60:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f0a4d64:	460a3203 */ 	div.s	$f8,$f6,$f10
/*  f0a4d68:	46044481 */ 	sub.s	$f18,$f8,$f4
/*  f0a4d6c:	0c004ad4 */ 	jal	random
/*  f0a4d70:	e7b200d4 */ 	swc1	$f18,0xd4($sp)
/*  f0a4d74:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4d78:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4d7c:	04410004 */ 	bgez	$v0,.PF0f0a4d90
/*  f0a4d80:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0a4d84:	44815000 */ 	mtc1	$at,$f10
/*  f0a4d88:	00000000 */ 	nop
/*  f0a4d8c:	460a3180 */ 	add.s	$f6,$f6,$f10
.PF0f0a4d90:
/*  f0a4d90:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f0a4d94:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4d98:	c424daf8 */ 	lwc1	$f4,-0x2508($at)
/*  f0a4d9c:	3c014408 */ 	lui	$at,0x4408
/*  f0a4da0:	44818000 */ 	mtc1	$at,$f16
/*  f0a4da4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4da8:	c426dafc */ 	lwc1	$f6,-0x2504($at)
/*  f0a4dac:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f0a4db0:	46109283 */ 	div.s	$f10,$f18,$f16
/*  f0a4db4:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f0a4db8:	10000060 */ 	b	.PF0f0a4f3c
/*  f0a4dbc:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
/*  f0a4dc0:	44802000 */ 	mtc1	$zero,$f4
.PF0f0a4dc4:
/*  f0a4dc4:	0c004ad4 */ 	jal	random
/*  f0a4dc8:	e60406e8 */ 	swc1	$f4,0x6e8($s0)
/*  f0a4dcc:	3c014020 */ 	lui	$at,0x4020
/*  f0a4dd0:	44810000 */ 	mtc1	$at,$f0
/*  f0a4dd4:	44829000 */ 	mtc1	$v0,$f18
/*  f0a4dd8:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a4ddc:	4481a000 */ 	mtc1	$at,$f20
/*  f0a4de0:	04410005 */ 	bgez	$v0,.PF0f0a4df8
/*  f0a4de4:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f0a4de8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4dec:	44815000 */ 	mtc1	$at,$f10
/*  f0a4df0:	00000000 */ 	nop
/*  f0a4df4:	460a8400 */ 	add.s	$f16,$f16,$f10
.PF0f0a4df8:
/*  f0a4df8:	46148182 */ 	mul.s	$f6,$f16,$f20
/*  f0a4dfc:	3c013e00 */ 	lui	$at,0x3e00
/*  f0a4e00:	44812000 */ 	mtc1	$at,$f4
/*  f0a4e04:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a4e08:	00000000 */ 	nop
/*  f0a4e0c:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f0a4e10:	46009280 */ 	add.s	$f10,$f18,$f0
/*  f0a4e14:	0c004ad4 */ 	jal	random
/*  f0a4e18:	e60a06ec */ 	swc1	$f10,0x6ec($s0)
/*  f0a4e1c:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4e20:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4e24:	04410004 */ 	bgez	$v0,.PF0f0a4e38
/*  f0a4e28:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0a4e2c:	44814000 */ 	mtc1	$at,$f8
/*  f0a4e30:	00000000 */ 	nop
/*  f0a4e34:	46083180 */ 	add.s	$f6,$f6,$f8
.PF0f0a4e38:
/*  f0a4e38:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f0a4e3c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a4e40:	44819000 */ 	mtc1	$at,$f18
/*  f0a4e44:	3c013e80 */ 	lui	$at,0x3e80
/*  f0a4e48:	44818000 */ 	mtc1	$at,$f16
/*  f0a4e4c:	46122280 */ 	add.s	$f10,$f4,$f18
/*  f0a4e50:	46105202 */ 	mul.s	$f8,$f10,$f16
/*  f0a4e54:	0c004ad4 */ 	jal	random
/*  f0a4e58:	e60806f0 */ 	swc1	$f8,0x6f0($s0)
/*  f0a4e5c:	44823000 */ 	mtc1	$v0,$f6
/*  f0a4e60:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4e64:	04410004 */ 	bgez	$v0,.PF0f0a4e78
/*  f0a4e68:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0a4e6c:	44819000 */ 	mtc1	$at,$f18
/*  f0a4e70:	00000000 */ 	nop
/*  f0a4e74:	46122100 */ 	add.s	$f4,$f4,$f18
.PF0f0a4e78:
/*  f0a4e78:	46142282 */ 	mul.s	$f10,$f4,$f20
/*  f0a4e7c:	3c014040 */ 	lui	$at,0x4040
/*  f0a4e80:	44818000 */ 	mtc1	$at,$f16
/*  f0a4e84:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4e88:	c426db00 */ 	lwc1	$f6,-0x2500($at)
/*  f0a4e8c:	3c0143b8 */ 	lui	$at,0x43b8
/*  f0a4e90:	44812000 */ 	mtc1	$at,$f4
/*  f0a4e94:	46105200 */ 	add.s	$f8,$f10,$f16
/*  f0a4e98:	46064482 */ 	mul.s	$f18,$f8,$f6
/*  f0a4e9c:	46049283 */ 	div.s	$f10,$f18,$f4
/*  f0a4ea0:	0c004ad4 */ 	jal	random
/*  f0a4ea4:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
/*  f0a4ea8:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4eac:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4eb0:	04410004 */ 	bgez	$v0,.PF0f0a4ec4
/*  f0a4eb4:	46808220 */ 	cvt.s.w	$f8,$f16
/*  f0a4eb8:	44813000 */ 	mtc1	$at,$f6
/*  f0a4ebc:	00000000 */ 	nop
/*  f0a4ec0:	46064200 */ 	add.s	$f8,$f8,$f6
.PF0f0a4ec4:
/*  f0a4ec4:	46144482 */ 	mul.s	$f18,$f8,$f20
/*  f0a4ec8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4ecc:	c424db04 */ 	lwc1	$f4,-0x24fc($at)
/*  f0a4ed0:	3c01446c */ 	lui	$at,0x446c
/*  f0a4ed4:	44818000 */ 	mtc1	$at,$f16
/*  f0a4ed8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4edc:	c428db08 */ 	lwc1	$f8,-0x24f8($at)
/*  f0a4ee0:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0a4ee4:	46105183 */ 	div.s	$f6,$f10,$f16
/*  f0a4ee8:	46083481 */ 	sub.s	$f18,$f6,$f8
/*  f0a4eec:	0c004ad4 */ 	jal	random
/*  f0a4ef0:	e7b200d4 */ 	swc1	$f18,0xd4($sp)
/*  f0a4ef4:	44822000 */ 	mtc1	$v0,$f4
/*  f0a4ef8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4efc:	04410004 */ 	bgez	$v0,.PF0f0a4f10
/*  f0a4f00:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0a4f04:	44818000 */ 	mtc1	$at,$f16
/*  f0a4f08:	00000000 */ 	nop
/*  f0a4f0c:	46105280 */ 	add.s	$f10,$f10,$f16
.PF0f0a4f10:
/*  f0a4f10:	46145182 */ 	mul.s	$f6,$f10,$f20
/*  f0a4f14:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4f18:	c428db0c */ 	lwc1	$f8,-0x24f4($at)
/*  f0a4f1c:	3c01446c */ 	lui	$at,0x446c
/*  f0a4f20:	44812000 */ 	mtc1	$at,$f4
/*  f0a4f24:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4f28:	c42adb10 */ 	lwc1	$f10,-0x24f0($at)
/*  f0a4f2c:	46083482 */ 	mul.s	$f18,$f6,$f8
/*  f0a4f30:	46049403 */ 	div.s	$f16,$f18,$f4
/*  f0a4f34:	460a8181 */ 	sub.s	$f6,$f16,$f10
/*  f0a4f38:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
.PF0f0a4f3c:
/*  f0a4f3c:	3c014348 */ 	lui	$at,0x4348
.PF0f0a4f40:
/*  f0a4f40:	44819000 */ 	mtc1	$at,$f18
/*  f0a4f44:	c60806dc */ 	lwc1	$f8,0x6dc($s0)
/*  f0a4f48:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f0a4f4c:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f0a4f50:	46124101 */ 	sub.s	$f4,$f8,$f18
/*  f0a4f54:	0c005887 */ 	jal	mtx4LoadRotation
/*  f0a4f58:	e60406d8 */ 	swc1	$f4,0x6d8($s0)
/*  f0a4f5c:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0a4f60:	0c0056cc */ 	jal	mtx4ToMtx3
/*  f0a4f64:	26050718 */ 	addiu	$a1,$s0,0x718
/*  f0a4f68:	3c03800a */ 	lui	$v1,0x800a
/*  f0a4f6c:	2463a510 */ 	addiu	$v1,$v1,-23280
/*  f0a4f70:	8c790034 */ 	lw	$t9,0x34($v1)
/*  f0a4f74:	5b20002e */ 	blezl	$t9,.PF0f0a5030
/*  f0a4f78:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
/*  f0a4f7c:	8e0806d4 */ 	lw	$t0,0x6d4($s0)
/*  f0a4f80:	00084d00 */ 	sll	$t1,$t0,0x14
/*  f0a4f84:	00095742 */ 	srl	$t2,$t1,0x1d
/*  f0a4f88:	51400029 */ 	beqzl	$t2,.PF0f0a5030
/*  f0a4f8c:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
/*  f0a4f90:	c6100324 */ 	lwc1	$f16,0x324($s0)
/*  f0a4f94:	c60a0364 */ 	lwc1	$f10,0x364($s0)
/*  f0a4f98:	c460004c */ 	lwc1	$f0,0x4c($v1)
/*  f0a4f9c:	260402f4 */ 	addiu	$a0,$s0,0x2f4
/*  f0a4fa0:	460a8181 */ 	sub.s	$f6,$f16,$f10
/*  f0a4fa4:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0a4fa8:	46003203 */ 	div.s	$f8,$f6,$f0
/*  f0a4fac:	e7a80084 */ 	swc1	$f8,0x84($sp)
/*  f0a4fb0:	c6040368 */ 	lwc1	$f4,0x368($s0)
/*  f0a4fb4:	c6120328 */ 	lwc1	$f18,0x328($s0)
/*  f0a4fb8:	46049401 */ 	sub.s	$f16,$f18,$f4
/*  f0a4fbc:	46008283 */ 	div.s	$f10,$f16,$f0
/*  f0a4fc0:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f0a4fc4:	c608036c */ 	lwc1	$f8,0x36c($s0)
/*  f0a4fc8:	c606032c */ 	lwc1	$f6,0x32c($s0)
/*  f0a4fcc:	46083481 */ 	sub.s	$f18,$f6,$f8
/*  f0a4fd0:	46009103 */ 	div.s	$f4,$f18,$f0
/*  f0a4fd4:	0c005cc6 */ 	jal	mtx00017588
/*  f0a4fd8:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f0a4fdc:	27a40044 */ 	addiu	$a0,$sp,0x44
/*  f0a4fe0:	0c005628 */ 	jal	mtx4RotateVecInPlace
/*  f0a4fe4:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f0a4fe8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4fec:	c420db14 */ 	lwc1	$f0,-0x24ec($at)
/*  f0a4ff0:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*  f0a4ff4:	c61006e8 */ 	lwc1	$f16,0x6e8($s0)
/*  f0a4ff8:	c61206ec */ 	lwc1	$f18,0x6ec($s0)
/*  f0a4ffc:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f0a5000:	46068200 */ 	add.s	$f8,$f16,$f6
/*  f0a5004:	c60606f0 */ 	lwc1	$f6,0x6f0($s0)
/*  f0a5008:	e60806e8 */ 	swc1	$f8,0x6e8($s0)
/*  f0a500c:	c7a40088 */ 	lwc1	$f4,0x88($sp)
/*  f0a5010:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0a5014:	460a9400 */ 	add.s	$f16,$f18,$f10
/*  f0a5018:	e61006ec */ 	swc1	$f16,0x6ec($s0)
/*  f0a501c:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*  f0a5020:	46004102 */ 	mul.s	$f4,$f8,$f0
/*  f0a5024:	46043480 */ 	add.s	$f18,$f6,$f4
/*  f0a5028:	e61206f0 */ 	swc1	$f18,0x6f0($s0)
/*  f0a502c:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
.PF0f0a5030:
/*  f0a5030:	316cff0f */ 	andi	$t4,$t3,0xff0f
/*  f0a5034:	358d0020 */ 	ori	$t5,$t4,0x20
/*  f0a5038:	10000043 */ 	b	.PF0f0a5148
/*  f0a503c:	a20d06d6 */ 	sb	$t5,0x6d6($s0)
.PF0f0a5040:
/*  f0a5040:	2463a510 */ 	addiu	$v1,$v1,-23280
/*  f0a5044:	8c6e0284 */ 	lw	$t6,0x284($v1)
/*  f0a5048:	c460004c */ 	lwc1	$f0,0x4c($v1)
/*  f0a504c:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f0a5050:	8dcf00d8 */ 	lw	$t7,0xd8($t6)
/*  f0a5054:	11e00008 */ 	beqz	$t7,.PF0f0a5078
/*  f0a5058:	00000000 */ 	nop
/*  f0a505c:	44811000 */ 	mtc1	$at,$f2
/*  f0a5060:	00000000 */ 	nop
/*  f0a5064:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0a5068:	00000000 */ 	nop
/*  f0a506c:	45000002 */ 	bc1f	.PF0f0a5078
/*  f0a5070:	00000000 */ 	nop
/*  f0a5074:	46001006 */ 	mov.s	$f0,$f2
.PF0f0a5078:
/*  f0a5078:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a507c:	c42adb18 */ 	lwc1	$f10,-0x24e8($at)
/*  f0a5080:	c60e06e0 */ 	lwc1	$f14,0x6e0($s0)
/*  f0a5084:	c60806d8 */ 	lwc1	$f8,0x6d8($s0)
/*  f0a5088:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f0a508c:	c60206ec */ 	lwc1	$f2,0x6ec($s0)
/*  f0a5090:	4608703c */ 	c.lt.s	$f14,$f8
/*  f0a5094:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a5098:	45000006 */ 	bc1f	.PF0f0a50b4
/*  f0a509c:	46101301 */ 	sub.s	$f12,$f2,$f16
/*  f0a50a0:	921806d6 */ 	lbu	$t8,0x6d6($s0)
/*  f0a50a4:	3319ff0f */ 	andi	$t9,$t8,0xff0f
/*  f0a50a8:	37280030 */ 	ori	$t0,$t9,0x30
/*  f0a50ac:	10000026 */ 	b	.PF0f0a5148
/*  f0a50b0:	a20806d6 */ 	sb	$t0,0x6d6($s0)
.PF0f0a50b4:
/*  f0a50b4:	44813000 */ 	mtc1	$at,$f6
/*  f0a50b8:	460c1480 */ 	add.s	$f18,$f2,$f12
/*  f0a50bc:	c60806dc */ 	lwc1	$f8,0x6dc($s0)
/*  f0a50c0:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0a50c4:	c60606e8 */ 	lwc1	$f6,0x6e8($s0)
/*  f0a50c8:	e60c06ec */ 	swc1	$f12,0x6ec($s0)
/*  f0a50cc:	00001025 */ 	move	$v0,$zero
/*  f0a50d0:	26040718 */ 	addiu	$a0,$s0,0x718
/*  f0a50d4:	260506f4 */ 	addiu	$a1,$s0,0x6f4
/*  f0a50d8:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f0a50dc:	460a7400 */ 	add.s	$f16,$f14,$f10
/*  f0a50e0:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0a50e4:	c60a06e4 */ 	lwc1	$f10,0x6e4($s0)
/*  f0a50e8:	e61006e0 */ 	swc1	$f16,0x6e0($s0)
/*  f0a50ec:	c61006f0 */ 	lwc1	$f16,0x6f0($s0)
/*  f0a50f0:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f0a50f4:	46044480 */ 	add.s	$f18,$f8,$f4
/*  f0a50f8:	e61206dc */ 	swc1	$f18,0x6dc($s0)
/*  f0a50fc:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0a5100:	e60806e4 */ 	swc1	$f8,0x6e4($s0)
/*  f0a5104:	8c690034 */ 	lw	$t1,0x34($v1)
/*  f0a5108:	59200010 */ 	blezl	$t1,.PF0f0a514c
/*  f0a510c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0a5110:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f0a5114:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f0a5118:	8fa40030 */ 	lw	$a0,0x30($sp)
.PF0f0a511c:
/*  f0a511c:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f0a5120:	0c0057a8 */ 	jal	mtx00016110
/*  f0a5124:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0a5128:	3c03800a */ 	lui	$v1,0x800a
/*  f0a512c:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f0a5130:	2463a510 */ 	addiu	$v1,$v1,-23280
/*  f0a5134:	8c6a0034 */ 	lw	$t2,0x34($v1)
/*  f0a5138:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0a513c:	004a082a */ 	slt	$at,$v0,$t2
/*  f0a5140:	5420fff6 */ 	bnezl	$at,.PF0f0a511c
/*  f0a5144:	8fa40030 */ 	lw	$a0,0x30($sp)
.PF0f0a5148:
/*  f0a5148:	8fbf0024 */ 	lw	$ra,0x24($sp)
.PF0f0a514c:
/*  f0a514c:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0a5150:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0a5154:	03e00008 */ 	jr	$ra
/*  f0a5158:	27bd00e0 */ 	addiu	$sp,$sp,0xe0
);
#elif VERSION >= VERSION_PAL_BETA
GLOBAL_ASM(
glabel bgun0f0a46a4
.late_rodata
glabel var7f1ac8cc
.word 0x3f088888
glabel var7f1ac8d0
.word 0x41713c65
glabel var7f1ac8d4
.word 0x3d0bd8cf
glabel var7f1ac8d8
.word 0x41713c65
glabel var7f1ac8dc
.word 0x3d0bd8cf
glabel var7f1ac8e0
.word 0x41713c65
glabel var7f1ac8e4
.word 0x3d0bd8cf
glabel var7f1ac8e8
.word 0x3f088888
glabel var7f1ac8ec
.word 0x40f13c65
glabel var7f1ac8f0
.word 0x41713c65
glabel var7f1ac8f4
.word 0x3c3d3463
glabel var7f1ac8f8
.word 0x41713c65
glabel var7f1ac8fc
.word 0x3c3d3463
glabel var7f1ac900
.word 0x40f13c65
glabel var7f1ac904
.word 0x41713c65
glabel var7f1ac908
.word 0x3bda10fd
glabel var7f1ac90c
.word 0x41713c65
glabel var7f1ac910
.word 0x3bda10fd
glabel var7f1ac914
.word 0x3e99999a
glabel var7f1ac918
.word 0x3e8e38e4
.text
/*  f0a4928:	27bdff20 */ 	addiu	$sp,$sp,-224
/*  f0a492c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0a4930:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0a4934:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0a4938:	afa500e4 */ 	sw	$a1,0xe4($sp)
/*  f0a493c:	afa600e8 */ 	sw	$a2,0xe8($sp)
/*  f0a4940:	948206d6 */ 	lhu	$v0,0x6d6($a0)
/*  f0a4944:	24030001 */ 	li	$v1,0x1
/*  f0a4948:	00808025 */ 	move	$s0,$a0
/*  f0a494c:	00027302 */ 	srl	$t6,$v0,0xc
/*  f0a4950:	11c30005 */ 	beq	$t6,$v1,.PB0f0a4968
/*  f0a4954:	24010002 */ 	li	$at,0x2
/*  f0a4958:	11c1018d */ 	beq	$t6,$at,.PB0f0a4f90
/*  f0a495c:	3c03800a */ 	lui	$v1,0x800a
/*  f0a4960:	100001ce */ 	b	.PB0f0a509c
/*  f0a4964:	8fbf0024 */ 	lw	$ra,0x24($sp)
.PB0f0a4968:
/*  f0a4968:	8e0206d4 */ 	lw	$v0,0x6d4($s0)
/*  f0a496c:	00027d00 */ 	sll	$t7,$v0,0x14
/*  f0a4970:	000fc742 */ 	srl	$t8,$t7,0x1d
/*  f0a4974:	13000007 */ 	beqz	$t8,.PB0f0a4994
/*  f0a4978:	00000000 */ 	nop
/*  f0a497c:	1303006c */ 	beq	$t8,$v1,.PB0f0a4b30
/*  f0a4980:	24010002 */ 	li	$at,0x2
/*  f0a4984:	530100e3 */ 	beql	$t8,$at,.PB0f0a4d14
/*  f0a4988:	44802000 */ 	mtc1	$zero,$f4
/*  f0a498c:	10000140 */ 	b	.PB0f0a4e90
/*  f0a4990:	3c014348 */ 	lui	$at,0x4348
.PB0f0a4994:
/*  f0a4994:	0c004be0 */ 	jal	random
/*  f0a4998:	00000000 */ 	nop
/*  f0a499c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a49a0:	c420e51c */ 	lwc1	$f0,-0x1ae4($at)
/*  f0a49a4:	44822000 */ 	mtc1	$v0,$f4
/*  f0a49a8:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a49ac:	4481a000 */ 	mtc1	$at,$f20
/*  f0a49b0:	04410005 */ 	bgez	$v0,.PB0f0a49c8
/*  f0a49b4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a49b8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a49bc:	44814000 */ 	mtc1	$at,$f8
/*  f0a49c0:	00000000 */ 	nop
/*  f0a49c4:	46083180 */ 	add.s	$f6,$f6,$f8
.PB0f0a49c8:
/*  f0a49c8:	46143282 */ 	mul.s	$f10,$f6,$f20
/*  f0a49cc:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a49d0:	44818000 */ 	mtc1	$at,$f16
/*  f0a49d4:	3c013d80 */ 	lui	$at,0x3d80
/*  f0a49d8:	44814000 */ 	mtc1	$at,$f8
/*  f0a49dc:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0a49e0:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0a49e4:	00000000 */ 	nop
/*  f0a49e8:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0a49ec:	46003280 */ 	add.s	$f10,$f6,$f0
/*  f0a49f0:	0c004be0 */ 	jal	random
/*  f0a49f4:	e60a06e8 */ 	swc1	$f10,0x6e8($s0)
/*  f0a49f8:	44828000 */ 	mtc1	$v0,$f16
/*  f0a49fc:	3c014020 */ 	lui	$at,0x4020
/*  f0a4a00:	44810000 */ 	mtc1	$at,$f0
/*  f0a4a04:	04410005 */ 	bgez	$v0,.PB0f0a4a1c
/*  f0a4a08:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0a4a0c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4a10:	44812000 */ 	mtc1	$at,$f4
/*  f0a4a14:	00000000 */ 	nop
/*  f0a4a18:	46049480 */ 	add.s	$f18,$f18,$f4
.PB0f0a4a1c:
/*  f0a4a1c:	46149202 */ 	mul.s	$f8,$f18,$f20
/*  f0a4a20:	3c013d80 */ 	lui	$at,0x3d80
/*  f0a4a24:	44815000 */ 	mtc1	$at,$f10
/*  f0a4a28:	44809000 */ 	mtc1	$zero,$f18
/*  f0a4a2c:	00000000 */ 	nop
/*  f0a4a30:	e61206f0 */ 	swc1	$f18,0x6f0($s0)
/*  f0a4a34:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0a4a38:	00000000 */ 	nop
/*  f0a4a3c:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0a4a40:	46008100 */ 	add.s	$f4,$f16,$f0
/*  f0a4a44:	0c004be0 */ 	jal	random
/*  f0a4a48:	e60406ec */ 	swc1	$f4,0x6ec($s0)
/*  f0a4a4c:	44824000 */ 	mtc1	$v0,$f8
/*  f0a4a50:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4a54:	04410004 */ 	bgez	$v0,.PB0f0a4a68
/*  f0a4a58:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0a4a5c:	44815000 */ 	mtc1	$at,$f10
/*  f0a4a60:	00000000 */ 	nop
/*  f0a4a64:	460a3180 */ 	add.s	$f6,$f6,$f10
.PB0f0a4a68:
/*  f0a4a68:	46143402 */ 	mul.s	$f16,$f6,$f20
/*  f0a4a6c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4a70:	c424e520 */ 	lwc1	$f4,-0x1ae0($at)
/*  f0a4a74:	3c014338 */ 	lui	$at,0x4338
/*  f0a4a78:	44814000 */ 	mtc1	$at,$f8
/*  f0a4a7c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4a80:	c426e524 */ 	lwc1	$f6,-0x1adc($at)
/*  f0a4a84:	46048482 */ 	mul.s	$f18,$f16,$f4
/*  f0a4a88:	46089283 */ 	div.s	$f10,$f18,$f8
/*  f0a4a8c:	46065401 */ 	sub.s	$f16,$f10,$f6
/*  f0a4a90:	0c004be0 */ 	jal	random
/*  f0a4a94:	e7b000d0 */ 	swc1	$f16,0xd0($sp)
/*  f0a4a98:	44822000 */ 	mtc1	$v0,$f4
/*  f0a4a9c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4aa0:	04410004 */ 	bgez	$v0,.PB0f0a4ab4
/*  f0a4aa4:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f0a4aa8:	44814000 */ 	mtc1	$at,$f8
/*  f0a4aac:	00000000 */ 	nop
/*  f0a4ab0:	46089480 */ 	add.s	$f18,$f18,$f8
.PB0f0a4ab4:
/*  f0a4ab4:	46149282 */ 	mul.s	$f10,$f18,$f20
/*  f0a4ab8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4abc:	c426e528 */ 	lwc1	$f6,-0x1ad8($at)
/*  f0a4ac0:	3c014338 */ 	lui	$at,0x4338
/*  f0a4ac4:	44812000 */ 	mtc1	$at,$f4
/*  f0a4ac8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4acc:	c432e52c */ 	lwc1	$f18,-0x1ad4($at)
/*  f0a4ad0:	46065402 */ 	mul.s	$f16,$f10,$f6
/*  f0a4ad4:	46048203 */ 	div.s	$f8,$f16,$f4
/*  f0a4ad8:	46124281 */ 	sub.s	$f10,$f8,$f18
/*  f0a4adc:	0c004be0 */ 	jal	random
/*  f0a4ae0:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0a4ae4:	44823000 */ 	mtc1	$v0,$f6
/*  f0a4ae8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4aec:	04410004 */ 	bgez	$v0,.PB0f0a4b00
/*  f0a4af0:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f0a4af4:	44812000 */ 	mtc1	$at,$f4
/*  f0a4af8:	00000000 */ 	nop
/*  f0a4afc:	46048400 */ 	add.s	$f16,$f16,$f4
.PB0f0a4b00:
/*  f0a4b00:	46148202 */ 	mul.s	$f8,$f16,$f20
/*  f0a4b04:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4b08:	c432e530 */ 	lwc1	$f18,-0x1ad0($at)
/*  f0a4b0c:	3c014338 */ 	lui	$at,0x4338
/*  f0a4b10:	44813000 */ 	mtc1	$at,$f6
/*  f0a4b14:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4b18:	c430e534 */ 	lwc1	$f16,-0x1acc($at)
/*  f0a4b1c:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f0a4b20:	46065103 */ 	div.s	$f4,$f10,$f6
/*  f0a4b24:	46102201 */ 	sub.s	$f8,$f4,$f16
/*  f0a4b28:	100000d8 */ 	b	.PB0f0a4e8c
/*  f0a4b2c:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
.PB0f0a4b30:
/*  f0a4b30:	0c004be0 */ 	jal	random
/*  f0a4b34:	00000000 */ 	nop
/*  f0a4b38:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4b3c:	c420e538 */ 	lwc1	$f0,-0x1ac8($at)
/*  f0a4b40:	44829000 */ 	mtc1	$v0,$f18
/*  f0a4b44:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a4b48:	4481a000 */ 	mtc1	$at,$f20
/*  f0a4b4c:	04410005 */ 	bgez	$v0,.PB0f0a4b64
/*  f0a4b50:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f0a4b54:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4b58:	44813000 */ 	mtc1	$at,$f6
/*  f0a4b5c:	00000000 */ 	nop
/*  f0a4b60:	46065280 */ 	add.s	$f10,$f10,$f6
.PB0f0a4b64:
/*  f0a4b64:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0a4b68:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a4b6c:	44818000 */ 	mtc1	$at,$f16
/*  f0a4b70:	3c013d80 */ 	lui	$at,0x3d80
/*  f0a4b74:	44813000 */ 	mtc1	$at,$f6
/*  f0a4b78:	3c014040 */ 	lui	$at,0x4040
/*  f0a4b7c:	46102201 */ 	sub.s	$f8,$f4,$f16
/*  f0a4b80:	44812000 */ 	mtc1	$at,$f4
/*  f0a4b84:	46004482 */ 	mul.s	$f18,$f8,$f0
/*  f0a4b88:	00000000 */ 	nop
/*  f0a4b8c:	46069282 */ 	mul.s	$f10,$f18,$f6
/*  f0a4b90:	00000000 */ 	nop
/*  f0a4b94:	46002402 */ 	mul.s	$f16,$f4,$f0
/*  f0a4b98:	46105200 */ 	add.s	$f8,$f10,$f16
/*  f0a4b9c:	46004487 */ 	neg.s	$f18,$f8
/*  f0a4ba0:	0c004be0 */ 	jal	random
/*  f0a4ba4:	e61206e8 */ 	swc1	$f18,0x6e8($s0)
/*  f0a4ba8:	44823000 */ 	mtc1	$v0,$f6
/*  f0a4bac:	3c014020 */ 	lui	$at,0x4020
/*  f0a4bb0:	44810000 */ 	mtc1	$at,$f0
/*  f0a4bb4:	04410005 */ 	bgez	$v0,.PB0f0a4bcc
/*  f0a4bb8:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0a4bbc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4bc0:	44815000 */ 	mtc1	$at,$f10
/*  f0a4bc4:	00000000 */ 	nop
/*  f0a4bc8:	460a2100 */ 	add.s	$f4,$f4,$f10
.PB0f0a4bcc:
/*  f0a4bcc:	46142402 */ 	mul.s	$f16,$f4,$f20
/*  f0a4bd0:	3c013e00 */ 	lui	$at,0x3e00
/*  f0a4bd4:	44819000 */ 	mtc1	$at,$f18
/*  f0a4bd8:	46008202 */ 	mul.s	$f8,$f16,$f0
/*  f0a4bdc:	00000000 */ 	nop
/*  f0a4be0:	46124182 */ 	mul.s	$f6,$f8,$f18
/*  f0a4be4:	46003280 */ 	add.s	$f10,$f6,$f0
/*  f0a4be8:	0c004be0 */ 	jal	random
/*  f0a4bec:	e60a06ec */ 	swc1	$f10,0x6ec($s0)
/*  f0a4bf0:	44822000 */ 	mtc1	$v0,$f4
/*  f0a4bf4:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4bf8:	04410004 */ 	bgez	$v0,.PB0f0a4c0c
/*  f0a4bfc:	46802420 */ 	cvt.s.w	$f16,$f4
/*  f0a4c00:	44814000 */ 	mtc1	$at,$f8
/*  f0a4c04:	00000000 */ 	nop
/*  f0a4c08:	46088400 */ 	add.s	$f16,$f16,$f8
.PB0f0a4c0c:
/*  f0a4c0c:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f0a4c10:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a4c14:	44813000 */ 	mtc1	$at,$f6
/*  f0a4c18:	00000000 */ 	nop
/*  f0a4c1c:	46069280 */ 	add.s	$f10,$f18,$f6
/*  f0a4c20:	46005107 */ 	neg.s	$f4,$f10
/*  f0a4c24:	0c004be0 */ 	jal	random
/*  f0a4c28:	e60406f0 */ 	swc1	$f4,0x6f0($s0)
/*  f0a4c2c:	44824000 */ 	mtc1	$v0,$f8
/*  f0a4c30:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4c34:	04410004 */ 	bgez	$v0,.PB0f0a4c48
/*  f0a4c38:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f0a4c3c:	44819000 */ 	mtc1	$at,$f18
/*  f0a4c40:	00000000 */ 	nop
/*  f0a4c44:	46128400 */ 	add.s	$f16,$f16,$f18
.PB0f0a4c48:
/*  f0a4c48:	46148182 */ 	mul.s	$f6,$f16,$f20
/*  f0a4c4c:	3c014040 */ 	lui	$at,0x4040
/*  f0a4c50:	44815000 */ 	mtc1	$at,$f10
/*  f0a4c54:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4c58:	c428e53c */ 	lwc1	$f8,-0x1ac4($at)
/*  f0a4c5c:	3c014350 */ 	lui	$at,0x4350
/*  f0a4c60:	44818000 */ 	mtc1	$at,$f16
/*  f0a4c64:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f0a4c68:	46082482 */ 	mul.s	$f18,$f4,$f8
/*  f0a4c6c:	46109183 */ 	div.s	$f6,$f18,$f16
/*  f0a4c70:	0c004be0 */ 	jal	random
/*  f0a4c74:	e7a600d0 */ 	swc1	$f6,0xd0($sp)
/*  f0a4c78:	44825000 */ 	mtc1	$v0,$f10
/*  f0a4c7c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4c80:	04410004 */ 	bgez	$v0,.PB0f0a4c94
/*  f0a4c84:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0a4c88:	44814000 */ 	mtc1	$at,$f8
/*  f0a4c8c:	00000000 */ 	nop
/*  f0a4c90:	46082100 */ 	add.s	$f4,$f4,$f8
.PB0f0a4c94:
/*  f0a4c94:	46142482 */ 	mul.s	$f18,$f4,$f20
/*  f0a4c98:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4c9c:	c430e540 */ 	lwc1	$f16,-0x1ac0($at)
/*  f0a4ca0:	3c014408 */ 	lui	$at,0x4408
/*  f0a4ca4:	44815000 */ 	mtc1	$at,$f10
/*  f0a4ca8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4cac:	c424e544 */ 	lwc1	$f4,-0x1abc($at)
/*  f0a4cb0:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f0a4cb4:	460a3203 */ 	div.s	$f8,$f6,$f10
/*  f0a4cb8:	46044481 */ 	sub.s	$f18,$f8,$f4
/*  f0a4cbc:	0c004be0 */ 	jal	random
/*  f0a4cc0:	e7b200d4 */ 	swc1	$f18,0xd4($sp)
/*  f0a4cc4:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4cc8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4ccc:	04410004 */ 	bgez	$v0,.PB0f0a4ce0
/*  f0a4cd0:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0a4cd4:	44815000 */ 	mtc1	$at,$f10
/*  f0a4cd8:	00000000 */ 	nop
/*  f0a4cdc:	460a3180 */ 	add.s	$f6,$f6,$f10
.PB0f0a4ce0:
/*  f0a4ce0:	46143202 */ 	mul.s	$f8,$f6,$f20
/*  f0a4ce4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4ce8:	c424e548 */ 	lwc1	$f4,-0x1ab8($at)
/*  f0a4cec:	3c014408 */ 	lui	$at,0x4408
/*  f0a4cf0:	44818000 */ 	mtc1	$at,$f16
/*  f0a4cf4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4cf8:	c426e54c */ 	lwc1	$f6,-0x1ab4($at)
/*  f0a4cfc:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f0a4d00:	46109283 */ 	div.s	$f10,$f18,$f16
/*  f0a4d04:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f0a4d08:	10000060 */ 	b	.PB0f0a4e8c
/*  f0a4d0c:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
/*  f0a4d10:	44802000 */ 	mtc1	$zero,$f4
.PB0f0a4d14:
/*  f0a4d14:	0c004be0 */ 	jal	random
/*  f0a4d18:	e60406e8 */ 	swc1	$f4,0x6e8($s0)
/*  f0a4d1c:	3c014020 */ 	lui	$at,0x4020
/*  f0a4d20:	44810000 */ 	mtc1	$at,$f0
/*  f0a4d24:	44829000 */ 	mtc1	$v0,$f18
/*  f0a4d28:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a4d2c:	4481a000 */ 	mtc1	$at,$f20
/*  f0a4d30:	04410005 */ 	bgez	$v0,.PB0f0a4d48
/*  f0a4d34:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f0a4d38:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4d3c:	44815000 */ 	mtc1	$at,$f10
/*  f0a4d40:	00000000 */ 	nop
/*  f0a4d44:	460a8400 */ 	add.s	$f16,$f16,$f10
.PB0f0a4d48:
/*  f0a4d48:	46148182 */ 	mul.s	$f6,$f16,$f20
/*  f0a4d4c:	3c013e00 */ 	lui	$at,0x3e00
/*  f0a4d50:	44812000 */ 	mtc1	$at,$f4
/*  f0a4d54:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a4d58:	00000000 */ 	nop
/*  f0a4d5c:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f0a4d60:	46009280 */ 	add.s	$f10,$f18,$f0
/*  f0a4d64:	0c004be0 */ 	jal	random
/*  f0a4d68:	e60a06ec */ 	swc1	$f10,0x6ec($s0)
/*  f0a4d6c:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4d70:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4d74:	04410004 */ 	bgez	$v0,.PB0f0a4d88
/*  f0a4d78:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0a4d7c:	44814000 */ 	mtc1	$at,$f8
/*  f0a4d80:	00000000 */ 	nop
/*  f0a4d84:	46083180 */ 	add.s	$f6,$f6,$f8
.PB0f0a4d88:
/*  f0a4d88:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f0a4d8c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a4d90:	44819000 */ 	mtc1	$at,$f18
/*  f0a4d94:	3c013e80 */ 	lui	$at,0x3e80
/*  f0a4d98:	44818000 */ 	mtc1	$at,$f16
/*  f0a4d9c:	46122280 */ 	add.s	$f10,$f4,$f18
/*  f0a4da0:	46105202 */ 	mul.s	$f8,$f10,$f16
/*  f0a4da4:	0c004be0 */ 	jal	random
/*  f0a4da8:	e60806f0 */ 	swc1	$f8,0x6f0($s0)
/*  f0a4dac:	44823000 */ 	mtc1	$v0,$f6
/*  f0a4db0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4db4:	04410004 */ 	bgez	$v0,.PB0f0a4dc8
/*  f0a4db8:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0a4dbc:	44819000 */ 	mtc1	$at,$f18
/*  f0a4dc0:	00000000 */ 	nop
/*  f0a4dc4:	46122100 */ 	add.s	$f4,$f4,$f18
.PB0f0a4dc8:
/*  f0a4dc8:	46142282 */ 	mul.s	$f10,$f4,$f20
/*  f0a4dcc:	3c014040 */ 	lui	$at,0x4040
/*  f0a4dd0:	44818000 */ 	mtc1	$at,$f16
/*  f0a4dd4:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4dd8:	c426e550 */ 	lwc1	$f6,-0x1ab0($at)
/*  f0a4ddc:	3c0143b8 */ 	lui	$at,0x43b8
/*  f0a4de0:	44812000 */ 	mtc1	$at,$f4
/*  f0a4de4:	46105200 */ 	add.s	$f8,$f10,$f16
/*  f0a4de8:	46064482 */ 	mul.s	$f18,$f8,$f6
/*  f0a4dec:	46049283 */ 	div.s	$f10,$f18,$f4
/*  f0a4df0:	0c004be0 */ 	jal	random
/*  f0a4df4:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
/*  f0a4df8:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4dfc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4e00:	04410004 */ 	bgez	$v0,.PB0f0a4e14
/*  f0a4e04:	46808220 */ 	cvt.s.w	$f8,$f16
/*  f0a4e08:	44813000 */ 	mtc1	$at,$f6
/*  f0a4e0c:	00000000 */ 	nop
/*  f0a4e10:	46064200 */ 	add.s	$f8,$f8,$f6
.PB0f0a4e14:
/*  f0a4e14:	46144482 */ 	mul.s	$f18,$f8,$f20
/*  f0a4e18:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4e1c:	c424e554 */ 	lwc1	$f4,-0x1aac($at)
/*  f0a4e20:	3c01446c */ 	lui	$at,0x446c
/*  f0a4e24:	44818000 */ 	mtc1	$at,$f16
/*  f0a4e28:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4e2c:	c428e558 */ 	lwc1	$f8,-0x1aa8($at)
/*  f0a4e30:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0a4e34:	46105183 */ 	div.s	$f6,$f10,$f16
/*  f0a4e38:	46083481 */ 	sub.s	$f18,$f6,$f8
/*  f0a4e3c:	0c004be0 */ 	jal	random
/*  f0a4e40:	e7b200d4 */ 	swc1	$f18,0xd4($sp)
/*  f0a4e44:	44822000 */ 	mtc1	$v0,$f4
/*  f0a4e48:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4e4c:	04410004 */ 	bgez	$v0,.PB0f0a4e60
/*  f0a4e50:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0a4e54:	44818000 */ 	mtc1	$at,$f16
/*  f0a4e58:	00000000 */ 	nop
/*  f0a4e5c:	46105280 */ 	add.s	$f10,$f10,$f16
.PB0f0a4e60:
/*  f0a4e60:	46145182 */ 	mul.s	$f6,$f10,$f20
/*  f0a4e64:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4e68:	c428e55c */ 	lwc1	$f8,-0x1aa4($at)
/*  f0a4e6c:	3c01446c */ 	lui	$at,0x446c
/*  f0a4e70:	44812000 */ 	mtc1	$at,$f4
/*  f0a4e74:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4e78:	c42ae560 */ 	lwc1	$f10,-0x1aa0($at)
/*  f0a4e7c:	46083482 */ 	mul.s	$f18,$f6,$f8
/*  f0a4e80:	46049403 */ 	div.s	$f16,$f18,$f4
/*  f0a4e84:	460a8181 */ 	sub.s	$f6,$f16,$f10
/*  f0a4e88:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
.PB0f0a4e8c:
/*  f0a4e8c:	3c014348 */ 	lui	$at,0x4348
.PB0f0a4e90:
/*  f0a4e90:	44819000 */ 	mtc1	$at,$f18
/*  f0a4e94:	c60806dc */ 	lwc1	$f8,0x6dc($s0)
/*  f0a4e98:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f0a4e9c:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f0a4ea0:	46124101 */ 	sub.s	$f4,$f8,$f18
/*  f0a4ea4:	0c005bb7 */ 	jal	mtx4LoadRotation
/*  f0a4ea8:	e60406d8 */ 	swc1	$f4,0x6d8($s0)
/*  f0a4eac:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0a4eb0:	0c0059fc */ 	jal	mtx4ToMtx3
/*  f0a4eb4:	26050718 */ 	addiu	$a1,$s0,0x718
/*  f0a4eb8:	3c03800a */ 	lui	$v1,0x800a
/*  f0a4ebc:	2463e4d0 */ 	addiu	$v1,$v1,-6960
/*  f0a4ec0:	8c790034 */ 	lw	$t9,0x34($v1)
/*  f0a4ec4:	5b20002e */ 	blezl	$t9,.PB0f0a4f80
/*  f0a4ec8:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
/*  f0a4ecc:	8e0806d4 */ 	lw	$t0,0x6d4($s0)
/*  f0a4ed0:	00084d00 */ 	sll	$t1,$t0,0x14
/*  f0a4ed4:	00095742 */ 	srl	$t2,$t1,0x1d
/*  f0a4ed8:	51400029 */ 	beqzl	$t2,.PB0f0a4f80
/*  f0a4edc:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
/*  f0a4ee0:	c6100324 */ 	lwc1	$f16,0x324($s0)
/*  f0a4ee4:	c60a0364 */ 	lwc1	$f10,0x364($s0)
/*  f0a4ee8:	c460004c */ 	lwc1	$f0,0x4c($v1)
/*  f0a4eec:	260402f4 */ 	addiu	$a0,$s0,0x2f4
/*  f0a4ef0:	460a8181 */ 	sub.s	$f6,$f16,$f10
/*  f0a4ef4:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0a4ef8:	46003203 */ 	div.s	$f8,$f6,$f0
/*  f0a4efc:	e7a80084 */ 	swc1	$f8,0x84($sp)
/*  f0a4f00:	c6040368 */ 	lwc1	$f4,0x368($s0)
/*  f0a4f04:	c6120328 */ 	lwc1	$f18,0x328($s0)
/*  f0a4f08:	46049401 */ 	sub.s	$f16,$f18,$f4
/*  f0a4f0c:	46008283 */ 	div.s	$f10,$f16,$f0
/*  f0a4f10:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f0a4f14:	c608036c */ 	lwc1	$f8,0x36c($s0)
/*  f0a4f18:	c606032c */ 	lwc1	$f6,0x32c($s0)
/*  f0a4f1c:	46083481 */ 	sub.s	$f18,$f6,$f8
/*  f0a4f20:	46009103 */ 	div.s	$f4,$f18,$f0
/*  f0a4f24:	0c005ff6 */ 	jal	mtx00017588
/*  f0a4f28:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f0a4f2c:	27a40044 */ 	addiu	$a0,$sp,0x44
/*  f0a4f30:	0c005958 */ 	jal	mtx4RotateVecInPlace
/*  f0a4f34:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f0a4f38:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4f3c:	c420e564 */ 	lwc1	$f0,-0x1a9c($at)
/*  f0a4f40:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*  f0a4f44:	c61006e8 */ 	lwc1	$f16,0x6e8($s0)
/*  f0a4f48:	c61206ec */ 	lwc1	$f18,0x6ec($s0)
/*  f0a4f4c:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f0a4f50:	46068200 */ 	add.s	$f8,$f16,$f6
/*  f0a4f54:	c60606f0 */ 	lwc1	$f6,0x6f0($s0)
/*  f0a4f58:	e60806e8 */ 	swc1	$f8,0x6e8($s0)
/*  f0a4f5c:	c7a40088 */ 	lwc1	$f4,0x88($sp)
/*  f0a4f60:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0a4f64:	460a9400 */ 	add.s	$f16,$f18,$f10
/*  f0a4f68:	e61006ec */ 	swc1	$f16,0x6ec($s0)
/*  f0a4f6c:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*  f0a4f70:	46004102 */ 	mul.s	$f4,$f8,$f0
/*  f0a4f74:	46043480 */ 	add.s	$f18,$f6,$f4
/*  f0a4f78:	e61206f0 */ 	swc1	$f18,0x6f0($s0)
/*  f0a4f7c:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
.PB0f0a4f80:
/*  f0a4f80:	316cff0f */ 	andi	$t4,$t3,0xff0f
/*  f0a4f84:	358d0020 */ 	ori	$t5,$t4,0x20
/*  f0a4f88:	10000043 */ 	b	.PB0f0a5098
/*  f0a4f8c:	a20d06d6 */ 	sb	$t5,0x6d6($s0)
.PB0f0a4f90:
/*  f0a4f90:	2463e4d0 */ 	addiu	$v1,$v1,-6960
/*  f0a4f94:	8c6e0284 */ 	lw	$t6,0x284($v1)
/*  f0a4f98:	c460004c */ 	lwc1	$f0,0x4c($v1)
/*  f0a4f9c:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f0a4fa0:	8dcf00d8 */ 	lw	$t7,0xd8($t6)
/*  f0a4fa4:	11e00008 */ 	beqz	$t7,.PB0f0a4fc8
/*  f0a4fa8:	00000000 */ 	nop
/*  f0a4fac:	44811000 */ 	mtc1	$at,$f2
/*  f0a4fb0:	00000000 */ 	nop
/*  f0a4fb4:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0a4fb8:	00000000 */ 	nop
/*  f0a4fbc:	45000002 */ 	bc1f	.PB0f0a4fc8
/*  f0a4fc0:	00000000 */ 	nop
/*  f0a4fc4:	46001006 */ 	mov.s	$f0,$f2
.PB0f0a4fc8:
/*  f0a4fc8:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0a4fcc:	c42ae568 */ 	lwc1	$f10,-0x1a98($at)
/*  f0a4fd0:	c60e06e0 */ 	lwc1	$f14,0x6e0($s0)
/*  f0a4fd4:	c60806d8 */ 	lwc1	$f8,0x6d8($s0)
/*  f0a4fd8:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f0a4fdc:	c60206ec */ 	lwc1	$f2,0x6ec($s0)
/*  f0a4fe0:	4608703c */ 	c.lt.s	$f14,$f8
/*  f0a4fe4:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a4fe8:	45000006 */ 	bc1f	.PB0f0a5004
/*  f0a4fec:	46101301 */ 	sub.s	$f12,$f2,$f16
/*  f0a4ff0:	921806d6 */ 	lbu	$t8,0x6d6($s0)
/*  f0a4ff4:	3319ff0f */ 	andi	$t9,$t8,0xff0f
/*  f0a4ff8:	37280030 */ 	ori	$t0,$t9,0x30
/*  f0a4ffc:	10000026 */ 	b	.PB0f0a5098
/*  f0a5000:	a20806d6 */ 	sb	$t0,0x6d6($s0)
.PB0f0a5004:
/*  f0a5004:	44813000 */ 	mtc1	$at,$f6
/*  f0a5008:	460c1480 */ 	add.s	$f18,$f2,$f12
/*  f0a500c:	c60806dc */ 	lwc1	$f8,0x6dc($s0)
/*  f0a5010:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0a5014:	c60606e8 */ 	lwc1	$f6,0x6e8($s0)
/*  f0a5018:	e60c06ec */ 	swc1	$f12,0x6ec($s0)
/*  f0a501c:	00001025 */ 	move	$v0,$zero
/*  f0a5020:	26040718 */ 	addiu	$a0,$s0,0x718
/*  f0a5024:	260506f4 */ 	addiu	$a1,$s0,0x6f4
/*  f0a5028:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f0a502c:	460a7400 */ 	add.s	$f16,$f14,$f10
/*  f0a5030:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0a5034:	c60a06e4 */ 	lwc1	$f10,0x6e4($s0)
/*  f0a5038:	e61006e0 */ 	swc1	$f16,0x6e0($s0)
/*  f0a503c:	c61006f0 */ 	lwc1	$f16,0x6f0($s0)
/*  f0a5040:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f0a5044:	46044480 */ 	add.s	$f18,$f8,$f4
/*  f0a5048:	e61206dc */ 	swc1	$f18,0x6dc($s0)
/*  f0a504c:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0a5050:	e60806e4 */ 	swc1	$f8,0x6e4($s0)
/*  f0a5054:	8c690034 */ 	lw	$t1,0x34($v1)
/*  f0a5058:	59200010 */ 	blezl	$t1,.PB0f0a509c
/*  f0a505c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0a5060:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f0a5064:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f0a5068:	8fa40030 */ 	lw	$a0,0x30($sp)
.PB0f0a506c:
/*  f0a506c:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f0a5070:	0c005ad8 */ 	jal	mtx00016110
/*  f0a5074:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0a5078:	3c03800a */ 	lui	$v1,0x800a
/*  f0a507c:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f0a5080:	2463e4d0 */ 	addiu	$v1,$v1,-6960
/*  f0a5084:	8c6a0034 */ 	lw	$t2,0x34($v1)
/*  f0a5088:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0a508c:	004a082a */ 	slt	$at,$v0,$t2
/*  f0a5090:	5420fff6 */ 	bnezl	$at,.PB0f0a506c
/*  f0a5094:	8fa40030 */ 	lw	$a0,0x30($sp)
.PB0f0a5098:
/*  f0a5098:	8fbf0024 */ 	lw	$ra,0x24($sp)
.PB0f0a509c:
/*  f0a509c:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0a50a0:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0a50a4:	03e00008 */ 	jr	$ra
/*  f0a50a8:	27bd00e0 */ 	addiu	$sp,$sp,0xe0
);
#else
GLOBAL_ASM(
glabel bgun0f0a46a4
.late_rodata
glabel var7f1ac8cc
.word 0x3f088888
glabel var7f1ac8d0
.word 0x40c907a9
glabel var7f1ac8d4
.word 0x3d0bd8cf
glabel var7f1ac8d8
.word 0x40c907a9
glabel var7f1ac8dc
.word 0x3d0bd8cf
glabel var7f1ac8e0
.word 0x40c907a9
glabel var7f1ac8e4
.word 0x3d0bd8cf
glabel var7f1ac8e8
.word 0x3f088888
glabel var7f1ac8ec
.word 0x40c907a9
glabel var7f1ac8f0
.word 0x40c907a9
glabel var7f1ac8f4
.word 0x3c3d3463
glabel var7f1ac8f8
.word 0x40c907a9
glabel var7f1ac8fc
.word 0x3c3d3463
glabel var7f1ac900
.word 0x40c907a9
glabel var7f1ac904
.word 0x40c907a9
glabel var7f1ac908
.word 0x3bda10fd
glabel var7f1ac90c
.word 0x40c907a9
glabel var7f1ac910
.word 0x3bda10fd
glabel var7f1ac914
.word 0x3e99999a
glabel var7f1ac918
.word 0x3e8e38e4
.text
/*  f0a46a4:	27bdff20 */ 	addiu	$sp,$sp,-224
/*  f0a46a8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f0a46ac:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f0a46b0:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f0a46b4:	afa500e4 */ 	sw	$a1,0xe4($sp)
/*  f0a46b8:	afa600e8 */ 	sw	$a2,0xe8($sp)
/*  f0a46bc:	948206d6 */ 	lhu	$v0,0x6d6($a0)
/*  f0a46c0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0a46c4:	00808025 */ 	or	$s0,$a0,$zero
/*  f0a46c8:	00027302 */ 	srl	$t6,$v0,0xc
/*  f0a46cc:	11c30005 */ 	beq	$t6,$v1,.L0f0a46e4
/*  f0a46d0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a46d4:	11c10194 */ 	beq	$t6,$at,.L0f0a4d28
/*  f0a46d8:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0a46dc:	100001d5 */ 	b	.L0f0a4e34
/*  f0a46e0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0a46e4:
/*  f0a46e4:	8e0206d4 */ 	lw	$v0,0x6d4($s0)
/*  f0a46e8:	00027d00 */ 	sll	$t7,$v0,0x14
/*  f0a46ec:	000fc742 */ 	srl	$t8,$t7,0x1d
/*  f0a46f0:	13000007 */ 	beqz	$t8,.L0f0a4710
/*  f0a46f4:	00000000 */ 	nop
/*  f0a46f8:	1303006f */ 	beq	$t8,$v1,.L0f0a48b8
/*  f0a46fc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a4700:	530100e8 */ 	beql	$t8,$at,.L0f0a4aa4
/*  f0a4704:	44802000 */ 	mtc1	$zero,$f4
/*  f0a4708:	10000147 */ 	b	.L0f0a4c28
/*  f0a470c:	3c014348 */ 	lui	$at,0x4348
.L0f0a4710:
/*  f0a4710:	0c004b70 */ 	jal	random
/*  f0a4714:	00000000 */ 	nop
/*  f0a4718:	3c017f1b */ 	lui	$at,%hi(var7f1ac8cc)
/*  f0a471c:	c420c8cc */ 	lwc1	$f0,%lo(var7f1ac8cc)($at)
/*  f0a4720:	44822000 */ 	mtc1	$v0,$f4
/*  f0a4724:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a4728:	4481a000 */ 	mtc1	$at,$f20
/*  f0a472c:	04410005 */ 	bgez	$v0,.L0f0a4744
/*  f0a4730:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a4734:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4738:	44814000 */ 	mtc1	$at,$f8
/*  f0a473c:	00000000 */ 	nop
/*  f0a4740:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0a4744:
/*  f0a4744:	46143282 */ 	mul.s	$f10,$f6,$f20
/*  f0a4748:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a474c:	44818000 */ 	mtc1	$at,$f16
/*  f0a4750:	3c013d80 */ 	lui	$at,0x3d80
/*  f0a4754:	44814000 */ 	mtc1	$at,$f8
/*  f0a4758:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f0a475c:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0a4760:	00000000 */ 	nop
/*  f0a4764:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f0a4768:	46003280 */ 	add.s	$f10,$f6,$f0
/*  f0a476c:	0c004b70 */ 	jal	random
/*  f0a4770:	e60a06e8 */ 	swc1	$f10,0x6e8($s0)
/*  f0a4774:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4778:	3c014020 */ 	lui	$at,0x4020
/*  f0a477c:	44810000 */ 	mtc1	$at,$f0
/*  f0a4780:	04410005 */ 	bgez	$v0,.L0f0a4798
/*  f0a4784:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0a4788:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a478c:	44812000 */ 	mtc1	$at,$f4
/*  f0a4790:	00000000 */ 	nop
/*  f0a4794:	46049480 */ 	add.s	$f18,$f18,$f4
.L0f0a4798:
/*  f0a4798:	46149202 */ 	mul.s	$f8,$f18,$f20
/*  f0a479c:	3c013d80 */ 	lui	$at,0x3d80
/*  f0a47a0:	44815000 */ 	mtc1	$at,$f10
/*  f0a47a4:	44809000 */ 	mtc1	$zero,$f18
/*  f0a47a8:	00000000 */ 	nop
/*  f0a47ac:	e61206f0 */ 	swc1	$f18,0x6f0($s0)
/*  f0a47b0:	46004182 */ 	mul.s	$f6,$f8,$f0
/*  f0a47b4:	00000000 */ 	nop
/*  f0a47b8:	460a3402 */ 	mul.s	$f16,$f6,$f10
/*  f0a47bc:	46008100 */ 	add.s	$f4,$f16,$f0
/*  f0a47c0:	0c004b70 */ 	jal	random
/*  f0a47c4:	e60406ec */ 	swc1	$f4,0x6ec($s0)
/*  f0a47c8:	44824000 */ 	mtc1	$v0,$f8
/*  f0a47cc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a47d0:	04410004 */ 	bgez	$v0,.L0f0a47e4
/*  f0a47d4:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0a47d8:	44815000 */ 	mtc1	$at,$f10
/*  f0a47dc:	00000000 */ 	nop
/*  f0a47e0:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f0a47e4:
/*  f0a47e4:	46143002 */ 	mul.s	$f0,$f6,$f20
/*  f0a47e8:	3c017f1b */ 	lui	$at,%hi(var7f1ac8d0)
/*  f0a47ec:	c424c8d0 */ 	lwc1	$f4,%lo(var7f1ac8d0)($at)
/*  f0a47f0:	3c014338 */ 	lui	$at,0x4338
/*  f0a47f4:	44814000 */ 	mtc1	$at,$f8
/*  f0a47f8:	3c017f1b */ 	lui	$at,%hi(var7f1ac8d4)
/*  f0a47fc:	c426c8d4 */ 	lwc1	$f6,%lo(var7f1ac8d4)($at)
/*  f0a4800:	46000400 */ 	add.s	$f16,$f0,$f0
/*  f0a4804:	46048482 */ 	mul.s	$f18,$f16,$f4
/*  f0a4808:	46089283 */ 	div.s	$f10,$f18,$f8
/*  f0a480c:	46065401 */ 	sub.s	$f16,$f10,$f6
/*  f0a4810:	0c004b70 */ 	jal	random
/*  f0a4814:	e7b000d0 */ 	swc1	$f16,0xd0($sp)
/*  f0a4818:	44822000 */ 	mtc1	$v0,$f4
/*  f0a481c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4820:	04410004 */ 	bgez	$v0,.L0f0a4834
/*  f0a4824:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f0a4828:	44814000 */ 	mtc1	$at,$f8
/*  f0a482c:	00000000 */ 	nop
/*  f0a4830:	46089480 */ 	add.s	$f18,$f18,$f8
.L0f0a4834:
/*  f0a4834:	46149002 */ 	mul.s	$f0,$f18,$f20
/*  f0a4838:	3c017f1b */ 	lui	$at,%hi(var7f1ac8d8)
/*  f0a483c:	c426c8d8 */ 	lwc1	$f6,%lo(var7f1ac8d8)($at)
/*  f0a4840:	3c014338 */ 	lui	$at,0x4338
/*  f0a4844:	44812000 */ 	mtc1	$at,$f4
/*  f0a4848:	3c017f1b */ 	lui	$at,%hi(var7f1ac8dc)
/*  f0a484c:	c432c8dc */ 	lwc1	$f18,%lo(var7f1ac8dc)($at)
/*  f0a4850:	46000280 */ 	add.s	$f10,$f0,$f0
/*  f0a4854:	46065402 */ 	mul.s	$f16,$f10,$f6
/*  f0a4858:	46048203 */ 	div.s	$f8,$f16,$f4
/*  f0a485c:	46124281 */ 	sub.s	$f10,$f8,$f18
/*  f0a4860:	0c004b70 */ 	jal	random
/*  f0a4864:	e7aa00d4 */ 	swc1	$f10,0xd4($sp)
/*  f0a4868:	44823000 */ 	mtc1	$v0,$f6
/*  f0a486c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4870:	04410004 */ 	bgez	$v0,.L0f0a4884
/*  f0a4874:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f0a4878:	44812000 */ 	mtc1	$at,$f4
/*  f0a487c:	00000000 */ 	nop
/*  f0a4880:	46048400 */ 	add.s	$f16,$f16,$f4
.L0f0a4884:
/*  f0a4884:	46148002 */ 	mul.s	$f0,$f16,$f20
/*  f0a4888:	3c017f1b */ 	lui	$at,%hi(var7f1ac8e0)
/*  f0a488c:	c432c8e0 */ 	lwc1	$f18,%lo(var7f1ac8e0)($at)
/*  f0a4890:	3c014338 */ 	lui	$at,0x4338
/*  f0a4894:	44813000 */ 	mtc1	$at,$f6
/*  f0a4898:	3c017f1b */ 	lui	$at,%hi(var7f1ac8e4)
/*  f0a489c:	c430c8e4 */ 	lwc1	$f16,%lo(var7f1ac8e4)($at)
/*  f0a48a0:	46000200 */ 	add.s	$f8,$f0,$f0
/*  f0a48a4:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f0a48a8:	46065103 */ 	div.s	$f4,$f10,$f6
/*  f0a48ac:	46102201 */ 	sub.s	$f8,$f4,$f16
/*  f0a48b0:	100000dc */ 	b	.L0f0a4c24
/*  f0a48b4:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
.L0f0a48b8:
/*  f0a48b8:	0c004b70 */ 	jal	random
/*  f0a48bc:	00000000 */ 	nop
/*  f0a48c0:	3c017f1b */ 	lui	$at,%hi(var7f1ac8e8)
/*  f0a48c4:	c420c8e8 */ 	lwc1	$f0,%lo(var7f1ac8e8)($at)
/*  f0a48c8:	44829000 */ 	mtc1	$v0,$f18
/*  f0a48cc:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a48d0:	4481a000 */ 	mtc1	$at,$f20
/*  f0a48d4:	04410005 */ 	bgez	$v0,.L0f0a48ec
/*  f0a48d8:	468092a0 */ 	cvt.s.w	$f10,$f18
/*  f0a48dc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a48e0:	44813000 */ 	mtc1	$at,$f6
/*  f0a48e4:	00000000 */ 	nop
/*  f0a48e8:	46065280 */ 	add.s	$f10,$f10,$f6
.L0f0a48ec:
/*  f0a48ec:	46145102 */ 	mul.s	$f4,$f10,$f20
/*  f0a48f0:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a48f4:	44818000 */ 	mtc1	$at,$f16
/*  f0a48f8:	3c013d80 */ 	lui	$at,0x3d80
/*  f0a48fc:	44813000 */ 	mtc1	$at,$f6
/*  f0a4900:	3c014040 */ 	lui	$at,0x4040
/*  f0a4904:	46102201 */ 	sub.s	$f8,$f4,$f16
/*  f0a4908:	44812000 */ 	mtc1	$at,$f4
/*  f0a490c:	46004482 */ 	mul.s	$f18,$f8,$f0
/*  f0a4910:	00000000 */ 	nop
/*  f0a4914:	46069282 */ 	mul.s	$f10,$f18,$f6
/*  f0a4918:	00000000 */ 	nop
/*  f0a491c:	46002402 */ 	mul.s	$f16,$f4,$f0
/*  f0a4920:	46105200 */ 	add.s	$f8,$f10,$f16
/*  f0a4924:	46004487 */ 	neg.s	$f18,$f8
/*  f0a4928:	0c004b70 */ 	jal	random
/*  f0a492c:	e61206e8 */ 	swc1	$f18,0x6e8($s0)
/*  f0a4930:	44823000 */ 	mtc1	$v0,$f6
/*  f0a4934:	3c014020 */ 	lui	$at,0x4020
/*  f0a4938:	44810000 */ 	mtc1	$at,$f0
/*  f0a493c:	04410005 */ 	bgez	$v0,.L0f0a4954
/*  f0a4940:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0a4944:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4948:	44815000 */ 	mtc1	$at,$f10
/*  f0a494c:	00000000 */ 	nop
/*  f0a4950:	460a2100 */ 	add.s	$f4,$f4,$f10
.L0f0a4954:
/*  f0a4954:	46142402 */ 	mul.s	$f16,$f4,$f20
/*  f0a4958:	3c013e00 */ 	lui	$at,0x3e00
/*  f0a495c:	44819000 */ 	mtc1	$at,$f18
/*  f0a4960:	46008202 */ 	mul.s	$f8,$f16,$f0
/*  f0a4964:	00000000 */ 	nop
/*  f0a4968:	46124182 */ 	mul.s	$f6,$f8,$f18
/*  f0a496c:	46003280 */ 	add.s	$f10,$f6,$f0
/*  f0a4970:	0c004b70 */ 	jal	random
/*  f0a4974:	e60a06ec */ 	swc1	$f10,0x6ec($s0)
/*  f0a4978:	44822000 */ 	mtc1	$v0,$f4
/*  f0a497c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4980:	04410004 */ 	bgez	$v0,.L0f0a4994
/*  f0a4984:	46802420 */ 	cvt.s.w	$f16,$f4
/*  f0a4988:	44814000 */ 	mtc1	$at,$f8
/*  f0a498c:	00000000 */ 	nop
/*  f0a4990:	46088400 */ 	add.s	$f16,$f16,$f8
.L0f0a4994:
/*  f0a4994:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f0a4998:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a499c:	44813000 */ 	mtc1	$at,$f6
/*  f0a49a0:	00000000 */ 	nop
/*  f0a49a4:	46069280 */ 	add.s	$f10,$f18,$f6
/*  f0a49a8:	46005107 */ 	neg.s	$f4,$f10
/*  f0a49ac:	0c004b70 */ 	jal	random
/*  f0a49b0:	e60406f0 */ 	swc1	$f4,0x6f0($s0)
/*  f0a49b4:	44824000 */ 	mtc1	$v0,$f8
/*  f0a49b8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a49bc:	04410004 */ 	bgez	$v0,.L0f0a49d0
/*  f0a49c0:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f0a49c4:	44819000 */ 	mtc1	$at,$f18
/*  f0a49c8:	00000000 */ 	nop
/*  f0a49cc:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f0a49d0:
/*  f0a49d0:	46148182 */ 	mul.s	$f6,$f16,$f20
/*  f0a49d4:	3c014040 */ 	lui	$at,0x4040
/*  f0a49d8:	44815000 */ 	mtc1	$at,$f10
/*  f0a49dc:	3c017f1b */ 	lui	$at,%hi(var7f1ac8ec)
/*  f0a49e0:	c428c8ec */ 	lwc1	$f8,%lo(var7f1ac8ec)($at)
/*  f0a49e4:	3c014350 */ 	lui	$at,0x4350
/*  f0a49e8:	44818000 */ 	mtc1	$at,$f16
/*  f0a49ec:	460a3100 */ 	add.s	$f4,$f6,$f10
/*  f0a49f0:	46082482 */ 	mul.s	$f18,$f4,$f8
/*  f0a49f4:	46109183 */ 	div.s	$f6,$f18,$f16
/*  f0a49f8:	0c004b70 */ 	jal	random
/*  f0a49fc:	e7a600d0 */ 	swc1	$f6,0xd0($sp)
/*  f0a4a00:	44825000 */ 	mtc1	$v0,$f10
/*  f0a4a04:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4a08:	04410004 */ 	bgez	$v0,.L0f0a4a1c
/*  f0a4a0c:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0a4a10:	44814000 */ 	mtc1	$at,$f8
/*  f0a4a14:	00000000 */ 	nop
/*  f0a4a18:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f0a4a1c:
/*  f0a4a1c:	46142002 */ 	mul.s	$f0,$f4,$f20
/*  f0a4a20:	3c017f1b */ 	lui	$at,%hi(var7f1ac8f0)
/*  f0a4a24:	c430c8f0 */ 	lwc1	$f16,%lo(var7f1ac8f0)($at)
/*  f0a4a28:	3c014408 */ 	lui	$at,0x4408
/*  f0a4a2c:	44815000 */ 	mtc1	$at,$f10
/*  f0a4a30:	3c017f1b */ 	lui	$at,%hi(var7f1ac8f4)
/*  f0a4a34:	c424c8f4 */ 	lwc1	$f4,%lo(var7f1ac8f4)($at)
/*  f0a4a38:	46000480 */ 	add.s	$f18,$f0,$f0
/*  f0a4a3c:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f0a4a40:	460a3203 */ 	div.s	$f8,$f6,$f10
/*  f0a4a44:	46044481 */ 	sub.s	$f18,$f8,$f4
/*  f0a4a48:	0c004b70 */ 	jal	random
/*  f0a4a4c:	e7b200d4 */ 	swc1	$f18,0xd4($sp)
/*  f0a4a50:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4a54:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4a58:	04410004 */ 	bgez	$v0,.L0f0a4a6c
/*  f0a4a5c:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0a4a60:	44815000 */ 	mtc1	$at,$f10
/*  f0a4a64:	00000000 */ 	nop
/*  f0a4a68:	460a3180 */ 	add.s	$f6,$f6,$f10
.L0f0a4a6c:
/*  f0a4a6c:	46143002 */ 	mul.s	$f0,$f6,$f20
/*  f0a4a70:	3c017f1b */ 	lui	$at,%hi(var7f1ac8f8)
/*  f0a4a74:	c424c8f8 */ 	lwc1	$f4,%lo(var7f1ac8f8)($at)
/*  f0a4a78:	3c014408 */ 	lui	$at,0x4408
/*  f0a4a7c:	44818000 */ 	mtc1	$at,$f16
/*  f0a4a80:	3c017f1b */ 	lui	$at,%hi(var7f1ac8fc)
/*  f0a4a84:	c426c8fc */ 	lwc1	$f6,%lo(var7f1ac8fc)($at)
/*  f0a4a88:	46000200 */ 	add.s	$f8,$f0,$f0
/*  f0a4a8c:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f0a4a90:	46109283 */ 	div.s	$f10,$f18,$f16
/*  f0a4a94:	46065201 */ 	sub.s	$f8,$f10,$f6
/*  f0a4a98:	10000062 */ 	b	.L0f0a4c24
/*  f0a4a9c:	e7a800d8 */ 	swc1	$f8,0xd8($sp)
/*  f0a4aa0:	44802000 */ 	mtc1	$zero,$f4
.L0f0a4aa4:
/*  f0a4aa4:	0c004b70 */ 	jal	random
/*  f0a4aa8:	e60406e8 */ 	swc1	$f4,0x6e8($s0)
/*  f0a4aac:	3c014020 */ 	lui	$at,0x4020
/*  f0a4ab0:	44810000 */ 	mtc1	$at,$f0
/*  f0a4ab4:	44829000 */ 	mtc1	$v0,$f18
/*  f0a4ab8:	3c012f80 */ 	lui	$at,0x2f80
/*  f0a4abc:	4481a000 */ 	mtc1	$at,$f20
/*  f0a4ac0:	04410005 */ 	bgez	$v0,.L0f0a4ad8
/*  f0a4ac4:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f0a4ac8:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4acc:	44815000 */ 	mtc1	$at,$f10
/*  f0a4ad0:	00000000 */ 	nop
/*  f0a4ad4:	460a8400 */ 	add.s	$f16,$f16,$f10
.L0f0a4ad8:
/*  f0a4ad8:	46148182 */ 	mul.s	$f6,$f16,$f20
/*  f0a4adc:	3c013e00 */ 	lui	$at,0x3e00
/*  f0a4ae0:	44812000 */ 	mtc1	$at,$f4
/*  f0a4ae4:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a4ae8:	00000000 */ 	nop
/*  f0a4aec:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f0a4af0:	46009280 */ 	add.s	$f10,$f18,$f0
/*  f0a4af4:	0c004b70 */ 	jal	random
/*  f0a4af8:	e60a06ec */ 	swc1	$f10,0x6ec($s0)
/*  f0a4afc:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4b00:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4b04:	04410004 */ 	bgez	$v0,.L0f0a4b18
/*  f0a4b08:	468081a0 */ 	cvt.s.w	$f6,$f16
/*  f0a4b0c:	44814000 */ 	mtc1	$at,$f8
/*  f0a4b10:	00000000 */ 	nop
/*  f0a4b14:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f0a4b18:
/*  f0a4b18:	46143102 */ 	mul.s	$f4,$f6,$f20
/*  f0a4b1c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0a4b20:	44819000 */ 	mtc1	$at,$f18
/*  f0a4b24:	3c013e80 */ 	lui	$at,0x3e80
/*  f0a4b28:	44818000 */ 	mtc1	$at,$f16
/*  f0a4b2c:	46122280 */ 	add.s	$f10,$f4,$f18
/*  f0a4b30:	46105202 */ 	mul.s	$f8,$f10,$f16
/*  f0a4b34:	0c004b70 */ 	jal	random
/*  f0a4b38:	e60806f0 */ 	swc1	$f8,0x6f0($s0)
/*  f0a4b3c:	44823000 */ 	mtc1	$v0,$f6
/*  f0a4b40:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4b44:	04410004 */ 	bgez	$v0,.L0f0a4b58
/*  f0a4b48:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0a4b4c:	44819000 */ 	mtc1	$at,$f18
/*  f0a4b50:	00000000 */ 	nop
/*  f0a4b54:	46122100 */ 	add.s	$f4,$f4,$f18
.L0f0a4b58:
/*  f0a4b58:	46142282 */ 	mul.s	$f10,$f4,$f20
/*  f0a4b5c:	3c014040 */ 	lui	$at,0x4040
/*  f0a4b60:	44818000 */ 	mtc1	$at,$f16
/*  f0a4b64:	3c017f1b */ 	lui	$at,%hi(var7f1ac900)
/*  f0a4b68:	c426c900 */ 	lwc1	$f6,%lo(var7f1ac900)($at)
/*  f0a4b6c:	3c0143b8 */ 	lui	$at,0x43b8
/*  f0a4b70:	44812000 */ 	mtc1	$at,$f4
/*  f0a4b74:	46105200 */ 	add.s	$f8,$f10,$f16
/*  f0a4b78:	46064482 */ 	mul.s	$f18,$f8,$f6
/*  f0a4b7c:	46049283 */ 	div.s	$f10,$f18,$f4
/*  f0a4b80:	0c004b70 */ 	jal	random
/*  f0a4b84:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
/*  f0a4b88:	44828000 */ 	mtc1	$v0,$f16
/*  f0a4b8c:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4b90:	04410004 */ 	bgez	$v0,.L0f0a4ba4
/*  f0a4b94:	46808220 */ 	cvt.s.w	$f8,$f16
/*  f0a4b98:	44813000 */ 	mtc1	$at,$f6
/*  f0a4b9c:	00000000 */ 	nop
/*  f0a4ba0:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f0a4ba4:
/*  f0a4ba4:	46144002 */ 	mul.s	$f0,$f8,$f20
/*  f0a4ba8:	3c017f1b */ 	lui	$at,%hi(var7f1ac904)
/*  f0a4bac:	c424c904 */ 	lwc1	$f4,%lo(var7f1ac904)($at)
/*  f0a4bb0:	3c01446c */ 	lui	$at,0x446c
/*  f0a4bb4:	44818000 */ 	mtc1	$at,$f16
/*  f0a4bb8:	3c017f1b */ 	lui	$at,%hi(var7f1ac908)
/*  f0a4bbc:	c428c908 */ 	lwc1	$f8,%lo(var7f1ac908)($at)
/*  f0a4bc0:	46000480 */ 	add.s	$f18,$f0,$f0
/*  f0a4bc4:	46049282 */ 	mul.s	$f10,$f18,$f4
/*  f0a4bc8:	46105183 */ 	div.s	$f6,$f10,$f16
/*  f0a4bcc:	46083481 */ 	sub.s	$f18,$f6,$f8
/*  f0a4bd0:	0c004b70 */ 	jal	random
/*  f0a4bd4:	e7b200d4 */ 	swc1	$f18,0xd4($sp)
/*  f0a4bd8:	44822000 */ 	mtc1	$v0,$f4
/*  f0a4bdc:	3c014f80 */ 	lui	$at,0x4f80
/*  f0a4be0:	04410004 */ 	bgez	$v0,.L0f0a4bf4
/*  f0a4be4:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0a4be8:	44818000 */ 	mtc1	$at,$f16
/*  f0a4bec:	00000000 */ 	nop
/*  f0a4bf0:	46105280 */ 	add.s	$f10,$f10,$f16
.L0f0a4bf4:
/*  f0a4bf4:	46145002 */ 	mul.s	$f0,$f10,$f20
/*  f0a4bf8:	3c017f1b */ 	lui	$at,%hi(var7f1ac90c)
/*  f0a4bfc:	c428c90c */ 	lwc1	$f8,%lo(var7f1ac90c)($at)
/*  f0a4c00:	3c01446c */ 	lui	$at,0x446c
/*  f0a4c04:	44812000 */ 	mtc1	$at,$f4
/*  f0a4c08:	3c017f1b */ 	lui	$at,%hi(var7f1ac910)
/*  f0a4c0c:	c42ac910 */ 	lwc1	$f10,%lo(var7f1ac910)($at)
/*  f0a4c10:	46000180 */ 	add.s	$f6,$f0,$f0
/*  f0a4c14:	46083482 */ 	mul.s	$f18,$f6,$f8
/*  f0a4c18:	46049403 */ 	div.s	$f16,$f18,$f4
/*  f0a4c1c:	460a8181 */ 	sub.s	$f6,$f16,$f10
/*  f0a4c20:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
.L0f0a4c24:
/*  f0a4c24:	3c014348 */ 	lui	$at,0x4348
.L0f0a4c28:
/*  f0a4c28:	44819000 */ 	mtc1	$at,$f18
/*  f0a4c2c:	c60806dc */ 	lwc1	$f8,0x6dc($s0)
/*  f0a4c30:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f0a4c34:	27a50090 */ 	addiu	$a1,$sp,0x90
/*  f0a4c38:	46124101 */ 	sub.s	$f4,$f8,$f18
/*  f0a4c3c:	0c005923 */ 	jal	mtx4LoadRotation
/*  f0a4c40:	e60406d8 */ 	swc1	$f4,0x6d8($s0)
/*  f0a4c44:	27a40090 */ 	addiu	$a0,$sp,0x90
/*  f0a4c48:	0c005768 */ 	jal	mtx4ToMtx3
/*  f0a4c4c:	26050718 */ 	addiu	$a1,$s0,0x718
/*  f0a4c50:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0a4c54:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0a4c58:	8c790034 */ 	lw	$t9,0x34($v1)
/*  f0a4c5c:	5b20002e */ 	blezl	$t9,.L0f0a4d18
/*  f0a4c60:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
/*  f0a4c64:	8e0806d4 */ 	lw	$t0,0x6d4($s0)
/*  f0a4c68:	00084d00 */ 	sll	$t1,$t0,0x14
/*  f0a4c6c:	00095742 */ 	srl	$t2,$t1,0x1d
/*  f0a4c70:	51400029 */ 	beqzl	$t2,.L0f0a4d18
/*  f0a4c74:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
/*  f0a4c78:	c6100324 */ 	lwc1	$f16,0x324($s0)
/*  f0a4c7c:	c60a0364 */ 	lwc1	$f10,0x364($s0)
/*  f0a4c80:	c460004c */ 	lwc1	$f0,0x4c($v1)
/*  f0a4c84:	260402f4 */ 	addiu	$a0,$s0,0x2f4
/*  f0a4c88:	460a8181 */ 	sub.s	$f6,$f16,$f10
/*  f0a4c8c:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f0a4c90:	46003203 */ 	div.s	$f8,$f6,$f0
/*  f0a4c94:	e7a80084 */ 	swc1	$f8,0x84($sp)
/*  f0a4c98:	c6040368 */ 	lwc1	$f4,0x368($s0)
/*  f0a4c9c:	c6120328 */ 	lwc1	$f18,0x328($s0)
/*  f0a4ca0:	46049401 */ 	sub.s	$f16,$f18,$f4
/*  f0a4ca4:	46008283 */ 	div.s	$f10,$f16,$f0
/*  f0a4ca8:	e7aa0088 */ 	swc1	$f10,0x88($sp)
/*  f0a4cac:	c608036c */ 	lwc1	$f8,0x36c($s0)
/*  f0a4cb0:	c606032c */ 	lwc1	$f6,0x32c($s0)
/*  f0a4cb4:	46083481 */ 	sub.s	$f18,$f6,$f8
/*  f0a4cb8:	46009103 */ 	div.s	$f4,$f18,$f0
/*  f0a4cbc:	0c005d62 */ 	jal	mtx00017588
/*  f0a4cc0:	e7a4008c */ 	swc1	$f4,0x8c($sp)
/*  f0a4cc4:	27a40044 */ 	addiu	$a0,$sp,0x44
/*  f0a4cc8:	0c0056c4 */ 	jal	mtx4RotateVecInPlace
/*  f0a4ccc:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f0a4cd0:	3c017f1b */ 	lui	$at,%hi(var7f1ac914)
/*  f0a4cd4:	c420c914 */ 	lwc1	$f0,%lo(var7f1ac914)($at)
/*  f0a4cd8:	c7aa0084 */ 	lwc1	$f10,0x84($sp)
/*  f0a4cdc:	c61006e8 */ 	lwc1	$f16,0x6e8($s0)
/*  f0a4ce0:	c61206ec */ 	lwc1	$f18,0x6ec($s0)
/*  f0a4ce4:	46005182 */ 	mul.s	$f6,$f10,$f0
/*  f0a4ce8:	46068200 */ 	add.s	$f8,$f16,$f6
/*  f0a4cec:	c60606f0 */ 	lwc1	$f6,0x6f0($s0)
/*  f0a4cf0:	e60806e8 */ 	swc1	$f8,0x6e8($s0)
/*  f0a4cf4:	c7a40088 */ 	lwc1	$f4,0x88($sp)
/*  f0a4cf8:	46002282 */ 	mul.s	$f10,$f4,$f0
/*  f0a4cfc:	460a9400 */ 	add.s	$f16,$f18,$f10
/*  f0a4d00:	e61006ec */ 	swc1	$f16,0x6ec($s0)
/*  f0a4d04:	c7a8008c */ 	lwc1	$f8,0x8c($sp)
/*  f0a4d08:	46004102 */ 	mul.s	$f4,$f8,$f0
/*  f0a4d0c:	46043480 */ 	add.s	$f18,$f6,$f4
/*  f0a4d10:	e61206f0 */ 	swc1	$f18,0x6f0($s0)
/*  f0a4d14:	920b06d6 */ 	lbu	$t3,0x6d6($s0)
.L0f0a4d18:
/*  f0a4d18:	316cff0f */ 	andi	$t4,$t3,0xff0f
/*  f0a4d1c:	358d0020 */ 	ori	$t5,$t4,0x20
/*  f0a4d20:	10000043 */ 	b	.L0f0a4e30
/*  f0a4d24:	a20d06d6 */ 	sb	$t5,0x6d6($s0)
.L0f0a4d28:
/*  f0a4d28:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0a4d2c:	8c6e0284 */ 	lw	$t6,0x284($v1)
/*  f0a4d30:	c460004c */ 	lwc1	$f0,0x4c($v1)
/*  f0a4d34:	3c013fc0 */ 	lui	$at,0x3fc0
/*  f0a4d38:	8dcf00d8 */ 	lw	$t7,0xd8($t6)
/*  f0a4d3c:	11e00008 */ 	beqz	$t7,.L0f0a4d60
/*  f0a4d40:	00000000 */ 	nop
/*  f0a4d44:	44811000 */ 	mtc1	$at,$f2
/*  f0a4d48:	00000000 */ 	nop
/*  f0a4d4c:	4600103c */ 	c.lt.s	$f2,$f0
/*  f0a4d50:	00000000 */ 	nop
/*  f0a4d54:	45000002 */ 	bc1f	.L0f0a4d60
/*  f0a4d58:	00000000 */ 	nop
/*  f0a4d5c:	46001006 */ 	mov.s	$f0,$f2
.L0f0a4d60:
/*  f0a4d60:	3c017f1b */ 	lui	$at,%hi(var7f1ac918)
/*  f0a4d64:	c42ac918 */ 	lwc1	$f10,%lo(var7f1ac918)($at)
/*  f0a4d68:	c60e06e0 */ 	lwc1	$f14,0x6e0($s0)
/*  f0a4d6c:	c60806d8 */ 	lwc1	$f8,0x6d8($s0)
/*  f0a4d70:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f0a4d74:	c60206ec */ 	lwc1	$f2,0x6ec($s0)
/*  f0a4d78:	4608703c */ 	c.lt.s	$f14,$f8
/*  f0a4d7c:	3c013f00 */ 	lui	$at,0x3f00
/*  f0a4d80:	45000006 */ 	bc1f	.L0f0a4d9c
/*  f0a4d84:	46101301 */ 	sub.s	$f12,$f2,$f16
/*  f0a4d88:	921806d6 */ 	lbu	$t8,0x6d6($s0)
/*  f0a4d8c:	3319ff0f */ 	andi	$t9,$t8,0xff0f
/*  f0a4d90:	37280030 */ 	ori	$t0,$t9,0x30
/*  f0a4d94:	10000026 */ 	b	.L0f0a4e30
/*  f0a4d98:	a20806d6 */ 	sb	$t0,0x6d6($s0)
.L0f0a4d9c:
/*  f0a4d9c:	44813000 */ 	mtc1	$at,$f6
/*  f0a4da0:	460c1480 */ 	add.s	$f18,$f2,$f12
/*  f0a4da4:	c60806dc */ 	lwc1	$f8,0x6dc($s0)
/*  f0a4da8:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0a4dac:	c60606e8 */ 	lwc1	$f6,0x6e8($s0)
/*  f0a4db0:	e60c06ec */ 	swc1	$f12,0x6ec($s0)
/*  f0a4db4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a4db8:	26040718 */ 	addiu	$a0,$s0,0x718
/*  f0a4dbc:	260506f4 */ 	addiu	$a1,$s0,0x6f4
/*  f0a4dc0:	46122282 */ 	mul.s	$f10,$f4,$f18
/*  f0a4dc4:	460a7400 */ 	add.s	$f16,$f14,$f10
/*  f0a4dc8:	46060102 */ 	mul.s	$f4,$f0,$f6
/*  f0a4dcc:	c60a06e4 */ 	lwc1	$f10,0x6e4($s0)
/*  f0a4dd0:	e61006e0 */ 	swc1	$f16,0x6e0($s0)
/*  f0a4dd4:	c61006f0 */ 	lwc1	$f16,0x6f0($s0)
/*  f0a4dd8:	46100182 */ 	mul.s	$f6,$f0,$f16
/*  f0a4ddc:	46044480 */ 	add.s	$f18,$f8,$f4
/*  f0a4de0:	e61206dc */ 	swc1	$f18,0x6dc($s0)
/*  f0a4de4:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f0a4de8:	e60806e4 */ 	swc1	$f8,0x6e4($s0)
/*  f0a4dec:	8c690034 */ 	lw	$t1,0x34($v1)
/*  f0a4df0:	59200010 */ 	blezl	$t1,.L0f0a4e34
/*  f0a4df4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f0a4df8:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f0a4dfc:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f0a4e00:	8fa40030 */ 	lw	$a0,0x30($sp)
.L0f0a4e04:
/*  f0a4e04:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f0a4e08:	0c005844 */ 	jal	mtx00016110
/*  f0a4e0c:	afa20040 */ 	sw	$v0,0x40($sp)
/*  f0a4e10:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f0a4e14:	8fa20040 */ 	lw	$v0,0x40($sp)
/*  f0a4e18:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f0a4e1c:	8c6a0034 */ 	lw	$t2,0x34($v1)
/*  f0a4e20:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0a4e24:	004a082a */ 	slt	$at,$v0,$t2
/*  f0a4e28:	5420fff6 */ 	bnezl	$at,.L0f0a4e04
/*  f0a4e2c:	8fa40030 */ 	lw	$a0,0x30($sp)
.L0f0a4e30:
/*  f0a4e30:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f0a4e34:
/*  f0a4e34:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f0a4e38:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f0a4e3c:	03e00008 */ 	jr	$ra
/*  f0a4e40:	27bd00e0 */ 	addiu	$sp,$sp,0xe0
);
#endif
#else
/**
 * With this function stubbed, the tranquilizer's spent ammo does not detach
 * when reloading, and the pulled pin on grenades and nbombs appears to move
 * with the model rather than detaching properly.
 */
void bgun0f0a46a4(struct hand *hand, struct modelfiledata *modeldef, bool isdetonator)
{
	struct coord spd0;
	Mtxf sp90;
	struct coord sp84;
	Mtxf sp44;
	s32 i;
	f32 lvupdate;
	f32 newval;
	f32 sumval;

	switch (hand->unk0d0e_00) {
	case 1:
		// 6e4
		switch (hand->unk0d0e_04) {
		case 0:
			// 710
			hand->unk0d20.f[0] = (RANDOMFRAC() - 0.5f) * 0.5333333f * 0.0625f + 0.5333333f;
			hand->unk0d20.f[1] = 0.0f;
			hand->unk0d20.f[2] = RANDOMFRAC() * 2.5f * 0.0625f + 2.5f;
			spd0.f[0] = 2.0f * RANDOMFRAC() * M_BADTAU / 184.0f - 0.03414231f;
			spd0.f[1] = 2.0f * RANDOMFRAC() * M_BADTAU / 184.0f - 0.03414231f;
			spd0.f[2] = 2.0f * RANDOMFRAC() * M_BADTAU / 184.0f - 0.03414231f;
			break;
		case 1:
			// 8b8
			hand->unk0d20.f[0] = -((RANDOMFRAC() - 0.5f) * 0.5333333f * 0.0625f + 3.0f * 0.5333333f);
			hand->unk0d20.f[1] = RANDOMFRAC() * 2.5f * 0.125f + 2.5f;
			hand->unk0d20.f[2] = -(RANDOMFRAC() + 1.0f);
			spd0.f[0] = (RANDOMFRAC() + 3.0f) * M_BADTAU / 208.0f;
			spd0.f[1] = 2.0f * RANDOMFRAC() * M_BADTAU / 544.0f - 0.0115481345f;
			spd0.f[2] = 2.0f * RANDOMFRAC() * M_BADTAU / 544.0f - 0.0115481345f;
			break;
		case 2:
			// aa4
			hand->unk0d20.f[0] = 0.0f;
			hand->unk0d20.f[1] = RANDOMFRAC() * 2.5f * 0.125f + 2.5f;
			hand->unk0d20.f[2] = (RANDOMFRAC() + 1.0f) * 0.25f;
			spd0.f[0] = (RANDOMFRAC() + 3.0f) * M_BADTAU / 368.0f;
			spd0.f[1] = 2.0f * RANDOMFRAC() * M_BADTAU / 944.0f - 0.006654857f;
			spd0.f[2] = 2.0f * RANDOMFRAC() * M_BADTAU / 944.0f - 0.006654857f;
			break;
		}

		// c28
		hand->unk0d10 = hand->unk0d14 - 200.0f;

		mtx4LoadRotation(&spd0, &sp90);
		mtx4ToMtx3(&sp90, hand->unk0d50);

		if (g_Vars.lvupdate240 > 0 && hand->unk0d0e_04) {
			sp84.x = (hand->posmtx.m[3][0] - hand->prevmtx.m[3][0]) / g_Vars.lvupdate240f;
			sp84.y = (hand->posmtx.m[3][1] - hand->prevmtx.m[3][1]) / g_Vars.lvupdate240f;
			sp84.z = (hand->posmtx.m[3][2] - hand->prevmtx.m[3][2]) / g_Vars.lvupdate240f;

			mtx00017588(hand->posmtx.m, sp44.m);
			mtx4RotateVecInPlace(&sp44, &sp84);

			hand->unk0d20.f[0] += sp84.x * 0.3f;
			hand->unk0d20.f[1] += sp84.y * 0.3f;
			hand->unk0d20.f[2] += sp84.z * 0.3f;
		}

		hand->unk0d0e_00 = 2;
		break;
	case 2:
		// d28
		lvupdate = g_Vars.lvupdate240f;

		if (g_Vars.currentplayer->isdead && lvupdate > 1.5f) {
			lvupdate = 1.5f;
		}

		newval = hand->unk0d20.f[1] - lvupdate * 0.2777778f;

		if (hand->unk0d18 < hand->unk0d10) {
			hand->unk0d0e_00 = 3;
			break;
		}

		sumval = hand->unk0d20.f[1] + newval;

		hand->unk0d20.f[1] = newval;

		hand->unk0d14 += lvupdate * hand->unk0d20.f[0];
		hand->unk0d18 += lvupdate * 0.5f * sumval;
		hand->unk0d1c += lvupdate * hand->unk0d20.f[2];

		for (i = 0; i < g_Vars.lvupdate240; i++) {
			mtx00016110(hand->unk0d50, hand->unk0d2c);
		}

		break;
	}
}
#endif

void bgun0f0a4e44(struct hand *hand, struct weapon *weapondef, struct modelfiledata *modeldef,
		struct weaponfunc *funcdef, s32 maxburst, u8 *allocation, s32 weaponnum,
		bool **arg7, s32 mtxindex, Mtxf *arg9, Mtxf *arg10)
{
	Mtxf spd8;
	s32 index;
	s32 shotstotake;
	bool spc4[3] = {false, false, false};
	Mtxf *mtx;
	s32 i;
	s32 partnum;
	f32 spb4;
	f32 sway;
	Mtxf sp70;

	index = hand->burstbullets % maxburst;
	shotstotake = hand->shotstotake;

	spb4 = RANDOMFRAC() * 0.25f + 1.0f;
	sway = weapondef->sway;

	mtx4LoadIdentity(&spd8);

	if (funcdef && (funcdef->flags & FUNCFLAG_00000001)) {
		mtx4LoadZRotation(RANDOMFRAC() * M_BADTAU, &spd8);
	}

	mtx4LoadZRotation((RANDOMFRAC() * 0.3 - 0.15), &spd8);

	mtx = (Mtxf *)allocation;
	mtx += mtxindex;

	mtx4MultMtx4InPlace(mtx, &spd8);
	mtx00015f04(spb4, &spd8);
	mtx00015ea8(sway, &spd8);
	mtx4Copy(&spd8, mtx);

	if (shotstotake == 0 && weaponnum != WEAPON_REAPER) {
		shotstotake++;
	}

	for (i = 0; i < shotstotake; i++) {
		spc4[index] = true;
		index++;

		if (index >= maxburst) {
			index = 0;
		}
	}

	for (i = 0; i < maxburst; i++) {
		if (spc4[i] && arg7[i] != NULL) {
			*arg7[i] = true;
		}
	}

	for (partnum = 0x50; partnum <= 0x52; partnum++) {
		struct modelnode *node = modelGetPart(modeldef, partnum);
		struct coord sp60;

		if (node && weaponnum != WEAPON_REAPER && weaponnum != WEAPON_SHOTGUN) {
			struct modelrodata_position *rodata = &node->rodata->position;
			s32 mtxindex = model0001a524(node, 0);

			sp60.x = rodata->pos.x * spd8.m[0][0] + rodata->pos.y * spd8.m[1][0] + rodata->pos.z * spd8.m[2][0] + spd8.m[3][0];
			sp60.y = rodata->pos.x * spd8.m[0][1] + rodata->pos.y * spd8.m[1][1] + rodata->pos.z * spd8.m[2][1] + spd8.m[3][1];
			sp60.z = rodata->pos.x * spd8.m[0][2] + rodata->pos.y * spd8.m[1][2] + rodata->pos.z * spd8.m[2][2] + spd8.m[3][2];

			mtx4LoadIdentity(&sp70);
			mtx4Align(sp70.m, RANDOMFRAC() * M_BADTAU, -sp60.x, -sp60.y, -sp60.z);
			mtx00015f04(0.10000001f * spb4, &sp70);

			mtx = (Mtxf *)allocation;

			mtx00016e98(arg10->m, 0, mtx->m[3][0] - hand->aimpos.x, mtx->m[3][1] - hand->aimpos.y, mtx->m[3][2] - hand->aimpos.z);
			mtx4MultMtx4InPlace(arg10, &sp70);
			mtx00016710(sway, sp70.m);
			mtx4MultMtx4InPlace(arg9, &sp70);
			mtx4SetTranslation(&sp60, &sp70);

			mtx = (Mtxf *)allocation;
			mtx += mtxindex;

			mtx4Copy(&sp70, mtx);
		}
	}
}

/**
 * Create casing and beam for a fired weapon,
 * and uncloak if the weapon is a throwable or fired projectile.
 */
void bgunCreateFx(struct hand *hand, s32 handnum, struct weaponfunc *funcdef, s32 weaponnum, struct modelfiledata *modeldef, u8 *allocation)
{
	f32 ground;
	bool createbeam = true;

	g_Vars.currentplayer->gunctrl.unk1583_04 = false;

	if (funcdef) {
		ground = g_Vars.currentplayer->vv_ground;

		if (modeldef && weaponnum != WEAPON_DY357MAGNUM && weaponnum != WEAPON_DY357LX) {
			s32 partnum = MODELPART_PISTOL_003C;
			struct modelnode *node;

			if (weaponnum == WEAPON_REAPER) {
				partnum = (hand->burstbullets & 1) == 1 ? MODELPART_REAPER_0030 : MODELPART_REAPER_0031;
			}

			node = modelGetPart(modeldef, partnum);

			if (node) {
				Mtxf *mtx = (Mtxf *)allocation;
				Mtxf sp24;

				mtx += model0001a524(node, 0);

				mtx4Copy(mtx, &sp24);
				mtx00015f04(9.999999f, &sp24);
				mtx4MultMtx4InPlace(camGetProjectionMtxF(), &sp24);

				casingCreateForHand(handnum, ground, &sp24);
			} else {
				casingCreateForHand(handnum, ground, &hand->posmtx);
			}

			bgunSetPartVisible(MODELPART_CMP150_0046, false, hand, modeldef);
			bgunSetPartVisible(MODELPART_CMP150_0047, true, hand, modeldef);
		}

		if (funcdef->type == INVENTORYFUNCTYPE_SHOOT_PROJECTILE) {
			chrUncloakTemporarily(g_Vars.currentplayer->prop->chr);
		} else if ((funcdef->type & 0xff) == INVENTORYFUNCTYPE_THROW) {
			chrUncloakTemporarily(g_Vars.currentplayer->prop->chr);
		}
	}

	if (funcdef) {
		if ((funcdef->type & 0xff) == INVENTORYFUNCTYPE_CLOSE || (funcdef->type & INVENTORYFUNCTYPE_0200)) {
			createbeam = false;
		}

		if ((funcdef->type & 0xff) == INVENTORYFUNCTYPE_SPECIAL) {
			createbeam = false;
		}

		if ((funcdef->type & 0xff) == INVENTORYFUNCTYPE_THROW) {
			createbeam = false;
		}
	}

	if (createbeam) {
		switch (weaponnum) {
		case WEAPON_FALCON2:
		case WEAPON_FALCON2_SILENCER:
		case WEAPON_FALCON2_SCOPE:
		case WEAPON_MAGSEC4:
		case WEAPON_MAULER:
		case WEAPON_PHOENIX:
		case WEAPON_DY357MAGNUM:
		case WEAPON_DY357LX:
		case WEAPON_CMP150:
		case WEAPON_CYCLONE:
		case WEAPON_CALLISTO:
		case WEAPON_RCP120:
		case WEAPON_LAPTOPGUN:
		case WEAPON_DRAGON:
		case WEAPON_K7AVENGER:
		case WEAPON_AR34:
		case WEAPON_SUPERDRAGON:
		case WEAPON_REAPER:
		case WEAPON_SNIPERRIFLE:
		case WEAPON_FARSIGHT:
		case WEAPON_TRANQUILIZER:
		case WEAPON_PP9I:
		case WEAPON_CC13:
		case WEAPON_KL01313:
		case WEAPON_KF7SPECIAL:
		case WEAPON_ZZT:
		case WEAPON_DMC:
		case WEAPON_AR53:
		case WEAPON_RCP45:
			beamCreateForHand(handnum);
			hand->numfires++;
			return;
		case WEAPON_LASER:
			hand->numfires++;
			beamCreateForHand(handnum);
			break;
		}
	}
}

void bgun0f0a5550(s32 handnum)
{
	u8 *mtxallocation;
	Mtxf sp2c4;
	Mtxf sp284;
	struct modelfiledata *modeldef = NULL;
	struct coord sp274 = {0, 0, 0};
	Mtxf sp234;
	Mtxf sp1f4;
	union modelrodata *rodata;
	bool *sp1e4[3] = {NULL, NULL, NULL};
	s32 sp1e0 = 0;
	struct modelnode *node;
	struct player *player = g_Vars.currentplayer;
	struct hand *hand = player->hands + handnum;
	struct weaponfunc *funcdef;
	struct weaponfunc_shoot *shootfunc = NULL;
	s32 i;
	s32 weaponnum = bgunGetWeaponNum2(handnum);
	struct weapon *weapondef;
	Mtxf *mtx;
	bool isdetonator = false;
	f32 fspare1;
	f32 fspare2;
	struct coord sp1a4;
	Mtxf sp164;
	Mtxf sp124;
	struct coord sp118;
	s32 j;

	weapondef = weaponFindById(weaponnum);

	if (handnum == HAND_LEFT && weaponnum == WEAPON_REMOTEMINE) {
		isdetonator = true;
	}

	funcdef = gsetGetWeaponFunction2(&hand->gset);

	if (funcdef && (funcdef->type & 0xff) == INVENTORYFUNCTYPE_SHOOT) {
		shootfunc = (struct weaponfunc_shoot *)funcdef;
	}

	bgunUpdateBlend(hand, handnum);

	if (handnum == HAND_RIGHT) {
		if (weaponHasFlag(bgunGetWeaponNum2(HAND_LEFT), WEAPONFLAG_00000040)) {
			hand->xshift += 2.0f * g_Vars.lvupdate240freal / 240.0f;

			if (hand->xshift > 2.0f) {
				hand->xshift = 2.0f;
			}
		} else {
			hand->xshift -= 2.0f * g_Vars.lvupdate240freal / 240.0f;

			if (hand->xshift < 0.0f) {
				hand->xshift = 0.0f;
			}
		}
	} else {
		if (weaponHasFlag(bgunGetWeaponNum2(HAND_RIGHT), WEAPONFLAG_00000040)) {
			hand->xshift -= 2.0f * g_Vars.lvupdate240freal / 240.0f;

			if (hand->xshift < -2.0f) {
				hand->xshift = -2.0f;
			}
		} else {
			hand->xshift += 2.0f * g_Vars.lvupdate240freal / 240.0f;

			if (hand->xshift > 0.0f) {
				hand->xshift = 0.0f;
			}
		}
	}

	if (handnum == HAND_RIGHT) {
		sp274.x = func0f0b131c(handnum) + hand->damppos.f[0] + hand->adjustpos.f[0];
		sp274.y = weapondef->updown + hand->damppos.f[1] + hand->adjustpos.f[1];
		sp274.z = weapondef->frontback + hand->damppos.f[2] + hand->adjustpos.f[2];
	} else if (isdetonator) {
		sp274.x = 6.5f + hand->damppos.f[0] - hand->adjustpos.f[0];
		sp274.y = -16.5f + hand->damppos.f[1] + hand->adjustpos.f[1];
		sp274.z = -16.0f + hand->damppos.f[2] + hand->adjustpos.f[2];
	} else {
		sp274.x = func0f0b131c(handnum) + hand->damppos.f[0] - hand->adjustpos.f[0];
		sp274.y = weapondef->updown + hand->damppos.f[1] + hand->adjustpos.f[1];
		sp274.z = weapondef->frontback + hand->damppos.f[2] + hand->adjustpos.f[2];
	}

	sp274.y += player->guncloseroffset * 5.0f / -90.0f * 50.0f;
	sp274.z -= player->guncloseroffset * 15.0f / -90.0f * 50.0f;

	if (hand->firing && shootfunc && g_Vars.lvupdate240 != 0 && shootfunc->unk14 != NULL) {
		sp274.x += (RANDOMFRAC() - 0.5f) * shootfunc->unk14->minradius * hand->finalmult[0];
		sp274.y += (RANDOMFRAC() - 0.5f) * shootfunc->unk14->maxradius * hand->finalmult[0];
		sp274.z += (RANDOMFRAC() - 0.5f) * shootfunc->unk14->incradius * hand->finalmult[0];
	}

	hand->fspare1 = (player->crosspos2[0] - camGetScreenLeft() - camGetScreenWidth() * 0.5f) * weapondef->eptr->unk0c / (camGetScreenWidth() * 0.5f);

	if (player->crosspos2[1] - camGetScreenTop() > camGetScreenHeight() * 0.5f) {
		hand->fspare2 = (player->crosspos2[1] - camGetScreenTop() - camGetScreenHeight() * 0.5f) * weapondef->eptr->unk08 / (camGetScreenHeight() * 0.5f);
	} else {
		hand->fspare2 = (player->crosspos2[1] - camGetScreenTop() - camGetScreenHeight() * 0.5f) * weapondef->eptr->unk04 / (camGetScreenHeight() * 0.5f);
	}

	fspare1 = hand->fspare1;
	fspare2 = hand->fspare2;

	sp274.f[0] += fspare1;
	sp274.f[1] -= fspare2;

	hand->visible = true;

	if (!weaponHasFlag(weaponnum, WEAPONFLAG_00000040)
			|| weaponHasFlag(weaponnum, WEAPONFLAG_00000080)
			|| hand->mode == HANDMODE_6
			|| hand->mode == HANDMODE_7
			|| !bgun0f09dd7c()
			|| hand->inuse == false
			|| bgunGetGunMemType() == 0) {
		hand->visible = false;
	}

	if (hand->visible) {
		modeldef = player->gunctrl.gunmodeldef;
		mtxallocation = gfxAllocate(modeldef->nummatrices * sizeof(Mtxf));

		if (weaponHasFlag(weaponnum, WEAPONFLAG_02000000)) {
			for (i = 0; i < modeldef->nummatrices; i++) {
				mtx = (Mtxf *)(mtxallocation + i * sizeof(Mtxf));
				mtx4LoadIdentity(mtx);
			}
		}

		bgunExecuteModelCmdList(hand->unk0dcc);

		if (player->gunctrl.handmodeldef != NULL) {
			bgunExecuteModelCmdList(hand->unk0dd0);
		}

		bgun0f098030(hand, modeldef);

		if (weaponHasFlag(weaponnum, WEAPONFLAG_00002000)) {
			bgun0f0981e8(hand, modeldef);
		}
	}

	mtx4LoadIdentity(&sp234);

	if (PLAYERCOUNT() == 1 && IS8MB() && weaponHasFlag(weaponnum, WEAPONFLAG_GANGSTA)) {
		bgunUpdateGangsta(hand, handnum, &sp274, funcdef, &sp284, &sp234);
	}

	if (hand->useposrot) {
		sp274.f[0] += hand->posrotmtx.m[3][0];
		sp274.f[1] += hand->posrotmtx.m[3][1];
		sp274.f[2] += hand->posrotmtx.m[3][2];

		mtx00015be0(&hand->posrotmtx, &sp234);

		sp234.m[3][0] = 0.0f;
		sp234.m[3][1] = 0.0f;
		sp234.m[3][2] = 0.0f;
	} else {
		hand->rotxoffset = 0.0f;
		hand->posoffset.x = 0.0f;
		hand->posoffset.y = 0.0f;
		hand->posoffset.z = 0.0f;
	}

	mtx00016d58(&sp284, 0.0f, 0.0f, 0.0f,
			hand->damplook.x, hand->damplook.y, hand->damplook.z,
			hand->dampup.x, hand->dampup.y, hand->dampup.z);

	mtx00015be0(&sp284, &sp234);

	sp1a4.x = 0.0f;
	sp1a4.y = M_PI;
	sp1a4.z = 0.0f;

	mtx4LoadRotation(&sp1a4, &sp164);

	sp1a4.y = 0.0f;

	bgun0f0a24f0(&sp118, handnum);

	sp1a4.y = -bgun0f0a2498(sp118.x, sp118.z, sp274.f[0], sp274.f[2]);
	sp1a4.x = bgun0f0a2498(sp118.y, sp118.z, sp274.f[1], sp274.f[2]);

	hand->lastrotangx = sp1a4.f[0];
	hand->lastrotangy = sp1a4.f[1];

	mtx4LoadRotation(&sp1a4, &sp124);
	mtx4MultMtx4(&sp124, &sp164, &sp284);
	mtx4MultMtx4InPlace(&sp284, &sp234);
	mtx4Copy(&sp234, &sp2c4);
	mtx4SetTranslation(&sp274, &sp2c4);

	mtx4Copy(&sp2c4, &hand->cammtx);
	mtx4Copy(&hand->posmtx, &hand->prevmtx);

	mtx00015be4(camGetProjectionMtxF(), &hand->cammtx, &hand->posmtx);

	if (hand->visible) {
		for (j = 0x5a; j < 0x5d; j++) {
			node = modelGetPart(modeldef, j);

			if (node) {
				rodata = node->rodata;
				sp1e4[sp1e0] = (bool *)&hand->unk0a6c[rodata->toggle.rwdataindex];
				sp1e0++;
			}
		}

		hand->gunmodel.matrices = (Mtxf *)mtxallocation;
		hand->handmodel.matrices = (Mtxf *)mtxallocation;

		if (weaponHasFlag(weaponnum, WEAPONFLAG_DUALFLIP) && handnum == HAND_LEFT) {
			mtx00015e24(-1, &sp2c4);
		}

		mtx00015f04(0.10000001f, &sp2c4);

		mtx4Copy(&sp2c4, (Mtxf *)mtxallocation);

		if (hand->unk0cc8_04 > 0) {
			switch (weaponnum) {
			case WEAPON_GRENADE:
			case WEAPON_NBOMB:
				hand->unk0d0e_00 = 1;
				hand->unk0d0e_04 = 1;
				break;
			case WEAPON_TRANQUILIZER:
				hand->unk0d0e_00 = 1;
				hand->unk0d0e_04 = 2;
				break;
			}
		}

		var8009d144 = hand;

		if (hand->unk0d0e_00 > 0) {
			bgun0f0a45d0(hand, modeldef, isdetonator);
		}

		var8009d0dc = -1;
		var8009d0f0[0] = var8009d0f0[1] = var8009d0f0[2] = -1;

		switch (weaponnum) {
		case WEAPON_LASER:
			bgunUpdateLaser(hand);
			break;
		case WEAPON_REAPER:
			bgunUpdateReaper(hand, modeldef);
			break;
		}

		{
			bool a0 = true;
			struct modelrenderdata renderdata = {NULL, true, 3};
#if VERSION >= VERSION_PAL_BETA
			bool a3 = false;
#endif
			s32 spcc;
			Mtxf *spc8;
			Mtxf *spc4;
			Mtxf sp84;
			u32 sp80;
			struct coord sp74;
			s32 stack;
			s32 sp6c;

			renderdata.unk00 = &sp2c4;
			renderdata.unk10 = hand->gunmodel.matrices;

			if (hand->animmode != HANDANIMMODE_IDLE) {
				a0 = false;
			}

			switch (weaponnum) {
			case WEAPON_REAPER:
				a0 = false;
				break;
			case WEAPON_COMBATKNIFE:
				if (player->hands[HAND_LEFT].loadedammo[0] == 0) {
					a0 = false;
				}
				// fall through
			case WEAPON_GRENADE:
			case WEAPON_NBOMB:
			case WEAPON_TIMEDMINE:
			case WEAPON_PROXIMITYMINE:
			case WEAPON_REMOTEMINE:
			case WEAPON_ECMMINE:
				if (player->hands[HAND_RIGHT].loadedammo[0] == 0) {
					a0 = false;
				}

				if (player->hands[handnum].state == HANDSTATE_AUTOSWITCH) {
					a0 = false;
				}

				if (player->hands[handnum].state == HANDSTATE_ATTACK) {
					a0 = false;
				}
				break;
			}

			if (hand->unk0d0e_00) {
				a0 = false;
			}

			if (player->hands[handnum].state == HANDSTATE_CHANGEGUN
					&& player->hands[handnum].stateminor < 2
					&& weapondef->unequip_animation != NULL) {
				a0 = false;
			}

#if VERSION >= VERSION_PAL_BETA
			switch (modelGetAnimNum(&hand->gunmodel)) {
			case ANIM_GUN_CROSSBOW_EQUIP:
			case ANIM_GUN_LAPTOP_EQUIP:
			case ANIM_GUN_LAPTOP_UNEQUIP:
			case ANIM_GUN_LAPTOP_RELOAD:
			case ANIM_GUN_FALCON2_RELOAD:
			case ANIM_GUN_CMP150_RELOAD:
			case ANIM_GUN_FARSIGHT_SHOOT:
			case ANIM_GUN_SHOTGUN_SHOOT_SINGLE:
			case ANIM_GUN_REAPER_SHOOT:
			case ANIM_GUN_MAGSEC4_RELOAD:
			case ANIM_GUN_CYCLONE_RELOAD:
			case ANIM_GUN_SNIPER_RELOAD:
			case ANIM_GUN_PHOENIX_RELOAD:
			case ANIM_GUN_FALCON2_RELOAD_SCOPE:
			case ANIM_GUN_REMOTEMINE_EQUIP:
				a3 = 1;
				break;
			}
#endif

			if (a0) {
				if (player->hands[HAND_RIGHT].unk0dd4 == -1) {
					mtx4LoadIdentity(&sp84);

					spc4 = hand->gunmodel.matrices;

					renderdata.unk00 = &sp84;
					renderdata.unk10 = player->hands[HAND_RIGHT].unk0dd8;

#if VERSION >= VERSION_PAL_BETA
					var8005efd8_2 = true;

					if (a3) {
						var8005efb0_2 = true;
					}

					model0001cebc(&renderdata, &hand->gunmodel);

					var8005efd8_2 = false;

					if (a3) {
						var8005efb0_2 = false;
					}
#else
					model0001cebc(&renderdata, &hand->gunmodel);
#endif

					player->hands[HAND_RIGHT].unk0dd4 = 1;

					hand->gunmodel.matrices = spc4;
				}

				spc8 = player->hands[HAND_RIGHT].unk0dd8;
				spc4 = hand->gunmodel.matrices;

				for (spcc = 0; spcc < hand->gunmodel.filedata->nummatrices; spcc++) {
					mtx00015be4(&sp2c4, spc8, spc4);
					spc8++;
					spc4++;
				}
			} else {
#if VERSION >= VERSION_PAL_BETA
				var8005efd8_2 = true;

				if (a3) {
					var8005efb0_2 = true;
				}

				model0001cebc(&renderdata, &hand->gunmodel);

				var8005efd8_2 = false;

				if (a3) {
					var8005efb0_2 = false;
				}
#else
				model0001cebc(&renderdata, &hand->gunmodel);
#endif
			}

			g_ModelJointPositionedFunc = 0;

			node = modelGetPart(modeldef, MODELPART_PISTOL_0033);

			if (node) {
				sp80 = model0001a524(node, 0);

				bgunUpdateSlide(handnum);

				sp74.f[0] = 0.0f;
				sp74.f[1] = 0.0f;
				sp74.f[2] = -hand->slidetrans;

				mtx = (Mtxf *)mtxallocation;
				mtx += sp80;

				mtx4RotateVecInPlace(mtx, &sp74);

				mtx->m[3][0] += sp74.f[0];
				mtx->m[3][1] += sp74.f[1];
				mtx->m[3][2] += sp74.f[2];
			}

			if (sp1e4[0] != NULL) {
				*sp1e4[0] = false;
			}

			if (sp1e4[1] != NULL) {
				*sp1e4[1] = false;
			}

			if (sp1e4[2] != NULL) {
				*sp1e4[2] = false;
			}

			switch (weaponnum) {
			case WEAPON_SNIPERRIFLE:
				bgunUpdateSniperRifle(modeldef, mtxallocation);
				break;
			case WEAPON_DEVASTATOR:
				bgunUpdateDevastator(hand, mtxallocation, modeldef);
				break;
			case WEAPON_SHOTGUN:
				bgunUpdateShotgun(hand, mtxallocation, sp1e4[0], modeldef);
				break;
			}

			node = modelGetPart(modeldef, 0x32);

			if (weaponnum == WEAPON_REAPER) {
				if (hand->flashon || hand->firing) {
					node = modelGetPart(modeldef, 0x1e + (hand->burstbullets % 3));
				} else {
					node = modelGetPart(modeldef, 0x1e + (g_Vars.lvframenum % 3));
				}
			}

			if (node) {
				sp6c = model0001a524(node, 0);

				mtx = (Mtxf *)mtxallocation;
				mtx += sp6c;

				hand->muzzlepos.f[0] = mtx->m[3][0];
				hand->muzzlepos.f[1] = mtx->m[3][1];
				hand->muzzlepos.f[2] = mtx->m[3][2];

				mtx4Copy(mtx, &hand->muzzlemat);
				mtx4TransformVecInPlace(camGetProjectionMtxF(), &hand->muzzlepos);

				hand->muzzlez = -((Mtxf *)((u32)mtxallocation + sp6c * sizeof(Mtxf)))->m[3][2];

				if (hand->flashon && sp1e0 > 0 && weaponnum != WEAPON_SHOTGUN && g_Vars.lvupdate240 != 0) {
					bgun0f0a4e44(hand, weapondef, modeldef, funcdef, sp1e0, mtxallocation, weaponnum, sp1e4, sp6c, &sp234, &sp1f4);
				}
			} else if (weaponnum == WEAPON_GRENADE
					|| weaponnum == WEAPON_TIMEDMINE
					|| weaponnum == WEAPON_REMOTEMINE
					|| weaponnum == WEAPON_PROXIMITYMINE
					|| weaponnum == WEAPON_NBOMB) {
				sp6c = model0001a524(modelGetPart(modeldef, 0x37), 0);

				mtx = (Mtxf *)mtxallocation;
				mtx += sp6c;

				hand->muzzlepos.x = mtx->m[3][0];
				hand->muzzlepos.y = mtx->m[3][1];
				hand->muzzlepos.z = mtx->m[3][2];

				mtx4Copy(mtx, &hand->muzzlemat);
				mtx4TransformVecInPlace(camGetProjectionMtxF(), &hand->muzzlepos);

				hand->muzzlez = -((Mtxf *)((u32)mtxallocation + sp6c * sizeof(Mtxf)))->m[3][2];
			} else {
				hand->muzzlepos.x = hand->posmtx.m[3][0];
				hand->muzzlepos.y = hand->posmtx.m[3][1];
				hand->muzzlepos.z = hand->posmtx.m[3][2];

				mtx4Copy(&hand->posmtx, &hand->muzzlemat);

				hand->muzzlez = -hand->cammtx.m[3][2];
			}
		}
	} else {
		hand->muzzlepos.x = hand->posmtx.m[3][0];
		hand->muzzlepos.y = hand->posmtx.m[3][1];
		hand->muzzlepos.z = hand->posmtx.m[3][2];

		mtx4Copy(&hand->posmtx, &hand->muzzlemat);

		hand->muzzlez = -hand->cammtx.m[3][2];
	}

	switch (weaponnum) {
	case WEAPON_ROCKETLAUNCHER:
		bgunUpdateRocketLauncher(hand, handnum, (struct weaponfunc_shootprojectile *)funcdef);
		break;
	case WEAPON_DY357MAGNUM:
	case WEAPON_DY357LX:
		if (hand->unk0cc8_04 > 0) {
			bgunUpdateMagnum(hand, handnum, modeldef, (Mtxf *)mtxallocation);
		}
		break;
	}

	if (hand->firing && g_Vars.lvupdate240 != 0) {
		bgunCreateFx(hand, handnum, funcdef, weaponnum, modeldef, mtxallocation);
	}

	if (PLAYERCOUNT() == 1 && IS8MB() && g_Vars.lvupdate240 != 0) {
		bgunUpdateSmoke(hand, handnum, weaponnum, funcdef);
	}

	if (hand->unk0d0e_00 > 0) {
		bgun0f0a46a4(hand, modeldef, isdetonator);
	}

	if (PLAYERCOUNT() == 1 && IS8MB() && hand->visible
			&& weaponnum >= WEAPON_FALCON2 && weaponnum <= WEAPON_FALCON2_SCOPE) {
		bgunUpdateLasersight(hand, modeldef, handnum, mtxallocation);
	} else {
		lasersightFree(handnum);
	}

	hand->animframeinc = 0;

#if VERSION >= VERSION_PAL_BETA
	hand->animframeincfreal = 0;
#endif
}

void bgunTickMaulerCharge(void)
{
	struct player *player = g_Vars.currentplayer;
	s32 i;

	for (i = 0; i < 2; i++) {
		struct hand *hand = &player->hands[i];
		u32 charging = false;

		if (hand->inuse) {
			if (bgunIsReloading(hand)) {
				// Reloading - reset charge amount
				hand->matmot1 = 0;
			} else if (hand->gset.weaponfunc == FUNC_SECONDARY) {
				// Charging or fully charged
				s32 oldvalue = hand->matmot1;
				s32 newvalue;

				if (hand->loadedammo[0] >= 2 && hand->matmot1 < 5) {
					charging = true;
					hand->matmot1 += g_Vars.lvupdate240freal * 0.05f;
				}

				if (hand->matmot1 > 5) {
					hand->matmot1 = 5;
				}

				newvalue = hand->matmot1;

				if (oldvalue != newvalue && hand->loadedammo[0] >= 2) {
					hand->loadedammo[0]--;
				}
			} else {
				// Using primary function - make the charge wear off slowly
				hand->matmot1 -= g_Vars.lvupdate240freal * 0.005f;

				if (hand->matmot1 < 0) {
					hand->matmot1 = 0;
				}
			}

			/**
			 * Probable @bug: In other places where audio is started and then
			 * its speed is adjusted, the game raises the priority of the main
			 * thread (this thread) to above the audio thread's priority so that
			 * the audio thread cannot execute and start playing the audio
			 * between the calls to sndStart and audioPostEvent. But this pattern
			 * is not done here.
			 *
			 * There is a known issue where the Mauler charge sound is played
			 * correctly then the game proceeds to play other unrelated sound
			 * effects before eventually crashing. It's suspected that this lack
			 * of thread priority adjusting is the root cause. Perhaps a race
			 * condition exists where the audio thread does something with the
			 * sound while this thread is in the middle of reconfiguring it.
			 * This is not yet confirmed.
			 */
			if (hand->audiohandle == NULL
					&& hand->matmot1 > 0.1f
					&& charging
					&& g_Vars.lvupdate240 != 0) {
				sndStart(var80095200, SFX_MAULER_CHARGE, &hand->audiohandle, -1, -1, -1, -1, -1);
			}

			if (hand->audiohandle) {
				f32 speed = 0.5f + hand->matmot1 / 3.0f + sinf(var80061630 * M_PI * 32.0f) * 0.03f;

				if (hand->matmot1 < 0.1f || !charging) {
					audioStop(hand->audiohandle);
				} else {
					audioPostEvent(hand->audiohandle, 16, *(s32 *)&speed);
				}
			}
		}
	}
}

void bgunTickGameplay2(void)
{
	struct player *player = g_Vars.currentplayer;
	struct hand *hand;
	u32 stack[3];
	s32 i;

#if VERSION >= VERSION_NTSC_1_0
	if (g_Vars.currentplayernum == 0) {
		projectilesDebug();
	}
#endif

	if (player->gunctrl.unk1583_06) {
		// empty
	} else {
		bgunTickLoad();
	}

	// Return control to Jo if eyespy has been deselected
	if ((g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY) == 0
			&& player->eyespy) {
		player->eyespy->active = false;
	}

	if ((g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_XRAYSCANNER)
			&& (bgunGetWeaponNum(HAND_RIGHT) != WEAPON_FARSIGHT || player->gunsightoff)) {
		// Using normal xray scanner (not Farsight zoom)
		if (player->visionmode != VISIONMODE_XRAY) {
			player->erasertime = 0;
		} else {
			player->erasertime += g_Vars.lvupdate240;
		}

		player->visionmode = VISIONMODE_XRAY;
		player->ecol_1 = 24;
		player->ecol_2 = 8;
		player->ecol_3 = 24;
		player->epcol_0 = 2;
		player->epcol_1 = 0;
		player->epcol_2 = 1;
	} else {
		if (player->gunsightoff == 0) {
			if (player->hands[HAND_RIGHT].gset.weaponnum == WEAPON_FARSIGHT) {
				// Aiming with the Farsight
				if (player->visionmode != VISIONMODE_XRAY) {
					player->erasertime = 0;
				} else {
					player->erasertime += g_Vars.lvupdate240;
				}

				player->visionmode = VISIONMODE_XRAY;
				player->ecol_1 = 16;
				player->ecol_2 = 24;
				player->ecol_3 = 8;
				player->epcol_0 = 0;
				player->epcol_1 = 1;
				player->epcol_2 = 2;
			} else {
				// Aiming with non-Farsight
				if (player->visionmode != VISIONMODE_SLAYERROCKET) {
					player->visionmode = VISIONMODE_NORMAL;
				}
			}
		} else {
			// Not aiming
			if (player->visionmode != VISIONMODE_SLAYERROCKET) {
				player->visionmode = VISIONMODE_NORMAL;
			}
		}
	}

	if (player->gunctrl.weaponnum == WEAPON_MAULER) {
		bgunTickMaulerCharge();
	}

	if (g_Vars.lvupdate240 == 0) {
		for (i = 0; i < 2; i++) {
			hand = &player->hands[i];

			if (hand->audiohandle) {
				audioStop(hand->audiohandle);
			}
		}
	}

	if (g_Vars.currentplayer->devicesactive &
			~g_Vars.currentplayer->devicesinhibit & DEVICE_CLOAKRCP120) {
		if (player->gunctrl.weaponnum == WEAPON_RCP120) {
			struct chrdata *chr = player->prop->chr;

			// Handle RCP120 cloak ammo usage
			if ((chr->hidden & CHRHFLAG_CLOAKED) && chr->cloakfadefinished == true) {
				hand = &player->hands[HAND_RIGHT];
				hand->matmot1 += LVUPDATE240FREAL() * 0.4f;

				if (hand->matmot1 > 1.0f) {
					s32 usedqty = hand->matmot1;

					if (usedqty > hand->loadedammo[0]) {
						usedqty = hand->loadedammo[0];
					}

					hand->matmot1 -= usedqty;
					hand->loadedammo[0] -= usedqty;

					// If out of ammo, turn off cloak
					if (hand->loadedammo[0] == 0 && hand->state != HANDSTATE_RELOAD) {
						s32 stilltogo = hand->matmot1;

						if (stilltogo > player->ammoheldarr[player->gunctrl.ammotypes[0]]) {
							g_Vars.currentplayer->devicesactive &= ~DEVICE_CLOAKRCP120;
						}
					}
				}
			}
		} else {
			// No longer using RCP120, so turn off cloak
			player->devicesactive &= ~DEVICE_CLOAKRCP120;
		}
	} else if (player->gunctrl.weaponnum == WEAPON_RCP120) {
		hand = &player->hands[HAND_RIGHT];

		// I think this is handling situations where the player has turned off
		// RCP120 cloak but there's still a bit of ammo to be subtracted on
		// this tick.
		if (hand->matmot1 > 1.0f) {
			s32 usedqty = hand->matmot1;

			if (usedqty > hand->loadedammo[0]) {
				usedqty = hand->loadedammo[0];
			}

			hand->matmot1 -= usedqty;
			hand->loadedammo[0] -= usedqty;

			if (hand->matmot1 > 1.0f) {
				s32 usedqty = hand->matmot1;

				if (usedqty > player->ammoheldarr[player->gunctrl.ammotypes[0]]) {
					usedqty = player->ammoheldarr[player->gunctrl.ammotypes[0]];
				}

				player->ammoheldarr[player->gunctrl.ammotypes[0]] -= usedqty;
				hand->matmot1 = 0;
			}
		}
	}

	bgunTickUnequippedReload();
	bgun0f0a5550(HAND_RIGHT);

	if (player->hands[HAND_LEFT].inuse) {
		bgun0f0a5550(HAND_LEFT);
	} else {
		player->hands[HAND_LEFT].unk0d0e_00 = 0;
	}

	bgunIsUsingSecondaryFunction();
}

s8 bgunFreeFireslotWrapper(s32 slotnum)
{
#if VERSION < VERSION_NTSC_1_0
	if (slotnum >= 0) {
		if (g_Fireslots[slotnum].unk04nb && sndGetState(g_Fireslots[slotnum].unk04nb) != AL_STOPPED) {
			audioStop(g_Fireslots[slotnum].unk04nb);
		}

		if (g_Fireslots[slotnum].unk08nb && sndGetState(g_Fireslots[slotnum].unk08nb) != AL_STOPPED) {
			audioStop(g_Fireslots[slotnum].unk08nb);
		}
	}
#endif

	return bgunFreeFireslot(slotnum);
}

s8 bgunFreeFireslot(s32 fireslot_id)
{
#if VERSION >= VERSION_NTSC_1_0
	if (fireslot_id >= 0 && fireslot_id < NUM_FIRESLOTS) {
		g_Fireslots[fireslot_id].endlvframe = -1;
	}
#else
	if (fireslot_id >= 0) {
		g_Fireslots[fireslot_id].endlvframe = -1;
	}
#endif

	return -1;
}

s32 bgunAllocateFireslot(void)
{
	s32 index = -1;
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Fireslots); i++) {
		if (g_Fireslots[i].endlvframe < 0) {
			g_Fireslots[i].endlvframe = 0;

#if VERSION < VERSION_NTSC_1_0
			g_Fireslots[i].unk04nb = 0;
			g_Fireslots[i].unk08nb = 0;
#endif

			g_Fireslots[i].beam.age = -1;
			index = i;
			break;
		}
	}

	return index;
}

u32 var8007029c = 0x00000000;
u32 var800702a0 = 0x00000001;
u32 var800702a4 = 0x00000003;
u32 var800702a8 = 0x00000000;
u32 var800702ac = 0x00000000;
u32 var800702b0 = 0x00000000;
u32 var800702b4 = 0x00000000;
u32 var800702b8 = 0x00000000;
u32 var800702bc = 0x00000000;
u32 var800702c0 = 0x00000000;
u32 var800702c4 = 0x00000000;
u32 var800702c8 = 0x00000000;
u32 var800702cc = 0x00000000;
u32 var800702d0 = 0x00000000;
u32 var800702d4 = 0x00000000;
u32 var800702d8 = 0x00000000;
u32 var800702dc = 0x00000001;

#if MATCHING
#if PAL
GLOBAL_ASM(
glabel bgunRender
.late_rodata
glabel var7f1aca8c
.word 0x3faaaaab
glabel var7f1aca90
.word 0x3f3ebebf
.text
/*  f0a7138:	27bdfeb0 */ 	addiu	$sp,$sp,-336
/*  f0a713c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0a7140:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f0a7144:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f0a7148:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f0a714c:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0a7150:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0a7154:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0a7158:	afa40150 */ 	sw	$a0,0x150($sp)
/*  f0a715c:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f0a7160:	3c198007 */ 	lui	$t9,%hi(var8007029c)
/*  f0a7164:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f0a7168:	2739029c */ 	addiu	$t9,$t9,%lo(var8007029c)
/*  f0a716c:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f0a7170:	272a003c */ 	addiu	$t2,$t9,0x3c
/*  f0a7174:	27b8010c */ 	addiu	$t8,$sp,0x10c
/*  f0a7178:	afaf014c */ 	sw	$t7,0x14c($sp)
.L0f0a717c:
/*  f0a717c:	8f210000 */ 	lw	$at,0x0($t9)
/*  f0a7180:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f0a7184:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f0a7188:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f0a718c:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f0a7190:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f0a7194:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f0a7198:	172afff8 */ 	bne	$t9,$t2,.L0f0a717c
/*  f0a719c:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f0a71a0:	8f210000 */ 	lw	$at,0x0($t9)
/*  f0a71a4:	af010000 */ 	sw	$at,0x0($t8)
/*  f0a71a8:	8e330284 */ 	lw	$s3,0x284($s1)
/*  f0a71ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a71b0:	966b0010 */ 	lhu	$t3,0x10($s3)
/*  f0a71b4:	1561000d */ 	bne	$t3,$at,.L0f0a71ec
/*  f0a71b8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a71bc:	24040f48 */ 	addiu	$a0,$zero,0xf48
/*  f0a71c0:	8e2c0284 */ 	lw	$t4,0x284($s1)
.L0f0a71c4:
/*  f0a71c4:	01821821 */ 	addu	$v1,$t4,$v0
/*  f0a71c8:	8c6d0854 */ 	lw	$t5,0x854($v1)
/*  f0a71cc:	244207a4 */ 	addiu	$v0,$v0,0x7a4
/*  f0a71d0:	11a00002 */ 	beqz	$t5,.L0f0a71dc
/*  f0a71d4:	00000000 */ 	nop
/*  f0a71d8:	ac600850 */ 	sw	$zero,0x850($v1)
.L0f0a71dc:
/*  f0a71dc:	5444fff9 */ 	bnel	$v0,$a0,.L0f0a71c4
/*  f0a71e0:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f0a71e4:	100002d5 */ 	b	.L0f0a7d3c
/*  f0a71e8:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0a71ec:
/*  f0a71ec:	0fc5d9ad */ 	jal	mblurRender
/*  f0a71f0:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a71f4:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a71f8:	0c002ca0 */ 	jal	vi0000b280
/*  f0a71fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a7200:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a7204:	0c002c74 */ 	jal	vi0000b1d0
/*  f0a7208:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a720c:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f0a7210:	afae014c */ 	sw	$t6,0x14c($sp)
/*  f0a7214:	0c002f40 */ 	jal	viGetViewLeft
/*  f0a7218:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0a721c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a7220:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0a7224:	0c002f44 */ 	jal	viGetViewTop
/*  f0a7228:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0a722c:	44822000 */ 	mtc1	$v0,$f4
/*  f0a7230:	44908000 */ 	mtc1	$s0,$f16
/*  f0a7234:	3c014080 */ 	lui	$at,0x4080
/*  f0a7238:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a723c:	44810000 */ 	mtc1	$at,$f0
/*  f0a7240:	3c01ed00 */ 	lui	$at,0xed00
/*  f0a7244:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0a7248:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a724c:	00000000 */ 	nop
/*  f0a7250:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0a7254:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0a7258:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0a725c:	44085000 */ 	mfc1	$t0,$f10
/*  f0a7260:	440b3000 */ 	mfc1	$t3,$f6
/*  f0a7264:	310a0fff */ 	andi	$t2,$t0,0xfff
/*  f0a7268:	0141c825 */ 	or	$t9,$t2,$at
/*  f0a726c:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f0a7270:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f0a7274:	032d7025 */ 	or	$t6,$t9,$t5
/*  f0a7278:	0c002f22 */ 	jal	viGetViewWidth
/*  f0a727c:	aeae0000 */ 	sw	$t6,0x0($s5)
/*  f0a7280:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0a7284:	00127c03 */ 	sra	$t7,$s2,0x10
/*  f0a7288:	0c002f40 */ 	jal	viGetViewLeft
/*  f0a728c:	01e09025 */ 	or	$s2,$t7,$zero
/*  f0a7290:	0002a400 */ 	sll	$s4,$v0,0x10
/*  f0a7294:	00144c03 */ 	sra	$t1,$s4,0x10
/*  f0a7298:	0c002f44 */ 	jal	viGetViewTop
/*  f0a729c:	0120a025 */ 	or	$s4,$t1,$zero
/*  f0a72a0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a72a4:	00104403 */ 	sra	$t0,$s0,0x10
/*  f0a72a8:	0c002f26 */ 	jal	viGetViewHeight
/*  f0a72ac:	01008025 */ 	or	$s0,$t0,$zero
/*  f0a72b0:	00505021 */ 	addu	$t2,$v0,$s0
/*  f0a72b4:	448a4000 */ 	mtc1	$t2,$f8
/*  f0a72b8:	0292c821 */ 	addu	$t9,$s4,$s2
/*  f0a72bc:	44992000 */ 	mtc1	$t9,$f4
/*  f0a72c0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0a72c4:	3c014080 */ 	lui	$at,0x4080
/*  f0a72c8:	44810000 */ 	mtc1	$at,$f0
/*  f0a72cc:	3c053fc0 */ 	lui	$a1,0x3fc0
/*  f0a72d0:	3c06447a */ 	lui	$a2,0x447a
/*  f0a72d4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a72d8:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0a72dc:	00000000 */ 	nop
/*  f0a72e0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a72e4:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0a72e8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0a72ec:	440b9000 */ 	mfc1	$t3,$f18
/*  f0a72f0:	440e5000 */ 	mfc1	$t6,$f10
/*  f0a72f4:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f0a72f8:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f0a72fc:	000f4b00 */ 	sll	$t1,$t7,0xc
/*  f0a7300:	01894025 */ 	or	$t0,$t4,$t1
/*  f0a7304:	aea80004 */ 	sw	$t0,0x4($s5)
/*  f0a7308:	0c002b29 */ 	jal	vi0000aca4
/*  f0a730c:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a7310:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f0a7314:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a7318:	91581bfc */ 	lbu	$t8,0x1bfc($t2)
/*  f0a731c:	53000016 */ 	beqzl	$t8,.L0f0a7378
/*  f0a7320:	8e2b006c */ 	lw	$t3,0x6c($s1)
/*  f0a7324:	0fc54bc7 */ 	jal	optionsGetScreenRatio
/*  f0a7328:	00000000 */ 	nop
/*  f0a732c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a7330:	14410008 */ 	bne	$v0,$at,.L0f0a7354
/*  f0a7334:	00000000 */ 	nop
/*  f0a7338:	0fc2f4d6 */ 	jal	player0f0bd358
/*  f0a733c:	00000000 */ 	nop
/*  f0a7340:	3c017f1b */ 	lui	$at,%hi(var7f1aca8c)
/*  f0a7344:	c430ca8c */ 	lwc1	$f16,%lo(var7f1aca8c)($at)
/*  f0a7348:	46100082 */ 	mul.s	$f2,$f0,$f16
/*  f0a734c:	10000005 */ 	b	.L0f0a7364
/*  f0a7350:	44061000 */ 	mfc1	$a2,$f2
.L0f0a7354:
/*  f0a7354:	0fc2f4d6 */ 	jal	player0f0bd358
/*  f0a7358:	00000000 */ 	nop
/*  f0a735c:	46000086 */ 	mov.s	$f2,$f0
/*  f0a7360:	44061000 */ 	mfc1	$a2,$f2
.L0f0a7364:
/*  f0a7364:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a7368:	0c002c3a */ 	jal	vi0000b0e8
/*  f0a736c:	3c054270 */ 	lui	$a1,0x4270
/*  f0a7370:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a7374:	8e2b006c */ 	lw	$t3,0x6c($s1)
.L0f0a7378:
/*  f0a7378:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a737c:	51600004 */ 	beqzl	$t3,.L0f0a7390
/*  f0a7380:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a7384:	10000002 */ 	b	.L0f0a7390
/*  f0a7388:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0a738c:	00002825 */ 	or	$a1,$zero,$zero
.L0f0a7390:
/*  f0a7390:	8e390068 */ 	lw	$t9,0x68($s1)
/*  f0a7394:	53200004 */ 	beqzl	$t9,.L0f0a73a8
/*  f0a7398:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a739c:	10000002 */ 	b	.L0f0a73a8
/*  f0a73a0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a73a4:	00002025 */ 	or	$a0,$zero,$zero
.L0f0a73a8:
/*  f0a73a8:	8e2d0064 */ 	lw	$t5,0x64($s1)
/*  f0a73ac:	51a00004 */ 	beqzl	$t5,.L0f0a73c0
/*  f0a73b0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a73b4:	10000002 */ 	b	.L0f0a73c0
/*  f0a73b8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0a73bc:	00001025 */ 	or	$v0,$zero,$zero
.L0f0a73c0:
/*  f0a73c0:	8e2e0070 */ 	lw	$t6,0x70($s1)
/*  f0a73c4:	51c00004 */ 	beqzl	$t6,.L0f0a73d8
/*  f0a73c8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a73cc:	10000002 */ 	b	.L0f0a73d8
/*  f0a73d0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0a73d4:	00001825 */ 	or	$v1,$zero,$zero
.L0f0a73d8:
/*  f0a73d8:	00627821 */ 	addu	$t7,$v1,$v0
/*  f0a73dc:	01e46021 */ 	addu	$t4,$t7,$a0
/*  f0a73e0:	01854821 */ 	addu	$t1,$t4,$a1
/*  f0a73e4:	15210008 */ 	bne	$t1,$at,.L0f0a7408
/*  f0a73e8:	3c088009 */ 	lui	$t0,%hi(g_Is4Mb)
/*  f0a73ec:	91080af0 */ 	lbu	$t0,%lo(g_Is4Mb)($t0)
/*  f0a73f0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a73f4:	51010005 */ 	beql	$t0,$at,.L0f0a740c
/*  f0a73f8:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0a73fc:	0fc2be93 */ 	jal	lasersightRenderBeam
/*  f0a7400:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a7404:	afa2014c */ 	sw	$v0,0x14c($sp)
.L0f0a7408:
/*  f0a7408:	0000a025 */ 	or	$s4,$zero,$zero
.L0f0a740c:
/*  f0a740c:	26700638 */ 	addiu	$s0,$s3,0x638
/*  f0a7410:	8fb500e4 */ 	lw	$s5,0xe4($sp)
/*  f0a7414:	24120019 */ 	addiu	$s2,$zero,0x1e
.L0f0a7418:
/*  f0a7418:	0fc2867c */ 	jal	bgunGetWeaponNum2
/*  f0a741c:	02802025 */ 	or	$a0,$s4,$zero
/*  f0a7420:	afa200ec */ 	sw	$v0,0xec($sp)
/*  f0a7424:	820a0007 */ 	lb	$t2,0x7($s0)
/*  f0a7428:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a742c:	260501dc */ 	addiu	$a1,$s0,0x1dc
/*  f0a7430:	114001f2 */ 	beqz	$t2,.L0f0a7bfc
/*  f0a7434:	00003025 */ 	or	$a2,$zero,$zero
/*  f0a7438:	26180384 */ 	addiu	$t8,$s0,0x384
/*  f0a743c:	afb8003c */ 	sw	$t8,0x3c($sp)
/*  f0a7440:	0fc2b2e4 */ 	jal	beamRender
/*  f0a7444:	00003825 */ 	or	$a3,$zero,$zero
/*  f0a7448:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a744c:	92040000 */ 	lbu	$a0,0x0($s0)
/*  f0a7450:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a7454:	34058000 */ 	dli	$a1,0x8000
/*  f0a7458:	10400030 */ 	beqz	$v0,.L0f0a751c
/*  f0a745c:	8fab014c */ 	lw	$t3,0x14c($sp)
/*  f0a7460:	25790008 */ 	addiu	$t9,$t3,0x8
/*  f0a7464:	afb9014c */ 	sw	$t9,0x14c($sp)
/*  f0a7468:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f0a746c:	3c0e8000 */ 	lui	$t6,0x8000
/*  f0a7470:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f0a7474:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f0a7478:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f0a747c:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f0a7480:	8faf014c */ 	lw	$t7,0x14c($sp)
/*  f0a7484:	3c090386 */ 	lui	$t1,0x386
/*  f0a7488:	3c088007 */ 	lui	$t0,%hi(var80070098)
/*  f0a748c:	25ec0008 */ 	addiu	$t4,$t7,0x8
/*  f0a7490:	afac014c */ 	sw	$t4,0x14c($sp)
/*  f0a7494:	25080098 */ 	addiu	$t0,$t0,%lo(var80070098)
/*  f0a7498:	35290010 */ 	ori	$t1,$t1,0x10
/*  f0a749c:	ade90000 */ 	sw	$t1,0x0($t7)
/*  f0a74a0:	ade80004 */ 	sw	$t0,0x4($t7)
/*  f0a74a4:	8faa014c */ 	lw	$t2,0x14c($sp)
/*  f0a74a8:	3c0b0388 */ 	lui	$t3,0x388
/*  f0a74ac:	3c198007 */ 	lui	$t9,%hi(var80070090)
/*  f0a74b0:	25580008 */ 	addiu	$t8,$t2,0x8
/*  f0a74b4:	afb8014c */ 	sw	$t8,0x14c($sp)
/*  f0a74b8:	27390090 */ 	addiu	$t9,$t9,%lo(var80070090)
/*  f0a74bc:	356b0010 */ 	ori	$t3,$t3,0x10
/*  f0a74c0:	ad4b0000 */ 	sw	$t3,0x0($t2)
/*  f0a74c4:	ad590004 */ 	sw	$t9,0x4($t2)
/*  f0a74c8:	8fad014c */ 	lw	$t5,0x14c($sp)
/*  f0a74cc:	3c0f0384 */ 	lui	$t7,0x384
/*  f0a74d0:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f0a74d4:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0a74d8:	afae014c */ 	sw	$t6,0x14c($sp)
/*  f0a74dc:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0a74e0:	0fc2d5ea */ 	jal	camGetLookAt
/*  f0a74e4:	afad00d4 */ 	sw	$t5,0xd4($sp)
/*  f0a74e8:	8fa500d4 */ 	lw	$a1,0xd4($sp)
/*  f0a74ec:	3c080382 */ 	lui	$t0,0x382
/*  f0a74f0:	35080010 */ 	ori	$t0,$t0,0x10
/*  f0a74f4:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0a74f8:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f0a74fc:	25890008 */ 	addiu	$t1,$t4,0x8
/*  f0a7500:	afa9014c */ 	sw	$t1,0x14c($sp)
/*  f0a7504:	ad880000 */ 	sw	$t0,0x0($t4)
/*  f0a7508:	0fc2d5ea */ 	jal	camGetLookAt
/*  f0a750c:	afac00d0 */ 	sw	$t4,0xd0($sp)
/*  f0a7510:	8fa300d0 */ 	lw	$v1,0xd0($sp)
/*  f0a7514:	244a0010 */ 	addiu	$t2,$v0,0x10
/*  f0a7518:	ac6a0004 */ 	sw	$t2,0x4($v1)
.L0f0a751c:
/*  f0a751c:	8fb8014c */ 	lw	$t8,0x14c($sp)
/*  f0a7520:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f0a7524:	3739000e */ 	ori	$t9,$t9,0xe
/*  f0a7528:	270b0008 */ 	addiu	$t3,$t8,0x8
/*  f0a752c:	afab014c */ 	sw	$t3,0x14c($sp)
/*  f0a7530:	3c014396 */ 	lui	$at,0x4396
/*  f0a7534:	44817000 */ 	mtc1	$at,$f14
/*  f0a7538:	44806000 */ 	mtc1	$zero,$f12
/*  f0a753c:	af190000 */ 	sw	$t9,0x0($t8)
/*  f0a7540:	0c005b73 */ 	jal	mtx00016dcc
/*  f0a7544:	afb800cc */ 	sw	$t8,0xcc($sp)
/*  f0a7548:	8fa300cc */ 	lw	$v1,0xcc($sp)
/*  f0a754c:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f0a7550:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0a7554:	0c006a47 */ 	jal	modelGetPart
/*  f0a7558:	8e04038c */ 	lw	$a0,0x38c($s0)
/*  f0a755c:	10400014 */ 	beqz	$v0,.L0f0a75b0
/*  f0a7560:	afa200e8 */ 	sw	$v0,0xe8($sp)
/*  f0a7564:	8e04038c */ 	lw	$a0,0x38c($s0)
/*  f0a7568:	0c006a47 */ 	jal	modelGetPart
/*  f0a756c:	24050011 */ 	addiu	$a1,$zero,0x11
/*  f0a7570:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0a7574:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f0a7578:	00402825 */ 	or	$a1,$v0,$zero
/*  f0a757c:	10400003 */ 	beqz	$v0,.L0f0a758c
/*  f0a7580:	3c06800a */ 	lui	$a2,%hi(var8009cf88)
/*  f0a7584:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0a7588:	ac4d0000 */ 	sw	$t5,0x0($v0)
.L0f0a758c:
/*  f0a758c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0a7590:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0a7594:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0a7598:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0a759c:	24c6cf88 */ 	addiu	$a2,$a2,%lo(var8009cf88)
/*  f0a75a0:	8fa7014c */ 	lw	$a3,0x14c($sp)
/*  f0a75a4:	0fc1fefe */ 	jal	tvscreenRender
/*  f0a75a8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0a75ac:	afa2014c */ 	sw	$v0,0x14c($sp)
.L0f0a75b0:
/*  f0a75b0:	8faf014c */ 	lw	$t7,0x14c($sp)
/*  f0a75b4:	8e250284 */ 	lw	$a1,0x284($s1)
/*  f0a75b8:	240c0004 */ 	addiu	$t4,$zero,0x4
/*  f0a75bc:	afac013c */ 	sw	$t4,0x13c($sp)
/*  f0a75c0:	afaf0118 */ 	sw	$t7,0x118($sp)
/*  f0a75c4:	8ca300d8 */ 	lw	$v1,0xd8($a1)
/*  f0a75c8:	3c078007 */ 	lui	$a3,%hi(g_InCutscene)
/*  f0a75cc:	14600013 */ 	bnez	$v1,.L0f0a761c
/*  f0a75d0:	00000000 */ 	nop
/*  f0a75d4:	8ce70764 */ 	lw	$a3,%lo(g_InCutscene)($a3)
/*  f0a75d8:	14e00010 */ 	bnez	$a3,.L0f0a761c
/*  f0a75dc:	00000000 */ 	nop
/*  f0a75e0:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a75e4:	50400007 */ 	beqzl	$v0,.L0f0a7604
/*  f0a75e8:	8caa1c54 */ 	lw	$t2,0x1c54($a1)
/*  f0a75ec:	1040000b */ 	beqz	$v0,.L0f0a761c
/*  f0a75f0:	00000000 */ 	nop
/*  f0a75f4:	80490037 */ 	lb	$t1,0x37($v0)
/*  f0a75f8:	15200008 */ 	bnez	$t1,.L0f0a761c
/*  f0a75fc:	00000000 */ 	nop
/*  f0a7600:	8caa1c54 */ 	lw	$t2,0x1c54($a1)
.L0f0a7604:
/*  f0a7604:	8ca800c4 */ 	lw	$t0,0xc4($a1)
/*  f0a7608:	0140c027 */ 	nor	$t8,$t2,$zero
/*  f0a760c:	01185824 */ 	and	$t3,$t0,$t8
/*  f0a7610:	31790001 */ 	andi	$t9,$t3,0x1
/*  f0a7614:	57200016 */ 	bnezl	$t9,.L0f0a7670
/*  f0a7618:	92681615 */ 	lbu	$t0,0x1615($s3)
.L0f0a761c:
/*  f0a761c:	14600078 */ 	bnez	$v1,.L0f0a7800
/*  f0a7620:	3c078007 */ 	lui	$a3,%hi(g_InCutscene)
/*  f0a7624:	8ce70764 */ 	lw	$a3,%lo(g_InCutscene)($a3)
/*  f0a7628:	54e00076 */ 	bnezl	$a3,.L0f0a7804
/*  f0a762c:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a7630:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a7634:	50400007 */ 	beqzl	$v0,.L0f0a7654
/*  f0a7638:	8caf1c54 */ 	lw	$t7,0x1c54($a1)
/*  f0a763c:	50400071 */ 	beqzl	$v0,.L0f0a7804
/*  f0a7640:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a7644:	804d0037 */ 	lb	$t5,0x37($v0)
/*  f0a7648:	55a0006e */ 	bnezl	$t5,.L0f0a7804
/*  f0a764c:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a7650:	8caf1c54 */ 	lw	$t7,0x1c54($a1)
.L0f0a7654:
/*  f0a7654:	8cae00c4 */ 	lw	$t6,0xc4($a1)
/*  f0a7658:	01e06027 */ 	nor	$t4,$t7,$zero
/*  f0a765c:	01cc4824 */ 	and	$t1,$t6,$t4
/*  f0a7660:	312a0008 */ 	andi	$t2,$t1,0x8
/*  f0a7664:	51400067 */ 	beqzl	$t2,.L0f0a7804
/*  f0a7668:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a766c:	92681615 */ 	lbu	$t0,0x1615($s3)
.L0f0a7670:
/*  f0a7670:	92781614 */ 	lbu	$t8,0x1614($s3)
/*  f0a7674:	26641614 */ 	addiu	$a0,$s3,0x1614
/*  f0a7678:	0118082a */ 	slt	$at,$t0,$t8
/*  f0a767c:	50200009 */ 	beqzl	$at,.L0f0a76a4
/*  f0a7680:	90820002 */ 	lbu	$v0,0x2($a0)
/*  f0a7684:	90830000 */ 	lbu	$v1,0x0($a0)
/*  f0a7688:	908b0002 */ 	lbu	$t3,0x2($a0)
/*  f0a768c:	0163082a */ 	slt	$at,$t3,$v1
/*  f0a7690:	50200004 */ 	beqzl	$at,.L0f0a76a4
/*  f0a7694:	90820002 */ 	lbu	$v0,0x2($a0)
/*  f0a7698:	1000000a */ 	b	.L0f0a76c4
/*  f0a769c:	00601025 */ 	or	$v0,$v1,$zero
/*  f0a76a0:	90820002 */ 	lbu	$v0,0x2($a0)
.L0f0a76a4:
/*  f0a76a4:	90860001 */ 	lbu	$a2,0x1($a0)
/*  f0a76a8:	00401825 */ 	or	$v1,$v0,$zero
/*  f0a76ac:	0046082a */ 	slt	$at,$v0,$a2
/*  f0a76b0:	10200003 */ 	beqz	$at,.L0f0a76c0
/*  f0a76b4:	00000000 */ 	nop
/*  f0a76b8:	10000001 */ 	b	.L0f0a76c0
/*  f0a76bc:	00c01825 */ 	or	$v1,$a2,$zero
.L0f0a76c0:
/*  f0a76c0:	00601025 */ 	or	$v0,$v1,$zero
.L0f0a76c4:
/*  f0a76c4:	90890003 */ 	lbu	$t1,0x3($a0)
/*  f0a76c8:	0002ce00 */ 	sll	$t9,$v0,0x18
/*  f0a76cc:	00026c00 */ 	sll	$t5,$v0,0x10
/*  f0a76d0:	032d7825 */ 	or	$t7,$t9,$t5
/*  f0a76d4:	00027200 */ 	sll	$t6,$v0,0x8
/*  f0a76d8:	01ee6025 */ 	or	$t4,$t7,$t6
/*  f0a76dc:	012c5021 */ 	addu	$t2,$t1,$t4
/*  f0a76e0:	afaa0140 */ 	sw	$t2,0x140($sp)
/*  f0a76e4:	8ca300d8 */ 	lw	$v1,0xd8($a1)
/*  f0a76e8:	14600021 */ 	bnez	$v1,.L0f0a7770
/*  f0a76ec:	00000000 */ 	nop
/*  f0a76f0:	14e0001f */ 	bnez	$a3,.L0f0a7770
/*  f0a76f4:	00000000 */ 	nop
/*  f0a76f8:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a76fc:	50400007 */ 	beqzl	$v0,.L0f0a771c
/*  f0a7700:	8cab1c54 */ 	lw	$t3,0x1c54($a1)
/*  f0a7704:	1040001a */ 	beqz	$v0,.L0f0a7770
/*  f0a7708:	00000000 */ 	nop
/*  f0a770c:	80480037 */ 	lb	$t0,0x37($v0)
/*  f0a7710:	15000017 */ 	bnez	$t0,.L0f0a7770
/*  f0a7714:	00000000 */ 	nop
/*  f0a7718:	8cab1c54 */ 	lw	$t3,0x1c54($a1)
.L0f0a771c:
/*  f0a771c:	8cb800c4 */ 	lw	$t8,0xc4($a1)
/*  f0a7720:	3c02800a */ 	lui	$v0,%hi(var8009caec+0x3)
/*  f0a7724:	0160c827 */ 	nor	$t9,$t3,$zero
/*  f0a7728:	03196824 */ 	and	$t5,$t8,$t9
/*  f0a772c:	31af0001 */ 	andi	$t7,$t5,0x1
/*  f0a7730:	11e0000f */ 	beqz	$t7,.L0f0a7770
/*  f0a7734:	00000000 */ 	nop
/*  f0a7738:	9042caef */ 	lbu	$v0,%lo(var8009caec+0x3)($v0)
/*  f0a773c:	3c06800a */ 	lui	$a2,%hi(var8009caf0)
/*  f0a7740:	90c6caf0 */ 	lbu	$a2,%lo(var8009caf0)($a2)
/*  f0a7744:	00027600 */ 	sll	$t6,$v0,0x18
/*  f0a7748:	00024c00 */ 	sll	$t1,$v0,0x10
/*  f0a774c:	01c96025 */ 	or	$t4,$t6,$t1
/*  f0a7750:	00025200 */ 	sll	$t2,$v0,0x8
/*  f0a7754:	018a4025 */ 	or	$t0,$t4,$t2
/*  f0a7758:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f0a775c:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*  f0a7760:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f0a7764:	00c8a821 */ 	addu	$s5,$a2,$t0
/*  f0a7768:	1000001f */ 	b	.L0f0a77e8
/*  f0a776c:	afa600bc */ 	sw	$a2,0xbc($sp)
.L0f0a7770:
/*  f0a7770:	5460001e */ 	bnezl	$v1,.L0f0a77ec
/*  f0a7774:	8fb900ec */ 	lw	$t9,0xec($sp)
/*  f0a7778:	54e0001c */ 	bnezl	$a3,.L0f0a77ec
/*  f0a777c:	8fb900ec */ 	lw	$t9,0xec($sp)
/*  f0a7780:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a7784:	50400007 */ 	beqzl	$v0,.L0f0a77a4
/*  f0a7788:	8cb91c54 */ 	lw	$t9,0x1c54($a1)
/*  f0a778c:	50400017 */ 	beqzl	$v0,.L0f0a77ec
/*  f0a7790:	8fb900ec */ 	lw	$t9,0xec($sp)
/*  f0a7794:	804b0037 */ 	lb	$t3,0x37($v0)
/*  f0a7798:	55600014 */ 	bnezl	$t3,.L0f0a77ec
/*  f0a779c:	8fb900ec */ 	lw	$t9,0xec($sp)
/*  f0a77a0:	8cb91c54 */ 	lw	$t9,0x1c54($a1)
.L0f0a77a4:
/*  f0a77a4:	8cb800c4 */ 	lw	$t8,0xc4($a1)
/*  f0a77a8:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f0a77ac:	03206827 */ 	nor	$t5,$t9,$zero
/*  f0a77b0:	030d7824 */ 	and	$t7,$t8,$t5
/*  f0a77b4:	31ee0008 */ 	andi	$t6,$t7,0x8
/*  f0a77b8:	11c0000b */ 	beqz	$t6,.L0f0a77e8
/*  f0a77bc:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f0a77c0:	00024e00 */ 	sll	$t1,$v0,0x18
/*  f0a77c4:	00006400 */ 	sll	$t4,$zero,0x10
/*  f0a77c8:	012c5025 */ 	or	$t2,$t1,$t4
/*  f0a77cc:	00004200 */ 	sll	$t0,$zero,0x8
/*  f0a77d0:	01485825 */ 	or	$t3,$t2,$t0
/*  f0a77d4:	00aba821 */ 	addu	$s5,$a1,$t3
/*  f0a77d8:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0a77dc:	afa000a4 */ 	sw	$zero,0xa4($sp)
/*  f0a77e0:	afa000a8 */ 	sw	$zero,0xa8($sp)
/*  f0a77e4:	afa500ac */ 	sw	$a1,0xac($sp)
.L0f0a77e8:
/*  f0a77e8:	8fb900ec */ 	lw	$t9,0xec($sp)
.L0f0a77ec:
/*  f0a77ec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a77f0:	5721003d */ 	bnel	$t9,$at,.L0f0a78e8
/*  f0a77f4:	8e6f00bc */ 	lw	$t7,0xbc($s3)
/*  f0a77f8:	1000003a */ 	b	.L0f0a78e4
/*  f0a77fc:	afb50140 */ 	sw	$s5,0x140($sp)
.L0f0a7800:
/*  f0a7800:	926d1614 */ 	lbu	$t5,0x1614($s3)
.L0f0a7804:
/*  f0a7804:	92781617 */ 	lbu	$t8,0x1617($s3)
/*  f0a7808:	92691615 */ 	lbu	$t1,0x1615($s3)
/*  f0a780c:	92681616 */ 	lbu	$t0,0x1616($s3)
/*  f0a7810:	000d7e00 */ 	sll	$t7,$t5,0x18
/*  f0a7814:	030f7025 */ 	or	$t6,$t8,$t7
/*  f0a7818:	00096400 */ 	sll	$t4,$t1,0x10
/*  f0a781c:	01cc5025 */ 	or	$t2,$t6,$t4
/*  f0a7820:	00085a00 */ 	sll	$t3,$t0,0x8
/*  f0a7824:	014bc825 */ 	or	$t9,$t2,$t3
/*  f0a7828:	afb90140 */ 	sw	$t9,0x140($sp)
/*  f0a782c:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f0a7830:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0a7834:	0320a825 */ 	or	$s5,$t9,$zero
/*  f0a7838:	15a1002a */ 	bne	$t5,$at,.L0f0a78e4
/*  f0a783c:	3c04ff00 */ 	lui	$a0,0xff00
/*  f0a7840:	3c014248 */ 	lui	$at,0x4248
/*  f0a7844:	44812000 */ 	mtc1	$at,$f4
/*  f0a7848:	c612023c */ 	lwc1	$f18,0x23c($s0)
/*  f0a784c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0a7850:	3c014f00 */ 	lui	$at,0x4f00
/*  f0a7854:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0a7858:	3484007f */ 	ori	$a0,$a0,0x7f
/*  f0a785c:	4458f800 */ 	cfc1	$t8,$31
/*  f0a7860:	44c6f800 */ 	ctc1	$a2,$31
/*  f0a7864:	00000000 */ 	nop
/*  f0a7868:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0a786c:	4446f800 */ 	cfc1	$a2,$31
/*  f0a7870:	00000000 */ 	nop
/*  f0a7874:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0a7878:	50c00013 */ 	beqzl	$a2,.L0f0a78c8
/*  f0a787c:	44064000 */ 	mfc1	$a2,$f8
/*  f0a7880:	44814000 */ 	mtc1	$at,$f8
/*  f0a7884:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0a7888:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0a788c:	44c6f800 */ 	ctc1	$a2,$31
/*  f0a7890:	00000000 */ 	nop
/*  f0a7894:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0a7898:	4446f800 */ 	cfc1	$a2,$31
/*  f0a789c:	00000000 */ 	nop
/*  f0a78a0:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0a78a4:	14c00005 */ 	bnez	$a2,.L0f0a78bc
/*  f0a78a8:	00000000 */ 	nop
/*  f0a78ac:	44064000 */ 	mfc1	$a2,$f8
/*  f0a78b0:	3c018000 */ 	lui	$at,0x8000
/*  f0a78b4:	10000007 */ 	b	.L0f0a78d4
/*  f0a78b8:	00c13025 */ 	or	$a2,$a2,$at
.L0f0a78bc:
/*  f0a78bc:	10000005 */ 	b	.L0f0a78d4
/*  f0a78c0:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0a78c4:	44064000 */ 	mfc1	$a2,$f8
.L0f0a78c8:
/*  f0a78c8:	00000000 */ 	nop
/*  f0a78cc:	04c0fffb */ 	bltz	$a2,.L0f0a78bc
/*  f0a78d0:	00000000 */ 	nop
.L0f0a78d4:
/*  f0a78d4:	44d8f800 */ 	ctc1	$t8,$31
/*  f0a78d8:	0fc01a40 */ 	jal	colourBlend
/*  f0a78dc:	03202825 */ 	or	$a1,$t9,$zero
/*  f0a78e0:	afa20140 */ 	sw	$v0,0x140($sp)
.L0f0a78e4:
/*  f0a78e4:	8e6f00bc */ 	lw	$t7,0xbc($s3)
.L0f0a78e8:
/*  f0a78e8:	0fc08af9 */ 	jal	chrGetCloakAlpha
/*  f0a78ec:	8de40004 */ 	lw	$a0,0x4($t7)
/*  f0a78f0:	284100ff */ 	slti	$at,$v0,0xff
/*  f0a78f4:	1020000f */ 	beqz	$at,.L0f0a7934
/*  f0a78f8:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0a78fc:	44825000 */ 	mtc1	$v0,$f10
/*  f0a7900:	3c017f1b */ 	lui	$at,%hi(var7f1aca90)
/*  f0a7904:	c432ca90 */ 	lwc1	$f18,%lo(var7f1aca90)($at)
/*  f0a7908:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0a790c:	8fa40140 */ 	lw	$a0,0x140($sp)
/*  f0a7910:	240e0005 */ 	addiu	$t6,$zero,0x5
/*  f0a7914:	afae013c */ 	sw	$t6,0x13c($sp)
/*  f0a7918:	afa40144 */ 	sw	$a0,0x144($sp)
/*  f0a791c:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0a7920:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0a7924:	44033000 */ 	mfc1	$v1,$f6
/*  f0a7928:	00000000 */ 	nop
/*  f0a792c:	24750041 */ 	addiu	$s5,$v1,0x41
/*  f0a7930:	afb50140 */ 	sw	$s5,0x140($sp)
.L0f0a7934:
/*  f0a7934:	0c0059d8 */ 	jal	mtx00016760
/*  f0a7938:	afac0110 */ 	sw	$t4,0x110($sp)
/*  f0a793c:	8e020218 */ 	lw	$v0,0x218($s0)
/*  f0a7940:	50400017 */ 	beqzl	$v0,.L0f0a79a0
/*  f0a7944:	8fa400ec */ 	lw	$a0,0xec($sp)
/*  f0a7948:	8c460018 */ 	lw	$a2,0x18($v0)
/*  f0a794c:	afa00094 */ 	sw	$zero,0x94($sp)
/*  f0a7950:	50c00013 */ 	beqzl	$a2,.L0f0a79a0
/*  f0a7954:	8fa400ec */ 	lw	$a0,0xec($sp)
/*  f0a7958:	8cc80008 */ 	lw	$t0,0x8($a2)
/*  f0a795c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0a7960:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0a7964:	1100000d */ 	beqz	$t0,.L0f0a799c
/*  f0a7968:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0a796c:	afaa0094 */ 	sw	$t2,0x94($sp)
/*  f0a7970:	0c0087bd */ 	jal	modelRender
/*  f0a7974:	afa60098 */ 	sw	$a2,0x98($sp)
/*  f0a7978:	8fa60098 */ 	lw	$a2,0x98($sp)
/*  f0a797c:	8ccb0008 */ 	lw	$t3,0x8($a2)
/*  f0a7980:	8cc4000c */ 	lw	$a0,0xc($a2)
/*  f0a7984:	0fc30cfc */ 	jal	func0f0c33f0
/*  f0a7988:	8565000e */ 	lh	$a1,0xe($t3)
/*  f0a798c:	8e0d021c */ 	lw	$t5,0x21c($s0)
/*  f0a7990:	51a00003 */ 	beqzl	$t5,.L0f0a79a0
/*  f0a7994:	8fa400ec */ 	lw	$a0,0xec($sp)
/*  f0a7998:	ae000218 */ 	sw	$zero,0x218($s0)
.L0f0a799c:
/*  f0a799c:	8fa400ec */ 	lw	$a0,0xec($sp)
.L0f0a79a0:
/*  f0a79a0:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a79a4:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f0a79a8:	1040000e */ 	beqz	$v0,.L0f0a79e4
/*  f0a79ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a79b0:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f0a79b4:	3c0fb600 */ 	lui	$t7,0xb600
/*  f0a79b8:	24093000 */ 	addiu	$t1,$zero,0x3000
/*  f0a79bc:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0a79c0:	afb90118 */ 	sw	$t9,0x118($sp)
/*  f0a79c4:	af090004 */ 	sw	$t1,0x4($t8)
/*  f0a79c8:	16800004 */ 	bnez	$s4,.L0f0a79dc
/*  f0a79cc:	af0f0000 */ 	sw	$t7,0x0($t8)
/*  f0a79d0:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f0a79d4:	10000003 */ 	b	.L0f0a79e4
/*  f0a79d8:	afae0148 */ 	sw	$t6,0x148($sp)
.L0f0a79dc:
/*  f0a79dc:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f0a79e0:	afac0148 */ 	sw	$t4,0x148($sp)
.L0f0a79e4:
/*  f0a79e4:	8e28006c */ 	lw	$t0,0x6c($s1)
/*  f0a79e8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a79ec:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a79f0:	11000003 */ 	beqz	$t0,.L0f0a7a00
/*  f0a79f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a79f8:	10000001 */ 	b	.L0f0a7a00
/*  f0a79fc:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0a7a00:
/*  f0a7a00:	8e2a0068 */ 	lw	$t2,0x68($s1)
/*  f0a7a04:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a7a08:	11400003 */ 	beqz	$t2,.L0f0a7a18
/*  f0a7a0c:	00000000 */ 	nop
/*  f0a7a10:	10000001 */ 	b	.L0f0a7a18
/*  f0a7a14:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0a7a18:
/*  f0a7a18:	8e2b0064 */ 	lw	$t3,0x64($s1)
/*  f0a7a1c:	11600003 */ 	beqz	$t3,.L0f0a7a2c
/*  f0a7a20:	00000000 */ 	nop
/*  f0a7a24:	10000001 */ 	b	.L0f0a7a2c
/*  f0a7a28:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a7a2c:
/*  f0a7a2c:	8e2d0070 */ 	lw	$t5,0x70($s1)
/*  f0a7a30:	11a00003 */ 	beqz	$t5,.L0f0a7a40
/*  f0a7a34:	00000000 */ 	nop
/*  f0a7a38:	10000001 */ 	b	.L0f0a7a40
/*  f0a7a3c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0a7a40:
/*  f0a7a40:	0062c021 */ 	addu	$t8,$v1,$v0
/*  f0a7a44:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f0a7a48:	03257821 */ 	addu	$t7,$t9,$a1
/*  f0a7a4c:	15e10036 */ 	bne	$t7,$at,.L0f0a7b28
/*  f0a7a50:	24050041 */ 	addiu	$a1,$zero,0x41
/*  f0a7a54:	0c006a47 */ 	jal	modelGetPart
/*  f0a7a58:	8e04038c */ 	lw	$a0,0x38c($s0)
/*  f0a7a5c:	50400033 */ 	beqzl	$v0,.L0f0a7b2c
/*  f0a7a60:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0a7a64:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0a7a68:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a7a6c:	84890010 */ 	lh	$t1,0x10($a0)
/*  f0a7a70:	5920002e */ 	blezl	$t1,.L0f0a7b2c
/*  f0a7a74:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0a7a78:	8e2a0034 */ 	lw	$t2,0x34($s1)
.L0f0a7a7c:
/*  f0a7a7c:	8c8e000c */ 	lw	$t6,0xc($a0)
/*  f0a7a80:	00056080 */ 	sll	$t4,$a1,0x2
/*  f0a7a84:	01520019 */ 	multu	$t2,$s2
/*  f0a7a88:	01856023 */ 	subu	$t4,$t4,$a1
/*  f0a7a8c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0a7a90:	01cc1021 */ 	addu	$v0,$t6,$t4
/*  f0a7a94:	8448000a */ 	lh	$t0,0xa($v0)
/*  f0a7a98:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f0a7a9c:	0325c823 */ 	subu	$t9,$t9,$a1
/*  f0a7aa0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0a7aa4:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0a7aa8:	00005812 */ 	mflo	$t3
/*  f0a7aac:	010b6823 */ 	subu	$t5,$t0,$t3
/*  f0a7ab0:	a44d0008 */ 	sh	$t5,0x8($v0)
/*  f0a7ab4:	8c98000c */ 	lw	$t8,0xc($a0)
/*  f0a7ab8:	03197821 */ 	addu	$t7,$t8,$t9
/*  f0a7abc:	85e9000a */ 	lh	$t1,0xa($t7)
/*  f0a7ac0:	2921a000 */ 	slti	$at,$t1,-24576
/*  f0a7ac4:	50200014 */ 	beqzl	$at,.L0f0a7b18
/*  f0a7ac8:	84980010 */ 	lh	$t8,0x10($a0)
/*  f0a7acc:	848e0010 */ 	lh	$t6,0x10($a0)
/*  f0a7ad0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a7ad4:	59c00010 */ 	blezl	$t6,.L0f0a7b18
/*  f0a7ad8:	84980010 */ 	lh	$t8,0x10($a0)
/*  f0a7adc:	8c8c000c */ 	lw	$t4,0xc($a0)
.L0f0a7ae0:
/*  f0a7ae0:	00035080 */ 	sll	$t2,$v1,0x2
/*  f0a7ae4:	01435023 */ 	subu	$t2,$t2,$v1
/*  f0a7ae8:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0a7aec:	018a1021 */ 	addu	$v0,$t4,$t2
/*  f0a7af0:	8448000a */ 	lh	$t0,0xa($v0)
/*  f0a7af4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0a7af8:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0a7afc:	250b2000 */ 	addiu	$t3,$t0,0x2000
/*  f0a7b00:	a44b0008 */ 	sh	$t3,0x8($v0)
/*  f0a7b04:	848d0010 */ 	lh	$t5,0x10($a0)
/*  f0a7b08:	006d082a */ 	slt	$at,$v1,$t5
/*  f0a7b0c:	5420fff4 */ 	bnezl	$at,.L0f0a7ae0
/*  f0a7b10:	8c8c000c */ 	lw	$t4,0xc($a0)
/*  f0a7b14:	84980010 */ 	lh	$t8,0x10($a0)
.L0f0a7b18:
/*  f0a7b18:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0a7b1c:	00b8082a */ 	slt	$at,$a1,$t8
/*  f0a7b20:	5420ffd6 */ 	bnezl	$at,.L0f0a7a7c
/*  f0a7b24:	8e2a0034 */ 	lw	$t2,0x34($s1)
.L0f0a7b28:
/*  f0a7b28:	27a4010c */ 	addiu	$a0,$sp,0x10c
.L0f0a7b2c:
/*  f0a7b2c:	0c0087bd */ 	jal	modelRender
/*  f0a7b30:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0a7b34:	8e791594 */ 	lw	$t9,0x1594($s3)
/*  f0a7b38:	3c0f8007 */ 	lui	$t7,%hi(var800702dc)
/*  f0a7b3c:	53200013 */ 	beqzl	$t9,.L0f0a7b8c
/*  f0a7b40:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f0a7b44:	8def02dc */ 	lw	$t7,%lo(var800702dc)($t7)
/*  f0a7b48:	8fa90140 */ 	lw	$t1,0x140($sp)
/*  f0a7b4c:	51e0000f */ 	beqzl	$t7,.L0f0a7b8c
/*  f0a7b50:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f0a7b54:	afa9007c */ 	sw	$t1,0x7c($sp)
/*  f0a7b58:	8e0e0390 */ 	lw	$t6,0x390($s0)
/*  f0a7b5c:	26050534 */ 	addiu	$a1,$s0,0x534
/*  f0a7b60:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0a7b64:	ae0e0540 */ 	sw	$t6,0x540($s0)
/*  f0a7b68:	0c007308 */ 	jal	model0001cc20
/*  f0a7b6c:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0a7b70:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0a7b74:	afb50140 */ 	sw	$s5,0x140($sp)
/*  f0a7b78:	0c0087bd */ 	jal	modelRender
/*  f0a7b7c:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0a7b80:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f0a7b84:	afa40140 */ 	sw	$a0,0x140($sp)
/*  f0a7b88:	8fac0118 */ 	lw	$t4,0x118($sp)
.L0f0a7b8c:
/*  f0a7b8c:	8fa400ec */ 	lw	$a0,0xec($sp)
/*  f0a7b90:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f0a7b94:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a7b98:	afac014c */ 	sw	$t4,0x14c($sp)
/*  f0a7b9c:	10400007 */ 	beqz	$v0,.L0f0a7bbc
/*  f0a7ba0:	8faa014c */ 	lw	$t2,0x14c($sp)
/*  f0a7ba4:	25480008 */ 	addiu	$t0,$t2,0x8
/*  f0a7ba8:	afa8014c */ 	sw	$t0,0x14c($sp)
/*  f0a7bac:	3c0bb600 */ 	lui	$t3,0xb600
/*  f0a7bb0:	240d3000 */ 	addiu	$t5,$zero,0x3000
/*  f0a7bb4:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0a7bb8:	ad4b0000 */ 	sw	$t3,0x0($t2)
.L0f0a7bbc:
/*  f0a7bbc:	8e18038c */ 	lw	$t8,0x38c($s0)
/*  f0a7bc0:	8e040390 */ 	lw	$a0,0x390($s0)
/*  f0a7bc4:	0fc30cfc */ 	jal	func0f0c33f0
/*  f0a7bc8:	8705000e */ 	lh	$a1,0xe($t8)
/*  f0a7bcc:	0c0059e1 */ 	jal	mtx00016784
/*  f0a7bd0:	00000000 */ 	nop
/*  f0a7bd4:	8fb9014c */ 	lw	$t9,0x14c($sp)
/*  f0a7bd8:	3c09bc00 */ 	lui	$t1,0xbc00
/*  f0a7bdc:	3529000e */ 	ori	$t1,$t1,0xe
/*  f0a7be0:	272f0008 */ 	addiu	$t7,$t9,0x8
/*  f0a7be4:	afaf014c */ 	sw	$t7,0x14c($sp)
/*  f0a7be8:	af290000 */ 	sw	$t1,0x0($t9)
/*  f0a7bec:	0c002adb */ 	jal	viGetPerspScale
/*  f0a7bf0:	afb90074 */ 	sw	$t9,0x74($sp)
/*  f0a7bf4:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f0a7bf8:	ac620004 */ 	sw	$v0,0x4($v1)
.L0f0a7bfc:
/*  f0a7bfc:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0a7c00:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a7c04:	1681fe04 */ 	bne	$s4,$at,.L0f0a7418
/*  f0a7c08:	261007a4 */ 	addiu	$s0,$s0,0x7a4
/*  f0a7c0c:	afb500e4 */ 	sw	$s5,0xe4($sp)
/*  f0a7c10:	0fc2baf8 */ 	jal	casingsRender
/*  f0a7c14:	27a4014c */ 	addiu	$a0,$sp,0x14c
/*  f0a7c18:	0fc5d8a6 */ 	jal	mblur0f176298
/*  f0a7c1c:	00000000 */ 	nop
/*  f0a7c20:	0fc5d8ab */ 	jal	mblur0f1762ac
/*  f0a7c24:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a7c28:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a7c2c:	0c002c74 */ 	jal	vi0000b1d0
/*  f0a7c30:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a7c34:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f0a7c38:	afae014c */ 	sw	$t6,0x14c($sp)
/*  f0a7c3c:	0c002f40 */ 	jal	viGetViewLeft
/*  f0a7c40:	00408825 */ 	or	$s1,$v0,$zero
/*  f0a7c44:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a7c48:	00106403 */ 	sra	$t4,$s0,0x10
/*  f0a7c4c:	0c002f44 */ 	jal	viGetViewTop
/*  f0a7c50:	01808025 */ 	or	$s0,$t4,$zero
/*  f0a7c54:	44824000 */ 	mtc1	$v0,$f8
/*  f0a7c58:	44902000 */ 	mtc1	$s0,$f4
/*  f0a7c5c:	3c014080 */ 	lui	$at,0x4080
/*  f0a7c60:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0a7c64:	44810000 */ 	mtc1	$at,$f0
/*  f0a7c68:	3c01ed00 */ 	lui	$at,0xed00
/*  f0a7c6c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a7c70:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0a7c74:	00000000 */ 	nop
/*  f0a7c78:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a7c7c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0a7c80:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0a7c84:	44089000 */ 	mfc1	$t0,$f18
/*  f0a7c88:	44195000 */ 	mfc1	$t9,$f10
/*  f0a7c8c:	310b0fff */ 	andi	$t3,$t0,0xfff
/*  f0a7c90:	01616825 */ 	or	$t5,$t3,$at
/*  f0a7c94:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f0a7c98:	000f4b00 */ 	sll	$t1,$t7,0xc
/*  f0a7c9c:	01a97025 */ 	or	$t6,$t5,$t1
/*  f0a7ca0:	0c002f22 */ 	jal	viGetViewWidth
/*  f0a7ca4:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f0a7ca8:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0a7cac:	00126403 */ 	sra	$t4,$s2,0x10
/*  f0a7cb0:	0c002f40 */ 	jal	viGetViewLeft
/*  f0a7cb4:	01809025 */ 	or	$s2,$t4,$zero
/*  f0a7cb8:	0002a400 */ 	sll	$s4,$v0,0x10
/*  f0a7cbc:	00145403 */ 	sra	$t2,$s4,0x10
/*  f0a7cc0:	0c002f44 */ 	jal	viGetViewTop
/*  f0a7cc4:	0140a025 */ 	or	$s4,$t2,$zero
/*  f0a7cc8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a7ccc:	00104403 */ 	sra	$t0,$s0,0x10
/*  f0a7cd0:	0c002f26 */ 	jal	viGetViewHeight
/*  f0a7cd4:	01008025 */ 	or	$s0,$t0,$zero
/*  f0a7cd8:	00505821 */ 	addu	$t3,$v0,$s0
/*  f0a7cdc:	448b8000 */ 	mtc1	$t3,$f16
/*  f0a7ce0:	02926821 */ 	addu	$t5,$s4,$s2
/*  f0a7ce4:	448d5000 */ 	mtc1	$t5,$f10
/*  f0a7ce8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0a7cec:	3c014080 */ 	lui	$at,0x4080
/*  f0a7cf0:	44812000 */ 	mtc1	$at,$f4
/*  f0a7cf4:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0a7cf8:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0a7cfc:	44819000 */ 	mtc1	$at,$f18
/*  f0a7d00:	00000000 */ 	nop
/*  f0a7d04:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0a7d08:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0a7d0c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0a7d10:	44194000 */ 	mfc1	$t9,$f8
/*  f0a7d14:	440e3000 */ 	mfc1	$t6,$f6
/*  f0a7d18:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f0a7d1c:	31cc0fff */ 	andi	$t4,$t6,0xfff
/*  f0a7d20:	000c5300 */ 	sll	$t2,$t4,0xc
/*  f0a7d24:	01ea4025 */ 	or	$t0,$t7,$t2
/*  f0a7d28:	ae280004 */ 	sw	$t0,0x4($s1)
/*  f0a7d2c:	8fb80150 */ 	lw	$t8,0x150($sp)
/*  f0a7d30:	8fab014c */ 	lw	$t3,0x14c($sp)
/*  f0a7d34:	af0b0000 */ 	sw	$t3,0x0($t8)
/*  f0a7d38:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0a7d3c:
/*  f0a7d3c:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f0a7d40:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f0a7d44:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f0a7d48:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f0a7d4c:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f0a7d50:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f0a7d54:	03e00008 */ 	jr	$ra
/*  f0a7d58:	27bd0150 */ 	addiu	$sp,$sp,0x150
);
#elif VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel bgunRender
.late_rodata
glabel var7f1aca8c
.word 0x3faaaaab
glabel var7f1aca90
.word 0x3f3ebebf
.text
/*  f0a7138:	27bdfeb0 */ 	addiu	$sp,$sp,-336
/*  f0a713c:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0a7140:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f0a7144:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f0a7148:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f0a714c:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0a7150:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0a7154:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0a7158:	afa40150 */ 	sw	$a0,0x150($sp)
/*  f0a715c:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f0a7160:	3c198007 */ 	lui	$t9,%hi(var8007029c)
/*  f0a7164:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f0a7168:	2739029c */ 	addiu	$t9,$t9,%lo(var8007029c)
/*  f0a716c:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f0a7170:	272a003c */ 	addiu	$t2,$t9,0x3c
/*  f0a7174:	27b8010c */ 	addiu	$t8,$sp,0x10c
/*  f0a7178:	afaf014c */ 	sw	$t7,0x14c($sp)
.L0f0a717c:
/*  f0a717c:	8f210000 */ 	lw	$at,0x0($t9)
/*  f0a7180:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f0a7184:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f0a7188:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f0a718c:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f0a7190:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f0a7194:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f0a7198:	172afff8 */ 	bne	$t9,$t2,.L0f0a717c
/*  f0a719c:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f0a71a0:	8f210000 */ 	lw	$at,0x0($t9)
/*  f0a71a4:	af010000 */ 	sw	$at,0x0($t8)
/*  f0a71a8:	8e330284 */ 	lw	$s3,0x284($s1)
/*  f0a71ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a71b0:	966b0010 */ 	lhu	$t3,0x10($s3)
/*  f0a71b4:	1561000d */ 	bne	$t3,$at,.L0f0a71ec
/*  f0a71b8:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a71bc:	24040f48 */ 	addiu	$a0,$zero,0xf48
/*  f0a71c0:	8e2c0284 */ 	lw	$t4,0x284($s1)
.L0f0a71c4:
/*  f0a71c4:	01821821 */ 	addu	$v1,$t4,$v0
/*  f0a71c8:	8c6d0854 */ 	lw	$t5,0x854($v1)
/*  f0a71cc:	244207a4 */ 	addiu	$v0,$v0,0x7a4
/*  f0a71d0:	11a00002 */ 	beqz	$t5,.L0f0a71dc
/*  f0a71d4:	00000000 */ 	nop
/*  f0a71d8:	ac600850 */ 	sw	$zero,0x850($v1)
.L0f0a71dc:
/*  f0a71dc:	5444fff9 */ 	bnel	$v0,$a0,.L0f0a71c4
/*  f0a71e0:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f0a71e4:	100002d5 */ 	b	.L0f0a7d3c
/*  f0a71e8:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0a71ec:
/*  f0a71ec:	0fc5d9ad */ 	jal	mblurRender
/*  f0a71f0:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a71f4:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a71f8:	0c002ca0 */ 	jal	vi0000b280
/*  f0a71fc:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a7200:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a7204:	0c002c74 */ 	jal	vi0000b1d0
/*  f0a7208:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a720c:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f0a7210:	afae014c */ 	sw	$t6,0x14c($sp)
/*  f0a7214:	0c002f40 */ 	jal	viGetViewLeft
/*  f0a7218:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0a721c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a7220:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0a7224:	0c002f44 */ 	jal	viGetViewTop
/*  f0a7228:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0a722c:	44822000 */ 	mtc1	$v0,$f4
/*  f0a7230:	44908000 */ 	mtc1	$s0,$f16
/*  f0a7234:	3c014080 */ 	lui	$at,0x4080
/*  f0a7238:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a723c:	44810000 */ 	mtc1	$at,$f0
/*  f0a7240:	3c01ed00 */ 	lui	$at,0xed00
/*  f0a7244:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0a7248:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a724c:	00000000 */ 	nop
/*  f0a7250:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0a7254:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0a7258:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0a725c:	44085000 */ 	mfc1	$t0,$f10
/*  f0a7260:	440b3000 */ 	mfc1	$t3,$f6
/*  f0a7264:	310a0fff */ 	andi	$t2,$t0,0xfff
/*  f0a7268:	0141c825 */ 	or	$t9,$t2,$at
/*  f0a726c:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f0a7270:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f0a7274:	032d7025 */ 	or	$t6,$t9,$t5
/*  f0a7278:	0c002f22 */ 	jal	viGetViewWidth
/*  f0a727c:	aeae0000 */ 	sw	$t6,0x0($s5)
/*  f0a7280:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0a7284:	00127c03 */ 	sra	$t7,$s2,0x10
/*  f0a7288:	0c002f40 */ 	jal	viGetViewLeft
/*  f0a728c:	01e09025 */ 	or	$s2,$t7,$zero
/*  f0a7290:	0002a400 */ 	sll	$s4,$v0,0x10
/*  f0a7294:	00144c03 */ 	sra	$t1,$s4,0x10
/*  f0a7298:	0c002f44 */ 	jal	viGetViewTop
/*  f0a729c:	0120a025 */ 	or	$s4,$t1,$zero
/*  f0a72a0:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a72a4:	00104403 */ 	sra	$t0,$s0,0x10
/*  f0a72a8:	0c002f26 */ 	jal	viGetViewHeight
/*  f0a72ac:	01008025 */ 	or	$s0,$t0,$zero
/*  f0a72b0:	00505021 */ 	addu	$t2,$v0,$s0
/*  f0a72b4:	448a4000 */ 	mtc1	$t2,$f8
/*  f0a72b8:	0292c821 */ 	addu	$t9,$s4,$s2
/*  f0a72bc:	44992000 */ 	mtc1	$t9,$f4
/*  f0a72c0:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0a72c4:	3c014080 */ 	lui	$at,0x4080
/*  f0a72c8:	44810000 */ 	mtc1	$at,$f0
/*  f0a72cc:	3c053fc0 */ 	lui	$a1,0x3fc0
/*  f0a72d0:	3c06447a */ 	lui	$a2,0x447a
/*  f0a72d4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a72d8:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0a72dc:	00000000 */ 	nop
/*  f0a72e0:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a72e4:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0a72e8:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0a72ec:	440b9000 */ 	mfc1	$t3,$f18
/*  f0a72f0:	440e5000 */ 	mfc1	$t6,$f10
/*  f0a72f4:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f0a72f8:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f0a72fc:	000f4b00 */ 	sll	$t1,$t7,0xc
/*  f0a7300:	01894025 */ 	or	$t0,$t4,$t1
/*  f0a7304:	aea80004 */ 	sw	$t0,0x4($s5)
/*  f0a7308:	0c002b29 */ 	jal	vi0000aca4
/*  f0a730c:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a7310:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f0a7314:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a7318:	91581bfc */ 	lbu	$t8,0x1bfc($t2)
/*  f0a731c:	53000016 */ 	beqzl	$t8,.L0f0a7378
/*  f0a7320:	8e2b006c */ 	lw	$t3,0x6c($s1)
/*  f0a7324:	0fc54bc7 */ 	jal	optionsGetScreenRatio
/*  f0a7328:	00000000 */ 	nop
/*  f0a732c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a7330:	14410008 */ 	bne	$v0,$at,.L0f0a7354
/*  f0a7334:	00000000 */ 	nop
/*  f0a7338:	0fc2f4d6 */ 	jal	player0f0bd358
/*  f0a733c:	00000000 */ 	nop
/*  f0a7340:	3c017f1b */ 	lui	$at,%hi(var7f1aca8c)
/*  f0a7344:	c430ca8c */ 	lwc1	$f16,%lo(var7f1aca8c)($at)
/*  f0a7348:	46100082 */ 	mul.s	$f2,$f0,$f16
/*  f0a734c:	10000005 */ 	b	.L0f0a7364
/*  f0a7350:	44061000 */ 	mfc1	$a2,$f2
.L0f0a7354:
/*  f0a7354:	0fc2f4d6 */ 	jal	player0f0bd358
/*  f0a7358:	00000000 */ 	nop
/*  f0a735c:	46000086 */ 	mov.s	$f2,$f0
/*  f0a7360:	44061000 */ 	mfc1	$a2,$f2
.L0f0a7364:
/*  f0a7364:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a7368:	0c002c3a */ 	jal	vi0000b0e8
/*  f0a736c:	3c054270 */ 	lui	$a1,0x4270
/*  f0a7370:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a7374:	8e2b006c */ 	lw	$t3,0x6c($s1)
.L0f0a7378:
/*  f0a7378:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a737c:	51600004 */ 	beqzl	$t3,.L0f0a7390
/*  f0a7380:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a7384:	10000002 */ 	b	.L0f0a7390
/*  f0a7388:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0a738c:	00002825 */ 	or	$a1,$zero,$zero
.L0f0a7390:
/*  f0a7390:	8e390068 */ 	lw	$t9,0x68($s1)
/*  f0a7394:	53200004 */ 	beqzl	$t9,.L0f0a73a8
/*  f0a7398:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a739c:	10000002 */ 	b	.L0f0a73a8
/*  f0a73a0:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a73a4:	00002025 */ 	or	$a0,$zero,$zero
.L0f0a73a8:
/*  f0a73a8:	8e2d0064 */ 	lw	$t5,0x64($s1)
/*  f0a73ac:	51a00004 */ 	beqzl	$t5,.L0f0a73c0
/*  f0a73b0:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a73b4:	10000002 */ 	b	.L0f0a73c0
/*  f0a73b8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0a73bc:	00001025 */ 	or	$v0,$zero,$zero
.L0f0a73c0:
/*  f0a73c0:	8e2e0070 */ 	lw	$t6,0x70($s1)
/*  f0a73c4:	51c00004 */ 	beqzl	$t6,.L0f0a73d8
/*  f0a73c8:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a73cc:	10000002 */ 	b	.L0f0a73d8
/*  f0a73d0:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0a73d4:	00001825 */ 	or	$v1,$zero,$zero
.L0f0a73d8:
/*  f0a73d8:	00627821 */ 	addu	$t7,$v1,$v0
/*  f0a73dc:	01e46021 */ 	addu	$t4,$t7,$a0
/*  f0a73e0:	01854821 */ 	addu	$t1,$t4,$a1
/*  f0a73e4:	15210008 */ 	bne	$t1,$at,.L0f0a7408
/*  f0a73e8:	3c088009 */ 	lui	$t0,%hi(g_Is4Mb)
/*  f0a73ec:	91080af0 */ 	lbu	$t0,%lo(g_Is4Mb)($t0)
/*  f0a73f0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a73f4:	51010005 */ 	beql	$t0,$at,.L0f0a740c
/*  f0a73f8:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0a73fc:	0fc2be93 */ 	jal	lasersightRenderBeam
/*  f0a7400:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a7404:	afa2014c */ 	sw	$v0,0x14c($sp)
.L0f0a7408:
/*  f0a7408:	0000a025 */ 	or	$s4,$zero,$zero
.L0f0a740c:
/*  f0a740c:	26700638 */ 	addiu	$s0,$s3,0x638
/*  f0a7410:	8fb500e4 */ 	lw	$s5,0xe4($sp)
/*  f0a7414:	24120019 */ 	addiu	$s2,$zero,0x19
.L0f0a7418:
/*  f0a7418:	0fc2867c */ 	jal	bgunGetWeaponNum2
/*  f0a741c:	02802025 */ 	or	$a0,$s4,$zero
/*  f0a7420:	afa200ec */ 	sw	$v0,0xec($sp)
/*  f0a7424:	820a0007 */ 	lb	$t2,0x7($s0)
/*  f0a7428:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a742c:	260501dc */ 	addiu	$a1,$s0,0x1dc
/*  f0a7430:	114001f2 */ 	beqz	$t2,.L0f0a7bfc
/*  f0a7434:	00003025 */ 	or	$a2,$zero,$zero
/*  f0a7438:	26180384 */ 	addiu	$t8,$s0,0x384
/*  f0a743c:	afb8003c */ 	sw	$t8,0x3c($sp)
/*  f0a7440:	0fc2b2e4 */ 	jal	beamRender
/*  f0a7444:	00003825 */ 	or	$a3,$zero,$zero
/*  f0a7448:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a744c:	92040000 */ 	lbu	$a0,0x0($s0)
/*  f0a7450:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a7454:	34058000 */ 	dli	$a1,0x8000
/*  f0a7458:	10400030 */ 	beqz	$v0,.L0f0a751c
/*  f0a745c:	8fab014c */ 	lw	$t3,0x14c($sp)
/*  f0a7460:	25790008 */ 	addiu	$t9,$t3,0x8
/*  f0a7464:	afb9014c */ 	sw	$t9,0x14c($sp)
/*  f0a7468:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f0a746c:	3c0e8000 */ 	lui	$t6,0x8000
/*  f0a7470:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f0a7474:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f0a7478:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f0a747c:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f0a7480:	8faf014c */ 	lw	$t7,0x14c($sp)
/*  f0a7484:	3c090386 */ 	lui	$t1,0x386
/*  f0a7488:	3c088007 */ 	lui	$t0,%hi(var80070098)
/*  f0a748c:	25ec0008 */ 	addiu	$t4,$t7,0x8
/*  f0a7490:	afac014c */ 	sw	$t4,0x14c($sp)
/*  f0a7494:	25080098 */ 	addiu	$t0,$t0,%lo(var80070098)
/*  f0a7498:	35290010 */ 	ori	$t1,$t1,0x10
/*  f0a749c:	ade90000 */ 	sw	$t1,0x0($t7)
/*  f0a74a0:	ade80004 */ 	sw	$t0,0x4($t7)
/*  f0a74a4:	8faa014c */ 	lw	$t2,0x14c($sp)
/*  f0a74a8:	3c0b0388 */ 	lui	$t3,0x388
/*  f0a74ac:	3c198007 */ 	lui	$t9,%hi(var80070090)
/*  f0a74b0:	25580008 */ 	addiu	$t8,$t2,0x8
/*  f0a74b4:	afb8014c */ 	sw	$t8,0x14c($sp)
/*  f0a74b8:	27390090 */ 	addiu	$t9,$t9,%lo(var80070090)
/*  f0a74bc:	356b0010 */ 	ori	$t3,$t3,0x10
/*  f0a74c0:	ad4b0000 */ 	sw	$t3,0x0($t2)
/*  f0a74c4:	ad590004 */ 	sw	$t9,0x4($t2)
/*  f0a74c8:	8fad014c */ 	lw	$t5,0x14c($sp)
/*  f0a74cc:	3c0f0384 */ 	lui	$t7,0x384
/*  f0a74d0:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f0a74d4:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0a74d8:	afae014c */ 	sw	$t6,0x14c($sp)
/*  f0a74dc:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0a74e0:	0fc2d5ea */ 	jal	camGetLookAt
/*  f0a74e4:	afad00d4 */ 	sw	$t5,0xd4($sp)
/*  f0a74e8:	8fa500d4 */ 	lw	$a1,0xd4($sp)
/*  f0a74ec:	3c080382 */ 	lui	$t0,0x382
/*  f0a74f0:	35080010 */ 	ori	$t0,$t0,0x10
/*  f0a74f4:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0a74f8:	8fac014c */ 	lw	$t4,0x14c($sp)
/*  f0a74fc:	25890008 */ 	addiu	$t1,$t4,0x8
/*  f0a7500:	afa9014c */ 	sw	$t1,0x14c($sp)
/*  f0a7504:	ad880000 */ 	sw	$t0,0x0($t4)
/*  f0a7508:	0fc2d5ea */ 	jal	camGetLookAt
/*  f0a750c:	afac00d0 */ 	sw	$t4,0xd0($sp)
/*  f0a7510:	8fa300d0 */ 	lw	$v1,0xd0($sp)
/*  f0a7514:	244a0010 */ 	addiu	$t2,$v0,0x10
/*  f0a7518:	ac6a0004 */ 	sw	$t2,0x4($v1)
.L0f0a751c:
/*  f0a751c:	8fb8014c */ 	lw	$t8,0x14c($sp)
/*  f0a7520:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f0a7524:	3739000e */ 	ori	$t9,$t9,0xe
/*  f0a7528:	270b0008 */ 	addiu	$t3,$t8,0x8
/*  f0a752c:	afab014c */ 	sw	$t3,0x14c($sp)
/*  f0a7530:	3c014396 */ 	lui	$at,0x4396
/*  f0a7534:	44817000 */ 	mtc1	$at,$f14
/*  f0a7538:	44806000 */ 	mtc1	$zero,$f12
/*  f0a753c:	af190000 */ 	sw	$t9,0x0($t8)
/*  f0a7540:	0c005b73 */ 	jal	mtx00016dcc
/*  f0a7544:	afb800cc */ 	sw	$t8,0xcc($sp)
/*  f0a7548:	8fa300cc */ 	lw	$v1,0xcc($sp)
/*  f0a754c:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f0a7550:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0a7554:	0c006a47 */ 	jal	modelGetPart
/*  f0a7558:	8e04038c */ 	lw	$a0,0x38c($s0)
/*  f0a755c:	10400014 */ 	beqz	$v0,.L0f0a75b0
/*  f0a7560:	afa200e8 */ 	sw	$v0,0xe8($sp)
/*  f0a7564:	8e04038c */ 	lw	$a0,0x38c($s0)
/*  f0a7568:	0c006a47 */ 	jal	modelGetPart
/*  f0a756c:	24050011 */ 	addiu	$a1,$zero,0x11
/*  f0a7570:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0a7574:	0c006a87 */ 	jal	modelGetNodeRwData
/*  f0a7578:	00402825 */ 	or	$a1,$v0,$zero
/*  f0a757c:	10400003 */ 	beqz	$v0,.L0f0a758c
/*  f0a7580:	3c06800a */ 	lui	$a2,%hi(var8009cf88)
/*  f0a7584:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0a7588:	ac4d0000 */ 	sw	$t5,0x0($v0)
.L0f0a758c:
/*  f0a758c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0a7590:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0a7594:	8fa4003c */ 	lw	$a0,0x3c($sp)
/*  f0a7598:	8fa500e8 */ 	lw	$a1,0xe8($sp)
/*  f0a759c:	24c6cf88 */ 	addiu	$a2,$a2,%lo(var8009cf88)
/*  f0a75a0:	8fa7014c */ 	lw	$a3,0x14c($sp)
/*  f0a75a4:	0fc1fefe */ 	jal	tvscreenRender
/*  f0a75a8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0a75ac:	afa2014c */ 	sw	$v0,0x14c($sp)
.L0f0a75b0:
/*  f0a75b0:	8faf014c */ 	lw	$t7,0x14c($sp)
/*  f0a75b4:	8e250284 */ 	lw	$a1,0x284($s1)
/*  f0a75b8:	240c0004 */ 	addiu	$t4,$zero,0x4
/*  f0a75bc:	afac013c */ 	sw	$t4,0x13c($sp)
/*  f0a75c0:	afaf0118 */ 	sw	$t7,0x118($sp)
/*  f0a75c4:	8ca300d8 */ 	lw	$v1,0xd8($a1)
/*  f0a75c8:	3c078007 */ 	lui	$a3,%hi(g_InCutscene)
/*  f0a75cc:	14600013 */ 	bnez	$v1,.L0f0a761c
/*  f0a75d0:	00000000 */ 	nop
/*  f0a75d4:	8ce70764 */ 	lw	$a3,%lo(g_InCutscene)($a3)
/*  f0a75d8:	14e00010 */ 	bnez	$a3,.L0f0a761c
/*  f0a75dc:	00000000 */ 	nop
/*  f0a75e0:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a75e4:	50400007 */ 	beqzl	$v0,.L0f0a7604
/*  f0a75e8:	8caa1c54 */ 	lw	$t2,0x1c54($a1)
/*  f0a75ec:	1040000b */ 	beqz	$v0,.L0f0a761c
/*  f0a75f0:	00000000 */ 	nop
/*  f0a75f4:	80490037 */ 	lb	$t1,0x37($v0)
/*  f0a75f8:	15200008 */ 	bnez	$t1,.L0f0a761c
/*  f0a75fc:	00000000 */ 	nop
/*  f0a7600:	8caa1c54 */ 	lw	$t2,0x1c54($a1)
.L0f0a7604:
/*  f0a7604:	8ca800c4 */ 	lw	$t0,0xc4($a1)
/*  f0a7608:	0140c027 */ 	nor	$t8,$t2,$zero
/*  f0a760c:	01185824 */ 	and	$t3,$t0,$t8
/*  f0a7610:	31790001 */ 	andi	$t9,$t3,0x1
/*  f0a7614:	57200016 */ 	bnezl	$t9,.L0f0a7670
/*  f0a7618:	92681615 */ 	lbu	$t0,0x1615($s3)
.L0f0a761c:
/*  f0a761c:	14600078 */ 	bnez	$v1,.L0f0a7800
/*  f0a7620:	3c078007 */ 	lui	$a3,%hi(g_InCutscene)
/*  f0a7624:	8ce70764 */ 	lw	$a3,%lo(g_InCutscene)($a3)
/*  f0a7628:	54e00076 */ 	bnezl	$a3,.L0f0a7804
/*  f0a762c:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a7630:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a7634:	50400007 */ 	beqzl	$v0,.L0f0a7654
/*  f0a7638:	8caf1c54 */ 	lw	$t7,0x1c54($a1)
/*  f0a763c:	50400071 */ 	beqzl	$v0,.L0f0a7804
/*  f0a7640:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a7644:	804d0037 */ 	lb	$t5,0x37($v0)
/*  f0a7648:	55a0006e */ 	bnezl	$t5,.L0f0a7804
/*  f0a764c:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a7650:	8caf1c54 */ 	lw	$t7,0x1c54($a1)
.L0f0a7654:
/*  f0a7654:	8cae00c4 */ 	lw	$t6,0xc4($a1)
/*  f0a7658:	01e06027 */ 	nor	$t4,$t7,$zero
/*  f0a765c:	01cc4824 */ 	and	$t1,$t6,$t4
/*  f0a7660:	312a0008 */ 	andi	$t2,$t1,0x8
/*  f0a7664:	51400067 */ 	beqzl	$t2,.L0f0a7804
/*  f0a7668:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a766c:	92681615 */ 	lbu	$t0,0x1615($s3)
.L0f0a7670:
/*  f0a7670:	92781614 */ 	lbu	$t8,0x1614($s3)
/*  f0a7674:	26641614 */ 	addiu	$a0,$s3,0x1614
/*  f0a7678:	0118082a */ 	slt	$at,$t0,$t8
/*  f0a767c:	50200009 */ 	beqzl	$at,.L0f0a76a4
/*  f0a7680:	90820002 */ 	lbu	$v0,0x2($a0)
/*  f0a7684:	90830000 */ 	lbu	$v1,0x0($a0)
/*  f0a7688:	908b0002 */ 	lbu	$t3,0x2($a0)
/*  f0a768c:	0163082a */ 	slt	$at,$t3,$v1
/*  f0a7690:	50200004 */ 	beqzl	$at,.L0f0a76a4
/*  f0a7694:	90820002 */ 	lbu	$v0,0x2($a0)
/*  f0a7698:	1000000a */ 	b	.L0f0a76c4
/*  f0a769c:	00601025 */ 	or	$v0,$v1,$zero
/*  f0a76a0:	90820002 */ 	lbu	$v0,0x2($a0)
.L0f0a76a4:
/*  f0a76a4:	90860001 */ 	lbu	$a2,0x1($a0)
/*  f0a76a8:	00401825 */ 	or	$v1,$v0,$zero
/*  f0a76ac:	0046082a */ 	slt	$at,$v0,$a2
/*  f0a76b0:	10200003 */ 	beqz	$at,.L0f0a76c0
/*  f0a76b4:	00000000 */ 	nop
/*  f0a76b8:	10000001 */ 	b	.L0f0a76c0
/*  f0a76bc:	00c01825 */ 	or	$v1,$a2,$zero
.L0f0a76c0:
/*  f0a76c0:	00601025 */ 	or	$v0,$v1,$zero
.L0f0a76c4:
/*  f0a76c4:	90890003 */ 	lbu	$t1,0x3($a0)
/*  f0a76c8:	0002ce00 */ 	sll	$t9,$v0,0x18
/*  f0a76cc:	00026c00 */ 	sll	$t5,$v0,0x10
/*  f0a76d0:	032d7825 */ 	or	$t7,$t9,$t5
/*  f0a76d4:	00027200 */ 	sll	$t6,$v0,0x8
/*  f0a76d8:	01ee6025 */ 	or	$t4,$t7,$t6
/*  f0a76dc:	012c5021 */ 	addu	$t2,$t1,$t4
/*  f0a76e0:	afaa0140 */ 	sw	$t2,0x140($sp)
/*  f0a76e4:	8ca300d8 */ 	lw	$v1,0xd8($a1)
/*  f0a76e8:	14600021 */ 	bnez	$v1,.L0f0a7770
/*  f0a76ec:	00000000 */ 	nop
/*  f0a76f0:	14e0001f */ 	bnez	$a3,.L0f0a7770
/*  f0a76f4:	00000000 */ 	nop
/*  f0a76f8:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a76fc:	50400007 */ 	beqzl	$v0,.L0f0a771c
/*  f0a7700:	8cab1c54 */ 	lw	$t3,0x1c54($a1)
/*  f0a7704:	1040001a */ 	beqz	$v0,.L0f0a7770
/*  f0a7708:	00000000 */ 	nop
/*  f0a770c:	80480037 */ 	lb	$t0,0x37($v0)
/*  f0a7710:	15000017 */ 	bnez	$t0,.L0f0a7770
/*  f0a7714:	00000000 */ 	nop
/*  f0a7718:	8cab1c54 */ 	lw	$t3,0x1c54($a1)
.L0f0a771c:
/*  f0a771c:	8cb800c4 */ 	lw	$t8,0xc4($a1)
/*  f0a7720:	3c02800a */ 	lui	$v0,%hi(var8009caec+0x3)
/*  f0a7724:	0160c827 */ 	nor	$t9,$t3,$zero
/*  f0a7728:	03196824 */ 	and	$t5,$t8,$t9
/*  f0a772c:	31af0001 */ 	andi	$t7,$t5,0x1
/*  f0a7730:	11e0000f */ 	beqz	$t7,.L0f0a7770
/*  f0a7734:	00000000 */ 	nop
/*  f0a7738:	9042caef */ 	lbu	$v0,%lo(var8009caec+0x3)($v0)
/*  f0a773c:	3c06800a */ 	lui	$a2,%hi(var8009caf0)
/*  f0a7740:	90c6caf0 */ 	lbu	$a2,%lo(var8009caf0)($a2)
/*  f0a7744:	00027600 */ 	sll	$t6,$v0,0x18
/*  f0a7748:	00024c00 */ 	sll	$t1,$v0,0x10
/*  f0a774c:	01c96025 */ 	or	$t4,$t6,$t1
/*  f0a7750:	00025200 */ 	sll	$t2,$v0,0x8
/*  f0a7754:	018a4025 */ 	or	$t0,$t4,$t2
/*  f0a7758:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f0a775c:	afa200b4 */ 	sw	$v0,0xb4($sp)
/*  f0a7760:	afa200b8 */ 	sw	$v0,0xb8($sp)
/*  f0a7764:	00c8a821 */ 	addu	$s5,$a2,$t0
/*  f0a7768:	1000001f */ 	b	.L0f0a77e8
/*  f0a776c:	afa600bc */ 	sw	$a2,0xbc($sp)
.L0f0a7770:
/*  f0a7770:	5460001e */ 	bnezl	$v1,.L0f0a77ec
/*  f0a7774:	8fb900ec */ 	lw	$t9,0xec($sp)
/*  f0a7778:	54e0001c */ 	bnezl	$a3,.L0f0a77ec
/*  f0a777c:	8fb900ec */ 	lw	$t9,0xec($sp)
/*  f0a7780:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a7784:	50400007 */ 	beqzl	$v0,.L0f0a77a4
/*  f0a7788:	8cb91c54 */ 	lw	$t9,0x1c54($a1)
/*  f0a778c:	50400017 */ 	beqzl	$v0,.L0f0a77ec
/*  f0a7790:	8fb900ec */ 	lw	$t9,0xec($sp)
/*  f0a7794:	804b0037 */ 	lb	$t3,0x37($v0)
/*  f0a7798:	55600014 */ 	bnezl	$t3,.L0f0a77ec
/*  f0a779c:	8fb900ec */ 	lw	$t9,0xec($sp)
/*  f0a77a0:	8cb91c54 */ 	lw	$t9,0x1c54($a1)
.L0f0a77a4:
/*  f0a77a4:	8cb800c4 */ 	lw	$t8,0xc4($a1)
/*  f0a77a8:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f0a77ac:	03206827 */ 	nor	$t5,$t9,$zero
/*  f0a77b0:	030d7824 */ 	and	$t7,$t8,$t5
/*  f0a77b4:	31ee0008 */ 	andi	$t6,$t7,0x8
/*  f0a77b8:	11c0000b */ 	beqz	$t6,.L0f0a77e8
/*  f0a77bc:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f0a77c0:	00024e00 */ 	sll	$t1,$v0,0x18
/*  f0a77c4:	00006400 */ 	sll	$t4,$zero,0x10
/*  f0a77c8:	012c5025 */ 	or	$t2,$t1,$t4
/*  f0a77cc:	00004200 */ 	sll	$t0,$zero,0x8
/*  f0a77d0:	01485825 */ 	or	$t3,$t2,$t0
/*  f0a77d4:	00aba821 */ 	addu	$s5,$a1,$t3
/*  f0a77d8:	afa200a0 */ 	sw	$v0,0xa0($sp)
/*  f0a77dc:	afa000a4 */ 	sw	$zero,0xa4($sp)
/*  f0a77e0:	afa000a8 */ 	sw	$zero,0xa8($sp)
/*  f0a77e4:	afa500ac */ 	sw	$a1,0xac($sp)
.L0f0a77e8:
/*  f0a77e8:	8fb900ec */ 	lw	$t9,0xec($sp)
.L0f0a77ec:
/*  f0a77ec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a77f0:	5721003d */ 	bnel	$t9,$at,.L0f0a78e8
/*  f0a77f4:	8e6f00bc */ 	lw	$t7,0xbc($s3)
/*  f0a77f8:	1000003a */ 	b	.L0f0a78e4
/*  f0a77fc:	afb50140 */ 	sw	$s5,0x140($sp)
.L0f0a7800:
/*  f0a7800:	926d1614 */ 	lbu	$t5,0x1614($s3)
.L0f0a7804:
/*  f0a7804:	92781617 */ 	lbu	$t8,0x1617($s3)
/*  f0a7808:	92691615 */ 	lbu	$t1,0x1615($s3)
/*  f0a780c:	92681616 */ 	lbu	$t0,0x1616($s3)
/*  f0a7810:	000d7e00 */ 	sll	$t7,$t5,0x18
/*  f0a7814:	030f7025 */ 	or	$t6,$t8,$t7
/*  f0a7818:	00096400 */ 	sll	$t4,$t1,0x10
/*  f0a781c:	01cc5025 */ 	or	$t2,$t6,$t4
/*  f0a7820:	00085a00 */ 	sll	$t3,$t0,0x8
/*  f0a7824:	014bc825 */ 	or	$t9,$t2,$t3
/*  f0a7828:	afb90140 */ 	sw	$t9,0x140($sp)
/*  f0a782c:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f0a7830:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0a7834:	0320a825 */ 	or	$s5,$t9,$zero
/*  f0a7838:	15a1002a */ 	bne	$t5,$at,.L0f0a78e4
/*  f0a783c:	3c04ff00 */ 	lui	$a0,0xff00
/*  f0a7840:	3c014248 */ 	lui	$at,0x4248
/*  f0a7844:	44812000 */ 	mtc1	$at,$f4
/*  f0a7848:	c612023c */ 	lwc1	$f18,0x23c($s0)
/*  f0a784c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0a7850:	3c014f00 */ 	lui	$at,0x4f00
/*  f0a7854:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0a7858:	3484007f */ 	ori	$a0,$a0,0x7f
/*  f0a785c:	4458f800 */ 	cfc1	$t8,$31
/*  f0a7860:	44c6f800 */ 	ctc1	$a2,$31
/*  f0a7864:	00000000 */ 	nop
/*  f0a7868:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0a786c:	4446f800 */ 	cfc1	$a2,$31
/*  f0a7870:	00000000 */ 	nop
/*  f0a7874:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0a7878:	50c00013 */ 	beqzl	$a2,.L0f0a78c8
/*  f0a787c:	44064000 */ 	mfc1	$a2,$f8
/*  f0a7880:	44814000 */ 	mtc1	$at,$f8
/*  f0a7884:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0a7888:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0a788c:	44c6f800 */ 	ctc1	$a2,$31
/*  f0a7890:	00000000 */ 	nop
/*  f0a7894:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0a7898:	4446f800 */ 	cfc1	$a2,$31
/*  f0a789c:	00000000 */ 	nop
/*  f0a78a0:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0a78a4:	14c00005 */ 	bnez	$a2,.L0f0a78bc
/*  f0a78a8:	00000000 */ 	nop
/*  f0a78ac:	44064000 */ 	mfc1	$a2,$f8
/*  f0a78b0:	3c018000 */ 	lui	$at,0x8000
/*  f0a78b4:	10000007 */ 	b	.L0f0a78d4
/*  f0a78b8:	00c13025 */ 	or	$a2,$a2,$at
.L0f0a78bc:
/*  f0a78bc:	10000005 */ 	b	.L0f0a78d4
/*  f0a78c0:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0a78c4:	44064000 */ 	mfc1	$a2,$f8
.L0f0a78c8:
/*  f0a78c8:	00000000 */ 	nop
/*  f0a78cc:	04c0fffb */ 	bltz	$a2,.L0f0a78bc
/*  f0a78d0:	00000000 */ 	nop
.L0f0a78d4:
/*  f0a78d4:	44d8f800 */ 	ctc1	$t8,$31
/*  f0a78d8:	0fc01a40 */ 	jal	colourBlend
/*  f0a78dc:	03202825 */ 	or	$a1,$t9,$zero
/*  f0a78e0:	afa20140 */ 	sw	$v0,0x140($sp)
.L0f0a78e4:
/*  f0a78e4:	8e6f00bc */ 	lw	$t7,0xbc($s3)
.L0f0a78e8:
/*  f0a78e8:	0fc08af9 */ 	jal	chrGetCloakAlpha
/*  f0a78ec:	8de40004 */ 	lw	$a0,0x4($t7)
/*  f0a78f0:	284100ff */ 	slti	$at,$v0,0xff
/*  f0a78f4:	1020000f */ 	beqz	$at,.L0f0a7934
/*  f0a78f8:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0a78fc:	44825000 */ 	mtc1	$v0,$f10
/*  f0a7900:	3c017f1b */ 	lui	$at,%hi(var7f1aca90)
/*  f0a7904:	c432ca90 */ 	lwc1	$f18,%lo(var7f1aca90)($at)
/*  f0a7908:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0a790c:	8fa40140 */ 	lw	$a0,0x140($sp)
/*  f0a7910:	240e0005 */ 	addiu	$t6,$zero,0x5
/*  f0a7914:	afae013c */ 	sw	$t6,0x13c($sp)
/*  f0a7918:	afa40144 */ 	sw	$a0,0x144($sp)
/*  f0a791c:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0a7920:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0a7924:	44033000 */ 	mfc1	$v1,$f6
/*  f0a7928:	00000000 */ 	nop
/*  f0a792c:	24750041 */ 	addiu	$s5,$v1,0x41
/*  f0a7930:	afb50140 */ 	sw	$s5,0x140($sp)
.L0f0a7934:
/*  f0a7934:	0c0059d8 */ 	jal	mtx00016760
/*  f0a7938:	afac0110 */ 	sw	$t4,0x110($sp)
/*  f0a793c:	8e020218 */ 	lw	$v0,0x218($s0)
/*  f0a7940:	50400017 */ 	beqzl	$v0,.L0f0a79a0
/*  f0a7944:	8fa400ec */ 	lw	$a0,0xec($sp)
/*  f0a7948:	8c460018 */ 	lw	$a2,0x18($v0)
/*  f0a794c:	afa00094 */ 	sw	$zero,0x94($sp)
/*  f0a7950:	50c00013 */ 	beqzl	$a2,.L0f0a79a0
/*  f0a7954:	8fa400ec */ 	lw	$a0,0xec($sp)
/*  f0a7958:	8cc80008 */ 	lw	$t0,0x8($a2)
/*  f0a795c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0a7960:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0a7964:	1100000d */ 	beqz	$t0,.L0f0a799c
/*  f0a7968:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0a796c:	afaa0094 */ 	sw	$t2,0x94($sp)
/*  f0a7970:	0c0087bd */ 	jal	modelRender
/*  f0a7974:	afa60098 */ 	sw	$a2,0x98($sp)
/*  f0a7978:	8fa60098 */ 	lw	$a2,0x98($sp)
/*  f0a797c:	8ccb0008 */ 	lw	$t3,0x8($a2)
/*  f0a7980:	8cc4000c */ 	lw	$a0,0xc($a2)
/*  f0a7984:	0fc30cfc */ 	jal	func0f0c33f0
/*  f0a7988:	8565000e */ 	lh	$a1,0xe($t3)
/*  f0a798c:	8e0d021c */ 	lw	$t5,0x21c($s0)
/*  f0a7990:	51a00003 */ 	beqzl	$t5,.L0f0a79a0
/*  f0a7994:	8fa400ec */ 	lw	$a0,0xec($sp)
/*  f0a7998:	ae000218 */ 	sw	$zero,0x218($s0)
.L0f0a799c:
/*  f0a799c:	8fa400ec */ 	lw	$a0,0xec($sp)
.L0f0a79a0:
/*  f0a79a0:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a79a4:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f0a79a8:	1040000e */ 	beqz	$v0,.L0f0a79e4
/*  f0a79ac:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a79b0:	8fb80118 */ 	lw	$t8,0x118($sp)
/*  f0a79b4:	3c0fb600 */ 	lui	$t7,0xb600
/*  f0a79b8:	24093000 */ 	addiu	$t1,$zero,0x3000
/*  f0a79bc:	27190008 */ 	addiu	$t9,$t8,0x8
/*  f0a79c0:	afb90118 */ 	sw	$t9,0x118($sp)
/*  f0a79c4:	af090004 */ 	sw	$t1,0x4($t8)
/*  f0a79c8:	16800004 */ 	bnez	$s4,.L0f0a79dc
/*  f0a79cc:	af0f0000 */ 	sw	$t7,0x0($t8)
/*  f0a79d0:	240e0003 */ 	addiu	$t6,$zero,0x3
/*  f0a79d4:	10000003 */ 	b	.L0f0a79e4
/*  f0a79d8:	afae0148 */ 	sw	$t6,0x148($sp)
.L0f0a79dc:
/*  f0a79dc:	240c0002 */ 	addiu	$t4,$zero,0x2
/*  f0a79e0:	afac0148 */ 	sw	$t4,0x148($sp)
.L0f0a79e4:
/*  f0a79e4:	8e28006c */ 	lw	$t0,0x6c($s1)
/*  f0a79e8:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a79ec:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a79f0:	11000003 */ 	beqz	$t0,.L0f0a7a00
/*  f0a79f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a79f8:	10000001 */ 	b	.L0f0a7a00
/*  f0a79fc:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f0a7a00:
/*  f0a7a00:	8e2a0068 */ 	lw	$t2,0x68($s1)
/*  f0a7a04:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a7a08:	11400003 */ 	beqz	$t2,.L0f0a7a18
/*  f0a7a0c:	00000000 */ 	nop
/*  f0a7a10:	10000001 */ 	b	.L0f0a7a18
/*  f0a7a14:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f0a7a18:
/*  f0a7a18:	8e2b0064 */ 	lw	$t3,0x64($s1)
/*  f0a7a1c:	11600003 */ 	beqz	$t3,.L0f0a7a2c
/*  f0a7a20:	00000000 */ 	nop
/*  f0a7a24:	10000001 */ 	b	.L0f0a7a2c
/*  f0a7a28:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f0a7a2c:
/*  f0a7a2c:	8e2d0070 */ 	lw	$t5,0x70($s1)
/*  f0a7a30:	11a00003 */ 	beqz	$t5,.L0f0a7a40
/*  f0a7a34:	00000000 */ 	nop
/*  f0a7a38:	10000001 */ 	b	.L0f0a7a40
/*  f0a7a3c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f0a7a40:
/*  f0a7a40:	0062c021 */ 	addu	$t8,$v1,$v0
/*  f0a7a44:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f0a7a48:	03257821 */ 	addu	$t7,$t9,$a1
/*  f0a7a4c:	15e10036 */ 	bne	$t7,$at,.L0f0a7b28
/*  f0a7a50:	24050041 */ 	addiu	$a1,$zero,0x41
/*  f0a7a54:	0c006a47 */ 	jal	modelGetPart
/*  f0a7a58:	8e04038c */ 	lw	$a0,0x38c($s0)
/*  f0a7a5c:	50400033 */ 	beqzl	$v0,.L0f0a7b2c
/*  f0a7a60:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0a7a64:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0a7a68:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a7a6c:	84890010 */ 	lh	$t1,0x10($a0)
/*  f0a7a70:	5920002e */ 	blezl	$t1,.L0f0a7b2c
/*  f0a7a74:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0a7a78:	8e2a0034 */ 	lw	$t2,0x34($s1)
.L0f0a7a7c:
/*  f0a7a7c:	8c8e000c */ 	lw	$t6,0xc($a0)
/*  f0a7a80:	00056080 */ 	sll	$t4,$a1,0x2
/*  f0a7a84:	01520019 */ 	multu	$t2,$s2
/*  f0a7a88:	01856023 */ 	subu	$t4,$t4,$a1
/*  f0a7a8c:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0a7a90:	01cc1021 */ 	addu	$v0,$t6,$t4
/*  f0a7a94:	8448000a */ 	lh	$t0,0xa($v0)
/*  f0a7a98:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f0a7a9c:	0325c823 */ 	subu	$t9,$t9,$a1
/*  f0a7aa0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0a7aa4:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0a7aa8:	00005812 */ 	mflo	$t3
/*  f0a7aac:	010b6823 */ 	subu	$t5,$t0,$t3
/*  f0a7ab0:	a44d0008 */ 	sh	$t5,0x8($v0)
/*  f0a7ab4:	8c98000c */ 	lw	$t8,0xc($a0)
/*  f0a7ab8:	03197821 */ 	addu	$t7,$t8,$t9
/*  f0a7abc:	85e9000a */ 	lh	$t1,0xa($t7)
/*  f0a7ac0:	2921a000 */ 	slti	$at,$t1,-24576
/*  f0a7ac4:	50200014 */ 	beqzl	$at,.L0f0a7b18
/*  f0a7ac8:	84980010 */ 	lh	$t8,0x10($a0)
/*  f0a7acc:	848e0010 */ 	lh	$t6,0x10($a0)
/*  f0a7ad0:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a7ad4:	59c00010 */ 	blezl	$t6,.L0f0a7b18
/*  f0a7ad8:	84980010 */ 	lh	$t8,0x10($a0)
/*  f0a7adc:	8c8c000c */ 	lw	$t4,0xc($a0)
.L0f0a7ae0:
/*  f0a7ae0:	00035080 */ 	sll	$t2,$v1,0x2
/*  f0a7ae4:	01435023 */ 	subu	$t2,$t2,$v1
/*  f0a7ae8:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f0a7aec:	018a1021 */ 	addu	$v0,$t4,$t2
/*  f0a7af0:	8448000a */ 	lh	$t0,0xa($v0)
/*  f0a7af4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0a7af8:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0a7afc:	250b2000 */ 	addiu	$t3,$t0,0x2000
/*  f0a7b00:	a44b0008 */ 	sh	$t3,0x8($v0)
/*  f0a7b04:	848d0010 */ 	lh	$t5,0x10($a0)
/*  f0a7b08:	006d082a */ 	slt	$at,$v1,$t5
/*  f0a7b0c:	5420fff4 */ 	bnezl	$at,.L0f0a7ae0
/*  f0a7b10:	8c8c000c */ 	lw	$t4,0xc($a0)
/*  f0a7b14:	84980010 */ 	lh	$t8,0x10($a0)
.L0f0a7b18:
/*  f0a7b18:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0a7b1c:	00b8082a */ 	slt	$at,$a1,$t8
/*  f0a7b20:	5420ffd6 */ 	bnezl	$at,.L0f0a7a7c
/*  f0a7b24:	8e2a0034 */ 	lw	$t2,0x34($s1)
.L0f0a7b28:
/*  f0a7b28:	27a4010c */ 	addiu	$a0,$sp,0x10c
.L0f0a7b2c:
/*  f0a7b2c:	0c0087bd */ 	jal	modelRender
/*  f0a7b30:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f0a7b34:	8e791594 */ 	lw	$t9,0x1594($s3)
/*  f0a7b38:	3c0f8007 */ 	lui	$t7,%hi(var800702dc)
/*  f0a7b3c:	53200013 */ 	beqzl	$t9,.L0f0a7b8c
/*  f0a7b40:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f0a7b44:	8def02dc */ 	lw	$t7,%lo(var800702dc)($t7)
/*  f0a7b48:	8fa90140 */ 	lw	$t1,0x140($sp)
/*  f0a7b4c:	51e0000f */ 	beqzl	$t7,.L0f0a7b8c
/*  f0a7b50:	8fac0118 */ 	lw	$t4,0x118($sp)
/*  f0a7b54:	afa9007c */ 	sw	$t1,0x7c($sp)
/*  f0a7b58:	8e0e0390 */ 	lw	$t6,0x390($s0)
/*  f0a7b5c:	26050534 */ 	addiu	$a1,$s0,0x534
/*  f0a7b60:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0a7b64:	ae0e0540 */ 	sw	$t6,0x540($s0)
/*  f0a7b68:	0c007308 */ 	jal	model0001cc20
/*  f0a7b6c:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f0a7b70:	8fa50054 */ 	lw	$a1,0x54($sp)
/*  f0a7b74:	afb50140 */ 	sw	$s5,0x140($sp)
/*  f0a7b78:	0c0087bd */ 	jal	modelRender
/*  f0a7b7c:	27a4010c */ 	addiu	$a0,$sp,0x10c
/*  f0a7b80:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f0a7b84:	afa40140 */ 	sw	$a0,0x140($sp)
/*  f0a7b88:	8fac0118 */ 	lw	$t4,0x118($sp)
.L0f0a7b8c:
/*  f0a7b8c:	8fa400ec */ 	lw	$a0,0xec($sp)
/*  f0a7b90:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f0a7b94:	0fc2c5f0 */ 	jal	weaponHasFlag
/*  f0a7b98:	afac014c */ 	sw	$t4,0x14c($sp)
/*  f0a7b9c:	10400007 */ 	beqz	$v0,.L0f0a7bbc
/*  f0a7ba0:	8faa014c */ 	lw	$t2,0x14c($sp)
/*  f0a7ba4:	25480008 */ 	addiu	$t0,$t2,0x8
/*  f0a7ba8:	afa8014c */ 	sw	$t0,0x14c($sp)
/*  f0a7bac:	3c0bb600 */ 	lui	$t3,0xb600
/*  f0a7bb0:	240d3000 */ 	addiu	$t5,$zero,0x3000
/*  f0a7bb4:	ad4d0004 */ 	sw	$t5,0x4($t2)
/*  f0a7bb8:	ad4b0000 */ 	sw	$t3,0x0($t2)
.L0f0a7bbc:
/*  f0a7bbc:	8e18038c */ 	lw	$t8,0x38c($s0)
/*  f0a7bc0:	8e040390 */ 	lw	$a0,0x390($s0)
/*  f0a7bc4:	0fc30cfc */ 	jal	func0f0c33f0
/*  f0a7bc8:	8705000e */ 	lh	$a1,0xe($t8)
/*  f0a7bcc:	0c0059e1 */ 	jal	mtx00016784
/*  f0a7bd0:	00000000 */ 	nop
/*  f0a7bd4:	8fb9014c */ 	lw	$t9,0x14c($sp)
/*  f0a7bd8:	3c09bc00 */ 	lui	$t1,0xbc00
/*  f0a7bdc:	3529000e */ 	ori	$t1,$t1,0xe
/*  f0a7be0:	272f0008 */ 	addiu	$t7,$t9,0x8
/*  f0a7be4:	afaf014c */ 	sw	$t7,0x14c($sp)
/*  f0a7be8:	af290000 */ 	sw	$t1,0x0($t9)
/*  f0a7bec:	0c002adb */ 	jal	viGetPerspScale
/*  f0a7bf0:	afb90074 */ 	sw	$t9,0x74($sp)
/*  f0a7bf4:	8fa30074 */ 	lw	$v1,0x74($sp)
/*  f0a7bf8:	ac620004 */ 	sw	$v0,0x4($v1)
.L0f0a7bfc:
/*  f0a7bfc:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0a7c00:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a7c04:	1681fe04 */ 	bne	$s4,$at,.L0f0a7418
/*  f0a7c08:	261007a4 */ 	addiu	$s0,$s0,0x7a4
/*  f0a7c0c:	afb500e4 */ 	sw	$s5,0xe4($sp)
/*  f0a7c10:	0fc2baf8 */ 	jal	casingsRender
/*  f0a7c14:	27a4014c */ 	addiu	$a0,$sp,0x14c
/*  f0a7c18:	0fc5d8a6 */ 	jal	mblur0f176298
/*  f0a7c1c:	00000000 */ 	nop
/*  f0a7c20:	0fc5d8ab */ 	jal	mblur0f1762ac
/*  f0a7c24:	8fa4014c */ 	lw	$a0,0x14c($sp)
/*  f0a7c28:	afa2014c */ 	sw	$v0,0x14c($sp)
/*  f0a7c2c:	0c002c74 */ 	jal	vi0000b1d0
/*  f0a7c30:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a7c34:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f0a7c38:	afae014c */ 	sw	$t6,0x14c($sp)
/*  f0a7c3c:	0c002f40 */ 	jal	viGetViewLeft
/*  f0a7c40:	00408825 */ 	or	$s1,$v0,$zero
/*  f0a7c44:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a7c48:	00106403 */ 	sra	$t4,$s0,0x10
/*  f0a7c4c:	0c002f44 */ 	jal	viGetViewTop
/*  f0a7c50:	01808025 */ 	or	$s0,$t4,$zero
/*  f0a7c54:	44824000 */ 	mtc1	$v0,$f8
/*  f0a7c58:	44902000 */ 	mtc1	$s0,$f4
/*  f0a7c5c:	3c014080 */ 	lui	$at,0x4080
/*  f0a7c60:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0a7c64:	44810000 */ 	mtc1	$at,$f0
/*  f0a7c68:	3c01ed00 */ 	lui	$at,0xed00
/*  f0a7c6c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a7c70:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0a7c74:	00000000 */ 	nop
/*  f0a7c78:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a7c7c:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0a7c80:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0a7c84:	44089000 */ 	mfc1	$t0,$f18
/*  f0a7c88:	44195000 */ 	mfc1	$t9,$f10
/*  f0a7c8c:	310b0fff */ 	andi	$t3,$t0,0xfff
/*  f0a7c90:	01616825 */ 	or	$t5,$t3,$at
/*  f0a7c94:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f0a7c98:	000f4b00 */ 	sll	$t1,$t7,0xc
/*  f0a7c9c:	01a97025 */ 	or	$t6,$t5,$t1
/*  f0a7ca0:	0c002f22 */ 	jal	viGetViewWidth
/*  f0a7ca4:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f0a7ca8:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0a7cac:	00126403 */ 	sra	$t4,$s2,0x10
/*  f0a7cb0:	0c002f40 */ 	jal	viGetViewLeft
/*  f0a7cb4:	01809025 */ 	or	$s2,$t4,$zero
/*  f0a7cb8:	0002a400 */ 	sll	$s4,$v0,0x10
/*  f0a7cbc:	00145403 */ 	sra	$t2,$s4,0x10
/*  f0a7cc0:	0c002f44 */ 	jal	viGetViewTop
/*  f0a7cc4:	0140a025 */ 	or	$s4,$t2,$zero
/*  f0a7cc8:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a7ccc:	00104403 */ 	sra	$t0,$s0,0x10
/*  f0a7cd0:	0c002f26 */ 	jal	viGetViewHeight
/*  f0a7cd4:	01008025 */ 	or	$s0,$t0,$zero
/*  f0a7cd8:	00505821 */ 	addu	$t3,$v0,$s0
/*  f0a7cdc:	448b8000 */ 	mtc1	$t3,$f16
/*  f0a7ce0:	02926821 */ 	addu	$t5,$s4,$s2
/*  f0a7ce4:	448d5000 */ 	mtc1	$t5,$f10
/*  f0a7ce8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0a7cec:	3c014080 */ 	lui	$at,0x4080
/*  f0a7cf0:	44812000 */ 	mtc1	$at,$f4
/*  f0a7cf4:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0a7cf8:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0a7cfc:	44819000 */ 	mtc1	$at,$f18
/*  f0a7d00:	00000000 */ 	nop
/*  f0a7d04:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0a7d08:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0a7d0c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0a7d10:	44194000 */ 	mfc1	$t9,$f8
/*  f0a7d14:	440e3000 */ 	mfc1	$t6,$f6
/*  f0a7d18:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f0a7d1c:	31cc0fff */ 	andi	$t4,$t6,0xfff
/*  f0a7d20:	000c5300 */ 	sll	$t2,$t4,0xc
/*  f0a7d24:	01ea4025 */ 	or	$t0,$t7,$t2
/*  f0a7d28:	ae280004 */ 	sw	$t0,0x4($s1)
/*  f0a7d2c:	8fb80150 */ 	lw	$t8,0x150($sp)
/*  f0a7d30:	8fab014c */ 	lw	$t3,0x14c($sp)
/*  f0a7d34:	af0b0000 */ 	sw	$t3,0x0($t8)
/*  f0a7d38:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f0a7d3c:
/*  f0a7d3c:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f0a7d40:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f0a7d44:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f0a7d48:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f0a7d4c:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f0a7d50:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f0a7d54:	03e00008 */ 	jr	$ra
/*  f0a7d58:	27bd0150 */ 	addiu	$sp,$sp,0x150
);
#else
GLOBAL_ASM(
glabel bgunRender
.late_rodata
glabel var7f1aca8c
.word 0x3faaaaab
glabel var7f1aca90
.word 0x3f3ebebf
.text
/*  f0a4e84:	27bdfeb8 */ 	addiu	$sp,$sp,-328
/*  f0a4e88:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f0a4e8c:	afb50030 */ 	sw	$s5,0x30($sp)
/*  f0a4e90:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f0a4e94:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f0a4e98:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f0a4e9c:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f0a4ea0:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0a4ea4:	afa40148 */ 	sw	$a0,0x148($sp)
/*  f0a4ea8:	8c8f0000 */ 	lw	$t7,0x0($a0)
/*  f0a4eac:	3c198007 */ 	lui	$t9,0x8007
/*  f0a4eb0:	3c11800a */ 	lui	$s1,0x800a
/*  f0a4eb4:	2739295c */ 	addiu	$t9,$t9,0x295c
/*  f0a4eb8:	2631e6c0 */ 	addiu	$s1,$s1,-6464
/*  f0a4ebc:	272a003c */ 	addiu	$t2,$t9,0x3c
/*  f0a4ec0:	27b80104 */ 	addiu	$t8,$sp,0x104
/*  f0a4ec4:	afaf0144 */ 	sw	$t7,0x144($sp)
.NB0f0a4ec8:
/*  f0a4ec8:	8f210000 */ 	lw	$at,0x0($t9)
/*  f0a4ecc:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f0a4ed0:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f0a4ed4:	af01fff4 */ 	sw	$at,-0xc($t8)
/*  f0a4ed8:	8f21fff8 */ 	lw	$at,-0x8($t9)
/*  f0a4edc:	af01fff8 */ 	sw	$at,-0x8($t8)
/*  f0a4ee0:	8f21fffc */ 	lw	$at,-0x4($t9)
/*  f0a4ee4:	172afff8 */ 	bne	$t9,$t2,.NB0f0a4ec8
/*  f0a4ee8:	af01fffc */ 	sw	$at,-0x4($t8)
/*  f0a4eec:	8f210000 */ 	lw	$at,0x0($t9)
/*  f0a4ef0:	af010000 */ 	sw	$at,0x0($t8)
/*  f0a4ef4:	8e330284 */ 	lw	$s3,0x284($s1)
/*  f0a4ef8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a4efc:	966b0010 */ 	lhu	$t3,0x10($s3)
/*  f0a4f00:	1561000d */ 	bne	$t3,$at,.NB0f0a4f38
/*  f0a4f04:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a4f08:	24040f48 */ 	addiu	$a0,$zero,0xf48
/*  f0a4f0c:	8e2c0284 */ 	lw	$t4,0x284($s1)
.NB0f0a4f10:
/*  f0a4f10:	01821821 */ 	addu	$v1,$t4,$v0
/*  f0a4f14:	8c6d0854 */ 	lw	$t5,0x854($v1)
/*  f0a4f18:	244207a4 */ 	addiu	$v0,$v0,0x7a4
/*  f0a4f1c:	11a00002 */ 	beqz	$t5,.NB0f0a4f28
/*  f0a4f20:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4f24:	ac600850 */ 	sw	$zero,0x850($v1)
.NB0f0a4f28:
/*  f0a4f28:	5444fff9 */ 	bnel	$v0,$a0,.NB0f0a4f10
/*  f0a4f2c:	8e2c0284 */ 	lw	$t4,0x284($s1)
/*  f0a4f30:	100002cd */ 	beqz	$zero,.NB0f0a5a68
/*  f0a4f34:	8fbf0034 */ 	lw	$ra,0x34($sp)
.NB0f0a4f38:
/*  f0a4f38:	0fc5c4d5 */ 	jal	mblurRender
/*  f0a4f3c:	8fa40144 */ 	lw	$a0,0x144($sp)
/*  f0a4f40:	afa20144 */ 	sw	$v0,0x144($sp)
/*  f0a4f44:	0c002d00 */ 	jal	vi0000b280
/*  f0a4f48:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a4f4c:	afa20144 */ 	sw	$v0,0x144($sp)
/*  f0a4f50:	0c002cd4 */ 	jal	vi0000b1d0
/*  f0a4f54:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a4f58:	244e0008 */ 	addiu	$t6,$v0,0x8
/*  f0a4f5c:	afae0144 */ 	sw	$t6,0x144($sp)
/*  f0a4f60:	0c002fb5 */ 	jal	viGetViewLeft
/*  f0a4f64:	0040a825 */ 	or	$s5,$v0,$zero
/*  f0a4f68:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a4f6c:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0a4f70:	0c002fb9 */ 	jal	viGetViewTop
/*  f0a4f74:	01e08025 */ 	or	$s0,$t7,$zero
/*  f0a4f78:	44822000 */ 	mtc1	$v0,$f4
/*  f0a4f7c:	44908000 */ 	mtc1	$s0,$f16
/*  f0a4f80:	3c014080 */ 	lui	$at,0x4080
/*  f0a4f84:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a4f88:	44810000 */ 	mtc1	$at,$f0
/*  f0a4f8c:	3c01ed00 */ 	lui	$at,0xed00
/*  f0a4f90:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0a4f94:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a4f98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a4f9c:	46009102 */ 	mul.s	$f4,$f18,$f0
/*  f0a4fa0:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0a4fa4:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0a4fa8:	44085000 */ 	mfc1	$t0,$f10
/*  f0a4fac:	440b3000 */ 	mfc1	$t3,$f6
/*  f0a4fb0:	310a0fff */ 	andi	$t2,$t0,0xfff
/*  f0a4fb4:	0141c825 */ 	or	$t9,$t2,$at
/*  f0a4fb8:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f0a4fbc:	000c6b00 */ 	sll	$t5,$t4,0xc
/*  f0a4fc0:	032d7025 */ 	or	$t6,$t9,$t5
/*  f0a4fc4:	0c002f97 */ 	jal	viGetViewWidth
/*  f0a4fc8:	aeae0000 */ 	sw	$t6,0x0($s5)
/*  f0a4fcc:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0a4fd0:	00127c03 */ 	sra	$t7,$s2,0x10
/*  f0a4fd4:	0c002fb5 */ 	jal	viGetViewLeft
/*  f0a4fd8:	01e09025 */ 	or	$s2,$t7,$zero
/*  f0a4fdc:	0002a400 */ 	sll	$s4,$v0,0x10
/*  f0a4fe0:	00144c03 */ 	sra	$t1,$s4,0x10
/*  f0a4fe4:	0c002fb9 */ 	jal	viGetViewTop
/*  f0a4fe8:	0120a025 */ 	or	$s4,$t1,$zero
/*  f0a4fec:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a4ff0:	00104403 */ 	sra	$t0,$s0,0x10
/*  f0a4ff4:	0c002f9b */ 	jal	viGetViewHeight
/*  f0a4ff8:	01008025 */ 	or	$s0,$t0,$zero
/*  f0a4ffc:	00505021 */ 	addu	$t2,$v0,$s0
/*  f0a5000:	448a4000 */ 	mtc1	$t2,$f8
/*  f0a5004:	0292c821 */ 	addu	$t9,$s4,$s2
/*  f0a5008:	44992000 */ 	mtc1	$t9,$f4
/*  f0a500c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0a5010:	3c014080 */ 	lui	$at,0x4080
/*  f0a5014:	44810000 */ 	mtc1	$at,$f0
/*  f0a5018:	3c053fc0 */ 	lui	$a1,0x3fc0
/*  f0a501c:	3c06447a */ 	lui	$a2,0x447a
/*  f0a5020:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a5024:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0a5028:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a502c:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a5030:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0a5034:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0a5038:	440b9000 */ 	mfc1	$t3,$f18
/*  f0a503c:	440e5000 */ 	mfc1	$t6,$f10
/*  f0a5040:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f0a5044:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f0a5048:	000f4b00 */ 	sll	$t1,$t7,0xc
/*  f0a504c:	01894025 */ 	or	$t0,$t4,$t1
/*  f0a5050:	aea80004 */ 	sw	$t0,0x4($s5)
/*  f0a5054:	0c002b89 */ 	jal	vi0000aca4
/*  f0a5058:	8fa40144 */ 	lw	$a0,0x144($sp)
/*  f0a505c:	8e2a0284 */ 	lw	$t2,0x284($s1)
/*  f0a5060:	afa20144 */ 	sw	$v0,0x144($sp)
/*  f0a5064:	91581bfc */ 	lbu	$t8,0x1bfc($t2)
/*  f0a5068:	53000016 */ 	beqzl	$t8,.NB0f0a50c4
/*  f0a506c:	8e2b006c */ 	lw	$t3,0x6c($s1)
/*  f0a5070:	0fc53582 */ 	jal	optionsGetScreenRatio
/*  f0a5074:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5078:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a507c:	14410008 */ 	bne	$v0,$at,.NB0f0a50a0
/*  f0a5080:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5084:	0fc2ebf0 */ 	jal	player0f0bd358
/*  f0a5088:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a508c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0a5090:	c4306dd4 */ 	lwc1	$f16,0x6dd4($at)
/*  f0a5094:	46100082 */ 	mul.s	$f2,$f0,$f16
/*  f0a5098:	10000005 */ 	beqz	$zero,.NB0f0a50b0
/*  f0a509c:	44061000 */ 	mfc1	$a2,$f2
.NB0f0a50a0:
/*  f0a50a0:	0fc2ebf0 */ 	jal	player0f0bd358
/*  f0a50a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a50a8:	46000086 */ 	mov.s	$f2,$f0
/*  f0a50ac:	44061000 */ 	mfc1	$a2,$f2
.NB0f0a50b0:
/*  f0a50b0:	8fa40144 */ 	lw	$a0,0x144($sp)
/*  f0a50b4:	0c002c9a */ 	jal	vi0000b0e8
/*  f0a50b8:	3c054270 */ 	lui	$a1,0x4270
/*  f0a50bc:	afa20144 */ 	sw	$v0,0x144($sp)
/*  f0a50c0:	8e2b006c */ 	lw	$t3,0x6c($s1)
.NB0f0a50c4:
/*  f0a50c4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a50c8:	51600004 */ 	beqzl	$t3,.NB0f0a50dc
/*  f0a50cc:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a50d0:	10000002 */ 	beqz	$zero,.NB0f0a50dc
/*  f0a50d4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0a50d8:	00002825 */ 	or	$a1,$zero,$zero
.NB0f0a50dc:
/*  f0a50dc:	8e390068 */ 	lw	$t9,0x68($s1)
/*  f0a50e0:	53200004 */ 	beqzl	$t9,.NB0f0a50f4
/*  f0a50e4:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a50e8:	10000002 */ 	beqz	$zero,.NB0f0a50f4
/*  f0a50ec:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0a50f0:	00002025 */ 	or	$a0,$zero,$zero
.NB0f0a50f4:
/*  f0a50f4:	8e2d0064 */ 	lw	$t5,0x64($s1)
/*  f0a50f8:	51a00004 */ 	beqzl	$t5,.NB0f0a510c
/*  f0a50fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a5100:	10000002 */ 	beqz	$zero,.NB0f0a510c
/*  f0a5104:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f0a5108:	00001025 */ 	or	$v0,$zero,$zero
.NB0f0a510c:
/*  f0a510c:	8e2e0070 */ 	lw	$t6,0x70($s1)
/*  f0a5110:	51c00004 */ 	beqzl	$t6,.NB0f0a5124
/*  f0a5114:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a5118:	10000002 */ 	beqz	$zero,.NB0f0a5124
/*  f0a511c:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0a5120:	00001825 */ 	or	$v1,$zero,$zero
.NB0f0a5124:
/*  f0a5124:	00627821 */ 	addu	$t7,$v1,$v0
/*  f0a5128:	01e46021 */ 	addu	$t4,$t7,$a0
/*  f0a512c:	01854821 */ 	addu	$t1,$t4,$a1
/*  f0a5130:	15210008 */ 	bne	$t1,$at,.NB0f0a5154
/*  f0a5134:	3c088009 */ 	lui	$t0,0x8009
/*  f0a5138:	910830e0 */ 	lbu	$t0,0x30e0($t0)
/*  f0a513c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a5140:	51010005 */ 	beql	$t0,$at,.NB0f0a5158
/*  f0a5144:	0000a025 */ 	or	$s4,$zero,$zero
/*  f0a5148:	0fc2b5eb */ 	jal	lasersightRenderBeam
/*  f0a514c:	8fa40144 */ 	lw	$a0,0x144($sp)
/*  f0a5150:	afa20144 */ 	sw	$v0,0x144($sp)
.NB0f0a5154:
/*  f0a5154:	0000a025 */ 	or	$s4,$zero,$zero
.NB0f0a5158:
/*  f0a5158:	26700638 */ 	addiu	$s0,$s3,0x638
/*  f0a515c:	8fb500dc */ 	lw	$s5,0xdc($sp)
/*  f0a5160:	24120019 */ 	addiu	$s2,$zero,0x19
.NB0f0a5164:
/*  f0a5164:	0fc27de9 */ 	jal	bgunGetWeaponNum2
/*  f0a5168:	02802025 */ 	or	$a0,$s4,$zero
/*  f0a516c:	afa200e4 */ 	sw	$v0,0xe4($sp)
/*  f0a5170:	820a0007 */ 	lb	$t2,0x7($s0)
/*  f0a5174:	8fa40144 */ 	lw	$a0,0x144($sp)
/*  f0a5178:	260501dc */ 	addiu	$a1,$s0,0x1dc
/*  f0a517c:	114001ea */ 	beqz	$t2,.NB0f0a5928
/*  f0a5180:	00003025 */ 	or	$a2,$zero,$zero
/*  f0a5184:	26180384 */ 	addiu	$t8,$s0,0x384
/*  f0a5188:	afb80038 */ 	sw	$t8,0x38($sp)
/*  f0a518c:	0fc2aa3c */ 	jal	beamRender
/*  f0a5190:	00003825 */ 	or	$a3,$zero,$zero
/*  f0a5194:	afa20144 */ 	sw	$v0,0x144($sp)
/*  f0a5198:	92040000 */ 	lbu	$a0,0x0($s0)
/*  f0a519c:	0fc2bd48 */ 	jal	weaponHasFlag
/*  f0a51a0:	34058000 */ 	dli	$a1,0x8000
/*  f0a51a4:	10400030 */ 	beqz	$v0,.NB0f0a5268
/*  f0a51a8:	8fab0144 */ 	lw	$t3,0x144($sp)
/*  f0a51ac:	25790008 */ 	addiu	$t9,$t3,0x8
/*  f0a51b0:	afb90144 */ 	sw	$t9,0x144($sp)
/*  f0a51b4:	3c0dbc00 */ 	lui	$t5,0xbc00
/*  f0a51b8:	3c0e8000 */ 	lui	$t6,0x8000
/*  f0a51bc:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f0a51c0:	35ad0002 */ 	ori	$t5,$t5,0x2
/*  f0a51c4:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f0a51c8:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f0a51cc:	8faf0144 */ 	lw	$t7,0x144($sp)
/*  f0a51d0:	3c090386 */ 	lui	$t1,0x386
/*  f0a51d4:	3c088007 */ 	lui	$t0,0x8007
/*  f0a51d8:	25ec0008 */ 	addiu	$t4,$t7,0x8
/*  f0a51dc:	afac0144 */ 	sw	$t4,0x144($sp)
/*  f0a51e0:	25082758 */ 	addiu	$t0,$t0,0x2758
/*  f0a51e4:	35290010 */ 	ori	$t1,$t1,0x10
/*  f0a51e8:	ade90000 */ 	sw	$t1,0x0($t7)
/*  f0a51ec:	ade80004 */ 	sw	$t0,0x4($t7)
/*  f0a51f0:	8faa0144 */ 	lw	$t2,0x144($sp)
/*  f0a51f4:	3c0b0388 */ 	lui	$t3,0x388
/*  f0a51f8:	3c198007 */ 	lui	$t9,0x8007
/*  f0a51fc:	25580008 */ 	addiu	$t8,$t2,0x8
/*  f0a5200:	afb80144 */ 	sw	$t8,0x144($sp)
/*  f0a5204:	27392750 */ 	addiu	$t9,$t9,0x2750
/*  f0a5208:	356b0010 */ 	ori	$t3,$t3,0x10
/*  f0a520c:	ad4b0000 */ 	sw	$t3,0x0($t2)
/*  f0a5210:	ad590004 */ 	sw	$t9,0x4($t2)
/*  f0a5214:	8fad0144 */ 	lw	$t5,0x144($sp)
/*  f0a5218:	3c0f0384 */ 	lui	$t7,0x384
/*  f0a521c:	35ef0010 */ 	ori	$t7,$t7,0x10
/*  f0a5220:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f0a5224:	afae0144 */ 	sw	$t6,0x144($sp)
/*  f0a5228:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f0a522c:	0fc2cd42 */ 	jal	camGetLookAt
/*  f0a5230:	afad00cc */ 	sw	$t5,0xcc($sp)
/*  f0a5234:	8fa500cc */ 	lw	$a1,0xcc($sp)
/*  f0a5238:	3c080382 */ 	lui	$t0,0x382
/*  f0a523c:	35080010 */ 	ori	$t0,$t0,0x10
/*  f0a5240:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f0a5244:	8fac0144 */ 	lw	$t4,0x144($sp)
/*  f0a5248:	25890008 */ 	addiu	$t1,$t4,0x8
/*  f0a524c:	afa90144 */ 	sw	$t1,0x144($sp)
/*  f0a5250:	ad880000 */ 	sw	$t0,0x0($t4)
/*  f0a5254:	0fc2cd42 */ 	jal	camGetLookAt
/*  f0a5258:	afac00c8 */ 	sw	$t4,0xc8($sp)
/*  f0a525c:	8fa300c8 */ 	lw	$v1,0xc8($sp)
/*  f0a5260:	244a0010 */ 	addiu	$t2,$v0,0x10
/*  f0a5264:	ac6a0004 */ 	sw	$t2,0x4($v1)
.NB0f0a5268:
/*  f0a5268:	8fb80144 */ 	lw	$t8,0x144($sp)
/*  f0a526c:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f0a5270:	3739000e */ 	ori	$t9,$t9,0xe
/*  f0a5274:	270b0008 */ 	addiu	$t3,$t8,0x8
/*  f0a5278:	afab0144 */ 	sw	$t3,0x144($sp)
/*  f0a527c:	3c014396 */ 	lui	$at,0x4396
/*  f0a5280:	44817000 */ 	mtc1	$at,$f14
/*  f0a5284:	44806000 */ 	mtc1	$zero,$f12
/*  f0a5288:	af190000 */ 	sw	$t9,0x0($t8)
/*  f0a528c:	0c005f57 */ 	jal	mtx00016dcc
/*  f0a5290:	afb800c4 */ 	sw	$t8,0xc4($sp)
/*  f0a5294:	8fa300c4 */ 	lw	$v1,0xc4($sp)
/*  f0a5298:	24050010 */ 	addiu	$a1,$zero,0x10
/*  f0a529c:	ac620004 */ 	sw	$v0,0x4($v1)
/*  f0a52a0:	0c006ea3 */ 	jal	modelGetPart
/*  f0a52a4:	8e04038c */ 	lw	$a0,0x38c($s0)
/*  f0a52a8:	10400014 */ 	beqz	$v0,.NB0f0a52fc
/*  f0a52ac:	afa200e0 */ 	sw	$v0,0xe0($sp)
/*  f0a52b0:	8e04038c */ 	lw	$a0,0x38c($s0)
/*  f0a52b4:	0c006ea3 */ 	jal	modelGetPart
/*  f0a52b8:	24050011 */ 	addiu	$a1,$zero,0x11
/*  f0a52bc:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0a52c0:	0c006bab */ 	jal	modelGetNodeRwData
/*  f0a52c4:	00402825 */ 	or	$a1,$v0,$zero
/*  f0a52c8:	10400003 */ 	beqz	$v0,.NB0f0a52d8
/*  f0a52cc:	3c06800a */ 	lui	$a2,0x800a
/*  f0a52d0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f0a52d4:	ac4d0000 */ 	sw	$t5,0x0($v0)
.NB0f0a52d8:
/*  f0a52d8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0a52dc:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f0a52e0:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0a52e4:	8fa500e0 */ 	lw	$a1,0xe0($sp)
/*  f0a52e8:	24c616b8 */ 	addiu	$a2,$a2,0x16b8
/*  f0a52ec:	8fa70144 */ 	lw	$a3,0x144($sp)
/*  f0a52f0:	0fc1f99c */ 	jal	tvscreenRender
/*  f0a52f4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f0a52f8:	afa20144 */ 	sw	$v0,0x144($sp)
.NB0f0a52fc:
/*  f0a52fc:	8faf0144 */ 	lw	$t7,0x144($sp)
/*  f0a5300:	8e250284 */ 	lw	$a1,0x284($s1)
/*  f0a5304:	240c0004 */ 	addiu	$t4,$zero,0x4
/*  f0a5308:	afac0134 */ 	sw	$t4,0x134($sp)
/*  f0a530c:	afaf0110 */ 	sw	$t7,0x110($sp)
/*  f0a5310:	8ca300d8 */ 	lw	$v1,0xd8($a1)
/*  f0a5314:	3c078007 */ 	lui	$a3,0x8007
/*  f0a5318:	14600013 */ 	bnez	$v1,.NB0f0a5368
/*  f0a531c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5320:	8ce72e24 */ 	lw	$a3,0x2e24($a3)
/*  f0a5324:	14e00010 */ 	bnez	$a3,.NB0f0a5368
/*  f0a5328:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a532c:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a5330:	50400007 */ 	beqzl	$v0,.NB0f0a5350
/*  f0a5334:	8caa1c54 */ 	lw	$t2,0x1c54($a1)
/*  f0a5338:	1040000b */ 	beqz	$v0,.NB0f0a5368
/*  f0a533c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5340:	80490037 */ 	lb	$t1,0x37($v0)
/*  f0a5344:	15200008 */ 	bnez	$t1,.NB0f0a5368
/*  f0a5348:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a534c:	8caa1c54 */ 	lw	$t2,0x1c54($a1)
.NB0f0a5350:
/*  f0a5350:	8ca800c4 */ 	lw	$t0,0xc4($a1)
/*  f0a5354:	0140c027 */ 	nor	$t8,$t2,$zero
/*  f0a5358:	01185824 */ 	and	$t3,$t0,$t8
/*  f0a535c:	31790001 */ 	andi	$t9,$t3,0x1
/*  f0a5360:	57200016 */ 	bnezl	$t9,.NB0f0a53bc
/*  f0a5364:	92681615 */ 	lbu	$t0,0x1615($s3)
.NB0f0a5368:
/*  f0a5368:	14600078 */ 	bnez	$v1,.NB0f0a554c
/*  f0a536c:	3c078007 */ 	lui	$a3,0x8007
/*  f0a5370:	8ce72e24 */ 	lw	$a3,0x2e24($a3)
/*  f0a5374:	54e00076 */ 	bnezl	$a3,.NB0f0a5550
/*  f0a5378:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a537c:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a5380:	50400007 */ 	beqzl	$v0,.NB0f0a53a0
/*  f0a5384:	8caf1c54 */ 	lw	$t7,0x1c54($a1)
/*  f0a5388:	50400071 */ 	beqzl	$v0,.NB0f0a5550
/*  f0a538c:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a5390:	804d0037 */ 	lb	$t5,0x37($v0)
/*  f0a5394:	55a0006e */ 	bnezl	$t5,.NB0f0a5550
/*  f0a5398:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a539c:	8caf1c54 */ 	lw	$t7,0x1c54($a1)
.NB0f0a53a0:
/*  f0a53a0:	8cae00c4 */ 	lw	$t6,0xc4($a1)
/*  f0a53a4:	01e06027 */ 	nor	$t4,$t7,$zero
/*  f0a53a8:	01cc4824 */ 	and	$t1,$t6,$t4
/*  f0a53ac:	312a0008 */ 	andi	$t2,$t1,0x8
/*  f0a53b0:	51400067 */ 	beqzl	$t2,.NB0f0a5550
/*  f0a53b4:	926d1614 */ 	lbu	$t5,0x1614($s3)
/*  f0a53b8:	92681615 */ 	lbu	$t0,0x1615($s3)
.NB0f0a53bc:
/*  f0a53bc:	92781614 */ 	lbu	$t8,0x1614($s3)
/*  f0a53c0:	26641614 */ 	addiu	$a0,$s3,0x1614
/*  f0a53c4:	0118082a */ 	slt	$at,$t0,$t8
/*  f0a53c8:	50200009 */ 	beqzl	$at,.NB0f0a53f0
/*  f0a53cc:	90820002 */ 	lbu	$v0,0x2($a0)
/*  f0a53d0:	90830000 */ 	lbu	$v1,0x0($a0)
/*  f0a53d4:	908b0002 */ 	lbu	$t3,0x2($a0)
/*  f0a53d8:	0163082a */ 	slt	$at,$t3,$v1
/*  f0a53dc:	50200004 */ 	beqzl	$at,.NB0f0a53f0
/*  f0a53e0:	90820002 */ 	lbu	$v0,0x2($a0)
/*  f0a53e4:	1000000a */ 	beqz	$zero,.NB0f0a5410
/*  f0a53e8:	00601025 */ 	or	$v0,$v1,$zero
/*  f0a53ec:	90820002 */ 	lbu	$v0,0x2($a0)
.NB0f0a53f0:
/*  f0a53f0:	90860001 */ 	lbu	$a2,0x1($a0)
/*  f0a53f4:	00401825 */ 	or	$v1,$v0,$zero
/*  f0a53f8:	0046082a */ 	slt	$at,$v0,$a2
/*  f0a53fc:	10200003 */ 	beqz	$at,.NB0f0a540c
/*  f0a5400:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5404:	10000001 */ 	beqz	$zero,.NB0f0a540c
/*  f0a5408:	00c01825 */ 	or	$v1,$a2,$zero
.NB0f0a540c:
/*  f0a540c:	00601025 */ 	or	$v0,$v1,$zero
.NB0f0a5410:
/*  f0a5410:	90890003 */ 	lbu	$t1,0x3($a0)
/*  f0a5414:	0002ce00 */ 	sll	$t9,$v0,0x18
/*  f0a5418:	00026c00 */ 	sll	$t5,$v0,0x10
/*  f0a541c:	032d7825 */ 	or	$t7,$t9,$t5
/*  f0a5420:	00027200 */ 	sll	$t6,$v0,0x8
/*  f0a5424:	01ee6025 */ 	or	$t4,$t7,$t6
/*  f0a5428:	012c5021 */ 	addu	$t2,$t1,$t4
/*  f0a542c:	afaa0138 */ 	sw	$t2,0x138($sp)
/*  f0a5430:	8ca300d8 */ 	lw	$v1,0xd8($a1)
/*  f0a5434:	14600021 */ 	bnez	$v1,.NB0f0a54bc
/*  f0a5438:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a543c:	14e0001f */ 	bnez	$a3,.NB0f0a54bc
/*  f0a5440:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5444:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a5448:	50400007 */ 	beqzl	$v0,.NB0f0a5468
/*  f0a544c:	8cab1c54 */ 	lw	$t3,0x1c54($a1)
/*  f0a5450:	1040001a */ 	beqz	$v0,.NB0f0a54bc
/*  f0a5454:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5458:	80480037 */ 	lb	$t0,0x37($v0)
/*  f0a545c:	15000017 */ 	bnez	$t0,.NB0f0a54bc
/*  f0a5460:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5464:	8cab1c54 */ 	lw	$t3,0x1c54($a1)
.NB0f0a5468:
/*  f0a5468:	8cb800c4 */ 	lw	$t8,0xc4($a1)
/*  f0a546c:	3c02800a */ 	lui	$v0,0x800a
/*  f0a5470:	0160c827 */ 	nor	$t9,$t3,$zero
/*  f0a5474:	03196824 */ 	and	$t5,$t8,$t9
/*  f0a5478:	31af0001 */ 	andi	$t7,$t5,0x1
/*  f0a547c:	11e0000f */ 	beqz	$t7,.NB0f0a54bc
/*  f0a5480:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5484:	9042122f */ 	lbu	$v0,0x122f($v0)
/*  f0a5488:	3c06800a */ 	lui	$a2,0x800a
/*  f0a548c:	90c61230 */ 	lbu	$a2,0x1230($a2)
/*  f0a5490:	00027600 */ 	sll	$t6,$v0,0x18
/*  f0a5494:	00024c00 */ 	sll	$t1,$v0,0x10
/*  f0a5498:	01c96025 */ 	or	$t4,$t6,$t1
/*  f0a549c:	00025200 */ 	sll	$t2,$v0,0x8
/*  f0a54a0:	018a4025 */ 	or	$t0,$t4,$t2
/*  f0a54a4:	afa200a8 */ 	sw	$v0,0xa8($sp)
/*  f0a54a8:	afa200ac */ 	sw	$v0,0xac($sp)
/*  f0a54ac:	afa200b0 */ 	sw	$v0,0xb0($sp)
/*  f0a54b0:	00c8a821 */ 	addu	$s5,$a2,$t0
/*  f0a54b4:	1000001f */ 	beqz	$zero,.NB0f0a5534
/*  f0a54b8:	afa600b4 */ 	sw	$a2,0xb4($sp)
.NB0f0a54bc:
/*  f0a54bc:	5460001e */ 	bnezl	$v1,.NB0f0a5538
/*  f0a54c0:	8fb900e4 */ 	lw	$t9,0xe4($sp)
/*  f0a54c4:	54e0001c */ 	bnezl	$a3,.NB0f0a5538
/*  f0a54c8:	8fb900e4 */ 	lw	$t9,0xe4($sp)
/*  f0a54cc:	8ca20480 */ 	lw	$v0,0x480($a1)
/*  f0a54d0:	50400007 */ 	beqzl	$v0,.NB0f0a54f0
/*  f0a54d4:	8cb91c54 */ 	lw	$t9,0x1c54($a1)
/*  f0a54d8:	50400017 */ 	beqzl	$v0,.NB0f0a5538
/*  f0a54dc:	8fb900e4 */ 	lw	$t9,0xe4($sp)
/*  f0a54e0:	804b0037 */ 	lb	$t3,0x37($v0)
/*  f0a54e4:	55600014 */ 	bnezl	$t3,.NB0f0a5538
/*  f0a54e8:	8fb900e4 */ 	lw	$t9,0xe4($sp)
/*  f0a54ec:	8cb91c54 */ 	lw	$t9,0x1c54($a1)
.NB0f0a54f0:
/*  f0a54f0:	8cb800c4 */ 	lw	$t8,0xc4($a1)
/*  f0a54f4:	240200ff */ 	addiu	$v0,$zero,0xff
/*  f0a54f8:	03206827 */ 	nor	$t5,$t9,$zero
/*  f0a54fc:	030d7824 */ 	and	$t7,$t8,$t5
/*  f0a5500:	31ee0008 */ 	andi	$t6,$t7,0x8
/*  f0a5504:	11c0000b */ 	beqz	$t6,.NB0f0a5534
/*  f0a5508:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f0a550c:	00024e00 */ 	sll	$t1,$v0,0x18
/*  f0a5510:	00006400 */ 	sll	$t4,$zero,0x10
/*  f0a5514:	012c5025 */ 	or	$t2,$t1,$t4
/*  f0a5518:	00004200 */ 	sll	$t0,$zero,0x8
/*  f0a551c:	01485825 */ 	or	$t3,$t2,$t0
/*  f0a5520:	00aba821 */ 	addu	$s5,$a1,$t3
/*  f0a5524:	afa20098 */ 	sw	$v0,0x98($sp)
/*  f0a5528:	afa0009c */ 	sw	$zero,0x9c($sp)
/*  f0a552c:	afa000a0 */ 	sw	$zero,0xa0($sp)
/*  f0a5530:	afa500a4 */ 	sw	$a1,0xa4($sp)
.NB0f0a5534:
/*  f0a5534:	8fb900e4 */ 	lw	$t9,0xe4($sp)
.NB0f0a5538:
/*  f0a5538:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a553c:	5721003d */ 	bnel	$t9,$at,.NB0f0a5634
/*  f0a5540:	8e6f00bc */ 	lw	$t7,0xbc($s3)
/*  f0a5544:	1000003a */ 	beqz	$zero,.NB0f0a5630
/*  f0a5548:	afb50138 */ 	sw	$s5,0x138($sp)
.NB0f0a554c:
/*  f0a554c:	926d1614 */ 	lbu	$t5,0x1614($s3)
.NB0f0a5550:
/*  f0a5550:	92781617 */ 	lbu	$t8,0x1617($s3)
/*  f0a5554:	92691615 */ 	lbu	$t1,0x1615($s3)
/*  f0a5558:	92681616 */ 	lbu	$t0,0x1616($s3)
/*  f0a555c:	000d7e00 */ 	sll	$t7,$t5,0x18
/*  f0a5560:	030f7025 */ 	or	$t6,$t8,$t7
/*  f0a5564:	00096400 */ 	sll	$t4,$t1,0x10
/*  f0a5568:	01cc5025 */ 	or	$t2,$t6,$t4
/*  f0a556c:	00085a00 */ 	sll	$t3,$t0,0x8
/*  f0a5570:	014bc825 */ 	or	$t9,$t2,$t3
/*  f0a5574:	afb90138 */ 	sw	$t9,0x138($sp)
/*  f0a5578:	920d0000 */ 	lbu	$t5,0x0($s0)
/*  f0a557c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f0a5580:	0320a825 */ 	or	$s5,$t9,$zero
/*  f0a5584:	15a1002a */ 	bne	$t5,$at,.NB0f0a5630
/*  f0a5588:	3c04ff00 */ 	lui	$a0,0xff00
/*  f0a558c:	3c014248 */ 	lui	$at,0x4248
/*  f0a5590:	44812000 */ 	mtc1	$at,$f4
/*  f0a5594:	c612023c */ 	lwc1	$f18,0x23c($s0)
/*  f0a5598:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0a559c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0a55a0:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0a55a4:	3484007f */ 	ori	$a0,$a0,0x7f
/*  f0a55a8:	4458f800 */ 	cfc1	$t8,$31
/*  f0a55ac:	44c6f800 */ 	ctc1	$a2,$31
/*  f0a55b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a55b4:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0a55b8:	4446f800 */ 	cfc1	$a2,$31
/*  f0a55bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a55c0:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0a55c4:	50c00013 */ 	beqzl	$a2,.NB0f0a5614
/*  f0a55c8:	44064000 */ 	mfc1	$a2,$f8
/*  f0a55cc:	44814000 */ 	mtc1	$at,$f8
/*  f0a55d0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0a55d4:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0a55d8:	44c6f800 */ 	ctc1	$a2,$31
/*  f0a55dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a55e0:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0a55e4:	4446f800 */ 	cfc1	$a2,$31
/*  f0a55e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a55ec:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f0a55f0:	14c00005 */ 	bnez	$a2,.NB0f0a5608
/*  f0a55f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a55f8:	44064000 */ 	mfc1	$a2,$f8
/*  f0a55fc:	3c018000 */ 	lui	$at,0x8000
/*  f0a5600:	10000007 */ 	beqz	$zero,.NB0f0a5620
/*  f0a5604:	00c13025 */ 	or	$a2,$a2,$at
.NB0f0a5608:
/*  f0a5608:	10000005 */ 	beqz	$zero,.NB0f0a5620
/*  f0a560c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f0a5610:	44064000 */ 	mfc1	$a2,$f8
.NB0f0a5614:
/*  f0a5614:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5618:	04c0fffb */ 	bltz	$a2,.NB0f0a5608
/*  f0a561c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f0a5620:
/*  f0a5620:	44d8f800 */ 	ctc1	$t8,$31
/*  f0a5624:	0fc01990 */ 	jal	colourBlend
/*  f0a5628:	03202825 */ 	or	$a1,$t9,$zero
/*  f0a562c:	afa20138 */ 	sw	$v0,0x138($sp)
.NB0f0a5630:
/*  f0a5630:	8e6f00bc */ 	lw	$t7,0xbc($s3)
.NB0f0a5634:
/*  f0a5634:	0fc089b4 */ 	jal	chrGetCloakAlpha
/*  f0a5638:	8de40004 */ 	lw	$a0,0x4($t7)
/*  f0a563c:	284100ff */ 	slti	$at,$v0,0xff
/*  f0a5640:	1020000f */ 	beqz	$at,.NB0f0a5680
/*  f0a5644:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0a5648:	44825000 */ 	mtc1	$v0,$f10
/*  f0a564c:	3c017f1a */ 	lui	$at,0x7f1a
/*  f0a5650:	c4326dd8 */ 	lwc1	$f18,0x6dd8($at)
/*  f0a5654:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0a5658:	8fa40138 */ 	lw	$a0,0x138($sp)
/*  f0a565c:	240e0005 */ 	addiu	$t6,$zero,0x5
/*  f0a5660:	afae0134 */ 	sw	$t6,0x134($sp)
/*  f0a5664:	afa4013c */ 	sw	$a0,0x13c($sp)
/*  f0a5668:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0a566c:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0a5670:	44033000 */ 	mfc1	$v1,$f6
/*  f0a5674:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5678:	24750041 */ 	addiu	$s5,$v1,0x41
/*  f0a567c:	afb50138 */ 	sw	$s5,0x138($sp)
.NB0f0a5680:
/*  f0a5680:	0c005dbc */ 	jal	mtx00016760
/*  f0a5684:	afac0108 */ 	sw	$t4,0x108($sp)
/*  f0a5688:	8e020218 */ 	lw	$v0,0x218($s0)
/*  f0a568c:	5040000f */ 	beqzl	$v0,.NB0f0a56cc
/*  f0a5690:	8fa400e4 */ 	lw	$a0,0xe4($sp)
/*  f0a5694:	8c450018 */ 	lw	$a1,0x18($v0)
/*  f0a5698:	27a40104 */ 	addiu	$a0,$sp,0x104
/*  f0a569c:	0c008be3 */ 	jal	modelRender
/*  f0a56a0:	afa50090 */ 	sw	$a1,0x90($sp)
/*  f0a56a4:	8fa60090 */ 	lw	$a2,0x90($sp)
/*  f0a56a8:	8cc80008 */ 	lw	$t0,0x8($a2)
/*  f0a56ac:	8cc4000c */ 	lw	$a0,0xc($a2)
/*  f0a56b0:	0fc303f0 */ 	jal	func0f0c33f0
/*  f0a56b4:	8505000e */ 	lh	$a1,0xe($t0)
/*  f0a56b8:	8e0a021c */ 	lw	$t2,0x21c($s0)
/*  f0a56bc:	51400003 */ 	beqzl	$t2,.NB0f0a56cc
/*  f0a56c0:	8fa400e4 */ 	lw	$a0,0xe4($sp)
/*  f0a56c4:	ae000218 */ 	sw	$zero,0x218($s0)
/*  f0a56c8:	8fa400e4 */ 	lw	$a0,0xe4($sp)
.NB0f0a56cc:
/*  f0a56cc:	0fc2bd48 */ 	jal	weaponHasFlag
/*  f0a56d0:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f0a56d4:	1040000e */ 	beqz	$v0,.NB0f0a5710
/*  f0a56d8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f0a56dc:	8fab0110 */ 	lw	$t3,0x110($sp)
/*  f0a56e0:	3c18b600 */ 	lui	$t8,0xb600
/*  f0a56e4:	24193000 */ 	addiu	$t9,$zero,0x3000
/*  f0a56e8:	256d0008 */ 	addiu	$t5,$t3,0x8
/*  f0a56ec:	afad0110 */ 	sw	$t5,0x110($sp)
/*  f0a56f0:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f0a56f4:	16800004 */ 	bnez	$s4,.NB0f0a5708
/*  f0a56f8:	ad780000 */ 	sw	$t8,0x0($t3)
/*  f0a56fc:	240f0003 */ 	addiu	$t7,$zero,0x3
/*  f0a5700:	10000003 */ 	beqz	$zero,.NB0f0a5710
/*  f0a5704:	afaf0140 */ 	sw	$t7,0x140($sp)
.NB0f0a5708:
/*  f0a5708:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f0a570c:	afa90140 */ 	sw	$t1,0x140($sp)
.NB0f0a5710:
/*  f0a5710:	8e2e006c */ 	lw	$t6,0x6c($s1)
/*  f0a5714:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a5718:	00002025 */ 	or	$a0,$zero,$zero
/*  f0a571c:	11c00003 */ 	beqz	$t6,.NB0f0a572c
/*  f0a5720:	00001025 */ 	or	$v0,$zero,$zero
/*  f0a5724:	10000001 */ 	beqz	$zero,.NB0f0a572c
/*  f0a5728:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f0a572c:
/*  f0a572c:	8e2c0068 */ 	lw	$t4,0x68($s1)
/*  f0a5730:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a5734:	11800003 */ 	beqz	$t4,.NB0f0a5744
/*  f0a5738:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a573c:	10000001 */ 	beqz	$zero,.NB0f0a5744
/*  f0a5740:	24040001 */ 	addiu	$a0,$zero,0x1
.NB0f0a5744:
/*  f0a5744:	8e280064 */ 	lw	$t0,0x64($s1)
/*  f0a5748:	11000003 */ 	beqz	$t0,.NB0f0a5758
/*  f0a574c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5750:	10000001 */ 	beqz	$zero,.NB0f0a5758
/*  f0a5754:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f0a5758:
/*  f0a5758:	8e2a0070 */ 	lw	$t2,0x70($s1)
/*  f0a575c:	11400003 */ 	beqz	$t2,.NB0f0a576c
/*  f0a5760:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5764:	10000001 */ 	beqz	$zero,.NB0f0a576c
/*  f0a5768:	24030001 */ 	addiu	$v1,$zero,0x1
.NB0f0a576c:
/*  f0a576c:	00625821 */ 	addu	$t3,$v1,$v0
/*  f0a5770:	01646821 */ 	addu	$t5,$t3,$a0
/*  f0a5774:	01a5c021 */ 	addu	$t8,$t5,$a1
/*  f0a5778:	17010036 */ 	bne	$t8,$at,.NB0f0a5854
/*  f0a577c:	24050041 */ 	addiu	$a1,$zero,0x41
/*  f0a5780:	0c006ea3 */ 	jal	modelGetPart
/*  f0a5784:	8e04038c */ 	lw	$a0,0x38c($s0)
/*  f0a5788:	50400033 */ 	beqzl	$v0,.NB0f0a5858
/*  f0a578c:	27a40104 */ 	addiu	$a0,$sp,0x104
/*  f0a5790:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f0a5794:	00002825 */ 	or	$a1,$zero,$zero
/*  f0a5798:	84990010 */ 	lh	$t9,0x10($a0)
/*  f0a579c:	5b20002e */ 	blezl	$t9,.NB0f0a5858
/*  f0a57a0:	27a40104 */ 	addiu	$a0,$sp,0x104
/*  f0a57a4:	8e2c0034 */ 	lw	$t4,0x34($s1)
.NB0f0a57a8:
/*  f0a57a8:	8c8f000c */ 	lw	$t7,0xc($a0)
/*  f0a57ac:	00054880 */ 	sll	$t1,$a1,0x2
/*  f0a57b0:	01920019 */ 	multu	$t4,$s2
/*  f0a57b4:	01254823 */ 	subu	$t1,$t1,$a1
/*  f0a57b8:	00094880 */ 	sll	$t1,$t1,0x2
/*  f0a57bc:	01e91021 */ 	addu	$v0,$t7,$t1
/*  f0a57c0:	844e000a */ 	lh	$t6,0xa($v0)
/*  f0a57c4:	00056880 */ 	sll	$t5,$a1,0x2
/*  f0a57c8:	01a56823 */ 	subu	$t5,$t5,$a1
/*  f0a57cc:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f0a57d0:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0a57d4:	00004012 */ 	mflo	$t0
/*  f0a57d8:	01c85023 */ 	subu	$t2,$t6,$t0
/*  f0a57dc:	a44a0008 */ 	sh	$t2,0x8($v0)
/*  f0a57e0:	8c8b000c */ 	lw	$t3,0xc($a0)
/*  f0a57e4:	016dc021 */ 	addu	$t8,$t3,$t5
/*  f0a57e8:	8719000a */ 	lh	$t9,0xa($t8)
/*  f0a57ec:	2b21a000 */ 	slti	$at,$t9,-24576
/*  f0a57f0:	50200014 */ 	beqzl	$at,.NB0f0a5844
/*  f0a57f4:	848b0010 */ 	lh	$t3,0x10($a0)
/*  f0a57f8:	848f0010 */ 	lh	$t7,0x10($a0)
/*  f0a57fc:	00001825 */ 	or	$v1,$zero,$zero
/*  f0a5800:	59e00010 */ 	blezl	$t7,.NB0f0a5844
/*  f0a5804:	848b0010 */ 	lh	$t3,0x10($a0)
/*  f0a5808:	8c89000c */ 	lw	$t1,0xc($a0)
.NB0f0a580c:
/*  f0a580c:	00036080 */ 	sll	$t4,$v1,0x2
/*  f0a5810:	01836023 */ 	subu	$t4,$t4,$v1
/*  f0a5814:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f0a5818:	012c1021 */ 	addu	$v0,$t1,$t4
/*  f0a581c:	844e000a */ 	lh	$t6,0xa($v0)
/*  f0a5820:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f0a5824:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f0a5828:	25c82000 */ 	addiu	$t0,$t6,0x2000
/*  f0a582c:	a4480008 */ 	sh	$t0,0x8($v0)
/*  f0a5830:	848a0010 */ 	lh	$t2,0x10($a0)
/*  f0a5834:	006a082a */ 	slt	$at,$v1,$t2
/*  f0a5838:	5420fff4 */ 	bnezl	$at,.NB0f0a580c
/*  f0a583c:	8c89000c */ 	lw	$t1,0xc($a0)
/*  f0a5840:	848b0010 */ 	lh	$t3,0x10($a0)
.NB0f0a5844:
/*  f0a5844:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f0a5848:	00ab082a */ 	slt	$at,$a1,$t3
/*  f0a584c:	5420ffd6 */ 	bnezl	$at,.NB0f0a57a8
/*  f0a5850:	8e2c0034 */ 	lw	$t4,0x34($s1)
.NB0f0a5854:
/*  f0a5854:	27a40104 */ 	addiu	$a0,$sp,0x104
.NB0f0a5858:
/*  f0a5858:	0c008be3 */ 	jal	modelRender
/*  f0a585c:	8fa50038 */ 	lw	$a1,0x38($sp)
/*  f0a5860:	8e6d1594 */ 	lw	$t5,0x1594($s3)
/*  f0a5864:	3c188007 */ 	lui	$t8,0x8007
/*  f0a5868:	51a00013 */ 	beqzl	$t5,.NB0f0a58b8
/*  f0a586c:	8fa90110 */ 	lw	$t1,0x110($sp)
/*  f0a5870:	8f18299c */ 	lw	$t8,0x299c($t8)
/*  f0a5874:	8fb90138 */ 	lw	$t9,0x138($sp)
/*  f0a5878:	5300000f */ 	beqzl	$t8,.NB0f0a58b8
/*  f0a587c:	8fa90110 */ 	lw	$t1,0x110($sp)
/*  f0a5880:	afb90078 */ 	sw	$t9,0x78($sp)
/*  f0a5884:	8e0f0390 */ 	lw	$t7,0x390($s0)
/*  f0a5888:	26050534 */ 	addiu	$a1,$s0,0x534
/*  f0a588c:	00a02025 */ 	or	$a0,$a1,$zero
/*  f0a5890:	ae0f0540 */ 	sw	$t7,0x540($s0)
/*  f0a5894:	0c007728 */ 	jal	model0001cc20
/*  f0a5898:	afa50050 */ 	sw	$a1,0x50($sp)
/*  f0a589c:	8fa50050 */ 	lw	$a1,0x50($sp)
/*  f0a58a0:	afb50138 */ 	sw	$s5,0x138($sp)
/*  f0a58a4:	0c008be3 */ 	jal	modelRender
/*  f0a58a8:	27a40104 */ 	addiu	$a0,$sp,0x104
/*  f0a58ac:	8fa40078 */ 	lw	$a0,0x78($sp)
/*  f0a58b0:	afa40138 */ 	sw	$a0,0x138($sp)
/*  f0a58b4:	8fa90110 */ 	lw	$t1,0x110($sp)
.NB0f0a58b8:
/*  f0a58b8:	8fa400e4 */ 	lw	$a0,0xe4($sp)
/*  f0a58bc:	24050020 */ 	addiu	$a1,$zero,0x20
/*  f0a58c0:	0fc2bd48 */ 	jal	weaponHasFlag
/*  f0a58c4:	afa90144 */ 	sw	$t1,0x144($sp)
/*  f0a58c8:	10400007 */ 	beqz	$v0,.NB0f0a58e8
/*  f0a58cc:	8fac0144 */ 	lw	$t4,0x144($sp)
/*  f0a58d0:	258e0008 */ 	addiu	$t6,$t4,0x8
/*  f0a58d4:	afae0144 */ 	sw	$t6,0x144($sp)
/*  f0a58d8:	3c08b600 */ 	lui	$t0,0xb600
/*  f0a58dc:	240a3000 */ 	addiu	$t2,$zero,0x3000
/*  f0a58e0:	ad8a0004 */ 	sw	$t2,0x4($t4)
/*  f0a58e4:	ad880000 */ 	sw	$t0,0x0($t4)
.NB0f0a58e8:
/*  f0a58e8:	8e0b038c */ 	lw	$t3,0x38c($s0)
/*  f0a58ec:	8e040390 */ 	lw	$a0,0x390($s0)
/*  f0a58f0:	0fc303f0 */ 	jal	func0f0c33f0
/*  f0a58f4:	8565000e */ 	lh	$a1,0xe($t3)
/*  f0a58f8:	0c005dc5 */ 	jal	mtx00016784
/*  f0a58fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5900:	8fad0144 */ 	lw	$t5,0x144($sp)
/*  f0a5904:	3c19bc00 */ 	lui	$t9,0xbc00
/*  f0a5908:	3739000e */ 	ori	$t9,$t9,0xe
/*  f0a590c:	25b80008 */ 	addiu	$t8,$t5,0x8
/*  f0a5910:	afb80144 */ 	sw	$t8,0x144($sp)
/*  f0a5914:	adb90000 */ 	sw	$t9,0x0($t5)
/*  f0a5918:	0c002b3b */ 	jal	viGetPerspScale
/*  f0a591c:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f0a5920:	8fa30070 */ 	lw	$v1,0x70($sp)
/*  f0a5924:	ac620004 */ 	sw	$v0,0x4($v1)
.NB0f0a5928:
/*  f0a5928:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f0a592c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f0a5930:	1681fe0c */ 	bne	$s4,$at,.NB0f0a5164
/*  f0a5934:	261007a4 */ 	addiu	$s0,$s0,0x7a4
/*  f0a5938:	afb500dc */ 	sw	$s5,0xdc($sp)
/*  f0a593c:	0fc2b250 */ 	jal	casingsRender
/*  f0a5940:	27a40144 */ 	addiu	$a0,$sp,0x144
/*  f0a5944:	0fc5c3ce */ 	jal	mblur0f176298
/*  f0a5948:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a594c:	0fc5c3d3 */ 	jal	mblur0f1762ac
/*  f0a5950:	8fa40144 */ 	lw	$a0,0x144($sp)
/*  f0a5954:	afa20144 */ 	sw	$v0,0x144($sp)
/*  f0a5958:	0c002cd4 */ 	jal	vi0000b1d0
/*  f0a595c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0a5960:	244f0008 */ 	addiu	$t7,$v0,0x8
/*  f0a5964:	afaf0144 */ 	sw	$t7,0x144($sp)
/*  f0a5968:	0c002fb5 */ 	jal	viGetViewLeft
/*  f0a596c:	00408825 */ 	or	$s1,$v0,$zero
/*  f0a5970:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a5974:	00104c03 */ 	sra	$t1,$s0,0x10
/*  f0a5978:	0c002fb9 */ 	jal	viGetViewTop
/*  f0a597c:	01208025 */ 	or	$s0,$t1,$zero
/*  f0a5980:	44824000 */ 	mtc1	$v0,$f8
/*  f0a5984:	44902000 */ 	mtc1	$s0,$f4
/*  f0a5988:	3c014080 */ 	lui	$at,0x4080
/*  f0a598c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0a5990:	44810000 */ 	mtc1	$at,$f0
/*  f0a5994:	3c01ed00 */ 	lui	$at,0xed00
/*  f0a5998:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0a599c:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f0a59a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a59a4:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f0a59a8:	4600848d */ 	trunc.w.s	$f18,$f16
/*  f0a59ac:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f0a59b0:	440e9000 */ 	mfc1	$t6,$f18
/*  f0a59b4:	440d5000 */ 	mfc1	$t5,$f10
/*  f0a59b8:	31c80fff */ 	andi	$t0,$t6,0xfff
/*  f0a59bc:	01015025 */ 	or	$t2,$t0,$at
/*  f0a59c0:	31b80fff */ 	andi	$t8,$t5,0xfff
/*  f0a59c4:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f0a59c8:	01597825 */ 	or	$t7,$t2,$t9
/*  f0a59cc:	0c002f97 */ 	jal	viGetViewWidth
/*  f0a59d0:	ae2f0000 */ 	sw	$t7,0x0($s1)
/*  f0a59d4:	00029400 */ 	sll	$s2,$v0,0x10
/*  f0a59d8:	00124c03 */ 	sra	$t1,$s2,0x10
/*  f0a59dc:	0c002fb5 */ 	jal	viGetViewLeft
/*  f0a59e0:	01209025 */ 	or	$s2,$t1,$zero
/*  f0a59e4:	0002a400 */ 	sll	$s4,$v0,0x10
/*  f0a59e8:	00146403 */ 	sra	$t4,$s4,0x10
/*  f0a59ec:	0c002fb9 */ 	jal	viGetViewTop
/*  f0a59f0:	0180a025 */ 	or	$s4,$t4,$zero
/*  f0a59f4:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0a59f8:	00107403 */ 	sra	$t6,$s0,0x10
/*  f0a59fc:	0c002f9b */ 	jal	viGetViewHeight
/*  f0a5a00:	01c08025 */ 	or	$s0,$t6,$zero
/*  f0a5a04:	00504021 */ 	addu	$t0,$v0,$s0
/*  f0a5a08:	44888000 */ 	mtc1	$t0,$f16
/*  f0a5a0c:	02925021 */ 	addu	$t2,$s4,$s2
/*  f0a5a10:	448a5000 */ 	mtc1	$t2,$f10
/*  f0a5a14:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f0a5a18:	3c014080 */ 	lui	$at,0x4080
/*  f0a5a1c:	44812000 */ 	mtc1	$at,$f4
/*  f0a5a20:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0a5a24:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f0a5a28:	44819000 */ 	mtc1	$at,$f18
/*  f0a5a2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f0a5a30:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f0a5a34:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0a5a38:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0a5a3c:	440d4000 */ 	mfc1	$t5,$f8
/*  f0a5a40:	440f3000 */ 	mfc1	$t7,$f6
/*  f0a5a44:	31b80fff */ 	andi	$t8,$t5,0xfff
/*  f0a5a48:	31e90fff */ 	andi	$t1,$t7,0xfff
/*  f0a5a4c:	00096300 */ 	sll	$t4,$t1,0xc
/*  f0a5a50:	030c7025 */ 	or	$t6,$t8,$t4
/*  f0a5a54:	ae2e0004 */ 	sw	$t6,0x4($s1)
/*  f0a5a58:	8fab0148 */ 	lw	$t3,0x148($sp)
/*  f0a5a5c:	8fa80144 */ 	lw	$t0,0x144($sp)
/*  f0a5a60:	ad680000 */ 	sw	$t0,0x0($t3)
/*  f0a5a64:	8fbf0034 */ 	lw	$ra,0x34($sp)
.NB0f0a5a68:
/*  f0a5a68:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f0a5a6c:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f0a5a70:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f0a5a74:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f0a5a78:	8fb4002c */ 	lw	$s4,0x2c($sp)
/*  f0a5a7c:	8fb50030 */ 	lw	$s5,0x30($sp)
/*  f0a5a80:	03e00008 */ 	jr	$ra
/*  f0a5a84:	27bd0148 */ 	addiu	$sp,$sp,0x148
);
#endif
#else
// Mismatch: Goal uses different codegen for accessing vertices
void bgunRender(Gfx **gdlptr)
{
	Gfx *gdl = *gdlptr;
	struct modelrenderdata renderdata = {NULL, true, 3}; // 10c
	struct player *player;
	s32 i;

	static bool renderhand = true; // var800702dc

	player = g_Vars.currentplayer;

	if (player->visionmode == VISIONMODE_XRAY) {
		for (i = 0; i < 2; i++) {
			if (g_Vars.currentplayer->hands[i].firedrocket) {
				g_Vars.currentplayer->hands[i].rocket = NULL;
			}
		}
		return;
	}

	gdl = mblurRender(gdl);
	gdl = vi0000b280(gdl);
	gdl = vi0000b1d0(gdl);

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, viGetViewLeft(), viGetViewTop(),
			viGetViewLeft() + viGetViewWidth(), viGetViewTop() + viGetViewHeight());

	gdl = vi0000aca4(gdl, 1.5, 1000);

	if (g_Vars.currentplayer->teleportstate != TELEPORTSTATE_INACTIVE) {
		f32 f2;

		if (optionsGetScreenRatio() == SCREENRATIO_16_9) {
			f2 = player0f0bd358() * 1.3333334f;
		} else {
			f2 = player0f0bd358();
		}

		gdl = vi0000b0e8(gdl, 60, f2);
	}

	if (PLAYERCOUNT() == 1 && IS8MB()) {
		gdl = lasersightRenderBeam(gdl);
	}

	for (i = 0; i < 2; i++) {
		struct hand *hand;
		s32 j;
		s32 alpha;
		s32 weaponnum; // ec
		struct modelnode *node; // e8
		u32 colour; // e4

		hand = player->hands + i;

		weaponnum = bgunGetWeaponNum2(i);

		if (hand->visible) {
			gdl = beamRender(gdl, &hand->beam, 0, 0);

			if (weaponHasFlag(hand->gset.weaponnum, WEAPONFLAG_00008000)) {
				gSPNumLights(gdl++, 1);
				gSPLight(gdl++, &var80070098, 1);
				gSPLight(gdl++, &var80070090, 2);
				gSPLookAt(gdl++, camGetLookAt());
			}

			gSPPerspNormalize(gdl++, mtx00016dcc(0, 300));

			// There is support for guns having a TV screen on them
			// but no guns have this model part so it's not used.
			node = modelGetPart(hand->gunmodel.filedata, MODELPART_0010);

			if (node) {
				union modelrwdata *rwdata = modelGetNodeRwData(&hand->gunmodel, modelGetPart(hand->gunmodel.filedata, MODELPART_0011));

				if (rwdata) {
					rwdata->toggle.visible = true;
				}

				gdl = tvscreenRender(&hand->gunmodel, node, &var8009cf88, gdl, 0, 1);
			}

			renderdata.gdl = gdl;
			renderdata.unk30 = 4;

			if (USINGDEVICE(DEVICE_NIGHTVISION) || USINGDEVICE(DEVICE_IRSCANNER)) {
				// 67c
				u8 *col = player->gunshadecol;
				u32 shade;
				s32 spb0[4];
				s32 spa0[4];

				if (col[0] > col[1] && col[0] > col[2]) {
					shade = col[0];
				} else if (col[1] > col[2]) {
					shade = col[1];
				} else {
					shade = col[2];
				}

				renderdata.envcolour = (shade << 24 | shade << 16 | shade << 8) + col[3];

				if (USINGDEVICE(DEVICE_NIGHTVISION)) {
					spb0[0] = var8009caef;
					spb0[1] = var8009caef;
					spb0[2] = var8009caef;
					spb0[3] = var8009caf0;

					colour = (spb0[0] << 24 | spb0[1] << 16 | spb0[2] << 8) + spb0[3];
				} else if (USINGDEVICE(DEVICE_IRSCANNER)) {
					spa0[0] = 0xff;
					spa0[1] = 0;
					spa0[2] = 0;
					spa0[3] = 0x80;

					colour = (spa0[0] << 24 | spa0[1] << 16 | spa0[2] << 8) + spa0[3];
				}

				if (weaponnum == WEAPON_UNARMED) {
					renderdata.envcolour = colour;
				}
			} else {
				renderdata.envcolour = player->gunshadecol[0] << 24 | player->gunshadecol[1] << 16 | player->gunshadecol[2] << 8 | player->gunshadecol[3];
				colour = renderdata.envcolour;

				// 838
				if (hand->gset.weaponnum == WEAPON_MAULER) {
					u32 weight = hand->matmot1 * 50.0f;
					renderdata.envcolour = colourBlend(0xff00007f, renderdata.envcolour, weight);
				}
			}

			// Apply transparency based on player's cloak
			alpha = chrGetCloakAlpha(player->prop->chr);

			if (alpha < 255) {
				colour = (s32) (alpha * 0.74509805f) + 0x41;
				renderdata.unk30 = 5;
				renderdata.fogcolour = renderdata.envcolour;
				renderdata.envcolour = colour;
			}

			renderdata.zbufferenabled = true;

			mtx00016760();

			// Render rocket launcher's rocket if it's in Jo's hand or in the launcher
			if (hand->rocket) {
				struct model *rocketmodel = hand->rocket->base.model; // 98
				bool sp94 = false;

#if VERSION >= VERSION_NTSC_1_0
				if (rocketmodel && rocketmodel->filedata) {
					sp94 = true;

					modelRender(&renderdata, rocketmodel);

					func0f0c33f0(rocketmodel->matrices, rocketmodel->filedata->nummatrices);

					if (hand->firedrocket) {
						hand->rocket = NULL;
					}
				}

				if (sp94);
#else
				modelRender(&renderdata, rocketmodel);

				func0f0c33f0(rocketmodel->matrices, rocketmodel->filedata->nummatrices);

				if (hand->firedrocket) {
					hand->rocket = NULL;
				}
#endif
			}

			if (weaponHasFlag(weaponnum, WEAPONFLAG_DUALFLIP)) {
				gSPClearGeometryMode(renderdata.gdl++, G_CULL_BOTH);

				if (i == HAND_RIGHT) {
					renderdata.cullmode = CULLMODE_BACK;
				} else {
					renderdata.cullmode = CULLMODE_FRONT;
				}
			}

			// Slide the laser's liquid texture
			if (PLAYERCOUNT() == 1) {
				node = modelGetPart(hand->gunmodel.filedata, MODELPART_LASER_0041);

				// a5c
				if (node) {
					struct modelrodata_gundl *rodata;
					rodata = &node->rodata->gundl;

					for (j = 0; j < rodata->numvertices; j++) {
						// a7c
						s32 stack[2];
						s32 k;

						(rodata->vertices + j)->t -= g_Vars.lvupdate240 * PALUP(25);

						if ((rodata->vertices + j)->t < -0x6000) {
							for (k = 0; k < rodata->numvertices; k++) {
								(rodata->vertices + k)->t += 0x2000;
							}
						}
					}
				}
			}

			// Render the gun
			modelRender(&renderdata, &hand->gunmodel);

			// Render the hand
			if (player->gunctrl.handmodeldef && renderhand) {
				s32 prevcolour = renderdata.envcolour; // 7c

				hand->handmodel.matrices = hand->gunmodel.matrices;

				model0001cc20(&hand->handmodel);

				renderdata.envcolour = colour;
				modelRender(&renderdata, &hand->handmodel);
				renderdata.envcolour = prevcolour;
			}

			// Clean up
			gdl = renderdata.gdl;

			if (weaponHasFlag(weaponnum, WEAPONFLAG_DUALFLIP)) {
				gSPClearGeometryMode(gdl++, G_CULL_BOTH);
			}

			func0f0c33f0(hand->gunmodel.matrices, hand->gunmodel.filedata->nummatrices);
			mtx00016784();

			gSPPerspNormalize(gdl++, viGetPerspScale());
		}
	}

	casingsRender(&gdl);
	mblur0f176298();

	gdl = mblur0f1762ac(gdl);
	gdl = vi0000b1d0(gdl);

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, viGetViewLeft(), viGetViewTop(),
			viGetViewLeft() + viGetViewWidth(), viGetViewTop() + viGetViewHeight());

	*gdlptr = gdl;
}
#endif

/**
 * Find and return an available audio handle out of a pool of four.
 */
struct sndstate **bgunAllocateAudioHandle(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_BgunAudioHandles); i++) {
		if (g_BgunAudioHandles[i] == NULL) {
			return &g_BgunAudioHandles[i];
		}
	}

	return NULL;
}

void bgunPlayPropHitSound(struct gset *gset, struct prop *prop, s32 texturenum)
{
#if VERSION >= VERSION_NTSC_1_0
	u32 rand1 = random();
	u32 rand2 = random();
	struct sndstate **handle;

	if (g_Vars.lvupdate240 <= 0) {
		return;
	}

	if (texturenum >= 0 && texturenum < NUM_TEXTURES
			&& g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds == 0) {
		return;
	}

	if (gset->weaponnum == WEAPON_REMOTEMINE
			|| gset->weaponnum == WEAPON_PROXIMITYMINE
			|| gset->weaponnum == WEAPON_TIMEDMINE
			|| gset->weaponnum == WEAPON_COMMSRIDER
			|| gset->weaponnum == WEAPON_TRACERBUG
			|| gset->weaponnum == WEAPON_TARGETAMPLIFIER
			|| gset->weaponnum == WEAPON_ECMMINE) {
		propsnd0f0939f8(NULL, prop, SFX_80AA, -1, -1, 0, 0, 0, NULL, -1, NULL, -1, -1, -1, -1);
		return;
	}

	handle = bgunAllocateAudioHandle();

	if (handle) {
		if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
			struct chrdata *chr = prop->chr;
			s16 soundnum = -1;
			bool overridden = false;
			s32 spac;
			s32 spa8;

			if (chrGetShield(chr) > 0) {
				soundnum = SFX_SHIELD_DAMAGE;
			} else if (gset->weaponnum == WEAPON_COMBATKNIFE
					|| gset->weaponnum == WEAPON_COMBATKNIFE // duplicate
					|| gset->weaponnum == WEAPON_BOLT) {
				soundnum = SFX_05F6;
				overridden = true;
			} else if (gset->weaponnum == WEAPON_UNARMED
					|| (gset->weaponfunc == FUNC_SECONDARY
						&& (gset->weaponnum == WEAPON_FALCON2
							|| gset->weaponnum == WEAPON_FALCON2_SILENCER
							|| gset->weaponnum == WEAPON_FALCON2_SCOPE
							|| gset->weaponnum == WEAPON_DY357MAGNUM
							|| gset->weaponnum == WEAPON_DY357LX))) {
				s16 sounds[] = { SFX_002F, SFX_0030, SFX_0031 };
				soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
			} else {
				s16 sounds[] = { SFX_HIT_CHR, SFX_HIT_CHR };
				soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
			}

			if (soundnum != -1) {
				propsnd0f094ef4(&prop->pos, prop->rooms, soundnum, &spac, &spa8);

				if (spac) {
					sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);

					if (*handle) {
						sndAdjust(handle, 0, spac, spa8, soundnum, 1, 1, -1, 1);
					}
				}
			}

			if (overridden) {
				return;
			}
		} else {
			s16 soundnum = -1;
			bool overridden = false;
			s32 sp90;
			s32 sp8c;
			u32 stack;

			if (texturenum == 10000) {
				soundnum = SFX_SHIELD_DAMAGE;
			} else if (gset->weaponnum == WEAPON_LASER) {
				if (gset->weaponfunc == FUNC_PRIMARY || ((gset->unk063a % 4) == 0 && (random() % 2))) {
					if ((random() % 2) == 0) {
						soundnum = SFX_CLOAK_ON;
					} else {
						soundnum = SFX_CLOAK_OFF;
					}
				}

				overridden = true;
			} else {
				if (gset->weaponnum == WEAPON_COMBATKNIFE || gset->weaponnum == WEAPON_BOLT) {
					soundnum = SFX_HIT_METAL_8079;
					overridden = true;
				} else {
					s16 sounds[] = {
						SFX_001B, SFX_001C, SFX_001D, SFX_001E,
						SFX_001B, SFX_001C, SFX_001D, SFX_001E,
						SFX_001B, SFX_001C, SFX_001D, SFX_001E,
						SFX_0023, SFX_0024, SFX_0025, SFX_0026,
						SFX_0027, SFX_0028, SFX_0029, SFX_002A,
					};

					soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
				}
			}

			if (soundnum != -1) {
				propsnd0f094ef4(&prop->pos, prop->rooms, soundnum, &sp90, &sp8c);

				if (sp90) {
					sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);

					if (*handle) {
						sndAdjust(handle, 0, sp90, sp8c, soundnum, 1, 1, -1, 1);
					}
				}
			}

			if (overridden) {
				return;
			}
		}
	}

	if (texturenum >= 0 && texturenum < NUM_TEXTURES && g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]) {
		s16 soundnum = -1;

		handle = bgunAllocateAudioHandle();

		if (handle) {
			if (g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds > 0) {
				s32 index = rand2 % g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds;
				soundnum = g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->sounds[index];

				if (soundnum != -1) {
					sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
				}
			}

			if (*handle && soundnum != -1) {
				func0f09505c(*handle, &prop->pos, 400, 2500, 3000, prop->rooms, soundnum, 0x7fff, 0);
			}
		}
	}
#else
	u32 rand1 = random();
	u32 rand2 = random();
	struct sndstate **handle;

	if (g_Vars.lvupdate240 <= 0) {
		return;
	}

	if (texturenum >= 0 && texturenum < NUM_TEXTURES
			&& g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds == 0) {
		return;
	}

	if (gset->weaponnum == WEAPON_REMOTEMINE
			|| gset->weaponnum == WEAPON_PROXIMITYMINE
			|| gset->weaponnum == WEAPON_TIMEDMINE
			|| gset->weaponnum == WEAPON_COMMSRIDER
			|| gset->weaponnum == WEAPON_TRACERBUG
			|| gset->weaponnum == WEAPON_TARGETAMPLIFIER
			|| gset->weaponnum == WEAPON_ECMMINE) {
		propsnd0f0939f8(NULL, prop, SFX_80AA, -1, -1, 0, 0, 0, NULL, -1, NULL, -1, -1, -1, -1);
		return;
	}

	handle = bgunAllocateAudioHandle();

	if (handle) {
		if (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER) {
			struct chrdata *chr = prop->chr;
			s16 soundnum;
			bool overridden = false;

			if (chrGetShield(chr) > 0) {
				sndStart(var80095200, SFX_SHIELD_DAMAGE, handle, -1, -1, -1, -1, -1);
				soundnum = SFX_SHIELD_DAMAGE;
			} else if (gset->weaponnum == WEAPON_COMBATKNIFE
					|| gset->weaponnum == WEAPON_COMBATKNIFE // duplicate
					|| gset->weaponnum == WEAPON_BOLT) {
				sndStart(var80095200, SFX_05F6, handle, -1, -1, -1, -1, -1);
				soundnum = SFX_05F6;
				overridden = true;
			} else if (gset->weaponnum == WEAPON_UNARMED
					|| (gset->weaponfunc == FUNC_SECONDARY
						&& (gset->weaponnum == WEAPON_FALCON2
							|| gset->weaponnum == WEAPON_FALCON2_SILENCER
							|| gset->weaponnum == WEAPON_FALCON2_SCOPE
							|| gset->weaponnum == WEAPON_DY357MAGNUM
							|| gset->weaponnum == WEAPON_DY357LX))) {
				s16 sounds[] = { SFX_002F, SFX_0030, SFX_0031 };
				soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
				sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			} else {
				s16 sounds[] = { SFX_HIT_CHR, SFX_HIT_CHR };
				soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
				sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			}

			if (*handle) {
				func0f09505c(*handle, &prop->pos, 400, 2500, 3000, prop->rooms, soundnum, 0x7fff, 0);
			}

			if (overridden) {
				return;
			}
		} else {
			s16 soundnum;
			bool overridden = false;
			u32 stack;

			if (texturenum == 10000) {
				sndStart(var80095200, SFX_SHIELD_DAMAGE, handle, -1, -1, -1, -1, -1);
				soundnum = SFX_SHIELD_DAMAGE;
			} else if (gset->weaponnum == WEAPON_LASER) {
				if (gset->weaponfunc == FUNC_PRIMARY || (gset->unk063a % 8) == 0) {
					if ((random() % 2) == 0) {
						soundnum = SFX_CLOAK_ON;
					} else {
						soundnum = SFX_CLOAK_OFF;
					}

					sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
					overridden = true;
				}
			} else {
				if (gset->weaponnum == WEAPON_COMBATKNIFE || gset->weaponnum == WEAPON_BOLT) {
					soundnum = SFX_HIT_METAL_8079;
					sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
					overridden = true;
				} else {
					s16 sounds[] = {
						SFX_001B, SFX_001C, SFX_001D, SFX_001E,
						SFX_001B, SFX_001C, SFX_001D, SFX_001E,
						SFX_001B, SFX_001C, SFX_001D, SFX_001E,
						SFX_0023, SFX_0024, SFX_0025, SFX_0026,
						SFX_0027, SFX_0028, SFX_0029, SFX_002A,
					};

					soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
					sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
				}
			}

			if (*handle) {
				func0f09505c(*handle, &prop->pos, 400, 2500, 3000, prop->rooms, soundnum, 0x7fff, 0);
			}

			if (overridden) {
				return;
			}
		}
	}

	if (texturenum >= 0 && texturenum < NUM_TEXTURES && g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]) {
		s16 soundnum = -1;

		handle = bgunAllocateAudioHandle();

		if (handle) {
			if (g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds > 0) {
				s32 index = rand2 % g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds;
				soundnum = g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->sounds[index];

				sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			}

			if (*handle) {
				func0f09505c(*handle, &prop->pos, 400, 2500, 3000, prop->rooms, soundnum, 0x7fff, 0);
			}
		}
	}
#endif
}

void bgunPlayGlassHitSound(struct coord *pos, s16 *rooms, s32 texturenum)
{
	if (g_Vars.lvupdate240 > 0) {
		struct sndstate **handle = bgunAllocateAudioHandle();

		if (handle) {
			sndStart(var80095200, SFX_HIT_GLASS, handle, -1, -1, -1, -1, -1);

			if (*handle) {
				func0f09505c(*handle, pos, 400, 2500, 3000, rooms, SFX_HIT_GLASS, 0x7fff, 0);
			}
		}
	}
}

void bgunPlayBgHitSound(struct gset *gset, struct coord *arg1, s32 texturenum, s16 *arg3)
{
#if VERSION >= VERSION_NTSC_1_0
	struct sndstate **handle;
	u32 rand1 = random();
	u32 rand2 = random();
	bool playdefault;
	s16 soundnum;
	bool overridden;

	if (g_Vars.lvupdate240 <= 0) {
		return;
	}

	if (texturenum >= 0 && texturenum < NUM_TEXTURES && g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds == 0) {
		return;
	}

	playdefault = true;
	handle = bgunAllocateAudioHandle();

	if (handle) {
		soundnum = -1;
		overridden = false;

		if (gset->weaponnum == WEAPON_LASER) {
			playdefault = false;

			if (gset->weaponfunc == FUNC_PRIMARY || ((gset->unk063a % 4) == 0 && (random() % 2))) {
				// Laser sounds
				s16 sounds[] = {SFX_CLOAK_ON, SFX_CLOAK_OFF};
				soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
				sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
				overridden = true;
			}
		} else if (gset->weaponnum == WEAPON_COMBATKNIFE || gset->weaponnum == WEAPON_BOLT) {
			// Knives and bolts make a metal sound
			soundnum = SFX_HIT_METAL_8079;
			sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			overridden = true;
		} else if (gset->weaponnum == WEAPON_REMOTEMINE
				|| gset->weaponnum == WEAPON_PROXIMITYMINE
				|| gset->weaponnum == WEAPON_TIMEDMINE
				|| gset->weaponnum == WEAPON_COMMSRIDER
				|| gset->weaponnum == WEAPON_TRACERBUG
				|| gset->weaponnum == WEAPON_TARGETAMPLIFIER
				|| gset->weaponnum == WEAPON_ECMMINE) {
			// Mine landing/activation sound
			soundnum = SFX_80AA;
			sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			overridden = true;
		} else {
			// Ricochet sounds
			s16 sounds[] = {
				SFX_0013, SFX_0014, SFX_0015, SFX_0016,
				SFX_0017, SFX_0018, SFX_0019, SFX_001A,
				SFX_0017, SFX_0018, SFX_0019, SFX_001A,
				SFX_0017, SFX_0018, SFX_0019, SFX_001A,
				SFX_001F, SFX_0020, SFX_0020, SFX_0021,
				SFX_001F, SFX_0020, SFX_0020, SFX_0021,
				SFX_001F, SFX_0020, SFX_0020, SFX_0021,
				SFX_0023, SFX_0024, SFX_0025, SFX_0026,
				SFX_0027, SFX_0028, SFX_0029, SFX_002A,
			};

			soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
			sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			overridden = false;
		}

		if (*handle != NULL) {
			func0f09505c(*handle, arg1, 400, 2500, 3000, arg3, soundnum, 0x7fff, 0);
		}

		if (overridden) {
			return;
		}
	}

	if (playdefault) {
		handle = bgunAllocateAudioHandle();

		if (handle != NULL && texturenum >= 0 && texturenum < NUM_TEXTURES) {
			s16 soundnum;
			struct surfacetype *type = g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype];

			if (type->numsounds > 0) {
				soundnum = -1;

				if (type != NULL) {
					s32 index = rand2 % type->numsounds;
					soundnum = type->sounds[index];
					sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
				}

				if (*handle != NULL) {
					func0f09505c(*handle, arg1, 400, 2500, 3000, arg3, soundnum, 0x7fff, 0);
				}
			}
		}
	}
#else
	struct sndstate **handle;
	u32 rand1 = random();
	u32 rand2 = random();
	s16 soundnum;
	bool overridden;

	if (g_Vars.lvupdate240 <= 0) {
		return;
	}

	if (texturenum >= 0 && texturenum < NUM_TEXTURES && g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype]->numsounds == 0) {
		return;
	}

	handle = bgunAllocateAudioHandle();

	if (handle) {
		overridden = false;

		if (gset->weaponnum == WEAPON_LASER) {
			if (gset->weaponfunc == FUNC_PRIMARY || (gset->unk063a % 8) == 0) {
				// Laser sounds
				s16 sounds[] = {SFX_CLOAK_ON, SFX_CLOAK_OFF};
				soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
				sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
				overridden = true;
			}
		} else if (gset->weaponnum == WEAPON_COMBATKNIFE || gset->weaponnum == WEAPON_BOLT) {
			// Knives and bolts make a metal sound
			soundnum = SFX_HIT_METAL_8079;
			sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			overridden = true;
		} else if (gset->weaponnum == WEAPON_REMOTEMINE
				|| gset->weaponnum == WEAPON_PROXIMITYMINE
				|| gset->weaponnum == WEAPON_TIMEDMINE
				|| gset->weaponnum == WEAPON_COMMSRIDER
				|| gset->weaponnum == WEAPON_TRACERBUG
				|| gset->weaponnum == WEAPON_TARGETAMPLIFIER
				|| gset->weaponnum == WEAPON_ECMMINE) {
			// Mine landing/activation sound
			sndStart(var80095200, SFX_80AA, handle, -1, -1, -1, -1, -1);
			overridden = true;
		} else {
			// Ricochet sounds
			s16 sounds[] = {
				SFX_0013, SFX_0014, SFX_0015, SFX_0016,
				SFX_0017, SFX_0018, SFX_0019, SFX_001A,
				SFX_0017, SFX_0018, SFX_0019, SFX_001A,
				SFX_0017, SFX_0018, SFX_0019, SFX_001A,
				SFX_001F, SFX_0020, SFX_0020, SFX_0021,
				SFX_001F, SFX_0020, SFX_0020, SFX_0021,
				SFX_001F, SFX_0020, SFX_0020, SFX_0021,
				SFX_0023, SFX_0024, SFX_0025, SFX_0026,
				SFX_0027, SFX_0028, SFX_0029, SFX_002A,
			};

			soundnum = sounds[rand1 % ARRAYCOUNT(sounds)];
			sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			overridden = false;
		}

		if (*handle != NULL) {
			func0f09505c(*handle, arg1, 400, 2500, 3000, arg3, soundnum, 0x7fff, 0);
		}

		if (overridden) {
			return;
		}
	}

	// Play default surface hit sound
	handle = bgunAllocateAudioHandle();

	if (handle != NULL && texturenum >= 0 && texturenum < NUM_TEXTURES) {
		s16 soundnum;
		struct surfacetype *type = g_SurfaceTypes[g_Textures[texturenum].soundsurfacetype];

		if (type->numsounds > 0) {
			soundnum = -1;

			if (type != NULL) {
				s32 index = rand2 % type->numsounds;
				soundnum = type->sounds[index];
				sndStart(var80095200, soundnum, handle, -1, -1, -1, -1, -1);
			}

			if (*handle != NULL) {
				func0f09505c(*handle, arg1, 400, 2500, 3000, arg3, soundnum, 0x7fff, 0);
			}
		}
	}
#endif
}

void bgunSetTriggerOn(s32 handnum, bool on)
{
	struct hand *hand = &g_Vars.currentplayer->hands[handnum];

	hand->triggerprev = hand->triggeron;
	hand->triggeron = on;

	if (!on) {
		hand->triggerreleased = true;
	}
}

#define VALIDWEAPON() (g_Vars.currentplayer->gunctrl.weaponnum >= WEAPON_UNARMED && g_Vars.currentplayer->gunctrl.weaponnum <= WEAPON_COMBATBOOST)
#define GETFUNC() (VALIDWEAPON() && (g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].gunfuncs[(g_Vars.currentplayer->gunctrl.weaponnum - 1) >> 3] & (1 << ((g_Vars.currentplayer->gunctrl.weaponnum - 1) & 7))))
#define SETFUNCPRI() g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].gunfuncs[(g_Vars.currentplayer->gunctrl.weaponnum - 1) >> 3] &= ~(1 << ((g_Vars.currentplayer->gunctrl.weaponnum - 1) & 7))
#define SETFUNCSEC() g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].gunfuncs[(g_Vars.currentplayer->gunctrl.weaponnum - 1) >> 3] |= 1 << ((g_Vars.currentplayer->gunctrl.weaponnum - 1) & 7)

/**
 * This is called once B has been held for 25 ticks, or earlier if pressing B+Z.
 *
 * The function may choose whether to change the gun function,
 * or activate the secondary function without switching to it.
 *
 * Return the following;
 * - USETIMER_CONTINUE if the B button timer should continue incrementing.
 * - USETIMER_STOP if the B button timer should stop (ie. the B press is consumed)
 * - USETIMER_REPEAT if this function should be called again on each frame until B is released.
 */
s32 bgunConsiderToggleGunFunction(s32 usedowntime, bool trigpressed, bool fromactivemenu)
{
	switch (bgunGetWeaponNum(HAND_RIGHT)) {
	case WEAPON_SNIPERRIFLE:
		// At 25 ticks (or B+Z), start showing the new function
		g_Vars.currentplayer->gunctrl.invertgunfunc = true;

		// B+Z immediately triggers crouch or stand
		if (trigpressed) {
			return USETIMER_STOP;
		}

		// Don't do anything if B hasn't been held for 50/60ths of a second
		if (usedowntime < TICKS(50)) {
			return USETIMER_CONTINUE;
		}

		if (g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponfunc != FUNC_SECONDARY) {
			return USETIMER_CONTINUE;
		}

		// Do crouch or stand
		g_Vars.currentplayer->hands[HAND_RIGHT].activatesecondary = true;
		return USETIMER_REPEAT;
	case WEAPON_RCP120:
	case WEAPON_LAPTOPGUN:
	case WEAPON_DRAGON:
	case WEAPON_REMOTEMINE:
		// These weapons use temporary alt functions
		g_Vars.currentplayer->gunctrl.invertgunfunc = true;

		if (fromactivemenu && bgunIsUsingSecondaryFunction() == true) {
			g_Vars.currentplayer->hands[HAND_RIGHT].activatesecondary = true;
		}

		return USETIMER_STOP;
	case WEAPON_MAULER:
	case WEAPON_CMP150:
	case WEAPON_K7AVENGER:
	case WEAPON_AR34:
	case WEAPON_FARSIGHT:
	case WEAPON_TIMEDMINE:
		// These weapons disallow B+Z
		if (!trigpressed) {
			if (VALIDWEAPON()) {
				if (1 - GETFUNC()) {
					SETFUNCSEC();
				} else {
					SETFUNCPRI();
				}
			}

			return USETIMER_STOP;
		}

		return USETIMER_CONTINUE;
	default:
		if (trigpressed) {
			g_Vars.currentplayer->gunctrl.invertgunfunc = true;
		} else {
			if (VALIDWEAPON()) {
				if (!GETFUNC()) {
					SETFUNCSEC();
				} else {
					SETFUNCPRI();
				}
			}
		}

		return USETIMER_STOP;
	}
}

void bgun0f0a8c50(void)
{
	if (g_Vars.currentplayer->hands[HAND_RIGHT].activatesecondary == false) {
		g_Vars.currentplayer->gunctrl.invertgunfunc = false;
	}
}

bool bgunIsUsingSecondaryFunction(void)
{
	struct player *player = g_Vars.currentplayer;
	s32 weaponnum = player->gunctrl.weaponnum;

	if (weaponnum >= WEAPON_UNARMED && weaponnum <= WEAPON_COMBATBOOST) {
		s32 index = (weaponnum - 1) >> 3;
		s32 value = 1 << ((weaponnum - 1) & 7);

		if (g_PlayerConfigsArray[g_Vars.currentplayerstats->mpindex].gunfuncs[index] & value) {
			if (player->gunctrl.invertgunfunc == true) {
				return false;
			}

			return true;
		}
	}

	if (player->gunctrl.invertgunfunc == true) {
		return true;
	}

	return false;
}

/**
 * Tick gun-related things during first-person gameplay.
 *
 * This function is not called during cutscenes.
 */
void bgunTickGameplay(bool triggeron)
{
	s32 gunsfiring[2] = {false, false};
	struct player *player = g_Vars.currentplayer;
	s32 i;

	// Remove weapons if in passive mode
	if (g_Vars.currentplayer->gunctrl.passivemode) {
		struct chrdata *chr = g_Vars.currentplayer->prop->chr;
		triggeron = false;

		if (invGetCount() > 1) {
			invClear();
			invGiveSingleWeapon(WEAPON_UNARMED);
		}

		if (g_Vars.currentplayer->gunctrl.weaponnum != WEAPON_UNARMED
				&& g_Vars.currentplayer->gunctrl.switchtoweaponnum != WEAPON_UNARMED) {
			bgunEquipWeapon(WEAPON_UNARMED);
		}

		g_Vars.currentplayer->gunctrl.dualwielding = false;
		g_Vars.currentplayer->devicesactive = 0;

		chr->cloakpause = 0;
		chr->cloakfadefrac = 0;
		chr->cloakfadefinished = false;
		chr->hidden &= ~CHRHFLAG_CLOAKED;
	}

	// Remove throwable items from inventory if there's no more left
	for (i = 0; i < invGetCount(); i++) {
		struct weapon *weapon;
		s32 weaponnum = invGetWeaponNumByIndex(i);
		s32 equippedweaponnum;

		switch (weaponnum) {
		case WEAPON_COMBATKNIFE:
		case WEAPON_GRENADE:
		case WEAPON_NBOMB:
		case WEAPON_COMBATBOOST:
		case WEAPON_CLOAKINGDEVICE:
		case WEAPON_ECMMINE:
		case WEAPON_COMMSRIDER:
		case WEAPON_TRACERBUG:
		case WEAPON_TARGETAMPLIFIER:
			weapon = weaponFindById(weaponnum);

			if (weapon && weapon->ammos[0]
					&& bgunGetAmmoCount(weapon->ammos[0]->type) == 0) {
				equippedweaponnum = bgunGetWeaponNum(HAND_RIGHT);
				invRemoveItemByNum(weaponnum);

				if (weaponnum == equippedweaponnum && !invHasSingleWeaponIncAllGuns(weaponnum)) {
					invCalculateCurrentIndex();
					bgunEquipWeapon(invGetWeaponNumByIndex(g_Vars.currentplayer->equipcuritem));
				}
			}
		}
	}

	if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
		triggeron = false;
		g_Vars.currentplayer->hands[HAND_LEFT].firing = false;
		g_Vars.currentplayer->hands[HAND_RIGHT].firing = false;
	}

	player->playertriggerprev = player->playertriggeron;
	player->playertriggeron = triggeron;

	if (triggeron == false && player->playertriggerprev) {
		// Releasing trigger
		player->doautoselect = true;
	}

	// Handle gun firing - particularly alternating
	// between left and right if dual wielding
	if (player->playertriggeron) {
		player->playertrigtime240 += g_Vars.lvupdate240;

		if (player->hands[HAND_LEFT].inuse
				&& player->hands[HAND_RIGHT].inuse
				&& player->gunctrl.weaponnum != WEAPON_REMOTEMINE) {
			if (player->playertrigtime240 > TICKS(80)) {
				gunsfiring[player->curguntofire] = 1;

				if (bgun0f099008(1 - player->curguntofire)
						|| player->hands[1 - player->curguntofire].triggeron) {
					gunsfiring[1 - player->curguntofire] = 1;
				}
			} else {
				if (player->playertriggerprev == false &&
						(bgun0f099008(1 - player->curguntofire) || !bgun0f099008(player->curguntofire))) {
					player->curguntofire = 1 - player->curguntofire;
				}

				gunsfiring[player->curguntofire] = 1;
				gunsfiring[1 - player->curguntofire] = 0;
			}
		} else {
			if (!player->hands[player->curguntofire].inuse
					&& player->hands[1 - player->curguntofire].inuse) {
				player->curguntofire = 1 - player->curguntofire;
			}

			if (player->gunctrl.weaponnum == WEAPON_REMOTEMINE) {
				player->curguntofire = 0;
			}

			gunsfiring[player->curguntofire] = 1;
			gunsfiring[1 - player->curguntofire] = 0;
		}
	} else {
		player->playertrigtime240 = 0;
	}

	bgunSetTriggerOn(HAND_RIGHT, gunsfiring[0]);
	bgunSetTriggerOn(HAND_LEFT, gunsfiring[1]);

	if (g_Vars.tickmode == TICKMODE_NORMAL && g_Vars.lvupdate240 > 0) {
		bgunTickHand(HAND_RIGHT);
		bgunTickHand(HAND_LEFT);
		bgunTickSwitch();

		if (cheatIsActive(CHEAT_UNLIMITEDAMMONORELOADS)) {
			s32 i;
			struct weapon *weapon;
			struct hand *lhand = &g_Vars.currentplayer->hands[HAND_LEFT];
			struct hand *rhand = &g_Vars.currentplayer->hands[HAND_RIGHT];

			weapon = weaponFindById(rhand->gset.weaponnum);

			for (i = 0; i != 2; i++) {
				if (weapon && weapon->ammos[i] &&
						bgunAmmotypeAllowsUnlimitedAmmo(weapon->ammos[i]->type)) {
					rhand->loadedammo[i] = rhand->clipsizes[i];
					lhand->loadedammo[i] = lhand->clipsizes[i];
				}
			}

			bgunGiveMaxAmmo(false);
		} else if (cheatIsActive(CHEAT_UNLIMITEDAMMO)) {
			bgunGiveMaxAmmo(false);
		}
	}

	bgunDecreaseNoiseRadius();

	if (player->resetshadecol) {
		propCalculateShadeColour(g_Vars.currentplayer->prop, player->gunshadecol, player->floorcol);
		player->resetshadecol = 0;
	} else {
		u8 shadecol[4];
		propCalculateShadeColour(g_Vars.currentplayer->prop, shadecol, player->floorcol);
		colourTween(player->gunshadecol, shadecol);
	}

	invIncrementHeldTime(bgunGetWeaponNum(HAND_RIGHT), bgunGetWeaponNum(HAND_LEFT));
}

void bgunSetPassiveMode(bool enable)
{
	s32 i;

	for (i = 0; i < PLAYERCOUNT(); i++) {
		g_Vars.players[i]->gunctrl.passivemode = enable;
	}
}

void bgunSetAimType(u32 aimtype)
{
	g_Vars.currentplayer->aimtype = aimtype;
}

void bgunSetAimPos(struct coord *coord)
{
	struct player *player = g_Vars.currentplayer;

	player->hands[HAND_RIGHT].aimpos.x = handGetXShift(HAND_RIGHT) + coord->x;
	player->hands[HAND_RIGHT].aimpos.y = coord->y;
	player->hands[HAND_RIGHT].aimpos.z = coord->z;

	player->hands[HAND_LEFT].aimpos.x = handGetXShift(HAND_LEFT) + coord->x;
	player->hands[HAND_LEFT].aimpos.y = coord->y;
	player->hands[HAND_LEFT].aimpos.z = coord->z;
}

void bgunSetHitPos(struct coord *coord)
{
	struct player *player = g_Vars.currentplayer;

	player->hands[HAND_LEFT].hitpos.x = player->hands[HAND_RIGHT].hitpos.x = coord->x;
	player->hands[HAND_LEFT].hitpos.y = player->hands[HAND_RIGHT].hitpos.y = coord->y;
	player->hands[HAND_LEFT].hitpos.z = player->hands[HAND_RIGHT].hitpos.z = coord->z;
}

void bgun0f0a9494(u32 operation)
{
	switch (operation) {
	case 0:
		g_Vars.currentplayer->hands[HAND_LEFT].hasdotinfo = g_Vars.currentplayer->hands[HAND_RIGHT].hasdotinfo = false;
		break;
	case 1:
		break;
	}
}

void bgun0f0a94d0(u32 operation, struct coord *pos, struct coord *rot)
{
	struct player *player = g_Vars.currentplayer;

	switch (operation) {
	case 0:
		if (pos->x > -100000.0f && pos->x < 100000.0f
				&& pos->y > -100000.0f && pos->y < 100000.0f
				&& pos->z > -100000.0f && pos->z < 100000.0f) {
			player->hands[HAND_RIGHT].hasdotinfo = true;
			player->hands[HAND_LEFT].hasdotinfo = true;

			player->hands[HAND_LEFT].dotpos.x = player->hands[HAND_RIGHT].dotpos.x = pos->x;
			player->hands[HAND_LEFT].dotpos.y = player->hands[HAND_RIGHT].dotpos.y = pos->y;
			player->hands[HAND_LEFT].dotpos.z = player->hands[HAND_RIGHT].dotpos.z = pos->z;

			player->hands[HAND_LEFT].dotrot.x = player->hands[HAND_RIGHT].dotrot.x = rot->x;
			player->hands[HAND_LEFT].dotrot.y = player->hands[HAND_RIGHT].dotrot.y = rot->y;
			player->hands[HAND_LEFT].dotrot.z = player->hands[HAND_RIGHT].dotrot.z = rot->z;
		}
		break;
	case 1:
	case 2:
		lasersightSetDot(operation - 1, pos, rot);
		break;
	}
}

void bgunSetGunAmmoVisible(u32 reason, bool enable)
{
	if (enable) {
		g_Vars.currentplayer->gunammooff &= ~reason;
	} else {
		g_Vars.currentplayer->gunammooff |= reason;
	}
}

struct ammotype g_AmmoTypes[] = {
	{ 0,            0, 0  },
	{ 800,          0, 0  }, // AMMOTYPE_PISTOL
	{ 800,          0, 0  }, // AMMOTYPE_SMG
	{ 69,           0, 0  }, // AMMOTYPE_CROSSBOW
	{ 400,          0, -2 }, // AMMOTYPE_RIFLE
	{ 100,          0, 0  }, // AMMOTYPE_SHOTGUN
	{ 100,          0, 0  }, // AMMOTYPE_FARSIGHT
	{ 12,           0, 0  }, // AMMOTYPE_GRENADE
	{ 3,            0, -2 }, // AMMOTYPE_ROCKET
	{ 10,           0, 0  }, // AMMOTYPE_KNIFE
	{ 200,          0, 0  }, // AMMOTYPE_MAGNUM
	{ 40,           0, 0  }, // AMMOTYPE_DEVASTATOR
	{ 10,           0, 1  }, // AMMOTYPE_REMOTE_MINE
	{ 10,           0, 1  }, // AMMOTYPE_PROXY_MINE
	{ 10,           0, 1  }, // AMMOTYPE_TIMED_MINE
	{ 800,          0, 0  }, // AMMOTYPE_REAPER
	{ 15,           0, -2 }, // AMMOTYPE_HOMINGROCKET
	{ 50,           0, 0  }, // AMMOTYPE_DART
	{ 10,           0, 0  }, // AMMOTYPE_NBOMB
	{ 200,          0, 0  }, // AMMOTYPE_SEDATIVE
	{ TICKS(18000), 0, 0  }, // AMMOTYPE_CLOAK
	{ 4,            0, 0  }, // AMMOTYPE_BOOST
	{ 200,          0, 0  }, // AMMOTYPE_PSYCHOSIS
	{ 2,            0, 0  }, // AMMOTYPE_17
	{ 10,           0, 0  }, // AMMOTYPE_BUG
	{ 10,           0, 0  }, // AMMOTYPE_MICROCAMERA
	{ 10,           0, 0  }, // AMMOTYPE_PLASTIQUE
	{ 1000,         0, 0  }, // AMMOTYPE_1B
	{ 10,           0, 0  }, // AMMOTYPE_1C
	{ 50,           0, -1 }, // AMMOTYPE_1D
	{ 1,            0, 0  }, // AMMOTYPE_TOKEN
	{ 200,          0, 0  }, // AMMOTYPE_1F
	{ 10,           0, 0  }, // AMMOTYPE_ECM_MINE
};

void bgunSetAmmoQuantity(s32 ammotype, s32 quantity)
{
	struct player *player = g_Vars.currentplayer;
	s32 weaponnum = bgunGetWeaponNum(HAND_RIGHT);
	s32 funcnum = -1;
	s32 magamount;

	// Check if this ammo type applies to the player's equipped weapon
	if (bgunGetAmmoTypeForWeapon(weaponnum, FUNC_PRIMARY) == ammotype) {
		funcnum = FUNC_PRIMARY;
	}

	if (bgunGetAmmoTypeForWeapon(weaponnum, FUNC_SECONDARY) == ammotype) {
		funcnum = FUNC_SECONDARY;
	}

	if (funcnum != -1 && weaponHasAmmoFlag(weaponnum, funcnum, AMMOFLAG_NORESERVE)) {
		// For cloak and combat boost, ammo cannot be held outside of the weapon.
		// So just add it to the loaded clip.
		player->hands[0].loadedammo[funcnum] += quantity;

		if (player->hands[0].loadedammo[funcnum] > player->hands[0].clipsizes[funcnum]) {
			player->hands[0].loadedammo[funcnum] = player->hands[0].clipsizes[funcnum];
		}

		player->ammoheldarr[ammotype] = 0;
		return;
	}

	magamount = 0;

	// For throwable items, the capacity applies to reserve + loaded
	if (funcnum != -1 && weaponHasAmmoFlag(weaponnum, funcnum, AMMOFLAG_EQUIPPEDISRESERVE)) {
		magamount = player->hands[0].loadedammo[funcnum] + player->hands[1].loadedammo[funcnum];
	}

	if (quantity > g_AmmoTypes[ammotype].capacity - magamount) {
		player->ammoheldarr[ammotype] = g_AmmoTypes[ammotype].capacity - magamount;
	} else {
		player->ammoheldarr[ammotype] = quantity;
	}
}

s32 bgunGetReservedAmmoCount(s32 ammotype)
{
	s32 i;
	s32 j;
	s32 total = g_Vars.currentplayer->ammoheldarr[ammotype];
	struct player *player = g_Vars.currentplayer;

	for (i = 0; i < 2; i++) {
		if (player->hands[i].inuse) {
			for (j = 0; j < 2; j++) {
				if (player->gunctrl.ammotypes[j] == ammotype && weaponHasAmmoFlag(player->hands[i].gset.weaponnum, j, AMMOFLAG_NORESERVE)) {
					total = total + player->hands[i].loadedammo[j];
				}
			}
		}
	}

	return total;
}

s32 bgunGetAmmoCount(s32 ammotype)
{
	s32 i;
	s32 j;
	s32 total = g_Vars.currentplayer->ammoheldarr[ammotype];
	struct player *player = g_Vars.currentplayer;

	for (i = 0; i < 2; i++) {
		if (player->hands[i].inuse) {
			for (j = 0; j < 2; j++) {
				if (player->gunctrl.ammotypes[j] == ammotype) {
					total = total + player->hands[i].loadedammo[j];
				}
			}
		}
	}

	return total;
}

s32 bgunGetCapacityByAmmotype(s32 ammotype)
{
	return g_AmmoTypes[ammotype].capacity;
}

bool bgunAmmotypeAllowsUnlimitedAmmo(u32 ammotype)
{
	switch (ammotype) {
	case AMMOTYPE_REMOTE_MINE:
		if (g_Vars.stagenum == STAGE_CHICAGO) {
			return false;
		}
		break;
	case AMMOTYPE_TIMED_MINE:
		if (g_Vars.stagenum == STAGE_AIRFORCEONE) {
			return false;
		}
		break;
	case AMMOTYPE_PSYCHOSIS:
	case AMMOTYPE_17:
	case AMMOTYPE_BUG:
	case AMMOTYPE_MICROCAMERA:
	case AMMOTYPE_PLASTIQUE:
	case AMMOTYPE_1B:
	case AMMOTYPE_1C:
	case AMMOTYPE_1D:
	case AMMOTYPE_TOKEN:
	case AMMOTYPE_1F:
	case AMMOTYPE_ECM_MINE:
		return false;
	}

	return true;
}

void bgunGiveMaxAmmo(bool force)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_AmmoTypes); i++) {
		bool give = true;

		if (!force) {
			give = bgunAmmotypeAllowsUnlimitedAmmo(i);
		}

		if (give) {
			bgunSetAmmoQuantity(i, g_AmmoTypes[i].capacity);
		}
	}
}

u32 bgunGetAmmoTypeForWeapon(u32 weaponnum, u32 func)
{
	struct weapon *weapon = weaponFindById(weaponnum);

	if (!weapon) {
		return 0;
	}

	if (!weapon->ammos[func]) {
		return 0;
	}

	return weapon->ammos[func]->type;
}

s32 bgunGetAmmoQtyForWeapon(u32 weaponnum, u32 func)
{
	struct weapon *weapon = weaponFindById(weaponnum);

	if (weapon) {
		struct inventory_ammo *ammo = weapon->ammos[func];

		if (ammo) {
			return bgunGetReservedAmmoCount(ammo->type);
		}
	}

	return 0;
}

void bgunSetAmmoQtyForWeapon(u32 weaponnum, u32 func, u32 quantity)
{
	struct weapon *weapon = weaponFindById(weaponnum);

	if (weapon) {
		struct inventory_ammo *ammo = weapon->ammos[func];

		if (ammo) {
			bgunSetAmmoQuantity(ammo->type, quantity);
		}
	}
}

s32 bgunGetAmmoCapacityForWeapon(s32 weaponnum, s32 func)
{
	struct weapon *weapon = weaponFindById(weaponnum);
	struct inventory_ammo *ammo = weapon->ammos[func];

	if (ammo) {
		return g_AmmoTypes[ammo->type].capacity;
	}

	return 0;
}

Gfx *bgunDrawHudString(Gfx *gdl, char *text, s32 x, bool halign, s32 y, s32 valign, u32 colour)
{
	s32 x1 = 0;
	s32 y1 = 0;
	s32 x2 = 0;
	s32 y2 = 0;
	s32 textheight;
	s32 textwidth;

	textwidth = 0;
	textheight = 0;

#if VERSION >= VERSION_JPN_FINAL
	textMeasure(&textheight, &textwidth, text, g_CharsNumeric, g_FontNumeric, -1);
#else
	textMeasure(&textheight, &textwidth, text, g_CharsNumeric, g_FontNumeric, 0);
#endif

	if (halign == HUDHALIGN_LEFT) { // left
		x2 = x + textwidth;
		x1 = x;
	} else if (halign == HUDHALIGN_RIGHT) { // right
		x1 = x - textwidth;
		x2 = x;
	} else if (halign == HUDHALIGN_MIDDLE) { // middle
		x2 = x + textwidth / 2;
		x1 = x2 - textwidth;
	}

	if (valign == HUDVALIGN_TOP) { // top
		y2 = y + textheight;
		y1 = y;
	} else if (valign == HUDVALIGN_BOTTOM) { // bottom
		y1 = y - textheight;
		y2 = y;
	} else if (valign == HUDVALIGN_MIDDLE) { // middle
		y2 = y + textheight / 2;
		y1 = y2 - textheight;
	}

	gdl = text0f153858(gdl, &x1, &y1, &x2, &y2);
	gdl = textRender(gdl, &x1, &y1, text, g_CharsNumeric, g_FontNumeric, colour, 0x000000a0, viGetWidth(), viGetHeight(), 0, 0);

	return gdl;
}

Gfx *bgunDrawHudInteger(Gfx *gdl, s32 value, s32 x, bool halign, s32 y, s32 valign, u32 colour)
{
	char buffer[12];

	sprintf(buffer, "%d\n", value);
	gdl = bgunDrawHudString(gdl, buffer, x, halign, y, valign, colour);

	return gdl;
}

void bgunResetAbmag(struct abmag *abmag)
{
	abmag->loadedammo = 0;
	abmag->change = 0;
	abmag->ref = 0;
	abmag->timer60 = 0;
}

void bgun0f0a9da8(struct abmag *mag, s32 remaining, s32 capacity, s32 height)
{
	s32 newchange;

	if (capacity > 20) {
		s32 newremaining = height * remaining / capacity;

		if (remaining > 0 && newremaining < 1) {
			newremaining = 1;
		}

		capacity = height;

		if (newremaining == mag->ref && mag->loadedammo > remaining) {
			mag->ref++;
		}

		mag->loadedammo = remaining;
		remaining = newremaining;
	}

	newchange = remaining - mag->ref;

	if ((mag->change < 0 && newchange > 0) || (mag->change > 0 && newchange < 0)) {
		mag->ref += mag->change;
		mag->change = 0;
		mag->timer60 = 0;

		newchange = remaining - mag->ref;
	}

	if (mag->change < 0 && mag->change > newchange) {
		if (mag->timer60 > -mag->change * TICKS(64)) {
			mag->timer60 = -mag->change * TICKS(64);
		}
	}

	mag->change = newchange;

	if (mag->change > 0) {
		height = capacity;

		if (capacity < 6) {
			height = 6;
		}
	} else {
		height = 8;

		if (mag->change < -3) {
			height += -mag->change * 2;
		}
	}

	if (mag->change != 0) {
		mag->timer60 += (s16)g_Vars.lvupdate240_60 * height;

		if (mag->timer60 > TICKS(255)) {
			if (mag->change > 0) {
				while (mag->timer60 > TICKS(255) && mag->change > 0) {
					mag->change--;
					mag->ref++;
					mag->timer60 -= TICKS(64);
				}
			} else {
				while (mag->timer60 > TICKS(255) && mag->change < 0) {
					mag->change++;
					mag->ref--;
					mag->timer60 -= TICKS(64);
				}
			}
		}
	} else {
		mag->timer60 = 0;
	}
}

/**
 * Render an ammo gauge on the HUD.
 *
 * Ammo gauges can be displayed in two ways. If the capacity is less than 20,
 * each bullet is displayed as a separate block with a gap between each. If the
 * capacity is 20 or more, a single block covers the whole gauge and the block
 * is partitioned into two (filled and empty).
 *
 * For the separated mode, a unit refers to a single bullet/block.
 * For the merged mode, a unit refers to a single 1px high line in the gauge.
 */
Gfx *bgunDrawHudGauge(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, struct abmag *abmag, s32 remaining, s32 capacity, u32 emptycolour, u32 filledcolour, bool flip)
{
	s32 gaugeheight = y2 - y1;
	s32 unitheight;
	s32 remainder1;
	s32 remainder2;
	s32 gaugetop;
	f32 ref;
	s32 numunits = capacity;
	s32 i;

	bgun0f0a9da8(abmag, remaining, numunits, gaugeheight);

	if (numunits > 20) {
		// Use a single merged bar
		ref = abmag->ref;
		unitheight = 1;
		numunits = gaugeheight;
		gaugetop = y2 - gaugeheight;
	} else {
		// Use a separate block for each bullet
		ref = abmag->ref;
		unitheight = gaugeheight / numunits;
		remainder1 = unitheight * numunits - gaugeheight;
		remainder2 = (unitheight + 1) * numunits - gaugeheight;

		if (remainder1 < 0) {
			remainder1 = -remainder1;
		}

		if (remainder2 < 0) {
			remainder2 = -remainder2;
		}

		if (remainder2 < remainder1) {
			unitheight++;
		}

		gaugetop = y2 - unitheight * capacity + 1;

		if (unitheight <= 2) {
			gaugetop--;
		}
	}

	if (unitheight == 0) {
		/**
		 * Using separate blocks, but the clip capacity is more than the gauge
		 * height meaning each block is less than 1px. This is impossible
		 * because the gauge switches modes away from separate blocks at 20,
		 * therefore this code is unreachable.
		 *
		 * This code renders the gauge in the merged style, but uses 1px per
		 * bullet and truncates the gauge at the gaugetop if needed. This is
		 * clearly an early revision of the code, as it is visually misleading
		 * and also lacks the transition effect.
		 */
		s32 partitiony;
		s32 tmp;

		gaugeheight = y2 - gaugetop;
		partitiony = y2 - gaugeheight * ref / numunits;
		tmp = y2;

		if (partitiony > gaugetop) {
			// Render empty partition
			gdl = textSetPrimColour(gdl, emptycolour);

			if (flip) {
				gDPFillRectangleScaled(gdl++, x1, y2 - partitiony + y1, x2, gaugeheight + y1);
			} else {
				gDPFillRectangleScaled(gdl++, x1, gaugetop, x2, partitiony);
			}

			gdl = text0f153838(gdl);
		}

		// Render filled partition
		gdl = textSetPrimColour(gdl, filledcolour);

		if (flip) {
			gDPFillRectangleScaled(gdl++, x1, y2 - tmp + y1, x2, y2 - partitiony + y1);
		} else {
			gDPFillRectangleScaled(gdl++, x1, partitiony, x2, y2);
		}
	} else {
		u32 colour;
		s32 unittop;
		s32 unitbottom;

		gdl = textSetPrimColour(gdl, emptycolour);

		unittop = gaugetop;
		unitbottom = -1;

		for (i = 0; i < numunits; i++) {
			bool newstate = false;
			u32 weight;

			if (1);

			if (abmag->change > 0) {
				// Loading or reloading
				if (i >= numunits - (s32)ref - abmag->change && i < numunits - (s32)ref) {
					// Unit is potentially unsettled
					s32 fadeamount = abmag->timer60 - (numunits - (s32)ref - i - 1) * TICKS(64);

					if (fadeamount >= 0) {
						if (fadeamount >= TICKS(64)) {
							// Unit is transitioning to filled
#if PAL
							weight = (fadeamount * 4 - TICKS(250)) / 3;
#else
							weight = (fadeamount * 4 - TICKS(252)) / 3;
#endif
							weight = PALUP(weight);

							if (weight > 255) {
								weight = 255;
							}

							colour = colourBlend(filledcolour, 0xffffffbf, weight);
						} else {
							// Unit is bright and has not started transitioning to filled yet
							weight = fadeamount * 4;
							weight = PALUP(weight);

#if VERSION >= VERSION_PAL_BETA
							if (weight > 255) {
								weight = 255;
							}
#endif

							colour = colourBlend(0xffffffbf, emptycolour, weight);
						}

						newstate = true;
					}
				}
			} else if (abmag->change < 0) {
				// Firing
				if (i < numunits - (s32)ref - abmag->change && i >= numunits - (s32) ref) {
					s32 fadeamount = abmag->timer60 - (i - numunits + (s32) ref) * TICKS(64);

					if (fadeamount >= 0) {
						weight = PALUP(fadeamount);

						if (weight > 255) {
							colour = emptycolour;
						} else {
							// Unit was recently emptied
							colour = colourBlend(emptycolour, filledcolour | 0xff, weight);
						}

						newstate = true;
					}
				}
			}

			// Special case for units which are one after the last one being
			// faded. I think their colour is calculated incorrectly by the code
			// above and this is resetting them to the normal filled colour.
			if (abmag->change < 0) {
				// Firing
				if (i == numunits - (s32) ref - abmag->change) {
					colour = filledcolour;
					newstate = true;
				}
			} else {
				if (i == numunits - (s32) ref) {
					colour = filledcolour;
					newstate = true;
				}
			}

			// Calculate unittop and unitbottom. For merged gauges keep unittop
			// as it is if possible, so the empty and filled partitions can be
			// drawn whenever the state is changed in order to save gfx calls.
			if (unitheight <= 2) {
				if (newstate) {
					if (unitbottom >= 0) {
						// Render empty or transitioning unit of merged gauge
						if (flip) {
							gDPFillRectangleScaled(gdl++, x1, y2 - unitbottom + y1, x2, y2 - unittop + y1);
						} else {
							gDPFillRectangleScaled(gdl++, x1, unittop, x2, unitbottom);
						}
					}

					unittop = gaugetop + i * unitheight;
				}

				unitbottom = gaugetop + i * unitheight + unitheight;
			} else {
				// Separate blocks - reduce unitbottom by 1 to make a gap
				unittop = gaugetop + i * unitheight;
				unitbottom = gaugetop + i * unitheight + unitheight - 1;
			}

			if (newstate) {
				gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
			}

			// For separate blocks, clip the unit bottom to the bottom of the gauge
			if (unitbottom >= y2 - 1 && unitheight >= 2) {
				unitbottom = y2;
			}

			// Render separated blocks
			if (unitheight >= 3) {
				if (flip) {
					gDPFillRectangleScaled(gdl++, x1, y2 - unitbottom + y1, x2, y2 - unittop + y1);
				} else {
					gDPFillRectangleScaled(gdl++, x1, unittop, x2, unitbottom);
				}
			}
		} // end loop

		// For merged gauges, render the final partition
		if (unitheight <= 2) {
			s32 stack;

			if (flip) {
				gDPFillRectangleScaled(gdl++, x1, y2 - unitbottom + y1, x2, y2 - unittop + y1);
			} else {
				gDPFillRectangleScaled(gdl++, x1, unittop, x2, unitbottom);
			}
		}
	}

	gdl = text0f153838(gdl);

	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

	return gdl;
}

Gfx *bgunDrawHud(Gfx *gdl)
{
	struct player *player = g_Vars.currentplayer;
	s32 bottom = viGetViewTop() + viGetViewHeight() - 13;
	s32 playercount = PLAYERCOUNT();
	s32 playernum = g_Vars.currentplayernum;
	struct gunctrl *ctrl;
	s32 secs60;
	s32 speedpilltime;
	s32 ammoindex = 0;
	s32 barwidth = 9;
	s32 reserveheight = 36;
	s32 clipheight = 57;
	s32 xpos;
	struct weapon *weapon = weaponFindById(player->gunctrl.weaponnum);
	u32 alpha;
	u32 fncolour;
	s32 funcnum;
	s32 fnfaderinc;
#if VERSION >= VERSION_NTSC_1_0
	s32 tmpfuncnum;
	struct handweaponinfo info;
#endif
	struct hand *hand = &player->hands[HAND_RIGHT];
	char *str;
	u32 colour;
	s32 x;
	s32 y;
	s32 textheight;
	s32 textwidth;
	struct weaponfunc *func;
	u16 nameid;
	struct hand *lefthand = &player->hands[HAND_LEFT];

	ctrl = &player->gunctrl;

	if (player->isdead) {
		return gdl;
	}

	if (g_Vars.currentplayer->gunctrl.passivemode) {
		return gdl;
	}

	if (g_Vars.lvframenum < 5) {
		return gdl;
	}

#if PAL
	g_ScaleX = 1;
#else
	g_ScaleX = g_ViRes == VIRES_HI ? 2 : 1;
#endif

	gdl = text0f153628(gdl);

	if (playercount >= 2) {
		barwidth = 5;
		reserveheight = 26;
		clipheight = 47;

		if (playercount == 2) {
			if (IS4MB() || (optionsGetScreenSplit() != SCREENSPLIT_VERTICAL && playernum == 0)) {
				bottom += 10;
			} else {
				bottom += 2;
			}
		} else if (playercount >= 3) {
			if (playernum < 2) {
				bottom += 10;
			} else {
				bottom += 2;
			}
		}
	} else if (optionsGetEffectiveScreenSize() != SCREENSIZE_FULL) {
		bottom += 8;
	}

	fncolour = 0xff000040;
	funcnum = hand->gset.weaponfunc;
	fnfaderinc = PALUP(g_Vars.lvupdate240 * 2);

#if VERSION >= VERSION_NTSC_1_0
	bgunGetWeaponInfo(&info, HAND_RIGHT);
	tmpfuncnum = bgunIsUsingSecondaryFunction();

	if (bgun0f098ca0(tmpfuncnum, &info, hand) >= 0) {
		funcnum = tmpfuncnum;
	}
#endif

	xpos = (viGetViewLeft() + viGetViewWidth()) / g_ScaleX - barwidth - 24;

	if (playercount == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB()) && playernum == 0) {
		xpos += 15;
	} else if (playercount >= 3 && (playernum % 2) == 0) {
		xpos += 15;
	}

	// Draw function square
	if (funcnum == FUNC_SECONDARY && ctrl->fnfader < 255) {
		if (ctrl->fnfader < 128) {
			ctrl->fnfader = 128;
		}

		if (ctrl->fnfader + fnfaderinc > 255) {
			ctrl->fnfader = 255;
		} else {
			ctrl->fnfader += fnfaderinc;
		}
	}

	if (funcnum == FUNC_PRIMARY && ctrl->fnfader > 0) {
		if (ctrl->fnfader - fnfaderinc < 0) {
			ctrl->fnfader = 0;
		} else {
			ctrl->fnfader -= fnfaderinc;
		}
	}

	if (ctrl->fnfader > 128) {
		fncolour = ((ctrl->fnfader * 2) - 256) << 16 | 0xff000040;
	}

	gdl = textSetPrimColour(gdl, fncolour);

	gDPFillRectangleScaled(gdl++, xpos - 13, bottom - 11, xpos - 2, bottom);

	gdl = text0f153838(gdl);

	// Draw weapon name and function name
	if (optionsGetShowGunFunction(g_Vars.currentplayerstats->mpindex)) {
#if VERSION >= VERSION_NTSC_1_0
		func = weaponGetFunctionById(hand->gset.weaponnum, funcnum);
#else
		func = weaponGetFunctionById(hand->gset.weaponnum, hand->gset.weaponfunc);
#endif
		nameid = invGetNameIdByIndex(invGetCurrentIndex());
		str = langGet(nameid);

		if (ctrl->curgunstr != nameid) {
			ctrl->guntypetimer = 0;
			ctrl->curgunstr = nameid;
		}

		if (ctrl->guntypetimer < 255) {
			colour = 0x55ffffff;

			if (ctrl->guntypetimer);

			if (ctrl->guntypetimer + g_Vars.lvupdate240_60 > 255) {
				ctrl->guntypetimer = 255;
			} else {
				ctrl->guntypetimer += (u16) g_Vars.lvupdate240_60;
			}

			textMeasure(&textheight, &textwidth, str, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
			textwidth += 2;

			if (textwidth > ctrl->guntypetimer * 3) {
				textwidth = ctrl->guntypetimer * 3;
			}

			if (playercount >= 2) {
				x = xpos - textwidth - 13;
			} else {
				x = xpos - textwidth - 2;
			}

#if VERSION == VERSION_JPN_FINAL
			y = bottom - textheight - 10;
#else
			y = bottom - textheight - 15;
#endif

			if (ctrl->guntypetimer > 192) {
				alpha = 255 - (ctrl->guntypetimer - 192) * 255 / 63U;
				colour = (colour & 0xffffff00) | alpha;
				if (0xffffff00);
			}

			gdl = textSetPrimColour(gdl, 0);

			gDPFillRectangleScaled(gdl++, x - 1, y - 1, xpos - 11, bottom);

			gdl = text0f153838(gdl);
			textSetWaveBlend(var80061630 * 50.0f, 0, 50);
			textSetWaveColours(0xffffffff, 0xffffffff);
			gdl = textRenderProjected(gdl, &x, &y, str, g_CharsHandelGothicXs, g_FontHandelGothicXs, colour, textwidth, 1000, 0, 0);
			textResetBlends();
		}

		if (func) {
			langGet(func->name);

			colour = 0xff5555ff;

			if ((ctrl->curfnstr != func->name && ctrl->fnfader > 128) || ctrl->curfnstr == 0) {
				ctrl->fnstrtimer = 0;
				ctrl->curfnstr = func->name;
			}

			str = langGet(ctrl->curfnstr);

			if (ctrl->fnstrtimer < 255) {
				if (ctrl->fnstrtimer + g_Vars.lvupdate240_60 > 255) {
					ctrl->fnstrtimer = 255;
				} else {
					ctrl->fnstrtimer += (u16) g_Vars.lvupdate240_60;
				}

#if VERSION >= VERSION_NTSC_1_0
				if (funcnum == FUNC_SECONDARY && func->name == ctrl->curfnstr) {
					colour |= 0x00ff0000;
				}

				if (funcnum == FUNC_PRIMARY && func->name != ctrl->curfnstr) {
					colour |= 0x00ff0000;
				}
#else
				if (hand->gset.weaponfunc == FUNC_SECONDARY && func->name == ctrl->curfnstr) {
					colour |= 0x00ff0000;
				}

				if (hand->gset.weaponfunc == FUNC_PRIMARY && func->name != ctrl->curfnstr) {
					colour |= 0x00ff0000;
				}
#endif

				textMeasure(&textheight, &textwidth, str, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);
				textwidth += 2;

				if (textwidth > ctrl->fnstrtimer * 3) {
					textwidth = ctrl->fnstrtimer * 3;
				}

				x = xpos - textwidth - 13;
#if VERSION == VERSION_JPN_FINAL
				y = bottom - textheight + 3;
#else
				y = bottom - textheight - 1;
#endif

				if (ctrl->fnstrtimer > 192) {
					alpha = 255 - (ctrl->fnstrtimer - 192) * 255 / 63U;
					colour = (colour & 0xffffff00) | alpha;
				}

				gdl = textSetPrimColour(gdl, 0);

				gDPFillRectangleScaled(gdl++, x - 1, y - 1, xpos - 11, bottom + 3);

				gdl = text0f153838(gdl);

				textSetWaveBlend(var80061630 * 50.0f, 0, 50);
				textSetWaveColours(0xffffffff, 0xffffffff);

				gdl = textRenderProjected(gdl, &x, &y, str,
						g_CharsHandelGothicXs, g_FontHandelGothicXs, colour, textwidth,
						1000, 0, 0);

				textResetBlends();
			}
		}
	}

	if (weapon && weapon->functions[hand->gset.weaponfunc] != NULL) {
		ammoindex = ((struct weaponfunc *)(weapon->functions[hand->gset.weaponfunc]))->ammoindex;
	}

	if (ammoindex == -1) {
		if (weapon->functions[1 - hand->gset.weaponfunc] != NULL) {
			ammoindex = ((struct weaponfunc *)(weapon->functions[1 - hand->gset.weaponfunc]))->ammoindex;
		}

		if (ammoindex == -1) {
			gdl = text0f153780(gdl);
			g_ScaleX = 1;
			return gdl;
		}
	}

	if (ammoindex != ctrl->lastmag) {
		bgunResetAbmag(&player->hands[HAND_LEFT].abmag);
		bgunResetAbmag(&hand->abmag);
		bgunResetAbmag(&ctrl->abmag);
		ctrl->lastmag = ammoindex;
	}

	// Left hand - mag
	if (lefthand->inuse
			&& weapon->ammos[ammoindex] != NULL
			&& lefthand->gset.weaponnum != WEAPON_REMOTEMINE) {
		xpos = viGetViewLeft() / g_ScaleX + 24;

		if (playercount == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB()) && playernum == 1) {
			xpos -= 14;
		} else if (playercount >= 3 && (playernum & 1) == 1) {
			xpos -= 14;
		}

		if (lefthand->clipsizes[ammoindex] > 0 && (weapon->ammos[ammoindex]->flags & AMMOFLAG_EQUIPPEDISRESERVE) == 0) {
			gdl = bgunDrawHudGauge(gdl,
					xpos, bottom - reserveheight - clipheight - 3, xpos + barwidth, bottom - reserveheight - 3,
					&lefthand->abmag, lefthand->loadedammo[ammoindex], lefthand->clipsizes[ammoindex],
					0x00300080, 0x00ff0040, false);
			gdl = bgunDrawHudInteger(gdl, lefthand->loadedammo[ammoindex], xpos + barwidth + 2, true,
					bottom - reserveheight - 8, 0, 0x00ff00a0);
		}
	}

	// Right hand - mag, reserve and combat boost timer
	if (hand->inuse && ctrl->ammotypes[ammoindex] >= 0) {
		s32 ammotype;
		s32 ammoheld;
		s32 ammototal;

		ammotype = player->gunctrl.ammotypes[ammoindex];

#if VERSION >= VERSION_NTSC_1_0
		xpos = (viGetViewLeft() + viGetViewWidth()) / g_ScaleX - barwidth - 24;
#else
		// NTSC Beta omits the brackets here. This would normally cause the
		// ammo info to be misaligned for players on the right side of the
		// screen and when using hi-res, but I'm not sure if hi-res can even be
		// active when using multiple players...
		xpos = viGetViewLeft() + viGetViewWidth() / g_ScaleX - barwidth - 24;
#endif

		if (playercount == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB()) && playernum == 0) {
			xpos += 15;
		} else if (playercount >= 3 && (playernum % 2) == 0) {
			xpos += 15;
		}

		// Mag
		ammoheld = player->ammoheldarr[ammotype];

		if (hand->clipsizes[ammoindex] > 0
				&& weapon->ammos[ammoindex] != NULL
				&& (weapon->ammos[ammoindex]->flags & AMMOFLAG_EQUIPPEDISRESERVE) == 0) {
			gdl = bgunDrawHudGauge(gdl, xpos, bottom - reserveheight - clipheight - 3, xpos + barwidth,
					bottom - reserveheight - 3, &hand->abmag, hand->loadedammo[ammoindex], hand->clipsizes[ammoindex],
					0x00300080, 0x00ff0040, false);
			gdl = bgunDrawHudInteger(gdl, hand->loadedammo[ammoindex], xpos - 2, false,
					bottom - reserveheight - 8, 0, 0x00ff00a0);
		}

		// Reserve
		if (g_AmmoTypes[ammotype].capacity > 0
				&& (weapon->ammos[ammoindex]->flags & AMMOFLAG_NORESERVE) == 0) {
			ammototal = ammoheld;

			if (weapon->ammos[ammoindex]->flags & AMMOFLAG_EQUIPPEDISRESERVE) {
				if (hand->clipsizes[ammoindex] > 0) {
					ammototal += hand->loadedammo[ammoindex];
				}

				if (lefthand->clipsizes[ammoindex] > 0) {
					ammototal += lefthand->loadedammo[ammoindex];
				}
			}

			gdl = bgunDrawHudGauge(gdl, xpos, bottom - reserveheight, xpos + barwidth,
					bottom, &ctrl->abmag, ammototal, g_AmmoTypes[ammotype].capacity,
					0x00403080, 0x00ffc040, true);
			gdl = bgunDrawHudInteger(gdl, ammototal, xpos - 2, false, bottom - reserveheight + 1, 0, 0x00ffc0a0);
		}

		// Combat boost timer
		if (hand->gset.weaponnum == WEAPON_COMBATBOOST) {
			s32 mins;
			char text[32];

			speedpilltime = g_Vars.speedpilltime;
			mins = speedpilltime / TICKS(3600);
			secs60 = speedpilltime - mins * TICKS(3600);

			if (mins >= 1) {
				sprintf(text, "%02d:%02d:%02d\n", mins, secs60 / TICKS(60), (secs60 - (secs60 / TICKS(60)) * TICKS(60)) * 100 / TICKS(60));
			} else {
				sprintf(text, "%02d:%02d\n", secs60 / TICKS(60), (secs60 - (secs60 / TICKS(60)) * TICKS(60)) * 100 / TICKS(60));
			}

			gdl = bgunDrawHudString(gdl, text, xpos + barwidth - 2, false, bottom - reserveheight + 1, 0, 0x00ffc0a0);
		}
	}

	gdl = text0f153780(gdl);

	g_ScaleX = 1;

	return gdl;
}

void bgunAddBoost(s32 amount)
{
	g_Vars.speedpilltime += amount;

	if (g_Vars.speedpilltime > 5 * 60 * TICKS(60)) { // 5 minutes
		g_Vars.speedpilltime = 5 * 60 * TICKS(60);
	}

	if (!g_Vars.speedpillwant) {
		u32 sound = lvGetSlowMotionType() ? SFX_ARGH_JO_02AD : SFX_JO_BOOST_ACTIVATE;

		sndStart(var80095200, sound, 0, -1, -1, -1, -1, -1);
	}

	g_Vars.speedpillwant = true;
}

void bgunSubtractBoost(s32 amount)
{
	g_Vars.speedpilltime -= amount;

	if (g_Vars.speedpilltime <= 0) {
		g_Vars.speedpilltime = 0;
		g_Vars.speedpillwant = false;
	}
}

void bgunApplyBoost(void)
{
	if (lvGetSlowMotionType() != SLOWMOTION_OFF) {
		bgunSubtractBoost(TICKS(1200));
	} else {
		bgunAddBoost(TICKS(600));
	}
}

void bgunRevertBoost(void)
{
	if (lvGetSlowMotionType() != SLOWMOTION_OFF) {
		bgunAddBoost(TICKS(1200));
	} else {
		bgunSubtractBoost(TICKS(600));
	}
}

/**
 * The main tick function as called from lvTick.
 *
 * This function doesn't do much because it's called during both cutscenes and
 * gameplay, while most gun tick operations happen during gameplay only.
 * See bgunTickGameplay for that.
 */
void bgunTickBoost(void)
{
	if (g_Vars.speedpillon && g_Vars.speedpilltime > 0 && !g_Vars.in_cutscene) {
		g_Vars.speedpilltime -= g_Vars.lvupdate240_60;

		if (g_Vars.speedpilltime <= 0) {
			g_Vars.speedpilltime = 0;
			g_Vars.speedpillwant = false;
		}
	}
}

/**
 * gunsightoff is 0 if the full sight is visible, ie. player is holding R.
 *
 * Otherwise, gunsightoff holds bit values for reasons why the sight is off.
 * This is typically 2, which is GUNSIGHTREASON_NOTAIMING.
 *
 * If the visible argument is true, it removes the reason from the field, thus
 * making the sight visible if there are no other reasons.
 */
void bgunSetSightVisible(u32 reason, bool visible)
{
	if (visible) {
		g_Vars.currentplayer->gunsightoff &= ~reason;
		return;
	}

	g_Vars.currentplayer->gunsightoff |= reason;
}

Gfx *bgunDrawSight(Gfx *gdl)
{
	if (g_Vars.currentplayer->gunsightoff == 0 && !g_Vars.currentplayer->mpmenuon) {
		// Player is aiming with R
		gdl = sightDraw(gdl, true, currentPlayerGetSight());
	} else {
		gdl = sightDraw(gdl, false, currentPlayerGetSight());
	}

	return gdl;
}

void bgun0f0abd30(s32 handnum)
{
	struct player *player = g_Vars.currentplayer;
	struct hand *hand = &player->hands[handnum];
	struct gunctrl *gunctrl = &player->gunctrl;
	struct weapon *weapon = weaponFindById(hand->gset.weaponnum);
	s32 i;

	for (i = 0; i < 2; i++) {
		if (handnum == HAND_RIGHT) {
			gunctrl->ammotypes[i] = -1;
		}

		if (weapon && weapon->ammos[i]) {
			if (handnum == HAND_RIGHT) {
				gunctrl->ammotypes[i] = weapon->ammos[i]->type;
			}

			hand->clipsizes[i] = weapon->ammos[i]->clipsize;

			if (handnum == HAND_LEFT && hand->gset.weaponnum == WEAPON_REMOTEMINE) {
				hand->clipsizes[i] = 0;
			}

			hand->loadedammo[i] = 0;
		}
	}

	hand->upgrademult[0] = 1;
	hand->upgrademult[1] = 1;
	hand->finalmult[0] = 1;
	hand->finalmult[1] = 1;

	if (gunctrl->ammotypes[0] >= 0) {
		bgunResetAbmag(&hand->abmag);

		if (handnum == HAND_RIGHT) {
			bgunResetAbmag(&gunctrl->abmag);
		}

		gunctrl->lastmag = false;
	}
}
