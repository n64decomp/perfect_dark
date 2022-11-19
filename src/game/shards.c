#include <ultra64.h>
#include "constants.h"
#include "data.h"
#include "game/atan2f.h"
#include "game/dlights.h"
#include "game/file.h"
#include "game/propsnd.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/gfxmemory.h"
#include "bss.h"
#include "lib/mtx.h"
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
		propsnd0f0939f8(NULL, NULL, SFX_GLASS_SHATTER, -1,
				-1, 0, 0, 0, &prop->pos, -1.0f, prop->rooms, -1, -1.0f, -1.0f, -1.0f);
	} else if (type == SHARDTYPE_BOTTLE) {
		/**
		 * @bug: This attempts to play one of two bottle breaking sounds
		 * randomly, but one of the SFX IDs isn't valid. This is why on Villa
		 * when you shoot the bottles, half of them don't play any breaking
		 * sound effect.
		 */
		propsnd0f0939f8(NULL, NULL, SFX_BOTTLE_BREAK + (random() % 2) * 2, -1,
				-1, 0, 0, 0, &prop->pos, -1.0f, prop->rooms, -1, -1.0f, -1.0f, -1.0f);
	} else if (type == SHARDTYPE_WOOD) {
		propsnd0f0939f8(NULL, NULL, SFX_WOOD_BREAK, -1,
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

			shardCreate(prop->rooms[0], &thispos, f30, (RANDOMFRAC() * 0.7f + 0.1f) * spec, type);
		}
	}
}

