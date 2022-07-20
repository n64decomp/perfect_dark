#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/debug.h"
#include "game/chr.h"
#include "game/prop.h"
#include "game/propsnd.h"
#include "game/atan2f.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/player.h"
#include "game/playermgr.h"
#include "game/bg.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/radar.h"
#include "game/bot.h"
#include "game/botcmd.h"
#include "game/botact.h"
#include "game/botinv.h"
#include "game/challenge.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pad.h"
#include "game/padhalllv.h"
#include "game/propobj.h"
#include "game/splat.h"
#include "bss.h"
#include "lib/model.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/anim.h"
#include "data.h"
#include "types.h"

#define PICKUPCRITERIA_DEFAULT  0
#define PICKUPCRITERIA_CRITICAL 1
#define PICKUPCRITERIA_ANY      2

struct chrdata *g_MpBotChrPtrs[MAX_BOTS];

u8 g_BotCount = 0;

struct botdifficulty g_BotDifficulties[] = {
	//           shootdelay
	//           |            unk04
	//           |            |                  unk08
	//           |            |                  |                  unk0c
	//           |            |                  |                  |             unk10
	//           |            |                  |                  |             |   unk14
	//           |            |                  |                  |             |   |                 unk18
	//           |            |                  |                  |             |   |                 |                  dizzyamount
	//           |            |                  |                  |             |   |                 |                  |
	/* meat */ { TICKS(90), 0.26175770163536,  0.52351540327072,  TICKS(600), 10, 0.69802051782608, 0.34901025891304,  TICKS(1000) },
	/* easy */ { TICKS(60), 0.12215359508991,  0.24430719017982,  TICKS(360), 10, 0.49733963608742, 0.13960410654545,  TICKS(1000) },
	/* norm */ { TICKS(30), 0.069802053272724, 0.13960410654545,  TICKS(180), 4,  0.34901025891304, 0.08725256472826,  TICKS(1500) },
	/* hard */ { TICKS(15), 0.026175770908594, 0.069802053272724, TICKS(90),  2,  0.24430719017982, 0.034901026636362, TICKS(2500) },
	/* perf */ { TICKS(0),  0,                 0.034901026636362, TICKS(45),  1,  0.17450512945652, 0,                 TICKS(4000) },
	/* dark */ { TICKS(0),  0,                 0,                 TICKS(0),   0,  0.13960410654545, 0,                 TICKS(4000) },
	{ 0 },
};

bool botIsDizzy(struct chrdata *chr)
{
	return chr->blurdrugamount >= g_BotDifficulties[chr->aibot->config->difficulty].dizzyamount;
}

void botReset(struct chrdata *chr, u8 respawning)
{
	s32 i;
	u32 rand;
	struct aibot *aibot = chr->aibot;

	if (aibot) {
		chr->fadealpha = -1;
		chr->chrflags &= ~CHRCFLAG_JUST_INJURED;
		chr->hidden &= ~CHRHFLAG_CLOAKED;
		chr->myaction = MA_AIBOTMAINLOOP;
		chr->shotbondsum = 0;

		if (respawning) {
			chr->numclosearghs = 0;
			chr->damage = 0;
			chr->target = -1;
			chr->chrpreset1 = -1;
			chr->cover = -1;
			chrSetShield(chr, 0);
			chr->cmnum = 0;
			chr->cmnum2 = 0;

#if VERSION >= VERSION_NTSC_1_0
			bgunFreeFireslot(chr->fireslots[0]);
			bgunFreeFireslot(chr->fireslots[1]);
#endif

			chr->unk32c_12 = 0;
			chr->fireslots[0] = -1;
			chr->fireslots[1] = -1;
			chr->firecount[0] = 0;
			chr->firecount[1] = 0;
			chr->weapons_held[0] = NULL;
			chr->weapons_held[1] = NULL;
			chr->weapons_held[2] = NULL;
			chr->liftaction = 0;
			chr->inlift = 0;
			chr->lift = NULL;
			chr->height = 185;

			for (i = 0; i < 33; i++) {
				aibot->ammoheld[i] = 0;
			}

			botinvClear(chr);

			aibot->weaponnum = WEAPON_UNARMED;
			aibot->gunfunc = FUNC_PRIMARY;
			aibot->iscloserangeweapon = true;
			aibot->loadedammo[0] = 0;
			aibot->loadedammo[1] = 0;
			aibot->gotoprop = NULL;
			aibot->timeuntilreload60[0] = 0;
			aibot->timeuntilreload60[1] = 0;
			aibot->nextbullettimer60[0] = 0;
			aibot->nextbullettimer60[1] = 0;
			aibot->distmode = -1;

#if VERSION < VERSION_PAL_BETA
			aibot->unk030 = 301;
#endif

			aibot->throwtimer60 = 0;
			aibot->burstsdone[0] = 0;
			aibot->burstsdone[1] = 0;
			aibot->skrocket = NULL;
			aibot->unk0a0 = 0;
			aibot->hasbriefcase = false;
			aibot->hascase = false;
			aibot->cloakdeviceenabled = false;
			aibot->rcp120cloakenabled = false;
			aibot->unk04c_04 = false;
			aibot->unk04c_03 = false;
			aibot->hasuplink = false;
			aibot->unk064 = 0;
			aibot->unk04c_00 = false;
			aibot->hillpadnum = -1;
			aibot->hillcovernum = -1;
			aibot->lastknownhill = -1;
			aibot->cyclonedischarging[1] = 0;
			aibot->cyclonedischarging[0] = 0;
			aibot->changeguntimer60 = 0;
			aibot->distmodettl60 = 0;
			aibot->forcemainloop = false;
			aibot->returntodefendtimer60 = 0;
			aibot->punchtimer60[HAND_LEFT] = -1;
			aibot->punchtimer60[HAND_RIGHT] = 0;
			aibot->reaperspeed[HAND_LEFT] = 0;
			aibot->reaperspeed[HAND_RIGHT] = 0;
			aibot->commandtimer60 = 0;
			aibot->shootdelaytimer60 = 0;
			aibot->targetlastseen60 = -1;
			aibot->lastseenanytarget60 = -1;
			aibot->targetinsight = 0;
			aibot->queryplayernum = 0;
			aibot->unk040 = 0;
			aibot->unk06c = 0;
			aibot->unk070 = 0;
			aibot->maulercharge[1] = 0;
			aibot->maulercharge[0] = 0;
			aibot->shotspeed.x = 0;
			aibot->shotspeed.y = 0;
			aibot->shotspeed.z = 0;

			for (i = 0; i != MAX_MPCHRS; i++) {
				aibot->chrnumsbydistanceasc[i] = -1;
				aibot->chrdistances[i] = U32_MAX;
				aibot->chrsinsight[i] = false;
				aibot->chrslastseen60[i] = -1;
				aibot->chrrooms[i] = -1;
			}

			aibot->waypoints[0] = NULL;
			aibot->unk208 = 0;
			aibot->random1 = random();
			aibot->random1ttl60 = 0;
			aibot->targetcloaktimer60 = 0;
			aibot->canseecloaked = 0;
			aibot->random2ttl60 = 0;
			aibot->unk2c4 = 0;

			aibot->random2 = random();
			aibot->randomfrac = RANDOMFRAC();
			aibot->cheap = 0;

#if VERSION >= VERSION_NTSC_1_0
			aibot->unk078 = 0;
			aibot->unk050 = 0;
			aibot->unk09d = 0;
#endif
		}

		if (aibot->config->type == BOTTYPE_TURTLE || aibot->config->type == BOTTYPE_SHIELD) {
			chr->cshield = 8;
		}

		if (aibot->config->difficulty == BOTDIFF_DARK) {
			aibot->unk064 &= ~1;

			if (mpHasShield()) {
				chr->cshield = 8;
			}
		}

		aibot->unk059 = 1;
		aibot->unk058 = TICKS(120);
	}
}

void botSpawn(struct chrdata *chr, u8 respawning)
{
	f32 thing;
	struct prop *prop;
	struct defaultobj *obj;
	struct aibot *aibot = chr->aibot;
	struct coord pos;
	s16 rooms[8];

	if (chr->prop) {
		prop = chr->prop->child;

		while (prop) {
			obj = prop->obj;

			if (obj) {
				obj->hidden |= OBJHFLAG_REAPABLE;
			}

			prop = prop->next;
		}
	}

	if (aibot) {
		botReset(chr, respawning);
		splatResetChr(chr);
		thing = scenarioChooseSpawnLocation(chr->radius, &pos, rooms, chr->prop);
		chr->hidden |= CHRHFLAG_00100000;
		chrMoveToPos(chr, &pos, rooms, thing, true);
		chr->aibot->unk0a4 = model0001ae44(chr->model);
		chr->aibot->angleoffset = 0;
		chr->aibot->speedtheta = 0;
		chr->aibot->unk0b0 = model0001ae44(chr->model);
		chr->aibot->unk0b4 = 0;
		chr->aibot->unk0b8 = 0;
		func0f02e9a0(chr, 0);
	}
}

void botSpawnAll(void)
{
	s32 i;

	for (i = 0; i < g_BotCount; i++) {
		botSpawn(g_MpBotChrPtrs[i], false);
	}
}

#if PIRACYCHECKS
u32 add87654321(u32 value)
{
	return value + 0x87654321;
}
#endif

#if VERSION >= VERSION_NTSC_1_0
u32 botPickupProp(struct prop *prop, struct chrdata *chr)
{
	struct defaultobj *obj = prop->obj;

	if (!chr || !chr->aibot) {
		return 0;
	}

	dprint();

	obj->flags3 &= ~OBJFLAG3_ISFETCHTARGET;

	switch (obj->type) {
	case OBJTYPE_KEY:
		// Missing break, but doesn't matter as keys don't exist in multiplayer
	case OBJTYPE_AMMOCRATE:
		{
			struct ammocrateobj *crate = (struct ammocrateobj *)prop->obj;
			u32 qty = ammocrateGetPickupAmmoQty((struct ammocrateobj *)prop->obj);
			dprint();

			if (qty) {
				botactGiveAmmoByType(chr->aibot, crate->ammotype, qty);
			}

			// Pickup sound
			propsnd0f0939f8(NULL, prop, SFX_PICKUP_AMMO, -1,
				-1, 1024, 0, 0, 0, -1, 0, -1, -1, -1, -1);

			objFree(obj, false, obj->hidden2 & OBJH2FLAG_CANREGEN);

			if (qty) {
				dprint();
			}
		}
		return 2;
	case OBJTYPE_MULTIAMMOCRATE:
		{
			struct multiammocrateobj *crate = (struct multiammocrateobj *)prop->obj;
			u32 padding[1];
			u32 qty;
			s32 i;
#if PIRACYCHECKS
			{
				u32 *ptr = (u32 *)&doorFinishClose;
				u32 *end = (u32 *)&doorSetMode;
				u32 checksum = 0;

				while (ptr < end) {
					checksum += *ptr;
					checksum *= 2;
					ptr++;
				}

				if (checksum != CHECKSUM_PLACEHOLDER) {
					u32 *ptr = (u32 *)chrCheckTargetInSight;
					ptr[0] = add87654321(0x24020001 - 0x87654321); // addiu v0,zero,1
					ptr[1] = add87654321(0x03e00008 - 0x87654321); // jr ra
					ptr[2] = add87654321(0x00000000 - 0x87654321); // nop
				}
			}
#endif
			dprint();

			for (i = 0; i != 19; i++) {
				qty = crate->slots[i].quantity;

				if (qty) {
					dprint();
				}

				if (qty) {
					botactGiveAmmoByType(chr->aibot, i + 1, qty);
				}
			}

			// Pickup sound
			propsnd0f0939f8(NULL, prop, SFX_PICKUP_AMMO, -1,
				-1, 1024, 0, 0, 0, -1, 0, -1, -1, -1, -1);

			objFree(obj, false, obj->hidden2 & OBJH2FLAG_CANREGEN);
		}
		return 2;
	case OBJTYPE_WEAPON:
		{
			struct weaponobj *weapon = prop->weapon;
			u32 itemtype = botinvGetItemType(chr, weapon->weaponnum);
			u32 result;
			u32 qty;

			if (weapon->weaponnum == WEAPON_BRIEFCASE2) {
				result = scenarioPickUpBriefcase(chr, prop);
			} else if (weapon->weaponnum == WEAPON_DATAUPLINK) {
				result = scenarioPickUpUplink(chr, prop);
			} else {
				propPlayPickupSound(prop, weapon->weaponnum);
				qty = weaponGetPickupAmmoQty(weapon);

				if (qty) {
					botactGiveAmmoByWeapon(chr->aibot, weapon->weaponnum, weapon->gunfunc, qty);
				}

				if (itemtype) {
					struct weapon *weapondef = weaponFindById(weapon->weaponnum);
					u32 originalpad = botinvGetWeaponPad(chr, weapon->weaponnum);
					u32 currentpad = obj->pad;

					if (itemtype == INVITEMTYPE_WEAP
							&& weapondef
							&& (weapondef->flags & WEAPONFLAG_DUALWIELD)
							&& originalpad != currentpad) {
						botinvGiveDualWeapon(chr, weapon->weaponnum);
						result = 1;
					} else {
						result = 2;
					}
				} else {
					botinvGiveProp(chr, prop);
					result = 1;
				}

				objFree(obj, false, obj->hidden2 & OBJH2FLAG_CANREGEN);
			}

			return result;
		}
	case OBJTYPE_SHIELD:
		{
			struct shieldobj *shield = (struct shieldobj *)prop->obj;

			propsnd0f0939f8(NULL, prop, SFX_PICKUP_SHIELD, -1,
				-1, 1024, 0, 0, 0, -1, 0, -1, -1, -1, -1);

			chrSetShield(chr, shield->amount * 8);
			objFree(obj, false, obj->hidden2 & OBJH2FLAG_CANREGEN);
		}
		return 3;
	case OBJTYPE_BASIC:
	case OBJTYPE_ALARM:
	case OBJTYPE_CCTV:
	case OBJTYPE_CHR:
	case OBJTYPE_SINGLEMONITOR:
	case OBJTYPE_MULTIMONITOR:
	case OBJTYPE_HANGINGMONITORS:
	case OBJTYPE_AUTOGUN:
	case OBJTYPE_LINKGUNS:
	case OBJTYPE_DEBRIS:
	case OBJTYPE_10:
	case OBJTYPE_HAT:
	case OBJTYPE_GRENADEPROB:
	case OBJTYPE_LINKLIFTDOOR:
	case OBJTYPE_TAG:
	case OBJTYPE_22:
	case OBJTYPE_BRIEFING:
	case OBJTYPE_GASBOTTLE:
	case OBJTYPE_RENAMEOBJ:
	case OBJTYPE_PADLOCKEDDOOR:
	case OBJTYPE_TRUCK:
	case OBJTYPE_HELI:
	case OBJTYPE_29:
	case OBJTYPE_GLASS:
	case OBJTYPE_SAFE:
	case OBJTYPE_SAFEITEM:
	case OBJTYPE_TANK:
	case OBJTYPE_CAMERAPOS:
	case OBJTYPE_TINTEDGLASS:
		break;
	}

	return 0;
}
#else
GLOBAL_ASM(
glabel botPickupProp
.late_rodata
glabel var7f1b33d0nb
.word botPickupProp+0x3ac
glabel var7f1b33d4nb
.word botPickupProp+0x080
glabel var7f1b33d8nb
.word botPickupProp+0x3ac
glabel var7f1b33dcnb
.word botPickupProp+0x3ac
glabel var7f1b33e0nb
.word botPickupProp+0x080
glabel var7f1b33e4nb
.word botPickupProp+0x1f4
glabel var7f1b33e8nb
.word botPickupProp+0x3ac
glabel var7f1b33ecnb
.word botPickupProp+0x3ac
glabel var7f1b33f0nb
.word botPickupProp+0x3ac
glabel var7f1b33f4nb
.word botPickupProp+0x3ac
glabel var7f1b33f8nb
.word botPickupProp+0x3ac
glabel var7f1b33fcnb
.word botPickupProp+0x3ac
glabel var7f1b3400nb
.word botPickupProp+0x3ac
glabel var7f1b3404nb
.word botPickupProp+0x3ac
glabel var7f1b3408nb
.word botPickupProp+0x3ac
glabel var7f1b340cnb
.word botPickupProp+0x3ac
glabel var7f1b3410nb
.word botPickupProp+0x3ac
glabel var7f1b3414nb
.word botPickupProp+0x130
glabel var7f1b3418nb
.word botPickupProp+0x314
glabel var7f1b341cnb
.word botPickupProp+0x3ac
glabel var7f1b3420nb
.word botPickupProp+0x3ac
glabel var7f1b3424nb
.word botPickupProp+0x3ac
glabel var7f1b3428nb
.word botPickupProp+0x3ac
glabel var7f1b342cnb
.word botPickupProp+0x3ac
glabel var7f1b3430nb
.word botPickupProp+0x3ac
glabel var7f1b3434nb
.word botPickupProp+0x3ac
glabel var7f1b3438nb
.word botPickupProp+0x3ac
glabel var7f1b343cnb
.word botPickupProp+0x3ac
glabel var7f1b3440nb
.word botPickupProp+0x3ac
glabel var7f1b3444nb
.word botPickupProp+0x3ac
glabel var7f1b3448nb
.word botPickupProp+0x3ac
glabel var7f1b344cnb
.word botPickupProp+0x3ac
glabel var7f1b3450nb
.word botPickupProp+0x3ac
glabel var7f1b3454nb
.word botPickupProp+0x3ac
glabel var7f1b3458nb
.word botPickupProp+0x3ac
glabel var7f1b345cnb
.word botPickupProp+0x3ac
glabel var7f1b3460nb
.word botPickupProp+0x3ac
glabel var7f1b3464nb
.word botPickupProp+0x3ac
glabel var7f1b3468nb
.word botPickupProp+0x3ac
glabel var7f1b346cnb
.word botPickupProp+0x3ac
glabel var7f1b3470nb
.word botPickupProp+0x3ac
glabel var7f1b3474nb
.word botPickupProp+0x3ac
glabel var7f1b3478nb
.word botPickupProp+0x3ac
glabel var7f1b347cnb
.word botPickupProp+0x3ac
glabel var7f1b3480nb
.word botPickupProp+0x3ac
.text
/*  f18a918:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f18a91c:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f18a920:	afb20050 */ 	sw	$s2,0x50($sp)
/*  f18a924:	afb1004c */ 	sw	$s1,0x4c($sp)
/*  f18a928:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f18a92c:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f18a930:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f18a934:	00a09025 */ 	or	$s2,$a1,$zero
/*  f18a938:	10a00004 */ 	beqz	$a1,.NB0f18a94c
/*  f18a93c:	afaf007c */ 	sw	$t7,0x7c($sp)
/*  f18a940:	8cb802d4 */ 	lw	$t8,0x2d4($a1)
/*  f18a944:	17000003 */ 	bnez	$t8,.NB0f18a954
/*  f18a948:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f18a94c:
/*  f18a94c:	100000de */ 	beqz	$zero,.NB0f18acc8
/*  f18a950:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18a954:
/*  f18a954:	0fc466bd */ 	jal	dprint
/*  f18a958:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a95c:	8fa2007c */ 	lw	$v0,0x7c($sp)
/*  f18a960:	2401bfff */ 	addiu	$at,$zero,-16385
/*  f18a964:	8c590010 */ 	lw	$t9,0x10($v0)
/*  f18a968:	90490003 */ 	lbu	$t1,0x3($v0)
/*  f18a96c:	03214024 */ 	and	$t0,$t9,$at
/*  f18a970:	252afffd */ 	addiu	$t2,$t1,-3
/*  f18a974:	2d41002d */ 	sltiu	$at,$t2,0x2d
/*  f18a978:	102000d2 */ 	beqz	$at,.NB0f18acc4
/*  f18a97c:	ac480010 */ 	sw	$t0,0x10($v0)
/*  f18a980:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f18a984:	3c017f1b */ 	lui	$at,0x7f1b
/*  f18a988:	002a0821 */ 	addu	$at,$at,$t2
/*  f18a98c:	8c2a33d0 */ 	lw	$t2,0x33d0($at)
/*  f18a990:	01400008 */ 	jr	$t2
/*  f18a994:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18a998:	8fab0080 */ 	lw	$t3,0x80($sp)
/*  f18a99c:	8d710004 */ 	lw	$s1,0x4($t3)
/*  f18a9a0:	0fc21a7e */ 	jal	ammocrateGetPickupAmmoQty
/*  f18a9a4:	02202025 */ 	or	$a0,$s1,$zero
/*  f18a9a8:	0fc466bd */ 	jal	dprint
/*  f18a9ac:	00408025 */ 	or	$s0,$v0,$zero
/*  f18a9b0:	12000004 */ 	beqz	$s0,.NB0f18a9c4
/*  f18a9b4:	02003025 */ 	or	$a2,$s0,$zero
/*  f18a9b8:	8e4402d4 */ 	lw	$a0,0x2d4($s2)
/*  f18a9bc:	0fc64fb5 */ 	jal	botactGiveAmmoByType
/*  f18a9c0:	8e25005c */ 	lw	$a1,0x5c($s1)
.NB0f18a9c4:
/*  f18a9c4:	3c01bf80 */ 	lui	$at,0xbf80
/*  f18a9c8:	44810000 */ 	mtc1	$at,$f0
/*  f18a9cc:	240cffff */ 	addiu	$t4,$zero,-1
/*  f18a9d0:	240d0400 */ 	addiu	$t5,$zero,0x400
/*  f18a9d4:	240effff */ 	addiu	$t6,$zero,-1
/*  f18a9d8:	afae002c */ 	sw	$t6,0x2c($sp)
/*  f18a9dc:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f18a9e0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f18a9e4:	00002025 */ 	or	$a0,$zero,$zero
/*  f18a9e8:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f18a9ec:	240600ea */ 	addiu	$a2,$zero,0xea
/*  f18a9f0:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f18a9f4:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f18a9f8:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f18a9fc:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f18aa00:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f18aa04:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f18aa08:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f18aa0c:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f18aa10:	0fc24762 */ 	jal	propsnd0f0939f8
/*  f18aa14:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f18aa18:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f18aa1c:	00002825 */ 	or	$a1,$zero,$zero
/*  f18aa20:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f18aa24:	30cf0004 */ 	andi	$t7,$a2,0x4
/*  f18aa28:	0fc1a7e4 */ 	jal	objFree
/*  f18aa2c:	01e03025 */ 	or	$a2,$t7,$zero
/*  f18aa30:	12000003 */ 	beqz	$s0,.NB0f18aa40
/*  f18aa34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aa38:	0fc466bd */ 	jal	dprint
/*  f18aa3c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f18aa40:
/*  f18aa40:	100000a1 */ 	beqz	$zero,.NB0f18acc8
/*  f18aa44:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f18aa48:	8fb80080 */ 	lw	$t8,0x80($sp)
/*  f18aa4c:	8f190004 */ 	lw	$t9,0x4($t8)
/*  f18aa50:	0fc466bd */ 	jal	dprint
/*  f18aa54:	afb90070 */ 	sw	$t9,0x70($sp)
/*  f18aa58:	00008025 */ 	or	$s0,$zero,$zero
/*  f18aa5c:	8fb10070 */ 	lw	$s1,0x70($sp)
.NB0f18aa60:
/*  f18aa60:	9626005e */ 	lhu	$a2,0x5e($s1)
/*  f18aa64:	10c00004 */ 	beqz	$a2,.NB0f18aa78
/*  f18aa68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aa6c:	0fc466bd */ 	jal	dprint
/*  f18aa70:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f18aa74:	8fa60068 */ 	lw	$a2,0x68($sp)
.NB0f18aa78:
/*  f18aa78:	10c00003 */ 	beqz	$a2,.NB0f18aa88
/*  f18aa7c:	26050001 */ 	addiu	$a1,$s0,0x1
/*  f18aa80:	0fc64fb5 */ 	jal	botactGiveAmmoByType
/*  f18aa84:	8e4402d4 */ 	lw	$a0,0x2d4($s2)
.NB0f18aa88:
/*  f18aa88:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f18aa8c:	24010013 */ 	addiu	$at,$zero,0x13
/*  f18aa90:	1601fff3 */ 	bne	$s0,$at,.NB0f18aa60
/*  f18aa94:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f18aa98:	3c01bf80 */ 	lui	$at,0xbf80
/*  f18aa9c:	44810000 */ 	mtc1	$at,$f0
/*  f18aaa0:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f18aaa4:	24090400 */ 	addiu	$t1,$zero,0x400
/*  f18aaa8:	240affff */ 	addiu	$t2,$zero,-1
/*  f18aaac:	afaa002c */ 	sw	$t2,0x2c($sp)
/*  f18aab0:	afa90014 */ 	sw	$t1,0x14($sp)
/*  f18aab4:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f18aab8:	00002025 */ 	or	$a0,$zero,$zero
/*  f18aabc:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f18aac0:	240600ea */ 	addiu	$a2,$zero,0xea
/*  f18aac4:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f18aac8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f18aacc:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f18aad0:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f18aad4:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f18aad8:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f18aadc:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f18aae0:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f18aae4:	0fc24762 */ 	jal	propsnd0f0939f8
/*  f18aae8:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f18aaec:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f18aaf0:	00002825 */ 	or	$a1,$zero,$zero
/*  f18aaf4:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f18aaf8:	30cc0004 */ 	andi	$t4,$a2,0x4
/*  f18aafc:	0fc1a7e4 */ 	jal	objFree
/*  f18ab00:	01803025 */ 	or	$a2,$t4,$zero
/*  f18ab04:	10000070 */ 	beqz	$zero,.NB0f18acc8
/*  f18ab08:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f18ab0c:	8fad0080 */ 	lw	$t5,0x80($sp)
/*  f18ab10:	02402025 */ 	or	$a0,$s2,$zero
/*  f18ab14:	8db00004 */ 	lw	$s0,0x4($t5)
/*  f18ab18:	0fc64788 */ 	jal	botinvGetItemType
/*  f18ab1c:	9205005c */ 	lbu	$a1,0x5c($s0)
/*  f18ab20:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f18ab24:	9205005c */ 	lbu	$a1,0x5c($s0)
/*  f18ab28:	24010056 */ 	addiu	$at,$zero,0x56
/*  f18ab2c:	02402025 */ 	or	$a0,$s2,$zero
/*  f18ab30:	54a10006 */ 	bnel	$a1,$at,.NB0f18ab4c
/*  f18ab34:	24010036 */ 	addiu	$at,$zero,0x36
/*  f18ab38:	0fc60340 */ 	jal	scenarioPickUpBriefcase
/*  f18ab3c:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f18ab40:	10000062 */ 	beqz	$zero,.NB0f18accc
/*  f18ab44:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f18ab48:	24010036 */ 	addiu	$at,$zero,0x36
.NB0f18ab4c:
/*  f18ab4c:	14a10005 */ 	bne	$a1,$at,.NB0f18ab64
/*  f18ab50:	02402025 */ 	or	$a0,$s2,$zero
/*  f18ab54:	0fc60612 */ 	jal	scenarioPickUpUplink
/*  f18ab58:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f18ab5c:	1000005b */ 	beqz	$zero,.NB0f18accc
/*  f18ab60:	8fbf0054 */ 	lw	$ra,0x54($sp)
.NB0f18ab64:
/*  f18ab64:	0fc2191a */ 	jal	propPlayPickupSound
/*  f18ab68:	8fa40080 */ 	lw	$a0,0x80($sp)
/*  f18ab6c:	0fc21aac */ 	jal	weaponGetPickupAmmoQty
/*  f18ab70:	02002025 */ 	or	$a0,$s0,$zero
/*  f18ab74:	10400005 */ 	beqz	$v0,.NB0f18ab8c
/*  f18ab78:	00403825 */ 	or	$a3,$v0,$zero
/*  f18ab7c:	8e4402d4 */ 	lw	$a0,0x2d4($s2)
/*  f18ab80:	9205005c */ 	lbu	$a1,0x5c($s0)
/*  f18ab84:	0fc64f87 */ 	jal	botactGiveAmmoByWeapon
/*  f18ab88:	9206005f */ 	lbu	$a2,0x5f($s0)
.NB0f18ab8c:
/*  f18ab8c:	8fae005c */ 	lw	$t6,0x5c($sp)
/*  f18ab90:	02402025 */ 	or	$a0,$s2,$zero
/*  f18ab94:	11c0001a */ 	beqz	$t6,.NB0f18ac00
/*  f18ab98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ab9c:	0fc2bb4c */ 	jal	weaponFindById
/*  f18aba0:	9204005c */ 	lbu	$a0,0x5c($s0)
/*  f18aba4:	00408825 */ 	or	$s1,$v0,$zero
/*  f18aba8:	02402025 */ 	or	$a0,$s2,$zero
/*  f18abac:	0fc647c4 */ 	jal	botinvGetWeaponPad
/*  f18abb0:	9205005c */ 	lbu	$a1,0x5c($s0)
/*  f18abb4:	8fb8005c */ 	lw	$t8,0x5c($sp)
/*  f18abb8:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f18abbc:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18abc0:	1701000d */ 	bne	$t8,$at,.NB0f18abf8
/*  f18abc4:	85e30006 */ 	lh	$v1,0x6($t7)
/*  f18abc8:	1220000b */ 	beqz	$s1,.NB0f18abf8
/*  f18abcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18abd0:	8e39004c */ 	lw	$t9,0x4c($s1)
/*  f18abd4:	33281000 */ 	andi	$t0,$t9,0x1000
/*  f18abd8:	11000007 */ 	beqz	$t0,.NB0f18abf8
/*  f18abdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18abe0:	10430005 */ 	beq	$v0,$v1,.NB0f18abf8
/*  f18abe4:	02402025 */ 	or	$a0,$s2,$zero
/*  f18abe8:	0fc647b9 */ 	jal	botinvGiveDualWeapon
/*  f18abec:	9205005c */ 	lbu	$a1,0x5c($s0)
/*  f18abf0:	10000006 */ 	beqz	$zero,.NB0f18ac0c
/*  f18abf4:	24100001 */ 	addiu	$s0,$zero,0x1
.NB0f18abf8:
/*  f18abf8:	10000004 */ 	beqz	$zero,.NB0f18ac0c
/*  f18abfc:	24100002 */ 	addiu	$s0,$zero,0x2
.NB0f18ac00:
/*  f18ac00:	0fc647d3 */ 	jal	botinvGiveProp
/*  f18ac04:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f18ac08:	24100001 */ 	addiu	$s0,$zero,0x1
.NB0f18ac0c:
/*  f18ac0c:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f18ac10:	00002825 */ 	or	$a1,$zero,$zero
/*  f18ac14:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f18ac18:	30ca0004 */ 	andi	$t2,$a2,0x4
/*  f18ac1c:	0fc1a7e4 */ 	jal	objFree
/*  f18ac20:	01403025 */ 	or	$a2,$t2,$zero
/*  f18ac24:	10000028 */ 	beqz	$zero,.NB0f18acc8
/*  f18ac28:	02001025 */ 	or	$v0,$s0,$zero
/*  f18ac2c:	8fa50080 */ 	lw	$a1,0x80($sp)
/*  f18ac30:	3c01bf80 */ 	lui	$at,0xbf80
/*  f18ac34:	44810000 */ 	mtc1	$at,$f0
/*  f18ac38:	8cb00004 */ 	lw	$s0,0x4($a1)
/*  f18ac3c:	240bffff */ 	addiu	$t3,$zero,-1
/*  f18ac40:	240c0400 */ 	addiu	$t4,$zero,0x400
/*  f18ac44:	240dffff */ 	addiu	$t5,$zero,-1
/*  f18ac48:	afad002c */ 	sw	$t5,0x2c($sp)
/*  f18ac4c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f18ac50:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f18ac54:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f18ac58:	afa00020 */ 	sw	$zero,0x20($sp)
/*  f18ac5c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f18ac60:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f18ac64:	00002025 */ 	or	$a0,$zero,$zero
/*  f18ac68:	240601cd */ 	addiu	$a2,$zero,0x1cd
/*  f18ac6c:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f18ac70:	e7a00038 */ 	swc1	$f0,0x38($sp)
/*  f18ac74:	e7a00034 */ 	swc1	$f0,0x34($sp)
/*  f18ac78:	e7a00030 */ 	swc1	$f0,0x30($sp)
/*  f18ac7c:	0fc24762 */ 	jal	propsnd0f0939f8
/*  f18ac80:	e7a00024 */ 	swc1	$f0,0x24($sp)
/*  f18ac84:	3c014100 */ 	lui	$at,0x4100
/*  f18ac88:	44813000 */ 	mtc1	$at,$f6
/*  f18ac8c:	c6040060 */ 	lwc1	$f4,0x60($s0)
/*  f18ac90:	02402025 */ 	or	$a0,$s2,$zero
/*  f18ac94:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f18ac98:	44054000 */ 	mfc1	$a1,$f8
/*  f18ac9c:	0fc0ce2c */ 	jal	chrSetShield
/*  f18aca0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18aca4:	8fa4007c */ 	lw	$a0,0x7c($sp)
/*  f18aca8:	00002825 */ 	or	$a1,$zero,$zero
/*  f18acac:	90860002 */ 	lbu	$a2,0x2($a0)
/*  f18acb0:	30ce0004 */ 	andi	$t6,$a2,0x4
/*  f18acb4:	0fc1a7e4 */ 	jal	objFree
/*  f18acb8:	01c03025 */ 	or	$a2,$t6,$zero
/*  f18acbc:	10000002 */ 	beqz	$zero,.NB0f18acc8
/*  f18acc0:	24020003 */ 	addiu	$v0,$zero,0x3
.NB0f18acc4:
/*  f18acc4:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18acc8:
/*  f18acc8:	8fbf0054 */ 	lw	$ra,0x54($sp)
.NB0f18accc:
/*  f18accc:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f18acd0:	8fb1004c */ 	lw	$s1,0x4c($sp)
/*  f18acd4:	8fb20050 */ 	lw	$s2,0x50($sp)
/*  f18acd8:	03e00008 */ 	jr	$ra
/*  f18acdc:	27bd0080 */ 	addiu	$sp,$sp,0x80
);
#endif

#if VERSION >= VERSION_NTSC_1_0
GLOBAL_ASM(
glabel botTestPropForPickup
.late_rodata
glabel var7f1b8ea4
.word 0x47742400
glabel var7f1b8ea8
.word 0x461c4000
.text
/*  f190be4:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f190be8:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f190bec:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f190bf0:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f190bf4:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f190bf8:	10a0000d */ 	beqz	$a1,.L0f190c30
/*  f190bfc:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f190c00:	8cb802d4 */ 	lw	$t8,0x2d4($a1)
/*  f190c04:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x31c)
/*  f190c08:	13000009 */ 	beqz	$t8,.L0f190c30
/*  f190c0c:	00000000 */ 	nop
/*  f190c10:	8f39a2dc */ 	lw	$t9,%lo(g_Vars+0x31c)($t9)
/*  f190c14:	00a02025 */ 	or	$a0,$a1,$zero
/*  f190c18:	13200005 */ 	beqz	$t9,.L0f190c30
/*  f190c1c:	00000000 */ 	nop
/*  f190c20:	0fc0e6a5 */ 	jal	chrIsDead
/*  f190c24:	afa5008c */ 	sw	$a1,0x8c($sp)
/*  f190c28:	10400003 */ 	beqz	$v0,.L0f190c38
/*  f190c2c:	00000000 */ 	nop
.L0f190c30:
/*  f190c30:	10000153 */ 	b	.L0f191180
/*  f190c34:	00001025 */ 	or	$v0,$zero,$zero
.L0f190c38:
/*  f190c38:	0fc47bba */ 	jal	dprint
/*  f190c3c:	00000000 */ 	nop
/*  f190c40:	8fa80088 */ 	lw	$t0,0x88($sp)
/*  f190c44:	85090002 */ 	lh	$t1,0x2($t0)
/*  f190c48:	11200003 */ 	beqz	$t1,.L0f190c58
/*  f190c4c:	00000000 */ 	nop
/*  f190c50:	1000014b */ 	b	.L0f191180
/*  f190c54:	00001025 */ 	or	$v0,$zero,$zero
.L0f190c58:
/*  f190c58:	0fc21465 */ 	jal	func0f085194
/*  f190c5c:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f190c60:	5040000d */ 	beqzl	$v0,.L0f190c98
/*  f190c64:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f190c68:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f190c6c:	24010011 */ 	addiu	$at,$zero,0x11
/*  f190c70:	904a0003 */ 	lbu	$t2,0x3($v0)
/*  f190c74:	51410008 */ 	beql	$t2,$at,.L0f190c98
/*  f190c78:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f190c7c:	8c4b0008 */ 	lw	$t3,0x8($v0)
/*  f190c80:	000b62c0 */ 	sll	$t4,$t3,0xb
/*  f190c84:	0581000a */ 	bgez	$t4,.L0f190cb0
/*  f190c88:	00000000 */ 	nop
/*  f190c8c:	1000013c */ 	b	.L0f191180
/*  f190c90:	00001025 */ 	or	$v0,$zero,$zero
/*  f190c94:	8fa20084 */ 	lw	$v0,0x84($sp)
.L0f190c98:
/*  f190c98:	8c4d0008 */ 	lw	$t5,0x8($v0)
/*  f190c9c:	000d7340 */ 	sll	$t6,$t5,0xd
/*  f190ca0:	05c00003 */ 	bltz	$t6,.L0f190cb0
/*  f190ca4:	00000000 */ 	nop
/*  f190ca8:	10000135 */ 	b	.L0f191180
/*  f190cac:	00001025 */ 	or	$v0,$zero,$zero
.L0f190cb0:
/*  f190cb0:	0fc47bba */ 	jal	dprint
/*  f190cb4:	00000000 */ 	nop
/*  f190cb8:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f190cbc:	8c4f0040 */ 	lw	$t7,0x40($v0)
/*  f190cc0:	31f80004 */ 	andi	$t8,$t7,0x4
/*  f190cc4:	17000005 */ 	bnez	$t8,.L0f190cdc
/*  f190cc8:	00000000 */ 	nop
/*  f190ccc:	8c590008 */ 	lw	$t9,0x8($v0)
/*  f190cd0:	00194300 */ 	sll	$t0,$t9,0xc
/*  f190cd4:	05010003 */ 	bgez	$t0,.L0f190ce4
/*  f190cd8:	00000000 */ 	nop
.L0f190cdc:
/*  f190cdc:	10000128 */ 	b	.L0f191180
/*  f190ce0:	00001025 */ 	or	$v0,$zero,$zero
.L0f190ce4:
/*  f190ce4:	0fc47bba */ 	jal	dprint
/*  f190ce8:	00000000 */ 	nop
/*  f190cec:	8fa30084 */ 	lw	$v1,0x84($sp)
/*  f190cf0:	8c690040 */ 	lw	$t1,0x40($v1)
/*  f190cf4:	312a0080 */ 	andi	$t2,$t1,0x80
/*  f190cf8:	1140000c */ 	beqz	$t2,.L0f190d2c
/*  f190cfc:	00000000 */ 	nop
/*  f190d00:	8c620048 */ 	lw	$v0,0x48($v1)
/*  f190d04:	10400009 */ 	beqz	$v0,.L0f190d2c
/*  f190d08:	00000000 */ 	nop
/*  f190d0c:	8c4b00b4 */ 	lw	$t3,0xb4($v0)
/*  f190d10:	19600006 */ 	blez	$t3,.L0f190d2c
/*  f190d14:	00000000 */ 	nop
/*  f190d18:	8c4c0090 */ 	lw	$t4,0x90($v0)
/*  f190d1c:	15800003 */ 	bnez	$t4,.L0f190d2c
/*  f190d20:	00000000 */ 	nop
/*  f190d24:	10000116 */ 	b	.L0f191180
/*  f190d28:	00001025 */ 	or	$v0,$zero,$zero
.L0f190d2c:
/*  f190d2c:	0fc47bba */ 	jal	dprint
/*  f190d30:	00000000 */ 	nop
/*  f190d34:	0fc19990 */ 	jal	objCanPickupFromSafe
/*  f190d38:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f190d3c:	14400003 */ 	bnez	$v0,.L0f190d4c
/*  f190d40:	00000000 */ 	nop
/*  f190d44:	1000010e */ 	b	.L0f191180
/*  f190d48:	00001025 */ 	or	$v0,$zero,$zero
.L0f190d4c:
/*  f190d4c:	0fc47bba */ 	jal	dprint
/*  f190d50:	00000000 */ 	nop
/*  f190d54:	8fad0084 */ 	lw	$t5,0x84($sp)
/*  f190d58:	24010008 */ 	addiu	$at,$zero,0x8
/*  f190d5c:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f190d60:	91a20003 */ 	lbu	$v0,0x3($t5)
/*  f190d64:	5441003c */ 	bnel	$v0,$at,.L0f190e58
/*  f190d68:	24010007 */ 	addiu	$at,$zero,0x7
/*  f190d6c:	8dc20004 */ 	lw	$v0,0x4($t6)
/*  f190d70:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f190d74:	9045005c */ 	lbu	$a1,0x5c($v0)
/*  f190d78:	0fc65f90 */ 	jal	botinvGetItemType
/*  f190d7c:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f190d80:	8faf0080 */ 	lw	$t7,0x80($sp)
/*  f190d84:	91e4005c */ 	lbu	$a0,0x5c($t7)
/*  f190d88:	0fc2c3f4 */ 	jal	weaponFindById
/*  f190d8c:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f190d90:	0002282b */ 	sltu	$a1,$zero,$v0
/*  f190d94:	10a00004 */ 	beqz	$a1,.L0f190da8
/*  f190d98:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f190d9c:	8c45004c */ 	lw	$a1,0x4c($v0)
/*  f190da0:	30b81000 */ 	andi	$t8,$a1,0x1000
/*  f190da4:	2f050001 */ 	sltiu	$a1,$t8,0x1
.L0f190da8:
/*  f190da8:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f190dac:	24010057 */ 	addiu	$at,$zero,0x57
/*  f190db0:	9050005c */ 	lbu	$s0,0x5c($v0)
/*  f190db4:	1201009b */ 	beq	$s0,$at,.L0f191024
/*  f190db8:	24010003 */ 	addiu	$at,$zero,0x3
/*  f190dbc:	10c10006 */ 	beq	$a2,$at,.L0f190dd8
/*  f190dc0:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f190dc4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f190dc8:	54c10015 */ 	bnel	$a2,$at,.L0f190e20
/*  f190dcc:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f190dd0:	50a00013 */ 	beqzl	$a1,.L0f190e20
/*  f190dd4:	8fa20080 */ 	lw	$v0,0x80($sp)
.L0f190dd8:
/*  f190dd8:	8d0402d4 */ 	lw	$a0,0x2d4($t0)
/*  f190ddc:	02002825 */ 	or	$a1,$s0,$zero
/*  f190de0:	9046005f */ 	lbu	$a2,0x5f($v0)
/*  f190de4:	0fc666f9 */ 	jal	botactGetAmmoQuantityByWeapon
/*  f190de8:	00003825 */ 	or	$a3,$zero,$zero
/*  f190dec:	8fa90080 */ 	lw	$t1,0x80($sp)
/*  f190df0:	00408025 */ 	or	$s0,$v0,$zero
/*  f190df4:	9124005c */ 	lbu	$a0,0x5c($t1)
/*  f190df8:	0fc6666c */ 	jal	botactGetAmmoTypeByFunction
/*  f190dfc:	9125005f */ 	lbu	$a1,0x5f($t1)
/*  f190e00:	0fc2a63d */ 	jal	bgunGetCapacityByAmmotype
/*  f190e04:	00402025 */ 	or	$a0,$v0,$zero
/*  f190e08:	0202082a */ 	slt	$at,$s0,$v0
/*  f190e0c:	54200004 */ 	bnezl	$at,.L0f190e20
/*  f190e10:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f190e14:	100000da */ 	b	.L0f191180
/*  f190e18:	00001025 */ 	or	$v0,$zero,$zero
/*  f190e1c:	8fa20080 */ 	lw	$v0,0x80($sp)
.L0f190e20:
/*  f190e20:	24010053 */ 	addiu	$at,$zero,0x53
/*  f190e24:	8faa0084 */ 	lw	$t2,0x84($sp)
/*  f190e28:	9050005c */ 	lbu	$s0,0x5c($v0)
/*  f190e2c:	12010003 */ 	beq	$s0,$at,.L0f190e3c
/*  f190e30:	24010054 */ 	addiu	$at,$zero,0x54
/*  f190e34:	5601007c */ 	bnel	$s0,$at,.L0f191028
/*  f190e38:	8fa9008c */ 	lw	$t1,0x8c($sp)
.L0f190e3c:
/*  f190e3c:	8d4b0040 */ 	lw	$t3,0x40($t2)
/*  f190e40:	316c0080 */ 	andi	$t4,$t3,0x80
/*  f190e44:	51800078 */ 	beqzl	$t4,.L0f191028
/*  f190e48:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f190e4c:	100000cc */ 	b	.L0f191180
/*  f190e50:	00001025 */ 	or	$v0,$zero,$zero
/*  f190e54:	24010007 */ 	addiu	$at,$zero,0x7
.L0f190e58:
/*  f190e58:	14410010 */ 	bne	$v0,$at,.L0f190e9c
/*  f190e5c:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f190e60:	8db00004 */ 	lw	$s0,0x4($t5)
/*  f190e64:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f190e68:	00003025 */ 	or	$a2,$zero,$zero
/*  f190e6c:	8e05005c */ 	lw	$a1,0x5c($s0)
/*  f190e70:	0fc6672e */ 	jal	botactGetAmmoQuantityByType
/*  f190e74:	8dc402d4 */ 	lw	$a0,0x2d4($t6)
/*  f190e78:	8e04005c */ 	lw	$a0,0x5c($s0)
/*  f190e7c:	0fc2a63d */ 	jal	bgunGetCapacityByAmmotype
/*  f190e80:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f190e84:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f190e88:	00a2082a */ 	slt	$at,$a1,$v0
/*  f190e8c:	54200066 */ 	bnezl	$at,.L0f191028
/*  f190e90:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f190e94:	100000ba */ 	b	.L0f191180
/*  f190e98:	00001025 */ 	or	$v0,$zero,$zero
.L0f190e9c:
/*  f190e9c:	24010014 */ 	addiu	$at,$zero,0x14
/*  f190ea0:	1441003d */ 	bne	$v0,$at,.L0f190f98
/*  f190ea4:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f190ea8:	8df00004 */ 	lw	$s0,0x4($t7)
/*  f190eac:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f190eb0:	afb80064 */ 	sw	$t8,0x64($sp)
/*  f190eb4:	0fc1a1ee */ 	jal	objGetDestroyedLevel
/*  f190eb8:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f190ebc:	10400005 */ 	beqz	$v0,.L0f190ed4
/*  f190ec0:	02001825 */ 	or	$v1,$s0,$zero
/*  f190ec4:	0fc47bba */ 	jal	dprint
/*  f190ec8:	00000000 */ 	nop
/*  f190ecc:	100000ac */ 	b	.L0f191180
/*  f190ed0:	00001025 */ 	or	$v0,$zero,$zero
.L0f190ed4:
/*  f190ed4:	00001025 */ 	or	$v0,$zero,$zero
.L0f190ed8:
/*  f190ed8:	24500001 */ 	addiu	$s0,$v0,0x1
/*  f190edc:	02002025 */ 	or	$a0,$s0,$zero
/*  f190ee0:	0fc668c7 */ 	jal	botactGetWeaponByAmmoType
/*  f190ee4:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f190ee8:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f190eec:	afa20068 */ 	sw	$v0,0x68($sp)
/*  f190ef0:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f190ef4:	9479005e */ 	lhu	$t9,0x5e($v1)
/*  f190ef8:	02002825 */ 	or	$a1,$s0,$zero
/*  f190efc:	00003025 */ 	or	$a2,$zero,$zero
/*  f190f00:	5b20001d */ 	blezl	$t9,.L0f190f78
/*  f190f04:	24010013 */ 	addiu	$at,$zero,0x13
/*  f190f08:	8d0402d4 */ 	lw	$a0,0x2d4($t0)
/*  f190f0c:	0fc6672e */ 	jal	botactGetAmmoQuantityByType
/*  f190f10:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f190f14:	02002025 */ 	or	$a0,$s0,$zero
/*  f190f18:	0fc2a63d */ 	jal	bgunGetCapacityByAmmotype
/*  f190f1c:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f190f20:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f190f24:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f190f28:	00a2082a */ 	slt	$at,$a1,$v0
/*  f190f2c:	50200012 */ 	beqzl	$at,.L0f190f78
/*  f190f30:	24010013 */ 	addiu	$at,$zero,0x13
/*  f190f34:	8fa90068 */ 	lw	$t1,0x68($sp)
/*  f190f38:	afa00064 */ 	sw	$zero,0x64($sp)
/*  f190f3c:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f190f40:	51200011 */ 	beqzl	$t1,.L0f190f88
/*  f190f44:	8faa0064 */ 	lw	$t2,0x64($sp)
/*  f190f48:	0fc65f90 */ 	jal	botinvGetItemType
/*  f190f4c:	01202825 */ 	or	$a1,$t1,$zero
/*  f190f50:	5440000d */ 	bnezl	$v0,.L0f190f88
/*  f190f54:	8faa0064 */ 	lw	$t2,0x64($sp)
/*  f190f58:	0fc47bba */ 	jal	dprint
/*  f190f5c:	00000000 */ 	nop
/*  f190f60:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f190f64:	0fc65fdb */ 	jal	botinvGiveProp
/*  f190f68:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f190f6c:	10000006 */ 	b	.L0f190f88
/*  f190f70:	8faa0064 */ 	lw	$t2,0x64($sp)
/*  f190f74:	24010013 */ 	addiu	$at,$zero,0x13
.L0f190f78:
/*  f190f78:	02001025 */ 	or	$v0,$s0,$zero
/*  f190f7c:	1601ffd6 */ 	bne	$s0,$at,.L0f190ed8
/*  f190f80:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f190f84:	8faa0064 */ 	lw	$t2,0x64($sp)
.L0f190f88:
/*  f190f88:	51400027 */ 	beqzl	$t2,.L0f191028
/*  f190f8c:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f190f90:	1000007b */ 	b	.L0f191180
/*  f190f94:	00001025 */ 	or	$v0,$zero,$zero
.L0f190f98:
/*  f190f98:	24010015 */ 	addiu	$at,$zero,0x15
/*  f190f9c:	14410021 */ 	bne	$v0,$at,.L0f191024
/*  f190fa0:	8fab0088 */ 	lw	$t3,0x88($sp)
/*  f190fa4:	8d6c0004 */ 	lw	$t4,0x4($t3)
/*  f190fa8:	00008025 */ 	or	$s0,$zero,$zero
/*  f190fac:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f190fb0:	0fc0cfe8 */ 	jal	chrGetShield
/*  f190fb4:	afac0058 */ 	sw	$t4,0x58($sp)
/*  f190fb8:	3c013e00 */ 	lui	$at,0x3e00
/*  f190fbc:	44812000 */ 	mtc1	$at,$f4
/*  f190fc0:	8fad0058 */ 	lw	$t5,0x58($sp)
/*  f190fc4:	3c0e800b */ 	lui	$t6,%hi(g_MpSetup+0x10)
/*  f190fc8:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f190fcc:	c5a80060 */ 	lwc1	$f8,0x60($t5)
/*  f190fd0:	4606403e */ 	c.le.s	$f8,$f6
/*  f190fd4:	00000000 */ 	nop
/*  f190fd8:	45000003 */ 	bc1f	.L0f190fe8
/*  f190fdc:	00000000 */ 	nop
/*  f190fe0:	1000000c */ 	b	.L0f191014
/*  f190fe4:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f190fe8:
/*  f190fe8:	91cecb98 */ 	lbu	$t6,%lo(g_MpSetup+0x10)($t6)
/*  f190fec:	24010001 */ 	addiu	$at,$zero,0x1
/*  f190ff0:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f190ff4:	15c10007 */ 	bne	$t6,$at,.L0f191014
/*  f190ff8:	00000000 */ 	nop
/*  f190ffc:	8df802d4 */ 	lw	$t8,0x2d4($t7)
/*  f191000:	8f19009c */ 	lw	$t9,0x9c($t8)
/*  f191004:	001947c2 */ 	srl	$t0,$t9,0x1f
/*  f191008:	11000002 */ 	beqz	$t0,.L0f191014
/*  f19100c:	00000000 */ 	nop
/*  f191010:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f191014:
/*  f191014:	52000004 */ 	beqzl	$s0,.L0f191028
/*  f191018:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f19101c:	10000058 */ 	b	.L0f191180
/*  f191020:	00001025 */ 	or	$v0,$zero,$zero
.L0f191024:
/*  f191024:	8fa9008c */ 	lw	$t1,0x8c($sp)
.L0f191028:
/*  f191028:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f19102c:	8d30001c */ 	lw	$s0,0x1c($t1)
/*  f191030:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f191034:	c452000c */ 	lwc1	$f18,0xc($v0)
/*  f191038:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f19103c:	c6100008 */ 	lwc1	$f16,0x8($s0)
/*  f191040:	c604000c */ 	lwc1	$f4,0xc($s0)
/*  f191044:	c6080010 */ 	lwc1	$f8,0x10($s0)
/*  f191048:	46105081 */ 	sub.s	$f2,$f10,$f16
/*  f19104c:	46049301 */ 	sub.s	$f12,$f18,$f4
/*  f191050:	e7a2004c */ 	swc1	$f2,0x4c($sp)
/*  f191054:	46083381 */ 	sub.s	$f14,$f6,$f8
/*  f191058:	e7ac0048 */ 	swc1	$f12,0x48($sp)
/*  f19105c:	0fc47bba */ 	jal	dprint
/*  f191060:	e7ae0044 */ 	swc1	$f14,0x44($sp)
/*  f191064:	c7a2004c */ 	lwc1	$f2,0x4c($sp)
/*  f191068:	8faa008c */ 	lw	$t2,0x8c($sp)
/*  f19106c:	c7ae0044 */ 	lwc1	$f14,0x44($sp)
/*  f191070:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f191074:	8d4b02d4 */ 	lw	$t3,0x2d4($t2)
/*  f191078:	c7ac0048 */ 	lwc1	$f12,0x48($sp)
/*  f19107c:	460e7402 */ 	mul.s	$f16,$f14,$f14
/*  f191080:	916c009c */ 	lbu	$t4,0x9c($t3)
/*  f191084:	3c017f1c */ 	lui	$at,%hi(var7f1b8ea4)
/*  f191088:	318d0001 */ 	andi	$t5,$t4,0x1
/*  f19108c:	11a00004 */ 	beqz	$t5,.L0f1910a0
/*  f191090:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f191094:	3c017f1c */ 	lui	$at,%hi(var7f1b8ea8)
/*  f191098:	10000002 */ 	b	.L0f1910a4
/*  f19109c:	c4208ea4 */ 	lwc1	$f0,%lo(var7f1b8ea4)($at)
.L0f1910a0:
/*  f1910a0:	c4208ea8 */ 	lwc1	$f0,%lo(var7f1b8ea8)($at)
.L0f1910a4:
/*  f1910a4:	4600903e */ 	c.le.s	$f18,$f0
/*  f1910a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1910ac:	3c01c348 */ 	lui	$at,0xc348
/*  f1910b0:	45000002 */ 	bc1f	.L0f1910bc
/*  f1910b4:	00000000 */ 	nop
/*  f1910b8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1910bc:
/*  f1910bc:	10400012 */ 	beqz	$v0,.L0f191108
/*  f1910c0:	00402825 */ 	or	$a1,$v0,$zero
/*  f1910c4:	44812000 */ 	mtc1	$at,$f4
/*  f1910c8:	3c014348 */ 	lui	$at,0x4348
/*  f1910cc:	00001025 */ 	or	$v0,$zero,$zero
/*  f1910d0:	460c203e */ 	c.le.s	$f4,$f12
/*  f1910d4:	00000000 */ 	nop
/*  f1910d8:	45000002 */ 	bc1f	.L0f1910e4
/*  f1910dc:	00000000 */ 	nop
/*  f1910e0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1910e4:
/*  f1910e4:	10400008 */ 	beqz	$v0,.L0f191108
/*  f1910e8:	00402825 */ 	or	$a1,$v0,$zero
/*  f1910ec:	44813000 */ 	mtc1	$at,$f6
/*  f1910f0:	00002825 */ 	or	$a1,$zero,$zero
/*  f1910f4:	4606603e */ 	c.le.s	$f12,$f6
/*  f1910f8:	00000000 */ 	nop
/*  f1910fc:	45000002 */ 	bc1f	.L0f191108
/*  f191100:	00000000 */ 	nop
/*  f191104:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f191108:
/*  f191108:	10a00014 */ 	beqz	$a1,.L0f19115c
/*  f19110c:	00a01825 */ 	or	$v1,$a1,$zero
/*  f191110:	0fc47bba */ 	jal	dprint
/*  f191114:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f191118:	8fae0084 */ 	lw	$t6,0x84($sp)
/*  f19111c:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f191120:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f191124:	8dcf000c */ 	lw	$t7,0xc($t6)
/*  f191128:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f19112c:	26050028 */ 	addiu	$a1,$s0,0x28
/*  f191130:	31f81000 */ 	andi	$t8,$t7,0x1000
/*  f191134:	17000009 */ 	bnez	$t8,.L0f19115c
/*  f191138:	24460008 */ 	addiu	$a2,$v0,0x8
/*  f19113c:	24190022 */ 	addiu	$t9,$zero,0x22
/*  f191140:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f191144:	24470028 */ 	addiu	$a3,$v0,0x28
/*  f191148:	0c00b734 */ 	jal	cd0002dcd0
/*  f19114c:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f191150:	14400002 */ 	bnez	$v0,.L0f19115c
/*  f191154:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f191158:	00001825 */ 	or	$v1,$zero,$zero
.L0f19115c:
/*  f19115c:	10600008 */ 	beqz	$v1,.L0f191180
/*  f191160:	00001025 */ 	or	$v0,$zero,$zero
/*  f191164:	0fc47bba */ 	jal	dprint
/*  f191168:	00000000 */ 	nop
/*  f19116c:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f191170:	0fc641e1 */ 	jal	botPickupProp
/*  f191174:	8fa5008c */ 	lw	$a1,0x8c($sp)
/*  f191178:	10000002 */ 	b	.L0f191184
/*  f19117c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f191180:
/*  f191180:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f191184:
/*  f191184:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f191188:	27bd0088 */ 	addiu	$sp,$sp,0x88
/*  f19118c:	03e00008 */ 	jr	$ra
/*  f191190:	00000000 */ 	nop
);
#else
GLOBAL_ASM(
glabel botTestPropForPickup
.late_rodata
glabel var7f1b8ea4
.word 0x47742400
glabel var7f1b8ea8
.word 0x461c4000
.text
/*  f18ace0:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f18ace4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f18ace8:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f18acec:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f18acf0:	8c8f0004 */ 	lw	$t7,0x4($a0)
/*  f18acf4:	10a0000d */ 	beqz	$a1,.NB0f18ad2c
/*  f18acf8:	afaf0084 */ 	sw	$t7,0x84($sp)
/*  f18acfc:	8cb802d4 */ 	lw	$t8,0x2d4($a1)
/*  f18ad00:	3c19800a */ 	lui	$t9,0x800a
/*  f18ad04:	13000009 */ 	beqz	$t8,.NB0f18ad2c
/*  f18ad08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ad0c:	8f39e9dc */ 	lw	$t9,-0x1624($t9)
/*  f18ad10:	00a02025 */ 	or	$a0,$a1,$zero
/*  f18ad14:	13200005 */ 	beqz	$t9,.NB0f18ad2c
/*  f18ad18:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ad1c:	0fc0e4ec */ 	jal	chrIsDead
/*  f18ad20:	afa5008c */ 	sw	$a1,0x8c($sp)
/*  f18ad24:	10400003 */ 	beqz	$v0,.NB0f18ad34
/*  f18ad28:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f18ad2c:
/*  f18ad2c:	1000014f */ 	beqz	$zero,.NB0f18b26c
/*  f18ad30:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18ad34:
/*  f18ad34:	0fc466bd */ 	jal	dprint
/*  f18ad38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ad3c:	8fa80088 */ 	lw	$t0,0x88($sp)
/*  f18ad40:	85090002 */ 	lh	$t1,0x2($t0)
/*  f18ad44:	11200003 */ 	beqz	$t1,.NB0f18ad54
/*  f18ad48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ad4c:	10000147 */ 	beqz	$zero,.NB0f18b26c
/*  f18ad50:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18ad54:
/*  f18ad54:	0fc20e86 */ 	jal	func0f085194
/*  f18ad58:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f18ad5c:	5040000d */ 	beqzl	$v0,.NB0f18ad94
/*  f18ad60:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f18ad64:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f18ad68:	24010011 */ 	addiu	$at,$zero,0x11
/*  f18ad6c:	904a0003 */ 	lbu	$t2,0x3($v0)
/*  f18ad70:	51410008 */ 	beql	$t2,$at,.NB0f18ad94
/*  f18ad74:	8fa20084 */ 	lw	$v0,0x84($sp)
/*  f18ad78:	8c4b0008 */ 	lw	$t3,0x8($v0)
/*  f18ad7c:	000b62c0 */ 	sll	$t4,$t3,0xb
/*  f18ad80:	0581000a */ 	bgez	$t4,.NB0f18adac
/*  f18ad84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ad88:	10000138 */ 	beqz	$zero,.NB0f18b26c
/*  f18ad8c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18ad90:	8fa20084 */ 	lw	$v0,0x84($sp)
.NB0f18ad94:
/*  f18ad94:	8c4d0008 */ 	lw	$t5,0x8($v0)
/*  f18ad98:	000d7340 */ 	sll	$t6,$t5,0xd
/*  f18ad9c:	05c00003 */ 	bltz	$t6,.NB0f18adac
/*  f18ada0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ada4:	10000131 */ 	beqz	$zero,.NB0f18b26c
/*  f18ada8:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18adac:
/*  f18adac:	0fc466bd */ 	jal	dprint
/*  f18adb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18adb4:	8faf0084 */ 	lw	$t7,0x84($sp)
/*  f18adb8:	8df80008 */ 	lw	$t8,0x8($t7)
/*  f18adbc:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f18adc0:	07210003 */ 	bgez	$t9,.NB0f18add0
/*  f18adc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18adc8:	10000128 */ 	beqz	$zero,.NB0f18b26c
/*  f18adcc:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18add0:
/*  f18add0:	0fc466bd */ 	jal	dprint
/*  f18add4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18add8:	8fa30084 */ 	lw	$v1,0x84($sp)
/*  f18addc:	8c680040 */ 	lw	$t0,0x40($v1)
/*  f18ade0:	31090080 */ 	andi	$t1,$t0,0x80
/*  f18ade4:	1120000c */ 	beqz	$t1,.NB0f18ae18
/*  f18ade8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18adec:	8c620048 */ 	lw	$v0,0x48($v1)
/*  f18adf0:	10400009 */ 	beqz	$v0,.NB0f18ae18
/*  f18adf4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18adf8:	8c4a00b4 */ 	lw	$t2,0xb4($v0)
/*  f18adfc:	19400006 */ 	blez	$t2,.NB0f18ae18
/*  f18ae00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ae04:	8c4b0090 */ 	lw	$t3,0x90($v0)
/*  f18ae08:	15600003 */ 	bnez	$t3,.NB0f18ae18
/*  f18ae0c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ae10:	10000116 */ 	beqz	$zero,.NB0f18b26c
/*  f18ae14:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18ae18:
/*  f18ae18:	0fc466bd */ 	jal	dprint
/*  f18ae1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ae20:	0fc19630 */ 	jal	objCanPickupFromSafe
/*  f18ae24:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f18ae28:	14400003 */ 	bnez	$v0,.NB0f18ae38
/*  f18ae2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ae30:	1000010e */ 	beqz	$zero,.NB0f18b26c
/*  f18ae34:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18ae38:
/*  f18ae38:	0fc466bd */ 	jal	dprint
/*  f18ae3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18ae40:	8fac0084 */ 	lw	$t4,0x84($sp)
/*  f18ae44:	24010008 */ 	addiu	$at,$zero,0x8
/*  f18ae48:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f18ae4c:	91820003 */ 	lbu	$v0,0x3($t4)
/*  f18ae50:	5441003c */ 	bnel	$v0,$at,.NB0f18af44
/*  f18ae54:	24010007 */ 	addiu	$at,$zero,0x7
/*  f18ae58:	8da20004 */ 	lw	$v0,0x4($t5)
/*  f18ae5c:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f18ae60:	9045005c */ 	lbu	$a1,0x5c($v0)
/*  f18ae64:	0fc64788 */ 	jal	botinvGetItemType
/*  f18ae68:	afa20080 */ 	sw	$v0,0x80($sp)
/*  f18ae6c:	8fae0080 */ 	lw	$t6,0x80($sp)
/*  f18ae70:	91c4005c */ 	lbu	$a0,0x5c($t6)
/*  f18ae74:	0fc2bb4c */ 	jal	weaponFindById
/*  f18ae78:	afa2007c */ 	sw	$v0,0x7c($sp)
/*  f18ae7c:	0002282b */ 	sltu	$a1,$zero,$v0
/*  f18ae80:	10a00004 */ 	beqz	$a1,.NB0f18ae94
/*  f18ae84:	8fa6007c */ 	lw	$a2,0x7c($sp)
/*  f18ae88:	8c45004c */ 	lw	$a1,0x4c($v0)
/*  f18ae8c:	30af1000 */ 	andi	$t7,$a1,0x1000
/*  f18ae90:	2de50001 */ 	sltiu	$a1,$t7,0x1
.NB0f18ae94:
/*  f18ae94:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f18ae98:	24010056 */ 	addiu	$at,$zero,0x56
/*  f18ae9c:	9050005c */ 	lbu	$s0,0x5c($v0)
/*  f18aea0:	1201009b */ 	beq	$s0,$at,.NB0f18b110
/*  f18aea4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f18aea8:	10c10006 */ 	beq	$a2,$at,.NB0f18aec4
/*  f18aeac:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f18aeb0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18aeb4:	54c10015 */ 	bnel	$a2,$at,.NB0f18af0c
/*  f18aeb8:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f18aebc:	50a00013 */ 	beqzl	$a1,.NB0f18af0c
/*  f18aec0:	8fa20080 */ 	lw	$v0,0x80($sp)
.NB0f18aec4:
/*  f18aec4:	8f2402d4 */ 	lw	$a0,0x2d4($t9)
/*  f18aec8:	02002825 */ 	or	$a1,$s0,$zero
/*  f18aecc:	9046005f */ 	lbu	$a2,0x5f($v0)
/*  f18aed0:	0fc64ef1 */ 	jal	botactGetAmmoQuantityByWeapon
/*  f18aed4:	00003825 */ 	or	$a3,$zero,$zero
/*  f18aed8:	8fa80080 */ 	lw	$t0,0x80($sp)
/*  f18aedc:	00408025 */ 	or	$s0,$v0,$zero
/*  f18aee0:	9104005c */ 	lbu	$a0,0x5c($t0)
/*  f18aee4:	0fc64e64 */ 	jal	botactGetAmmoTypeByFunction
/*  f18aee8:	9105005f */ 	lbu	$a1,0x5f($t0)
/*  f18aeec:	0fc29da5 */ 	jal	bgunGetCapacityByAmmotype
/*  f18aef0:	00402025 */ 	or	$a0,$v0,$zero
/*  f18aef4:	0202082a */ 	slt	$at,$s0,$v0
/*  f18aef8:	54200004 */ 	bnezl	$at,.NB0f18af0c
/*  f18aefc:	8fa20080 */ 	lw	$v0,0x80($sp)
/*  f18af00:	100000da */ 	beqz	$zero,.NB0f18b26c
/*  f18af04:	00001025 */ 	or	$v0,$zero,$zero
/*  f18af08:	8fa20080 */ 	lw	$v0,0x80($sp)
.NB0f18af0c:
/*  f18af0c:	24010052 */ 	addiu	$at,$zero,0x52
/*  f18af10:	8fa90084 */ 	lw	$t1,0x84($sp)
/*  f18af14:	9050005c */ 	lbu	$s0,0x5c($v0)
/*  f18af18:	12010003 */ 	beq	$s0,$at,.NB0f18af28
/*  f18af1c:	24010053 */ 	addiu	$at,$zero,0x53
/*  f18af20:	5601007c */ 	bnel	$s0,$at,.NB0f18b114
/*  f18af24:	8fa8008c */ 	lw	$t0,0x8c($sp)
.NB0f18af28:
/*  f18af28:	8d2a0040 */ 	lw	$t2,0x40($t1)
/*  f18af2c:	314b0080 */ 	andi	$t3,$t2,0x80
/*  f18af30:	51600078 */ 	beqzl	$t3,.NB0f18b114
/*  f18af34:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f18af38:	100000cc */ 	beqz	$zero,.NB0f18b26c
/*  f18af3c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18af40:	24010007 */ 	addiu	$at,$zero,0x7
.NB0f18af44:
/*  f18af44:	14410010 */ 	bne	$v0,$at,.NB0f18af88
/*  f18af48:	8fac0088 */ 	lw	$t4,0x88($sp)
/*  f18af4c:	8d900004 */ 	lw	$s0,0x4($t4)
/*  f18af50:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f18af54:	00003025 */ 	or	$a2,$zero,$zero
/*  f18af58:	8e05005c */ 	lw	$a1,0x5c($s0)
/*  f18af5c:	0fc64f26 */ 	jal	botactGetAmmoQuantityByType
/*  f18af60:	8da402d4 */ 	lw	$a0,0x2d4($t5)
/*  f18af64:	8e04005c */ 	lw	$a0,0x5c($s0)
/*  f18af68:	0fc29da5 */ 	jal	bgunGetCapacityByAmmotype
/*  f18af6c:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f18af70:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f18af74:	00a2082a */ 	slt	$at,$a1,$v0
/*  f18af78:	54200066 */ 	bnezl	$at,.NB0f18b114
/*  f18af7c:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f18af80:	100000ba */ 	beqz	$zero,.NB0f18b26c
/*  f18af84:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18af88:
/*  f18af88:	24010014 */ 	addiu	$at,$zero,0x14
/*  f18af8c:	1441003d */ 	bne	$v0,$at,.NB0f18b084
/*  f18af90:	8fae0088 */ 	lw	$t6,0x88($sp)
/*  f18af94:	8dd00004 */ 	lw	$s0,0x4($t6)
/*  f18af98:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f18af9c:	afaf0064 */ 	sw	$t7,0x64($sp)
/*  f18afa0:	0fc19e8e */ 	jal	objGetDestroyedLevel
/*  f18afa4:	8fa40084 */ 	lw	$a0,0x84($sp)
/*  f18afa8:	10400005 */ 	beqz	$v0,.NB0f18afc0
/*  f18afac:	02001825 */ 	or	$v1,$s0,$zero
/*  f18afb0:	0fc466bd */ 	jal	dprint
/*  f18afb4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18afb8:	100000ac */ 	beqz	$zero,.NB0f18b26c
/*  f18afbc:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18afc0:
/*  f18afc0:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18afc4:
/*  f18afc4:	24500001 */ 	addiu	$s0,$v0,0x1
/*  f18afc8:	02002025 */ 	or	$a0,$s0,$zero
/*  f18afcc:	0fc650bf */ 	jal	botactGetWeaponByAmmoType
/*  f18afd0:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f18afd4:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f18afd8:	afa20068 */ 	sw	$v0,0x68($sp)
/*  f18afdc:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f18afe0:	9478005e */ 	lhu	$t8,0x5e($v1)
/*  f18afe4:	02002825 */ 	or	$a1,$s0,$zero
/*  f18afe8:	00003025 */ 	or	$a2,$zero,$zero
/*  f18afec:	5b00001d */ 	blezl	$t8,.NB0f18b064
/*  f18aff0:	24010013 */ 	addiu	$at,$zero,0x13
/*  f18aff4:	8f2402d4 */ 	lw	$a0,0x2d4($t9)
/*  f18aff8:	0fc64f26 */ 	jal	botactGetAmmoQuantityByType
/*  f18affc:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f18b000:	02002025 */ 	or	$a0,$s0,$zero
/*  f18b004:	0fc29da5 */ 	jal	bgunGetCapacityByAmmotype
/*  f18b008:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f18b00c:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f18b010:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f18b014:	00a2082a */ 	slt	$at,$a1,$v0
/*  f18b018:	50200012 */ 	beqzl	$at,.NB0f18b064
/*  f18b01c:	24010013 */ 	addiu	$at,$zero,0x13
/*  f18b020:	8fa80068 */ 	lw	$t0,0x68($sp)
/*  f18b024:	afa00064 */ 	sw	$zero,0x64($sp)
/*  f18b028:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f18b02c:	51000011 */ 	beqzl	$t0,.NB0f18b074
/*  f18b030:	8fa90064 */ 	lw	$t1,0x64($sp)
/*  f18b034:	0fc64788 */ 	jal	botinvGetItemType
/*  f18b038:	01002825 */ 	or	$a1,$t0,$zero
/*  f18b03c:	5440000d */ 	bnezl	$v0,.NB0f18b074
/*  f18b040:	8fa90064 */ 	lw	$t1,0x64($sp)
/*  f18b044:	0fc466bd */ 	jal	dprint
/*  f18b048:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b04c:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f18b050:	0fc647d3 */ 	jal	botinvGiveProp
/*  f18b054:	8fa50088 */ 	lw	$a1,0x88($sp)
/*  f18b058:	10000006 */ 	beqz	$zero,.NB0f18b074
/*  f18b05c:	8fa90064 */ 	lw	$t1,0x64($sp)
/*  f18b060:	24010013 */ 	addiu	$at,$zero,0x13
.NB0f18b064:
/*  f18b064:	02001025 */ 	or	$v0,$s0,$zero
/*  f18b068:	1601ffd6 */ 	bne	$s0,$at,.NB0f18afc4
/*  f18b06c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f18b070:	8fa90064 */ 	lw	$t1,0x64($sp)
.NB0f18b074:
/*  f18b074:	51200027 */ 	beqzl	$t1,.NB0f18b114
/*  f18b078:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f18b07c:	1000007b */ 	beqz	$zero,.NB0f18b26c
/*  f18b080:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18b084:
/*  f18b084:	24010015 */ 	addiu	$at,$zero,0x15
/*  f18b088:	14410021 */ 	bne	$v0,$at,.NB0f18b110
/*  f18b08c:	8faa0088 */ 	lw	$t2,0x88($sp)
/*  f18b090:	8d4b0004 */ 	lw	$t3,0x4($t2)
/*  f18b094:	00008025 */ 	or	$s0,$zero,$zero
/*  f18b098:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f18b09c:	0fc0ce2a */ 	jal	chrGetShield
/*  f18b0a0:	afab0058 */ 	sw	$t3,0x58($sp)
/*  f18b0a4:	3c013e00 */ 	lui	$at,0x3e00
/*  f18b0a8:	44812000 */ 	mtc1	$at,$f4
/*  f18b0ac:	8fac0058 */ 	lw	$t4,0x58($sp)
/*  f18b0b0:	3c0d800b */ 	lui	$t5,0x800b
/*  f18b0b4:	46040182 */ 	mul.s	$f6,$f0,$f4
/*  f18b0b8:	c5880060 */ 	lwc1	$f8,0x60($t4)
/*  f18b0bc:	4606403e */ 	c.le.s	$f8,$f6
/*  f18b0c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b0c4:	45000003 */ 	bc1f	.NB0f18b0d4
/*  f18b0c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b0cc:	1000000c */ 	beqz	$zero,.NB0f18b100
/*  f18b0d0:	24100001 */ 	addiu	$s0,$zero,0x1
.NB0f18b0d4:
/*  f18b0d4:	91ad1448 */ 	lbu	$t5,0x1448($t5)
/*  f18b0d8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f18b0dc:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f18b0e0:	15a10007 */ 	bne	$t5,$at,.NB0f18b100
/*  f18b0e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b0e8:	8dcf02d4 */ 	lw	$t7,0x2d4($t6)
/*  f18b0ec:	8df8009c */ 	lw	$t8,0x9c($t7)
/*  f18b0f0:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f18b0f4:	13200002 */ 	beqz	$t9,.NB0f18b100
/*  f18b0f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b0fc:	24100001 */ 	addiu	$s0,$zero,0x1
.NB0f18b100:
/*  f18b100:	52000004 */ 	beqzl	$s0,.NB0f18b114
/*  f18b104:	8fa8008c */ 	lw	$t0,0x8c($sp)
/*  f18b108:	10000058 */ 	beqz	$zero,.NB0f18b26c
/*  f18b10c:	00001025 */ 	or	$v0,$zero,$zero
.NB0f18b110:
/*  f18b110:	8fa8008c */ 	lw	$t0,0x8c($sp)
.NB0f18b114:
/*  f18b114:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f18b118:	8d10001c */ 	lw	$s0,0x1c($t0)
/*  f18b11c:	c44a0008 */ 	lwc1	$f10,0x8($v0)
/*  f18b120:	c452000c */ 	lwc1	$f18,0xc($v0)
/*  f18b124:	c4460010 */ 	lwc1	$f6,0x10($v0)
/*  f18b128:	c6100008 */ 	lwc1	$f16,0x8($s0)
/*  f18b12c:	c604000c */ 	lwc1	$f4,0xc($s0)
/*  f18b130:	c6080010 */ 	lwc1	$f8,0x10($s0)
/*  f18b134:	46105081 */ 	sub.s	$f2,$f10,$f16
/*  f18b138:	46049301 */ 	sub.s	$f12,$f18,$f4
/*  f18b13c:	e7a2004c */ 	swc1	$f2,0x4c($sp)
/*  f18b140:	46083381 */ 	sub.s	$f14,$f6,$f8
/*  f18b144:	e7ac0048 */ 	swc1	$f12,0x48($sp)
/*  f18b148:	0fc466bd */ 	jal	dprint
/*  f18b14c:	e7ae0044 */ 	swc1	$f14,0x44($sp)
/*  f18b150:	c7a2004c */ 	lwc1	$f2,0x4c($sp)
/*  f18b154:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f18b158:	c7ae0044 */ 	lwc1	$f14,0x44($sp)
/*  f18b15c:	46021282 */ 	mul.s	$f10,$f2,$f2
/*  f18b160:	8d2a02d4 */ 	lw	$t2,0x2d4($t1)
/*  f18b164:	c7ac0048 */ 	lwc1	$f12,0x48($sp)
/*  f18b168:	460e7402 */ 	mul.s	$f16,$f14,$f14
/*  f18b16c:	914b009c */ 	lbu	$t3,0x9c($t2)
/*  f18b170:	3c017f1b */ 	lui	$at,0x7f1b
/*  f18b174:	316c0001 */ 	andi	$t4,$t3,0x1
/*  f18b178:	11800004 */ 	beqz	$t4,.NB0f18b18c
/*  f18b17c:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f18b180:	3c017f1b */ 	lui	$at,0x7f1b
/*  f18b184:	10000002 */ 	beqz	$zero,.NB0f18b190
/*  f18b188:	c4203484 */ 	lwc1	$f0,0x3484($at)
.NB0f18b18c:
/*  f18b18c:	c4203488 */ 	lwc1	$f0,0x3488($at)
.NB0f18b190:
/*  f18b190:	4600903e */ 	c.le.s	$f18,$f0
/*  f18b194:	00001025 */ 	or	$v0,$zero,$zero
/*  f18b198:	3c01c348 */ 	lui	$at,0xc348
/*  f18b19c:	45000002 */ 	bc1f	.NB0f18b1a8
/*  f18b1a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b1a4:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f18b1a8:
/*  f18b1a8:	10400012 */ 	beqz	$v0,.NB0f18b1f4
/*  f18b1ac:	00402825 */ 	or	$a1,$v0,$zero
/*  f18b1b0:	44812000 */ 	mtc1	$at,$f4
/*  f18b1b4:	3c014348 */ 	lui	$at,0x4348
/*  f18b1b8:	00001025 */ 	or	$v0,$zero,$zero
/*  f18b1bc:	460c203e */ 	c.le.s	$f4,$f12
/*  f18b1c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b1c4:	45000002 */ 	bc1f	.NB0f18b1d0
/*  f18b1c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b1cc:	24020001 */ 	addiu	$v0,$zero,0x1
.NB0f18b1d0:
/*  f18b1d0:	10400008 */ 	beqz	$v0,.NB0f18b1f4
/*  f18b1d4:	00402825 */ 	or	$a1,$v0,$zero
/*  f18b1d8:	44813000 */ 	mtc1	$at,$f6
/*  f18b1dc:	00002825 */ 	or	$a1,$zero,$zero
/*  f18b1e0:	4606603e */ 	c.le.s	$f12,$f6
/*  f18b1e4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b1e8:	45000002 */ 	bc1f	.NB0f18b1f4
/*  f18b1ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b1f0:	24050001 */ 	addiu	$a1,$zero,0x1
.NB0f18b1f4:
/*  f18b1f4:	10a00014 */ 	beqz	$a1,.NB0f18b248
/*  f18b1f8:	00a01825 */ 	or	$v1,$a1,$zero
/*  f18b1fc:	0fc466bd */ 	jal	dprint
/*  f18b200:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f18b204:	8fad0084 */ 	lw	$t5,0x84($sp)
/*  f18b208:	8fa20088 */ 	lw	$v0,0x88($sp)
/*  f18b20c:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f18b210:	8dae000c */ 	lw	$t6,0xc($t5)
/*  f18b214:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f18b218:	26050028 */ 	addiu	$a1,$s0,0x28
/*  f18b21c:	31cf1000 */ 	andi	$t7,$t6,0x1000
/*  f18b220:	15e00009 */ 	bnez	$t7,.NB0f18b248
/*  f18b224:	24460008 */ 	addiu	$a2,$v0,0x8
/*  f18b228:	24180022 */ 	addiu	$t8,$zero,0x22
/*  f18b22c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f18b230:	24470028 */ 	addiu	$a3,$v0,0x28
/*  f18b234:	0c00bc36 */ 	jal	cd0002dcd0
/*  f18b238:	afa3003c */ 	sw	$v1,0x3c($sp)
/*  f18b23c:	14400002 */ 	bnez	$v0,.NB0f18b248
/*  f18b240:	8fa3003c */ 	lw	$v1,0x3c($sp)
/*  f18b244:	00001825 */ 	or	$v1,$zero,$zero
.NB0f18b248:
/*  f18b248:	10600008 */ 	beqz	$v1,.NB0f18b26c
/*  f18b24c:	00001025 */ 	or	$v0,$zero,$zero
/*  f18b250:	0fc466bd */ 	jal	dprint
/*  f18b254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f18b258:	8fa40088 */ 	lw	$a0,0x88($sp)
/*  f18b25c:	0fc62a46 */ 	jal	botPickupProp
/*  f18b260:	8fa5008c */ 	lw	$a1,0x8c($sp)
/*  f18b264:	10000002 */ 	beqz	$zero,.NB0f18b270
/*  f18b268:	8fbf0024 */ 	lw	$ra,0x24($sp)
.NB0f18b26c:
/*  f18b26c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.NB0f18b270:
/*  f18b270:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f18b274:	27bd0088 */ 	addiu	$sp,$sp,0x88
/*  f18b278:	03e00008 */ 	jr	$ra
/*  f18b27c:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

// Mismatch: Uses too many callee-save registers
//bool botTestPropForPickup(struct prop *prop, struct chrdata *chr)
//{
//	struct defaultobj *obj = prop->obj; // 84
//
//	struct weaponobj *weaponobj; // 80
//	s32 itemtype; // 7c
//	struct weapon *weapon;
//	bool singleonly;
//	s32 cap;
//	s32 qty;
//
//	struct ammocrateobj *crate;
//
//	s32 weaponnum; // 68
//	bool ignore1; // 64
//	struct multiammocrateobj *crate2;
//
//	struct shieldobj *shield; // 58
//	bool ignore2;
//
//	struct prop *chrprop;
//
//	f32 xdist; // 4c
//	f32 ydist; // 48
//	f32 zdist; // 44
//	f32 sqrange;
//	bool sp3c;
//	s32 i;
//	f32 latdist;
//	u32 stack;
//
//	if (!chr || !chr->aibot || !g_Vars.lvmpbotlevel || chrIsDead(chr)) {
//		return false;
//	}
//
//	dprint();
//
//	if (prop->timetoregen != 0) {
//		return false;
//	}
//
//	if (func0f085194(obj) && obj->type != OBJTYPE_HAT) {
//		if (obj->flags & OBJFLAG_UNCOLLECTABLE) {
//			return false;
//		}
//	} else {
//		if ((obj->flags & OBJFLAG_COLLECTABLE) == 0) {
//			return false;
//		}
//	}
//
//	dprint();
//
//	if ((obj->hidden & OBJHFLAG_REAPABLE) || (obj->flags & OBJFLAG_THROWNLAPTOP)) {
//		return false;
//	}
//
//	dprint();
//
//	if ((obj->hidden & OBJHFLAG_PROJECTILE)
//			&& obj->projectile
//			&& obj->projectile->unk0b4 > 0
//			&& obj->projectile->bouncecount == 0) {
//		return false;
//	}
//
//	dprint();
//
//	if (!objCanPickupFromSafe(obj)) {
//		return false;
//	}
//
//	dprint();
//
//	// d64
//	if (obj->type == OBJTYPE_WEAPON) {
//		weaponobj = prop->weapon; // 80
//		itemtype = botinvGetItemType(chr, weaponobj->weaponnum); // 7c
//		weapon = weaponFindById(weaponobj->weaponnum);
//		singleonly = weapon && (weapon->flags & WEAPONFLAG_DUALWIELD) == 0;
//
//		if (weaponobj->weaponnum != WEAPON_BRIEFCASE2) {
//			// If aibot is dual wielding, or single wielding and weapon doesn't support dual,
//			// ignore the pickup if at max ammo already
//			if (itemtype == INVITEMTYPE_DUAL || (itemtype == INVITEMTYPE_WEAP && singleonly)) {
//				qty = botactGetAmmoQuantityByWeapon(chr->aibot, weaponobj->weaponnum, weaponobj->gunfunc, false);
//				cap = bgunGetCapacityByAmmotype(botactGetAmmoTypeByFunction(weaponobj->weaponnum, weaponobj->gunfunc));
//
//				if (qty >= cap) {
//					return false;
//				}
//			}
//
//			// Ignore rockets that are in flight
//			if ((weaponobj->weaponnum == WEAPON_ROCKET || weaponobj->weaponnum == WEAPON_HOMINGROCKET)
//					&& (obj->hidden & OBJHFLAG_PROJECTILE)) {
//				return false;
//			}
//		}
//	} else /*e58*/ if (obj->type == OBJTYPE_AMMOCRATE) {
//		crate = (struct ammocrateobj *)prop->obj;
//
//		// Ignore ammo crate if at max ammo already
//		if (botactGetAmmoQuantityByType(chr->aibot, crate->ammotype, false) >= bgunGetCapacityByAmmotype(crate->ammotype)) {
//			return false;
//		}
//	} else /*e9c*/ if (obj->type == OBJTYPE_MULTIAMMOCRATE) {
//		crate2 = (struct multiammocrateobj *)prop->obj;
//		ignore1 = true;
//
//		if (objGetDestroyedLevel(obj)) {
//			dprint();
//			return false;
//		}
//
//		for (i = 0; i < 0x13; i++) {
//			weaponnum = botactGetWeaponByAmmoType(i + 1);
//
//			if (crate2->slots[i].quantity > 0) {
//				if (botactGetAmmoQuantityByType(chr->aibot, i + 1, false) < bgunGetCapacityByAmmotype(i + 1)) {
//					ignore1 = false;
//
//					if (weaponnum && !botinvGetItemType(chr, weaponnum)) {
//						dprint();
//						botinvGiveProp(chr, prop);
//					}
//
//					break;
//				}
//			}
//		}
//
//		if (ignore1) {
//			return false;
//		}
//	} else /*f9c*/ if (obj->type == OBJTYPE_SHIELD) {
//		shield = (struct shieldobj *)prop->obj; // 58
//		ignore2 = false;
//
//		if (shield->amount <= chrGetShield(chr) * 0.125f) {
//			ignore2 = true;
//		} else if (g_MpSetup.scenario == MPSCENARIO_HOLDTHEBRIEFCASE && chr->aibot->hasbriefcase) {
//			ignore2 = true;
//		}
//
//		if (ignore2) {
//			return false;
//		}
//	}
//
//	// 024
//	chrprop = chr->prop;
//
//	xdist = prop->pos.x - chrprop->pos.x;
//	ydist = prop->pos.y - chrprop->pos.y;
//	zdist = prop->pos.z - chrprop->pos.z;
//
//	latdist = xdist * xdist + zdist * zdist;
//
//	dprint();
//
//	if (chr->aibot->cheap) {
//		sqrange = 250 * 250;
//	} else {
//		sqrange = 100 * 100;
//	}
//
//	sp3c = latdist <= sqrange && ydist >= -200 && ydist <= 200;
//
//	// 108
//	if (sp3c) {
//		dprint();
//
//		if ((obj->flags2 & OBJFLAG2_PICKUPWITHOUTLOS) == 0
//				&& !cd0002dcd0(&chrprop->pos, chrprop->rooms, &prop->pos, prop->rooms, 0x22)) {
//			sp3c = false;
//		}
//	}
//
//	// 15c
//	if (sp3c) {
//		dprint();
//		return botPickupProp(prop, chr);
//	}
//
//	return false;
//}

s32 botIsObjCollectable(struct defaultobj *obj)
{
	if (!obj) {
		return false;
	}

	if (obj->type == OBJTYPE_AMMOCRATE
			|| obj->type == OBJTYPE_MULTIAMMOCRATE
			|| obj->type == OBJTYPE_SHIELD) {
		return true;
	}

	if (obj->type == OBJTYPE_WEAPON) {
		struct weaponobj *weapon = (struct weaponobj *)obj;

		if (weapon->weaponnum == WEAPON_NBOMB
				|| weapon->weaponnum == WEAPON_GRENADE
				|| weapon->weaponnum == WEAPON_GRENADEROUND
				|| weapon->weaponnum == WEAPON_PROXIMITYMINE
				|| weapon->weaponnum == WEAPON_REMOTEMINE
				|| weapon->weaponnum == WEAPON_TIMEDMINE
				|| weapon->weaponnum == WEAPON_SKROCKET
				|| (weapon->weaponnum == WEAPON_DRAGON && weapon->gunfunc == FUNC_SECONDARY)) {
			return false;
		}

		return true;
	}

	return false;
}

/**
 * Check nearby props to see if the chr is picking them up on this frame.
 */
void botCheckPickups(struct chrdata *chr)
{
	s32 i;
	s16 *propnumptr;
	s16 propnums[260];
	s16 allrooms[22];
	s16 neighbours[12];

	roomsCopy(chr->prop->rooms, allrooms);

	for (i = 0; chr->prop->rooms[i] != -1; i++) {
		roomGetNeighbours(chr->prop->rooms[i], neighbours, 10);
		roomsAppend(neighbours, allrooms, 20);
	}

	roomGetProps(allrooms, propnums, 256);
	propnumptr = propnums;

	while (*propnumptr >= 0) {
		struct prop *prop = &g_Vars.props[*propnumptr];

		if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON) {
			if (prop->timetoregen == 0) {
				struct defaultobj *obj = prop->obj;

#if VERSION >= VERSION_NTSC_1_0
				if (obj)
#endif
				{
					if ((obj->hidden & OBJHFLAG_PROJECTILE) == 0
							|| obj->projectile == NULL
							|| obj->projectile->unk0b4 <= 0
							|| obj->projectile->bouncecount != 0) {
						if (botIsObjCollectable(obj)) {
							if (botTestPropForPickup(prop, chr)) {
								propExecuteTickOperation(prop, TICKOP_FREE);
							} else {
								dprint();
							}
						}
					}
				}
			}
		}

		propnumptr++;
	}
}

s32 botGuessCrouchPos(struct chrdata *chr)
{
	s32 crouchpos;

	if (chr->height <= 90) {
		crouchpos = CROUCHPOS_SQUAT;
	} else if (chr->height <= 135) {
		crouchpos = CROUCHPOS_DUCK;
	} else {
		crouchpos = CROUCHPOS_STAND;
	}

	return crouchpos;
}

bool botApplyMovement(struct chrdata *chr)
{
	struct aibot *aibot;
	u32 stack;
	f32 speedforwards;
	f32 speedsideways;
	f32 angle;
	f32 angle2;

	if (!chr || !chr->aibot) {
		return false;
	}

	aibot = chr->aibot;

	angle = chrGetInverseTheta(chr) - func0f03e578(chr);

	if (angle < 0) {
		angle += M_BADTAU;
	}

	speedforwards = aibot->unk06c * cosf(angle) - sinf(angle) * aibot->unk070;
	speedsideways = aibot->unk06c * sinf(angle) + cosf(angle) * aibot->unk070;

	playerChooseThirdPersonAnimation(chr, botGuessCrouchPos(chr), speedsideways, speedforwards, aibot->speedtheta, &aibot->angleoffset, &aibot->unk068);

	angle2 = chrGetInverseTheta(chr) - aibot->angleoffset;

	if (angle2 < 0) {
		angle2 += M_BADTAU;
	}

	if (angle2 >= M_BADTAU) {
		angle2 -= M_BADTAU;
	}

	model0001ae90(chr->model, angle2);

	return true;
}

s32 botGetWeaponNum(struct chrdata *chr)
{
	if (chr->aibot) {
		return chr->aibot->weaponnum;
	}

	return g_Vars.players[playermgrGetPlayerNumByProp(chr->prop)]->hands[HAND_RIGHT].gset.weaponnum;
}

u8 botGetTargetsWeaponNum(struct chrdata *chr)
{
	struct prop *target = chrGetTargetProp(chr);
	u8 weaponnum = WEAPON_NONE;

	if (target) {
		weaponnum = botGetWeaponNum(target->chr);
	}

	return weaponnum;
}

bool botIsAboutToAttack(struct chrdata *chr, bool arg1)
{
	bool result = false;
	struct prop *target;
	u32 stack;
	s32 mpindex;

	if (chr->target != -1) {
		target = chrGetTargetProp(chr);
		mpindex = mpPlayerGetIndex(target->chr);
		result = false;

		if (chr->aibot->chrsinsight[mpindex]) {
			result = true;
		}

		if (chr->aibot->config->difficulty > BOTDIFF_MEAT) {
			if (chr->aibot->chrslastseen60[mpindex] >= g_Vars.lvframe60 - TICKS(240)
					|| (arrayIntersects(chr->prop->rooms, target->rooms))) {
				result = true;
			}

			if (chr->aibot->config->difficulty >= BOTDIFF_NORMAL) {
				if (roomsAreNeighbours(chr->prop->rooms[0], target->rooms[0])
						|| chr->aibot->chrrooms[mpindex] == target->rooms[0]
						|| roomsAreNeighbours(chr->aibot->chrrooms[mpindex], target->rooms[0])) {
					result = true;
				}

				if (chr->aibot->config->difficulty == BOTDIFF_NORMAL) {
					if (chr->aibot->unk208 > 0 && chr->aibot->unk208 < 4) {
						result = true;
					}
				} else {
					if (chr->aibot->unk208 > 0 && chr->aibot->unk208 < 5) {
						result = true;
					}
				}
			}
		}

		if (!arg1
				&& (chr->aibot->config->difficulty == BOTDIFF_MEAT || chr->aibot->config->difficulty == BOTDIFF_EASY)
				&& !func0f02e064(chr)) {
			f32 tmp = func0f03e578(chr);
			f32 angle = atan2f(target->pos.x - chr->prop->pos.x, target->pos.z - chr->prop->pos.z) - tmp;

			if (angle < 0) {
				angle += M_BADTAU;
			}

			if (angle > M_PI) {
				angle = M_BADTAU - angle;
			}

			if (chr->aibot->config->difficulty == BOTDIFF_MEAT) {
				if (angle > 0.43626284599304f) {
					result = false;
				}
			} else {
				if (chr->aibot->config->difficulty == BOTDIFF_EASY && angle > 1.5705461502075f) {
					result = false;
				}
			}
		}
	}

	return result;
}

#if PAL
GLOBAL_ASM(
glabel botTick
.late_rodata
glabel var7f1b8ecc
.word 0x40c907a9
glabel var7f1b8ed0
.word 0x40c907a9
glabel var7f1b8ed4
.word 0x3d80a8be
glabel var7f1b8ed8
.word 0x40c907a9
glabel var7f1b8edc
.word 0x39c59ed7
glabel var7f1b8ee0
.word 0x3d7c45d9
glabel var7f1b8ee4
.word 0xc0490fdb
glabel var7f1b8ee8
.word 0x40490fdb
glabel var7f1b8eec
.word 0x40490fdb
glabel var7f1b8ef0
.word 0x4181e420
.text
/*  f1918d0:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f1918d4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1918d8:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f1918dc:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f1918e0:	afa40068 */ 	sw	$a0,0x68($sp)
/*  f1918e4:	8c910004 */ 	lw	$s1,0x4($a0)
/*  f1918e8:	8e3002d4 */ 	lw	$s0,0x2d4($s1)
/*  f1918ec:	afa0005c */ 	sw	$zero,0x5c($sp)
/*  f1918f0:	90870001 */ 	lbu	$a3,0x1($a0)
/*  f1918f4:	30ef0008 */ 	andi	$t7,$a3,0x8
/*  f1918f8:	000f382b */ 	sltu	$a3,$zero,$t7
/*  f1918fc:	10e00005 */ 	beqz	$a3,.L0f191914
/*  f191900:	00000000 */ 	nop
/*  f191904:	3c07800a */ 	lui	$a3,%hi(g_Vars+0x34)
/*  f191908:	8ce79ff4 */ 	lw	$a3,%lo(g_Vars+0x34)($a3)
/*  f19190c:	0007c82b */ 	sltu	$t9,$zero,$a3
/*  f191910:	03203825 */ 	or	$a3,$t9,$zero
.L0f191914:
/*  f191914:	1200019d */ 	beqz	$s0,.L0f191f8c
/*  f191918:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f19191c:	10e00183 */ 	beqz	$a3,.L0f191f2c
/*  f191920:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x8)
/*  f191924:	8d089fc8 */ 	lw	$t0,%lo(g_Vars+0x8)($t0)
/*  f191928:	29010091 */ 	slti	$at,$t0,0x91
/*  f19192c:	1420017f */ 	bnez	$at,.L0f191f2c
/*  f191930:	00000000 */ 	nop
/*  f191934:	0fc652d0 */ 	jal	botTickUnpaused
/*  f191938:	02202025 */ 	or	$a0,$s1,$zero
/*  f19193c:	920a009c */ 	lbu	$t2,0x9c($s0)
/*  f191940:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191944:	354b0001 */ 	ori	$t3,$t2,0x1
/*  f191948:	a20b009c */ 	sb	$t3,0x9c($s0)
/*  f19194c:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f191950:	858d0028 */ 	lh	$t5,0x28($t4)
/*  f191954:	11a10014 */ 	beq	$t5,$at,.L0f1919a8
/*  f191958:	01801825 */ 	or	$v1,$t4,$zero
/*  f19195c:	85840028 */ 	lh	$a0,0x28($t4)
.L0f191960:
/*  f191960:	0fc575ba */ 	jal	roomIsOnscreen
/*  f191964:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f191968:	14400006 */ 	bnez	$v0,.L0f191984
/*  f19196c:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f191970:	84640028 */ 	lh	$a0,0x28($v1)
/*  f191974:	0fc575d1 */ 	jal	roomIsStandby
/*  f191978:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f19197c:	10400005 */ 	beqz	$v0,.L0f191994
/*  f191980:	8fa30028 */ 	lw	$v1,0x28($sp)
.L0f191984:
/*  f191984:	920e009c */ 	lbu	$t6,0x9c($s0)
/*  f191988:	31cffffe */ 	andi	$t7,$t6,0xfffe
/*  f19198c:	10000006 */ 	b	.L0f1919a8
/*  f191990:	a20f009c */ 	sb	$t7,0x9c($s0)
.L0f191994:
/*  f191994:	8464002a */ 	lh	$a0,0x2a($v1)
/*  f191998:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19199c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f1919a0:	1481ffef */ 	bne	$a0,$at,.L0f191960
/*  f1919a4:	00000000 */ 	nop
.L0f1919a8:
/*  f1919a8:	862202d8 */ 	lh	$v0,0x2d8($s1)
/*  f1919ac:	18400012 */ 	blez	$v0,.L0f1919f8
/*  f1919b0:	28411389 */ 	slti	$at,$v0,0x1047
/*  f1919b4:	14200004 */ 	bnez	$at,.L0f1919c8
/*  f1919b8:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x38)
/*  f1919bc:	24181388 */ 	addiu	$t8,$zero,0x1046
/*  f1919c0:	a63802d8 */ 	sh	$t8,0x2d8($s1)
/*  f1919c4:	862202d8 */ 	lh	$v0,0x2d8($s1)
.L0f1919c8:
/*  f1919c8:	922802ff */ 	lbu	$t0,0x2ff($s1)
/*  f1919cc:	8f399ff8 */ 	lw	$t9,%lo(g_Vars+0x38)($t9)
/*  f1919d0:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f1919d4:	03290019 */ 	multu	$t9,$t1
/*  f1919d8:	00005012 */ 	mflo	$t2
/*  f1919dc:	004a5823 */ 	subu	$t3,$v0,$t2
/*  f1919e0:	a62b02d8 */ 	sh	$t3,0x2d8($s1)
/*  f1919e4:	862d02d8 */ 	lh	$t5,0x2d8($s1)
/*  f1919e8:	1da00003 */ 	bgtz	$t5,.L0f1919f8
/*  f1919ec:	00000000 */ 	nop
/*  f1919f0:	a62002d8 */ 	sh	$zero,0x2d8($s1)
/*  f1919f4:	a22002ff */ 	sb	$zero,0x2ff($s1)
.L0f1919f8:
/*  f1919f8:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f1919fc:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a00:	e7a00044 */ 	swc1	$f0,0x44($sp)
/*  f191a04:	0fc0e6a5 */ 	jal	chrIsDead
/*  f191a08:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a0c:	50400006 */ 	beqzl	$v0,.L0f191a28
/*  f191a10:	8e0c0044 */ 	lw	$t4,0x44($s0)
/*  f191a14:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f191a18:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a1c:	1000005b */ 	b	.L0f191b8c
/*  f191a20:	46000086 */ 	mov.s	$f2,$f0
/*  f191a24:	8e0c0044 */ 	lw	$t4,0x44($s0)
.L0f191a28:
/*  f191a28:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a2c:	11800005 */ 	beqz	$t4,.L0f191a44
/*  f191a30:	00000000 */ 	nop
/*  f191a34:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f191a38:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a3c:	10000053 */ 	b	.L0f191b8c
/*  f191a40:	46000086 */ 	mov.s	$f2,$f0
.L0f191a44:
/*  f191a44:	0fc6458e */ 	jal	botIsAboutToAttack
/*  f191a48:	00002825 */ 	or	$a1,$zero,$zero
/*  f191a4c:	5040000c */ 	beqzl	$v0,.L0f191a80
/*  f191a50:	922402a0 */ 	lbu	$a0,0x2a0($s1)
/*  f191a54:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f191a58:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a5c:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a60:	0fc122a1 */ 	jal	chrGetAngleToPos
/*  f191a64:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f191a68:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191a6c:	c60801c0 */ 	lwc1	$f8,0x1c0($s0)
/*  f191a70:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f191a74:	10000045 */ 	b	.L0f191b8c
/*  f191a78:	46083080 */ 	add.s	$f2,$f6,$f8
/*  f191a7c:	922402a0 */ 	lbu	$a0,0x2a0($s1)
.L0f191a80:
/*  f191a80:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f191a84:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f191a88:	1481000f */ 	bne	$a0,$at,.L0f191ac8
/*  f191a8c:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f191a90:	8c6200d4 */ 	lw	$v0,0xd4($v1)
/*  f191a94:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191a98:	1041000b */ 	beq	$v0,$at,.L0f191ac8
/*  f191a9c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f191aa0:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f191aa4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f191aa8:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f191aac:	8de50080 */ 	lw	$a1,0x80($t7)
/*  f191ab0:	02202025 */ 	or	$a0,$s1,$zero
/*  f191ab4:	0fc122a1 */ 	jal	chrGetAngleToPos
/*  f191ab8:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f191abc:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f191ac0:	10000032 */ 	b	.L0f191b8c
/*  f191ac4:	46005080 */ 	add.s	$f2,$f10,$f0
.L0f191ac8:
/*  f191ac8:	24010032 */ 	addiu	$at,$zero,0x32
/*  f191acc:	5481001e */ 	bnel	$a0,$at,.L0f191b48
/*  f191ad0:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191ad4:	8602000a */ 	lh	$v0,0xa($s0)
/*  f191ad8:	3c014396 */ 	lui	$at,0x4396
/*  f191adc:	04400019 */ 	bltz	$v0,.L0f191b44
/*  f191ae0:	00021880 */ 	sll	$v1,$v0,0x2
/*  f191ae4:	0203c021 */ 	addu	$t8,$s0,$v1
/*  f191ae8:	c704013c */ 	lwc1	$f4,0x13c($t8)
/*  f191aec:	44813000 */ 	mtc1	$at,$f6
/*  f191af0:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x8)
/*  f191af4:	4606203c */ 	c.lt.s	$f4,$f6
/*  f191af8:	00000000 */ 	nop
/*  f191afc:	45020012 */ 	bc1fl	.L0f191b48
/*  f191b00:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191b04:	8f399fc8 */ 	lw	$t9,%lo(g_Vars+0x8)($t9)
/*  f191b08:	8e0801e4 */ 	lw	$t0,0x1e4($s0)
/*  f191b0c:	2729ffc4 */ 	addiu	$t1,$t9,-50
/*  f191b10:	0109082a */ 	slt	$at,$t0,$t1
/*  f191b14:	5420000c */ 	bnezl	$at,.L0f191b48
/*  f191b18:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191b1c:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f191b20:	914b0048 */ 	lbu	$t3,0x48($t2)
/*  f191b24:	51600008 */ 	beqzl	$t3,.L0f191b48
/*  f191b28:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191b2c:	3c04800b */ 	lui	$a0,%hi(g_MpAllChrPtrs)
/*  f191b30:	00832021 */ 	addu	$a0,$a0,$v1
/*  f191b34:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f191b38:	8c84c4d0 */ 	lw	$a0,%lo(g_MpAllChrPtrs)($a0)
/*  f191b3c:	10000013 */ 	b	.L0f191b8c
/*  f191b40:	46000086 */ 	mov.s	$f2,$f0
.L0f191b44:
/*  f191b44:	24010033 */ 	addiu	$at,$zero,0x33
.L0f191b48:
/*  f191b48:	1481000d */ 	bne	$a0,$at,.L0f191b80
/*  f191b4c:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x8)
/*  f191b50:	8d8c9fc8 */ 	lw	$t4,%lo(g_Vars+0x8)($t4)
/*  f191b54:	8e0d01e4 */ 	lw	$t5,0x1e4($s0)
/*  f191b58:	258effc4 */ 	addiu	$t6,$t4,-50
/*  f191b5c:	01ae082a */ 	slt	$at,$t5,$t6
/*  f191b60:	14200007 */ 	bnez	$at,.L0f191b80
/*  f191b64:	00000000 */ 	nop
/*  f191b68:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f191b6c:	91f80048 */ 	lbu	$t8,0x48($t7)
/*  f191b70:	13000003 */ 	beqz	$t8,.L0f191b80
/*  f191b74:	00000000 */ 	nop
/*  f191b78:	10000004 */ 	b	.L0f191b8c
/*  f191b7c:	c6020098 */ 	lwc1	$f2,0x98($s0)
.L0f191b80:
/*  f191b80:	0fc0f95e */ 	jal	func0f03e578
/*  f191b84:	02202025 */ 	or	$a0,$s1,$zero
/*  f191b88:	46000086 */ 	mov.s	$f2,$f0
.L0f191b8c:
/*  f191b8c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ecc)
/*  f191b90:	c42e8ecc */ 	lwc1	$f14,%lo(var7f1b8ecc)($at)
/*  f191b94:	44809000 */ 	mtc1	$zero,$f18
/*  f191b98:	4602703e */ 	c.le.s	$f14,$f2
/*  f191b9c:	00000000 */ 	nop
/*  f191ba0:	45020007 */ 	bc1fl	.L0f191bc0
/*  f191ba4:	4612103c */ 	c.lt.s	$f2,$f18
/*  f191ba8:	460e1081 */ 	sub.s	$f2,$f2,$f14
.L0f191bac:
/*  f191bac:	4602703e */ 	c.le.s	$f14,$f2
/*  f191bb0:	00000000 */ 	nop
/*  f191bb4:	4503fffd */ 	bc1tl	.L0f191bac
/*  f191bb8:	460e1081 */ 	sub.s	$f2,$f2,$f14
/*  f191bbc:	4612103c */ 	c.lt.s	$f2,$f18
.L0f191bc0:
/*  f191bc0:	02202025 */ 	or	$a0,$s1,$zero
/*  f191bc4:	45020007 */ 	bc1fl	.L0f191be4
/*  f191bc8:	863902d8 */ 	lh	$t9,0x2d8($s1)
/*  f191bcc:	460e1080 */ 	add.s	$f2,$f2,$f14
.L0f191bd0:
/*  f191bd0:	4612103c */ 	c.lt.s	$f2,$f18
/*  f191bd4:	00000000 */ 	nop
/*  f191bd8:	4503fffd */ 	bc1tl	.L0f191bd0
/*  f191bdc:	460e1080 */ 	add.s	$f2,$f2,$f14
/*  f191be0:	863902d8 */ 	lh	$t9,0x2d8($s1)
.L0f191be4:
/*  f191be4:	5b20002c */ 	blezl	$t9,.L0f191c98
/*  f191be8:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191bec:	0fc0e6a5 */ 	jal	chrIsDead
/*  f191bf0:	e7a20048 */ 	swc1	$f2,0x48($sp)
/*  f191bf4:	3c017f1c */ 	lui	$at,%hi(var7f1b8ed0)
/*  f191bf8:	44809000 */ 	mtc1	$zero,$f18
/*  f191bfc:	c42e8ed0 */ 	lwc1	$f14,%lo(var7f1b8ed0)($at)
/*  f191c00:	14400024 */ 	bnez	$v0,.L0f191c94
/*  f191c04:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f191c08:	8e080044 */ 	lw	$t0,0x44($s0)
/*  f191c0c:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x8)
/*  f191c10:	55000021 */ 	bnezl	$t0,.L0f191c98
/*  f191c14:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191c18:	8d299fc8 */ 	lw	$t1,%lo(g_Vars+0x8)($t1)
/*  f191c1c:	24010078 */ 	addiu	$at,$zero,0x64
/*  f191c20:	e7a20048 */ 	swc1	$f2,0x48($sp)
/*  f191c24:	0121001a */ 	div	$zero,$t1,$at
/*  f191c28:	00005010 */ 	mfhi	$t2
/*  f191c2c:	448a4000 */ 	mtc1	$t2,$f8
/*  f191c30:	3c017f1c */ 	lui	$at,%hi(var7f1b8ed4)
/*  f191c34:	c4248ed4 */ 	lwc1	$f4,%lo(var7f1b8ed4)($at)
/*  f191c38:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f191c3c:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f191c40:	0c0068f7 */ 	jal	sinf
/*  f191c44:	00000000 */ 	nop
/*  f191c48:	862b02d8 */ 	lh	$t3,0x2d8($s1)
/*  f191c4c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ed8)
/*  f191c50:	c42e8ed8 */ 	lwc1	$f14,%lo(var7f1b8ed8)($at)
/*  f191c54:	448b3000 */ 	mtc1	$t3,$f6
/*  f191c58:	3c017f1c */ 	lui	$at,%hi(var7f1b8edc)
/*  f191c5c:	c42a8edc */ 	lwc1	$f10,%lo(var7f1b8edc)($at)
/*  f191c60:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f191c64:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f191c68:	44809000 */ 	mtc1	$zero,$f18
/*  f191c6c:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f191c70:	00000000 */ 	nop
/*  f191c74:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f191c78:	46061080 */ 	add.s	$f2,$f2,$f6
/*  f191c7c:	4602703e */ 	c.le.s	$f14,$f2
/*  f191c80:	00000000 */ 	nop
/*  f191c84:	45000002 */ 	bc1f	.L0f191c90
/*  f191c88:	00000000 */ 	nop
/*  f191c8c:	460e1081 */ 	sub.s	$f2,$f2,$f14
.L0f191c90:
/*  f191c90:	460e1080 */ 	add.s	$f2,$f2,$f14
.L0f191c94:
/*  f191c94:	c7a40044 */ 	lwc1	$f4,0x44($sp)
.L0f191c98:
/*  f191c98:	3c017f1c */ 	lui	$at,%hi(var7f1b8ee0)
/*  f191c9c:	c42a8ee0 */ 	lwc1	$f10,%lo(var7f1b8ee0)($at)
/*  f191ca0:	46041001 */ 	sub.s	$f0,$f2,$f4
/*  f191ca4:	3c017f1c */ 	lui	$at,%hi(var7f1b8ee4)
/*  f191ca8:	c4268ee4 */ 	lwc1	$f6,%lo(var7f1b8ee4)($at)
/*  f191cac:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f191cb0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f191cb4:	4606003c */ 	c.lt.s	$f0,$f6
/*  f191cb8:	c448004c */ 	lwc1	$f8,0x4c($v0)
/*  f191cbc:	46000406 */ 	mov.s	$f16,$f0
/*  f191cc0:	3c017f1c */ 	lui	$at,%hi(var7f1b8ee8)
/*  f191cc4:	460a4302 */ 	mul.s	$f12,$f8,$f10
/*  f191cc8:	45000003 */ 	bc1f	.L0f191cd8
/*  f191ccc:	00000000 */ 	nop
/*  f191cd0:	10000007 */ 	b	.L0f191cf0
/*  f191cd4:	460e0400 */ 	add.s	$f16,$f0,$f14
.L0f191cd8:
/*  f191cd8:	c4288ee8 */ 	lwc1	$f8,%lo(var7f1b8ee8)($at)
/*  f191cdc:	4600403e */ 	c.le.s	$f8,$f0
/*  f191ce0:	00000000 */ 	nop
/*  f191ce4:	45020003 */ 	bc1fl	.L0f191cf4
/*  f191ce8:	4610903e */ 	c.le.s	$f18,$f16
/*  f191cec:	460e0401 */ 	sub.s	$f16,$f0,$f14
.L0f191cf0:
/*  f191cf0:	4610903e */ 	c.le.s	$f18,$f16
.L0f191cf4:
/*  f191cf4:	c7a80044 */ 	lwc1	$f8,0x44($sp)
/*  f191cf8:	3c017f1c */ 	lui	$at,%hi(var7f1b8eec)
/*  f191cfc:	4502000f */ 	bc1fl	.L0f191d3c
/*  f191d00:	46006107 */ 	neg.s	$f4,$f12
/*  f191d04:	460c803e */ 	c.le.s	$f16,$f12
/*  f191d08:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f191d0c:	45020004 */ 	bc1fl	.L0f191d20
/*  f191d10:	460c5080 */ 	add.s	$f2,$f10,$f12
/*  f191d14:	10000015 */ 	b	.L0f191d6c
/*  f191d18:	46001006 */ 	mov.s	$f0,$f2
/*  f191d1c:	460c5080 */ 	add.s	$f2,$f10,$f12
.L0f191d20:
/*  f191d20:	4602703e */ 	c.le.s	$f14,$f2
/*  f191d24:	46001006 */ 	mov.s	$f0,$f2
/*  f191d28:	45020011 */ 	bc1fl	.L0f191d70
/*  f191d2c:	46080281 */ 	sub.s	$f10,$f0,$f8
/*  f191d30:	1000000e */ 	b	.L0f191d6c
/*  f191d34:	460e1001 */ 	sub.s	$f0,$f2,$f14
/*  f191d38:	46006107 */ 	neg.s	$f4,$f12
.L0f191d3c:
/*  f191d3c:	c7a60044 */ 	lwc1	$f6,0x44($sp)
/*  f191d40:	4610203e */ 	c.le.s	$f4,$f16
/*  f191d44:	00000000 */ 	nop
/*  f191d48:	45020004 */ 	bc1fl	.L0f191d5c
/*  f191d4c:	460c303c */ 	c.lt.s	$f6,$f12
/*  f191d50:	10000006 */ 	b	.L0f191d6c
/*  f191d54:	46001006 */ 	mov.s	$f0,$f2
/*  f191d58:	460c303c */ 	c.lt.s	$f6,$f12
.L0f191d5c:
/*  f191d5c:	460c3081 */ 	sub.s	$f2,$f6,$f12
/*  f191d60:	45000002 */ 	bc1f	.L0f191d6c
/*  f191d64:	46001006 */ 	mov.s	$f0,$f2
/*  f191d68:	460e1000 */ 	add.s	$f0,$f2,$f14
.L0f191d6c:
/*  f191d6c:	46080281 */ 	sub.s	$f10,$f0,$f8
.L0f191d70:
/*  f191d70:	e60a00ac */ 	swc1	$f10,0xac($s0)
/*  f191d74:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191d78:	4604003c */ 	c.lt.s	$f0,$f4
/*  f191d7c:	00000000 */ 	nop
/*  f191d80:	45020005 */ 	bc1fl	.L0f191d98
/*  f191d84:	c60200ac */ 	lwc1	$f2,0xac($s0)
/*  f191d88:	c60600ac */ 	lwc1	$f6,0xac($s0)
/*  f191d8c:	460e3200 */ 	add.s	$f8,$f6,$f14
/*  f191d90:	e60800ac */ 	swc1	$f8,0xac($s0)
/*  f191d94:	c60200ac */ 	lwc1	$f2,0xac($s0)
.L0f191d98:
/*  f191d98:	c42a8eec */ 	lwc1	$f10,%lo(var7f1b8eec)($at)
/*  f191d9c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ef0)
/*  f191da0:	4602503e */ 	c.le.s	$f10,$f2
/*  f191da4:	00000000 */ 	nop
/*  f191da8:	45020005 */ 	bc1fl	.L0f191dc0
/*  f191dac:	c446004c */ 	lwc1	$f6,0x4c($v0)
/*  f191db0:	460e1101 */ 	sub.s	$f4,$f2,$f14
/*  f191db4:	e60400ac */ 	swc1	$f4,0xac($s0)
/*  f191db8:	c60200ac */ 	lwc1	$f2,0xac($s0)
/*  f191dbc:	c446004c */ 	lwc1	$f6,0x4c($v0)
.L0f191dc0:
/*  f191dc0:	4600703e */ 	c.le.s	$f14,$f0
/*  f191dc4:	46061203 */ 	div.s	$f8,$f2,$f6
/*  f191dc8:	e60800ac */ 	swc1	$f8,0xac($s0)
/*  f191dcc:	c60a00ac */ 	lwc1	$f10,0xac($s0)
/*  f191dd0:	c4248ef0 */ 	lwc1	$f4,%lo(var7f1b8ef0)($at)
/*  f191dd4:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f191dd8:	45000006 */ 	bc1f	.L0f191df4
/*  f191ddc:	e60600ac */ 	swc1	$f6,0xac($s0)
/*  f191de0:	460e0001 */ 	sub.s	$f0,$f0,$f14
.L0f191de4:
/*  f191de4:	4600703e */ 	c.le.s	$f14,$f0
/*  f191de8:	00000000 */ 	nop
/*  f191dec:	4503fffd */ 	bc1tl	.L0f191de4
/*  f191df0:	460e0001 */ 	sub.s	$f0,$f0,$f14
.L0f191df4:
/*  f191df4:	4612003c */ 	c.lt.s	$f0,$f18
/*  f191df8:	00000000 */ 	nop
/*  f191dfc:	45020007 */ 	bc1fl	.L0f191e1c
/*  f191e00:	44050000 */ 	mfc1	$a1,$f0
/*  f191e04:	460e0000 */ 	add.s	$f0,$f0,$f14
.L0f191e08:
/*  f191e08:	4612003c */ 	c.lt.s	$f0,$f18
/*  f191e0c:	00000000 */ 	nop
/*  f191e10:	4503fffd */ 	bc1tl	.L0f191e08
/*  f191e14:	460e0000 */ 	add.s	$f0,$f0,$f14
/*  f191e18:	44050000 */ 	mfc1	$a1,$f0
.L0f191e1c:
/*  f191e1c:	0fc0f94e */ 	jal	chrSetLookAngle
/*  f191e20:	02202025 */ 	or	$a0,$s1,$zero
/*  f191e24:	862c017e */ 	lh	$t4,0x17e($s1)
/*  f191e28:	44809000 */ 	mtc1	$zero,$f18
/*  f191e2c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191e30:	11810018 */ 	beq	$t4,$at,.L0f191e94
/*  f191e34:	00000000 */ 	nop
/*  f191e38:	8e0d004c */ 	lw	$t5,0x4c($s0)
/*  f191e3c:	02202025 */ 	or	$a0,$s1,$zero
/*  f191e40:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f191e44:	05e00013 */ 	bltz	$t7,.L0f191e94
/*  f191e48:	00000000 */ 	nop
/*  f191e4c:	8e380174 */ 	lw	$t8,0x174($s1)
/*  f191e50:	00003025 */ 	or	$a2,$zero,$zero
/*  f191e54:	00003825 */ 	or	$a3,$zero,$zero
/*  f191e58:	13000003 */ 	beqz	$t8,.L0f191e68
/*  f191e5c:	00000000 */ 	nop
/*  f191e60:	10000001 */ 	b	.L0f191e68
/*  f191e64:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f191e68:
/*  f191e68:	8e390170 */ 	lw	$t9,0x170($s1)
/*  f191e6c:	13200003 */ 	beqz	$t9,.L0f191e7c
/*  f191e70:	00000000 */ 	nop
/*  f191e74:	10000001 */ 	b	.L0f191e7c
/*  f191e78:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f191e7c:
/*  f191e7c:	8e050068 */ 	lw	$a1,0x68($s0)
/*  f191e80:	0fc0fa7d */ 	jal	func0f03e9f4
/*  f191e84:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f191e88:	44809000 */ 	mtc1	$zero,$f18
/*  f191e8c:	10000006 */ 	b	.L0f191ea8
/*  f191e90:	82220007 */ 	lb	$v0,0x7($s1)
.L0f191e94:
/*  f191e94:	0fc0fe0a */ 	jal	chrResetAimEndProperties
/*  f191e98:	02202025 */ 	or	$a0,$s1,$zero
/*  f191e9c:	44809000 */ 	mtc1	$zero,$f18
/*  f191ea0:	00000000 */ 	nop
/*  f191ea4:	82220007 */ 	lb	$v0,0x7($s1)
.L0f191ea8:
/*  f191ea8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f191eac:	10410003 */ 	beq	$v0,$at,.L0f191ebc
/*  f191eb0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f191eb4:	54410005 */ 	bnel	$v0,$at,.L0f191ecc
/*  f191eb8:	8e080044 */ 	lw	$t0,0x44($s0)
.L0f191ebc:
/*  f191ebc:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f191ec0:	1000001a */ 	b	.L0f191f2c
/*  f191ec4:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191ec8:	8e080044 */ 	lw	$t0,0x44($s0)
.L0f191ecc:
/*  f191ecc:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x8)
/*  f191ed0:	2401000f */ 	addiu	$at,$zero,0xf
/*  f191ed4:	11000006 */ 	beqz	$t0,.L0f191ef0
/*  f191ed8:	00000000 */ 	nop
/*  f191edc:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f191ee0:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191ee4:	8d299fc8 */ 	lw	$t1,%lo(g_Vars+0x8)($t1)
/*  f191ee8:	10000010 */ 	b	.L0f191f2c
/*  f191eec:	ae0901e4 */ 	sw	$t1,0x1e4($s0)
.L0f191ef0:
/*  f191ef0:	1441000a */ 	bne	$v0,$at,.L0f191f1c
/*  f191ef4:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x8)
/*  f191ef8:	922a0065 */ 	lbu	$t2,0x65($s1)
/*  f191efc:	3c013f80 */ 	lui	$at,0x3f80
/*  f191f00:	314b0020 */ 	andi	$t3,$t2,0x20
/*  f191f04:	55600006 */ 	bnezl	$t3,.L0f191f20
/*  f191f08:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f191f0c:	44814000 */ 	mtc1	$at,$f8
/*  f191f10:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191f14:	10000005 */ 	b	.L0f191f2c
/*  f191f18:	e608006c */ 	swc1	$f8,0x6c($s0)
.L0f191f1c:
/*  f191f1c:	e612006c */ 	swc1	$f18,0x6c($s0)
.L0f191f20:
/*  f191f20:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191f24:	8d8c9fc8 */ 	lw	$t4,%lo(g_Vars+0x8)($t4)
/*  f191f28:	ae0c01e4 */ 	sw	$t4,0x1e4($s0)
.L0f191f2c:
/*  f191f2c:	0fc64512 */ 	jal	botApplyMovement
/*  f191f30:	02202025 */ 	or	$a0,$s1,$zero
/*  f191f34:	0fc08c26 */ 	jal	chrTick
/*  f191f38:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f191f3c:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x8)
/*  f191f40:	8dad9fc8 */ 	lw	$t5,%lo(g_Vars+0x8)($t5)
/*  f191f44:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f191f48:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f191f4c:	29a10091 */ 	slti	$at,$t5,0x91
/*  f191f50:	5420000f */ 	bnezl	$at,.L0f191f90
/*  f191f54:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f191f58:	51c00004 */ 	beqzl	$t6,.L0f191f6c
/*  f191f5c:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f191f60:	0fc615c8 */ 	jal	scenarioTickChr
/*  f191f64:	02202025 */ 	or	$a0,$s1,$zero
/*  f191f68:	8faf0058 */ 	lw	$t7,0x58($sp)
.L0f191f6c:
/*  f191f6c:	51e00008 */ 	beqzl	$t7,.L0f191f90
/*  f191f70:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f191f74:	0fc0e6a5 */ 	jal	chrIsDead
/*  f191f78:	02202025 */ 	or	$a0,$s1,$zero
/*  f191f7c:	54400004 */ 	bnezl	$v0,.L0f191f90
/*  f191f80:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f191f84:	0fc64493 */ 	jal	botCheckPickups
/*  f191f88:	02202025 */ 	or	$a0,$s1,$zero
.L0f191f8c:
/*  f191f8c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f191f90:
/*  f191f90:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f191f94:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f191f98:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f191f9c:	03e00008 */ 	jr	$ra
/*  f191fa0:	27bd0068 */ 	addiu	$sp,$sp,0x68
);
#else
GLOBAL_ASM(
glabel botTick
.late_rodata
glabel var7f1b8ecc
.word 0x40c907a9
glabel var7f1b8ed0
.word 0x40c907a9
glabel var7f1b8ed4
.word 0x3d566e92
glabel var7f1b8ed8
.word 0x40c907a9
glabel var7f1b8edc
.word 0x39a4af08
glabel var7f1b8ee0
.word 0x3d7c45d9
glabel var7f1b8ee4
.word 0xc0490fdb
glabel var7f1b8ee8
.word 0x40490fdb
glabel var7f1b8eec
.word 0x40490fdb
glabel var7f1b8ef0
.word 0x4181e420
.text
/*  f1918d0:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f1918d4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f1918d8:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f1918dc:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f1918e0:	afa40068 */ 	sw	$a0,0x68($sp)
/*  f1918e4:	8c910004 */ 	lw	$s1,0x4($a0)
/*  f1918e8:	8e3002d4 */ 	lw	$s0,0x2d4($s1)
/*  f1918ec:	afa0005c */ 	sw	$zero,0x5c($sp)
/*  f1918f0:	90870001 */ 	lbu	$a3,0x1($a0)
/*  f1918f4:	30ef0008 */ 	andi	$t7,$a3,0x8
/*  f1918f8:	000f382b */ 	sltu	$a3,$zero,$t7
/*  f1918fc:	10e00005 */ 	beqz	$a3,.L0f191914
/*  f191900:	00000000 */ 	nop
/*  f191904:	3c07800a */ 	lui	$a3,%hi(g_Vars+0x34)
/*  f191908:	8ce79ff4 */ 	lw	$a3,%lo(g_Vars+0x34)($a3)
/*  f19190c:	0007c82b */ 	sltu	$t9,$zero,$a3
/*  f191910:	03203825 */ 	or	$a3,$t9,$zero
.L0f191914:
/*  f191914:	1200019d */ 	beqz	$s0,.L0f191f8c
/*  f191918:	afa70058 */ 	sw	$a3,0x58($sp)
/*  f19191c:	10e00183 */ 	beqz	$a3,.L0f191f2c
/*  f191920:	3c08800a */ 	lui	$t0,%hi(g_Vars+0x8)
/*  f191924:	8d089fc8 */ 	lw	$t0,%lo(g_Vars+0x8)($t0)
/*  f191928:	29010091 */ 	slti	$at,$t0,0x91
/*  f19192c:	1420017f */ 	bnez	$at,.L0f191f2c
/*  f191930:	00000000 */ 	nop
/*  f191934:	0fc652d0 */ 	jal	botTickUnpaused
/*  f191938:	02202025 */ 	or	$a0,$s1,$zero
/*  f19193c:	920a009c */ 	lbu	$t2,0x9c($s0)
/*  f191940:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191944:	354b0001 */ 	ori	$t3,$t2,0x1
/*  f191948:	a20b009c */ 	sb	$t3,0x9c($s0)
/*  f19194c:	8fac0068 */ 	lw	$t4,0x68($sp)
/*  f191950:	858d0028 */ 	lh	$t5,0x28($t4)
/*  f191954:	11a10014 */ 	beq	$t5,$at,.L0f1919a8
/*  f191958:	01801825 */ 	or	$v1,$t4,$zero
/*  f19195c:	85840028 */ 	lh	$a0,0x28($t4)
.L0f191960:
/*  f191960:	0fc575ba */ 	jal	roomIsOnscreen
/*  f191964:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f191968:	14400006 */ 	bnez	$v0,.L0f191984
/*  f19196c:	8fa30028 */ 	lw	$v1,0x28($sp)
/*  f191970:	84640028 */ 	lh	$a0,0x28($v1)
/*  f191974:	0fc575d1 */ 	jal	roomIsStandby
/*  f191978:	afa30028 */ 	sw	$v1,0x28($sp)
/*  f19197c:	10400005 */ 	beqz	$v0,.L0f191994
/*  f191980:	8fa30028 */ 	lw	$v1,0x28($sp)
.L0f191984:
/*  f191984:	920e009c */ 	lbu	$t6,0x9c($s0)
/*  f191988:	31cffffe */ 	andi	$t7,$t6,0xfffe
/*  f19198c:	10000006 */ 	b	.L0f1919a8
/*  f191990:	a20f009c */ 	sb	$t7,0x9c($s0)
.L0f191994:
/*  f191994:	8464002a */ 	lh	$a0,0x2a($v1)
/*  f191998:	2401ffff */ 	addiu	$at,$zero,-1
/*  f19199c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f1919a0:	1481ffef */ 	bne	$a0,$at,.L0f191960
/*  f1919a4:	00000000 */ 	nop
.L0f1919a8:
/*  f1919a8:	862202d8 */ 	lh	$v0,0x2d8($s1)
/*  f1919ac:	18400012 */ 	blez	$v0,.L0f1919f8
/*  f1919b0:	28411389 */ 	slti	$at,$v0,0x1389
/*  f1919b4:	14200004 */ 	bnez	$at,.L0f1919c8
/*  f1919b8:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x38)
/*  f1919bc:	24181388 */ 	addiu	$t8,$zero,0x1388
/*  f1919c0:	a63802d8 */ 	sh	$t8,0x2d8($s1)
/*  f1919c4:	862202d8 */ 	lh	$v0,0x2d8($s1)
.L0f1919c8:
/*  f1919c8:	922802ff */ 	lbu	$t0,0x2ff($s1)
/*  f1919cc:	8f399ff8 */ 	lw	$t9,%lo(g_Vars+0x38)($t9)
/*  f1919d0:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f1919d4:	03290019 */ 	multu	$t9,$t1
/*  f1919d8:	00005012 */ 	mflo	$t2
/*  f1919dc:	004a5823 */ 	subu	$t3,$v0,$t2
/*  f1919e0:	a62b02d8 */ 	sh	$t3,0x2d8($s1)
/*  f1919e4:	862d02d8 */ 	lh	$t5,0x2d8($s1)
/*  f1919e8:	1da00003 */ 	bgtz	$t5,.L0f1919f8
/*  f1919ec:	00000000 */ 	nop
/*  f1919f0:	a62002d8 */ 	sh	$zero,0x2d8($s1)
/*  f1919f4:	a22002ff */ 	sb	$zero,0x2ff($s1)
.L0f1919f8:
/*  f1919f8:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f1919fc:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a00:	e7a00044 */ 	swc1	$f0,0x44($sp)
/*  f191a04:	0fc0e6a5 */ 	jal	chrIsDead
/*  f191a08:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a0c:	50400006 */ 	beqzl	$v0,.L0f191a28
/*  f191a10:	8e0c0044 */ 	lw	$t4,0x44($s0)
/*  f191a14:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f191a18:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a1c:	1000005b */ 	b	.L0f191b8c
/*  f191a20:	46000086 */ 	mov.s	$f2,$f0
/*  f191a24:	8e0c0044 */ 	lw	$t4,0x44($s0)
.L0f191a28:
/*  f191a28:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a2c:	11800005 */ 	beqz	$t4,.L0f191a44
/*  f191a30:	00000000 */ 	nop
/*  f191a34:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f191a38:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a3c:	10000053 */ 	b	.L0f191b8c
/*  f191a40:	46000086 */ 	mov.s	$f2,$f0
.L0f191a44:
/*  f191a44:	0fc6458e */ 	jal	botIsAboutToAttack
/*  f191a48:	00002825 */ 	or	$a1,$zero,$zero
/*  f191a4c:	5040000c */ 	beqzl	$v0,.L0f191a80
/*  f191a50:	922402a0 */ 	lbu	$a0,0x2a0($s1)
/*  f191a54:	0fc0a221 */ 	jal	chrGetTargetProp
/*  f191a58:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a5c:	02202025 */ 	or	$a0,$s1,$zero
/*  f191a60:	0fc122a1 */ 	jal	chrGetAngleToPos
/*  f191a64:	24450008 */ 	addiu	$a1,$v0,0x8
/*  f191a68:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191a6c:	c60801c0 */ 	lwc1	$f8,0x1c0($s0)
/*  f191a70:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f191a74:	10000045 */ 	b	.L0f191b8c
/*  f191a78:	46083080 */ 	add.s	$f2,$f6,$f8
/*  f191a7c:	922402a0 */ 	lbu	$a0,0x2a0($s1)
.L0f191a80:
/*  f191a80:	2401002e */ 	addiu	$at,$zero,0x2e
/*  f191a84:	3c03800b */ 	lui	$v1,%hi(g_ScenarioData)
/*  f191a88:	1481000f */ 	bne	$a0,$at,.L0f191ac8
/*  f191a8c:	2463c110 */ 	addiu	$v1,$v1,%lo(g_ScenarioData)
/*  f191a90:	8c6200d4 */ 	lw	$v0,0xd4($v1)
/*  f191a94:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191a98:	1041000b */ 	beq	$v0,$at,.L0f191ac8
/*  f191a9c:	00027080 */ 	sll	$t6,$v0,0x2
/*  f191aa0:	01c27023 */ 	subu	$t6,$t6,$v0
/*  f191aa4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f191aa8:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f191aac:	8de50080 */ 	lw	$a1,0x80($t7)
/*  f191ab0:	02202025 */ 	or	$a0,$s1,$zero
/*  f191ab4:	0fc122a1 */ 	jal	chrGetAngleToPos
/*  f191ab8:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f191abc:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f191ac0:	10000032 */ 	b	.L0f191b8c
/*  f191ac4:	46005080 */ 	add.s	$f2,$f10,$f0
.L0f191ac8:
/*  f191ac8:	24010032 */ 	addiu	$at,$zero,0x32
/*  f191acc:	5481001e */ 	bnel	$a0,$at,.L0f191b48
/*  f191ad0:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191ad4:	8602000a */ 	lh	$v0,0xa($s0)
/*  f191ad8:	3c014396 */ 	lui	$at,0x4396
/*  f191adc:	04400019 */ 	bltz	$v0,.L0f191b44
/*  f191ae0:	00021880 */ 	sll	$v1,$v0,0x2
/*  f191ae4:	0203c021 */ 	addu	$t8,$s0,$v1
/*  f191ae8:	c704013c */ 	lwc1	$f4,0x13c($t8)
/*  f191aec:	44813000 */ 	mtc1	$at,$f6
/*  f191af0:	3c19800a */ 	lui	$t9,%hi(g_Vars+0x8)
/*  f191af4:	4606203c */ 	c.lt.s	$f4,$f6
/*  f191af8:	00000000 */ 	nop
/*  f191afc:	45020012 */ 	bc1fl	.L0f191b48
/*  f191b00:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191b04:	8f399fc8 */ 	lw	$t9,%lo(g_Vars+0x8)($t9)
/*  f191b08:	8e0801e4 */ 	lw	$t0,0x1e4($s0)
/*  f191b0c:	2729ffc4 */ 	addiu	$t1,$t9,-60
/*  f191b10:	0109082a */ 	slt	$at,$t0,$t1
/*  f191b14:	5420000c */ 	bnezl	$at,.L0f191b48
/*  f191b18:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191b1c:	8e0a0004 */ 	lw	$t2,0x4($s0)
/*  f191b20:	914b0048 */ 	lbu	$t3,0x48($t2)
/*  f191b24:	51600008 */ 	beqzl	$t3,.L0f191b48
/*  f191b28:	24010033 */ 	addiu	$at,$zero,0x33
/*  f191b2c:	3c04800b */ 	lui	$a0,%hi(g_MpAllChrPtrs)
/*  f191b30:	00832021 */ 	addu	$a0,$a0,$v1
/*  f191b34:	0fc0f917 */ 	jal	chrGetInverseTheta
/*  f191b38:	8c84c4d0 */ 	lw	$a0,%lo(g_MpAllChrPtrs)($a0)
/*  f191b3c:	10000013 */ 	b	.L0f191b8c
/*  f191b40:	46000086 */ 	mov.s	$f2,$f0
.L0f191b44:
/*  f191b44:	24010033 */ 	addiu	$at,$zero,0x33
.L0f191b48:
/*  f191b48:	1481000d */ 	bne	$a0,$at,.L0f191b80
/*  f191b4c:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x8)
/*  f191b50:	8d8c9fc8 */ 	lw	$t4,%lo(g_Vars+0x8)($t4)
/*  f191b54:	8e0d01e4 */ 	lw	$t5,0x1e4($s0)
/*  f191b58:	258effc4 */ 	addiu	$t6,$t4,-60
/*  f191b5c:	01ae082a */ 	slt	$at,$t5,$t6
/*  f191b60:	14200007 */ 	bnez	$at,.L0f191b80
/*  f191b64:	00000000 */ 	nop
/*  f191b68:	8e0f0004 */ 	lw	$t7,0x4($s0)
/*  f191b6c:	91f80048 */ 	lbu	$t8,0x48($t7)
/*  f191b70:	13000003 */ 	beqz	$t8,.L0f191b80
/*  f191b74:	00000000 */ 	nop
/*  f191b78:	10000004 */ 	b	.L0f191b8c
/*  f191b7c:	c6020098 */ 	lwc1	$f2,0x98($s0)
.L0f191b80:
/*  f191b80:	0fc0f95e */ 	jal	func0f03e578
/*  f191b84:	02202025 */ 	or	$a0,$s1,$zero
/*  f191b88:	46000086 */ 	mov.s	$f2,$f0
.L0f191b8c:
/*  f191b8c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ecc)
/*  f191b90:	c42e8ecc */ 	lwc1	$f14,%lo(var7f1b8ecc)($at)
/*  f191b94:	44809000 */ 	mtc1	$zero,$f18
/*  f191b98:	4602703e */ 	c.le.s	$f14,$f2
/*  f191b9c:	00000000 */ 	nop
/*  f191ba0:	45020007 */ 	bc1fl	.L0f191bc0
/*  f191ba4:	4612103c */ 	c.lt.s	$f2,$f18
/*  f191ba8:	460e1081 */ 	sub.s	$f2,$f2,$f14
.L0f191bac:
/*  f191bac:	4602703e */ 	c.le.s	$f14,$f2
/*  f191bb0:	00000000 */ 	nop
/*  f191bb4:	4503fffd */ 	bc1tl	.L0f191bac
/*  f191bb8:	460e1081 */ 	sub.s	$f2,$f2,$f14
/*  f191bbc:	4612103c */ 	c.lt.s	$f2,$f18
.L0f191bc0:
/*  f191bc0:	02202025 */ 	or	$a0,$s1,$zero
/*  f191bc4:	45020007 */ 	bc1fl	.L0f191be4
/*  f191bc8:	863902d8 */ 	lh	$t9,0x2d8($s1)
/*  f191bcc:	460e1080 */ 	add.s	$f2,$f2,$f14
.L0f191bd0:
/*  f191bd0:	4612103c */ 	c.lt.s	$f2,$f18
/*  f191bd4:	00000000 */ 	nop
/*  f191bd8:	4503fffd */ 	bc1tl	.L0f191bd0
/*  f191bdc:	460e1080 */ 	add.s	$f2,$f2,$f14
/*  f191be0:	863902d8 */ 	lh	$t9,0x2d8($s1)
.L0f191be4:
/*  f191be4:	5b20002c */ 	blezl	$t9,.L0f191c98
/*  f191be8:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191bec:	0fc0e6a5 */ 	jal	chrIsDead
/*  f191bf0:	e7a20048 */ 	swc1	$f2,0x48($sp)
/*  f191bf4:	3c017f1c */ 	lui	$at,%hi(var7f1b8ed0)
/*  f191bf8:	44809000 */ 	mtc1	$zero,$f18
/*  f191bfc:	c42e8ed0 */ 	lwc1	$f14,%lo(var7f1b8ed0)($at)
/*  f191c00:	14400024 */ 	bnez	$v0,.L0f191c94
/*  f191c04:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f191c08:	8e080044 */ 	lw	$t0,0x44($s0)
/*  f191c0c:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x8)
/*  f191c10:	55000021 */ 	bnezl	$t0,.L0f191c98
/*  f191c14:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191c18:	8d299fc8 */ 	lw	$t1,%lo(g_Vars+0x8)($t1)
/*  f191c1c:	24010078 */ 	addiu	$at,$zero,0x78
/*  f191c20:	e7a20048 */ 	swc1	$f2,0x48($sp)
/*  f191c24:	0121001a */ 	div	$zero,$t1,$at
/*  f191c28:	00005010 */ 	mfhi	$t2
/*  f191c2c:	448a4000 */ 	mtc1	$t2,$f8
/*  f191c30:	3c017f1c */ 	lui	$at,%hi(var7f1b8ed4)
/*  f191c34:	c4248ed4 */ 	lwc1	$f4,%lo(var7f1b8ed4)($at)
/*  f191c38:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f191c3c:	46045302 */ 	mul.s	$f12,$f10,$f4
/*  f191c40:	0c0068f7 */ 	jal	sinf
/*  f191c44:	00000000 */ 	nop
/*  f191c48:	862b02d8 */ 	lh	$t3,0x2d8($s1)
/*  f191c4c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ed8)
/*  f191c50:	c42e8ed8 */ 	lwc1	$f14,%lo(var7f1b8ed8)($at)
/*  f191c54:	448b3000 */ 	mtc1	$t3,$f6
/*  f191c58:	3c017f1c */ 	lui	$at,%hi(var7f1b8edc)
/*  f191c5c:	c42a8edc */ 	lwc1	$f10,%lo(var7f1b8edc)($at)
/*  f191c60:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f191c64:	c7a20048 */ 	lwc1	$f2,0x48($sp)
/*  f191c68:	44809000 */ 	mtc1	$zero,$f18
/*  f191c6c:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f191c70:	00000000 */ 	nop
/*  f191c74:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f191c78:	46061080 */ 	add.s	$f2,$f2,$f6
/*  f191c7c:	4602703e */ 	c.le.s	$f14,$f2
/*  f191c80:	00000000 */ 	nop
/*  f191c84:	45000002 */ 	bc1f	.L0f191c90
/*  f191c88:	00000000 */ 	nop
/*  f191c8c:	460e1081 */ 	sub.s	$f2,$f2,$f14
.L0f191c90:
/*  f191c90:	460e1080 */ 	add.s	$f2,$f2,$f14
.L0f191c94:
/*  f191c94:	c7a40044 */ 	lwc1	$f4,0x44($sp)
.L0f191c98:
/*  f191c98:	3c017f1c */ 	lui	$at,%hi(var7f1b8ee0)
/*  f191c9c:	c42a8ee0 */ 	lwc1	$f10,%lo(var7f1b8ee0)($at)
/*  f191ca0:	46041001 */ 	sub.s	$f0,$f2,$f4
/*  f191ca4:	3c017f1c */ 	lui	$at,%hi(var7f1b8ee4)
/*  f191ca8:	c4268ee4 */ 	lwc1	$f6,%lo(var7f1b8ee4)($at)
/*  f191cac:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f191cb0:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f191cb4:	4606003c */ 	c.lt.s	$f0,$f6
/*  f191cb8:	c448004c */ 	lwc1	$f8,0x4c($v0)
/*  f191cbc:	46000406 */ 	mov.s	$f16,$f0
/*  f191cc0:	3c017f1c */ 	lui	$at,%hi(var7f1b8ee8)
/*  f191cc4:	460a4302 */ 	mul.s	$f12,$f8,$f10
/*  f191cc8:	45000003 */ 	bc1f	.L0f191cd8
/*  f191ccc:	00000000 */ 	nop
/*  f191cd0:	10000007 */ 	b	.L0f191cf0
/*  f191cd4:	460e0400 */ 	add.s	$f16,$f0,$f14
.L0f191cd8:
/*  f191cd8:	c4288ee8 */ 	lwc1	$f8,%lo(var7f1b8ee8)($at)
/*  f191cdc:	4600403e */ 	c.le.s	$f8,$f0
/*  f191ce0:	00000000 */ 	nop
/*  f191ce4:	45020003 */ 	bc1fl	.L0f191cf4
/*  f191ce8:	4610903e */ 	c.le.s	$f18,$f16
/*  f191cec:	460e0401 */ 	sub.s	$f16,$f0,$f14
.L0f191cf0:
/*  f191cf0:	4610903e */ 	c.le.s	$f18,$f16
.L0f191cf4:
/*  f191cf4:	c7a80044 */ 	lwc1	$f8,0x44($sp)
/*  f191cf8:	3c017f1c */ 	lui	$at,%hi(var7f1b8eec)
/*  f191cfc:	4502000f */ 	bc1fl	.L0f191d3c
/*  f191d00:	46006107 */ 	neg.s	$f4,$f12
/*  f191d04:	460c803e */ 	c.le.s	$f16,$f12
/*  f191d08:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f191d0c:	45020004 */ 	bc1fl	.L0f191d20
/*  f191d10:	460c5080 */ 	add.s	$f2,$f10,$f12
/*  f191d14:	10000015 */ 	b	.L0f191d6c
/*  f191d18:	46001006 */ 	mov.s	$f0,$f2
/*  f191d1c:	460c5080 */ 	add.s	$f2,$f10,$f12
.L0f191d20:
/*  f191d20:	4602703e */ 	c.le.s	$f14,$f2
/*  f191d24:	46001006 */ 	mov.s	$f0,$f2
/*  f191d28:	45020011 */ 	bc1fl	.L0f191d70
/*  f191d2c:	46080281 */ 	sub.s	$f10,$f0,$f8
/*  f191d30:	1000000e */ 	b	.L0f191d6c
/*  f191d34:	460e1001 */ 	sub.s	$f0,$f2,$f14
/*  f191d38:	46006107 */ 	neg.s	$f4,$f12
.L0f191d3c:
/*  f191d3c:	c7a60044 */ 	lwc1	$f6,0x44($sp)
/*  f191d40:	4610203e */ 	c.le.s	$f4,$f16
/*  f191d44:	00000000 */ 	nop
/*  f191d48:	45020004 */ 	bc1fl	.L0f191d5c
/*  f191d4c:	460c303c */ 	c.lt.s	$f6,$f12
/*  f191d50:	10000006 */ 	b	.L0f191d6c
/*  f191d54:	46001006 */ 	mov.s	$f0,$f2
/*  f191d58:	460c303c */ 	c.lt.s	$f6,$f12
.L0f191d5c:
/*  f191d5c:	460c3081 */ 	sub.s	$f2,$f6,$f12
/*  f191d60:	45000002 */ 	bc1f	.L0f191d6c
/*  f191d64:	46001006 */ 	mov.s	$f0,$f2
/*  f191d68:	460e1000 */ 	add.s	$f0,$f2,$f14
.L0f191d6c:
/*  f191d6c:	46080281 */ 	sub.s	$f10,$f0,$f8
.L0f191d70:
/*  f191d70:	e60a00ac */ 	swc1	$f10,0xac($s0)
/*  f191d74:	c7a40044 */ 	lwc1	$f4,0x44($sp)
/*  f191d78:	4604003c */ 	c.lt.s	$f0,$f4
/*  f191d7c:	00000000 */ 	nop
/*  f191d80:	45020005 */ 	bc1fl	.L0f191d98
/*  f191d84:	c60200ac */ 	lwc1	$f2,0xac($s0)
/*  f191d88:	c60600ac */ 	lwc1	$f6,0xac($s0)
/*  f191d8c:	460e3200 */ 	add.s	$f8,$f6,$f14
/*  f191d90:	e60800ac */ 	swc1	$f8,0xac($s0)
/*  f191d94:	c60200ac */ 	lwc1	$f2,0xac($s0)
.L0f191d98:
/*  f191d98:	c42a8eec */ 	lwc1	$f10,%lo(var7f1b8eec)($at)
/*  f191d9c:	3c017f1c */ 	lui	$at,%hi(var7f1b8ef0)
/*  f191da0:	4602503e */ 	c.le.s	$f10,$f2
/*  f191da4:	00000000 */ 	nop
/*  f191da8:	45020005 */ 	bc1fl	.L0f191dc0
/*  f191dac:	c446004c */ 	lwc1	$f6,0x4c($v0)
/*  f191db0:	460e1101 */ 	sub.s	$f4,$f2,$f14
/*  f191db4:	e60400ac */ 	swc1	$f4,0xac($s0)
/*  f191db8:	c60200ac */ 	lwc1	$f2,0xac($s0)
/*  f191dbc:	c446004c */ 	lwc1	$f6,0x4c($v0)
.L0f191dc0:
/*  f191dc0:	4600703e */ 	c.le.s	$f14,$f0
/*  f191dc4:	46061203 */ 	div.s	$f8,$f2,$f6
/*  f191dc8:	e60800ac */ 	swc1	$f8,0xac($s0)
/*  f191dcc:	c60a00ac */ 	lwc1	$f10,0xac($s0)
/*  f191dd0:	c4248ef0 */ 	lwc1	$f4,%lo(var7f1b8ef0)($at)
/*  f191dd4:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f191dd8:	45000006 */ 	bc1f	.L0f191df4
/*  f191ddc:	e60600ac */ 	swc1	$f6,0xac($s0)
/*  f191de0:	460e0001 */ 	sub.s	$f0,$f0,$f14
.L0f191de4:
/*  f191de4:	4600703e */ 	c.le.s	$f14,$f0
/*  f191de8:	00000000 */ 	nop
/*  f191dec:	4503fffd */ 	bc1tl	.L0f191de4
/*  f191df0:	460e0001 */ 	sub.s	$f0,$f0,$f14
.L0f191df4:
/*  f191df4:	4612003c */ 	c.lt.s	$f0,$f18
/*  f191df8:	00000000 */ 	nop
/*  f191dfc:	45020007 */ 	bc1fl	.L0f191e1c
/*  f191e00:	44050000 */ 	mfc1	$a1,$f0
/*  f191e04:	460e0000 */ 	add.s	$f0,$f0,$f14
.L0f191e08:
/*  f191e08:	4612003c */ 	c.lt.s	$f0,$f18
/*  f191e0c:	00000000 */ 	nop
/*  f191e10:	4503fffd */ 	bc1tl	.L0f191e08
/*  f191e14:	460e0000 */ 	add.s	$f0,$f0,$f14
/*  f191e18:	44050000 */ 	mfc1	$a1,$f0
.L0f191e1c:
/*  f191e1c:	0fc0f94e */ 	jal	chrSetLookAngle
/*  f191e20:	02202025 */ 	or	$a0,$s1,$zero
/*  f191e24:	862c017e */ 	lh	$t4,0x17e($s1)
/*  f191e28:	44809000 */ 	mtc1	$zero,$f18
/*  f191e2c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f191e30:	11810018 */ 	beq	$t4,$at,.L0f191e94
/*  f191e34:	00000000 */ 	nop
/*  f191e38:	8e0d004c */ 	lw	$t5,0x4c($s0)
/*  f191e3c:	02202025 */ 	or	$a0,$s1,$zero
/*  f191e40:	000d7840 */ 	sll	$t7,$t5,0x1
/*  f191e44:	05e00013 */ 	bltz	$t7,.L0f191e94
/*  f191e48:	00000000 */ 	nop
/*  f191e4c:	8e380174 */ 	lw	$t8,0x174($s1)
/*  f191e50:	00003025 */ 	or	$a2,$zero,$zero
/*  f191e54:	00003825 */ 	or	$a3,$zero,$zero
/*  f191e58:	13000003 */ 	beqz	$t8,.L0f191e68
/*  f191e5c:	00000000 */ 	nop
/*  f191e60:	10000001 */ 	b	.L0f191e68
/*  f191e64:	24060001 */ 	addiu	$a2,$zero,0x1
.L0f191e68:
/*  f191e68:	8e390170 */ 	lw	$t9,0x170($s1)
/*  f191e6c:	13200003 */ 	beqz	$t9,.L0f191e7c
/*  f191e70:	00000000 */ 	nop
/*  f191e74:	10000001 */ 	b	.L0f191e7c
/*  f191e78:	24070001 */ 	addiu	$a3,$zero,0x1
.L0f191e7c:
/*  f191e7c:	8e050068 */ 	lw	$a1,0x68($s0)
/*  f191e80:	0fc0fa7d */ 	jal	func0f03e9f4
/*  f191e84:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f191e88:	44809000 */ 	mtc1	$zero,$f18
/*  f191e8c:	10000006 */ 	b	.L0f191ea8
/*  f191e90:	82220007 */ 	lb	$v0,0x7($s1)
.L0f191e94:
/*  f191e94:	0fc0fe0a */ 	jal	chrResetAimEndProperties
/*  f191e98:	02202025 */ 	or	$a0,$s1,$zero
/*  f191e9c:	44809000 */ 	mtc1	$zero,$f18
/*  f191ea0:	00000000 */ 	nop
/*  f191ea4:	82220007 */ 	lb	$v0,0x7($s1)
.L0f191ea8:
/*  f191ea8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f191eac:	10410003 */ 	beq	$v0,$at,.L0f191ebc
/*  f191eb0:	24010005 */ 	addiu	$at,$zero,0x5
/*  f191eb4:	54410005 */ 	bnel	$v0,$at,.L0f191ecc
/*  f191eb8:	8e080044 */ 	lw	$t0,0x44($s0)
.L0f191ebc:
/*  f191ebc:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f191ec0:	1000001a */ 	b	.L0f191f2c
/*  f191ec4:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191ec8:	8e080044 */ 	lw	$t0,0x44($s0)
.L0f191ecc:
/*  f191ecc:	3c09800a */ 	lui	$t1,%hi(g_Vars+0x8)
/*  f191ed0:	2401000f */ 	addiu	$at,$zero,0xf
/*  f191ed4:	11000006 */ 	beqz	$t0,.L0f191ef0
/*  f191ed8:	00000000 */ 	nop
/*  f191edc:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f191ee0:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191ee4:	8d299fc8 */ 	lw	$t1,%lo(g_Vars+0x8)($t1)
/*  f191ee8:	10000010 */ 	b	.L0f191f2c
/*  f191eec:	ae0901e4 */ 	sw	$t1,0x1e4($s0)
.L0f191ef0:
/*  f191ef0:	1441000a */ 	bne	$v0,$at,.L0f191f1c
/*  f191ef4:	3c0c800a */ 	lui	$t4,%hi(g_Vars+0x8)
/*  f191ef8:	922a0065 */ 	lbu	$t2,0x65($s1)
/*  f191efc:	3c013f80 */ 	lui	$at,0x3f80
/*  f191f00:	314b0020 */ 	andi	$t3,$t2,0x20
/*  f191f04:	55600006 */ 	bnezl	$t3,.L0f191f20
/*  f191f08:	e612006c */ 	swc1	$f18,0x6c($s0)
/*  f191f0c:	44814000 */ 	mtc1	$at,$f8
/*  f191f10:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191f14:	10000005 */ 	b	.L0f191f2c
/*  f191f18:	e608006c */ 	swc1	$f8,0x6c($s0)
.L0f191f1c:
/*  f191f1c:	e612006c */ 	swc1	$f18,0x6c($s0)
.L0f191f20:
/*  f191f20:	e6120070 */ 	swc1	$f18,0x70($s0)
/*  f191f24:	8d8c9fc8 */ 	lw	$t4,%lo(g_Vars+0x8)($t4)
/*  f191f28:	ae0c01e4 */ 	sw	$t4,0x1e4($s0)
.L0f191f2c:
/*  f191f2c:	0fc64512 */ 	jal	botApplyMovement
/*  f191f30:	02202025 */ 	or	$a0,$s1,$zero
/*  f191f34:	0fc08c26 */ 	jal	chrTick
/*  f191f38:	8fa40068 */ 	lw	$a0,0x68($sp)
/*  f191f3c:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x8)
/*  f191f40:	8dad9fc8 */ 	lw	$t5,%lo(g_Vars+0x8)($t5)
/*  f191f44:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f191f48:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f191f4c:	29a10091 */ 	slti	$at,$t5,0x91
/*  f191f50:	5420000f */ 	bnezl	$at,.L0f191f90
/*  f191f54:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f191f58:	51c00004 */ 	beqzl	$t6,.L0f191f6c
/*  f191f5c:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f191f60:	0fc615c8 */ 	jal	scenarioTickChr
/*  f191f64:	02202025 */ 	or	$a0,$s1,$zero
/*  f191f68:	8faf0058 */ 	lw	$t7,0x58($sp)
.L0f191f6c:
/*  f191f6c:	51e00008 */ 	beqzl	$t7,.L0f191f90
/*  f191f70:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f191f74:	0fc0e6a5 */ 	jal	chrIsDead
/*  f191f78:	02202025 */ 	or	$a0,$s1,$zero
/*  f191f7c:	54400004 */ 	bnezl	$v0,.L0f191f90
/*  f191f80:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f191f84:	0fc64493 */ 	jal	botCheckPickups
/*  f191f88:	02202025 */ 	or	$a0,$s1,$zero
.L0f191f8c:
/*  f191f8c:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f191f90:
/*  f191f90:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f191f94:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f191f98:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f191f9c:	03e00008 */ 	jr	$ra
/*  f191fa0:	27bd0068 */ 	addiu	$sp,$sp,0x68
);
#endif

// Mismatch: regalloc for updateable calculation
//s32 botTick(struct prop *prop)
//{
//	struct chrdata *chr = prop->chr;
//	struct aibot *aibot = chr->aibot;
//	s32 result = TICKOP_NONE;
//	bool updateable;
//	s32 i;
//	f32 diffangle;
//	f32 tweenangle;
//	f32 targetangle;
//	f32 oldangle;
//	f32 newangle;
//
//	*(s32 *)&updateable = (prop->flags & PROPFLAG_NOTYETTICKED) && g_Vars.lvupdate240;
//
//	if (aibot) {
//		if (updateable && g_Vars.lvframe60 >= 145) {
//			botTickUnpaused(chr);
//
//			// Calculate cheap
//			aibot->cheap = true;
//
//			for (i = 0; prop->rooms[i] != -1; i++) {
//				if (roomIsOnscreen(prop->rooms[i]) || roomIsStandby(prop->rooms[i])) {
//					aibot->cheap = false;
//					break;
//				}
//			}
//
//			// Dampen blur
//			if (chr->blurdrugamount > 0) {
//				if (chr->blurdrugamount > TICKS(5000)) {
//					chr->blurdrugamount = TICKS(5000);
//				}
//
//				chr->blurdrugamount -= g_Vars.lvupdate240_60 * (chr->blurnumtimesdied + 1);
//
//				if (chr->blurdrugamount <= 0) {
//					chr->blurdrugamount = 0;
//					chr->blurnumtimesdied = 0;
//				}
//			}
//
//			// Calculate target angle
//			oldangle = chrGetInverseTheta(chr);
//
//			if (chrIsDead(chr)) {
//				targetangle = chrGetInverseTheta(chr);
//			} else if (aibot->skrocket) {
//				targetangle = chrGetInverseTheta(chr);
//			} else if (botIsAboutToAttack(chr, false)) {
//				struct prop *target = chrGetTargetProp(chr);
//				targetangle = chrGetAngleToPos(chr, &target->pos);
//				targetangle = oldangle + targetangle + aibot->unk1c0;
//			} else if (chr->myaction == MA_AIBOTDOWNLOAD && g_ScenarioData.htm.dlterminalnum != -1) {
//				targetangle = chrGetAngleToPos(chr, &g_ScenarioData.htm.terminals[g_ScenarioData.htm.dlterminalnum].prop->pos);
//				targetangle = oldangle + targetangle;
//			} else if (chr->myaction == MA_AIBOTFOLLOW
//					&& aibot->followingplayernum >= 0
//					&& aibot->chrdistances[aibot->followingplayernum] < 300
//					&& aibot->unk1e4 >= g_Vars.lvframe60 - TICKS(60)
//					&& aibot->config->difficulty != BOTDIFF_MEAT) {
//				targetangle = chrGetInverseTheta(g_MpAllChrPtrs[aibot->followingplayernum]);
//			} else if (chr->myaction == MA_AIBOTDEFEND
//					&& aibot->unk1e4 >= g_Vars.lvframe60 - TICKS(60)
//					&& aibot->config->difficulty != BOTDIFF_MEAT) {
//				targetangle = aibot->unk098;
//			} else {
//				targetangle = func0f03e578(chr);
//			}
//
//			while (targetangle >= M_BADTAU) {
//				targetangle -= M_BADTAU;
//			}
//
//			while (targetangle < 0) {
//				targetangle += M_BADTAU;
//			}
//
//			if (chr->blurdrugamount > 0 && !chrIsDead(chr) && aibot->skrocket == NULL) {
//				targetangle += chr->blurdrugamount * 0.00031410926021636f * sinf((g_Vars.lvframe60 % TICKS(120)) * 0.052351541817188f);
//
//				if (targetangle >= M_BADTAU) {
//					targetangle -= M_BADTAU;
//				}
//
//				targetangle += M_BADTAU;
//			}
//
//			tweenangle = g_Vars.lvupdate240freal * 0.061590049415827f;
//			diffangle = targetangle - oldangle;
//
//			if (diffangle < -M_PI) {
//				diffangle += M_BADTAU;
//			} else if (diffangle >= M_PI) {
//				diffangle -= M_BADTAU;
//			}
//
//			if (diffangle >= 0) {
//				if (diffangle <= tweenangle) {
//					newangle = targetangle;
//				} else {
//					newangle = oldangle + tweenangle;
//
//					if (newangle >= M_BADTAU) {
//						newangle -= M_BADTAU;
//					}
//				}
//			} else {
//				if (diffangle >= -tweenangle) {
//					newangle = targetangle;
//				} else {
//					newangle = oldangle - tweenangle;
//
//					if (newangle < 0) {
//						newangle += M_BADTAU;
//					}
//				}
//			}
//
//			aibot->speedtheta = newangle - oldangle;
//
//			if (aibot->speedtheta < 0) {
//				aibot->speedtheta += M_BADTAU;
//			}
//
//			if (aibot->speedtheta >= M_PI) {
//				aibot->speedtheta -= M_BADTAU;
//			}
//
//			aibot->speedtheta /= g_Vars.lvupdate240freal;
//			aibot->speedtheta *= 16.236389160156f;
//
//			while (newangle >= M_BADTAU) {
//				newangle -= M_BADTAU;
//			}
//
//			while (newangle < 0) {
//				newangle += M_BADTAU;
//			}
//
//			chrSetLookAngle(chr, newangle);
//
//			if (chr->target != -1 && !aibot->iscloserangeweapon) {
//				bool left = chr->weapons_held[HAND_LEFT] ? true : false;
//				bool right = chr->weapons_held[HAND_RIGHT] ? true : false;
//
//				func0f03e9f4(chr, aibot->unk068, left, right, 0);
//			} else {
//				chrResetAimEndProperties(chr);
//			}
//
//			if (chr->actiontype == ACT_DIE || chr->actiontype == ACT_DEAD) {
//				aibot->unk06c = 0;
//				aibot->unk070 = 0;
//			} else if (aibot->skrocket) {
//				aibot->unk06c = 0;
//				aibot->unk070 = 0;
//				aibot->unk1e4 = g_Vars.lvframe60;
//			} else if (chr->actiontype == ACT_GOPOS && (chr->act_gopos.flags & GOPOSFLAG_20) == 0) {
//				aibot->unk06c = 1;
//				aibot->unk070 = 0;
//			} else {
//				aibot->unk06c = 0;
//				aibot->unk070 = 0;
//				aibot->unk1e4 = g_Vars.lvframe60;
//			}
//		}
//
//		botApplyMovement(chr);
//
//		result = chrTick(prop);
//
//		if (g_Vars.lvframe60 >= 145) {
//			if (updateable) {
//				scenarioTickChr(chr);
//			}
//
//			if (updateable && !chrIsDead(chr)) {
//				botCheckPickups(chr);
//			}
//		}
//	}
//
//	return result;
//}

f32 botCalculateMaxSpeed(struct chrdata *chr)
{
	f32 speed;

	if (chr->aibot->hascase || chr->aibot->hasbriefcase) {
		speed = -63.600006103516f;
	} else {
		speed = g_HeadsAndBodies[chr->bodynum].height * (1.0f / 159.0f);
	}

	speed = speed * 0.002830188954249f + 1.0f;

	if (chr->aibot->config->type == BOTTYPE_TURTLE) {
		speed *= 3.5f;
	} else if (chr->aibot->config->type == BOTTYPE_SPEED) {
		speed *= 14.0f;
	} else {
		switch (chr->aibot->config->difficulty) {
		case BOTDIFF_MEAT:
			speed *= 5.0f;
			break;
		case BOTDIFF_EASY:
			speed *= 6.2f;
			break;
		default:
		case BOTDIFF_NORMAL:
			speed *= 7.6f;
			break;
		case BOTDIFF_HARD:
			speed *= 9.4f;
			break;
		case BOTDIFF_PERFECT:
			speed *= 11.2f;
			break;
		case BOTDIFF_DARK:
			speed *= 11.2f;
			break;
		}
	}

	if (botGuessCrouchPos(chr) == CROUCHPOS_SQUAT) {
		speed *= 0.35f;
	} else if (botGuessCrouchPos(chr) == CROUCHPOS_DUCK) {
		speed *= 0.5f;
	} else if (chr->actiontype == ACT_GOPOS
			&& chr->act_gopos.waypoints[chr->act_gopos.curindex] == NULL
			&& chrGetLateralDistanceToCoord(chr, &chr->act_gopos.endpos) < 200) {
		speed *= 0.5f;
	}

	return speed;
}

#if VERSION >= VERSION_NTSC_1_0
void bot0f1921f8(struct chrdata *chr, f32 *move, s32 numupdates, f32 arg3)
#else
void bot0f1921f8(struct chrdata *chr, f32 *move)
#endif
{
	s32 i;
	f32 sp50;
	f32 cosine;
	f32 sine;
	u32 stack[4];
	f32 sp30[2];
	f32 fVar7;
	f32 fVar8;
	f32 speed;
	f32 tmp;

	if (!chr || !chr->aibot) {
		return;
	}

	if (g_Vars.lvframe60 < 145) {
		move[0] = 0;
		move[1] = 0;
		return;
	}

	fVar7 = chr->aibot->unk070;
	fVar8 = chr->aibot->unk06c;

	speed = botCalculateMaxSpeed(chr);

	fVar7 *= speed;
	fVar8 *= speed;

	sp50 = func0f03e578(chr);

	cosine = cosf(sp50);
	sine = sinf(sp50);

	sp30[0] = fVar7 * cosine + fVar8 * sine;
	sp30[1] = -fVar7 * sine + fVar8 * cosine;

	move[0] = 0;
	move[1] = 0;


#if VERSION >= VERSION_NTSC_1_0
	tmp = (PAL ? 0.065f : 0.055000007152557f) * arg3 / numupdates;

	for (i = 0; i < numupdates; i++) {
		chr->aibot->unk0b4 = (PAL ? 0.935f : 0.945f) * chr->aibot->unk0b4 + sp30[0];
		chr->aibot->unk0b8 = (PAL ? 0.935f : 0.945f) * chr->aibot->unk0b8 + sp30[1];

		move[0] += chr->aibot->unk0b4 * tmp;
		move[1] += chr->aibot->unk0b8 * tmp;
	}
#else
	tmp = (PAL ? 0.065f : 0.055000007152557f) * g_Vars.lvupdate240freal / g_Vars.lvupdate240;

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		chr->aibot->unk0b4 = (PAL ? 0.935f : 0.945f) * chr->aibot->unk0b4 + sp30[0];
		chr->aibot->unk0b8 = (PAL ? 0.935f : 0.945f) * chr->aibot->unk0b8 + sp30[1];

		move[0] += chr->aibot->unk0b4 * tmp;
		move[1] += chr->aibot->unk0b8 * tmp;
	}
#endif
}

u32 g_MpBotCommands[NUM_MPBOTCOMMANDS] = {
	L_MISC_175, // "Follow"
	L_MISC_176, // "Attack"
	L_MISC_177, // "Defend"
	L_MISC_178, // "Hold"
	L_MISC_179, // "Normal"
	L_MISC_180, // "Download"
	L_MISC_181, // "Get Case"
	L_MISC_182, // "Tag Box"
	L_MISC_209, // "Save Case"
	L_MISC_210, // "Def Hill"
	L_MISC_211, // "Hold Hill"
	L_MISC_212, // "Get Case"
	L_MISC_213, // "Pop Cap"
	L_MISC_214, // "Protect"
};

char *botGetCommandName(s32 command)
{
	if (command < 0 || command >= NUM_MPBOTCOMMANDS) {
		return langGet(L_MISC_179); // "Normal"
	}

	return langGet(g_MpBotCommands[command]);
}

void botApplyAttack(struct chrdata *chr, struct prop *prop)
{
	chr->aibot->command = AIBOTCMD_ATTACK;
	chr->aibot->attackpropnum = prop - g_Vars.props;
	chr->aibot->forcemainloop = true;
}

void botApplyFollow(struct chrdata *chr, struct prop *prop)
{
	chr->aibot->command = AIBOTCMD_FOLLOW;
	chr->aibot->followprotectpropnum = prop - g_Vars.props;
	chr->aibot->forcemainloop = true;
}

void botApplyProtect(struct chrdata *chr, struct prop *prop)
{
	chr->aibot->command = AIBOTCMD_PROTECT;
	chr->aibot->followprotectpropnum = prop - g_Vars.props;
	chr->aibot->forcemainloop = true;
}

void botApplyDefend(struct chrdata *chr, struct coord *pos, s16 *room, f32 arg3)
{
	chr->aibot->command = AIBOTCMD_DEFEND;
	chr->aibot->defendholdpos.x = pos->x;
	chr->aibot->defendholdpos.y = pos->y;
	chr->aibot->defendholdpos.z = pos->z;
	roomsCopy(room, chr->aibot->defendholdrooms);
	chr->aibot->unk098 = arg3;
	chr->aibot->forcemainloop = true;
}

void botApplyHold(struct chrdata *chr, struct coord *pos, s16 *room, f32 arg3)
{
	chr->aibot->command = AIBOTCMD_HOLD;
	chr->aibot->defendholdpos.x = pos->x;
	chr->aibot->defendholdpos.y = pos->y;
	chr->aibot->defendholdpos.z = pos->z;
	roomsCopy(room, chr->aibot->defendholdrooms);
	chr->aibot->unk098 = arg3;
	chr->aibot->forcemainloop = true;
}

void botApplyScenarioCommand(struct chrdata *chr, u32 command)
{
	chr->aibot->command = command;
	chr->aibot->forcemainloop = true;
}

void botLoseGun(struct chrdata *chr, struct prop *attackerprop)
{
	if (chr->aibot->weaponnum >= WEAPON_FALCON2 && chr->aibot->weaponnum != WEAPON_BRIEFCASE2) {
		struct prop *prop = NULL;
		struct defaultobj *obj;

		if (chr->weapons_held[HAND_LEFT]) {
			obj = chr->weapons_held[HAND_LEFT]->obj;

			obj->hidden |= OBJHFLAG_REAPABLE;
			chr->weapons_held[HAND_LEFT] = NULL;
		}

		if (chr->weapons_held[HAND_RIGHT]) {
			prop = chr->weapons_held[HAND_RIGHT];
			weaponSetGunfireVisible(prop, false, -1);
			chr->weapons_held[HAND_RIGHT] = NULL;
		} else {
			s32 modelnum = playermgrGetModelOfWeapon(chr->aibot->weaponnum);

			if (modelnum >= 0) {
				prop = weaponCreateForChr(chr, modelnum, chr->aibot->weaponnum, OBJFLAG_WEAPON_AICANNOTUSE, NULL, NULL);
			}
		}

		if (prop && prop->obj) {
			obj = prop->obj;
			objSetDropped(prop, DROPTYPE_DEFAULT);
			chr->hidden |= CHRHFLAG_00000001;

			if (obj->hidden & OBJHFLAG_PROJECTILE) {
				obj->projectile->unk0b4 = TICKS(240);
				obj->projectile->unk108 = attackerprop;
			}
		}

		botinvRemoveItem(chr, chr->aibot->weaponnum);

		chr->aibot->loadedammo[0] = 0;
		chr->aibot->loadedammo[1] = 0;

		botinvSwitchToWeapon(chr, WEAPON_UNARMED, FUNC_PRIMARY);
	}
}

/**
 * Set the bot's target and update tracking figures.
 *
 * This should be called on each tick even if the target hasn't changed
 * because the tracking figures need to be constantly updated.
 */
void botSetTarget(struct chrdata *botchr, s32 propnum)
{
	struct chrdata *otherchr = NULL;
	s32 index;

	if (propnum >= 0) {
		otherchr = (g_Vars.props + propnum)->chr;

		index = mpPlayerGetIndex(otherchr);

		botchr->aibot->targetinsight = botchr->aibot->chrsinsight[index];
		botchr->aibot->targetlastseen60 = botchr->aibot->chrslastseen60[index];
	} else {
		botchr->aibot->targetinsight = false;
		botchr->aibot->targetlastseen60 = -1;
	}

	if (botchr->aibot->targetlastseen60 > botchr->aibot->lastseenanytarget60) {
		botchr->aibot->lastseenanytarget60 = botchr->aibot->targetlastseen60;
	}

	if (botchr->target != propnum) {
		botchr->target = propnum;
		botchr->aibot->shootdelaytimer60 = 0;
		botchr->aibot->waypoints[0] = NULL;
		botchr->aibot->unk208 = 0;

		if (botchr->aibot->targetinsight && otherchr) {
			botchr->aibot->targetcloaktimer60 = TICKS(120);
		} else {
			botchr->aibot->targetcloaktimer60 = 0;
		}
	} else {
		if (botchr->aibot->targetinsight) {
			if (g_Vars.lvupdate240 > 0) {
				botchr->aibot->shootdelaytimer60 += g_Vars.diffframe60;
			}
		} else {
			if (g_Vars.lvupdate240 > 0) {
				botchr->aibot->shootdelaytimer60 -= g_Vars.diffframe60;
			}

			if (botchr->aibot->shootdelaytimer60 < 0) {
				botchr->aibot->shootdelaytimer60 = 0;
			}
		}
	}

	if (botchr->aibot->targetinsight && otherchr) {
		if ((otherchr->hidden & CHRHFLAG_CLOAKED) == 0) {
			botchr->aibot->targetcloaktimer60 = TICKS(120);
		} else {
			if (botchr->aibot->targetcloaktimer60 > 0) {
				botchr->aibot->targetcloaktimer60 -= g_Vars.lvupdate240_60;
			}
		}
	} else {
		botchr->aibot->targetcloaktimer60 = 0;
	}
}

bool botIsTargetInvisible(struct chrdata *botchr, struct chrdata *otherchr)
{
	if (otherchr->prop->type == PROPTYPE_PLAYER && !g_Vars.bondvisible) {
		return true;
	}

	if (otherchr->chrflags & CHRCFLAG_HIDDEN) {
		return true;
	}

	if ((otherchr->hidden & CHRHFLAG_CLOAKED)) {
		if (botchr && botchr->aibot
				&& ((botchr->target != -1 && chrGetTargetProp(botchr) == otherchr->prop && botchr->aibot->targetcloaktimer60 > 0)
				|| (botchr->aibot->canseecloaked && chrIsLookingAtPos(botchr, &otherchr->prop->pos, 32)))) {
			return false;
		}

		return true;
	}

	return false;
}

/**
 * Return true if there's ground between the chr and the death barrier.
 *
 * The death barrier is at -30000.
 * It's assumed that no walkable ground exists below -20000.
 */
bool botHasGround(struct chrdata *chr)
{
	return chr->ground >= -20000;
}

void bot0f192a74(struct chrdata *chr)
{
	struct aibot *aibot = chr->aibot;
	s32 diff = aibot->config->difficulty;
	s32 i;
	f32 fVar12;
	f32 fVar11;
	f32 tmp;

	aibot->unk1cc -= g_Vars.lvupdate240_60;

	if (aibot->unk1cc <= 0) {
		aibot->unk1d0 = random();
		aibot->unk1cc = TICKS(20) + random() % TICKS(20);
	}

	if (g_Vars.lvupdate240 > 0) {
		if (aibot->targetinsight) {
			aibot->unk1d4 += g_Vars.diffframe60;
		} else {
			aibot->unk1d4 -= g_Vars.diffframe60;
		}

		tmp = g_BotDifficulties[diff].unk10 * (aibot->speedtheta * g_Vars.lvupdate240f);

		if (tmp < 0) {
			tmp = -tmp;
		}

		aibot->unk1d4 -= tmp;
	}

	if (aibot->unk1d4 > aibot->shootdelaytimer60) {
		aibot->unk1d4 = aibot->shootdelaytimer60;
	}

	if (aibot->unk1d4 < 0) {
		aibot->unk1d4 = 0;
	}

	if (aibot->unk1d4 >= g_BotDifficulties[diff].unk0c) {
		aibot->unk1d4 = g_BotDifficulties[diff].unk0c;
		fVar12 = 0;
		fVar11 = 0;
	} else {
		tmp = (g_BotDifficulties[diff].unk0c - aibot->unk1d4) / g_BotDifficulties[diff].unk0c;
		fVar12 = g_BotDifficulties[diff].unk04 * tmp;
		fVar11 = g_BotDifficulties[diff].unk08 * tmp;
	}

	if (chr->target != -1) {
		struct prop *target = chrGetTargetProp(chr);

		if (target->chr->hidden & CHRHFLAG_CLOAKED) {
			if (fVar11 < g_BotDifficulties[diff].unk14) {
				fVar11 = g_BotDifficulties[diff].unk14;
			}
		}
	}

	if (fVar11 < g_BotDifficulties[diff].unk18) {
		fVar11 = g_BotDifficulties[diff].unk18;
	}

	aibot->unk1c8 = (fVar11 - fVar12) * (aibot->unk1d0 & 0xffff) * 0.000015259021893144f + fVar12;

	if (aibot->unk1d0 & 0x10000) {
		aibot->unk1c8 = -aibot->unk1c8;
	}

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		aibot->unk1c4 = aibot->unk1c4 * (PAL ? 0.97f : 0.97500002384186f) + aibot->unk1c8;
	}

	aibot->unk1c0 = aibot->unk1c4 * (PAL ? 0.029999971389771f : 0.024999976158142f);
}

/**
 * Return true if the bot is a peacesim and is happy to fight the given chr,
 * or if the bot is not a peacesim.
 */
bool botPassesPeaceCheck(struct chrdata *botchr, struct chrdata *otherchr)
{
	struct aibot *aibot = botchr->aibot;
	bool pass = true;

	if (aibot->config->type == BOTTYPE_PEACE) {
		s32 otherweaponnum = botGetWeaponNum(otherchr);

		if (otherweaponnum == WEAPON_NONE || otherweaponnum == WEAPON_UNARMED) {
			pass = false;
		}
	}

	return pass;
}

/**
 * Return true if the bot is a cowardsim and is happy to fight the given chr,
 * or if the bot is not a cowardsim.
 */
bool botPassesCowardCheck(struct chrdata *botchr, struct chrdata *otherchr)
{
	struct aibot *aibot = botchr->aibot;
	bool pass = true;
	s32 otherweaponnum;
	s32 myscore1;
	s32 myscore2;
	s32 theirscore1;
	s32 theirscore2;

	if (aibot->config->type == BOTTYPE_COWARD) {
		otherweaponnum = botGetWeaponNum(otherchr);

		botinvScoreWeapon(botchr, aibot->weaponnum, FUNC_PRIMARY, 1, false, &myscore1, &myscore2, false, false);
		botinvScoreWeapon(botchr, otherweaponnum, FUNC_PRIMARY, 1, false, &theirscore1, &theirscore2, false, false);

		if (theirscore1 >= myscore1 - 30) {
			pass = false;
		}
	}

	return pass;
}

/**
 * Choose and assign a general target to chase and attack.
 *
 * The function considers the distances and visibility of other chrs.
 *
 * The function does not compare weapons with the target, nor ammo counts,
 * and does not factor in the bot types (eg. VengeSim).
 */
void botChooseGeneralTarget(struct chrdata *botchr)
{
	struct aibot *aibot = botchr->aibot;
	s32 i;
	s32 j;
	bool distancesdone[MAX_MPCHRS];
	s16 room = -1;
	struct chrdata *trychr;
	s32 playernum;

	// Advance the bot's internal pointer to the next chr
	// and update stats about that chr
	aibot->queryplayernum = (aibot->queryplayernum + 1) % g_MpNumChrs;

	trychr = mpGetChrFromPlayerIndex(aibot->queryplayernum);

	if (trychr != botchr) {
		// This condition passes on average once every 4 minutes per player.
		// However, the usage of canseecloaked appears to be botched.
		// It is implemented in botIsTargetInvisible, but that function is not
		// called here while canseecloaked is true.
		if (random() % TICKS(4 * 60 * 60) < g_MpNumChrs * g_Vars.lvupdate240_60) {
			aibot->canseecloaked = true;
		}

		aibot->chrdistances[aibot->queryplayernum] = chrGetDistanceToCoord(botchr, &trychr->prop->pos);
		aibot->chrsinsight[aibot->queryplayernum] = chrCanSeeChr(botchr, trychr, &room);
		aibot->chrrooms[aibot->queryplayernum] = room;

		aibot->canseecloaked = false;
	}

	// Update last seen timestamps for all visible chrs
	for (i = 0; i < g_MpNumChrs; i++) {
		if (aibot->chrsinsight[i]) {
			aibot->chrslastseen60[i] = g_Vars.lvframe60;
		}
	}

	// Update chrnumsbydistanceasc
	for (i = 0; i < g_MpNumChrs; i++) {
		distancesdone[i] = false;
	}

	for (i = 0; i < g_MpNumChrs; i++) {
		s32 closestplayernum = -1;
		f32 closestdistance = 0;

		for (j = 0; j < g_MpNumChrs; j++) {
			if (!distancesdone[j] && (closestplayernum < 0 || aibot->chrdistances[j] < closestdistance)) {
				closestplayernum = j;
				closestdistance = aibot->chrdistances[j];
			}
		}

		if (closestplayernum >= 0) {
			aibot->chrnumsbydistanceasc[i] = closestplayernum;
			distancesdone[closestplayernum] = true;
		}
	}

	bot0f192a74(botchr);

	// If the bot is data uplinking, clear the target
	if (botchr->myaction == MA_AIBOTDOWNLOAD) {
		botSetTarget(botchr, -1);
		return;
	}

	// If the bot is attacking, keep the same target if possible
	if (botchr->myaction == MA_AIBOTATTACK
			&& aibot->attackingplayernum >= 0
			&& aibot->chrsinsight[aibot->attackingplayernum]
			&& !chrIsDead(g_MpAllChrPtrs[aibot->attackingplayernum])) {
		botSetTarget(botchr, g_MpAllChrPtrs[aibot->attackingplayernum]->prop - g_Vars.props);
		return;
	}

	// Check if existing target needs to be invalidated
	if (botchr->target != -1) {
		struct prop *targetprop = chrGetTargetProp(botchr);

		if (chrIsDead(targetprop->chr)) {
			botchr->target = -1;
		}

		if (!botchr->aibot->targetinsight && botIsTargetInvisible(botchr, targetprop->chr)) {
			botchr->target = -1;
		}

		if (chrCompareTeams(botchr, targetprop->chr, COMPARE_FRIENDS)) {
			botchr->target = -1;
		}

		if (!botPassesPeaceCheck(botchr, targetprop->chr)) {
			botchr->target = -1;
		}

		if (!botchr->aibot->targetinsight && !botPassesCowardCheck(botchr, targetprop->chr)) {
			botchr->target = -1;
		}
	}

	// If there's no existing target, try all chrs in distance order
	if (botchr->target == -1) {
		s32 closestavailablechrnum = -1;
		s32 tmp;
		s32 stack;

		for (tmp = 0; tmp < g_MpNumChrs; tmp++) {
			s32 i = aibot->chrnumsbydistanceasc[tmp];
			trychr = mpGetChrFromPlayerIndex(i);

			if (trychr != botchr
					&& !chrIsDead(trychr)
					&& chrCompareTeams(botchr, trychr, COMPARE_ENEMIES)
					&& botPassesPeaceCheck(botchr, trychr)) {
				// If the chr is in sight, that's it
				if (aibot->chrsinsight[i]) {
					botSetTarget(botchr, trychr->prop - g_Vars.props);
					return;
				}

				// Meat and easy sims will target the closest chr, even if that
				// chr isn't in sight and when there are other chrs in sight who
				// are further away
				if (!botIsTargetInvisible(botchr, trychr)
						&& (aibot->config->difficulty == BOTDIFF_MEAT || aibot->config->difficulty == BOTDIFF_EASY)) {
					botSetTarget(botchr, trychr->prop - g_Vars.props);
					return;
				}

				// Other sim types will prioritise chrs in sight, which means
				// the closest out of sight chrnum must be stored for later
				if (!botIsTargetInvisible(botchr, trychr) && closestavailablechrnum < 0) {
					closestavailablechrnum = i;
				}
			}
		}

		// Use closest out of sight chr
		if (closestavailablechrnum >= 0) {
			trychr = mpGetChrFromPlayerIndex(closestavailablechrnum);
			botSetTarget(botchr, trychr->prop - g_Vars.props);
			return;
		}

		// No one available - maybe everyone else is dead or cloaked
		botSetTarget(botchr, -1);
		return;
	}

	// Bot has an existing target
	// If they're still in sight, keep the target
	playernum = mpPlayerGetIndex((g_Vars.props + botchr->target)->chr);

	if (aibot->chrsinsight[playernum]) {
		botSetTarget(botchr, botchr->target);
		return;
	}

	// Target is no longer in sight
	// Check for other chrs who are in sight, by distance
	for (i = 0; i < g_MpNumChrs; i++) {
		if (aibot->chrsinsight[aibot->chrnumsbydistanceasc[i]]) {
			trychr = mpGetChrFromPlayerIndex(aibot->chrnumsbydistanceasc[i]);

			if (trychr != botchr
					&& !chrIsDead(trychr)
					&& chrCompareTeams(botchr, trychr, COMPARE_ENEMIES)
					&& botPassesPeaceCheck(botchr, trychr)) {
				botSetTarget(botchr, trychr->prop - g_Vars.props);
				return;
			}
		}
	}

	// No one else in sight - maintain original target
	botSetTarget(botchr, botchr->target);
}

/**
 * Check if the bot is capable of following the given chr.
 *
 * They are not capable if it would create a circular follow loop.
 */
bool botCanFollow(struct chrdata *botchr, struct chrdata *leader)
{
	bool canfollow = true;

	while (true) {
		struct aibot *aibot = leader->aibot;

		if (!aibot || leader->myaction != MA_AIBOTFOLLOW || aibot->followingplayernum < 0) {
			// Okay to follow
			break;
		}

		leader = g_MpAllChrPtrs[aibot->followingplayernum];

		if (leader == botchr) {
			// Can't follow - it would create a follow loop
			canfollow = false;
			break;
		}
	}

	return canfollow;
}

s32 botFindTeammateToFollow(struct chrdata *chr, f32 range)
{
	s32 result = -1;

	if ((g_MpSetup.options & MPOPTION_TEAMSENABLED)
			&& chr->myaction != MA_AIBOTFOLLOW
			&& (random() % 100) < chr->aibot->followchance) {
		f32 closestdistance = 0;
		s32 closestplayernum = -1;
		s32 i;

		for (i = 0; i < g_MpNumChrs; i++) {
			if (chr != g_MpAllChrPtrs[i]
					&& !chrIsDead(g_MpAllChrPtrs[i])
					&& chr->team == g_MpAllChrPtrs[i]->team
					&& botCanFollow(chr, g_MpAllChrPtrs[i])) {
				f32 distance = chr->aibot->chrdistances[i];

				if (closestplayernum < 0 || distance < closestdistance) {
					closestplayernum = i;
					closestdistance = distance;
				}
			}
		}

		if (closestplayernum >= 0 && closestdistance < range) {
			result = closestplayernum;
		}
	}

	return result;
}

void botScheduleReload(struct chrdata *chr, s32 handnum)
{
	chr->aibot->timeuntilreload60[handnum] = g_AibotWeaponPreferences[chr->aibot->weaponnum].reloaddelay * (PAL ? 50 : 60);

	if (g_AibotWeaponPreferences[chr->aibot->weaponnum].allowpartialreloaddelay) {
		s32 capacity = botactGetClipCapacityByFunction(chr->aibot->weaponnum, chr->aibot->gunfunc);

		chr->aibot->timeuntilreload60[handnum] *= capacity - chr->aibot->loadedammo[handnum];
		chr->aibot->timeuntilreload60[handnum] /= capacity;
	}
}

#define HASENOUGHPRI(aibot, weaponnum, goal) (g_AibotWeaponPreferences[weaponnum].haspriammogoal && botactGetAmmoQuantityByWeapon(aibot, weaponnum, FUNC_PRIMARY, true) >= (goal))
#define HASENOUGHSEC(aibot, weaponnum, goal) (g_AibotWeaponPreferences[weaponnum].hassecammogoal && botactGetAmmoQuantityByWeapon(aibot, weaponnum, FUNC_SECONDARY, true) >= (goal))

/**
 * Find a prop for the bot to pick up.
 *
 * Criteria can be:
 *
 * PICKUPCRITERIA_DEFAULT:
 *     This is the most common criteria. It is used when the bot has spawned and
 *     is gathering weapons, as well as when they return to their main loop.
 *
 * PICKUPCRITERIA_CRITICAL:
 *     Find props only if the bot needs them critically, eg if they are low on
 *     shield or ammo. This is used when the bot has other things it can be
 *     doing such as scenario objectives and has to decide between the two.
 *
 * PICKUPCRITERIA_ANY:
 *     Find pretty much any prop. This is used when the bot has nothing else to
 *     do (eg. if all opponents are cloaked) and may as well stock up on ammo.
 */
struct prop *botFindPickup(struct chrdata *chr, s32 criteria)
{
	struct aibot *aibot = chr->aibot;
	s32 weaponnums[6];
	s32 scores1[6];
	s32 scores2[6];
	struct prop *weapproplist[6];
	f32 weapdistlist[6];
	struct prop *ammoproplist[33];
	f32 ammodistlist[33];
	struct invitem *invitems[6];
	s32 i;
	s32 j;
	struct prop *prop;
	struct weaponobj *weapon;
	struct prop *chosenprop = NULL;
	bool barelydominatinghill = false;
	s32 numteam;
	s32 numopponents;
	struct multiammocrateobj *crate;
	s32 weaponnum;
	f32 sqdist1;
	f32 sqdist2;
	struct defaultobj *obj;
	s32 ammotype;
	s32 bestscore1;
	bool done;

	if (&aibot);
	if (&criteria);

	// If the hill has one or two bots from the same team in it, the bots will
	// be less likely to leave the hill for pickups (barelydominatinghill = true).
	// If there are three or more then this limitation is removed.
	// The amount increases if there are opponents in the hill too.
	if (aibot->teamisonlyai
			&& g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL
			&& chr->prop->rooms[0] == g_ScenarioData.koh.hillrooms[0]) {
		numteam = botGetNumTeammatesDefendingHill(chr);
		numopponents = botGetNumOpponentsInHill(chr);

		if (numteam >= numopponents && numteam <= numopponents + 2) {
			barelydominatinghill = true;
		}
	}

	// botinvScoreAllWeapons populates weaponnums, scores1 and scores2
	// and sorts them by score1 descending
	botinvScoreAllWeapons(chr, weaponnums, scores1, scores2);

	for (i = 0; i < ARRAYCOUNT(weapproplist); i++) {
		weapproplist[i] = NULL;
	}

	for (i = 0; i < ARRAYCOUNT(ammoproplist); i++) {
		ammoproplist[i] = NULL;
	}

	for (i = 0; i < ARRAYCOUNT(weaponnums); i++) {
		invitems[i] = botinvGetItem(chr, weaponnums[i]);
	}

	// Iterate all active props and populate the proplist and distlist arrays.
	// Generally these arrays are populated with the closest prop of each weapon
	// and ammotype, however there's a 1/16 chance that any prop will be skipped
	// and a 1/16 chance that a further prop will overwrite the current closest.
	prop = g_Vars.activeprops;

	while (prop) {
		if (prop->parent == NULL && prop->timetoregen == 0) {
			if (prop->type == PROPTYPE_WEAPON) {
				weapon = prop->weapon;

				if ((weapon->base.flags3 & OBJFLAG3_ISFETCHTARGET) == 0) {
					sqdist1 = chrGetSquaredDistanceToCoord(chr, &prop->pos);

					for (i = 0; i < ARRAYCOUNT(weaponnums); i++) {
						if (weaponnums[i] > WEAPON_UNARMED && weaponnums[i] == weapon->weaponnum) {
							if (random() % 16) {
								if (weapproplist[i] == NULL || sqdist1 < weapdistlist[i] || random() % 16 == 0) {
									weapproplist[i] = prop;
									weapdistlist[i] = sqdist1;
								}
							}
							break;
						}
					}

					ammotype = botactGetAmmoTypeByFunction(weapon->weaponnum, FUNC_PRIMARY);

					if (ammotype > 0 && random() % 16) {
						if (ammoproplist[ammotype] == NULL || sqdist1 < ammodistlist[ammotype] || random() % 16 == 0) {
							ammoproplist[ammotype] = prop;
							ammodistlist[ammotype] = sqdist1;
						}
					}
				}
			} else if (prop->type == PROPTYPE_OBJ) {
				obj = prop->obj;

				if ((obj->flags3 & OBJFLAG3_ISFETCHTARGET) == 0) {
					if (obj->type == OBJTYPE_MULTIAMMOCRATE) {
						crate = (struct multiammocrateobj *)prop->obj;
						sqdist2 = chrGetSquaredDistanceToCoord(chr, &prop->pos);

						for (i = 0; i < 19; i++) {
							s32 ammotype = i + 1;

							if (crate->slots[i].quantity > 0) {
								weaponnum = botactGetWeaponByAmmoType(ammotype);

								if (weaponnum > 0) {
									for (j = 0; j < ARRAYCOUNT(weaponnums); j++) {
										if (weaponnums[j] > WEAPON_UNARMED && weaponnum == weaponnums[j]) {
											if (random() % 16) {
												if (weapproplist[j] == NULL || sqdist2 < weapdistlist[j] || random() % 16 == 0) {
													weapproplist[j] = prop;
													weapdistlist[j] = sqdist2;
												}
											}
											break;
										}
									}
								}

								if (random() % 16) {
									if (ammoproplist[ammotype] == NULL || sqdist2 < ammodistlist[ammotype] || random() % 16 == 0) {
										ammoproplist[ammotype] = prop;
										ammodistlist[ammotype] = sqdist2;
									}
								}
							}
						}
					} else if (obj->type == OBJTYPE_SHIELD) {
						for (i = 0; i < ARRAYCOUNT(weaponnums); i++) {
							if (weaponnums[i] == WEAPON_MPSHIELD) {
								sqdist2 = chrGetSquaredDistanceToCoord(chr, &prop->pos);

								if (random() % 16 == 0) {
									break;
								}

								if (weapproplist[i] == NULL || sqdist2 < weapdistlist[i] || random() % 16 == 0) {
									weapproplist[i] = prop;
									weapdistlist[i] = sqdist2;
								}

								break;
							}
						}
					}
				}
			}
		}

		prop = prop->next;
	}

	// Find the best score out of the 6 weapons, only considering ones which
	// the bot is allowed to carry and which require ammo
	bestscore1 = 0;
	done = false;

	for (i = 0; i < ARRAYCOUNT(weaponnums); i++) {
		if (1);
		if ((botinvAllowsWeapon(chr, weaponnums[i], FUNC_PRIMARY) || botinvAllowsWeapon(chr, weaponnums[i], FUNC_SECONDARY))
				&& (g_AibotWeaponPreferences[weaponnums[i]].haspriammogoal || g_AibotWeaponPreferences[weaponnums[i]].hassecammogoal)
				&& scores1[i] > bestscore1) {
			bestscore1 = scores1[i];
		}
	}

	// Decide if the bot wants to find a shield, based on the amount of health
	// and shield the bot currently has. This shield logic is done prior to
	// weapons and ammo, so a shield takes precedence.
	// Note that max health and shield is 8 each, and that the bot must be under
	// BOTH the limits for a shield to be fetched.
	for (i = 0; i < ARRAYCOUNT(weaponnums) && !done; i++) {
		if (weaponnums[i] == WEAPON_MPSHIELD
				&& (g_MpSetup.scenario != MPSCENARIO_HOLDTHEBRIEFCASE || !chr->aibot->hasbriefcase)) {
			f32 triggerathealth = 8.1f;
			f32 desiredshield = 0;
			s32 rand;

			if (aibot->config->type == BOTTYPE_SHIELD) {
				// ShieldSims are more likely to fetch shields
				if (criteria == PICKUPCRITERIA_ANY) {
					desiredshield = 7.9f;
				} else if (criteria == PICKUPCRITERIA_DEFAULT) {
					desiredshield = 6 - (aibot->randomfrac + aibot->randomfrac);
				} else if (criteria == PICKUPCRITERIA_CRITICAL) {
					desiredshield = 4 - (aibot->randomfrac + aibot->randomfrac);
				}
			} else if (barelydominatinghill) {
				// Bots will be less likely to fetch shields while defending the hill
				triggerathealth = 4 - (aibot->randomfrac + aibot->randomfrac);
				desiredshield = 1 - aibot->randomfrac;
			} else if (g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE && botShouldReturnCtcToken(chr)) {
				// Bots will be less likely to fetch shields while returning a CTC case
				triggerathealth = 3 - (aibot->randomfrac + aibot->randomfrac);
			} else if (chr->myaction == MA_AIBOTDOWNLOAD) {
				// Bots will be less likely to fetch shields while uplinking
				triggerathealth = 4 - (aibot->randomfrac + aibot->randomfrac);
				desiredshield = 1;
			} else {
				// Default behaviour
				if (criteria == PICKUPCRITERIA_ANY) {
					desiredshield = 7.9f;
				} else if (criteria == PICKUPCRITERIA_DEFAULT) {
					desiredshield = 4 - (aibot->randomfrac + aibot->randomfrac);
				} else if (criteria == PICKUPCRITERIA_CRITICAL) {
					desiredshield = 2 - aibot->randomfrac;
				}
			}

			// Meat, easy and normal sims reduce the limits further,
			// making them less likely to fetch shields.
			if (aibot->config->difficulty == BOTDIFF_MEAT) {
				rand = aibot->random2 % 8;

				if (rand < 2) {
					desiredshield = 0;
					triggerathealth = 0;
				} else if (rand < 4) {
					desiredshield = 0;
					triggerathealth = 2 - aibot->randomfrac;
				} else {
					desiredshield -= aibot->randomfrac * 16;

					if (desiredshield <= 0) {
						triggerathealth += desiredshield;
						desiredshield = 0;
					}
				}
			} else if (aibot->config->difficulty == BOTDIFF_EASY) {
				rand = aibot->random2 % 8;

				if (rand <= 0) {
					desiredshield = 0;
					triggerathealth = 0;
				} else {
					desiredshield -= aibot->randomfrac * 11;

					if (desiredshield <= 0) {
						triggerathealth += desiredshield;
						desiredshield = 0;
					}
				}
			} else if (aibot->config->difficulty == BOTDIFF_NORMAL) {
				desiredshield -= aibot->randomfrac * 4;

				if (desiredshield <= 0) {
					triggerathealth += desiredshield;
					desiredshield = 0;
				}
			}

			// Actually check the limits and decide if the shield is desired
			if (chr->maxdamage - chr->damage < triggerathealth
					&& chr->cshield <= desiredshield
					&& weapproplist[i] != NULL
					&& scores2[i] >= bestscore1) {
				chosenprop = weapproplist[i];
				done = true;
				break;
			}
		}
	}

	// Consider ammo for weapons that the bot already has.
	// This loop is iterated in order of highest scoring weapons first. If the
	// first iterated weapon which the bot holds has enough ammo then the lower
	// scoring weapons will not be considered, nor will any new weapons be
	// picked up.
	for (i = 0; i < ARRAYCOUNT(weaponnums) && !done; i++) {
		if (weaponnums[i] != WEAPON_MPSHIELD
				&& invitems[i] != NULL
				&& (g_AibotWeaponPreferences[weaponnums[i]].haspriammogoal
					|| g_AibotWeaponPreferences[weaponnums[i]].hassecammogoal)
				&& scores2[i] >= bestscore1) {
			s32 desiredpriammo;
			s32 desiredsecammo;
			s32 funcnum;
			bool include_equipped = true;
			s32 stack;

			// Don't go after ammo when returning a CTC token
			if (g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE && botShouldReturnCtcToken(chr)) {
				done = true;
				break;
			}

			// Don't go after ammo when downloading in Hacker Central
			if (chr->myaction == MA_AIBOTDOWNLOAD) {
				done = true;
				break;
			}

			if (barelydominatinghill) {
				// If the bot's team is only barely controlling the hill,
				// don't leave it unless the bot is out of ammo, and even then
				// just get one ammo pickup
				desiredpriammo = g_AibotWeaponPreferences[weaponnums[i]].criticalammopri;

				if (desiredpriammo > 1) {
					desiredpriammo = 1;
				}

				desiredsecammo = g_AibotWeaponPreferences[weaponnums[i]].criticalammosec;

				if (desiredsecammo > 1) {
					desiredsecammo = 1;
				}

				if (HASENOUGHPRI(aibot, weaponnums[i], desiredpriammo) || HASENOUGHSEC(aibot, weaponnums[i], desiredsecammo)) {
					done = true;
					break;
				}
			} else if (criteria == PICKUPCRITERIA_ANY) {
				// If looking for any pickups at all, use the weapon's ammo
				// capacities as the goal ammo
				desiredpriammo = bgunGetCapacityByAmmotype(botactGetAmmoTypeByFunction(weaponnums[i], FUNC_PRIMARY));
				desiredsecammo = bgunGetCapacityByAmmotype(botactGetAmmoTypeByFunction(weaponnums[i], FUNC_SECONDARY));

				// If bot has max ammo for both weapon's functions
				if ((g_AibotWeaponPreferences[weaponnums[i]].haspriammogoal == false
							|| botactGetAmmoQuantityByWeapon(aibot, weaponnums[i], FUNC_PRIMARY, false) >= desiredpriammo)
						&& (g_AibotWeaponPreferences[weaponnums[i]].hassecammogoal == false
							|| botactGetAmmoQuantityByWeapon(aibot, weaponnums[i], FUNC_SECONDARY, false) >= desiredsecammo)) {
					// Consider next weapon
					continue;
				}

				include_equipped = false;
			} else if (criteria == PICKUPCRITERIA_DEFAULT) {
				// Default - use the target ammo amount
				desiredpriammo = g_AibotWeaponPreferences[weaponnums[i]].targetammopri;
				desiredsecammo = g_AibotWeaponPreferences[weaponnums[i]].targetammosec;

				if (HASENOUGHPRI(aibot, weaponnums[i], desiredpriammo) || HASENOUGHSEC(aibot, weaponnums[i], desiredsecammo)) {
					done = true;
					break;
				}
			} else if (criteria == PICKUPCRITERIA_CRITICAL) {
				// Critical - use the critical ammo amount
				desiredpriammo = g_AibotWeaponPreferences[weaponnums[i]].criticalammopri;
				desiredsecammo = g_AibotWeaponPreferences[weaponnums[i]].criticalammosec;

				if (HASENOUGHPRI(aibot, weaponnums[i], desiredpriammo) || HASENOUGHSEC(aibot, weaponnums[i], desiredsecammo)) {
					done = true;
					break;
				}
			}

			// Iterate both weapon functions and check
			// if the bot has enough ammo for that function
			for (funcnum = 0; funcnum < 2; funcnum++) {
				if (botinvAllowsWeapon(chr, weaponnums[i], funcnum)) {
					s32 ammotype = botactGetAmmoTypeByFunction(weaponnums[i], funcnum);

					if (ammotype > 0) {
						s32 goal = funcnum ? desiredsecammo : desiredpriammo;
						s32 qty = botactGetAmmoQuantityByType(aibot, ammotype, include_equipped);

						if (qty < goal && ammoproplist[ammotype]) {
							chosenprop = ammoproplist[ammotype];
							done = true;
							break;
						}
					}
				}
			}
		}
	}

	// If done is still false, the bot mustn't have any weapons.
	// Consider picking up weapons that the bot doesn't have.
	// Fetch the highest scoring weapon if there are any pickups for it.
	for (i = 0; i < ARRAYCOUNT(weaponnums) && !done; i++) {
		if (weaponnums[i] != WEAPON_MPSHIELD) {
			if (g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE && botShouldReturnCtcToken(chr)) {
				done = true;
				break;
			}

			if (chr->myaction == MA_AIBOTDOWNLOAD) {
				done = true;
				break;
			}

			if (!barelydominatinghill
					&& (botinvAllowsWeapon(chr, weaponnums[i], FUNC_PRIMARY) || botinvAllowsWeapon(chr, weaponnums[i], FUNC_SECONDARY))
					&& invitems[i] == NULL
					&& weapproplist[i] != NULL) {
				chosenprop = weapproplist[i];
				done = true;
				break;
			}
		}
	}

	if (criteria == PICKUPCRITERIA_ANY) {
		// Consider ammo even for weapons that the bot doesn't have
		for (i = 0; i < ARRAYCOUNT(weaponnums) && !done; i++) {
			if (weaponnums[i] != WEAPON_MPSHIELD) {
				for (j = 0; j < 2; j++) {
					if (botinvAllowsWeapon(chr, weaponnums[i], j)) {
						s32 ammotype = botactGetAmmoTypeByFunction(weaponnums[i], j);

						if (ammotype > 0
								&& botactGetAmmoQuantityByType(aibot, ammotype, false) < bgunGetCapacityByAmmotype(ammotype)
								&& ammoproplist[ammotype] != NULL) {
							chosenprop = ammoproplist[ammotype];
							done = true;
							break;
						}
					}
				}
			}
		}
	}

	return chosenprop;
}

/**
 * Check if the bot wants to do a critical pickup.
 *
 * This returns true when the bot is low on health or ammo and there are pickups
 * available.
 */
bool botCanDoCriticalPickup(struct chrdata *chr)
{
	return botFindPickup(chr, PICKUPCRITERIA_CRITICAL) != NULL;
}

/**
 * Find a pickup to fetch based on default criteria. Default criteria basically
 * means a good amount of ammo - not lacking but not excessive either.
 */
struct prop *botFindDefaultPickup(struct chrdata *chr)
{
	return botFindPickup(chr, PICKUPCRITERIA_DEFAULT);
}

/**
 * Find any pickup to fetch. This is used when the bot has nothing else to do
 * (eg. if all opponents are cloaked).
 */
struct prop *botFindAnyPickup(struct chrdata *chr)
{
	return botFindPickup(chr, PICKUPCRITERIA_ANY);
}

s32 botGetTeamSize(struct chrdata *chr)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i < g_MpNumChrs; i++) {
		if (chr->team == g_MpAllChrPtrs[i]->team) {
			count++;
		}
	}

	return count;
}

s32 botGetCountInTeamDoingCommand(struct chrdata *self, u32 command, bool includeself)
{
	s32 count = 0;
	s32 i;

	for (i = PLAYERCOUNT(); i < g_MpNumChrs; i++) {
		if (self->team == g_MpAllChrPtrs[i]->team) {
			if (includeself || self != g_MpAllChrPtrs[i]) {
				if (command == g_MpAllChrPtrs[i]->aibot->command) {
					count++;
				}
			}
		}
	}

	return count;
}

s32 botIsChrsCtcTokenHeld(struct chrdata *chr)
{
	struct mpchrconfig *mpchr = g_MpAllChrConfigPtrs[mpPlayerGetIndex(chr)];
	struct prop *prop = g_ScenarioData.ctc.tokens[mpchr->team];

	return prop && (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER);
}

/**
 * If chr doesn't have the case, return false.
 * If chr has the case:
 *     If chr is on a team by themself and their token is stolen, return false
 *     Otherwise, return true
 */
bool botShouldReturnCtcToken(struct chrdata *chr)
{
	if (chr->aibot->hascase) {
		if (!chr->aibot->teamisonlyai || botGetTeamSize(chr) >= 2 || !botIsChrsCtcTokenHeld(chr)) {
			return true;
		}
	}

	return false;
}

s32 botGetNumTeammatesDefendingHill(struct chrdata *bot)
{
	s32 count = 0;
	s32 i;

	for (i = 0; i < g_MpNumChrs; i++) {
		if (bot->team == g_MpAllChrPtrs[i]->team
				&& g_MpAllChrPtrs[i]->prop->rooms[0] == g_ScenarioData.koh.hillrooms[0]) {
			if (g_MpAllChrPtrs[i]->aibot->command == AIBOTCMD_DEFHILL
					|| g_MpAllChrPtrs[i]->aibot->command == AIBOTCMD_HOLDHILL) {
				count++;
			}
		}
	}

	return count;
}

/**
 * Find the opposing team who has the most players in the hill and return the
 * number of their players who are in the hill.
 *
 * This function is slightly misnamed.
 */
s32 botGetNumOpponentsInHill(struct chrdata *chr)
{
	struct mpchrconfig *mpchr = g_MpAllChrConfigPtrs[mpPlayerGetIndex(chr)];
	struct mpchrconfig *loopmpchr;
	s32 countsperteam[8] = {0};
	s32 max = 0;
	s32 i;

	for (i = 0; i < g_MpNumChrs; i++) {
		if (g_MpAllChrPtrs[i]->prop->rooms[0] == g_ScenarioData.koh.hillrooms[0]) {
			s32 mpindex = func0f18d074(i);

			loopmpchr = MPCHR(mpindex);

			if (loopmpchr->team != mpchr->team) {
				countsperteam[loopmpchr->team]++;
			}
		}
	}

	for (i = 0; i < 8; i++) {
		if (countsperteam[i] > max) {
			max = countsperteam[i];
		}
	}

	return max;
}

#if VERSION == VERSION_PAL_FINAL
GLOBAL_ASM(
glabel botTickUnpaused
.late_rodata
glabel var7f1b8f54
.word 0x49742400
glabel var7f1b8f58
.word botTickUnpaused+0x2398
glabel var7f1b8f5c
.word botTickUnpaused+0x23fc
glabel var7f1b8f60
.word botTickUnpaused+0x23fc
glabel var7f1b8f64
.word botTickUnpaused+0x23fc
glabel var7f1b8f68
.word botTickUnpaused+0x2398
glabel var7f1b8f6c
.word botTickUnpaused+0x2398
glabel var7f1b8f70
.word botTickUnpaused+0x2398
glabel var7f1b8f74
.word botTickUnpaused+0x23fc
glabel var7f1b8f78
.word botTickUnpaused+0x23fc
glabel var7f1b8f7c
.word botTickUnpaused+0x2398
glabel var7f1b8f80
.word botTickUnpaused+0x2398
glabel var7f1b8f84
.word botTickUnpaused+0x2398
glabel var7f1b8f88
.word botTickUnpaused+0x2398
glabel var7f1b8f8c
.word botTickUnpaused+0x2398
glabel var7f1b8f90
.word botTickUnpaused+0x2398
glabel var7f1b8f94
.word botTickUnpaused+0x2398
glabel var7f1b8f98
.word botTickUnpaused+0x2398
glabel var7f1b8f9c
.word botTickUnpaused+0x2398
glabel var7f1b8fa0
.word botTickUnpaused+0x2398
glabel var7f1b8fa4
.word botTickUnpaused+0x2474
glabel var7f1b8fa8
.word botTickUnpaused+0x2398
glabel var7f1b8fac
.word botTickUnpaused+0x2398
glabel var7f1b8fb0
.word botTickUnpaused+0x2398
glabel var7f1b8fb4
.word botTickUnpaused+0x2398
glabel var7f1b8fb8
.word botTickUnpaused+0x2398
glabel var7f1b8fbc
.word botTickUnpaused+0x23fc
glabel var7f1b8fc0
.word botTickUnpaused+0x2398
glabel var7f1b8fc4
.word botTickUnpaused+0x2450
glabel var7f1b8fc8
.word 0x3d4ccccd
.text
/*  f195bf8:	27bdfd08 */ 	addiu	$sp,$sp,-760
/*  f195bfc:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f195c00:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f195c04:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f195c08:	0080a025 */ 	move	$s4,$a0
/*  f195c0c:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f195c10:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f195c14:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f195c18:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f195c1c:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f195c20:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f195c24:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f195c28:	0fc0e706 */ 	jal	chrIsDead
/*  f195c2c:	2415ffff */ 	li	$s5,-1
/*  f195c30:	14400a77 */ 	bnez	$v0,.PF0f198610
/*  f195c34:	3c16800a */ 	lui	$s6,0x800a
/*  f195c38:	8e9202d4 */ 	lw	$s2,0x2d4($s4)
/*  f195c3c:	26d6a510 */ 	addiu	$s6,$s6,-23280
/*  f195c40:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f195c44:	8e4e02cc */ 	lw	$t6,0x2cc($s2)
/*  f195c48:	01cfc823 */ 	subu	$t9,$t6,$t7
/*  f195c4c:	07210017 */ 	bgez	$t9,.PF0f195cac
/*  f195c50:	ae5902cc */ 	sw	$t9,0x2cc($s2)
/*  f195c54:	0c004ad4 */ 	jal	random
/*  f195c58:	00000000 */ 	nop
/*  f195c5c:	24012ee0 */ 	li	$at,0x2ee0
/*  f195c60:	0041001b */ 	divu	$zero,$v0,$at
/*  f195c64:	00004810 */ 	mfhi	$t1
/*  f195c68:	252a05dc */ 	addiu	$t2,$t1,0x5dc
/*  f195c6c:	0c004ad4 */ 	jal	random
/*  f195c70:	ae4a02cc */ 	sw	$t2,0x2cc($s2)
/*  f195c74:	0c004ad4 */ 	jal	random
/*  f195c78:	ae4202d0 */ 	sw	$v0,0x2d0($s2)
/*  f195c7c:	44822000 */ 	mtc1	$v0,$f4
/*  f195c80:	3c014f80 */ 	lui	$at,0x4f80
/*  f195c84:	04410004 */ 	bgez	$v0,.PF0f195c98
/*  f195c88:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f195c8c:	44814000 */ 	mtc1	$at,$f8
/*  f195c90:	00000000 */ 	nop
/*  f195c94:	46083180 */ 	add.s	$f6,$f6,$f8
.PF0f195c98:
/*  f195c98:	3c012f80 */ 	lui	$at,0x2f80
/*  f195c9c:	44815000 */ 	mtc1	$at,$f10
/*  f195ca0:	00000000 */ 	nop
/*  f195ca4:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f195ca8:	e65202d4 */ 	swc1	$f18,0x2d4($s2)
.PF0f195cac:
/*  f195cac:	00008025 */ 	move	$s0,$zero
/*  f195cb0:	02403825 */ 	move	$a3,$s2
.PF0f195cb4:
/*  f195cb4:	84e2002c */ 	lh	$v0,0x2c($a3)
/*  f195cb8:	5840000f */ 	blezl	$v0,.PF0f195cf8
/*  f195cbc:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f195cc0:	8ecb0038 */ 	lw	$t3,0x38($s6)
/*  f195cc4:	02802025 */ 	move	$a0,$s4
/*  f195cc8:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f195ccc:	a4ec002c */ 	sh	$t4,0x2c($a3)
/*  f195cd0:	84ed002c */ 	lh	$t5,0x2c($a3)
/*  f195cd4:	5da00037 */ 	bgtzl	$t5,.PF0f195db4
/*  f195cd8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f195cdc:	02002825 */ 	move	$a1,$s0
/*  f195ce0:	24060001 */ 	li	$a2,0x1
/*  f195ce4:	0fc66ad0 */ 	jal	botactReload
/*  f195ce8:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f195cec:	10000030 */ 	b	.PF0f195db0
/*  f195cf0:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f195cf4:	8e45004c */ 	lw	$a1,0x4c($s2)
.PF0f195cf8:
/*  f195cf8:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f195cfc:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f195d00:	00057080 */ 	sll	$t6,$a1,0x2
/*  f195d04:	0fc66ce7 */ 	jal	botactIsWeaponThrowable
/*  f195d08:	000e2fc2 */ 	srl	$a1,$t6,0x1f
/*  f195d0c:	14400028 */ 	bnez	$v0,.PF0f195db0
/*  f195d10:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f195d14:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f195d18:	0010c080 */ 	sll	$t8,$s0,0x2
/*  f195d1c:	0258c821 */ 	addu	$t9,$s2,$t8
/*  f195d20:	8f230024 */ 	lw	$v1,0x24($t9)
/*  f195d24:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f195d28:	00054880 */ 	sll	$t1,$a1,0x2
/*  f195d2c:	00092fc2 */ 	srl	$a1,$t1,0x1f
/*  f195d30:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f195d34:	0fc66abe */ 	jal	botactGetClipCapacityByFunction
/*  f195d38:	afa302e8 */ 	sw	$v1,0x2e8($sp)
/*  f195d3c:	8fa302e8 */ 	lw	$v1,0x2e8($sp)
/*  f195d40:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f195d44:	1c600008 */ 	bgtz	$v1,.PF0f195d68
/*  f195d48:	00000000 */ 	nop
/*  f195d4c:	18400006 */ 	blez	$v0,.PF0f195d68
/*  f195d50:	02802025 */ 	move	$a0,$s4
/*  f195d54:	02002825 */ 	move	$a1,$s0
/*  f195d58:	0fc651d3 */ 	jal	botScheduleReload
/*  f195d5c:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f195d60:	10000013 */ 	b	.PF0f195db0
/*  f195d64:	8fa70054 */ 	lw	$a3,0x54($sp)
.PF0f195d68:
/*  f195d68:	04410003 */ 	bgez	$v0,.PF0f195d78
/*  f195d6c:	00025843 */ 	sra	$t3,$v0,0x1
/*  f195d70:	24410001 */ 	addiu	$at,$v0,0x1
/*  f195d74:	00015843 */ 	sra	$t3,$at,0x1
.PF0f195d78:
/*  f195d78:	006b082a */ 	slt	$at,$v1,$t3
/*  f195d7c:	5020000d */ 	beqzl	$at,.PF0f195db4
/*  f195d80:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f195d84:	8ecd0008 */ 	lw	$t5,0x8($s6)
/*  f195d88:	8e4c0124 */ 	lw	$t4,0x124($s2)
/*  f195d8c:	02802025 */ 	move	$a0,$s4
/*  f195d90:	25aeff9c */ 	addiu	$t6,$t5,-100
/*  f195d94:	018e082a */ 	slt	$at,$t4,$t6
/*  f195d98:	50200006 */ 	beqzl	$at,.PF0f195db4
/*  f195d9c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f195da0:	02002825 */ 	move	$a1,$s0
/*  f195da4:	0fc651d3 */ 	jal	botScheduleReload
/*  f195da8:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f195dac:	8fa70054 */ 	lw	$a3,0x54($sp)
.PF0f195db0:
/*  f195db0:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0f195db4:
/*  f195db4:	24010002 */ 	li	$at,0x2
/*  f195db8:	1601ffbe */ 	bne	$s0,$at,.PF0f195cb4
/*  f195dbc:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f195dc0:	8e4200cc */ 	lw	$v0,0xcc($s2)
/*  f195dc4:	58400045 */ 	blezl	$v0,.PF0f195edc
/*  f195dc8:	8e4d0020 */ 	lw	$t5,0x20($s2)
/*  f195dcc:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f195dd0:	02802025 */ 	move	$a0,$s4
/*  f195dd4:	004fc823 */ 	subu	$t9,$v0,$t7
/*  f195dd8:	1f20003f */ 	bgtz	$t9,.PF0f195ed8
/*  f195ddc:	ae5900cc */ 	sw	$t9,0xcc($s2)
/*  f195de0:	0fc6637c */ 	jal	botinvGetItem
/*  f195de4:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f195de8:	00408025 */ 	move	$s0,$v0
/*  f195dec:	0fc4a571 */ 	jal	playermgrGetModelOfWeapon
/*  f195df0:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f195df4:	12000019 */ 	beqz	$s0,.PF0f195e5c
/*  f195df8:	00408825 */ 	move	$s1,$v0
/*  f195dfc:	04400017 */ 	bltz	$v0,.PF0f195e5c
/*  f195e00:	02802025 */ 	move	$a0,$s4
/*  f195e04:	00402825 */ 	move	$a1,$v0
/*  f195e08:	8e460020 */ 	lw	$a2,0x20($s2)
/*  f195e0c:	0fc22e7f */ 	jal	chrGiveWeapon
/*  f195e10:	00003825 */ 	move	$a3,$zero
/*  f195e14:	02802025 */ 	move	$a0,$s4
/*  f195e18:	00002825 */ 	move	$a1,$zero
/*  f195e1c:	0fc66ad0 */ 	jal	botactReload
/*  f195e20:	00003025 */ 	move	$a2,$zero
/*  f195e24:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f195e28:	24010003 */ 	li	$at,0x3
/*  f195e2c:	02802025 */ 	move	$a0,$s4
/*  f195e30:	15210008 */ 	bne	$t1,$at,.PF0f195e54
/*  f195e34:	02202825 */ 	move	$a1,$s1
/*  f195e38:	8e460020 */ 	lw	$a2,0x20($s2)
/*  f195e3c:	0fc22e7f */ 	jal	chrGiveWeapon
/*  f195e40:	3c071000 */ 	lui	$a3,0x1000
/*  f195e44:	02802025 */ 	move	$a0,$s4
/*  f195e48:	24050001 */ 	li	$a1,0x1
/*  f195e4c:	0fc66ad0 */ 	jal	botactReload
/*  f195e50:	00003025 */ 	move	$a2,$zero
.PF0f195e54:
/*  f195e54:	1000000e */ 	b	.PF0f195e90
/*  f195e58:	ae400034 */ 	sw	$zero,0x34($s2)
.PF0f195e5c:
/*  f195e5c:	8e8a02d4 */ 	lw	$t2,0x2d4($s4)
/*  f195e60:	24170001 */ 	li	$s7,0x1
/*  f195e64:	ad570020 */ 	sw	$s7,0x20($t2)
/*  f195e68:	8e8302d4 */ 	lw	$v1,0x2d4($s4)
/*  f195e6c:	906b004c */ 	lbu	$t3,0x4c($v1)
/*  f195e70:	316dffdf */ 	andi	$t5,$t3,0xffdf
/*  f195e74:	a06d004c */ 	sb	$t5,0x4c($v1)
/*  f195e78:	8e8302d4 */ 	lw	$v1,0x2d4($s4)
/*  f195e7c:	906c004c */ 	lbu	$t4,0x4c($v1)
/*  f195e80:	318effbf */ 	andi	$t6,$t4,0xffbf
/*  f195e84:	35cf0040 */ 	ori	$t7,$t6,0x40
/*  f195e88:	a06f004c */ 	sb	$t7,0x4c($v1)
/*  f195e8c:	ae400034 */ 	sw	$zero,0x34($s2)
.PF0f195e90:
/*  f195e90:	02401025 */ 	move	$v0,$s2
/*  f195e94:	00001825 */ 	move	$v1,$zero
/*  f195e98:	02802025 */ 	move	$a0,$s4
/*  f195e9c:	24060008 */ 	li	$a2,0x8
.PF0f195ea0:
/*  f195ea0:	a440003c */ 	sh	$zero,0x3c($v0)
/*  f195ea4:	8c850170 */ 	lw	$a1,0x170($a0)
/*  f195ea8:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f195eac:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f195eb0:	10a00007 */ 	beqz	$a1,.PF0f195ed0
/*  f195eb4:	00000000 */ 	nop
/*  f195eb8:	8e9802d4 */ 	lw	$t8,0x2d4($s4)
/*  f195ebc:	8cab0004 */ 	lw	$t3,0x4($a1)
/*  f195ec0:	8f19004c */ 	lw	$t9,0x4c($t8)
/*  f195ec4:	00194880 */ 	sll	$t1,$t9,0x2
/*  f195ec8:	000957c2 */ 	srl	$t2,$t1,0x1f
/*  f195ecc:	a16a005f */ 	sb	$t2,0x5f($t3)
.PF0f195ed0:
/*  f195ed0:	1466fff3 */ 	bne	$v1,$a2,.PF0f195ea0
/*  f195ed4:	24840004 */ 	addiu	$a0,$a0,0x4
.PF0f195ed8:
/*  f195ed8:	8e4d0020 */ 	lw	$t5,0x20($s2)
.PF0f195edc:
/*  f195edc:	2401001d */ 	li	$at,0x1d
/*  f195ee0:	24170001 */ 	li	$s7,0x1
/*  f195ee4:	55a10005 */ 	bnel	$t5,$at,.PF0f195efc
/*  f195ee8:	8e4f001c */ 	lw	$t7,0x1c($s2)
/*  f195eec:	8e8e02d4 */ 	lw	$t6,0x2d4($s4)
/*  f195ef0:	240c03e7 */ 	li	$t4,0x3e7
/*  f195ef4:	adcc0024 */ 	sw	$t4,0x24($t6)
/*  f195ef8:	8e4f001c */ 	lw	$t7,0x1c($s2)
.PF0f195efc:
/*  f195efc:	8df80050 */ 	lw	$t8,0x50($t7)
/*  f195f00:	1b00000d */ 	blez	$t8,.PF0f195f38
/*  f195f04:	02802025 */ 	move	$a0,$s4
/*  f195f08:	0fc649bc */ 	jal	botIsAboutToAttack
/*  f195f0c:	02e02825 */ 	move	$a1,$s7
/*  f195f10:	54400006 */ 	bnezl	$v0,.PF0f195f2c
/*  f195f14:	924a004c */ 	lbu	$t2,0x4c($s2)
/*  f195f18:	929902a0 */ 	lbu	$t9,0x2a0($s4)
/*  f195f1c:	2401002e */ 	li	$at,0x2e
/*  f195f20:	57210006 */ 	bnel	$t9,$at,.PF0f195f3c
/*  f195f24:	8e420210 */ 	lw	$v0,0x210($s2)
/*  f195f28:	924a004c */ 	lbu	$t2,0x4c($s2)
.PF0f195f2c:
/*  f195f2c:	354b0002 */ 	ori	$t3,$t2,0x2
/*  f195f30:	1000001e */ 	b	.PF0f195fac
/*  f195f34:	a24b004c */ 	sb	$t3,0x4c($s2)
.PF0f195f38:
/*  f195f38:	8e420210 */ 	lw	$v0,0x210($s2)
.PF0f195f3c:
/*  f195f3c:	240403e8 */ 	li	$a0,0x3e8
/*  f195f40:	8e4d001c */ 	lw	$t5,0x1c($s2)
/*  f195f44:	00026142 */ 	srl	$t4,$v0,0x5
/*  f195f48:	0184001b */ 	divu	$zero,$t4,$a0
/*  f195f4c:	8da30050 */ 	lw	$v1,0x50($t5)
/*  f195f50:	00007010 */ 	mfhi	$t6
/*  f195f54:	25cf03e8 */ 	addiu	$t7,$t6,0x3e8
/*  f195f58:	14800002 */ 	bnez	$a0,.PF0f195f64
/*  f195f5c:	00000000 */ 	nop
/*  f195f60:	0007000d */ 	break	0x7
.PF0f195f64:
/*  f195f64:	01e3082b */ 	sltu	$at,$t7,$v1
/*  f195f68:	10200005 */ 	beqz	$at,.PF0f195f80
/*  f195f6c:	00025442 */ 	srl	$t2,$v0,0x11
/*  f195f70:	9259004c */ 	lbu	$t9,0x4c($s2)
/*  f195f74:	37290002 */ 	ori	$t1,$t9,0x2
/*  f195f78:	1000000c */ 	b	.PF0f195fac
/*  f195f7c:	a249004c */ 	sb	$t1,0x4c($s2)
.PF0f195f80:
/*  f195f80:	0144001b */ 	divu	$zero,$t2,$a0
/*  f195f84:	00005810 */ 	mfhi	$t3
/*  f195f88:	0163082b */ 	sltu	$at,$t3,$v1
/*  f195f8c:	14800002 */ 	bnez	$a0,.PF0f195f98
/*  f195f90:	00000000 */ 	nop
/*  f195f94:	0007000d */ 	break	0x7
.PF0f195f98:
/*  f195f98:	54200005 */ 	bnezl	$at,.PF0f195fb0
/*  f195f9c:	8e4e004c */ 	lw	$t6,0x4c($s2)
/*  f195fa0:	924d004c */ 	lbu	$t5,0x4c($s2)
/*  f195fa4:	31acfffd */ 	andi	$t4,$t5,0xfffd
/*  f195fa8:	a24c004c */ 	sb	$t4,0x4c($s2)
.PF0f195fac:
/*  f195fac:	8e4e004c */ 	lw	$t6,0x4c($s2)
.PF0f195fb0:
/*  f195fb0:	000ec180 */ 	sll	$t8,$t6,0x6
/*  f195fb4:	07020039 */ 	bltzl	$t8,.PF0f19609c
/*  f195fb8:	924b009c */ 	lbu	$t3,0x9c($s2)
/*  f195fbc:	8e590020 */ 	lw	$t9,0x20($s2)
/*  f195fc0:	2401000d */ 	li	$at,0xd
/*  f195fc4:	02402025 */ 	move	$a0,$s2
/*  f195fc8:	17210033 */ 	bne	$t9,$at,.PF0f196098
/*  f195fcc:	2405000d */ 	li	$a1,0xd
/*  f195fd0:	00003025 */ 	move	$a2,$zero
/*  f195fd4:	0fc66b39 */ 	jal	botactGetAmmoQuantityByWeapon
/*  f195fd8:	02e03825 */ 	move	$a3,$s7
/*  f195fdc:	00408025 */ 	move	$s0,$v0
/*  f195fe0:	02802025 */ 	move	$a0,$s4
/*  f195fe4:	0fc649bc */ 	jal	botIsAboutToAttack
/*  f195fe8:	02e02825 */ 	move	$a1,$s7
/*  f195fec:	5040001a */ 	beqzl	$v0,.PF0f196058
/*  f195ff0:	8e4b0210 */ 	lw	$t3,0x210($s2)
/*  f195ff4:	8e420210 */ 	lw	$v0,0x210($s2)
/*  f195ff8:	240100c8 */ 	li	$at,0xc8
/*  f195ffc:	00024982 */ 	srl	$t1,$v0,0x6
/*  f196000:	0121001b */ 	divu	$zero,$t1,$at
/*  f196004:	00005010 */ 	mfhi	$t2
/*  f196008:	254b00c8 */ 	addiu	$t3,$t2,0xc8
/*  f19600c:	0170082b */ 	sltu	$at,$t3,$s0
/*  f196010:	10200005 */ 	beqz	$at,.PF0f196028
/*  f196014:	00027c02 */ 	srl	$t7,$v0,0x10
/*  f196018:	924c009c */ 	lbu	$t4,0x9c($s2)
/*  f19601c:	358e0020 */ 	ori	$t6,$t4,0x20
/*  f196020:	10000020 */ 	b	.PF0f1960a4
/*  f196024:	a24e009c */ 	sb	$t6,0x9c($s2)
.PF0f196028:
/*  f196028:	24010046 */ 	li	$at,0x46
/*  f19602c:	01e1001b */ 	divu	$zero,$t7,$at
/*  f196030:	0000c010 */ 	mfhi	$t8
/*  f196034:	2719001e */ 	addiu	$t9,$t8,0x1e
/*  f196038:	0330082b */ 	sltu	$at,$t9,$s0
/*  f19603c:	5420001a */ 	bnezl	$at,.PF0f1960a8
/*  f196040:	8e4c0004 */ 	lw	$t4,0x4($s2)
/*  f196044:	9249009c */ 	lbu	$t1,0x9c($s2)
/*  f196048:	312affdf */ 	andi	$t2,$t1,0xffdf
/*  f19604c:	10000015 */ 	b	.PF0f1960a4
/*  f196050:	a24a009c */ 	sb	$t2,0x9c($s2)
/*  f196054:	8e4b0210 */ 	lw	$t3,0x210($s2)
.PF0f196058:
/*  f196058:	240101f4 */ 	li	$at,0x1f4
/*  f19605c:	000b6b02 */ 	srl	$t5,$t3,0xc
/*  f196060:	01a1001b */ 	divu	$zero,$t5,$at
/*  f196064:	00006010 */ 	mfhi	$t4
/*  f196068:	258e012c */ 	addiu	$t6,$t4,0x12c
/*  f19606c:	01d0082b */ 	sltu	$at,$t6,$s0
/*  f196070:	50200006 */ 	beqzl	$at,.PF0f19608c
/*  f196074:	9249009c */ 	lbu	$t1,0x9c($s2)
/*  f196078:	9258009c */ 	lbu	$t8,0x9c($s2)
/*  f19607c:	37190020 */ 	ori	$t9,$t8,0x20
/*  f196080:	10000008 */ 	b	.PF0f1960a4
/*  f196084:	a259009c */ 	sb	$t9,0x9c($s2)
/*  f196088:	9249009c */ 	lbu	$t1,0x9c($s2)
.PF0f19608c:
/*  f19608c:	312affdf */ 	andi	$t2,$t1,0xffdf
/*  f196090:	10000004 */ 	b	.PF0f1960a4
/*  f196094:	a24a009c */ 	sb	$t2,0x9c($s2)
.PF0f196098:
/*  f196098:	924b009c */ 	lbu	$t3,0x9c($s2)
.PF0f19609c:
/*  f19609c:	316dffdf */ 	andi	$t5,$t3,0xffdf
/*  f1960a0:	a24d009c */ 	sb	$t5,0x9c($s2)
.PF0f1960a4:
/*  f1960a4:	8e4c0004 */ 	lw	$t4,0x4($s2)
.PF0f1960a8:
/*  f1960a8:	24010004 */ 	li	$at,0x4
/*  f1960ac:	918e0047 */ 	lbu	$t6,0x47($t4)
/*  f1960b0:	55c1000e */ 	bnel	$t6,$at,.PF0f1960ec
/*  f1960b4:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f1960b8:	868f017e */ 	lh	$t7,0x17e($s4)
/*  f1960bc:	241effff */ 	li	$s8,-1
/*  f1960c0:	53cf000a */ 	beql	$s8,$t7,.PF0f1960ec
/*  f1960c4:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f1960c8:	8e580128 */ 	lw	$t8,0x128($s2)
/*  f1960cc:	53000007 */ 	beqzl	$t8,.PF0f1960ec
/*  f1960d0:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f1960d4:	929902a0 */ 	lbu	$t9,0x2a0($s4)
/*  f1960d8:	2401002f */ 	li	$at,0x2f
/*  f1960dc:	53210003 */ 	beql	$t9,$at,.PF0f1960ec
/*  f1960e0:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f1960e4:	ae5700d8 */ 	sw	$s7,0xd8($s2)
/*  f1960e8:	824a004f */ 	lb	$t2,0x4f($s2)
.PF0f1960ec:
/*  f1960ec:	241effff */ 	li	$s8,-1
/*  f1960f0:	05430143 */ 	bgezl	$t2,.PF0f196600
/*  f1960f4:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
/*  f1960f8:	8e420118 */ 	lw	$v0,0x118($s2)
/*  f1960fc:	18400005 */ 	blez	$v0,.PF0f196114
/*  f196100:	00000000 */ 	nop
/*  f196104:	8ecb0038 */ 	lw	$t3,0x38($s6)
/*  f196108:	004b6823 */ 	subu	$t5,$v0,$t3
/*  f19610c:	ae4d0118 */ 	sw	$t5,0x118($s2)
/*  f196110:	01a01025 */ 	move	$v0,$t5
.PF0f196114:
/*  f196114:	5c40013a */ 	bgtzl	$v0,.PF0f196600
/*  f196118:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
/*  f19611c:	0fc655e3 */ 	jal	botGetTeamSize
/*  f196120:	02802025 */ 	move	$a0,$s4
/*  f196124:	3c03800b */ 	lui	$v1,0x800b
/*  f196128:	9063d138 */ 	lbu	$v1,-0x2ec8($v1)
/*  f19612c:	00409825 */ 	move	$s3,$v0
/*  f196130:	02802025 */ 	move	$a0,$s4
/*  f196134:	16e3001e */ 	bne	$s7,$v1,.PF0f1961b0
/*  f196138:	24010002 */ 	li	$at,0x2
/*  f19613c:	2405000b */ 	li	$a1,0xb
/*  f196140:	0fc655f7 */ 	jal	botGetCountInTeamDoingCommand
/*  f196144:	00003025 */ 	move	$a2,$zero
/*  f196148:	18400010 */ 	blez	$v0,.PF0f19618c
/*  f19614c:	266c0001 */ 	addiu	$t4,$s3,0x1
/*  f196150:	05810003 */ 	bgez	$t4,.PF0f196160
/*  f196154:	000c7043 */ 	sra	$t6,$t4,0x1
/*  f196158:	25810001 */ 	addiu	$at,$t4,0x1
/*  f19615c:	00017043 */ 	sra	$t6,$at,0x1
.PF0f196160:
/*  f196160:	004e082a */ 	slt	$at,$v0,$t6
/*  f196164:	5420000a */ 	bnezl	$at,.PF0f196190
/*  f196168:	02802025 */ 	move	$a0,$s4
/*  f19616c:	0c004ad4 */ 	jal	random
/*  f196170:	00000000 */ 	nop
/*  f196174:	24010064 */ 	li	$at,0x64
/*  f196178:	0041001b */ 	divu	$zero,$v0,$at
/*  f19617c:	00007810 */ 	mfhi	$t7
/*  f196180:	2de10042 */ 	sltiu	$at,$t7,0x42
/*  f196184:	10200006 */ 	beqz	$at,.PF0f1961a0
/*  f196188:	02802025 */ 	move	$a0,$s4
.PF0f19618c:
/*  f19618c:	02802025 */ 	move	$a0,$s4
.PF0f196190:
/*  f196190:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f196194:	2405000b */ 	li	$a1,0xb
/*  f196198:	10000111 */ 	b	.PF0f1965e0
/*  f19619c:	00000000 */ 	nop
.PF0f1961a0:
/*  f1961a0:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f1961a4:	24050004 */ 	li	$a1,0x4
/*  f1961a8:	1000010d */ 	b	.PF0f1965e0
/*  f1961ac:	00000000 */ 	nop
.PF0f1961b0:
/*  f1961b0:	14610022 */ 	bne	$v1,$at,.PF0f19623c
/*  f1961b4:	02802025 */ 	move	$a0,$s4
/*  f1961b8:	24050005 */ 	li	$a1,0x5
/*  f1961bc:	0fc655f7 */ 	jal	botGetCountInTeamDoingCommand
/*  f1961c0:	00003025 */ 	move	$a2,$zero
/*  f1961c4:	8e58004c */ 	lw	$t8,0x4c($s2)
/*  f1961c8:	00184940 */ 	sll	$t1,$t8,0x5
/*  f1961cc:	05220013 */ 	bltzl	$t1,.PF0f19621c
/*  f1961d0:	02802025 */ 	move	$a0,$s4
/*  f1961d4:	18400010 */ 	blez	$v0,.PF0f196218
/*  f1961d8:	266a0001 */ 	addiu	$t2,$s3,0x1
/*  f1961dc:	05410003 */ 	bgez	$t2,.PF0f1961ec
/*  f1961e0:	000a5843 */ 	sra	$t3,$t2,0x1
/*  f1961e4:	25410001 */ 	addiu	$at,$t2,0x1
/*  f1961e8:	00015843 */ 	sra	$t3,$at,0x1
.PF0f1961ec:
/*  f1961ec:	004b082a */ 	slt	$at,$v0,$t3
/*  f1961f0:	5420000a */ 	bnezl	$at,.PF0f19621c
/*  f1961f4:	02802025 */ 	move	$a0,$s4
/*  f1961f8:	0c004ad4 */ 	jal	random
/*  f1961fc:	00000000 */ 	nop
/*  f196200:	24010064 */ 	li	$at,0x64
/*  f196204:	0041001b */ 	divu	$zero,$v0,$at
/*  f196208:	00006810 */ 	mfhi	$t5
/*  f19620c:	2da10032 */ 	sltiu	$at,$t5,0x32
/*  f196210:	10200006 */ 	beqz	$at,.PF0f19622c
/*  f196214:	02802025 */ 	move	$a0,$s4
.PF0f196218:
/*  f196218:	02802025 */ 	move	$a0,$s4
.PF0f19621c:
/*  f19621c:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f196220:	24050005 */ 	li	$a1,0x5
/*  f196224:	100000ee */ 	b	.PF0f1965e0
/*  f196228:	00000000 */ 	nop
.PF0f19622c:
/*  f19622c:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f196230:	24050004 */ 	li	$a1,0x4
/*  f196234:	100000ea */ 	b	.PF0f1965e0
/*  f196238:	00000000 */ 	nop
.PF0f19623c:
/*  f19623c:	24010003 */ 	li	$at,0x3
/*  f196240:	1461001e */ 	bne	$v1,$at,.PF0f1962bc
/*  f196244:	02802025 */ 	move	$a0,$s4
/*  f196248:	2405000c */ 	li	$a1,0xc
/*  f19624c:	0fc655f7 */ 	jal	botGetCountInTeamDoingCommand
/*  f196250:	00003025 */ 	move	$a2,$zero
/*  f196254:	18400010 */ 	blez	$v0,.PF0f196298
/*  f196258:	266c0001 */ 	addiu	$t4,$s3,0x1
/*  f19625c:	05810003 */ 	bgez	$t4,.PF0f19626c
/*  f196260:	000c7043 */ 	sra	$t6,$t4,0x1
/*  f196264:	25810001 */ 	addiu	$at,$t4,0x1
/*  f196268:	00017043 */ 	sra	$t6,$at,0x1
.PF0f19626c:
/*  f19626c:	004e082a */ 	slt	$at,$v0,$t6
/*  f196270:	5420000a */ 	bnezl	$at,.PF0f19629c
/*  f196274:	02802025 */ 	move	$a0,$s4
/*  f196278:	0c004ad4 */ 	jal	random
/*  f19627c:	00000000 */ 	nop
/*  f196280:	24010064 */ 	li	$at,0x64
/*  f196284:	0041001b */ 	divu	$zero,$v0,$at
/*  f196288:	00007810 */ 	mfhi	$t7
/*  f19628c:	2de10032 */ 	sltiu	$at,$t7,0x32
/*  f196290:	10200006 */ 	beqz	$at,.PF0f1962ac
/*  f196294:	02802025 */ 	move	$a0,$s4
.PF0f196298:
/*  f196298:	02802025 */ 	move	$a0,$s4
.PF0f19629c:
/*  f19629c:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f1962a0:	2405000c */ 	li	$a1,0xc
/*  f1962a4:	100000ce */ 	b	.PF0f1965e0
/*  f1962a8:	00000000 */ 	nop
.PF0f1962ac:
/*  f1962ac:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f1962b0:	24050004 */ 	li	$a1,0x4
/*  f1962b4:	100000ca */ 	b	.PF0f1965e0
/*  f1962b8:	00000000 */ 	nop
.PF0f1962bc:
/*  f1962bc:	24010004 */ 	li	$at,0x4
/*  f1962c0:	54610034 */ 	bnel	$v1,$at,.PF0f196394
/*  f1962c4:	24010005 */ 	li	$at,0x5
/*  f1962c8:	0fc6566f */ 	jal	botGetNumTeammatesDefendingHill
/*  f1962cc:	02802025 */ 	move	$a0,$s4
/*  f1962d0:	8e98001c */ 	lw	$t8,0x1c($s4)
/*  f1962d4:	3c09800b */ 	lui	$t1,0x800b
/*  f1962d8:	8529c6be */ 	lh	$t1,-0x3942($t1)
/*  f1962dc:	87190028 */ 	lh	$t9,0x28($t8)
/*  f1962e0:	00408025 */ 	move	$s0,$v0
/*  f1962e4:	02802025 */ 	move	$a0,$s4
/*  f1962e8:	17290002 */ 	bne	$t9,$t1,.PF0f1962f4
/*  f1962ec:	00000000 */ 	nop
/*  f1962f0:	2450ffff */ 	addiu	$s0,$v0,-1
.PF0f1962f4:
/*  f1962f4:	1a000008 */ 	blez	$s0,.PF0f196318
/*  f1962f8:	00000000 */ 	nop
/*  f1962fc:	06610003 */ 	bgez	$s3,.PF0f19630c
/*  f196300:	00135043 */ 	sra	$t2,$s3,0x1
/*  f196304:	26610001 */ 	addiu	$at,$s3,0x1
/*  f196308:	00015043 */ 	sra	$t2,$at,0x1
.PF0f19630c:
/*  f19630c:	020a082a */ 	slt	$at,$s0,$t2
/*  f196310:	10200005 */ 	beqz	$at,.PF0f196328
/*  f196314:	00000000 */ 	nop
.PF0f196318:
/*  f196318:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f19631c:	2405000a */ 	li	$a1,0xa
/*  f196320:	100000af */ 	b	.PF0f1965e0
/*  f196324:	00000000 */ 	nop
.PF0f196328:
/*  f196328:	0fc65692 */ 	jal	botGetNumOpponentsInHill
/*  f19632c:	02802025 */ 	move	$a0,$s4
/*  f196330:	0050082a */ 	slt	$at,$v0,$s0
/*  f196334:	10200012 */ 	beqz	$at,.PF0f196380
/*  f196338:	02802025 */ 	move	$a0,$s4
/*  f19633c:	0c004ad4 */ 	jal	random
/*  f196340:	00000000 */ 	nop
/*  f196344:	24010064 */ 	li	$at,0x64
/*  f196348:	0041001b */ 	divu	$zero,$v0,$at
/*  f19634c:	00005810 */ 	mfhi	$t3
/*  f196350:	2d610032 */ 	sltiu	$at,$t3,0x32
/*  f196354:	10200006 */ 	beqz	$at,.PF0f196370
/*  f196358:	02802025 */ 	move	$a0,$s4
/*  f19635c:	02802025 */ 	move	$a0,$s4
/*  f196360:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f196364:	24050009 */ 	li	$a1,0x9
/*  f196368:	1000009d */ 	b	.PF0f1965e0
/*  f19636c:	00000000 */ 	nop
.PF0f196370:
/*  f196370:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f196374:	24050004 */ 	li	$a1,0x4
/*  f196378:	10000099 */ 	b	.PF0f1965e0
/*  f19637c:	00000000 */ 	nop
.PF0f196380:
/*  f196380:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f196384:	2405000a */ 	li	$a1,0xa
/*  f196388:	10000095 */ 	b	.PF0f1965e0
/*  f19638c:	00000000 */ 	nop
/*  f196390:	24010005 */ 	li	$at,0x5
.PF0f196394:
/*  f196394:	14610092 */ 	bne	$v1,$at,.PF0f1965e0
/*  f196398:	00000000 */ 	nop
/*  f19639c:	14570035 */ 	bne	$v0,$s7,.PF0f196474
/*  f1963a0:	02802025 */ 	move	$a0,$s4
/*  f1963a4:	02802025 */ 	move	$a0,$s4
/*  f1963a8:	24050006 */ 	li	$a1,0x6
/*  f1963ac:	0fc655f7 */ 	jal	botGetCountInTeamDoingCommand
/*  f1963b0:	02e03025 */ 	move	$a2,$s7
/*  f1963b4:	00408025 */ 	move	$s0,$v0
/*  f1963b8:	0fc65655 */ 	jal	botShouldReturnCtcToken
/*  f1963bc:	02802025 */ 	move	$a0,$s4
/*  f1963c0:	10400005 */ 	beqz	$v0,.PF0f1963d8
/*  f1963c4:	02802025 */ 	move	$a0,$s4
/*  f1963c8:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f1963cc:	24050006 */ 	li	$a1,0x6
/*  f1963d0:	10000083 */ 	b	.PF0f1965e0
/*  f1963d4:	00000000 */ 	nop
.PF0f1963d8:
/*  f1963d8:	0fc6563b */ 	jal	botIsChrsCtcTokenHeld
/*  f1963dc:	02802025 */ 	move	$a0,$s4
/*  f1963e0:	10400012 */ 	beqz	$v0,.PF0f19642c
/*  f1963e4:	00000000 */ 	nop
/*  f1963e8:	0c004ad4 */ 	jal	random
/*  f1963ec:	00000000 */ 	nop
/*  f1963f0:	24010064 */ 	li	$at,0x64
/*  f1963f4:	0041001b */ 	divu	$zero,$v0,$at
/*  f1963f8:	00006810 */ 	mfhi	$t5
/*  f1963fc:	2da1001e */ 	sltiu	$at,$t5,0x1e
/*  f196400:	10200006 */ 	beqz	$at,.PF0f19641c
/*  f196404:	02802025 */ 	move	$a0,$s4
/*  f196408:	02802025 */ 	move	$a0,$s4
/*  f19640c:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f196410:	24050006 */ 	li	$a1,0x6
/*  f196414:	10000072 */ 	b	.PF0f1965e0
/*  f196418:	00000000 */ 	nop
.PF0f19641c:
/*  f19641c:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f196420:	24050008 */ 	li	$a1,0x8
/*  f196424:	1000006e */ 	b	.PF0f1965e0
/*  f196428:	00000000 */ 	nop
.PF0f19642c:
/*  f19642c:	0c004ad4 */ 	jal	random
/*  f196430:	00000000 */ 	nop
/*  f196434:	24010064 */ 	li	$at,0x64
/*  f196438:	0041001b */ 	divu	$zero,$v0,$at
/*  f19643c:	00006010 */ 	mfhi	$t4
/*  f196440:	2d810046 */ 	sltiu	$at,$t4,0x46
/*  f196444:	14200003 */ 	bnez	$at,.PF0f196454
/*  f196448:	02802025 */ 	move	$a0,$s4
/*  f19644c:	1e000005 */ 	bgtz	$s0,.PF0f196464
/*  f196450:	24050008 */ 	li	$a1,0x8
.PF0f196454:
/*  f196454:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f196458:	24050006 */ 	li	$a1,0x6
/*  f19645c:	10000060 */ 	b	.PF0f1965e0
/*  f196460:	00000000 */ 	nop
.PF0f196464:
/*  f196464:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f196468:	02802025 */ 	move	$a0,$s4
/*  f19646c:	1000005c */ 	b	.PF0f1965e0
/*  f196470:	00000000 */ 	nop
.PF0f196474:
/*  f196474:	24050006 */ 	li	$a1,0x6
/*  f196478:	0fc655f7 */ 	jal	botGetCountInTeamDoingCommand
/*  f19647c:	00003025 */ 	move	$a2,$zero
/*  f196480:	00408825 */ 	move	$s1,$v0
/*  f196484:	02802025 */ 	move	$a0,$s4
/*  f196488:	24050008 */ 	li	$a1,0x8
/*  f19648c:	0fc655f7 */ 	jal	botGetCountInTeamDoingCommand
/*  f196490:	00003025 */ 	move	$a2,$zero
/*  f196494:	00408025 */ 	move	$s0,$v0
/*  f196498:	0fc65655 */ 	jal	botShouldReturnCtcToken
/*  f19649c:	02802025 */ 	move	$a0,$s4
/*  f1964a0:	10400005 */ 	beqz	$v0,.PF0f1964b8
/*  f1964a4:	02802025 */ 	move	$a0,$s4
/*  f1964a8:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f1964ac:	24050006 */ 	li	$a1,0x6
/*  f1964b0:	1000004b */ 	b	.PF0f1965e0
/*  f1964b4:	00000000 */ 	nop
.PF0f1964b8:
/*  f1964b8:	0fc6563b */ 	jal	botIsChrsCtcTokenHeld
/*  f1964bc:	02802025 */ 	move	$a0,$s4
/*  f1964c0:	10400014 */ 	beqz	$v0,.PF0f196514
/*  f1964c4:	00000000 */ 	nop
/*  f1964c8:	5a00000a */ 	blezl	$s0,.PF0f1964f4
/*  f1964cc:	02802025 */ 	move	$a0,$s4
/*  f1964d0:	0c004ad4 */ 	jal	random
/*  f1964d4:	00000000 */ 	nop
/*  f1964d8:	24010064 */ 	li	$at,0x64
/*  f1964dc:	0041001b */ 	divu	$zero,$v0,$at
/*  f1964e0:	00007010 */ 	mfhi	$t6
/*  f1964e4:	2dc10046 */ 	sltiu	$at,$t6,0x46
/*  f1964e8:	10200006 */ 	beqz	$at,.PF0f196504
/*  f1964ec:	02802025 */ 	move	$a0,$s4
/*  f1964f0:	02802025 */ 	move	$a0,$s4
.PF0f1964f4:
/*  f1964f4:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f1964f8:	24050008 */ 	li	$a1,0x8
/*  f1964fc:	10000038 */ 	b	.PF0f1965e0
/*  f196500:	00000000 */ 	nop
.PF0f196504:
/*  f196504:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f196508:	24050006 */ 	li	$a1,0x6
/*  f19650c:	10000034 */ 	b	.PF0f1965e0
/*  f196510:	00000000 */ 	nop
.PF0f196514:
/*  f196514:	1a200005 */ 	blez	$s1,.PF0f19652c
/*  f196518:	24010003 */ 	li	$at,0x3
/*  f19651c:	0261001a */ 	div	$zero,$s3,$at
/*  f196520:	00007812 */ 	mflo	$t7
/*  f196524:	022f082a */ 	slt	$at,$s1,$t7
/*  f196528:	10200005 */ 	beqz	$at,.PF0f196540
.PF0f19652c:
/*  f19652c:	02802025 */ 	move	$a0,$s4
/*  f196530:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f196534:	24050006 */ 	li	$a1,0x6
/*  f196538:	10000029 */ 	b	.PF0f1965e0
/*  f19653c:	00000000 */ 	nop
.PF0f196540:
/*  f196540:	1a000008 */ 	blez	$s0,.PF0f196564
/*  f196544:	02802025 */ 	move	$a0,$s4
/*  f196548:	06610003 */ 	bgez	$s3,.PF0f196558
/*  f19654c:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f196550:	26610003 */ 	addiu	$at,$s3,0x3
/*  f196554:	0001c083 */ 	sra	$t8,$at,0x2
.PF0f196558:
/*  f196558:	0218082a */ 	slt	$at,$s0,$t8
/*  f19655c:	10200005 */ 	beqz	$at,.PF0f196574
/*  f196560:	00000000 */ 	nop
.PF0f196564:
/*  f196564:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f196568:	24050008 */ 	li	$a1,0x8
/*  f19656c:	1000001c */ 	b	.PF0f1965e0
/*  f196570:	00000000 */ 	nop
.PF0f196574:
/*  f196574:	0c004ad4 */ 	jal	random
/*  f196578:	00000000 */ 	nop
/*  f19657c:	24010064 */ 	li	$at,0x64
/*  f196580:	0041001b */ 	divu	$zero,$v0,$at
/*  f196584:	0000c810 */ 	mfhi	$t9
/*  f196588:	2f21001e */ 	sltiu	$at,$t9,0x1e
/*  f19658c:	10200005 */ 	beqz	$at,.PF0f1965a4
/*  f196590:	02802025 */ 	move	$a0,$s4
/*  f196594:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f196598:	24050006 */ 	li	$a1,0x6
/*  f19659c:	10000010 */ 	b	.PF0f1965e0
/*  f1965a0:	00000000 */ 	nop
.PF0f1965a4:
/*  f1965a4:	0c004ad4 */ 	jal	random
/*  f1965a8:	00000000 */ 	nop
/*  f1965ac:	24010064 */ 	li	$at,0x64
/*  f1965b0:	0041001b */ 	divu	$zero,$v0,$at
/*  f1965b4:	00004810 */ 	mfhi	$t1
/*  f1965b8:	2d21001e */ 	sltiu	$at,$t1,0x1e
/*  f1965bc:	10200006 */ 	beqz	$at,.PF0f1965d8
/*  f1965c0:	02802025 */ 	move	$a0,$s4
/*  f1965c4:	02802025 */ 	move	$a0,$s4
/*  f1965c8:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f1965cc:	24050008 */ 	li	$a1,0x8
/*  f1965d0:	10000003 */ 	b	.PF0f1965e0
/*  f1965d4:	00000000 */ 	nop
.PF0f1965d8:
/*  f1965d8:	0fc64db2 */ 	jal	botApplyScenarioCommand
/*  f1965dc:	24050004 */ 	li	$a1,0x4
.PF0f1965e0:
/*  f1965e0:	0c004ad4 */ 	jal	random
/*  f1965e4:	00000000 */ 	nop
/*  f1965e8:	240107d0 */ 	li	$at,0x7d0
/*  f1965ec:	0041001b */ 	divu	$zero,$v0,$at
/*  f1965f0:	00005010 */ 	mfhi	$t2
/*  f1965f4:	254b03e8 */ 	addiu	$t3,$t2,0x3e8
/*  f1965f8:	ae4b0118 */ 	sw	$t3,0x118($s2)
/*  f1965fc:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
.PF0f196600:
/*  f196600:	24010029 */ 	li	$at,0x29
/*  f196604:	51a10005 */ 	beql	$t5,$at,.PF0f19661c
/*  f196608:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f19660c:	8e4c00d8 */ 	lw	$t4,0xd8($s2)
/*  f196610:	1180039a */ 	beqz	$t4,.PF0f19747c
/*  f196614:	00000000 */ 	nop
/*  f196618:	8e4e0004 */ 	lw	$t6,0x4($s2)
.PF0f19661c:
/*  f19661c:	ae4000d8 */ 	sw	$zero,0xd8($s2)
/*  f196620:	a65e0008 */ 	sh	$s8,0x8($s2)
/*  f196624:	91cf0047 */ 	lbu	$t7,0x47($t6)
/*  f196628:	24010004 */ 	li	$at,0x4
/*  f19662c:	15e1000e */ 	bne	$t7,$at,.PF0f196668
/*  f196630:	00000000 */ 	nop
/*  f196634:	8698017e */ 	lh	$t8,0x17e($s4)
/*  f196638:	13d8000b */ 	beq	$s8,$t8,.PF0f196668
/*  f19663c:	00000000 */ 	nop
/*  f196640:	8e590128 */ 	lw	$t9,0x128($s2)
/*  f196644:	02802025 */ 	move	$a0,$s4
/*  f196648:	13200007 */ 	beqz	$t9,.PF0f196668
/*  f19664c:	00000000 */ 	nop
/*  f196650:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f196654:	2415002f */ 	li	$s5,0x2f
/*  f196658:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f19665c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f196660:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f196664:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PF0f196668:
/*  f196668:	06a10006 */ 	bgez	$s5,.PF0f196684
/*  f19666c:	00000000 */ 	nop
/*  f196670:	0fc655d3 */ 	jal	botFindDefaultPickup
/*  f196674:	02802025 */ 	move	$a0,$s4
/*  f196678:	10400002 */ 	beqz	$v0,.PF0f196684
/*  f19667c:	ae420010 */ 	sw	$v0,0x10($s2)
/*  f196680:	2415002a */ 	li	$s5,0x2a
.PF0f196684:
/*  f196684:	06a10240 */ 	bgez	$s5,.PF0f196f88
/*  f196688:	00000000 */ 	nop
/*  f19668c:	92420079 */ 	lbu	$v0,0x79($s2)
/*  f196690:	16e20019 */ 	bne	$s7,$v0,.PF0f1966f8
/*  f196694:	00000000 */ 	nop
/*  f196698:	8e4900c0 */ 	lw	$t1,0xc0($s2)
/*  f19669c:	8ecb0338 */ 	lw	$t3,0x338($s6)
/*  f1966a0:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f1966a4:	01495021 */ 	addu	$t2,$t2,$t1
/*  f1966a8:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f1966ac:	014b6821 */ 	addu	$t5,$t2,$t3
/*  f1966b0:	8db00004 */ 	lw	$s0,0x4($t5)
/*  f1966b4:	0fc0e706 */ 	jal	chrIsDead
/*  f1966b8:	02002025 */ 	move	$a0,$s0
/*  f1966bc:	14400232 */ 	bnez	$v0,.PF0f196f88
/*  f1966c0:	02802025 */ 	move	$a0,$s4
/*  f1966c4:	0fc64e81 */ 	jal	botIsTargetInvisible
/*  f1966c8:	02002825 */ 	move	$a1,$s0
/*  f1966cc:	1440022e */ 	bnez	$v0,.PF0f196f88
/*  f1966d0:	02802025 */ 	move	$a0,$s4
/*  f1966d4:	0fc64f9c */ 	jal	botPassesCowardCheck
/*  f1966d8:	02002825 */ 	move	$a1,$s0
/*  f1966dc:	1040022a */ 	beqz	$v0,.PF0f196f88
/*  f1966e0:	02002025 */ 	move	$a0,$s0
/*  f1966e4:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f1966e8:	2415002f */ 	li	$s5,0x2f
/*  f1966ec:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f1966f0:	10000225 */ 	b	.PF0f196f88
/*  f1966f4:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PF0f1966f8:
/*  f1966f8:	1440000d */ 	bnez	$v0,.PF0f196730
/*  f1966fc:	2401000d */ 	li	$at,0xd
/*  f196700:	8e4c00d4 */ 	lw	$t4,0xd4($s2)
/*  f196704:	ae5701e0 */ 	sw	$s7,0x1e0($s2)
/*  f196708:	8ecf0338 */ 	lw	$t7,0x338($s6)
/*  f19670c:	000c70c0 */ 	sll	$t6,$t4,0x3
/*  f196710:	01cc7021 */ 	addu	$t6,$t6,$t4
/*  f196714:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f196718:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f19671c:	24150032 */ 	li	$s5,0x32
/*  f196720:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196724:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f196728:	10000217 */ 	b	.PF0f196f88
/*  f19672c:	a642000a */ 	sh	$v0,0xa($s2)
.PF0f196730:
/*  f196730:	5441000e */ 	bnel	$v0,$at,.PF0f19676c
/*  f196734:	24010002 */ 	li	$at,0x2
/*  f196738:	8e5900d4 */ 	lw	$t9,0xd4($s2)
/*  f19673c:	ae4001e0 */ 	sw	$zero,0x1e0($s2)
/*  f196740:	8eca0338 */ 	lw	$t2,0x338($s6)
/*  f196744:	001948c0 */ 	sll	$t1,$t9,0x3
/*  f196748:	01394821 */ 	addu	$t1,$t1,$t9
/*  f19674c:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f196750:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f196754:	24150032 */ 	li	$s5,0x32
/*  f196758:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f19675c:	8d640004 */ 	lw	$a0,0x4($t3)
/*  f196760:	10000209 */ 	b	.PF0f196f88
/*  f196764:	a642000a */ 	sh	$v0,0xa($s2)
/*  f196768:	24010002 */ 	li	$at,0x2
.PF0f19676c:
/*  f19676c:	54410005 */ 	bnel	$v0,$at,.PF0f196784
/*  f196770:	24010003 */ 	li	$at,0x3
/*  f196774:	24150033 */ 	li	$s5,0x33
/*  f196778:	10000203 */ 	b	.PF0f196f88
/*  f19677c:	ae5701dc */ 	sw	$s7,0x1dc($s2)
/*  f196780:	24010003 */ 	li	$at,0x3
.PF0f196784:
/*  f196784:	54410005 */ 	bnel	$v0,$at,.PF0f19679c
/*  f196788:	24010006 */ 	li	$at,0x6
/*  f19678c:	24150033 */ 	li	$s5,0x33
/*  f196790:	100001fd */ 	b	.PF0f196f88
/*  f196794:	ae4001dc */ 	sw	$zero,0x1dc($s2)
/*  f196798:	24010006 */ 	li	$at,0x6
.PF0f19679c:
/*  f19679c:	14410089 */ 	bne	$v0,$at,.PF0f1969c4
/*  f1967a0:	3c0d800b */ 	lui	$t5,0x800b
/*  f1967a4:	91add138 */ 	lbu	$t5,-0x2ec8($t5)
/*  f1967a8:	24010005 */ 	li	$at,0x5
/*  f1967ac:	15a10083 */ 	bne	$t5,$at,.PF0f1969bc
/*  f1967b0:	00000000 */ 	nop
/*  f1967b4:	8e4c009c */ 	lw	$t4,0x9c($s2)
/*  f1967b8:	000c7840 */ 	sll	$t7,$t4,0x1
/*  f1967bc:	05e0007f */ 	bltz	$t7,.PF0f1969bc
/*  f1967c0:	00000000 */ 	nop
/*  f1967c4:	0fc63e8e */ 	jal	radarGetTeamIndex
/*  f1967c8:	92840125 */ 	lbu	$a0,0x125($s4)
/*  f1967cc:	3c07800b */ 	lui	$a3,0x800b
/*  f1967d0:	00003025 */ 	move	$a2,$zero
/*  f1967d4:	24e7c6b0 */ 	addiu	$a3,$a3,-14672
/*  f1967d8:	00002825 */ 	move	$a1,$zero
/*  f1967dc:	27b00298 */ 	addiu	$s0,$sp,0x298
/*  f1967e0:	24080003 */ 	li	$t0,0x3
.PF0f1967e4:
/*  f1967e4:	10a20020 */ 	beq	$a1,$v0,.PF0f196868
/*  f1967e8:	0005c040 */ 	sll	$t8,$a1,0x1
/*  f1967ec:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f1967f0:	87290000 */ 	lh	$t1,0x0($t9)
/*  f1967f4:	00055080 */ 	sll	$t2,$a1,0x2
/*  f1967f8:	00ea5821 */ 	addu	$t3,$a3,$t2
/*  f1967fc:	5120001b */ 	beqzl	$t1,.PF0f19686c
/*  f196800:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f196804:	8d640058 */ 	lw	$a0,0x58($t3)
/*  f196808:	24010004 */ 	li	$at,0x4
/*  f19680c:	00066880 */ 	sll	$t5,$a2,0x2
/*  f196810:	90830000 */ 	lbu	$v1,0x0($a0)
/*  f196814:	020d6021 */ 	addu	$t4,$s0,$t5
/*  f196818:	50610004 */ 	beql	$v1,$at,.PF0f19682c
/*  f19681c:	ad840000 */ 	sw	$a0,0x0($t4)
/*  f196820:	16e30004 */ 	bne	$s7,$v1,.PF0f196834
/*  f196824:	00000000 */ 	nop
/*  f196828:	ad840000 */ 	sw	$a0,0x0($t4)
.PF0f19682c:
/*  f19682c:	1000000e */ 	b	.PF0f196868
/*  f196830:	24c60001 */ 	addiu	$a2,$a2,0x1
.PF0f196834:
/*  f196834:	11030003 */ 	beq	$t0,$v1,.PF0f196844
/*  f196838:	24010006 */ 	li	$at,0x6
/*  f19683c:	5461000b */ 	bnel	$v1,$at,.PF0f19686c
/*  f196840:	24a50001 */ 	addiu	$a1,$a1,0x1
.PF0f196844:
/*  f196844:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f196848:	928e0125 */ 	lbu	$t6,0x125($s4)
/*  f19684c:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f196850:	906f0125 */ 	lbu	$t7,0x125($v1)
/*  f196854:	0218c821 */ 	addu	$t9,$s0,$t8
/*  f196858:	55cf0004 */ 	bnel	$t6,$t7,.PF0f19686c
/*  f19685c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f196860:	af240000 */ 	sw	$a0,0x0($t9)
/*  f196864:	24c60001 */ 	addiu	$a2,$a2,0x1
.PF0f196868:
/*  f196868:	24a50001 */ 	addiu	$a1,$a1,0x1
.PF0f19686c:
/*  f19686c:	24010004 */ 	li	$at,0x4
/*  f196870:	14a1ffdc */ 	bne	$a1,$at,.PF0f1967e4
/*  f196874:	00000000 */ 	nop
/*  f196878:	18c00050 */ 	blez	$a2,.PF0f1969bc
/*  f19687c:	00000000 */ 	nop
/*  f196880:	0c004ad4 */ 	jal	random
/*  f196884:	afa60294 */ 	sw	$a2,0x294($sp)
/*  f196888:	8fa60294 */ 	lw	$a2,0x294($sp)
/*  f19688c:	0046001b */ 	divu	$zero,$v0,$a2
/*  f196890:	00002010 */ 	mfhi	$a0
/*  f196894:	24890001 */ 	addiu	$t1,$a0,0x1
/*  f196898:	00808825 */ 	move	$s1,$a0
/*  f19689c:	0126001a */ 	div	$zero,$t1,$a2
/*  f1968a0:	00001810 */ 	mfhi	$v1
/*  f1968a4:	14c00002 */ 	bnez	$a2,.PF0f1968b0
/*  f1968a8:	00000000 */ 	nop
/*  f1968ac:	0007000d */ 	break	0x7
.PF0f1968b0:
/*  f1968b0:	14c00002 */ 	bnez	$a2,.PF0f1968bc
/*  f1968b4:	00000000 */ 	nop
/*  f1968b8:	0007000d */ 	break	0x7
.PF0f1968bc:
/*  f1968bc:	2401ffff */ 	li	$at,-1
/*  f1968c0:	14c10004 */ 	bne	$a2,$at,.PF0f1968d4
/*  f1968c4:	3c018000 */ 	lui	$at,0x8000
/*  f1968c8:	15210002 */ 	bne	$t1,$at,.PF0f1968d4
/*  f1968cc:	00000000 */ 	nop
/*  f1968d0:	0006000d */ 	break	0x6
.PF0f1968d4:
/*  f1968d4:	00035080 */ 	sll	$t2,$v1,0x2
.PF0f1968d8:
/*  f1968d8:	020a5821 */ 	addu	$t3,$s0,$t2
/*  f1968dc:	8d650000 */ 	lw	$a1,0x0($t3)
/*  f1968e0:	afa60294 */ 	sw	$a2,0x294($sp)
/*  f1968e4:	afa30288 */ 	sw	$v1,0x288($sp)
/*  f1968e8:	02802025 */ 	move	$a0,$s4
/*  f1968ec:	0fc125bb */ 	jal	chrGetSquaredDistanceToCoord
/*  f1968f0:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f1968f4:	3c017f1c */ 	lui	$at,0x7f1c
/*  f1968f8:	c424a5b4 */ 	lwc1	$f4,-0x5a4c($at)
/*  f1968fc:	8fa30288 */ 	lw	$v1,0x288($sp)
/*  f196900:	8fa60294 */ 	lw	$a2,0x294($sp)
/*  f196904:	4604003c */ 	c.lt.s	$f0,$f4
/*  f196908:	246d0001 */ 	addiu	$t5,$v1,0x1
/*  f19690c:	45000003 */ 	bc1f	.PF0f19691c
/*  f196910:	00000000 */ 	nop
/*  f196914:	10000010 */ 	b	.PF0f196958
/*  f196918:	00608825 */ 	move	$s1,$v1
.PF0f19691c:
/*  f19691c:	5071000f */ 	beql	$v1,$s1,.PF0f19695c
/*  f196920:	00116080 */ 	sll	$t4,$s1,0x2
/*  f196924:	01a6001a */ 	div	$zero,$t5,$a2
/*  f196928:	00001810 */ 	mfhi	$v1
/*  f19692c:	14c00002 */ 	bnez	$a2,.PF0f196938
/*  f196930:	00000000 */ 	nop
/*  f196934:	0007000d */ 	break	0x7
.PF0f196938:
/*  f196938:	2401ffff */ 	li	$at,-1
/*  f19693c:	14c10004 */ 	bne	$a2,$at,.PF0f196950
/*  f196940:	3c018000 */ 	lui	$at,0x8000
/*  f196944:	15a10002 */ 	bne	$t5,$at,.PF0f196950
/*  f196948:	00000000 */ 	nop
/*  f19694c:	0006000d */ 	break	0x6
.PF0f196950:
/*  f196950:	1000ffe1 */ 	b	.PF0f1968d8
/*  f196954:	00035080 */ 	sll	$t2,$v1,0x2
.PF0f196958:
/*  f196958:	00116080 */ 	sll	$t4,$s1,0x2
.PF0f19695c:
/*  f19695c:	020c9821 */ 	addu	$s3,$s0,$t4
/*  f196960:	8e620000 */ 	lw	$v0,0x0($s3)
/*  f196964:	24010004 */ 	li	$at,0x4
/*  f196968:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f19696c:	50610004 */ 	beql	$v1,$at,.PF0f196980
/*  f196970:	2415002a */ 	li	$s5,0x2a
/*  f196974:	16e30004 */ 	bne	$s7,$v1,.PF0f196988
/*  f196978:	02802025 */ 	move	$a0,$s4
/*  f19697c:	2415002a */ 	li	$s5,0x2a
.PF0f196980:
/*  f196980:	10000181 */ 	b	.PF0f196f88
/*  f196984:	ae420010 */ 	sw	$v0,0x10($s2)
.PF0f196988:
/*  f196988:	0fc65163 */ 	jal	botCanFollow
/*  f19698c:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f196990:	1040000a */ 	beqz	$v0,.PF0f1969bc
/*  f196994:	00000000 */ 	nop
/*  f196998:	0c004ad4 */ 	jal	random
/*  f19699c:	24150032 */ 	li	$s5,0x32
/*  f1969a0:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f1969a4:	2dcf0001 */ 	sltiu	$t7,$t6,0x1
/*  f1969a8:	ae4f01e0 */ 	sw	$t7,0x1e0($s2)
/*  f1969ac:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f1969b0:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f1969b4:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f1969b8:	a642000a */ 	sh	$v0,0xa($s2)
.PF0f1969bc:
/*  f1969bc:	10000172 */ 	b	.PF0f196f88
/*  f1969c0:	00000000 */ 	nop
.PF0f1969c4:
/*  f1969c4:	24010008 */ 	li	$at,0x8
/*  f1969c8:	14410043 */ 	bne	$v0,$at,.PF0f196ad8
/*  f1969cc:	3c19800b */ 	lui	$t9,0x800b
/*  f1969d0:	9339d138 */ 	lbu	$t9,-0x2ec8($t9)
/*  f1969d4:	24010005 */ 	li	$at,0x5
/*  f1969d8:	1721016b */ 	bne	$t9,$at,.PF0f196f88
/*  f1969dc:	00000000 */ 	nop
/*  f1969e0:	0fc63e8e */ 	jal	radarGetTeamIndex
/*  f1969e4:	92840125 */ 	lbu	$a0,0x125($s4)
/*  f1969e8:	00024880 */ 	sll	$t1,$v0,0x2
/*  f1969ec:	3c03800b */ 	lui	$v1,0x800b
/*  f1969f0:	00691821 */ 	addu	$v1,$v1,$t1
/*  f1969f4:	8c63c708 */ 	lw	$v1,-0x38f8($v1)
/*  f1969f8:	24010003 */ 	li	$at,0x3
/*  f1969fc:	90640000 */ 	lbu	$a0,0x0($v1)
/*  f196a00:	10810003 */ 	beq	$a0,$at,.PF0f196a10
/*  f196a04:	24010006 */ 	li	$at,0x6
/*  f196a08:	54810026 */ 	bnel	$a0,$at,.PF0f196aa4
/*  f196a0c:	c4680008 */ 	lwc1	$f8,0x8($v1)
.PF0f196a10:
/*  f196a10:	8c700004 */ 	lw	$s0,0x4($v1)
/*  f196a14:	928a0125 */ 	lbu	$t2,0x125($s4)
/*  f196a18:	02802025 */ 	move	$a0,$s4
/*  f196a1c:	920b0125 */ 	lbu	$t3,0x125($s0)
/*  f196a20:	154b000e */ 	bne	$t2,$t3,.PF0f196a5c
/*  f196a24:	00000000 */ 	nop
/*  f196a28:	0fc65163 */ 	jal	botCanFollow
/*  f196a2c:	02002825 */ 	move	$a1,$s0
/*  f196a30:	10400155 */ 	beqz	$v0,.PF0f196f88
/*  f196a34:	00000000 */ 	nop
/*  f196a38:	0c004ad4 */ 	jal	random
/*  f196a3c:	24150032 */ 	li	$s5,0x32
/*  f196a40:	304d0003 */ 	andi	$t5,$v0,0x3
/*  f196a44:	2dac0001 */ 	sltiu	$t4,$t5,0x1
/*  f196a48:	ae4c01e0 */ 	sw	$t4,0x1e0($s2)
/*  f196a4c:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196a50:	02002025 */ 	move	$a0,$s0
/*  f196a54:	1000014c */ 	b	.PF0f196f88
/*  f196a58:	a642000a */ 	sh	$v0,0xa($s2)
.PF0f196a5c:
/*  f196a5c:	0fc0e706 */ 	jal	chrIsDead
/*  f196a60:	02002025 */ 	move	$a0,$s0
/*  f196a64:	14400148 */ 	bnez	$v0,.PF0f196f88
/*  f196a68:	02802025 */ 	move	$a0,$s4
/*  f196a6c:	0fc64e81 */ 	jal	botIsTargetInvisible
/*  f196a70:	02002825 */ 	move	$a1,$s0
/*  f196a74:	14400144 */ 	bnez	$v0,.PF0f196f88
/*  f196a78:	02802025 */ 	move	$a0,$s4
/*  f196a7c:	0fc64f9c */ 	jal	botPassesCowardCheck
/*  f196a80:	02002825 */ 	move	$a1,$s0
/*  f196a84:	10400140 */ 	beqz	$v0,.PF0f196f88
/*  f196a88:	02002025 */ 	move	$a0,$s0
/*  f196a8c:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196a90:	2415002f */ 	li	$s5,0x2f
/*  f196a94:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f196a98:	1000013b */ 	b	.PF0f196f88
/*  f196a9c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f196aa0:	c4680008 */ 	lwc1	$f8,0x8($v1)
.PF0f196aa4:
/*  f196aa4:	2415002b */ 	li	$s5,0x2b
/*  f196aa8:	24640028 */ 	addiu	$a0,$v1,0x28
/*  f196aac:	e64800ec */ 	swc1	$f8,0xec($s2)
/*  f196ab0:	c466000c */ 	lwc1	$f6,0xc($v1)
/*  f196ab4:	264500f8 */ 	addiu	$a1,$s2,0xf8
/*  f196ab8:	e64600f0 */ 	swc1	$f6,0xf0($s2)
/*  f196abc:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f196ac0:	0fc1968d */ 	jal	roomsCopy
/*  f196ac4:	e64a00f4 */ 	swc1	$f10,0xf4($s2)
/*  f196ac8:	924e004c */ 	lbu	$t6,0x4c($s2)
/*  f196acc:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f196ad0:	1000012d */ 	b	.PF0f196f88
/*  f196ad4:	a24f004c */ 	sb	$t7,0x4c($s2)
.PF0f196ad8:
/*  f196ad8:	24010009 */ 	li	$at,0x9
/*  f196adc:	14410048 */ 	bne	$v0,$at,.PF0f196c00
/*  f196ae0:	3c18800b */ 	lui	$t8,0x800b
/*  f196ae4:	9318d138 */ 	lbu	$t8,-0x2ec8($t8)
/*  f196ae8:	24010004 */ 	li	$at,0x4
/*  f196aec:	17010126 */ 	bne	$t8,$at,.PF0f196f88
/*  f196af0:	00000000 */ 	nop
/*  f196af4:	8e99001c */ 	lw	$t9,0x1c($s4)
/*  f196af8:	3c0a800b */ 	lui	$t2,0x800b
/*  f196afc:	854ac6be */ 	lh	$t2,-0x3942($t2)
/*  f196b00:	87290028 */ 	lh	$t1,0x28($t9)
/*  f196b04:	152a0016 */ 	bne	$t1,$t2,.PF0f196b60
/*  f196b08:	00000000 */ 	nop
/*  f196b0c:	868b017e */ 	lh	$t3,0x17e($s4)
/*  f196b10:	13cb0013 */ 	beq	$s8,$t3,.PF0f196b60
/*  f196b14:	00000000 */ 	nop
/*  f196b18:	8e4d0128 */ 	lw	$t5,0x128($s2)
/*  f196b1c:	11a00010 */ 	beqz	$t5,.PF0f196b60
/*  f196b20:	00000000 */ 	nop
/*  f196b24:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f196b28:	02802025 */ 	move	$a0,$s4
/*  f196b2c:	02802025 */ 	move	$a0,$s4
/*  f196b30:	0fc64f9c */ 	jal	botPassesCowardCheck
/*  f196b34:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f196b38:	10400009 */ 	beqz	$v0,.PF0f196b60
/*  f196b3c:	02802025 */ 	move	$a0,$s4
/*  f196b40:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f196b44:	2415002f */ 	li	$s5,0x2f
/*  f196b48:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196b4c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f196b50:	240c00fa */ 	li	$t4,0xfa
/*  f196b54:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f196b58:	1000010b */ 	b	.PF0f196f88
/*  f196b5c:	ae4c01d8 */ 	sw	$t4,0x1d8($s2)
.PF0f196b60:
/*  f196b60:	3c04800b */ 	lui	$a0,0x800b
/*  f196b64:	27ae0260 */ 	addiu	$t6,$sp,0x260
/*  f196b68:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f196b6c:	8484c6be */ 	lh	$a0,-0x3942($a0)
/*  f196b70:	27a5026c */ 	addiu	$a1,$sp,0x26c
/*  f196b74:	27a60268 */ 	addiu	$a2,$sp,0x268
/*  f196b78:	0fc66f1c */ 	jal	botroomFindPos
/*  f196b7c:	27a70264 */ 	addiu	$a3,$sp,0x264
/*  f196b80:	10400101 */ 	beqz	$v0,.PF0f196f88
/*  f196b84:	c7b2026c */ 	lwc1	$f18,0x26c($sp)
/*  f196b88:	e65200ec */ 	swc1	$f18,0xec($s2)
/*  f196b8c:	c7a40270 */ 	lwc1	$f4,0x270($sp)
/*  f196b90:	3c04800b */ 	lui	$a0,0x800b
/*  f196b94:	2415002b */ 	li	$s5,0x2b
/*  f196b98:	e64400f0 */ 	swc1	$f4,0xf0($s2)
/*  f196b9c:	c7a80274 */ 	lwc1	$f8,0x274($sp)
/*  f196ba0:	2484c6be */ 	addiu	$a0,$a0,-14658
/*  f196ba4:	264500f8 */ 	addiu	$a1,$s2,0xf8
/*  f196ba8:	0fc1968d */ 	jal	roomsCopy
/*  f196bac:	e64800f4 */ 	swc1	$f8,0xf4($s2)
/*  f196bb0:	8e8f001c */ 	lw	$t7,0x1c($s4)
/*  f196bb4:	3c19800b */ 	lui	$t9,0x800b
/*  f196bb8:	8739c6be */ 	lh	$t9,-0x3942($t9)
/*  f196bbc:	85f80028 */ 	lh	$t8,0x28($t7)
/*  f196bc0:	924e004c */ 	lbu	$t6,0x4c($s2)
/*  f196bc4:	3c0a800b */ 	lui	$t2,0x800b
/*  f196bc8:	03194826 */ 	xor	$t1,$t8,$t9
/*  f196bcc:	2d290001 */ 	sltiu	$t1,$t1,0x1
/*  f196bd0:	0009582b */ 	sltu	$t3,$zero,$t1
/*  f196bd4:	000b61c0 */ 	sll	$t4,$t3,0x7
/*  f196bd8:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f196bdc:	018fc025 */ 	or	$t8,$t4,$t7
/*  f196be0:	a258004c */ 	sb	$t8,0x4c($s2)
/*  f196be4:	8fb90264 */ 	lw	$t9,0x264($sp)
/*  f196be8:	a6590048 */ 	sh	$t9,0x48($s2)
/*  f196bec:	8fa90260 */ 	lw	$t1,0x260($sp)
/*  f196bf0:	a649004a */ 	sh	$t1,0x4a($s2)
/*  f196bf4:	854ac6be */ 	lh	$t2,-0x3942($t2)
/*  f196bf8:	100000e3 */ 	b	.PF0f196f88
/*  f196bfc:	ae4a00bc */ 	sw	$t2,0xbc($s2)
.PF0f196c00:
/*  f196c00:	2401000a */ 	li	$at,0xa
/*  f196c04:	1441002c */ 	bne	$v0,$at,.PF0f196cb8
/*  f196c08:	3c0b800b */ 	lui	$t3,0x800b
/*  f196c0c:	916bd138 */ 	lbu	$t3,-0x2ec8($t3)
/*  f196c10:	24010004 */ 	li	$at,0x4
/*  f196c14:	3c04800b */ 	lui	$a0,0x800b
/*  f196c18:	156100db */ 	bne	$t3,$at,.PF0f196f88
/*  f196c1c:	27a50254 */ 	addiu	$a1,$sp,0x254
/*  f196c20:	27ad0248 */ 	addiu	$t5,$sp,0x248
/*  f196c24:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f196c28:	8484c6be */ 	lh	$a0,-0x3942($a0)
/*  f196c2c:	27a60250 */ 	addiu	$a2,$sp,0x250
/*  f196c30:	0fc66f1c */ 	jal	botroomFindPos
/*  f196c34:	27a7024c */ 	addiu	$a3,$sp,0x24c
/*  f196c38:	104000d3 */ 	beqz	$v0,.PF0f196f88
/*  f196c3c:	c7a60254 */ 	lwc1	$f6,0x254($sp)
/*  f196c40:	e64600ec */ 	swc1	$f6,0xec($s2)
/*  f196c44:	c7aa0258 */ 	lwc1	$f10,0x258($sp)
/*  f196c48:	3c04800b */ 	lui	$a0,0x800b
/*  f196c4c:	2415002b */ 	li	$s5,0x2b
/*  f196c50:	e64a00f0 */ 	swc1	$f10,0xf0($s2)
/*  f196c54:	c7b2025c */ 	lwc1	$f18,0x25c($sp)
/*  f196c58:	2484c6be */ 	addiu	$a0,$a0,-14658
/*  f196c5c:	264500f8 */ 	addiu	$a1,$s2,0xf8
/*  f196c60:	0fc1968d */ 	jal	roomsCopy
/*  f196c64:	e65200f4 */ 	swc1	$f18,0xf4($s2)
/*  f196c68:	8e8e001c */ 	lw	$t6,0x1c($s4)
/*  f196c6c:	3c0f800b */ 	lui	$t7,0x800b
/*  f196c70:	85efc6be */ 	lh	$t7,-0x3942($t7)
/*  f196c74:	85cc0028 */ 	lh	$t4,0x28($t6)
/*  f196c78:	924d004c */ 	lbu	$t5,0x4c($s2)
/*  f196c7c:	3c19800b */ 	lui	$t9,0x800b
/*  f196c80:	018fc026 */ 	xor	$t8,$t4,$t7
/*  f196c84:	2f180001 */ 	sltiu	$t8,$t8,0x1
/*  f196c88:	0018482b */ 	sltu	$t1,$zero,$t8
/*  f196c8c:	000959c0 */ 	sll	$t3,$t1,0x7
/*  f196c90:	31aeff7f */ 	andi	$t6,$t5,0xff7f
/*  f196c94:	016e6025 */ 	or	$t4,$t3,$t6
/*  f196c98:	a24c004c */ 	sb	$t4,0x4c($s2)
/*  f196c9c:	8faf024c */ 	lw	$t7,0x24c($sp)
/*  f196ca0:	a64f0048 */ 	sh	$t7,0x48($s2)
/*  f196ca4:	8fb80248 */ 	lw	$t8,0x248($sp)
/*  f196ca8:	a658004a */ 	sh	$t8,0x4a($s2)
/*  f196cac:	8739c6be */ 	lh	$t9,-0x3942($t9)
/*  f196cb0:	100000b5 */ 	b	.PF0f196f88
/*  f196cb4:	ae5900bc */ 	sw	$t9,0xbc($s2)
.PF0f196cb8:
/*  f196cb8:	24010005 */ 	li	$at,0x5
/*  f196cbc:	1441003b */ 	bne	$v0,$at,.PF0f196dac
/*  f196cc0:	3c09800b */ 	lui	$t1,0x800b
/*  f196cc4:	9129d138 */ 	lbu	$t1,-0x2ec8($t1)
/*  f196cc8:	24010002 */ 	li	$at,0x2
/*  f196ccc:	3c02800b */ 	lui	$v0,0x800b
/*  f196cd0:	152100ad */ 	bne	$t1,$at,.PF0f196f88
/*  f196cd4:	00000000 */ 	nop
/*  f196cd8:	8c42c7ec */ 	lw	$v0,-0x3814($v0)
/*  f196cdc:	104000aa */ 	beqz	$v0,.PF0f196f88
/*  f196ce0:	00000000 */ 	nop
/*  f196ce4:	8e8a001c */ 	lw	$t2,0x1c($s4)
/*  f196ce8:	104a00a7 */ 	beq	$v0,$t2,.PF0f196f88
/*  f196cec:	00000000 */ 	nop
/*  f196cf0:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f196cf4:	24010003 */ 	li	$at,0x3
/*  f196cf8:	3c0d800b */ 	lui	$t5,0x800b
/*  f196cfc:	10610003 */ 	beq	$v1,$at,.PF0f196d0c
/*  f196d00:	24010006 */ 	li	$at,0x6
/*  f196d04:	54610027 */ 	bnel	$v1,$at,.PF0f196da4
/*  f196d08:	2415002c */ 	li	$s5,0x2c
.PF0f196d0c:
/*  f196d0c:	8dadd134 */ 	lw	$t5,-0x2ecc($t5)
/*  f196d10:	8c500004 */ 	lw	$s0,0x4($v0)
/*  f196d14:	02802025 */ 	move	$a0,$s4
/*  f196d18:	31ab0002 */ 	andi	$t3,$t5,0x2
/*  f196d1c:	11600013 */ 	beqz	$t3,.PF0f196d6c
/*  f196d20:	00000000 */ 	nop
/*  f196d24:	928e0125 */ 	lbu	$t6,0x125($s4)
/*  f196d28:	920c0125 */ 	lbu	$t4,0x125($s0)
/*  f196d2c:	02002825 */ 	move	$a1,$s0
/*  f196d30:	15cc000e */ 	bne	$t6,$t4,.PF0f196d6c
/*  f196d34:	00000000 */ 	nop
/*  f196d38:	0fc65163 */ 	jal	botCanFollow
/*  f196d3c:	02802025 */ 	move	$a0,$s4
/*  f196d40:	10400091 */ 	beqz	$v0,.PF0f196f88
/*  f196d44:	00000000 */ 	nop
/*  f196d48:	0c004ad4 */ 	jal	random
/*  f196d4c:	24150032 */ 	li	$s5,0x32
/*  f196d50:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f196d54:	2df80001 */ 	sltiu	$t8,$t7,0x1
/*  f196d58:	ae5801e0 */ 	sw	$t8,0x1e0($s2)
/*  f196d5c:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196d60:	02002025 */ 	move	$a0,$s0
/*  f196d64:	10000088 */ 	b	.PF0f196f88
/*  f196d68:	a642000a */ 	sh	$v0,0xa($s2)
.PF0f196d6c:
/*  f196d6c:	0fc64e81 */ 	jal	botIsTargetInvisible
/*  f196d70:	02002825 */ 	move	$a1,$s0
/*  f196d74:	14400084 */ 	bnez	$v0,.PF0f196f88
/*  f196d78:	02802025 */ 	move	$a0,$s4
/*  f196d7c:	0fc64f9c */ 	jal	botPassesCowardCheck
/*  f196d80:	02002825 */ 	move	$a1,$s0
/*  f196d84:	10400080 */ 	beqz	$v0,.PF0f196f88
/*  f196d88:	02002025 */ 	move	$a0,$s0
/*  f196d8c:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196d90:	2415002f */ 	li	$s5,0x2f
/*  f196d94:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f196d98:	1000007b */ 	b	.PF0f196f88
/*  f196d9c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f196da0:	2415002c */ 	li	$s5,0x2c
.PF0f196da4:
/*  f196da4:	10000078 */ 	b	.PF0f196f88
/*  f196da8:	ae420010 */ 	sw	$v0,0x10($s2)
.PF0f196dac:
/*  f196dac:	2401000b */ 	li	$at,0xb
/*  f196db0:	1441003a */ 	bne	$v0,$at,.PF0f196e9c
/*  f196db4:	3c19800b */ 	lui	$t9,0x800b
/*  f196db8:	9339d138 */ 	lbu	$t9,-0x2ec8($t9)
/*  f196dbc:	3c02800b */ 	lui	$v0,0x800b
/*  f196dc0:	16f90071 */ 	bne	$s7,$t9,.PF0f196f88
/*  f196dc4:	00000000 */ 	nop
/*  f196dc8:	8c42c6b4 */ 	lw	$v0,-0x394c($v0)
/*  f196dcc:	1040006e */ 	beqz	$v0,.PF0f196f88
/*  f196dd0:	00000000 */ 	nop
/*  f196dd4:	8e89001c */ 	lw	$t1,0x1c($s4)
/*  f196dd8:	1049006b */ 	beq	$v0,$t1,.PF0f196f88
/*  f196ddc:	00000000 */ 	nop
/*  f196de0:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f196de4:	24010003 */ 	li	$at,0x3
/*  f196de8:	3c0a800b */ 	lui	$t2,0x800b
/*  f196dec:	10610003 */ 	beq	$v1,$at,.PF0f196dfc
/*  f196df0:	24010006 */ 	li	$at,0x6
/*  f196df4:	54610027 */ 	bnel	$v1,$at,.PF0f196e94
/*  f196df8:	2415002c */ 	li	$s5,0x2c
.PF0f196dfc:
/*  f196dfc:	8d4ad134 */ 	lw	$t2,-0x2ecc($t2)
/*  f196e00:	8c500004 */ 	lw	$s0,0x4($v0)
/*  f196e04:	02802025 */ 	move	$a0,$s4
/*  f196e08:	314d0002 */ 	andi	$t5,$t2,0x2
/*  f196e0c:	11a00013 */ 	beqz	$t5,.PF0f196e5c
/*  f196e10:	00000000 */ 	nop
/*  f196e14:	928b0125 */ 	lbu	$t3,0x125($s4)
/*  f196e18:	920e0125 */ 	lbu	$t6,0x125($s0)
/*  f196e1c:	02002825 */ 	move	$a1,$s0
/*  f196e20:	156e000e */ 	bne	$t3,$t6,.PF0f196e5c
/*  f196e24:	00000000 */ 	nop
/*  f196e28:	0fc65163 */ 	jal	botCanFollow
/*  f196e2c:	02802025 */ 	move	$a0,$s4
/*  f196e30:	10400055 */ 	beqz	$v0,.PF0f196f88
/*  f196e34:	00000000 */ 	nop
/*  f196e38:	0c004ad4 */ 	jal	random
/*  f196e3c:	24150032 */ 	li	$s5,0x32
/*  f196e40:	304c0003 */ 	andi	$t4,$v0,0x3
/*  f196e44:	2d8f0001 */ 	sltiu	$t7,$t4,0x1
/*  f196e48:	ae4f01e0 */ 	sw	$t7,0x1e0($s2)
/*  f196e4c:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196e50:	02002025 */ 	move	$a0,$s0
/*  f196e54:	1000004c */ 	b	.PF0f196f88
/*  f196e58:	a642000a */ 	sh	$v0,0xa($s2)
.PF0f196e5c:
/*  f196e5c:	0fc64e81 */ 	jal	botIsTargetInvisible
/*  f196e60:	02002825 */ 	move	$a1,$s0
/*  f196e64:	14400048 */ 	bnez	$v0,.PF0f196f88
/*  f196e68:	02802025 */ 	move	$a0,$s4
/*  f196e6c:	0fc64f9c */ 	jal	botPassesCowardCheck
/*  f196e70:	02002825 */ 	move	$a1,$s0
/*  f196e74:	10400044 */ 	beqz	$v0,.PF0f196f88
/*  f196e78:	02002025 */ 	move	$a0,$s0
/*  f196e7c:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196e80:	2415002f */ 	li	$s5,0x2f
/*  f196e84:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f196e88:	1000003f */ 	b	.PF0f196f88
/*  f196e8c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f196e90:	2415002c */ 	li	$s5,0x2c
.PF0f196e94:
/*  f196e94:	1000003c */ 	b	.PF0f196f88
/*  f196e98:	ae420010 */ 	sw	$v0,0x10($s2)
.PF0f196e9c:
/*  f196e9c:	2401000c */ 	li	$at,0xc
/*  f196ea0:	14410039 */ 	bne	$v0,$at,.PF0f196f88
/*  f196ea4:	3c18800b */ 	lui	$t8,0x800b
/*  f196ea8:	9318d138 */ 	lbu	$t8,-0x2ec8($t8)
/*  f196eac:	24010003 */ 	li	$at,0x3
/*  f196eb0:	3c02800b */ 	lui	$v0,0x800b
/*  f196eb4:	17010034 */ 	bne	$t8,$at,.PF0f196f88
/*  f196eb8:	00000000 */ 	nop
/*  f196ebc:	8c42c6b4 */ 	lw	$v0,-0x394c($v0)
/*  f196ec0:	3c09800b */ 	lui	$t1,0x800b
/*  f196ec4:	04400030 */ 	bltz	$v0,.PF0f196f88
/*  f196ec8:	0002c840 */ 	sll	$t9,$v0,0x1
/*  f196ecc:	01394821 */ 	addu	$t1,$t1,$t9
/*  f196ed0:	8529c6b8 */ 	lh	$t1,-0x3948($t1)
/*  f196ed4:	3c0d800b */ 	lui	$t5,0x800b
/*  f196ed8:	8e8b001c */ 	lw	$t3,0x1c($s4)
/*  f196edc:	00095080 */ 	sll	$t2,$t1,0x2
/*  f196ee0:	01aa6821 */ 	addu	$t5,$t5,$t2
/*  f196ee4:	8dadca70 */ 	lw	$t5,-0x3590($t5)
/*  f196ee8:	3c0e800b */ 	lui	$t6,0x800b
/*  f196eec:	8da3001c */ 	lw	$v1,0x1c($t5)
/*  f196ef0:	106b0025 */ 	beq	$v1,$t3,.PF0f196f88
/*  f196ef4:	00000000 */ 	nop
/*  f196ef8:	8dced134 */ 	lw	$t6,-0x2ecc($t6)
/*  f196efc:	8c700004 */ 	lw	$s0,0x4($v1)
/*  f196f00:	02802025 */ 	move	$a0,$s4
/*  f196f04:	31cc0002 */ 	andi	$t4,$t6,0x2
/*  f196f08:	11800013 */ 	beqz	$t4,.PF0f196f58
/*  f196f0c:	00000000 */ 	nop
/*  f196f10:	928f0125 */ 	lbu	$t7,0x125($s4)
/*  f196f14:	92180125 */ 	lbu	$t8,0x125($s0)
/*  f196f18:	02002825 */ 	move	$a1,$s0
/*  f196f1c:	15f8000e */ 	bne	$t7,$t8,.PF0f196f58
/*  f196f20:	00000000 */ 	nop
/*  f196f24:	0fc65163 */ 	jal	botCanFollow
/*  f196f28:	02802025 */ 	move	$a0,$s4
/*  f196f2c:	10400016 */ 	beqz	$v0,.PF0f196f88
/*  f196f30:	00000000 */ 	nop
/*  f196f34:	0c004ad4 */ 	jal	random
/*  f196f38:	24150032 */ 	li	$s5,0x32
/*  f196f3c:	30590003 */ 	andi	$t9,$v0,0x3
/*  f196f40:	2f290001 */ 	sltiu	$t1,$t9,0x1
/*  f196f44:	ae4901e0 */ 	sw	$t1,0x1e0($s2)
/*  f196f48:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196f4c:	02002025 */ 	move	$a0,$s0
/*  f196f50:	1000000d */ 	b	.PF0f196f88
/*  f196f54:	a642000a */ 	sh	$v0,0xa($s2)
.PF0f196f58:
/*  f196f58:	0fc64e81 */ 	jal	botIsTargetInvisible
/*  f196f5c:	02002825 */ 	move	$a1,$s0
/*  f196f60:	14400009 */ 	bnez	$v0,.PF0f196f88
/*  f196f64:	02802025 */ 	move	$a0,$s4
/*  f196f68:	0fc64f9c */ 	jal	botPassesCowardCheck
/*  f196f6c:	02002825 */ 	move	$a1,$s0
/*  f196f70:	10400005 */ 	beqz	$v0,.PF0f196f88
/*  f196f74:	02002025 */ 	move	$a0,$s0
/*  f196f78:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f196f7c:	2415002f */ 	li	$s5,0x2f
/*  f196f80:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f196f84:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PF0f196f88:
/*  f196f88:	06a10078 */ 	bgez	$s5,.PF0f19716c
/*  f196f8c:	3c03800b */ 	lui	$v1,0x800b
/*  f196f90:	9063d138 */ 	lbu	$v1,-0x2ec8($v1)
/*  f196f94:	24010003 */ 	li	$at,0x3
/*  f196f98:	16e3001a */ 	bne	$s7,$v1,.PF0f197004
/*  f196f9c:	00000000 */ 	nop
/*  f196fa0:	8e4a009c */ 	lw	$t2,0x9c($s2)
/*  f196fa4:	000a6fc2 */ 	srl	$t5,$t2,0x1f
/*  f196fa8:	11a00070 */ 	beqz	$t5,.PF0f19716c
/*  f196fac:	00000000 */ 	nop
/*  f196fb0:	0c004ad4 */ 	jal	random
/*  f196fb4:	03c08025 */ 	move	$s0,$s8
/*  f196fb8:	24010064 */ 	li	$at,0x64
/*  f196fbc:	0041001b */ 	divu	$zero,$v0,$at
/*  f196fc0:	00005810 */ 	mfhi	$t3
/*  f196fc4:	2d610042 */ 	sltiu	$at,$t3,0x42
/*  f196fc8:	10200005 */ 	beqz	$at,.PF0f196fe0
/*  f196fcc:	02802025 */ 	move	$a0,$s4
/*  f196fd0:	3c0547c3 */ 	lui	$a1,0x47c3
/*  f196fd4:	0fc65178 */ 	jal	botFindTeammateToFollow
/*  f196fd8:	34a55000 */ 	ori	$a1,$a1,0x5000
/*  f196fdc:	00408025 */ 	move	$s0,$v0
.PF0f196fe0:
/*  f196fe0:	06000062 */ 	bltz	$s0,.PF0f19716c
/*  f196fe4:	00000000 */ 	nop
/*  f196fe8:	0c004ad4 */ 	jal	random
/*  f196fec:	24150032 */ 	li	$s5,0x32
/*  f196ff0:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f196ff4:	2dcc0001 */ 	sltiu	$t4,$t6,0x1
/*  f196ff8:	ae4c01e0 */ 	sw	$t4,0x1e0($s2)
/*  f196ffc:	1000005b */ 	b	.PF0f19716c
/*  f197000:	a650000a */ 	sh	$s0,0xa($s2)
.PF0f197004:
/*  f197004:	14610024 */ 	bne	$v1,$at,.PF0f197098
/*  f197008:	3c02800b */ 	lui	$v0,0x800b
/*  f19700c:	8c42c6b4 */ 	lw	$v0,-0x394c($v0)
/*  f197010:	3c18800b */ 	lui	$t8,0x800b
/*  f197014:	04400055 */ 	bltz	$v0,.PF0f19716c
/*  f197018:	00027840 */ 	sll	$t7,$v0,0x1
/*  f19701c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f197020:	8718c6b8 */ 	lh	$t8,-0x3948($t8)
/*  f197024:	3c09800b */ 	lui	$t1,0x800b
/*  f197028:	8e8a001c */ 	lw	$t2,0x1c($s4)
/*  f19702c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f197030:	01394821 */ 	addu	$t1,$t1,$t9
/*  f197034:	8d29ca70 */ 	lw	$t1,-0x3590($t1)
/*  f197038:	8d23001c */ 	lw	$v1,0x1c($t1)
/*  f19703c:	146a004b */ 	bne	$v1,$t2,.PF0f19716c
/*  f197040:	00000000 */ 	nop
/*  f197044:	0c004ad4 */ 	jal	random
/*  f197048:	03c08025 */ 	move	$s0,$s8
/*  f19704c:	24010064 */ 	li	$at,0x64
/*  f197050:	0041001b */ 	divu	$zero,$v0,$at
/*  f197054:	00006810 */ 	mfhi	$t5
/*  f197058:	2da10042 */ 	sltiu	$at,$t5,0x42
/*  f19705c:	10200005 */ 	beqz	$at,.PF0f197074
/*  f197060:	02802025 */ 	move	$a0,$s4
/*  f197064:	3c0547c3 */ 	lui	$a1,0x47c3
/*  f197068:	0fc65178 */ 	jal	botFindTeammateToFollow
/*  f19706c:	34a55000 */ 	ori	$a1,$a1,0x5000
/*  f197070:	00408025 */ 	move	$s0,$v0
.PF0f197074:
/*  f197074:	0600003d */ 	bltz	$s0,.PF0f19716c
/*  f197078:	00000000 */ 	nop
/*  f19707c:	0c004ad4 */ 	jal	random
/*  f197080:	24150032 */ 	li	$s5,0x32
/*  f197084:	304b0003 */ 	andi	$t3,$v0,0x3
/*  f197088:	2d6e0001 */ 	sltiu	$t6,$t3,0x1
/*  f19708c:	ae4e01e0 */ 	sw	$t6,0x1e0($s2)
/*  f197090:	10000036 */ 	b	.PF0f19716c
/*  f197094:	a650000a */ 	sh	$s0,0xa($s2)
.PF0f197098:
/*  f197098:	24010005 */ 	li	$at,0x5
/*  f19709c:	54610021 */ 	bnel	$v1,$at,.PF0f197124
/*  f1970a0:	24010002 */ 	li	$at,0x2
/*  f1970a4:	0fc65655 */ 	jal	botShouldReturnCtcToken
/*  f1970a8:	02802025 */ 	move	$a0,$s4
/*  f1970ac:	1040002f */ 	beqz	$v0,.PF0f19716c
/*  f1970b0:	00000000 */ 	nop
/*  f1970b4:	92840125 */ 	lbu	$a0,0x125($s4)
/*  f1970b8:	0fc63e8e */ 	jal	radarGetTeamIndex
/*  f1970bc:	2415002b */ 	li	$s5,0x2b
/*  f1970c0:	3c07800b */ 	lui	$a3,0x800b
/*  f1970c4:	24e7c6b0 */ 	addiu	$a3,$a3,-14672
/*  f1970c8:	00026040 */ 	sll	$t4,$v0,0x1
/*  f1970cc:	00ec7821 */ 	addu	$t7,$a3,$t4
/*  f1970d0:	85e30008 */ 	lh	$v1,0x8($t7)
/*  f1970d4:	24050042 */ 	li	$a1,0x42
/*  f1970d8:	27a601d8 */ 	addiu	$a2,$sp,0x1d8
/*  f1970dc:	0003c100 */ 	sll	$t8,$v1,0x4
/*  f1970e0:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f1970e4:	0fc45964 */ 	jal	padUnpack
/*  f1970e8:	87240018 */ 	lh	$a0,0x18($t9)
/*  f1970ec:	c7a401d8 */ 	lwc1	$f4,0x1d8($sp)
/*  f1970f0:	924a004c */ 	lbu	$t2,0x4c($s2)
/*  f1970f4:	e64400ec */ 	swc1	$f4,0xec($s2)
/*  f1970f8:	c7a801dc */ 	lwc1	$f8,0x1dc($sp)
/*  f1970fc:	314dff7f */ 	andi	$t5,$t2,0xff7f
/*  f197100:	e64800f0 */ 	swc1	$f8,0xf0($s2)
/*  f197104:	c7a601e0 */ 	lwc1	$f6,0x1e0($sp)
/*  f197108:	e64600f4 */ 	swc1	$f6,0xf4($s2)
/*  f19710c:	8fa90220 */ 	lw	$t1,0x220($sp)
/*  f197110:	a65e00fa */ 	sh	$s8,0xfa($s2)
/*  f197114:	a24d004c */ 	sb	$t5,0x4c($s2)
/*  f197118:	10000014 */ 	b	.PF0f19716c
/*  f19711c:	a64900f8 */ 	sh	$t1,0xf8($s2)
/*  f197120:	24010002 */ 	li	$at,0x2
.PF0f197124:
/*  f197124:	14610011 */ 	bne	$v1,$at,.PF0f19716c
/*  f197128:	3c0b800b */ 	lui	$t3,0x800b
/*  f19712c:	8d6bc7ec */ 	lw	$t3,-0x3814($t3)
/*  f197130:	8e8e001c */ 	lw	$t6,0x1c($s4)
/*  f197134:	156e000d */ 	bne	$t3,$t6,.PF0f19716c
/*  f197138:	00000000 */ 	nop
/*  f19713c:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f197140:	02802025 */ 	move	$a0,$s4
/*  f197144:	3c03800b */ 	lui	$v1,0x800b
/*  f197148:	2463c6b0 */ 	addiu	$v1,$v1,-14672
/*  f19714c:	846c00d2 */ 	lh	$t4,0xd2($v1)
/*  f197150:	2415002e */ 	li	$s5,0x2e
/*  f197154:	104c0005 */ 	beq	$v0,$t4,.PF0f19716c
/*  f197158:	00000000 */ 	nop
/*  f19715c:	8c6f0080 */ 	lw	$t7,0x80($v1)
/*  f197160:	2415002c */ 	li	$s5,0x2c
/*  f197164:	10000001 */ 	b	.PF0f19716c
/*  f197168:	ae4f0010 */ 	sw	$t7,0x10($s2)
.PF0f19716c:
/*  f19716c:	06a100a2 */ 	bgez	$s5,.PF0f1973f8
/*  f197170:	00000000 */ 	nop
/*  f197174:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f197178:	2401000c */ 	li	$at,0xc
/*  f19717c:	93020047 */ 	lbu	$v0,0x47($t8)
/*  f197180:	54410011 */ 	bnel	$v0,$at,.PF0f1971c8
/*  f197184:	24010009 */ 	li	$at,0x9
/*  f197188:	86420076 */ 	lh	$v0,0x76($s2)
/*  f19718c:	02802025 */ 	move	$a0,$s4
/*  f197190:	3c05800b */ 	lui	$a1,0x800b
/*  f197194:	04400098 */ 	bltz	$v0,.PF0f1973f8
/*  f197198:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f19719c:	00b92821 */ 	addu	$a1,$a1,$t9
/*  f1971a0:	0fc64e81 */ 	jal	botIsTargetInvisible
/*  f1971a4:	8ca5ca70 */ 	lw	$a1,-0x3590($a1)
/*  f1971a8:	14400093 */ 	bnez	$v0,.PF0f1973f8
/*  f1971ac:	00000000 */ 	nop
/*  f1971b0:	86490076 */ 	lh	$t1,0x76($s2)
/*  f1971b4:	2415002f */ 	li	$s5,0x2f
/*  f1971b8:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f1971bc:	1000008e */ 	b	.PF0f1973f8
/*  f1971c0:	a6490008 */ 	sh	$t1,0x8($s2)
/*  f1971c4:	24010009 */ 	li	$at,0x9
.PF0f1971c8:
/*  f1971c8:	54410021 */ 	bnel	$v0,$at,.PF0f197250
/*  f1971cc:	24010008 */ 	li	$at,0x8
/*  f1971d0:	8e4a0114 */ 	lw	$t2,0x114($s2)
/*  f1971d4:	0543000f */ 	bgezl	$t2,.PF0f197214
/*  f1971d8:	8e420114 */ 	lw	$v0,0x114($s2)
/*  f1971dc:	86420076 */ 	lh	$v0,0x76($s2)
/*  f1971e0:	02802025 */ 	move	$a0,$s4
/*  f1971e4:	3c05800b */ 	lui	$a1,0x800b
/*  f1971e8:	04400009 */ 	bltz	$v0,.PF0f197210
/*  f1971ec:	00026880 */ 	sll	$t5,$v0,0x2
/*  f1971f0:	00ad2821 */ 	addu	$a1,$a1,$t5
/*  f1971f4:	8ca5ca70 */ 	lw	$a1,-0x3590($a1)
/*  f1971f8:	0fc12b09 */ 	jal	chrCompareTeams
/*  f1971fc:	24060001 */ 	li	$a2,0x1
/*  f197200:	54400004 */ 	bnezl	$v0,.PF0f197214
/*  f197204:	8e420114 */ 	lw	$v0,0x114($s2)
/*  f197208:	864b0076 */ 	lh	$t3,0x76($s2)
/*  f19720c:	ae4b0114 */ 	sw	$t3,0x114($s2)
.PF0f197210:
/*  f197210:	8e420114 */ 	lw	$v0,0x114($s2)
.PF0f197214:
/*  f197214:	02802025 */ 	move	$a0,$s4
/*  f197218:	3c05800b */ 	lui	$a1,0x800b
/*  f19721c:	04400076 */ 	bltz	$v0,.PF0f1973f8
/*  f197220:	00027080 */ 	sll	$t6,$v0,0x2
/*  f197224:	00ae2821 */ 	addu	$a1,$a1,$t6
/*  f197228:	0fc64e81 */ 	jal	botIsTargetInvisible
/*  f19722c:	8ca5ca70 */ 	lw	$a1,-0x3590($a1)
/*  f197230:	14400071 */ 	bnez	$v0,.PF0f1973f8
/*  f197234:	00000000 */ 	nop
/*  f197238:	8e4c0114 */ 	lw	$t4,0x114($s2)
/*  f19723c:	2415002f */ 	li	$s5,0x2f
/*  f197240:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f197244:	1000006c */ 	b	.PF0f1973f8
/*  f197248:	a64c0008 */ 	sh	$t4,0x8($s2)
/*  f19724c:	24010008 */ 	li	$at,0x8
.PF0f197250:
/*  f197250:	5441002a */ 	bnel	$v0,$at,.PF0f1972fc
/*  f197254:	24010006 */ 	li	$at,0x6
/*  f197258:	0fc625a2 */ 	jal	mpGetPlayerRankings
/*  f19725c:	27a400e4 */ 	addiu	$a0,$sp,0xe4
/*  f197260:	18400065 */ 	blez	$v0,.PF0f1973f8
/*  f197264:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f197268:	0302c021 */ 	addu	$t8,$t8,$v0
/*  f19726c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f197270:	27b000e4 */ 	addiu	$s0,$sp,0xe4
/*  f197274:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f197278:	afb90050 */ 	sw	$t9,0x50($sp)
.PF0f19727c:
/*  f19727c:	0fc6386d */ 	jal	func0f18d0e8
/*  f197280:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f197284:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f197288:	0fc63843 */ 	jal	mpGetChrFromPlayerIndex
/*  f19728c:	00402025 */ 	move	$a0,$v0
/*  f197290:	10540012 */ 	beq	$v0,$s4,.PF0f1972dc
/*  f197294:	00402025 */ 	move	$a0,$v0
/*  f197298:	0fc0e706 */ 	jal	chrIsDead
/*  f19729c:	afa200d4 */ 	sw	$v0,0xd4($sp)
/*  f1972a0:	1440000e */ 	bnez	$v0,.PF0f1972dc
/*  f1972a4:	8fb100d4 */ 	lw	$s1,0xd4($sp)
/*  f1972a8:	02802025 */ 	move	$a0,$s4
/*  f1972ac:	02202825 */ 	move	$a1,$s1
/*  f1972b0:	0fc12b09 */ 	jal	chrCompareTeams
/*  f1972b4:	24060002 */ 	li	$a2,0x2
/*  f1972b8:	10400008 */ 	beqz	$v0,.PF0f1972dc
/*  f1972bc:	02802025 */ 	move	$a0,$s4
/*  f1972c0:	0fc64e81 */ 	jal	botIsTargetInvisible
/*  f1972c4:	02202825 */ 	move	$a1,$s1
/*  f1972c8:	14400004 */ 	bnez	$v0,.PF0f1972dc
/*  f1972cc:	8fa900d8 */ 	lw	$t1,0xd8($sp)
/*  f1972d0:	2415002f */ 	li	$s5,0x2f
/*  f1972d4:	a6490008 */ 	sh	$t1,0x8($s2)
/*  f1972d8:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PF0f1972dc:
/*  f1972dc:	8faa0050 */ 	lw	$t2,0x50($sp)
/*  f1972e0:	26100014 */ 	addiu	$s0,$s0,0x14
/*  f1972e4:	020a082b */ 	sltu	$at,$s0,$t2
/*  f1972e8:	1420ffe4 */ 	bnez	$at,.PF0f19727c
/*  f1972ec:	00000000 */ 	nop
/*  f1972f0:	10000041 */ 	b	.PF0f1973f8
/*  f1972f4:	00000000 */ 	nop
/*  f1972f8:	24010006 */ 	li	$at,0x6
.PF0f1972fc:
/*  f1972fc:	1441003e */ 	bne	$v0,$at,.PF0f1973f8
/*  f197300:	3c13800b */ 	lui	$s3,0x800b
/*  f197304:	2673cad0 */ 	addiu	$s3,$s3,-13616
/*  f197308:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f19730c:	44805000 */ 	mtc1	$zero,$f10
/*  f197310:	03c08825 */ 	move	$s1,$s8
/*  f197314:	00008025 */ 	move	$s0,$zero
/*  f197318:	19a00032 */ 	blez	$t5,.PF0f1973e4
/*  f19731c:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
.PF0f197320:
/*  f197320:	0fc63843 */ 	jal	mpGetChrFromPlayerIndex
/*  f197324:	02002025 */ 	move	$a0,$s0
/*  f197328:	10540029 */ 	beq	$v0,$s4,.PF0f1973d0
/*  f19732c:	00402025 */ 	move	$a0,$v0
/*  f197330:	0fc0e706 */ 	jal	chrIsDead
/*  f197334:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f197338:	14400025 */ 	bnez	$v0,.PF0f1973d0
/*  f19733c:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f197340:	02802025 */ 	move	$a0,$s4
/*  f197344:	24060002 */ 	li	$a2,0x2
/*  f197348:	0fc12b09 */ 	jal	chrCompareTeams
/*  f19734c:	afa500c0 */ 	sw	$a1,0xc0($sp)
/*  f197350:	1040001f */ 	beqz	$v0,.PF0f1973d0
/*  f197354:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f197358:	02802025 */ 	move	$a0,$s4
/*  f19735c:	0fc64e81 */ 	jal	botIsTargetInvisible
/*  f197360:	afa500c0 */ 	sw	$a1,0xc0($sp)
/*  f197364:	1440001a */ 	bnez	$v0,.PF0f1973d0
/*  f197368:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f19736c:	8cab02d4 */ 	lw	$t3,0x2d4($a1)
/*  f197370:	11600005 */ 	beqz	$t3,.PF0f197388
/*  f197374:	00000000 */ 	nop
/*  f197378:	c4b20104 */ 	lwc1	$f18,0x104($a1)
/*  f19737c:	c4a40100 */ 	lwc1	$f4,0x100($a1)
/*  f197380:	1000000b */ 	b	.PF0f1973b0
/*  f197384:	46049001 */ 	sub.s	$f0,$f18,$f4
.PF0f197388:
/*  f197388:	0fc4a513 */ 	jal	playermgrGetPlayerNumByProp
/*  f19738c:	8ca4001c */ 	lw	$a0,0x1c($a1)
/*  f197390:	00027080 */ 	sll	$t6,$v0,0x2
/*  f197394:	02ce6021 */ 	addu	$t4,$s6,$t6
/*  f197398:	8d980064 */ 	lw	$t8,0x64($t4)
/*  f19739c:	3c014100 */ 	lui	$at,0x4100
/*  f1973a0:	44813000 */ 	mtc1	$at,$f6
/*  f1973a4:	c70800dc */ 	lwc1	$f8,0xdc($t8)
/*  f1973a8:	46064002 */ 	mul.s	$f0,$f8,$f6
/*  f1973ac:	00000000 */ 	nop
.PF0f1973b0:
/*  f1973b0:	06200005 */ 	bltz	$s1,.PF0f1973c8
/*  f1973b4:	c7aa00d0 */ 	lwc1	$f10,0xd0($sp)
/*  f1973b8:	460a003c */ 	c.lt.s	$f0,$f10
/*  f1973bc:	00000000 */ 	nop
/*  f1973c0:	45020004 */ 	bc1fl	.PF0f1973d4
/*  f1973c4:	8e6f0000 */ 	lw	$t7,0x0($s3)
.PF0f1973c8:
/*  f1973c8:	02008825 */ 	move	$s1,$s0
/*  f1973cc:	e7a000d0 */ 	swc1	$f0,0xd0($sp)
.PF0f1973d0:
/*  f1973d0:	8e6f0000 */ 	lw	$t7,0x0($s3)
.PF0f1973d4:
/*  f1973d4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1973d8:	020f082a */ 	slt	$at,$s0,$t7
/*  f1973dc:	1420ffd0 */ 	bnez	$at,.PF0f197320
/*  f1973e0:	00000000 */ 	nop
.PF0f1973e4:
/*  f1973e4:	06200004 */ 	bltz	$s1,.PF0f1973f8
/*  f1973e8:	00000000 */ 	nop
/*  f1973ec:	2415002f */ 	li	$s5,0x2f
/*  f1973f0:	a6510008 */ 	sh	$s1,0x8($s2)
/*  f1973f4:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PF0f1973f8:
/*  f1973f8:	06a1000d */ 	bgez	$s5,.PF0f197430
/*  f1973fc:	00000000 */ 	nop
/*  f197400:	8699017e */ 	lh	$t9,0x17e($s4)
/*  f197404:	13d9000a */ 	beq	$s8,$t9,.PF0f197430
/*  f197408:	00000000 */ 	nop
/*  f19740c:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f197410:	02802025 */ 	move	$a0,$s4
/*  f197414:	02802025 */ 	move	$a0,$s4
/*  f197418:	0fc64f9c */ 	jal	botPassesCowardCheck
/*  f19741c:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f197420:	10400003 */ 	beqz	$v0,.PF0f197430
/*  f197424:	00000000 */ 	nop
/*  f197428:	2415002f */ 	li	$s5,0x2f
/*  f19742c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PF0f197430:
/*  f197430:	06a1000b */ 	bgez	$s5,.PF0f197460
/*  f197434:	02802025 */ 	move	$a0,$s4
/*  f197438:	0fc65178 */ 	jal	botFindTeammateToFollow
/*  f19743c:	3c054396 */ 	lui	$a1,0x4396
/*  f197440:	04400007 */ 	bltz	$v0,.PF0f197460
/*  f197444:	00408025 */ 	move	$s0,$v0
/*  f197448:	0c004ad4 */ 	jal	random
/*  f19744c:	24150032 */ 	li	$s5,0x32
/*  f197450:	30490003 */ 	andi	$t1,$v0,0x3
/*  f197454:	2d2a0001 */ 	sltiu	$t2,$t1,0x1
/*  f197458:	ae4a01e0 */ 	sw	$t2,0x1e0($s2)
/*  f19745c:	a650000a */ 	sh	$s0,0xa($s2)
.PF0f197460:
/*  f197460:	06a10006 */ 	bgez	$s5,.PF0f19747c
/*  f197464:	00000000 */ 	nop
/*  f197468:	0fc655db */ 	jal	botFindAnyPickup
/*  f19746c:	02802025 */ 	move	$a0,$s4
/*  f197470:	10400002 */ 	beqz	$v0,.PF0f19747c
/*  f197474:	ae420010 */ 	sw	$v0,0x10($s2)
/*  f197478:	2415002a */ 	li	$s5,0x2a
.PF0f19747c:
/*  f19747c:	3c13800b */ 	lui	$s3,0x800b
/*  f197480:	06a00082 */ 	bltz	$s5,.PF0f19768c
/*  f197484:	2673cad0 */ 	addiu	$s3,$s3,-13616
/*  f197488:	2401002a */ 	li	$at,0x2a
/*  f19748c:	56a1000a */ 	bnel	$s5,$at,.PF0f1974b8
/*  f197490:	2401002f */ 	li	$at,0x2f
/*  f197494:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f197498:	02802025 */ 	move	$a0,$s4
/*  f19749c:	50a0007c */ 	beqzl	$a1,.PF0f197690
/*  f1974a0:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f1974a4:	0fc0eb3e */ 	jal	chrGoToProp
/*  f1974a8:	24060002 */ 	li	$a2,0x2
/*  f1974ac:	10000077 */ 	b	.PF0f19768c
/*  f1974b0:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f1974b4:	2401002f */ 	li	$at,0x2f
.PF0f1974b8:
/*  f1974b8:	56a10009 */ 	bnel	$s5,$at,.PF0f1974e0
/*  f1974bc:	24010032 */ 	li	$at,0x32
/*  f1974c0:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
/*  f1974c4:	2401002f */ 	li	$at,0x2f
/*  f1974c8:	51a10071 */ 	beql	$t5,$at,.PF0f197690
/*  f1974cc:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f1974d0:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f1974d4:	1000006d */ 	b	.PF0f19768c
/*  f1974d8:	a25e0074 */ 	sb	$s8,0x74($s2)
/*  f1974dc:	24010032 */ 	li	$at,0x32
.PF0f1974e0:
/*  f1974e0:	56a10010 */ 	bnel	$s5,$at,.PF0f197524
/*  f1974e4:	24010033 */ 	li	$at,0x33
/*  f1974e8:	928b02a0 */ 	lbu	$t3,0x2a0($s4)
/*  f1974ec:	24010032 */ 	li	$at,0x32
/*  f1974f0:	51610067 */ 	beql	$t3,$at,.PF0f197690
/*  f1974f4:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f1974f8:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f1974fc:	8e4e01e0 */ 	lw	$t6,0x1e0($s2)
/*  f197500:	a25e0074 */ 	sb	$s8,0x74($s2)
/*  f197504:	02802025 */ 	move	$a0,$s4
/*  f197508:	51c00061 */ 	beqzl	$t6,.PF0f197690
/*  f19750c:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f197510:	0fc64e0d */ 	jal	botSetTarget
/*  f197514:	03c02825 */ 	move	$a1,$s8
/*  f197518:	1000005d */ 	b	.PF0f197690
/*  f19751c:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f197520:	24010033 */ 	li	$at,0x33
.PF0f197524:
/*  f197524:	56a10010 */ 	bnel	$s5,$at,.PF0f197568
/*  f197528:	2401002b */ 	li	$at,0x2b
/*  f19752c:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f197530:	8e4c01dc */ 	lw	$t4,0x1dc($s2)
/*  f197534:	02802025 */ 	move	$a0,$s4
/*  f197538:	51800004 */ 	beqzl	$t4,.PF0f19754c
/*  f19753c:	02802025 */ 	move	$a0,$s4
/*  f197540:	0fc64e0d */ 	jal	botSetTarget
/*  f197544:	03c02825 */ 	move	$a1,$s8
/*  f197548:	02802025 */ 	move	$a0,$s4
.PF0f19754c:
/*  f19754c:	2645008c */ 	addiu	$a1,$s2,0x8c
/*  f197550:	2646007a */ 	addiu	$a2,$s2,0x7a
/*  f197554:	0fc0e170 */ 	jal	chrGoToPos
/*  f197558:	24070002 */ 	li	$a3,0x2
/*  f19755c:	1000004c */ 	b	.PF0f197690
/*  f197560:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f197564:	2401002b */ 	li	$at,0x2b
.PF0f197568:
/*  f197568:	56a10037 */ 	bnel	$s5,$at,.PF0f197648
/*  f19756c:	2401002c */ 	li	$at,0x2c
/*  f197570:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f197574:	c64400ec */ 	lwc1	$f4,0xec($s2)
/*  f197578:	44808000 */ 	mtc1	$zero,$f16
/*  f19757c:	c4720008 */ 	lwc1	$f18,0x8($v1)
/*  f197580:	c64600f0 */ 	lwc1	$f6,0xf0($s2)
/*  f197584:	c468000c */ 	lwc1	$f8,0xc($v1)
/*  f197588:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f19758c:	c65200f4 */ 	lwc1	$f18,0xf4($s2)
/*  f197590:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f197594:	3c0141a0 */ 	lui	$at,0x41a0
/*  f197598:	4610003c */ 	c.lt.s	$f0,$f16
/*  f19759c:	44817000 */ 	mtc1	$at,$f14
/*  f1975a0:	46064081 */ 	sub.s	$f2,$f8,$f6
/*  f1975a4:	45000002 */ 	bc1f	.PF0f1975b0
/*  f1975a8:	46125301 */ 	sub.s	$f12,$f10,$f18
/*  f1975ac:	46000007 */ 	neg.s	$f0,$f0
.PF0f1975b0:
/*  f1975b0:	4610103c */ 	c.lt.s	$f2,$f16
/*  f1975b4:	02802025 */ 	move	$a0,$s4
/*  f1975b8:	264500ec */ 	addiu	$a1,$s2,0xec
/*  f1975bc:	264600f8 */ 	addiu	$a2,$s2,0xf8
/*  f1975c0:	45000002 */ 	bc1f	.PF0f1975cc
/*  f1975c4:	24070002 */ 	li	$a3,0x2
/*  f1975c8:	46001087 */ 	neg.s	$f2,$f2
.PF0f1975cc:
/*  f1975cc:	4610603c */ 	c.lt.s	$f12,$f16
/*  f1975d0:	00000000 */ 	nop
/*  f1975d4:	45020003 */ 	bc1fl	.PF0f1975e4
/*  f1975d8:	4600703c */ 	c.lt.s	$f14,$f0
/*  f1975dc:	46006307 */ 	neg.s	$f12,$f12
/*  f1975e0:	4600703c */ 	c.lt.s	$f14,$f0
.PF0f1975e4:
/*  f1975e4:	00000000 */ 	nop
/*  f1975e8:	4501000e */ 	bc1t	.PF0f197624
/*  f1975ec:	00000000 */ 	nop
/*  f1975f0:	460c703c */ 	c.lt.s	$f14,$f12
/*  f1975f4:	3c014348 */ 	lui	$at,0x4348
/*  f1975f8:	4501000a */ 	bc1t	.PF0f197624
/*  f1975fc:	00000000 */ 	nop
/*  f197600:	44812000 */ 	mtc1	$at,$f4
/*  f197604:	00000000 */ 	nop
/*  f197608:	4602203c */ 	c.lt.s	$f4,$f2
/*  f19760c:	00000000 */ 	nop
/*  f197610:	45000008 */ 	bc1f	.PF0f197634
/*  f197614:	00000000 */ 	nop
/*  f197618:	828f032d */ 	lb	$t7,0x32d($s4)
/*  f19761c:	05e00005 */ 	bltz	$t7,.PF0f197634
/*  f197620:	00000000 */ 	nop
.PF0f197624:
/*  f197624:	0fc0e170 */ 	jal	chrGoToPos
/*  f197628:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f19762c:	10000018 */ 	b	.PF0f197690
/*  f197630:	928202a0 */ 	lbu	$v0,0x2a0($s4)
.PF0f197634:
/*  f197634:	0fc0baf7 */ 	jal	chrStand
/*  f197638:	02802025 */ 	move	$a0,$s4
/*  f19763c:	10000014 */ 	b	.PF0f197690
/*  f197640:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f197644:	2401002c */ 	li	$at,0x2c
.PF0f197648:
/*  f197648:	56a1000c */ 	bnel	$s5,$at,.PF0f19767c
/*  f19764c:	2401002e */ 	li	$at,0x2e
/*  f197650:	8e590010 */ 	lw	$t9,0x10($s2)
/*  f197654:	02802025 */ 	move	$a0,$s4
/*  f197658:	24060002 */ 	li	$a2,0x2
/*  f19765c:	5320000c */ 	beqzl	$t9,.PF0f197690
/*  f197660:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f197664:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f197668:	0fc0eb3e */ 	jal	chrGoToProp
/*  f19766c:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f197670:	10000007 */ 	b	.PF0f197690
/*  f197674:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f197678:	2401002e */ 	li	$at,0x2e
.PF0f19767c:
/*  f19767c:	16a10003 */ 	bne	$s5,$at,.PF0f19768c
/*  f197680:	02802025 */ 	move	$a0,$s4
/*  f197684:	0fc0baf7 */ 	jal	chrStand
/*  f197688:	a29502a0 */ 	sb	$s5,0x2a0($s4)
.PF0f19768c:
/*  f19768c:	928202a0 */ 	lbu	$v0,0x2a0($s4)
.PF0f197690:
/*  f197690:	2401002a */ 	li	$at,0x2a
/*  f197694:	54410012 */ 	bnel	$v0,$at,.PF0f1976e0
/*  f197698:	2401002f */ 	li	$at,0x2f
/*  f19769c:	82890007 */ 	lb	$t1,0x7($s4)
/*  f1976a0:	2401000f */ 	li	$at,0xf
/*  f1976a4:	240b0029 */ 	li	$t3,0x29
/*  f1976a8:	1521000a */ 	bne	$t1,$at,.PF0f1976d4
/*  f1976ac:	00000000 */ 	nop
/*  f1976b0:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f1976b4:	10a00007 */ 	beqz	$a1,.PF0f1976d4
/*  f1976b8:	00000000 */ 	nop
/*  f1976bc:	8caa0018 */ 	lw	$t2,0x18($a1)
/*  f1976c0:	15400004 */ 	bnez	$t2,.PF0f1976d4
/*  f1976c4:	00000000 */ 	nop
/*  f1976c8:	84ad0002 */ 	lh	$t5,0x2($a1)
/*  f1976cc:	11a00162 */ 	beqz	$t5,.PF0f197c58
/*  f1976d0:	00000000 */ 	nop
.PF0f1976d4:
/*  f1976d4:	10000160 */ 	b	.PF0f197c58
/*  f1976d8:	a28b02a0 */ 	sb	$t3,0x2a0($s4)
/*  f1976dc:	2401002f */ 	li	$at,0x2f
.PF0f1976e0:
/*  f1976e0:	5441003f */ 	bnel	$v0,$at,.PF0f1977e0
/*  f1976e4:	24010032 */ 	li	$at,0x32
/*  f1976e8:	86420008 */ 	lh	$v0,0x8($s2)
/*  f1976ec:	3c04800b */ 	lui	$a0,0x800b
/*  f1976f0:	04400011 */ 	bltz	$v0,.PF0f197738
/*  f1976f4:	00027080 */ 	sll	$t6,$v0,0x2
/*  f1976f8:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f1976fc:	0fc0e706 */ 	jal	chrIsDead
/*  f197700:	8c84ca70 */ 	lw	$a0,-0x3590($a0)
/*  f197704:	5440000a */ 	bnezl	$v0,.PF0f197730
/*  f197708:	240f0029 */ 	li	$t7,0x29
/*  f19770c:	864c0008 */ 	lh	$t4,0x8($s2)
/*  f197710:	3c05800b */ 	lui	$a1,0x800b
/*  f197714:	02802025 */ 	move	$a0,$s4
/*  f197718:	000cc080 */ 	sll	$t8,$t4,0x2
/*  f19771c:	00b82821 */ 	addu	$a1,$a1,$t8
/*  f197720:	0fc64f9c */ 	jal	botPassesCowardCheck
/*  f197724:	8ca5ca70 */ 	lw	$a1,-0x3590($a1)
/*  f197728:	14400003 */ 	bnez	$v0,.PF0f197738
/*  f19772c:	240f0029 */ 	li	$t7,0x29
.PF0f197730:
/*  f197730:	10000149 */ 	b	.PF0f197c58
/*  f197734:	a28f02a0 */ 	sb	$t7,0x2a0($s4)
.PF0f197738:
/*  f197738:	86590008 */ 	lh	$t9,0x8($s2)
/*  f19773c:	07210013 */ 	bgez	$t9,.PF0f19778c
/*  f197740:	00000000 */ 	nop
/*  f197744:	8689017e */ 	lh	$t1,0x17e($s4)
/*  f197748:	53c9000e */ 	beql	$s8,$t1,.PF0f197784
/*  f19774c:	240a0029 */ 	li	$t2,0x29
/*  f197750:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f197754:	02802025 */ 	move	$a0,$s4
/*  f197758:	0fc0e706 */ 	jal	chrIsDead
/*  f19775c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f197760:	54400008 */ 	bnezl	$v0,.PF0f197784
/*  f197764:	240a0029 */ 	li	$t2,0x29
/*  f197768:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f19776c:	02802025 */ 	move	$a0,$s4
/*  f197770:	02802025 */ 	move	$a0,$s4
/*  f197774:	0fc64f9c */ 	jal	botPassesCowardCheck
/*  f197778:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f19777c:	14400003 */ 	bnez	$v0,.PF0f19778c
/*  f197780:	240a0029 */ 	li	$t2,0x29
.PF0f197784:
/*  f197784:	10000134 */ 	b	.PF0f197c58
/*  f197788:	a28a02a0 */ 	sb	$t2,0x2a0($s4)
.PF0f19778c:
/*  f19778c:	0fc661c0 */ 	jal	botcmdTickDistMode
/*  f197790:	02802025 */ 	move	$a0,$s4
/*  f197794:	0fc655ca */ 	jal	botCanDoCriticalPickup
/*  f197798:	02802025 */ 	move	$a0,$s4
/*  f19779c:	10400003 */ 	beqz	$v0,.PF0f1977ac
/*  f1977a0:	240d0029 */ 	li	$t5,0x29
/*  f1977a4:	1000012c */ 	b	.PF0f197c58
/*  f1977a8:	a28d02a0 */ 	sb	$t5,0x2a0($s4)
.PF0f1977ac:
/*  f1977ac:	8e4201d8 */ 	lw	$v0,0x1d8($s2)
/*  f1977b0:	04400129 */ 	bltz	$v0,.PF0f197c58
/*  f1977b4:	00000000 */ 	nop
/*  f1977b8:	8ece0008 */ 	lw	$t6,0x8($s6)
/*  f1977bc:	8e4b0120 */ 	lw	$t3,0x120($s2)
/*  f1977c0:	24180029 */ 	li	$t8,0x29
/*  f1977c4:	01c26023 */ 	subu	$t4,$t6,$v0
/*  f1977c8:	016c082a */ 	slt	$at,$t3,$t4
/*  f1977cc:	10200122 */ 	beqz	$at,.PF0f197c58
/*  f1977d0:	00000000 */ 	nop
/*  f1977d4:	10000120 */ 	b	.PF0f197c58
/*  f1977d8:	a29802a0 */ 	sb	$t8,0x2a0($s4)
/*  f1977dc:	24010032 */ 	li	$at,0x32
.PF0f1977e0:
/*  f1977e0:	5441004e */ 	bnel	$v0,$at,.PF0f19791c
/*  f1977e4:	24010033 */ 	li	$at,0x33
/*  f1977e8:	8642000a */ 	lh	$v0,0xa($s2)
/*  f1977ec:	3c04800b */ 	lui	$a0,0x800b
/*  f1977f0:	04400005 */ 	bltz	$v0,.PF0f197808
/*  f1977f4:	00027880 */ 	sll	$t7,$v0,0x2
/*  f1977f8:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f1977fc:	0fc0e706 */ 	jal	chrIsDead
/*  f197800:	8c84ca70 */ 	lw	$a0,-0x3590($a0)
/*  f197804:	10400003 */ 	beqz	$v0,.PF0f197814
.PF0f197808:
/*  f197808:	24190029 */ 	li	$t9,0x29
/*  f19780c:	10000112 */ 	b	.PF0f197c58
/*  f197810:	a29902a0 */ 	sb	$t9,0x2a0($s4)
.PF0f197814:
/*  f197814:	0fc661c0 */ 	jal	botcmdTickDistMode
/*  f197818:	02802025 */ 	move	$a0,$s4
/*  f19781c:	8e4901e0 */ 	lw	$t1,0x1e0($s2)
/*  f197820:	11200037 */ 	beqz	$t1,.PF0f197900
/*  f197824:	00000000 */ 	nop
/*  f197828:	868a017e */ 	lh	$t2,0x17e($s4)
/*  f19782c:	13ca0034 */ 	beq	$s8,$t2,.PF0f197900
/*  f197830:	00000000 */ 	nop
/*  f197834:	8e4d0128 */ 	lw	$t5,0x128($s2)
/*  f197838:	11a00031 */ 	beqz	$t5,.PF0f197900
/*  f19783c:	00000000 */ 	nop
/*  f197840:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f197844:	02802025 */ 	move	$a0,$s4
/*  f197848:	02802025 */ 	move	$a0,$s4
/*  f19784c:	0fc64f9c */ 	jal	botPassesCowardCheck
/*  f197850:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f197854:	1040002a */ 	beqz	$v0,.PF0f197900
/*  f197858:	3c0143fa */ 	lui	$at,0x43fa
/*  f19785c:	864e000a */ 	lh	$t6,0xa($s2)
/*  f197860:	3c0c800b */ 	lui	$t4,0x800b
/*  f197864:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f197868:	000e5880 */ 	sll	$t3,$t6,0x2
/*  f19786c:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f197870:	8d8cca70 */ 	lw	$t4,-0x3590($t4)
/*  f197874:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f197878:	44806000 */ 	mtc1	$zero,$f12
/*  f19787c:	8d82001c */ 	lw	$v0,0x1c($t4)
/*  f197880:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f197884:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f197888:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f19788c:	46064001 */ 	sub.s	$f0,$f8,$f6
/*  f197890:	46125081 */ 	sub.s	$f2,$f10,$f18
/*  f197894:	460c003c */ 	c.lt.s	$f0,$f12
/*  f197898:	00000000 */ 	nop
/*  f19789c:	45020003 */ 	bc1fl	.PF0f1978ac
/*  f1978a0:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1978a4:	46000007 */ 	neg.s	$f0,$f0
/*  f1978a8:	460c103c */ 	c.lt.s	$f2,$f12
.PF0f1978ac:
/*  f1978ac:	44816000 */ 	mtc1	$at,$f12
/*  f1978b0:	45020003 */ 	bc1fl	.PF0f1978c0
/*  f1978b4:	460c003c */ 	c.lt.s	$f0,$f12
/*  f1978b8:	46001087 */ 	neg.s	$f2,$f2
/*  f1978bc:	460c003c */ 	c.lt.s	$f0,$f12
.PF0f1978c0:
/*  f1978c0:	00000000 */ 	nop
/*  f1978c4:	4500000e */ 	bc1f	.PF0f197900
/*  f1978c8:	00000000 */ 	nop
/*  f1978cc:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1978d0:	2418002f */ 	li	$t8,0x2f
/*  f1978d4:	02802025 */ 	move	$a0,$s4
/*  f1978d8:	45000009 */ 	bc1f	.PF0f197900
/*  f1978dc:	00000000 */ 	nop
/*  f1978e0:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f1978e4:	a29802a0 */ 	sb	$t8,0x2a0($s4)
/*  f1978e8:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f1978ec:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f1978f0:	240f00fa */ 	li	$t7,0xfa
/*  f1978f4:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f1978f8:	ae4f01d8 */ 	sw	$t7,0x1d8($s2)
/*  f1978fc:	a25e0074 */ 	sb	$s8,0x74($s2)
.PF0f197900:
/*  f197900:	0fc655ca */ 	jal	botCanDoCriticalPickup
/*  f197904:	02802025 */ 	move	$a0,$s4
/*  f197908:	104000d3 */ 	beqz	$v0,.PF0f197c58
/*  f19790c:	24190029 */ 	li	$t9,0x29
/*  f197910:	100000d1 */ 	b	.PF0f197c58
/*  f197914:	a29902a0 */ 	sb	$t9,0x2a0($s4)
/*  f197918:	24010033 */ 	li	$at,0x33
.PF0f19791c:
/*  f19791c:	54410063 */ 	bnel	$v0,$at,.PF0f197aac
/*  f197920:	2401002b */ 	li	$at,0x2b
/*  f197924:	82890007 */ 	lb	$t1,0x7($s4)
/*  f197928:	2401000f */ 	li	$at,0xf
/*  f19792c:	11210058 */ 	beq	$t1,$at,.PF0f197a90
/*  f197930:	00000000 */ 	nop
/*  f197934:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f197938:	c648008c */ 	lwc1	$f8,0x8c($s2)
/*  f19793c:	44807000 */ 	mtc1	$zero,$f14
/*  f197940:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f197944:	c64a0090 */ 	lwc1	$f10,0x90($s2)
/*  f197948:	c466000c */ 	lwc1	$f6,0xc($v1)
/*  f19794c:	46082001 */ 	sub.s	$f0,$f4,$f8
/*  f197950:	c6440094 */ 	lwc1	$f4,0x94($s2)
/*  f197954:	c4720010 */ 	lwc1	$f18,0x10($v1)
/*  f197958:	3c014220 */ 	lui	$at,0x4220
/*  f19795c:	460e003c */ 	c.lt.s	$f0,$f14
/*  f197960:	460a3081 */ 	sub.s	$f2,$f6,$f10
/*  f197964:	45000002 */ 	bc1f	.PF0f197970
/*  f197968:	46049301 */ 	sub.s	$f12,$f18,$f4
/*  f19796c:	46000007 */ 	neg.s	$f0,$f0
.PF0f197970:
/*  f197970:	460e103c */ 	c.lt.s	$f2,$f14
/*  f197974:	00000000 */ 	nop
/*  f197978:	45020003 */ 	bc1fl	.PF0f197988
/*  f19797c:	460e603c */ 	c.lt.s	$f12,$f14
/*  f197980:	46001087 */ 	neg.s	$f2,$f2
/*  f197984:	460e603c */ 	c.lt.s	$f12,$f14
.PF0f197988:
/*  f197988:	44817000 */ 	mtc1	$at,$f14
/*  f19798c:	45020003 */ 	bc1fl	.PF0f19799c
/*  f197990:	8e4200dc */ 	lw	$v0,0xdc($s2)
/*  f197994:	46006307 */ 	neg.s	$f12,$f12
/*  f197998:	8e4200dc */ 	lw	$v0,0xdc($s2)
.PF0f19799c:
/*  f19799c:	58400005 */ 	blezl	$v0,.PF0f1979b4
/*  f1979a0:	4600703c */ 	c.lt.s	$f14,$f0
/*  f1979a4:	8eca0038 */ 	lw	$t2,0x38($s6)
/*  f1979a8:	004a6823 */ 	subu	$t5,$v0,$t2
/*  f1979ac:	ae4d00dc */ 	sw	$t5,0xdc($s2)
/*  f1979b0:	4600703c */ 	c.lt.s	$f14,$f0
.PF0f1979b4:
/*  f1979b4:	00000000 */ 	nop
/*  f1979b8:	4503000f */ 	bc1tl	.PF0f1979f8
/*  f1979bc:	8e4c00dc */ 	lw	$t4,0xdc($s2)
/*  f1979c0:	460c703c */ 	c.lt.s	$f14,$f12
/*  f1979c4:	3c014348 */ 	lui	$at,0x4348
/*  f1979c8:	4503000b */ 	bc1tl	.PF0f1979f8
/*  f1979cc:	8e4c00dc */ 	lw	$t4,0xdc($s2)
/*  f1979d0:	44814000 */ 	mtc1	$at,$f8
/*  f1979d4:	00000000 */ 	nop
/*  f1979d8:	4602403c */ 	c.lt.s	$f8,$f2
/*  f1979dc:	00000000 */ 	nop
/*  f1979e0:	4502000e */ 	bc1fl	.PF0f197a1c
/*  f1979e4:	8e5801dc */ 	lw	$t8,0x1dc($s2)
/*  f1979e8:	828b032d */ 	lb	$t3,0x32d($s4)
/*  f1979ec:	0562000b */ 	bltzl	$t3,.PF0f197a1c
/*  f1979f0:	8e5801dc */ 	lw	$t8,0x1dc($s2)
/*  f1979f4:	8e4c00dc */ 	lw	$t4,0xdc($s2)
.PF0f1979f8:
/*  f1979f8:	02802025 */ 	move	$a0,$s4
/*  f1979fc:	2645008c */ 	addiu	$a1,$s2,0x8c
/*  f197a00:	1d80001e */ 	bgtz	$t4,.PF0f197a7c
/*  f197a04:	2646007a */ 	addiu	$a2,$s2,0x7a
/*  f197a08:	0fc0e170 */ 	jal	chrGoToPos
/*  f197a0c:	24070002 */ 	li	$a3,0x2
/*  f197a10:	1000001b */ 	b	.PF0f197a80
/*  f197a14:	8e4d00dc */ 	lw	$t5,0xdc($s2)
/*  f197a18:	8e5801dc */ 	lw	$t8,0x1dc($s2)
.PF0f197a1c:
/*  f197a1c:	53000018 */ 	beqzl	$t8,.PF0f197a80
/*  f197a20:	8e4d00dc */ 	lw	$t5,0xdc($s2)
/*  f197a24:	868f017e */ 	lh	$t7,0x17e($s4)
/*  f197a28:	53cf0015 */ 	beql	$s8,$t7,.PF0f197a80
/*  f197a2c:	8e4d00dc */ 	lw	$t5,0xdc($s2)
/*  f197a30:	8e590128 */ 	lw	$t9,0x128($s2)
/*  f197a34:	53200012 */ 	beqzl	$t9,.PF0f197a80
/*  f197a38:	8e4d00dc */ 	lw	$t5,0xdc($s2)
/*  f197a3c:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f197a40:	02802025 */ 	move	$a0,$s4
/*  f197a44:	02802025 */ 	move	$a0,$s4
/*  f197a48:	0fc64f9c */ 	jal	botPassesCowardCheck
/*  f197a4c:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f197a50:	1040000a */ 	beqz	$v0,.PF0f197a7c
/*  f197a54:	2409002f */ 	li	$t1,0x2f
/*  f197a58:	a28902a0 */ 	sb	$t1,0x2a0($s4)
/*  f197a5c:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f197a60:	02802025 */ 	move	$a0,$s4
/*  f197a64:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f197a68:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f197a6c:	240a00fa */ 	li	$t2,0xfa
/*  f197a70:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f197a74:	ae4a01d8 */ 	sw	$t2,0x1d8($s2)
/*  f197a78:	a25e0074 */ 	sb	$s8,0x74($s2)
.PF0f197a7c:
/*  f197a7c:	8e4d00dc */ 	lw	$t5,0xdc($s2)
.PF0f197a80:
/*  f197a80:	240e0032 */ 	li	$t6,0x32
/*  f197a84:	1da00002 */ 	bgtz	$t5,.PF0f197a90
/*  f197a88:	00000000 */ 	nop
/*  f197a8c:	ae4e00dc */ 	sw	$t6,0xdc($s2)
.PF0f197a90:
/*  f197a90:	0fc655ca */ 	jal	botCanDoCriticalPickup
/*  f197a94:	02802025 */ 	move	$a0,$s4
/*  f197a98:	1040006f */ 	beqz	$v0,.PF0f197c58
/*  f197a9c:	240b0029 */ 	li	$t3,0x29
/*  f197aa0:	1000006d */ 	b	.PF0f197c58
/*  f197aa4:	a28b02a0 */ 	sb	$t3,0x2a0($s4)
/*  f197aa8:	2401002b */ 	li	$at,0x2b
.PF0f197aac:
/*  f197aac:	1441002f */ 	bne	$v0,$at,.PF0f197b6c
/*  f197ab0:	3c0c800b */ 	lui	$t4,0x800b
/*  f197ab4:	918cd138 */ 	lbu	$t4,-0x2ec8($t4)
/*  f197ab8:	24010004 */ 	li	$at,0x4
/*  f197abc:	5581001f */ 	bnel	$t4,$at,.PF0f197b3c
/*  f197ac0:	828b0007 */ 	lb	$t3,0x7($s4)
/*  f197ac4:	8e58004c */ 	lw	$t8,0x4c($s2)
/*  f197ac8:	3c02800b */ 	lui	$v0,0x800b
/*  f197acc:	00187fc2 */ 	srl	$t7,$t8,0x1f
/*  f197ad0:	51e0001a */ 	beqzl	$t7,.PF0f197b3c
/*  f197ad4:	828b0007 */ 	lb	$t3,0x7($s4)
/*  f197ad8:	8442c6be */ 	lh	$v0,-0x3942($v0)
/*  f197adc:	8e5900bc */ 	lw	$t9,0xbc($s2)
/*  f197ae0:	53220006 */ 	beql	$t9,$v0,.PF0f197afc
/*  f197ae4:	8e8d001c */ 	lw	$t5,0x1c($s4)
/*  f197ae8:	9249004c */ 	lbu	$t1,0x4c($s2)
/*  f197aec:	312aff7f */ 	andi	$t2,$t1,0xff7f
/*  f197af0:	10000011 */ 	b	.PF0f197b38
/*  f197af4:	a24a004c */ 	sb	$t2,0x4c($s2)
/*  f197af8:	8e8d001c */ 	lw	$t5,0x1c($s4)
.PF0f197afc:
/*  f197afc:	85ae0028 */ 	lh	$t6,0x28($t5)
/*  f197b00:	51c2000e */ 	beql	$t6,$v0,.PF0f197b3c
/*  f197b04:	828b0007 */ 	lb	$t3,0x7($s4)
/*  f197b08:	86440048 */ 	lh	$a0,0x48($s2)
/*  f197b0c:	04820006 */ 	bltzl	$a0,.PF0f197b28
/*  f197b10:	8644004a */ 	lh	$a0,0x4a($s2)
/*  f197b14:	0fc45b48 */ 	jal	padSetFlag
/*  f197b18:	3c050002 */ 	lui	$a1,0x2
/*  f197b1c:	10000007 */ 	b	.PF0f197b3c
/*  f197b20:	828b0007 */ 	lb	$t3,0x7($s4)
/*  f197b24:	8644004a */ 	lh	$a0,0x4a($s2)
.PF0f197b28:
/*  f197b28:	04820004 */ 	bltzl	$a0,.PF0f197b3c
/*  f197b2c:	828b0007 */ 	lb	$t3,0x7($s4)
/*  f197b30:	0fc45bfa */ 	jal	coverSetFlag
/*  f197b34:	24050100 */ 	li	$a1,0x100
.PF0f197b38:
/*  f197b38:	828b0007 */ 	lb	$t3,0x7($s4)
.PF0f197b3c:
/*  f197b3c:	2401000f */ 	li	$at,0xf
/*  f197b40:	240c0029 */ 	li	$t4,0x29
/*  f197b44:	11610003 */ 	beq	$t3,$at,.PF0f197b54
/*  f197b48:	00000000 */ 	nop
/*  f197b4c:	10000042 */ 	b	.PF0f197c58
/*  f197b50:	a28c02a0 */ 	sb	$t4,0x2a0($s4)
.PF0f197b54:
/*  f197b54:	0fc655ca */ 	jal	botCanDoCriticalPickup
/*  f197b58:	02802025 */ 	move	$a0,$s4
/*  f197b5c:	1040003e */ 	beqz	$v0,.PF0f197c58
/*  f197b60:	24180029 */ 	li	$t8,0x29
/*  f197b64:	1000003c */ 	b	.PF0f197c58
/*  f197b68:	a29802a0 */ 	sb	$t8,0x2a0($s4)
.PF0f197b6c:
/*  f197b6c:	2401002c */ 	li	$at,0x2c
/*  f197b70:	54410029 */ 	bnel	$v0,$at,.PF0f197c18
/*  f197b74:	2401002e */ 	li	$at,0x2e
/*  f197b78:	0fc655ca */ 	jal	botCanDoCriticalPickup
/*  f197b7c:	02802025 */ 	move	$a0,$s4
/*  f197b80:	10400003 */ 	beqz	$v0,.PF0f197b90
/*  f197b84:	240f0029 */ 	li	$t7,0x29
/*  f197b88:	10000033 */ 	b	.PF0f197c58
/*  f197b8c:	a28f02a0 */ 	sb	$t7,0x2a0($s4)
.PF0f197b90:
/*  f197b90:	82990007 */ 	lb	$t9,0x7($s4)
/*  f197b94:	2401000f */ 	li	$at,0xf
/*  f197b98:	240a0029 */ 	li	$t2,0x29
/*  f197b9c:	17210008 */ 	bne	$t9,$at,.PF0f197bc0
/*  f197ba0:	00000000 */ 	nop
/*  f197ba4:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f197ba8:	10a00005 */ 	beqz	$a1,.PF0f197bc0
/*  f197bac:	00000000 */ 	nop
/*  f197bb0:	8ca90018 */ 	lw	$t1,0x18($a1)
/*  f197bb4:	3c03800b */ 	lui	$v1,0x800b
/*  f197bb8:	11200003 */ 	beqz	$t1,.PF0f197bc8
/*  f197bbc:	00000000 */ 	nop
.PF0f197bc0:
/*  f197bc0:	10000025 */ 	b	.PF0f197c58
/*  f197bc4:	a28a02a0 */ 	sb	$t2,0x2a0($s4)
.PF0f197bc8:
/*  f197bc8:	9063d138 */ 	lbu	$v1,-0x2ec8($v1)
/*  f197bcc:	24010002 */ 	li	$at,0x2
/*  f197bd0:	12e30021 */ 	beq	$s7,$v1,.PF0f197c58
/*  f197bd4:	00000000 */ 	nop
/*  f197bd8:	1461001f */ 	bne	$v1,$at,.PF0f197c58
/*  f197bdc:	3c0d800b */ 	lui	$t5,0x800b
/*  f197be0:	8dadc7ec */ 	lw	$t5,-0x3814($t5)
/*  f197be4:	8e8e001c */ 	lw	$t6,0x1c($s4)
/*  f197be8:	15ae001b */ 	bne	$t5,$t6,.PF0f197c58
/*  f197bec:	00000000 */ 	nop
/*  f197bf0:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f197bf4:	02802025 */ 	move	$a0,$s4
/*  f197bf8:	3c0b800b */ 	lui	$t3,0x800b
/*  f197bfc:	856bc782 */ 	lh	$t3,-0x387e($t3)
/*  f197c00:	240c0029 */ 	li	$t4,0x29
/*  f197c04:	144b0014 */ 	bne	$v0,$t3,.PF0f197c58
/*  f197c08:	00000000 */ 	nop
/*  f197c0c:	10000012 */ 	b	.PF0f197c58
/*  f197c10:	a28c02a0 */ 	sb	$t4,0x2a0($s4)
/*  f197c14:	2401002e */ 	li	$at,0x2e
.PF0f197c18:
/*  f197c18:	1441000f */ 	bne	$v0,$at,.PF0f197c58
/*  f197c1c:	00000000 */ 	nop
/*  f197c20:	0fc655ca */ 	jal	botCanDoCriticalPickup
/*  f197c24:	02802025 */ 	move	$a0,$s4
/*  f197c28:	10400003 */ 	beqz	$v0,.PF0f197c38
/*  f197c2c:	24180029 */ 	li	$t8,0x29
/*  f197c30:	10000009 */ 	b	.PF0f197c58
/*  f197c34:	a29802a0 */ 	sb	$t8,0x2a0($s4)
.PF0f197c38:
/*  f197c38:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f197c3c:	02802025 */ 	move	$a0,$s4
/*  f197c40:	3c0f800b */ 	lui	$t7,0x800b
/*  f197c44:	85efc782 */ 	lh	$t7,-0x387e($t7)
/*  f197c48:	24190029 */ 	li	$t9,0x29
/*  f197c4c:	104f0002 */ 	beq	$v0,$t7,.PF0f197c58
/*  f197c50:	00000000 */ 	nop
/*  f197c54:	a29902a0 */ 	sb	$t9,0x2a0($s4)
.PF0f197c58:
/*  f197c58:	0fc64fd0 */ 	jal	botChooseGeneralTarget
/*  f197c5c:	02802025 */ 	move	$a0,$s4
/*  f197c60:	0fc63831 */ 	jal	mpPlayerGetIndex
/*  f197c64:	02802025 */ 	move	$a0,$s4
/*  f197c68:	8ec9000c */ 	lw	$t1,0xc($s6)
/*  f197c6c:	8e6a0000 */ 	lw	$t2,0x0($s3)
/*  f197c70:	012a001a */ 	div	$zero,$t1,$t2
/*  f197c74:	00006810 */ 	mfhi	$t5
/*  f197c78:	15400002 */ 	bnez	$t2,.PF0f197c84
/*  f197c7c:	00000000 */ 	nop
/*  f197c80:	0007000d */ 	break	0x7
.PF0f197c84:
/*  f197c84:	2401ffff */ 	li	$at,-1
/*  f197c88:	15410004 */ 	bne	$t2,$at,.PF0f197c9c
/*  f197c8c:	3c018000 */ 	lui	$at,0x8000
/*  f197c90:	15210002 */ 	bne	$t1,$at,.PF0f197c9c
/*  f197c94:	00000000 */ 	nop
/*  f197c98:	0006000d */ 	break	0x6
.PF0f197c9c:
/*  f197c9c:	144d0024 */ 	bne	$v0,$t5,.PF0f197d30
/*  f197ca0:	00000000 */ 	nop
/*  f197ca4:	868e017e */ 	lh	$t6,0x17e($s4)
/*  f197ca8:	13ce0021 */ 	beq	$s8,$t6,.PF0f197d30
/*  f197cac:	00000000 */ 	nop
/*  f197cb0:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f197cb4:	02802025 */ 	move	$a0,$s4
/*  f197cb8:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f197cbc:	00408025 */ 	move	$s0,$v0
/*  f197cc0:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f197cc4:	0fc4534d */ 	jal	waypointFindClosestToPos
/*  f197cc8:	24650028 */ 	addiu	$a1,$v1,0x28
/*  f197ccc:	00408825 */ 	move	$s1,$v0
/*  f197cd0:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f197cd4:	0fc4534d */ 	jal	waypointFindClosestToPos
/*  f197cd8:	26050028 */ 	addiu	$a1,$s0,0x28
/*  f197cdc:	12200014 */ 	beqz	$s1,.PF0f197d30
/*  f197ce0:	00408025 */ 	move	$s0,$v0
/*  f197ce4:	10400012 */ 	beqz	$v0,.PF0f197d30
/*  f197ce8:	00000000 */ 	nop
/*  f197cec:	8ecb0008 */ 	lw	$t3,0x8($s6)
/*  f197cf0:	868f0000 */ 	lh	$t7,0x0($s4)
/*  f197cf4:	000b6243 */ 	sra	$t4,$t3,0x9
/*  f197cf8:	000cc1c0 */ 	sll	$t8,$t4,0x7
/*  f197cfc:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f197d00:	03192021 */ 	addu	$a0,$t8,$t9
/*  f197d04:	0fc45348 */ 	jal	waypointSetHashThing
/*  f197d08:	00802825 */ 	move	$a1,$a0
/*  f197d0c:	02002025 */ 	move	$a0,$s0
/*  f197d10:	02202825 */ 	move	$a1,$s1
/*  f197d14:	264601e8 */ 	addiu	$a2,$s2,0x1e8
/*  f197d18:	0fc45733 */ 	jal	waypointFindRoute
/*  f197d1c:	24070008 */ 	li	$a3,0x8
/*  f197d20:	ae420208 */ 	sw	$v0,0x208($s2)
/*  f197d24:	00002025 */ 	move	$a0,$zero
/*  f197d28:	0fc45348 */ 	jal	waypointSetHashThing
/*  f197d2c:	00002825 */ 	move	$a1,$zero
.PF0f197d30:
/*  f197d30:	0fc667fb */ 	jal	botinvTick
/*  f197d34:	02802025 */ 	move	$a0,$s4
/*  f197d38:	afa00088 */ 	sw	$zero,0x88($sp)
/*  f197d3c:	00009825 */ 	move	$s3,$zero
/*  f197d40:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f197d44:	02408825 */ 	move	$s1,$s2
.PF0f197d48:
/*  f197d48:	8e22005c */ 	lw	$v0,0x5c($s1)
/*  f197d4c:	0000a825 */ 	move	$s5,$zero
/*  f197d50:	18400004 */ 	blez	$v0,.PF0f197d64
/*  f197d54:	00000000 */ 	nop
/*  f197d58:	8ec90038 */ 	lw	$t1,0x38($s6)
/*  f197d5c:	00495023 */ 	subu	$t2,$v0,$t1
/*  f197d60:	ae2a005c */ 	sw	$t2,0x5c($s1)
.PF0f197d64:
/*  f197d64:	16770004 */ 	bne	$s3,$s7,.PF0f197d78
/*  f197d68:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f197d6c:	51a00003 */ 	beqzl	$t5,.PF0f197d7c
/*  f197d70:	8e4e0044 */ 	lw	$t6,0x44($s2)
/*  f197d74:	ae37005c */ 	sw	$s7,0x5c($s1)
.PF0f197d78:
/*  f197d78:	8e4e0044 */ 	lw	$t6,0x44($s2)
.PF0f197d7c:
/*  f197d7c:	15c00212 */ 	bnez	$t6,.PF0f1985c8
/*  f197d80:	00000000 */ 	nop
/*  f197d84:	8e4b00cc */ 	lw	$t3,0xcc($s2)
/*  f197d88:	1d60020f */ 	bgtz	$t3,.PF0f1985c8
/*  f197d8c:	00000000 */ 	nop
/*  f197d90:	8e42004c */ 	lw	$v0,0x4c($s2)
/*  f197d94:	0013c040 */ 	sll	$t8,$s3,0x1
/*  f197d98:	02581821 */ 	addu	$v1,$s2,$t8
/*  f197d9c:	00027840 */ 	sll	$t7,$v0,0x1
/*  f197da0:	05e300b5 */ 	bgezl	$t7,.PF0f198078
/*  f197da4:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f197da8:	8479003c */ 	lh	$t9,0x3c($v1)
/*  f197dac:	07200206 */ 	bltz	$t9,.PF0f1985c8
/*  f197db0:	00000000 */ 	nop
/*  f197db4:	8469002c */ 	lh	$t1,0x2c($v1)
/*  f197db8:	1d200203 */ 	bgtz	$t1,.PF0f1985c8
/*  f197dbc:	00000000 */ 	nop
/*  f197dc0:	8e4a0020 */ 	lw	$t2,0x20($s2)
/*  f197dc4:	2401001c */ 	li	$at,0x1c
/*  f197dc8:	2404001c */ 	li	$a0,0x1c
/*  f197dcc:	1541000d */ 	bne	$t2,$at,.PF0f197e04
/*  f197dd0:	02e02825 */ 	move	$a1,$s7
/*  f197dd4:	0fc26dd4 */ 	jal	bgunGetMinClipQty
/*  f197dd8:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f197ddc:	8e2d0024 */ 	lw	$t5,0x24($s1)
/*  f197de0:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f197de4:	02802025 */ 	move	$a0,$s4
/*  f197de8:	01a2082a */ 	slt	$at,$t5,$v0
/*  f197dec:	10200005 */ 	beqz	$at,.PF0f197e04
/*  f197df0:	02602825 */ 	move	$a1,$s3
/*  f197df4:	0fc651d3 */ 	jal	botScheduleReload
/*  f197df8:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f197dfc:	100001f2 */ 	b	.PF0f1985c8
/*  f197e00:	00000000 */ 	nop
.PF0f197e04:
/*  f197e04:	846e003c */ 	lh	$t6,0x3c($v1)
/*  f197e08:	8ecb0038 */ 	lw	$t3,0x38($s6)
/*  f197e0c:	01cb6023 */ 	subu	$t4,$t6,$t3
/*  f197e10:	a46c003c */ 	sh	$t4,0x3c($v1)
/*  f197e14:	868f017e */ 	lh	$t7,0x17e($s4)
/*  f197e18:	53cf0042 */ 	beql	$s8,$t7,.PF0f197f24
/*  f197e1c:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f197e20:	8e580128 */ 	lw	$t8,0x128($s2)
/*  f197e24:	5300003f */ 	beqzl	$t8,.PF0f197f24
/*  f197e28:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f197e2c:	8e490004 */ 	lw	$t1,0x4($s2)
/*  f197e30:	3c0e8009 */ 	lui	$t6,0x8009
/*  f197e34:	8e59011c */ 	lw	$t9,0x11c($s2)
/*  f197e38:	912a0048 */ 	lbu	$t2,0x48($t1)
/*  f197e3c:	02802025 */ 	move	$a0,$s4
/*  f197e40:	000a6940 */ 	sll	$t5,$t2,0x5
/*  f197e44:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f197e48:	91ce8264 */ 	lbu	$t6,-0x7d9c($t6)
/*  f197e4c:	032e082a */ 	slt	$at,$t9,$t6
/*  f197e50:	54200034 */ 	bnezl	$at,.PF0f197f24
/*  f197e54:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f197e58:	0fc644c8 */ 	jal	botIsDizzy
/*  f197e5c:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f197e60:	14400030 */ 	bnez	$v0,.PF0f197f24
/*  f197e64:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f197e68:	8e4b0020 */ 	lw	$t3,0x20($s2)
/*  f197e6c:	2401001c */ 	li	$at,0x1c
/*  f197e70:	02802025 */ 	move	$a0,$s4
/*  f197e74:	15610014 */ 	bne	$t3,$at,.PF0f197ec8
/*  f197e78:	24050028 */ 	li	$a1,0x28
/*  f197e7c:	02802025 */ 	move	$a0,$s4
/*  f197e80:	2405001e */ 	li	$a1,0x1e
/*  f197e84:	00003025 */ 	move	$a2,$zero
/*  f197e88:	0fc12480 */ 	jal	chrIsTargetInFov
/*  f197e8c:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f197e90:	1040000b */ 	beqz	$v0,.PF0f197ec0
/*  f197e94:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f197e98:	02802025 */ 	move	$a0,$s4
/*  f197e9c:	0fc124d8 */ 	jal	chrGetDistanceToTarget
/*  f197ea0:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f197ea4:	3c014352 */ 	lui	$at,0x4352
/*  f197ea8:	44813000 */ 	mtc1	$at,$f6
/*  f197eac:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f197eb0:	4600303c */ 	c.lt.s	$f6,$f0
/*  f197eb4:	00000000 */ 	nop
/*  f197eb8:	4502001b */ 	bc1fl	.PF0f197f28
/*  f197ebc:	846c003c */ 	lh	$t4,0x3c($v1)
.PF0f197ec0:
/*  f197ec0:	10000018 */ 	b	.PF0f197f24
/*  f197ec4:	a460003c */ 	sh	$zero,0x3c($v1)
.PF0f197ec8:
/*  f197ec8:	00003025 */ 	move	$a2,$zero
/*  f197ecc:	0fc12480 */ 	jal	chrIsTargetInFov
/*  f197ed0:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f197ed4:	10400010 */ 	beqz	$v0,.PF0f197f18
/*  f197ed8:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f197edc:	3c014352 */ 	lui	$at,0x4352
/*  f197ee0:	44815000 */ 	mtc1	$at,$f10
/*  f197ee4:	3c014316 */ 	lui	$at,0x4316
/*  f197ee8:	44819000 */ 	mtc1	$at,$f18
/*  f197eec:	02802025 */ 	move	$a0,$s4
/*  f197ef0:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f197ef4:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f197ef8:	0fc124d8 */ 	jal	chrGetDistanceToTarget
/*  f197efc:	e7a40050 */ 	swc1	$f4,0x50($sp)
/*  f197f00:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f197f04:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f197f08:	4600403c */ 	c.lt.s	$f8,$f0
/*  f197f0c:	00000000 */ 	nop
/*  f197f10:	45020005 */ 	bc1fl	.PF0f197f28
/*  f197f14:	846c003c */ 	lh	$t4,0x3c($v1)
.PF0f197f18:
/*  f197f18:	10000002 */ 	b	.PF0f197f24
/*  f197f1c:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f197f20:	a460003c */ 	sh	$zero,0x3c($v1)
.PF0f197f24:
/*  f197f24:	846c003c */ 	lh	$t4,0x3c($v1)
.PF0f197f28:
/*  f197f28:	3c014352 */ 	lui	$at,0x4352
/*  f197f2c:	058101a6 */ 	bgez	$t4,.PF0f1985c8
/*  f197f30:	00000000 */ 	nop
/*  f197f34:	44813000 */ 	mtc1	$at,$f6
/*  f197f38:	02802025 */ 	move	$a0,$s4
/*  f197f3c:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f197f40:	44105000 */ 	mfc1	$s0,$f10
/*  f197f44:	0fc089cc */ 	jal	chrUncloakTemporarily
/*  f197f48:	00000000 */ 	nop
/*  f197f4c:	02802025 */ 	move	$a0,$s4
/*  f197f50:	24050002 */ 	li	$a1,0x2
/*  f197f54:	02003025 */ 	move	$a2,$s0
/*  f197f58:	0fc0eef2 */ 	jal	chrPunchInflictDamage
/*  f197f5c:	00003825 */ 	move	$a3,$zero
/*  f197f60:	16600199 */ 	bnez	$s3,.PF0f1985c8
/*  f197f64:	00000000 */ 	nop
/*  f197f68:	8e580020 */ 	lw	$t8,0x20($s2)
/*  f197f6c:	2709ffff */ 	addiu	$t1,$t8,-1
/*  f197f70:	2d21001c */ 	sltiu	$at,$t1,0x1c
/*  f197f74:	10200006 */ 	beqz	$at,.PF0f197f90
/*  f197f78:	00094880 */ 	sll	$t1,$t1,0x2
/*  f197f7c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f197f80:	00290821 */ 	addu	$at,$at,$t1
/*  f197f84:	8c29a5b8 */ 	lw	$t1,-0x5a48($at)
/*  f197f88:	01200008 */ 	jr	$t1
/*  f197f8c:	00000000 */ 	nop
.PF0f197f90:
/*  f197f90:	8e8a02d4 */ 	lw	$t2,0x2d4($s4)
/*  f197f94:	24190064 */ 	li	$t9,0x64
/*  f197f98:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*  f197f9c:	91a20048 */ 	lbu	$v0,0x48($t5)
/*  f197fa0:	14400003 */ 	bnez	$v0,.PF0f197fb0
/*  f197fa4:	00000000 */ 	nop
/*  f197fa8:	10000007 */ 	b	.PF0f197fc8
/*  f197fac:	a659003c */ 	sh	$t9,0x3c($s2)
.PF0f197fb0:
/*  f197fb0:	16e20004 */ 	bne	$s7,$v0,.PF0f197fc4
/*  f197fb4:	240b0019 */ 	li	$t3,0x19
/*  f197fb8:	240e0032 */ 	li	$t6,0x32
/*  f197fbc:	10000002 */ 	b	.PF0f197fc8
/*  f197fc0:	a64e003c */ 	sh	$t6,0x3c($s2)
.PF0f197fc4:
/*  f197fc4:	a64b003c */ 	sh	$t3,0x3c($s2)
.PF0f197fc8:
/*  f197fc8:	0c004ad4 */ 	jal	random
/*  f197fcc:	00000000 */ 	nop
/*  f197fd0:	24010003 */ 	li	$at,0x3
/*  f197fd4:	0041001b */ 	divu	$zero,$v0,$at
/*  f197fd8:	00006010 */ 	mfhi	$t4
/*  f197fdc:	1580017a */ 	bnez	$t4,.PF0f1985c8
/*  f197fe0:	00000000 */ 	nop
/*  f197fe4:	864f003c */ 	lh	$t7,0x3c($s2)
/*  f197fe8:	25f8fff0 */ 	addiu	$t8,$t7,-16
/*  f197fec:	10000176 */ 	b	.PF0f1985c8
/*  f197ff0:	a658003e */ 	sh	$t8,0x3e($s2)
/*  f197ff4:	8e8902d4 */ 	lw	$t1,0x2d4($s4)
/*  f197ff8:	240d0064 */ 	li	$t5,0x64
/*  f197ffc:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*  f198000:	91420048 */ 	lbu	$v0,0x48($t2)
/*  f198004:	14400003 */ 	bnez	$v0,.PF0f198014
/*  f198008:	00000000 */ 	nop
/*  f19800c:	10000007 */ 	b	.PF0f19802c
/*  f198010:	a64d003c */ 	sh	$t5,0x3c($s2)
.PF0f198014:
/*  f198014:	16e20004 */ 	bne	$s7,$v0,.PF0f198028
/*  f198018:	240e0032 */ 	li	$t6,0x32
/*  f19801c:	2419004b */ 	li	$t9,0x4b
/*  f198020:	10000002 */ 	b	.PF0f19802c
/*  f198024:	a659003c */ 	sh	$t9,0x3c($s2)
.PF0f198028:
/*  f198028:	a64e003c */ 	sh	$t6,0x3c($s2)
.PF0f19802c:
/*  f19802c:	8e8b0174 */ 	lw	$t3,0x174($s4)
/*  f198030:	11600165 */ 	beqz	$t3,.PF0f1985c8
/*  f198034:	00000000 */ 	nop
/*  f198038:	864c003c */ 	lh	$t4,0x3c($s2)
/*  f19803c:	258fffdf */ 	addiu	$t7,$t4,-33
/*  f198040:	10000161 */ 	b	.PF0f1985c8
/*  f198044:	a64f003e */ 	sh	$t7,0x3e($s2)
/*  f198048:	24180032 */ 	li	$t8,0x32
/*  f19804c:	a658003c */ 	sh	$t8,0x3c($s2)
/*  f198050:	2404001c */ 	li	$a0,0x1c
/*  f198054:	0fc26dd4 */ 	jal	bgunGetMinClipQty
/*  f198058:	02e02825 */ 	move	$a1,$s7
/*  f19805c:	8e490024 */ 	lw	$t1,0x24($s2)
/*  f198060:	01225023 */ 	subu	$t2,$t1,$v0
/*  f198064:	10000158 */ 	b	.PF0f1985c8
/*  f198068:	ae4a0024 */ 	sw	$t2,0x24($s2)
/*  f19806c:	10000156 */ 	b	.PF0f1985c8
/*  f198070:	a640003c */ 	sh	$zero,0x3c($s2)
/*  f198074:	8e440020 */ 	lw	$a0,0x20($s2)
.PF0f198078:
/*  f198078:	24010019 */ 	li	$at,0x19
/*  f19807c:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f198080:	14810011 */ 	bne	$a0,$at,.PF0f1980c8
/*  f198084:	00022880 */ 	sll	$a1,$v0,0x2
/*  f198088:	07230010 */ 	bgezl	$t9,.PF0f1980cc
/*  f19808c:	0005c7c2 */ 	srl	$t8,$a1,0x1f
/*  f198090:	868e017e */ 	lh	$t6,0x17e($s4)
/*  f198094:	53ce000d */ 	beql	$s8,$t6,.PF0f1980cc
/*  f198098:	0005c7c2 */ 	srl	$t8,$a1,0x1f
/*  f19809c:	8e4b0024 */ 	lw	$t3,0x24($s2)
/*  f1980a0:	19600149 */ 	blez	$t3,.PF0f1985c8
/*  f1980a4:	00000000 */ 	nop
/*  f1980a8:	0fc089cc */ 	jal	chrUncloakTemporarily
/*  f1980ac:	02802025 */ 	move	$a0,$s4
/*  f1980b0:	0fc66e54 */ 	jal	botactCreateSlayerRocket
/*  f1980b4:	02802025 */ 	move	$a0,$s4
/*  f1980b8:	8e4c0024 */ 	lw	$t4,0x24($s2)
/*  f1980bc:	258fffff */ 	addiu	$t7,$t4,-1
/*  f1980c0:	10000141 */ 	b	.PF0f1985c8
/*  f1980c4:	ae4f0024 */ 	sw	$t7,0x24($s2)
.PF0f1980c8:
/*  f1980c8:	0005c7c2 */ 	srl	$t8,$a1,0x1f
.PF0f1980cc:
/*  f1980cc:	0fc66ce7 */ 	jal	botactIsWeaponThrowable
/*  f1980d0:	03002825 */ 	move	$a1,$t8
/*  f1980d4:	1040005b */ 	beqz	$v0,.PF0f198244
/*  f1980d8:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f1980dc:	1660013a */ 	bnez	$s3,.PF0f1985c8
/*  f1980e0:	00000000 */ 	nop
/*  f1980e4:	8e420034 */ 	lw	$v0,0x34($s2)
/*  f1980e8:	02402025 */ 	move	$a0,$s2
/*  f1980ec:	58400005 */ 	blezl	$v0,.PF0f198104
/*  f1980f0:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
/*  f1980f4:	8ec90038 */ 	lw	$t1,0x38($s6)
/*  f1980f8:	00495023 */ 	subu	$t2,$v0,$t1
/*  f1980fc:	ae4a0034 */ 	sw	$t2,0x34($s2)
/*  f198100:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
.PF0f198104:
/*  f198104:	8db90034 */ 	lw	$t9,0x34($t5)
/*  f198108:	1f20012f */ 	bgtz	$t9,.PF0f1985c8
/*  f19810c:	00000000 */ 	nop
/*  f198110:	8e46004c */ 	lw	$a2,0x4c($s2)
/*  f198114:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f198118:	00003825 */ 	move	$a3,$zero
/*  f19811c:	00067080 */ 	sll	$t6,$a2,0x2
/*  f198120:	0fc66b39 */ 	jal	botactGetAmmoQuantityByWeapon
/*  f198124:	000e37c2 */ 	srl	$a2,$t6,0x1f
/*  f198128:	5c400008 */ 	bgtzl	$v0,.PF0f19814c
/*  f19812c:	868c017e */ 	lh	$t4,0x17e($s4)
/*  f198130:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198134:	2401000e */ 	li	$at,0xe
/*  f198138:	10810003 */ 	beq	$a0,$at,.PF0f198148
/*  f19813c:	2401000f */ 	li	$at,0xf
/*  f198140:	14810121 */ 	bne	$a0,$at,.PF0f1985c8
/*  f198144:	00000000 */ 	nop
.PF0f198148:
/*  f198148:	868c017e */ 	lh	$t4,0x17e($s4)
.PF0f19814c:
/*  f19814c:	00008025 */ 	move	$s0,$zero
/*  f198150:	13cc0018 */ 	beq	$s8,$t4,.PF0f1981b4
/*  f198154:	00000000 */ 	nop
/*  f198158:	8e4f0128 */ 	lw	$t7,0x128($s2)
/*  f19815c:	11e00015 */ 	beqz	$t7,.PF0f1981b4
/*  f198160:	00000000 */ 	nop
/*  f198164:	8e490004 */ 	lw	$t1,0x4($s2)
/*  f198168:	3c198009 */ 	lui	$t9,0x8009
/*  f19816c:	8e58011c */ 	lw	$t8,0x11c($s2)
/*  f198170:	912a0048 */ 	lbu	$t2,0x48($t1)
/*  f198174:	000a6940 */ 	sll	$t5,$t2,0x5
/*  f198178:	032dc821 */ 	addu	$t9,$t9,$t5
/*  f19817c:	93398264 */ 	lbu	$t9,-0x7d9c($t9)
/*  f198180:	0319082a */ 	slt	$at,$t8,$t9
/*  f198184:	1420000b */ 	bnez	$at,.PF0f1981b4
/*  f198188:	00000000 */ 	nop
/*  f19818c:	0fc644c8 */ 	jal	botIsDizzy
/*  f198190:	02802025 */ 	move	$a0,$s4
/*  f198194:	14400006 */ 	bnez	$v0,.PF0f1981b0
/*  f198198:	02802025 */ 	move	$a0,$s4
/*  f19819c:	2405002d */ 	li	$a1,0x2d
/*  f1981a0:	0fc12480 */ 	jal	chrIsTargetInFov
/*  f1981a4:	00003025 */ 	move	$a2,$zero
/*  f1981a8:	10400002 */ 	beqz	$v0,.PF0f1981b4
/*  f1981ac:	00000000 */ 	nop
.PF0f1981b0:
/*  f1981b0:	02e08025 */ 	move	$s0,$s7
.PF0f1981b4:
/*  f1981b4:	12000104 */ 	beqz	$s0,.PF0f1985c8
/*  f1981b8:	00000000 */ 	nop
/*  f1981bc:	0fc089cc */ 	jal	chrUncloakTemporarily
/*  f1981c0:	02802025 */ 	move	$a0,$s4
/*  f1981c4:	8e46004c */ 	lw	$a2,0x4c($s2)
/*  f1981c8:	02402025 */ 	move	$a0,$s2
/*  f1981cc:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f1981d0:	00067080 */ 	sll	$t6,$a2,0x2
/*  f1981d4:	000e37c2 */ 	srl	$a2,$t6,0x1f
/*  f1981d8:	0fc66b9c */ 	jal	botactTryRemoveAmmoFromReserve
/*  f1981dc:	02e03825 */ 	move	$a3,$s7
/*  f1981e0:	0fc66d1f */ 	jal	botact0f19a37c
/*  f1981e4:	02802025 */ 	move	$a0,$s4
/*  f1981e8:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f1981ec:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1981f0:	00056080 */ 	sll	$t4,$a1,0x2
/*  f1981f4:	0fc2c531 */ 	jal	weaponGetFunctionById
/*  f1981f8:	000c2fc2 */ 	srl	$a1,$t4,0x1f
/*  f1981fc:	5040000d */ 	beqzl	$v0,.PF0f198234
/*  f198200:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
/*  f198204:	8c490010 */ 	lw	$t1,0x10($v0)
/*  f198208:	02802025 */ 	move	$a0,$s4
/*  f19820c:	00095340 */ 	sll	$t2,$t1,0xd
/*  f198210:	05430008 */ 	bgezl	$t2,.PF0f198234
/*  f198214:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
/*  f198218:	0fc663a5 */ 	jal	botinvRemoveItem
/*  f19821c:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f198220:	02802025 */ 	move	$a0,$s4
/*  f198224:	02e02825 */ 	move	$a1,$s7
/*  f198228:	0fc6696c */ 	jal	botinvSwitchToWeapon
/*  f19822c:	00003025 */ 	move	$a2,$zero
/*  f198230:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
.PF0f198234:
/*  f198234:	0fc66cf7 */ 	jal	botactGetProjectileThrowInterval
/*  f198238:	8da40020 */ 	lw	$a0,0x20($t5)
/*  f19823c:	100000e2 */ 	b	.PF0f1985c8
/*  f198240:	ae420034 */ 	sw	$v0,0x34($s2)
.PF0f198244:
/*  f198244:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f198248:	8f2e0170 */ 	lw	$t6,0x170($t9)
/*  f19824c:	0013c040 */ 	sll	$t8,$s3,0x1
/*  f198250:	02536821 */ 	addu	$t5,$s2,$s3
/*  f198254:	11c000d9 */ 	beqz	$t6,.PF0f1985bc
/*  f198258:	0258c821 */ 	addu	$t9,$s2,$t8
/*  f19825c:	8e2b0024 */ 	lw	$t3,0x24($s1)
/*  f198260:	596000d7 */ 	blezl	$t3,.PF0f1985c0
/*  f198264:	ae2000c4 */ 	sw	$zero,0xc4($s1)
/*  f198268:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f19826c:	00008025 */ 	move	$s0,$zero
/*  f198270:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198274:	00056080 */ 	sll	$t4,$a1,0x2
/*  f198278:	0fc2c8f8 */ 	jal	weaponGetNumTicksPerShot
/*  f19827c:	000c2fc2 */ 	srl	$a1,$t4,0x1f
/*  f198280:	5c400030 */ 	bgtzl	$v0,.PF0f198344
/*  f198284:	02e08025 */ 	move	$s0,$s7
/*  f198288:	8e490020 */ 	lw	$t1,0x20($s2)
/*  f19828c:	24010006 */ 	li	$at,0x6
/*  f198290:	55210027 */ 	bnel	$t1,$at,.PF0f198330
/*  f198294:	8e29005c */ 	lw	$t1,0x5c($s1)
/*  f198298:	8e4a004c */ 	lw	$t2,0x4c($s2)
/*  f19829c:	000a6880 */ 	sll	$t5,$t2,0x2
/*  f1982a0:	000dc7c2 */ 	srl	$t8,$t5,0x1f
/*  f1982a4:	56f80022 */ 	bnel	$s7,$t8,.PF0f198330
/*  f1982a8:	8e29005c */ 	lw	$t1,0x5c($s1)
/*  f1982ac:	8e390024 */ 	lw	$t9,0x24($s1)
/*  f1982b0:	2b210002 */ 	slti	$at,$t9,0x2
/*  f1982b4:	1420001d */ 	bnez	$at,.PF0f19832c
/*  f1982b8:	3c017f1c */ 	lui	$at,0x7f1c
/*  f1982bc:	c428a628 */ 	lwc1	$f8,-0x59d8($at)
/*  f1982c0:	c6c4004c */ 	lwc1	$f4,0x4c($s6)
/*  f1982c4:	c62000e4 */ 	lwc1	$f0,0xe4($s1)
/*  f1982c8:	3c0140a0 */ 	lui	$at,0x40a0
/*  f1982cc:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f1982d0:	4600048d */ 	trunc.w.s	$f18,$f0
/*  f1982d4:	44039000 */ 	mfc1	$v1,$f18
/*  f1982d8:	44819000 */ 	mtc1	$at,$f18
/*  f1982dc:	46060280 */ 	add.s	$f10,$f0,$f6
/*  f1982e0:	3c0140a0 */ 	lui	$at,0x40a0
/*  f1982e4:	e62a00e4 */ 	swc1	$f10,0xe4($s1)
/*  f1982e8:	c62000e4 */ 	lwc1	$f0,0xe4($s1)
/*  f1982ec:	4600903c */ 	c.lt.s	$f18,$f0
/*  f1982f0:	00000000 */ 	nop
/*  f1982f4:	45020006 */ 	bc1fl	.PF0f198310
/*  f1982f8:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f1982fc:	44812000 */ 	mtc1	$at,$f4
/*  f198300:	00000000 */ 	nop
/*  f198304:	e62400e4 */ 	swc1	$f4,0xe4($s1)
/*  f198308:	c62000e4 */ 	lwc1	$f0,0xe4($s1)
/*  f19830c:	4600020d */ 	trunc.w.s	$f8,$f0
.PF0f198310:
/*  f198310:	44024000 */ 	mfc1	$v0,$f8
/*  f198314:	00000000 */ 	nop
/*  f198318:	50430005 */ 	beql	$v0,$v1,.PF0f198330
/*  f19831c:	8e29005c */ 	lw	$t1,0x5c($s1)
/*  f198320:	8e2c0024 */ 	lw	$t4,0x24($s1)
/*  f198324:	258fffff */ 	addiu	$t7,$t4,-1
/*  f198328:	ae2f0024 */ 	sw	$t7,0x24($s1)
.PF0f19832c:
/*  f19832c:	8e29005c */ 	lw	$t1,0x5c($s1)
.PF0f198330:
/*  f198330:	1d200004 */ 	bgtz	$t1,.PF0f198344
/*  f198334:	00000000 */ 	nop
/*  f198338:	10000002 */ 	b	.PF0f198344
/*  f19833c:	02e08025 */ 	move	$s0,$s7
/*  f198340:	02e08025 */ 	move	$s0,$s7
.PF0f198344:
/*  f198344:	52000052 */ 	beqzl	$s0,.PF0f198490
/*  f198348:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f19834c:	8e2a00c4 */ 	lw	$t2,0xc4($s1)
/*  f198350:	02536821 */ 	addu	$t5,$s2,$s3
/*  f198354:	15400004 */ 	bnez	$t2,.PF0f198368
/*  f198358:	00000000 */ 	nop
/*  f19835c:	91b8004d */ 	lbu	$t8,0x4d($t5)
/*  f198360:	5b000004 */ 	blezl	$t8,.PF0f198374
/*  f198364:	8699017e */ 	lh	$t9,0x17e($s4)
.PF0f198368:
/*  f198368:	1000003a */ 	b	.PF0f198454
/*  f19836c:	02e0a825 */ 	move	$s5,$s7
/*  f198370:	8699017e */ 	lh	$t9,0x17e($s4)
.PF0f198374:
/*  f198374:	13d90037 */ 	beq	$s8,$t9,.PF0f198454
/*  f198378:	00000000 */ 	nop
/*  f19837c:	8e4e0128 */ 	lw	$t6,0x128($s2)
/*  f198380:	11c00034 */ 	beqz	$t6,.PF0f198454
/*  f198384:	00000000 */ 	nop
/*  f198388:	8e4c0004 */ 	lw	$t4,0x4($s2)
/*  f19838c:	3c0a8009 */ 	lui	$t2,0x8009
/*  f198390:	8e4b011c */ 	lw	$t3,0x11c($s2)
/*  f198394:	918f0048 */ 	lbu	$t7,0x48($t4)
/*  f198398:	000f4940 */ 	sll	$t1,$t7,0x5
/*  f19839c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f1983a0:	914a8264 */ 	lbu	$t2,-0x7d9c($t2)
/*  f1983a4:	016a082a */ 	slt	$at,$t3,$t2
/*  f1983a8:	1420002a */ 	bnez	$at,.PF0f198454
/*  f1983ac:	00000000 */ 	nop
/*  f1983b0:	0fc644c8 */ 	jal	botIsDizzy
/*  f1983b4:	02802025 */ 	move	$a0,$s4
/*  f1983b8:	14400006 */ 	bnez	$v0,.PF0f1983d4
/*  f1983bc:	02802025 */ 	move	$a0,$s4
/*  f1983c0:	2405002d */ 	li	$a1,0x2d
/*  f1983c4:	0fc12480 */ 	jal	chrIsTargetInFov
/*  f1983c8:	00003025 */ 	move	$a2,$zero
/*  f1983cc:	10400021 */ 	beqz	$v0,.PF0f198454
/*  f1983d0:	00000000 */ 	nop
.PF0f1983d4:
/*  f1983d4:	0fc0a26a */ 	jal	chrGetTargetProp
/*  f1983d8:	02802025 */ 	move	$a0,$s4
/*  f1983dc:	0fc0e706 */ 	jal	chrIsDead
/*  f1983e0:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f1983e4:	1440001b */ 	bnez	$v0,.PF0f198454
/*  f1983e8:	00000000 */ 	nop
/*  f1983ec:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1983f0:	2401000b */ 	li	$at,0xb
/*  f1983f4:	02e0a825 */ 	move	$s5,$s7
/*  f1983f8:	54810009 */ 	bnel	$a0,$at,.PF0f198420
/*  f1983fc:	24010014 */ 	li	$at,0x14
/*  f198400:	8e4d004c */ 	lw	$t5,0x4c($s2)
/*  f198404:	000dc080 */ 	sll	$t8,$t5,0x2
/*  f198408:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f19840c:	56f90004 */ 	bnel	$s7,$t9,.PF0f198420
/*  f198410:	24010014 */ 	li	$at,0x14
/*  f198414:	1000000f */ 	b	.PF0f198454
/*  f198418:	ae3700c4 */ 	sw	$s7,0xc4($s1)
/*  f19841c:	24010014 */ 	li	$at,0x14
.PF0f198420:
/*  f198420:	1481000c */ 	bne	$a0,$at,.PF0f198454
/*  f198424:	00137040 */ 	sll	$t6,$s3,0x1
/*  f198428:	024e1821 */ 	addu	$v1,$s2,$t6
/*  f19842c:	846c00e0 */ 	lh	$t4,0xe0($v1)
/*  f198430:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f198434:	240a004b */ 	li	$t2,0x4b
/*  f198438:	018f4821 */ 	addu	$t1,$t4,$t7
/*  f19843c:	a46900e0 */ 	sh	$t1,0xe0($v1)
/*  f198440:	846b00e0 */ 	lh	$t3,0xe0($v1)
/*  f198444:	2961004c */ 	slti	$at,$t3,0x4c
/*  f198448:	14200002 */ 	bnez	$at,.PF0f198454
/*  f19844c:	00000000 */ 	nop
/*  f198450:	a46a00e0 */ 	sh	$t2,0xe0($v1)
.PF0f198454:
/*  f198454:	16a0000d */ 	bnez	$s5,.PF0f19848c
/*  f198458:	00136840 */ 	sll	$t5,$s3,0x1
/*  f19845c:	024d1821 */ 	addu	$v1,$s2,$t5
/*  f198460:	846200e0 */ 	lh	$v0,0xe0($v1)
/*  f198464:	5840000a */ 	blezl	$v0,.PF0f198490
/*  f198468:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f19846c:	8ed80038 */ 	lw	$t8,0x38($s6)
/*  f198470:	02e0a825 */ 	move	$s5,$s7
/*  f198474:	0058c823 */ 	subu	$t9,$v0,$t8
/*  f198478:	a47900e0 */ 	sh	$t9,0xe0($v1)
/*  f19847c:	846e00e0 */ 	lh	$t6,0xe0($v1)
/*  f198480:	05c30003 */ 	bgezl	$t6,.PF0f198490
/*  f198484:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f198488:	a46000e0 */ 	sh	$zero,0xe0($v1)
.PF0f19848c:
/*  f19848c:	8e45004c */ 	lw	$a1,0x4c($s2)
.PF0f198490:
/*  f198490:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198494:	00056080 */ 	sll	$t4,$a1,0x2
/*  f198498:	0fc2c8f8 */ 	jal	weaponGetNumTicksPerShot
/*  f19849c:	000c2fc2 */ 	srl	$a1,$t4,0x1f
/*  f1984a0:	1c400049 */ 	bgtz	$v0,.PF0f1985c8
/*  f1984a4:	00000000 */ 	nop
/*  f1984a8:	12a00047 */ 	beqz	$s5,.PF0f1985c8
/*  f1984ac:	00000000 */ 	nop
/*  f1984b0:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f1984b4:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1984b8:	00054880 */ 	sll	$t1,$a1,0x2
/*  f1984bc:	0fc66dc3 */ 	jal	botactGetShootInterval60
/*  f1984c0:	00092fc2 */ 	srl	$a1,$t1,0x1f
/*  f1984c4:	28410006 */ 	slti	$at,$v0,0x6
/*  f1984c8:	1420000b */ 	bnez	$at,.PF0f1984f8
/*  f1984cc:	ae22005c */ 	sw	$v0,0x5c($s1)
/*  f1984d0:	00026880 */ 	sll	$t5,$v0,0x2
/*  f1984d4:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f1984d8:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f1984dc:	01a26821 */ 	addu	$t5,$t5,$v0
/*  f1984e0:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f1984e4:	2401003c */ 	li	$at,0x3c
/*  f1984e8:	01a1001a */ 	div	$zero,$t5,$at
/*  f1984ec:	0000c012 */ 	mflo	$t8
/*  f1984f0:	ae38005c */ 	sw	$t8,0x5c($s1)
/*  f1984f4:	00000000 */ 	nop
.PF0f1984f8:
/*  f1984f8:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f1984fc:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198500:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f198504:	0fc2c531 */ 	jal	weaponGetFunctionById
/*  f198508:	00192fc2 */ 	srl	$a1,$t9,0x1f
/*  f19850c:	1040002e */ 	beqz	$v0,.PF0f1985c8
/*  f198510:	00000000 */ 	nop
/*  f198514:	8c430010 */ 	lw	$v1,0x10($v0)
/*  f198518:	306c1002 */ 	andi	$t4,$v1,0x1002
/*  f19851c:	1180002a */ 	beqz	$t4,.PF0f1985c8
/*  f198520:	00000000 */ 	nop
/*  f198524:	8e2f0024 */ 	lw	$t7,0x24($s1)
/*  f198528:	30691000 */ 	andi	$t1,$v1,0x1000
/*  f19852c:	29e10002 */ 	slti	$at,$t7,0x2
/*  f198530:	14200025 */ 	bnez	$at,.PF0f1985c8
/*  f198534:	00000000 */ 	nop
/*  f198538:	11200003 */ 	beqz	$t1,.PF0f198548
/*  f19853c:	24040003 */ 	li	$a0,0x3
/*  f198540:	10000001 */ 	b	.PF0f198548
/*  f198544:	24040002 */ 	li	$a0,0x2
.PF0f198548:
/*  f198548:	8e8b02d4 */ 	lw	$t3,0x2d4($s4)
/*  f19854c:	01731021 */ 	addu	$v0,$t3,$s3
/*  f198550:	904a004d */ 	lbu	$t2,0x4d($v0)
/*  f198554:	254d0001 */ 	addiu	$t5,$t2,0x1
/*  f198558:	a04d004d */ 	sb	$t5,0x4d($v0)
/*  f19855c:	8e9802d4 */ 	lw	$t8,0x2d4($s4)
/*  f198560:	03131021 */ 	addu	$v0,$t8,$s3
/*  f198564:	9059004d */ 	lbu	$t9,0x4d($v0)
/*  f198568:	0324001a */ 	div	$zero,$t9,$a0
/*  f19856c:	00007010 */ 	mfhi	$t6
/*  f198570:	a04e004d */ 	sb	$t6,0x4d($v0)
/*  f198574:	8e8302d4 */ 	lw	$v1,0x2d4($s4)
/*  f198578:	14800002 */ 	bnez	$a0,.PF0f198584
/*  f19857c:	00000000 */ 	nop
/*  f198580:	0007000d */ 	break	0x7
.PF0f198584:
/*  f198584:	2401ffff */ 	li	$at,-1
/*  f198588:	14810004 */ 	bne	$a0,$at,.PF0f19859c
/*  f19858c:	3c018000 */ 	lui	$at,0x8000
/*  f198590:	17210002 */ 	bne	$t9,$at,.PF0f19859c
/*  f198594:	00000000 */ 	nop
/*  f198598:	0006000d */ 	break	0x6
.PF0f19859c:
/*  f19859c:	00736021 */ 	addu	$t4,$v1,$s3
/*  f1985a0:	918f004d */ 	lbu	$t7,0x4d($t4)
/*  f1985a4:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f1985a8:	11e00007 */ 	beqz	$t7,.PF0f1985c8
/*  f1985ac:	24090005 */ 	li	$t1,0x5
/*  f1985b0:	006b5021 */ 	addu	$t2,$v1,$t3
/*  f1985b4:	10000004 */ 	b	.PF0f1985c8
/*  f1985b8:	ad49005c */ 	sw	$t1,0x5c($t2)
.PF0f1985bc:
/*  f1985bc:	ae2000c4 */ 	sw	$zero,0xc4($s1)
.PF0f1985c0:
/*  f1985c0:	a1a0004d */ 	sb	$zero,0x4d($t5)
/*  f1985c4:	a72000e0 */ 	sh	$zero,0xe0($t9)
.PF0f1985c8:
/*  f1985c8:	52a00007 */ 	beqzl	$s5,.PF0f1985e8
/*  f1985cc:	02802025 */ 	move	$a0,$s4
/*  f1985d0:	0fc089cc */ 	jal	chrUncloakTemporarily
/*  f1985d4:	02802025 */ 	move	$a0,$s4
/*  f1985d8:	56600003 */ 	bnezl	$s3,.PF0f1985e8
/*  f1985dc:	02802025 */ 	move	$a0,$s4
/*  f1985e0:	afb70088 */ 	sw	$s7,0x88($sp)
/*  f1985e4:	02802025 */ 	move	$a0,$s4
.PF0f1985e8:
/*  f1985e8:	02602825 */ 	move	$a1,$s3
/*  f1985ec:	0fc0fec3 */ 	jal	chrSetHandFiring
/*  f1985f0:	02a03025 */ 	move	$a2,$s5
/*  f1985f4:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f1985f8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f1985fc:	24010002 */ 	li	$at,0x2
/*  f198600:	25cc0004 */ 	addiu	$t4,$t6,0x4
/*  f198604:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f198608:	1661fdcf */ 	bne	$s3,$at,.PF0f197d48
/*  f19860c:	26310004 */ 	addiu	$s1,$s1,0x4
.PF0f198610:
/*  f198610:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f198614:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f198618:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f19861c:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f198620:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f198624:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f198628:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f19862c:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f198630:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f198634:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f198638:	03e00008 */ 	jr	$ra
/*  f19863c:	27bd02f8 */ 	addiu	$sp,$sp,0x2f8
);
#elif VERSION == VERSION_PAL_BETA
GLOBAL_ASM(
glabel botTickUnpaused
.late_rodata
glabel var7f1b8f54
.word 0x49742400
glabel var7f1b8f58
.word botTickUnpaused+0x2398
glabel var7f1b8f5c
.word botTickUnpaused+0x23fc
glabel var7f1b8f60
.word botTickUnpaused+0x23fc
glabel var7f1b8f64
.word botTickUnpaused+0x23fc
glabel var7f1b8f68
.word botTickUnpaused+0x2398
glabel var7f1b8f6c
.word botTickUnpaused+0x2398
glabel var7f1b8f70
.word botTickUnpaused+0x2398
glabel var7f1b8f74
.word botTickUnpaused+0x23fc
glabel var7f1b8f78
.word botTickUnpaused+0x23fc
glabel var7f1b8f7c
.word botTickUnpaused+0x2398
glabel var7f1b8f80
.word botTickUnpaused+0x2398
glabel var7f1b8f84
.word botTickUnpaused+0x2398
glabel var7f1b8f88
.word botTickUnpaused+0x2398
glabel var7f1b8f8c
.word botTickUnpaused+0x2398
glabel var7f1b8f90
.word botTickUnpaused+0x2398
glabel var7f1b8f94
.word botTickUnpaused+0x2398
glabel var7f1b8f98
.word botTickUnpaused+0x2398
glabel var7f1b8f9c
.word botTickUnpaused+0x2398
glabel var7f1b8fa0
.word botTickUnpaused+0x2398
glabel var7f1b8fa4
.word botTickUnpaused+0x2474
glabel var7f1b8fa8
.word botTickUnpaused+0x2398
glabel var7f1b8fac
.word botTickUnpaused+0x2398
glabel var7f1b8fb0
.word botTickUnpaused+0x2398
glabel var7f1b8fb4
.word botTickUnpaused+0x2398
glabel var7f1b8fb8
.word botTickUnpaused+0x2398
glabel var7f1b8fbc
.word botTickUnpaused+0x23fc
glabel var7f1b8fc0
.word botTickUnpaused+0x2398
glabel var7f1b8fc4
.word botTickUnpaused+0x2450
glabel var7f1b8fc8
.word 0x3d4ccccd
.text
/*  f1966e8:	27bdfd08 */ 	addiu	$sp,$sp,-760
/*  f1966ec:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f1966f0:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f1966f4:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f1966f8:	0080a025 */ 	move	$s4,$a0
/*  f1966fc:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f196700:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f196704:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f196708:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f19670c:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f196710:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f196714:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f196718:	0fc0e6e9 */ 	jal	chrIsDead
/*  f19671c:	2415ffff */ 	li	$s5,-1
/*  f196720:	14400a77 */ 	bnez	$v0,.PB0f199100
/*  f196724:	3c16800a */ 	lui	$s6,0x800a
/*  f196728:	8e9202d4 */ 	lw	$s2,0x2d4($s4)
/*  f19672c:	26d6e4d0 */ 	addiu	$s6,$s6,-6960
/*  f196730:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f196734:	8e4e02cc */ 	lw	$t6,0x2cc($s2)
/*  f196738:	01cfc823 */ 	subu	$t9,$t6,$t7
/*  f19673c:	07210017 */ 	bgez	$t9,.PB0f19679c
/*  f196740:	ae5902cc */ 	sw	$t9,0x2cc($s2)
/*  f196744:	0c004be0 */ 	jal	random
/*  f196748:	00000000 */ 	nop
/*  f19674c:	24012ee0 */ 	li	$at,0x2ee0
/*  f196750:	0041001b */ 	divu	$zero,$v0,$at
/*  f196754:	00004810 */ 	mfhi	$t1
/*  f196758:	252a05dc */ 	addiu	$t2,$t1,0x5dc
/*  f19675c:	0c004be0 */ 	jal	random
/*  f196760:	ae4a02cc */ 	sw	$t2,0x2cc($s2)
/*  f196764:	0c004be0 */ 	jal	random
/*  f196768:	ae4202d0 */ 	sw	$v0,0x2d0($s2)
/*  f19676c:	44822000 */ 	mtc1	$v0,$f4
/*  f196770:	3c014f80 */ 	lui	$at,0x4f80
/*  f196774:	04410004 */ 	bgez	$v0,.PB0f196788
/*  f196778:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f19677c:	44814000 */ 	mtc1	$at,$f8
/*  f196780:	00000000 */ 	nop
/*  f196784:	46083180 */ 	add.s	$f6,$f6,$f8
.PB0f196788:
/*  f196788:	3c012f80 */ 	lui	$at,0x2f80
/*  f19678c:	44815000 */ 	mtc1	$at,$f10
/*  f196790:	00000000 */ 	nop
/*  f196794:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f196798:	e65202d4 */ 	swc1	$f18,0x2d4($s2)
.PB0f19679c:
/*  f19679c:	00008025 */ 	move	$s0,$zero
/*  f1967a0:	02403825 */ 	move	$a3,$s2
.PB0f1967a4:
/*  f1967a4:	84e2002c */ 	lh	$v0,0x2c($a3)
/*  f1967a8:	5840000f */ 	blezl	$v0,.PB0f1967e8
/*  f1967ac:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f1967b0:	8ecb0038 */ 	lw	$t3,0x38($s6)
/*  f1967b4:	02802025 */ 	move	$a0,$s4
/*  f1967b8:	004b6023 */ 	subu	$t4,$v0,$t3
/*  f1967bc:	a4ec002c */ 	sh	$t4,0x2c($a3)
/*  f1967c0:	84ed002c */ 	lh	$t5,0x2c($a3)
/*  f1967c4:	5da00037 */ 	bgtzl	$t5,.PB0f1968a4
/*  f1967c8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1967cc:	02002825 */ 	move	$a1,$s0
/*  f1967d0:	24060001 */ 	li	$a2,0x1
/*  f1967d4:	0fc66d88 */ 	jal	botactReload
/*  f1967d8:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f1967dc:	10000030 */ 	b	.PB0f1968a0
/*  f1967e0:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f1967e4:	8e45004c */ 	lw	$a1,0x4c($s2)
.PB0f1967e8:
/*  f1967e8:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1967ec:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f1967f0:	00057080 */ 	sll	$t6,$a1,0x2
/*  f1967f4:	0fc66f9f */ 	jal	botactIsWeaponThrowable
/*  f1967f8:	000e2fc2 */ 	srl	$a1,$t6,0x1f
/*  f1967fc:	14400028 */ 	bnez	$v0,.PB0f1968a0
/*  f196800:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f196804:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f196808:	0010c080 */ 	sll	$t8,$s0,0x2
/*  f19680c:	0258c821 */ 	addu	$t9,$s2,$t8
/*  f196810:	8f230024 */ 	lw	$v1,0x24($t9)
/*  f196814:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f196818:	00054880 */ 	sll	$t1,$a1,0x2
/*  f19681c:	00092fc2 */ 	srl	$a1,$t1,0x1f
/*  f196820:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f196824:	0fc66d76 */ 	jal	botactGetClipCapacityByFunction
/*  f196828:	afa302e8 */ 	sw	$v1,0x2e8($sp)
/*  f19682c:	8fa302e8 */ 	lw	$v1,0x2e8($sp)
/*  f196830:	8fa70054 */ 	lw	$a3,0x54($sp)
/*  f196834:	1c600008 */ 	bgtz	$v1,.PB0f196858
/*  f196838:	00000000 */ 	nop
/*  f19683c:	18400006 */ 	blez	$v0,.PB0f196858
/*  f196840:	02802025 */ 	move	$a0,$s4
/*  f196844:	02002825 */ 	move	$a1,$s0
/*  f196848:	0fc6548f */ 	jal	botScheduleReload
/*  f19684c:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f196850:	10000013 */ 	b	.PB0f1968a0
/*  f196854:	8fa70054 */ 	lw	$a3,0x54($sp)
.PB0f196858:
/*  f196858:	04410003 */ 	bgez	$v0,.PB0f196868
/*  f19685c:	00025843 */ 	sra	$t3,$v0,0x1
/*  f196860:	24410001 */ 	addiu	$at,$v0,0x1
/*  f196864:	00015843 */ 	sra	$t3,$at,0x1
.PB0f196868:
/*  f196868:	006b082a */ 	slt	$at,$v1,$t3
/*  f19686c:	5020000d */ 	beqzl	$at,.PB0f1968a4
/*  f196870:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f196874:	8ecd0008 */ 	lw	$t5,0x8($s6)
/*  f196878:	8e4c0124 */ 	lw	$t4,0x124($s2)
/*  f19687c:	02802025 */ 	move	$a0,$s4
/*  f196880:	25aeff9c */ 	addiu	$t6,$t5,-100
/*  f196884:	018e082a */ 	slt	$at,$t4,$t6
/*  f196888:	50200006 */ 	beqzl	$at,.PB0f1968a4
/*  f19688c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f196890:	02002825 */ 	move	$a1,$s0
/*  f196894:	0fc6548f */ 	jal	botScheduleReload
/*  f196898:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f19689c:	8fa70054 */ 	lw	$a3,0x54($sp)
.PB0f1968a0:
/*  f1968a0:	26100001 */ 	addiu	$s0,$s0,0x1
.PB0f1968a4:
/*  f1968a4:	24010002 */ 	li	$at,0x2
/*  f1968a8:	1601ffbe */ 	bne	$s0,$at,.PB0f1967a4
/*  f1968ac:	24e70002 */ 	addiu	$a3,$a3,0x2
/*  f1968b0:	8e4200cc */ 	lw	$v0,0xcc($s2)
/*  f1968b4:	58400045 */ 	blezl	$v0,.PB0f1969cc
/*  f1968b8:	8e4d0020 */ 	lw	$t5,0x20($s2)
/*  f1968bc:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f1968c0:	02802025 */ 	move	$a0,$s4
/*  f1968c4:	004fc823 */ 	subu	$t9,$v0,$t7
/*  f1968c8:	1f20003f */ 	bgtz	$t9,.PB0f1969c8
/*  f1968cc:	ae5900cc */ 	sw	$t9,0xcc($s2)
/*  f1968d0:	0fc66634 */ 	jal	botinvGetItem
/*  f1968d4:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f1968d8:	00408025 */ 	move	$s0,$v0
/*  f1968dc:	0fc4a7f5 */ 	jal	playermgrGetModelOfWeapon
/*  f1968e0:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f1968e4:	12000019 */ 	beqz	$s0,.PB0f19694c
/*  f1968e8:	00408825 */ 	move	$s1,$v0
/*  f1968ec:	04400017 */ 	bltz	$v0,.PB0f19694c
/*  f1968f0:	02802025 */ 	move	$a0,$s4
/*  f1968f4:	00402825 */ 	move	$a1,$v0
/*  f1968f8:	8e460020 */ 	lw	$a2,0x20($s2)
/*  f1968fc:	0fc22e53 */ 	jal	chrGiveWeapon
/*  f196900:	00003825 */ 	move	$a3,$zero
/*  f196904:	02802025 */ 	move	$a0,$s4
/*  f196908:	00002825 */ 	move	$a1,$zero
/*  f19690c:	0fc66d88 */ 	jal	botactReload
/*  f196910:	00003025 */ 	move	$a2,$zero
/*  f196914:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f196918:	24010003 */ 	li	$at,0x3
/*  f19691c:	02802025 */ 	move	$a0,$s4
/*  f196920:	15210008 */ 	bne	$t1,$at,.PB0f196944
/*  f196924:	02202825 */ 	move	$a1,$s1
/*  f196928:	8e460020 */ 	lw	$a2,0x20($s2)
/*  f19692c:	0fc22e53 */ 	jal	chrGiveWeapon
/*  f196930:	3c071000 */ 	lui	$a3,0x1000
/*  f196934:	02802025 */ 	move	$a0,$s4
/*  f196938:	24050001 */ 	li	$a1,0x1
/*  f19693c:	0fc66d88 */ 	jal	botactReload
/*  f196940:	00003025 */ 	move	$a2,$zero
.PB0f196944:
/*  f196944:	1000000e */ 	b	.PB0f196980
/*  f196948:	ae400034 */ 	sw	$zero,0x34($s2)
.PB0f19694c:
/*  f19694c:	8e8a02d4 */ 	lw	$t2,0x2d4($s4)
/*  f196950:	24170001 */ 	li	$s7,0x1
/*  f196954:	ad570020 */ 	sw	$s7,0x20($t2)
/*  f196958:	8e8302d4 */ 	lw	$v1,0x2d4($s4)
/*  f19695c:	906b004c */ 	lbu	$t3,0x4c($v1)
/*  f196960:	316dffdf */ 	andi	$t5,$t3,0xffdf
/*  f196964:	a06d004c */ 	sb	$t5,0x4c($v1)
/*  f196968:	8e8302d4 */ 	lw	$v1,0x2d4($s4)
/*  f19696c:	906c004c */ 	lbu	$t4,0x4c($v1)
/*  f196970:	318effbf */ 	andi	$t6,$t4,0xffbf
/*  f196974:	35cf0040 */ 	ori	$t7,$t6,0x40
/*  f196978:	a06f004c */ 	sb	$t7,0x4c($v1)
/*  f19697c:	ae400034 */ 	sw	$zero,0x34($s2)
.PB0f196980:
/*  f196980:	02401025 */ 	move	$v0,$s2
/*  f196984:	00001825 */ 	move	$v1,$zero
/*  f196988:	02802025 */ 	move	$a0,$s4
/*  f19698c:	24060008 */ 	li	$a2,0x8
.PB0f196990:
/*  f196990:	a440003c */ 	sh	$zero,0x3c($v0)
/*  f196994:	8c850170 */ 	lw	$a1,0x170($a0)
/*  f196998:	24420002 */ 	addiu	$v0,$v0,0x2
/*  f19699c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1969a0:	10a00007 */ 	beqz	$a1,.PB0f1969c0
/*  f1969a4:	00000000 */ 	nop
/*  f1969a8:	8e9802d4 */ 	lw	$t8,0x2d4($s4)
/*  f1969ac:	8cab0004 */ 	lw	$t3,0x4($a1)
/*  f1969b0:	8f19004c */ 	lw	$t9,0x4c($t8)
/*  f1969b4:	00194880 */ 	sll	$t1,$t9,0x2
/*  f1969b8:	000957c2 */ 	srl	$t2,$t1,0x1f
/*  f1969bc:	a16a005f */ 	sb	$t2,0x5f($t3)
.PB0f1969c0:
/*  f1969c0:	1466fff3 */ 	bne	$v1,$a2,.PB0f196990
/*  f1969c4:	24840004 */ 	addiu	$a0,$a0,0x4
.PB0f1969c8:
/*  f1969c8:	8e4d0020 */ 	lw	$t5,0x20($s2)
.PB0f1969cc:
/*  f1969cc:	2401001d */ 	li	$at,0x1d
/*  f1969d0:	24170001 */ 	li	$s7,0x1
/*  f1969d4:	55a10005 */ 	bnel	$t5,$at,.PB0f1969ec
/*  f1969d8:	8e4f001c */ 	lw	$t7,0x1c($s2)
/*  f1969dc:	8e8e02d4 */ 	lw	$t6,0x2d4($s4)
/*  f1969e0:	240c03e7 */ 	li	$t4,0x3e7
/*  f1969e4:	adcc0024 */ 	sw	$t4,0x24($t6)
/*  f1969e8:	8e4f001c */ 	lw	$t7,0x1c($s2)
.PB0f1969ec:
/*  f1969ec:	8df80050 */ 	lw	$t8,0x50($t7)
/*  f1969f0:	1b00000d */ 	blez	$t8,.PB0f196a28
/*  f1969f4:	02802025 */ 	move	$a0,$s4
/*  f1969f8:	0fc64c78 */ 	jal	botIsAboutToAttack
/*  f1969fc:	02e02825 */ 	move	$a1,$s7
/*  f196a00:	54400006 */ 	bnezl	$v0,.PB0f196a1c
/*  f196a04:	924a004c */ 	lbu	$t2,0x4c($s2)
/*  f196a08:	929902a0 */ 	lbu	$t9,0x2a0($s4)
/*  f196a0c:	2401002e */ 	li	$at,0x2e
/*  f196a10:	57210006 */ 	bnel	$t9,$at,.PB0f196a2c
/*  f196a14:	8e420210 */ 	lw	$v0,0x210($s2)
/*  f196a18:	924a004c */ 	lbu	$t2,0x4c($s2)
.PB0f196a1c:
/*  f196a1c:	354b0002 */ 	ori	$t3,$t2,0x2
/*  f196a20:	1000001e */ 	b	.PB0f196a9c
/*  f196a24:	a24b004c */ 	sb	$t3,0x4c($s2)
.PB0f196a28:
/*  f196a28:	8e420210 */ 	lw	$v0,0x210($s2)
.PB0f196a2c:
/*  f196a2c:	240404b0 */ 	li	$a0,0x4b0
/*  f196a30:	8e4d001c */ 	lw	$t5,0x1c($s2)
/*  f196a34:	00026142 */ 	srl	$t4,$v0,0x5
/*  f196a38:	0184001b */ 	divu	$zero,$t4,$a0
/*  f196a3c:	8da30050 */ 	lw	$v1,0x50($t5)
/*  f196a40:	00007010 */ 	mfhi	$t6
/*  f196a44:	25cf04b0 */ 	addiu	$t7,$t6,0x4b0
/*  f196a48:	14800002 */ 	bnez	$a0,.PB0f196a54
/*  f196a4c:	00000000 */ 	nop
/*  f196a50:	0007000d */ 	break	0x7
.PB0f196a54:
/*  f196a54:	01e3082b */ 	sltu	$at,$t7,$v1
/*  f196a58:	10200005 */ 	beqz	$at,.PB0f196a70
/*  f196a5c:	00025442 */ 	srl	$t2,$v0,0x11
/*  f196a60:	9259004c */ 	lbu	$t9,0x4c($s2)
/*  f196a64:	37290002 */ 	ori	$t1,$t9,0x2
/*  f196a68:	1000000c */ 	b	.PB0f196a9c
/*  f196a6c:	a249004c */ 	sb	$t1,0x4c($s2)
.PB0f196a70:
/*  f196a70:	0144001b */ 	divu	$zero,$t2,$a0
/*  f196a74:	00005810 */ 	mfhi	$t3
/*  f196a78:	0163082b */ 	sltu	$at,$t3,$v1
/*  f196a7c:	14800002 */ 	bnez	$a0,.PB0f196a88
/*  f196a80:	00000000 */ 	nop
/*  f196a84:	0007000d */ 	break	0x7
.PB0f196a88:
/*  f196a88:	54200005 */ 	bnezl	$at,.PB0f196aa0
/*  f196a8c:	8e4e004c */ 	lw	$t6,0x4c($s2)
/*  f196a90:	924d004c */ 	lbu	$t5,0x4c($s2)
/*  f196a94:	31acfffd */ 	andi	$t4,$t5,0xfffd
/*  f196a98:	a24c004c */ 	sb	$t4,0x4c($s2)
.PB0f196a9c:
/*  f196a9c:	8e4e004c */ 	lw	$t6,0x4c($s2)
.PB0f196aa0:
/*  f196aa0:	000ec180 */ 	sll	$t8,$t6,0x6
/*  f196aa4:	07020039 */ 	bltzl	$t8,.PB0f196b8c
/*  f196aa8:	924b009c */ 	lbu	$t3,0x9c($s2)
/*  f196aac:	8e590020 */ 	lw	$t9,0x20($s2)
/*  f196ab0:	2401000d */ 	li	$at,0xd
/*  f196ab4:	02402025 */ 	move	$a0,$s2
/*  f196ab8:	17210033 */ 	bne	$t9,$at,.PB0f196b88
/*  f196abc:	2405000d */ 	li	$a1,0xd
/*  f196ac0:	00003025 */ 	move	$a2,$zero
/*  f196ac4:	0fc66df1 */ 	jal	botactGetAmmoQuantityByWeapon
/*  f196ac8:	02e03825 */ 	move	$a3,$s7
/*  f196acc:	00408025 */ 	move	$s0,$v0
/*  f196ad0:	02802025 */ 	move	$a0,$s4
/*  f196ad4:	0fc64c78 */ 	jal	botIsAboutToAttack
/*  f196ad8:	02e02825 */ 	move	$a1,$s7
/*  f196adc:	5040001a */ 	beqzl	$v0,.PB0f196b48
/*  f196ae0:	8e4b0210 */ 	lw	$t3,0x210($s2)
/*  f196ae4:	8e420210 */ 	lw	$v0,0x210($s2)
/*  f196ae8:	240100c8 */ 	li	$at,0xc8
/*  f196aec:	00024982 */ 	srl	$t1,$v0,0x6
/*  f196af0:	0121001b */ 	divu	$zero,$t1,$at
/*  f196af4:	00005010 */ 	mfhi	$t2
/*  f196af8:	254b00c8 */ 	addiu	$t3,$t2,0xc8
/*  f196afc:	0170082b */ 	sltu	$at,$t3,$s0
/*  f196b00:	10200005 */ 	beqz	$at,.PB0f196b18
/*  f196b04:	00027c02 */ 	srl	$t7,$v0,0x10
/*  f196b08:	924c009c */ 	lbu	$t4,0x9c($s2)
/*  f196b0c:	358e0020 */ 	ori	$t6,$t4,0x20
/*  f196b10:	10000020 */ 	b	.PB0f196b94
/*  f196b14:	a24e009c */ 	sb	$t6,0x9c($s2)
.PB0f196b18:
/*  f196b18:	24010046 */ 	li	$at,0x46
/*  f196b1c:	01e1001b */ 	divu	$zero,$t7,$at
/*  f196b20:	0000c010 */ 	mfhi	$t8
/*  f196b24:	2719001e */ 	addiu	$t9,$t8,0x1e
/*  f196b28:	0330082b */ 	sltu	$at,$t9,$s0
/*  f196b2c:	5420001a */ 	bnezl	$at,.PB0f196b98
/*  f196b30:	8e4c0004 */ 	lw	$t4,0x4($s2)
/*  f196b34:	9249009c */ 	lbu	$t1,0x9c($s2)
/*  f196b38:	312affdf */ 	andi	$t2,$t1,0xffdf
/*  f196b3c:	10000015 */ 	b	.PB0f196b94
/*  f196b40:	a24a009c */ 	sb	$t2,0x9c($s2)
/*  f196b44:	8e4b0210 */ 	lw	$t3,0x210($s2)
.PB0f196b48:
/*  f196b48:	240101f4 */ 	li	$at,0x1f4
/*  f196b4c:	000b6b02 */ 	srl	$t5,$t3,0xc
/*  f196b50:	01a1001b */ 	divu	$zero,$t5,$at
/*  f196b54:	00006010 */ 	mfhi	$t4
/*  f196b58:	258e012c */ 	addiu	$t6,$t4,0x12c
/*  f196b5c:	01d0082b */ 	sltu	$at,$t6,$s0
/*  f196b60:	50200006 */ 	beqzl	$at,.PB0f196b7c
/*  f196b64:	9249009c */ 	lbu	$t1,0x9c($s2)
/*  f196b68:	9258009c */ 	lbu	$t8,0x9c($s2)
/*  f196b6c:	37190020 */ 	ori	$t9,$t8,0x20
/*  f196b70:	10000008 */ 	b	.PB0f196b94
/*  f196b74:	a259009c */ 	sb	$t9,0x9c($s2)
/*  f196b78:	9249009c */ 	lbu	$t1,0x9c($s2)
.PB0f196b7c:
/*  f196b7c:	312affdf */ 	andi	$t2,$t1,0xffdf
/*  f196b80:	10000004 */ 	b	.PB0f196b94
/*  f196b84:	a24a009c */ 	sb	$t2,0x9c($s2)
.PB0f196b88:
/*  f196b88:	924b009c */ 	lbu	$t3,0x9c($s2)
.PB0f196b8c:
/*  f196b8c:	316dffdf */ 	andi	$t5,$t3,0xffdf
/*  f196b90:	a24d009c */ 	sb	$t5,0x9c($s2)
.PB0f196b94:
/*  f196b94:	8e4c0004 */ 	lw	$t4,0x4($s2)
.PB0f196b98:
/*  f196b98:	24010004 */ 	li	$at,0x4
/*  f196b9c:	918e0047 */ 	lbu	$t6,0x47($t4)
/*  f196ba0:	55c1000e */ 	bnel	$t6,$at,.PB0f196bdc
/*  f196ba4:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f196ba8:	868f017e */ 	lh	$t7,0x17e($s4)
/*  f196bac:	241effff */ 	li	$s8,-1
/*  f196bb0:	53cf000a */ 	beql	$s8,$t7,.PB0f196bdc
/*  f196bb4:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f196bb8:	8e580128 */ 	lw	$t8,0x128($s2)
/*  f196bbc:	53000007 */ 	beqzl	$t8,.PB0f196bdc
/*  f196bc0:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f196bc4:	929902a0 */ 	lbu	$t9,0x2a0($s4)
/*  f196bc8:	2401002f */ 	li	$at,0x2f
/*  f196bcc:	53210003 */ 	beql	$t9,$at,.PB0f196bdc
/*  f196bd0:	824a004f */ 	lb	$t2,0x4f($s2)
/*  f196bd4:	ae5700d8 */ 	sw	$s7,0xd8($s2)
/*  f196bd8:	824a004f */ 	lb	$t2,0x4f($s2)
.PB0f196bdc:
/*  f196bdc:	241effff */ 	li	$s8,-1
/*  f196be0:	05430143 */ 	bgezl	$t2,.PB0f1970f0
/*  f196be4:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
/*  f196be8:	8e420118 */ 	lw	$v0,0x118($s2)
/*  f196bec:	18400005 */ 	blez	$v0,.PB0f196c04
/*  f196bf0:	00000000 */ 	nop
/*  f196bf4:	8ecb0038 */ 	lw	$t3,0x38($s6)
/*  f196bf8:	004b6823 */ 	subu	$t5,$v0,$t3
/*  f196bfc:	ae4d0118 */ 	sw	$t5,0x118($s2)
/*  f196c00:	01a01025 */ 	move	$v0,$t5
.PB0f196c04:
/*  f196c04:	5c40013a */ 	bgtzl	$v0,.PB0f1970f0
/*  f196c08:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
/*  f196c0c:	0fc6589f */ 	jal	botGetTeamSize
/*  f196c10:	02802025 */ 	move	$a0,$s4
/*  f196c14:	3c03800b */ 	lui	$v1,0x800b
/*  f196c18:	906311b8 */ 	lbu	$v1,0x11b8($v1)
/*  f196c1c:	00409825 */ 	move	$s3,$v0
/*  f196c20:	02802025 */ 	move	$a0,$s4
/*  f196c24:	16e3001e */ 	bne	$s7,$v1,.PB0f196ca0
/*  f196c28:	24010002 */ 	li	$at,0x2
/*  f196c2c:	2405000b */ 	li	$a1,0xb
/*  f196c30:	0fc658b3 */ 	jal	botGetCountInTeamDoingCommand
/*  f196c34:	00003025 */ 	move	$a2,$zero
/*  f196c38:	18400010 */ 	blez	$v0,.PB0f196c7c
/*  f196c3c:	266c0001 */ 	addiu	$t4,$s3,0x1
/*  f196c40:	05810003 */ 	bgez	$t4,.PB0f196c50
/*  f196c44:	000c7043 */ 	sra	$t6,$t4,0x1
/*  f196c48:	25810001 */ 	addiu	$at,$t4,0x1
/*  f196c4c:	00017043 */ 	sra	$t6,$at,0x1
.PB0f196c50:
/*  f196c50:	004e082a */ 	slt	$at,$v0,$t6
/*  f196c54:	5420000a */ 	bnezl	$at,.PB0f196c80
/*  f196c58:	02802025 */ 	move	$a0,$s4
/*  f196c5c:	0c004be0 */ 	jal	random
/*  f196c60:	00000000 */ 	nop
/*  f196c64:	24010064 */ 	li	$at,0x64
/*  f196c68:	0041001b */ 	divu	$zero,$v0,$at
/*  f196c6c:	00007810 */ 	mfhi	$t7
/*  f196c70:	2de10042 */ 	sltiu	$at,$t7,0x42
/*  f196c74:	10200006 */ 	beqz	$at,.PB0f196c90
/*  f196c78:	02802025 */ 	move	$a0,$s4
.PB0f196c7c:
/*  f196c7c:	02802025 */ 	move	$a0,$s4
.PB0f196c80:
/*  f196c80:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196c84:	2405000b */ 	li	$a1,0xb
/*  f196c88:	10000111 */ 	b	.PB0f1970d0
/*  f196c8c:	00000000 */ 	nop
.PB0f196c90:
/*  f196c90:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196c94:	24050004 */ 	li	$a1,0x4
/*  f196c98:	1000010d */ 	b	.PB0f1970d0
/*  f196c9c:	00000000 */ 	nop
.PB0f196ca0:
/*  f196ca0:	14610022 */ 	bne	$v1,$at,.PB0f196d2c
/*  f196ca4:	02802025 */ 	move	$a0,$s4
/*  f196ca8:	24050005 */ 	li	$a1,0x5
/*  f196cac:	0fc658b3 */ 	jal	botGetCountInTeamDoingCommand
/*  f196cb0:	00003025 */ 	move	$a2,$zero
/*  f196cb4:	8e58004c */ 	lw	$t8,0x4c($s2)
/*  f196cb8:	00184940 */ 	sll	$t1,$t8,0x5
/*  f196cbc:	05220013 */ 	bltzl	$t1,.PB0f196d0c
/*  f196cc0:	02802025 */ 	move	$a0,$s4
/*  f196cc4:	18400010 */ 	blez	$v0,.PB0f196d08
/*  f196cc8:	266a0001 */ 	addiu	$t2,$s3,0x1
/*  f196ccc:	05410003 */ 	bgez	$t2,.PB0f196cdc
/*  f196cd0:	000a5843 */ 	sra	$t3,$t2,0x1
/*  f196cd4:	25410001 */ 	addiu	$at,$t2,0x1
/*  f196cd8:	00015843 */ 	sra	$t3,$at,0x1
.PB0f196cdc:
/*  f196cdc:	004b082a */ 	slt	$at,$v0,$t3
/*  f196ce0:	5420000a */ 	bnezl	$at,.PB0f196d0c
/*  f196ce4:	02802025 */ 	move	$a0,$s4
/*  f196ce8:	0c004be0 */ 	jal	random
/*  f196cec:	00000000 */ 	nop
/*  f196cf0:	24010064 */ 	li	$at,0x64
/*  f196cf4:	0041001b */ 	divu	$zero,$v0,$at
/*  f196cf8:	00006810 */ 	mfhi	$t5
/*  f196cfc:	2da10032 */ 	sltiu	$at,$t5,0x32
/*  f196d00:	10200006 */ 	beqz	$at,.PB0f196d1c
/*  f196d04:	02802025 */ 	move	$a0,$s4
.PB0f196d08:
/*  f196d08:	02802025 */ 	move	$a0,$s4
.PB0f196d0c:
/*  f196d0c:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196d10:	24050005 */ 	li	$a1,0x5
/*  f196d14:	100000ee */ 	b	.PB0f1970d0
/*  f196d18:	00000000 */ 	nop
.PB0f196d1c:
/*  f196d1c:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196d20:	24050004 */ 	li	$a1,0x4
/*  f196d24:	100000ea */ 	b	.PB0f1970d0
/*  f196d28:	00000000 */ 	nop
.PB0f196d2c:
/*  f196d2c:	24010003 */ 	li	$at,0x3
/*  f196d30:	1461001e */ 	bne	$v1,$at,.PB0f196dac
/*  f196d34:	02802025 */ 	move	$a0,$s4
/*  f196d38:	2405000c */ 	li	$a1,0xc
/*  f196d3c:	0fc658b3 */ 	jal	botGetCountInTeamDoingCommand
/*  f196d40:	00003025 */ 	move	$a2,$zero
/*  f196d44:	18400010 */ 	blez	$v0,.PB0f196d88
/*  f196d48:	266c0001 */ 	addiu	$t4,$s3,0x1
/*  f196d4c:	05810003 */ 	bgez	$t4,.PB0f196d5c
/*  f196d50:	000c7043 */ 	sra	$t6,$t4,0x1
/*  f196d54:	25810001 */ 	addiu	$at,$t4,0x1
/*  f196d58:	00017043 */ 	sra	$t6,$at,0x1
.PB0f196d5c:
/*  f196d5c:	004e082a */ 	slt	$at,$v0,$t6
/*  f196d60:	5420000a */ 	bnezl	$at,.PB0f196d8c
/*  f196d64:	02802025 */ 	move	$a0,$s4
/*  f196d68:	0c004be0 */ 	jal	random
/*  f196d6c:	00000000 */ 	nop
/*  f196d70:	24010064 */ 	li	$at,0x64
/*  f196d74:	0041001b */ 	divu	$zero,$v0,$at
/*  f196d78:	00007810 */ 	mfhi	$t7
/*  f196d7c:	2de10032 */ 	sltiu	$at,$t7,0x32
/*  f196d80:	10200006 */ 	beqz	$at,.PB0f196d9c
/*  f196d84:	02802025 */ 	move	$a0,$s4
.PB0f196d88:
/*  f196d88:	02802025 */ 	move	$a0,$s4
.PB0f196d8c:
/*  f196d8c:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196d90:	2405000c */ 	li	$a1,0xc
/*  f196d94:	100000ce */ 	b	.PB0f1970d0
/*  f196d98:	00000000 */ 	nop
.PB0f196d9c:
/*  f196d9c:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196da0:	24050004 */ 	li	$a1,0x4
/*  f196da4:	100000ca */ 	b	.PB0f1970d0
/*  f196da8:	00000000 */ 	nop
.PB0f196dac:
/*  f196dac:	24010004 */ 	li	$at,0x4
/*  f196db0:	54610034 */ 	bnel	$v1,$at,.PB0f196e84
/*  f196db4:	24010005 */ 	li	$at,0x5
/*  f196db8:	0fc6592b */ 	jal	botGetNumTeammatesDefendingHill
/*  f196dbc:	02802025 */ 	move	$a0,$s4
/*  f196dc0:	8e98001c */ 	lw	$t8,0x1c($s4)
/*  f196dc4:	3c09800b */ 	lui	$t1,0x800b
/*  f196dc8:	8529073e */ 	lh	$t1,0x73e($t1)
/*  f196dcc:	87190028 */ 	lh	$t9,0x28($t8)
/*  f196dd0:	00408025 */ 	move	$s0,$v0
/*  f196dd4:	02802025 */ 	move	$a0,$s4
/*  f196dd8:	17290002 */ 	bne	$t9,$t1,.PB0f196de4
/*  f196ddc:	00000000 */ 	nop
/*  f196de0:	2450ffff */ 	addiu	$s0,$v0,-1
.PB0f196de4:
/*  f196de4:	1a000008 */ 	blez	$s0,.PB0f196e08
/*  f196de8:	00000000 */ 	nop
/*  f196dec:	06610003 */ 	bgez	$s3,.PB0f196dfc
/*  f196df0:	00135043 */ 	sra	$t2,$s3,0x1
/*  f196df4:	26610001 */ 	addiu	$at,$s3,0x1
/*  f196df8:	00015043 */ 	sra	$t2,$at,0x1
.PB0f196dfc:
/*  f196dfc:	020a082a */ 	slt	$at,$s0,$t2
/*  f196e00:	10200005 */ 	beqz	$at,.PB0f196e18
/*  f196e04:	00000000 */ 	nop
.PB0f196e08:
/*  f196e08:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196e0c:	2405000a */ 	li	$a1,0xa
/*  f196e10:	100000af */ 	b	.PB0f1970d0
/*  f196e14:	00000000 */ 	nop
.PB0f196e18:
/*  f196e18:	0fc6594e */ 	jal	botGetNumOpponentsInHill
/*  f196e1c:	02802025 */ 	move	$a0,$s4
/*  f196e20:	0050082a */ 	slt	$at,$v0,$s0
/*  f196e24:	10200012 */ 	beqz	$at,.PB0f196e70
/*  f196e28:	02802025 */ 	move	$a0,$s4
/*  f196e2c:	0c004be0 */ 	jal	random
/*  f196e30:	00000000 */ 	nop
/*  f196e34:	24010064 */ 	li	$at,0x64
/*  f196e38:	0041001b */ 	divu	$zero,$v0,$at
/*  f196e3c:	00005810 */ 	mfhi	$t3
/*  f196e40:	2d610032 */ 	sltiu	$at,$t3,0x32
/*  f196e44:	10200006 */ 	beqz	$at,.PB0f196e60
/*  f196e48:	02802025 */ 	move	$a0,$s4
/*  f196e4c:	02802025 */ 	move	$a0,$s4
/*  f196e50:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196e54:	24050009 */ 	li	$a1,0x9
/*  f196e58:	1000009d */ 	b	.PB0f1970d0
/*  f196e5c:	00000000 */ 	nop
.PB0f196e60:
/*  f196e60:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196e64:	24050004 */ 	li	$a1,0x4
/*  f196e68:	10000099 */ 	b	.PB0f1970d0
/*  f196e6c:	00000000 */ 	nop
.PB0f196e70:
/*  f196e70:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196e74:	2405000a */ 	li	$a1,0xa
/*  f196e78:	10000095 */ 	b	.PB0f1970d0
/*  f196e7c:	00000000 */ 	nop
/*  f196e80:	24010005 */ 	li	$at,0x5
.PB0f196e84:
/*  f196e84:	14610092 */ 	bne	$v1,$at,.PB0f1970d0
/*  f196e88:	00000000 */ 	nop
/*  f196e8c:	14570035 */ 	bne	$v0,$s7,.PB0f196f64
/*  f196e90:	02802025 */ 	move	$a0,$s4
/*  f196e94:	02802025 */ 	move	$a0,$s4
/*  f196e98:	24050006 */ 	li	$a1,0x6
/*  f196e9c:	0fc658b3 */ 	jal	botGetCountInTeamDoingCommand
/*  f196ea0:	02e03025 */ 	move	$a2,$s7
/*  f196ea4:	00408025 */ 	move	$s0,$v0
/*  f196ea8:	0fc65911 */ 	jal	botShouldReturnCtcToken
/*  f196eac:	02802025 */ 	move	$a0,$s4
/*  f196eb0:	10400005 */ 	beqz	$v0,.PB0f196ec8
/*  f196eb4:	02802025 */ 	move	$a0,$s4
/*  f196eb8:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196ebc:	24050006 */ 	li	$a1,0x6
/*  f196ec0:	10000083 */ 	b	.PB0f1970d0
/*  f196ec4:	00000000 */ 	nop
.PB0f196ec8:
/*  f196ec8:	0fc658f7 */ 	jal	botIsChrsCtcTokenHeld
/*  f196ecc:	02802025 */ 	move	$a0,$s4
/*  f196ed0:	10400012 */ 	beqz	$v0,.PB0f196f1c
/*  f196ed4:	00000000 */ 	nop
/*  f196ed8:	0c004be0 */ 	jal	random
/*  f196edc:	00000000 */ 	nop
/*  f196ee0:	24010064 */ 	li	$at,0x64
/*  f196ee4:	0041001b */ 	divu	$zero,$v0,$at
/*  f196ee8:	00006810 */ 	mfhi	$t5
/*  f196eec:	2da1001e */ 	sltiu	$at,$t5,0x1e
/*  f196ef0:	10200006 */ 	beqz	$at,.PB0f196f0c
/*  f196ef4:	02802025 */ 	move	$a0,$s4
/*  f196ef8:	02802025 */ 	move	$a0,$s4
/*  f196efc:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196f00:	24050006 */ 	li	$a1,0x6
/*  f196f04:	10000072 */ 	b	.PB0f1970d0
/*  f196f08:	00000000 */ 	nop
.PB0f196f0c:
/*  f196f0c:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196f10:	24050008 */ 	li	$a1,0x8
/*  f196f14:	1000006e */ 	b	.PB0f1970d0
/*  f196f18:	00000000 */ 	nop
.PB0f196f1c:
/*  f196f1c:	0c004be0 */ 	jal	random
/*  f196f20:	00000000 */ 	nop
/*  f196f24:	24010064 */ 	li	$at,0x64
/*  f196f28:	0041001b */ 	divu	$zero,$v0,$at
/*  f196f2c:	00006010 */ 	mfhi	$t4
/*  f196f30:	2d810046 */ 	sltiu	$at,$t4,0x46
/*  f196f34:	14200003 */ 	bnez	$at,.PB0f196f44
/*  f196f38:	02802025 */ 	move	$a0,$s4
/*  f196f3c:	1e000005 */ 	bgtz	$s0,.PB0f196f54
/*  f196f40:	24050008 */ 	li	$a1,0x8
.PB0f196f44:
/*  f196f44:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196f48:	24050006 */ 	li	$a1,0x6
/*  f196f4c:	10000060 */ 	b	.PB0f1970d0
/*  f196f50:	00000000 */ 	nop
.PB0f196f54:
/*  f196f54:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196f58:	02802025 */ 	move	$a0,$s4
/*  f196f5c:	1000005c */ 	b	.PB0f1970d0
/*  f196f60:	00000000 */ 	nop
.PB0f196f64:
/*  f196f64:	24050006 */ 	li	$a1,0x6
/*  f196f68:	0fc658b3 */ 	jal	botGetCountInTeamDoingCommand
/*  f196f6c:	00003025 */ 	move	$a2,$zero
/*  f196f70:	00408825 */ 	move	$s1,$v0
/*  f196f74:	02802025 */ 	move	$a0,$s4
/*  f196f78:	24050008 */ 	li	$a1,0x8
/*  f196f7c:	0fc658b3 */ 	jal	botGetCountInTeamDoingCommand
/*  f196f80:	00003025 */ 	move	$a2,$zero
/*  f196f84:	00408025 */ 	move	$s0,$v0
/*  f196f88:	0fc65911 */ 	jal	botShouldReturnCtcToken
/*  f196f8c:	02802025 */ 	move	$a0,$s4
/*  f196f90:	10400005 */ 	beqz	$v0,.PB0f196fa8
/*  f196f94:	02802025 */ 	move	$a0,$s4
/*  f196f98:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196f9c:	24050006 */ 	li	$a1,0x6
/*  f196fa0:	1000004b */ 	b	.PB0f1970d0
/*  f196fa4:	00000000 */ 	nop
.PB0f196fa8:
/*  f196fa8:	0fc658f7 */ 	jal	botIsChrsCtcTokenHeld
/*  f196fac:	02802025 */ 	move	$a0,$s4
/*  f196fb0:	10400014 */ 	beqz	$v0,.PB0f197004
/*  f196fb4:	00000000 */ 	nop
/*  f196fb8:	5a00000a */ 	blezl	$s0,.PB0f196fe4
/*  f196fbc:	02802025 */ 	move	$a0,$s4
/*  f196fc0:	0c004be0 */ 	jal	random
/*  f196fc4:	00000000 */ 	nop
/*  f196fc8:	24010064 */ 	li	$at,0x64
/*  f196fcc:	0041001b */ 	divu	$zero,$v0,$at
/*  f196fd0:	00007010 */ 	mfhi	$t6
/*  f196fd4:	2dc10046 */ 	sltiu	$at,$t6,0x46
/*  f196fd8:	10200006 */ 	beqz	$at,.PB0f196ff4
/*  f196fdc:	02802025 */ 	move	$a0,$s4
/*  f196fe0:	02802025 */ 	move	$a0,$s4
.PB0f196fe4:
/*  f196fe4:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196fe8:	24050008 */ 	li	$a1,0x8
/*  f196fec:	10000038 */ 	b	.PB0f1970d0
/*  f196ff0:	00000000 */ 	nop
.PB0f196ff4:
/*  f196ff4:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f196ff8:	24050006 */ 	li	$a1,0x6
/*  f196ffc:	10000034 */ 	b	.PB0f1970d0
/*  f197000:	00000000 */ 	nop
.PB0f197004:
/*  f197004:	1a200005 */ 	blez	$s1,.PB0f19701c
/*  f197008:	24010003 */ 	li	$at,0x3
/*  f19700c:	0261001a */ 	div	$zero,$s3,$at
/*  f197010:	00007812 */ 	mflo	$t7
/*  f197014:	022f082a */ 	slt	$at,$s1,$t7
/*  f197018:	10200005 */ 	beqz	$at,.PB0f197030
.PB0f19701c:
/*  f19701c:	02802025 */ 	move	$a0,$s4
/*  f197020:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f197024:	24050006 */ 	li	$a1,0x6
/*  f197028:	10000029 */ 	b	.PB0f1970d0
/*  f19702c:	00000000 */ 	nop
.PB0f197030:
/*  f197030:	1a000008 */ 	blez	$s0,.PB0f197054
/*  f197034:	02802025 */ 	move	$a0,$s4
/*  f197038:	06610003 */ 	bgez	$s3,.PB0f197048
/*  f19703c:	0013c083 */ 	sra	$t8,$s3,0x2
/*  f197040:	26610003 */ 	addiu	$at,$s3,0x3
/*  f197044:	0001c083 */ 	sra	$t8,$at,0x2
.PB0f197048:
/*  f197048:	0218082a */ 	slt	$at,$s0,$t8
/*  f19704c:	10200005 */ 	beqz	$at,.PB0f197064
/*  f197050:	00000000 */ 	nop
.PB0f197054:
/*  f197054:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f197058:	24050008 */ 	li	$a1,0x8
/*  f19705c:	1000001c */ 	b	.PB0f1970d0
/*  f197060:	00000000 */ 	nop
.PB0f197064:
/*  f197064:	0c004be0 */ 	jal	random
/*  f197068:	00000000 */ 	nop
/*  f19706c:	24010064 */ 	li	$at,0x64
/*  f197070:	0041001b */ 	divu	$zero,$v0,$at
/*  f197074:	0000c810 */ 	mfhi	$t9
/*  f197078:	2f21001e */ 	sltiu	$at,$t9,0x1e
/*  f19707c:	10200005 */ 	beqz	$at,.PB0f197094
/*  f197080:	02802025 */ 	move	$a0,$s4
/*  f197084:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f197088:	24050006 */ 	li	$a1,0x6
/*  f19708c:	10000010 */ 	b	.PB0f1970d0
/*  f197090:	00000000 */ 	nop
.PB0f197094:
/*  f197094:	0c004be0 */ 	jal	random
/*  f197098:	00000000 */ 	nop
/*  f19709c:	24010064 */ 	li	$at,0x64
/*  f1970a0:	0041001b */ 	divu	$zero,$v0,$at
/*  f1970a4:	00004810 */ 	mfhi	$t1
/*  f1970a8:	2d21001e */ 	sltiu	$at,$t1,0x1e
/*  f1970ac:	10200006 */ 	beqz	$at,.PB0f1970c8
/*  f1970b0:	02802025 */ 	move	$a0,$s4
/*  f1970b4:	02802025 */ 	move	$a0,$s4
/*  f1970b8:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f1970bc:	24050008 */ 	li	$a1,0x8
/*  f1970c0:	10000003 */ 	b	.PB0f1970d0
/*  f1970c4:	00000000 */ 	nop
.PB0f1970c8:
/*  f1970c8:	0fc6506e */ 	jal	botApplyScenarioCommand
/*  f1970cc:	24050004 */ 	li	$a1,0x4
.PB0f1970d0:
/*  f1970d0:	0c004be0 */ 	jal	random
/*  f1970d4:	00000000 */ 	nop
/*  f1970d8:	240107d0 */ 	li	$at,0x7d0
/*  f1970dc:	0041001b */ 	divu	$zero,$v0,$at
/*  f1970e0:	00005010 */ 	mfhi	$t2
/*  f1970e4:	254b03e8 */ 	addiu	$t3,$t2,0x3e8
/*  f1970e8:	ae4b0118 */ 	sw	$t3,0x118($s2)
/*  f1970ec:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
.PB0f1970f0:
/*  f1970f0:	24010029 */ 	li	$at,0x29
/*  f1970f4:	51a10005 */ 	beql	$t5,$at,.PB0f19710c
/*  f1970f8:	8e4e0004 */ 	lw	$t6,0x4($s2)
/*  f1970fc:	8e4c00d8 */ 	lw	$t4,0xd8($s2)
/*  f197100:	1180039a */ 	beqz	$t4,.PB0f197f6c
/*  f197104:	00000000 */ 	nop
/*  f197108:	8e4e0004 */ 	lw	$t6,0x4($s2)
.PB0f19710c:
/*  f19710c:	ae4000d8 */ 	sw	$zero,0xd8($s2)
/*  f197110:	a65e0008 */ 	sh	$s8,0x8($s2)
/*  f197114:	91cf0047 */ 	lbu	$t7,0x47($t6)
/*  f197118:	24010004 */ 	li	$at,0x4
/*  f19711c:	15e1000e */ 	bne	$t7,$at,.PB0f197158
/*  f197120:	00000000 */ 	nop
/*  f197124:	8698017e */ 	lh	$t8,0x17e($s4)
/*  f197128:	13d8000b */ 	beq	$s8,$t8,.PB0f197158
/*  f19712c:	00000000 */ 	nop
/*  f197130:	8e590128 */ 	lw	$t9,0x128($s2)
/*  f197134:	02802025 */ 	move	$a0,$s4
/*  f197138:	13200007 */ 	beqz	$t9,.PB0f197158
/*  f19713c:	00000000 */ 	nop
/*  f197140:	0fc0a255 */ 	jal	chrGetTargetProp
/*  f197144:	2415002f */ 	li	$s5,0x2f
/*  f197148:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f19714c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f197150:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f197154:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PB0f197158:
/*  f197158:	06a10006 */ 	bgez	$s5,.PB0f197174
/*  f19715c:	00000000 */ 	nop
/*  f197160:	0fc6588f */ 	jal	botFindDefaultPickup
/*  f197164:	02802025 */ 	move	$a0,$s4
/*  f197168:	10400002 */ 	beqz	$v0,.PB0f197174
/*  f19716c:	ae420010 */ 	sw	$v0,0x10($s2)
/*  f197170:	2415002a */ 	li	$s5,0x2a
.PB0f197174:
/*  f197174:	06a10240 */ 	bgez	$s5,.PB0f197a78
/*  f197178:	00000000 */ 	nop
/*  f19717c:	92420079 */ 	lbu	$v0,0x79($s2)
/*  f197180:	16e20019 */ 	bne	$s7,$v0,.PB0f1971e8
/*  f197184:	00000000 */ 	nop
/*  f197188:	8e4900c0 */ 	lw	$t1,0xc0($s2)
/*  f19718c:	8ecb0338 */ 	lw	$t3,0x338($s6)
/*  f197190:	000950c0 */ 	sll	$t2,$t1,0x3
/*  f197194:	01495021 */ 	addu	$t2,$t2,$t1
/*  f197198:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f19719c:	014b6821 */ 	addu	$t5,$t2,$t3
/*  f1971a0:	8db00004 */ 	lw	$s0,0x4($t5)
/*  f1971a4:	0fc0e6e9 */ 	jal	chrIsDead
/*  f1971a8:	02002025 */ 	move	$a0,$s0
/*  f1971ac:	14400232 */ 	bnez	$v0,.PB0f197a78
/*  f1971b0:	02802025 */ 	move	$a0,$s4
/*  f1971b4:	0fc6513d */ 	jal	botIsTargetInvisible
/*  f1971b8:	02002825 */ 	move	$a1,$s0
/*  f1971bc:	1440022e */ 	bnez	$v0,.PB0f197a78
/*  f1971c0:	02802025 */ 	move	$a0,$s4
/*  f1971c4:	0fc65258 */ 	jal	botPassesCowardCheck
/*  f1971c8:	02002825 */ 	move	$a1,$s0
/*  f1971cc:	1040022a */ 	beqz	$v0,.PB0f197a78
/*  f1971d0:	02002025 */ 	move	$a0,$s0
/*  f1971d4:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f1971d8:	2415002f */ 	li	$s5,0x2f
/*  f1971dc:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f1971e0:	10000225 */ 	b	.PB0f197a78
/*  f1971e4:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PB0f1971e8:
/*  f1971e8:	1440000d */ 	bnez	$v0,.PB0f197220
/*  f1971ec:	2401000d */ 	li	$at,0xd
/*  f1971f0:	8e4c00d4 */ 	lw	$t4,0xd4($s2)
/*  f1971f4:	ae5701e0 */ 	sw	$s7,0x1e0($s2)
/*  f1971f8:	8ecf0338 */ 	lw	$t7,0x338($s6)
/*  f1971fc:	000c70c0 */ 	sll	$t6,$t4,0x3
/*  f197200:	01cc7021 */ 	addu	$t6,$t6,$t4
/*  f197204:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f197208:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f19720c:	24150032 */ 	li	$s5,0x32
/*  f197210:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f197214:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f197218:	10000217 */ 	b	.PB0f197a78
/*  f19721c:	a642000a */ 	sh	$v0,0xa($s2)
.PB0f197220:
/*  f197220:	5441000e */ 	bnel	$v0,$at,.PB0f19725c
/*  f197224:	24010002 */ 	li	$at,0x2
/*  f197228:	8e5900d4 */ 	lw	$t9,0xd4($s2)
/*  f19722c:	ae4001e0 */ 	sw	$zero,0x1e0($s2)
/*  f197230:	8eca0338 */ 	lw	$t2,0x338($s6)
/*  f197234:	001948c0 */ 	sll	$t1,$t9,0x3
/*  f197238:	01394821 */ 	addu	$t1,$t1,$t9
/*  f19723c:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f197240:	012a5821 */ 	addu	$t3,$t1,$t2
/*  f197244:	24150032 */ 	li	$s5,0x32
/*  f197248:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f19724c:	8d640004 */ 	lw	$a0,0x4($t3)
/*  f197250:	10000209 */ 	b	.PB0f197a78
/*  f197254:	a642000a */ 	sh	$v0,0xa($s2)
/*  f197258:	24010002 */ 	li	$at,0x2
.PB0f19725c:
/*  f19725c:	54410005 */ 	bnel	$v0,$at,.PB0f197274
/*  f197260:	24010003 */ 	li	$at,0x3
/*  f197264:	24150033 */ 	li	$s5,0x33
/*  f197268:	10000203 */ 	b	.PB0f197a78
/*  f19726c:	ae5701dc */ 	sw	$s7,0x1dc($s2)
/*  f197270:	24010003 */ 	li	$at,0x3
.PB0f197274:
/*  f197274:	54410005 */ 	bnel	$v0,$at,.PB0f19728c
/*  f197278:	24010006 */ 	li	$at,0x6
/*  f19727c:	24150033 */ 	li	$s5,0x33
/*  f197280:	100001fd */ 	b	.PB0f197a78
/*  f197284:	ae4001dc */ 	sw	$zero,0x1dc($s2)
/*  f197288:	24010006 */ 	li	$at,0x6
.PB0f19728c:
/*  f19728c:	14410089 */ 	bne	$v0,$at,.PB0f1974b4
/*  f197290:	3c0d800b */ 	lui	$t5,0x800b
/*  f197294:	91ad11b8 */ 	lbu	$t5,0x11b8($t5)
/*  f197298:	24010005 */ 	li	$at,0x5
/*  f19729c:	15a10083 */ 	bne	$t5,$at,.PB0f1974ac
/*  f1972a0:	00000000 */ 	nop
/*  f1972a4:	8e4c009c */ 	lw	$t4,0x9c($s2)
/*  f1972a8:	000c7840 */ 	sll	$t7,$t4,0x1
/*  f1972ac:	05e0007f */ 	bltz	$t7,.PB0f1974ac
/*  f1972b0:	00000000 */ 	nop
/*  f1972b4:	0fc6414a */ 	jal	radarGetTeamIndex
/*  f1972b8:	92840125 */ 	lbu	$a0,0x125($s4)
/*  f1972bc:	3c07800b */ 	lui	$a3,0x800b
/*  f1972c0:	00003025 */ 	move	$a2,$zero
/*  f1972c4:	24e70730 */ 	addiu	$a3,$a3,0x730
/*  f1972c8:	00002825 */ 	move	$a1,$zero
/*  f1972cc:	27b00298 */ 	addiu	$s0,$sp,0x298
/*  f1972d0:	24080003 */ 	li	$t0,0x3
.PB0f1972d4:
/*  f1972d4:	10a20020 */ 	beq	$a1,$v0,.PB0f197358
/*  f1972d8:	0005c040 */ 	sll	$t8,$a1,0x1
/*  f1972dc:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f1972e0:	87290000 */ 	lh	$t1,0x0($t9)
/*  f1972e4:	00055080 */ 	sll	$t2,$a1,0x2
/*  f1972e8:	00ea5821 */ 	addu	$t3,$a3,$t2
/*  f1972ec:	5120001b */ 	beqzl	$t1,.PB0f19735c
/*  f1972f0:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f1972f4:	8d640058 */ 	lw	$a0,0x58($t3)
/*  f1972f8:	24010004 */ 	li	$at,0x4
/*  f1972fc:	00066880 */ 	sll	$t5,$a2,0x2
/*  f197300:	90830000 */ 	lbu	$v1,0x0($a0)
/*  f197304:	020d6021 */ 	addu	$t4,$s0,$t5
/*  f197308:	50610004 */ 	beql	$v1,$at,.PB0f19731c
/*  f19730c:	ad840000 */ 	sw	$a0,0x0($t4)
/*  f197310:	16e30004 */ 	bne	$s7,$v1,.PB0f197324
/*  f197314:	00000000 */ 	nop
/*  f197318:	ad840000 */ 	sw	$a0,0x0($t4)
.PB0f19731c:
/*  f19731c:	1000000e */ 	b	.PB0f197358
/*  f197320:	24c60001 */ 	addiu	$a2,$a2,0x1
.PB0f197324:
/*  f197324:	11030003 */ 	beq	$t0,$v1,.PB0f197334
/*  f197328:	24010006 */ 	li	$at,0x6
/*  f19732c:	5461000b */ 	bnel	$v1,$at,.PB0f19735c
/*  f197330:	24a50001 */ 	addiu	$a1,$a1,0x1
.PB0f197334:
/*  f197334:	8c830004 */ 	lw	$v1,0x4($a0)
/*  f197338:	928e0125 */ 	lbu	$t6,0x125($s4)
/*  f19733c:	0006c080 */ 	sll	$t8,$a2,0x2
/*  f197340:	906f0125 */ 	lbu	$t7,0x125($v1)
/*  f197344:	0218c821 */ 	addu	$t9,$s0,$t8
/*  f197348:	55cf0004 */ 	bnel	$t6,$t7,.PB0f19735c
/*  f19734c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f197350:	af240000 */ 	sw	$a0,0x0($t9)
/*  f197354:	24c60001 */ 	addiu	$a2,$a2,0x1
.PB0f197358:
/*  f197358:	24a50001 */ 	addiu	$a1,$a1,0x1
.PB0f19735c:
/*  f19735c:	24010004 */ 	li	$at,0x4
/*  f197360:	14a1ffdc */ 	bne	$a1,$at,.PB0f1972d4
/*  f197364:	00000000 */ 	nop
/*  f197368:	18c00050 */ 	blez	$a2,.PB0f1974ac
/*  f19736c:	00000000 */ 	nop
/*  f197370:	0c004be0 */ 	jal	random
/*  f197374:	afa60294 */ 	sw	$a2,0x294($sp)
/*  f197378:	8fa60294 */ 	lw	$a2,0x294($sp)
/*  f19737c:	0046001b */ 	divu	$zero,$v0,$a2
/*  f197380:	00002010 */ 	mfhi	$a0
/*  f197384:	24890001 */ 	addiu	$t1,$a0,0x1
/*  f197388:	00808825 */ 	move	$s1,$a0
/*  f19738c:	0126001a */ 	div	$zero,$t1,$a2
/*  f197390:	00001810 */ 	mfhi	$v1
/*  f197394:	14c00002 */ 	bnez	$a2,.PB0f1973a0
/*  f197398:	00000000 */ 	nop
/*  f19739c:	0007000d */ 	break	0x7
.PB0f1973a0:
/*  f1973a0:	14c00002 */ 	bnez	$a2,.PB0f1973ac
/*  f1973a4:	00000000 */ 	nop
/*  f1973a8:	0007000d */ 	break	0x7
.PB0f1973ac:
/*  f1973ac:	2401ffff */ 	li	$at,-1
/*  f1973b0:	14c10004 */ 	bne	$a2,$at,.PB0f1973c4
/*  f1973b4:	3c018000 */ 	lui	$at,0x8000
/*  f1973b8:	15210002 */ 	bne	$t1,$at,.PB0f1973c4
/*  f1973bc:	00000000 */ 	nop
/*  f1973c0:	0006000d */ 	break	0x6
.PB0f1973c4:
/*  f1973c4:	00035080 */ 	sll	$t2,$v1,0x2
.PB0f1973c8:
/*  f1973c8:	020a5821 */ 	addu	$t3,$s0,$t2
/*  f1973cc:	8d650000 */ 	lw	$a1,0x0($t3)
/*  f1973d0:	afa60294 */ 	sw	$a2,0x294($sp)
/*  f1973d4:	afa30288 */ 	sw	$v1,0x288($sp)
/*  f1973d8:	02802025 */ 	move	$a0,$s4
/*  f1973dc:	0fc1259e */ 	jal	chrGetSquaredDistanceToCoord
/*  f1973e0:	24a50008 */ 	addiu	$a1,$a1,0x8
/*  f1973e4:	3c017f1c */ 	lui	$at,0x7f1c
/*  f1973e8:	c424b2f4 */ 	lwc1	$f4,-0x4d0c($at)
/*  f1973ec:	8fa30288 */ 	lw	$v1,0x288($sp)
/*  f1973f0:	8fa60294 */ 	lw	$a2,0x294($sp)
/*  f1973f4:	4604003c */ 	c.lt.s	$f0,$f4
/*  f1973f8:	246d0001 */ 	addiu	$t5,$v1,0x1
/*  f1973fc:	45000003 */ 	bc1f	.PB0f19740c
/*  f197400:	00000000 */ 	nop
/*  f197404:	10000010 */ 	b	.PB0f197448
/*  f197408:	00608825 */ 	move	$s1,$v1
.PB0f19740c:
/*  f19740c:	5071000f */ 	beql	$v1,$s1,.PB0f19744c
/*  f197410:	00116080 */ 	sll	$t4,$s1,0x2
/*  f197414:	01a6001a */ 	div	$zero,$t5,$a2
/*  f197418:	00001810 */ 	mfhi	$v1
/*  f19741c:	14c00002 */ 	bnez	$a2,.PB0f197428
/*  f197420:	00000000 */ 	nop
/*  f197424:	0007000d */ 	break	0x7
.PB0f197428:
/*  f197428:	2401ffff */ 	li	$at,-1
/*  f19742c:	14c10004 */ 	bne	$a2,$at,.PB0f197440
/*  f197430:	3c018000 */ 	lui	$at,0x8000
/*  f197434:	15a10002 */ 	bne	$t5,$at,.PB0f197440
/*  f197438:	00000000 */ 	nop
/*  f19743c:	0006000d */ 	break	0x6
.PB0f197440:
/*  f197440:	1000ffe1 */ 	b	.PB0f1973c8
/*  f197444:	00035080 */ 	sll	$t2,$v1,0x2
.PB0f197448:
/*  f197448:	00116080 */ 	sll	$t4,$s1,0x2
.PB0f19744c:
/*  f19744c:	020c9821 */ 	addu	$s3,$s0,$t4
/*  f197450:	8e620000 */ 	lw	$v0,0x0($s3)
/*  f197454:	24010004 */ 	li	$at,0x4
/*  f197458:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f19745c:	50610004 */ 	beql	$v1,$at,.PB0f197470
/*  f197460:	2415002a */ 	li	$s5,0x2a
/*  f197464:	16e30004 */ 	bne	$s7,$v1,.PB0f197478
/*  f197468:	02802025 */ 	move	$a0,$s4
/*  f19746c:	2415002a */ 	li	$s5,0x2a
.PB0f197470:
/*  f197470:	10000181 */ 	b	.PB0f197a78
/*  f197474:	ae420010 */ 	sw	$v0,0x10($s2)
.PB0f197478:
/*  f197478:	0fc6541f */ 	jal	botCanFollow
/*  f19747c:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f197480:	1040000a */ 	beqz	$v0,.PB0f1974ac
/*  f197484:	00000000 */ 	nop
/*  f197488:	0c004be0 */ 	jal	random
/*  f19748c:	24150032 */ 	li	$s5,0x32
/*  f197490:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f197494:	2dcf0001 */ 	sltiu	$t7,$t6,0x1
/*  f197498:	ae4f01e0 */ 	sw	$t7,0x1e0($s2)
/*  f19749c:	8e780000 */ 	lw	$t8,0x0($s3)
/*  f1974a0:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f1974a4:	8f040004 */ 	lw	$a0,0x4($t8)
/*  f1974a8:	a642000a */ 	sh	$v0,0xa($s2)
.PB0f1974ac:
/*  f1974ac:	10000172 */ 	b	.PB0f197a78
/*  f1974b0:	00000000 */ 	nop
.PB0f1974b4:
/*  f1974b4:	24010008 */ 	li	$at,0x8
/*  f1974b8:	14410043 */ 	bne	$v0,$at,.PB0f1975c8
/*  f1974bc:	3c19800b */ 	lui	$t9,0x800b
/*  f1974c0:	933911b8 */ 	lbu	$t9,0x11b8($t9)
/*  f1974c4:	24010005 */ 	li	$at,0x5
/*  f1974c8:	1721016b */ 	bne	$t9,$at,.PB0f197a78
/*  f1974cc:	00000000 */ 	nop
/*  f1974d0:	0fc6414a */ 	jal	radarGetTeamIndex
/*  f1974d4:	92840125 */ 	lbu	$a0,0x125($s4)
/*  f1974d8:	00024880 */ 	sll	$t1,$v0,0x2
/*  f1974dc:	3c03800b */ 	lui	$v1,0x800b
/*  f1974e0:	00691821 */ 	addu	$v1,$v1,$t1
/*  f1974e4:	8c630788 */ 	lw	$v1,0x788($v1)
/*  f1974e8:	24010003 */ 	li	$at,0x3
/*  f1974ec:	90640000 */ 	lbu	$a0,0x0($v1)
/*  f1974f0:	10810003 */ 	beq	$a0,$at,.PB0f197500
/*  f1974f4:	24010006 */ 	li	$at,0x6
/*  f1974f8:	54810026 */ 	bnel	$a0,$at,.PB0f197594
/*  f1974fc:	c4680008 */ 	lwc1	$f8,0x8($v1)
.PB0f197500:
/*  f197500:	8c700004 */ 	lw	$s0,0x4($v1)
/*  f197504:	928a0125 */ 	lbu	$t2,0x125($s4)
/*  f197508:	02802025 */ 	move	$a0,$s4
/*  f19750c:	920b0125 */ 	lbu	$t3,0x125($s0)
/*  f197510:	154b000e */ 	bne	$t2,$t3,.PB0f19754c
/*  f197514:	00000000 */ 	nop
/*  f197518:	0fc6541f */ 	jal	botCanFollow
/*  f19751c:	02002825 */ 	move	$a1,$s0
/*  f197520:	10400155 */ 	beqz	$v0,.PB0f197a78
/*  f197524:	00000000 */ 	nop
/*  f197528:	0c004be0 */ 	jal	random
/*  f19752c:	24150032 */ 	li	$s5,0x32
/*  f197530:	304d0003 */ 	andi	$t5,$v0,0x3
/*  f197534:	2dac0001 */ 	sltiu	$t4,$t5,0x1
/*  f197538:	ae4c01e0 */ 	sw	$t4,0x1e0($s2)
/*  f19753c:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f197540:	02002025 */ 	move	$a0,$s0
/*  f197544:	1000014c */ 	b	.PB0f197a78
/*  f197548:	a642000a */ 	sh	$v0,0xa($s2)
.PB0f19754c:
/*  f19754c:	0fc0e6e9 */ 	jal	chrIsDead
/*  f197550:	02002025 */ 	move	$a0,$s0
/*  f197554:	14400148 */ 	bnez	$v0,.PB0f197a78
/*  f197558:	02802025 */ 	move	$a0,$s4
/*  f19755c:	0fc6513d */ 	jal	botIsTargetInvisible
/*  f197560:	02002825 */ 	move	$a1,$s0
/*  f197564:	14400144 */ 	bnez	$v0,.PB0f197a78
/*  f197568:	02802025 */ 	move	$a0,$s4
/*  f19756c:	0fc65258 */ 	jal	botPassesCowardCheck
/*  f197570:	02002825 */ 	move	$a1,$s0
/*  f197574:	10400140 */ 	beqz	$v0,.PB0f197a78
/*  f197578:	02002025 */ 	move	$a0,$s0
/*  f19757c:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f197580:	2415002f */ 	li	$s5,0x2f
/*  f197584:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f197588:	1000013b */ 	b	.PB0f197a78
/*  f19758c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f197590:	c4680008 */ 	lwc1	$f8,0x8($v1)
.PB0f197594:
/*  f197594:	2415002b */ 	li	$s5,0x2b
/*  f197598:	24640028 */ 	addiu	$a0,$v1,0x28
/*  f19759c:	e64800ec */ 	swc1	$f8,0xec($s2)
/*  f1975a0:	c466000c */ 	lwc1	$f6,0xc($v1)
/*  f1975a4:	264500f8 */ 	addiu	$a1,$s2,0xf8
/*  f1975a8:	e64600f0 */ 	swc1	$f6,0xf0($s2)
/*  f1975ac:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f1975b0:	0fc19661 */ 	jal	roomsCopy
/*  f1975b4:	e64a00f4 */ 	swc1	$f10,0xf4($s2)
/*  f1975b8:	924e004c */ 	lbu	$t6,0x4c($s2)
/*  f1975bc:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f1975c0:	1000012d */ 	b	.PB0f197a78
/*  f1975c4:	a24f004c */ 	sb	$t7,0x4c($s2)
.PB0f1975c8:
/*  f1975c8:	24010009 */ 	li	$at,0x9
/*  f1975cc:	14410048 */ 	bne	$v0,$at,.PB0f1976f0
/*  f1975d0:	3c18800b */ 	lui	$t8,0x800b
/*  f1975d4:	931811b8 */ 	lbu	$t8,0x11b8($t8)
/*  f1975d8:	24010004 */ 	li	$at,0x4
/*  f1975dc:	17010126 */ 	bne	$t8,$at,.PB0f197a78
/*  f1975e0:	00000000 */ 	nop
/*  f1975e4:	8e99001c */ 	lw	$t9,0x1c($s4)
/*  f1975e8:	3c0a800b */ 	lui	$t2,0x800b
/*  f1975ec:	854a073e */ 	lh	$t2,0x73e($t2)
/*  f1975f0:	87290028 */ 	lh	$t1,0x28($t9)
/*  f1975f4:	152a0016 */ 	bne	$t1,$t2,.PB0f197650
/*  f1975f8:	00000000 */ 	nop
/*  f1975fc:	868b017e */ 	lh	$t3,0x17e($s4)
/*  f197600:	13cb0013 */ 	beq	$s8,$t3,.PB0f197650
/*  f197604:	00000000 */ 	nop
/*  f197608:	8e4d0128 */ 	lw	$t5,0x128($s2)
/*  f19760c:	11a00010 */ 	beqz	$t5,.PB0f197650
/*  f197610:	00000000 */ 	nop
/*  f197614:	0fc0a255 */ 	jal	chrGetTargetProp
/*  f197618:	02802025 */ 	move	$a0,$s4
/*  f19761c:	02802025 */ 	move	$a0,$s4
/*  f197620:	0fc65258 */ 	jal	botPassesCowardCheck
/*  f197624:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f197628:	10400009 */ 	beqz	$v0,.PB0f197650
/*  f19762c:	02802025 */ 	move	$a0,$s4
/*  f197630:	0fc0a255 */ 	jal	chrGetTargetProp
/*  f197634:	2415002f */ 	li	$s5,0x2f
/*  f197638:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f19763c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f197640:	240c00fa */ 	li	$t4,0xfa
/*  f197644:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f197648:	1000010b */ 	b	.PB0f197a78
/*  f19764c:	ae4c01d8 */ 	sw	$t4,0x1d8($s2)
.PB0f197650:
/*  f197650:	3c04800b */ 	lui	$a0,0x800b
/*  f197654:	27ae0260 */ 	addiu	$t6,$sp,0x260
/*  f197658:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f19765c:	8484073e */ 	lh	$a0,0x73e($a0)
/*  f197660:	27a5026c */ 	addiu	$a1,$sp,0x26c
/*  f197664:	27a60268 */ 	addiu	$a2,$sp,0x268
/*  f197668:	0fc671fc */ 	jal	botroomFindPos
/*  f19766c:	27a70264 */ 	addiu	$a3,$sp,0x264
/*  f197670:	10400101 */ 	beqz	$v0,.PB0f197a78
/*  f197674:	c7b2026c */ 	lwc1	$f18,0x26c($sp)
/*  f197678:	e65200ec */ 	swc1	$f18,0xec($s2)
/*  f19767c:	c7a40270 */ 	lwc1	$f4,0x270($sp)
/*  f197680:	3c04800b */ 	lui	$a0,0x800b
/*  f197684:	2415002b */ 	li	$s5,0x2b
/*  f197688:	e64400f0 */ 	swc1	$f4,0xf0($s2)
/*  f19768c:	c7a80274 */ 	lwc1	$f8,0x274($sp)
/*  f197690:	2484073e */ 	addiu	$a0,$a0,0x73e
/*  f197694:	264500f8 */ 	addiu	$a1,$s2,0xf8
/*  f197698:	0fc19661 */ 	jal	roomsCopy
/*  f19769c:	e64800f4 */ 	swc1	$f8,0xf4($s2)
/*  f1976a0:	8e8f001c */ 	lw	$t7,0x1c($s4)
/*  f1976a4:	3c19800b */ 	lui	$t9,0x800b
/*  f1976a8:	8739073e */ 	lh	$t9,0x73e($t9)
/*  f1976ac:	85f80028 */ 	lh	$t8,0x28($t7)
/*  f1976b0:	924e004c */ 	lbu	$t6,0x4c($s2)
/*  f1976b4:	3c0a800b */ 	lui	$t2,0x800b
/*  f1976b8:	03194826 */ 	xor	$t1,$t8,$t9
/*  f1976bc:	2d290001 */ 	sltiu	$t1,$t1,0x1
/*  f1976c0:	0009582b */ 	sltu	$t3,$zero,$t1
/*  f1976c4:	000b61c0 */ 	sll	$t4,$t3,0x7
/*  f1976c8:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f1976cc:	018fc025 */ 	or	$t8,$t4,$t7
/*  f1976d0:	a258004c */ 	sb	$t8,0x4c($s2)
/*  f1976d4:	8fb90264 */ 	lw	$t9,0x264($sp)
/*  f1976d8:	a6590048 */ 	sh	$t9,0x48($s2)
/*  f1976dc:	8fa90260 */ 	lw	$t1,0x260($sp)
/*  f1976e0:	a649004a */ 	sh	$t1,0x4a($s2)
/*  f1976e4:	854a073e */ 	lh	$t2,0x73e($t2)
/*  f1976e8:	100000e3 */ 	b	.PB0f197a78
/*  f1976ec:	ae4a00bc */ 	sw	$t2,0xbc($s2)
.PB0f1976f0:
/*  f1976f0:	2401000a */ 	li	$at,0xa
/*  f1976f4:	1441002c */ 	bne	$v0,$at,.PB0f1977a8
/*  f1976f8:	3c0b800b */ 	lui	$t3,0x800b
/*  f1976fc:	916b11b8 */ 	lbu	$t3,0x11b8($t3)
/*  f197700:	24010004 */ 	li	$at,0x4
/*  f197704:	3c04800b */ 	lui	$a0,0x800b
/*  f197708:	156100db */ 	bne	$t3,$at,.PB0f197a78
/*  f19770c:	27a50254 */ 	addiu	$a1,$sp,0x254
/*  f197710:	27ad0248 */ 	addiu	$t5,$sp,0x248
/*  f197714:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f197718:	8484073e */ 	lh	$a0,0x73e($a0)
/*  f19771c:	27a60250 */ 	addiu	$a2,$sp,0x250
/*  f197720:	0fc671fc */ 	jal	botroomFindPos
/*  f197724:	27a7024c */ 	addiu	$a3,$sp,0x24c
/*  f197728:	104000d3 */ 	beqz	$v0,.PB0f197a78
/*  f19772c:	c7a60254 */ 	lwc1	$f6,0x254($sp)
/*  f197730:	e64600ec */ 	swc1	$f6,0xec($s2)
/*  f197734:	c7aa0258 */ 	lwc1	$f10,0x258($sp)
/*  f197738:	3c04800b */ 	lui	$a0,0x800b
/*  f19773c:	2415002b */ 	li	$s5,0x2b
/*  f197740:	e64a00f0 */ 	swc1	$f10,0xf0($s2)
/*  f197744:	c7b2025c */ 	lwc1	$f18,0x25c($sp)
/*  f197748:	2484073e */ 	addiu	$a0,$a0,0x73e
/*  f19774c:	264500f8 */ 	addiu	$a1,$s2,0xf8
/*  f197750:	0fc19661 */ 	jal	roomsCopy
/*  f197754:	e65200f4 */ 	swc1	$f18,0xf4($s2)
/*  f197758:	8e8e001c */ 	lw	$t6,0x1c($s4)
/*  f19775c:	3c0f800b */ 	lui	$t7,0x800b
/*  f197760:	85ef073e */ 	lh	$t7,0x73e($t7)
/*  f197764:	85cc0028 */ 	lh	$t4,0x28($t6)
/*  f197768:	924d004c */ 	lbu	$t5,0x4c($s2)
/*  f19776c:	3c19800b */ 	lui	$t9,0x800b
/*  f197770:	018fc026 */ 	xor	$t8,$t4,$t7
/*  f197774:	2f180001 */ 	sltiu	$t8,$t8,0x1
/*  f197778:	0018482b */ 	sltu	$t1,$zero,$t8
/*  f19777c:	000959c0 */ 	sll	$t3,$t1,0x7
/*  f197780:	31aeff7f */ 	andi	$t6,$t5,0xff7f
/*  f197784:	016e6025 */ 	or	$t4,$t3,$t6
/*  f197788:	a24c004c */ 	sb	$t4,0x4c($s2)
/*  f19778c:	8faf024c */ 	lw	$t7,0x24c($sp)
/*  f197790:	a64f0048 */ 	sh	$t7,0x48($s2)
/*  f197794:	8fb80248 */ 	lw	$t8,0x248($sp)
/*  f197798:	a658004a */ 	sh	$t8,0x4a($s2)
/*  f19779c:	8739073e */ 	lh	$t9,0x73e($t9)
/*  f1977a0:	100000b5 */ 	b	.PB0f197a78
/*  f1977a4:	ae5900bc */ 	sw	$t9,0xbc($s2)
.PB0f1977a8:
/*  f1977a8:	24010005 */ 	li	$at,0x5
/*  f1977ac:	1441003b */ 	bne	$v0,$at,.PB0f19789c
/*  f1977b0:	3c09800b */ 	lui	$t1,0x800b
/*  f1977b4:	912911b8 */ 	lbu	$t1,0x11b8($t1)
/*  f1977b8:	24010002 */ 	li	$at,0x2
/*  f1977bc:	3c02800b */ 	lui	$v0,0x800b
/*  f1977c0:	152100ad */ 	bne	$t1,$at,.PB0f197a78
/*  f1977c4:	00000000 */ 	nop
/*  f1977c8:	8c42086c */ 	lw	$v0,0x86c($v0)
/*  f1977cc:	104000aa */ 	beqz	$v0,.PB0f197a78
/*  f1977d0:	00000000 */ 	nop
/*  f1977d4:	8e8a001c */ 	lw	$t2,0x1c($s4)
/*  f1977d8:	104a00a7 */ 	beq	$v0,$t2,.PB0f197a78
/*  f1977dc:	00000000 */ 	nop
/*  f1977e0:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f1977e4:	24010003 */ 	li	$at,0x3
/*  f1977e8:	3c0d800b */ 	lui	$t5,0x800b
/*  f1977ec:	10610003 */ 	beq	$v1,$at,.PB0f1977fc
/*  f1977f0:	24010006 */ 	li	$at,0x6
/*  f1977f4:	54610027 */ 	bnel	$v1,$at,.PB0f197894
/*  f1977f8:	2415002c */ 	li	$s5,0x2c
.PB0f1977fc:
/*  f1977fc:	8dad11b4 */ 	lw	$t5,0x11b4($t5)
/*  f197800:	8c500004 */ 	lw	$s0,0x4($v0)
/*  f197804:	02802025 */ 	move	$a0,$s4
/*  f197808:	31ab0002 */ 	andi	$t3,$t5,0x2
/*  f19780c:	11600013 */ 	beqz	$t3,.PB0f19785c
/*  f197810:	00000000 */ 	nop
/*  f197814:	928e0125 */ 	lbu	$t6,0x125($s4)
/*  f197818:	920c0125 */ 	lbu	$t4,0x125($s0)
/*  f19781c:	02002825 */ 	move	$a1,$s0
/*  f197820:	15cc000e */ 	bne	$t6,$t4,.PB0f19785c
/*  f197824:	00000000 */ 	nop
/*  f197828:	0fc6541f */ 	jal	botCanFollow
/*  f19782c:	02802025 */ 	move	$a0,$s4
/*  f197830:	10400091 */ 	beqz	$v0,.PB0f197a78
/*  f197834:	00000000 */ 	nop
/*  f197838:	0c004be0 */ 	jal	random
/*  f19783c:	24150032 */ 	li	$s5,0x32
/*  f197840:	304f0003 */ 	andi	$t7,$v0,0x3
/*  f197844:	2df80001 */ 	sltiu	$t8,$t7,0x1
/*  f197848:	ae5801e0 */ 	sw	$t8,0x1e0($s2)
/*  f19784c:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f197850:	02002025 */ 	move	$a0,$s0
/*  f197854:	10000088 */ 	b	.PB0f197a78
/*  f197858:	a642000a */ 	sh	$v0,0xa($s2)
.PB0f19785c:
/*  f19785c:	0fc6513d */ 	jal	botIsTargetInvisible
/*  f197860:	02002825 */ 	move	$a1,$s0
/*  f197864:	14400084 */ 	bnez	$v0,.PB0f197a78
/*  f197868:	02802025 */ 	move	$a0,$s4
/*  f19786c:	0fc65258 */ 	jal	botPassesCowardCheck
/*  f197870:	02002825 */ 	move	$a1,$s0
/*  f197874:	10400080 */ 	beqz	$v0,.PB0f197a78
/*  f197878:	02002025 */ 	move	$a0,$s0
/*  f19787c:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f197880:	2415002f */ 	li	$s5,0x2f
/*  f197884:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f197888:	1000007b */ 	b	.PB0f197a78
/*  f19788c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f197890:	2415002c */ 	li	$s5,0x2c
.PB0f197894:
/*  f197894:	10000078 */ 	b	.PB0f197a78
/*  f197898:	ae420010 */ 	sw	$v0,0x10($s2)
.PB0f19789c:
/*  f19789c:	2401000b */ 	li	$at,0xb
/*  f1978a0:	1441003a */ 	bne	$v0,$at,.PB0f19798c
/*  f1978a4:	3c19800b */ 	lui	$t9,0x800b
/*  f1978a8:	933911b8 */ 	lbu	$t9,0x11b8($t9)
/*  f1978ac:	3c02800b */ 	lui	$v0,0x800b
/*  f1978b0:	16f90071 */ 	bne	$s7,$t9,.PB0f197a78
/*  f1978b4:	00000000 */ 	nop
/*  f1978b8:	8c420734 */ 	lw	$v0,0x734($v0)
/*  f1978bc:	1040006e */ 	beqz	$v0,.PB0f197a78
/*  f1978c0:	00000000 */ 	nop
/*  f1978c4:	8e89001c */ 	lw	$t1,0x1c($s4)
/*  f1978c8:	1049006b */ 	beq	$v0,$t1,.PB0f197a78
/*  f1978cc:	00000000 */ 	nop
/*  f1978d0:	90430000 */ 	lbu	$v1,0x0($v0)
/*  f1978d4:	24010003 */ 	li	$at,0x3
/*  f1978d8:	3c0a800b */ 	lui	$t2,0x800b
/*  f1978dc:	10610003 */ 	beq	$v1,$at,.PB0f1978ec
/*  f1978e0:	24010006 */ 	li	$at,0x6
/*  f1978e4:	54610027 */ 	bnel	$v1,$at,.PB0f197984
/*  f1978e8:	2415002c */ 	li	$s5,0x2c
.PB0f1978ec:
/*  f1978ec:	8d4a11b4 */ 	lw	$t2,0x11b4($t2)
/*  f1978f0:	8c500004 */ 	lw	$s0,0x4($v0)
/*  f1978f4:	02802025 */ 	move	$a0,$s4
/*  f1978f8:	314d0002 */ 	andi	$t5,$t2,0x2
/*  f1978fc:	11a00013 */ 	beqz	$t5,.PB0f19794c
/*  f197900:	00000000 */ 	nop
/*  f197904:	928b0125 */ 	lbu	$t3,0x125($s4)
/*  f197908:	920e0125 */ 	lbu	$t6,0x125($s0)
/*  f19790c:	02002825 */ 	move	$a1,$s0
/*  f197910:	156e000e */ 	bne	$t3,$t6,.PB0f19794c
/*  f197914:	00000000 */ 	nop
/*  f197918:	0fc6541f */ 	jal	botCanFollow
/*  f19791c:	02802025 */ 	move	$a0,$s4
/*  f197920:	10400055 */ 	beqz	$v0,.PB0f197a78
/*  f197924:	00000000 */ 	nop
/*  f197928:	0c004be0 */ 	jal	random
/*  f19792c:	24150032 */ 	li	$s5,0x32
/*  f197930:	304c0003 */ 	andi	$t4,$v0,0x3
/*  f197934:	2d8f0001 */ 	sltiu	$t7,$t4,0x1
/*  f197938:	ae4f01e0 */ 	sw	$t7,0x1e0($s2)
/*  f19793c:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f197940:	02002025 */ 	move	$a0,$s0
/*  f197944:	1000004c */ 	b	.PB0f197a78
/*  f197948:	a642000a */ 	sh	$v0,0xa($s2)
.PB0f19794c:
/*  f19794c:	0fc6513d */ 	jal	botIsTargetInvisible
/*  f197950:	02002825 */ 	move	$a1,$s0
/*  f197954:	14400048 */ 	bnez	$v0,.PB0f197a78
/*  f197958:	02802025 */ 	move	$a0,$s4
/*  f19795c:	0fc65258 */ 	jal	botPassesCowardCheck
/*  f197960:	02002825 */ 	move	$a1,$s0
/*  f197964:	10400044 */ 	beqz	$v0,.PB0f197a78
/*  f197968:	02002025 */ 	move	$a0,$s0
/*  f19796c:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f197970:	2415002f */ 	li	$s5,0x2f
/*  f197974:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f197978:	1000003f */ 	b	.PB0f197a78
/*  f19797c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f197980:	2415002c */ 	li	$s5,0x2c
.PB0f197984:
/*  f197984:	1000003c */ 	b	.PB0f197a78
/*  f197988:	ae420010 */ 	sw	$v0,0x10($s2)
.PB0f19798c:
/*  f19798c:	2401000c */ 	li	$at,0xc
/*  f197990:	14410039 */ 	bne	$v0,$at,.PB0f197a78
/*  f197994:	3c18800b */ 	lui	$t8,0x800b
/*  f197998:	931811b8 */ 	lbu	$t8,0x11b8($t8)
/*  f19799c:	24010003 */ 	li	$at,0x3
/*  f1979a0:	3c02800b */ 	lui	$v0,0x800b
/*  f1979a4:	17010034 */ 	bne	$t8,$at,.PB0f197a78
/*  f1979a8:	00000000 */ 	nop
/*  f1979ac:	8c420734 */ 	lw	$v0,0x734($v0)
/*  f1979b0:	3c09800b */ 	lui	$t1,0x800b
/*  f1979b4:	04400030 */ 	bltz	$v0,.PB0f197a78
/*  f1979b8:	0002c840 */ 	sll	$t9,$v0,0x1
/*  f1979bc:	01394821 */ 	addu	$t1,$t1,$t9
/*  f1979c0:	85290738 */ 	lh	$t1,0x738($t1)
/*  f1979c4:	3c0d800b */ 	lui	$t5,0x800b
/*  f1979c8:	8e8b001c */ 	lw	$t3,0x1c($s4)
/*  f1979cc:	00095080 */ 	sll	$t2,$t1,0x2
/*  f1979d0:	01aa6821 */ 	addu	$t5,$t5,$t2
/*  f1979d4:	8dad0af0 */ 	lw	$t5,0xaf0($t5)
/*  f1979d8:	3c0e800b */ 	lui	$t6,0x800b
/*  f1979dc:	8da3001c */ 	lw	$v1,0x1c($t5)
/*  f1979e0:	106b0025 */ 	beq	$v1,$t3,.PB0f197a78
/*  f1979e4:	00000000 */ 	nop
/*  f1979e8:	8dce11b4 */ 	lw	$t6,0x11b4($t6)
/*  f1979ec:	8c700004 */ 	lw	$s0,0x4($v1)
/*  f1979f0:	02802025 */ 	move	$a0,$s4
/*  f1979f4:	31cc0002 */ 	andi	$t4,$t6,0x2
/*  f1979f8:	11800013 */ 	beqz	$t4,.PB0f197a48
/*  f1979fc:	00000000 */ 	nop
/*  f197a00:	928f0125 */ 	lbu	$t7,0x125($s4)
/*  f197a04:	92180125 */ 	lbu	$t8,0x125($s0)
/*  f197a08:	02002825 */ 	move	$a1,$s0
/*  f197a0c:	15f8000e */ 	bne	$t7,$t8,.PB0f197a48
/*  f197a10:	00000000 */ 	nop
/*  f197a14:	0fc6541f */ 	jal	botCanFollow
/*  f197a18:	02802025 */ 	move	$a0,$s4
/*  f197a1c:	10400016 */ 	beqz	$v0,.PB0f197a78
/*  f197a20:	00000000 */ 	nop
/*  f197a24:	0c004be0 */ 	jal	random
/*  f197a28:	24150032 */ 	li	$s5,0x32
/*  f197a2c:	30590003 */ 	andi	$t9,$v0,0x3
/*  f197a30:	2f290001 */ 	sltiu	$t1,$t9,0x1
/*  f197a34:	ae4901e0 */ 	sw	$t1,0x1e0($s2)
/*  f197a38:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f197a3c:	02002025 */ 	move	$a0,$s0
/*  f197a40:	1000000d */ 	b	.PB0f197a78
/*  f197a44:	a642000a */ 	sh	$v0,0xa($s2)
.PB0f197a48:
/*  f197a48:	0fc6513d */ 	jal	botIsTargetInvisible
/*  f197a4c:	02002825 */ 	move	$a1,$s0
/*  f197a50:	14400009 */ 	bnez	$v0,.PB0f197a78
/*  f197a54:	02802025 */ 	move	$a0,$s4
/*  f197a58:	0fc65258 */ 	jal	botPassesCowardCheck
/*  f197a5c:	02002825 */ 	move	$a1,$s0
/*  f197a60:	10400005 */ 	beqz	$v0,.PB0f197a78
/*  f197a64:	02002025 */ 	move	$a0,$s0
/*  f197a68:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f197a6c:	2415002f */ 	li	$s5,0x2f
/*  f197a70:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f197a74:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PB0f197a78:
/*  f197a78:	06a10078 */ 	bgez	$s5,.PB0f197c5c
/*  f197a7c:	3c03800b */ 	lui	$v1,0x800b
/*  f197a80:	906311b8 */ 	lbu	$v1,0x11b8($v1)
/*  f197a84:	24010003 */ 	li	$at,0x3
/*  f197a88:	16e3001a */ 	bne	$s7,$v1,.PB0f197af4
/*  f197a8c:	00000000 */ 	nop
/*  f197a90:	8e4a009c */ 	lw	$t2,0x9c($s2)
/*  f197a94:	000a6fc2 */ 	srl	$t5,$t2,0x1f
/*  f197a98:	11a00070 */ 	beqz	$t5,.PB0f197c5c
/*  f197a9c:	00000000 */ 	nop
/*  f197aa0:	0c004be0 */ 	jal	random
/*  f197aa4:	03c08025 */ 	move	$s0,$s8
/*  f197aa8:	24010064 */ 	li	$at,0x64
/*  f197aac:	0041001b */ 	divu	$zero,$v0,$at
/*  f197ab0:	00005810 */ 	mfhi	$t3
/*  f197ab4:	2d610042 */ 	sltiu	$at,$t3,0x42
/*  f197ab8:	10200005 */ 	beqz	$at,.PB0f197ad0
/*  f197abc:	02802025 */ 	move	$a0,$s4
/*  f197ac0:	3c0547c3 */ 	lui	$a1,0x47c3
/*  f197ac4:	0fc65434 */ 	jal	botFindTeammateToFollow
/*  f197ac8:	34a55000 */ 	ori	$a1,$a1,0x5000
/*  f197acc:	00408025 */ 	move	$s0,$v0
.PB0f197ad0:
/*  f197ad0:	06000062 */ 	bltz	$s0,.PB0f197c5c
/*  f197ad4:	00000000 */ 	nop
/*  f197ad8:	0c004be0 */ 	jal	random
/*  f197adc:	24150032 */ 	li	$s5,0x32
/*  f197ae0:	304e0003 */ 	andi	$t6,$v0,0x3
/*  f197ae4:	2dcc0001 */ 	sltiu	$t4,$t6,0x1
/*  f197ae8:	ae4c01e0 */ 	sw	$t4,0x1e0($s2)
/*  f197aec:	1000005b */ 	b	.PB0f197c5c
/*  f197af0:	a650000a */ 	sh	$s0,0xa($s2)
.PB0f197af4:
/*  f197af4:	14610024 */ 	bne	$v1,$at,.PB0f197b88
/*  f197af8:	3c02800b */ 	lui	$v0,0x800b
/*  f197afc:	8c420734 */ 	lw	$v0,0x734($v0)
/*  f197b00:	3c18800b */ 	lui	$t8,0x800b
/*  f197b04:	04400055 */ 	bltz	$v0,.PB0f197c5c
/*  f197b08:	00027840 */ 	sll	$t7,$v0,0x1
/*  f197b0c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f197b10:	87180738 */ 	lh	$t8,0x738($t8)
/*  f197b14:	3c09800b */ 	lui	$t1,0x800b
/*  f197b18:	8e8a001c */ 	lw	$t2,0x1c($s4)
/*  f197b1c:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f197b20:	01394821 */ 	addu	$t1,$t1,$t9
/*  f197b24:	8d290af0 */ 	lw	$t1,0xaf0($t1)
/*  f197b28:	8d23001c */ 	lw	$v1,0x1c($t1)
/*  f197b2c:	146a004b */ 	bne	$v1,$t2,.PB0f197c5c
/*  f197b30:	00000000 */ 	nop
/*  f197b34:	0c004be0 */ 	jal	random
/*  f197b38:	03c08025 */ 	move	$s0,$s8
/*  f197b3c:	24010064 */ 	li	$at,0x64
/*  f197b40:	0041001b */ 	divu	$zero,$v0,$at
/*  f197b44:	00006810 */ 	mfhi	$t5
/*  f197b48:	2da10042 */ 	sltiu	$at,$t5,0x42
/*  f197b4c:	10200005 */ 	beqz	$at,.PB0f197b64
/*  f197b50:	02802025 */ 	move	$a0,$s4
/*  f197b54:	3c0547c3 */ 	lui	$a1,0x47c3
/*  f197b58:	0fc65434 */ 	jal	botFindTeammateToFollow
/*  f197b5c:	34a55000 */ 	ori	$a1,$a1,0x5000
/*  f197b60:	00408025 */ 	move	$s0,$v0
.PB0f197b64:
/*  f197b64:	0600003d */ 	bltz	$s0,.PB0f197c5c
/*  f197b68:	00000000 */ 	nop
/*  f197b6c:	0c004be0 */ 	jal	random
/*  f197b70:	24150032 */ 	li	$s5,0x32
/*  f197b74:	304b0003 */ 	andi	$t3,$v0,0x3
/*  f197b78:	2d6e0001 */ 	sltiu	$t6,$t3,0x1
/*  f197b7c:	ae4e01e0 */ 	sw	$t6,0x1e0($s2)
/*  f197b80:	10000036 */ 	b	.PB0f197c5c
/*  f197b84:	a650000a */ 	sh	$s0,0xa($s2)
.PB0f197b88:
/*  f197b88:	24010005 */ 	li	$at,0x5
/*  f197b8c:	54610021 */ 	bnel	$v1,$at,.PB0f197c14
/*  f197b90:	24010002 */ 	li	$at,0x2
/*  f197b94:	0fc65911 */ 	jal	botShouldReturnCtcToken
/*  f197b98:	02802025 */ 	move	$a0,$s4
/*  f197b9c:	1040002f */ 	beqz	$v0,.PB0f197c5c
/*  f197ba0:	00000000 */ 	nop
/*  f197ba4:	92840125 */ 	lbu	$a0,0x125($s4)
/*  f197ba8:	0fc6414a */ 	jal	radarGetTeamIndex
/*  f197bac:	2415002b */ 	li	$s5,0x2b
/*  f197bb0:	3c07800b */ 	lui	$a3,0x800b
/*  f197bb4:	24e70730 */ 	addiu	$a3,$a3,0x730
/*  f197bb8:	00026040 */ 	sll	$t4,$v0,0x1
/*  f197bbc:	00ec7821 */ 	addu	$t7,$a3,$t4
/*  f197bc0:	85e30008 */ 	lh	$v1,0x8($t7)
/*  f197bc4:	24050042 */ 	li	$a1,0x42
/*  f197bc8:	27a601d8 */ 	addiu	$a2,$sp,0x1d8
/*  f197bcc:	0003c100 */ 	sll	$t8,$v1,0x4
/*  f197bd0:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f197bd4:	0fc458d4 */ 	jal	padUnpack
/*  f197bd8:	87240018 */ 	lh	$a0,0x18($t9)
/*  f197bdc:	c7a401d8 */ 	lwc1	$f4,0x1d8($sp)
/*  f197be0:	924a004c */ 	lbu	$t2,0x4c($s2)
/*  f197be4:	e64400ec */ 	swc1	$f4,0xec($s2)
/*  f197be8:	c7a801dc */ 	lwc1	$f8,0x1dc($sp)
/*  f197bec:	314dff7f */ 	andi	$t5,$t2,0xff7f
/*  f197bf0:	e64800f0 */ 	swc1	$f8,0xf0($s2)
/*  f197bf4:	c7a601e0 */ 	lwc1	$f6,0x1e0($sp)
/*  f197bf8:	e64600f4 */ 	swc1	$f6,0xf4($s2)
/*  f197bfc:	8fa90220 */ 	lw	$t1,0x220($sp)
/*  f197c00:	a65e00fa */ 	sh	$s8,0xfa($s2)
/*  f197c04:	a24d004c */ 	sb	$t5,0x4c($s2)
/*  f197c08:	10000014 */ 	b	.PB0f197c5c
/*  f197c0c:	a64900f8 */ 	sh	$t1,0xf8($s2)
/*  f197c10:	24010002 */ 	li	$at,0x2
.PB0f197c14:
/*  f197c14:	14610011 */ 	bne	$v1,$at,.PB0f197c5c
/*  f197c18:	3c0b800b */ 	lui	$t3,0x800b
/*  f197c1c:	8d6b086c */ 	lw	$t3,0x86c($t3)
/*  f197c20:	8e8e001c */ 	lw	$t6,0x1c($s4)
/*  f197c24:	156e000d */ 	bne	$t3,$t6,.PB0f197c5c
/*  f197c28:	00000000 */ 	nop
/*  f197c2c:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f197c30:	02802025 */ 	move	$a0,$s4
/*  f197c34:	3c03800b */ 	lui	$v1,0x800b
/*  f197c38:	24630730 */ 	addiu	$v1,$v1,0x730
/*  f197c3c:	846c00d2 */ 	lh	$t4,0xd2($v1)
/*  f197c40:	2415002e */ 	li	$s5,0x2e
/*  f197c44:	104c0005 */ 	beq	$v0,$t4,.PB0f197c5c
/*  f197c48:	00000000 */ 	nop
/*  f197c4c:	8c6f0080 */ 	lw	$t7,0x80($v1)
/*  f197c50:	2415002c */ 	li	$s5,0x2c
/*  f197c54:	10000001 */ 	b	.PB0f197c5c
/*  f197c58:	ae4f0010 */ 	sw	$t7,0x10($s2)
.PB0f197c5c:
/*  f197c5c:	06a100a2 */ 	bgez	$s5,.PB0f197ee8
/*  f197c60:	00000000 */ 	nop
/*  f197c64:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f197c68:	2401000c */ 	li	$at,0xc
/*  f197c6c:	93020047 */ 	lbu	$v0,0x47($t8)
/*  f197c70:	54410011 */ 	bnel	$v0,$at,.PB0f197cb8
/*  f197c74:	24010009 */ 	li	$at,0x9
/*  f197c78:	86420076 */ 	lh	$v0,0x76($s2)
/*  f197c7c:	02802025 */ 	move	$a0,$s4
/*  f197c80:	3c05800b */ 	lui	$a1,0x800b
/*  f197c84:	04400098 */ 	bltz	$v0,.PB0f197ee8
/*  f197c88:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f197c8c:	00b92821 */ 	addu	$a1,$a1,$t9
/*  f197c90:	0fc6513d */ 	jal	botIsTargetInvisible
/*  f197c94:	8ca50af0 */ 	lw	$a1,0xaf0($a1)
/*  f197c98:	14400093 */ 	bnez	$v0,.PB0f197ee8
/*  f197c9c:	00000000 */ 	nop
/*  f197ca0:	86490076 */ 	lh	$t1,0x76($s2)
/*  f197ca4:	2415002f */ 	li	$s5,0x2f
/*  f197ca8:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f197cac:	1000008e */ 	b	.PB0f197ee8
/*  f197cb0:	a6490008 */ 	sh	$t1,0x8($s2)
/*  f197cb4:	24010009 */ 	li	$at,0x9
.PB0f197cb8:
/*  f197cb8:	54410021 */ 	bnel	$v0,$at,.PB0f197d40
/*  f197cbc:	24010008 */ 	li	$at,0x8
/*  f197cc0:	8e4a0114 */ 	lw	$t2,0x114($s2)
/*  f197cc4:	0543000f */ 	bgezl	$t2,.PB0f197d04
/*  f197cc8:	8e420114 */ 	lw	$v0,0x114($s2)
/*  f197ccc:	86420076 */ 	lh	$v0,0x76($s2)
/*  f197cd0:	02802025 */ 	move	$a0,$s4
/*  f197cd4:	3c05800b */ 	lui	$a1,0x800b
/*  f197cd8:	04400009 */ 	bltz	$v0,.PB0f197d00
/*  f197cdc:	00026880 */ 	sll	$t5,$v0,0x2
/*  f197ce0:	00ad2821 */ 	addu	$a1,$a1,$t5
/*  f197ce4:	8ca50af0 */ 	lw	$a1,0xaf0($a1)
/*  f197ce8:	0fc12aec */ 	jal	chrCompareTeams
/*  f197cec:	24060001 */ 	li	$a2,0x1
/*  f197cf0:	54400004 */ 	bnezl	$v0,.PB0f197d04
/*  f197cf4:	8e420114 */ 	lw	$v0,0x114($s2)
/*  f197cf8:	864b0076 */ 	lh	$t3,0x76($s2)
/*  f197cfc:	ae4b0114 */ 	sw	$t3,0x114($s2)
.PB0f197d00:
/*  f197d00:	8e420114 */ 	lw	$v0,0x114($s2)
.PB0f197d04:
/*  f197d04:	02802025 */ 	move	$a0,$s4
/*  f197d08:	3c05800b */ 	lui	$a1,0x800b
/*  f197d0c:	04400076 */ 	bltz	$v0,.PB0f197ee8
/*  f197d10:	00027080 */ 	sll	$t6,$v0,0x2
/*  f197d14:	00ae2821 */ 	addu	$a1,$a1,$t6
/*  f197d18:	0fc6513d */ 	jal	botIsTargetInvisible
/*  f197d1c:	8ca50af0 */ 	lw	$a1,0xaf0($a1)
/*  f197d20:	14400071 */ 	bnez	$v0,.PB0f197ee8
/*  f197d24:	00000000 */ 	nop
/*  f197d28:	8e4c0114 */ 	lw	$t4,0x114($s2)
/*  f197d2c:	2415002f */ 	li	$s5,0x2f
/*  f197d30:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
/*  f197d34:	1000006c */ 	b	.PB0f197ee8
/*  f197d38:	a64c0008 */ 	sh	$t4,0x8($s2)
/*  f197d3c:	24010008 */ 	li	$at,0x8
.PB0f197d40:
/*  f197d40:	5441002a */ 	bnel	$v0,$at,.PB0f197dec
/*  f197d44:	24010006 */ 	li	$at,0x6
/*  f197d48:	0fc62862 */ 	jal	mpGetPlayerRankings
/*  f197d4c:	27a400e4 */ 	addiu	$a0,$sp,0xe4
/*  f197d50:	18400065 */ 	blez	$v0,.PB0f197ee8
/*  f197d54:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f197d58:	0302c021 */ 	addu	$t8,$t8,$v0
/*  f197d5c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f197d60:	27b000e4 */ 	addiu	$s0,$sp,0xe4
/*  f197d64:	0310c821 */ 	addu	$t9,$t8,$s0
/*  f197d68:	afb90050 */ 	sw	$t9,0x50($sp)
.PB0f197d6c:
/*  f197d6c:	0fc63b2d */ 	jal	func0f18d0e8
/*  f197d70:	8e040004 */ 	lw	$a0,0x4($s0)
/*  f197d74:	afa200d8 */ 	sw	$v0,0xd8($sp)
/*  f197d78:	0fc63b03 */ 	jal	mpGetChrFromPlayerIndex
/*  f197d7c:	00402025 */ 	move	$a0,$v0
/*  f197d80:	10540012 */ 	beq	$v0,$s4,.PB0f197dcc
/*  f197d84:	00402025 */ 	move	$a0,$v0
/*  f197d88:	0fc0e6e9 */ 	jal	chrIsDead
/*  f197d8c:	afa200d4 */ 	sw	$v0,0xd4($sp)
/*  f197d90:	1440000e */ 	bnez	$v0,.PB0f197dcc
/*  f197d94:	8fb100d4 */ 	lw	$s1,0xd4($sp)
/*  f197d98:	02802025 */ 	move	$a0,$s4
/*  f197d9c:	02202825 */ 	move	$a1,$s1
/*  f197da0:	0fc12aec */ 	jal	chrCompareTeams
/*  f197da4:	24060002 */ 	li	$a2,0x2
/*  f197da8:	10400008 */ 	beqz	$v0,.PB0f197dcc
/*  f197dac:	02802025 */ 	move	$a0,$s4
/*  f197db0:	0fc6513d */ 	jal	botIsTargetInvisible
/*  f197db4:	02202825 */ 	move	$a1,$s1
/*  f197db8:	14400004 */ 	bnez	$v0,.PB0f197dcc
/*  f197dbc:	8fa900d8 */ 	lw	$t1,0xd8($sp)
/*  f197dc0:	2415002f */ 	li	$s5,0x2f
/*  f197dc4:	a6490008 */ 	sh	$t1,0x8($s2)
/*  f197dc8:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PB0f197dcc:
/*  f197dcc:	8faa0050 */ 	lw	$t2,0x50($sp)
/*  f197dd0:	26100014 */ 	addiu	$s0,$s0,0x14
/*  f197dd4:	020a082b */ 	sltu	$at,$s0,$t2
/*  f197dd8:	1420ffe4 */ 	bnez	$at,.PB0f197d6c
/*  f197ddc:	00000000 */ 	nop
/*  f197de0:	10000041 */ 	b	.PB0f197ee8
/*  f197de4:	00000000 */ 	nop
/*  f197de8:	24010006 */ 	li	$at,0x6
.PB0f197dec:
/*  f197dec:	1441003e */ 	bne	$v0,$at,.PB0f197ee8
/*  f197df0:	3c13800b */ 	lui	$s3,0x800b
/*  f197df4:	26730b50 */ 	addiu	$s3,$s3,0xb50
/*  f197df8:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f197dfc:	44805000 */ 	mtc1	$zero,$f10
/*  f197e00:	03c08825 */ 	move	$s1,$s8
/*  f197e04:	00008025 */ 	move	$s0,$zero
/*  f197e08:	19a00032 */ 	blez	$t5,.PB0f197ed4
/*  f197e0c:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
.PB0f197e10:
/*  f197e10:	0fc63b03 */ 	jal	mpGetChrFromPlayerIndex
/*  f197e14:	02002025 */ 	move	$a0,$s0
/*  f197e18:	10540029 */ 	beq	$v0,$s4,.PB0f197ec0
/*  f197e1c:	00402025 */ 	move	$a0,$v0
/*  f197e20:	0fc0e6e9 */ 	jal	chrIsDead
/*  f197e24:	afa200c0 */ 	sw	$v0,0xc0($sp)
/*  f197e28:	14400025 */ 	bnez	$v0,.PB0f197ec0
/*  f197e2c:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f197e30:	02802025 */ 	move	$a0,$s4
/*  f197e34:	24060002 */ 	li	$a2,0x2
/*  f197e38:	0fc12aec */ 	jal	chrCompareTeams
/*  f197e3c:	afa500c0 */ 	sw	$a1,0xc0($sp)
/*  f197e40:	1040001f */ 	beqz	$v0,.PB0f197ec0
/*  f197e44:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f197e48:	02802025 */ 	move	$a0,$s4
/*  f197e4c:	0fc6513d */ 	jal	botIsTargetInvisible
/*  f197e50:	afa500c0 */ 	sw	$a1,0xc0($sp)
/*  f197e54:	1440001a */ 	bnez	$v0,.PB0f197ec0
/*  f197e58:	8fa500c0 */ 	lw	$a1,0xc0($sp)
/*  f197e5c:	8cab02d4 */ 	lw	$t3,0x2d4($a1)
/*  f197e60:	11600005 */ 	beqz	$t3,.PB0f197e78
/*  f197e64:	00000000 */ 	nop
/*  f197e68:	c4b20104 */ 	lwc1	$f18,0x104($a1)
/*  f197e6c:	c4a40100 */ 	lwc1	$f4,0x100($a1)
/*  f197e70:	1000000b */ 	b	.PB0f197ea0
/*  f197e74:	46049001 */ 	sub.s	$f0,$f18,$f4
.PB0f197e78:
/*  f197e78:	0fc4a797 */ 	jal	playermgrGetPlayerNumByProp
/*  f197e7c:	8ca4001c */ 	lw	$a0,0x1c($a1)
/*  f197e80:	00027080 */ 	sll	$t6,$v0,0x2
/*  f197e84:	02ce6021 */ 	addu	$t4,$s6,$t6
/*  f197e88:	8d980064 */ 	lw	$t8,0x64($t4)
/*  f197e8c:	3c014100 */ 	lui	$at,0x4100
/*  f197e90:	44813000 */ 	mtc1	$at,$f6
/*  f197e94:	c70800dc */ 	lwc1	$f8,0xdc($t8)
/*  f197e98:	46064002 */ 	mul.s	$f0,$f8,$f6
/*  f197e9c:	00000000 */ 	nop
.PB0f197ea0:
/*  f197ea0:	06200005 */ 	bltz	$s1,.PB0f197eb8
/*  f197ea4:	c7aa00d0 */ 	lwc1	$f10,0xd0($sp)
/*  f197ea8:	460a003c */ 	c.lt.s	$f0,$f10
/*  f197eac:	00000000 */ 	nop
/*  f197eb0:	45020004 */ 	bc1fl	.PB0f197ec4
/*  f197eb4:	8e6f0000 */ 	lw	$t7,0x0($s3)
.PB0f197eb8:
/*  f197eb8:	02008825 */ 	move	$s1,$s0
/*  f197ebc:	e7a000d0 */ 	swc1	$f0,0xd0($sp)
.PB0f197ec0:
/*  f197ec0:	8e6f0000 */ 	lw	$t7,0x0($s3)
.PB0f197ec4:
/*  f197ec4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f197ec8:	020f082a */ 	slt	$at,$s0,$t7
/*  f197ecc:	1420ffd0 */ 	bnez	$at,.PB0f197e10
/*  f197ed0:	00000000 */ 	nop
.PB0f197ed4:
/*  f197ed4:	06200004 */ 	bltz	$s1,.PB0f197ee8
/*  f197ed8:	00000000 */ 	nop
/*  f197edc:	2415002f */ 	li	$s5,0x2f
/*  f197ee0:	a6510008 */ 	sh	$s1,0x8($s2)
/*  f197ee4:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PB0f197ee8:
/*  f197ee8:	06a1000d */ 	bgez	$s5,.PB0f197f20
/*  f197eec:	00000000 */ 	nop
/*  f197ef0:	8699017e */ 	lh	$t9,0x17e($s4)
/*  f197ef4:	13d9000a */ 	beq	$s8,$t9,.PB0f197f20
/*  f197ef8:	00000000 */ 	nop
/*  f197efc:	0fc0a255 */ 	jal	chrGetTargetProp
/*  f197f00:	02802025 */ 	move	$a0,$s4
/*  f197f04:	02802025 */ 	move	$a0,$s4
/*  f197f08:	0fc65258 */ 	jal	botPassesCowardCheck
/*  f197f0c:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f197f10:	10400003 */ 	beqz	$v0,.PB0f197f20
/*  f197f14:	00000000 */ 	nop
/*  f197f18:	2415002f */ 	li	$s5,0x2f
/*  f197f1c:	ae5e01d8 */ 	sw	$s8,0x1d8($s2)
.PB0f197f20:
/*  f197f20:	06a1000b */ 	bgez	$s5,.PB0f197f50
/*  f197f24:	02802025 */ 	move	$a0,$s4
/*  f197f28:	0fc65434 */ 	jal	botFindTeammateToFollow
/*  f197f2c:	3c054396 */ 	lui	$a1,0x4396
/*  f197f30:	04400007 */ 	bltz	$v0,.PB0f197f50
/*  f197f34:	00408025 */ 	move	$s0,$v0
/*  f197f38:	0c004be0 */ 	jal	random
/*  f197f3c:	24150032 */ 	li	$s5,0x32
/*  f197f40:	30490003 */ 	andi	$t1,$v0,0x3
/*  f197f44:	2d2a0001 */ 	sltiu	$t2,$t1,0x1
/*  f197f48:	ae4a01e0 */ 	sw	$t2,0x1e0($s2)
/*  f197f4c:	a650000a */ 	sh	$s0,0xa($s2)
.PB0f197f50:
/*  f197f50:	06a10006 */ 	bgez	$s5,.PB0f197f6c
/*  f197f54:	00000000 */ 	nop
/*  f197f58:	0fc65897 */ 	jal	botFindAnyPickup
/*  f197f5c:	02802025 */ 	move	$a0,$s4
/*  f197f60:	10400002 */ 	beqz	$v0,.PB0f197f6c
/*  f197f64:	ae420010 */ 	sw	$v0,0x10($s2)
/*  f197f68:	2415002a */ 	li	$s5,0x2a
.PB0f197f6c:
/*  f197f6c:	3c13800b */ 	lui	$s3,0x800b
/*  f197f70:	06a00082 */ 	bltz	$s5,.PB0f19817c
/*  f197f74:	26730b50 */ 	addiu	$s3,$s3,0xb50
/*  f197f78:	2401002a */ 	li	$at,0x2a
/*  f197f7c:	56a1000a */ 	bnel	$s5,$at,.PB0f197fa8
/*  f197f80:	2401002f */ 	li	$at,0x2f
/*  f197f84:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f197f88:	02802025 */ 	move	$a0,$s4
/*  f197f8c:	50a0007c */ 	beqzl	$a1,.PB0f198180
/*  f197f90:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f197f94:	0fc0eb21 */ 	jal	chrGoToProp
/*  f197f98:	24060002 */ 	li	$a2,0x2
/*  f197f9c:	10000077 */ 	b	.PB0f19817c
/*  f197fa0:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f197fa4:	2401002f */ 	li	$at,0x2f
.PB0f197fa8:
/*  f197fa8:	56a10009 */ 	bnel	$s5,$at,.PB0f197fd0
/*  f197fac:	24010032 */ 	li	$at,0x32
/*  f197fb0:	928d02a0 */ 	lbu	$t5,0x2a0($s4)
/*  f197fb4:	2401002f */ 	li	$at,0x2f
/*  f197fb8:	51a10071 */ 	beql	$t5,$at,.PB0f198180
/*  f197fbc:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f197fc0:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f197fc4:	1000006d */ 	b	.PB0f19817c
/*  f197fc8:	a25e0074 */ 	sb	$s8,0x74($s2)
/*  f197fcc:	24010032 */ 	li	$at,0x32
.PB0f197fd0:
/*  f197fd0:	56a10010 */ 	bnel	$s5,$at,.PB0f198014
/*  f197fd4:	24010033 */ 	li	$at,0x33
/*  f197fd8:	928b02a0 */ 	lbu	$t3,0x2a0($s4)
/*  f197fdc:	24010032 */ 	li	$at,0x32
/*  f197fe0:	51610067 */ 	beql	$t3,$at,.PB0f198180
/*  f197fe4:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f197fe8:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f197fec:	8e4e01e0 */ 	lw	$t6,0x1e0($s2)
/*  f197ff0:	a25e0074 */ 	sb	$s8,0x74($s2)
/*  f197ff4:	02802025 */ 	move	$a0,$s4
/*  f197ff8:	51c00061 */ 	beqzl	$t6,.PB0f198180
/*  f197ffc:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f198000:	0fc650c9 */ 	jal	botSetTarget
/*  f198004:	03c02825 */ 	move	$a1,$s8
/*  f198008:	1000005d */ 	b	.PB0f198180
/*  f19800c:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f198010:	24010033 */ 	li	$at,0x33
.PB0f198014:
/*  f198014:	56a10010 */ 	bnel	$s5,$at,.PB0f198058
/*  f198018:	2401002b */ 	li	$at,0x2b
/*  f19801c:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f198020:	8e4c01dc */ 	lw	$t4,0x1dc($s2)
/*  f198024:	02802025 */ 	move	$a0,$s4
/*  f198028:	51800004 */ 	beqzl	$t4,.PB0f19803c
/*  f19802c:	02802025 */ 	move	$a0,$s4
/*  f198030:	0fc650c9 */ 	jal	botSetTarget
/*  f198034:	03c02825 */ 	move	$a1,$s8
/*  f198038:	02802025 */ 	move	$a0,$s4
.PB0f19803c:
/*  f19803c:	2645008c */ 	addiu	$a1,$s2,0x8c
/*  f198040:	2646007a */ 	addiu	$a2,$s2,0x7a
/*  f198044:	0fc0e153 */ 	jal	chrGoToPos
/*  f198048:	24070002 */ 	li	$a3,0x2
/*  f19804c:	1000004c */ 	b	.PB0f198180
/*  f198050:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f198054:	2401002b */ 	li	$at,0x2b
.PB0f198058:
/*  f198058:	56a10037 */ 	bnel	$s5,$at,.PB0f198138
/*  f19805c:	2401002c */ 	li	$at,0x2c
/*  f198060:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f198064:	c64400ec */ 	lwc1	$f4,0xec($s2)
/*  f198068:	44808000 */ 	mtc1	$zero,$f16
/*  f19806c:	c4720008 */ 	lwc1	$f18,0x8($v1)
/*  f198070:	c64600f0 */ 	lwc1	$f6,0xf0($s2)
/*  f198074:	c468000c */ 	lwc1	$f8,0xc($v1)
/*  f198078:	46049001 */ 	sub.s	$f0,$f18,$f4
/*  f19807c:	c65200f4 */ 	lwc1	$f18,0xf4($s2)
/*  f198080:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f198084:	3c0141a0 */ 	lui	$at,0x41a0
/*  f198088:	4610003c */ 	c.lt.s	$f0,$f16
/*  f19808c:	44817000 */ 	mtc1	$at,$f14
/*  f198090:	46064081 */ 	sub.s	$f2,$f8,$f6
/*  f198094:	45000002 */ 	bc1f	.PB0f1980a0
/*  f198098:	46125301 */ 	sub.s	$f12,$f10,$f18
/*  f19809c:	46000007 */ 	neg.s	$f0,$f0
.PB0f1980a0:
/*  f1980a0:	4610103c */ 	c.lt.s	$f2,$f16
/*  f1980a4:	02802025 */ 	move	$a0,$s4
/*  f1980a8:	264500ec */ 	addiu	$a1,$s2,0xec
/*  f1980ac:	264600f8 */ 	addiu	$a2,$s2,0xf8
/*  f1980b0:	45000002 */ 	bc1f	.PB0f1980bc
/*  f1980b4:	24070002 */ 	li	$a3,0x2
/*  f1980b8:	46001087 */ 	neg.s	$f2,$f2
.PB0f1980bc:
/*  f1980bc:	4610603c */ 	c.lt.s	$f12,$f16
/*  f1980c0:	00000000 */ 	nop
/*  f1980c4:	45020003 */ 	bc1fl	.PB0f1980d4
/*  f1980c8:	4600703c */ 	c.lt.s	$f14,$f0
/*  f1980cc:	46006307 */ 	neg.s	$f12,$f12
/*  f1980d0:	4600703c */ 	c.lt.s	$f14,$f0
.PB0f1980d4:
/*  f1980d4:	00000000 */ 	nop
/*  f1980d8:	4501000e */ 	bc1t	.PB0f198114
/*  f1980dc:	00000000 */ 	nop
/*  f1980e0:	460c703c */ 	c.lt.s	$f14,$f12
/*  f1980e4:	3c014348 */ 	lui	$at,0x4348
/*  f1980e8:	4501000a */ 	bc1t	.PB0f198114
/*  f1980ec:	00000000 */ 	nop
/*  f1980f0:	44812000 */ 	mtc1	$at,$f4
/*  f1980f4:	00000000 */ 	nop
/*  f1980f8:	4602203c */ 	c.lt.s	$f4,$f2
/*  f1980fc:	00000000 */ 	nop
/*  f198100:	45000008 */ 	bc1f	.PB0f198124
/*  f198104:	00000000 */ 	nop
/*  f198108:	828f032d */ 	lb	$t7,0x32d($s4)
/*  f19810c:	05e00005 */ 	bltz	$t7,.PB0f198124
/*  f198110:	00000000 */ 	nop
.PB0f198114:
/*  f198114:	0fc0e153 */ 	jal	chrGoToPos
/*  f198118:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f19811c:	10000018 */ 	b	.PB0f198180
/*  f198120:	928202a0 */ 	lbu	$v0,0x2a0($s4)
.PB0f198124:
/*  f198124:	0fc0bae3 */ 	jal	chrStand
/*  f198128:	02802025 */ 	move	$a0,$s4
/*  f19812c:	10000014 */ 	b	.PB0f198180
/*  f198130:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f198134:	2401002c */ 	li	$at,0x2c
.PB0f198138:
/*  f198138:	56a1000c */ 	bnel	$s5,$at,.PB0f19816c
/*  f19813c:	2401002e */ 	li	$at,0x2e
/*  f198140:	8e590010 */ 	lw	$t9,0x10($s2)
/*  f198144:	02802025 */ 	move	$a0,$s4
/*  f198148:	24060002 */ 	li	$a2,0x2
/*  f19814c:	5320000c */ 	beqzl	$t9,.PB0f198180
/*  f198150:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f198154:	a29502a0 */ 	sb	$s5,0x2a0($s4)
/*  f198158:	0fc0eb21 */ 	jal	chrGoToProp
/*  f19815c:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f198160:	10000007 */ 	b	.PB0f198180
/*  f198164:	928202a0 */ 	lbu	$v0,0x2a0($s4)
/*  f198168:	2401002e */ 	li	$at,0x2e
.PB0f19816c:
/*  f19816c:	16a10003 */ 	bne	$s5,$at,.PB0f19817c
/*  f198170:	02802025 */ 	move	$a0,$s4
/*  f198174:	0fc0bae3 */ 	jal	chrStand
/*  f198178:	a29502a0 */ 	sb	$s5,0x2a0($s4)
.PB0f19817c:
/*  f19817c:	928202a0 */ 	lbu	$v0,0x2a0($s4)
.PB0f198180:
/*  f198180:	2401002a */ 	li	$at,0x2a
/*  f198184:	54410012 */ 	bnel	$v0,$at,.PB0f1981d0
/*  f198188:	2401002f */ 	li	$at,0x2f
/*  f19818c:	82890007 */ 	lb	$t1,0x7($s4)
/*  f198190:	2401000f */ 	li	$at,0xf
/*  f198194:	240b0029 */ 	li	$t3,0x29
/*  f198198:	1521000a */ 	bne	$t1,$at,.PB0f1981c4
/*  f19819c:	00000000 */ 	nop
/*  f1981a0:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f1981a4:	10a00007 */ 	beqz	$a1,.PB0f1981c4
/*  f1981a8:	00000000 */ 	nop
/*  f1981ac:	8caa0018 */ 	lw	$t2,0x18($a1)
/*  f1981b0:	15400004 */ 	bnez	$t2,.PB0f1981c4
/*  f1981b4:	00000000 */ 	nop
/*  f1981b8:	84ad0002 */ 	lh	$t5,0x2($a1)
/*  f1981bc:	11a00162 */ 	beqz	$t5,.PB0f198748
/*  f1981c0:	00000000 */ 	nop
.PB0f1981c4:
/*  f1981c4:	10000160 */ 	b	.PB0f198748
/*  f1981c8:	a28b02a0 */ 	sb	$t3,0x2a0($s4)
/*  f1981cc:	2401002f */ 	li	$at,0x2f
.PB0f1981d0:
/*  f1981d0:	5441003f */ 	bnel	$v0,$at,.PB0f1982d0
/*  f1981d4:	24010032 */ 	li	$at,0x32
/*  f1981d8:	86420008 */ 	lh	$v0,0x8($s2)
/*  f1981dc:	3c04800b */ 	lui	$a0,0x800b
/*  f1981e0:	04400011 */ 	bltz	$v0,.PB0f198228
/*  f1981e4:	00027080 */ 	sll	$t6,$v0,0x2
/*  f1981e8:	008e2021 */ 	addu	$a0,$a0,$t6
/*  f1981ec:	0fc0e6e9 */ 	jal	chrIsDead
/*  f1981f0:	8c840af0 */ 	lw	$a0,0xaf0($a0)
/*  f1981f4:	5440000a */ 	bnezl	$v0,.PB0f198220
/*  f1981f8:	240f0029 */ 	li	$t7,0x29
/*  f1981fc:	864c0008 */ 	lh	$t4,0x8($s2)
/*  f198200:	3c05800b */ 	lui	$a1,0x800b
/*  f198204:	02802025 */ 	move	$a0,$s4
/*  f198208:	000cc080 */ 	sll	$t8,$t4,0x2
/*  f19820c:	00b82821 */ 	addu	$a1,$a1,$t8
/*  f198210:	0fc65258 */ 	jal	botPassesCowardCheck
/*  f198214:	8ca50af0 */ 	lw	$a1,0xaf0($a1)
/*  f198218:	14400003 */ 	bnez	$v0,.PB0f198228
/*  f19821c:	240f0029 */ 	li	$t7,0x29
.PB0f198220:
/*  f198220:	10000149 */ 	b	.PB0f198748
/*  f198224:	a28f02a0 */ 	sb	$t7,0x2a0($s4)
.PB0f198228:
/*  f198228:	86590008 */ 	lh	$t9,0x8($s2)
/*  f19822c:	07210013 */ 	bgez	$t9,.PB0f19827c
/*  f198230:	00000000 */ 	nop
/*  f198234:	8689017e */ 	lh	$t1,0x17e($s4)
/*  f198238:	53c9000e */ 	beql	$s8,$t1,.PB0f198274
/*  f19823c:	240a0029 */ 	li	$t2,0x29
/*  f198240:	0fc0a255 */ 	jal	chrGetTargetProp
/*  f198244:	02802025 */ 	move	$a0,$s4
/*  f198248:	0fc0e6e9 */ 	jal	chrIsDead
/*  f19824c:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f198250:	54400008 */ 	bnezl	$v0,.PB0f198274
/*  f198254:	240a0029 */ 	li	$t2,0x29
/*  f198258:	0fc0a255 */ 	jal	chrGetTargetProp
/*  f19825c:	02802025 */ 	move	$a0,$s4
/*  f198260:	02802025 */ 	move	$a0,$s4
/*  f198264:	0fc65258 */ 	jal	botPassesCowardCheck
/*  f198268:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f19826c:	14400003 */ 	bnez	$v0,.PB0f19827c
/*  f198270:	240a0029 */ 	li	$t2,0x29
.PB0f198274:
/*  f198274:	10000134 */ 	b	.PB0f198748
/*  f198278:	a28a02a0 */ 	sb	$t2,0x2a0($s4)
.PB0f19827c:
/*  f19827c:	0fc66478 */ 	jal	botcmdTickDistMode
/*  f198280:	02802025 */ 	move	$a0,$s4
/*  f198284:	0fc65886 */ 	jal	botCanDoCriticalPickup
/*  f198288:	02802025 */ 	move	$a0,$s4
/*  f19828c:	10400003 */ 	beqz	$v0,.PB0f19829c
/*  f198290:	240d0029 */ 	li	$t5,0x29
/*  f198294:	1000012c */ 	b	.PB0f198748
/*  f198298:	a28d02a0 */ 	sb	$t5,0x2a0($s4)
.PB0f19829c:
/*  f19829c:	8e4201d8 */ 	lw	$v0,0x1d8($s2)
/*  f1982a0:	04400129 */ 	bltz	$v0,.PB0f198748
/*  f1982a4:	00000000 */ 	nop
/*  f1982a8:	8ece0008 */ 	lw	$t6,0x8($s6)
/*  f1982ac:	8e4b0120 */ 	lw	$t3,0x120($s2)
/*  f1982b0:	24180029 */ 	li	$t8,0x29
/*  f1982b4:	01c26023 */ 	subu	$t4,$t6,$v0
/*  f1982b8:	016c082a */ 	slt	$at,$t3,$t4
/*  f1982bc:	10200122 */ 	beqz	$at,.PB0f198748
/*  f1982c0:	00000000 */ 	nop
/*  f1982c4:	10000120 */ 	b	.PB0f198748
/*  f1982c8:	a29802a0 */ 	sb	$t8,0x2a0($s4)
/*  f1982cc:	24010032 */ 	li	$at,0x32
.PB0f1982d0:
/*  f1982d0:	5441004e */ 	bnel	$v0,$at,.PB0f19840c
/*  f1982d4:	24010033 */ 	li	$at,0x33
/*  f1982d8:	8642000a */ 	lh	$v0,0xa($s2)
/*  f1982dc:	3c04800b */ 	lui	$a0,0x800b
/*  f1982e0:	04400005 */ 	bltz	$v0,.PB0f1982f8
/*  f1982e4:	00027880 */ 	sll	$t7,$v0,0x2
/*  f1982e8:	008f2021 */ 	addu	$a0,$a0,$t7
/*  f1982ec:	0fc0e6e9 */ 	jal	chrIsDead
/*  f1982f0:	8c840af0 */ 	lw	$a0,0xaf0($a0)
/*  f1982f4:	10400003 */ 	beqz	$v0,.PB0f198304
.PB0f1982f8:
/*  f1982f8:	24190029 */ 	li	$t9,0x29
/*  f1982fc:	10000112 */ 	b	.PB0f198748
/*  f198300:	a29902a0 */ 	sb	$t9,0x2a0($s4)
.PB0f198304:
/*  f198304:	0fc66478 */ 	jal	botcmdTickDistMode
/*  f198308:	02802025 */ 	move	$a0,$s4
/*  f19830c:	8e4901e0 */ 	lw	$t1,0x1e0($s2)
/*  f198310:	11200037 */ 	beqz	$t1,.PB0f1983f0
/*  f198314:	00000000 */ 	nop
/*  f198318:	868a017e */ 	lh	$t2,0x17e($s4)
/*  f19831c:	13ca0034 */ 	beq	$s8,$t2,.PB0f1983f0
/*  f198320:	00000000 */ 	nop
/*  f198324:	8e4d0128 */ 	lw	$t5,0x128($s2)
/*  f198328:	11a00031 */ 	beqz	$t5,.PB0f1983f0
/*  f19832c:	00000000 */ 	nop
/*  f198330:	0fc0a255 */ 	jal	chrGetTargetProp
/*  f198334:	02802025 */ 	move	$a0,$s4
/*  f198338:	02802025 */ 	move	$a0,$s4
/*  f19833c:	0fc65258 */ 	jal	botPassesCowardCheck
/*  f198340:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f198344:	1040002a */ 	beqz	$v0,.PB0f1983f0
/*  f198348:	3c0143fa */ 	lui	$at,0x43fa
/*  f19834c:	864e000a */ 	lh	$t6,0xa($s2)
/*  f198350:	3c0c800b */ 	lui	$t4,0x800b
/*  f198354:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f198358:	000e5880 */ 	sll	$t3,$t6,0x2
/*  f19835c:	018b6021 */ 	addu	$t4,$t4,$t3
/*  f198360:	8d8c0af0 */ 	lw	$t4,0xaf0($t4)
/*  f198364:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f198368:	44806000 */ 	mtc1	$zero,$f12
/*  f19836c:	8d82001c */ 	lw	$v0,0x1c($t4)
/*  f198370:	c46a0010 */ 	lwc1	$f10,0x10($v1)
/*  f198374:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*  f198378:	c4520010 */ 	lwc1	$f18,0x10($v0)
/*  f19837c:	46064001 */ 	sub.s	$f0,$f8,$f6
/*  f198380:	46125081 */ 	sub.s	$f2,$f10,$f18
/*  f198384:	460c003c */ 	c.lt.s	$f0,$f12
/*  f198388:	00000000 */ 	nop
/*  f19838c:	45020003 */ 	bc1fl	.PB0f19839c
/*  f198390:	460c103c */ 	c.lt.s	$f2,$f12
/*  f198394:	46000007 */ 	neg.s	$f0,$f0
/*  f198398:	460c103c */ 	c.lt.s	$f2,$f12
.PB0f19839c:
/*  f19839c:	44816000 */ 	mtc1	$at,$f12
/*  f1983a0:	45020003 */ 	bc1fl	.PB0f1983b0
/*  f1983a4:	460c003c */ 	c.lt.s	$f0,$f12
/*  f1983a8:	46001087 */ 	neg.s	$f2,$f2
/*  f1983ac:	460c003c */ 	c.lt.s	$f0,$f12
.PB0f1983b0:
/*  f1983b0:	00000000 */ 	nop
/*  f1983b4:	4500000e */ 	bc1f	.PB0f1983f0
/*  f1983b8:	00000000 */ 	nop
/*  f1983bc:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1983c0:	2418002f */ 	li	$t8,0x2f
/*  f1983c4:	02802025 */ 	move	$a0,$s4
/*  f1983c8:	45000009 */ 	bc1f	.PB0f1983f0
/*  f1983cc:	00000000 */ 	nop
/*  f1983d0:	0fc0a255 */ 	jal	chrGetTargetProp
/*  f1983d4:	a29802a0 */ 	sb	$t8,0x2a0($s4)
/*  f1983d8:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f1983dc:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f1983e0:	240f00fa */ 	li	$t7,0xfa
/*  f1983e4:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f1983e8:	ae4f01d8 */ 	sw	$t7,0x1d8($s2)
/*  f1983ec:	a25e0074 */ 	sb	$s8,0x74($s2)
.PB0f1983f0:
/*  f1983f0:	0fc65886 */ 	jal	botCanDoCriticalPickup
/*  f1983f4:	02802025 */ 	move	$a0,$s4
/*  f1983f8:	104000d3 */ 	beqz	$v0,.PB0f198748
/*  f1983fc:	24190029 */ 	li	$t9,0x29
/*  f198400:	100000d1 */ 	b	.PB0f198748
/*  f198404:	a29902a0 */ 	sb	$t9,0x2a0($s4)
/*  f198408:	24010033 */ 	li	$at,0x33
.PB0f19840c:
/*  f19840c:	54410063 */ 	bnel	$v0,$at,.PB0f19859c
/*  f198410:	2401002b */ 	li	$at,0x2b
/*  f198414:	82890007 */ 	lb	$t1,0x7($s4)
/*  f198418:	2401000f */ 	li	$at,0xf
/*  f19841c:	11210058 */ 	beq	$t1,$at,.PB0f198580
/*  f198420:	00000000 */ 	nop
/*  f198424:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f198428:	c648008c */ 	lwc1	$f8,0x8c($s2)
/*  f19842c:	44807000 */ 	mtc1	$zero,$f14
/*  f198430:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f198434:	c64a0090 */ 	lwc1	$f10,0x90($s2)
/*  f198438:	c466000c */ 	lwc1	$f6,0xc($v1)
/*  f19843c:	46082001 */ 	sub.s	$f0,$f4,$f8
/*  f198440:	c6440094 */ 	lwc1	$f4,0x94($s2)
/*  f198444:	c4720010 */ 	lwc1	$f18,0x10($v1)
/*  f198448:	3c014220 */ 	lui	$at,0x4220
/*  f19844c:	460e003c */ 	c.lt.s	$f0,$f14
/*  f198450:	460a3081 */ 	sub.s	$f2,$f6,$f10
/*  f198454:	45000002 */ 	bc1f	.PB0f198460
/*  f198458:	46049301 */ 	sub.s	$f12,$f18,$f4
/*  f19845c:	46000007 */ 	neg.s	$f0,$f0
.PB0f198460:
/*  f198460:	460e103c */ 	c.lt.s	$f2,$f14
/*  f198464:	00000000 */ 	nop
/*  f198468:	45020003 */ 	bc1fl	.PB0f198478
/*  f19846c:	460e603c */ 	c.lt.s	$f12,$f14
/*  f198470:	46001087 */ 	neg.s	$f2,$f2
/*  f198474:	460e603c */ 	c.lt.s	$f12,$f14
.PB0f198478:
/*  f198478:	44817000 */ 	mtc1	$at,$f14
/*  f19847c:	45020003 */ 	bc1fl	.PB0f19848c
/*  f198480:	8e4200dc */ 	lw	$v0,0xdc($s2)
/*  f198484:	46006307 */ 	neg.s	$f12,$f12
/*  f198488:	8e4200dc */ 	lw	$v0,0xdc($s2)
.PB0f19848c:
/*  f19848c:	58400005 */ 	blezl	$v0,.PB0f1984a4
/*  f198490:	4600703c */ 	c.lt.s	$f14,$f0
/*  f198494:	8eca0038 */ 	lw	$t2,0x38($s6)
/*  f198498:	004a6823 */ 	subu	$t5,$v0,$t2
/*  f19849c:	ae4d00dc */ 	sw	$t5,0xdc($s2)
/*  f1984a0:	4600703c */ 	c.lt.s	$f14,$f0
.PB0f1984a4:
/*  f1984a4:	00000000 */ 	nop
/*  f1984a8:	4503000f */ 	bc1tl	.PB0f1984e8
/*  f1984ac:	8e4c00dc */ 	lw	$t4,0xdc($s2)
/*  f1984b0:	460c703c */ 	c.lt.s	$f14,$f12
/*  f1984b4:	3c014348 */ 	lui	$at,0x4348
/*  f1984b8:	4503000b */ 	bc1tl	.PB0f1984e8
/*  f1984bc:	8e4c00dc */ 	lw	$t4,0xdc($s2)
/*  f1984c0:	44814000 */ 	mtc1	$at,$f8
/*  f1984c4:	00000000 */ 	nop
/*  f1984c8:	4602403c */ 	c.lt.s	$f8,$f2
/*  f1984cc:	00000000 */ 	nop
/*  f1984d0:	4502000e */ 	bc1fl	.PB0f19850c
/*  f1984d4:	8e5801dc */ 	lw	$t8,0x1dc($s2)
/*  f1984d8:	828b032d */ 	lb	$t3,0x32d($s4)
/*  f1984dc:	0562000b */ 	bltzl	$t3,.PB0f19850c
/*  f1984e0:	8e5801dc */ 	lw	$t8,0x1dc($s2)
/*  f1984e4:	8e4c00dc */ 	lw	$t4,0xdc($s2)
.PB0f1984e8:
/*  f1984e8:	02802025 */ 	move	$a0,$s4
/*  f1984ec:	2645008c */ 	addiu	$a1,$s2,0x8c
/*  f1984f0:	1d80001e */ 	bgtz	$t4,.PB0f19856c
/*  f1984f4:	2646007a */ 	addiu	$a2,$s2,0x7a
/*  f1984f8:	0fc0e153 */ 	jal	chrGoToPos
/*  f1984fc:	24070002 */ 	li	$a3,0x2
/*  f198500:	1000001b */ 	b	.PB0f198570
/*  f198504:	8e4d00dc */ 	lw	$t5,0xdc($s2)
/*  f198508:	8e5801dc */ 	lw	$t8,0x1dc($s2)
.PB0f19850c:
/*  f19850c:	53000018 */ 	beqzl	$t8,.PB0f198570
/*  f198510:	8e4d00dc */ 	lw	$t5,0xdc($s2)
/*  f198514:	868f017e */ 	lh	$t7,0x17e($s4)
/*  f198518:	53cf0015 */ 	beql	$s8,$t7,.PB0f198570
/*  f19851c:	8e4d00dc */ 	lw	$t5,0xdc($s2)
/*  f198520:	8e590128 */ 	lw	$t9,0x128($s2)
/*  f198524:	53200012 */ 	beqzl	$t9,.PB0f198570
/*  f198528:	8e4d00dc */ 	lw	$t5,0xdc($s2)
/*  f19852c:	0fc0a255 */ 	jal	chrGetTargetProp
/*  f198530:	02802025 */ 	move	$a0,$s4
/*  f198534:	02802025 */ 	move	$a0,$s4
/*  f198538:	0fc65258 */ 	jal	botPassesCowardCheck
/*  f19853c:	8c450004 */ 	lw	$a1,0x4($v0)
/*  f198540:	1040000a */ 	beqz	$v0,.PB0f19856c
/*  f198544:	2409002f */ 	li	$t1,0x2f
/*  f198548:	a28902a0 */ 	sb	$t1,0x2a0($s4)
/*  f19854c:	0fc0a255 */ 	jal	chrGetTargetProp
/*  f198550:	02802025 */ 	move	$a0,$s4
/*  f198554:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f198558:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f19855c:	240a00fa */ 	li	$t2,0xfa
/*  f198560:	a6420008 */ 	sh	$v0,0x8($s2)
/*  f198564:	ae4a01d8 */ 	sw	$t2,0x1d8($s2)
/*  f198568:	a25e0074 */ 	sb	$s8,0x74($s2)
.PB0f19856c:
/*  f19856c:	8e4d00dc */ 	lw	$t5,0xdc($s2)
.PB0f198570:
/*  f198570:	240e0032 */ 	li	$t6,0x32
/*  f198574:	1da00002 */ 	bgtz	$t5,.PB0f198580
/*  f198578:	00000000 */ 	nop
/*  f19857c:	ae4e00dc */ 	sw	$t6,0xdc($s2)
.PB0f198580:
/*  f198580:	0fc65886 */ 	jal	botCanDoCriticalPickup
/*  f198584:	02802025 */ 	move	$a0,$s4
/*  f198588:	1040006f */ 	beqz	$v0,.PB0f198748
/*  f19858c:	240b0029 */ 	li	$t3,0x29
/*  f198590:	1000006d */ 	b	.PB0f198748
/*  f198594:	a28b02a0 */ 	sb	$t3,0x2a0($s4)
/*  f198598:	2401002b */ 	li	$at,0x2b
.PB0f19859c:
/*  f19859c:	1441002f */ 	bne	$v0,$at,.PB0f19865c
/*  f1985a0:	3c0c800b */ 	lui	$t4,0x800b
/*  f1985a4:	918c11b8 */ 	lbu	$t4,0x11b8($t4)
/*  f1985a8:	24010004 */ 	li	$at,0x4
/*  f1985ac:	5581001f */ 	bnel	$t4,$at,.PB0f19862c
/*  f1985b0:	828b0007 */ 	lb	$t3,0x7($s4)
/*  f1985b4:	8e58004c */ 	lw	$t8,0x4c($s2)
/*  f1985b8:	3c02800b */ 	lui	$v0,0x800b
/*  f1985bc:	00187fc2 */ 	srl	$t7,$t8,0x1f
/*  f1985c0:	51e0001a */ 	beqzl	$t7,.PB0f19862c
/*  f1985c4:	828b0007 */ 	lb	$t3,0x7($s4)
/*  f1985c8:	8442073e */ 	lh	$v0,0x73e($v0)
/*  f1985cc:	8e5900bc */ 	lw	$t9,0xbc($s2)
/*  f1985d0:	53220006 */ 	beql	$t9,$v0,.PB0f1985ec
/*  f1985d4:	8e8d001c */ 	lw	$t5,0x1c($s4)
/*  f1985d8:	9249004c */ 	lbu	$t1,0x4c($s2)
/*  f1985dc:	312aff7f */ 	andi	$t2,$t1,0xff7f
/*  f1985e0:	10000011 */ 	b	.PB0f198628
/*  f1985e4:	a24a004c */ 	sb	$t2,0x4c($s2)
/*  f1985e8:	8e8d001c */ 	lw	$t5,0x1c($s4)
.PB0f1985ec:
/*  f1985ec:	85ae0028 */ 	lh	$t6,0x28($t5)
/*  f1985f0:	51c2000e */ 	beql	$t6,$v0,.PB0f19862c
/*  f1985f4:	828b0007 */ 	lb	$t3,0x7($s4)
/*  f1985f8:	86440048 */ 	lh	$a0,0x48($s2)
/*  f1985fc:	04820006 */ 	bltzl	$a0,.PB0f198618
/*  f198600:	8644004a */ 	lh	$a0,0x4a($s2)
/*  f198604:	0fc45ab8 */ 	jal	padSetFlag
/*  f198608:	3c050002 */ 	lui	$a1,0x2
/*  f19860c:	10000007 */ 	b	.PB0f19862c
/*  f198610:	828b0007 */ 	lb	$t3,0x7($s4)
/*  f198614:	8644004a */ 	lh	$a0,0x4a($s2)
.PB0f198618:
/*  f198618:	04820004 */ 	bltzl	$a0,.PB0f19862c
/*  f19861c:	828b0007 */ 	lb	$t3,0x7($s4)
/*  f198620:	0fc45b6a */ 	jal	coverSetFlag
/*  f198624:	24050100 */ 	li	$a1,0x100
.PB0f198628:
/*  f198628:	828b0007 */ 	lb	$t3,0x7($s4)
.PB0f19862c:
/*  f19862c:	2401000f */ 	li	$at,0xf
/*  f198630:	240c0029 */ 	li	$t4,0x29
/*  f198634:	11610003 */ 	beq	$t3,$at,.PB0f198644
/*  f198638:	00000000 */ 	nop
/*  f19863c:	10000042 */ 	b	.PB0f198748
/*  f198640:	a28c02a0 */ 	sb	$t4,0x2a0($s4)
.PB0f198644:
/*  f198644:	0fc65886 */ 	jal	botCanDoCriticalPickup
/*  f198648:	02802025 */ 	move	$a0,$s4
/*  f19864c:	1040003e */ 	beqz	$v0,.PB0f198748
/*  f198650:	24180029 */ 	li	$t8,0x29
/*  f198654:	1000003c */ 	b	.PB0f198748
/*  f198658:	a29802a0 */ 	sb	$t8,0x2a0($s4)
.PB0f19865c:
/*  f19865c:	2401002c */ 	li	$at,0x2c
/*  f198660:	54410029 */ 	bnel	$v0,$at,.PB0f198708
/*  f198664:	2401002e */ 	li	$at,0x2e
/*  f198668:	0fc65886 */ 	jal	botCanDoCriticalPickup
/*  f19866c:	02802025 */ 	move	$a0,$s4
/*  f198670:	10400003 */ 	beqz	$v0,.PB0f198680
/*  f198674:	240f0029 */ 	li	$t7,0x29
/*  f198678:	10000033 */ 	b	.PB0f198748
/*  f19867c:	a28f02a0 */ 	sb	$t7,0x2a0($s4)
.PB0f198680:
/*  f198680:	82990007 */ 	lb	$t9,0x7($s4)
/*  f198684:	2401000f */ 	li	$at,0xf
/*  f198688:	240a0029 */ 	li	$t2,0x29
/*  f19868c:	17210008 */ 	bne	$t9,$at,.PB0f1986b0
/*  f198690:	00000000 */ 	nop
/*  f198694:	8e450010 */ 	lw	$a1,0x10($s2)
/*  f198698:	10a00005 */ 	beqz	$a1,.PB0f1986b0
/*  f19869c:	00000000 */ 	nop
/*  f1986a0:	8ca90018 */ 	lw	$t1,0x18($a1)
/*  f1986a4:	3c03800b */ 	lui	$v1,0x800b
/*  f1986a8:	11200003 */ 	beqz	$t1,.PB0f1986b8
/*  f1986ac:	00000000 */ 	nop
.PB0f1986b0:
/*  f1986b0:	10000025 */ 	b	.PB0f198748
/*  f1986b4:	a28a02a0 */ 	sb	$t2,0x2a0($s4)
.PB0f1986b8:
/*  f1986b8:	906311b8 */ 	lbu	$v1,0x11b8($v1)
/*  f1986bc:	24010002 */ 	li	$at,0x2
/*  f1986c0:	12e30021 */ 	beq	$s7,$v1,.PB0f198748
/*  f1986c4:	00000000 */ 	nop
/*  f1986c8:	1461001f */ 	bne	$v1,$at,.PB0f198748
/*  f1986cc:	3c0d800b */ 	lui	$t5,0x800b
/*  f1986d0:	8dad086c */ 	lw	$t5,0x86c($t5)
/*  f1986d4:	8e8e001c */ 	lw	$t6,0x1c($s4)
/*  f1986d8:	15ae001b */ 	bne	$t5,$t6,.PB0f198748
/*  f1986dc:	00000000 */ 	nop
/*  f1986e0:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f1986e4:	02802025 */ 	move	$a0,$s4
/*  f1986e8:	3c0b800b */ 	lui	$t3,0x800b
/*  f1986ec:	856b0802 */ 	lh	$t3,0x802($t3)
/*  f1986f0:	240c0029 */ 	li	$t4,0x29
/*  f1986f4:	144b0014 */ 	bne	$v0,$t3,.PB0f198748
/*  f1986f8:	00000000 */ 	nop
/*  f1986fc:	10000012 */ 	b	.PB0f198748
/*  f198700:	a28c02a0 */ 	sb	$t4,0x2a0($s4)
/*  f198704:	2401002e */ 	li	$at,0x2e
.PB0f198708:
/*  f198708:	1441000f */ 	bne	$v0,$at,.PB0f198748
/*  f19870c:	00000000 */ 	nop
/*  f198710:	0fc65886 */ 	jal	botCanDoCriticalPickup
/*  f198714:	02802025 */ 	move	$a0,$s4
/*  f198718:	10400003 */ 	beqz	$v0,.PB0f198728
/*  f19871c:	24180029 */ 	li	$t8,0x29
/*  f198720:	10000009 */ 	b	.PB0f198748
/*  f198724:	a29802a0 */ 	sb	$t8,0x2a0($s4)
.PB0f198728:
/*  f198728:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f19872c:	02802025 */ 	move	$a0,$s4
/*  f198730:	3c0f800b */ 	lui	$t7,0x800b
/*  f198734:	85ef0802 */ 	lh	$t7,0x802($t7)
/*  f198738:	24190029 */ 	li	$t9,0x29
/*  f19873c:	104f0002 */ 	beq	$v0,$t7,.PB0f198748
/*  f198740:	00000000 */ 	nop
/*  f198744:	a29902a0 */ 	sb	$t9,0x2a0($s4)
.PB0f198748:
/*  f198748:	0fc6528c */ 	jal	botChooseGeneralTarget
/*  f19874c:	02802025 */ 	move	$a0,$s4
/*  f198750:	0fc63af1 */ 	jal	mpPlayerGetIndex
/*  f198754:	02802025 */ 	move	$a0,$s4
/*  f198758:	8ec9000c */ 	lw	$t1,0xc($s6)
/*  f19875c:	8e6a0000 */ 	lw	$t2,0x0($s3)
/*  f198760:	012a001a */ 	div	$zero,$t1,$t2
/*  f198764:	00006810 */ 	mfhi	$t5
/*  f198768:	15400002 */ 	bnez	$t2,.PB0f198774
/*  f19876c:	00000000 */ 	nop
/*  f198770:	0007000d */ 	break	0x7
.PB0f198774:
/*  f198774:	2401ffff */ 	li	$at,-1
/*  f198778:	15410004 */ 	bne	$t2,$at,.PB0f19878c
/*  f19877c:	3c018000 */ 	lui	$at,0x8000
/*  f198780:	15210002 */ 	bne	$t1,$at,.PB0f19878c
/*  f198784:	00000000 */ 	nop
/*  f198788:	0006000d */ 	break	0x6
.PB0f19878c:
/*  f19878c:	144d0024 */ 	bne	$v0,$t5,.PB0f198820
/*  f198790:	00000000 */ 	nop
/*  f198794:	868e017e */ 	lh	$t6,0x17e($s4)
/*  f198798:	13ce0021 */ 	beq	$s8,$t6,.PB0f198820
/*  f19879c:	00000000 */ 	nop
/*  f1987a0:	0fc0a255 */ 	jal	chrGetTargetProp
/*  f1987a4:	02802025 */ 	move	$a0,$s4
/*  f1987a8:	8e83001c */ 	lw	$v1,0x1c($s4)
/*  f1987ac:	00408025 */ 	move	$s0,$v0
/*  f1987b0:	24640008 */ 	addiu	$a0,$v1,0x8
/*  f1987b4:	0fc452bd */ 	jal	waypointFindClosestToPos
/*  f1987b8:	24650028 */ 	addiu	$a1,$v1,0x28
/*  f1987bc:	00408825 */ 	move	$s1,$v0
/*  f1987c0:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f1987c4:	0fc452bd */ 	jal	waypointFindClosestToPos
/*  f1987c8:	26050028 */ 	addiu	$a1,$s0,0x28
/*  f1987cc:	12200014 */ 	beqz	$s1,.PB0f198820
/*  f1987d0:	00408025 */ 	move	$s0,$v0
/*  f1987d4:	10400012 */ 	beqz	$v0,.PB0f198820
/*  f1987d8:	00000000 */ 	nop
/*  f1987dc:	8ecb0008 */ 	lw	$t3,0x8($s6)
/*  f1987e0:	868f0000 */ 	lh	$t7,0x0($s4)
/*  f1987e4:	000b6243 */ 	sra	$t4,$t3,0x9
/*  f1987e8:	000cc1c0 */ 	sll	$t8,$t4,0x7
/*  f1987ec:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f1987f0:	03192021 */ 	addu	$a0,$t8,$t9
/*  f1987f4:	0fc452b8 */ 	jal	waypointSetHashThing
/*  f1987f8:	00802825 */ 	move	$a1,$a0
/*  f1987fc:	02002025 */ 	move	$a0,$s0
/*  f198800:	02202825 */ 	move	$a1,$s1
/*  f198804:	264601e8 */ 	addiu	$a2,$s2,0x1e8
/*  f198808:	0fc456a3 */ 	jal	waypointFindRoute
/*  f19880c:	24070008 */ 	li	$a3,0x8
/*  f198810:	ae420208 */ 	sw	$v0,0x208($s2)
/*  f198814:	00002025 */ 	move	$a0,$zero
/*  f198818:	0fc452b8 */ 	jal	waypointSetHashThing
/*  f19881c:	00002825 */ 	move	$a1,$zero
.PB0f198820:
/*  f198820:	0fc66ab3 */ 	jal	botinvTick
/*  f198824:	02802025 */ 	move	$a0,$s4
/*  f198828:	afa00088 */ 	sw	$zero,0x88($sp)
/*  f19882c:	00009825 */ 	move	$s3,$zero
/*  f198830:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f198834:	02408825 */ 	move	$s1,$s2
.PB0f198838:
/*  f198838:	8e22005c */ 	lw	$v0,0x5c($s1)
/*  f19883c:	0000a825 */ 	move	$s5,$zero
/*  f198840:	18400004 */ 	blez	$v0,.PB0f198854
/*  f198844:	00000000 */ 	nop
/*  f198848:	8ec90038 */ 	lw	$t1,0x38($s6)
/*  f19884c:	00495023 */ 	subu	$t2,$v0,$t1
/*  f198850:	ae2a005c */ 	sw	$t2,0x5c($s1)
.PB0f198854:
/*  f198854:	16770004 */ 	bne	$s3,$s7,.PB0f198868
/*  f198858:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f19885c:	51a00003 */ 	beqzl	$t5,.PB0f19886c
/*  f198860:	8e4e0044 */ 	lw	$t6,0x44($s2)
/*  f198864:	ae37005c */ 	sw	$s7,0x5c($s1)
.PB0f198868:
/*  f198868:	8e4e0044 */ 	lw	$t6,0x44($s2)
.PB0f19886c:
/*  f19886c:	15c00212 */ 	bnez	$t6,.PB0f1990b8
/*  f198870:	00000000 */ 	nop
/*  f198874:	8e4b00cc */ 	lw	$t3,0xcc($s2)
/*  f198878:	1d60020f */ 	bgtz	$t3,.PB0f1990b8
/*  f19887c:	00000000 */ 	nop
/*  f198880:	8e42004c */ 	lw	$v0,0x4c($s2)
/*  f198884:	0013c040 */ 	sll	$t8,$s3,0x1
/*  f198888:	02581821 */ 	addu	$v1,$s2,$t8
/*  f19888c:	00027840 */ 	sll	$t7,$v0,0x1
/*  f198890:	05e300b5 */ 	bgezl	$t7,.PB0f198b68
/*  f198894:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198898:	8479003c */ 	lh	$t9,0x3c($v1)
/*  f19889c:	07200206 */ 	bltz	$t9,.PB0f1990b8
/*  f1988a0:	00000000 */ 	nop
/*  f1988a4:	8469002c */ 	lh	$t1,0x2c($v1)
/*  f1988a8:	1d200203 */ 	bgtz	$t1,.PB0f1990b8
/*  f1988ac:	00000000 */ 	nop
/*  f1988b0:	8e4a0020 */ 	lw	$t2,0x20($s2)
/*  f1988b4:	2401001c */ 	li	$at,0x1c
/*  f1988b8:	2404001c */ 	li	$a0,0x1c
/*  f1988bc:	1541000d */ 	bne	$t2,$at,.PB0f1988f4
/*  f1988c0:	02e02825 */ 	move	$a1,$s7
/*  f1988c4:	0fc26da8 */ 	jal	bgunGetMinClipQty
/*  f1988c8:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f1988cc:	8e2d0024 */ 	lw	$t5,0x24($s1)
/*  f1988d0:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f1988d4:	02802025 */ 	move	$a0,$s4
/*  f1988d8:	01a2082a */ 	slt	$at,$t5,$v0
/*  f1988dc:	10200005 */ 	beqz	$at,.PB0f1988f4
/*  f1988e0:	02602825 */ 	move	$a1,$s3
/*  f1988e4:	0fc6548f */ 	jal	botScheduleReload
/*  f1988e8:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f1988ec:	100001f2 */ 	b	.PB0f1990b8
/*  f1988f0:	00000000 */ 	nop
.PB0f1988f4:
/*  f1988f4:	846e003c */ 	lh	$t6,0x3c($v1)
/*  f1988f8:	8ecb0038 */ 	lw	$t3,0x38($s6)
/*  f1988fc:	01cb6023 */ 	subu	$t4,$t6,$t3
/*  f198900:	a46c003c */ 	sh	$t4,0x3c($v1)
/*  f198904:	868f017e */ 	lh	$t7,0x17e($s4)
/*  f198908:	53cf0042 */ 	beql	$s8,$t7,.PB0f198a14
/*  f19890c:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f198910:	8e580128 */ 	lw	$t8,0x128($s2)
/*  f198914:	5300003f */ 	beqzl	$t8,.PB0f198a14
/*  f198918:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f19891c:	8e490004 */ 	lw	$t1,0x4($s2)
/*  f198920:	3c0e8009 */ 	lui	$t6,0x8009
/*  f198924:	8e59011c */ 	lw	$t9,0x11c($s2)
/*  f198928:	912a0048 */ 	lbu	$t2,0x48($t1)
/*  f19892c:	02802025 */ 	move	$a0,$s4
/*  f198930:	000a6940 */ 	sll	$t5,$t2,0x5
/*  f198934:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f198938:	91cea1f4 */ 	lbu	$t6,-0x5e0c($t6)
/*  f19893c:	032e082a */ 	slt	$at,$t9,$t6
/*  f198940:	54200034 */ 	bnezl	$at,.PB0f198a14
/*  f198944:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f198948:	0fc64784 */ 	jal	botIsDizzy
/*  f19894c:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f198950:	14400030 */ 	bnez	$v0,.PB0f198a14
/*  f198954:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f198958:	8e4b0020 */ 	lw	$t3,0x20($s2)
/*  f19895c:	2401001c */ 	li	$at,0x1c
/*  f198960:	02802025 */ 	move	$a0,$s4
/*  f198964:	15610014 */ 	bne	$t3,$at,.PB0f1989b8
/*  f198968:	24050028 */ 	li	$a1,0x28
/*  f19896c:	02802025 */ 	move	$a0,$s4
/*  f198970:	2405001e */ 	li	$a1,0x1e
/*  f198974:	00003025 */ 	move	$a2,$zero
/*  f198978:	0fc12463 */ 	jal	chrIsTargetInFov
/*  f19897c:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f198980:	1040000b */ 	beqz	$v0,.PB0f1989b0
/*  f198984:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f198988:	02802025 */ 	move	$a0,$s4
/*  f19898c:	0fc124bb */ 	jal	chrGetDistanceToTarget
/*  f198990:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f198994:	3c014352 */ 	lui	$at,0x4352
/*  f198998:	44813000 */ 	mtc1	$at,$f6
/*  f19899c:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f1989a0:	4600303c */ 	c.lt.s	$f6,$f0
/*  f1989a4:	00000000 */ 	nop
/*  f1989a8:	4502001b */ 	bc1fl	.PB0f198a18
/*  f1989ac:	846c003c */ 	lh	$t4,0x3c($v1)
.PB0f1989b0:
/*  f1989b0:	10000018 */ 	b	.PB0f198a14
/*  f1989b4:	a460003c */ 	sh	$zero,0x3c($v1)
.PB0f1989b8:
/*  f1989b8:	00003025 */ 	move	$a2,$zero
/*  f1989bc:	0fc12463 */ 	jal	chrIsTargetInFov
/*  f1989c0:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f1989c4:	10400010 */ 	beqz	$v0,.PB0f198a08
/*  f1989c8:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f1989cc:	3c014352 */ 	lui	$at,0x4352
/*  f1989d0:	44815000 */ 	mtc1	$at,$f10
/*  f1989d4:	3c014316 */ 	lui	$at,0x4316
/*  f1989d8:	44819000 */ 	mtc1	$at,$f18
/*  f1989dc:	02802025 */ 	move	$a0,$s4
/*  f1989e0:	afa30054 */ 	sw	$v1,0x54($sp)
/*  f1989e4:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f1989e8:	0fc124bb */ 	jal	chrGetDistanceToTarget
/*  f1989ec:	e7a40050 */ 	swc1	$f4,0x50($sp)
/*  f1989f0:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f1989f4:	8fa30054 */ 	lw	$v1,0x54($sp)
/*  f1989f8:	4600403c */ 	c.lt.s	$f8,$f0
/*  f1989fc:	00000000 */ 	nop
/*  f198a00:	45020005 */ 	bc1fl	.PB0f198a18
/*  f198a04:	846c003c */ 	lh	$t4,0x3c($v1)
.PB0f198a08:
/*  f198a08:	10000002 */ 	b	.PB0f198a14
/*  f198a0c:	a460003c */ 	sh	$zero,0x3c($v1)
/*  f198a10:	a460003c */ 	sh	$zero,0x3c($v1)
.PB0f198a14:
/*  f198a14:	846c003c */ 	lh	$t4,0x3c($v1)
.PB0f198a18:
/*  f198a18:	3c014352 */ 	lui	$at,0x4352
/*  f198a1c:	058101a6 */ 	bgez	$t4,.PB0f1990b8
/*  f198a20:	00000000 */ 	nop
/*  f198a24:	44813000 */ 	mtc1	$at,$f6
/*  f198a28:	02802025 */ 	move	$a0,$s4
/*  f198a2c:	4600328d */ 	trunc.w.s	$f10,$f6
/*  f198a30:	44105000 */ 	mfc1	$s0,$f10
/*  f198a34:	0fc089b4 */ 	jal	chrUncloakTemporarily
/*  f198a38:	00000000 */ 	nop
/*  f198a3c:	02802025 */ 	move	$a0,$s4
/*  f198a40:	24050002 */ 	li	$a1,0x2
/*  f198a44:	02003025 */ 	move	$a2,$s0
/*  f198a48:	0fc0eed5 */ 	jal	chrPunchInflictDamage
/*  f198a4c:	00003825 */ 	move	$a3,$zero
/*  f198a50:	16600199 */ 	bnez	$s3,.PB0f1990b8
/*  f198a54:	00000000 */ 	nop
/*  f198a58:	8e580020 */ 	lw	$t8,0x20($s2)
/*  f198a5c:	2709ffff */ 	addiu	$t1,$t8,-1
/*  f198a60:	2d21001c */ 	sltiu	$at,$t1,0x1c
/*  f198a64:	10200006 */ 	beqz	$at,.PB0f198a80
/*  f198a68:	00094880 */ 	sll	$t1,$t1,0x2
/*  f198a6c:	3c017f1c */ 	lui	$at,0x7f1c
/*  f198a70:	00290821 */ 	addu	$at,$at,$t1
/*  f198a74:	8c29b2f8 */ 	lw	$t1,-0x4d08($at)
/*  f198a78:	01200008 */ 	jr	$t1
/*  f198a7c:	00000000 */ 	nop
.PB0f198a80:
/*  f198a80:	8e8a02d4 */ 	lw	$t2,0x2d4($s4)
/*  f198a84:	24190064 */ 	li	$t9,0x64
/*  f198a88:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*  f198a8c:	91a20048 */ 	lbu	$v0,0x48($t5)
/*  f198a90:	14400003 */ 	bnez	$v0,.PB0f198aa0
/*  f198a94:	00000000 */ 	nop
/*  f198a98:	10000007 */ 	b	.PB0f198ab8
/*  f198a9c:	a659003c */ 	sh	$t9,0x3c($s2)
.PB0f198aa0:
/*  f198aa0:	16e20004 */ 	bne	$s7,$v0,.PB0f198ab4
/*  f198aa4:	240b0019 */ 	li	$t3,0x19
/*  f198aa8:	240e0032 */ 	li	$t6,0x32
/*  f198aac:	10000002 */ 	b	.PB0f198ab8
/*  f198ab0:	a64e003c */ 	sh	$t6,0x3c($s2)
.PB0f198ab4:
/*  f198ab4:	a64b003c */ 	sh	$t3,0x3c($s2)
.PB0f198ab8:
/*  f198ab8:	0c004be0 */ 	jal	random
/*  f198abc:	00000000 */ 	nop
/*  f198ac0:	24010003 */ 	li	$at,0x3
/*  f198ac4:	0041001b */ 	divu	$zero,$v0,$at
/*  f198ac8:	00006010 */ 	mfhi	$t4
/*  f198acc:	1580017a */ 	bnez	$t4,.PB0f1990b8
/*  f198ad0:	00000000 */ 	nop
/*  f198ad4:	864f003c */ 	lh	$t7,0x3c($s2)
/*  f198ad8:	25f8fff0 */ 	addiu	$t8,$t7,-16
/*  f198adc:	10000176 */ 	b	.PB0f1990b8
/*  f198ae0:	a658003e */ 	sh	$t8,0x3e($s2)
/*  f198ae4:	8e8902d4 */ 	lw	$t1,0x2d4($s4)
/*  f198ae8:	240d0064 */ 	li	$t5,0x64
/*  f198aec:	8d2a0004 */ 	lw	$t2,0x4($t1)
/*  f198af0:	91420048 */ 	lbu	$v0,0x48($t2)
/*  f198af4:	14400003 */ 	bnez	$v0,.PB0f198b04
/*  f198af8:	00000000 */ 	nop
/*  f198afc:	10000007 */ 	b	.PB0f198b1c
/*  f198b00:	a64d003c */ 	sh	$t5,0x3c($s2)
.PB0f198b04:
/*  f198b04:	16e20004 */ 	bne	$s7,$v0,.PB0f198b18
/*  f198b08:	240e0032 */ 	li	$t6,0x32
/*  f198b0c:	2419004b */ 	li	$t9,0x4b
/*  f198b10:	10000002 */ 	b	.PB0f198b1c
/*  f198b14:	a659003c */ 	sh	$t9,0x3c($s2)
.PB0f198b18:
/*  f198b18:	a64e003c */ 	sh	$t6,0x3c($s2)
.PB0f198b1c:
/*  f198b1c:	8e8b0174 */ 	lw	$t3,0x174($s4)
/*  f198b20:	11600165 */ 	beqz	$t3,.PB0f1990b8
/*  f198b24:	00000000 */ 	nop
/*  f198b28:	864c003c */ 	lh	$t4,0x3c($s2)
/*  f198b2c:	258fffdf */ 	addiu	$t7,$t4,-33
/*  f198b30:	10000161 */ 	b	.PB0f1990b8
/*  f198b34:	a64f003e */ 	sh	$t7,0x3e($s2)
/*  f198b38:	24180032 */ 	li	$t8,0x32
/*  f198b3c:	a658003c */ 	sh	$t8,0x3c($s2)
/*  f198b40:	2404001c */ 	li	$a0,0x1c
/*  f198b44:	0fc26da8 */ 	jal	bgunGetMinClipQty
/*  f198b48:	02e02825 */ 	move	$a1,$s7
/*  f198b4c:	8e490024 */ 	lw	$t1,0x24($s2)
/*  f198b50:	01225023 */ 	subu	$t2,$t1,$v0
/*  f198b54:	10000158 */ 	b	.PB0f1990b8
/*  f198b58:	ae4a0024 */ 	sw	$t2,0x24($s2)
/*  f198b5c:	10000156 */ 	b	.PB0f1990b8
/*  f198b60:	a640003c */ 	sh	$zero,0x3c($s2)
/*  f198b64:	8e440020 */ 	lw	$a0,0x20($s2)
.PB0f198b68:
/*  f198b68:	24010019 */ 	li	$at,0x19
/*  f198b6c:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f198b70:	14810011 */ 	bne	$a0,$at,.PB0f198bb8
/*  f198b74:	00022880 */ 	sll	$a1,$v0,0x2
/*  f198b78:	07230010 */ 	bgezl	$t9,.PB0f198bbc
/*  f198b7c:	0005c7c2 */ 	srl	$t8,$a1,0x1f
/*  f198b80:	868e017e */ 	lh	$t6,0x17e($s4)
/*  f198b84:	53ce000d */ 	beql	$s8,$t6,.PB0f198bbc
/*  f198b88:	0005c7c2 */ 	srl	$t8,$a1,0x1f
/*  f198b8c:	8e4b0024 */ 	lw	$t3,0x24($s2)
/*  f198b90:	19600149 */ 	blez	$t3,.PB0f1990b8
/*  f198b94:	00000000 */ 	nop
/*  f198b98:	0fc089b4 */ 	jal	chrUncloakTemporarily
/*  f198b9c:	02802025 */ 	move	$a0,$s4
/*  f198ba0:	0fc6710c */ 	jal	botactCreateSlayerRocket
/*  f198ba4:	02802025 */ 	move	$a0,$s4
/*  f198ba8:	8e4c0024 */ 	lw	$t4,0x24($s2)
/*  f198bac:	258fffff */ 	addiu	$t7,$t4,-1
/*  f198bb0:	10000141 */ 	b	.PB0f1990b8
/*  f198bb4:	ae4f0024 */ 	sw	$t7,0x24($s2)
.PB0f198bb8:
/*  f198bb8:	0005c7c2 */ 	srl	$t8,$a1,0x1f
.PB0f198bbc:
/*  f198bbc:	0fc66f9f */ 	jal	botactIsWeaponThrowable
/*  f198bc0:	03002825 */ 	move	$a1,$t8
/*  f198bc4:	1040005b */ 	beqz	$v0,.PB0f198d34
/*  f198bc8:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f198bcc:	1660013a */ 	bnez	$s3,.PB0f1990b8
/*  f198bd0:	00000000 */ 	nop
/*  f198bd4:	8e420034 */ 	lw	$v0,0x34($s2)
/*  f198bd8:	02402025 */ 	move	$a0,$s2
/*  f198bdc:	58400005 */ 	blezl	$v0,.PB0f198bf4
/*  f198be0:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
/*  f198be4:	8ec90038 */ 	lw	$t1,0x38($s6)
/*  f198be8:	00495023 */ 	subu	$t2,$v0,$t1
/*  f198bec:	ae4a0034 */ 	sw	$t2,0x34($s2)
/*  f198bf0:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
.PB0f198bf4:
/*  f198bf4:	8db90034 */ 	lw	$t9,0x34($t5)
/*  f198bf8:	1f20012f */ 	bgtz	$t9,.PB0f1990b8
/*  f198bfc:	00000000 */ 	nop
/*  f198c00:	8e46004c */ 	lw	$a2,0x4c($s2)
/*  f198c04:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f198c08:	00003825 */ 	move	$a3,$zero
/*  f198c0c:	00067080 */ 	sll	$t6,$a2,0x2
/*  f198c10:	0fc66df1 */ 	jal	botactGetAmmoQuantityByWeapon
/*  f198c14:	000e37c2 */ 	srl	$a2,$t6,0x1f
/*  f198c18:	5c400008 */ 	bgtzl	$v0,.PB0f198c3c
/*  f198c1c:	868c017e */ 	lh	$t4,0x17e($s4)
/*  f198c20:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198c24:	2401000e */ 	li	$at,0xe
/*  f198c28:	10810003 */ 	beq	$a0,$at,.PB0f198c38
/*  f198c2c:	2401000f */ 	li	$at,0xf
/*  f198c30:	14810121 */ 	bne	$a0,$at,.PB0f1990b8
/*  f198c34:	00000000 */ 	nop
.PB0f198c38:
/*  f198c38:	868c017e */ 	lh	$t4,0x17e($s4)
.PB0f198c3c:
/*  f198c3c:	00008025 */ 	move	$s0,$zero
/*  f198c40:	13cc0018 */ 	beq	$s8,$t4,.PB0f198ca4
/*  f198c44:	00000000 */ 	nop
/*  f198c48:	8e4f0128 */ 	lw	$t7,0x128($s2)
/*  f198c4c:	11e00015 */ 	beqz	$t7,.PB0f198ca4
/*  f198c50:	00000000 */ 	nop
/*  f198c54:	8e490004 */ 	lw	$t1,0x4($s2)
/*  f198c58:	3c198009 */ 	lui	$t9,0x8009
/*  f198c5c:	8e58011c */ 	lw	$t8,0x11c($s2)
/*  f198c60:	912a0048 */ 	lbu	$t2,0x48($t1)
/*  f198c64:	000a6940 */ 	sll	$t5,$t2,0x5
/*  f198c68:	032dc821 */ 	addu	$t9,$t9,$t5
/*  f198c6c:	9339a1f4 */ 	lbu	$t9,-0x5e0c($t9)
/*  f198c70:	0319082a */ 	slt	$at,$t8,$t9
/*  f198c74:	1420000b */ 	bnez	$at,.PB0f198ca4
/*  f198c78:	00000000 */ 	nop
/*  f198c7c:	0fc64784 */ 	jal	botIsDizzy
/*  f198c80:	02802025 */ 	move	$a0,$s4
/*  f198c84:	14400006 */ 	bnez	$v0,.PB0f198ca0
/*  f198c88:	02802025 */ 	move	$a0,$s4
/*  f198c8c:	2405002d */ 	li	$a1,0x2d
/*  f198c90:	0fc12463 */ 	jal	chrIsTargetInFov
/*  f198c94:	00003025 */ 	move	$a2,$zero
/*  f198c98:	10400002 */ 	beqz	$v0,.PB0f198ca4
/*  f198c9c:	00000000 */ 	nop
.PB0f198ca0:
/*  f198ca0:	02e08025 */ 	move	$s0,$s7
.PB0f198ca4:
/*  f198ca4:	12000104 */ 	beqz	$s0,.PB0f1990b8
/*  f198ca8:	00000000 */ 	nop
/*  f198cac:	0fc089b4 */ 	jal	chrUncloakTemporarily
/*  f198cb0:	02802025 */ 	move	$a0,$s4
/*  f198cb4:	8e46004c */ 	lw	$a2,0x4c($s2)
/*  f198cb8:	02402025 */ 	move	$a0,$s2
/*  f198cbc:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f198cc0:	00067080 */ 	sll	$t6,$a2,0x2
/*  f198cc4:	000e37c2 */ 	srl	$a2,$t6,0x1f
/*  f198cc8:	0fc66e54 */ 	jal	botactTryRemoveAmmoFromReserve
/*  f198ccc:	02e03825 */ 	move	$a3,$s7
/*  f198cd0:	0fc66fd7 */ 	jal	botact0f19a37c
/*  f198cd4:	02802025 */ 	move	$a0,$s4
/*  f198cd8:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f198cdc:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198ce0:	00056080 */ 	sll	$t4,$a1,0x2
/*  f198ce4:	0fc2c505 */ 	jal	weaponGetFunctionById
/*  f198ce8:	000c2fc2 */ 	srl	$a1,$t4,0x1f
/*  f198cec:	5040000d */ 	beqzl	$v0,.PB0f198d24
/*  f198cf0:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
/*  f198cf4:	8c490010 */ 	lw	$t1,0x10($v0)
/*  f198cf8:	02802025 */ 	move	$a0,$s4
/*  f198cfc:	00095340 */ 	sll	$t2,$t1,0xd
/*  f198d00:	05430008 */ 	bgezl	$t2,.PB0f198d24
/*  f198d04:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
/*  f198d08:	0fc6665d */ 	jal	botinvRemoveItem
/*  f198d0c:	8e450020 */ 	lw	$a1,0x20($s2)
/*  f198d10:	02802025 */ 	move	$a0,$s4
/*  f198d14:	02e02825 */ 	move	$a1,$s7
/*  f198d18:	0fc66c24 */ 	jal	botinvSwitchToWeapon
/*  f198d1c:	00003025 */ 	move	$a2,$zero
/*  f198d20:	8e8d02d4 */ 	lw	$t5,0x2d4($s4)
.PB0f198d24:
/*  f198d24:	0fc66faf */ 	jal	botactGetProjectileThrowInterval
/*  f198d28:	8da40020 */ 	lw	$a0,0x20($t5)
/*  f198d2c:	100000e2 */ 	b	.PB0f1990b8
/*  f198d30:	ae420034 */ 	sw	$v0,0x34($s2)
.PB0f198d34:
/*  f198d34:	0298c821 */ 	addu	$t9,$s4,$t8
/*  f198d38:	8f2e0170 */ 	lw	$t6,0x170($t9)
/*  f198d3c:	0013c040 */ 	sll	$t8,$s3,0x1
/*  f198d40:	02536821 */ 	addu	$t5,$s2,$s3
/*  f198d44:	11c000d9 */ 	beqz	$t6,.PB0f1990ac
/*  f198d48:	0258c821 */ 	addu	$t9,$s2,$t8
/*  f198d4c:	8e2b0024 */ 	lw	$t3,0x24($s1)
/*  f198d50:	596000d7 */ 	blezl	$t3,.PB0f1990b0
/*  f198d54:	ae2000c4 */ 	sw	$zero,0xc4($s1)
/*  f198d58:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f198d5c:	00008025 */ 	move	$s0,$zero
/*  f198d60:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198d64:	00056080 */ 	sll	$t4,$a1,0x2
/*  f198d68:	0fc2c8be */ 	jal	weaponGetNumTicksPerShot
/*  f198d6c:	000c2fc2 */ 	srl	$a1,$t4,0x1f
/*  f198d70:	5c400030 */ 	bgtzl	$v0,.PB0f198e34
/*  f198d74:	02e08025 */ 	move	$s0,$s7
/*  f198d78:	8e490020 */ 	lw	$t1,0x20($s2)
/*  f198d7c:	24010006 */ 	li	$at,0x6
/*  f198d80:	55210027 */ 	bnel	$t1,$at,.PB0f198e20
/*  f198d84:	8e29005c */ 	lw	$t1,0x5c($s1)
/*  f198d88:	8e4a004c */ 	lw	$t2,0x4c($s2)
/*  f198d8c:	000a6880 */ 	sll	$t5,$t2,0x2
/*  f198d90:	000dc7c2 */ 	srl	$t8,$t5,0x1f
/*  f198d94:	56f80022 */ 	bnel	$s7,$t8,.PB0f198e20
/*  f198d98:	8e29005c */ 	lw	$t1,0x5c($s1)
/*  f198d9c:	8e390024 */ 	lw	$t9,0x24($s1)
/*  f198da0:	2b210002 */ 	slti	$at,$t9,0x2
/*  f198da4:	1420001d */ 	bnez	$at,.PB0f198e1c
/*  f198da8:	3c017f1c */ 	lui	$at,0x7f1c
/*  f198dac:	c428b368 */ 	lwc1	$f8,-0x4c98($at)
/*  f198db0:	c6c4004c */ 	lwc1	$f4,0x4c($s6)
/*  f198db4:	c62000e4 */ 	lwc1	$f0,0xe4($s1)
/*  f198db8:	3c0140a0 */ 	lui	$at,0x40a0
/*  f198dbc:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f198dc0:	4600048d */ 	trunc.w.s	$f18,$f0
/*  f198dc4:	44039000 */ 	mfc1	$v1,$f18
/*  f198dc8:	44819000 */ 	mtc1	$at,$f18
/*  f198dcc:	46060280 */ 	add.s	$f10,$f0,$f6
/*  f198dd0:	3c0140a0 */ 	lui	$at,0x40a0
/*  f198dd4:	e62a00e4 */ 	swc1	$f10,0xe4($s1)
/*  f198dd8:	c62000e4 */ 	lwc1	$f0,0xe4($s1)
/*  f198ddc:	4600903c */ 	c.lt.s	$f18,$f0
/*  f198de0:	00000000 */ 	nop
/*  f198de4:	45020006 */ 	bc1fl	.PB0f198e00
/*  f198de8:	4600020d */ 	trunc.w.s	$f8,$f0
/*  f198dec:	44812000 */ 	mtc1	$at,$f4
/*  f198df0:	00000000 */ 	nop
/*  f198df4:	e62400e4 */ 	swc1	$f4,0xe4($s1)
/*  f198df8:	c62000e4 */ 	lwc1	$f0,0xe4($s1)
/*  f198dfc:	4600020d */ 	trunc.w.s	$f8,$f0
.PB0f198e00:
/*  f198e00:	44024000 */ 	mfc1	$v0,$f8
/*  f198e04:	00000000 */ 	nop
/*  f198e08:	50430005 */ 	beql	$v0,$v1,.PB0f198e20
/*  f198e0c:	8e29005c */ 	lw	$t1,0x5c($s1)
/*  f198e10:	8e2c0024 */ 	lw	$t4,0x24($s1)
/*  f198e14:	258fffff */ 	addiu	$t7,$t4,-1
/*  f198e18:	ae2f0024 */ 	sw	$t7,0x24($s1)
.PB0f198e1c:
/*  f198e1c:	8e29005c */ 	lw	$t1,0x5c($s1)
.PB0f198e20:
/*  f198e20:	1d200004 */ 	bgtz	$t1,.PB0f198e34
/*  f198e24:	00000000 */ 	nop
/*  f198e28:	10000002 */ 	b	.PB0f198e34
/*  f198e2c:	02e08025 */ 	move	$s0,$s7
/*  f198e30:	02e08025 */ 	move	$s0,$s7
.PB0f198e34:
/*  f198e34:	52000052 */ 	beqzl	$s0,.PB0f198f80
/*  f198e38:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f198e3c:	8e2a00c4 */ 	lw	$t2,0xc4($s1)
/*  f198e40:	02536821 */ 	addu	$t5,$s2,$s3
/*  f198e44:	15400004 */ 	bnez	$t2,.PB0f198e58
/*  f198e48:	00000000 */ 	nop
/*  f198e4c:	91b8004d */ 	lbu	$t8,0x4d($t5)
/*  f198e50:	5b000004 */ 	blezl	$t8,.PB0f198e64
/*  f198e54:	8699017e */ 	lh	$t9,0x17e($s4)
.PB0f198e58:
/*  f198e58:	1000003a */ 	b	.PB0f198f44
/*  f198e5c:	02e0a825 */ 	move	$s5,$s7
/*  f198e60:	8699017e */ 	lh	$t9,0x17e($s4)
.PB0f198e64:
/*  f198e64:	13d90037 */ 	beq	$s8,$t9,.PB0f198f44
/*  f198e68:	00000000 */ 	nop
/*  f198e6c:	8e4e0128 */ 	lw	$t6,0x128($s2)
/*  f198e70:	11c00034 */ 	beqz	$t6,.PB0f198f44
/*  f198e74:	00000000 */ 	nop
/*  f198e78:	8e4c0004 */ 	lw	$t4,0x4($s2)
/*  f198e7c:	3c0a8009 */ 	lui	$t2,0x8009
/*  f198e80:	8e4b011c */ 	lw	$t3,0x11c($s2)
/*  f198e84:	918f0048 */ 	lbu	$t7,0x48($t4)
/*  f198e88:	000f4940 */ 	sll	$t1,$t7,0x5
/*  f198e8c:	01495021 */ 	addu	$t2,$t2,$t1
/*  f198e90:	914aa1f4 */ 	lbu	$t2,-0x5e0c($t2)
/*  f198e94:	016a082a */ 	slt	$at,$t3,$t2
/*  f198e98:	1420002a */ 	bnez	$at,.PB0f198f44
/*  f198e9c:	00000000 */ 	nop
/*  f198ea0:	0fc64784 */ 	jal	botIsDizzy
/*  f198ea4:	02802025 */ 	move	$a0,$s4
/*  f198ea8:	14400006 */ 	bnez	$v0,.PB0f198ec4
/*  f198eac:	02802025 */ 	move	$a0,$s4
/*  f198eb0:	2405002d */ 	li	$a1,0x2d
/*  f198eb4:	0fc12463 */ 	jal	chrIsTargetInFov
/*  f198eb8:	00003025 */ 	move	$a2,$zero
/*  f198ebc:	10400021 */ 	beqz	$v0,.PB0f198f44
/*  f198ec0:	00000000 */ 	nop
.PB0f198ec4:
/*  f198ec4:	0fc0a255 */ 	jal	chrGetTargetProp
/*  f198ec8:	02802025 */ 	move	$a0,$s4
/*  f198ecc:	0fc0e6e9 */ 	jal	chrIsDead
/*  f198ed0:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f198ed4:	1440001b */ 	bnez	$v0,.PB0f198f44
/*  f198ed8:	00000000 */ 	nop
/*  f198edc:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198ee0:	2401000b */ 	li	$at,0xb
/*  f198ee4:	02e0a825 */ 	move	$s5,$s7
/*  f198ee8:	54810009 */ 	bnel	$a0,$at,.PB0f198f10
/*  f198eec:	24010014 */ 	li	$at,0x14
/*  f198ef0:	8e4d004c */ 	lw	$t5,0x4c($s2)
/*  f198ef4:	000dc080 */ 	sll	$t8,$t5,0x2
/*  f198ef8:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f198efc:	56f90004 */ 	bnel	$s7,$t9,.PB0f198f10
/*  f198f00:	24010014 */ 	li	$at,0x14
/*  f198f04:	1000000f */ 	b	.PB0f198f44
/*  f198f08:	ae3700c4 */ 	sw	$s7,0xc4($s1)
/*  f198f0c:	24010014 */ 	li	$at,0x14
.PB0f198f10:
/*  f198f10:	1481000c */ 	bne	$a0,$at,.PB0f198f44
/*  f198f14:	00137040 */ 	sll	$t6,$s3,0x1
/*  f198f18:	024e1821 */ 	addu	$v1,$s2,$t6
/*  f198f1c:	846c00e0 */ 	lh	$t4,0xe0($v1)
/*  f198f20:	8ecf0038 */ 	lw	$t7,0x38($s6)
/*  f198f24:	240a004b */ 	li	$t2,0x4b
/*  f198f28:	018f4821 */ 	addu	$t1,$t4,$t7
/*  f198f2c:	a46900e0 */ 	sh	$t1,0xe0($v1)
/*  f198f30:	846b00e0 */ 	lh	$t3,0xe0($v1)
/*  f198f34:	2961004c */ 	slti	$at,$t3,0x4c
/*  f198f38:	14200002 */ 	bnez	$at,.PB0f198f44
/*  f198f3c:	00000000 */ 	nop
/*  f198f40:	a46a00e0 */ 	sh	$t2,0xe0($v1)
.PB0f198f44:
/*  f198f44:	16a0000d */ 	bnez	$s5,.PB0f198f7c
/*  f198f48:	00136840 */ 	sll	$t5,$s3,0x1
/*  f198f4c:	024d1821 */ 	addu	$v1,$s2,$t5
/*  f198f50:	846200e0 */ 	lh	$v0,0xe0($v1)
/*  f198f54:	5840000a */ 	blezl	$v0,.PB0f198f80
/*  f198f58:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f198f5c:	8ed80038 */ 	lw	$t8,0x38($s6)
/*  f198f60:	02e0a825 */ 	move	$s5,$s7
/*  f198f64:	0058c823 */ 	subu	$t9,$v0,$t8
/*  f198f68:	a47900e0 */ 	sh	$t9,0xe0($v1)
/*  f198f6c:	846e00e0 */ 	lh	$t6,0xe0($v1)
/*  f198f70:	05c30003 */ 	bgezl	$t6,.PB0f198f80
/*  f198f74:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f198f78:	a46000e0 */ 	sh	$zero,0xe0($v1)
.PB0f198f7c:
/*  f198f7c:	8e45004c */ 	lw	$a1,0x4c($s2)
.PB0f198f80:
/*  f198f80:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198f84:	00056080 */ 	sll	$t4,$a1,0x2
/*  f198f88:	0fc2c8be */ 	jal	weaponGetNumTicksPerShot
/*  f198f8c:	000c2fc2 */ 	srl	$a1,$t4,0x1f
/*  f198f90:	1c400049 */ 	bgtz	$v0,.PB0f1990b8
/*  f198f94:	00000000 */ 	nop
/*  f198f98:	12a00047 */ 	beqz	$s5,.PB0f1990b8
/*  f198f9c:	00000000 */ 	nop
/*  f198fa0:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f198fa4:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198fa8:	00054880 */ 	sll	$t1,$a1,0x2
/*  f198fac:	0fc6707b */ 	jal	botactGetShootInterval60
/*  f198fb0:	00092fc2 */ 	srl	$a1,$t1,0x1f
/*  f198fb4:	28410006 */ 	slti	$at,$v0,0x6
/*  f198fb8:	1420000b */ 	bnez	$at,.PB0f198fe8
/*  f198fbc:	ae22005c */ 	sw	$v0,0x5c($s1)
/*  f198fc0:	00026880 */ 	sll	$t5,$v0,0x2
/*  f198fc4:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f198fc8:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f198fcc:	01a26821 */ 	addu	$t5,$t5,$v0
/*  f198fd0:	000d6840 */ 	sll	$t5,$t5,0x1
/*  f198fd4:	2401003c */ 	li	$at,0x3c
/*  f198fd8:	01a1001a */ 	div	$zero,$t5,$at
/*  f198fdc:	0000c012 */ 	mflo	$t8
/*  f198fe0:	ae38005c */ 	sw	$t8,0x5c($s1)
/*  f198fe4:	00000000 */ 	nop
.PB0f198fe8:
/*  f198fe8:	8e45004c */ 	lw	$a1,0x4c($s2)
/*  f198fec:	8e440020 */ 	lw	$a0,0x20($s2)
/*  f198ff0:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f198ff4:	0fc2c505 */ 	jal	weaponGetFunctionById
/*  f198ff8:	00192fc2 */ 	srl	$a1,$t9,0x1f
/*  f198ffc:	1040002e */ 	beqz	$v0,.PB0f1990b8
/*  f199000:	00000000 */ 	nop
/*  f199004:	8c430010 */ 	lw	$v1,0x10($v0)
/*  f199008:	306c1002 */ 	andi	$t4,$v1,0x1002
/*  f19900c:	1180002a */ 	beqz	$t4,.PB0f1990b8
/*  f199010:	00000000 */ 	nop
/*  f199014:	8e2f0024 */ 	lw	$t7,0x24($s1)
/*  f199018:	30691000 */ 	andi	$t1,$v1,0x1000
/*  f19901c:	29e10002 */ 	slti	$at,$t7,0x2
/*  f199020:	14200025 */ 	bnez	$at,.PB0f1990b8
/*  f199024:	00000000 */ 	nop
/*  f199028:	11200003 */ 	beqz	$t1,.PB0f199038
/*  f19902c:	24040003 */ 	li	$a0,0x3
/*  f199030:	10000001 */ 	b	.PB0f199038
/*  f199034:	24040002 */ 	li	$a0,0x2
.PB0f199038:
/*  f199038:	8e8b02d4 */ 	lw	$t3,0x2d4($s4)
/*  f19903c:	01731021 */ 	addu	$v0,$t3,$s3
/*  f199040:	904a004d */ 	lbu	$t2,0x4d($v0)
/*  f199044:	254d0001 */ 	addiu	$t5,$t2,0x1
/*  f199048:	a04d004d */ 	sb	$t5,0x4d($v0)
/*  f19904c:	8e9802d4 */ 	lw	$t8,0x2d4($s4)
/*  f199050:	03131021 */ 	addu	$v0,$t8,$s3
/*  f199054:	9059004d */ 	lbu	$t9,0x4d($v0)
/*  f199058:	0324001a */ 	div	$zero,$t9,$a0
/*  f19905c:	00007010 */ 	mfhi	$t6
/*  f199060:	a04e004d */ 	sb	$t6,0x4d($v0)
/*  f199064:	8e8302d4 */ 	lw	$v1,0x2d4($s4)
/*  f199068:	14800002 */ 	bnez	$a0,.PB0f199074
/*  f19906c:	00000000 */ 	nop
/*  f199070:	0007000d */ 	break	0x7
.PB0f199074:
/*  f199074:	2401ffff */ 	li	$at,-1
/*  f199078:	14810004 */ 	bne	$a0,$at,.PB0f19908c
/*  f19907c:	3c018000 */ 	lui	$at,0x8000
/*  f199080:	17210002 */ 	bne	$t9,$at,.PB0f19908c
/*  f199084:	00000000 */ 	nop
/*  f199088:	0006000d */ 	break	0x6
.PB0f19908c:
/*  f19908c:	00736021 */ 	addu	$t4,$v1,$s3
/*  f199090:	918f004d */ 	lbu	$t7,0x4d($t4)
/*  f199094:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f199098:	11e00007 */ 	beqz	$t7,.PB0f1990b8
/*  f19909c:	24090005 */ 	li	$t1,0x5
/*  f1990a0:	006b5021 */ 	addu	$t2,$v1,$t3
/*  f1990a4:	10000004 */ 	b	.PB0f1990b8
/*  f1990a8:	ad49005c */ 	sw	$t1,0x5c($t2)
.PB0f1990ac:
/*  f1990ac:	ae2000c4 */ 	sw	$zero,0xc4($s1)
.PB0f1990b0:
/*  f1990b0:	a1a0004d */ 	sb	$zero,0x4d($t5)
/*  f1990b4:	a72000e0 */ 	sh	$zero,0xe0($t9)
.PB0f1990b8:
/*  f1990b8:	52a00007 */ 	beqzl	$s5,.PB0f1990d8
/*  f1990bc:	02802025 */ 	move	$a0,$s4
/*  f1990c0:	0fc089b4 */ 	jal	chrUncloakTemporarily
/*  f1990c4:	02802025 */ 	move	$a0,$s4
/*  f1990c8:	56600003 */ 	bnezl	$s3,.PB0f1990d8
/*  f1990cc:	02802025 */ 	move	$a0,$s4
/*  f1990d0:	afb70088 */ 	sw	$s7,0x88($sp)
/*  f1990d4:	02802025 */ 	move	$a0,$s4
.PB0f1990d8:
/*  f1990d8:	02602825 */ 	move	$a1,$s3
/*  f1990dc:	0fc0fea6 */ 	jal	chrSetHandFiring
/*  f1990e0:	02a03025 */ 	move	$a2,$s5
/*  f1990e4:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f1990e8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f1990ec:	24010002 */ 	li	$at,0x2
/*  f1990f0:	25cc0004 */ 	addiu	$t4,$t6,0x4
/*  f1990f4:	afac004c */ 	sw	$t4,0x4c($sp)
/*  f1990f8:	1661fdcf */ 	bne	$s3,$at,.PB0f198838
/*  f1990fc:	26310004 */ 	addiu	$s1,$s1,0x4
.PB0f199100:
/*  f199100:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f199104:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f199108:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f19910c:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f199110:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f199114:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f199118:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f19911c:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f199120:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f199124:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f199128:	03e00008 */ 	jr	$ra
/*  f19912c:	27bd02f8 */ 	addiu	$sp,$sp,0x2f8
);
#else
/**
 * The tick function for a multiplayer simulant while the game is running.
 *
 * The function implements per-scenario decision logic as well as shooting and
 * reloading.
 *
 * General function overview:
 * - Some minor things at the start
 * - If team is only AI, choose scenario commands as if player had assigned them
 * - If the bot is in its main loop:
 *     - Choose a new myaction value based on the command.
 *     - Apply the new myaction if any
 * - If the existing myaction is no longer valid, force a return to the main
 *   loop on the next tick
 * - Decide whether to switch weapons (via botinvTick)
 * - Decide whether to discharge a shot on this tick
 */
void botTickUnpaused(struct chrdata *chr)
{
	s32 newaction = -1;

	if (!chrIsDead(chr)) {
		struct aibot *aibot = chr->aibot;
		s32 i;

		// Consider updating random values
		aibot->random2ttl60 -= g_Vars.lvupdate240_60;

		if (aibot->random2ttl60 < 0) {
			aibot->random2ttl60 = 1800 + random() % 14400;
			aibot->random2 = random();
			aibot->randomfrac = RANDOMFRAC();
		}

		// Consider reloading
		for (i = 0; i != 2; i++) {
			// Reload if timer has reached 0
			if (aibot->timeuntilreload60[i] > 0) {
				aibot->timeuntilreload60[i] -= g_Vars.lvupdate240_60;

				if (aibot->timeuntilreload60[i] <= 0) {
					botactReload(chr, i, true);
				}
			} else if (!botactIsWeaponThrowable(aibot->weaponnum, aibot->gunfunc)) {
				// If the weapon is reloadable, schedule a reload if bot is out
				// of ammo or has less than half a clip and last saw their
				// target 2 seconds ago
				s32 loadedammo = aibot->loadedammo[i];
				s32 clipsize = botactGetClipCapacityByFunction(aibot->weaponnum, aibot->gunfunc);

				if (loadedammo <= 0 && clipsize > 0) {
					botScheduleReload(chr, i);
				} else if (loadedammo < clipsize / 2 && aibot->lastseenanytarget60 < g_Vars.lvframe60 - 120) {
					botScheduleReload(chr, i);
				}
			}
		}

		// Handle switching weapons
		if (aibot->changeguntimer60 > 0) {
			aibot->changeguntimer60 -= g_Vars.lvupdate240_60;

			if (aibot->changeguntimer60 <= 0) {
				struct invitem *item = botinvGetItem(chr, aibot->weaponnum);
				s32 modelnum = playermgrGetModelOfWeapon(aibot->weaponnum);
				s32 i;

				if (item && modelnum >= 0) {
					chrGiveWeapon(chr, modelnum, aibot->weaponnum, 0);
					botactReload(chr, HAND_RIGHT, false);

					if (item->type == INVITEMTYPE_DUAL) {
						chrGiveWeapon(chr, modelnum, aibot->weaponnum, OBJFLAG_WEAPON_LEFTHANDED);
						botactReload(chr, HAND_LEFT, false);
					}
				} else {
					// Bot doesn't have the weapon it was told to switch to
					chr->aibot->weaponnum = WEAPON_UNARMED;
					chr->aibot->gunfunc = FUNC_PRIMARY;
					chr->aibot->iscloserangeweapon = 1;
				}

				aibot->throwtimer60 = 0;

				for (i = 0; i < 2; i++) {
					aibot->punchtimer60[i] = 0;

					if (chr->weapons_held[i]) {
						chr->weapons_held[i]->weapon->gunfunc = chr->aibot->gunfunc;
					}
				}
			}
		}

		// The laser has unlimited ammo
		if (aibot->weaponnum == WEAPON_LASER) {
			chr->aibot->loadedammo[HAND_RIGHT] = 999;
		}

		// Consider starting or stopping cloak
		if (aibot->ammoheld[AMMOTYPE_CLOAK] > 0
				&& (botIsAboutToAttack(chr, true) || chr->myaction == MA_AIBOTDOWNLOAD)) {
			aibot->cloakdeviceenabled = true;
		} else if (aibot->ammoheld[AMMOTYPE_CLOAK] > 1200 + (aibot->random1 >> 5) % 1200) {
			aibot->cloakdeviceenabled = true;
		} else if (aibot->ammoheld[AMMOTYPE_CLOAK] <= (aibot->random1 >> 17) % 1200) {
			aibot->cloakdeviceenabled = false;
		}

		// Consider starting or stopping RC-P120 cloak
		if (!aibot->cloakdeviceenabled && aibot->weaponnum == WEAPON_RCP120) {
			s32 qty = botactGetAmmoQuantityByWeapon(aibot, WEAPON_RCP120, FUNC_PRIMARY, true);

			if (botIsAboutToAttack(chr, true)) {
				if (qty > 200 + (aibot->random1 >> 6) % 200) {
					aibot->rcp120cloakenabled = true;
				} else if (qty <= 30 + (aibot->random1 >> 16) % 70) {
					aibot->rcp120cloakenabled = false;
				}
			} else {
				if (qty > 300 + (aibot->random1 >> 12) % 500) {
					aibot->rcp120cloakenabled = true;
				} else {
					aibot->rcp120cloakenabled = false;
				}
			}
		} else {
			aibot->rcp120cloakenabled = false;
		}

		// KazeSims will attack on sight
		if (aibot->config->type == BOTTYPE_KAZE
				&& chr->target != -1
				&& aibot->targetinsight
				&& chr->myaction != MA_AIBOTATTACK) {
			aibot->forcemainloop = true;
		}

		// If there's no humans on the bot's team to give it commands, figure
		// out which commands to apply automatically based on the scenario.
		if (aibot->teamisonlyai) {
			if (aibot->commandtimer60 > 0) {
				aibot->commandtimer60 -= g_Vars.lvupdate240_60;
			}

			if (aibot->commandtimer60 <= 0) {
				s32 teamsize = botGetTeamSize(chr);

				if (g_MpSetup.scenario == MPSCENARIO_HOLDTHEBRIEFCASE) {
					s32 numgetting = botGetCountInTeamDoingCommand(chr, AIBOTCMD_GETCASE2, false);

					if (numgetting <= 0 || (numgetting < (teamsize + 1) / 2 || random() % 100 < 66)) {
						botApplyScenarioCommand(chr, AIBOTCMD_GETCASE2);
					} else {
						botApplyScenarioCommand(chr, AIBOTCMD_NORMAL);
					}
				} else if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL) {
					s32 numbots = botGetCountInTeamDoingCommand(chr, AIBOTCMD_DOWNLOAD, false);

					if (aibot->hasuplink || numbots <= 0 || (numbots < (teamsize + 1) / 2 || random() % 100 < 50)) {
						botApplyScenarioCommand(chr, AIBOTCMD_DOWNLOAD);
					} else {
						botApplyScenarioCommand(chr, AIBOTCMD_NORMAL);
					}
				} else if (g_MpSetup.scenario == MPSCENARIO_POPACAP) {
					s32 numchasing = botGetCountInTeamDoingCommand(chr, AIBOTCMD_POPCAP, false);

					if (numchasing <= 0 || numchasing < (teamsize + 1) / 2 || random() % 100 < 50) {
						botApplyScenarioCommand(chr, AIBOTCMD_POPCAP);
					} else {
						botApplyScenarioCommand(chr, AIBOTCMD_NORMAL);
					}
				} else if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL) {
					s32 numinhill = botGetNumTeammatesDefendingHill(chr);

					// Don't count ourselves
					if (chr->prop->rooms[0] == g_ScenarioData.koh.hillrooms[0]) {
						numinhill--;
					}

					if (numinhill <= 0 || numinhill < teamsize / 2) {
						botApplyScenarioCommand(chr, AIBOTCMD_HOLDHILL);
					} else if (numinhill > botGetNumOpponentsInHill(chr)) {
						if (random() % 100 < 50) {
							botApplyScenarioCommand(chr, AIBOTCMD_DEFHILL);
						} else {
							botApplyScenarioCommand(chr, AIBOTCMD_NORMAL);
						}
					} else {
						botApplyScenarioCommand(chr, AIBOTCMD_HOLDHILL);
					}
				} else if (g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE) {
					if (teamsize == 1) {
						// One man team
						s32 numgetting = botGetCountInTeamDoingCommand(chr, AIBOTCMD_GETCASE, true);

						if (botShouldReturnCtcToken(chr)) {
							botApplyScenarioCommand(chr, AIBOTCMD_GETCASE);
						} else if (botIsChrsCtcTokenHeld(chr)) {
							if (random() % 100 < 30) {
								botApplyScenarioCommand(chr, AIBOTCMD_GETCASE);
							} else {
								botApplyScenarioCommand(chr, AIBOTCMD_SAVECASE);
							}
						} else {
							if (random() % 100 < 70 || numgetting <= 0) {
								botApplyScenarioCommand(chr, AIBOTCMD_GETCASE);
							} else {
								botApplyScenarioCommand(chr, AIBOTCMD_SAVECASE);
							}
						}
					} else {
						// Not a one man team
						s32 numgetting = botGetCountInTeamDoingCommand(chr, AIBOTCMD_GETCASE, false);
						s32 numsaving = botGetCountInTeamDoingCommand(chr, AIBOTCMD_SAVECASE, false);

						if (botShouldReturnCtcToken(chr)) {
							botApplyScenarioCommand(chr, AIBOTCMD_GETCASE);
						} else if (botIsChrsCtcTokenHeld(chr)) {
							if (numsaving <= 0 || random() % 100 < 70) {
								botApplyScenarioCommand(chr, AIBOTCMD_SAVECASE);
							} else {
								botApplyScenarioCommand(chr, AIBOTCMD_GETCASE);
							}
						} else if (numgetting <= 0 || numgetting < teamsize / 3) {
							botApplyScenarioCommand(chr, AIBOTCMD_GETCASE);
						} else if (numsaving <= 0 || numsaving < teamsize / 4) {
							botApplyScenarioCommand(chr, AIBOTCMD_SAVECASE);
						} else if (random() % 100 < 30) {
							botApplyScenarioCommand(chr, AIBOTCMD_GETCASE);
						} else if (random() % 100 < 30) {
							botApplyScenarioCommand(chr, AIBOTCMD_SAVECASE);
						} else {
							botApplyScenarioCommand(chr, AIBOTCMD_NORMAL);
						}
					}
				}

				// Consider changing command in 20 to 60 seconds
				aibot->commandtimer60 = 1200 + random() % 2400;
			}
		}

		// The main loop is entered whenever the bot needs something to do
		// or when a player gives it a command. It calculates a new myaction
		// value and associated arguments based on its assigned command.
		if (chr->myaction == MA_AIBOTMAINLOOP || aibot->forcemainloop) {
			aibot->forcemainloop = false;
			aibot->attackingplayernum = -1;

			// KazeSim will attack people on sight regardless of command
			if (aibot->config->type == BOTTYPE_KAZE && chr->target != -1 && aibot->targetinsight) {
				newaction = MA_AIBOTATTACK;
				aibot->attackingplayernum = mpPlayerGetIndex(chrGetTargetProp(chr)->chr);
				aibot->abortattacktimer60 = -1;
			}

			// Check if the bot needs to fetch some weapons or ammo
			if (newaction < 0) {
				aibot->gotoprop = botFindDefaultPickup(chr);

				if (aibot->gotoprop) {
					newaction = MA_AIBOTGETITEM;
				}
			}

			// Bot is good to implement the assigned command
			if (newaction < 0) {
				if (aibot->command == AIBOTCMD_ATTACK) {
					// Attack the prop (player) given in attackpropnum
					// This is a human command only
					struct chrdata *targetchr = (g_Vars.props + aibot->attackpropnum)->chr;

					if (!chrIsDead(targetchr)
							&& !botIsTargetInvisible(chr, targetchr)
							&& botPassesCowardCheck(chr, targetchr)) {
						newaction = MA_AIBOTATTACK;
						aibot->attackingplayernum = mpPlayerGetIndex(targetchr);
						aibot->abortattacktimer60 = -1;
					}
				} else if (aibot->command == AIBOTCMD_FOLLOW) {
					// Follow the prop (player) given in followprotectpropnum
					// This is a human command only
					newaction = MA_AIBOTFOLLOW;
					aibot->canbreakfollow = true;
					aibot->followingplayernum = mpPlayerGetIndex((g_Vars.props + aibot->followprotectpropnum)->chr);
				} else if (aibot->command == AIBOTCMD_PROTECT) {
					// Protect the prop (player) given in followprotectpropnum
					// This is a human command only
					newaction = MA_AIBOTFOLLOW;
					aibot->canbreakfollow = false;
					aibot->followingplayernum = mpPlayerGetIndex((g_Vars.props + aibot->followprotectpropnum)->chr);
				} else if (aibot->command == AIBOTCMD_DEFEND) {
					// Defend the position given in defendholdpos
					// This is a human command only
					newaction = MA_AIBOTDEFEND;
					aibot->canbreakdefend = true;
				} else if (aibot->command == AIBOTCMD_HOLD) {
					// Hold the position given in defendholdpos
					// This is a human command only
					newaction = MA_AIBOTDEFEND;
					aibot->canbreakdefend = false;
				} else if (aibot->command == AIBOTCMD_GETCASE) {
					// Capture the case - fetch and return the opponent's token
					if (g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE && !aibot->hascase) {
						// Make an array of pointers to other teams' tokens
						// but ignore enemy tokens held by other teams
						s32 botteamindex = radarGetTeamIndex(chr->team);
						s32 i;
						struct prop *tokens[4];
						s32 numtokens = 0;

						for (i = 0; i != 4; i++) {
							if (i != botteamindex && g_ScenarioData.ctc.playercountsperteam[i]) {
								if (g_ScenarioData.ctc.tokens[i]->type == PROPTYPE_WEAPON
										|| g_ScenarioData.ctc.tokens[i]->type == PROPTYPE_OBJ) {
									// Token is not held
									tokens[numtokens++] = g_ScenarioData.ctc.tokens[i];
								} else if (g_ScenarioData.ctc.tokens[i]->type == PROPTYPE_CHR
										|| g_ScenarioData.ctc.tokens[i]->type == PROPTYPE_PLAYER) {
									// Token is held
									struct chrdata *tokenchr = g_ScenarioData.ctc.tokens[i]->chr;

									if (tokenchr->team == chr->team) {
										// Token is held by teammate
										tokens[numtokens++] = g_ScenarioData.ctc.tokens[i];
									}
								}
							}
						}

						// Prefer a token within 10 metres, otherwise pick any
						if (numtokens > 0) {
							s32 index;
							s32 i;

							index = random() % numtokens;

							i = (index + 1) % numtokens;

							while (true) {
								f32 sqdist = chrGetSquaredDistanceToCoord(chr, &tokens[i]->pos);

								if (sqdist < 1000 * 1000) {
									index = i;
									break;
								}

								if (i == index) {
									break;
								}

								i = (i + 1) % numtokens;
							}

							if (index);

							// If the chosen token is not held then collect it,
							// otherwise it's held by a teammate so go protect them
							if (tokens[index]->type == PROPTYPE_WEAPON || tokens[index]->type == PROPTYPE_OBJ) {
								newaction = MA_AIBOTGETITEM;
								aibot->gotoprop = tokens[index];
							} else if (botCanFollow(chr, tokens[index]->chr)) {
								newaction = MA_AIBOTFOLLOW;
								aibot->canbreakfollow = random() % 4 == 0;
								aibot->followingplayernum = mpPlayerGetIndex(tokens[index]->chr);
							}
						}
					}
				} else if (aibot->command == AIBOTCMD_SAVECASE) {
					// Capture the case - recover/protect bot's own token
					if (g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE) {
						// Find out where the bot's token is
						struct prop *token = g_ScenarioData.ctc.tokens[radarGetTeamIndex(chr->team)];

						if (token->type == PROPTYPE_CHR || token->type == PROPTYPE_PLAYER) {
							struct chrdata *tokenchr = token->chr;

							if (tokenchr->team == chr->team) {
								// Held by a teammate - follow/protect them
								if (botCanFollow(chr, tokenchr)) {
									newaction = MA_AIBOTFOLLOW;
									aibot->canbreakfollow = random() % 4 == 0;
									aibot->followingplayernum = mpPlayerGetIndex(tokenchr);
								}
							} else {
								// Held by an opponent - attack them
								if (!chrIsDead(tokenchr)
										&& !botIsTargetInvisible(chr, tokenchr)
										&& botPassesCowardCheck(chr, tokenchr)) {
									newaction = MA_AIBOTATTACK;
									aibot->attackingplayernum = mpPlayerGetIndex(tokenchr);
									aibot->abortattacktimer60 = -1;
								}
							}
						} else {
							// Token is not held - go to the pos to defend it
							newaction = MA_AIBOTGOTOPOS;
							aibot->gotopos.x = token->pos.x;
							aibot->gotopos.y = token->pos.y;
							aibot->gotopos.z = token->pos.z;
							roomsCopy(token->rooms, aibot->gotorooms);
							aibot->unk04c_00 = false;
						}
					}
				} else if (aibot->command == AIBOTCMD_DEFHILL) {
					// King of the hill - defend the hill (allow wandering out)
					if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL) {
						if (chr->prop->rooms[0] == g_ScenarioData.koh.hillrooms[0]
								&& chr->target != -1
								&& aibot->targetinsight
								&& botPassesCowardCheck(chr, chrGetTargetProp(chr)->chr)) {
							// Bot is in the hill and sees target - attack them
							newaction = MA_AIBOTATTACK;
							aibot->attackingplayernum = mpPlayerGetIndex(chrGetTargetProp(chr)->chr);
							aibot->abortattacktimer60 = 300;
						} else {
							// Go to the hill if not there already
							u32 stack;
							struct coord posinhill;
							f32 angle;
							s32 padnuminhill;
							s32 covernuminhill;

							if (botroomFindPos(g_ScenarioData.koh.hillrooms[0], &posinhill, &angle, &padnuminhill, &covernuminhill)) {
								newaction = MA_AIBOTGOTOPOS;
								aibot->gotopos.x = posinhill.x;
								aibot->gotopos.y = posinhill.y;
								aibot->gotopos.z = posinhill.z;
								roomsCopy(g_ScenarioData.koh.hillrooms, aibot->gotorooms);
								aibot->unk04c_00 = (chr->prop->rooms[0] == g_ScenarioData.koh.hillrooms[0]) != 0;
								aibot->hillpadnum = padnuminhill;
								aibot->hillcovernum = covernuminhill;
								aibot->lastknownhill = g_ScenarioData.koh.hillrooms[0];
							}
						}
					}
				} else if (aibot->command == AIBOTCMD_HOLDHILL) {
					// King of the hill - hold the hill (don't wander out)
					if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL) {
						struct coord posinhill;
						f32 angle;
						s32 padnuminhill;
						s32 covernuminhill;

						// Go to the hill if not there already
						if (botroomFindPos(g_ScenarioData.koh.hillrooms[0], &posinhill, &angle, &padnuminhill, &covernuminhill)) {
							newaction = MA_AIBOTGOTOPOS;
							aibot->gotopos.x = posinhill.x;
							aibot->gotopos.y = posinhill.y;
							aibot->gotopos.z = posinhill.z;
							roomsCopy(g_ScenarioData.koh.hillrooms, aibot->gotorooms);
							aibot->unk04c_00 = (chr->prop->rooms[0] == g_ScenarioData.koh.hillrooms[0]) != 0;
							aibot->hillpadnum = padnuminhill;
							aibot->hillcovernum = covernuminhill;
							aibot->lastknownhill = g_ScenarioData.koh.hillrooms[0];
						}
					}
				} else if (aibot->command == AIBOTCMD_DOWNLOAD) {
					// Hacker Central - fetch uplink
					if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL
							&& g_ScenarioData.htm.uplink
							&& g_ScenarioData.htm.uplink != chr->prop) {
						// Uplink is not held by current bot
						if (g_ScenarioData.htm.uplink->type == PROPTYPE_CHR
								|| g_ScenarioData.htm.uplink->type == PROPTYPE_PLAYER) {
							struct chrdata *uplinkchr = g_ScenarioData.htm.uplink->chr;

							if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) && uplinkchr->team == chr->team) {
								// Uplink is held by teammate - protect them
								if (botCanFollow(chr, uplinkchr)) {
									newaction = MA_AIBOTFOLLOW;
									aibot->canbreakfollow = random() % 4 == 0;
									aibot->followingplayernum = mpPlayerGetIndex(uplinkchr);
								}
							} else {
								// Uplink is held by opponent - attack them
								if (!botIsTargetInvisible(chr, uplinkchr) && botPassesCowardCheck(chr, uplinkchr)) {
									newaction = MA_AIBOTATTACK;
									aibot->attackingplayernum = mpPlayerGetIndex(uplinkchr);
									aibot->abortattacktimer60 = -1;
								}
							}
						} else {
							// Uplink is not held by anyone - fetch it
							newaction = MA_AIBOTGOTOPROP;
							aibot->gotoprop = g_ScenarioData.htm.uplink;
						}
					}
				} else if (aibot->command == AIBOTCMD_GETCASE2) {
					// Hold the briefcase - fetch and hold the case
					if (g_MpSetup.scenario == MPSCENARIO_HOLDTHEBRIEFCASE
							&& g_ScenarioData.htb.token
							&& g_ScenarioData.htb.token != chr->prop) {
						// Briefcase is not held by current bot
						if (g_ScenarioData.htb.token->type == PROPTYPE_CHR
								|| g_ScenarioData.htb.token->type == PROPTYPE_PLAYER) {
							struct chrdata *tokenchr = g_ScenarioData.htb.token->chr;

							if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) && tokenchr->team == chr->team) {
								// Briefcase is held by teammate - protect them
								if (botCanFollow(chr, tokenchr)) {
									newaction = MA_AIBOTFOLLOW;
									aibot->canbreakfollow = random() % 4 == 0;
									aibot->followingplayernum = mpPlayerGetIndex(tokenchr);
								}
							} else if (!botIsTargetInvisible(chr, tokenchr) && botPassesCowardCheck(chr, tokenchr)) {
								// Briefcase is held by opponent - attack them
								newaction = MA_AIBOTATTACK;
								aibot->attackingplayernum = mpPlayerGetIndex(tokenchr);
								aibot->abortattacktimer60 = -1;
							}
						} else {
							// Briefcase is not held by anyone - fetch it
							newaction = MA_AIBOTGOTOPROP;
							aibot->gotoprop = g_ScenarioData.htb.token;
						}
					}
				} else if (aibot->command == AIBOTCMD_POPCAP) {
					// Pop a cap - attack the target
					if (g_MpSetup.scenario == MPSCENARIO_POPACAP && g_ScenarioData.pac.victimindex >= 0) {
						struct prop *victimprop = g_MpAllChrPtrs[g_ScenarioData.pac.victims[g_ScenarioData.pac.victimindex]]->prop;

						if (victimprop != chr->prop) {
							// Victim is not the current bot
							struct chrdata *victimchr = victimprop->chr;

							if ((g_MpSetup.options & MPOPTION_TEAMSENABLED) && victimchr->team == chr->team) {
								// Victim is a teammate - protect them
								if (botCanFollow(chr, victimchr)) {
									newaction = MA_AIBOTFOLLOW;
									aibot->canbreakfollow = random() % 4 == 0;
									aibot->followingplayernum = mpPlayerGetIndex(victimchr);
								}
							} else {
								// Victim is an opponent - attack them
								if (!botIsTargetInvisible(chr, victimchr) && botPassesCowardCheck(chr, victimchr)) {
									newaction = MA_AIBOTATTACK;
									aibot->attackingplayernum = mpPlayerGetIndex(victimchr);
									aibot->abortattacktimer60 = -1;
								}
							}
						}
					}
				}
			}

			// The bot can still not have an action if it's general combat, or
			// in some situations like having the uplink in Hacker Central or
			// holding the briefcase in Hold the Briefcase.
			if (newaction < 0) {
				if (g_MpSetup.scenario == MPSCENARIO_HOLDTHEBRIEFCASE) {
					if (aibot->hasbriefcase) {
						// Current bot has the briefcase - follow a teammate for protection
						s32 playernum = -1;

						if (random() % 100 < 66) {
							playernum = botFindTeammateToFollow(chr, 100000);
						}

						if (playernum >= 0) {
							newaction = MA_AIBOTFOLLOW;
							aibot->canbreakfollow = random() % 4 == 0;
							aibot->followingplayernum = playernum;
						}
					}
				} else if (g_MpSetup.scenario == MPSCENARIO_POPACAP) {
					if (g_ScenarioData.pac.victimindex >= 0) {
						struct prop *victimprop = g_MpAllChrPtrs[g_ScenarioData.pac.victims[g_ScenarioData.pac.victimindex]]->prop;

						if (victimprop == chr->prop) {
							// Current bot is the victim - follow a teammate for protection
							s32 playernum = -1;

							if (random() % 100 < 66) {
								playernum = botFindTeammateToFollow(chr, 100000);
							}

							if (playernum >= 0) {
								newaction = MA_AIBOTFOLLOW;
								aibot->canbreakfollow = random() % 4 == 0;
								aibot->followingplayernum = playernum;
							}
						}
					}
				} else if (g_MpSetup.scenario == MPSCENARIO_CAPTURETHECASE) {
					// If the bot is holding an opponent's token, take it home
					if (botShouldReturnCtcToken(chr)) {
						struct pad pad;
						s32 teamindex = g_ScenarioData.ctc.teamindexes[radarGetTeamIndex(chr->team)];
						newaction = MA_AIBOTGOTOPOS;
						padUnpack(g_ScenarioData.ctc.spawnpadsperteam[teamindex].homepad, PADFIELD_POS | PADFIELD_ROOM, &pad);
						aibot->gotopos.x = pad.pos.x;
						aibot->gotopos.y = pad.pos.y;
						aibot->gotopos.z = pad.pos.z;
						aibot->gotorooms[0] = pad.room;
						aibot->gotorooms[1] = -1;
						aibot->unk04c_00 = false;
					}
				} else if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL) {
					// If the bot has the uplink, go to the terminal
					if (g_ScenarioData.htm.uplink == chr->prop) {
						if (g_ScenarioData.htm.playernuminrange != mpPlayerGetIndex(chr)) {
							newaction = MA_AIBOTGOTOPROP;
							aibot->gotoprop = g_ScenarioData.htm.terminals[0].prop;
						} else {
							newaction = MA_AIBOTDOWNLOAD;
						}
					}
				}
			}

			// If there's nothing to do for scenarios then go find some people to kill
			if (newaction < 0) {
				if (aibot->config->type == BOTTYPE_VENGE) {
					// Attack the last player who killed the bot
					if (aibot->lastkilledbyplayernum >= 0
							&& !botIsTargetInvisible(chr, g_MpAllChrPtrs[aibot->lastkilledbyplayernum])) {
						newaction = MA_AIBOTATTACK;
						aibot->attackingplayernum = aibot->lastkilledbyplayernum;
						aibot->abortattacktimer60 = -1;
					}
				} else if (aibot->config->type == BOTTYPE_FEUD) {
					// Attack a single player the whole match
					if (aibot->feudplayernum < 0
							&& aibot->lastkilledbyplayernum >= 0
							&& !chrCompareTeams(chr, g_MpAllChrPtrs[aibot->lastkilledbyplayernum], COMPARE_FRIENDS)) {
						aibot->feudplayernum = aibot->lastkilledbyplayernum;
					}

					if (aibot->feudplayernum >= 0 && !botIsTargetInvisible(chr, g_MpAllChrPtrs[aibot->feudplayernum])) {
						newaction = MA_AIBOTATTACK;
						aibot->abortattacktimer60 = -1;
						aibot->attackingplayernum = aibot->feudplayernum;
					}
				} else if (aibot->config->type == BOTTYPE_JUDGE) {
					// Attack the winning player
					struct ranking rankings[MAX_MPCHRS];
					s32 count = mpGetPlayerRankings(rankings);
					s32 i;

					for (i = 0; i < count; i++) {
						s32 playernum = func0f18d0e8(rankings[i].chrnum);
						struct chrdata *otherchr = mpGetChrFromPlayerIndex(playernum);

						if (otherchr != chr
								&& !chrIsDead(otherchr)
								&& chrCompareTeams(chr, otherchr, COMPARE_ENEMIES)
								&& !botIsTargetInvisible(chr, otherchr)) {
							newaction = MA_AIBOTATTACK;
							aibot->attackingplayernum = playernum;
							aibot->abortattacktimer60 = -1;
						}
					}
				} else if (aibot->config->type == BOTTYPE_PREY) {
					// Attack the weakest player
					f32 minhealth = 0;
					s32 weakestplayernum = -1;
					f32 health;
					s32 i;

					for (i = 0; i < g_MpNumChrs; i++) {
						struct chrdata *otherchr = mpGetChrFromPlayerIndex(i);

						if (otherchr != chr
								&& !chrIsDead(otherchr)
								&& chrCompareTeams(chr, otherchr, COMPARE_ENEMIES)
								&& !botIsTargetInvisible(chr, otherchr)) {
							if (otherchr->aibot) {
								health = otherchr->maxdamage - otherchr->damage;
							} else {
								health = g_Vars.players[playermgrGetPlayerNumByProp(otherchr->prop)]->bondhealth * 8;
							}

							if (weakestplayernum < 0 || health < minhealth) {
								weakestplayernum = i;
								minhealth = health;
							}
						}
					}

					if (weakestplayernum >= 0) {
						newaction = MA_AIBOTATTACK;
						aibot->attackingplayernum = weakestplayernum;
						aibot->abortattacktimer60 = -1;
					}
				}
			}

			// If the bot didn't set an action above,
			// try attacking the existing target
			if (newaction < 0) {
				if (chr->target != -1 && botPassesCowardCheck(chr, chrGetTargetProp(chr)->chr)) {
					newaction = MA_AIBOTATTACK;
					aibot->abortattacktimer60 = -1;
				}
			}

			// If there's no existing target, just follow a teammate
			if (newaction < 0) {
				s32 playernum = botFindTeammateToFollow(chr, 300);

				if (playernum >= 0) {
					newaction = MA_AIBOTFOLLOW;
					aibot->canbreakfollow = random() % 4 == 0;
					aibot->followingplayernum = playernum;
				}
			}

			// If there's no teammate to follow, stock up on weapons and ammo
			if (newaction < 0) {
				aibot->gotoprop = botFindAnyPickup(chr);

				if (aibot->gotoprop) {
					newaction = MA_AIBOTGETITEM;
				}
			}
		}

		// Implement the new action
		if (newaction >= 0) {
			if (newaction == MA_AIBOTGETITEM) {
				if (aibot->gotoprop) {
					chrGoToProp(chr, aibot->gotoprop, SPEED_RUN);
					chr->myaction = newaction;
				}
			} else if (newaction == MA_AIBOTATTACK) {
				if (chr->myaction != MA_AIBOTATTACK) {
					chr->myaction = newaction;
					aibot->distmode = -1;
				}
			} else if (newaction == MA_AIBOTFOLLOW) {
				if (chr->myaction != MA_AIBOTFOLLOW) {
					chr->myaction = newaction;
					aibot->distmode = -1;

					if (aibot->canbreakfollow) {
						botSetTarget(chr, -1);
					}
				}
			} else if (newaction == MA_AIBOTDEFEND) {
				chr->myaction = newaction;

				if (aibot->canbreakdefend) {
					botSetTarget(chr, -1);
				}

				chrGoToPos(chr, &aibot->defendholdpos, aibot->defendholdrooms, SPEED_RUN);
			} else if (newaction == MA_AIBOTGOTOPOS) {
				f32 xdist = chr->prop->pos.x - aibot->gotopos.x;
				f32 ydist = chr->prop->pos.y - aibot->gotopos.y;
				f32 zdist = chr->prop->pos.z - aibot->gotopos.z;

				if (xdist < 0) {
					xdist = -xdist;
				}

				if (ydist < 0) {
					ydist = -ydist;
				}

				if (zdist < 0) {
					zdist = -zdist;
				}

				if (xdist > 20 || zdist > 20 || (ydist > 200 && chr->inlift == 0)) {
					chr->myaction = newaction;
					chrGoToPos(chr, &aibot->gotopos, aibot->gotorooms, SPEED_RUN);
				} else {
					chrStand(chr);
				}
			} else if (newaction == MA_AIBOTGOTOPROP) {
				if (aibot->gotoprop) {
					chr->myaction = newaction;
					chrGoToProp(chr, aibot->gotoprop, SPEED_RUN);
				}
			} else if (newaction == MA_AIBOTDOWNLOAD) {
				chr->myaction = newaction;
				chrStand(chr);
			}
		}

		// If the action is no longer valid, go back to the main loop
		// so another action can be chosen on the next tick
		if (chr->myaction == MA_AIBOTGETITEM) {
			if (chr->actiontype != ACT_GOPOS
					|| aibot->gotoprop == NULL
					|| aibot->gotoprop->parent
					|| aibot->gotoprop->timetoregen != 0) {
				chr->myaction = MA_AIBOTMAINLOOP;
			}
		} else if (chr->myaction == MA_AIBOTATTACK) {
			if (aibot->attackingplayernum >= 0
					&& (chrIsDead(g_MpAllChrPtrs[aibot->attackingplayernum]) || !botPassesCowardCheck(chr, g_MpAllChrPtrs[aibot->attackingplayernum]))) {
				chr->myaction = MA_AIBOTMAINLOOP;
			} else if (aibot->attackingplayernum < 0
					&& (chr->target == -1
						|| chrIsDead(chrGetTargetProp(chr)->chr)
						|| !botPassesCowardCheck(chr, chrGetTargetProp(chr)->chr))) {
				chr->myaction = MA_AIBOTMAINLOOP;
			} else {
				botcmdTickDistMode(chr);

				if (botCanDoCriticalPickup(chr)) {
					chr->myaction = MA_AIBOTMAINLOOP;
				} else if (aibot->abortattacktimer60 >= 0 && aibot->targetlastseen60 < g_Vars.lvframe60 - aibot->abortattacktimer60) {
					chr->myaction = MA_AIBOTMAINLOOP;
				}
			}
		} else if (chr->myaction == MA_AIBOTFOLLOW) {
			if (aibot->followingplayernum < 0
					|| chrIsDead(g_MpAllChrPtrs[aibot->followingplayernum])) {
				chr->myaction = MA_AIBOTMAINLOOP;
			} else {
				botcmdTickDistMode(chr);

				if (aibot->canbreakfollow
						&& chr->target != -1
						&& aibot->targetinsight
						&& botPassesCowardCheck(chr, chrGetTargetProp(chr)->chr)) {
					f32 xdist = chr->prop->pos.x - g_MpAllChrPtrs[aibot->followingplayernum]->prop->pos.x;
					f32 zdist = chr->prop->pos.z - g_MpAllChrPtrs[aibot->followingplayernum]->prop->pos.z;

					if (xdist < 0) {
						xdist = -xdist;
					}

					if (zdist < 0) {
						zdist = -zdist;
					}

					// No y check?
					if (xdist < 500 && zdist < 500) {
						chr->myaction = MA_AIBOTATTACK;
						aibot->attackingplayernum = mpPlayerGetIndex(chrGetTargetProp(chr)->chr);
						aibot->abortattacktimer60 = 300;
						aibot->distmode = -1;
					}
				}

				if (botCanDoCriticalPickup(chr)) {
					chr->myaction = MA_AIBOTMAINLOOP;
				}
			}
		} else if (chr->myaction == MA_AIBOTDEFEND) {
			if (chr->actiontype != ACT_GOPOS) {
				f32 xdist = chr->prop->pos.x - aibot->defendholdpos.x;
				f32 ydist = chr->prop->pos.y - aibot->defendholdpos.y;
				f32 zdist = chr->prop->pos.z - aibot->defendholdpos.z;

				if (xdist < 0) {
					xdist = -xdist;
				}

				if (ydist < 0) {
					ydist = -ydist;
				}

				if (zdist < 0) {
					zdist = -zdist;
				}

				if (aibot->returntodefendtimer60 > 0) {
					aibot->returntodefendtimer60 -= g_Vars.lvupdate240_60;
				}

				if (xdist > 40 || zdist > 40 || (ydist > 200 && !chr->inlift)) {
					if (aibot->returntodefendtimer60 <= 0) {
						chrGoToPos(chr, &aibot->defendholdpos, aibot->defendholdrooms, SPEED_RUN);
					}
				} else if (aibot->canbreakdefend
						&& chr->target != -1
						&& aibot->targetinsight
						&& botPassesCowardCheck(chr, chrGetTargetProp(chr)->chr)) {
					chr->myaction = MA_AIBOTATTACK;
					aibot->attackingplayernum = mpPlayerGetIndex(chrGetTargetProp(chr)->chr);
					aibot->abortattacktimer60 = 300;
					aibot->distmode = -1;
				}

				if (aibot->returntodefendtimer60 <= 0) {
					aibot->returntodefendtimer60 = 60;
				}
			}

			if (botCanDoCriticalPickup(chr)) {
				chr->myaction = MA_AIBOTMAINLOOP;
			}
		} else if (chr->myaction == MA_AIBOTGOTOPOS) {
			if (g_MpSetup.scenario == MPSCENARIO_KINGOFTHEHILL && aibot->unk04c_00) {
				if (aibot->lastknownhill != g_ScenarioData.koh.hillrooms[0]) {
					// Someone scored the hill
					aibot->unk04c_00 = false;
				} else if (chr->prop->rooms[0] == g_ScenarioData.koh.hillrooms[0]) {
					// empty
				} else if (aibot->hillpadnum >= 0) {
					padSetFlag(aibot->hillpadnum, PADFLAG_20000);
				} else if (aibot->hillcovernum >= 0) {
					coverSetFlag(aibot->hillcovernum, COVERFLAG_0100);
				}
			}

			if (chr->actiontype != ACT_GOPOS) {
				chr->myaction = MA_AIBOTMAINLOOP;
			} else if (botCanDoCriticalPickup(chr)) {
				chr->myaction = MA_AIBOTMAINLOOP;
			}
		} else if (chr->myaction == MA_AIBOTGOTOPROP) {
			if (botCanDoCriticalPickup(chr)) {
				chr->myaction = MA_AIBOTMAINLOOP;
			} else if (chr->actiontype != ACT_GOPOS || aibot->gotoprop == NULL || aibot->gotoprop->parent) {
				chr->myaction = MA_AIBOTMAINLOOP;
			} else if (g_MpSetup.scenario == MPSCENARIO_HOLDTHEBRIEFCASE) {
				// empty
			} else if (g_MpSetup.scenario == MPSCENARIO_HACKERCENTRAL
					&& g_ScenarioData.htm.uplink == chr->prop
					&& g_ScenarioData.htm.playernuminrange == mpPlayerGetIndex(chr)) {
				chr->myaction = MA_AIBOTMAINLOOP;
			}
		} else if (chr->myaction == MA_AIBOTDOWNLOAD) {
			if (botCanDoCriticalPickup(chr)) {
				chr->myaction = MA_AIBOTMAINLOOP;
			} else if (g_ScenarioData.htm.playernuminrange != mpPlayerGetIndex(chr)) {
				chr->myaction = MA_AIBOTMAINLOOP;
			}
		}

		// Regardless of the action, choose a general target and maintain a
		// route to them, even if it won't be followed
		botChooseGeneralTarget(chr);

		if (mpPlayerGetIndex(chr) == (g_Vars.lvframenum % g_MpNumChrs) && chr->target != -1) {
			struct prop *targetprop = chrGetTargetProp(chr);
			struct waypoint *first = waypointFindClosestToPos(&chr->prop->pos, chr->prop->rooms);
			struct waypoint *last = waypointFindClosestToPos(&targetprop->pos, targetprop->rooms);

			if (first && last) {
				s32 hash = (g_Vars.lvframe60 >> 9) * 128 + chr->chrnum * 8;
				waypointSetHashThing(hash, hash);
				aibot->unk208 = waypointFindRoute(last, first, aibot->waypoints, ARRAYCOUNT(aibot->waypoints));
				waypointSetHashThing(0, 0);
			}
		}

		// Tick the bot's inventory. They may decide to switch weapons.
		botinvTick(chr);

		// Iterate both hands and handle shooting
		{
			bool firingright = false;
			s32 i;

			for (i = 0; i < 2; i++) {
				bool firing = false;

				// nextbullettimer60 is positive if the chr is firing
				// It's used to implement the weapon's fire rate correctly
				if (aibot->nextbullettimer60[i] > 0) {
					aibot->nextbullettimer60[i] -= g_Vars.lvupdate240_60;
				}

				// Don't shoot the left hand on the same frame as the right
				// (note that right is iterated first)
				if (i == HAND_LEFT && firingright) {
					aibot->nextbullettimer60[i] = 1;
				}

				if (aibot->skrocket == NULL && aibot->changeguntimer60 <= 0) {
					if (aibot->iscloserangeweapon) {
						// Consider punching, pistol whipping etc
						// Despite the name, punchtimer60 is used for all close
						// range attacks. Its value is 0 if not currently
						// punching, positive (and ticking down) when cooling
						// down from a previous punch, and negative when
						// starting the punch.
						if (aibot->punchtimer60[i] >= 0 && aibot->timeuntilreload60[i] <= 0) {
							if (aibot->weaponnum == WEAPON_TRANQUILIZER
									&& aibot->loadedammo[i] < bgunGetMinClipQty(WEAPON_TRANQUILIZER, FUNC_SECONDARY)) {
								aibot->punchtimer60[i] = 0;
								botScheduleReload(chr, i);
							} else {
								f32 range = 210;

								// Decide whether to actually punch or not.
								// This seems a bit backwards in that the timer
								// is set to negative (ie. punch) then the check
								// below has to cancel it by setting it back to 0.
								aibot->punchtimer60[i] -= g_Vars.lvupdate240_60;

								if (chr->target != -1
										&& aibot->targetinsight
										&& aibot->shootdelaytimer60 >= g_BotDifficulties[aibot->config->difficulty].shootdelay) {
									if (!botIsDizzy(chr)) {
										if (aibot->weaponnum == WEAPON_TRANQUILIZER) {
											if (!chrIsTargetInFov(chr, 30, 0) || chrGetDistanceToTarget(chr) > range) {
												aibot->punchtimer60[i] = 0;
											}
										} else {
											if (!chrIsTargetInFov(chr, 40, 0) || chrGetDistanceToTarget(chr) > range + 150) {
												aibot->punchtimer60[i] = 0;
											}
										}
									}
								} else {
									aibot->punchtimer60[i] = 0;
								}

								// If the punch was not cancelled, execute it
								if (aibot->punchtimer60[i] < 0) {
									chrUncloakTemporarily(chr);
									chrPunchInflictDamage(chr, 2, range, false);

									if (i == HAND_RIGHT) {
										// Set the punch cooldown timer
										switch (aibot->weaponnum) {
										case WEAPON_UNARMED:
										case WEAPON_MAGSEC4:
										case WEAPON_MAULER:
										case WEAPON_PHOENIX:
										case WEAPON_CMP150:
										case WEAPON_CYCLONE:
										case WEAPON_CALLISTO:
										case WEAPON_RCP120:
										case WEAPON_LAPTOPGUN:
										case WEAPON_DRAGON:
										case WEAPON_K7AVENGER:
										case WEAPON_AR34:
										case WEAPON_SUPERDRAGON:
										case WEAPON_SHOTGUN:
										case WEAPON_SNIPERRIFLE:
										case WEAPON_FARSIGHT:
										case WEAPON_DEVASTATOR:
										case WEAPON_ROCKETLAUNCHER:
										case WEAPON_SLAYER:
										case WEAPON_CROSSBOW:
										default:
											if (chr->aibot->config->difficulty == BOTDIFF_MEAT) {
												aibot->punchtimer60[0] = 120;
											} else if (chr->aibot->config->difficulty == BOTDIFF_EASY) {
												aibot->punchtimer60[0] = 60;
											} else {
												aibot->punchtimer60[0] = 30;
											}

											if (random() % 3 == 0) {
												aibot->punchtimer60[1] = aibot->punchtimer60[0] - 20;
											}
											break;
										case WEAPON_FALCON2:
										case WEAPON_FALCON2_SILENCER:
										case WEAPON_FALCON2_SCOPE:
										case WEAPON_DY357MAGNUM:
										case WEAPON_DY357LX:
										case WEAPON_COMBATKNIFE:
											if (chr->aibot->config->difficulty == BOTDIFF_MEAT) {
												aibot->punchtimer60[0] = 120;
											} else if (chr->aibot->config->difficulty == BOTDIFF_EASY) {
												aibot->punchtimer60[0] = 90;
											} else {
												aibot->punchtimer60[0] = 60;
											}

											if (chr->weapons_held[HAND_LEFT]) {
												aibot->punchtimer60[1] = aibot->punchtimer60[0] - 40;
											}
											break;
										case WEAPON_TRANQUILIZER:
											aibot->punchtimer60[0] = 60;
											aibot->loadedammo[0] -= bgunGetMinClipQty(WEAPON_TRANQUILIZER, FUNC_SECONDARY);
											break;
										case WEAPON_REAPER:
											aibot->punchtimer60[0] = 0;
											break;
										}
									}
								}
							}
						}
					} else if (aibot->weaponnum == WEAPON_SLAYER && aibot->gunfunc != FUNC_PRIMARY && chr->target != -1) {
						// Bots fire Slayer rockets regardless of where they are
						// on the map provided they have ammo
						if (aibot->loadedammo[0] > 0) {
							chrUncloakTemporarily(chr);
							botactCreateSlayerRocket(chr);
							aibot->loadedammo[0]--;
						}
					} else if (botactIsWeaponThrowable(aibot->weaponnum, aibot->gunfunc)) {
						// Hand throwing a weapon
						if (i == HAND_RIGHT) {
							if (aibot->throwtimer60 > 0) {
								aibot->throwtimer60 -= g_Vars.lvupdate240_60;
							}

							if (chr->aibot->throwtimer60 <= 0) {
								if (botactGetAmmoQuantityByWeapon(aibot, aibot->weaponnum, aibot->gunfunc, false) > 0
										|| aibot->weaponnum == WEAPON_LAPTOPGUN
										|| aibot->weaponnum == WEAPON_DRAGON) {
									bool throw = false;

									if (chr->target != -1
											&& aibot->targetinsight
											&& aibot->shootdelaytimer60 >= g_BotDifficulties[aibot->config->difficulty].shootdelay
											&& (botIsDizzy(chr) || chrIsTargetInFov(chr, 45, false))) {
										throw = true;
									}

									if (throw) {
										struct weaponfunc *func;

										chrUncloakTemporarily(chr);
										botactTryRemoveAmmoFromReserve(aibot, aibot->weaponnum, aibot->gunfunc, 1);
										botact0f19a37c(chr);

										func = weaponGetFunctionById(aibot->weaponnum, aibot->gunfunc);

										if (func && (func->flags & FUNCFLAG_DISCARDWEAPON)) {
											botinvRemoveItem(chr, aibot->weaponnum);
											botinvSwitchToWeapon(chr, WEAPON_UNARMED, FUNC_PRIMARY);
										}

										aibot->throwtimer60 = botactGetProjectileThrowInterval(chr->aibot->weaponnum);
									}
								}
							}
						}
					} else if (chr->weapons_held[i] && aibot->loadedammo[i] > 0) {
						// Handle firing a regular weapon
						bool canshoot = false;

						if (weaponGetNumTicksPerShot(aibot->weaponnum, aibot->gunfunc) <= 0) {
							// Increment the mauler charge and deplete ammo as
							// the charge amount crosses each whole number.
							// Yes, this is actually implemented for bots.
							if (aibot->weaponnum == WEAPON_MAULER
									&& aibot->gunfunc == FUNC_SECONDARY
									&& aibot->loadedammo[i] >= 2) {
								s32 newchargei;
								s32 oldchargei = aibot->maulercharge[i];

								aibot->maulercharge[i] += g_Vars.lvupdate240freal * 0.05f;

								if (aibot->maulercharge[i] > 5) {
									aibot->maulercharge[i] = 5;
								}

								newchargei = aibot->maulercharge[i];

								if (newchargei != oldchargei) {
									aibot->loadedammo[i]--;
								}
							}

							if (aibot->nextbullettimer60[i] <= 0) {
								canshoot = true;
							}
						} else {
							canshoot = true;
						}

						if (canshoot) {
							if (aibot->cyclonedischarging[i] || aibot->burstsdone[i] > 0) {
								firing = true;
							} else if (chr->target != -1
									&& aibot->targetinsight
									&& aibot->shootdelaytimer60 >= g_BotDifficulties[aibot->config->difficulty].shootdelay
									&& (botIsDizzy(chr) || chrIsTargetInFov(chr, 45, false))
									&& !chrIsDead(chrGetTargetProp(chr)->chr)) {
								firing = true;

								if (aibot->weaponnum == WEAPON_CYCLONE && aibot->gunfunc == FUNC_SECONDARY) {
									aibot->cyclonedischarging[i] = true;
								} else if (aibot->weaponnum == WEAPON_REAPER) {
									aibot->reaperspeed[i] += g_Vars.lvupdate240_60;

									if (aibot->reaperspeed[i] > 90) {
										aibot->reaperspeed[i] = 90;
									}
								}
							}

							// The Reaper continues shooting momentarily when
							// the trigger is released
							if (!firing && aibot->reaperspeed[i] > 0) {
								firing = true;

								aibot->reaperspeed[i] -= g_Vars.lvupdate240_60;

								if (aibot->reaperspeed[i] < 0) {
									aibot->reaperspeed[i] = 0;
								}
							}
						}

						if (weaponGetNumTicksPerShot(aibot->weaponnum, aibot->gunfunc) <= 0 && firing) {
							struct weaponfunc *func;
							aibot->nextbullettimer60[i] = botactGetShootInterval60(aibot->weaponnum, aibot->gunfunc);

#if PAL
							if (aibot->nextbullettimer60[i] >= 6) {
								aibot->nextbullettimer60[i] = aibot->nextbullettimer60[i] * 50 / 60;
							}
#endif

							func = weaponGetFunctionById(aibot->weaponnum, aibot->gunfunc);

							if (func
									&& (func->flags & (FUNCFLAG_BURST3 | FUNCFLAG_BURST2))
									&& aibot->loadedammo[i] >= 2) {
								s32 burstqty = (func->flags & FUNCFLAG_BURST2) ? 2 : 3;

								chr->aibot->burstsdone[i]++;
								chr->aibot->burstsdone[i] %= burstqty;

								if (chr->aibot->burstsdone[i]) {
									chr->aibot->nextbullettimer60[i] = 5;
								}
							}
						}
					} else {
						aibot->cyclonedischarging[i] = false;
						aibot->burstsdone[i] = 0;
						aibot->reaperspeed[i] = 0;
					}
				}

				if (firing) {
					chrUncloakTemporarily(chr);

					if (i == HAND_RIGHT) {
						firingright = true;
					}
				}

				chrSetHandFiring(chr, i, firing);
			}
		}
	}
}
#endif

void botCheckFetch(struct chrdata *chr)
{
	bool alreadyfetching = false;
	struct aibot *aibot = chr->aibot;

	if (chr->myaction == MA_AIBOTGETITEM) {
		if (chr->act_gopos.waypoints[chr->act_gopos.curindex] == 0) {
			struct prop *prop = aibot->gotoprop;

#if VERSION >= VERSION_PAL_FINAL
			// pal-final adds a check for prop->obj
			if (prop && prop->obj && !prop->parent && prop->timetoregen == 0) {
				if (prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_OBJ) {
					prop->obj->flags3 |= OBJFLAG3_ISFETCHTARGET;
				}
			}
#else
			if (prop && !prop->parent && prop->timetoregen == 0) {
				if (prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_OBJ) {
					prop->obj->flags3 |= OBJFLAG3_ISFETCHTARGET;
				}
			}
#endif
		}

		aibot->forcemainloop = true;
		alreadyfetching = true;
	}

	if (!alreadyfetching) {
		chrGoToPos(chr, &chr->act_gopos.endpos, chr->act_gopos.endrooms, chr->act_gopos.flags);
	}
}
