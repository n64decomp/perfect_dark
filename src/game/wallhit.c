#include <ultra64.h>
#include "constants.h"
#include "game/dlights.h"
#include "game/chr.h"
#include "game/game_0b0fd0.h"
#include "game/tex.h"
#include "game/playermgr.h"
#include "game/room.h"
#include "game/gfxmemory.h"
#include "game/file.h"
#include "game/options.h"
#include "game/utils.h"
#include "game/wallhit.h"
#include "bss.h"
#include "lib/main.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

#define WALLHITTYPE_SOFT   0
#define WALLHITTYPE_BULLET 1
#define WALLHITTYPE_SCORCH 2
#define WALLHITTYPE_BLOOD  3
#define WALLHITTYPE_PAINT  4

#define IS_BLOOD_DROP(texnum) (texnum >= WALLHITTEX_BLOOD4 && texnum <= WALLHITTEX_BLOOD4)

const char var7f1b5a10[] = "WallHit_MakeSpaceRoom : ERROR - Couldn't find any space in room %d\n";

struct wallhit *g_Wallhits;
struct wallhit *g_FreeWallhits;
struct wallhit *g_ActiveWallhits;

s32 var8007f740 = 0;
u8 g_WallhitBloodColour[4] = {0x40, 0x0a, 0x0a, 0x00};
f32 var8007f748 = 1;
f32 var8007f74c = 1;
u32 var8007f750 = 0;
f32 var8007f754 = 0;
f32 var8007f758 = 0;

struct wallhittex {
	f32 width;
	f32 height;
	u8 type;
};

struct wallhittex g_WallhitTexes[] = {
	/*0x00*/ { 10,  10,  WALLHITTYPE_BULLET }, // WALLHITTEX_WATER
	/*0x01*/ { 6,   6,   WALLHITTYPE_BULLET }, // WALLHITTEX_BULLET1
	/*0x02*/ { 8,   8,   WALLHITTYPE_SOFT   }, // WALLHITTEX_SOFT
	/*0x03*/ { 6,   6,   WALLHITTYPE_BULLET }, // WALLHITTEX_GLASS1
	/*0x04*/ { 8,   8,   WALLHITTYPE_BULLET }, // WALLHITTEX_GLASS2
	/*0x05*/ { 12,  12,  WALLHITTYPE_BULLET }, // WALLHITTEX_GLASS3
	/*0x06*/ { 6,   6,   WALLHITTYPE_BULLET }, // WALLHITTEX_BULLET2
	/*0x07*/ { 100, 100, WALLHITTYPE_SCORCH }, // WALLHITTEX_SCORCH
	/*0x08*/ { 24,  24,  WALLHITTYPE_PAINT  }, // WALLHITTEX_PAINT
	/*0x09*/ { 20,  20,  WALLHITTYPE_BLOOD  }, // WALLHITTEX_BLOOD1
	/*0x0a*/ { 20,  20,  WALLHITTYPE_BLOOD  }, // WALLHITTEX_BLOOD2
	/*0x0b*/ { 20,  20,  WALLHITTYPE_BLOOD  }, // WALLHITTEX_BLOOD3
	/*0x0c*/ { 20,  20,  WALLHITTYPE_BLOOD  }, // WALLHITTEX_BLOOD4
	/*0x0d*/ { 6,   6,   WALLHITTYPE_BULLET }, // WALLHITTEX_BPGLASS1
	/*0x0e*/ { 8,   8,   WALLHITTYPE_BULLET }, // WALLHITTEX_BPGLASS2
	/*0x0f*/ { 12,  12,  WALLHITTYPE_BULLET }, // WALLHITTEX_BPGLASS3
	/*0x10*/ { 4,   4,   WALLHITTYPE_BULLET }, // WALLHITTEX_WOOD
	/*0x11*/ { 6,   6,   WALLHITTYPE_BULLET }, // WALLHITTEX_METAL
};

s16 wallhitFinaliseAxis(f32 value)
{
	if (value > var8007f754) {
		var8007f754 = value;
	} else if (-value > var8007f758) {
		var8007f758 = -value;
	}

	if (value > 8000) {
		value = 8000;
	} else if (value < -8000) {
		value = -8000;
	}

	if (value > 0) {
		value += 0.5f;
	} else {
		value -= 0.5f;
	}

	return value;
}

void wallhitFree(struct wallhit *wallhit)
{
	struct wallhit *iter;
	s32 i;

	wallhit->timermax = 0;
	wallhit->timercur = 0;
	wallhit->inuse = false;

	// Update the global list
	if (wallhit == g_ActiveWallhits) {
		g_ActiveWallhits = wallhit->globalnext;
		wallhit->globalnext = NULL;
	} else {
		iter = g_ActiveWallhits;

		while (wallhit != iter->globalnext) {
			iter = iter->globalnext;
		}

		iter->globalnext = wallhit->globalnext;
	}

	wallhit->globalnext = g_FreeWallhits;
	g_FreeWallhits = wallhit;

	// Update the room/prop's wallhit list
	if (wallhit->objprop == NULL) {
		if (wallhit->xlu) {
			if (wallhit == g_Rooms[wallhit->roomnum].xluwallhits) {
				g_Rooms[wallhit->roomnum].xluwallhits = wallhit->localnext;
			} else {
				iter = g_Rooms[wallhit->roomnum].xluwallhits;

				while (wallhit != iter->localnext) {
					iter = iter->localnext;
				}

				iter->localnext = wallhit->localnext;
			}

			wallhit->localnext = NULL;
		} else {
			if (wallhit == g_Rooms[wallhit->roomnum].opawallhits) {
				g_Rooms[wallhit->roomnum].opawallhits = wallhit->localnext;
			} else {
				iter = g_Rooms[wallhit->roomnum].opawallhits;

				while (wallhit != iter->localnext) {
					iter = iter->localnext;
				}

				iter->localnext = wallhit->localnext;
			}

			wallhit->localnext = NULL;
		}
	} else {
		struct prop *prop = wallhit->objprop;

		if (wallhit->xlu) {
			if (wallhit == prop->xluwallhits) {
				prop->xluwallhits = wallhit->localnext;
			} else {
				iter = prop->xluwallhits;

				while (wallhit != iter->localnext) {
					iter = iter->localnext;
				}

				iter->localnext = wallhit->localnext;
			}

			wallhit->localnext = NULL;
		} else {
			if (wallhit == prop->opawallhits) {
				prop->opawallhits = wallhit->localnext;
			} else {
				iter = prop->opawallhits;

				while (wallhit != iter->localnext) {
					iter = iter->localnext;
				}

				iter->localnext = wallhit->localnext;
			}

			wallhit->localnext = NULL;
		}
	}

	wallhit->objprop = NULL;

	g_WallhitsNumUsed--;
	g_WallhitsNumFree++;

	for (i = 0; i < 4; i++) {
		wallhit->basecolours[i].a = 0;
		wallhit->finalcolours[i].a = 0;
	}
}

void wallhitsFreeByProp(struct prop *prop, s8 layer)
{
	struct prop *copy = prop;

	if (layer) {
		while (copy->xluwallhits) {
			wallhitFade(copy->xluwallhits, 1);
			wallhitFree(copy->xluwallhits);
		}
	} else {
		while (copy->opawallhits) {
			wallhitFade(copy->opawallhits, 1);
			wallhitFree(copy->opawallhits);
		}
	}
}

bool chrIsUsingPaintball(struct chrdata *chr)
{
	s32 prevplayernum = g_Vars.currentplayernum;
	bool paintball;

	if (chr && chr->prop && chr->prop->type == PROPTYPE_PLAYER) {
		setCurrentPlayerNum(playermgrGetPlayerNumByProp(chr->prop));
	} else {
		setCurrentPlayerNum(random() % PLAYERCOUNT());
	}

	paintball = optionsGetPaintball(g_Vars.currentplayerstats->mpindex);

	setCurrentPlayerNum(prevplayernum);

	return paintball;
}

void wallhitChooseBloodColour(struct prop *prop)
{
	if (prop && prop->chr && (prop->type == PROPTYPE_CHR || prop->type == PROPTYPE_PLAYER)) {
		struct chrdata *chr = prop->chr;
		chrGetBloodColour(chr->bodynum, g_WallhitBloodColour, NULL);
	} else {
		g_WallhitBloodColour[0] = 0x40;
		g_WallhitBloodColour[1] = 0x0a;
		g_WallhitBloodColour[2] = 0x0a;
	}
}

void wallhitFade(struct wallhit *wallhit, u32 arg1)
{
	if (!wallhit->fading) {
		if (wallhit->objprop) {
			g_WallhitCountsPerRoom[0]--;
		} else {
			g_WallhitCountsPerRoom[wallhit->roomnum]--;
		}

		if (wallhit->timermax == 0) {
			wallhit->timermax = arg1;
			wallhit->timercur = arg1;
		}

		wallhit->fading = true;

		var8009cc48--;
		g_WallhitsNumUsed++;

		if (g_WallhitTexes[wallhit->texturenum].type == WALLHITTYPE_BLOOD) {
			var8009cc54--;
		} else {
			var8009cc58--;
		}

		wallhit->expanding = false;
	}
}

/**
 * Remove a single wallhit from the given room.
 *
 * Room may be -1 to remove a wallhit from any room, or 0 to remove a prop
 * wallhit, or any number > 0 to remove a wallhit from that room.
 *
 * Wallhits are removed in such a way to try to meet the target blood to
 * non-blood ratio. If a blood wallhit will be removed, a blood drop will
 * be favoured over a blood puddle. The actual wallhit to be removed will
 * be the oldest one that meets that criteria.
 */
bool wallhitReapOneInRoom(s32 room)
{
	if (room == -1 || g_WallhitCountsPerRoom[room]) {
		f32 ratio = 0.0f;
		u32 blooddropframe = U32_MAX;
		u32 bloodpuddleframe = U32_MAX;
		u32 otherframe = U32_MAX;
		s32 blooddropindex = -1;
		s32 bloodpuddleindex = -1;
		s32 otherindex = -1;
		s32 numblood;
		s32 numother;
		s32 numtotal;
		s32 i;

		for (i = 0, numblood = 0, numother = 0; i < g_WallhitsMax; i++) {
			if (g_Wallhits[i].inuse
					&& !g_Wallhits[i].fading
					&& (room == -1
						|| (room == 0 && g_Wallhits[i].objprop != NULL)
						|| (room && room == g_Wallhits[i].roomnum))) {
				if (g_WallhitTexes[g_Wallhits[i].texturenum].type == WALLHITTYPE_BLOOD) {
					numblood++;

					if (IS_BLOOD_DROP(g_Wallhits[i].texturenum)) {
						if (g_Wallhits[i].createdframe < blooddropframe) {
							blooddropframe = g_Wallhits[i].createdframe;
							blooddropindex = i;
						}
					} else {
						if (g_Wallhits[i].createdframe < bloodpuddleframe) {
							bloodpuddleframe = g_Wallhits[i].createdframe;
							bloodpuddleindex = i;
						}
					}
				} else {
					numother++;

					if (g_Wallhits[i].createdframe < otherframe) {
						otherframe = g_Wallhits[i].createdframe;
						otherindex = i;
					}
				}
			}
		}

		numtotal = numblood + numother;

		if (numtotal > 0) {
			ratio = (f32) numblood / (f32) numtotal;
		}

		if (ratio > g_WallhitTargetBloodRatio && (blooddropindex != -1 || bloodpuddleindex != -1)) {
			if (blooddropindex != -1) {
				wallhitFade(&g_Wallhits[blooddropindex], TICKS(30));
				return true;
			} else {
				wallhitFade(&g_Wallhits[bloodpuddleindex], TICKS(30));
				return true;
			}
		} else {
			if (otherindex != -1) {
				wallhitFade(&g_Wallhits[otherindex], TICKS(30));
				return true;
			}
		}
	}

	return false;
}

