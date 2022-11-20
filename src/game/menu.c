#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/game_006900.h"
#include "game/body.h"
#include "game/objectives.h"
#include "game/quaternion.h"
#include "game/bondgun.h"
#include "game/tex.h"
#include "game/camera.h"
#include "game/player.h"
#include "game/modeldef.h"
#include "game/savebuffer.h"
#include "game/menugfx.h"
#include "game/menuitem.h"
#include "game/menu.h"
#include "game/filelist.h"
#include "game/filemgr.h"
#include "game/credits.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/mplayer/setup.h"
#include "game/music.h"
#include "game/texdecompress.h"
#include "game/mplayer/setup.h"
#include "game/challenge.h"
#include "game/training.h"
#include "game/game_1a78b0.h"
#include "game/gamefile.h"
#include "game/gfxmemory.h"
#include "game/lang.h"
#include "game/mplayer/mplayer.h"
#include "game/pak.h"
#include "game/options.h"
#include "game/propobj.h"
#include "bss.h"
#include "lib/joy.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/model.h"
#include "lib/snd.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "lib/str.h"
#include "lib/mtx.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"

#if VERSION >= VERSION_PAL_FINAL
char g_CheatMarqueeString[300];
#elif VERSION >= VERSION_NTSC_1_0
char g_CheatMarqueeString[252];
#else
char g_StringPointer[104];
char g_StringPointer2[100];
#endif

u8 *g_BlurBuffer;
s32 var8009dfc0;
u32 var8009dfc4;
struct briefing g_Briefing;
u32 var8009dfe4;
struct missionconfig g_MissionConfig;
struct menu g_Menus[4];
struct menudata g_MenuData;
s32 g_MenuScissorX1;
s32 g_MenuScissorX2;
s32 g_MenuScissorY1;
s32 g_MenuScissorY2;
Vp var800a2048[4][2];

#if VERSION >= VERSION_NTSC_1_0
struct menudialogdef g_PakCannotReadGameBoyMenuDialog;
struct menudialogdef g_PakDamagedMenuDialog;
struct menudialogdef g_PakDataLostMenuDialog;
#else
struct menudialogdef g_PakDamagedMenuDialog;
#endif

struct menudialogdef g_PakFullMenuDialog;
struct menudialogdef g_PakRemovedMenuDialog;
struct menudialogdef g_PakRepairFailedMenuDialog;
struct menudialogdef g_PakRepairSuccessMenuDialog;

#if VERSION >= VERSION_JPN_FINAL
const struct menucolourpalette g_MenuColourPalettes[] = {
	{ 0x20202000, 0x20202000, 0x20202000, 0x4f4f4f00, 0x00000000, 0x00000000, 0x4f4f4f00, 0x4f4f4f00, 0x4f4f4f00, 0x4f4f4f00, 0x00000000, 0x00000000, 0x4f4f4f00, 0x00000000, 0x00000000 },
	{ 0x0060bf7f, 0x0000507f, 0x00f0ff7f, 0xffffffff, 0x00002f9f, 0x00006f7f, 0x00ffffff, 0x007f7fff, 0xffffffff, 0x8fffffff, 0x000044ff, 0x000030ff, 0x7f7fffff, 0xffffffff, 0x6644ff7f },
	{ 0xbf00007f, 0x5000007f, 0xff00007f, 0xffff00ff, 0x2f00009f, 0x6f00007f, 0xff9070ff, 0x7f0000ff, 0xffff00ff, 0xffa090ff, 0x440000ff, 0x003000ff, 0xffff00ff, 0xffffffff, 0xff44447f },
	{ 0x00bf007f, 0x0050007f, 0x00ff007f, 0xffff00ff, 0x002f009f, 0x00ff0028, 0x55ff55ff, 0x006f00af, 0xffffffff, 0x00000000, 0x004400ff, 0x003000ff, 0xffff00ff, 0xffffffff, 0x44ff447f },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff9f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
	{ 0xaaaaaaff, 0xaaaaaa7f, 0xaaaaaaff, 0xffffffff, 0xffffff9f, 0xffffffff, 0xffffffff, 0xffffffff, 0xff8888ff, 0xffffffff, 0x00000000, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
};
#else
const struct menucolourpalette g_MenuColourPalettes[] = {
	{ 0x20202000, 0x20202000, 0x20202000, 0x4f4f4f00, 0x00000000, 0x00000000, 0x4f4f4f00, 0x4f4f4f00, 0x4f4f4f00, 0x4f4f4f00, 0x00000000, 0x00000000, 0x4f4f4f00, 0x00000000, 0x00000000 },
	{ 0x0060bf7f, 0x0000507f, 0x00f0ff7f, 0xffffffff, 0x00002f7f, 0x00006f7f, 0x00ffffff, 0x007f7fff, 0xffffffff, 0x8fffffff, 0x000044ff, 0x000030ff, 0x7f7fffff, 0xffffffff, 0x6644ff7f },
	{ 0xbf00007f, 0x5000007f, 0xff00007f, 0xffff00ff, 0x2f00007f, 0x6f00007f, 0xff7050ff, 0x7f0000ff, 0xffff00ff, 0xff9070ff, 0x440000ff, 0x003000ff, 0xffff00ff, 0xffffffff, 0xff44447f },
	{ 0x00bf007f, 0x0050007f, 0x00ff007f, 0xffff00ff, 0x002f007f, 0x00ff0028, 0x55ff55ff, 0x006f00af, 0xffffffff, 0x00000000, 0x004400ff, 0x003000ff, 0xffff00ff, 0xffffffff, 0x44ff447f },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
	{ 0xaaaaaaff, 0xaaaaaa7f, 0xaaaaaaff, 0xffffffff, 0xffffff2f, 0xffffffff, 0xffffffff, 0xffffffff, 0xff8888ff, 0xffffffff, 0x00000000, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
};
#endif

const struct menucolourpalette g_MenuColourPalettes2[] = {
	{ 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x4f4f4f00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000 },
	{ 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x006f6faf, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000 },
	{ 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x006f6faf, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000 },
	{ 0xffffff00, 0xffffff00, 0xffffff00, 0xff7f0000, 0xffffff00, 0xffffff00, 0x00ffff00, 0x006f6faf, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0xffffff00, 0x00000000 },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
};

const struct menucolourpalette g_MenuColourPalettes3[] = {
	{ 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x4f4f4f00, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x00000000 },
	{ 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x006f6faf, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x00000000 },
	{ 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x006f6faf, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x00000000 },
	{ 0x44444400, 0x44444400, 0x44444400, 0x00ff0000, 0x44444400, 0x44444400, 0xffff0000, 0x006f6faf, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x44444400, 0x00000000 },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
	{ 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffff7f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffff5f, 0xffffffff, 0xffffff7f, 0xffffffff },
};

#if VERSION >= VERSION_NTSC_1_0
char *g_StringPointer = g_CheatMarqueeString;
char *g_StringPointer2 = &g_CheatMarqueeString[VERSION >= VERSION_PAL_FINAL ? 150 : 125];
#endif

s32 g_MpPlayerNum = 0;

void menuPlaySound(s32 menusound)
{
	s32 sound = -1;
	s32 flag1 = false;
	s32 flag2 = false;
	f32 speed = 1;

	switch (menusound) {
	case MENUSOUND_SWIPE:
		sound = SFX_MENU_SWIPE;
		break;
	case MENUSOUND_OPENDIALOG:
		sound = SFX_MENU_OPENDIALOG;
		break;
	case MENUSOUND_FOCUS:
		sound = SFX_MENU_FOCUS;
		break;
	case MENUSOUND_SELECT:
		sound = SFX_MENU_SELECT;
		break;
	case MENUSOUND_ERROR:
		speed = 0.4f;
		sound = SFX_MENU_ERROR;
		flag1 = true;
		break;
	case MENUSOUND_EXPLOSION:
		sound = SFX_EXPLOSION_8098;
		break;
	case MENUSOUND_TOGGLEON:
		sound = SFX_MENU_SELECT;
		break;
	case MENUSOUND_TOGGLEOFF:
		sound = SFX_MENU_SUBFOCUS;
		break;
	case MENUSOUND_SUBFOCUS:
		sound = SFX_MENU_SUBFOCUS;
		break;
	case MENUSOUND_KEYBOARDFOCUS:
		sound = SFX_PICKUP_AMMO;
		flag1 = true;
		flag2 = true;
		speed = 3.5f;
		break;
	case MENUSOUND_KEYBOARDCANCEL:
		sound = SFX_MENU_CANCEL;
		flag1 = true;
		speed = 0.41904801130295f;
		break;
	}

	if (sound != -1) {
		struct sndstate *handle;

#if VERSION >= VERSION_NTSC_1_0
		OSPri prevpri = osGetThreadPri(NULL);
		osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);
#endif

		handle = sndStart(var80095200, sound, NULL, -1, -1, -1, -1, -1);

		if (handle && flag1) {
			audioPostEvent(handle, 16, *(s32 *)&speed);
		}

		if (handle && flag2) {
			audioPostEvent(handle, 8, 0x4000);
		}

#if VERSION >= VERSION_NTSC_1_0
		osSetThreadPri(0, prevpri);
#endif
	}
}

bool menuIsSoloMissionOrMp(void)
{
	switch (g_MenuData.root) {
	case MENUROOT_MAINMENU:
	case MENUROOT_TRAINING:
		if (g_Vars.stagenum == STAGE_CITRAINING) {
			return false;
		}

		return true;
	case MENUROOT_MPPAUSE:
		return true;
	}

	return false;
}

bool currentPlayerIsMenuOpenInSoloOrMp(void)
{
	s32 mpindex = g_Vars.currentplayerstats->mpindex;

	if (menuIsSoloMissionOrMp()) {
		if (mpindex >= 4) {
			mpindex -= 4;
		}

		if (g_Menus[mpindex].curdialog) {
			return true;
		}
	}

	return false;
}

bool func0f0f0c68(void)
{
	if (g_MenuData.bg || g_MenuData.nextbg != 255) {
		return false;
	}

	return true;
}

void menuSetBanner(s32 bannernum, bool allplayers)
{
	if (allplayers) {
		g_MenuData.bannernum = bannernum;
		return;
	}

	g_Menus[g_MpPlayerNum].bannernum = bannernum;
}

#if VERSION >= VERSION_NTSC_1_0
Gfx *menuRenderBanner(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, bool big, s32 msgnum, s32 arg7, s32 arg8)
#else
Gfx *menuRenderBanner(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, bool big, s32 msgnum)
#endif
{
	s32 midx;
	s32 x;
	s32 y;
	s32 texttop;
	s32 textheight;
	s32 textwidth;
	s32 waitheight;
	s32 waitwidth;
	s32 bannertop;
	s32 bannerbottom;
	struct fontchar *chars;
	struct font *font;

	static u16 msgs[] = {
		L_MPMENU_484, // "Searching for Camera!"
		L_MPMENU_485, // "Calibrating Camera"
		L_MPMENU_486, // "Downloading Image"
		L_MPMENU_487, // "Loading Image"
		L_MPMENU_488, // "Saving Image"
		L_MPMENU_489, // "Transferring Image"
		L_MPMENU_490, // "Uploading Segment"
		L_MPMENU_491, // "Checking Controller Pak"
		L_MPMENU_492, // "Getting PerfectHead"
		L_MPMENU_493, // "Saving PerfectHead"
		L_MPMENU_494, // "Auto Camera Adjustment"
	};

	chars = g_CharsHandelGothicSm;
	font = g_FontHandelGothicSm;

	if (big) {
#if VERSION >= VERSION_PAL_BETA
		if (g_CharsHandelGothicMd) {
			chars = g_CharsHandelGothicMd;
			font = g_FontHandelGothicMd;
		}
#else
		chars = g_CharsHandelGothicMd;
		font = g_FontHandelGothicMd;
#endif
	}

#if VERSION >= VERSION_NTSC_1_0
	midx = (x1 + arg7 + x2 - arg8) / 2;
#else
	midx = (x1 + x2) / 2;
#endif

	y = (y1 + y2) / 2;

	textMeasure(&textheight, &textwidth, langGet(msgs[msgnum]), chars, font, 0);

	// "Please Wait..."
	textMeasure(&waitheight, &waitwidth, langGet(L_MPMENU_495), chars, font, 0);

#if VERSION >= VERSION_NTSC_1_0 && VERSION < VERSION_JPN_FINAL
	if (msgs[msgnum] == L_MPMENU_491) { // "Checking Controller Pak"
		// Add space for "TM"
		textwidth += 7;
	}
#endif

	y -= (textheight + waitheight) / 2;
	texttop = y;
	bannertop = y - 4;
	bannerbottom = y + textheight + waitheight + 7;

	// Black fill
	gdl = textSetPrimColour(gdl, 0x0000007f);
	gDPFillRectangleScaled(gdl++, x1, y1, x2, y2);
	gdl = text0f153838(gdl);

	// Dark blue fill
	gdl = textSetPrimColour(gdl, 0x00007f7f);
	gDPFillRectangleScaled(gdl++, x1, bannertop, x2, bannerbottom);
	gdl = text0f153838(gdl);

	// Top and bottom borders (light blue)
	gdl = textSetPrimColour(gdl, 0x7f7fff7f);
	gDPFillRectangleScaled(gdl++, x1, bannerbottom + 2, x2, bannerbottom + 4);
	gDPFillRectangleScaled(gdl++, x1, bannertop - 4, x2, bannertop - 2);
	gdl = text0f153838(gdl);

	gdl = text0f153628(gdl);

	// Render the selected message's shadow
	x = midx - textwidth / 2 + 2;
	y += 2;
	gdl = textRenderProjected(gdl, &x, &y, langGet(msgs[msgnum]),
			chars, font, 0x000000ff, viGetWidth(), viGetWidth(), 0, 0);

	// Render "Please Wait..." shadow
	x = midx - waitwidth / 2 + 2;
	y += 3;
	gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_495),
			chars, font, 0x000000ff, viGetWidth(), viGetWidth(), 0, 0);

	// Render the selected message proper
	x = midx - textwidth / 2;
	y = texttop;
	gdl = textRenderProjected(gdl, &x, &y, langGet(msgs[msgnum]),
			chars, font, 0xbfbfffff, viGetWidth(), viGetWidth(), 0, 0);

	// Render "Please Wait..." proper
	x = midx - waitwidth / 2;
	y += 3;
	gdl = textRenderProjected(gdl, &x, &y, langGet(L_MPMENU_495),
			chars, font, 0xbfbfffff, viGetWidth(), viGetWidth(), 0, 0);

#if VERSION >= VERSION_NTSC_1_0 && VERSION < VERSION_JPN_FINAL
	if (msgs[msgnum] == L_MPMENU_491) { // "Checking Controller Pak"
		// Render "TM"
		y = texttop - 1;
		x = textwidth / 2 + midx - 7;
		gdl = textRenderProjected(gdl, &x, &y, "TM",
				g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xbfbfffff, viGetWidth(), viGetWidth(), 0, 0);
	}
#endif

	gdl = text0f153780(gdl);

	return gdl;
}

u32 var80071464 = 0;

struct menudfc *func0f0f1338(struct menuitem *item)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_Menus[g_MpPlayerNum].unkdfc[i].item == item) {
			return &g_Menus[g_MpPlayerNum].unkdfc[i];
		}
	}

	return NULL;
}

void func0f0f139c(struct menuitem *item, f32 arg1)
{
	struct menudfc *thing = func0f0f1338(item);

	if (thing) {
		thing->unk04 = arg1;
		return;
	}

	thing = func0f0f1338(NULL);

	if (thing) {
		thing->item = item;
		thing->unk04 = arg1;
	}
}

void func0f0f13ec(struct menuitem *item)
{
	struct menudfc *thing = func0f0f1338(item);

	if (thing) {
		thing->item = NULL;
	}
}

void func0f0f1418(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		if (g_Menus[g_MpPlayerNum].unkdfc[i].item) {
#if VERSION >= VERSION_PAL_BETA
			g_Menus[g_MpPlayerNum].unkdfc[i].unk04 += g_Vars.diffframe60freal / 60.0f;
#else
			g_Menus[g_MpPlayerNum].unkdfc[i].unk04 += g_Vars.diffframe60f / 60.0f;
#endif
		}
	}
}

void func0f0f1494(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		g_Menus[g_MpPlayerNum].unkdfc[i].item = NULL;
	}
}

char *menuResolveText(u32 thing, void *dialogoritem)
{
	char *(*handler)(void *dialogoritem) = (void *)thing;

	// Null/zero
	if (thing == 0) {
		return NULL;
	}

	// Text ID
	if (thing < 0x5a00) {
		return langGet((u32)thing);
	}

	if (thing > (u32)func0f1a78b0) {
#if VERSION < VERSION_NTSC_1_0
		CRASH();
#endif
		return NULL;
	}

	// Function pointer
	if (handler) {
		return handler(dialogoritem);
	}

	return "";
}

char *menuResolveParam2Text(struct menuitem *item)
{
	return menuResolveText(item->param2, item);
}

char *menuResolveDialogTitle(struct menudialogdef *dialogdef)
{
	return menuResolveText(dialogdef->title, dialogdef);
}

void func0f0f15a4(struct menuitem *item, s32 *arg1)
{
	switch (item->type) {
	case MENUITEMTYPE_SLIDER:
	case MENUITEMTYPE_CHECKBOX:
	case MENUITEMTYPE_RANKING:
	case MENUITEMTYPE_14:
	case MENUITEMTYPE_18:
		*arg1 = 1;
		break;
#if VERSION < VERSION_PAL_BETA
	case MENUITEMTYPE_SCROLLABLE:
#endif
	case MENUITEMTYPE_MARQUEE:
	case MENUITEMTYPE_CONTROLLER:
		*arg1 = 2;
		break;
	case MENUITEMTYPE_LIST:
#if VERSION >= VERSION_PAL_BETA
	case MENUITEMTYPE_SCROLLABLE:
#endif
		*arg1 = 3;
		break;
	case MENUITEMTYPE_DROPDOWN:
		*arg1 = 4;
		break;
	case MENUITEMTYPE_PLAYERSTATS:
		*arg1 = 5;
		break;
	case MENUITEMTYPE_KEYBOARD:
	case MENUITEMTYPE_10:
	case MENUITEMTYPE_16:
		*arg1 = 3;
		break;
	}
}

void menuCalculateItemSize(struct menuitem *item, s16 *width, s16 *height, struct menudialog *dialog)
{
	char *text;
	s32 textwidth;
	s32 textheight;
	struct fontchar *chars = g_CharsHandelGothicSm;
	struct font *font = g_FontHandelGothicSm;
	s32 i;
	union handlerdata handlerdata;
	union handlerdata handlerdata2;
	char *text2;
	s32 numobjectives;

	// Check if item's handler handles MENUOP_CHECKHIDDEN
	if (item->handler && (item->flags & MENUITEMFLAG_SELECTABLE_OPENSDIALOG) == 0) {
		if (item->handler(MENUOP_CHECKHIDDEN, item, &handlerdata)) {
			*width = 0;
			*height = 0;
			return;
		}
	}

	switch (item->type) {
	case MENUITEMTYPE_CONTROLLER:
#if VERSION == VERSION_JPN_FINAL
		*height = 190;
		*width = 240;
#elif PAL
		*height = 156;
		*width = 230;
#else
		*height = 150;
		*width = 230;
#endif
		break;
	case MENUITEMTYPE_18:
		*height = item->param2 == 1 ? 170 : 126;
		*width = 210;
		break;
	case MENUITEMTYPE_14:
		*width = 90;
		*height = 54;
		break;
	case MENUITEMTYPE_METER:
		*width = 24;
		*height = 6;
		break;
	case MENUITEMTYPE_KEYBOARD:
		*width = 130;
		*height = 73;
		break;
	case MENUITEMTYPE_LIST:
		if (item->param2 > 0) {
			*width = item->param2;
		} else {
			*width = 80;

#if VERSION >= VERSION_NTSC_1_0
			if ((item->flags & MENUITEMFLAG_LIST_WIDE) != 0) {
				*width = 180;
			}
#else
			if ((item->flags && MENUITEMFLAG_LIST_WIDE) != 0) {
				*width = 180;
			}
#endif
		}

#if VERSION >= VERSION_JPN_FINAL
		*height = item->param3 > 0 ? item->param3 : 112;
#else
		*height = item->param3 > 0 ? item->param3 : 121;
#endif
		break;
	case MENUITEMTYPE_DROPDOWN:
		text = menuResolveParam2Text(item);

		if (text && strcmp(text, "") == 0) {
			*width = 0;
			*height = 0;
		} else {
			textwidth = 0;
			textheight = 0;

			if (text != NULL) {
				textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);
			}

			*width = textwidth + 20;
			*height = VERSION == VERSION_JPN_FINAL ? 14 : 12;

			if (item->handler) {
				handlerdata2.dropdown.value = 0;
				item->handler(MENUOP_GETSELECTEDINDEX, item, &handlerdata2);
				handlerdata2.dropdown.unk04 = 0;
				text2 = (char *)item->handler(MENUOP_GETOPTIONTEXT, item, &handlerdata2);
				textMeasure(&textheight, &textwidth, text2, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

#if VERSION >= VERSION_PAL_FINAL
				if ((item->flags & MENUITEMFLAG_ADJUSTWIDTH) == 0) {
					*width += textwidth + 10;
				} else {
					*width += textwidth + 3;
				}
#else
				*width += textwidth + 10;
#endif
			}
		}
		break;
	case MENUITEMTYPE_13:
		*width = 70;
		*height = 50;
		break;
	case MENUITEMTYPE_SLIDER:
		if (dialog && dialog->unk6e) {
			*width = 120;
			*height = 22;
			return;
		}

		*width = 150;
		*height = VERSION == VERSION_JPN_FINAL ? 14 : 12;

		if (item->flags & MENUITEMFLAG_SLIDER_ALTSIZE) {
			*height = 22;
			*width = 120;
		}
		break;
	case MENUITEMTYPE_CHECKBOX:
		if (item->flags & MENUITEMFLAG_SMALLFONT) {
			chars = g_CharsHandelGothicXs;
			font = g_FontHandelGothicXs;
		}

		text = menuResolveParam2Text(item);

		if (text == NULL) {
			*width = 120;
		} else if (strcmp(text, "") == 0) {
			*width = 0;
			*height = 0;
		} else {
			textMeasure(&textheight, &textwidth, text, chars, font, 0);
			*width = (s16)textwidth + 34;
		}
		*height = VERSION == VERSION_JPN_FINAL ? 14 : 12;
		break;
	case MENUITEMTYPE_MODEL:
		*width = item->param2;
		*height = item->param3;
		break;
	case MENUITEMTYPE_SEPARATOR:
		*width = 1;
		if (item->param2) {
			*width = item->param2;
		}
		*height = VERSION == VERSION_JPN_FINAL ? 2 : 5;
		break;
	case MENUITEMTYPE_MARQUEE:
		*width = 1;
#if VERSION == VERSION_JPN_FINAL
		*height = LINEHEIGHT;
#else
		if (item->flags & MENUITEMFLAG_SMALLFONT) {
			*height = LINEHEIGHT;
		} else {
			*height = LINEHEIGHT + 2;
		}
#endif
		break;
	case MENUITEMTYPE_LABEL:
	case MENUITEMTYPE_SELECTABLE:
		text = menuResolveParam2Text(item);

		if (text == NULL) {
			*width = 0;
			*height = 0;
			return;
		}

		if (item->flags & MENUITEMFLAG_SMALLFONT) {
			chars = g_CharsHandelGothicXs;
			font = g_FontHandelGothicXs;
		}

		if (item->flags & MENUITEMFLAG_BIGFONT) {
			chars = g_CharsHandelGothicMd;
			font = g_FontHandelGothicMd;
		}

		if (strcmp(text, "") == 0) {
			*height = 0;
			*width = *height;
		} else {
			textMeasure(&textheight, &textwidth, text, chars, font, 0);
			*width = (s16)textwidth + 8;

			if ((item->flags & (MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_ADJUSTWIDTH)) == 0) {
				*width += 20;
			}

#if VERSION == VERSION_JPN_FINAL
			*height = textheight;
#else
			*height = textheight + 3;

			if (item->flags & MENUITEMFLAG_SMALLFONT) {
				*height -= 2;
			}
#endif

			if ((item->flags & (MENUITEMFLAG_LABEL_HASRIGHTTEXT | MENUITEMFLAG_BIGFONT)) == 0) {
				text = menuResolveText(item->param3, item);

				// @bug: This is not how you check for an empty string
				if (text != NULL && text != "") {
					textMeasure(&textheight, &textwidth, text, chars, font, 0);
					*width += textwidth + 5;

					if (item->flags & MENUITEMFLAG_ADJUSTWIDTH) {
						*width -= 6;
					}
				}
			}
		}

		if (item->flags & MENUITEMFLAG_BIGFONT) {
			*height = 28;
			*width += 36;
		}

		if (item->flags & MENUITEMFLAG_LESSHEIGHT) {
			*height -= 1;
		}
		break;
	case MENUITEMTYPE_SCROLLABLE:
		*width = item->param2 > 0 ? item->param2 : 240;
		*height = item->param3 > 0 ? item->param3 : 150;
		break;
	case MENUITEMTYPE_OBJECTIVES:
		numobjectives = 0;
		*width = 240;

		for (i = 0; i < 6; i++) {
			if (g_Briefing.objectivenames[i] && (g_Briefing.objectivedifficulties[i] & (1 << lvGetDifficulty()))) {
				numobjectives++;
			}
		}

#if VERSION >= VERSION_JPN_FINAL
		if (item->param == 0) {
			*height = 9 + numobjectives * 24;
		} else if (item->param == 1) {
			*height = 9 + numobjectives * 16;
		} else if (item->param == 2) {
			*height = 9 + numobjectives * 36;
			*height -= 5;
			*width = 120;
		}
#elif VERSION >= VERSION_PAL_FINAL
		if (item->param == 0) {
			*height = 9 + numobjectives * 18;
		} else if (item->param == 1) {
			*height = 9 + numobjectives * 14;
		} else if (item->param == 2) {
			*height = 9 + numobjectives * 34;
			*width = 120;
		}
#else
		if (item->param == 0) {
			*height = 9 + numobjectives * 18;
		} else if (item->param == 1) {
			*height = 9 + numobjectives * 14;
		} else if (item->param == 2) {
			*height = 9 + numobjectives * 30;
			*width = 120;
		}
#endif
		break;
	case MENUITEMTYPE_07:
		*width = 120;
		*height = 120;
		break;
	case MENUITEMTYPE_PLAYERSTATS:
		*width = 125;
		*height = 68;
		break;
	case MENUITEMTYPE_RANKING:
		*width = 125;
		*height = 58;
		break;
	case MENUITEMTYPE_10:
		*width = item->param2 ? item->param2 + 2 : 66;
		*height = *width;
		break;
	case MENUITEMTYPE_16:
		*width = 66;
		*height = *width;
		break;
	case MENUITEMTYPE_CAROUSEL:
		*width = 130;
		*height = item->param3;
		break;
	default:
		*width = 80;
		*height = 12;
		break;
	}
}

const char var7f1b2400[] = "(BNC:Menu) findItem Warning: Item not found\n";
const char var7f1b2430[] = "(BNC:Menu) menuFirstFocus - Menu %s does not have any focusable item!\n";
const char var7f1b2478[] = "(BNC:Menu) menuLastFocus - Menu %s does not have any focusable item!\n";
const char var7f1b24c0[] = "Init menu %x\n";
const char var7f1b24d0[] = "[]-[] Added Main menu to ctl slot %d\n";
const char var7f1b24f8[] = "[]-[] Added Slide menu to ctl slot %d\n";
const char var7f1b2520[] = "[]-[] StackStart Stats: slides %d, ctlPtr %d slidePtr %d\n";
const char var7f1b255c[] = "$-$-$avePtr: %d\n";
const char var7f1b2570[] = "[]-[] Menu End: now %d slides\n";
const char var7f1b2590[] = "Freeing challenge mem\n";
const char var7f1b25a8[] = "IG:) style %d gbHead:%d\n";
const char var7f1b25c4[] = "GRABBED GUN MEM!\n";
const char var7f1b25d8[] = "Freeing challenge mem\n";

void func0f0f1d6c(struct menudialogdef *dialogdef, struct menudialog *dialog, struct menu *menu)
{
	s32 colindex = menu->colend - 1;
	s32 rowindex = menu->rowend;
	s32 itemindex = 0;
	s32 numblocksthisitem;
	struct menuitem *item = dialogdef->items;
	s16 blockindex = menu->blockend;

	dialog->numcols = 0;
	dialog->colstart = (u16) colindex + 1;
	dialog->blockstart = blockindex;

	if (item) {
		bool newcolumn = true;

		while (item->type != MENUITEMTYPE_END) {
			if (item->flags & MENUITEMFLAG_NEWCOLUMN) {
				newcolumn = true;
			}

			if (newcolumn) {
				dialog->numcols++;
				colindex++;

				menu->cols[colindex].width = 0;
				menu->cols[colindex].height = 0;
				menu->cols[colindex].unk04 = 0;
				menu->cols[colindex].numrows = 0;
				menu->cols[colindex].rowstart = rowindex;

				newcolumn = false;
			}

			numblocksthisitem = -1;
			func0f0f15a4(item, &numblocksthisitem);

			if (numblocksthisitem != -1) {
				menu->rows[rowindex].blockindex = blockindex;
				blockindex += (s16)numblocksthisitem;
			} else {
				menu->rows[rowindex].blockindex = -1;
			}

			menu->rows[rowindex].itemindex = itemindex;
			menu->cols[colindex].numrows++;
			rowindex++;
			item++;
			itemindex++;
		}
	}

	menu->colend = colindex + 1;
	menu->rowend = rowindex;
	menu->blockend = blockindex;
}

void dialog0f0f1ef4(struct menudialog *dialog)
{
	s32 bodyheight = dialog->height - LINEHEIGHT - 1;
	s32 itemheight;
	s32 i;
	s32 j;

	if ((dialog->definition->flags & MENUDIALOGFLAG_SMOOTHSCROLLABLE) == 0
			&& g_MenuData.root != MENUROOT_TRAINING
			&& bodyheight < dialog->contentheight) {
		for (i = 0; i < dialog->numcols; i++) {
			s32 colindex = dialog->colstart + i;
			s32 remaining = g_Menus[g_MpPlayerNum].cols[colindex].height - bodyheight;

			if (remaining > 0) {
				for (j = 0; j < g_Menus[g_MpPlayerNum].cols[colindex].numrows; j++) {
					if (remaining > 0) {
						s32 itemheight = 0;
						s32 rowindex = g_Menus[g_MpPlayerNum].cols[colindex].rowstart + j;
						struct menuitem *item = &dialog->definition->items[g_Menus[g_MpPlayerNum].rows[rowindex].itemindex];

						switch (item->type) {
						case MENUITEMTYPE_LIST:
							if (item->flags & MENUITEMFLAG_LIST_CUSTOMRENDER) {
								itemheight = remaining;

								if (g_Menus[g_MpPlayerNum].rows[rowindex].height - itemheight < 30) {
									itemheight = g_Menus[g_MpPlayerNum].rows[rowindex].height - 30;
								}
							} else {
								itemheight = (remaining + 10) / 11 * 11;
							}
							break;
						case MENUITEMTYPE_SCROLLABLE:
						case MENUITEMTYPE_MODEL:
							itemheight = remaining;
							if (g_Menus[g_MpPlayerNum].rows[rowindex].height - remaining < 50) {
								itemheight = g_Menus[g_MpPlayerNum].rows[rowindex].height - 50;
							}
							break;
						}

						if (itemheight > 0) {
							g_Menus[g_MpPlayerNum].rows[rowindex].height -= itemheight;
							remaining -= itemheight;
						}
					}
				}
			}
		}
	}
}

