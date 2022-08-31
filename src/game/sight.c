#include <ultra64.h>
#include "constants.h"
#include "game/chraction.h"
#include "game/bondgun.h"
#include "game/game_0b0fd0.h"
#include "game/game_0b2150.h"
#include "game/tex.h"
#include "game/savebuffer.h"
#include "game/sight.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/gfxmemory.h"
#include "game/lang.h"
#include "game/options.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/snd.h"
#include "data.h"
#include "types.h"

/**
 * Return true if the prop is considered friendly (blue sight).
 */
bool sightIsPropFriendly(struct prop *prop)
{
	if (prop == NULL) {
		prop = g_Vars.currentplayer->lookingatprop.prop;
	}

	if (prop == NULL) {
		return false;
	}

	if (prop->type != PROPTYPE_CHR && prop->type != PROPTYPE_PLAYER) {
		return false;
	}

	if (g_Vars.coopplayernum >= 0 && prop->type == PROPTYPE_PLAYER) {
		return true;
	}

	if (g_Vars.antiplayernum >= 0 && prop->type == PROPTYPE_PLAYER) {
		return false;
	}

	if (g_Vars.normmplayerisrunning == false
			&& prop->chr
			&& (prop->chr->hidden2 & CHRH2FLAG_BLUESIGHT)) {
		return true;
	}

	return chrCompareTeams(g_Vars.currentplayer->prop->chr, prop->chr, COMPARE_FRIENDS);
}

void sight0f0d715c(void)
{
	// empty
}

Gfx *sight0f0d7164(Gfx *gdl)
{
	return gdl;
}

/**
 * Return true if the given prop can be added to the target list.
 */
bool sightCanTargetProp(struct prop *prop, s32 max)
{
	s32 i;

	for (i = 0; i < max; i++) {
		if (prop == g_Vars.currentplayer->trackedprops[i].prop) {
			return false;
		}
	}

	if (prop->type == PROPTYPE_CHR) {
		return true;
	}

	if (prop->type == PROPTYPE_PLAYER) {
		return true;
	}

	if ((prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_DOOR)
			&& prop->obj && (prop->obj->flags3 & OBJFLAG3_REACTTOSIGHT)) {
		return true;
	}

	if (bgunGetWeaponNum(HAND_RIGHT) == WEAPON_ROCKETLAUNCHER) {
		return true;
	}

	return false;
}

/**
 * Return true if the sight should change colour when aiming at the given prop.
 */
bool sightIsReactiveToProp(struct prop *prop)
{
	if (prop->obj == NULL) {
		return false;
	}

	if (prop->type == PROPTYPE_OBJ || prop->type == PROPTYPE_WEAPON || prop->type == PROPTYPE_DOOR) {
		struct defaultobj *obj = prop->obj;

		if (g_Vars.stagenum == STAGE_CITRAINING
				&& (obj->modelnum == MODEL_COMHUB || obj->modelnum == MODEL_CIHUB || obj->modelnum == MODEL_TARGET)) {
			return true;
		}

		if (objGetDestroyedLevel(obj) > 0) {
			return false;
		}
	} else if (prop->type == PROPTYPE_CHR) {
		struct chrdata *chr = prop->chr;

		if (chr && chr->race == RACE_EYESPY) {
			struct eyespy *eyespy = chrToEyespy(chr);

			if (!eyespy || !eyespy->deployed) {
				return false;
			}
		}
	}

	return true;
}

s32 sightFindFreeTargetIndex(s32 max)
{
	s32 i;

	for (i = 0; i < max; i++) {
		if (g_Vars.currentplayer->trackedprops[i].prop == NULL) {
			return i;
		}
	}

	return -1;
}

void func0f0d7364(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_Vars.currentplayer->trackedprops); i++) {
		g_Vars.currentplayer->trackedprops[i].prop = NULL;
	}
}

void sightTick(bool sighton)
{
	struct trackedprop *trackedprop;
	u8 newtarget;
	s32 i;
	s32 index;
	struct inventory_class *thing = func0f0b11bc(&g_Vars.currentplayer->hands[0].gset);
	struct weaponfunc *func = weaponGetFunctionById(g_Vars.currentplayer->hands[0].gset.weaponnum,
			g_Vars.currentplayer->hands[0].gset.weaponfunc);

	g_Vars.currentplayer->sighttimer240 += g_Vars.lvupdate240;

	for (i = 0; i < 4; i++) {
		if (g_Vars.currentplayer->targetset[i] > TICKS(512)) {
			if (g_Vars.currentplayer->targetset[i] < (VERSION >= VERSION_PAL_BETA ? TICKS(1020) : 1024) - g_Vars.lvupdate240) {
				g_Vars.currentplayer->targetset[i] += g_Vars.lvupdate240;
			} else {
				g_Vars.currentplayer->targetset[i] = TICKS(1020);
			}
		} else {
			if (g_Vars.currentplayer->targetset[i] < (VERSION >= VERSION_PAL_BETA ? TICKS(512) : 516) - g_Vars.lvupdate240) {
				g_Vars.currentplayer->targetset[i] += g_Vars.lvupdate240;
			} else {
				g_Vars.currentplayer->targetset[i] = TICKS(512);
			}
		}
	}

	newtarget = thing->unk18 >> 28;

	if (gsetHasFunctionFlags(&g_Vars.currentplayer->hands[0].gset, FUNCFLAG_THREATDETECTOR)) {
		newtarget = 5;
	}

	if (func && (func->type & 0xff) == INVENTORYFUNCTYPE_CLOSE) {
		newtarget = 0;
	}

	if (newtarget != g_Vars.currentplayer->target) {
		if (newtarget == 5) {
			for (i = 0; i < 4; i++) {
				g_Vars.currentplayer->trackedprops[i].prop = NULL;
			}
		}

		g_Vars.currentplayer->target = newtarget;

		switch (newtarget) {
		case SIGHTTARGET_NONE:
		case SIGHTTARGET_DEFAULT:
		case SIGHTTARGET_BETASCANNER:
		case SIGHTTARGET_ROCKETLAUNCHER:
		case SIGHTTARGET_CMP150:
			break;
		}
	}

	if (sighton && g_Vars.currentplayer->lastsighton == false && newtarget != 5) {
		for (i = 0; i < 4; i++) {
			g_Vars.currentplayer->trackedprops[i].prop = NULL;
		}
	}

	for (i = 0; i < 4; i++) {
		trackedprop = &g_Vars.currentplayer->trackedprops[i];

		if (trackedprop->prop && !sightIsReactiveToProp(trackedprop->prop)) {
			trackedprop->prop = NULL;
		}
	}

	trackedprop = &g_Vars.currentplayer->lookingatprop;

	if (trackedprop->prop && !sightIsReactiveToProp(trackedprop->prop)) {
		trackedprop->prop = NULL;
	}

	switch (g_Vars.currentplayer->target) {
	case SIGHTTARGET_DEFAULT:
	case SIGHTTARGET_BETASCANNER:
		// Conditionally copy lookingatprop to trackedprops[0], overwriting anything that's there
		if (sighton) {
			if (g_Vars.currentplayer->lookingatprop.prop) {
				if (g_Vars.currentplayer->lookingatprop.prop != g_Vars.currentplayer->trackedprops[0].prop) {
					struct sndstate *handle;

					handle = snd00010718(&handle, 0, 0x7fff, 0x40, 7, 1, 1, -1, 1);

					trackedprop = &g_Vars.currentplayer->trackedprops[0];

					trackedprop->prop = g_Vars.currentplayer->lookingatprop.prop;
					trackedprop->x1 = g_Vars.currentplayer->lookingatprop.x1;
					trackedprop->y1 = g_Vars.currentplayer->lookingatprop.y1;
					trackedprop->x2 = g_Vars.currentplayer->lookingatprop.x2;
					trackedprop->y2 = g_Vars.currentplayer->lookingatprop.y2;

					g_Vars.currentplayer->targetset[0] = 0;
				}
			} else {
				g_Vars.currentplayer->trackedprops[0].prop = NULL;
			}
		}
		break;
	case SIGHTTARGET_ROCKETLAUNCHER:
		// Conditionally copy lookingatprop to trackedprops[0], but only if that slot is empty
		if (sighton && g_Vars.currentplayer->lookingatprop.prop
				&& sightCanTargetProp(g_Vars.currentplayer->lookingatprop.prop, 1)) {
			index = sightFindFreeTargetIndex(1);

			if (index >= 0) {
				struct sndstate *handle;

				handle = snd00010718(&handle, 0, 0x7fff, 0x40, 7, 1, 1, -1, 1);

				trackedprop = &g_Vars.currentplayer->trackedprops[index];

				trackedprop->prop = g_Vars.currentplayer->lookingatprop.prop;
				trackedprop->x1 = g_Vars.currentplayer->lookingatprop.x1;
				trackedprop->y1 = g_Vars.currentplayer->lookingatprop.y1;
				trackedprop->x2 = g_Vars.currentplayer->lookingatprop.x2;
				trackedprop->y2 = g_Vars.currentplayer->lookingatprop.y2;

				g_Vars.currentplayer->targetset[index] = 0;
			}
		}
		break;
	case SIGHTTARGET_CMP150:
		// Conditionally copy lookingatprop to any trackedprops slot, but only if the slot is empty
		if (sighton && g_Vars.currentplayer->lookingatprop.prop
				&& sightCanTargetProp(g_Vars.currentplayer->lookingatprop.prop, 4)) {
			index = sightFindFreeTargetIndex(4);

			if (index >= 0) {
				struct sndstate *handle;

				handle = snd00010718(&handle, 0, 0x7fff, 0x40, 7, 1, 1, -1, 1);

				trackedprop = &g_Vars.currentplayer->trackedprops[index];

				trackedprop->prop = g_Vars.currentplayer->lookingatprop.prop;
				trackedprop->x1 = g_Vars.currentplayer->lookingatprop.x1;
				trackedprop->y1 = g_Vars.currentplayer->lookingatprop.y1;
				trackedprop->x2 = g_Vars.currentplayer->lookingatprop.x2;
				trackedprop->y2 = g_Vars.currentplayer->lookingatprop.y2;

				g_Vars.currentplayer->targetset[index] = 0;
			}
		}
		break;
	case SIGHTTARGET_NONE:
	case SIGHTTARGET_THREATDETECTOR:
		break;
	}

	g_Vars.currentplayer->lastsighton = sighton;
}

/**
 * Calculate the position of one border of a target box.
 *
 * The arguments here are named for a left border,
 * but can be called for any of the four edges.
 */
s32 sightCalculateBoxBound(s32 targetx, s32 viewleft, s32 timeelapsed, s32 timeend)
{
	s32 value;

	if (timeelapsed > timeend) {
		timeelapsed = timeend;
	}

	value = (targetx - viewleft) * timeelapsed;

	return viewleft + value / timeend;
}

/**
 * Draw a red (or blue) box around the given trackedprop.
 *
 * textid can be:
 * 0 to have no label
 * 1 to label it as "0"
 * 2 to label it as "1"
 * ...
 * 6 to label it as "5"
 * 7 or above to treat textid as a proper language text ID.
 */
Gfx *sightDrawTargetBox(Gfx *gdl, struct trackedprop *trackedprop, s32 textid, s32 time)
{
	s32 viewleft = viGetViewLeft() / g_ScaleX;
	s32 viewtop = viGetViewTop();
	s32 viewwidth = viGetViewWidth() / g_ScaleX;
	s32 viewheight = viGetViewHeight();
	s32 viewright = viewleft + viewwidth - 1;
	s32 viewbottom = viewtop + viewheight - 1;
	u32 colour;
	s32 boxleft;
	s32 boxright;
	s32 boxtop;
	s32 boxbottom;
	bool textonscreen = true;

	if (time > TICKS(512)) {
		time = TICKS(512);
	}

	boxleft = sightCalculateBoxBound(trackedprop->x1 / g_ScaleX, viewleft, time, TICKS(80));
	boxtop = sightCalculateBoxBound(trackedprop->y1, viewtop, time, TICKS(80));
	boxright = sightCalculateBoxBound(trackedprop->x2 / g_ScaleX, viewright, time, TICKS(80));
	boxbottom = sightCalculateBoxBound(trackedprop->y2, viewbottom, time, TICKS(80));

	if (trackedprop->prop) {
		colour = sightIsPropFriendly(trackedprop->prop) ? 0x000ff60 : 0xff000060;

		gdl = textSetPrimColour(gdl, colour);

		// Left
		if (boxleft >= viewleft && boxleft <= viewright && boxtop <= viewbottom && boxbottom >= viewtop) {
			gDPFillRectangleScaled(gdl++,
					boxleft, (boxtop > viewtop ? boxtop : viewtop),
					boxleft + 1, (boxbottom < viewbottom ? boxbottom : viewbottom) + 1);
		}

		// Right
		if (boxright >= viewleft && boxright <= viewright && boxtop <= viewbottom && boxbottom >= viewtop) {
			gDPFillRectangleScaled(gdl++,
					boxright, (boxtop > viewtop ? boxtop : viewtop),
					boxright + 1, (boxbottom < viewbottom ? boxbottom : viewbottom) + 1);
		} else {
			textonscreen = false;
		}

		// Top
		if (boxtop >= viewtop && boxtop <= viewbottom && boxleft <= viewright && boxright >= viewleft) {
			gDPFillRectangleScaled(gdl++,
					(boxleft > viewleft ? boxleft : viewleft), boxtop,
					(boxright < viewright ? boxright : viewright) + 1, boxtop + 1);
		} else {
			textonscreen = false;
		}

		// Bottom
		if (boxbottom >= viewtop && boxbottom <= viewbottom && boxleft <= viewright && boxright >= viewleft) {
			gDPFillRectangleScaled(gdl++,
					(boxleft > viewleft ? boxleft : viewleft), boxbottom,
					(boxright < viewright ? boxright : viewright) + 1, boxbottom + 1);
		}

		gdl = text0f153838(gdl);

		if (textid != 0 && textonscreen) {
			s32 x = boxright + 3;
			s32 y = boxtop + 3;

			if (textid < 7) {
				char label[] = {'1', '\n', '\0'};

				// textid 1 writes '0'
				label[0] = textid + 0x2f;

				gdl = textRender(gdl, &x, &y, label, g_CharsNumeric, g_FontNumeric, 0x00ff00a0, 0x000000a0, viGetWidth(), viGetHeight(), 0, 0);
			} else {
				char *text = langGet(textid);
#if VERSION >= VERSION_JPN_FINAL
				gdl = func0f1574d0jf(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, viGetWidth(), viGetHeight(), 0, 0);
#else
				gdl = textRender(gdl, &x, &y, text, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0, viGetWidth(), viGetHeight(), 0, 0);
#endif
			}
		}
	}

	return gdl;
}

Gfx *sightDrawAimer(Gfx *gdl, s32 x, s32 y, s32 radius, s32 cornergap, u32 colour)
{
	s32 viewleft = viGetViewLeft() / g_ScaleX;
	s32 viewtop = viGetViewTop();
	s32 viewwidth = viGetViewWidth() / g_ScaleX;
	s32 viewheight = viGetViewHeight();
	s32 viewright = viewleft + viewwidth - 1;
	s32 viewbottom = viewtop + viewheight - 1;

	gdl = textSetPrimColour(gdl, 0x00ff0028);

	// Draw the lines that span most of the viewport
	if (PLAYERCOUNT() == 1) {
		gDPFillRectangleScaled(gdl++, viewleft + 48, y, x - radius + 3, y + 1);
		gDPFillRectangleScaled(gdl++, x + radius - 2, y, viewright - 48, y + 1);
		gDPFillRectangleScaled(gdl++, x, viewtop + 10, x + 1, y - radius + 3);
		gDPFillRectangleScaled(gdl++, x, y + radius - 2, x + 1, viewbottom - 9);
	} else {
		gDPFillRectangleScaled(gdl++, viewleft, y, x - radius + 3, y + 1);
		gDPFillRectangleScaled(gdl++, x + radius - 2, y, viewright + 1, y + 1);
		gDPFillRectangleScaled(gdl++, x, viewtop, x + 1, y - radius + 3);
		gDPFillRectangleScaled(gdl++, x, y + radius - 2, x + 1, viewbottom + 1);
	}

	gdl = text0f153838(gdl);
	gdl = textSetPrimColour(gdl, colour);

	// Draw the box
	gDPFillRectangleScaled(gdl++, x - radius, y - radius, x - radius + 1, y + radius + 1);
	gDPFillRectangleScaled(gdl++, x + radius, y - radius, x + radius + 1, y + radius + 1);
	gDPFillRectangleScaled(gdl++, x - radius, y - radius, x + radius + 1, y - radius + 1);
	gDPFillRectangleScaled(gdl++, x - radius, y + radius, x + radius + 1, y + radius + 1);

	// Go over the corners a second time
	gDPFillRectangleScaled(gdl++, x - radius, y - radius, x - radius + 1, y - cornergap + 1);
	gDPFillRectangleScaled(gdl++, x - radius, y + cornergap, x - radius + 1, y + radius + 1);
	gDPFillRectangleScaled(gdl++, x + radius, y - radius, x + radius + 1, y - cornergap + 1);
	gDPFillRectangleScaled(gdl++, x + radius, y + cornergap, x + radius + 1, y + radius + 1);
	gDPFillRectangleScaled(gdl++, x - radius, y - radius, x - cornergap + 1, y - radius + 1);
	gDPFillRectangleScaled(gdl++, x + cornergap, y - radius, x + radius + 1, y - radius + 1);
	gDPFillRectangleScaled(gdl++, x - radius, y + radius, x - cornergap + 1, y + radius + 1);
	gDPFillRectangleScaled(gdl++, x + cornergap, y + radius, x + radius + 1, y + radius + 1);

	gdl = text0f153838(gdl);

	return gdl;
}

/**
 * The delayed aimer is an unused aimer box. It's twice as big as the normal one
 * and follows the gun's cursor with a very noticeable delay. The lines that
 * span the viewport are not used here, and a 3x3 box is filled in with green
 * at the live crosshair position.
 *
 * Because its position and speed properties are static variables, they only get
 * updated when the aimer is held. This means releasing and pressing R again
 * causes the box to appear where it was last.
 *
 * The default Y position is not quite centered, is not updated for PAL,
 * and is not reset for split screen play. There's also no viewport boundary
 * checks. It's likely that this feature was just a concept and was dropped
 * pretty early.
 */
Gfx *sightDrawDelayedAimer(Gfx *gdl, s32 x, s32 y, s32 radius, s32 cornergap, u32 colour)
{
	s32 boxx;
	s32 boxy;
	s32 i;
	f32 dist;
	f32 accel;
	u32 stack;

	static f32 xpos = 160;
	static f32 ypos = 120;
	static f32 xspeed = 0;
	static f32 yspeed = 0;

	for (i = 0; i < g_Vars.lvupdate240_60; i++) {
		dist = x - xpos;

		if (dist > 0.5f || dist < -0.5f) {
			accel = dist * 0.05f;

			if (accel > PALUPF(2.0f)) {
				accel = PALUPF(2.0f);
			}

			if (accel < -PALUPF(2.0f)) {
				accel = -PALUPF(2.0f);
			}

			if (accel > xspeed) {
				accel = PALUPF(0.05f);
			} else if (accel < xspeed) {
				accel = -PALUPF(0.05f);
			} else {
				accel = 0.0f;
			}

			xspeed += accel;

			if (xspeed > PALUPF(2.0f)) {
				xspeed = PALUPF(2.0f);
			}

			if (xspeed < -PALUPF(2.0f)) {
				xspeed = -PALUPF(2.0f);
			}

			xpos += xspeed;
		} else {
			xpos = x;
			xspeed = 0.0f;
		}

		dist = y - ypos;

		if (dist > 0.5f || dist < -0.5f) {
			accel = dist * 0.05f;

			if (accel > PALUPF(2.0f)) {
				accel = PALUPF(2.0f);
			}
			if (accel < -PALUPF(2.0f)) {
				accel = -PALUPF(2.0f);
			}

			if (yspeed < accel) {
				accel = PALUPF(0.05f);
			} else if (accel < yspeed) {
				accel = -PALUPF(0.05f);
			} else {
				accel = 0.0f;
			}

			yspeed += accel;

			if (yspeed > PALUPF(2.0f)) {
				yspeed = PALUPF(2.0f);
			}

			if (yspeed < -PALUPF(2.0f)) {
				yspeed = -PALUPF(2.0f);
			}

			ypos += yspeed;
		} else {
			ypos = y;
			yspeed = 0.0f;
		}
	}

	boxx = xpos;
	boxy = ypos;

	gdl = textSetPrimColour(gdl, 0x00ff0028);

	// Fill a 3x3 box at the live crosshair
	gDPFillRectangleScaled(gdl++, x - 1, y - 1, x + 2, y);
	gDPFillRectangleScaled(gdl++, x - 1, y, x + 2, y + 1);
	gDPFillRectangleScaled(gdl++, x - 1, y + 1, x + 2, y + 2);

	gdl = text0f153838(gdl);

	gdl = textSetPrimColour(gdl, colour);

	// Draw the box
	gDPFillRectangleScaled(gdl++, boxx - radius, boxy - radius, boxx - radius + 1, boxy + radius + 1);
	gDPFillRectangleScaled(gdl++, boxx + radius, boxy - radius, boxx + radius + 1, boxy + radius + 1);
	gDPFillRectangleScaled(gdl++, boxx - radius, boxy - radius, boxx + radius + 1, boxy - radius + 1);
	gDPFillRectangleScaled(gdl++, boxx - radius, boxy + radius, boxx + radius + 1, boxy + radius + 1);

	// Go over the corners a second time
	gDPFillRectangleScaled(gdl++, boxx - radius, boxy - radius, boxx - radius + 1, boxy - cornergap + 1);
	gDPFillRectangleScaled(gdl++, boxx - radius, boxy + cornergap, boxx - radius + 1, boxy + radius + 1);
	gDPFillRectangleScaled(gdl++, boxx + radius, boxy - radius, boxx + radius + 1, boxy - cornergap + 1);
	gDPFillRectangleScaled(gdl++, boxx + radius, boxy + cornergap, boxx + radius + 1, boxy + radius + 1);
	gDPFillRectangleScaled(gdl++, boxx - radius, boxy - radius, boxx - cornergap + 1, boxy - radius + 1);
	gDPFillRectangleScaled(gdl++, boxx + cornergap, boxy - radius, boxx + radius + 1, boxy - radius + 1);
	gDPFillRectangleScaled(gdl++, boxx - radius, boxy + radius, boxx - cornergap + 1, boxy + radius + 1);
	gDPFillRectangleScaled(gdl++, boxx + cornergap, boxy + radius, boxx + radius + 1, boxy + radius + 1);

	gdl = text0f153838(gdl);

	return gdl;
}