/**
 * Remove a single wallhit.
 *
 * The wallhit will be removed from a room that's offscreen and not in standby
 * if possible, otherwise a room that's in standby. If wallhits only exist in
 * onscreen rooms then all rooms are considered, and prop hits too.
 *
 * The chosen room will be the one with the most wallhits within one of those
 * three categories.
 */
void wallhitReapOne(void)
{
	s32 room;
	u32 i;
	bool done = false;

	for (i = 0; !done && i < 3; i++) {
		s32 bestroom = -1;
		s32 bestvalue = -1;

		for (room = 0; room < g_Vars.roomcount; room++) {
			s32 onscreen = room == 0 ? 1 : (g_Rooms[room].flags & ROOMFLAG_ONSCREEN);
			s32 standby = room == 0 ? 1 : (g_Rooms[room].flags & ROOMFLAG_STANDBY);
			bool consider;

			if (i == 0) {
				consider = !onscreen && !standby;
			} else if (i == 1) {
				consider = !onscreen;
			} else {
				consider = true;
			}

			if (consider) {
				if (g_WallhitCountsPerRoom[room] > bestvalue) {
					bestvalue = g_WallhitCountsPerRoom[room];
					bestroom = room;
				}
			}
		}

		if (1);
		if (1);

		if (bestroom != -1) {
			s32 min = bestroom == 0 ? g_MinPropWallhits : g_MinBgWallhitsPerRoom;

			if (g_WallhitCountsPerRoom[bestroom] > min) {
				if (wallhitReapOneInRoom(bestroom)) {
					done = true;
				}
			}
		}
	}

	if (!done) {
		wallhitReapOneInRoom(-1);
	}

	if (1);
}