void dialogCalculateContentSize(struct menudialogdef *dialogdef, struct menudialog *dialog, struct menu *menu)
{
	s32 contentheight;
	s32 rowindex;
	s32 contentwidth;
	s32 titleextra;
	s32 i;
	s32 textwidth;
	s32 textheight;
	u32 stack;
	struct menuitem *item = dialogdef->items;
	s32 colindex = dialog->colstart - 1;

	// Iterate items and calculate their dimensions
	if (item != NULL) {
		bool newcolumn = true;
		s16 width;
		s16 height;

		while (item->type != MENUITEMTYPE_END) {
			if (item->flags & MENUITEMFLAG_NEWCOLUMN) {
				newcolumn = true;
			}

			if (newcolumn) {
				colindex++;
				menu->cols[colindex].width = 0;
				menu->cols[colindex].height = 0;

				newcolumn = false;
				rowindex = menu->cols[colindex].rowstart;
			}

			menuCalculateItemSize(item, &width, &height, dialog);

			if (width > menu->cols[colindex].width) {
				menu->cols[colindex].width = width;
			}

			menu->rows[rowindex].height = height;
			menu->cols[colindex].height += height;
			rowindex++;
			item++;
		}
	}

	contentheight = 0;
	contentwidth = 0;

	for (i = 0; i < dialog->numcols; i++) {
		s32 columnheight = menu->cols[dialog->colstart + i].height;

		contentwidth += menu->cols[dialog->colstart + i].width;

		if (columnheight > contentheight) {
			contentheight = columnheight;
		}
	}

#if VERSION == VERSION_JPN_FINAL
	contentheight += 15;

	if ((dialog->definition->flags & MENUDIALOGFLAG_1000) == 0) {
		contentheight += 2;
	}
#else
	contentheight += 12;
#endif

	// Calculate and consider the title width.
	// Some of the multiplayer dialogs have a player number
	// in the top right, so extra space is considered for those.
	textMeasure(&textheight, &textwidth, menuResolveDialogTitle(dialog->definition), g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

	titleextra = 8;

	switch (g_MenuData.root) {
	case MENUROOT_MPSETUP:
	case MENUROOT_MPPAUSE:
	case MENUROOT_MPENDSCREEN:
	case MENUROOT_4MBMAINMENU:
		titleextra = 17;
		break;
	}

	if (textwidth + titleextra > contentwidth) {
		contentwidth = textwidth + titleextra;
	}

	dialog->contentwidth = contentwidth;
	dialog->contentheight = contentheight;
}

/**
 * Find the given item in the given dialog, and write its column and row indices
 * to the given pointers. Return the y value of the item relative to the dialog.
 */
s32 dialogFindItem(struct menudialog *dialog, struct menuitem *item, s32 *rowindex, s32 *colindex)
{
	for (*colindex = dialog->colstart; *colindex < dialog->colstart + dialog->numcols; *colindex += 1) {
		s32 y = 0;
		*rowindex = g_Menus[g_MpPlayerNum].cols[*colindex].rowstart;

		while (*rowindex < g_Menus[g_MpPlayerNum].cols[*colindex].rowstart + g_Menus[g_MpPlayerNum].cols[*colindex].numrows) {
			struct menuitem *thisitem = &dialog->definition->items[g_Menus[g_MpPlayerNum].rows[*rowindex].itemindex];

			if (thisitem == item) {
				return y;
			}

			y = y + g_Menus[g_MpPlayerNum].rows[*rowindex].height;
			*rowindex += 1;
		}
	}

	*colindex = dialog->colstart;
	*rowindex = g_Menus[g_MpPlayerNum].cols[*colindex].rowstart;

	return 0;
}

/**
 * If this returns true, the scrollable is rendered with less padding and
 * scrolling is disabled.
 */
bool menuIsScrollableUnscrollable(struct menuitem *item)
{
	if (item->type == MENUITEMTYPE_SCROLLABLE) {
		if (item->param == DESCRIPTION_MPCONFIG
				|| item->param == DESCRIPTION_MPCHALLENGE
				|| item->param == DESCRIPTION_DEVICETRAINING
				|| item->param == DESCRIPTION_FRWEAPON
				|| item->param == DESCRIPTION_HOLOTRAINING) {
			return true;
		}
	}

	return false;
}

bool menuIsItemDisabled(struct menuitem *item, struct menudialog *dialog)
{
	union handlerdata sp30;
	s16 width;
	s16 height;
	u32 stack[2];

	if (item->flags & MENUITEMFLAG_ALWAYSDISABLED) {
		return true;
	}

	if (mpIsPlayerLockedOut(g_MpPlayerNum) && item->flags & MENUITEMFLAG_LOCKABLEMAJOR) {
		return true;
	}

	if (menuIsScrollableUnscrollable(item)) {
		return true;
	}

	if (item->handler
			&& (item->flags & MENUITEMFLAG_SELECTABLE_OPENSDIALOG) == 0
			&& item->handler(MENUOP_CHECKDISABLED, item, &sp30)) {
		return true;
	}

	menuCalculateItemSize(item, &width, &height, dialog);

	if (height == 0) {
		return true;
	}

	return false;
}

bool menuIsItemFocusable(struct menuitem *item, struct menudialog *dialog, s32 arg2)
{
	s32 rowindex;
	s32 colindex;

	switch (item->type) {
	case MENUITEMTYPE_LABEL:
	case MENUITEMTYPE_OBJECTIVES:
	case MENUITEMTYPE_07:
	case MENUITEMTYPE_SEPARATOR:
	case MENUITEMTYPE_MODEL:
	case MENUITEMTYPE_13:
	case MENUITEMTYPE_METER:
	case MENUITEMTYPE_MARQUEE:
	case MENUITEMTYPE_CONTROLLER:
		return false;
	case MENUITEMTYPE_10:
	case MENUITEMTYPE_14:
	case MENUITEMTYPE_16:
	case MENUITEMTYPE_18:
		dialogFindItem(dialog, item, &rowindex, &colindex);
	}

	if (menuIsItemDisabled(item, dialog)) {
		return false;
	}

	return true;
}

struct menuitem *dialogFindItemAtColY(s32 targety, s32 colindex, struct menudialogdef *dialogdef, s32 *rowindexptr, struct menudialog *dialog)
{
	struct menuitem *result = NULL;
	bool done = false;
	s32 rowindex = g_Menus[g_MpPlayerNum].cols[colindex].rowstart;
	s32 y;
	s32 i;

	for (i = 0, y = 0; !done && i < g_Menus[g_MpPlayerNum].cols[colindex].numrows; rowindex++, i++) {
		struct menuitem *item = &dialogdef->items[g_Menus[g_MpPlayerNum].rows[rowindex].itemindex];

		if (menuIsItemFocusable(item, dialog, 1)) {
			result = item;

			if (y >= targety) {
				done = true;
			}

			*rowindexptr = rowindex;
		}

		y = y + g_Menus[g_MpPlayerNum].rows[rowindex].height;
	}

	return result;
}

struct menuitem *dialogFindFirstItem(struct menudialog *dialog)
{
	s32 i;
	s32 colindex = dialog->colstart;
	s32 rowindex;

	for (i = 0; i < dialog->numcols; i++) {
		struct menuitem *item = dialogFindItemAtColY(0, colindex, dialog->definition, &rowindex, dialog);

		if (item != NULL) {
			return item;
		}

		colindex++;
	}

	menuResolveDialogTitle(dialog->definition);

	return dialog->definition->items;
}

struct menuitem *dialogFindFirstItemRight(struct menudialog *dialog)
{
	s32 i;
	s32 colindex = dialog->colstart + dialog->numcols - 1;
	s32 rowindex;

	for (i = 0; i < dialog->numcols; i++) {
		struct menuitem *item = dialogFindItemAtColY(0, colindex, dialog->definition, &rowindex, dialog);

		if (item != NULL) {
			return item;
		}

		colindex--;
	}

	menuResolveDialogTitle(dialog->definition);

	return dialog->definition->items;
}

void dialogChangeItemFocusVertically(struct menudialog *dialog, s32 updown)
{
	s32 rowindex;
	s32 colindex;
	bool done = false;
	s32 startrowindex;
	struct menuitem *item;
	s32 start;
	s32 end;

	dialogFindItem(dialog, dialog->focuseditem, &rowindex, &colindex);

	startrowindex = rowindex;

	while (!done) {
		rowindex += updown;
		start = g_Menus[g_MpPlayerNum].cols[colindex].rowstart;
		end = g_Menus[g_MpPlayerNum].cols[colindex].numrows + start;

		if (rowindex >= end) {
			rowindex = start;
		}

		if (rowindex < start) {
			rowindex = end - 1;
		}

		item = &dialog->definition->items[g_Menus[g_MpPlayerNum].rows[rowindex].itemindex];

		if (menuIsItemFocusable(item, dialog, updown)) {
			done = true;
		}

		if (rowindex == startrowindex) {
			done = true;
		}
	}

	dialog->focuseditem = item;
}

s32 dialogChangeItemFocusHorizontally(struct menudialog *dialog, s32 leftright)
{
	s32 rowindex;
	s32 colindex;
	bool done = false;
	s32 swipedir = 0;
	s32 y = dialogFindItem(dialog, dialog->focuseditem, &rowindex, &colindex);
	s32 startcolindex = colindex;
	struct menuitem *item;

	while (!done) {
		colindex += leftright;

		if (colindex >= dialog->colstart + dialog->numcols) {
			swipedir = 1;
			colindex = dialog->colstart;
		}

		if (colindex < dialog->colstart) {
			swipedir = -1;
			colindex = dialog->colstart + dialog->numcols - 1;
		}

		item = dialogFindItemAtColY(y, colindex, dialog->definition, &rowindex, dialog);

		if (item) {
			done = true;
		}

		if (colindex == startcolindex) {
			done = true;
		}
	}

	if (item) {
		dialog->focuseditem = item;
	}

	return swipedir;
}

s32 dialogChangeItemFocus(struct menudialog *dialog, s32 leftright, s32 updown)
{
	s32 swipedir = 0;

	if (leftright == 0 && updown == 0) {
		return 0;
	}

	if (updown != 0) {
		dialogChangeItemFocusVertically(dialog, updown);
	}

	if (leftright != 0) {
		swipedir = dialogChangeItemFocusHorizontally(dialog, leftright);
	}

	if (dialog->focuseditem != 0) {
		if (dialog->focuseditem->handler != NULL) {
			if ((dialog->focuseditem->flags & MENUITEMFLAG_SELECTABLE_OPENSDIALOG) == 0) {
				union handlerdata data;
				dialog->focuseditem->handler(MENUOP_FOCUS, dialog->focuseditem, &data);
			}
		}
	}

	return swipedir;
}

void menuOpenDialog(struct menudialogdef *dialogdef, struct menudialog *dialog, struct menu *menu)
{
	union handlerdata data3;
	struct menuitem *item;
	union handlerdata data1;
	union handlerdata data2;

	dialog->definition = dialogdef;

	switch (g_MenuData.root) {
	case MENUROOT_MPSETUP:
	case MENUROOT_4MBMAINMENU:
		dialog->unk6e = 1;
		break;
	case MENUROOT_MAINMENU:
	case MENUROOT_TRAINING:
	default:
		dialog->unk6e = 0;
		break;
	}

	func0f0f1d6c(dialogdef, dialog, menu);
	dialogInitItems(dialog);

	dialog->type = dialogdef->type;
	dialog->transitionfrac = -1;
	dialog->redrawtimer = 0;
	dialog->unk4c = RANDOMFRAC() * M_TAU;

	g_Menus[g_MpPlayerNum].curdialog->state = MENUDIALOGSTATE_PREOPEN;
	g_Menus[g_MpPlayerNum].curdialog->statefrac = 0;

	dialog->unk54 = 0;
	dialog->unk58 = 0;
	dialog->unk5c = 0;

	dialog->focuseditem = dialogFindFirstItem(dialog);

	// Check if any items should be focused automatically
	item = dialog->definition->items;

	while (item->type != MENUITEMTYPE_END) {
		if (item->handler
				&& (item->flags & MENUITEMFLAG_SELECTABLE_OPENSDIALOG) == 0
				&& item->handler(MENUOP_CHECKPREFOCUSED, item, &data1)) {
			dialog->focuseditem = item;
		}

		item++;
	}

	// Run focus handler
	if (dialog->focuseditem
			&& dialog->focuseditem->handler
			&& (dialog->focuseditem->flags & MENUITEMFLAG_SELECTABLE_OPENSDIALOG) == 0) {
		dialog->focuseditem->handler(MENUOP_FOCUS, dialog->focuseditem, &data2);
	}

	dialog->dimmed = false;
	dialog->scroll = 0;
	dialog->dstscroll = 0;

	if (dialogdef->handler) {
		dialogdef->handler(MENUOP_OPEN, dialogdef, &data3);
	}

	dialogCalculateContentSize(dialogdef, dialog, menu);
	dialogCalculatePosition(dialog);

	dialog->x = dialog->dstx;
	dialog->y = dialog->dsty;
	dialog->width = dialog->dstwidth;
	dialog->height = dialog->dstheight;
}

void menuPushDialog(struct menudialogdef *dialogdef)
{
	if (dialogdef) {
		func0f0f37a4(&g_Menus[g_MpPlayerNum].unk840);

		if (g_Menus[g_MpPlayerNum].depth < 6 && g_Menus[g_MpPlayerNum].numdialogs < ARRAYCOUNT(g_Menus[0].dialogs)) {
			struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth];
			struct menudialogdef *sibling;
			struct menudialog *dialog;

			g_Menus[g_MpPlayerNum].depth++;

			layer->numsiblings = 1;
			layer->cursibling = 0;

			dialog = &g_Menus[g_MpPlayerNum].dialogs[g_Menus[g_MpPlayerNum].numdialogs];
			g_Menus[g_MpPlayerNum].numdialogs++;
			layer->siblings[0] = dialog;
			g_Menus[g_MpPlayerNum].curdialog = dialog;
			dialog->swipedir = 0;

			menuOpenDialog(dialogdef, dialog, &g_Menus[g_MpPlayerNum]);

			dialog->dstx = (viGetWidth() - dialog->width) / 2;
			dialog->dsty = (viGetHeight() - dialog->height) / 2;

			g_Menus[g_MpPlayerNum].fm.unke40_00 = true;
			sibling = dialogdef->nextsibling;

			while (sibling && layer->numsiblings < 5) {
				// If this limit were to be reached, the game would soft lock
				// because sibling is incremented inside the if-statement block.
				if (g_Menus[g_MpPlayerNum].numdialogs < ARRAYCOUNT(g_Menus[0].dialogs)) {
					dialog = &g_Menus[g_MpPlayerNum].dialogs[g_Menus[g_MpPlayerNum].numdialogs];
					g_Menus[g_MpPlayerNum].numdialogs++;

					layer->siblings[layer->numsiblings] = dialog;
					layer->numsiblings++;

					dialog->swipedir = -1;

					menuOpenDialog(sibling, dialog, &g_Menus[g_MpPlayerNum]);

					dialog->dstx = dialog->x = -320;
					dialog->dsty = dialog->y = (viGetHeight() - dialog->height) / 2;
					dialog->type = 0;

					sibling = sibling->nextsibling;
				}
			}

			if (sibling);

			menuPlaySound(MENUSOUND_OPENDIALOG);

			if (dialogdef->type == MENUDIALOGTYPE_DANGER) {
				menuPlaySound(MENUSOUND_ERROR);
			}

			if (dialogdef->type == MENUDIALOGTYPE_SUCCESS) {
				menuPlaySound(MENUSOUND_SUCCESS);
			}
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
bool func0f0f3220(s32 arg0)
{
	bool save = true;
	s32 i;

	if (g_MenuData.unk669[arg0] == 4) {
		s32 prevplayernum = g_MpPlayerNum;

		for (i = 3; i >= 0; i--) {
			if (g_Menus[i].curdialog) {
				g_MpPlayerNum = i;
			}
		}

		if (g_Menus[g_MpPlayerNum].depth >= 2) {
			save = false;
		}

		if (g_Menus[g_MpPlayerNum].curdialog
				&& g_Menus[g_MpPlayerNum].curdialog->definition->type == MENUDIALOGTYPE_DANGER) {
			save = false;

			if (g_Menus[g_MpPlayerNum].curdialog->definition == &g_MpEndscreenChallengeCheatedMenuDialog
					|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_MpEndscreenChallengeFailedMenuDialog) {
				save = true;
			}
		}

		if (save) {
			filemgrSaveOrLoad(&g_GameFileGuid, FILEOP_SAVE_GAME_000, 0);
		}

		g_MpPlayerNum = prevplayernum;
	} else if (g_MenuData.unk669[arg0] < 4) {
		s32 prevplayernum = g_MpPlayerNum;
		g_MpPlayerNum = g_MenuData.unk669[arg0];
		filemgrSaveOrLoad(&g_PlayerConfigsArray[g_MpPlayerNum].fileguid, FILEOP_SAVE_MPPLAYER, g_MpPlayerNum);
		save = true;
		g_MpPlayerNum = prevplayernum;
	}

	if (save) {
		g_MenuData.unk66e--;
	}

	return save;
}
#else
void func0f0f3220(s32 arg0)
{
	s32 i;

	if (g_MenuData.unk669[arg0] == 4) {
		s32 prevplayernum = g_MpPlayerNum;

		for (i = 3; i >= 0; i--) {
			if (g_Menus[i].curdialog) {
				g_MpPlayerNum = i;
			}
		}

		filemgrSaveOrLoad(&g_GameFileGuid, FILEOP_SAVE_GAME_000, 0);

		g_MpPlayerNum = prevplayernum;
	} else if (g_MenuData.unk669[arg0] < 4) {
		s32 prevplayernum = g_MpPlayerNum;
		g_MpPlayerNum = g_MenuData.unk669[arg0];
		filemgrSaveOrLoad(&g_PlayerConfigsArray[g_MpPlayerNum].fileguid, FILEOP_SAVE_MPPLAYER, g_MpPlayerNum);
		g_MpPlayerNum = prevplayernum;
	}

	g_MenuData.unk66e--;
}
#endif

void menuCloseDialog(void)
{
	if (g_Menus[g_MpPlayerNum].depth > 0) {
		union handlerdata data;
		struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth - 1];
		u32 value_prevent = 1; // constant value, but required for match
		s32 i;

		for (i = 0; i < layer->numsiblings; i++) {
			data.dialog1.preventclose = false;

			if (layer->siblings[i]->definition->handler) {
				layer->siblings[i]->definition->handler(MENUOP_CLOSE, layer->siblings[i]->definition, &data);
			}

			if (value_prevent == data.dialog1.preventclose) {
				return;
			}
		}

		for (i = 0; i < layer->numsiblings; i++) {
			g_Menus[g_MpPlayerNum].numdialogs--;
		}

		g_Menus[g_MpPlayerNum].rowend = g_Menus[g_MpPlayerNum].cols[layer->siblings[0]->colstart].rowstart;
		g_Menus[g_MpPlayerNum].colend = layer->siblings[0]->colstart;
		g_Menus[g_MpPlayerNum].blockend = layer->siblings[0]->blockstart;
		g_Menus[g_MpPlayerNum].depth--;

		menuPlaySound(MENUSOUND_0B);
	}

#if VERSION >= VERSION_NTSC_1_0
	if (g_MenuData.unk66e > 0 && g_Menus[g_MpPlayerNum].depth == 0)
#else
	if (g_MenuData.unk66e > 0)
#endif
	{
		s32 value = g_MenuData.unk66e;

		while (value >= 0) {
			func0f0f3220(value);
			value--;
		}
	}

	if (g_Menus[g_MpPlayerNum].depth == 0) {
		g_Menus[g_MpPlayerNum].curdialog = NULL;
	} else {
		struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth - 1];
		g_Menus[g_MpPlayerNum].curdialog = layer->siblings[layer->cursibling];
	}
}

void menuUpdateCurFrame(void)
{
	s32 depth = g_Menus[g_MpPlayerNum].depth;

	if (depth == 0) {
		// No more parent menus - return control to the player
		g_Vars.currentplayer->joybutinhibit = 0xffffffff;
		menuClose();
		g_Menus[g_MpPlayerNum].curdialog = NULL;
	} else {
		// Set up parent menu
		struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[depth - 1];
		g_Menus[g_MpPlayerNum].curdialog = layer->siblings[layer->cursibling];
	}
}

void menuPopDialog(void)
{
	menuCloseDialog();
	menuUpdateCurFrame();
}

void func0f0f3704(struct menudialogdef *dialogdef)
{
	menuCloseDialog();
	menuPushDialog(dialogdef);
}

void func0f0f372c(struct menu840 *arg0, f32 x, f32 y, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, u8 flags)
{
	arg0->unk5b1_05 = true;

	if (flags & 2) {
		arg0->unk538 = x;
		arg0->unk53c = y;
		arg0->unk540 = arg3;
	}

	if (flags & 4) {
		arg0->unk548 = arg4;
		arg0->unk54c = arg5;
		arg0->unk550 = arg6;
	}

	if (flags & 1) {
		arg0->unk544 = arg7;
	}

	arg0->unk568 = flags;
	arg0->unk564 = 0.0f;
}

void func0f0f37a4(struct menu840 *arg0)
{
	if (arg0->unk010 == 0x4fac5ace) {
		challengeUnsetCurrent();
	}

	arg0->unk000 = 0;
	arg0->unk00c = 0;
	arg0->unk010 = 0;
	arg0->bodymodeldef = 0;
	arg0->headmodeldef = 0;
	arg0->unk05c = 0;
	arg0->unk05e = 0;
	arg0->unk5b0 = 0;
	arg0->unk5b1_01 = false;
	arg0->unk5b1_02 = false;
	arg0->unk5b1_03 = false;
	arg0->unk5b1_04 = false;
	arg0->unk5b1_05 = false;
	arg0->unk5b1_06 = false;
	arg0->unk5b1_07 = false;
	arg0->partvisibility = NULL;
	arg0->unk560 = -1;
	arg0->headnum = -1;
	arg0->bodynum = -1;
	arg0->unk550 = 0.0f;
	arg0->unk54c = 0.0f;
	arg0->unk548 = 0.0f;
	arg0->unk540 = 0.0f;
	arg0->unk53c = 0.0f;
	arg0->unk538 = 0.0f;
	arg0->unk534 = 0.0f;
	arg0->unk530 = 0.0f;
	arg0->unk52c = 0.0f;
	arg0->unk528 = 0.0f;
	arg0->unk524 = 0.0f;
	arg0->unk520 = 0.0f;
	arg0->unk518 = 0.0f;
	arg0->unk514 = 0.0f;
	arg0->unk510 = 0.0f;
	arg0->unk558 = 0.0f;
	arg0->unk55c = 1.0f;
	arg0->unk51c = 1.0f;
	arg0->unk544 = 1.0f;
	arg0->unk554 = -1.0f;
}

Lights1 var80071468 = gdSPDefLights1(0x96, 0x96, 0x96, 0xff, 0xff, 0xff, 0xb2, 0x4d, 0x2e);

/**
 * Render the hudpiece as well as any models within dialogs.
 */
Gfx *menuRenderModels(Gfx *gdl, struct menu840 *thing, s32 arg2)
{
	f32 a;
	f32 b;
	f32 c;
	f32 sp430;
	f32 sp42c;
	f32 sp428;
	f32 sp424;
	s32 totalfilelen;
	struct texpool texpool;
	s32 bodyfilelen2;
	u16 bodyfilenum;
	u16 headfilenum;
	s32 bodynum;
	s32 headnum;

	if (g_Vars.stagenum != STAGE_CITRAINING && g_Vars.stagenum != STAGE_CREDITS) {
		if (g_MenuData.unk5d5_01 && arg2 != 1 && arg2 < 3) {
			return gdl;
		}

		if (thing->unk004 == NULL) {
			if (bgun0f09e004(1)) {
				thing->unk004 = bgunGetGunMem();
				thing->unk008 = bgunCalculateGunMemCapacity();
			} else {
				return gdl;
			}
		}
	}

	if (thing->unk004 == NULL) {
		return gdl;
	}

	if (thing->unk00c != 0) {
		if (thing->unk00c == thing->unk010) {
			thing->unk00c = 0;
			thing->unk000 = 0;
		} else {
			if (thing->unk010 == 0x4fac5ace) {
				challengeUnsetCurrent();
			}

			if (thing->unk000 == 0) {
				thing->unk000 = 1;
				return gdl;
			}

			thing->unk000--;

			if (thing->unk000 == 0) {
				if ((thing->unk00c & 0xffff) == 0xffff || (thing->unk00c & 0x80000000)) {
					if (thing->unk00c & 0x80000000) {
						headnum = thing->unk00c & 0x3ff;
						bodynum = (thing->unk00c & 0xffc00) >> 10;
					} else {
						s32 mpheadnum = (thing->unk00c >> 16) & 0xff;
						s32 mpbodynum = (thing->unk00c >> 24) & 0xff;
						bodynum = mpGetBodyId(mpbodynum);

						if (mpheadnum < mpGetNumHeads2()) {
							headnum = mpGetHeadId(mpheadnum);
						} else {
							headnum = func0f14a9f8(mpheadnum - mpGetNumHeads2());
							headnum = mpGetBeauHeadId(headnum);
							thing->unk5b0 = (mpheadnum - mpGetNumHeads2()) & 0xff;
						}
					}

					bodyfilenum = g_HeadsAndBodies[bodynum].filenum;

					totalfilelen = fileGetInflatedSize(bodyfilenum);
					totalfilelen = ALIGN64(totalfilelen);

					if (g_HeadsAndBodies[bodynum].unk00_01) {
						headnum = -1;
						headfilenum = 0xffff;
					} else {
						headfilenum = g_HeadsAndBodies[headnum].filenum;
						totalfilelen += ALIGN64(fileGetInflatedSize(headfilenum));
					}

					totalfilelen += 0x4000;

					texInitPool(&texpool, thing->unk004 + totalfilelen, thing->unk008 - totalfilelen);

					thing->headnum = headnum;
					thing->bodynum = bodynum;
					thing->bodymodeldef = modeldefLoad(bodyfilenum, thing->unk004, totalfilelen, &texpool);
					bodyfilelen2 = ALIGN64(fileGetLoadedSize(bodyfilenum));
					modelCalculateRwDataLen(thing->bodymodeldef);

					if (headnum < 0) {
						thing->headmodeldef = NULL;
					} else {
						thing->headmodeldef = modeldefLoad(headfilenum, thing->unk004 + bodyfilelen2, totalfilelen - bodyfilelen2, &texpool);
						fileGetLoadedSize(headfilenum);
						bodyCalculateHeadOffset(thing->headmodeldef, headnum, bodynum);
						modelCalculateRwDataLen(thing->headmodeldef);
					}

					modelInit(&thing->bodymodel, thing->bodymodeldef, &thing->unk110, true);
					animInit(&thing->bodyanim);

					thing->bodymodel.rwdatalen = 256;
					thing->bodymodel.anim = &thing->bodyanim;

					body0f02ce8c(bodynum, headnum, thing->bodymodeldef, thing->headmodeldef, totalfilelen * 0, &thing->bodymodel, false, 1);
				} else {
					totalfilelen = ALIGN64(fileGetInflatedSize(thing->unk00c)) + 0x4000;
					if (1);

					texInitPool(&texpool, &thing->unk004[(u32)totalfilelen], thing->unk008 - totalfilelen);

					thing->headnum = -1;
					thing->bodynum = -1;
					thing->bodymodeldef = modeldefLoad(thing->unk00c, thing->unk004, totalfilelen, &texpool);

					fileGetLoadedSize(thing->unk00c);
					modelCalculateRwDataLen(thing->bodymodeldef);
					modelInit(&thing->bodymodel, thing->bodymodeldef, &thing->unk110, true);
					animInit(&thing->bodyanim);

					thing->bodymodel.rwdatalen = 256;
					thing->bodymodel.anim = &thing->bodyanim;
				}

				thing->unk010 = thing->unk00c;
				thing->unk05e = 0;
				thing->unk00c = 0;
			} else {
				return gdl;
			}
		}
	}

	if (thing->bodymodeldef != NULL) {
		struct modelrenderdata renderdata = {NULL, true, 3};
		Mtxf *sp3b4;
		s32 i;
		u32 stack[3];
		struct coord sp398;
		f32 sp390[2];
		Mtxf sp350;
		Mtxf sp310;
		f32 sp30c[1];
		bool sp308;
		struct coord sp2fc;
		f32 sp2f8;
		bool sp2f4;

		if (arg2 < 3 && g_MenuData.unk5d5_03) {
			gdl = vi0000b280(gdl);
			gdl = vi0000b1d0(gdl);

			g_MenuData.unk5d5_03 = false;

			if (arg2 != 2) {
				gdl = menuApplyScissor(gdl);
			}

			gSPSetGeometryMode(gdl++, G_ZBUFFER);
		}

		gSPDisplayList(gdl++, var80061380);
		gSPDisplayList(gdl++, var800613a0);

		sp308 = false;

		if (thing->unk554 > 0.0f) {
			sp2f4 = true;

			if (thing->bodymodeldef->skel == &g_SkelChr) {
				struct modelnode *node = modelGetPart(thing->bodymodeldef, MODELPART_CHR_0006);

				if (node) {
					struct modelrodata_position *rodata = &node->rodata->position;
					f32 f0 = menuGetLinearOscPauseFrac(thing->unk574 / TICKS(480.0f));

					sp2fc.f[0] = 0.0f;
					sp2fc.f[1] = 0.0f - (rodata->pos.f[1] / 7.6f * (1.0f - f0 * f0));
					sp2fc.f[2] = 0.0f;

					sp308 = true;

					thing->unk554 = 100.0f + (1.0f - f0) * 270.0f;
					sp2f8 = thing->unk554 / (rodata->pos.f[1] / 2.0f);

					sp2f4 = false;

					modelFindBboxRodata(&thing->bodymodel);
				}

				if (1);
			}

			if (sp2f4) {
				struct modelrodata_bbox *bbox = modelFindBboxRodata(&thing->bodymodel);

				if (bbox) {
					sp2fc.x = -(bbox->xmax - ((bbox->xmax - bbox->xmin) * 0.5f));
					sp2fc.y = -(bbox->ymax - ((bbox->ymax - bbox->ymin) * 0.5f));
					sp2fc.z = -(bbox->zmax - ((bbox->zmax - bbox->zmin) * 0.5f));
					sp308 = true;
					sp2f8 = thing->unk554 / ((bbox->ymax - bbox->ymin) * 0.5f);
				}
			}
		}

		mtx4LoadIdentity(&sp350);

		if (arg2 == 1) {
			if (IS8MB()) {
				s32 i;

				if (thing->unk510 != thing->unk538) {
					for (i = 0; i < g_Vars.diffframe60; i++) {
						thing->unk510 = (thing->unk538 * PALUPF(0.002f)) + ((1.0f - PALUPF(0.002f)) * thing->unk510);
					}
				}

				if (thing->unk514 != thing->unk53c) {
					for (i = 0; i < g_Vars.diffframe60; i++) {
						thing->unk514 = (thing->unk53c * PALUPF(0.002f)) + ((1.0f - PALUPF(0.002f)) * thing->unk514);
					}
				}

				if (thing->unk518 != thing->unk540) {
					for (i = 0; i < g_Vars.diffframe60; i++) {
						thing->unk518 = (thing->unk540 * PALUPF(0.002f)) + ((1.0f - PALUPF(0.002f)) * thing->unk518);
					}
				}

				if (thing->unk51c != thing->unk544) {
					for (i = 0; i < g_Vars.diffframe60; i++) {
						thing->unk51c = (thing->unk544 * PALUPF(0.002f)) + ((1.0f - PALUPF(0.002f)) * thing->unk51c);
					}
				}

				sp430 = thing->unk510;

#if !PAL
				if (g_ViRes == VIRES_HI) {
					sp430 *= 2.0f;
				}
#endif

				sp42c = thing->unk514;
				sp428 = thing->unk518;
				sp424 = thing->unk51c;

				a = thing->unk548;
				b = thing->unk54c;
				c = thing->unk550;

				thing->unk520 = a;
				thing->unk524 = b;
				thing->unk528 = c;

				sp398.x = a;
				sp398.y = b;
				sp398.z = c;

				mtx4LoadRotation(&sp398, &sp350);
			}
		} else {
			if (thing->unk5b1_05) {
#if VERSION >= VERSION_PAL_BETA
				thing->unk564 += g_Vars.diffframe60freal / 40.0f;
#else
				thing->unk564 += g_Vars.diffframe60f / 40.0f;
#endif

				if (thing->unk564 > 1.0f) {
					thing->unk5b1_05 = false;
					thing->unk510 = thing->unk538;
					thing->unk514 = thing->unk53c;
					thing->unk518 = thing->unk540;
					thing->unk51c = thing->unk544;
				} else {
					f32 sp2d0 = (-cosf(thing->unk564 * M_PI) * 0.5f) + 0.5f;
					f32 sp2cc = 1.0f - sp2d0;

					if (thing->unk568 & 2) {
						sp430 = (thing->unk510 * sp2cc) + (sp2d0 * thing->unk538);
						sp42c = (thing->unk514 * sp2cc) + (sp2d0 * thing->unk53c);
						sp428 = (thing->unk518 * sp2cc) + (sp2d0 * thing->unk540);
					} else {
						sp430 = thing->unk510 = thing->unk538;
						sp42c = thing->unk514 = thing->unk53c;
						sp428 = thing->unk518 = thing->unk540;
					}

					if (thing->unk568 & 1) {
						sp424 = (thing->unk51c * sp2cc) + (sp2d0 * thing->unk544);
					} else {
						sp424 = thing->unk51c = thing->unk544;
					}

					if (thing->unk568 & 4) {
						f32 sp2bc[4];
						f32 sp2ac[4];
						f32 sp29c[4];
						struct coord sp290;

						sp290.x = thing->unk520;
						sp290.y = thing->unk524;
						sp290.z = thing->unk528;

						quaternion0f096ca0(&sp290, sp2bc);

						sp290.x = thing->unk548;
						sp290.y = thing->unk54c;
						sp290.z = thing->unk550;

						quaternion0f096ca0(&sp290, sp2ac);
						quaternionSlerp(sp2bc, sp2ac, sp2d0, sp29c);
						quaternionToMtx(sp29c, &sp350);
					} else {
						a = thing->unk548;
						b = thing->unk54c;
						c = thing->unk550;

						thing->unk520 = a;
						thing->unk524 = b;
						thing->unk528 = c;

						sp398.x = a;
						sp398.y = b;
						sp398.z = c;

						mtx4LoadRotation(&sp398, &sp350);
					}
				}
			}

			if (!thing->unk5b1_05) {
				sp430 = thing->unk510 = thing->unk538;
				sp42c = thing->unk514 = thing->unk53c;
				sp428 = thing->unk518 = thing->unk540;
				sp424 = thing->unk51c = thing->unk544;

				if (1);
				a = thing->unk548;
				b = thing->unk54c;
				c = thing->unk550;

				thing->unk520 = a;
				thing->unk524 = b;
				thing->unk528 = c;

				sp398.x = a;
				sp398.y = b;
				sp398.z = c;

				mtx4LoadRotation(&sp398, &sp350);
			}
		}

		sp30c[0] = -100.0f + sp428;

		if (arg2 == 1) {
			if (IS8MB()) {
				sp390[0] = thing->unk510 * g_ScaleX;
				sp390[1] = thing->unk514;
			}
		} else {
			sp390[0] = sp430 * g_ScaleX + viGetViewLeft() + viGetViewWidth() * 0.5f;
			sp390[1] = sp42c + viGetViewTop() + viGetViewHeight() * 0.5f;
		}

		cam0f0b4c3c(sp390, &sp398, 1.0f);
		mtx4LoadIdentity(&sp310);

		if (thing->partvisibility != NULL) {
			struct modelpartvisibility *ptr = thing->partvisibility;

			while (ptr->part != 255) {
				struct modelnode *node = modelGetPart(thing->bodymodeldef, ptr->part);

				if (node) {
					union modelrwdata *rwdata = modelGetNodeRwData(&thing->bodymodel, node);

					if (rwdata) {
						if (ptr->visible) {
							rwdata->toggle.visible = true;
						} else {
							rwdata->toggle.visible = false;
						}
					}
				}

				ptr++;
			}
		}

		if (arg2 == 3) {
			sp398.x = thing->unk510;
			sp398.y = thing->unk514;
			sp398.z = thing->unk518;
		} else {
			c = sp30c[0] / sp398.z;
			sp398.x = c * sp398.x;
			sp398.y = c * sp398.y;
			sp398.z = c * sp398.z;
		}

#if VERSION < VERSION_NTSC_1_0
		if ((thing->unk010 & 0x80000000) != 0) {
			struct coord oldpos;
			struct coord newpos = {0, 0, 0};
			u32 stack[3];

			model0001b3bc(&thing->bodymodel);

			modelGetRootPosition(&thing->bodymodel, &oldpos);

			if (joyGetButtons(0, L_TRIG)) {
				modelSetRootPosition(&thing->bodymodel, &newpos);
			}
		}
#endif

		mtx4LoadTranslation(&sp398, &sp310);

		if (sp308) {
			mtx00015f04(sp424 * sp2f8, &sp310);
		} else {
			mtx00015f04(sp424, &sp310);
		}

		{
			Mtxf sp244;
			Mtxf sp204;
			Mtxf sp1c4;
			Mtxf sp184;

			if (sp308) {
				mtx4LoadTranslation(&sp2fc, &sp204);
			} else {
				sp398.x = thing->unk52c;
				sp398.y = thing->unk530;
				sp398.z = thing->unk534;
				mtx4LoadTranslation(&sp398, &sp204);
			}

			mtx4MultMtx4(&sp310, &sp350, &sp244);

			if (arg2 == 3) {
				credits0f13ae04(&sp1c4);
				mtx4MultMtx4(&sp1c4, &sp244, &sp184);
				mtx4MultMtx4(&sp184, &sp204, &thing->unk014);
			} else {
				mtx4MultMtx4(&sp244, &sp204, &thing->unk014);
			}
		}

		gdl = menugfx0f0e2348(gdl);

		if (arg2 < 3) {
			if (arg2 != 0) {
				gdl = func0f0d49c8(gdl);
				gSPMatrix(gdl++, osVirtualToPhysical(camGetPerspectiveMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
			} else {
				f32 aspect = (f32) (g_MenuScissorX2 - g_MenuScissorX1) / (f32) (g_MenuScissorY2 - g_MenuScissorY1);
				static u32 znear = 10;
				static u32 zfar = 300;

				mainOverrideVariable("mzn", &znear);
				mainOverrideVariable("mzf", &zfar);

				gdl = func0f0d49c8(gdl);

				viSetViewPosition(g_MenuScissorX1 * g_ScaleX, g_MenuScissorY1);
				viSetFovAspectAndSize(g_Vars.currentplayer->fovy, aspect, (g_MenuScissorX2 - g_MenuScissorX1) * g_ScaleX, g_MenuScissorY2 - g_MenuScissorY1);

				gdl = vi0000af00(gdl, var800a2048[g_MpPlayerNum]);
				gdl = vi0000aca4(gdl, znear, zfar);
			}
		}

		sp3b4 = gfxAllocate(thing->bodymodeldef->nummatrices * sizeof(Mtxf));

		for (i = 0; i < thing->bodymodeldef->nummatrices; i++) {
			mtx4LoadIdentity(&sp3b4[i]);
		}

		thing->bodymodel.matrices = sp3b4;

		if (thing->unk05c && thing->unk05e != thing->unk05c) {
			if (thing->unk5b1_04) {
				modelSetAnimation(&thing->bodymodel, thing->unk05c, false, 0, PALUPF(-0.5f), 0.0f);
				model0001e018(&thing->bodymodel, modelGetNumAnimFrames(&thing->bodymodel));
			} else {
				modelSetAnimation(&thing->bodymodel, thing->unk05c, false, 0, PALUPF(0.5f), 0.0f);
			}

			thing->unk05e = thing->unk05c;
		}

		thing->unk05c = 0;

		if (thing->unk05e != 0) {
			f32 sp178;
			u32 stack;

			model0001ee18(&thing->bodymodel, g_Vars.diffframe240, true);

			if (thing->unk5b1_04) {
				sp178 = modelGetNumAnimFrames(&thing->bodymodel) - modelGetCurAnimFrame(&thing->bodymodel);
			} else {
				sp178 = modelGetCurAnimFrame(&thing->bodymodel);
			}

			if (sp178 >= modelGetNumAnimFrames(&thing->bodymodel) - 1) {
				thing->unk05e = 0;
			}
		}

		mtx4Copy(&thing->unk014, sp3b4);

		renderdata.unk00 = &thing->unk014;
		renderdata.unk10 = thing->bodymodel.matrices;

		model0001cebc(&renderdata, &thing->bodymodel);

		if (thing->bodymodeldef->skel == &g_SkelHudPiece) {
			struct modelnode *node = modelGetPart(thing->bodymodeldef, MODELPART_HUDPIECE_0000);

			if (node) {
				struct modelrodata_gundl *rodata = &node->rodata->gundl;
				s32 i;
				s32 j;

				for (i = 0; i < rodata->numvertices; i++) {
#if VERSION >= VERSION_PAL_BETA
					rodata->vertices[i].s -= (s32) (100.0f * g_Vars.diffframe60freal);
#else
					rodata->vertices[i].s -= 100 * g_Vars.diffframe60;
#endif

					if (rodata->vertices[i].s < -0x6000) {
						for (j = 0; j < rodata->numvertices; j++) {
							rodata->vertices[j].s += 0x2000;
						}
					}
				}
			}

			node = modelGetPart(thing->bodymodeldef, MODELPART_HUDPIECE_0002);

			if (node) {
				s32 sp160;
				Mtxf sp120;
				Mtxf spe0;
				sp160 = model0001a524(node, 0);
				mtx4LoadIdentity(&sp120);
				mtx4LoadXRotation(menuGetCosOscFrac(4), &sp120);
				mtx4MultMtx4((Mtxf *)((u32)sp3b4 + sp160 * sizeof(Mtxf)), &sp120, &spe0);
				mtx4Copy(&spe0, (Mtxf *)((u32)sp3b4 + sp160 * sizeof(Mtxf)));
			}

			node = modelGetPart(thing->bodymodeldef, MODELPART_HUDPIECE_0001);

			if (node) {
				if (g_MenuData.root == MENUROOT_MAINMENU
						|| g_MenuData.root == MENUROOT_FILEMGR
						|| g_MenuData.root == MENUROOT_MPSETUP
						|| g_MenuData.root == MENUROOT_TRAINING) {
					s32 index = model0001a524(node, 0);
					struct coord spd0;
					f32 spc8[2];

					spd0.x = sp3b4[index].m[3][0];
					spd0.y = sp3b4[index].m[3][1];
					spd0.z = sp3b4[index].m[3][2];

					cam0f0b4d04(&spd0, spc8);
					var8009de98 = ((s32)spc8[0] - viGetWidth() / 2) / g_ScaleX;
					var8009de9c = (s32)spc8[1] - viGetHeight() / 2;
				}
			}
		}

		gSPSetLights1(gdl++, var80071468);
		gSPLookAtX(gdl++, &camGetLookAt()->l[0]);
		gSPLookAtY(gdl++, &camGetLookAt()->l[1]);

		renderdata.unk30 = 1;
		renderdata.envcolour = 0xffffffff;
		renderdata.fogcolour = 0xffffffff;

		gSPSetGeometryMode(gdl++, G_ZBUFFER);

		renderdata.gdl = gdl;
		renderdata.zbufferenabled = true;
		modelRender(&renderdata, &thing->bodymodel);
		gdl = renderdata.gdl;

		mtx00016760();

		for (i = 0; i < thing->bodymodeldef->nummatrices; i++) {
			Mtxf sp70;
			mtx4Copy((Mtxf *)((u32)thing->bodymodel.matrices + i * sizeof(Mtxf)), &sp70);
			mtx00016054(&sp70, &thing->bodymodel.matrices[i]);
		}

		mtx00016784();

		if (arg2 < 3) {
			gdl = func0f0d479c(gdl);
		}

		gDPPipeSync(gdl++);
		gDPSetCycleType(gdl++, G_CYC_1CYCLE);
		gDPSetAlphaCompare(gdl++, G_AC_NONE);
		gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);
		gSPClearGeometryMode(gdl++, G_CULL_BOTH);
		gDPSetTextureFilter(gdl++, G_TF_BILERP);

		texSelect(&gdl, NULL, 2, 0, 2, 1, NULL);

		gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

		texSelect(&gdl, NULL, 2, 0, 2, 1, NULL);

		gSPDisplayList(gdl++, var800613a0);
	}

	return gdl;
}

void menuGetTeamTitlebarColours(u32 *top, u32 *middle, u32 *bottom)
{
	const u32 colours[][3] = {
		// top, middle, bottom
		{ 0xbf000000, 0x50000000, 0xff000000 },
		{ 0xbfbf0000, 0x50500000, 0xffff0000 },
		{ 0x0000bf00, 0x00005000, 0x0000ff00 },
		{ 0xbf00bf00, 0x50005000, 0xff00ff00 },
		{ 0x00bfbf00, 0x00505000, 0x00ffff00 },
		{ 0xff885500, 0x7f482000, 0xff885500 },
		{ 0xff888800, 0x7f484800, 0xff888800 },
		{ 0x88445500, 0x48242000, 0x88445500 },
	};

	*top = colours[g_PlayerConfigsArray[g_MpPlayerNum].base.team][0] | (*top & 0xff);
	*middle = colours[g_PlayerConfigsArray[g_MpPlayerNum].base.team][1] | (*middle & 0xff);
	*bottom = colours[g_PlayerConfigsArray[g_MpPlayerNum].base.team][2] | (*bottom & 0xff);
}

Gfx *menuApplyScissor(Gfx *gdl)
{
	gDPPipeSync(gdl++);

#if VERSION >= VERSION_NTSC_1_0
	g_ScissorX1 = g_MenuScissorX1 * g_ScaleX;
	g_ScissorX2 = g_MenuScissorX2 * g_ScaleX;
	g_ScissorY1 = g_MenuScissorY1;
	g_ScissorY2 = g_MenuScissorY2;

	if (g_ScissorX1 < 0) {
		g_ScissorX1 = 0;
	}

	if (g_ScissorX2 < 0) {
		g_ScissorX2 = 0;
	}

	if (g_ScissorY1 < 0) {
		g_ScissorY1 = 0;
	}

	if (g_ScissorY2 < 0) {
		g_ScissorY2 = 0;
	}

	if (g_ScissorX1 > viGetBufWidth()) {
		g_ScissorX1 = viGetBufWidth();
	}

	if (g_ScissorX2 > viGetBufWidth()) {
		g_ScissorX2 = viGetBufWidth();
	}

	if (g_ScissorY1 > viGetBufHeight()) {
		g_ScissorY1 = viGetBufHeight();
	}

	if (g_ScissorY2 > viGetBufHeight()) {
		g_ScissorY2 = viGetBufHeight();
	}

	if (g_ScissorX2 < g_ScissorX1) {
		g_ScissorX2 = g_ScissorX1;
	}

	if (g_ScissorY2 < g_ScissorY1) {
		g_ScissorY2 = g_ScissorY1;
	}

	gDPSetScissor(gdl++, G_SC_NON_INTERLACE, g_ScissorX1, g_ScissorY1, g_ScissorX2, g_ScissorY2);
#else
	gDPSetScissor(gdl++, G_SC_NON_INTERLACE,
			g_MenuScissorX1 * g_ScaleX, g_MenuScissorY1,
			g_MenuScissorX2 * g_ScaleX, g_MenuScissorY2);
#endif

	return gdl;
}

/**
 * Render a single menu dialog.
 *
 * The lightweight argument is always false. If set to true, a lighter-weight
 * variant of the dialog is rendered which has no borders, less background,
 * no overlays and no models such as inventory weapons.
 */
Gfx *dialogRender(Gfx *gdl, struct menudialog *dialog, struct menu *menu, bool lightweight)
{
	s32 i;
	s32 dialogleft;
	s32 dialogtop;
	s32 dialogright;
	s32 dialogbottom;
	s32 x;
	s32 y;
	s16 dialogwidth;
	union menuitemdata *itemdata;
	s32 j;
	u32 colour1;
	u32 colour2;
	u32 colour3;
	struct menurendercontext context;
	s32 curx;
	s32 bgx1;
	s32 bgy1;
	s32 bgx2;
	s32 bgy2;
	s16 dialogheight;
	char *title;
	u32 colour4;
	u32 colour5;
	f32 sp170;

	bgx1 = dialog->x;
	bgy1 = dialog->y;
	bgx2 = dialog->x + dialog->width;
	bgy2 = dialog->y + dialog->height;

#if VERSION >= VERSION_NTSC_1_0
	if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
			&& menuGetRoot() == MENUROOT_MPENDSCREEN
			&& !var8009dfc0) {
		return gdl;
	}
#endif

	colour1 = MIXCOLOUR(dialog, unk28);

	text0f156030(colour1);

	var8007fb9c = false;

	if (g_Menus[g_MpPlayerNum].curdialog == dialog
			&& (dialog->definition->flags & MENUDIALOGFLAG_0002)
			&& !lightweight
			&& g_Menus[g_MpPlayerNum].unk840.unk5b1_07 == 1) {
		gSPSetGeometryMode(gdl++, G_ZBUFFER);
		gdl = menuRenderModels(gdl, &g_Menus[g_MpPlayerNum].unk840, 2);
		gSPClearGeometryMode(gdl++, G_ZBUFFER);
	}

	dialogwidth = dialog->width;
	dialogheight = dialog->height;

	if (dialog->state == MENUDIALOGSTATE_PREOPEN) {
#if VERSION >= VERSION_NTSC_1_0
		if (dialog->definition == &g_MpReadyMenuDialog) {
			return gdl;
		}
#endif

		sp170 = 1.0f - g_MenuData.unk010;

#if VERSION >= VERSION_NTSC_1_0
		if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) && menuGetRoot() == MENUROOT_MPENDSCREEN) {
			sp170 = 1.0f - dialog->statefrac;
		}
#endif

		sp170 = 1.0f - sp170 * sp170;
		dialogheight *= sp170;
		bgy2 = dialog->y + dialogheight;
	}

	dialogleft = dialog->x;
	dialogtop = dialog->y;
	dialogright = dialogleft + dialogwidth;
	dialogbottom = dialogtop + dialogheight;

	title = menuResolveDialogTitle(dialog->definition);

	colour1 = MIXCOLOUR(dialog, unk00);
	colour2 = MIXCOLOUR(dialog, unk04);
	colour3 = MIXCOLOUR(dialog, unk08);

	gSPClearGeometryMode(gdl++, G_ZBUFFER);

	colour4 = colour1;
	colour5 = colour3;

	if ((colour4 & 0xff) > 0x3f) {
		colour4 = (colour4 & 0xffffff00) | 0x3f;
	}

	if ((colour5 & 0xff) > 0x3f) {
		colour5 = (colour5 & 0xffffff00) | 0x3f;
	}

	var8009de90 = -1000;
	var8009de94 = 1000;

	if (dialog->definition->flags & MENUDIALOGFLAG_DISABLETITLEBAR) {
		bgy1 += LINEHEIGHT;
	}

	// Render the walls/floor/ceiling coming from the projection source.
	// Each surface is rendered a second time with the colours swapped.
	// The order is top, right, bottom, left.
	if (g_MenuData.root != MENUROOT_MPSETUP && (g_MenuData.root != MENUROOT_MPPAUSE || g_Vars.normmplayerisrunning)) {
		var800a4634 = menugfxDrawPlane(var800a4634, bgx1, bgy1, bgx2, bgy1, colour4, colour5, MENUPLANE_00);
		var800a4634 = menugfxDrawPlane(var800a4634, bgx2, bgy1, bgx2, bgy2, colour5, colour4, MENUPLANE_00);
		var800a4634 = menugfxDrawPlane(var800a4634, bgx2, bgy2, bgx1, bgy2, colour4, colour5, MENUPLANE_00);
		var800a4634 = menugfxDrawPlane(var800a4634, bgx1, bgy2, bgx1, bgy1, colour5, colour4, MENUPLANE_00);
		var800a4634 = menugfxDrawPlane(var800a4634, bgx1, bgy1, bgx2, bgy1, colour5, colour4, MENUPLANE_01);
		var800a4634 = menugfxDrawPlane(var800a4634, bgx2, bgy1, bgx2, bgy2, colour4, colour5, MENUPLANE_01);
		var800a4634 = menugfxDrawPlane(var800a4634, bgx2, bgy2, bgx1, bgy2, colour5, colour4, MENUPLANE_01);
		var800a4634 = menugfxDrawPlane(var800a4634, bgx1, bgy2, bgx1, bgy1, colour4, colour5, MENUPLANE_01);
	}

	// Render the title bar
	if ((dialog->definition->flags & MENUDIALOGFLAG_DISABLETITLEBAR) == 0) {
		if (((g_MenuData.root == MENUROOT_MPSETUP) || (g_MenuData.root == MENUROOT_4MBMAINMENU))
				&& (g_MpSetup.options & MPOPTION_TEAMSENABLED)
				&& g_Vars.mpsetupmenu != MPSETUPMENU_GENERAL) {
			menuGetTeamTitlebarColours(&colour1, &colour2, &colour3);
		}

		gdl = menugfxRenderGradient(gdl, dialogleft - 2, dialogtop, dialogright + 2, dialogtop + LINEHEIGHT, colour1, colour2, colour3);
		gdl = menugfxDrawShimmer(gdl, dialogleft - 2, dialogtop, dialogright + 2, dialogtop + 1, (colour1 & 0xff) >> 1, 1, 40, 0);
		gdl = menugfxDrawShimmer(gdl, dialogleft - 2, dialogtop + 10, dialogright + 2, dialogtop + LINEHEIGHT, (colour1 & 0xff) >> 1, 0, 40, 1);

		x = dialogleft + 2;
		y = dialogtop + 2;

		gdl = text0f153628(gdl);

		context.unk18 = false;

		if (lightweight) {
			context.unk18 = true;
		}

		{
			char *sp154[] = {
				"1\n",
				"2\n",
				"3\n",
				"4\n",
			};

			colour1 = MIXCOLOUR(dialog, unk0c);

			textSetWaveColours(g_MenuColourPalettes3[dialog->type].unk0c, g_MenuColourPalettes2[dialog->type].unk0c);

			// Title shadow
			x = dialogleft + 3;
			y = dialogtop + 3;

			gdl = textRenderProjected(gdl, &x, &y, title, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour1 & 0xff, dialogwidth, viGetHeight(), 0, 0);

			// Title proper
			x = dialogleft + 2;
			y = dialogtop + 2;

			gdl = textRenderProjected(gdl, &x, &y, title, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour1, dialogwidth, viGetHeight(), 0, 0);

			// In MP dialogs, render the player number in the top right
			if (g_MenuData.root == MENUROOT_MPSETUP
					|| g_MenuData.root == MENUROOT_MPPAUSE
					|| g_MenuData.root == MENUROOT_MPENDSCREEN
					|| g_MenuData.root == MENUROOT_4MBMAINMENU) {
				x = dialogright - 9;
				y = dialogtop + 2;

				gdl = textRenderProjected(gdl, &x, &y, sp154[g_MpPlayerNum], g_CharsHandelGothicSm, g_FontHandelGothicSm, colour1, dialogwidth, viGetHeight(), 0, 0);
			}
		}

		gdl = text0f153780(gdl);
	}

	// Configure things for the redraw effect
	if (!(dialog->redrawtimer < 0.0f)) {
		if (g_MenuData.root != MENUROOT_MPPAUSE) {
			if (dialog->state >= MENUDIALOGSTATE_POPULATED) {
				textSetDiagonalBlend(dialog->x, dialog->y, dialog->redrawtimer, DIAGMODE_REDRAW);
			} else {
				textSetDiagonalBlend(dialog->x, dialog->y, dialog->redrawtimer, DIAGMODE_FADEIN);
			}

			var8007fb9c = true;
		}
	} else if (dialog->state == MENUDIALOGSTATE_POPULATED) {
		textSetMenuBlend(dialog->statefrac);
	}

	if (dialogbottom < dialogtop + LINEHEIGHT) {
		dialogbottom = dialogtop + LINEHEIGHT;
	}

	colour1 = MIXCOLOUR(dialog, unk10);

	if (dialog->dimmed) {
		colour1 = (colourBlend(colour1, 0x00000000, 44) & 0xffffff00) | (colour1 & 0xff);
	}

	colour2 = MIXCOLOUR(dialog, unk14);

	// Draw the dialog's background and outer borders
	if (!lightweight) {
		if (dialog->state == MENUDIALOGSTATE_OPENING) {
			gdl = menugfxRenderDialogBackground(gdl, dialogleft + 1, dialogtop + LINEHEIGHT, dialogright - 1, dialogbottom, dialog, colour1, colour2, 1.0f);
		} else if (dialog->state == MENUDIALOGSTATE_POPULATING) {
			gdl = menugfxRenderDialogBackground(gdl, dialogleft + 1, dialogtop + LINEHEIGHT, dialogright - 1, dialogbottom, dialog, colour1, colour2, dialog->statefrac);
		} else {
			gdl = menugfxRenderDialogBackground(gdl, dialogleft + 1, dialogtop + LINEHEIGHT, dialogright - 1, dialogbottom, dialog, colour1, colour2, -1.0f);
		}

		// No dialog has this flag, so this branch is unused
		if (dialog->definition->flags & MENUDIALOGFLAG_DISABLETITLEBAR) {
			gdl = menugfxDrawDialogBorderLine(gdl, dialogleft + 1, dialogtop + LINEHEIGHT, dialogright - 1, dialogtop + LINEHEIGHT + 1, MIXCOLOUR(dialog, unk00), MIXCOLOUR(dialog, unk08));
		}
	}

	if (dialog->state == MENUDIALOGSTATE_PREOPEN) {
		return gdl;
	}

	{
		struct menulayer *layer;
		s32 viewleft = viGetViewLeft() / g_ScaleX;
		s32 viewtop = viGetViewTop();
		s32 viewright = (viGetViewLeft() + viGetViewWidth()) / g_ScaleX;
		s32 viewbottom = viGetViewTop() + viGetViewHeight();

		g_MenuScissorX1 = dialogleft + 2;
		g_MenuScissorX2 = dialogright - 2;
		g_MenuScissorY1 = dialogtop + LINEHEIGHT;
		g_MenuScissorY2 = dialogbottom - 1;

		if (g_MenuScissorX2 < viewleft) {
			return gdl;
		}

		if (g_MenuScissorY2 < viewtop) {
			return gdl;
		}

		if (g_MenuScissorX1 > viewright) {
			return gdl;
		}

		if (g_MenuScissorY1 > viewbottom) {
			return gdl;
		}

		if (g_MenuScissorX2 > viewright) {
			g_MenuScissorX2 = viewright;
		}

		if (g_MenuScissorY2 > viewbottom) {
			g_MenuScissorY2 = viewbottom;
		}

		if (g_MenuScissorX1 < viewleft) {
			g_MenuScissorX1 = viewleft;
		}

		// @bug: This should be g_MenuScissorY1
		// but the condition can't pass anyway.
		if (g_MenuScissorX2 < viewtop) {
			g_MenuScissorX2 = viewtop;
		}

		var8009de90 = g_MenuScissorY1;
		var8009de94 = g_MenuScissorY2;

		gdl = menuApplyScissor(gdl);

		// Render models (inventory, chr/vehicle bios)
		if (g_Menus[g_MpPlayerNum].curdialog == dialog
				&& (dialog->definition->flags & MENUDIALOGFLAG_0002)
				&& !lightweight
				&& !g_Menus[g_MpPlayerNum].unk840.unk5b1_07) {
			gSPSetGeometryMode(gdl++, G_ZBUFFER);

			gdl = menuRenderModels(gdl, &g_Menus[g_MpPlayerNum].unk840, 0);

			gSPClearGeometryMode(gdl++, G_ZBUFFER);

			viSetViewPosition(g_Vars.currentplayer->viewleft, g_Vars.currentplayer->viewtop);
			viSetFovAspectAndSize(g_Vars.currentplayer->fovy, g_Vars.currentplayer->aspect,
					g_Vars.currentplayer->viewwidth, g_Vars.currentplayer->viewheight);
		}

		// Render menu items
		if (dialog->type != 0 || dialog->transitionfrac >= 0.0f) {
			u32 stack;
			s32 sumwidth;
			s32 cury;
			bool prevwaslist;
			s32 colwidth;
			u32 sp120;
			bool offscreen;
			struct menuitem *item;
			s32 focused;
			s32 colindex;
			s32 rowindex;

			sumwidth = 0;
			curx = dialogleft;

			for (i = 0; i < dialog->numcols; i++) {
				cury = dialogtop + LINEHEIGHT + 1 + dialog->scroll;
				prevwaslist = false;

				sp120 = MIXCOLOUR(dialog, unfocused);
				sp120 = (sp120 & 0xffffff00) | 0x3f;

				colindex = dialog->colstart + i;

				if (i != 0 && (dialog->definition->flags & MENUDIALOGFLAG_0400) == 0) {
					gdl = menugfxDrawFilledRect(gdl, curx - 1, dialogtop + LINEHEIGHT + 1, curx, dialogbottom, sp120, sp120);
				}

				colwidth = menu->cols[colindex].width;
				sumwidth += colwidth;

				if (i == dialog->numcols - 1) {
					s32 v0 = (dialogright - dialogleft) - 2;

					if (sumwidth < v0) {
						colwidth = (colwidth + v0) - sumwidth;
					}
				}

				for (j = 0; j < menu->cols[colindex].numrows; j++) {
					focused = 0;
					rowindex = menu->cols[colindex].rowstart + j;
					item = &dialog->definition->items[menu->rows[rowindex].itemindex];
					itemdata = NULL;
					offscreen = false;

					if (item == dialog->focuseditem) {
						focused = 1;

						if (dialog->dimmed) {
							focused = 3;
						}
					}

					if (menu->rows[rowindex].blockindex != -1) {
						itemdata = (union menuitemdata *)&menu->blocks[menu->rows[rowindex].blockindex];
					}

					context.x = curx;
					context.y = cury;
					context.width = colwidth;
					context.height = menu->rows[rowindex].height;

					if (context.y + context.height < dialogtop + LINEHEIGHT + 1) {
						offscreen = true;
					}

					if (context.y > dialogbottom) {
						offscreen = true;
					}

					if (context.height == 0) {
						offscreen = true;
					}

					if (!offscreen) {
						context.item = item;
						context.data = itemdata;
						context.focused = focused;
						context.dialog = dialog;

						if (prevwaslist) {
							gdl = menugfxDrawFilledRect(gdl, context.x, context.y - 1, context.x + context.width, context.y, sp120, sp120);
							prevwaslist = false;
						}

						if ((item->flags & MENUITEMFLAG_DARKERBG) && !lightweight) {
							// Render a darker background behind the item
							s32 x1 = context.x;
							s32 y1 = context.y;
							s32 x2 = x1 + context.width;
							s32 y2 = y1 + context.height;
							u32 colour;
							u32 colour2;

							colour2 = MIXCOLOUR(dialog, unk28);
							colour = colourBlend(colour2, colour2 & 0xffffff00, 127);

							gdl = textSetPrimColour(gdl, colour);
							gDPFillRectangleScaled(gdl++, x1, y1, x2, y2);
							gdl = text0f153838(gdl);
						}

						if (focused) {
							if (item->type == MENUITEMTYPE_03
									|| item->type == MENUITEMTYPE_SELECTABLE
									|| item->type == MENUITEMTYPE_CHECKBOX
									|| item->type == MENUITEMTYPE_0A
									|| item->type == MENUITEMTYPE_SLIDER
									|| item->type == MENUITEMTYPE_DROPDOWN) {
#if VERSION >= VERSION_NTSC_1_0
								if (!(dialog->transitionfrac >= 0.0f && dialog->type2 == 0)
										&& !(dialog->transitionfrac < 0.0f && dialog->type == 0)) {
									text0f156024(1);
								}
#else
								text0f156024(1);
#endif
							}

							// Render the horizontal line behind the focused item
							if (item->type == MENUITEMTYPE_SELECTABLE
									|| item->type == MENUITEMTYPE_CHECKBOX
									|| item->type == MENUITEMTYPE_0A
									|| item->type == MENUITEMTYPE_DROPDOWN) {
								s32 liney = context.y + context.height / 2 - 1;
								s32 x1 = context.x;
								s32 x3 = context.x + 8;
								s32 x4 = context.x + context.width / 3;
								u32 colour = (sp120 & 0xffffff00) | 0x2f;

								// Left side
								gdl = menugfx0f0e2498(gdl);
								gdl = menugfxDrawTri2(gdl, x1, liney - 1, x3 - 3, liney, sp120, sp120, 0);
								gdl = menugfxDrawTri2(gdl, x3 - 3, liney - 1, x3, liney, sp120, 0xffffffff, 0);
								gdl = menugfxDrawTri2(gdl, x1, liney + 1, x3 - 3, liney + 2, sp120, sp120, 0);
								gdl = menugfxDrawTri2(gdl, x3 - 3, liney + 1, x3, liney + 2, sp120, 0xffffffff, 0);
								gdl = menugfxDrawTri2(gdl, x3 - 2, liney, x4, liney + 1, colour, sp120 & 0xffffff00, 0);

								if (item->flags & MENUITEMFLAG_SELECTABLE_CENTRE) {
									// Right side
									x1 = context.x + context.width;
									x3 = context.x + context.width - 8;
									x4 = context.x + context.width - context.width / 3;

									gdl = menugfxDrawTri2(gdl, x1 - 5, liney - 1, x1, liney, sp120, sp120, 0);
									gdl = menugfxDrawTri2(gdl, x3, liney - 1, x3 + 3, liney, -1, sp120, 0);
									gdl = menugfxDrawTri2(gdl, x3 + 3, liney + 1, x1, liney + 2, sp120, sp120, 0);
									gdl = menugfxDrawTri2(gdl, x3, liney + 1, x3 + 3, liney + 2, -1, sp120, 0);
									gdl = menugfxDrawTri2(gdl, x4, liney, x3 + 2, liney + 1, sp120 & 0xffffff00, colour, 0);
								}
							}
						}

						gdl = menuitemRender(gdl, &context);

						if (item->type == MENUITEMTYPE_LIST) {
							prevwaslist = true;
						}

						if (focused) {
							text0f156024(0);
						}
					}

					cury += menu->rows[rowindex].height;
				}

				curx += menu->cols[colindex].width;
			}

			// Render overlays, such as dropdown menus
			if (!lightweight) {
				gdl = textSetPrimColour(gdl, 0x00000000);

				curx = dialogleft;

				for (i = 0; i < dialog->numcols; i++) {
#if VERSION >= VERSION_NTSC_1_0
					s32 cury = dialogtop + LINEHEIGHT + 1 + dialog->scroll;
#else
					s32 cury = dialogtop + LINEHEIGHT + 1;
#endif
					colindex = dialog->colstart + i;

					for (j = 0; j < menu->cols[colindex].numrows; j++) {
						union menuitemdata *itemdata;
						struct menuitem *item;

						rowindex = menu->cols[colindex].rowstart + j;
						itemdata = NULL;
						item = &dialog->definition->items[menu->rows[rowindex].itemindex];

						if (menu->rows[rowindex].blockindex != -1) {
							itemdata = (union menuitemdata *)&menu->blocks[menu->rows[rowindex].blockindex];
						}

						gdl = menuitemOverlay(gdl, curx, cury, menu->cols[colindex].width, menu->rows[rowindex].height, item, dialog, itemdata);

						cury += menu->rows[rowindex].height;
					}

					curx += menu->cols[colindex].width;
				}

				gdl = text0f153838(gdl);
			}

			gDPSetScissor(gdl++, G_SC_NON_INTERLACE, viGetViewLeft(), viGetViewTop(),
					viGetViewLeft() + viGetViewWidth(), viGetViewTop() + viGetViewHeight());
		} else {
			gDPSetScissor(gdl++, G_SC_NON_INTERLACE, viGetViewLeft(), viGetViewTop(),
					viGetViewLeft() + viGetViewWidth(), viGetViewTop() + viGetViewHeight());
		}

		// Render left/right chevrons and sibling dialog titles
		layer = &g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth - 1];

		if ((dialog->type != 0 || dialog->transitionfrac >= 0.0f)
				&& layer->siblings[layer->cursibling] == dialog
				&& layer->numsiblings >= 2) {
			// Draw chevrons
			u32 colour1;
			u32 colour;
			u32 weight = menuGetSinOscFrac(10) * 255.0f;

			colour1 = MIXCOLOUR(dialog, unk00);
			colour = colourBlend(0xffffffff, colour1, weight);

			gdl = menugfxDrawDialogChevron(gdl, dialogleft - 5, (dialogtop + dialogbottom) / 2, 9, 1, colour, colour, menuGetSinOscFrac(20));
			gdl = menugfxDrawDialogChevron(gdl, dialogright + 5, (dialogtop + dialogbottom) / 2, 9, 3, colour, colour, menuGetSinOscFrac(20));

			if (g_MenuData.root == MENUROOT_MAINMENU
					|| g_MenuData.root == MENUROOT_4MBFILEMGR
					|| g_MenuData.root == MENUROOT_TRAINING
					|| g_MenuData.root == MENUROOT_FILEMGR) {
				char *title;
				s32 textheight;
				s32 textwidth;
				s32 previndex;
				s32 nextindex;

				textResetBlends();
				textSetRotation90(true);

				gdl = text0f153628(gdl);

				// Left/previous title
				previndex = layer->cursibling - 1;

				if (previndex < 0) {
					previndex = layer->numsiblings - 1;
				}

				title = menuResolveDialogTitle(layer->siblings[previndex]->definition);

				textMeasure(&textheight, &textwidth, title, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

				x = dialogleft - 1;
				y = (dialogtop + dialogbottom) / 2 - textwidth - 3;

				if (y < dialogtop) {
					y = (dialogtop + dialogbottom - textwidth) / 2;
					x -= 3;
				}

				gdl = textRenderProjected(gdl, &y, &x, title, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0xffffffff, dialogwidth, viGetHeight(), 0, 0);

				// Right/next title
				nextindex = layer->cursibling + 1;

				if (nextindex >= layer->numsiblings) {
					nextindex = 0;
				}

				title = menuResolveDialogTitle(layer->siblings[nextindex]->definition);

				textMeasure(&textheight, &textwidth, title, g_CharsHandelGothicXs, g_FontHandelGothicXs, 0);

#if VERSION == VERSION_JPN_FINAL
				x = dialogright + 13;
#else
				x = dialogright + 7;
#endif
				y = (dialogtop + dialogbottom) / 2 + 3;

				if (y + textwidth > dialogbottom) {
					y = (dialogtop + dialogbottom - textwidth) / 2;
					x += 3;
				}

				gdl = textRenderProjected(gdl, &y, &x, title, g_CharsHandelGothicXs, g_FontHandelGothicXs, -1, dialogwidth, viGetHeight(), 0, 0);
				gdl = text0f153780(gdl);

				textSetRotation90(false);
			}
		}
	}

	return gdl;
}

