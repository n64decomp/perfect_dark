#include <ultra64.h>
#include "constants.h"
#include "data.h"
#include "game/atan2f.h"
#include "game/dlights.h"
#include "game/file.h"
#include "game/game_092610.h"
#include "game/game_0b3350.h"
#include "game/game_0b4950.h"
#include "game/gfxmemory.h"
#include "bss.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "lib/rng.h"
#include "types.h"

s32 g_MaxShards;
struct shard *g_Shards;

s32 g_NextShardNum = 0;
bool g_ShardsActive = false;

void shardCreate(s16 room, struct coord *pos, f32 rotx, f32 size, s32 type);

void shardsCreate(struct coord *pos, f32 *rotx, f32 *roty, f32 *rotz, f32 relxmin, f32 relxmax, f32 relymin, f32 relymax, s32 type, struct prop *prop)
{
	s32 y;
	s32 x;
	s32 speci;
	s32 speci2;
	struct coord thispos;
	f32 f0;
	f32 f20;
	f32 f30;
	f32 spec;
	s32 ymax;
	s32 xmax;
	struct coord basepos;
	f32 spcc[3];
	f32 spc0[3];
	f32 spac;

	spcc[0] = rotx[0];
	spcc[1] = rotx[1];
	spcc[2] = rotx[2];

	f0 = sqrtf(spcc[0] * spcc[0] + spcc[1] * spcc[1] + spcc[2] * spcc[2]);

	spcc[0] *= 1.0f / f0;
	spcc[1] *= 1.0f / f0;
	spcc[2] *= 1.0f / f0;

	relxmin *= f0;
	relxmax *= f0;

	spc0[0] = roty[0];
	spc0[1] = roty[1];
	spc0[2] = roty[2];

	f0 = sqrtf(spc0[0] * spc0[0] + spc0[1] * spc0[1] + spc0[2] * spc0[2]);

	spc0[0] *= 1.0f / f0;
	spc0[1] *= 1.0f / f0;
	spc0[2] *= 1.0f / f0;

	relymin *= f0;
	relymax *= f0;

	f30 = atan2f(rotz[0], rotz[2]);

	f20 = relxmax - relxmin;
	spac = relymax - relymin;

	spec = sqrtf(f20 * spac / (f32) (g_MaxShards / 2));
	speci = spec;
	speci2 = speci;

	basepos.x = (pos->f[0] + (relxmin + (speci >> 1)) * spcc[0]) + spc0[0] * (relymin + (speci >> 1));
	basepos.y = (pos->f[1] + (relxmin + (speci >> 1)) * spcc[1]) + spc0[1] * (relymin + (speci >> 1));
	basepos.z = (pos->f[2] + (relxmin + (speci >> 1)) * spcc[2]) + spc0[2] * (relymin + (speci >> 1));

	if (type == SHARDTYPE_GLASS) {
		func0f0939f8(NULL, NULL, SFX_GLASS_SHATTER, -1,
				-1, 0, 0, 0, &prop->pos, -1.0f, prop->rooms, -1, -1.0f, -1.0f, -1.0f);
	} else if (type == SHARDTYPE_BOTTLE) {
		/**
		 * @bug: This attempts to play one of two bottle breaking sounds
		 * randomly, but one of the SFX IDs isn't valid. This is why on Villa
		 * when you shoot the bottles, half of them don't play any breaking
		 * sound effect.
		 */
		func0f0939f8(NULL, NULL, SFX_BOTTLE_BREAK + (random() % 2) * 2, -1,
				-1, 0, 0, 0, &prop->pos, -1.0f, prop->rooms, -1, -1.0f, -1.0f, -1.0f);
	} else if (type == SHARDTYPE_WOOD) {
		func0f0939f8(NULL, NULL, SFX_WOOD_BREAK, -1,
				-1, 0, 0, 0, &prop->pos, -1.0f, prop->rooms, -1, -1.0f, -1.0f, -1.0f);
	}

	xmax = f20 / speci;
	ymax = spac / speci2;

	for (y = 0; y < ymax; y++) {
		f32 f20 = y * (f32) speci2;

		for (x = 0; x < xmax; x++) {
			thispos.x = basepos.f[0] + x * (f32) speci * spcc[0] + spc0[0] * f20;
			thispos.y = basepos.f[1] + x * (f32) speci * spcc[1] + spc0[1] * f20;
			thispos.z = basepos.f[2] + x * (f32) speci * spcc[2] + spc0[2] * f20;

			shardCreate(prop->rooms[0], &thispos, f30,
					(random() * (1.0f / U32_MAX) * 0.7f + 0.1f) * spec, type);
		}
	}
}

void shardCreate(s16 room, struct coord *pos, f32 rotx, f32 size, s32 type)
{
	f32 velx = random() * (1.0f / U32_MAX) * 2.0f - 1.0f;
	f32 vely = random() * (1.0f / U32_MAX) * 1.12f - 0.12f;
	f32 velz = random() * (1.0f / U32_MAX) * 2.0f - 1.0f;
	s32 i;

	g_Shards[g_NextShardNum].type = type;
	g_Shards[g_NextShardNum].room = room;
	g_Shards[g_NextShardNum].age60 = 1;

	g_Shards[g_NextShardNum].pos.x = pos->x;
	g_Shards[g_NextShardNum].pos.y = pos->y;
	g_Shards[g_NextShardNum].pos.z = pos->z;

	g_Shards[g_NextShardNum].vel.x = velx * PALUPF(1.5f);
	g_Shards[g_NextShardNum].vel.y = vely * PALUPF(3.0f);
	g_Shards[g_NextShardNum].vel.z = velz * PALUPF(1.5f);

	g_Shards[g_NextShardNum].vertices[0].x = (random() * (1.0f / U32_MAX) * 0.5f + 1.0f) * size;
	g_Shards[g_NextShardNum].vertices[0].y = (random() * (1.0f / U32_MAX) * 0.5f + 1.0f) * size;
	g_Shards[g_NextShardNum].vertices[1].x = (random() * (1.0f / U32_MAX) * 0.5f + 1.0f) * size;
	g_Shards[g_NextShardNum].vertices[1].y = (random() * (1.0f / U32_MAX) * 0.5f + 1.0f) * -size;
	g_Shards[g_NextShardNum].vertices[2].x = (random() * (1.0f / U32_MAX) * 0.5f + 1.0f) * -size;
	g_Shards[g_NextShardNum].vertices[2].y = (random() * (1.0f / U32_MAX) * 0.5f + 1.0f) * -size;

	for (i = 0; i < 3; i++) {
		g_Shards[g_NextShardNum].vertices[i].z = 0;
		g_Shards[g_NextShardNum].vertices[i].unk08 = 0;
		g_Shards[g_NextShardNum].vertices[i].unk0a = 0;
		g_Shards[g_NextShardNum].vertices[i].s = i * 4;
	}

	if (type == SHARDTYPE_WOOD) {
		s32 rand = random() % 100;

		if (rand < 20) {
			*(u32 *)g_Shards[g_NextShardNum].colours[0] = 0xbbbbbbf0;
			*(u32 *)g_Shards[g_NextShardNum].colours[1] = 0xaaaaaaf0;
			*(u32 *)g_Shards[g_NextShardNum].colours[2] = 0x777777f0;
		} else if (rand < 40) {
			*(u32 *)g_Shards[g_NextShardNum].colours[0] = 0x000000f0;
			*(u32 *)g_Shards[g_NextShardNum].colours[1] = 0x000000f0;
			*(u32 *)g_Shards[g_NextShardNum].colours[2] = 0x000000f0;
		} else if (rand < 60) {
			*(u32 *)g_Shards[g_NextShardNum].colours[0] = 0x553311f0;
			*(u32 *)g_Shards[g_NextShardNum].colours[1] = 0x553311f0;
			*(u32 *)g_Shards[g_NextShardNum].colours[2] = 0x553311f0;
		} else {
			*(u32 *)g_Shards[g_NextShardNum].colours[0] = 0xddaa88f0;
			*(u32 *)g_Shards[g_NextShardNum].colours[1] = 0xddaa88f0;
			*(u32 *)g_Shards[g_NextShardNum].colours[2] = 0xddaa88f0;
		}
	} else {
		s32 i;
		s32 j;

		g_Shards[g_NextShardNum].colours[0][0] = 0x05;
		g_Shards[g_NextShardNum].colours[0][1] = 0x05;
		g_Shards[g_NextShardNum].colours[0][2] = 0x7e;

		g_Shards[g_NextShardNum].colours[1][0] = 0x05;
		g_Shards[g_NextShardNum].colours[1][1] = 0xfb;
		g_Shards[g_NextShardNum].colours[1][2] = 0x7e;

		g_Shards[g_NextShardNum].colours[2][0] = 0xfb;
		g_Shards[g_NextShardNum].colours[2][1] = 0xfb;
		g_Shards[g_NextShardNum].colours[2][2] = 0x7e;

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				g_Shards[g_NextShardNum].colours[i][j] = random() % 0xff;
			}
		}

		g_Shards[g_NextShardNum].colours[0][3] = g_Shards[g_NextShardNum].colours[1][3] = g_Shards[g_NextShardNum].colours[2][3] = 0xff;
	}

	g_Shards[g_NextShardNum].rot.x = rotx;
	g_Shards[g_NextShardNum].rot.y = 0;
	g_Shards[g_NextShardNum].rot.z = random() * (1.0f / U32_MAX) * M_BADTAU;

	g_Shards[g_NextShardNum].rotspeed.x = random() * (1.0f / U32_MAX) * PALUPF(0.1f);
	g_Shards[g_NextShardNum].rotspeed.y = random() * (1.0f / U32_MAX) * PALUPF(0.1f);
	g_Shards[g_NextShardNum].rotspeed.z = random() * (1.0f / U32_MAX) * PALUPF(0.1f);

	g_NextShardNum++;

	if (g_NextShardNum >= g_MaxShards) {
		g_NextShardNum = 0;
	}

	if (!g_ShardsActive) {
		g_ShardsActive = true;
	}
}

