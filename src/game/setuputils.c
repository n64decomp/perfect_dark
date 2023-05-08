#include <ultra64.h>
#include "constants.h"
#include "game/prop.h"
#include "game/setuputils.h"
#include "game/modelmgr.h"
#include "game/bg.h"
#include "game/modeldef.h"
#include "game/propobj.h"
#include "lib/model.h"
#include "bss.h"
#include "data.h"
#include "types.h"

struct stagesetup g_StageSetup;
u8 *g_GeCreditsData;

u32 setupGetCmdLength(u32 *cmd)
{
	switch ((u8)cmd[0]) {
	case OBJTYPE_CHR:                return 11;
	case OBJTYPE_DOOR:               return 55;
	case OBJTYPE_DOORSCALE:          return 2;
	case OBJTYPE_BASIC:              return 23;
	case OBJTYPE_DEBRIS:             return 23;
	case OBJTYPE_GLASS:              return 24;
	case OBJTYPE_TINTEDGLASS:        return 26;
	case OBJTYPE_SAFE:               return 23;
	case OBJTYPE_GASBOTTLE:          return 23;
	case OBJTYPE_KEY:                return 24;
	case OBJTYPE_ALARM:              return 23;
	case OBJTYPE_CCTV:               return 49;
	case OBJTYPE_AMMOCRATE:          return 24;
	case OBJTYPE_WEAPON:             return 26;
	case OBJTYPE_SINGLEMONITOR:      return 53;
	case OBJTYPE_MULTIMONITOR:       return 140;
	case OBJTYPE_HANGINGMONITORS:    return 23;
	case OBJTYPE_AUTOGUN:            return 43;
	case OBJTYPE_LINKGUNS:           return 2;
	case OBJTYPE_HAT:                return 23;
	case OBJTYPE_GRENADEPROB:        return 2;
	case OBJTYPE_LINKLIFTDOOR:       return 5;
	case OBJTYPE_SAFEITEM:           return 5;
	case OBJTYPE_MULTIAMMOCRATE:     return 42;
	case OBJTYPE_SHIELD:             return 26;
	case OBJTYPE_TAG:                return 4;
	case OBJTYPE_RENAMEOBJ:          return 10;
	case OBJTYPE_BEGINOBJECTIVE:     return 4;
	case OBJTYPE_ENDOBJECTIVE:       return 1;
	case OBJECTIVETYPE_DESTROYOBJ:   return 2;
	case OBJECTIVETYPE_COMPFLAGS:    return 2;
	case OBJECTIVETYPE_FAILFLAGS:    return 2;
	case OBJECTIVETYPE_COLLECTOBJ:   return 2;
	case OBJECTIVETYPE_THROWOBJ:     return 2;
	case OBJECTIVETYPE_HOLOGRAPH:    return 4;
	case OBJECTIVETYPE_1F:           return 1;
	case OBJECTIVETYPE_ENTERROOM:    return 4;
	case OBJECTIVETYPE_THROWINROOM:    return 5;
	case OBJTYPE_22:                 return 1;
	case OBJTYPE_BRIEFING:           return 4;
	case OBJTYPE_PADLOCKEDDOOR:      return 4;
	case OBJTYPE_TRUCK:              return 34;
	case OBJTYPE_HELI:               return 35;
	case OBJTYPE_TANK:               return 32;
	case OBJTYPE_CAMERAPOS:          return 7;
	case OBJTYPE_LIFT:               return 37;
	case OBJTYPE_CONDITIONALSCENERY: return 5;
	case OBJTYPE_BLOCKEDPATH:        return 4;
	case OBJTYPE_HOVERBIKE:          return 56;
	case OBJTYPE_HOVERPROP:          return 39;
	case OBJTYPE_FAN:                return 29;
	case OBJTYPE_HOVERCAR:           return 38;
	case OBJTYPE_CHOPPER:            return 58;
	case OBJTYPE_PADEFFECT:          return 3;
	case OBJTYPE_MINE:               return 26;
	case OBJTYPE_ESCASTEP:           return 27;
	}

	return 1;
}

u32 *setupGetCmdByIndex(s32 wantindex)
{
	u32 *cmd = g_StageSetup.props;

	if (wantindex >= 0 && cmd) {
		s32 cmdindex = 0;

		while ((u8)cmd[0] != OBJTYPE_END) {
			if (cmdindex == wantindex) {
				return cmd;
			}

			cmd = cmd + setupGetCmdLength(cmd);
			cmdindex++;
		}
	}

	return NULL;
}

u32 setupGetCmdIndexByProp(struct prop *prop)
{
	u32 *cmd = g_StageSetup.props;

	if (cmd) {
		s32 cmdindex = 0;

		while ((u8)cmd[0] != OBJTYPE_END) {
			if ((struct prop *)cmd[5] == prop) {
				return cmdindex;
			}

			cmd = cmd + setupGetCmdLength(cmd);
			cmdindex++;
		}
	}

	return -1;
}

bool setupLoadModeldef(s32 modelnum)
{
	if (g_ModelStates[modelnum].filedata == NULL) {
		g_ModelStates[modelnum].filedata = modeldefLoadToNew(g_ModelStates[modelnum].fileid);
		modelCalculateRwDataLen(g_ModelStates[modelnum].filedata);
		return true;
	}

	return false;
}