const char var7f1b2668[] = "[]-[] Terminate Complete\n";
const char var7f1b2684[] = "Enabling control %d\n";
const char var7f1b269c[] = "NOT IN MODE MULTIINGAME!\n";
const char var7f1b26b8[] = "Numactive now:%d\n";
const char var7f1b26cc[] = "[]-[] SwitchMenuMode called, context %d\n";

void menuGetContPads(s8 *contpadnum1, s8 *contpadnum2)
{
	switch (g_MenuData.root) {
	case MENUROOT_MPSETUP:
	case MENUROOT_FILEMGR:
	case MENUROOT_BOOTPAKMGR:
	case MENUROOT_4MBFILEMGR:
	case MENUROOT_4MBMAINMENU:
		*contpadnum1 = g_MpPlayerNum;
		*contpadnum2 = -1;
		break;
	default:
		*contpadnum1 = optionsGetContpadNum1(g_Vars.currentplayerstats->mpindex);
		*contpadnum2 = -1;

		if (!g_Vars.normmplayerisrunning) {
			s32 mode = optionsGetControlMode(g_Vars.currentplayerstats->mpindex);

			if (mode == CONTROLMODE_23 || mode == CONTROLMODE_24 || mode == CONTROLMODE_22 || mode == CONTROLMODE_21) {
				*contpadnum2 = optionsGetContpadNum2(g_Vars.currentplayerstats->mpindex);
			}
		}
		break;
	}
}

u32 g_MpNumJoined = 1;

/**
 * Choose which direction a new dialog should swipe from in the combat simulator
 * menus.
 */
