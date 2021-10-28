#include <ultra64.h>
#include "constants.h"
#include "bss.h"
#include "lib/lib_13790.h"
#include "data.h"
#include "types.h"

#define NUM_COLS 80
#define NUM_ROWS 35

struct dhudchar {
	char c;
	u8 paletteindex;
};

#if VERSION < VERSION_NTSC_1_0
struct dhudchar g_DHudCharBuffer[NUM_COLS][NUM_ROWS];
Gfx g_DHudFgGbi[32];
Gfx g_DHudBgGbi[32];

u32 var800606e0nb[] = {
	0xb8000000, 0x00000000, 0x00000000, 0x00227a00,
	0x007a348b, 0x00223434, 0x00115811, 0x00696900,
	0x00000000, 0x00009c00, 0x00004600, 0x00460000,
	0x00004600, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000046, 0x00229c11, 0x00346900,
	0x00229c11, 0x00699c11, 0x00005834, 0x00adad34,
	0x00118b34, 0x009cad7a, 0x00229c11, 0x00229c11,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00113411, 0x00000000, 0x0046ce00,
	0x00ad58de, 0x00466969, 0x009c9c69, 0x008b8b00,
	0x00469c00, 0x0022ce00, 0x00583400, 0x00345800,
	0x007ace69, 0x00005800, 0x00000000, 0x00000000,
	0x00000000, 0x00003446, 0x008b007a, 0x00588b00,
	0x008b008b, 0x0022007a, 0x00119c69, 0x008b0000,
	0x009c1100, 0x0022008b, 0x008b007a, 0x008b007a,
	0x00000000, 0x00000000, 0x00225869, 0x00000000,
	0x69582200, 0x009c698b, 0x00000000, 0x0046ce00,
	0x00222258, 0x00deef7a, 0x00ad1111, 0x0069ef9c,
	0x008b0000, 0x00460000, 0x008b0000, 0x00008b00,
	0x0058ce34, 0x00008b00, 0x00000000, 0x00000000,
	0x00000000, 0x00008b00, 0x008b008b, 0x00008b00,
	0x0011007a, 0x00118b46, 0x0058467a, 0x00cead22,
	0x009c8b00, 0x0000117a, 0x00698b46, 0x008b00ad,
	0x0034ad00, 0x0034ad00, 0x228b4600, 0x8b8b8b8b,
	0x00468b22, 0x0011008b, 0x00000000, 0x00007a00,
	0x00000000, 0x009c9c00, 0x00118b34, 0x22adbd46,
	0x008b8b34, 0x00000000, 0x008b0000, 0x00008b00,
	0x007a2269, 0x22adef9c, 0x00000000, 0x22adadad,
	0x00000000, 0x00226900, 0x008b008b, 0x00008b00,
	0x00007a00, 0x0000117a, 0x009c347a, 0x0000008b,
	0x00ce117a, 0x00002269, 0x008b227a, 0x00229c8b,
	0x00001100, 0x00001100, 0xad580000, 0x34343434,
	0x000058ad, 0x0000bd34, 0x00000000, 0x00112200,
	0x00000000, 0x22dede22, 0x00ce5858, 0x0046468b,
	0x008bad00, 0x00000000, 0x008b0000, 0x00008b00,
	0x00000000, 0x00008b00, 0x00003400, 0x00000000,
	0x00002200, 0x00691100, 0x008b008b, 0x00008b00,
	0x00691158, 0x0011008b, 0x007a9cad, 0x1122008b,
	0x008b008b, 0x00008b00, 0x008b008b, 0x0000227a,
	0x00002200, 0x00002200, 0x228b4600, 0x8b8b8b8b,
	0x00468b22, 0x00006900, 0x00000000, 0x00228b00,
	0x00000000, 0x008b8b00, 0x0034bd00, 0x00119c46,
	0x007a6969, 0x00000000, 0x00583400, 0x00345800,
	0x00000000, 0x00005800, 0x0011ff00, 0x00000000,
	0x00228b00, 0x008b0000, 0x00349c22, 0x008bce69,
	0x22bdad8b, 0x007a9c11, 0x00008b8b, 0x118b9c11,
	0x00349c22, 0x00005800, 0x00349c11, 0x00588b11,
	0x00228b00, 0x0069ad00, 0x00225869, 0x00000000,
	0x69582200, 0x0000bd00, 0x00000000, 0x00000000,
	0x00000000, 0x00464600, 0x00004600, 0x00000000,
	0x00000000, 0x00000000, 0x00004600, 0x00460000,
	0x00000000, 0x00000000, 0x00583400, 0x00000000,
	0x00000000, 0x58340000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x008b0000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00229c11, 0x00221100,
	0x11223400, 0x00003411, 0x11342200, 0x00343422,
	0x00343422, 0x00002222, 0x00220022, 0x00342222,
	0x00003434, 0x00341122, 0x22341100, 0x11110022,
	0x22221134, 0x00002200, 0x00343411, 0x00003400,
	0x00343411, 0x00113411, 0x00343434, 0x11341134,
	0x11220034, 0x34220034, 0x11340022, 0x11220034,
	0x00223422, 0x00008b34, 0x00460000, 0x00587a00,
	0x00005800, 0x00000000, 0x348b008b, 0x0069bd00,
	0x11de7a58, 0x00ad69de, 0x22ce7a9c, 0x11ce7aad,
	0x11ce7aad, 0x00ad7ade, 0x22ce00ce, 0x0069ce58,
	0x00008bce, 0x22ce22ce, 0x46ce4600, 0x7abd00ff,
	0x58ff46ce, 0x00ad7a9c, 0x11ce7a7a, 0x00ad7a8b,
	0x22ce7a7a, 0x118b7abd, 0x469ccece, 0x8b8b34ce,
	0x8b8b00bd, 0xbd8b22bd, 0x58ce00ce, 0x22bd00ce,
	0x00bd7aad, 0x00008b00, 0x007a1100, 0x00008b00,
	0x00694658, 0x00000000, 0x468b7abd, 0x00588b22,
	0x008b008b, 0x46460011, 0x008b007a, 0x118b3458,
	0x008b3458, 0x46460011, 0x008b008b, 0x00008b00,
	0x0000117a, 0x008b7a11, 0x008b0000, 0x589c58bd,
	0x11ad698b, 0x4646007a, 0x118b007a, 0x5846007a,
	0x118b007a, 0x46580011, 0x34228b46, 0x6934008b,
	0x007a008b, 0x58348b7a, 0x11696946, 0x00695846,
	0x00113458, 0x00008b00, 0x00116900, 0x00008b00,
	0x00110011, 0x00000000, 0x468b8b9c, 0x009c228b,
	0x00dead7a, 0x58340000, 0x008b007a, 0x11dead00,
	0x00dead00, 0x583400ad, 0x46deadbd, 0x00008b00,
	0x3411117a, 0x00dead00, 0x008b0000, 0x5846ad7a,
	0x118b8b8b, 0x5834007a, 0x11dead34, 0x5834007a,
	0x11dede46, 0x0058ad34, 0x00008b00, 0x5834008b,
	0x008b117a, 0x00bdde8b, 0x0022ad00, 0x0011bd00,
	0x00226900, 0x00008b00, 0x00008b00, 0x00008b00,
	0x00000000, 0x00000000, 0x348b348b, 0x469c8bad,
	0x008b007a, 0x347a0058, 0x008b009c, 0x008b008b,
	0x008b0000, 0x228b007a, 0x008b008b, 0x00008b00,
	0x46462269, 0x008b117a, 0x008b007a, 0x6934347a,
	0x118b34de, 0x118b009c, 0x008b0000, 0x228b009c,
	0x008b117a, 0x3434008b, 0x00008b00, 0x4646008b,
	0x0022ce00, 0x00adbd8b, 0x008b007a, 0x00008b00,
	0x008b0058, 0x00008b00, 0x00003446, 0x00008b00,
	0x00000000, 0x00000000, 0x00697a9c, 0x7a9c00bd,
	0x69cead58, 0x0058ad58, 0x22bdad34, 0x22cead8b,
	0x22bd2200, 0x0058ad58, 0x22ad00ce, 0x008bbd7a,
	0x007a7a00, 0x22bd228b, 0x69bdadbd, 0x8b9c00bd,
	0x69ce227a, 0x0058ad34, 0x22ce6900, 0x009cef69,
	0x22bd2258, 0x7a9c9c22, 0x0046ce34, 0x007aad11,
	0x00005800, 0x00580058, 0x22ad00ce, 0x0058bd34,
	0x00ad9c9c, 0x00008b00, 0x0000008b, 0x00008b00,
	0x00000000, 0x22222222, 0x00002211, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x0058588b,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x0000ce34, 0x0000007a, 0x1158ad00,
	0x00000000, 0x7a7a7a7a, 0x00693400, 0x00000000,
	0x22690000, 0x00000000, 0x0000008b, 0x00000000,
	0x0000589c, 0x11000000, 0x22690000, 0x00001100,
	0x00001100, 0x22690000, 0x008b7a00, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00004646, 0x00004600, 0x00464600,
	0x00000000, 0x00000000, 0x0046ad00, 0x00000000,
	0x008b0000, 0x00000000, 0x0000008b, 0x00000000,
	0x00116900, 0x00000000, 0x008b0000, 0x00006900,
	0x00006900, 0x008b0000, 0x00008b00, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00226900, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00008b00, 0x00008b00, 0x00008b00,
	0x00000000, 0x00000000, 0x00005800, 0x008b9c34,
	0x00cead69, 0x007aad9c, 0x008badbd, 0x007aad34,
	0x009cde7a, 0x008b9cce, 0x11cead69, 0x00589c00,
	0x008bad69, 0x008bad69, 0x00008b00, 0x7aad9c9c,
	0x22cead69, 0x007aad34, 0x22cead69, 0x008b9cde,
	0x22de9c69, 0x007aad9c, 0x009cde7a, 0x118b00ad,
	0x11ce00de, 0x34ce00de, 0x22ce34ad, 0x22ce00de,
	0x00bd9cad, 0x00008b00, 0x00008b00, 0x00008b00,
	0x229c347a, 0x00000000, 0x00000000, 0x009cad7a,
	0x008b007a, 0x69340034, 0x4634009c, 0x46ce9cbd,
	0x00226900, 0x4646008b, 0x008b008b, 0x00008b00,
	0x0000007a, 0x00de7a00, 0x00008b00, 0x46468b69,
	0x119c008b, 0x4646008b, 0x008b0069, 0x5846008b,
	0x008b0000, 0x008b7a58, 0x00226900, 0x008b008b,
	0x007a117a, 0x008b8b8b, 0x0058bd00, 0x008b008b,
	0x00464646, 0x00467a00, 0x00008b00, 0x00008b46,
	0x7a349c22, 0x00000000, 0x00000000, 0x4634227a,
	0x009c007a, 0x58460022, 0x4646009c, 0x34460034,
	0x00226900, 0x3446009c, 0x008b008b, 0x00008b00,
	0x0000007a, 0x008b6911, 0x00008b00, 0x46468b69,
	0x118b008b, 0x3458008b, 0x00ad0069, 0x584600ad,
	0x008b0000, 0x0069348b, 0x00226911, 0x008b009c,
	0x0011de00, 0x00adbd8b, 0x00699c11, 0x00469c34,
	0x00225858, 0x00008b00, 0x00008b00, 0x00008b00,
	0x00000000, 0x00000000, 0x00000000, 0x119c8bce,
	0x22adad58, 0x007a9c46, 0x0069adad, 0x1169ad46,
	0x008bbd7a, 0x0069adad, 0x22ad00bd, 0x118bce69,
	0x0000007a, 0x227a34ce, 0x008bbd7a, 0x7a699c46,
	0x69bd00ce, 0x007a9c22, 0x00bd9c58, 0x0069adad,
	0x22ce9c34, 0x008bad58, 0x00009c8b, 0x00699cad,
	0x11005800, 0x00580069, 0x11bd349c, 0x00009c00,
	0x00adad9c, 0x00008b00, 0x00008b00, 0x00008b00,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x0000008b, 0x00000000, 0x00000000,
	0x00004646, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x008b0000, 0x0000008b,
	0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00226900,
	0x00000000, 0x00008b46, 0x00008b00, 0x00467a00,
	0x00000000, 0x00000000,
};