#if MATCHING
GLOBAL_ASM(
glabel wallhitsTick
.late_rodata
glabel var7f1b5d08
.word 0x3f19999a
glabel var7f1b5d0c
.word 0x3fc90fdb
glabel var7f1b5d10
.word 0x3e4ccccd
glabel var7f1b5d14
.word 0x3f19999a
glabel var7f1b5d18
.word 0x3e4ccccd
.text
/*  f13eb44:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f13eb48:	afb00048 */ 	sw	$s0,0x48($sp)
/*  f13eb4c:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f13eb50:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f13eb54:	8e0e0034 */ 	lw	$t6,0x34($s0)
/*  f13eb58:	3c014000 */ 	lui	$at,0x4000
/*  f13eb5c:	44814000 */ 	mtc1	$at,$f8
/*  f13eb60:	448e2000 */ 	mtc1	$t6,$f4
/*  f13eb64:	3c013e80 */ 	lui	$at,0x3e80
/*  f13eb68:	f7bc0038 */ 	sdc1	$f28,0x38($sp)
/*  f13eb6c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f13eb70:	44812000 */ 	mtc1	$at,$f4
/*  f13eb74:	afbf006c */ 	sw	$ra,0x6c($sp)
/*  f13eb78:	afbe0068 */ 	sw	$s8,0x68($sp)
/*  f13eb7c:	afb70064 */ 	sw	$s7,0x64($sp)
/*  f13eb80:	afb60060 */ 	sw	$s6,0x60($sp)
/*  f13eb84:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f13eb88:	afb5005c */ 	sw	$s5,0x5c($sp)
/*  f13eb8c:	afb40058 */ 	sw	$s4,0x58($sp)
/*  f13eb90:	afb30054 */ 	sw	$s3,0x54($sp)
/*  f13eb94:	46045702 */ 	mul.s	$f28,$f10,$f4
/*  f13eb98:	afb20050 */ 	sw	$s2,0x50($sp)
/*  f13eb9c:	afb1004c */ 	sw	$s1,0x4c($sp)
/*  f13eba0:	f7be0040 */ 	sdc1	$f30,0x40($sp)
/*  f13eba4:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f13eba8:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f13ebac:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f13ebb0:	0fc2c536 */ 	jal	currentPlayerGetGunZoomFov
/*  f13ebb4:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f13ebb8:	3c047f1b */ 	lui	$a0,%hi(var7f1b5a54)
/*  f13ebbc:	3c058008 */ 	lui	$a1,%hi(var8007f750)
/*  f13ebc0:	46000506 */ 	mov.s	$f20,$f0
/*  f13ebc4:	24a5f750 */ 	addiu	$a1,$a1,%lo(var8007f750)
/*  f13ebc8:	0c0036cc */ 	jal	mainOverrideVariable
/*  f13ebcc:	24845a54 */ 	addiu	$a0,$a0,%lo(var7f1b5a54)
/*  f13ebd0:	44803000 */ 	mtc1	$zero,$f6
/*  f13ebd4:	3c018008 */ 	lui	$at,%hi(var8007f740)
/*  f13ebd8:	ac20f740 */ 	sw	$zero,%lo(var8007f740)($at)
/*  f13ebdc:	4606a032 */ 	c.eq.s	$f20,$f6
/*  f13ebe0:	3c014270 */ 	lui	$at,0x4270
/*  f13ebe4:	3c038008 */ 	lui	$v1,%hi(var8007f748)
/*  f13ebe8:	3c09800a */ 	lui	$t1,%hi(var8009cc74)
/*  f13ebec:	45030008 */ 	bc1tl	.L0f13ec10
/*  f13ebf0:	3c013f80 */ 	lui	$at,0x3f80
/*  f13ebf4:	44811000 */ 	mtc1	$at,$f2
/*  f13ebf8:	3c013f80 */ 	lui	$at,0x3f80
/*  f13ebfc:	4602a032 */ 	c.eq.s	$f20,$f2
/*  f13ec00:	00000000 */ 	nop
/*  f13ec04:	45020007 */ 	bc1fl	.L0f13ec24
/*  f13ec08:	8e0f0284 */ 	lw	$t7,0x284($s0)
/*  f13ec0c:	3c013f80 */ 	lui	$at,0x3f80
.L0f13ec10:
/*  f13ec10:	44814000 */ 	mtc1	$at,$f8
/*  f13ec14:	2463f748 */ 	addiu	$v1,$v1,%lo(var8007f748)
/*  f13ec18:	1000000d */ 	b	.L0f13ec50
/*  f13ec1c:	e4680000 */ 	swc1	$f8,0x0($v1)
/*  f13ec20:	8e0f0284 */ 	lw	$t7,0x284($s0)
.L0f13ec24:
/*  f13ec24:	44813000 */ 	mtc1	$at,$f6
/*  f13ec28:	46141103 */ 	div.s	$f4,$f2,$f20
/*  f13ec2c:	c5ea1848 */ 	lwc1	$f10,0x1848($t7)
/*  f13ec30:	3c038008 */ 	lui	$v1,%hi(var8007f748)
/*  f13ec34:	2463f748 */ 	addiu	$v1,$v1,%lo(var8007f748)
/*  f13ec38:	460aa003 */ 	div.s	$f0,$f20,$f10
/*  f13ec3c:	46003203 */ 	div.s	$f8,$f6,$f0
/*  f13ec40:	44813000 */ 	mtc1	$at,$f6
/*  f13ec44:	46082281 */ 	sub.s	$f10,$f4,$f8
/*  f13ec48:	46065100 */ 	add.s	$f4,$f10,$f6
/*  f13ec4c:	e4640000 */ 	swc1	$f4,0x0($v1)
.L0f13ec50:
/*  f13ec50:	3c013f80 */ 	lui	$at,0x3f80
/*  f13ec54:	4481d000 */ 	mtc1	$at,$f26
/*  f13ec58:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*  f13ec5c:	3c18800a */ 	lui	$t8,%hi(g_WallhitsNumFree)
/*  f13ec60:	3c19800a */ 	lui	$t9,%hi(g_WallhitsNumUsed)
/*  f13ec64:	4608d283 */ 	div.s	$f10,$f26,$f8
/*  f13ec68:	8f39cc50 */ 	lw	$t9,%lo(g_WallhitsNumUsed)($t9)
/*  f13ec6c:	8f18cc4c */ 	lw	$t8,%lo(g_WallhitsNumFree)($t8)
/*  f13ec70:	3c08800a */ 	lui	$t0,%hi(var8009cc70)
/*  f13ec74:	8d08cc70 */ 	lw	$t0,%lo(var8009cc70)($t0)
/*  f13ec78:	3c018008 */ 	lui	$at,%hi(var8007f74c)
/*  f13ec7c:	03191021 */ 	addu	$v0,$t8,$t9
/*  f13ec80:	e42af74c */ 	swc1	$f10,%lo(var8007f74c)($at)
/*  f13ec84:	0048082a */ 	slt	$at,$v0,$t0
/*  f13ec88:	10200005 */ 	beqz	$at,.L0f13eca0
/*  f13ec8c:	00000000 */ 	nop
/*  f13ec90:	0fc4fa65 */ 	jal	wallhitReapOne
/*  f13ec94:	00000000 */ 	nop
/*  f13ec98:	1000000e */ 	b	.L0f13ecd4
/*  f13ec9c:	00000000 */ 	nop
.L0f13eca0:
/*  f13eca0:	8d29cc74 */ 	lw	$t1,%lo(var8009cc74)($t1)
/*  f13eca4:	0049082a */ 	slt	$at,$v0,$t1
/*  f13eca8:	1020000a */ 	beqz	$at,.L0f13ecd4
/*  f13ecac:	3c028008 */ 	lui	$v0,%hi(g_WallhitTexes+0xd8)
/*  f13ecb0:	8c42f834 */ 	lw	$v0,%lo(g_WallhitTexes+0xd8)($v0)
/*  f13ecb4:	3c018008 */ 	lui	$at,%hi(g_WallhitTexes+0xd8)
/*  f13ecb8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f13ecbc:	ac22f834 */ 	sw	$v0,%lo(g_WallhitTexes+0xd8)($at)
/*  f13ecc0:	24010008 */ 	addiu	$at,$zero,0x8
/*  f13ecc4:	14410003 */ 	bne	$v0,$at,.L0f13ecd4
/*  f13ecc8:	3c018008 */ 	lui	$at,%hi(g_WallhitTexes+0xd8)
/*  f13eccc:	0fc4fa65 */ 	jal	wallhitReapOne
/*  f13ecd0:	ac20f834 */ 	sw	$zero,%lo(g_WallhitTexes+0xd8)($at)
.L0f13ecd4:
/*  f13ecd4:	3c02800a */ 	lui	$v0,%hi(g_WallhitsMax)
/*  f13ecd8:	8c42cc44 */ 	lw	$v0,%lo(g_WallhitsMax)($v0)
/*  f13ecdc:	3c11800a */ 	lui	$s1,%hi(g_Wallhits)
/*  f13ece0:	8e3141b0 */ 	lw	$s1,%lo(g_Wallhits)($s1)
/*  f13ece4:	184001b1 */ 	blez	$v0,.L0f13f3ac
/*  f13ece8:	0000b825 */ 	or	$s7,$zero,$zero
/*  f13ecec:	3c013f00 */ 	lui	$at,0x3f00
/*  f13ecf0:	3c1e8008 */ 	lui	$s8,%hi(var800845dc)
/*  f13ecf4:	27b300f8 */ 	addiu	$s3,$sp,0xf8
/*  f13ecf8:	4481a000 */ 	mtc1	$at,$f20
/*  f13ecfc:	0260b025 */ 	or	$s6,$s3,$zero
/*  f13ed00:	27de45dc */ 	addiu	$s8,$s8,%lo(var800845dc)
/*  f13ed04:	2415000c */ 	addiu	$s5,$zero,0xc
/*  f13ed08:	27b400c8 */ 	addiu	$s4,$sp,0xc8
/*  f13ed0c:	24120004 */ 	addiu	$s2,$zero,0x4
.L0f13ed10:
/*  f13ed10:	9224006f */ 	lbu	$a0,0x6f($s1)
/*  f13ed14:	4600e006 */ 	mov.s	$f0,$f28
/*  f13ed18:	000459c2 */ 	srl	$t3,$a0,0x7
/*  f13ed1c:	516001a0 */ 	beqzl	$t3,.L0f13f3a0
/*  f13ed20:	26f70001 */ 	addiu	$s7,$s7,0x1
/*  f13ed24:	8e220070 */ 	lw	$v0,0x70($s1)
/*  f13ed28:	24010008 */ 	addiu	$at,$zero,0x8
/*  f13ed2c:	304c000f */ 	andi	$t4,$v0,0xf
/*  f13ed30:	11810015 */ 	beq	$t4,$at,.L0f13ed88
/*  f13ed34:	01801025 */ 	or	$v0,$t4,$zero
/*  f13ed38:	44823000 */ 	mtc1	$v0,$f6
/*  f13ed3c:	3c014f80 */ 	lui	$at,0x4f80
/*  f13ed40:	05810004 */ 	bgez	$t4,.L0f13ed54
/*  f13ed44:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f13ed48:	44814000 */ 	mtc1	$at,$f8
/*  f13ed4c:	00000000 */ 	nop
/*  f13ed50:	46082100 */ 	add.s	$f4,$f4,$f8
.L0f13ed54:
/*  f13ed54:	3c014100 */ 	lui	$at,0x4100
/*  f13ed58:	44815000 */ 	mtc1	$at,$f10
/*  f13ed5c:	3c013e00 */ 	lui	$at,0x3e00
/*  f13ed60:	44814000 */ 	mtc1	$at,$f8
/*  f13ed64:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f13ed68:	3c017f1b */ 	lui	$at,%hi(var7f1b5d08)
/*  f13ed6c:	c42a5d08 */ 	lwc1	$f10,%lo(var7f1b5d08)($at)
/*  f13ed70:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f13ed74:	00000000 */ 	nop
/*  f13ed78:	46045182 */ 	mul.s	$f6,$f10,$f4
/*  f13ed7c:	00000000 */ 	nop
/*  f13ed80:	4606e002 */ 	mul.s	$f0,$f28,$f6
/*  f13ed84:	00000000 */ 	nop
.L0f13ed88:
/*  f13ed88:	9222006d */ 	lbu	$v0,0x6d($s1)
/*  f13ed8c:	50400180 */ 	beqzl	$v0,.L0f13f390
/*  f13ed90:	34890004 */ 	ori	$t1,$a0,0x4
/*  f13ed94:	8e2d006c */ 	lw	$t5,0x6c($s1)
/*  f13ed98:	000d7ec0 */ 	sll	$t7,$t5,0x1b
/*  f13ed9c:	05e3002e */ 	bgezl	$t7,.L0f13ee58
/*  f13eda0:	46140100 */ 	add.s	$f4,$f0,$f20
/*  f13eda4:	9223006e */ 	lbu	$v1,0x6e($s1)
/*  f13eda8:	34990080 */ 	ori	$t9,$a0,0x80
/*  f13edac:	46140200 */ 	add.s	$f8,$f0,$f20
/*  f13edb0:	0043082a */ 	slt	$at,$v0,$v1
/*  f13edb4:	10200005 */ 	beqz	$at,.L0f13edcc
/*  f13edb8:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f13edbc:	a220006d */ 	sb	$zero,0x6d($s1)
/*  f13edc0:	a220006e */ 	sb	$zero,0x6e($s1)
/*  f13edc4:	a239006f */ 	sb	$t9,0x6f($s1)
/*  f13edc8:	300300ff */ 	andi	$v1,$zero,0xff
.L0f13edcc:
/*  f13edcc:	4448f800 */ 	cfc1	$t0,$31
/*  f13edd0:	44c9f800 */ 	ctc1	$t1,$31
/*  f13edd4:	3c014f00 */ 	lui	$at,0x4f00
/*  f13edd8:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f13eddc:	4449f800 */ 	cfc1	$t1,$31
/*  f13ede0:	00000000 */ 	nop
/*  f13ede4:	31290078 */ 	andi	$t1,$t1,0x78
/*  f13ede8:	51200013 */ 	beqzl	$t1,.L0f13ee38
/*  f13edec:	44095000 */ 	mfc1	$t1,$f10
/*  f13edf0:	44815000 */ 	mtc1	$at,$f10
/*  f13edf4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f13edf8:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f13edfc:	44c9f800 */ 	ctc1	$t1,$31
/*  f13ee00:	00000000 */ 	nop
/*  f13ee04:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f13ee08:	4449f800 */ 	cfc1	$t1,$31
/*  f13ee0c:	00000000 */ 	nop
/*  f13ee10:	31290078 */ 	andi	$t1,$t1,0x78
/*  f13ee14:	15200005 */ 	bnez	$t1,.L0f13ee2c
/*  f13ee18:	00000000 */ 	nop
/*  f13ee1c:	44095000 */ 	mfc1	$t1,$f10
/*  f13ee20:	3c018000 */ 	lui	$at,0x8000
/*  f13ee24:	10000007 */ 	b	.L0f13ee44
/*  f13ee28:	01214825 */ 	or	$t1,$t1,$at
.L0f13ee2c:
/*  f13ee2c:	10000005 */ 	b	.L0f13ee44
/*  f13ee30:	2409ffff */ 	addiu	$t1,$zero,-1
/*  f13ee34:	44095000 */ 	mfc1	$t1,$f10
.L0f13ee38:
/*  f13ee38:	00000000 */ 	nop
/*  f13ee3c:	0520fffb */ 	bltz	$t1,.L0f13ee2c
/*  f13ee40:	00000000 */ 	nop
.L0f13ee44:
/*  f13ee44:	44c8f800 */ 	ctc1	$t0,$31
/*  f13ee48:	00695021 */ 	addu	$t2,$v1,$t1
/*  f13ee4c:	1000002b */ 	b	.L0f13eefc
/*  f13ee50:	a22a006e */ 	sb	$t2,0x6e($s1)
/*  f13ee54:	46140100 */ 	add.s	$f4,$f0,$f20
.L0f13ee58:
/*  f13ee58:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f13ee5c:	3c014f00 */ 	lui	$at,0x4f00
/*  f13ee60:	444bf800 */ 	cfc1	$t3,$31
/*  f13ee64:	44c2f800 */ 	ctc1	$v0,$31
/*  f13ee68:	00000000 */ 	nop
/*  f13ee6c:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f13ee70:	4442f800 */ 	cfc1	$v0,$31
/*  f13ee74:	00000000 */ 	nop
/*  f13ee78:	30420078 */ 	andi	$v0,$v0,0x78
/*  f13ee7c:	50400013 */ 	beqzl	$v0,.L0f13eecc
/*  f13ee80:	44023000 */ 	mfc1	$v0,$f6
/*  f13ee84:	44813000 */ 	mtc1	$at,$f6
/*  f13ee88:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f13ee8c:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f13ee90:	44c2f800 */ 	ctc1	$v0,$31
/*  f13ee94:	00000000 */ 	nop
/*  f13ee98:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f13ee9c:	4442f800 */ 	cfc1	$v0,$31
/*  f13eea0:	00000000 */ 	nop
/*  f13eea4:	30420078 */ 	andi	$v0,$v0,0x78
/*  f13eea8:	14400005 */ 	bnez	$v0,.L0f13eec0
/*  f13eeac:	00000000 */ 	nop
/*  f13eeb0:	44023000 */ 	mfc1	$v0,$f6
/*  f13eeb4:	3c018000 */ 	lui	$at,0x8000
/*  f13eeb8:	10000007 */ 	b	.L0f13eed8
/*  f13eebc:	00411025 */ 	or	$v0,$v0,$at
.L0f13eec0:
/*  f13eec0:	10000005 */ 	b	.L0f13eed8
/*  f13eec4:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f13eec8:	44023000 */ 	mfc1	$v0,$f6
.L0f13eecc:
/*  f13eecc:	00000000 */ 	nop
/*  f13eed0:	0440fffb */ 	bltz	$v0,.L0f13eec0
/*  f13eed4:	00000000 */ 	nop
.L0f13eed8:
/*  f13eed8:	9223006e */ 	lbu	$v1,0x6e($s1)
/*  f13eedc:	44cbf800 */ 	ctc1	$t3,$31
/*  f13eee0:	0043082b */ 	sltu	$at,$v0,$v1
/*  f13eee4:	10200003 */ 	beqz	$at,.L0f13eef4
/*  f13eee8:	00626023 */ 	subu	$t4,$v1,$v0
/*  f13eeec:	10000003 */ 	b	.L0f13eefc
/*  f13eef0:	a22c006e */ 	sb	$t4,0x6e($s1)
.L0f13eef4:
/*  f13eef4:	0fc4f86c */ 	jal	wallhitFree
/*  f13eef8:	02202025 */ 	or	$a0,$s1,$zero
.L0f13eefc:
/*  f13eefc:	9222006d */ 	lbu	$v0,0x6d($s1)
/*  f13ef00:	50400114 */ 	beqzl	$v0,.L0f13f354
/*  f13ef04:	8238006f */ 	lb	$t8,0x6f($s1)
/*  f13ef08:	922d006e */ 	lbu	$t5,0x6e($s1)
/*  f13ef0c:	44823000 */ 	mtc1	$v0,$f6
/*  f13ef10:	3c014f80 */ 	lui	$at,0x4f80
/*  f13ef14:	448d4000 */ 	mtc1	$t5,$f8
/*  f13ef18:	05a10004 */ 	bgez	$t5,.L0f13ef2c
/*  f13ef1c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f13ef20:	44812000 */ 	mtc1	$at,$f4
/*  f13ef24:	00000000 */ 	nop
/*  f13ef28:	46045280 */ 	add.s	$f10,$f10,$f4
.L0f13ef2c:
/*  f13ef2c:	04410005 */ 	bgez	$v0,.L0f13ef44
/*  f13ef30:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f13ef34:	3c014f80 */ 	lui	$at,0x4f80
/*  f13ef38:	44812000 */ 	mtc1	$at,$f4
/*  f13ef3c:	00000000 */ 	nop
/*  f13ef40:	46044200 */ 	add.s	$f8,$f8,$f4
.L0f13ef44:
/*  f13ef44:	46085603 */ 	div.s	$f24,$f10,$f8
/*  f13ef48:	3c017f1b */ 	lui	$at,%hi(var7f1b5d0c)
/*  f13ef4c:	4618d03c */ 	c.lt.s	$f26,$f24
/*  f13ef50:	00000000 */ 	nop
/*  f13ef54:	45020003 */ 	bc1fl	.L0f13ef64
/*  f13ef58:	8e2e006c */ 	lw	$t6,0x6c($s1)
/*  f13ef5c:	4600d606 */ 	mov.s	$f24,$f26
/*  f13ef60:	8e2e006c */ 	lw	$t6,0x6c($s1)
.L0f13ef64:
/*  f13ef64:	4600c586 */ 	mov.s	$f22,$f24
/*  f13ef68:	000ec6c0 */ 	sll	$t8,$t6,0x1b
/*  f13ef6c:	070300bf */ 	bgezl	$t8,.L0f13f26c
/*  f13ef70:	00001825 */ 	or	$v1,$zero,$zero
/*  f13ef74:	c4265d0c */ 	lwc1	$f6,%lo(var7f1b5d0c)($at)
/*  f13ef78:	3c017f1b */ 	lui	$at,%hi(var7f1b5d10)
/*  f13ef7c:	c4245d10 */ 	lwc1	$f4,%lo(var7f1b5d10)($at)
/*  f13ef80:	46183502 */ 	mul.s	$f20,$f6,$f24
/*  f13ef84:	e7bc012c */ 	swc1	$f28,0x12c($sp)
/*  f13ef88:	00008025 */ 	or	$s0,$zero,$zero
/*  f13ef8c:	4604d701 */ 	sub.s	$f28,$f26,$f4
/*  f13ef90:	0c0068f7 */ 	jal	sinf
/*  f13ef94:	4600a306 */ 	mov.s	$f12,$f20
/*  f13ef98:	461c0782 */ 	mul.s	$f30,$f0,$f28
/*  f13ef9c:	4614d481 */ 	sub.s	$f18,$f26,$f20
/*  f13efa0:	3c017f1b */ 	lui	$at,%hi(var7f1b5d14)
/*  f13efa4:	c4305d14 */ 	lwc1	$f16,%lo(var7f1b5d14)($at)
/*  f13efa8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f13efac:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f13efb0:	46109580 */ 	add.s	$f22,$f18,$f16
/*  f13efb4:	ae220064 */ 	sw	$v0,0x64($s1)
/*  f13efb8:	c7d00008 */ 	lwc1	$f16,0x8($s8)
/*  f13efbc:	c7ce0004 */ 	lwc1	$f14,0x4($s8)
/*  f13efc0:	c7cc0000 */ 	lwc1	$f12,0x0($s8)
/*  f13efc4:	27a400c8 */ 	addiu	$a0,$sp,0xc8
/*  f13efc8:	02201825 */ 	or	$v1,$s1,$zero
/*  f13efcc:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f13efd0:	0093082b */ 	sltu	$at,$a0,$s3
/*  f13efd4:	10200013 */ 	beqz	$at,.L0f13f024
/*  f13efd8:	84790000 */ 	lh	$t9,0x0($v1)
.L0f13efdc:
/*  f13efdc:	4499e000 */ 	mtc1	$t9,$f28
/*  f13efe0:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f13efe4:	0093082b */ 	sltu	$at,$a0,$s3
/*  f13efe8:	4680e720 */ 	cvt.s.w	$f28,$f28
/*  f13efec:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f13eff0:	e49cffe8 */ 	swc1	$f28,-0x18($a0)
/*  f13eff4:	8468fff6 */ 	lh	$t0,-0xa($v1)
/*  f13eff8:	4488e000 */ 	mtc1	$t0,$f28
/*  f13effc:	00000000 */ 	nop
/*  f13f000:	4680e720 */ 	cvt.s.w	$f28,$f28
/*  f13f004:	e49cffec */ 	swc1	$f28,-0x14($a0)
/*  f13f008:	8469fff8 */ 	lh	$t1,-0x8($v1)
/*  f13f00c:	4489e000 */ 	mtc1	$t1,$f28
/*  f13f010:	00000000 */ 	nop
/*  f13f014:	4680e720 */ 	cvt.s.w	$f28,$f28
/*  f13f018:	e49cfff0 */ 	swc1	$f28,-0x10($a0)
/*  f13f01c:	1420ffef */ 	bnez	$at,.L0f13efdc
/*  f13f020:	84790000 */ 	lh	$t9,0x0($v1)
.L0f13f024:
/*  f13f024:	4499e000 */ 	mtc1	$t9,$f28
/*  f13f028:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f13f02c:	4680e720 */ 	cvt.s.w	$f28,$f28
/*  f13f030:	e49cfff4 */ 	swc1	$f28,-0xc($a0)
/*  f13f034:	8468fff6 */ 	lh	$t0,-0xa($v1)
/*  f13f038:	4488e000 */ 	mtc1	$t0,$f28
/*  f13f03c:	00000000 */ 	nop
/*  f13f040:	4680e720 */ 	cvt.s.w	$f28,$f28
/*  f13f044:	e49cfff8 */ 	swc1	$f28,-0x8($a0)
/*  f13f048:	8469fff8 */ 	lh	$t1,-0x8($v1)
/*  f13f04c:	4489e000 */ 	mtc1	$t1,$f28
/*  f13f050:	00000000 */ 	nop
/*  f13f054:	4680e720 */ 	cvt.s.w	$f28,$f28
/*  f13f058:	e49cfffc */ 	swc1	$f28,-0x4($a0)
/*  f13f05c:	00002825 */ 	or	$a1,$zero,$zero
/*  f13f060:	27a400c8 */ 	addiu	$a0,$sp,0xc8
.L0f13f064:
/*  f13f064:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f13f068:	c4800004 */ 	lwc1	$f0,0x4($a0)
/*  f13f06c:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f13f070:	460c5300 */ 	add.s	$f12,$f10,$f12
/*  f13f074:	460e0380 */ 	add.s	$f14,$f0,$f14
/*  f13f078:	1200000a */ 	beqz	$s0,.L0f13f0a4
/*  f13f07c:	46104400 */ 	add.s	$f16,$f8,$f16
/*  f13f080:	02150019 */ 	multu	$s0,$s5
/*  f13f084:	00005012 */ 	mflo	$t2
/*  f13f088:	028a5821 */ 	addu	$t3,$s4,$t2
/*  f13f08c:	c5660004 */ 	lwc1	$f6,0x4($t3)
/*  f13f090:	4606003c */ 	c.lt.s	$f0,$f6
/*  f13f094:	00000000 */ 	nop
/*  f13f098:	45020003 */ 	bc1fl	.L0f13f0a8
/*  f13f09c:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f13f0a0:	00a08025 */ 	or	$s0,$a1,$zero
.L0f13f0a4:
/*  f13f0a4:	24a50001 */ 	addiu	$a1,$a1,0x1
.L0f13f0a8:
/*  f13f0a8:	28a10004 */ 	slti	$at,$a1,0x4
/*  f13f0ac:	1420ffed */ 	bnez	$at,.L0f13f064
/*  f13f0b0:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f13f0b4:	3c013e80 */ 	lui	$at,0x3e80
/*  f13f0b8:	44810000 */ 	mtc1	$at,$f0
/*  f13f0bc:	3c017f1b */ 	lui	$at,%hi(var7f1b5d18)
/*  f13f0c0:	c4245d18 */ 	lwc1	$f4,%lo(var7f1b5d18)($at)
/*  f13f0c4:	460c0302 */ 	mul.s	$f12,$f0,$f12
/*  f13f0c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f13f0cc:	27a400c8 */ 	addiu	$a0,$sp,0xc8
/*  f13f0d0:	460e0382 */ 	mul.s	$f14,$f0,$f14
/*  f13f0d4:	02201825 */ 	or	$v1,$s1,$zero
/*  f13f0d8:	461e2080 */ 	add.s	$f2,$f4,$f30
/*  f13f0dc:	46100402 */ 	mul.s	$f16,$f0,$f16
/*  f13f0e0:	00000000 */ 	nop
/*  f13f0e4:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f13f0e8:	c4940004 */ 	lwc1	$f20,0x4($a0)
/*  f13f0ec:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f13f0f0:	460c5281 */ 	sub.s	$f10,$f10,$f12
/*  f13f0f4:	460ea701 */ 	sub.s	$f28,$f20,$f14
/*  f13f0f8:	460a1782 */ 	mul.s	$f30,$f2,$f10
/*  f13f0fc:	5096002e */ 	beql	$a0,$s6,.L0f13f1b8
/*  f13f100:	c48afffc */ 	lwc1	$f10,-0x4($a0)
.L0f13f104:
/*  f13f104:	461c1502 */ 	mul.s	$f20,$f2,$f28
/*  f13f108:	460cf480 */ 	add.s	$f18,$f30,$f12
/*  f13f10c:	c48afffc */ 	lwc1	$f10,-0x4($a0)
/*  f13f110:	8e2e0064 */ 	lw	$t6,0x64($s1)
/*  f13f114:	2484000c */ 	addiu	$a0,$a0,0xc
/*  f13f118:	46105281 */ 	sub.s	$f10,$f10,$f16
/*  f13f11c:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f13f120:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f13f124:	4600948d */ 	trunc.w.s	$f18,$f18
/*  f13f128:	460a1282 */ 	mul.s	$f10,$f2,$f10
/*  f13f12c:	460ea500 */ 	add.s	$f20,$f20,$f14
/*  f13f130:	440d9000 */ 	mfc1	$t5,$f18
/*  f13f134:	4600a50d */ 	trunc.w.s	$f20,$f20
/*  f13f138:	a5ed0000 */ 	sh	$t5,0x0($t7)
/*  f13f13c:	8e280064 */ 	lw	$t0,0x64($s1)
/*  f13f140:	46105280 */ 	add.s	$f10,$f10,$f16
/*  f13f144:	4419a000 */ 	mfc1	$t9,$f20
/*  f13f148:	01024821 */ 	addu	$t1,$t0,$v0
/*  f13f14c:	4600528d */ 	trunc.w.s	$f10,$f10
/*  f13f150:	a5390002 */ 	sh	$t9,0x2($t1)
/*  f13f154:	8e2c0064 */ 	lw	$t4,0x64($s1)
/*  f13f158:	440b5000 */ 	mfc1	$t3,$f10
/*  f13f15c:	01827021 */ 	addu	$t6,$t4,$v0
/*  f13f160:	a5cb0004 */ 	sh	$t3,0x4($t6)
/*  f13f164:	8e2f0064 */ 	lw	$t7,0x64($s1)
/*  f13f168:	846dfffc */ 	lh	$t5,-0x4($v1)
/*  f13f16c:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f13f170:	a70d0008 */ 	sh	$t5,0x8($t8)
/*  f13f174:	8e390064 */ 	lw	$t9,0x64($s1)
/*  f13f178:	8468fffe */ 	lh	$t0,-0x2($v1)
/*  f13f17c:	03224821 */ 	addu	$t1,$t9,$v0
/*  f13f180:	a528000a */ 	sh	$t0,0xa($t1)
/*  f13f184:	8e2c0064 */ 	lw	$t4,0x64($s1)
/*  f13f188:	906afffb */ 	lbu	$t2,-0x5($v1)
/*  f13f18c:	01825821 */ 	addu	$t3,$t4,$v0
/*  f13f190:	a16a0007 */ 	sb	$t2,0x7($t3)
/*  f13f194:	c48afff4 */ 	lwc1	$f10,-0xc($a0)
/*  f13f198:	c494fff8 */ 	lwc1	$f20,-0x8($a0)
/*  f13f19c:	2442000c */ 	addiu	$v0,$v0,12
/*  f13f1a0:	460c5281 */ 	sub.s	$f10,$f10,$f12
/*  f13f1a4:	460ea701 */ 	sub.s	$f28,$f20,$f14
/*  f13f1a8:	460a1782 */ 	mul.s	$f30,$f2,$f10
/*  f13f1ac:	1496ffd5 */ 	bne	$a0,$s6,.L0f13f104
/*  f13f1b0:	00000000 */ 	nop
/*  f13f1b4:	c48afffc */ 	lwc1	$f10,-0x4($a0)
.L0f13f1b8:
/*  f13f1b8:	461c1502 */ 	mul.s	$f20,$f2,$f28
/*  f13f1bc:	460cf480 */ 	add.s	$f18,$f30,$f12
/*  f13f1c0:	8e2e0064 */ 	lw	$t6,0x64($s1)
/*  f13f1c4:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f13f1c8:	46105281 */ 	sub.s	$f10,$f10,$f16
/*  f13f1cc:	01c27821 */ 	addu	$t7,$t6,$v0
/*  f13f1d0:	4600948d */ 	trunc.w.s	$f18,$f18
/*  f13f1d4:	460a1282 */ 	mul.s	$f10,$f2,$f10
/*  f13f1d8:	460ea500 */ 	add.s	$f20,$f20,$f14
/*  f13f1dc:	440d9000 */ 	mfc1	$t5,$f18
/*  f13f1e0:	4600a50d */ 	trunc.w.s	$f20,$f20
/*  f13f1e4:	a5ed0000 */ 	sh	$t5,0x0($t7)
/*  f13f1e8:	8e280064 */ 	lw	$t0,0x64($s1)
/*  f13f1ec:	46105280 */ 	add.s	$f10,$f10,$f16
/*  f13f1f0:	4419a000 */ 	mfc1	$t9,$f20
/*  f13f1f4:	01024821 */ 	addu	$t1,$t0,$v0
/*  f13f1f8:	4600528d */ 	trunc.w.s	$f10,$f10
/*  f13f1fc:	a5390002 */ 	sh	$t9,0x2($t1)
/*  f13f200:	8e2c0064 */ 	lw	$t4,0x64($s1)
/*  f13f204:	440b5000 */ 	mfc1	$t3,$f10
/*  f13f208:	01827021 */ 	addu	$t6,$t4,$v0
/*  f13f20c:	a5cb0004 */ 	sh	$t3,0x4($t6)
/*  f13f210:	8e2f0064 */ 	lw	$t7,0x64($s1)
/*  f13f214:	846dfffc */ 	lh	$t5,-0x4($v1)
/*  f13f218:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f13f21c:	a70d0008 */ 	sh	$t5,0x8($t8)
/*  f13f220:	8e390064 */ 	lw	$t9,0x64($s1)
/*  f13f224:	8468fffe */ 	lh	$t0,-0x2($v1)
/*  f13f228:	03224821 */ 	addu	$t1,$t9,$v0
/*  f13f22c:	a528000a */ 	sh	$t0,0xa($t1)
/*  f13f230:	8e2c0064 */ 	lw	$t4,0x64($s1)
/*  f13f234:	906afffb */ 	lbu	$t2,-0x5($v1)
/*  f13f238:	01825821 */ 	addu	$t3,$t4,$v0
/*  f13f23c:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f13f240:	a16a0007 */ 	sb	$t2,0x7($t3)
/*  f13f244:	4618c600 */ 	add.s	$f24,$f24,$f24
/*  f13f248:	3c013f00 */ 	lui	$at,0x3f00
/*  f13f24c:	4481a000 */ 	mtc1	$at,$f20
/*  f13f250:	4618d03c */ 	c.lt.s	$f26,$f24
/*  f13f254:	00000000 */ 	nop
/*  f13f258:	45020003 */ 	bc1fl	.L0f13f268
/*  f13f25c:	c7bc012c */ 	lwc1	$f28,0x12c($sp)
/*  f13f260:	4600d606 */ 	mov.s	$f24,$f26
/*  f13f264:	c7bc012c */ 	lwc1	$f28,0x12c($sp)
.L0f13f268:
/*  f13f268:	00001825 */ 	or	$v1,$zero,$zero
.L0f13f26c:
/*  f13f26c:	02201025 */ 	or	$v0,$s1,$zero
.L0f13f270:
/*  f13f270:	4616d03c */ 	c.lt.s	$f26,$f22
/*  f13f274:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f13f278:	3c014f80 */ 	lui	$at,0x4f80
/*  f13f27c:	45020003 */ 	bc1fl	.L0f13f28c
/*  f13f280:	904e0033 */ 	lbu	$t6,0x33($v0)
/*  f13f284:	4600d586 */ 	mov.s	$f22,$f26
/*  f13f288:	904e0033 */ 	lbu	$t6,0x33($v0)
.L0f13f28c:
/*  f13f28c:	448e5000 */ 	mtc1	$t6,$f10
/*  f13f290:	05c10004 */ 	bgez	$t6,.L0f13f2a4
/*  f13f294:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f13f298:	44813000 */ 	mtc1	$at,$f6
/*  f13f29c:	00000000 */ 	nop
/*  f13f2a0:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f13f2a4:
/*  f13f2a4:	46184102 */ 	mul.s	$f4,$f8,$f24
/*  f13f2a8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f13f2ac:	3c014f00 */ 	lui	$at,0x4f00
/*  f13f2b0:	444ff800 */ 	cfc1	$t7,$31
/*  f13f2b4:	44c4f800 */ 	ctc1	$a0,$31
/*  f13f2b8:	00000000 */ 	nop
/*  f13f2bc:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f13f2c0:	4444f800 */ 	cfc1	$a0,$31
/*  f13f2c4:	00000000 */ 	nop
/*  f13f2c8:	30840078 */ 	andi	$a0,$a0,0x78
/*  f13f2cc:	50800013 */ 	beqzl	$a0,.L0f13f31c
/*  f13f2d0:	44045000 */ 	mfc1	$a0,$f10
/*  f13f2d4:	44815000 */ 	mtc1	$at,$f10
/*  f13f2d8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f13f2dc:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f13f2e0:	44c4f800 */ 	ctc1	$a0,$31
/*  f13f2e4:	00000000 */ 	nop
/*  f13f2e8:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f13f2ec:	4444f800 */ 	cfc1	$a0,$31
/*  f13f2f0:	00000000 */ 	nop
/*  f13f2f4:	30840078 */ 	andi	$a0,$a0,0x78
/*  f13f2f8:	14800005 */ 	bnez	$a0,.L0f13f310
/*  f13f2fc:	00000000 */ 	nop
/*  f13f300:	44045000 */ 	mfc1	$a0,$f10
/*  f13f304:	3c018000 */ 	lui	$at,0x8000
/*  f13f308:	10000007 */ 	b	.L0f13f328
/*  f13f30c:	00812025 */ 	or	$a0,$a0,$at
.L0f13f310:
/*  f13f310:	10000005 */ 	b	.L0f13f328
/*  f13f314:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f13f318:	44045000 */ 	mfc1	$a0,$f10
.L0f13f31c:
/*  f13f31c:	00000000 */ 	nop
/*  f13f320:	0480fffb */ 	bltz	$a0,.L0f13f310
/*  f13f324:	00000000 */ 	nop
.L0f13f328:
/*  f13f328:	44cff800 */ 	ctc1	$t7,$31
/*  f13f32c:	2c810100 */ 	sltiu	$at,$a0,0x100
/*  f13f330:	54200003 */ 	bnezl	$at,.L0f13f340
/*  f13f334:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f13f338:	240400ff */ 	addiu	$a0,$zero,0xff
/*  f13f33c:	24420004 */ 	addiu	$v0,$v0,0x4
.L0f13f340:
/*  f13f340:	1472ffcb */ 	bne	$v1,$s2,.L0f13f270
/*  f13f344:	a044003f */ 	sb	$a0,0x3f($v0)
/*  f13f348:	10000010 */ 	b	.L0f13f38c
/*  f13f34c:	9224006f */ 	lbu	$a0,0x6f($s1)
/*  f13f350:	8238006f */ 	lb	$t8,0x6f($s1)
.L0f13f354:
/*  f13f354:	00001825 */ 	or	$v1,$zero,$zero
/*  f13f358:	02201025 */ 	or	$v0,$s1,$zero
/*  f13f35c:	0703000a */ 	bgezl	$t8,.L0f13f388
/*  f13f360:	ae200064 */ 	sw	$zero,0x64($s1)
/*  f13f364:	ae200064 */ 	sw	$zero,0x64($s1)
.L0f13f368:
/*  f13f368:	90590033 */ 	lbu	$t9,0x33($v0)
/*  f13f36c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f13f370:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f13f374:	1472fffc */ 	bne	$v1,$s2,.L0f13f368
/*  f13f378:	a059003f */ 	sb	$t9,0x3f($v0)
/*  f13f37c:	10000003 */ 	b	.L0f13f38c
/*  f13f380:	9224006f */ 	lbu	$a0,0x6f($s1)
/*  f13f384:	ae200064 */ 	sw	$zero,0x64($s1)
.L0f13f388:
/*  f13f388:	9224006f */ 	lbu	$a0,0x6f($s1)
.L0f13f38c:
/*  f13f38c:	34890004 */ 	ori	$t1,$a0,0x4
.L0f13f390:
/*  f13f390:	3c02800a */ 	lui	$v0,%hi(g_WallhitsMax)
/*  f13f394:	a229006f */ 	sb	$t1,0x6f($s1)
/*  f13f398:	8c42cc44 */ 	lw	$v0,%lo(g_WallhitsMax)($v0)
/*  f13f39c:	26f70001 */ 	addiu	$s7,$s7,0x1
.L0f13f3a0:
/*  f13f3a0:	02e2082a */ 	slt	$at,$s7,$v0
/*  f13f3a4:	1420fe5a */ 	bnez	$at,.L0f13ed10
/*  f13f3a8:	2631007c */ 	addiu	$s1,$s1,124
.L0f13f3ac:
/*  f13f3ac:	8fbf006c */ 	lw	$ra,0x6c($sp)
/*  f13f3b0:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f13f3b4:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f13f3b8:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f13f3bc:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f13f3c0:	d7bc0038 */ 	ldc1	$f28,0x38($sp)
/*  f13f3c4:	d7be0040 */ 	ldc1	$f30,0x40($sp)
/*  f13f3c8:	8fb00048 */ 	lw	$s0,0x48($sp)
/*  f13f3cc:	8fb1004c */ 	lw	$s1,0x4c($sp)
/*  f13f3d0:	8fb20050 */ 	lw	$s2,0x50($sp)
/*  f13f3d4:	8fb30054 */ 	lw	$s3,0x54($sp)
/*  f13f3d8:	8fb40058 */ 	lw	$s4,0x58($sp)
/*  f13f3dc:	8fb5005c */ 	lw	$s5,0x5c($sp)
/*  f13f3e0:	8fb60060 */ 	lw	$s6,0x60($sp)
/*  f13f3e4:	8fb70064 */ 	lw	$s7,0x64($sp)
/*  f13f3e8:	8fbe0068 */ 	lw	$s8,0x68($sp)
/*  f13f3ec:	03e00008 */ 	jr	$ra
/*  f13f3f0:	27bd0130 */ 	addiu	$sp,$sp,0x130
);
const char var7f1b5a54[] = "wallhit";

