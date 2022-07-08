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

struct var800a45a0 *var800a45a0;
u32 var800a45a4;
struct texturething var800a45a8;
u32 var800a45b8;
u32 var800a45bc;

const char var7f1b6050[] = "Init";
const char var7f1b6058[] = "Start Header Read";
const char var7f1b606c[] = "Header Read Done";
const char var7f1b6080[] = "Null";
const char var7f1b6088[] = "Exit 1";
const char var7f1b6090[] = "Exit 2";
const char var7f1b6098[] = "Exit 3";

const u32 var7f1b60a0[][2] = {
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

const u32 var7f1b62a0[] = {0x00000000};
const u32 var7f1b62a4[] = {0xffffffff};
const u32 var7f1b62a8[] = {0xdc9785ff};
const u32 var7f1b62ac[] = {0xdc917bff};
const u32 var7f1b62b0[] = {0xdd8d71ff};
const u32 var7f1b62b4[] = {0xdd8367ff};
const u32 var7f1b62b8[] = {0xdf795dff};
const u32 var7f1b62bc[] = {0xdf7953ff};
const u32 var7f1b62c0[] = {0x00000000};
const u32 var7f1b62c4[] = {0xffffffff};
const u32 var7f1b62c8[] = {0xa67b6dff};
const u32 var7f1b62cc[] = {0xa16152ff};
const u32 var7f1b62d0[] = {0x8c6741ff};
const u32 var7f1b62d4[] = {0x81544cff};
const u32 var7f1b62d8[] = {0x6a4031ff};
const u32 var7f1b62dc[] = {0x4f433cff};
const u32 var7f1b62e0[] = {0x00000000};
const u32 var7f1b62e4[] = {0xffffffff};
const u32 var7f1b62e8[] = {0xccb38dff};
const u32 var7f1b62ec[] = {0xddc07cff};
const u32 var7f1b62f0[] = {0xe6a667ff};
const u32 var7f1b62f4[] = {0xd1ab50ff};
const u32 var7f1b62f8[] = {0xc69f6dff};
const u32 var7f1b62fc[] = {0xb27e5bff};
const u32 var7f1b6300[] = {0x00000000};
const u32 var7f1b6304[] = {0xffffffff};
const u32 var7f1b6308[] = {0x5f3a25ff};
const u32 var7f1b630c[] = {0x553a20ff};
const u32 var7f1b6310[] = {0x4b351cff};
const u32 var7f1b6314[] = {0x412d19ff};
const u32 var7f1b6318[] = {0x41260fff};
const u32 var7f1b631c[] = {0x371e04ff};
const u32 var7f1b6320[] = {0x00000000};
const u32 var7f1b6324[] = {0xffffffff};
const u32 var7f1b6328[] = {0xe9d679ff};
const u32 var7f1b632c[] = {0x654f40ff};
const u32 var7f1b6330[] = {0xebb279ff};
const u32 var7f1b6334[] = {0x846b51ff};
const u32 var7f1b6338[] = {0xebc579ff};
const u32 var7f1b633c[] = {0xab8d6fff};
const u32 var7f1b6340[] = {0x00000000};
const u32 var7f1b6344[] = {0xffffffff};
const u32 var7f1b6348[] = {0x26374dff};
const u32 var7f1b634c[] = {0x18253eff};
const u32 var7f1b6350[] = {0x171d20ff};
const u32 var7f1b6354[] = {0x060e16ff};
const u32 var7f1b6358[] = {0x00001cff};
const u32 var7f1b635c[] = {0x000001ff};
const u32 var7f1b6360[] = {0x00000000};
const u32 var7f1b6364[] = {0xffffffff};
const u32 var7f1b6368[] = {0x972f1aff};
const u32 var7f1b636c[] = {0x822817ff};
const u32 var7f1b6370[] = {0x6e1e12ff};
const u32 var7f1b6374[] = {0x5a140dff};
const u32 var7f1b6378[] = {0x460a08ff};
const u32 var7f1b637c[] = {0x200001ff};
const u32 var7f1b6380[] = {0x00000000};
const u32 var7f1b6384[] = {0xffffffff};
const u32 var7f1b6388[] = {0x79b2ebff};
const u32 var7f1b638c[] = {0x007fffff};
const u32 var7f1b6390[] = {0x1f5fdfff};
const u32 var7f1b6394[] = {0x0043caff};
const u32 var7f1b6398[] = {0x00147eff};
const u32 var7f1b639c[] = {0x0c1857ff};

const char var7f1b63a0[] = "RWI : Cam Alloc : Guid=%d -> Total = %u (%d at %s)\n";

u32 var8007f8c0 = (u32)&var7f1b6050;
u32 var8007f8c4 = (u32)&var7f1b6058;
u32 var8007f8c8 = (u32)&var7f1b606c;
u32 var8007f8cc = (u32)&var7f1b6080;
u32 var8007f8d0 = (u32)&var7f1b6088;
u32 var8007f8d4 = (u32)&var7f1b6090;
u32 var8007f8d8 = (u32)&var7f1b6098;
struct var8007f8dc *var8007f8dc = NULL;
struct var8007f8e0 *var8007f8e0 = NULL;
u32 var8007f8e4 = 0x00000000;
u32 var8007f8e8 = 0x00000008;
u32 var8007f8ec = 0x0000005a;
u32 var8007f8f0 = 0x00000005;
u32 var8007f8f4 = 0x000000c8;
u32 var8007f8f8 = 0x00000000;
u32 var8007f8fc = 0x00000001;
u32 var8007f900 = 0x00000078;

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

u32 var8007f9d0 = 0x00000000;

/**
 * Fill the texture buffer with a linear gradient: black (left) to white (right).
 */
void func0f149c90(struct textureconfig *tconfig)
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

void *func0f149d58(u32 size, u32 line, char *file)
{
	s32 i;
	void *allocation;

	static u32 var8007f9d4 = 0;

	size = align16(size);

	bgGarbageCollectRooms(size, 1);

	var8007f9d0 += size;
	allocation = memaAlloc(size);
	var8007f9d4++;

	for (i = 0; i < var800a45a0->unk37c; i++) {
		if (var800a45a0->unk380[i] == NULL) {
			// @bug? Is this meant to be writing to [i]?
			// Otherwise it's appending to the array without increasing unk37c.
			var800a45a0->unk380[var800a45a0->unk37c] = allocation;
			var800a45a0->unk3f8[var800a45a0->unk37c] = size;

			return allocation;
		}
	}

	var800a45a0->unk380[var800a45a0->unk37c] = allocation;
	var800a45a0->unk3f8[var800a45a0->unk37c] = size;
	var800a45a0->unk37c++;

	return allocation;
}

void func0f149e58(u8 *arg0, u32 size)
{
	s32 i;

	var8007f9d0 -= size;

	for (i = 0; i < var800a45a0->unk37c; i++) {
		if (arg0 == NULL || arg0 == var800a45a0->unk380[i]) {
			memaFree(var800a45a0->unk380[i], var800a45a0->unk3f8[i]);
			var800a45a0->unk380[i] = 0;
		}
	}

	if (arg0 == NULL) {
		var800a45a0->unk37c = 0;
	}
}

void func0f149f10(void)
{
	// empty
}

void func0f149f18(void)
{
	struct var8007f8e0 *thing;
	s32 i;

	func0f14b394(func0f14a06c(-1));

	thing = func0f14a06c(-1);
	thing->unk3f4_00 = false;

	if (var800a45a0->unk470) {
		for (i = 0; i < 0x4000; i++) {
			var800a45a0->unk470[i] = random() % 255;
		}
	}
}

void func0f149fc8(s32 index)
{
	func0f14c50c(func0f14a06c(index), func0f14a06c(-1), 1040, "camdraw.c");
}

const char var7f1b63e0[] = "Cam -> Dumping head vertex colour information\n";
const char var7f1b6410[] = "Cam -> Face Col - Pal=%d, Entry=%d, Col=%08x\n";
const char var7f1b6440[] = "Cam -> Hair Col - Pal=%d, Entry=%d, Col=%08x\n";
const char var7f1b6470[] = "Cam_Tick (%d Total Slots)";
const char var7f1b648c[] = "Current Camera Slot = %d\n";
const char var7f1b64a8[] = "Slot %d -> Active = %d";

void func0f14a00c(bool arg0)
{
	struct var8007f8e0 *thing;

	thing = func0f14a06c(-1);
	thing->unk3f4_04 = arg0;

	thing = func0f14a06c(-2);
	thing->unk3f4_04 = arg0;
}

struct var8007f8e0 *func0f14a06c(s32 index)
{
	if (index == -1) {
		return &var8007f8e0[var800a45a0->unk16c];
	}

	if (index == -4) {
		return &var8007f8e0[var800a45a0->unk174];
	}

	if (index == -5) {
		return &var8007f8e0[var800a45a0->unk178];
	}

	if (index == -2) {
		return &var8007f8e0[var800a45a0->unk014[var800a45a0->unk004]];
	}

	if (index == -3) {
		return &var8007f8e0[var800a45a0->unk170];
	}

	return &var8007f8e0[var800a45a0->unk014[index]];
}

void func0f14a16c(s32 arg0)
{
	struct var8007f8dc *thing = func0f14a20c();
	thing->unk100 = arg0;
}

bool func0f14a194(void)
{
	return var8007f8dc[var800a45a0->unk000].unk0d4_04 & 0xff;
}

/**
 * 0 returns "Style 1"
 * 1 returns "Style 2"
 * 2 returns "Style 3"
 * 3 returns "Style 4"
 */
char *phGetStyleName(s32 stylenum)
{
	return langGet(L_MISC_429 + stylenum);
}

/**
 * 0 returns "Blonde"
 * 1 returns "Black"
 * 2 returns "Auburn"
 * 3 returns "Blue Rinse"
 */
char *phGetColourName(s32 colournum)
{
	return langGet(L_MISC_433 + colournum);
}

struct var8007f8dc *func0f14a20c(void)
{
	return &var8007f8dc[func0f14a5a4()];
}

void func0f14a240(void)
{
	s32 i;
	s32 j;

	var800a45a0->unk48c = 0;
	var800a45a0->unk484 = 0;
	var800a45a0->unk470 = 0;
	var800a45a0->unk474 = 0;
	var800a45a0->unk478 = 0;
	var800a45a0->unk47c = 0;
	var800a45a0->unk480 = 0;
	var800a45a0->unk37c = 0;
	var800a45a0->unk000 = 0;
	var800a45a0->unk004 = -1;
	var800a45a0->unk008 = 1;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			// empty
		}
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			// empty
		}
	}
}

bool func0f14a2fc(s32 index, u32 line, char *file)
{
	struct var8007f8e0 *thing = func0f14a06c(index);
	return thing->unk3f4_00;
}

void pheadInit(void)
{
	s32 i;

	if (IS8MB()) {
		u32 size1 = align16(sizeof(struct var8007f8dc) * 4);
		u32 size2 = align16(sizeof(struct var800a45a0));

		var8007f8dc = mempAlloc(size1, MEMPOOL_PERMANENT);
		var800a45a0 = mempAlloc(size2, MEMPOOL_PERMANENT);

		func0f14a240();

		for (i = 0; i < 4; i++) {
			func0f14ad58(i);
		}
	}
}

void pheadInit2(void)
{
	// empty
}

void pheadReset(void)
{
	s32 i;

	var800a45a0->unk37c = 0;

	for (i = 0; i < 4; i++) {
		var8007f8dc[i].unk0d4_03 = false;
	}
}

void func0f14a404(void)
{
	func0f149e58(NULL, 0);
}

void func0f14a428(void)
{
	s32 i;

	for (i = 0; i < 22; i++) {
		func0f14a2fc(i, 1296, "camdraw.c");
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
		func0f149c90(&var800a45a0->unk484[i]);
	}

	for (i = 0; i < 4; i++) {
		var8007f8dc[i].unk0f4 = 0;
		pak0f11d478(i);
	}
}

void func0f14a52c(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		var8007f8dc[i].unk0d4_03 = true;
	}
}

void func0f14a560(void)
{
	s32 i;

	for (i = 0; i < 4; i++) {
		var8007f8dc[i].unk0d4_03 = false;
	}
}

void func0f14a594(s32 arg0)
{
	var800a45a0->unk000 = arg0;
}

s32 func0f14a5a4(void)
{
	return var800a45a0->unk000;
}

void func0f14a5b4(s32 index)
{
	var800a45a0->unk004 = index;

	func0f14b394(func0f14a06c(index));
}

void func0f14a5e4(void)
{
	func0f14def0(-1, 1407, "camdraw.c");
}

void func0f14a610(void)
{
	func0f14def0(-1, 1415, "camdraw.c");
	func0f14c50c(func0f14a06c(-2), func0f14a06c(-1), 1416, "camdraw.c");
}

s32 func0f14a668(void)
{
	return var800a45a0->unk004;
}

void func0f14a678(void)
{
	func0f14c50c(func0f14a06c(-2), func0f14a06c(-1), 1433, "camdraw.c");
}

void func0f14a6bc(void)
{
	func0f14c50c(func0f14a06c(-4), func0f14a06c(-1), 1441, "camdraw.c");
	func0f14c50c(func0f14a06c(-1), func0f14a06c(-3), 1442, "camdraw.c");
	func0f14c50c(func0f14a06c(-3), func0f14a06c(-4), 1443, "camdraw.c");
}

const char var7f1b6584[] = "Cam_CopyEditorToUndo\n";

void func0f14a760(void)
{
	func0f14c50c(func0f14a06c(-3), func0f14a06c(-1), 1452, "camdraw.c");
}

const char var7f1b65a8[] = "Cam_CopyUndoToEditor\n";

void func0f14a7a4(void)
{
	func0f14c50c(func0f14a06c(-1), func0f14a06c(-3), 1461, "camdraw.c");
}

void func0f14a7e8(s32 index)
{
	func0f14c50c(func0f14a06c(-1), func0f14a06c(index), 1470, "camdraw.c");
}

void func0f14a830(void)
{
	struct var8007f8dc *thing = func0f14a20c();

	if (thing->unk0d4_00) {
		thing->unk0d4_00 = false;
	} else {
		thing->unk0d4_00 = true;
	}

	if (thing->unk0d4_00) {
		func0f14def0(-1, 1484, "camdraw.c");
	}
}

struct textureconfig *func0f14a89c(s32 index)
{
	struct var8007f8e0 *thing = func0f14a06c(index);

	return &thing->unk004;
}

bool func0f14a8c0(void)
{
	struct var8007f8dc *thing = func0f14a20c();

	return thing->unk0d4_00;
}

bool func0f14a8e8(void)
{
	struct var8007f8dc *thing = func0f14a20c();

	return thing->unk0f8 == 0 ? false : true;
}

void func0f14a91c(s32 arg0)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->unk3bc = arg0;

	func0f14def0(-1, 1518, "camdraw.c");
}

const char var7f1b65f0[] = "Cam -> Setting current hair colour to %s\n";
const char var7f1b661c[] = "Cam -> Setting current face colour to %s\n";

void func0f14a95c(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->unk3bc = 0x80;
}

s32 func0f14a984(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	return thing->unk3bc;
}

void func0f14a9a8(s32 arg0)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->unk3a4 = arg0;
}

void func0f14a9d4(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->unk3a4 = 0;
}

s32 func0f14a9f8(s32 index)
{
	struct var8007f8e0 *thing = func0f14a06c(index);

	return thing->unk3a4;
}

void func0f14aa1c(s32 arg0)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->unk3b8 = arg0;
}

void func0f14aa48(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->unk3b8 = 6;
}

s32 func0f14aa70(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	return thing->unk3b8;
}

void func0f14aa94(s32 colournum)
{
	struct var8007f8e0 *thing;

	phGetColourName(colournum);

	thing = func0f14a06c(-1);
	thing->colournum = colournum;
}

void func0f14aac4(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->colournum = 0;
}

s32 func0f14aae8(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	return thing->colournum;
}

void func0f14ab0c(s32 stylenum)
{
	struct var8007f8e0 *thing;

	phGetStyleName(stylenum);

	thing = func0f14a06c(-1);
	thing->stylenum = stylenum;
}

void func0f14ab3c(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);
	thing->stylenum = 0;
}

s32 func0f14ab60(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);
	return thing->stylenum;
}

void func0f14ab84(s32 arg0)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);
	thing->unk3b4 = arg0;
}

s32 func0f14abb0(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);
	return thing->unk3b4;
}

void func0f14abd4(s32 index, s32 arg1)
{
	var8007f8dc[index].unk06c = arg1;
}

s32 func0f14abf4(s32 index)
{
	return var8007f8dc[index].unk06c;
}

bool func0f14ac14(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);
	return thing->unk3f4_02;
}

void func0f14ac3c(bool arg0)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);
	thing->unk3f4_02 = arg0;

	func0f14def0(-1, 1681, "camdraw.c");
}

const char var7f1b6654[] = "Cam_SetAutoDeArtefact -> State = %d\n";

bool func0f14ac90(void)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);
	return thing->unk3f4_01;
}

void func0f14acb8(bool arg0)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	if (arg0) {
		thing->unk3f4_01 = true;
	} else {
		thing->unk3f4_01 = false;
	}

	func0f14def0(-1, 1699, "camdraw.c");
}

u16 func0f14ad14(s32 device)
{
	return var8007f8dc[device].unk05c & 0xffff;
}

s32 func0f14ad38(s32 device)
{
	return var8007f8dc[device].unk060;
}

const char var7f1b6688[] = "Cam_ClearCameraLoadBuffer -> Camera=%d\n";
const char var7f1b66b0[] = "Cam_StartTemp : Need %u bytes for temp cam images buffer\n";

u32 var8007f9d8 = 0x3f800000;
u32 var8007f9dc = 0x3f800000;
u32 var8007f9e0 = 0x3f800000;
u32 var8007f9e4 = 0x3f800000;
u32 var8007f9e8 = 0x3f800000;
u32 var8007f9ec = 0x3f800000;
u32 var8007f9f0 = 0x3f800000;
u32 var8007f9f4 = 0x3f800000;
u32 var8007f9f8 = 0x3f800000;

GLOBAL_ASM(
glabel func0f14ad58
.late_rodata
glabel var7f1b72e4
.word 0x3dcccccd
glabel var7f1b72e8
.word 0x3e4ccccd
.text
/*  f14ad58:	3c0f8008 */ 	lui	$t7,%hi(var8007f8dc)
/*  f14ad5c:	8deff8dc */ 	lw	$t7,%lo(var8007f8dc)($t7)
/*  f14ad60:	00047180 */ 	sll	$t6,$a0,0x6
/*  f14ad64:	3c013f80 */ 	lui	$at,0x3f80
/*  f14ad68:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f14ad6c:	44810000 */ 	mtc1	$at,$f0
/*  f14ad70:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f14ad74:	3c0142dc */ 	lui	$at,0x42dc
/*  f14ad78:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f14ad7c:	44812000 */ 	mtc1	$at,$f4
/*  f14ad80:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f14ad84:	3c017f1b */ 	lui	$at,%hi(var7f1b72e4)
/*  f14ad88:	e4400004 */ 	swc1	$f0,0x4($v0)
/*  f14ad8c:	e4400008 */ 	swc1	$f0,0x8($v0)
/*  f14ad90:	e4440050 */ 	swc1	$f4,0x50($v0)
/*  f14ad94:	c42672e4 */ 	lwc1	$f6,%lo(var7f1b72e4)($at)
/*  f14ad98:	3c017f1b */ 	lui	$at,%hi(var7f1b72e8)
/*  f14ad9c:	44801000 */ 	mtc1	$zero,$f2
/*  f14ada0:	e446000c */ 	swc1	$f6,0xc($v0)
/*  f14ada4:	c42872e8 */ 	lwc1	$f8,%lo(var7f1b72e8)($at)
/*  f14ada8:	3c0141f0 */ 	lui	$at,0x41f0
/*  f14adac:	44815000 */ 	mtc1	$at,$f10
/*  f14adb0:	2403ffff */ 	addiu	$v1,$zero,-1
/*  f14adb4:	2418001e */ 	addiu	$t8,$zero,0x1e
/*  f14adb8:	ac430058 */ 	sw	$v1,0x58($v0)
/*  f14adbc:	ac430068 */ 	sw	$v1,0x68($v0)
/*  f14adc0:	ac40006c */ 	sw	$zero,0x6c($v0)
/*  f14adc4:	ac400070 */ 	sw	$zero,0x70($v0)
/*  f14adc8:	ac400074 */ 	sw	$zero,0x74($v0)
/*  f14adcc:	ac400084 */ 	sw	$zero,0x84($v0)
/*  f14add0:	ac580054 */ 	sw	$t8,0x54($v0)
/*  f14add4:	3c198008 */ 	lui	$t9,%hi(var8007f904+0x3c)
/*  f14add8:	e4400024 */ 	swc1	$f0,0x24($v0)
/*  f14addc:	e4400028 */ 	swc1	$f0,0x28($v0)
/*  f14ade0:	e440003c */ 	swc1	$f0,0x3c($v0)
/*  f14ade4:	e4420014 */ 	swc1	$f2,0x14($v0)
/*  f14ade8:	e4420018 */ 	swc1	$f2,0x18($v0)
/*  f14adec:	e442001c */ 	swc1	$f2,0x1c($v0)
/*  f14adf0:	e4420020 */ 	swc1	$f2,0x20($v0)
/*  f14adf4:	e442002c */ 	swc1	$f2,0x2c($v0)
/*  f14adf8:	e4420030 */ 	swc1	$f2,0x30($v0)
/*  f14adfc:	e4420034 */ 	swc1	$f2,0x34($v0)
/*  f14ae00:	e4420038 */ 	swc1	$f2,0x38($v0)
/*  f14ae04:	e4420040 */ 	swc1	$f2,0x40($v0)
/*  f14ae08:	e4480010 */ 	swc1	$f8,0x10($v0)
/*  f14ae0c:	e44a0044 */ 	swc1	$f10,0x44($v0)
/*  f14ae10:	9739f940 */ 	lhu	$t9,%lo(var8007f904+0x3c)($t9)
/*  f14ae14:	904b00d4 */ 	lbu	$t3,0xd4($v0)
/*  f14ae18:	24080006 */ 	addiu	$t0,$zero,0x6
/*  f14ae1c:	ac480060 */ 	sw	$t0,0x60($v0)
/*  f14ae20:	316dff7f */ 	andi	$t5,$t3,0xff7f
/*  f14ae24:	31af00bf */ 	andi	$t7,$t5,0xbf
/*  f14ae28:	2409000e */ 	addiu	$t1,$zero,0xe
/*  f14ae2c:	3c013f80 */ 	lui	$at,0x3f80
/*  f14ae30:	a04d00d4 */ 	sb	$t5,0xd4($v0)
/*  f14ae34:	31e800df */ 	andi	$t0,$t7,0xdf
/*  f14ae38:	44818000 */ 	mtc1	$at,$f16
/*  f14ae3c:	ac49008c */ 	sw	$t1,0x8c($v0)
/*  f14ae40:	a04f00d4 */ 	sb	$t7,0xd4($v0)
/*  f14ae44:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f14ae48:	24030003 */ 	addiu	$v1,$zero,0x3
/*  f14ae4c:	a04800d4 */ 	sb	$t0,0xd4($v0)
/*  f14ae50:	35090008 */ 	ori	$t1,$t0,0x8
/*  f14ae54:	ac4a0088 */ 	sw	$t2,0x88($v0)
/*  f14ae58:	ac400090 */ 	sw	$zero,0x90($v0)
/*  f14ae5c:	ac400064 */ 	sw	$zero,0x64($v0)
/*  f14ae60:	ac4000f4 */ 	sw	$zero,0xf4($v0)
/*  f14ae64:	ac400094 */ 	sw	$zero,0x94($v0)
/*  f14ae68:	a04900d4 */ 	sb	$t1,0xd4($v0)
/*  f14ae6c:	ac4000f8 */ 	sw	$zero,0xf8($v0)
/*  f14ae70:	ac4300fc */ 	sw	$v1,0xfc($v0)
/*  f14ae74:	ac430100 */ 	sw	$v1,0x100($v0)
/*  f14ae78:	ac4000e0 */ 	sw	$zero,0xe0($v0)
/*  f14ae7c:	ac4000e4 */ 	sw	$zero,0xe4($v0)
/*  f14ae80:	ac4000e8 */ 	sw	$zero,0xe8($v0)
/*  f14ae84:	ac4000ec */ 	sw	$zero,0xec($v0)
/*  f14ae88:	ac4000f0 */ 	sw	$zero,0xf0($v0)
/*  f14ae8c:	ac400078 */ 	sw	$zero,0x78($v0)
/*  f14ae90:	ac40007c */ 	sw	$zero,0x7c($v0)
/*  f14ae94:	ac59005c */ 	sw	$t9,0x5c($v0)
/*  f14ae98:	03e00008 */ 	jr	$ra
/*  f14ae9c:	e4500048 */ 	swc1	$f16,0x48($v0)
);

