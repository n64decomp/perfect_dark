#include <ultra64.h>
#include "constants.h"
#include "game/debug.h"
#include "game/game_006900.h"
#include "game/propsnd.h"
#include "game/bg.h"
#include "bss.h"
#include "lib/model.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

s32 g_FootstepSounds[] = {
	/* none   */ -1,                   -1,                   -1,                   -1,                   -1,                   -1,                   -1,                   -1,
	/* wood   */ SFXMAP_80DC_FOOTSTEP, SFXMAP_80DD_FOOTSTEP, SFXMAP_80E0_FOOTSTEP, SFXMAP_80E1_FOOTSTEP, SFXMAP_80DE_FOOTSTEP, SFXMAP_80DF_FOOTSTEP, SFXMAP_80E2_FOOTSTEP, SFXMAP_80E3_FOOTSTEP,
	/* stone  */ SFXMAP_80C4_FOOTSTEP, SFXMAP_80C5_FOOTSTEP, SFXMAP_80C8_FOOTSTEP, SFXMAP_80C9_FOOTSTEP, SFXMAP_80C6_FOOTSTEP, SFXMAP_80C7_FOOTSTEP, SFXMAP_80CA_FOOTSTEP, SFXMAP_80CB_FOOTSTEP,
	/* carpet */ SFXMAP_80E6_FOOTSTEP, SFXMAP_80E7_FOOTSTEP, SFXMAP_80EA_FOOTSTEP, SFXMAP_80EB_FOOTSTEP, SFXMAP_80E8_FOOTSTEP, SFXMAP_80E9_FOOTSTEP, SFXMAP_80EC_FOOTSTEP, SFXMAP_80ED_FOOTSTEP,
	/* metal  */ SFXMAP_80D4_FOOTSTEP, SFXMAP_80D5_FOOTSTEP, SFXMAP_80D8_FOOTSTEP, SFXMAP_80D9_FOOTSTEP, SFXMAP_80D6_FOOTSTEP, SFXMAP_80D7_FOOTSTEP, SFXMAP_80DA_FOOTSTEP, SFXMAP_80DB_FOOTSTEP,
	/* mud    */ SFXMAP_80EE_FOOTSTEP, SFXMAP_80EF_FOOTSTEP, SFXMAP_80F2_FOOTSTEP, SFXMAP_80F3_FOOTSTEP, SFXMAP_80F0_FOOTSTEP, SFXMAP_80F1_FOOTSTEP, SFXMAP_80F4_FOOTSTEP, SFXMAP_80F5_FOOTSTEP,
	/* water  */ SFXMAP_80E4_FOOTSTEP, SFXMAP_80E5_FOOTSTEP, SFXMAP_80E4_FOOTSTEP, SFXMAP_80E5_FOOTSTEP, SFXMAP_80E4_FOOTSTEP, SFXMAP_80E5_FOOTSTEP, SFXMAP_80E4_FOOTSTEP, SFXMAP_80E5_FOOTSTEP,
	/* dirt   */ SFXMAP_80CC_FOOTSTEP, SFXMAP_80CD_FOOTSTEP, SFXMAP_80D0_FOOTSTEP, SFXMAP_80D1_FOOTSTEP, SFXMAP_80CE_FOOTSTEP, SFXMAP_80CF_FOOTSTEP, SFXMAP_80D2_FOOTSTEP, SFXMAP_80D3_FOOTSTEP,
	/* snow   */ SFXMAP_8187_FOOTSTEP, SFXMAP_8188_FOOTSTEP, SFXMAP_818B_FOOTSTEP, SFXMAP_818C_FOOTSTEP, SFXMAP_8189_FOOTSTEP, SFXMAP_818A_FOOTSTEP, SFXMAP_818D_FOOTSTEP, SFXMAP_818E_FOOTSTEP,
};

struct footstepframe {
	u16 animnum;
	u8 frame1;
	u8 frame2;
};

