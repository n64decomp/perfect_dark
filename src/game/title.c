#include <ultra64.h>
#include "constants.h"
#include "game/title.h"
#include "game/bondgun.h"
#include "game/modelmgr.h"
#include "game/tex.h"
#include "game/inv.h"
#include "game/playermgr.h"
#include "game/gfxmemory.h"
#include "game/credits.h"
#include "game/bondview.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/music.h"
#include "game/training.h"
#include "game/modeldef.h"
#include "game/lang.h"
#include "game/propobj.h"
#include "game/savebuffer.h"
#include "bss.h"
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

static void titleSkipToPdTitle(void);

u8 *var8009cca0;
struct gfxvtx *var8009cca8[2];
u32 *var8009ccb0[2];
u32 var8009ccb8;

bool g_IsTitleDemo = false;
bool g_TitleButtonPressed = false;
bool g_TitleFastForward = false;
s32 g_TitleMode = -1;
s32 g_TitleNextMode = -1;
u32 g_TitleDelayedTimer = 2;
s32 g_TitleDelayedMode = -1;
s32 g_TitleTimer = 0;
s32 g_TitleNextStage = -1; // appears to be used for more than just title
u32 var800624f0 = 0x00000000;
struct model *g_TitleModel = NULL;
struct model *g_TitleModelNLogo2 = NULL;
struct model *g_TitleModelPdTwo = NULL;
struct model *g_TitleModelPdThree = NULL;


Lights1 var80062530 = gdSPDefLights1(0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
Lights1 var80062560 = gdSPDefLights1(0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);

Lights1 var80062578 = gdSPDefLights1(0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f);
Lights1 var80062590 = gdSPDefLights1(0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
Lights1 var800625a8 = gdSPDefLights1(0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f);


char *mpPlayerGetWeaponOfChoiceName(u32 playernum, u32 slot)
{
	char *name;
	s32 weapon1;
	s32 weapon2;
	u32 prevplayernum = g_Vars.currentplayernum;
	s32 weapon;

	setCurrentPlayerNum(playernum);

	invGetWeaponOfChoice(&weapon1, &weapon2);

	weapon = slot == 1 ? weapon2 : weapon1;

	name = bgunGetName(weapon);
	setCurrentPlayerNum(prevplayernum);

	return name;
}

static void titleSetLight(Lights1 *light, u8 r, u8 g, u8 b, f32 luminosity, struct coord *dir)
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

static void titleInitLegal(void)
{
	musicQueueStopAllEvent();
	g_TitleTimer = 0;
	g_TitleButtonPressed = false;
	g_TitleFastForward = false;
}

static void titleTickLegal(void)
{
	viSetFovY(60);
	viSetAspect(1.33333333f);
	viSetZRange(100, 10000);
	g_ViBackData->usezbuf = false;

	g_TitleTimer += g_Vars.lvupdate60;

	if (g_TitleTimer > TICKS(180)) {
		titleSetNextMode(TITLEMODE_CHECKCONTROLLERS);
	}
}

static void titleInitCheckControllers(void)
{
	g_TitleTimer = 0;
	viBlack(true);
}

static void titleExitCheckControllers(void)
{
	viConfigureForLogos();
	viSetMode(VIMODE_HI);
	viBlack(false);
}

static void titleTickCheckControllers(void)
{
	g_TitleTimer++;
	viSetZRange(100, 10000);
	g_ViBackData->usezbuf = false;

	if (g_TitleTimer > 6) {
		if ((joyGetConnectedControllers() & 1) == 0) {
			titleSetNextMode(TITLEMODE_NOCONTROLLER);
		} else {
			titleSetNextMode(TITLEMODE_RARELOGO);
		}
	}
}

static Gfx *titleRenderCheckControllers(Gfx *gdl)
{
	if (g_TitleTimer > 2 && g_TitleTimer < 6) {
		gdl = titleClear(gdl);
	}

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
	{ 266, 296, 0, 1, LEGALELEMENTTYPE_WHITETEXTSM, L_OPTIONS_075 }, // "tm"
	{ 286, 299, 0, 1, LEGALELEMENTTYPE_WHITETEXTLG, L_OPTIONS_074 }, // "NOT DETECTED"
	{ 69,  320, 1, 1, LEGALELEMENTTYPE_LINE,        0             },
	{ 69,  328, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_OPTIONS_087 }, // "The Rarewere Logo and Perfect Dark are ..."
	{ 138, 343, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_OPTIONS_088 }, // "Presented in Dolby Surround. Dolby and ..."
	{ 69,  372, 0, 1, LEGALELEMENTTYPE_BLUETEXTMD,  L_OPTIONS_089 }, // "Uses Miles Sound System ..."
	{ 69,  428, 1, 1, LEGALELEMENTTYPE_LINE,        0             },
	{ 69,  433, 0, 1, LEGALELEMENTTYPE_BLUETEXTSM,  L_OPTIONS_093 }, // "rare designs on the future <<<"
	{ 69,  344, 0, 1, LEGALELEMENTTYPE_DOLBYLOGO,   0             },
};

static Gfx *titleRenderLegal(Gfx *gdl)
{
	struct legalelement *elem;
	struct legalelement *end;
	struct modelrenderdata renderdata = { NULL, true, 3 };
	s32 x;
	s32 y;
	struct fontchar *font1;
	struct font *font2;

	if (g_LegalEnabled) {
		gdl = titleClear(gdl);
		gdl = text0f153628(gdl);

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
					elem->textid = L_OPTIONS_073;
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
				gdl = text0f153780(gdl);
				gdl = text0f153a34(gdl, elem->x, elem->y, g_ViBackData->x, elem->y + 2, 0x7f7fff7f);
				gdl = text0f153628(gdl);
			} else if (elem->type == LEGALELEMENTTYPE_DOLBYLOGO) {
				gdl = text0f153780(gdl);

				gDPPipeSync(gdl++);
				gDPSetTexturePersp(gdl++, G_TP_NONE);
				gDPSetAlphaCompare(gdl++, G_AC_NONE);
				gDPSetTextureLOD(gdl++, G_TL_TILE);
				gDPSetTextureConvert(gdl++, G_TC_FILT);

				texSelect(&gdl, &g_TexGeneralConfigs[47], 1, 0, 2, 1, 0);

				gDPSetCycleType(gdl++, G_CYC_1CYCLE);
				gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
				gDPSetTextureFilter(gdl++, G_TF_POINT);

				gSPTextureRectangle(gdl++,
						elem->x << 2,
						elem->y << 2,
						(elem->x + 64) << 2,
						(elem->y + 24) << 2,
						G_TX_RENDERTILE, 0, 0x0300, 0x0400, -0x0400);

				gdl = text0f153628(gdl);
			} else if (elem->type == LEGALELEMENTTYPE_RARELOGO) {
				gdl = text0f153780(gdl);

				gDPPipeSync(gdl++);
				gDPSetTexturePersp(gdl++, G_TP_NONE);
				gDPSetAlphaCompare(gdl++, G_AC_NONE);
				gDPSetTextureLOD(gdl++, G_TL_TILE);
				gDPSetTextureConvert(gdl++, G_TC_FILT);

				texSelect(&gdl, &g_TexGeneralConfigs[49], 1, 0, 2, 1, 0);

				gDPSetCycleType(gdl++, G_CYC_1CYCLE);
				gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
				gDPSetTextureFilter(gdl++, G_TF_POINT);

				gSPTextureRectangle(gdl++,
						elem->x << 2,
						elem->y << 2,
						(elem->x + 32) << 2,
						(elem->y + 42) << 2,
						G_TX_RENDERTILE, 0, 0x0540, 0x0400, -0x0400);

				gdl = text0f153628(gdl);
			} else {
				x = elem->x;
				y = elem->y;
				gdl = textRenderProjected(gdl, &x, &y, langGet(elem->textid), font1, font2, colour, g_ViBackData->x, g_ViBackData->y, 0, 0);
			}
		}

		gdl = text0f153780(gdl);
	}

	return gdl;
}

