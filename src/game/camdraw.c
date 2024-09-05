#include <ultra64.h>
#include "constants.h"
#include "game/camdraw.h"
#include "game/tex.h"
#include "game/menu.h"
#include "game/stubs/game_102230.h"
#include "game/bg.h"
#include "game/lang.h"
#include "game/pak.h"
#include "game/splat.h"
#include "game/utils.h"
#include "bss.h"
#include "lib/main.h"
#include "lib/memp.h"
#include "lib/model.h"
#include "lib/mema.h"
#include "lib/rng.h"
#include "lib/mtx.h"
#include "lib/libc/ll.h"
#include "data.h"
#include "types.h"
#include "string.h"

/**
 * camdraw_* functions refer to the editing system as a whole.
 * editor_* functions refer to an editor instance (one per player, max 4).
 * phead_* functions refer to an editor slot. There are 22 of these.
 */

#define AUTOCALSTATUS_OFF    0
#define AUTOCALSTATUS_RESET  1
#define AUTOCALSTATUS_2      2
#define AUTOCALSTATUS_3      3
#define AUTOCALSTATUS_4      4
#define AUTOCALSTATUS_5      5
#define AUTOCALSTATUS_FINISH 6

#define EDITOR100_0 0
#define EDITOR100_1 1
#define EDITOR100_2 2
#define EDITOR100_3 3
#define EDITOR100_4 4
#define EDITOR100_5 5

#define HEADID_EDITOR   -1
#define HEADID_SPECIAL2 -2
#define HEADID_UNDO     -3
#define HEADID_SPECIAL4 -4
#define HEADID_SPECIAL5 -5

#define READMODE_INIT        0
#define READMODE_STARTHEADER 1
#define READMODE_DONEHEADER  2
#define READMODE_NULL        3
#define READMODE_EXIT1       4
#define READMODE_EXIT2       5
#define READMODE_EXIT3       6

#define MAX_EDITORS 4

#define NUM_UNK47C 30

#define IMGWIDTH_EDIT  128
#define IMGWIDTH_THUMB 64
#define IMGWIDTH_SAVE  32

#define IMGHEIGHT_EDIT  128
#define IMGHEIGHT_THUMB 64
#define IMGHEIGHT_SAVE  32

#define IMGNUMPIXELS_EDIT  (IMGWIDTH_EDIT * IMGHEIGHT_EDIT)
#define IMGNUMPIXELS_THUMB (IMGWIDTH_THUMB * IMGHEIGHT_THUMB)
#define IMGNUMPIXELS_SAVE  (IMGWIDTH_SAVE * IMGHEIGHT_SAVE)

struct camerafile {
	u8 unk00[128];
	u16 unk80;
	u16 unk82;
	u16 unk84;
	u8 unk86;
	u8 unk87;
	u8 unk88;
	u8 unk89;
	u8 unk8a;
	u8 unk8b;
	u8 unk8c;
	u8 unk8d;
	u16 unk8e_00 : 1;
	u16 unk8e_01 : 1;
	u16 unk8e_02 : 8;
	s16 unk90[7];
	u8 unk9e[IMGNUMPIXELS_SAVE];
};

struct headeditordata {
	/*0x000*/ u32 editorindex;
	/*0x004*/ u32 unk004;
	/*0x008*/ u32 unk008;
	/*0x00c*/ s32 unk00c;
	/*0x010*/ s32 unk010;
	/*0x014*/ u32 unk014[22];
	/*0x06c*/ s32 unk06c[8][8];
	/*0x16c*/ u32 editorslot;
	/*0x170*/ u32 undoslot;
	/*0x174*/ u32 special4slot;
	/*0x178*/ u32 special5slot;
	/*0x17c*/ f32 unk17c[8][8];
	/*0x27c*/ f32 unk27c[8][8];
	/*0x37c*/ s32 numallocations;
	/*0x380*/ u8 *allocations[30];
	/*0x3f8*/ u32 allocationsizes[30];
	/*0x470*/ u8 *unk470; // 128x128
	/*0x474*/ f32 *unk474; // 128x128
	/*0x478*/ f32 *unk478; // 128x128
	/*0x47c*/ u32 *unk47c; // 30 elements
	/*0x480*/ u8 *unk480; // 64x64
	/*0x484*/ struct textureconfig *unk484;
	/*0x488*/ struct textureconfig *unk488;
	/*0x48c*/ u32 unk48c;
};

struct perfecthead {
	/*0x000*/ u32 unk000;
	/*0x004*/ struct textureconfig fullsizetex;
	/*0x010*/ struct textureconfig thumbnailtex;
	/*0x01c*/ u8 *unk01c; // 64x64
	/*0x020*/ u8 *unk020; // 32x32
	/*0x024*/ u8 *unk024;
	/*0x028*/ u32 unk028;
	/*0x02c*/ u32 unk02c;
	/*0x030*/ f32 unk030;
	/*0x034*/ u16 unk034;
	/*0x036*/ u8 quality;
	/*0x038*/ u32 unk038;
	/*0x03c*/ u32 unk03c;
	/*0x040*/ u8 unk040[200];
	/*0x108*/ u8 unk108[500];
	/*0x2fc*/ u8 unk2fc[160];
	/*0x39c*/ s32 colournum;
	/*0x3a0*/ s32 stylenum;
	/*0x3a4*/ s32 unk3a4;
	/*0x3a8*/ s32 unk3a8;
	/*0x3ac*/ s32 unk3ac;
	/*0x3b0*/ s32 unk3b0;
	/*0x3b4*/ s32 unk3b4;
	/*0x3b8*/ s32 unk3b8;
	/*0x3bc*/ s32 unk3bc;
	/*0x3c0*/ s32 unk3c0;
	/*0x3c4*/ s32 unk3c4;
	/*0x3c8*/ s32 unk3c8;
	/*0x3cc*/ s32 unk3cc;
	/*0x3d0*/ f32 unk3d0[7];
	/*0x3ec*/ s32 unk3ec;
	/*0x3f0*/ s32 unk3f0;
	/*0x3f4*/ u16 active : 1;
	/*0x3f4*/ u16 autodeartefact : 1;
	/*0x3f4*/ u16 unk3f4_02 : 1;
	/*0x3f4*/ u16 unk3f4_03 : 1;
	/*0x3f4*/ u16 unk3f4_04 : 1;
	/*0x3f8*/ struct fileguid fileguid;
};

struct headeditor {
	/*0x000*/ u32 unk000;
	/*0x004*/ f32 unk004;
	/*0x008*/ f32 unk008;
	/*0x00c*/ f32 unk00c;
	/*0x010*/ f32 unk010;
	/*0x014*/ f32 unk014;
	/*0x018*/ f32 unk018;
	/*0x01c*/ f32 unk01c;
	/*0x020*/ f32 unk020;
	/*0x024*/ f32 unk024;
	/*0x028*/ f32 unk028;
	/*0x02c*/ f32 unk02c;
	/*0x030*/ f32 unk030;
	/*0x034*/ f32 unk034;
	/*0x038*/ f32 unk038;
	/*0x03c*/ f32 unk03c;
	/*0x040*/ f32 unk040;
	/*0x044*/ f32 unk044;
	/*0x048*/ f32 unk048;
	/*0x04c*/ f32 unk04c;
	/*0x050*/ f32 unk050;
	/*0x054*/ s32 unk054;
	/*0x058*/ u32 unk058;
	/*0x05c*/ s32 timenow;
	/*0x060*/ s32 unk060;
	/*0x064*/ s32 timeinc;
	/*0x068*/ u32 unk068;
	/*0x06c*/ u32 unk06c;
	/*0x070*/ u32 unk070;
	/*0x074*/ s32 unk074;
	/*0x078*/ u32 unk078;
	/*0x07c*/ s32 unk07c;
	/*0x080*/ s32 unk080;
	/*0x084*/ u32 unk084;
	/*0x088*/ s32 unk088;
	/*0x08c*/ u32 unk08c;
	/*0x090*/ s32 unk090;
	/*0x094*/ u32 numvalidimages;
	/*0x098*/ u8 imageslots[30];
	/*0x0b6*/ u8 validimages[30];
	/*0x0d4*/ u8 unk0d4_00 : 1;
	/*0x0d4*/ u8 unk0d4_01 : 1;
	/*0x0d4*/ u8 unk0d4_02 : 1;
	/*0x0d4*/ u8 needsgbpak : 1;
	/*0x0d4*/ u8 unk0d4_04 : 1;
	/*0x0d8*/ void *unk0d8;
	/*0x0dc*/ u32 *unk0dc;
	/*0x0e0*/ u32 unk0e0;
	/*0x0e4*/ u32 unk0e4;
	/*0x0e8*/ u32 unk0e8;
	/*0x0ec*/ u32 unk0ec;
	/*0x0f0*/ u32 unk0f0;
	/*0x0f4*/ u32 readmode;
	/*0x0f8*/ u32 autocalstatus;
	/*0x0fc*/ u32 unk0fc;
	/*0x100*/ u32 unk100;
};

struct headeditordata *g_HeadEditorData;

char *g_CamReadStates[] = {
	"Init",
	"Start Header Read",
	"Header Read Done",
	"Null",
	"Exit 1",
	"Exit 2",
	"Exit 3",
};

const u32 var7f1b60a0[64][2] = {
	{ 0, 0 },
	{ 0, 1 },
	{ 1, 0 },
	{ 2, 0 },
	{ 1, 1 },
	{ 0, 2 },
	{ 0, 3 },
	{ 1, 2 },
	{ 2, 1 },
	{ 3, 0 },
	{ 4, 0 },
	{ 3, 1 },
	{ 2, 2 },
	{ 1, 3 },
	{ 0, 4 },
	{ 0, 5 },
	{ 1, 4 },
	{ 2, 3 },
	{ 3, 2 },
	{ 4, 1 },
	{ 5, 0 },
	{ 6, 0 },
	{ 5, 1 },
	{ 4, 2 },
	{ 3, 3 },
	{ 2, 4 },
	{ 1, 5 },
	{ 0, 6 },
	{ 0, 7 },
	{ 1, 6 },
	{ 2, 5 },
	{ 3, 4 },
	{ 4, 3 },
	{ 5, 2 },
	{ 6, 1 },
	{ 7, 0 },
	{ 7, 1 },
	{ 6, 2 },
	{ 5, 3 },
	{ 4, 4 },
	{ 3, 5 },
	{ 2, 6 },
	{ 1, 7 },
	{ 2, 7 },
	{ 3, 6 },
	{ 4, 5 },
	{ 5, 4 },
	{ 6, 3 },
	{ 7, 2 },
	{ 7, 3 },
	{ 6, 4 },
	{ 5, 5 },
	{ 4, 6 },
	{ 3, 7 },
	{ 4, 7 },
	{ 5, 6 },
	{ 6, 5 },
	{ 7, 4 },
	{ 7, 5 },
	{ 6, 6 },
	{ 5, 7 },
	{ 6, 7 },
	{ 7, 6 },
	{ 7, 7 },
};

const u32 var7f1b62a0[8][8] = {
	{ 0x00000000, 0xffffffff, 0xdc9785ff, 0xdc917bff, 0xdd8d71ff, 0xdd8367ff, 0xdf795dff, 0xdf7953ff },
	{ 0x00000000, 0xffffffff, 0xa67b6dff, 0xa16152ff, 0x8c6741ff, 0x81544cff, 0x6a4031ff, 0x4f433cff },
	{ 0x00000000, 0xffffffff, 0xccb38dff, 0xddc07cff, 0xe6a667ff, 0xd1ab50ff, 0xc69f6dff, 0xb27e5bff },
	{ 0x00000000, 0xffffffff, 0x5f3a25ff, 0x553a20ff, 0x4b351cff, 0x412d19ff, 0x41260fff, 0x371e04ff },
	{ 0x00000000, 0xffffffff, 0xe9d679ff, 0x654f40ff, 0xebb279ff, 0x846b51ff, 0xebc579ff, 0xab8d6fff },
	{ 0x00000000, 0xffffffff, 0x26374dff, 0x18253eff, 0x171d20ff, 0x060e16ff, 0x00001cff, 0x000001ff },
	{ 0x00000000, 0xffffffff, 0x972f1aff, 0x822817ff, 0x6e1e12ff, 0x5a140dff, 0x460a08ff, 0x200001ff },
	{ 0x00000000, 0xffffffff, 0x79b2ebff, 0x007fffff, 0x1f5fdfff, 0x0043caff, 0x00147eff, 0x0c1857ff },
};

struct headeditor *g_HeadEditors = NULL;
struct perfecthead *g_PerfectHeadSlots = NULL;

u32 var8007f8e4 = 0;
u32 var8007f8e8 = 8;
u32 var8007f8ec = 90;
u32 var8007f8f0 = 5;
u32 var8007f8f4 = 200;
u32 var8007f8f8 = 0;
u32 var8007f8fc = 1;
u32 var8007f900 = 120;