struct footstepframe g_FootstepAnims[] = {
	{ ANIM_002B,               8,  25 },
	{ ANIM_0029,               5,  14 },
	{ ANIM_006B,               8,  25 },
	{ ANIM_0028,               27, 8  },
	{ ANIM_RUNNING_TWOHANDGUN, 18, 6  },
	{ ANIM_0052,               8,  25 },
	{ ANIM_0053,               25, 8  },
	{ ANIM_0054,               25, 8  },
	{ ANIM_0055,               7,  18 },
	{ ANIM_0056,               7,  18 },
	{ ANIM_0057,               18, 7  },
	{ ANIM_0058,               15, 5  },
	{ ANIM_RUNNING_ONEHANDGUN, 8,  20 },
	{ ANIM_005A,               6,  15 },
	{ ANIM_006C,               25, 8  },
	{ ANIM_006D,               25, 8  },
	{ ANIM_006E,               8,  19 },
	{ ANIM_006F,               21, 8  },
	{ ANIM_0070,               15, 5  },
	{ ANIM_0071,               15, 5  },
	{ ANIM_0072,               23, 8  },
	{ ANIM_0073,               8,  19 },
	{ ANIM_0093,               23, 10 },
	{ ANIM_0094,               15, 5  },
	{ ANIM_005F,               14, 1  },
	{ ANIM_0016,               29, 10 },
	{ ANIM_0018,               24, 46 },
	{ ANIM_001B,               10, 28 },
	{ ANIM_001D,               13, 2  },
	{ ANIM_001E,               12, 1  },
	{ ANIM_005C,               19, 42 },
	{ ANIM_005D,               15, 5  },
	{ ANIM_005E,               4,  12 },
	{ ANIM_0392,               5,  20 },
	{ ANIM_SKEDAR_RUNNING,     0,  0  },
};

bool footstep_is_running(s32 animnum)
{
	switch (animnum) {
	case ANIM_001D:
	case ANIM_001E:
	case ANIM_0029:
	case ANIM_RUNNING_TWOHANDGUN:
	case ANIM_0055:
	case ANIM_0056:
	case ANIM_0057:
	case ANIM_0058:
	case ANIM_RUNNING_ONEHANDGUN:
	case ANIM_005A:
	case ANIM_005D:
	case ANIM_005E:
	case ANIM_005F:
	case ANIM_006E:
	case ANIM_006F:
	case ANIM_0070:
	case ANIM_0071:
	case ANIM_0073:
	case ANIM_0093:
	case ANIM_0094:
	case ANIM_SKEDAR_RUNNING:
		return true;
	}

	return false;
}

s32 footstep_choose_sound(struct chrdata *chr, s32 footstepindex)
{
	s32 floortype;
	s32 running;
	s32 rand;
	s32 index;

	if (chr->footstep == 0) {
		return 0;
	}

	floortype = chr->floortype <= FLOORTYPE_SNOW ? chr->floortype : 0;

	if (floortype == -1) {
		return 0;
	}

	if (CHRRACE(chr) == RACE_SKEDAR && chr->bodynum != BODY_MINISKEDAR) {
		u32 result;
		chr->lastfootsample ^= 1;

		if (floortype == FLOORTYPE_METAL) {
			if (chr->lastfootsample) {
				result = SFXMAP_8191_FOOTSTEP;
			} else {
				result = SFXMAP_8192_FOOTSTEP;
			}
		} else {
			if (chr->lastfootsample) {
				result = SFXMAP_818F_FOOTSTEP;
			} else {
				result = SFXMAP_8190_FOOTSTEP;
			}
		}

		return result;
	}

	running = footstep_is_running(g_FootstepAnims[footstepindex].animnum);

	do {
		rand = random() % 8;
		index = (running ? 2 : 0) + (rand & 5) + floortype * 8;
	} while (index == chr->lastfootsample);

	chr->lastfootsample = index;

	return g_FootstepSounds[index];
}

/**
 * Check if a footstep sound should play for the given chr and play it if so.
 *
 * It is assumed that the chr is moving normally and not via magic.
 */