s32 g_DHudBaseX = 5;
s32 g_DHudBaseY = 1;
s32 g_DHudPosX = 24;
s32 g_DHudPosY = 16;
bool g_DHudIsEmpty = true;
bool g_DHudInitialised = false;

u32 var80061180nb[] = {
	0xe7000000, 0x00000000, 0xba001402, 0x00000000,
	0xba000602, 0x000000c0, 0xb900031d, 0x500a4240,
	0xfc30b261, 0x5566db6d, 0xba001301, 0x00000000,
	0xba000e02, 0x00000000, 0xb9000002, 0x00000000,
	0xfd700000, 0x800606e8, 0xf5700000, 0x07000000,
	0xe6000000, 0x00000000, 0xf3000000, 0x0753f080,
	0xe7000000, 0x00000000, 0xf5682000, 0x00000000,
	0xf2000000, 0x001fc050, 0xe6000000, 0x00000000,
	0xb8000000, 0x00000000,
};

struct dhudchar (*g_DHudCharBufferPtr)[NUM_ROWS] = NULL;
Gfx *g_DHudFgGbiPtrs = NULL;
Gfx *g_DHudBgGbiPtrs = NULL;
s32 g_DHudNextPaletteIndex = 0;
u32 var80061218nb = 0xb8000000;
u32 var8006121cnb = 0x00000000;
u32 var80061220nb = 0xc0000000;
u32 var80061224nb = 0x00000000;
Gfx g_DHudFgColour = gsDPSetPrimColor(0, 0, 0xff, 0xff, 0xff, 0);
Gfx g_DHudBgColour = gsDPSetEnvColor(0, 0, 0, 0);
#endif