// Mismatch: need to fiddle with the order of these
//void func0f14ad58(s32 index)
//{
//	struct var8007f8dc *thing = &var8007f8dc[index];
//
//	thing->unk000 = 0;
//	thing->unk004 = 1.0f;
//	thing->unk008 = 1.0f;
//	thing->unk050 = 110.0f;
//	thing->unk00c = 0.1f;
//	thing->unk010 = 0.2f;
//	thing->unk054 = 30;
//	thing->unk058 = -1;
//	thing->unk068 = -1;
//	thing->unk06c = 0;
//	thing->unk070 = 0;
//	thing->unk074 = 0;
//	thing->unk084 = 0;
//	thing->unk024 = 1.0f;
//	thing->unk028 = 1.0f;
//	thing->unk03c = 1.0f;
//	thing->unk014 = 0.0f;
//	thing->unk018 = 0.0f;
//	thing->unk01c = 0.0f;
//	thing->unk020 = 0.0f;
//	thing->unk02c = 0.0f;
//	thing->unk030 = 0.0f;
//	thing->unk034 = 0.0f;
//	thing->unk038 = 0.0f;
//	thing->unk040 = 0.0f;
//	thing->unk044 = 30.0f;
//	thing->unk060 = 6;
//	thing->unk08c = 14;
//	thing->unk088 = 1;
//	thing->unk090 = 0;
//	thing->unk064 = 0;
//	thing->unk0f4 = 0;
//	thing->unk094 = 0;
//	thing->unk0f8 = 0;
//	thing->unk0fc = 3;
//	thing->unk100 = 3;
//	thing->unk0e0 = 0;
//	thing->unk0e4 = 0;
//	thing->unk0e8 = 0;
//	thing->unk0ec = 0;
//	thing->unk0f0 = 0;
//	thing->unk078 = 0;
//	thing->unk07c = 0;
//	thing->unk05c = var8007f940;
//	thing->unk048 = 1.0f;
//	thing->unk0d4_00 = false;
//	thing->unk0d4_01 = false;
//	thing->unk0d4_02 = false;
//	thing->unk0d4_04 = true;
//}