u16 var8007f904[] = {
	0x0200, 0x0233, 0x024e, 0x026b,
	0x0289, 0x02a9, 0x02ca, 0x02ed,
	0x0312, 0x0338, 0x0360, 0x038b,
	0x03b7, 0x03e5, 0x0416, 0x0449,
	0x047f, 0x04b7, 0x04f2, 0x0530,
	0x0570, 0x05b4, 0x05fc, 0x0646,
	0x0695, 0x06e7, 0x073d, 0x0798,
	0x07f7, 0x085a, 0x08c3, 0x0930,
	0x09a3, 0x0a1b, 0x0a9a, 0x0b1e,
	0x0ba9, 0x0c3b, 0x0cd4, 0x0d74,
	0x0e1c, 0x0ecc, 0x0f85, 0x1047,
	0x1113, 0x11e8, 0x12c8, 0x13b3,
	0x14a9, 0x15ab, 0x16ba, 0x17d6,
	0x18ff, 0x1a38, 0x1b7f, 0x1cd7,
	0x1e3f, 0x1fb9, 0x2146, 0x22e6,
	0x249a, 0x2663, 0x2843, 0x2a3a,
	0x2c49, 0x2e73, 0x30b7, 0x3318,
	0x3596, 0x3834, 0x3af2, 0x3dd3,
	0x40d7, 0x4402, 0x4753, 0x4acf,
	0x4e75, 0x524a, 0x564e, 0x5a84,
	0x5eef, 0x6392, 0x686e, 0x6d87,
	0x72df, 0x787a, 0x7e5c, 0x8487,
	0x8aff, 0x91c7, 0x98e5, 0xa05b,
	0xa82f, 0xb065, 0xb901, 0xc208,
	0xcb81, 0xd570, 0xdfdb, 0xeac8,
	0xf63d, 0xffff,
};

u32 g_AllocatedSize = 0;

struct perfecthead *phead_find(s32 index);
struct headeditor *camdraw_current_editor(void);
void editor_init(s32 index);
void camdraw_finish(void);
void phead_randomise_textures(struct perfecthead *arg0);
void editor_make_textures(void);
void camdraw_copy(struct perfecthead *dst, struct perfecthead *src, u32 line, char *file);
void camdraw_copy_texture(struct textureconfig *arg0, struct textureconfig *arg1);
void func0f14c7dc(struct textureconfig *tconfig);
u32 camdraw_get_texture_size(struct textureconfig *tconfig);
void editor_autocalibrate(s32 index, u8 *arg1);
void editor_make_texture_type2(u8 *arg0, u8 *arg1);
void editor_make_texture_type3(u8 *src, u8 *dst);
void editor_make_texture_type4(u8 *arg0, u8 *arg1);
void func0f14d84c(f32 *arg0, s32 arg1);
void func0f14d8d8(f32 *arg0, f32 *arg1, s32 arg2, f32 *arg3, s32 arg4);
void phead0f14dac0(u8 *arg0, struct textureconfig *arg1);
void func0f14def0(s32 index, u32 line, char *file);
void func0f14e1c4(struct perfecthead *arg0);
f32 func0f14e4ac(s32 arg0, s32 *arg1, s32 *arg2);
void func0f14e790(u8 *arg0);
void func0f14e7e0(u8 *arg0);
void func0f14e884(struct textureconfig *tconfig, s32 numrows, s32 arg2, u64 arg3);
void func0f14ecd8(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3);
void func0f14eeb0(f32 arg0[7]);
void phead_get_unk3d0(f32 *arg0);
void editor_make_texture_type5(struct perfecthead *arg0);

/**
 * Fill the texture buffer with a linear gradient: black (left) to white (right).
 */
void camdraw_write_gradient_texture(struct textureconfig *tconfig)
{
	s32 x;
	s32 y;

	for (y = 0; y < tconfig->height; y++) {
		for (x = 0; x < tconfig->width; x++) {
			s32 value = (x * 8 / tconfig->width) * 32;
			s32 fudge = (y & 1) ? ((x & 4) ? -4 : 4) : 0;

			tconfig->textureptr[y * 64 + x + fudge] = value;
		}
	}
}

void *camdraw_allocate(u32 size, u32 line, char *file)
{
	s32 i;
	void *allocation = NULL;

	static u32 total = 0;

	size = align16(size);

	bg_garbage_collect_rooms(size, true);

	g_AllocatedSize += size;
	allocation = mema_alloc(size);
	total++;

	osSyncPrintf("RWI : Cam Alloc : Guid=%d -> Total = %u (%d at %s)\n", 0, total, line, file);

	for (i = 0; i < g_HeadEditorData->numallocations; i++) {
		if (g_HeadEditorData->allocations[i] == NULL) {
			// @bug: This meant to be writing to [i]
			g_HeadEditorData->allocations[g_HeadEditorData->numallocations] = allocation;
			g_HeadEditorData->allocationsizes[g_HeadEditorData->numallocations] = size;

			return allocation;
		}
	}

	g_HeadEditorData->allocations[g_HeadEditorData->numallocations] = allocation;
	g_HeadEditorData->allocationsizes[g_HeadEditorData->numallocations] = size;
	g_HeadEditorData->numallocations++;

	return allocation;
}

void camdraw_free(void *allocation, u32 size)
{
	s32 i;

	g_AllocatedSize -= size;

	for (i = 0; i < g_HeadEditorData->numallocations; i++) {
		if (allocation == NULL || allocation == g_HeadEditorData->allocations[i]) {
			mema_free(g_HeadEditorData->allocations[i], g_HeadEditorData->allocationsizes[i]);
			g_HeadEditorData->allocations[i] = NULL;
		}
	}

	if (allocation == NULL) {
		g_HeadEditorData->numallocations = 0;
	}
}

void func0f149f10(void)
{
	// empty
}

void func0f149f18(void)
{
	struct perfecthead *head;
	s32 i;

	phead_randomise_textures(phead_find(HEADID_EDITOR));

	head = phead_find(HEADID_EDITOR);
	head->active = false;

	if (g_HeadEditorData->unk470) {
		for (i = 0; i < IMGNUMPIXELS_EDIT; i++) {
			g_HeadEditorData->unk470[i] = random() % 255;
		}
	}
}

void camdraw_copy_editor_to_index(s32 index)
{
	camdraw_copy(phead_find(index), phead_find(HEADID_EDITOR), 1040, "camdraw.c");
}

void phead_set_unk3f4_04(bool arg0)
{
	struct perfecthead *head;

	head = phead_find(HEADID_EDITOR);
	head->unk3f4_04 = arg0;

	head = phead_find(HEADID_SPECIAL2);
	head->unk3f4_04 = arg0;
}

struct perfecthead *phead_find(s32 index)
{
	if (index == HEADID_EDITOR) {
		return &g_PerfectHeadSlots[g_HeadEditorData->editorslot];
	}

	if (index == HEADID_SPECIAL4) {
		return &g_PerfectHeadSlots[g_HeadEditorData->special4slot];
	}

	if (index == HEADID_SPECIAL5) {
		return &g_PerfectHeadSlots[g_HeadEditorData->special5slot];
	}

	if (index == HEADID_SPECIAL2) {
		return &g_PerfectHeadSlots[g_HeadEditorData->unk014[g_HeadEditorData->unk004]];
	}

	if (index == HEADID_UNDO) {
		return &g_PerfectHeadSlots[g_HeadEditorData->undoslot];
	}

	return &g_PerfectHeadSlots[g_HeadEditorData->unk014[index]];
}

void editor_set_unk100(s32 value)
{
	struct headeditor *editor = camdraw_current_editor();
	editor->unk100 = value;
}

bool editor_get_unk0d4_04(void)
{
	return g_HeadEditors[g_HeadEditorData->editorindex].unk0d4_04 & 0xff;
}

/**
 * 0 returns "Style 1"
 * 1 returns "Style 2"
 * 2 returns "Style 3"
 * 3 returns "Style 4"
 */
char *camdraw_get_style_name(s32 stylenum)
{
	return lang_get(L_MISC_429 + stylenum);
}

/**
 * 0 returns "Blonde"
 * 1 returns "Black"
 * 2 returns "Auburn"
 * 3 returns "Blue Rinse"
 */
char *camdraw_get_colour_name(s32 colournum)
{
	return lang_get(L_MISC_433 + colournum);
}

struct headeditor *camdraw_current_editor(void)
{
	return &g_HeadEditors[camdraw_get_editor_index()];
}

void camdraw_init2(void)
{
	s32 i;
	s32 j;

	g_HeadEditorData->unk48c = 0;
	g_HeadEditorData->unk484 = NULL;
	g_HeadEditorData->unk470 = NULL;
	g_HeadEditorData->unk474 = NULL;
	g_HeadEditorData->unk478 = NULL;
	g_HeadEditorData->unk47c = NULL;
	g_HeadEditorData->unk480 = NULL;
	g_HeadEditorData->numallocations = 0;
	g_HeadEditorData->editorindex = 0;
	g_HeadEditorData->unk004 = -1;
	g_HeadEditorData->unk008 = 1;

	osSyncPrintf("Cam -> Dumping head vertex colour information\n");

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			osSyncPrintf("Cam -> Face Col - Pal=%d, Entry=%d, Col=%08x\n");
		}
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			osSyncPrintf("Cam -> Hair Col - Pal=%d, Entry=%d, Col=%08x\n");
		}
	}
}

const char var7f1b6470[] = "Cam_Tick (%d Total Slots)";
const char var7f1b648c[] = "Current Camera Slot = %d\n";
const char var7f1b64a8[] = "Slot %d -> Active = %d";

bool phead_is_active(s32 index, u32 line, char *file)
{
	struct perfecthead *head = phead_find(index);
	return head->active;
}

void camdraw_init(void)
{
	s32 i;

	if (IS8MB()) {
		u32 size1 = align16(sizeof(struct headeditor) * MAX_EDITORS);
		u32 size2 = align16(sizeof(struct headeditordata));

		g_HeadEditors = memp_alloc(size1, MEMPOOL_PERMANENT);
		g_HeadEditorData = memp_alloc(size2, MEMPOOL_PERMANENT);

		camdraw_init2();

		for (i = 0; i < MAX_EDITORS; i++) {
			editor_init(i);
		}
	}
}

void camdraw_init_afterpaks(void)
{
	// empty
}

void camdraw_reset(void)
{
	s32 i;

	g_HeadEditorData->numallocations = 0;

	for (i = 0; i < MAX_EDITORS; i++) {
		g_HeadEditors[i].needsgbpak = false;
	}
}

void camdraw_free_all_heads(void)
{
	camdraw_free(NULL, 0);
}

void camdraw_print_head_state(void)
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(g_HeadEditorData->unk014); i++) {
		phead_is_active(i, 1296, "camdraw.c");
	}
}

const char var7f1b64cc[] = "CAM : Cam_StartCamFileRead - Go\n";
const char var7f1b64f0[] = "************ Cam_ActivateAndClearSlot ************ : Slot=%d\n";

void func0f14a480(void)
{
	// empty
}

void func0f14a488(void)
{
	s32 i;

	func0f14aed0(-1);

	for (i = 0; i < 32; i++) {
		camdraw_write_gradient_texture(&g_HeadEditorData->unk484[i]);
	}

	for (i = 0; i < MAX_EDITORS; i++) {
		g_HeadEditors[i].readmode = READMODE_INIT;
		pak0f11d478(i);
	}
}

void camdraw_start_gbpaks(void)
{
	s32 i;

	for (i = 0; i < MAX_EDITORS; i++) {
		g_HeadEditors[i].needsgbpak = true;
	}
}

void camdraw_stop_gbpaks(void)
{
	s32 i;

	for (i = 0; i < MAX_EDITORS; i++) {
		g_HeadEditors[i].needsgbpak = false;
	}
}

void camdraw_set_editor_index(s32 index)
{
	g_HeadEditorData->editorindex = index;
}

s32 camdraw_get_editor_index(void)
{
	return g_HeadEditorData->editorindex;
}

void func0f14a5b4(s32 index)
{
	g_HeadEditorData->unk004 = index;

	phead_randomise_textures(phead_find(index));
}

void func0f14a5e4(void)
{
	func0f14def0(HEADID_EDITOR, 1407, "camdraw.c");
}

void func0f14a610(void)
{
	func0f14def0(HEADID_EDITOR, 1415, "camdraw.c");
	camdraw_copy(phead_find(HEADID_SPECIAL2), phead_find(HEADID_EDITOR), 1416, "camdraw.c");
}

s32 func0f14a668(void)
{
	return g_HeadEditorData->unk004;
}

void func0f14a678(void)
{
	camdraw_copy(phead_find(HEADID_SPECIAL2), phead_find(HEADID_EDITOR), 1433, "camdraw.c");
}

void phead_undo(void)
{
	camdraw_copy(phead_find(HEADID_SPECIAL4), phead_find(HEADID_EDITOR), 1441, "camdraw.c");
	camdraw_copy(phead_find(HEADID_EDITOR), phead_find(HEADID_UNDO), 1442, "camdraw.c");
	camdraw_copy(phead_find(HEADID_UNDO), phead_find(HEADID_SPECIAL4), 1443, "camdraw.c");
}

void camdraw_copy_editor_to_undo(void)
{
	osSyncPrintf("Cam_CopyEditorToUndo\n");
	camdraw_copy(phead_find(HEADID_UNDO), phead_find(HEADID_EDITOR), 1452, "camdraw.c");
}

void camdraw_copy_undo_to_editor(void)
{
	osSyncPrintf("Cam_CopyUndoToEditor\n");
	camdraw_copy(phead_find(HEADID_EDITOR), phead_find(HEADID_UNDO), 1461, "camdraw.c");
}

void camdraw_copy_index_to_editor(s32 index)
{
	camdraw_copy(phead_find(HEADID_EDITOR), phead_find(index), 1470, "camdraw.c");
}

void func0f14a830(void)
{
	struct headeditor *editor = camdraw_current_editor();

	if (editor->unk0d4_00) {
		editor->unk0d4_00 = false;
	} else {
		editor->unk0d4_00 = true;
	}

	if (editor->unk0d4_00) {
		func0f14def0(HEADID_EDITOR, 1484, "camdraw.c");
	}
}

struct textureconfig *phead_get_texture(s32 index)
{
	struct perfecthead *head = phead_find(index);
	return &head->fullsizetex;
}

bool editor_get_unk0d4_00(void)
{
	struct headeditor *editor = camdraw_current_editor();
	return editor->unk0d4_00;
}

