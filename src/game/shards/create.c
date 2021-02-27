#include <ultra64.h>
#include "constants.h"
#include "game/dlights.h"
#include "game/game_092610.h"
#include "game/atan2f.h"
#include "game/game_0b3350.h"
#include "game/file.h"
#include "gvars/gvars.h"
#include "lib/rng.h"
#include "lib/lib_159b0.h"
#include "lib/lib_16110.h"
#include "data.h"
#include "types.h"

s32 g_MaxShards;
struct shard *g_Shards;

s32 g_NextShardNum = 0;
bool g_ShardsActive = false;

void shardCreate(s16 room, struct coord *pos, f32 rotx, f32 size, s32 type);

void shardsCreate(struct coord *pos, f32 *rotx, f32 *roty, f32 *rotz, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 type, struct prop *prop)
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

	arg4 *= f0;
	arg5 *= f0;

	spc0[0] = roty[0];
	spc0[1] = roty[1];
	spc0[2] = roty[2];

	f0 = sqrtf(spc0[0] * spc0[0] + spc0[1] * spc0[1] + spc0[2] * spc0[2]);

	spc0[0] *= 1.0f / f0;
	spc0[1] *= 1.0f / f0;
	spc0[2] *= 1.0f / f0;

	arg6 *= f0;
	arg7 *= f0;

	f30 = atan2f(rotz[0], rotz[2]);

	f20 = arg5 - arg4;
	spac = arg7 - arg6;

	spec = sqrtf(f20 * spac / (f32) (g_MaxShards / 2));
	speci = spec;
	speci2 = speci;

	basepos.x = (pos->f[0] + (arg4 + (speci >> 1)) * spcc[0]) + spc0[0] * (arg6 + (speci >> 1));
	basepos.y = (pos->f[1] + (arg4 + (speci >> 1)) * spcc[1]) + spc0[1] * (arg6 + (speci >> 1));
	basepos.z = (pos->f[2] + (arg4 + (speci >> 1)) * spcc[2]) + spc0[2] * (arg6 + (speci >> 1));

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

	g_Shards[g_NextShardNum].vel.x = velx * 1.5f;
	g_Shards[g_NextShardNum].vel.y = vely * 3.0f;
	g_Shards[g_NextShardNum].vel.z = velz * 1.5f;

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

	g_Shards[g_NextShardNum].rotspeed.x = random() * (1.0f / U32_MAX) * 0.1f;
	g_Shards[g_NextShardNum].rotspeed.y = random() * (1.0f / U32_MAX) * 0.1f;
	g_Shards[g_NextShardNum].rotspeed.z = random() * (1.0f / U32_MAX) * 0.1f;

	g_NextShardNum++;

	if (g_NextShardNum >= g_MaxShards) {
		g_NextShardNum = 0;
	}

	if (!g_ShardsActive) {
		g_ShardsActive = true;
	}
}