s32 var8007f834 = 0;
#else

// Mismatch: float regalloc for midx, midy and midz
void wallhitsTick(void)
{
	f32 sp12c;
	f32 fov;
	s32 numallocated;
	s32 i;
	s32 j;
	u32 stack[3];
	f32 midx;
	f32 midy;
	f32 midz;
	f32 f22;
	f32 f24;
	struct wallhit *wallhit;
	struct coord spc8[4];
	u32 stack2[4];

	static s32 var8007f834 = 0;

	sp12c = (g_Vars.lvupdate240 + 2.0f) * 0.25f;
	fov = currentPlayerGetGunZoomFov();

	mainOverrideVariable("wallhit", &var8007f750);

	var8007f740 = 0;

	if (fov == 0.0f || fov == 60.0f) {
		var8007f748 = 1;
	} else {
		f32 tmp = fov / g_Vars.currentplayer->zoominfovy;
		var8007f748 = 60.0f / fov - 1.00f / tmp + 1;
	}

	var8007f74c = 1.0f / var8007f748;

	numallocated = g_WallhitsNumFree + g_WallhitsNumUsed;

	if (numallocated < var8009cc70) {
		wallhitReapOne();
	} else if (numallocated < var8009cc74) {
		var8007f834++;

		if (var8007f834 == 8) {
			var8007f834 = 0;
			wallhitReapOne();
		}
	}

	wallhit = g_Wallhits;

	for (i = 0; i < g_WallhitsMax; i++) {
		f32 f0 = sp12c;

		if (wallhit->inuse) {
			if (wallhit->timerspeed != 8) {
				f0 *= 0.6f * ((wallhit->timerspeed - 8.0f) * 0.125f);
			}

			if (wallhit->timermax) {
				u32 amount = (u32)(f0 + 0.5f);

				if (wallhit->expanding) {
					if (wallhit->timercur > wallhit->timermax) {
						wallhit->timermax = 0;
						wallhit->timercur = 0;
						wallhit->inuse = true;
					}

					wallhit->timercur += amount;
				} else {
					if (amount < wallhit->timercur) {
						wallhit->timercur -= amount;
					} else {
						wallhitFree(wallhit);
					}
				}

				if (wallhit->timermax) {
					f24 = (f32) wallhit->timercur / wallhit->timermax;

					if (f24 > 1.0f) {
						f24 = 1.0f;
					}

					f22 = f24;

					if (wallhit->expanding) {
						f32 frac = 0.2f;
						f32 sizefrac;
						f32 f30;
						s32 minindex;
						f32 tmp;
						s32 j;

						tmp = 1.5707964f * f24;
						f30 = (1.0f - frac) * sinf(tmp);
						f22 = 1.0f - tmp + 0.6f;

						wallhit->vertices2 = gfxAllocateVertices(4);

						midx = var800845dc.x; \
						midy = var800845dc.y; \
						midz = var800845dc.z;

						// Copy the vertices into a float array
						for (j = 0; j < 4; j++) {
							spc8[j].x = wallhit->vertices[j].x;
							spc8[j].y = wallhit->vertices[j].y;
							spc8[j].z = wallhit->vertices[j].z;
						}

						// Sum the vertices and divide them by 4 to get the centre
						minindex = 0;

						for (j = 0; j < 4; j++) {
							midx = midx + spc8[j].x;
							midy = midy + spc8[j].y;
							midz = midz + spc8[j].z;

							// This should be j != 0, but minindex is unused
							// so it doesn't affect anything
							if (minindex != 0 && spc8[j].y < spc8[minindex].y) {
								minindex = j;
							}
						}

						midx = 0.25f * midx;
						midy = 0.25f * midy;
						midz = 0.25f * midz;

						sizefrac = frac + f30;

						// Calculate and apply the new size
						for (j = 0; j < 4; j++) {
							f32 xradius = spc8[j].x - midx;
							f32 yradius = spc8[j].y - midy;
							f32 zradius = spc8[j].z - midz;

							wallhit->vertices2[j].x = midx + xradius * sizefrac;
							wallhit->vertices2[j].y = midy + yradius * sizefrac;
							wallhit->vertices2[j].z = midz + zradius * sizefrac;
							wallhit->vertices2[j].s = wallhit->vertices[j].s;
							wallhit->vertices2[j].t = wallhit->vertices[j].t;
							wallhit->vertices2[j].colour = wallhit->vertices[j].colour;
						}

						if (1);

						f24 *= 2.0f;

						if (f24 > 1.0f) {
							f24 = 1.0f;
						}

						if (1);
					}

					for (j = 0; j < 4; j++) {
						u32 alpha;

						if (f22 > 1.0f) {
							f22 = 1.0f;
						}

						alpha = wallhit->basecolours[j].a * f24;

						if (alpha > 255) {
							alpha = 255;
						}

						wallhit->finalcolours[j].a = alpha;
					}
				} else {
					if (wallhit->inuse) {
						wallhit->vertices2 = NULL;

						for (j = 0; j < 4; j++) {
							wallhit->finalcolours[j].a = wallhit->basecolours[j].a;
						}
					} else {
						wallhit->vertices2 = NULL;
					}
				}
			}

			wallhit->unk6f_05 = true;
		}

		wallhit++;

		if (1);
	}
}
#endif

