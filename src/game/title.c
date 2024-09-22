#include <ultra64.h>
#include "constants.h"
#include "game/title.h"
#include "game/bondgun.h"
#include "game/modelmgr.h"
#include "game/tex.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/game_006900.h"
#include "game/gfxmemory.h"
#include "game/credits.h"
#include "game/bondview.h"
#include "game/text.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/training.h"
#include "game/modeldef.h"
#include "game/lang.h"
#include "game/propobj.h"
#include "game/savebuffer.h"
#include "bss.h"
#include "lib/crash.h"
#include "lib/joy.h"
#include "lib/vi.h"
#include "lib/main.h"
#include "lib/model.h"
#include "lib/snd.h"
#include "lib/mtx.h"
#include "lib/lib_317f0.h"
#include "data.h"
#include "types.h"
#include "string.h"

u8 *var8009cca0;
u32 var8009cca4;
Vtx *g_PdLogoVertices[NUM_FRAMEBUFFERS];
Col *g_PdLogoColours[NUM_FRAMEBUFFERS];
s32 g_PdLogoVtxColIndex;

#if VERSION == VERSION_JPN_FINAL
f32 var8009d34cjf;
f32 var8009d350jf;
f32 var8009d358jf[4];
#endif

s16 g_TitleViewHeight = 480;
bool g_IsTitleDemo = false;
bool g_TitleButtonPressed = false;
bool g_TitleFastForward = false;
u32 g_TitleIdleTime60 = 0;
s32 g_TitleMode = -1;
s32 g_TitleNextMode = -1;
u32 g_TitleDelayedTimer = 2;
s32 g_TitleDelayedMode = -1;
s32 g_TitleTimer = 0;
u32 var800624c8 = 0x00000000;
u32 var800624cc = 0x00000000;
u32 var800624d0 = 0x00000000;
u32 var800624d4 = 0x00000000;
u32 var800624d8 = 0x00000000;
u32 var800624dc = 0x00000000;
u32 var800624e0 = 0x00000000;
s32 g_TitleNextStage = -1; // appears to be used for more than just title
s32 var800624e8 = 1;
u32 var800624ec = 0x00000001;
u32 var800624f0 = 0x00000000;
s32 var800624f4 = 1;
struct model *g_TitleModel = NULL;
struct model *g_TitleModelNLogo2 = NULL;
u32 var80062500 = 0x00000000;
u32 var80062504 = 0x00000000;
struct model *g_TitleModelPdTwo = NULL;
struct model *g_TitleModelPdThree = NULL;

#if VERSION == VERSION_JPN_FINAL
u32 var800623f0jf = 0;
struct model *g_TitleModelJpnLogo1 = NULL;
struct model *g_TitleModelJpnLogo2 = NULL;
struct model *g_TitleModelJpnPd = NULL;
#endif

u32 var80062510 = 0x00000000;
u32 var80062514 = 0x00000000;

