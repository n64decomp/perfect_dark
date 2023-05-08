#include <ultra64.h>
#include "constants.h"
#include "game/casing.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

static void casingTick(struct casing *casing)
{
	f32 tmp;
	f32 tmp2;
	f32 sp8c[3][3];
	f32 sp68[3][3];
	s32 i;
	s32 j;
	f32 lvupdate = g_Vars.lvupdate60freal;
	f32 sp58;

	tmp2 = lvupdate * (1.0f / 3.6f);
	tmp = casing->speed.y - tmp2;
	casing->pos.y += lvupdate * 0.5f * (casing->speed.y + tmp);

	if (casing->pos.y < casing->ground) {
		i = -1;

		if (var8009d0d8 == 0) {
			if (g_CasingAudioHandles[0] == NULL) {
				i = 0;
			}

			if (g_CasingAudioHandles[1] == NULL) {
				i = 1;
			}
		}

		if (g_Vars.lvupdate240 > 0
				&& i >= 0
				&& g_Vars.currentplayer->hands[0].mode != HANDMODE_2
				&& g_Vars.currentplayer->hands[1].mode != HANDMODE_2) {
			sp58 = RANDOMFRAC() * 0.25f + 0.98f;

			var8009d0d8 = TICKS(20);
			sndStart(var80095200, SFX_8051, &g_CasingAudioHandles[i], -1, -1, -1.0f, -1, -1);

			if (g_CasingAudioHandles[i]) {
				audioPostEvent(g_CasingAudioHandles[i], 0x10, *(s32 *)&sp58);
			}
		}

		casing->modeldef = NULL;
		return;
	}

	casing->speed.y = tmp;
	casing->pos.x += lvupdate * casing->speed.x;
	casing->pos.z += lvupdate * casing->speed.z;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			sp8c[i][j] = casing->rotspeed[i][j] * (1.0f / 4096.0f);
			sp68[i][j] = casing->rot[i][j] * (1.0f / 4096.0f);
		}
	}

	for (i = 0; i < g_Vars.lvupdate240; i++) {
		mtx00016110(sp8c, sp68);
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			casing->rot[i][j] = sp68[i][j] * 4096.0f;
		}
	}
}

void casingsTick(void)
{
	s32 i;
	struct casing *end;
	struct casing *casing;

	if (var8009d0d8 > 0) {
		var8009d0d8 -= g_Vars.lvupdate240;
	}

	if (var8009d0d8 < 0) {
		var8009d0d8 = 0;
	}

	if (g_CasingsActive) {
		g_CasingsActive = false;

		end = g_Casings + ARRAYCOUNT(g_Casings);
		casing = g_Casings;

		while (casing < end) {
			if (casing->modeldef) {
				casingTick(casing);

				if (!g_CasingsActive) {
					g_CasingsActive = true;
				}
			}

			casing++;
		}
	}
}