#if VERSION < VERSION_NTSC_1_0
s32 dhud00013fe0nb(s32 arg0, s32 arg1)
{
	return 0;
}
#endif

#if VERSION < VERSION_NTSC_1_0
s32 dhud00013ff0nb(s32 arg0, s32 arg1)
{
	return 0;
}
#endif

#if VERSION < VERSION_NTSC_1_0
void dhud00014000nb(void)
{
	// empty
}
#endif

void dhudInit(void)
{
#if VERSION < VERSION_NTSC_1_0
	s32 i;
	s32 x;
	s32 y;
	u32 stack;

	Gfx cmd = {0, 0};

	g_DHudCharBufferPtr = g_DHudCharBuffer;
	g_DHudFgGbiPtrs = g_DHudFgGbi;
	g_DHudBgGbiPtrs = g_DHudBgGbi;

	g_DHudInitialised = true;

	for (x = 0; x < NUM_COLS; x++) {
		for (y = 0; y < NUM_ROWS; y++) {
			g_DHudCharBufferPtr[x][y].c = '\0';
			g_DHudCharBufferPtr[x][y].paletteindex = 0;
		}
	}

	for (i = 0; i < 32; i++) {
		g_DHudFgGbiPtrs[i] = cmd;
		g_DHudBgGbiPtrs[i] = cmd;
	}
#endif
}