void func0f0f7594(s32 arg0, s32 *vdir, s32 *hdir)
{
	if (g_MenuData.root == MENUROOT_MPSETUP) {
		s32 playernum = g_Menus[g_MpPlayerNum].playernum;

		*vdir = 0;
		*hdir = 0;

		switch (g_MpNumJoined) {
		case 1:
			*hdir = arg0;
			break;
		case 2:
			if (playernum == 0) {
				if (arg0 < 0) {
					*hdir = -1;
				} else {
					*vdir = -1;
				}
			} else {
				if (arg0 > 0) {
					*hdir = 1;
				} else {
					*vdir = 1;
				}
			}
			break;
		case 3:
			if (playernum == 2) {
				*hdir = arg0;
			} else if (playernum == 0) {
				if (arg0 < 0) {
					*hdir = -1;
				} else {
					*vdir = -1;
				}
			} else {
				if (arg0 > 0) {
					*hdir = 1;
				} else {
					*vdir = -1;
				}
			}
			break;
		case 4:
			if (playernum == 0 || playernum == 2) {
				if (arg0 < 0) {
					*hdir = -1;
				} else {
					*vdir = playernum == 0 ? -1 : 1;
				}
			} else {
				if (arg0 > 0) {
					*hdir = 1;
				} else {
					*vdir = playernum == 1 ? -1 : 1;
				}
			}
			break;
		}
	} else {
		*vdir = 0;
		*hdir = arg0;
	}
}

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel menuFindAvailableSize
.late_rodata
glabel var7f1b369cjf
.word 0x7f0f859c
.word 0x7f0f87f4
.word 0x7f0f87f4
.word 0x7f0f8b64
.word 0x7f0f8b64
.word 0x7f0f87f4
.word 0x7f0f8b64
.word 0x7f0f87f4
.word 0x7f0f859c
.text
/*  f0f83cc:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f0f83d0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f0f83d4:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f0f83d8:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f0f83dc:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f0f83e0:	0c002f29 */ 	jal	viGetViewLeft
/*  f0f83e4:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f0f83e8:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0f83ec:	8dce00f4 */ 	lw	$t6,0xf4($t6)
/*  f0f83f0:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f0f83f4:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f0f83f8:	004e001a */ 	div	$zero,$v0,$t6
/*  f0f83fc:	00003012 */ 	mflo	$a2
/*  f0f8400:	24c60014 */ 	addiu	$a2,$a2,0x14
/*  f0f8404:	15c00002 */ 	bnez	$t6,.JF0f0f8410
/*  f0f8408:	00000000 */ 	nop
/*  f0f840c:	0007000d */ 	break	0x7
.JF0f0f8410:
/*  f0f8410:	2401ffff */ 	li	$at,-1
/*  f0f8414:	15c10004 */ 	bne	$t6,$at,.JF0f0f8428
/*  f0f8418:	3c018000 */ 	lui	$at,0x8000
/*  f0f841c:	14410002 */ 	bne	$v0,$at,.JF0f0f8428
/*  f0f8420:	00000000 */ 	nop
/*  f0f8424:	0006000d */ 	break	0x6
.JF0f0f8428:
/*  f0f8428:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f0f842c:	0c002f2d */ 	jal	viGetViewTop
/*  f0f8430:	00000000 */ 	nop
/*  f0f8434:	24440004 */ 	addiu	$a0,$v0,0x4
/*  f0f8438:	0c002f29 */ 	jal	viGetViewLeft
/*  f0f843c:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0f8440:	0c002f0b */ 	jal	viGetViewWidth
/*  f0f8444:	a7a2001e */ 	sh	$v0,0x1e($sp)
/*  f0f8448:	87af001e */ 	lh	$t7,0x1e($sp)
/*  f0f844c:	3c198008 */ 	lui	$t9,0x8008
/*  f0f8450:	8f3900f4 */ 	lw	$t9,0xf4($t9)
/*  f0f8454:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f0f8458:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0f845c:	0319001a */ 	div	$zero,$t8,$t9
/*  f0f8460:	00003812 */ 	mflo	$a3
/*  f0f8464:	24e7ffec */ 	addiu	$a3,$a3,-20
/*  f0f8468:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f0f846c:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f0f8470:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f0f8474:	17200002 */ 	bnez	$t9,.JF0f0f8480
/*  f0f8478:	00000000 */ 	nop
/*  f0f847c:	0007000d */ 	break	0x7
.JF0f0f8480:
/*  f0f8480:	2401ffff */ 	li	$at,-1
/*  f0f8484:	17210004 */ 	bne	$t9,$at,.JF0f0f8498
/*  f0f8488:	3c018000 */ 	lui	$at,0x8000
/*  f0f848c:	17010002 */ 	bne	$t8,$at,.JF0f0f8498
/*  f0f8490:	00000000 */ 	nop
/*  f0f8494:	0006000d */ 	break	0x6
.JF0f0f8498:
/*  f0f8498:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f0f849c:	0c002f2d */ 	jal	viGetViewTop
/*  f0f84a0:	00000000 */ 	nop
/*  f0f84a4:	0c002f0f */ 	jal	viGetViewHeight
/*  f0f84a8:	a7a2001e */ 	sh	$v0,0x1e($sp)
/*  f0f84ac:	87ae001e */ 	lh	$t6,0x1e($sp)
/*  f0f84b0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0f84b4:	004e2821 */ 	addu	$a1,$v0,$t6
/*  f0f84b8:	24a5fffc */ 	addiu	$a1,$a1,-4
/*  f0f84bc:	0fc3c64f */ 	jal	currentPlayerIsMenuOpenInSoloOrMp
/*  f0f84c0:	afa50030 */ 	sw	$a1,0x30($sp)
/*  f0f84c4:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f0f84c8:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0f84cc:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f0f84d0:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f0f84d4:	8fa70034 */ 	lw	$a3,0x34($sp)
/*  f0f84d8:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f0f84dc:	10400002 */ 	beqz	$v0,.JF0f0f84e8
/*  f0f84e0:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f0f84e4:	24030001 */ 	li	$v1,0x1
.JF0f0f84e8:
/*  f0f84e8:	8fa80050 */ 	lw	$t0,0x50($sp)
/*  f0f84ec:	1100000d */ 	beqz	$t0,.JF0f0f8524
/*  f0f84f0:	00000000 */ 	nop
/*  f0f84f4:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f0f84f8:	3c0f8007 */ 	lui	$t7,0x8007
/*  f0f84fc:	25ef26a8 */ 	addiu	$t7,$t7,0x26a8
/*  f0f8500:	11e20007 */ 	beq	$t7,$v0,.JF0f0f8520
/*  f0f8504:	3c188007 */ 	lui	$t8,0x8007
/*  f0f8508:	27182654 */ 	addiu	$t8,$t8,0x2654
/*  f0f850c:	13020004 */ 	beq	$t8,$v0,.JF0f0f8520
/*  f0f8510:	3c198007 */ 	lui	$t9,0x8007
/*  f0f8514:	27392600 */ 	addiu	$t9,$t9,0x2600
/*  f0f8518:	17220002 */ 	bne	$t9,$v0,.JF0f0f8524
/*  f0f851c:	00000000 */ 	nop
.JF0f0f8520:
/*  f0f8520:	00001825 */ 	move	$v1,$zero
.JF0f0f8524:
/*  f0f8524:	10600011 */ 	beqz	$v1,.JF0f0f856c
/*  f0f8528:	00000000 */ 	nop
/*  f0f852c:	24840016 */ 	addiu	$a0,$a0,0x16
/*  f0f8530:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f0f8534:	afa50030 */ 	sw	$a1,0x30($sp)
/*  f0f8538:	afa6003c */ 	sw	$a2,0x3c($sp)
/*  f0f853c:	0fc548e8 */ 	jal	optionsGetEffectiveScreenSize
/*  f0f8540:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f0f8544:	24010002 */ 	li	$at,0x2
/*  f0f8548:	8fa40038 */ 	lw	$a0,0x38($sp)
/*  f0f854c:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f0f8550:	8fa6003c */ 	lw	$a2,0x3c($sp)
/*  f0f8554:	8fa70034 */ 	lw	$a3,0x34($sp)
/*  f0f8558:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f0f855c:	14410003 */ 	bne	$v0,$at,.JF0f0f856c
/*  f0f8560:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f0f8564:	2484fff8 */ 	addiu	$a0,$a0,-8
/*  f0f8568:	24a50004 */ 	addiu	$a1,$a1,0x4
.JF0f0f856c:
/*  f0f856c:	3c02800a */ 	lui	$v0,0x800a
/*  f0f8570:	244220c0 */ 	addiu	$v0,$v0,0x20c0
/*  f0f8574:	8c4e0004 */ 	lw	$t6,0x4($v0)
/*  f0f8578:	25cffffd */ 	addiu	$t7,$t6,-3
/*  f0f857c:	2de10009 */ 	sltiu	$at,$t7,0x9
/*  f0f8580:	10200178 */ 	beqz	$at,.JF0f0f8b64
/*  f0f8584:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f8588:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0f858c:	002f0821 */ 	addu	$at,$at,$t7
/*  f0f8590:	8c2f369c */ 	lw	$t7,0x369c($at)
/*  f0f8594:	01e00008 */ 	jr	$t7
/*  f0f8598:	00000000 */ 	nop
/*  f0f859c:	3c1f8007 */ 	lui	$ra,0x8007
/*  f0f85a0:	27ff1998 */ 	addiu	$ra,$ra,0x1998
/*  f0f85a4:	8ff80000 */ 	lw	$t8,0x0($ra)
/*  f0f85a8:	904f0017 */ 	lbu	$t7,0x17($v0)
/*  f0f85ac:	3c0d800a */ 	lui	$t5,0x800a
/*  f0f85b0:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0f85b4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f85b8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0f85bc:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0f85c0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0f85c4:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0f85c8:	25ade700 */ 	addiu	$t5,$t5,-6400
/*  f0f85cc:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0f85d0:	01b97021 */ 	addu	$t6,$t5,$t9
/*  f0f85d4:	1de00004 */ 	bgtz	$t7,.JF0f0f85e8
/*  f0f85d8:	91c3083b */ 	lbu	$v1,0x83b($t6)
/*  f0f85dc:	90580018 */ 	lbu	$t8,0x18($v0)
/*  f0f85e0:	5b000003 */ 	blezl	$t8,.JF0f0f85f0
/*  f0f85e4:	90590019 */ 	lbu	$t9,0x19($v0)
.JF0f0f85e8:
/*  f0f85e8:	2484000a */ 	addiu	$a0,$a0,0xa
/*  f0f85ec:	90590019 */ 	lbu	$t9,0x19($v0)
.JF0f0f85f0:
/*  f0f85f0:	5f200005 */ 	bgtzl	$t9,.JF0f0f8608
/*  f0f85f4:	24a5fff6 */ 	addiu	$a1,$a1,-10
/*  f0f85f8:	904e001a */ 	lbu	$t6,0x1a($v0)
/*  f0f85fc:	19c00002 */ 	blez	$t6,.JF0f0f8608
/*  f0f8600:	00000000 */ 	nop
/*  f0f8604:	24a5fff6 */ 	addiu	$a1,$a1,-10
.JF0f0f8608:
/*  f0f8608:	3c028007 */ 	lui	$v0,0x8007
/*  f0f860c:	8c421a28 */ 	lw	$v0,0x1a28($v0)
/*  f0f8610:	24010001 */ 	li	$at,0x1
/*  f0f8614:	1041000a */ 	beq	$v0,$at,.JF0f0f8640
/*  f0f8618:	24010002 */ 	li	$at,0x2
/*  f0f861c:	1041000f */ 	beq	$v0,$at,.JF0f0f865c
/*  f0f8620:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0f8624:	24010003 */ 	li	$at,0x3
/*  f0f8628:	10410020 */ 	beq	$v0,$at,.JF0f0f86ac
/*  f0f862c:	24010004 */ 	li	$at,0x4
/*  f0f8630:	10410047 */ 	beq	$v0,$at,.JF0f0f8750
/*  f0f8634:	00000000 */ 	nop
/*  f0f8638:	10000151 */ 	b	.JF0f0f8b80
/*  f0f863c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.JF0f0f8640:
/*  f0f8640:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f8644:	ad870000 */ 	sw	$a3,0x0($t4)
/*  f0f8648:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f864c:	ade40000 */ 	sw	$a0,0x0($t7)
/*  f0f8650:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f0f8654:	10000149 */ 	b	.JF0f0f8b7c
/*  f0f8658:	af050000 */ 	sw	$a1,0x0($t8)
.JF0f0f865c:
/*  f0f865c:	af240000 */ 	sw	$a0,0x0($t9)
/*  f0f8660:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0f8664:	00c7c821 */ 	addu	$t9,$a2,$a3
/*  f0f8668:	14600009 */ 	bnez	$v1,.JF0f0f8690
/*  f0f866c:	adc50000 */ 	sw	$a1,0x0($t6)
/*  f0f8670:	00c77821 */ 	addu	$t7,$a2,$a3
/*  f0f8674:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f8678:	05e10003 */ 	bgez	$t7,.JF0f0f8688
/*  f0f867c:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f0f8680:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0f8684:	0001c043 */ 	sra	$t8,$at,0x1
.JF0f0f8688:
/*  f0f8688:	1000013c */ 	b	.JF0f0f8b7c
/*  f0f868c:	ad980000 */ 	sw	$t8,0x0($t4)
.JF0f0f8690:
/*  f0f8690:	07210003 */ 	bgez	$t9,.JF0f0f86a0
/*  f0f8694:	00197043 */ 	sra	$t6,$t9,0x1
/*  f0f8698:	27210001 */ 	addiu	$at,$t9,0x1
/*  f0f869c:	00017043 */ 	sra	$t6,$at,0x1
.JF0f0f86a0:
/*  f0f86a0:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f0f86a4:	10000135 */ 	b	.JF0f0f8b7c
/*  f0f86a8:	ad870000 */ 	sw	$a3,0x0($t4)
.JF0f0f86ac:
/*  f0f86ac:	10600003 */ 	beqz	$v1,.JF0f0f86bc
/*  f0f86b0:	24080001 */ 	li	$t0,0x1
/*  f0f86b4:	1468001b */ 	bne	$v1,$t0,.JF0f0f8724
/*  f0f86b8:	00857821 */ 	addu	$t7,$a0,$a1
.JF0f0f86bc:
/*  f0f86bc:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f86c0:	0085c021 */ 	addu	$t8,$a0,$a1
/*  f0f86c4:	ade40000 */ 	sw	$a0,0x0($t7)
/*  f0f86c8:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0f86cc:	07010003 */ 	bgez	$t8,.JF0f0f86dc
/*  f0f86d0:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f86d4:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f86d8:	0001c843 */ 	sra	$t9,$at,0x1
.JF0f0f86dc:
/*  f0f86dc:	14600009 */ 	bnez	$v1,.JF0f0f8704
/*  f0f86e0:	add90000 */ 	sw	$t9,0x0($t6)
/*  f0f86e4:	00c77821 */ 	addu	$t7,$a2,$a3
/*  f0f86e8:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f86ec:	05e10003 */ 	bgez	$t7,.JF0f0f86fc
/*  f0f86f0:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f0f86f4:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0f86f8:	0001c043 */ 	sra	$t8,$at,0x1
.JF0f0f86fc:
/*  f0f86fc:	1000011f */ 	b	.JF0f0f8b7c
/*  f0f8700:	ad980000 */ 	sw	$t8,0x0($t4)
.JF0f0f8704:
/*  f0f8704:	00c7c821 */ 	addu	$t9,$a2,$a3
/*  f0f8708:	07210003 */ 	bgez	$t9,.JF0f0f8718
/*  f0f870c:	00197043 */ 	sra	$t6,$t9,0x1
/*  f0f8710:	27210001 */ 	addiu	$at,$t9,0x1
/*  f0f8714:	00017043 */ 	sra	$t6,$at,0x1
.JF0f0f8718:
/*  f0f8718:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f0f871c:	10000117 */ 	b	.JF0f0f8b7c
/*  f0f8720:	ad870000 */ 	sw	$a3,0x0($t4)
.JF0f0f8724:
/*  f0f8724:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0f8728:	05e10003 */ 	bgez	$t7,.JF0f0f8738
/*  f0f872c:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f0f8730:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0f8734:	0001c043 */ 	sra	$t8,$at,0x1
.JF0f0f8738:
/*  f0f8738:	af380000 */ 	sw	$t8,0x0($t9)
/*  f0f873c:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0f8740:	adc50000 */ 	sw	$a1,0x0($t6)
/*  f0f8744:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f8748:	1000010c */ 	b	.JF0f0f8b7c
/*  f0f874c:	ad870000 */ 	sw	$a3,0x0($t4)
.JF0f0f8750:
/*  f0f8750:	10600003 */ 	beqz	$v1,.JF0f0f8760
/*  f0f8754:	24010002 */ 	li	$at,0x2
/*  f0f8758:	14610009 */ 	bne	$v1,$at,.JF0f0f8780
/*  f0f875c:	00c7c821 */ 	addu	$t9,$a2,$a3
.JF0f0f8760:
/*  f0f8760:	00c77821 */ 	addu	$t7,$a2,$a3
/*  f0f8764:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f8768:	05e10003 */ 	bgez	$t7,.JF0f0f8778
/*  f0f876c:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f0f8770:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0f8774:	0001c043 */ 	sra	$t8,$at,0x1
.JF0f0f8778:
/*  f0f8778:	10000007 */ 	b	.JF0f0f8798
/*  f0f877c:	ad980000 */ 	sw	$t8,0x0($t4)
.JF0f0f8780:
/*  f0f8780:	07210003 */ 	bgez	$t9,.JF0f0f8790
/*  f0f8784:	00197043 */ 	sra	$t6,$t9,0x1
/*  f0f8788:	27210001 */ 	addiu	$at,$t9,0x1
/*  f0f878c:	00017043 */ 	sra	$t6,$at,0x1
.JF0f0f8790:
/*  f0f8790:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f0f8794:	ad870000 */ 	sw	$a3,0x0($t4)
.JF0f0f8798:
/*  f0f8798:	10600003 */ 	beqz	$v1,.JF0f0f87a8
/*  f0f879c:	24080001 */ 	li	$t0,0x1
/*  f0f87a0:	1468000b */ 	bne	$v1,$t0,.JF0f0f87d0
/*  f0f87a4:	00857821 */ 	addu	$t7,$a0,$a1
.JF0f0f87a8:
/*  f0f87a8:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f0f87ac:	0085c021 */ 	addu	$t8,$a0,$a1
/*  f0f87b0:	ade40000 */ 	sw	$a0,0x0($t7)
/*  f0f87b4:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0f87b8:	07010003 */ 	bgez	$t8,.JF0f0f87c8
/*  f0f87bc:	0018c843 */ 	sra	$t9,$t8,0x1
/*  f0f87c0:	27010001 */ 	addiu	$at,$t8,0x1
/*  f0f87c4:	0001c843 */ 	sra	$t9,$at,0x1
.JF0f0f87c8:
/*  f0f87c8:	100000ec */ 	b	.JF0f0f8b7c
/*  f0f87cc:	add90000 */ 	sw	$t9,0x0($t6)
.JF0f0f87d0:
/*  f0f87d0:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0f87d4:	05e10003 */ 	bgez	$t7,.JF0f0f87e4
/*  f0f87d8:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f0f87dc:	25e10001 */ 	addiu	$at,$t7,0x1
/*  f0f87e0:	0001c043 */ 	sra	$t8,$at,0x1
.JF0f0f87e4:
/*  f0f87e4:	af380000 */ 	sw	$t8,0x0($t9)
/*  f0f87e8:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0f87ec:	100000e3 */ 	b	.JF0f0f8b7c
/*  f0f87f0:	adc50000 */ 	sw	$a1,0x0($t6)
/*  f0f87f4:	3c1f8007 */ 	lui	$ra,0x8007
/*  f0f87f8:	27ff1998 */ 	addiu	$ra,$ra,0x1998
/*  f0f87fc:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f0f8800:	3c0d800a */ 	lui	$t5,0x800a
/*  f0f8804:	25ade700 */ 	addiu	$t5,$t5,-6400
/*  f0f8808:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*  f0f880c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f8810:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f0f8814:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f0f8818:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f0f881c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f0f8820:	0018c100 */ 	sll	$t8,$t8,0x4
/*  f0f8824:	01b8c821 */ 	addu	$t9,$t5,$t8
/*  f0f8828:	932e083b */ 	lbu	$t6,0x83b($t9)
/*  f0f882c:	3c03800a */ 	lui	$v1,0x800a
/*  f0f8830:	2463a630 */ 	addiu	$v1,$v1,-22992
/*  f0f8834:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f0f8838:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f0f883c:	8f190064 */ 	lw	$t9,0x64($t8)
/*  f0f8840:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0f8844:	8def00f4 */ 	lw	$t7,0xf4($t7)
/*  f0f8848:	872e0634 */ 	lh	$t6,0x634($t9)
/*  f0f884c:	00005025 */ 	move	$t2,$zero
/*  f0f8850:	01cf001a */ 	div	$zero,$t6,$t7
/*  f0f8854:	0000c012 */ 	mflo	$t8
/*  f0f8858:	ad780000 */ 	sw	$t8,0x0($t3)
/*  f0f885c:	8ff90000 */ 	lw	$t9,0x0($ra)
/*  f0f8860:	15e00002 */ 	bnez	$t7,.JF0f0f886c
/*  f0f8864:	00000000 */ 	nop
/*  f0f8868:	0007000d */ 	break	0x7
.JF0f0f886c:
/*  f0f886c:	2401ffff */ 	li	$at,-1
/*  f0f8870:	15e10004 */ 	bne	$t7,$at,.JF0f0f8884
/*  f0f8874:	3c018000 */ 	lui	$at,0x8000
/*  f0f8878:	15c10002 */ 	bne	$t6,$at,.JF0f0f8884
/*  f0f887c:	00000000 */ 	nop
/*  f0f8880:	0006000d */ 	break	0x6
.JF0f0f8884:
/*  f0f8884:	001970c0 */ 	sll	$t6,$t9,0x3
/*  f0f8888:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f888c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f8890:	01d97021 */ 	addu	$t6,$t6,$t9
/*  f0f8894:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f8898:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f889c:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f88a0:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0f88a4:	91f8083b */ 	lbu	$t8,0x83b($t7)
/*  f0f88a8:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0f88ac:	00797021 */ 	addu	$t6,$v1,$t9
/*  f0f88b0:	8dcf0064 */ 	lw	$t7,0x64($t6)
/*  f0f88b4:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0f88b8:	85f80636 */ 	lh	$t8,0x636($t7)
/*  f0f88bc:	af380000 */ 	sw	$t8,0x0($t9)
/*  f0f88c0:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f0f88c4:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f88c8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f88cc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f88d0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f88d4:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f88d8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f88dc:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f88e0:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0f88e4:	9319083b */ 	lbu	$t9,0x83b($t8)
/*  f0f88e8:	00197080 */ 	sll	$t6,$t9,0x2
/*  f0f88ec:	006e7821 */ 	addu	$t7,$v1,$t6
/*  f0f88f0:	8de20064 */ 	lw	$v0,0x64($t7)
/*  f0f88f4:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0f88f8:	8def00f4 */ 	lw	$t7,0xf4($t7)
/*  f0f88fc:	84580630 */ 	lh	$t8,0x630($v0)
/*  f0f8900:	84590634 */ 	lh	$t9,0x634($v0)
/*  f0f8904:	03197021 */ 	addu	$t6,$t8,$t9
/*  f0f8908:	01cf001a */ 	div	$zero,$t6,$t7
/*  f0f890c:	0000c012 */ 	mflo	$t8
/*  f0f8910:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0f8914:	8ff90000 */ 	lw	$t9,0x0($ra)
/*  f0f8918:	15e00002 */ 	bnez	$t7,.JF0f0f8924
/*  f0f891c:	00000000 */ 	nop
/*  f0f8920:	0007000d */ 	break	0x7
.JF0f0f8924:
/*  f0f8924:	2401ffff */ 	li	$at,-1
/*  f0f8928:	15e10004 */ 	bne	$t7,$at,.JF0f0f893c
/*  f0f892c:	3c018000 */ 	lui	$at,0x8000
/*  f0f8930:	15c10002 */ 	bne	$t6,$at,.JF0f0f893c
/*  f0f8934:	00000000 */ 	nop
/*  f0f8938:	0006000d */ 	break	0x6
.JF0f0f893c:
/*  f0f893c:	001970c0 */ 	sll	$t6,$t9,0x3
/*  f0f8940:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f8944:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f8948:	01d97021 */ 	addu	$t6,$t6,$t9
/*  f0f894c:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f8950:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f8954:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f8958:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0f895c:	91f8083b */ 	lbu	$t8,0x83b($t7)
/*  f0f8960:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f0f8964:	00797021 */ 	addu	$t6,$v1,$t9
/*  f0f8968:	8dc20064 */ 	lw	$v0,0x64($t6)
/*  f0f896c:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0f8970:	844f0632 */ 	lh	$t7,0x632($v0)
/*  f0f8974:	84580636 */ 	lh	$t8,0x636($v0)
/*  f0f8978:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f0f897c:	add90000 */ 	sw	$t9,0x0($t6)
/*  f0f8980:	8c65006c */ 	lw	$a1,0x6c($v1)
/*  f0f8984:	10a00003 */ 	beqz	$a1,.JF0f0f8994
/*  f0f8988:	00000000 */ 	nop
/*  f0f898c:	10000001 */ 	b	.JF0f0f8994
/*  f0f8990:	240a0001 */ 	li	$t2,0x1
.JF0f0f8994:
/*  f0f8994:	8c660068 */ 	lw	$a2,0x68($v1)
/*  f0f8998:	00003825 */ 	move	$a3,$zero
/*  f0f899c:	00002025 */ 	move	$a0,$zero
/*  f0f89a0:	10c00003 */ 	beqz	$a2,.JF0f0f89b0
/*  f0f89a4:	00000000 */ 	nop
/*  f0f89a8:	10000001 */ 	b	.JF0f0f89b0
/*  f0f89ac:	24070001 */ 	li	$a3,0x1
.JF0f0f89b0:
/*  f0f89b0:	8c680064 */ 	lw	$t0,0x64($v1)
/*  f0f89b4:	00001025 */ 	move	$v0,$zero
/*  f0f89b8:	11000003 */ 	beqz	$t0,.JF0f0f89c8
/*  f0f89bc:	00000000 */ 	nop
/*  f0f89c0:	10000001 */ 	b	.JF0f0f89c8
/*  f0f89c4:	24040001 */ 	li	$a0,0x1
.JF0f0f89c8:
/*  f0f89c8:	8c690070 */ 	lw	$t1,0x70($v1)
/*  f0f89cc:	11200003 */ 	beqz	$t1,.JF0f0f89dc
/*  f0f89d0:	00000000 */ 	nop
/*  f0f89d4:	10000001 */ 	b	.JF0f0f89dc
/*  f0f89d8:	24020001 */ 	li	$v0,0x1
.JF0f0f89dc:
/*  f0f89dc:	00447821 */ 	addu	$t7,$v0,$a0
/*  f0f89e0:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f0f89e4:	030ac821 */ 	addu	$t9,$t8,$t2
/*  f0f89e8:	2b210003 */ 	slti	$at,$t9,0x3
/*  f0f89ec:	14200026 */ 	bnez	$at,.JF0f0f8a88
/*  f0f89f0:	00005025 */ 	move	$t2,$zero
/*  f0f89f4:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f0f89f8:	24010002 */ 	li	$at,0x2
/*  f0f89fc:	3c05800a */ 	lui	$a1,0x800a
/*  f0f8a00:	000e78c0 */ 	sll	$t7,$t6,0x3
/*  f0f8a04:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f8a08:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f0f8a0c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f0f8a10:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f0f8a14:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f0f8a18:	000f7900 */ 	sll	$t7,$t7,0x4
/*  f0f8a1c:	01afc021 */ 	addu	$t8,$t5,$t7
/*  f0f8a20:	9302083b */ 	lbu	$v0,0x83b($t8)
/*  f0f8a24:	3c06800a */ 	lui	$a2,0x800a
/*  f0f8a28:	50400004 */ 	beqzl	$v0,.JF0f0f8a3c
/*  f0f8a2c:	8d790000 */ 	lw	$t9,0x0($t3)
/*  f0f8a30:	1441000b */ 	bne	$v0,$at,.JF0f0f8a60
/*  f0f8a34:	3c08800a */ 	lui	$t0,0x800a
/*  f0f8a38:	8d790000 */ 	lw	$t9,0x0($t3)
.JF0f0f8a3c:
/*  f0f8a3c:	3c08800a */ 	lui	$t0,0x800a
/*  f0f8a40:	3c09800a */ 	lui	$t1,0x800a
/*  f0f8a44:	272e0016 */ 	addiu	$t6,$t9,0x16
/*  f0f8a48:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f0f8a4c:	8d29a6a0 */ 	lw	$t1,-0x5960($t1)
/*  f0f8a50:	8d08a694 */ 	lw	$t0,-0x596c($t0)
/*  f0f8a54:	8cc6a698 */ 	lw	$a2,-0x5968($a2)
/*  f0f8a58:	1000000b */ 	b	.JF0f0f8a88
/*  f0f8a5c:	8ca5a69c */ 	lw	$a1,-0x5964($a1)
.JF0f0f8a60:
/*  f0f8a60:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f0f8a64:	3c05800a */ 	lui	$a1,0x800a
/*  f0f8a68:	3c06800a */ 	lui	$a2,0x800a
/*  f0f8a6c:	25f8ffea */ 	addiu	$t8,$t7,-22
/*  f0f8a70:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f0f8a74:	3c09800a */ 	lui	$t1,0x800a
/*  f0f8a78:	8d29a6a0 */ 	lw	$t1,-0x5960($t1)
/*  f0f8a7c:	8d08a694 */ 	lw	$t0,-0x596c($t0)
/*  f0f8a80:	8cc6a698 */ 	lw	$a2,-0x5968($a2)
/*  f0f8a84:	8ca5a69c */ 	lw	$a1,-0x5964($a1)
.JF0f0f8a88:
/*  f0f8a88:	10a00003 */ 	beqz	$a1,.JF0f0f8a98
/*  f0f8a8c:	24010002 */ 	li	$at,0x2
/*  f0f8a90:	10000001 */ 	b	.JF0f0f8a98
/*  f0f8a94:	240a0001 */ 	li	$t2,0x1
.JF0f0f8a98:
/*  f0f8a98:	10c00003 */ 	beqz	$a2,.JF0f0f8aa8
/*  f0f8a9c:	00003825 */ 	move	$a3,$zero
/*  f0f8aa0:	10000001 */ 	b	.JF0f0f8aa8
/*  f0f8aa4:	24070001 */ 	li	$a3,0x1
.JF0f0f8aa8:
/*  f0f8aa8:	11000003 */ 	beqz	$t0,.JF0f0f8ab8
/*  f0f8aac:	00002025 */ 	move	$a0,$zero
/*  f0f8ab0:	10000001 */ 	b	.JF0f0f8ab8
/*  f0f8ab4:	24040001 */ 	li	$a0,0x1
.JF0f0f8ab8:
/*  f0f8ab8:	11200003 */ 	beqz	$t1,.JF0f0f8ac8
/*  f0f8abc:	00001025 */ 	move	$v0,$zero
/*  f0f8ac0:	10000001 */ 	b	.JF0f0f8ac8
/*  f0f8ac4:	24020001 */ 	li	$v0,0x1
.JF0f0f8ac8:
/*  f0f8ac8:	0044c821 */ 	addu	$t9,$v0,$a0
/*  f0f8acc:	03277021 */ 	addu	$t6,$t9,$a3
/*  f0f8ad0:	01ca7821 */ 	addu	$t7,$t6,$t2
/*  f0f8ad4:	55e1002a */ 	bnel	$t7,$at,.JF0f0f8b80
/*  f0f8ad8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f0f8adc:	0fc54978 */ 	jal	optionsGetScreenSplit
/*  f0f8ae0:	00000000 */ 	nop
/*  f0f8ae4:	24080001 */ 	li	$t0,0x1
/*  f0f8ae8:	3c0d800a */ 	lui	$t5,0x800a
/*  f0f8aec:	3c1f8007 */ 	lui	$ra,0x8007
/*  f0f8af0:	27ff1998 */ 	addiu	$ra,$ra,0x1998
/*  f0f8af4:	25ade700 */ 	addiu	$t5,$t5,-6400
/*  f0f8af8:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f0f8afc:	11020005 */ 	beq	$t0,$v0,.JF0f0f8b14
/*  f0f8b00:	8fac0048 */ 	lw	$t4,0x48($sp)
/*  f0f8b04:	3c188009 */ 	lui	$t8,0x8009
/*  f0f8b08:	93181160 */ 	lbu	$t8,0x1160($t8)
/*  f0f8b0c:	5518001c */ 	bnel	$t0,$t8,.JF0f0f8b80
/*  f0f8b10:	8fbf0014 */ 	lw	$ra,0x14($sp)
.JF0f0f8b14:
/*  f0f8b14:	8ff90000 */ 	lw	$t9,0x0($ra)
/*  f0f8b18:	001970c0 */ 	sll	$t6,$t9,0x3
/*  f0f8b1c:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f8b20:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f0f8b24:	01d97021 */ 	addu	$t6,$t6,$t9
/*  f0f8b28:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f0f8b2c:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f0f8b30:	000e7100 */ 	sll	$t6,$t6,0x4
/*  f0f8b34:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f0f8b38:	91f8083b */ 	lbu	$t8,0x83b($t7)
/*  f0f8b3c:	57000006 */ 	bnezl	$t8,.JF0f0f8b58
/*  f0f8b40:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f0f8b44:	8d790000 */ 	lw	$t9,0x0($t3)
/*  f0f8b48:	272e0016 */ 	addiu	$t6,$t9,0x16
/*  f0f8b4c:	1000000b */ 	b	.JF0f0f8b7c
/*  f0f8b50:	ad6e0000 */ 	sw	$t6,0x0($t3)
/*  f0f8b54:	8d8f0000 */ 	lw	$t7,0x0($t4)
.JF0f0f8b58:
/*  f0f8b58:	25f8ffea */ 	addiu	$t8,$t7,-22
/*  f0f8b5c:	10000007 */ 	b	.JF0f0f8b7c
/*  f0f8b60:	ad980000 */ 	sw	$t8,0x0($t4)
.JF0f0f8b64:
/*  f0f8b64:	ad660000 */ 	sw	$a2,0x0($t3)
/*  f0f8b68:	8fb90044 */ 	lw	$t9,0x44($sp)
/*  f0f8b6c:	af240000 */ 	sw	$a0,0x0($t9)
/*  f0f8b70:	ad870000 */ 	sw	$a3,0x0($t4)
/*  f0f8b74:	8fae004c */ 	lw	$t6,0x4c($sp)
/*  f0f8b78:	adc50000 */ 	sw	$a1,0x0($t6)
.JF0f0f8b7c:
/*  f0f8b7c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.JF0f0f8b80:
/*  f0f8b80:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f0f8b84:	03e00008 */ 	jr	$ra
/*  f0f8b88:	00000000 */ 	nop
);
#else
/**
 * Find the maximum possible dimensions for a dialog.
 *
 * This is pretty much the player's viewport with some adjustments made for
 * padding. There are some trickier calculations for MP setup where the players
 * are sharing a viewport.
 */
void menuFindAvailableSize(s32 *leftptr, s32 *topptr, s32 *rightptr, s32 *bottomptr)
{
	s32 left = viGetViewLeft() / g_ScaleX + 20;
	s32 top = viGetViewTop() + 4;
	s32 right = (viGetViewLeft() + viGetViewWidth()) / g_ScaleX - 20;
	s32 bottom = viGetViewTop() + viGetViewHeight() - 4;
	s32 playernum;
	u32 stack[2];

	if (currentPlayerIsMenuOpenInSoloOrMp()) {
		// Make room for health bar
		top += 22;

		if (optionsGetEffectiveScreenSize() == SCREENSIZE_CINEMA) {
			top -= 8;
			bottom += 4;
		}
	}

	switch (g_MenuData.root) {
	case MENUROOT_MPSETUP:
	case MENUROOT_4MBMAINMENU:
		playernum = g_Menus[g_MpPlayerNum].playernum;

		// Make room for the "Press START" labels
		if (g_MenuData.playerjoinalpha[0] > 0 || g_MenuData.playerjoinalpha[1] > 0) {
			top += 10;
		}

		if (g_MenuData.playerjoinalpha[2] > 0 || g_MenuData.playerjoinalpha[3] > 0) {
			bottom -= 10;
		}

		switch (g_MpNumJoined) {
		case 1:
			// 1 player - the full screen is available
			*leftptr = left;
			*rightptr = right;
			*topptr = top;
			*bottomptr = bottom;
			return;
		case 2:
			// 2 players - left/right halves each
			*topptr = top;
			*bottomptr = bottom;

			if (playernum == 0) {
				*leftptr = left;
				*rightptr = (left + right) / 2;
			} else {
				*leftptr = (left + right) / 2;
				*rightptr = right;
			}
			return;
		case 3:
			// 3 players - top two quarters and the third takes the full bottom
			if (playernum == 0 || playernum == 1) {
				*topptr = top;
				*bottomptr = (top + bottom) / 2;

				if (playernum == 0) {
					*leftptr = left;
					*rightptr = (left + right) / 2;
				} else {
					*leftptr = (left + right) / 2;
					*rightptr = right;
				}
			} else {
				*topptr = (top + bottom) / 2;
				*bottomptr = bottom;
				*leftptr = left;
				*rightptr = right;
			}
			break;
		case 4:
			// 4 players - quarters
			if (playernum == 0 || playernum == 2) {
				*leftptr = left;
				*rightptr = (left + right) / 2;
			} else {
				*leftptr = (left + right) / 2;
				*rightptr = right;
			}
			if (playernum == 0 || playernum == 1) {
				*topptr = top;
				*bottomptr = (top + bottom) / 2;
			} else {
				*topptr = (top + bottom) / 2;
				*bottomptr = bottom;
			}
			break;
		}
		break;
	case MENUROOT_MPPAUSE:
	case MENUROOT_MPENDSCREEN:
	case MENUROOT_PICKTARGET:
	case MENUROOT_4MBFILEMGR:
		*leftptr = g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->viewleft / g_ScaleX;
		*topptr = g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->viewtop;
		*rightptr = (g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->viewleft + g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->viewwidth) / g_ScaleX;
		*bottomptr = g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->viewtop + g_Vars.players[g_Menus[g_MpPlayerNum].playernum]->viewheight;

		if (PLAYERCOUNT() > 2) {
			if (g_Menus[g_MpPlayerNum].playernum == 0 || g_Menus[g_MpPlayerNum].playernum == 2) {
				*leftptr += 22;
			} else {
				*rightptr -= 22;
			}
		}

#if VERSION >= VERSION_NTSC_1_0
		if (PLAYERCOUNT() == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB()))
#else
		if (PLAYERCOUNT() == 2 && optionsGetScreenSplit() == SCREENSPLIT_VERTICAL)
#endif
		{
			if (g_Menus[g_MpPlayerNum].playernum == 0) {
				*leftptr += 22;
			} else {
				*rightptr -= 22;
			}
		}
		break;
	default:
		*leftptr = left;
		*topptr = top;
		*rightptr = right;
		*bottomptr = bottom;
		break;
	}
}
#endif

void dialogCalculatePosition(struct menudialog *dialog)
{
	s32 xmin;
	s32 xmax;
	s32 ymin;
	s32 ymax;
	s32 width;
	s32 height;
	s32 vdir;
	s32 hdir;

#if VERSION >= VERSION_JPN_FINAL
	menuFindAvailableSize(&xmin, &ymin, &xmax, &ymax, dialog);
#else
	menuFindAvailableSize(&xmin, &ymin, &xmax, &ymax);
#endif

	height = ymax - ymin - 6;
	width = xmax - xmin - 6;

	if (width > dialog->contentwidth) {
		width = dialog->contentwidth;
	}

	if (height > dialog->contentheight) {
		height = dialog->contentheight;
	}

	dialog->dstx = (xmax + xmin - width) / 2;
	dialog->dsty = (ymin + ymax - height) / 2;
	dialog->dstwidth = width;
	dialog->dstheight = height;

	if (dialog->swipedir != 0) {
		func0f0f7594(dialog->swipedir, &vdir, &hdir);

		if (hdir < 0) {
			dialog->dstx = -4 - dialog->dstwidth;
		}

		if (hdir > 0) {
			dialog->dstx = (viGetViewLeft() + viGetViewWidth()) / g_ScaleX + 4;
		}

		if (vdir < 0) {
			dialog->dsty = -4 - dialog->dstheight;
		}

		if (vdir > 0) {
			dialog->dsty = viGetViewTop() + viGetViewHeight() + 4;
		}
	}
}

void menuClose(void)
{
	g_Menus[g_MpPlayerNum].depth = 0;
	g_Menus[g_MpPlayerNum].numdialogs = 0;
	g_Menus[g_MpPlayerNum].rowend = 0;
	g_Menus[g_MpPlayerNum].colend = 0;
	g_Menus[g_MpPlayerNum].blockend = 0;
	g_Menus[g_MpPlayerNum].curdialog = NULL;
	g_Menus[g_MpPlayerNum].openinhibit = 10;

	if (g_MenuData.root == MENUROOT_MPPAUSE) {
		g_PlayersWithControl[g_Menus[g_MpPlayerNum].playernum] = true;
	}

	g_MenuData.count--;

	if (g_MenuData.root == MENUROOT_MPPAUSE && g_Vars.currentplayer->activemenumode == AMMODE_EDIT) {
		g_Vars.currentplayer->activemenumode = AMMODE_VIEW;
	}

	if (g_MenuData.root == MENUROOT_BOOTPAKMGR) {
		mainChangeToStage(STAGE_TITLE);
	}
}

void func0f0f8120(void)
{
	struct menudialog *prev = g_Menus[g_MpPlayerNum].curdialog;
	s32 i;

	if (g_MenuData.unk66e > 0) {
		for (i = g_MenuData.unk66e; i >= 0; i--) {
			func0f0f3220(i);
		}
	}

	if (g_Menus[g_MpPlayerNum].curdialog == prev) {
		while (g_Menus[g_MpPlayerNum].depth > 0) {
			menuPopDialog();
		}
	}
}

void func0f0f820c(struct menudialogdef *dialogdef, s32 root)
{
	s32 i;
	s32 prevplayernum = g_MpPlayerNum;

	for (i = 0; i < 4; i++) {
		if (g_Menus[i].curdialog) {
			g_MpPlayerNum = i;
			func0f0f8120();
		}
	}

	g_MpPlayerNum = prevplayernum;

	g_MenuData.unk008 = root;
	g_MenuData.unk00c = dialogdef;
}

void menuSetBackground(s32 bg)
{
	// Can only screenshot if there is no background already,
	// because we want a clean screenshot
	bool screenshot = g_MenuData.bg == 0;

	// If there's already a screenshottable background queued,
	// there's no need to create another
	if (g_MenuData.nextbg == MENUBG_BLUR || g_MenuData.nextbg == MENUBG_CONEALPHA) {
		screenshot = false;
	}

	if (g_MenuData.bg != bg) {
		g_MenuData.nextbg = bg;
	}

	if (screenshot && g_MenuData.bg == 0) {
		g_MenuData.screenshottimer = 1;
	}
}

void func0f0f8300(void)
{
	s32 i;

	if (g_MenuData.count == 0) {
		for (i = 0; i < 4; i++) {
			g_MenuData.playerjoinalpha[i] = 0;
		}
	}
}

void menuPushRootDialog(struct menudialogdef *dialogdef, s32 root)
{
	g_Menus[g_MpPlayerNum].numdialogs = 0;
	g_Menus[g_MpPlayerNum].depth = 0;

	g_MenuData.unk5d5_01 = false;
	g_MenuData.unk5d5_04 = false;

	g_PlayersWithControl[g_Menus[g_MpPlayerNum].playernum] = false;

	func0f0f1494();

	g_MenuData.count++;

	if (root == MENUROOT_PICKTARGET) {
		g_Menus[g_MpPlayerNum].mppause.unke40_00 = true;
		root = MENUROOT_MPPAUSE;
	}

	switch (root) {
	case MENUROOT_ENDSCREEN:
	case MENUROOT_MAINMENU:
	case MENUROOT_FILEMGR:
	case MENUROOT_BOOTPAKMGR:
	case MENUROOT_PICKTARGET:
	case MENUROOT_COOPCONTINUE:
	case MENUROOT_4MBFILEMGR:
	case MENUROOT_TRAINING:
		g_MenuData.count = 1;
		break;
	}

	g_Menus[g_MpPlayerNum].unk820 = 1;

	g_MenuData.root = root;
	g_MenuData.unk008 = -1;
	g_MenuData.unk5d5_02 = false;

	if (root == MENUROOT_MAINMENU
			|| root == MENUROOT_MPSETUP
			|| root == MENUROOT_TRAINING
			|| root == MENUROOT_FILEMGR) {
		if (IS8MB() && (g_MenuData.unk5d4 == 0 || g_MenuData.unk01c.unk5b1_04)) {
			if (!g_MenuData.unk5d5_04) {
				g_MenuData.unk5d5_05 = true;
			}
		}
	}

	menuPushDialog(dialogdef);

	switch (root) {
	case MENUROOT_MPSETUP:
		menuSetBackground(MENUBG_CONEALPHA);
		break;
	case MENUROOT_4MBFILEMGR:
		musicStartMenu();
		g_MenuData.bg = MENUBG_CONEOPAQUE;
		break;
	case MENUROOT_4MBMAINMENU:
		g_MenuData.bg = MENUBG_CONEOPAQUE;
		break;
	case MENUROOT_ENDSCREEN:
		if (dialogdef->type == MENUDIALOGTYPE_DANGER) {
			g_MenuData.unk5d4 = 0;
			g_MenuData.nextbg = MENUBG_FAILURE;
			break;
		}
		// fall-through
	case MENUROOT_MAINMENU:
	case MENUROOT_MPENDSCREEN:
	case MENUROOT_FILEMGR:
	case MENUROOT_COOPCONTINUE:
	case MENUROOT_TRAINING:
		menuSetBackground(MENUBG_BLUR);
		break;
	case MENUROOT_BOOTPAKMGR:
		musicStartMenu();
		g_MenuData.bg = MENUBG_GRADIENT;
		break;
	}

	if (menuIsSoloMissionOrMp()) {
		playerDisplayHealth();
	}
}

void func0f0f85e0(struct menudialogdef *dialogdef, s32 root)
{
	if (dialogdef == &g_CiMenuViaPcMenuDialog) {
		musicStartMenu();
	}

	menuPushRootDialog(dialogdef, root);
	lvSetPaused(true);
	g_Vars.currentplayer->pausemode = PAUSEMODE_PAUSED;
}