void footstep_check_default(struct chrdata *chr)
{
	if (debug_is_footsteps_enabled() && PLAYERCOUNT() == 1 && chr) {
		chr->footstep = 0;
		chr->magicanim = -1;
		chr->magicframe = 0;

		if (chr->model && chr->model->anim) {
			s32 soundnum;
			f32 prevframe = chr->oldframe;
			f32 frame = chr->model->anim->frame;
			s32 i;

			chr->oldframe = frame;

			for (i = 0; i < ARRAYCOUNT(g_FootstepAnims); i++) {
				if (model_get_anim_num(chr->model) == g_FootstepAnims[i].animnum) {
					if (CHRRACE(chr) == RACE_SKEDAR && g_FootstepAnims[i].animnum == ANIM_SKEDAR_RUNNING) {
						if ((frame >= 2 && prevframe < 2) || (frame >= 17 && prevframe < 17)) { \
							chr->footstep = 1;
						} else if ((frame >= 10 && prevframe < 10) || (frame >= 25 && prevframe < 25)) {
							chr->footstep = 2;
						}
					} else {
						if (frame >= g_FootstepAnims[i].frame1 && prevframe < g_FootstepAnims[i].frame1) {
							chr->footstep = 1;
						} else if (frame >= g_FootstepAnims[i].frame2 && prevframe < g_FootstepAnims[i].frame2) {
							chr->footstep = 2;
						}
					}

					soundnum = footstep_choose_sound(chr, i);

					if (soundnum != -1 && chr->footstep != 0) {
#if VERSION >= VERSION_NTSC_1_0
						ps_create(NULL, chr->prop, soundnum, -1, -1, PSFLAG_AMBIENT, 0, PSTYPE_FOOTSTEP, NULL, -1, NULL, -1, -1, -1, -1);
#else
						ps_create(NULL, chr->prop, soundnum, -1, -1, 0, 0, PSTYPE_NONE, NULL, -1, NULL, -1, -1, -1, -1);
#endif
					}

					chr->magicanim = i;
#if VERSION >= VERSION_PAL_BETA
					chr->magicspeed = chr->model->anim->speed;
#else
					chr->magicspeed = chr->model->anim->speed * 0.25f;
#endif
					return;
				}
			}
		}
	}
}

/**
 * Assuming the given chr is moving using magic, check if a footstep sound
 * should play and play it if so.
 *
 * The "magic" method of movement applies when the chr is off-screen.
 * It uses a computationally simple approach to movement.
 */
void footstep_check_magic(struct chrdata *chr)
{
	s32 index;
	f32 frame;
	f32 prevframe;
	struct prop *playerprop = g_Vars.currentplayer->prop;
	f32 xdiff;
	f32 ydiff;
	f32 zdiff;
	s32 soundnum;

	if (debug_is_footsteps_enabled() && PLAYERCOUNT() == 1 && chr->magicanim >= 0) {
#if VERSION >= VERSION_PAL_BETA
		chr->magicframe += g_Vars.lvupdate60freal * chr->magicspeed;
#else
		chr->magicframe += g_Vars.lvupdate240 * chr->magicspeed;
#endif

		if (chr->prop) {
			xdiff = playerprop->pos.x - chr->prop->pos.x;
			ydiff = playerprop->pos.y - chr->prop->pos.y;

			if (ydiff < 0.0f) {
				ydiff = -ydiff;
			}

			zdiff = playerprop->pos.z - chr->prop->pos.z;

			frame = chr->magicframe;
			index = chr->magicanim;
			prevframe = chr->oldframe;

			chr->footstep = 0;
			chr->oldframe = frame;

			if (ydiff < 250 && xdiff * xdiff + zdiff * zdiff < 3000000) {
				if (CHRRACE(chr) == RACE_SKEDAR && g_FootstepAnims[index].animnum == ANIM_SKEDAR_RUNNING) {
					if ((frame >= 2 && prevframe < 2) || (frame >= 17 && prevframe < 17)) {
						chr->footstep = 1;
					} else if ((frame >= 10 && prevframe < 10) || (frame >= 25 && prevframe < 25)) {
						chr->footstep = 2;
					}
				} else {
					if (frame >= g_FootstepAnims[index].frame1 && prevframe < g_FootstepAnims[index].frame1) {
						chr->footstep = 1;
					} else if (frame >= g_FootstepAnims[index].frame2 && prevframe < g_FootstepAnims[index].frame2) {
						chr->footstep = 2;
					}
				}

				soundnum = footstep_choose_sound(chr, index);

				if (soundnum != -1 && chr->footstep != 0) {
#if VERSION >= VERSION_NTSC_1_0
					ps_create(NULL, chr->prop, soundnum, -1,
							-1, PSFLAG_AMBIENT, 0, PSTYPE_FOOTSTEP, NULL, -1, NULL, -1, -1, -1, -1);
#else
					ps_create(NULL, chr->prop, soundnum, -1,
							-1, 0, 0, PSTYPE_NONE, NULL, -1, NULL, -1, -1, -1, -1);
#endif
				}
			}

			if (footstep_is_running(g_FootstepAnims[index].animnum)) {
				if (chr->magicframe > 22) {
					chr->magicframe -= 22;
				}
			} else {
				if (chr->magicframe > 34) {
					chr->magicframe -= 34;
				}
			}
		}
	}
}