void dhudTryReset(void)
{
#if VERSION < VERSION_NTSC_1_0
	if (g_DHudInitialised) {
		dhudReset();
	}
#endif
}

#if VERSION >= VERSION_NTSC_1_0
void func000137a0(void)
{
	// empty
}

void func000137a8(void)
{
	// empty
}
#endif

#if VERSION < VERSION_NTSC_1_0
void dhudPutCharAt(s32 x, s32 y, char c)
{
	s32 i;

	// Check if the current colour pair exists in the palette
	for (i = 0; i < 32; i++) {
		if (g_DHudFgColour.words.w1 == g_DHudFgGbiPtrs[i].words.w1
				&& g_DHudBgColour.words.w1 == g_DHudBgGbiPtrs[i].words.w1) {
			goto havepalette;
		}
	}

	// Add colours to pallete
	g_DHudFgGbiPtrs[g_DHudNextPaletteIndex] = g_DHudFgColour;
	g_DHudBgGbiPtrs[g_DHudNextPaletteIndex] = g_DHudBgColour;

	i = g_DHudNextPaletteIndex = (g_DHudNextPaletteIndex + 1) % 32;

havepalette:
	g_DHudCharBufferPtr[x][y].c = c;
	g_DHudCharBufferPtr[x][y].paletteindex = i;

	if (c != '\0') {
		g_DHudIsEmpty = false;
	}
}
#endif

#if VERSION < VERSION_NTSC_1_0
void dhudResetPos(void)
{
	if (g_DHudInitialised) {
		g_DHudPosX = g_DHudBaseX;
		g_DHudPosY = g_DHudBaseY;
	}
}
#endif

#if VERSION < VERSION_NTSC_1_0
void dhudReset(void)
{
	s32 x;
	s32 y;

	if (g_DHudInitialised && g_DHudIsEmpty != true) {
		for (y = 0; y < NUM_ROWS; y++) {
			for (x = 0; x < NUM_COLS; x++) {
				dhudPutCharAt(x, y, '\0');
			}
		}

		g_DHudIsEmpty = true;

		dhudResetPos();
		dhud00014000nb();

		g_DHudNextPaletteIndex = 0;
	}
}
#endif