Gfx *sightDrawDefault(Gfx *gdl, bool sighton)
{
	s32 radius;
	s32 cornergap;
	u32 colour;
	s32 x = (s32) g_Vars.currentplayer->crosspos[0] / g_ScaleX;
	s32 y = g_Vars.currentplayer->crosspos[1];
	struct trackedprop *trackedprop;
	s32 i;

	static s32 sight = 0;
	static s32 identifytimer = 0;

	gdl = text0f153628(gdl);

	if (1);

	switch (g_Vars.currentplayer->target) {
	case SIGHTTARGET_NONE:
		// SIGHTTARGET_NONE is used for unarmed, but this appears to be
		// unreachable. The aimer is never drawn when unarmed.
		if (sighton) {
			colour = 0x00ff0028;
			radius = 8;
			cornergap = 5;
			gdl = sightDrawAimer(gdl, x, y, radius, cornergap, colour);
		}
		break;
	case SIGHTTARGET_DEFAULT:
		// For most guns, render the aimer if holding R
		if (sighton) {
			if (g_Vars.currentplayer->lookingatprop.prop == NULL) {
				colour = 0x00ff0028;
				radius = 8;
				cornergap = 5;
			} else {
				colour = sightIsPropFriendly(NULL) ? 0x0000ff60 : 0xff000060;
				radius = 6;
				cornergap = 3;
			}

			mainOverrideVariable("sight", &sight);

			switch (sight) {
			case 0:
				gdl = sightDrawAimer(gdl, x, y, radius, cornergap, colour);
				break;
			case 1:
				gdl = sightDrawDelayedAimer(gdl, x, y, radius * 2, cornergap * 2, colour);
				break;
			}
		}
		break;
	case SIGHTTARGET_BETASCANNER:
		// An unused sight target. When holding R, it flashes the text
		// "Identify" and draws a red box around the targetted prop.
		if (sighton) {
			s32 textx;
			s32 texty;

			if (g_Vars.currentplayer->lookingatprop.prop == NULL) {
				colour = 0x00ff0028;
				radius = 8;
				cornergap = 5;
			} else {
				colour = sightIsPropFriendly(NULL) ? 0x0000ff60 : 0xff000060;
				radius = 6;
				cornergap = 3;
			}

			textx = 135;
			texty = 200;

			identifytimer += g_Vars.lvupdate240;

			if (identifytimer & 0x80) {
				// "Identify"
#if VERSION == VERSION_JPN_FINAL
				gdl = func0f1574d0jf(gdl, &textx, &texty, langGet(L_MISC_439),
						g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0,
						viGetWidth(), viGetHeight(), 0, 0);
#else
				gdl = textRender(gdl, &textx, &texty, langGet(L_MISC_439),
						g_CharsHandelGothicXs, g_FontHandelGothicXs, 0x00ff00a0, 0x000000a0,
						viGetWidth(), viGetHeight(), 0, 0);
#endif
			}

			gdl = sightDrawAimer(gdl, x, y, radius, cornergap, colour);

			if (g_Vars.currentplayer->lookingatprop.prop) {
				gdl = sightDrawTargetBox(gdl, &g_Vars.currentplayer->lookingatprop, 1, g_Vars.currentplayer->targetset[0]);
			}
		}
		break;
	case SIGHTTARGET_ROCKETLAUNCHER:
		for (i = 0; i < 1; i++) {
			trackedprop = &g_Vars.currentplayer->trackedprops[i];

			if (trackedprop->prop) {
				gdl = sightDrawTargetBox(gdl, trackedprop, 0, g_Vars.currentplayer->targetset[i]);
			}
		}

		if (sighton) {
			if (g_Vars.currentplayer->lookingatprop.prop == NULL) {
				colour = 0x00ff0028;
				radius = 8;
				cornergap = 5;
			} else {
				colour = sightIsPropFriendly(NULL) ? 0x0000ff60 : 0xff000060;
				radius = 6;
				cornergap = 3;
			}

			gdl = sightDrawAimer(gdl, x, y, radius, cornergap, colour);
		}
		break;
	case SIGHTTARGET_CMP150:
	case SIGHTTARGET_THREATDETECTOR:
		for (i = 0; i < 4; i++) {
			trackedprop = &g_Vars.currentplayer->trackedprops[i];

			if (trackedprop->prop) {
				if (g_Vars.currentplayer->target == SIGHTTARGET_THREATDETECTOR) {
					struct defaultobj *obj = trackedprop->prop->obj;
					struct weaponobj *weapon;
					u32 textid = 0;

					// @dangerous: There is no check here to see if the prop
					// type is obj. However, it's likely that only objs can be
					// in the cmdfollowprops list at this point, so it's
					// probably OK.
					if (obj && obj->type == OBJTYPE_AUTOGUN
							&& (obj->flags2 & (OBJFLAG2_AICANNOTUSE | OBJFLAG2_80000000)) == 0) {
						textid = L_GUN_215; // "AUTOGUN"
					}

					weapon = trackedprop->prop->weapon;

					if (weapon && weapon->base.type == OBJTYPE_WEAPON) {
						switch (weapon->weaponnum) {
						case WEAPON_GRENADE:
							// "PROXY" and "TIMED"
							textid = (weapon->gunfunc == FUNC_SECONDARY) ? L_GUN_212 : L_GUN_213;
							break;
						case WEAPON_NBOMB:
							// "PROXY" and "IMPACT"
							textid = (weapon->gunfunc == FUNC_SECONDARY) ? L_GUN_212 : L_GUN_216;
							break;
						case WEAPON_TIMEDMINE:
							textid = L_GUN_213; // "TIMED"
							break;
						case WEAPON_PROXIMITYMINE:
							textid = L_GUN_212; // "PROXY"
							break;
						case WEAPON_REMOTEMINE:
							textid = L_GUN_214; // "REMOTE"
							break;
						case WEAPON_DRAGON:
							if (weapon->gunfunc == FUNC_SECONDARY) {
								textid = L_GUN_212; // "PROXY"
							}
							break;
						}
					}

					gdl = sightDrawTargetBox(gdl, trackedprop, textid, g_Vars.currentplayer->targetset[i]);
				} else {
					// CMP150-tracked prop
					gdl = sightDrawTargetBox(gdl, trackedprop, i + 2, g_Vars.currentplayer->targetset[i]);
				}
			}
		}

		if (sighton) {
			if (g_Vars.currentplayer->lookingatprop.prop == NULL) {
				colour = 0x00ff0028;
				radius = 8;
				cornergap = 5;
			} else {
				colour = sightIsPropFriendly(NULL) ? 0x0000ff60 : 0xff000060;
				radius = 6;
				cornergap = 3;
			}

			gdl = sightDrawAimer(gdl, x, y, radius, cornergap, colour);
		}
		break;
	}

	gdl = text0f153780(gdl);

	return gdl;
}

Gfx *sightDrawClassic(Gfx *gdl, bool sighton)
{
	struct textureconfig *tconfig = &g_TexGeCrosshairConfigs[0];
	f32 spc4[2];
	f32 spbc[2];
	s32 x = g_Vars.currentplayer->crosspos[0];
	s32 y = g_Vars.currentplayer->crosspos[1];
	s32 x1;
	s32 x2;
	s32 y1;
	s32 y2;

	if (!sighton) {
		return gdl;
	}

	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureFilter(gdl++, G_TF_POINT);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetTextureLUT(gdl++, G_TT_NONE);
	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
	gDPSetPrimColor(gdl++, 0, 0, 0x00, 0x00, 0x00, 0x00);

	x1 = x - (tconfig->width >> 1);
	y1 = y - (tconfig->height >> 1);
	x2 = x + (tconfig->width >> 1);
	y2 = y + (tconfig->height >> 1);

	gDPFillRectangle(gdl++, x1, y1, x2, y2);

	spc4[0] = x;
	spc4[1] = y;

	spbc[0] = (tconfig->width >> 1) * (f32)g_ScaleX;
	spbc[1] = tconfig->height >> 1;

	texSelect(&gdl, tconfig, 2, 0, 0, 1, NULL);

	func0f0b278c(&gdl, spc4, spbc, tconfig->width, tconfig->height,
			0, 0, 1, 0xff, 0xff, 0xff, 0x7f, tconfig->level > 0, 0);

	gDPPipeSync(gdl++);
	gDPSetColorDither(gdl++, G_CD_BAYER);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_LOD);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetTextureLUT(gdl++, G_TT_NONE);

	return gdl;
}

Gfx *sightDrawType2(Gfx *gdl, bool sighton)
{
	return sightDrawClassic(gdl, sighton);
}

#define COLOUR_LIGHTRED 0xff555564
#define COLOUR_DARKRED  0xff0000b2
#define COLOUR_GREEN    0x55ff5564
#define COLOUR_DARKBLUE 0x0000ff60

#define DIR_UP    0
#define DIR_DOWN  1
#define DIR_LEFT  2
#define DIR_RIGHT 3

Gfx *sightDrawSkedarTriangle(Gfx *gdl, s32 x, s32 y, s32 dir, u32 colour)
{
	s32 points[6];
	struct gfxvtx *vertices = gfxAllocateVertices(3);
	u32 *colours = gfxAllocateColours(2);

	switch (dir) {
	case DIR_UP:
		points[0] = x;
		points[1] = y;
		points[2] = x + 5;
		points[3] = y + 7;
		points[4] = x - 5;
		points[5] = y + 7;
		break;
	case DIR_DOWN:
		points[0] = x;
		points[1] = y;
		points[2] = x + 5;
		points[3] = y - 7;
		points[4] = x - 5;
		points[5] = y - 7;
		break;
	case DIR_LEFT:
		points[0] = x;
		points[1] = y;
		points[2] = x + 7;
		points[3] = y - 5;
		points[4] = x + 7;
		points[5] = y + 5;
		break;
	case DIR_RIGHT:
		points[0] = x;
		points[1] = y;
		points[2] = x - 7;
		points[3] = y - 5;
		points[4] = x - 7;
		points[5] = y + 5;
		break;
	default:
		return gdl;
	}

	vertices[0].x = points[0] * 10;
	vertices[0].y = points[1] * 10;
	vertices[0].z = -10;
	vertices[1].x = points[2] * 10;
	vertices[1].y = points[3] * 10;
	vertices[1].z = -10;
	vertices[2].x = points[4] * 10;
	vertices[2].y = points[5] * 10;
	vertices[2].z = -10;

	// @bug: This also needs to check for COLOUR_LIGHTRED because the caller can
	// use two shades of red. The second colour is used when zeroing the sight
	// in on a new target. Because of this bug, targeting an ally with the
	// Mauler or Reaper will show a red crosshair while it's still zeroing.
	if (colour == COLOUR_DARKRED && sightIsPropFriendly(NULL)) {
		colour = COLOUR_DARKBLUE;
	}

#define RGBA(r, g, b, a) (((r) & 0xff) << 24 | ((g) & 0xff) << 16 | ((b) & 0xff) << 8 | ((a) & 0xff))

	colours[0] = colour;
	colours[1] = RGBA((colour >> 24) & 0xff, (colour >> 16) & 0xff, (colour >> 8) & 0xff, 0x08);

	vertices[0].colour = 0;
	vertices[1].colour = 4;
	vertices[2].colour = 4;

	gDPSetColorArray(gdl++, colours, 2);
	gDPSetVerticeArray(gdl++, vertices, 3);
	gDPTri1(gdl++, 0, 1, 2);

	return gdl;
}

Gfx *sightDrawSkedar(Gfx *gdl, bool sighton)
{
	s32 viewleft = viGetViewLeft() / g_ScaleX;
	s32 viewtop = viGetViewTop();
	s32 viewwidth = viGetViewWidth() / g_ScaleX;
	s32 viewheight = viGetViewHeight();
	s32 viewright = viewleft + viewwidth - 1;
	s32 viewbottom = viewtop + viewheight - 1;
	s32 paddingy = viewheight / 4;
	s32 paddingx = viewwidth / 4;
	s32 x = (s32) (g_Vars.currentplayer->crosspos[0] / g_ScaleX);
	s32 trix1;
	s32 trix2;
	s32 y = g_Vars.currentplayer->crosspos[1];
	s32 triy2;
	s32 triy1;
	u32 colour;
	u8 dir;
	bool hasprop = g_Vars.currentplayer->lookingatprop.prop != NULL;
	f32 frac;

	if (!sighton) {
		return gdl;
	}

	if (!hasprop) {
		g_Vars.currentplayer->sighttimer240 = 0;
	}

	gdl = func0f0d479c(gdl);

	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);
	gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

	trix1 = x;
	triy1 = y;
	trix2 = x;
	triy2 = y;

	if (hasprop && g_Vars.currentplayer->sighttimer240 < TICKS(48)) {
		frac = g_Vars.currentplayer->sighttimer240 / TICKS(48.0f);
	}

	// Outer top triangle
	if (!hasprop) {
		colour = COLOUR_LIGHTRED;

		if (x < viewleft + paddingx) {
			// Aiming far left
			dir = DIR_LEFT;
			trix1 = viewleft + paddingx;
		} else if (x > viewright - paddingx) {
			// Aiming far right
			dir = DIR_RIGHT;
			trix1 = viewright - paddingx;
		} else {
			// Aiming within the bounds
			dir = DIR_DOWN;
			colour = COLOUR_GREEN;
		}

		triy1 = viewtop + paddingy;
	} else {
		if (g_Vars.currentplayer->sighttimer240 < TICKS(48)) {
			// Zeroing on a prop
			colour = COLOUR_LIGHTRED;
			dir = DIR_DOWN;
			triy1 = (y - viewtop - paddingy - 2) * frac + viewtop + paddingy;
		} else {
			// Zeroed on a prop
			colour = COLOUR_DARKRED;
			dir = DIR_DOWN;
			triy1 = y - 2;
		}
	}

	gdl = sightDrawSkedarTriangle(gdl, trix1, triy1, dir, colour);

	// Outer bottom triangle
	if (!hasprop) {
		colour = COLOUR_LIGHTRED;

		if (dir == DIR_DOWN) {
			colour = COLOUR_GREEN;
			dir = DIR_UP;
		}

		triy1 = viewbottom - paddingy;
	} else {
		if (g_Vars.currentplayer->sighttimer240 < TICKS(48)) {
			// Zeroing on a prop
			colour = COLOUR_LIGHTRED;
			dir = DIR_UP;
			triy1 = (y - viewbottom + paddingy + 2) * frac + viewbottom - paddingy;
		} else {
			// Zeroed on a prop
			colour = COLOUR_DARKRED;
			dir = DIR_UP;
			triy1 = y + 2;
		}
	}

	gdl = sightDrawSkedarTriangle(gdl, trix1, triy1, dir, colour);

	// Outer right triangle
	if (!hasprop) {
		colour = COLOUR_LIGHTRED;

		if (y < viewtop + paddingy) {
			// Aiming far up
			dir = DIR_UP;
			triy2 = viewtop + paddingy;
		} else if (y > viewbottom - paddingy) {
			// Aiming far down
			dir = DIR_DOWN;
			triy2 = viewbottom - paddingy;
		} else {
			// Aiming within the bounds
			dir = DIR_LEFT;
			colour = COLOUR_GREEN;
		}

		trix2 = viewright - paddingx;
	} else {
		if (g_Vars.currentplayer->sighttimer240 < TICKS(48)) {
			// Zeroing on a prop
			colour = COLOUR_LIGHTRED;
			dir = DIR_LEFT;
			trix2 = (x - viewright + paddingx + 2) * frac + viewright - paddingx;
		} else {
			colour = COLOUR_DARKRED;
			// Zeroed on a prop
			dir = DIR_LEFT;
			trix2 = x + 2;
		}
	}

	gdl = sightDrawSkedarTriangle(gdl, trix2, triy2, dir, colour);

	// Outer left triangle
	if (!hasprop) {
		colour = COLOUR_LIGHTRED;

		if (dir == DIR_LEFT) {
			colour = COLOUR_GREEN;
			dir = DIR_RIGHT;
		}

		trix2 = viewleft + paddingx;
	} else {
		if (g_Vars.currentplayer->sighttimer240 < TICKS(48)) {
			// Zeroing on a prop
			colour = COLOUR_LIGHTRED;
			dir = DIR_RIGHT;
			trix2 = (x - viewleft - paddingx - 2) * frac + viewleft + paddingx;
		} else {
			// Zeroed on a prop
			colour = COLOUR_DARKRED;
			dir = DIR_RIGHT;
			trix2 = x - 2;
		}
	}

	gdl = sightDrawSkedarTriangle(gdl, trix2, triy2, dir, colour);

	// Inner triangles
	if (!hasprop || g_Vars.currentplayer->sighttimer240 < TICKS(48)) {
		colour = hasprop ? COLOUR_LIGHTRED : COLOUR_GREEN;

		gdl = sightDrawSkedarTriangle(gdl, x + 0, y - 2, DIR_DOWN, colour);
		gdl = sightDrawSkedarTriangle(gdl, x + 0, y + 2, DIR_UP, colour);
		gdl = sightDrawSkedarTriangle(gdl, x - 2, y + 0, DIR_RIGHT, colour);
		gdl = sightDrawSkedarTriangle(gdl, x + 2, y + 0, DIR_LEFT, colour);
	}

	gdl = func0f0d49c8(gdl);

	return gdl;
}