bool func0f14aea0(s32 device)
{
	return var8007f8dc[device].unk0d4_03;
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

const char var7f1b66ec[] = "camdraw.c";
const char var7f1b66f8[] = "camdraw.c";
const char var7f1b6704[] = "camdraw.c";
const char var7f1b6710[] = "camdraw.c";
const char var7f1b671c[] = "camdraw.c";
const char var7f1b6728[] = "Camera -> Cam_Start for Camera %d\n";
const char var7f1b674c[] = "Camera -> Cam_Stop\n";
const char var7f1b6760[] = "Camera -> Cam_Finish - Done\n";
const char var7f1b6780[] = "Camera ->Created a new slot - Id=%d\n";
const char var7f1b67a8[] = "Camera -> CD_DeleteSlot - Dumping slot %d\n";

GLOBAL_ASM(
glabel func0f14aee0
/*  f14aee0:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f14aee4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f14aee8:	3c15800a */ 	lui	$s5,%hi(var800a45a0)
/*  f14aeec:	26b545a0 */ 	addiu	$s5,$s5,%lo(var800a45a0)
/*  f14aef0:	8ea20000 */ 	lw	$v0,0x0($s5)
/*  f14aef4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f14aef8:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f14aefc:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f14af00:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f14af04:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f14af08:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f14af0c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f14af10:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f14af14:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f14af18:	8c4e0484 */ 	lw	$t6,0x484($v0)
/*  f14af1c:	27b0006c */ 	addiu	$s0,$sp,0x6c
/*  f14af20:	24120021 */ 	addiu	$s2,$zero,0x21
/*  f14af24:	15c00030 */ 	bnez	$t6,.L0f14afe8
/*  f14af28:	00000000 */ 	nop
/*  f14af2c:	0fc531f7 */ 	jal	func0f14c7dc
/*  f14af30:	02002025 */ 	or	$a0,$s0,$zero
/*  f14af34:	0fc53205 */ 	jal	func0f14c814
/*  f14af38:	02002025 */ 	or	$a0,$s0,$zero
/*  f14af3c:	0fc5db70 */ 	jal	align32
/*  f14af40:	00402025 */ 	or	$a0,$v0,$zero
/*  f14af44:	0040a025 */ 	or	$s4,$v0,$zero
/*  f14af48:	0fc5db69 */ 	jal	align16
/*  f14af4c:	2404018c */ 	addiu	$a0,$zero,0x18c
/*  f14af50:	00142140 */ 	sll	$a0,$s4,0x5
/*  f14af54:	00408025 */ 	or	$s0,$v0,$zero
/*  f14af58:	0fc5db69 */ 	jal	align16
/*  f14af5c:	00942021 */ 	addu	$a0,$a0,$s4
/*  f14af60:	02022021 */ 	addu	$a0,$s0,$v0
/*  f14af64:	0c0048f2 */ 	jal	mempAlloc
/*  f14af68:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f14af6c:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f14af70:	2451018c */ 	addiu	$s1,$v0,0x18c
/*  f14af74:	00009825 */ 	or	$s3,$zero,$zero
/*  f14af78:	00008025 */ 	or	$s0,$zero,$zero
/*  f14af7c:	ade20484 */ 	sw	$v0,0x484($t7)
.L0f14af80:
/*  f14af80:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f14af84:	8f190484 */ 	lw	$t9,0x484($t8)
/*  f14af88:	0fc531f7 */ 	jal	func0f14c7dc
/*  f14af8c:	03302021 */ 	addu	$a0,$t9,$s0
/*  f14af90:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f14af94:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f14af98:	8d090484 */ 	lw	$t1,0x484($t0)
/*  f14af9c:	01305021 */ 	addu	$t2,$t1,$s0
/*  f14afa0:	ad510000 */ 	sw	$s1,0x0($t2)
/*  f14afa4:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f14afa8:	1672fff5 */ 	bne	$s3,$s2,.L0f14af80
/*  f14afac:	02348821 */ 	addu	$s1,$s1,$s4
/*  f14afb0:	00009825 */ 	or	$s3,$zero,$zero
/*  f14afb4:	00008025 */ 	or	$s0,$zero,$zero
.L0f14afb8:
/*  f14afb8:	8eab0000 */ 	lw	$t3,0x0($s5)
/*  f14afbc:	8d6c0484 */ 	lw	$t4,0x484($t3)
/*  f14afc0:	0fc52724 */ 	jal	func0f149c90
/*  f14afc4:	01902021 */ 	addu	$a0,$t4,$s0
/*  f14afc8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f14afcc:	1672fffa */ 	bne	$s3,$s2,.L0f14afb8
/*  f14afd0:	2610000c */ 	addiu	$s0,$s0,0xc
/*  f14afd4:	8ea20000 */ 	lw	$v0,0x0($s5)
/*  f14afd8:	8c4d0484 */ 	lw	$t5,0x484($v0)
/*  f14afdc:	25ae0180 */ 	addiu	$t6,$t5,0x180
/*  f14afe0:	ac4e0488 */ 	sw	$t6,0x488($v0)
/*  f14afe4:	8ea20000 */ 	lw	$v0,0x0($s5)
.L0f14afe8:
/*  f14afe8:	3c067f1b */ 	lui	$a2,%hi(var7f1b66ec)
/*  f14afec:	ac40037c */ 	sw	$zero,0x37c($v0)
/*  f14aff0:	24c666ec */ 	addiu	$a2,$a2,%lo(var7f1b66ec)
/*  f14aff4:	24044000 */ 	addiu	$a0,$zero,0x4000
/*  f14aff8:	2405077b */ 	addiu	$a1,$zero,0x77b
/*  f14affc:	0fc52756 */ 	jal	func0f149d58
/*  f14b000:	00009825 */ 	or	$s3,$zero,$zero
/*  f14b004:	8eaf0000 */ 	lw	$t7,0x0($s5)
/*  f14b008:	3c100001 */ 	lui	$s0,0x1
/*  f14b00c:	3c067f1b */ 	lui	$a2,%hi(var7f1b66f8)
/*  f14b010:	24c666f8 */ 	addiu	$a2,$a2,%lo(var7f1b66f8)
/*  f14b014:	02002025 */ 	or	$a0,$s0,$zero
/*  f14b018:	2405077c */ 	addiu	$a1,$zero,0x77c
/*  f14b01c:	0fc52756 */ 	jal	func0f149d58
/*  f14b020:	ade20470 */ 	sw	$v0,0x470($t7)
/*  f14b024:	8eb80000 */ 	lw	$t8,0x0($s5)
/*  f14b028:	3c067f1b */ 	lui	$a2,%hi(var7f1b6704)
/*  f14b02c:	24c66704 */ 	addiu	$a2,$a2,%lo(var7f1b6704)
/*  f14b030:	02002025 */ 	or	$a0,$s0,$zero
/*  f14b034:	2405077d */ 	addiu	$a1,$zero,0x77d
/*  f14b038:	0fc52756 */ 	jal	func0f149d58
/*  f14b03c:	af020474 */ 	sw	$v0,0x474($t8)
/*  f14b040:	8eb90000 */ 	lw	$t9,0x0($s5)
/*  f14b044:	3c067f1b */ 	lui	$a2,%hi(var7f1b6710)
/*  f14b048:	24c66710 */ 	addiu	$a2,$a2,%lo(var7f1b6710)
/*  f14b04c:	24040078 */ 	addiu	$a0,$zero,0x78
/*  f14b050:	2405077e */ 	addiu	$a1,$zero,0x77e
/*  f14b054:	0fc52756 */ 	jal	func0f149d58
/*  f14b058:	af220478 */ 	sw	$v0,0x478($t9)
/*  f14b05c:	8ea80000 */ 	lw	$t0,0x0($s5)
/*  f14b060:	3c067f1b */ 	lui	$a2,%hi(var7f1b671c)
/*  f14b064:	24c6671c */ 	addiu	$a2,$a2,%lo(var7f1b671c)
/*  f14b068:	24041000 */ 	addiu	$a0,$zero,0x1000
/*  f14b06c:	2405077f */ 	addiu	$a1,$zero,0x77f
/*  f14b070:	0fc52756 */ 	jal	func0f149d58
/*  f14b074:	ad02047c */ 	sw	$v0,0x47c($t0)
/*  f14b078:	8ea90000 */ 	lw	$t1,0x0($s5)
/*  f14b07c:	3c168008 */ 	lui	$s6,%hi(var8007f8dc)
/*  f14b080:	26d6f8dc */ 	addiu	$s6,$s6,%lo(var8007f8dc)
/*  f14b084:	0000a025 */ 	or	$s4,$zero,$zero
/*  f14b088:	241e0004 */ 	addiu	$s8,$zero,0x4
/*  f14b08c:	2417ffff */ 	addiu	$s7,$zero,-1
/*  f14b090:	2412001e */ 	addiu	$s2,$zero,0x1e
/*  f14b094:	241000ff */ 	addiu	$s0,$zero,0xff
/*  f14b098:	ad220480 */ 	sw	$v0,0x480($t1)
.L0f14b09c:
/*  f14b09c:	8eab0000 */ 	lw	$t3,0x0($s5)
/*  f14b0a0:	8eca0000 */ 	lw	$t2,0x0($s6)
/*  f14b0a4:	00132600 */ 	sll	$a0,$s3,0x18
/*  f14b0a8:	8d6c047c */ 	lw	$t4,0x47c($t3)
/*  f14b0ac:	028a8821 */ 	addu	$s1,$s4,$t2
/*  f14b0b0:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f14b0b4:	ae2c00dc */ 	sw	$t4,0xdc($s1)
/*  f14b0b8:	8ead0000 */ 	lw	$t5,0x0($s5)
/*  f14b0bc:	01e02025 */ 	or	$a0,$t7,$zero
/*  f14b0c0:	8da50480 */ 	lw	$a1,0x480($t5)
/*  f14b0c4:	ae37007c */ 	sw	$s7,0x7c($s1)
/*  f14b0c8:	ae200078 */ 	sw	$zero,0x78($s1)
/*  f14b0cc:	0fc45c54 */ 	jal	pak0f117150
/*  f14b0d0:	ae2500d8 */ 	sw	$a1,0xd8($s1)
/*  f14b0d4:	00002025 */ 	or	$a0,$zero,$zero
/*  f14b0d8:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f14b0dc:	0fc45c6d */ 	jal	pak0f1171b4
/*  f14b0e0:	00003025 */ 	or	$a2,$zero,$zero
/*  f14b0e4:	0fc52bb4 */ 	jal	func0f14aed0
/*  f14b0e8:	02602025 */ 	or	$a0,$s3,$zero
/*  f14b0ec:	ae200094 */ 	sw	$zero,0x94($s1)
/*  f14b0f0:	00001825 */ 	or	$v1,$zero,$zero
/*  f14b0f4:	02201025 */ 	or	$v0,$s1,$zero
.L0f14b0f8:
/*  f14b0f8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f14b0fc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14b100:	a0500097 */ 	sb	$s0,0x97($v0)
/*  f14b104:	1472fffc */ 	bne	$v1,$s2,.L0f14b0f8
/*  f14b108:	a05000b5 */ 	sb	$s0,0xb5($v0)
/*  f14b10c:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f14b110:	167effe2 */ 	bne	$s3,$s8,.L0f14b09c
/*  f14b114:	26940104 */ 	addiu	$s4,$s4,0x104
/*  f14b118:	0fc52965 */ 	jal	func0f14a594
/*  f14b11c:	00002025 */ 	or	$a0,$zero,$zero
/*  f14b120:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f14b124:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f14b128:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f14b12c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f14b130:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f14b134:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f14b138:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f14b13c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f14b140:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f14b144:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f14b148:	03e00008 */ 	jr	$ra
/*  f14b14c:	27bd0080 */ 	addiu	$sp,$sp,0x80
);

void func0f14b150(void)
{
	var800a45a0->unk48c = 0;

	func0f14b178();
}

void func0f14b178(void)
{
	s32 i;

	func0f149e58(var800a45a0->unk470, 0x4000);
	func0f149e58(var800a45a0->unk474, 0x10000);
	func0f149e58(var800a45a0->unk478, 0x10000);
	func0f149e58(var800a45a0->unk47c, 0x78);
	func0f149e58(var800a45a0->unk480, 0x1000);

	for (i = 0; i < 4; i++) {
		struct var8007f8dc *thing = &var8007f8dc[i];

		thing->unk0d4_03 = false;
		thing->unk0dc = 0;
		thing->unk0d8 = 0;
	}
}

void func0f14b228(struct var8007f8e0 *arg0)
{
	s32 i;

	arg0->unk03c = 0;
	arg0->unk3f4_00 = false;

	for (i = 0; i < ARRAYCOUNT(arg0->unk040); i++) {
		arg0->unk040[i] = 0xff;
	}

	for (i = 0; i < ARRAYCOUNT(arg0->unk2fc); i++) {
		arg0->unk2fc[i] = 0xff;
	}

	for (i = 0; i < ARRAYCOUNT(arg0->unk108); i++) {
		arg0->unk108[i] = 0xff;
	}

	for (i = 0; i < ARRAYCOUNT(arg0->unk3d0); i++) {
		arg0->unk3d0[i] = 1.0f;
	}

	arg0->unk036 = 3;
	arg0->unk3f4_01 = false;
	arg0->unk3f4_02 = true;
	arg0->unk3f4_03 = false;
	arg0->unk028 = 0;
	arg0->unk02c = 0;
	arg0->unk034 = 0;
	arg0->unk030 = 1.0f;
	arg0->unk3f4_04 = false;
	arg0->colournum = 0;
	arg0->stylenum = 0;
	arg0->unk3a4 = 0;
	arg0->unk3a8 = -1;
	arg0->unk3ac = -1;
	arg0->unk3b0 = -1;
	arg0->unk3b4 = 0x10;
	arg0->unk3b8 = 6;
	arg0->unk3bc = 0x80;
	arg0->unk3c0 = 10;
	arg0->unk3c4 = 0x36;
	arg0->unk3c8 = 3;
	arg0->unk3cc = 0x3d;
	arg0->unk3ec = 0;
	arg0->unk3f0 = 0;
	arg0->fileguid.fileid = 0;
	arg0->fileguid.deviceserial = 0;
}

void func0f14b358(void)
{
	// empty
}

void func0f14b360(s32 index)
{
	struct var8007f8e0 *thing = func0f14a06c(index);

	func0f14b228(thing);
	func0f14b394(thing);
}

void func0f14b394(struct var8007f8e0 *arg0)
{
	s32 size;
	s32 i;

	size = align32(func0f14c814(&arg0->unk004));

	for (i = 0; i < size; i++) {
		arg0->unk004.textureptr[i] = random() % 0xff;
	}

	size = align32(func0f14c814(&arg0->unk010));

	for (i = 0; i < size; i++) {
		arg0->unk010.textureptr[i] = random() % 0xff;
	}

	func0f14b228(arg0);
}

bool func0f14b484(s32 index)
{
	struct var8007f8dc *thing = &var8007f8dc[index];

	thing->unk004 = var8007f8e8 * 0.01f;
	thing->unk008 = var8007f8ec * 0.01f;
	thing->unk00c = var8007f8f0 * 0.01f;
	thing->unk010 = var8007f8f4 * 0.01f;
	thing->unk000 = var8007f8fc;
	thing->unk050 = var8007f900;
	thing->unk020 = thing->unk024;
	thing->unk038 = thing->unk03c;
	thing->unk024 = osGetCount() * 0.0000001f;
	thing->unk028 = thing->unk024 - thing->unk020;

	if (thing->unk028 > 15) {
		thing->unk028 = 15;
	}

	thing->unk03c = thing->unk04c - thing->unk050;
	thing->unk01c = thing->unk03c;
	thing->unk018 = thing->unk03c / thing->unk028;
	thing->unk014 += thing->unk03c * thing->unk028;

	if (thing->unk014 > 500) {
		thing->unk014 = 500;
	}

	if (thing->unk014 < -500) {
		thing->unk014 = -500;
	}

	thing->unk034 = thing->unk010 * -1.0f * thing->unk018;
	thing->unk02c = thing->unk008 * thing->unk01c;
	thing->unk030 = thing->unk00c * thing->unk014;
	thing->unk040 = -thing->unk004 * ((thing->unk010 * -1.0f * thing->unk018) + thing->unk008 * thing->unk01c + thing->unk00c * thing->unk014);

	if (thing->unk000) {
		if (ABS(thing->unk03c) > 10.0f) {
			if (ABS(thing->unk040) >= 1.0f) {
				thing->unk054 += (s32)thing->unk040;

				if (thing->unk054 > 80) {
					thing->unk054 = 80;
				}

				if (thing->unk054 < 1) {
					thing->unk054 = 1;
				}

				thing->unk044 += thing->unk040;

				if (thing->unk044 > 80) {
					thing->unk044 = 80;
				}

				if (thing->unk044 < 1) {
					thing->unk044 = 1;
				}

				thing->unk05c = var8007f904[thing->unk054];

				if (thing->unk05c < var8007f904[1]) {
					thing->unk05c = var8007f904[1];
					thing->unk060--;

					if (thing->unk060 < 2) {
						thing->unk060 = 2;
					}
				} else if (thing->unk05c > var8007f904[80]) {
					thing->unk05c = var8007f904[80];
					thing->unk060++;

					if (thing->unk060 > 10) {
						thing->unk060 = 10;
					}
				}

				thing->unk014 = 0.0f;
			}
		} else {
			thing->unk014 = 0.0f;
		}
	}

	if (thing->unk04c < 70 || thing->unk04c > 160) {
		return false;
	}

	return true;
}

void func0f14b8ac(s32 index)
{
	struct var8007f8dc *thing = &var8007f8dc[index];

	mainOverrideVariable("kg", &var8007f8e8);
	mainOverrideVariable("Kp", &var8007f8ec);
	mainOverrideVariable("Ki", &var8007f8f0);
	mainOverrideVariable("Kd", &var8007f8f4);
	mainOverrideVariable("tInt", &var8007f8f8);
	mainOverrideVariable("gocal", &var8007f8fc);
	mainOverrideVariable("aim", &var8007f900);

	if (thing->unk0d4_00) {
		func0f14cf6c();
		return;
	}

	func0f14a95c();

	if (pak0f11d3f8(func0f14a5a4())) {
		pak0f11d620(func0f14a5a4());

		if (thing->unk0f8 == 0 && var8007f8dc[var800a45a0->unk000].unk0d4_04 == false) {
			func0f14e790(var800a45a0->unk470);
			func0f14a16c(1);
			func0f14bc04();
			return;
		}

		switch (pakGetUnk008(func0f14a5a4())) {
		case 12:
			func0f14a95c();
			func0f14aa48();
			func0f14e790(var800a45a0->unk470);
			func0f14cf6c();
			pak0f11e3bc(func0f14a5a4());
			func0f14a16c(1);
			func0f14bc04();
			break;
		case 1:
			pak0f11d4dc(func0f14a5a4());
			break;
		case 11:
			pak0f11d9c4(func0f14a5a4(), var800a45a0->unk470, 0, 0);
			func0f14d064(index, var800a45a0->unk470);
			pak0f11d478(func0f14a5a4());

			if (thing->unk0f8 == 0) {
				func0f14a16c(3);
				func0f14bc04();

				if (var8007f8dc[var800a45a0->unk000].unk0d4_04) {
					struct var8007f8e0 *thing2 = func0f14a06c(-1);
					thing2->unk3f4_00 = true;
				}
			} else {
				func0f14a16c(4);
				func0f14bc04();
			}

			if (!func0f14a8e8()) {
				func0f14b484(var800a45a0->unk000);
			}
			break;
		}
	} else {
		func0f14cf6c();
		func0f14e7e0(var800a45a0->unk470);
		func0f14a16c(3);
		func0f14bc04();
	}
}

const char var7f1b67f8[] = "CAM : Cam_MakeTextures\n";

void func0f14bc04(void)
{
	struct var8007f8e0 *thing1 = func0f14a06c(-1);
	struct var8007f8dc *thing2 = func0f14a20c();

	thing1->unk3f4_02 = true;

	switch (thing2->unk100) {
	case 0:
		break;
	case 1:
		thing1->unk3f4_02 = false;
		func0f14d714(var800a45a0->unk470, thing1->unk01c);
		break;
	case 4:
		func0f14d714(var800a45a0->unk470, thing1->unk01c);
		break;
	case 2:
		func0f14d2c8(var800a45a0->unk470, thing1->unk01c);
		break;
	case 3:
		func0f14d4f0(var800a45a0->unk470, thing1->unk01c);
		break;
	case 5:
		func0f14ff94(thing1);
		break;
	}

	func0f14def0(-1, 2433, "camdraw.c");

	if (thing2->unk100 != 4) {
		phead0f14dac0(var800a45a0->unk470, &thing1->unk010);
	}

	thing1->unk3f4_03 = false;
}

const char var7f1b681c[] = "pD->ReadMode = %s";
const char var7f1b6830[] = "Camera -> Getting Header Info\n";
const char var7f1b6850[] = "Camera -> Item=%d, pD->CamHeader[i]=%d\n";
const char var7f1b6878[] = "Camera -> Found %d Valid images\n";
const char var7f1b689c[] = "Camera -> Item=%d, Valid=%s, Bank=%d\n";
const char var7f1b68c4[] = "YES";
const char var7f1b68c8[] = "NO";
const char var7f1b68cc[] = "CD_TransferCurrentCacheToEditorAndExit : Player=%d, pD->CamRdImg=%d\n";
const char var7f1b6914[] = "Camera -> CD_CycleHandleRead - Need to load up the camera header\n";
const char var7f1b6958[] = "Camera -> CD_CycleHandleRead - Image %d needs loading for editor coppying on menu exit\n";
const char var7f1b69b0[] = "Camera -> CD_CycleHandleRead - Error ekCamReadModeExit2 in Null cycle\n";
const char var7f1b69f8[] = "CAMERA : COPY SLOT (%d of %s): Slot %d(%s) -> Slot %d(%s)\n";
const char var7f1b6a34[] = "ACTIVE";
const char var7f1b6a3c[] = "NULL";
const char var7f1b6a44[] = "ACTIVE";
const char var7f1b6a4c[] = "NULL";
const char var7f1b6a54[] = "RWI : Warning -> Not copying the thumbnail texture\n";
const char var7f1b6a88[] = "CD_DrawTexture : pTex=%x\n";
const char var7f1b6aa4[] = "Cam -> WARNING - Not done intensity table recalc :- No samples within threshold\n";
const char var7f1b6af8[] = "Camera -> Call to reset auto calibrate\n";
const char var7f1b6b20[] = "AC -> ekCamAutoCalStatusReset - pD->tTime = %d, pD->tTimeNxAdd = %d\n";
const char var7f1b6b68[] = "Cam 0 -> Time = %d, Target = %d, tInt = %.2f\n";
const char var7f1b6b98[] = "Cam 0 -> Too Low -> Adding Time\n";
const char var7f1b6bbc[] = "Cam 0 -> Too High -> Subbing Time\n";
const char var7f1b6be0[] = "Cam -> ekCamAutoCalStatusSettingTime - New time = %d\n";
const char var7f1b6c18[] = "%s%sAC -> Gain = %d, Target = %.2f, tInt = %.2f\n";
const char var7f1b6c4c[] = "";
const char var7f1b6c50[] = "";
const char var7f1b6c54[] = "Auto Calibrate is removing the menu message\n";
const char var7f1b6c84[] = "Auto Calibrate is shutting down\n";
const char var7f1b6ca8[] = "Cam -> Cam_BalanceSlot %d -> tZroShift = %d\n";
const char var7f1b6cd8[] = "Cam_BuildFaceTexture (slot=%d): %d of %s\n";

void func0f14bd34(s32 index)
{
	struct var8007f8dc *thing = &var8007f8dc[index];

	if (thing->unk080 != -1) {
		pak0f1171b4(func0f14a5a4(), 3, 0);
		pak0f11d540(func0f14a5a4(), thing->unk0b6[thing->unk080]);
	}
}

void func0f14bdbc(s32 index)
{
	struct var8007f8dc *thing = &var8007f8dc[index];
	struct var8007f8e0 *thing2;
	s32 i;
	s32 value;

	for (i = 0; i < 30; i++) {
		thing->unk0dc[i] = 0;
	}

	thing->unk094 = 0;

	for (i = 0; i < 30; i++) {
		thing->unk098[i] = 0xff;
		thing->unk0b6[i] = 0xff;
	}

	value = var8007f8dc[index].unk0f4;

	if (value == 4 || value == 5) {
		thing->unk0f4 = 6;
		g_MpPlayerNum = index;
		menuSetBanner(-1, false);

		thing2 = func0f14a06c(-1);
		thing2->unk3f4_00 = false;

		g_MpPlayerNum = index;

		menuPopDialog();

		g_MpPlayerNum = 0;
	} else {
		pak0f11e3bc(func0f14a5a4());

		thing->unk0f4 = 0;
	}
}

void func0f14bec8(s32 index)
{
	struct var8007f8dc *thing = &var8007f8dc[index];
	struct var8007f8e0 *thing2 = func0f14a06c(-1);
	struct textureconfig *thing3;
	s32 i;

	if (thing->unk0f4 == 4 && thing->unk080 == thing->unk074) {
		thing->unk0f4 = 5;
	}

	switch (thing->unk0f4) {
	case 1:
		pak0f11d9c4(index, NULL, thing->unk098, 0);
		thing->unk0f4 = 2;

		for (i = 0; i < 30; i++) {
			if (thing->unk098[i] != 0xff) {
				thing->unk098[i] += 2;
			}
		}

		for (i = 0, thing->unk094 = 0; i < 30; i++) {
			if (thing->unk098[i] != 0xff) {
				thing->unk0b6[thing->unk094] = thing->unk098[i];
				thing->unk094++;
			}
		}

		for (i = thing->unk094; i < 30; i++) {
			thing->unk0b6[i] = 0xff;
		}

		if (thing->unk094);

		for (i = 0; i < 30; i++);

		pak0f1171b4(func0f14a5a4(), 3, 0);
		pak0f11d478(func0f14a5a4());
		break;
	case 3:
		pak0f11d9c4(func0f14a5a4(), var800a45a0->unk470, 0, 1);
		thing3 = &var800a45a0->unk484[thing->unk080];
		func0f14a16c(2);
		func0f14bc04();
		func0f14c75c(thing3, &thing2->unk004);
		thing->unk0dc[thing->unk080] = 1;
		pak0f11d478(func0f14a5a4());
		break;
	case 4:
		pak0f11d478(func0f14a5a4());
		break;
	case 5:
		pak0f11d9c4(func0f14a5a4(), var800a45a0->unk470, 0, 1);
		func0f14a16c(3);
		func0f14bc04();
		pak0f11d478(func0f14a5a4());
		g_MpPlayerNum = index;
		menuSetBanner(-1, false);
		func0f14a678();
		thing2->unk3f4_00 = true;
		g_MpPlayerNum = index;
		stub0f102230();
		g_MpPlayerNum = 0;
		thing->unk0f4 = 6;
		break;
	case 2:
	case 6:
		break;
	}
}

void func0f14c1cc(s32 index)
{
	struct var8007f8dc *thing = &var8007f8dc[index];
	s32 count = func0f14f008(index);
	s32 max = count / 2 + 1;
	s32 i;

	switch (thing->unk0f4) {
	case 0:
		pak0f1171b4(func0f14a5a4(), 0, 0);
		pak0f11d5b0(func0f14a5a4());
		thing->unk0f4 = 1;
		break;
	case 2:
		thing->unk0f4 = 3;
		break;
	case 4:
		if (thing->unk074 != thing->unk080) {
			thing->unk0dc[thing->unk074] = 0;
			thing->unk080 = thing->unk074;
			thing->unk0f4 = 5;

			func0f14bd34(index);
		}
		break;
	case 3:
		thing->unk080 = -1;

		for (i = 0; i < max; i++) {
			s32 a = (thing->unk074 + i) % count;
			s32 b = thing->unk074 - i;

			if (b < 0) {
				b += count;
			}

			if (thing->unk0dc[a] == 0 && thing->unk0b6[a] != 0xff) {
				thing->unk080 = a;
				break;
			}

			if (thing->unk0dc[b] == 0 && thing->unk0b6[b] != 0xff) {
				thing->unk080 = b;
				break;
			}
		}
		func0f14bd34(index);
		break;
	case 1:
	case 5:
		break;
	}
}

void func0f14c3a4(s32 index)
{
	struct var8007f8dc *thing = &var8007f8dc[index];
	s32 i;

	if (pak0f11d3f8(func0f14a5a4()) == 0) {
		for (i = 0; i < 30; i++) {
			thing->unk0dc[i] = 0;
		}

		for (i = 0; i < 30; i++) {
			thing->unk094 = 0;
			thing->unk098[i] = 0xff;
			thing->unk0b6[i] = 0xff;
		}
	} else {
		pak0f11d620(func0f14a5a4());

		switch (pakGetUnk008(func0f14a5a4())) {
		case 1:
			func0f14c1cc(index);
			break;
		case 11:
			func0f14bec8(index);
			break;
		case 12:
			func0f14bdbc(index);
			break;
		}
	}
}

void func0f14c4c0(s32 index)
{
	var8007f8dc[index].unk0f4 = 4;
	g_MpPlayerNum = index;

	menuSetBanner(MENUBANNER_DOWNLOADINGIMAGE, false);
}

GLOBAL_ASM(
glabel func0f14c50c
/*  f14c50c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f14c510:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f14c514:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f14c518:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f14c51c:	3c068008 */ 	lui	$a2,%hi(var8007f8e0)
/*  f14c520:	00808025 */ 	or	$s0,$a0,$zero
/*  f14c524:	00a08825 */ 	or	$s1,$a1,$zero
/*  f14c528:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f14c52c:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f14c530:	8cc6f8e0 */ 	lw	$a2,%lo(var8007f8e0)($a2)
/*  f14c534:	00001025 */ 	or	$v0,$zero,$zero
/*  f14c538:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f14c53c:
/*  f14c53c:	28410016 */ 	slti	$at,$v0,0x16
/*  f14c540:	5420fffe */ 	bnezl	$at,.L0f14c53c
/*  f14c544:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14c548:	8e2203f4 */ 	lw	$v0,0x3f4($s1)
/*  f14c54c:	920c03f4 */ 	lbu	$t4,0x3f4($s0)
/*  f14c550:	02001825 */ 	or	$v1,$s0,$zero
/*  f14c554:	00027fc2 */ 	srl	$t7,$v0,0x1f
/*  f14c558:	000fc9c0 */ 	sll	$t9,$t7,0x7
/*  f14c55c:	318dff7f */ 	andi	$t5,$t4,0xff7f
/*  f14c560:	032d7025 */ 	or	$t6,$t9,$t5
/*  f14c564:	a20e03f4 */ 	sb	$t6,0x3f4($s0)
/*  f14c568:	8e2f03f4 */ 	lw	$t7,0x3f4($s1)
/*  f14c56c:	00001025 */ 	or	$v0,$zero,$zero
/*  f14c570:	02202025 */ 	or	$a0,$s1,$zero
/*  f14c574:	000fc040 */ 	sll	$t8,$t7,0x1
/*  f14c578:	001867c2 */ 	srl	$t4,$t8,0x1f
/*  f14c57c:	000cc980 */ 	sll	$t9,$t4,0x6
/*  f14c580:	332d0040 */ 	andi	$t5,$t9,0x40
/*  f14c584:	31cf00bf */ 	andi	$t7,$t6,0xbf
/*  f14c588:	01afc025 */ 	or	$t8,$t5,$t7
/*  f14c58c:	a21803f4 */ 	sb	$t8,0x3f4($s0)
/*  f14c590:	8e2c03f4 */ 	lw	$t4,0x3f4($s1)
/*  f14c594:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f14c598:	240a003f */ 	addiu	$t2,$zero,0x3f
/*  f14c59c:	000cc880 */ 	sll	$t9,$t4,0x2
/*  f14c5a0:	001977c2 */ 	srl	$t6,$t9,0x1f
/*  f14c5a4:	000e6940 */ 	sll	$t5,$t6,0x5
/*  f14c5a8:	31af0020 */ 	andi	$t7,$t5,0x20
/*  f14c5ac:	330c00df */ 	andi	$t4,$t8,0xdf
/*  f14c5b0:	01ecc825 */ 	or	$t9,$t7,$t4
/*  f14c5b4:	a21903f4 */ 	sb	$t9,0x3f4($s0)
/*  f14c5b8:	8e2e03f4 */ 	lw	$t6,0x3f4($s1)
/*  f14c5bc:	00004025 */ 	or	$t0,$zero,$zero
/*  f14c5c0:	24070fc0 */ 	addiu	$a3,$zero,0xfc0
/*  f14c5c4:	000e68c0 */ 	sll	$t5,$t6,0x3
/*  f14c5c8:	000dc7c2 */ 	srl	$t8,$t5,0x1f
/*  f14c5cc:	00187900 */ 	sll	$t7,$t8,0x4
/*  f14c5d0:	31ec0010 */ 	andi	$t4,$t7,0x10
/*  f14c5d4:	332e00ef */ 	andi	$t6,$t9,0xef
/*  f14c5d8:	018e6825 */ 	or	$t5,$t4,$t6
/*  f14c5dc:	a20d03f4 */ 	sb	$t5,0x3f4($s0)
/*  f14c5e0:	8e38039c */ 	lw	$t8,0x39c($s1)
/*  f14c5e4:	240bffc0 */ 	addiu	$t3,$zero,-64
/*  f14c5e8:	24090040 */ 	addiu	$t1,$zero,0x40
/*  f14c5ec:	ae18039c */ 	sw	$t8,0x39c($s0)
/*  f14c5f0:	8e2f03a0 */ 	lw	$t7,0x3a0($s1)
/*  f14c5f4:	ae0f03a0 */ 	sw	$t7,0x3a0($s0)
/*  f14c5f8:	8e3903a4 */ 	lw	$t9,0x3a4($s1)
/*  f14c5fc:	ae1903a4 */ 	sw	$t9,0x3a4($s0)
/*  f14c600:	8e2c03b4 */ 	lw	$t4,0x3b4($s1)
/*  f14c604:	ae0c03b4 */ 	sw	$t4,0x3b4($s0)
/*  f14c608:	8e2e03b8 */ 	lw	$t6,0x3b8($s1)
/*  f14c60c:	ae0e03b8 */ 	sw	$t6,0x3b8($s0)
/*  f14c610:	8e2d03bc */ 	lw	$t5,0x3bc($s1)
/*  f14c614:	ae0d03bc */ 	sw	$t5,0x3bc($s0)
/*  f14c618:	8e3803c0 */ 	lw	$t8,0x3c0($s1)
/*  f14c61c:	ae1803c0 */ 	sw	$t8,0x3c0($s0)
/*  f14c620:	8e2f03c4 */ 	lw	$t7,0x3c4($s1)
/*  f14c624:	ae0f03c4 */ 	sw	$t7,0x3c4($s0)
/*  f14c628:	8e3903c8 */ 	lw	$t9,0x3c8($s1)
/*  f14c62c:	ae1903c8 */ 	sw	$t9,0x3c8($s0)
/*  f14c630:	8e2c03cc */ 	lw	$t4,0x3cc($s1)
/*  f14c634:	ae0c03cc */ 	sw	$t4,0x3cc($s0)
/*  f14c638:	8e2e03ec */ 	lw	$t6,0x3ec($s1)
/*  f14c63c:	ae0e03ec */ 	sw	$t6,0x3ec($s0)
/*  f14c640:	8e2d03f0 */ 	lw	$t5,0x3f0($s1)
/*  f14c644:	ae0d03f0 */ 	sw	$t5,0x3f0($s0)
/*  f14c648:	8e3803f8 */ 	lw	$t8,0x3f8($s1)
/*  f14c64c:	ae1803f8 */ 	sw	$t8,0x3f8($s0)
/*  f14c650:	962f03fc */ 	lhu	$t7,0x3fc($s1)
/*  f14c654:	a60f03fc */ 	sh	$t7,0x3fc($s0)
.L0f14c658:
/*  f14c658:	c48403d0 */ 	lwc1	$f4,0x3d0($a0)
/*  f14c65c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14c660:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f14c664:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f14c668:	1445fffb */ 	bne	$v0,$a1,.L0f14c658
/*  f14c66c:	e46403cc */ 	swc1	$f4,0x3cc($v1)
/*  f14c670:	8e19001c */ 	lw	$t9,0x1c($s0)
/*  f14c674:	1320001a */ 	beqz	$t9,.L0f14c6e0
.L0f14c678:
/*  f14c678:	00001025 */ 	or	$v0,$zero,$zero
/*  f14c67c:	31460001 */ 	andi	$a2,$t2,0x1
.L0f14c680:
/*  f14c680:	10c00008 */ 	beqz	$a2,.L0f14c6a4
/*  f14c684:	8e05001c */ 	lw	$a1,0x1c($s0)
/*  f14c688:	304c0004 */ 	andi	$t4,$v0,0x4
/*  f14c68c:	11800003 */ 	beqz	$t4,.L0f14c69c
/*  f14c690:	24030004 */ 	addiu	$v1,$zero,0x4
/*  f14c694:	10000004 */ 	b	.L0f14c6a8
/*  f14c698:	2404fffc */ 	addiu	$a0,$zero,-4
.L0f14c69c:
/*  f14c69c:	10000002 */ 	b	.L0f14c6a8
/*  f14c6a0:	00602025 */ 	or	$a0,$v1,$zero
.L0f14c6a4:
/*  f14c6a4:	00002025 */ 	or	$a0,$zero,$zero
.L0f14c6a8:
/*  f14c6a8:	8e2e0004 */ 	lw	$t6,0x4($s1)
/*  f14c6ac:	00a8c821 */ 	addu	$t9,$a1,$t0
/*  f14c6b0:	03226021 */ 	addu	$t4,$t9,$v0
/*  f14c6b4:	008e6821 */ 	addu	$t5,$a0,$t6
/*  f14c6b8:	01a7c021 */ 	addu	$t8,$t5,$a3
/*  f14c6bc:	03027821 */ 	addu	$t7,$t8,$v0
/*  f14c6c0:	91e30000 */ 	lbu	$v1,0x0($t7)
/*  f14c6c4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14c6c8:	1449ffed */ 	bne	$v0,$t1,.L0f14c680
/*  f14c6cc:	a1830000 */ 	sb	$v1,0x0($t4)
/*  f14c6d0:	24e7ffc0 */ 	addiu	$a3,$a3,-64
/*  f14c6d4:	254affff */ 	addiu	$t2,$t2,-1
/*  f14c6d8:	1567ffe7 */ 	bne	$t3,$a3,.L0f14c678
/*  f14c6dc:	25080040 */ 	addiu	$t0,$t0,0x40
.L0f14c6e0:
/*  f14c6e0:	26040004 */ 	addiu	$a0,$s0,0x4
/*  f14c6e4:	0fc531d7 */ 	jal	func0f14c75c
/*  f14c6e8:	26250004 */ 	addiu	$a1,$s1,0x4
/*  f14c6ec:	8e0e0010 */ 	lw	$t6,0x10($s0)
/*  f14c6f0:	51c00008 */ 	beqzl	$t6,.L0f14c714
/*  f14c6f4:	8e3803f4 */ 	lw	$t8,0x3f4($s1)
/*  f14c6f8:	8e2d0010 */ 	lw	$t5,0x10($s1)
/*  f14c6fc:	26040010 */ 	addiu	$a0,$s0,0x10
/*  f14c700:	51a00004 */ 	beqzl	$t5,.L0f14c714
/*  f14c704:	8e3803f4 */ 	lw	$t8,0x3f4($s1)
/*  f14c708:	0fc531d7 */ 	jal	func0f14c75c
/*  f14c70c:	26250010 */ 	addiu	$a1,$s1,0x10
/*  f14c710:	8e3803f4 */ 	lw	$t8,0x3f4($s1)
.L0f14c714:
/*  f14c714:	00001025 */ 	or	$v0,$zero,$zero
/*  f14c718:	24030400 */ 	addiu	$v1,$zero,0x400
/*  f14c71c:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f14c720:	0723000a */ 	bgezl	$t9,.L0f14c74c
/*  f14c724:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f14c728:
/*  f14c728:	8e2c0020 */ 	lw	$t4,0x20($s1)
/*  f14c72c:	8e180020 */ 	lw	$t8,0x20($s0)
/*  f14c730:	01827021 */ 	addu	$t6,$t4,$v0
/*  f14c734:	91cd0000 */ 	lbu	$t5,0x0($t6)
/*  f14c738:	03027821 */ 	addu	$t7,$t8,$v0
/*  f14c73c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14c740:	1443fff9 */ 	bne	$v0,$v1,.L0f14c728
/*  f14c744:	a1ed0000 */ 	sb	$t5,0x0($t7)
/*  f14c748:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f14c74c:
/*  f14c74c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f14c750:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f14c754:	03e00008 */ 	jr	$ra
/*  f14c758:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

// Mismatch: Goal loads var8007f8e0 into a2 then does nothing with it.
// The below optimises it out.
//void func0f14c50c(struct var8007f8e0 *dst, struct var8007f8e0 *src, u32 line, char *file)
//{
//	struct var8007f8e0 *thing = var8007f8e0;
//	s32 i;
//	s32 j;
//	s32 row = 0;
//
//	for (i = 0; i < 22; i++);
//
//	dst->unk3f4_00 = src->unk3f4_00;
//	dst->unk3f4_01 = src->unk3f4_01;
//	dst->unk3f4_02 = src->unk3f4_02;
//	dst->unk3f4_03 = src->unk3f4_03;
//	dst->colournum = src->colournum;
//	dst->stylenum = src->stylenum;
//	dst->unk3a4 = src->unk3a4;
//	dst->unk3b4 = src->unk3b4;
//	dst->unk3b8 = src->unk3b8;
//	dst->unk3bc = src->unk3bc;
//	dst->unk3c0 = src->unk3c0;
//	dst->unk3c4 = src->unk3c4;
//	dst->unk3c8 = src->unk3c8;
//	dst->unk3cc = src->unk3cc;
//	dst->unk3ec = src->unk3ec;
//	dst->unk3f0 = src->unk3f0;
//
//	dst->fileguid.fileid = src->fileguid.fileid;
//	dst->fileguid.deviceserial = src->fileguid.deviceserial;
//
//	for (i = 0; i != 7; i++) {
//		dst->unk3d0[i] = src->unk3d0[i];
//	}
//
//	if (dst->unk01c) {
//		s32 i;
//
//		for (i = 63; i != -1; i--) {
//			for (j = 0; j != 64; j++) {
//				s32 fudge = (i & 1) ? ((j & 4) ? -4 : 4) : 0;
//
//				dst->unk01c[row * 64 + j] = src->unk004.textureptr[i * 64 + j + fudge];
//			}
//
//			row++;
//		}
//	}
//
//	func0f14c75c(&dst->unk004, &src->unk004);
//
//	if (dst->unk010.textureptr && src->unk010.textureptr) {
//		func0f14c75c(&dst->unk010, &src->unk010);
//	}
//
//	if (src->unk3f4_04) {
//		for (i = 0; i < 1024; i++) {
//			dst->unk020[i] = src->unk020[i];
//		}
//	}
//}

void func0f14c75c(struct textureconfig *arg0, struct textureconfig *arg1)
{
	s32 i;
	u32 size = align32(func0f14c814(arg0));

	align32(func0f14c814(arg1));

	for (i = 0; i < size; i++) {
		arg0->textureptr[i] = arg1->textureptr[i];
	}
}

void func0f14c7dc(struct textureconfig *tconfig)
{
	tconfig->width = 64;
	tconfig->height = 64;
	tconfig->level = 0;
	tconfig->format = 4;
	tconfig->depth = 1;
	tconfig->s = 0;
	tconfig->t = 1;
	tconfig->unk0b = 1;
}

void func0f14c80c(void)
{
	// empty
}

u32 func0f14c814(struct textureconfig *tconfig)
{
	u32 size = tconfig->width * tconfig->height;

	switch (tconfig->depth) {
	case 0:
		size >>= 1;
		break;
	case 2:
		size *= 2;
		break;
	case 3:
		size *= 4;
		break;
	case 1:
		break;
	}

	return size;
}

Gfx *func0f14c870(Gfx *gdl, struct textureconfig *tconfig, f32 *arg2, f32 arg3, f32 arg4)
{
	u32 x = (arg2[0] + 0.5f) * 4.0f;
	u32 y = (arg2[1] + 0.5f) * 4.0f;

	u32 width = ((arg2[0] - 0.5f) + (arg3 * tconfig->width)) * 4.0f;
	u32 height = ((arg2[1] - 0.5f) + (arg3 * tconfig->height)) * 4.0f;

	u32 stack;
	s32 sp28 = (tconfig->height - 0.5f) * 32.0f;

	gDPPipeSync(gdl++);
	gDPSetTextureFilter(gdl++, G_TF_POINT);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetCombineMode(gdl++, G_CC_MODULATEI, G_CC_MODULATEI);

	texSelect(&gdl, tconfig, 1, 0, 2, 1, &var800a45a8);

	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);

	gSPTextureRectangle(gdl++,
			x * g_ScaleX, y,
			width * g_ScaleX, height,
			G_TX_RENDERTILE, 16, sp28,
			(s32)(1024.0f / arg3) / g_ScaleX,
			(s32)(1024.0f / arg4));

	return gdl;
}

void func0f14cdb8(s32 index, u8 *arg1)
{
	s32 count;
	s32 i;
	s32 j;

	var8007f8dc[index].unk04c = 0;

	count = 0;

	for (i = 0x1000; i < 0x3000; i += 0x80) {
		for (j = 0x20; j < 0x60; j++) {
			count++;
			var8007f8dc[index].unk04c += arg1[i + j];
		}
	}

	if (count > 0) {
		var8007f8dc[index].unk04c /= count;
		return;
	}

	var8007f8dc[index].unk04c = 0;
}

void func0f14ce84(void)
{
	if (pak0f11d3f8(func0f14a5a4())) {
		if (pakGetUnk008(func0f14a5a4()) != 12) {
			var8007f8dc[func0f14a5a4()].unk0f8 = 1;
			var8007f8dc[func0f14a5a4()].unk0d4_00 = false;

			func0f14a95c();
			func0f14aa48();
			func0f14aac4();
			func0f14ab3c();
		} else {
			pak0f11e3bc(func0f14a5a4());
		}
	}
}

void func0f14cf6c(void)
{
	g_MpPlayerNum = 0;

	menuSetBanner(-1, false);

	if (var8007f8dc[func0f14a5a4()].unk0f8) {
		switch (var8007f8dc[func0f14a5a4()].unk0f8) {
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			pak0f1171b4(func0f14a5a4(), 3, 0);
			g_MpPlayerNum = 0;
			menuSetBanner(-1, false);
			break;
		}

		var8007f8dc[func0f14a5a4()].unk0f8 = 0;
	}
}

void func0f14d064(s32 index, u8 *arg1)
{
	struct var8007f8dc *thing = &var8007f8dc[index];
	f32 a;
	f32 b;

	if (thing->unk0f8 == 1) {
		thing->unk05c = 0x4000;
		thing->unk064 = 0x2000;
		thing->unk060 = 6;
		g_MpPlayerNum = index;
		menuSetBanner(MENUBANNER_CALIBRATINGCAMERA, false);
		func0f14a16c(1);
		pak0f1171b4(func0f14a5a4(), 1, 1);
		thing->unk0f8 = 3;
		return;
	}

	if (thing->unk0f8 == 3) {
		func0f14cdb8(index, arg1);
		a = thing->unk04c;

		if (a > 130) {
			b = a - 130;
		} else {
			b = -(a - 130);
		}

		if (b < 10 || thing->unk064 == 64) {
			thing->unk0f8 = 2;
		} else {
			if (a < 130) {
				thing->unk05c += thing->unk064;
			} else {
				thing->unk05c -= thing->unk064;
			}

			thing->unk064 >>= 1;
		}
	}

	if (thing->unk0f8 == 2) {
		func0f14cdb8(index, arg1);

		if (thing->unk060 == 12 || thing->unk04c > 120) {
			thing->unk0f8 = 6;
		} else {
			thing->unk060 += 2;
		}
	}

	if (thing->unk0f8 == 6) {
		pak0f1171b4(func0f14a5a4(), 3, 0);
		thing->unk0f8 = 6;
		thing->unk100 = thing->unk0fc;
		g_MpPlayerNum = index;
		menuSetBanner(-1, false);
		pak0f1171b4(func0f14a5a4(), 3, 0);
		var8007f8dc[var800a45a0->unk000].unk0d4_04 = true;
		thing->unk0f8 = 0;
	}

	if (thing->unk0f8 == 0) {
		func0f14cdb8(index, arg1);
	}
}

GLOBAL_ASM(
glabel func0f14d2c8
/*  f14d2c8:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f14d2cc:	3c02800a */ 	lui	$v0,%hi(var800a45a0)
/*  f14d2d0:	8c4245a0 */ 	lw	$v0,%lo(var800a45a0)($v0)
/*  f14d2d4:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f14d2d8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f14d2dc:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f14d2e0:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f14d2e4:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f14d2e8:	3c0f8008 */ 	lui	$t7,%hi(var8007f9d8)
/*  f14d2ec:	25eff9d8 */ 	addiu	$t7,$t7,%lo(var8007f9d8)
/*  f14d2f0:	00809025 */ 	or	$s2,$a0,$zero
/*  f14d2f4:	24080080 */ 	addiu	$t0,$zero,0x80
/*  f14d2f8:	25ea0024 */ 	addiu	$t2,$t7,0x24
/*  f14d2fc:	27ae0050 */ 	addiu	$t6,$sp,0x50
/*  f14d300:	8c510474 */ 	lw	$s1,0x474($v0)
/*  f14d304:	8c500478 */ 	lw	$s0,0x478($v0)
.L0f14d308:
/*  f14d308:	8de10000 */ 	lw	$at,0x0($t7)
/*  f14d30c:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f14d310:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f14d314:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f14d318:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f14d31c:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f14d320:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f14d324:	15eafff8 */ 	bne	$t7,$t2,.L0f14d308
/*  f14d328:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f14d32c:	00003825 */ 	or	$a3,$zero,$zero
/*  f14d330:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f14d334:	000731c0 */ 	sll	$a2,$a3,0x7
.L0f14d338:
/*  f14d338:	00065880 */ 	sll	$t3,$a2,0x2
/*  f14d33c:	022b1821 */ 	addu	$v1,$s1,$t3
/*  f14d340:	02462021 */ 	addu	$a0,$s2,$a2
/*  f14d344:	00001025 */ 	or	$v0,$zero,$zero
.L0f14d348:
/*  f14d348:	908c0000 */ 	lbu	$t4,0x0($a0)
/*  f14d34c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14d350:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f14d354:	448c2000 */ 	mtc1	$t4,$f4
/*  f14d358:	3c014f80 */ 	lui	$at,0x4f80
/*  f14d35c:	05810004 */ 	bgez	$t4,.L0f14d370
/*  f14d360:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14d364:	44814000 */ 	mtc1	$at,$f8
/*  f14d368:	00000000 */ 	nop
/*  f14d36c:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f14d370:
/*  f14d370:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f14d374:	1445fff4 */ 	bne	$v0,$a1,.L0f14d348
/*  f14d378:	e466fffc */ 	swc1	$f6,-0x4($v1)
/*  f14d37c:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f14d380:	00e8082a */ 	slt	$at,$a3,$t0
/*  f14d384:	5420ffec */ 	bnezl	$at,.L0f14d338
/*  f14d388:	000731c0 */ 	sll	$a2,$a3,0x7
/*  f14d38c:	27a40050 */ 	addiu	$a0,$sp,0x50
/*  f14d390:	0fc53613 */ 	jal	func0f14d84c
/*  f14d394:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f14d398:	240d0003 */ 	addiu	$t5,$zero,0x3
/*  f14d39c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f14d3a0:	02202025 */ 	or	$a0,$s1,$zero
/*  f14d3a4:	02002825 */ 	or	$a1,$s0,$zero
/*  f14d3a8:	24060080 */ 	addiu	$a2,$zero,0x80
/*  f14d3ac:	0fc53636 */ 	jal	func0f14d8d8
/*  f14d3b0:	27a70050 */ 	addiu	$a3,$sp,0x50
/*  f14d3b4:	3c013e80 */ 	lui	$at,0x3e80
/*  f14d3b8:	44817000 */ 	mtc1	$at,$f14
/*  f14d3bc:	3c01437f */ 	lui	$at,0x437f
/*  f14d3c0:	44816000 */ 	mtc1	$at,$f12
/*  f14d3c4:	44801000 */ 	mtc1	$zero,$f2
/*  f14d3c8:	8fa80094 */ 	lw	$t0,0x94($sp)
/*  f14d3cc:	00003825 */ 	or	$a3,$zero,$zero
/*  f14d3d0:	24093f00 */ 	addiu	$t1,$zero,0x3f00
/*  f14d3d4:	2406007e */ 	addiu	$a2,$zero,0x7e
.L0f14d3d8:
/*  f14d3d8:	00001825 */ 	or	$v1,$zero,$zero
/*  f14d3dc:	01002025 */ 	or	$a0,$t0,$zero
/*  f14d3e0:	00e02825 */ 	or	$a1,$a3,$zero
.L0f14d3e4:
/*  f14d3e4:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f14d3e8:	03301021 */ 	addu	$v0,$t9,$s0
/*  f14d3ec:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f14d3f0:	c4500004 */ 	lwc1	$f16,0x4($v0)
/*  f14d3f4:	c4440200 */ 	lwc1	$f4,0x200($v0)
/*  f14d3f8:	c4460204 */ 	lwc1	$f6,0x204($v0)
/*  f14d3fc:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f14d400:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f14d404:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f14d408:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f14d40c:	46049200 */ 	add.s	$f8,$f18,$f4
/*  f14d410:	3c014f00 */ 	lui	$at,0x4f00
/*  f14d414:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f14d418:	460e5002 */ 	mul.s	$f0,$f10,$f14
/*  f14d41c:	4602003c */ 	c.lt.s	$f0,$f2
/*  f14d420:	00000000 */ 	nop
/*  f14d424:	45020003 */ 	bc1fl	.L0f14d434
/*  f14d428:	4600603c */ 	c.lt.s	$f12,$f0
/*  f14d42c:	46001006 */ 	mov.s	$f0,$f2
/*  f14d430:	4600603c */ 	c.lt.s	$f12,$f0
.L0f14d434:
/*  f14d434:	00000000 */ 	nop
/*  f14d438:	45020003 */ 	bc1fl	.L0f14d448
/*  f14d43c:	4458f800 */ 	cfc1	$t8,$31
/*  f14d440:	46006006 */ 	mov.s	$f0,$f12
/*  f14d444:	4458f800 */ 	cfc1	$t8,$31
.L0f14d448:
/*  f14d448:	44caf800 */ 	ctc1	$t2,$31
/*  f14d44c:	00000000 */ 	nop
/*  f14d450:	46000424 */ 	cvt.w.s	$f16,$f0
/*  f14d454:	444af800 */ 	cfc1	$t2,$31
/*  f14d458:	00000000 */ 	nop
/*  f14d45c:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f14d460:	51400013 */ 	beqzl	$t2,.L0f14d4b0
/*  f14d464:	440a8000 */ 	mfc1	$t2,$f16
/*  f14d468:	44818000 */ 	mtc1	$at,$f16
/*  f14d46c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f14d470:	46100401 */ 	sub.s	$f16,$f0,$f16
/*  f14d474:	44caf800 */ 	ctc1	$t2,$31
/*  f14d478:	00000000 */ 	nop
/*  f14d47c:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f14d480:	444af800 */ 	cfc1	$t2,$31
/*  f14d484:	00000000 */ 	nop
/*  f14d488:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f14d48c:	15400005 */ 	bnez	$t2,.L0f14d4a4
/*  f14d490:	00000000 */ 	nop
/*  f14d494:	440a8000 */ 	mfc1	$t2,$f16
/*  f14d498:	3c018000 */ 	lui	$at,0x8000
/*  f14d49c:	10000007 */ 	b	.L0f14d4bc
/*  f14d4a0:	01415025 */ 	or	$t2,$t2,$at
.L0f14d4a4:
/*  f14d4a4:	10000005 */ 	b	.L0f14d4bc
/*  f14d4a8:	240affff */ 	addiu	$t2,$zero,-1
/*  f14d4ac:	440a8000 */ 	mfc1	$t2,$f16
.L0f14d4b0:
/*  f14d4b0:	00000000 */ 	nop
/*  f14d4b4:	0540fffb */ 	bltz	$t2,.L0f14d4a4
/*  f14d4b8:	00000000 */ 	nop
.L0f14d4bc:
/*  f14d4bc:	44d8f800 */ 	ctc1	$t8,$31
/*  f14d4c0:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f14d4c4:	1466ffc7 */ 	bne	$v1,$a2,.L0f14d3e4
/*  f14d4c8:	a08affff */ 	sb	$t2,-0x1($a0)
/*  f14d4cc:	24e70100 */ 	addiu	$a3,$a3,0x100
/*  f14d4d0:	14e9ffc1 */ 	bne	$a3,$t1,.L0f14d3d8
/*  f14d4d4:	25080040 */ 	addiu	$t0,$t0,0x40
/*  f14d4d8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f14d4dc:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f14d4e0:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f14d4e4:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f14d4e8:	03e00008 */ 	jr	$ra
/*  f14d4ec:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

GLOBAL_ASM(
glabel func0f14d4f0
/*  f14d4f0:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f14d4f4:	3c02800a */ 	lui	$v0,%hi(var800a45a0)
/*  f14d4f8:	8c4245a0 */ 	lw	$v0,%lo(var800a45a0)($v0)
/*  f14d4fc:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f14d500:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f14d504:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f14d508:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f14d50c:	afa500d4 */ 	sw	$a1,0xd4($sp)
/*  f14d510:	3c0f8008 */ 	lui	$t7,%hi(var8007f9fc)
/*  f14d514:	25eff9fc */ 	addiu	$t7,$t7,%lo(var8007f9fc)
/*  f14d518:	00809025 */ 	or	$s2,$a0,$zero
/*  f14d51c:	24080080 */ 	addiu	$t0,$zero,0x80
/*  f14d520:	25ea0060 */ 	addiu	$t2,$t7,0x60
/*  f14d524:	27ae0050 */ 	addiu	$t6,$sp,0x50
/*  f14d528:	8c510474 */ 	lw	$s1,0x474($v0)
/*  f14d52c:	8c500478 */ 	lw	$s0,0x478($v0)
.L0f14d530:
/*  f14d530:	8de10000 */ 	lw	$at,0x0($t7)
/*  f14d534:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f14d538:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f14d53c:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f14d540:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f14d544:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f14d548:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f14d54c:	15eafff8 */ 	bne	$t7,$t2,.L0f14d530
/*  f14d550:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f14d554:	8de10000 */ 	lw	$at,0x0($t7)
/*  f14d558:	00003825 */ 	or	$a3,$zero,$zero
/*  f14d55c:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f14d560:	adc10000 */ 	sw	$at,0x0($t6)
/*  f14d564:	000731c0 */ 	sll	$a2,$a3,0x7
.L0f14d568:
/*  f14d568:	00065880 */ 	sll	$t3,$a2,0x2
/*  f14d56c:	022b1821 */ 	addu	$v1,$s1,$t3
/*  f14d570:	02462021 */ 	addu	$a0,$s2,$a2
/*  f14d574:	00001025 */ 	or	$v0,$zero,$zero
.L0f14d578:
/*  f14d578:	908c0000 */ 	lbu	$t4,0x0($a0)
/*  f14d57c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14d580:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f14d584:	448c2000 */ 	mtc1	$t4,$f4
/*  f14d588:	3c014f80 */ 	lui	$at,0x4f80
/*  f14d58c:	05810004 */ 	bgez	$t4,.L0f14d5a0
/*  f14d590:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14d594:	44814000 */ 	mtc1	$at,$f8
/*  f14d598:	00000000 */ 	nop
/*  f14d59c:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f14d5a0:
/*  f14d5a0:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f14d5a4:	1445fff4 */ 	bne	$v0,$a1,.L0f14d578
/*  f14d5a8:	e466fffc */ 	swc1	$f6,-0x4($v1)
/*  f14d5ac:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f14d5b0:	00e8082a */ 	slt	$at,$a3,$t0
/*  f14d5b4:	5420ffec */ 	bnezl	$at,.L0f14d568
/*  f14d5b8:	000731c0 */ 	sll	$a2,$a3,0x7
/*  f14d5bc:	240d0005 */ 	addiu	$t5,$zero,0x5
/*  f14d5c0:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f14d5c4:	02202025 */ 	or	$a0,$s1,$zero
/*  f14d5c8:	02002825 */ 	or	$a1,$s0,$zero
/*  f14d5cc:	24060080 */ 	addiu	$a2,$zero,0x80
/*  f14d5d0:	0fc53636 */ 	jal	func0f14d8d8
/*  f14d5d4:	27a70050 */ 	addiu	$a3,$sp,0x50
/*  f14d5d8:	3c013e80 */ 	lui	$at,0x3e80
/*  f14d5dc:	44817000 */ 	mtc1	$at,$f14
/*  f14d5e0:	3c01437f */ 	lui	$at,0x437f
/*  f14d5e4:	44816000 */ 	mtc1	$at,$f12
/*  f14d5e8:	44801000 */ 	mtc1	$zero,$f2
/*  f14d5ec:	8fa800d4 */ 	lw	$t0,0xd4($sp)
/*  f14d5f0:	00003825 */ 	or	$a3,$zero,$zero
/*  f14d5f4:	24093f00 */ 	addiu	$t1,$zero,0x3f00
/*  f14d5f8:	2406007e */ 	addiu	$a2,$zero,0x7e
.L0f14d5fc:
/*  f14d5fc:	00001825 */ 	or	$v1,$zero,$zero
/*  f14d600:	01002025 */ 	or	$a0,$t0,$zero
/*  f14d604:	00e02825 */ 	or	$a1,$a3,$zero
.L0f14d608:
/*  f14d608:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f14d60c:	03301021 */ 	addu	$v0,$t9,$s0
/*  f14d610:	c44a0000 */ 	lwc1	$f10,0x0($v0)
/*  f14d614:	c4500004 */ 	lwc1	$f16,0x4($v0)
/*  f14d618:	c4440200 */ 	lwc1	$f4,0x200($v0)
/*  f14d61c:	c4460204 */ 	lwc1	$f6,0x204($v0)
/*  f14d620:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f14d624:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f14d628:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f14d62c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f14d630:	46049200 */ 	add.s	$f8,$f18,$f4
/*  f14d634:	3c014f00 */ 	lui	$at,0x4f00
/*  f14d638:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f14d63c:	460e5002 */ 	mul.s	$f0,$f10,$f14
/*  f14d640:	4602003c */ 	c.lt.s	$f0,$f2
/*  f14d644:	00000000 */ 	nop
/*  f14d648:	45020003 */ 	bc1fl	.L0f14d658
/*  f14d64c:	4600603c */ 	c.lt.s	$f12,$f0
/*  f14d650:	46001006 */ 	mov.s	$f0,$f2
/*  f14d654:	4600603c */ 	c.lt.s	$f12,$f0
.L0f14d658:
/*  f14d658:	00000000 */ 	nop
/*  f14d65c:	45020003 */ 	bc1fl	.L0f14d66c
/*  f14d660:	4458f800 */ 	cfc1	$t8,$31
/*  f14d664:	46006006 */ 	mov.s	$f0,$f12
/*  f14d668:	4458f800 */ 	cfc1	$t8,$31
.L0f14d66c:
/*  f14d66c:	44caf800 */ 	ctc1	$t2,$31
/*  f14d670:	00000000 */ 	nop
/*  f14d674:	46000424 */ 	cvt.w.s	$f16,$f0
/*  f14d678:	444af800 */ 	cfc1	$t2,$31
/*  f14d67c:	00000000 */ 	nop
/*  f14d680:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f14d684:	51400013 */ 	beqzl	$t2,.L0f14d6d4
/*  f14d688:	440a8000 */ 	mfc1	$t2,$f16
/*  f14d68c:	44818000 */ 	mtc1	$at,$f16
/*  f14d690:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f14d694:	46100401 */ 	sub.s	$f16,$f0,$f16
/*  f14d698:	44caf800 */ 	ctc1	$t2,$31
/*  f14d69c:	00000000 */ 	nop
/*  f14d6a0:	46008424 */ 	cvt.w.s	$f16,$f16
/*  f14d6a4:	444af800 */ 	cfc1	$t2,$31
/*  f14d6a8:	00000000 */ 	nop
/*  f14d6ac:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f14d6b0:	15400005 */ 	bnez	$t2,.L0f14d6c8
/*  f14d6b4:	00000000 */ 	nop
/*  f14d6b8:	440a8000 */ 	mfc1	$t2,$f16
/*  f14d6bc:	3c018000 */ 	lui	$at,0x8000
/*  f14d6c0:	10000007 */ 	b	.L0f14d6e0
/*  f14d6c4:	01415025 */ 	or	$t2,$t2,$at
.L0f14d6c8:
/*  f14d6c8:	10000005 */ 	b	.L0f14d6e0
/*  f14d6cc:	240affff */ 	addiu	$t2,$zero,-1
/*  f14d6d0:	440a8000 */ 	mfc1	$t2,$f16
.L0f14d6d4:
/*  f14d6d4:	00000000 */ 	nop
/*  f14d6d8:	0540fffb */ 	bltz	$t2,.L0f14d6c8
/*  f14d6dc:	00000000 */ 	nop
.L0f14d6e0:
/*  f14d6e0:	44d8f800 */ 	ctc1	$t8,$31
/*  f14d6e4:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f14d6e8:	1466ffc7 */ 	bne	$v1,$a2,.L0f14d608
/*  f14d6ec:	a08affff */ 	sb	$t2,-0x1($a0)
/*  f14d6f0:	24e70100 */ 	addiu	$a3,$a3,0x100
/*  f14d6f4:	14e9ffc1 */ 	bne	$a3,$t1,.L0f14d5fc
/*  f14d6f8:	25080040 */ 	addiu	$t0,$t0,0x40
/*  f14d6fc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f14d700:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f14d704:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f14d708:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f14d70c:	03e00008 */ 	jr	$ra
/*  f14d710:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);

u32 var8007f9fc = 0x3b42938e;
u32 var8007fa00 = 0x3c5a0169;
u32 var8007fa04 = 0x3cb3b752;
u32 var8007fa08 = 0x3c5a0169;
u32 var8007fa0c = 0x3b42938e;
u32 var8007fa10 = 0x3c5a0169;
u32 var8007fa14 = 0x3d7442c8;
u32 var8007fa18 = 0x3dc95bff;
u32 var8007fa1c = 0x3d7442c8;
u32 var8007fa20 = 0x3c5a0169;
u32 var8007fa24 = 0x3cb3b752;
u32 var8007fa28 = 0x3dc95bff;
u32 var8007fa2c = 0x3e25fe54;
u32 var8007fa30 = 0x3dc95bff;
u32 var8007fa34 = 0x3cb3b752;
u32 var8007fa38 = 0x3c5a0169;
u32 var8007fa3c = 0x3d7442c8;
u32 var8007fa40 = 0x3dc95bff;
u32 var8007fa44 = 0x3d7442c8;
u32 var8007fa48 = 0x3c5a0169;
u32 var8007fa4c = 0x3b42938e;
u32 var8007fa50 = 0x3c5a0169;
u32 var8007fa54 = 0x3cb3b752;
u32 var8007fa58 = 0x3c5a0169;
u32 var8007fa5c = 0x3b42938e;

// Mismatch: Different codegen. The function is generating a 64x64 thumbnail
// from a 128x128 source, and there's lots of different ways that variables can
// be used to do this.
//void func0f14d4f0(u8 *arg0, u8 *arg1)
//{
//	f32 *s1 = (f32 *) var800a45a0->unk474;
//	f32 *s0 = (f32 *) var800a45a0->unk478;
//	s32 i;
//	s32 j;
//	s32 x;
//	s32 y;
//
//	f32 sp50[] = {
//		0.0029690000228584f,
//		0.013306000269949f,
//		0.021937999874353f,
//		0.013306000269949f,
//		0.0029690000228584f,
//		0.013306000269949f,
//		0.059634000062943f,
//		0.098319999873638f,
//		0.059634000062943f,
//		0.013306000269949f,
//		0.021937999874353f,
//		0.098319999873638f,
//		0.16210299730301f,
//		0.098319999873638f,
//		0.021937999874353f,
//		0.013306000269949f,
//		0.059634000062943f,
//		0.098319999873638f,
//		0.059634000062943f,
//		0.013306000269949f,
//		0.0029690000228584f,
//		0.013306000269949f,
//		0.021937999874353f,
//		0.013306000269949f,
//		0.0029690000228584f,
//	};
//
//	for (i = 0; i < 128; i++) {
//		for (j = 0; j < 128; j++) {
//			s1[i * 128 + j] = arg0[i * 128 + j];
//		}
//	}
//
//	func0f14d8d8(s1, s0, 128, sp50, 5);
//
//	for (y = 0; y < 63; y++) {
//		for (x = 0; x < 63; x++) {
//			f32 value = (
//					s0[y * 2 * 128 + x * 2 + 0] +
//					s0[y * 2 * 128 + x * 2 + 1] +
//					s0[y * 2 * 128 + x * 2 + 128] +
//					s0[y * 2 * 128 + x * 2 + 129]) * 0.25f;
//
//			if (value < 0.0f) {
//				value = 0.0f;
//			}
//
//			if (value > 255.0f) {
//				value = 255.0f;
//			}
//
//			arg1[y * 64 + x] = value;
//		}
//	}
//}

void func0f14d714(u8 *arg0, u8 *arg1)
{
	s32 x;
	s32 y;

	for (y = 0; y < 63; y++) {
		for (x = 0; x < 63; x++) {
			f32 value = (arg0[y * 256 + x * 2]
					+ arg0[y * 256 + x * 2 + 1]
					+ arg0[y * 256 + x * 2 + 0x80]
					+ arg0[y * 256 + x * 2 + 0x81]) * 0.25f;

			if (value < 0.0f) {
				value = 0.0f;
			}

			if (value > 255.0f) {
				value = 255.0f;
			}

			arg1[y * 64 + x] = value;
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

void phead0f14dac0(u8 *arg0, struct textureconfig *arg1)
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

			if (arg1 != NULL) {
				func0f14e884(arg1, 15 - i, j, f12);
			}
		}
	}
}

void func0f14dc30(s32 index, bool arg1)
{
	f32 f26 = func0f14a984() - 128;
	s32 sp80;
	s32 sp7c;
	s32 y;
	s32 j;
	struct var8007f8e0 *thing = func0f14a06c(index);
	f32 f22;

	f22 = thing->unk3f4_02 ? func0f14e4ac(0, &sp80, &sp7c) : 0.0f;

	for (y = 0; y < 64; y++) {
		for (j = 0; j < 64; j++) {
			f32 f14 = thing->unk01c[y * 64 + j];
			f32 f12;
			f32 f2;

			if (arg1 && thing->unk3f4_02 && sp7c) {
				f32 f0 = sp80 - j;
				f32 fVar8 = f0 > 0.0f ? f0 : -f0;

				f12 = fVar8 / sp7c;

				if (f12 > 1.0f) {
					f12 = 1.0f;
				}

				f2 = f22 * f12;

				if (j > sp80) {
					f2 *= -1.0f;
				}

				f2 *= var8007f8dc->unk088;
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

			thing->unk004.textureptr[(u32)(63 - y) * 64 + j + (((u32)(63 - y) & 1) ? ((j & 4) ? -4 : 4) : 0)] = f12;
		}
	}
}

void func0f14def0(s32 index, u32 line, char *file)
{
	struct var8007f8e0 *a = func0f14a06c(-1);
	struct var8007f8e0 *b = (index != -1 ? func0f14a06c(index) : NULL);
	struct var8007f8e0 *c = func0f14a06c(-4);
	struct var8007f8e0 *d = func0f14a06c(-5);

	func0f14c50c(d, a, 3508, "camdraw.c");

	func0f14dc30(-1, false);

	if (b != NULL) {
		func0f14e1c4(b);
	}

	func0f14dc30(-5, true);

	func0f14e1c4(d);
	func0f14c50c(c, d, 3519, "camdraw.c");
}

const char var7f1b6d1c[] = "Cam %d -> Balance : No Data Available\n";

s32 func0f14dfc0(struct var8007f8e0 *arg0, s32 arg1, s32 arg2)
{
	u32 sp3c[5];
	u32 sp28[5];
	s32 i;
	s32 j;
	s32 len;

	sp28[0] = *(arg0->unk004.textureptr + arg2 * 64 + ((arg2 & 1) ? ((arg1 & 4) ? -4 : 4) : 0) + arg1);
	sp28[1] = *(arg0->unk004.textureptr + (arg2 - 1) * 64 + (((arg2 - 1) & 1) ? ((arg1 & 4) ? -4 : 4) : 0) + arg1);
	sp28[2] = *(arg0->unk004.textureptr + arg2 * 64 + ((arg2 & 1) ? (((arg1 - 1) & 4) ? -4 : 4) : 0) + arg1 - 1);
	sp28[3] = *(arg0->unk004.textureptr + (arg2 + 1) * 64 + (((arg2 + 1) & 1) ? ((arg1 & 4) ? -4 : 4) : 0) + arg1);
	sp28[4] = *(arg0->unk004.textureptr + arg2 * 64 + ((arg2 & 1) ? (((arg1 + 1) & 4) ? -4 : 4) : 0) + arg1 + 1);

	len = 0;

	for (i = 0; i < 5; i++) {
		s32 bestvalue = 9999;
		s32 bestindex = -1;

		for (j = 0; j < 5; j++) {
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

void func0f14e1c4(struct var8007f8e0 *arg0)
{
	s32 spbc;
	s32 spb8;
	s32 spb4;
	s32 spb0;
	s32 mid1;
	s32 mid2;
	f32 f26;
	s32 a;
	s32 b;
	s32 value1;
	s32 value2;
	f32 f22;
	f32 f20;
	s32 i;

	func0f14ecd8(&spbc, &spb8, &spb4, &spb0);

	mid1 = (u32) (spb0 + spb8) >> 1;
	mid2 = (u32) (spb4 + spbc) >> 1;

	f26 = (f32) (spb4 - spbc);

	a = mid2 - (u32)(f26 * 0.25f);
	b = (u32)(f26 * 0.25f) + mid2;

	value1 = func0f14dfc0(arg0, a, mid1);
	value2 = func0f14dfc0(arg0, b, mid1);

	f22 = f26 * 0.5f;

	for (f20 = 0.0f; f20 < f22; f20 += 1.0f) {
		s32 size = f22 - sqrtf(2.0f * f22 * f20 - f20 * f20);

		s32 y1 = ((s32)f20 + spb8);
		s32 y2 = (spb0 - (s32)f20);

		for (i = 0; i < size; i++) {
			s32 x1 = spbc + i;
			s32 x2 = spb4 - i;

			arg0->unk004.textureptr[y1 * 64 + x1 + ((y1 & 1) ? ((x1 & 4) ? -4 : 4) : 0)] = value1;
			arg0->unk004.textureptr[y2 * 64 + x1 + ((y2 & 1) ? ((x1 & 4) ? -4 : 4) : 0)] = value1;
			arg0->unk004.textureptr[y1 * 64 + x2 + ((y1 & 1) ? ((x2 & 4) ? -4 : 4) : 0)] = value2;
			arg0->unk004.textureptr[y2 * 64 + x2 + ((y2 & 1) ? ((x2 & 4) ? -4 : 4) : 0)] = value2;
		}
	}
}

GLOBAL_ASM(
glabel func0f14e4ac
/*  f14e4ac:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f14e4b0:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f14e4b4:	afa400a8 */ 	sw	$a0,0xa8($sp)
/*  f14e4b8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f14e4bc:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f14e4c0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f14e4c4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f14e4c8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f14e4cc:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f14e4d0:	afa600b0 */ 	sw	$a2,0xb0($sp)
/*  f14e4d4:	0fc5281b */ 	jal	func0f14a06c
/*  f14e4d8:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f14e4dc:	27a40098 */ 	addiu	$a0,$sp,0x98
/*  f14e4e0:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f14e4e4:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f14e4e8:	27a7008c */ 	addiu	$a3,$sp,0x8c
/*  f14e4ec:	0fc53b36 */ 	jal	func0f14ecd8
/*  f14e4f0:	afa200a4 */ 	sw	$v0,0xa4($sp)
/*  f14e4f4:	8fa700ac */ 	lw	$a3,0xac($sp)
/*  f14e4f8:	44807000 */ 	mtc1	$zero,$f14
/*  f14e4fc:	8fad00a4 */ 	lw	$t5,0xa4($sp)
/*  f14e500:	10e00002 */ 	beqz	$a3,.L0f14e50c
/*  f14e504:	00005825 */ 	or	$t3,$zero,$zero
/*  f14e508:	ace00000 */ 	sw	$zero,0x0($a3)
.L0f14e50c:
/*  f14e50c:	8fa600b0 */ 	lw	$a2,0xb0($sp)
/*  f14e510:	00004025 */ 	or	$t0,$zero,$zero
/*  f14e514:	00004825 */ 	or	$t1,$zero,$zero
/*  f14e518:	10c00002 */ 	beqz	$a2,.L0f14e524
/*  f14e51c:	46007086 */ 	mov.s	$f2,$f14
/*  f14e520:	acc00000 */ 	sw	$zero,0x0($a2)
.L0f14e524:
/*  f14e524:	8fa40090 */ 	lw	$a0,0x90($sp)
/*  f14e528:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f14e52c:	46007306 */ 	mov.s	$f12,$f14
/*  f14e530:	00851823 */ 	subu	$v1,$a0,$a1
/*  f14e534:	28610020 */ 	slti	$at,$v1,0x20
/*  f14e538:	10200009 */ 	beqz	$at,.L0f14e560
/*  f14e53c:	00857821 */ 	addu	$t7,$a0,$a1
/*  f14e540:	00851021 */ 	addu	$v0,$a0,$a1
/*  f14e544:	00027043 */ 	sra	$t6,$v0,0x1
/*  f14e548:	25d3fff0 */ 	addiu	$s3,$t6,-16
/*  f14e54c:	06610002 */ 	bgez	$s3,.L0f14e558
/*  f14e550:	00000000 */ 	nop
/*  f14e554:	00009825 */ 	or	$s3,$zero,$zero
.L0f14e558:
/*  f14e558:	10000005 */ 	b	.L0f14e570
/*  f14e55c:	26740020 */ 	addiu	$s4,$s3,0x20
.L0f14e560:
/*  f14e560:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f14e564:	0003c843 */ 	sra	$t9,$v1,0x1
/*  f14e568:	03199823 */ 	subu	$s3,$t8,$t9
/*  f14e56c:	0263a021 */ 	addu	$s4,$s3,$v1
.L0f14e570:
/*  f14e570:	8fa4008c */ 	lw	$a0,0x8c($sp)
/*  f14e574:	8fa50094 */ 	lw	$a1,0x94($sp)
/*  f14e578:	02938823 */ 	subu	$s1,$s4,$s3
/*  f14e57c:	00851823 */ 	subu	$v1,$a0,$a1
/*  f14e580:	28610020 */ 	slti	$at,$v1,0x20
/*  f14e584:	10200009 */ 	beqz	$at,.L0f14e5ac
/*  f14e588:	00857821 */ 	addu	$t7,$a0,$a1
/*  f14e58c:	00851021 */ 	addu	$v0,$a0,$a1
/*  f14e590:	00027043 */ 	sra	$t6,$v0,0x1
/*  f14e594:	25d0fff0 */ 	addiu	$s0,$t6,-16
/*  f14e598:	06010002 */ 	bgez	$s0,.L0f14e5a4
/*  f14e59c:	00000000 */ 	nop
/*  f14e5a0:	00008025 */ 	or	$s0,$zero,$zero
.L0f14e5a4:
/*  f14e5a4:	10000005 */ 	b	.L0f14e5bc
/*  f14e5a8:	261f0020 */ 	addiu	$ra,$s0,0x20
.L0f14e5ac:
/*  f14e5ac:	000fc043 */ 	sra	$t8,$t7,0x1
/*  f14e5b0:	0003c843 */ 	sra	$t9,$v1,0x1
/*  f14e5b4:	03198023 */ 	subu	$s0,$t8,$t9
/*  f14e5b8:	0203f821 */ 	addu	$ra,$s0,$v1
.L0f14e5bc:
/*  f14e5bc:	03f01023 */ 	subu	$v0,$ra,$s0
/*  f14e5c0:	00117043 */ 	sra	$t6,$s1,0x1
/*  f14e5c4:	00029043 */ 	sra	$s2,$v0,0x1
/*  f14e5c8:	01c08825 */ 	or	$s1,$t6,$zero
/*  f14e5cc:	1a40003e */ 	blez	$s2,.L0f14e6c8
/*  f14e5d0:	01c05025 */ 	or	$t2,$t6,$zero
/*  f14e5d4:	25ccfff0 */ 	addiu	$t4,$t6,-16
.L0f14e5d8:
/*  f14e5d8:	05810002 */ 	bgez	$t4,.L0f14e5e4
/*  f14e5dc:	01801825 */ 	or	$v1,$t4,$zero
/*  f14e5e0:	00001825 */ 	or	$v1,$zero,$zero
.L0f14e5e4:
/*  f14e5e4:	0071082a */ 	slt	$at,$v1,$s1
/*  f14e5e8:	10200033 */ 	beqz	$at,.L0f14e6b8
/*  f14e5ec:	00601025 */ 	or	$v0,$v1,$zero
/*  f14e5f0:	02741821 */ 	addu	$v1,$s3,$s4
/*  f14e5f4:	021f2021 */ 	addu	$a0,$s0,$ra
/*  f14e5f8:	8dae001c */ 	lw	$t6,0x1c($t5)
/*  f14e5fc:	0004c843 */ 	sra	$t9,$a0,0x1
/*  f14e600:	0003c043 */ 	sra	$t8,$v1,0x1
/*  f14e604:	03001825 */ 	or	$v1,$t8,$zero
/*  f14e608:	032b7823 */ 	subu	$t7,$t9,$t3
/*  f14e60c:	000fc180 */ 	sll	$t8,$t7,0x6
/*  f14e610:	03202025 */ 	or	$a0,$t9,$zero
/*  f14e614:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f14e618:	01c07825 */ 	or	$t7,$t6,$zero
/*  f14e61c:	008b7021 */ 	addu	$t6,$a0,$t3
/*  f14e620:	000ec180 */ 	sll	$t8,$t6,0x6
/*  f14e624:	03233021 */ 	addu	$a2,$t9,$v1
/*  f14e628:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f14e62c:	03233821 */ 	addu	$a3,$t9,$v1
/*  f14e630:	00c27023 */ 	subu	$t6,$a2,$v0
.L0f14e634:
/*  f14e634:	91c30000 */ 	lbu	$v1,0x0($t6)
/*  f14e638:	00e27821 */ 	addu	$t7,$a3,$v0
/*  f14e63c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14e640:	28610015 */ 	slti	$at,$v1,0x15
/*  f14e644:	1420001a */ 	bnez	$at,.L0f14e6b0
/*  f14e648:	91e40000 */ 	lbu	$a0,0x0($t7)
/*  f14e64c:	286100c8 */ 	slti	$at,$v1,0xc8
/*  f14e650:	10200017 */ 	beqz	$at,.L0f14e6b0
/*  f14e654:	28810015 */ 	slti	$at,$a0,0x15
/*  f14e658:	14200015 */ 	bnez	$at,.L0f14e6b0
/*  f14e65c:	288100c8 */ 	slti	$at,$a0,0xc8
/*  f14e660:	10200013 */ 	beqz	$at,.L0f14e6b0
/*  f14e664:	00000000 */ 	nop
/*  f14e668:	44832000 */ 	mtc1	$v1,$f4
/*  f14e66c:	44845000 */ 	mtc1	$a0,$f10
/*  f14e670:	04610005 */ 	bgez	$v1,.L0f14e688
/*  f14e674:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f14e678:	3c014f80 */ 	lui	$at,0x4f80
/*  f14e67c:	44814000 */ 	mtc1	$at,$f8
/*  f14e680:	00000000 */ 	nop
/*  f14e684:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f14e688:
/*  f14e688:	46061080 */ 	add.s	$f2,$f2,$f6
/*  f14e68c:	25080001 */ 	addiu	$t0,$t0,0x1
/*  f14e690:	04810005 */ 	bgez	$a0,.L0f14e6a8
/*  f14e694:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f14e698:	3c014f80 */ 	lui	$at,0x4f80
/*  f14e69c:	44819000 */ 	mtc1	$at,$f18
/*  f14e6a0:	00000000 */ 	nop
/*  f14e6a4:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f14e6a8:
/*  f14e6a8:	46106300 */ 	add.s	$f12,$f12,$f16
/*  f14e6ac:	25290001 */ 	addiu	$t1,$t1,0x1
.L0f14e6b0:
/*  f14e6b0:	544affe0 */ 	bnel	$v0,$t2,.L0f14e634
/*  f14e6b4:	00c27023 */ 	subu	$t6,$a2,$v0
.L0f14e6b8:
/*  f14e6b8:	256b0001 */ 	addiu	$t3,$t3,0x1
/*  f14e6bc:	0172082a */ 	slt	$at,$t3,$s2
/*  f14e6c0:	1420ffc5 */ 	bnez	$at,.L0f14e5d8
/*  f14e6c4:	00000000 */ 	nop
.L0f14e6c8:
/*  f14e6c8:	51000029 */ 	beqzl	$t0,.L0f14e770
/*  f14e6cc:	46007006 */ 	mov.s	$f0,$f14
/*  f14e6d0:	51200027 */ 	beqzl	$t1,.L0f14e770
/*  f14e6d4:	46007006 */ 	mov.s	$f0,$f14
/*  f14e6d8:	44882000 */ 	mtc1	$t0,$f4
/*  f14e6dc:	44895000 */ 	mtc1	$t1,$f10
/*  f14e6e0:	3c013f80 */ 	lui	$at,0x3f80
/*  f14e6e4:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f14e6e8:	44810000 */ 	mtc1	$at,$f0
/*  f14e6ec:	8fb800ac */ 	lw	$t8,0xac($sp)
/*  f14e6f0:	0274c821 */ 	addu	$t9,$s3,$s4
/*  f14e6f4:	00197043 */ 	sra	$t6,$t9,0x1
/*  f14e6f8:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f14e6fc:	3c013f00 */ 	lui	$at,0x3f00
/*  f14e700:	46080183 */ 	div.s	$f6,$f0,$f8
/*  f14e704:	46120403 */ 	div.s	$f16,$f0,$f18
/*  f14e708:	46061082 */ 	mul.s	$f2,$f2,$f6
/*  f14e70c:	00000000 */ 	nop
/*  f14e710:	46106302 */ 	mul.s	$f12,$f12,$f16
/*  f14e714:	13000002 */ 	beqz	$t8,.L0f14e720
/*  f14e718:	00000000 */ 	nop
/*  f14e71c:	af0e0000 */ 	sw	$t6,0x0($t8)
.L0f14e720:
/*  f14e720:	460c1100 */ 	add.s	$f4,$f2,$f12
/*  f14e724:	44814000 */ 	mtc1	$at,$f8
/*  f14e728:	8faf00b0 */ 	lw	$t7,0xb0($sp)
/*  f14e72c:	46082182 */ 	mul.s	$f6,$f4,$f8
/*  f14e730:	51e00003 */ 	beqzl	$t7,.L0f14e740
/*  f14e734:	46023001 */ 	sub.s	$f0,$f6,$f2
/*  f14e738:	adf10000 */ 	sw	$s1,0x0($t7)
/*  f14e73c:	46023001 */ 	sub.s	$f0,$f6,$f2
.L0f14e740:
/*  f14e740:	8faf00a8 */ 	lw	$t7,0xa8($sp)
/*  f14e744:	3c188008 */ 	lui	$t8,%hi(var8007f8dc)
/*  f14e748:	8f18f8dc */ 	lw	$t8,%lo(var8007f8dc)($t8)
/*  f14e74c:	4600028d */ 	trunc.w.s	$f10,$f0
/*  f14e750:	000fc980 */ 	sll	$t9,$t7,0x6
/*  f14e754:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f14e758:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f14e75c:	440e5000 */ 	mfc1	$t6,$f10
/*  f14e760:	03197821 */ 	addu	$t7,$t8,$t9
/*  f14e764:	10000002 */ 	b	.L0f14e770
/*  f14e768:	adee0090 */ 	sw	$t6,0x90($t7)
/*  f14e76c:	46007006 */ 	mov.s	$f0,$f14
.L0f14e770:
/*  f14e770:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f14e774:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f14e778:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f14e77c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f14e780:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f14e784:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f14e788:	03e00008 */ 	jr	$ra
/*  f14e78c:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

void func0f14e790(u8 *arg0)
{
	s32 i;
	s32 j;

	for (i = 0; i < 128; i++) {
		for (j = 0; j < 128; j++) {
			arg0[i * 128 + j] = j / 16 * 32;
		}
	}
}

void func0f14e7e0(u8 *arg0)
{
	s32 i;
	s32 j;

	for (i = 0; i < 128; i++) {
		for (j = 0; j < 128; j++) {
			arg0[i * 128 + j] = random() % 255;
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
	sp40 = (0x40 - sp40 - bitsperpixel) & 0x3f;

	if (numrows & 1) {
		sp40 = (sp40 + 0x20) & 0x3f;
	}

	sp34 = (s64 *)(tconfig->textureptr + ((sp5c >> 3) + (numbytes >> 3)) * 8);
	*sp34 = (*sp34 & ~(mask << sp40)) + (arg3 << sp40);
}

Gfx *func0f14eb04(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
	f32 sp30[2];
	struct var8007f8e0 *thing;
	u32 stack[2];

	sp30[0] = arg2;
	sp30[1] = arg3;

	thing = func0f14a06c(arg1);

	gdl = func0f14c870(gdl, &thing->unk004, sp30, (arg4 - arg2) * 0.015625f, (arg5 - arg3) * 0.015625f);

	return gdl;
}

Gfx *func0f14eb98(Gfx *gdl, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
	f32 sp30[2];
	struct var8007f8e0 *thing;
	u32 stack[2];

	sp30[0] = arg2;
	sp30[1] = arg3;

	thing = func0f14a06c(arg1);

	gdl = func0f14c870(gdl, &thing->unk010, sp30, (arg4 - arg2) * 0.0625f, (arg5 - arg3) * 0.0625f);

	return gdl;
}

void func0f14ec2c(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
	struct var8007f8e0 *thing1 = func0f14a06c(-1);
	struct var8007f8e0 *thing2 = func0f14a06c(-2);

	if (thing1) {
		thing1->unk3c0 = arg0;
		thing1->unk3c8 = arg1;
		thing1->unk3c4 = arg2;
		thing1->unk3cc = arg3;
		thing1->unk3ec = 0;
		thing1->unk3f0 = 0;
	}

	if (thing2) {
		thing2->unk3c0 = arg0;
		thing2->unk3c8 = arg1;
		thing2->unk3c4 = arg2;
		thing2->unk3cc = arg3;
		thing2->unk3ec = 0;
		thing2->unk3f0 = 0;
	}

	func0f14def0(-1, 4159, "camdraw.c");
}

const char var7f1b6d50[] = "Cam_SetSquashZ : %u, %u, %f\n";

void func0f14ecd8(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3)
{
	struct var8007f8e0 *thing = func0f14a06c(-2);

	*arg0 = thing->unk3c0;
	*arg1 = thing->unk3c8;
	*arg2 = thing->unk3c4;
	*arg3 = thing->unk3cc;
}

void func0f14ed38(void)
{
	func0f14ec2c(10, 3, 54, 61);
}

u32 func0f14ed64(void)
{
	f32 foo[7];

	func0f14ef50(foo);

	return (u32)(foo[6] * 100) - 25;
}

void func0f14ee18(u32 arg0)
{
	f32 foo[7];

	arg0 += 25;

	func0f14ef50(foo);

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
void func0f14eeb0(f32 *arg0)
{
	struct var8007f8e0 *thing1 = func0f14a06c(-1);
	struct var8007f8e0 *thing2 = func0f14a06c(-2);
	s32 i;

	for (i = 0; i < 7; i++) {
		f32 tmp = arg0[i];

		if (tmp > 1.9f) {
			tmp = 1.9f;
		}

		if (tmp < 0.1f) {
			tmp = 0.1f;
		}

		if (thing1) {
			thing1->unk3d0[i] = arg0[i];
		}

		if (thing2) {
			thing2->unk3d0[i] = arg0[i];
		}
	}

	func0f14def0(-1, 4240, "camdraw.c");
}

void func0f14ef50(f32 *arg0)
{
	s32 i;

	for (i = 0; i < 7; i++) {
		struct var8007f8e0 *thing = func0f14a06c(-2);

		arg0[i] = thing->unk3d0[i];
	}
}

const char var7f1b6d7c[] = "Cam : Alloc for copy of Vtx %d bytes\n";
const char var7f1b6da4[] = "CAM : Cam_AllocAndCopyAllVtx -> Ptr all-ready allocted - No extra needed\n";

void func0f14efa8(void)
{
	f32 array[] = {1, 1, 1, 1, 1, 1, 1};
	func0f14eeb0(array);
}

s32 func0f14f008(s32 index)
{
	if (index == -1) {
		index = var800a45a0->unk000;
	}

	return var8007f8dc[index].unk094;
}

void func0f14f03c(s32 index, s32 value)
{
	var8007f8dc[index].unk074 = value;
}

s32 func0f14f05c(s32 index)
{
	return var8007f8dc[index].unk074;
}

Gfx *func0f14f07c(Gfx *gdl, s32 headorbodynum, s32 x1, s32 y1, s32 x2, s32 y2)
{
	struct textureconfig *thing = &var800a45a0->unk484[headorbodynum];
	f32 sp34[2];
	u32 stack;

	sp34[0] = x1;
	sp34[1] = y1;

	if (func0f14a20c()->unk0b6[headorbodynum] != 0xff) {
		if (func0f14a20c()->unk0dc[headorbodynum] == 0) {
			gdl = func0f14c870(gdl, var800a45a0->unk488, sp34,
					(x2 - x1) * (1.0f / 64.0f),
					(y2 - y1) * (1.0f / 64.0f));
		} else {
			gdl = func0f14c870(gdl, thing, sp34,
					(x2 - x1) * (1.0f / 64.0f),
					(y2 - y1) * (1.0f / 64.0f));
		}
	}

	return gdl;
}

/**
 * Calculate the bounding box of the src coordinates and store it in dst.
 *
 * Note that each element in src is 12 bytes
 * but only the first 6 are coordinates.
 */
void func0f14f1d4(s16 *src, s32 len, s32 *dst)
{
	s32 i;

	if (len > 0) {
		dst[0] = dst[3] = src[0];
		dst[1] = dst[4] = src[1];
		dst[2] = dst[5] = src[2];

		for (i = 1; i < len; i++) {
			if (src[i * 6] > dst[3]) {
				dst[3] = src[i * 6];
			} else if (src[i * 6] < dst[0]) {
				dst[0] = src[i * 6];
			}

			if (src[i * 6 + 1] > dst[4]) {
				dst[4] = src[i * 6 + 1];
			} else if (src[i * 6 + 1] < dst[1]) {
				dst[1] = src[i * 6 + 1];
			}

			if (src[i * 6 + 2] > dst[5]) {
				dst[5] = src[i * 6 + 2];
			} else if (src[i * 6 + 2] < dst[2]) {
				dst[2] = src[i * 6 + 2];
			}
		}
	}
}

s32 func0f14f2b4(struct modelfiledata *filedata, struct gfxvtx **dst, u32 *len)
{
	struct modelnode *node1 = modelGetPart(filedata, MODELPART_HEAD_0190);
	struct modelnode *node2 = modelGetPart(filedata, MODELPART_HEAD_0191);
	struct modelnode *node3 = modelGetPart(filedata, MODELPART_HEAD_0192);

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
		size = align16(totalverts * sizeof(struct gfxvtx));

		if (*dst == 0) {
			*dst = func0f149d58(size, 4429, "camdraw.c");
		}

		memcpy(*dst, node1rodata->vertices, node1numverts * sizeof(struct gfxvtx));
		memcpy(*dst + node1numverts, node2rodata->vertices, node2numverts * sizeof(struct gfxvtx));
		memcpy(*dst + node1numverts + node2numverts, node3rodata->vertices, node3numverts * sizeof(struct gfxvtx));

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
const char var7f1b7104[] = "Cam_LoadFromPakIntoSlot -> Pak=%d, fileGuid=%u, pakGuid=%u, Slot=%d, pS=%x, pE=%x\n";


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

u32 func0f14f4a0(u32 arg0)
{
	return arg0;
}

void func0f14f4a8(void)
{
	// empty
}

void func0f14f4b0(u32 arg0)
{
	// empty
}

void func0f14f4b8(struct var8007f8e0 *arg0)
{
	s32 i;

	arg0->unk028 = 0;
	arg0->unk02c = 0;

	for (i = 0; i < 64 * 64; i++) {
		arg0->unk01c[i] = 0;
	}
}

void func0f14f4e4(struct var8007f8e0 *arg0)
{
	s32 i;

	arg0->unk028 = 0;
	arg0->unk02c = 0;

	for (i = 0; i < 64 * 64; i++) {
		arg0->unk024[i] = 0;
	}
}

GLOBAL_ASM(
glabel func0f14f510
.late_rodata
glabel var7f1b7364
.word 0x40490fda
.text
/*  f14f510:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f14f514:	afb40050 */ 	sw	$s4,0x50($sp)
/*  f14f518:	afb3004c */ 	sw	$s3,0x4c($sp)
/*  f14f51c:	3c14800a */ 	lui	$s4,%hi(var800a45a0)
/*  f14f520:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f14f524:	afb60058 */ 	sw	$s6,0x58($sp)
/*  f14f528:	afb50054 */ 	sw	$s5,0x54($sp)
/*  f14f52c:	afb20048 */ 	sw	$s2,0x48($sp)
/*  f14f530:	afb10044 */ 	sw	$s1,0x44($sp)
/*  f14f534:	afb00040 */ 	sw	$s0,0x40($sp)
/*  f14f538:	f7bc0038 */ 	sdc1	$f28,0x38($sp)
/*  f14f53c:	f7ba0030 */ 	sdc1	$f26,0x30($sp)
/*  f14f540:	f7b80028 */ 	sdc1	$f24,0x28($sp)
/*  f14f544:	f7b60020 */ 	sdc1	$f22,0x20($sp)
/*  f14f548:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f14f54c:	269445a0 */ 	addiu	$s4,$s4,%lo(var800a45a0)
/*  f14f550:	00009825 */ 	or	$s3,$zero,$zero
/*  f14f554:	266e0001 */ 	addiu	$t6,$s3,0x1
.L0f14f558:
/*  f14f558:	01c40019 */ 	multu	$t6,$a0
/*  f14f55c:	00008825 */ 	or	$s1,$zero,$zero
/*  f14f560:	00008025 */ 	or	$s0,$zero,$zero
/*  f14f564:	00001012 */ 	mflo	$v0
/*  f14f568:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f14f56c:	00000000 */ 	nop
.L0f14f570:
/*  f14f570:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f14f574:	0013c140 */ 	sll	$t8,$s3,0x5
/*  f14f578:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f14f57c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f14f580:	03304021 */ 	addu	$t0,$t9,$s0
/*  f14f584:	2a210008 */ 	slti	$at,$s1,0x8
/*  f14f588:	ad02006c */ 	sw	$v0,0x6c($t0)
/*  f14f58c:	00441021 */ 	addu	$v0,$v0,$a0
/*  f14f590:	1420fff7 */ 	bnez	$at,.L0f14f570
/*  f14f594:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f14f598:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f14f59c:	2a610008 */ 	slti	$at,$s3,0x8
/*  f14f5a0:	5420ffed */ 	bnezl	$at,.L0f14f558
/*  f14f5a4:	266e0001 */ 	addiu	$t6,$s3,0x1
/*  f14f5a8:	8e890000 */ 	lw	$t1,0x0($s4)
/*  f14f5ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f14f5b0:	4481b000 */ 	mtc1	$at,$f22
/*  f14f5b4:	ad200010 */ 	sw	$zero,0x10($t1)
/*  f14f5b8:	8e8a0000 */ 	lw	$t2,0x0($s4)
/*  f14f5bc:	3c014100 */ 	lui	$at,0x4100
/*  f14f5c0:	4481a000 */ 	mtc1	$at,$f20
/*  f14f5c4:	00008025 */ 	or	$s0,$zero,$zero
/*  f14f5c8:	00009025 */ 	or	$s2,$zero,$zero
/*  f14f5cc:	24110100 */ 	addiu	$s1,$zero,0x100
/*  f14f5d0:	ad40000c */ 	sw	$zero,0xc($t2)
.L0f14f5d4:
/*  f14f5d4:	0c012974 */ 	jal	sqrtf
/*  f14f5d8:	4600a306 */ 	mov.s	$f12,$f20
/*  f14f5dc:	4600b103 */ 	div.s	$f4,$f22,$f0
/*  f14f5e0:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f14f5e4:	01706021 */ 	addu	$t4,$t3,$s0
/*  f14f5e8:	e584017c */ 	swc1	$f4,0x17c($t4)
/*  f14f5ec:	8e820000 */ 	lw	$v0,0x0($s4)
/*  f14f5f0:	00506821 */ 	addu	$t5,$v0,$s0
/*  f14f5f4:	c5a6017c */ 	lwc1	$f6,0x17c($t5)
/*  f14f5f8:	00527021 */ 	addu	$t6,$v0,$s2
/*  f14f5fc:	26520020 */ 	addiu	$s2,$s2,0x20
/*  f14f600:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f14f604:	1651fff3 */ 	bne	$s2,$s1,.L0f14f5d4
/*  f14f608:	e5c6027c */ 	swc1	$f6,0x27c($t6)
/*  f14f60c:	3c014180 */ 	lui	$at,0x4180
/*  f14f610:	4481e000 */ 	mtc1	$at,$f28
/*  f14f614:	3c017f1b */ 	lui	$at,%hi(var7f1b7364)
/*  f14f618:	c43a7364 */ 	lwc1	$f26,%lo(var7f1b7364)($at)
/*  f14f61c:	3c013e80 */ 	lui	$at,0x3e80
/*  f14f620:	4481c000 */ 	mtc1	$at,$f24
/*  f14f624:	24130001 */ 	addiu	$s3,$zero,0x1
/*  f14f628:	24150004 */ 	addiu	$s5,$zero,0x4
/*  f14f62c:	24160008 */ 	addiu	$s6,$zero,0x8
.L0f14f630:
/*  f14f630:	44934000 */ 	mtc1	$s3,$f8
/*  f14f634:	00008825 */ 	or	$s1,$zero,$zero
/*  f14f638:	00008025 */ 	or	$s0,$zero,$zero
/*  f14f63c:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f14f640:	468045a0 */ 	cvt.s.w	$f22,$f8
.L0f14f644:
/*  f14f644:	0c012974 */ 	jal	sqrtf
/*  f14f648:	4600c306 */ 	mov.s	$f12,$f24
/*  f14f64c:	44925000 */ 	mtc1	$s2,$f10
/*  f14f650:	46000506 */ 	mov.s	$f20,$f0
/*  f14f654:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f14f658:	461a8482 */ 	mul.s	$f18,$f16,$f26
/*  f14f65c:	00000000 */ 	nop
/*  f14f660:	46169102 */ 	mul.s	$f4,$f18,$f22
/*  f14f664:	0c0068f4 */ 	jal	cosf
/*  f14f668:	461c2303 */ 	div.s	$f12,$f4,$f28
/*  f14f66c:	46140182 */ 	mul.s	$f6,$f0,$f20
/*  f14f670:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*  f14f674:	0013c140 */ 	sll	$t8,$s3,0x5
/*  f14f678:	00134940 */ 	sll	$t1,$s3,0x5
/*  f14f67c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f14f680:	03304021 */ 	addu	$t0,$t9,$s0
/*  f14f684:	00116140 */ 	sll	$t4,$s1,0x5
/*  f14f688:	e506017c */ 	swc1	$f6,0x17c($t0)
/*  f14f68c:	8e820000 */ 	lw	$v0,0x0($s4)
/*  f14f690:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f14f694:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f14f698:	00495021 */ 	addu	$t2,$v0,$t1
/*  f14f69c:	01505821 */ 	addu	$t3,$t2,$s0
/*  f14f6a0:	c568017c */ 	lwc1	$f8,0x17c($t3)
/*  f14f6a4:	004c6821 */ 	addu	$t5,$v0,$t4
/*  f14f6a8:	01b57021 */ 	addu	$t6,$t5,$s5
/*  f14f6ac:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f14f6b0:	1636ffe4 */ 	bne	$s1,$s6,.L0f14f644
/*  f14f6b4:	e5c8027c */ 	swc1	$f8,0x27c($t6)
/*  f14f6b8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f14f6bc:	1676ffdc */ 	bne	$s3,$s6,.L0f14f630
/*  f14f6c0:	26b50004 */ 	addiu	$s5,$s5,0x4
/*  f14f6c4:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*  f14f6c8:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f14f6cc:	d7b60020 */ 	ldc1	$f22,0x20($sp)
/*  f14f6d0:	d7b80028 */ 	ldc1	$f24,0x28($sp)
/*  f14f6d4:	d7ba0030 */ 	ldc1	$f26,0x30($sp)
/*  f14f6d8:	d7bc0038 */ 	ldc1	$f28,0x38($sp)
/*  f14f6dc:	8fb00040 */ 	lw	$s0,0x40($sp)
/*  f14f6e0:	8fb10044 */ 	lw	$s1,0x44($sp)
/*  f14f6e4:	8fb20048 */ 	lw	$s2,0x48($sp)
/*  f14f6e8:	8fb3004c */ 	lw	$s3,0x4c($sp)
/*  f14f6ec:	8fb40050 */ 	lw	$s4,0x50($sp)
/*  f14f6f0:	8fb50054 */ 	lw	$s5,0x54($sp)
/*  f14f6f4:	8fb60058 */ 	lw	$s6,0x58($sp)
/*  f14f6f8:	03e00008 */ 	jr	$ra
/*  f14f6fc:	27bd0060 */ 	addiu	$sp,$sp,0x60
);

//void func0f14f510(s32 arg0)
//{
//	s32 i;
//	s32 j;
//
//	for (i = 0; i < 8; i++) {
//		s32 tmp = (i + 1) * arg0 + 1;
//
//		for (j = 0; j < 8; j++) {
//			var800a45a0->unk06c[i * 8 + j] = tmp + j * arg0;
//		}
//	}
//
//	var800a45a0->unk010 = 0;
//	var800a45a0->unk00c = 0;
//
//	for (i = 0; i < 8; i++) {
//		var800a45a0->unk17c[i] = 1 / sqrtf(8);
//		var800a45a0->unk27c[i * 8] = var800a45a0->unk17c[i];
//	}
//
//	for (i = 1; i < 8; i++) {
//		for (j = 0; j < 8; j++) {
//			var800a45a0->unk17c[i * 8 + j] = sqrtf(0.25f) * cosf(((1 + j * 2) * M_PI * i) / 16.0f);
//			var800a45a0->unk27c[j * 8 + i] = var800a45a0->unk17c[i * 8 + j];
//		}
//	}
//}

void func0f14f700(struct var8007f8e0 *arg0, u32 arg1, u32 arg2)
{
	u32 bit;

	for (bit = 1 << (arg2 + 31); bit != 0; bit >>= 1) {
		if (bit & arg1) {
			s32 remainder = arg0->unk02c % 8;
			s32 index = arg0->unk02c / 8;
			u8 mask = 1 << (7 - remainder);

			arg0->unk024[index] |= mask;
		}

		arg0->unk02c++;
	}
}

u32 func0f14f76c(struct var8007f8e0 *arg0, u32 arg1)
{
	u32 bit;
	u32 bits;

	for (bit = 1 << (arg1 + 31), bits = 0; bit != 0; bit >>= 1) {
		u32 remainder = arg0->unk02c % 8;
		u32 index = arg0->unk02c / 8;
		u8 mask = 1 << (7 - remainder);

		if (arg0->unk020[index] & mask) {
			bits |= bit;
		}

		arg0->unk02c++;
	}

	return bits;
}

s32 phead0f14f7d4(struct var8007f8e0 *arg0)
{
	s32 sp24;
	s32 v0;

	if (var800a45a0->unk00c > 0) {
		var800a45a0->unk00c--;
		return 0;
	}

	sp24 = func0f14f76c(arg0, 2);

	if (sp24 == 0) {
		var800a45a0->unk00c = func0f14f76c(arg0, 4);
		return 0;
	}

	if (sp24 == 1) {
		sp24 = func0f14f76c(arg0, 1) + 1;
	} else {
		sp24 = func0f14f76c(arg0, 2) + sp24 * 4 - 5;
	}

	v0 = func0f14f76c(arg0, sp24);

	if ((1 << (sp24 + 31)) & v0) {
		return v0;
	}

	return (v0 - (1 << sp24)) + 1;
}

void phead0f14f8cc(struct var8007f8e0 *arg0, s32 arg1[8][8])
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var7f1b60a0); i++) {
		s32 v0 = phead0f14f7d4(arg0);

		s32 upper = var7f1b60a0[i][0];
		s32 lower = var7f1b60a0[i][1];

		arg1[upper][lower] = var800a45a0->unk06c[upper][lower] * v0;
	}
}