bool editor_is_autocalibrating(void)
{
	struct headeditor *editor = camdraw_current_editor();
	return editor->autocalstatus == AUTOCALSTATUS_OFF ? false : true;
}

void phead_set_unk3bc(s32 value)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	head->unk3bc = value;

	func0f14def0(HEADID_EDITOR, 1518, "camdraw.c");
}

void phead_reset_unk3bc(void)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	head->unk3bc = 128;
}

s32 phead_get_unk3bc(void)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	return head->unk3bc;
}

void phead_set_unk3a4(s32 value)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	head->unk3a4 = value;
}

void phead_reset_unk3a4(void)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	head->unk3a4 = 0;
}

s32 phead_get_unk3a4(s32 index)
{
	struct perfecthead *head = phead_find(index);
	return head->unk3a4;
}

void phead_set_unk3b8(s32 value)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	head->unk3b8 = value;
}

void phead_reset_unk3b8(void)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	head->unk3b8 = 6;
}

s32 phead_get_unk3b8(void)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	return head->unk3b8;
}

const char var7f1b65f0[] = "Cam -> Setting current hair colour to %s\n";
const char var7f1b661c[] = "Cam -> Setting current face colour to %s\n";

void phead_set_colournum(s32 colournum)
{
	struct perfecthead *head;

	camdraw_get_colour_name(colournum);

	head = phead_find(HEADID_EDITOR);
	head->colournum = colournum;
}

void phead_reset_colournum(void)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	head->colournum = 0;
}

s32 phead_get_colournum(void)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	return head->colournum;
}

void phead_set_stylenum(s32 stylenum)
{
	struct perfecthead *head;

	camdraw_get_style_name(stylenum);

	head = phead_find(HEADID_EDITOR);
	head->stylenum = stylenum;
}

void phead_reset_stylenum(void)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	head->stylenum = 0;
}

s32 phead_get_stylenum(void)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	return head->stylenum;
}

void phead_set_unk3b4(s32 value)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	head->unk3b4 = value;
}

s32 phead_get_unk3b4(void)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	return head->unk3b4;
}

void editor_set_unk06c(s32 index, s32 arg1)
{
	g_HeadEditors[index].unk06c = arg1;
}

s32 editor_get_unk06c(s32 index)
{
	return g_HeadEditors[index].unk06c;
}

bool phead_get_unk3f4_02(void)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	return head->unk3f4_02;
}

void phead_set_unk3f4_02(bool value)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	head->unk3f4_02 = value;

	func0f14def0(HEADID_EDITOR, 1681, "camdraw.c");
}

bool phead_get_autodeartefact(void)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	return head->autodeartefact;
}

void phead_set_autodeartefact(bool enabled)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);

	if (enabled) {
		head->autodeartefact = true;
	} else {
		head->autodeartefact = false;
	}

	osSyncPrintf("Cam_SetAutoDeArtefact -> State = %d\n", enabled);

	func0f14def0(HEADID_EDITOR, 1699, "camdraw.c");
}

u16 editor_get_unk05c(s32 device)
{
	return g_HeadEditors[device].timenow & 0xffff;
}

s32 editor_get_unk060(s32 device)
{
	return g_HeadEditors[device].unk060;
}

const char var7f1b6688[] = "Cam_ClearCameraLoadBuffer -> Camera=%d\n";
const char var7f1b66b0[] = "Cam_StartTemp : Need %u bytes for temp cam images buffer\n";

void editor_init(s32 index)
{
	struct headeditor *editor = &g_HeadEditors[index];

	editor->unk000 = 0;
	editor->unk004 = 1.0f;
	editor->unk008 = 1.0f;
	editor->unk050 = 110.0f;
	editor->unk00c = 0.1f;
	editor->unk010 = 0.2f;
	editor->unk058 = -1;
	editor->unk068 = -1;
	editor->unk06c = 0;
	editor->unk070 = 0;
	editor->unk074 = 0;
	editor->unk084 = 0;
	editor->unk054 = 30;
	editor->unk014 = 0.0f;
	editor->unk018 = 0.0f;
	editor->unk01c = 0.0f;
	editor->unk020 = 0.0f;
	editor->unk024 = 1.0f;
	editor->unk028 = 1.0f;
	editor->unk02c = 0.0f;
	editor->unk030 = 0.0f;
	editor->unk034 = 0.0f;
	editor->unk038 = 0.0f;
	editor->unk03c = 1.0f;
	editor->unk040 = 0.0f;
	editor->unk044 = 30.0f;
	editor->timenow = var8007f904[30];
	editor->unk060 = 6;
	editor->unk08c = 14;
	editor->unk048 = 1.00f;
	editor->unk088 = 1;
	editor->unk090 = 0;
	editor->timeinc = 0;
	editor->readmode = READMODE_INIT;
	editor->numvalidimages = 0;
	editor->unk0d4_00 = false;
	editor->unk0d4_01 = false;
	editor->unk0d4_02 = false;
	editor->unk0d4_04 = true;
	editor->autocalstatus = AUTOCALSTATUS_OFF;
	editor->unk0fc = EDITOR100_3;
	editor->unk100 = EDITOR100_3;
	editor->unk0e0 = 0;
	editor->unk0e4 = 0;
	editor->unk0e8 = 0;
	editor->unk0ec = 0;
	editor->unk0f0 = 0;
	editor->unk078 = 0;
	editor->unk07c = 0;
}

bool editor_needs_gbpak(s32 device)
{
	return g_HeadEditors[device].needsgbpak;
}

void func0f14aec8(void)
{
	// empty
}

void func0f14aed0(s32 device)
{
	// empty
}

void func0f14aed8(void)
{
	// empty
}

void func0f14aee0(void)
{
	s32 i;
	s32 j;

	if (g_HeadEditorData->unk484 == NULL) {
		struct textureconfig tconfig;
		u8 *ptr;
		s32 texturesize;
		s32 count = 33;
		s32 totalsize;
		u32 stack[2];

		func0f14c7dc(&tconfig);

		texturesize = align32(camdraw_get_texture_size(&tconfig));

		totalsize = align16(sizeof(struct textureconfig) * count);
		totalsize += align16(texturesize * count);

		ptr = memp_alloc(totalsize, MEMPOOL_STAGE);

		g_HeadEditorData->unk484 = (struct textureconfig *)ptr;
		ptr += sizeof(struct textureconfig) * count;

		for (i = 0; i < count; i++) {
			func0f14c7dc(&g_HeadEditorData->unk484[i]);
			g_HeadEditorData->unk484[i].textureptr = ptr;
			ptr += texturesize;
		}

		for (i = 0; i < count; i++) {
			camdraw_write_gradient_texture(&g_HeadEditorData->unk484[i]);
		}

		g_HeadEditorData->unk488 = g_HeadEditorData->unk484 + 32;
	}

	g_HeadEditorData->numallocations = 0;

	g_HeadEditorData->unk470 = camdraw_allocate(IMGNUMPIXELS_EDIT * sizeof(*g_HeadEditorData->unk470), 1915, "camdraw.c");
	g_HeadEditorData->unk474 = camdraw_allocate(IMGNUMPIXELS_EDIT * sizeof(*g_HeadEditorData->unk474), 1916, "camdraw.c");
	g_HeadEditorData->unk478 = camdraw_allocate(IMGNUMPIXELS_EDIT * sizeof(*g_HeadEditorData->unk478), 1917, "camdraw.c");
	g_HeadEditorData->unk47c = camdraw_allocate(NUM_UNK47C * sizeof(*g_HeadEditorData->unk47c), 1918, "camdraw.c");
	g_HeadEditorData->unk480 = camdraw_allocate(IMGNUMPIXELS_THUMB * sizeof(*g_HeadEditorData->unk480), 1919, "camdraw.c");

	for (i = 0; i < MAX_EDITORS; i++) {
		struct headeditor *editor = &g_HeadEditors[i];

		osSyncPrintf("Camera -> Cam_Start for Camera %d\n", i);

		editor->unk0dc = g_HeadEditorData->unk47c;
		editor->unk0d8 = g_HeadEditorData->unk480;
		editor->unk07c = -1;
		editor->unk078 = 0;

		pak0f117150(i, editor->unk0d8);
		pak0f1171b4(SAVEDEVICE_CONTROLLERPAK1, PAK00C_03, 0);
		func0f14aed0(i);

		editor->numvalidimages = 0;

		for (j = 0; j < ARRAYCOUNT(editor->imageslots); j++) {
			editor->imageslots[j] = 0xff;
			editor->validimages[j] = 0xff;
		}
	}

	camdraw_set_editor_index(0);
}

void camdraw_stop(void)
{
	osSyncPrintf("Camera -> Cam_Stop\n");

	g_HeadEditorData->unk48c = 0;

	camdraw_finish();
}

void camdraw_finish(void)
{
	s32 i;

	camdraw_free(g_HeadEditorData->unk470, IMGNUMPIXELS_EDIT * sizeof(*g_HeadEditorData->unk470));
	camdraw_free(g_HeadEditorData->unk474, IMGNUMPIXELS_EDIT * sizeof(*g_HeadEditorData->unk474));
	camdraw_free(g_HeadEditorData->unk478, IMGNUMPIXELS_EDIT * sizeof(*g_HeadEditorData->unk478));
	camdraw_free(g_HeadEditorData->unk47c, NUM_UNK47C * sizeof(*g_HeadEditorData->unk47c));
	camdraw_free(g_HeadEditorData->unk480, IMGNUMPIXELS_THUMB * sizeof(*g_HeadEditorData->unk480));

	for (i = 0; i < MAX_EDITORS; i++) {
		struct headeditor *editor = &g_HeadEditors[i];

		editor->needsgbpak = false;
		editor->unk0dc = NULL;
		editor->unk0d8 = NULL;
	}

	osSyncPrintf("Camera -> Cam_Finish - Done\n");
}

void phead_set_defaults(struct perfecthead *head)
{
	s32 i;

	head->unk03c = 0;
	head->active = false;

	for (i = 0; i < ARRAYCOUNT(head->unk040); i++) {
		head->unk040[i] = 0xff;
	}

	for (i = 0; i < ARRAYCOUNT(head->unk2fc); i++) {
		head->unk2fc[i] = 0xff;
	}

	for (i = 0; i < ARRAYCOUNT(head->unk108); i++) {
		head->unk108[i] = 0xff;
	}

	for (i = 0; i < ARRAYCOUNT(head->unk3d0); i++) {
		head->unk3d0[i] = 1.0f;
	}

	head->quality = 3;
	head->autodeartefact = false;
	head->unk3f4_02 = true;
	head->unk3f4_03 = false;
	head->unk028 = 0;
	head->unk02c = 0;
	head->unk034 = 0;
	head->unk030 = 1.0f;
	head->unk3f4_04 = false;
	head->colournum = 0;
	head->stylenum = 0;
	head->unk3a4 = 0;
	head->unk3a8 = -1;
	head->unk3ac = -1;
	head->unk3b0 = -1;
	head->unk3b4 = 16;
	head->unk3b8 = 6;
	head->unk3bc = 128;
	head->unk3c0 = 10;
	head->unk3c4 = 54;
	head->unk3c8 = 3;
	head->unk3cc = 61;
	head->unk3ec = 0;
	head->unk3f0 = 0;
	head->fileguid.fileid = 0;
	head->fileguid.deviceserial = 0;
}

const char var7f1b6780[] = "Camera ->Created a new slot - Id=%d\n";
const char var7f1b67a8[] = "Camera -> CD_DeleteSlot - Dumping slot %d\n";

void func0f14b358(void)
{
	// empty
}

void phead_reset(s32 index)
{
	struct perfecthead *head = phead_find(index);

	phead_set_defaults(head);
	phead_randomise_textures(head);
}

void phead_randomise_textures(struct perfecthead *head)
{
	s32 size;
	s32 i;

	size = align32(camdraw_get_texture_size(&head->fullsizetex));

	for (i = 0; i < size; i++) {
		head->fullsizetex.textureptr[i] = random() % 0xff;
	}

	size = align32(camdraw_get_texture_size(&head->thumbnailtex));

	for (i = 0; i < size; i++) {
		head->thumbnailtex.textureptr[i] = random() % 0xff;
	}

	phead_set_defaults(head);
}

bool func0f14b484(s32 index)
{
	struct headeditor *editor = &g_HeadEditors[index];

	editor->unk004 = var8007f8e8 * 0.01f;
	editor->unk008 = var8007f8ec * 0.01f;
	editor->unk00c = var8007f8f0 * 0.01f;
	editor->unk010 = var8007f8f4 * 0.01f;
	editor->unk000 = var8007f8fc;
	editor->unk050 = var8007f900;
	editor->unk020 = editor->unk024;
	editor->unk038 = editor->unk03c;
	editor->unk024 = osGetCount() * 0.0000001f;
	editor->unk028 = editor->unk024 - editor->unk020;

	if (editor->unk028 > 15) {
		editor->unk028 = 15;
	}

	editor->unk03c = editor->unk04c - editor->unk050;
	editor->unk01c = editor->unk03c;
	editor->unk018 = editor->unk03c / editor->unk028;
	editor->unk014 += editor->unk03c * editor->unk028;

	if (editor->unk014 > 500) {
		editor->unk014 = 500;
	}

	if (editor->unk014 < -500) {
		editor->unk014 = -500;
	}

	editor->unk034 = editor->unk010 * -1.0f * editor->unk018;
	editor->unk02c = editor->unk008 * editor->unk01c;
	editor->unk030 = editor->unk00c * editor->unk014;
	editor->unk040 = -editor->unk004 * ((editor->unk010 * -1.0f * editor->unk018) + editor->unk008 * editor->unk01c + editor->unk00c * editor->unk014);

	if (editor->unk000) {
		if (ABS(editor->unk03c) > 10.0f) {
			if (ABS(editor->unk040) >= 1.0f) {
				editor->unk054 += (s32)editor->unk040;

				if (editor->unk054 > 80) {
					editor->unk054 = 80;
				}

				if (editor->unk054 < 1) {
					editor->unk054 = 1;
				}

				editor->unk044 += editor->unk040;

				if (editor->unk044 > 80) {
					editor->unk044 = 80;
				}

				if (editor->unk044 < 1) {
					editor->unk044 = 1;
				}

				editor->timenow = var8007f904[editor->unk054];

				if (editor->timenow < var8007f904[1]) {
					editor->timenow = var8007f904[1];
					editor->unk060--;

					if (editor->unk060 < 2) {
						editor->unk060 = 2;
					}
				} else if (editor->timenow > var8007f904[80]) {
					editor->timenow = var8007f904[80];
					editor->unk060++;

					if (editor->unk060 > 10) {
						editor->unk060 = 10;
					}
				}

				editor->unk014 = 0.0f;
			}
		} else {
			editor->unk014 = 0.0f;
		}
	}

	if (editor->unk04c < 70 || editor->unk04c > 160) {
		return false;
	}

	return true;
}