GLOBAL_ASM(
glabel sightDrawZoom
.late_rodata
glabel var7f1ade54
.word 0x3e4ccccd
.text
/*  f0da2dc:	27bdff00 */ 	addiu	$sp,$sp,-256
/*  f0da2e0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0da2e4:	afa50104 */ 	sw	$a1,0x104($sp)
/*  f0da2e8:	0c002f40 */ 	jal	viGetViewLeft
/*  f0da2ec:	afa40100 */ 	sw	$a0,0x100($sp)
/*  f0da2f0:	3c088008 */ 	lui	$t0,%hi(g_ScaleX)
/*  f0da2f4:	2508fac0 */ 	addiu	$t0,$t0,%lo(g_ScaleX)
/*  f0da2f8:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0da2fc:	8fa60100 */ 	lw	$a2,0x100($sp)
/*  f0da300:	004e001a */ 	div	$zero,$v0,$t6
/*  f0da304:	00007812 */ 	mflo	$t7
/*  f0da308:	afaf00fc */ 	sw	$t7,0xfc($sp)
/*  f0da30c:	15c00002 */ 	bnez	$t6,.L0f0da318
/*  f0da310:	00000000 */ 	nop
/*  f0da314:	0007000d */ 	break	0x7
.L0f0da318:
/*  f0da318:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0da31c:	15c10004 */ 	bne	$t6,$at,.L0f0da330
/*  f0da320:	3c018000 */ 	lui	$at,0x8000
/*  f0da324:	14410002 */ 	bne	$v0,$at,.L0f0da330
/*  f0da328:	00000000 */ 	nop
/*  f0da32c:	0006000d */ 	break	0x6
.L0f0da330:
/*  f0da330:	0c002f44 */ 	jal	viGetViewTop
/*  f0da334:	00000000 */ 	nop
/*  f0da338:	0c002f22 */ 	jal	viGetViewWidth
/*  f0da33c:	afa200f8 */ 	sw	$v0,0xf8($sp)
/*  f0da340:	3c088008 */ 	lui	$t0,%hi(g_ScaleX)
/*  f0da344:	2508fac0 */ 	addiu	$t0,$t0,%lo(g_ScaleX)
/*  f0da348:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f0da34c:	8fa60100 */ 	lw	$a2,0x100($sp)
/*  f0da350:	0058001a */ 	div	$zero,$v0,$t8
/*  f0da354:	0000c812 */ 	mflo	$t9
/*  f0da358:	00197043 */ 	sra	$t6,$t9,0x1
/*  f0da35c:	17000002 */ 	bnez	$t8,.L0f0da368
/*  f0da360:	00000000 */ 	nop
/*  f0da364:	0007000d */ 	break	0x7
.L0f0da368:
/*  f0da368:	2401ffff */ 	addiu	$at,$zero,-1
/*  f0da36c:	17010004 */ 	bne	$t8,$at,.L0f0da380
/*  f0da370:	3c018000 */ 	lui	$at,0x8000
/*  f0da374:	14410002 */ 	bne	$v0,$at,.L0f0da380
/*  f0da378:	00000000 */ 	nop
/*  f0da37c:	0006000d */ 	break	0x6
.L0f0da380:
/*  f0da380:	afae00f4 */ 	sw	$t6,0xf4($sp)
/*  f0da384:	0c002f26 */ 	jal	viGetViewHeight
/*  f0da388:	00000000 */ 	nop
/*  f0da38c:	8fb800f8 */ 	lw	$t8,0xf8($sp)
/*  f0da390:	00021843 */ 	sra	$v1,$v0,0x1
/*  f0da394:	3c07800a */ 	lui	$a3,%hi(g_Vars)
/*  f0da398:	00037840 */ 	sll	$t7,$v1,0x1
/*  f0da39c:	3c013f80 */ 	lui	$at,0x3f80
/*  f0da3a0:	44812000 */ 	mtc1	$at,$f4
/*  f0da3a4:	24e79fc0 */ 	addiu	$a3,$a3,%lo(g_Vars)
/*  f0da3a8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0da3ac:	8cef0284 */ 	lw	$t7,0x284($a3)
/*  f0da3b0:	2465fff6 */ 	addiu	$a1,$v1,-10
/*  f0da3b4:	272effff */ 	addiu	$t6,$t9,-1
/*  f0da3b8:	afa300f0 */ 	sw	$v1,0xf0($sp)
/*  f0da3bc:	afae00e8 */ 	sw	$t6,0xe8($sp)
/*  f0da3c0:	afa500e0 */ 	sw	$a1,0xe0($sp)
/*  f0da3c4:	afa500dc */ 	sw	$a1,0xdc($sp)
/*  f0da3c8:	e7a400cc */ 	swc1	$f4,0xcc($sp)
/*  f0da3cc:	91f80638 */ 	lbu	$t8,0x638($t7)
/*  f0da3d0:	8cf90288 */ 	lw	$t9,0x288($a3)
/*  f0da3d4:	00036843 */ 	sra	$t5,$v1,0x1
/*  f0da3d8:	afb800b0 */ 	sw	$t8,0xb0($sp)
/*  f0da3dc:	25adffea */ 	addiu	$t5,$t5,-22
/*  f0da3e0:	8f240070 */ 	lw	$a0,0x70($t9)
/*  f0da3e4:	0fc54a28 */ 	jal	optionsGetShowZoomRange
/*  f0da3e8:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f0da3ec:	0002202b */ 	sltu	$a0,$zero,$v0
/*  f0da3f0:	8fa60100 */ 	lw	$a2,0x100($sp)
/*  f0da3f4:	1080000a */ 	beqz	$a0,.L0f0da420
/*  f0da3f8:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f0da3fc:	3c0e800a */ 	lui	$t6,%hi(g_Vars+0x288)
/*  f0da400:	8dcea248 */ 	lw	$t6,%lo(g_Vars+0x288)($t6)
/*  f0da404:	8dc40070 */ 	lw	$a0,0x70($t6)
/*  f0da408:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f0da40c:	0fc54a04 */ 	jal	optionsGetSightOnScreen
/*  f0da410:	afa60100 */ 	sw	$a2,0x100($sp)
/*  f0da414:	8fa60100 */ 	lw	$a2,0x100($sp)
/*  f0da418:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f0da41c:	0002202b */ 	sltu	$a0,$zero,$v0
.L0f0da420:
/*  f0da420:	a3a400af */ 	sb	$a0,0xaf($sp)
/*  f0da424:	afa60100 */ 	sw	$a2,0x100($sp)
/*  f0da428:	0fc2c536 */ 	jal	currentPlayerGetGunZoomFov
/*  f0da42c:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f0da430:	44803000 */ 	mtc1	$zero,$f6
/*  f0da434:	3c0f800a */ 	lui	$t7,%hi(g_Vars+0x284)
/*  f0da438:	8defa244 */ 	lw	$t7,%lo(g_Vars+0x284)($t7)
/*  f0da43c:	46060032 */ 	c.eq.s	$f0,$f6
/*  f0da440:	93a200af */ 	lbu	$v0,0xaf($sp)
/*  f0da444:	8fa60100 */ 	lw	$a2,0x100($sp)
/*  f0da448:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f0da44c:	45010008 */ 	bc1t	.L0f0da470
/*  f0da450:	c5e21848 */ 	lwc1	$f2,0x1848($t7)
/*  f0da454:	3c014270 */ 	lui	$at,0x4270
/*  f0da458:	44814000 */ 	mtc1	$at,$f8
/*  f0da45c:	00000000 */ 	nop
/*  f0da460:	46080032 */ 	c.eq.s	$f0,$f8
/*  f0da464:	00000000 */ 	nop
/*  f0da468:	45020008 */ 	bc1fl	.L0f0da48c
/*  f0da46c:	46020283 */ 	div.s	$f10,$f0,$f2
.L0f0da470:
/*  f0da470:	8fb800b0 */ 	lw	$t8,0xb0($sp)
/*  f0da474:	24010015 */ 	addiu	$at,$zero,0x15
/*  f0da478:	13010005 */ 	beq	$t8,$at,.L0f0da490
/*  f0da47c:	00000000 */ 	nop
/*  f0da480:	10000003 */ 	b	.L0f0da490
/*  f0da484:	00001025 */ 	or	$v0,$zero,$zero
/*  f0da488:	46020283 */ 	div.s	$f10,$f0,$f2
.L0f0da48c:
/*  f0da48c:	e7aa00cc */ 	swc1	$f10,0xcc($sp)
.L0f0da490:
/*  f0da490:	10400730 */ 	beqz	$v0,.L0f0dc154
/*  f0da494:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0da498:	0fc54d8a */ 	jal	text0f153628
/*  f0da49c:	afad00b4 */ 	sw	$t5,0xb4($sp)
/*  f0da4a0:	3c0500ff */ 	lui	$a1,0xff
/*  f0da4a4:	34a50028 */ 	ori	$a1,$a1,0x28
/*  f0da4a8:	0fc54df7 */ 	jal	textSetPrimColour
/*  f0da4ac:	00402025 */ 	or	$a0,$v0,$zero
/*  f0da4b0:	3c017f1b */ 	lui	$at,%hi(var7f1ade54)
/*  f0da4b4:	c420de54 */ 	lwc1	$f0,%lo(var7f1ade54)($at)
/*  f0da4b8:	c7a400cc */ 	lwc1	$f4,0xcc($sp)
/*  f0da4bc:	3c088008 */ 	lui	$t0,%hi(g_ScaleX)
/*  f0da4c0:	3c04800a */ 	lui	$a0,%hi(g_Vars)
/*  f0da4c4:	4600203c */ 	c.lt.s	$f4,$f0
/*  f0da4c8:	2508fac0 */ 	addiu	$t0,$t0,%lo(g_ScaleX)
/*  f0da4cc:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f0da4d0:	24849fc0 */ 	addiu	$a0,$a0,%lo(g_Vars)
/*  f0da4d4:	45020012 */ 	bc1fl	.L0f0da520
/*  f0da4d8:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f0da4dc:	8fa700f4 */ 	lw	$a3,0xf4($sp)
/*  f0da4e0:	0007c843 */ 	sra	$t9,$a3,0x1
/*  f0da4e4:	272effc4 */ 	addiu	$t6,$t9,-60
/*  f0da4e8:	448e3000 */ 	mtc1	$t6,$f6
/*  f0da4ec:	00000000 */ 	nop
/*  f0da4f0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0da4f4:	448d3000 */ 	mtc1	$t5,$f6
/*  f0da4f8:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0da4fc:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0da500:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0da504:	46004282 */ 	mul.s	$f10,$f8,$f0
/*  f0da508:	441f2000 */ 	mfc1	$ra,$f4
/*  f0da50c:	4600510d */ 	trunc.w.s	$f4,$f10
/*  f0da510:	440d2000 */ 	mfc1	$t5,$f4
/*  f0da514:	10000012 */ 	b	.L0f0da560
/*  f0da518:	8c8f006c */ 	lw	$t7,0x6c($a0)
/*  f0da51c:	8fa700f4 */ 	lw	$a3,0xf4($sp)
.L0f0da520:
/*  f0da520:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0da524:	00077043 */ 	sra	$t6,$a3,0x1
/*  f0da528:	25cfffc4 */ 	addiu	$t7,$t6,-60
/*  f0da52c:	448f3000 */ 	mtc1	$t7,$f6
/*  f0da530:	00000000 */ 	nop
/*  f0da534:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0da538:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f0da53c:	448d4000 */ 	mtc1	$t5,$f8
/*  f0da540:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f0da544:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0da548:	441f3000 */ 	mfc1	$ra,$f6
/*  f0da54c:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0da550:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0da554:	440d4000 */ 	mfc1	$t5,$f8
/*  f0da558:	00000000 */ 	nop
/*  f0da55c:	8c8f006c */ 	lw	$t7,0x6c($a0)
.L0f0da560:
/*  f0da560:	51e00004 */ 	beqzl	$t7,.L0f0da574
/*  f0da564:	00003025 */ 	or	$a2,$zero,$zero
/*  f0da568:	10000002 */ 	b	.L0f0da574
/*  f0da56c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f0da570:	00003025 */ 	or	$a2,$zero,$zero
.L0f0da574:
/*  f0da574:	8c980068 */ 	lw	$t8,0x68($a0)
/*  f0da578:	53000004 */ 	beqzl	$t8,.L0f0da58c
/*  f0da57c:	00001825 */ 	or	$v1,$zero,$zero
/*  f0da580:	10000002 */ 	b	.L0f0da58c
/*  f0da584:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f0da588:	00001825 */ 	or	$v1,$zero,$zero
.L0f0da58c:
/*  f0da58c:	8c8e0064 */ 	lw	$t6,0x64($a0)
/*  f0da590:	51c00004 */ 	beqzl	$t6,.L0f0da5a4
/*  f0da594:	00002825 */ 	or	$a1,$zero,$zero
/*  f0da598:	10000002 */ 	b	.L0f0da5a4
/*  f0da59c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0da5a0:	00002825 */ 	or	$a1,$zero,$zero
.L0f0da5a4:
/*  f0da5a4:	8c990070 */ 	lw	$t9,0x70($a0)
/*  f0da5a8:	53200004 */ 	beqzl	$t9,.L0f0da5bc
/*  f0da5ac:	00002025 */ 	or	$a0,$zero,$zero
/*  f0da5b0:	10000002 */ 	b	.L0f0da5bc
/*  f0da5b4:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f0da5b8:	00002025 */ 	or	$a0,$zero,$zero
.L0f0da5bc:
/*  f0da5bc:	00857821 */ 	addu	$t7,$a0,$a1
/*  f0da5c0:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f0da5c4:	03067021 */ 	addu	$t6,$t8,$a2
/*  f0da5c8:	29c10002 */ 	slti	$at,$t6,0x2
/*  f0da5cc:	14200003 */ 	bnez	$at,.L0f0da5dc
/*  f0da5d0:	24efffcf */ 	addiu	$t7,$a3,-49
/*  f0da5d4:	000dc840 */ 	sll	$t9,$t5,0x1
/*  f0da5d8:	03206825 */ 	or	$t5,$t9,$zero
.L0f0da5dc:
/*  f0da5dc:	448f5000 */ 	mtc1	$t7,$f10
/*  f0da5e0:	2be10005 */ 	slti	$at,$ra,0x5
/*  f0da5e4:	10200002 */ 	beqz	$at,.L0f0da5f0
/*  f0da5e8:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f0da5ec:	241f0005 */ 	addiu	$ra,$zero,0x5
.L0f0da5f0:
/*  f0da5f0:	29a10005 */ 	slti	$at,$t5,0x5
/*  f0da5f4:	50200003 */ 	beqzl	$at,.L0f0da604
/*  f0da5f8:	44872000 */ 	mtc1	$a3,$f4
/*  f0da5fc:	240d0005 */ 	addiu	$t5,$zero,0x5
/*  f0da600:	44872000 */ 	mtc1	$a3,$f4
.L0f0da604:
/*  f0da604:	c7a800cc */ 	lwc1	$f8,0xcc($sp)
/*  f0da608:	8fa300fc */ 	lw	$v1,0xfc($sp)
/*  f0da60c:	46802020 */ 	cvt.s.w	$f0,$f4
/*  f0da610:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f0da614:	0007c040 */ 	sll	$t8,$a3,0x1
/*  f0da618:	03037021 */ 	addu	$t6,$t8,$v1
/*  f0da61c:	25d9ffff */ 	addiu	$t9,$t6,-1
/*  f0da620:	44993000 */ 	mtc1	$t9,$f6
/*  f0da624:	24efffd0 */ 	addiu	$t7,$a3,-48
/*  f0da628:	8fb900dc */ 	lw	$t9,0xdc($sp)
/*  f0da62c:	46040281 */ 	sub.s	$f10,$f0,$f4
/*  f0da630:	3c013f80 */ 	lui	$at,0x3f80
/*  f0da634:	46803120 */ 	cvt.s.w	$f4,$f6
/*  f0da638:	460a2181 */ 	sub.s	$f6,$f4,$f10
/*  f0da63c:	448f2000 */ 	mtc1	$t7,$f4
/*  f0da640:	00000000 */ 	nop
/*  f0da644:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0da648:	e7a60050 */ 	swc1	$f6,0x50($sp)
/*  f0da64c:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0da650:	44834000 */ 	mtc1	$v1,$f8
/*  f0da654:	46040281 */ 	sub.s	$f10,$f0,$f4
/*  f0da658:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0da65c:	449f4000 */ 	mtc1	$ra,$f8
/*  f0da660:	00000000 */ 	nop
/*  f0da664:	46804320 */ 	cvt.s.w	$f12,$f8
/*  f0da668:	44994000 */ 	mtc1	$t9,$f8
/*  f0da66c:	460a2080 */ 	add.s	$f2,$f4,$f10
/*  f0da670:	46023381 */ 	sub.s	$f14,$f6,$f2
/*  f0da674:	460c703c */ 	c.lt.s	$f14,$f12
/*  f0da678:	00000000 */ 	nop
/*  f0da67c:	45020008 */ 	bc1fl	.L0f0da6a0
/*  f0da680:	8fae00f0 */ 	lw	$t6,0xf0($sp)
/*  f0da684:	4600710d */ 	trunc.w.s	$f4,$f14
/*  f0da688:	441f2000 */ 	mfc1	$ra,$f4
/*  f0da68c:	00000000 */ 	nop
/*  f0da690:	449f5000 */ 	mtc1	$ra,$f10
/*  f0da694:	00000000 */ 	nop
/*  f0da698:	46805320 */ 	cvt.s.w	$f12,$f10
/*  f0da69c:	8fae00f0 */ 	lw	$t6,0xf0($sp)
.L0f0da6a0:
/*  f0da6a0:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0da6a4:	c7aa00cc */ 	lwc1	$f10,0xcc($sp)
/*  f0da6a8:	448e3000 */ 	mtc1	$t6,$f6
/*  f0da6ac:	8faf00e8 */ 	lw	$t7,0xe8($sp)
/*  f0da6b0:	8fb800e0 */ 	lw	$t8,0xe0($sp)
/*  f0da6b4:	46803020 */ 	cvt.s.w	$f0,$f6
/*  f0da6b8:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0da6bc:	448f2000 */ 	mtc1	$t7,$f4
/*  f0da6c0:	8fae00f8 */ 	lw	$t6,0xf8($sp)
/*  f0da6c4:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f0da6c8:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0da6cc:	46083101 */ 	sub.s	$f4,$f6,$f8
/*  f0da6d0:	44983000 */ 	mtc1	$t8,$f6
/*  f0da6d4:	00000000 */ 	nop
/*  f0da6d8:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0da6dc:	e7a40048 */ 	swc1	$f4,0x48($sp)
/*  f0da6e0:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f0da6e4:	448e5000 */ 	mtc1	$t6,$f10
/*  f0da6e8:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f0da6ec:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f0da6f0:	448d5000 */ 	mtc1	$t5,$f10
/*  f0da6f4:	00000000 */ 	nop
/*  f0da6f8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f0da6fc:	46083380 */ 	add.s	$f14,$f6,$f8
/*  f0da700:	460e2401 */ 	sub.s	$f16,$f4,$f14
/*  f0da704:	4612803c */ 	c.lt.s	$f16,$f18
/*  f0da708:	00000000 */ 	nop
/*  f0da70c:	45020008 */ 	bc1fl	.L0f0da730
/*  f0da710:	460c1100 */ 	add.s	$f4,$f2,$f12
/*  f0da714:	4600818d */ 	trunc.w.s	$f6,$f16
/*  f0da718:	440d3000 */ 	mfc1	$t5,$f6
/*  f0da71c:	00000000 */ 	nop
/*  f0da720:	448d4000 */ 	mtc1	$t5,$f8
/*  f0da724:	00000000 */ 	nop
/*  f0da728:	468044a0 */ 	cvt.s.w	$f18,$f8
/*  f0da72c:	460c1100 */ 	add.s	$f4,$f2,$f12
.L0f0da730:
/*  f0da730:	44810000 */ 	mtc1	$at,$f0
/*  f0da734:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0da738:	3c03f600 */ 	lui	$v1,0xf600
/*  f0da73c:	46002281 */ 	sub.s	$f10,$f4,$f0
/*  f0da740:	00402025 */ 	or	$a0,$v0,$zero
/*  f0da744:	24460008 */ 	addiu	$a2,$v0,0x8
/*  f0da748:	46007200 */ 	add.s	$f8,$f14,$f0
/*  f0da74c:	46005180 */ 	add.s	$f6,$f10,$f0
/*  f0da750:	444ff800 */ 	cfc1	$t7,$31
/*  f0da754:	44caf800 */ 	ctc1	$t2,$31
/*  f0da758:	e7a6001c */ 	swc1	$f6,0x1c($sp)
/*  f0da75c:	46004124 */ 	cvt.w.s	$f4,$f8
/*  f0da760:	444af800 */ 	cfc1	$t2,$31
/*  f0da764:	00000000 */ 	nop
/*  f0da768:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0da76c:	11400012 */ 	beqz	$t2,.L0f0da7b8
/*  f0da770:	3c014f00 */ 	lui	$at,0x4f00
/*  f0da774:	44812000 */ 	mtc1	$at,$f4
/*  f0da778:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0da77c:	46044101 */ 	sub.s	$f4,$f8,$f4
/*  f0da780:	44caf800 */ 	ctc1	$t2,$31
/*  f0da784:	00000000 */ 	nop
/*  f0da788:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0da78c:	444af800 */ 	cfc1	$t2,$31
/*  f0da790:	00000000 */ 	nop
/*  f0da794:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0da798:	15400005 */ 	bnez	$t2,.L0f0da7b0
/*  f0da79c:	00000000 */ 	nop
/*  f0da7a0:	440a2000 */ 	mfc1	$t2,$f4
/*  f0da7a4:	3c018000 */ 	lui	$at,0x8000
/*  f0da7a8:	10000007 */ 	b	.L0f0da7c8
/*  f0da7ac:	01415025 */ 	or	$t2,$t2,$at
.L0f0da7b0:
/*  f0da7b0:	10000005 */ 	b	.L0f0da7c8
/*  f0da7b4:	240affff */ 	addiu	$t2,$zero,-1
.L0f0da7b8:
/*  f0da7b8:	440a2000 */ 	mfc1	$t2,$f4
/*  f0da7bc:	00000000 */ 	nop
/*  f0da7c0:	0540fffb */ 	bltz	$t2,.L0f0da7b0
/*  f0da7c4:	00000000 */ 	nop
.L0f0da7c8:
/*  f0da7c8:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0da7cc:	44cff800 */ 	ctc1	$t7,$31
/*  f0da7d0:	315803ff */ 	andi	$t8,$t2,0x3ff
/*  f0da7d4:	44995000 */ 	mtc1	$t9,$f10
/*  f0da7d8:	00185080 */ 	sll	$t2,$t8,0x2
/*  f0da7dc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0da7e0:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0da7e4:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f0da7e8:	444ff800 */ 	cfc1	$t7,$31
/*  f0da7ec:	44d8f800 */ 	ctc1	$t8,$31
/*  f0da7f0:	00000000 */ 	nop
/*  f0da7f4:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0da7f8:	4458f800 */ 	cfc1	$t8,$31
/*  f0da7fc:	00000000 */ 	nop
/*  f0da800:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0da804:	13000012 */ 	beqz	$t8,.L0f0da850
/*  f0da808:	3c014f00 */ 	lui	$at,0x4f00
/*  f0da80c:	44815000 */ 	mtc1	$at,$f10
/*  f0da810:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0da814:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0da818:	44d8f800 */ 	ctc1	$t8,$31
/*  f0da81c:	00000000 */ 	nop
/*  f0da820:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0da824:	4458f800 */ 	cfc1	$t8,$31
/*  f0da828:	00000000 */ 	nop
/*  f0da82c:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0da830:	17000005 */ 	bnez	$t8,.L0f0da848
/*  f0da834:	00000000 */ 	nop
/*  f0da838:	44185000 */ 	mfc1	$t8,$f10
/*  f0da83c:	3c018000 */ 	lui	$at,0x8000
/*  f0da840:	10000007 */ 	b	.L0f0da860
/*  f0da844:	0301c025 */ 	or	$t8,$t8,$at
.L0f0da848:
/*  f0da848:	10000005 */ 	b	.L0f0da860
/*  f0da84c:	2418ffff */ 	addiu	$t8,$zero,-1
.L0f0da850:
/*  f0da850:	44185000 */ 	mfc1	$t8,$f10
/*  f0da854:	00000000 */ 	nop
/*  f0da858:	0700fffb */ 	bltz	$t8,.L0f0da848
/*  f0da85c:	00000000 */ 	nop
.L0f0da860:
/*  f0da860:	44cff800 */ 	ctc1	$t7,$31
/*  f0da864:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0da868:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0da86c:	46001400 */ 	add.s	$f16,$f2,$f0
/*  f0da870:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0da874:	03237825 */ 	or	$t7,$t9,$v1
/*  f0da878:	01eac025 */ 	or	$t8,$t7,$t2
/*  f0da87c:	444ef800 */ 	cfc1	$t6,$31
/*  f0da880:	44c7f800 */ 	ctc1	$a3,$31
/*  f0da884:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f0da888:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0da88c:	460071a4 */ 	cvt.w.s	$f6,$f14
/*  f0da890:	4447f800 */ 	cfc1	$a3,$31
/*  f0da894:	00000000 */ 	nop
/*  f0da898:	30e70078 */ 	andi	$a3,$a3,0x78
/*  f0da89c:	10e00012 */ 	beqz	$a3,.L0f0da8e8
/*  f0da8a0:	3c014f00 */ 	lui	$at,0x4f00
/*  f0da8a4:	44813000 */ 	mtc1	$at,$f6
/*  f0da8a8:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f0da8ac:	46067181 */ 	sub.s	$f6,$f14,$f6
/*  f0da8b0:	44c7f800 */ 	ctc1	$a3,$31
/*  f0da8b4:	00000000 */ 	nop
/*  f0da8b8:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0da8bc:	4447f800 */ 	cfc1	$a3,$31
/*  f0da8c0:	00000000 */ 	nop
/*  f0da8c4:	30e70078 */ 	andi	$a3,$a3,0x78
/*  f0da8c8:	14e00005 */ 	bnez	$a3,.L0f0da8e0
/*  f0da8cc:	00000000 */ 	nop
/*  f0da8d0:	44073000 */ 	mfc1	$a3,$f6
/*  f0da8d4:	3c018000 */ 	lui	$at,0x8000
/*  f0da8d8:	10000007 */ 	b	.L0f0da8f8
/*  f0da8dc:	00e13825 */ 	or	$a3,$a3,$at
.L0f0da8e0:
/*  f0da8e0:	10000005 */ 	b	.L0f0da8f8
/*  f0da8e4:	2407ffff */ 	addiu	$a3,$zero,-1
.L0f0da8e8:
/*  f0da8e8:	44073000 */ 	mfc1	$a3,$f6
/*  f0da8ec:	00000000 */ 	nop
/*  f0da8f0:	04e0fffb */ 	bltz	$a3,.L0f0da8e0
/*  f0da8f4:	00000000 */ 	nop
.L0f0da8f8:
/*  f0da8f8:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f0da8fc:	44cef800 */ 	ctc1	$t6,$31
/*  f0da900:	30f903ff */ 	andi	$t9,$a3,0x3ff
/*  f0da904:	44984000 */ 	mtc1	$t8,$f8
/*  f0da908:	00193880 */ 	sll	$a3,$t9,0x2
/*  f0da90c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0da910:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0da914:	46048282 */ 	mul.s	$f10,$f16,$f4
/*  f0da918:	444ef800 */ 	cfc1	$t6,$31
/*  f0da91c:	44d9f800 */ 	ctc1	$t9,$31
/*  f0da920:	00000000 */ 	nop
/*  f0da924:	460051a4 */ 	cvt.w.s	$f6,$f10
/*  f0da928:	4459f800 */ 	cfc1	$t9,$31
/*  f0da92c:	00000000 */ 	nop
/*  f0da930:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0da934:	13200012 */ 	beqz	$t9,.L0f0da980
/*  f0da938:	3c014f00 */ 	lui	$at,0x4f00
/*  f0da93c:	44813000 */ 	mtc1	$at,$f6
/*  f0da940:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0da944:	46065181 */ 	sub.s	$f6,$f10,$f6
/*  f0da948:	44d9f800 */ 	ctc1	$t9,$31
/*  f0da94c:	00000000 */ 	nop
/*  f0da950:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0da954:	4459f800 */ 	cfc1	$t9,$31
/*  f0da958:	00000000 */ 	nop
/*  f0da95c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0da960:	17200005 */ 	bnez	$t9,.L0f0da978
/*  f0da964:	00000000 */ 	nop
/*  f0da968:	44193000 */ 	mfc1	$t9,$f6
/*  f0da96c:	3c018000 */ 	lui	$at,0x8000
/*  f0da970:	10000007 */ 	b	.L0f0da990
/*  f0da974:	0321c825 */ 	or	$t9,$t9,$at
.L0f0da978:
/*  f0da978:	10000005 */ 	b	.L0f0da990
/*  f0da97c:	2419ffff */ 	addiu	$t9,$zero,-1
.L0f0da980:
/*  f0da980:	44193000 */ 	mfc1	$t9,$f6
/*  f0da984:	00000000 */ 	nop
/*  f0da988:	0720fffb */ 	bltz	$t9,.L0f0da978
/*  f0da98c:	00000000 */ 	nop
.L0f0da990:
/*  f0da990:	44cef800 */ 	ctc1	$t6,$31
/*  f0da994:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0da998:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0da99c:	46127200 */ 	add.s	$f8,$f14,$f18
/*  f0da9a0:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0da9a4:	03077025 */ 	or	$t6,$t8,$a3
/*  f0da9a8:	00c02825 */ 	or	$a1,$a2,$zero
/*  f0da9ac:	46004101 */ 	sub.s	$f4,$f8,$f0
/*  f0da9b0:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f0da9b4:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0da9b8:	46002280 */ 	add.s	$f10,$f4,$f0
/*  f0da9bc:	4459f800 */ 	cfc1	$t9,$31
/*  f0da9c0:	44cbf800 */ 	ctc1	$t3,$31
/*  f0da9c4:	00000000 */ 	nop
/*  f0da9c8:	460051a4 */ 	cvt.w.s	$f6,$f10
/*  f0da9cc:	444bf800 */ 	cfc1	$t3,$31
/*  f0da9d0:	00000000 */ 	nop
/*  f0da9d4:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0da9d8:	11600012 */ 	beqz	$t3,.L0f0daa24
/*  f0da9dc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0da9e0:	44813000 */ 	mtc1	$at,$f6
/*  f0da9e4:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0da9e8:	46065181 */ 	sub.s	$f6,$f10,$f6
/*  f0da9ec:	44cbf800 */ 	ctc1	$t3,$31
/*  f0da9f0:	00000000 */ 	nop
/*  f0da9f4:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0da9f8:	444bf800 */ 	cfc1	$t3,$31
/*  f0da9fc:	00000000 */ 	nop
/*  f0daa00:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0daa04:	15600005 */ 	bnez	$t3,.L0f0daa1c
/*  f0daa08:	00000000 */ 	nop
/*  f0daa0c:	440b3000 */ 	mfc1	$t3,$f6
/*  f0daa10:	3c018000 */ 	lui	$at,0x8000
/*  f0daa14:	10000007 */ 	b	.L0f0daa34
/*  f0daa18:	01615825 */ 	or	$t3,$t3,$at
.L0f0daa1c:
/*  f0daa1c:	10000005 */ 	b	.L0f0daa34
/*  f0daa20:	240bffff */ 	addiu	$t3,$zero,-1
.L0f0daa24:
/*  f0daa24:	440b3000 */ 	mfc1	$t3,$f6
/*  f0daa28:	00000000 */ 	nop
/*  f0daa2c:	0560fffb */ 	bltz	$t3,.L0f0daa1c
/*  f0daa30:	00000000 */ 	nop
.L0f0daa34:
/*  f0daa34:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0daa38:	44d9f800 */ 	ctc1	$t9,$31
/*  f0daa3c:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f0daa40:	448e4000 */ 	mtc1	$t6,$f8
/*  f0daa44:	000f5880 */ 	sll	$t3,$t7,0x2
/*  f0daa48:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0daa4c:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0daa50:	46048282 */ 	mul.s	$f10,$f16,$f4
/*  f0daa54:	4459f800 */ 	cfc1	$t9,$31
/*  f0daa58:	44cff800 */ 	ctc1	$t7,$31
/*  f0daa5c:	00000000 */ 	nop
/*  f0daa60:	460051a4 */ 	cvt.w.s	$f6,$f10
/*  f0daa64:	444ff800 */ 	cfc1	$t7,$31
/*  f0daa68:	00000000 */ 	nop
/*  f0daa6c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0daa70:	11e00012 */ 	beqz	$t7,.L0f0daabc
/*  f0daa74:	3c014f00 */ 	lui	$at,0x4f00
/*  f0daa78:	44813000 */ 	mtc1	$at,$f6
/*  f0daa7c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0daa80:	46065181 */ 	sub.s	$f6,$f10,$f6
/*  f0daa84:	44cff800 */ 	ctc1	$t7,$31
/*  f0daa88:	00000000 */ 	nop
/*  f0daa8c:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0daa90:	444ff800 */ 	cfc1	$t7,$31
/*  f0daa94:	00000000 */ 	nop
/*  f0daa98:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0daa9c:	15e00005 */ 	bnez	$t7,.L0f0daab4
/*  f0daaa0:	00000000 */ 	nop
/*  f0daaa4:	440f3000 */ 	mfc1	$t7,$f6
/*  f0daaa8:	3c018000 */ 	lui	$at,0x8000
/*  f0daaac:	10000007 */ 	b	.L0f0daacc
/*  f0daab0:	01e17825 */ 	or	$t7,$t7,$at
.L0f0daab4:
/*  f0daab4:	10000005 */ 	b	.L0f0daacc
/*  f0daab8:	240fffff */ 	addiu	$t7,$zero,-1
.L0f0daabc:
/*  f0daabc:	440f3000 */ 	mfc1	$t7,$f6
/*  f0daac0:	00000000 */ 	nop
/*  f0daac4:	05e0fffb */ 	bltz	$t7,.L0f0daab4
/*  f0daac8:	00000000 */ 	nop
.L0f0daacc:
/*  f0daacc:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0daad0:	44d9f800 */ 	ctc1	$t9,$31
/*  f0daad4:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0daad8:	01c3c825 */ 	or	$t9,$t6,$v1
/*  f0daadc:	032b7825 */ 	or	$t7,$t9,$t3
/*  f0daae0:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f0daae4:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f0daae8:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0daaec:	44984000 */ 	mtc1	$t8,$f8
/*  f0daaf0:	00000000 */ 	nop
/*  f0daaf4:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0daaf8:	46041282 */ 	mul.s	$f10,$f2,$f4
/*  f0daafc:	444ef800 */ 	cfc1	$t6,$31
/*  f0dab00:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dab04:	00000000 */ 	nop
/*  f0dab08:	460051a4 */ 	cvt.w.s	$f6,$f10
/*  f0dab0c:	4459f800 */ 	cfc1	$t9,$31
/*  f0dab10:	00000000 */ 	nop
/*  f0dab14:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0dab18:	13200012 */ 	beqz	$t9,.L0f0dab64
/*  f0dab1c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dab20:	44813000 */ 	mtc1	$at,$f6
/*  f0dab24:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0dab28:	46065181 */ 	sub.s	$f6,$f10,$f6
/*  f0dab2c:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dab30:	00000000 */ 	nop
/*  f0dab34:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0dab38:	4459f800 */ 	cfc1	$t9,$31
/*  f0dab3c:	00000000 */ 	nop
/*  f0dab40:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0dab44:	17200005 */ 	bnez	$t9,.L0f0dab5c
/*  f0dab48:	00000000 */ 	nop
/*  f0dab4c:	44193000 */ 	mfc1	$t9,$f6
/*  f0dab50:	3c018000 */ 	lui	$at,0x8000
/*  f0dab54:	10000007 */ 	b	.L0f0dab74
/*  f0dab58:	0321c825 */ 	or	$t9,$t9,$at
.L0f0dab5c:
/*  f0dab5c:	10000005 */ 	b	.L0f0dab74
/*  f0dab60:	2419ffff */ 	addiu	$t9,$zero,-1
.L0f0dab64:
/*  f0dab64:	44193000 */ 	mfc1	$t9,$f6
/*  f0dab68:	00000000 */ 	nop
/*  f0dab6c:	0720fffb */ 	bltz	$t9,.L0f0dab5c
/*  f0dab70:	00000000 */ 	nop
.L0f0dab74:
/*  f0dab74:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0dab78:	44cef800 */ 	ctc1	$t6,$31
/*  f0dab7c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0dab80:	03077025 */ 	or	$t6,$t8,$a3
/*  f0dab84:	acae0004 */ 	sw	$t6,0x4($a1)
/*  f0dab88:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0dab8c:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f0dab90:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dab94:	44993000 */ 	mtc1	$t9,$f6
/*  f0dab98:	46004101 */ 	sub.s	$f4,$f8,$f0
/*  f0dab9c:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0daba0:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0daba4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0daba8:	46002280 */ 	add.s	$f10,$f4,$f0
/*  f0dabac:	46085102 */ 	mul.s	$f4,$f10,$f8
/*  f0dabb0:	e7aa0028 */ 	swc1	$f10,0x28($sp)
/*  f0dabb4:	444ff800 */ 	cfc1	$t7,$31
/*  f0dabb8:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dabbc:	00000000 */ 	nop
/*  f0dabc0:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f0dabc4:	4458f800 */ 	cfc1	$t8,$31
/*  f0dabc8:	00000000 */ 	nop
/*  f0dabcc:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dabd0:	13000012 */ 	beqz	$t8,.L0f0dac1c
/*  f0dabd4:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dabd8:	44813000 */ 	mtc1	$at,$f6
/*  f0dabdc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dabe0:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f0dabe4:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dabe8:	00000000 */ 	nop
/*  f0dabec:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0dabf0:	4458f800 */ 	cfc1	$t8,$31
/*  f0dabf4:	00000000 */ 	nop
/*  f0dabf8:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dabfc:	17000005 */ 	bnez	$t8,.L0f0dac14
/*  f0dac00:	00000000 */ 	nop
/*  f0dac04:	44183000 */ 	mfc1	$t8,$f6
/*  f0dac08:	3c018000 */ 	lui	$at,0x8000
/*  f0dac0c:	10000007 */ 	b	.L0f0dac2c
/*  f0dac10:	0301c025 */ 	or	$t8,$t8,$at
.L0f0dac14:
/*  f0dac14:	10000005 */ 	b	.L0f0dac2c
/*  f0dac18:	2418ffff */ 	addiu	$t8,$zero,-1
.L0f0dac1c:
/*  f0dac1c:	44183000 */ 	mfc1	$t8,$f6
/*  f0dac20:	00000000 */ 	nop
/*  f0dac24:	0700fffb */ 	bltz	$t8,.L0f0dac14
/*  f0dac28:	00000000 */ 	nop
.L0f0dac2c:
/*  f0dac2c:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0dac30:	44cff800 */ 	ctc1	$t7,$31
/*  f0dac34:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0dac38:	03237825 */ 	or	$t7,$t9,$v1
/*  f0dac3c:	01eac025 */ 	or	$t8,$t7,$t2
/*  f0dac40:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0dac44:	c7aa0050 */ 	lwc1	$f10,0x50($sp)
/*  f0dac48:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0dac4c:	3c014000 */ 	lui	$at,0x4000
/*  f0dac50:	460c5201 */ 	sub.s	$f8,$f10,$f12
/*  f0dac54:	44812000 */ 	mtc1	$at,$f4
/*  f0dac58:	448e5000 */ 	mtc1	$t6,$f10
/*  f0dac5c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dac60:	46044180 */ 	add.s	$f6,$f8,$f4
/*  f0dac64:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0dac68:	e7a60030 */ 	swc1	$f6,0x30($sp)
/*  f0dac6c:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f0dac70:	4459f800 */ 	cfc1	$t9,$31
/*  f0dac74:	44cff800 */ 	ctc1	$t7,$31
/*  f0dac78:	00000000 */ 	nop
/*  f0dac7c:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0dac80:	444ff800 */ 	cfc1	$t7,$31
/*  f0dac84:	00000000 */ 	nop
/*  f0dac88:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dac8c:	11e00012 */ 	beqz	$t7,.L0f0dacd8
/*  f0dac90:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dac94:	44815000 */ 	mtc1	$at,$f10
/*  f0dac98:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dac9c:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0daca0:	44cff800 */ 	ctc1	$t7,$31
/*  f0daca4:	00000000 */ 	nop
/*  f0daca8:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dacac:	444ff800 */ 	cfc1	$t7,$31
/*  f0dacb0:	00000000 */ 	nop
/*  f0dacb4:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dacb8:	15e00005 */ 	bnez	$t7,.L0f0dacd0
/*  f0dacbc:	00000000 */ 	nop
/*  f0dacc0:	440f5000 */ 	mfc1	$t7,$f10
/*  f0dacc4:	3c018000 */ 	lui	$at,0x8000
/*  f0dacc8:	10000007 */ 	b	.L0f0dace8
/*  f0daccc:	01e17825 */ 	or	$t7,$t7,$at
.L0f0dacd0:
/*  f0dacd0:	10000005 */ 	b	.L0f0dace8
/*  f0dacd4:	240fffff */ 	addiu	$t7,$zero,-1
.L0f0dacd8:
/*  f0dacd8:	440f5000 */ 	mfc1	$t7,$f10
/*  f0dacdc:	00000000 */ 	nop
/*  f0dace0:	05e0fffb */ 	bltz	$t7,.L0f0dacd0
/*  f0dace4:	00000000 */ 	nop
.L0f0dace8:
/*  f0dace8:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0dacec:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dacf0:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0dacf4:	01c7c825 */ 	or	$t9,$t6,$a3
/*  f0dacf8:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0dacfc:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0dad00:	c7a60050 */ 	lwc1	$f6,0x50($sp)
/*  f0dad04:	e7ae004c */ 	swc1	$f14,0x4c($sp)
/*  f0dad08:	448f4000 */ 	mtc1	$t7,$f8
/*  f0dad0c:	46003380 */ 	add.s	$f14,$f6,$f0
/*  f0dad10:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dad14:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0dad18:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0dad1c:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0dad20:	46047282 */ 	mul.s	$f10,$f14,$f4
/*  f0dad24:	4458f800 */ 	cfc1	$t8,$31
/*  f0dad28:	44cef800 */ 	ctc1	$t6,$31
/*  f0dad2c:	00000000 */ 	nop
/*  f0dad30:	460051a4 */ 	cvt.w.s	$f6,$f10
/*  f0dad34:	444ef800 */ 	cfc1	$t6,$31
/*  f0dad38:	00000000 */ 	nop
/*  f0dad3c:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dad40:	11c00012 */ 	beqz	$t6,.L0f0dad8c
/*  f0dad44:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dad48:	44813000 */ 	mtc1	$at,$f6
/*  f0dad4c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dad50:	46065181 */ 	sub.s	$f6,$f10,$f6
/*  f0dad54:	44cef800 */ 	ctc1	$t6,$31
/*  f0dad58:	00000000 */ 	nop
/*  f0dad5c:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0dad60:	444ef800 */ 	cfc1	$t6,$31
/*  f0dad64:	00000000 */ 	nop
/*  f0dad68:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dad6c:	15c00005 */ 	bnez	$t6,.L0f0dad84
/*  f0dad70:	00000000 */ 	nop
/*  f0dad74:	440e3000 */ 	mfc1	$t6,$f6
/*  f0dad78:	3c018000 */ 	lui	$at,0x8000
/*  f0dad7c:	10000007 */ 	b	.L0f0dad9c
/*  f0dad80:	01c17025 */ 	or	$t6,$t6,$at
.L0f0dad84:
/*  f0dad84:	10000005 */ 	b	.L0f0dad9c
/*  f0dad88:	240effff */ 	addiu	$t6,$zero,-1
.L0f0dad8c:
/*  f0dad8c:	440e3000 */ 	mfc1	$t6,$f6
/*  f0dad90:	00000000 */ 	nop
/*  f0dad94:	05c0fffb */ 	bltz	$t6,.L0f0dad84
/*  f0dad98:	00000000 */ 	nop
.L0f0dad9c:
/*  f0dad9c:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0dada0:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dada4:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0dada8:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0dadac:	030b7025 */ 	or	$t6,$t8,$t3
/*  f0dadb0:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f0dadb4:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0dadb8:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f0dadbc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dadc0:	44992000 */ 	mtc1	$t9,$f4
/*  f0dadc4:	00000000 */ 	nop
/*  f0dadc8:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0dadcc:	460a4182 */ 	mul.s	$f6,$f8,$f10
/*  f0dadd0:	444ff800 */ 	cfc1	$t7,$31
/*  f0dadd4:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dadd8:	00000000 */ 	nop
/*  f0daddc:	46003124 */ 	cvt.w.s	$f4,$f6
/*  f0dade0:	4458f800 */ 	cfc1	$t8,$31
/*  f0dade4:	00000000 */ 	nop
/*  f0dade8:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dadec:	13000012 */ 	beqz	$t8,.L0f0dae38
/*  f0dadf0:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dadf4:	44812000 */ 	mtc1	$at,$f4
/*  f0dadf8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dadfc:	46043101 */ 	sub.s	$f4,$f6,$f4
/*  f0dae00:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dae04:	00000000 */ 	nop
/*  f0dae08:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0dae0c:	4458f800 */ 	cfc1	$t8,$31
/*  f0dae10:	00000000 */ 	nop
/*  f0dae14:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dae18:	17000005 */ 	bnez	$t8,.L0f0dae30
/*  f0dae1c:	00000000 */ 	nop
/*  f0dae20:	44182000 */ 	mfc1	$t8,$f4
/*  f0dae24:	3c018000 */ 	lui	$at,0x8000
/*  f0dae28:	10000007 */ 	b	.L0f0dae48
/*  f0dae2c:	0301c025 */ 	or	$t8,$t8,$at
.L0f0dae30:
/*  f0dae30:	10000005 */ 	b	.L0f0dae48
/*  f0dae34:	2418ffff */ 	addiu	$t8,$zero,-1
.L0f0dae38:
/*  f0dae38:	44182000 */ 	mfc1	$t8,$f4
/*  f0dae3c:	00000000 */ 	nop
/*  f0dae40:	0700fffb */ 	bltz	$t8,.L0f0dae30
/*  f0dae44:	00000000 */ 	nop
.L0f0dae48:
/*  f0dae48:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0dae4c:	44cff800 */ 	ctc1	$t7,$31
/*  f0dae50:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0dae54:	03277825 */ 	or	$t7,$t9,$a3
/*  f0dae58:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0dae5c:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f0dae60:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0dae64:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0dae68:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f0dae6c:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0dae70:	4458f800 */ 	cfc1	$t8,$31
/*  f0dae74:	44c5f800 */ 	ctc1	$a1,$31
/*  f0dae78:	00000000 */ 	nop
/*  f0dae7c:	460051a4 */ 	cvt.w.s	$f6,$f10
/*  f0dae80:	4445f800 */ 	cfc1	$a1,$31
/*  f0dae84:	00000000 */ 	nop
/*  f0dae88:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f0dae8c:	10a00012 */ 	beqz	$a1,.L0f0daed8
/*  f0dae90:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dae94:	44813000 */ 	mtc1	$at,$f6
/*  f0dae98:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f0dae9c:	46065181 */ 	sub.s	$f6,$f10,$f6
/*  f0daea0:	44c5f800 */ 	ctc1	$a1,$31
/*  f0daea4:	00000000 */ 	nop
/*  f0daea8:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0daeac:	4445f800 */ 	cfc1	$a1,$31
/*  f0daeb0:	00000000 */ 	nop
/*  f0daeb4:	30a50078 */ 	andi	$a1,$a1,0x78
/*  f0daeb8:	14a00005 */ 	bnez	$a1,.L0f0daed0
/*  f0daebc:	00000000 */ 	nop
/*  f0daec0:	44053000 */ 	mfc1	$a1,$f6
/*  f0daec4:	3c018000 */ 	lui	$at,0x8000
/*  f0daec8:	10000007 */ 	b	.L0f0daee8
/*  f0daecc:	00a12825 */ 	or	$a1,$a1,$at
.L0f0daed0:
/*  f0daed0:	10000005 */ 	b	.L0f0daee8
/*  f0daed4:	2405ffff */ 	addiu	$a1,$zero,-1
.L0f0daed8:
/*  f0daed8:	44053000 */ 	mfc1	$a1,$f6
/*  f0daedc:	00000000 */ 	nop
/*  f0daee0:	04a0fffb */ 	bltz	$a1,.L0f0daed0
/*  f0daee4:	00000000 */ 	nop
.L0f0daee8:
/*  f0daee8:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0daeec:	44d8f800 */ 	ctc1	$t8,$31
/*  f0daef0:	c7a4001c */ 	lwc1	$f4,0x1c($sp)
/*  f0daef4:	448f4000 */ 	mtc1	$t7,$f8
/*  f0daef8:	30ae03ff */ 	andi	$t6,$a1,0x3ff
/*  f0daefc:	000e2880 */ 	sll	$a1,$t6,0x2
/*  f0daf00:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0daf04:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0daf08:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f0daf0c:	4458f800 */ 	cfc1	$t8,$31
/*  f0daf10:	44cef800 */ 	ctc1	$t6,$31
/*  f0daf14:	00000000 */ 	nop
/*  f0daf18:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f0daf1c:	444ef800 */ 	cfc1	$t6,$31
/*  f0daf20:	00000000 */ 	nop
/*  f0daf24:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0daf28:	11c00012 */ 	beqz	$t6,.L0f0daf74
/*  f0daf2c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0daf30:	44814000 */ 	mtc1	$at,$f8
/*  f0daf34:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0daf38:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f0daf3c:	44cef800 */ 	ctc1	$t6,$31
/*  f0daf40:	00000000 */ 	nop
/*  f0daf44:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0daf48:	444ef800 */ 	cfc1	$t6,$31
/*  f0daf4c:	00000000 */ 	nop
/*  f0daf50:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0daf54:	15c00005 */ 	bnez	$t6,.L0f0daf6c
/*  f0daf58:	00000000 */ 	nop
/*  f0daf5c:	440e4000 */ 	mfc1	$t6,$f8
/*  f0daf60:	3c018000 */ 	lui	$at,0x8000
/*  f0daf64:	10000007 */ 	b	.L0f0daf84
/*  f0daf68:	01c17025 */ 	or	$t6,$t6,$at
.L0f0daf6c:
/*  f0daf6c:	10000005 */ 	b	.L0f0daf84
/*  f0daf70:	240effff */ 	addiu	$t6,$zero,-1
.L0f0daf74:
/*  f0daf74:	440e4000 */ 	mfc1	$t6,$f8
/*  f0daf78:	00000000 */ 	nop
/*  f0daf7c:	05c0fffb */ 	bltz	$t6,.L0f0daf6c
/*  f0daf80:	00000000 */ 	nop
.L0f0daf84:
/*  f0daf84:	44d8f800 */ 	ctc1	$t8,$31
/*  f0daf88:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0daf8c:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0daf90:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0daf94:	03057025 */ 	or	$t6,$t8,$a1
/*  f0daf98:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0daf9c:	4459f800 */ 	cfc1	$t9,$31
/*  f0dafa0:	44c9f800 */ 	ctc1	$t1,$31
/*  f0dafa4:	c7a40048 */ 	lwc1	$f4,0x48($sp)
/*  f0dafa8:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0dafac:	4449f800 */ 	cfc1	$t1,$31
/*  f0dafb0:	00000000 */ 	nop
/*  f0dafb4:	31290078 */ 	andi	$t1,$t1,0x78
/*  f0dafb8:	11200012 */ 	beqz	$t1,.L0f0db004
/*  f0dafbc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dafc0:	44815000 */ 	mtc1	$at,$f10
/*  f0dafc4:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f0dafc8:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0dafcc:	44c9f800 */ 	ctc1	$t1,$31
/*  f0dafd0:	00000000 */ 	nop
/*  f0dafd4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dafd8:	4449f800 */ 	cfc1	$t1,$31
/*  f0dafdc:	00000000 */ 	nop
/*  f0dafe0:	31290078 */ 	andi	$t1,$t1,0x78
/*  f0dafe4:	15200005 */ 	bnez	$t1,.L0f0daffc
/*  f0dafe8:	00000000 */ 	nop
/*  f0dafec:	44095000 */ 	mfc1	$t1,$f10
/*  f0daff0:	3c018000 */ 	lui	$at,0x8000
/*  f0daff4:	10000007 */ 	b	.L0f0db014
/*  f0daff8:	01214825 */ 	or	$t1,$t1,$at
.L0f0daffc:
/*  f0daffc:	10000005 */ 	b	.L0f0db014
/*  f0db000:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f0db004:
/*  f0db004:	44095000 */ 	mfc1	$t1,$f10
/*  f0db008:	00000000 */ 	nop
/*  f0db00c:	0520fffb */ 	bltz	$t1,.L0f0daffc
/*  f0db010:	00000000 */ 	nop
.L0f0db014:
/*  f0db014:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0db018:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db01c:	312f03ff */ 	andi	$t7,$t1,0x3ff
/*  f0db020:	448e3000 */ 	mtc1	$t6,$f6
/*  f0db024:	000f4880 */ 	sll	$t1,$t7,0x2
/*  f0db028:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0db02c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0db030:	46088102 */ 	mul.s	$f4,$f16,$f8
/*  f0db034:	4459f800 */ 	cfc1	$t9,$31
/*  f0db038:	44cff800 */ 	ctc1	$t7,$31
/*  f0db03c:	00000000 */ 	nop
/*  f0db040:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0db044:	444ff800 */ 	cfc1	$t7,$31
/*  f0db048:	00000000 */ 	nop
/*  f0db04c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0db050:	11e00012 */ 	beqz	$t7,.L0f0db09c
/*  f0db054:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db058:	44815000 */ 	mtc1	$at,$f10
/*  f0db05c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0db060:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0db064:	44cff800 */ 	ctc1	$t7,$31
/*  f0db068:	00000000 */ 	nop
/*  f0db06c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0db070:	444ff800 */ 	cfc1	$t7,$31
/*  f0db074:	00000000 */ 	nop
/*  f0db078:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0db07c:	15e00005 */ 	bnez	$t7,.L0f0db094
/*  f0db080:	00000000 */ 	nop
/*  f0db084:	440f5000 */ 	mfc1	$t7,$f10
/*  f0db088:	3c018000 */ 	lui	$at,0x8000
/*  f0db08c:	10000007 */ 	b	.L0f0db0ac
/*  f0db090:	01e17825 */ 	or	$t7,$t7,$at
.L0f0db094:
/*  f0db094:	10000005 */ 	b	.L0f0db0ac
/*  f0db098:	240fffff */ 	addiu	$t7,$zero,-1
.L0f0db09c:
/*  f0db09c:	440f5000 */ 	mfc1	$t7,$f10
/*  f0db0a0:	00000000 */ 	nop
/*  f0db0a4:	05e0fffb */ 	bltz	$t7,.L0f0db094
/*  f0db0a8:	00000000 */ 	nop
.L0f0db0ac:
/*  f0db0ac:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0db0b0:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db0b4:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0db0b8:	01c9c825 */ 	or	$t9,$t6,$t1
/*  f0db0bc:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0db0c0:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0db0c4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db0c8:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0db0cc:	448f3000 */ 	mtc1	$t7,$f6
/*  f0db0d0:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0db0d4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0db0d8:	46088102 */ 	mul.s	$f4,$f16,$f8
/*  f0db0dc:	4458f800 */ 	cfc1	$t8,$31
/*  f0db0e0:	44cef800 */ 	ctc1	$t6,$31
/*  f0db0e4:	00000000 */ 	nop
/*  f0db0e8:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0db0ec:	444ef800 */ 	cfc1	$t6,$31
/*  f0db0f0:	00000000 */ 	nop
/*  f0db0f4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db0f8:	11c00012 */ 	beqz	$t6,.L0f0db144
/*  f0db0fc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db100:	44815000 */ 	mtc1	$at,$f10
/*  f0db104:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db108:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0db10c:	44cef800 */ 	ctc1	$t6,$31
/*  f0db110:	00000000 */ 	nop
/*  f0db114:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0db118:	444ef800 */ 	cfc1	$t6,$31
/*  f0db11c:	00000000 */ 	nop
/*  f0db120:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db124:	15c00005 */ 	bnez	$t6,.L0f0db13c
/*  f0db128:	00000000 */ 	nop
/*  f0db12c:	440e5000 */ 	mfc1	$t6,$f10
/*  f0db130:	3c018000 */ 	lui	$at,0x8000
/*  f0db134:	10000007 */ 	b	.L0f0db154
/*  f0db138:	01c17025 */ 	or	$t6,$t6,$at
.L0f0db13c:
/*  f0db13c:	10000005 */ 	b	.L0f0db154
/*  f0db140:	240effff */ 	addiu	$t6,$zero,-1
.L0f0db144:
/*  f0db144:	440e5000 */ 	mfc1	$t6,$f10
/*  f0db148:	00000000 */ 	nop
/*  f0db14c:	05c0fffb */ 	bltz	$t6,.L0f0db13c
/*  f0db150:	00000000 */ 	nop
.L0f0db154:
/*  f0db154:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0db158:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db15c:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0db160:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0db164:	03057025 */ 	or	$t6,$t8,$a1
/*  f0db168:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0db16c:	c7a60048 */ 	lwc1	$f6,0x48($sp)
/*  f0db170:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0db174:	46123201 */ 	sub.s	$f8,$f6,$f18
/*  f0db178:	46004100 */ 	add.s	$f4,$f8,$f0
/*  f0db17c:	4459f800 */ 	cfc1	$t9,$31
/*  f0db180:	44cbf800 */ 	ctc1	$t3,$31
/*  f0db184:	00000000 */ 	nop
/*  f0db188:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0db18c:	444bf800 */ 	cfc1	$t3,$31
/*  f0db190:	00000000 */ 	nop
/*  f0db194:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0db198:	11600012 */ 	beqz	$t3,.L0f0db1e4
/*  f0db19c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db1a0:	44815000 */ 	mtc1	$at,$f10
/*  f0db1a4:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f0db1a8:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0db1ac:	44cbf800 */ 	ctc1	$t3,$31
/*  f0db1b0:	00000000 */ 	nop
/*  f0db1b4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0db1b8:	444bf800 */ 	cfc1	$t3,$31
/*  f0db1bc:	00000000 */ 	nop
/*  f0db1c0:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f0db1c4:	15600005 */ 	bnez	$t3,.L0f0db1dc
/*  f0db1c8:	00000000 */ 	nop
/*  f0db1cc:	440b5000 */ 	mfc1	$t3,$f10
/*  f0db1d0:	3c018000 */ 	lui	$at,0x8000
/*  f0db1d4:	10000007 */ 	b	.L0f0db1f4
/*  f0db1d8:	01615825 */ 	or	$t3,$t3,$at
.L0f0db1dc:
/*  f0db1dc:	10000005 */ 	b	.L0f0db1f4
/*  f0db1e0:	240bffff */ 	addiu	$t3,$zero,-1
.L0f0db1e4:
/*  f0db1e4:	440b5000 */ 	mfc1	$t3,$f10
/*  f0db1e8:	00000000 */ 	nop
/*  f0db1ec:	0560fffb */ 	bltz	$t3,.L0f0db1dc
/*  f0db1f0:	00000000 */ 	nop
.L0f0db1f4:
/*  f0db1f4:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0db1f8:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db1fc:	316f03ff */ 	andi	$t7,$t3,0x3ff
/*  f0db200:	448e3000 */ 	mtc1	$t6,$f6
/*  f0db204:	000f5880 */ 	sll	$t3,$t7,0x2
/*  f0db208:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0db20c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0db210:	46081102 */ 	mul.s	$f4,$f2,$f8
/*  f0db214:	4459f800 */ 	cfc1	$t9,$31
/*  f0db218:	44cff800 */ 	ctc1	$t7,$31
/*  f0db21c:	00000000 */ 	nop
/*  f0db220:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0db224:	444ff800 */ 	cfc1	$t7,$31
/*  f0db228:	00000000 */ 	nop
/*  f0db22c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0db230:	11e00012 */ 	beqz	$t7,.L0f0db27c
/*  f0db234:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db238:	44815000 */ 	mtc1	$at,$f10
/*  f0db23c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0db240:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0db244:	44cff800 */ 	ctc1	$t7,$31
/*  f0db248:	00000000 */ 	nop
/*  f0db24c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0db250:	444ff800 */ 	cfc1	$t7,$31
/*  f0db254:	00000000 */ 	nop
/*  f0db258:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0db25c:	15e00005 */ 	bnez	$t7,.L0f0db274
/*  f0db260:	00000000 */ 	nop
/*  f0db264:	440f5000 */ 	mfc1	$t7,$f10
/*  f0db268:	3c018000 */ 	lui	$at,0x8000
/*  f0db26c:	10000007 */ 	b	.L0f0db28c
/*  f0db270:	01e17825 */ 	or	$t7,$t7,$at
.L0f0db274:
/*  f0db274:	10000005 */ 	b	.L0f0db28c
/*  f0db278:	240fffff */ 	addiu	$t7,$zero,-1
.L0f0db27c:
/*  f0db27c:	440f5000 */ 	mfc1	$t7,$f10
/*  f0db280:	00000000 */ 	nop
/*  f0db284:	05e0fffb */ 	bltz	$t7,.L0f0db274
/*  f0db288:	00000000 */ 	nop
.L0f0db28c:
/*  f0db28c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0db290:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db294:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0db298:	01cbc825 */ 	or	$t9,$t6,$t3
/*  f0db29c:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0db2a0:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0db2a4:	c7a60028 */ 	lwc1	$f6,0x28($sp)
/*  f0db2a8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db2ac:	448f4000 */ 	mtc1	$t7,$f8
/*  f0db2b0:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0db2b4:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0db2b8:	46804120 */ 	cvt.s.w	$f4,$f8
/*  f0db2bc:	46043282 */ 	mul.s	$f10,$f6,$f4
/*  f0db2c0:	4458f800 */ 	cfc1	$t8,$31
/*  f0db2c4:	44cef800 */ 	ctc1	$t6,$31
/*  f0db2c8:	00000000 */ 	nop
/*  f0db2cc:	46005224 */ 	cvt.w.s	$f8,$f10
/*  f0db2d0:	444ef800 */ 	cfc1	$t6,$31
/*  f0db2d4:	00000000 */ 	nop
/*  f0db2d8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db2dc:	11c00012 */ 	beqz	$t6,.L0f0db328
/*  f0db2e0:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db2e4:	44814000 */ 	mtc1	$at,$f8
/*  f0db2e8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db2ec:	46085201 */ 	sub.s	$f8,$f10,$f8
/*  f0db2f0:	44cef800 */ 	ctc1	$t6,$31
/*  f0db2f4:	00000000 */ 	nop
/*  f0db2f8:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0db2fc:	444ef800 */ 	cfc1	$t6,$31
/*  f0db300:	00000000 */ 	nop
/*  f0db304:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db308:	15c00005 */ 	bnez	$t6,.L0f0db320
/*  f0db30c:	00000000 */ 	nop
/*  f0db310:	440e4000 */ 	mfc1	$t6,$f8
/*  f0db314:	3c018000 */ 	lui	$at,0x8000
/*  f0db318:	10000007 */ 	b	.L0f0db338
/*  f0db31c:	01c17025 */ 	or	$t6,$t6,$at
.L0f0db320:
/*  f0db320:	10000005 */ 	b	.L0f0db338
/*  f0db324:	240effff */ 	addiu	$t6,$zero,-1
.L0f0db328:
/*  f0db328:	440e4000 */ 	mfc1	$t6,$f8
/*  f0db32c:	00000000 */ 	nop
/*  f0db330:	05c0fffb */ 	bltz	$t6,.L0f0db320
/*  f0db334:	00000000 */ 	nop
.L0f0db338:
/*  f0db338:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0db33c:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db340:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0db344:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0db348:	03057025 */ 	or	$t6,$t8,$a1
/*  f0db34c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f0db350:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0db354:	c7a60030 */ 	lwc1	$f6,0x30($sp)
/*  f0db358:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0db35c:	44992000 */ 	mtc1	$t9,$f4
/*  f0db360:	00000000 */ 	nop
/*  f0db364:	468022a0 */ 	cvt.s.w	$f10,$f4
/*  f0db368:	460a3202 */ 	mul.s	$f8,$f6,$f10
/*  f0db36c:	444ff800 */ 	cfc1	$t7,$31
/*  f0db370:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db374:	00000000 */ 	nop
/*  f0db378:	46004124 */ 	cvt.w.s	$f4,$f8
/*  f0db37c:	4458f800 */ 	cfc1	$t8,$31
/*  f0db380:	00000000 */ 	nop
/*  f0db384:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0db388:	13000012 */ 	beqz	$t8,.L0f0db3d4
/*  f0db38c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db390:	44812000 */ 	mtc1	$at,$f4
/*  f0db394:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0db398:	46044101 */ 	sub.s	$f4,$f8,$f4
/*  f0db39c:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db3a0:	00000000 */ 	nop
/*  f0db3a4:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0db3a8:	4458f800 */ 	cfc1	$t8,$31
/*  f0db3ac:	00000000 */ 	nop
/*  f0db3b0:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0db3b4:	17000005 */ 	bnez	$t8,.L0f0db3cc
/*  f0db3b8:	00000000 */ 	nop
/*  f0db3bc:	44182000 */ 	mfc1	$t8,$f4
/*  f0db3c0:	3c018000 */ 	lui	$at,0x8000
/*  f0db3c4:	10000007 */ 	b	.L0f0db3e4
/*  f0db3c8:	0301c025 */ 	or	$t8,$t8,$at
.L0f0db3cc:
/*  f0db3cc:	10000005 */ 	b	.L0f0db3e4
/*  f0db3d0:	2418ffff */ 	addiu	$t8,$zero,-1
.L0f0db3d4:
/*  f0db3d4:	44182000 */ 	mfc1	$t8,$f4
/*  f0db3d8:	00000000 */ 	nop
/*  f0db3dc:	0700fffb */ 	bltz	$t8,.L0f0db3cc
/*  f0db3e0:	00000000 */ 	nop
.L0f0db3e4:
/*  f0db3e4:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0db3e8:	44cff800 */ 	ctc1	$t7,$31
/*  f0db3ec:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0db3f0:	03297825 */ 	or	$t7,$t9,$t1
/*  f0db3f4:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0db3f8:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f0db3fc:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0db400:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0db404:	44983000 */ 	mtc1	$t8,$f6
/*  f0db408:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0db40c:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f0db410:	460a7202 */ 	mul.s	$f8,$f14,$f10
/*  f0db414:	444ef800 */ 	cfc1	$t6,$31
/*  f0db418:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db41c:	00000000 */ 	nop
/*  f0db420:	46004124 */ 	cvt.w.s	$f4,$f8
/*  f0db424:	4459f800 */ 	cfc1	$t9,$31
/*  f0db428:	00000000 */ 	nop
/*  f0db42c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0db430:	13200012 */ 	beqz	$t9,.L0f0db47c
/*  f0db434:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db438:	44812000 */ 	mtc1	$at,$f4
/*  f0db43c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0db440:	46044101 */ 	sub.s	$f4,$f8,$f4
/*  f0db444:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db448:	00000000 */ 	nop
/*  f0db44c:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0db450:	4459f800 */ 	cfc1	$t9,$31
/*  f0db454:	00000000 */ 	nop
/*  f0db458:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0db45c:	17200005 */ 	bnez	$t9,.L0f0db474
/*  f0db460:	00000000 */ 	nop
/*  f0db464:	44192000 */ 	mfc1	$t9,$f4
/*  f0db468:	3c018000 */ 	lui	$at,0x8000
/*  f0db46c:	10000007 */ 	b	.L0f0db48c
/*  f0db470:	0321c825 */ 	or	$t9,$t9,$at
.L0f0db474:
/*  f0db474:	10000005 */ 	b	.L0f0db48c
/*  f0db478:	2419ffff */ 	addiu	$t9,$zero,-1
.L0f0db47c:
/*  f0db47c:	44192000 */ 	mfc1	$t9,$f4
/*  f0db480:	00000000 */ 	nop
/*  f0db484:	0720fffb */ 	bltz	$t9,.L0f0db474
/*  f0db488:	00000000 */ 	nop
.L0f0db48c:
/*  f0db48c:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0db490:	44cef800 */ 	ctc1	$t6,$31
/*  f0db494:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0db498:	03037025 */ 	or	$t6,$t8,$v1
/*  f0db49c:	01c5c825 */ 	or	$t9,$t6,$a1
/*  f0db4a0:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0db4a4:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0db4a8:	c7a60050 */ 	lwc1	$f6,0x50($sp)
/*  f0db4ac:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db4b0:	448f5000 */ 	mtc1	$t7,$f10
/*  f0db4b4:	00000000 */ 	nop
/*  f0db4b8:	46805220 */ 	cvt.s.w	$f8,$f10
/*  f0db4bc:	46083102 */ 	mul.s	$f4,$f6,$f8
/*  f0db4c0:	4458f800 */ 	cfc1	$t8,$31
/*  f0db4c4:	44cef800 */ 	ctc1	$t6,$31
/*  f0db4c8:	00000000 */ 	nop
/*  f0db4cc:	460022a4 */ 	cvt.w.s	$f10,$f4
/*  f0db4d0:	444ef800 */ 	cfc1	$t6,$31
/*  f0db4d4:	00000000 */ 	nop
/*  f0db4d8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db4dc:	11c00012 */ 	beqz	$t6,.L0f0db528
/*  f0db4e0:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db4e4:	44815000 */ 	mtc1	$at,$f10
/*  f0db4e8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db4ec:	460a2281 */ 	sub.s	$f10,$f4,$f10
/*  f0db4f0:	44cef800 */ 	ctc1	$t6,$31
/*  f0db4f4:	00000000 */ 	nop
/*  f0db4f8:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0db4fc:	444ef800 */ 	cfc1	$t6,$31
/*  f0db500:	00000000 */ 	nop
/*  f0db504:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db508:	15c00005 */ 	bnez	$t6,.L0f0db520
/*  f0db50c:	00000000 */ 	nop
/*  f0db510:	440e5000 */ 	mfc1	$t6,$f10
/*  f0db514:	3c018000 */ 	lui	$at,0x8000
/*  f0db518:	10000007 */ 	b	.L0f0db538
/*  f0db51c:	01c17025 */ 	or	$t6,$t6,$at
.L0f0db520:
/*  f0db520:	10000005 */ 	b	.L0f0db538
/*  f0db524:	240effff */ 	addiu	$t6,$zero,-1
.L0f0db528:
/*  f0db528:	440e5000 */ 	mfc1	$t6,$f10
/*  f0db52c:	00000000 */ 	nop
/*  f0db530:	05c0fffb */ 	bltz	$t6,.L0f0db520
/*  f0db534:	00000000 */ 	nop
.L0f0db538:
/*  f0db538:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0db53c:	001f7043 */ 	sra	$t6,$ra,0x1
/*  f0db540:	01c0f825 */ 	or	$ra,$t6,$zero
/*  f0db544:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db548:	449f3000 */ 	mtc1	$ra,$f6
/*  f0db54c:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0db550:	01ebc025 */ 	or	$t8,$t7,$t3
/*  f0db554:	46803320 */ 	cvt.s.w	$f12,$f6
/*  f0db558:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0db55c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0db560:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db564:	000dc843 */ 	sra	$t9,$t5,0x1
/*  f0db568:	448f5000 */ 	mtc1	$t7,$f10
/*  f0db56c:	460c1200 */ 	add.s	$f8,$f2,$f12
/*  f0db570:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0db574:	03206825 */ 	or	$t5,$t9,$zero
/*  f0db578:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f0db57c:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0db580:	46004100 */ 	add.s	$f4,$f8,$f0
/*  f0db584:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f0db588:	e7a40028 */ 	swc1	$f4,0x28($sp)
/*  f0db58c:	4458f800 */ 	cfc1	$t8,$31
/*  f0db590:	44cef800 */ 	ctc1	$t6,$31
/*  f0db594:	00000000 */ 	nop
/*  f0db598:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0db59c:	444ef800 */ 	cfc1	$t6,$31
/*  f0db5a0:	00000000 */ 	nop
/*  f0db5a4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db5a8:	11c00012 */ 	beqz	$t6,.L0f0db5f4
/*  f0db5ac:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db5b0:	44815000 */ 	mtc1	$at,$f10
/*  f0db5b4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db5b8:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0db5bc:	44cef800 */ 	ctc1	$t6,$31
/*  f0db5c0:	00000000 */ 	nop
/*  f0db5c4:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0db5c8:	444ef800 */ 	cfc1	$t6,$31
/*  f0db5cc:	00000000 */ 	nop
/*  f0db5d0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db5d4:	15c00005 */ 	bnez	$t6,.L0f0db5ec
/*  f0db5d8:	00000000 */ 	nop
/*  f0db5dc:	440e5000 */ 	mfc1	$t6,$f10
/*  f0db5e0:	3c018000 */ 	lui	$at,0x8000
/*  f0db5e4:	10000007 */ 	b	.L0f0db604
/*  f0db5e8:	01c17025 */ 	or	$t6,$t6,$at
.L0f0db5ec:
/*  f0db5ec:	10000005 */ 	b	.L0f0db604
/*  f0db5f0:	240effff */ 	addiu	$t6,$zero,-1
.L0f0db5f4:
/*  f0db5f4:	440e5000 */ 	mfc1	$t6,$f10
/*  f0db5f8:	00000000 */ 	nop
/*  f0db5fc:	05c0fffb */ 	bltz	$t6,.L0f0db5ec
/*  f0db600:	00000000 */ 	nop
.L0f0db604:
/*  f0db604:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0db608:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db60c:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0db610:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0db614:	030a7025 */ 	or	$t6,$t8,$t2
/*  f0db618:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0db61c:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0db620:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0db624:	44992000 */ 	mtc1	$t9,$f4
/*  f0db628:	00000000 */ 	nop
/*  f0db62c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0db630:	46061202 */ 	mul.s	$f8,$f2,$f6
/*  f0db634:	444ff800 */ 	cfc1	$t7,$31
/*  f0db638:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db63c:	00000000 */ 	nop
/*  f0db640:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0db644:	4458f800 */ 	cfc1	$t8,$31
/*  f0db648:	00000000 */ 	nop
/*  f0db64c:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0db650:	13000012 */ 	beqz	$t8,.L0f0db69c
/*  f0db654:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db658:	44815000 */ 	mtc1	$at,$f10
/*  f0db65c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0db660:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0db664:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db668:	00000000 */ 	nop
/*  f0db66c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0db670:	4458f800 */ 	cfc1	$t8,$31
/*  f0db674:	00000000 */ 	nop
/*  f0db678:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0db67c:	17000005 */ 	bnez	$t8,.L0f0db694
/*  f0db680:	00000000 */ 	nop
/*  f0db684:	44185000 */ 	mfc1	$t8,$f10
/*  f0db688:	3c018000 */ 	lui	$at,0x8000
/*  f0db68c:	10000007 */ 	b	.L0f0db6ac
/*  f0db690:	0301c025 */ 	or	$t8,$t8,$at
.L0f0db694:
/*  f0db694:	10000005 */ 	b	.L0f0db6ac
/*  f0db698:	2418ffff */ 	addiu	$t8,$zero,-1
.L0f0db69c:
/*  f0db69c:	44185000 */ 	mfc1	$t8,$f10
/*  f0db6a0:	00000000 */ 	nop
/*  f0db6a4:	0700fffb */ 	bltz	$t8,.L0f0db694
/*  f0db6a8:	00000000 */ 	nop
.L0f0db6ac:
/*  f0db6ac:	44cff800 */ 	ctc1	$t7,$31
/*  f0db6b0:	448d2000 */ 	mtc1	$t5,$f4
/*  f0db6b4:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0db6b8:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0db6bc:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f0db6c0:	03277825 */ 	or	$t7,$t9,$a3
/*  f0db6c4:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f0db6c8:	c7a6004c */ 	lwc1	$f6,0x4c($sp)
/*  f0db6cc:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0db6d0:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0db6d4:	46123200 */ 	add.s	$f8,$f6,$f18
/*  f0db6d8:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0db6dc:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f0db6e0:	4458f800 */ 	cfc1	$t8,$31
/*  f0db6e4:	44ccf800 */ 	ctc1	$t4,$31
/*  f0db6e8:	00000000 */ 	nop
/*  f0db6ec:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0db6f0:	444cf800 */ 	cfc1	$t4,$31
/*  f0db6f4:	00000000 */ 	nop
/*  f0db6f8:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f0db6fc:	11800012 */ 	beqz	$t4,.L0f0db748
/*  f0db700:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db704:	44812000 */ 	mtc1	$at,$f4
/*  f0db708:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f0db70c:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0db710:	44ccf800 */ 	ctc1	$t4,$31
/*  f0db714:	00000000 */ 	nop
/*  f0db718:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0db71c:	444cf800 */ 	cfc1	$t4,$31
/*  f0db720:	00000000 */ 	nop
/*  f0db724:	318c0078 */ 	andi	$t4,$t4,0x78
/*  f0db728:	15800005 */ 	bnez	$t4,.L0f0db740
/*  f0db72c:	00000000 */ 	nop
/*  f0db730:	440c2000 */ 	mfc1	$t4,$f4
/*  f0db734:	3c018000 */ 	lui	$at,0x8000
/*  f0db738:	10000007 */ 	b	.L0f0db758
/*  f0db73c:	01816025 */ 	or	$t4,$t4,$at
.L0f0db740:
/*  f0db740:	10000005 */ 	b	.L0f0db758
/*  f0db744:	240cffff */ 	addiu	$t4,$zero,-1
.L0f0db748:
/*  f0db748:	440c2000 */ 	mfc1	$t4,$f4
/*  f0db74c:	00000000 */ 	nop
/*  f0db750:	0580fffb */ 	bltz	$t4,.L0f0db740
/*  f0db754:	00000000 */ 	nop
.L0f0db758:
/*  f0db758:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0db75c:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db760:	318e03ff */ 	andi	$t6,$t4,0x3ff
/*  f0db764:	448f3000 */ 	mtc1	$t7,$f6
/*  f0db768:	000e6080 */ 	sll	$t4,$t6,0x2
/*  f0db76c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db770:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0db774:	46088282 */ 	mul.s	$f10,$f16,$f8
/*  f0db778:	4458f800 */ 	cfc1	$t8,$31
/*  f0db77c:	44cef800 */ 	ctc1	$t6,$31
/*  f0db780:	00000000 */ 	nop
/*  f0db784:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0db788:	444ef800 */ 	cfc1	$t6,$31
/*  f0db78c:	00000000 */ 	nop
/*  f0db790:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db794:	11c00012 */ 	beqz	$t6,.L0f0db7e0
/*  f0db798:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db79c:	44812000 */ 	mtc1	$at,$f4
/*  f0db7a0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db7a4:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0db7a8:	44cef800 */ 	ctc1	$t6,$31
/*  f0db7ac:	00000000 */ 	nop
/*  f0db7b0:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0db7b4:	444ef800 */ 	cfc1	$t6,$31
/*  f0db7b8:	00000000 */ 	nop
/*  f0db7bc:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db7c0:	15c00005 */ 	bnez	$t6,.L0f0db7d8
/*  f0db7c4:	00000000 */ 	nop
/*  f0db7c8:	440e2000 */ 	mfc1	$t6,$f4
/*  f0db7cc:	3c018000 */ 	lui	$at,0x8000
/*  f0db7d0:	10000007 */ 	b	.L0f0db7f0
/*  f0db7d4:	01c17025 */ 	or	$t6,$t6,$at
.L0f0db7d8:
/*  f0db7d8:	10000005 */ 	b	.L0f0db7f0
/*  f0db7dc:	240effff */ 	addiu	$t6,$zero,-1
.L0f0db7e0:
/*  f0db7e0:	440e2000 */ 	mfc1	$t6,$f4
/*  f0db7e4:	00000000 */ 	nop
/*  f0db7e8:	05c0fffb */ 	bltz	$t6,.L0f0db7d8
/*  f0db7ec:	00000000 */ 	nop
.L0f0db7f0:
/*  f0db7f0:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0db7f4:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db7f8:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0db7fc:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0db800:	030c7025 */ 	or	$t6,$t8,$t4
/*  f0db804:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f0db808:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0db80c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0db810:	44993000 */ 	mtc1	$t9,$f6
/*  f0db814:	00000000 */ 	nop
/*  f0db818:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0db81c:	46081282 */ 	mul.s	$f10,$f2,$f8
/*  f0db820:	444ff800 */ 	cfc1	$t7,$31
/*  f0db824:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db828:	00000000 */ 	nop
/*  f0db82c:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0db830:	4458f800 */ 	cfc1	$t8,$31
/*  f0db834:	00000000 */ 	nop
/*  f0db838:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0db83c:	13000012 */ 	beqz	$t8,.L0f0db888
/*  f0db840:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db844:	44812000 */ 	mtc1	$at,$f4
/*  f0db848:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0db84c:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0db850:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db854:	00000000 */ 	nop
/*  f0db858:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0db85c:	4458f800 */ 	cfc1	$t8,$31
/*  f0db860:	00000000 */ 	nop
/*  f0db864:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0db868:	17000005 */ 	bnez	$t8,.L0f0db880
/*  f0db86c:	00000000 */ 	nop
/*  f0db870:	44182000 */ 	mfc1	$t8,$f4
/*  f0db874:	3c018000 */ 	lui	$at,0x8000
/*  f0db878:	10000007 */ 	b	.L0f0db898
/*  f0db87c:	0301c025 */ 	or	$t8,$t8,$at
.L0f0db880:
/*  f0db880:	10000005 */ 	b	.L0f0db898
/*  f0db884:	2418ffff */ 	addiu	$t8,$zero,-1
.L0f0db888:
/*  f0db888:	44182000 */ 	mfc1	$t8,$f4
/*  f0db88c:	00000000 */ 	nop
/*  f0db890:	0700fffb */ 	bltz	$t8,.L0f0db880
/*  f0db894:	00000000 */ 	nop
.L0f0db898:
/*  f0db898:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0db89c:	44cff800 */ 	ctc1	$t7,$31
/*  f0db8a0:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0db8a4:	03277825 */ 	or	$t7,$t9,$a3
/*  f0db8a8:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f0db8ac:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f0db8b0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0db8b4:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0db8b8:	44983000 */ 	mtc1	$t8,$f6
/*  f0db8bc:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0db8c0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f0db8c4:	46087282 */ 	mul.s	$f10,$f14,$f8
/*  f0db8c8:	444ef800 */ 	cfc1	$t6,$31
/*  f0db8cc:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db8d0:	00000000 */ 	nop
/*  f0db8d4:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0db8d8:	4459f800 */ 	cfc1	$t9,$31
/*  f0db8dc:	00000000 */ 	nop
/*  f0db8e0:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0db8e4:	13200012 */ 	beqz	$t9,.L0f0db930
/*  f0db8e8:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db8ec:	44812000 */ 	mtc1	$at,$f4
/*  f0db8f0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0db8f4:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0db8f8:	44d9f800 */ 	ctc1	$t9,$31
/*  f0db8fc:	00000000 */ 	nop
/*  f0db900:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0db904:	4459f800 */ 	cfc1	$t9,$31
/*  f0db908:	00000000 */ 	nop
/*  f0db90c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0db910:	17200005 */ 	bnez	$t9,.L0f0db928
/*  f0db914:	00000000 */ 	nop
/*  f0db918:	44192000 */ 	mfc1	$t9,$f4
/*  f0db91c:	3c018000 */ 	lui	$at,0x8000
/*  f0db920:	10000007 */ 	b	.L0f0db940
/*  f0db924:	0321c825 */ 	or	$t9,$t9,$at
.L0f0db928:
/*  f0db928:	10000005 */ 	b	.L0f0db940
/*  f0db92c:	2419ffff */ 	addiu	$t9,$zero,-1
.L0f0db930:
/*  f0db930:	44192000 */ 	mfc1	$t9,$f4
/*  f0db934:	00000000 */ 	nop
/*  f0db938:	0720fffb */ 	bltz	$t9,.L0f0db928
/*  f0db93c:	00000000 */ 	nop
.L0f0db940:
/*  f0db940:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0db944:	44cef800 */ 	ctc1	$t6,$31
/*  f0db948:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0db94c:	03037025 */ 	or	$t6,$t8,$v1
/*  f0db950:	01cac825 */ 	or	$t9,$t6,$t2
/*  f0db954:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0db958:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0db95c:	c7a60050 */ 	lwc1	$f6,0x50($sp)
/*  f0db960:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db964:	448f4000 */ 	mtc1	$t7,$f8
/*  f0db968:	460c3001 */ 	sub.s	$f0,$f6,$f12
/*  f0db96c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0db970:	460a0102 */ 	mul.s	$f4,$f0,$f10
/*  f0db974:	4458f800 */ 	cfc1	$t8,$31
/*  f0db978:	44cef800 */ 	ctc1	$t6,$31
/*  f0db97c:	00000000 */ 	nop
/*  f0db980:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f0db984:	444ef800 */ 	cfc1	$t6,$31
/*  f0db988:	00000000 */ 	nop
/*  f0db98c:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db990:	11c00012 */ 	beqz	$t6,.L0f0db9dc
/*  f0db994:	3c014f00 */ 	lui	$at,0x4f00
/*  f0db998:	44813000 */ 	mtc1	$at,$f6
/*  f0db99c:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0db9a0:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f0db9a4:	44cef800 */ 	ctc1	$t6,$31
/*  f0db9a8:	00000000 */ 	nop
/*  f0db9ac:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0db9b0:	444ef800 */ 	cfc1	$t6,$31
/*  f0db9b4:	00000000 */ 	nop
/*  f0db9b8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0db9bc:	15c00005 */ 	bnez	$t6,.L0f0db9d4
/*  f0db9c0:	00000000 */ 	nop
/*  f0db9c4:	440e3000 */ 	mfc1	$t6,$f6
/*  f0db9c8:	3c018000 */ 	lui	$at,0x8000
/*  f0db9cc:	10000007 */ 	b	.L0f0db9ec
/*  f0db9d0:	01c17025 */ 	or	$t6,$t6,$at
.L0f0db9d4:
/*  f0db9d4:	10000005 */ 	b	.L0f0db9ec
/*  f0db9d8:	240effff */ 	addiu	$t6,$zero,-1
.L0f0db9dc:
/*  f0db9dc:	440e3000 */ 	mfc1	$t6,$f6
/*  f0db9e0:	00000000 */ 	nop
/*  f0db9e4:	05c0fffb */ 	bltz	$t6,.L0f0db9d4
/*  f0db9e8:	00000000 */ 	nop
.L0f0db9ec:
/*  f0db9ec:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0db9f0:	44d8f800 */ 	ctc1	$t8,$31
/*  f0db9f4:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0db9f8:	01e7c025 */ 	or	$t8,$t7,$a3
/*  f0db9fc:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0dba00:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0dba04:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dba08:	00c05825 */ 	or	$t3,$a2,$zero
/*  f0dba0c:	448e4000 */ 	mtc1	$t6,$f8
/*  f0dba10:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0dba14:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f0dba18:	460a7102 */ 	mul.s	$f4,$f14,$f10
/*  f0dba1c:	4459f800 */ 	cfc1	$t9,$31
/*  f0dba20:	44cff800 */ 	ctc1	$t7,$31
/*  f0dba24:	00000000 */ 	nop
/*  f0dba28:	460021a4 */ 	cvt.w.s	$f6,$f4
/*  f0dba2c:	444ff800 */ 	cfc1	$t7,$31
/*  f0dba30:	00000000 */ 	nop
/*  f0dba34:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dba38:	11e00012 */ 	beqz	$t7,.L0f0dba84
/*  f0dba3c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dba40:	44813000 */ 	mtc1	$at,$f6
/*  f0dba44:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dba48:	46062181 */ 	sub.s	$f6,$f4,$f6
/*  f0dba4c:	44cff800 */ 	ctc1	$t7,$31
/*  f0dba50:	00000000 */ 	nop
/*  f0dba54:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f0dba58:	444ff800 */ 	cfc1	$t7,$31
/*  f0dba5c:	00000000 */ 	nop
/*  f0dba60:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dba64:	15e00005 */ 	bnez	$t7,.L0f0dba7c
/*  f0dba68:	00000000 */ 	nop
/*  f0dba6c:	440f3000 */ 	mfc1	$t7,$f6
/*  f0dba70:	3c018000 */ 	lui	$at,0x8000
/*  f0dba74:	10000007 */ 	b	.L0f0dba94
/*  f0dba78:	01e17825 */ 	or	$t7,$t7,$at
.L0f0dba7c:
/*  f0dba7c:	10000005 */ 	b	.L0f0dba94
/*  f0dba80:	240fffff */ 	addiu	$t7,$zero,-1
.L0f0dba84:
/*  f0dba84:	440f3000 */ 	mfc1	$t7,$f6
/*  f0dba88:	00000000 */ 	nop
/*  f0dba8c:	05e0fffb */ 	bltz	$t7,.L0f0dba7c
/*  f0dba90:	00000000 */ 	nop
.L0f0dba94:
/*  f0dba94:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0dba98:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dba9c:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0dbaa0:	01c3c825 */ 	or	$t9,$t6,$v1
/*  f0dbaa4:	032c7825 */ 	or	$t7,$t9,$t4
/*  f0dbaa8:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f0dbaac:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f0dbab0:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f0dbab4:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0dbab8:	44985000 */ 	mtc1	$t8,$f10
/*  f0dbabc:	00000000 */ 	nop
/*  f0dbac0:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f0dbac4:	46044182 */ 	mul.s	$f6,$f8,$f4
/*  f0dbac8:	444ef800 */ 	cfc1	$t6,$31
/*  f0dbacc:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dbad0:	00000000 */ 	nop
/*  f0dbad4:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f0dbad8:	4459f800 */ 	cfc1	$t9,$31
/*  f0dbadc:	00000000 */ 	nop
/*  f0dbae0:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0dbae4:	13200012 */ 	beqz	$t9,.L0f0dbb30
/*  f0dbae8:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbaec:	44815000 */ 	mtc1	$at,$f10
/*  f0dbaf0:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0dbaf4:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f0dbaf8:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dbafc:	00000000 */ 	nop
/*  f0dbb00:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dbb04:	4459f800 */ 	cfc1	$t9,$31
/*  f0dbb08:	00000000 */ 	nop
/*  f0dbb0c:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0dbb10:	17200005 */ 	bnez	$t9,.L0f0dbb28
/*  f0dbb14:	00000000 */ 	nop
/*  f0dbb18:	44195000 */ 	mfc1	$t9,$f10
/*  f0dbb1c:	3c018000 */ 	lui	$at,0x8000
/*  f0dbb20:	10000007 */ 	b	.L0f0dbb40
/*  f0dbb24:	0321c825 */ 	or	$t9,$t9,$at
.L0f0dbb28:
/*  f0dbb28:	10000005 */ 	b	.L0f0dbb40
/*  f0dbb2c:	2419ffff */ 	addiu	$t9,$zero,-1
.L0f0dbb30:
/*  f0dbb30:	44195000 */ 	mfc1	$t9,$f10
/*  f0dbb34:	00000000 */ 	nop
/*  f0dbb38:	0720fffb */ 	bltz	$t9,.L0f0dbb28
/*  f0dbb3c:	00000000 */ 	nop
.L0f0dbb40:
/*  f0dbb40:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0dbb44:	44cef800 */ 	ctc1	$t6,$31
/*  f0dbb48:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0dbb4c:	03077025 */ 	or	$t6,$t8,$a3
/*  f0dbb50:	ad6e0004 */ 	sw	$t6,0x4($t3)
/*  f0dbb54:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0dbb58:	c7a80028 */ 	lwc1	$f8,0x28($sp)
/*  f0dbb5c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dbb60:	44992000 */ 	mtc1	$t9,$f4
/*  f0dbb64:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0dbb68:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0dbb6c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f0dbb70:	46064282 */ 	mul.s	$f10,$f8,$f6
/*  f0dbb74:	444ff800 */ 	cfc1	$t7,$31
/*  f0dbb78:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dbb7c:	00000000 */ 	nop
/*  f0dbb80:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0dbb84:	4458f800 */ 	cfc1	$t8,$31
/*  f0dbb88:	00000000 */ 	nop
/*  f0dbb8c:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dbb90:	13000012 */ 	beqz	$t8,.L0f0dbbdc
/*  f0dbb94:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbb98:	44812000 */ 	mtc1	$at,$f4
/*  f0dbb9c:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dbba0:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0dbba4:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dbba8:	00000000 */ 	nop
/*  f0dbbac:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0dbbb0:	4458f800 */ 	cfc1	$t8,$31
/*  f0dbbb4:	00000000 */ 	nop
/*  f0dbbb8:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dbbbc:	17000005 */ 	bnez	$t8,.L0f0dbbd4
/*  f0dbbc0:	00000000 */ 	nop
/*  f0dbbc4:	44182000 */ 	mfc1	$t8,$f4
/*  f0dbbc8:	3c018000 */ 	lui	$at,0x8000
/*  f0dbbcc:	10000007 */ 	b	.L0f0dbbec
/*  f0dbbd0:	0301c025 */ 	or	$t8,$t8,$at
.L0f0dbbd4:
/*  f0dbbd4:	10000005 */ 	b	.L0f0dbbec
/*  f0dbbd8:	2418ffff */ 	addiu	$t8,$zero,-1
.L0f0dbbdc:
/*  f0dbbdc:	44182000 */ 	mfc1	$t8,$f4
/*  f0dbbe0:	00000000 */ 	nop
/*  f0dbbe4:	0700fffb */ 	bltz	$t8,.L0f0dbbd4
/*  f0dbbe8:	00000000 */ 	nop
.L0f0dbbec:
/*  f0dbbec:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0dbbf0:	44cff800 */ 	ctc1	$t7,$31
/*  f0dbbf4:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0dbbf8:	03237825 */ 	or	$t7,$t9,$v1
/*  f0dbbfc:	01e5c025 */ 	or	$t8,$t7,$a1
/*  f0dbc00:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0dbc04:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0dbc08:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dbc0c:	448e4000 */ 	mtc1	$t6,$f8
/*  f0dbc10:	00000000 */ 	nop
/*  f0dbc14:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0dbc18:	46061282 */ 	mul.s	$f10,$f2,$f6
/*  f0dbc1c:	4459f800 */ 	cfc1	$t9,$31
/*  f0dbc20:	44cff800 */ 	ctc1	$t7,$31
/*  f0dbc24:	00000000 */ 	nop
/*  f0dbc28:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0dbc2c:	444ff800 */ 	cfc1	$t7,$31
/*  f0dbc30:	00000000 */ 	nop
/*  f0dbc34:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dbc38:	11e00012 */ 	beqz	$t7,.L0f0dbc84
/*  f0dbc3c:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbc40:	44812000 */ 	mtc1	$at,$f4
/*  f0dbc44:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dbc48:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0dbc4c:	44cff800 */ 	ctc1	$t7,$31
/*  f0dbc50:	00000000 */ 	nop
/*  f0dbc54:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0dbc58:	444ff800 */ 	cfc1	$t7,$31
/*  f0dbc5c:	00000000 */ 	nop
/*  f0dbc60:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dbc64:	15e00005 */ 	bnez	$t7,.L0f0dbc7c
/*  f0dbc68:	00000000 */ 	nop
/*  f0dbc6c:	440f2000 */ 	mfc1	$t7,$f4
/*  f0dbc70:	3c018000 */ 	lui	$at,0x8000
/*  f0dbc74:	10000007 */ 	b	.L0f0dbc94
/*  f0dbc78:	01e17825 */ 	or	$t7,$t7,$at
.L0f0dbc7c:
/*  f0dbc7c:	10000005 */ 	b	.L0f0dbc94
/*  f0dbc80:	240fffff */ 	addiu	$t7,$zero,-1
.L0f0dbc84:
/*  f0dbc84:	440f2000 */ 	mfc1	$t7,$f4
/*  f0dbc88:	00000000 */ 	nop
/*  f0dbc8c:	05e0fffb */ 	bltz	$t7,.L0f0dbc7c
/*  f0dbc90:	00000000 */ 	nop
.L0f0dbc94:
/*  f0dbc94:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0dbc98:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dbc9c:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0dbca0:	01c9c825 */ 	or	$t9,$t6,$t1
/*  f0dbca4:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0dbca8:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0dbcac:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dbcb0:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0dbcb4:	448f4000 */ 	mtc1	$t7,$f8
/*  f0dbcb8:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0dbcbc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbcc0:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0dbcc4:	46068282 */ 	mul.s	$f10,$f16,$f6
/*  f0dbcc8:	4458f800 */ 	cfc1	$t8,$31
/*  f0dbccc:	44cef800 */ 	ctc1	$t6,$31
/*  f0dbcd0:	00000000 */ 	nop
/*  f0dbcd4:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f0dbcd8:	444ef800 */ 	cfc1	$t6,$31
/*  f0dbcdc:	00000000 */ 	nop
/*  f0dbce0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dbce4:	51c00013 */ 	beqzl	$t6,.L0f0dbd34
/*  f0dbce8:	440e2000 */ 	mfc1	$t6,$f4
/*  f0dbcec:	44812000 */ 	mtc1	$at,$f4
/*  f0dbcf0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dbcf4:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f0dbcf8:	44cef800 */ 	ctc1	$t6,$31
/*  f0dbcfc:	00000000 */ 	nop
/*  f0dbd00:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f0dbd04:	444ef800 */ 	cfc1	$t6,$31
/*  f0dbd08:	00000000 */ 	nop
/*  f0dbd0c:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dbd10:	15c00005 */ 	bnez	$t6,.L0f0dbd28
/*  f0dbd14:	00000000 */ 	nop
/*  f0dbd18:	440e2000 */ 	mfc1	$t6,$f4
/*  f0dbd1c:	3c018000 */ 	lui	$at,0x8000
/*  f0dbd20:	10000007 */ 	b	.L0f0dbd40
/*  f0dbd24:	01c17025 */ 	or	$t6,$t6,$at
.L0f0dbd28:
/*  f0dbd28:	10000005 */ 	b	.L0f0dbd40
/*  f0dbd2c:	240effff */ 	addiu	$t6,$zero,-1
/*  f0dbd30:	440e2000 */ 	mfc1	$t6,$f4
.L0f0dbd34:
/*  f0dbd34:	00000000 */ 	nop
/*  f0dbd38:	05c0fffb */ 	bltz	$t6,.L0f0dbd28
/*  f0dbd3c:	00000000 */ 	nop
.L0f0dbd40:
/*  f0dbd40:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0dbd44:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dbd48:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0dbd4c:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0dbd50:	03057025 */ 	or	$t6,$t8,$a1
/*  f0dbd54:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f0dbd58:	c7a80048 */ 	lwc1	$f8,0x48($sp)
/*  f0dbd5c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0dbd60:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbd64:	46124181 */ 	sub.s	$f6,$f8,$f18
/*  f0dbd68:	4459f800 */ 	cfc1	$t9,$31
/*  f0dbd6c:	44caf800 */ 	ctc1	$t2,$31
/*  f0dbd70:	00000000 */ 	nop
/*  f0dbd74:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f0dbd78:	444af800 */ 	cfc1	$t2,$31
/*  f0dbd7c:	00000000 */ 	nop
/*  f0dbd80:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0dbd84:	51400013 */ 	beqzl	$t2,.L0f0dbdd4
/*  f0dbd88:	440a5000 */ 	mfc1	$t2,$f10
/*  f0dbd8c:	44815000 */ 	mtc1	$at,$f10
/*  f0dbd90:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f0dbd94:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f0dbd98:	44caf800 */ 	ctc1	$t2,$31
/*  f0dbd9c:	00000000 */ 	nop
/*  f0dbda0:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dbda4:	444af800 */ 	cfc1	$t2,$31
/*  f0dbda8:	00000000 */ 	nop
/*  f0dbdac:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f0dbdb0:	15400005 */ 	bnez	$t2,.L0f0dbdc8
/*  f0dbdb4:	00000000 */ 	nop
/*  f0dbdb8:	440a5000 */ 	mfc1	$t2,$f10
/*  f0dbdbc:	3c018000 */ 	lui	$at,0x8000
/*  f0dbdc0:	10000007 */ 	b	.L0f0dbde0
/*  f0dbdc4:	01415025 */ 	or	$t2,$t2,$at
.L0f0dbdc8:
/*  f0dbdc8:	10000005 */ 	b	.L0f0dbde0
/*  f0dbdcc:	240affff */ 	addiu	$t2,$zero,-1
/*  f0dbdd0:	440a5000 */ 	mfc1	$t2,$f10
.L0f0dbdd4:
/*  f0dbdd4:	00000000 */ 	nop
/*  f0dbdd8:	0540fffb */ 	bltz	$t2,.L0f0dbdc8
/*  f0dbddc:	00000000 */ 	nop
.L0f0dbde0:
/*  f0dbde0:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f0dbde4:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dbde8:	314f03ff */ 	andi	$t7,$t2,0x3ff
/*  f0dbdec:	448e2000 */ 	mtc1	$t6,$f4
/*  f0dbdf0:	000f5080 */ 	sll	$t2,$t7,0x2
/*  f0dbdf4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dbdf8:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0dbdfc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbe00:	46081182 */ 	mul.s	$f6,$f2,$f8
/*  f0dbe04:	4459f800 */ 	cfc1	$t9,$31
/*  f0dbe08:	44cff800 */ 	ctc1	$t7,$31
/*  f0dbe0c:	00000000 */ 	nop
/*  f0dbe10:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f0dbe14:	444ff800 */ 	cfc1	$t7,$31
/*  f0dbe18:	00000000 */ 	nop
/*  f0dbe1c:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dbe20:	51e00013 */ 	beqzl	$t7,.L0f0dbe70
/*  f0dbe24:	440f5000 */ 	mfc1	$t7,$f10
/*  f0dbe28:	44815000 */ 	mtc1	$at,$f10
/*  f0dbe2c:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f0dbe30:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f0dbe34:	44cff800 */ 	ctc1	$t7,$31
/*  f0dbe38:	00000000 */ 	nop
/*  f0dbe3c:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dbe40:	444ff800 */ 	cfc1	$t7,$31
/*  f0dbe44:	00000000 */ 	nop
/*  f0dbe48:	31ef0078 */ 	andi	$t7,$t7,0x78
/*  f0dbe4c:	15e00005 */ 	bnez	$t7,.L0f0dbe64
/*  f0dbe50:	00000000 */ 	nop
/*  f0dbe54:	440f5000 */ 	mfc1	$t7,$f10
/*  f0dbe58:	3c018000 */ 	lui	$at,0x8000
/*  f0dbe5c:	10000007 */ 	b	.L0f0dbe7c
/*  f0dbe60:	01e17825 */ 	or	$t7,$t7,$at
.L0f0dbe64:
/*  f0dbe64:	10000005 */ 	b	.L0f0dbe7c
/*  f0dbe68:	240fffff */ 	addiu	$t7,$zero,-1
/*  f0dbe6c:	440f5000 */ 	mfc1	$t7,$f10
.L0f0dbe70:
/*  f0dbe70:	00000000 */ 	nop
/*  f0dbe74:	05e0fffb */ 	bltz	$t7,.L0f0dbe64
/*  f0dbe78:	00000000 */ 	nop
.L0f0dbe7c:
/*  f0dbe7c:	31f803ff */ 	andi	$t8,$t7,0x3ff
/*  f0dbe80:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dbe84:	00187380 */ 	sll	$t6,$t8,0xe
/*  f0dbe88:	01cac825 */ 	or	$t9,$t6,$t2
/*  f0dbe8c:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f0dbe90:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0dbe94:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dbe98:	00c03825 */ 	or	$a3,$a2,$zero
/*  f0dbe9c:	448f2000 */ 	mtc1	$t7,$f4
/*  f0dbea0:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0dbea4:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbea8:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0dbeac:	46087182 */ 	mul.s	$f6,$f14,$f8
/*  f0dbeb0:	4458f800 */ 	cfc1	$t8,$31
/*  f0dbeb4:	44cef800 */ 	ctc1	$t6,$31
/*  f0dbeb8:	00000000 */ 	nop
/*  f0dbebc:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f0dbec0:	444ef800 */ 	cfc1	$t6,$31
/*  f0dbec4:	00000000 */ 	nop
/*  f0dbec8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dbecc:	51c00013 */ 	beqzl	$t6,.L0f0dbf1c
/*  f0dbed0:	440e5000 */ 	mfc1	$t6,$f10
/*  f0dbed4:	44815000 */ 	mtc1	$at,$f10
/*  f0dbed8:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dbedc:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f0dbee0:	44cef800 */ 	ctc1	$t6,$31
/*  f0dbee4:	00000000 */ 	nop
/*  f0dbee8:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dbeec:	444ef800 */ 	cfc1	$t6,$31
/*  f0dbef0:	00000000 */ 	nop
/*  f0dbef4:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dbef8:	15c00005 */ 	bnez	$t6,.L0f0dbf10
/*  f0dbefc:	00000000 */ 	nop
/*  f0dbf00:	440e5000 */ 	mfc1	$t6,$f10
/*  f0dbf04:	3c018000 */ 	lui	$at,0x8000
/*  f0dbf08:	10000007 */ 	b	.L0f0dbf28
/*  f0dbf0c:	01c17025 */ 	or	$t6,$t6,$at
.L0f0dbf10:
/*  f0dbf10:	10000005 */ 	b	.L0f0dbf28
/*  f0dbf14:	240effff */ 	addiu	$t6,$zero,-1
/*  f0dbf18:	440e5000 */ 	mfc1	$t6,$f10
.L0f0dbf1c:
/*  f0dbf1c:	00000000 */ 	nop
/*  f0dbf20:	05c0fffb */ 	bltz	$t6,.L0f0dbf10
/*  f0dbf24:	00000000 */ 	nop
.L0f0dbf28:
/*  f0dbf28:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0dbf2c:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dbf30:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0dbf34:	01e3c025 */ 	or	$t8,$t7,$v1
/*  f0dbf38:	03057025 */ 	or	$t6,$t8,$a1
/*  f0dbf3c:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f0dbf40:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f0dbf44:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dbf48:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dbf4c:	44992000 */ 	mtc1	$t9,$f4
/*  f0dbf50:	00000000 */ 	nop
/*  f0dbf54:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0dbf58:	46080182 */ 	mul.s	$f6,$f0,$f8
/*  f0dbf5c:	444ff800 */ 	cfc1	$t7,$31
/*  f0dbf60:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dbf64:	00000000 */ 	nop
/*  f0dbf68:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f0dbf6c:	4458f800 */ 	cfc1	$t8,$31
/*  f0dbf70:	00000000 */ 	nop
/*  f0dbf74:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dbf78:	53000013 */ 	beqzl	$t8,.L0f0dbfc8
/*  f0dbf7c:	44185000 */ 	mfc1	$t8,$f10
/*  f0dbf80:	44815000 */ 	mtc1	$at,$f10
/*  f0dbf84:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f0dbf88:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f0dbf8c:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dbf90:	00000000 */ 	nop
/*  f0dbf94:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dbf98:	4458f800 */ 	cfc1	$t8,$31
/*  f0dbf9c:	00000000 */ 	nop
/*  f0dbfa0:	33180078 */ 	andi	$t8,$t8,0x78
/*  f0dbfa4:	17000005 */ 	bnez	$t8,.L0f0dbfbc
/*  f0dbfa8:	00000000 */ 	nop
/*  f0dbfac:	44185000 */ 	mfc1	$t8,$f10
/*  f0dbfb0:	3c018000 */ 	lui	$at,0x8000
/*  f0dbfb4:	10000007 */ 	b	.L0f0dbfd4
/*  f0dbfb8:	0301c025 */ 	or	$t8,$t8,$at
.L0f0dbfbc:
/*  f0dbfbc:	10000005 */ 	b	.L0f0dbfd4
/*  f0dbfc0:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f0dbfc4:	44185000 */ 	mfc1	$t8,$f10
.L0f0dbfc8:
/*  f0dbfc8:	00000000 */ 	nop
/*  f0dbfcc:	0700fffb */ 	bltz	$t8,.L0f0dbfbc
/*  f0dbfd0:	00000000 */ 	nop
.L0f0dbfd4:
/*  f0dbfd4:	330e03ff */ 	andi	$t6,$t8,0x3ff
/*  f0dbfd8:	44cff800 */ 	ctc1	$t7,$31
/*  f0dbfdc:	000ecb80 */ 	sll	$t9,$t6,0xe
/*  f0dbfe0:	03297825 */ 	or	$t7,$t9,$t1
/*  f0dbfe4:	acef0004 */ 	sw	$t7,0x4($a3)
/*  f0dbfe8:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f0dbfec:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0dbff0:	00c01025 */ 	or	$v0,$a2,$zero
/*  f0dbff4:	44982000 */ 	mtc1	$t8,$f4
/*  f0dbff8:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f0dbffc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dc000:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f0dc004:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0dc008:	46087182 */ 	mul.s	$f6,$f14,$f8
/*  f0dc00c:	444ef800 */ 	cfc1	$t6,$31
/*  f0dc010:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dc014:	00000000 */ 	nop
/*  f0dc018:	460032a4 */ 	cvt.w.s	$f10,$f6
/*  f0dc01c:	4459f800 */ 	cfc1	$t9,$31
/*  f0dc020:	00000000 */ 	nop
/*  f0dc024:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0dc028:	53200013 */ 	beqzl	$t9,.L0f0dc078
/*  f0dc02c:	44195000 */ 	mfc1	$t9,$f10
/*  f0dc030:	44815000 */ 	mtc1	$at,$f10
/*  f0dc034:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f0dc038:	460a3281 */ 	sub.s	$f10,$f6,$f10
/*  f0dc03c:	44d9f800 */ 	ctc1	$t9,$31
/*  f0dc040:	00000000 */ 	nop
/*  f0dc044:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0dc048:	4459f800 */ 	cfc1	$t9,$31
/*  f0dc04c:	00000000 */ 	nop
/*  f0dc050:	33390078 */ 	andi	$t9,$t9,0x78
/*  f0dc054:	17200005 */ 	bnez	$t9,.L0f0dc06c
/*  f0dc058:	00000000 */ 	nop
/*  f0dc05c:	44195000 */ 	mfc1	$t9,$f10
/*  f0dc060:	3c018000 */ 	lui	$at,0x8000
/*  f0dc064:	10000007 */ 	b	.L0f0dc084
/*  f0dc068:	0321c825 */ 	or	$t9,$t9,$at
.L0f0dc06c:
/*  f0dc06c:	10000005 */ 	b	.L0f0dc084
/*  f0dc070:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f0dc074:	44195000 */ 	mfc1	$t9,$f10
.L0f0dc078:
/*  f0dc078:	00000000 */ 	nop
/*  f0dc07c:	0720fffb */ 	bltz	$t9,.L0f0dc06c
/*  f0dc080:	00000000 */ 	nop
.L0f0dc084:
/*  f0dc084:	332f03ff */ 	andi	$t7,$t9,0x3ff
/*  f0dc088:	44cef800 */ 	ctc1	$t6,$31
/*  f0dc08c:	000fc380 */ 	sll	$t8,$t7,0xe
/*  f0dc090:	03037025 */ 	or	$t6,$t8,$v1
/*  f0dc094:	01c5c825 */ 	or	$t9,$t6,$a1
/*  f0dc098:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f0dc09c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f0dc0a0:	c7a40050 */ 	lwc1	$f4,0x50($sp)
/*  f0dc0a4:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dc0a8:	448f4000 */ 	mtc1	$t7,$f8
/*  f0dc0ac:	3c014f00 */ 	lui	$at,0x4f00
/*  f0dc0b0:	468041a0 */ 	cvt.s.w	$f6,$f8
/*  f0dc0b4:	46062282 */ 	mul.s	$f10,$f4,$f6
/*  f0dc0b8:	4458f800 */ 	cfc1	$t8,$31
/*  f0dc0bc:	44cef800 */ 	ctc1	$t6,$31
/*  f0dc0c0:	00000000 */ 	nop
/*  f0dc0c4:	46005224 */ 	cvt.w.s	$f8,$f10
/*  f0dc0c8:	444ef800 */ 	cfc1	$t6,$31
/*  f0dc0cc:	00000000 */ 	nop
/*  f0dc0d0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dc0d4:	51c00013 */ 	beqzl	$t6,.L0f0dc124
/*  f0dc0d8:	440e4000 */ 	mfc1	$t6,$f8
/*  f0dc0dc:	44814000 */ 	mtc1	$at,$f8
/*  f0dc0e0:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f0dc0e4:	46085201 */ 	sub.s	$f8,$f10,$f8
/*  f0dc0e8:	44cef800 */ 	ctc1	$t6,$31
/*  f0dc0ec:	00000000 */ 	nop
/*  f0dc0f0:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f0dc0f4:	444ef800 */ 	cfc1	$t6,$31
/*  f0dc0f8:	00000000 */ 	nop
/*  f0dc0fc:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0dc100:	15c00005 */ 	bnez	$t6,.L0f0dc118
/*  f0dc104:	00000000 */ 	nop
/*  f0dc108:	440e4000 */ 	mfc1	$t6,$f8
/*  f0dc10c:	3c018000 */ 	lui	$at,0x8000
/*  f0dc110:	10000007 */ 	b	.L0f0dc130
/*  f0dc114:	01c17025 */ 	or	$t6,$t6,$at
.L0f0dc118:
/*  f0dc118:	10000005 */ 	b	.L0f0dc130
/*  f0dc11c:	240effff */ 	addiu	$t6,$zero,-1
/*  f0dc120:	440e4000 */ 	mfc1	$t6,$f8
.L0f0dc124:
/*  f0dc124:	00000000 */ 	nop
/*  f0dc128:	05c0fffb */ 	bltz	$t6,.L0f0dc118
/*  f0dc12c:	00000000 */ 	nop
.L0f0dc130:
/*  f0dc130:	31d903ff */ 	andi	$t9,$t6,0x3ff
/*  f0dc134:	00197b80 */ 	sll	$t7,$t9,0xe
/*  f0dc138:	44d8f800 */ 	ctc1	$t8,$31
/*  f0dc13c:	01eac025 */ 	or	$t8,$t7,$t2
/*  f0dc140:	0fc54e0e */ 	jal	text0f153838
/*  f0dc144:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f0dc148:	0fc54de0 */ 	jal	text0f153780
/*  f0dc14c:	00402025 */ 	or	$a0,$v0,$zero
/*  f0dc150:	00403025 */ 	or	$a2,$v0,$zero
.L0f0dc154:
/*  f0dc154:	00c02025 */ 	or	$a0,$a2,$zero
/*  f0dc158:	0fc363de */ 	jal	sightDrawDefault
/*  f0dc15c:	8fa50104 */ 	lw	$a1,0x104($sp)
/*  f0dc160:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0dc164:	27bd0100 */ 	addiu	$sp,$sp,0x100
/*  f0dc168:	03e00008 */ 	jr	$ra
/*  f0dc16c:	00000000 */ 	nop
);

