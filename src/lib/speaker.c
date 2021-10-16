#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/snd.h"
#include "lib/speaker.h"
#include "lib/lib_2fc60.h"
#include "lib/lib_317f0.h"
#include "lib/lib_39c80.h"
#include "lib/lib_39fe0.h"
#include "lib/lib_3a100.h"
#include "lib/lib_3c4d0.h"
#include "lib/lib_3cdc0.h"
#include "lib/lib_3d280.h"
#include "lib/lib_3e3e0.h"
#include "lib/lib_3e730.h"
#include "data.h"
#include "types.h"

struct var8009c340 var8009c340;

void speakersSetMode(u8 mode)
{
	s32 i;

	var8009c340.surround = 0;
	var8009c340.mono = 0;
	var8009c340.headphone = 0;

	switch (mode) {
	case SPEAKERMODE_MONO:
		var8009c340.mono = 1;
		break;
	case SPEAKERMODE_HEADPHONE:
		var8009c340.headphone = 1;
		break;
	case SPEAKERMODE_SURROUND:
		var8009c340.surround = 1;
		break;
	}

	for (i = 0; i < 2; i++) {
		speaker00034104(i, 0);
	}
}

void speaker00034104(s32 index, s32 arg1)
{
	if (arg1 == 0) {
		arg1 = var8009c340.unk08[index];
	}

	var8009c340.unk04[index] = 0;
	var8009c340.unk06[index] = 0;

	switch (arg1) {
	case 2:
		if (var8009c340.surround) {
			var8009c340.unk06[index] = 1;
		}
		break;
	case 3:
		if (var8009c340.surround) {
			var8009c340.unk04[index] = 1;
		}
		break;
	case 4:
		if (!var8009c340.mono) {
			var8009c340.unk04[index] = 1;
		}
		break;
	case 5:
		if (!var8009c340.mono) {
			var8009c340.unk04[index] = 1;
			var8009c340.unk06[index] = 1;
		}
		break;
	}

	var8009c340.unk08[index] = arg1;
}