void func0f14f974(struct var8007f8e0 *arg0, s32 arg1)
{
	s32 absarg1;
	s32 sp28;
	s32 sp24;

	if (arg1 == 0) {
		var800a45a0->unk010++;
		return;
	}

	if (var800a45a0->unk010 != 0) {
		while (var800a45a0->unk010 > 0) {
			func0f14f700(arg0, 0, 2);

			if (var800a45a0->unk010 < 17) {
				func0f14f700(arg0, var800a45a0->unk010 - 1, 4);
				var800a45a0->unk010 = 0;
			} else {
				func0f14f700(arg0, 15, 4);
				var800a45a0->unk010 -= 16;
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
		func0f14f700(arg0, sp24 + 1, 3);
	} else {
		func0f14f700(arg0, sp24 + 5, 4);
	}

	if (arg1 > 0) {
		func0f14f700(arg0, arg1, sp24);
	} else {
		func0f14f700(arg0, arg1 + sp28, sp24);
	}
}

void func0f14faf8(struct var8007f8e0 *arg0, s32 arg1[8][8])
{
	s32 i;

	for (i = 0; i < ARRAYCOUNT(var7f1b60a0); i++) {
		u32 upper = var7f1b60a0[i][0];
		u32 lower = var7f1b60a0[i][1];
		f32 f0 = (f32) arg1[upper][lower] / (f32) var800a45a0->unk06c[upper][lower];
		s32 a1;

		if (f0 < 0.0f) {
			a1 = f0 - 0.5f;
		} else {
			a1 = f0 + 0.5f;
		}

		func0f14f974(arg0, a1);
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
				sp30[i][j] += (arg0[i][k] - 0x80) * var800a45a0->unk27c[k][j];
			}
		}
	}

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			f32 f0 = 0.0f;

			for (k = 0; k < 8; k++) {
				f0 += var800a45a0->unk17c[i][k] * sp30[k][j];
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
				sp30[i][j] += arg0[i][k] * var800a45a0->unk17c[k][j];
			}
		}
	}

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			f32 f0 = 0.0f;

			for (k = 0; k < 8; k++) {
				f0 += var800a45a0->unk27c[i][k] * sp30[k][j];
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

void func0f14ff94(struct var8007f8e0 *arg0)
{
	s32 i;
	s32 j;
	s32 k;
	s32 tmp;
	s32 sp60[8][8];
	u8 *sp40[8];

	func0f14f4b8(arg0);
	tmp = func0f14f76c(arg0, 8);
	func0f14f510(tmp);

	for (i = 0; i < 64; i += 8) {
		for (j = 0; j < 64; j += 8) {
			phead0f14f8cc(arg0, sp60);

			for (k = 0; k < 8; k++) {
				sp40[k] = &arg0->unk01c[(i + k) * 64 + j];
			}

			phead0f14fdb0(sp60, sp40);
		}
	}
}

void func0f150068(struct var8007f8e0 *arg0, s32 arg1)
{
	s32 i;
	s32 j;
	s32 k;
	s32 sp64[8][8];
	u8 *sp44[8];

	func0f14f4e4(arg0);
	func0f14f510(arg1);
	func0f14f700(arg0, arg1, 8);

	for (i = 0; i < 0x40; i += 8) {
		for (j = 0; j < 0x40; j += 8) {
			for (k = 0; k < 8; k++) {
				sp44[k] = &arg0->unk01c[(i + k) * 0x40 + j];
			}

			func0f14fbfc(sp44, sp64);
			func0f14faf8(arg0, sp64);
		}
	}

	func0f14f974(arg0, 1);

	arg0->unk034 = arg0->unk02c / 8;
}

const char var7f1b7158[] = "camdraw.c";
const char var7f1b7164[] = "camdraw.c";
const char var7f1b7170[] = "Cam -> Compressing Editor Slot\n";
const char var7f1b7190[] = "Cam -> Trying image compression at quality %u\n";
const char var7f1b71c0[] = "Cam -> Failed - Too big - This=%u, Max=%d\n";
const char var7f1b71ec[] = "Cam -> Trying lower quality setting\n";
const char var7f1b7214[] = "Cam -> Save Failed - Cant get it small enough - oo-er\n";
const char var7f1b724c[] = "Cam -> Sucess at quality %u - Size=%u, Max=%d\n";
const char var7f1b727c[] = "\nCam_SaveEditSlotToParamPakItem -> Save failed\n";
const char var7f1b72ac[] = "Camera Save Error Result: %d\n";
const char var7f1b72cc[] = "Magic Guid set to %d\n";

GLOBAL_ASM(
glabel func0f15015c
/*  f15015c:	27bdfb20 */ 	addiu	$sp,$sp,-1248
/*  f150160:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f150164:	afa404e0 */ 	sw	$a0,0x4e0($sp)
/*  f150168:	afa604e8 */ 	sw	$a2,0x4e8($sp)
/*  f15016c:	00047600 */ 	sll	$t6,$a0,0x18
/*  f150170:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f150174:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f150178:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f15017c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f150180:	27a60040 */ 	addiu	$a2,$sp,0x40
/*  f150184:	0fc45a00 */ 	jal	pakReadBodyAtGuid
/*  f150188:	24070080 */ 	addiu	$a3,$zero,0x80
/*  f15018c:	1440000b */ 	bnez	$v0,.L0f1501bc
/*  f150190:	8fa504e8 */ 	lw	$a1,0x4e8($sp)
/*  f150194:	00a01825 */ 	or	$v1,$a1,$zero
/*  f150198:	27a20040 */ 	addiu	$v0,$sp,0x40
/*  f15019c:	27a400c0 */ 	addiu	$a0,$sp,0xc0
.L0f1501a0:
/*  f1501a0:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f1501a4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1501a8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1501ac:	1444fffc */ 	bne	$v0,$a0,.L0f1501a0
/*  f1501b0:	a078ffff */ 	sb	$t8,-0x1($v1)
/*  f1501b4:	10000010 */ 	b	.L0f1501f8
/*  f1501b8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1501bc:
/*  f1501bc:	2401000a */ 	addiu	$at,$zero,0xa
/*  f1501c0:	1441000c */ 	bne	$v0,$at,.L0f1501f4
/*  f1501c4:	24120080 */ 	addiu	$s2,$zero,0x80
/*  f1501c8:	00008025 */ 	or	$s0,$zero,$zero
/*  f1501cc:	00a08825 */ 	or	$s1,$a1,$zero
.L0f1501d0:
/*  f1501d0:	0c004b70 */ 	jal	random
/*  f1501d4:	00000000 */ 	nop
/*  f1501d8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1501dc:	0212082a */ 	slt	$at,$s0,$s2
/*  f1501e0:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1501e4:	1420fffa */ 	bnez	$at,.L0f1501d0
/*  f1501e8:	a222ffff */ 	sb	$v0,-0x1($s1)
/*  f1501ec:	10000002 */ 	b	.L0f1501f8
/*  f1501f0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1501f4:
/*  f1501f4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1501f8:
/*  f1501f8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1501fc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f150200:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f150204:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f150208:	03e00008 */ 	jr	$ra
/*  f15020c:	27bd04e0 */ 	addiu	$sp,$sp,0x4e0
);

// Mismatch: Goal stores arg2 to the stack then loads it after the call to
// pakReadBodyAtGuid. The below stores it in s2.
//bool func0f15015c(s8 device, s32 filenum, u8 *arg2)
//{
//	u8 stack[0x420];
//	u8 buffer[128];
//	s32 ret;
//	s32 i;
//
//	ret = pakReadBodyAtGuid(device, filenum, buffer, 128);
//
//	if (ret == 0) {
//		for (i = 0; i < 128; i++) {
//			arg2[i] = buffer[i];
//		}
//
//		return true;
//	}
//
//	if (ret == 10) {
//		s32 i;
//
//		for (i = 0; i < 128; i++) {
//			arg2[i] = random();
//		}
//
//		return true;
//	}
//
//	return false;
//}

GLOBAL_ASM(
glabel func0f150210
/*  f150210:	27bdfb20 */ 	addiu	$sp,$sp,-1248
/*  f150214:	2401ffff */ 	addiu	$at,$zero,-1
/*  f150218:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f15021c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f150220:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f150224:	afa404e0 */ 	sw	$a0,0x4e0($sp)
/*  f150228:	afa504e4 */ 	sw	$a1,0x4e4($sp)
/*  f15022c:	14e10003 */ 	bne	$a3,$at,.L0f15023c
/*  f150230:	afa604e8 */ 	sw	$a2,0x4e8($sp)
/*  f150234:	10000002 */ 	b	.L0f150240
/*  f150238:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f15023c:
/*  f15023c:	00e02025 */ 	or	$a0,$a3,$zero
.L0f150240:
/*  f150240:	0fc5281b */ 	jal	func0f14a06c
/*  f150244:	00000000 */ 	nop
/*  f150248:	00408025 */ 	or	$s0,$v0,$zero
/*  f15024c:	0fc5281b */ 	jal	func0f14a06c
/*  f150250:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f150254:	00408825 */ 	or	$s1,$v0,$zero
/*  f150258:	83a404e3 */ 	lb	$a0,0x4e3($sp)
/*  f15025c:	8fa504e4 */ 	lw	$a1,0x4e4($sp)
/*  f150260:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f150264:	0fc45a00 */ 	jal	pakReadBodyAtGuid
/*  f150268:	00003825 */ 	or	$a3,$zero,$zero
/*  f15026c:	14400076 */ 	bnez	$v0,.L0f150448
/*  f150270:	00401825 */ 	or	$v1,$v0,$zero
/*  f150274:	8fae04e4 */ 	lw	$t6,0x4e4($sp)
/*  f150278:	ae0e03f8 */ 	sw	$t6,0x3f8($s0)
/*  f15027c:	97af04ea */ 	lhu	$t7,0x4ea($sp)
/*  f150280:	12300003 */ 	beq	$s1,$s0,.L0f150290
/*  f150284:	a60f03fc */ 	sh	$t7,0x3fc($s0)
/*  f150288:	8e38001c */ 	lw	$t8,0x1c($s1)
/*  f15028c:	ae18001c */ 	sw	$t8,0x1c($s0)
.L0f150290:
/*  f150290:	97b900c6 */ 	lhu	$t9,0xc6($sp)
/*  f150294:	920c03f4 */ 	lbu	$t4,0x3f4($s0)
/*  f150298:	3c01447a */ 	lui	$at,0x447a
/*  f15029c:	00194bc2 */ 	srl	$t1,$t9,0xf
/*  f1502a0:	00095180 */ 	sll	$t2,$t1,0x6
/*  f1502a4:	314b0040 */ 	andi	$t3,$t2,0x40
/*  f1502a8:	318dffbf */ 	andi	$t5,$t4,0xffbf
/*  f1502ac:	016d6025 */ 	or	$t4,$t3,$t5
/*  f1502b0:	a20c03f4 */ 	sb	$t4,0x3f4($s0)
/*  f1502b4:	8faf00c4 */ 	lw	$t7,0xc4($sp)
/*  f1502b8:	318b00df */ 	andi	$t3,$t4,0xdf
/*  f1502bc:	44810000 */ 	mtc1	$at,$f0
/*  f1502c0:	000fc440 */ 	sll	$t8,$t7,0x11
/*  f1502c4:	001847c2 */ 	srl	$t0,$t8,0x1f
/*  f1502c8:	00084940 */ 	sll	$t1,$t0,0x5
/*  f1502cc:	312a0020 */ 	andi	$t2,$t1,0x20
/*  f1502d0:	014b6825 */ 	or	$t5,$t2,$t3
/*  f1502d4:	a20d03f4 */ 	sb	$t5,0x3f4($s0)
/*  f1502d8:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f1502dc:	02002025 */ 	or	$a0,$s0,$zero
/*  f1502e0:	27a30038 */ 	addiu	$v1,$sp,0x38
/*  f1502e4:	000e7c80 */ 	sll	$t7,$t6,0x12
/*  f1502e8:	000fc602 */ 	srl	$t8,$t7,0x18
/*  f1502ec:	ae1803a4 */ 	sw	$t8,0x3a4($s0)
/*  f1502f0:	97b900ba */ 	lhu	$t9,0xba($sp)
/*  f1502f4:	27a20046 */ 	addiu	$v0,$sp,0x46
/*  f1502f8:	ae1903bc */ 	sw	$t9,0x3bc($s0)
/*  f1502fc:	97a800bc */ 	lhu	$t0,0xbc($sp)
/*  f150300:	ae0803b8 */ 	sw	$t0,0x3b8($s0)
/*  f150304:	93a900c4 */ 	lbu	$t1,0xc4($sp)
/*  f150308:	920803f4 */ 	lbu	$t0,0x3f4($s0)
/*  f15030c:	ae09039c */ 	sw	$t1,0x39c($s0)
/*  f150310:	93ac00c5 */ 	lbu	$t4,0xc5($sp)
/*  f150314:	ae0c03a0 */ 	sw	$t4,0x3a0($s0)
/*  f150318:	93aa00be */ 	lbu	$t2,0xbe($sp)
/*  f15031c:	ae0a03c0 */ 	sw	$t2,0x3c0($s0)
/*  f150320:	93ab00bf */ 	lbu	$t3,0xbf($sp)
/*  f150324:	350a0010 */ 	ori	$t2,$t0,0x10
/*  f150328:	ae0b03c4 */ 	sw	$t3,0x3c4($s0)
/*  f15032c:	93ad00c0 */ 	lbu	$t5,0xc0($sp)
/*  f150330:	354b0080 */ 	ori	$t3,$t2,0x80
/*  f150334:	ae0d03c8 */ 	sw	$t5,0x3c8($s0)
/*  f150338:	93ae00c1 */ 	lbu	$t6,0xc1($sp)
/*  f15033c:	ae0e03cc */ 	sw	$t6,0x3cc($s0)
/*  f150340:	93af00c2 */ 	lbu	$t7,0xc2($sp)
/*  f150344:	ae0f03ec */ 	sw	$t7,0x3ec($s0)
/*  f150348:	93b800c3 */ 	lbu	$t8,0xc3($sp)
/*  f15034c:	a20a03f4 */ 	sb	$t2,0x3f4($s0)
/*  f150350:	a20b03f4 */ 	sb	$t3,0x3f4($s0)
/*  f150354:	ae1803f0 */ 	sw	$t8,0x3f0($s0)
/*  f150358:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f15035c:	0062082b */ 	sltu	$at,$v1,$v0
/*  f150360:	1020000a */ 	beqz	$at,.L0f15038c
/*  f150364:	846d008e */ 	lh	$t5,0x8e($v1)
.L0f150368:
/*  f150368:	448d9000 */ 	mtc1	$t5,$f18
/*  f15036c:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f150370:	0062082b */ 	sltu	$at,$v1,$v0
/*  f150374:	468094a0 */ 	cvt.s.w	$f18,$f18
/*  f150378:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f15037c:	46009483 */ 	div.s	$f18,$f18,$f0
/*  f150380:	e49203cc */ 	swc1	$f18,0x3cc($a0)
/*  f150384:	1420fff8 */ 	bnez	$at,.L0f150368
/*  f150388:	846d008e */ 	lh	$t5,0x8e($v1)
.L0f15038c:
/*  f15038c:	448d9000 */ 	mtc1	$t5,$f18
/*  f150390:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f150394:	468094a0 */ 	cvt.s.w	$f18,$f18
/*  f150398:	46009483 */ 	div.s	$f18,$f18,$f0
/*  f15039c:	e49203cc */ 	swc1	$f18,0x3cc($a0)
/*  f1503a0:	00001025 */ 	or	$v0,$zero,$zero
/*  f1503a4:	27a30038 */ 	addiu	$v1,$sp,0x38
.L0f1503a8:
/*  f1503a8:	8e0f0020 */ 	lw	$t7,0x20($s0)
/*  f1503ac:	906e009e */ 	lbu	$t6,0x9e($v1)
/*  f1503b0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1503b4:	01e2c021 */ 	addu	$t8,$t7,$v0
/*  f1503b8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1503bc:	28410400 */ 	slti	$at,$v0,0x400
/*  f1503c0:	1420fff9 */ 	bnez	$at,.L0f1503a8
/*  f1503c4:	a30e0000 */ 	sb	$t6,0x0($t8)
/*  f1503c8:	12300006 */ 	beq	$s1,$s0,.L0f1503e4
/*  f1503cc:	02202025 */ 	or	$a0,$s1,$zero
/*  f1503d0:	3c077f1b */ 	lui	$a3,%hi(var7f1b7158)
/*  f1503d4:	24e77158 */ 	addiu	$a3,$a3,%lo(var7f1b7158)
/*  f1503d8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1503dc:	0fc53143 */ 	jal	func0f14c50c
/*  f1503e0:	2406195e */ 	addiu	$a2,$zero,0x195e
.L0f1503e4:
/*  f1503e4:	0fc52803 */ 	jal	func0f14a00c
/*  f1503e8:	00002025 */ 	or	$a0,$zero,$zero
/*  f1503ec:	0fc5285b */ 	jal	func0f14a16c
/*  f1503f0:	24040005 */ 	addiu	$a0,$zero,0x5
/*  f1503f4:	0fc52f01 */ 	jal	func0f14bc04
/*  f1503f8:	00000000 */ 	nop
/*  f1503fc:	00001025 */ 	or	$v0,$zero,$zero
/*  f150400:	27a30038 */ 	addiu	$v1,$sp,0x38
/*  f150404:	24040080 */ 	addiu	$a0,$zero,0x80
.L0f150408:
/*  f150408:	8e280010 */ 	lw	$t0,0x10($s1)
/*  f15040c:	90790000 */ 	lbu	$t9,0x0($v1)
/*  f150410:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f150414:	01024821 */ 	addu	$t1,$t0,$v0
/*  f150418:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f15041c:	1444fffa */ 	bne	$v0,$a0,.L0f150408
/*  f150420:	a1390000 */ 	sb	$t9,0x0($t1)
/*  f150424:	12300006 */ 	beq	$s1,$s0,.L0f150440
/*  f150428:	02002025 */ 	or	$a0,$s0,$zero
/*  f15042c:	3c077f1b */ 	lui	$a3,%hi(var7f1b7164)
/*  f150430:	24e77164 */ 	addiu	$a3,$a3,%lo(var7f1b7164)
/*  f150434:	02202825 */ 	or	$a1,$s1,$zero
/*  f150438:	0fc53143 */ 	jal	func0f14c50c
/*  f15043c:	2406196d */ 	addiu	$a2,$zero,0x196d
.L0f150440:
/*  f150440:	10000004 */ 	b	.L0f150454
/*  f150444:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f150448:
/*  f150448:	3c01800a */ 	lui	$at,%hi(g_FilemgrLastPakError)
/*  f15044c:	ac2321f8 */ 	sw	$v1,%lo(g_FilemgrLastPakError)($at)
/*  f150450:	00001025 */ 	or	$v0,$zero,$zero
.L0f150454:
/*  f150454:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f150458:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f15045c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f150460:	03e00008 */ 	jr	$ra
/*  f150464:	27bd04e0 */ 	addiu	$sp,$sp,0x4e0
);

GLOBAL_ASM(
glabel func0f150468
/*  f150468:	27bdeb08 */ 	addiu	$sp,$sp,-5368
/*  f15046c:	afb0001c */ 	sw	$s0,0x1c($sp)
/*  f150470:	00048600 */ 	sll	$s0,$a0,0x18
/*  f150474:	00107603 */ 	sra	$t6,$s0,0x18
/*  f150478:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f15047c:	afb30028 */ 	sw	$s3,0x28($sp)
/*  f150480:	afb20024 */ 	sw	$s2,0x24($sp)
/*  f150484:	afa414f8 */ 	sw	$a0,0x14f8($sp)
/*  f150488:	00a09025 */ 	or	$s2,$a1,$zero
/*  f15048c:	30d3ffff */ 	andi	$s3,$a2,0xffff
/*  f150490:	01c08025 */ 	or	$s0,$t6,$zero
/*  f150494:	afb10020 */ 	sw	$s1,0x20($sp)
/*  f150498:	afa61500 */ 	sw	$a2,0x1500($sp)
/*  f15049c:	0fc5281b */ 	jal	func0f14a06c
/*  f1504a0:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f1504a4:	8c4f03f4 */ 	lw	$t7,0x3f4($v0)
/*  f1504a8:	00408825 */ 	or	$s1,$v0,$zero
/*  f1504ac:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f1504b0:	000fc8c0 */ 	sll	$t9,$t7,0x3
/*  f1504b4:	07200030 */ 	bltz	$t9,.L0f150578
/*  f1504b8:	27a90044 */ 	addiu	$t1,$sp,0x44
/*  f1504bc:	a0480036 */ 	sb	$t0,0x36($v0)
/*  f1504c0:	ac490024 */ 	sw	$t1,0x24($v0)
/*  f1504c4:	310500ff */ 	andi	$a1,$t0,0xff
.L0f1504c8:
/*  f1504c8:	0fc5401a */ 	jal	func0f150068
/*  f1504cc:	02202025 */ 	or	$a0,$s1,$zero
/*  f1504d0:	8e2a002c */ 	lw	$t2,0x2c($s1)
/*  f1504d4:	000a58c2 */ 	srl	$t3,$t2,0x3
/*  f1504d8:	316cffff */ 	andi	$t4,$t3,0xffff
/*  f1504dc:	2d810400 */ 	sltiu	$at,$t4,0x400
/*  f1504e0:	14200009 */ 	bnez	$at,.L0f150508
/*  f1504e4:	a7ab10d0 */ 	sh	$t3,0x10d0($sp)
/*  f1504e8:	922d0036 */ 	lbu	$t5,0x36($s1)
/*  f1504ec:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f1504f0:	31c500ff */ 	andi	$a1,$t6,0xff
/*  f1504f4:	28a1000c */ 	slti	$at,$a1,0xc
/*  f1504f8:	1420fff3 */ 	bnez	$at,.L0f1504c8
/*  f1504fc:	a22e0036 */ 	sb	$t6,0x36($s1)
/*  f150500:	100000a5 */ 	b	.L0f150798
/*  f150504:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f150508:
/*  f150508:	97af10d0 */ 	lhu	$t7,0x10d0($sp)
/*  f15050c:	00001025 */ 	or	$v0,$zero,$zero
/*  f150510:	24050400 */ 	addiu	$a1,$zero,0x400
/*  f150514:	51e0000d */ 	beqzl	$t7,.L0f15054c
/*  f150518:	97a210d0 */ 	lhu	$v0,0x10d0($sp)
/*  f15051c:	8e380024 */ 	lw	$t8,0x24($s1)
.L0f150520:
/*  f150520:	8e290020 */ 	lw	$t1,0x20($s1)
/*  f150524:	0302c821 */ 	addu	$t9,$t8,$v0
/*  f150528:	93280000 */ 	lbu	$t0,0x0($t9)
/*  f15052c:	01225021 */ 	addu	$t2,$t1,$v0
/*  f150530:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f150534:	a1480000 */ 	sb	$t0,0x0($t2)
/*  f150538:	97ab10d0 */ 	lhu	$t3,0x10d0($sp)
/*  f15053c:	004b082b */ 	sltu	$at,$v0,$t3
/*  f150540:	5420fff7 */ 	bnezl	$at,.L0f150520
/*  f150544:	8e380024 */ 	lw	$t8,0x24($s1)
/*  f150548:	97a210d0 */ 	lhu	$v0,0x10d0($sp)
.L0f15054c:
/*  f15054c:	28410400 */ 	slti	$at,$v0,0x400
/*  f150550:	50200007 */ 	beqzl	$at,.L0f150570
/*  f150554:	922f03f4 */ 	lbu	$t7,0x3f4($s1)
.L0f150558:
/*  f150558:	8e2c0020 */ 	lw	$t4,0x20($s1)
/*  f15055c:	01826821 */ 	addu	$t5,$t4,$v0
/*  f150560:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f150564:	1445fffc */ 	bne	$v0,$a1,.L0f150558
/*  f150568:	a1a00000 */ 	sb	$zero,0x0($t5)
/*  f15056c:	922f03f4 */ 	lbu	$t7,0x3f4($s1)
.L0f150570:
/*  f150570:	35f80010 */ 	ori	$t8,$t7,0x10
/*  f150574:	a23803f4 */ 	sb	$t8,0x3f4($s1)
.L0f150578:
/*  f150578:	8e3903f4 */ 	lw	$t9,0x3f4($s1)
/*  f15057c:	93ac10de */ 	lbu	$t4,0x10de($sp)
/*  f150580:	3c01447a */ 	lui	$at,0x447a
/*  f150584:	00194840 */ 	sll	$t1,$t9,0x1
/*  f150588:	000947c2 */ 	srl	$t0,$t1,0x1f
/*  f15058c:	000859c0 */ 	sll	$t3,$t0,0x7
/*  f150590:	318dff7f */ 	andi	$t5,$t4,0xff7f
/*  f150594:	016d5025 */ 	or	$t2,$t3,$t5
/*  f150598:	a3aa10de */ 	sb	$t2,0x10de($sp)
/*  f15059c:	8e2f03f4 */ 	lw	$t7,0x3f4($s1)
/*  f1505a0:	314c00bf */ 	andi	$t4,$t2,0xbf
/*  f1505a4:	44810000 */ 	mtc1	$at,$f0
/*  f1505a8:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1505ac:	0018cfc2 */ 	srl	$t9,$t8,0x1f
/*  f1505b0:	00194980 */ 	sll	$t1,$t9,0x6
/*  f1505b4:	31280040 */ 	andi	$t0,$t1,0x40
/*  f1505b8:	010c5825 */ 	or	$t3,$t0,$t4
/*  f1505bc:	a3ab10de */ 	sb	$t3,0x10de($sp)
/*  f1505c0:	922d03a7 */ 	lbu	$t5,0x3a7($s1)
/*  f1505c4:	97b910de */ 	lhu	$t9,0x10de($sp)
/*  f1505c8:	24050400 */ 	addiu	$a1,$zero,0x400
/*  f1505cc:	000d7980 */ 	sll	$t7,$t5,0x6
/*  f1505d0:	31f83fc0 */ 	andi	$t8,$t7,0x3fc0
/*  f1505d4:	3329c03f */ 	andi	$t1,$t9,0xc03f
/*  f1505d8:	03097025 */ 	or	$t6,$t8,$t1
/*  f1505dc:	a7ae10de */ 	sh	$t6,0x10de($sp)
/*  f1505e0:	8e2a03bc */ 	lw	$t2,0x3bc($s1)
/*  f1505e4:	27a31050 */ 	addiu	$v1,$sp,0x1050
/*  f1505e8:	02202025 */ 	or	$a0,$s1,$zero
/*  f1505ec:	a7aa10d2 */ 	sh	$t2,0x10d2($sp)
/*  f1505f0:	8e2803b8 */ 	lw	$t0,0x3b8($s1)
/*  f1505f4:	27a2105e */ 	addiu	$v0,$sp,0x105e
/*  f1505f8:	a7a810d4 */ 	sh	$t0,0x10d4($sp)
/*  f1505fc:	8e2c039c */ 	lw	$t4,0x39c($s1)
/*  f150600:	a3ac10dc */ 	sb	$t4,0x10dc($sp)
/*  f150604:	8e2b03a0 */ 	lw	$t3,0x3a0($s1)
/*  f150608:	a3ab10dd */ 	sb	$t3,0x10dd($sp)
/*  f15060c:	8e2d03c0 */ 	lw	$t5,0x3c0($s1)
/*  f150610:	a3ad10d6 */ 	sb	$t5,0x10d6($sp)
/*  f150614:	8e2f03c4 */ 	lw	$t7,0x3c4($s1)
/*  f150618:	a3af10d7 */ 	sb	$t7,0x10d7($sp)
/*  f15061c:	8e3903c8 */ 	lw	$t9,0x3c8($s1)
/*  f150620:	a3b910d8 */ 	sb	$t9,0x10d8($sp)
/*  f150624:	8e3803cc */ 	lw	$t8,0x3cc($s1)
/*  f150628:	a3b810d9 */ 	sb	$t8,0x10d9($sp)
/*  f15062c:	8e2903ec */ 	lw	$t1,0x3ec($s1)
/*  f150630:	a3a910da */ 	sb	$t1,0x10da($sp)
/*  f150634:	8e2e03f0 */ 	lw	$t6,0x3f0($s1)
/*  f150638:	a3ae10db */ 	sb	$t6,0x10db($sp)
/*  f15063c:	c49003d0 */ 	lwc1	$f16,0x3d0($a0)
/*  f150640:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f150644:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f150648:	5062000c */ 	beql	$v1,$v0,.L0f15067c
/*  f15064c:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f150650:	4600940d */ 	trunc.w.s	$f16,$f18
.L0f150654:
/*  f150654:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f150658:	24630002 */ 	addiu	$v1,$v1,0x2
/*  f15065c:	44088000 */ 	mfc1	$t0,$f16
/*  f150660:	00000000 */ 	nop
/*  f150664:	a468008c */ 	sh	$t0,0x8c($v1)
/*  f150668:	c49003d0 */ 	lwc1	$f16,0x3d0($a0)
/*  f15066c:	46008482 */ 	mul.s	$f18,$f16,$f0
/*  f150670:	5462fff8 */ 	bnel	$v1,$v0,.L0f150654
/*  f150674:	4600940d */ 	trunc.w.s	$f16,$f18
/*  f150678:	4600940d */ 	trunc.w.s	$f16,$f18
.L0f15067c:
/*  f15067c:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f150680:	44088000 */ 	mfc1	$t0,$f16
/*  f150684:	00000000 */ 	nop
/*  f150688:	a468008e */ 	sh	$t0,0x8e($v1)
/*  f15068c:	00001025 */ 	or	$v0,$zero,$zero
/*  f150690:	27a31050 */ 	addiu	$v1,$sp,0x1050
.L0f150694:
/*  f150694:	8e2c0010 */ 	lw	$t4,0x10($s1)
/*  f150698:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f15069c:	01825821 */ 	addu	$t3,$t4,$v0
/*  f1506a0:	916d0000 */ 	lbu	$t5,0x0($t3)
/*  f1506a4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1506a8:	28410080 */ 	slti	$at,$v0,0x80
/*  f1506ac:	1420fff9 */ 	bnez	$at,.L0f150694
/*  f1506b0:	a06dffff */ 	sb	$t5,-0x1($v1)
/*  f1506b4:	00001025 */ 	or	$v0,$zero,$zero
/*  f1506b8:	27a31050 */ 	addiu	$v1,$sp,0x1050
.L0f1506bc:
/*  f1506bc:	8e2f0020 */ 	lw	$t7,0x20($s1)
/*  f1506c0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1506c4:	01e2c821 */ 	addu	$t9,$t7,$v0
/*  f1506c8:	93380000 */ 	lbu	$t8,0x0($t9)
/*  f1506cc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1506d0:	1445fffa */ 	bne	$v0,$a1,.L0f1506bc
/*  f1506d4:	a078009d */ 	sb	$t8,0x9d($v1)
/*  f1506d8:	00102600 */ 	sll	$a0,$s0,0x18
/*  f1506dc:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f1506e0:	3c018007 */ 	lui	$at,%hi(g_FileLists+0x1c)
/*  f1506e4:	00047603 */ 	sra	$t6,$a0,0x18
/*  f1506e8:	27aa1044 */ 	addiu	$t2,$sp,0x1044
/*  f1506ec:	ac295bdc */ 	sw	$t1,%lo(g_FileLists+0x1c)($at)
/*  f1506f0:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f1506f4:	01c02025 */ 	or	$a0,$t6,$zero
/*  f1506f8:	02402825 */ 	or	$a1,$s2,$zero
/*  f1506fc:	24060008 */ 	addiu	$a2,$zero,0x8
/*  f150700:	27a71050 */ 	addiu	$a3,$sp,0x1050
/*  f150704:	0fc45a0a */ 	jal	pakSaveAtGuid
/*  f150708:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f15070c:	1440001f */ 	bnez	$v0,.L0f15078c
/*  f150710:	00401825 */ 	or	$v1,$v0,$zero
/*  f150714:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f150718:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f15071c:	00008025 */ 	or	$s0,$zero,$zero
.L0f150720:
/*  f150720:	0fc5281b */ 	jal	func0f14a06c
/*  f150724:	02002025 */ 	or	$a0,$s0,$zero
/*  f150728:	8e2803f8 */ 	lw	$t0,0x3f8($s1)
/*  f15072c:	8c4c03f8 */ 	lw	$t4,0x3f8($v0)
/*  f150730:	550c000e */ 	bnel	$t0,$t4,.L0f15076c
/*  f150734:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f150738:	962b03fc */ 	lhu	$t3,0x3fc($s1)
/*  f15073c:	944d03fc */ 	lhu	$t5,0x3fc($v0)
/*  f150740:	8faf1044 */ 	lw	$t7,0x1044($sp)
/*  f150744:	2a01000c */ 	slti	$at,$s0,0xc
/*  f150748:	556d0008 */ 	bnel	$t3,$t5,.L0f15076c
/*  f15074c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f150750:	ac4f03f8 */ 	sw	$t7,0x3f8($v0)
/*  f150754:	14200004 */ 	bnez	$at,.L0f150768
/*  f150758:	a45303fc */ 	sh	$s3,0x3fc($v0)
/*  f15075c:	8e590458 */ 	lw	$t9,0x458($s2)
/*  f150760:	37380001 */ 	ori	$t8,$t9,0x1
/*  f150764:	ae580458 */ 	sw	$t8,0x458($s2)
.L0f150768:
/*  f150768:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f15076c:
/*  f15076c:	24010012 */ 	addiu	$at,$zero,0x12
/*  f150770:	1601ffeb */ 	bne	$s0,$at,.L0f150720
/*  f150774:	00000000 */ 	nop
/*  f150778:	8fa91044 */ 	lw	$t1,0x1044($sp)
/*  f15077c:	a63303fc */ 	sh	$s3,0x3fc($s1)
/*  f150780:	00001025 */ 	or	$v0,$zero,$zero
/*  f150784:	10000004 */ 	b	.L0f150798
/*  f150788:	ae2903f8 */ 	sw	$t1,0x3f8($s1)
.L0f15078c:
/*  f15078c:	3c01800a */ 	lui	$at,%hi(g_FilemgrLastPakError)
/*  f150790:	ac2321f8 */ 	sw	$v1,%lo(g_FilemgrLastPakError)($at)
/*  f150794:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f150798:
/*  f150798:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f15079c:	8fb0001c */ 	lw	$s0,0x1c($sp)
/*  f1507a0:	8fb10020 */ 	lw	$s1,0x20($sp)
/*  f1507a4:	8fb20024 */ 	lw	$s2,0x24($sp)
/*  f1507a8:	8fb30028 */ 	lw	$s3,0x28($sp)
/*  f1507ac:	03e00008 */ 	jr	$ra
/*  f1507b0:	27bd14f8 */ 	addiu	$sp,$sp,0x14f8
);

void phGetGuid(s32 index, struct fileguid *guid)
{
	struct var8007f8e0 *thing = func0f14a06c(index);

	guid->fileid = thing->fileguid.fileid;
	guid->deviceserial = thing->fileguid.deviceserial;
}

void phSetFileId(s32 fileid)
{
	struct var8007f8e0 *thing = func0f14a06c(-1);

	thing->fileguid.deviceserial = 0;
	thing->fileguid.fileid = fileid;
}