// Mismatch: Goal loads 1.0f into $at earlier
//Gfx *sightDrawZoom(Gfx *gdl, bool sighton)
//{
//	s32 viewleft; // fc
//	s32 viewtop; // f8
//	s32 halfwidth; // f4
//	s32 halfheight; // f0
//	s32 viewright;
//	s32 viewbottom; // e8
//	f32 maxfovy;
//	s32 availableabove; // e0
//	s32 availablebelow; // dc
//	s32 availableleft;
//	s32 availableright;
//	f32 zoominfovy;
//	f32 frac; // cc
//
//	f32 boxright; // 50
//	f32 boxtop; // 4c
//	f32 boxbottom; // 48
//	f32 boxleft;
//
//	s32 outerwidth;
//	s32 outerheight; // b4
//	s32 weaponnum; // b0
//	u8 showzoomrange;  // af
//
//	s32 innerwidth;
//	s32 innerheight;
//
//	viewleft = viGetViewLeft() / g_ScaleX;
//	viewtop = viGetViewTop();
//	halfwidth = (viGetViewWidth() / g_ScaleX) >> 1;
//	halfheight = viGetViewHeight() >> 1;
//	viewright = viewleft + halfwidth * 2 - 1;
//	viewbottom = viewtop + halfheight * 2 - 1;
//
//	availableleft = halfwidth - 48;
//	availableright = halfwidth - 49;
//	availableabove = halfheight - 10;
//	availablebelow = halfheight - 10;
//	frac = 1.0f;
//	weaponnum = g_Vars.currentplayer->hands[HAND_RIGHT].gset.weaponnum;
//	outerwidth = (halfwidth >> 1) - 60;
//	outerheight = (halfheight >> 1) - 22;
//
//	showzoomrange = optionsGetShowZoomRange(g_Vars.currentplayerstats->mpindex)
//		&& optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex);
//
//	maxfovy = currentPlayerGetGunZoomFov();
//	zoominfovy = g_Vars.currentplayer->zoominfovy;
//
//	if (maxfovy == 0.0f || maxfovy == 60.0f) {
//		if (weaponnum != WEAPON_SNIPERRIFLE) {
//			showzoomrange = false;
//		}
//	} else {
//		frac = maxfovy / zoominfovy;
//	}
//
//	if (showzoomrange) {
//		gdl = text0f153628(gdl);
//		gdl = textSetPrimColour(gdl, 0x00ff0028);
//
//		if (frac < 0.2f) {
//			outerwidth *= 0.2f;
//			outerheight *= 0.2f;
//		} else {
//			outerwidth *= frac;
//			outerheight *= frac;
//		}
//
//		if (PLAYERCOUNT() >= 2) {
//			outerheight *= 2;
//		}
//
//		if (outerwidth < 5) {
//			outerwidth = 5;
//		}
//
//		if (outerheight < 5) {
//			outerheight = 5;
//		}
//
//		// a600
//		boxtop = viewtop + (halfheight - availableabove * frac);
//		boxleft = viewleft + (halfwidth - availableleft * frac);
//		boxright = viewright - (halfwidth - availableright * frac);
//		boxbottom = viewbottom - (halfheight - availablebelow * frac);
//
//		// Goal loads 1.0f into $at around here
//		// (The +1s in the GBI macros are floats)
//
//		if (outerwidth > boxright - boxleft) {
//			outerwidth = boxright - boxleft;
//		}
//
//		if (outerheight > boxbottom - boxtop) {
//			outerheight = boxbottom - boxtop;
//		}
//
//		// a72c
//		// Top left outer
//		gDPFillRectangleScaled(gdl++, boxleft + 1, boxtop, boxleft + outerwidth - 1 + 1, boxtop + 1);
//		gDPFillRectangleScaled(gdl++, boxleft, boxtop, boxleft + 1, boxtop + outerheight - 1 + 1);
//
//		// Top right outer
//		gDPFillRectangleScaled(gdl++, boxright - outerwidth + 2, boxtop, boxright - 1 + 1, boxtop + 1);
//		gDPFillRectangleScaled(gdl++, boxright, boxtop, boxright + 1, boxtop + outerheight - 1 + 1);
//
//		// Bottom left outer
//		gDPFillRectangleScaled(gdl++, boxleft + 1, boxbottom, boxleft + outerwidth - 1 + 1, boxbottom + 1);
//		gDPFillRectangleScaled(gdl++, boxleft, boxbottom - outerheight + 1, boxleft + 1, boxbottom + 1);
//
//		// Bottom right outer
//		gDPFillRectangleScaled(gdl++, boxright - outerwidth + 2, boxbottom, boxright - 1 + 1, boxbottom + 1);
//		gDPFillRectangleScaled(gdl++, boxright, boxbottom - outerheight + 1, boxright + 1, boxbottom + 1);
//
//		innerwidth = outerwidth >> 1;
//		innerheight = outerheight >> 1;
//
//		// Top left inner
//		gDPFillRectangleScaled(gdl++, boxleft, boxtop, boxleft + innerwidth + 1, boxtop + 1);
//		gDPFillRectangleScaled(gdl++, boxleft, boxtop, boxleft + 1, boxtop + innerheight + 1);
//
//		// Top right inner
//		gDPFillRectangleScaled(gdl++, boxright - innerwidth, boxtop, boxright + 1, boxtop + 1);
//		gDPFillRectangleScaled(gdl++, boxright, boxtop, boxright + 1, boxtop + innerheight + 1);
//
//		// Bottom left inner
//		gDPFillRectangleScaled(gdl++, boxleft, boxbottom, boxleft + innerwidth + 1, boxbottom + 1);
//		gDPFillRectangleScaled(gdl++, boxleft, boxbottom - innerheight, boxleft + 1, boxbottom + 1);
//
//		// Bottom right inner
//		gDPFillRectangleScaled(gdl++, boxright - innerwidth, boxbottom, boxright + 1, boxbottom + 1);
//		gDPFillRectangleScaled(gdl++, boxright, boxbottom - innerheight, boxright + 1, boxbottom + 1);
//
//		gdl = text0f153838(gdl);
//		gdl = text0f153780(gdl);
//	}
//
//	gdl = sightDrawDefault(gdl, sighton);
//
//	return gdl;
//}