static bool setupGetObjBbox(struct defaultobj *obj, struct coord *pos, f32 realrot[3][3], struct coord *arg3, struct coord *arg4)
{
	struct modelrodata_bbox *bbox = objFindBboxRodata(obj);

	if (bbox != NULL) {
		arg3->x = pos->x + objGetRotatedLocalXMinByMtx3(bbox, realrot);
		arg3->y = pos->y + objGetRotatedLocalYMinByMtx3(bbox, realrot);
		arg3->z = pos->z + objGetRotatedLocalZMinByMtx3(bbox, realrot);

		arg4->x = pos->x + objGetRotatedLocalXMaxByMtx3(bbox, realrot);
		arg4->y = pos->y + objGetRotatedLocalYMaxByMtx3(bbox, realrot);
		arg4->z = pos->z + objGetRotatedLocalZMaxByMtx3(bbox, realrot);

		return true;
	}

	return false;
}

bool setup0f092304(struct defaultobj *obj, struct coord *arg1, struct coord *arg2)
{
	return setupGetObjBbox(obj, &obj->prop->pos, obj->realrot, arg1, arg2);
}

void setup0f09233c(struct defaultobj *obj, struct coord *pos, f32 realrot[3][3], s16 *rooms)
{
	struct coord a;
	struct coord b;
	u32 stack;

	if (setupGetObjBbox(obj, pos, realrot, &a, &b)) {
		a.x -= 1;
		a.y -= 1;
		a.z -= 1;
		b.x += 1;
		b.y += 1;
		b.z += 1;

		bgFindEnteredRooms(&a, &b, rooms, 7, false);
	}
}

void setup0f0923d4(struct defaultobj *obj)
{
	propDeregisterRooms(obj->prop);
	setup0f09233c(obj, &obj->prop->pos, obj->realrot, obj->prop->rooms);
	propRegisterRooms(obj->prop);
}

struct defaultobj *setupGetObjByCmdIndex(u32 cmdindex)
{
	u32 *cmd = setupGetCmdByIndex(cmdindex);

	if (cmd) {
		switch ((u8)cmd[0]) {
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
		case OBJTYPE_DEBRIS:
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
			return (struct defaultobj *)cmd;
		case OBJTYPE_DOORSCALE:
		case OBJTYPE_CHR:
		case OBJTYPE_LINKGUNS:
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
		case OBJTYPE_22:
		case OBJTYPE_BRIEFING:
		case OBJTYPE_RENAMEOBJ:
		case OBJTYPE_PADLOCKEDDOOR:
		case OBJTYPE_SAFEITEM:
		case OBJTYPE_CAMERAPOS:
		case OBJTYPE_CONDITIONALSCENERY:
		case OBJTYPE_BLOCKEDPATH:
		case OBJTYPE_PADEFFECT:
			return NULL;
		}
	}

	return (struct defaultobj *)cmd;
}

/**
 * Find an object in the setup file of little importance that can be reused for
 * something of greater importance.
 *
 * For example, if a weapon is being dropped on screen and there are no extra
 * weapon structs left, this function is used to find another weapon elsewhere
 * in the stage so it can be repurposed.
 *
 * The caller can specify if the obj must already have a prop or model. The
 * caller sets these to true if the game is already at the prop or model limit.
 *
 * If an unused object can be found then it will be returned. Otherwise, for
 * non-weapons, the function will return NULL and write some candidates to
 * offscreenobjptr and anyobjptr. offscreenobjptr will be an object that is
 * offscreen, while anyobjptr will be any object.
 *
 * In reality this function is only called with objtypes weapon and hat, and the
 * hat caller is unreachable because hats don't exist in PD. So it's only used
 * for weapons which means the candidate logic isn't used.
 */
struct defaultobj *setupFindObjForReuse(s32 wanttype, struct defaultobj **offscreenobjptr, struct defaultobj **anyobjptr, bool musthaveprop, bool musthavemodel, struct modelfiledata *filedata)
{
	struct defaultobj *offscreenobj = NULL;
	struct defaultobj *anyobj = NULL;

	u32 *cmd = g_StageSetup.props;

	if (cmd) {
		while ((u8)cmd[0] != OBJTYPE_END) {
			if ((wanttype & 0xff) == (u8)cmd[0]) {
				struct defaultobj *obj = (struct defaultobj *)cmd;

				if (obj->prop == NULL) {
					if (!musthaveprop && !musthavemodel) {
						return obj;
					}
				} else if (wanttype != OBJTYPE_WEAPON
						&& (obj->hidden & OBJHFLAG_PROJECTILE) == 0
						&& (obj->hidden2 & OBJH2FLAG_CANREGEN) == 0
						&& (obj->flags & OBJFLAG_00800000) == 0
						&& obj->prop->parent == NULL
						&& (!musthavemodel || modelmgrCanSlotFitRwdata(obj->model, filedata))) {
					if (offscreenobj == NULL && (obj->prop->flags & (PROPFLAG_ONTHISSCREENTHISTICK | PROPFLAG_ONANYSCREENTHISTICK | PROPFLAG_ONANYSCREENPREVTICK)) == 0) {
						offscreenobj = obj;
					}

					if (anyobj == NULL) {
						anyobj = obj;
					}
				}
			}

			cmd = cmd + setupGetCmdLength(cmd);
		}
	}

	*offscreenobjptr = offscreenobj;
	*anyobjptr = anyobj;

	return NULL;
}