u32 g_MenuCThresh = 120;

Gfx *menuRenderDialog(Gfx *gdl, struct menudialog *dialog, struct menu *menu, bool lightweight)
{
	mainOverrideVariable("cthresh", &g_MenuCThresh);

	textSetWaveBlend(dialog->unk54, dialog->unk58, g_MenuCThresh);

	gdl = dialogRender(gdl, dialog, menu, lightweight);

	textResetBlends();

	return gdl;
}

const char var7f1b2700[] = "[]-[] slide from %d";
const char var7f1b2714[] = " to %d\n";
const char var7f1b271c[] = "UNPAUSE: enabling control 0\n";
const char var7f1b273c[] = "file: type %d guid %x-%x data %x err %d\n";
const char var7f1b2768[] = "StartSelects\n";

/**
 * Render all dialogs for the current player.
 *
 * There's usually only one on screen at a time, but there can be multiple when
 * transitioning between dialogs. This happens when swiping left or right beteen
 * dialogs on the same layer, or when opening or closing dialogs.
 */
Gfx *menuRenderDialogs(Gfx *gdl)
{
	if (g_Menus[g_MpPlayerNum].curdialog) {
		if (g_MenuData.root == MENUROOT_MPPAUSE
				|| g_MenuData.root == MENUROOT_PICKTARGET
				|| g_MenuData.root == MENUROOT_MPENDSCREEN) {
			var8009de98 = g_Menus[g_MpPlayerNum].curdialog->x + g_Menus[g_MpPlayerNum].curdialog->width / 2 - viGetWidth() / (g_ScaleX * 2);
			var8009de9c = g_Menus[g_MpPlayerNum].curdialog->y + g_Menus[g_MpPlayerNum].curdialog->height / 2 - viGetHeight() / 2;

			gdl = menuRenderDialog(gdl, g_Menus[g_MpPlayerNum].curdialog, &g_Menus[g_MpPlayerNum], 0);
		} else {
			s32 i;
			s32 j;

#if VERSION >= VERSION_NTSC_1_0
			// NTSC 1.0 and newer renders one "other" dialog plus the current
			// dialog. The other dialog is only rendered if on-screen, and it
			// ensures the current dialog is drawn last.
			struct menudialog *dialogs[] = { NULL, NULL };

			for (i = 0; i < g_Menus[g_MpPlayerNum].depth; i++) {
				struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[i];

				for (j = 0; j < layer->numsiblings; j++) {
					if (layer->siblings[j] != g_Menus[g_MpPlayerNum].curdialog) {
						if (layer->siblings[j]->type != 0 || layer->siblings[j]->transitionfrac >= 0) {
							dialogs[0] = layer->siblings[j];
						}
					}
				}
			}

			// Render the other dialog if any
			if (dialogs[0]) {
				gdl = menuRenderDialog(gdl, dialogs[0], &g_Menus[g_MpPlayerNum], 0);
			}

			// Render the current dialog
			if (g_Menus[g_MpPlayerNum].curdialog) {
				gdl = menuRenderDialog(gdl, g_Menus[g_MpPlayerNum].curdialog, &g_Menus[g_MpPlayerNum], 0);
			}
#else
			// NTSC beta renders all dialogs all the time, and in their natural order
			for (i = 0; i < g_Menus[g_MpPlayerNum].depth; i++) {
				struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[i];

				for (j = 0; j < layer->numsiblings; j++) {
					gdl = menuRenderDialog(gdl, layer->siblings[j], &g_Menus[g_MpPlayerNum], 0);
				}
			}
#endif
		}

		// Render banner messages
		if (g_Menus[g_MpPlayerNum].bannernum != -1
				&& (g_Menus[g_MpPlayerNum].curdialog->definition->flags & MENUDIALOGFLAG_DISABLEBANNER) == 0) {
			if (g_MenuData.count >= 2) {
				s32 xmin;
				s32 ymin;
				s32 xmax;
				s32 ymax;

#if VERSION >= VERSION_JPN_FINAL
				menuFindAvailableSize(&xmin, &ymin, &xmax, &ymax, NULL);
#else
				menuFindAvailableSize(&xmin, &ymin, &xmax, &ymax);
#endif

#if VERSION >= VERSION_NTSC_1_0
				gdl = menuRenderBanner(gdl, xmin, ymin, xmax, ymax, false, g_Menus[g_MpPlayerNum].bannernum, 0, 0);
#else
				gdl = menuRenderBanner(gdl, xmin, ymin, xmax, ymax, false, g_Menus[g_MpPlayerNum].bannernum);
#endif
			} else {
				s32 xmin = viGetViewLeft() / g_ScaleX;
				s32 ymin = viGetViewTop();
				s32 xmax = (viGetViewLeft() + viGetViewWidth()) / g_ScaleX;
				s32 ymax = viGetViewTop() + viGetViewHeight();

#if VERSION >= VERSION_NTSC_1_0
				gdl = menuRenderBanner(gdl, xmin, ymin, xmax, ymax, true, g_Menus[g_MpPlayerNum].bannernum, 0, 0);
#else
				gdl = menuRenderBanner(gdl, xmin, ymin, xmax, ymax, true, g_Menus[g_MpPlayerNum].bannernum);
#endif
			}
		}
	}

	return gdl;
}

u32 var800714e8 = 0;

void func0f0f8bb4(struct menu840 *arg0, u32 arg1, u32 arg2)
{
	arg0->unk008 = arg1;
	arg0->unk004 = arg2 ? mempAlloc(arg1, MEMPOOL_STAGE) : NULL;
	arg0->unk54c = 0.0f;
	arg0->unk000 = 0;
	arg0->unk00c = 0xffff;
	arg0->bodymodeldef = NULL;
	arg0->unk010 = 0;
	arg0->unk56c = 0;
	arg0->unk570 = 0;
	arg0->partvisibility = NULL;
	arg0->unk5b1_01 = false;
	arg0->unk5b1_02 = false;
	arg0->unk5b1_04 = false;
	arg0->unk5b1_06 = false;
	arg0->headnum = -1;
	arg0->bodynum = -1;
	arg0->unk538 = 0.0f;
	arg0->unk510 = 0.0f;
	arg0->unk53c = 0.0f;
	arg0->unk514 = 0.0f;
	arg0->unk540 = 0.0f;
	arg0->unk518 = 0.0f;
	arg0->unk544 = 0.0f;
	arg0->unk51c = 0.0f;
	arg0->unk548 = 0.0f;
	arg0->unk520 = 0.0f;
	arg0->unk550 = 0.0f;
	arg0->unk528 = 0.0f;
	arg0->unk534 = 0.0f;
	arg0->unk530 = 0.0f;
	arg0->unk52c = 0.0f;
	arg0->unk524 = arg0->unk54c;
}

void menuReset(void)
{
	s32 i;

	func0f110bf0();

	var8009dfc0 = 0;

	if (IS8MB()) {
		g_BlurBuffer = mempAlloc(0x4b00, MEMPOOL_STAGE);
	}

	g_MenuData.unk5d5_01 = false;

	texLoadFromConfig(&g_TexGeneralConfigs[1]);
	texLoadFromConfig(&g_TexGeneralConfigs[6]);
	texLoadFromConfig(&g_TexGeneralConfigs[51]);
	texLoadFromConfig(&g_TexGeneralConfigs[52]);
	texLoadFromConfig(&g_TexGeneralConfigs[53]);
	texLoadFromConfig(&g_TexGeneralConfigs[54]);
	texLoadFromConfig(&g_TexGeneralConfigs[55]);

	if (g_Vars.stagenum == STAGE_CITRAINING) {
		for (i = 12; i < 34; i++) {
			texLoadFromConfig(&g_TexGeneralConfigs[i]);
		}

		texLoadFromConfig(&g_TexGeneralConfigs[34]);
		texLoadFromConfig(&g_TexGeneralConfigs[36]);
		texLoadFromConfig(&g_TexGeneralConfigs[35]);
	}

	if (g_Vars.mplayerisrunning) {
		texLoadFromConfig(&g_TexGeneralConfigs[35]);
	}

	for (i = 0; i < 4; i++) {
		g_Menus[i].unk840.unk004 = NULL;
	}

	g_MenuData.unk01c.unk004 = NULL;

	if (g_Vars.stagenum == STAGE_CITRAINING) {
		g_MissionConfig.iscoop = false;
		g_MissionConfig.isanti = false;
		g_MissionConfig.pdmode = false;
	}

	if (!g_Vars.mplayerisrunning) {
		s32 max = 0;

		if (g_Vars.stagenum == STAGE_CITRAINING) {
			max = 4;
		}

		if (g_Vars.stagenum == STAGE_4MBMENU) {
			max = 4;
		}

		for (i = 0; i < max; i++) {
			func0f0f8bb4(&g_Menus[i].unk840, IS4MB() ? 0xb400 : 0x25800, 1);
		}

		if (IS8MB()) {
			func0f0f8bb4(&g_MenuData.unk01c, 0xc800, 1);
		}

		g_MenuData.unk01c.unk00c = 0x259;
		g_MenuData.unk01c.unk524 = g_MenuData.unk01c.unk54c = -M_PI;
		g_MenuData.unk01c.unk520 = g_MenuData.unk01c.unk548 = 0;
		g_MenuData.unk01c.unk528 = g_MenuData.unk01c.unk550 = 0;
		g_MenuData.unk01c.unk510 = g_MenuData.unk01c.unk538 = -205.5f;
		g_MenuData.unk01c.unk514 = g_MenuData.unk01c.unk53c = 244.7f;
		g_MenuData.unk01c.unk518 = g_MenuData.unk01c.unk540 = 68.3f;
		g_MenuData.unk01c.unk51c = g_MenuData.unk01c.unk544 = 0.12209f;
		g_MenuData.unk01c.unk5b1_01 = false;
		g_MenuData.unk01c.unk574 = 0;
		g_MenuData.unk01c.unk580 = 0;
	}

	g_MenuData.unk5d4 = 0;
	g_MenuData.unk5d5_05 = false;

	for (i = 0; i < 4; i++) {
		g_Menus[i].curdialog = NULL;
		g_Menus[i].depth = 0;
		g_Menus[i].numdialogs = 0;
		g_Menus[i].unk820 = 0;
		g_Menus[i].rowend = 0;
		g_Menus[i].blockend = 0;
		g_Menus[i].colend = 0;
		g_Menus[i].bannernum = -1;
		g_Menus[i].fm.unke41 = 0;
		g_Menus[i].fm.unke64 = 0;
		g_Menus[i].fm.headtextures = NULL;
	}

	g_MenuData.unk668 = -1;
	g_MenuData.unk00c = 0;
	g_MenuData.unk008 = -1;
	g_MenuData.count = 0;
	g_MenuData.root = 0;
	g_MenuData.unk010 = 0;
	g_MenuData.bg = 0;
	g_MenuData.unk5d5_06 = false;
	g_MenuData.nextbg = 255;
	g_MenuData.bannernum = -1;

	for (i = 0; i < 5; i++) {
		g_MenuData.unk669[i] = 0xff;
	}

	g_MenuData.unk66e = 0;
	g_MenuData.unk66f = 0;
}

void menuSwipe(s32 direction)
{
	struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth - 1];
	struct menuitem *item;
	union handlerdata sp50;
	union handlerdata sp40;

	if (layer->numsiblings >= 2) {
		g_Menus[g_MpPlayerNum].curdialog->swipedir = -direction;

		layer->cursibling += (s8)direction;

		if (layer->cursibling < 0) {
			layer->cursibling = layer->numsiblings - 1;
		}

		if (layer->cursibling >= layer->numsiblings) {
			layer->cursibling = 0;
		}

		g_Menus[g_MpPlayerNum].curdialog = layer->siblings[layer->cursibling];

		if (direction == 1) {
			g_Menus[g_MpPlayerNum].curdialog->focuseditem = dialogFindFirstItem(g_Menus[g_MpPlayerNum].curdialog);
		} else {
			g_Menus[g_MpPlayerNum].curdialog->focuseditem = dialogFindFirstItemRight(g_Menus[g_MpPlayerNum].curdialog);
		}

		item = g_Menus[g_MpPlayerNum].curdialog->definition->items;

		while (item->type != MENUITEMTYPE_END) {
			if (item->handler
					&& (item->flags & MENUITEMFLAG_SELECTABLE_OPENSDIALOG) == 0
					&& item->handler(MENUOP_CHECKPREFOCUSED, item, &sp50)) {
				g_Menus[g_MpPlayerNum].curdialog->focuseditem = item;
			}

			item++;
		}

		if (g_Menus[g_MpPlayerNum].curdialog->focuseditem != 0
				&& g_Menus[g_MpPlayerNum].curdialog->focuseditem->handler
				&& ((g_Menus[g_MpPlayerNum].curdialog->focuseditem->flags & MENUITEMFLAG_SELECTABLE_OPENSDIALOG) == 0)) {
			g_Menus[g_MpPlayerNum].curdialog->focuseditem->handler(MENUOP_FOCUS, g_Menus[g_MpPlayerNum].curdialog->focuseditem, &sp40);
		}

		g_Menus[g_MpPlayerNum].curdialog->swipedir = direction;

		dialogCalculatePosition(g_Menus[g_MpPlayerNum].curdialog);

		g_Menus[g_MpPlayerNum].curdialog->x = g_Menus[g_MpPlayerNum].curdialog->dstx;
		g_Menus[g_MpPlayerNum].curdialog->y = g_Menus[g_MpPlayerNum].curdialog->dsty;
		g_Menus[g_MpPlayerNum].curdialog->swipedir = 0;
		g_Menus[g_MpPlayerNum].curdialog->state = MENUDIALOGSTATE_PREOPEN;
		g_Menus[g_MpPlayerNum].curdialog->statefrac = 0.0f;

		func0f0f37a4(&g_Menus[g_MpPlayerNum].unk840);

		menuPlaySound(MENUSOUND_SWIPE);
	}
}

extern struct menudialogdef g_MpDropOut4MbMenuDialog;

void dialogTick(struct menudialog *dialog, struct menuinputs *inputs, u32 tickflags)
{
	bool usedefaultbehaviour;
	struct menudialogdef *definition;
	struct menu *menu;
	u8 transitiontotype;
	s32 oldfracint;
	s32 oldx;
	s32 col;
	f32 newx;
	union handlerdata data;
	struct menuinputs spd8;
	s32 oldy;
	f32 newy;
	s32 oldwidth;
	f32 newwidth;
	s32 oldheight;
	f32 newheight;
	s32 i;
	u32 stack;

	usedefaultbehaviour = false;
	definition = dialog->definition;
	menu = &g_Menus[g_MpPlayerNum];

	if (g_Menus[g_MpPlayerNum].fm.unke40_00 || g_MainIsDebugMenuOpen) {
		inputs->leftright = inputs->updown = inputs->select = inputs->back = inputs->xaxis = inputs->yaxis = inputs->shoulder = inputs->back2 = inputs->unk14 = 0;
		g_Menus[g_MpPlayerNum].fm.unke40_00 = false;
	}

	g_Menus[g_MpPlayerNum].fm.unke40_00 = false;

	spd8.select = 0;
	spd8.back = inputs->back;
	spd8.leftright = inputs->leftright;
	spd8.updown = inputs->updown;
	spd8.xaxis = inputs->xaxis;
	spd8.yaxis = inputs->yaxis;
	spd8.leftrightheld = inputs->leftrightheld;
	spd8.updownheld = inputs->updownheld;
	spd8.start = 0;
	spd8.unk0c = inputs->unk0c;
	spd8.unk10 = inputs->unk10;

	dialog->unk54++;
	dialog->unk5c += g_Vars.diffframe60;
	dialog->unk54 += dialog->unk5c / 9;
	dialog->unk5c %= 9;
	dialog->unk54 %= g_MenuCThresh;

	// For endscreens, handle transitioning of background and dialog type
	if (dialog->transitionfrac < 0.0f) {
		// Transition not yet started
		if (dialog == g_Menus[g_MpPlayerNum].curdialog) {
			transitiontotype = definition->type;

			if (mpIsPlayerLockedOut(g_MpPlayerNum) && (dialog->definition->flags & MENUDIALOGFLAG_MPLOCKABLE)) {
				transitiontotype = MENUDIALOGTYPE_DANGER;
			}

			if (g_MenuData.root == MENUROOT_ENDSCREEN) {
				if (g_MenuData.bg == MENUBG_8 || g_MenuData.bg == MENUBG_SUCCESS) {
					transitiontotype = MENUDIALOGTYPE_DEFAULT;
				}

				if (g_StageIndex == STAGEINDEX_DEFENSE
						&& g_MenuData.bg != MENUBG_FAILURE
						&& g_MenuData.nextbg != MENUBG_FAILURE) {
					transitiontotype = MENUDIALOGTYPE_WHITE;
					dialog->type = MENUDIALOGTYPE_WHITE;
				}
			}

			if (dialog->type != transitiontotype) {
				dialog->type2 = transitiontotype;
				dialog->colourweight = 0;
				dialog->transitionfrac = 0;
			}
		} else if (dialog->type != 0) {
			dialog->type2 = 0;
			dialog->colourweight = 0;
			dialog->transitionfrac = 0;
		}
	} else {
		// Mid-transition
		if (g_MenuData.root == MENUROOT_ENDSCREEN
				&& g_StageIndex == STAGEINDEX_DEFENSE
				&& g_MenuData.bg != MENUBG_FAILURE
				&& g_MenuData.nextbg != MENUBG_FAILURE
				&& dialog->type2 != 0) {
			dialog->type2 = MENUDIALOGTYPE_WHITE;
		}

		// Success endscreens transition to the background slower than failures
		if (g_MenuData.root == MENUROOT_ENDSCREEN
				&& dialog->type == MENUDIALOGTYPE_SUCCESS
				&& (g_MenuData.bg == MENUBG_8 || g_MenuData.bg == MENUBG_SUCCESS)) {
#if VERSION >= VERSION_PAL_BETA
			dialog->transitionfrac += g_Vars.diffframe60freal * 0.01f;
#else
			dialog->transitionfrac += g_Vars.diffframe60f * 0.01f;
#endif
		} else {
#if VERSION >= VERSION_PAL_BETA
			dialog->transitionfrac += g_Vars.diffframe60freal * 0.042f;
#else
			dialog->transitionfrac += g_Vars.diffframe60f * 0.042f;
#endif
		}

		if (dialog->transitionfrac > 1.0f) {
			dialog->transitionfrac = -1.0f;
			dialog->type = dialog->type2;
		}

		dialog->colourweight = dialog->transitionfrac * 255.0f;
	}

	// When fully open and ready, the dialog shows the text fully opaque for
	// 2 seconds (redrawtimer < 0.0f) then starts the redraw timer and waits for
	// it to finish before repeating the process. While the redraw timer is
	// active, the text begins to fade before being redrawn.
	if (dialog->state == MENUDIALOGSTATE_POPULATED) {
		if (g_MenuData.nextbg != MENUBG_CONEALPHA) {
			if (dialog->redrawtimer < 0.0f) {
#if VERSION >= VERSION_PAL_BETA
				dialog->statefrac += g_Vars.diffframe60freal / 120.0f;
#else
				dialog->statefrac += g_Vars.diffframe60f / 120.0f;
#endif

				if (dialog->statefrac > 1.0f) {
					dialog->redrawtimer = 0.0f;
				}
			} else {
				dialog->statefrac = 0.0f;
			}
		}
	}

	// When populating the text for the first time, wait for both the redraw
	// timer to finish and a minimum duration.
	if (dialog->state == MENUDIALOGSTATE_POPULATING) {
#if VERSION >= VERSION_PAL_BETA
		dialog->statefrac -= 0.05f * g_Vars.diffframe60freal;
#else
		dialog->statefrac -= 0.05f * g_Vars.diffframe60f;
#endif

		if (dialog->statefrac < 0.0f) {
			dialog->statefrac = 0.0f;

			if (dialog->redrawtimer < 0.0f) {
				dialog->state = MENUDIALOGSTATE_POPULATED;
			}
		}
	}

	// When opening the dialog, the height increases gradually over several
	// frames. This part doesn't actually change the height - it updates the
	// statefrac based on the current height.
	if (dialog->state == MENUDIALOGSTATE_OPENING) {
		oldfracint = dialog->statefrac;

		if (dialog->statefrac != dialog->height) {
			for (i = 0; i < g_Vars.diffframe60; i++) {
#if PAL
				dialog->statefrac = dialog->height * 0.235f + 0.765f * dialog->statefrac;
#else
				dialog->statefrac = dialog->height * 0.2f + 0.8f * dialog->statefrac;
#endif
			}
		}

		if ((s32)dialog->statefrac == oldfracint) {
			dialog->statefrac = oldfracint + 1.0f;
		}

		if (dialog->statefrac > dialog->height - 1.0f && dialog->statefrac < dialog->height + 1.0f) {
			dialog->state = MENUDIALOGSTATE_POPULATING;
			dialog->statefrac = 1.0f;
		}
	}

#if VERSION >= VERSION_NTSC_1_0
	if (dialog->state == MENUDIALOGSTATE_PREOPEN) {
		if (dialog->definition == &g_MpReadyMenuDialog) {
			if (dialog->statefrac < 0.1f) {
				dialog->statefrac += 0.04f;
			} else {
				dialog->state = MENUDIALOGSTATE_OPENING;
				dialog->redrawtimer = 0.0f;
				dialog->statefrac = 0.5f;
			}
		} else if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0) && menuGetRoot() == MENUROOT_MPENDSCREEN) {
			if (var8009dfc0) {
#if VERSION >= VERSION_PAL_BETA
				dialog->statefrac += g_Vars.diffframe240freal / 60.0f;
#else
				dialog->statefrac += g_Vars.diffframe240 / 60.0f;
#endif

				if (dialog->statefrac > 1.0f) {
					dialog->state = MENUDIALOGSTATE_OPENING;
					dialog->redrawtimer = 0.0f;
					dialog->statefrac = 0.5f;
				}
			}
		} else {
			if (g_MenuData.nextbg == 255 || g_MenuData.bg != 0) {
				dialog->state = MENUDIALOGSTATE_OPENING;
				dialog->redrawtimer = 0.0f;
				dialog->statefrac = 0.5f;
			}
		}
	}
#else
	if (dialog->state == MENUDIALOGSTATE_PREOPEN) {
		if (g_MenuData.nextbg == 255 || g_MenuData.bg != 0) {
			dialog->state = MENUDIALOGSTATE_OPENING;
			dialog->redrawtimer = 0.0f;
			dialog->statefrac = 0.5f;
		}
	}
#endif

	// Increment the redraw timer, which makes the contents fade and then get
	// redrawn. The initial draw is done faster than subsequent draws.
	if (dialog->redrawtimer < 0.0f) {
		// Redraw not active
	} else {
#if VERSION >= VERSION_PAL_BETA
		if (dialog->state == MENUDIALOGSTATE_POPULATED) {
			dialog->redrawtimer += g_Vars.diffframe60freal + g_Vars.diffframe60freal;
		} else {
			dialog->redrawtimer += 5 * g_Vars.diffframe60freal;
		}
#else
		if (dialog->state == MENUDIALOGSTATE_POPULATED) {
			dialog->redrawtimer += 2 * g_Vars.diffframe60;
		} else {
			dialog->redrawtimer += 5 * g_Vars.diffframe60;
		}
#endif

		if (dialog->redrawtimer > 600.0f) {
			dialog->redrawtimer = -1.0f;
		}
	}

	if ((dialog->definition->flags & MENUDIALOGFLAG_DISABLERESIZE) == 0) {
		dialogCalculateContentSize(dialog->definition, dialog, menu);
	}

	dialogCalculatePosition(dialog);
	dialog0f0f1ef4(dialog);

	// Update slide
	if (g_MenuData.root == MENUROOT_MPPAUSE
			|| g_MenuData.root == MENUROOT_PICKTARGET
			|| g_MenuData.root == MENUROOT_MPENDSCREEN) {
		// Don't slide
		dialog->x = dialog->dstx;
		dialog->y = dialog->dsty;
	} else {
		// Slide X
		if (dialog->x != dialog->dstx) {
			oldx = dialog->x;
			newx = dialog->x;

			for (i = 0; i < g_Vars.diffframe60; i++) {
#if PAL
				newx = dialog->dstx * 0.348f + 0.652f * newx;
#else
				newx = dialog->dstx * 0.3f + 0.7f * newx;
#endif
			}

			dialog->x = newx;

			if (dialog->x != dialog->dstx && dialog->x == oldx) {
				if (dialog->x < dialog->dstx) {
					dialog->x++;
				} else {
					dialog->x--;
				}
			}
		}

		// Slide Y
		if (dialog->y != dialog->dsty) {
			oldy = dialog->y;
			newy = dialog->y;

			for (i = 0; i < g_Vars.diffframe60; i++) {
#if PAL
				newy = dialog->dsty * 0.348f + 0.652f * newy;
#else
				newy = dialog->dsty * 0.3f + 0.7f * newy;
#endif
			}

			dialog->y = newy;

			if (dialog->y != dialog->dsty && dialog->y == oldy) {
				if (dialog->y < dialog->dsty) {
					dialog->y++;
				} else {
					dialog->y--;
				}
			}
		}
	}

	// Tween the width
	if (dialog->width != dialog->dstwidth) {
		oldwidth = dialog->width;
		newwidth = dialog->width;

		for (i = 0; i < g_Vars.diffframe60; i++) {
#if PAL
			newwidth = dialog->dstwidth * 0.348f + 0.652f * newwidth;
#else
			newwidth = dialog->dstwidth * 0.3f + 0.7f * newwidth;
#endif
		}

		dialog->width = newwidth;

		if (dialog->width != dialog->dstwidth && dialog->width == oldwidth) {
			if (dialog->width < dialog->dstwidth) {
				dialog->width++;
			} else {
				dialog->width--;
			}
		}
	}

	// Tween the height
	if (dialog->height != dialog->dstheight) {
		s32 i;
		oldheight = dialog->height;
		newheight = dialog->height;

		for (i = 0; i < g_Vars.diffframe60; i++) {
#if PAL
			newheight = dialog->dstheight * 0.348f + 0.652f * newheight;
#else
			newheight = dialog->dstheight * 0.3f + 0.7f * newheight;
#endif
		}

		dialog->height = newheight;

		if (dialog->height != dialog->dstheight && dialog->height == oldheight) {
			if (dialog->height < dialog->dstheight) {
				dialog->height++;
			} else {
				dialog->height--;
			}
		}
	}

	// Call the dialog's tick handler, if any
	data.dialog2.inputs = inputs;

	if (definition->handler != NULL) {
		definition->handler(MENUOP_TICK, definition, &data);
	}

	if (dialog->dimmed) {
		dialog->unk10 += g_Vars.diffframe60;
	} else {
		dialog->unk10 = 0;
	}

	// Tick each item in the dialog
	{
		s32 j;

		for (col = 0; col < dialog->numcols; col++) {
			s32 colindex = dialog->colstart + col;

			for (j = 0; j < menu->cols[colindex].numrows; j++) {
				s32 rowindex = menu->cols[colindex].rowstart + j;
				struct menuitem *item = &dialog->definition->items[menu->rows[rowindex].itemindex];
				union menuitemdata *handlerdata = NULL;
				struct menuinputs *inputsptr = inputs;

				if (mpIsPlayerLockedOut(g_MpPlayerNum) && (item->flags & MENUITEMFLAG_LOCKABLEMINOR)) {
					inputsptr = &spd8;
				} else if ((item->flags & MENUITEMFLAG_MPWEAPONSLOT) && mpGetWeaponSet() != func0f189088()) {
					inputsptr = &spd8;
				} else if (g_MenuData.root == MENUROOT_12) {
					inputsptr = &spd8;
				}

				if (inputsptr);

				if (menu->rows[rowindex].blockindex != -1) {
					handlerdata = (union menuitemdata *)&menu->blocks[menu->rows[rowindex].blockindex];
				}

				if (g_Menus[g_MpPlayerNum].fm.unke40_00 == 0 && !g_MainIsDebugMenuOpen) {
					if ((tickflags & MENUTICKFLAG_DIALOGISCURRENT) && item == dialog->focuseditem) {
						u32 itemtickflags = tickflags | MENUTICKFLAG_ITEMISFOCUSED;

						if (dialog->dimmed) {
							usedefaultbehaviour = menuitemTick(item, dialog, inputsptr, itemtickflags | MENUTICKFLAG_DIALOGISDIMMED, handlerdata);
						} else {
							usedefaultbehaviour = menuitemTick(item, dialog, inputsptr, itemtickflags, handlerdata);
						}
					} else {
						menuitemTick(item, dialog, inputsptr, tickflags, handlerdata);
					}
				}
			}
		}
	}

	// If the focused item is disabled somehow, automatically jump to the next
	if (dialog->focuseditem
			&& menuIsItemDisabled(dialog->focuseditem, dialog)
			&& (tickflags & MENUTICKFLAG_DIALOGISCURRENT)) {
		usedefaultbehaviour = true;
		inputs->updown = 1;
		dialog->dimmed = false;
	}

	// Apply default navigational behaviour if requested
	if (usedefaultbehaviour && (tickflags & MENUTICKFLAG_DIALOGISCURRENT) && !dialog->dimmed) {
		struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[g_Menus[g_MpPlayerNum].depth - 1];

		if (layer->numsiblings <= 1) {
			struct menuitem *prevfocuseditem = dialog->focuseditem;

			dialogChangeItemFocus(dialog, inputs->leftright, inputs->updown);

			if (dialog->focuseditem != prevfocuseditem) {
				menuPlaySound(MENUSOUND_FOCUS);
			}
		} else {
			struct menuitem *prevfocuseditem = dialog->focuseditem;
			s32 swipedir = dialogChangeItemFocus(dialog, inputs->leftright, inputs->updown);

			if (swipedir != 0) {
				menuSwipe(swipedir);
			} else if (prevfocuseditem != dialog->focuseditem) {
				menuPlaySound(MENUSOUND_FOCUS);
			}
		}

		if (inputs->back) {
			if ((dialog->definition->flags & MENUDIALOGFLAG_DROPOUTONCLOSE) && g_Vars.unk000498) {
				if (IS4MB()) {
					menuPushDialog(&g_MpDropOut4MbMenuDialog);
				} else {
					menuPushDialog(&g_MpDropOutMenuDialog);
				}
			} else if ((dialog->definition->flags & MENUDIALOGFLAG_IGNOREBACK) == 0) {
				menuPopDialog();
			}
		} else if (dialog->definition->flags & MENUDIALOGFLAG_CLOSEONSELECT) {
			if (dialog->state > MENUDIALOGSTATE_PREOPEN) {
				if ((inputs->select & 1) == 1 || (inputs->back & 1) == 1) {
					menuPopDialog();
				}
			}
		}
	}

	// Scrolling related (when the dialog is too big vertically)
	if (dialog->focuseditem && (dialog->definition->flags & MENUDIALOGFLAG_DISABLEITEMSCROLL) == 0) {
#if VERSION >= VERSION_NTSC_1_0
		s32 dstscroll;
		s32 itemy;
		s32 rowindex;
		s32 colindex;
#else
		s32 dstscroll;
		s32 rowindex;
		s32 colindex;
		s32 itemy;
#endif

		s32 y = dialogFindItem(dialog, dialog->focuseditem, &rowindex, &colindex);

		if ((dialog->focuseditem->flags & MENUITEMFLAG_00010000) == 0) {
			itemy = y + menu->rows[rowindex].height / 2;
			dstscroll = (dialog->height - LINEHEIGHT - 1) / 2 - itemy;

			if (dstscroll > 0) {
				dstscroll = 0;
			}

			if (dstscroll < dialog->height - dialog->contentheight) {
				dstscroll = dialog->height - dialog->contentheight;
			}

			dialog->dstscroll = dstscroll;
		} else {
			dialog->dstscroll = 0;
		}
	} else if (dialog->definition->flags & MENUDIALOGFLAG_SMOOTHSCROLLABLE) {
#if VERSION >= VERSION_PAL_BETA
		s32 adjustment = (s32)(inputs->yaxis * g_Vars.diffframe60freal / 20) - (s32)(inputs->updownheld * g_Vars.diffframe60freal);
#else
		s32 adjustment = inputs->yaxis * g_Vars.diffframe60 / 20 - inputs->updownheld * g_Vars.diffframe60;
#endif
		dialog->dstscroll += adjustment;

		if (dialog->dstscroll > 0) {
			dialog->dstscroll = 0;
		}

		if (dialog->dstscroll < dialog->height - dialog->contentheight) {
			dialog->dstscroll = dialog->height - dialog->contentheight;
		}

		dialog->scroll = dialog->dstscroll;
	}

	{
		if (dialog->scroll != dialog->dstscroll) {
			s32 oldscroll = dialog->scroll;
			f32 newscroll = dialog->scroll;
			s32 i;

			for (i = 0; i < g_Vars.diffframe60; i++) {
#if PAL
				newscroll = (dialog->dstscroll * 0.235f) + (0.765f * newscroll);
#else
				newscroll = (dialog->dstscroll * 0.2f) + (0.8f * newscroll);
#endif
			}

			dialog->scroll = newscroll;

			if (dialog->scroll != dialog->dstscroll && dialog->scroll == oldscroll) {
				if (dialog->scroll < dialog->dstscroll) {
					dialog->scroll++;
				} else {
					dialog->scroll--;
				}
			}
		}
	}

	if (g_Menus[g_MpPlayerNum].fm.unke40_00 || g_MainIsDebugMenuOpen) {
		inputs->leftright = inputs->updown = inputs->select = inputs->back = inputs->xaxis = inputs->yaxis = inputs->shoulder = inputs->back2 = inputs->unk14 = 0;
		g_Menus[g_MpPlayerNum].fm.unke40_00 = false;
	}
}

void dialogInitItems(struct menudialog *dialog)
{
	struct menu *menu = &g_Menus[g_MpPlayerNum];
	s32 i;
	s32 j;

	for (i = 0; i < dialog->numcols; i++) {
		s32 colindex = dialog->colstart + i;

		for (j = 0; j < menu->cols[colindex].numrows; j++) {
			s32 rowindex = menu->cols[colindex].rowstart + j;
			struct menuitem *item = &dialog->definition->items[menu->rows[rowindex].itemindex];
			union menuitemdata *data = NULL;

			if (menu->rows[rowindex].blockindex != -1) {
				data = (union menuitemdata *)&menu->blocks[menu->rows[rowindex].blockindex];
			}

			menuitemInit(item, data);
		}
	}
}

void func0f0fa6ac(void)
{
	switch (g_MenuData.root) {
	case MENUROOT_MAINMENU:
	case MENUROOT_MPSETUP:
	case MENUROOT_FILEMGR:
	case MENUROOT_4MBMAINMENU:
	case MENUROOT_TRAINING:
		playerUnpause();
		g_PlayersWithControl[0] = true;
	}
}