Gfx *sightDrawMaian(Gfx *gdl, bool sighton)
{
	s32 viewleft = viGetViewLeft() / g_ScaleX;
	s32 viewtop = viGetViewTop();
	s32 viewwidth = viGetViewWidth() / g_ScaleX;
	s32 viewheight = viGetViewHeight();
	s32 viewright = viewleft + viewwidth - 1;
	s32 viewbottom = viewtop + viewheight - 1;
	s32 x = (s32)g_Vars.currentplayer->crosspos[0] / g_ScaleX;
	s32 y = g_Vars.currentplayer->crosspos[1];
	struct gfxvtx *vertices;
	u32 *colours;
	s32 inner[4];
	bool hasprop = g_Vars.currentplayer->lookingatprop.prop != NULL;
	u32 colour = 0xff000060;

	if (!sighton) {
		return gdl;
	}

	if (sightIsPropFriendly(NULL)) {
		colour = 0x0000ff60;
	}

	vertices = gfxAllocateVertices(8);
	colours = gfxAllocateColours(2);
	gdl = func0f0d479c(gdl);

	gSPClearGeometryMode(gdl++, G_CULL_BOTH);
	gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);
	gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
	gDPSetTextureFilter(gdl++, G_TF_BILERP);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

	vertices[0].x = (viewleft + (viewwidth >> 1)) * 10;
	vertices[0].y = (viewtop + 10) * 10;
	vertices[0].z = -10;
	vertices[1].x = (viewleft + (viewwidth >> 1)) * 10;
	vertices[1].y = (viewbottom - 10) * 10;
	vertices[1].z = -10;
	vertices[2].x = (viewleft + 48) * 10;
	vertices[2].y = (viewtop + (viewheight >> 1)) * 10;
	vertices[2].z = -10;
	vertices[3].x = (viewright - 49) * 10;
	vertices[3].y = (viewtop + (viewheight >> 1)) * 10;
	vertices[3].z = -10;

	inner[0] = x + 4;
	inner[1] = x - 4;
	inner[2] = y + 4;
	inner[3] = y - 4;

	vertices[4].x = inner[1] * 10;
	vertices[4].y = inner[3] * 10;
	vertices[4].z = -10;
	vertices[5].x = inner[0] * 10;
	vertices[5].y = inner[3] * 10;
	vertices[5].z = -10;
	vertices[6].x = inner[0] * 10;
	vertices[6].y = inner[2] * 10;
	vertices[6].z = -10;
	vertices[7].x = inner[1] * 10;
	vertices[7].y = inner[2] * 10;
	vertices[7].z = -10;

	colours[0] = 0x00ff000f;
	colours[1] = hasprop ? colour : 0x00ff0044;

	vertices[0].colour = 0;
	vertices[1].colour = 0;
	vertices[2].colour = 0;
	vertices[3].colour = 0;
	vertices[4].colour = 4;
	vertices[5].colour = 4;
	vertices[6].colour = 4;
	vertices[7].colour = 4;

	// Draw the main 4 triangles
	gDPSetColorArray(gdl++, colours, 2);
	gDPSetVerticeArray(gdl++, vertices, 8);
	gDPTri4(gdl++, 0, 4, 5, 5, 3, 6, 7, 6, 1, 4, 7, 2);

	gdl = func0f0d49c8(gdl);
	gdl = textSetPrimColour(gdl, 0x00ff0028);

	// Draw border over inner points
	gDPFillRectangleScaled(gdl++, x - 4, y - 4, x - 3, y + 5); // left
	gDPFillRectangleScaled(gdl++, x + 4, y - 4, x + 5, y + 5); // right
	gDPFillRectangleScaled(gdl++, x - 4, y - 4, x + 5, y - 3); // top
	gDPFillRectangleScaled(gdl++, x - 4, y + 4, x + 5, y + 5); // bottom

	gdl = text0f153838(gdl);

	return gdl;
}