void func0f14b8ac(s32 index)
{
	struct headeditor *editor = &g_HeadEditors[index];

	main_override_variable("kg", &var8007f8e8);
	main_override_variable("Kp", &var8007f8ec);
	main_override_variable("Ki", &var8007f8f0);
	main_override_variable("Kd", &var8007f8f4);
	main_override_variable("tInt", &var8007f8f8);
	main_override_variable("gocal", &var8007f8fc);
	main_override_variable("aim", &var8007f900);

	if (editor->unk0d4_00) {
		editor_stop_autocalibrate();
		return;
	}

	phead_reset_unk3bc();

	if (pak0f11d3f8(camdraw_get_editor_index())) {
		pak0f11d620(camdraw_get_editor_index());

		if (editor->autocalstatus == AUTOCALSTATUS_OFF && g_HeadEditors[g_HeadEditorData->editorindex].unk0d4_04 == false) {
			func0f14e790(g_HeadEditorData->unk470);
			editor_set_unk100(EDITOR100_1);
			editor_make_textures();
			return;
		}

		switch (pak_get_unk008(camdraw_get_editor_index())) {
		case PAK008_12:
			phead_reset_unk3bc();
			phead_reset_unk3b8();
			func0f14e790(g_HeadEditorData->unk470);
			editor_stop_autocalibrate();
			pak0f11e3bc(camdraw_get_editor_index());
			editor_set_unk100(EDITOR100_1);
			editor_make_textures();
			break;
		case PAK008_01:
			pak0f11d4dc(camdraw_get_editor_index());
			break;
		case PAK008_11:
			pak0f11d9c4(camdraw_get_editor_index(), g_HeadEditorData->unk470, 0, 0);
			editor_autocalibrate(index, g_HeadEditorData->unk470);
			pak0f11d478(camdraw_get_editor_index());

			if (editor->autocalstatus == AUTOCALSTATUS_OFF) {
				editor_set_unk100(EDITOR100_3);
				editor_make_textures();

				if (g_HeadEditors[g_HeadEditorData->editorindex].unk0d4_04) {
					struct perfecthead *head = phead_find(HEADID_EDITOR);
					head->active = true;
				}
			} else {
				editor_set_unk100(EDITOR100_4);
				editor_make_textures();
			}

			if (!editor_is_autocalibrating()) {
				func0f14b484(g_HeadEditorData->editorindex);
			}
			break;
		}
	} else {
		editor_stop_autocalibrate();
		func0f14e7e0(g_HeadEditorData->unk470);
		editor_set_unk100(EDITOR100_3);
		editor_make_textures();
	}
}

void editor_make_textures(void)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	struct headeditor *editor = camdraw_current_editor();

	osSyncPrintf("CAM : Cam_MakeTextures\n");

	head->unk3f4_02 = true;

	switch (editor->unk100) {
	case EDITOR100_0:
		break;
	case EDITOR100_1:
		head->unk3f4_02 = false;
		editor_make_texture_type4(g_HeadEditorData->unk470, head->unk01c);
		break;
	case EDITOR100_4:
		editor_make_texture_type4(g_HeadEditorData->unk470, head->unk01c);
		break;
	case EDITOR100_2:
		editor_make_texture_type2(g_HeadEditorData->unk470, head->unk01c);
		break;
	case EDITOR100_3:
		editor_make_texture_type3(g_HeadEditorData->unk470, head->unk01c);
		break;
	case EDITOR100_5:
		editor_make_texture_type5(head);
		break;
	}

	func0f14def0(HEADID_EDITOR, 2433, "camdraw.c");

	if (editor->unk100 != EDITOR100_4) {
		phead0f14dac0(g_HeadEditorData->unk470, &head->thumbnailtex);
	}

	head->unk3f4_03 = false;
}

void func0f14bd34(s32 index)
{
	struct headeditor *editor = &g_HeadEditors[index];

	if (editor->unk080 != -1) {
		pak0f1171b4(camdraw_get_editor_index(), PAK00C_03, 0);
		pak0f11d540(camdraw_get_editor_index(), editor->validimages[editor->unk080]);
	}
}

void func0f14bdbc(s32 index)
{
	struct headeditor *editor = &g_HeadEditors[index];
	struct perfecthead *head;
	s32 i;

	for (i = 0; i < NUM_UNK47C; i++) {
		editor->unk0dc[i] = NULL;
	}

	editor->numvalidimages = 0;

	for (i = 0; i < ARRAYCOUNT(editor->imageslots); i++) {
		editor->imageslots[i] = 0xff;
		editor->validimages[i] = 0xff;
	}

	if (g_HeadEditors[index].readmode == READMODE_EXIT1 || g_HeadEditors[index].readmode == READMODE_EXIT2) {
		editor->readmode = READMODE_EXIT3;
		g_MpPlayerNum = index;
		menu_set_banner(-1, false);

		head = phead_find(HEADID_EDITOR);
		head->active = false;

		g_MpPlayerNum = index;

		menu_pop_dialog();

		g_MpPlayerNum = 0;
	} else {
		pak0f11e3bc(camdraw_get_editor_index());

		editor->readmode = READMODE_INIT;
	}
}

void editor_cycle_handle_read(s32 index)
{
	struct headeditor *editor = &g_HeadEditors[index];
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	struct textureconfig *tconfig;
	s32 i;

	if (editor->readmode == READMODE_EXIT1 && editor->unk080 == editor->unk074) {
		editor->readmode = READMODE_EXIT2;
	}

	osSyncPrintf("pD->ReadMode = %s");

	switch (editor->readmode) {
	case READMODE_STARTHEADER:
		osSyncPrintf("Camera -> Getting Header Info\n");

		pak0f11d9c4(index, NULL, editor->imageslots, 0);

		editor->readmode = READMODE_DONEHEADER;

		for (i = 0; i < ARRAYCOUNT(editor->imageslots); i++) {
			osSyncPrintf("Camera -> Item=%d, pD->CamHeader[i]=%d\n");

			if (editor->imageslots[i] != 0xff) {
				editor->imageslots[i] += 2;
			}
		}

		for (i = 0, editor->numvalidimages = 0; i < ARRAYCOUNT(editor->imageslots); i++) {
			if (editor->imageslots[i] != 0xff) {
				editor->validimages[editor->numvalidimages] = editor->imageslots[i];
				editor->numvalidimages++;
			}
		}

		for (i = editor->numvalidimages; i < ARRAYCOUNT(editor->validimages); i++) {
			editor->validimages[i] = 0xff;
		}

		if (editor->numvalidimages) {
			osSyncPrintf("Camera -> Found %d Valid images\n", editor->numvalidimages);
		}

		for (i = 0; i < ARRAYCOUNT(editor->validimages); i++) {
			osSyncPrintf("Camera -> Item=%d, Valid=%s, Bank=%d\n", i, 0 ? "YES" : "NO", index);
		}

		pak0f1171b4(camdraw_get_editor_index(), PAK00C_03, 0);
		pak0f11d478(camdraw_get_editor_index());
		break;
	case READMODE_NULL:
		// The location of this message is probably wrong
		osSyncPrintf("CD_TransferCurrentCacheToEditorAndExit : Player=%d, pD->CamRdImg=%d\n");

		pak0f11d9c4(camdraw_get_editor_index(), g_HeadEditorData->unk470, 0, 1);
		tconfig = &g_HeadEditorData->unk484[editor->unk080];
		editor_set_unk100(EDITOR100_2);
		editor_make_textures();
		camdraw_copy_texture(tconfig, &head->fullsizetex);
		editor->unk0dc[editor->unk080] = 1;
		pak0f11d478(camdraw_get_editor_index());
		break;
	case READMODE_EXIT1:
		pak0f11d478(camdraw_get_editor_index());
		break;
	case READMODE_EXIT2:
		pak0f11d9c4(camdraw_get_editor_index(), g_HeadEditorData->unk470, 0, 1);
		editor_set_unk100(EDITOR100_3);
		editor_make_textures();
		pak0f11d478(camdraw_get_editor_index());
		g_MpPlayerNum = index;
		menu_set_banner(-1, false);
		func0f14a678();
		head->active = true;
		g_MpPlayerNum = index;
		stub0f102230();
		g_MpPlayerNum = 0;
		editor->readmode = READMODE_EXIT3;
		break;
	case READMODE_DONEHEADER:
	case READMODE_EXIT3:
		break;
	}
}

void func0f14c1cc(s32 index)
{
	struct headeditor *editor = &g_HeadEditors[index];
	s32 count = editor_get_num_valid_images(index);
	s32 max = count / 2 + 1;
	s32 i;

	switch (editor->readmode) {
	case READMODE_INIT:
		osSyncPrintf("Camera -> CD_CycleHandleRead - Need to load up the camera header\n");
		pak0f1171b4(camdraw_get_editor_index(), PAK00C_00, 0);
		pak0f11d5b0(camdraw_get_editor_index());
		editor->readmode = READMODE_STARTHEADER;
		break;
	case READMODE_DONEHEADER:
		editor->readmode = READMODE_NULL;
		break;
	case READMODE_EXIT1:
		if (editor->unk074 != editor->unk080) {
			editor->unk0dc[editor->unk074] = 0;
			editor->unk080 = editor->unk074;
			editor->readmode = READMODE_EXIT2;

			func0f14bd34(index);
		}
		break;
	case READMODE_NULL:
		editor->unk080 = -1;

		for (i = 0; i < max; i++) {
			s32 a = (editor->unk074 + i) % count;
			s32 b = editor->unk074 - i;

			if (b < 0) {
				b += count;
			}

			if (editor->unk0dc[a] == 0 && editor->validimages[a] != 0xff) {
				editor->unk080 = a;
				break;
			}

			if (editor->unk0dc[b] == 0 && editor->validimages[b] != 0xff) {
				editor->unk080 = b;
				break;
			}

			// The location of this message is probably wrong
			osSyncPrintf("Camera -> CD_CycleHandleRead - Image %d needs loading for editor coppying on menu exit\n");
		}
		func0f14bd34(index);
		break;
	case READMODE_STARTHEADER:
	case READMODE_EXIT2:
		osSyncPrintf("Camera -> CD_CycleHandleRead - Error ekCamReadModeExit2 in Null cycle\n");
		break;
	}
}

void func0f14c3a4(s32 index)
{
	struct headeditor *editor = &g_HeadEditors[index];
	s32 i;

	if (pak0f11d3f8(camdraw_get_editor_index()) == 0) {
		for (i = 0; i < NUM_UNK47C; i++) {
			editor->unk0dc[i] = 0;
		}

		for (i = 0; i < ARRAYCOUNT(editor->imageslots); i++) {
			editor->numvalidimages = 0;
			editor->imageslots[i] = 0xff;
			editor->validimages[i] = 0xff;
		}
	} else {
		pak0f11d620(camdraw_get_editor_index());

		switch (pak_get_unk008(camdraw_get_editor_index())) {
		case PAK008_01:
			func0f14c1cc(index);
			break;
		case PAK008_11:
			editor_cycle_handle_read(index);
			break;
		case PAK008_12:
			func0f14bdbc(index);
			break;
		}
	}
}

void editor_begin_download(s32 index)
{
	g_HeadEditors[index].readmode = READMODE_EXIT1;
	g_MpPlayerNum = index;

	menu_set_banner(MENUBANNER_DOWNLOADINGIMAGE, false);
}