const char var7f1b5a5c[] = "g_MaxRound = %s%s%f";
const char var7f1b5a70[] = "";
const char var7f1b5a74[] = "";
const char var7f1b5a78[] = "g_MinRound = %s%s%f";
const char var7f1b5a8c[] = "";
const char var7f1b5a90[] = "";
const char var7f1b5a94[] = "Done %d Z buffer calcs";
const char var7f1b5aac[] = "ZOOM : g_ZoomFactor=%s%s%f";
const char var7f1b5ac8[] = "";
const char var7f1b5acc[] = "";
const char var7f1b5ad0[] = "ZOOM : g_ZoomScalar=%s%s%f";
const char var7f1b5aec[] = "";
const char var7f1b5af0[] = "";
const char var7f1b5af4[] = "ZOOM : scale=%s%s%f";
const char var7f1b5b08[] = "";
const char var7f1b5b0c[] = "";
const char var7f1b5b10[] = "WallHit_Tick : Status - RED";
const char var7f1b5b2c[] = "WallHit_Tick : Status - YELLOW (%u)";
const char var7f1b5b50[] = "WallHit_Tick : Status - GREEN";
const char var7f1b5b70[] = "WallHit_Tick : %d Used";
const char var7f1b5b88[] = "WallHit_Tick : %d Free";
const char var7f1b5ba0[] = "WallHit_Tick : %d Pending";
const char var7f1b5bbc[] = "WallHit_Tick : %d Blood";
const char var7f1b5bd4[] = "WallHit_Tick : %d Other";
const char var7f1b5bec[] = "WallHit_Tick : %d Ratio";
const char var7f1b5c04[] = "WallHit_Tick : %d(%d) Prop Hits";
const char var7f1b5c24[] = "tLifeTime=%s%s%f, tScalarGbl=%f";
const char var7f1b5c44[] = "";
const char var7f1b5c48[] = "";

