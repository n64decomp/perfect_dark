#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_00e460.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_01a3a0.h"
#include "game/data/data_020df0.h"
#include "game/game_015010.h"
#include "game/propobj.h"
#include "game/game_091e10.h"
#include "gvars/gvars.h"
#include "types.h"

void setupParseObjects(void)
{
	u32 *ptr = g_StageSetup.props;

	if (ptr) {
		while ((u8)ptr[0] != OBJTYPE_END) {
			switch ((u8)ptr[0]) {
			case OBJTYPE_DOOR:
			case OBJTYPE_BASIC:
			case OBJTYPE_KEY:
			case OBJTYPE_05:
			case OBJTYPE_CAMERA:
			case OBJTYPE_AMMOCRATE:
			case OBJTYPE_WEAPON:
			case OBJTYPE_SINGLEMONITOR:
			case OBJTYPE_MULTIMONITOR:
			case OBJTYPE_0C:
			case OBJTYPE_AUTOGUN:
			case OBJTYPE_11:
			case OBJTYPE_MULTIAMMOCRATE:
			case OBJTYPE_SHIELD:
			case OBJTYPE_24:
			case OBJTYPE_TRUCK:
			case OBJTYPE_HELI:
			case OBJTYPE_29:
			case OBJTYPE_GLASS:
			case OBJTYPE_2B:
			case OBJTYPE_2D:
			case OBJTYPE_TINTEDGLASS:
			case OBJTYPE_LIFT:
			case OBJTYPE_HOVERBIKE:
			case OBJTYPE_HOVERPROP:
			case OBJTYPE_VENTFAN:
			case OBJTYPE_HOVERCAR:
			case OBJTYPE_CHOPPER:
			case OBJTYPE_ESCALATOR:
				setupParseObjectWithArg2False(ptr, 1);
				break;
			case OBJTYPE_DOORSCALE:
			case OBJTYPE_CHR:
			case OBJTYPE_LINKGUNS:
			case OBJTYPE_DEBRIS:
			case OBJTYPE_10:
			case OBJTYPE_12:
			case OBJTYPE_LINKOBJS:
			case OBJTYPE_TAG:
			case OBJTYPE_BEGINOBJECTIVE:
			case OBJTYPE_ENDOBJECTIVE:
			case OBJECTIVETYPE_DESTROYOBJ:
			case OBJECTIVETYPE_COMPFLAGS:
			case OBJECTIVETYPE_FAILFLAGS:
			case OBJECTIVETYPE_COLLECTOBJ:
			case OBJECTIVETYPE_THROWOBJ:
			case OBJECTIVETYPE_HOLOGRAPH:
			case OBJECTIVETYPE_1F:
			case OBJECTIVETYPE_ENTERROOM:
			case OBJECTIVETYPE_ATTACHOBJ:
			case OBJTYPE_22:
			case OBJTYPE_BRIEFING:
			case OBJTYPE_RENAMEOBJ:
			case OBJTYPE_26:
			case OBJTYPE_2C:
			case OBJTYPE_CAMERA2:
			case OBJTYPE_LINKSCENERY:
			case OBJTYPE_LINKPATHS:
			case OBJTYPE_END:
			case OBJTYPE_PADEFFECT:
			case OBJTYPE_MINE:
				break;
			}

			ptr = ptr + setupGetCommandLength(ptr);
		}
	}
}
