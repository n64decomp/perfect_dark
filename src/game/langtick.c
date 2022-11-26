#include <ultra64.h>
#include "constants.h"
#include "game/lang.h"
#include "game/room.h"
#include "lib/main.h"
#include "bss.h"
#include "data.h"
#include "types.h"

#if VERSION == VERSION_JPN_FINAL
s32 var8009d370jf;
#endif

extern s32 var8009d140jf;

void langTick(void)
{
	s32 i;

#if VERSION == VERSION_JPN_FINAL
	static u32 language = 99;

	var8009d370jf = 0;

	mainOverrideVariable("jap", &language);

	if (language < 2) {
		langSetJpnEnabled(language);
		language = 99;
	}

	for (i = 0; i < var8009d140jf; i++) {
		if (var800aabb8[i].unk00_00) {
			var800aabb8[i].unk00_00--;
		}
	}
#elif VERSION >= VERSION_PAL_BETA
	static u32 language = 99;

	mainOverrideVariable("language", &language);

	if (language < 5) {
		langSetEuropean(language);
		language = 99;
	}

	if (g_Jpn) {
		for (i = 0; i != 124; i++) {
			if (var800aabb8[i].unk00_00) {
				var800aabb8[i].unk00_00--;
			}
		}
	}
#else
	if (g_Jpn) {
		for (i = 0; i != 124; i++) {
			if (var800aabb8[i].unk00_00) {
				var800aabb8[i].unk00_00--;
			}
		}
	}
#endif
}