void wallhitCreate(struct coord *relpos, struct coord *arg1, struct coord *arg2, s16 arg3[3],
		s16 arg4[3], s16 texnum, s16 room, struct prop *objprop,
		s8 mtxindex, s8 arg9, struct chrdata *chr, bool xlu)
{
	f32 scale = RANDOMFRAC() * 0.1f + 0.6f;
	f32 width = g_WallhitTexes[texnum].width * scale;
	f32 height = g_WallhitTexes[texnum].height * scale;

	wallhitCreateWith20Args(relpos, arg1, arg2, arg3,
			arg4, texnum, room, objprop,
			NULL, mtxindex, arg9, chr,
			width, height, 0xff, 0xff,
			0, 0, 0, xlu);
}

void wallhitCreateWith20Args(struct coord *relpos, struct coord *arg1, struct coord *arg2, s16 arg3[3],
		s16 arg4[3], s16 texnum, s16 room, struct prop *objprop,
		struct prop *chrprop, s8 mtxindex, s8 arg10, struct chrdata *chr,
		f32 width, f32 height, u8 minalpha, u8 maxalpha,
		s32 rotdeg, u32 timermax, u32 timerspeed, bool xlu)
{
	struct coord sp1f4;
	struct coord sp1e8;
	struct coord sp1dc;
	struct coord sp1d0;
	bool xiszero;
	bool ziszero;
	bool yiszero;
	struct coord sp1b8;
	struct coord sp1ac;
	struct coord sp17c[4];
	s32 type;
	f32 f0;
	u8 alpha;
	struct wallhit *wallhit;
	f32 mult = 1.0f;
	f32 brightnessfrac;
#if VERSION >= VERSION_NTSC_1_0
	bool paintball;
#endif
	u32 stack[6];
	struct coord sp13c;
	struct coord sp130;
	u32 stack2[3];
	struct coord sp118;
	s32 i;
	s32 room2;
	u32 range;
	struct coord sp100;

	sp1b8 = *arg1;

#if VERSION >= VERSION_NTSC_1_0
	func0f177164(&sp1b8, &sp1b8, 956, "wallhit.c");
#else
	func0f177164(&sp1b8, &sp1b8, 955, "wallhit.c");
#endif

#if VERSION >= VERSION_NTSC_1_0
	paintball = chrIsUsingPaintball(chr);

	if (paintball && g_WallhitTexes[texnum].type != WALLHITTYPE_BLOOD) {
		if (texnum != WALLHITTEX_SCORCH) {
			width = 15.0f;
			height = 15.0f;
		}

		texnum = WALLHITTEX_PAINT;
		timermax = TICKS(10);
	}

	switch (texnum) {
	case WALLHITTEX_BULLET2:
	case WALLHITTEX_BLOOD1:
	case WALLHITTEX_BLOOD2:
	case WALLHITTEX_BLOOD3:
	case WALLHITTEX_BLOOD4:
	case WALLHITTEX_BPGLASS1:
	case WALLHITTEX_BPGLASS2:
	case WALLHITTEX_BPGLASS3:
	case WALLHITTEX_METAL:
		break;
	default:
	case WALLHITTEX_SCORCH:
	case WALLHITTEX_PAINT:
	case WALLHITTEX_WOOD:
		rotdeg = random() % 360;
		break;
	}

	type = paintball ? WALLHITTYPE_PAINT : g_WallhitTexes[texnum].type;
#else
	switch (texnum) {
	case WALLHITTEX_BULLET2:
	case WALLHITTEX_PAINT:
	case WALLHITTEX_BLOOD1:
	case WALLHITTEX_BLOOD2:
	case WALLHITTEX_BLOOD3:
	case WALLHITTEX_BLOOD4:
	case WALLHITTEX_BPGLASS1:
	case WALLHITTEX_BPGLASS2:
	case WALLHITTEX_BPGLASS3:
	case WALLHITTEX_METAL:
		break;
	default:
	case WALLHITTEX_SCORCH:
	case WALLHITTEX_WOOD:
		rotdeg = random() % 360;
		break;
	}

	if (chrIsUsingPaintball(chr) && g_WallhitTexes[texnum].type != WALLHITTYPE_BLOOD) {
		if (texnum != WALLHITTEX_SCORCH) {
			width = 15.0f;
			height = 15.0f;
		}

		rotdeg = random() % 360;
		type = WALLHITTYPE_PAINT;
		timermax = TICKS(10);
	} else {
		type = g_WallhitTexes[texnum].type;
	}
#endif

	if (g_FreeWallhits != NULL) {
		// Check if we are at a limit and need to free some old wallhits
		s32 room2 = objprop ? 0 : room;
		s32 max;

		if (objprop) {
			max = g_MaxPropWallhits - 1;
		} else {
			max = g_MaxBgWallhitsPerRoom - 1;
		}

		if (g_WallhitCountsPerRoom[room2] > max) {
			if (!wallhitReapOneInRoom(room2)) {
				return;
			}
		} else if (g_WallhitCountsPerRoom[room] > g_MaxBgWallhitsPerRoom) {
			if (!wallhitReapOneInRoom(room)) {
				return;
			}
		}

		// Adjust counters
		g_WallhitCountsPerRoom[room2]++;
		g_WallhitsNumFree--;
		var8009cc48++;

		if (g_WallhitTexes[texnum].type == WALLHITTYPE_BLOOD) {
			var8009cc54++;
		} else {
			var8009cc58++;
		}

		// Remove the head of the free list and prepend it to the active list
		wallhit = g_FreeWallhits;
		g_FreeWallhits = wallhit->globalnext;
		wallhit->globalnext = g_ActiveWallhits;
		g_ActiveWallhits = wallhit;

		wallhit->xlu = xlu;
		wallhit->localnext = NULL;

		// Prepend to the prop-local or room-local list
		if (objprop != NULL) {
			if (xlu) {
				wallhit->localnext = objprop->xluwallhits;
				objprop->xluwallhits = wallhit;
			} else {
				wallhit->localnext = objprop->opawallhits;
				objprop->opawallhits = wallhit;
			}

			wallhit->objprop = objprop;
		} else {
			if (xlu) {
				wallhit->localnext = g_Rooms[room].xluwallhits;
				g_Rooms[room].xluwallhits = wallhit;
			} else {
				wallhit->localnext = g_Rooms[room].opawallhits;
				g_Rooms[room].opawallhits = wallhit;
			}

			wallhit->objprop = NULL;
		}

		sp1ac.f[0] = relpos->x;
		sp1ac.f[1] = relpos->y;
		sp1ac.f[2] = relpos->z;

		xiszero = ABS(arg1->x) < var800845d4 ? true : false;
		yiszero = ABS(arg1->y) < var800845d4 ? true : false;
		ziszero = ABS(arg1->z) < var800845d4 ? true : false;

		if (xiszero && ziszero) {
			sp1f4.x = -1.0f;
			sp1f4.y = 0.0f;
			sp1f4.z = 0.0f;

			sp1e8.x = 0.0f;
			sp1e8.y = 0.0f;
			sp1e8.z = (arg1->y >= 0.0f ? 1.0f : -1.0f) * -1.0f;
		} else if (xiszero && yiszero) {
			sp1f4.x = arg1->z >= 0.0f ? 1.0f : -1.0f;
			sp1f4.y = 0.0f;
			sp1f4.z = 0.0f;

			sp1e8.x = 0.0f;
			sp1e8.y = -1.0f;
			sp1e8.z = 0.0f;
		} else if (yiszero && ziszero) {
			sp1f4.x = 0.0f;
			sp1f4.y = (arg1->x >= 0.0f ? 1.0f : -1.0f) * -1.0f;
			sp1f4.z = 0.0f;

			sp1e8.x = 0.0f;
			sp1e8.y = 0.0f;
			sp1e8.z = 1.0f;
		} else if (arg3 && arg4) {
			sp13c.x = arg3[0];
			sp13c.y = arg3[1];
			sp13c.z = arg3[2];

			sp130.x = arg4[0];
			sp130.y = arg4[1];
			sp130.z = arg4[2];

#if VERSION >= VERSION_NTSC_1_0
			func0f177164(&sp13c, &sp13c, 1151, "wallhit.c");
			func0f177164(&sp130, &sp130, 1152, "wallhit.c");
#else
			func0f177164(&sp13c, &sp13c, 1142, "wallhit.c");
			func0f177164(&sp130, &sp130, 1143, "wallhit.c");
#endif

			f0 = (sp13c.x * sp130.x + sp13c.y * sp130.y + sp13c.z * sp130.z) * -1.0f;

			sp118.x = f0 * sp13c.x + sp130.x;
			sp118.y = f0 * sp13c.y + sp130.y;
			sp118.z = f0 * sp13c.z + sp130.z;

			func0f1770ac(&sp13c, &sp118, &sp100);

			sp1f4 = sp13c;

			sp1e8 = sp118;
		} else {
			f32 f0 = sqrtf(sp1b8.x * sp1b8.x + sp1b8.z * sp1b8.z);
			f32 xvalue = sp1b8.x / f0;
			f32 zvalue = sp1b8.z / f0;

			sp1f4.x = zvalue;
			sp1f4.y = 0.0f;
			sp1f4.z = -xvalue;

			sp1e8.x = sp1b8.y * xvalue;
			sp1e8.y = -f0;
			sp1e8.z = sp1b8.y * zvalue;
		}

		osSyncPrintf("AFT : tVecU (along) = (%s%s%f,%f,%f)\n", "", "", sp1f4.x, sp1f4.y, sp1f4.z);
		osSyncPrintf("AFT : tVecV (up)    = (%s%s%f,%f,%f)\n", "", "", sp1e8.x, sp1e8.y, sp1e8.z);

		if (rotdeg != 0) {
			u32 stack[6];
			f32 spd0 = sinf(rotdeg * 0.017453292f);
			f32 spcc = cosf(rotdeg * 0.017453292f);
			u32 stack2[12];

			sp1dc.x = spcc * sp1f4.x + spd0 * sp1e8.x;
			sp1dc.y = spcc * sp1f4.y + spd0 * sp1e8.y;
			sp1dc.z = spcc * sp1f4.z + spd0 * sp1e8.z;

			sp1d0.x = -spd0 * sp1f4.x + spcc * sp1e8.x;
			sp1d0.y = -spd0 * sp1f4.y + spcc * sp1e8.y;
			sp1d0.z = -spd0 * sp1f4.z + spcc * sp1e8.z;
		} else {
			sp1dc = sp1f4;

			sp1d0 = sp1e8;
		}

		if (objprop) {
			struct defaultobj *obj = objprop->obj;
			Mtxf *mtx = &obj->model->matrices[mtxindex];
			struct doorobj *door = objprop->door;
			struct coord sp84;
			struct coord sp78;

			if (obj->type == OBJTYPE_DOOR && (door->doorflags & DOORFLAG_FLIP)) {
				sp1d0.x = -1.0f * sp1d0.x;
				sp1d0.y = -1.0f * sp1d0.y;
				sp1d0.z = -1.0f * sp1d0.z;
			}

			sp84 = sp1dc;

			sp78 = sp1d0;

			mtx4RotateVecInPlace(mtx, &sp84);
			mtx4RotateVecInPlace(mtx, &sp78);

			width /= sqrtf(sp84.x * sp84.x + sp84.y * sp84.y + sp84.z * sp84.z);
			height /= sqrtf(sp78.x * sp78.x + sp78.y * sp78.y + sp78.z * sp78.z);

			if (xlu) {
				obj->hidden2 |= OBJH2FLAG_HASXLU;
			} else {
				obj->hidden2 |= OBJH2FLAG_HASOPA;
			}
		} else {
			struct coord *roompos = roomGetPos(room);

			if (arg2 != NULL) {
				f32 xdist = arg2->x - relpos->x;
				f32 ydist = arg2->y - relpos->y;
				f32 zdist = arg2->z - relpos->z;
				f32 sum = xdist * sp1b8.x + ydist * sp1b8.y + zdist * sp1b8.z;

				if (sum < 0.0f) {
					sp1d0.x = -1.0f * sp1d0.x;
					sp1d0.y = -1.0f * sp1d0.y;
					sp1d0.z = -1.0f * sp1d0.z;
				}
			}

			sp1ac.x = mult * sp1ac.x;
			sp1ac.y = mult * sp1ac.y;
			sp1ac.z = mult * sp1ac.z;

			sp1ac.x -= roompos->x;
			sp1ac.y -= roompos->y;
			sp1ac.z -= roompos->z;

			width *= mult;
			height *= mult;
		}

		sp1dc.x = width * sp1dc.x;
		sp1dc.y = width * sp1dc.y;
		sp1dc.z = width * sp1dc.z;

		sp1d0.x = height * sp1d0.x;
		sp1d0.y = height * sp1d0.y;
		sp1d0.z = height * sp1d0.z;

		sp17c[0].x = sp1dc.x + sp1d0.x;
		sp17c[0].y = sp1dc.y + sp1d0.y;
		sp17c[0].z = sp1dc.z + sp1d0.z;

		sp17c[1].x = sp1dc.x - sp1d0.x;
		sp17c[1].y = sp1dc.y - sp1d0.y;
		sp17c[1].z = sp1dc.z - sp1d0.z;

		sp17c[2].x = -sp17c[0].x;
		sp17c[2].y = -sp17c[0].y;
		sp17c[2].z = -sp17c[0].z;

		sp17c[3].x = sp1d0.x - sp1dc.x; \
		sp17c[3].y = sp1d0.y - sp1dc.y; \
		sp17c[3].z = sp1d0.z - sp1dc.z;

		wallhit->relpos = *relpos;

		wallhit->mtxindex = mtxindex;
		wallhit->unk6f_01 = arg10;
		wallhit->roomnum = room;
		wallhit->inuse = true;
		wallhit->fading = false;
		wallhit->texturenum = texnum;
		wallhit->chrprop = chrprop;
		wallhit->objprop = objprop;
		wallhit->vertices2 = NULL;
		wallhit->timermax = timermax;
		wallhit->timercur = 0;
		wallhit->expanding = true;
		wallhit->timerspeed = timerspeed ? timerspeed : 8;
		wallhit->createdframe = g_Vars.lvframenum;
		wallhit->unk6f_05 = false;

		for (i = 0; i < 4; i++) {
			struct coord sp58;
			s16 x;
			s16 y;
			s16 z;

			sp58.x = sp17c[i].x + sp1ac.x;
			sp58.y = sp17c[i].y + sp1ac.y;
			sp58.z = sp17c[i].z + sp1ac.z;

			x = wallhitFinaliseAxis(sp58.x);
			y = wallhitFinaliseAxis(sp58.y);
			z = wallhitFinaliseAxis(sp58.z);

			wallhit->vertices[i].x = x;
			wallhit->vertices[i].y = y;
			wallhit->vertices[i].z = z;
			wallhit->vertices[i].colour = i * 4;
		}

		wallhit->vertices[0].s = 0;
		wallhit->vertices[0].t = g_TexWallhitConfigs[texnum].height * 32;
		wallhit->vertices[1].s = 0;
		wallhit->vertices[1].t = 0;
		wallhit->vertices[2].s = g_TexWallhitConfigs[texnum].width * 32;
		wallhit->vertices[2].t = 0;
		wallhit->vertices[3].s = g_TexWallhitConfigs[texnum].width * 32;
		wallhit->vertices[3].t = g_TexWallhitConfigs[texnum].height * 32;

		if (wallhit->objprop) {
			struct prop *prop = wallhit->objprop;

			while (prop->parent) {
				prop = prop->parent;
			}

			room2 = prop->rooms[0];
		} else {
			room2 = wallhit->roomnum;
		}

		{
			u8 r;
			u8 g;
			u8 b;
			u8 a;

			brightnessfrac = func0f000a10(room2) * (1.0f / 255.0f);

			range = maxalpha - (u32)minalpha;

			if (range) {
				alpha = minalpha + (random() % range);
			} else {
				alpha = 0;
			}

			for (i = 0; i < 4; i++) {
				switch (type) {
				case WALLHITTYPE_BULLET:
					r = g = b = 255 - (random() % 40);
					a = alpha ? alpha : 255;
					break;
				case WALLHITTYPE_SOFT:
					r = g = b = random() % 70;
					a = alpha ? alpha : 255 - (random() % 50);
					break;
				case WALLHITTYPE_SCORCH:
					r = g = b = random() % 50;
					a = alpha ? alpha : 255 - (random() % 80);
					break;
				case WALLHITTYPE_BLOOD:
					r = g_WallhitBloodColour[0];
					g = g_WallhitBloodColour[1];
					b = g_WallhitBloodColour[2];
					a = alpha ? alpha : 255;
					break;
				case WALLHITTYPE_PAINT:
					r = (random() % 2) ? 0xff : 0;
					g = (random() % 2) ? 0xff : 0;
					b = (random() % 2) ? 0xff : 0;
					a = alpha ? alpha : 255;
					break;
				default:
					osSyncPrintf("Wallhit colour %d not implemented, substituting black\n", type);
					r = g = b = 0;
					a = alpha ? alpha : 255;
					break;
				}

				wallhit->basecolours[i].r = r;
				wallhit->basecolours[i].g = g;
				wallhit->basecolours[i].b = b;
				wallhit->basecolours[i].a = a;

				wallhit->finalcolours[i].r = r * brightnessfrac;
				wallhit->finalcolours[i].g = g * brightnessfrac;
				wallhit->finalcolours[i].b = b * brightnessfrac;
				wallhit->finalcolours[i].a = wallhit->timermax ? 0 : a;
			}
		}
	}
}