void camdraw_copy(struct perfecthead *dst, struct perfecthead *src, u32 line, char *file)
{
	struct perfecthead *head;
	s32 i;
	s32 j;
	s32 x;
	s32 srcrow;
	s32 dstrow;
	s32 srcnum;
	s32 dstnum;

	for (i = 0; i < ARRAYCOUNT(g_HeadEditorData->unk014); i++) {
		head = &g_PerfectHeadSlots[i];

		if (head == src) {
			srcnum = i;
		}

		if (head == dst) {
			dstnum = i;
		}
	}

	osSyncPrintf("CAMERA : COPY SLOT (%d of %s): Slot %d(%s) -> Slot %d(%s)\n",
			line, file,
			srcnum, src->active ? "ACTIVE" : "NULL",
			dstnum, dst->active ? "ACTIVE" : "NULL");

	dst->active = src->active;
	dst->autodeartefact = src->autodeartefact;
	dst->unk3f4_02 = src->unk3f4_02;
	dst->unk3f4_03 = src->unk3f4_03;
	dst->colournum = src->colournum;
	dst->stylenum = src->stylenum;
	dst->unk3a4 = src->unk3a4;
	dst->unk3b4 = src->unk3b4;
	dst->unk3b8 = src->unk3b8;
	dst->unk3bc = src->unk3bc;
	dst->unk3c0 = src->unk3c0;
	dst->unk3c4 = src->unk3c4;
	dst->unk3c8 = src->unk3c8;
	dst->unk3cc = src->unk3cc;
	dst->unk3ec = src->unk3ec;
	dst->unk3f0 = src->unk3f0;

	dst->fileguid.fileid = src->fileguid.fileid;
	dst->fileguid.deviceserial = src->fileguid.deviceserial;

	for (i = 0; i < ARRAYCOUNT(dst->unk3d0); i++) {
		dst->unk3d0[i] = src->unk3d0[i];
	}

	if (dst->unk01c) {
		for (j = IMGHEIGHT_THUMB - 1, dstrow = 0, srcrow = (IMGHEIGHT_THUMB - 1) * IMGWIDTH_THUMB; (srcrow ^ 0) != -IMGHEIGHT_THUMB;) {
			for (x = 0; x != IMGWIDTH_THUMB;) {
				s32 fudge = (j & 1) ? ((x & 4) ? -4 : 4) : 0;
				u8 tmp = *(u8 *) (src->fullsizetex.texturenum + (0, fudge) + srcrow + x);

				dst->unk01c[dstrow + x] = tmp;
				x++;
			}

			j--;
			srcrow -= IMGWIDTH_THUMB;
			dstrow += IMGWIDTH_THUMB;
		}
	}

	camdraw_copy_texture(&dst->fullsizetex, &src->fullsizetex);

	if (dst->thumbnailtex.textureptr && src->thumbnailtex.textureptr) {
		camdraw_copy_texture(&dst->thumbnailtex, &src->thumbnailtex);
	} else {
		osSyncPrintf("RWI : Warning -> Not copying the thumbnail texture\n");
	}

	if (src->unk3f4_03) {
		for (i = 0; i < IMGNUMPIXELS_SAVE; i++) {
			dst->unk020[i] = src->unk020[i];
		}
	}
}

void camdraw_copy_texture(struct textureconfig *dst, struct textureconfig *src)
{
	s32 i;
	u32 size = align32(camdraw_get_texture_size(dst));

	align32(camdraw_get_texture_size(src));

	for (i = 0; i < size; i++) {
		dst->textureptr[i] = src->textureptr[i];
	}
}

void func0f14c7dc(struct textureconfig *tconfig)
{
	tconfig->width = IMGWIDTH_THUMB;
	tconfig->height = IMGHEIGHT_THUMB;
	tconfig->level = 0;
	tconfig->format = G_IM_FMT_I;
	tconfig->depth = G_IM_SIZ_8b;
	tconfig->s = 0;
	tconfig->t = 1;
	tconfig->unk0b = 1;
}

void func0f14c80c(void)
{
	// empty
}

u32 camdraw_get_texture_size(struct textureconfig *tconfig)
{
	u32 size = tconfig->width * tconfig->height;

	switch (tconfig->depth) {
	case G_IM_SIZ_4b:
		size >>= 1;
		break;
	case G_IM_SIZ_16b:
		size *= 2;
		break;
	case G_IM_SIZ_32b:
		size *= 4;
		break;
	case G_IM_SIZ_8b:
		break;
	}

	return size;
}

Gfx *phead_draw_texture(Gfx *gdl, struct textureconfig *tconfig, f32 pos[2], f32 width, f32 height)
{
	static struct texpool texpool;

	u32 x = (pos[0] + 0.5f) * 4.0f;
	u32 y = (pos[1] + 0.5f) * 4.0f;

	u32 pxwidth = ((pos[0] - 0.5f) + (width * tconfig->width)) * 4.0f;
	u32 pxheight = ((pos[1] - 0.5f) + (width * tconfig->height)) * 4.0f; // @bug? Using width

	u32 stack;
	s32 sp28 = (tconfig->height - 0.5f) * 32.0f;

	osSyncPrintf("CD_DrawTexture : pTex=%x\n", tconfig);

	gDPPipeSync(gdl++);
	gDPSetTextureFilter(gdl++, G_TF_POINT);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);

	tex_select(&gdl, tconfig, 1, 0, 2, 1, &texpool);

	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);

	gSPTextureRectangle(gdl++,
			x * g_ScaleX, y,
			pxwidth * g_ScaleX, pxheight,
			G_TX_RENDERTILE, 16, sp28,
			(s32)(1024.0f / width) / g_ScaleX,
			(s32)(1024.0f / height));

	return gdl;
}

#define SAFEZONE 32

void editor_recalc_intensity_table(s32 index, u8 *arg1)
{
	s32 numsamples;
	s32 x;
	s32 y;

	g_HeadEditors[index].unk04c = 0;

	numsamples = 0;

	for (y = SAFEZONE; y < IMGHEIGHT_EDIT - SAFEZONE; y++) {
		for (x = SAFEZONE; x < IMGWIDTH_EDIT - SAFEZONE; x++) {
			numsamples++;
			g_HeadEditors[index].unk04c += arg1[y * IMGWIDTH_EDIT + x];
		}
	}

	if (numsamples > 0) {
		g_HeadEditors[index].unk04c /= numsamples;
	} else {
		osSyncPrintf("Cam -> WARNING - Not done intensity table recalc :- No samples within threshold\n");
		g_HeadEditors[index].unk04c = 0;
	}
}

void editor_reset_autocalibrate(void)
{
	osSyncPrintf("Camera -> Call to reset auto calibrate\n");

	if (pak0f11d3f8(camdraw_get_editor_index())) {
		if (pak_get_unk008(camdraw_get_editor_index()) != PAK008_12) {
			g_HeadEditors[camdraw_get_editor_index()].autocalstatus = AUTOCALSTATUS_RESET;
			g_HeadEditors[camdraw_get_editor_index()].unk0d4_00 = false;

			phead_reset_unk3bc();
			phead_reset_unk3b8();
			phead_reset_colournum();
			phead_reset_stylenum();
		} else {
			pak0f11e3bc(camdraw_get_editor_index());
		}
	}
}

void editor_stop_autocalibrate(void)
{
	g_MpPlayerNum = 0;

	menu_set_banner(-1, false);

	if (g_HeadEditors[camdraw_get_editor_index()].autocalstatus != AUTOCALSTATUS_OFF) {
		switch (g_HeadEditors[camdraw_get_editor_index()].autocalstatus) {
		case AUTOCALSTATUS_2:
		case AUTOCALSTATUS_3:
		case AUTOCALSTATUS_4:
		case AUTOCALSTATUS_5:
		case AUTOCALSTATUS_FINISH:
			pak0f1171b4(camdraw_get_editor_index(), PAK00C_03, 0);
			g_MpPlayerNum = 0;
			menu_set_banner(-1, false);
			break;
		}

		g_HeadEditors[camdraw_get_editor_index()].autocalstatus = AUTOCALSTATUS_OFF;
	}
}

void editor_autocalibrate(s32 index, u8 *arg1)
{
	struct headeditor *editor = &g_HeadEditors[index];
	f32 a;
	f32 b;

	if (editor->autocalstatus == AUTOCALSTATUS_RESET) {
		osSyncPrintf("AC -> ekCamAutoCalStatusReset - pD->tTime = %d, pD->tTimeNxAdd = %d\n");

		editor->timenow = 0x4000;
		editor->timeinc = 0x2000;
		editor->unk060 = 6;
		g_MpPlayerNum = index;
		menu_set_banner(MENUBANNER_CALIBRATINGCAMERA, false);
		editor_set_unk100(EDITOR100_1);
		pak0f1171b4(camdraw_get_editor_index(), PAK00C_01, 1);
		editor->autocalstatus = AUTOCALSTATUS_3;
		return;
	}

	if (editor->autocalstatus == AUTOCALSTATUS_3) {
		editor_recalc_intensity_table(index, arg1);
		a = editor->unk04c;

		if (a > 130) {
			b = a - 130;
		} else {
			b = -(a - 130);
		}

		if (b < 10 || editor->timeinc == 64) {
			osSyncPrintf("Cam 0 -> Time = %d, Target = %d, tInt = %.2f\n");
			editor->autocalstatus = AUTOCALSTATUS_2;
		} else {
			if (a < 130) {
				osSyncPrintf("Cam 0 -> Too Low -> Adding Time\n");
				editor->timenow += editor->timeinc;
			} else {
				osSyncPrintf("Cam 0 -> Too High -> Subbing Time\n");
				editor->timenow -= editor->timeinc;
			}

			editor->timeinc >>= 1;

			osSyncPrintf("Cam -> ekCamAutoCalStatusSettingTime - New time = %d\n", editor->timenow);
		}
	}

	if (editor->autocalstatus == AUTOCALSTATUS_2) {
		editor_recalc_intensity_table(index, arg1);

		if (editor->unk060 == 12 || editor->unk04c > 120) {
			osSyncPrintf("%s%sAC -> Gain = %d, Target = %.2f, tInt = %.2f\n", "", "");
			editor->autocalstatus = AUTOCALSTATUS_FINISH;
		} else {
			editor->unk060 += 2;
		}
	}

	if (editor->autocalstatus == AUTOCALSTATUS_FINISH) {
		pak0f1171b4(camdraw_get_editor_index(), PAK00C_03, 0);
		editor->autocalstatus = AUTOCALSTATUS_FINISH;
		editor->unk100 = editor->unk0fc;
		g_MpPlayerNum = index;

		osSyncPrintf("Auto Calibrate is removing the menu message\n");
		menu_set_banner(-1, false);

		pak0f1171b4(camdraw_get_editor_index(), PAK00C_03, 0);
		g_HeadEditors[g_HeadEditorData->editorindex].unk0d4_04 = true;
		editor->autocalstatus = AUTOCALSTATUS_OFF;
	}

	if (editor->autocalstatus == AUTOCALSTATUS_OFF) {
		osSyncPrintf("Auto Calibrate is shutting down\n");
		editor_recalc_intensity_table(index, arg1);
	}
}

const char var7f1b6ca8[] = "Cam -> Cam_BalanceSlot %d -> tZroShift = %d\n";
const char var7f1b6cd8[] = "Cam_BuildFaceTexture (slot=%d): %d of %s\n";

void editor_make_texture_type2(u8 *src, u8 *dst)
{
	f32 *s1 = g_HeadEditorData->unk474;
	f32 *s0 = g_HeadEditorData->unk478;
	s32 size = IMGWIDTH_EDIT;
	s32 i;
	s32 j;
	s32 k;
	s32 l;
	f32 sp50[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
	s32 four = 4;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			s1[i * size + j] = *(j + src + i * size);
		}
	}

	func0f14d84c(sp50, 3);
	func0f14d8d8(s1, s0, size, sp50, 3);

	for (k = 0; k < IMGHEIGHT_THUMB - 1; k++) {
		for (l = 0; l < IMGWIDTH_THUMB - 1; l++) {
			f32 *srcrow = &s0[k * IMGWIDTH_THUMB * four + l * 2];
			f32 f0;

			f0 = (srcrow[0] + srcrow[1] + srcrow[IMGWIDTH_THUMB * 2] + srcrow[IMGWIDTH_THUMB * 2 + 1]) / 4.0f;

			if (f0 < 0.0f) {
				f0 = 0.0f;
			}

			if (f0 > 255.0f) {
				f0 = 255.0f;
			}

			dst[k * IMGWIDTH_THUMB + l] = f0;
		}
	}
}

/**
 * Generate a 64x64 thumbnail from a 128x128 source.
 */
void editor_make_texture_type3(u8 *src, u8 *dst)
{
	f32 *s1 = g_HeadEditorData->unk474;
	f32 *s0 = g_HeadEditorData->unk478;
	s32 i;
	s32 j;
	s32 x;
	s32 y;
	s32 size = IMGWIDTH_EDIT;

	f32 sp50[] = {
		0.0029690000228584f,
		0.013306000269949f,
		0.021937999874353f,
		0.013306000269949f,
		0.0029690000228584f,
		0.013306000269949f,
		0.059634000062943f,
		0.098319999873638f,
		0.059634000062943f,
		0.013306000269949f,
		0.021937999874353f,
		0.098319999873638f,
		0.16210299730301f,
		0.098319999873638f,
		0.021937999874353f,
		0.013306000269949f,
		0.059634000062943f,
		0.098319999873638f,
		0.059634000062943f,
		0.013306000269949f,
		0.0029690000228584f,
		0.013306000269949f,
		0.021937999874353f,
		0.013306000269949f,
		0.0029690000228584f,
	};

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			s32 index = i * size + j;
			s1[index] = src[index];
		}
	}

	func0f14d8d8(s1, s0, size, sp50, 5);

	for (y = 0; y < IMGHEIGHT_THUMB - 1; y++) {
		for (x = 0; x < IMGWIDTH_THUMB - 1; x++) {
			f32 *srcrow = &s0[y * size * 2 + x * 2];
			f32 value = (srcrow[0] + srcrow[1] + srcrow[IMGWIDTH_EDIT] + srcrow[IMGWIDTH_EDIT + 1]) / 4.0f;

			if (value < 0.0f) {
				value = 0.0f;
			}

			if (value > 255.0f) {
				value = 255.0f;
			}

			dst[y * IMGWIDTH_THUMB + x] = value;
		}
	}
}

void editor_make_texture_type4(u8 *src, u8 *dst)
{
	s32 x;
	s32 y;

	for (y = 0; y < IMGHEIGHT_THUMB - 1; y++) {
		for (x = 0; x < IMGWIDTH_THUMB - 1; x++) {
			u8 *srcrow = &src[y * IMGWIDTH_EDIT * 2 + x * 2];
			f32 value = (srcrow[0] + srcrow[1] + srcrow[IMGWIDTH_EDIT] + srcrow[IMGWIDTH_EDIT + 1]) / 4.0f;

			if (value < 0.0f) {
				value = 0.0f;
			}

			if (value > 255.0f) {
				value = 255.0f;
			}

			dst[y * IMGWIDTH_THUMB + x] = value;
		}
	}
}