bool g_LegalEnabled = true;
bool g_PdLogoIsFirstTick = true;
bool g_PdLogoTriggerExit = false;

static void titleInitPdLogo(void)
{
	u8 *nextaddr = var8009cca0;
	u32 remaining;
	u32 size;

	g_TitleTimer = 0;

	{
		struct coord coord = {0, 0, 0};
		g_ModelStates[MODEL_NLOGO].filedata = modeldefLoad(g_ModelStates[MODEL_NLOGO].fileid, nextaddr, 0x47800, 0);
		size = ALIGN64(fileGetLoadedSize(g_ModelStates[MODEL_NLOGO].fileid));
		nextaddr += size;
		remaining = 0x47800 - size;
		modelCalculateRwDataLen(g_ModelStates[MODEL_NLOGO].filedata);

		g_TitleModel = modelmgrInstantiateModelWithAnim(g_ModelStates[MODEL_NLOGO].filedata);
		g_TitleModel->scale = 1;
		modelSetRootPosition(g_TitleModel, &coord);
	}

	{
		struct coord coord = {0, 0, 0};
		g_ModelStates[MODEL_NLOGO2].filedata = modeldefLoad(g_ModelStates[MODEL_NLOGO2].fileid, nextaddr, remaining, 0);
		size = ALIGN64(fileGetLoadedSize(g_ModelStates[MODEL_NLOGO2].fileid));
		nextaddr += size;
		remaining -= size;
		modelCalculateRwDataLen(g_ModelStates[MODEL_NLOGO2].filedata);

		g_TitleModelNLogo2 = modelmgrInstantiateModelWithAnim(g_ModelStates[MODEL_NLOGO2].filedata);
		g_TitleModelNLogo2->scale = 1;
		modelSetRootPosition(g_TitleModelNLogo2, &coord);
	}

	{
		struct coord coord = {0, 0, 0};
		g_ModelStates[MODEL_PDTWO].filedata = modeldefLoad(g_ModelStates[MODEL_PDTWO].fileid, nextaddr, remaining, 0);
		size = ALIGN64(fileGetLoadedSize(g_ModelStates[MODEL_PDTWO].fileid));
		nextaddr += size;
		remaining -= size;
		modelCalculateRwDataLen(g_ModelStates[MODEL_PDTWO].filedata);

		g_TitleModelPdTwo = modelmgrInstantiateModelWithoutAnim(g_ModelStates[MODEL_PDTWO].filedata);
		g_TitleModelPdTwo->scale = 1;
		modelSetRootPosition(g_TitleModelPdTwo, &coord);
	}

	{
		struct coord coord = {0, 0, 0};
		g_ModelStates[MODEL_PDTHREE].filedata = modeldefLoad(g_ModelStates[MODEL_PDTHREE].fileid, nextaddr, remaining, 0);
		size = ALIGN64(fileGetLoadedSize(g_ModelStates[MODEL_PDTHREE].fileid));
		nextaddr += size;
		remaining -= size;
		modelCalculateRwDataLen(g_ModelStates[MODEL_PDTHREE].filedata);

		g_TitleModelPdThree = modelmgrInstantiateModelWithoutAnim(g_ModelStates[MODEL_PDTHREE].filedata);
		g_TitleModelPdThree->scale = 1;
		modelSetRootPosition(g_TitleModelPdThree, &coord);
	}

	{
		struct modelrodata_dl *rodata = (struct modelrodata_dl *)modelGetPartRodata(g_ModelStates[MODEL_PDTWO].filedata, MODELPART_LOGO_0002);

		size = ALIGN8(rodata->numvertices * sizeof(struct gfxvtx));

		var8009cca8[0] = (void *)nextaddr;

		nextaddr += size;
		remaining -= size;
		var8009cca8[1] = (void *)nextaddr;

		nextaddr += size;
		remaining -= size;
		size = ALIGN8(rodata->numcolours * sizeof(struct colour));
		var8009ccb0[0] = (void *)nextaddr;

		nextaddr += size;
		remaining -= size;
		var8009ccb0[1] = (void *)nextaddr;

		if (1);
		var8009ccb8 = 0;

		g_PdLogoIsFirstTick = true;
		g_PdLogoTriggerExit = false;

		if (g_TitleButtonPressed) {
			titleSkipToPdTitle();
		}
	}
}

static void titleExitPdLogo(void)
{
	modelmgrFreeModel(g_TitleModel);
	modelmgrFreeModel(g_TitleModelNLogo2);
	modelmgrFreeModel(g_TitleModelPdTwo);
	modelmgrFreeModel(g_TitleModelPdThree);
}