/**
 * Maybe a LOD calculation?
 */
s32 wallhit0f140750(struct coord *coord)
{
	f32 x;
	f32 y;
	f32 z;
	f32 tmp;

	x = g_Vars.currentplayer->projectionmtx->m[3][0] - coord->f[0];
	y = g_Vars.currentplayer->projectionmtx->m[3][1] - coord->f[1];
	z = g_Vars.currentplayer->projectionmtx->m[3][2] - coord->f[2];

	var8007f740++;

	if (x < 0) {
		x = -x;
	}

	if (y < 0) {
		y = -y;
	}

	if (z < 0) {
		z = -z;
	}

	if (y > x) {
		x = y;
	}

	if (z > x) {
		x = z;
	}

	tmp = x * var8007f74c;

	if (tmp > 1600) {
		return 4;
	}

	if (tmp > 400) {
		return 8;
	}

	if (tmp > 300) {
		return 16;
	}

	if (tmp > 200) {
		return 32;
	}

	if (tmp > 100) {
		return 64;
	}

	return 128;
}

Gfx *wallhitRenderOpaBgHits(s32 roomnum, Gfx *gdl)
{
	struct wallhit *wallhit;
	struct colour *colours;
	s32 prevtexturenum;
	s32 prev6b;

	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gSPSetGeometryMode(gdl++, G_CULL_BACK);
#if VERSION >= VERSION_NTSC_1_0
	gDPSetTextureDetail(gdl++, G_TD_CLAMP);
#endif
	gDPSetColorDither(gdl++, G_CD_NOISE);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);

	prevtexturenum = -1;
	prev6b = -1;

	gdl = roomPushMtx(gdl, roomnum);

	wallhit = g_Rooms[roomnum].opawallhits;

	while (wallhit) {
		if (wallhit->inuse && wallhit->unk6f_05) {
			if (wallhit->xlu) {
				wallhit->unk6b = 1;
			} else {
				wallhit->unk6b = wallhit0f140750(&wallhit->relpos);
			}

			if (wallhit->texturenum != prevtexturenum || wallhit->unk6b != prev6b) {
				texSelect(&gdl, &g_TexWallhitConfigs[wallhit->texturenum], 2, wallhit->unk6b, 2, 1, NULL);

				prevtexturenum = wallhit->texturenum;
				prev6b = wallhit->unk6b;
			}

			colours = gfxAllocateColours(4);
			colours[0] = wallhit->finalcolours[0];
			colours[1] = wallhit->finalcolours[1];
			colours[2] = wallhit->finalcolours[2];
			colours[3] = wallhit->finalcolours[3];

			gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 4);

			if (wallhit->vertices2 != NULL) {
				gDPSetVerticeArray(gdl++, wallhit->vertices2, 4);
			} else {
				gDPSetVerticeArray(gdl++, osVirtualToPhysical(&wallhit->vertices), 4);
			}

			gDPTri2(gdl++, 0, 1, 2, 0, 2, 3);
		}

		wallhit = wallhit->localnext;
	}

	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gDPSetColorDither(gdl++, G_CD_BAYER);

	return gdl;
}