#if VERSION >= VERSION_NTSC_1_0
Gfx *shardsRenderWood(Gfx *gdl)
{
	if (g_ShardsActive) {
		s16 prevroom = 0;
		s32 i;
		Mtxf shardmtx;
		s32 j;

		if (g_Vars.currentplayer->visionmode);

		gSPClearGeometryMode(gdl++, G_CULL_BOTH);
		gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);
		gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
		gDPSetTextureFilter(gdl++, G_TF_BILERP);
		gDPSetCycleType(gdl++, G_CYC_2CYCLE);
		gDPSetTextureLOD(gdl++, G_TL_LOD);
		gSPMatrix(gdl++, osVirtualToPhysical(currentPlayerGetUnk1758()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

		for (i = 0; i < g_MaxShards; i++) {
			if (g_Shards[i].age60 > 0 && g_Shards[i].type == SHARDTYPE_WOOD) {
				bool render = true;
				f32 alphamult = 1.0f;
				f32 xraydist;
				Mtxf *mtx = gfxAllocateMatrix();
				u32 stack;

				if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
					xraydist = sqrtf(ERASERSQDIST(g_Shards[i].pos.f));

					if (g_Vars.currentplayer->eraserpropdist < xraydist) {
						render = false;
					}

					if (g_Vars.currentplayer->eraserpropdist - 150.0f < xraydist) {
						alphamult = 1.0f - (xraydist - (g_Vars.currentplayer->eraserpropdist - 150.0f)) / 150.0f;
					}

					xraydist = xraydist / g_Vars.currentplayer->eraserpropdist;

					if (xraydist > 1.0f) {
						xraydist = 1.0f;
					}
				}

				if (render) {
					/**
					 * The following function call is really just this:
					 *
					 * func000166a4(&g_Shards[i].pos, &g_Shards[i].rot, &shardmtx);
					 *
					 * ... but that causes a mismatch, so I'm using a hacky but
					 * matching alternative. This hack is @dangerous because it
					 * assumes the offsets of pos and rot in the shard struct.
					 */
					func000166a4(
							(struct coord *)((u8 *)g_Shards + i * sizeof(struct shard) + 0x08),
							(struct coord *)((u8 *)g_Shards + i * sizeof(struct shard) + 0x14),
							&shardmtx);

					shardmtx.m[3][0] -= g_Vars.currentplayer->globaldrawworldoffset.x;
					shardmtx.m[3][1] -= g_Vars.currentplayer->globaldrawworldoffset.y;
					shardmtx.m[3][2] -= g_Vars.currentplayer->globaldrawworldoffset.z;

					if (shardmtx.m[3][0] < 10000 && shardmtx.m[3][0] > -10000
							&& shardmtx.m[3][1] < 10000 && shardmtx.m[3][1] > -10000
							&& shardmtx.m[3][2] < 10000 && shardmtx.m[3][2] > -10000) {
						func00016054(&shardmtx, mtx);

						gSPMatrix(gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

						if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
							u8 (*colours)[4] = gfxAllocateColours(3);

							if (g_Shards[i].age60 >= PALDOWN(100)) {
								f32 frac = g_Shards[i].age60 / (PAL ? 41.666664123535f : 50.0f);

								if (frac > 1) {
									frac = 1;
								}

								alphamult = (1.0f - frac) * alphamult;
							}

							alphamult *= 0.5f;

							for (j = 0; j < 3; j++) {
								colours[j][0] = xraydist * 255.0f;
								colours[j][1] = (1.0f - xraydist) * 255.0f;
								colours[j][2] = 0;
								colours[j][3] = g_Shards[g_NextShardNum].colours[j][3] * alphamult;
							}

							gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 3);
						} else {
							if (g_Shards[i].room != prevroom) {
								gdl = func0f001138(gdl, g_Shards[i].room);
								prevroom = g_Shards[i].room;
							}

							gDPSetColorArray(gdl++, osVirtualToPhysical(g_Shards[i].colours), 3);
						}

						gDPSetVerticeArray(gdl++, osVirtualToPhysical(g_Shards[i].vertices), 3);
						gSP1Triangle(gdl++, 0, 1, 2, 0);
					}
				}
			}
		}

		if (prevroom == 0) {
			gdl = func0f001300(gdl);
		}

		gSPClearGeometryMode(gdl++, G_LIGHTING | G_TEXTURE_GEN);
		gSPMatrix(gdl++, currentPlayerGetUnk1750(), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
		gSPMatrix(gdl++, currentPlayerGetUnk173c(), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	}

	return gdl;
}
#else
Gfx *shardsRenderWood(Gfx *gdl);

GLOBAL_ASM(
glabel shardsRenderWood
/*  f14bf50:	27bdfed8 */ 	addiu	$sp,$sp,-296
/*  f14bf54:	3c0e8008 */ 	lui	$t6,0x8008
/*  f14bf58:	8dce22e4 */ 	lw	$t6,0x22e4($t6)
/*  f14bf5c:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f14bf60:	00809825 */ 	or	$s3,$a0,$zero
/*  f14bf64:	afbf0064 */ 	sw	$ra,0x64($sp)
/*  f14bf68:	afbe0060 */ 	sw	$s8,0x60($sp)
/*  f14bf6c:	afb7005c */ 	sw	$s7,0x5c($sp)
/*  f14bf70:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f14bf74:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f14bf78:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f14bf7c:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f14bf80:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f14bf84:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f14bf88:	f7bc0038 */ 	sdc1	$f28,0x38($sp)
/*  f14bf8c:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f14bf90:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f14bf94:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f14bf98:	11c00192 */ 	beqz	$t6,.NB0f14c5e4
/*  f14bf9c:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f14bfa0:	a7a00126 */ 	sh	$zero,0x126($sp)
/*  f14bfa4:	24930008 */ 	addiu	$s3,$a0,0x8
/*  f14bfa8:	3c0fb600 */ 	lui	$t7,0xb600
/*  f14bfac:	24183000 */ 	addiu	$t8,$zero,0x3000
/*  f14bfb0:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f14bfb4:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f14bfb8:	02601825 */ 	or	$v1,$s3,$zero
/*  f14bfbc:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f14bfc0:	3c19b700 */ 	lui	$t9,0xb700
/*  f14bfc4:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f14bfc8:	24080204 */ 	addiu	$t0,$zero,0x204
/*  f14bfcc:	02602025 */ 	or	$a0,$s3,$zero
/*  f14bfd0:	ac680004 */ 	sw	$t0,0x4($v1)
/*  f14bfd4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f14bfd8:	3c09fcff */ 	lui	$t1,0xfcff
/*  f14bfdc:	3c0afffe */ 	lui	$t2,0xfffe
/*  f14bfe0:	354a793c */ 	ori	$t2,$t2,0x793c
/*  f14bfe4:	3529ffff */ 	ori	$t1,$t1,0xffff
/*  f14bfe8:	02602825 */ 	or	$a1,$s3,$zero
/*  f14bfec:	ac890000 */ 	sw	$t1,0x0($a0)
/*  f14bff0:	ac8a0004 */ 	sw	$t2,0x4($a0)
/*  f14bff4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f14bff8:	3c0bba00 */ 	lui	$t3,0xba00
/*  f14bffc:	356b0c02 */ 	ori	$t3,$t3,0xc02
/*  f14c000:	240c2000 */ 	addiu	$t4,$zero,0x2000
/*  f14c004:	02603025 */ 	or	$a2,$s3,$zero
/*  f14c008:	acac0004 */ 	sw	$t4,0x4($a1)
/*  f14c00c:	acab0000 */ 	sw	$t3,0x0($a1)
/*  f14c010:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f14c014:	3c0dba00 */ 	lui	$t5,0xba00
/*  f14c018:	35ad1402 */ 	ori	$t5,$t5,0x1402
/*  f14c01c:	3c0e0010 */ 	lui	$t6,0x10
/*  f14c020:	02601025 */ 	or	$v0,$s3,$zero
/*  f14c024:	acce0004 */ 	sw	$t6,0x4($a2)
/*  f14c028:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f14c02c:	3c0fba00 */ 	lui	$t7,0xba00
/*  f14c030:	35ef1001 */ 	ori	$t7,$t7,0x1001
/*  f14c034:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f14c038:	3c180001 */ 	lui	$t8,0x1
/*  f14c03c:	3c190103 */ 	lui	$t9,0x103
/*  f14c040:	3c17800a */ 	lui	$s7,0x800a
/*  f14c044:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f14c048:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f14c04c:	37390040 */ 	ori	$t9,$t9,0x40
/*  f14c050:	02608025 */ 	or	$s0,$s3,$zero
/*  f14c054:	26f7e6c0 */ 	addiu	$s7,$s7,-6464
/*  f14c058:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f14c05c:	0fc2cb5a */ 	jal	currentPlayerGetUnk1758
/*  f14c060:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f14c064:	0c013100 */ 	jal	osVirtualToPhysical
/*  f14c068:	00402025 */ 	or	$a0,$v0,$zero
/*  f14c06c:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f14c070:	3c08800b */ 	lui	$t0,0x800b
/*  f14c074:	8d088d40 */ 	lw	$t0,-0x72c0($t0)
/*  f14c078:	0000f025 */ 	or	$s8,$zero,$zero
/*  f14c07c:	0000a025 */ 	or	$s4,$zero,$zero
/*  f14c080:	1900013e */ 	blez	$t0,.NB0f14c57c
/*  f14c084:	3c013f80 */ 	lui	$at,0x3f80
/*  f14c088:	4481e000 */ 	mtc1	$at,$f28
/*  f14c08c:	3c014316 */ 	lui	$at,0x4316
/*  f14c090:	4481d000 */ 	mtc1	$at,$f26
/*  f14c094:	3c013f80 */ 	lui	$at,0x3f80
/*  f14c098:	3c158008 */ 	lui	$s5,0x8008
/*  f14c09c:	3c12800b */ 	lui	$s2,0x800b
/*  f14c0a0:	4481c000 */ 	mtc1	$at,$f24
/*  f14c0a4:	26528d44 */ 	addiu	$s2,$s2,-29372
/*  f14c0a8:	26b522e0 */ 	addiu	$s5,$s5,0x22e0
/*  f14c0ac:	c7b600b4 */ 	lwc1	$f22,0xb4($sp)
/*  f14c0b0:	2416000c */ 	addiu	$s6,$zero,0xc
/*  f14c0b4:	8e490000 */ 	lw	$t1,0x0($s2)
.NB0f14c0b8:
/*  f14c0b8:	01341021 */ 	addu	$v0,$t1,$s4
/*  f14c0bc:	8c4a0004 */ 	lw	$t2,0x4($v0)
/*  f14c0c0:	19400126 */ 	blez	$t2,.NB0f14c55c
/*  f14c0c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c0c8:	904b0068 */ 	lbu	$t3,0x68($v0)
/*  f14c0cc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f14c0d0:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f14c0d4:	15610121 */ 	bne	$t3,$at,.NB0f14c55c
/*  f14c0d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c0dc:	0fc588b6 */ 	jal	gfxAllocateMatrix
/*  f14c0e0:	4600c506 */ 	mov.s	$f20,$f24
/*  f14c0e4:	8ee30284 */ 	lw	$v1,0x284($s7)
/*  f14c0e8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14c0ec:	00408825 */ 	or	$s1,$v0,$zero
/*  f14c0f0:	946c0010 */ 	lhu	$t4,0x10($v1)
/*  f14c0f4:	15810025 */ 	bne	$t4,$at,.NB0f14c18c
/*  f14c0f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c0fc:	8e4d0000 */ 	lw	$t5,0x0($s2)
/*  f14c100:	c46a0018 */ 	lwc1	$f10,0x18($v1)
/*  f14c104:	c4660020 */ 	lwc1	$f6,0x20($v1)
/*  f14c108:	01b41021 */ 	addu	$v0,$t5,$s4
/*  f14c10c:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f14c110:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f14c114:	c450000c */ 	lwc1	$f16,0xc($v0)
/*  f14c118:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f14c11c:	c472001c */ 	lwc1	$f18,0x1c($v1)
/*  f14c120:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f14c124:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f14c128:	46128381 */ 	sub.s	$f14,$f16,$f18
/*  f14c12c:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f14c130:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f14c134:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f14c138:	0c012e84 */ 	jal	sqrtf
/*  f14c13c:	46085300 */ 	add.s	$f12,$f10,$f8
/*  f14c140:	8eee0284 */ 	lw	$t6,0x284($s7)
/*  f14c144:	c5c20024 */ 	lwc1	$f2,0x24($t6)
/*  f14c148:	4600103c */ 	c.lt.s	$f2,$f0
/*  f14c14c:	461a1301 */ 	sub.s	$f12,$f2,$f26
/*  f14c150:	45000002 */ 	bc1f	.NB0f14c15c
/*  f14c154:	46020583 */ 	div.s	$f22,$f0,$f2
/*  f14c158:	00008025 */ 	or	$s0,$zero,$zero
.NB0f14c15c:
/*  f14c15c:	4600603c */ 	c.lt.s	$f12,$f0
/*  f14c160:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c164:	45020005 */ 	bc1fl	.NB0f14c17c
/*  f14c168:	4616c03c */ 	c.lt.s	$f24,$f22
/*  f14c16c:	460c0401 */ 	sub.s	$f16,$f0,$f12
/*  f14c170:	461a8483 */ 	div.s	$f18,$f16,$f26
/*  f14c174:	4612c501 */ 	sub.s	$f20,$f24,$f18
/*  f14c178:	4616c03c */ 	c.lt.s	$f24,$f22
.NB0f14c17c:
/*  f14c17c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c180:	45000002 */ 	bc1f	.NB0f14c18c
/*  f14c184:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c188:	4600c586 */ 	mov.s	$f22,$f24
.NB0f14c18c:
/*  f14c18c:	120000f3 */ 	beqz	$s0,.NB0f14c55c
/*  f14c190:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c194:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f14c198:	27a600e0 */ 	addiu	$a2,$sp,0xe0
/*  f14c19c:	01f41021 */ 	addu	$v0,$t7,$s4
/*  f14c1a0:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f14c1a4:	0c005d8d */ 	jal	func000166a4
/*  f14c1a8:	24450014 */ 	addiu	$a1,$v0,0x14
/*  f14c1ac:	8ee30284 */ 	lw	$v1,0x284($s7)
/*  f14c1b0:	c7a40110 */ 	lwc1	$f4,0x110($sp)
/*  f14c1b4:	c7a80114 */ 	lwc1	$f8,0x114($sp)
/*  f14c1b8:	c4660038 */ 	lwc1	$f6,0x38($v1)
/*  f14c1bc:	27a400e0 */ 	addiu	$a0,$sp,0xe0
/*  f14c1c0:	02202825 */ 	or	$a1,$s1,$zero
/*  f14c1c4:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f14c1c8:	c7a40118 */ 	lwc1	$f4,0x118($sp)
/*  f14c1cc:	e7aa0110 */ 	swc1	$f10,0x110($sp)
/*  f14c1d0:	c470003c */ 	lwc1	$f16,0x3c($v1)
/*  f14c1d4:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f14c1d8:	e7b20114 */ 	swc1	$f18,0x114($sp)
/*  f14c1dc:	c4660040 */ 	lwc1	$f6,0x40($v1)
/*  f14c1e0:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f14c1e4:	0c005bd1 */ 	jal	func00016054
/*  f14c1e8:	e7aa0118 */ 	swc1	$f10,0x118($sp)
/*  f14c1ec:	3c180102 */ 	lui	$t8,0x102
/*  f14c1f0:	37180040 */ 	ori	$t8,$t8,0x40
/*  f14c1f4:	02608025 */ 	or	$s0,$s3,$zero
/*  f14c1f8:	ae180000 */ 	sw	$t8,0x0($s0)
/*  f14c1fc:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f14c200:	0c013100 */ 	jal	osVirtualToPhysical
/*  f14c204:	02202025 */ 	or	$a0,$s1,$zero
/*  f14c208:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f14c20c:	8ef90284 */ 	lw	$t9,0x284($s7)
/*  f14c210:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14c214:	97280010 */ 	lhu	$t0,0x10($t9)
/*  f14c218:	150100a9 */ 	bne	$t0,$at,.NB0f14c4c0
/*  f14c21c:	3c01437f */ 	lui	$at,0x437f
/*  f14c220:	44814000 */ 	mtc1	$at,$f8
/*  f14c224:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f14c228:	3c014f00 */ 	lui	$at,0x4f00
/*  f14c22c:	4608b402 */ 	mul.s	$f16,$f22,$f8
/*  f14c230:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f14c234:	4449f800 */ 	cfc1	$t1,$31
/*  f14c238:	44d0f800 */ 	ctc1	$s0,$31
/*  f14c23c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c240:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f14c244:	4450f800 */ 	cfc1	$s0,$31
/*  f14c248:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c24c:	32100078 */ 	andi	$s0,$s0,0x78
/*  f14c250:	52000013 */ 	beqzl	$s0,.NB0f14c2a0
/*  f14c254:	44109000 */ 	mfc1	$s0,$f18
/*  f14c258:	44819000 */ 	mtc1	$at,$f18
/*  f14c25c:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f14c260:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f14c264:	44d0f800 */ 	ctc1	$s0,$31
/*  f14c268:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c26c:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f14c270:	4450f800 */ 	cfc1	$s0,$31
/*  f14c274:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c278:	32100078 */ 	andi	$s0,$s0,0x78
/*  f14c27c:	16000005 */ 	bnez	$s0,.NB0f14c294
/*  f14c280:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c284:	44109000 */ 	mfc1	$s0,$f18
/*  f14c288:	3c018000 */ 	lui	$at,0x8000
/*  f14c28c:	10000007 */ 	beqz	$zero,.NB0f14c2ac
/*  f14c290:	02018025 */ 	or	$s0,$s0,$at
.NB0f14c294:
/*  f14c294:	10000005 */ 	beqz	$zero,.NB0f14c2ac
/*  f14c298:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f14c29c:	44109000 */ 	mfc1	$s0,$f18
.NB0f14c2a0:
/*  f14c2a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c2a4:	0600fffb */ 	bltz	$s0,.NB0f14c294
/*  f14c2a8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f14c2ac:
/*  f14c2ac:	44c9f800 */ 	ctc1	$t1,$31
/*  f14c2b0:	3c01437f */ 	lui	$at,0x437f
/*  f14c2b4:	44813000 */ 	mtc1	$at,$f6
/*  f14c2b8:	4616c101 */ 	sub.s	$f4,$f24,$f22
/*  f14c2bc:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f14c2c0:	3c014f00 */ 	lui	$at,0x4f00
/*  f14c2c4:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f14c2c8:	444af800 */ 	cfc1	$t2,$31
/*  f14c2cc:	44d1f800 */ 	ctc1	$s1,$31
/*  f14c2d0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c2d4:	46005224 */ 	cvt.w.s	$f8,$f10
/*  f14c2d8:	4451f800 */ 	cfc1	$s1,$31
/*  f14c2dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c2e0:	32310078 */ 	andi	$s1,$s1,0x78
/*  f14c2e4:	52200013 */ 	beqzl	$s1,.NB0f14c334
/*  f14c2e8:	44114000 */ 	mfc1	$s1,$f8
/*  f14c2ec:	44814000 */ 	mtc1	$at,$f8
/*  f14c2f0:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f14c2f4:	46085201 */ 	sub.s	$f8,$f10,$f8
/*  f14c2f8:	44d1f800 */ 	ctc1	$s1,$31
/*  f14c2fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c300:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f14c304:	4451f800 */ 	cfc1	$s1,$31
/*  f14c308:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c30c:	32310078 */ 	andi	$s1,$s1,0x78
/*  f14c310:	16200005 */ 	bnez	$s1,.NB0f14c328
/*  f14c314:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c318:	44114000 */ 	mfc1	$s1,$f8
/*  f14c31c:	3c018000 */ 	lui	$at,0x8000
/*  f14c320:	10000007 */ 	beqz	$zero,.NB0f14c340
/*  f14c324:	02218825 */ 	or	$s1,$s1,$at
.NB0f14c328:
/*  f14c328:	10000005 */ 	beqz	$zero,.NB0f14c340
/*  f14c32c:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f14c330:	44114000 */ 	mfc1	$s1,$f8
.NB0f14c334:
/*  f14c334:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c338:	0620fffb */ 	bltz	$s1,.NB0f14c328
/*  f14c33c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f14c340:
/*  f14c340:	44caf800 */ 	ctc1	$t2,$31
/*  f14c344:	0fc588c3 */ 	jal	gfxAllocateColours
/*  f14c348:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c34c:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f14c350:	00403025 */ 	or	$a2,$v0,$zero
/*  f14c354:	01746021 */ 	addu	$t4,$t3,$s4
/*  f14c358:	8d830004 */ 	lw	$v1,0x4($t4)
/*  f14c35c:	3c0b0708 */ 	lui	$t3,0x708
/*  f14c360:	356b000c */ 	ori	$t3,$t3,0xc
/*  f14c364:	28610064 */ 	slti	$at,$v1,0x64
/*  f14c368:	5420000f */ 	bnezl	$at,.NB0f14c3a8
/*  f14c36c:	3c013f00 */ 	lui	$at,0x3f00
/*  f14c370:	44838000 */ 	mtc1	$v1,$f16
/*  f14c374:	3c014248 */ 	lui	$at,0x4248
/*  f14c378:	44812000 */ 	mtc1	$at,$f4
/*  f14c37c:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f14c380:	46049003 */ 	div.s	$f0,$f18,$f4
/*  f14c384:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f14c388:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c38c:	45020003 */ 	bc1fl	.NB0f14c39c
/*  f14c390:	4600c181 */ 	sub.s	$f6,$f24,$f0
/*  f14c394:	4600e006 */ 	mov.s	$f0,$f28
/*  f14c398:	4600c181 */ 	sub.s	$f6,$f24,$f0
.NB0f14c39c:
/*  f14c39c:	46143502 */ 	mul.s	$f20,$f6,$f20
/*  f14c3a0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c3a4:	3c013f00 */ 	lui	$at,0x3f00
.NB0f14c3a8:
/*  f14c3a8:	44815000 */ 	mtc1	$at,$f10
/*  f14c3ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f14c3b0:	00401825 */ 	or	$v1,$v0,$zero
/*  f14c3b4:	460aa502 */ 	mul.s	$f20,$f20,$f10
/*  f14c3b8:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f14c3bc:
/*  f14c3bc:	a0700000 */ 	sb	$s0,0x0($v1)
/*  f14c3c0:	a0710001 */ 	sb	$s1,0x1($v1)
/*  f14c3c4:	a0600002 */ 	sb	$zero,0x2($v1)
/*  f14c3c8:	8eae0000 */ 	lw	$t6,0x0($s5)
/*  f14c3cc:	8e4d0000 */ 	lw	$t5,0x0($s2)
/*  f14c3d0:	3c014f80 */ 	lui	$at,0x4f80
/*  f14c3d4:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f14c3d8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f14c3dc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f14c3e0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f14c3e4:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f14c3e8:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f14c3ec:	0304c821 */ 	addu	$t9,$t8,$a0
/*  f14c3f0:	9328005f */ 	lbu	$t0,0x5f($t9)
/*  f14c3f4:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f14c3f8:	44884000 */ 	mtc1	$t0,$f8
/*  f14c3fc:	05010004 */ 	bgez	$t0,.NB0f14c410
/*  f14c400:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f14c404:	44819000 */ 	mtc1	$at,$f18
/*  f14c408:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c40c:	46128400 */ 	add.s	$f16,$f16,$f18
.NB0f14c410:
/*  f14c410:	46148102 */ 	mul.s	$f4,$f16,$f20
/*  f14c414:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f14c418:	3c014f00 */ 	lui	$at,0x4f00
/*  f14c41c:	4449f800 */ 	cfc1	$t1,$31
/*  f14c420:	44caf800 */ 	ctc1	$t2,$31
/*  f14c424:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c428:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f14c42c:	444af800 */ 	cfc1	$t2,$31
/*  f14c430:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c434:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f14c438:	51400013 */ 	beqzl	$t2,.NB0f14c488
/*  f14c43c:	440a3000 */ 	mfc1	$t2,$f6
/*  f14c440:	44813000 */ 	mtc1	$at,$f6
/*  f14c444:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f14c448:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f14c44c:	44caf800 */ 	ctc1	$t2,$31
/*  f14c450:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c454:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f14c458:	444af800 */ 	cfc1	$t2,$31
/*  f14c45c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c460:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f14c464:	15400005 */ 	bnez	$t2,.NB0f14c47c
/*  f14c468:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c46c:	440a3000 */ 	mfc1	$t2,$f6
/*  f14c470:	3c018000 */ 	lui	$at,0x8000
/*  f14c474:	10000007 */ 	beqz	$zero,.NB0f14c494
/*  f14c478:	01415025 */ 	or	$t2,$t2,$at
.NB0f14c47c:
/*  f14c47c:	10000005 */ 	beqz	$zero,.NB0f14c494
/*  f14c480:	240affff */ 	addiu	$t2,$zero,-1
/*  f14c484:	440a3000 */ 	mfc1	$t2,$f6
.NB0f14c488:
/*  f14c488:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c48c:	0540fffb */ 	bltz	$t2,.NB0f14c47c
/*  f14c490:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f14c494:
/*  f14c494:	44c9f800 */ 	ctc1	$t1,$31
/*  f14c498:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f14c49c:	1496ffc7 */ 	bne	$a0,$s6,.NB0f14c3bc
/*  f14c4a0:	a06affff */ 	sb	$t2,-0x1($v1)
/*  f14c4a4:	02608025 */ 	or	$s0,$s3,$zero
/*  f14c4a8:	ae0b0000 */ 	sw	$t3,0x0($s0)
/*  f14c4ac:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f14c4b0:	0c013100 */ 	jal	osVirtualToPhysical
/*  f14c4b4:	00c02025 */ 	or	$a0,$a2,$zero
/*  f14c4b8:	10000018 */ 	beqz	$zero,.NB0f14c51c
/*  f14c4bc:	ae020004 */ 	sw	$v0,0x4($s0)
.NB0f14c4c0:
/*  f14c4c0:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f14c4c4:	87ad0126 */ 	lh	$t5,0x126($sp)
/*  f14c4c8:	01947021 */ 	addu	$t6,$t4,$s4
/*  f14c4cc:	85c50000 */ 	lh	$a1,0x0($t6)
/*  f14c4d0:	51a50009 */ 	beql	$t5,$a1,.NB0f14c4f8
/*  f14c4d4:	3c080708 */ 	lui	$t0,0x708
/*  f14c4d8:	0fc0044e */ 	jal	func0f001138
/*  f14c4dc:	02602025 */ 	or	$a0,$s3,$zero
/*  f14c4e0:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f14c4e4:	00409825 */ 	or	$s3,$v0,$zero
/*  f14c4e8:	01f4c021 */ 	addu	$t8,$t7,$s4
/*  f14c4ec:	87190000 */ 	lh	$t9,0x0($t8)
/*  f14c4f0:	a7b90126 */ 	sh	$t9,0x126($sp)
/*  f14c4f4:	3c080708 */ 	lui	$t0,0x708
.NB0f14c4f8:
/*  f14c4f8:	3508000c */ 	ori	$t0,$t0,0xc
/*  f14c4fc:	02608025 */ 	or	$s0,$s3,$zero
/*  f14c500:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f14c504:	8e490000 */ 	lw	$t1,0x0($s2)
/*  f14c508:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f14c50c:	01342021 */ 	addu	$a0,$t1,$s4
/*  f14c510:	0c013100 */ 	jal	osVirtualToPhysical
/*  f14c514:	2484005c */ 	addiu	$a0,$a0,0x5c
/*  f14c518:	ae020004 */ 	sw	$v0,0x4($s0)
.NB0f14c51c:
/*  f14c51c:	3c0a0420 */ 	lui	$t2,0x420
/*  f14c520:	354a0024 */ 	ori	$t2,$t2,0x24
/*  f14c524:	02608025 */ 	or	$s0,$s3,$zero
/*  f14c528:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f14c52c:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f14c530:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f14c534:	01742021 */ 	addu	$a0,$t3,$s4
/*  f14c538:	0c013100 */ 	jal	osVirtualToPhysical
/*  f14c53c:	24840038 */ 	addiu	$a0,$a0,0x38
/*  f14c540:	02601825 */ 	or	$v1,$s3,$zero
/*  f14c544:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f14c548:	3c0cbf00 */ 	lui	$t4,0xbf00
/*  f14c54c:	240e0a14 */ 	addiu	$t6,$zero,0xa14
/*  f14c550:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f14c554:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f14c558:	26730008 */ 	addiu	$s3,$s3,0x8
.NB0f14c55c:
/*  f14c55c:	3c0d800b */ 	lui	$t5,0x800b
/*  f14c560:	8dad8d40 */ 	lw	$t5,-0x72c0($t5)
/*  f14c564:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f14c568:	2694006c */ 	addiu	$s4,$s4,0x6c
/*  f14c56c:	03cd082a */ 	slt	$at,$s8,$t5
/*  f14c570:	5420fed1 */ 	bnezl	$at,.NB0f14c0b8
/*  f14c574:	8e490000 */ 	lw	$t1,0x0($s2)
/*  f14c578:	e7b600b4 */ 	swc1	$f22,0xb4($sp)
.NB0f14c57c:
/*  f14c57c:	87af0126 */ 	lh	$t7,0x126($sp)
/*  f14c580:	55e00005 */ 	bnezl	$t7,.NB0f14c598
/*  f14c584:	02601025 */ 	or	$v0,$s3,$zero
/*  f14c588:	0fc004c0 */ 	jal	func0f001300
/*  f14c58c:	02602025 */ 	or	$a0,$s3,$zero
/*  f14c590:	00409825 */ 	or	$s3,$v0,$zero
/*  f14c594:	02601025 */ 	or	$v0,$s3,$zero
.NB0f14c598:
/*  f14c598:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f14c59c:	3c18b600 */ 	lui	$t8,0xb600
/*  f14c5a0:	3c190006 */ 	lui	$t9,0x6
/*  f14c5a4:	3c080103 */ 	lui	$t0,0x103
/*  f14c5a8:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f14c5ac:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f14c5b0:	35080040 */ 	ori	$t0,$t0,0x40
/*  f14c5b4:	02608025 */ 	or	$s0,$s3,$zero
/*  f14c5b8:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f14c5bc:	0fc2cb52 */ 	jal	currentPlayerGetUnk1750
/*  f14c5c0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f14c5c4:	3c090102 */ 	lui	$t1,0x102
/*  f14c5c8:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f14c5cc:	35290040 */ 	ori	$t1,$t1,0x40
/*  f14c5d0:	02608825 */ 	or	$s1,$s3,$zero
/*  f14c5d4:	ae290000 */ 	sw	$t1,0x0($s1)
/*  f14c5d8:	0fc2cb42 */ 	jal	currentPlayerGetUnk173c
/*  f14c5dc:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f14c5e0:	ae220004 */ 	sw	$v0,0x4($s1)
.NB0f14c5e4:
/*  f14c5e4:	8fbf0064 */ 	lw	$ra,0x64($sp)
/*  f14c5e8:	02601025 */ 	or	$v0,$s3,$zero
/*  f14c5ec:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f14c5f0:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f14c5f4:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f14c5f8:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f14c5fc:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f14c600:	d7bc0038 */ 	ldc1	$f28,0x38($sp)
/*  f14c604:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f14c608:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f14c60c:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f14c610:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f14c614:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f14c618:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f14c61c:	8fb7005c */ 	lw	$s7,0x5c($sp)
/*  f14c620:	8fbe0060 */ 	lw	$s8,0x60($sp)
/*  f14c624:	03e00008 */ 	jr	$ra
/*  f14c628:	27bd0128 */ 	addiu	$sp,$sp,0x128
);
#endif

#if VERSION >= VERSION_NTSC_1_0
Gfx *shardsRenderGlass(Gfx *gdl)
{
	if (g_ShardsActive) {
		s16 prevroom = 0;
		s32 i;
		Mtxf shardmtx;
		s32 j;

		if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
			func0f0b39c0(&gdl, NULL, 2, 1, 2, 1, NULL);
		} else {
			func0f0b39c0(&gdl, &var800ab590[1], 2, 1, 2, 1, NULL);
		}

		gSPTexture(gdl++, 0x0d80, 0x0d80, 2, G_TX_RENDERTILE, G_ON);
		gDPSetCycleType(gdl++, G_CYC_2CYCLE);
		gDPSetTextureLOD(gdl++, G_TL_LOD);
		gSPClearGeometryMode(gdl++, G_CULL_BOTH);
		gDPSetTextureFilter(gdl++, G_TF_BILERP);

		if (g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
			gSPSetGeometryMode(gdl++, G_LIGHTING | G_TEXTURE_GEN);
		}

		gSPMatrix(gdl++, osVirtualToPhysical(currentPlayerGetUnk1758()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

		for (i = 0; i < g_MaxShards; i++) {
			if (g_Shards[i].age60 > 0 && g_Shards[i].type != SHARDTYPE_WOOD) {
				bool render = true;
				f32 alphamult = 1.0f;
				f32 xraydist;
				Mtxf *mtx = gfxAllocateMatrix();
				u32 stack;

				if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
					xraydist = sqrtf(ERASERSQDIST(g_Shards[i].pos.f));

					if (g_Vars.currentplayer->eraserpropdist < xraydist) {
						render = false;
					}

					if (g_Vars.currentplayer->eraserpropdist - 150.0f < xraydist) {
						alphamult = 1.0f - (xraydist - (g_Vars.currentplayer->eraserpropdist - 150.0f)) / 150.0f;
					}

					xraydist = xraydist / g_Vars.currentplayer->eraserpropdist;

					if (xraydist > 1.0f) {
						xraydist = 1.0f;
					}
				}

				if (render) {
					/**
					 * @dangerous: See comment for similar code in shardsRenderWood.
					 */
					func000166a4(
							(struct coord *)((u8 *)g_Shards + i * sizeof(struct shard) + 0x08),
							(struct coord *)((u8 *)g_Shards + i * sizeof(struct shard) + 0x14),
							&shardmtx);

					shardmtx.m[3][0] -= g_Vars.currentplayer->globaldrawworldoffset.x;
					shardmtx.m[3][1] -= g_Vars.currentplayer->globaldrawworldoffset.y;
					shardmtx.m[3][2] -= g_Vars.currentplayer->globaldrawworldoffset.z;

					if (shardmtx.m[3][0] < 10000 && shardmtx.m[3][0] > -10000
							&& shardmtx.m[3][1] < 10000 && shardmtx.m[3][1] > -10000
							&& shardmtx.m[3][2] < 10000 && shardmtx.m[3][2] > -10000) {
						func00016054(&shardmtx, mtx);

						gSPMatrix(gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

						if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
							u8 (*colours)[4] = gfxAllocateColours(3);

							if (g_Shards[i].age60 >= PALDOWN(100)) {
								f32 frac = g_Shards[i].age60 / (PAL ? 41.666664123535f : 50.0f);

								if (frac > 1) {
									frac = 1;
								}

								alphamult = (1.0f - frac) * alphamult;
							}

							alphamult *= 0.5f;

							for (j = 0; j < 3; j++) {
								colours[j][0] = xraydist * 255.0f;
								colours[j][1] = (1.0f - xraydist) * 255.0f;
								colours[j][2] = 0;
								colours[j][3] = g_Shards[g_NextShardNum].colours[j][3] * alphamult;
							}

							gDPSetColorArray(gdl++, osVirtualToPhysical(colours), 3);
						} else {
							if (g_Shards[i].room != prevroom) {
								gdl = func0f001138(gdl, g_Shards[i].room);
								prevroom = g_Shards[i].room;
							}

							gDPSetColorArray(gdl++, osVirtualToPhysical(g_Shards[i].colours), 3);
						}

						gDPSetVerticeArray(gdl++, osVirtualToPhysical(g_Shards[i].vertices), 3);
						gSP1Triangle(gdl++, 0, 1, 2, 0);
					}
				}
			}
		}

		if (prevroom == 0) {
			gdl = func0f001300(gdl);
		}

		gSPClearGeometryMode(gdl++, G_LIGHTING | G_TEXTURE_GEN);
		gSPMatrix(gdl++, currentPlayerGetUnk1750(), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
		gSPMatrix(gdl++, currentPlayerGetUnk173c(), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	}

	return gdl;
}
#else
Gfx *shardsRenderGlass(Gfx *gdl);

GLOBAL_ASM(
glabel shardsRenderGlass
/*  f14c62c:	27bdfec8 */ 	addiu	$sp,$sp,-312
/*  f14c630:	3c0e8008 */ 	lui	$t6,0x8008
/*  f14c634:	8dce22e4 */ 	lw	$t6,0x22e4($t6)
/*  f14c638:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f14c63c:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f14c640:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f14c644:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f14c648:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f14c64c:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f14c650:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f14c654:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f14c658:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f14c65c:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f14c660:	f7bc0048 */ 	sdc1	$f28,0x48($sp)
/*  f14c664:	f7ba0040 */ 	sdc1	$f26,0x40($sp)
/*  f14c668:	f7b80038 */ 	sdc1	$f24,0x38($sp)
/*  f14c66c:	f7b60030 */ 	sdc1	$f22,0x30($sp)
/*  f14c670:	f7b40028 */ 	sdc1	$f20,0x28($sp)
/*  f14c674:	11c001c3 */ 	beqz	$t6,.NB0f14cd84
/*  f14c678:	afa40138 */ 	sw	$a0,0x138($sp)
/*  f14c67c:	3c16800a */ 	lui	$s6,0x800a
/*  f14c680:	26d6e6c0 */ 	addiu	$s6,$s6,-6464
/*  f14c684:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f14c688:	a7a00136 */ 	sh	$zero,0x136($sp)
/*  f14c68c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14c690:	95f80010 */ 	lhu	$t8,0x10($t7)
/*  f14c694:	27a40138 */ 	addiu	$a0,$sp,0x138
/*  f14c698:	3c05800b */ 	lui	$a1,0x800b
/*  f14c69c:	1701000d */ 	bne	$t8,$at,.NB0f14c6d4
/*  f14c6a0:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f14c6a4:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f14c6a8:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f14c6ac:	afa80014 */ 	sw	$t0,0x14($sp)
/*  f14c6b0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f14c6b4:	27a40138 */ 	addiu	$a0,$sp,0x138
/*  f14c6b8:	00002825 */ 	or	$a1,$zero,$zero
/*  f14c6bc:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f14c6c0:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f14c6c4:	0fc2c5c8 */ 	jal	func0f0b39c0
/*  f14c6c8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f14c6cc:	1000000b */ 	beqz	$zero,.NB0f14c6fc
/*  f14c6d0:	8fab0138 */ 	lw	$t3,0x138($sp)
.NB0f14c6d4:
/*  f14c6d4:	8ca5fe40 */ 	lw	$a1,-0x1c0($a1)
/*  f14c6d8:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f14c6dc:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f14c6e0:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f14c6e4:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f14c6e8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f14c6ec:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f14c6f0:	0fc2c5c8 */ 	jal	func0f0b39c0
/*  f14c6f4:	24a5000c */ 	addiu	$a1,$a1,0xc
/*  f14c6f8:	8fab0138 */ 	lw	$t3,0x138($sp)
.NB0f14c6fc:
/*  f14c6fc:	3c0dbb00 */ 	lui	$t5,0xbb00
/*  f14c700:	3c0e0d80 */ 	lui	$t6,0xd80
/*  f14c704:	256c0008 */ 	addiu	$t4,$t3,0x8
/*  f14c708:	afac0138 */ 	sw	$t4,0x138($sp)
/*  f14c70c:	35ce0d80 */ 	ori	$t6,$t6,0xd80
/*  f14c710:	35ad1001 */ 	ori	$t5,$t5,0x1001
/*  f14c714:	ad6d0000 */ 	sw	$t5,0x0($t3)
/*  f14c718:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f14c71c:	8faf0138 */ 	lw	$t7,0x138($sp)
/*  f14c720:	3c19ba00 */ 	lui	$t9,0xba00
/*  f14c724:	37391402 */ 	ori	$t9,$t9,0x1402
/*  f14c728:	25f80008 */ 	addiu	$t8,$t7,0x8
/*  f14c72c:	afb80138 */ 	sw	$t8,0x138($sp)
/*  f14c730:	3c080010 */ 	lui	$t0,0x10
/*  f14c734:	ade80004 */ 	sw	$t0,0x4($t7)
/*  f14c738:	adf90000 */ 	sw	$t9,0x0($t7)
/*  f14c73c:	8fa90138 */ 	lw	$t1,0x138($sp)
/*  f14c740:	3c0bba00 */ 	lui	$t3,0xba00
/*  f14c744:	356b1001 */ 	ori	$t3,$t3,0x1001
/*  f14c748:	252a0008 */ 	addiu	$t2,$t1,0x8
/*  f14c74c:	afaa0138 */ 	sw	$t2,0x138($sp)
/*  f14c750:	3c0c0001 */ 	lui	$t4,0x1
/*  f14c754:	ad2c0004 */ 	sw	$t4,0x4($t1)
/*  f14c758:	ad2b0000 */ 	sw	$t3,0x0($t1)
/*  f14c75c:	8fad0138 */ 	lw	$t5,0x138($sp)
/*  f14c760:	3c0fb600 */ 	lui	$t7,0xb600
/*  f14c764:	24183000 */ 	addiu	$t8,$zero,0x3000
/*  f14c768:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f14c76c:	afae0138 */ 	sw	$t6,0x138($sp)
/*  f14c770:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f14c774:	adaf0000 */ 	sw	$t7,0x0($t5)
/*  f14c778:	8fb90138 */ 	lw	$t9,0x138($sp)
/*  f14c77c:	3c09ba00 */ 	lui	$t1,0xba00
/*  f14c780:	35290c02 */ 	ori	$t1,$t1,0xc02
/*  f14c784:	27280008 */ 	addiu	$t0,$t9,0x8
/*  f14c788:	afa80138 */ 	sw	$t0,0x138($sp)
/*  f14c78c:	240a2000 */ 	addiu	$t2,$zero,0x2000
/*  f14c790:	af2a0004 */ 	sw	$t2,0x4($t9)
/*  f14c794:	af290000 */ 	sw	$t1,0x0($t9)
/*  f14c798:	8ecb0284 */ 	lw	$t3,0x284($s6)
/*  f14c79c:	8fad0138 */ 	lw	$t5,0x138($sp)
/*  f14c7a0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14c7a4:	956c0010 */ 	lhu	$t4,0x10($t3)
/*  f14c7a8:	3c0fb700 */ 	lui	$t7,0xb700
/*  f14c7ac:	3c180006 */ 	lui	$t8,0x6
/*  f14c7b0:	11810004 */ 	beq	$t4,$at,.NB0f14c7c4
/*  f14c7b4:	25ae0008 */ 	addiu	$t6,$t5,0x8
/*  f14c7b8:	afae0138 */ 	sw	$t6,0x138($sp)
/*  f14c7bc:	adb80004 */ 	sw	$t8,0x4($t5)
/*  f14c7c0:	adaf0000 */ 	sw	$t7,0x0($t5)
.NB0f14c7c4:
/*  f14c7c4:	8fb00138 */ 	lw	$s0,0x138($sp)
/*  f14c7c8:	3c090103 */ 	lui	$t1,0x103
/*  f14c7cc:	35290040 */ 	ori	$t1,$t1,0x40
/*  f14c7d0:	26080008 */ 	addiu	$t0,$s0,0x8
/*  f14c7d4:	afa80138 */ 	sw	$t0,0x138($sp)
/*  f14c7d8:	0fc2cb5a */ 	jal	currentPlayerGetUnk1758
/*  f14c7dc:	ae090000 */ 	sw	$t1,0x0($s0)
/*  f14c7e0:	0c013100 */ 	jal	osVirtualToPhysical
/*  f14c7e4:	00402025 */ 	or	$a0,$v0,$zero
/*  f14c7e8:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f14c7ec:	3c0a800b */ 	lui	$t2,0x800b
/*  f14c7f0:	8d4a8d40 */ 	lw	$t2,-0x72c0($t2)
/*  f14c7f4:	0000b825 */ 	or	$s7,$zero,$zero
/*  f14c7f8:	00009825 */ 	or	$s3,$zero,$zero
/*  f14c7fc:	19400144 */ 	blez	$t2,.NB0f14cd10
/*  f14c800:	3c013f80 */ 	lui	$at,0x3f80
/*  f14c804:	4481e000 */ 	mtc1	$at,$f28
/*  f14c808:	3c014316 */ 	lui	$at,0x4316
/*  f14c80c:	4481d000 */ 	mtc1	$at,$f26
/*  f14c810:	3c013f80 */ 	lui	$at,0x3f80
/*  f14c814:	3c148008 */ 	lui	$s4,0x8008
/*  f14c818:	3c12800b */ 	lui	$s2,0x800b
/*  f14c81c:	4481c000 */ 	mtc1	$at,$f24
/*  f14c820:	26528d44 */ 	addiu	$s2,$s2,-29372
/*  f14c824:	269422e0 */ 	addiu	$s4,$s4,0x22e0
/*  f14c828:	c7b600c4 */ 	lwc1	$f22,0xc4($sp)
/*  f14c82c:	27be00f0 */ 	addiu	$s8,$sp,0xf0
/*  f14c830:	2415000c */ 	addiu	$s5,$zero,0xc
/*  f14c834:	8e4b0000 */ 	lw	$t3,0x0($s2)
.NB0f14c838:
/*  f14c838:	01731021 */ 	addu	$v0,$t3,$s3
/*  f14c83c:	8c4c0004 */ 	lw	$t4,0x4($v0)
/*  f14c840:	1980012b */ 	blez	$t4,.NB0f14ccf0
/*  f14c844:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c848:	904d0068 */ 	lbu	$t5,0x68($v0)
/*  f14c84c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f14c850:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f14c854:	11a10126 */ 	beq	$t5,$at,.NB0f14ccf0
/*  f14c858:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c85c:	0fc588b6 */ 	jal	gfxAllocateMatrix
/*  f14c860:	4600c506 */ 	mov.s	$f20,$f24
/*  f14c864:	8ec30284 */ 	lw	$v1,0x284($s6)
/*  f14c868:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14c86c:	00408825 */ 	or	$s1,$v0,$zero
/*  f14c870:	946e0010 */ 	lhu	$t6,0x10($v1)
/*  f14c874:	15c10025 */ 	bne	$t6,$at,.NB0f14c90c
/*  f14c878:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c87c:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f14c880:	c46a0018 */ 	lwc1	$f10,0x18($v1)
/*  f14c884:	c4660020 */ 	lwc1	$f6,0x20($v1)
/*  f14c888:	01f31021 */ 	addu	$v0,$t7,$s3
/*  f14c88c:	c4480008 */ 	lwc1	$f8,0x8($v0)
/*  f14c890:	c4440010 */ 	lwc1	$f4,0x10($v0)
/*  f14c894:	c450000c */ 	lwc1	$f16,0xc($v0)
/*  f14c898:	460a4081 */ 	sub.s	$f2,$f8,$f10
/*  f14c89c:	c472001c */ 	lwc1	$f18,0x1c($v1)
/*  f14c8a0:	46062001 */ 	sub.s	$f0,$f4,$f6
/*  f14c8a4:	46021102 */ 	mul.s	$f4,$f2,$f2
/*  f14c8a8:	46128381 */ 	sub.s	$f14,$f16,$f18
/*  f14c8ac:	460e7182 */ 	mul.s	$f6,$f14,$f14
/*  f14c8b0:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f14c8b4:	46000282 */ 	mul.s	$f10,$f0,$f0
/*  f14c8b8:	0c012e84 */ 	jal	sqrtf
/*  f14c8bc:	46085300 */ 	add.s	$f12,$f10,$f8
/*  f14c8c0:	8ed80284 */ 	lw	$t8,0x284($s6)
/*  f14c8c4:	c7020024 */ 	lwc1	$f2,0x24($t8)
/*  f14c8c8:	4600103c */ 	c.lt.s	$f2,$f0
/*  f14c8cc:	461a1301 */ 	sub.s	$f12,$f2,$f26
/*  f14c8d0:	45000002 */ 	bc1f	.NB0f14c8dc
/*  f14c8d4:	46020583 */ 	div.s	$f22,$f0,$f2
/*  f14c8d8:	00008025 */ 	or	$s0,$zero,$zero
.NB0f14c8dc:
/*  f14c8dc:	4600603c */ 	c.lt.s	$f12,$f0
/*  f14c8e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c8e4:	45020005 */ 	bc1fl	.NB0f14c8fc
/*  f14c8e8:	4616c03c */ 	c.lt.s	$f24,$f22
/*  f14c8ec:	460c0401 */ 	sub.s	$f16,$f0,$f12
/*  f14c8f0:	461a8483 */ 	div.s	$f18,$f16,$f26
/*  f14c8f4:	4612c501 */ 	sub.s	$f20,$f24,$f18
/*  f14c8f8:	4616c03c */ 	c.lt.s	$f24,$f22
.NB0f14c8fc:
/*  f14c8fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c900:	45000002 */ 	bc1f	.NB0f14c90c
/*  f14c904:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c908:	4600c586 */ 	mov.s	$f22,$f24
.NB0f14c90c:
/*  f14c90c:	120000f8 */ 	beqz	$s0,.NB0f14ccf0
/*  f14c910:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c914:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f14c918:	03c03025 */ 	or	$a2,$s8,$zero
/*  f14c91c:	03331021 */ 	addu	$v0,$t9,$s3
/*  f14c920:	24440008 */ 	addiu	$a0,$v0,0x8
/*  f14c924:	0c005d8d */ 	jal	func000166a4
/*  f14c928:	24450014 */ 	addiu	$a1,$v0,0x14
/*  f14c92c:	8ec30284 */ 	lw	$v1,0x284($s6)
/*  f14c930:	c7a40120 */ 	lwc1	$f4,0x120($sp)
/*  f14c934:	c7a80124 */ 	lwc1	$f8,0x124($sp)
/*  f14c938:	c4660038 */ 	lwc1	$f6,0x38($v1)
/*  f14c93c:	03c02025 */ 	or	$a0,$s8,$zero
/*  f14c940:	02202825 */ 	or	$a1,$s1,$zero
/*  f14c944:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f14c948:	c7a40128 */ 	lwc1	$f4,0x128($sp)
/*  f14c94c:	e7aa0120 */ 	swc1	$f10,0x120($sp)
/*  f14c950:	c470003c */ 	lwc1	$f16,0x3c($v1)
/*  f14c954:	46104481 */ 	sub.s	$f18,$f8,$f16
/*  f14c958:	e7b20124 */ 	swc1	$f18,0x124($sp)
/*  f14c95c:	c4660040 */ 	lwc1	$f6,0x40($v1)
/*  f14c960:	46062281 */ 	sub.s	$f10,$f4,$f6
/*  f14c964:	0c005bd1 */ 	jal	func00016054
/*  f14c968:	e7aa0128 */ 	swc1	$f10,0x128($sp)
/*  f14c96c:	8fb00138 */ 	lw	$s0,0x138($sp)
/*  f14c970:	3c0a0102 */ 	lui	$t2,0x102
/*  f14c974:	354a0040 */ 	ori	$t2,$t2,0x40
/*  f14c978:	26090008 */ 	addiu	$t1,$s0,0x8
/*  f14c97c:	afa90138 */ 	sw	$t1,0x138($sp)
/*  f14c980:	02202025 */ 	or	$a0,$s1,$zero
/*  f14c984:	0c013100 */ 	jal	osVirtualToPhysical
/*  f14c988:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f14c98c:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f14c990:	8ecb0284 */ 	lw	$t3,0x284($s6)
/*  f14c994:	24010001 */ 	addiu	$at,$zero,0x1
/*  f14c998:	956c0010 */ 	lhu	$t4,0x10($t3)
/*  f14c99c:	158100aa */ 	bne	$t4,$at,.NB0f14cc48
/*  f14c9a0:	3c01437f */ 	lui	$at,0x437f
/*  f14c9a4:	44814000 */ 	mtc1	$at,$f8
/*  f14c9a8:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f14c9ac:	3c014f00 */ 	lui	$at,0x4f00
/*  f14c9b0:	4608b402 */ 	mul.s	$f16,$f22,$f8
/*  f14c9b4:	24040003 */ 	addiu	$a0,$zero,0x3
/*  f14c9b8:	444df800 */ 	cfc1	$t5,$31
/*  f14c9bc:	44d0f800 */ 	ctc1	$s0,$31
/*  f14c9c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c9c4:	460084a4 */ 	cvt.w.s	$f18,$f16
/*  f14c9c8:	4450f800 */ 	cfc1	$s0,$31
/*  f14c9cc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c9d0:	32100078 */ 	andi	$s0,$s0,0x78
/*  f14c9d4:	52000013 */ 	beqzl	$s0,.NB0f14ca24
/*  f14c9d8:	44109000 */ 	mfc1	$s0,$f18
/*  f14c9dc:	44819000 */ 	mtc1	$at,$f18
/*  f14c9e0:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f14c9e4:	46128481 */ 	sub.s	$f18,$f16,$f18
/*  f14c9e8:	44d0f800 */ 	ctc1	$s0,$31
/*  f14c9ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c9f0:	460094a4 */ 	cvt.w.s	$f18,$f18
/*  f14c9f4:	4450f800 */ 	cfc1	$s0,$31
/*  f14c9f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14c9fc:	32100078 */ 	andi	$s0,$s0,0x78
/*  f14ca00:	16000005 */ 	bnez	$s0,.NB0f14ca18
/*  f14ca04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14ca08:	44109000 */ 	mfc1	$s0,$f18
/*  f14ca0c:	3c018000 */ 	lui	$at,0x8000
/*  f14ca10:	10000007 */ 	beqz	$zero,.NB0f14ca30
/*  f14ca14:	02018025 */ 	or	$s0,$s0,$at
.NB0f14ca18:
/*  f14ca18:	10000005 */ 	beqz	$zero,.NB0f14ca30
/*  f14ca1c:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f14ca20:	44109000 */ 	mfc1	$s0,$f18
.NB0f14ca24:
/*  f14ca24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14ca28:	0600fffb */ 	bltz	$s0,.NB0f14ca18
/*  f14ca2c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f14ca30:
/*  f14ca30:	44cdf800 */ 	ctc1	$t5,$31
/*  f14ca34:	3c01437f */ 	lui	$at,0x437f
/*  f14ca38:	44813000 */ 	mtc1	$at,$f6
/*  f14ca3c:	4616c101 */ 	sub.s	$f4,$f24,$f22
/*  f14ca40:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f14ca44:	3c014f00 */ 	lui	$at,0x4f00
/*  f14ca48:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f14ca4c:	444ef800 */ 	cfc1	$t6,$31
/*  f14ca50:	44d1f800 */ 	ctc1	$s1,$31
/*  f14ca54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14ca58:	46005224 */ 	cvt.w.s	$f8,$f10
/*  f14ca5c:	4451f800 */ 	cfc1	$s1,$31
/*  f14ca60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14ca64:	32310078 */ 	andi	$s1,$s1,0x78
/*  f14ca68:	52200013 */ 	beqzl	$s1,.NB0f14cab8
/*  f14ca6c:	44114000 */ 	mfc1	$s1,$f8
/*  f14ca70:	44814000 */ 	mtc1	$at,$f8
/*  f14ca74:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f14ca78:	46085201 */ 	sub.s	$f8,$f10,$f8
/*  f14ca7c:	44d1f800 */ 	ctc1	$s1,$31
/*  f14ca80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14ca84:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f14ca88:	4451f800 */ 	cfc1	$s1,$31
/*  f14ca8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14ca90:	32310078 */ 	andi	$s1,$s1,0x78
/*  f14ca94:	16200005 */ 	bnez	$s1,.NB0f14caac
/*  f14ca98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14ca9c:	44114000 */ 	mfc1	$s1,$f8
/*  f14caa0:	3c018000 */ 	lui	$at,0x8000
/*  f14caa4:	10000007 */ 	beqz	$zero,.NB0f14cac4
/*  f14caa8:	02218825 */ 	or	$s1,$s1,$at
.NB0f14caac:
/*  f14caac:	10000005 */ 	beqz	$zero,.NB0f14cac4
/*  f14cab0:	2411ffff */ 	addiu	$s1,$zero,-1
/*  f14cab4:	44114000 */ 	mfc1	$s1,$f8
.NB0f14cab8:
/*  f14cab8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14cabc:	0620fffb */ 	bltz	$s1,.NB0f14caac
/*  f14cac0:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f14cac4:
/*  f14cac4:	44cef800 */ 	ctc1	$t6,$31
/*  f14cac8:	0fc588c3 */ 	jal	gfxAllocateColours
/*  f14cacc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14cad0:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f14cad4:	00403025 */ 	or	$a2,$v0,$zero
/*  f14cad8:	01f3c021 */ 	addu	$t8,$t7,$s3
/*  f14cadc:	8f030004 */ 	lw	$v1,0x4($t8)
/*  f14cae0:	28610064 */ 	slti	$at,$v1,0x64
/*  f14cae4:	5420000f */ 	bnezl	$at,.NB0f14cb24
/*  f14cae8:	3c013f00 */ 	lui	$at,0x3f00
/*  f14caec:	44838000 */ 	mtc1	$v1,$f16
/*  f14caf0:	3c014248 */ 	lui	$at,0x4248
/*  f14caf4:	44812000 */ 	mtc1	$at,$f4
/*  f14caf8:	468084a0 */ 	cvt.s.w	$f18,$f16
/*  f14cafc:	46049003 */ 	div.s	$f0,$f18,$f4
/*  f14cb00:	4600e03c */ 	c.lt.s	$f28,$f0
/*  f14cb04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14cb08:	45020003 */ 	bc1fl	.NB0f14cb18
/*  f14cb0c:	4600c181 */ 	sub.s	$f6,$f24,$f0
/*  f14cb10:	4600e006 */ 	mov.s	$f0,$f28
/*  f14cb14:	4600c181 */ 	sub.s	$f6,$f24,$f0
.NB0f14cb18:
/*  f14cb18:	46143502 */ 	mul.s	$f20,$f6,$f20
/*  f14cb1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14cb20:	3c013f00 */ 	lui	$at,0x3f00
.NB0f14cb24:
/*  f14cb24:	44815000 */ 	mtc1	$at,$f10
/*  f14cb28:	00002025 */ 	or	$a0,$zero,$zero
/*  f14cb2c:	00401825 */ 	or	$v1,$v0,$zero
/*  f14cb30:	460aa502 */ 	mul.s	$f20,$f20,$f10
/*  f14cb34:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f14cb38:
/*  f14cb38:	a0700000 */ 	sb	$s0,0x0($v1)
/*  f14cb3c:	a0710001 */ 	sb	$s1,0x1($v1)
/*  f14cb40:	a0600002 */ 	sb	$zero,0x2($v1)
/*  f14cb44:	8e880000 */ 	lw	$t0,0x0($s4)
/*  f14cb48:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f14cb4c:	3c014f80 */ 	lui	$at,0x4f80
/*  f14cb50:	000848c0 */ 	sll	$t1,$t0,0x3
/*  f14cb54:	01284823 */ 	subu	$t1,$t1,$t0
/*  f14cb58:	00094880 */ 	sll	$t1,$t1,0x2
/*  f14cb5c:	01284823 */ 	subu	$t1,$t1,$t0
/*  f14cb60:	00094880 */ 	sll	$t1,$t1,0x2
/*  f14cb64:	03295021 */ 	addu	$t2,$t9,$t1
/*  f14cb68:	01445821 */ 	addu	$t3,$t2,$a0
/*  f14cb6c:	916c005f */ 	lbu	$t4,0x5f($t3)
/*  f14cb70:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f14cb74:	448c4000 */ 	mtc1	$t4,$f8
/*  f14cb78:	05810004 */ 	bgez	$t4,.NB0f14cb8c
/*  f14cb7c:	46804420 */ 	cvt.s.w	$f16,$f8
/*  f14cb80:	44819000 */ 	mtc1	$at,$f18
/*  f14cb84:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14cb88:	46128400 */ 	add.s	$f16,$f16,$f18
.NB0f14cb8c:
/*  f14cb8c:	46148102 */ 	mul.s	$f4,$f16,$f20
/*  f14cb90:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f14cb94:	3c014f00 */ 	lui	$at,0x4f00
/*  f14cb98:	444df800 */ 	cfc1	$t5,$31
/*  f14cb9c:	44cef800 */ 	ctc1	$t6,$31
/*  f14cba0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14cba4:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f14cba8:	444ef800 */ 	cfc1	$t6,$31
/*  f14cbac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14cbb0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f14cbb4:	51c00013 */ 	beqzl	$t6,.NB0f14cc04
/*  f14cbb8:	440e3000 */ 	mfc1	$t6,$f6
/*  f14cbbc:	44813000 */ 	mtc1	$at,$f6
/*  f14cbc0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f14cbc4:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f14cbc8:	44cef800 */ 	ctc1	$t6,$31
/*  f14cbcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14cbd0:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f14cbd4:	444ef800 */ 	cfc1	$t6,$31
/*  f14cbd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14cbdc:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f14cbe0:	15c00005 */ 	bnez	$t6,.NB0f14cbf8
/*  f14cbe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14cbe8:	440e3000 */ 	mfc1	$t6,$f6
/*  f14cbec:	3c018000 */ 	lui	$at,0x8000
/*  f14cbf0:	10000007 */ 	beqz	$zero,.NB0f14cc10
/*  f14cbf4:	01c17025 */ 	or	$t6,$t6,$at
.NB0f14cbf8:
/*  f14cbf8:	10000005 */ 	beqz	$zero,.NB0f14cc10
/*  f14cbfc:	240effff */ 	addiu	$t6,$zero,-1
/*  f14cc00:	440e3000 */ 	mfc1	$t6,$f6
.NB0f14cc04:
/*  f14cc04:	00000000 */ 	sll	$zero,$zero,0x0
/*  f14cc08:	05c0fffb */ 	bltz	$t6,.NB0f14cbf8
/*  f14cc0c:	00000000 */ 	sll	$zero,$zero,0x0
.NB0f14cc10:
/*  f14cc10:	44cdf800 */ 	ctc1	$t5,$31
/*  f14cc14:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f14cc18:	1495ffc7 */ 	bne	$a0,$s5,.NB0f14cb38
/*  f14cc1c:	a06effff */ 	sb	$t6,-0x1($v1)
/*  f14cc20:	8fb00138 */ 	lw	$s0,0x138($sp)
/*  f14cc24:	3c080708 */ 	lui	$t0,0x708
/*  f14cc28:	3508000c */ 	ori	$t0,$t0,0xc
/*  f14cc2c:	26180008 */ 	addiu	$t8,$s0,0x8
/*  f14cc30:	afb80138 */ 	sw	$t8,0x138($sp)
/*  f14cc34:	00c02025 */ 	or	$a0,$a2,$zero
/*  f14cc38:	0c013100 */ 	jal	osVirtualToPhysical
/*  f14cc3c:	ae080000 */ 	sw	$t0,0x0($s0)
/*  f14cc40:	10000019 */ 	beqz	$zero,.NB0f14cca8
/*  f14cc44:	ae020004 */ 	sw	$v0,0x4($s0)
.NB0f14cc48:
/*  f14cc48:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f14cc4c:	87aa0136 */ 	lh	$t2,0x136($sp)
/*  f14cc50:	03334821 */ 	addu	$t1,$t9,$s3
/*  f14cc54:	85250000 */ 	lh	$a1,0x0($t1)
/*  f14cc58:	51450009 */ 	beql	$t2,$a1,.NB0f14cc80
/*  f14cc5c:	8fb00138 */ 	lw	$s0,0x138($sp)
/*  f14cc60:	0fc0044e */ 	jal	func0f001138
/*  f14cc64:	8fa40138 */ 	lw	$a0,0x138($sp)
/*  f14cc68:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f14cc6c:	afa20138 */ 	sw	$v0,0x138($sp)
/*  f14cc70:	01736021 */ 	addu	$t4,$t3,$s3
/*  f14cc74:	858d0000 */ 	lh	$t5,0x0($t4)
/*  f14cc78:	a7ad0136 */ 	sh	$t5,0x136($sp)
/*  f14cc7c:	8fb00138 */ 	lw	$s0,0x138($sp)
.NB0f14cc80:
/*  f14cc80:	3c180708 */ 	lui	$t8,0x708
/*  f14cc84:	3718000c */ 	ori	$t8,$t8,0xc
/*  f14cc88:	260f0008 */ 	addiu	$t7,$s0,0x8
/*  f14cc8c:	afaf0138 */ 	sw	$t7,0x138($sp)
/*  f14cc90:	ae180000 */ 	sw	$t8,0x0($s0)
/*  f14cc94:	8e480000 */ 	lw	$t0,0x0($s2)
/*  f14cc98:	01132021 */ 	addu	$a0,$t0,$s3
/*  f14cc9c:	0c013100 */ 	jal	osVirtualToPhysical
/*  f14cca0:	2484005c */ 	addiu	$a0,$a0,0x5c
/*  f14cca4:	ae020004 */ 	sw	$v0,0x4($s0)
.NB0f14cca8:
/*  f14cca8:	8fb00138 */ 	lw	$s0,0x138($sp)
/*  f14ccac:	3c0a0420 */ 	lui	$t2,0x420
/*  f14ccb0:	354a0024 */ 	ori	$t2,$t2,0x24
/*  f14ccb4:	26090008 */ 	addiu	$t1,$s0,0x8
/*  f14ccb8:	afa90138 */ 	sw	$t1,0x138($sp)
/*  f14ccbc:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f14ccc0:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f14ccc4:	01732021 */ 	addu	$a0,$t3,$s3
/*  f14ccc8:	0c013100 */ 	jal	osVirtualToPhysical
/*  f14cccc:	24840038 */ 	addiu	$a0,$a0,0x38
/*  f14ccd0:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f14ccd4:	8fac0138 */ 	lw	$t4,0x138($sp)
/*  f14ccd8:	3c0ebf00 */ 	lui	$t6,0xbf00
/*  f14ccdc:	240f0a14 */ 	addiu	$t7,$zero,0xa14
/*  f14cce0:	258d0008 */ 	addiu	$t5,$t4,0x8
/*  f14cce4:	afad0138 */ 	sw	$t5,0x138($sp)
/*  f14cce8:	ad8f0004 */ 	sw	$t7,0x4($t4)
/*  f14ccec:	ad8e0000 */ 	sw	$t6,0x0($t4)
.NB0f14ccf0:
/*  f14ccf0:	3c18800b */ 	lui	$t8,0x800b
/*  f14ccf4:	8f188d40 */ 	lw	$t8,-0x72c0($t8)
/*  f14ccf8:	26f70001 */ 	addiu	$s7,$s7,0x1
/*  f14ccfc:	2673006c */ 	addiu	$s3,$s3,0x6c
/*  f14cd00:	02f8082a */ 	slt	$at,$s7,$t8
/*  f14cd04:	5420fecc */ 	bnezl	$at,.NB0f14c838
/*  f14cd08:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f14cd0c:	e7b600c4 */ 	swc1	$f22,0xc4($sp)
.NB0f14cd10:
/*  f14cd10:	87a80136 */ 	lh	$t0,0x136($sp)
/*  f14cd14:	55000005 */ 	bnezl	$t0,.NB0f14cd2c
/*  f14cd18:	8fb90138 */ 	lw	$t9,0x138($sp)
/*  f14cd1c:	0fc004c0 */ 	jal	func0f001300
/*  f14cd20:	8fa40138 */ 	lw	$a0,0x138($sp)
/*  f14cd24:	afa20138 */ 	sw	$v0,0x138($sp)
/*  f14cd28:	8fb90138 */ 	lw	$t9,0x138($sp)
.NB0f14cd2c:
/*  f14cd2c:	3c0ab600 */ 	lui	$t2,0xb600
/*  f14cd30:	3c0b0006 */ 	lui	$t3,0x6
/*  f14cd34:	27290008 */ 	addiu	$t1,$t9,0x8
/*  f14cd38:	afa90138 */ 	sw	$t1,0x138($sp)
/*  f14cd3c:	af2b0004 */ 	sw	$t3,0x4($t9)
/*  f14cd40:	af2a0000 */ 	sw	$t2,0x0($t9)
/*  f14cd44:	8fb00138 */ 	lw	$s0,0x138($sp)
/*  f14cd48:	3c0e0103 */ 	lui	$t6,0x103
/*  f14cd4c:	35ce0040 */ 	ori	$t6,$t6,0x40
/*  f14cd50:	260d0008 */ 	addiu	$t5,$s0,0x8
/*  f14cd54:	afad0138 */ 	sw	$t5,0x138($sp)
/*  f14cd58:	0fc2cb52 */ 	jal	currentPlayerGetUnk1750
/*  f14cd5c:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f14cd60:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f14cd64:	8fb10138 */ 	lw	$s1,0x138($sp)
/*  f14cd68:	3c080102 */ 	lui	$t0,0x102
/*  f14cd6c:	35080040 */ 	ori	$t0,$t0,0x40
/*  f14cd70:	26380008 */ 	addiu	$t8,$s1,0x8
/*  f14cd74:	afb80138 */ 	sw	$t8,0x138($sp)
/*  f14cd78:	0fc2cb42 */ 	jal	currentPlayerGetUnk173c
/*  f14cd7c:	ae280000 */ 	sw	$t0,0x0($s1)
/*  f14cd80:	ae220004 */ 	sw	$v0,0x4($s1)
.NB0f14cd84:
/*  f14cd84:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f14cd88:	8fa20138 */ 	lw	$v0,0x138($sp)
/*  f14cd8c:	d7b40028 */ 	ldc1	$f20,0x28($sp)
/*  f14cd90:	d7b60030 */ 	ldc1	$f22,0x30($sp)
/*  f14cd94:	d7b80038 */ 	ldc1	$f24,0x38($sp)
/*  f14cd98:	d7ba0040 */ 	ldc1	$f26,0x40($sp)
/*  f14cd9c:	d7bc0048 */ 	ldc1	$f28,0x48($sp)
/*  f14cda0:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f14cda4:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f14cda8:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f14cdac:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f14cdb0:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f14cdb4:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f14cdb8:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f14cdbc:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f14cdc0:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f14cdc4:	03e00008 */ 	jr	$ra
/*  f14cdc8:	27bd0138 */ 	addiu	$sp,$sp,0x138
);
#endif

Gfx *shardsRender(Gfx *gdl)
{
	gdl = shardsRenderWood(gdl);
	gdl = shardsRenderGlass(gdl);

	return gdl;
}