void menuProcessInput(void)
{
	s32 yhelddir;
	s32 xhelddir;
	s32 ytapdir;
	s32 xtapdir;
	bool starttoselect;
	struct menuinputs inputs;
	struct menudialog *dialog;
	struct menu *menu;
	bool starttap;
	s32 stickx;
	s32 sticky;
	s32 numcontpads;
	s32 i;
	s32 contpadnums[4];
	s8 contpadnum1;
	s8 contpadnum2;
	struct fileguid guid;
	s32 xdeadzone;
	s32 ydeadzone;
	s32 digitalrepeatinterval;
	s32 xstickintervalmult;
	s32 stickintervalbase;
	s32 ystickintervalmult;
	s32 allowdiagonal;

	yhelddir = 0;
	xhelddir = 0;
	ytapdir = 0;
	xtapdir = 0;
	starttoselect = false;

	menu = &g_Menus[g_MpPlayerNum];
	dialog = g_Menus[g_MpPlayerNum].curdialog;

	if (g_MenuData.root == MENUROOT_MPPAUSE) {
		g_AmIndex = g_Vars.currentplayernum;
	}

	func0f0f1418();

	inputs.select = 0;
	inputs.back = 0;
	inputs.shoulder = 0;
	inputs.back2 = 0;

	if (g_Menus[g_MpPlayerNum].curdialog) {
		stickx = 0;
		sticky = 0;
		starttap = false;
		numcontpads = 0;

		// Decide which controller pads will control this player's menu
		if (g_MenuData.root == MENUROOT_BOOTPAKMGR) {
			contpadnums[0] = 0;
			contpadnums[1] = 1;
			contpadnums[2] = 2;
			contpadnums[3] = 3;
			numcontpads = 4;
		} else {
			menuGetContPads(&contpadnum1, &contpadnum2);

			if (contpadnum1 >= 0) {
				contpadnums[numcontpads] = contpadnum1;
				numcontpads++;
			}

			if (contpadnum2 >= 0) {
				contpadnums[numcontpads] = contpadnum2;
				numcontpads++;
			}
		}

		// Handle some kind of file save/load timer
		if (g_Menus[g_MpPlayerNum].fm.unke41 > 0) {
			g_Menus[g_MpPlayerNum].fm.unke41--;

			if (g_Menus[g_MpPlayerNum].fm.unke41 == 0) {
				guid.fileid = g_Menus[g_MpPlayerNum].fm.fileid;
				guid.deviceserial = g_Menus[g_MpPlayerNum].fm.deviceserial;

				filemgrSaveOrLoad(&guid, -1, 0);
			} else {
				g_Menus[g_MpPlayerNum].fm.unke40_00 = true;
			}
		}

		// Iterate controllers and figure out which buttons are being pressed.
		// For the control stick input, take whichever stick is pressed the most.
		for (i = 0; i < numcontpads; i++) {
			s8 thisstickx = joyGetStickX(contpadnums[i]);
			s8 thissticky = joyGetStickY(contpadnums[i]);
			u16 buttons = joyGetButtons(contpadnums[i], 0xffff);
			u16 buttonsnow = joyGetButtonsPressedThisFrame(contpadnums[i], 0xffff);

			if (buttonsnow & A_BUTTON) {
				inputs.select = 1;
			}

			if (buttonsnow & B_BUTTON) {
				inputs.back = 1;
			}

			if (buttonsnow & Z_TRIG) {
				inputs.select = 1;
			}

			if (buttonsnow & START_BUTTON) {
				starttap = true;
			}

			if (buttons & R_TRIG) {
				inputs.shoulder = 1;
			}

			if (buttons & L_TRIG) {
				inputs.shoulder = 1;
			}

			if ((stickx < 0 ? -stickx : stickx) < (thisstickx < 0 ? -thisstickx : thisstickx)) {
				stickx = thisstickx;
			}

			if ((sticky < 0 ? -sticky : sticky) < (thissticky < 0 ? -thissticky : thissticky)) {
				sticky = thissticky;
			}

			if (buttons & U_CBUTTONS) {
				yhelddir = -1;
			}

			if (buttonsnow & U_CBUTTONS) {
				ytapdir = -1;
			}

			if (buttons & D_CBUTTONS) {
				yhelddir = 1;
			}

			if (buttonsnow & D_CBUTTONS) {
				ytapdir = 1;
			}

			if (buttons & L_CBUTTONS) {
				xhelddir = -1;
			}

			if (buttonsnow & L_CBUTTONS) {
				xtapdir = -1;
			}

			if (buttons & R_CBUTTONS) {
				xhelddir = 1;
			}

			if (buttonsnow & R_CBUTTONS) {
				xtapdir = 1;
			}

			if (buttons & U_JPAD) {
				yhelddir = -1;
			}

			if (buttonsnow & U_JPAD) {
				ytapdir = -1;
			}

			if (buttons & D_JPAD) {
				yhelddir = 1;
			}

			if (buttonsnow & D_JPAD) {
				ytapdir = 1;
			}

			if (buttons & L_JPAD) {
				xhelddir = -1;
			}

			if (buttonsnow & L_JPAD) {
				xtapdir = -1;
			}

			if (buttons & R_JPAD) {
				xhelddir = 1;
			}

			if (buttonsnow & R_JPAD) {
				xtapdir = 1;
			}
		}

		// Prevent select and going back on the same frame
		if (inputs.select) {
			inputs.back = 0;
		}

		if (ytapdir != 0) {
			yhelddir = ytapdir;
		}

		if (xtapdir != 0) {
			xhelddir = xtapdir;
		}

		// Choose repeat rate settings
		digitalrepeatinterval = TICKS(10);
		xdeadzone = 30;
		ydeadzone = 20;
		stickintervalbase = 60;
		xstickintervalmult = 33;
		ystickintervalmult = 44;
		allowdiagonal = false;

		if (g_Menus[g_MpPlayerNum].curdialog) {
			struct menuitem *item = g_Menus[g_MpPlayerNum].curdialog->focuseditem;

			if (item) {
				if (item->type == MENUITEMTYPE_SLIDER || item->type == MENUITEMTYPE_10) {
					if (g_Menus[g_MpPlayerNum].curdialog->dimmed) {
						digitalrepeatinterval = TICKS(5);
						xdeadzone = 20;
						stickintervalbase = 30;
						xstickintervalmult = 10;
					}
				}

				if (item->type == MENUITEMTYPE_KEYBOARD) {
					allowdiagonal = true;
					digitalrepeatinterval = TICKS(5);
					xdeadzone = 20;
					xstickintervalmult = 10;
					ystickintervalmult = 10;
				}
			}
		}

		// Handle left/right repeat
		{
			s32 absstickx;
			s32 abssticky;
			s32 oldslot;
			s32 newslot;
			s32 interval;
			bool apply = false;

			// This check doesn't exist in the up/down code later on...
			// It's likely unnecessary
			if (xhelddir == 0) {
				menu->xrepeatmode = MENUREPEATMODE_RELEASED;
			}

			if (xtapdir != 0) {
				// Direction was pressed this frame - reset the repeat properties
				menu->xrepeatmode = MENUREPEATMODE_SLOW;
				menu->xrepeattimer60 = 0;
				menu->xrepeatdir = xtapdir;
				apply = true;
			} else if (xhelddir != 0) {
				xhelddir = menu->xrepeatdir;
			}

			// If held for 1 second, repeat faster
			if (menu->xrepeattimer60 > TICKS(60)) {
				menu->xrepeatmode = MENUREPEATMODE_FAST;
			}

			// Calculate the old and new repeat slots.
			// If these are different, the repeat will be applied on this tick.
			oldslot = menu->xrepeattimer60 / digitalrepeatinterval;
			newslot = (menu->xrepeattimer60 + g_Vars.diffframe60) / digitalrepeatinterval;

			if (menu->xrepeatmode == MENUREPEATMODE_SLOW) {
				oldslot /= 2;
				newslot /= 2;
			}

			inputs.leftrightheld = xhelddir;

			// Check if the stick is being pushed left or right
			absstickx = stickx < 0 ? -stickx : stickx;
			abssticky = sticky < 0 ? -sticky : sticky;

			if (absstickx >= xdeadzone && (absstickx > abssticky || allowdiagonal)) {
				// Reset the repeat if it's a different direction
				if (stickx < 0 && menu->xrepeatcount > 0) {
					menu->xrepeatcount = 0;
				}

				if (stickx > 0 && menu->xrepeatcount < 0) {
					menu->xrepeatcount = 0;
				}

				if (menu->xrepeatcount == 0) {
					menu->xrepeattimer60 = 0;
				}

				// Calculate the repeat interval based on the stick pressure
				if (absstickx > 70) {
					absstickx = 70;
				}

				absstickx -= xdeadzone;
				interval = stickintervalbase - xstickintervalmult * absstickx / (70 - xdeadzone);

				// After 3 repeats, halve the interval (ie. make faster)
				if (menu->xrepeatcount >= 3 || menu->xrepeatcount <= -3) {
					interval /= 2;
				}

				if (interval > 0) {
#if VERSION >= VERSION_PAL_BETA
					if (interval > 3) {
						interval = TICKS(interval);
					}
#endif

					oldslot = menu->xrepeattimer60 / interval;
					newslot = (menu->xrepeattimer60 + g_Vars.diffframe60) / interval;

					xhelddir = stickx < 0 ? -1 : 1;

					if (oldslot != newslot) {
						apply = true;
					}

					if (menu->xrepeatcount == 0) {
						apply = true;
					}

					if (apply) {
						menu->xrepeatcount += xhelddir;
					}
				}
			} else {
				menu->xrepeatcount = 0;
			}

			if (oldslot != newslot) {
				apply = true;
			}

			if (!apply) {
				xhelddir = 0;
			}
		}

		// Handle up/down repeat
		{
			s32 absstickx;
			s32 abssticky;
			s32 oldslot;
			s32 newslot;
			s32 interval;
			bool apply = false;

			if (ytapdir != 0) {
				// Direction was pressed this frame - reset the repeat properties
				apply = true;
				menu->yrepeatmode = MENUREPEATMODE_SLOW;
				menu->yrepeattimer60 = 0;
				menu->yrepeatdir = ytapdir;
			} else if (yhelddir != 0) {
				yhelddir = menu->yrepeatdir;
			}

			// If held for 1 second, repeat faster
			if (menu->yrepeattimer60 > TICKS(60)) {
				menu->yrepeatmode = MENUREPEATMODE_FAST;
			}

			// Calculate the old and new repeat slots.
			// If these are different, the repeat will be applied on this tick.
			oldslot = menu->yrepeattimer60 / digitalrepeatinterval;
			newslot = (menu->yrepeattimer60 + g_Vars.diffframe60) / digitalrepeatinterval;

			if (menu->yrepeatmode == MENUREPEATMODE_SLOW) {
				oldslot /= 2;
				newslot /= 2;
			}

			inputs.updownheld = yhelddir;

			// Check if the stick is being pushed up or down
			abssticky = sticky < 0 ? -sticky : sticky;
			absstickx = stickx < 0 ? -stickx : stickx;

			if (abssticky >= ydeadzone && (abssticky > absstickx || allowdiagonal)) {
				// Reset the repeat if it's a different direction
				if (sticky < 0 && menu->yrepeatcount < 0) {
					menu->yrepeatcount = 0;
				}

				if (sticky > 0 && menu->yrepeatcount > 0) {
					menu->yrepeatcount = 0;
				}

				if (menu->yrepeatcount == 0) {
					menu->yrepeattimer60 = 0;
				}

				// Calculate the repeat interval based on the stick pressure
				if (abssticky > 70) {
					abssticky = 70;
				}

				abssticky -= ydeadzone;
				interval = stickintervalbase - ystickintervalmult * abssticky / 50;

				// After 3 repeats, third the interval (ie. make faster)
				if (menu->yrepeatcount >= 3 || menu->yrepeatcount <= -3) {
					interval /= 3;
				}

				if (interval > 0) {
#if VERSION >= VERSION_PAL_BETA
					if (interval > 3) {
						interval = TICKS(interval);
					}
#endif

					oldslot = menu->yrepeattimer60 / interval;
					newslot = (menu->yrepeattimer60 + g_Vars.diffframe60) / interval;

					yhelddir = sticky > 0 ? -1 : 1;

					if (oldslot != newslot) {
						apply = true;
					}

					if (menu->yrepeatcount == 0) {
						apply = true;
					}

					if (apply) {
						menu->yrepeatcount += yhelddir;
					}
				}
			} else {
				menu->yrepeatcount = 0;
			}

			if (oldslot != newslot) {
				apply = true;
			}

			if (!apply) {
				yhelddir = 0;
			}
		}

		menu->xrepeattimer60 += g_Vars.diffframe60;
		menu->yrepeattimer60 += g_Vars.diffframe60;

		inputs.leftright = xhelddir;
		inputs.updown = yhelddir;
		inputs.xaxis = stickx;
		inputs.yaxis = sticky;
		inputs.unk14 = 0;
		inputs.start = starttap ? true : false;

		// Handle dialogs that allow pressing start to select,
		// and handle pressing start on a list item.
		if (g_Menus[g_MpPlayerNum].curdialog && starttap) {
			struct menuitem *item;

			if (g_Menus[g_MpPlayerNum].curdialog->definition->flags & MENUDIALOGFLAG_STARTSELECTS) {
				inputs.select = true;
				starttoselect = true;
			}

			item = g_Menus[g_MpPlayerNum].curdialog->focuseditem;

			if (item && item->type == MENUITEMTYPE_LIST) {
				inputs.select = true;
			}
		}

		// Iterate all dialogs and give them the input for processing
		{
			bool foundcurrent = false;
			s32 i;
			s32 j;

			for (i = 0; i < g_Menus[g_MpPlayerNum].depth; i++) {
				struct menulayer *layer = &g_Menus[g_MpPlayerNum].layers[i];

				for (j = 0; j < layer->numsiblings; j++) {
					u32 tickflags = 0;

					if (i == g_Menus[g_MpPlayerNum].depth - 1 && j == layer->cursibling && !foundcurrent) {
						tickflags |= MENUTICKFLAG_DIALOGISCURRENT;
						foundcurrent = true;
					}

					dialogTick(layer->siblings[j], &inputs, tickflags);
				}
			}
		}

		switch (g_MenuData.root) {
		case MENUROOT_MPSETUP:
		case MENUROOT_4MBMAINMENU:
			// Allow pressing start on most MP setup dialogs to jump straight to
			// the Ready dialog, or apply the quick start setup.
			if (inputs.start && !starttoselect && g_Menus[g_MpPlayerNum].curdialog && !dialog->dimmed) {
				if (g_Menus[g_MpPlayerNum].curdialog->definition);

				if (g_Vars.mpsetupmenu != MPSETUPMENU_GENERAL
						&& g_Menus[g_MpPlayerNum].curdialog->definition != &g_MpReadyMenuDialog) {
					menuPushDialog(&g_MpReadyMenuDialog);
				} else if (g_Menus[g_MpPlayerNum].curdialog->definition == &g_MpQuickTeamGameSetupMenuDialog) {
					func0f17f428();
				}
			}
			break;
		case MENUROOT_MPPAUSE:
			if (g_InCutscene) {
				func0f0f8120();
			}
			g_Menus[g_MpPlayerNum].openinhibit = 10;
			// fall-through
		case MENUROOT_ENDSCREEN:
		case MENUROOT_MAINMENU:
		case MENUROOT_MPENDSCREEN:
		case MENUROOT_TRAINING:
			if (inputs.start && !starttoselect && g_Menus[g_MpPlayerNum].curdialog
					&& (dialog->definition->flags & MENUDIALOGFLAG_IGNOREBACK) == 0) {
				func0f0f8120();
			}
			break;
		}
	}
}

Gfx *menugfxRenderBgFailureAlt(Gfx *gdl);

/**
 * Render layer 1 of the menu background.
 *
 * Layer 1 is drawn before the hud piece. Almost everything is in layer 1.
 *
 * frac is used when transitioning between two backgrounds.
 * A value of 1 means draw this background with full alpha.
 */
Gfx *menuRenderBackgroundLayer1(Gfx *gdl, u8 bg, f32 frac)
{
	static u32 bblur = 1;

	switch (bg) {
	case MENUBG_BLUR:
		{
			u32 alpha = 255 * frac;

			// Render the blurred background texture with full alpha
			gdl = menugfxRenderBgBlur(gdl, 0xffffff00 | alpha, 0, 0);

			// Render it twice more with half alpha and offset
			gdl = menugfxRenderBgBlur(gdl, 0xffffff00 | alpha >> 1, -30, -30);
			gdl = menugfxRenderBgBlur(gdl, 0xffffff00 | alpha >> 1, 30, 30);
		}
		break;
	case MENUBG_BLACK:
	case MENUBG_8:
		{
			u32 colour = 255 * frac;
			gSPDisplayList(gdl++, var800613a0);
			gdl = textSetPrimColour(gdl, colour);
			gDPFillRectangle(gdl++, 0, 0, viGetWidth(), viGetHeight());
			gdl = text0f153838(gdl);
		}
		break;
	case MENUBG_SUCCESS:
		{
			// Fill with black
			gSPDisplayList(gdl++, var800613a0);
			gdl = textSetPrimColour(gdl, 0x000000ff);
			gDPFillRectangle(gdl++, 0, 0, viGetWidth(), viGetHeight());
			gdl = text0f153838(gdl);

			// Render the success BG
			gdl = menugfxRenderBgSuccess(gdl);

			// Render alpha black if fading in
			{
				u32 alpha = (1.0f - frac) * 255;

				if (alpha) {
					gSPDisplayList(gdl++, var800613a0);
					gdl = textSetPrimColour(gdl, alpha);
					gDPFillRectangle(gdl++, 0, 0, viGetWidth(), viGetHeight());
					gdl = text0f153838(gdl);
				}
			}
		}
		break;
	case MENUBG_FAILURE:
		{
			// Fill with white -> black while fading in
			u32 stack;
			u32 channel = (1.0f - frac) * 255;
			gSPDisplayList(gdl++, var800613a0);
			gdl = textSetPrimColour(gdl, channel << 24 | channel << 16 | channel << 8 | 0xff);
			gDPFillRectangle(gdl++, 0, 0, viGetWidth(), viGetHeight());
			gdl = text0f153838(gdl);

			// Render the failure BG
			gdl = menugfxRenderBgFailure(gdl);
		}
		break;
	case MENUBG_CONEALPHA:
		mainOverrideVariable("bblur", &bblur);

		if (g_MenuData.screenshottimer) {
			return gdl;
		}

		if (bblur) {
			// Render the blurred background
			gdl = menugfxRenderBgBlur(gdl, 0xffffffff, 0, 0);

			// While fading, render red
			if (frac < 1.0f) {
				u32 alpha;
				u32 stack;

				gSPDisplayList(gdl++, var800613a0);
				alpha = (1.0f - frac) * 255;
				gdl = textSetPrimColour(gdl, 0xff000000 | alpha);
				gDPFillRectangle(gdl++, 0, 0, viGetWidth(), viGetHeight());
				gdl = text0f153838(gdl);
			}
		}
		break;
	case MENUBG_GRADIENT:
		// Blue to red
		gdl = menugfxRenderGradient(gdl, 0, 0, viGetWidth(), viGetHeight(), 0x00007f7f, 0x000000ff, 0x8f0000ff);
		break;
	case MENUBG_CONEOPAQUE:
		// Yellow to yellow (ie. not a gradient)
		gdl = menugfxRenderGradient(gdl, 0, 0, viGetWidth(), viGetHeight(), 0x3f3f00ff, 0x7f0000ff, 0x3f3f00ff);
		break;
	}

	return gdl;
}

u32 var800714f0 = 1;

Gfx *menuRenderBackgroundLayer2(Gfx *gdl, u8 bg, f32 frac)
{
	if (bg == MENUBG_CONEALPHA || bg == MENUBG_CONEOPAQUE) {
		mainOverrideVariable("cone", &var800714f0);

		if (var800714f0
				&& (g_MenuData.nextbg == MENUBG_CONEALPHA || g_MenuData.nextbg == 0 || g_MenuData.nextbg == 255)) {
			gdl = menugfxRenderBgCone(gdl);
		}
	}

	return gdl;
}

#if VERSION >= VERSION_JPN_FINAL
u32 usepiece = 1;
const char var7f1b34b4jf[] = "usePiece";
const char var7f1b34c0jf[] = "%s%s";
const char var7f1b34c8jf[] = "%s%s";

