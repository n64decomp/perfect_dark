#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/data/data_02da90.h"
#include "gvars/gvars.h"
#include "lib/lib_0e9d0.h"
#include "lib/lib_317f0.h"
#include "types.h"

void func0f0150a0(void)
{
	s32 i;

	for (i = 0; i < (IS4MB() ? 30 : 40); i++) {
		if (var8006ae10[i].unk30 & 0x0010) {
			func0000fbc4(var8006ae10[i].unk26);
			var8006ae10[i].unk30 &= ~0x0010;
			var8006ae10[i].unk30 &= ~0x0002;
		} else if (var8006ae10[i].audiohandle && audioIsPlaying(var8006ae10[i].audiohandle)) {
			audioStop(var8006ae10[i].audiohandle);
			var8006ae10[i].unk30 &= ~0x0002;
		}
	}
}