Gfx *wallhitRenderXluBgHits(s32 roomnum, Gfx *gdl)
{
	struct wallhit *wallhit;
	struct colour *colours;
	s32 prevtexturenum;
	s32 prev6b;

	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
#if VERSION >= VERSION_NTSC_1_0
	gDPSetTextureDetail(gdl++, G_TD_CLAMP);
#endif
	gDPSetColorDither(gdl++, G_CD_NOISE);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);

	prevtexturenum = -1;
	prev6b = -1;

	gdl = roomPushMtx(gdl, roomnum);

	wallhit = g_Rooms[roomnum].xluwallhits;

	while (wallhit) {
		if (wallhit->inuse && wallhit->unk6f_05) {
			wallhit->unk6b = 1;

			if (wallhit->texturenum != prevtexturenum || wallhit->unk6b != prev6b) {
				texSelect(&gdl, &g_TexWallhitConfigs[wallhit->texturenum], 2, wallhit->unk6b, 2, 1, NULL);

				prevtexturenum = wallhit->texturenum;
				prev6b = wallhit->unk6b;
			}

			colours = gfxAllocateColours(4);
			colours[0] = wallhit->finalcolours[0];
			colours[1] = wallhit->finalcolours[1];
			colours[2] = wallhit->finalcolours[2];
			colours[3] = wallhit->finalcolours[3];

			gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 4);

			if (wallhit->vertices2 != NULL) {
				gDPSetVerticeArray(gdl++, wallhit->vertices2, 4);
			} else {
				gDPSetVerticeArray(gdl++, osVirtualToPhysical(&wallhit->vertices), 4);
			}

			gDPTri2(gdl++, 0, 1, 2, 0, 2, 3);
		}

		wallhit = wallhit->localnext;
	}

	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gDPSetColorDither(gdl++, G_CD_BAYER);

	return gdl;
}

Gfx *wallhitRenderPropHits(Gfx *gdl, struct prop *prop, bool xlu)
{
	struct colour *colours;
	struct defaultobj *obj = prop->obj;
	bool hasany = false;
	struct wallhit *wallhit;
	s16 prevmtxindex = -1;
	s32 prevtexturenum = -1;
	s32 prev6b = -1;

	if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
		return gdl;
	}

	gSPClearGeometryMode(gdl++, G_CULL_BOTH);

	if (!xlu) {
		gSPSetGeometryMode(gdl++, G_CULL_BACK);
	}

#if VERSION >= VERSION_NTSC_1_0
	gDPSetTextureDetail(gdl++, G_TD_CLAMP);
#endif
	gDPSetColorDither(gdl++, G_CD_NOISE);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);

	wallhit = xlu ? prop->xluwallhits : prop->opawallhits;

	while (wallhit) {
		if (wallhit->inuse) {
			hasany = true;

			if (wallhit->mtxindex != prevmtxindex) {
				Mtxf *mtx = &obj->model->matrices[wallhit->mtxindex];
				if (wallhit->mtxindex);
				prevmtxindex = wallhit->mtxindex;
				gSPMatrix(gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
			}

			if (!xlu) {
				if (wallhit->xlu) {
					wallhit->unk6b = 1;
				} else {
					struct coord sp74;
					sp74.x = wallhit->relpos.x + prop->pos.x;
					sp74.y = wallhit->relpos.y + prop->pos.y;
					sp74.z = wallhit->relpos.z + prop->pos.z;

					wallhit->unk6b = wallhit0f140750(&sp74);
				}
			} else {
				wallhit->unk6b = 1;
			}

			if (prevtexturenum != wallhit->texturenum || prev6b != wallhit->unk6b) {
				texSelect(&gdl, &g_TexWallhitConfigs[wallhit->texturenum], 2, wallhit->unk6b, 2, 1, NULL);

				prevtexturenum = wallhit->texturenum;
				prev6b = wallhit->unk6b;
			}

			colours = gfxAllocateColours(4);
			colours[0] = wallhit->finalcolours[0];
			colours[1] = wallhit->finalcolours[1];
			colours[2] = wallhit->finalcolours[2];
			colours[3] = wallhit->finalcolours[3];

			gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 4);

			if (wallhit->vertices2 != NULL) {
				gDPSetVerticeArray(gdl++, wallhit->vertices2, 4);
			} else {
				gDPSetVerticeArray(gdl++, osVirtualToPhysical(&wallhit->vertices), 4);
			}

			gDPTri2(gdl++, 0, 1, 2, 0, 2, 3);
		}

		wallhit = wallhit->localnext;
	}

	if (!hasany) {
		obj->hidden2 &= ~(1 << xlu);
	}

	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gDPSetColorDither(gdl++, G_CD_BAYER);

	return gdl;
}

Gfx *wallhitRenderBgHits(s32 roomnum, Gfx *gdl)
{
	if (g_Rooms[roomnum].opawallhits != NULL) {
		gdl = wallhitRenderOpaBgHits(roomnum, gdl);
	}

	if (g_Rooms[roomnum].xluwallhits != NULL) {
		gdl = wallhitRenderXluBgHits(roomnum, gdl);
	}

	return gdl;
}

void wallhitsRecolour(void)
{
	s32 i;
	s32 j;
	u32 stack;
	struct wallhit *wallhit;
	f32 sp0c;
	f32 sp08;
	f32 sp04;

	for (i = 0, wallhit = g_Wallhits; i < g_WallhitsMax; i++) {
		if (wallhit->roomnum > 0) {
			s32 room = -1;

			if (wallhit->objprop != NULL) {
				struct prop *prop = wallhit->objprop;

				while (prop->parent) {
					prop = prop->parent;
				}

				for (j = 0; prop->rooms[j] != -1; j++) {
					if (g_Rooms[prop->rooms[j]].flags & ROOMFLAG_1000) {
						room = prop->rooms[j];

						sp0c = g_Rooms[room].unk74;
						sp08 = g_Rooms[room].unk78;
						sp04 = g_Rooms[room].unk7c;
						break;
					}
				}
			} else {
				if (g_Rooms[wallhit->roomnum].flags & ROOMFLAG_1000) {
					room = wallhit->roomnum;

					sp0c = g_Rooms[room].unk74;
					sp08 = g_Rooms[room].unk78;
					sp04 = g_Rooms[room].unk7c;
				}
			}

			if (room > 0) {
				for (j = 0; j < 4; j++) {
					wallhit->finalcolours[j].r = wallhit->basecolours[j].r * sp0c;
					wallhit->finalcolours[j].g = wallhit->basecolours[j].g * sp08;
					wallhit->finalcolours[j].b = wallhit->basecolours[j].b * sp04;
				}
			}
		}

		wallhit++;
	}
}

void wallhitFadeSplatsForRemovedChr(struct prop *chrprop)
{
	s32 i;

	for (i = 0; i < g_WallhitsMax; i++) {
		struct wallhit *wallhit = &g_Wallhits[i];

		if (wallhit->chrprop
				&& wallhit->roomnum > 0
				&& wallhit->chrprop == chrprop
				&& g_WallhitTexes[wallhit->texturenum].type == WALLHITTYPE_BLOOD) {
			if (IS_BLOOD_DROP(wallhit->texturenum) || (random() % 100) < 35) {
				wallhitFade(wallhit, TICKS(120));
			} else {
				wallhit->createdframe = g_Vars.lvframenum;
			}
		}
	}
}

void wallhitRemoveOldestWoundedSplatByChr(struct prop *chrprop)
{
	s32 oldestframe = 0x0fffffff;
	s32 oldestindex = -1;
	s32 i;

	for (i = 0; i < g_WallhitsMax; i++) {
		struct wallhit *wallhit = &g_Wallhits[i];

		if (wallhit->chrprop
				&& wallhit->roomnum > 0
				&& wallhit->chrprop == chrprop
				&& !wallhit->fading
				&& g_WallhitTexes[wallhit->texturenum].type == WALLHITTYPE_BLOOD
				&& IS_BLOOD_DROP(wallhit->texturenum)
				&& wallhit->createdframe < oldestframe) {
			oldestframe = wallhit->createdframe;
			oldestindex = i;
		}
	}

	if (oldestindex != -1) {
		wallhitFade(&g_Wallhits[oldestindex], TICKS(120));
	}
}

Gfx *wallhit0f141814(Gfx *gdl, s32 arg1)
{
	return gdl;
}