Gfx *sightDrawTarget(Gfx *gdl)
{
	s32 x = (s32)g_Vars.currentplayer->crosspos[0] / g_ScaleX;
	s32 y = g_Vars.currentplayer->crosspos[1];

	static u32 var80070f9c = 0x00ff00ff;
	static u32 var80070fa0 = 0x00ff0011;

	mainOverrideVariable("sout", &var80070f9c);
	mainOverrideVariable("sin", &var80070fa0);

	gdl = textSetPrimColour(gdl, 0x00ff0028);

	gDPFillRectangleScaled(gdl++, x + 2, y + 0, x + 7, y + 1);
	gDPFillRectangleScaled(gdl++, x + 2, y + 0, x + 5, y + 1);
	gDPFillRectangleScaled(gdl++, x - 6, y + 0, x - 1, y + 1);
	gDPFillRectangleScaled(gdl++, x - 4, y + 0, x - 1, y + 1);
	gDPFillRectangleScaled(gdl++, x + 0, y + 2, x + 1, y + 7);
	gDPFillRectangleScaled(gdl++, x + 0, y + 2, x + 1, y + 5);
	gDPFillRectangleScaled(gdl++, x + 0, y - 6, x + 1, y - 1);
	gDPFillRectangleScaled(gdl++, x + 0, y - 4, x + 1, y - 1);

	gdl = text0f153838(gdl);

	return gdl;
}