void func0f14d84c(f32 *arg0, s32 arg1)
{
	f32 sum = 0;
	s32 len = arg1 * arg1;
	f32 mult;
	s32 i;

	for (i = 0; i < len; i++) {
		sum += arg0[i];
	}

	mult = 1 / sum;

	for (i = 0; i < len; i++) {
		arg0[i] *= mult;
	}
}

void func0f14d8d8(f32 *arg0, f32 *arg1, s32 arg2, f32 *arg3, s32 arg4)
{
	s32 t0 = arg4 / 2;
	s32 t1 = t0 + 1;
	s32 v0 = arg2 - 1;
	s32 a3 = -t0;
	s32 i;
	s32 j;
	s32 k;
	s32 l;
	f32 sp5c[19][19];
	s32 m;
	s32 n;

	for (i = 0; i < arg4; i++) {
		for (j = 0; j < arg4; j++) {
			sp5c[i][j] = arg3[i * arg4 + j];
		}
	}

	for (k = 0; k < arg2; k++) {
		for (l = 0; l < arg2; l++) {
			f32 f0 = 0.0f;

			for (m = a3; m < t1; m++) {
				s32 t5 = k + m;

				if (t5 > v0) {
					t5 = v0;
				}

				if (t5 < 0) {
					t5 = 0;
				}

				for (n = a3; n < t1; n++) {
					s32 s2 = l + n;

					if (s2 > v0) {
						s2 = v0;
					}

					if (s2 < 0) {
						s2 = 0;
					}

					f0 += sp5c[m + t0][n + t0] * arg0[t5 * arg2 + s2];
				}
			}

			arg1[k * arg2 + l] = f0;
		}
	}
}

void phead0f14dac0(u8 *arg0, struct textureconfig *texconfig)
{
	s32 i;
	s32 j;
	s32 k;
	s32 l;

	for (i = 0; i < 16; i++) {
		for (j = 0; j < 16; j++) {
			f32 f12 = 0.0f;

			for (k = 0; k < 8; k++) {
				for (l = 0; l < 8; l++) {
					f12 += arg0[(i * 8 + l) * 128 + j * 8 + k];
				}
			}

			f12 *= 0.015625f;

			if (f12 > 255.0f) {
				f12 = 255.0f;
			}

			f12 *= 0.0625f;

			if (texconfig != NULL) {
				func0f14e884(texconfig, 15 - i, j, f12);
			}
		}
	}
}

void func0f14dc30(s32 index, bool arg1)
{
	f32 f26 = phead_get_unk3bc() - 128;
	s32 sp80;
	s32 sp7c;
	s32 x;
	s32 y;
	struct perfecthead *head = phead_find(index);
	f32 f22;

	f22 = head->unk3f4_02 ? func0f14e4ac(0, &sp80, &sp7c) : 0.0f;

	for (y = 0; y < IMGHEIGHT_THUMB; y++) {
		for (x = 0; x < IMGWIDTH_THUMB; x++) {
			f32 f14 = head->unk01c[y * IMGWIDTH_THUMB + x];
			f32 f12;
			f32 f2;

			if (arg1 && head->unk3f4_02 && sp7c) {
				f32 f0 = sp80 - x;
				f32 absf0 = f0 > 0.0f ? f0 : -f0;

				f12 = absf0 / sp7c;

				if (f12 > 1.0f) {
					f12 = 1.0f;
				}

				f2 = f22 * f12;

				if (x > sp80) {
					f2 *= -1.0f;
				}

				f2 *= g_HeadEditors->unk088;
			} else {
				f2 = 0.0f;
			}

			f12 = f14 + f2 + f26;

			if (f12 < 0.0f) {
				f12 = 0.0f;
			}

			if (f12 > 255.0f) {
				f12 = 255.0f;
			}

			head->fullsizetex.textureptr[(u32)(IMGHEIGHT_THUMB - 1 - y) * IMGWIDTH_THUMB + x + (((u32)(IMGHEIGHT_THUMB - 1 - y) & 1) ? ((x & 4) ? -4 : 4) : 0)] = f12;
		}
	}
}

void func0f14def0(s32 index, u32 line, char *file)
{
	struct perfecthead *editorhead = phead_find(HEADID_EDITOR);
	struct perfecthead *selectedhead = (index != -1 ? phead_find(index) : NULL);
	struct perfecthead *special4head = phead_find(HEADID_SPECIAL4);
	struct perfecthead *special5head = phead_find(HEADID_SPECIAL5);

	camdraw_copy(special5head, editorhead, 3508, "camdraw.c");

	func0f14dc30(HEADID_EDITOR, false);

	if (selectedhead != NULL) {
		func0f14e1c4(selectedhead);
	}

	func0f14dc30(HEADID_SPECIAL5, true);

	func0f14e1c4(special5head);
	camdraw_copy(special4head, special5head, 3519, "camdraw.c");
}

const char var7f1b6d1c[] = "Cam %d -> Balance : No Data Available\n";

s32 func0f14dfc0(struct perfecthead *head, s32 x, s32 y)
{
	u32 sp3c[5];
	u32 sp28[5];
	s32 i;
	s32 j;
	s32 len;

	sp28[0] = *(head->fullsizetex.textureptr + y * IMGWIDTH_THUMB + ((y & 1) ? ((x & 4) ? -4 : 4) : 0) + x);
	sp28[1] = *(head->fullsizetex.textureptr + (y - 1) * IMGWIDTH_THUMB + (((y - 1) & 1) ? ((x & 4) ? -4 : 4) : 0) + x);
	sp28[2] = *(head->fullsizetex.textureptr + y * IMGWIDTH_THUMB + ((y & 1) ? (((x - 1) & 4) ? -4 : 4) : 0) + x - 1);
	sp28[3] = *(head->fullsizetex.textureptr + (y + 1) * IMGWIDTH_THUMB + (((y + 1) & 1) ? ((x & 4) ? -4 : 4) : 0) + x);
	sp28[4] = *(head->fullsizetex.textureptr + y * IMGWIDTH_THUMB + ((y & 1) ? (((x + 1) & 4) ? -4 : 4) : 0) + x + 1);

	len = 0;

	for (i = 0; i < ARRAYCOUNT(sp28); i++) {
		s32 bestvalue = 9999;
		s32 bestindex = -1;

		for (j = 0; j < ARRAYCOUNT(sp28); j++) {
			if (sp28[j] < bestvalue) {
				bestindex = j;
				bestvalue = sp28[j];
			}
		}

		if (bestindex != -1) {
			sp3c[len] = sp28[bestindex];
			len++;

			sp28[bestindex] = 99999;
		}
	}

	return (sp3c[1] + sp3c[2] + sp3c[3]) / 3;
}

void func0f14e1c4(struct perfecthead *head)
{
	s32 spbc;
	s32 spb8;
	s32 spb4;
	s32 spb0;
	s32 mid1;
	s32 mid2;
	f32 f26;
	s32 x1;
	s32 x2;
	s32 value1;
	s32 value2;
	f32 f22;
	f32 f20;
	s32 i;

	func0f14ecd8(&spbc, &spb8, &spb4, &spb0);

	mid1 = (u32) (spb0 + spb8) >> 1;
	mid2 = (u32) (spb4 + spbc) >> 1;

	f26 = (f32) (spb4 - spbc);

	x1 = mid2 - (u32)(f26 * 0.25f);
	x2 = (u32)(f26 * 0.25f) + mid2;

	value1 = func0f14dfc0(head, x1, mid1);
	value2 = func0f14dfc0(head, x2, mid1);

	f22 = f26 * 0.5f;

	for (f20 = 0.0f; f20 < f22; f20 += 1.0f) {
		s32 size = f22 - sqrtf(2.0f * f22 * f20 - f20 * f20);

		s32 y1 = ((s32)f20 + spb8);
		s32 y2 = (spb0 - (s32)f20);

		for (i = 0; i < size; i++) {
			s32 x1 = spbc + i;
			s32 x2 = spb4 - i;

			head->fullsizetex.textureptr[y1 * IMGWIDTH_THUMB + x1 + ((y1 & 1) ? ((x1 & 4) ? -4 : 4) : 0)] = value1;
			head->fullsizetex.textureptr[y2 * IMGWIDTH_THUMB + x1 + ((y2 & 1) ? ((x1 & 4) ? -4 : 4) : 0)] = value1;
			head->fullsizetex.textureptr[y1 * IMGWIDTH_THUMB + x2 + ((y1 & 1) ? ((x2 & 4) ? -4 : 4) : 0)] = value2;
			head->fullsizetex.textureptr[y2 * IMGWIDTH_THUMB + x2 + ((y2 & 1) ? ((x2 & 4) ? -4 : 4) : 0)] = value2;
		}
	}
}

f32 func0f14e4ac(s32 index, s32 *arg1, s32 *arg2)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	s32 i;
	s32 j;
	s32 sp98;
	s32 sp94;
	s32 sp90;
	s32 sp8c;
	s32 range;
	s32 count1;
	s32 count2;
	f32 sum1;
	f32 sum2;
	s32 avg1;
	s32 avg2;
	s32 upper1;
	s32 upper2;
	s32 lower1;
	s32 lower2;
	s32 halfdiff1;
	s32 halfdiff2;
	f32 result;

	func0f14ecd8(&sp98, &sp94, &sp90, &sp8c);

	if (arg1 != NULL) {
		*arg1 = 0;
	}

	count1 = 0;
	count2 = 0;
	sum1 = 0.0f;

	if (arg2 != NULL) {
		*arg2 = 0;
	}

	sum2 = 0.0f;
	range = sp90 - sp98;

	if (range < 32) {
		lower1 = ((sp90 + sp98) >> 1) - 16;

		if (lower1 < 0) {
			lower1 = 0;
		}

		upper1 = lower1 + 32;
	} else {
		lower1 = ((sp90 + sp98) >> 1) - (range >> 1);
		upper1 = lower1 + range;
	}

	range = sp8c - sp94;

	if (range < 32) {
		lower2 = ((sp8c + sp94) >> 1) - 16;

		if (lower2 < 0) {
			lower2 = 0;
		}

		upper2 = lower2 + 32;
	} else {
		lower2 = ((sp8c + sp94) >> 1) - (range >> 1);
		upper2 = lower2 + range;
	}

	halfdiff1 = (upper1 - lower1) >> 1;
	halfdiff2 = (upper2 - lower2) >> 1;

	for (i = 0; i < halfdiff2; i++) {
		s32 start = halfdiff1 - 16;

		if (start < 0) {
			start = 0;
		}

		avg1 = (lower1 + upper1) >> 1;
		avg2 = (lower2 + upper2) >> 1;

		for (j = start; j < halfdiff1; j++) {
			u8 value1 = head->unk01c[(avg2 - i) * IMGWIDTH_THUMB + avg1 - j];
			u8 value2 = head->unk01c[(avg2 + i) * IMGWIDTH_THUMB + avg1 + j];

			if (value1 >= 21 && value1 < 200 && value2 >= 21 && value2 < 200) {
				sum1 += value1;
				sum2 += value2;
				count1++;
				count2++;
			}
		}
	}

	if (count1 != 0 && count2 != 0) {
		sum1 *= 1.0f / count1;
		sum2 *= 1.0f / count2;

		if (arg1 != NULL) {
			*arg1 = (lower1 + upper1) >> 1;
		}

		if (arg2 != NULL) {
			*arg2 = halfdiff1;
		}

		result = (sum1 + sum2) * 0.5f - sum1;

		if (1);

		g_HeadEditors[index].unk090 = result;

		return result;
	}

	return 0.0f;
}

void func0f14e790(u8 *dst)
{
	s32 x;
	s32 y;

	for (y = 0; y < IMGHEIGHT_EDIT; y++) {
		for (x = 0; x < IMGWIDTH_EDIT; x++) {
			dst[y * IMGWIDTH_EDIT + x] = x / 16 * 32;
		}
	}
}

void func0f14e7e0(u8 *dst)
{
	s32 x;
	s32 y;

	for (y = 0; y < IMGHEIGHT_EDIT; y++) {
		for (x = 0; x < IMGWIDTH_EDIT; x++) {
			dst[y * IMGWIDTH_EDIT + x] = random() % 255;
		}
	}
}

void func0f14e884(struct textureconfig *tconfig, s32 numrows, s32 arg2, u64 arg3)
{
	s32 sp5c;
	s32 numbytes;
	s32 bitsperpixel;
	u32 stack;
	s32 pixelsperdword;
	s64 sp40;
	s64 mask;
	s64 *sp34;

	switch (tconfig->depth) {
	case G_IM_SIZ_4b:
		pixelsperdword = 16;
		mask = 0xf;
		sp5c = arg2 >> 1;
		bitsperpixel = 4;
		numbytes = (tconfig->width >> 1) * numrows;
		break;
	case G_IM_SIZ_8b:
		pixelsperdword = 8;
		mask = 0xff;
		sp5c = arg2;
		bitsperpixel = 8;
		numbytes = tconfig->width * numrows;
		break;
	case G_IM_SIZ_16b:
		pixelsperdword = 4;
		mask = 0xffff;
		sp5c = arg2 * 2;
		bitsperpixel = 16;
		numbytes = tconfig->width * 2 * numrows;
		break;
	case G_IM_SIZ_32b:
		pixelsperdword = 2;
		mask = 0xffffffff;
		sp5c = arg2 * 4;
		bitsperpixel = 32;
		numbytes = tconfig->width * 4 * numrows;
		break;
	}

	sp40 = ((arg2 % pixelsperdword) * bitsperpixel);
	sp40 = (IMGWIDTH_THUMB - sp40 - bitsperpixel) & (IMGWIDTH_THUMB - 1);

	if (numrows & 1) {
		sp40 = (sp40 + IMGWIDTH_THUMB / 2) & (IMGWIDTH_THUMB - 1);
	}

	sp34 = (s64 *)(tconfig->textureptr + ((sp5c >> 3) + (numbytes >> 3)) * 8);
	*sp34 = (*sp34 & ~(mask << sp40)) + (arg3 << sp40);
}