void shardCreate(s16 room, struct coord *pos, f32 rotx, f32 size, s32 type)
{
	f32 velx = RANDOMFRAC() * 2.0f - 1.0f;
	f32 vely = RANDOMFRAC() * 1.12f - 0.12f;
	f32 velz = RANDOMFRAC() * 2.0f - 1.0f;
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

	g_Shards[g_NextShardNum].vertices[0].x = (RANDOMFRAC() * 0.5f + 1.0f) * size;
	g_Shards[g_NextShardNum].vertices[0].y = (RANDOMFRAC() * 0.5f + 1.0f) * size;
	g_Shards[g_NextShardNum].vertices[1].x = (RANDOMFRAC() * 0.5f + 1.0f) * size;
	g_Shards[g_NextShardNum].vertices[1].y = (RANDOMFRAC() * 0.5f + 1.0f) * -size;
	g_Shards[g_NextShardNum].vertices[2].x = (RANDOMFRAC() * 0.5f + 1.0f) * -size;
	g_Shards[g_NextShardNum].vertices[2].y = (RANDOMFRAC() * 0.5f + 1.0f) * -size;

	for (i = 0; i < 3; i++) {
		g_Shards[g_NextShardNum].vertices[i].z = 0;
		g_Shards[g_NextShardNum].vertices[i].s = 0;
		g_Shards[g_NextShardNum].vertices[i].t = 0;
		g_Shards[g_NextShardNum].vertices[i].colour = i * 4;
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
	g_Shards[g_NextShardNum].rot.z = RANDOMFRAC() * M_BADTAU;

	g_Shards[g_NextShardNum].rotspeed.x = RANDOMFRAC() * PALUPF(0.1f);
	g_Shards[g_NextShardNum].rotspeed.y = RANDOMFRAC() * PALUPF(0.1f);
	g_Shards[g_NextShardNum].rotspeed.z = RANDOMFRAC() * PALUPF(0.1f);

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
		gSPMatrix(gdl++, osVirtualToPhysical(camGetOrthogonalMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

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
					struct shard *shard = (struct shard *) ((u8 *)g_Shards + i * sizeof(struct shard));

					mtx4LoadRotationAndTranslation(&shard->pos, &shard->rot, &shardmtx);

					shardmtx.m[3][0] -= g_Vars.currentplayer->globaldrawworldoffset.x;
					shardmtx.m[3][1] -= g_Vars.currentplayer->globaldrawworldoffset.y;
					shardmtx.m[3][2] -= g_Vars.currentplayer->globaldrawworldoffset.z;

					if (shardmtx.m[3][0] < 10000 && shardmtx.m[3][0] > -10000
							&& shardmtx.m[3][1] < 10000 && shardmtx.m[3][1] > -10000
							&& shardmtx.m[3][2] < 10000 && shardmtx.m[3][2] > -10000) {
						mtx00016054(&shardmtx, mtx);

						gSPMatrix(gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

						if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
							u8 (*colours)[4] = gfxAllocateColours(3);

							if (g_Shards[i].age60 >= TICKS(100)) {
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
								gdl = lightsSetForRoom(gdl, g_Shards[i].room);
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
			gdl = lightsSetDefault(gdl);
		}

		gSPClearGeometryMode(gdl++, G_LIGHTING | G_TEXTURE_GEN);
		gSPMatrix(gdl++, camGetPerspectiveMtxL(), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
		gSPMatrix(gdl++, camGetMtxL173c(), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
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
/*  f14c05c:	0fc2cb5a */ 	jal	camGetOrthogonalMtxL
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
/*  f14c1a4:	0c005d8d */ 	jal	mtx4LoadRotationAndTranslation
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
/*  f14c1e4:	0c005bd1 */ 	jal	mtx00016054
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
/*  f14c4d8:	0fc0044e */ 	jal	lightsSetForRoom
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
/*  f14c588:	0fc004c0 */ 	jal	lightsSetDefault
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
/*  f14c5bc:	0fc2cb52 */ 	jal	camGetPerspectiveMtxL
/*  f14c5c0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f14c5c4:	3c090102 */ 	lui	$t1,0x102
/*  f14c5c8:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f14c5cc:	35290040 */ 	ori	$t1,$t1,0x40
/*  f14c5d0:	02608825 */ 	or	$s1,$s3,$zero
/*  f14c5d4:	ae290000 */ 	sw	$t1,0x0($s1)
/*  f14c5d8:	0fc2cb42 */ 	jal	camGetMtxL173c
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

Gfx *shardsRenderGlass(Gfx *gdl)
{
	if (g_ShardsActive) {
		s16 prevroom = 0;
		s32 i;
		Mtxf shardmtx;
		s32 j;

		if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
			texSelect(&gdl, NULL, 2, 1, 2, 1, NULL);
		} else {
			texSelect(&gdl, &g_TexShardConfigs[1], 2, 1, 2, 1, NULL);
		}

		gSPTexture(gdl++, 0x0d80, 0x0d80, 2, G_TX_RENDERTILE, G_ON);
		gDPSetCycleType(gdl++, G_CYC_2CYCLE);
		gDPSetTextureLOD(gdl++, G_TL_LOD);
		gSPClearGeometryMode(gdl++, G_CULL_BOTH);
		gDPSetTextureFilter(gdl++, G_TF_BILERP);

		if (g_Vars.currentplayer->visionmode != VISIONMODE_XRAY) {
			gSPSetGeometryMode(gdl++, G_LIGHTING | G_TEXTURE_GEN);
		}

		gSPMatrix(gdl++, osVirtualToPhysical(camGetOrthogonalMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

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
					struct shard *shard = (struct shard *) ((u8 *)g_Shards + i * sizeof(struct shard));

					mtx4LoadRotationAndTranslation(&shard->pos, &shard->rot, &shardmtx);

					shardmtx.m[3][0] -= g_Vars.currentplayer->globaldrawworldoffset.x;
					shardmtx.m[3][1] -= g_Vars.currentplayer->globaldrawworldoffset.y;
					shardmtx.m[3][2] -= g_Vars.currentplayer->globaldrawworldoffset.z;

#if VERSION >= VERSION_NTSC_1_0
					if (shardmtx.m[3][0] < 10000 && shardmtx.m[3][0] > -10000
							&& shardmtx.m[3][1] < 10000 && shardmtx.m[3][1] > -10000
							&& shardmtx.m[3][2] < 10000 && shardmtx.m[3][2] > -10000)
#endif
					{
						mtx00016054(&shardmtx, mtx);

						gSPMatrix(gdl++, osVirtualToPhysical(mtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

						if (g_Vars.currentplayer->visionmode == VISIONMODE_XRAY) {
							u8 (*colours)[4] = gfxAllocateColours(3);

							if (g_Shards[i].age60 >= TICKS(100)) {
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
								gdl = lightsSetForRoom(gdl, g_Shards[i].room);
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
			gdl = lightsSetDefault(gdl);
		}

		gSPClearGeometryMode(gdl++, G_LIGHTING | G_TEXTURE_GEN);
		gSPMatrix(gdl++, camGetPerspectiveMtxL(), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
		gSPMatrix(gdl++, camGetMtxL173c(), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
	}

	return gdl;
}

Gfx *shardsRender(Gfx *gdl)
{
	gdl = shardsRenderWood(gdl);
	gdl = shardsRenderGlass(gdl);

	return gdl;
}