bool sightHasTargetWhileAiming(s32 sight)
{
	if (sight == SIGHT_DEFAULT || sight == SIGHT_ZOOM) {
		return true;
	}

	return false;
}

/**
 * sighton is true if the player is using the aimer (ie. holding R).
 */
Gfx *sightDraw(Gfx *gdl, bool sighton, s32 sight)
{
	if (sight);

	if (g_Vars.currentplayer->activemenumode != AMMODE_CLOSED) {
		return gdl;
	}

	if (g_Vars.currentplayer->gunctrl.passivemode) {
		return gdl;
	}

#if PAL
	g_ScaleX = 1;
#else
	if (g_ViRes == VIRES_HI) {
		g_ScaleX = 2;
	} else {
		g_ScaleX = 1;
	}
#endif

	if (PLAYERCOUNT() >= 2 && g_Vars.coopplayernum < 0 && g_Vars.antiplayernum < 0) {
		sight = SIGHT_DEFAULT;
	}

	sightTick(sighton);

	switch (sight) {
	case SIGHT_DEFAULT:
		gdl = sightDrawDefault(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	case SIGHT_CLASSIC:
		gdl = sightDrawClassic(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	case SIGHT_2:
		gdl = sightDrawType2(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	case SIGHT_3:
		gdl = sightDrawDefault(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	case SIGHT_SKEDAR:
		gdl = sightDrawSkedar(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	case SIGHT_ZOOM:
		gdl = sightDrawZoom(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	case SIGHT_MAIAN:
		gdl = sightDrawMaian(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	default:
		gdl = sightDrawDefault(gdl, sighton && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex));
		break;
	case SIGHT_NONE:
		break;
	}

	if (sight != SIGHT_NONE && optionsGetSightOnScreen(g_Vars.currentplayerstats->mpindex)) {
		if ((optionsGetAlwaysShowTarget(g_Vars.currentplayerstats->mpindex) && !sighton)
				|| (sighton && sightHasTargetWhileAiming(sight))) {
			gdl = sightDrawTarget(gdl);
		}
	}

	g_ScaleX = 1;

	return gdl;
}