void dhudSetPos(s32 x, s32 y)
{
#if VERSION < VERSION_NTSC_1_0
	if (g_DHudInitialised) {
		x += g_DHudBaseX;
		y += g_DHudBaseY;

		if (y >= (viGetHeight() - 10) / 7) {
			y = (viGetHeight() - 10) / 7 - 1;
		}

		g_DHudPosX = x;
		g_DHudPosY = y;
	}
#endif
}

void dhudSetFgColour(s32 r, s32 g, s32 b, s32 a)
{
#if VERSION < VERSION_NTSC_1_0
	if (g_DHudInitialised) {
		g_DHudFgColour.words.w1 = r << 24 | g << 16 | b << 8 | (255 - a);
	}
#endif
}

void dhudSetBgColour(s32 r, s32 g, s32 b, s32 a)
{
#if VERSION < VERSION_NTSC_1_0
	if (g_DHudInitialised) {
		g_DHudBgColour.words.w1 = r << 24 | g << 16 | b << 8 | (255 - a);
	}
#endif
}

void dhudPrintChar(u8 c)
{
#if VERSION < VERSION_NTSC_1_0
	s32 maxwidth = (viGetWidth() - 13) / 4;
	s32 maxheight = (viGetHeight() - 10) / 7;

	if (g_DHudInitialised) {
		if (c == '\0' || (c >= ' ' && c <= '~')) {
			dhudPutCharAt(g_DHudPosX, g_DHudPosY, c);
		}

		g_DHudPosX++;

		if (c == '\r' || c == '\n' || g_DHudPosX >= maxwidth) {
			g_DHudPosX = g_DHudBaseX;
			g_DHudPosY++;

			if (g_DHudPosY >= maxheight) {
				g_DHudPosY = g_DHudBaseY;
			}
		}
	}
#endif
}

void dhudPrintCharAt(s32 x, s32 y, char c)
{
#if VERSION < VERSION_NTSC_1_0
	if (g_DHudInitialised) {
		dhudSetPos(x, y);
		dhudPrintChar(c);
	}
#endif
}

void dhudPrintString(char *str)
{
#if VERSION < VERSION_NTSC_1_0
	if (g_DHudInitialised) {
		while (*str != '\0') {
			dhudPrintChar(*str++);
		}
	}
#endif
}

void dhudPrintStringAt(s32 x, s32 y, char *str)
{
#if VERSION < VERSION_NTSC_1_0
	if (g_DHudInitialised) {
		dhudSetPos(x, y);

		while (*str != '\0') {
			dhudPrintChar(*str++);
		}
	}
#endif
}

#if VERSION >= VERSION_NTSC_1_0
Gfx *dhudRender(Gfx *gdl)
{
	return gdl;
}
#else
u32 var80061240nb = 0x000000ff;