Gfx *phead_draw_fullsize_texture(Gfx *gdl, s32 index, s32 x1, s32 y1, s32 x2, s32 y2)
{
	f32 pos[2];
	struct perfecthead *head;
	u32 stack[2];

	pos[0] = x1;
	pos[1] = y1;

	head = phead_find(index);

	gdl = phead_draw_texture(gdl, &head->fullsizetex, pos, (x2 - x1) * (1.0f / 64.0f), (y2 - y1) * (1.0f / 64.0f));

	return gdl;
}

Gfx *phead_draw_thumbnail_texture(Gfx *gdl, s32 index, s32 x1, s32 y1, s32 x2, s32 y2)
{
	f32 pos[2];
	struct perfecthead *head;
	u32 stack[2];

	pos[0] = x1;
	pos[1] = y1;

	head = phead_find(index);

	gdl = phead_draw_texture(gdl, &head->thumbnailtex, pos, (x2 - x1) * (1.0f / 16.0f), (y2 - y1) * (1.0f / 16.0f));

	return gdl;
}

void func0f14ec2c(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
	struct perfecthead *head1 = phead_find(HEADID_EDITOR);
	struct perfecthead *head2 = phead_find(HEADID_SPECIAL2);

	if (head1) {
		head1->unk3c0 = arg0;
		head1->unk3c8 = arg1;
		head1->unk3c4 = arg2;
		head1->unk3cc = arg3;
		head1->unk3ec = 0;
		head1->unk3f0 = 0;
	}

	if (head2) {
		head2->unk3c0 = arg0;
		head2->unk3c8 = arg1;
		head2->unk3c4 = arg2;
		head2->unk3cc = arg3;
		head2->unk3ec = 0;
		head2->unk3f0 = 0;
	}

	func0f14def0(HEADID_EDITOR, 4159, "camdraw.c");
}

const char var7f1b6d50[] = "Cam_SetSquashZ : %u, %u, %f\n";

void func0f14ecd8(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3)
{
	struct perfecthead *head = phead_find(HEADID_SPECIAL2);

	*arg0 = head->unk3c0;
	*arg1 = head->unk3c8;
	*arg2 = head->unk3c4;
	*arg3 = head->unk3cc;
}

void func0f14ed38(void)
{
	func0f14ec2c(10, 3, 54, 61);
}

u32 func0f14ed64(void)
{
	f32 foo[7];

	phead_get_unk3d0(foo);

	return (u32)(foo[6] * 100) - 25;
}

void func0f14ee18(u32 arg0)
{
	f32 foo[7];

	arg0 += 25;

	phead_get_unk3d0(foo);

	foo[6] = arg0 * 0.01f;

	if (foo[6] > 1.9f) {
		foo[6] = 1.9f;
	}

	if (foo[6] < 0.1f) {
		foo[6] = 0.1f;
	}

	func0f14eeb0(foo);
}

// @bug? Nothing is done with tmp
void func0f14eeb0(f32 arg0[7])
{
	struct perfecthead *head1 = phead_find(HEADID_EDITOR);
	struct perfecthead *head2 = phead_find(HEADID_SPECIAL2);
	s32 i;

	for (i = 0; i < ARRAYCOUNT(head1->unk3d0); i++) {
		f32 tmp = arg0[i];

		if (tmp > 1.9f) {
			tmp = 1.9f;
		}

		if (tmp < 0.1f) {
			tmp = 0.1f;
		}

		if (head1) {
			head1->unk3d0[i] = arg0[i];
		}

		if (head2) {
			head2->unk3d0[i] = arg0[i];
		}
	}

	func0f14def0(HEADID_EDITOR, 4240, "camdraw.c");
}

void phead_get_unk3d0(f32 dst[7])
{
	struct perfecthead *head;
	s32 i;

	for (i = 0; i < ARRAYCOUNT(head->unk3d0); i++) {
		head = phead_find(HEADID_SPECIAL2);

		dst[i] = head->unk3d0[i];
	}
}

void func0f14efa8(void)
{
	f32 array[] = {1, 1, 1, 1, 1, 1, 1};
	func0f14eeb0(array);
}

s32 editor_get_num_valid_images(s32 index)
{
	if (index == -1) {
		index = g_HeadEditorData->editorindex;
	}

	return g_HeadEditors[index].numvalidimages;
}

void editor_set_unk074(s32 index, s32 value)
{
	g_HeadEditors[index].unk074 = value;
}

s32 editor_get_unk074(s32 index)
{
	return g_HeadEditors[index].unk074;
}

Gfx *func0f14f07c(Gfx *gdl, s32 imagenum, s32 x1, s32 y1, s32 x2, s32 y2)
{
	struct textureconfig *tconfig = &g_HeadEditorData->unk484[imagenum];
	f32 pos[2];
	u32 stack;

	pos[0] = x1;
	pos[1] = y1;

	if (camdraw_current_editor()->validimages[imagenum] != 0xff) {
		if (camdraw_current_editor()->unk0dc[imagenum] == 0) {
			gdl = phead_draw_texture(gdl, g_HeadEditorData->unk488, pos,
					(x2 - x1) * (1.0f / 64.0f),
					(y2 - y1) * (1.0f / 64.0f));
		} else {
			gdl = phead_draw_texture(gdl, tconfig, pos,
					(x2 - x1) * (1.0f / 64.0f),
					(y2 - y1) * (1.0f / 64.0f));
		}
	}

	return gdl;
}

/**
 * Calculate the bounding box of the src coordinates and store it in dst.
 *
 * src is x, y, z, unused, unused, unused (repeat len times).
 * bbox is xmin, ymin, zmin, xmax, ymax, zmax.
 */
void camdraw_calc_bbox(s16 *src, s32 len, s32 bbox[6])
{
	s32 i;

	if (len > 0) {
		bbox[0] = bbox[3] = src[0];
		bbox[1] = bbox[4] = src[1];
		bbox[2] = bbox[5] = src[2];

		for (i = 1; i < len; i++) {
			if (src[i * 6] > bbox[3]) {
				bbox[3] = src[i * 6];
			} else if (src[i * 6] < bbox[0]) {
				bbox[0] = src[i * 6];
			}

			if (src[i * 6 + 1] > bbox[4]) {
				bbox[4] = src[i * 6 + 1];
			} else if (src[i * 6 + 1] < bbox[1]) {
				bbox[1] = src[i * 6 + 1];
			}

			if (src[i * 6 + 2] > bbox[5]) {
				bbox[5] = src[i * 6 + 2];
			} else if (src[i * 6 + 2] < bbox[2]) {
				bbox[2] = src[i * 6 + 2];
			}
		}
	}
}

s32 camdraw_copy_vertices(struct modeldef *modeldef, Vtx **dst, u32 *len)
{
	struct modelnode *node1 = model_get_part(modeldef, MODELPART_HEAD_0190);
	struct modelnode *node2 = model_get_part(modeldef, MODELPART_HEAD_0191);
	struct modelnode *node3 = model_get_part(modeldef, MODELPART_HEAD_0192);

	s32 totalverts = 0;

	if (len != NULL) {
		*len = 0;
	}

	if (node1 && node2 && node3) {
		struct modelrodata_dl *node1rodata = &node1->rodata->dl;
		struct modelrodata_dl *node2rodata = &node2->rodata->dl;
		struct modelrodata_dl *node3rodata = &node3->rodata->dl;

		s32 node1numverts = node1rodata->numvertices;
		s32 node2numverts = node2rodata->numvertices;
		s32 node3numverts = node3rodata->numvertices;

		s32 size;

		totalverts = node1numverts + node2numverts + node3numverts;
		size = align16(totalverts * sizeof(Vtx));

		osSyncPrintf("Cam : Alloc for copy of Vtx %d bytes\n", size);

		if (*dst) {
			osSyncPrintf("CAM : Cam_AllocAndCopyAllVtx -> Ptr all-ready allocted - No extra needed\n");
		} else {
			*dst = camdraw_allocate(size, 4429, "camdraw.c");
		}

		memcpy(*dst, node1rodata->vertices, node1numverts * sizeof(Vtx));
		memcpy(*dst + node1numverts, node2rodata->vertices, node2numverts * sizeof(Vtx));
		memcpy(*dst + node1numverts + node2numverts, node3rodata->vertices, node3numverts * sizeof(Vtx));

		if (len != NULL) {
			*len = size;
		}
	}

	return totalverts;
}

const char var7f1b6dfc[] = "Cam_RebuildHead : Slot=%d\n";
const char var7f1b6e18[] = "Cam -> Cam_ColourHeadOnePart - Remapping %s\n";
const char var7f1b6e48[] = "Cam_ColourHead : Face Col = %u, Hair Col = %u\n";
const char var7f1b6e78[] = "FACE";
const char var7f1b6e80[] = "SIDE";
const char var7f1b6e88[] = "HAIR";
const char var7f1b6e90[] = "Cam -> Cam_SquashOnePart - pExtents=%08x, pVcopy=%08x, \n";
const char var7f1b6ecc[] = "Cam -> Cam_SquashOnePart - Head centre at (%d,%d,%d)\n";
const char var7f1b6f04[] = "Cam -> Cam_SquashOnePart - Scale Param 1 = %s%s%.3f\n";
const char var7f1b6f3c[] = "";
const char var7f1b6f40[] = "";
const char var7f1b6f44[] = "Cam -> Cam_SquashOnePart - Scale Param 2 = %s%s%.3f\n";
const char var7f1b6f7c[] = "";
const char var7f1b6f80[] = "";
const char var7f1b6f84[] = "Cam -> Cam_SquashOnePart - Scale Param 3 = %s%s%.3f\n";
const char var7f1b6fbc[] = "";
const char var7f1b6fc0[] = "";
const char var7f1b6fc4[] = "Cam -> Cam_SquashOnePart - Scale Param 4 = %s%s%.3f\n";
const char var7f1b6ffc[] = "";
const char var7f1b7000[] = "";
const char var7f1b7004[] = "Cam -> Cam_SquashOnePart - Scale Param 5 = %s%s%.3f\n";
const char var7f1b703c[] = "";
const char var7f1b7040[] = "";
const char var7f1b7044[] = "Cam -> Cam_SquashOnePart - Scale Param 6 = %s%s%.3f\n";
const char var7f1b707c[] = "";
const char var7f1b7080[] = "";
const char var7f1b7084[] = "Cam -> Cam_SquashOnePart - Scale Param 7 = %s%s%.3f\n";
const char var7f1b70bc[] = "";
const char var7f1b70c0[] = "";
const char var7f1b70c4[] = "Cam_DctInitialise_Read -> %x\n";
const char var7f1b70e4[] = "Cam_DctUnCompressSlot -> %x\n";

void func0f14f444(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
	// empty
}

void func0f14f458(void)
{
	// empty
}

void func0f14f460(void)
{
	// empty
}

void func0f14f468(void)
{
	// empty
}

void func0f14f470(void)
{
	// empty
}

void func0f14f478(void)
{
	// empty
}

void func0f14f480(void)
{
	// empty
}

void func0f14f488(void)
{
	// empty
}

void func0f14f490(void)
{
	// empty
}

void func0f14f498(void)
{
	// empty
}

Gfx *func0f14f4a0(Gfx *gdl)
{
	return gdl;
}

void func0f14f4a8(void)
{
	// empty
}

void func0f14f4b0(u32 arg0)
{
	// empty
}

void func0f14f4b8(struct perfecthead *head)
{
	s32 i;

	head->unk028 = 0;
	head->unk02c = 0;

	for (i = 0; i < IMGNUMPIXELS_THUMB; i++) {
		head->unk01c[i] = 0;
	}
}

void func0f14f4e4(struct perfecthead *head)
{
	s32 i;

	head->unk028 = 0;
	head->unk02c = 0;

	for (i = 0; i < IMGNUMPIXELS_THUMB; i++) {
		head->unk024[i] = 0;
	}
}

void func0f14f510(s32 quality)
{
	s32 i;
	s32 j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			g_HeadEditorData->unk06c[i][j] = (i + 1 + j) * quality + 1;
		}
	}

	g_HeadEditorData->unk010 = 0;
	g_HeadEditorData->unk00c = 0;

	for (j = 0; j < 8; j++) {
		g_HeadEditorData->unk17c[0][j] = 1 / sqrtf(8.0f);
		g_HeadEditorData->unk27c[j][0] = g_HeadEditorData->unk17c[0][j];
	}

	for (i = 1; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			s32 v0 = j * 2 + 1;
			f32 angle = v0 * RAD(180, 3.141592502594f) * i / 16;

			g_HeadEditorData->unk17c[i][j] = sqrtf(0.25f) * cosf(angle);
			g_HeadEditorData->unk27c[j][i] = g_HeadEditorData->unk17c[i][j];
		}
	}
}

void func0f14f700(struct perfecthead *head, u32 arg1, u32 arg2)
{
	u32 bit;

	for (bit = 1 << (arg2 - 1); bit != 0; bit >>= 1) {
		if (bit & arg1) {
			s32 remainder = head->unk02c % 8;
			s32 index = head->unk02c / 8;
			u8 mask = 1 << (7 - remainder);

			head->unk024[index] |= mask;
		}

		head->unk02c++;
	}
}

