#include <ultra64.h>
#include "constants.h"
#include "game/setuputils.h"
#include "game/propobj.h"
#include "bss.h"
#include "data.h"
#include "types.h"

void objs_stop(void)
{
	u32 *ptr = g_StageSetup.props;

	if (ptr) {
		while ((u8)ptr[0] != OBJTYPE_END) {
			switch ((u8)ptr[0]) {
			case OBJTYPE_DOOR:
			case OBJTYPE_BASIC:
			case OBJTYPE_KEY:
			case OBJTYPE_ALARM:
			case OBJTYPE_CCTV:
			case OBJTYPE_AMMOCRATE:
			case OBJTYPE_WEAPON:
			case OBJTYPE_SINGLEMONITOR:
			case OBJTYPE_MULTIMONITOR:
			case OBJTYPE_HANGINGMONITORS:
			case OBJTYPE_AUTOGUN:
			case OBJTYPE_HAT:
			case OBJTYPE_MULTIAMMOCRATE:
			case OBJTYPE_SHIELD:
			case OBJTYPE_GASBOTTLE:
			case OBJTYPE_TRUCK:
			case OBJTYPE_HELI:
			case OBJTYPE_29:
			case OBJTYPE_GLASS:
			case OBJTYPE_SAFE:
			case OBJTYPE_TANK:
			case OBJTYPE_TINTEDGLASS:
			case OBJTYPE_LIFT:
			case OBJTYPE_HOVERBIKE:
			case OBJTYPE_HOVERPROP:
			case OBJTYPE_FAN:
			case OBJTYPE_HOVERCAR:
			case OBJTYPE_CHOPPER:
			case OBJTYPE_ESCASTEP:
				obj_free_permanently((struct defaultobj *) ptr, true);
				break;
			case OBJTYPE_DOORSCALE:
			case OBJTYPE_CHR:
			case OBJTYPE_LINKGUNS:
			case OBJTYPE_DEBRIS:
			case OBJTYPE_10:
			case OBJTYPE_GRENADEPROB:
			case OBJTYPE_LINKLIFTDOOR:
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
			case OBJECTIVETYPE_THROWINROOM:
			case OBJECTIVETYPE_COPYGOLDENEYE:
			case OBJTYPE_BRIEFING:
			case OBJTYPE_RENAMEOBJ:
			case OBJTYPE_PADLOCKEDDOOR:
			case OBJTYPE_SAFEITEM:
			case OBJTYPE_CAMERAPRESET:
			case OBJTYPE_CONDITIONALSCENERY:
			case OBJTYPE_BLOCKEDPATH:
			case OBJTYPE_END:
			case OBJTYPE_PADEFFECT:
			case OBJTYPE_MINE:
				break;
			}

			ptr = ptr + setup_get_cmd_length(ptr);
		}
	}
}