Lights1 var80062518 = gdSPDefLights1(0x96, 0x96, 0x96, 0xff, 0xff, 0xff, 0x4d, 0x4d, 0x2e);
Lights1 g_TitleLightPdLogoFront = gdSPDefLights1(0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
Lights1 var80062548 = gdSPDefLights1(0x3f, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
Lights1 g_TitleLightPdLogoNotFront = gdSPDefLights1(0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);

#if VERSION == VERSION_JPN_FINAL
Lights1 g_TitleLightPdLogoJpn = gdSPDefLights1(0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
#endif

Lights1 g_TitleLightPdLogoMain = gdSPDefLights1(0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f);
Lights1 g_TitleLightNintendoRare = gdSPDefLights1(0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
Lights1 var800625a8 = gdSPDefLights1(0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f);
Lights1 var800625c0 = gdSPDefLights1(0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f);
Lights1 var800625d8 = gdSPDefLights1(0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f);

#if VERSION == VERSION_JPN_FINAL
Lights1 var800624f8jf = gdSPDefLights1(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f);
Lights1 var80062510jf = gdSPDefLights1(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f);
#endif

void title_skip_to_pd_title(void);

char *mp_player_get_weapon_of_choice_name(u32 playernum, u32 slot)
{
	char *name;
	s32 weapon1;
	s32 weapon2;
	u32 prevplayernum = g_Vars.currentplayernum;
	s32 weapon;

	set_current_player_num(playernum);

	inv_get_weapon_of_choice(&weapon1, &weapon2);

	weapon = slot == 1 ? weapon2 : weapon1;

	name = bgun_get_name(weapon);
	set_current_player_num(prevplayernum);

	return name;
}

void title_set_light(Lights1 *light, u8 r, u8 g, u8 b, f32 luminosity, struct coord *dir)
{
	light->a.l.col[0] = r * luminosity;
	light->a.l.col[1] = g * luminosity;
	light->a.l.col[2] = b * luminosity;

	light->a.l.colc[0] = r * luminosity;
	light->a.l.colc[1] = g * luminosity;
	light->a.l.colc[2] = b * luminosity;

	light->l[0].l.col[0] = r;
	light->l[0].l.col[1] = g;
	light->l[0].l.col[2] = b;

	light->l[0].l.colc[0] = r;
	light->l[0].l.colc[1] = g;
	light->l[0].l.colc[2] = b;

	light->l[0].l.dir[0] = dir->x * 127.0f;
	light->l[0].l.dir[1] = dir->y * 127.0f;
	light->l[0].l.dir[2] = dir->z * 127.0f;
}

void title_init_legal(void)
{
	music_queue_stop_all_event();
	var800624f4 = 1;
	g_TitleTimer = 0;
	g_TitleButtonPressed = false;
	g_TitleFastForward = false;

#if VERSION == VERSION_PAL_BETA
	// Play a sound if player has successfully enabled the crash screen.
	// This is done in main_init by holding all four C buttons.
	if (g_CrashEnabled) {
		snd_start(var80095200, SFX_8113, 0, -1, -1, -1.0f, -1, -1);
	}
#endif
}

void title_exit_legal(void)
{
	// empty
}

void title_tick_legal(void)
{
	vi_set_fov_y(60);
	vi_set_aspect(1.33333333f);
	vi_set_z_range(100, 10000);
	vi_set_use_z_buf(false);

	g_TitleTimer += g_Vars.lvupdate60;

	if (g_TitleTimer > TICKS(180)) {
		title_set_next_mode(TITLEMODE_CHECKCONTROLLERS);
	}
}

void title_init_check_controllers(void)
{
	g_TitleTimer = 0;
	vi_black(true);
}

void title_exit_check_controllers(void)
{
	var800624e8 = 0;
	vi_configure_for_logos();
	vi_set_mode(VIMODE_HI);
	vi_black(false);
}

void title_tick_check_controllers(void)
{
	g_TitleTimer++;
	vi_set_z_range(100, 10000);
	vi_set_use_z_buf(false);

	if (g_TitleTimer > 6) {
		if ((joy_get_connected_controllers() & 1) == 0) {
			title_set_next_mode(TITLEMODE_NOCONTROLLER);
		} else {
			title_set_next_mode(TITLEMODE_RARELOGO);
		}
	}
}

Gfx *title_render_check_controllers(Gfx *gdl)
{
	if (g_TitleTimer > 2 && g_TitleTimer < 6) {
		gdl = title_clear(gdl);
	}

	return gdl;
}

Gfx *title0f0165f0(Gfx *gdl, s32 xcentre, s32 ycentre, s32 xscale, s32 yscale, char *text, struct fontchar *font1, struct font *font2, s32 colour)
{
	s32 textheight;
	s32 textwidth;
	s32 x;
	s32 y;

	textwidth = 0;
	textheight = 0;

	text_measure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = xcentre - xscale * textwidth / 2;
	y = ycentre - yscale * textheight / 2;

	gdl = text_render_v2(gdl, &x, &y, text, font1, font2, colour, vi_get_width(), vi_get_height(), 0, 0);

	return gdl;
}

bool g_LegalEnabled;

#define LEGALELEMENTTYPE_BLUETEXTSM  0
#define LEGALELEMENTTYPE_BLUETEXTMD  1
#define LEGALELEMENTTYPE_BLUETEXTLG  2
#define LEGALELEMENTTYPE_LINE        3
#define LEGALELEMENTTYPE_DOLBYLOGO   4
#define LEGALELEMENTTYPE_WHITETEXTLG 5
#define LEGALELEMENTTYPE_WHITETEXTSM 6
#define LEGALELEMENTTYPE_RARELOGO    7

struct legalelement {
	s16 x;
	s16 y;
	s16 unused04;
	s16 unused06;
	s16 type;
	u16 textid;
};

struct legalelement g_LegalElements[] = {
#if VERSION == VERSION_JPN_FINAL
	{ 49,  163, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_077   }, // "Nintendo 64 Product Identification"
	{ 49,  184, 1, 1, LEGALELEMENTTYPE_LINE,        0               },
	{ 69,  191, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_078   }, // "Product ID:"
	{ 69,  211, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_079   }, // "Product Code:"
	{ 69,  231, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_080   }, // "Variant:"
	{ 69,  251, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_081   }, // "Developer:"
	{ 249, 191, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_082   }, // "Perfect Dark"
	{ 249, 211, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_083   }, // "NUS-NPDE-USA"
	{ 249, 231, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_084   }, // "NTSC version 8.7 final"
	{ 249, 251, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_085   }, // "Rare Ltd. (twycross)"
	{ 69,  274, 1, 1, LEGALELEMENTTYPE_LINE,        0               },
	{ 69,  283, 0, 1, LEGALELEMENTTYPE_WHITETEXTLG, L_OPTIONS_076   }, // "N64 EXPANSION PAK"
	{ -1,  283, 0, 1, LEGALELEMENTTYPE_WHITETEXTLG, L_OPTIONS_074   }, // "NOT DETECTED"
	{ 69,  304, 1, 1, LEGALELEMENTTYPE_LINE,        0               },
	{ 69,  312, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_OPTIONS_087   }, // "The Rarewere Logo and Perfect Dark are ..."
	{ 69,  328, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_MPWEAPONS_280 }, // "Perfect Dark Registered Trademark No..."
	{ 138, 343, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_OPTIONS_088   }, // "Presented in Dolby Surround. Dolby and ..."
	{ 69,  372, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_OPTIONS_089   }, // "Uses Miles Sound System ..."
	{ 69,  428, 1, 1, LEGALELEMENTTYPE_LINE,        0               },
	{ 69,  433, 0, 1, LEGALELEMENTTYPE_BLUETEXTSM,  L_OPTIONS_093   }, // "rare designs on the future <<<"
	{ 69,  343, 0, 1, LEGALELEMENTTYPE_DOLBYLOGO,   0               },
#else
	{ 49,  179, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_077 }, // "Nintendo 64 Product Identification"
	{ 49,  200, 1, 1, LEGALELEMENTTYPE_LINE,        0             },
	{ 69,  207, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_078 }, // "Product ID:"
	{ 69,  227, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_079 }, // "Product Code:"
	{ 69,  247, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_080 }, // "Variant:"
	{ 69,  267, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_081 }, // "Developer:"
	{ 249, 207, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_082 }, // "Perfect Dark"
	{ 249, 227, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_083 }, // "NUS-NPDE-USA"
	{ 249, 247, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_084 }, // "NTSC version 8.7 final"
	{ 249, 267, 1, 1, LEGALELEMENTTYPE_BLUETEXTLG,  L_OPTIONS_085 }, // "Rare Ltd. (twycross)"
	{ 69,  290, 1, 1, LEGALELEMENTTYPE_LINE,        0             },
	{ 69,  299, 0, 1, LEGALELEMENTTYPE_WHITETEXTLG, L_OPTIONS_076 }, // "N64 EXPANSION PAK"
#if VERSION >= VERSION_PAL_BETA
	{ -1,  296, 0, 1, LEGALELEMENTTYPE_WHITETEXTSM, L_OPTIONS_075 }, // "tm"
	{ -1,  299, 0, 1, LEGALELEMENTTYPE_WHITETEXTLG, L_OPTIONS_074 }, // "NOT DETECTED"
#else
	{ 266, 296, 0, 1, LEGALELEMENTTYPE_WHITETEXTSM, L_OPTIONS_075 }, // "tm"
	{ 286, 299, 0, 1, LEGALELEMENTTYPE_WHITETEXTLG, L_OPTIONS_074 }, // "NOT DETECTED"
#endif
	{ 69,  320, 1, 1, LEGALELEMENTTYPE_LINE,        0             },
	{ 69,  328, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_OPTIONS_087 }, // "The Rarewere Logo and Perfect Dark are ..."
	{ 138, 343, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_OPTIONS_088 }, // "Presented in Dolby Surround. Dolby and ..."
	{ 69,  372, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_OPTIONS_089 }, // "Uses Miles Sound System ..."
	{ 69,  428, 1, 1, LEGALELEMENTTYPE_LINE,        0             },
	{ 69,  433, 0, 1, LEGALELEMENTTYPE_BLUETEXTSM,  L_OPTIONS_093 }, // "rare designs on the future <<<"
	{ 69,  344, 0, 1, LEGALELEMENTTYPE_DOLBYLOGO,   0             },
#endif
};

Gfx *title_render_legal(Gfx *gdl)
{
#if VERSION >= VERSION_PAL_BETA
	s32 prevx = 0;
#endif
	struct legalelement *elem;
	struct legalelement *end;
	struct modelrenderdata renderdata = { NULL, true, 3 };
	s32 x;
	s32 y;
	struct fontchar *font1;
	struct font *font2;

	if (g_LegalEnabled) {
		gdl = title_clear(gdl);
#if VERSION == VERSION_JPN_FINAL
		gdl = func0f0d479c(gdl);
#endif
		gdl = text_begin(gdl);

		elem = g_LegalElements;
		end = &g_LegalElements[ARRAYCOUNT(g_LegalElements)];

		for (; elem < end; elem++) {
			u32 colour = 0x7f7fffff;

			switch (elem->type) {
			case LEGALELEMENTTYPE_BLUETEXTSM:
				font1 = g_CharsHandelGothicSm;
				font2 = g_FontHandelGothicSm;
				break;
			case LEGALELEMENTTYPE_BLUETEXTMD:
				font1 = g_CharsHandelGothicMd;
				font2 = g_FontHandelGothicMd;
				break;
			case LEGALELEMENTTYPE_BLUETEXTLG:
				font1 = g_CharsHandelGothicLg;
				font2 = g_FontHandelGothicLg;
				break;
			case LEGALELEMENTTYPE_WHITETEXTLG:
				font1 = g_CharsHandelGothicLg;
				font2 = g_FontHandelGothicLg;
				colour = 0xffffffff;

				if (elem->textid == L_OPTIONS_074 || elem->textid == L_OPTIONS_073) {
#if VERSION >= VERSION_PAL_BETA
					prevx += 10;
#endif

					if (IS4MB()) {
						elem->textid = L_OPTIONS_074;
					} else {
						elem->textid = L_OPTIONS_073;
					}
				}
				break;
			case LEGALELEMENTTYPE_WHITETEXTSM:
				font1 = g_CharsHandelGothicSm;
				font2 = g_FontHandelGothicSm;
				colour = 0xffffffff;
				break;
			default:
				font1 = g_CharsHandelGothicLg;
				font2 = g_FontHandelGothicLg;
				break;
			}

			if (elem->type == LEGALELEMENTTYPE_LINE) {
				gdl = text_end(gdl);
#if VERSION == VERSION_JPN_FINAL
				gdl = text_draw_box(gdl, elem->x, elem->y - 1, vi_get_width(), elem->y + 1, 0x7f7fff7f);
#else
				gdl = text_draw_box(gdl, elem->x, elem->y, vi_get_width(), elem->y + 2, 0x7f7fff7f);
#endif
				gdl = text_begin(gdl);
			} else if (elem->type == LEGALELEMENTTYPE_DOLBYLOGO) {
				gdl = text_end(gdl);

				gDPPipeSync(gdl++);
				gDPSetTexturePersp(gdl++, G_TP_NONE);
				gDPSetAlphaCompare(gdl++, G_AC_NONE);
				gDPSetTextureLOD(gdl++, G_TL_TILE);
				gDPSetTextureConvert(gdl++, G_TC_FILT);

				tex_select(&gdl, &g_TexGeneralConfigs[TEX_GENERAL_DOLBYLOGO], 1, 0, 2, 1, 0);

				gDPSetCycleType(gdl++, G_CYC_1CYCLE);
				gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
				gDPSetTextureFilter(gdl++, G_TF_POINT);

				gSPTextureRectangle(gdl++,
						elem->x << 2,
						elem->y << 2,
						(elem->x + 64) << 2,
						(elem->y + 24) << 2,
						G_TX_RENDERTILE, 0, 0x0300, 0x0400, -0x0400);

				gdl = text_begin(gdl);
			} else if (elem->type == LEGALELEMENTTYPE_RARELOGO) {
				gdl = text_end(gdl);

				gDPPipeSync(gdl++);
				gDPSetTexturePersp(gdl++, G_TP_NONE);
				gDPSetAlphaCompare(gdl++, G_AC_NONE);
				gDPSetTextureLOD(gdl++, G_TL_TILE);
				gDPSetTextureConvert(gdl++, G_TC_FILT);

				tex_select(&gdl, &g_TexGeneralConfigs[TEX_GENERAL_RARELOGO], 1, 0, 2, 1, 0);

				gDPSetCycleType(gdl++, G_CYC_1CYCLE);
				gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
				gDPSetTextureFilter(gdl++, G_TF_POINT);

				gSPTextureRectangle(gdl++,
						elem->x << 2,
						elem->y << 2,
						(elem->x + 32) << 2,
						(elem->y + 42) << 2,
						G_TX_RENDERTILE, 0, 0x0540, 0x0400, -0x0400);

				gdl = text_begin(gdl);
			} else {
#if VERSION == VERSION_JPN_FINAL
				u32 stack;
				x = elem->x == -1 ? prevx : elem->x;
				y = elem->y - 1;

				if (elem->type == LEGALELEMENTTYPE_WHITETEXTLG || elem->type == LEGALELEMENTTYPE_WHITETEXTSM) {
					y -= 3;

					g_TextScaleX = 2;
					var80080108jf = 2;

					if (elem->x == -1) {
						x += 24;
					}

					gdl = text_render_v2(gdl, &x, &y, lang_get(elem->textid), font1, font2, colour, vi_get_width(), vi_get_height(), 0, 0);

					g_TextScaleX = 1;
					var80080108jf = 1;
				} else {
					gdl = text_render_v2(gdl, &x, &y, lang_get(elem->textid), font1, font2, (colour & 0xffffff00) | ((colour & 0xff) * 2 / 3), vi_get_width(), vi_get_height(), 0, 0);

					x = elem->x == -1 ? prevx : elem->x;
					y = elem->y;
					gdl = text_render_v2(gdl, &x, &y, lang_get(elem->textid), font1, font2, colour, vi_get_width(), vi_get_height(), 0, 0);

					prevx = x;
				}
#elif VERSION >= VERSION_PAL_FINAL
				u32 stack;
				// Render a darker copy of the text one pixel above
				x = elem->x == -1 ? prevx : elem->x;
				y = elem->y - 1;
				gdl = text_render_v2(gdl, &x, &y, lang_get(elem->textid), font1, font2, (colour & 0xffffff00) | ((colour & 0xff) * 2 / 3), vi_get_width(), vi_get_height(), 0, 0);

				// Render the text properly
				x = elem->x == -1 ? prevx : elem->x;
				y = elem->y;
				gdl = text_render_v2(gdl, &x, &y, lang_get(elem->textid), font1, font2, colour, vi_get_width(), vi_get_height(), 0, 0);

				prevx = x;
#elif VERSION >= VERSION_PAL_BETA
				x = elem->x == -1 ? prevx : elem->x;
				y = elem->y;
				gdl = text_render_v2(gdl, &x, &y, lang_get(elem->textid), font1, font2, colour, vi_get_width(), vi_get_height(), 0, 0);
				prevx = x;
#else
				x = elem->x;
				y = elem->y;
				gdl = text_render_v2(gdl, &x, &y, lang_get(elem->textid), font1, font2, colour, vi_get_width(), vi_get_height(), 0, 0);
#endif
			}
		}

		gdl = text_end(gdl);
	}

	return gdl;
}

bool g_LegalEnabled = true;
bool g_PdLogoIsFirstTick = true;
bool g_PdLogoTriggerExit = false;

void title_init_pd_logo(void)
{
	u8 *nextaddr = var8009cca0;
	u32 remaining;
	u32 size;

	g_TitleTimer = 0;

#if VERSION == VERSION_JPN_FINAL
	{
		s32 i;
		s32 j;

		var8009d34cjf = var8009d350jf = 9.0f;

		for (i = 0; i < 4; i++) {
			for (j = 0; j < 20; j++) {
				var8009d34cjf = 0.99f * var8009d34cjf + 0.01f;
			}

			for (j = 0; j < ARRAYCOUNT(var8009d358jf) - 1; j++) {
				var8009d358jf[j] = var8009d358jf[j + 1];
			}

			var8009d358jf[3] = var8009d34cjf;
		}

		var8009d350jf = var8009d358jf[1];
	}
#endif

	{
		struct coord coord = {0, 0, 0};
		g_ModelStates[MODEL_NLOGO].modeldef = modeldef_load(g_ModelStates[MODEL_NLOGO].fileid, nextaddr, TITLE_ALLOCSIZE, 0);
		size = ALIGN64(file_get_loaded_size(g_ModelStates[MODEL_NLOGO].fileid));
		nextaddr += size;
		remaining = TITLE_ALLOCSIZE - size;
		model_allocate_rw_data(g_ModelStates[MODEL_NLOGO].modeldef);

		g_TitleModel = modelmgr_instantiate_model_with_anim(g_ModelStates[MODEL_NLOGO].modeldef);
		model_set_scale(g_TitleModel, 1);
		model_set_root_position(g_TitleModel, &coord);
	}

	{
		struct coord coord = {0, 0, 0};
		g_ModelStates[MODEL_NLOGO2].modeldef = modeldef_load(g_ModelStates[MODEL_NLOGO2].fileid, nextaddr, remaining, 0);
		size = ALIGN64(file_get_loaded_size(g_ModelStates[MODEL_NLOGO2].fileid));
		nextaddr += size;
		remaining -= size;
		model_allocate_rw_data(g_ModelStates[MODEL_NLOGO2].modeldef);

		g_TitleModelNLogo2 = modelmgr_instantiate_model_with_anim(g_ModelStates[MODEL_NLOGO2].modeldef);
		model_set_scale(g_TitleModelNLogo2, 1);
		model_set_root_position(g_TitleModelNLogo2, &coord);
	}

	{
		struct coord coord = {0, 0, 0};
		g_ModelStates[MODEL_PDTWO].modeldef = modeldef_load(g_ModelStates[MODEL_PDTWO].fileid, nextaddr, remaining, 0);
		size = ALIGN64(file_get_loaded_size(g_ModelStates[MODEL_PDTWO].fileid));
		nextaddr += size;
		remaining -= size;
		model_allocate_rw_data(g_ModelStates[MODEL_PDTWO].modeldef);

		g_TitleModelPdTwo = modelmgr_instantiate_model_without_anim(g_ModelStates[MODEL_PDTWO].modeldef);
		model_set_scale(g_TitleModelPdTwo, 1);
		model_set_root_position(g_TitleModelPdTwo, &coord);
	}

#if VERSION == VERSION_JPN_FINAL
	{
		struct coord coord = {0, 0, 0};
		g_ModelStates[MODEL_JPNLOGO].modeldef = modeldef_load(g_ModelStates[MODEL_JPNLOGO].fileid, nextaddr, remaining, 0);
		size = ALIGN64(file_get_loaded_size(g_ModelStates[MODEL_JPNLOGO].fileid));
		nextaddr += size;
		remaining -= size;
		model_allocate_rw_data(g_ModelStates[MODEL_JPNLOGO].modeldef);

		g_TitleModelJpnLogo1 = modelmgr_instantiate_model_without_anim(g_ModelStates[MODEL_JPNLOGO].modeldef);
		g_TitleModelJpnLogo2 = modelmgr_instantiate_model_without_anim(g_ModelStates[MODEL_JPNLOGO].modeldef);
		model_set_scale(g_TitleModelJpnLogo1, 1);
		model_set_scale(g_TitleModelJpnLogo2, 1);
		model_set_root_position(g_TitleModelJpnLogo1, &coord);
		model_set_root_position(g_TitleModelJpnLogo2, &coord);

		g_ModelStates[MODEL_JPNPD].modeldef = modeldef_load(g_ModelStates[MODEL_JPNPD].fileid, nextaddr, remaining, 0);
		size = ALIGN64(file_get_loaded_size(g_ModelStates[MODEL_JPNPD].fileid));
		nextaddr += size;
		remaining -= size;
		model_allocate_rw_data(g_ModelStates[MODEL_JPNPD].modeldef);

		g_TitleModelJpnPd = modelmgr_instantiate_model_without_anim(g_ModelStates[MODEL_JPNPD].modeldef);
		model_set_scale(g_TitleModelJpnPd, 1);
		model_set_root_position(g_TitleModelJpnPd, &coord);
	}
#endif

	{
		struct coord coord = {0, 0, 0};
		g_ModelStates[MODEL_PDTHREE].modeldef = modeldef_load(g_ModelStates[MODEL_PDTHREE].fileid, nextaddr, remaining, 0);
		size = ALIGN64(file_get_loaded_size(g_ModelStates[MODEL_PDTHREE].fileid));
		nextaddr += size;
		remaining -= size;
		model_allocate_rw_data(g_ModelStates[MODEL_PDTHREE].modeldef);

		g_TitleModelPdThree = modelmgr_instantiate_model_without_anim(g_ModelStates[MODEL_PDTHREE].modeldef);
		model_set_scale(g_TitleModelPdThree, 1);
		model_set_root_position(g_TitleModelPdThree, &coord);
	}

	{
		struct modelrodata_dl *rodata = (struct modelrodata_dl *)model_get_part_rodata(g_ModelStates[MODEL_PDTWO].modeldef, MODELPART_LOGO_FRONTSIDE);

		size = ALIGN8(rodata->numvertices * sizeof(Vtx));

		g_PdLogoVertices[0] = (void *)nextaddr;

		nextaddr += size;
		remaining -= size;
		g_PdLogoVertices[1] = (void *)nextaddr;

		nextaddr += size;
		remaining -= size;
		size = ALIGN8(rodata->numcolours * sizeof(Col));
		g_PdLogoColours[0] = (void *)nextaddr;

		nextaddr += size;
		remaining -= size;
		g_PdLogoColours[1] = (void *)nextaddr;

		if (1);
		g_PdLogoVtxColIndex = 0;
		var800624f4 = 1;

		joy00014810(false);

		g_PdLogoIsFirstTick = true;
		g_PdLogoTriggerExit = false;

		if (g_TitleButtonPressed) {
			title_skip_to_pd_title();
		}
	}
}

void title_exit_pd_logo(void)
{
	modelmgr_free_model(g_TitleModel);
	modelmgr_free_model(g_TitleModelNLogo2);
	modelmgr_free_model(g_TitleModelPdTwo);
	modelmgr_free_model(g_TitleModelPdThree);

#if VERSION == VERSION_JPN_FINAL
	modelmgr_free_model(g_TitleModelJpnLogo1);
	modelmgr_free_model(g_TitleModelJpnLogo2);
	modelmgr_free_model(g_TitleModelJpnPd);
#endif

	joy00014810(true);
}

void title_tick_pd_logo(void)
{
	vi_set_fov_y(46);
	vi_set_aspect(1.33333333f);
	vi_set_z_range(100, 10000);
	vi_set_use_z_buf(false);

	g_TitleTimer += g_Vars.lvupdate60;
	g_PdLogoVtxColIndex = 1 - g_PdLogoVtxColIndex;

#if VERSION == VERSION_JPN_FINAL
	if (g_TitleTimer > 950) {
		g_PdLogoTriggerExit = true;
	}
#endif

	if (g_PdLogoTriggerExit) {
		// Exiting due to player not pressing anything
		if (g_AltTitleEnabled && IS8MB()) {
			g_TitleMode = TITLEMODE_SKIP;
			credits_request_alt_title();
			g_TitleNextStage = STAGE_CREDITS; // for alt title screen
			set_num_players(1);
			main_change_to_stage(g_TitleNextStage);

			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = -1;
			g_Vars.antiplayernum = -1;

			lv_set_difficulty(DIFF_A);
			vi_black(true);
		} else {
			title_set_next_mode(TITLEMODE_SKIP);
		}
	}

	if (g_TitleButtonPressed && g_TitleTimer > TICKS(666)) {
		title_set_next_mode(TITLEMODE_SKIP);
	}

	if (joy_get_buttons_pressed_this_frame(0, 0xffff)) {
		g_TitleButtonPressed = g_TitleFastForward = true;

		if (g_TitleTimer < TICKS(549)) {
			title_set_next_mode(TITLEMODE_PDLOGO);
		}
	}
}

Gfx *title_render_pd_logo_model(Gfx *gdl, struct model *model, bool arg2, f32 arg3, s32 arg4, f32 arg5, Mtxf *arg6, Vtx *vertices, Col *colours)
{
	struct modelrenderdata renderdata = {NULL, true, 3};
	s32 tmp2;
	s32 i;
	s32 j;
	Vtx *sp100;
	Col *spfc;
	union modelrwdata *tmp;
	struct modelrwdata_dl *rwdata;
	struct modelnode *node1;
	struct modelnode *node2;
	s32 s6;
	s32 k;
	struct modelrodata_dl *s5rodata;
	struct modelrodata_dl *s1rodata;
	s32 alpha1;
	s32 spcc[3];
	f32 spc0[3];
	Vtx *a3;
	s32 alpha2;
	Vtx *t0;
	Col *s1;
	Col *s2;
	Mtxf sp6c;

	tmp = model_get_node_rw_data(model, model_get_part(model->definition, MODELPART_LOGO_0000));
	tmp->toggle.visible = arg2;

	tmp = model_get_node_rw_data(model, model_get_part(model->definition, MODELPART_LOGO_0001));
	tmp->toggle.visible = !arg2;

	s6 = arg3 * 65536.0f;

	if (s6 < 0) {
		s6 = 0;
	} else if (s6 > 65536) {
		s6 = 65536;
	}

	alpha1 = s6 / 256;

	if (alpha1 > arg4) {
		alpha1 = arg4;
	}

	if (!arg2) {
		s6 = 65536 - s6;
		alpha1 = 256 - alpha1;
	}

	if (alpha1 < 0) {
		alpha1 = 0;
	} else if (alpha1 > 255) {
		alpha1 = 255;
	}

	alpha2 = arg5 * 256.0f;

	if (alpha2 < 0) {
		alpha2 = 0;
	} else if (alpha2 > 255) {
		alpha2 = 255;
	}

	sp100 = vertices;
	spfc = colours;

	for (i = 0; i < 4; i++) {
		if (i == 0) {
			node1 = model_get_part(model->definition, MODELPART_LOGO_FRONTSIDE);
			node2 = model_get_part(model->definition, MODELPART_LOGO_0003);
		} else if (i == 1) {
			node1 = model_get_part(model->definition, MODELPART_LOGO_RIGHTSIDE);
			node2 = model_get_part(model->definition, MODELPART_LOGO_0005);
		} else if (i == 2) {
			node1 = model_get_part(model->definition, MODELPART_LOGO_BACKSIDE);
			node2 = model_get_part(model->definition, MODELPART_LOGO_0007);
		} else {
			node1 = model_get_part(model->definition, MODELPART_LOGO_LEFTSIDE);
			node2 = model_get_part(model->definition, MODELPART_LOGO_0009);
		}

		if (node1 && node2) {
			if (arg2) {
				s5rodata = &node1->rodata->dl;
				s1rodata = &node2->rodata->dl;
				rwdata = model_get_node_rw_data(model, node1);
			} else {
				s5rodata = &node2->rodata->dl;
				s1rodata = &node1->rodata->dl;
				rwdata = model_get_node_rw_data(model, node2);
			}

			s1 = (Col *)ALIGN8(s5rodata->numvertices * sizeof(Vtx) + (s32)s5rodata->vertices);
			s2 = (Col *)ALIGN8(s1rodata->numvertices * (s32) sizeof(Vtx) + (s32)s1rodata->vertices);

			a3 = s5rodata->vertices;
			t0 = s1rodata->vertices;

			rwdata->vertices = sp100;
			rwdata->colours = spfc;

			for (j = 0; j < s5rodata->numvertices; j++) {
				sp100[j] = a3[j];

				tmp2 = (t0[j].x - a3[j].x) * s6;
				tmp2 = tmp2 / 65536;
				sp100[j].x += (s16) tmp2;

				tmp2 = (t0[j].y - a3[j].y) * s6;
				tmp2 = tmp2 / 65536;
				sp100[j].y += (s16) tmp2;

				tmp2 = (t0[j].z - a3[j].z) * s6;
				tmp2 = tmp2 / 65536;
				sp100[j].z += (s16) tmp2;
			}

			for (j = 0; j < s5rodata->numcolours; j++) {
				spcc[0] = ((s8) s2[j].r * s6 + (s8) s1[j].r * (65536 - s6)) / 65536;
				spcc[1] = ((s8) s2[j].g * s6 + (s8) s1[j].g * (65536 - s6)) / 65536;
				spcc[2] = ((s8) s2[j].b * s6 + (s8) s1[j].b * (65536 - s6)) / 65536;

				spc0[0] = spcc[0];
				spc0[1] = spcc[1];
				spc0[2] = spcc[2];

				if (spc0[0] != 0.0f || spc0[1] != 0.0f || spc0[2] != 0.0f) {
					guNormalize(&spc0[0], &spc0[1], &spc0[2]);
				}

				spfc[j].r = (s32) (spc0[0] * 127.0f);
				spfc[j].g = (s32) (spc0[1] * 127.0f);
				spfc[j].b = (s32) (spc0[2] * 127.0f);
				spfc[j].a = alpha2;
			}

			sp100 = (void *)ALIGN8(s5rodata->numvertices * sizeof(Vtx) + (s32)sp100);
			spfc = (void *)ALIGN8(s5rodata->numcolours * sizeof(u32) + (s32)spfc);
		}
	}

	gDPSetPrimColor(gdl++, 0, 0, 0x00, 0x00, 0x00, alpha1);

	renderdata.unk00 = arg6;
	renderdata.unk10 = gfx_allocate(model->definition->nummatrices * sizeof(Mtxf));

	mtx4_copy(arg6, renderdata.unk10);

	model->matrices = renderdata.unk10;

	model_update_relations(model);

	renderdata.flags = 3;
	renderdata.zbufferenabled = false;
	renderdata.gdl = gdl;

	model_render(&renderdata, model);

	gdl = renderdata.gdl;

	for (j = 0, k = 0; j < model->definition->nummatrices; j++, k += sizeof(Mtxf)) {
		mtx4_copy((Mtxf *)((uintptr_t)model->matrices + k), &sp6c);
		mtx_f2l(&sp6c, model->matrices + j);
	}

	return gdl;
}

f32 g_PdLogoYRotCur = 0;
f32 g_PdLogoYRotSpeed = 0;
f32 g_PdLogoXRotCur = 0;
f32 g_PdLogoXRotSpeed = 0;
f32 g_PdLogoScale = 1;
f32 g_PdLogoFrac = 0;
bool g_PdLogoUseCombinedModel = false;
f32 g_PdLogoEndYRot = 0;
f32 g_PdLogoAmbientLightFrac = 1;
s32 g_PdLogoBlackTimer = 0;
bool g_PdLogoYRotEnabled = false;
s32 g_PdLogoPreMorphTimer = 0;
bool g_PdLogoMorphing = false;
s32 g_PdLogoExitTimer = 0;
s32 g_PdLogoMorphEndTimer = 0;
bool g_PdLogoYRotStopping = false;
bool g_PdLogoDarkenEnabled = false;
bool g_PdLogoPointlessTimerEnabled = false;
s32 g_PdLogoPreTitleTimer = 0;
f32 g_PdLogoTitleStepFrac = 0;
s32 g_PdLogoTitleStep = 0;
bool g_PdLogoTitlePresenting = false;
s32 g_PdLogoPointlessTimer = 0;
s32 var80062804 = 1;
f32 g_PdLogoUnusedRot = BADDTOR(90);
bool g_PdLogoUnusedRotEnabled = false;
bool g_PdLogoLightMoving = false;
f32 g_PdLogoLightDirFrac = 0;


/**
 * Skip immediately to the "PERFECT DARK" part of the PdLogo mode.
 *
 * Assumes the title mode is already PdLogo, but at an earlier point.
 */
void title_skip_to_pd_title(void)
{
	g_PdLogoYRotCur = 0;
	g_PdLogoYRotSpeed = 0;
	g_PdLogoXRotCur = 0;
	g_PdLogoXRotSpeed = 0;
	g_PdLogoScale = 0.35f;
	g_PdLogoFrac = 1;
	g_PdLogoTitleStepFrac = 0.63f;
	g_PdLogoUnusedRot = DTOR(94.215);
	g_PdLogoLightDirFrac = 0.19975f;
	g_PdLogoEndYRot = 0;
	g_PdLogoAmbientLightFrac = 0;

	g_PdLogoUseCombinedModel = true;
	g_PdLogoBlackTimer = 0;
	g_PdLogoYRotEnabled = false;
	g_PdLogoPreMorphTimer = 0;
	g_PdLogoMorphing = false;
	g_PdLogoExitTimer = 0;
	g_PdLogoMorphEndTimer = 0;
	g_PdLogoYRotStopping = false;
	g_PdLogoDarkenEnabled = false;
	g_PdLogoPointlessTimerEnabled = false;
	g_PdLogoPreTitleTimer = 0;
	g_PdLogoTitleStep = 1;
	g_PdLogoTitlePresenting = true;
	g_PdLogoPointlessTimer = 0;
	var80062804 = 1;
	g_PdLogoUnusedRotEnabled = true;
	g_PdLogoLightMoving = true;
	g_TitleTimer = TICKS(549);
	g_PdLogoIsFirstTick = false;

	music_start_temporary_primary(MUSIC_TITLE2);
}

Gfx *title_render_pd_logo(Gfx *gdl)
{
	struct modelrenderdata renderdata = {NULL, true, 3};
	Mtxf sp2b0;
	Mtxf sp270;
	Mtxf sp230;
	struct model *model;
	struct modelnode *node;
	Mtxf sp1e8;
	Mtxf sp1a8;

	f32 yrotmax = 4.240475f;
	f32 xrotmax = 0.47116387f;
	f32 xrotmin = 0.0f;

#if VERSION >= VERSION_PAL_FINAL
	f32 yrotaccel = PALUPF(0.00018846555f);
	f32 xrotaccel = PALUPF(0.00011307933f);
	f32 yrotmaxspeed = PALUPF(0.018846555f);
	f32 xrotmaxspeed = PALUPF(0.011307933f);
#else
	f32 yrotaccel = 0.00018846555f;
	f32 xrotaccel = 0.00011307933f;
	f32 yrotmaxspeed = 0.018846555f;
	f32 xrotmaxspeed = 0.011307933f;
#endif

	s32 premorphduration = TICKS(80);
	f32 amblightinc = 0.0075f;
	f32 lightdirinc = 0.017f;
	f32 logoinc = 0.004f;
	f32 unusedrotinc = 0.006282185f;
	f32 step0inc = 0.025f;
	f32 step1inc = 0.09f;
	f32 step2inc = 0.1f;

	s32 tmp;
	struct modelrodata_dl *rodata;
	struct modelrwdata_dl *rwdata;

	u32 stack1[8];

#if VERSION == VERSION_JPN_FINAL
	u32 stack2[1];
	s32 i;
	s32 j;
	f32 firstvalue;
	s32 step0value;
	u32 step1weight;
	u32 step1colour;
#endif

	f32 sp13c;

	Gfx *tmpgdl;
	LookAt *lookat;
	Mtx spf0;

	sp13c = g_TitleTimer / TICKS(4500.0f) - 0.1f;

	if (g_PdLogoIsFirstTick) {
		g_PdLogoYRotCur = yrotmax;
		g_PdLogoYRotSpeed = yrotmaxspeed;
		g_PdLogoXRotCur = xrotmax;
		g_PdLogoXRotSpeed = 0.0f;
		g_PdLogoScale = 0.35f;
		g_PdLogoFrac = 0.0f;
		g_PdLogoUseCombinedModel = false;
		g_PdLogoAmbientLightFrac = 1.0f;
		g_PdLogoIsFirstTick = false;
		g_PdLogoBlackTimer = 1;
		g_PdLogoYRotEnabled = false;
		g_PdLogoPreMorphTimer = 0;
		g_PdLogoMorphing = false;
		g_PdLogoExitTimer = 0;
		g_PdLogoMorphEndTimer = 0;
		g_PdLogoYRotStopping = false;
		g_PdLogoDarkenEnabled = false;
		var80062804 = 1;
		g_PdLogoPointlessTimerEnabled = false;
		g_PdLogoPreTitleTimer = 0;
		g_PdLogoTitleStepFrac = 0.0f;
		g_PdLogoTitlePresenting = false;
		g_PdLogoTitleStep = -1;
		g_PdLogoPointlessTimer = 0;
		g_PdLogoUnusedRotEnabled = false;
		g_PdLogoUnusedRot = BADDTOR(90);
		g_PdLogoLightMoving = false;
		g_PdLogoLightDirFrac = 0.0f;
	}

	if (g_PdLogoBlackTimer != 0) {
		g_PdLogoBlackTimer++;

		if (g_PdLogoBlackTimer >= 4) {
			g_PdLogoBlackTimer = 0;
			g_PdLogoYRotEnabled = true;
			g_PdLogoPreMorphTimer = 1;
		}
	}

	if (g_PdLogoYRotStopping) {
		if (g_PdLogoYRotCur < g_PdLogoEndYRot) {
			apply_speed(&g_PdLogoYRotCur, g_PdLogoEndYRot, &g_PdLogoYRotSpeed, yrotaccel, yrotaccel, yrotmaxspeed);

			if (g_PdLogoYRotCur >= g_PdLogoEndYRot) {
				g_PdLogoYRotCur = g_PdLogoEndYRot;
				g_PdLogoYRotSpeed = 0.0f;
			}

			if (g_PdLogoYRotCur >= BADDTOR(360)) {
				g_PdLogoYRotCur -= BADDTOR(360);
				g_PdLogoEndYRot -= BADDTOR(360);
			} else if (g_PdLogoYRotCur < 0.0f) {
				g_PdLogoYRotCur += BADDTOR(360);
				g_PdLogoEndYRot += BADDTOR(360);
			}
		}

		if (g_PdLogoYRotCur >= g_PdLogoEndYRot) {
			g_PdLogoYRotStopping = false;
		}
	} else if (g_PdLogoYRotEnabled) {
#if VERSION >= VERSION_PAL_FINAL
		g_PdLogoYRotCur += g_PdLogoYRotSpeed * g_Vars.lvupdate60;
#else
		g_PdLogoYRotCur += g_PdLogoYRotSpeed * g_Vars.lvupdate60freal;
#endif

		if (g_PdLogoYRotCur >= BADDTOR(360)) {
			g_PdLogoYRotCur -= BADDTOR(360);
		} else if (g_PdLogoYRotCur < 0.0f) {
			g_PdLogoYRotCur += BADDTOR(360);
		}
	}

	if (g_PdLogoPreMorphTimer != 0) {
		g_PdLogoPreMorphTimer += g_Vars.lvupdate60;

		if (g_PdLogoPreMorphTimer > 0) {
			g_PdLogoFrac = (f32) g_PdLogoPreMorphTimer / premorphduration;
		} else {
			g_PdLogoFrac = 0.0f;
		}

		if (g_PdLogoPreMorphTimer > premorphduration) {
			g_PdLogoPreMorphTimer = 0;
			g_PdLogoMorphing = true;
			g_PdLogoFrac = 0.0f;
			g_PdLogoUseCombinedModel = true;
		}
	}

	if (g_PdLogoMorphing) {
		g_PdLogoFrac += logoinc * g_Vars.lvupdate60freal;

		if (g_PdLogoFrac >= 0.8f) {
			if (g_PdLogoMorphEndTimer == 0) {
				g_PdLogoMorphEndTimer = 1;
			}
		}

		if (g_PdLogoFrac >= 1.0f) {
			g_PdLogoFrac = 1.0f;
			g_PdLogoMorphing = false;
		}
	}

	if (g_PdLogoMorphEndTimer != 0) {
		g_PdLogoMorphEndTimer += g_Vars.lvupdate60;

		if (g_PdLogoXRotCur > xrotmin) {
			// Implement the camera lowering effect, but it's actually
			// the model that rotates upwards to face the camera
			apply_rotation(&g_PdLogoXRotCur, xrotmin, &g_PdLogoXRotSpeed, xrotaccel, xrotaccel, xrotmaxspeed);

			if (g_PdLogoXRotCur <= xrotmin) {
				g_PdLogoXRotCur = xrotmin;
				g_PdLogoXRotSpeed = 0.0f;
			}
		}

		if (g_PdLogoMorphEndTimer > TICKS(30) && g_PdLogoMorphEndTimer - g_Vars.lvupdate60 <= TICKS(30)) {
			// Start slowing the spinning rotation
			g_PdLogoYRotEnabled = false;
			g_PdLogoYRotStopping = true;

			tmp = g_PdLogoYRotCur * 4.0f / BADDTOR(360);
			tmp += 2;

			g_PdLogoEndYRot = tmp * BADDTOR(360) / 4.0f;
		}

		if (g_PdLogoMorphEndTimer > TICKS(100) && g_PdLogoMorphEndTimer - g_Vars.lvupdate60 <= TICKS(100)) {
			g_PdLogoDarkenEnabled = true;
		}

		if (!g_PdLogoYRotStopping && g_PdLogoXRotCur <= 0.0f) {
			// Spinning has stopped and model is also facing camera vertically
			g_PdLogoMorphEndTimer = 0;
			g_PdLogoDarkenEnabled = true;
		}
	}

	if (g_PdLogoDarkenEnabled) {
		// Fading out the side and back faces of the logo. This is done by adjusting the ambient lighting.
		// The front face is excluded from this further below.
		g_PdLogoAmbientLightFrac -= amblightinc * g_Vars.lvupdate60freal;

		if (g_PdLogoAmbientLightFrac <= 0.0f) {
			g_PdLogoAmbientLightFrac = 0.0f;
			g_PdLogoDarkenEnabled = false;
			g_PdLogoPreTitleTimer = 1;
		}
	}

	if (g_PdLogoPreTitleTimer != 0) {
		g_PdLogoPreTitleTimer += g_Vars.lvupdate60;

		if (g_PdLogoPreTitleTimer > TICKS(20)) {
			g_PdLogoPreTitleTimer = 0;
			g_PdLogoPointlessTimerEnabled = true;
		}
	}

	if (g_PdLogoPointlessTimerEnabled) {
		g_PdLogoPointlessTimerEnabled = false;
		g_PdLogoPointlessTimer = 1;
	}

	if (g_PdLogoPointlessTimer != 0) {
		g_PdLogoPointlessTimer += g_Vars.lvupdate60;

		if (g_PdLogoPointlessTimer > 0) {
			g_PdLogoPointlessTimer = 0;
			g_PdLogoTitlePresenting = true;
			g_PdLogoTitleStep = 1;
			g_PdLogoLightMoving = true;
		}
	}

#if VERSION >= VERSION_JPN_FINAL
	if (g_PdLogoTitleStep >= 0) {
		g_PdLogoUnusedRotEnabled = true;

		if (g_PdLogoTitleStep < 2) {
			g_PdLogoTitleStepFrac += g_Vars.lvupdate60f / 12.0f;
		} else {
			g_PdLogoTitleStepFrac += 0.05f * g_Vars.lvupdate60f;
		}

		for (i = 0; i < g_Vars.lvupdate240; i++) {
			var8009d34cjf = 0.99f * var8009d34cjf + 0.01f;
		}

		if (g_PdLogoTitleStepFrac >= 1.0f) {
			firstvalue = var8009d358jf[0];
			var8009d350jf = var8009d358jf[2];

			for (j = 0; j < 3; j++) {
				var8009d358jf[j] = var8009d358jf[j + 1];
			}

			var8009d358jf[3] = g_PdLogoTitleStep > 3 ? firstvalue : var8009d34cjf;

			g_PdLogoTitleStepFrac = 0.0f;
			g_PdLogoTitleStep++;
		}
	}
#else
	if (g_PdLogoTitlePresenting) {
		g_PdLogoUnusedRotEnabled = 1;

		if (g_PdLogoTitleStep == 0) {
			g_PdLogoTitleStepFrac += step0inc;
		} else if (g_PdLogoTitleStep == 1) {
			g_PdLogoTitleStepFrac += step1inc;
		} else {
			g_PdLogoTitleStepFrac += step2inc;
		}

		if (g_PdLogoTitleStepFrac >= 1.0f) {
			g_PdLogoTitleStepFrac = 0.0f;
			g_PdLogoTitleStep++;

#if VERSION == VERSION_PAL_FINAL
			if (g_PdLogoTitleStep == 6)
#else
			if (g_PdLogoTitleStep == 10)
#endif
			{
				g_PdLogoTitlePresenting = false;
				g_PdLogoExitTimer = 1;
			}
		}
	}
#endif

	if (g_PdLogoUnusedRotEnabled) {
		// Some unused value... maybe a different method of rotating the light?
		g_PdLogoUnusedRot += unusedrotinc * g_Vars.lvupdate60freal;

		if (g_PdLogoUnusedRot >= BADDTOR(360)) {
			g_PdLogoUnusedRot -= BADDTOR(360);
		}
	}

	if (g_PdLogoLightMoving) {
		g_PdLogoLightDirFrac += lightdirinc * g_Vars.lvupdate60freal;

		if (g_PdLogoLightDirFrac >= 1.0f) {
			g_PdLogoLightDirFrac = 1.0f;
			g_PdLogoLightMoving = false;
		}
	}

	if (g_PdLogoExitTimer != 0) {
		g_PdLogoExitTimer += g_Vars.lvupdate60;

		if (g_PdLogoExitTimer > TICKS(60)) {
			g_PdLogoExitTimer = 0;
			g_PdLogoTriggerExit = true;
		}
	}

#if VERSION == VERSION_JPN_FINAL
	if (g_PdLogoTitleStep < 0) {
		gdl = vi_set_fill_colour(gdl, 0x00, 0x00, 0x00);
	} else if (g_PdLogoTitleStep == 0) {
		step0value = g_PdLogoTitleStepFrac * 255.0f;
		gdl = vi_set_fill_colour(gdl, step0value, step0value, step0value);
	} else if (g_PdLogoTitleStep == 1) {
		step1weight = g_PdLogoTitleStepFrac * 255.0f;
		step1colour = colour_blend(0xffffffff, 0xa5002c00, step1weight);
		gdl = vi_set_fill_colour(gdl, ((step1colour >> 24) & 0xff), (step1colour >> 16) & 0xff, (step1colour >> 8) & 0xff);
	} else {
		gdl = vi_set_fill_colour(gdl, 0xb9, 0x00, 0x2c);
	}
#else
	gdl = vi_set_fill_colour(gdl, 0x00, 0x00, 0x00);
#endif

	gdl = vi_fill_buffer(gdl);

	if (g_PdLogoBlackTimer != 0) {
		return gdl;
	}

	lookat = gfx_allocate_look_at(2);
	guLookAtReflect(&spf0, lookat, 0.0f, 0.0f, 4000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	gSPLookAt(gdl++, lookat);

	{
		f32 angle1;
		f32 angle2;
#if VERSION == VERSION_JPN_FINAL
		u8 greenblue;
		f32 frac;
#endif

		angle1 = (g_PdLogoLightDirFrac + -1.0f);
		angle2 = 0.0f - 0.15f * g_PdLogoLightDirFrac;
		angle1 = DTOR(180) + angle1 * DTOR(180);
		angle2 = DTOR(180) + angle2 * DTOR(180);

#if VERSION == VERSION_JPN_FINAL
		if (g_PdLogoUseCombinedModel == true) {
			if (g_PdLogoMorphing) {
				frac = 1.0f - g_PdLogoFrac * 2.0f;

				if (frac < 0.0f) {
					frac = 0.0f;
				}

				greenblue = 255.0f * frac;
			} else {
				frac = 0.0f;
				greenblue = 0;
			}
		} else {
			frac = 1.0f;
			greenblue = 255;
		}

		if (g_PdLogoTitleStep < 0) {
			g_TitleLightPdLogoMain.l[0].l.col[0] = g_TitleLightPdLogoMain.l[0].l.colc[0] = 255;
			g_TitleLightPdLogoMain.l[0].l.col[1] = g_TitleLightPdLogoMain.l[0].l.col[2] = g_TitleLightPdLogoMain.l[0].l.colc[1] = g_TitleLightPdLogoMain.l[0].l.colc[2] = greenblue;
		} else {
			g_TitleLightPdLogoMain.l[0].l.col[0] = g_TitleLightPdLogoMain.l[0].l.colc[0] = 0;
			g_TitleLightPdLogoMain.l[0].l.col[1] = g_TitleLightPdLogoMain.l[0].l.col[2] = g_TitleLightPdLogoMain.l[0].l.colc[1] = g_TitleLightPdLogoMain.l[0].l.colc[2] = 0;
		}

		g_TitleLightPdLogoNotFront.a.l.col[0] = g_TitleLightPdLogoNotFront.a.l.colc[0] = 255.0f * g_PdLogoAmbientLightFrac;
		g_TitleLightPdLogoNotFront.a.l.col[1] = g_TitleLightPdLogoNotFront.a.l.col[2] = g_TitleLightPdLogoNotFront.a.l.colc[1] = g_TitleLightPdLogoNotFront.a.l.colc[2] = 255.0f * frac * g_PdLogoAmbientLightFrac;

		g_TitleLightPdLogoFront.a.l.col[0] = g_TitleLightPdLogoFront.a.l.colc[0] = 255;
		g_TitleLightPdLogoFront.a.l.col[1] = g_TitleLightPdLogoFront.a.l.col[2] = g_TitleLightPdLogoFront.a.l.colc[1] = g_TitleLightPdLogoFront.a.l.colc[2] = greenblue;
#else
		g_TitleLightPdLogoMain.a.l.col[0] = g_TitleLightPdLogoMain.a.l.col[1] = g_TitleLightPdLogoMain.a.l.col[2] = g_TitleLightPdLogoMain.a.l.colc[0] = g_TitleLightPdLogoMain.a.l.colc[1] = g_TitleLightPdLogoMain.a.l.colc[2] = 0;
		g_TitleLightPdLogoMain.l[0].l.col[0] = g_TitleLightPdLogoMain.l[0].l.col[1] = g_TitleLightPdLogoMain.l[0].l.col[2] = g_TitleLightPdLogoMain.l[0].l.colc[0] = g_TitleLightPdLogoMain.l[0].l.colc[1] = g_TitleLightPdLogoMain.l[0].l.colc[2] = 0xff;
#endif

		g_TitleLightPdLogoMain.l[0].l.dir[0] = 127.0f * sinf(angle1) * cosf(angle2);
		g_TitleLightPdLogoMain.l[0].l.dir[1] = 127.0f * sinf(angle2);
		g_TitleLightPdLogoMain.l[0].l.dir[2] = 127.0f * cosf(angle1) * cosf(angle2);
	}

	mtx00016ae4(&sp2b0, 0.0f, 0.0f, 4000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	model = g_PdLogoUseCombinedModel == true ? g_TitleModel : g_TitleModelNLogo2;

	mtx4_load_y_rotation(g_PdLogoYRotCur, &sp1e8);
	mtx4_load_x_rotation(g_PdLogoXRotCur, &sp1a8);
	mtx4_mult_mtx4_in_place(&sp1a8, &sp1e8);
	mtx4_mult_mtx4(&sp2b0, &sp1e8, &sp270);
	mtx00015f04(g_PdLogoScale, &sp270);

#if VERSION != VERSION_JPN_FINAL
	g_TitleLightPdLogoNotFront.a.l.col[0] = g_TitleLightPdLogoNotFront.a.l.col[1] = g_TitleLightPdLogoNotFront.a.l.col[2] = g_TitleLightPdLogoNotFront.a.l.colc[0] = g_TitleLightPdLogoNotFront.a.l.colc[1] = g_TitleLightPdLogoNotFront.a.l.colc[2] = 255.0f * g_PdLogoAmbientLightFrac;
#endif

	// Inject a SetLights command into the displaylists for each of the four logo sides.
	// The front face gets a different light which makes it remain lit when the other sides go dark.
#if VERSION == VERSION_JPN_FINAL
	if (g_PdLogoTitleStep <= 0)
#endif
	{
		s32 numvertices = 0;
		s32 numcolours = 0;

		node = model_get_part(model->definition, MODELPART_LOGO_FRONTSIDE);

		if (node != NULL) {
			rodata = &node->rodata->dl;
			numvertices += rodata->numvertices + 1;
			numcolours += rodata->numcolours + 1;
			rwdata = model_get_node_rw_data(model, node);
			rwdata->gdl = tmpgdl = gfx_allocate(5 * sizeof(Gfx));

			gSPSetLights1(tmpgdl++, g_TitleLightPdLogoFront);
			gSPBranchList(tmpgdl++, rodata->opagdl);
		}

		node = model_get_part(model->definition, MODELPART_LOGO_RIGHTSIDE);

		if (node != NULL) {
			rodata = &node->rodata->dl;
			numvertices += rodata->numvertices + 1;
			numcolours += rodata->numcolours + 1;
			rwdata = model_get_node_rw_data(model, node);
			rwdata->gdl = tmpgdl = gfx_allocate(5 * sizeof(Gfx));

			if (g_PdLogoAmbientLightFrac > 0.0f) {
				gSPSetLights1(tmpgdl++, g_TitleLightPdLogoNotFront);
				gSPBranchList(tmpgdl++, rodata->opagdl);
			} else {
				gSPEndDisplayList(tmpgdl++);
			}
		}

		node = model_get_part(model->definition, MODELPART_LOGO_BACKSIDE);

		if (node != NULL) {
			rodata = &node->rodata->dl;
			numvertices += rodata->numvertices + 1;
			numcolours += rodata->numcolours + 1;
			rwdata = model_get_node_rw_data(model, node);
			rwdata->gdl = tmpgdl = gfx_allocate(5 * sizeof(Gfx));

			if (g_PdLogoAmbientLightFrac > 0.0f) {
				gSPSetLights1(tmpgdl++, g_TitleLightPdLogoNotFront);
				gSPBranchList(tmpgdl++, rodata->opagdl);
			} else {
				gSPEndDisplayList(tmpgdl++);
			}
		}

		node = model_get_part(model->definition, MODELPART_LOGO_LEFTSIDE);

		if (node != NULL) {
			rodata = &node->rodata->dl;
			numvertices += rodata->numvertices + 1;
			numcolours += rodata->numcolours + 1;
			rwdata = model_get_node_rw_data(model, node);
			rwdata->gdl = tmpgdl = gfx_allocate(5 * sizeof(Gfx));

			if (g_PdLogoAmbientLightFrac > 0.0f) {
				gSPSetLights1(tmpgdl++, g_TitleLightPdLogoNotFront);
				gSPBranchList(tmpgdl++, rodata->opagdl);
			} else {
				gSPEndDisplayList(tmpgdl++);
			}
		}

		gdl = title_render_pd_logo_model(gdl, model, var80062804, g_PdLogoFrac, 240, 1.0f, &sp270, gfx_allocate_vertices(numvertices), gfx_allocate_colours(numcolours));
	}

	gSPSetLights1(gdl++, g_TitleLightPdLogoMain);

	{
		u32 stack3[4];
		struct coord sp64 = {0, 0, 1000};
		mtx4_load_translation(&sp64, &sp1e8);
	}

#if VERSION == VERSION_JPN_FINAL
	mtx00015ea8(0.01f, &sp1e8);
	mtx4_mult_mtx4(&sp2b0, &sp1e8, &sp230);
	mtx00015f04(0.308f, &sp230);
	mtx00015f04(3.5f, &sp230);

	if (g_PdLogoTitleStep >= 0) {
		// Background flashing logo
		if (g_PdLogoTitleStep >= 2) {
			u32 stack4[1];
			Mtxf sp1b0;
			u32 stack5[4];
			s32 mtxindex;
			u32 envalpha;

			envalpha = (1.0f - g_PdLogoTitleStepFrac) * 255.0f;

			mtx4_load_identity(&sp1b0);
			mtx00015f04(var8009d350jf * 1.5f, &sp1b0);
			mtx00016ae4(&sp2b0, 0.0f, 0.0f, 4000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
			mtx4_mult_mtx4_in_place(&sp2b0, &sp1b0);
			mtx4_copy(&sp1b0, &sp2b0);

			renderdata.unk00 = &sp2b0;
			renderdata.unk10 = gfx_allocate(g_TitleModelJpnLogo2->definition->nummatrices * sizeof(Mtxf));

			mtx4_copy(&sp2b0, renderdata.unk10);

			g_TitleModelJpnLogo2->matrices = renderdata.unk10;

			model_update_relations(g_TitleModelJpnLogo2);

			renderdata.unk30 = 5;
			renderdata.zbufferenabled = false;
			renderdata.fogcolour = 0xff0000ff;
			renderdata.envcolour = 0xff000000 | envalpha;
			renderdata.gdl = gdl;

			model_render(&renderdata, g_TitleModelJpnLogo2);

			gdl = renderdata.gdl;

			for (mtxindex = 0; mtxindex < g_TitleModelJpnLogo2->definition->nummatrices; mtxindex++) {
				Mtxf mtx;
				mtx4_copy((Mtxf *) ((uintptr_t) g_TitleModelJpnLogo2->matrices + mtxindex * sizeof(Mtxf)), &mtx);
				mtx_f2l(&mtx, g_TitleModelJpnLogo2->matrices + mtxindex);
			}
		}

		// Primary "PERFECT DARK" logo
		{
			u32 fogcolour;
			u32 envcolour;
			s32 mtxindex;

			if (g_PdLogoTitleStep <= 2) {
				fogcolour = 0;
				envcolour = 0;
			} else if (g_PdLogoTitleStep == 3) {
				fogcolour = 0;
				envcolour = (u8) (235.0f * g_PdLogoTitleStepFrac);
			} else if (g_PdLogoTitleStep == 4) {
				fogcolour = 235.0f * g_PdLogoTitleStepFrac;
				envcolour = 255;
			} else if (g_PdLogoTitleStep == 5) {
				fogcolour = 235.0f - 138.0f * g_PdLogoTitleStepFrac;
				envcolour = (u8) (235.0f - 138.0f * g_PdLogoTitleStepFrac);
			} else {
				fogcolour = 0x61;
				envcolour = 0x61;
			}

			g_TitleLightPdLogoJpn.l[0].l.col[0] = g_TitleLightPdLogoJpn.l[0].l.colc[0] = 255;
			g_TitleLightPdLogoJpn.l[0].l.col[1] = g_TitleLightPdLogoJpn.l[0].l.col[2] = g_TitleLightPdLogoJpn.l[0].l.colc[1] = g_TitleLightPdLogoJpn.l[0].l.colc[2] = 0;

			gSPSetLights1(gdl++, g_TitleLightPdLogoJpn);
			gSPSetLights1(gdl++, g_TitleLightPdLogoMain);

			renderdata.unk00 = &sp230;

			renderdata.unk10 = gfx_allocate(g_TitleModelJpnPd->definition->nummatrices * sizeof(Mtxf));

			mtx4_copy(&sp230, renderdata.unk10);

			g_TitleModelJpnPd->matrices = renderdata.unk10;

			model_update_relations(g_TitleModelJpnPd);

			// @bug: || should be | in fogcolour expression
			renderdata.zbufferenabled = false;
			renderdata.unk30 = 5;
			renderdata.fogcolour = fogcolour << 24 || fogcolour << 16 || (fogcolour << 8 | 0xff);
			renderdata.envcolour = envcolour;
			renderdata.gdl = gdl;

			model_render(&renderdata, g_TitleModelJpnPd);

			gdl = renderdata.gdl;

			for (mtxindex = 0; mtxindex < g_TitleModelJpnPd->definition->nummatrices; mtxindex++) {
				Mtxf mtx;
				mtx4_copy((Mtxf *) ((uintptr_t) g_TitleModelJpnPd->matrices + mtxindex * sizeof(Mtxf)), &mtx);
				mtx_f2l(&mtx, g_TitleModelJpnPd->matrices + mtxindex);
			}
		}

		// Black logo
		{
			u32 stack6[1];
			Mtxf spb0;
			u32 stack7[4];
			s32 mtxindex;

			mtx4_load_identity(&spb0);
			mtx00015f04(var8009d34cjf * 1.5f, &spb0);
			mtx00016ae4(&sp2b0, 0.0f, 0.0f, 4000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
			mtx4_mult_mtx4_in_place(&sp2b0, &spb0);
			mtx4_copy(&spb0, &sp2b0);

			renderdata.unk00 = &sp2b0;
			renderdata.unk10 = gfx_allocate(g_TitleModelJpnLogo1->definition->nummatrices * sizeof(Mtxf));

			mtx4_copy(&sp2b0, renderdata.unk10);

			g_TitleModelJpnLogo1->matrices = renderdata.unk10;

			model_update_relations(g_TitleModelJpnLogo1);

			renderdata.zbufferenabled = false;
			renderdata.unk30 = 5;
			renderdata.fogcolour = 0x000000ff;
			renderdata.envcolour = 0x000000ff;
			renderdata.gdl = gdl;

			model_render(&renderdata, g_TitleModelJpnLogo1);

			gdl = renderdata.gdl;

			for (mtxindex = 0; mtxindex < g_TitleModelJpnLogo1->definition->nummatrices; mtxindex++) {
				Mtxf mtx;
				mtx4_copy((Mtxf *) ((uintptr_t) g_TitleModelJpnLogo1->matrices + mtxindex * sizeof(Mtxf)), &mtx);
				mtx_f2l(&mtx, g_TitleModelJpnLogo1->matrices + mtxindex);
			}
		}
	}
#else
	mtx00015f88(1.0f + sp13c, &sp1e8);
	mtx4_mult_mtx4(&sp2b0, &sp1e8, &sp230);
	mtx00015f04(0.308f, &sp230);

	// Render the "PERFECT DARK" model
	if (g_PdLogoTitleStep >= 0) {
		if (g_PdLogoTitleStep == 0) {
			// empty
		} else if (g_PdLogoTitleStep == 1) {
			bool visible = g_PdLogoTitleStepFrac < 0.5f;
			model = g_TitleModelPdThree;
			gdl = title_render_pd_logo_model(gdl, model, visible, g_PdLogoTitleStepFrac, 255, g_PdLogoTitleStepFrac, &sp230, g_PdLogoVertices[g_PdLogoVtxColIndex], g_PdLogoColours[g_PdLogoVtxColIndex]);
		} else if (g_PdLogoTitleStep == 2) {
			bool visible = g_PdLogoTitleStepFrac < 0.5f;
			model = g_TitleModelPdTwo;
			gdl = title_render_pd_logo_model(gdl, model, visible, 1.0f - g_PdLogoTitleStepFrac, 255, 1.0f, &sp230, g_PdLogoVertices[g_PdLogoVtxColIndex], g_PdLogoColours[g_PdLogoVtxColIndex]);
		} else if (g_PdLogoTitleStep == 3) {
			bool visible = g_PdLogoTitleStepFrac < 0.5f;
			model = g_TitleModelPdTwo;
			gdl = title_render_pd_logo_model(gdl, model, visible, g_PdLogoTitleStepFrac, 255, 1.0f, &sp230, g_PdLogoVertices[g_PdLogoVtxColIndex], g_PdLogoColours[g_PdLogoVtxColIndex]);
		} else {
			model = g_TitleModelPdTwo;
			gdl = title_render_pd_logo_model(gdl, model, false, 1.0f, 255, 1.0f, &sp230, g_PdLogoVertices[g_PdLogoVtxColIndex], g_PdLogoColours[g_PdLogoVtxColIndex]);
		}
	}
#endif

	return gdl;
}

struct sndstate *g_TitleAudioHandle = NULL;
bool g_TitleTypewriterFinishing = false;

void title_init_rare_presents(void)
{
	g_TitleTimer = 0;
	joy00014810(false);
	g_TitleAudioHandle = NULL;
}

void title_exit_rare_presents(void)
{
	if (g_TitleAudioHandle) {
		audioStop(g_TitleAudioHandle);
	}

	g_TitleAudioHandle = NULL;
	joy00014810(true);
}

void title_tick_rare_presents(void)
{
	vi_set_fov_y(60);
	vi_set_aspect(1.33333333f);
	vi_set_z_range(100, 10000);
	vi_set_use_z_buf(false);

	g_TitleTimer += g_Vars.lvupdate60;

	if (g_TitleTimer > TICKS(300)) {
		title_set_next_mode(TITLEMODE_PDLOGO);
	} else if (joy_get_buttons_pressed_this_frame(0, 0xffff)) {
		title_set_next_mode(TITLEMODE_SKIP);
	}
}

Gfx *title_render_typewriter_text(Gfx *gdl, s32 *x, s32 *y, u16 textnum, s32 timer, s32 *colourcomponent)
{
	s32 lentoprint = timer / 3;
	char *text = lang_get(textnum);
	s32 i;
	u8 buffer[] = {'\0', '\0'};
	s32 fulllen = strlen(text);

	if (lentoprint <= 0) {
		return gdl;
	}

	if (lentoprint > fulllen) {
		lentoprint = fulllen;
	}

	for (i = 0; i < lentoprint; i++) {
		s32 remaining = timer - 3 * i;
		s32 tmp;

		if (remaining > 60) {
			remaining = 60;
		}

		if (remaining < 10) {
			g_TitleTypewriterFinishing = true;
		}

		*colourcomponent = tmp = (60 - remaining) * 255 / 60;

		buffer[0] = text[i];
		gdl = text_render_v2(gdl, x, y, buffer, g_CharsHandelGothicLg, g_FontHandelGothicLg,
				0x7f7fffff | (tmp << 8) | (tmp << 16), vi_get_width(), vi_get_height(), 0, 0);
	}

	return gdl;
}

Gfx *title_render_rare_presents(Gfx *gdl)
{
	s32 x;
	s32 y;
	s32 colourcomponent = 255;

	gdl = title_clear(gdl);
	gdl = text_begin(gdl);

	x = vi_get_view_left() + 50;
	y = vi_get_view_top() + vi_get_view_height() - 80;

	g_TitleTypewriterFinishing = false;

	if (g_TitleMode == TITLEMODE_RAREPRESENTS1) {
		gdl = title_render_typewriter_text(gdl, &x, &y, L_OPTIONS_005, g_TitleTimer, &colourcomponent); // "earth:"

		if (g_TitleTimer > 70) {
			x = vi_get_view_left() + 50;
			y = vi_get_view_top() + vi_get_view_height() - 60;
			gdl = title_render_typewriter_text(gdl, &x, &y, L_OPTIONS_006, g_TitleTimer - 100, &colourcomponent); // "   prehistory"
		}
	} else {
		gdl = title_render_typewriter_text(gdl, &x, &y, L_OPTIONS_007, g_TitleTimer - 35, &colourcomponent); // "rare presents"
	}

	gdl = text_end(gdl);

	if (g_TitleTypewriterFinishing) {
		if (g_TitleAudioHandle == NULL) {
			snd_start(var80095200, SFX_HUDMSG, &g_TitleAudioHandle, -1, -1, -1, -1, -1);
		}
	} else {
		if (g_TitleAudioHandle) {
			audioStop(g_TitleAudioHandle);
		}

		g_TitleAudioHandle = NULL;
	}

	if (((s32)(g_20SecIntervalFrac * 80.0f) % 2) == 0) {
		u32 colour = (colourcomponent << 8) | 0x7f7fffff | (colourcomponent << 16);
		gdl = text_draw_box(gdl, x + 2, y, x + 12, y + 20, colour);
	}

	gdl = bview_draw_intro_text(gdl);

	if (g_TitleTimer > TICKS(222)) {
		f32 alpha = ((g_TitleTimer - TICKS(222.0f)) / TICKS(78.0f));
		u32 stack;

		gdl = text_draw_box(gdl, vi_get_view_left(), vi_get_view_top(),
				vi_get_view_left() + vi_get_view_width(),
				vi_get_view_top() + vi_get_view_height(),
				255.0f * alpha);
	}

	return gdl;
}

void title_init_nintendo_logo(void)
{
	u8 *nextaddr = var8009cca0;

	g_TitleFastForward = false;

	if (g_TitleButtonPressed) {
		g_TitleTimer = VERSION == VERSION_PAL_FINAL ? TICKS(160) : TICKS(180);
	} else {
		g_TitleTimer = 0;
	}

	{
		struct coord coord = {0, 0, 0};

		g_ModelStates[MODEL_NINTENDOLOGO].modeldef = modeldef_load(g_ModelStates[MODEL_NINTENDOLOGO].fileid, nextaddr, TITLE_ALLOCSIZE, 0);

		model_allocate_rw_data(g_ModelStates[MODEL_NINTENDOLOGO].modeldef);
		g_TitleModel = modelmgr_instantiate_model_without_anim(g_ModelStates[MODEL_NINTENDOLOGO].modeldef);
		model_set_scale(g_TitleModel, 1);
		model_set_root_position(g_TitleModel, &coord);
		var800624f4 = 1;
		joy00014810(false);
	}
}

void title_exit_nintendo_logo(void)
{
	modelmgr_free_model(g_TitleModel);
	joy00014810(true);
}

/**
 * If no button has been pressed during the Rare logo (so g_TitleButtonPressed
 * is false) and the player presses a button within 140 ticks of the Nintendo
 * logo, the Nintendo logo sequence will play at double speed until it exits at
 * the 140 tick mark.
 */
void title_tick_nintendo_logo(void)
{
	vi_set_fov_y(60);
	vi_set_aspect(1.33333333f);
	vi_set_z_range(100, 10000);
	vi_set_use_z_buf(false);

	g_TitleTimer += g_Vars.lvupdate60;

	if (g_TitleFastForward) {
		g_TitleTimer += g_Vars.lvupdate60;
	}

	if (joy_get_buttons_pressed_this_frame(0, 0xffff)) {
		if (osResetType == RESETTYPE_WARM) {
			g_TitleButtonPressed = true;
			title_set_next_mode(TITLEMODE_PDLOGO);
		} else if (!g_TitleButtonPressed) {
			g_TitleFastForward = true;
		}
	}

	if (g_TitleFastForward && !g_TitleButtonPressed && g_TitleTimer > TICKS(140)) {
		g_TitleButtonPressed = true;
		g_TitleFastForward = false;
		title_set_next_mode(TITLEMODE_PDLOGO);
	}

#if VERSION == VERSION_PAL_FINAL
	if (g_TitleTimer > TICKS(220))
#else
	if (g_TitleTimer > TICKS(240))
#endif
	{
		title_set_next_mode(TITLEMODE_PDLOGO);
	}
}

Gfx *title_render_nintendo_logo(Gfx *gdl)
{
	struct modelrenderdata renderdata = { NULL, true, 3 };
	s32 i;
	s32 j;
	Mtxf sp108;
	f32 fracdone = g_TitleTimer / (VERSION == VERSION_PAL_FINAL ? 183.0f : TICKS(240.0f));
	struct coord lightdir = {0, 0, 0};
	s32 v0;

	gdl = title_clear(gdl);

	gSPSetLights1(gdl++, g_TitleLightNintendoRare);

	lightdir.z = sinf((1 - fracdone) * 1.5f * DTOR(180));
	lightdir.x = cosf((1 - fracdone) * 1.5f * DTOR(180));

	guNormalize(&lightdir.x, &lightdir.y, &lightdir.z);

	v0 = 255;

	if (fracdone < 0.1f) {
		v0 = 255.0f * fracdone / 0.1f;
	}

	if (fracdone > 0.9f) {
		v0 = (1 - fracdone) * 255.0f / 0.1f;
	}

	if (v0 > 255) {
		v0 = 255;
	}

	if (v0 < 0) {
		v0 = 0;
	}

	title_set_light(&g_TitleLightNintendoRare, v0, v0, v0, 0.0f, &lightdir);

	{
		Mtxf spa8;
		struct coord sp9c;
		s32 stack[2];
		Mtxf sp54;

		sp9c.x = 0.0f;

		if (fracdone < 0.4f) {
			sp9c.x = (-cosf((1.0f - fracdone / .4f) * DTOR(180)) * 0.5f + 0.5f) * DTOR(90);
		}

		sp9c.y = (-cosf((1.0f - (fracdone / 1)) * DTOR(180)) * 0.5f + .5f) * 0.35f;
		sp9c.z = 0.0f;

		mtx4_load_rotation(&sp9c, &spa8);
		mtx00015f88(fracdone * 0.2f + 1.0f, &spa8);

		mtx00016ae4(&sp108,
				/* pos  */ 0.0f, 0.0f, 4000,
				/* look */ 0.0f, 0.0f, 0.0f,
				/* up   */ 0.0f, 1.0f, 0.0f);

		mtx4_mult_mtx4_in_place(&sp108, &spa8);
		mtx4_copy(&spa8, &sp108);
		renderdata.unk00 = &sp108;

		renderdata.unk10 = gfx_allocate(g_TitleModel->definition->nummatrices * sizeof(Mtxf));
		mtx4_copy(&sp108, renderdata.unk10);
		g_TitleModel->matrices = renderdata.unk10;

		model_update_relations(g_TitleModel);

		renderdata.flags = 3;
		renderdata.zbufferenabled = false;
		renderdata.gdl = gdl;

		model_render(&renderdata, g_TitleModel);

		gdl = renderdata.gdl;

		for (i = 0, j = 0; i < g_TitleModel->definition->nummatrices; i++, j += sizeof(Mtxf)) {
			mtx4_copy((Mtxf *)((uintptr_t)g_TitleModel->matrices + j), &sp54);
			mtx_f2l(&sp54, g_TitleModel->matrices + i);
		}
	}

	return gdl;
}

void title_init_rare_logo(void)
{
	u8 *nextaddr = var8009cca0;

	g_TitleTimer = -3;

	{
		struct coord coord = {0, 0, 0};

		g_ModelStates[MODEL_RARELOGO].modeldef = modeldef_load(g_ModelStates[MODEL_RARELOGO].fileid, nextaddr, TITLE_ALLOCSIZE, 0);

		model_allocate_rw_data(g_ModelStates[MODEL_RARELOGO].modeldef);
		g_TitleModel = modelmgr_instantiate_model_without_anim(g_ModelStates[MODEL_RARELOGO].modeldef);
		model_set_scale(g_TitleModel, 1);
		model_set_root_position(g_TitleModel, &coord);

		var800624f4 = 1;

		music_queue_stop_all_event();
		joy00014810(false);

		if (!g_IsTitleDemo && IS8MB()) {
			g_IsTitleDemo = true;
		}
	}
}

void title_exit_rare_logo(void)
{
	modelmgr_free_model(g_TitleModel);
	joy00014810(true);
}

/**
 * If a button is pressed between 0-59 ticks, set the timer to 100 and schedule
 * the next mode for 140 (ie. in 40 ticks time).
 *
 * If a button is pressed at 60+ ticks, set the next mode immediately.
 *
 * So the fastest way to skip through the Rare logo is to press a button as
 * early as possible, but if you press the button between 20-59 ticks it'll end
 * up taking longer than if you'd waited a second.
 */
void title_tick_rare_logo(void)
{
	vi_set_fov_y(60);
	vi_set_aspect(1.33333333f);
	vi_set_z_range(100, 10000);
	vi_set_use_z_buf(false);

	if (g_TitleTimer < 0) {
		g_TitleTimer++;
	} else {
		if (g_TitleTimer == 0) {
			music_queue_start_event(TRACKTYPE_PRIMARY, MUSIC_TITLE1, 0, 0x7fff);
		}

		g_TitleTimer += g_Vars.lvupdate60;

		if (joy_get_buttons_pressed_this_frame(0, 0xffff)) {
			if (osResetType == RESETTYPE_WARM) {
				g_TitleButtonPressed = true;
				title_set_next_mode(TITLEMODE_PDLOGO);
			} else if (!g_TitleButtonPressed) {
				if (g_TitleTimer < TICKS(60)) {
					g_TitleButtonPressed = true;

					if (g_TitleTimer < TICKS(100)) {
						g_TitleTimer = TICKS(100);
					}
				} else {
					g_TitleFastForward = true;
					g_TitleButtonPressed = true;
				}
			}
		}

		if (g_TitleTimer > TICKS(240)
				|| g_TitleFastForward
				|| (g_TitleButtonPressed && g_TitleTimer > TICKS(140))) {
			title_set_next_mode(TITLEMODE_NINTENDOLOGO);
		}
	}
}

f32 func0f019d0c(f32 arg0)
{
	return ((1.0f - arg0) + (1.0f - arg0)) * DTOR(180) - DTOR(90);
}

Gfx *title_render_rare_logo(Gfx *gdl)
{
	struct modelrenderdata renderdata = { NULL, true, 3 };
	s32 i;
	f32 fracdone = g_TitleTimer / TICKS(240.0f);
	Mtxf sp118;
	s32 j;
	s32 s0;

	static f32 var80062920 = 0;

	gdl = title_clear(gdl);

	if (g_TitleTimer < 0) {
		return gdl;
	}

	{
		struct coord lightdir = {0, 0, 0};
		f32 tmp;
		Mtxf spc0;
		struct coord spb4;
		struct modelrwdata_toggle *rwdata;

		lightdir.z = sinf(func0f019d0c(fracdone));
		lightdir.x = cosf(func0f019d0c(fracdone));

		guNormalize(&lightdir.x, &lightdir.y, &lightdir.z);

		s0 = 255;

		if (fracdone < 0.1f) {
			s0 = 255.0f * fracdone / 0.1f;
		}

		if (s0 > 255) {
			s0 = 255;
		}

		if (s0 < 0) {
			s0 = 0;
		}

		if (fracdone < 0.2f) {
			title_set_light(&g_TitleLightNintendoRare,
					(s32)(255.0f * fracdone / 0.2f),
					(s32)(255.0f * fracdone / 0.2f),
					(s32)(255.0f * fracdone / 0.2f),
					0, &lightdir);
		} else {
			title_set_light(&g_TitleLightNintendoRare, s0, s0, s0, 0, &lightdir);
		}

		s0 = s0 * 192 / 255;

		if (fracdone < 0.5f) {
			lightdir.z = sinf(func0f019d0c(0.5f));
			lightdir.x = cosf(func0f019d0c(0.5f));
			guNormalize(&lightdir.x, &lightdir.y, &lightdir.z);
			title_set_light(&var800625a8, s0, s0, s0, 0, &lightdir);
		} else {
			title_set_light(&var800625a8, s0, s0, s0, 0, &lightdir);
		}

		var80062920 += g_Vars.lvupdate60f / 90;

		tmp = 1 - fracdone * 1;

		spb4.x = 0;
		spb4.y = DTOR(90) * tmp;
		spb4.z = 0;

		mtx4_load_rotation(&spb4, &spc0);
		mtx00015f88(1 + fracdone * 0.25f, &spc0);

		mtx00016ae4(&sp118,
				/* pos  */ 0, 0, 4000,
				/* look */ 0, 0, 0,
				/* up   */ 0, 1, 0);

		mtx4_mult_mtx4_in_place(&sp118, &spc0);
		mtx4_copy(&spc0, &sp118);

		renderdata.unk00 = &sp118;
		renderdata.unk10 = gfx_allocate(g_TitleModel->definition->nummatrices * sizeof(Mtxf));
		mtx4_copy(&sp118, renderdata.unk10);

		g_TitleModel->matrices = renderdata.unk10;

		model_update_relations(g_TitleModel);

		rwdata = model_get_node_rw_data(g_TitleModel, model_get_part(g_TitleModel->definition, MODELPART_RARELOGO_000B));

		if (rwdata) {
			rwdata->visible = false;
		}

		rwdata = model_get_node_rw_data(g_TitleModel, model_get_part(g_TitleModel->definition, MODELPART_RARELOGO_000D));

		if (rwdata) {
			rwdata->visible = true;
		}

		rwdata = model_get_node_rw_data(g_TitleModel, model_get_part(g_TitleModel->definition, MODELPART_RARELOGO_000C));

		if (rwdata) {
			rwdata->visible = false;
		}

		gSPSetLights1(gdl++, g_TitleLightNintendoRare);

		renderdata.flags = 3;
		renderdata.zbufferenabled = 0;
		renderdata.gdl = gdl;

		model_render(&renderdata, g_TitleModel);

		gdl = renderdata.gdl;

		rwdata = model_get_node_rw_data(g_TitleModel, model_get_part(g_TitleModel->definition, MODELPART_RARELOGO_000B));

		if (rwdata) {
			rwdata->visible = true;
		}

		rwdata = model_get_node_rw_data(g_TitleModel, model_get_part(g_TitleModel->definition, MODELPART_RARELOGO_000D));

		if (rwdata) {
			rwdata->visible = false;
		}

		rwdata = model_get_node_rw_data(g_TitleModel, model_get_part(g_TitleModel->definition, MODELPART_RARELOGO_000C));

		if (rwdata) {
			rwdata->visible = true;
		}

		gSPSetLights1(gdl++, g_TitleLightNintendoRare);

		renderdata.flags = 3;
		renderdata.zbufferenabled = 0;
		renderdata.gdl = gdl;

		model_render(&renderdata, g_TitleModel);

		gdl = renderdata.gdl;

		for (i = 0, j = 0; i < g_TitleModel->definition->nummatrices; i++, j += sizeof(Mtxf)) {
			Mtxf sp58;
			mtx4_copy((Mtxf *)((uintptr_t)g_TitleModel->matrices + j), &sp58);
			mtx_f2l(&sp58, g_TitleModel->matrices + i);
		}
	}

	return gdl;
}

s32 g_NumPlayers = 0;
u32 var80062928 = 0x00000000;
u32 var8006292c = 0x00000001;
u32 var80062930 = 0x00000001;
u32 var80062934 = 0x00000001;
u32 var80062938 = 0x00000000;

s32 get_num_players(void)
{
	return g_NumPlayers;
}

void set_num_players(s32 numplayers)
{
	g_NumPlayers = numplayers;
}

s32 player_get_team(s32 playernum)
{
	return g_PlayerConfigsArray[g_Vars.playerstats[playernum].mpindex].base.team;
}

void player_set_team(s32 playernum, s32 team)
{
	g_PlayerConfigsArray[g_Vars.playerstats[playernum].mpindex].base.team = team;
}

void title_init_skip(void)
{
	g_TitleNextStage = STAGE_CITRAINING;

	set_num_players(1);

	if (g_IsTitleDemo) {
		g_TitleNextStage = STAGE_DEFECTION;
		g_IsTitleDemo++;
	}

	if (IS4MB()) {
		g_TitleNextStage = STAGE_4MBMENU;
		vi_set_aspect(PAL ? 1.7316017150879f : ((f32) FBALLOC_WIDTH_LO / (f32) FBALLOC_HEIGHT_LO));
		vi_set_size(FBALLOC_WIDTH_LO, FBALLOC_HEIGHT_LO);
		vi_set_buf_size(FBALLOC_WIDTH_LO, FBALLOC_HEIGHT_LO);
		playermgr_set_view_size(FBALLOC_WIDTH_LO, FBALLOC_HEIGHT_LO);
		vi_set_view_size(FBALLOC_WIDTH_LO, FBALLOC_HEIGHT_LO);
	}

	main_change_to_stage(g_TitleNextStage);

	g_Vars.bondplayernum = 0;
	g_Vars.coopplayernum = -1;
	g_Vars.antiplayernum = -1;

	lv_set_difficulty(DIFF_A);
	vi_black(true);
}

void title_init_no_controller(void)
{
	g_TitleTimer = 0;
}

void title_exit_no_controller(void)
{
	// empty
}

void title_tick_no_controller(void)
{
	vi_set_fov_y(60);
	vi_set_aspect(1.33333333f);
	vi_set_z_range(100, 10000);
	vi_set_use_z_buf(false);

	g_TitleTimer += g_Vars.lvupdate60;
}

Gfx *title_render_no_controller(Gfx *gdl)
{
	s32 textheight;
	s32 textwidth;
	s32 x;
	s32 y;
	char *text;
	u32 stack[2];
	s16 tmp;
	s16 width;

	if (1);
	if (1);
	if (1);

	// This was likely printed to console
	joy_get_connected_controllers();

	gdl = title_clear(gdl);
	gdl = text_begin(gdl);

#if VERSION >= VERSION_JPN_FINAL
	y = g_TitleViewHeight / 2 - 50;

	g_TextScaleX = 2;
	var80080108jf = 2;

	// Line 1
	text = lang_get(L_MPWEAPONS_285);
	text_measure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = 288 - textwidth;
	gdl = text_render_v2(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, vi_get_width(), vi_get_height(), 0, 0);
	y += 18;

	// Line 2
	text = lang_get(L_MPWEAPONS_286);
	text_measure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = 288 - textwidth;
	gdl = text_render_v2(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, vi_get_width(), vi_get_height(), 0, 0);
	y += 28;

	// Line 3
	text = lang_get(L_MPWEAPONS_287);
	text_measure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = 288 - textwidth;
	gdl = text_render_v2(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, vi_get_width(), vi_get_height(), 0, 0);
	y += 18;

	// Line 4
	text = lang_get(L_MPWEAPONS_288);
	text_measure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = 288 - textwidth;
	gdl = text_render_v2(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, vi_get_width(), vi_get_height(), 0, 0);
	y += 18;

	g_TextScaleX = 1;
	var80080108jf = 1;
#else
	// Line 1
	text = lang_get(L_OPTIONS_071); // "- no controller in controller socket 1 -"
	text_measure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = 288 - (textwidth >> 1);
	y = (g_TitleViewHeight / 2) - (textheight >> 1) - 12;

	if (g_Jpn) {
		width = vi_get_width();
		gdl = text_render_v1(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, 0x008000ff, width, vi_get_height(), 0, 0);
	} else {
		width = vi_get_width();
		gdl = text_render_v2(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, width, vi_get_height(), 0, 0);
	}

	// Line 2
	text = lang_get(L_OPTIONS_072); // "please power off and attach a controller"
	text_measure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = 288 - (textwidth >> 1);
	y = (g_TitleViewHeight / 2) - (textheight >> 1) + 12;

	if (g_Jpn) {
		width = vi_get_width();
		gdl = text_render_v1(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, 0x008000ff, width, vi_get_height(), 0, 0);
	} else {
		width = vi_get_width();
		gdl = text_render_v2(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, width, vi_get_height(), 0, 0);
	}
#endif

	gdl = text_end(gdl);

	return gdl;
}

#if VERSION >= VERSION_JPN_FINAL
void title_init_no_expansion(void)
{
	g_TitleTimer = 0;
}
#endif

#if VERSION >= VERSION_JPN_FINAL
void title_exit_no_expansion(void)
{
	// empty
}
#endif

#if VERSION >= VERSION_JPN_FINAL
void title_tick_no_expansion(void)
{
	vi_set_fov_y(60);
	vi_set_aspect(1.33333333f);
	vi_set_z_range(100, 10000);
	vi_set_use_z_buf(0);

	g_TitleTimer += g_Vars.lvupdate60;
}
#endif

#if VERSION >= VERSION_JPN_FINAL
Gfx *title_render_no_expansion(Gfx *gdl)
{
	s32 textheight;
	s32 textwidth;
	s32 x;
	s32 y;
	char *text;
	u32 stack[2];
	s16 tmp;
	s16 width;

	if (1);
	if (1);
	if (1);

	joy_get_connected_controllers();

	gdl = title_clear(gdl);
	gdl = text_begin(gdl);

	x = 50;
	y = g_TitleViewHeight / 2 - 36;

	g_TextScaleX = 2;
	var80080108jf = 2;

	text = lang_get(L_MPWEAPONS_281);
	text_measure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);
	x = 288 - textwidth;
	width = vi_get_width();
	gdl = text_render_v2(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, width, vi_get_height(), 0, 0);
	y += 18;

	text = lang_get(L_MPWEAPONS_282);
	text_measure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);
	x = 288 - textwidth;
	width = vi_get_width();
	gdl = text_render_v2(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, width, vi_get_height(), 0, 0);
	y += 18;

	text = lang_get(L_MPWEAPONS_284);
	text_measure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);
	x = 288 - textwidth;
	width = vi_get_width();
	gdl = text_render_v2(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, width, vi_get_height(), 0, 0);
	y += 18;

	g_TextScaleX = 1;
	var80080108jf = 1;

	gdl = text_end(gdl);

	return gdl;
}
#endif

void title_set_next_mode(s32 mode)
{
	if (g_TitleDelayedMode != mode) {
		g_TitleNextMode = mode;
	}
}

s32 title_get_mode(void)
{
	return g_TitleMode;
}

void title_tick(void)
{
#if PAL
	vi_set_aspect(576.0f / g_TitleViewHeight * 1.1904761791229f);
#else
	vi_set_aspect(576.0f / g_TitleViewHeight);
#endif
	vi_set_size(576, g_TitleViewHeight);
	vi_set_buf_size(576, g_TitleViewHeight);
	playermgr_set_view_size(576, g_TitleViewHeight);
	vi_set_view_size(576, g_TitleViewHeight);
	playermgr_set_view_position(0, 0);
	vi_set_view_position(0, 0);

	// If there's a new mode to transition to, schedule it to apply in 3 ticks
	// time and call the exit function for the current mode.
	if (g_TitleNextMode >= 0) {
		g_TitleDelayedTimer = 3;
		g_TitleDelayedMode = g_TitleNextMode;

		switch (g_TitleMode) {
		case TITLEMODE_LEGAL:
			title_exit_legal();
			break;
		case TITLEMODE_CHECKCONTROLLERS:
			title_exit_check_controllers();
			break;
		case TITLEMODE_PDLOGO:
			title_exit_pd_logo();
			break;
		case TITLEMODE_NINTENDOLOGO:
			title_exit_nintendo_logo();
			break;
		case TITLEMODE_RARELOGO:
			title_exit_rare_logo();
			break;
		case TITLEMODE_NOCONTROLLER:
			title_exit_no_controller();
			break;
#if VERSION >= VERSION_JPN_FINAL
		case TITLEMODE_NOEXPANSION:
			title_exit_no_expansion();
			break;
#endif
		}

		if (g_TitleMode != TITLEMODE_CHECKCONTROLLERS) {
			vi_black(true);
		}

		g_TitleNextMode = -1;
	}

	// If there's a new mode scheduled, tick the timer down
	if (g_TitleDelayedTimer != 0) {
		g_TitleDelayedTimer--;

		if (g_TitleMode == -1) {
			g_TitleDelayedTimer = 0;
		}

		if (g_TitleDelayedTimer == 0 && g_TitleDelayedMode != -1) {
			g_TitleNextMode = g_TitleDelayedMode;
			g_TitleDelayedMode = -1;
		}
	}

	// Apply new mode
	if (g_TitleNextMode >= 0) {
		g_TitleMode = g_TitleNextMode;
		g_TitleNextMode = -1;
		g_TitleFastForward = false;

		switch (g_TitleMode) {
		case TITLEMODE_LEGAL:
			title_init_legal();
			break;
		case TITLEMODE_CHECKCONTROLLERS:
			title_init_check_controllers();
			break;
		case TITLEMODE_PDLOGO:
			title_init_pd_logo();
			break;
		case TITLEMODE_NINTENDOLOGO:
			title_init_nintendo_logo();
			break;
		case TITLEMODE_RARELOGO:
			title_init_rare_logo();
			break;
		case TITLEMODE_SKIP:
			title_init_skip();
			break;
		case TITLEMODE_NOCONTROLLER:
			title_init_no_controller();
			break;
#if VERSION >= VERSION_JPN_FINAL
		case TITLEMODE_NOEXPANSION:
			title_init_no_expansion();
			break;
#endif
		}

		if (g_TitleMode != TITLEMODE_CHECKCONTROLLERS && g_TitleMode != TITLEMODE_SKIP) {
			vi_black(false);
		}
	}

	// Run the current mode's tick function
	switch (g_TitleMode) {
	case TITLEMODE_LEGAL:
		title_tick_legal();
		break;
	case TITLEMODE_CHECKCONTROLLERS:
		title_tick_check_controllers();
		break;
	case TITLEMODE_PDLOGO:
		title_tick_pd_logo();
		break;
	case TITLEMODE_NINTENDOLOGO:
		title_tick_nintendo_logo();
		break;
	case TITLEMODE_RARELOGO:
		title_tick_rare_logo();
		break;
	case TITLEMODE_NOCONTROLLER:
		title_tick_no_controller();
		break;
#if VERSION >= VERSION_JPN_FINAL
	case TITLEMODE_NOEXPANSION:
		title_tick_no_expansion();
		break;
#endif
	case TITLEMODE_SKIP:
		vi_set_use_z_buf(false);
		title_set_next_mode(TITLEMODE_RARELOGO);
		break;
	}
}

bool title_is_changing_mode(void)
{
	return g_TitleNextMode >= 0;
}

bool title_is_keeping_mode(void)
{
	if (g_TitleNextMode >= 0) {
		return false;
	}

	if (g_TitleMode == -1 || g_TitleMode == TITLEMODE_SKIP) {
		return false;
	}

	return true;
}

void title_exit(void)
{
	switch (g_TitleMode) {
	case TITLEMODE_LEGAL:
		title_exit_legal();
		break;
	case TITLEMODE_CHECKCONTROLLERS:
		title_exit_check_controllers();
		break;
	case TITLEMODE_PDLOGO:
		title_exit_pd_logo();
		break;
	case TITLEMODE_NINTENDOLOGO:
		title_exit_nintendo_logo();
		break;
	case TITLEMODE_RARELOGO:
		title_exit_rare_logo();
		break;
	case TITLEMODE_NOCONTROLLER:
		title_exit_no_controller();
		break;
#if VERSION >= VERSION_JPN_FINAL
	case TITLEMODE_NOEXPANSION:
		title_exit_no_expansion();
		break;
#endif
	case TITLEMODE_RAREPRESENTS1:
	case TITLEMODE_RAREPRESENTS2:
		title_exit_rare_presents();
		break;
	}

	g_TitleNextMode = -1;
	g_TitleMode = -1;
}

void title_init_from_ai_cmd(u32 value)
{
	switch (value) {
	case TITLEAIMODE_RAREPRESENTS1:
		g_TitleMode = TITLEMODE_RAREPRESENTS1;
		title_init_rare_presents();
		break;
	case TITLEAIMODE_RARELOGO:
		g_TitleMode = TITLEMODE_RARELOGO;
		title_init_rare_logo();
		break;
	case TITLEAIMODE_RAREPRESENTS2:
		g_TitleMode = TITLEMODE_RAREPRESENTS2;
		title_init_rare_presents();
		break;
	case TITLEAIMODE_NINTENDOLOGO:
		g_TitleMode = TITLEMODE_NINTENDOLOGO;
		title_init_nintendo_logo();
		break;
	case TITLEAIMODE_PDLOGO:
		g_TitleMode = TITLEMODE_PDLOGO;
		title_init_pd_logo();
		break;
	}

	g_TitleNextMode = -1;
}

bool func0f01ad5c(void)
{
	if (!title_is_keeping_mode()) {
		return false;
	}

	if (g_TitleMode == TITLEMODE_RAREPRESENTS2) {
		return false;
	}

	if (g_TitleMode == TITLEMODE_RAREPRESENTS1) {
		return false;
	}

	return true;
}

void func0f01adb8(void)
{
	vi_set_mode(VIMODE_HI);
	vi_set_size(576, g_TitleViewHeight);
	vi_set_buf_size(576, g_TitleViewHeight);
	playermgr_set_view_size(576, g_TitleViewHeight);
	vi_set_view_size(576, g_TitleViewHeight);
	playermgr_set_view_position(0, 0);
	vi_set_view_position(0, 0);
}

void title_tick_old(void)
{
	if (title_is_keeping_mode()) {
		joy00014810(false);

		if (g_TitleDelayedTimer == 0) {
			switch (g_TitleMode) {
			case TITLEMODE_LEGAL:
				title_tick_legal();
				break;
			case TITLEMODE_CHECKCONTROLLERS:
				title_tick_check_controllers();
				break;
			case TITLEMODE_PDLOGO:
				title_tick_pd_logo();
				break;
			case TITLEMODE_NINTENDOLOGO:
				title_tick_nintendo_logo();
				break;
			case TITLEMODE_RAREPRESENTS1:
			case TITLEMODE_RAREPRESENTS2:
				title_tick_rare_presents();
				break;
			case TITLEMODE_RARELOGO:
				title_tick_rare_logo();
				break;
			}
		}
	}
}

Gfx *title_render(Gfx *gdl)
{
	if (g_TitleDelayedTimer == 0) {
		switch (g_TitleMode) {
		case TITLEMODE_LEGAL:
			gdl = title_render_legal(gdl);
			break;
		case TITLEMODE_CHECKCONTROLLERS:
			gdl = title_render_check_controllers(gdl);
			break;
		case TITLEMODE_PDLOGO:
			gdl = title_render_pd_logo(gdl);
			break;
		case TITLEMODE_NINTENDOLOGO:
			gdl = title_render_nintendo_logo(gdl);
			break;
		case TITLEMODE_RAREPRESENTS1:
		case TITLEMODE_RAREPRESENTS2:
			gdl = title_render_rare_presents(gdl);
			break;
		case TITLEMODE_RARELOGO:
			gdl = title_render_rare_logo(gdl);
			break;
		case TITLEMODE_NOCONTROLLER:
			gdl = title_render_no_controller(gdl);
			break;
#if VERSION >= VERSION_JPN_FINAL
		case TITLEMODE_NOEXPANSION:
			gdl = title_render_no_expansion(gdl);
			break;
#endif
		}
	}

	return gdl;
}