GLOBAL_ASM(
glabel dhudRender
/*    14684:	27bdff78 */ 	addiu	$sp,$sp,-136
/*    14688:	3c0e8006 */ 	lui	$t6,0x8006
/*    1468c:	8dce117c */ 	lw	$t6,0x117c($t6)
/*    14690:	afb00018 */ 	sw	$s0,0x18($sp)
/*    14694:	00808025 */ 	or	$s0,$a0,$zero
/*    14698:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    1469c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*    146a0:	afb70034 */ 	sw	$s7,0x34($sp)
/*    146a4:	afb60030 */ 	sw	$s6,0x30($sp)
/*    146a8:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    146ac:	afb40028 */ 	sw	$s4,0x28($sp)
/*    146b0:	afb30024 */ 	sw	$s3,0x24($sp)
/*    146b4:	afb20020 */ 	sw	$s2,0x20($sp)
/*    146b8:	15c00003 */ 	bnez	$t6,.NB000146c8
/*    146bc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    146c0:	100000a5 */ 	beqz	$zero,.NB00014958
/*    146c4:	00801025 */ 	or	$v0,$a0,$zero
.NB000146c8:
/*    146c8:	3c0f8006 */ 	lui	$t7,0x8006
/*    146cc:	8def1178 */ 	lw	$t7,0x1178($t7)
/*    146d0:	02008825 */ 	or	$s1,$s0,$zero
/*    146d4:	2406ffff */ 	addiu	$a2,$zero,-1
/*    146d8:	15e0009e */ 	bnez	$t7,.NB00014954
/*    146dc:	0000a025 */ 	or	$s4,$zero,$zero
/*    146e0:	3c078006 */ 	lui	$a3,0x8006
/*    146e4:	8ce71208 */ 	lw	$a3,0x1208($a3)
/*    146e8:	00004025 */ 	or	$t0,$zero,$zero
/*    146ec:	24090050 */ 	addiu	$t1,$zero,0x50
/*    146f0:	00002825 */ 	or	$a1,$zero,$zero
.NB000146f4:
/*    146f4:	00e82021 */ 	addu	$a0,$a3,$t0
.NB000146f8:
/*    146f8:	90820000 */ 	lbu	$v0,0x0($a0)
/*    146fc:	24a50001 */ 	addiu	$a1,$a1,0x1
/*    14700:	90830001 */ 	lbu	$v1,0x1($a0)
/*    14704:	10400006 */ 	beqz	$v0,.NB00014720
/*    14708:	00000000 */ 	sll	$zero,$zero,0x0
/*    1470c:	50660004 */ 	beql	$v1,$a2,.NB00014720
/*    14710:	26310018 */ 	addiu	$s1,$s1,0x18
/*    14714:	26310010 */ 	addiu	$s1,$s1,0x10
/*    14718:	00603025 */ 	or	$a2,$v1,$zero
/*    1471c:	26310018 */ 	addiu	$s1,$s1,0x18
.NB00014720:
/*    14720:	14a9fff5 */ 	bne	$a1,$t1,.NB000146f8
/*    14724:	24840046 */ 	addiu	$a0,$a0,0x46
/*    14728:	25080002 */ 	addiu	$t0,$t0,0x2
/*    1472c:	29010046 */ 	slti	$at,$t0,0x46
/*    14730:	5420fff0 */ 	bnezl	$at,.NB000146f4
/*    14734:	00002825 */ 	or	$a1,$zero,$zero
/*    14738:	0fc588f2 */ 	jal	gfxGetFreeGfx
/*    1473c:	02002025 */ 	or	$a0,$s0,$zero
/*    14740:	02302023 */ 	subu	$a0,$s1,$s0
/*    14744:	1c800003 */ 	bgtz	$a0,.NB00014754
/*    14748:	24090050 */ 	addiu	$t1,$zero,0x50
/*    1474c:	10000082 */ 	beqz	$zero,.NB00014958
/*    14750:	02001025 */ 	or	$v0,$s0,$zero
.NB00014754:
/*    14754:	2443f800 */ 	addiu	$v1,$v0,-2048
/*    14758:	1c600004 */ 	bgtz	$v1,.NB0001476c
/*    1475c:	2413ffff */ 	addiu	$s3,$zero,-1
/*    14760:	3c018006 */ 	lui	$at,0x8006
/*    14764:	10000017 */ 	beqz	$zero,.NB000147c4
/*    14768:	ac201240 */ 	sw	$zero,0x1240($at)
.NB0001476c:
/*    1476c:	0064082a */ 	slt	$at,$v1,$a0
/*    14770:	10200011 */ 	beqz	$at,.NB000147b8
/*    14774:	0003c200 */ 	sll	$t8,$v1,0x8
/*    14778:	0303c023 */ 	subu	$t8,$t8,$v1
/*    1477c:	0304001a */ 	div	$zero,$t8,$a0
/*    14780:	14800002 */ 	bnez	$a0,.NB0001478c
/*    14784:	00000000 */ 	sll	$zero,$zero,0x0
/*    14788:	0007000d */ 	break	0x7
.NB0001478c:
/*    1478c:	2401ffff */ 	addiu	$at,$zero,-1
/*    14790:	14810004 */ 	bne	$a0,$at,.NB000147a4
/*    14794:	3c018000 */ 	lui	$at,0x8000
/*    14798:	17010002 */ 	bne	$t8,$at,.NB000147a4
/*    1479c:	00000000 */ 	sll	$zero,$zero,0x0
/*    147a0:	0006000d */ 	break	0x6
.NB000147a4:
/*    147a4:	3c018006 */ 	lui	$at,0x8006
/*    147a8:	0000c812 */ 	mflo	$t9
/*    147ac:	ac391240 */ 	sw	$t9,0x1240($at)
/*    147b0:	10000005 */ 	beqz	$zero,.NB000147c8
/*    147b4:	02001025 */ 	or	$v0,$s0,$zero
.NB000147b8:
/*    147b8:	240a0100 */ 	addiu	$t2,$zero,0x100
/*    147bc:	3c018006 */ 	lui	$at,0x8006
/*    147c0:	ac2a1240 */ 	sw	$t2,0x1240($at)
.NB000147c4:
/*    147c4:	02001025 */ 	or	$v0,$s0,$zero
.NB000147c8:
/*    147c8:	3c0c8006 */ 	lui	$t4,0x8006
/*    147cc:	258c1180 */ 	addiu	$t4,$t4,0x1180
/*    147d0:	3c0b0600 */ 	lui	$t3,0x600
/*    147d4:	3c178006 */ 	lui	$s7,0x8006
/*    147d8:	3c168006 */ 	lui	$s6,0x8006
/*    147dc:	3c158006 */ 	lui	$s5,0x8006
/*    147e0:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*    147e4:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*    147e8:	26100008 */ 	addiu	$s0,$s0,0x8
/*    147ec:	26b51208 */ 	addiu	$s5,$s5,0x1208
/*    147f0:	26d6120c */ 	addiu	$s6,$s6,0x120c
/*    147f4:	26f71210 */ 	addiu	$s7,$s7,0x1210
/*    147f8:	0000a025 */ 	or	$s4,$zero,$zero
/*    147fc:	00004025 */ 	or	$t0,$zero,$zero
/*    14800:	3c1ee400 */ 	lui	$s8,0xe400
.NB00014804:
/*    14804:	00008825 */ 	or	$s1,$zero,$zero
/*    14808:	001170c0 */ 	sll	$t6,$s1,0x3
.NB0001480c:
/*    1480c:	01d17021 */ 	addu	$t6,$t6,$s1
/*    14810:	8ead0000 */ 	lw	$t5,0x0($s5)
/*    14814:	000e7080 */ 	sll	$t6,$t6,0x2
/*    14818:	01d17023 */ 	subu	$t6,$t6,$s1
/*    1481c:	000e7040 */ 	sll	$t6,$t6,0x1
/*    14820:	01ae7821 */ 	addu	$t7,$t5,$t6
/*    14824:	01e81021 */ 	addu	$v0,$t7,$t0
/*    14828:	90520000 */ 	lbu	$s2,0x0($v0)
/*    1482c:	90430001 */ 	lbu	$v1,0x1($v0)
/*    14830:	52400042 */ 	beqzl	$s2,.NB0001493c
/*    14834:	26310001 */ 	addiu	$s1,$s1,0x1
/*    14838:	50730011 */ 	beql	$v1,$s3,.NB00014880
/*    1483c:	02002025 */ 	or	$a0,$s0,$zero
/*    14840:	8ed80000 */ 	lw	$t8,0x0($s6)
/*    14844:	000310c0 */ 	sll	$v0,$v1,0x3
/*    14848:	26100010 */ 	addiu	$s0,$s0,0x10
/*    1484c:	0302c821 */ 	addu	$t9,$t8,$v0
/*    14850:	8f210000 */ 	lw	$at,0x0($t9)
/*    14854:	00609825 */ 	or	$s3,$v1,$zero
/*    14858:	ae01fff0 */ 	sw	$at,-0x10($s0)
/*    1485c:	8f2b0004 */ 	lw	$t3,0x4($t9)
/*    14860:	ae0bfff4 */ 	sw	$t3,-0xc($s0)
/*    14864:	8eec0000 */ 	lw	$t4,0x0($s7)
/*    14868:	01826821 */ 	addu	$t5,$t4,$v0
/*    1486c:	8da10000 */ 	lw	$at,0x0($t5)
/*    14870:	ae01fff8 */ 	sw	$at,-0x8($s0)
/*    14874:	8daf0004 */ 	lw	$t7,0x4($t5)
/*    14878:	ae0ffffc */ 	sw	$t7,-0x4($s0)
/*    1487c:	02002025 */ 	or	$a0,$s0,$zero
.NB00014880:
/*    14880:	0fc588f2 */ 	jal	gfxGetFreeGfx
/*    14884:	afa80040 */ 	sw	$t0,0x40($sp)
/*    14888:	28410400 */ 	slti	$at,$v0,0x400
/*    1488c:	8fa80040 */ 	lw	$t0,0x40($sp)
/*    14890:	14200029 */ 	bnez	$at,.NB00014938
/*    14894:	24090050 */ 	addiu	$t1,$zero,0x50
/*    14898:	00111900 */ 	sll	$v1,$s1,0x4
/*    1489c:	24780010 */ 	addiu	$t8,$v1,0x10
/*    148a0:	330a0fff */ 	andi	$t2,$t8,0xfff
/*    148a4:	001420c0 */ 	sll	$a0,$s4,0x3
/*    148a8:	00942023 */ 	subu	$a0,$a0,$s4
/*    148ac:	000acb00 */ 	sll	$t9,$t2,0xc
/*    148b0:	00042080 */ 	sll	$a0,$a0,0x2
/*    148b4:	306f0fff */ 	andi	$t7,$v1,0xfff
/*    148b8:	000fc300 */ 	sll	$t8,$t7,0xc
/*    148bc:	308a0fff */ 	andi	$t2,$a0,0xfff
/*    148c0:	033e5825 */ 	or	$t3,$t9,$s8
/*    148c4:	030ac825 */ 	or	$t9,$t8,$t2
/*    148c8:	248c001c */ 	addiu	$t4,$a0,0x1c
/*    148cc:	02001025 */ 	or	$v0,$s0,$zero
/*    148d0:	2646ffe0 */ 	addiu	$a2,$s2,-32
/*    148d4:	0006c143 */ 	sra	$t8,$a2,0x5
/*    148d8:	318e0fff */ 	andi	$t6,$t4,0xfff
/*    148dc:	016e6825 */ 	or	$t5,$t3,$t6
/*    148e0:	001850c0 */ 	sll	$t2,$t8,0x3
/*    148e4:	26100008 */ 	addiu	$s0,$s0,0x8
/*    148e8:	02002825 */ 	or	$a1,$s0,$zero
/*    148ec:	01585023 */ 	subu	$t2,$t2,$t8
/*    148f0:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*    148f4:	ac590004 */ 	sw	$t9,0x4($v0)
/*    148f8:	30cd001f */ 	andi	$t5,$a2,0x1f
/*    148fc:	000a5140 */ 	sll	$t2,$t2,0x5
/*    14900:	3c0cb400 */ 	lui	$t4,0xb400
/*    14904:	acac0000 */ 	sw	$t4,0x0($a1)
/*    14908:	3159ffff */ 	andi	$t9,$t2,0xffff
/*    1490c:	000d7dc0 */ 	sll	$t7,$t5,0x17
/*    14910:	26100008 */ 	addiu	$s0,$s0,0x8
/*    14914:	02003825 */ 	or	$a3,$s0,$zero
/*    14918:	01f96025 */ 	or	$t4,$t7,$t9
/*    1491c:	acac0004 */ 	sw	$t4,0x4($a1)
/*    14920:	3c0e0400 */ 	lui	$t6,0x400
/*    14924:	35ce0400 */ 	ori	$t6,$t6,0x400
/*    14928:	3c0bb300 */ 	lui	$t3,0xb300
/*    1492c:	aceb0000 */ 	sw	$t3,0x0($a3)
/*    14930:	acee0004 */ 	sw	$t6,0x4($a3)
/*    14934:	26100008 */ 	addiu	$s0,$s0,0x8
.NB00014938:
/*    14938:	26310001 */ 	addiu	$s1,$s1,0x1
.NB0001493c:
/*    1493c:	5629ffb3 */ 	bnel	$s1,$t1,.NB0001480c
/*    14940:	001170c0 */ 	sll	$t6,$s1,0x3
/*    14944:	26940001 */ 	addiu	$s4,$s4,0x1
/*    14948:	24010023 */ 	addiu	$at,$zero,0x23
/*    1494c:	1681ffad */ 	bne	$s4,$at,.NB00014804
/*    14950:	25080002 */ 	addiu	$t0,$t0,0x2
.NB00014954:
/*    14954:	02001025 */ 	or	$v0,$s0,$zero
.NB00014958:
/*    14958:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    1495c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    14960:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    14964:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    14968:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    1496c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    14970:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    14974:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    14978:	8fb70034 */ 	lw	$s7,0x34($sp)
/*    1497c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*    14980:	03e00008 */ 	jr	$ra
/*    14984:	27bd0088 */ 	addiu	$sp,$sp,0x88
);
#endif