u32 func0f14f76c(struct perfecthead *head, u32 arg1)
{
	u32 bit;
	u32 bits;

	for (bit = 1 << (arg1 - 1), bits = 0; bit != 0; bit >>= 1) {
		u32 remainder = head->unk02c % 8;
		u32 index = head->unk02c / 8;
		u8 mask = 1 << (7 - remainder);

		if (head->unk020[index] & mask) {
			bits |= bit;
		}

		head->unk02c++;
	}

	return bits;
}

s32 phead0f14f7d4(struct perfecthead *head)
{
	s32 sp24;
	s32 v0;

	if (g_HeadEditorData->unk00c > 0) {
		g_HeadEditorData->unk00c--;
		return 0;
	}

	sp24 = func0f14f76c(head, 2);

	if (sp24 == 0) {
		g_HeadEditorData->unk00c = func0f14f76c(head, 4);
		return 0;
	}

	if (sp24 == 1) {
		sp24 = func0f14f76c(head, 1) + 1;
	} else {
		sp24 = func0f14f76c(head, 2) + sp24 * 4 - 5;
	}

	v0 = func0f14f76c(head, sp24);

	if ((1 << (sp24 - 1)) & v0) {
		return v0;
	}

	return (v0 - (1 << sp24)) + 1;
}

void phead0f14f8cc(struct perfecthead *head, s32 arg1[8][8])
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var7f1b60a0); i++) {
		s32 v0 = phead0f14f7d4(head);

		s32 upper = var7f1b60a0[i][0];
		s32 lower = var7f1b60a0[i][1];

		arg1[upper][lower] = g_HeadEditorData->unk06c[upper][lower] * v0;
	}
}

void func0f14f974(struct perfecthead *head, s32 arg1)
{
	s32 absarg1;
	s32 sp28;
	s32 sp24;

	if (arg1 == 0) {
		g_HeadEditorData->unk010++;
		return;
	}

	if (g_HeadEditorData->unk010 != 0) {
		while (g_HeadEditorData->unk010 > 0) {
			func0f14f700(head, 0, 2);

			if (g_HeadEditorData->unk010 < 17) {
				func0f14f700(head, g_HeadEditorData->unk010 - 1, 4);
				g_HeadEditorData->unk010 = 0;
			} else {
				func0f14f700(head, 15, 4);
				g_HeadEditorData->unk010 -= 16;
			}
		}
	}

	absarg1 = ABS(arg1);
	sp28 = 1;
	sp24 = 1;

	while (sp28 < absarg1) {
		sp28 = sp28 * 2 + 1;
		sp24++;
	}

	if (sp24 < 3) {
		func0f14f700(head, sp24 + 1, 3);
	} else {
		func0f14f700(head, sp24 + 5, 4);
	}

	if (arg1 > 0) {
		func0f14f700(head, arg1, sp24);
	} else {
		func0f14f700(head, arg1 + sp28, sp24);
	}
}

void func0f14faf8(struct perfecthead *head, s32 arg1[8][8])
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var7f1b60a0); i++) {
		u32 upper = var7f1b60a0[i][0];
		u32 lower = var7f1b60a0[i][1];
		f32 f0 = (f32) arg1[upper][lower] / (f32) g_HeadEditorData->unk06c[upper][lower];
		s32 a1;

		if (f0 < 0.0f) {
			a1 = f0 - 0.5f;
		} else {
			a1 = f0 + 0.5f;
		}

		func0f14f974(head, a1);
	}
}

void func0f14fbfc(u8 *arg0[8], s32 arg1[8][8])
{
	f32 sp30[8][8];
	s32 i;
	s32 j;
	s32 k;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			sp30[i][j] = 0.0f;

			for (k = 0; k < 8; k++) {
				sp30[i][j] += (arg0[i][k] - 128) * g_HeadEditorData->unk27c[k][j];
			}
		}
	}

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			f32 f0 = 0.0f;

			for (k = 0; k < 8; k++) {
				f0 += g_HeadEditorData->unk17c[i][k] * sp30[k][j];
			}

			if (f0 < 0.0f) {
				arg1[i][j] = f0 - 0.5f;
			} else {
				arg1[i][j] = f0 + 0.5f;
			}
		}
	}
}

void phead0f14fdb0(s32 arg0[8][8], u8 **arg1)
{
	f32 sp30[8][8];
	s32 i;
	s32 j;
	s32 k;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			sp30[i][j] = 0.0f;

			for (k = 0; k < 8; k++) {
				sp30[i][j] += arg0[i][k] * g_HeadEditorData->unk17c[k][j];
			}
		}
	}

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			f32 f0 = 0.0f;

			for (k = 0; k < 8; k++) {
				f0 += g_HeadEditorData->unk27c[i][k] * sp30[k][j];
			}

			f0 += 128.0f;

			if (f0 > 255.0f) {
				f0 = 255.0f;
			}

			if (f0 < 0.0f) {
				f0 = 0.0f;
			}

			if (f0 < 0.0f) {
				arg1[i][j] = (s8)(f0 - 0.5f);
			} else {
				arg1[i][j] = (s8)(f0 + 0.5f);
			}
		}
	}
}

void editor_make_texture_type5(struct perfecthead *head)
{
	s32 y;
	s32 x;
	s32 i;
	s32 quality;
	s32 sp60[8][8];
	u8 *sp40[8];

	func0f14f4b8(head);
	quality = func0f14f76c(head, 8);
	func0f14f510(quality);

	for (y = 0; y < IMGHEIGHT_THUMB; y += 8) {
		for (x = 0; x < IMGWIDTH_THUMB; x += 8) {
			phead0f14f8cc(head, sp60);

			for (i = 0; i < 8; i++) {
				sp40[i] = &head->unk01c[(y + i) * IMGWIDTH_THUMB + x];
			}

			phead0f14fdb0(sp60, sp40);
		}
	}
}

void phead_compress(struct perfecthead *head, s32 quality)
{
	s32 y;
	s32 x;
	s32 i;
	s32 sp64[8][8];
	u8 *sp44[8];

	func0f14f4e4(head);
	func0f14f510(quality);
	func0f14f700(head, quality, 8);

	for (y = 0; y < IMGHEIGHT_THUMB; y += 8) {
		for (x = 0; x < IMGWIDTH_THUMB; x += 8) {
			for (i = 0; i < 8; i++) {
				sp44[i] = &head->unk01c[(y + i) * IMGHEIGHT_THUMB + x];
			}

			func0f14fbfc(sp44, sp64);
			func0f14faf8(head, sp64);
		}
	}

	func0f14f974(head, 1);

	head->unk034 = head->unk02c / 8;
}

bool camdraw_get_filemgr_preview(s8 device, s32 filenum, u8 *dst)
{
	u8 stack[0x420];
	u8 buffer[128];
	s32 ret;
	s32 i;

	ret = pak_read_body_at_guid(device, filenum, buffer, 128);

	if (ret == 0) {
		for (i = 0; i < sizeof(buffer); i++) {
			dst[i] = buffer[i];
		}

		return true;
	}

	if (ret == 10) {
		s32 i;
		s32 size = 128;

		for (i = 0; i < size; i++) {
			dst[i] = random();
		}

		return true;
	}

	return false;
}

bool phead_load_file(s8 device, s32 fileid, u16 serial, s32 index)
{
	s32 i;
	s32 ret;
	struct camerafile file;
	u32 stack;

	struct perfecthead *selectedhead = phead_find(index == -1 ? HEADID_EDITOR : index);
	struct perfecthead *editinghead = phead_find(HEADID_EDITOR);

	osSyncPrintf("Cam_LoadFromPakIntoSlot -> Pak=%d, fileGuid=%u, pakGuid=%u, Slot=%d, pS=%x, pE=%x\n",
			device, fileid, serial, index, selectedhead, editinghead);

	ret = pak_read_body_at_guid(device, fileid, (u8 *)&file, 0);

	if (ret == 0) {
		selectedhead->fileguid.fileid = fileid;
		selectedhead->fileguid.deviceserial = serial;

		if (editinghead != selectedhead) {
			selectedhead->unk01c = editinghead->unk01c;
		}

		selectedhead->autodeartefact = (s32)file.unk8e_00;
		selectedhead->unk3f4_02 = (s32)file.unk8e_01;
		selectedhead->unk3a4 = file.unk8e_02;
		selectedhead->unk3bc = file.unk82;
		selectedhead->unk3b8 = file.unk84;
		selectedhead->colournum = file.unk8c;
		selectedhead->stylenum = file.unk8d;
		selectedhead->unk3c0 = file.unk86;
		selectedhead->unk3c4 = file.unk87;
		selectedhead->unk3c8 = file.unk88;
		selectedhead->unk3cc = file.unk89;
		selectedhead->unk3ec = file.unk8a;
		selectedhead->unk3f0 = file.unk8b;
		selectedhead->unk3f4_03 = true;
		selectedhead->active = true;

		for (i = 0; i < ARRAYCOUNT(selectedhead->unk3d0); i++) {
			selectedhead->unk3d0[i] = file.unk90[i] / 1000.0f;
		}

		for (i = 0; i < IMGNUMPIXELS_SAVE; i++) {
			selectedhead->unk020[i] = file.unk9e[i];
		}

		if (editinghead != selectedhead) {
			camdraw_copy(editinghead, selectedhead, 6494, "camdraw.c");
		}

		phead_set_unk3f4_04(false);
		editor_set_unk100(EDITOR100_5);
		editor_make_textures();

		for (i = 0; i < 128; i++) {
			editinghead->thumbnailtex.textureptr[i] = file.unk00[i];
		}

		if (editinghead != selectedhead) {
			camdraw_copy(selectedhead, editinghead, 6509, "camdraw.c");
		}

		return true;
	}

	g_FilemgrLastPakError = ret;

	return 0;
}

s32 phead_save_file(s8 device, s32 fileid, u16 serial)
{
	s32 stack;
	s32 maxquality = 12;
	struct camerafile file;
	struct perfecthead *head = phead_find(HEADID_EDITOR);
	s32 ret;
	s32 writtenfileid;
	u8 sp44[IMGNUMPIXELS_THUMB];
	s32 i;

	if (!head->unk3f4_03) {
		head->quality = 1;
		head->unk024 = sp44;

		osSyncPrintf("Cam -> Compressing Editor Slot\n");

		while (true) {
			osSyncPrintf("Cam -> Trying image compression at quality %u\n", head->quality);

			phead_compress(head, head->quality);

			file.unk80 = head->unk02c / 8;

			if ((u32) file.unk80 >= IMGNUMPIXELS_SAVE) {
				osSyncPrintf("Cam -> Failed - Too big - This=%u, Max=%d\n", head->quality, maxquality);

				head->quality++;

				if (head->quality < maxquality) {
					osSyncPrintf("Cam -> Trying lower quality setting\n");
				} else {
					osSyncPrintf("Cam -> Save Failed - Cant get it small enough - oo-er\n");
					return -1;
				}
			} else {
				osSyncPrintf("Cam -> Sucess at quality %u - Size=%u, Max=%d\n");
				break;
			}
		}

		for (i = 0; i < (u32) file.unk80; i++) {
			head->unk020[i] = head->unk024[i];
		}

		for (i = file.unk80; i < IMGNUMPIXELS_SAVE; i++) {
			head->unk020[i] = 0;
		}

		head->unk3f4_03 = true;
	}

	file.unk8e_00 = head->autodeartefact;
	file.unk8e_01 = head->unk3f4_02;
	file.unk8e_02 = head->unk3a4;

	file.unk82 = head->unk3bc;
	file.unk84 = head->unk3b8;
	file.unk8c = head->colournum;
	file.unk8d = head->stylenum;
	file.unk86 = head->unk3c0;
	file.unk87 = head->unk3c4;
	file.unk88 = head->unk3c8;
	file.unk89 = head->unk3cc;
	file.unk8a = head->unk3ec;
	file.unk8b = head->unk3f0;

	for (i = 0; i != ARRAYCOUNT(file.unk90); i++) {
		file.unk90[i] = head->unk3d0[i] * 1000.0f;
	}

	for (i = 0; i < ARRAYCOUNT(file.unk00); i++) {
		file.unk00[i] = head->thumbnailtex.textureptr[i];
	}

	for (i = 0; i < ARRAYCOUNT(file.unk9e); i++) {
		file.unk9e[i] = head->unk020[i];
	}

	var80075bd0[3] = true;

	ret = pak_save_at_guid(device, fileid, PAKFILETYPE_CAMERA, (u8 *)&file, &writtenfileid, NULL);

	if (ret != 0) {
		osSyncPrintf("\nCam_SaveEditSlotToParamPakItem -> Save failed\n");
		osSyncPrintf("Camera Save Error Result: %d\n", ret);
	}

	if (ret == 0) {
		s32 i;
		for (i = 0; i < 18; i++) {
			struct perfecthead *iterhead = phead_find(i);

			if (iterhead->fileguid.fileid == head->fileguid.fileid
					&& iterhead->fileguid.deviceserial == head->fileguid.deviceserial) {
				iterhead->fileguid.fileid = writtenfileid;
				iterhead->fileguid.deviceserial = serial;

				if (i >= 12) {
					g_Vars.modifiedfiles |= MODFILE_GAME;
				}
			}
		}

		head->fileguid.fileid = writtenfileid;
		head->fileguid.deviceserial = serial;

		osSyncPrintf("Magic Guid set to %d\n", writtenfileid);
		return 0;
	}

	g_FilemgrLastPakError = ret;

	return -1;
}

void phead_get_guid(s32 index, struct fileguid *guid)
{
	struct perfecthead *head = phead_find(index);

	guid->fileid = head->fileguid.fileid;
	guid->deviceserial = head->fileguid.deviceserial;
}

void phead_set_file_id(s32 fileid)
{
	struct perfecthead *head = phead_find(HEADID_EDITOR);

	head->fileguid.deviceserial = 0;
	head->fileguid.fileid = fileid;
}