GLOBAL_ASM(
glabel menuRender
.late_rodata
glabel var7f1b381cjf
.word 0
.word 0x3f847ae1
.word 0x47ae147b
.word 0xc34d8000
.word 0x4374b333
.text
/*  f0fc924:	27bdfee8 */ 	addiu	$sp,$sp,-280
/*  f0fc928:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f0fc92c:	3c118007 */ 	lui	$s1,0x8007
/*  f0fc930:	26311998 */ 	addiu	$s1,$s1,0x1998
/*  f0fc934:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f0fc938:	3c0e8007 */ 	lui	$t6,0x8007
/*  f0fc93c:	8dce0c18 */ 	lw	$t6,0xc18($t6)
/*  f0fc940:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f0fc944:	24020001 */ 	li	$v0,0x1
/*  f0fc948:	0080a825 */ 	move	$s5,$a0
/*  f0fc94c:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f0fc950:	afb70050 */ 	sw	$s7,0x50($sp)
/*  f0fc954:	afb6004c */ 	sw	$s6,0x4c($sp)
/*  f0fc958:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f0fc95c:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f0fc960:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f0fc964:	144e0005 */ 	bne	$v0,$t6,.JF0f0fc97c
/*  f0fc968:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f0fc96c:	240f0002 */ 	li	$t7,0x2
/*  f0fc970:	3c018008 */ 	lui	$at,0x8008
/*  f0fc974:	10000003 */ 	b	.JF0f0fc984
/*  f0fc978:	ac2f00f4 */ 	sw	$t7,0xf4($at)
.JF0f0fc97c:
/*  f0fc97c:	3c018008 */ 	lui	$at,0x8008
/*  f0fc980:	ac2200f4 */ 	sw	$v0,0xf4($at)
.JF0f0fc984:
/*  f0fc984:	0fc35617 */ 	jal	func0f0d479c
/*  f0fc988:	02a02025 */ 	move	$a0,$s5
/*  f0fc98c:	3c138006 */ 	lui	$s3,0x8006
/*  f0fc990:	3c17800a */ 	lui	$s7,0x800a
/*  f0fc994:	26731280 */ 	addiu	$s3,$s3,0x1280
/*  f0fc998:	3c180600 */ 	lui	$t8,0x600
/*  f0fc99c:	26f720c0 */ 	addiu	$s7,$s7,0x20c0
/*  f0fc9a0:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f0fc9a4:	ac530004 */ 	sw	$s3,0x4($v0)
/*  f0fc9a8:	92e30015 */ 	lbu	$v1,0x15($s7)
/*  f0fc9ac:	24550008 */ 	addiu	$s5,$v0,0x8
/*  f0fc9b0:	240100ff */ 	li	$at,0xff
/*  f0fc9b4:	10610017 */ 	beq	$v1,$at,.JF0f0fca14
/*  f0fc9b8:	02a02025 */ 	move	$a0,$s5
/*  f0fc9bc:	1460000c */ 	bnez	$v1,.JF0f0fc9f0
/*  f0fc9c0:	02a02025 */ 	move	$a0,$s5
/*  f0fc9c4:	3c013f80 */ 	lui	$at,0x3f80
/*  f0fc9c8:	44812000 */ 	mtc1	$at,$f4
/*  f0fc9cc:	c6e60010 */ 	lwc1	$f6,0x10($s7)
/*  f0fc9d0:	02a02025 */ 	move	$a0,$s5
/*  f0fc9d4:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fc9d8:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f0fc9dc:	44064000 */ 	mfc1	$a2,$f8
/*  f0fc9e0:	0fc3f05f */ 	jal	menuRenderBackgroundLayer1
/*  f0fc9e4:	00000000 */ 	nop
/*  f0fc9e8:	1000000e */ 	b	.JF0f0fca24
/*  f0fc9ec:	0040a825 */ 	move	$s5,$v0
.JF0f0fc9f0:
/*  f0fc9f0:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fc9f4:	0fc3f05f */ 	jal	menuRenderBackgroundLayer1
/*  f0fc9f8:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0fc9fc:	00402025 */ 	move	$a0,$v0
/*  f0fca00:	92e50015 */ 	lbu	$a1,0x15($s7)
/*  f0fca04:	0fc3f05f */ 	jal	menuRenderBackgroundLayer1
/*  f0fca08:	8ee60010 */ 	lw	$a2,0x10($s7)
/*  f0fca0c:	10000005 */ 	b	.JF0f0fca24
/*  f0fca10:	0040a825 */ 	move	$s5,$v0
.JF0f0fca14:
/*  f0fca14:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fca18:	0fc3f05f */ 	jal	menuRenderBackgroundLayer1
/*  f0fca1c:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0fca20:	0040a825 */ 	move	$s5,$v0
.JF0f0fca24:
/*  f0fca24:	8ef905d4 */ 	lw	$t9,0x5d4($s7)
/*  f0fca28:	240c040d */ 	li	$t4,0x40d
/*  f0fca2c:	240f0001 */ 	li	$t7,0x1
/*  f0fca30:	00195b00 */ 	sll	$t3,$t9,0xc
/*  f0fca34:	0561000b */ 	bgez	$t3,.JF0f0fca64
/*  f0fca38:	3c0a8009 */ 	lui	$t2,0x8009
/*  f0fca3c:	92ed05cd */ 	lbu	$t5,0x5cd($s7)
/*  f0fca40:	92f805d5 */ 	lbu	$t8,0x5d5($s7)
/*  f0fca44:	a6e0007a */ 	sh	$zero,0x7a($s7)
/*  f0fca48:	31aeffef */ 	andi	$t6,$t5,0xffef
/*  f0fca4c:	3319fff7 */ 	andi	$t9,$t8,0xfff7
/*  f0fca50:	a6ec0078 */ 	sh	$t4,0x78($s7)
/*  f0fca54:	aee0059c */ 	sw	$zero,0x59c($s7)
/*  f0fca58:	a2ee05cd */ 	sb	$t6,0x5cd($s7)
/*  f0fca5c:	a2ef05d4 */ 	sb	$t7,0x5d4($s7)
/*  f0fca60:	a2f905d5 */ 	sb	$t9,0x5d5($s7)
.JF0f0fca64:
/*  f0fca64:	914a1160 */ 	lbu	$t2,0x1160($t2)
/*  f0fca68:	24010001 */ 	li	$at,0x1
/*  f0fca6c:	114100ab */ 	beq	$t2,$at,.JF0f0fcd1c
/*  f0fca70:	00000000 */ 	nop
/*  f0fca74:	92eb05d4 */ 	lbu	$t3,0x5d4($s7)
/*  f0fca78:	02a01025 */ 	move	$v0,$s5
/*  f0fca7c:	3c0cb700 */ 	lui	$t4,0xb700
/*  f0fca80:	116000a6 */ 	beqz	$t3,.JF0f0fcd1c
/*  f0fca84:	240d0001 */ 	li	$t5,0x1
/*  f0fca88:	00008025 */ 	move	$s0,$zero
/*  f0fca8c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f0fca90:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0fca94:	0c004b60 */ 	jal	random
/*  f0fca98:	ac4d0004 */ 	sw	$t5,0x4($v0)
/*  f0fca9c:	44825000 */ 	mtc1	$v0,$f10
/*  f0fcaa0:	3c014f80 */ 	lui	$at,0x4f80
/*  f0fcaa4:	04410004 */ 	bgez	$v0,.JF0f0fcab8
/*  f0fcaa8:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f0fcaac:	44819000 */ 	mtc1	$at,$f18
/*  f0fcab0:	00000000 */ 	nop
/*  f0fcab4:	46128400 */ 	add.s	$f16,$f16,$f18
.JF0f0fcab8:
/*  f0fcab8:	3c012f80 */ 	lui	$at,0x2f80
/*  f0fcabc:	44812000 */ 	mtc1	$at,$f4
/*  f0fcac0:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0fcac4:	d42a3820 */ 	ldc1	$f10,0x3820($at)
/*  f0fcac8:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f0fcacc:	46003221 */ 	cvt.d.s	$f8,$f6
/*  f0fcad0:	462a403c */ 	c.lt.d	$f8,$f10
/*  f0fcad4:	00000000 */ 	nop
/*  f0fcad8:	4502002d */ 	bc1fl	.JF0f0fcb90
/*  f0fcadc:	8ee30004 */ 	lw	$v1,0x4($s7)
/*  f0fcae0:	0c004b60 */ 	jal	random
/*  f0fcae4:	00000000 */ 	nop
/*  f0fcae8:	44829000 */ 	mtc1	$v0,$f18
/*  f0fcaec:	3c014f80 */ 	lui	$at,0x4f80
/*  f0fcaf0:	04410004 */ 	bgez	$v0,.JF0f0fcb04
/*  f0fcaf4:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f0fcaf8:	44812000 */ 	mtc1	$at,$f4
/*  f0fcafc:	00000000 */ 	nop
/*  f0fcb00:	46048400 */ 	add.s	$f16,$f16,$f4
.JF0f0fcb04:
/*  f0fcb04:	3c012f80 */ 	lui	$at,0x2f80
/*  f0fcb08:	44813000 */ 	mtc1	$at,$f6
/*  f0fcb0c:	3c0142a0 */ 	lui	$at,0x42a0
/*  f0fcb10:	44815000 */ 	mtc1	$at,$f10
/*  f0fcb14:	46068202 */ 	mul.s	$f8,$f16,$f6
/*  f0fcb18:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0fcb1c:	c4243828 */ 	lwc1	$f4,0x3828($at)
/*  f0fcb20:	3c014220 */ 	lui	$at,0x4220
/*  f0fcb24:	44813000 */ 	mtc1	$at,$f6
/*  f0fcb28:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f0fcb2c:	46049400 */ 	add.s	$f16,$f18,$f4
/*  f0fcb30:	46068201 */ 	sub.s	$f8,$f16,$f6
/*  f0fcb34:	0c004b60 */ 	jal	random
/*  f0fcb38:	e6e80554 */ 	swc1	$f8,0x554($s7)
/*  f0fcb3c:	44825000 */ 	mtc1	$v0,$f10
/*  f0fcb40:	3c014f80 */ 	lui	$at,0x4f80
/*  f0fcb44:	04410004 */ 	bgez	$v0,.JF0f0fcb58
/*  f0fcb48:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f0fcb4c:	44812000 */ 	mtc1	$at,$f4
/*  f0fcb50:	00000000 */ 	nop
/*  f0fcb54:	46049480 */ 	add.s	$f18,$f18,$f4
.JF0f0fcb58:
/*  f0fcb58:	3c012f80 */ 	lui	$at,0x2f80
/*  f0fcb5c:	44818000 */ 	mtc1	$at,$f16
/*  f0fcb60:	3c0142a0 */ 	lui	$at,0x42a0
/*  f0fcb64:	44814000 */ 	mtc1	$at,$f8
/*  f0fcb68:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f0fcb6c:	3c017f1b */ 	lui	$at,0x7f1b
/*  f0fcb70:	c424382c */ 	lwc1	$f4,0x382c($at)
/*  f0fcb74:	3c014220 */ 	lui	$at,0x4220
/*  f0fcb78:	44818000 */ 	mtc1	$at,$f16
/*  f0fcb7c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f0fcb80:	46045480 */ 	add.s	$f18,$f10,$f4
/*  f0fcb84:	46109181 */ 	sub.s	$f6,$f18,$f16
/*  f0fcb88:	e6e60558 */ 	swc1	$f6,0x558($s7)
/*  f0fcb8c:	8ee30004 */ 	lw	$v1,0x4($s7)
.JF0f0fcb90:
/*  f0fcb90:	3c12800a */ 	lui	$s2,0x800a
/*  f0fcb94:	3c14800a */ 	lui	$s4,0x800a
/*  f0fcb98:	2694e568 */ 	addiu	$s4,$s4,-6808
/*  f0fcb9c:	2652e56c */ 	addiu	$s2,$s2,-6804
/*  f0fcba0:	24060003 */ 	li	$a2,0x3
/*  f0fcba4:	ae400000 */ 	sw	$zero,0x0($s2)
/*  f0fcba8:	14c30005 */ 	bne	$a2,$v1,.JF0f0fcbc0
/*  f0fcbac:	ae800000 */ 	sw	$zero,0x0($s4)
/*  f0fcbb0:	8eef0000 */ 	lw	$t7,0x0($s7)
/*  f0fcbb4:	5de00003 */ 	bgtzl	$t7,.JF0f0fcbc4
/*  f0fcbb8:	24010002 */ 	li	$at,0x2
/*  f0fcbbc:	24100001 */ 	li	$s0,0x1
.JF0f0fcbc0:
/*  f0fcbc0:	24010002 */ 	li	$at,0x2
.JF0f0fcbc4:
/*  f0fcbc4:	10610008 */ 	beq	$v1,$at,.JF0f0fcbe8
/*  f0fcbc8:	3c16800a */ 	lui	$s6,0x800a
/*  f0fcbcc:	10c30006 */ 	beq	$a2,$v1,.JF0f0fcbe8
/*  f0fcbd0:	24010006 */ 	li	$at,0x6
/*  f0fcbd4:	10610004 */ 	beq	$v1,$at,.JF0f0fcbe8
/*  f0fcbd8:	2401000d */ 	li	$at,0xd
/*  f0fcbdc:	50610003 */ 	beql	$v1,$at,.JF0f0fcbec
/*  f0fcbe0:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f0fcbe4:	24100001 */ 	li	$s0,0x1
.JF0f0fcbe8:
/*  f0fcbe8:	8e380000 */ 	lw	$t8,0x0($s1)
.JF0f0fcbec:
/*  f0fcbec:	3c0a800a */ 	lui	$t2,0x800a
/*  f0fcbf0:	3c047f1b */ 	lui	$a0,0x7f1b
/*  f0fcbf4:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f0fcbf8:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0fcbfc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f0fcc00:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f0fcc04:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f0fcc08:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f0fcc0c:	0019c900 */ 	sll	$t9,$t9,0x4
/*  f0fcc10:	01595021 */ 	addu	$t2,$t2,$t9
/*  f0fcc14:	8d4aebf8 */ 	lw	$t2,-0x1408($t2)
/*  f0fcc18:	26d6a630 */ 	addiu	$s6,$s6,-22992
/*  f0fcc1c:	248434b4 */ 	addiu	$a0,$a0,0x34b4
/*  f0fcc20:	15400004 */ 	bnez	$t2,.JF0f0fcc34
/*  f0fcc24:	3c058007 */ 	lui	$a1,0x8007
/*  f0fcc28:	50c30003 */ 	beql	$a2,$v1,.JF0f0fcc38
/*  f0fcc2c:	8ec30284 */ 	lw	$v1,0x284($s6)
/*  f0fcc30:	24100001 */ 	li	$s0,0x1
.JF0f0fcc34:
/*  f0fcc34:	8ec30284 */ 	lw	$v1,0x284($s6)
.JF0f0fcc38:
/*  f0fcc38:	8c620480 */ 	lw	$v0,0x480($v1)
/*  f0fcc3c:	1040000c */ 	beqz	$v0,.JF0f0fcc70
/*  f0fcc40:	00000000 */ 	nop
/*  f0fcc44:	8c6c1c54 */ 	lw	$t4,0x1c54($v1)
/*  f0fcc48:	8c6b00c4 */ 	lw	$t3,0xc4($v1)
/*  f0fcc4c:	01806827 */ 	nor	$t5,$t4,$zero
/*  f0fcc50:	016d7024 */ 	and	$t6,$t3,$t5
/*  f0fcc54:	31cf0004 */ 	andi	$t7,$t6,0x4
/*  f0fcc58:	11e00005 */ 	beqz	$t7,.JF0f0fcc70
/*  f0fcc5c:	00000000 */ 	nop
/*  f0fcc60:	80580037 */ 	lb	$t8,0x37($v0)
/*  f0fcc64:	13000002 */ 	beqz	$t8,.JF0f0fcc70
/*  f0fcc68:	00000000 */ 	nop
/*  f0fcc6c:	24100001 */ 	li	$s0,0x1
.JF0f0fcc70:
/*  f0fcc70:	12000012 */ 	beqz	$s0,.JF0f0fccbc
/*  f0fcc74:	00000000 */ 	nop
/*  f0fcc78:	8ef9059c */ 	lw	$t9,0x59c($s7)
/*  f0fcc7c:	240d040d */ 	li	$t5,0x40d
/*  f0fcc80:	240e0001 */ 	li	$t6,0x1
/*  f0fcc84:	57200009 */ 	bnezl	$t9,.JF0f0fccac
/*  f0fcc88:	86ef007a */ 	lh	$t7,0x7a($s7)
/*  f0fcc8c:	92ec05cd */ 	lbu	$t4,0x5cd($s7)
/*  f0fcc90:	a6e0007a */ 	sh	$zero,0x7a($s7)
/*  f0fcc94:	a6ed0078 */ 	sh	$t5,0x78($s7)
/*  f0fcc98:	358b0010 */ 	ori	$t3,$t4,0x10
/*  f0fcc9c:	a2eb05cd */ 	sb	$t3,0x5cd($s7)
/*  f0fcca0:	10000006 */ 	b	.JF0f0fccbc
/*  f0fcca4:	aeee059c */ 	sw	$t6,0x59c($s7)
/*  f0fcca8:	86ef007a */ 	lh	$t7,0x7a($s7)
.JF0f0fccac:
/*  f0fccac:	15e00003 */ 	bnez	$t7,.JF0f0fccbc
/*  f0fccb0:	00000000 */ 	nop
/*  f0fccb4:	aee0059c */ 	sw	$zero,0x59c($s7)
/*  f0fccb8:	a2e005d4 */ 	sb	$zero,0x5d4($s7)
.JF0f0fccbc:
/*  f0fccbc:	0c0036b4 */ 	jal	mainOverrideVariable
/*  f0fccc0:	24a51a44 */ 	addiu	$a1,$a1,0x1a44
/*  f0fccc4:	3c188007 */ 	lui	$t8,0x8007
/*  f0fccc8:	8f181a44 */ 	lw	$t8,0x1a44($t8)
/*  f0fcccc:	02a02025 */ 	move	$a0,$s5
/*  f0fccd0:	3c05800a */ 	lui	$a1,0x800a
/*  f0fccd4:	1300000f */ 	beqz	$t8,.JF0f0fcd14
/*  f0fccd8:	00000000 */ 	nop
/*  f0fccdc:	92f905d5 */ 	lbu	$t9,0x5d5($s7)
/*  f0fcce0:	24a520dc */ 	addiu	$a1,$a1,0x20dc
/*  f0fcce4:	24060001 */ 	li	$a2,0x1
/*  f0fcce8:	332affdf */ 	andi	$t2,$t9,0xffdf
/*  f0fccec:	0fc3d151 */ 	jal	menuRenderModels
/*  f0fccf0:	a2ea05d5 */ 	sb	$t2,0x5d5($s7)
/*  f0fccf4:	3c0cb600 */ 	lui	$t4,0xb600
/*  f0fccf8:	240b0001 */ 	li	$t3,0x1
/*  f0fccfc:	ac4b0004 */ 	sw	$t3,0x4($v0)
/*  f0fcd00:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f0fcd04:	92ee05d5 */ 	lbu	$t6,0x5d5($s7)
/*  f0fcd08:	24550008 */ 	addiu	$s5,$v0,0x8
/*  f0fcd0c:	35cf0020 */ 	ori	$t7,$t6,0x20
/*  f0fcd10:	a2ef05d5 */ 	sb	$t7,0x5d5($s7)
.JF0f0fcd14:
/*  f0fcd14:	1000000a */ 	b	.JF0f0fcd40
/*  f0fcd18:	8ee205d4 */ 	lw	$v0,0x5d4($s7)
.JF0f0fcd1c:
/*  f0fcd1c:	3c12800a */ 	lui	$s2,0x800a
/*  f0fcd20:	3c14800a */ 	lui	$s4,0x800a
/*  f0fcd24:	2694e568 */ 	addiu	$s4,$s4,-6808
/*  f0fcd28:	2652e56c */ 	addiu	$s2,$s2,-6804
/*  f0fcd2c:	3c16800a */ 	lui	$s6,0x800a
/*  f0fcd30:	26d6a630 */ 	addiu	$s6,$s6,-22992
/*  f0fcd34:	ae400000 */ 	sw	$zero,0x0($s2)
/*  f0fcd38:	ae800000 */ 	sw	$zero,0x0($s4)
/*  f0fcd3c:	8ee205d4 */ 	lw	$v0,0x5d4($s7)
.JF0f0fcd40:
/*  f0fcd40:	000252c0 */ 	sll	$t2,$v0,0xb
/*  f0fcd44:	05410005 */ 	bgez	$t2,.JF0f0fcd5c
/*  f0fcd48:	02a02025 */ 	move	$a0,$s5
/*  f0fcd4c:	8eec0670 */ 	lw	$t4,0x670($s7)
/*  f0fcd50:	8eeb0674 */ 	lw	$t3,0x674($s7)
/*  f0fcd54:	ae8c0000 */ 	sw	$t4,0x0($s4)
/*  f0fcd58:	ae4b0000 */ 	sw	$t3,0x0($s2)
.JF0f0fcd5c:
/*  f0fcd5c:	92e30015 */ 	lbu	$v1,0x15($s7)
/*  f0fcd60:	240100ff */ 	li	$at,0xff
/*  f0fcd64:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0fcd68:	10610017 */ 	beq	$v1,$at,.JF0f0fcdc8
/*  f0fcd6c:	00000000 */ 	nop
/*  f0fcd70:	1460000c */ 	bnez	$v1,.JF0f0fcda4
/*  f0fcd74:	02a02025 */ 	move	$a0,$s5
/*  f0fcd78:	3c013f80 */ 	lui	$at,0x3f80
/*  f0fcd7c:	44814000 */ 	mtc1	$at,$f8
/*  f0fcd80:	c6ea0010 */ 	lwc1	$f10,0x10($s7)
/*  f0fcd84:	02a02025 */ 	move	$a0,$s5
/*  f0fcd88:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fcd8c:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f0fcd90:	44062000 */ 	mfc1	$a2,$f4
/*  f0fcd94:	0fc3f225 */ 	jal	menuRenderBackgroundLayer2
/*  f0fcd98:	00000000 */ 	nop
/*  f0fcd9c:	1000000d */ 	b	.JF0f0fcdd4
/*  f0fcda0:	0040a825 */ 	move	$s5,$v0
.JF0f0fcda4:
/*  f0fcda4:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fcda8:	0fc3f225 */ 	jal	menuRenderBackgroundLayer2
/*  f0fcdac:	3c063f80 */ 	lui	$a2,0x3f80
/*  f0fcdb0:	00402025 */ 	move	$a0,$v0
/*  f0fcdb4:	92e50015 */ 	lbu	$a1,0x15($s7)
/*  f0fcdb8:	0fc3f225 */ 	jal	menuRenderBackgroundLayer2
/*  f0fcdbc:	8ee60010 */ 	lw	$a2,0x10($s7)
/*  f0fcdc0:	10000004 */ 	b	.JF0f0fcdd4
/*  f0fcdc4:	0040a825 */ 	move	$s5,$v0
.JF0f0fcdc8:
/*  f0fcdc8:	0fc3f225 */ 	jal	menuRenderBackgroundLayer2
/*  f0fcdcc:	92e50014 */ 	lbu	$a1,0x14($s7)
/*  f0fcdd0:	0040a825 */ 	move	$s5,$v0
.JF0f0fcdd4:
/*  f0fcdd4:	92ed0014 */ 	lbu	$t5,0x14($s7)
/*  f0fcdd8:	55a00006 */ 	bnezl	$t5,.JF0f0fcdf4
/*  f0fcddc:	8ecf0284 */ 	lw	$t7,0x284($s6)
/*  f0fcde0:	92ee0015 */ 	lbu	$t6,0x15($s7)
/*  f0fcde4:	240100ff */ 	li	$at,0xff
/*  f0fcde8:	51c10010 */ 	beql	$t6,$at,.JF0f0fce2c
/*  f0fcdec:	8ef90000 */ 	lw	$t9,0x0($s7)
/*  f0fcdf0:	8ecf0284 */ 	lw	$t7,0x284($s6)
.JF0f0fcdf4:
/*  f0fcdf4:	8de20480 */ 	lw	$v0,0x480($t7)
/*  f0fcdf8:	10400004 */ 	beqz	$v0,.JF0f0fce0c
/*  f0fcdfc:	00000000 */ 	nop
/*  f0fce00:	80580037 */ 	lb	$t8,0x37($v0)
/*  f0fce04:	57000009 */ 	bnezl	$t8,.JF0f0fce2c
/*  f0fce08:	8ef90000 */ 	lw	$t9,0x0($s7)
.JF0f0fce0c:
/*  f0fce0c:	0fc356a2 */ 	jal	func0f0d49c8
/*  f0fce10:	02a02025 */ 	move	$a0,$s5
/*  f0fce14:	0fc2f3fe */ 	jal	playerRenderHealthBar
/*  f0fce18:	00402025 */ 	move	$a0,$v0
/*  f0fce1c:	0fc35617 */ 	jal	func0f0d479c
/*  f0fce20:	00402025 */ 	move	$a0,$v0
/*  f0fce24:	0040a825 */ 	move	$s5,$v0
/*  f0fce28:	8ef90000 */ 	lw	$t9,0x0($s7)
.JF0f0fce2c:
/*  f0fce2c:	5b20017c */ 	blezl	$t9,.JF0f0fd420
/*  f0fce30:	82ef001b */ 	lb	$t7,0x1b($s7)
/*  f0fce34:	0fc54c87 */ 	jal	text0f153ab0
/*  f0fce38:	02a02025 */ 	move	$a0,$s5
/*  f0fce3c:	8ee30004 */ 	lw	$v1,0x4($s7)
/*  f0fce40:	24010004 */ 	li	$at,0x4
/*  f0fce44:	0040a825 */ 	move	$s5,$v0
/*  f0fce48:	10610003 */ 	beq	$v1,$at,.JF0f0fce58
/*  f0fce4c:	24010005 */ 	li	$at,0x5
/*  f0fce50:	14610008 */ 	bne	$v1,$at,.JF0f0fce74
/*  f0fce54:	00008025 */ 	move	$s0,$zero
.JF0f0fce58:
/*  f0fce58:	8eca0288 */ 	lw	$t2,0x288($s6)
/*  f0fce5c:	02a02025 */ 	move	$a0,$s5
/*  f0fce60:	8d4c0070 */ 	lw	$t4,0x70($t2)
/*  f0fce64:	0fc3e4e8 */ 	jal	menuRenderDialogs
/*  f0fce68:	ae2c0000 */ 	sw	$t4,0x0($s1)
/*  f0fce6c:	10000008 */ 	b	.JF0f0fce90
/*  f0fce70:	0040a825 */ 	move	$s5,$v0
.JF0f0fce74:
/*  f0fce74:	ae300000 */ 	sw	$s0,0x0($s1)
/*  f0fce78:	0fc3e4e8 */ 	jal	menuRenderDialogs
/*  f0fce7c:	02a02025 */ 	move	$a0,$s5
/*  f0fce80:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f0fce84:	24010004 */ 	li	$at,0x4
/*  f0fce88:	1601fffa */ 	bne	$s0,$at,.JF0f0fce74
/*  f0fce8c:	0040a825 */ 	move	$s5,$v0
.JF0f0fce90:
/*  f0fce90:	3c0b0103 */ 	lui	$t3,0x103
/*  f0fce94:	ae200000 */ 	sw	$zero,0x0($s1)
/*  f0fce98:	356b0040 */ 	ori	$t3,$t3,0x40
/*  f0fce9c:	02a08025 */ 	move	$s0,$s5
/*  f0fcea0:	ae0b0000 */ 	sw	$t3,0x0($s0)
/*  f0fcea4:	0fc2d81a */ 	jal	camGetPerspectiveMtxL
/*  f0fcea8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f0fceac:	0c012b34 */ 	jal	osVirtualToPhysical
/*  f0fceb0:	00402025 */ 	move	$a0,$v0
/*  f0fceb4:	02a01825 */ 	move	$v1,$s5
/*  f0fceb8:	ae020004 */ 	sw	$v0,0x4($s0)
/*  f0fcebc:	3c0d0600 */ 	lui	$t5,0x600
/*  f0fcec0:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f0fcec4:	ac730004 */ 	sw	$s3,0x4($v1)
/*  f0fcec8:	0fc54cab */ 	jal	text0f153b40
/*  f0fcecc:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f0fced0:	8ee30004 */ 	lw	$v1,0x4($s7)
/*  f0fced4:	24010003 */ 	li	$at,0x3
/*  f0fced8:	10610003 */ 	beq	$v1,$at,.JF0f0fcee8
/*  f0fcedc:	2401000b */ 	li	$at,0xb
/*  f0fcee0:	54610149 */ 	bnel	$v1,$at,.JF0f0fd408
/*  f0fcee4:	02a01025 */ 	move	$v0,$s5
.JF0f0fcee8:
/*  f0fcee8:	0c002f29 */ 	jal	viGetViewLeft
/*  f0fceec:	00000000 */ 	nop
/*  f0fcef0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f0fcef4:	8dce00f4 */ 	lw	$t6,0xf4($t6)
/*  f0fcef8:	004e001a */ 	div	$zero,$v0,$t6
/*  f0fcefc:	00007812 */ 	mflo	$t7
/*  f0fcf00:	25f80014 */ 	addiu	$t8,$t7,0x14
/*  f0fcf04:	15c00002 */ 	bnez	$t6,.JF0f0fcf10
/*  f0fcf08:	00000000 */ 	nop
/*  f0fcf0c:	0007000d */ 	break	0x7
.JF0f0fcf10:
/*  f0fcf10:	2401ffff */ 	li	$at,-1
/*  f0fcf14:	15c10004 */ 	bne	$t6,$at,.JF0f0fcf28
/*  f0fcf18:	3c018000 */ 	lui	$at,0x8000
/*  f0fcf1c:	14410002 */ 	bne	$v0,$at,.JF0f0fcf28
/*  f0fcf20:	00000000 */ 	nop
/*  f0fcf24:	0006000d */ 	break	0x6
.JF0f0fcf28:
/*  f0fcf28:	afb800f0 */ 	sw	$t8,0xf0($sp)
/*  f0fcf2c:	0c002f2d */ 	jal	viGetViewTop
/*  f0fcf30:	00000000 */ 	nop
/*  f0fcf34:	24590004 */ 	addiu	$t9,$v0,0x4
/*  f0fcf38:	0c002f29 */ 	jal	viGetViewLeft
/*  f0fcf3c:	afb900ec */ 	sw	$t9,0xec($sp)
/*  f0fcf40:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fcf44:	00105403 */ 	sra	$t2,$s0,0x10
/*  f0fcf48:	0c002f0b */ 	jal	viGetViewWidth
/*  f0fcf4c:	01408025 */ 	move	$s0,$t2
/*  f0fcf50:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0fcf54:	8d6b00f4 */ 	lw	$t3,0xf4($t3)
/*  f0fcf58:	00506021 */ 	addu	$t4,$v0,$s0
/*  f0fcf5c:	018b001a */ 	div	$zero,$t4,$t3
/*  f0fcf60:	00006812 */ 	mflo	$t5
/*  f0fcf64:	25aeffec */ 	addiu	$t6,$t5,-20
/*  f0fcf68:	15600002 */ 	bnez	$t3,.JF0f0fcf74
/*  f0fcf6c:	00000000 */ 	nop
/*  f0fcf70:	0007000d */ 	break	0x7
.JF0f0fcf74:
/*  f0fcf74:	2401ffff */ 	li	$at,-1
/*  f0fcf78:	15610004 */ 	bne	$t3,$at,.JF0f0fcf8c
/*  f0fcf7c:	3c018000 */ 	lui	$at,0x8000
/*  f0fcf80:	15810002 */ 	bne	$t4,$at,.JF0f0fcf8c
/*  f0fcf84:	00000000 */ 	nop
/*  f0fcf88:	0006000d */ 	break	0x6
.JF0f0fcf8c:
/*  f0fcf8c:	afae00e8 */ 	sw	$t6,0xe8($sp)
/*  f0fcf90:	0c002f2d */ 	jal	viGetViewTop
/*  f0fcf94:	00000000 */ 	nop
/*  f0fcf98:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fcf9c:	00107c03 */ 	sra	$t7,$s0,0x10
/*  f0fcfa0:	0c002f0f */ 	jal	viGetViewHeight
/*  f0fcfa4:	01e08025 */ 	move	$s0,$t7
/*  f0fcfa8:	0050c021 */ 	addu	$t8,$v0,$s0
/*  f0fcfac:	2719fffc */ 	addiu	$t9,$t8,-4
/*  f0fcfb0:	afb900e4 */ 	sw	$t9,0xe4($sp)
/*  f0fcfb4:	0fc54b55 */ 	jal	text0f153628
/*  f0fcfb8:	02a02025 */ 	move	$a0,$s5
/*  f0fcfbc:	3c13800a */ 	lui	$s3,0x800a
/*  f0fcfc0:	0040a825 */ 	move	$s5,$v0
/*  f0fcfc4:	2673a634 */ 	addiu	$s3,$s3,-22988
/*  f0fcfc8:	00009025 */ 	move	$s2,$zero
/*  f0fcfcc:	27b400b8 */ 	addiu	$s4,$sp,0xb8
/*  f0fcfd0:	8ec20490 */ 	lw	$v0,0x490($s6)
.JF0f0fcfd4:
/*  f0fcfd4:	24030002 */ 	li	$v1,0x2
/*  f0fcfd8:	02d25021 */ 	addu	$t2,$s6,$s2
/*  f0fcfdc:	54620013 */ 	bnel	$v1,$v0,.JF0f0fd02c
/*  f0fcfe0:	8eeb0004 */ 	lw	$t3,0x4($s7)
/*  f0fcfe4:	814c0494 */ 	lb	$t4,0x494($t2)
/*  f0fcfe8:	24100001 */ 	li	$s0,0x1
/*  f0fcfec:	5180000f */ 	beqzl	$t4,.JF0f0fd02c
/*  f0fcff0:	8eeb0004 */ 	lw	$t3,0x4($s7)
/*  f0fcff4:	0fc5baa5 */ 	jal	langGet
/*  f0fcff8:	240451e2 */ 	li	$a0,0x51e2
/*  f0fcffc:	00408825 */ 	move	$s1,$v0
/*  f0fd000:	0fc5baa5 */ 	jal	langGet
/*  f0fd004:	240458ca */ 	li	$a0,0x58ca
/*  f0fd008:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0fd00c:	24a534c0 */ 	addiu	$a1,$a1,0x34c0
/*  f0fd010:	02802025 */ 	move	$a0,$s4
/*  f0fd014:	02203025 */ 	move	$a2,$s1
/*  f0fd018:	0c004d95 */ 	jal	sprintf
/*  f0fd01c:	00403825 */ 	move	$a3,$v0
/*  f0fd020:	10000023 */ 	b	.JF0f0fd0b0
/*  f0fd024:	00000000 */ 	nop
/*  f0fd028:	8eeb0004 */ 	lw	$t3,0x4($s7)
.JF0f0fd02c:
/*  f0fd02c:	2401000b */ 	li	$at,0xb
/*  f0fd030:	24100001 */ 	li	$s0,0x1
/*  f0fd034:	15610013 */ 	bne	$t3,$at,.JF0f0fd084
/*  f0fd038:	00000000 */ 	nop
/*  f0fd03c:	1462000d */ 	bne	$v1,$v0,.JF0f0fd074
/*  f0fd040:	3c108007 */ 	lui	$s0,0x8007
/*  f0fd044:	3c02800a */ 	lui	$v0,0x800a
/*  f0fd048:	24100001 */ 	li	$s0,0x1
/*  f0fd04c:	2442a630 */ 	addiu	$v0,$v0,-22992
/*  f0fd050:	804d0494 */ 	lb	$t5,0x494($v0)
.JF0f0fd054:
/*  f0fd054:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f0fd058:	11a00002 */ 	beqz	$t5,.JF0f0fd064
/*  f0fd05c:	00000000 */ 	nop
/*  f0fd060:	00008025 */ 	move	$s0,$zero
.JF0f0fd064:
/*  f0fd064:	5453fffb */ 	bnel	$v0,$s3,.JF0f0fd054
/*  f0fd068:	804d0494 */ 	lb	$t5,0x494($v0)
/*  f0fd06c:	10000005 */ 	b	.JF0f0fd084
/*  f0fd070:	00000000 */ 	nop
.JF0f0fd074:
/*  f0fd074:	8e101a28 */ 	lw	$s0,0x1a28($s0)
/*  f0fd078:	2e0e0002 */ 	sltiu	$t6,$s0,0x2
/*  f0fd07c:	10000001 */ 	b	.JF0f0fd084
/*  f0fd080:	01c08025 */ 	move	$s0,$t6
.JF0f0fd084:
/*  f0fd084:	0fc5baa5 */ 	jal	langGet
/*  f0fd088:	240451e2 */ 	li	$a0,0x51e2
/*  f0fd08c:	00408825 */ 	move	$s1,$v0
/*  f0fd090:	0fc5baa5 */ 	jal	langGet
/*  f0fd094:	240451e3 */ 	li	$a0,0x51e3
/*  f0fd098:	3c057f1b */ 	lui	$a1,0x7f1b
/*  f0fd09c:	24a534c8 */ 	addiu	$a1,$a1,0x34c8
/*  f0fd0a0:	02802025 */ 	move	$a0,$s4
/*  f0fd0a4:	02203025 */ 	move	$a2,$s1
/*  f0fd0a8:	0c004d95 */ 	jal	sprintf
/*  f0fd0ac:	00403825 */ 	move	$a3,$v0
.JF0f0fd0b0:
/*  f0fd0b0:	120000cd */ 	beqz	$s0,.JF0f0fd3e8
/*  f0fd0b4:	27a400e0 */ 	addiu	$a0,$sp,0xe0
/*  f0fd0b8:	3c0f8008 */ 	lui	$t7,0x8008
/*  f0fd0bc:	8def0148 */ 	lw	$t7,0x148($t7)
/*  f0fd0c0:	3c078008 */ 	lui	$a3,0x8008
/*  f0fd0c4:	8ce7014c */ 	lw	$a3,0x14c($a3)
/*  f0fd0c8:	27a500dc */ 	addiu	$a1,$sp,0xdc
/*  f0fd0cc:	02803025 */ 	move	$a2,$s4
/*  f0fd0d0:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f0fd0d4:	02f28821 */ 	addu	$s1,$s7,$s2
/*  f0fd0d8:	0fc55d49 */ 	jal	textMeasure
/*  f0fd0dc:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f0fd0e0:	0c004ff9 */ 	jal	joyGetConnectedControllers
/*  f0fd0e4:	00000000 */ 	nop
/*  f0fd0e8:	3c19800b */ 	lui	$t9,0x800b
/*  f0fd0ec:	9739d5ce */ 	lhu	$t9,-0x2a32($t9)
/*  f0fd0f0:	0040c027 */ 	nor	$t8,$v0,$zero
/*  f0fd0f4:	240c0001 */ 	li	$t4,0x1
/*  f0fd0f8:	024c5804 */ 	sllv	$t3,$t4,$s2
/*  f0fd0fc:	03195025 */ 	or	$t2,$t8,$t9
/*  f0fd100:	014b6824 */ 	and	$t5,$t2,$t3
/*  f0fd104:	15a00016 */ 	bnez	$t5,.JF0f0fd160
/*  f0fd108:	3c014110 */ 	lui	$at,0x4110
/*  f0fd10c:	3c014040 */ 	lui	$at,0x4040
/*  f0fd110:	44818000 */ 	mtc1	$at,$f16
/*  f0fd114:	c6d20010 */ 	lwc1	$f18,0x10($s6)
/*  f0fd118:	92220017 */ 	lbu	$v0,0x17($s1)
/*  f0fd11c:	240f00ff */ 	li	$t7,0xff
/*  f0fd120:	46109182 */ 	mul.s	$f6,$f18,$f16
/*  f0fd124:	284100ff */ 	slti	$at,$v0,0xff
/*  f0fd128:	01e2c023 */ 	subu	$t8,$t7,$v0
/*  f0fd12c:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f0fd130:	44034000 */ 	mfc1	$v1,$f8
/*  f0fd134:	10200019 */ 	beqz	$at,.JF0f0fd19c
/*  f0fd138:	0078082a */ 	slt	$at,$v1,$t8
/*  f0fd13c:	10200005 */ 	beqz	$at,.JF0f0fd154
/*  f0fd140:	240c00ff */ 	li	$t4,0xff
/*  f0fd144:	0043c821 */ 	addu	$t9,$v0,$v1
/*  f0fd148:	a2390017 */ 	sb	$t9,0x17($s1)
/*  f0fd14c:	10000013 */ 	b	.JF0f0fd19c
/*  f0fd150:	332200ff */ 	andi	$v0,$t9,0xff
.JF0f0fd154:
/*  f0fd154:	a22c0017 */ 	sb	$t4,0x17($s1)
/*  f0fd158:	10000010 */ 	b	.JF0f0fd19c
/*  f0fd15c:	318200ff */ 	andi	$v0,$t4,0xff
.JF0f0fd160:
/*  f0fd160:	c6ca0010 */ 	lwc1	$f10,0x10($s6)
/*  f0fd164:	44812000 */ 	mtc1	$at,$f4
/*  f0fd168:	92220017 */ 	lbu	$v0,0x17($s1)
/*  f0fd16c:	46045482 */ 	mul.s	$f18,$f10,$f4
/*  f0fd170:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f0fd174:	44038000 */ 	mfc1	$v1,$f16
/*  f0fd178:	18400008 */ 	blez	$v0,.JF0f0fd19c
/*  f0fd17c:	0062082a */ 	slt	$at,$v1,$v0
/*  f0fd180:	10200004 */ 	beqz	$at,.JF0f0fd194
/*  f0fd184:	00435823 */ 	subu	$t3,$v0,$v1
/*  f0fd188:	a22b0017 */ 	sb	$t3,0x17($s1)
/*  f0fd18c:	10000003 */ 	b	.JF0f0fd19c
/*  f0fd190:	316200ff */ 	andi	$v0,$t3,0xff
.JF0f0fd194:
/*  f0fd194:	a2200017 */ 	sb	$zero,0x17($s1)
/*  f0fd198:	300200ff */ 	andi	$v0,$zero,0xff
.JF0f0fd19c:
/*  f0fd19c:	18400092 */ 	blez	$v0,.JF0f0fd3e8
/*  f0fd1a0:	3c0141a0 */ 	lui	$at,0x41a0
/*  f0fd1a4:	44816000 */ 	mtc1	$at,$f12
/*  f0fd1a8:	0fc01ae2 */ 	jal	menuGetSinOscFrac
/*  f0fd1ac:	00000000 */ 	nop
/*  f0fd1b0:	3c01437f */ 	lui	$at,0x437f
/*  f0fd1b4:	44813000 */ 	mtc1	$at,$f6
/*  f0fd1b8:	240e0001 */ 	li	$t6,0x1
/*  f0fd1bc:	3c014f00 */ 	lui	$at,0x4f00
/*  f0fd1c0:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f0fd1c4:	240451e2 */ 	li	$a0,0x51e2
/*  f0fd1c8:	444df800 */ 	cfc1	$t5,$31
/*  f0fd1cc:	44cef800 */ 	ctc1	$t6,$31
/*  f0fd1d0:	00000000 */ 	nop
/*  f0fd1d4:	460042a4 */ 	cvt.w.s	$f10,$f8
/*  f0fd1d8:	444ef800 */ 	cfc1	$t6,$31
/*  f0fd1dc:	00000000 */ 	nop
/*  f0fd1e0:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0fd1e4:	51c00013 */ 	beqzl	$t6,.JF0f0fd234
/*  f0fd1e8:	440e5000 */ 	mfc1	$t6,$f10
/*  f0fd1ec:	44815000 */ 	mtc1	$at,$f10
/*  f0fd1f0:	240e0001 */ 	li	$t6,0x1
/*  f0fd1f4:	460a4281 */ 	sub.s	$f10,$f8,$f10
/*  f0fd1f8:	44cef800 */ 	ctc1	$t6,$31
/*  f0fd1fc:	00000000 */ 	nop
/*  f0fd200:	460052a4 */ 	cvt.w.s	$f10,$f10
/*  f0fd204:	444ef800 */ 	cfc1	$t6,$31
/*  f0fd208:	00000000 */ 	nop
/*  f0fd20c:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f0fd210:	15c00005 */ 	bnez	$t6,.JF0f0fd228
/*  f0fd214:	00000000 */ 	nop
/*  f0fd218:	440e5000 */ 	mfc1	$t6,$f10
/*  f0fd21c:	3c018000 */ 	lui	$at,0x8000
/*  f0fd220:	10000007 */ 	b	.JF0f0fd240
/*  f0fd224:	01c17025 */ 	or	$t6,$t6,$at
.JF0f0fd228:
/*  f0fd228:	10000005 */ 	b	.JF0f0fd240
/*  f0fd22c:	240effff */ 	li	$t6,-1
/*  f0fd230:	440e5000 */ 	mfc1	$t6,$f10
.JF0f0fd234:
/*  f0fd234:	00000000 */ 	nop
/*  f0fd238:	05c0fffb */ 	bltz	$t6,.JF0f0fd228
/*  f0fd23c:	00000000 */ 	nop
.JF0f0fd240:
/*  f0fd240:	44cdf800 */ 	ctc1	$t5,$31
/*  f0fd244:	0fc5baa5 */ 	jal	langGet
/*  f0fd248:	afae00a0 */ 	sw	$t6,0xa0($sp)
/*  f0fd24c:	02802025 */ 	move	$a0,$s4
/*  f0fd250:	00402825 */ 	move	$a1,$v0
/*  f0fd254:	0c004d95 */ 	jal	sprintf
/*  f0fd258:	26460001 */ 	addiu	$a2,$s2,0x1
/*  f0fd25c:	2a410002 */ 	slti	$at,$s2,0x2
/*  f0fd260:	10200005 */ 	beqz	$at,.JF0f0fd278
/*  f0fd264:	8fb900e4 */ 	lw	$t9,0xe4($sp)
/*  f0fd268:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f0fd26c:	25f80002 */ 	addiu	$t8,$t7,0x2
/*  f0fd270:	10000003 */ 	b	.JF0f0fd280
/*  f0fd274:	afb800a8 */ 	sw	$t8,0xa8($sp)
.JF0f0fd278:
/*  f0fd278:	272cfff7 */ 	addiu	$t4,$t9,-9
/*  f0fd27c:	afac00a8 */ 	sw	$t4,0xa8($sp)
.JF0f0fd280:
/*  f0fd280:	24010001 */ 	li	$at,0x1
/*  f0fd284:	12410004 */ 	beq	$s2,$at,.JF0f0fd298
/*  f0fd288:	8faa00e8 */ 	lw	$t2,0xe8($sp)
/*  f0fd28c:	24010003 */ 	li	$at,0x3
/*  f0fd290:	16410006 */ 	bne	$s2,$at,.JF0f0fd2ac
/*  f0fd294:	8faf00f0 */ 	lw	$t7,0xf0($sp)
.JF0f0fd298:
/*  f0fd298:	8fab00dc */ 	lw	$t3,0xdc($sp)
/*  f0fd29c:	014b6823 */ 	subu	$t5,$t2,$t3
/*  f0fd2a0:	25aefffe */ 	addiu	$t6,$t5,-2
/*  f0fd2a4:	10000003 */ 	b	.JF0f0fd2b4
/*  f0fd2a8:	afae00ac */ 	sw	$t6,0xac($sp)
.JF0f0fd2ac:
/*  f0fd2ac:	25f80002 */ 	addiu	$t8,$t7,0x2
/*  f0fd2b0:	afb800ac */ 	sw	$t8,0xac($sp)
.JF0f0fd2b4:
/*  f0fd2b4:	0c002eeb */ 	jal	viGetWidth
/*  f0fd2b8:	00000000 */ 	nop
/*  f0fd2bc:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fd2c0:	0010cc03 */ 	sra	$t9,$s0,0x10
/*  f0fd2c4:	0c002eef */ 	jal	viGetHeight
/*  f0fd2c8:	03208025 */ 	move	$s0,$t9
/*  f0fd2cc:	922b0017 */ 	lbu	$t3,0x17($s1)
/*  f0fd2d0:	3c0c8008 */ 	lui	$t4,0x8008
/*  f0fd2d4:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0fd2d8:	3c015070 */ 	lui	$at,0x5070
/*  f0fd2dc:	8d4a0148 */ 	lw	$t2,0x148($t2)
/*  f0fd2e0:	8d8c014c */ 	lw	$t4,0x14c($t4)
/*  f0fd2e4:	3421ff00 */ 	ori	$at,$at,0xff00
/*  f0fd2e8:	01616825 */ 	or	$t5,$t3,$at
/*  f0fd2ec:	afad0018 */ 	sw	$t5,0x18($sp)
/*  f0fd2f0:	02a02025 */ 	move	$a0,$s5
/*  f0fd2f4:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f0fd2f8:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f0fd2fc:	02803825 */ 	move	$a3,$s4
/*  f0fd300:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0fd304:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0fd308:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0fd30c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0fd310:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f0fd314:	0fc55886 */ 	jal	textRenderProjected
/*  f0fd318:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f0fd31c:	8ece0490 */ 	lw	$t6,0x490($s6)
/*  f0fd320:	24010002 */ 	li	$at,0x2
/*  f0fd324:	0040a825 */ 	move	$s5,$v0
/*  f0fd328:	15c1000b */ 	bne	$t6,$at,.JF0f0fd358
/*  f0fd32c:	02d27821 */ 	addu	$t7,$s6,$s2
/*  f0fd330:	81f80494 */ 	lb	$t8,0x494($t7)
/*  f0fd334:	13000008 */ 	beqz	$t8,.JF0f0fd358
/*  f0fd338:	00000000 */ 	nop
/*  f0fd33c:	0fc5baa5 */ 	jal	langGet
/*  f0fd340:	240458ca */ 	li	$a0,0x58ca
/*  f0fd344:	02802025 */ 	move	$a0,$s4
/*  f0fd348:	0c004c34 */ 	jal	strcpy
/*  f0fd34c:	00402825 */ 	move	$a1,$v0
/*  f0fd350:	1000000d */ 	b	.JF0f0fd388
/*  f0fd354:	2403ffff */ 	li	$v1,-1
.JF0f0fd358:
/*  f0fd358:	0fc5baa5 */ 	jal	langGet
/*  f0fd35c:	240451e3 */ 	li	$a0,0x51e3
/*  f0fd360:	02802025 */ 	move	$a0,$s4
/*  f0fd364:	0c004c34 */ 	jal	strcpy
/*  f0fd368:	00402825 */ 	move	$a1,$v0
/*  f0fd36c:	3c0400ff */ 	lui	$a0,0xff
/*  f0fd370:	3484ff00 */ 	ori	$a0,$a0,0xff00
/*  f0fd374:	2405ff00 */ 	li	$a1,-256
/*  f0fd378:	0fc01a60 */ 	jal	colourBlend
/*  f0fd37c:	8fa600a0 */ 	lw	$a2,0xa0($sp)
/*  f0fd380:	92390017 */ 	lbu	$t9,0x17($s1)
/*  f0fd384:	03221825 */ 	or	$v1,$t9,$v0
.JF0f0fd388:
/*  f0fd388:	0c002eeb */ 	jal	viGetWidth
/*  f0fd38c:	afa300a4 */ 	sw	$v1,0xa4($sp)
/*  f0fd390:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fd394:	00106403 */ 	sra	$t4,$s0,0x10
/*  f0fd398:	0c002eef */ 	jal	viGetHeight
/*  f0fd39c:	01808025 */ 	move	$s0,$t4
/*  f0fd3a0:	3c0a8008 */ 	lui	$t2,0x8008
/*  f0fd3a4:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0fd3a8:	8d6b0148 */ 	lw	$t3,0x148($t3)
/*  f0fd3ac:	8d4a014c */ 	lw	$t2,0x14c($t2)
/*  f0fd3b0:	8fa300a4 */ 	lw	$v1,0xa4($sp)
/*  f0fd3b4:	02a02025 */ 	move	$a0,$s5
/*  f0fd3b8:	27a500ac */ 	addiu	$a1,$sp,0xac
/*  f0fd3bc:	27a600a8 */ 	addiu	$a2,$sp,0xa8
/*  f0fd3c0:	02803825 */ 	move	$a3,$s4
/*  f0fd3c4:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f0fd3c8:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f0fd3cc:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f0fd3d0:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f0fd3d4:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f0fd3d8:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f0fd3dc:	0fc55886 */ 	jal	textRenderProjected
/*  f0fd3e0:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f0fd3e4:	0040a825 */ 	move	$s5,$v0
.JF0f0fd3e8:
/*  f0fd3e8:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f0fd3ec:	24010004 */ 	li	$at,0x4
/*  f0fd3f0:	5641fef8 */ 	bnel	$s2,$at,.JF0f0fcfd4
/*  f0fd3f4:	8ec20490 */ 	lw	$v0,0x490($s6)
/*  f0fd3f8:	0fc54bb7 */ 	jal	text0f153780
/*  f0fd3fc:	02a02025 */ 	move	$a0,$s5
/*  f0fd400:	0040a825 */ 	move	$s5,$v0
/*  f0fd404:	02a01025 */ 	move	$v0,$s5
.JF0f0fd408:
/*  f0fd408:	3c0db700 */ 	lui	$t5,0xb700
/*  f0fd40c:	240e0001 */ 	li	$t6,0x1
/*  f0fd410:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f0fd414:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f0fd418:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f0fd41c:	82ef001b */ 	lb	$t7,0x1b($s7)
.JF0f0fd420:
/*  f0fd420:	2401ffff */ 	li	$at,-1
/*  f0fd424:	11e100a1 */ 	beq	$t7,$at,.JF0f0fd6ac
/*  f0fd428:	00000000 */ 	nop
/*  f0fd42c:	0c002f29 */ 	jal	viGetViewLeft
/*  f0fd430:	00000000 */ 	nop
/*  f0fd434:	3c188008 */ 	lui	$t8,0x8008
/*  f0fd438:	8f1800f4 */ 	lw	$t8,0xf4($t8)
/*  f0fd43c:	0058001a */ 	div	$zero,$v0,$t8
/*  f0fd440:	0000c812 */ 	mflo	$t9
/*  f0fd444:	afb90098 */ 	sw	$t9,0x98($sp)
/*  f0fd448:	17000002 */ 	bnez	$t8,.JF0f0fd454
/*  f0fd44c:	00000000 */ 	nop
/*  f0fd450:	0007000d */ 	break	0x7
.JF0f0fd454:
/*  f0fd454:	2401ffff */ 	li	$at,-1
/*  f0fd458:	17010004 */ 	bne	$t8,$at,.JF0f0fd46c
/*  f0fd45c:	3c018000 */ 	lui	$at,0x8000
/*  f0fd460:	14410002 */ 	bne	$v0,$at,.JF0f0fd46c
/*  f0fd464:	00000000 */ 	nop
/*  f0fd468:	0006000d */ 	break	0x6
.JF0f0fd46c:
/*  f0fd46c:	0c002f2d */ 	jal	viGetViewTop
/*  f0fd470:	00000000 */ 	nop
/*  f0fd474:	0c002f29 */ 	jal	viGetViewLeft
/*  f0fd478:	afa20094 */ 	sw	$v0,0x94($sp)
/*  f0fd47c:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fd480:	00106403 */ 	sra	$t4,$s0,0x10
/*  f0fd484:	0c002f0b */ 	jal	viGetViewWidth
/*  f0fd488:	01808025 */ 	move	$s0,$t4
/*  f0fd48c:	3c0b8008 */ 	lui	$t3,0x8008
/*  f0fd490:	8d6b00f4 */ 	lw	$t3,0xf4($t3)
/*  f0fd494:	00505021 */ 	addu	$t2,$v0,$s0
/*  f0fd498:	014b001a */ 	div	$zero,$t2,$t3
/*  f0fd49c:	0000a012 */ 	mflo	$s4
/*  f0fd4a0:	15600002 */ 	bnez	$t3,.JF0f0fd4ac
/*  f0fd4a4:	00000000 */ 	nop
/*  f0fd4a8:	0007000d */ 	break	0x7
.JF0f0fd4ac:
/*  f0fd4ac:	2401ffff */ 	li	$at,-1
/*  f0fd4b0:	15610004 */ 	bne	$t3,$at,.JF0f0fd4c4
/*  f0fd4b4:	3c018000 */ 	lui	$at,0x8000
/*  f0fd4b8:	15410002 */ 	bne	$t2,$at,.JF0f0fd4c4
/*  f0fd4bc:	00000000 */ 	nop
/*  f0fd4c0:	0006000d */ 	break	0x6
.JF0f0fd4c4:
/*  f0fd4c4:	0c002f2d */ 	jal	viGetViewTop
/*  f0fd4c8:	00000000 */ 	nop
/*  f0fd4cc:	00028400 */ 	sll	$s0,$v0,0x10
/*  f0fd4d0:	00106c03 */ 	sra	$t5,$s0,0x10
/*  f0fd4d4:	0c002f0f */ 	jal	viGetViewHeight
/*  f0fd4d8:	01a08025 */ 	move	$s0,$t5
/*  f0fd4dc:	8ec7006c */ 	lw	$a3,0x6c($s6)
/*  f0fd4e0:	00504821 */ 	addu	$t1,$v0,$s0
/*  f0fd4e4:	00009025 */ 	move	$s2,$zero
/*  f0fd4e8:	10e00003 */ 	beqz	$a3,.JF0f0fd4f8
/*  f0fd4ec:	00009825 */ 	move	$s3,$zero
/*  f0fd4f0:	10000002 */ 	b	.JF0f0fd4fc
/*  f0fd4f4:	24080001 */ 	li	$t0,0x1
.JF0f0fd4f8:
/*  f0fd4f8:	00004025 */ 	move	$t0,$zero
.JF0f0fd4fc:
/*  f0fd4fc:	8ec40068 */ 	lw	$a0,0x68($s6)
/*  f0fd500:	50800004 */ 	beqzl	$a0,.JF0f0fd514
/*  f0fd504:	00001825 */ 	move	$v1,$zero
/*  f0fd508:	10000002 */ 	b	.JF0f0fd514
/*  f0fd50c:	24030001 */ 	li	$v1,0x1
/*  f0fd510:	00001825 */ 	move	$v1,$zero
.JF0f0fd514:
/*  f0fd514:	8ec50064 */ 	lw	$a1,0x64($s6)
/*  f0fd518:	50a00004 */ 	beqzl	$a1,.JF0f0fd52c
/*  f0fd51c:	00008825 */ 	move	$s1,$zero
/*  f0fd520:	10000002 */ 	b	.JF0f0fd52c
/*  f0fd524:	24110001 */ 	li	$s1,0x1
/*  f0fd528:	00008825 */ 	move	$s1,$zero
.JF0f0fd52c:
/*  f0fd52c:	8ec60070 */ 	lw	$a2,0x70($s6)
/*  f0fd530:	50c00004 */ 	beqzl	$a2,.JF0f0fd544
/*  f0fd534:	00001025 */ 	move	$v0,$zero
/*  f0fd538:	10000002 */ 	b	.JF0f0fd544
/*  f0fd53c:	24020001 */ 	li	$v0,0x1
/*  f0fd540:	00001025 */ 	move	$v0,$zero
.JF0f0fd544:
/*  f0fd544:	00517021 */ 	addu	$t6,$v0,$s1
/*  f0fd548:	01c37821 */ 	addu	$t7,$t6,$v1
/*  f0fd54c:	01e8c021 */ 	addu	$t8,$t7,$t0
/*  f0fd550:	2b010003 */ 	slti	$at,$t8,0x3
/*  f0fd554:	1420000a */ 	bnez	$at,.JF0f0fd580
/*  f0fd558:	00000000 */ 	nop
/*  f0fd55c:	8ec2028c */ 	lw	$v0,0x28c($s6)
/*  f0fd560:	24010001 */ 	li	$at,0x1
/*  f0fd564:	10410003 */ 	beq	$v0,$at,.JF0f0fd574
/*  f0fd568:	24010003 */ 	li	$at,0x3
/*  f0fd56c:	54410004 */ 	bnel	$v0,$at,.JF0f0fd580
/*  f0fd570:	2412000f */ 	li	$s2,0xf
.JF0f0fd574:
/*  f0fd574:	10000002 */ 	b	.JF0f0fd580
/*  f0fd578:	2413000f */ 	li	$s3,0xf
/*  f0fd57c:	2412000f */ 	li	$s2,0xf
.JF0f0fd580:
/*  f0fd580:	10e00003 */ 	beqz	$a3,.JF0f0fd590
/*  f0fd584:	24010002 */ 	li	$at,0x2
/*  f0fd588:	10000002 */ 	b	.JF0f0fd594
/*  f0fd58c:	24080001 */ 	li	$t0,0x1
.JF0f0fd590:
/*  f0fd590:	00004025 */ 	move	$t0,$zero
.JF0f0fd594:
/*  f0fd594:	10800003 */ 	beqz	$a0,.JF0f0fd5a4
/*  f0fd598:	00001825 */ 	move	$v1,$zero
/*  f0fd59c:	10000001 */ 	b	.JF0f0fd5a4
/*  f0fd5a0:	24030001 */ 	li	$v1,0x1
.JF0f0fd5a4:
/*  f0fd5a4:	10a00003 */ 	beqz	$a1,.JF0f0fd5b4
/*  f0fd5a8:	00008825 */ 	move	$s1,$zero
/*  f0fd5ac:	10000001 */ 	b	.JF0f0fd5b4
/*  f0fd5b0:	24110001 */ 	li	$s1,0x1
.JF0f0fd5b4:
/*  f0fd5b4:	10c00003 */ 	beqz	$a2,.JF0f0fd5c4
/*  f0fd5b8:	00001025 */ 	move	$v0,$zero
/*  f0fd5bc:	10000001 */ 	b	.JF0f0fd5c4
/*  f0fd5c0:	24020001 */ 	li	$v0,0x1
.JF0f0fd5c4:
/*  f0fd5c4:	0051c821 */ 	addu	$t9,$v0,$s1
/*  f0fd5c8:	03236021 */ 	addu	$t4,$t9,$v1
/*  f0fd5cc:	01885021 */ 	addu	$t2,$t4,$t0
/*  f0fd5d0:	55410013 */ 	bnel	$t2,$at,.JF0f0fd620
/*  f0fd5d4:	8ece006c */ 	lw	$t6,0x6c($s6)
/*  f0fd5d8:	0fc54978 */ 	jal	optionsGetScreenSplit
/*  f0fd5dc:	afa9008c */ 	sw	$t1,0x8c($sp)
/*  f0fd5e0:	24010001 */ 	li	$at,0x1
/*  f0fd5e4:	10410006 */ 	beq	$v0,$at,.JF0f0fd600
/*  f0fd5e8:	8fa9008c */ 	lw	$t1,0x8c($sp)
/*  f0fd5ec:	3c0b8009 */ 	lui	$t3,0x8009
/*  f0fd5f0:	916b1160 */ 	lbu	$t3,0x1160($t3)
/*  f0fd5f4:	24010001 */ 	li	$at,0x1
/*  f0fd5f8:	55610009 */ 	bnel	$t3,$at,.JF0f0fd620
/*  f0fd5fc:	8ece006c */ 	lw	$t6,0x6c($s6)
.JF0f0fd600:
/*  f0fd600:	8ecd028c */ 	lw	$t5,0x28c($s6)
/*  f0fd604:	24010001 */ 	li	$at,0x1
/*  f0fd608:	55a10004 */ 	bnel	$t5,$at,.JF0f0fd61c
/*  f0fd60c:	2412000f */ 	li	$s2,0xf
/*  f0fd610:	10000002 */ 	b	.JF0f0fd61c
/*  f0fd614:	2413000f */ 	li	$s3,0xf
/*  f0fd618:	2412000f */ 	li	$s2,0xf
.JF0f0fd61c:
/*  f0fd61c:	8ece006c */ 	lw	$t6,0x6c($s6)
.JF0f0fd620:
/*  f0fd620:	8ec40068 */ 	lw	$a0,0x68($s6)
/*  f0fd624:	8ec50064 */ 	lw	$a1,0x64($s6)
/*  f0fd628:	11c00003 */ 	beqz	$t6,.JF0f0fd638
/*  f0fd62c:	8ec60070 */ 	lw	$a2,0x70($s6)
/*  f0fd630:	10000002 */ 	b	.JF0f0fd63c
/*  f0fd634:	24080001 */ 	li	$t0,0x1
.JF0f0fd638:
/*  f0fd638:	00004025 */ 	move	$t0,$zero
.JF0f0fd63c:
/*  f0fd63c:	10800003 */ 	beqz	$a0,.JF0f0fd64c
/*  f0fd640:	02803825 */ 	move	$a3,$s4
/*  f0fd644:	10000002 */ 	b	.JF0f0fd650
/*  f0fd648:	24030001 */ 	li	$v1,0x1
.JF0f0fd64c:
/*  f0fd64c:	00001825 */ 	move	$v1,$zero
.JF0f0fd650:
/*  f0fd650:	10a00003 */ 	beqz	$a1,.JF0f0fd660
/*  f0fd654:	02a02025 */ 	move	$a0,$s5
/*  f0fd658:	10000002 */ 	b	.JF0f0fd664
/*  f0fd65c:	24110001 */ 	li	$s1,0x1
.JF0f0fd660:
/*  f0fd660:	00008825 */ 	move	$s1,$zero
.JF0f0fd664:
/*  f0fd664:	10c00003 */ 	beqz	$a2,.JF0f0fd674
/*  f0fd668:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f0fd66c:	10000002 */ 	b	.JF0f0fd678
/*  f0fd670:	24020001 */ 	li	$v0,0x1
.JF0f0fd674:
/*  f0fd674:	00001025 */ 	move	$v0,$zero
.JF0f0fd678:
/*  f0fd678:	00517821 */ 	addu	$t7,$v0,$s1
/*  f0fd67c:	01e3c021 */ 	addu	$t8,$t7,$v1
/*  f0fd680:	82ea001b */ 	lb	$t2,0x1b($s7)
/*  f0fd684:	0308c821 */ 	addu	$t9,$t8,$t0
/*  f0fd688:	2b2c0002 */ 	slti	$t4,$t9,0x2
/*  f0fd68c:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f0fd690:	8fa60094 */ 	lw	$a2,0x94($sp)
/*  f0fd694:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f0fd698:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f0fd69c:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f0fd6a0:	0fc3c68e */ 	jal	menuRenderBanner
/*  f0fd6a4:	afaa0018 */ 	sw	$t2,0x18($sp)
/*  f0fd6a8:	0040a825 */ 	move	$s5,$v0
.JF0f0fd6ac:
/*  f0fd6ac:	0fc356a2 */ 	jal	func0f0d49c8
/*  f0fd6b0:	02a02025 */ 	move	$a0,$s5
/*  f0fd6b4:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f0fd6b8:	240b0001 */ 	li	$t3,0x1
/*  f0fd6bc:	3c018008 */ 	lui	$at,0x8008
/*  f0fd6c0:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f0fd6c4:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f0fd6c8:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f0fd6cc:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f0fd6d0:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f0fd6d4:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f0fd6d8:	8fb6004c */ 	lw	$s6,0x4c($sp)
/*  f0fd6dc:	8fb70050 */ 	lw	$s7,0x50($sp)
/*  f0fd6e0:	ac2b00f4 */ 	sw	$t3,0xf4($at)
/*  f0fd6e4:	03e00008 */ 	jr	$ra
/*  f0fd6e8:	27bd0118 */ 	addiu	$sp,$sp,0x118
);
#else
Gfx *menuRender(Gfx *gdl)
{
	static u32 usepiece = 1;

	g_MpPlayerNum = 0;

#if PAL
	g_ScaleX = 1;
#else
	g_ScaleX = g_ViRes == VIRES_HI ? 2 : 1;
#endif

	gdl = func0f0d479c(gdl);

	gSPDisplayList(gdl++, var800613a0);

	// Render the background
	if (g_MenuData.nextbg != 255) {
		if (g_MenuData.nextbg == 0) {
			gdl = menuRenderBackgroundLayer1(gdl, g_MenuData.bg, 1.0f - g_MenuData.unk010);
		} else {
			gdl = menuRenderBackgroundLayer1(gdl, g_MenuData.bg, 1.0f);
			gdl = menuRenderBackgroundLayer1(gdl, g_MenuData.nextbg, g_MenuData.unk010);
		}
	} else {
		gdl = menuRenderBackgroundLayer1(gdl, g_MenuData.bg, 1.0f);
	}

	// Calculate hudpiece things then render it
	if (g_MenuData.unk5d5_05) {
		g_MenuData.unk01c.unk05e = 0;
		g_MenuData.unk01c.unk05c = 0x40d;
		g_MenuData.unk01c.unk580 = 0;
		g_MenuData.unk01c.unk5b1_04 = false;
		g_MenuData.unk5d4 = 1;
		g_MenuData.unk5d5_05 = false;
	}

	if (IS8MB() && g_MenuData.unk5d4) {
		bool removepiece = false;

		gSPSetGeometryMode(gdl++, G_ZBUFFER);

		// Everyone 1 in 100 frames on average, calculate a new X/Y for the hudpiece
		// Note: unintentional 64-bit float comparison done here
		if (RANDOMFRAC() < 0.01) {
			g_MenuData.unk01c.unk538 = RANDOMFRAC() * 80.0f + -205.5f - 40.0f;
			g_MenuData.unk01c.unk53c = RANDOMFRAC() * 80.0f + 244.7f - 40.0f;
		}

		var8009de98 = var8009de9c = 0;

		if (g_MenuData.root == MENUROOT_MPSETUP) {
			if (g_MenuData.count <= 0) {
				removepiece = true;
			}
		}

		if (g_MenuData.root != MENUROOT_MAINMENU
				&& g_MenuData.root != MENUROOT_MPSETUP
				&& g_MenuData.root != MENUROOT_FILEMGR
				&& g_MenuData.root != MENUROOT_TRAINING) {
			removepiece = true;
		}

		if (g_Menus[g_MpPlayerNum].curdialog == NULL) {
			if (g_MenuData.root != MENUROOT_MPSETUP) {
				removepiece = true;
			}
		}

		if (g_Vars.currentplayer->eyespy
				&& (g_Vars.currentplayer->devicesactive & ~g_Vars.currentplayer->devicesinhibit & DEVICE_EYESPY)
				&& g_Vars.currentplayer->eyespy->active) {
			removepiece = true;
		}

		if (removepiece) {
			if (g_MenuData.unk01c.unk580 == 0) {
				g_MenuData.unk01c.unk5b1_04 = true;
				g_MenuData.unk01c.unk05e = 0;
				g_MenuData.unk01c.unk05c = 0x40d;
				g_MenuData.unk01c.unk580 = 1;
			} else if (g_MenuData.unk01c.unk05e == 0) {
				g_MenuData.unk01c.unk580 = 0;
				g_MenuData.unk5d4 = 0;
			}
		}

		mainOverrideVariable("usePiece", &usepiece);

		if (usepiece) {
			g_MenuData.unk5d5_03 = false;

			gdl = menuRenderModels(gdl, &g_MenuData.unk01c, 1);
			gSPClearGeometryMode(gdl++, G_ZBUFFER);

			g_MenuData.unk5d5_03 = true;
		}
	} else {
		var8009de98 = var8009de9c = 0;
	}

	if (g_MenuData.unk5d5_04) {
		var8009de98 = g_MenuData.unk670;
		var8009de9c = g_MenuData.unk674;
	}

	// Render the second layer of the background (for the combat simulator cone,
	// which draws over the top of the hud piece)
	if (g_MenuData.nextbg != 255) {
		if (g_MenuData.nextbg == 0) {
			gdl = menuRenderBackgroundLayer2(gdl, g_MenuData.bg, 1.0f - g_MenuData.unk010);
		} else {
			gdl = menuRenderBackgroundLayer2(gdl, g_MenuData.bg, 1.0f);
			gdl = menuRenderBackgroundLayer2(gdl, g_MenuData.nextbg, g_MenuData.unk010);
		}
	} else {
		gdl = menuRenderBackgroundLayer2(gdl, g_MenuData.bg, 1.0f);
	}

	// Render the health bar (playerRenderHealthBar may choose not to render)
	if ((g_MenuData.bg || g_MenuData.nextbg != 255)
			&& (!g_Vars.currentplayer->eyespy || !g_Vars.currentplayer->eyespy->active)) {
		gdl = func0f0d49c8(gdl);
		gdl = playerRenderHealthBar(gdl);
		gdl = func0f0d479c(gdl);
	}

	if (g_MenuData.count > 0) {
		// Render dialogs
		gdl = text0f153ab0(gdl);

		if (g_MenuData.root == MENUROOT_MPPAUSE || g_MenuData.root == MENUROOT_MPENDSCREEN) {
			g_MpPlayerNum = g_Vars.currentplayerstats->mpindex;
			gdl = menuRenderDialogs(gdl);
		} else {
			s32 i;

			for (i = 0; i < 4; i++) {
				g_MpPlayerNum = i;
				gdl = menuRenderDialogs(gdl);
			}
		}

		g_MpPlayerNum = 0;

		gSPMatrix(gdl++, osVirtualToPhysical(camGetPerspectiveMtxL()), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
		gSPDisplayList(gdl++, var800613a0);

		text0f153b40();

		// Render corner texts in combat simulator
		if (g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU) {
			s32 i;
			s32 j;
			s32 viewleft = viGetViewLeft() / g_ScaleX + 20;
			s32 viewtop = viGetViewTop() + 4;
			s32 viewright = (viGetViewLeft() + viGetViewWidth()) / g_ScaleX - 20;
			s32 viewbottom = viGetViewTop() + viGetViewHeight() - 4;
			s32 textheight;
			s32 textwidth;
			bool renderit;
			char text[32];
			s32 tmp1;
			s32 tmp2;
			s32 x;
			s32 y;
			s32 colour;

			gdl = text0f153628(gdl);

			for (i = 0; i < 4; i++) {
				// Figure out what text will be displayed. The text calculated
				// here is for measuring purposes only and isn't rendered.
				// Amusingly, there's a %d placeholder in the text which isn't
				// replaced prior to measuring, so the width is slightly wrong.
				if (g_Vars.mpsetupmenu == MPSETUPMENU_GENERAL && g_Vars.waitingtojoin[i]) {
					// Player has pressed start but they can't open the player-specific
					// dialog yet because they're still on the Combat Simulator dialog
					// or similar. Show "Ready" in their corner.
					renderit = true;
					// "Player %d: " and "Ready!"
					sprintf(text, "%s%s", langGet(L_MPMENU_482), langGet(L_MISC_461));
				} else {
					if (g_MenuData.root == MENUROOT_4MBMAINMENU) {
						if (g_Vars.mpsetupmenu == MPSETUPMENU_GENERAL) {
							renderit = true;

							for (j = 0; j < 4; j++) {
								if (g_Vars.waitingtojoin[j]) {
									renderit = false;
								}
							}
						} else {
							renderit = g_MpNumJoined < 2;
						}
					} else {
						renderit = true;
					}

					// "Player %d: " and "Press START!"
					sprintf(text, "%s%s", langGet(L_MPMENU_482), langGet(L_MPMENU_483));
				}

				if (renderit) {
					textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, 0);

					// Check which controllers are connected
					// and update the alpha of the label
					if (((g_MpSetup.chrslots | ~joyGetConnectedControllers()) & (1 << i)) == 0) {
#if VERSION >= VERSION_PAL_BETA
						tmp1 = g_Vars.diffframe60freal * 3;
#else
						tmp1 = g_Vars.diffframe60 * 3;
#endif

						if (g_MenuData.playerjoinalpha[i] < 255) {
							if (255 - g_MenuData.playerjoinalpha[i] > tmp1) {
								g_MenuData.playerjoinalpha[i] += tmp1;
							} else {
								g_MenuData.playerjoinalpha[i] = 255;
							}
						}
					} else {
#if VERSION >= VERSION_PAL_BETA
						tmp2 = g_Vars.diffframe60freal * 9;
#else
						tmp2 = g_Vars.diffframe60 * 9;
#endif

						if (g_MenuData.playerjoinalpha[i] > 0) {
							if (g_MenuData.playerjoinalpha[i] > tmp2) {
								g_MenuData.playerjoinalpha[i] -= tmp2;
							} else {
								g_MenuData.playerjoinalpha[i] = 0;
							}
						}
					}

					if (g_MenuData.playerjoinalpha[i] > 0) {
						u32 weight = menuGetSinOscFrac(20) * 255.0f;

						// "Player %d: "
						sprintf(text, langGet(L_MPMENU_482), i + 1);

						if (i < 2) {
							y = viewtop + 2;
						} else {
							y = viewbottom - 9;
						}

						if (i == 1 || i == 3) {
							x = viewright - textwidth - 2;
						} else {
							x = viewleft + 2;
						}

						gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, g_MenuData.playerjoinalpha[i] | 0x5070ff00, viGetWidth(), viGetHeight(), 0, 0);

						if (g_Vars.mpsetupmenu == MPSETUPMENU_GENERAL && g_Vars.waitingtojoin[i]) {
							// "Ready!"
							strcpy(text, langGet(L_MISC_461));
							colour = g_MenuData.playerjoinalpha[i] | 0xd00020ff;
						} else {
							// "Press START!"
							strcpy(text, langGet(L_MPMENU_483));
							colour = colourBlend(0x00ffff00, 0xffffff00, weight) | g_MenuData.playerjoinalpha[i];
						}

						gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicSm, g_FontHandelGothicSm, colour, viGetWidth(), viGetHeight(), 0, 0);
					}
				}
			}

			gdl = text0f153780(gdl);
		}

		gSPSetGeometryMode(gdl++, G_ZBUFFER);
	}

	// Render banner messages, such as "Please Wait...",
	// "Checking Controller Pak" and some unused game boy camera texts.
	if (g_MenuData.bannernum != -1) {
		s32 x1 = viGetViewLeft() / g_ScaleX;
		s32 y1 = viGetViewTop();
		s32 x2 = (viGetViewLeft() + viGetViewWidth()) / g_ScaleX;
		s32 y2 = viGetViewTop() + viGetViewHeight();

#if VERSION >= VERSION_NTSC_1_0
		s32 left = 0;
		s32 right = 0;

		if (PLAYERCOUNT() >= 3) {
			if (g_Vars.currentplayernum == 1 || g_Vars.currentplayernum == 3) {
				right = 15;
			} else {
				left = 15;
			}
		}

		if (PLAYERCOUNT() == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB())) {
			if (g_Vars.currentplayernum == 1) {
				right = 15;
			} else {
				left = 15;
			}
		}

		gdl = menuRenderBanner(gdl, x1, y1, x2, y2, PLAYERCOUNT() < 2, g_MenuData.bannernum, left, right);