static void titleTickPdLogo(void)
{
	viSetFovY(46);
	viSetAspect(1.33333333f);
	viSetZRange(100, 10000);
	g_ViBackData->usezbuf = false;

	g_TitleTimer += g_Vars.lvupdate60;
	var8009ccb8 = 1 - var8009ccb8;

	if (g_PdLogoTriggerExit) {
		// Exiting due to player not pressing anything
		if (g_AltTitleEnabled) {
			g_TitleMode = TITLEMODE_SKIP;
			creditsRequestAltTitle();
			g_TitleNextStage = STAGE_CREDITS; // for alt title screen
			g_NumPlayers = 1;
			mainChangeToStage(g_TitleNextStage);

			g_Vars.bondplayernum = 0;
			g_Vars.coopplayernum = -1;
			g_Vars.antiplayernum = -1;

			lvSetDifficulty(DIFF_A);
			viBlack(true);
		} else {
			titleSetNextMode(TITLEMODE_SKIP);
		}
	}

	if (g_TitleButtonPressed && g_TitleTimer > TICKS(666)) {
		titleSetNextMode(TITLEMODE_SKIP);
	}

	if (joyGetButtonsPressedThisFrame(0, 0xffff)) {
		g_TitleButtonPressed = g_TitleFastForward = true;

		if (g_TitleTimer < TICKS(549)) {
			titleSetNextMode(TITLEMODE_PDLOGO);
		}
	}
}