#else
		if (PLAYERCOUNT() >= 3) {
			if (g_Vars.currentplayernum == 1 || g_Vars.currentplayernum == 3) {
				x2 -= 10;
			} else {
				x1 += 10;
			}
		}

		if (PLAYERCOUNT() == 2 && (optionsGetScreenSplit() == SCREENSPLIT_VERTICAL || IS4MB())) {
			if (g_Vars.currentplayernum == 1) {
				x2 -= 10;
			} else {
				x1 += 10;
			}
		}

		gdl = menuRenderBanner(gdl, x1, y1, x2, y2, PLAYERCOUNT() < 2, g_MenuData.bannernum);
#endif
	}

	gdl = func0f0d49c8(gdl);

	g_ScaleX = 1;

	return gdl;
}
#endif

const char var7f1b27a4[] = "Tune Selector - mode %d\n";

u32 menuChooseMusic(void)
{
	s32 missionsuccess = MUSIC_MISSION_SUCCESS;

	if (g_StageIndex == STAGEINDEX_DEFENSE) {
		missionsuccess = MUSIC_MISSION_UNKNOWN;
	}

	if (g_MenuData.root == MENUROOT_ENDSCREEN) {
		if (g_Vars.bond->isdead || g_Vars.bond->aborted || !objectiveIsAllComplete()) {
			return MUSIC_MISSION_FAILED;
		}

		return missionsuccess;
	}

	if (g_MenuData.root == MENUROOT_MPENDSCREEN) {
		if (g_Vars.coopplayernum >= 0) {
			if ((g_Vars.bond->isdead && g_Vars.coop->isdead)
					|| g_Vars.bond->aborted
					|| g_Vars.coop->aborted
					|| !objectiveIsAllComplete()) {
				return MUSIC_MISSION_FAILED;
			}

			return missionsuccess;
		}

		if (g_Vars.antiplayernum >= 0) {
			if (g_Vars.bond->isdead || g_Vars.bond->aborted || !objectiveIsAllComplete()) {
				return MUSIC_MISSION_FAILED;
			}

			return missionsuccess;
		}
	}

	if (g_MenuData.root == MENUROOT_FILEMGR) {
		return MUSIC_MAINMENU;
	}

	if (g_MenuData.root == MENUROOT_MPSETUP || g_MenuData.root == MENUROOT_4MBMAINMENU) {
		return MUSIC_COMBATSIM_MENU;
	}

	if (g_MenuData.root == MENUROOT_MPPAUSE) {
		return MUSIC_COMBATSIM_COMPLETE;
	}

	if (g_MenuData.root == MENUROOT_BOOTPAKMGR) {
		return MUSIC_MISSION_UNKNOWN;
	}

	if (g_Vars.mplayerisrunning) {
		return MUSIC_COMBATSIM_COMPLETE;
	}

	if (g_Vars.stagenum == STAGE_CITRAINING || g_Vars.stagenum == STAGE_4MBMENU) {
		return MUSIC_MAINMENU;
	}

	return MUSIC_PAUSEMENU;
}

bool func0f0fcbcc(void)
{
	if (g_FileState == FILESTATE_UNSELECTED && g_Vars.stagenum == STAGE_CITRAINING) {
		return true;
	}

	return false;
}

bool func0f0fcc04(void)
{
	return false;
}

u32 menuGetRoot(void)
{
	if (g_MenuData.count == 0) {
		return 0;
	}

	return g_MenuData.root;
}

#if VERSION >= VERSION_NTSC_1_0
struct menudialogdef g_PakAttemptRepairMenuDialog;

s32 menuhandler000fcc34(s32 operation, struct menuitem *item, union handlerdata *data)
{
	bool done = false;

	if (operation == MENUOP_SET) {
		while (!done) {
			done = true;

			if (g_Menus[g_MpPlayerNum].curdialog) {
				if (g_Menus[g_MpPlayerNum].curdialog->definition == &g_PakRepairSuccessMenuDialog
						|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_PakRemovedMenuDialog
						|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_PakRepairFailedMenuDialog
						|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_PakAttemptRepairMenuDialog
						|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_PakDamagedMenuDialog
						|| g_Menus[g_MpPlayerNum].curdialog->definition == &g_PakFullMenuDialog) {
					done = false;
					menuPopDialog();
				}
			}
		}
	}

	return 0;
}
#endif

s32 menudialog000fcd48(s32 operation, struct menudialogdef *dialogdef, union handlerdata *data)
{
	if (operation == MENUOP_TICK) {
		if (g_Menus[g_MpPlayerNum].curdialog
				&& g_Menus[g_MpPlayerNum].curdialog->definition == dialogdef
				&& joy000155b4(g_Menus[g_MpPlayerNum].fm.device3) == 0) {
			func0f0f3704(&g_PakRemovedMenuDialog);
		}
	}

	return 0;
}

#if VERSION >= VERSION_NTSC_1_0
s32 func0f0fcdd0(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		func0f0f3704(&g_PakDamagedMenuDialog);
	}

	return 0;
}
#endif

s32 menuhandlerRepairPak(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		if (pakRepair(g_Menus[g_MpPlayerNum].fm.device3)) {
			func0f0f3704(&g_PakRepairSuccessMenuDialog);
		} else {
			func0f0f3704(&g_PakRepairFailedMenuDialog);
		}
	}

	return 0;
}

void func0f0fce8c(struct menudialogdef *dialogdef, s32 playernum, s32 arg2)
{
	s32 prevplayernum = g_MpPlayerNum;

	g_MpPlayerNum = playernum;
	g_Menus[g_MpPlayerNum].fm.device3 = arg2;

	if (g_Menus[g_MpPlayerNum].curdialog == NULL) {
		if (PLAYERCOUNT() == 1) {
			menuPushRootDialog(dialogdef, MENUROOT_MAINMENU);
			lvSetPaused(true);
			g_Vars.currentplayer->pausemode = PAUSEMODE_PAUSED;
		} else {
			menuPushRootDialog(dialogdef, MENUROOT_MPPAUSE);
		}
	} else {
		menuPushDialog(dialogdef);
	}

	g_MpPlayerNum = prevplayernum;
}

struct menuitem g_PakRemovedMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPWEAPONS_174, // "The Controller Pak has been removed."
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
#if VERSION >= VERSION_NTSC_1_0
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_073, // "OK"
		0,
		menuhandler000fcc34,
#else
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_073, // "OK"
		0,
		NULL,
#endif
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_PakRemovedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_173, // "Error"
	g_PakRemovedMenuItems,
	NULL,
	0,
	NULL,
};

struct menuitem g_PakRepairSuccessMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPWEAPONS_181, // "The Controller Pak has been repaired."
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
#if VERSION >= VERSION_NTSC_1_0
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_073, // "OK"
		0,
		menuhandler000fcc34,
#else
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_073, // "OK"
		0,
		NULL,
#endif
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_PakRepairSuccessMenuDialog = {
	MENUDIALOGTYPE_SUCCESS,
	L_MPWEAPONS_180, // "Repair Successful"
	g_PakRepairSuccessMenuItems,
	menudialog000fcd48,
	0,
	NULL,
};

struct menuitem g_PakRepairFailedMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPWEAPONS_183, // "The Controller Pak  cannot be repaired. You will not be able to load from or save to this Controller Pak."
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_073, // "OK"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_PakRepairFailedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_182, // "Repair Failed"
	g_PakRepairFailedMenuItems,
	menudialog000fcd48,
	0,
	NULL,
};

struct menuitem g_PakAttemptRepairMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPWEAPONS_176, // "Are you sure you want to attempt repair of this Controller Pak?"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPWEAPONS_177, // "Data may be lost!"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_178, // "Cancel"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_179, // "Repair"
		0,
		menuhandlerRepairPak,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_PakAttemptRepairMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_175, // "Attempt Repair"
	g_PakAttemptRepairMenuItems,
	menudialog000fcd48,
	0,
	NULL,
};

char *menuTextSaveDeviceName(struct menuitem *item)
{
	u16 devices[] = {
		L_OPTIONS_112, // "Controller Pak 1"
		L_OPTIONS_113, // "Controller Pak 2"
		L_OPTIONS_114, // "Controller Pak 3"
		L_OPTIONS_115, // "Controller Pak 4"
#if VERSION >= VERSION_NTSC_1_0
		L_OPTIONS_111, // "Game Pak"
#endif
	};

	if ((u8)g_Menus[g_MpPlayerNum].fm.device3 < ARRAYCOUNT(devices)) {
		return langGet(devices[(u8)g_Menus[g_MpPlayerNum].fm.device3]);
	}

	return NULL;
}

s32 menuhandlerRetrySavePak(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
		menuPopDialog();

#if VERSION >= VERSION_NTSC_1_0
		g_Vars.unk0004e4 &= 0xfff0;
		g_Vars.unk0004e4 |= 8;
		g_Vars.unk0004e4 |= 1 << ((u8)g_Menus[g_MpPlayerNum].fm.device3 + 8);
#else
		pak0f1169c8(g_Menus[g_MpPlayerNum].fm.device3, 0);
#endif
	}

	return 0;
}

s32 menuhandlerWarnRepairPak(s32 operation, struct menuitem *item, union handlerdata *data)
{
	if (operation == MENUOP_SET) {
#if VERSION >= VERSION_NTSC_1_0
		menuPushDialog(&g_PakAttemptRepairMenuDialog);
#else
		func0f0f3704(&g_PakAttemptRepairMenuDialog);
#endif
	}

	return 0;
}

u32 func0f0fd118(u32 playernum)
{
	u32 result = 0;

	if (g_Vars.normmplayerisrunning) {
		if (g_MpSetup.chrslots & (1 << playernum)) {
			result = playernum;
		}
	} else {
		if ((g_Vars.coopplayernum >= 0 || g_Vars.antiplayernum >= 0)
				&& PLAYERCOUNT() >= 2
				&& playernum == 1) {
			result = 1;
		}
	}

	return result;
}

bool func0f0fd1f4(s32 arg0, s32 arg1)
{
	s32 playernum = func0f0fd118(arg0);
	bool result = true;

	if (g_Vars.lvframenum < 20) {
		result = false;
	}

	if (g_FileState == FILESTATE_UNSELECTED) {
		result = false;
	}

	if (g_Vars.stagenum == STAGE_BOOTPAKMENU) {
		result = true;
	}

	if (g_Menus[playernum].curdialog) {
		if (g_Menus[playernum].curdialog->definition == &g_PakDamagedMenuDialog
#if VERSION >= VERSION_NTSC_1_0
				|| g_Menus[playernum].curdialog->definition == &g_PakCannotReadGameBoyMenuDialog
				|| g_Menus[playernum].curdialog->definition == &g_PakDataLostMenuDialog
#endif
				|| g_Menus[playernum].curdialog->definition == &g_PakFullMenuDialog
				|| g_Menus[playernum].curdialog->definition == &g_PakAttemptRepairMenuDialog
				|| g_Menus[playernum].curdialog->definition == &g_PakRemovedMenuDialog
				|| g_Menus[playernum].curdialog->definition == &g_PakRepairSuccessMenuDialog
				|| g_Menus[playernum].curdialog->definition == &g_PakRepairFailedMenuDialog
				) {
			result = false;
		}
	} else if (g_MenuData.nextbg != 255 || g_MenuData.bg || g_MenuData.unk5d4) {
		result = false;
	}

	return result;
}

void func0f0fd320(s32 arg0, s32 arg1)
{
	s32 prevplayernum = g_MpPlayerNum;
	s32 playernum = func0f0fd118(arg0);
	bool found;
	s32 i;

	g_MpPlayerNum = playernum;

	switch (arg1) {
	case 1:
	case 2:
		func0f0fce8c(&g_PakDamagedMenuDialog, playernum, arg0);
		break;
	case 0:
		found = false;

		for (i = 0; i < g_Menus[g_MpPlayerNum].depth; i++) {
			if (g_Menus[g_MpPlayerNum].layers[i].siblings[0]
					&& g_Menus[g_MpPlayerNum].layers[i].siblings[0]->definition == &g_PakChoosePakMenuDialog) {
				found = true;
			}
		}

		if (!found) {
			func0f0fce8c(&g_PakFullMenuDialog, playernum, arg0);
		}
		break;
#if VERSION >= VERSION_NTSC_1_0
	case 3:
		func0f0fce8c(&g_PakCannotReadGameBoyMenuDialog, playernum, arg0);
		break;
	case 4:
		func0f0fce8c(&g_PakDataLostMenuDialog, playernum, arg0);
		break;
#endif
	}

	g_MpPlayerNum = prevplayernum;
}

void func0f0fd494(struct coord *pos)
{
	f32 xy[2];
	struct coord coord;
	Mtxf *matrix;

	g_MenuData.unk5d5_04 = true;

	matrix = camGetWorldToScreenMtxf();

	mtx4TransformVec(matrix, pos, &coord);
	cam0f0b4d04(&coord, xy);

	g_MenuData.unk670 = (s32)xy[0] - viGetWidth() / 2;
	g_MenuData.unk674 = (s32)xy[1] - viGetHeight() / 2;

	g_MenuData.unk5d5_05 = false;
}

void func0f0fd548(s32 arg0)
{
	g_MenuData.unk669[g_MenuData.unk66e++] = arg0;
	g_MenuData.unk66f = 0;
}

struct menudialog *menuIsDialogOpen(struct menudialogdef *dialogdef)
{
	s32 i;
	s32 j;

	if (g_Menus[g_MpPlayerNum].curdialog) {
		for (i = 0; i < g_Menus[g_MpPlayerNum].depth; i++) {
			for (j = 0; j < g_Menus[g_MpPlayerNum].layers[i].numsiblings; j++) {
				if (g_Menus[g_MpPlayerNum].layers[i].siblings[j]
						&& g_Menus[g_MpPlayerNum].layers[i].siblings[j]->definition == dialogdef) {
					return g_Menus[g_MpPlayerNum].layers[i].siblings[j];
				}
			}
		}
	}

	return false;
}

struct menuitem g_PakDamagedMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE,
		(u32)&menuTextSaveDeviceName,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_LESSHEIGHT,
		L_MPWEAPONS_065, // "is damaged or"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_LESSHEIGHT,
		L_MPWEAPONS_066, // "inserted incorrectly."
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000082,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPWEAPONS_067, // "Attempt Repair"
		0,
		menuhandlerWarnRepairPak,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		0,
		L_MPWEAPONS_068, // "Retry"
		0,
		menuhandlerRetrySavePak,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPWEAPONS_069, // "Continue without using the Controller Pak"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_PakDamagedMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_064, // "Damaged Controller Pak"
	g_PakDamagedMenuItems,
	menudialog000fcd48,
#if VERSION >= VERSION_NTSC_1_0
	0x00000020,
#else
	0,
#endif
	NULL,
};

struct menuitem g_PakFullMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE,
		(u32)&menuTextSaveDeviceName,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_LESSHEIGHT,
		L_MPWEAPONS_071, // "is too full to save note - 1 note and 28 pages required to save."
		0,
		NULL,
	},
#if VERSION != VERSION_JPN_FINAL
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_LESSHEIGHT,
		L_OPTIONS_003, // ""
		0,
		NULL,
	},
#endif
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SMALLFONT | MENUITEMFLAG_LESSHEIGHT,
		L_MPWEAPONS_072, // "Enter the Controller Pak Menu to free some space (hold START while powering up.)"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG | MENUITEMFLAG_SELECTABLE_CENTRE,
		L_MPWEAPONS_073, // "OK"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_PakFullMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_070, // "Full Controller Pak"
	g_PakFullMenuItems,
	menudialog000fcd48,
#if VERSION >= VERSION_NTSC_1_0
	0x00000020,
#else
	0,
#endif
	NULL,
};

#if VERSION >= VERSION_NTSC_1_0
struct menuitem g_PakCannotReadGameBoyMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING,
		L_MPWEAPONS_254, // "Cannot read Game Boy Game Pak. Check connections and make sure correct Game Boy Game Pak is being used."
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000082,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPWEAPONS_255, // "Cancel"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_PakCannotReadGameBoyMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_253, // "Error"
	g_PakCannotReadGameBoyMenuItems,
	NULL,
	MENUDIALOGFLAG_IGNOREBACK,
	NULL,
};

struct menuitem g_PakDataLostMenuItems[] = {
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE,
		(u32)&menuTextSaveDeviceName,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_LESSHEIGHT,
		L_MPWEAPONS_257, // "The saved data has"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_LESSHEIGHT,
		L_MPWEAPONS_258, // "been erased due to"
		0,
		NULL,
	},
	{
		MENUITEMTYPE_LABEL,
		0,
		MENUITEMFLAG_LESSLEFTPADDING | MENUITEMFLAG_SELECTABLE_CENTRE | MENUITEMFLAG_LESSHEIGHT,
		L_MPWEAPONS_259, // "corruption or damage."
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SEPARATOR,
		0,
		0,
		0x00000082,
		0,
		NULL,
	},
	{
		MENUITEMTYPE_SELECTABLE,
		0,
		MENUITEMFLAG_SELECTABLE_CLOSESDIALOG,
		L_MPWEAPONS_260, // "Cancel"
		0,
		NULL,
	},
	{ MENUITEMTYPE_END },
};

struct menudialogdef g_PakDataLostMenuDialog = {
	MENUDIALOGTYPE_DANGER,
	L_MPWEAPONS_256, // "Error"
	g_PakDataLostMenuItems,
	NULL,
	MENUDIALOGFLAG_IGNOREBACK,
	NULL,
};
#endif