static Gfx *titleRenderPdLogoModel(Gfx *gdl, struct model *model, bool arg2, f32 arg3, s32 arg4, f32 arg5, Mtxf *arg6, struct gfxvtx *vertices, u32 *colours)
{
	struct modelrenderdata renderdata = {NULL, true, 3};
	s32 tmp2;
	s32 i;
	s32 j;
	struct gfxvtx *sp100;
	struct colour *spfc;
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
	struct gfxvtx *a3;
	s32 alpha2;
	struct gfxvtx *t0;
	struct colour *s1;
	struct colour *s2;
	Mtxf sp6c;

	tmp = modelGetNodeRwData(model, modelGetPart(model->filedata, MODELPART_LOGO_0000));
	tmp->toggle.visible = arg2;

	tmp = modelGetNodeRwData(model, modelGetPart(model->filedata, MODELPART_LOGO_0001));
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
	spfc = (void *)colours;

	for (i = 0; i < 4; i++) {
		if (i == 0) {
			node1 = modelGetPart(model->filedata, MODELPART_LOGO_0002);
			node2 = modelGetPart(model->filedata, MODELPART_LOGO_0003);
		} else if (i == 1) {
			node1 = modelGetPart(model->filedata, MODELPART_LOGO_0004);
			node2 = modelGetPart(model->filedata, MODELPART_LOGO_0005);
		} else if (i == 2) {
			node1 = modelGetPart(model->filedata, MODELPART_LOGO_0006);
			node2 = modelGetPart(model->filedata, MODELPART_LOGO_0007);
		} else {
			node1 = modelGetPart(model->filedata, MODELPART_LOGO_0008);
			node2 = modelGetPart(model->filedata, MODELPART_LOGO_0009);
		}

		if (node1 && node2) {
			if (arg2) {
				s5rodata = &node1->rodata->dl;
				s1rodata = &node2->rodata->dl;
				rwdata = modelGetNodeRwData(model, node1);
			} else {
				s5rodata = &node2->rodata->dl;
				s1rodata = &node1->rodata->dl;
				rwdata = modelGetNodeRwData(model, node2);
			}

			s1 = (struct colour *)ALIGN8(s5rodata->numvertices * sizeof(struct gfxvtx) + (s32)s5rodata->vertices);
			s2 = (struct colour *)ALIGN8(s1rodata->numvertices * (s32) sizeof(struct gfxvtx) + (s32)s1rodata->vertices);

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

			sp100 = (void *)ALIGN8(s5rodata->numvertices * sizeof(struct gfxvtx) + (s32)sp100);
			spfc = (void *)ALIGN8(s5rodata->numcolours * sizeof(u32) + (s32)spfc);
		}
	}

	gDPSetPrimColor(gdl++, 0, 0, 0x00, 0x00, 0x00, alpha1);

	renderdata.unk00 = arg6;
	renderdata.unk10 = gfxAllocate(model->filedata->nummatrices * sizeof(Mtxf));

	mtx4Copy(arg6, renderdata.unk10);

	model->matrices = renderdata.unk10;

	model0001cc20(model);

	renderdata.flags = 3;
	renderdata.zbufferenabled = false;
	renderdata.gdl = gdl;

	modelRender(&renderdata, model);

	gdl = renderdata.gdl;

	for (j = 0, k = 0; j < model->filedata->nummatrices; j++, k += sizeof(Mtxf)) {
		mtx4Copy((Mtxf *)((u32)model->matrices + k), &sp6c);
		mtx00016054(&sp6c, model->matrices + j);
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
f32 g_PdLogoUnusedRot = 1.5705462694168;
bool g_PdLogoUnusedRotEnabled = false;
bool g_PdLogoLightMoving = false;
f32 g_PdLogoLightDirFrac = 0;


/**
 * Skip immediately to the "PERFECT DARK" part of the PdLogo mode.
 *
 * Assumes the title mode is already PdLogo, but at an earlier point.
 */
static void titleSkipToPdTitle(void)
{
	g_PdLogoYRotCur = 0;
	g_PdLogoYRotSpeed = 0;
	g_PdLogoXRotCur = 0;
	g_PdLogoXRotSpeed = 0;
	g_PdLogoScale = 0.35f;
	g_PdLogoFrac = 1;
	g_PdLogoTitleStepFrac = 0.63f;
	g_PdLogoUnusedRot = 1.6443619728088f;
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

	musicStartTemporaryPrimary(MUSIC_TITLE2);
}

static Gfx *titleRenderPdLogo(Gfx *gdl)
{
	struct modelrenderdata renderdata = { NULL, true, 3 }; // 2f0
	Mtxf sp2b0;
	Mtxf sp270;
	Mtxf sp230;
	struct model *model; // 22c
	Mtxf sp1e8;
	Mtxf sp1a8;
	struct modelnode *node;
	struct modelrodata_dl *rodata; // 164
	struct modelrwdata_dl *rwdata; // 160
	f32 sp13c = g_TitleTimer / 4500.0f - 0.1f;
	LookAt *lookat; // 134
	Mtx spf0;
	f32 spe4;
	f32 spe0;
	s32 numvertices; // dc
	s32 numcolours; // d8

	// b74
	if (g_PdLogoIsFirstTick) {
		g_PdLogoYRotCur = 4.2404751777649f;
		g_PdLogoYRotSpeed = 0.018846554681659f;
		g_PdLogoXRotCur = 0.47116386890411f;
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
		g_PdLogoUnusedRot = 1.5705462694168f;
		g_PdLogoLightMoving = false;
		g_PdLogoLightDirFrac = 0.0f;
	}

	// c7c
	if (g_PdLogoBlackTimer != 0) {
		g_PdLogoBlackTimer++;

		if (g_PdLogoBlackTimer >= 4) {
			g_PdLogoBlackTimer = 0;
			g_PdLogoYRotEnabled = true;
			g_PdLogoPreMorphTimer = 1;
		}
	}

	// ce4
	if (g_PdLogoYRotStopping) {
		if (g_PdLogoYRotCur < g_PdLogoEndYRot) {
			applySpeed(&g_PdLogoYRotCur, g_PdLogoEndYRot, &g_PdLogoYRotSpeed, 0.00018846555030905f, 0.00018846555030905f, 0.018846554681659f);

			if (g_PdLogoYRotCur >= g_PdLogoEndYRot) {
				g_PdLogoYRotCur = g_PdLogoEndYRot;
				g_PdLogoYRotSpeed = 0.0f;
			}

			if (g_PdLogoYRotCur >= M_BADTAU) {
				g_PdLogoYRotCur -= M_BADTAU;
				g_PdLogoEndYRot -= M_BADTAU;
			} else if (g_PdLogoYRotCur < 0.0f) {
				g_PdLogoYRotCur += M_BADTAU;
				g_PdLogoEndYRot += M_BADTAU;
			}
		}

		if (g_PdLogoYRotCur >= g_PdLogoEndYRot) {
			g_PdLogoYRotStopping = false;
		}
	} else /*e18*/ if (g_PdLogoYRotEnabled) {
		g_PdLogoYRotCur += g_PdLogoYRotSpeed * g_Vars.lvupdate60freal;

		if (g_PdLogoYRotCur >= M_BADTAU) {
			g_PdLogoYRotCur -= M_BADTAU;
		} else if (g_PdLogoYRotCur < 0.0f) {
			g_PdLogoYRotCur += M_BADTAU;
		}
	}

	// e90
	if (g_PdLogoPreMorphTimer != 0) {
		s32 duration = 80;

		g_PdLogoPreMorphTimer += g_Vars.lvupdate60;

		if (g_PdLogoPreMorphTimer > 0) {
			g_PdLogoFrac = (f32) g_PdLogoPreMorphTimer / (f32) duration;
		} else {
			g_PdLogoFrac = 0.0f;
		}

		if (g_PdLogoPreMorphTimer > duration) {
			g_PdLogoPreMorphTimer = 0;
			g_PdLogoMorphing = true;
			g_PdLogoFrac = 0.0f;
			g_PdLogoUseCombinedModel = true;
		}
	}

	// f14
	if (g_PdLogoMorphing) {
		g_PdLogoFrac += 0.004f * g_Vars.lvupdate60freal;

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

	// f80
	if (g_PdLogoMorphEndTimer != 0) {
		g_PdLogoMorphEndTimer += g_Vars.lvupdate60;

		if (g_PdLogoXRotCur > 0.0f) {
			// Implement the camera lowering effect, but it's actually
			// the model that rotates upwards to face the camera
			applyRotation(&g_PdLogoXRotCur, 0.0f, &g_PdLogoXRotSpeed, 0.00011307933164062f, 0.00011307933164062f, 0.011307933367789f);

			if (g_PdLogoXRotCur <= 0.0f) {
				g_PdLogoXRotCur = 0.0f;
				g_PdLogoXRotSpeed = 0.0f;
			}
		}

		if (g_PdLogoMorphEndTimer > 30 && g_PdLogoMorphEndTimer - g_Vars.lvupdate60 <= 30) {
			// Start slowing the spinning rotation
			g_PdLogoYRotEnabled = false;
			g_PdLogoYRotStopping = true;
			g_PdLogoEndYRot = ((s32) (g_PdLogoYRotCur * 4.0f / M_BADTAU) + 2) * M_BADTAU * 0.25f;
		}

		if (g_PdLogoMorphEndTimer > 100 && g_PdLogoMorphEndTimer - g_Vars.lvupdate60 <= 100) {
			g_PdLogoDarkenEnabled = true;
		}

		if (!g_PdLogoYRotStopping && g_PdLogoXRotCur <= 0.0f) {
			// Spinning has stopped and model is also facing camera vertically
			g_PdLogoMorphEndTimer = 0;
			g_PdLogoDarkenEnabled = true;
		}
	}

	// 118
	if (g_PdLogoDarkenEnabled) {
		// Fading out the side and back faces of the logo...
		// This is done by adjusting the ambient lighting. I guess the front
		// face is excluded from ambient light?
		g_PdLogoAmbientLightFrac -= 0.0075f * g_Vars.lvupdate60freal;

		if (g_PdLogoAmbientLightFrac <= 0.0f) {
			g_PdLogoAmbientLightFrac = 0.0f;
			g_PdLogoDarkenEnabled = false;
			g_PdLogoPreTitleTimer = 1;
		}
	}

	// 178
	if (g_PdLogoPreTitleTimer != 0) {
		g_PdLogoPreTitleTimer += g_Vars.lvupdate60;

		if (g_PdLogoPreTitleTimer > 20) {
			g_PdLogoPreTitleTimer = 0;
			g_PdLogoPointlessTimerEnabled = true;
		}
	}

	// 1a8
	if (g_PdLogoPointlessTimerEnabled) {
		g_PdLogoPointlessTimerEnabled = false;
		g_PdLogoPointlessTimer = 1;
	}

	// 1c4
	if (g_PdLogoPointlessTimer != 0) {
		g_PdLogoPointlessTimer += g_Vars.lvupdate60;

		if (g_PdLogoPointlessTimer > 0) {
			g_PdLogoPointlessTimer = 0;
			g_PdLogoTitlePresenting = true;
			g_PdLogoTitleStep = 1;
			g_PdLogoLightMoving = true;
		}
	}

	// 208
	if (g_PdLogoTitlePresenting) {
		g_PdLogoUnusedRotEnabled = true;

		if (g_PdLogoTitleStep == 0) {
			// Unreachable - step 0 is not used
			g_PdLogoTitleStepFrac += 0.025f;
		} else if (g_PdLogoTitleStep == 1) {
			g_PdLogoTitleStepFrac += 0.09f;
		} else {
			g_PdLogoTitleStepFrac += 0.1f;
		}

		if (g_PdLogoTitleStepFrac >= 1.0f) {
			g_PdLogoTitleStepFrac = 0.0f;
			g_PdLogoTitleStep++;

			if (g_PdLogoTitleStep == 10) {
				g_PdLogoTitlePresenting = false;
				g_PdLogoExitTimer = 1;
			}
		}
	}

	// 2d4
	if (g_PdLogoUnusedRotEnabled) {
		// Some unused value... maybe a different method of rotating the light?
		g_PdLogoUnusedRot += 0.0062821852043271f * g_Vars.lvupdate60freal;

		if (g_PdLogoUnusedRot >= M_BADTAU) {
			g_PdLogoUnusedRot -= M_BADTAU;
		}
	}

	// 32c
	if (g_PdLogoLightMoving) {
		g_PdLogoLightDirFrac += 0.017f * g_Vars.lvupdate60freal;

		if (g_PdLogoLightDirFrac >= 1.0f) {
			g_PdLogoLightDirFrac = 1.0f;
			g_PdLogoLightMoving = false;
		}
	}

	// 380
	if (g_PdLogoExitTimer != 0) {
		g_PdLogoExitTimer += g_Vars.lvupdate60;

		if (g_PdLogoExitTimer > 60) {
			g_PdLogoExitTimer = 0;
			g_PdLogoTriggerExit = true;
		}
	}

	// 3b0
	gdl = viSetFillColour(gdl, 0, 0, 0);
	gdl = viFillBuffer(gdl);

	if (g_PdLogoBlackTimer != 0) {
		return gdl;
	}

	lookat = gfxAllocateLookAt(2);

	guLookAtReflect(&spf0, lookat,
			0.0f, 0.0f, 4000.0f,
			0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f);

	gSPLookAt(gdl++, lookat);

	spe4 = (g_PdLogoLightDirFrac + -1.0f) * M_PI + M_PI;
	spe0 = (0.0f - 0.15f * g_PdLogoLightDirFrac) * M_PI + M_PI;

	var80062578.a.l.colc[0] = var80062578.a.l.colc[1] = var80062578.a.l.colc[2] = 0;
	var80062578.a.l.col[0] = var80062578.a.l.col[1] = var80062578.a.l.col[2] = 0;
	var80062578.l[0].l.colc[0] = var80062578.l[0].l.colc[1] = var80062578.l[0].l.colc[2] = 255;
	var80062578.l[0].l.col[0] = var80062578.l[0].l.col[1] = var80062578.l[0].l.col[2] = 255;

	var80062578.l[0].l.dir[0] = 127.0f * sinf(spe4) * cosf(spe0);
	var80062578.l[0].l.dir[1] = 127.0f * sinf(spe0);
	var80062578.l[0].l.dir[2] = 127.0f * cosf(spe4) * cosf(spe0);

	mtx00016ae4(&sp2b0,
			0.0f, 0.0f, 4000,
			0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f);

	if (g_PdLogoUseCombinedModel == true) {
		model = g_TitleModel;
	} else {
		model = g_TitleModelNLogo2;
	}

	mtx4LoadYRotation(g_PdLogoYRotCur, &sp1e8);
	mtx4LoadXRotation(g_PdLogoXRotCur, &sp1a8);
	mtx4MultMtx4InPlace(&sp1a8, &sp1e8);
	mtx4MultMtx4(&sp2b0, &sp1e8, &sp270);
	mtx00015f04(g_PdLogoScale, &sp270);

	var80062560.a.l.colc[0] = var80062560.a.l.colc[1] = var80062560.a.l.colc[2] = 255.0f * g_PdLogoAmbientLightFrac;
	var80062560.a.l.col[0] = var80062560.a.l.col[1] = var80062560.a.l.col[2] = 255.0f * g_PdLogoAmbientLightFrac;

	numvertices = 0;
	numcolours = 0;

	node = modelGetPart(model->filedata, MODELPART_LOGO_0002);

	if (node) {
		Gfx *tmp;

		rodata = &node->rodata->dl;
		numvertices += rodata->numvertices + 1;
		numcolours += rodata->numcolours + 1;

		rwdata = modelGetNodeRwData(model, node);
		rwdata->gdl = tmp = gfxAllocate(5 * sizeof(Gfx));

		gSPSetLights1(tmp++, var80062530);
		gSPBranchList(tmp++, rodata->primary);
	}

	node = modelGetPart(model->filedata, MODELPART_LOGO_0004);

	if (node) {
		Gfx *tmp;

		rodata = &node->rodata->dl;
		numvertices += rodata->numvertices + 1;
		numcolours += rodata->numcolours + 1;

		rwdata = modelGetNodeRwData(model, node);
		rwdata->gdl = tmp = gfxAllocate(5 * sizeof(Gfx));

		if (g_PdLogoAmbientLightFrac > 0.0f) {
			gSPSetLights1(tmp++, var80062560);
			gSPBranchList(tmp++, rodata->primary);
		} else {
			gSPEndDisplayList(tmp++);
		}
	}

	node = modelGetPart(model->filedata, MODELPART_LOGO_0006);

	if (node) {
		Gfx *tmp;

		rodata = &node->rodata->dl;
		numvertices += rodata->numvertices + 1;
		numcolours += rodata->numcolours + 1;

		rwdata = modelGetNodeRwData(model, node);
		rwdata->gdl = tmp = gfxAllocate(5 * sizeof(Gfx));

		if (g_PdLogoAmbientLightFrac > 0.0f) {
			gSPSetLights1(tmp++, var80062560);
			gSPBranchList(tmp++, rodata->primary);
		} else {
			gSPEndDisplayList(tmp++);
		}
	}

	node = modelGetPart(model->filedata, MODELPART_LOGO_0008);

	if (node) {
		Gfx *tmp;

		rodata = &node->rodata->dl;
		numvertices += rodata->numvertices + 1;
		numcolours += rodata->numcolours + 1;

		rwdata = modelGetNodeRwData(model, node);
		rwdata->gdl = tmp = gfxAllocate(5 * sizeof(Gfx));

		if (g_PdLogoAmbientLightFrac > 0.0f) {
			gSPSetLights1(tmp++, var80062560);
			gSPBranchList(tmp++, rodata->primary);
		} else {
			gSPEndDisplayList(tmp++);
		}
	}

	gdl = titleRenderPdLogoModel(gdl, model, var80062804, g_PdLogoFrac, 240, 1.0f, &sp270, gfxAllocateVertices(numvertices), gfxAllocateColours(numcolours));

	gSPSetLights1(gdl++, var80062578);

	{
		struct coord sp64 = {0, 0, 1000};

		mtx4LoadTranslation(&sp64, &sp1e8);
		mtx00015f88(1.0f + sp13c, &sp1e8);
		mtx4MultMtx4(&sp2b0, &sp1e8, &sp230);
		mtx00015f04(0.308f, &sp230);

		if (g_PdLogoTitleStep >= 0) {
			if (g_PdLogoTitleStep == 0) {
				// empty
			} else if (g_PdLogoTitleStep == 1) {
				f32 frac = g_PdLogoTitleStepFrac;
				s32 a2 = g_PdLogoTitleStepFrac < 0.5f;

				gdl = titleRenderPdLogoModel(gdl, g_TitleModelPdThree, a2, frac, 255, frac, &sp230, var8009cca8[var8009ccb8], var8009ccb0[var8009ccb8]);
			} else if (g_PdLogoTitleStep == 2) {
				f32 frac = g_PdLogoTitleStepFrac;
				s32 a2 = g_PdLogoTitleStepFrac < 0.5f;

				gdl = titleRenderPdLogoModel(gdl, g_TitleModelPdTwo, a2, 1.0f - frac, 255, 1.0f, &sp230, var8009cca8[var8009ccb8], var8009ccb0[var8009ccb8]);
			} else if (g_PdLogoTitleStep == 3) {
				f32 frac = g_PdLogoTitleStepFrac;
				s32 a2 = g_PdLogoTitleStepFrac < 0.5f;

				gdl = titleRenderPdLogoModel(gdl, g_TitleModelPdTwo, a2, frac, 255, 1.0f, &sp230, var8009cca8[var8009ccb8], var8009ccb0[var8009ccb8]);
			} else {
				gdl = titleRenderPdLogoModel(gdl, g_TitleModelPdTwo, 0, 1.0f, 255, 1.0f, &sp230, var8009cca8[var8009ccb8], var8009ccb0[var8009ccb8]);
			}
		}
	}

	return gdl;
}


static void titleInitNintendoLogo(void)
{
	u8 *nextaddr = var8009cca0;

	g_TitleFastForward = false;

	if (g_TitleButtonPressed) {
		g_TitleTimer = TICKS(180);
	} else {
		g_TitleTimer = 0;
	}

	{
		struct coord coord = {0, 0, 0};

		g_ModelStates[MODEL_NINTENDOLOGO].filedata = modeldefLoad(g_ModelStates[MODEL_NINTENDOLOGO].fileid, nextaddr, 0x47800, 0);

		modelCalculateRwDataLen(g_ModelStates[MODEL_NINTENDOLOGO].filedata);
		g_TitleModel = modelmgrInstantiateModelWithoutAnim(g_ModelStates[MODEL_NINTENDOLOGO].filedata);
		g_TitleModel->scale = 1;
		modelSetRootPosition(g_TitleModel, &coord);
	}
}

static void titleExitNintendoLogo(void)
{
	modelmgrFreeModel(g_TitleModel);
}

/**
 * If no button has been pressed during the Rare logo (so g_TitleButtonPressed
 * is false) and the player presses a button within 140 ticks of the Nintendo
 * logo, the Nintendo logo sequence will play at double speed until it exits at
 * the 140 tick mark.
 */
static void titleTickNintendoLogo(void)
{
	viSetFovY(60);
	viSetAspect(1.33333333f);
	viSetZRange(100, 10000);
	g_ViBackData->usezbuf = false;

	g_TitleTimer += g_Vars.lvupdate60;

	if (g_TitleFastForward) {
		g_TitleTimer += g_Vars.lvupdate60;
	}

	if (joyGetButtonsPressedThisFrame(0, 0xffff)) {
		if (osResetType == RESETTYPE_WARM) {
			g_TitleButtonPressed = true;
			titleSetNextMode(TITLEMODE_PDLOGO);
		} else if (!g_TitleButtonPressed) {
			g_TitleFastForward = true;
		}
	}

	if (g_TitleFastForward && !g_TitleButtonPressed && g_TitleTimer > TICKS(140)) {
		g_TitleButtonPressed = true;
		g_TitleFastForward = false;
		titleSetNextMode(TITLEMODE_PDLOGO);
	}

	if (g_TitleTimer > TICKS(240)) {
		titleSetNextMode(TITLEMODE_PDLOGO);
	}
}

static Gfx *titleRenderNintendoLogo(Gfx *gdl)
{
	struct modelrenderdata renderdata = { NULL, true, 3 };
	s32 i;
	s32 j;
	Mtxf sp108;
	f32 fracdone = g_TitleTimer / TICKS(240.0f);
	struct coord lightdir = {0, 0, 0};
	s32 v0;

	gdl = titleClear(gdl);

	gSPSetLights1(gdl++, var80062590);

	lightdir.z = sinf((1 - fracdone) * 1.5f * M_PI);
	lightdir.x = cosf((1 - fracdone) * 1.5f * M_PI);

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

	titleSetLight(&var80062590, v0, v0, v0, 0.0f, &lightdir);

	{
		Mtxf spa8;
		struct coord sp9c;
		s32 stack[2];
		Mtxf sp54;

		sp9c.x = 0.0f;

		if (fracdone < 0.4f) {
			sp9c.x = (-cosf((1.0f - fracdone / .4f) * M_PI) * 0.5f + 0.5f) * 1.5707963705063f;
		}

		sp9c.y = (-cosf((1.0f - (fracdone / 1)) * M_PI) * 0.5f + .5f) * 0.35f;
		sp9c.z = 0.0f;

		mtx4LoadRotation(&sp9c, &spa8);
		mtx00015f88(fracdone * 0.2f + 1.0f, &spa8);

		mtx00016ae4(&sp108,
				/* pos  */ 0.0f, 0.0f, 4000,
				/* look */ 0.0f, 0.0f, 0.0f,
				/* up   */ 0.0f, 1.0f, 0.0f);

		mtx4MultMtx4InPlace(&sp108, &spa8);
		mtx4Copy(&spa8, &sp108);
		renderdata.unk00 = &sp108;

		renderdata.unk10 = gfxAllocate(g_TitleModel->filedata->nummatrices * sizeof(Mtxf));
		mtx4Copy(&sp108, renderdata.unk10);
		g_TitleModel->matrices = renderdata.unk10;

		model0001cc20(g_TitleModel);

		renderdata.flags = 3;
		renderdata.zbufferenabled = false;
		renderdata.gdl = gdl;

		modelRender(&renderdata, g_TitleModel);

		gdl = renderdata.gdl;

		for (i = 0, j = 0; i < g_TitleModel->filedata->nummatrices; i++, j += sizeof(Mtxf)) {
			mtx4Copy((Mtxf *)((u32)g_TitleModel->matrices + j), &sp54);
			mtx00016054(&sp54, g_TitleModel->matrices + i);
		}
	}

	return gdl;
}

static void titleInitRareLogo(void)
{
	u8 *nextaddr = var8009cca0;

	g_TitleTimer = -3;

	{
		struct coord coord = {0, 0, 0};

		g_ModelStates[MODEL_RARELOGO].filedata = modeldefLoad(g_ModelStates[MODEL_RARELOGO].fileid, nextaddr, 0x47800, 0);

		modelCalculateRwDataLen(g_ModelStates[MODEL_RARELOGO].filedata);
		g_TitleModel = modelmgrInstantiateModelWithoutAnim(g_ModelStates[MODEL_RARELOGO].filedata);
		g_TitleModel->scale = 1;
		modelSetRootPosition(g_TitleModel, &coord);

		musicQueueStopAllEvent();

		if (!g_IsTitleDemo) {
			g_IsTitleDemo = true;
		}
	}
}

static void titleExitRareLogo(void)
{
	modelmgrFreeModel(g_TitleModel);
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
static void titleTickRareLogo(void)
{
	viSetFovY(60);
	viSetAspect(1.33333333f);
	viSetZRange(100, 10000);
	g_ViBackData->usezbuf = false;

	if (g_TitleTimer < 0) {
		g_TitleTimer++;
	} else {
		if (g_TitleTimer == 0) {
			musicQueueStartEvent(TRACKTYPE_PRIMARY, MUSIC_TITLE1, 0, 0x7fff);
		}

		g_TitleTimer += g_Vars.lvupdate60;

		if (joyGetButtonsPressedThisFrame(0, 0xffff)) {
			if (osResetType == RESETTYPE_WARM) {
				g_TitleButtonPressed = true;
				titleSetNextMode(TITLEMODE_PDLOGO);
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
			titleSetNextMode(TITLEMODE_NINTENDOLOGO);
		}
	}
}

static f32 func0f019d0c(f32 arg0)
{
	return ((1.0f - arg0) + (1.0f - arg0)) * M_PI - DEG2RAD(90);
}

static Gfx *titleRenderRareLogo(Gfx *gdl)
{
	struct modelrenderdata renderdata = { NULL, true, 3 };
	s32 i;
	f32 fracdone = g_TitleTimer / TICKS(240.0f);
	Mtxf sp118;
	s32 j;
	s32 s0;

	static f32 var80062920 = 0;

	gdl = titleClear(gdl);

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
			titleSetLight(&var80062590,
					(s32)(255.0f * fracdone / 0.2f),
					(s32)(255.0f * fracdone / 0.2f),
					(s32)(255.0f * fracdone / 0.2f),
					0, &lightdir);
		} else {
			titleSetLight(&var80062590, s0, s0, s0, 0, &lightdir);
		}

		s0 = s0 * 192 / 255;

		if (fracdone < 0.5f) {
			lightdir.z = sinf(func0f019d0c(0.5f));
			lightdir.x = cosf(func0f019d0c(0.5f));
			guNormalize(&lightdir.x, &lightdir.y, &lightdir.z);
			titleSetLight(&var800625a8, s0, s0, s0, 0, &lightdir);
		} else {
			titleSetLight(&var800625a8, s0, s0, s0, 0, &lightdir);
		}

		var80062920 += g_Vars.lvupdate60f / 90;

		tmp = 1 - fracdone * 1;

		spb4.x = 0;
		spb4.y = 1.5707963705063f * tmp;
		spb4.z = 0;

		mtx4LoadRotation(&spb4, &spc0);
		mtx00015f88(1 + fracdone * 0.25f, &spc0);

		mtx00016ae4(&sp118,
				/* pos  */ 0, 0, 4000,
				/* look */ 0, 0, 0,
				/* up   */ 0, 1, 0);

		mtx4MultMtx4InPlace(&sp118, &spc0);
		mtx4Copy(&spc0, &sp118);

		renderdata.unk00 = &sp118;
		renderdata.unk10 = gfxAllocate(g_TitleModel->filedata->nummatrices * sizeof(Mtxf));
		mtx4Copy(&sp118, renderdata.unk10);

		g_TitleModel->matrices = renderdata.unk10;

		model0001cc20(g_TitleModel);

		rwdata = modelGetNodeRwData(g_TitleModel, modelGetPart(g_TitleModel->filedata, MODELPART_RARELOGO_000B));

		if (rwdata) {
			rwdata->visible = false;
		}

		rwdata = modelGetNodeRwData(g_TitleModel, modelGetPart(g_TitleModel->filedata, MODELPART_RARELOGO_000D));

		if (rwdata) {
			rwdata->visible = true;
		}

		rwdata = modelGetNodeRwData(g_TitleModel, modelGetPart(g_TitleModel->filedata, MODELPART_RARELOGO_000C));

		if (rwdata) {
			rwdata->visible = false;
		}

		gSPSetLights1(gdl++, var80062590);

		renderdata.flags = 3;
		renderdata.zbufferenabled = 0;
		renderdata.gdl = gdl;

		modelRender(&renderdata, g_TitleModel);

		gdl = renderdata.gdl;

		rwdata = modelGetNodeRwData(g_TitleModel, modelGetPart(g_TitleModel->filedata, MODELPART_RARELOGO_000B));

		if (rwdata) {
			rwdata->visible = true;
		}

		rwdata = modelGetNodeRwData(g_TitleModel, modelGetPart(g_TitleModel->filedata, MODELPART_RARELOGO_000D));

		if (rwdata) {
			rwdata->visible = false;
		}

		rwdata = modelGetNodeRwData(g_TitleModel, modelGetPart(g_TitleModel->filedata, MODELPART_RARELOGO_000C));

		if (rwdata) {
			rwdata->visible = true;
		}

		gSPSetLights1(gdl++, var80062590);

		renderdata.flags = 3;
		renderdata.zbufferenabled = 0;
		renderdata.gdl = gdl;

		modelRender(&renderdata, g_TitleModel);

		gdl = renderdata.gdl;

		for (i = 0, j = 0; i < g_TitleModel->filedata->nummatrices; i++, j += sizeof(Mtxf)) {
			Mtxf sp58;
			mtx4Copy((Mtxf *)((u32)g_TitleModel->matrices + j), &sp58);
			mtx00016054(&sp58, g_TitleModel->matrices + i);
		}
	}

	return gdl;
}

s32 g_NumPlayers = 0;

static void titleInitSkip(void)
{
	g_TitleNextStage = STAGE_CITRAINING;

	g_NumPlayers = 1;

	if (g_IsTitleDemo) {
		g_TitleNextStage = STAGE_DEFECTION;
		g_IsTitleDemo++;
	}

	mainChangeToStage(g_TitleNextStage);

	g_Vars.bondplayernum = 0;
	g_Vars.coopplayernum = -1;
	g_Vars.antiplayernum = -1;

	lvSetDifficulty(DIFF_A);
	viBlack(true);
}

static void titleInitNoController(void)
{
	g_TitleTimer = 0;
}

static void titleTickNoController(void)
{
	viSetFovY(60);
	viSetAspect(1.33333333f);
	viSetZRange(100, 10000);
	g_ViBackData->usezbuf = false;

	g_TitleTimer += g_Vars.lvupdate60;
}

static Gfx *titleRenderNoController(Gfx *gdl)
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
	joyGetConnectedControllers();

	gdl = titleClear(gdl);
	gdl = text0f153628(gdl);

	// Line 1
	text = langGet(L_OPTIONS_071); // "- no controller in controller socket 1 -"
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = 288 - (textwidth >> 1);
	y = (480 / 2) - (textheight >> 1) - 12;

	width = g_ViBackData->x;
	gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, width, g_ViBackData->y, 0, 0);

	// Line 2
	text = langGet(L_OPTIONS_072); // "please power off and attach a controller"
	textMeasure(&textheight, &textwidth, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0);

	x = 288 - (textwidth >> 1);
	y = (480 / 2) - (textheight >> 1) + 12;

	width = g_ViBackData->x;
	gdl = textRenderProjected(gdl, &x, &y, text, g_CharsHandelGothicLg, g_FontHandelGothicLg, 0xffffffff, width, g_ViBackData->y, 0, 0);

	gdl = text0f153780(gdl);

	return gdl;
}

void titleSetNextMode(s32 mode)
{
	if (g_TitleDelayedMode != mode) {
		g_TitleNextMode = mode;
	}
}

void titleTick(void)
{
#if PAL
	viSetAspect(576.0f / 480 * 1.1904761791229f);
#else
	viSetAspect(576.0f / 480);
#endif
	viSetSize(576, 480);
	viSetBufSize(576, 480);
	playermgrSetViewSize(576, 480);
	viSetViewSize(576, 480);
	playermgrSetViewPosition(0, 0);
	viSetViewPosition(0, 0);

	// If there's a new mode to transition to, schedule it to apply in 3 ticks
	// time and call the exit function for the current mode.
	if (g_TitleNextMode >= 0) {
		g_TitleDelayedTimer = 3;
		g_TitleDelayedMode = g_TitleNextMode;

		switch (g_TitleMode) {
		case TITLEMODE_CHECKCONTROLLERS:
			titleExitCheckControllers();
			break;
		case TITLEMODE_PDLOGO:
			titleExitPdLogo();
			break;
		case TITLEMODE_NINTENDOLOGO:
			titleExitNintendoLogo();
			break;
		case TITLEMODE_RARELOGO:
			titleExitRareLogo();
			break;
		}

		if (g_TitleMode != TITLEMODE_CHECKCONTROLLERS) {
			viBlack(true);
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
			titleInitLegal();
			break;
		case TITLEMODE_CHECKCONTROLLERS:
			titleInitCheckControllers();
			break;
		case TITLEMODE_PDLOGO:
			titleInitPdLogo();
			break;
		case TITLEMODE_NINTENDOLOGO:
			titleInitNintendoLogo();
			break;
		case TITLEMODE_RARELOGO:
			titleInitRareLogo();
			break;
		case TITLEMODE_SKIP:
			titleInitSkip();
			break;
		case TITLEMODE_NOCONTROLLER:
			titleInitNoController();
			break;
		}

		if (g_TitleMode != TITLEMODE_CHECKCONTROLLERS && g_TitleMode != TITLEMODE_SKIP) {
			viBlack(false);
		}
	}

	// Run the current mode's tick function
	switch (g_TitleMode) {
	case TITLEMODE_LEGAL:
		titleTickLegal();
		break;
	case TITLEMODE_CHECKCONTROLLERS:
		titleTickCheckControllers();
		break;
	case TITLEMODE_PDLOGO:
		titleTickPdLogo();
		break;
	case TITLEMODE_NINTENDOLOGO:
		titleTickNintendoLogo();
		break;
	case TITLEMODE_RARELOGO:
		titleTickRareLogo();
		break;
	case TITLEMODE_NOCONTROLLER:
		titleTickNoController();
		break;
	case TITLEMODE_SKIP:
		g_ViBackData->usezbuf = false;
		titleSetNextMode(TITLEMODE_RARELOGO);
		break;
	}
}

Gfx *titleRender(Gfx *gdl)
{
	if (g_TitleDelayedTimer == 0) {
		switch (g_TitleMode) {
		case TITLEMODE_LEGAL:
			gdl = titleRenderLegal(gdl);
			break;
		case TITLEMODE_CHECKCONTROLLERS:
			gdl = titleRenderCheckControllers(gdl);
			break;
		case TITLEMODE_PDLOGO:
			gdl = titleRenderPdLogo(gdl);
			break;
		case TITLEMODE_NINTENDOLOGO:
			gdl = titleRenderNintendoLogo(gdl);
			break;
		case TITLEMODE_RARELOGO:
			gdl = titleRenderRareLogo(gdl);
			break;
		case TITLEMODE_NOCONTROLLER:
			gdl = titleRenderNoController(gdl);
			break;
		}
	}

	return gdl;
}
