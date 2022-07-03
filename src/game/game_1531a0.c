#include <ultra64.h>
#include "constants.h"
#include "game/game_006900.h"
#include "game/gfxmemory.h"
#include "game/savebuffer.h"
#include "game/game_1531a0.h"
#include "game/file.h"
#include "game/lang.h"
#include "bss.h"
#include "lib/vi.h"
#include "lib/dma.h"
#include "lib/main.h"
#include "lib/memp.h"
#include "data.h"
#include "types.h"

const char var7f1b73b0[] = "burncol";

#if VERSION >= VERSION_JPN_FINAL
const char var7f1b8068jf[] = "ope";
#endif

const char var7f1b73b8[] = "sbrd";
const char var7f1b73c0[] = "lalpha";
const char var7f1b73c8[] = "subtlety";
const char var7f1b73d4[] = "subtletx";
const char var7f1b73e0[] = "coly";
const char var7f1b73e8[] = "colx";
const char var7f1b73f0[] = "lfade";
const char var7f1b73f8[] = "llimbo";

const u32 var7f1b7400[] = {0x453b8000};
const u32 var7f1b7404[] = {0x453b8000};

#if VERSION == VERSION_JPN_FINAL
u8 jpnfill5[0x2a8];
#endif

struct var800a45d0 var800a45d0;
Gfx *var800a4634;
Gfx *var800a4638;
#if VERSION == VERSION_JPN_FINAL
u8 jpnfill6[0x0c];
#endif
u32 var800a463c;

#if VERSION == VERSION_JPN_FINAL
u32 var800800f0jf = 0;
s32 g_ScaleX = 1;
u32 var80080104jf = 0;
s32 var8007fac4 = 0;
bool g_TextRotated90 = false;
u32 var8007facc = 0;
s32 var8007fad0 = 1;
s32 var80080108jf = 1;
#else
s32 g_ScaleX = 1;
s32 var8007fac4 = 0;
bool g_TextRotated90 = false;
u32 var8007facc = 0;
s32 var8007fad0 = 1;
#endif

u32 var8007fad4 = 0xffffffff;
u32 var8007fad8 = 0x00000000;
u32 var8007fadc = 0x00000000;
u32 var8007fae0 = 0x00000000;
u32 var8007fae4 = 0x00000000;
u32 var8007fae8 = 0x00000000;
u32 var8007faec = 0x00000000;
u32 var8007faf0 = 0x00000000;

struct font *g_FontTahoma2 = NULL;
struct fontchar *g_FontTahoma1 = NULL;
struct font *g_FontNumeric = NULL;
struct fontchar *g_CharsNumeric = NULL;
struct font *g_FontHandelGothicXs = NULL;
struct fontchar *g_CharsHandelGothicXs = NULL;
struct font *g_FontHandelGothicSm = NULL;
struct fontchar *g_CharsHandelGothicSm = NULL;
struct font *g_FontHandelGothicMd = NULL;
struct fontchar *g_CharsHandelGothicMd = NULL;
struct font *g_FontHandelGothicLg = NULL;
struct fontchar *g_CharsHandelGothicLg = NULL;

u32 var8007fb24 = 0x00000000;
u32 var8007fb28 = 0x00000000;
u32 var8007fb2c = 0x00000000;
u32 var8007fb30 = 0x00000000;
u32 var8007fb34 = 0x00000000;
u32 var8007fb38 = 0x00000000;
u32 var8007fb3c = 0xff00ff00;
u32 var8007fb40 = 0xff00ff00;
u32 var8007fb44 = 0xff00ff00;
u32 var8007fb48 = 0xff00ff00;
u32 var8007fb4c = 0xff00ff24;
u32 var8007fb50 = 0xff48ff6c;
u32 var8007fb54 = 0xff90ffb4;
u32 var8007fb58 = 0xffd8ffff;
u32 var8007fb5c = 0xff00ff58;
u32 var8007fb60 = 0xff74ff90;
u32 var8007fb64 = 0xffacffc8;
u32 var8007fb68 = 0xffe4ffff;
u32 var8007fb6c = 0xffffffff;
u32 var8007fb70 = 0xffffffff;
u32 var8007fb74 = 0xffffffff;
u32 var8007fb78 = 0xffffffff;
u32 var8007fb7c = 0xff00ff00;
u32 var8007fb80 = 0xff00ff00;
u32 var8007fb84 = 0xff00ff00;
u32 var8007fb88 = 0xff00ff00;
u32 var8007fb8c = 0xff00ff18;
u32 var8007fb90 = 0xff30ff5c;
u32 var8007fb94 = 0xff88ffb4;
u32 var8007fb98 = 0xffd8ffff;

#if VERSION == VERSION_JPN_FINAL
u32 var800801d8jf = 0xff00ff11;
u32 var800801dcjf = 0xff22ff33;
u32 var800801e0jf = 0xff44ff55;
u32 var800801e4jf = 0xff66ff77;
u32 var800801e8jf = 0xff88ff99;
u32 var800801ecjf = 0xffaaffbb;
u32 var800801f0jf = 0xffccffdd;
u32 var800801f4jf = 0xffeeffff;
#endif

u32 var8007fb9c = 0x00000000;
s32 var8007fba0 = 0;
s32 var8007fba4 = -1;
u32 var8007fba8 = 0x00000000;
u32 var8007fbac = 0x00000001;
u32 var8007fbb0 = 0x00000064;
u32 var8007fbb4 = 0x0000002c;
u32 var8007fbb8 = 0x00000080;
u32 var8007fbbc = 0x0000003c;
u32 var8007fbc0 = 0x44444400;
u32 var8007fbc4 = 0xffffff00;
u32 var8007fbc8 = 0xffffff00;

#if VERSION >= VERSION_JPN_FINAL
u32 jpnfill8 = 0;
u32 var8007fbd8 = 0x00000000;
u32 var80080130pf[3] = {0};
#elif VERSION >= VERSION_PAL_BETA
u32 var8007fbd8 = 0x00000000;
u32 var80080130pf[4] = {0};
#else
u32 var8007fbcc = 0x00000c0b;
u32 var8007fbd0 = 0x00000000;
u32 var8007fbd4 = 0x00000000;
u32 var8007fbd8 = 0x00000000;
u32 var8007fbdc = 0x00000c0b;
u32 var8007fbe0 = 0x00000000;
u32 var8007fbe4 = 0x00000000;
u32 var8007fbe8 = 0x00000000;
#endif

void fontsInit(void)
{
	// empty
}

void func0f1531a8(s32 arg0)
{
	var8007fac4 = -arg0;
}

void textSetRotation90(bool rotated)
{
	g_TextRotated90 = rotated;
}

void func0f1531c4(s32 arg0)
{
	var8007facc = arg0;
}

void func0f1531d0(s32 arg0)
{
	var8007fad4 = arg0;
}

void func0f1531dc(bool arg0)
{
	if (arg0) {
		var8007fad0 = 2;
	} else {
		var8007fad0 = 1;
	}

#if VERSION == VERSION_JPN_FINAL
	var80080108jf = 1;
#endif
}

void fontLoad(u8 *romstart, u8 *romend, struct font **fontptr, struct fontchar **charsptr, bool monospace)
{
	extern u8 _fonthandelgothicsmSegmentRomStart;
	extern u8 _fonthandelgothicxsSegmentRomStart;
	extern u8 _fonthandelgothicmdSegmentRomStart;

	u32 len;
	s32 maxwidth;
	s32 i;
	struct font *font;
	struct fontchar *chars;

#if VERSION >= VERSION_PAL_BETA
	s32 numchars = 94;

#if PAL
	// PAL has more characters in these fonts
	if (romstart == &_fonthandelgothicsmSegmentRomStart
			|| romstart == &_fonthandelgothicxsSegmentRomStart
			|| romstart == &_fonthandelgothicmdSegmentRomStart) {
		numchars = 135;
	}
#endif
#define NUMCHARS() numchars
#else
#define NUMCHARS() 94
#endif

	len = (u32)romend - (u32)romstart;
	font = mempAlloc(len, MEMPOOL_STAGE);
	chars = font->chars;

	dmaExec(font, (u32) romstart, len);

	// Convert pointers
	for (i = 0; i < NUMCHARS(); i++) {
		chars[i].pixeldata += (u32)font;
	}

#if VERSION >= VERSION_JPN_FINAL
	if (romstart == &_fonthandelgothicsmSegmentRomStart) {
		for (i = 0; i < NUMCHARS(); i++) {
			chars[i].baseline++;
		}
	}
#endif

	// If requested monospace, set all widths to the max, minus 1 for some reason
	if (monospace) {
		maxwidth = 0;

		for (i = 0; i < NUMCHARS(); i++) {
			if (chars[i].width > maxwidth) {
				maxwidth = chars[i].width;
			}
		}

		maxwidth--;

		for (i = 0; i < NUMCHARS(); i++) {
			chars[i].width = maxwidth;
		}
	}

	*fontptr = font;
	*charsptr = chars;

#if PAL
	if (romstart == &_fonthandelgothicsmSegmentRomStart
			|| romstart == &_fonthandelgothicxsSegmentRomStart
			|| romstart == &_fonthandelgothicmdSegmentRomStart) {
		// Increment the baseline of the pipe character.
		// It is suspected that the pipe character is used as a reference to set
		// the size for all other text, so changing this increases the line
		// height of these fonts.
		(*charsptr)['|' - 0x21].baseline++;
	}
#endif
}

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel fontsReset
/*  f1529d4:	3c018008 */ 	lui	$at,0x8008
/*  f1529d8:	ac200128 */ 	sw	$zero,0x128($at)
/*  f1529dc:	3c018008 */ 	lui	$at,0x8008
/*  f1529e0:	3c068008 */ 	lui	$a2,0x8008
/*  f1529e4:	ac200130 */ 	sw	$zero,0x130($at)
/*  f1529e8:	24c60138 */ 	addiu	$a2,$a2,0x138
/*  f1529ec:	acc00000 */ 	sw	$zero,0x0($a2)
/*  f1529f0:	3c018008 */ 	lui	$at,0x8008
/*  f1529f4:	ac200140 */ 	sw	$zero,0x140($at)
/*  f1529f8:	3c018008 */ 	lui	$at,0x8008
/*  f1529fc:	ac200148 */ 	sw	$zero,0x148($at)
/*  f152a00:	3c018008 */ 	lui	$at,0x8008
/*  f152a04:	ac200150 */ 	sw	$zero,0x150($at)
/*  f152a08:	3c018008 */ 	lui	$at,0x8008
/*  f152a0c:	ac200158 */ 	sw	$zero,0x158($at)
/*  f152a10:	3c018008 */ 	lui	$at,0x8008
/*  f152a14:	ac200160 */ 	sw	$zero,0x160($at)
/*  f152a18:	3c018008 */ 	lui	$at,0x8008
/*  f152a1c:	ac200168 */ 	sw	$zero,0x168($at)
/*  f152a20:	3c018008 */ 	lui	$at,0x8008
/*  f152a24:	ac200170 */ 	sw	$zero,0x170($at)
/*  f152a28:	3c018008 */ 	lui	$at,0x8008
/*  f152a2c:	ac20012c */ 	sw	$zero,0x12c($at)
/*  f152a30:	3c018008 */ 	lui	$at,0x8008
/*  f152a34:	3c078008 */ 	lui	$a3,0x8008
/*  f152a38:	ac200134 */ 	sw	$zero,0x134($at)
/*  f152a3c:	24e7013c */ 	addiu	$a3,$a3,0x13c
/*  f152a40:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f152a44:	3c018008 */ 	lui	$at,0x8008
/*  f152a48:	ac200144 */ 	sw	$zero,0x144($at)
/*  f152a4c:	3c018008 */ 	lui	$at,0x8008
/*  f152a50:	ac20014c */ 	sw	$zero,0x14c($at)
/*  f152a54:	3c018008 */ 	lui	$at,0x8008
/*  f152a58:	ac200154 */ 	sw	$zero,0x154($at)
/*  f152a5c:	3c018008 */ 	lui	$at,0x8008
/*  f152a60:	ac20015c */ 	sw	$zero,0x15c($at)
/*  f152a64:	3c018008 */ 	lui	$at,0x8008
/*  f152a68:	ac200164 */ 	sw	$zero,0x164($at)
/*  f152a6c:	3c018008 */ 	lui	$at,0x8008
/*  f152a70:	ac20016c */ 	sw	$zero,0x16c($at)
/*  f152a74:	3c018008 */ 	lui	$at,0x8008
/*  f152a78:	ac200174 */ 	sw	$zero,0x174($at)
/*  f152a7c:	3c018008 */ 	lui	$at,0x8008
/*  f152a80:	ac2000fc */ 	sw	$zero,0xfc($at)
/*  f152a84:	3c018008 */ 	lui	$at,0x8008
/*  f152a88:	ac200100 */ 	sw	$zero,0x100($at)
/*  f152a8c:	3c018008 */ 	lui	$at,0x8008
/*  f152a90:	ac200104 */ 	sw	$zero,0x104($at)
/*  f152a94:	3c018008 */ 	lui	$at,0x8008
/*  f152a98:	240effff */ 	li	$t6,-1
/*  f152a9c:	ac2e0110 */ 	sw	$t6,0x110($at)
/*  f152aa0:	3c018008 */ 	lui	$at,0x8008
/*  f152aa4:	ac200114 */ 	sw	$zero,0x114($at)
/*  f152aa8:	3c018008 */ 	lui	$at,0x8008
/*  f152aac:	ac200118 */ 	sw	$zero,0x118($at)
/*  f152ab0:	3c018008 */ 	lui	$at,0x8008
/*  f152ab4:	ac20011c */ 	sw	$zero,0x11c($at)
/*  f152ab8:	3c018008 */ 	lui	$at,0x8008
/*  f152abc:	ac200120 */ 	sw	$zero,0x120($at)
/*  f152ac0:	3c02800a */ 	lui	$v0,0x800a
/*  f152ac4:	8c42aae4 */ 	lw	$v0,-0x551c($v0)
/*  f152ac8:	3c018008 */ 	lui	$at,0x8008
/*  f152acc:	ac200124 */ 	sw	$zero,0x124($at)
/*  f152ad0:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f152ad4:	2401005a */ 	li	$at,0x5a
/*  f152ad8:	14410021 */ 	bne	$v0,$at,.JF0f152b60
/*  f152adc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f152ae0:	3c04007f */ 	lui	$a0,0x7f
/*  f152ae4:	3c05007f */ 	lui	$a1,0x7f
/*  f152ae8:	3c068008 */ 	lui	$a2,0x8008
/*  f152aec:	3c078008 */ 	lui	$a3,0x8008
/*  f152af0:	24e7014c */ 	addiu	$a3,$a3,0x14c
/*  f152af4:	24c60148 */ 	addiu	$a2,$a2,0x148
/*  f152af8:	24a5c640 */ 	addiu	$a1,$a1,-14784
/*  f152afc:	248493c0 */ 	addiu	$a0,$a0,-27712
/*  f152b00:	0fc54a2f */ 	jal	fontLoad
/*  f152b04:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f152b08:	3c04007f */ 	lui	$a0,0x7f
/*  f152b0c:	3c05007f */ 	lui	$a1,0x7f
/*  f152b10:	3c068008 */ 	lui	$a2,0x8008
/*  f152b14:	3c078008 */ 	lui	$a3,0x8008
/*  f152b18:	24e70154 */ 	addiu	$a3,$a3,0x154
/*  f152b1c:	24c60150 */ 	addiu	$a2,$a2,0x150
/*  f152b20:	24a52d00 */ 	addiu	$a1,$a1,0x2d00
/*  f152b24:	2484ecb0 */ 	addiu	$a0,$a0,-4944
/*  f152b28:	0fc54a2f */ 	jal	fontLoad
/*  f152b2c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f152b30:	3c04007f */ 	lui	$a0,0x7f
/*  f152b34:	3c05007f */ 	lui	$a1,0x7f
/*  f152b38:	3c068008 */ 	lui	$a2,0x8008
/*  f152b3c:	3c078008 */ 	lui	$a3,0x8008
/*  f152b40:	24e7015c */ 	addiu	$a3,$a3,0x15c
/*  f152b44:	24c60158 */ 	addiu	$a2,$a2,0x158
/*  f152b48:	24a561c0 */ 	addiu	$a1,$a1,0x61c0
/*  f152b4c:	24842d00 */ 	addiu	$a0,$a0,0x2d00
/*  f152b50:	0fc54a2f */ 	jal	fontLoad
/*  f152b54:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f152b58:	1000007b */ 	b	.JF0f152d48
/*  f152b5c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.JF0f152b60:
/*  f152b60:	2401005c */ 	li	$at,0x5c
/*  f152b64:	1441002b */ 	bne	$v0,$at,.JF0f152c14
/*  f152b68:	3c04007f */ 	lui	$a0,0x7f
/*  f152b6c:	3c04007f */ 	lui	$a0,0x7f
/*  f152b70:	3c05007f */ 	lui	$a1,0x7f
/*  f152b74:	3c068008 */ 	lui	$a2,0x8008
/*  f152b78:	3c078008 */ 	lui	$a3,0x8008
/*  f152b7c:	24e70144 */ 	addiu	$a3,$a3,0x144
/*  f152b80:	24c60140 */ 	addiu	$a2,$a2,0x140
/*  f152b84:	24a5ecb0 */ 	addiu	$a1,$a1,-4944
/*  f152b88:	2484c640 */ 	addiu	$a0,$a0,-14784
/*  f152b8c:	0fc54a2f */ 	jal	fontLoad
/*  f152b90:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f152b94:	3c068008 */ 	lui	$a2,0x8008
/*  f152b98:	3c04007f */ 	lui	$a0,0x7f
/*  f152b9c:	3c05007f */ 	lui	$a1,0x7f
/*  f152ba0:	3c078008 */ 	lui	$a3,0x8008
/*  f152ba4:	24c60148 */ 	addiu	$a2,$a2,0x148
/*  f152ba8:	24e7014c */ 	addiu	$a3,$a3,0x14c
/*  f152bac:	24a5c640 */ 	addiu	$a1,$a1,-14784
/*  f152bb0:	248493c0 */ 	addiu	$a0,$a0,-27712
/*  f152bb4:	0fc54a2f */ 	jal	fontLoad
/*  f152bb8:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f152bbc:	3c04007f */ 	lui	$a0,0x7f
/*  f152bc0:	3c05007f */ 	lui	$a1,0x7f
/*  f152bc4:	3c068008 */ 	lui	$a2,0x8008
/*  f152bc8:	3c078008 */ 	lui	$a3,0x8008
/*  f152bcc:	24e70154 */ 	addiu	$a3,$a3,0x154
/*  f152bd0:	24c60150 */ 	addiu	$a2,$a2,0x150
/*  f152bd4:	24a52d00 */ 	addiu	$a1,$a1,0x2d00
/*  f152bd8:	2484ecb0 */ 	addiu	$a0,$a0,-4944
/*  f152bdc:	0fc54a2f */ 	jal	fontLoad
/*  f152be0:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f152be4:	3c04007f */ 	lui	$a0,0x7f
/*  f152be8:	3c05007f */ 	lui	$a1,0x7f
/*  f152bec:	3c068008 */ 	lui	$a2,0x8008
/*  f152bf0:	3c078008 */ 	lui	$a3,0x8008
/*  f152bf4:	24e7015c */ 	addiu	$a3,$a3,0x15c
/*  f152bf8:	24c60158 */ 	addiu	$a2,$a2,0x158
/*  f152bfc:	24a561c0 */ 	addiu	$a1,$a1,0x61c0
/*  f152c00:	24842d00 */ 	addiu	$a0,$a0,0x2d00
/*  f152c04:	0fc54a2f */ 	jal	fontLoad
/*  f152c08:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f152c0c:	1000004e */ 	b	.JF0f152d48
/*  f152c10:	8fbf001c */ 	lw	$ra,0x1c($sp)
.JF0f152c14:
/*  f152c14:	3c05007f */ 	lui	$a1,0x7f
/*  f152c18:	24a593c0 */ 	addiu	$a1,$a1,-27712
/*  f152c1c:	248481b0 */ 	addiu	$a0,$a0,-32336
/*  f152c20:	0fc54a2f */ 	jal	fontLoad
/*  f152c24:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f152c28:	3c0f800a */ 	lui	$t7,0x800a
/*  f152c2c:	8defa948 */ 	lw	$t7,-0x56b8($t7)
/*  f152c30:	3c068008 */ 	lui	$a2,0x8008
/*  f152c34:	24c60148 */ 	addiu	$a2,$a2,0x148
/*  f152c38:	11e00011 */ 	beqz	$t7,.JF0f152c80
/*  f152c3c:	3c188009 */ 	lui	$t8,0x8009
/*  f152c40:	93181160 */ 	lbu	$t8,0x1160($t8)
/*  f152c44:	24010001 */ 	li	$at,0x1
/*  f152c48:	3c02800a */ 	lui	$v0,0x800a
/*  f152c4c:	1701000c */ 	bne	$t8,$at,.JF0f152c80
/*  f152c50:	24424cf0 */ 	addiu	$v0,$v0,0x4cf0
/*  f152c54:	3c03800a */ 	lui	$v1,0x800a
/*  f152c58:	24634f94 */ 	addiu	$v1,$v1,0x4f94
.JF0f152c5c:
/*  f152c5c:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f152c60:	1443fffe */ 	bne	$v0,$v1,.JF0f152c5c
/*  f152c64:	ac40fffc */ 	sw	$zero,-0x4($v0)
/*  f152c68:	3c19800a */ 	lui	$t9,0x800a
/*  f152c6c:	27394cf0 */ 	addiu	$t9,$t9,0x4cf0
/*  f152c70:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f152c74:	3c018008 */ 	lui	$at,0x8008
/*  f152c78:	10000032 */ 	b	.JF0f152d44
/*  f152c7c:	ac390140 */ 	sw	$t9,0x140($at)
.JF0f152c80:
/*  f152c80:	3c04007f */ 	lui	$a0,0x7f
/*  f152c84:	3c05007f */ 	lui	$a1,0x7f
/*  f152c88:	3c078008 */ 	lui	$a3,0x8008
/*  f152c8c:	24e7014c */ 	addiu	$a3,$a3,0x14c
/*  f152c90:	24a5c640 */ 	addiu	$a1,$a1,-14784
/*  f152c94:	248493c0 */ 	addiu	$a0,$a0,-27712
/*  f152c98:	0fc54a2f */ 	jal	fontLoad
/*  f152c9c:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f152ca0:	3c09800a */ 	lui	$t1,0x800a
/*  f152ca4:	8d29a948 */ 	lw	$t1,-0x56b8($t1)
/*  f152ca8:	3c04007f */ 	lui	$a0,0x7f
/*  f152cac:	3c0a8009 */ 	lui	$t2,0x8009
/*  f152cb0:	11200004 */ 	beqz	$t1,.JF0f152cc4
/*  f152cb4:	2484ecb0 */ 	addiu	$a0,$a0,-4944
/*  f152cb8:	914a1160 */ 	lbu	$t2,0x1160($t2)
/*  f152cbc:	24010001 */ 	li	$at,0x1
/*  f152cc0:	11410008 */ 	beq	$t2,$at,.JF0f152ce4
.JF0f152cc4:
/*  f152cc4:	3c05007f */ 	lui	$a1,0x7f
/*  f152cc8:	3c068008 */ 	lui	$a2,0x8008
/*  f152ccc:	3c078008 */ 	lui	$a3,0x8008
/*  f152cd0:	24e70154 */ 	addiu	$a3,$a3,0x154
/*  f152cd4:	24c60150 */ 	addiu	$a2,$a2,0x150
/*  f152cd8:	24a52d00 */ 	addiu	$a1,$a1,0x2d00
/*  f152cdc:	0fc54a2f */ 	jal	fontLoad
/*  f152ce0:	afa00010 */ 	sw	$zero,0x10($sp)
.JF0f152ce4:
/*  f152ce4:	3c0b800a */ 	lui	$t3,0x800a
/*  f152ce8:	8d6baae4 */ 	lw	$t3,-0x551c($t3)
/*  f152cec:	2401004e */ 	li	$at,0x4e
/*  f152cf0:	3c04007f */ 	lui	$a0,0x7f
/*  f152cf4:	15610009 */ 	bne	$t3,$at,.JF0f152d1c
/*  f152cf8:	24842d00 */ 	addiu	$a0,$a0,0x2d00
/*  f152cfc:	3c05007f */ 	lui	$a1,0x7f
/*  f152d00:	3c068008 */ 	lui	$a2,0x8008
/*  f152d04:	3c078008 */ 	lui	$a3,0x8008
/*  f152d08:	24e7015c */ 	addiu	$a3,$a3,0x15c
/*  f152d0c:	24c60158 */ 	addiu	$a2,$a2,0x158
/*  f152d10:	24a561c0 */ 	addiu	$a1,$a1,0x61c0
/*  f152d14:	0fc54a2f */ 	jal	fontLoad
/*  f152d18:	afa00010 */ 	sw	$zero,0x10($sp)
.JF0f152d1c:
/*  f152d1c:	3c04007f */ 	lui	$a0,0x7f
/*  f152d20:	3c05007f */ 	lui	$a1,0x7f
/*  f152d24:	3c068008 */ 	lui	$a2,0x8008
/*  f152d28:	3c078008 */ 	lui	$a3,0x8008
/*  f152d2c:	24e70144 */ 	addiu	$a3,$a3,0x144
/*  f152d30:	24c60140 */ 	addiu	$a2,$a2,0x140
/*  f152d34:	24a5ecb0 */ 	addiu	$a1,$a1,-4944
/*  f152d38:	2484c640 */ 	addiu	$a0,$a0,-14784
/*  f152d3c:	0fc54a2f */ 	jal	fontLoad
/*  f152d40:	afa00010 */ 	sw	$zero,0x10($sp)
.JF0f152d44:
/*  f152d44:	8fbf001c */ 	lw	$ra,0x1c($sp)
.JF0f152d48:
/*  f152d48:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f152d4c:	03e00008 */ 	jr	$ra
/*  f152d50:	00000000 */ 	nop
);
#else
void fontsReset(void)
{
	extern u8 _fontbankgothicSegmentRomStart,     _fontbankgothicSegmentRomEnd;
	extern u8 _fontzurichSegmentRomStart,         _fontzurichSegmentRomEnd;
	extern u8 _fonttahomaSegmentRomStart,         _fonttahomaSegmentRomEnd;
	extern u8 _fontnumericSegmentRomStart,        _fontnumericSegmentRomEnd;
	extern u8 _fonthandelgothicsmSegmentRomStart, _fonthandelgothicsmSegmentRomEnd;
	extern u8 _fonthandelgothicxsSegmentRomStart, _fonthandelgothicxsSegmentRomEnd;
	extern u8 _fonthandelgothicmdSegmentRomStart, _fonthandelgothicmdSegmentRomEnd;
	extern u8 _fonthandelgothiclgSegmentRomStart, _fonthandelgothiclgSegmentRomEnd;
	extern u8 _fontocramdSegmentRomStart,         _fontocramdSegmentRomEnd;
	extern u8 _fontocralgSegmentRomStart,         _fontocralgSegmentRomEnd;

	var8007faec = 0;
	g_FontTahoma2 = NULL;
	g_FontNumeric = NULL;
	g_FontHandelGothicXs = NULL;
	g_FontHandelGothicSm = NULL;
	g_FontHandelGothicMd = NULL;
	g_FontHandelGothicLg = NULL;
	var8007fb24 = 0;
	var8007fb2c = 0;
	var8007fb34 = 0;

	var8007faf0 = 0;
	g_FontTahoma1 = NULL;
	g_CharsNumeric = NULL;
	g_CharsHandelGothicXs = NULL;
	g_CharsHandelGothicSm = NULL;
	g_CharsHandelGothicMd = NULL;
	g_CharsHandelGothicLg = NULL;
	var8007fb28 = 0;
	var8007fb30 = 0;
	var8007fb38 = 0;

	var8007fac4 = 0;
	g_TextRotated90 = false;
	var8007facc = 0;
	var8007fad4 = 0xffffffff;
	var8007fad8 = 0;
	var8007fadc = 0;
	var8007fae0 = 0;
	var8007fae4 = 0;
	var8007fae8 = 0;

	if (g_Vars.stagenum == STAGE_TITLE) {
		fontLoad(&_fonthandelgothicsmSegmentRomStart, &_fonthandelgothicsmSegmentRomEnd, &g_FontHandelGothicSm, &g_CharsHandelGothicSm, false);
		fontLoad(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd, &g_CharsHandelGothicMd, false);
		fontLoad(&_fonthandelgothiclgSegmentRomStart, &_fonthandelgothiclgSegmentRomEnd, &g_FontHandelGothicLg, &g_CharsHandelGothicLg, false);
	} else if (g_Vars.stagenum == STAGE_CREDITS) {
		fontLoad(&_fonthandelgothicxsSegmentRomStart, &_fonthandelgothicxsSegmentRomEnd, &g_FontHandelGothicXs, &g_CharsHandelGothicXs, false);
		fontLoad(&_fonthandelgothicsmSegmentRomStart, &_fonthandelgothicsmSegmentRomEnd, &g_FontHandelGothicSm, &g_CharsHandelGothicSm, false);
		fontLoad(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd, &g_CharsHandelGothicMd, false);
		fontLoad(&_fonthandelgothiclgSegmentRomStart, &_fonthandelgothiclgSegmentRomEnd, &g_FontHandelGothicLg, &g_CharsHandelGothicLg, false);
	} else {
#if !PAL
		// This unused GE font exists in NTSC but was removed in the PAL version
		fontLoad(&_fonttahomaSegmentRomStart, &_fonttahomaSegmentRomEnd, &g_FontTahoma2, &g_FontTahoma1, false);
#endif

		fontLoad(&_fontnumericSegmentRomStart, &_fontnumericSegmentRomEnd, &g_FontNumeric, &g_CharsNumeric, false);
		fontLoad(&_fonthandelgothicxsSegmentRomStart, &_fonthandelgothicxsSegmentRomEnd, &g_FontHandelGothicXs, &g_CharsHandelGothicXs, false);
		fontLoad(&_fonthandelgothicsmSegmentRomStart, &_fonthandelgothicsmSegmentRomEnd, &g_FontHandelGothicSm, &g_CharsHandelGothicSm, false);

#if PAL
		if (!g_Vars.normmplayerisrunning) {
			fontLoad(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd, &g_CharsHandelGothicMd, false);
		}
#else
		fontLoad(&_fonthandelgothicmdSegmentRomStart, &_fonthandelgothicmdSegmentRomEnd, &g_FontHandelGothicMd, &g_CharsHandelGothicMd, false);
#endif

		if (g_Vars.stagenum == STAGE_TEST_OLD) {
			fontLoad(&_fonthandelgothiclgSegmentRomStart, &_fonthandelgothiclgSegmentRomEnd, &g_FontHandelGothicLg, &g_CharsHandelGothicLg, false);
		}
	}
}
#endif

Gfx *func0f153628(Gfx *gdl)
{
	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetColorDither(gdl++, G_CD_DISABLE);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPSetCombineLERP(gdl++,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
	gDPSetTexturePersp(gdl++, G_TP_NONE);
	gDPSetAlphaCompare(gdl++, G_AC_NONE);
	gDPSetTextureLOD(gdl++, G_TL_TILE);
	gDPSetTextureConvert(gdl++, G_TC_FILT);
	gDPSetTextureLUT(gdl++, G_TT_NONE);

	if (var8007fad8) {
		gDPSetTextureFilter(gdl++, G_TF_AVERAGE);
	}
#if VERSION == VERSION_JPN_FINAL
	else if (var80080108jf == 2) {
		gDPSetTextureFilter(gdl++, G_TF_POINT);
	}
#endif
	else {
		gDPSetTextureFilter(gdl++, G_TF_BILERP);
	}

	return gdl;
}

Gfx *func0f153780(Gfx *gdl)
{
	gDPPipeSync(gdl++);
	gDPSetColorDither(gdl++, G_CD_BAYER);
	gDPSetTexturePersp(gdl++, G_TP_PERSP);
	gDPSetTextureLOD(gdl++, G_TL_LOD);

	return gdl;
}

Gfx *gfxSetPrimColour(Gfx *gdl, u32 colour)
{
	gDPPipeSync(gdl++);
	gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
	gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

	gDPSetPrimColorViaWord(gdl++, 0, 0, colour);

	return gdl;
}

Gfx *func0f153838(Gfx *gdl)
{
	gDPSetCombineLERP(gdl++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);

	return gdl;
}

Gfx *func0f153858(Gfx *gdl, s32 *x1, s32 *y1, s32 *x2, s32 *y2)
{
	gdl = gfxSetPrimColour(gdl, 0x00000000);

	gDPFillRectangle(gdl++, *x1, *y1, *x2, *y2);

	gdl = func0f153838(gdl);

	return gdl;
}

Gfx *func0f1538e4(Gfx *gdl, s32 *x1, s32 *y1, s32 *x2, s32 *y2)
{
	gdl = gfxSetPrimColour(gdl, 0x00000000);

	gDPFillRectangleScaled(gdl++, *x1, *y1, *x2, *y2);

	gdl = func0f153838(gdl);

	return gdl;
}

#if VERSION >= VERSION_NTSC_1_0
Gfx *func0f153990(Gfx *gdl, s32 left, s32 top, s32 width, s32 height)
{
	gdl = gfxSetPrimColour(gdl, 0x00000000);

#if VERSION >= VERSION_JPN_FINAL
	gDPFillRectangle(gdl++, left - 1, top - 1, width * var8007fad0 + left + 1, top + height * var80080108jf + 1);
#else
	gDPFillRectangle(gdl++, left - 1, top - 1, width * var8007fad0 + left + 1, top + height + 1);
#endif

	gdl = func0f153838(gdl);

	return gdl;
}
#endif

Gfx *func0f153a34(Gfx *gdl, s32 x1, s32 y1, s32 x2, s32 y2, u32 colour)
{
	gdl = gfxSetPrimColour(gdl, colour);

	gDPFillRectangle(gdl++, x1, y1, x2, y2);

	gdl = func0f153838(gdl);

	return gdl;
}

Gfx *func0f153ab0(Gfx *gdl)
{
	Gfx *allocation;

	var8007fb9c = 1;

	allocation = gfxAllocate(sizeof(Gfx) * 530);

	var800a4634 = allocation;
	var800a4638 = allocation + 530;

	gSPDisplayList(gdl++, var800a4634);

	gdl = func0f0d4c80(gdl);

	var800a4634 = func0f0d4a3c(var800a4634, 0);
	var8007fba4 = -1;

	return gdl;
}

void func0f153b40(void)
{
	var8007fb9c = 0;

	gSPEndDisplayList(var800a4634++);
}

void func0f153b6c(s32 arg0)
{
	if (arg0 != var8007fba4) {
		f32 tmp = var800a45d0.unk14 * var800a45d0.unk14 - (f32)((arg0 - var800a45d0.unk10) * (arg0 - var800a45d0.unk10));

		if (tmp > 0.0f) {
			var8007fba0 = sqrtf(tmp) + var800a45d0.unk0c;
		} else {
			var8007fba0 = 0;
		}

		var8007fba4 = arg0;
	}
}

void func0f153c20(s32 x, s32 y, f32 arg2, u8 arg3)
{
	var800a45d0.unk00 |= 0x01;
	var800a45d0.unk0c = x;
	var800a45d0.unk10 = y;
	var800a45d0.unk14 = arg2;
	var800a45d0.unk18 = arg3;
}

void func0f153c50(void)
{
	var800a45d0.unk1c = var800a45d0.unk0c;
	var800a45d0.unk20 = var800a45d0.unk10;
	var800a45d0.unk24 = var800a45d0.unk14;
	var800a45d0.unk28 = var800a45d0.unk18;
	var800a45d0.unk29 = var800a45d0.unk00 & 1;
}

void func0f153c88(void)
{
	var800a45d0.unk0c = var800a45d0.unk1c;
	var800a45d0.unk10 = var800a45d0.unk20;
	var800a45d0.unk14 = var800a45d0.unk24;
	var800a45d0.unk18 = var800a45d0.unk28;
	var800a45d0.unk00 |= var800a45d0.unk29;
}

void func0f153cc4(s32 arg0, s32 arg1, u32 arg2)
{
	var800a45d0.unk00 |= 0x02;
	var800a45d0.unk2c = arg0;
	var800a45d0.unk30 = arg1;
	var800a45d0.unk34 = arg2;
}

void func0f153ce8(s32 x1, s32 x2, u32 arg2)
{
	var800a45d0.unk00 |= 0x10;
	var800a45d0.x1 = x1;
	var800a45d0.x2 = x2;
	var800a45d0.unk40 = arg2;
}

void func0f153d0c(void)
{
	var800a45d0.unk00 = 0;
}

void func0f153d18(void)
{
	var800a45d0.unk00 = 0;
}

void func0f153d24(void)
{
	var800a45d0.unk2a = var800a45d0.unk00;
	var800a45d0.unk00 = 0;
}

void func0f153d3c(void)
{
	var800a45d0.unk00 = var800a45d0.unk2a;
}

void func0f153d50(s32 arg0, s32 arg1, s32 cthresh)
{
	var800a45d0.unk00 |= 0x04;
	var800a45d0.unk4c = arg0;
	var800a45d0.unk50 = arg1;
	var800a45d0.cthresh = cthresh;
	var800a45d0.colour58 = 0x44444400;
	var800a45d0.colour5c = 0xffffff00;
}

void func0f153d88(f32 arg0)
{
	var800a45d0.unk00 |= 0x08;
	var800a45d0.unk60 = arg0 * arg0 * 110.0f;
}

void func0f153e38(u32 colour51, u32 colour2)
{
	var800a45d0.colour58 = colour51;
	var800a45d0.colour5c = colour2;
}

void func0f153e4c(void)
{
	var800a45d0.unk00 = 0;
}

s32 func0f153e58(void)
{
	return (var800a45d0.unk00 & 1)
		&& (var800a45d0.unk18 == 0 || var800a45d0.unk18 == 2);
}

GLOBAL_ASM(
glabel func0f153e94
/*  f153e94:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f153e98:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f153e9c:	912e0000 */ 	lbu	$t6,0x0($t1)
/*  f153ea0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f153ea4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f153ea8:	31cf0001 */ 	andi	$t7,$t6,0x1
/*  f153eac:	00c03825 */ 	or	$a3,$a2,$zero
/*  f153eb0:	11e00139 */ 	beqz	$t7,.L0f154398
/*  f153eb4:	00c04025 */ 	or	$t0,$a2,$zero
/*  f153eb8:	8d38000c */ 	lw	$t8,0xc($t1)
/*  f153ebc:	00981023 */ 	subu	$v0,$a0,$t8
/*  f153ec0:	2841f449 */ 	slti	$at,$v0,-2999
/*  f153ec4:	1420001c */ 	bnez	$at,.L0f153f38
/*  f153ec8:	28410bb8 */ 	slti	$at,$v0,0xbb8
/*  f153ecc:	1020001a */ 	beqz	$at,.L0f153f38
/*  f153ed0:	00000000 */ 	nop
/*  f153ed4:	8d390010 */ 	lw	$t9,0x10($t1)
/*  f153ed8:	00b91823 */ 	subu	$v1,$a1,$t9
/*  f153edc:	2861f449 */ 	slti	$at,$v1,-2999
/*  f153ee0:	14200015 */ 	bnez	$at,.L0f153f38
/*  f153ee4:	28610bb8 */ 	slti	$at,$v1,0xbb8
/*  f153ee8:	10200013 */ 	beqz	$at,.L0f153f38
/*  f153eec:	00000000 */ 	nop
/*  f153ef0:	00420019 */ 	multu	$v0,$v0
/*  f153ef4:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f153ef8:	afa60018 */ 	sw	$a2,0x18($sp)
/*  f153efc:	00005012 */ 	mflo	$t2
/*  f153f00:	00000000 */ 	nop
/*  f153f04:	00000000 */ 	nop
/*  f153f08:	00630019 */ 	multu	$v1,$v1
/*  f153f0c:	00005812 */ 	mflo	$t3
/*  f153f10:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f153f14:	448c2000 */ 	mtc1	$t4,$f4
/*  f153f18:	0c012974 */ 	jal	sqrtf
/*  f153f1c:	46802320 */ 	cvt.s.w	$f12,$f4
/*  f153f20:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f153f24:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f153f28:	8fa70030 */ 	lw	$a3,0x30($sp)
/*  f153f2c:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f153f30:	10000003 */ 	b	.L0f153f40
/*  f153f34:	46000306 */ 	mov.s	$f12,$f0
.L0f153f38:
/*  f153f38:	3c017f1b */ 	lui	$at,%hi(var7f1b7400)
/*  f153f3c:	c42c7400 */ 	lwc1	$f12,%lo(var7f1b7400)($at)
.L0f153f40:
/*  f153f40:	3c0d8008 */ 	lui	$t5,%hi(var8007fbac)
/*  f153f44:	8dadfbac */ 	lw	$t5,%lo(var8007fbac)($t5)
/*  f153f48:	3c014f80 */ 	lui	$at,0x4f80
/*  f153f4c:	3c0e8008 */ 	lui	$t6,%hi(var8007fbb0)
/*  f153f50:	448d3000 */ 	mtc1	$t5,$f6
/*  f153f54:	3c0f8008 */ 	lui	$t7,%hi(var8007fbb4)
/*  f153f58:	05a10004 */ 	bgez	$t5,.L0f153f6c
/*  f153f5c:	468033a0 */ 	cvt.s.w	$f14,$f6
/*  f153f60:	44814000 */ 	mtc1	$at,$f8
/*  f153f64:	00000000 */ 	nop
/*  f153f68:	46087380 */ 	add.s	$f14,$f14,$f8
.L0f153f6c:
/*  f153f6c:	8dcefbb0 */ 	lw	$t6,%lo(var8007fbb0)($t6)
/*  f153f70:	3c014f80 */ 	lui	$at,0x4f80
/*  f153f74:	448e5000 */ 	mtc1	$t6,$f10
/*  f153f78:	05c10004 */ 	bgez	$t6,.L0f153f8c
/*  f153f7c:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f153f80:	44812000 */ 	mtc1	$at,$f4
/*  f153f84:	00000000 */ 	nop
/*  f153f88:	46049480 */ 	add.s	$f18,$f18,$f4
.L0f153f8c:
/*  f153f8c:	8deffbb4 */ 	lw	$t7,%lo(var8007fbb4)($t7)
/*  f153f90:	3c014f80 */ 	lui	$at,0x4f80
/*  f153f94:	448f3000 */ 	mtc1	$t7,$f6
/*  f153f98:	05e10004 */ 	bgez	$t7,.L0f153fac
/*  f153f9c:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f153fa0:	44814000 */ 	mtc1	$at,$f8
/*  f153fa4:	00000000 */ 	nop
/*  f153fa8:	46088400 */ 	add.s	$f16,$f16,$f8
.L0f153fac:
/*  f153fac:	91220018 */ 	lbu	$v0,0x18($t1)
/*  f153fb0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f153fb4:	14400082 */ 	bnez	$v0,.L0f1541c0
/*  f153fb8:	00000000 */ 	nop
/*  f153fbc:	c5200014 */ 	lwc1	$f0,0x14($t1)
/*  f153fc0:	460c003c */ 	c.lt.s	$f0,$f12
/*  f153fc4:	00000000 */ 	nop
/*  f153fc8:	45020004 */ 	bc1fl	.L0f153fdc
/*  f153fcc:	460e0081 */ 	sub.s	$f2,$f0,$f14
/*  f153fd0:	100000f1 */ 	b	.L0f154398
/*  f153fd4:	00004025 */ 	or	$t0,$zero,$zero
/*  f153fd8:	460e0081 */ 	sub.s	$f2,$f0,$f14
.L0f153fdc:
/*  f153fdc:	240a00ff */ 	addiu	$t2,$zero,0xff
/*  f153fe0:	460c103c */ 	c.lt.s	$f2,$f12
/*  f153fe4:	00000000 */ 	nop
/*  f153fe8:	45020030 */ 	bc1fl	.L0f1540ac
/*  f153fec:	46107280 */ 	add.s	$f10,$f14,$f16
/*  f153ff0:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f153ff4:	3c01437f */ 	lui	$at,0x437f
/*  f153ff8:	44813000 */ 	mtc1	$at,$f6
/*  f153ffc:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f154000:	460e5103 */ 	div.s	$f4,$f10,$f14
/*  f154004:	3c014f00 */ 	lui	$at,0x4f00
/*  f154008:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f15400c:	4458f800 */ 	cfc1	$t8,$31
/*  f154010:	44d9f800 */ 	ctc1	$t9,$31
/*  f154014:	00000000 */ 	nop
/*  f154018:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f15401c:	4459f800 */ 	cfc1	$t9,$31
/*  f154020:	00000000 */ 	nop
/*  f154024:	33390078 */ 	andi	$t9,$t9,0x78
/*  f154028:	53200013 */ 	beqzl	$t9,.L0f154078
/*  f15402c:	44194000 */ 	mfc1	$t9,$f8
/*  f154030:	44814000 */ 	mtc1	$at,$f8
/*  f154034:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f154038:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f15403c:	44d9f800 */ 	ctc1	$t9,$31
/*  f154040:	00000000 */ 	nop
/*  f154044:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f154048:	4459f800 */ 	cfc1	$t9,$31
/*  f15404c:	00000000 */ 	nop
/*  f154050:	33390078 */ 	andi	$t9,$t9,0x78
/*  f154054:	17200005 */ 	bnez	$t9,.L0f15406c
/*  f154058:	00000000 */ 	nop
/*  f15405c:	44194000 */ 	mfc1	$t9,$f8
/*  f154060:	3c018000 */ 	lui	$at,0x8000
/*  f154064:	10000007 */ 	b	.L0f154084
/*  f154068:	0321c825 */ 	or	$t9,$t9,$at
.L0f15406c:
/*  f15406c:	10000005 */ 	b	.L0f154084
/*  f154070:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f154074:	44194000 */ 	mfc1	$t9,$f8
.L0f154078:
/*  f154078:	00000000 */ 	nop
/*  f15407c:	0720fffb */ 	bltz	$t9,.L0f15406c
/*  f154080:	00000000 */ 	nop
.L0f154084:
/*  f154084:	01591023 */ 	subu	$v0,$t2,$t9
/*  f154088:	00025a00 */ 	sll	$t3,$v0,0x8
/*  f15408c:	01626025 */ 	or	$t4,$t3,$v0
/*  f154090:	00026c00 */ 	sll	$t5,$v0,0x10
/*  f154094:	018d7025 */ 	or	$t6,$t4,$t5
/*  f154098:	00027e00 */ 	sll	$t7,$v0,0x18
/*  f15409c:	44d8f800 */ 	ctc1	$t8,$31
/*  f1540a0:	100000bd */ 	b	.L0f154398
/*  f1540a4:	01cf4025 */ 	or	$t0,$t6,$t7
/*  f1540a8:	46107280 */ 	add.s	$f10,$f14,$f16
.L0f1540ac:
/*  f1540ac:	30f800ff */ 	andi	$t8,$a3,0xff
/*  f1540b0:	270a00ff */ 	addiu	$t2,$t8,0xff
/*  f1540b4:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1540b8:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f1540bc:	00e15824 */ 	and	$t3,$a3,$at
/*  f1540c0:	000ac842 */ 	srl	$t9,$t2,0x1
/*  f1540c4:	460c203c */ 	c.lt.s	$f4,$f12
/*  f1540c8:	00000000 */ 	nop
/*  f1540cc:	45020004 */ 	bc1fl	.L0f1540e0
/*  f1540d0:	46127180 */ 	add.s	$f6,$f14,$f18
/*  f1540d4:	100000b0 */ 	b	.L0f154398
/*  f1540d8:	032b4025 */ 	or	$t0,$t9,$t3
/*  f1540dc:	46127180 */ 	add.s	$f6,$f14,$f18
.L0f1540e0:
/*  f1540e0:	241900ff */ 	addiu	$t9,$zero,0xff
/*  f1540e4:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f1540e8:	46080081 */ 	sub.s	$f2,$f0,$f8
/*  f1540ec:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1540f0:	00000000 */ 	nop
/*  f1540f4:	450200a9 */ 	bc1fl	.L0f15439c
/*  f1540f8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1540fc:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f154100:	3c01437f */ 	lui	$at,0x437f
/*  f154104:	44813000 */ 	mtc1	$at,$f6
/*  f154108:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f15410c:	46125103 */ 	div.s	$f4,$f10,$f18
/*  f154110:	30ec00ff */ 	andi	$t4,$a3,0xff
/*  f154114:	258d00ff */ 	addiu	$t5,$t4,0xff
/*  f154118:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f15411c:	00e17824 */ 	and	$t7,$a3,$at
/*  f154120:	000d7042 */ 	srl	$t6,$t5,0x1
/*  f154124:	01cf2825 */ 	or	$a1,$t6,$t7
/*  f154128:	3c014f00 */ 	lui	$at,0x4f00
/*  f15412c:	00e02025 */ 	or	$a0,$a3,$zero
/*  f154130:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f154134:	4458f800 */ 	cfc1	$t8,$31
/*  f154138:	44caf800 */ 	ctc1	$t2,$31
/*  f15413c:	00000000 */ 	nop
/*  f154140:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f154144:	444af800 */ 	cfc1	$t2,$31
/*  f154148:	00000000 */ 	nop
/*  f15414c:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f154150:	51400013 */ 	beqzl	$t2,.L0f1541a0
/*  f154154:	440a4000 */ 	mfc1	$t2,$f8
/*  f154158:	44814000 */ 	mtc1	$at,$f8
/*  f15415c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f154160:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f154164:	44caf800 */ 	ctc1	$t2,$31
/*  f154168:	00000000 */ 	nop
/*  f15416c:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f154170:	444af800 */ 	cfc1	$t2,$31
/*  f154174:	00000000 */ 	nop
/*  f154178:	314a0078 */ 	andi	$t2,$t2,0x78
/*  f15417c:	15400005 */ 	bnez	$t2,.L0f154194
/*  f154180:	00000000 */ 	nop
/*  f154184:	440a4000 */ 	mfc1	$t2,$f8
/*  f154188:	3c018000 */ 	lui	$at,0x8000
/*  f15418c:	10000007 */ 	b	.L0f1541ac
/*  f154190:	01415025 */ 	or	$t2,$t2,$at
.L0f154194:
/*  f154194:	10000005 */ 	b	.L0f1541ac
/*  f154198:	240affff */ 	addiu	$t2,$zero,-1
/*  f15419c:	440a4000 */ 	mfc1	$t2,$f8
.L0f1541a0:
/*  f1541a0:	00000000 */ 	nop
/*  f1541a4:	0540fffb */ 	bltz	$t2,.L0f154194
/*  f1541a8:	00000000 */ 	nop
.L0f1541ac:
/*  f1541ac:	44d8f800 */ 	ctc1	$t8,$31
/*  f1541b0:	0fc01a40 */ 	jal	colourBlend
/*  f1541b4:	032a3023 */ 	subu	$a2,$t9,$t2
/*  f1541b8:	10000077 */ 	b	.L0f154398
/*  f1541bc:	00404025 */ 	or	$t0,$v0,$zero
.L0f1541c0:
/*  f1541c0:	54410076 */ 	bnel	$v0,$at,.L0f15439c
/*  f1541c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1541c8:	c5200014 */ 	lwc1	$f0,0x14($t1)
/*  f1541cc:	460c003c */ 	c.lt.s	$f0,$f12
/*  f1541d0:	00000000 */ 	nop
/*  f1541d4:	45020004 */ 	bc1fl	.L0f1541e8
/*  f1541d8:	460e0081 */ 	sub.s	$f2,$f0,$f14
/*  f1541dc:	1000006e */ 	b	.L0f154398
/*  f1541e0:	00004025 */ 	or	$t0,$zero,$zero
/*  f1541e4:	460e0081 */ 	sub.s	$f2,$f0,$f14
.L0f1541e8:
/*  f1541e8:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1541ec:	00000000 */ 	nop
/*  f1541f0:	4502002e */ 	bc1fl	.L0f1542ac
/*  f1541f4:	44808000 */ 	mtc1	$zero,$f16
/*  f1541f8:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f1541fc:	3c01437f */ 	lui	$at,0x437f
/*  f154200:	44813000 */ 	mtc1	$at,$f6
/*  f154204:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f154208:	460e5103 */ 	div.s	$f4,$f10,$f14
/*  f15420c:	3c014f00 */ 	lui	$at,0x4f00
/*  f154210:	00002025 */ 	or	$a0,$zero,$zero
/*  f154214:	30e500ff */ 	andi	$a1,$a3,0xff
/*  f154218:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f15421c:	444bf800 */ 	cfc1	$t3,$31
/*  f154220:	44c6f800 */ 	ctc1	$a2,$31
/*  f154224:	00000000 */ 	nop
/*  f154228:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f15422c:	4446f800 */ 	cfc1	$a2,$31
/*  f154230:	00000000 */ 	nop
/*  f154234:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f154238:	50c00013 */ 	beqzl	$a2,.L0f154288
/*  f15423c:	44064000 */ 	mfc1	$a2,$f8
/*  f154240:	44814000 */ 	mtc1	$at,$f8
/*  f154244:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f154248:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f15424c:	44c6f800 */ 	ctc1	$a2,$31
/*  f154250:	00000000 */ 	nop
/*  f154254:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f154258:	4446f800 */ 	cfc1	$a2,$31
/*  f15425c:	00000000 */ 	nop
/*  f154260:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f154264:	14c00005 */ 	bnez	$a2,.L0f15427c
/*  f154268:	00000000 */ 	nop
/*  f15426c:	44064000 */ 	mfc1	$a2,$f8
/*  f154270:	3c018000 */ 	lui	$at,0x8000
/*  f154274:	10000007 */ 	b	.L0f154294
/*  f154278:	00c13025 */ 	or	$a2,$a2,$at
.L0f15427c:
/*  f15427c:	10000005 */ 	b	.L0f154294
/*  f154280:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f154284:	44064000 */ 	mfc1	$a2,$f8
.L0f154288:
/*  f154288:	00000000 */ 	nop
/*  f15428c:	04c0fffb */ 	bltz	$a2,.L0f15427c
/*  f154290:	00000000 */ 	nop
.L0f154294:
/*  f154294:	44cbf800 */ 	ctc1	$t3,$31
/*  f154298:	0fc01a40 */ 	jal	colourBlend
/*  f15429c:	00000000 */ 	nop
/*  f1542a0:	1000003d */ 	b	.L0f154398
/*  f1542a4:	00404025 */ 	or	$t0,$v0,$zero
/*  f1542a8:	44808000 */ 	mtc1	$zero,$f16
.L0f1542ac:
/*  f1542ac:	00000000 */ 	nop
/*  f1542b0:	46107280 */ 	add.s	$f10,$f14,$f16
/*  f1542b4:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f1542b8:	460c203c */ 	c.lt.s	$f4,$f12
/*  f1542bc:	00000000 */ 	nop
/*  f1542c0:	45020004 */ 	bc1fl	.L0f1542d4
/*  f1542c4:	46127180 */ 	add.s	$f6,$f14,$f18
/*  f1542c8:	10000033 */ 	b	.L0f154398
/*  f1542cc:	30e800ff */ 	andi	$t0,$a3,0xff
/*  f1542d0:	46127180 */ 	add.s	$f6,$f14,$f18
.L0f1542d4:
/*  f1542d4:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f1542d8:	46080081 */ 	sub.s	$f2,$f0,$f8
/*  f1542dc:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1542e0:	00000000 */ 	nop
/*  f1542e4:	4502002d */ 	bc1fl	.L0f15439c
/*  f1542e8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1542ec:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f1542f0:	3c01437f */ 	lui	$at,0x437f
/*  f1542f4:	44813000 */ 	mtc1	$at,$f6
/*  f1542f8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1542fc:	46125103 */ 	div.s	$f4,$f10,$f18
/*  f154300:	3c014f00 */ 	lui	$at,0x4f00
/*  f154304:	30e400ff */ 	andi	$a0,$a3,0xff
/*  f154308:	00e02825 */ 	or	$a1,$a3,$zero
/*  f15430c:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f154310:	444cf800 */ 	cfc1	$t4,$31
/*  f154314:	44c6f800 */ 	ctc1	$a2,$31
/*  f154318:	00000000 */ 	nop
/*  f15431c:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f154320:	4446f800 */ 	cfc1	$a2,$31
/*  f154324:	00000000 */ 	nop
/*  f154328:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f15432c:	50c00013 */ 	beqzl	$a2,.L0f15437c
/*  f154330:	44064000 */ 	mfc1	$a2,$f8
/*  f154334:	44814000 */ 	mtc1	$at,$f8
/*  f154338:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f15433c:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f154340:	44c6f800 */ 	ctc1	$a2,$31
/*  f154344:	00000000 */ 	nop
/*  f154348:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f15434c:	4446f800 */ 	cfc1	$a2,$31
/*  f154350:	00000000 */ 	nop
/*  f154354:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f154358:	14c00005 */ 	bnez	$a2,.L0f154370
/*  f15435c:	00000000 */ 	nop
/*  f154360:	44064000 */ 	mfc1	$a2,$f8
/*  f154364:	3c018000 */ 	lui	$at,0x8000
/*  f154368:	10000007 */ 	b	.L0f154388
/*  f15436c:	00c13025 */ 	or	$a2,$a2,$at
.L0f154370:
/*  f154370:	10000005 */ 	b	.L0f154388
/*  f154374:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f154378:	44064000 */ 	mfc1	$a2,$f8
.L0f15437c:
/*  f15437c:	00000000 */ 	nop
/*  f154380:	04c0fffb */ 	bltz	$a2,.L0f154370
/*  f154384:	00000000 */ 	nop
.L0f154388:
/*  f154388:	44ccf800 */ 	ctc1	$t4,$31
/*  f15438c:	0fc01a40 */ 	jal	colourBlend
/*  f154390:	00000000 */ 	nop
/*  f154394:	00404025 */ 	or	$t0,$v0,$zero
.L0f154398:
/*  f154398:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f15439c:
/*  f15439c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f1543a0:	01001025 */ 	or	$v0,$t0,$zero
/*  f1543a4:	03e00008 */ 	jr	$ra
/*  f1543a8:	00000000 */ 	nop
);

GLOBAL_ASM(
glabel func0f1543ac
/*  f1543ac:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f1543b0:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f1543b4:	91280000 */ 	lbu	$t0,0x0($t1)
/*  f1543b8:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f1543bc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1543c0:	310e0008 */ 	andi	$t6,$t0,0x8
/*  f1543c4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1543c8:	afa400a8 */ 	sw	$a0,0xa8($sp)
/*  f1543cc:	afa500ac */ 	sw	$a1,0xac($sp)
/*  f1543d0:	00c03825 */ 	or	$a3,$a2,$zero
/*  f1543d4:	11c0000e */ 	beqz	$t6,.L0f154410
/*  f1543d8:	00c08025 */ 	or	$s0,$a2,$zero
/*  f1543dc:	00002025 */ 	or	$a0,$zero,$zero
/*  f1543e0:	00e02825 */ 	or	$a1,$a3,$zero
/*  f1543e4:	8d260060 */ 	lw	$a2,0x60($t1)
/*  f1543e8:	0fc01a40 */ 	jal	colourBlend
/*  f1543ec:	afa700b0 */ 	sw	$a3,0xb0($sp)
/*  f1543f0:	8fa700b0 */ 	lw	$a3,0xb0($sp)
/*  f1543f4:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f1543f8:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1543fc:	00417824 */ 	and	$t7,$v0,$at
/*  f154400:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154404:	30f800ff */ 	andi	$t8,$a3,0xff
/*  f154408:	01f88025 */ 	or	$s0,$t7,$t8
/*  f15440c:	91280000 */ 	lbu	$t0,0x0($t1)
.L0f154410:
/*  f154410:	31190002 */ 	andi	$t9,$t0,0x2
/*  f154414:	53200029 */ 	beqzl	$t9,.L0f1544bc
/*  f154418:	310e0010 */ 	andi	$t6,$t0,0x10
/*  f15441c:	8faa00ac */ 	lw	$t2,0xac($sp)
/*  f154420:	8d2b002c */ 	lw	$t3,0x2c($t1)
/*  f154424:	8d2c0030 */ 	lw	$t4,0x30($t1)
/*  f154428:	02002025 */ 	or	$a0,$s0,$zero
/*  f15442c:	014b1023 */ 	subu	$v0,$t2,$t3
/*  f154430:	04410002 */ 	bgez	$v0,.L0f15443c
/*  f154434:	014c1823 */ 	subu	$v1,$t2,$t4
/*  f154438:	00021023 */ 	negu	$v0,$v0
.L0f15443c:
/*  f15443c:	04630003 */ 	bgezl	$v1,.L0f15444c
/*  f154440:	0062082a */ 	slt	$at,$v1,$v0
/*  f154444:	00031823 */ 	negu	$v1,$v1
/*  f154448:	0062082a */ 	slt	$at,$v1,$v0
.L0f15444c:
/*  f15444c:	50200003 */ 	beqzl	$at,.L0f15445c
/*  f154450:	8d230034 */ 	lw	$v1,0x34($t1)
/*  f154454:	00601025 */ 	or	$v0,$v1,$zero
/*  f154458:	8d230034 */ 	lw	$v1,0x34($t1)
.L0f15445c:
/*  f15445c:	0062082a */ 	slt	$at,$v1,$v0
/*  f154460:	54200016 */ 	bnezl	$at,.L0f1544bc
/*  f154464:	310e0010 */ 	andi	$t6,$t0,0x10
/*  f154468:	00026a00 */ 	sll	$t5,$v0,0x8
/*  f15446c:	01a26823 */ 	subu	$t5,$t5,$v0
/*  f154470:	01a3001a */ 	div	$zero,$t5,$v1
/*  f154474:	00003012 */ 	mflo	$a2
/*  f154478:	00002825 */ 	or	$a1,$zero,$zero
/*  f15447c:	14600002 */ 	bnez	$v1,.L0f154488
/*  f154480:	00000000 */ 	nop
/*  f154484:	0007000d */ 	break	0x7
.L0f154488:
/*  f154488:	2401ffff */ 	addiu	$at,$zero,-1
/*  f15448c:	14610004 */ 	bne	$v1,$at,.L0f1544a0
/*  f154490:	3c018000 */ 	lui	$at,0x8000
/*  f154494:	15a10002 */ 	bne	$t5,$at,.L0f1544a0
/*  f154498:	00000000 */ 	nop
/*  f15449c:	0006000d */ 	break	0x6
.L0f1544a0:
/*  f1544a0:	0fc01a40 */ 	jal	colourBlend
/*  f1544a4:	00000000 */ 	nop
/*  f1544a8:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f1544ac:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f1544b0:	91280000 */ 	lbu	$t0,0x0($t1)
/*  f1544b4:	00408025 */ 	or	$s0,$v0,$zero
/*  f1544b8:	310e0010 */ 	andi	$t6,$t0,0x10
.L0f1544bc:
/*  f1544bc:	11c00027 */ 	beqz	$t6,.L0f15455c
/*  f1544c0:	8faf00a8 */ 	lw	$t7,0xa8($sp)
/*  f1544c4:	8d380038 */ 	lw	$t8,0x38($t1)
/*  f1544c8:	8d39003c */ 	lw	$t9,0x3c($t1)
/*  f1544cc:	02002025 */ 	or	$a0,$s0,$zero
/*  f1544d0:	01f81023 */ 	subu	$v0,$t7,$t8
/*  f1544d4:	04410002 */ 	bgez	$v0,.L0f1544e0
/*  f1544d8:	01f91823 */ 	subu	$v1,$t7,$t9
/*  f1544dc:	00001025 */ 	or	$v0,$zero,$zero
.L0f1544e0:
/*  f1544e0:	04630003 */ 	bgezl	$v1,.L0f1544f0
/*  f1544e4:	0062082a */ 	slt	$at,$v1,$v0
/*  f1544e8:	00031823 */ 	negu	$v1,$v1
/*  f1544ec:	0062082a */ 	slt	$at,$v1,$v0
.L0f1544f0:
/*  f1544f0:	50200003 */ 	beqzl	$at,.L0f154500
/*  f1544f4:	8d230040 */ 	lw	$v1,0x40($t1)
/*  f1544f8:	00601025 */ 	or	$v0,$v1,$zero
/*  f1544fc:	8d230040 */ 	lw	$v1,0x40($t1)
.L0f154500:
/*  f154500:	00025a00 */ 	sll	$t3,$v0,0x8
/*  f154504:	01625823 */ 	subu	$t3,$t3,$v0
/*  f154508:	0062082a */ 	slt	$at,$v1,$v0
/*  f15450c:	54200014 */ 	bnezl	$at,.L0f154560
/*  f154510:	310a0001 */ 	andi	$t2,$t0,0x1
/*  f154514:	0163001a */ 	div	$zero,$t3,$v1
/*  f154518:	00003012 */ 	mflo	$a2
/*  f15451c:	00002825 */ 	or	$a1,$zero,$zero
/*  f154520:	14600002 */ 	bnez	$v1,.L0f15452c
/*  f154524:	00000000 */ 	nop
/*  f154528:	0007000d */ 	break	0x7
.L0f15452c:
/*  f15452c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f154530:	14610004 */ 	bne	$v1,$at,.L0f154544
/*  f154534:	3c018000 */ 	lui	$at,0x8000
/*  f154538:	15610002 */ 	bne	$t3,$at,.L0f154544
/*  f15453c:	00000000 */ 	nop
/*  f154540:	0006000d */ 	break	0x6
.L0f154544:
/*  f154544:	0fc01a40 */ 	jal	colourBlend
/*  f154548:	00000000 */ 	nop
/*  f15454c:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154550:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154554:	91280000 */ 	lbu	$t0,0x0($t1)
/*  f154558:	00408025 */ 	or	$s0,$v0,$zero
.L0f15455c:
/*  f15455c:	310a0001 */ 	andi	$t2,$t0,0x1
.L0f154560:
/*  f154560:	114001fd */ 	beqz	$t2,.L0f154d58
/*  f154564:	8fac00a8 */ 	lw	$t4,0xa8($sp)
/*  f154568:	8d2d000c */ 	lw	$t5,0xc($t1)
/*  f15456c:	018d1023 */ 	subu	$v0,$t4,$t5
/*  f154570:	2841f449 */ 	slti	$at,$v0,-2999
/*  f154574:	14200018 */ 	bnez	$at,.L0f1545d8
/*  f154578:	28410bb8 */ 	slti	$at,$v0,0xbb8
/*  f15457c:	10200016 */ 	beqz	$at,.L0f1545d8
/*  f154580:	8fae00ac */ 	lw	$t6,0xac($sp)
/*  f154584:	8d380010 */ 	lw	$t8,0x10($t1)
/*  f154588:	01d81823 */ 	subu	$v1,$t6,$t8
/*  f15458c:	2861f449 */ 	slti	$at,$v1,-2999
/*  f154590:	14200011 */ 	bnez	$at,.L0f1545d8
/*  f154594:	28610bb8 */ 	slti	$at,$v1,0xbb8
/*  f154598:	1020000f */ 	beqz	$at,.L0f1545d8
/*  f15459c:	00000000 */ 	nop
/*  f1545a0:	00420019 */ 	multu	$v0,$v0
/*  f1545a4:	00007812 */ 	mflo	$t7
/*  f1545a8:	00000000 */ 	nop
/*  f1545ac:	00000000 */ 	nop
/*  f1545b0:	00630019 */ 	multu	$v1,$v1
/*  f1545b4:	0000c812 */ 	mflo	$t9
/*  f1545b8:	01f95821 */ 	addu	$t3,$t7,$t9
/*  f1545bc:	448b2000 */ 	mtc1	$t3,$f4
/*  f1545c0:	0c012974 */ 	jal	sqrtf
/*  f1545c4:	46802320 */ 	cvt.s.w	$f12,$f4
/*  f1545c8:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f1545cc:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f1545d0:	10000003 */ 	b	.L0f1545e0
/*  f1545d4:	46000306 */ 	mov.s	$f12,$f0
.L0f1545d8:
/*  f1545d8:	3c017f1b */ 	lui	$at,%hi(var7f1b7404)
/*  f1545dc:	c42c7404 */ 	lwc1	$f12,%lo(var7f1b7404)($at)
.L0f1545e0:
/*  f1545e0:	3c0a8008 */ 	lui	$t2,%hi(var8007fbac)
/*  f1545e4:	8d4afbac */ 	lw	$t2,%lo(var8007fbac)($t2)
/*  f1545e8:	3c014f80 */ 	lui	$at,0x4f80
/*  f1545ec:	3c0c8008 */ 	lui	$t4,%hi(var8007fbb0)
/*  f1545f0:	448a3000 */ 	mtc1	$t2,$f6
/*  f1545f4:	3c0d8008 */ 	lui	$t5,%hi(var8007fbb4)
/*  f1545f8:	05410004 */ 	bgez	$t2,.L0f15460c
/*  f1545fc:	468033a0 */ 	cvt.s.w	$f14,$f6
/*  f154600:	44814000 */ 	mtc1	$at,$f8
/*  f154604:	00000000 */ 	nop
/*  f154608:	46087380 */ 	add.s	$f14,$f14,$f8
.L0f15460c:
/*  f15460c:	8d8cfbb0 */ 	lw	$t4,%lo(var8007fbb0)($t4)
/*  f154610:	3c014f80 */ 	lui	$at,0x4f80
/*  f154614:	448c5000 */ 	mtc1	$t4,$f10
/*  f154618:	05810004 */ 	bgez	$t4,.L0f15462c
/*  f15461c:	468054a0 */ 	cvt.s.w	$f18,$f10
/*  f154620:	44812000 */ 	mtc1	$at,$f4
/*  f154624:	00000000 */ 	nop
/*  f154628:	46049480 */ 	add.s	$f18,$f18,$f4
.L0f15462c:
/*  f15462c:	8dadfbb4 */ 	lw	$t5,%lo(var8007fbb4)($t5)
/*  f154630:	3c014f80 */ 	lui	$at,0x4f80
/*  f154634:	448d3000 */ 	mtc1	$t5,$f6
/*  f154638:	05a10004 */ 	bgez	$t5,.L0f15464c
/*  f15463c:	46803420 */ 	cvt.s.w	$f16,$f6
/*  f154640:	44814000 */ 	mtc1	$at,$f8
/*  f154644:	00000000 */ 	nop
/*  f154648:	46088400 */ 	add.s	$f16,$f16,$f8
.L0f15464c:
/*  f15464c:	91220018 */ 	lbu	$v0,0x18($t1)
/*  f154650:	24010002 */ 	addiu	$at,$zero,0x2
/*  f154654:	14400095 */ 	bnez	$v0,.L0f1548ac
/*  f154658:	00000000 */ 	nop
/*  f15465c:	c5200014 */ 	lwc1	$f0,0x14($t1)
/*  f154660:	460c003c */ 	c.lt.s	$f0,$f12
/*  f154664:	00000000 */ 	nop
/*  f154668:	45020004 */ 	bc1fl	.L0f15467c
/*  f15466c:	460e0081 */ 	sub.s	$f2,$f0,$f14
/*  f154670:	100001b9 */ 	b	.L0f154d58
/*  f154674:	00008025 */ 	or	$s0,$zero,$zero
/*  f154678:	460e0081 */ 	sub.s	$f2,$f0,$f14
.L0f15467c:
/*  f15467c:	460c103c */ 	c.lt.s	$f2,$f12
/*  f154680:	00000000 */ 	nop
/*  f154684:	45020031 */ 	bc1fl	.L0f15474c
/*  f154688:	46107280 */ 	add.s	$f10,$f14,$f16
/*  f15468c:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f154690:	3c01437f */ 	lui	$at,0x437f
/*  f154694:	44813000 */ 	mtc1	$at,$f6
/*  f154698:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f15469c:	460e5103 */ 	div.s	$f4,$f10,$f14
/*  f1546a0:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f1546a4:	3c014f00 */ 	lui	$at,0x4f00
/*  f1546a8:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f1546ac:	444ef800 */ 	cfc1	$t6,$31
/*  f1546b0:	44d8f800 */ 	ctc1	$t8,$31
/*  f1546b4:	00000000 */ 	nop
/*  f1546b8:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f1546bc:	4458f800 */ 	cfc1	$t8,$31
/*  f1546c0:	00000000 */ 	nop
/*  f1546c4:	33180078 */ 	andi	$t8,$t8,0x78
/*  f1546c8:	53000013 */ 	beqzl	$t8,.L0f154718
/*  f1546cc:	44184000 */ 	mfc1	$t8,$f8
/*  f1546d0:	44814000 */ 	mtc1	$at,$f8
/*  f1546d4:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1546d8:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f1546dc:	44d8f800 */ 	ctc1	$t8,$31
/*  f1546e0:	00000000 */ 	nop
/*  f1546e4:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f1546e8:	4458f800 */ 	cfc1	$t8,$31
/*  f1546ec:	00000000 */ 	nop
/*  f1546f0:	33180078 */ 	andi	$t8,$t8,0x78
/*  f1546f4:	17000005 */ 	bnez	$t8,.L0f15470c
/*  f1546f8:	00000000 */ 	nop
/*  f1546fc:	44184000 */ 	mfc1	$t8,$f8
/*  f154700:	3c018000 */ 	lui	$at,0x8000
/*  f154704:	10000007 */ 	b	.L0f154724
/*  f154708:	0301c025 */ 	or	$t8,$t8,$at
.L0f15470c:
/*  f15470c:	10000005 */ 	b	.L0f154724
/*  f154710:	2418ffff */ 	addiu	$t8,$zero,-1
/*  f154714:	44184000 */ 	mfc1	$t8,$f8
.L0f154718:
/*  f154718:	00000000 */ 	nop
/*  f15471c:	0700fffb */ 	bltz	$t8,.L0f15470c
/*  f154720:	00000000 */ 	nop
.L0f154724:
/*  f154724:	00f81023 */ 	subu	$v0,$a3,$t8
/*  f154728:	00027a00 */ 	sll	$t7,$v0,0x8
/*  f15472c:	01e2c825 */ 	or	$t9,$t7,$v0
/*  f154730:	00025c00 */ 	sll	$t3,$v0,0x10
/*  f154734:	032b5025 */ 	or	$t2,$t9,$t3
/*  f154738:	00026600 */ 	sll	$t4,$v0,0x18
/*  f15473c:	44cef800 */ 	ctc1	$t6,$31
/*  f154740:	10000185 */ 	b	.L0f154d58
/*  f154744:	014c8025 */ 	or	$s0,$t2,$t4
/*  f154748:	46107280 */ 	add.s	$f10,$f14,$f16
.L0f15474c:
/*  f15474c:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f154750:	460c203c */ 	c.lt.s	$f4,$f12
/*  f154754:	00000000 */ 	nop
/*  f154758:	45020004 */ 	bc1fl	.L0f15476c
/*  f15475c:	46127180 */ 	add.s	$f6,$f14,$f18
/*  f154760:	1000017d */ 	b	.L0f154d58
/*  f154764:	2410ffff */ 	addiu	$s0,$zero,-1
/*  f154768:	46127180 */ 	add.s	$f6,$f14,$f18
.L0f15476c:
/*  f15476c:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f154770:	46080081 */ 	sub.s	$f2,$f0,$f8
/*  f154774:	460c103c */ 	c.lt.s	$f2,$f12
/*  f154778:	00000000 */ 	nop
/*  f15477c:	45020177 */ 	bc1fl	.L0f154d5c
/*  f154780:	912a0000 */ 	lbu	$t2,0x0($t1)
/*  f154784:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f154788:	3c01437f */ 	lui	$at,0x437f
/*  f15478c:	44813000 */ 	mtc1	$at,$f6
/*  f154790:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f154794:	46125103 */ 	div.s	$f4,$f10,$f18
/*  f154798:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f15479c:	3c014f00 */ 	lui	$at,0x4f00
/*  f1547a0:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f1547a4:	444df800 */ 	cfc1	$t5,$31
/*  f1547a8:	44c4f800 */ 	ctc1	$a0,$31
/*  f1547ac:	00000000 */ 	nop
/*  f1547b0:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f1547b4:	4444f800 */ 	cfc1	$a0,$31
/*  f1547b8:	00000000 */ 	nop
/*  f1547bc:	30840078 */ 	andi	$a0,$a0,0x78
/*  f1547c0:	50800013 */ 	beqzl	$a0,.L0f154810
/*  f1547c4:	44044000 */ 	mfc1	$a0,$f8
/*  f1547c8:	44814000 */ 	mtc1	$at,$f8
/*  f1547cc:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1547d0:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f1547d4:	44c4f800 */ 	ctc1	$a0,$31
/*  f1547d8:	00000000 */ 	nop
/*  f1547dc:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f1547e0:	4444f800 */ 	cfc1	$a0,$31
/*  f1547e4:	00000000 */ 	nop
/*  f1547e8:	30840078 */ 	andi	$a0,$a0,0x78
/*  f1547ec:	14800005 */ 	bnez	$a0,.L0f154804
/*  f1547f0:	00000000 */ 	nop
/*  f1547f4:	44044000 */ 	mfc1	$a0,$f8
/*  f1547f8:	3c018000 */ 	lui	$at,0x8000
/*  f1547fc:	10000007 */ 	b	.L0f15481c
/*  f154800:	00812025 */ 	or	$a0,$a0,$at
.L0f154804:
/*  f154804:	10000005 */ 	b	.L0f15481c
/*  f154808:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f15480c:	44044000 */ 	mfc1	$a0,$f8
.L0f154810:
/*  f154810:	00000000 */ 	nop
/*  f154814:	0480fffb */ 	bltz	$a0,.L0f154804
/*  f154818:	00000000 */ 	nop
.L0f15481c:
/*  f15481c:	00870019 */ 	multu	$a0,$a3
/*  f154820:	00107602 */ 	srl	$t6,$s0,0x18
/*  f154824:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f154828:	00e41023 */ 	subu	$v0,$a3,$a0
/*  f15482c:	44cdf800 */ 	ctc1	$t5,$31
/*  f154830:	00106402 */ 	srl	$t4,$s0,0x10
/*  f154834:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f154838:	00106202 */ 	srl	$t4,$s0,0x8
/*  f15483c:	00001812 */ 	mflo	$v1
/*  f154840:	00000000 */ 	nop
/*  f154844:	00000000 */ 	nop
/*  f154848:	03020019 */ 	multu	$t8,$v0
/*  f15484c:	00007812 */ 	mflo	$t7
/*  f154850:	01e3c821 */ 	addu	$t9,$t7,$v1
/*  f154854:	00195a02 */ 	srl	$t3,$t9,0x8
/*  f154858:	01a20019 */ 	multu	$t5,$v0
/*  f15485c:	318d00ff */ 	andi	$t5,$t4,0xff
/*  f154860:	320c00ff */ 	andi	$t4,$s0,0xff
/*  f154864:	000b5600 */ 	sll	$t2,$t3,0x18
/*  f154868:	00007012 */ 	mflo	$t6
/*  f15486c:	01c3c021 */ 	addu	$t8,$t6,$v1
/*  f154870:	00187a02 */ 	srl	$t7,$t8,0x8
/*  f154874:	01a20019 */ 	multu	$t5,$v0
/*  f154878:	000fcc00 */ 	sll	$t9,$t7,0x10
/*  f15487c:	01595825 */ 	or	$t3,$t2,$t9
/*  f154880:	00007012 */ 	mflo	$t6
/*  f154884:	01c3c021 */ 	addu	$t8,$t6,$v1
/*  f154888:	00187a02 */ 	srl	$t7,$t8,0x8
/*  f15488c:	01820019 */ 	multu	$t4,$v0
/*  f154890:	000f5200 */ 	sll	$t2,$t7,0x8
/*  f154894:	016ac825 */ 	or	$t9,$t3,$t2
/*  f154898:	00006812 */ 	mflo	$t5
/*  f15489c:	01a37021 */ 	addu	$t6,$t5,$v1
/*  f1548a0:	000ec202 */ 	srl	$t8,$t6,0x8
/*  f1548a4:	1000012c */ 	b	.L0f154d58
/*  f1548a8:	03388025 */ 	or	$s0,$t9,$t8
.L0f1548ac:
/*  f1548ac:	1441007f */ 	bne	$v0,$at,.L0f154aac
/*  f1548b0:	3c047f1b */ 	lui	$a0,%hi(var7f1b73b0)
/*  f1548b4:	c5200014 */ 	lwc1	$f0,0x14($t1)
/*  f1548b8:	460c003c */ 	c.lt.s	$f0,$f12
/*  f1548bc:	00000000 */ 	nop
/*  f1548c0:	45020004 */ 	bc1fl	.L0f1548d4
/*  f1548c4:	44807000 */ 	mtc1	$zero,$f14
/*  f1548c8:	10000123 */ 	b	.L0f154d58
/*  f1548cc:	00008025 */ 	or	$s0,$zero,$zero
/*  f1548d0:	44807000 */ 	mtc1	$zero,$f14
.L0f1548d4:
/*  f1548d4:	00000000 */ 	nop
/*  f1548d8:	460e0081 */ 	sub.s	$f2,$f0,$f14
/*  f1548dc:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1548e0:	00000000 */ 	nop
/*  f1548e4:	45020030 */ 	bc1fl	.L0f1549a8
/*  f1548e8:	44805000 */ 	mtc1	$zero,$f10
/*  f1548ec:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f1548f0:	3c01437f */ 	lui	$at,0x437f
/*  f1548f4:	44813000 */ 	mtc1	$at,$f6
/*  f1548f8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1548fc:	460e5103 */ 	div.s	$f4,$f10,$f14
/*  f154900:	3c014f00 */ 	lui	$at,0x4f00
/*  f154904:	00002025 */ 	or	$a0,$zero,$zero
/*  f154908:	320500ff */ 	andi	$a1,$s0,0xff
/*  f15490c:	46062002 */ 	mul.s	$f0,$f4,$f6
/*  f154910:	444ff800 */ 	cfc1	$t7,$31
/*  f154914:	44c6f800 */ 	ctc1	$a2,$31
/*  f154918:	00000000 */ 	nop
/*  f15491c:	46000224 */ 	cvt.w.s	$f8,$f0
/*  f154920:	4446f800 */ 	cfc1	$a2,$31
/*  f154924:	00000000 */ 	nop
/*  f154928:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f15492c:	50c00013 */ 	beqzl	$a2,.L0f15497c
/*  f154930:	44064000 */ 	mfc1	$a2,$f8
/*  f154934:	44814000 */ 	mtc1	$at,$f8
/*  f154938:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f15493c:	46080201 */ 	sub.s	$f8,$f0,$f8
/*  f154940:	44c6f800 */ 	ctc1	$a2,$31
/*  f154944:	00000000 */ 	nop
/*  f154948:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f15494c:	4446f800 */ 	cfc1	$a2,$31
/*  f154950:	00000000 */ 	nop
/*  f154954:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f154958:	14c00005 */ 	bnez	$a2,.L0f154970
/*  f15495c:	00000000 */ 	nop
/*  f154960:	44064000 */ 	mfc1	$a2,$f8
/*  f154964:	3c018000 */ 	lui	$at,0x8000
/*  f154968:	10000007 */ 	b	.L0f154988
/*  f15496c:	00c13025 */ 	or	$a2,$a2,$at
.L0f154970:
/*  f154970:	10000005 */ 	b	.L0f154988
/*  f154974:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f154978:	44064000 */ 	mfc1	$a2,$f8
.L0f15497c:
/*  f15497c:	00000000 */ 	nop
/*  f154980:	04c0fffb */ 	bltz	$a2,.L0f154970
/*  f154984:	00000000 */ 	nop
.L0f154988:
/*  f154988:	44cff800 */ 	ctc1	$t7,$31
/*  f15498c:	0fc01a40 */ 	jal	colourBlend
/*  f154990:	00000000 */ 	nop
/*  f154994:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154998:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f15499c:	100000ee */ 	b	.L0f154d58
/*  f1549a0:	00408025 */ 	or	$s0,$v0,$zero
/*  f1549a4:	44805000 */ 	mtc1	$zero,$f10
.L0f1549a8:
/*  f1549a8:	3c014284 */ 	lui	$at,0x4284
/*  f1549ac:	320b00ff */ 	andi	$t3,$s0,0xff
/*  f1549b0:	460a7100 */ 	add.s	$f4,$f14,$f10
/*  f1549b4:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f1549b8:	460c303c */ 	c.lt.s	$f6,$f12
/*  f1549bc:	00000000 */ 	nop
/*  f1549c0:	45020004 */ 	bc1fl	.L0f1549d4
/*  f1549c4:	44818000 */ 	mtc1	$at,$f16
/*  f1549c8:	100000e3 */ 	b	.L0f154d58
/*  f1549cc:	01608025 */ 	or	$s0,$t3,$zero
/*  f1549d0:	44818000 */ 	mtc1	$at,$f16
.L0f1549d4:
/*  f1549d4:	44805000 */ 	mtc1	$zero,$f10
/*  f1549d8:	46107200 */ 	add.s	$f8,$f14,$f16
/*  f1549dc:	460a4100 */ 	add.s	$f4,$f8,$f10
/*  f1549e0:	46040081 */ 	sub.s	$f2,$f0,$f4
/*  f1549e4:	460c103c */ 	c.lt.s	$f2,$f12
/*  f1549e8:	00000000 */ 	nop
/*  f1549ec:	450200db */ 	bc1fl	.L0f154d5c
/*  f1549f0:	912a0000 */ 	lbu	$t2,0x0($t1)
/*  f1549f4:	46026181 */ 	sub.s	$f6,$f12,$f2
/*  f1549f8:	3c01437f */ 	lui	$at,0x437f
/*  f1549fc:	44815000 */ 	mtc1	$at,$f10
/*  f154a00:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f154a04:	46103203 */ 	div.s	$f8,$f6,$f16
/*  f154a08:	3c014f00 */ 	lui	$at,0x4f00
/*  f154a0c:	00002025 */ 	or	$a0,$zero,$zero
/*  f154a10:	02002825 */ 	or	$a1,$s0,$zero
/*  f154a14:	460a4002 */ 	mul.s	$f0,$f8,$f10
/*  f154a18:	444af800 */ 	cfc1	$t2,$31
/*  f154a1c:	44c6f800 */ 	ctc1	$a2,$31
/*  f154a20:	00000000 */ 	nop
/*  f154a24:	46000124 */ 	cvt.w.s	$f4,$f0
/*  f154a28:	4446f800 */ 	cfc1	$a2,$31
/*  f154a2c:	00000000 */ 	nop
/*  f154a30:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f154a34:	50c00013 */ 	beqzl	$a2,.L0f154a84
/*  f154a38:	44062000 */ 	mfc1	$a2,$f4
/*  f154a3c:	44812000 */ 	mtc1	$at,$f4
/*  f154a40:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f154a44:	46040101 */ 	sub.s	$f4,$f0,$f4
/*  f154a48:	44c6f800 */ 	ctc1	$a2,$31
/*  f154a4c:	00000000 */ 	nop
/*  f154a50:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f154a54:	4446f800 */ 	cfc1	$a2,$31
/*  f154a58:	00000000 */ 	nop
/*  f154a5c:	30c60078 */ 	andi	$a2,$a2,0x78
/*  f154a60:	14c00005 */ 	bnez	$a2,.L0f154a78
/*  f154a64:	00000000 */ 	nop
/*  f154a68:	44062000 */ 	mfc1	$a2,$f4
/*  f154a6c:	3c018000 */ 	lui	$at,0x8000
/*  f154a70:	10000007 */ 	b	.L0f154a90
/*  f154a74:	00c13025 */ 	or	$a2,$a2,$at
.L0f154a78:
/*  f154a78:	10000005 */ 	b	.L0f154a90
/*  f154a7c:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f154a80:	44062000 */ 	mfc1	$a2,$f4
.L0f154a84:
/*  f154a84:	00000000 */ 	nop
/*  f154a88:	04c0fffb */ 	bltz	$a2,.L0f154a78
/*  f154a8c:	00000000 */ 	nop
.L0f154a90:
/*  f154a90:	44caf800 */ 	ctc1	$t2,$31
/*  f154a94:	0fc01a40 */ 	jal	colourBlend
/*  f154a98:	00000000 */ 	nop
/*  f154a9c:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154aa0:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154aa4:	100000ac */ 	b	.L0f154d58
/*  f154aa8:	00408025 */ 	or	$s0,$v0,$zero
.L0f154aac:
/*  f154aac:	320200ff */ 	andi	$v0,$s0,0xff
/*  f154ab0:	3c058008 */ 	lui	$a1,%hi(var8007fbc8)
/*  f154ab4:	afa20050 */ 	sw	$v0,0x50($sp)
/*  f154ab8:	24a5fbc8 */ 	addiu	$a1,$a1,%lo(var8007fbc8)
/*  f154abc:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f154ac0:	248473b0 */ 	addiu	$a0,$a0,%lo(var7f1b73b0)
/*  f154ac4:	e7ac0084 */ 	swc1	$f12,0x84($sp)
/*  f154ac8:	0c0036cc */ 	jal	mainOverrideVariable
/*  f154acc:	e7ae00a4 */ 	swc1	$f14,0xa4($sp)
/*  f154ad0:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154ad4:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154ad8:	c7ac0084 */ 	lwc1	$f12,0x84($sp)
/*  f154adc:	c5200014 */ 	lwc1	$f0,0x14($t1)
/*  f154ae0:	8fa20024 */ 	lw	$v0,0x24($sp)
/*  f154ae4:	c7ae00a4 */ 	lwc1	$f14,0xa4($sp)
/*  f154ae8:	460c003c */ 	c.lt.s	$f0,$f12
/*  f154aec:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f154af0:	02002825 */ 	or	$a1,$s0,$zero
/*  f154af4:	45020008 */ 	bc1fl	.L0f154b18
/*  f154af8:	460e0081 */ 	sub.s	$f2,$f0,$f14
/*  f154afc:	0fc01a40 */ 	jal	colourBlend
/*  f154b00:	2406006e */ 	addiu	$a2,$zero,0x6e
/*  f154b04:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154b08:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154b0c:	10000092 */ 	b	.L0f154d58
/*  f154b10:	00408025 */ 	or	$s0,$v0,$zero
/*  f154b14:	460e0081 */ 	sub.s	$f2,$f0,$f14
.L0f154b18:
/*  f154b18:	3c0141b0 */ 	lui	$at,0x41b0
/*  f154b1c:	460c103c */ 	c.lt.s	$f2,$f12
/*  f154b20:	00000000 */ 	nop
/*  f154b24:	4502003d */ 	bc1fl	.L0f154c1c
/*  f154b28:	44818000 */ 	mtc1	$at,$f16
/*  f154b2c:	46026181 */ 	sub.s	$f6,$f12,$f2
/*  f154b30:	3c01437f */ 	lui	$at,0x437f
/*  f154b34:	44815000 */ 	mtc1	$at,$f10
/*  f154b38:	3c0c8008 */ 	lui	$t4,%hi(var8007fbc8)
/*  f154b3c:	460e3203 */ 	div.s	$f8,$f6,$f14
/*  f154b40:	8d8cfbc8 */ 	lw	$t4,%lo(var8007fbc8)($t4)
/*  f154b44:	02002825 */ 	or	$a1,$s0,$zero
/*  f154b48:	240600c0 */ 	addiu	$a2,$zero,0xc0
/*  f154b4c:	01822025 */ 	or	$a0,$t4,$v0
/*  f154b50:	460a4102 */ 	mul.s	$f4,$f8,$f10
/*  f154b54:	0fc01a40 */ 	jal	colourBlend
/*  f154b58:	e7a4004c */ 	swc1	$f4,0x4c($sp)
/*  f154b5c:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f154b60:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f154b64:	02002825 */ 	or	$a1,$s0,$zero
/*  f154b68:	0fc01a40 */ 	jal	colourBlend
/*  f154b6c:	2406006e */ 	addiu	$a2,$zero,0x6e
/*  f154b70:	444df800 */ 	cfc1	$t5,$31
/*  f154b74:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f154b78:	44cef800 */ 	ctc1	$t6,$31
/*  f154b7c:	c7a6004c */ 	lwc1	$f6,0x4c($sp)
/*  f154b80:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f154b84:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f154b88:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f154b8c:	00402825 */ 	or	$a1,$v0,$zero
/*  f154b90:	3c014f00 */ 	lui	$at,0x4f00
/*  f154b94:	444ef800 */ 	cfc1	$t6,$31
/*  f154b98:	00000000 */ 	nop
/*  f154b9c:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f154ba0:	51c00013 */ 	beqzl	$t6,.L0f154bf0
/*  f154ba4:	440e4000 */ 	mfc1	$t6,$f8
/*  f154ba8:	44814000 */ 	mtc1	$at,$f8
/*  f154bac:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f154bb0:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f154bb4:	44cef800 */ 	ctc1	$t6,$31
/*  f154bb8:	00000000 */ 	nop
/*  f154bbc:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f154bc0:	444ef800 */ 	cfc1	$t6,$31
/*  f154bc4:	00000000 */ 	nop
/*  f154bc8:	31ce0078 */ 	andi	$t6,$t6,0x78
/*  f154bcc:	15c00005 */ 	bnez	$t6,.L0f154be4
/*  f154bd0:	00000000 */ 	nop
/*  f154bd4:	440e4000 */ 	mfc1	$t6,$f8
/*  f154bd8:	3c018000 */ 	lui	$at,0x8000
/*  f154bdc:	10000007 */ 	b	.L0f154bfc
/*  f154be0:	01c17025 */ 	or	$t6,$t6,$at
.L0f154be4:
/*  f154be4:	10000005 */ 	b	.L0f154bfc
/*  f154be8:	240effff */ 	addiu	$t6,$zero,-1
/*  f154bec:	440e4000 */ 	mfc1	$t6,$f8
.L0f154bf0:
/*  f154bf0:	00000000 */ 	nop
/*  f154bf4:	05c0fffb */ 	bltz	$t6,.L0f154be4
/*  f154bf8:	00000000 */ 	nop
.L0f154bfc:
/*  f154bfc:	44cdf800 */ 	ctc1	$t5,$31
/*  f154c00:	0fc01a40 */ 	jal	colourBlend
/*  f154c04:	00ee3023 */ 	subu	$a2,$a3,$t6
/*  f154c08:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154c0c:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154c10:	10000051 */ 	b	.L0f154d58
/*  f154c14:	00408025 */ 	or	$s0,$v0,$zero
/*  f154c18:	44818000 */ 	mtc1	$at,$f16
.L0f154c1c:
/*  f154c1c:	3c014248 */ 	lui	$at,0x4248
/*  f154c20:	3c198008 */ 	lui	$t9,%hi(var8007fbc8)
/*  f154c24:	46107280 */ 	add.s	$f10,$f14,$f16
/*  f154c28:	02002825 */ 	or	$a1,$s0,$zero
/*  f154c2c:	460a0101 */ 	sub.s	$f4,$f0,$f10
/*  f154c30:	460c203c */ 	c.lt.s	$f4,$f12
/*  f154c34:	00000000 */ 	nop
/*  f154c38:	4502000a */ 	bc1fl	.L0f154c64
/*  f154c3c:	44819000 */ 	mtc1	$at,$f18
/*  f154c40:	8f39fbc8 */ 	lw	$t9,%lo(var8007fbc8)($t9)
/*  f154c44:	240600c0 */ 	addiu	$a2,$zero,0xc0
/*  f154c48:	0fc01a40 */ 	jal	colourBlend
/*  f154c4c:	03222025 */ 	or	$a0,$t9,$v0
/*  f154c50:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154c54:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154c58:	1000003f */ 	b	.L0f154d58
/*  f154c5c:	00408025 */ 	or	$s0,$v0,$zero
/*  f154c60:	44819000 */ 	mtc1	$at,$f18
.L0f154c64:
/*  f154c64:	00000000 */ 	nop
/*  f154c68:	46127180 */ 	add.s	$f6,$f14,$f18
/*  f154c6c:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f154c70:	46080081 */ 	sub.s	$f2,$f0,$f8
/*  f154c74:	460c103c */ 	c.lt.s	$f2,$f12
/*  f154c78:	00000000 */ 	nop
/*  f154c7c:	45020037 */ 	bc1fl	.L0f154d5c
/*  f154c80:	912a0000 */ 	lbu	$t2,0x0($t1)
/*  f154c84:	46026281 */ 	sub.s	$f10,$f12,$f2
/*  f154c88:	3c01437f */ 	lui	$at,0x437f
/*  f154c8c:	44813000 */ 	mtc1	$at,$f6
/*  f154c90:	3c188008 */ 	lui	$t8,%hi(var8007fbc8)
/*  f154c94:	46125103 */ 	div.s	$f4,$f10,$f18
/*  f154c98:	8f18fbc8 */ 	lw	$t8,%lo(var8007fbc8)($t8)
/*  f154c9c:	02002825 */ 	or	$a1,$s0,$zero
/*  f154ca0:	240600c0 */ 	addiu	$a2,$zero,0xc0
/*  f154ca4:	03022025 */ 	or	$a0,$t8,$v0
/*  f154ca8:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f154cac:	0fc01a40 */ 	jal	colourBlend
/*  f154cb0:	e7a80044 */ 	swc1	$f8,0x44($sp)
/*  f154cb4:	444ff800 */ 	cfc1	$t7,$31
/*  f154cb8:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f154cbc:	44cbf800 */ 	ctc1	$t3,$31
/*  f154cc0:	c7aa0044 */ 	lwc1	$f10,0x44($sp)
/*  f154cc4:	240700ff */ 	addiu	$a3,$zero,0xff
/*  f154cc8:	02002025 */ 	or	$a0,$s0,$zero
/*  f154ccc:	46005124 */ 	cvt.w.s	$f4,$f10
/*  f154cd0:	00402825 */ 	or	$a1,$v0,$zero
/*  f154cd4:	3c014f00 */ 	lui	$at,0x4f00
/*  f154cd8:	444bf800 */ 	cfc1	$t3,$31
/*  f154cdc:	00000000 */ 	nop
/*  f154ce0:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f154ce4:	51600013 */ 	beqzl	$t3,.L0f154d34
/*  f154ce8:	440b2000 */ 	mfc1	$t3,$f4
/*  f154cec:	44812000 */ 	mtc1	$at,$f4
/*  f154cf0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f154cf4:	46045101 */ 	sub.s	$f4,$f10,$f4
/*  f154cf8:	44cbf800 */ 	ctc1	$t3,$31
/*  f154cfc:	00000000 */ 	nop
/*  f154d00:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f154d04:	444bf800 */ 	cfc1	$t3,$31
/*  f154d08:	00000000 */ 	nop
/*  f154d0c:	316b0078 */ 	andi	$t3,$t3,0x78
/*  f154d10:	15600005 */ 	bnez	$t3,.L0f154d28
/*  f154d14:	00000000 */ 	nop
/*  f154d18:	440b2000 */ 	mfc1	$t3,$f4
/*  f154d1c:	3c018000 */ 	lui	$at,0x8000
/*  f154d20:	10000007 */ 	b	.L0f154d40
/*  f154d24:	01615825 */ 	or	$t3,$t3,$at
.L0f154d28:
/*  f154d28:	10000005 */ 	b	.L0f154d40
/*  f154d2c:	240bffff */ 	addiu	$t3,$zero,-1
/*  f154d30:	440b2000 */ 	mfc1	$t3,$f4
.L0f154d34:
/*  f154d34:	00000000 */ 	nop
/*  f154d38:	0560fffb */ 	bltz	$t3,.L0f154d28
/*  f154d3c:	00000000 */ 	nop
.L0f154d40:
/*  f154d40:	44cff800 */ 	ctc1	$t7,$31
/*  f154d44:	0fc01a40 */ 	jal	colourBlend
/*  f154d48:	00eb3023 */ 	subu	$a2,$a3,$t3
/*  f154d4c:	3c09800a */ 	lui	$t1,%hi(var800a45d0)
/*  f154d50:	252945d0 */ 	addiu	$t1,$t1,%lo(var800a45d0)
/*  f154d54:	00408025 */ 	or	$s0,$v0,$zero
.L0f154d58:
/*  f154d58:	912a0000 */ 	lbu	$t2,0x0($t1)
.L0f154d5c:
/*  f154d5c:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f154d60:	314c0004 */ 	andi	$t4,$t2,0x4
/*  f154d64:	51800055 */ 	beqzl	$t4,.L0f154ebc
/*  f154d68:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f154d6c:	8d2d004c */ 	lw	$t5,0x4c($t1)
/*  f154d70:	8d380050 */ 	lw	$t8,0x50($t1)
/*  f154d74:	8fab00ac */ 	lw	$t3,0xac($sp)
/*  f154d78:	01aec823 */ 	subu	$t9,$t5,$t6
/*  f154d7c:	03387821 */ 	addu	$t7,$t9,$t8
/*  f154d80:	01eb5023 */ 	subu	$t2,$t7,$t3
/*  f154d84:	254c0320 */ 	addiu	$t4,$t2,0x320
/*  f154d88:	448c3000 */ 	mtc1	$t4,$f6
/*  f154d8c:	8d2d0054 */ 	lw	$t5,0x54($t1)
/*  f154d90:	3c014080 */ 	lui	$at,0x4080
/*  f154d94:	46803020 */ 	cvt.s.w	$f0,$f6
/*  f154d98:	44811000 */ 	mtc1	$at,$f2
/*  f154d9c:	448d5000 */ 	mtc1	$t5,$f10
/*  f154da0:	3c013f80 */ 	lui	$at,0x3f80
/*  f154da4:	44816000 */ 	mtc1	$at,$f12
/*  f154da8:	46805120 */ 	cvt.s.w	$f4,$f10
/*  f154dac:	46001202 */ 	mul.s	$f8,$f2,$f0
/*  f154db0:	3c013e80 */ 	lui	$at,0x3e80
/*  f154db4:	44813000 */ 	mtc1	$at,$f6
/*  f154db8:	3c014000 */ 	lui	$at,0x4000
/*  f154dbc:	320200ff */ 	andi	$v0,$s0,0xff
/*  f154dc0:	3c188008 */ 	lui	$t8,%hi(var8007fbbc)
/*  f154dc4:	3c0a8008 */ 	lui	$t2,%hi(var8007fbb8)
/*  f154dc8:	46044003 */ 	div.s	$f0,$f8,$f4
/*  f154dcc:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f154dd0:	4600520d */ 	trunc.w.s	$f8,$f10
/*  f154dd4:	44194000 */ 	mfc1	$t9,$f8
/*  f154dd8:	00000000 */ 	nop
/*  f154ddc:	44992000 */ 	mtc1	$t9,$f4
/*  f154de0:	00000000 */ 	nop
/*  f154de4:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f154de8:	44802000 */ 	mtc1	$zero,$f4
/*  f154dec:	46023282 */ 	mul.s	$f10,$f6,$f2
/*  f154df0:	460a0001 */ 	sub.s	$f0,$f0,$f10
/*  f154df4:	460c0001 */ 	sub.s	$f0,$f0,$f12
/*  f154df8:	4600603c */ 	c.lt.s	$f12,$f0
/*  f154dfc:	00000000 */ 	nop
/*  f154e00:	45020005 */ 	bc1fl	.L0f154e18
/*  f154e04:	4604003c */ 	c.lt.s	$f0,$f4
/*  f154e08:	44814000 */ 	mtc1	$at,$f8
/*  f154e0c:	00000000 */ 	nop
/*  f154e10:	46004001 */ 	sub.s	$f0,$f8,$f0
/*  f154e14:	4604003c */ 	c.lt.s	$f0,$f4
.L0f154e18:
/*  f154e18:	00000000 */ 	nop
/*  f154e1c:	45000015 */ 	bc1f	.L0f154e74
/*  f154e20:	00000000 */ 	nop
/*  f154e24:	8f18fbbc */ 	lw	$t8,%lo(var8007fbbc)($t8)
/*  f154e28:	44802000 */ 	mtc1	$zero,$f4
/*  f154e2c:	3c014f80 */ 	lui	$at,0x4f80
/*  f154e30:	44983000 */ 	mtc1	$t8,$f6
/*  f154e34:	07010004 */ 	bgez	$t8,.L0f154e48
/*  f154e38:	468032a0 */ 	cvt.s.w	$f10,$f6
/*  f154e3c:	44814000 */ 	mtc1	$at,$f8
/*  f154e40:	00000000 */ 	nop
/*  f154e44:	46085280 */ 	add.s	$f10,$f10,$f8
.L0f154e48:
/*  f154e48:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f154e4c:	8d2b0058 */ 	lw	$t3,0x58($t1)
/*  f154e50:	02002825 */ 	or	$a1,$s0,$zero
/*  f154e54:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f154e58:	004b2025 */ 	or	$a0,$v0,$t3
/*  f154e5c:	4600410d */ 	trunc.w.s	$f4,$f8
/*  f154e60:	44062000 */ 	mfc1	$a2,$f4
/*  f154e64:	0fc01a40 */ 	jal	colourBlend
/*  f154e68:	00000000 */ 	nop
/*  f154e6c:	10000012 */ 	b	.L0f154eb8
/*  f154e70:	00408025 */ 	or	$s0,$v0,$zero
.L0f154e74:
/*  f154e74:	8d4afbb8 */ 	lw	$t2,%lo(var8007fbb8)($t2)
/*  f154e78:	3c014f80 */ 	lui	$at,0x4f80
/*  f154e7c:	448a5000 */ 	mtc1	$t2,$f10
/*  f154e80:	05410004 */ 	bgez	$t2,.L0f154e94
/*  f154e84:	468051a0 */ 	cvt.s.w	$f6,$f10
/*  f154e88:	44814000 */ 	mtc1	$at,$f8
/*  f154e8c:	00000000 */ 	nop
/*  f154e90:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f154e94:
/*  f154e94:	46003102 */ 	mul.s	$f4,$f6,$f0
/*  f154e98:	8d2d005c */ 	lw	$t5,0x5c($t1)
/*  f154e9c:	02002825 */ 	or	$a1,$s0,$zero
/*  f154ea0:	004d2025 */ 	or	$a0,$v0,$t5
/*  f154ea4:	4600228d */ 	trunc.w.s	$f10,$f4
/*  f154ea8:	44065000 */ 	mfc1	$a2,$f10
/*  f154eac:	0fc01a40 */ 	jal	colourBlend
/*  f154eb0:	00000000 */ 	nop
/*  f154eb4:	00408025 */ 	or	$s0,$v0,$zero
.L0f154eb8:
/*  f154eb8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f154ebc:
/*  f154ebc:	02001025 */ 	or	$v0,$s0,$zero
/*  f154ec0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f154ec4:	03e00008 */ 	jr	$ra
/*  f154ec8:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

Gfx *func0f154ecc(Gfx *gdl, u32 arg1, u32 arg2)
{
	u32 colour = func0f1543ac(arg1, arg2, var800a45d0.colour04);

	if (colour != var800a45d0.colour44) {
		gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
	}

	var800a45d0.colour44 = colour;

	return gdl;
}

#if VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f155c4cpf
.late_rodata
glabel var7f1b8738pf
.word func0f155c4cpf+0xd0
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd0
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd0
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd0
.word func0f155c4cpf+0x28
.word func0f155c4cpf+0x28
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0x28
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0x34
.word func0f155c4cpf+0x34
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0x40
.word func0f155c4cpf+0x40
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xa0
.word func0f155c4cpf+0x4c
.word func0f155c4cpf+0x4c
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0x4c
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0x58
.word func0f155c4cpf+0x58
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0x58
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xc4
.word func0f155c4cpf+0x64
.word func0f155c4cpf+0x64
.word func0f155c4cpf+0x64
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0x64
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xb8
.word func0f155c4cpf+0x70
.word func0f155c4cpf+0x70
.word func0f155c4cpf+0x70
.word func0f155c4cpf+0x70
.word func0f155c4cpf+0x7c
.word func0f155c4cpf+0x7c
.word func0f155c4cpf+0x7c
.word func0f155c4cpf+0x7c
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xac
.word func0f155c4cpf+0x88
.word func0f155c4cpf+0x88
.word func0f155c4cpf+0x88
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0x88
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0xd8
.word func0f155c4cpf+0x94
.word func0f155c4cpf+0x94
.word func0f155c4cpf+0x94
.word func0f155c4cpf+0x94
.text
/*  f155c4c:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f155c50:	25cfff5f */ 	addiu	$t7,$t6,-161
/*  f155c54:	2de1005c */ 	sltiu	$at,$t7,0x5c
/*  f155c58:	10200032 */ 	beqz	$at,.PF0f155d24
/*  f155c5c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f155c60:	3c017f1c */ 	lui	$at,%hi(var7f1b8738pf)
/*  f155c64:	002f0821 */ 	addu	$at,$at,$t7
/*  f155c68:	8c2f8738 */ 	lw	$t7,%lo(var7f1b8738pf)($at)
/*  f155c6c:	01e00008 */ 	jr	$t7
/*  f155c70:	00000000 */ 	nop
/*  f155c74:	24180041 */ 	li	$t8,0x41
/*  f155c78:	03e00008 */ 	jr	$ra
/*  f155c7c:	a0980000 */ 	sb	$t8,0x0($a0)
/*  f155c80:	24190045 */ 	li	$t9,0x45
/*  f155c84:	03e00008 */ 	jr	$ra
/*  f155c88:	a0990000 */ 	sb	$t9,0x0($a0)
/*  f155c8c:	24080049 */ 	li	$t0,0x49
/*  f155c90:	03e00008 */ 	jr	$ra
/*  f155c94:	a0880000 */ 	sb	$t0,0x0($a0)
/*  f155c98:	2409004f */ 	li	$t1,0x4f
/*  f155c9c:	03e00008 */ 	jr	$ra
/*  f155ca0:	a0890000 */ 	sb	$t1,0x0($a0)
/*  f155ca4:	240a0055 */ 	li	$t2,0x55
/*  f155ca8:	03e00008 */ 	jr	$ra
/*  f155cac:	a08a0000 */ 	sb	$t2,0x0($a0)
/*  f155cb0:	240b0061 */ 	li	$t3,0x61
/*  f155cb4:	03e00008 */ 	jr	$ra
/*  f155cb8:	a08b0000 */ 	sb	$t3,0x0($a0)
/*  f155cbc:	240c0065 */ 	li	$t4,0x65
/*  f155cc0:	03e00008 */ 	jr	$ra
/*  f155cc4:	a08c0000 */ 	sb	$t4,0x0($a0)
/*  f155cc8:	240d0069 */ 	li	$t5,0x69
/*  f155ccc:	03e00008 */ 	jr	$ra
/*  f155cd0:	a08d0000 */ 	sb	$t5,0x0($a0)
/*  f155cd4:	240e006f */ 	li	$t6,0x6f
/*  f155cd8:	03e00008 */ 	jr	$ra
/*  f155cdc:	a08e0000 */ 	sb	$t6,0x0($a0)
/*  f155ce0:	240f0075 */ 	li	$t7,0x75
/*  f155ce4:	03e00008 */ 	jr	$ra
/*  f155ce8:	a08f0000 */ 	sb	$t7,0x0($a0)
/*  f155cec:	2418004e */ 	li	$t8,0x4e
/*  f155cf0:	03e00008 */ 	jr	$ra
/*  f155cf4:	a0980000 */ 	sb	$t8,0x0($a0)
/*  f155cf8:	2419006e */ 	li	$t9,0x6e
/*  f155cfc:	03e00008 */ 	jr	$ra
/*  f155d00:	a0990000 */ 	sb	$t9,0x0($a0)
/*  f155d04:	24080063 */ 	li	$t0,0x63
/*  f155d08:	03e00008 */ 	jr	$ra
/*  f155d0c:	a0880000 */ 	sb	$t0,0x0($a0)
/*  f155d10:	24090042 */ 	li	$t1,0x42
/*  f155d14:	03e00008 */ 	jr	$ra
/*  f155d18:	a0890000 */ 	sb	$t1,0x0($a0)
/*  f155d1c:	240a0020 */ 	li	$t2,0x20
/*  f155d20:	a08a0000 */ 	sb	$t2,0x0($a0)
.PF0f155d24:
/*  f155d24:	03e00008 */ 	jr	$ra
/*  f155d28:	00000000 */ 	nop
);
#endif

#if VERSION == VERSION_JPN_FINAL
GLOBAL_ASM(
glabel func0f154784jf
.late_rodata
glabel var7f1b822cjf
.word 0x7f1548f4
.word 0x7f1548fc
.word 0x7f154904
.word 0x7f15490c
.word 0x7f154914
.word 0x7f15491c
.word 0x7f154924
.word 0x7f15492c
.word 0x7f154934
.word 0x7f15493c
.word 0x7f154944
.word 0x7f15494c
.word 0x7f154954
.word 0x7f15495c
.word 0x7f154874
.word 0x7f15487c
.word 0x7f154884
.word 0x7f15488c
.word 0x7f154894
.word 0x7f15489c
.word 0x7f1548a4
.word 0x7f1548ac
.word 0x7f1548b4
.word 0x7f1548bc
.word 0x7f1548c4
.word 0x7f1548cc
.word 0x7f1548d4
.word 0x7f1548dc
.word 0x7f1548e4
.word 0x7f1548ec
.text
/*  f154784:	308effff */ 	andi	$t6,$a0,0xffff
/*  f154788:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f15478c:	29c10010 */ 	slti	$at,$t6,0x10
/*  f154790:	01c02025 */ 	move	$a0,$t6
/*  f154794:	00001825 */ 	move	$v1,$zero
/*  f154798:	14200008 */ 	bnez	$at,.JF0f1547bc
/*  f15479c:	01c01025 */ 	move	$v0,$t6
/*  f1547a0:	29c1001a */ 	slti	$at,$t6,0x1a
/*  f1547a4:	50200006 */ 	beqzl	$at,.JF0f1547c0
/*  f1547a8:	2841001a */ 	slti	$at,$v0,0x1a
/*  f1547ac:	01c01825 */ 	move	$v1,$t6
/*  f1547b0:	24630020 */ 	addiu	$v1,$v1,0x20
/*  f1547b4:	306f00ff */ 	andi	$t7,$v1,0xff
/*  f1547b8:	01e01825 */ 	move	$v1,$t7
.JF0f1547bc:
/*  f1547bc:	2841001a */ 	slti	$at,$v0,0x1a
.JF0f1547c0:
/*  f1547c0:	14200007 */ 	bnez	$at,.JF0f1547e0
/*  f1547c4:	28410034 */ 	slti	$at,$v0,0x34
/*  f1547c8:	50200006 */ 	beqzl	$at,.JF0f1547e4
/*  f1547cc:	28410095 */ 	slti	$at,$v0,0x95
/*  f1547d0:	00801825 */ 	move	$v1,$a0
/*  f1547d4:	24630027 */ 	addiu	$v1,$v1,0x27
/*  f1547d8:	307800ff */ 	andi	$t8,$v1,0xff
/*  f1547dc:	03001825 */ 	move	$v1,$t8
.JF0f1547e0:
/*  f1547e0:	28410095 */ 	slti	$at,$v0,0x95
.JF0f1547e4:
/*  f1547e4:	14200007 */ 	bnez	$at,.JF0f154804
/*  f1547e8:	284100af */ 	slti	$at,$v0,0xaf
/*  f1547ec:	50200006 */ 	beqzl	$at,.JF0f154808
/*  f1547f0:	240103fe */ 	li	$at,0x3fe
/*  f1547f4:	00801825 */ 	move	$v1,$a0
/*  f1547f8:	2463ffcc */ 	addiu	$v1,$v1,-52
/*  f1547fc:	307900ff */ 	andi	$t9,$v1,0xff
/*  f154800:	03201825 */ 	move	$v1,$t9
.JF0f154804:
/*  f154804:	240103fe */ 	li	$at,0x3fe
.JF0f154808:
/*  f154808:	10410003 */ 	beq	$v0,$at,.JF0f154818
/*  f15480c:	240103ff */ 	li	$at,0x3ff
/*  f154810:	54410003 */ 	bnel	$v0,$at,.JF0f154820
/*  f154814:	284100ff */ 	slti	$at,$v0,0xff
.JF0f154818:
/*  f154818:	2403002d */ 	li	$v1,0x2d
/*  f15481c:	284100ff */ 	slti	$at,$v0,0xff
.JF0f154820:
/*  f154820:	1020004f */ 	beqz	$at,.JF0f154960
/*  f154824:	308200ff */ 	andi	$v0,$a0,0xff
/*  f154828:	28410010 */ 	slti	$at,$v0,0x10
/*  f15482c:	14200009 */ 	bnez	$at,.JF0f154854
/*  f154830:	2448ffcc */ 	addiu	$t0,$v0,-52
/*  f154834:	2d01000e */ 	sltiu	$at,$t0,0xe
/*  f154838:	10200049 */ 	beqz	$at,.JF0f154960
/*  f15483c:	00084080 */ 	sll	$t0,$t0,0x2
/*  f154840:	3c017f1c */ 	lui	$at,0x7f1c
/*  f154844:	00280821 */ 	addu	$at,$at,$t0
/*  f154848:	8c28822c */ 	lw	$t0,-0x7dd4($at)
/*  f15484c:	01000008 */ 	jr	$t0
/*  f154850:	00000000 */ 	nop
.JF0f154854:
/*  f154854:	2c410010 */ 	sltiu	$at,$v0,0x10
/*  f154858:	10200041 */ 	beqz	$at,.JF0f154960
/*  f15485c:	00024880 */ 	sll	$t1,$v0,0x2
/*  f154860:	3c017f1c */ 	lui	$at,0x7f1c
/*  f154864:	00290821 */ 	addu	$at,$at,$t1
/*  f154868:	8c298264 */ 	lw	$t1,-0x7d9c($at)
/*  f15486c:	01200008 */ 	jr	$t1
/*  f154870:	00000000 */ 	nop
/*  f154874:	03e00008 */ 	jr	$ra
/*  f154878:	24020020 */ 	li	$v0,0x20
/*  f15487c:	03e00008 */ 	jr	$ra
/*  f154880:	2402002c */ 	li	$v0,0x2c
/*  f154884:	03e00008 */ 	jr	$ra
/*  f154888:	24020024 */ 	li	$v0,0x24
/*  f15488c:	03e00008 */ 	jr	$ra
/*  f154890:	24020028 */ 	li	$v0,0x28
/*  f154894:	03e00008 */ 	jr	$ra
/*  f154898:	24020029 */ 	li	$v0,0x29
/*  f15489c:	03e00008 */ 	jr	$ra
/*  f1548a0:	2402002e */ 	li	$v0,0x2e
/*  f1548a4:	03e00008 */ 	jr	$ra
/*  f1548a8:	24020025 */ 	li	$v0,0x25
/*  f1548ac:	03e00008 */ 	jr	$ra
/*  f1548b0:	2402005b */ 	li	$v0,0x5b
/*  f1548b4:	03e00008 */ 	jr	$ra
/*  f1548b8:	2402005d */ 	li	$v0,0x5d
/*  f1548bc:	03e00008 */ 	jr	$ra
/*  f1548c0:	24020022 */ 	li	$v0,0x22
/*  f1548c4:	03e00008 */ 	jr	$ra
/*  f1548c8:	2402003c */ 	li	$v0,0x3c
/*  f1548cc:	03e00008 */ 	jr	$ra
/*  f1548d0:	2402003e */ 	li	$v0,0x3e
/*  f1548d4:	03e00008 */ 	jr	$ra
/*  f1548d8:	24020026 */ 	li	$v0,0x26
/*  f1548dc:	03e00008 */ 	jr	$ra
/*  f1548e0:	2402007e */ 	li	$v0,0x7e
/*  f1548e4:	03e00008 */ 	jr	$ra
/*  f1548e8:	2402002e */ 	li	$v0,0x2e
/*  f1548ec:	03e00008 */ 	jr	$ra
/*  f1548f0:	24020020 */ 	li	$v0,0x20
/*  f1548f4:	03e00008 */ 	jr	$ra
/*  f1548f8:	24020021 */ 	li	$v0,0x21
/*  f1548fc:	03e00008 */ 	jr	$ra
/*  f154900:	24020022 */ 	li	$v0,0x22
/*  f154904:	03e00008 */ 	jr	$ra
/*  f154908:	24020023 */ 	li	$v0,0x23
/*  f15490c:	03e00008 */ 	jr	$ra
/*  f154910:	24020022 */ 	li	$v0,0x22
/*  f154914:	03e00008 */ 	jr	$ra
/*  f154918:	2402002a */ 	li	$v0,0x2a
/*  f15491c:	03e00008 */ 	jr	$ra
/*  f154920:	2402002b */ 	li	$v0,0x2b
/*  f154924:	03e00008 */ 	jr	$ra
/*  f154928:	2402002c */ 	li	$v0,0x2c
/*  f15492c:	03e00008 */ 	jr	$ra
/*  f154930:	2402002d */ 	li	$v0,0x2d
/*  f154934:	03e00008 */ 	jr	$ra
/*  f154938:	2402002e */ 	li	$v0,0x2e
/*  f15493c:	03e00008 */ 	jr	$ra
/*  f154940:	2402002f */ 	li	$v0,0x2f
/*  f154944:	03e00008 */ 	jr	$ra
/*  f154948:	2402003a */ 	li	$v0,0x3a
/*  f15494c:	03e00008 */ 	jr	$ra
/*  f154950:	2402003d */ 	li	$v0,0x3d
/*  f154954:	03e00008 */ 	jr	$ra
/*  f154958:	2402003f */ 	li	$v0,0x3f
/*  f15495c:	24030040 */ 	li	$v1,0x40
.JF0f154960:
/*  f154960:	03e00008 */ 	jr	$ra
/*  f154964:	00601025 */ 	move	$v0,$v1
);
#endif

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel func0f155d2cpf
.late_rodata
glabel var7f1b82a4jf
.word 0x7f154a3c
.word 0x7f154aac
.word 0x7f154a84
.word 0x7f154ab4
.word 0x7f154a4c
.word 0x7f154a6c
.word 0x7f154a9c
.word 0x7f154af8
.word 0x7f154a54
.word 0x7f154a5c
.word 0x7f154abc
.word 0x7f154ac4
.word 0x7f154a44
.word 0x7f154acc
.word 0x7f154a64
.word 0x7f154ad4
.word 0x7f154af8
.word 0x7f154af8
.word 0x7f154af8
.word 0x7f154af8
.word 0x7f154af8
.word 0x7f154af8
.word 0x7f154af8
.word 0x7f154af8
.word 0x7f154af8
.word 0x7f154af8
.word 0x7f154adc
.word 0x7f154af8
.word 0x7f154a8c
.word 0x7f154ae4
.word 0x7f154a94
.word 0x7f154aec
.word 0x7f154af4
.text
/*  f154968:	308e00ff */ 	andi	$t6,$a0,0xff
/*  f15496c:	29c10030 */ 	slti	$at,$t6,0x30
/*  f154970:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f154974:	00001825 */ 	move	$v1,$zero
/*  f154978:	14200007 */ 	bnez	$at,.JF0f154998
/*  f15497c:	01c01025 */ 	move	$v0,$t6
/*  f154980:	29c1003a */ 	slti	$at,$t6,0x3a
/*  f154984:	50200005 */ 	beqzl	$at,.JF0f15499c
/*  f154988:	28410041 */ 	slti	$at,$v0,0x41
/*  f15498c:	25c3ffe0 */ 	addiu	$v1,$t6,-32
/*  f154990:	306fffff */ 	andi	$t7,$v1,0xffff
/*  f154994:	01e01825 */ 	move	$v1,$t7
.JF0f154998:
/*  f154998:	28410041 */ 	slti	$at,$v0,0x41
.JF0f15499c:
/*  f15499c:	14200006 */ 	bnez	$at,.JF0f1549b8
/*  f1549a0:	2841005b */ 	slti	$at,$v0,0x5b
/*  f1549a4:	50200005 */ 	beqzl	$at,.JF0f1549bc
/*  f1549a8:	28410061 */ 	slti	$at,$v0,0x61
/*  f1549ac:	2443ffd9 */ 	addiu	$v1,$v0,-39
/*  f1549b0:	3078ffff */ 	andi	$t8,$v1,0xffff
/*  f1549b4:	03001825 */ 	move	$v1,$t8
.JF0f1549b8:
/*  f1549b8:	28410061 */ 	slti	$at,$v0,0x61
.JF0f1549bc:
/*  f1549bc:	14200006 */ 	bnez	$at,.JF0f1549d8
/*  f1549c0:	2841007b */ 	slti	$at,$v0,0x7b
/*  f1549c4:	50200005 */ 	beqzl	$at,.JF0f1549dc
/*  f1549c8:	2841005c */ 	slti	$at,$v0,0x5c
/*  f1549cc:	24430034 */ 	addiu	$v1,$v0,0x34
/*  f1549d0:	3079ffff */ 	andi	$t9,$v1,0xffff
/*  f1549d4:	03201825 */ 	move	$v1,$t9
.JF0f1549d8:
/*  f1549d8:	2841005c */ 	slti	$at,$v0,0x5c
.JF0f1549dc:
/*  f1549dc:	14200007 */ 	bnez	$at,.JF0f1549fc
/*  f1549e0:	2401005d */ 	li	$at,0x5d
/*  f1549e4:	10410025 */ 	beq	$v0,$at,.JF0f154a7c
/*  f1549e8:	2401007e */ 	li	$at,0x7e
/*  f1549ec:	1041002d */ 	beq	$v0,$at,.JF0f154aa4
/*  f1549f0:	00000000 */ 	nop
/*  f1549f4:	03e00008 */ 	jr	$ra
/*  f1549f8:	00601025 */ 	move	$v0,$v1
.JF0f1549fc:
/*  f1549fc:	28410041 */ 	slti	$at,$v0,0x41
/*  f154a00:	14200006 */ 	bnez	$at,.JF0f154a1c
/*  f154a04:	2448ffe0 */ 	addiu	$t0,$v0,-32
/*  f154a08:	2401005b */ 	li	$at,0x5b
/*  f154a0c:	10410019 */ 	beq	$v0,$at,.JF0f154a74
/*  f154a10:	00000000 */ 	nop
/*  f154a14:	03e00008 */ 	jr	$ra
/*  f154a18:	00601025 */ 	move	$v0,$v1
.JF0f154a1c:
/*  f154a1c:	2d010021 */ 	sltiu	$at,$t0,0x21
/*  f154a20:	10200035 */ 	beqz	$at,.JF0f154af8
/*  f154a24:	00084080 */ 	sll	$t0,$t0,0x2
/*  f154a28:	3c017f1c */ 	lui	$at,0x7f1c
/*  f154a2c:	00280821 */ 	addu	$at,$at,$t0
/*  f154a30:	8c2882a4 */ 	lw	$t0,-0x7d5c($at)
/*  f154a34:	01000008 */ 	jr	$t0
/*  f154a38:	00000000 */ 	nop
/*  f154a3c:	03e00008 */ 	jr	$ra
/*  f154a40:	00001025 */ 	move	$v0,$zero
/*  f154a44:	03e00008 */ 	jr	$ra
/*  f154a48:	24020001 */ 	li	$v0,0x1
/*  f154a4c:	03e00008 */ 	jr	$ra
/*  f154a50:	24020002 */ 	li	$v0,0x2
/*  f154a54:	03e00008 */ 	jr	$ra
/*  f154a58:	24020003 */ 	li	$v0,0x3
/*  f154a5c:	03e00008 */ 	jr	$ra
/*  f154a60:	24020004 */ 	li	$v0,0x4
/*  f154a64:	03e00008 */ 	jr	$ra
/*  f154a68:	24020005 */ 	li	$v0,0x5
/*  f154a6c:	03e00008 */ 	jr	$ra
/*  f154a70:	24020006 */ 	li	$v0,0x6
.JF0f154a74:
/*  f154a74:	03e00008 */ 	jr	$ra
/*  f154a78:	24020007 */ 	li	$v0,0x7
.JF0f154a7c:
/*  f154a7c:	03e00008 */ 	jr	$ra
/*  f154a80:	24020008 */ 	li	$v0,0x8
/*  f154a84:	03e00008 */ 	jr	$ra
/*  f154a88:	24020009 */ 	li	$v0,0x9
/*  f154a8c:	03e00008 */ 	jr	$ra
/*  f154a90:	2402000a */ 	li	$v0,0xa
/*  f154a94:	03e00008 */ 	jr	$ra
/*  f154a98:	2402000b */ 	li	$v0,0xb
/*  f154a9c:	03e00008 */ 	jr	$ra
/*  f154aa0:	2402000c */ 	li	$v0,0xc
.JF0f154aa4:
/*  f154aa4:	03e00008 */ 	jr	$ra
/*  f154aa8:	2402000d */ 	li	$v0,0xd
/*  f154aac:	03e00008 */ 	jr	$ra
/*  f154ab0:	24020034 */ 	li	$v0,0x34
/*  f154ab4:	03e00008 */ 	jr	$ra
/*  f154ab8:	24020036 */ 	li	$v0,0x36
/*  f154abc:	03e00008 */ 	jr	$ra
/*  f154ac0:	24020038 */ 	li	$v0,0x38
/*  f154ac4:	03e00008 */ 	jr	$ra
/*  f154ac8:	24020039 */ 	li	$v0,0x39
/*  f154acc:	03e00008 */ 	jr	$ra
/*  f154ad0:	2402003b */ 	li	$v0,0x3b
/*  f154ad4:	03e00008 */ 	jr	$ra
/*  f154ad8:	2402003d */ 	li	$v0,0x3d
/*  f154adc:	03e00008 */ 	jr	$ra
/*  f154ae0:	2402003e */ 	li	$v0,0x3e
/*  f154ae4:	03e00008 */ 	jr	$ra
/*  f154ae8:	2402003f */ 	li	$v0,0x3f
/*  f154aec:	03e00008 */ 	jr	$ra
/*  f154af0:	24020040 */ 	li	$v0,0x40
/*  f154af4:	24030041 */ 	li	$v1,0x41
.JF0f154af8:
/*  f154af8:	03e00008 */ 	jr	$ra
/*  f154afc:	00601025 */ 	move	$v0,$v1
):
#elif VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel textMapCodeUnitToChar
.late_rodata
glabel var7f1b88a8pf
.word 0x7f155f94
glabel var7f1b88acpf
.word 0x7f155fc8
glabel var7f1b88b0pf
.word 0x7f155fc8
glabel var7f1b88b4pf
.word 0x7f155fc8
glabel var7f1b88b8pf
.word 0x7f155fc8
glabel var7f1b88bcpf
.word 0x7f155fc8
glabel var7f1b88c0pf
.word 0x7f155fc8
glabel var7f1b88c4pf
.word 0x7f155fc8
glabel var7f1b88c8pf
.word 0x7f155fc8
glabel var7f1b88ccpf
.word 0x7f155fa4
glabel var7f1b88d0pf
.word 0x7f155fc8
glabel var7f1b88d4pf
.word 0x7f155fc8
glabel var7f1b88d8pf
.word 0x7f155fc8
glabel var7f1b88dcpf
.word 0x7f155fc8
glabel var7f1b88e0pf
.word 0x7f155fc8
glabel var7f1b88e4pf
.word 0x7f155f9c
glabel var7f1b88e8pf
.word 0x7f155fc8
glabel var7f1b88ecpf
.word 0x7f155fc8
glabel var7f1b88f0pf
.word 0x7f155fc8
glabel var7f1b88f4pf
.word 0x7f155fc8
glabel var7f1b88f8pf
.word 0x7f155fc8
glabel var7f1b88fcpf
.word 0x7f155fc8
glabel var7f1b8900pf
.word 0x7f155fc8
glabel var7f1b8904pf
.word 0x7f155fc8
glabel var7f1b8908pf
.word 0x7f155fc8
glabel var7f1b890cpf
.word 0x7f155fc8
glabel var7f1b8910pf
.word 0x7f155fc8
glabel var7f1b8914pf
.word 0x7f155fc8
glabel var7f1b8918pf
.word 0x7f155fc8
glabel var7f1b891cpf
.word 0x7f155fc8
glabel var7f1b8920pf
.word 0x7f155f8c
glabel var7f1b8924pf
.word 0x7f155e74
glabel var7f1b8928pf
.word 0x7f155e6c
glabel var7f1b892cpf
.word 0x7f155fc8
glabel var7f1b8930pf
.word 0x7f155fc8
glabel var7f1b8934pf
.word 0x7f155e64
glabel var7f1b8938pf
.word 0x7f155fc8
glabel var7f1b893cpf
.word 0x7f155fc8
glabel var7f1b8940pf
.word 0x7f155fc8
glabel var7f1b8944pf
.word 0x7f155e84
glabel var7f1b8948pf
.word 0x7f155e7c
glabel var7f1b894cpf
.word 0x7f155fc8
glabel var7f1b8950pf
.word 0x7f155fc8
glabel var7f1b8954pf
.word 0x7f155e94
glabel var7f1b8958pf
.word 0x7f155e8c
glabel var7f1b895cpf
.word 0x7f155fc8
glabel var7f1b8960pf
.word 0x7f155fc8
glabel var7f1b8964pf
.word 0x7f155fc8
glabel var7f1b8968pf
.word 0x7f155f6c
glabel var7f1b896cpf
.word 0x7f155eac
glabel var7f1b8970pf
.word 0x7f155ea4
glabel var7f1b8974pf
.word 0x7f155fc8
glabel var7f1b8978pf
.word 0x7f155fc8
glabel var7f1b897cpf
.word 0x7f155e9c
glabel var7f1b8980pf
.word 0x7f155fc8
glabel var7f1b8984pf
.word 0x7f155fc8
glabel var7f1b8988pf
.word 0x7f155ec4
glabel var7f1b898cpf
.word 0x7f155ebc
glabel var7f1b8990pf
.word 0x7f155fc8
glabel var7f1b8994pf
.word 0x7f155eb4
glabel var7f1b8998pf
.word 0x7f155fc8
glabel var7f1b899cpf
.word 0x7f155fc8
glabel var7f1b89a0pf
.word 0x7f155f84
glabel var7f1b89a4pf
.word 0x7f155edc
glabel var7f1b89a8pf
.word 0x7f155ed4
glabel var7f1b89acpf
.word 0x7f155ee4
glabel var7f1b89b0pf
.word 0x7f155fc8
glabel var7f1b89b4pf
.word 0x7f155ecc
glabel var7f1b89b8pf
.word 0x7f155fc8
glabel var7f1b89bcpf
.word 0x7f155fc8
glabel var7f1b89c0pf
.word 0x7f155f7c
glabel var7f1b89c4pf
.word 0x7f155f04
glabel var7f1b89c8pf
.word 0x7f155ef4
glabel var7f1b89ccpf
.word 0x7f155eec
glabel var7f1b89d0pf
.word 0x7f155efc
glabel var7f1b89d4pf
.word 0x7f155f0c
glabel var7f1b89d8pf
.word 0x7f155f1c
glabel var7f1b89dcpf
.word 0x7f155f24
glabel var7f1b89e0pf
.word 0x7f155f14
glabel var7f1b89e4pf
.word 0x7f155fc8
glabel var7f1b89e8pf
.word 0x7f155f74
glabel var7f1b89ecpf
.word 0x7f155f44
glabel var7f1b89f0pf
.word 0x7f155f3c
glabel var7f1b89f4pf
.word 0x7f155f2c
glabel var7f1b89f8pf
.word 0x7f155fc8
glabel var7f1b89fcpf
.word 0x7f155f34
glabel var7f1b8a00pf
.word 0x7f155fc8
glabel var7f1b8a04pf
.word 0x7f155fc8
glabel var7f1b8a08pf
.word 0x7f155f4c
glabel var7f1b8a0cpf
.word 0x7f155f5c
glabel var7f1b8a10pf
.word 0x7f155f64
glabel var7f1b8a14pf
.word 0x7f155f54
.text
/*  f155d2c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f155d30:	8dce4660 */ 	lw	$t6,0x4660($t6)
/*  f155d34:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f155d38:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f155d3c:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f155d40:	11c0002d */ 	beqz	$t6,.PF0f155df8
/*  f155d44:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f155d48:	8c980000 */ 	lw	$t8,0x0($a0)
/*  f155d4c:	2405000c */ 	li	$a1,0xc
/*  f155d50:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f155d54:	93020000 */ 	lbu	$v0,0x0($t8)
/*  f155d58:	28410080 */ 	slti	$at,$v0,0x80
/*  f155d5c:	50200018 */ 	beqzl	$at,.PF0f155dc0
/*  f155d60:	906b0000 */ 	lbu	$t3,0x0($v1)
/*  f155d64:	00450019 */ 	multu	$v0,$a1
/*  f155d68:	8faa002c */ 	lw	$t2,0x2c($sp)
/*  f155d6c:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f155d70:	0000c812 */ 	mflo	$t9
/*  f155d74:	03274021 */ 	addu	$t0,$t9,$a3
/*  f155d78:	2509fe74 */ 	addiu	$t1,$t0,-396
/*  f155d7c:	ad490000 */ 	sw	$t1,0x0($t2)
/*  f155d80:	906b0000 */ 	lbu	$t3,0x0($v1)
/*  f155d84:	01650019 */ 	multu	$t3,$a1
/*  f155d88:	00006012 */ 	mflo	$t4
/*  f155d8c:	01876821 */ 	addu	$t5,$t4,$a3
/*  f155d90:	25aefe74 */ 	addiu	$t6,$t5,-396
/*  f155d94:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f155d98:	8faf0028 */ 	lw	$t7,0x28($sp)
/*  f155d9c:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f155da0:	93190000 */ 	lbu	$t9,0x0($t8)
/*  f155da4:	a0790000 */ 	sb	$t9,0x0($v1)
/*  f155da8:	8fa80028 */ 	lw	$t0,0x28($sp)
/*  f155dac:	8d090000 */ 	lw	$t1,0x0($t0)
/*  f155db0:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f155db4:	100000b2 */ 	b	.PF0f156080
/*  f155db8:	ad0a0000 */ 	sw	$t2,0x0($t0)
/*  f155dbc:	906b0000 */ 	lbu	$t3,0x0($v1)
.PF0f155dc0:
/*  f155dc0:	2405000c */ 	li	$a1,0xc
/*  f155dc4:	8faf002c */ 	lw	$t7,0x2c($sp)
/*  f155dc8:	01650019 */ 	multu	$t3,$a1
/*  f155dcc:	00006012 */ 	mflo	$t4
/*  f155dd0:	01876821 */ 	addu	$t5,$t4,$a3
/*  f155dd4:	25aefe74 */ 	addiu	$t6,$t5,-396
/*  f155dd8:	adee0000 */ 	sw	$t6,0x0($t7)
/*  f155ddc:	90780000 */ 	lbu	$t8,0x0($v1)
/*  f155de0:	03050019 */ 	multu	$t8,$a1
/*  f155de4:	0000c812 */ 	mflo	$t9
/*  f155de8:	03274821 */ 	addu	$t1,$t9,$a3
/*  f155dec:	252afe74 */ 	addiu	$t2,$t1,-396
/*  f155df0:	100000a3 */ 	b	.PF0f156080
/*  f155df4:	acca0000 */ 	sw	$t2,0x0($a2)
.PF0f155df8:
/*  f155df8:	8fa80028 */ 	lw	$t0,0x28($sp)
/*  f155dfc:	3c0d8008 */ 	lui	$t5,0x8008
/*  f155e00:	8dad0070 */ 	lw	$t5,0x70($t5)
/*  f155e04:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*  f155e08:	00001025 */ 	move	$v0,$zero
/*  f155e0c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f155e10:	916c0000 */ 	lbu	$t4,0x0($t3)
/*  f155e14:	10ed0009 */ 	beq	$a3,$t5,.PF0f155e3c
/*  f155e18:	a3ac0027 */ 	sb	$t4,0x27($sp)
/*  f155e1c:	8dce0078 */ 	lw	$t6,0x78($t6)
/*  f155e20:	3c0f8008 */ 	lui	$t7,0x8008
/*  f155e24:	50ee0006 */ 	beql	$a3,$t6,.PF0f155e40
/*  f155e28:	93b80027 */ 	lbu	$t8,0x27($sp)
/*  f155e2c:	8def0068 */ 	lw	$t7,0x68($t7)
/*  f155e30:	27a40027 */ 	addiu	$a0,$sp,0x27
/*  f155e34:	54ef005e */ 	bnel	$a3,$t7,.PF0f155fb0
/*  f155e38:	a3a20026 */ 	sb	$v0,0x26($sp)
.PF0f155e3c:
/*  f155e3c:	93b80027 */ 	lbu	$t8,0x27($sp)
.PF0f155e40:
/*  f155e40:	2719ff5f */ 	addiu	$t9,$t8,-161
/*  f155e44:	2f21005c */ 	sltiu	$at,$t9,0x5c
/*  f155e48:	1020005f */ 	beqz	$at,.PF0f155fc8
/*  f155e4c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f155e50:	3c017f1c */ 	lui	$at,0x7f1c
/*  f155e54:	00390821 */ 	addu	$at,$at,$t9
/*  f155e58:	8c3988a8 */ 	lw	$t9,-0x7758($at)
/*  f155e5c:	03200008 */ 	jr	$t9
/*  f155e60:	00000000 */ 	nop
/*  f155e64:	10000058 */ 	b	.PF0f155fc8
/*  f155e68:	2402005e */ 	li	$v0,0x5e
/*  f155e6c:	10000056 */ 	b	.PF0f155fc8
/*  f155e70:	24020066 */ 	li	$v0,0x66
/*  f155e74:	10000054 */ 	b	.PF0f155fc8
/*  f155e78:	24020070 */ 	li	$v0,0x70
/*  f155e7c:	10000052 */ 	b	.PF0f155fc8
/*  f155e80:	24020067 */ 	li	$v0,0x67
/*  f155e84:	10000050 */ 	b	.PF0f155fc8
/*  f155e88:	24020071 */ 	li	$v0,0x71
/*  f155e8c:	1000004e */ 	b	.PF0f155fc8
/*  f155e90:	24020068 */ 	li	$v0,0x68
/*  f155e94:	1000004c */ 	b	.PF0f155fc8
/*  f155e98:	24020072 */ 	li	$v0,0x72
/*  f155e9c:	1000004a */ 	b	.PF0f155fc8
/*  f155ea0:	2402005f */ 	li	$v0,0x5f
/*  f155ea4:	10000048 */ 	b	.PF0f155fc8
/*  f155ea8:	24020069 */ 	li	$v0,0x69
/*  f155eac:	10000046 */ 	b	.PF0f155fc8
/*  f155eb0:	24020073 */ 	li	$v0,0x73
/*  f155eb4:	10000044 */ 	b	.PF0f155fc8
/*  f155eb8:	24020060 */ 	li	$v0,0x60
/*  f155ebc:	10000042 */ 	b	.PF0f155fc8
/*  f155ec0:	2402006a */ 	li	$v0,0x6a
/*  f155ec4:	10000040 */ 	b	.PF0f155fc8
/*  f155ec8:	24020074 */ 	li	$v0,0x74
/*  f155ecc:	1000003e */ 	b	.PF0f155fc8
/*  f155ed0:	24020061 */ 	li	$v0,0x61
/*  f155ed4:	1000003c */ 	b	.PF0f155fc8
/*  f155ed8:	2402006b */ 	li	$v0,0x6b
/*  f155edc:	1000003a */ 	b	.PF0f155fc8
/*  f155ee0:	24020075 */ 	li	$v0,0x75
/*  f155ee4:	10000038 */ 	b	.PF0f155fc8
/*  f155ee8:	2402007a */ 	li	$v0,0x7a
/*  f155eec:	10000036 */ 	b	.PF0f155fc8
/*  f155ef0:	2402007b */ 	li	$v0,0x7b
/*  f155ef4:	10000034 */ 	b	.PF0f155fc8
/*  f155ef8:	2402006c */ 	li	$v0,0x6c
/*  f155efc:	10000032 */ 	b	.PF0f155fc8
/*  f155f00:	24020062 */ 	li	$v0,0x62
/*  f155f04:	10000030 */ 	b	.PF0f155fc8
/*  f155f08:	24020076 */ 	li	$v0,0x76
/*  f155f0c:	1000002e */ 	b	.PF0f155fc8
/*  f155f10:	24020077 */ 	li	$v0,0x77
/*  f155f14:	1000002c */ 	b	.PF0f155fc8
/*  f155f18:	24020063 */ 	li	$v0,0x63
/*  f155f1c:	1000002a */ 	b	.PF0f155fc8
/*  f155f20:	2402006d */ 	li	$v0,0x6d
/*  f155f24:	10000028 */ 	b	.PF0f155fc8
/*  f155f28:	2402007c */ 	li	$v0,0x7c
/*  f155f2c:	10000026 */ 	b	.PF0f155fc8
/*  f155f30:	2402007d */ 	li	$v0,0x7d
/*  f155f34:	10000024 */ 	b	.PF0f155fc8
/*  f155f38:	24020064 */ 	li	$v0,0x64
/*  f155f3c:	10000022 */ 	b	.PF0f155fc8
/*  f155f40:	2402006e */ 	li	$v0,0x6e
/*  f155f44:	10000020 */ 	b	.PF0f155fc8
/*  f155f48:	24020078 */ 	li	$v0,0x78
/*  f155f4c:	1000001e */ 	b	.PF0f155fc8
/*  f155f50:	24020079 */ 	li	$v0,0x79
/*  f155f54:	1000001c */ 	b	.PF0f155fc8
/*  f155f58:	24020065 */ 	li	$v0,0x65
/*  f155f5c:	1000001a */ 	b	.PF0f155fc8
/*  f155f60:	2402006f */ 	li	$v0,0x6f
/*  f155f64:	10000018 */ 	b	.PF0f155fc8
/*  f155f68:	2402007e */ 	li	$v0,0x7e
/*  f155f6c:	10000016 */ 	b	.PF0f155fc8
/*  f155f70:	2402007f */ 	li	$v0,0x7f
/*  f155f74:	10000014 */ 	b	.PF0f155fc8
/*  f155f78:	24020080 */ 	li	$v0,0x80
/*  f155f7c:	10000012 */ 	b	.PF0f155fc8
/*  f155f80:	24020081 */ 	li	$v0,0x81
/*  f155f84:	10000010 */ 	b	.PF0f155fc8
/*  f155f88:	24020082 */ 	li	$v0,0x82
/*  f155f8c:	1000000e */ 	b	.PF0f155fc8
/*  f155f90:	24020083 */ 	li	$v0,0x83
/*  f155f94:	1000000c */ 	b	.PF0f155fc8
/*  f155f98:	24020084 */ 	li	$v0,0x84
/*  f155f9c:	1000000a */ 	b	.PF0f155fc8
/*  f155fa0:	24020085 */ 	li	$v0,0x85
/*  f155fa4:	10000008 */ 	b	.PF0f155fc8
/*  f155fa8:	24020086 */ 	li	$v0,0x86
/*  f155fac:	a3a20026 */ 	sb	$v0,0x26($sp)
.PF0f155fb0:
/*  f155fb0:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f155fb4:	0fc55713 */ 	jal	func0f155c4cpf
/*  f155fb8:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f155fbc:	93a20026 */ 	lbu	$v0,0x26($sp)
/*  f155fc0:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f155fc4:	8fa70034 */ 	lw	$a3,0x34($sp)
.PF0f155fc8:
/*  f155fc8:	18400009 */ 	blez	$v0,.PF0f155ff0
/*  f155fcc:	00402025 */ 	move	$a0,$v0
/*  f155fd0:	00024880 */ 	sll	$t1,$v0,0x2
/*  f155fd4:	01224823 */ 	subu	$t1,$t1,$v0
/*  f155fd8:	8fa8002c */ 	lw	$t0,0x2c($sp)
/*  f155fdc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f155fe0:	01275021 */ 	addu	$t2,$t1,$a3
/*  f155fe4:	2405000c */ 	li	$a1,0xc
/*  f155fe8:	10000014 */ 	b	.PF0f15603c
/*  f155fec:	ad0a0000 */ 	sw	$t2,0x0($t0)
.PF0f155ff0:
/*  f155ff0:	93a20027 */ 	lbu	$v0,0x27($sp)
/*  f155ff4:	240b0021 */ 	li	$t3,0x21
/*  f155ff8:	2405000c */ 	li	$a1,0xc
/*  f155ffc:	28410021 */ 	slti	$at,$v0,0x21
/*  f156000:	10200003 */ 	beqz	$at,.PF0f156010
/*  f156004:	240c0021 */ 	li	$t4,0x21
/*  f156008:	a3ab0027 */ 	sb	$t3,0x27($sp)
/*  f15600c:	24020021 */ 	li	$v0,0x21
.PF0f156010:
/*  f156010:	2841007f */ 	slti	$at,$v0,0x7f
/*  f156014:	14200003 */ 	bnez	$at,.PF0f156024
/*  f156018:	00000000 */ 	nop
/*  f15601c:	a3ac0027 */ 	sb	$t4,0x27($sp)
/*  f156020:	24020021 */ 	li	$v0,0x21
.PF0f156024:
/*  f156024:	00450019 */ 	multu	$v0,$a1
/*  f156028:	8fb8002c */ 	lw	$t8,0x2c($sp)
/*  f15602c:	00006812 */ 	mflo	$t5
/*  f156030:	01a77021 */ 	addu	$t6,$t5,$a3
/*  f156034:	25cffe74 */ 	addiu	$t7,$t6,-396
/*  f156038:	af0f0000 */ 	sw	$t7,0x0($t8)
.PF0f15603c:
/*  f15603c:	8fa30038 */ 	lw	$v1,0x38($sp)
/*  f156040:	90790000 */ 	lbu	$t9,0x0($v1)
/*  f156044:	03250019 */ 	multu	$t9,$a1
/*  f156048:	00004812 */ 	mflo	$t1
/*  f15604c:	01275021 */ 	addu	$t2,$t1,$a3
/*  f156050:	2548fe74 */ 	addiu	$t0,$t2,-396
/*  f156054:	18800004 */ 	blez	$a0,.PF0f156068
/*  f156058:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f15605c:	0fc55713 */ 	jal	func0f155c4cpf
/*  f156060:	27a40027 */ 	addiu	$a0,$sp,0x27
/*  f156064:	8fa30038 */ 	lw	$v1,0x38($sp)
.PF0f156068:
/*  f156068:	93ab0027 */ 	lbu	$t3,0x27($sp)
/*  f15606c:	a06b0000 */ 	sb	$t3,0x0($v1)
/*  f156070:	8fac0028 */ 	lw	$t4,0x28($sp)
/*  f156074:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f156078:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f15607c:	ad8e0000 */ 	sw	$t6,0x0($t4)
.PF0f156080:
/*  f156080:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f156084:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f156088:	03e00008 */ 	jr	$ra
/*  f15608c:	00000000 */ 	nop
);
#elif VERSION >= VERSION_PAL_BETA
GLOBAL_ASM(
glabel func0f155d2cpf
.late_rodata
glabel var7f1b88a8pf
.word 0x7f15641c
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f15641c
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f15641c
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f15641c
.word 0x7f156374
.word 0x7f156374
.word 0x7f156424
.word 0x7f156424
.word 0x7f156374
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f156380
.word 0x7f156380
.word 0x7f156424
.word 0x7f156424
.word 0x7f15638c
.word 0x7f15638c
.word 0x7f156424
.word 0x7f156424
.word 0x7f156424
.word 0x7f1563ec
.word 0x7f156398
.word 0x7f156398
.word 0x7f156424
.word 0x7f156424
.word 0x7f156398
.word 0x7f156424
.word 0x7f156424
.word 0x7f1563a4
.word 0x7f1563a4
.word 0x7f156424
.word 0x7f1563a4
.word 0x7f156424
.word 0x7f156424
.word 0x7f156410
.word 0x7f1563b0
.word 0x7f1563b0
.word 0x7f1563b0
.word 0x7f156424
.word 0x7f1563b0
.word 0x7f156424
.word 0x7f156424
.word 0x7f156404
.word 0x7f1563bc
.word 0x7f1563bc
.word 0x7f1563bc
.word 0x7f1563bc
.word 0x7f1563c8
.word 0x7f1563c8
.word 0x7f1563c8
.word 0x7f1563c8
.word 0x7f156424
.word 0x7f1563f8
.word 0x7f1563d4
.word 0x7f1563d4
.word 0x7f1563d4
.word 0x7f156424
.word 0x7f1563d4
.word 0x7f156424
.word 0x7f156424
.word 0x7f1563e0
.word 0x7f1563e0
.word 0x7f1563e0
.word 0x7f1563e0
.text
/*  f15634c:	908e0000 */ 	lbu	$t6,0x0($a0)
/*  f156350:	25cfff5f */ 	addiu	$t7,$t6,-161
/*  f156354:	2de1005c */ 	sltiu	$at,$t7,0x5c
/*  f156358:	10200032 */ 	beqz	$at,.PB0f156424
/*  f15635c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f156360:	3c017f1c */ 	lui	$at,0x7f1c
/*  f156364:	002f0821 */ 	addu	$at,$at,$t7
/*  f156368:	8c2f9438 */ 	lw	$t7,-0x6bc8($at)
/*  f15636c:	01e00008 */ 	jr	$t7
/*  f156370:	00000000 */ 	nop
/*  f156374:	24180041 */ 	li	$t8,0x41
/*  f156378:	03e00008 */ 	jr	$ra
/*  f15637c:	a0980000 */ 	sb	$t8,0x0($a0)
/*  f156380:	24190045 */ 	li	$t9,0x45
/*  f156384:	03e00008 */ 	jr	$ra
/*  f156388:	a0990000 */ 	sb	$t9,0x0($a0)
/*  f15638c:	24080049 */ 	li	$t0,0x49
/*  f156390:	03e00008 */ 	jr	$ra
/*  f156394:	a0880000 */ 	sb	$t0,0x0($a0)
/*  f156398:	2409004f */ 	li	$t1,0x4f
/*  f15639c:	03e00008 */ 	jr	$ra
/*  f1563a0:	a0890000 */ 	sb	$t1,0x0($a0)
/*  f1563a4:	240a0055 */ 	li	$t2,0x55
/*  f1563a8:	03e00008 */ 	jr	$ra
/*  f1563ac:	a08a0000 */ 	sb	$t2,0x0($a0)
/*  f1563b0:	240b0061 */ 	li	$t3,0x61
/*  f1563b4:	03e00008 */ 	jr	$ra
/*  f1563b8:	a08b0000 */ 	sb	$t3,0x0($a0)
/*  f1563bc:	240c0065 */ 	li	$t4,0x65
/*  f1563c0:	03e00008 */ 	jr	$ra
/*  f1563c4:	a08c0000 */ 	sb	$t4,0x0($a0)
/*  f1563c8:	240d0069 */ 	li	$t5,0x69
/*  f1563cc:	03e00008 */ 	jr	$ra
/*  f1563d0:	a08d0000 */ 	sb	$t5,0x0($a0)
/*  f1563d4:	240e006f */ 	li	$t6,0x6f
/*  f1563d8:	03e00008 */ 	jr	$ra
/*  f1563dc:	a08e0000 */ 	sb	$t6,0x0($a0)
/*  f1563e0:	240f0075 */ 	li	$t7,0x75
/*  f1563e4:	03e00008 */ 	jr	$ra
/*  f1563e8:	a08f0000 */ 	sb	$t7,0x0($a0)
/*  f1563ec:	2418004e */ 	li	$t8,0x4e
/*  f1563f0:	03e00008 */ 	jr	$ra
/*  f1563f4:	a0980000 */ 	sb	$t8,0x0($a0)
/*  f1563f8:	2419006e */ 	li	$t9,0x6e
/*  f1563fc:	03e00008 */ 	jr	$ra
/*  f156400:	a0990000 */ 	sb	$t9,0x0($a0)
/*  f156404:	24080063 */ 	li	$t0,0x63
/*  f156408:	03e00008 */ 	jr	$ra
/*  f15640c:	a0880000 */ 	sb	$t0,0x0($a0)
/*  f156410:	24090042 */ 	li	$t1,0x42
/*  f156414:	03e00008 */ 	jr	$ra
/*  f156418:	a0890000 */ 	sb	$t1,0x0($a0)
/*  f15641c:	240a0020 */ 	li	$t2,0x20
/*  f156420:	a08a0000 */ 	sb	$t2,0x0($a0)
.PB0f156424:
/*  f156424:	03e00008 */ 	jr	$ra
/*  f156428:	00000000 */ 	nop
);
#endif

void func0f155d2cpf(void *c);
void textMapCodeUnitToChar(char **text, struct fontchar **arg1, struct fontchar **arg2, struct fontchar *chars, u8 *prevchar);

#if VERSION == VERSION_JPN_FINAL
GLOBAL_ASM(
glabel textMapCodeUnitToChar
/*  f154b00:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f154b04:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f154b08:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f154b0c:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f154b10:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f154b14:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f154b18:	8c8e0000 */ 	lw	$t6,0x0($a0)
/*  f154b1c:	00808025 */ 	move	$s0,$a0
/*  f154b20:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f154b24:	91c20000 */ 	lbu	$v0,0x0($t6)
/*  f154b28:	240a000b */ 	li	$t2,0xb
/*  f154b2c:	24848068 */ 	addiu	$a0,$a0,-32664
/*  f154b30:	28410080 */ 	slti	$at,$v0,0x80
/*  f154b34:	10200032 */ 	beqz	$at,.JF0f154c00
/*  f154b38:	00401825 */ 	move	$v1,$v0
/*  f154b3c:	10e00004 */ 	beqz	$a3,.JF0f154b50
/*  f154b40:	3c188008 */ 	lui	$t8,0x8008
/*  f154b44:	8f1800f0 */ 	lw	$t8,0xf0($t8)
/*  f154b48:	53000016 */ 	beqzl	$t8,.JF0f154ba4
/*  f154b4c:	2404000c */ 	li	$a0,0xc
.JF0f154b50:
/*  f154b50:	3c03800a */ 	lui	$v1,0x800a
/*  f154b54:	24635008 */ 	addiu	$v1,$v1,0x5008
/*  f154b58:	2405000c */ 	li	$a1,0xc
/*  f154b5c:	304400ff */ 	andi	$a0,$v0,0xff
/*  f154b60:	a4600000 */ 	sh	$zero,0x0($v1)
/*  f154b64:	a0600002 */ 	sb	$zero,0x2($v1)
/*  f154b68:	a0650003 */ 	sb	$a1,0x3($v1)
/*  f154b6c:	a0650004 */ 	sb	$a1,0x4($v1)
/*  f154b70:	a4600006 */ 	sh	$zero,0x6($v1)
/*  f154b74:	0fc5525a */ 	jal	func0f155d2cpf
/*  f154b78:	ac600008 */ 	sw	$zero,0x8($v1)
/*  f154b7c:	8fab0034 */ 	lw	$t3,0x34($sp)
/*  f154b80:	3c03800a */ 	lui	$v1,0x800a
/*  f154b84:	24635008 */ 	addiu	$v1,$v1,0x5008
/*  f154b88:	24590080 */ 	addiu	$t9,$v0,0x80
/*  f154b8c:	a4790000 */ 	sh	$t9,0x0($v1)
/*  f154b90:	ad630000 */ 	sw	$v1,0x0($t3)
/*  f154b94:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f154b98:	10000011 */ 	b	.JF0f154be0
/*  f154b9c:	ad830000 */ 	sw	$v1,0x0($t4)
/*  f154ba0:	2404000c */ 	li	$a0,0xc
.JF0f154ba4:
/*  f154ba4:	00640019 */ 	multu	$v1,$a0
/*  f154ba8:	8fae003c */ 	lw	$t6,0x3c($sp)
/*  f154bac:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f154bb0:	00006812 */ 	mflo	$t5
/*  f154bb4:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f154bb8:	25f8fe74 */ 	addiu	$t8,$t7,-396
/*  f154bbc:	af380000 */ 	sw	$t8,0x0($t9)
/*  f154bc0:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f154bc4:	8fb90038 */ 	lw	$t9,0x38($sp)
/*  f154bc8:	916c0000 */ 	lbu	$t4,0x0($t3)
/*  f154bcc:	01840019 */ 	multu	$t4,$a0
/*  f154bd0:	00006812 */ 	mflo	$t5
/*  f154bd4:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f154bd8:	25f8fe74 */ 	addiu	$t8,$t7,-396
/*  f154bdc:	af380000 */ 	sw	$t8,0x0($t9)
.JF0f154be0:
/*  f154be0:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f154be4:	8fad0040 */ 	lw	$t5,0x40($sp)
/*  f154be8:	916c0000 */ 	lbu	$t4,0x0($t3)
/*  f154bec:	a1ac0000 */ 	sb	$t4,0x0($t5)
/*  f154bf0:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f154bf4:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f154bf8:	10000040 */ 	b	.JF0f154cfc
/*  f154bfc:	ae0f0000 */ 	sw	$t7,0x0($s0)
.JF0f154c00:
/*  f154c00:	3c03800a */ 	lui	$v1,0x800a
/*  f154c04:	24635008 */ 	addiu	$v1,$v1,0x5008
/*  f154c08:	a4600000 */ 	sh	$zero,0x0($v1)
/*  f154c0c:	a0600002 */ 	sb	$zero,0x2($v1)
/*  f154c10:	a06a0003 */ 	sb	$t2,0x3($v1)
/*  f154c14:	a06a0004 */ 	sb	$t2,0x4($v1)
/*  f154c18:	a4600006 */ 	sh	$zero,0x6($v1)
/*  f154c1c:	ac600008 */ 	sw	$zero,0x8($v1)
/*  f154c20:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f154c24:	3c058008 */ 	lui	$a1,0x8008
/*  f154c28:	24a50228 */ 	addiu	$a1,$a1,0x228
/*  f154c2c:	90460000 */ 	lbu	$a2,0x0($v0)
/*  f154c30:	24580001 */ 	addiu	$t8,$v0,0x1
/*  f154c34:	ae180000 */ 	sw	$t8,0x0($s0)
/*  f154c38:	93070000 */ 	lbu	$a3,0x0($t8)
/*  f154c3c:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f154c40:	30cb007f */ 	andi	$t3,$a2,0x7f
/*  f154c44:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f154c48:	000b61c0 */ 	sll	$t4,$t3,0x7
/*  f154c4c:	30ed007f */ 	andi	$t5,$a3,0x7f
/*  f154c50:	018d4825 */ 	or	$t1,$t4,$t5
/*  f154c54:	a7a9002a */ 	sh	$t1,0x2a($sp)
/*  f154c58:	afa90024 */ 	sw	$t1,0x24($sp)
/*  f154c5c:	0c0036b4 */ 	jal	mainOverrideVariable
/*  f154c60:	a3a00029 */ 	sb	$zero,0x29($sp)
/*  f154c64:	3c0e8008 */ 	lui	$t6,0x8008
/*  f154c68:	8dce0228 */ 	lw	$t6,0x228($t6)
/*  f154c6c:	3c03800a */ 	lui	$v1,0x800a
/*  f154c70:	24635008 */ 	addiu	$v1,$v1,0x5008
/*  f154c74:	93a80029 */ 	lbu	$t0,0x29($sp)
/*  f154c78:	11c00006 */ 	beqz	$t6,.JF0f154c94
/*  f154c7c:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f154c80:	0fc551e1 */ 	jal	func0f154784jf
/*  f154c84:	3204ffff */ 	andi	$a0,$s0,0xffff
/*  f154c88:	3c03800a */ 	lui	$v1,0x800a
/*  f154c8c:	24635008 */ 	addiu	$v1,$v1,0x5008
/*  f154c90:	304800ff */ 	andi	$t0,$v0,0xff
.JF0f154c94:
/*  f154c94:	11000004 */ 	beqz	$t0,.JF0f154ca8
/*  f154c98:	01001025 */ 	move	$v0,$t0
/*  f154c9c:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f154ca0:	2404000c */ 	li	$a0,0xc
/*  f154ca4:	14a0000d */ 	bnez	$a1,.JF0f154cdc
.JF0f154ca8:
/*  f154ca8:	32181fff */ 	andi	$t8,$s0,0x1fff
/*  f154cac:	2b010400 */ 	slti	$at,$t8,0x400
/*  f154cb0:	14200002 */ 	bnez	$at,.JF0f154cbc
/*  f154cb4:	24190002 */ 	li	$t9,0x2
/*  f154cb8:	a7b9002a */ 	sh	$t9,0x2a($sp)
.JF0f154cbc:
/*  f154cbc:	97ab002a */ 	lhu	$t3,0x2a($sp)
/*  f154cc0:	8fad0034 */ 	lw	$t5,0x34($sp)
/*  f154cc4:	256c0080 */ 	addiu	$t4,$t3,0x80
/*  f154cc8:	a46c0000 */ 	sh	$t4,0x0($v1)
/*  f154ccc:	ada30000 */ 	sw	$v1,0x0($t5)
/*  f154cd0:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f154cd4:	10000009 */ 	b	.JF0f154cfc
/*  f154cd8:	adc30000 */ 	sw	$v1,0x0($t6)
.JF0f154cdc:
/*  f154cdc:	00440019 */ 	multu	$v0,$a0
/*  f154ce0:	8fab0034 */ 	lw	$t3,0x34($sp)
/*  f154ce4:	00007812 */ 	mflo	$t7
/*  f154ce8:	01e5c021 */ 	addu	$t8,$t7,$a1
/*  f154cec:	2719fe74 */ 	addiu	$t9,$t8,-396
/*  f154cf0:	ad790000 */ 	sw	$t9,0x0($t3)
/*  f154cf4:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f154cf8:	ad830000 */ 	sw	$v1,0x0($t4)
.JF0f154cfc:
/*  f154cfc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f154d00:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f154d04:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f154d08:	03e00008 */ 	jr	$ra
/*  f154d0c:	00000000 */ 	nop
);
#elif VERSION == VERSION_PAL_BETA
void textMapCodeUnitToChar(char **text, struct fontchar **arg1, struct fontchar **arg2, struct fontchar *chars, u8 *prevchar)
{
	u8 c;
	u8 index;

	if (g_Jpn) {
		if (**text < 0x80) {
			*arg1 = &chars[**text - 0x21];
			*arg2 = &chars[*prevchar - 0x21];

			*prevchar = **text;
			*text += 1;
			return;
		}

		*arg1 = &chars[*prevchar - 0x21];
		*arg2 = &chars[*prevchar - 0x21];
		return;
	}

	index = 0;
	c = **text;

	if (chars == g_CharsHandelGothicSm || chars == g_CharsHandelGothicMd || chars == g_CharsHandelGothicXs) {
		switch (c) {
		case 0xc4: index = 0x5e; break;
		case 0xc1: index = 0x66; break;
		case 0xc0: index = 0x70; break;
		case 0xc9: index = 0x67; break;
		case 0xc8: index = 0x71; break;
		case 0xcd: index = 0x68; break;
		case 0xcc: index = 0x72; break;
		case 0xd6: index = 0x5f; break;
		case 0xd3: index = 0x69; break;
		case 0xd2: index = 0x73; break;
		case 0xdc: index = 0x60; break;
		case 0xda: index = 0x6a; break;
		case 0xd9: index = 0x74; break;
		case 0xe4: index = 0x61; break;
		case 0xe1: index = 0x6b; break;
		case 0xe0: index = 0x75; break;
		case 0xe2: index = 0x7a; break;
		case 0xea: index = 0x7b; break;
		case 0xe9: index = 0x6c; break;
		case 0xeb: index = 0x62; break;
		case 0xe8: index = 0x76; break;
		case 0xec: index = 0x77; break;
		case 0xef: index = 0x63; break;
		case 0xed: index = 0x6d; break;
		case 0xee: index = 0x7c; break;
		case 0xf4: index = 0x7d; break;
		case 0xf6: index = 0x64; break;
		case 0xf3: index = 0x6e; break;
		case 0xf2: index = 0x78; break;
		case 0xf9: index = 0x79; break;
		case 0xfc: index = 0x65; break;
		case 0xfa: index = 0x6f; break;
		case 0xfb: index = 0x7e; break;
		case 0xd1: index = 0x7f; break;
		case 0xf1: index = 0x80; break;
		case 0xe7: index = 0x81; break;
		case 0xdf: index = 0x82; break;
		case 0xbf: index = 0x83; break;
		case 0xa1: index = 0x84; break;
		case 0xb0: index = 0x85; break;
		case 0xaa: index = 0x86; break;
		}
	} else {
		func0f155d2cpf(&c);
	}

	if (index > 0) {
		*arg1 = &chars[index];
	} else {
		if (c < 0x21) {
			c = 0x21;
		}

		if (c > 0x7e) {
			c = 0x21;
		}

		*arg1 = &chars[c - 0x21];
	}

	*arg2 = &chars[*prevchar - 0x21];

	if (index > 0) {
		func0f155d2cpf(&c);
	}

	*prevchar = c;
	*text += 1;
}
#endif

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel func0f154f38
/*  f154d10:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f154d14:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f154d18:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f154d1c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f154d20:	afa50054 */ 	sw	$a1,0x54($sp)
/*  f154d24:	84ef0006 */ 	lh	$t7,0x6($a3)
/*  f154d28:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f154d2c:	84cd0006 */ 	lh	$t5,0x6($a2)
/*  f154d30:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f154d34:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f154d38:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f154d3c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f154d40:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f154d44:	01d96021 */ 	addu	$t4,$t6,$t9
/*  f154d48:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f154d4c:	018fc021 */ 	addu	$t8,$t4,$t7
/*  f154d50:	3c198008 */ 	lui	$t9,0x8008
/*  f154d54:	8f3900fc */ 	lw	$t9,0xfc($t9)
/*  f154d58:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*  f154d5c:	8cac0000 */ 	lw	$t4,0x0($a1)
/*  f154d60:	00808025 */ 	move	$s0,$a0
/*  f154d64:	01d91021 */ 	addu	$v0,$t6,$t9
/*  f154d68:	01827823 */ 	subu	$t7,$t4,$v0
/*  f154d6c:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f154d70:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f154d74:	8cce0008 */ 	lw	$t6,0x8($a2)
/*  f154d78:	00c08825 */ 	move	$s1,$a2
/*  f154d7c:	55c00006 */ 	bnezl	$t6,.JF0f154d98
/*  f154d80:	96390000 */ 	lhu	$t9,0x0($s1)
/*  f154d84:	94c40000 */ 	lhu	$a0,0x0($a2)
/*  f154d88:	0fc5b967 */ 	jal	lang0f16e3fc
/*  f154d8c:	2484ff80 */ 	addiu	$a0,$a0,-128
/*  f154d90:	ae220008 */ 	sw	$v0,0x8($s1)
/*  f154d94:	96390000 */ 	lhu	$t9,0x0($s1)
.JF0f154d98:
/*  f154d98:	3c0c8008 */ 	lui	$t4,0x8008
/*  f154d9c:	2b210080 */ 	slti	$at,$t9,0x80
/*  f154da0:	1420001e */ 	bnez	$at,.JF0f154e1c
/*  f154da4:	00000000 */ 	nop
/*  f154da8:	3c0c8008 */ 	lui	$t4,0x8008
/*  f154dac:	8d8c00f8 */ 	lw	$t4,0xf8($t4)
/*  f154db0:	02002825 */ 	move	$a1,$s0
/*  f154db4:	3c0ffd10 */ 	lui	$t7,0xfd10
/*  f154db8:	15800032 */ 	bnez	$t4,.JF0f154e84
/*  f154dbc:	3c048008 */ 	lui	$a0,0x8008
/*  f154dc0:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f154dc4:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f154dc8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f154dcc:	0c012b34 */ 	jal	osVirtualToPhysical
/*  f154dd0:	248401d8 */ 	addiu	$a0,$a0,0x1d8
/*  f154dd4:	8fa5002c */ 	lw	$a1,0x2c($sp)
/*  f154dd8:	24180001 */ 	li	$t8,0x1
/*  f154ddc:	3c018008 */ 	lui	$at,0x8008
/*  f154de0:	02001825 */ 	move	$v1,$s0
/*  f154de4:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f154de8:	ac3800f8 */ 	sw	$t8,0xf8($at)
/*  f154dec:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f154df0:	3c0de600 */ 	lui	$t5,0xe600
/*  f154df4:	02002025 */ 	move	$a0,$s0
/*  f154df8:	3c190603 */ 	lui	$t9,0x603
/*  f154dfc:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f154e00:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f154e04:	3739c000 */ 	ori	$t9,$t9,0xc000
/*  f154e08:	3c0ef000 */ 	lui	$t6,0xf000
/*  f154e0c:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f154e10:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f154e14:	1000001b */ 	b	.JF0f154e84
/*  f154e18:	26100008 */ 	addiu	$s0,$s0,0x8
.JF0f154e1c:
/*  f154e1c:	8d8c00f8 */ 	lw	$t4,0xf8($t4)
/*  f154e20:	02002825 */ 	move	$a1,$s0
/*  f154e24:	3c0ffd10 */ 	lui	$t7,0xfd10
/*  f154e28:	11800016 */ 	beqz	$t4,.JF0f154e84
/*  f154e2c:	3c048008 */ 	lui	$a0,0x8008
/*  f154e30:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f154e34:	afa50020 */ 	sw	$a1,0x20($sp)
/*  f154e38:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f154e3c:	0c012b34 */ 	jal	osVirtualToPhysical
/*  f154e40:	24840178 */ 	addiu	$a0,$a0,0x178
/*  f154e44:	8fa50020 */ 	lw	$a1,0x20($sp)
/*  f154e48:	3c018008 */ 	lui	$at,0x8008
/*  f154e4c:	02001825 */ 	move	$v1,$s0
/*  f154e50:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f154e54:	ac2000f8 */ 	sw	$zero,0xf8($at)
/*  f154e58:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f154e5c:	3c18e600 */ 	lui	$t8,0xe600
/*  f154e60:	02002025 */ 	move	$a0,$s0
/*  f154e64:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f154e68:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f154e6c:	3c0e0603 */ 	lui	$t6,0x603
/*  f154e70:	35cec000 */ 	ori	$t6,$t6,0xc000
/*  f154e74:	3c0df000 */ 	lui	$t5,0xf000
/*  f154e78:	ac8d0000 */ 	sw	$t5,0x0($a0)
/*  f154e7c:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f154e80:	26100008 */ 	addiu	$s0,$s0,0x8
.JF0f154e84:
/*  f154e84:	02001025 */ 	move	$v0,$s0
/*  f154e88:	3c19fd50 */ 	lui	$t9,0xfd50
/*  f154e8c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f154e90:	8e2c0008 */ 	lw	$t4,0x8($s1)
/*  f154e94:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f154e98:	02001825 */ 	move	$v1,$s0
/*  f154e9c:	ac4c0004 */ 	sw	$t4,0x4($v0)
/*  f154ea0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f154ea4:	3c0fe600 */ 	lui	$t7,0xe600
/*  f154ea8:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f154eac:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f154eb0:	02003825 */ 	move	$a3,$s0
/*  f154eb4:	3c18f300 */ 	lui	$t8,0xf300
/*  f154eb8:	acf80000 */ 	sw	$t8,0x0($a3)
/*  f154ebc:	92240003 */ 	lbu	$a0,0x3($s1)
/*  f154ec0:	c7b00068 */ 	lwc1	$f16,0x68($sp)
/*  f154ec4:	c7ae0064 */ 	lwc1	$f14,0x64($sp)
/*  f154ec8:	000468c0 */ 	sll	$t5,$a0,0x3
/*  f154ecc:	25a40011 */ 	addiu	$a0,$t5,0x11
/*  f154ed0:	00047043 */ 	sra	$t6,$a0,0x1
/*  f154ed4:	25c4ffff */ 	addiu	$a0,$t6,-1
/*  f154ed8:	288107ff */ 	slti	$at,$a0,0x7ff
/*  f154edc:	10200003 */ 	beqz	$at,.JF0f154eec
/*  f154ee0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f154ee4:	10000002 */ 	b	.JF0f154ef0
/*  f154ee8:	00804825 */ 	move	$t1,$a0
.JF0f154eec:
/*  f154eec:	240907ff */ 	li	$t1,0x7ff
.JF0f154ef0:
/*  f154ef0:	3c014120 */ 	lui	$at,0x4120
/*  f154ef4:	44816000 */ 	mtc1	$at,$f12
/*  f154ef8:	3c014220 */ 	lui	$at,0x4220
/*  f154efc:	44819000 */ 	mtc1	$at,$f18
/*  f154f00:	31390fff */ 	andi	$t9,$t1,0xfff
/*  f154f04:	00196300 */ 	sll	$t4,$t9,0xc
/*  f154f08:	3c010700 */ 	lui	$at,0x700
/*  f154f0c:	01817825 */ 	or	$t7,$t4,$at
/*  f154f10:	35f80800 */ 	ori	$t8,$t7,0x800
/*  f154f14:	acf80004 */ 	sw	$t8,0x4($a3)
/*  f154f18:	02001825 */ 	move	$v1,$s0
/*  f154f1c:	3c0de700 */ 	lui	$t5,0xe700
/*  f154f20:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f154f24:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f154f28:	8fae0054 */ 	lw	$t6,0x54($sp)
/*  f154f2c:	3c048008 */ 	lui	$a0,0x8008
/*  f154f30:	8c840118 */ 	lw	$a0,0x118($a0)
/*  f154f34:	8dc20000 */ 	lw	$v0,0x0($t6)
/*  f154f38:	c7a4006c */ 	lwc1	$f4,0x6c($sp)
/*  f154f3c:	3c058008 */ 	lui	$a1,0x8008
/*  f154f40:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f154f44:	03246021 */ 	addu	$t4,$t9,$a0
/*  f154f48:	448c3000 */ 	mtc1	$t4,$f6
/*  f154f4c:	46049002 */ 	mul.s	$f0,$f18,$f4
/*  f154f50:	8ca5011c */ 	lw	$a1,0x11c($a1)
/*  f154f54:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f154f58:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f154f5c:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f154f60:	00000000 */ 	nop
/*  f154f64:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*  f154f68:	c7aa0070 */ 	lwc1	$f10,0x70($sp)
/*  f154f6c:	460a9082 */ 	mul.s	$f2,$f18,$f10
/*  f154f70:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f154f74:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f154f78:	44184000 */ 	mfc1	$t8,$f8
/*  f154f7c:	00000000 */ 	nop
/*  f154f80:	a7b80046 */ 	sh	$t8,0x46($sp)
/*  f154f84:	82260002 */ 	lb	$a2,0x2($s1)
/*  f154f88:	00066880 */ 	sll	$t5,$a2,0x2
/*  f154f8c:	01a57021 */ 	addu	$t6,$t5,$a1
/*  f154f90:	448e2000 */ 	mtc1	$t6,$f4
/*  f154f94:	00000000 */ 	nop
/*  f154f98:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f154f9c:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f154fa0:	00000000 */ 	nop
/*  f154fa4:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f154fa8:	46025100 */ 	add.s	$f4,$f10,$f2
/*  f154fac:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f154fb0:	440c3000 */ 	mfc1	$t4,$f6
/*  f154fb4:	00000000 */ 	nop
/*  f154fb8:	a7ac0044 */ 	sh	$t4,0x44($sp)
/*  f154fbc:	922a0004 */ 	lbu	$t2,0x4($s1)
/*  f154fc0:	004a7821 */ 	addu	$t7,$v0,$t2
/*  f154fc4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f154fc8:	03046821 */ 	addu	$t5,$t8,$a0
/*  f154fcc:	25ae0004 */ 	addiu	$t6,$t5,0x4
/*  f154fd0:	448e4000 */ 	mtc1	$t6,$f8
/*  f154fd4:	24040004 */ 	li	$a0,0x4
/*  f154fd8:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f154fdc:	460e5102 */ 	mul.s	$f4,$f10,$f14
/*  f154fe0:	00000000 */ 	nop
/*  f154fe4:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f154fe8:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f154fec:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f154ff0:	440c5000 */ 	mfc1	$t4,$f10
/*  f154ff4:	00000000 */ 	nop
/*  f154ff8:	a7ac0042 */ 	sh	$t4,0x42($sp)
/*  f154ffc:	92270003 */ 	lbu	$a3,0x3($s1)
/*  f155000:	00c77821 */ 	addu	$t7,$a2,$a3
/*  f155004:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f155008:	03056821 */ 	addu	$t5,$t8,$a1
/*  f15500c:	25ae0004 */ 	addiu	$t6,$t5,0x4
/*  f155010:	448e2000 */ 	mtc1	$t6,$f4
/*  f155014:	00e0c025 */ 	move	$t8,$a3
/*  f155018:	27070001 */ 	addiu	$a3,$t8,0x1
/*  f15501c:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f155020:	25460001 */ 	addiu	$a2,$t2,0x1
/*  f155024:	00066980 */ 	sll	$t5,$a2,0x6
/*  f155028:	25b90001 */ 	addiu	$t9,$t5,0x1
/*  f15502c:	a7b9003c */ 	sh	$t9,0x3c($sp)
/*  f155030:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f155034:	00000000 */ 	nop
/*  f155038:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f15503c:	46025100 */ 	add.s	$f4,$f10,$f2
/*  f155040:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f155044:	440c3000 */ 	mfc1	$t4,$f6
/*  f155048:	00000000 */ 	nop
/*  f15504c:	a7ac0040 */ 	sh	$t4,0x40($sp)
/*  f155050:	00076180 */ 	sll	$t4,$a3,0x6
/*  f155054:	25980001 */ 	addiu	$t8,$t4,0x1
/*  f155058:	0fc59f5d */ 	jal	gfxAllocateVertices
/*  f15505c:	a7b80038 */ 	sh	$t8,0x38($sp)
/*  f155060:	24040001 */ 	li	$a0,0x1
/*  f155064:	0fc59f77 */ 	jal	gfxAllocateColours
/*  f155068:	afa20034 */ 	sw	$v0,0x34($sp)
/*  f15506c:	8fa30034 */ 	lw	$v1,0x34($sp)
/*  f155070:	3c0dff00 */ 	lui	$t5,0xff00
/*  f155074:	87a6003c */ 	lh	$a2,0x3c($sp)
/*  f155078:	87a70038 */ 	lh	$a3,0x38($sp)
/*  f15507c:	35ad00ff */ 	ori	$t5,$t5,0xff
/*  f155080:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f155084:	2405fff6 */ 	li	$a1,-10
/*  f155088:	a4650004 */ 	sh	$a1,0x4($v1)
/*  f15508c:	a4650010 */ 	sh	$a1,0x10($v1)
/*  f155090:	a465001c */ 	sh	$a1,0x1c($v1)
/*  f155094:	a4650028 */ 	sh	$a1,0x28($v1)
/*  f155098:	a0600007 */ 	sb	$zero,0x7($v1)
/*  f15509c:	a0600013 */ 	sb	$zero,0x13($v1)
/*  f1550a0:	a060001f */ 	sb	$zero,0x1f($v1)
/*  f1550a4:	a060002b */ 	sb	$zero,0x2b($v1)
/*  f1550a8:	87a80046 */ 	lh	$t0,0x46($sp)
/*  f1550ac:	240b0001 */ 	li	$t3,0x1
/*  f1550b0:	00405025 */ 	move	$t2,$v0
/*  f1550b4:	05010003 */ 	bgez	$t0,.JF0f1550c4
/*  f1550b8:	00087083 */ 	sra	$t6,$t0,0x2
/*  f1550bc:	25010003 */ 	addiu	$at,$t0,0x3
/*  f1550c0:	00017083 */ 	sra	$t6,$at,0x2
.JF0f1550c4:
/*  f1550c4:	a46e0000 */ 	sh	$t6,0x0($v1)
/*  f1550c8:	87a40044 */ 	lh	$a0,0x44($sp)
/*  f1550cc:	a46b0008 */ 	sh	$t3,0x8($v1)
/*  f1550d0:	a46b000a */ 	sh	$t3,0xa($v1)
/*  f1550d4:	01c04025 */ 	move	$t0,$t6
/*  f1550d8:	04810003 */ 	bgez	$a0,.JF0f1550e8
/*  f1550dc:	0004c883 */ 	sra	$t9,$a0,0x2
/*  f1550e0:	24810003 */ 	addiu	$at,$a0,0x3
/*  f1550e4:	0001c883 */ 	sra	$t9,$at,0x2
.JF0f1550e8:
/*  f1550e8:	a4790002 */ 	sh	$t9,0x2($v1)
/*  f1550ec:	87a90042 */ 	lh	$t1,0x42($sp)
/*  f1550f0:	03202025 */ 	move	$a0,$t9
/*  f1550f4:	a464000e */ 	sh	$a0,0xe($v1)
/*  f1550f8:	05210003 */ 	bgez	$t1,.JF0f155108
/*  f1550fc:	00096083 */ 	sra	$t4,$t1,0x2
/*  f155100:	25210003 */ 	addiu	$at,$t1,0x3
/*  f155104:	00016083 */ 	sra	$t4,$at,0x2
.JF0f155108:
/*  f155108:	a46c000c */ 	sh	$t4,0xc($v1)
/*  f15510c:	a46b0016 */ 	sh	$t3,0x16($v1)
/*  f155110:	a46c0018 */ 	sh	$t4,0x18($v1)
/*  f155114:	a4660014 */ 	sh	$a2,0x14($v1)
/*  f155118:	87a20040 */ 	lh	$v0,0x40($sp)
/*  f15511c:	02002025 */ 	move	$a0,$s0
/*  f155120:	a4660020 */ 	sh	$a2,0x20($v1)
/*  f155124:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155128:	3c180700 */ 	lui	$t8,0x700
/*  f15512c:	a4680024 */ 	sh	$t0,0x24($v1)
/*  f155130:	a46b002c */ 	sh	$t3,0x2c($v1)
/*  f155134:	a4670022 */ 	sh	$a3,0x22($v1)
/*  f155138:	a467002e */ 	sh	$a3,0x2e($v1)
/*  f15513c:	37180004 */ 	ori	$t8,$t8,0x4
/*  f155140:	02002825 */ 	move	$a1,$s0
/*  f155144:	3c0d0430 */ 	lui	$t5,0x430
/*  f155148:	35ad0030 */ 	ori	$t5,$t5,0x30
/*  f15514c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155150:	02003025 */ 	move	$a2,$s0
/*  f155154:	3c0eb100 */ 	lui	$t6,0xb100
/*  f155158:	35ce0002 */ 	ori	$t6,$t6,0x2
/*  f15515c:	24193210 */ 	li	$t9,0x3210
/*  f155160:	01804825 */ 	move	$t1,$t4
/*  f155164:	04410003 */ 	bgez	$v0,.JF0f155174
/*  f155168:	00027883 */ 	sra	$t7,$v0,0x2
/*  f15516c:	24410003 */ 	addiu	$at,$v0,0x3
/*  f155170:	00017883 */ 	sra	$t7,$at,0x2
.JF0f155174:
/*  f155174:	a46f001a */ 	sh	$t7,0x1a($v1)
/*  f155178:	a46f0026 */ 	sh	$t7,0x26($v1)
/*  f15517c:	ac8a0004 */ 	sw	$t2,0x4($a0)
/*  f155180:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f155184:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f155188:	aca30004 */ 	sw	$v1,0x4($a1)
/*  f15518c:	acd90004 */ 	sw	$t9,0x4($a2)
/*  f155190:	acce0000 */ 	sw	$t6,0x0($a2)
/*  f155194:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f155198:	92380004 */ 	lbu	$t8,0x4($s1)
/*  f15519c:	26020008 */ 	addiu	$v0,$s0,0x8
/*  f1551a0:	8d8f0000 */ 	lw	$t7,0x0($t4)
/*  f1551a4:	01f86821 */ 	addu	$t5,$t7,$t8
/*  f1551a8:	ad8d0000 */ 	sw	$t5,0x0($t4)
/*  f1551ac:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1551b0:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f1551b4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f1551b8:	03e00008 */ 	jr	$ra
/*  f1551bc:	27bd0050 */ 	addiu	$sp,$sp,0x50
);
#else
GLOBAL_ASM(
glabel func0f154f38
/*  f154f38:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f154f3c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f154f40:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f154f44:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f154f48:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f154f4c:	8cef0004 */ 	lw	$t7,0x4($a3)
/*  f154f50:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f154f54:	8ccd0004 */ 	lw	$t5,0x4($a2)
/*  f154f58:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f154f5c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f154f60:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f154f64:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f154f68:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f154f6c:	01d96021 */ 	addu	$t4,$t6,$t9
/*  f154f70:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f154f74:	018fc021 */ 	addu	$t8,$t4,$t7
/*  f154f78:	3c198008 */ 	lui	$t9,%hi(var8007fac4)
/*  f154f7c:	8f39fac4 */ 	lw	$t9,%lo(var8007fac4)($t9)
/*  f154f80:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*  f154f84:	8cad0000 */ 	lw	$t5,0x0($a1)
/*  f154f88:	3c18fd50 */ 	lui	$t8,0xfd50
/*  f154f8c:	01d94021 */ 	addu	$t0,$t6,$t9
/*  f154f90:	01a86023 */ 	subu	$t4,$t5,$t0
/*  f154f94:	258f0001 */ 	addiu	$t7,$t4,0x1
/*  f154f98:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f154f9c:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f154fa0:	8cce0008 */ 	lw	$t6,0x8($a2)
/*  f154fa4:	24900008 */ 	addiu	$s0,$a0,0x8
/*  f154fa8:	02001825 */ 	or	$v1,$s0,$zero
/*  f154fac:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f154fb0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f154fb4:	3c19e600 */ 	lui	$t9,0xe600
/*  f154fb8:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f154fbc:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f154fc0:	02004825 */ 	or	$t1,$s0,$zero
/*  f154fc4:	3c0df300 */ 	lui	$t5,0xf300
/*  f154fc8:	ad2d0000 */ 	sw	$t5,0x0($t1)
/*  f154fcc:	90ca0002 */ 	lbu	$t2,0x2($a2)
/*  f154fd0:	00c08825 */ 	or	$s1,$a2,$zero
/*  f154fd4:	00a09025 */ 	or	$s2,$a1,$zero
/*  f154fd8:	000a60c0 */ 	sll	$t4,$t2,0x3
/*  f154fdc:	258a0011 */ 	addiu	$t2,$t4,0x11
/*  f154fe0:	000a7843 */ 	sra	$t7,$t2,0x1
/*  f154fe4:	25eaffff */ 	addiu	$t2,$t7,-1
/*  f154fe8:	294107ff */ 	slti	$at,$t2,0x7ff
/*  f154fec:	10200003 */ 	beqz	$at,.L0f154ffc
/*  f154ff0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f154ff4:	10000002 */ 	b	.L0f155000
/*  f154ff8:	01403825 */ 	or	$a3,$t2,$zero
.L0f154ffc:
/*  f154ffc:	240707ff */ 	addiu	$a3,$zero,0x7ff
.L0f155000:
/*  f155000:	3c014120 */ 	lui	$at,0x4120
/*  f155004:	44816000 */ 	mtc1	$at,$f12
/*  f155008:	3c014220 */ 	lui	$at,0x4220
/*  f15500c:	44819000 */ 	mtc1	$at,$f18
/*  f155010:	30f80fff */ 	andi	$t8,$a3,0xfff
/*  f155014:	00187300 */ 	sll	$t6,$t8,0xc
/*  f155018:	3c010700 */ 	lui	$at,0x700
/*  f15501c:	01c1c825 */ 	or	$t9,$t6,$at
/*  f155020:	c7ae005c */ 	lwc1	$f14,0x5c($sp)
/*  f155024:	c7b00060 */ 	lwc1	$f16,0x60($sp)
/*  f155028:	372d0800 */ 	ori	$t5,$t9,0x800
/*  f15502c:	ad2d0004 */ 	sw	$t5,0x4($t1)
/*  f155030:	02001825 */ 	or	$v1,$s0,$zero
/*  f155034:	3c0ce700 */ 	lui	$t4,0xe700
/*  f155038:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f15503c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f155040:	8e420000 */ 	lw	$v0,0x0($s2)
/*  f155044:	3c048008 */ 	lui	$a0,%hi(var8007fadc)
/*  f155048:	8c84fadc */ 	lw	$a0,%lo(var8007fadc)($a0)
/*  f15504c:	00027880 */ 	sll	$t7,$v0,0x2
/*  f155050:	c7a40064 */ 	lwc1	$f4,0x64($sp)
/*  f155054:	01e4c021 */ 	addu	$t8,$t7,$a0
/*  f155058:	44983000 */ 	mtc1	$t8,$f6
/*  f15505c:	46049002 */ 	mul.s	$f0,$f18,$f4
/*  f155060:	3c058008 */ 	lui	$a1,%hi(var8007fae0)
/*  f155064:	8ca5fae0 */ 	lw	$a1,%lo(var8007fae0)($a1)
/*  f155068:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15506c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f155070:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f155074:	00000000 */ 	nop
/*  f155078:	460c5102 */ 	mul.s	$f4,$f10,$f12
/*  f15507c:	c7aa0068 */ 	lwc1	$f10,0x68($sp)
/*  f155080:	460a9082 */ 	mul.s	$f2,$f18,$f10
/*  f155084:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f155088:	4600320d */ 	trunc.w.s	$f8,$f6
/*  f15508c:	44194000 */ 	mfc1	$t9,$f8
/*  f155090:	00000000 */ 	nop
/*  f155094:	a7b9003e */ 	sh	$t9,0x3e($sp)
/*  f155098:	82260001 */ 	lb	$a2,0x1($s1)
/*  f15509c:	00066880 */ 	sll	$t5,$a2,0x2
/*  f1550a0:	01a56021 */ 	addu	$t4,$t5,$a1
/*  f1550a4:	448c2000 */ 	mtc1	$t4,$f4
/*  f1550a8:	00000000 */ 	nop
/*  f1550ac:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1550b0:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f1550b4:	00000000 */ 	nop
/*  f1550b8:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f1550bc:	46025100 */ 	add.s	$f4,$f10,$f2
/*  f1550c0:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f1550c4:	44183000 */ 	mfc1	$t8,$f6
/*  f1550c8:	00000000 */ 	nop
/*  f1550cc:	a7b8003c */ 	sh	$t8,0x3c($sp)
/*  f1550d0:	922a0003 */ 	lbu	$t2,0x3($s1)
/*  f1550d4:	004a7021 */ 	addu	$t6,$v0,$t2
/*  f1550d8:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f1550dc:	03246821 */ 	addu	$t5,$t9,$a0
/*  f1550e0:	25ac0004 */ 	addiu	$t4,$t5,0x4
/*  f1550e4:	448c4000 */ 	mtc1	$t4,$f8
/*  f1550e8:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f1550ec:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f1550f0:	460e5102 */ 	mul.s	$f4,$f10,$f14
/*  f1550f4:	00000000 */ 	nop
/*  f1550f8:	460c2182 */ 	mul.s	$f6,$f4,$f12
/*  f1550fc:	46003200 */ 	add.s	$f8,$f6,$f0
/*  f155100:	4600428d */ 	trunc.w.s	$f10,$f8
/*  f155104:	44185000 */ 	mfc1	$t8,$f10
/*  f155108:	00000000 */ 	nop
/*  f15510c:	a7b8003a */ 	sh	$t8,0x3a($sp)
/*  f155110:	92270002 */ 	lbu	$a3,0x2($s1)
/*  f155114:	00c77021 */ 	addu	$t6,$a2,$a3
/*  f155118:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f15511c:	03256821 */ 	addu	$t5,$t9,$a1
/*  f155120:	25ac0004 */ 	addiu	$t4,$t5,0x4
/*  f155124:	448c2000 */ 	mtc1	$t4,$f4
/*  f155128:	00e0c825 */ 	or	$t9,$a3,$zero
/*  f15512c:	27270001 */ 	addiu	$a3,$t9,0x1
/*  f155130:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f155134:	25460001 */ 	addiu	$a2,$t2,0x1
/*  f155138:	00066980 */ 	sll	$t5,$a2,0x6
/*  f15513c:	25af0001 */ 	addiu	$t7,$t5,0x1
/*  f155140:	a7af0034 */ 	sh	$t7,0x34($sp)
/*  f155144:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f155148:	00000000 */ 	nop
/*  f15514c:	460c4282 */ 	mul.s	$f10,$f8,$f12
/*  f155150:	46025100 */ 	add.s	$f4,$f10,$f2
/*  f155154:	4600218d */ 	trunc.w.s	$f6,$f4
/*  f155158:	44183000 */ 	mfc1	$t8,$f6
/*  f15515c:	00000000 */ 	nop
/*  f155160:	a7b80038 */ 	sh	$t8,0x38($sp)
/*  f155164:	0007c180 */ 	sll	$t8,$a3,0x6
/*  f155168:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f15516c:	0fc59e59 */ 	jal	gfxAllocateVertices
/*  f155170:	a7b90030 */ 	sh	$t9,0x30($sp)
/*  f155174:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f155178:	0fc59e73 */ 	jal	gfxAllocateColours
/*  f15517c:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f155180:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f155184:	3c0dff00 */ 	lui	$t5,0xff00
/*  f155188:	87a60034 */ 	lh	$a2,0x34($sp)
/*  f15518c:	87a70030 */ 	lh	$a3,0x30($sp)
/*  f155190:	35ad00ff */ 	ori	$t5,$t5,0xff
/*  f155194:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f155198:	2405fff6 */ 	addiu	$a1,$zero,-10
/*  f15519c:	a4650004 */ 	sh	$a1,0x4($v1)
/*  f1551a0:	a4650010 */ 	sh	$a1,0x10($v1)
/*  f1551a4:	a465001c */ 	sh	$a1,0x1c($v1)
/*  f1551a8:	a4650028 */ 	sh	$a1,0x28($v1)
/*  f1551ac:	a0600007 */ 	sb	$zero,0x7($v1)
/*  f1551b0:	a0600013 */ 	sb	$zero,0x13($v1)
/*  f1551b4:	a060001f */ 	sb	$zero,0x1f($v1)
/*  f1551b8:	a060002b */ 	sb	$zero,0x2b($v1)
/*  f1551bc:	87a8003e */ 	lh	$t0,0x3e($sp)
/*  f1551c0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f1551c4:	00405825 */ 	or	$t3,$v0,$zero
/*  f1551c8:	05010003 */ 	bgez	$t0,.L0f1551d8
/*  f1551cc:	00086083 */ 	sra	$t4,$t0,0x2
/*  f1551d0:	25010003 */ 	addiu	$at,$t0,0x3
/*  f1551d4:	00016083 */ 	sra	$t4,$at,0x2
.L0f1551d8:
/*  f1551d8:	a46c0000 */ 	sh	$t4,0x0($v1)
/*  f1551dc:	87a4003c */ 	lh	$a0,0x3c($sp)
/*  f1551e0:	a46a0008 */ 	sh	$t2,0x8($v1)
/*  f1551e4:	a46a000a */ 	sh	$t2,0xa($v1)
/*  f1551e8:	01804025 */ 	or	$t0,$t4,$zero
/*  f1551ec:	04810003 */ 	bgez	$a0,.L0f1551fc
/*  f1551f0:	00047883 */ 	sra	$t7,$a0,0x2
/*  f1551f4:	24810003 */ 	addiu	$at,$a0,0x3
/*  f1551f8:	00017883 */ 	sra	$t7,$at,0x2
.L0f1551fc:
/*  f1551fc:	a46f0002 */ 	sh	$t7,0x2($v1)
/*  f155200:	87a9003a */ 	lh	$t1,0x3a($sp)
/*  f155204:	01e02025 */ 	or	$a0,$t7,$zero
/*  f155208:	a464000e */ 	sh	$a0,0xe($v1)
/*  f15520c:	05210003 */ 	bgez	$t1,.L0f15521c
/*  f155210:	0009c083 */ 	sra	$t8,$t1,0x2
/*  f155214:	25210003 */ 	addiu	$at,$t1,0x3
/*  f155218:	0001c083 */ 	sra	$t8,$at,0x2
.L0f15521c:
/*  f15521c:	a478000c */ 	sh	$t8,0xc($v1)
/*  f155220:	a46a0016 */ 	sh	$t2,0x16($v1)
/*  f155224:	a4780018 */ 	sh	$t8,0x18($v1)
/*  f155228:	a4660014 */ 	sh	$a2,0x14($v1)
/*  f15522c:	87a20038 */ 	lh	$v0,0x38($sp)
/*  f155230:	02002025 */ 	or	$a0,$s0,$zero
/*  f155234:	a4660020 */ 	sh	$a2,0x20($v1)
/*  f155238:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15523c:	3c190700 */ 	lui	$t9,0x700
/*  f155240:	a4680024 */ 	sh	$t0,0x24($v1)
/*  f155244:	a46a002c */ 	sh	$t2,0x2c($v1)
/*  f155248:	a4670022 */ 	sh	$a3,0x22($v1)
/*  f15524c:	a467002e */ 	sh	$a3,0x2e($v1)
/*  f155250:	37390004 */ 	ori	$t9,$t9,0x4
/*  f155254:	02002825 */ 	or	$a1,$s0,$zero
/*  f155258:	3c0d0430 */ 	lui	$t5,0x430
/*  f15525c:	35ad0030 */ 	ori	$t5,$t5,0x30
/*  f155260:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155264:	02003025 */ 	or	$a2,$s0,$zero
/*  f155268:	3c0cb100 */ 	lui	$t4,0xb100
/*  f15526c:	358c0002 */ 	ori	$t4,$t4,0x2
/*  f155270:	240f3210 */ 	addiu	$t7,$zero,0x3210
/*  f155274:	03004825 */ 	or	$t1,$t8,$zero
/*  f155278:	04410003 */ 	bgez	$v0,.L0f155288
/*  f15527c:	00027083 */ 	sra	$t6,$v0,0x2
/*  f155280:	24410003 */ 	addiu	$at,$v0,0x3
/*  f155284:	00017083 */ 	sra	$t6,$at,0x2
.L0f155288:
/*  f155288:	a46e001a */ 	sh	$t6,0x1a($v1)
/*  f15528c:	a46e0026 */ 	sh	$t6,0x26($v1)
/*  f155290:	ac8b0004 */ 	sw	$t3,0x4($a0)
/*  f155294:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f155298:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f15529c:	aca30004 */ 	sw	$v1,0x4($a1)
/*  f1552a0:	accf0004 */ 	sw	$t7,0x4($a2)
/*  f1552a4:	accc0000 */ 	sw	$t4,0x0($a2)
/*  f1552a8:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f1552ac:	922e0003 */ 	lbu	$t6,0x3($s1)
/*  f1552b0:	26020008 */ 	addiu	$v0,$s0,0x8
/*  f1552b4:	030ec821 */ 	addu	$t9,$t8,$t6
/*  f1552b8:	ae590000 */ 	sw	$t9,0x0($s2)
/*  f1552bc:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1552c0:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f1552c4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f1552c8:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f1552cc:	03e00008 */ 	jr	$ra
/*  f1552d0:	27bd0048 */ 	addiu	$sp,$sp,0x48
);
#endif

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel func0f1552d4
/*  f1551c0:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f1551c4:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f1551c8:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f1551cc:	f7ba0048 */ 	sdc1	$f26,0x48($sp)
/*  f1551d0:	4487d000 */ 	mtc1	$a3,$f26
/*  f1551d4:	00808025 */ 	move	$s0,$a0
/*  f1551d8:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f1551dc:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f1551e0:	afa500d4 */ 	sw	$a1,0xd4($sp)
/*  f1551e4:	afa600d8 */ 	sw	$a2,0xd8($sp)
/*  f1551e8:	240e0048 */ 	li	$t6,0x48
/*  f1551ec:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f1551f0:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f1551f4:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f1551f8:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f1551fc:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f155200:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f155204:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f155208:	f7b80040 */ 	sdc1	$f24,0x40($sp)
/*  f15520c:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f155210:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f155214:	00008825 */ 	move	$s1,$zero
/*  f155218:	a3ae00cb */ 	sb	$t6,0xcb($sp)
/*  f15521c:	afa000b8 */ 	sw	$zero,0xb8($sp)
/*  f155220:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f155224:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f155228:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f15522c:	8fa700e8 */ 	lw	$a3,0xe8($sp)
/*  f155230:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f155234:	0fc55d49 */ 	jal	textMeasure
/*  f155238:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f15523c:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f155240:	3c013f80 */ 	lui	$at,0x3f80
/*  f155244:	44810000 */ 	mtc1	$at,$f0
/*  f155248:	44983000 */ 	mtc1	$t8,$f6
/*  f15524c:	8fb900f4 */ 	lw	$t9,0xf4($sp)
/*  f155250:	4600d101 */ 	sub.s	$f4,$f26,$f0
/*  f155254:	3c013f00 */ 	lui	$at,0x3f00
/*  f155258:	44811000 */ 	mtc1	$at,$f2
/*  f15525c:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f155260:	44999000 */ 	mtc1	$t9,$f18
/*  f155264:	2408000d */ 	li	$t0,0xd
/*  f155268:	c7b800e0 */ 	lwc1	$f24,0xe0($sp)
/*  f15526c:	8fa900f8 */ 	lw	$t1,0xf8($sp)
/*  f155270:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f155274:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f155278:	44889000 */ 	mtc1	$t0,$f18
/*  f15527c:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f155280:	02001025 */ 	move	$v0,$s0
/*  f155284:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155288:	3c13e700 */ 	lui	$s3,0xe700
/*  f15528c:	02001825 */ 	move	$v1,$s0
/*  f155290:	46025402 */ 	mul.s	$f16,$f10,$f2
/*  f155294:	4600c281 */ 	sub.s	$f10,$f24,$f0
/*  f155298:	3c0aba00 */ 	lui	$t2,0xba00
/*  f15529c:	354a0e02 */ 	ori	$t2,$t2,0xe02
/*  f1552a0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1552a4:	340bc000 */ 	li	$t3,0xc000
/*  f1552a8:	02009025 */ 	move	$s2,$s0
/*  f1552ac:	46068102 */ 	mul.s	$f4,$f16,$f6
/*  f1552b0:	3c0cfd10 */ 	lui	$t4,0xfd10
/*  f1552b4:	3c048008 */ 	lui	$a0,0x8008
/*  f1552b8:	248401d8 */ 	addiu	$a0,$a0,0x1d8
/*  f1552bc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1552c0:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f1552c4:	46044501 */ 	sub.s	$f20,$f8,$f4
/*  f1552c8:	46105182 */ 	mul.s	$f6,$f10,$f16
/*  f1552cc:	44892000 */ 	mtc1	$t1,$f4
/*  f1552d0:	c7b000d8 */ 	lwc1	$f16,0xd8($sp)
/*  f1552d4:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1552d8:	ac530000 */ 	sw	$s3,0x0($v0)
/*  f1552dc:	ac6b0004 */ 	sw	$t3,0x4($v1)
/*  f1552e0:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f1552e4:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f1552e8:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f1552ec:	ae4c0000 */ 	sw	$t4,0x0($s2)
/*  f1552f0:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f1552f4:	0c012b34 */ 	jal	osVirtualToPhysical
/*  f1552f8:	460a8581 */ 	sub.s	$f22,$f16,$f10
/*  f1552fc:	ae420004 */ 	sw	$v0,0x4($s2)
/*  f155300:	240d0001 */ 	li	$t5,0x1
/*  f155304:	3c018008 */ 	lui	$at,0x8008
/*  f155308:	02001825 */ 	move	$v1,$s0
/*  f15530c:	ac2d00f8 */ 	sw	$t5,0xf8($at)
/*  f155310:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155314:	3c0ee600 */ 	lui	$t6,0xe600
/*  f155318:	02002025 */ 	move	$a0,$s0
/*  f15531c:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f155320:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f155324:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155328:	3c180603 */ 	lui	$t8,0x603
/*  f15532c:	3718c000 */ 	ori	$t8,$t8,0xc000
/*  f155330:	3c0ff000 */ 	lui	$t7,0xf000
/*  f155334:	02002825 */ 	move	$a1,$s0
/*  f155338:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f15533c:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f155340:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155344:	3c19f540 */ 	lui	$t9,0xf540
/*  f155348:	37390200 */ 	ori	$t9,$t9,0x200
/*  f15534c:	02003025 */ 	move	$a2,$s0
/*  f155350:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f155354:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f155358:	3c090007 */ 	lui	$t1,0x7
/*  f15535c:	3529c07c */ 	ori	$t1,$t1,0xc07c
/*  f155360:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155364:	3c08f200 */ 	lui	$t0,0xf200
/*  f155368:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f15536c:	acc90004 */ 	sw	$t1,0x4($a2)
/*  f155370:	02003825 */ 	move	$a3,$s0
/*  f155374:	3c0afa00 */ 	lui	$t2,0xfa00
/*  f155378:	acea0000 */ 	sw	$t2,0x0($a3)
/*  f15537c:	8fab00f0 */ 	lw	$t3,0xf0($sp)
/*  f155380:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155384:	02001025 */ 	move	$v0,$s0
/*  f155388:	aceb0004 */ 	sw	$t3,0x4($a3)
/*  f15538c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f155390:	ac530000 */ 	sw	$s3,0x0($v0)
/*  f155394:	8fac00e4 */ 	lw	$t4,0xe4($sp)
/*  f155398:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15539c:	51800049 */ 	beqzl	$t4,.JF0f1554c4
/*  f1553a0:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f1553a4:	91820000 */ 	lbu	$v0,0x0($t4)
/*  f1553a8:	3c1e8008 */ 	lui	$s8,0x8008
/*  f1553ac:	27de010c */ 	addiu	$s8,$s8,0x10c
/*  f1553b0:	10400043 */ 	beqz	$v0,.JF0f1554c0
/*  f1553b4:	2417000d */ 	li	$s7,0xd
/*  f1553b8:	3c168008 */ 	lui	$s6,0x8008
/*  f1553bc:	3c138008 */ 	lui	$s3,0x8008
/*  f1553c0:	26730108 */ 	addiu	$s3,$s3,0x108
/*  f1553c4:	26d60110 */ 	addiu	$s6,$s6,0x110
/*  f1553c8:	2415000a */ 	li	$s5,0xa
/*  f1553cc:	24140005 */ 	li	$s4,0x5
/*  f1553d0:	24120020 */ 	li	$s2,0x20
.JF0f1553d4:
/*  f1553d4:	1642000d */ 	bne	$s2,$v0,.JF0f15540c
/*  f1553d8:	00000000 */ 	nop
/*  f1553dc:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f1553e0:	8fa300b8 */ 	lw	$v1,0xb8($sp)
/*  f1553e4:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f1553e8:	01b40019 */ 	multu	$t5,$s4
/*  f1553ec:	240f0048 */ 	li	$t7,0x48
/*  f1553f0:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f1553f4:	a3af00cb */ 	sb	$t7,0xcb($sp)
/*  f1553f8:	afb900e4 */ 	sw	$t9,0xe4($sp)
/*  f1553fc:	00007012 */ 	mflo	$t6
/*  f155400:	01c31821 */ 	addu	$v1,$t6,$v1
/*  f155404:	1000002a */ 	b	.JF0f1554b0
/*  f155408:	afa300b8 */ 	sw	$v1,0xb8($sp)
.JF0f15540c:
/*  f15540c:	16a20016 */ 	bne	$s5,$v0,.JF0f155468
/*  f155410:	27a400e4 */ 	addiu	$a0,$sp,0xe4
/*  f155414:	8ec20000 */ 	lw	$v0,0x0($s6)
/*  f155418:	24080048 */ 	li	$t0,0x48
/*  f15541c:	8fa300b8 */ 	lw	$v1,0xb8($sp)
/*  f155420:	04400006 */ 	bltz	$v0,.JF0f15543c
/*  f155424:	a3a800cb */ 	sb	$t0,0xcb($sp)
/*  f155428:	54600005 */ 	bnezl	$v1,.JF0f155440
/*  f15542c:	8fc90000 */ 	lw	$t1,0x0($s8)
/*  f155430:	02228821 */ 	addu	$s1,$s1,$v0
/*  f155434:	10000007 */ 	b	.JF0f155454
/*  f155438:	00001825 */ 	move	$v1,$zero
.JF0f15543c:
/*  f15543c:	8fc90000 */ 	lw	$t1,0x0($s8)
.JF0f155440:
/*  f155440:	00001825 */ 	move	$v1,$zero
/*  f155444:	02e90019 */ 	multu	$s7,$t1
/*  f155448:	00005012 */ 	mflo	$t2
/*  f15544c:	01518821 */ 	addu	$s1,$t2,$s1
/*  f155450:	00000000 */ 	nop
.JF0f155454:
/*  f155454:	8fab00e4 */ 	lw	$t3,0xe4($sp)
/*  f155458:	afa300b8 */ 	sw	$v1,0xb8($sp)
/*  f15545c:	256c0001 */ 	addiu	$t4,$t3,0x1
/*  f155460:	10000013 */ 	b	.JF0f1554b0
/*  f155464:	afac00e4 */ 	sw	$t4,0xe4($sp)
.JF0f155468:
/*  f155468:	27ad00cb */ 	addiu	$t5,$sp,0xcb
/*  f15546c:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f155470:	27a50084 */ 	addiu	$a1,$sp,0x84
/*  f155474:	27a60080 */ 	addiu	$a2,$sp,0x80
/*  f155478:	0fc552c0 */ 	jal	textMapCodeUnitToChar
/*  f15547c:	8fa700e8 */ 	lw	$a3,0xe8($sp)
/*  f155480:	8fae00ec */ 	lw	$t6,0xec($sp)
/*  f155484:	02002025 */ 	move	$a0,$s0
/*  f155488:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f15548c:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f155490:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f155494:	e7ba0014 */ 	swc1	$f26,0x14($sp)
/*  f155498:	e7b80018 */ 	swc1	$f24,0x18($sp)
/*  f15549c:	e7b4001c */ 	swc1	$f20,0x1c($sp)
/*  f1554a0:	e7b60020 */ 	swc1	$f22,0x20($sp)
/*  f1554a4:	0fc55344 */ 	jal	func0f154f38
/*  f1554a8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1554ac:	00408025 */ 	move	$s0,$v0
.JF0f1554b0:
/*  f1554b0:	8faf00e4 */ 	lw	$t7,0xe4($sp)
/*  f1554b4:	91e20000 */ 	lbu	$v0,0x0($t7)
/*  f1554b8:	1440ffc6 */ 	bnez	$v0,.JF0f1553d4
/*  f1554bc:	00000000 */ 	nop
.JF0f1554c0:
/*  f1554c0:	8fbf0074 */ 	lw	$ra,0x74($sp)
.JF0f1554c4:
/*  f1554c4:	02001025 */ 	move	$v0,$s0
/*  f1554c8:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f1554cc:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f1554d0:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f1554d4:	d7b80040 */ 	ldc1	$f24,0x40($sp)
/*  f1554d8:	d7ba0048 */ 	ldc1	$f26,0x48($sp)
/*  f1554dc:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f1554e0:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f1554e4:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f1554e8:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f1554ec:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f1554f0:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f1554f4:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f1554f8:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f1554fc:	03e00008 */ 	jr	$ra
/*  f155500:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);
#elif VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f1552d4
/*  f15642c:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f156430:	f7ba0048 */ 	sdc1	$f26,0x48($sp)
/*  f156434:	4487d000 */ 	mtc1	$a3,$f26
/*  f156438:	8fa700e8 */ 	lw	$a3,0xe8($sp)
/*  f15643c:	240e0048 */ 	li	$t6,0x48
/*  f156440:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f156444:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f156448:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f15644c:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f156450:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f156454:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f156458:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f15645c:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f156460:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f156464:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f156468:	f7b80040 */ 	sdc1	$f24,0x40($sp)
/*  f15646c:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f156470:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f156474:	afa500d4 */ 	sw	$a1,0xd4($sp)
/*  f156478:	afa600d8 */ 	sw	$a2,0xd8($sp)
/*  f15647c:	a3ae00cb */ 	sb	$t6,0xcb($sp)
/*  f156480:	afa000b8 */ 	sw	$zero,0xb8($sp)
/*  f156484:	3c198008 */ 	lui	$t9,0x8008
/*  f156488:	8f394660 */ 	lw	$t9,0x4660($t9)
/*  f15648c:	90f80446 */ 	lbu	$t8,0x446($a3)
/*  f156490:	80ef0445 */ 	lb	$t7,0x445($a3)
/*  f156494:	00808025 */ 	move	$s0,$a0
/*  f156498:	00008825 */ 	move	$s1,$zero
/*  f15649c:	13200005 */ 	beqz	$t9,.PF0f1564b4
/*  f1564a0:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f1564a4:	2841000e */ 	slti	$at,$v0,0xe
/*  f1564a8:	50200003 */ 	beqzl	$at,.PF0f1564b8
/*  f1564ac:	8fa800ec */ 	lw	$t0,0xec($sp)
/*  f1564b0:	2402000e */ 	li	$v0,0xe
.PF0f1564b4:
/*  f1564b4:	8fa800ec */ 	lw	$t0,0xec($sp)
.PF0f1564b8:
/*  f1564b8:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f1564bc:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f1564c0:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f1564c4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1564c8:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f1564cc:	0fc5609a */ 	jal	textMeasure
/*  f1564d0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f1564d4:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f1564d8:	3c013f80 */ 	lui	$at,0x3f80
/*  f1564dc:	44810000 */ 	mtc1	$at,$f0
/*  f1564e0:	44893000 */ 	mtc1	$t1,$f6
/*  f1564e4:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f1564e8:	4600d101 */ 	sub.s	$f4,$f26,$f0
/*  f1564ec:	3c013f00 */ 	lui	$at,0x3f00
/*  f1564f0:	44811000 */ 	mtc1	$at,$f2
/*  f1564f4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1564f8:	448a9000 */ 	mtc1	$t2,$f18
/*  f1564fc:	8fab00bc */ 	lw	$t3,0xbc($sp)
/*  f156500:	c7b800e0 */ 	lwc1	$f24,0xe0($sp)
/*  f156504:	8fac00f8 */ 	lw	$t4,0xf8($sp)
/*  f156508:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f15650c:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f156510:	448b9000 */ 	mtc1	$t3,$f18
/*  f156514:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f156518:	02001025 */ 	move	$v0,$s0
/*  f15651c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156520:	3c13e700 */ 	lui	$s3,0xe700
/*  f156524:	02001825 */ 	move	$v1,$s0
/*  f156528:	46025402 */ 	mul.s	$f16,$f10,$f2
/*  f15652c:	4600c281 */ 	sub.s	$f10,$f24,$f0
/*  f156530:	3c0dba00 */ 	lui	$t5,0xba00
/*  f156534:	35ad0e02 */ 	ori	$t5,$t5,0xe02
/*  f156538:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15653c:	340ec000 */ 	li	$t6,0xc000
/*  f156540:	02009025 */ 	move	$s2,$s0
/*  f156544:	46068102 */ 	mul.s	$f4,$f16,$f6
/*  f156548:	3c0ffd10 */ 	lui	$t7,0xfd10
/*  f15654c:	3c048008 */ 	lui	$a0,0x8008
/*  f156550:	2484009c */ 	addiu	$a0,$a0,0x9c
/*  f156554:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156558:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f15655c:	46044501 */ 	sub.s	$f20,$f8,$f4
/*  f156560:	46105182 */ 	mul.s	$f6,$f10,$f16
/*  f156564:	448c2000 */ 	mtc1	$t4,$f4
/*  f156568:	c7b000d8 */ 	lwc1	$f16,0xd8($sp)
/*  f15656c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f156570:	ac530000 */ 	sw	$s3,0x0($v0)
/*  f156574:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f156578:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f15657c:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f156580:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f156584:	ae4f0000 */ 	sw	$t7,0x0($s2)
/*  f156588:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f15658c:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f156590:	460a8581 */ 	sub.s	$f22,$f16,$f10
/*  f156594:	02001825 */ 	move	$v1,$s0
/*  f156598:	ae420004 */ 	sw	$v0,0x4($s2)
/*  f15659c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1565a0:	3c18e600 */ 	lui	$t8,0xe600
/*  f1565a4:	02002025 */ 	move	$a0,$s0
/*  f1565a8:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f1565ac:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1565b0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1565b4:	3c080603 */ 	lui	$t0,0x603
/*  f1565b8:	3508c000 */ 	ori	$t0,$t0,0xc000
/*  f1565bc:	3c19f000 */ 	lui	$t9,0xf000
/*  f1565c0:	02002825 */ 	move	$a1,$s0
/*  f1565c4:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f1565c8:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f1565cc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1565d0:	3c09f540 */ 	lui	$t1,0xf540
/*  f1565d4:	35290200 */ 	ori	$t1,$t1,0x200
/*  f1565d8:	02003025 */ 	move	$a2,$s0
/*  f1565dc:	aca90000 */ 	sw	$t1,0x0($a1)
/*  f1565e0:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f1565e4:	3c0b0007 */ 	lui	$t3,0x7
/*  f1565e8:	356bc07c */ 	ori	$t3,$t3,0xc07c
/*  f1565ec:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1565f0:	3c0af200 */ 	lui	$t2,0xf200
/*  f1565f4:	acca0000 */ 	sw	$t2,0x0($a2)
/*  f1565f8:	accb0004 */ 	sw	$t3,0x4($a2)
/*  f1565fc:	02003825 */ 	move	$a3,$s0
/*  f156600:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f156604:	acec0000 */ 	sw	$t4,0x0($a3)
/*  f156608:	8fad00f0 */ 	lw	$t5,0xf0($sp)
/*  f15660c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156610:	02001025 */ 	move	$v0,$s0
/*  f156614:	aced0004 */ 	sw	$t5,0x4($a3)
/*  f156618:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f15661c:	ac530000 */ 	sw	$s3,0x0($v0)
/*  f156620:	8fae00e4 */ 	lw	$t6,0xe4($sp)
/*  f156624:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156628:	51c00045 */ 	beqzl	$t6,.PF0f156740
/*  f15662c:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f156630:	91c20000 */ 	lbu	$v0,0x0($t6)
/*  f156634:	27be0084 */ 	addiu	$s8,$sp,0x84
/*  f156638:	27b700e4 */ 	addiu	$s7,$sp,0xe4
/*  f15663c:	1040003f */ 	beqz	$v0,.PF0f15673c
/*  f156640:	3c168008 */ 	lui	$s6,0x8008
/*  f156644:	3c138008 */ 	lui	$s3,0x8008
/*  f156648:	26730030 */ 	addiu	$s3,$s3,0x30
/*  f15664c:	26d60034 */ 	addiu	$s6,$s6,0x34
/*  f156650:	2415000a */ 	li	$s5,0xa
/*  f156654:	24140005 */ 	li	$s4,0x5
/*  f156658:	24120020 */ 	li	$s2,0x20
.PF0f15665c:
/*  f15665c:	1642000d */ 	bne	$s2,$v0,.PF0f156694
/*  f156660:	00000000 */ 	nop
/*  f156664:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f156668:	8fa300b8 */ 	lw	$v1,0xb8($sp)
/*  f15666c:	8fa800e4 */ 	lw	$t0,0xe4($sp)
/*  f156670:	01f40019 */ 	multu	$t7,$s4
/*  f156674:	24190048 */ 	li	$t9,0x48
/*  f156678:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f15667c:	a3b900cb */ 	sb	$t9,0xcb($sp)
/*  f156680:	afa900e4 */ 	sw	$t1,0xe4($sp)
/*  f156684:	0000c012 */ 	mflo	$t8
/*  f156688:	03031821 */ 	addu	$v1,$t8,$v1
/*  f15668c:	10000027 */ 	b	.PF0f15672c
/*  f156690:	afa300b8 */ 	sw	$v1,0xb8($sp)
.PF0f156694:
/*  f156694:	16a20013 */ 	bne	$s5,$v0,.PF0f1566e4
/*  f156698:	02e02025 */ 	move	$a0,$s7
/*  f15669c:	8ec20000 */ 	lw	$v0,0x0($s6)
/*  f1566a0:	240a0048 */ 	li	$t2,0x48
/*  f1566a4:	8fa300b8 */ 	lw	$v1,0xb8($sp)
/*  f1566a8:	04400006 */ 	bltz	$v0,.PF0f1566c4
/*  f1566ac:	a3aa00cb */ 	sb	$t2,0xcb($sp)
/*  f1566b0:	54600005 */ 	bnezl	$v1,.PF0f1566c8
/*  f1566b4:	8fab00bc */ 	lw	$t3,0xbc($sp)
/*  f1566b8:	02228821 */ 	addu	$s1,$s1,$v0
/*  f1566bc:	10000004 */ 	b	.PF0f1566d0
/*  f1566c0:	00001825 */ 	move	$v1,$zero
.PF0f1566c4:
/*  f1566c4:	8fab00bc */ 	lw	$t3,0xbc($sp)
.PF0f1566c8:
/*  f1566c8:	00001825 */ 	move	$v1,$zero
/*  f1566cc:	022b8821 */ 	addu	$s1,$s1,$t3
.PF0f1566d0:
/*  f1566d0:	8fac00e4 */ 	lw	$t4,0xe4($sp)
/*  f1566d4:	afa300b8 */ 	sw	$v1,0xb8($sp)
/*  f1566d8:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f1566dc:	10000013 */ 	b	.PF0f15672c
/*  f1566e0:	afad00e4 */ 	sw	$t5,0xe4($sp)
.PF0f1566e4:
/*  f1566e4:	27ae00cb */ 	addiu	$t6,$sp,0xcb
/*  f1566e8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f1566ec:	03c02825 */ 	move	$a1,$s8
/*  f1566f0:	27a60080 */ 	addiu	$a2,$sp,0x80
/*  f1566f4:	0fc5574b */ 	jal	textMapCodeUnitToChar
/*  f1566f8:	8fa700e8 */ 	lw	$a3,0xe8($sp)
/*  f1566fc:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f156700:	02002025 */ 	move	$a0,$s0
/*  f156704:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f156708:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f15670c:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f156710:	e7ba0014 */ 	swc1	$f26,0x14($sp)
/*  f156714:	e7b80018 */ 	swc1	$f24,0x18($sp)
/*  f156718:	e7b4001c */ 	swc1	$f20,0x1c($sp)
/*  f15671c:	e7b60020 */ 	swc1	$f22,0x20($sp)
/*  f156720:	0fc55824 */ 	jal	func0f154f38
/*  f156724:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f156728:	00408025 */ 	move	$s0,$v0
.PF0f15672c:
/*  f15672c:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f156730:	93020000 */ 	lbu	$v0,0x0($t8)
/*  f156734:	1440ffc9 */ 	bnez	$v0,.PF0f15665c
/*  f156738:	00000000 */ 	nop
.PF0f15673c:
/*  f15673c:	8fbf0074 */ 	lw	$ra,0x74($sp)
.PF0f156740:
/*  f156740:	02001025 */ 	move	$v0,$s0
/*  f156744:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f156748:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f15674c:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f156750:	d7b80040 */ 	ldc1	$f24,0x40($sp)
/*  f156754:	d7ba0048 */ 	ldc1	$f26,0x48($sp)
/*  f156758:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f15675c:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f156760:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f156764:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f156768:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f15676c:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f156770:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f156774:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f156778:	03e00008 */ 	jr	$ra
/*  f15677c:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);
#elif VERSION >= VERSION_PAL_BETA
GLOBAL_ASM(
glabel func0f1552d4
/*  f156b2c:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f156b30:	f7ba0048 */ 	sdc1	$f26,0x48($sp)
/*  f156b34:	4487d000 */ 	mtc1	$a3,$f26
/*  f156b38:	8fa700e8 */ 	lw	$a3,0xe8($sp)
/*  f156b3c:	240e0048 */ 	li	$t6,0x48
/*  f156b40:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f156b44:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f156b48:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f156b4c:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f156b50:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f156b54:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f156b58:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f156b5c:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f156b60:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f156b64:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f156b68:	f7b80040 */ 	sdc1	$f24,0x40($sp)
/*  f156b6c:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f156b70:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f156b74:	afa500d4 */ 	sw	$a1,0xd4($sp)
/*  f156b78:	afa600d8 */ 	sw	$a2,0xd8($sp)
/*  f156b7c:	a3ae00cb */ 	sb	$t6,0xcb($sp)
/*  f156b80:	afa000b8 */ 	sw	$zero,0xb8($sp)
/*  f156b84:	3c198008 */ 	lui	$t9,0x8008
/*  f156b88:	8f3965f0 */ 	lw	$t9,0x65f0($t9)
/*  f156b8c:	90f80446 */ 	lbu	$t8,0x446($a3)
/*  f156b90:	80ef0445 */ 	lb	$t7,0x445($a3)
/*  f156b94:	00808025 */ 	move	$s0,$a0
/*  f156b98:	00008825 */ 	move	$s1,$zero
/*  f156b9c:	13200005 */ 	beqz	$t9,.PB0f156bb4
/*  f156ba0:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f156ba4:	2841000e */ 	slti	$at,$v0,0xe
/*  f156ba8:	50200003 */ 	beqzl	$at,.PB0f156bb8
/*  f156bac:	8fa800ec */ 	lw	$t0,0xec($sp)
/*  f156bb0:	2402000e */ 	li	$v0,0xe
.PB0f156bb4:
/*  f156bb4:	8fa800ec */ 	lw	$t0,0xec($sp)
.PB0f156bb8:
/*  f156bb8:	27a400c0 */ 	addiu	$a0,$sp,0xc0
/*  f156bbc:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f156bc0:	8fa600e4 */ 	lw	$a2,0xe4($sp)
/*  f156bc4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f156bc8:	afa200bc */ 	sw	$v0,0xbc($sp)
/*  f156bcc:	0fc5625a */ 	jal	textMeasure
/*  f156bd0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f156bd4:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f156bd8:	3c013f80 */ 	lui	$at,0x3f80
/*  f156bdc:	44810000 */ 	mtc1	$at,$f0
/*  f156be0:	44893000 */ 	mtc1	$t1,$f6
/*  f156be4:	8faa00f4 */ 	lw	$t2,0xf4($sp)
/*  f156be8:	4600d101 */ 	sub.s	$f4,$f26,$f0
/*  f156bec:	3c013f00 */ 	lui	$at,0x3f00
/*  f156bf0:	44811000 */ 	mtc1	$at,$f2
/*  f156bf4:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f156bf8:	448a9000 */ 	mtc1	$t2,$f18
/*  f156bfc:	8fab00bc */ 	lw	$t3,0xbc($sp)
/*  f156c00:	c7b800e0 */ 	lwc1	$f24,0xe0($sp)
/*  f156c04:	8fac00f8 */ 	lw	$t4,0xf8($sp)
/*  f156c08:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f156c0c:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f156c10:	448b9000 */ 	mtc1	$t3,$f18
/*  f156c14:	c7a800d4 */ 	lwc1	$f8,0xd4($sp)
/*  f156c18:	02001025 */ 	move	$v0,$s0
/*  f156c1c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156c20:	3c13e700 */ 	lui	$s3,0xe700
/*  f156c24:	02001825 */ 	move	$v1,$s0
/*  f156c28:	46025402 */ 	mul.s	$f16,$f10,$f2
/*  f156c2c:	4600c281 */ 	sub.s	$f10,$f24,$f0
/*  f156c30:	3c0dba00 */ 	lui	$t5,0xba00
/*  f156c34:	35ad0e02 */ 	ori	$t5,$t5,0xe02
/*  f156c38:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156c3c:	340ec000 */ 	li	$t6,0xc000
/*  f156c40:	02009025 */ 	move	$s2,$s0
/*  f156c44:	46068102 */ 	mul.s	$f4,$f16,$f6
/*  f156c48:	3c0ffd10 */ 	lui	$t7,0xfd10
/*  f156c4c:	3c048008 */ 	lui	$a0,0x8008
/*  f156c50:	2484200c */ 	addiu	$a0,$a0,0x200c
/*  f156c54:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156c58:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f156c5c:	46044501 */ 	sub.s	$f20,$f8,$f4
/*  f156c60:	46105182 */ 	mul.s	$f6,$f10,$f16
/*  f156c64:	448c2000 */ 	mtc1	$t4,$f4
/*  f156c68:	c7b000d8 */ 	lwc1	$f16,0xd8($sp)
/*  f156c6c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f156c70:	ac530000 */ 	sw	$s3,0x0($v0)
/*  f156c74:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f156c78:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f156c7c:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f156c80:	ac6d0000 */ 	sw	$t5,0x0($v1)
/*  f156c84:	ae4f0000 */ 	sw	$t7,0x0($s2)
/*  f156c88:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f156c8c:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f156c90:	460a8581 */ 	sub.s	$f22,$f16,$f10
/*  f156c94:	02001825 */ 	move	$v1,$s0
/*  f156c98:	ae420004 */ 	sw	$v0,0x4($s2)
/*  f156c9c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156ca0:	3c18e600 */ 	lui	$t8,0xe600
/*  f156ca4:	02002025 */ 	move	$a0,$s0
/*  f156ca8:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f156cac:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f156cb0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156cb4:	3c080603 */ 	lui	$t0,0x603
/*  f156cb8:	3508c000 */ 	ori	$t0,$t0,0xc000
/*  f156cbc:	3c19f000 */ 	lui	$t9,0xf000
/*  f156cc0:	02002825 */ 	move	$a1,$s0
/*  f156cc4:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f156cc8:	ac880004 */ 	sw	$t0,0x4($a0)
/*  f156ccc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156cd0:	3c09f540 */ 	lui	$t1,0xf540
/*  f156cd4:	35290200 */ 	ori	$t1,$t1,0x200
/*  f156cd8:	02003025 */ 	move	$a2,$s0
/*  f156cdc:	aca90000 */ 	sw	$t1,0x0($a1)
/*  f156ce0:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f156ce4:	3c0b0007 */ 	lui	$t3,0x7
/*  f156ce8:	356bc07c */ 	ori	$t3,$t3,0xc07c
/*  f156cec:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156cf0:	3c0af200 */ 	lui	$t2,0xf200
/*  f156cf4:	acca0000 */ 	sw	$t2,0x0($a2)
/*  f156cf8:	accb0004 */ 	sw	$t3,0x4($a2)
/*  f156cfc:	02003825 */ 	move	$a3,$s0
/*  f156d00:	3c0cfa00 */ 	lui	$t4,0xfa00
/*  f156d04:	acec0000 */ 	sw	$t4,0x0($a3)
/*  f156d08:	8fad00f0 */ 	lw	$t5,0xf0($sp)
/*  f156d0c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156d10:	02001025 */ 	move	$v0,$s0
/*  f156d14:	aced0004 */ 	sw	$t5,0x4($a3)
/*  f156d18:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f156d1c:	ac530000 */ 	sw	$s3,0x0($v0)
/*  f156d20:	8fae00e4 */ 	lw	$t6,0xe4($sp)
/*  f156d24:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156d28:	51c00045 */ 	beqzl	$t6,.PB0f156e40
/*  f156d2c:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f156d30:	91c20000 */ 	lbu	$v0,0x0($t6)
/*  f156d34:	27be0084 */ 	addiu	$s8,$sp,0x84
/*  f156d38:	27b700e4 */ 	addiu	$s7,$sp,0xe4
/*  f156d3c:	1040003f */ 	beqz	$v0,.PB0f156e3c
/*  f156d40:	3c168008 */ 	lui	$s6,0x8008
/*  f156d44:	3c138008 */ 	lui	$s3,0x8008
/*  f156d48:	26731fa0 */ 	addiu	$s3,$s3,0x1fa0
/*  f156d4c:	26d61fa4 */ 	addiu	$s6,$s6,0x1fa4
/*  f156d50:	2415000a */ 	li	$s5,0xa
/*  f156d54:	24140005 */ 	li	$s4,0x5
/*  f156d58:	24120020 */ 	li	$s2,0x20
.PB0f156d5c:
/*  f156d5c:	1642000d */ 	bne	$s2,$v0,.PB0f156d94
/*  f156d60:	00000000 */ 	nop
/*  f156d64:	8e6f0000 */ 	lw	$t7,0x0($s3)
/*  f156d68:	8fa300b8 */ 	lw	$v1,0xb8($sp)
/*  f156d6c:	8fa800e4 */ 	lw	$t0,0xe4($sp)
/*  f156d70:	01f40019 */ 	multu	$t7,$s4
/*  f156d74:	24190048 */ 	li	$t9,0x48
/*  f156d78:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f156d7c:	a3b900cb */ 	sb	$t9,0xcb($sp)
/*  f156d80:	afa900e4 */ 	sw	$t1,0xe4($sp)
/*  f156d84:	0000c012 */ 	mflo	$t8
/*  f156d88:	03031821 */ 	addu	$v1,$t8,$v1
/*  f156d8c:	10000027 */ 	b	.PB0f156e2c
/*  f156d90:	afa300b8 */ 	sw	$v1,0xb8($sp)
.PB0f156d94:
/*  f156d94:	16a20013 */ 	bne	$s5,$v0,.PB0f156de4
/*  f156d98:	02e02025 */ 	move	$a0,$s7
/*  f156d9c:	8ec20000 */ 	lw	$v0,0x0($s6)
/*  f156da0:	240a0048 */ 	li	$t2,0x48
/*  f156da4:	8fa300b8 */ 	lw	$v1,0xb8($sp)
/*  f156da8:	04400006 */ 	bltz	$v0,.PB0f156dc4
/*  f156dac:	a3aa00cb */ 	sb	$t2,0xcb($sp)
/*  f156db0:	54600005 */ 	bnezl	$v1,.PB0f156dc8
/*  f156db4:	8fab00bc */ 	lw	$t3,0xbc($sp)
/*  f156db8:	02228821 */ 	addu	$s1,$s1,$v0
/*  f156dbc:	10000004 */ 	b	.PB0f156dd0
/*  f156dc0:	00001825 */ 	move	$v1,$zero
.PB0f156dc4:
/*  f156dc4:	8fab00bc */ 	lw	$t3,0xbc($sp)
.PB0f156dc8:
/*  f156dc8:	00001825 */ 	move	$v1,$zero
/*  f156dcc:	022b8821 */ 	addu	$s1,$s1,$t3
.PB0f156dd0:
/*  f156dd0:	8fac00e4 */ 	lw	$t4,0xe4($sp)
/*  f156dd4:	afa300b8 */ 	sw	$v1,0xb8($sp)
/*  f156dd8:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f156ddc:	10000013 */ 	b	.PB0f156e2c
/*  f156de0:	afad00e4 */ 	sw	$t5,0xe4($sp)
.PB0f156de4:
/*  f156de4:	27ae00cb */ 	addiu	$t6,$sp,0xcb
/*  f156de8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f156dec:	03c02825 */ 	move	$a1,$s8
/*  f156df0:	27a60080 */ 	addiu	$a2,$sp,0x80
/*  f156df4:	0fc5590b */ 	jal	textMapCodeUnitToChar
/*  f156df8:	8fa700e8 */ 	lw	$a3,0xe8($sp)
/*  f156dfc:	8faf00ec */ 	lw	$t7,0xec($sp)
/*  f156e00:	02002025 */ 	move	$a0,$s0
/*  f156e04:	27a500b8 */ 	addiu	$a1,$sp,0xb8
/*  f156e08:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f156e0c:	8fa70080 */ 	lw	$a3,0x80($sp)
/*  f156e10:	e7ba0014 */ 	swc1	$f26,0x14($sp)
/*  f156e14:	e7b80018 */ 	swc1	$f24,0x18($sp)
/*  f156e18:	e7b4001c */ 	swc1	$f20,0x1c($sp)
/*  f156e1c:	e7b60020 */ 	swc1	$f22,0x20($sp)
/*  f156e20:	0fc559e4 */ 	jal	func0f154f38
/*  f156e24:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f156e28:	00408025 */ 	move	$s0,$v0
.PB0f156e2c:
/*  f156e2c:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f156e30:	93020000 */ 	lbu	$v0,0x0($t8)
/*  f156e34:	1440ffc9 */ 	bnez	$v0,.PB0f156d5c
/*  f156e38:	00000000 */ 	nop
.PB0f156e3c:
/*  f156e3c:	8fbf0074 */ 	lw	$ra,0x74($sp)
.PB0f156e40:
/*  f156e40:	02001025 */ 	move	$v0,$s0
/*  f156e44:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f156e48:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f156e4c:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f156e50:	d7b80040 */ 	ldc1	$f24,0x40($sp)
/*  f156e54:	d7ba0048 */ 	ldc1	$f26,0x48($sp)
/*  f156e58:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f156e5c:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f156e60:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f156e64:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f156e68:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f156e6c:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f156e70:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f156e74:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f156e78:	03e00008 */ 	jr	$ra
/*  f156e7c:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);
#else
GLOBAL_ASM(
glabel func0f1552d4
/*  f1552d4:	27bdff28 */ 	addiu	$sp,$sp,-216
/*  f1552d8:	afb50064 */ 	sw	$s5,0x64($sp)
/*  f1552dc:	8fb500f0 */ 	lw	$s5,0xf0($sp)
/*  f1552e0:	afbf0074 */ 	sw	$ra,0x74($sp)
/*  f1552e4:	afbe0070 */ 	sw	$s8,0x70($sp)
/*  f1552e8:	afb7006c */ 	sw	$s7,0x6c($sp)
/*  f1552ec:	afb60068 */ 	sw	$s6,0x68($sp)
/*  f1552f0:	afb40060 */ 	sw	$s4,0x60($sp)
/*  f1552f4:	afb3005c */ 	sw	$s3,0x5c($sp)
/*  f1552f8:	afb20058 */ 	sw	$s2,0x58($sp)
/*  f1552fc:	afb10054 */ 	sw	$s1,0x54($sp)
/*  f155300:	afb00050 */ 	sw	$s0,0x50($sp)
/*  f155304:	f7ba0048 */ 	sdc1	$f26,0x48($sp)
/*  f155308:	f7b80040 */ 	sdc1	$f24,0x40($sp)
/*  f15530c:	f7b60038 */ 	sdc1	$f22,0x38($sp)
/*  f155310:	f7b40030 */ 	sdc1	$f20,0x30($sp)
/*  f155314:	afa500dc */ 	sw	$a1,0xdc($sp)
/*  f155318:	afa600e0 */ 	sw	$a2,0xe0($sp)
/*  f15531c:	afa000c0 */ 	sw	$zero,0xc0($sp)
/*  f155320:	3c188008 */ 	lui	$t8,%hi(g_Jpn)
/*  f155324:	8f184120 */ 	lw	$t8,%lo(g_Jpn)($t8)
/*  f155328:	92af0446 */ 	lbu	$t7,0x446($s5)
/*  f15532c:	82ae0445 */ 	lb	$t6,0x445($s5)
/*  f155330:	4487d000 */ 	mtc1	$a3,$f26
/*  f155334:	00808825 */ 	or	$s1,$a0,$zero
/*  f155338:	00009025 */ 	or	$s2,$zero,$zero
/*  f15533c:	24130048 */ 	addiu	$s3,$zero,0x48
/*  f155340:	13000005 */ 	beqz	$t8,.L0f155358
/*  f155344:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f155348:	2841000e */ 	slti	$at,$v0,0xe
/*  f15534c:	50200003 */ 	beqzl	$at,.L0f15535c
/*  f155350:	8fb000ec */ 	lw	$s0,0xec($sp)
/*  f155354:	2402000e */ 	addiu	$v0,$zero,0xe
.L0f155358:
/*  f155358:	8fb000ec */ 	lw	$s0,0xec($sp)
.L0f15535c:
/*  f15535c:	8fb900f4 */ 	lw	$t9,0xf4($sp)
/*  f155360:	27a400c8 */ 	addiu	$a0,$sp,0xc8
/*  f155364:	27a500cc */ 	addiu	$a1,$sp,0xcc
/*  f155368:	02a03825 */ 	or	$a3,$s5,$zero
/*  f15536c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f155370:	afa200c4 */ 	sw	$v0,0xc4($sp)
/*  f155374:	02003025 */ 	or	$a2,$s0,$zero
/*  f155378:	0fc55cbe */ 	jal	textMeasure
/*  f15537c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f155380:	8fa800cc */ 	lw	$t0,0xcc($sp)
/*  f155384:	3c013f80 */ 	lui	$at,0x3f80
/*  f155388:	44810000 */ 	mtc1	$at,$f0
/*  f15538c:	44883000 */ 	mtc1	$t0,$f6
/*  f155390:	8fa900fc */ 	lw	$t1,0xfc($sp)
/*  f155394:	4600d101 */ 	sub.s	$f4,$f26,$f0
/*  f155398:	3c013f00 */ 	lui	$at,0x3f00
/*  f15539c:	44811000 */ 	mtc1	$at,$f2
/*  f1553a0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f1553a4:	44899000 */ 	mtc1	$t1,$f18
/*  f1553a8:	8faa00c4 */ 	lw	$t2,0xc4($sp)
/*  f1553ac:	c7b800e8 */ 	lwc1	$f24,0xe8($sp)
/*  f1553b0:	8fab0100 */ 	lw	$t3,0x100($sp)
/*  f1553b4:	468091a0 */ 	cvt.s.w	$f6,$f18
/*  f1553b8:	46082282 */ 	mul.s	$f10,$f4,$f8
/*  f1553bc:	448a9000 */ 	mtc1	$t2,$f18
/*  f1553c0:	c7a800dc */ 	lwc1	$f8,0xdc($sp)
/*  f1553c4:	02201025 */ 	or	$v0,$s1,$zero
/*  f1553c8:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1553cc:	3c16e700 */ 	lui	$s6,0xe700
/*  f1553d0:	02201825 */ 	or	$v1,$s1,$zero
/*  f1553d4:	46025402 */ 	mul.s	$f16,$f10,$f2
/*  f1553d8:	4600c281 */ 	sub.s	$f10,$f24,$f0
/*  f1553dc:	3c0cba00 */ 	lui	$t4,0xba00
/*  f1553e0:	358c0e02 */ 	ori	$t4,$t4,0xe02
/*  f1553e4:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1553e8:	340dc000 */ 	dli	$t5,0xc000
/*  f1553ec:	0220a025 */ 	or	$s4,$s1,$zero
/*  f1553f0:	46068102 */ 	mul.s	$f4,$f16,$f6
/*  f1553f4:	3c0efd10 */ 	lui	$t6,0xfd10
/*  f1553f8:	3c048008 */ 	lui	$a0,%hi(var8007fb3c)
/*  f1553fc:	2484fb3c */ 	addiu	$a0,$a0,%lo(var8007fb3c)
/*  f155400:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f155404:	46809420 */ 	cvt.s.w	$f16,$f18
/*  f155408:	46044501 */ 	sub.s	$f20,$f8,$f4
/*  f15540c:	46105182 */ 	mul.s	$f6,$f10,$f16
/*  f155410:	448b2000 */ 	mtc1	$t3,$f4
/*  f155414:	c7b000e0 */ 	lwc1	$f16,0xe0($sp)
/*  f155418:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f15541c:	ac560000 */ 	sw	$s6,0x0($v0)
/*  f155420:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f155424:	468024a0 */ 	cvt.s.w	$f18,$f4
/*  f155428:	46023202 */ 	mul.s	$f8,$f6,$f2
/*  f15542c:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f155430:	ae8e0000 */ 	sw	$t6,0x0($s4)
/*  f155434:	46124282 */ 	mul.s	$f10,$f8,$f18
/*  f155438:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f15543c:	460a8581 */ 	sub.s	$f22,$f16,$f10
/*  f155440:	02201825 */ 	or	$v1,$s1,$zero
/*  f155444:	ae820004 */ 	sw	$v0,0x4($s4)
/*  f155448:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f15544c:	3c0fe600 */ 	lui	$t7,0xe600
/*  f155450:	02202025 */ 	or	$a0,$s1,$zero
/*  f155454:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f155458:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f15545c:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f155460:	3c190603 */ 	lui	$t9,0x603
/*  f155464:	3739c000 */ 	ori	$t9,$t9,0xc000
/*  f155468:	3c18f000 */ 	lui	$t8,0xf000
/*  f15546c:	02202825 */ 	or	$a1,$s1,$zero
/*  f155470:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f155474:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f155478:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f15547c:	3c08f540 */ 	lui	$t0,0xf540
/*  f155480:	35080200 */ 	ori	$t0,$t0,0x200
/*  f155484:	02203025 */ 	or	$a2,$s1,$zero
/*  f155488:	aca80000 */ 	sw	$t0,0x0($a1)
/*  f15548c:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f155490:	3c0a0007 */ 	lui	$t2,0x7
/*  f155494:	354ac07c */ 	ori	$t2,$t2,0xc07c
/*  f155498:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f15549c:	3c09f200 */ 	lui	$t1,0xf200
/*  f1554a0:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f1554a4:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f1554a8:	02203825 */ 	or	$a3,$s1,$zero
/*  f1554ac:	3c0bfa00 */ 	lui	$t3,0xfa00
/*  f1554b0:	aceb0000 */ 	sw	$t3,0x0($a3)
/*  f1554b4:	8fac00f8 */ 	lw	$t4,0xf8($sp)
/*  f1554b8:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1554bc:	02201025 */ 	or	$v0,$s1,$zero
/*  f1554c0:	acec0004 */ 	sw	$t4,0x4($a3)
/*  f1554c4:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1554c8:	ac560000 */ 	sw	$s6,0x0($v0)
/*  f1554cc:	1200005e */ 	beqz	$s0,.L0f155648
/*  f1554d0:	26310008 */ 	addiu	$s1,$s1,0x8
/*  f1554d4:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f1554d8:	3c178008 */ 	lui	$s7,%hi(var8007fad0)
/*  f1554dc:	26f7fad0 */ 	addiu	$s7,$s7,%lo(var8007fad0)
/*  f1554e0:	10400059 */ 	beqz	$v0,.L0f155648
/*  f1554e4:	241e0005 */ 	addiu	$s8,$zero,0x5
/*  f1554e8:	24160020 */ 	addiu	$s6,$zero,0x20
/*  f1554ec:	2414000c */ 	addiu	$s4,$zero,0xc
.L0f1554f0:
/*  f1554f0:	16c2000a */ 	bne	$s6,$v0,.L0f15551c
/*  f1554f4:	2401000a */ 	addiu	$at,$zero,0xa
/*  f1554f8:	8eed0000 */ 	lw	$t5,0x0($s7)
/*  f1554fc:	8fa300c0 */ 	lw	$v1,0xc0($sp)
/*  f155500:	24130048 */ 	addiu	$s3,$zero,0x48
/*  f155504:	01be0019 */ 	multu	$t5,$s8
/*  f155508:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15550c:	00007012 */ 	mflo	$t6
/*  f155510:	01c31821 */ 	addu	$v1,$t6,$v1
/*  f155514:	10000049 */ 	b	.L0f15563c
/*  f155518:	afa300c0 */ 	sw	$v1,0xc0($sp)
.L0f15551c:
/*  f15551c:	54410012 */ 	bnel	$v0,$at,.L0f155568
/*  f155520:	28410080 */ 	slti	$at,$v0,0x80
/*  f155524:	3c028008 */ 	lui	$v0,%hi(var8007fad4)
/*  f155528:	8c42fad4 */ 	lw	$v0,%lo(var8007fad4)($v0)
/*  f15552c:	8fa300c0 */ 	lw	$v1,0xc0($sp)
/*  f155530:	24130048 */ 	addiu	$s3,$zero,0x48
/*  f155534:	04400006 */ 	bltz	$v0,.L0f155550
/*  f155538:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15553c:	54600005 */ 	bnezl	$v1,.L0f155554
/*  f155540:	8faf00c4 */ 	lw	$t7,0xc4($sp)
/*  f155544:	02429021 */ 	addu	$s2,$s2,$v0
/*  f155548:	10000004 */ 	b	.L0f15555c
/*  f15554c:	00001825 */ 	or	$v1,$zero,$zero
.L0f155550:
/*  f155550:	8faf00c4 */ 	lw	$t7,0xc4($sp)
.L0f155554:
/*  f155554:	00001825 */ 	or	$v1,$zero,$zero
/*  f155558:	024f9021 */ 	addu	$s2,$s2,$t7
.L0f15555c:
/*  f15555c:	10000037 */ 	b	.L0f15563c
/*  f155560:	afa300c0 */ 	sw	$v1,0xc0($sp)
/*  f155564:	28410080 */ 	slti	$at,$v0,0x80
.L0f155568:
/*  f155568:	10200016 */ 	beqz	$at,.L0f1555c4
/*  f15556c:	304b007f */ 	andi	$t3,$v0,0x7f
/*  f155570:	00540019 */ 	multu	$v0,$s4
/*  f155574:	8fa800f4 */ 	lw	$t0,0xf4($sp)
/*  f155578:	02202025 */ 	or	$a0,$s1,$zero
/*  f15557c:	27a500c0 */ 	addiu	$a1,$sp,0xc0
/*  f155580:	e7ba0014 */ 	swc1	$f26,0x14($sp)
/*  f155584:	e7b80018 */ 	swc1	$f24,0x18($sp)
/*  f155588:	e7b4001c */ 	swc1	$f20,0x1c($sp)
/*  f15558c:	e7b60020 */ 	swc1	$f22,0x20($sp)
/*  f155590:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f155594:	0000c012 */ 	mflo	$t8
/*  f155598:	03153021 */ 	addu	$a2,$t8,$s5
/*  f15559c:	24c6fe74 */ 	addiu	$a2,$a2,-396
/*  f1555a0:	02740019 */ 	multu	$s3,$s4
/*  f1555a4:	0000c812 */ 	mflo	$t9
/*  f1555a8:	03353821 */ 	addu	$a3,$t9,$s5
/*  f1555ac:	0fc553ce */ 	jal	func0f154f38
/*  f1555b0:	24e7fe74 */ 	addiu	$a3,$a3,-396
/*  f1555b4:	00408825 */ 	or	$s1,$v0,$zero
/*  f1555b8:	92130000 */ 	lbu	$s3,0x0($s0)
/*  f1555bc:	1000001f */ 	b	.L0f15563c
/*  f1555c0:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f1555c4:
/*  f1555c4:	3c0f8008 */ 	lui	$t7,%hi(var8007fbcc)
/*  f1555c8:	92090001 */ 	lbu	$t1,0x1($s0)
/*  f1555cc:	25effbcc */ 	addiu	$t7,$t7,%lo(var8007fbcc)
/*  f1555d0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1555d4:	000b61c0 */ 	sll	$t4,$t3,0x7
/*  f1555d8:	27ae0080 */ 	addiu	$t6,$sp,0x80
/*  f1555dc:	312a007f */ 	andi	$t2,$t1,0x7f
/*  f1555e0:	014c1825 */ 	or	$v1,$t2,$t4
/*  f1555e4:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1555e8:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1555ec:	8df90004 */ 	lw	$t9,0x4($t7)
/*  f1555f0:	3064ffff */ 	andi	$a0,$v1,0xffff
/*  f1555f4:	30882000 */ 	andi	$t0,$a0,0x2000
/*  f1555f8:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1555fc:	11000005 */ 	beqz	$t0,.L0f155614
/*  f155600:	add90004 */ 	sw	$t9,0x4($t6)
/*  f155604:	2409000f */ 	addiu	$t1,$zero,0xf
/*  f155608:	240b0010 */ 	addiu	$t3,$zero,0x10
/*  f15560c:	a3a90083 */ 	sb	$t1,0x83($sp)
/*  f155610:	a3ab0082 */ 	sb	$t3,0x82($sp)
.L0f155614:
/*  f155614:	308a1fff */ 	andi	$t2,$a0,0x1fff
/*  f155618:	294103c8 */ 	slti	$at,$t2,0x3c8
/*  f15561c:	54200003 */ 	bnezl	$at,.L0f15562c
/*  f155620:	248c0080 */ 	addiu	$t4,$a0,0x80
/*  f155624:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f155628:	248c0080 */ 	addiu	$t4,$a0,0x80
.L0f15562c:
/*  f15562c:	0fc5b8ff */ 	jal	lang0f16e3fc
/*  f155630:	a3ac0080 */ 	sb	$t4,0x80($sp)
/*  f155634:	afa20088 */ 	sw	$v0,0x88($sp)
/*  f155638:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f15563c:
/*  f15563c:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f155640:	1440ffab */ 	bnez	$v0,.L0f1554f0
/*  f155644:	00000000 */ 	nop
.L0f155648:
/*  f155648:	8fbf0074 */ 	lw	$ra,0x74($sp)
/*  f15564c:	02201025 */ 	or	$v0,$s1,$zero
/*  f155650:	8fb10054 */ 	lw	$s1,0x54($sp)
/*  f155654:	d7b40030 */ 	ldc1	$f20,0x30($sp)
/*  f155658:	d7b60038 */ 	ldc1	$f22,0x38($sp)
/*  f15565c:	d7b80040 */ 	ldc1	$f24,0x40($sp)
/*  f155660:	d7ba0048 */ 	ldc1	$f26,0x48($sp)
/*  f155664:	8fb00050 */ 	lw	$s0,0x50($sp)
/*  f155668:	8fb20058 */ 	lw	$s2,0x58($sp)
/*  f15566c:	8fb3005c */ 	lw	$s3,0x5c($sp)
/*  f155670:	8fb40060 */ 	lw	$s4,0x60($sp)
/*  f155674:	8fb50064 */ 	lw	$s5,0x64($sp)
/*  f155678:	8fb60068 */ 	lw	$s6,0x68($sp)
/*  f15567c:	8fb7006c */ 	lw	$s7,0x6c($sp)
/*  f155680:	8fbe0070 */ 	lw	$s8,0x70($sp)
/*  f155684:	03e00008 */ 	jr	$ra
/*  f155688:	27bd00d8 */ 	addiu	$sp,$sp,0xd8
);
#endif

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel func0f15568c
/*  f155504:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f155508:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f15550c:	3c1f8008 */ 	lui	$ra,0x8008
/*  f155510:	27ff0108 */ 	addiu	$ra,$ra,0x108
/*  f155514:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f155518:	8fb800d4 */ 	lw	$t8,0xd4($sp)
/*  f15551c:	3c0d8008 */ 	lui	$t5,0x8008
/*  f155520:	afae00ac */ 	sw	$t6,0xac($sp)
/*  f155524:	3c0e8008 */ 	lui	$t6,0x8008
/*  f155528:	8dce0100 */ 	lw	$t6,0x100($t6)
/*  f15552c:	25ad010c */ 	addiu	$t5,$t5,0x10c
/*  f155530:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f155534:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f155538:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f15553c:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f155540:	2719fffe */ 	addiu	$t9,$t8,-2
/*  f155544:	00808025 */ 	move	$s0,$a0
/*  f155548:	00e08825 */ 	move	$s1,$a3
/*  f15554c:	00a09025 */ 	move	$s2,$a1
/*  f155550:	afa600c0 */ 	sw	$a2,0xc0($sp)
/*  f155554:	afb900d4 */ 	sw	$t9,0xd4($sp)
/*  f155558:	11c00003 */ 	beqz	$t6,.JF0f155568
/*  f15555c:	afaf00a8 */ 	sw	$t7,0xa8($sp)
/*  f155560:	240f0001 */ 	li	$t7,0x1
/*  f155564:	afaf00ac */ 	sw	$t7,0xac($sp)
.JF0f155568:
/*  f155568:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f15556c:	8fae00e0 */ 	lw	$t6,0xe0($sp)
/*  f155570:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*  f155574:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f155578:	8fb800c8 */ 	lw	$t8,0xc8($sp)
/*  f15557c:	032e6021 */ 	addu	$t4,$t9,$t6
/*  f155580:	87190006 */ 	lh	$t9,0x6($t8)
/*  f155584:	00197080 */ 	sll	$t6,$t9,0x2
/*  f155588:	01d97023 */ 	subu	$t6,$t6,$t9
/*  f15558c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f155590:	01d97021 */ 	addu	$t6,$t6,$t9
/*  f155594:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f155598:	862e0006 */ 	lh	$t6,0x6($s1)
/*  f15559c:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f1555a0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1555a4:	032fc021 */ 	addu	$t8,$t9,$t7
/*  f1555a8:	3c198008 */ 	lui	$t9,0x8008
/*  f1555ac:	8f3900fc */ 	lw	$t9,0xfc($t9)
/*  f1555b0:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*  f1555b4:	8fb800ac */ 	lw	$t8,0xac($sp)
/*  f1555b8:	01d91021 */ 	addu	$v0,$t6,$t9
/*  f1555bc:	244fffff */ 	addiu	$t7,$v0,-1
/*  f1555c0:	01f80019 */ 	multu	$t7,$t8
/*  f1555c4:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f1555c8:	00007012 */ 	mflo	$t6
/*  f1555cc:	032e7823 */ 	subu	$t7,$t9,$t6
/*  f1555d0:	ae4f0000 */ 	sw	$t7,0x0($s2)
/*  f1555d4:	8fb800d8 */ 	lw	$t8,0xd8($sp)
/*  f1555d8:	8fb900ac */ 	lw	$t9,0xac($sp)
/*  f1555dc:	8faf00dc */ 	lw	$t7,0xdc($sp)
/*  f1555e0:	03190019 */ 	multu	$t8,$t9
/*  f1555e4:	8fb800a8 */ 	lw	$t8,0xa8($sp)
/*  f1555e8:	00007012 */ 	mflo	$t6
/*  f1555ec:	afae00d8 */ 	sw	$t6,0xd8($sp)
/*  f1555f0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1555f4:	01f80019 */ 	multu	$t7,$t8
/*  f1555f8:	8dce0100 */ 	lw	$t6,0x100($t6)
/*  f1555fc:	0000c812 */ 	mflo	$t9
/*  f155600:	afb900dc */ 	sw	$t9,0xdc($sp)
/*  f155604:	55c00017 */ 	bnezl	$t6,.JF0f155664
/*  f155608:	8fa300d0 */ 	lw	$v1,0xd0($sp)
/*  f15560c:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f155610:	59e002ee */ 	blezl	$t7,.JF0f1561cc
/*  f155614:	922f0004 */ 	lbu	$t7,0x4($s1)
/*  f155618:	0c002eeb */ 	jal	viGetWidth
/*  f15561c:	afac00b0 */ 	sw	$t4,0xb0($sp)
/*  f155620:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f155624:	8fac00b0 */ 	lw	$t4,0xb0($sp)
/*  f155628:	0058082a */ 	slt	$at,$v0,$t8
/*  f15562c:	542002e7 */ 	bnezl	$at,.JF0f1561cc
/*  f155630:	922f0004 */ 	lbu	$t7,0x4($s1)
/*  f155634:	0c002eef */ 	jal	viGetHeight
/*  f155638:	afac00b0 */ 	sw	$t4,0xb0($sp)
/*  f15563c:	8fac00b0 */ 	lw	$t4,0xb0($sp)
/*  f155640:	82390002 */ 	lb	$t9,0x2($s1)
/*  f155644:	3c0d8008 */ 	lui	$t5,0x8008
/*  f155648:	3c1f8008 */ 	lui	$ra,0x8008
/*  f15564c:	01997021 */ 	addu	$t6,$t4,$t9
/*  f155650:	004e082a */ 	slt	$at,$v0,$t6
/*  f155654:	27ff0108 */ 	addiu	$ra,$ra,0x108
/*  f155658:	142002db */ 	bnez	$at,.JF0f1561c8
/*  f15565c:	25ad010c */ 	addiu	$t5,$t5,0x10c
/*  f155660:	8fa300d0 */ 	lw	$v1,0xd0($sp)
.JF0f155664:
/*  f155664:	8faf00d8 */ 	lw	$t7,0xd8($sp)
/*  f155668:	8fae00d4 */ 	lw	$t6,0xd4($sp)
/*  f15566c:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f155670:	afb80040 */ 	sw	$t8,0x40($sp)
/*  f155674:	8e460000 */ 	lw	$a2,0x0($s2)
/*  f155678:	8faf00dc */ 	lw	$t7,0xdc($sp)
/*  f15567c:	0306082a */ 	slt	$at,$t8,$a2
/*  f155680:	142002d1 */ 	bnez	$at,.JF0f1561c8
/*  f155684:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f155688:	afb8003c */ 	sw	$t8,0x3c($sp)
/*  f15568c:	82390002 */ 	lb	$t9,0x2($s1)
/*  f155690:	032c1021 */ 	addu	$v0,$t9,$t4
/*  f155694:	0302082a */ 	slt	$at,$t8,$v0
/*  f155698:	142002cb */ 	bnez	$at,.JF0f1561c8
/*  f15569c:	00c3082a */ 	slt	$at,$a2,$v1
/*  f1556a0:	542002ca */ 	bnezl	$at,.JF0f1561cc
/*  f1556a4:	922f0004 */ 	lbu	$t7,0x4($s1)
/*  f1556a8:	922f0003 */ 	lbu	$t7,0x3($s1)
/*  f1556ac:	004fc821 */ 	addu	$t9,$v0,$t7
/*  f1556b0:	032e082a */ 	slt	$at,$t9,$t6
/*  f1556b4:	542002c5 */ 	bnezl	$at,.JF0f1561cc
/*  f1556b8:	922f0004 */ 	lbu	$t7,0x4($s1)
/*  f1556bc:	8e380008 */ 	lw	$t8,0x8($s1)
/*  f1556c0:	5700000c */ 	bnezl	$t8,.JF0f1556f4
/*  f1556c4:	962f0000 */ 	lhu	$t7,0x0($s1)
/*  f1556c8:	96240000 */ 	lhu	$a0,0x0($s1)
/*  f1556cc:	afac00b0 */ 	sw	$t4,0xb0($sp)
/*  f1556d0:	0fc5b967 */ 	jal	lang0f16e3fc
/*  f1556d4:	2484ff80 */ 	addiu	$a0,$a0,-128
/*  f1556d8:	8fac00b0 */ 	lw	$t4,0xb0($sp)
/*  f1556dc:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1556e0:	3c1f8008 */ 	lui	$ra,0x8008
/*  f1556e4:	27ff0108 */ 	addiu	$ra,$ra,0x108
/*  f1556e8:	25ad010c */ 	addiu	$t5,$t5,0x10c
/*  f1556ec:	ae220008 */ 	sw	$v0,0x8($s1)
/*  f1556f0:	962f0000 */ 	lhu	$t7,0x0($s1)
.JF0f1556f4:
/*  f1556f4:	3c198008 */ 	lui	$t9,0x8008
/*  f1556f8:	3c188008 */ 	lui	$t8,0x8008
/*  f1556fc:	29e10080 */ 	slti	$at,$t7,0x80
/*  f155700:	14200023 */ 	bnez	$at,.JF0f155790
/*  f155704:	00000000 */ 	nop
/*  f155708:	8f3900f8 */ 	lw	$t9,0xf8($t9)
/*  f15570c:	02002825 */ 	move	$a1,$s0
/*  f155710:	3c0efd10 */ 	lui	$t6,0xfd10
/*  f155714:	1720003e */ 	bnez	$t9,.JF0f155810
/*  f155718:	3c048008 */ 	lui	$a0,0x8008
/*  f15571c:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f155720:	afac00b0 */ 	sw	$t4,0xb0($sp)
/*  f155724:	afa500a4 */ 	sw	$a1,0xa4($sp)
/*  f155728:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15572c:	0c012b34 */ 	jal	osVirtualToPhysical
/*  f155730:	248401d8 */ 	addiu	$a0,$a0,0x1d8
/*  f155734:	8fa500a4 */ 	lw	$a1,0xa4($sp)
/*  f155738:	8fac00b0 */ 	lw	$t4,0xb0($sp)
/*  f15573c:	24180001 */ 	li	$t8,0x1
/*  f155740:	3c018008 */ 	lui	$at,0x8008
/*  f155744:	02001825 */ 	move	$v1,$s0
/*  f155748:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f15574c:	ac3800f8 */ 	sw	$t8,0xf8($at)
/*  f155750:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155754:	3c0fe600 */ 	lui	$t7,0xe600
/*  f155758:	02002025 */ 	move	$a0,$s0
/*  f15575c:	3c0e0603 */ 	lui	$t6,0x603
/*  f155760:	3c0d8008 */ 	lui	$t5,0x8008
/*  f155764:	3c1f8008 */ 	lui	$ra,0x8008
/*  f155768:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f15576c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f155770:	35cec000 */ 	ori	$t6,$t6,0xc000
/*  f155774:	3c19f000 */ 	lui	$t9,0xf000
/*  f155778:	27ff0108 */ 	addiu	$ra,$ra,0x108
/*  f15577c:	25ad010c */ 	addiu	$t5,$t5,0x10c
/*  f155780:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f155784:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f155788:	10000021 */ 	b	.JF0f155810
/*  f15578c:	26100008 */ 	addiu	$s0,$s0,0x8
.JF0f155790:
/*  f155790:	8f1800f8 */ 	lw	$t8,0xf8($t8)
/*  f155794:	02002825 */ 	move	$a1,$s0
/*  f155798:	3c0ffd10 */ 	lui	$t7,0xfd10
/*  f15579c:	1300001c */ 	beqz	$t8,.JF0f155810
/*  f1557a0:	3c048008 */ 	lui	$a0,0x8008
/*  f1557a4:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f1557a8:	afac00b0 */ 	sw	$t4,0xb0($sp)
/*  f1557ac:	afa50098 */ 	sw	$a1,0x98($sp)
/*  f1557b0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1557b4:	0c012b34 */ 	jal	osVirtualToPhysical
/*  f1557b8:	24840178 */ 	addiu	$a0,$a0,0x178
/*  f1557bc:	8fa50098 */ 	lw	$a1,0x98($sp)
/*  f1557c0:	8fac00b0 */ 	lw	$t4,0xb0($sp)
/*  f1557c4:	3c018008 */ 	lui	$at,0x8008
/*  f1557c8:	02001825 */ 	move	$v1,$s0
/*  f1557cc:	aca20004 */ 	sw	$v0,0x4($a1)
/*  f1557d0:	ac2000f8 */ 	sw	$zero,0xf8($at)
/*  f1557d4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1557d8:	3c19e600 */ 	lui	$t9,0xe600
/*  f1557dc:	02002025 */ 	move	$a0,$s0
/*  f1557e0:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f1557e4:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1557e8:	3c180603 */ 	lui	$t8,0x603
/*  f1557ec:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1557f0:	3c1f8008 */ 	lui	$ra,0x8008
/*  f1557f4:	3718c000 */ 	ori	$t8,$t8,0xc000
/*  f1557f8:	3c0ef000 */ 	lui	$t6,0xf000
/*  f1557fc:	27ff0108 */ 	addiu	$ra,$ra,0x108
/*  f155800:	25ad010c */ 	addiu	$t5,$t5,0x10c
/*  f155804:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f155808:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f15580c:	26100008 */ 	addiu	$s0,$s0,0x8
.JF0f155810:
/*  f155810:	02001025 */ 	move	$v0,$s0
/*  f155814:	3c0ffd50 */ 	lui	$t7,0xfd50
/*  f155818:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f15581c:	8e390008 */ 	lw	$t9,0x8($s1)
/*  f155820:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155824:	02001825 */ 	move	$v1,$s0
/*  f155828:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f15582c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155830:	3c0ee600 */ 	lui	$t6,0xe600
/*  f155834:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f155838:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f15583c:	02002025 */ 	move	$a0,$s0
/*  f155840:	3c18f300 */ 	lui	$t8,0xf300
/*  f155844:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f155848:	92250003 */ 	lbu	$a1,0x3($s1)
/*  f15584c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155850:	240307ff */ 	li	$v1,0x7ff
/*  f155854:	000578c0 */ 	sll	$t7,$a1,0x3
/*  f155858:	25e50011 */ 	addiu	$a1,$t7,0x11
/*  f15585c:	0005c843 */ 	sra	$t9,$a1,0x1
/*  f155860:	2725ffff */ 	addiu	$a1,$t9,-1
/*  f155864:	28a107ff */ 	slti	$at,$a1,0x7ff
/*  f155868:	10200003 */ 	beqz	$at,.JF0f155878
/*  f15586c:	02001025 */ 	move	$v0,$s0
/*  f155870:	10000001 */ 	b	.JF0f155878
/*  f155874:	00a01825 */ 	move	$v1,$a1
.JF0f155878:
/*  f155878:	306e0fff */ 	andi	$t6,$v1,0xfff
/*  f15587c:	000ec300 */ 	sll	$t8,$t6,0xc
/*  f155880:	3c010700 */ 	lui	$at,0x700
/*  f155884:	03017825 */ 	or	$t7,$t8,$at
/*  f155888:	35f90800 */ 	ori	$t9,$t7,0x800
/*  f15588c:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f155890:	3c0ee700 */ 	lui	$t6,0xe700
/*  f155894:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f155898:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f15589c:	3c18800a */ 	lui	$t8,0x800a
/*  f1558a0:	93184f98 */ 	lbu	$t8,0x4f98($t8)
/*  f1558a4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1558a8:	3c198008 */ 	lui	$t9,0x8008
/*  f1558ac:	5300001c */ 	beqzl	$t8,.JF0f155920
/*  f1558b0:	922b0004 */ 	lbu	$t3,0x4($s1)
/*  f1558b4:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f1558b8:	8f3900f4 */ 	lw	$t9,0xf4($t9)
/*  f1558bc:	8fae00c0 */ 	lw	$t6,0xc0($sp)
/*  f1558c0:	02002025 */ 	move	$a0,$s0
/*  f1558c4:	01f9001a */ 	div	$zero,$t7,$t9
/*  f1558c8:	17200002 */ 	bnez	$t9,.JF0f1558d4
/*  f1558cc:	00000000 */ 	nop
/*  f1558d0:	0007000d */ 	break	0x7
.JF0f1558d4:
/*  f1558d4:	2401ffff */ 	li	$at,-1
/*  f1558d8:	17210004 */ 	bne	$t9,$at,.JF0f1558ec
/*  f1558dc:	3c018000 */ 	lui	$at,0x8000
/*  f1558e0:	15e10002 */ 	bne	$t7,$at,.JF0f1558ec
/*  f1558e4:	00000000 */ 	nop
/*  f1558e8:	0006000d */ 	break	0x6
.JF0f1558ec:
/*  f1558ec:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f1558f0:	8dd80000 */ 	lw	$t8,0x0($t6)
/*  f1558f4:	00002812 */ 	mflo	$a1
/*  f1558f8:	afac00b0 */ 	sw	$t4,0xb0($sp)
/*  f1558fc:	0fc5518e */ 	jal	func0f154ecc
/*  f155900:	030f3021 */ 	addu	$a2,$t8,$t7
/*  f155904:	3c0d8008 */ 	lui	$t5,0x8008
/*  f155908:	3c1f8008 */ 	lui	$ra,0x8008
/*  f15590c:	27ff0108 */ 	addiu	$ra,$ra,0x108
/*  f155910:	25ad010c */ 	addiu	$t5,$t5,0x10c
/*  f155914:	8fac00b0 */ 	lw	$t4,0xb0($sp)
/*  f155918:	00408025 */ 	move	$s0,$v0
/*  f15591c:	922b0004 */ 	lbu	$t3,0x4($s1)
.JF0f155920:
/*  f155920:	8fae00ac */ 	lw	$t6,0xac($sp)
/*  f155924:	8e460000 */ 	lw	$a2,0x0($s2)
/*  f155928:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f15592c:	01cb0019 */ 	multu	$t6,$t3
/*  f155930:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f155934:	0000c012 */ 	mflo	$t8
/*  f155938:	00d87821 */ 	addu	$t7,$a2,$t8
/*  f15593c:	032f082a */ 	slt	$at,$t9,$t7
/*  f155940:	54200222 */ 	bnezl	$at,.JF0f1561cc
/*  f155944:	922f0004 */ 	lbu	$t7,0x4($s1)
/*  f155948:	82270002 */ 	lb	$a3,0x2($s1)
/*  f15594c:	8fb900d4 */ 	lw	$t9,0xd4($sp)
/*  f155950:	00ee0019 */ 	multu	$a3,$t6
/*  f155954:	0000c012 */ 	mflo	$t8
/*  f155958:	030c1021 */ 	addu	$v0,$t8,$t4
/*  f15595c:	0059082a */ 	slt	$at,$v0,$t9
/*  f155960:	542001b0 */ 	bnezl	$at,.JF0f156024
/*  f155964:	8da20000 */ 	lw	$v0,0x0($t5)
/*  f155968:	922a0003 */ 	lbu	$t2,0x3($s1)
/*  f15596c:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f155970:	014e0019 */ 	multu	$t2,$t6
/*  f155974:	3c0e8008 */ 	lui	$t6,0x8008
/*  f155978:	0000c012 */ 	mflo	$t8
/*  f15597c:	0058c821 */ 	addu	$t9,$v0,$t8
/*  f155980:	01f9082a */ 	slt	$at,$t7,$t9
/*  f155984:	54200145 */ 	bnezl	$at,.JF0f155e9c
/*  f155988:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f15598c:	8dce0100 */ 	lw	$t6,0x100($t6)
/*  f155990:	51c00065 */ 	beqzl	$t6,.JF0f155b28
/*  f155994:	8ff90000 */ 	lw	$t9,0x0($ra)
/*  f155998:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f15599c:	3c088008 */ 	lui	$t0,0x8008
/*  f1559a0:	25080118 */ 	addiu	$t0,$t0,0x118
/*  f1559a4:	01780019 */ 	multu	$t3,$t8
/*  f1559a8:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f1559ac:	3c098008 */ 	lui	$t1,0x8008
/*  f1559b0:	3c01e500 */ 	lui	$at,0xe500
/*  f1559b4:	2529011c */ 	addiu	$t1,$t1,0x11c
/*  f1559b8:	02001025 */ 	move	$v0,$s0
/*  f1559bc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1559c0:	02001825 */ 	move	$v1,$s0
/*  f1559c4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1559c8:	02002025 */ 	move	$a0,$s0
/*  f1559cc:	00007812 */ 	mflo	$t7
/*  f1559d0:	00cfc821 */ 	addu	$t9,$a2,$t7
/*  f1559d4:	00197080 */ 	sll	$t6,$t9,0x2
/*  f1559d8:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f1559dc:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f1559e0:	03217025 */ 	or	$t6,$t9,$at
/*  f1559e4:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f1559e8:	0187c023 */ 	subu	$t8,$t4,$a3
/*  f1559ec:	00187880 */ 	sll	$t7,$t8,0x2
/*  f1559f0:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f1559f4:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f1559f8:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f1559fc:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f155a00:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f155a04:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f155a08:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f155a0c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155a10:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f155a14:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f155a18:	8ff90000 */ 	lw	$t9,0x0($ra)
/*  f155a1c:	922e0003 */ 	lbu	$t6,0x3($s1)
/*  f155a20:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f155a24:	01d90019 */ 	multu	$t6,$t9
/*  f155a28:	822e0002 */ 	lb	$t6,0x2($s1)
/*  f155a2c:	018ec823 */ 	subu	$t9,$t4,$t6
/*  f155a30:	0000c012 */ 	mflo	$t8
/*  f155a34:	03387023 */ 	subu	$t6,$t9,$t8
/*  f155a38:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f155a3c:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f155a40:	03387021 */ 	addu	$t6,$t9,$t8
/*  f155a44:	31d90fff */ 	andi	$t9,$t6,0xfff
/*  f155a48:	0019c300 */ 	sll	$t8,$t9,0xc
/*  f155a4c:	01f87025 */ 	or	$t6,$t7,$t8
/*  f155a50:	ac4e0004 */ 	sw	$t6,0x4($v0)
/*  f155a54:	3c19b400 */ 	lui	$t9,0xb400
/*  f155a58:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f155a5c:	922f0003 */ 	lbu	$t7,0x3($s1)
/*  f155a60:	3c198008 */ 	lui	$t9,0x8008
/*  f155a64:	8f390120 */ 	lw	$t9,0x120($t9)
/*  f155a68:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f155a6c:	00187140 */ 	sll	$t6,$t8,0x5
/*  f155a70:	01d97821 */ 	addu	$t7,$t6,$t9
/*  f155a74:	3c198008 */ 	lui	$t9,0x8008
/*  f155a78:	8f390124 */ 	lw	$t9,0x124($t9)
/*  f155a7c:	25f80020 */ 	addiu	$t8,$t7,0x20
/*  f155a80:	330effff */ 	andi	$t6,$t8,0xffff
/*  f155a84:	27380020 */ 	addiu	$t8,$t9,0x20
/*  f155a88:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f155a8c:	032e7825 */ 	or	$t7,$t9,$t6
/*  f155a90:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f155a94:	3c18b300 */ 	lui	$t8,0xb300
/*  f155a98:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f155a9c:	8db90000 */ 	lw	$t9,0x0($t5)
/*  f155aa0:	240e0400 */ 	li	$t6,0x400
/*  f155aa4:	240f0400 */ 	li	$t7,0x400
/*  f155aa8:	01d9001a */ 	div	$zero,$t6,$t9
/*  f155aac:	17200002 */ 	bnez	$t9,.JF0f155ab8
/*  f155ab0:	00000000 */ 	nop
/*  f155ab4:	0007000d */ 	break	0x7
.JF0f155ab8:
/*  f155ab8:	2401ffff */ 	li	$at,-1
/*  f155abc:	17210004 */ 	bne	$t9,$at,.JF0f155ad0
/*  f155ac0:	3c018000 */ 	lui	$at,0x8000
/*  f155ac4:	15c10002 */ 	bne	$t6,$at,.JF0f155ad0
/*  f155ac8:	00000000 */ 	nop
/*  f155acc:	0006000d */ 	break	0x6
.JF0f155ad0:
/*  f155ad0:	8ff90000 */ 	lw	$t9,0x0($ra)
/*  f155ad4:	0000c012 */ 	mflo	$t8
/*  f155ad8:	00187400 */ 	sll	$t6,$t8,0x10
/*  f155adc:	00000000 */ 	nop
/*  f155ae0:	01f9001a */ 	div	$zero,$t7,$t9
/*  f155ae4:	17200002 */ 	bnez	$t9,.JF0f155af0
/*  f155ae8:	00000000 */ 	nop
/*  f155aec:	0007000d */ 	break	0x7
.JF0f155af0:
/*  f155af0:	2401ffff */ 	li	$at,-1
/*  f155af4:	17210004 */ 	bne	$t9,$at,.JF0f155b08
/*  f155af8:	3c018000 */ 	lui	$at,0x8000
/*  f155afc:	15e10002 */ 	bne	$t7,$at,.JF0f155b08
/*  f155b00:	00000000 */ 	nop
/*  f155b04:	0006000d */ 	break	0x6
.JF0f155b08:
/*  f155b08:	3c0f0001 */ 	lui	$t7,0x1
/*  f155b0c:	0000c012 */ 	mflo	$t8
/*  f155b10:	01f8c823 */ 	subu	$t9,$t7,$t8
/*  f155b14:	332fffff */ 	andi	$t7,$t9,0xffff
/*  f155b18:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f155b1c:	100001aa */ 	b	.JF0f1561c8
/*  f155b20:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f155b24:	8ff90000 */ 	lw	$t9,0x0($ra)
.JF0f155b28:
/*  f155b28:	8da20000 */ 	lw	$v0,0x0($t5)
/*  f155b2c:	3c088008 */ 	lui	$t0,0x8008
/*  f155b30:	01790019 */ 	multu	$t3,$t9
/*  f155b34:	25080118 */ 	addiu	$t0,$t0,0x118
/*  f155b38:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f155b3c:	3c01e400 */ 	lui	$at,0xe400
/*  f155b40:	3c098008 */ 	lui	$t1,0x8008
/*  f155b44:	2529011c */ 	addiu	$t1,$t1,0x11c
/*  f155b48:	02001825 */ 	move	$v1,$s0
/*  f155b4c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155b50:	02002025 */ 	move	$a0,$s0
/*  f155b54:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155b58:	00007012 */ 	mflo	$t6
/*  f155b5c:	00ce7821 */ 	addu	$t7,$a2,$t6
/*  f155b60:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f155b64:	00e20019 */ 	multu	$a3,$v0
/*  f155b68:	03197021 */ 	addu	$t6,$t8,$t9
/*  f155b6c:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f155b70:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f155b74:	0301c825 */ 	or	$t9,$t8,$at
/*  f155b78:	02002825 */ 	move	$a1,$s0
/*  f155b7c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155b80:	00007012 */ 	mflo	$t6
/*  f155b84:	018e7821 */ 	addu	$t7,$t4,$t6
/*  f155b88:	00000000 */ 	nop
/*  f155b8c:	01420019 */ 	multu	$t2,$v0
/*  f155b90:	0000c012 */ 	mflo	$t8
/*  f155b94:	01f87021 */ 	addu	$t6,$t7,$t8
/*  f155b98:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f155b9c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f155ba0:	01f87021 */ 	addu	$t6,$t7,$t8
/*  f155ba4:	00027880 */ 	sll	$t7,$v0,0x2
/*  f155ba8:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f155bac:	270e0004 */ 	addiu	$t6,$t8,0x4
/*  f155bb0:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f155bb4:	032fc025 */ 	or	$t8,$t9,$t7
/*  f155bb8:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f155bbc:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f155bc0:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f155bc4:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f155bc8:	032fc021 */ 	addu	$t8,$t9,$t7
/*  f155bcc:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f155bd0:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f155bd4:	822f0002 */ 	lb	$t7,0x2($s1)
/*  f155bd8:	000ecb00 */ 	sll	$t9,$t6,0xc
/*  f155bdc:	01f80019 */ 	multu	$t7,$t8
/*  f155be0:	00007012 */ 	mflo	$t6
/*  f155be4:	018e7821 */ 	addu	$t7,$t4,$t6
/*  f155be8:	8d2e0000 */ 	lw	$t6,0x0($t1)
/*  f155bec:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f155bf0:	030e7821 */ 	addu	$t7,$t8,$t6
/*  f155bf4:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f155bf8:	03387025 */ 	or	$t6,$t9,$t8
/*  f155bfc:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f155c00:	3c0fb400 */ 	lui	$t7,0xb400
/*  f155c04:	ac8f0000 */ 	sw	$t7,0x0($a0)
/*  f155c08:	3c198008 */ 	lui	$t9,0x8008
/*  f155c0c:	8f390120 */ 	lw	$t9,0x120($t9)
/*  f155c10:	272e0020 */ 	addiu	$t6,$t9,0x20
/*  f155c14:	3c198008 */ 	lui	$t9,0x8008
/*  f155c18:	8f390124 */ 	lw	$t9,0x124($t9)
/*  f155c1c:	000e7c00 */ 	sll	$t7,$t6,0x10
/*  f155c20:	27380020 */ 	addiu	$t8,$t9,0x20
/*  f155c24:	330effff */ 	andi	$t6,$t8,0xffff
/*  f155c28:	01eec825 */ 	or	$t9,$t7,$t6
/*  f155c2c:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f155c30:	3c18b300 */ 	lui	$t8,0xb300
/*  f155c34:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f155c38:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f155c3c:	240e0400 */ 	li	$t6,0x400
/*  f155c40:	24190400 */ 	li	$t9,0x400
/*  f155c44:	01cf001a */ 	div	$zero,$t6,$t7
/*  f155c48:	15e00002 */ 	bnez	$t7,.JF0f155c54
/*  f155c4c:	00000000 */ 	nop
/*  f155c50:	0007000d */ 	break	0x7
.JF0f155c54:
/*  f155c54:	2401ffff */ 	li	$at,-1
/*  f155c58:	15e10004 */ 	bne	$t7,$at,.JF0f155c6c
/*  f155c5c:	3c018000 */ 	lui	$at,0x8000
/*  f155c60:	15c10002 */ 	bne	$t6,$at,.JF0f155c6c
/*  f155c64:	00000000 */ 	nop
/*  f155c68:	0006000d */ 	break	0x6
.JF0f155c6c:
/*  f155c6c:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f155c70:	0000c012 */ 	mflo	$t8
/*  f155c74:	00187400 */ 	sll	$t6,$t8,0x10
/*  f155c78:	00000000 */ 	nop
/*  f155c7c:	032f001a */ 	div	$zero,$t9,$t7
/*  f155c80:	0000c012 */ 	mflo	$t8
/*  f155c84:	15e00002 */ 	bnez	$t7,.JF0f155c90
/*  f155c88:	00000000 */ 	nop
/*  f155c8c:	0007000d */ 	break	0x7
.JF0f155c90:
/*  f155c90:	2401ffff */ 	li	$at,-1
/*  f155c94:	15e10004 */ 	bne	$t7,$at,.JF0f155ca8
/*  f155c98:	3c018000 */ 	lui	$at,0x8000
/*  f155c9c:	17210002 */ 	bne	$t9,$at,.JF0f155ca8
/*  f155ca0:	00000000 */ 	nop
/*  f155ca4:	0006000d */ 	break	0x6
.JF0f155ca8:
/*  f155ca8:	3319ffff */ 	andi	$t9,$t8,0xffff
/*  f155cac:	01d97825 */ 	or	$t7,$t6,$t9
/*  f155cb0:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f155cb4:	3c188008 */ 	lui	$t8,0x8008
/*  f155cb8:	8f1801f8 */ 	lw	$t8,0x1f8($t8)
/*  f155cbc:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f155cc0:	8fae00c0 */ 	lw	$t6,0xc0($sp)
/*  f155cc4:	53000141 */ 	beqzl	$t8,.JF0f1561cc
/*  f155cc8:	922f0004 */ 	lbu	$t7,0x4($s1)
/*  f155ccc:	8dd90000 */ 	lw	$t9,0x0($t6)
/*  f155cd0:	afac00b0 */ 	sw	$t4,0xb0($sp)
/*  f155cd4:	0fc54cb6 */ 	jal	func0f153b6c
/*  f155cd8:	032f2021 */ 	addu	$a0,$t9,$t7
/*  f155cdc:	3c0e8008 */ 	lui	$t6,0x8008
/*  f155ce0:	8dce00f4 */ 	lw	$t6,0xf4($t6)
/*  f155ce4:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f155ce8:	3c058008 */ 	lui	$a1,0x8008
/*  f155cec:	8ca501fc */ 	lw	$a1,0x1fc($a1)
/*  f155cf0:	030e001a */ 	div	$zero,$t8,$t6
/*  f155cf4:	00001812 */ 	mflo	$v1
/*  f155cf8:	3c0d8008 */ 	lui	$t5,0x8008
/*  f155cfc:	3c1f8008 */ 	lui	$ra,0x8008
/*  f155d00:	27ff0108 */ 	addiu	$ra,$ra,0x108
/*  f155d04:	25ad010c */ 	addiu	$t5,$t5,0x10c
/*  f155d08:	8fac00b0 */ 	lw	$t4,0xb0($sp)
/*  f155d0c:	15c00002 */ 	bnez	$t6,.JF0f155d18
/*  f155d10:	00000000 */ 	nop
/*  f155d14:	0007000d */ 	break	0x7
.JF0f155d18:
/*  f155d18:	2401ffff */ 	li	$at,-1
/*  f155d1c:	15c10004 */ 	bne	$t6,$at,.JF0f155d30
/*  f155d20:	3c018000 */ 	lui	$at,0x8000
/*  f155d24:	17010002 */ 	bne	$t8,$at,.JF0f155d30
/*  f155d28:	00000000 */ 	nop
/*  f155d2c:	0006000d */ 	break	0x6
.JF0f155d30:
/*  f155d30:	00a3082a */ 	slt	$at,$a1,$v1
/*  f155d34:	54200036 */ 	bnezl	$at,.JF0f155e10
/*  f155d38:	24a2fffd */ 	addiu	$v0,$a1,-3
/*  f155d3c:	92390004 */ 	lbu	$t9,0x4($s1)
/*  f155d40:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f155d44:	032f0019 */ 	multu	$t9,$t7
/*  f155d48:	0000c012 */ 	mflo	$t8
/*  f155d4c:	00787021 */ 	addu	$t6,$v1,$t8
/*  f155d50:	01c5082a */ 	slt	$at,$t6,$a1
/*  f155d54:	5420002e */ 	bnezl	$at,.JF0f155e10
/*  f155d58:	24a2fffd */ 	addiu	$v0,$a1,-3
/*  f155d5c:	8da20000 */ 	lw	$v0,0x0($t5)
/*  f155d60:	82390002 */ 	lb	$t9,0x2($s1)
/*  f155d64:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f155d68:	3c03800a */ 	lui	$v1,0x800a
/*  f155d6c:	03220019 */ 	multu	$t9,$v0
/*  f155d70:	8c634f9c */ 	lw	$v1,0x4f9c($v1)
/*  f155d74:	3c04800a */ 	lui	$a0,0x800a
/*  f155d78:	8c844ffc */ 	lw	$a0,0x4ffc($a0)
/*  f155d7c:	afac00b0 */ 	sw	$t4,0xb0($sp)
/*  f155d80:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f155d84:	00a03825 */ 	move	$a3,$a1
/*  f155d88:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f155d8c:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f155d90:	00007812 */ 	mflo	$t7
/*  f155d94:	01ec3021 */ 	addu	$a2,$t7,$t4
/*  f155d98:	00000000 */ 	nop
/*  f155d9c:	03020019 */ 	multu	$t8,$v0
/*  f155da0:	00007012 */ 	mflo	$t6
/*  f155da4:	00cec821 */ 	addu	$t9,$a2,$t6
/*  f155da8:	0fc35773 */ 	jal	func0f0d4d0c
/*  f155dac:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f155db0:	3c01800a */ 	lui	$at,0x800a
/*  f155db4:	ac224ffc */ 	sw	$v0,0x4ffc($at)
/*  f155db8:	3c188008 */ 	lui	$t8,0x8008
/*  f155dbc:	8f1800f4 */ 	lw	$t8,0xf4($t8)
/*  f155dc0:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f155dc4:	3c0d8008 */ 	lui	$t5,0x8008
/*  f155dc8:	3c1f8008 */ 	lui	$ra,0x8008
/*  f155dcc:	01f8001a */ 	div	$zero,$t7,$t8
/*  f155dd0:	00001812 */ 	mflo	$v1
/*  f155dd4:	3c058008 */ 	lui	$a1,0x8008
/*  f155dd8:	8ca501fc */ 	lw	$a1,0x1fc($a1)
/*  f155ddc:	27ff0108 */ 	addiu	$ra,$ra,0x108
/*  f155de0:	25ad010c */ 	addiu	$t5,$t5,0x10c
/*  f155de4:	8fac00b0 */ 	lw	$t4,0xb0($sp)
/*  f155de8:	17000002 */ 	bnez	$t8,.JF0f155df4
/*  f155dec:	00000000 */ 	nop
/*  f155df0:	0007000d */ 	break	0x7
.JF0f155df4:
/*  f155df4:	2401ffff */ 	li	$at,-1
/*  f155df8:	17010004 */ 	bne	$t8,$at,.JF0f155e0c
/*  f155dfc:	3c018000 */ 	lui	$at,0x8000
/*  f155e00:	15e10002 */ 	bne	$t7,$at,.JF0f155e0c
/*  f155e04:	00000000 */ 	nop
/*  f155e08:	0006000d */ 	break	0x6
.JF0f155e0c:
/*  f155e0c:	24a2fffd */ 	addiu	$v0,$a1,-3
.JF0f155e10:
/*  f155e10:	0043082a */ 	slt	$at,$v0,$v1
/*  f155e14:	542000ed */ 	bnezl	$at,.JF0f1561cc
/*  f155e18:	922f0004 */ 	lbu	$t7,0x4($s1)
/*  f155e1c:	922e0004 */ 	lbu	$t6,0x4($s1)
/*  f155e20:	8ff90000 */ 	lw	$t9,0x0($ra)
/*  f155e24:	01d90019 */ 	multu	$t6,$t9
/*  f155e28:	00007812 */ 	mflo	$t7
/*  f155e2c:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f155e30:	0302082a */ 	slt	$at,$t8,$v0
/*  f155e34:	542000e5 */ 	bnezl	$at,.JF0f1561cc
/*  f155e38:	922f0004 */ 	lbu	$t7,0x4($s1)
/*  f155e3c:	8da20000 */ 	lw	$v0,0x0($t5)
/*  f155e40:	822e0002 */ 	lb	$t6,0x2($s1)
/*  f155e44:	922f0003 */ 	lbu	$t7,0x3($s1)
/*  f155e48:	3c03800a */ 	lui	$v1,0x800a
/*  f155e4c:	01c20019 */ 	multu	$t6,$v0
/*  f155e50:	8c634f9c */ 	lw	$v1,0x4f9c($v1)
/*  f155e54:	3c04800a */ 	lui	$a0,0x800a
/*  f155e58:	8c844ffc */ 	lw	$a0,0x4ffc($a0)
/*  f155e5c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f155e60:	00a03825 */ 	move	$a3,$a1
/*  f155e64:	afa30014 */ 	sw	$v1,0x14($sp)
/*  f155e68:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f155e6c:	0000c812 */ 	mflo	$t9
/*  f155e70:	032c3021 */ 	addu	$a2,$t9,$t4
/*  f155e74:	00000000 */ 	nop
/*  f155e78:	01e20019 */ 	multu	$t7,$v0
/*  f155e7c:	0000c012 */ 	mflo	$t8
/*  f155e80:	00d87021 */ 	addu	$t6,$a2,$t8
/*  f155e84:	0fc35773 */ 	jal	func0f0d4d0c
/*  f155e88:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f155e8c:	3c01800a */ 	lui	$at,0x800a
/*  f155e90:	100000cd */ 	b	.JF0f1561c8
/*  f155e94:	ac224ffc */ 	sw	$v0,0x4ffc($at)
/*  f155e98:	8daf0000 */ 	lw	$t7,0x0($t5)
.JF0f155e9c:
/*  f155e9c:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*  f155ea0:	00ef0019 */ 	multu	$a3,$t7
/*  f155ea4:	0000c012 */ 	mflo	$t8
/*  f155ea8:	030c7021 */ 	addu	$t6,$t8,$t4
/*  f155eac:	032e082a */ 	slt	$at,$t9,$t6
/*  f155eb0:	542000c6 */ 	bnezl	$at,.JF0f1561cc
/*  f155eb4:	922f0004 */ 	lbu	$t7,0x4($s1)
/*  f155eb8:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f155ebc:	3c088008 */ 	lui	$t0,0x8008
/*  f155ec0:	25080118 */ 	addiu	$t0,$t0,0x118
/*  f155ec4:	016f0019 */ 	multu	$t3,$t7
/*  f155ec8:	3c098008 */ 	lui	$t1,0x8008
/*  f155ecc:	3c01e400 */ 	lui	$at,0xe400
/*  f155ed0:	2529011c */ 	addiu	$t1,$t1,0x11c
/*  f155ed4:	02001025 */ 	move	$v0,$s0
/*  f155ed8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155edc:	02001825 */ 	move	$v1,$s0
/*  f155ee0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155ee4:	02002025 */ 	move	$a0,$s0
/*  f155ee8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155eec:	0000c012 */ 	mflo	$t8
/*  f155ef0:	00d87021 */ 	addu	$t6,$a2,$t8
/*  f155ef4:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f155ef8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f155efc:	01f87021 */ 	addu	$t6,$t7,$t8
/*  f155f00:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f155f04:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f155f08:	03017025 */ 	or	$t6,$t8,$at
/*  f155f0c:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f155f10:	00197880 */ 	sll	$t7,$t9,0x2
/*  f155f14:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f155f18:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f155f1c:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f155f20:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f155f24:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f155f28:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f155f2c:	00197080 */ 	sll	$t6,$t9,0x2
/*  f155f30:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f155f34:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f155f38:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f155f3c:	822f0002 */ 	lb	$t7,0x2($s1)
/*  f155f40:	00197300 */ 	sll	$t6,$t9,0xc
/*  f155f44:	01f80019 */ 	multu	$t7,$t8
/*  f155f48:	0000c812 */ 	mflo	$t9
/*  f155f4c:	01997821 */ 	addu	$t7,$t4,$t9
/*  f155f50:	8d390000 */ 	lw	$t9,0x0($t1)
/*  f155f54:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f155f58:	03197821 */ 	addu	$t7,$t8,$t9
/*  f155f5c:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f155f60:	01d8c825 */ 	or	$t9,$t6,$t8
/*  f155f64:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f155f68:	3c0fb400 */ 	lui	$t7,0xb400
/*  f155f6c:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f155f70:	3c0e8008 */ 	lui	$t6,0x8008
/*  f155f74:	8dce0120 */ 	lw	$t6,0x120($t6)
/*  f155f78:	25d90020 */ 	addiu	$t9,$t6,0x20
/*  f155f7c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f155f80:	8dce0124 */ 	lw	$t6,0x124($t6)
/*  f155f84:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f155f88:	25d80020 */ 	addiu	$t8,$t6,0x20
/*  f155f8c:	3319ffff */ 	andi	$t9,$t8,0xffff
/*  f155f90:	01f97025 */ 	or	$t6,$t7,$t9
/*  f155f94:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f155f98:	3c18b300 */ 	lui	$t8,0xb300
/*  f155f9c:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f155fa0:	8fef0000 */ 	lw	$t7,0x0($ra)
/*  f155fa4:	24190400 */ 	li	$t9,0x400
/*  f155fa8:	240e0400 */ 	li	$t6,0x400
/*  f155fac:	032f001a */ 	div	$zero,$t9,$t7
/*  f155fb0:	15e00002 */ 	bnez	$t7,.JF0f155fbc
/*  f155fb4:	00000000 */ 	nop
/*  f155fb8:	0007000d */ 	break	0x7
.JF0f155fbc:
/*  f155fbc:	2401ffff */ 	li	$at,-1
/*  f155fc0:	15e10004 */ 	bne	$t7,$at,.JF0f155fd4
/*  f155fc4:	3c018000 */ 	lui	$at,0x8000
/*  f155fc8:	17210002 */ 	bne	$t9,$at,.JF0f155fd4
/*  f155fcc:	00000000 */ 	nop
/*  f155fd0:	0006000d */ 	break	0x6
.JF0f155fd4:
/*  f155fd4:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f155fd8:	0000c012 */ 	mflo	$t8
/*  f155fdc:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f155fe0:	00000000 */ 	nop
/*  f155fe4:	01cf001a */ 	div	$zero,$t6,$t7
/*  f155fe8:	0000c012 */ 	mflo	$t8
/*  f155fec:	15e00002 */ 	bnez	$t7,.JF0f155ff8
/*  f155ff0:	00000000 */ 	nop
/*  f155ff4:	0007000d */ 	break	0x7
.JF0f155ff8:
/*  f155ff8:	2401ffff */ 	li	$at,-1
/*  f155ffc:	15e10004 */ 	bne	$t7,$at,.JF0f156010
/*  f156000:	3c018000 */ 	lui	$at,0x8000
/*  f156004:	15c10002 */ 	bne	$t6,$at,.JF0f156010
/*  f156008:	00000000 */ 	nop
/*  f15600c:	0006000d */ 	break	0x6
.JF0f156010:
/*  f156010:	330effff */ 	andi	$t6,$t8,0xffff
/*  f156014:	032e7825 */ 	or	$t7,$t9,$t6
/*  f156018:	1000006b */ 	b	.JF0f1561c8
/*  f15601c:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f156020:	8da20000 */ 	lw	$v0,0x0($t5)
.JF0f156024:
/*  f156024:	922e0003 */ 	lbu	$t6,0x3($s1)
/*  f156028:	00e20019 */ 	multu	$a3,$v0
/*  f15602c:	0000c012 */ 	mflo	$t8
/*  f156030:	030cc821 */ 	addu	$t9,$t8,$t4
/*  f156034:	8fb800d4 */ 	lw	$t8,0xd4($sp)
/*  f156038:	01c20019 */ 	multu	$t6,$v0
/*  f15603c:	00007812 */ 	mflo	$t7
/*  f156040:	032f2021 */ 	addu	$a0,$t9,$t7
/*  f156044:	0098082a */ 	slt	$at,$a0,$t8
/*  f156048:	54200060 */ 	bnezl	$at,.JF0f1561cc
/*  f15604c:	922f0004 */ 	lbu	$t7,0x4($s1)
/*  f156050:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f156054:	3c088008 */ 	lui	$t0,0x8008
/*  f156058:	25080118 */ 	addiu	$t0,$t0,0x118
/*  f15605c:	016e0019 */ 	multu	$t3,$t6
/*  f156060:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f156064:	3c098008 */ 	lui	$t1,0x8008
/*  f156068:	2529011c */ 	addiu	$t1,$t1,0x11c
/*  f15606c:	3c01e400 */ 	lui	$at,0xe400
/*  f156070:	02001025 */ 	move	$v0,$s0
/*  f156074:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156078:	02001825 */ 	move	$v1,$s0
/*  f15607c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156080:	02002825 */ 	move	$a1,$s0
/*  f156084:	0000c812 */ 	mflo	$t9
/*  f156088:	00d97821 */ 	addu	$t7,$a2,$t9
/*  f15608c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f156090:	030ec821 */ 	addu	$t9,$t8,$t6
/*  f156094:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f156098:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f15609c:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f1560a0:	03017025 */ 	or	$t6,$t8,$at
/*  f1560a4:	0004c880 */ 	sll	$t9,$a0,0x2
/*  f1560a8:	032fc021 */ 	addu	$t8,$t9,$t7
/*  f1560ac:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f1560b0:	01d97825 */ 	or	$t7,$t6,$t9
/*  f1560b4:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f1560b8:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f1560bc:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f1560c0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1560c4:	00187080 */ 	sll	$t6,$t8,0x2
/*  f1560c8:	01d97821 */ 	addu	$t7,$t6,$t9
/*  f1560cc:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f1560d0:	8fb900d4 */ 	lw	$t9,0xd4($sp)
/*  f1560d4:	00187300 */ 	sll	$t6,$t8,0xc
/*  f1560d8:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f1560dc:	00197880 */ 	sll	$t7,$t9,0x2
/*  f1560e0:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f1560e4:	332f0fff */ 	andi	$t7,$t9,0xfff
/*  f1560e8:	01cfc025 */ 	or	$t8,$t6,$t7
/*  f1560ec:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f1560f0:	3c19b400 */ 	lui	$t9,0xb400
/*  f1560f4:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f1560f8:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f1560fc:	822e0002 */ 	lb	$t6,0x2($s1)
/*  f156100:	8fb900d4 */ 	lw	$t9,0xd4($sp)
/*  f156104:	01cf0019 */ 	multu	$t6,$t7
/*  f156108:	032c7023 */ 	subu	$t6,$t9,$t4
/*  f15610c:	0000c012 */ 	mflo	$t8
/*  f156110:	01d87823 */ 	subu	$t7,$t6,$t8
/*  f156114:	3c0e8008 */ 	lui	$t6,0x8008
/*  f156118:	8dce0124 */ 	lw	$t6,0x124($t6)
/*  f15611c:	000fc940 */ 	sll	$t9,$t7,0x5
/*  f156120:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f156124:	3c0e8008 */ 	lui	$t6,0x8008
/*  f156128:	8dce0120 */ 	lw	$t6,0x120($t6)
/*  f15612c:	270f0020 */ 	addiu	$t7,$t8,0x20
/*  f156130:	31f9ffff */ 	andi	$t9,$t7,0xffff
/*  f156134:	25cf0020 */ 	addiu	$t7,$t6,0x20
/*  f156138:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f15613c:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f156140:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f156144:	3c0fb300 */ 	lui	$t7,0xb300
/*  f156148:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f15614c:	8fee0000 */ 	lw	$t6,0x0($ra)
/*  f156150:	24190400 */ 	li	$t9,0x400
/*  f156154:	24180400 */ 	li	$t8,0x400
/*  f156158:	032e001a */ 	div	$zero,$t9,$t6
/*  f15615c:	15c00002 */ 	bnez	$t6,.JF0f156168
/*  f156160:	00000000 */ 	nop
/*  f156164:	0007000d */ 	break	0x7
.JF0f156168:
/*  f156168:	2401ffff */ 	li	$at,-1
/*  f15616c:	15c10004 */ 	bne	$t6,$at,.JF0f156180
/*  f156170:	3c018000 */ 	lui	$at,0x8000
/*  f156174:	17210002 */ 	bne	$t9,$at,.JF0f156180
/*  f156178:	00000000 */ 	nop
/*  f15617c:	0006000d */ 	break	0x6
.JF0f156180:
/*  f156180:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f156184:	00007812 */ 	mflo	$t7
/*  f156188:	000fcc00 */ 	sll	$t9,$t7,0x10
/*  f15618c:	00000000 */ 	nop
/*  f156190:	030e001a */ 	div	$zero,$t8,$t6
/*  f156194:	00007812 */ 	mflo	$t7
/*  f156198:	15c00002 */ 	bnez	$t6,.JF0f1561a4
/*  f15619c:	00000000 */ 	nop
/*  f1561a0:	0007000d */ 	break	0x7
.JF0f1561a4:
/*  f1561a4:	2401ffff */ 	li	$at,-1
/*  f1561a8:	15c10004 */ 	bne	$t6,$at,.JF0f1561bc
/*  f1561ac:	3c018000 */ 	lui	$at,0x8000
/*  f1561b0:	17010002 */ 	bne	$t8,$at,.JF0f1561bc
/*  f1561b4:	00000000 */ 	nop
/*  f1561b8:	0006000d */ 	break	0x6
.JF0f1561bc:
/*  f1561bc:	31f8ffff */ 	andi	$t8,$t7,0xffff
/*  f1561c0:	03387025 */ 	or	$t6,$t9,$t8
/*  f1561c4:	acae0004 */ 	sw	$t6,0x4($a1)
.JF0f1561c8:
/*  f1561c8:	922f0004 */ 	lbu	$t7,0x4($s1)
.JF0f1561cc:
/*  f1561cc:	8fb900ac */ 	lw	$t9,0xac($sp)
/*  f1561d0:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f1561d4:	02001025 */ 	move	$v0,$s0
/*  f1561d8:	01f90019 */ 	multu	$t7,$t9
/*  f1561dc:	0000c012 */ 	mflo	$t8
/*  f1561e0:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f1561e4:	ae4f0000 */ 	sw	$t7,0x0($s2)
/*  f1561e8:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1561ec:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f1561f0:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f1561f4:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f1561f8:	03e00008 */ 	jr	$ra
/*  f1561fc:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);
#elif VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel func0f15568c
/*  f156780:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f156784:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f156788:	3c0c8008 */ 	lui	$t4,0x8008
/*  f15678c:	3c198008 */ 	lui	$t9,0x8008
/*  f156790:	8f390028 */ 	lw	$t9,0x28($t9)
/*  f156794:	258c0030 */ 	addiu	$t4,$t4,0x30
/*  f156798:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f15679c:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f1567a0:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f1567a4:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f1567a8:	25f8fffe */ 	addiu	$t8,$t7,-2
/*  f1567ac:	00808025 */ 	move	$s0,$a0
/*  f1567b0:	00e08825 */ 	move	$s1,$a3
/*  f1567b4:	00a09025 */ 	move	$s2,$a1
/*  f1567b8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f1567bc:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f1567c0:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f1567c4:	13200003 */ 	beqz	$t9,.PF0f1567d4
/*  f1567c8:	afae008c */ 	sw	$t6,0x8c($sp)
/*  f1567cc:	240d0001 */ 	li	$t5,0x1
/*  f1567d0:	afad008c */ 	sw	$t5,0x8c($sp)
.PF0f1567d4:
/*  f1567d4:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f1567d8:	8fad00a8 */ 	lw	$t5,0xa8($sp)
/*  f1567dc:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f1567e0:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f1567e4:	8dae0004 */ 	lw	$t6,0x4($t5)
/*  f1567e8:	8fb900ac */ 	lw	$t9,0xac($sp)
/*  f1567ec:	01f85021 */ 	addu	$t2,$t7,$t8
/*  f1567f0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1567f4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1567f8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1567fc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f156800:	8e2e0004 */ 	lw	$t6,0x4($s1)
/*  f156804:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f156808:	03386821 */ 	addu	$t5,$t9,$t8
/*  f15680c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f156810:	01afc821 */ 	addu	$t9,$t5,$t7
/*  f156814:	3c0e8008 */ 	lui	$t6,0x8008
/*  f156818:	8dce0024 */ 	lw	$t6,0x24($t6)
/*  f15681c:	8f380000 */ 	lw	$t8,0x0($t9)
/*  f156820:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f156824:	030e1021 */ 	addu	$v0,$t8,$t6
/*  f156828:	244dffff */ 	addiu	$t5,$v0,-1
/*  f15682c:	01af0019 */ 	multu	$t5,$t7
/*  f156830:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f156834:	0000c812 */ 	mflo	$t9
/*  f156838:	03197023 */ 	subu	$t6,$t8,$t9
/*  f15683c:	ae4e0000 */ 	sw	$t6,0x0($s2)
/*  f156840:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*  f156844:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f156848:	3c198008 */ 	lui	$t9,0x8008
/*  f15684c:	8f390028 */ 	lw	$t9,0x28($t9)
/*  f156850:	01af0019 */ 	multu	$t5,$t7
/*  f156854:	0000c012 */ 	mflo	$t8
/*  f156858:	afb800b8 */ 	sw	$t8,0xb8($sp)
/*  f15685c:	57200016 */ 	bnezl	$t9,.PF0f1568b8
/*  f156860:	8fa200b0 */ 	lw	$v0,0xb0($sp)
/*  f156864:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f156868:	59c00222 */ 	blezl	$t6,.PF0f1570f4
/*  f15686c:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156870:	0c002e53 */ 	jal	viGetWidth
/*  f156874:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f156878:	8e4d0000 */ 	lw	$t5,0x0($s2)
/*  f15687c:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f156880:	004d082a */ 	slt	$at,$v0,$t5
/*  f156884:	5420021b */ 	bnezl	$at,.PF0f1570f4
/*  f156888:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f15688c:	0c002e57 */ 	jal	viGetHeight
/*  f156890:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f156894:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f156898:	822f0001 */ 	lb	$t7,0x1($s1)
/*  f15689c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1568a0:	258c0030 */ 	addiu	$t4,$t4,0x30
/*  f1568a4:	014fc021 */ 	addu	$t8,$t2,$t7
/*  f1568a8:	0058082a */ 	slt	$at,$v0,$t8
/*  f1568ac:	54200211 */ 	bnezl	$at,.PF0f1570f4
/*  f1568b0:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f1568b4:	8fa200b0 */ 	lw	$v0,0xb0($sp)
.PF0f1568b8:
/*  f1568b8:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*  f1568bc:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f1568c0:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f1568c4:	00594021 */ 	addu	$t0,$v0,$t9
/*  f1568c8:	0107082a */ 	slt	$at,$t0,$a3
/*  f1568cc:	14200208 */ 	bnez	$at,.PF0f1570f0
/*  f1568d0:	8fad00bc */ 	lw	$t5,0xbc($sp)
/*  f1568d4:	822f0001 */ 	lb	$t7,0x1($s1)
/*  f1568d8:	01cd5821 */ 	addu	$t3,$t6,$t5
/*  f1568dc:	01ea3021 */ 	addu	$a2,$t7,$t2
/*  f1568e0:	0166082a */ 	slt	$at,$t3,$a2
/*  f1568e4:	14200202 */ 	bnez	$at,.PF0f1570f0
/*  f1568e8:	00e2082a */ 	slt	$at,$a3,$v0
/*  f1568ec:	54200201 */ 	bnezl	$at,.PF0f1570f4
/*  f1568f0:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f1568f4:	92380002 */ 	lbu	$t8,0x2($s1)
/*  f1568f8:	02001025 */ 	move	$v0,$s0
/*  f1568fc:	3c0dfd50 */ 	lui	$t5,0xfd50
/*  f156900:	00d8c821 */ 	addu	$t9,$a2,$t8
/*  f156904:	032e082a */ 	slt	$at,$t9,$t6
/*  f156908:	142001f9 */ 	bnez	$at,.PF0f1570f0
/*  f15690c:	3c18e600 */ 	lui	$t8,0xe600
/*  f156910:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f156914:	8e2f0008 */ 	lw	$t7,0x8($s1)
/*  f156918:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15691c:	02001825 */ 	move	$v1,$s0
/*  f156920:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f156924:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156928:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f15692c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f156930:	02002025 */ 	move	$a0,$s0
/*  f156934:	3c19f300 */ 	lui	$t9,0xf300
/*  f156938:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f15693c:	92250002 */ 	lbu	$a1,0x2($s1)
/*  f156940:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156944:	02001025 */ 	move	$v0,$s0
/*  f156948:	000570c0 */ 	sll	$t6,$a1,0x3
/*  f15694c:	25c50011 */ 	addiu	$a1,$t6,0x11
/*  f156950:	00056843 */ 	sra	$t5,$a1,0x1
/*  f156954:	25a5ffff */ 	addiu	$a1,$t5,-1
/*  f156958:	28a107ff */ 	slti	$at,$a1,0x7ff
/*  f15695c:	10200003 */ 	beqz	$at,.PF0f15696c
/*  f156960:	3c0de700 */ 	lui	$t5,0xe700
/*  f156964:	10000002 */ 	b	.PF0f156970
/*  f156968:	00a01825 */ 	move	$v1,$a1
.PF0f15696c:
/*  f15696c:	240307ff */ 	li	$v1,0x7ff
.PF0f156970:
/*  f156970:	306f0fff */ 	andi	$t7,$v1,0xfff
/*  f156974:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f156978:	3c010700 */ 	lui	$at,0x700
/*  f15697c:	0301c825 */ 	or	$t9,$t8,$at
/*  f156980:	372e0800 */ 	ori	$t6,$t9,0x800
/*  f156984:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f156988:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f15698c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f156990:	3c0f800a */ 	lui	$t7,0x800a
/*  f156994:	91ef4b70 */ 	lbu	$t7,0x4b70($t7)
/*  f156998:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15699c:	02002025 */ 	move	$a0,$s0
/*  f1569a0:	11e0001c */ 	beqz	$t7,.PF0f156a14
/*  f1569a4:	3c198008 */ 	lui	$t9,0x8008
/*  f1569a8:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f1569ac:	8f390020 */ 	lw	$t9,0x20($t9)
/*  f1569b0:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f1569b4:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f1569b8:	0319001a */ 	div	$zero,$t8,$t9
/*  f1569bc:	8dcd0000 */ 	lw	$t5,0x0($t6)
/*  f1569c0:	00002812 */ 	mflo	$a1
/*  f1569c4:	afab0038 */ 	sw	$t3,0x38($sp)
/*  f1569c8:	17200002 */ 	bnez	$t9,.PF0f1569d4
/*  f1569cc:	00000000 */ 	nop
/*  f1569d0:	0007000d */ 	break	0x7
.PF0f1569d4:
/*  f1569d4:	2401ffff */ 	li	$at,-1
/*  f1569d8:	17210004 */ 	bne	$t9,$at,.PF0f1569ec
/*  f1569dc:	3c018000 */ 	lui	$at,0x8000
/*  f1569e0:	17010002 */ 	bne	$t8,$at,.PF0f1569ec
/*  f1569e4:	00000000 */ 	nop
/*  f1569e8:	0006000d */ 	break	0x6
.PF0f1569ec:
/*  f1569ec:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f1569f0:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f1569f4:	0fc556f8 */ 	jal	func0f154ecc
/*  f1569f8:	01af3021 */ 	addu	$a2,$t5,$t7
/*  f1569fc:	3c0c8008 */ 	lui	$t4,0x8008
/*  f156a00:	258c0030 */ 	addiu	$t4,$t4,0x30
/*  f156a04:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f156a08:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f156a0c:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f156a10:	00408025 */ 	move	$s0,$v0
.PF0f156a14:
/*  f156a14:	92290003 */ 	lbu	$t1,0x3($s1)
/*  f156a18:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f156a1c:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f156a20:	03090019 */ 	multu	$t8,$t1
/*  f156a24:	0000c812 */ 	mflo	$t9
/*  f156a28:	00f97021 */ 	addu	$t6,$a3,$t9
/*  f156a2c:	010e082a */ 	slt	$at,$t0,$t6
/*  f156a30:	542001b0 */ 	bnezl	$at,.PF0f1570f4
/*  f156a34:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156a38:	82240001 */ 	lb	$a0,0x1($s1)
/*  f156a3c:	8fa300b4 */ 	lw	$v1,0xb4($sp)
/*  f156a40:	008a3021 */ 	addu	$a2,$a0,$t2
/*  f156a44:	00c3082a */ 	slt	$at,$a2,$v1
/*  f156a48:	54200158 */ 	bnezl	$at,.PF0f156fac
/*  f156a4c:	92380002 */ 	lbu	$t8,0x2($s1)
/*  f156a50:	922d0002 */ 	lbu	$t5,0x2($s1)
/*  f156a54:	3c0f8008 */ 	lui	$t7,0x8008
/*  f156a58:	00cd1021 */ 	addu	$v0,$a2,$t5
/*  f156a5c:	0162082a */ 	slt	$at,$t3,$v0
/*  f156a60:	54200106 */ 	bnezl	$at,.PF0f156e7c
/*  f156a64:	0166082a */ 	slt	$at,$t3,$a2
/*  f156a68:	8def0028 */ 	lw	$t7,0x28($t7)
/*  f156a6c:	3c068008 */ 	lui	$a2,0x8008
/*  f156a70:	24c6003c */ 	addiu	$a2,$a2,0x3c
/*  f156a74:	11e00050 */ 	beqz	$t7,.PF0f156bb8
/*  f156a78:	3c088008 */ 	lui	$t0,0x8008
/*  f156a7c:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f156a80:	00e9c021 */ 	addu	$t8,$a3,$t1
/*  f156a84:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f156a88:	032e6821 */ 	addu	$t5,$t9,$t6
/*  f156a8c:	25080040 */ 	addiu	$t0,$t0,0x40
/*  f156a90:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f156a94:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*  f156a98:	0144c823 */ 	subu	$t9,$t2,$a0
/*  f156a9c:	3c01e500 */ 	lui	$at,0xe500
/*  f156aa0:	01e1c025 */ 	or	$t8,$t7,$at
/*  f156aa4:	00197080 */ 	sll	$t6,$t9,0x2
/*  f156aa8:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f156aac:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f156ab0:	00197300 */ 	sll	$t6,$t9,0xc
/*  f156ab4:	030e6825 */ 	or	$t5,$t8,$t6
/*  f156ab8:	02001025 */ 	move	$v0,$s0
/*  f156abc:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f156ac0:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f156ac4:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f156ac8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156acc:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f156ad0:	03387021 */ 	addu	$t6,$t9,$t8
/*  f156ad4:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f156ad8:	922f0002 */ 	lbu	$t7,0x2($s1)
/*  f156adc:	31cd0fff */ 	andi	$t5,$t6,0xfff
/*  f156ae0:	822e0001 */ 	lb	$t6,0x1($s1)
/*  f156ae4:	01f90019 */ 	multu	$t7,$t9
/*  f156ae8:	02001825 */ 	move	$v1,$s0
/*  f156aec:	014e7823 */ 	subu	$t7,$t2,$t6
/*  f156af0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156af4:	02002825 */ 	move	$a1,$s0
/*  f156af8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156afc:	0000c012 */ 	mflo	$t8
/*  f156b00:	01f8c823 */ 	subu	$t9,$t7,$t8
/*  f156b04:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f156b08:	00197080 */ 	sll	$t6,$t9,0x2
/*  f156b0c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f156b10:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f156b14:	00197300 */ 	sll	$t6,$t9,0xc
/*  f156b18:	01ae7825 */ 	or	$t7,$t5,$t6
/*  f156b1c:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f156b20:	3c18b400 */ 	lui	$t8,0xb400
/*  f156b24:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f156b28:	92390002 */ 	lbu	$t9,0x2($s1)
/*  f156b2c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f156b30:	8def0044 */ 	lw	$t7,0x44($t7)
/*  f156b34:	272dffff */ 	addiu	$t5,$t9,-1
/*  f156b38:	000d7140 */ 	sll	$t6,$t5,0x5
/*  f156b3c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f156b40:	3c0e8008 */ 	lui	$t6,0x8008
/*  f156b44:	8dce0048 */ 	lw	$t6,0x48($t6)
/*  f156b48:	27190020 */ 	addiu	$t9,$t8,0x20
/*  f156b4c:	332dffff */ 	andi	$t5,$t9,0xffff
/*  f156b50:	25d80020 */ 	addiu	$t8,$t6,0x20
/*  f156b54:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f156b58:	032d7025 */ 	or	$t6,$t9,$t5
/*  f156b5c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f156b60:	3c0fb300 */ 	lui	$t7,0xb300
/*  f156b64:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f156b68:	24190400 */ 	li	$t9,0x400
/*  f156b6c:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f156b70:	3c0e0001 */ 	lui	$t6,0x1
/*  f156b74:	0338001a */ 	div	$zero,$t9,$t8
/*  f156b78:	17000002 */ 	bnez	$t8,.PF0f156b84
/*  f156b7c:	00000000 */ 	nop
/*  f156b80:	0007000d */ 	break	0x7
.PF0f156b84:
/*  f156b84:	2401ffff */ 	li	$at,-1
/*  f156b88:	17010004 */ 	bne	$t8,$at,.PF0f156b9c
/*  f156b8c:	3c018000 */ 	lui	$at,0x8000
/*  f156b90:	17210002 */ 	bne	$t9,$at,.PF0f156b9c
/*  f156b94:	00000000 */ 	nop
/*  f156b98:	0006000d */ 	break	0x6
.PF0f156b9c:
/*  f156b9c:	00006812 */ 	mflo	$t5
/*  f156ba0:	01cd7823 */ 	subu	$t7,$t6,$t5
/*  f156ba4:	31f9ffff */ 	andi	$t9,$t7,0xffff
/*  f156ba8:	3c010400 */ 	lui	$at,0x400
/*  f156bac:	0321c025 */ 	or	$t8,$t9,$at
/*  f156bb0:	1000014f */ 	b	.PF0f1570f0
/*  f156bb4:	acb80004 */ 	sw	$t8,0x4($a1)
.PF0f156bb8:
/*  f156bb8:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f156bbc:	3c068008 */ 	lui	$a2,0x8008
/*  f156bc0:	24c6003c */ 	addiu	$a2,$a2,0x3c
/*  f156bc4:	012e0019 */ 	multu	$t1,$t6
/*  f156bc8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f156bcc:	3c088008 */ 	lui	$t0,0x8008
/*  f156bd0:	25080040 */ 	addiu	$t0,$t0,0x40
/*  f156bd4:	3c01e400 */ 	lui	$at,0xe400
/*  f156bd8:	02001825 */ 	move	$v1,$s0
/*  f156bdc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156be0:	02002025 */ 	move	$a0,$s0
/*  f156be4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156be8:	02002825 */ 	move	$a1,$s0
/*  f156bec:	00006812 */ 	mflo	$t5
/*  f156bf0:	00ed7821 */ 	addu	$t7,$a3,$t5
/*  f156bf4:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f156bf8:	03387021 */ 	addu	$t6,$t9,$t8
/*  f156bfc:	31cd0fff */ 	andi	$t5,$t6,0xfff
/*  f156c00:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f156c04:	000d7b00 */ 	sll	$t7,$t5,0xc
/*  f156c08:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f156c0c:	01e1c825 */ 	or	$t9,$t7,$at
/*  f156c10:	030e6821 */ 	addu	$t5,$t8,$t6
/*  f156c14:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f156c18:	032fc025 */ 	or	$t8,$t9,$t7
/*  f156c1c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f156c20:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f156c24:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f156c28:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156c2c:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f156c30:	01b97821 */ 	addu	$t7,$t5,$t9
/*  f156c34:	822d0001 */ 	lb	$t5,0x1($s1)
/*  f156c38:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f156c3c:	00187300 */ 	sll	$t6,$t8,0xc
/*  f156c40:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f156c44:	014dc821 */ 	addu	$t9,$t2,$t5
/*  f156c48:	00197880 */ 	sll	$t7,$t9,0x2
/*  f156c4c:	01f86821 */ 	addu	$t5,$t7,$t8
/*  f156c50:	31b90fff */ 	andi	$t9,$t5,0xfff
/*  f156c54:	01d97825 */ 	or	$t7,$t6,$t9
/*  f156c58:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f156c5c:	3c18b400 */ 	lui	$t8,0xb400
/*  f156c60:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f156c64:	3c0d8008 */ 	lui	$t5,0x8008
/*  f156c68:	8dad0044 */ 	lw	$t5,0x44($t5)
/*  f156c6c:	3c188008 */ 	lui	$t8,0x8008
/*  f156c70:	8f180048 */ 	lw	$t8,0x48($t8)
/*  f156c74:	25b90020 */ 	addiu	$t9,$t5,0x20
/*  f156c78:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f156c7c:	270d0020 */ 	addiu	$t5,$t8,0x20
/*  f156c80:	31aeffff */ 	andi	$t6,$t5,0xffff
/*  f156c84:	01eec825 */ 	or	$t9,$t7,$t6
/*  f156c88:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f156c8c:	3c18b300 */ 	lui	$t8,0xb300
/*  f156c90:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f156c94:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f156c98:	240f0400 */ 	li	$t7,0x400
/*  f156c9c:	01ed001a */ 	div	$zero,$t7,$t5
/*  f156ca0:	00007012 */ 	mflo	$t6
/*  f156ca4:	31d9ffff */ 	andi	$t9,$t6,0xffff
/*  f156ca8:	0019c400 */ 	sll	$t8,$t9,0x10
/*  f156cac:	15a00002 */ 	bnez	$t5,.PF0f156cb8
/*  f156cb0:	00000000 */ 	nop
/*  f156cb4:	0007000d */ 	break	0x7
.PF0f156cb8:
/*  f156cb8:	2401ffff */ 	li	$at,-1
/*  f156cbc:	15a10004 */ 	bne	$t5,$at,.PF0f156cd0
/*  f156cc0:	3c018000 */ 	lui	$at,0x8000
/*  f156cc4:	15e10002 */ 	bne	$t7,$at,.PF0f156cd0
/*  f156cc8:	00000000 */ 	nop
/*  f156ccc:	0006000d */ 	break	0x6
.PF0f156cd0:
/*  f156cd0:	370f0400 */ 	ori	$t7,$t8,0x400
/*  f156cd4:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f156cd8:	3c0d8008 */ 	lui	$t5,0x8008
/*  f156cdc:	8dad00fc */ 	lw	$t5,0xfc($t5)
/*  f156ce0:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f156ce4:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f156ce8:	51a00102 */ 	beqzl	$t5,.PF0f1570f4
/*  f156cec:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156cf0:	8dd90000 */ 	lw	$t9,0x0($t6)
/*  f156cf4:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f156cf8:	0fc55220 */ 	jal	func0f153b6c
/*  f156cfc:	03382021 */ 	addu	$a0,$t9,$t8
/*  f156d00:	3c0d8008 */ 	lui	$t5,0x8008
/*  f156d04:	8dad0020 */ 	lw	$t5,0x20($t5)
/*  f156d08:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f156d0c:	3c058008 */ 	lui	$a1,0x8008
/*  f156d10:	8ca50100 */ 	lw	$a1,0x100($a1)
/*  f156d14:	01ed001a */ 	div	$zero,$t7,$t5
/*  f156d18:	00001812 */ 	mflo	$v1
/*  f156d1c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f156d20:	258c0030 */ 	addiu	$t4,$t4,0x30
/*  f156d24:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f156d28:	15a00002 */ 	bnez	$t5,.PF0f156d34
/*  f156d2c:	00000000 */ 	nop
/*  f156d30:	0007000d */ 	break	0x7
.PF0f156d34:
/*  f156d34:	2401ffff */ 	li	$at,-1
/*  f156d38:	15a10004 */ 	bne	$t5,$at,.PF0f156d4c
/*  f156d3c:	3c018000 */ 	lui	$at,0x8000
/*  f156d40:	15e10002 */ 	bne	$t7,$at,.PF0f156d4c
/*  f156d44:	00000000 */ 	nop
/*  f156d48:	0006000d */ 	break	0x6
.PF0f156d4c:
/*  f156d4c:	00a3082a */ 	slt	$at,$a1,$v1
/*  f156d50:	5420002e */ 	bnezl	$at,.PF0f156e0c
/*  f156d54:	24a2fffd */ 	addiu	$v0,$a1,-3
/*  f156d58:	922e0003 */ 	lbu	$t6,0x3($s1)
/*  f156d5c:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f156d60:	3c04800a */ 	lui	$a0,0x800a
/*  f156d64:	00a03825 */ 	move	$a3,$a1
/*  f156d68:	01d90019 */ 	multu	$t6,$t9
/*  f156d6c:	3c02800a */ 	lui	$v0,0x800a
/*  f156d70:	0000c012 */ 	mflo	$t8
/*  f156d74:	00787821 */ 	addu	$t7,$v1,$t8
/*  f156d78:	01e5082a */ 	slt	$at,$t7,$a1
/*  f156d7c:	54200023 */ 	bnezl	$at,.PF0f156e0c
/*  f156d80:	24a2fffd */ 	addiu	$v0,$a1,-3
/*  f156d84:	822d0001 */ 	lb	$t5,0x1($s1)
/*  f156d88:	922e0002 */ 	lbu	$t6,0x2($s1)
/*  f156d8c:	8c424b74 */ 	lw	$v0,0x4b74($v0)
/*  f156d90:	01aa3021 */ 	addu	$a2,$t5,$t2
/*  f156d94:	00cec821 */ 	addu	$t9,$a2,$t6
/*  f156d98:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f156d9c:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f156da0:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f156da4:	8c844bd4 */ 	lw	$a0,0x4bd4($a0)
/*  f156da8:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f156dac:	0fc354ab */ 	jal	func0f0d4d0c
/*  f156db0:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f156db4:	3c01800a */ 	lui	$at,0x800a
/*  f156db8:	ac224bd4 */ 	sw	$v0,0x4bd4($at)
/*  f156dbc:	3c0f8008 */ 	lui	$t7,0x8008
/*  f156dc0:	8def0020 */ 	lw	$t7,0x20($t7)
/*  f156dc4:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f156dc8:	3c0c8008 */ 	lui	$t4,0x8008
/*  f156dcc:	3c058008 */ 	lui	$a1,0x8008
/*  f156dd0:	030f001a */ 	div	$zero,$t8,$t7
/*  f156dd4:	00001812 */ 	mflo	$v1
/*  f156dd8:	8ca50100 */ 	lw	$a1,0x100($a1)
/*  f156ddc:	258c0030 */ 	addiu	$t4,$t4,0x30
/*  f156de0:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f156de4:	15e00002 */ 	bnez	$t7,.PF0f156df0
/*  f156de8:	00000000 */ 	nop
/*  f156dec:	0007000d */ 	break	0x7
.PF0f156df0:
/*  f156df0:	2401ffff */ 	li	$at,-1
/*  f156df4:	15e10004 */ 	bne	$t7,$at,.PF0f156e08
/*  f156df8:	3c018000 */ 	lui	$at,0x8000
/*  f156dfc:	17010002 */ 	bne	$t8,$at,.PF0f156e08
/*  f156e00:	00000000 */ 	nop
/*  f156e04:	0006000d */ 	break	0x6
.PF0f156e08:
/*  f156e08:	24a2fffd */ 	addiu	$v0,$a1,-3
.PF0f156e0c:
/*  f156e0c:	0043082a */ 	slt	$at,$v0,$v1
/*  f156e10:	542000b8 */ 	bnezl	$at,.PF0f1570f4
/*  f156e14:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156e18:	922d0003 */ 	lbu	$t5,0x3($s1)
/*  f156e1c:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f156e20:	3c04800a */ 	lui	$a0,0x800a
/*  f156e24:	00a03825 */ 	move	$a3,$a1
/*  f156e28:	01ae0019 */ 	multu	$t5,$t6
/*  f156e2c:	0000c812 */ 	mflo	$t9
/*  f156e30:	0079c021 */ 	addu	$t8,$v1,$t9
/*  f156e34:	0302082a */ 	slt	$at,$t8,$v0
/*  f156e38:	142000ad */ 	bnez	$at,.PF0f1570f0
/*  f156e3c:	3c02800a */ 	lui	$v0,0x800a
/*  f156e40:	822f0001 */ 	lb	$t7,0x1($s1)
/*  f156e44:	922d0002 */ 	lbu	$t5,0x2($s1)
/*  f156e48:	8c424b74 */ 	lw	$v0,0x4b74($v0)
/*  f156e4c:	01ea3021 */ 	addu	$a2,$t7,$t2
/*  f156e50:	00cd7021 */ 	addu	$t6,$a2,$t5
/*  f156e54:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f156e58:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f156e5c:	8c844bd4 */ 	lw	$a0,0x4bd4($a0)
/*  f156e60:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f156e64:	0fc354ab */ 	jal	func0f0d4d0c
/*  f156e68:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f156e6c:	3c01800a */ 	lui	$at,0x800a
/*  f156e70:	1000009f */ 	b	.PF0f1570f0
/*  f156e74:	ac224bd4 */ 	sw	$v0,0x4bd4($at)
/*  f156e78:	0166082a */ 	slt	$at,$t3,$a2
.PF0f156e7c:
/*  f156e7c:	5420009d */ 	bnezl	$at,.PF0f1570f4
/*  f156e80:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156e84:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f156e88:	3c068008 */ 	lui	$a2,0x8008
/*  f156e8c:	24c6003c */ 	addiu	$a2,$a2,0x3c
/*  f156e90:	01390019 */ 	multu	$t1,$t9
/*  f156e94:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f156e98:	3c088008 */ 	lui	$t0,0x8008
/*  f156e9c:	25080040 */ 	addiu	$t0,$t0,0x40
/*  f156ea0:	3c01e400 */ 	lui	$at,0xe400
/*  f156ea4:	02001025 */ 	move	$v0,$s0
/*  f156ea8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156eac:	02001825 */ 	move	$v1,$s0
/*  f156eb0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156eb4:	02002025 */ 	move	$a0,$s0
/*  f156eb8:	0000c012 */ 	mflo	$t8
/*  f156ebc:	00f87821 */ 	addu	$t7,$a3,$t8
/*  f156ec0:	000f6880 */ 	sll	$t5,$t7,0x2
/*  f156ec4:	01aec821 */ 	addu	$t9,$t5,$t6
/*  f156ec8:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f156ecc:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f156ed0:	00187b00 */ 	sll	$t7,$t8,0xc
/*  f156ed4:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f156ed8:	01e16825 */ 	or	$t5,$t7,$at
/*  f156edc:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f156ee0:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f156ee4:	01af7025 */ 	or	$t6,$t5,$t7
/*  f156ee8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f156eec:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f156ef0:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f156ef4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156ef8:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f156efc:	030d7821 */ 	addu	$t7,$t8,$t5
/*  f156f00:	82380001 */ 	lb	$t8,0x1($s1)
/*  f156f04:	31ee0fff */ 	andi	$t6,$t7,0xfff
/*  f156f08:	000ecb00 */ 	sll	$t9,$t6,0xc
/*  f156f0c:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f156f10:	01586821 */ 	addu	$t5,$t2,$t8
/*  f156f14:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f156f18:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f156f1c:	330d0fff */ 	andi	$t5,$t8,0xfff
/*  f156f20:	032d7825 */ 	or	$t7,$t9,$t5
/*  f156f24:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f156f28:	3c0eb400 */ 	lui	$t6,0xb400
/*  f156f2c:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f156f30:	3c188008 */ 	lui	$t8,0x8008
/*  f156f34:	8f180044 */ 	lw	$t8,0x44($t8)
/*  f156f38:	3c0e8008 */ 	lui	$t6,0x8008
/*  f156f3c:	8dce0048 */ 	lw	$t6,0x48($t6)
/*  f156f40:	270d0020 */ 	addiu	$t5,$t8,0x20
/*  f156f44:	000d7c00 */ 	sll	$t7,$t5,0x10
/*  f156f48:	25d80020 */ 	addiu	$t8,$t6,0x20
/*  f156f4c:	3319ffff */ 	andi	$t9,$t8,0xffff
/*  f156f50:	01f96825 */ 	or	$t5,$t7,$t9
/*  f156f54:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f156f58:	240f0400 */ 	li	$t7,0x400
/*  f156f5c:	3c0eb300 */ 	lui	$t6,0xb300
/*  f156f60:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f156f64:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f156f68:	01f8001a */ 	div	$zero,$t7,$t8
/*  f156f6c:	0000c812 */ 	mflo	$t9
/*  f156f70:	332dffff */ 	andi	$t5,$t9,0xffff
/*  f156f74:	000d7400 */ 	sll	$t6,$t5,0x10
/*  f156f78:	17000002 */ 	bnez	$t8,.PF0f156f84
/*  f156f7c:	00000000 */ 	nop
/*  f156f80:	0007000d */ 	break	0x7
.PF0f156f84:
/*  f156f84:	2401ffff */ 	li	$at,-1
/*  f156f88:	17010004 */ 	bne	$t8,$at,.PF0f156f9c
/*  f156f8c:	3c018000 */ 	lui	$at,0x8000
/*  f156f90:	15e10002 */ 	bne	$t7,$at,.PF0f156f9c
/*  f156f94:	00000000 */ 	nop
/*  f156f98:	0006000d */ 	break	0x6
.PF0f156f9c:
/*  f156f9c:	35cf0400 */ 	ori	$t7,$t6,0x400
/*  f156fa0:	10000053 */ 	b	.PF0f1570f0
/*  f156fa4:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f156fa8:	92380002 */ 	lbu	$t8,0x2($s1)
.PF0f156fac:
/*  f156fac:	00d81021 */ 	addu	$v0,$a2,$t8
/*  f156fb0:	0043082a */ 	slt	$at,$v0,$v1
/*  f156fb4:	5420004f */ 	bnezl	$at,.PF0f1570f4
/*  f156fb8:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156fbc:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f156fc0:	3c068008 */ 	lui	$a2,0x8008
/*  f156fc4:	24c6003c */ 	addiu	$a2,$a2,0x3c
/*  f156fc8:	01390019 */ 	multu	$t1,$t9
/*  f156fcc:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f156fd0:	3c088008 */ 	lui	$t0,0x8008
/*  f156fd4:	25080040 */ 	addiu	$t0,$t0,0x40
/*  f156fd8:	3c01e400 */ 	lui	$at,0xe400
/*  f156fdc:	02001825 */ 	move	$v1,$s0
/*  f156fe0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156fe4:	02002025 */ 	move	$a0,$s0
/*  f156fe8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156fec:	02002825 */ 	move	$a1,$s0
/*  f156ff0:	00006812 */ 	mflo	$t5
/*  f156ff4:	00ed7021 */ 	addu	$t6,$a3,$t5
/*  f156ff8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f156ffc:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f157000:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f157004:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f157008:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f15700c:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f157010:	01c17825 */ 	or	$t7,$t6,$at
/*  f157014:	03196821 */ 	addu	$t5,$t8,$t9
/*  f157018:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f15701c:	01eec025 */ 	or	$t8,$t7,$t6
/*  f157020:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f157024:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f157028:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f15702c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f157030:	00196880 */ 	sll	$t5,$t9,0x2
/*  f157034:	01af7021 */ 	addu	$t6,$t5,$t7
/*  f157038:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f15703c:	31d80fff */ 	andi	$t8,$t6,0xfff
/*  f157040:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f157044:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f157048:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f15704c:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f157050:	330d0fff */ 	andi	$t5,$t8,0xfff
/*  f157054:	032d7825 */ 	or	$t7,$t9,$t5
/*  f157058:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f15705c:	3c0eb400 */ 	lui	$t6,0xb400
/*  f157060:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f157064:	8fb800b4 */ 	lw	$t8,0xb4($sp)
/*  f157068:	822d0001 */ 	lb	$t5,0x1($s1)
/*  f15706c:	030ac823 */ 	subu	$t9,$t8,$t2
/*  f157070:	3c188008 */ 	lui	$t8,0x8008
/*  f157074:	8f180048 */ 	lw	$t8,0x48($t8)
/*  f157078:	032d7823 */ 	subu	$t7,$t9,$t5
/*  f15707c:	000f7140 */ 	sll	$t6,$t7,0x5
/*  f157080:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f157084:	3c0e8008 */ 	lui	$t6,0x8008
/*  f157088:	8dce0044 */ 	lw	$t6,0x44($t6)
/*  f15708c:	272d0020 */ 	addiu	$t5,$t9,0x20
/*  f157090:	31afffff */ 	andi	$t7,$t5,0xffff
/*  f157094:	25d90020 */ 	addiu	$t9,$t6,0x20
/*  f157098:	00196c00 */ 	sll	$t5,$t9,0x10
/*  f15709c:	01af7025 */ 	or	$t6,$t5,$t7
/*  f1570a0:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f1570a4:	3c18b300 */ 	lui	$t8,0xb300
/*  f1570a8:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1570ac:	240d0400 */ 	li	$t5,0x400
/*  f1570b0:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f1570b4:	01b9001a */ 	div	$zero,$t5,$t9
/*  f1570b8:	00007812 */ 	mflo	$t7
/*  f1570bc:	31eeffff */ 	andi	$t6,$t7,0xffff
/*  f1570c0:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f1570c4:	17200002 */ 	bnez	$t9,.PF0f1570d0
/*  f1570c8:	00000000 */ 	nop
/*  f1570cc:	0007000d */ 	break	0x7
.PF0f1570d0:
/*  f1570d0:	2401ffff */ 	li	$at,-1
/*  f1570d4:	17210004 */ 	bne	$t9,$at,.PF0f1570e8
/*  f1570d8:	3c018000 */ 	lui	$at,0x8000
/*  f1570dc:	15a10002 */ 	bne	$t5,$at,.PF0f1570e8
/*  f1570e0:	00000000 */ 	nop
/*  f1570e4:	0006000d */ 	break	0x6
.PF0f1570e8:
/*  f1570e8:	370d0400 */ 	ori	$t5,$t8,0x400
/*  f1570ec:	acad0004 */ 	sw	$t5,0x4($a1)
.PF0f1570f0:
/*  f1570f0:	92390003 */ 	lbu	$t9,0x3($s1)
.PF0f1570f4:
/*  f1570f4:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f1570f8:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f1570fc:	02001025 */ 	move	$v0,$s0
/*  f157100:	032f0019 */ 	multu	$t9,$t7
/*  f157104:	00007012 */ 	mflo	$t6
/*  f157108:	030e6821 */ 	addu	$t5,$t8,$t6
/*  f15710c:	ae4d0000 */ 	sw	$t5,0x0($s2)
/*  f157110:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f157114:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f157118:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f15711c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f157120:	03e00008 */ 	jr	$ra
/*  f157124:	27bd0098 */ 	addiu	$sp,$sp,0x98
);
#elif VERSION >= VERSION_PAL_BETA
GLOBAL_ASM(
glabel func0f15568c
/*  f156e80:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f156e84:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f156e88:	3c0c8008 */ 	lui	$t4,0x8008
/*  f156e8c:	3c198008 */ 	lui	$t9,0x8008
/*  f156e90:	8f391f98 */ 	lw	$t9,0x1f98($t9)
/*  f156e94:	258c1fa0 */ 	addiu	$t4,$t4,0x1fa0
/*  f156e98:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f156e9c:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f156ea0:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f156ea4:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f156ea8:	25f8fffe */ 	addiu	$t8,$t7,-2
/*  f156eac:	00808025 */ 	move	$s0,$a0
/*  f156eb0:	00e08825 */ 	move	$s1,$a3
/*  f156eb4:	00a09025 */ 	move	$s2,$a1
/*  f156eb8:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f156ebc:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f156ec0:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f156ec4:	13200003 */ 	beqz	$t9,.PB0f156ed4
/*  f156ec8:	afae008c */ 	sw	$t6,0x8c($sp)
/*  f156ecc:	240d0001 */ 	li	$t5,0x1
/*  f156ed0:	afad008c */ 	sw	$t5,0x8c($sp)
.PB0f156ed4:
/*  f156ed4:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f156ed8:	8fad00a8 */ 	lw	$t5,0xa8($sp)
/*  f156edc:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f156ee0:	8dcf0000 */ 	lw	$t7,0x0($t6)
/*  f156ee4:	8dae0004 */ 	lw	$t6,0x4($t5)
/*  f156ee8:	8fb900ac */ 	lw	$t9,0xac($sp)
/*  f156eec:	01f85021 */ 	addu	$t2,$t7,$t8
/*  f156ef0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f156ef4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f156ef8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f156efc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f156f00:	8e2e0004 */ 	lw	$t6,0x4($s1)
/*  f156f04:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f156f08:	03386821 */ 	addu	$t5,$t9,$t8
/*  f156f0c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f156f10:	01afc821 */ 	addu	$t9,$t5,$t7
/*  f156f14:	3c0e8008 */ 	lui	$t6,0x8008
/*  f156f18:	8dce1f94 */ 	lw	$t6,0x1f94($t6)
/*  f156f1c:	8f380000 */ 	lw	$t8,0x0($t9)
/*  f156f20:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f156f24:	030e1021 */ 	addu	$v0,$t8,$t6
/*  f156f28:	244dffff */ 	addiu	$t5,$v0,-1
/*  f156f2c:	01af0019 */ 	multu	$t5,$t7
/*  f156f30:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f156f34:	0000c812 */ 	mflo	$t9
/*  f156f38:	03197023 */ 	subu	$t6,$t8,$t9
/*  f156f3c:	ae4e0000 */ 	sw	$t6,0x0($s2)
/*  f156f40:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*  f156f44:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f156f48:	3c198008 */ 	lui	$t9,0x8008
/*  f156f4c:	8f391f98 */ 	lw	$t9,0x1f98($t9)
/*  f156f50:	01af0019 */ 	multu	$t5,$t7
/*  f156f54:	0000c012 */ 	mflo	$t8
/*  f156f58:	afb800b8 */ 	sw	$t8,0xb8($sp)
/*  f156f5c:	57200016 */ 	bnezl	$t9,.PB0f156fb8
/*  f156f60:	8fa200b0 */ 	lw	$v0,0xb0($sp)
/*  f156f64:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f156f68:	59c00222 */ 	blezl	$t6,.PB0f1577f4
/*  f156f6c:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156f70:	0c002e4d */ 	jal	viGetWidth
/*  f156f74:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f156f78:	8e4d0000 */ 	lw	$t5,0x0($s2)
/*  f156f7c:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f156f80:	004d082a */ 	slt	$at,$v0,$t5
/*  f156f84:	5420021b */ 	bnezl	$at,.PB0f1577f4
/*  f156f88:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156f8c:	0c002e51 */ 	jal	viGetHeight
/*  f156f90:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f156f94:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f156f98:	822f0001 */ 	lb	$t7,0x1($s1)
/*  f156f9c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f156fa0:	258c1fa0 */ 	addiu	$t4,$t4,0x1fa0
/*  f156fa4:	014fc021 */ 	addu	$t8,$t2,$t7
/*  f156fa8:	0058082a */ 	slt	$at,$v0,$t8
/*  f156fac:	54200211 */ 	bnezl	$at,.PB0f1577f4
/*  f156fb0:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156fb4:	8fa200b0 */ 	lw	$v0,0xb0($sp)
.PB0f156fb8:
/*  f156fb8:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*  f156fbc:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f156fc0:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f156fc4:	00594021 */ 	addu	$t0,$v0,$t9
/*  f156fc8:	0107082a */ 	slt	$at,$t0,$a3
/*  f156fcc:	14200208 */ 	bnez	$at,.PB0f1577f0
/*  f156fd0:	8fad00bc */ 	lw	$t5,0xbc($sp)
/*  f156fd4:	822f0001 */ 	lb	$t7,0x1($s1)
/*  f156fd8:	01cd5821 */ 	addu	$t3,$t6,$t5
/*  f156fdc:	01ea3021 */ 	addu	$a2,$t7,$t2
/*  f156fe0:	0166082a */ 	slt	$at,$t3,$a2
/*  f156fe4:	14200202 */ 	bnez	$at,.PB0f1577f0
/*  f156fe8:	00e2082a */ 	slt	$at,$a3,$v0
/*  f156fec:	54200201 */ 	bnezl	$at,.PB0f1577f4
/*  f156ff0:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156ff4:	92380002 */ 	lbu	$t8,0x2($s1)
/*  f156ff8:	02001025 */ 	move	$v0,$s0
/*  f156ffc:	3c0dfd50 */ 	lui	$t5,0xfd50
/*  f157000:	00d8c821 */ 	addu	$t9,$a2,$t8
/*  f157004:	032e082a */ 	slt	$at,$t9,$t6
/*  f157008:	142001f9 */ 	bnez	$at,.PB0f1577f0
/*  f15700c:	3c18e600 */ 	lui	$t8,0xe600
/*  f157010:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f157014:	8e2f0008 */ 	lw	$t7,0x8($s1)
/*  f157018:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15701c:	02001825 */ 	move	$v1,$s0
/*  f157020:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f157024:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f157028:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f15702c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f157030:	02002025 */ 	move	$a0,$s0
/*  f157034:	3c19f300 */ 	lui	$t9,0xf300
/*  f157038:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f15703c:	92250002 */ 	lbu	$a1,0x2($s1)
/*  f157040:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f157044:	02001025 */ 	move	$v0,$s0
/*  f157048:	000570c0 */ 	sll	$t6,$a1,0x3
/*  f15704c:	25c50011 */ 	addiu	$a1,$t6,0x11
/*  f157050:	00056843 */ 	sra	$t5,$a1,0x1
/*  f157054:	25a5ffff */ 	addiu	$a1,$t5,-1
/*  f157058:	28a107ff */ 	slti	$at,$a1,0x7ff
/*  f15705c:	10200003 */ 	beqz	$at,.PB0f15706c
/*  f157060:	3c0de700 */ 	lui	$t5,0xe700
/*  f157064:	10000002 */ 	b	.PB0f157070
/*  f157068:	00a01825 */ 	move	$v1,$a1
.PB0f15706c:
/*  f15706c:	240307ff */ 	li	$v1,0x7ff
.PB0f157070:
/*  f157070:	306f0fff */ 	andi	$t7,$v1,0xfff
/*  f157074:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f157078:	3c010700 */ 	lui	$at,0x700
/*  f15707c:	0301c825 */ 	or	$t9,$t8,$at
/*  f157080:	372e0800 */ 	ori	$t6,$t9,0x800
/*  f157084:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f157088:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f15708c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f157090:	3c0f800b */ 	lui	$t7,0x800b
/*  f157094:	91ef8bf0 */ 	lbu	$t7,-0x7410($t7)
/*  f157098:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15709c:	02002025 */ 	move	$a0,$s0
/*  f1570a0:	11e0001c */ 	beqz	$t7,.PB0f157114
/*  f1570a4:	3c198008 */ 	lui	$t9,0x8008
/*  f1570a8:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f1570ac:	8f391f90 */ 	lw	$t9,0x1f90($t9)
/*  f1570b0:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f1570b4:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f1570b8:	0319001a */ 	div	$zero,$t8,$t9
/*  f1570bc:	8dcd0000 */ 	lw	$t5,0x0($t6)
/*  f1570c0:	00002812 */ 	mflo	$a1
/*  f1570c4:	afab0038 */ 	sw	$t3,0x38($sp)
/*  f1570c8:	17200002 */ 	bnez	$t9,.PB0f1570d4
/*  f1570cc:	00000000 */ 	nop
/*  f1570d0:	0007000d */ 	break	0x7
.PB0f1570d4:
/*  f1570d4:	2401ffff */ 	li	$at,-1
/*  f1570d8:	17210004 */ 	bne	$t9,$at,.PB0f1570ec
/*  f1570dc:	3c018000 */ 	lui	$at,0x8000
/*  f1570e0:	17010002 */ 	bne	$t8,$at,.PB0f1570ec
/*  f1570e4:	00000000 */ 	nop
/*  f1570e8:	0006000d */ 	break	0x6
.PB0f1570ec:
/*  f1570ec:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f1570f0:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f1570f4:	0fc558b8 */ 	jal	func0f154ecc
/*  f1570f8:	01af3021 */ 	addu	$a2,$t5,$t7
/*  f1570fc:	3c0c8008 */ 	lui	$t4,0x8008
/*  f157100:	258c1fa0 */ 	addiu	$t4,$t4,0x1fa0
/*  f157104:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f157108:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f15710c:	8fab0038 */ 	lw	$t3,0x38($sp)
/*  f157110:	00408025 */ 	move	$s0,$v0
.PB0f157114:
/*  f157114:	92290003 */ 	lbu	$t1,0x3($s1)
/*  f157118:	8fb8008c */ 	lw	$t8,0x8c($sp)
/*  f15711c:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f157120:	03090019 */ 	multu	$t8,$t1
/*  f157124:	0000c812 */ 	mflo	$t9
/*  f157128:	00f97021 */ 	addu	$t6,$a3,$t9
/*  f15712c:	010e082a */ 	slt	$at,$t0,$t6
/*  f157130:	542001b0 */ 	bnezl	$at,.PB0f1577f4
/*  f157134:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f157138:	82240001 */ 	lb	$a0,0x1($s1)
/*  f15713c:	8fa300b4 */ 	lw	$v1,0xb4($sp)
/*  f157140:	008a3021 */ 	addu	$a2,$a0,$t2
/*  f157144:	00c3082a */ 	slt	$at,$a2,$v1
/*  f157148:	54200158 */ 	bnezl	$at,.PB0f1576ac
/*  f15714c:	92380002 */ 	lbu	$t8,0x2($s1)
/*  f157150:	922d0002 */ 	lbu	$t5,0x2($s1)
/*  f157154:	3c0f8008 */ 	lui	$t7,0x8008
/*  f157158:	00cd1021 */ 	addu	$v0,$a2,$t5
/*  f15715c:	0162082a */ 	slt	$at,$t3,$v0
/*  f157160:	54200106 */ 	bnezl	$at,.PB0f15757c
/*  f157164:	0166082a */ 	slt	$at,$t3,$a2
/*  f157168:	8def1f98 */ 	lw	$t7,0x1f98($t7)
/*  f15716c:	3c068008 */ 	lui	$a2,0x8008
/*  f157170:	24c61fac */ 	addiu	$a2,$a2,0x1fac
/*  f157174:	11e00050 */ 	beqz	$t7,.PB0f1572b8
/*  f157178:	3c088008 */ 	lui	$t0,0x8008
/*  f15717c:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f157180:	00e9c021 */ 	addu	$t8,$a3,$t1
/*  f157184:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f157188:	032e6821 */ 	addu	$t5,$t9,$t6
/*  f15718c:	25081fb0 */ 	addiu	$t0,$t0,0x1fb0
/*  f157190:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f157194:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*  f157198:	0144c823 */ 	subu	$t9,$t2,$a0
/*  f15719c:	3c01e500 */ 	lui	$at,0xe500
/*  f1571a0:	01e1c025 */ 	or	$t8,$t7,$at
/*  f1571a4:	00197080 */ 	sll	$t6,$t9,0x2
/*  f1571a8:	01cd7821 */ 	addu	$t7,$t6,$t5
/*  f1571ac:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f1571b0:	00197300 */ 	sll	$t6,$t9,0xc
/*  f1571b4:	030e6825 */ 	or	$t5,$t8,$t6
/*  f1571b8:	02001025 */ 	move	$v0,$s0
/*  f1571bc:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f1571c0:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f1571c4:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f1571c8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1571cc:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f1571d0:	03387021 */ 	addu	$t6,$t9,$t8
/*  f1571d4:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f1571d8:	922f0002 */ 	lbu	$t7,0x2($s1)
/*  f1571dc:	31cd0fff */ 	andi	$t5,$t6,0xfff
/*  f1571e0:	822e0001 */ 	lb	$t6,0x1($s1)
/*  f1571e4:	01f90019 */ 	multu	$t7,$t9
/*  f1571e8:	02001825 */ 	move	$v1,$s0
/*  f1571ec:	014e7823 */ 	subu	$t7,$t2,$t6
/*  f1571f0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1571f4:	02002825 */ 	move	$a1,$s0
/*  f1571f8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1571fc:	0000c012 */ 	mflo	$t8
/*  f157200:	01f8c823 */ 	subu	$t9,$t7,$t8
/*  f157204:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f157208:	00197080 */ 	sll	$t6,$t9,0x2
/*  f15720c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f157210:	33190fff */ 	andi	$t9,$t8,0xfff
/*  f157214:	00197300 */ 	sll	$t6,$t9,0xc
/*  f157218:	01ae7825 */ 	or	$t7,$t5,$t6
/*  f15721c:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f157220:	3c18b400 */ 	lui	$t8,0xb400
/*  f157224:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f157228:	92390002 */ 	lbu	$t9,0x2($s1)
/*  f15722c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f157230:	8def1fb4 */ 	lw	$t7,0x1fb4($t7)
/*  f157234:	272dffff */ 	addiu	$t5,$t9,-1
/*  f157238:	000d7140 */ 	sll	$t6,$t5,0x5
/*  f15723c:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f157240:	3c0e8008 */ 	lui	$t6,0x8008
/*  f157244:	8dce1fb8 */ 	lw	$t6,0x1fb8($t6)
/*  f157248:	27190020 */ 	addiu	$t9,$t8,0x20
/*  f15724c:	332dffff */ 	andi	$t5,$t9,0xffff
/*  f157250:	25d80020 */ 	addiu	$t8,$t6,0x20
/*  f157254:	0018cc00 */ 	sll	$t9,$t8,0x10
/*  f157258:	032d7025 */ 	or	$t6,$t9,$t5
/*  f15725c:	ac6e0004 */ 	sw	$t6,0x4($v1)
/*  f157260:	3c0fb300 */ 	lui	$t7,0xb300
/*  f157264:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f157268:	24190400 */ 	li	$t9,0x400
/*  f15726c:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f157270:	3c0e0001 */ 	lui	$t6,0x1
/*  f157274:	0338001a */ 	div	$zero,$t9,$t8
/*  f157278:	17000002 */ 	bnez	$t8,.PB0f157284
/*  f15727c:	00000000 */ 	nop
/*  f157280:	0007000d */ 	break	0x7
.PB0f157284:
/*  f157284:	2401ffff */ 	li	$at,-1
/*  f157288:	17010004 */ 	bne	$t8,$at,.PB0f15729c
/*  f15728c:	3c018000 */ 	lui	$at,0x8000
/*  f157290:	17210002 */ 	bne	$t9,$at,.PB0f15729c
/*  f157294:	00000000 */ 	nop
/*  f157298:	0006000d */ 	break	0x6
.PB0f15729c:
/*  f15729c:	00006812 */ 	mflo	$t5
/*  f1572a0:	01cd7823 */ 	subu	$t7,$t6,$t5
/*  f1572a4:	31f9ffff */ 	andi	$t9,$t7,0xffff
/*  f1572a8:	3c010400 */ 	lui	$at,0x400
/*  f1572ac:	0321c025 */ 	or	$t8,$t9,$at
/*  f1572b0:	1000014f */ 	b	.PB0f1577f0
/*  f1572b4:	acb80004 */ 	sw	$t8,0x4($a1)
.PB0f1572b8:
/*  f1572b8:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f1572bc:	3c068008 */ 	lui	$a2,0x8008
/*  f1572c0:	24c61fac */ 	addiu	$a2,$a2,0x1fac
/*  f1572c4:	012e0019 */ 	multu	$t1,$t6
/*  f1572c8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f1572cc:	3c088008 */ 	lui	$t0,0x8008
/*  f1572d0:	25081fb0 */ 	addiu	$t0,$t0,0x1fb0
/*  f1572d4:	3c01e400 */ 	lui	$at,0xe400
/*  f1572d8:	02001825 */ 	move	$v1,$s0
/*  f1572dc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1572e0:	02002025 */ 	move	$a0,$s0
/*  f1572e4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1572e8:	02002825 */ 	move	$a1,$s0
/*  f1572ec:	00006812 */ 	mflo	$t5
/*  f1572f0:	00ed7821 */ 	addu	$t7,$a3,$t5
/*  f1572f4:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f1572f8:	03387021 */ 	addu	$t6,$t9,$t8
/*  f1572fc:	31cd0fff */ 	andi	$t5,$t6,0xfff
/*  f157300:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f157304:	000d7b00 */ 	sll	$t7,$t5,0xc
/*  f157308:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f15730c:	01e1c825 */ 	or	$t9,$t7,$at
/*  f157310:	030e6821 */ 	addu	$t5,$t8,$t6
/*  f157314:	31af0fff */ 	andi	$t7,$t5,0xfff
/*  f157318:	032fc025 */ 	or	$t8,$t9,$t7
/*  f15731c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f157320:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f157324:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f157328:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15732c:	000e6880 */ 	sll	$t5,$t6,0x2
/*  f157330:	01b97821 */ 	addu	$t7,$t5,$t9
/*  f157334:	822d0001 */ 	lb	$t5,0x1($s1)
/*  f157338:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f15733c:	00187300 */ 	sll	$t6,$t8,0xc
/*  f157340:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f157344:	014dc821 */ 	addu	$t9,$t2,$t5
/*  f157348:	00197880 */ 	sll	$t7,$t9,0x2
/*  f15734c:	01f86821 */ 	addu	$t5,$t7,$t8
/*  f157350:	31b90fff */ 	andi	$t9,$t5,0xfff
/*  f157354:	01d97825 */ 	or	$t7,$t6,$t9
/*  f157358:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f15735c:	3c18b400 */ 	lui	$t8,0xb400
/*  f157360:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f157364:	3c0d8008 */ 	lui	$t5,0x8008
/*  f157368:	8dad1fb4 */ 	lw	$t5,0x1fb4($t5)
/*  f15736c:	3c188008 */ 	lui	$t8,0x8008
/*  f157370:	8f181fb8 */ 	lw	$t8,0x1fb8($t8)
/*  f157374:	25b90020 */ 	addiu	$t9,$t5,0x20
/*  f157378:	00197c00 */ 	sll	$t7,$t9,0x10
/*  f15737c:	270d0020 */ 	addiu	$t5,$t8,0x20
/*  f157380:	31aeffff */ 	andi	$t6,$t5,0xffff
/*  f157384:	01eec825 */ 	or	$t9,$t7,$t6
/*  f157388:	ac990004 */ 	sw	$t9,0x4($a0)
/*  f15738c:	3c18b300 */ 	lui	$t8,0xb300
/*  f157390:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f157394:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f157398:	240f0400 */ 	li	$t7,0x400
/*  f15739c:	01ed001a */ 	div	$zero,$t7,$t5
/*  f1573a0:	00007012 */ 	mflo	$t6
/*  f1573a4:	31d9ffff */ 	andi	$t9,$t6,0xffff
/*  f1573a8:	0019c400 */ 	sll	$t8,$t9,0x10
/*  f1573ac:	15a00002 */ 	bnez	$t5,.PB0f1573b8
/*  f1573b0:	00000000 */ 	nop
/*  f1573b4:	0007000d */ 	break	0x7
.PB0f1573b8:
/*  f1573b8:	2401ffff */ 	li	$at,-1
/*  f1573bc:	15a10004 */ 	bne	$t5,$at,.PB0f1573d0
/*  f1573c0:	3c018000 */ 	lui	$at,0x8000
/*  f1573c4:	15e10002 */ 	bne	$t7,$at,.PB0f1573d0
/*  f1573c8:	00000000 */ 	nop
/*  f1573cc:	0006000d */ 	break	0x6
.PB0f1573d0:
/*  f1573d0:	370f0400 */ 	ori	$t7,$t8,0x400
/*  f1573d4:	acaf0004 */ 	sw	$t7,0x4($a1)
/*  f1573d8:	3c0d8008 */ 	lui	$t5,0x8008
/*  f1573dc:	8dad206c */ 	lw	$t5,0x206c($t5)
/*  f1573e0:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f1573e4:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f1573e8:	51a00102 */ 	beqzl	$t5,.PB0f1577f4
/*  f1573ec:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f1573f0:	8dd90000 */ 	lw	$t9,0x0($t6)
/*  f1573f4:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f1573f8:	0fc553e0 */ 	jal	func0f153b6c
/*  f1573fc:	03382021 */ 	addu	$a0,$t9,$t8
/*  f157400:	3c0d8008 */ 	lui	$t5,0x8008
/*  f157404:	8dad1f90 */ 	lw	$t5,0x1f90($t5)
/*  f157408:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f15740c:	3c058008 */ 	lui	$a1,0x8008
/*  f157410:	8ca52070 */ 	lw	$a1,0x2070($a1)
/*  f157414:	01ed001a */ 	div	$zero,$t7,$t5
/*  f157418:	00001812 */ 	mflo	$v1
/*  f15741c:	3c0c8008 */ 	lui	$t4,0x8008
/*  f157420:	258c1fa0 */ 	addiu	$t4,$t4,0x1fa0
/*  f157424:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f157428:	15a00002 */ 	bnez	$t5,.PB0f157434
/*  f15742c:	00000000 */ 	nop
/*  f157430:	0007000d */ 	break	0x7
.PB0f157434:
/*  f157434:	2401ffff */ 	li	$at,-1
/*  f157438:	15a10004 */ 	bne	$t5,$at,.PB0f15744c
/*  f15743c:	3c018000 */ 	lui	$at,0x8000
/*  f157440:	15e10002 */ 	bne	$t7,$at,.PB0f15744c
/*  f157444:	00000000 */ 	nop
/*  f157448:	0006000d */ 	break	0x6
.PB0f15744c:
/*  f15744c:	00a3082a */ 	slt	$at,$a1,$v1
/*  f157450:	5420002e */ 	bnezl	$at,.PB0f15750c
/*  f157454:	24a2fffd */ 	addiu	$v0,$a1,-3
/*  f157458:	922e0003 */ 	lbu	$t6,0x3($s1)
/*  f15745c:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f157460:	3c04800b */ 	lui	$a0,0x800b
/*  f157464:	00a03825 */ 	move	$a3,$a1
/*  f157468:	01d90019 */ 	multu	$t6,$t9
/*  f15746c:	3c02800b */ 	lui	$v0,0x800b
/*  f157470:	0000c012 */ 	mflo	$t8
/*  f157474:	00787821 */ 	addu	$t7,$v1,$t8
/*  f157478:	01e5082a */ 	slt	$at,$t7,$a1
/*  f15747c:	54200023 */ 	bnezl	$at,.PB0f15750c
/*  f157480:	24a2fffd */ 	addiu	$v0,$a1,-3
/*  f157484:	822d0001 */ 	lb	$t5,0x1($s1)
/*  f157488:	922e0002 */ 	lbu	$t6,0x2($s1)
/*  f15748c:	8c428bf4 */ 	lw	$v0,-0x740c($v0)
/*  f157490:	01aa3021 */ 	addu	$a2,$t5,$t2
/*  f157494:	00cec821 */ 	addu	$t9,$a2,$t6
/*  f157498:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f15749c:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f1574a0:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f1574a4:	8c848c54 */ 	lw	$a0,-0x73ac($a0)
/*  f1574a8:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f1574ac:	0fc3546b */ 	jal	func0f0d4d0c
/*  f1574b0:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f1574b4:	3c01800b */ 	lui	$at,0x800b
/*  f1574b8:	ac228c54 */ 	sw	$v0,-0x73ac($at)
/*  f1574bc:	3c0f8008 */ 	lui	$t7,0x8008
/*  f1574c0:	8def1f90 */ 	lw	$t7,0x1f90($t7)
/*  f1574c4:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f1574c8:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1574cc:	3c058008 */ 	lui	$a1,0x8008
/*  f1574d0:	030f001a */ 	div	$zero,$t8,$t7
/*  f1574d4:	00001812 */ 	mflo	$v1
/*  f1574d8:	8ca52070 */ 	lw	$a1,0x2070($a1)
/*  f1574dc:	258c1fa0 */ 	addiu	$t4,$t4,0x1fa0
/*  f1574e0:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f1574e4:	15e00002 */ 	bnez	$t7,.PB0f1574f0
/*  f1574e8:	00000000 */ 	nop
/*  f1574ec:	0007000d */ 	break	0x7
.PB0f1574f0:
/*  f1574f0:	2401ffff */ 	li	$at,-1
/*  f1574f4:	15e10004 */ 	bne	$t7,$at,.PB0f157508
/*  f1574f8:	3c018000 */ 	lui	$at,0x8000
/*  f1574fc:	17010002 */ 	bne	$t8,$at,.PB0f157508
/*  f157500:	00000000 */ 	nop
/*  f157504:	0006000d */ 	break	0x6
.PB0f157508:
/*  f157508:	24a2fffd */ 	addiu	$v0,$a1,-3
.PB0f15750c:
/*  f15750c:	0043082a */ 	slt	$at,$v0,$v1
/*  f157510:	542000b8 */ 	bnezl	$at,.PB0f1577f4
/*  f157514:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f157518:	922d0003 */ 	lbu	$t5,0x3($s1)
/*  f15751c:	8d8e0000 */ 	lw	$t6,0x0($t4)
/*  f157520:	3c04800b */ 	lui	$a0,0x800b
/*  f157524:	00a03825 */ 	move	$a3,$a1
/*  f157528:	01ae0019 */ 	multu	$t5,$t6
/*  f15752c:	0000c812 */ 	mflo	$t9
/*  f157530:	0079c021 */ 	addu	$t8,$v1,$t9
/*  f157534:	0302082a */ 	slt	$at,$t8,$v0
/*  f157538:	142000ad */ 	bnez	$at,.PB0f1577f0
/*  f15753c:	3c02800b */ 	lui	$v0,0x800b
/*  f157540:	822f0001 */ 	lb	$t7,0x1($s1)
/*  f157544:	922d0002 */ 	lbu	$t5,0x2($s1)
/*  f157548:	8c428bf4 */ 	lw	$v0,-0x740c($v0)
/*  f15754c:	01ea3021 */ 	addu	$a2,$t7,$t2
/*  f157550:	00cd7021 */ 	addu	$t6,$a2,$t5
/*  f157554:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f157558:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f15755c:	8c848c54 */ 	lw	$a0,-0x73ac($a0)
/*  f157560:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f157564:	0fc3546b */ 	jal	func0f0d4d0c
/*  f157568:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f15756c:	3c01800b */ 	lui	$at,0x800b
/*  f157570:	1000009f */ 	b	.PB0f1577f0
/*  f157574:	ac228c54 */ 	sw	$v0,-0x73ac($at)
/*  f157578:	0166082a */ 	slt	$at,$t3,$a2
.PB0f15757c:
/*  f15757c:	5420009d */ 	bnezl	$at,.PB0f1577f4
/*  f157580:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f157584:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f157588:	3c068008 */ 	lui	$a2,0x8008
/*  f15758c:	24c61fac */ 	addiu	$a2,$a2,0x1fac
/*  f157590:	01390019 */ 	multu	$t1,$t9
/*  f157594:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f157598:	3c088008 */ 	lui	$t0,0x8008
/*  f15759c:	25081fb0 */ 	addiu	$t0,$t0,0x1fb0
/*  f1575a0:	3c01e400 */ 	lui	$at,0xe400
/*  f1575a4:	02001025 */ 	move	$v0,$s0
/*  f1575a8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1575ac:	02001825 */ 	move	$v1,$s0
/*  f1575b0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1575b4:	02002025 */ 	move	$a0,$s0
/*  f1575b8:	0000c012 */ 	mflo	$t8
/*  f1575bc:	00f87821 */ 	addu	$t7,$a3,$t8
/*  f1575c0:	000f6880 */ 	sll	$t5,$t7,0x2
/*  f1575c4:	01aec821 */ 	addu	$t9,$t5,$t6
/*  f1575c8:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f1575cc:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f1575d0:	00187b00 */ 	sll	$t7,$t8,0xc
/*  f1575d4:	000b7080 */ 	sll	$t6,$t3,0x2
/*  f1575d8:	01e16825 */ 	or	$t5,$t7,$at
/*  f1575dc:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f1575e0:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f1575e4:	01af7025 */ 	or	$t6,$t5,$t7
/*  f1575e8:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f1575ec:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f1575f0:	8ccd0000 */ 	lw	$t5,0x0($a2)
/*  f1575f4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1575f8:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f1575fc:	030d7821 */ 	addu	$t7,$t8,$t5
/*  f157600:	82380001 */ 	lb	$t8,0x1($s1)
/*  f157604:	31ee0fff */ 	andi	$t6,$t7,0xfff
/*  f157608:	000ecb00 */ 	sll	$t9,$t6,0xc
/*  f15760c:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f157610:	01586821 */ 	addu	$t5,$t2,$t8
/*  f157614:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f157618:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f15761c:	330d0fff */ 	andi	$t5,$t8,0xfff
/*  f157620:	032d7825 */ 	or	$t7,$t9,$t5
/*  f157624:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f157628:	3c0eb400 */ 	lui	$t6,0xb400
/*  f15762c:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f157630:	3c188008 */ 	lui	$t8,0x8008
/*  f157634:	8f181fb4 */ 	lw	$t8,0x1fb4($t8)
/*  f157638:	3c0e8008 */ 	lui	$t6,0x8008
/*  f15763c:	8dce1fb8 */ 	lw	$t6,0x1fb8($t6)
/*  f157640:	270d0020 */ 	addiu	$t5,$t8,0x20
/*  f157644:	000d7c00 */ 	sll	$t7,$t5,0x10
/*  f157648:	25d80020 */ 	addiu	$t8,$t6,0x20
/*  f15764c:	3319ffff */ 	andi	$t9,$t8,0xffff
/*  f157650:	01f96825 */ 	or	$t5,$t7,$t9
/*  f157654:	ac6d0004 */ 	sw	$t5,0x4($v1)
/*  f157658:	240f0400 */ 	li	$t7,0x400
/*  f15765c:	3c0eb300 */ 	lui	$t6,0xb300
/*  f157660:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f157664:	8d980000 */ 	lw	$t8,0x0($t4)
/*  f157668:	01f8001a */ 	div	$zero,$t7,$t8
/*  f15766c:	0000c812 */ 	mflo	$t9
/*  f157670:	332dffff */ 	andi	$t5,$t9,0xffff
/*  f157674:	000d7400 */ 	sll	$t6,$t5,0x10
/*  f157678:	17000002 */ 	bnez	$t8,.PB0f157684
/*  f15767c:	00000000 */ 	nop
/*  f157680:	0007000d */ 	break	0x7
.PB0f157684:
/*  f157684:	2401ffff */ 	li	$at,-1
/*  f157688:	17010004 */ 	bne	$t8,$at,.PB0f15769c
/*  f15768c:	3c018000 */ 	lui	$at,0x8000
/*  f157690:	15e10002 */ 	bne	$t7,$at,.PB0f15769c
/*  f157694:	00000000 */ 	nop
/*  f157698:	0006000d */ 	break	0x6
.PB0f15769c:
/*  f15769c:	35cf0400 */ 	ori	$t7,$t6,0x400
/*  f1576a0:	10000053 */ 	b	.PB0f1577f0
/*  f1576a4:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f1576a8:	92380002 */ 	lbu	$t8,0x2($s1)
.PB0f1576ac:
/*  f1576ac:	00d81021 */ 	addu	$v0,$a2,$t8
/*  f1576b0:	0043082a */ 	slt	$at,$v0,$v1
/*  f1576b4:	5420004f */ 	bnezl	$at,.PB0f1577f4
/*  f1576b8:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f1576bc:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f1576c0:	3c068008 */ 	lui	$a2,0x8008
/*  f1576c4:	24c61fac */ 	addiu	$a2,$a2,0x1fac
/*  f1576c8:	01390019 */ 	multu	$t1,$t9
/*  f1576cc:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f1576d0:	3c088008 */ 	lui	$t0,0x8008
/*  f1576d4:	25081fb0 */ 	addiu	$t0,$t0,0x1fb0
/*  f1576d8:	3c01e400 */ 	lui	$at,0xe400
/*  f1576dc:	02001825 */ 	move	$v1,$s0
/*  f1576e0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1576e4:	02002025 */ 	move	$a0,$s0
/*  f1576e8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1576ec:	02002825 */ 	move	$a1,$s0
/*  f1576f0:	00006812 */ 	mflo	$t5
/*  f1576f4:	00ed7021 */ 	addu	$t6,$a3,$t5
/*  f1576f8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1576fc:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f157700:	332d0fff */ 	andi	$t5,$t9,0xfff
/*  f157704:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f157708:	000d7300 */ 	sll	$t6,$t5,0xc
/*  f15770c:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f157710:	01c17825 */ 	or	$t7,$t6,$at
/*  f157714:	03196821 */ 	addu	$t5,$t8,$t9
/*  f157718:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f15771c:	01eec025 */ 	or	$t8,$t7,$t6
/*  f157720:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f157724:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f157728:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f15772c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f157730:	00196880 */ 	sll	$t5,$t9,0x2
/*  f157734:	01af7021 */ 	addu	$t6,$t5,$t7
/*  f157738:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f15773c:	31d80fff */ 	andi	$t8,$t6,0xfff
/*  f157740:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f157744:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f157748:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f15774c:	01eec021 */ 	addu	$t8,$t7,$t6
/*  f157750:	330d0fff */ 	andi	$t5,$t8,0xfff
/*  f157754:	032d7825 */ 	or	$t7,$t9,$t5
/*  f157758:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f15775c:	3c0eb400 */ 	lui	$t6,0xb400
/*  f157760:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f157764:	8fb800b4 */ 	lw	$t8,0xb4($sp)
/*  f157768:	822d0001 */ 	lb	$t5,0x1($s1)
/*  f15776c:	030ac823 */ 	subu	$t9,$t8,$t2
/*  f157770:	3c188008 */ 	lui	$t8,0x8008
/*  f157774:	8f181fb8 */ 	lw	$t8,0x1fb8($t8)
/*  f157778:	032d7823 */ 	subu	$t7,$t9,$t5
/*  f15777c:	000f7140 */ 	sll	$t6,$t7,0x5
/*  f157780:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f157784:	3c0e8008 */ 	lui	$t6,0x8008
/*  f157788:	8dce1fb4 */ 	lw	$t6,0x1fb4($t6)
/*  f15778c:	272d0020 */ 	addiu	$t5,$t9,0x20
/*  f157790:	31afffff */ 	andi	$t7,$t5,0xffff
/*  f157794:	25d90020 */ 	addiu	$t9,$t6,0x20
/*  f157798:	00196c00 */ 	sll	$t5,$t9,0x10
/*  f15779c:	01af7025 */ 	or	$t6,$t5,$t7
/*  f1577a0:	ac8e0004 */ 	sw	$t6,0x4($a0)
/*  f1577a4:	3c18b300 */ 	lui	$t8,0xb300
/*  f1577a8:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1577ac:	240d0400 */ 	li	$t5,0x400
/*  f1577b0:	8d990000 */ 	lw	$t9,0x0($t4)
/*  f1577b4:	01b9001a */ 	div	$zero,$t5,$t9
/*  f1577b8:	00007812 */ 	mflo	$t7
/*  f1577bc:	31eeffff */ 	andi	$t6,$t7,0xffff
/*  f1577c0:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f1577c4:	17200002 */ 	bnez	$t9,.PB0f1577d0
/*  f1577c8:	00000000 */ 	nop
/*  f1577cc:	0007000d */ 	break	0x7
.PB0f1577d0:
/*  f1577d0:	2401ffff */ 	li	$at,-1
/*  f1577d4:	17210004 */ 	bne	$t9,$at,.PB0f1577e8
/*  f1577d8:	3c018000 */ 	lui	$at,0x8000
/*  f1577dc:	15a10002 */ 	bne	$t5,$at,.PB0f1577e8
/*  f1577e0:	00000000 */ 	nop
/*  f1577e4:	0006000d */ 	break	0x6
.PB0f1577e8:
/*  f1577e8:	370d0400 */ 	ori	$t5,$t8,0x400
/*  f1577ec:	acad0004 */ 	sw	$t5,0x4($a1)
.PB0f1577f0:
/*  f1577f0:	92390003 */ 	lbu	$t9,0x3($s1)
.PB0f1577f4:
/*  f1577f4:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f1577f8:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f1577fc:	02001025 */ 	move	$v0,$s0
/*  f157800:	032f0019 */ 	multu	$t9,$t7
/*  f157804:	00007012 */ 	mflo	$t6
/*  f157808:	030e6821 */ 	addu	$t5,$t8,$t6
/*  f15780c:	ae4d0000 */ 	sw	$t5,0x0($s2)
/*  f157810:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f157814:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f157818:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f15781c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f157820:	03e00008 */ 	jr	$ra
/*  f157824:	27bd0098 */ 	addiu	$sp,$sp,0x98
);
#else
GLOBAL_ASM(
glabel func0f15568c
/*  f15568c:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f155690:	3c0d8008 */ 	lui	$t5,%hi(var8007fad0)
/*  f155694:	3c0f8008 */ 	lui	$t7,%hi(g_TextRotated90)
/*  f155698:	8deffac8 */ 	lw	$t7,%lo(g_TextRotated90)($t7)
/*  f15569c:	25adfad0 */ 	addiu	$t5,$t5,%lo(var8007fad0)
/*  f1556a0:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f1556a4:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f1556a8:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f1556ac:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f1556b0:	00808025 */ 	or	$s0,$a0,$zero
/*  f1556b4:	00e08825 */ 	or	$s1,$a3,$zero
/*  f1556b8:	00a09025 */ 	or	$s2,$a1,$zero
/*  f1556bc:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f1556c0:	afa600a0 */ 	sw	$a2,0xa0($sp)
/*  f1556c4:	11e00003 */ 	beqz	$t7,.L0f1556d4
/*  f1556c8:	afae008c */ 	sw	$t6,0x8c($sp)
/*  f1556cc:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f1556d0:	afb8008c */ 	sw	$t8,0x8c($sp)
.L0f1556d4:
/*  f1556d4:	8fb900a0 */ 	lw	$t9,0xa0($sp)
/*  f1556d8:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f1556dc:	8fb800ac */ 	lw	$t8,0xac($sp)
/*  f1556e0:	8f2e0000 */ 	lw	$t6,0x0($t9)
/*  f1556e4:	8fb900a8 */ 	lw	$t9,0xa8($sp)
/*  f1556e8:	01cf5021 */ 	addu	$t2,$t6,$t7
/*  f1556ec:	8f2e0004 */ 	lw	$t6,0x4($t9)
/*  f1556f0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1556f4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f1556f8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1556fc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f155700:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f155704:	8e2f0004 */ 	lw	$t7,0x4($s1)
/*  f155708:	03197021 */ 	addu	$t6,$t8,$t9
/*  f15570c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f155710:	01d8c821 */ 	addu	$t9,$t6,$t8
/*  f155714:	3c0e8008 */ 	lui	$t6,%hi(var8007fac4)
/*  f155718:	8dcefac4 */ 	lw	$t6,%lo(var8007fac4)($t6)
/*  f15571c:	8f2f0000 */ 	lw	$t7,0x0($t9)
/*  f155720:	8fb9008c */ 	lw	$t9,0x8c($sp)
/*  f155724:	01ee1021 */ 	addu	$v0,$t7,$t6
/*  f155728:	2458ffff */ 	addiu	$t8,$v0,-1
/*  f15572c:	03190019 */ 	multu	$t8,$t9
/*  f155730:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f155734:	00007812 */ 	mflo	$t7
/*  f155738:	01cfc023 */ 	subu	$t8,$t6,$t7
/*  f15573c:	ae580000 */ 	sw	$t8,0x0($s2)
/*  f155740:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*  f155744:	8fae008c */ 	lw	$t6,0x8c($sp)
/*  f155748:	3c188008 */ 	lui	$t8,%hi(g_TextRotated90)
/*  f15574c:	8f18fac8 */ 	lw	$t8,%lo(g_TextRotated90)($t8)
/*  f155750:	032e0019 */ 	multu	$t9,$t6
/*  f155754:	00007812 */ 	mflo	$t7
/*  f155758:	afaf00b8 */ 	sw	$t7,0xb8($sp)
/*  f15575c:	57000016 */ 	bnezl	$t8,.L0f1557b8
/*  f155760:	8fa200b0 */ 	lw	$v0,0xb0($sp)
/*  f155764:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f155768:	5b200221 */ 	blezl	$t9,.L0f155ff0
/*  f15576c:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f155770:	0c002f02 */ 	jal	viGetWidth
/*  f155774:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f155778:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f15577c:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f155780:	004e082a */ 	slt	$at,$v0,$t6
/*  f155784:	5420021a */ 	bnezl	$at,.L0f155ff0
/*  f155788:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f15578c:	0c002f06 */ 	jal	viGetHeight
/*  f155790:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f155794:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f155798:	822f0001 */ 	lb	$t7,0x1($s1)
/*  f15579c:	3c0d8008 */ 	lui	$t5,%hi(var8007fad0)
/*  f1557a0:	25adfad0 */ 	addiu	$t5,$t5,%lo(var8007fad0)
/*  f1557a4:	014fc021 */ 	addu	$t8,$t2,$t7
/*  f1557a8:	0058082a */ 	slt	$at,$v0,$t8
/*  f1557ac:	54200210 */ 	bnezl	$at,.L0f155ff0
/*  f1557b0:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f1557b4:	8fa200b0 */ 	lw	$v0,0xb0($sp)
.L0f1557b8:
/*  f1557b8:	8fb900b8 */ 	lw	$t9,0xb8($sp)
/*  f1557bc:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f1557c0:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f1557c4:	00594021 */ 	addu	$t0,$v0,$t9
/*  f1557c8:	0107082a */ 	slt	$at,$t0,$a3
/*  f1557cc:	14200207 */ 	bnez	$at,.L0f155fec
/*  f1557d0:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f1557d4:	822f0001 */ 	lb	$t7,0x1($s1)
/*  f1557d8:	016e6021 */ 	addu	$t4,$t3,$t6
/*  f1557dc:	01ea3021 */ 	addu	$a2,$t7,$t2
/*  f1557e0:	0186082a */ 	slt	$at,$t4,$a2
/*  f1557e4:	14200201 */ 	bnez	$at,.L0f155fec
/*  f1557e8:	00e2082a */ 	slt	$at,$a3,$v0
/*  f1557ec:	54200200 */ 	bnezl	$at,.L0f155ff0
/*  f1557f0:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f1557f4:	92380002 */ 	lbu	$t8,0x2($s1)
/*  f1557f8:	02001025 */ 	or	$v0,$s0,$zero
/*  f1557fc:	3c0efd50 */ 	lui	$t6,0xfd50
/*  f155800:	00d8c821 */ 	addu	$t9,$a2,$t8
/*  f155804:	032b082a */ 	slt	$at,$t9,$t3
/*  f155808:	142001f8 */ 	bnez	$at,.L0f155fec
/*  f15580c:	3c18e600 */ 	lui	$t8,0xe600
/*  f155810:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f155814:	8e2f0008 */ 	lw	$t7,0x8($s1)
/*  f155818:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15581c:	02001825 */ 	or	$v1,$s0,$zero
/*  f155820:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f155824:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155828:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f15582c:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f155830:	02002025 */ 	or	$a0,$s0,$zero
/*  f155834:	3c19f300 */ 	lui	$t9,0xf300
/*  f155838:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f15583c:	92250002 */ 	lbu	$a1,0x2($s1)
/*  f155840:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155844:	240307ff */ 	addiu	$v1,$zero,0x7ff
/*  f155848:	000570c0 */ 	sll	$t6,$a1,0x3
/*  f15584c:	25c50011 */ 	addiu	$a1,$t6,0x11
/*  f155850:	00057843 */ 	sra	$t7,$a1,0x1
/*  f155854:	25e5ffff */ 	addiu	$a1,$t7,-1
/*  f155858:	28a107ff */ 	slti	$at,$a1,0x7ff
/*  f15585c:	10200003 */ 	beqz	$at,.L0f15586c
/*  f155860:	02001025 */ 	or	$v0,$s0,$zero
/*  f155864:	10000001 */ 	b	.L0f15586c
/*  f155868:	00a01825 */ 	or	$v1,$a1,$zero
.L0f15586c:
/*  f15586c:	30780fff */ 	andi	$t8,$v1,0xfff
/*  f155870:	0018cb00 */ 	sll	$t9,$t8,0xc
/*  f155874:	3c010700 */ 	lui	$at,0x700
/*  f155878:	03217025 */ 	or	$t6,$t9,$at
/*  f15587c:	35cf0800 */ 	ori	$t7,$t6,0x800
/*  f155880:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f155884:	3c18e700 */ 	lui	$t8,0xe700
/*  f155888:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f15588c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f155890:	3c19800a */ 	lui	$t9,%hi(var800a45d0)
/*  f155894:	933945d0 */ 	lbu	$t9,%lo(var800a45d0)($t9)
/*  f155898:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15589c:	3c0f8008 */ 	lui	$t7,%hi(g_ScaleX)
/*  f1558a0:	5320001f */ 	beqzl	$t9,.L0f155920
/*  f1558a4:	92290003 */ 	lbu	$t1,0x3($s1)
/*  f1558a8:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f1558ac:	8deffac0 */ 	lw	$t7,%lo(g_ScaleX)($t7)
/*  f1558b0:	8fb800a0 */ 	lw	$t8,0xa0($sp)
/*  f1558b4:	02002025 */ 	or	$a0,$s0,$zero
/*  f1558b8:	01cf001a */ 	div	$zero,$t6,$t7
/*  f1558bc:	8f190000 */ 	lw	$t9,0x0($t8)
/*  f1558c0:	15e00002 */ 	bnez	$t7,.L0f1558cc
/*  f1558c4:	00000000 */ 	nop
/*  f1558c8:	0007000d */ 	break	0x7
.L0f1558cc:
/*  f1558cc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1558d0:	15e10004 */ 	bne	$t7,$at,.L0f1558e4
/*  f1558d4:	3c018000 */ 	lui	$at,0x8000
/*  f1558d8:	15c10002 */ 	bne	$t6,$at,.L0f1558e4
/*  f1558dc:	00000000 */ 	nop
/*  f1558e0:	0006000d */ 	break	0x6
.L0f1558e4:
/*  f1558e4:	8fae00c0 */ 	lw	$t6,0xc0($sp)
/*  f1558e8:	00002812 */ 	mflo	$a1
/*  f1558ec:	afac0038 */ 	sw	$t4,0x38($sp)
/*  f1558f0:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f1558f4:	afa80040 */ 	sw	$t0,0x40($sp)
/*  f1558f8:	0fc553b3 */ 	jal	func0f154ecc
/*  f1558fc:	032e3021 */ 	addu	$a2,$t9,$t6
/*  f155900:	3c0d8008 */ 	lui	$t5,%hi(var8007fad0)
/*  f155904:	25adfad0 */ 	addiu	$t5,$t5,%lo(var8007fad0)
/*  f155908:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f15590c:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f155910:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f155914:	8fac0038 */ 	lw	$t4,0x38($sp)
/*  f155918:	00408025 */ 	or	$s0,$v0,$zero
/*  f15591c:	92290003 */ 	lbu	$t1,0x3($s1)
.L0f155920:
/*  f155920:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f155924:	8e470000 */ 	lw	$a3,0x0($s2)
/*  f155928:	01e90019 */ 	multu	$t7,$t1
/*  f15592c:	0000c012 */ 	mflo	$t8
/*  f155930:	00f8c821 */ 	addu	$t9,$a3,$t8
/*  f155934:	0119082a */ 	slt	$at,$t0,$t9
/*  f155938:	542001ad */ 	bnezl	$at,.L0f155ff0
/*  f15593c:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f155940:	82240001 */ 	lb	$a0,0x1($s1)
/*  f155944:	008a3021 */ 	addu	$a2,$a0,$t2
/*  f155948:	00cb082a */ 	slt	$at,$a2,$t3
/*  f15594c:	54200158 */ 	bnezl	$at,.L0f155eb0
/*  f155950:	92390002 */ 	lbu	$t9,0x2($s1)
/*  f155954:	922e0002 */ 	lbu	$t6,0x2($s1)
/*  f155958:	3c0f8008 */ 	lui	$t7,%hi(g_TextRotated90)
/*  f15595c:	00ce1021 */ 	addu	$v0,$a2,$t6
/*  f155960:	0182082a */ 	slt	$at,$t4,$v0
/*  f155964:	54200106 */ 	bnezl	$at,.L0f155d80
/*  f155968:	0186082a */ 	slt	$at,$t4,$a2
/*  f15596c:	8deffac8 */ 	lw	$t7,%lo(g_TextRotated90)($t7)
/*  f155970:	3c068008 */ 	lui	$a2,%hi(var8007fadc)
/*  f155974:	24c6fadc */ 	addiu	$a2,$a2,%lo(var8007fadc)
/*  f155978:	11e00050 */ 	beqz	$t7,.L0f155abc
/*  f15597c:	3c088008 */ 	lui	$t0,%hi(var8007fae0)
/*  f155980:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f155984:	00e9c021 */ 	addu	$t8,$a3,$t1
/*  f155988:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f15598c:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f155990:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f155994:	3c01e500 */ 	lui	$at,0xe500
/*  f155998:	2508fae0 */ 	addiu	$t0,$t0,%lo(var8007fae0)
/*  f15599c:	0301c825 */ 	or	$t9,$t8,$at
/*  f1559a0:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f1559a4:	01447023 */ 	subu	$t6,$t2,$a0
/*  f1559a8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1559ac:	01f87021 */ 	addu	$t6,$t7,$t8
/*  f1559b0:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f1559b4:	000fc300 */ 	sll	$t8,$t7,0xc
/*  f1559b8:	03387025 */ 	or	$t6,$t9,$t8
/*  f1559bc:	02001025 */ 	or	$v0,$s0,$zero
/*  f1559c0:	ac4e0000 */ 	sw	$t6,0x0($v0)
/*  f1559c4:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f1559c8:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f1559cc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1559d0:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f1559d4:	03387021 */ 	addu	$t6,$t9,$t8
/*  f1559d8:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f1559dc:	92390002 */ 	lbu	$t9,0x2($s1)
/*  f1559e0:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f1559e4:	02001825 */ 	or	$v1,$s0,$zero
/*  f1559e8:	03380019 */ 	multu	$t9,$t8
/*  f1559ec:	82390001 */ 	lb	$t9,0x1($s1)
/*  f1559f0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f1559f4:	02002825 */ 	or	$a1,$s0,$zero
/*  f1559f8:	0159c023 */ 	subu	$t8,$t2,$t9
/*  f1559fc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155a00:	00007012 */ 	mflo	$t6
/*  f155a04:	030ec823 */ 	subu	$t9,$t8,$t6
/*  f155a08:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f155a0c:	0019c080 */ 	sll	$t8,$t9,0x2
/*  f155a10:	030ec821 */ 	addu	$t9,$t8,$t6
/*  f155a14:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f155a18:	00187300 */ 	sll	$t6,$t8,0xc
/*  f155a1c:	01eec825 */ 	or	$t9,$t7,$t6
/*  f155a20:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f155a24:	3c18b400 */ 	lui	$t8,0xb400
/*  f155a28:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f155a2c:	922f0002 */ 	lbu	$t7,0x2($s1)
/*  f155a30:	3c188008 */ 	lui	$t8,%hi(var8007fae4)
/*  f155a34:	8f18fae4 */ 	lw	$t8,%lo(var8007fae4)($t8)
/*  f155a38:	25eeffff */ 	addiu	$t6,$t7,-1
/*  f155a3c:	000ec940 */ 	sll	$t9,$t6,0x5
/*  f155a40:	03387821 */ 	addu	$t7,$t9,$t8
/*  f155a44:	3c188008 */ 	lui	$t8,%hi(var8007fae8)
/*  f155a48:	8f18fae8 */ 	lw	$t8,%lo(var8007fae8)($t8)
/*  f155a4c:	25ee0020 */ 	addiu	$t6,$t7,0x20
/*  f155a50:	31d9ffff */ 	andi	$t9,$t6,0xffff
/*  f155a54:	270e0020 */ 	addiu	$t6,$t8,0x20
/*  f155a58:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f155a5c:	03197825 */ 	or	$t7,$t8,$t9
/*  f155a60:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f155a64:	3c0eb300 */ 	lui	$t6,0xb300
/*  f155a68:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f155a6c:	24190400 */ 	addiu	$t9,$zero,0x400
/*  f155a70:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f155a74:	3c0e0001 */ 	lui	$t6,0x1
/*  f155a78:	0338001a */ 	div	$zero,$t9,$t8
/*  f155a7c:	17000002 */ 	bnez	$t8,.L0f155a88
/*  f155a80:	00000000 */ 	nop
/*  f155a84:	0007000d */ 	break	0x7
.L0f155a88:
/*  f155a88:	2401ffff */ 	addiu	$at,$zero,-1
/*  f155a8c:	17010004 */ 	bne	$t8,$at,.L0f155aa0
/*  f155a90:	3c018000 */ 	lui	$at,0x8000
/*  f155a94:	17210002 */ 	bne	$t9,$at,.L0f155aa0
/*  f155a98:	00000000 */ 	nop
/*  f155a9c:	0006000d */ 	break	0x6
.L0f155aa0:
/*  f155aa0:	00007812 */ 	mflo	$t7
/*  f155aa4:	01cfc823 */ 	subu	$t9,$t6,$t7
/*  f155aa8:	3338ffff */ 	andi	$t8,$t9,0xffff
/*  f155aac:	3c010400 */ 	lui	$at,0x400
/*  f155ab0:	03017025 */ 	or	$t6,$t8,$at
/*  f155ab4:	1000014d */ 	b	.L0f155fec
/*  f155ab8:	acae0004 */ 	sw	$t6,0x4($a1)
.L0f155abc:
/*  f155abc:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f155ac0:	3c068008 */ 	lui	$a2,%hi(var8007fadc)
/*  f155ac4:	24c6fadc */ 	addiu	$a2,$a2,%lo(var8007fadc)
/*  f155ac8:	012f0019 */ 	multu	$t1,$t7
/*  f155acc:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f155ad0:	3c088008 */ 	lui	$t0,%hi(var8007fae0)
/*  f155ad4:	2508fae0 */ 	addiu	$t0,$t0,%lo(var8007fae0)
/*  f155ad8:	3c01e400 */ 	lui	$at,0xe400
/*  f155adc:	02001825 */ 	or	$v1,$s0,$zero
/*  f155ae0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155ae4:	02002025 */ 	or	$a0,$s0,$zero
/*  f155ae8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155aec:	02002825 */ 	or	$a1,$s0,$zero
/*  f155af0:	0000c812 */ 	mflo	$t9
/*  f155af4:	00f9c021 */ 	addu	$t8,$a3,$t9
/*  f155af8:	00187080 */ 	sll	$t6,$t8,0x2
/*  f155afc:	01cfc821 */ 	addu	$t9,$t6,$t7
/*  f155b00:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f155b04:	00187300 */ 	sll	$t6,$t8,0xc
/*  f155b08:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f155b0c:	01c17825 */ 	or	$t7,$t6,$at
/*  f155b10:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f155b14:	03387021 */ 	addu	$t6,$t9,$t8
/*  f155b18:	31d90fff */ 	andi	$t9,$t6,0xfff
/*  f155b1c:	01f9c025 */ 	or	$t8,$t7,$t9
/*  f155b20:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f155b24:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f155b28:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f155b2c:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155b30:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f155b34:	01f9c021 */ 	addu	$t8,$t7,$t9
/*  f155b38:	82390001 */ 	lb	$t9,0x1($s1)
/*  f155b3c:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f155b40:	000e7b00 */ 	sll	$t7,$t6,0xc
/*  f155b44:	0159c021 */ 	addu	$t8,$t2,$t9
/*  f155b48:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f155b4c:	00187080 */ 	sll	$t6,$t8,0x2
/*  f155b50:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f155b54:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f155b58:	01eec825 */ 	or	$t9,$t7,$t6
/*  f155b5c:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f155b60:	3c18b400 */ 	lui	$t8,0xb400
/*  f155b64:	ac980000 */ 	sw	$t8,0x0($a0)
/*  f155b68:	3c0f8008 */ 	lui	$t7,%hi(var8007fae4)
/*  f155b6c:	8deffae4 */ 	lw	$t7,%lo(var8007fae4)($t7)
/*  f155b70:	25f90020 */ 	addiu	$t9,$t7,0x20
/*  f155b74:	3c0f8008 */ 	lui	$t7,%hi(var8007fae8)
/*  f155b78:	8deffae8 */ 	lw	$t7,%lo(var8007fae8)($t7)
/*  f155b7c:	0019c400 */ 	sll	$t8,$t9,0x10
/*  f155b80:	25ee0020 */ 	addiu	$t6,$t7,0x20
/*  f155b84:	31d9ffff */ 	andi	$t9,$t6,0xffff
/*  f155b88:	03197825 */ 	or	$t7,$t8,$t9
/*  f155b8c:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f155b90:	3c0eb300 */ 	lui	$t6,0xb300
/*  f155b94:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f155b98:	24190400 */ 	addiu	$t9,$zero,0x400
/*  f155b9c:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f155ba0:	0338001a */ 	div	$zero,$t9,$t8
/*  f155ba4:	00007812 */ 	mflo	$t7
/*  f155ba8:	31eeffff */ 	andi	$t6,$t7,0xffff
/*  f155bac:	17000002 */ 	bnez	$t8,.L0f155bb8
/*  f155bb0:	00000000 */ 	nop
/*  f155bb4:	0007000d */ 	break	0x7
.L0f155bb8:
/*  f155bb8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f155bbc:	17010004 */ 	bne	$t8,$at,.L0f155bd0
/*  f155bc0:	3c018000 */ 	lui	$at,0x8000
/*  f155bc4:	17210002 */ 	bne	$t9,$at,.L0f155bd0
/*  f155bc8:	00000000 */ 	nop
/*  f155bcc:	0006000d */ 	break	0x6
.L0f155bd0:
/*  f155bd0:	000ecc00 */ 	sll	$t9,$t6,0x10
/*  f155bd4:	37380400 */ 	ori	$t8,$t9,0x400
/*  f155bd8:	acb80004 */ 	sw	$t8,0x4($a1)
/*  f155bdc:	3c0f8008 */ 	lui	$t7,%hi(var8007fb9c)
/*  f155be0:	8deffb9c */ 	lw	$t7,%lo(var8007fb9c)($t7)
/*  f155be4:	8fb800c0 */ 	lw	$t8,0xc0($sp)
/*  f155be8:	8fae00a0 */ 	lw	$t6,0xa0($sp)
/*  f155bec:	51e00100 */ 	beqzl	$t7,.L0f155ff0
/*  f155bf0:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f155bf4:	8dd90000 */ 	lw	$t9,0x0($t6)
/*  f155bf8:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f155bfc:	0fc54edb */ 	jal	func0f153b6c
/*  f155c00:	03382021 */ 	addu	$a0,$t9,$t8
/*  f155c04:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f155c08:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f155c0c:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f155c10:	3c058008 */ 	lui	$a1,%hi(var8007fba0)
/*  f155c14:	8ca5fba0 */ 	lw	$a1,%lo(var8007fba0)($a1)
/*  f155c18:	01ee001a */ 	div	$zero,$t7,$t6
/*  f155c1c:	00001812 */ 	mflo	$v1
/*  f155c20:	3c0d8008 */ 	lui	$t5,%hi(var8007fad0)
/*  f155c24:	25adfad0 */ 	addiu	$t5,$t5,%lo(var8007fad0)
/*  f155c28:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f155c2c:	15c00002 */ 	bnez	$t6,.L0f155c38
/*  f155c30:	00000000 */ 	nop
/*  f155c34:	0007000d */ 	break	0x7
.L0f155c38:
/*  f155c38:	2401ffff */ 	addiu	$at,$zero,-1
/*  f155c3c:	15c10004 */ 	bne	$t6,$at,.L0f155c50
/*  f155c40:	3c018000 */ 	lui	$at,0x8000
/*  f155c44:	15e10002 */ 	bne	$t7,$at,.L0f155c50
/*  f155c48:	00000000 */ 	nop
/*  f155c4c:	0006000d */ 	break	0x6
.L0f155c50:
/*  f155c50:	00a3082a */ 	slt	$at,$a1,$v1
/*  f155c54:	5420002e */ 	bnezl	$at,.L0f155d10
/*  f155c58:	24a2fffd */ 	addiu	$v0,$a1,-3
/*  f155c5c:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f155c60:	8db80000 */ 	lw	$t8,0x0($t5)
/*  f155c64:	3c04800a */ 	lui	$a0,%hi(var800a4634)
/*  f155c68:	00a03825 */ 	or	$a3,$a1,$zero
/*  f155c6c:	03380019 */ 	multu	$t9,$t8
/*  f155c70:	3c02800a */ 	lui	$v0,%hi(var800a45d0+0x4)
/*  f155c74:	00007812 */ 	mflo	$t7
/*  f155c78:	006f7021 */ 	addu	$t6,$v1,$t7
/*  f155c7c:	01c5082a */ 	slt	$at,$t6,$a1
/*  f155c80:	54200023 */ 	bnezl	$at,.L0f155d10
/*  f155c84:	24a2fffd */ 	addiu	$v0,$a1,-3
/*  f155c88:	82390001 */ 	lb	$t9,0x1($s1)
/*  f155c8c:	92380002 */ 	lbu	$t8,0x2($s1)
/*  f155c90:	8c4245d4 */ 	lw	$v0,%lo(var800a45d0+0x4)($v0)
/*  f155c94:	032a3021 */ 	addu	$a2,$t9,$t2
/*  f155c98:	00d87821 */ 	addu	$t7,$a2,$t8
/*  f155c9c:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f155ca0:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f155ca4:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f155ca8:	8c844634 */ 	lw	$a0,%lo(var800a4634)($a0)
/*  f155cac:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f155cb0:	0fc35343 */ 	jal	func0f0d4d0c
/*  f155cb4:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f155cb8:	3c01800a */ 	lui	$at,%hi(var800a4634)
/*  f155cbc:	ac224634 */ 	sw	$v0,%lo(var800a4634)($at)
/*  f155cc0:	3c198008 */ 	lui	$t9,%hi(g_ScaleX)
/*  f155cc4:	8f39fac0 */ 	lw	$t9,%lo(g_ScaleX)($t9)
/*  f155cc8:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f155ccc:	3c0d8008 */ 	lui	$t5,%hi(var8007fad0)
/*  f155cd0:	3c058008 */ 	lui	$a1,%hi(var8007fba0)
/*  f155cd4:	01d9001a */ 	div	$zero,$t6,$t9
/*  f155cd8:	00001812 */ 	mflo	$v1
/*  f155cdc:	8ca5fba0 */ 	lw	$a1,%lo(var8007fba0)($a1)
/*  f155ce0:	25adfad0 */ 	addiu	$t5,$t5,%lo(var8007fad0)
/*  f155ce4:	8faa0090 */ 	lw	$t2,0x90($sp)
/*  f155ce8:	17200002 */ 	bnez	$t9,.L0f155cf4
/*  f155cec:	00000000 */ 	nop
/*  f155cf0:	0007000d */ 	break	0x7
.L0f155cf4:
/*  f155cf4:	2401ffff */ 	addiu	$at,$zero,-1
/*  f155cf8:	17210004 */ 	bne	$t9,$at,.L0f155d0c
/*  f155cfc:	3c018000 */ 	lui	$at,0x8000
/*  f155d00:	15c10002 */ 	bne	$t6,$at,.L0f155d0c
/*  f155d04:	00000000 */ 	nop
/*  f155d08:	0006000d */ 	break	0x6
.L0f155d0c:
/*  f155d0c:	24a2fffd */ 	addiu	$v0,$a1,-3
.L0f155d10:
/*  f155d10:	0043082a */ 	slt	$at,$v0,$v1
/*  f155d14:	542000b6 */ 	bnezl	$at,.L0f155ff0
/*  f155d18:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f155d1c:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f155d20:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f155d24:	3c04800a */ 	lui	$a0,%hi(var800a4634)
/*  f155d28:	00a03825 */ 	or	$a3,$a1,$zero
/*  f155d2c:	030f0019 */ 	multu	$t8,$t7
/*  f155d30:	00007012 */ 	mflo	$t6
/*  f155d34:	006ec821 */ 	addu	$t9,$v1,$t6
/*  f155d38:	0322082a */ 	slt	$at,$t9,$v0
/*  f155d3c:	142000ab */ 	bnez	$at,.L0f155fec
/*  f155d40:	3c02800a */ 	lui	$v0,%hi(var800a45d0+0x4)
/*  f155d44:	82380001 */ 	lb	$t8,0x1($s1)
/*  f155d48:	922f0002 */ 	lbu	$t7,0x2($s1)
/*  f155d4c:	8c4245d4 */ 	lw	$v0,%lo(var800a45d0+0x4)($v0)
/*  f155d50:	030a3021 */ 	addu	$a2,$t8,$t2
/*  f155d54:	00cf7021 */ 	addu	$t6,$a2,$t7
/*  f155d58:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f155d5c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f155d60:	8c844634 */ 	lw	$a0,%lo(var800a4634)($a0)
/*  f155d64:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f155d68:	0fc35343 */ 	jal	func0f0d4d0c
/*  f155d6c:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f155d70:	3c01800a */ 	lui	$at,%hi(var800a4634)
/*  f155d74:	1000009d */ 	b	.L0f155fec
/*  f155d78:	ac224634 */ 	sw	$v0,%lo(var800a4634)($at)
/*  f155d7c:	0186082a */ 	slt	$at,$t4,$a2
.L0f155d80:
/*  f155d80:	5420009b */ 	bnezl	$at,.L0f155ff0
/*  f155d84:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f155d88:	8db90000 */ 	lw	$t9,0x0($t5)
/*  f155d8c:	3c068008 */ 	lui	$a2,%hi(var8007fadc)
/*  f155d90:	24c6fadc */ 	addiu	$a2,$a2,%lo(var8007fadc)
/*  f155d94:	01390019 */ 	multu	$t1,$t9
/*  f155d98:	8cd90000 */ 	lw	$t9,0x0($a2)
/*  f155d9c:	3c088008 */ 	lui	$t0,%hi(var8007fae0)
/*  f155da0:	2508fae0 */ 	addiu	$t0,$t0,%lo(var8007fae0)
/*  f155da4:	3c01e400 */ 	lui	$at,0xe400
/*  f155da8:	02001025 */ 	or	$v0,$s0,$zero
/*  f155dac:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155db0:	02001825 */ 	or	$v1,$s0,$zero
/*  f155db4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155db8:	02002025 */ 	or	$a0,$s0,$zero
/*  f155dbc:	0000c012 */ 	mflo	$t8
/*  f155dc0:	00f87821 */ 	addu	$t7,$a3,$t8
/*  f155dc4:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f155dc8:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f155dcc:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f155dd0:	000f7300 */ 	sll	$t6,$t7,0xc
/*  f155dd4:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f155dd8:	01c1c825 */ 	or	$t9,$t6,$at
/*  f155ddc:	000cc080 */ 	sll	$t8,$t4,0x2
/*  f155de0:	030f7021 */ 	addu	$t6,$t8,$t7
/*  f155de4:	31d80fff */ 	andi	$t8,$t6,0xfff
/*  f155de8:	03387825 */ 	or	$t7,$t9,$t8
/*  f155dec:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f155df0:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f155df4:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f155df8:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155dfc:	000ec880 */ 	sll	$t9,$t6,0x2
/*  f155e00:	03387821 */ 	addu	$t7,$t9,$t8
/*  f155e04:	82380001 */ 	lb	$t8,0x1($s1)
/*  f155e08:	31ee0fff */ 	andi	$t6,$t7,0xfff
/*  f155e0c:	000ecb00 */ 	sll	$t9,$t6,0xc
/*  f155e10:	01587821 */ 	addu	$t7,$t2,$t8
/*  f155e14:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f155e18:	000f7080 */ 	sll	$t6,$t7,0x2
/*  f155e1c:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f155e20:	31ee0fff */ 	andi	$t6,$t7,0xfff
/*  f155e24:	032ec025 */ 	or	$t8,$t9,$t6
/*  f155e28:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f155e2c:	3c0fb400 */ 	lui	$t7,0xb400
/*  f155e30:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f155e34:	3c198008 */ 	lui	$t9,%hi(var8007fae4)
/*  f155e38:	8f39fae4 */ 	lw	$t9,%lo(var8007fae4)($t9)
/*  f155e3c:	27380020 */ 	addiu	$t8,$t9,0x20
/*  f155e40:	3c198008 */ 	lui	$t9,%hi(var8007fae8)
/*  f155e44:	8f39fae8 */ 	lw	$t9,%lo(var8007fae8)($t9)
/*  f155e48:	00187c00 */ 	sll	$t7,$t8,0x10
/*  f155e4c:	272e0020 */ 	addiu	$t6,$t9,0x20
/*  f155e50:	31d8ffff */ 	andi	$t8,$t6,0xffff
/*  f155e54:	01f8c825 */ 	or	$t9,$t7,$t8
/*  f155e58:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f155e5c:	3c0eb300 */ 	lui	$t6,0xb300
/*  f155e60:	ac8e0000 */ 	sw	$t6,0x0($a0)
/*  f155e64:	24180400 */ 	addiu	$t8,$zero,0x400
/*  f155e68:	8daf0000 */ 	lw	$t7,0x0($t5)
/*  f155e6c:	030f001a */ 	div	$zero,$t8,$t7
/*  f155e70:	0000c812 */ 	mflo	$t9
/*  f155e74:	332effff */ 	andi	$t6,$t9,0xffff
/*  f155e78:	15e00002 */ 	bnez	$t7,.L0f155e84
/*  f155e7c:	00000000 */ 	nop
/*  f155e80:	0007000d */ 	break	0x7
.L0f155e84:
/*  f155e84:	2401ffff */ 	addiu	$at,$zero,-1
/*  f155e88:	15e10004 */ 	bne	$t7,$at,.L0f155e9c
/*  f155e8c:	3c018000 */ 	lui	$at,0x8000
/*  f155e90:	17010002 */ 	bne	$t8,$at,.L0f155e9c
/*  f155e94:	00000000 */ 	nop
/*  f155e98:	0006000d */ 	break	0x6
.L0f155e9c:
/*  f155e9c:	000ec400 */ 	sll	$t8,$t6,0x10
/*  f155ea0:	370f0400 */ 	ori	$t7,$t8,0x400
/*  f155ea4:	10000051 */ 	b	.L0f155fec
/*  f155ea8:	ac8f0004 */ 	sw	$t7,0x4($a0)
/*  f155eac:	92390002 */ 	lbu	$t9,0x2($s1)
.L0f155eb0:
/*  f155eb0:	00d91021 */ 	addu	$v0,$a2,$t9
/*  f155eb4:	004b082a */ 	slt	$at,$v0,$t3
/*  f155eb8:	5420004d */ 	bnezl	$at,.L0f155ff0
/*  f155ebc:	92380003 */ 	lbu	$t8,0x3($s1)
/*  f155ec0:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f155ec4:	3c068008 */ 	lui	$a2,%hi(var8007fadc)
/*  f155ec8:	24c6fadc */ 	addiu	$a2,$a2,%lo(var8007fadc)
/*  f155ecc:	012e0019 */ 	multu	$t1,$t6
/*  f155ed0:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f155ed4:	3c088008 */ 	lui	$t0,%hi(var8007fae0)
/*  f155ed8:	2508fae0 */ 	addiu	$t0,$t0,%lo(var8007fae0)
/*  f155edc:	3c01e400 */ 	lui	$at,0xe400
/*  f155ee0:	02001825 */ 	or	$v1,$s0,$zero
/*  f155ee4:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155ee8:	02002025 */ 	or	$a0,$s0,$zero
/*  f155eec:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155ef0:	02002825 */ 	or	$a1,$s0,$zero
/*  f155ef4:	0000c012 */ 	mflo	$t8
/*  f155ef8:	00f87821 */ 	addu	$t7,$a3,$t8
/*  f155efc:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f155f00:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f155f04:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f155f08:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f155f0c:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f155f10:	03217025 */ 	or	$t6,$t9,$at
/*  f155f14:	0002c080 */ 	sll	$t8,$v0,0x2
/*  f155f18:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f155f1c:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f155f20:	01d87825 */ 	or	$t7,$t6,$t8
/*  f155f24:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f155f28:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f155f2c:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f155f30:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f155f34:	00197080 */ 	sll	$t6,$t9,0x2
/*  f155f38:	01d87821 */ 	addu	$t7,$t6,$t8
/*  f155f3c:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f155f40:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f155f44:	00197300 */ 	sll	$t6,$t9,0xc
/*  f155f48:	000bc080 */ 	sll	$t8,$t3,0x2
/*  f155f4c:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f155f50:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f155f54:	01d87825 */ 	or	$t7,$t6,$t8
/*  f155f58:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f155f5c:	3c19b400 */ 	lui	$t9,0xb400
/*  f155f60:	ac990000 */ 	sw	$t9,0x0($a0)
/*  f155f64:	82380001 */ 	lb	$t8,0x1($s1)
/*  f155f68:	016a7023 */ 	subu	$t6,$t3,$t2
/*  f155f6c:	01d87823 */ 	subu	$t7,$t6,$t8
/*  f155f70:	3c0e8008 */ 	lui	$t6,%hi(var8007fae8)
/*  f155f74:	8dcefae8 */ 	lw	$t6,%lo(var8007fae8)($t6)
/*  f155f78:	000fc940 */ 	sll	$t9,$t7,0x5
/*  f155f7c:	032ec021 */ 	addu	$t8,$t9,$t6
/*  f155f80:	3c0e8008 */ 	lui	$t6,%hi(var8007fae4)
/*  f155f84:	8dcefae4 */ 	lw	$t6,%lo(var8007fae4)($t6)
/*  f155f88:	270f0020 */ 	addiu	$t7,$t8,0x20
/*  f155f8c:	31f9ffff */ 	andi	$t9,$t7,0xffff
/*  f155f90:	25cf0020 */ 	addiu	$t7,$t6,0x20
/*  f155f94:	000f7400 */ 	sll	$t6,$t7,0x10
/*  f155f98:	01d9c025 */ 	or	$t8,$t6,$t9
/*  f155f9c:	ac980004 */ 	sw	$t8,0x4($a0)
/*  f155fa0:	3c0fb300 */ 	lui	$t7,0xb300
/*  f155fa4:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f155fa8:	24190400 */ 	addiu	$t9,$zero,0x400
/*  f155fac:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f155fb0:	032e001a */ 	div	$zero,$t9,$t6
/*  f155fb4:	0000c012 */ 	mflo	$t8
/*  f155fb8:	330fffff */ 	andi	$t7,$t8,0xffff
/*  f155fbc:	15c00002 */ 	bnez	$t6,.L0f155fc8
/*  f155fc0:	00000000 */ 	nop
/*  f155fc4:	0007000d */ 	break	0x7
.L0f155fc8:
/*  f155fc8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f155fcc:	15c10004 */ 	bne	$t6,$at,.L0f155fe0
/*  f155fd0:	3c018000 */ 	lui	$at,0x8000
/*  f155fd4:	17210002 */ 	bne	$t9,$at,.L0f155fe0
/*  f155fd8:	00000000 */ 	nop
/*  f155fdc:	0006000d */ 	break	0x6
.L0f155fe0:
/*  f155fe0:	000fcc00 */ 	sll	$t9,$t7,0x10
/*  f155fe4:	372e0400 */ 	ori	$t6,$t9,0x400
/*  f155fe8:	acae0004 */ 	sw	$t6,0x4($a1)
.L0f155fec:
/*  f155fec:	92380003 */ 	lbu	$t8,0x3($s1)
.L0f155ff0:
/*  f155ff0:	8faf008c */ 	lw	$t7,0x8c($sp)
/*  f155ff4:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f155ff8:	02001025 */ 	or	$v0,$s0,$zero
/*  f155ffc:	030f0019 */ 	multu	$t8,$t7
/*  f156000:	0000c812 */ 	mflo	$t9
/*  f156004:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f156008:	ae580000 */ 	sw	$t8,0x0($s2)
/*  f15600c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f156010:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f156014:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f156018:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f15601c:	03e00008 */ 	jr	$ra
/*  f156020:	27bd0098 */ 	addiu	$sp,$sp,0x98
);
#endif

void func0f156024(s32 arg0)
{
	var8007fbd8 = arg0;
}

void func0f156030(u32 colour)
{
	var800a463c = colour;
}

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel textRenderProjected
/*  f156218:	27bdff50 */ 	addiu	$sp,$sp,-176
/*  f15621c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f156220:	8def0100 */ 	lw	$t7,0x100($t7)
/*  f156224:	3c0e8008 */ 	lui	$t6,0x8008
/*  f156228:	8dce0108 */ 	lw	$t6,0x108($t6)
/*  f15622c:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f156230:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f156234:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f156238:	00c08825 */ 	move	$s1,$a2
/*  f15623c:	00a09025 */ 	move	$s2,$a1
/*  f156240:	00809825 */ 	move	$s3,$a0
/*  f156244:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f156248:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f15624c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f156250:	afa700bc */ 	sw	$a3,0xbc($sp)
/*  f156254:	11e0000a */ 	beqz	$t7,.JF0f156280
/*  f156258:	afae00a0 */ 	sw	$t6,0xa0($sp)
/*  f15625c:	3c198008 */ 	lui	$t9,0x8008
/*  f156260:	8f3900f4 */ 	lw	$t9,0xf4($t9)
/*  f156264:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f156268:	240a0001 */ 	li	$t2,0x1
/*  f15626c:	03190019 */ 	multu	$t8,$t9
/*  f156270:	00004812 */ 	mflo	$t1
/*  f156274:	acc90000 */ 	sw	$t1,0x0($a2)
/*  f156278:	10000008 */ 	b	.JF0f15629c
/*  f15627c:	afaa00a0 */ 	sw	$t2,0xa0($sp)
.JF0f156280:
/*  f156280:	3c0c8008 */ 	lui	$t4,0x8008
/*  f156284:	8d8c00f4 */ 	lw	$t4,0xf4($t4)
/*  f156288:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f15628c:	016c0019 */ 	multu	$t3,$t4
/*  f156290:	00006812 */ 	mflo	$t5
/*  f156294:	ae4d0000 */ 	sw	$t5,0x0($s2)
/*  f156298:	00000000 */ 	nop
.JF0f15629c:
/*  f15629c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1562a0:	8dce022c */ 	lw	$t6,0x22c($t6)
/*  f1562a4:	11c000d8 */ 	beqz	$t6,.JF0f156608
/*  f1562a8:	3c014220 */ 	lui	$at,0x4220
/*  f1562ac:	44816000 */ 	mtc1	$at,$f12
/*  f1562b0:	0fc01ae2 */ 	jal	func0f006b08
/*  f1562b4:	00000000 */ 	nop
/*  f1562b8:	8e4f0000 */ 	lw	$t7,0x0($s2)
/*  f1562bc:	3c188008 */ 	lui	$t8,0x8008
/*  f1562c0:	8f1800f4 */ 	lw	$t8,0xf4($t8)
/*  f1562c4:	3c02800a */ 	lui	$v0,0x800a
/*  f1562c8:	24424f98 */ 	addiu	$v0,$v0,0x4f98
/*  f1562cc:	01f8001a */ 	div	$zero,$t7,$t8
/*  f1562d0:	0000c812 */ 	mflo	$t9
/*  f1562d4:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1562d8:	8d8c0100 */ 	lw	$t4,0x100($t4)
/*  f1562dc:	afb90094 */ 	sw	$t9,0x94($sp)
/*  f1562e0:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f1562e4:	904a0018 */ 	lbu	$t2,0x18($v0)
/*  f1562e8:	904b0000 */ 	lbu	$t3,0x0($v0)
/*  f1562ec:	3c10800a */ 	lui	$s0,0x800a
/*  f1562f0:	17000002 */ 	bnez	$t8,.JF0f1562fc
/*  f1562f4:	00000000 */ 	nop
/*  f1562f8:	0007000d */ 	break	0x7
.JF0f1562fc:
/*  f1562fc:	2401ffff */ 	li	$at,-1
/*  f156300:	17010004 */ 	bne	$t8,$at,.JF0f156314
/*  f156304:	3c018000 */ 	lui	$at,0x8000
/*  f156308:	15e10002 */ 	bne	$t7,$at,.JF0f156314
/*  f15630c:	00000000 */ 	nop
/*  f156310:	0006000d */ 	break	0x6
.JF0f156314:
/*  f156314:	8e105014 */ 	lw	$s0,0x5014($s0)
/*  f156318:	afa90090 */ 	sw	$t1,0x90($sp)
/*  f15631c:	afaa008c */ 	sw	$t2,0x8c($sp)
/*  f156320:	15800003 */ 	bnez	$t4,.JF0f156330
/*  f156324:	afab0088 */ 	sw	$t3,0x88($sp)
/*  f156328:	252effff */ 	addiu	$t6,$t1,-1
/*  f15632c:	afae0090 */ 	sw	$t6,0x90($sp)
.JF0f156330:
/*  f156330:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f156334:	3c058008 */ 	lui	$a1,0x8008
/*  f156338:	24a50230 */ 	addiu	$a1,$a1,0x230
/*  f15633c:	0c0036b4 */ 	jal	mainOverrideVariable
/*  f156340:	2484806c */ 	addiu	$a0,$a0,-32660
/*  f156344:	3c028008 */ 	lui	$v0,0x8008
/*  f156348:	8c420230 */ 	lw	$v0,0x230($v0)
/*  f15634c:	3c0d8008 */ 	lui	$t5,0x8008
/*  f156350:	02602025 */ 	move	$a0,$s3
/*  f156354:	10400002 */ 	beqz	$v0,.JF0f156360
/*  f156358:	27a50094 */ 	addiu	$a1,$sp,0x94
/*  f15635c:	00408025 */ 	move	$s0,$v0
.JF0f156360:
/*  f156360:	3c02800a */ 	lui	$v0,0x800a
/*  f156364:	24424f98 */ 	addiu	$v0,$v0,0x4f98
/*  f156368:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f15636c:	90590018 */ 	lbu	$t9,0x18($v0)
/*  f156370:	2401fffb */ 	li	$at,-5
/*  f156374:	01e1c024 */ 	and	$t8,$t7,$at
/*  f156378:	13200006 */ 	beqz	$t9,.JF0f156394
/*  f15637c:	a0580000 */ 	sb	$t8,0x0($v0)
/*  f156380:	330900ff */ 	andi	$t1,$t8,0xff
/*  f156384:	2401fffe */ 	li	$at,-2
/*  f156388:	01215024 */ 	and	$t2,$t1,$at
/*  f15638c:	10000003 */ 	b	.JF0f15639c
/*  f156390:	a04a0000 */ 	sb	$t2,0x0($v0)
.JF0f156394:
/*  f156394:	240b0002 */ 	li	$t3,0x2
/*  f156398:	a04b0018 */ 	sb	$t3,0x18($v0)
.JF0f15639c:
/*  f15639c:	3c018008 */ 	lui	$at,0x8008
/*  f1563a0:	ac20022c */ 	sw	$zero,0x22c($at)
/*  f1563a4:	8e4c0000 */ 	lw	$t4,0x0($s2)
/*  f1563a8:	8dad00f4 */ 	lw	$t5,0xf4($t5)
/*  f1563ac:	8fb400d8 */ 	lw	$s4,0xd8($sp)
/*  f1563b0:	8fa900c0 */ 	lw	$t1,0xc0($sp)
/*  f1563b4:	018d001a */ 	div	$zero,$t4,$t5
/*  f1563b8:	00007012 */ 	mflo	$t6
/*  f1563bc:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f1563c0:	afaf0094 */ 	sw	$t7,0x94($sp)
/*  f1563c4:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f1563c8:	15a00002 */ 	bnez	$t5,.JF0f1563d4
/*  f1563cc:	00000000 */ 	nop
/*  f1563d0:	0007000d */ 	break	0x7
.JF0f1563d4:
/*  f1563d4:	2401ffff */ 	li	$at,-1
/*  f1563d8:	15a10004 */ 	bne	$t5,$at,.JF0f1563ec
/*  f1563dc:	3c018000 */ 	lui	$at,0x8000
/*  f1563e0:	15810002 */ 	bne	$t4,$at,.JF0f1563ec
/*  f1563e4:	00000000 */ 	nop
/*  f1563e8:	0006000d */ 	break	0x6
.JF0f1563ec:
/*  f1563ec:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*  f1563f0:	8fad00d4 */ 	lw	$t5,0xd4($sp)
/*  f1563f4:	8faa00c4 */ 	lw	$t2,0xc4($sp)
/*  f1563f8:	8fab00cc */ 	lw	$t3,0xcc($sp)
/*  f1563fc:	2719ffff */ 	addiu	$t9,$t8,-1
/*  f156400:	afb90090 */ 	sw	$t9,0x90($sp)
/*  f156404:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f156408:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f15640c:	8fa700bc */ 	lw	$a3,0xbc($sp)
/*  f156410:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f156414:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f156418:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f15641c:	afad0024 */ 	sw	$t5,0x24($sp)
/*  f156420:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f156424:	0fc55886 */ 	jal	textRenderProjected
/*  f156428:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f15642c:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f156430:	3c0f8008 */ 	lui	$t7,0x8008
/*  f156434:	8def00f4 */ 	lw	$t7,0xf4($t7)
/*  f156438:	8fab00c0 */ 	lw	$t3,0xc0($sp)
/*  f15643c:	8fac00c4 */ 	lw	$t4,0xc4($sp)
/*  f156440:	01cf001a */ 	div	$zero,$t6,$t7
/*  f156444:	0000c012 */ 	mflo	$t8
/*  f156448:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f15644c:	afb90094 */ 	sw	$t9,0x94($sp)
/*  f156450:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f156454:	8fad00cc */ 	lw	$t5,0xcc($sp)
/*  f156458:	27b30094 */ 	addiu	$s3,$sp,0x94
/*  f15645c:	15e00002 */ 	bnez	$t7,.JF0f156468
/*  f156460:	00000000 */ 	nop
/*  f156464:	0007000d */ 	break	0x7
.JF0f156468:
/*  f156468:	2401ffff */ 	li	$at,-1
/*  f15646c:	15e10004 */ 	bne	$t7,$at,.JF0f156480
/*  f156470:	3c018000 */ 	lui	$at,0x8000
/*  f156474:	15c10002 */ 	bne	$t6,$at,.JF0f156480
/*  f156478:	00000000 */ 	nop
/*  f15647c:	0006000d */ 	break	0x6
.JF0f156480:
/*  f156480:	8fae00d0 */ 	lw	$t6,0xd0($sp)
/*  f156484:	8faf00d4 */ 	lw	$t7,0xd4($sp)
/*  f156488:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f15648c:	afaa0090 */ 	sw	$t2,0x90($sp)
/*  f156490:	02602825 */ 	move	$a1,$s3
/*  f156494:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f156498:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f15649c:	00402025 */ 	move	$a0,$v0
/*  f1564a0:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f1564a4:	8fa700bc */ 	lw	$a3,0xbc($sp)
/*  f1564a8:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f1564ac:	afac0014 */ 	sw	$t4,0x14($sp)
/*  f1564b0:	afad001c */ 	sw	$t5,0x1c($sp)
/*  f1564b4:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f1564b8:	0fc55886 */ 	jal	textRenderProjected
/*  f1564bc:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f1564c0:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f1564c4:	3c198008 */ 	lui	$t9,0x8008
/*  f1564c8:	8f3900f4 */ 	lw	$t9,0xf4($t9)
/*  f1564cc:	8fad00c0 */ 	lw	$t5,0xc0($sp)
/*  f1564d0:	8fae00c4 */ 	lw	$t6,0xc4($sp)
/*  f1564d4:	0319001a */ 	div	$zero,$t8,$t9
/*  f1564d8:	00004812 */ 	mflo	$t1
/*  f1564dc:	252affff */ 	addiu	$t2,$t1,-1
/*  f1564e0:	afaa0094 */ 	sw	$t2,0x94($sp)
/*  f1564e4:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f1564e8:	17200002 */ 	bnez	$t9,.JF0f1564f4
/*  f1564ec:	00000000 */ 	nop
/*  f1564f0:	0007000d */ 	break	0x7
.JF0f1564f4:
/*  f1564f4:	2401ffff */ 	li	$at,-1
/*  f1564f8:	17210004 */ 	bne	$t9,$at,.JF0f15650c
/*  f1564fc:	3c018000 */ 	lui	$at,0x8000
/*  f156500:	17010002 */ 	bne	$t8,$at,.JF0f15650c
/*  f156504:	00000000 */ 	nop
/*  f156508:	0006000d */ 	break	0x6
.JF0f15650c:
/*  f15650c:	8fb800d0 */ 	lw	$t8,0xd0($sp)
/*  f156510:	8fb900d4 */ 	lw	$t9,0xd4($sp)
/*  f156514:	8faf00cc */ 	lw	$t7,0xcc($sp)
/*  f156518:	256cffff */ 	addiu	$t4,$t3,-1
/*  f15651c:	afac0090 */ 	sw	$t4,0x90($sp)
/*  f156520:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f156524:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f156528:	00402025 */ 	move	$a0,$v0
/*  f15652c:	02602825 */ 	move	$a1,$s3
/*  f156530:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f156534:	8fa700bc */ 	lw	$a3,0xbc($sp)
/*  f156538:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f15653c:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f156540:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f156544:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f156548:	0fc55886 */ 	jal	textRenderProjected
/*  f15654c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f156550:	8e490000 */ 	lw	$t1,0x0($s2)
/*  f156554:	3c0a8008 */ 	lui	$t2,0x8008
/*  f156558:	8d4a00f4 */ 	lw	$t2,0xf4($t2)
/*  f15655c:	8faf00c0 */ 	lw	$t7,0xc0($sp)
/*  f156560:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f156564:	012a001a */ 	div	$zero,$t1,$t2
/*  f156568:	00005812 */ 	mflo	$t3
/*  f15656c:	256cffff */ 	addiu	$t4,$t3,-1
/*  f156570:	afac0094 */ 	sw	$t4,0x94($sp)
/*  f156574:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f156578:	15400002 */ 	bnez	$t2,.JF0f156584
/*  f15657c:	00000000 */ 	nop
/*  f156580:	0007000d */ 	break	0x7
.JF0f156584:
/*  f156584:	2401ffff */ 	li	$at,-1
/*  f156588:	15410004 */ 	bne	$t2,$at,.JF0f15659c
/*  f15658c:	3c018000 */ 	lui	$at,0x8000
/*  f156590:	15210002 */ 	bne	$t1,$at,.JF0f15659c
/*  f156594:	00000000 */ 	nop
/*  f156598:	0006000d */ 	break	0x6
.JF0f15659c:
/*  f15659c:	8fa900d0 */ 	lw	$t1,0xd0($sp)
/*  f1565a0:	8faa00d4 */ 	lw	$t2,0xd4($sp)
/*  f1565a4:	8fb900cc */ 	lw	$t9,0xcc($sp)
/*  f1565a8:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f1565ac:	afae0090 */ 	sw	$t6,0x90($sp)
/*  f1565b0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1565b4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1565b8:	00402025 */ 	move	$a0,$v0
/*  f1565bc:	02602825 */ 	move	$a1,$s3
/*  f1565c0:	27a60090 */ 	addiu	$a2,$sp,0x90
/*  f1565c4:	8fa700bc */ 	lw	$a3,0xbc($sp)
/*  f1565c8:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f1565cc:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1565d0:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f1565d4:	afaa0024 */ 	sw	$t2,0x24($sp)
/*  f1565d8:	0fc55886 */ 	jal	textRenderProjected
/*  f1565dc:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f1565e0:	8fac0088 */ 	lw	$t4,0x88($sp)
/*  f1565e4:	240b0001 */ 	li	$t3,0x1
/*  f1565e8:	3c018008 */ 	lui	$at,0x8008
/*  f1565ec:	ac2b022c */ 	sw	$t3,0x22c($at)
/*  f1565f0:	8fad008c */ 	lw	$t5,0x8c($sp)
/*  f1565f4:	3c01800a */ 	lui	$at,0x800a
/*  f1565f8:	a02c4f98 */ 	sb	$t4,0x4f98($at)
/*  f1565fc:	3c01800a */ 	lui	$at,0x800a
/*  f156600:	00409825 */ 	move	$s3,$v0
/*  f156604:	a02d4fb0 */ 	sb	$t5,0x4fb0($at)
.JF0f156608:
/*  f156608:	3c0e8008 */ 	lui	$t6,0x8008
/*  f15660c:	8dce0100 */ 	lw	$t6,0x100($t6)
/*  f156610:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f156614:	8fb400d8 */ 	lw	$s4,0xd8($sp)
/*  f156618:	15c00004 */ 	bnez	$t6,.JF0f15662c
/*  f15661c:	24848074 */ 	addiu	$a0,$a0,-32652
/*  f156620:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f156624:	25f8ffff */ 	addiu	$t8,$t7,-1
/*  f156628:	ae380000 */ 	sw	$t8,0x0($s1)
.JF0f15662c:
/*  f15662c:	3c058008 */ 	lui	$a1,0x8008
/*  f156630:	0c0036b4 */ 	jal	mainOverrideVariable
/*  f156634:	24a50208 */ 	addiu	$a1,$a1,0x208
/*  f156638:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f15663c:	3c058008 */ 	lui	$a1,0x8008
/*  f156640:	24a50214 */ 	addiu	$a1,$a1,0x214
/*  f156644:	0c0036b4 */ 	jal	mainOverrideVariable
/*  f156648:	2484807c */ 	addiu	$a0,$a0,-32644
/*  f15664c:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f156650:	3c058008 */ 	lui	$a1,0x8008
/*  f156654:	24a50218 */ 	addiu	$a1,$a1,0x218
/*  f156658:	0c0036b4 */ 	jal	mainOverrideVariable
/*  f15665c:	24848088 */ 	addiu	$a0,$a0,-32632
/*  f156660:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f156664:	3c058008 */ 	lui	$a1,0x8008
/*  f156668:	24a50220 */ 	addiu	$a1,$a1,0x220
/*  f15666c:	0c0036b4 */ 	jal	mainOverrideVariable
/*  f156670:	24848094 */ 	addiu	$a0,$a0,-32620
/*  f156674:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f156678:	3c058008 */ 	lui	$a1,0x8008
/*  f15667c:	24a5021c */ 	addiu	$a1,$a1,0x21c
/*  f156680:	0c0036b4 */ 	jal	mainOverrideVariable
/*  f156684:	2484809c */ 	addiu	$a0,$a0,-32612
/*  f156688:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f15668c:	3c058008 */ 	lui	$a1,0x8008
/*  f156690:	24a5020c */ 	addiu	$a1,$a1,0x20c
/*  f156694:	0c0036b4 */ 	jal	mainOverrideVariable
/*  f156698:	248480a4 */ 	addiu	$a0,$a0,-32604
/*  f15669c:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1566a0:	3c058008 */ 	lui	$a1,0x8008
/*  f1566a4:	24a50210 */ 	addiu	$a1,$a1,0x210
/*  f1566a8:	0c0036b4 */ 	jal	mainOverrideVariable
/*  f1566ac:	248480ac */ 	addiu	$a0,$a0,-32596
/*  f1566b0:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f1566b4:	8e500000 */ 	lw	$s0,0x0($s2)
/*  f1566b8:	24090048 */ 	li	$t1,0x48
/*  f1566bc:	2401ffff */ 	li	$at,-1
/*  f1566c0:	a3a900a7 */ 	sb	$t1,0xa7($sp)
/*  f1566c4:	16810006 */ 	bne	$s4,$at,.JF0f1566e0
/*  f1566c8:	afb900a8 */ 	sw	$t9,0xa8($sp)
/*  f1566cc:	8faa00c0 */ 	lw	$t2,0xc0($sp)
/*  f1566d0:	914b0447 */ 	lbu	$t3,0x447($t2)
/*  f1566d4:	814c0446 */ 	lb	$t4,0x446($t2)
/*  f1566d8:	10000002 */ 	b	.JF0f1566e4
/*  f1566dc:	016ca021 */ 	addu	$s4,$t3,$t4
.JF0f1566e0:
/*  f1566e0:	2414000d */ 	li	$s4,0xd
.JF0f1566e4:
/*  f1566e4:	02601025 */ 	move	$v0,$s3
/*  f1566e8:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1566ec:	3c0de700 */ 	lui	$t5,0xe700
/*  f1566f0:	02601825 */ 	move	$v1,$s3
/*  f1566f4:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f1566f8:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1566fc:	3c0eba00 */ 	lui	$t6,0xba00
/*  f156700:	35ce0e02 */ 	ori	$t6,$t6,0xe02
/*  f156704:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f156708:	340fc000 */ 	li	$t7,0xc000
/*  f15670c:	ac6f0004 */ 	sw	$t7,0x4($v1)
/*  f156710:	ac6e0000 */ 	sw	$t6,0x0($v1)
/*  f156714:	02603825 */ 	move	$a3,$s3
/*  f156718:	3c18fd10 */ 	lui	$t8,0xfd10
/*  f15671c:	acf80000 */ 	sw	$t8,0x0($a3)
/*  f156720:	3c048008 */ 	lui	$a0,0x8008
/*  f156724:	248401d8 */ 	addiu	$a0,$a0,0x1d8
/*  f156728:	afa70078 */ 	sw	$a3,0x78($sp)
/*  f15672c:	0c012b34 */ 	jal	osVirtualToPhysical
/*  f156730:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f156734:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f156738:	24190001 */ 	li	$t9,0x1
/*  f15673c:	3c018008 */ 	lui	$at,0x8008
/*  f156740:	02601825 */ 	move	$v1,$s3
/*  f156744:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f156748:	ac3900f8 */ 	sw	$t9,0xf8($at)
/*  f15674c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f156750:	3c09e600 */ 	lui	$t1,0xe600
/*  f156754:	02602025 */ 	move	$a0,$s3
/*  f156758:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f15675c:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f156760:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f156764:	3c0b0603 */ 	lui	$t3,0x603
/*  f156768:	356bc000 */ 	ori	$t3,$t3,0xc000
/*  f15676c:	3c0af000 */ 	lui	$t2,0xf000
/*  f156770:	02602825 */ 	move	$a1,$s3
/*  f156774:	ac8a0000 */ 	sw	$t2,0x0($a0)
/*  f156778:	ac8b0004 */ 	sw	$t3,0x4($a0)
/*  f15677c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f156780:	3c0cf540 */ 	lui	$t4,0xf540
/*  f156784:	358c0200 */ 	ori	$t4,$t4,0x200
/*  f156788:	02603025 */ 	move	$a2,$s3
/*  f15678c:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f156790:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f156794:	3c0e0007 */ 	lui	$t6,0x7
/*  f156798:	35cec07c */ 	ori	$t6,$t6,0xc07c
/*  f15679c:	3c0df200 */ 	lui	$t5,0xf200
/*  f1567a0:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f1567a4:	acce0004 */ 	sw	$t6,0x4($a2)
/*  f1567a8:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1567ac:	8fa300c8 */ 	lw	$v1,0xc8($sp)
/*  f1567b0:	02604025 */ 	move	$t0,$s3
/*  f1567b4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1567b8:	3c0ffa00 */ 	lui	$t7,0xfa00
/*  f1567bc:	ad0f0000 */ 	sw	$t7,0x0($t0)
/*  f1567c0:	02601025 */ 	move	$v0,$s3
/*  f1567c4:	ad030004 */ 	sw	$v1,0x4($t0)
/*  f1567c8:	3c18e700 */ 	lui	$t8,0xe700
/*  f1567cc:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f1567d0:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1567d4:	8fb900bc */ 	lw	$t9,0xbc($sp)
/*  f1567d8:	3c01800a */ 	lui	$at,0x800a
/*  f1567dc:	ac234f9c */ 	sw	$v1,0x4f9c($at)
/*  f1567e0:	3c01800a */ 	lui	$at,0x800a
/*  f1567e4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1567e8:	13200048 */ 	beqz	$t9,.JF0f15690c
/*  f1567ec:	ac234fdc */ 	sw	$v1,0x4fdc($at)
/*  f1567f0:	93220000 */ 	lbu	$v0,0x0($t9)
/*  f1567f4:	10400045 */ 	beqz	$v0,.JF0f15690c
/*  f1567f8:	00000000 */ 	nop
/*  f1567fc:	24010020 */ 	li	$at,0x20
.JF0f156800:
/*  f156800:	5441000e */ 	bnel	$v0,$at,.JF0f15683c
/*  f156804:	2401000a */ 	li	$at,0xa
/*  f156808:	8faa00a0 */ 	lw	$t2,0xa0($sp)
/*  f15680c:	8e490000 */ 	lw	$t1,0x0($s2)
/*  f156810:	240d0048 */ 	li	$t5,0x48
/*  f156814:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f156818:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f15681c:	012b6021 */ 	addu	$t4,$t1,$t3
/*  f156820:	ae4c0000 */ 	sw	$t4,0x0($s2)
/*  f156824:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f156828:	a3ad00a7 */ 	sb	$t5,0xa7($sp)
/*  f15682c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f156830:	10000032 */ 	b	.JF0f1568fc
/*  f156834:	afaf00bc */ 	sw	$t7,0xbc($sp)
/*  f156838:	2401000a */ 	li	$at,0xa
.JF0f15683c:
/*  f15683c:	14410015 */ 	bne	$v0,$at,.JF0f156894
/*  f156840:	3c028008 */ 	lui	$v0,0x8008
/*  f156844:	8c420110 */ 	lw	$v0,0x110($v0)
/*  f156848:	04420009 */ 	bltzl	$v0,.JF0f156870
/*  f15684c:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f156850:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f156854:	56180006 */ 	bnel	$s0,$t8,.JF0f156870
/*  f156858:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f15685c:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f156860:	03225021 */ 	addu	$t2,$t9,$v0
/*  f156864:	10000004 */ 	b	.JF0f156878
/*  f156868:	ae2a0000 */ 	sw	$t2,0x0($s1)
/*  f15686c:	8e290000 */ 	lw	$t1,0x0($s1)
.JF0f156870:
/*  f156870:	01345821 */ 	addu	$t3,$t1,$s4
/*  f156874:	ae2b0000 */ 	sw	$t3,0x0($s1)
.JF0f156878:
/*  f156878:	ae500000 */ 	sw	$s0,0x0($s2)
/*  f15687c:	8fad00bc */ 	lw	$t5,0xbc($sp)
/*  f156880:	240c0048 */ 	li	$t4,0x48
/*  f156884:	a3ac00a7 */ 	sb	$t4,0xa7($sp)
/*  f156888:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f15688c:	1000001b */ 	b	.JF0f1568fc
/*  f156890:	afae00bc */ 	sw	$t6,0xbc($sp)
.JF0f156894:
/*  f156894:	27af00a7 */ 	addiu	$t7,$sp,0xa7
/*  f156898:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f15689c:	27a400bc */ 	addiu	$a0,$sp,0xbc
/*  f1568a0:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f1568a4:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f1568a8:	0fc552c0 */ 	jal	textMapCodeUnitToChar
/*  f1568ac:	8fa700c0 */ 	lw	$a3,0xc0($sp)
/*  f1568b0:	8fb80058 */ 	lw	$t8,0x58($sp)
/*  f1568b4:	8fb900c4 */ 	lw	$t9,0xc4($sp)
/*  f1568b8:	8faa00a8 */ 	lw	$t2,0xa8($sp)
/*  f1568bc:	8fa900cc */ 	lw	$t1,0xcc($sp)
/*  f1568c0:	8fab00d0 */ 	lw	$t3,0xd0($sp)
/*  f1568c4:	8fac00d4 */ 	lw	$t4,0xd4($sp)
/*  f1568c8:	02602025 */ 	move	$a0,$s3
/*  f1568cc:	02402825 */ 	move	$a1,$s2
/*  f1568d0:	02203025 */ 	move	$a2,$s1
/*  f1568d4:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f1568d8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1568dc:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1568e0:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f1568e4:	afaa001c */ 	sw	$t2,0x1c($sp)
/*  f1568e8:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f1568ec:	afab0024 */ 	sw	$t3,0x24($sp)
/*  f1568f0:	0fc55541 */ 	jal	func0f15568c
/*  f1568f4:	afac0028 */ 	sw	$t4,0x28($sp)
/*  f1568f8:	00409825 */ 	move	$s3,$v0
.JF0f1568fc:
/*  f1568fc:	8fad00bc */ 	lw	$t5,0xbc($sp)
/*  f156900:	91a20000 */ 	lbu	$v0,0x0($t5)
/*  f156904:	5440ffbe */ 	bnezl	$v0,.JF0f156800
/*  f156908:	24010020 */ 	li	$at,0x20
.JF0f15690c:
/*  f15690c:	3c0e8008 */ 	lui	$t6,0x8008
/*  f156910:	8dce0100 */ 	lw	$t6,0x100($t6)
/*  f156914:	02601025 */ 	move	$v0,$s3
/*  f156918:	11c00012 */ 	beqz	$t6,.JF0f156964
/*  f15691c:	00000000 */ 	nop
/*  f156920:	3c188008 */ 	lui	$t8,0x8008
/*  f156924:	8f1800f4 */ 	lw	$t8,0xf4($t8)
/*  f156928:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*  f15692c:	01f8001a */ 	div	$zero,$t7,$t8
/*  f156930:	0000c812 */ 	mflo	$t9
/*  f156934:	ae390000 */ 	sw	$t9,0x0($s1)
/*  f156938:	17000002 */ 	bnez	$t8,.JF0f156944
/*  f15693c:	00000000 */ 	nop
/*  f156940:	0007000d */ 	break	0x7
.JF0f156944:
/*  f156944:	2401ffff */ 	li	$at,-1
/*  f156948:	17010004 */ 	bne	$t8,$at,.JF0f15695c
/*  f15694c:	3c018000 */ 	lui	$at,0x8000
/*  f156950:	15e10002 */ 	bne	$t7,$at,.JF0f15695c
/*  f156954:	00000000 */ 	nop
/*  f156958:	0006000d */ 	break	0x6
.JF0f15695c:
/*  f15695c:	10000011 */ 	b	.JF0f1569a4
/*  f156960:	8fbf004c */ 	lw	$ra,0x4c($sp)
.JF0f156964:
/*  f156964:	3c098008 */ 	lui	$t1,0x8008
/*  f156968:	8d2900f4 */ 	lw	$t1,0xf4($t1)
/*  f15696c:	8e4a0000 */ 	lw	$t2,0x0($s2)
/*  f156970:	0149001a */ 	div	$zero,$t2,$t1
/*  f156974:	00005812 */ 	mflo	$t3
/*  f156978:	ae4b0000 */ 	sw	$t3,0x0($s2)
/*  f15697c:	15200002 */ 	bnez	$t1,.JF0f156988
/*  f156980:	00000000 */ 	nop
/*  f156984:	0007000d */ 	break	0x7
.JF0f156988:
/*  f156988:	2401ffff */ 	li	$at,-1
/*  f15698c:	15210004 */ 	bne	$t1,$at,.JF0f1569a0
/*  f156990:	3c018000 */ 	lui	$at,0x8000
/*  f156994:	15410002 */ 	bne	$t2,$at,.JF0f1569a0
/*  f156998:	00000000 */ 	nop
/*  f15699c:	0006000d */ 	break	0x6
.JF0f1569a0:
/*  f1569a0:	8fbf004c */ 	lw	$ra,0x4c($sp)
.JF0f1569a4:
/*  f1569a4:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1569a8:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f1569ac:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f1569b0:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f1569b4:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f1569b8:	03e00008 */ 	jr	$ra
/*  f1569bc:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);
#elif VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel textRenderProjected
/*  f157140:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f157144:	3c0e8008 */ 	lui	$t6,0x8008
/*  f157148:	8dce0028 */ 	lw	$t6,0x28($t6)
/*  f15714c:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f157150:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f157154:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f157158:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f15715c:	3c158008 */ 	lui	$s5,0x8008
/*  f157160:	00c08025 */ 	move	$s0,$a2
/*  f157164:	00a08825 */ 	move	$s1,$a1
/*  f157168:	00809825 */ 	move	$s3,$a0
/*  f15716c:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f157170:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f157174:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f157178:	afa700b4 */ 	sw	$a3,0xb4($sp)
/*  f15717c:	11c0000a */ 	beqz	$t6,.PF0f1571a8
/*  f157180:	8eb50030 */ 	lw	$s5,0x30($s5)
/*  f157184:	3c188008 */ 	lui	$t8,0x8008
/*  f157188:	8f180020 */ 	lw	$t8,0x20($t8)
/*  f15718c:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f157190:	24150001 */ 	li	$s5,0x1
/*  f157194:	01f80019 */ 	multu	$t7,$t8
/*  f157198:	0000c812 */ 	mflo	$t9
/*  f15719c:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f1571a0:	10000008 */ 	b	.PF0f1571c4
/*  f1571a4:	00000000 */ 	nop
.PF0f1571a8:
/*  f1571a8:	3c0a8008 */ 	lui	$t2,0x8008
/*  f1571ac:	8d4a0020 */ 	lw	$t2,0x20($t2)
/*  f1571b0:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f1571b4:	012a0019 */ 	multu	$t1,$t2
/*  f1571b8:	00005812 */ 	mflo	$t3
/*  f1571bc:	ae2b0000 */ 	sw	$t3,0x0($s1)
/*  f1571c0:	00000000 */ 	nop
.PF0f1571c4:
/*  f1571c4:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1571c8:	8d8c012c */ 	lw	$t4,0x12c($t4)
/*  f1571cc:	11800064 */ 	beqz	$t4,.PF0f157360
/*  f1571d0:	3c014220 */ 	lui	$at,0x4220
/*  f1571d4:	44816000 */ 	mtc1	$at,$f12
/*  f1571d8:	0fc01abe */ 	jal	func0f006b08
/*  f1571dc:	00000000 */ 	nop
/*  f1571e0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1571e4:	8dce0020 */ 	lw	$t6,0x20($t6)
/*  f1571e8:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f1571ec:	24090001 */ 	li	$t1,0x1
/*  f1571f0:	3c12800a */ 	lui	$s2,0x800a
/*  f1571f4:	01ae001a */ 	div	$zero,$t5,$t6
/*  f1571f8:	15c00002 */ 	bnez	$t6,.PF0f157204
/*  f1571fc:	00000000 */ 	nop
/*  f157200:	0007000d */ 	break	0x7
.PF0f157204:
/*  f157204:	2401ffff */ 	li	$at,-1
/*  f157208:	15c10004 */ 	bne	$t6,$at,.PF0f15721c
/*  f15720c:	3c018000 */ 	lui	$at,0x8000
/*  f157210:	15a10002 */ 	bne	$t5,$at,.PF0f15721c
/*  f157214:	00000000 */ 	nop
/*  f157218:	0006000d */ 	break	0x6
.PF0f15721c:
/*  f15721c:	3c013f80 */ 	lui	$at,0x3f80
/*  f157220:	44812000 */ 	mtc1	$at,$f4
/*  f157224:	3c0142c8 */ 	lui	$at,0x42c8
/*  f157228:	44814000 */ 	mtc1	$at,$f8
/*  f15722c:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f157230:	3c014316 */ 	lui	$at,0x4316
/*  f157234:	44818000 */ 	mtc1	$at,$f16
/*  f157238:	00007812 */ 	mflo	$t7
/*  f15723c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f157240:	afaf008c */ 	sw	$t7,0x8c($sp)
/*  f157244:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f157248:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f15724c:	3c058008 */ 	lui	$a1,0x8008
/*  f157250:	8e524bdc */ 	lw	$s2,0x4bdc($s2)
/*  f157254:	8faa00c0 */ 	lw	$t2,0xc0($sp)
/*  f157258:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f15725c:	24a50130 */ 	addiu	$a1,$a1,0x130
/*  f157260:	248486e8 */ 	addiu	$a0,$a0,-31000
/*  f157264:	afb80088 */ 	sw	$t8,0x88($sp)
/*  f157268:	4459f800 */ 	cfc1	$t9,$31
/*  f15726c:	44c9f800 */ 	ctc1	$t1,$31
/*  f157270:	00000000 */ 	nop
/*  f157274:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f157278:	4449f800 */ 	cfc1	$t1,$31
/*  f15727c:	00000000 */ 	nop
/*  f157280:	31210004 */ 	andi	$at,$t1,0x4
/*  f157284:	31290078 */ 	andi	$t1,$t1,0x78
/*  f157288:	11200012 */ 	beqz	$t1,.PF0f1572d4
/*  f15728c:	3c014f00 */ 	lui	$at,0x4f00
/*  f157290:	44812000 */ 	mtc1	$at,$f4
/*  f157294:	24090001 */ 	li	$t1,0x1
/*  f157298:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f15729c:	44c9f800 */ 	ctc1	$t1,$31
/*  f1572a0:	00000000 */ 	nop
/*  f1572a4:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f1572a8:	4449f800 */ 	cfc1	$t1,$31
/*  f1572ac:	00000000 */ 	nop
/*  f1572b0:	31290078 */ 	andi	$t1,$t1,0x78
/*  f1572b4:	15200005 */ 	bnez	$t1,.PF0f1572cc
/*  f1572b8:	00000000 */ 	nop
/*  f1572bc:	44092000 */ 	mfc1	$t1,$f4
/*  f1572c0:	3c018000 */ 	lui	$at,0x8000
/*  f1572c4:	10000007 */ 	b	.PF0f1572e4
/*  f1572c8:	01214825 */ 	or	$t1,$t1,$at
.PF0f1572cc:
/*  f1572cc:	10000005 */ 	b	.PF0f1572e4
/*  f1572d0:	2409ffff */ 	li	$t1,-1
.PF0f1572d4:
/*  f1572d4:	44092000 */ 	mfc1	$t1,$f4
/*  f1572d8:	00000000 */ 	nop
/*  f1572dc:	0520fffb */ 	bltz	$t1,.PF0f1572cc
/*  f1572e0:	00000000 */ 	nop
.PF0f1572e4:
/*  f1572e4:	2401ff00 */ 	li	$at,-256
/*  f1572e8:	01415824 */ 	and	$t3,$t2,$at
/*  f1572ec:	01696025 */ 	or	$t4,$t3,$t1
/*  f1572f0:	44d9f800 */ 	ctc1	$t9,$31
/*  f1572f4:	0c003624 */ 	jal	mainOverrideVariable
/*  f1572f8:	afac0094 */ 	sw	$t4,0x94($sp)
/*  f1572fc:	3c028008 */ 	lui	$v0,0x8008
/*  f157300:	8c420130 */ 	lw	$v0,0x130($v0)
/*  f157304:	8fb400d0 */ 	lw	$s4,0xd0($sp)
/*  f157308:	02602025 */ 	move	$a0,$s3
/*  f15730c:	10400002 */ 	beqz	$v0,.PF0f157318
/*  f157310:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f157314:	00409025 */ 	move	$s2,$v0
.PF0f157318:
/*  f157318:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*  f15731c:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f157320:	8faf0094 */ 	lw	$t7,0x94($sp)
/*  f157324:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f157328:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*  f15732c:	8faa00cc */ 	lw	$t2,0xcc($sp)
/*  f157330:	27a60088 */ 	addiu	$a2,$sp,0x88
/*  f157334:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f157338:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f15733c:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f157340:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f157344:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f157348:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f15734c:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f157350:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f157354:	0fc55fa0 */ 	jal	textRender
/*  f157358:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f15735c:	00409825 */ 	move	$s3,$v0
.PF0f157360:
/*  f157360:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f157364:	3c058008 */ 	lui	$a1,0x8008
/*  f157368:	8fb400d0 */ 	lw	$s4,0xd0($sp)
/*  f15736c:	24a5010c */ 	addiu	$a1,$a1,0x10c
/*  f157370:	0c003624 */ 	jal	mainOverrideVariable
/*  f157374:	248486f0 */ 	addiu	$a0,$a0,-30992
/*  f157378:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f15737c:	3c058008 */ 	lui	$a1,0x8008
/*  f157380:	24a50118 */ 	addiu	$a1,$a1,0x118
/*  f157384:	0c003624 */ 	jal	mainOverrideVariable
/*  f157388:	248486f8 */ 	addiu	$a0,$a0,-30984
/*  f15738c:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f157390:	3c058008 */ 	lui	$a1,0x8008
/*  f157394:	24a5011c */ 	addiu	$a1,$a1,0x11c
/*  f157398:	0c003624 */ 	jal	mainOverrideVariable
/*  f15739c:	24848704 */ 	addiu	$a0,$a0,-30972
/*  f1573a0:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1573a4:	3c058008 */ 	lui	$a1,0x8008
/*  f1573a8:	24a50124 */ 	addiu	$a1,$a1,0x124
/*  f1573ac:	0c003624 */ 	jal	mainOverrideVariable
/*  f1573b0:	24848710 */ 	addiu	$a0,$a0,-30960
/*  f1573b4:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1573b8:	3c058008 */ 	lui	$a1,0x8008
/*  f1573bc:	24a50120 */ 	addiu	$a1,$a1,0x120
/*  f1573c0:	0c003624 */ 	jal	mainOverrideVariable
/*  f1573c4:	24848718 */ 	addiu	$a0,$a0,-30952
/*  f1573c8:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1573cc:	3c058008 */ 	lui	$a1,0x8008
/*  f1573d0:	24a50110 */ 	addiu	$a1,$a1,0x110
/*  f1573d4:	0c003624 */ 	jal	mainOverrideVariable
/*  f1573d8:	24848720 */ 	addiu	$a0,$a0,-30944
/*  f1573dc:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f1573e0:	3c058008 */ 	lui	$a1,0x8008
/*  f1573e4:	24a50114 */ 	addiu	$a1,$a1,0x114
/*  f1573e8:	0c003624 */ 	jal	mainOverrideVariable
/*  f1573ec:	24848728 */ 	addiu	$a0,$a0,-30936
/*  f1573f0:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f1573f4:	8e320000 */ 	lw	$s2,0x0($s1)
/*  f1573f8:	24090048 */ 	li	$t1,0x48
/*  f1573fc:	a3a9009f */ 	sb	$t1,0x9f($sp)
/*  f157400:	16800005 */ 	bnez	$s4,.PF0f157418
/*  f157404:	afab00a0 */ 	sw	$t3,0xa0($sp)
/*  f157408:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f15740c:	818d0445 */ 	lb	$t5,0x445($t4)
/*  f157410:	918e0446 */ 	lbu	$t6,0x446($t4)
/*  f157414:	01aea021 */ 	addu	$s4,$t5,$t6
.PF0f157418:
/*  f157418:	3c0f8008 */ 	lui	$t7,0x8008
/*  f15741c:	8def4660 */ 	lw	$t7,0x4660($t7)
/*  f157420:	02601025 */ 	move	$v0,$s3
/*  f157424:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157428:	11e00005 */ 	beqz	$t7,.PF0f157440
/*  f15742c:	3c18e700 */ 	lui	$t8,0xe700
/*  f157430:	2a81000e */ 	slti	$at,$s4,0xe
/*  f157434:	50200003 */ 	beqzl	$at,.PF0f157444
/*  f157438:	02601825 */ 	move	$v1,$s3
/*  f15743c:	2414000e */ 	li	$s4,0xe
.PF0f157440:
/*  f157440:	02601825 */ 	move	$v1,$s3
.PF0f157444:
/*  f157444:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f157448:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f15744c:	3c19ba00 */ 	lui	$t9,0xba00
/*  f157450:	37390e02 */ 	ori	$t9,$t9,0xe02
/*  f157454:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157458:	340ac000 */ 	li	$t2,0xc000
/*  f15745c:	ac6a0004 */ 	sw	$t2,0x4($v1)
/*  f157460:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f157464:	02603825 */ 	move	$a3,$s3
/*  f157468:	3c0bfd10 */ 	lui	$t3,0xfd10
/*  f15746c:	aceb0000 */ 	sw	$t3,0x0($a3)
/*  f157470:	3c048008 */ 	lui	$a0,0x8008
/*  f157474:	2484009c */ 	addiu	$a0,$a0,0x9c
/*  f157478:	afa70078 */ 	sw	$a3,0x78($sp)
/*  f15747c:	0c012ab0 */ 	jal	osVirtualToPhysical
/*  f157480:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157484:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f157488:	02601825 */ 	move	$v1,$s3
/*  f15748c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157490:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f157494:	3c09e600 */ 	lui	$t1,0xe600
/*  f157498:	02602025 */ 	move	$a0,$s3
/*  f15749c:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f1574a0:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1574a4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1574a8:	3c0d0603 */ 	lui	$t5,0x603
/*  f1574ac:	35adc000 */ 	ori	$t5,$t5,0xc000
/*  f1574b0:	3c0cf000 */ 	lui	$t4,0xf000
/*  f1574b4:	02602825 */ 	move	$a1,$s3
/*  f1574b8:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f1574bc:	ac8d0004 */ 	sw	$t5,0x4($a0)
/*  f1574c0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1574c4:	3c0ef540 */ 	lui	$t6,0xf540
/*  f1574c8:	35ce0200 */ 	ori	$t6,$t6,0x200
/*  f1574cc:	02603025 */ 	move	$a2,$s3
/*  f1574d0:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f1574d4:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f1574d8:	3c180007 */ 	lui	$t8,0x7
/*  f1574dc:	3718c07c */ 	ori	$t8,$t8,0xc07c
/*  f1574e0:	3c0ff200 */ 	lui	$t7,0xf200
/*  f1574e4:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f1574e8:	acd80004 */ 	sw	$t8,0x4($a2)
/*  f1574ec:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1574f0:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f1574f4:	02604025 */ 	move	$t0,$s3
/*  f1574f8:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f1574fc:	3c19fa00 */ 	lui	$t9,0xfa00
/*  f157500:	ad190000 */ 	sw	$t9,0x0($t0)
/*  f157504:	02601025 */ 	move	$v0,$s3
/*  f157508:	ad040004 */ 	sw	$a0,0x4($t0)
/*  f15750c:	3c0ae700 */ 	lui	$t2,0xe700
/*  f157510:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f157514:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f157518:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f15751c:	3c03800a */ 	lui	$v1,0x800a
/*  f157520:	24634b70 */ 	addiu	$v1,$v1,0x4b70
/*  f157524:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157528:	ac640004 */ 	sw	$a0,0x4($v1)
/*  f15752c:	11600047 */ 	beqz	$t3,.PF0f15764c
/*  f157530:	ac640044 */ 	sw	$a0,0x44($v1)
/*  f157534:	91620000 */ 	lbu	$v0,0x0($t3)
/*  f157538:	10400044 */ 	beqz	$v0,.PF0f15764c
/*  f15753c:	00000000 */ 	nop
/*  f157540:	24010020 */ 	li	$at,0x20
.PF0f157544:
/*  f157544:	5441000d */ 	bnel	$v0,$at,.PF0f15757c
/*  f157548:	2401000a */ 	li	$at,0xa
/*  f15754c:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f157550:	00156080 */ 	sll	$t4,$s5,0x2
/*  f157554:	01956021 */ 	addu	$t4,$t4,$s5
/*  f157558:	012c6821 */ 	addu	$t5,$t1,$t4
/*  f15755c:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f157560:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f157564:	240e0048 */ 	li	$t6,0x48
/*  f157568:	a3ae009f */ 	sb	$t6,0x9f($sp)
/*  f15756c:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f157570:	10000032 */ 	b	.PF0f15763c
/*  f157574:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f157578:	2401000a */ 	li	$at,0xa
.PF0f15757c:
/*  f15757c:	14410015 */ 	bne	$v0,$at,.PF0f1575d4
/*  f157580:	3c028008 */ 	lui	$v0,0x8008
/*  f157584:	8c420034 */ 	lw	$v0,0x34($v0)
/*  f157588:	04420009 */ 	bltzl	$v0,.PF0f1575b0
/*  f15758c:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f157590:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f157594:	56590006 */ 	bnel	$s2,$t9,.PF0f1575b0
/*  f157598:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f15759c:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f1575a0:	01425821 */ 	addu	$t3,$t2,$v0
/*  f1575a4:	10000004 */ 	b	.PF0f1575b8
/*  f1575a8:	ae0b0000 */ 	sw	$t3,0x0($s0)
/*  f1575ac:	8e090000 */ 	lw	$t1,0x0($s0)
.PF0f1575b0:
/*  f1575b0:	01346021 */ 	addu	$t4,$t1,$s4
/*  f1575b4:	ae0c0000 */ 	sw	$t4,0x0($s0)
.PF0f1575b8:
/*  f1575b8:	ae320000 */ 	sw	$s2,0x0($s1)
/*  f1575bc:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f1575c0:	240d0048 */ 	li	$t5,0x48
/*  f1575c4:	a3ad009f */ 	sb	$t5,0x9f($sp)
/*  f1575c8:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f1575cc:	1000001b */ 	b	.PF0f15763c
/*  f1575d0:	afaf00b4 */ 	sw	$t7,0xb4($sp)
.PF0f1575d4:
/*  f1575d4:	27b8009f */ 	addiu	$t8,$sp,0x9f
/*  f1575d8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1575dc:	27a400b4 */ 	addiu	$a0,$sp,0xb4
/*  f1575e0:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f1575e4:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f1575e8:	0fc5574b */ 	jal	textMapCodeUnitToChar
/*  f1575ec:	8fa700b8 */ 	lw	$a3,0xb8($sp)
/*  f1575f0:	8fb90058 */ 	lw	$t9,0x58($sp)
/*  f1575f4:	8faa00bc */ 	lw	$t2,0xbc($sp)
/*  f1575f8:	8fab00a0 */ 	lw	$t3,0xa0($sp)
/*  f1575fc:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f157600:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*  f157604:	8fad00cc */ 	lw	$t5,0xcc($sp)
/*  f157608:	02602025 */ 	move	$a0,$s3
/*  f15760c:	02202825 */ 	move	$a1,$s1
/*  f157610:	02003025 */ 	move	$a2,$s0
/*  f157614:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f157618:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f15761c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f157620:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f157624:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f157628:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f15762c:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f157630:	0fc559e0 */ 	jal	func0f15568c
/*  f157634:	afad0028 */ 	sw	$t5,0x28($sp)
/*  f157638:	00409825 */ 	move	$s3,$v0
.PF0f15763c:
/*  f15763c:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f157640:	91c20000 */ 	lbu	$v0,0x0($t6)
/*  f157644:	5440ffbf */ 	bnezl	$v0,.PF0f157544
/*  f157648:	24010020 */ 	li	$at,0x20
.PF0f15764c:
/*  f15764c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f157650:	8def0028 */ 	lw	$t7,0x28($t7)
/*  f157654:	02601025 */ 	move	$v0,$s3
/*  f157658:	11e00012 */ 	beqz	$t7,.PF0f1576a4
/*  f15765c:	00000000 */ 	nop
/*  f157660:	3c198008 */ 	lui	$t9,0x8008
/*  f157664:	8f390020 */ 	lw	$t9,0x20($t9)
/*  f157668:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f15766c:	0319001a */ 	div	$zero,$t8,$t9
/*  f157670:	00005012 */ 	mflo	$t2
/*  f157674:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f157678:	17200002 */ 	bnez	$t9,.PF0f157684
/*  f15767c:	00000000 */ 	nop
/*  f157680:	0007000d */ 	break	0x7
.PF0f157684:
/*  f157684:	2401ffff */ 	li	$at,-1
/*  f157688:	17210004 */ 	bne	$t9,$at,.PF0f15769c
/*  f15768c:	3c018000 */ 	lui	$at,0x8000
/*  f157690:	17010002 */ 	bne	$t8,$at,.PF0f15769c
/*  f157694:	00000000 */ 	nop
/*  f157698:	0006000d */ 	break	0x6
.PF0f15769c:
/*  f15769c:	10000011 */ 	b	.PF0f1576e4
/*  f1576a0:	8fbf004c */ 	lw	$ra,0x4c($sp)
.PF0f1576a4:
/*  f1576a4:	3c098008 */ 	lui	$t1,0x8008
/*  f1576a8:	8d290020 */ 	lw	$t1,0x20($t1)
/*  f1576ac:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f1576b0:	0169001a */ 	div	$zero,$t3,$t1
/*  f1576b4:	00006012 */ 	mflo	$t4
/*  f1576b8:	ae2c0000 */ 	sw	$t4,0x0($s1)
/*  f1576bc:	15200002 */ 	bnez	$t1,.PF0f1576c8
/*  f1576c0:	00000000 */ 	nop
/*  f1576c4:	0007000d */ 	break	0x7
.PF0f1576c8:
/*  f1576c8:	2401ffff */ 	li	$at,-1
/*  f1576cc:	15210004 */ 	bne	$t1,$at,.PF0f1576e0
/*  f1576d0:	3c018000 */ 	lui	$at,0x8000
/*  f1576d4:	15610002 */ 	bne	$t3,$at,.PF0f1576e0
/*  f1576d8:	00000000 */ 	nop
/*  f1576dc:	0006000d */ 	break	0x6
.PF0f1576e0:
/*  f1576e0:	8fbf004c */ 	lw	$ra,0x4c($sp)
.PF0f1576e4:
/*  f1576e4:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f1576e8:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f1576ec:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f1576f0:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f1576f4:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f1576f8:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f1576fc:	03e00008 */ 	jr	$ra
/*  f157700:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);
#elif VERSION >= VERSION_PAL_BETA
GLOBAL_ASM(
glabel textRenderProjected
/*  f157840:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f157844:	3c0e8008 */ 	lui	$t6,0x8008
/*  f157848:	8dce1f98 */ 	lw	$t6,0x1f98($t6)
/*  f15784c:	afb50048 */ 	sw	$s5,0x48($sp)
/*  f157850:	afb30040 */ 	sw	$s3,0x40($sp)
/*  f157854:	afb10038 */ 	sw	$s1,0x38($sp)
/*  f157858:	afb00034 */ 	sw	$s0,0x34($sp)
/*  f15785c:	3c158008 */ 	lui	$s5,0x8008
/*  f157860:	00c08025 */ 	move	$s0,$a2
/*  f157864:	00a08825 */ 	move	$s1,$a1
/*  f157868:	00809825 */ 	move	$s3,$a0
/*  f15786c:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f157870:	afb40044 */ 	sw	$s4,0x44($sp)
/*  f157874:	afb2003c */ 	sw	$s2,0x3c($sp)
/*  f157878:	afa700b4 */ 	sw	$a3,0xb4($sp)
/*  f15787c:	11c0000a */ 	beqz	$t6,.PB0f1578a8
/*  f157880:	8eb51fa0 */ 	lw	$s5,0x1fa0($s5)
/*  f157884:	3c188008 */ 	lui	$t8,0x8008
/*  f157888:	8f181f90 */ 	lw	$t8,0x1f90($t8)
/*  f15788c:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f157890:	24150001 */ 	li	$s5,0x1
/*  f157894:	01f80019 */ 	multu	$t7,$t8
/*  f157898:	0000c812 */ 	mflo	$t9
/*  f15789c:	acd90000 */ 	sw	$t9,0x0($a2)
/*  f1578a0:	10000008 */ 	b	.PB0f1578c4
/*  f1578a4:	00000000 */ 	nop
.PB0f1578a8:
/*  f1578a8:	3c0a8008 */ 	lui	$t2,0x8008
/*  f1578ac:	8d4a1f90 */ 	lw	$t2,0x1f90($t2)
/*  f1578b0:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f1578b4:	012a0019 */ 	multu	$t1,$t2
/*  f1578b8:	00005812 */ 	mflo	$t3
/*  f1578bc:	ae2b0000 */ 	sw	$t3,0x0($s1)
/*  f1578c0:	00000000 */ 	nop
.PB0f1578c4:
/*  f1578c4:	3c0c8008 */ 	lui	$t4,0x8008
/*  f1578c8:	8d8c209c */ 	lw	$t4,0x209c($t4)
/*  f1578cc:	11800064 */ 	beqz	$t4,.PB0f157a60
/*  f1578d0:	3c014220 */ 	lui	$at,0x4220
/*  f1578d4:	44816000 */ 	mtc1	$at,$f12
/*  f1578d8:	0fc01abe */ 	jal	func0f006b08
/*  f1578dc:	00000000 */ 	nop
/*  f1578e0:	3c0e8008 */ 	lui	$t6,0x8008
/*  f1578e4:	8dce1f90 */ 	lw	$t6,0x1f90($t6)
/*  f1578e8:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f1578ec:	24090001 */ 	li	$t1,0x1
/*  f1578f0:	3c12800b */ 	lui	$s2,0x800b
/*  f1578f4:	01ae001a */ 	div	$zero,$t5,$t6
/*  f1578f8:	15c00002 */ 	bnez	$t6,.PB0f157904
/*  f1578fc:	00000000 */ 	nop
/*  f157900:	0007000d */ 	break	0x7
.PB0f157904:
/*  f157904:	2401ffff */ 	li	$at,-1
/*  f157908:	15c10004 */ 	bne	$t6,$at,.PB0f15791c
/*  f15790c:	3c018000 */ 	lui	$at,0x8000
/*  f157910:	15a10002 */ 	bne	$t5,$at,.PB0f15791c
/*  f157914:	00000000 */ 	nop
/*  f157918:	0006000d */ 	break	0x6
.PB0f15791c:
/*  f15791c:	3c013f80 */ 	lui	$at,0x3f80
/*  f157920:	44812000 */ 	mtc1	$at,$f4
/*  f157924:	3c0142c8 */ 	lui	$at,0x42c8
/*  f157928:	44814000 */ 	mtc1	$at,$f8
/*  f15792c:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f157930:	3c014316 */ 	lui	$at,0x4316
/*  f157934:	44818000 */ 	mtc1	$at,$f16
/*  f157938:	00007812 */ 	mflo	$t7
/*  f15793c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f157940:	afaf008c */ 	sw	$t7,0x8c($sp)
/*  f157944:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f157948:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f15794c:	3c058008 */ 	lui	$a1,0x8008
/*  f157950:	8e528c5c */ 	lw	$s2,-0x73a4($s2)
/*  f157954:	8faa00c0 */ 	lw	$t2,0xc0($sp)
/*  f157958:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f15795c:	24a520a0 */ 	addiu	$a1,$a1,0x20a0
/*  f157960:	248493e8 */ 	addiu	$a0,$a0,-27672
/*  f157964:	afb80088 */ 	sw	$t8,0x88($sp)
/*  f157968:	4459f800 */ 	cfc1	$t9,$31
/*  f15796c:	44c9f800 */ 	ctc1	$t1,$31
/*  f157970:	00000000 */ 	nop
/*  f157974:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f157978:	4449f800 */ 	cfc1	$t1,$31
/*  f15797c:	00000000 */ 	nop
/*  f157980:	31210004 */ 	andi	$at,$t1,0x4
/*  f157984:	31290078 */ 	andi	$t1,$t1,0x78
/*  f157988:	11200012 */ 	beqz	$t1,.PB0f1579d4
/*  f15798c:	3c014f00 */ 	lui	$at,0x4f00
/*  f157990:	44812000 */ 	mtc1	$at,$f4
/*  f157994:	24090001 */ 	li	$t1,0x1
/*  f157998:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f15799c:	44c9f800 */ 	ctc1	$t1,$31
/*  f1579a0:	00000000 */ 	nop
/*  f1579a4:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f1579a8:	4449f800 */ 	cfc1	$t1,$31
/*  f1579ac:	00000000 */ 	nop
/*  f1579b0:	31290078 */ 	andi	$t1,$t1,0x78
/*  f1579b4:	15200005 */ 	bnez	$t1,.PB0f1579cc
/*  f1579b8:	00000000 */ 	nop
/*  f1579bc:	44092000 */ 	mfc1	$t1,$f4
/*  f1579c0:	3c018000 */ 	lui	$at,0x8000
/*  f1579c4:	10000007 */ 	b	.PB0f1579e4
/*  f1579c8:	01214825 */ 	or	$t1,$t1,$at
.PB0f1579cc:
/*  f1579cc:	10000005 */ 	b	.PB0f1579e4
/*  f1579d0:	2409ffff */ 	li	$t1,-1
.PB0f1579d4:
/*  f1579d4:	44092000 */ 	mfc1	$t1,$f4
/*  f1579d8:	00000000 */ 	nop
/*  f1579dc:	0520fffb */ 	bltz	$t1,.PB0f1579cc
/*  f1579e0:	00000000 */ 	nop
.PB0f1579e4:
/*  f1579e4:	2401ff00 */ 	li	$at,-256
/*  f1579e8:	01415824 */ 	and	$t3,$t2,$at
/*  f1579ec:	01696025 */ 	or	$t4,$t3,$t1
/*  f1579f0:	44d9f800 */ 	ctc1	$t9,$31
/*  f1579f4:	0c003648 */ 	jal	mainOverrideVariable
/*  f1579f8:	afac0094 */ 	sw	$t4,0x94($sp)
/*  f1579fc:	3c028008 */ 	lui	$v0,0x8008
/*  f157a00:	8c4220a0 */ 	lw	$v0,0x20a0($v0)
/*  f157a04:	8fb400d0 */ 	lw	$s4,0xd0($sp)
/*  f157a08:	02602025 */ 	move	$a0,$s3
/*  f157a0c:	10400002 */ 	beqz	$v0,.PB0f157a18
/*  f157a10:	27a5008c */ 	addiu	$a1,$sp,0x8c
/*  f157a14:	00409025 */ 	move	$s2,$v0
.PB0f157a18:
/*  f157a18:	8fad00b8 */ 	lw	$t5,0xb8($sp)
/*  f157a1c:	8fae00bc */ 	lw	$t6,0xbc($sp)
/*  f157a20:	8faf0094 */ 	lw	$t7,0x94($sp)
/*  f157a24:	8fb800c4 */ 	lw	$t8,0xc4($sp)
/*  f157a28:	8fb900c8 */ 	lw	$t9,0xc8($sp)
/*  f157a2c:	8faa00cc */ 	lw	$t2,0xcc($sp)
/*  f157a30:	27a60088 */ 	addiu	$a2,$sp,0x88
/*  f157a34:	8fa700b4 */ 	lw	$a3,0xb4($sp)
/*  f157a38:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f157a3c:	afb4002c */ 	sw	$s4,0x2c($sp)
/*  f157a40:	afad0010 */ 	sw	$t5,0x10($sp)
/*  f157a44:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f157a48:	afaf0018 */ 	sw	$t7,0x18($sp)
/*  f157a4c:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f157a50:	afb90024 */ 	sw	$t9,0x24($sp)
/*  f157a54:	0fc56160 */ 	jal	textRender
/*  f157a58:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f157a5c:	00409825 */ 	move	$s3,$v0
.PB0f157a60:
/*  f157a60:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f157a64:	3c058008 */ 	lui	$a1,0x8008
/*  f157a68:	8fb400d0 */ 	lw	$s4,0xd0($sp)
/*  f157a6c:	24a5207c */ 	addiu	$a1,$a1,0x207c
/*  f157a70:	0c003648 */ 	jal	mainOverrideVariable
/*  f157a74:	248493f0 */ 	addiu	$a0,$a0,-27664
/*  f157a78:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f157a7c:	3c058008 */ 	lui	$a1,0x8008
/*  f157a80:	24a52088 */ 	addiu	$a1,$a1,0x2088
/*  f157a84:	0c003648 */ 	jal	mainOverrideVariable
/*  f157a88:	248493f8 */ 	addiu	$a0,$a0,-27656
/*  f157a8c:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f157a90:	3c058008 */ 	lui	$a1,0x8008
/*  f157a94:	24a5208c */ 	addiu	$a1,$a1,0x208c
/*  f157a98:	0c003648 */ 	jal	mainOverrideVariable
/*  f157a9c:	24849404 */ 	addiu	$a0,$a0,-27644
/*  f157aa0:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f157aa4:	3c058008 */ 	lui	$a1,0x8008
/*  f157aa8:	24a52094 */ 	addiu	$a1,$a1,0x2094
/*  f157aac:	0c003648 */ 	jal	mainOverrideVariable
/*  f157ab0:	24849410 */ 	addiu	$a0,$a0,-27632
/*  f157ab4:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f157ab8:	3c058008 */ 	lui	$a1,0x8008
/*  f157abc:	24a52090 */ 	addiu	$a1,$a1,0x2090
/*  f157ac0:	0c003648 */ 	jal	mainOverrideVariable
/*  f157ac4:	24849418 */ 	addiu	$a0,$a0,-27624
/*  f157ac8:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f157acc:	3c058008 */ 	lui	$a1,0x8008
/*  f157ad0:	24a52080 */ 	addiu	$a1,$a1,0x2080
/*  f157ad4:	0c003648 */ 	jal	mainOverrideVariable
/*  f157ad8:	24849420 */ 	addiu	$a0,$a0,-27616
/*  f157adc:	3c047f1c */ 	lui	$a0,0x7f1c
/*  f157ae0:	3c058008 */ 	lui	$a1,0x8008
/*  f157ae4:	24a52084 */ 	addiu	$a1,$a1,0x2084
/*  f157ae8:	0c003648 */ 	jal	mainOverrideVariable
/*  f157aec:	24849428 */ 	addiu	$a0,$a0,-27608
/*  f157af0:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f157af4:	8e320000 */ 	lw	$s2,0x0($s1)
/*  f157af8:	24090048 */ 	li	$t1,0x48
/*  f157afc:	a3a9009f */ 	sb	$t1,0x9f($sp)
/*  f157b00:	16800005 */ 	bnez	$s4,.PB0f157b18
/*  f157b04:	afab00a0 */ 	sw	$t3,0xa0($sp)
/*  f157b08:	8fac00b8 */ 	lw	$t4,0xb8($sp)
/*  f157b0c:	818d0445 */ 	lb	$t5,0x445($t4)
/*  f157b10:	918e0446 */ 	lbu	$t6,0x446($t4)
/*  f157b14:	01aea021 */ 	addu	$s4,$t5,$t6
.PB0f157b18:
/*  f157b18:	3c0f8008 */ 	lui	$t7,0x8008
/*  f157b1c:	8def65f0 */ 	lw	$t7,0x65f0($t7)
/*  f157b20:	02601025 */ 	move	$v0,$s3
/*  f157b24:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157b28:	11e00005 */ 	beqz	$t7,.PB0f157b40
/*  f157b2c:	3c18e700 */ 	lui	$t8,0xe700
/*  f157b30:	2a81000e */ 	slti	$at,$s4,0xe
/*  f157b34:	50200003 */ 	beqzl	$at,.PB0f157b44
/*  f157b38:	02601825 */ 	move	$v1,$s3
/*  f157b3c:	2414000e */ 	li	$s4,0xe
.PB0f157b40:
/*  f157b40:	02601825 */ 	move	$v1,$s3
.PB0f157b44:
/*  f157b44:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f157b48:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f157b4c:	3c19ba00 */ 	lui	$t9,0xba00
/*  f157b50:	37390e02 */ 	ori	$t9,$t9,0xe02
/*  f157b54:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157b58:	340ac000 */ 	li	$t2,0xc000
/*  f157b5c:	ac6a0004 */ 	sw	$t2,0x4($v1)
/*  f157b60:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f157b64:	02603825 */ 	move	$a3,$s3
/*  f157b68:	3c0bfd10 */ 	lui	$t3,0xfd10
/*  f157b6c:	aceb0000 */ 	sw	$t3,0x0($a3)
/*  f157b70:	3c048008 */ 	lui	$a0,0x8008
/*  f157b74:	2484200c */ 	addiu	$a0,$a0,0x200c
/*  f157b78:	afa70078 */ 	sw	$a3,0x78($sp)
/*  f157b7c:	0c012de0 */ 	jal	osVirtualToPhysical
/*  f157b80:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157b84:	8fa70078 */ 	lw	$a3,0x78($sp)
/*  f157b88:	02601825 */ 	move	$v1,$s3
/*  f157b8c:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157b90:	ace20004 */ 	sw	$v0,0x4($a3)
/*  f157b94:	3c09e600 */ 	lui	$t1,0xe600
/*  f157b98:	02602025 */ 	move	$a0,$s3
/*  f157b9c:	ac690000 */ 	sw	$t1,0x0($v1)
/*  f157ba0:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f157ba4:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157ba8:	3c0d0603 */ 	lui	$t5,0x603
/*  f157bac:	35adc000 */ 	ori	$t5,$t5,0xc000
/*  f157bb0:	3c0cf000 */ 	lui	$t4,0xf000
/*  f157bb4:	02602825 */ 	move	$a1,$s3
/*  f157bb8:	ac8c0000 */ 	sw	$t4,0x0($a0)
/*  f157bbc:	ac8d0004 */ 	sw	$t5,0x4($a0)
/*  f157bc0:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157bc4:	3c0ef540 */ 	lui	$t6,0xf540
/*  f157bc8:	35ce0200 */ 	ori	$t6,$t6,0x200
/*  f157bcc:	02603025 */ 	move	$a2,$s3
/*  f157bd0:	acae0000 */ 	sw	$t6,0x0($a1)
/*  f157bd4:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f157bd8:	3c180007 */ 	lui	$t8,0x7
/*  f157bdc:	3718c07c */ 	ori	$t8,$t8,0xc07c
/*  f157be0:	3c0ff200 */ 	lui	$t7,0xf200
/*  f157be4:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f157be8:	acd80004 */ 	sw	$t8,0x4($a2)
/*  f157bec:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157bf0:	8fa400c0 */ 	lw	$a0,0xc0($sp)
/*  f157bf4:	02604025 */ 	move	$t0,$s3
/*  f157bf8:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157bfc:	3c19fa00 */ 	lui	$t9,0xfa00
/*  f157c00:	ad190000 */ 	sw	$t9,0x0($t0)
/*  f157c04:	02601025 */ 	move	$v0,$s3
/*  f157c08:	ad040004 */ 	sw	$a0,0x4($t0)
/*  f157c0c:	3c0ae700 */ 	lui	$t2,0xe700
/*  f157c10:	ac4a0000 */ 	sw	$t2,0x0($v0)
/*  f157c14:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f157c18:	8fab00b4 */ 	lw	$t3,0xb4($sp)
/*  f157c1c:	3c03800b */ 	lui	$v1,0x800b
/*  f157c20:	24638bf0 */ 	addiu	$v1,$v1,-29712
/*  f157c24:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f157c28:	ac640004 */ 	sw	$a0,0x4($v1)
/*  f157c2c:	11600047 */ 	beqz	$t3,.PB0f157d4c
/*  f157c30:	ac640044 */ 	sw	$a0,0x44($v1)
/*  f157c34:	91620000 */ 	lbu	$v0,0x0($t3)
/*  f157c38:	10400044 */ 	beqz	$v0,.PB0f157d4c
/*  f157c3c:	00000000 */ 	nop
/*  f157c40:	24010020 */ 	li	$at,0x20
.PB0f157c44:
/*  f157c44:	5441000d */ 	bnel	$v0,$at,.PB0f157c7c
/*  f157c48:	2401000a */ 	li	$at,0xa
/*  f157c4c:	8e290000 */ 	lw	$t1,0x0($s1)
/*  f157c50:	00156080 */ 	sll	$t4,$s5,0x2
/*  f157c54:	01956021 */ 	addu	$t4,$t4,$s5
/*  f157c58:	012c6821 */ 	addu	$t5,$t1,$t4
/*  f157c5c:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f157c60:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f157c64:	240e0048 */ 	li	$t6,0x48
/*  f157c68:	a3ae009f */ 	sb	$t6,0x9f($sp)
/*  f157c6c:	25f80001 */ 	addiu	$t8,$t7,0x1
/*  f157c70:	10000032 */ 	b	.PB0f157d3c
/*  f157c74:	afb800b4 */ 	sw	$t8,0xb4($sp)
/*  f157c78:	2401000a */ 	li	$at,0xa
.PB0f157c7c:
/*  f157c7c:	14410015 */ 	bne	$v0,$at,.PB0f157cd4
/*  f157c80:	3c028008 */ 	lui	$v0,0x8008
/*  f157c84:	8c421fa4 */ 	lw	$v0,0x1fa4($v0)
/*  f157c88:	04420009 */ 	bltzl	$v0,.PB0f157cb0
/*  f157c8c:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f157c90:	8e390000 */ 	lw	$t9,0x0($s1)
/*  f157c94:	56590006 */ 	bnel	$s2,$t9,.PB0f157cb0
/*  f157c98:	8e090000 */ 	lw	$t1,0x0($s0)
/*  f157c9c:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f157ca0:	01425821 */ 	addu	$t3,$t2,$v0
/*  f157ca4:	10000004 */ 	b	.PB0f157cb8
/*  f157ca8:	ae0b0000 */ 	sw	$t3,0x0($s0)
/*  f157cac:	8e090000 */ 	lw	$t1,0x0($s0)
.PB0f157cb0:
/*  f157cb0:	01346021 */ 	addu	$t4,$t1,$s4
/*  f157cb4:	ae0c0000 */ 	sw	$t4,0x0($s0)
.PB0f157cb8:
/*  f157cb8:	ae320000 */ 	sw	$s2,0x0($s1)
/*  f157cbc:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f157cc0:	240d0048 */ 	li	$t5,0x48
/*  f157cc4:	a3ad009f */ 	sb	$t5,0x9f($sp)
/*  f157cc8:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f157ccc:	1000001b */ 	b	.PB0f157d3c
/*  f157cd0:	afaf00b4 */ 	sw	$t7,0xb4($sp)
.PB0f157cd4:
/*  f157cd4:	27b8009f */ 	addiu	$t8,$sp,0x9f
/*  f157cd8:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f157cdc:	27a400b4 */ 	addiu	$a0,$sp,0xb4
/*  f157ce0:	27a5005c */ 	addiu	$a1,$sp,0x5c
/*  f157ce4:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f157ce8:	0fc5590b */ 	jal	textMapCodeUnitToChar
/*  f157cec:	8fa700b8 */ 	lw	$a3,0xb8($sp)
/*  f157cf0:	8fb90058 */ 	lw	$t9,0x58($sp)
/*  f157cf4:	8faa00bc */ 	lw	$t2,0xbc($sp)
/*  f157cf8:	8fab00a0 */ 	lw	$t3,0xa0($sp)
/*  f157cfc:	8fa900c4 */ 	lw	$t1,0xc4($sp)
/*  f157d00:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*  f157d04:	8fad00cc */ 	lw	$t5,0xcc($sp)
/*  f157d08:	02602025 */ 	move	$a0,$s3
/*  f157d0c:	02202825 */ 	move	$a1,$s1
/*  f157d10:	02003025 */ 	move	$a2,$s0
/*  f157d14:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f157d18:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f157d1c:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f157d20:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f157d24:	afab001c */ 	sw	$t3,0x1c($sp)
/*  f157d28:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f157d2c:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f157d30:	0fc55ba0 */ 	jal	func0f15568c
/*  f157d34:	afad0028 */ 	sw	$t5,0x28($sp)
/*  f157d38:	00409825 */ 	move	$s3,$v0
.PB0f157d3c:
/*  f157d3c:	8fae00b4 */ 	lw	$t6,0xb4($sp)
/*  f157d40:	91c20000 */ 	lbu	$v0,0x0($t6)
/*  f157d44:	5440ffbf */ 	bnezl	$v0,.PB0f157c44
/*  f157d48:	24010020 */ 	li	$at,0x20
.PB0f157d4c:
/*  f157d4c:	3c0f8008 */ 	lui	$t7,0x8008
/*  f157d50:	8def1f98 */ 	lw	$t7,0x1f98($t7)
/*  f157d54:	02601025 */ 	move	$v0,$s3
/*  f157d58:	11e00012 */ 	beqz	$t7,.PB0f157da4
/*  f157d5c:	00000000 */ 	nop
/*  f157d60:	3c198008 */ 	lui	$t9,0x8008
/*  f157d64:	8f391f90 */ 	lw	$t9,0x1f90($t9)
/*  f157d68:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f157d6c:	0319001a */ 	div	$zero,$t8,$t9
/*  f157d70:	00005012 */ 	mflo	$t2
/*  f157d74:	ae0a0000 */ 	sw	$t2,0x0($s0)
/*  f157d78:	17200002 */ 	bnez	$t9,.PB0f157d84
/*  f157d7c:	00000000 */ 	nop
/*  f157d80:	0007000d */ 	break	0x7
.PB0f157d84:
/*  f157d84:	2401ffff */ 	li	$at,-1
/*  f157d88:	17210004 */ 	bne	$t9,$at,.PB0f157d9c
/*  f157d8c:	3c018000 */ 	lui	$at,0x8000
/*  f157d90:	17010002 */ 	bne	$t8,$at,.PB0f157d9c
/*  f157d94:	00000000 */ 	nop
/*  f157d98:	0006000d */ 	break	0x6
.PB0f157d9c:
/*  f157d9c:	10000011 */ 	b	.PB0f157de4
/*  f157da0:	8fbf004c */ 	lw	$ra,0x4c($sp)
.PB0f157da4:
/*  f157da4:	3c098008 */ 	lui	$t1,0x8008
/*  f157da8:	8d291f90 */ 	lw	$t1,0x1f90($t1)
/*  f157dac:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f157db0:	0169001a */ 	div	$zero,$t3,$t1
/*  f157db4:	00006012 */ 	mflo	$t4
/*  f157db8:	ae2c0000 */ 	sw	$t4,0x0($s1)
/*  f157dbc:	15200002 */ 	bnez	$t1,.PB0f157dc8
/*  f157dc0:	00000000 */ 	nop
/*  f157dc4:	0007000d */ 	break	0x7
.PB0f157dc8:
/*  f157dc8:	2401ffff */ 	li	$at,-1
/*  f157dcc:	15210004 */ 	bne	$t1,$at,.PB0f157de0
/*  f157dd0:	3c018000 */ 	lui	$at,0x8000
/*  f157dd4:	15610002 */ 	bne	$t3,$at,.PB0f157de0
/*  f157dd8:	00000000 */ 	nop
/*  f157ddc:	0006000d */ 	break	0x6
.PB0f157de0:
/*  f157de0:	8fbf004c */ 	lw	$ra,0x4c($sp)
.PB0f157de4:
/*  f157de4:	8fb00034 */ 	lw	$s0,0x34($sp)
/*  f157de8:	8fb10038 */ 	lw	$s1,0x38($sp)
/*  f157dec:	8fb2003c */ 	lw	$s2,0x3c($sp)
/*  f157df0:	8fb30040 */ 	lw	$s3,0x40($sp)
/*  f157df4:	8fb40044 */ 	lw	$s4,0x44($sp)
/*  f157df8:	8fb50048 */ 	lw	$s5,0x48($sp)
/*  f157dfc:	03e00008 */ 	jr	$ra
/*  f157e00:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);
#else
GLOBAL_ASM(
glabel textRenderProjected
/*  f15603c:	27bdff40 */ 	addiu	$sp,$sp,-192
/*  f156040:	3c0f8008 */ 	lui	$t7,%hi(g_TextRotated90)
/*  f156044:	8deffac8 */ 	lw	$t7,%lo(g_TextRotated90)($t7)
/*  f156048:	3c0e8008 */ 	lui	$t6,%hi(var8007fad0)
/*  f15604c:	8dcefad0 */ 	lw	$t6,%lo(var8007fad0)($t6)
/*  f156050:	afb5004c */ 	sw	$s5,0x4c($sp)
/*  f156054:	afb40048 */ 	sw	$s4,0x48($sp)
/*  f156058:	afb30044 */ 	sw	$s3,0x44($sp)
/*  f15605c:	afb00038 */ 	sw	$s0,0x38($sp)
/*  f156060:	00e08025 */ 	or	$s0,$a3,$zero
/*  f156064:	00c09825 */ 	or	$s3,$a2,$zero
/*  f156068:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f15606c:	0080a825 */ 	or	$s5,$a0,$zero
/*  f156070:	afbf005c */ 	sw	$ra,0x5c($sp)
/*  f156074:	afbe0058 */ 	sw	$s8,0x58($sp)
/*  f156078:	afb70054 */ 	sw	$s7,0x54($sp)
/*  f15607c:	afb60050 */ 	sw	$s6,0x50($sp)
/*  f156080:	afb20040 */ 	sw	$s2,0x40($sp)
/*  f156084:	afb1003c */ 	sw	$s1,0x3c($sp)
/*  f156088:	11e0000a */ 	beqz	$t7,.L0f1560b4
/*  f15608c:	afae00b0 */ 	sw	$t6,0xb0($sp)
/*  f156090:	3c198008 */ 	lui	$t9,%hi(g_ScaleX)
/*  f156094:	8f39fac0 */ 	lw	$t9,%lo(g_ScaleX)($t9)
/*  f156098:	8cd80000 */ 	lw	$t8,0x0($a2)
/*  f15609c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f1560a0:	03190019 */ 	multu	$t8,$t9
/*  f1560a4:	00004012 */ 	mflo	$t0
/*  f1560a8:	acc80000 */ 	sw	$t0,0x0($a2)
/*  f1560ac:	10000008 */ 	b	.L0f1560d0
/*  f1560b0:	afa900b0 */ 	sw	$t1,0xb0($sp)
.L0f1560b4:
/*  f1560b4:	3c0b8008 */ 	lui	$t3,%hi(g_ScaleX)
/*  f1560b8:	8d6bfac0 */ 	lw	$t3,%lo(g_ScaleX)($t3)
/*  f1560bc:	8e8a0000 */ 	lw	$t2,0x0($s4)
/*  f1560c0:	014b0019 */ 	multu	$t2,$t3
/*  f1560c4:	00006012 */ 	mflo	$t4
/*  f1560c8:	ae8c0000 */ 	sw	$t4,0x0($s4)
/*  f1560cc:	00000000 */ 	nop
.L0f1560d0:
/*  f1560d0:	3c0d8008 */ 	lui	$t5,%hi(var8007fbd8)
/*  f1560d4:	8dadfbd8 */ 	lw	$t5,%lo(var8007fbd8)($t5)
/*  f1560d8:	11a00062 */ 	beqz	$t5,.L0f156264
/*  f1560dc:	3c014220 */ 	lui	$at,0x4220
/*  f1560e0:	44816000 */ 	mtc1	$at,$f12
/*  f1560e4:	0fc01ac2 */ 	jal	func0f006b08
/*  f1560e8:	00000000 */ 	nop
/*  f1560ec:	3c0f8008 */ 	lui	$t7,%hi(g_ScaleX)
/*  f1560f0:	8deffac0 */ 	lw	$t7,%lo(g_ScaleX)($t7)
/*  f1560f4:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*  f1560f8:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f1560fc:	3c11800a */ 	lui	$s1,%hi(var800a463c)
/*  f156100:	01cf001a */ 	div	$zero,$t6,$t7
/*  f156104:	15e00002 */ 	bnez	$t7,.L0f156110
/*  f156108:	00000000 */ 	nop
/*  f15610c:	0007000d */ 	break	0x7
.L0f156110:
/*  f156110:	2401ffff */ 	addiu	$at,$zero,-1
/*  f156114:	15e10004 */ 	bne	$t7,$at,.L0f156128
/*  f156118:	3c018000 */ 	lui	$at,0x8000
/*  f15611c:	15c10002 */ 	bne	$t6,$at,.L0f156128
/*  f156120:	00000000 */ 	nop
/*  f156124:	0006000d */ 	break	0x6
.L0f156128:
/*  f156128:	3c013f80 */ 	lui	$at,0x3f80
/*  f15612c:	44812000 */ 	mtc1	$at,$f4
/*  f156130:	3c0142c8 */ 	lui	$at,0x42c8
/*  f156134:	44814000 */ 	mtc1	$at,$f8
/*  f156138:	46002181 */ 	sub.s	$f6,$f4,$f0
/*  f15613c:	3c014316 */ 	lui	$at,0x4316
/*  f156140:	44818000 */ 	mtc1	$at,$f16
/*  f156144:	0000c012 */ 	mflo	$t8
/*  f156148:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f15614c:	afb800a4 */ 	sw	$t8,0xa4($sp)
/*  f156150:	8e790000 */ 	lw	$t9,0x0($s3)
/*  f156154:	3c047f1b */ 	lui	$a0,%hi(var7f1b73b8)
/*  f156158:	3c058008 */ 	lui	$a1,%hi(var8007fbe8)
/*  f15615c:	8e31463c */ 	lw	$s1,%lo(var800a463c)($s1)
/*  f156160:	8faa00d8 */ 	lw	$t2,0xd8($sp)
/*  f156164:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f156168:	24a5fbe8 */ 	addiu	$a1,$a1,%lo(var8007fbe8)
/*  f15616c:	248473b8 */ 	addiu	$a0,$a0,%lo(var7f1b73b8)
/*  f156170:	afb900a0 */ 	sw	$t9,0xa0($sp)
/*  f156174:	4448f800 */ 	cfc1	$t0,$31
/*  f156178:	44c9f800 */ 	ctc1	$t1,$31
/*  f15617c:	00000000 */ 	nop
/*  f156180:	46009124 */ 	cvt.w.s	$f4,$f18
/*  f156184:	4449f800 */ 	cfc1	$t1,$31
/*  f156188:	00000000 */ 	nop
/*  f15618c:	31210004 */ 	andi	$at,$t1,0x4
/*  f156190:	31290078 */ 	andi	$t1,$t1,0x78
/*  f156194:	11200012 */ 	beqz	$t1,.L0f1561e0
/*  f156198:	3c014f00 */ 	lui	$at,0x4f00
/*  f15619c:	44812000 */ 	mtc1	$at,$f4
/*  f1561a0:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f1561a4:	46049101 */ 	sub.s	$f4,$f18,$f4
/*  f1561a8:	44c9f800 */ 	ctc1	$t1,$31
/*  f1561ac:	00000000 */ 	nop
/*  f1561b0:	46002124 */ 	cvt.w.s	$f4,$f4
/*  f1561b4:	4449f800 */ 	cfc1	$t1,$31
/*  f1561b8:	00000000 */ 	nop
/*  f1561bc:	31290078 */ 	andi	$t1,$t1,0x78
/*  f1561c0:	15200005 */ 	bnez	$t1,.L0f1561d8
/*  f1561c4:	00000000 */ 	nop
/*  f1561c8:	44092000 */ 	mfc1	$t1,$f4
/*  f1561cc:	3c018000 */ 	lui	$at,0x8000
/*  f1561d0:	10000007 */ 	b	.L0f1561f0
/*  f1561d4:	01214825 */ 	or	$t1,$t1,$at
.L0f1561d8:
/*  f1561d8:	10000005 */ 	b	.L0f1561f0
/*  f1561dc:	2409ffff */ 	addiu	$t1,$zero,-1
.L0f1561e0:
/*  f1561e0:	44092000 */ 	mfc1	$t1,$f4
/*  f1561e4:	00000000 */ 	nop
/*  f1561e8:	0520fffb */ 	bltz	$t1,.L0f1561d8
/*  f1561ec:	00000000 */ 	nop
.L0f1561f0:
/*  f1561f0:	2401ff00 */ 	addiu	$at,$zero,-256
/*  f1561f4:	01415824 */ 	and	$t3,$t2,$at
/*  f1561f8:	44c8f800 */ 	ctc1	$t0,$31
/*  f1561fc:	0c0036cc */ 	jal	mainOverrideVariable
/*  f156200:	01699025 */ 	or	$s2,$t3,$t1
/*  f156204:	3c028008 */ 	lui	$v0,%hi(var8007fbe8)
/*  f156208:	8c42fbe8 */ 	lw	$v0,%lo(var8007fbe8)($v0)
/*  f15620c:	02a02025 */ 	or	$a0,$s5,$zero
/*  f156210:	27a500a4 */ 	addiu	$a1,$sp,0xa4
/*  f156214:	10400002 */ 	beqz	$v0,.L0f156220
/*  f156218:	27a600a0 */ 	addiu	$a2,$sp,0xa0
/*  f15621c:	00408825 */ 	or	$s1,$v0,$zero
.L0f156220:
/*  f156220:	8fac00d0 */ 	lw	$t4,0xd0($sp)
/*  f156224:	8fad00d4 */ 	lw	$t5,0xd4($sp)
/*  f156228:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*  f15622c:	8faf00e0 */ 	lw	$t7,0xe0($sp)
/*  f156230:	8fb800e4 */ 	lw	$t8,0xe4($sp)
/*  f156234:	8fb900e8 */ 	lw	$t9,0xe8($sp)
/*  f156238:	02003825 */ 	or	$a3,$s0,$zero
/*  f15623c:	afb20018 */ 	sw	$s2,0x18($sp)
/*  f156240:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f156244:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f156248:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f15624c:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f156250:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f156254:	afb80028 */ 	sw	$t8,0x28($sp)
/*  f156258:	0fc55b92 */ 	jal	textRender
/*  f15625c:	afb9002c */ 	sw	$t9,0x2c($sp)
/*  f156260:	0040a825 */ 	or	$s5,$v0,$zero
.L0f156264:
/*  f156264:	3c047f1b */ 	lui	$a0,%hi(var7f1b73c0)
/*  f156268:	3c058008 */ 	lui	$a1,%hi(var8007fbac)
/*  f15626c:	24a5fbac */ 	addiu	$a1,$a1,%lo(var8007fbac)
/*  f156270:	0c0036cc */ 	jal	mainOverrideVariable
/*  f156274:	248473c0 */ 	addiu	$a0,$a0,%lo(var7f1b73c0)
/*  f156278:	3c047f1b */ 	lui	$a0,%hi(var7f1b73c8)
/*  f15627c:	3c058008 */ 	lui	$a1,%hi(var8007fbb8)
/*  f156280:	24a5fbb8 */ 	addiu	$a1,$a1,%lo(var8007fbb8)
/*  f156284:	0c0036cc */ 	jal	mainOverrideVariable
/*  f156288:	248473c8 */ 	addiu	$a0,$a0,%lo(var7f1b73c8)
/*  f15628c:	3c047f1b */ 	lui	$a0,%hi(var7f1b73d4)
/*  f156290:	3c058008 */ 	lui	$a1,%hi(var8007fbbc)
/*  f156294:	24a5fbbc */ 	addiu	$a1,$a1,%lo(var8007fbbc)
/*  f156298:	0c0036cc */ 	jal	mainOverrideVariable
/*  f15629c:	248473d4 */ 	addiu	$a0,$a0,%lo(var7f1b73d4)
/*  f1562a0:	3c047f1b */ 	lui	$a0,%hi(var7f1b73e0)
/*  f1562a4:	3c058008 */ 	lui	$a1,%hi(var8007fbc4)
/*  f1562a8:	24a5fbc4 */ 	addiu	$a1,$a1,%lo(var8007fbc4)
/*  f1562ac:	0c0036cc */ 	jal	mainOverrideVariable
/*  f1562b0:	248473e0 */ 	addiu	$a0,$a0,%lo(var7f1b73e0)
/*  f1562b4:	3c047f1b */ 	lui	$a0,%hi(var7f1b73e8)
/*  f1562b8:	3c058008 */ 	lui	$a1,%hi(var8007fbc0)
/*  f1562bc:	24a5fbc0 */ 	addiu	$a1,$a1,%lo(var8007fbc0)
/*  f1562c0:	0c0036cc */ 	jal	mainOverrideVariable
/*  f1562c4:	248473e8 */ 	addiu	$a0,$a0,%lo(var7f1b73e8)
/*  f1562c8:	3c047f1b */ 	lui	$a0,%hi(var7f1b73f0)
/*  f1562cc:	3c058008 */ 	lui	$a1,%hi(var8007fbb0)
/*  f1562d0:	24a5fbb0 */ 	addiu	$a1,$a1,%lo(var8007fbb0)
/*  f1562d4:	0c0036cc */ 	jal	mainOverrideVariable
/*  f1562d8:	248473f0 */ 	addiu	$a0,$a0,%lo(var7f1b73f0)
/*  f1562dc:	3c047f1b */ 	lui	$a0,%hi(var7f1b73f8)
/*  f1562e0:	3c058008 */ 	lui	$a1,%hi(var8007fbb4)
/*  f1562e4:	24a5fbb4 */ 	addiu	$a1,$a1,%lo(var8007fbb4)
/*  f1562e8:	0c0036cc */ 	jal	mainOverrideVariable
/*  f1562ec:	248473f8 */ 	addiu	$a0,$a0,%lo(var7f1b73f8)
/*  f1562f0:	8fa800e8 */ 	lw	$t0,0xe8($sp)
/*  f1562f4:	8e910000 */ 	lw	$s1,0x0($s4)
/*  f1562f8:	8e7e0000 */ 	lw	$s8,0x0($s3)
/*  f1562fc:	15000006 */ 	bnez	$t0,.L0f156318
/*  f156300:	24120048 */ 	addiu	$s2,$zero,0x48
/*  f156304:	8faa00d0 */ 	lw	$t2,0xd0($sp)
/*  f156308:	814b0445 */ 	lb	$t3,0x445($t2)
/*  f15630c:	91490446 */ 	lbu	$t1,0x446($t2)
/*  f156310:	01696021 */ 	addu	$t4,$t3,$t1
/*  f156314:	afac00e8 */ 	sw	$t4,0xe8($sp)
.L0f156318:
/*  f156318:	3c0d8008 */ 	lui	$t5,%hi(g_Jpn)
/*  f15631c:	8dad4120 */ 	lw	$t5,%lo(g_Jpn)($t5)
/*  f156320:	02a01025 */ 	or	$v0,$s5,$zero
/*  f156324:	3c17e700 */ 	lui	$s7,0xe700
/*  f156328:	11a00007 */ 	beqz	$t5,.L0f156348
/*  f15632c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f156330:	8fae00e8 */ 	lw	$t6,0xe8($sp)
/*  f156334:	240f000e */ 	addiu	$t7,$zero,0xe
/*  f156338:	29c1000e */ 	slti	$at,$t6,0xe
/*  f15633c:	50200003 */ 	beqzl	$at,.L0f15634c
/*  f156340:	02a01825 */ 	or	$v1,$s5,$zero
/*  f156344:	afaf00e8 */ 	sw	$t7,0xe8($sp)
.L0f156348:
/*  f156348:	02a01825 */ 	or	$v1,$s5,$zero
.L0f15634c:
/*  f15634c:	ac570000 */ 	sw	$s7,0x0($v0)
/*  f156350:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f156354:	3c18ba00 */ 	lui	$t8,0xba00
/*  f156358:	37180e02 */ 	ori	$t8,$t8,0xe02
/*  f15635c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f156360:	3419c000 */ 	dli	$t9,0xc000
/*  f156364:	ac790004 */ 	sw	$t9,0x4($v1)
/*  f156368:	ac780000 */ 	sw	$t8,0x0($v1)
/*  f15636c:	02a0b025 */ 	or	$s6,$s5,$zero
/*  f156370:	3c08fd10 */ 	lui	$t0,0xfd10
/*  f156374:	3c048008 */ 	lui	$a0,%hi(var8007fb3c)
/*  f156378:	2484fb3c */ 	addiu	$a0,$a0,%lo(var8007fb3c)
/*  f15637c:	aec80000 */ 	sw	$t0,0x0($s6)
/*  f156380:	0c012d20 */ 	jal	osVirtualToPhysical
/*  f156384:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f156388:	02a01825 */ 	or	$v1,$s5,$zero
/*  f15638c:	aec20004 */ 	sw	$v0,0x4($s6)
/*  f156390:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f156394:	3c0ae600 */ 	lui	$t2,0xe600
/*  f156398:	02a02025 */ 	or	$a0,$s5,$zero
/*  f15639c:	ac6a0000 */ 	sw	$t2,0x0($v1)
/*  f1563a0:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f1563a4:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1563a8:	3c090603 */ 	lui	$t1,0x603
/*  f1563ac:	3529c000 */ 	ori	$t1,$t1,0xc000
/*  f1563b0:	3c0bf000 */ 	lui	$t3,0xf000
/*  f1563b4:	02a02825 */ 	or	$a1,$s5,$zero
/*  f1563b8:	ac8b0000 */ 	sw	$t3,0x0($a0)
/*  f1563bc:	ac890004 */ 	sw	$t1,0x4($a0)
/*  f1563c0:	3c0cf540 */ 	lui	$t4,0xf540
/*  f1563c4:	358c0200 */ 	ori	$t4,$t4,0x200
/*  f1563c8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1563cc:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f1563d0:	aca00004 */ 	sw	$zero,0x4($a1)
/*  f1563d4:	02a03025 */ 	or	$a2,$s5,$zero
/*  f1563d8:	3c0e0007 */ 	lui	$t6,0x7
/*  f1563dc:	35cec07c */ 	ori	$t6,$t6,0xc07c
/*  f1563e0:	3c0df200 */ 	lui	$t5,0xf200
/*  f1563e4:	accd0000 */ 	sw	$t5,0x0($a2)
/*  f1563e8:	acce0004 */ 	sw	$t6,0x4($a2)
/*  f1563ec:	8fa400d8 */ 	lw	$a0,0xd8($sp)
/*  f1563f0:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1563f4:	02a03825 */ 	or	$a3,$s5,$zero
/*  f1563f8:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f1563fc:	3c0ffa00 */ 	lui	$t7,0xfa00
/*  f156400:	acef0000 */ 	sw	$t7,0x0($a3)
/*  f156404:	02a01025 */ 	or	$v0,$s5,$zero
/*  f156408:	ace40004 */ 	sw	$a0,0x4($a3)
/*  f15640c:	3c03800a */ 	lui	$v1,%hi(var800a45d0)
/*  f156410:	246345d0 */ 	addiu	$v1,$v1,%lo(var800a45d0)
/*  f156414:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f156418:	ac570000 */ 	sw	$s7,0x0($v0)
/*  f15641c:	26b50008 */ 	addiu	$s5,$s5,0x8
/*  f156420:	ac640004 */ 	sw	$a0,0x4($v1)
/*  f156424:	12000078 */ 	beqz	$s0,.L0f156608
/*  f156428:	ac640044 */ 	sw	$a0,0x44($v1)
/*  f15642c:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f156430:	10400075 */ 	beqz	$v0,.L0f156608
/*  f156434:	00000000 */ 	nop
/*  f156438:	2417000c */ 	addiu	$s7,$zero,0xc
/*  f15643c:	27b60068 */ 	addiu	$s6,$sp,0x68
/*  f156440:	24010020 */ 	addiu	$at,$zero,0x20
.L0f156444:
/*  f156444:	5441000b */ 	bnel	$v0,$at,.L0f156474
/*  f156448:	2401000a */ 	addiu	$at,$zero,0xa
/*  f15644c:	8fb900b0 */ 	lw	$t9,0xb0($sp)
/*  f156450:	8e980000 */ 	lw	$t8,0x0($s4)
/*  f156454:	24120048 */ 	addiu	$s2,$zero,0x48
/*  f156458:	00194080 */ 	sll	$t0,$t9,0x2
/*  f15645c:	01194021 */ 	addu	$t0,$t0,$t9
/*  f156460:	03085021 */ 	addu	$t2,$t8,$t0
/*  f156464:	ae8a0000 */ 	sw	$t2,0x0($s4)
/*  f156468:	10000064 */ 	b	.L0f1565fc
/*  f15646c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f156470:	2401000a */ 	addiu	$at,$zero,0xa
.L0f156474:
/*  f156474:	54410015 */ 	bnel	$v0,$at,.L0f1564cc
/*  f156478:	28410080 */ 	slti	$at,$v0,0x80
/*  f15647c:	3c028008 */ 	lui	$v0,%hi(var8007fad4)
/*  f156480:	8c42fad4 */ 	lw	$v0,%lo(var8007fad4)($v0)
/*  f156484:	24120048 */ 	addiu	$s2,$zero,0x48
/*  f156488:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15648c:	04420009 */ 	bltzl	$v0,.L0f1564b4
/*  f156490:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f156494:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*  f156498:	562b0006 */ 	bnel	$s1,$t3,.L0f1564b4
/*  f15649c:	8e6d0000 */ 	lw	$t5,0x0($s3)
/*  f1564a0:	8e690000 */ 	lw	$t1,0x0($s3)
/*  f1564a4:	01226021 */ 	addu	$t4,$t1,$v0
/*  f1564a8:	10000005 */ 	b	.L0f1564c0
/*  f1564ac:	ae6c0000 */ 	sw	$t4,0x0($s3)
/*  f1564b0:	8e6d0000 */ 	lw	$t5,0x0($s3)
.L0f1564b4:
/*  f1564b4:	8fae00e8 */ 	lw	$t6,0xe8($sp)
/*  f1564b8:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f1564bc:	ae6f0000 */ 	sw	$t7,0x0($s3)
.L0f1564c0:
/*  f1564c0:	1000004e */ 	b	.L0f1565fc
/*  f1564c4:	ae910000 */ 	sw	$s1,0x0($s4)
/*  f1564c8:	28410080 */ 	slti	$at,$v0,0x80
.L0f1564cc:
/*  f1564cc:	1020001d */ 	beqz	$at,.L0f156544
/*  f1564d0:	3059007f */ 	andi	$t9,$v0,0x7f
/*  f1564d4:	00570019 */ 	multu	$v0,$s7
/*  f1564d8:	8fa300d0 */ 	lw	$v1,0xd0($sp)
/*  f1564dc:	8fab00d4 */ 	lw	$t3,0xd4($sp)
/*  f1564e0:	8fa900dc */ 	lw	$t1,0xdc($sp)
/*  f1564e4:	8fac00e0 */ 	lw	$t4,0xe0($sp)
/*  f1564e8:	8fad00e4 */ 	lw	$t5,0xe4($sp)
/*  f1564ec:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1564f0:	02802825 */ 	or	$a1,$s4,$zero
/*  f1564f4:	02603025 */ 	or	$a2,$s3,$zero
/*  f1564f8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1564fc:	0000c812 */ 	mflo	$t9
/*  f156500:	03233821 */ 	addu	$a3,$t9,$v1
/*  f156504:	24e7fe74 */ 	addiu	$a3,$a3,-396
/*  f156508:	02570019 */ 	multu	$s2,$s7
/*  f15650c:	afbe001c */ 	sw	$s8,0x1c($sp)
/*  f156510:	afab0014 */ 	sw	$t3,0x14($sp)
/*  f156514:	afa90020 */ 	sw	$t1,0x20($sp)
/*  f156518:	afac0024 */ 	sw	$t4,0x24($sp)
/*  f15651c:	afad0028 */ 	sw	$t5,0x28($sp)
/*  f156520:	0000c012 */ 	mflo	$t8
/*  f156524:	03034021 */ 	addu	$t0,$t8,$v1
/*  f156528:	250afe74 */ 	addiu	$t2,$t0,-396
/*  f15652c:	0fc555a3 */ 	jal	func0f15568c
/*  f156530:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f156534:	0040a825 */ 	or	$s5,$v0,$zero
/*  f156538:	92120000 */ 	lbu	$s2,0x0($s0)
/*  f15653c:	1000002f */ 	b	.L0f1565fc
/*  f156540:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f156544:
/*  f156544:	3c0a8008 */ 	lui	$t2,%hi(var8007fbdc)
/*  f156548:	254afbdc */ 	addiu	$t2,$t2,%lo(var8007fbdc)
/*  f15654c:	8d410000 */ 	lw	$at,0x0($t2)
/*  f156550:	920e0001 */ 	lbu	$t6,0x1($s0)
/*  f156554:	0019c1c0 */ 	sll	$t8,$t9,0x7
/*  f156558:	aec10000 */ 	sw	$at,0x0($s6)
/*  f15655c:	8d490004 */ 	lw	$t1,0x4($t2)
/*  f156560:	31cf007f */ 	andi	$t7,$t6,0x7f
/*  f156564:	01f81825 */ 	or	$v1,$t7,$t8
/*  f156568:	aec90004 */ 	sw	$t1,0x4($s6)
/*  f15656c:	8d410008 */ 	lw	$at,0x8($t2)
/*  f156570:	3064ffff */ 	andi	$a0,$v1,0xffff
/*  f156574:	308c2000 */ 	andi	$t4,$a0,0x2000
/*  f156578:	11800005 */ 	beqz	$t4,.L0f156590
/*  f15657c:	aec10008 */ 	sw	$at,0x8($s6)
/*  f156580:	240d000f */ 	addiu	$t5,$zero,0xf
/*  f156584:	240e0010 */ 	addiu	$t6,$zero,0x10
/*  f156588:	a3ad006b */ 	sb	$t5,0x6b($sp)
/*  f15658c:	a3ae006a */ 	sb	$t6,0x6a($sp)
.L0f156590:
/*  f156590:	30991fff */ 	andi	$t9,$a0,0x1fff
/*  f156594:	2b2103c8 */ 	slti	$at,$t9,0x3c8
/*  f156598:	54200003 */ 	bnezl	$at,.L0f1565a8
/*  f15659c:	248f0080 */ 	addiu	$t7,$a0,0x80
/*  f1565a0:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f1565a4:	248f0080 */ 	addiu	$t7,$a0,0x80
.L0f1565a8:
/*  f1565a8:	0fc5b8ff */ 	jal	lang0f16e3fc
/*  f1565ac:	a3af0068 */ 	sb	$t7,0x68($sp)
/*  f1565b0:	8fb800d4 */ 	lw	$t8,0xd4($sp)
/*  f1565b4:	8fa800dc */ 	lw	$t0,0xdc($sp)
/*  f1565b8:	8fab00e0 */ 	lw	$t3,0xe0($sp)
/*  f1565bc:	8faa00e4 */ 	lw	$t2,0xe4($sp)
/*  f1565c0:	afa20070 */ 	sw	$v0,0x70($sp)
/*  f1565c4:	02a02025 */ 	or	$a0,$s5,$zero
/*  f1565c8:	02802825 */ 	or	$a1,$s4,$zero
/*  f1565cc:	02603025 */ 	or	$a2,$s3,$zero
/*  f1565d0:	02c03825 */ 	or	$a3,$s6,$zero
/*  f1565d4:	afb60010 */ 	sw	$s6,0x10($sp)
/*  f1565d8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1565dc:	afbe001c */ 	sw	$s8,0x1c($sp)
/*  f1565e0:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f1565e4:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f1565e8:	afab0024 */ 	sw	$t3,0x24($sp)
/*  f1565ec:	0fc555a3 */ 	jal	func0f15568c
/*  f1565f0:	afaa0028 */ 	sw	$t2,0x28($sp)
/*  f1565f4:	0040a825 */ 	or	$s5,$v0,$zero
/*  f1565f8:	26100002 */ 	addiu	$s0,$s0,0x2
.L0f1565fc:
/*  f1565fc:	92020000 */ 	lbu	$v0,0x0($s0)
/*  f156600:	5440ff90 */ 	bnezl	$v0,.L0f156444
/*  f156604:	24010020 */ 	addiu	$at,$zero,0x20
.L0f156608:
/*  f156608:	3c098008 */ 	lui	$t1,%hi(g_TextRotated90)
/*  f15660c:	8d29fac8 */ 	lw	$t1,%lo(g_TextRotated90)($t1)
/*  f156610:	02a01025 */ 	or	$v0,$s5,$zero
/*  f156614:	11200012 */ 	beqz	$t1,.L0f156660
/*  f156618:	00000000 */ 	nop
/*  f15661c:	3c0d8008 */ 	lui	$t5,%hi(g_ScaleX)
/*  f156620:	8dadfac0 */ 	lw	$t5,%lo(g_ScaleX)($t5)
/*  f156624:	8e6c0000 */ 	lw	$t4,0x0($s3)
/*  f156628:	018d001a */ 	div	$zero,$t4,$t5
/*  f15662c:	00007012 */ 	mflo	$t6
/*  f156630:	ae6e0000 */ 	sw	$t6,0x0($s3)
/*  f156634:	15a00002 */ 	bnez	$t5,.L0f156640
/*  f156638:	00000000 */ 	nop
/*  f15663c:	0007000d */ 	break	0x7
.L0f156640:
/*  f156640:	2401ffff */ 	addiu	$at,$zero,-1
/*  f156644:	15a10004 */ 	bne	$t5,$at,.L0f156658
/*  f156648:	3c018000 */ 	lui	$at,0x8000
/*  f15664c:	15810002 */ 	bne	$t4,$at,.L0f156658
/*  f156650:	00000000 */ 	nop
/*  f156654:	0006000d */ 	break	0x6
.L0f156658:
/*  f156658:	10000011 */ 	b	.L0f1566a0
/*  f15665c:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0f156660:
/*  f156660:	3c0f8008 */ 	lui	$t7,%hi(g_ScaleX)
/*  f156664:	8deffac0 */ 	lw	$t7,%lo(g_ScaleX)($t7)
/*  f156668:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f15666c:	032f001a */ 	div	$zero,$t9,$t7
/*  f156670:	0000c012 */ 	mflo	$t8
/*  f156674:	ae980000 */ 	sw	$t8,0x0($s4)
/*  f156678:	15e00002 */ 	bnez	$t7,.L0f156684
/*  f15667c:	00000000 */ 	nop
/*  f156680:	0007000d */ 	break	0x7
.L0f156684:
/*  f156684:	2401ffff */ 	addiu	$at,$zero,-1
/*  f156688:	15e10004 */ 	bne	$t7,$at,.L0f15669c
/*  f15668c:	3c018000 */ 	lui	$at,0x8000
/*  f156690:	17210002 */ 	bne	$t9,$at,.L0f15669c
/*  f156694:	00000000 */ 	nop
/*  f156698:	0006000d */ 	break	0x6
.L0f15669c:
/*  f15669c:	8fbf005c */ 	lw	$ra,0x5c($sp)
.L0f1566a0:
/*  f1566a0:	8fb00038 */ 	lw	$s0,0x38($sp)
/*  f1566a4:	8fb1003c */ 	lw	$s1,0x3c($sp)
/*  f1566a8:	8fb20040 */ 	lw	$s2,0x40($sp)
/*  f1566ac:	8fb30044 */ 	lw	$s3,0x44($sp)
/*  f1566b0:	8fb40048 */ 	lw	$s4,0x48($sp)
/*  f1566b4:	8fb5004c */ 	lw	$s5,0x4c($sp)
/*  f1566b8:	8fb60050 */ 	lw	$s6,0x50($sp)
/*  f1566bc:	8fb70054 */ 	lw	$s7,0x54($sp)
/*  f1566c0:	8fbe0058 */ 	lw	$s8,0x58($sp)
/*  f1566c4:	03e00008 */ 	jr	$ra
/*  f1566c8:	27bd00c0 */ 	addiu	$sp,$sp,0xc0
);
#endif

Gfx *func0f1566cc(Gfx *gdl, u32 arg1, u32 arg2)
{
	u32 colour = func0f1543ac(arg1, arg2, var800a45d0.colour04);

	if (colour != var800a45d0.colour44) {
		gDPSetColor(gdl++, G_SETENVCOLOR, colour);
	}

	var800a45d0.colour44 = colour;

	colour = (var800a45d0.colour08 & 0xffffff00) | (func0f1543ac(arg1, arg2, var800a45d0.colour08) & 0xff);

	if (colour != var800a45d0.colour48) {
		gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
	}

	var800a45d0.colour48 = colour;

	return gdl;
}

Gfx *func0f156790(Gfx *gdl, s32 *x, s32 *y, struct fontchar *char1, struct fontchar *char2,
		struct font *font, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10);

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel func0f156790
/*  f156a84:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f156a88:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f156a8c:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f156a90:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f156a94:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f156a98:	8cce0000 */ 	lw	$t6,0x0($a2)
/*  f156a9c:	8faf0068 */ 	lw	$t7,0x68($sp)
/*  f156aa0:	8fab0050 */ 	lw	$t3,0x50($sp)
/*  f156aa4:	8fb90054 */ 	lw	$t9,0x54($sp)
/*  f156aa8:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f156aac:	afb80038 */ 	sw	$t8,0x38($sp)
/*  f156ab0:	856c0006 */ 	lh	$t4,0x6($t3)
/*  f156ab4:	84f80006 */ 	lh	$t8,0x6($a3)
/*  f156ab8:	00808025 */ 	move	$s0,$a0
/*  f156abc:	000c6880 */ 	sll	$t5,$t4,0x2
/*  f156ac0:	01ac6823 */ 	subu	$t5,$t5,$t4
/*  f156ac4:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f156ac8:	01ac6821 */ 	addu	$t5,$t5,$t4
/*  f156acc:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f156ad0:	032e7821 */ 	addu	$t7,$t9,$t6
/*  f156ad4:	00185880 */ 	sll	$t3,$t8,0x2
/*  f156ad8:	01eb6021 */ 	addu	$t4,$t7,$t3
/*  f156adc:	3c198008 */ 	lui	$t9,0x8008
/*  f156ae0:	8f3900fc */ 	lw	$t9,0xfc($t9)
/*  f156ae4:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f156ae8:	3c188008 */ 	lui	$t8,0x8008
/*  f156aec:	8f180108 */ 	lw	$t8,0x108($t8)
/*  f156af0:	01b91021 */ 	addu	$v0,$t5,$t9
/*  f156af4:	244effff */ 	addiu	$t6,$v0,-1
/*  f156af8:	01d80019 */ 	multu	$t6,$t8
/*  f156afc:	8cab0000 */ 	lw	$t3,0x0($a1)
/*  f156b00:	00e08825 */ 	move	$s1,$a3
/*  f156b04:	00a09025 */ 	move	$s2,$a1
/*  f156b08:	00007812 */ 	mflo	$t7
/*  f156b0c:	016f6023 */ 	subu	$t4,$t3,$t7
/*  f156b10:	1980005f */ 	blez	$t4,.JF0f156c90
/*  f156b14:	acac0000 */ 	sw	$t4,0x0($a1)
/*  f156b18:	0c002eeb */ 	jal	viGetWidth
/*  f156b1c:	00000000 */ 	nop
/*  f156b20:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f156b24:	0059082a */ 	slt	$at,$v0,$t9
/*  f156b28:	14200059 */ 	bnez	$at,.JF0f156c90
/*  f156b2c:	00000000 */ 	nop
/*  f156b30:	0c002eef */ 	jal	viGetHeight
/*  f156b34:	00000000 */ 	nop
/*  f156b38:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f156b3c:	82380002 */ 	lb	$t8,0x2($s1)
/*  f156b40:	8fa90058 */ 	lw	$t1,0x58($sp)
/*  f156b44:	8fab0060 */ 	lw	$t3,0x60($sp)
/*  f156b48:	01d81821 */ 	addu	$v1,$t6,$t8
/*  f156b4c:	0043082a */ 	slt	$at,$v0,$v1
/*  f156b50:	1420004f */ 	bnez	$at,.JF0f156c90
/*  f156b54:	00000000 */ 	nop
/*  f156b58:	8e420000 */ 	lw	$v0,0x0($s2)
/*  f156b5c:	012b7821 */ 	addu	$t7,$t1,$t3
/*  f156b60:	8faa005c */ 	lw	$t2,0x5c($sp)
/*  f156b64:	01e2082a */ 	slt	$at,$t7,$v0
/*  f156b68:	14200049 */ 	bnez	$at,.JF0f156c90
/*  f156b6c:	8fac0064 */ 	lw	$t4,0x64($sp)
/*  f156b70:	014c6821 */ 	addu	$t5,$t2,$t4
/*  f156b74:	01a3082a */ 	slt	$at,$t5,$v1
/*  f156b78:	14200045 */ 	bnez	$at,.JF0f156c90
/*  f156b7c:	0049082a */ 	slt	$at,$v0,$t1
/*  f156b80:	14200043 */ 	bnez	$at,.JF0f156c90
/*  f156b84:	00000000 */ 	nop
/*  f156b88:	92390003 */ 	lbu	$t9,0x3($s1)
/*  f156b8c:	00797021 */ 	addu	$t6,$v1,$t9
/*  f156b90:	01ca082a */ 	slt	$at,$t6,$t2
/*  f156b94:	1420003e */ 	bnez	$at,.JF0f156c90
/*  f156b98:	00000000 */ 	nop
/*  f156b9c:	8e380008 */ 	lw	$t8,0x8($s1)
/*  f156ba0:	57000008 */ 	bnezl	$t8,.JF0f156bc4
/*  f156ba4:	02001025 */ 	move	$v0,$s0
/*  f156ba8:	96240000 */ 	lhu	$a0,0x0($s1)
/*  f156bac:	0fc5b967 */ 	jal	lang0f16e3fc
/*  f156bb0:	2484ff80 */ 	addiu	$a0,$a0,-128
/*  f156bb4:	8fa90058 */ 	lw	$t1,0x58($sp)
/*  f156bb8:	8faa005c */ 	lw	$t2,0x5c($sp)
/*  f156bbc:	ae220008 */ 	sw	$v0,0x8($s1)
/*  f156bc0:	02001025 */ 	move	$v0,$s0
.JF0f156bc4:
/*  f156bc4:	3c0bfd50 */ 	lui	$t3,0xfd50
/*  f156bc8:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f156bcc:	8e2f0008 */ 	lw	$t7,0x8($s1)
/*  f156bd0:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156bd4:	02001825 */ 	move	$v1,$s0
/*  f156bd8:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f156bdc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156be0:	3c0ce600 */ 	lui	$t4,0xe600
/*  f156be4:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f156be8:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f156bec:	02004025 */ 	move	$t0,$s0
/*  f156bf0:	3c0df300 */ 	lui	$t5,0xf300
/*  f156bf4:	ad0d0000 */ 	sw	$t5,0x0($t0)
/*  f156bf8:	92240003 */ 	lbu	$a0,0x3($s1)
/*  f156bfc:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156c00:	02001025 */ 	move	$v0,$s0
/*  f156c04:	0004c8c0 */ 	sll	$t9,$a0,0x3
/*  f156c08:	27240011 */ 	addiu	$a0,$t9,0x11
/*  f156c0c:	00047043 */ 	sra	$t6,$a0,0x1
/*  f156c10:	25c4ffff */ 	addiu	$a0,$t6,-1
/*  f156c14:	288107ff */ 	slti	$at,$a0,0x7ff
/*  f156c18:	10200003 */ 	beqz	$at,.JF0f156c28
/*  f156c1c:	3c0de700 */ 	lui	$t5,0xe700
/*  f156c20:	10000002 */ 	b	.JF0f156c2c
/*  f156c24:	00801825 */ 	move	$v1,$a0
.JF0f156c28:
/*  f156c28:	240307ff */ 	li	$v1,0x7ff
.JF0f156c2c:
/*  f156c2c:	30780fff */ 	andi	$t8,$v1,0xfff
/*  f156c30:	00185b00 */ 	sll	$t3,$t8,0xc
/*  f156c34:	3c010700 */ 	lui	$at,0x700
/*  f156c38:	01617825 */ 	or	$t7,$t3,$at
/*  f156c3c:	35ec0800 */ 	ori	$t4,$t7,0x800
/*  f156c40:	ad0c0004 */ 	sw	$t4,0x4($t0)
/*  f156c44:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f156c48:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f156c4c:	8e590000 */ 	lw	$t9,0x0($s2)
/*  f156c50:	3c0e8008 */ 	lui	$t6,0x8008
/*  f156c54:	8dce0108 */ 	lw	$t6,0x108($t6)
/*  f156c58:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f156c5c:	8fab0060 */ 	lw	$t3,0x60($sp)
/*  f156c60:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f156c64:	2558ffff */ 	addiu	$t8,$t2,-1
/*  f156c68:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f156c6c:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f156c70:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f156c74:	02203825 */ 	move	$a3,$s1
/*  f156c78:	032e2823 */ 	subu	$a1,$t9,$t6
/*  f156c7c:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f156c80:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f156c84:	0fc55b33 */ 	jal	func0f156a24
/*  f156c88:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f156c8c:	00408025 */ 	move	$s0,$v0
.JF0f156c90:
/*  f156c90:	3c0d8008 */ 	lui	$t5,0x8008
/*  f156c94:	8dad0108 */ 	lw	$t5,0x108($t5)
/*  f156c98:	922c0004 */ 	lbu	$t4,0x4($s1)
/*  f156c9c:	8e4e0000 */ 	lw	$t6,0x0($s2)
/*  f156ca0:	02001025 */ 	move	$v0,$s0
/*  f156ca4:	018d0019 */ 	multu	$t4,$t5
/*  f156ca8:	0000c812 */ 	mflo	$t9
/*  f156cac:	01d9c021 */ 	addu	$t8,$t6,$t9
/*  f156cb0:	ae580000 */ 	sw	$t8,0x0($s2)
/*  f156cb4:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f156cb8:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f156cbc:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f156cc0:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f156cc4:	03e00008 */ 	jr	$ra
/*  f156cc8:	27bd0040 */ 	addiu	$sp,$sp,0x40
);
#else
GLOBAL_ASM(
glabel func0f156790
/*  f156790:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f156794:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f156798:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f15679c:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f1567a0:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f1567a4:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f1567a8:	8ccf0000 */ 	lw	$t7,0x0($a2)
/*  f1567ac:	8fb80068 */ 	lw	$t8,0x68($sp)
/*  f1567b0:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f1567b4:	8fab0054 */ 	lw	$t3,0x54($sp)
/*  f1567b8:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f1567bc:	afb90038 */ 	sw	$t9,0x38($sp)
/*  f1567c0:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*  f1567c4:	8cf90004 */ 	lw	$t9,0x4($a3)
/*  f1567c8:	00808025 */ 	or	$s0,$a0,$zero
/*  f1567cc:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f1567d0:	01cd7023 */ 	subu	$t6,$t6,$t5
/*  f1567d4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f1567d8:	01cd7021 */ 	addu	$t6,$t6,$t5
/*  f1567dc:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f1567e0:	016fc021 */ 	addu	$t8,$t3,$t7
/*  f1567e4:	00196080 */ 	sll	$t4,$t9,0x2
/*  f1567e8:	030c6821 */ 	addu	$t5,$t8,$t4
/*  f1567ec:	3c0b8008 */ 	lui	$t3,%hi(var8007fac4)
/*  f1567f0:	8d6bfac4 */ 	lw	$t3,%lo(var8007fac4)($t3)
/*  f1567f4:	8dae0000 */ 	lw	$t6,0x0($t5)
/*  f1567f8:	3c198008 */ 	lui	$t9,%hi(var8007fad0)
/*  f1567fc:	8f39fad0 */ 	lw	$t9,%lo(var8007fad0)($t9)
/*  f156800:	01cb1021 */ 	addu	$v0,$t6,$t3
/*  f156804:	244fffff */ 	addiu	$t7,$v0,-1
/*  f156808:	01f90019 */ 	multu	$t7,$t9
/*  f15680c:	8cac0000 */ 	lw	$t4,0x0($a1)
/*  f156810:	00a08825 */ 	or	$s1,$a1,$zero
/*  f156814:	00e09025 */ 	or	$s2,$a3,$zero
/*  f156818:	0000c012 */ 	mflo	$t8
/*  f15681c:	01986823 */ 	subu	$t5,$t4,$t8
/*  f156820:	19a00071 */ 	blez	$t5,.L0f1569e8
/*  f156824:	acad0000 */ 	sw	$t5,0x0($a1)
/*  f156828:	0c002f02 */ 	jal	viGetWidth
/*  f15682c:	00000000 */ 	nop
/*  f156830:	8e2b0000 */ 	lw	$t3,0x0($s1)
/*  f156834:	004b082a */ 	slt	$at,$v0,$t3
/*  f156838:	1420006b */ 	bnez	$at,.L0f1569e8
/*  f15683c:	00000000 */ 	nop
/*  f156840:	0c002f06 */ 	jal	viGetHeight
/*  f156844:	00000000 */ 	nop
/*  f156848:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f15684c:	82590001 */ 	lb	$t9,0x1($s2)
/*  f156850:	8fa90058 */ 	lw	$t1,0x58($sp)
/*  f156854:	8fac0060 */ 	lw	$t4,0x60($sp)
/*  f156858:	01f91821 */ 	addu	$v1,$t7,$t9
/*  f15685c:	0043082a */ 	slt	$at,$v0,$v1
/*  f156860:	14200061 */ 	bnez	$at,.L0f1569e8
/*  f156864:	00000000 */ 	nop
/*  f156868:	8e220000 */ 	lw	$v0,0x0($s1)
/*  f15686c:	012cc021 */ 	addu	$t8,$t1,$t4
/*  f156870:	8faa005c */ 	lw	$t2,0x5c($sp)
/*  f156874:	0302082a */ 	slt	$at,$t8,$v0
/*  f156878:	1420005b */ 	bnez	$at,.L0f1569e8
/*  f15687c:	8fad0064 */ 	lw	$t5,0x64($sp)
/*  f156880:	014d7021 */ 	addu	$t6,$t2,$t5
/*  f156884:	01c3082a */ 	slt	$at,$t6,$v1
/*  f156888:	14200057 */ 	bnez	$at,.L0f1569e8
/*  f15688c:	0049082a */ 	slt	$at,$v0,$t1
/*  f156890:	14200055 */ 	bnez	$at,.L0f1569e8
/*  f156894:	00000000 */ 	nop
/*  f156898:	924b0002 */ 	lbu	$t3,0x2($s2)
/*  f15689c:	3c19800a */ 	lui	$t9,%hi(var800a45d0)
/*  f1568a0:	006b7821 */ 	addu	$t7,$v1,$t3
/*  f1568a4:	01ea082a */ 	slt	$at,$t7,$t2
/*  f1568a8:	1420004f */ 	bnez	$at,.L0f1569e8
/*  f1568ac:	00000000 */ 	nop
/*  f1568b0:	933945d0 */ 	lbu	$t9,%lo(var800a45d0)($t9)
/*  f1568b4:	3c0c8008 */ 	lui	$t4,%hi(g_ScaleX)
/*  f1568b8:	8fb80048 */ 	lw	$t8,0x48($sp)
/*  f1568bc:	53200017 */ 	beqzl	$t9,.L0f15691c
/*  f1568c0:	02001025 */ 	or	$v0,$s0,$zero
/*  f1568c4:	8d8cfac0 */ 	lw	$t4,%lo(g_ScaleX)($t4)
/*  f1568c8:	8f0d0000 */ 	lw	$t5,0x0($t8)
/*  f1568cc:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f1568d0:	004c001a */ 	div	$zero,$v0,$t4
/*  f1568d4:	00002812 */ 	mflo	$a1
/*  f1568d8:	02002025 */ 	or	$a0,$s0,$zero
/*  f1568dc:	15800002 */ 	bnez	$t4,.L0f1568e8
/*  f1568e0:	00000000 */ 	nop
/*  f1568e4:	0007000d */ 	break	0x7
.L0f1568e8:
/*  f1568e8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1568ec:	15810004 */ 	bne	$t4,$at,.L0f156900
/*  f1568f0:	3c018000 */ 	lui	$at,0x8000
/*  f1568f4:	14410002 */ 	bne	$v0,$at,.L0f156900
/*  f1568f8:	00000000 */ 	nop
/*  f1568fc:	0006000d */ 	break	0x6
.L0f156900:
/*  f156900:	01ae3021 */ 	addu	$a2,$t5,$t6
/*  f156904:	0fc559b3 */ 	jal	func0f1566cc
/*  f156908:	00000000 */ 	nop
/*  f15690c:	8fa90058 */ 	lw	$t1,0x58($sp)
/*  f156910:	8faa005c */ 	lw	$t2,0x5c($sp)
/*  f156914:	00408025 */ 	or	$s0,$v0,$zero
/*  f156918:	02001025 */ 	or	$v0,$s0,$zero
.L0f15691c:
/*  f15691c:	3c0bfd50 */ 	lui	$t3,0xfd50
/*  f156920:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f156924:	8e4f0008 */ 	lw	$t7,0x8($s2)
/*  f156928:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f15692c:	02001825 */ 	or	$v1,$s0,$zero
/*  f156930:	ac4f0004 */ 	sw	$t7,0x4($v0)
/*  f156934:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156938:	3c19e600 */ 	lui	$t9,0xe600
/*  f15693c:	ac790000 */ 	sw	$t9,0x0($v1)
/*  f156940:	ac600004 */ 	sw	$zero,0x4($v1)
/*  f156944:	02004025 */ 	or	$t0,$s0,$zero
/*  f156948:	3c0cf300 */ 	lui	$t4,0xf300
/*  f15694c:	ad0c0000 */ 	sw	$t4,0x0($t0)
/*  f156950:	92440002 */ 	lbu	$a0,0x2($s2)
/*  f156954:	26100008 */ 	addiu	$s0,$s0,0x8
/*  f156958:	02001025 */ 	or	$v0,$s0,$zero
/*  f15695c:	0004c0c0 */ 	sll	$t8,$a0,0x3
/*  f156960:	27040011 */ 	addiu	$a0,$t8,0x11
/*  f156964:	00046843 */ 	sra	$t5,$a0,0x1
/*  f156968:	25a4ffff */ 	addiu	$a0,$t5,-1
/*  f15696c:	288107ff */ 	slti	$at,$a0,0x7ff
/*  f156970:	10200003 */ 	beqz	$at,.L0f156980
/*  f156974:	3c0ce700 */ 	lui	$t4,0xe700
/*  f156978:	10000002 */ 	b	.L0f156984
/*  f15697c:	00801825 */ 	or	$v1,$a0,$zero
.L0f156980:
/*  f156980:	240307ff */ 	addiu	$v1,$zero,0x7ff
.L0f156984:
/*  f156984:	306e0fff */ 	andi	$t6,$v1,0xfff
/*  f156988:	000e5b00 */ 	sll	$t3,$t6,0xc
/*  f15698c:	3c010700 */ 	lui	$at,0x700
/*  f156990:	01617825 */ 	or	$t7,$t3,$at
/*  f156994:	35f90800 */ 	ori	$t9,$t7,0x800
/*  f156998:	ad190004 */ 	sw	$t9,0x4($t0)
/*  f15699c:	ac400004 */ 	sw	$zero,0x4($v0)
/*  f1569a0:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f1569a4:	8e380000 */ 	lw	$t8,0x0($s1)
/*  f1569a8:	3c0d8008 */ 	lui	$t5,%hi(var8007fad0)
/*  f1569ac:	8dadfad0 */ 	lw	$t5,%lo(var8007fad0)($t5)
/*  f1569b0:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f1569b4:	8fab0060 */ 	lw	$t3,0x60($sp)
/*  f1569b8:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f1569bc:	254effff */ 	addiu	$t6,$t2,-1
/*  f1569c0:	26040008 */ 	addiu	$a0,$s0,0x8
/*  f1569c4:	afae0014 */ 	sw	$t6,0x14($sp)
/*  f1569c8:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f1569cc:	02403825 */ 	or	$a3,$s2,$zero
/*  f1569d0:	030d2823 */ 	subu	$a1,$t8,$t5
/*  f1569d4:	afaf001c */ 	sw	$t7,0x1c($sp)
/*  f1569d8:	afab0018 */ 	sw	$t3,0x18($sp)
/*  f1569dc:	0fc55a89 */ 	jal	func0f156a24
/*  f1569e0:	24c6ffff */ 	addiu	$a2,$a2,-1
/*  f1569e4:	00408025 */ 	or	$s0,$v0,$zero
.L0f1569e8:
/*  f1569e8:	3c0c8008 */ 	lui	$t4,%hi(var8007fad0)
/*  f1569ec:	8d8cfad0 */ 	lw	$t4,%lo(var8007fad0)($t4)
/*  f1569f0:	92590003 */ 	lbu	$t9,0x3($s2)
/*  f1569f4:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f1569f8:	02001025 */ 	or	$v0,$s0,$zero
/*  f1569fc:	032c0019 */ 	multu	$t9,$t4
/*  f156a00:	0000c012 */ 	mflo	$t8
/*  f156a04:	01b87021 */ 	addu	$t6,$t5,$t8
/*  f156a08:	ae2e0000 */ 	sw	$t6,0x0($s1)
/*  f156a0c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f156a10:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f156a14:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f156a18:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f156a1c:	03e00008 */ 	jr	$ra
/*  f156a20:	27bd0040 */ 	addiu	$sp,$sp,0x40
);
#endif

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel func0f156a24
/*  f156ccc:	90e30004 */ 	lbu	$v1,0x4($a3)
/*  f156cd0:	8fae0010 */ 	lw	$t6,0x10($sp)
/*  f156cd4:	8faf0018 */ 	lw	$t7,0x18($sp)
/*  f156cd8:	00654821 */ 	addu	$t1,$v1,$a1
/*  f156cdc:	25390002 */ 	addiu	$t9,$t1,0x2
/*  f156ce0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f156ce4:	0319082a */ 	slt	$at,$t8,$t9
/*  f156ce8:	142000ff */ 	bnez	$at,.JF0f1570e8
/*  f156cec:	00000000 */ 	nop
/*  f156cf0:	80ea0002 */ 	lb	$t2,0x2($a3)
/*  f156cf4:	8fab0014 */ 	lw	$t3,0x14($sp)
/*  f156cf8:	8fad001c */ 	lw	$t5,0x1c($sp)
/*  f156cfc:	01464021 */ 	addu	$t0,$t2,$a2
/*  f156d00:	010b082a */ 	slt	$at,$t0,$t3
/*  f156d04:	542000bb */ 	bnezl	$at,.JF0f156ff4
/*  f156d08:	90ed0003 */ 	lbu	$t5,0x3($a3)
/*  f156d0c:	90ee0003 */ 	lbu	$t6,0x3($a3)
/*  f156d10:	016d6021 */ 	addu	$t4,$t3,$t5
/*  f156d14:	3c188008 */ 	lui	$t8,0x8008
/*  f156d18:	010e1021 */ 	addu	$v0,$t0,$t6
/*  f156d1c:	244f0002 */ 	addiu	$t7,$v0,0x2
/*  f156d20:	018f082a */ 	slt	$at,$t4,$t7
/*  f156d24:	5420007a */ 	bnezl	$at,.JF0f156f10
/*  f156d28:	0188082a */ 	slt	$at,$t4,$t0
/*  f156d2c:	8f180100 */ 	lw	$t8,0x100($t8)
/*  f156d30:	3c088008 */ 	lui	$t0,0x8008
/*  f156d34:	25080108 */ 	addiu	$t0,$t0,0x108
/*  f156d38:	1300003e */ 	beqz	$t8,.JF0f156e34
/*  f156d3c:	00cac823 */ 	subu	$t9,$a2,$t2
/*  f156d40:	00196880 */ 	sll	$t5,$t9,0x2
/*  f156d44:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f156d48:	000e7b00 */ 	sll	$t7,$t6,0xc
/*  f156d4c:	0009c880 */ 	sll	$t9,$t1,0x2
/*  f156d50:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f156d54:	3c01e500 */ 	lui	$at,0xe500
/*  f156d58:	01e1c025 */ 	or	$t8,$t7,$at
/*  f156d5c:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f156d60:	030e7825 */ 	or	$t7,$t8,$t6
/*  f156d64:	00801025 */ 	move	$v0,$a0
/*  f156d68:	3c088008 */ 	lui	$t0,0x8008
/*  f156d6c:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f156d70:	90f90003 */ 	lbu	$t9,0x3($a3)
/*  f156d74:	25080108 */ 	addiu	$t0,$t0,0x108
/*  f156d78:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f156d7c:	272d0002 */ 	addiu	$t5,$t9,0x2
/*  f156d80:	80ef0002 */ 	lb	$t7,0x2($a3)
/*  f156d84:	01b80019 */ 	multu	$t5,$t8
/*  f156d88:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156d8c:	00cfc823 */ 	subu	$t9,$a2,$t7
/*  f156d90:	00801825 */ 	move	$v1,$a0
/*  f156d94:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156d98:	00805825 */ 	move	$t3,$a0
/*  f156d9c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156da0:	00007012 */ 	mflo	$t6
/*  f156da4:	032e6823 */ 	subu	$t5,$t9,$t6
/*  f156da8:	000dc080 */ 	sll	$t8,$t5,0x2
/*  f156dac:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f156db0:	00057080 */ 	sll	$t6,$a1,0x2
/*  f156db4:	31cd0fff */ 	andi	$t5,$t6,0xfff
/*  f156db8:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f156dbc:	032dc025 */ 	or	$t8,$t9,$t5
/*  f156dc0:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f156dc4:	3c0fb400 */ 	lui	$t7,0xb400
/*  f156dc8:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f156dcc:	90ee0003 */ 	lbu	$t6,0x3($a3)
/*  f156dd0:	3c0fb300 */ 	lui	$t7,0xb300
/*  f156dd4:	00801025 */ 	move	$v0,$a0
/*  f156dd8:	25d90001 */ 	addiu	$t9,$t6,0x1
/*  f156ddc:	00196940 */ 	sll	$t5,$t9,0x5
/*  f156de0:	31b8ffff */ 	andi	$t8,$t5,0xffff
/*  f156de4:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f156de8:	24190400 */ 	li	$t9,0x400
/*  f156dec:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f156df0:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f156df4:	032e001a */ 	div	$zero,$t9,$t6
/*  f156df8:	00006812 */ 	mflo	$t5
/*  f156dfc:	31b8ffff */ 	andi	$t8,$t5,0xffff
/*  f156e00:	00187c00 */ 	sll	$t7,$t8,0x10
/*  f156e04:	15c00002 */ 	bnez	$t6,.JF0f156e10
/*  f156e08:	00000000 */ 	nop
/*  f156e0c:	0007000d */ 	break	0x7
.JF0f156e10:
/*  f156e10:	2401ffff */ 	li	$at,-1
/*  f156e14:	15c10004 */ 	bne	$t6,$at,.JF0f156e28
/*  f156e18:	3c018000 */ 	lui	$at,0x8000
/*  f156e1c:	17210002 */ 	bne	$t9,$at,.JF0f156e28
/*  f156e20:	00000000 */ 	nop
/*  f156e24:	0006000d */ 	break	0x6
.JF0f156e28:
/*  f156e28:	35f9fc00 */ 	ori	$t9,$t7,0xfc00
/*  f156e2c:	03e00008 */ 	jr	$ra
/*  f156e30:	ad790004 */ 	sw	$t9,0x4($t3)
.JF0f156e34:
/*  f156e34:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f156e38:	3c01e400 */ 	lui	$at,0xe400
/*  f156e3c:	00804825 */ 	move	$t1,$a0
/*  f156e40:	006e0019 */ 	multu	$v1,$t6
/*  f156e44:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156e48:	00805025 */ 	move	$t2,$a0
/*  f156e4c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156e50:	00805825 */ 	move	$t3,$a0
/*  f156e54:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156e58:	00006812 */ 	mflo	$t5
/*  f156e5c:	01a5c021 */ 	addu	$t8,$t5,$a1
/*  f156e60:	00187880 */ 	sll	$t7,$t8,0x2
/*  f156e64:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f156e68:	332e0fff */ 	andi	$t6,$t9,0xfff
/*  f156e6c:	000e6b00 */ 	sll	$t5,$t6,0xc
/*  f156e70:	00027880 */ 	sll	$t7,$v0,0x2
/*  f156e74:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f156e78:	332e0fff */ 	andi	$t6,$t9,0xfff
/*  f156e7c:	01a1c025 */ 	or	$t8,$t5,$at
/*  f156e80:	030e6825 */ 	or	$t5,$t8,$t6
/*  f156e84:	ad2d0000 */ 	sw	$t5,0x0($t1)
/*  f156e88:	80ee0002 */ 	lb	$t6,0x2($a3)
/*  f156e8c:	00057880 */ 	sll	$t7,$a1,0x2
/*  f156e90:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f156e94:	00ce6821 */ 	addu	$t5,$a2,$t6
/*  f156e98:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f156e9c:	0019c300 */ 	sll	$t8,$t9,0xc
/*  f156ea0:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f156ea4:	03197025 */ 	or	$t6,$t8,$t9
/*  f156ea8:	ad2e0004 */ 	sw	$t6,0x4($t1)
/*  f156eac:	3c0db400 */ 	lui	$t5,0xb400
/*  f156eb0:	ad4d0000 */ 	sw	$t5,0x0($t2)
/*  f156eb4:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f156eb8:	24190400 */ 	li	$t9,0x400
/*  f156ebc:	3c0fb300 */ 	lui	$t7,0xb300
/*  f156ec0:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f156ec4:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f156ec8:	00801025 */ 	move	$v0,$a0
/*  f156ecc:	0338001a */ 	div	$zero,$t9,$t8
/*  f156ed0:	00007012 */ 	mflo	$t6
/*  f156ed4:	31cdffff */ 	andi	$t5,$t6,0xffff
/*  f156ed8:	000d7c00 */ 	sll	$t7,$t5,0x10
/*  f156edc:	17000002 */ 	bnez	$t8,.JF0f156ee8
/*  f156ee0:	00000000 */ 	nop
/*  f156ee4:	0007000d */ 	break	0x7
.JF0f156ee8:
/*  f156ee8:	2401ffff */ 	li	$at,-1
/*  f156eec:	17010004 */ 	bne	$t8,$at,.JF0f156f00
/*  f156ef0:	3c018000 */ 	lui	$at,0x8000
/*  f156ef4:	17210002 */ 	bne	$t9,$at,.JF0f156f00
/*  f156ef8:	00000000 */ 	nop
/*  f156efc:	0006000d */ 	break	0x6
.JF0f156f00:
/*  f156f00:	35f90400 */ 	ori	$t9,$t7,0x400
/*  f156f04:	03e00008 */ 	jr	$ra
/*  f156f08:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f156f0c:	0188082a */ 	slt	$at,$t4,$t0
.JF0f156f10:
/*  f156f10:	14200075 */ 	bnez	$at,.JF0f1570e8
/*  f156f14:	3c088008 */ 	lui	$t0,0x8008
/*  f156f18:	25080108 */ 	addiu	$t0,$t0,0x108
/*  f156f1c:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f156f20:	3c01e400 */ 	lui	$at,0xe400
/*  f156f24:	00801025 */ 	move	$v0,$a0
/*  f156f28:	00780019 */ 	multu	$v1,$t8
/*  f156f2c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156f30:	00804825 */ 	move	$t1,$a0
/*  f156f34:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156f38:	00805025 */ 	move	$t2,$a0
/*  f156f3c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156f40:	00007012 */ 	mflo	$t6
/*  f156f44:	01c56821 */ 	addu	$t5,$t6,$a1
/*  f156f48:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f156f4c:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f156f50:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f156f54:	00187300 */ 	sll	$t6,$t8,0xc
/*  f156f58:	000c7880 */ 	sll	$t7,$t4,0x2
/*  f156f5c:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f156f60:	01c16825 */ 	or	$t5,$t6,$at
/*  f156f64:	01b9c025 */ 	or	$t8,$t5,$t9
/*  f156f68:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f156f6c:	80f90002 */ 	lb	$t9,0x2($a3)
/*  f156f70:	00057080 */ 	sll	$t6,$a1,0x2
/*  f156f74:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f156f78:	00d9c021 */ 	addu	$t8,$a2,$t9
/*  f156f7c:	00187080 */ 	sll	$t6,$t8,0x2
/*  f156f80:	000f6b00 */ 	sll	$t5,$t7,0xc
/*  f156f84:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f156f88:	01afc825 */ 	or	$t9,$t5,$t7
/*  f156f8c:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f156f90:	3c18b400 */ 	lui	$t8,0xb400
/*  f156f94:	ad380000 */ 	sw	$t8,0x0($t1)
/*  f156f98:	ad200004 */ 	sw	$zero,0x4($t1)
/*  f156f9c:	240f0400 */ 	li	$t7,0x400
/*  f156fa0:	3c0eb300 */ 	lui	$t6,0xb300
/*  f156fa4:	ad4e0000 */ 	sw	$t6,0x0($t2)
/*  f156fa8:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*  f156fac:	00801025 */ 	move	$v0,$a0
/*  f156fb0:	01ed001a */ 	div	$zero,$t7,$t5
/*  f156fb4:	0000c812 */ 	mflo	$t9
/*  f156fb8:	3338ffff */ 	andi	$t8,$t9,0xffff
/*  f156fbc:	00187400 */ 	sll	$t6,$t8,0x10
/*  f156fc0:	15a00002 */ 	bnez	$t5,.JF0f156fcc
/*  f156fc4:	00000000 */ 	nop
/*  f156fc8:	0007000d */ 	break	0x7
.JF0f156fcc:
/*  f156fcc:	2401ffff */ 	li	$at,-1
/*  f156fd0:	15a10004 */ 	bne	$t5,$at,.JF0f156fe4
/*  f156fd4:	3c018000 */ 	lui	$at,0x8000
/*  f156fd8:	15e10002 */ 	bne	$t7,$at,.JF0f156fe4
/*  f156fdc:	00000000 */ 	nop
/*  f156fe0:	0006000d */ 	break	0x6
.JF0f156fe4:
/*  f156fe4:	35cf0400 */ 	ori	$t7,$t6,0x400
/*  f156fe8:	03e00008 */ 	jr	$ra
/*  f156fec:	ad4f0004 */ 	sw	$t7,0x4($t2)
/*  f156ff0:	90ed0003 */ 	lbu	$t5,0x3($a3)
.JF0f156ff4:
/*  f156ff4:	010d1021 */ 	addu	$v0,$t0,$t5
/*  f156ff8:	24590002 */ 	addiu	$t9,$v0,0x2
/*  f156ffc:	032b082a */ 	slt	$at,$t9,$t3
/*  f157000:	14200039 */ 	bnez	$at,.JF0f1570e8
/*  f157004:	3c088008 */ 	lui	$t0,0x8008
/*  f157008:	25080108 */ 	addiu	$t0,$t0,0x108
/*  f15700c:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f157010:	3c01e400 */ 	lui	$at,0xe400
/*  f157014:	00804825 */ 	move	$t1,$a0
/*  f157018:	00780019 */ 	multu	$v1,$t8
/*  f15701c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f157020:	00805025 */ 	move	$t2,$a0
/*  f157024:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f157028:	00806025 */ 	move	$t4,$a0
/*  f15702c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f157030:	00007012 */ 	mflo	$t6
/*  f157034:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f157038:	000f6880 */ 	sll	$t5,$t7,0x2
/*  f15703c:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f157040:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f157044:	00187300 */ 	sll	$t6,$t8,0xc
/*  f157048:	00026880 */ 	sll	$t5,$v0,0x2
/*  f15704c:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f157050:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f157054:	01c17825 */ 	or	$t7,$t6,$at
/*  f157058:	01f87025 */ 	or	$t6,$t7,$t8
/*  f15705c:	00056880 */ 	sll	$t5,$a1,0x2
/*  f157060:	31b90fff */ 	andi	$t9,$t5,0xfff
/*  f157064:	ad2e0000 */ 	sw	$t6,0x0($t1)
/*  f157068:	000bc080 */ 	sll	$t8,$t3,0x2
/*  f15706c:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f157070:	00197b00 */ 	sll	$t7,$t9,0xc
/*  f157074:	01ee6825 */ 	or	$t5,$t7,$t6
/*  f157078:	ad2d0004 */ 	sw	$t5,0x4($t1)
/*  f15707c:	3c19b400 */ 	lui	$t9,0xb400
/*  f157080:	ad590000 */ 	sw	$t9,0x0($t2)
/*  f157084:	80f80002 */ 	lb	$t8,0x2($a3)
/*  f157088:	01787823 */ 	subu	$t7,$t3,$t8
/*  f15708c:	01e67023 */ 	subu	$t6,$t7,$a2
/*  f157090:	000e6940 */ 	sll	$t5,$t6,0x5
/*  f157094:	31b9ffff */ 	andi	$t9,$t5,0xffff
/*  f157098:	ad590004 */ 	sw	$t9,0x4($t2)
/*  f15709c:	3c18b300 */ 	lui	$t8,0xb300
/*  f1570a0:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f1570a4:	240e0400 */ 	li	$t6,0x400
/*  f1570a8:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f1570ac:	01cf001a */ 	div	$zero,$t6,$t7
/*  f1570b0:	00006812 */ 	mflo	$t5
/*  f1570b4:	31b9ffff */ 	andi	$t9,$t5,0xffff
/*  f1570b8:	0019c400 */ 	sll	$t8,$t9,0x10
/*  f1570bc:	15e00002 */ 	bnez	$t7,.JF0f1570c8
/*  f1570c0:	00000000 */ 	nop
/*  f1570c4:	0007000d */ 	break	0x7
.JF0f1570c8:
/*  f1570c8:	2401ffff */ 	li	$at,-1
/*  f1570cc:	15e10004 */ 	bne	$t7,$at,.JF0f1570e0
/*  f1570d0:	3c018000 */ 	lui	$at,0x8000
/*  f1570d4:	15c10002 */ 	bne	$t6,$at,.JF0f1570e0
/*  f1570d8:	00000000 */ 	nop
/*  f1570dc:	0006000d */ 	break	0x6
.JF0f1570e0:
/*  f1570e0:	370e0400 */ 	ori	$t6,$t8,0x400
/*  f1570e4:	ad8e0004 */ 	sw	$t6,0x4($t4)
.JF0f1570e8:
/*  f1570e8:	03e00008 */ 	jr	$ra
/*  f1570ec:	00801025 */ 	move	$v0,$a0
);
#else
GLOBAL_ASM(
glabel func0f156a24
/*  f156a24:	90e30003 */ 	lbu	$v1,0x3($a3)
/*  f156a28:	8fae0010 */ 	lw	$t6,0x10($sp)
/*  f156a2c:	8faf0018 */ 	lw	$t7,0x18($sp)
/*  f156a30:	00654821 */ 	addu	$t1,$v1,$a1
/*  f156a34:	25390002 */ 	addiu	$t9,$t1,0x2
/*  f156a38:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f156a3c:	0319082a */ 	slt	$at,$t8,$t9
/*  f156a40:	142000ff */ 	bnez	$at,.L0f156e40
/*  f156a44:	00000000 */ 	nop
/*  f156a48:	80ea0001 */ 	lb	$t2,0x1($a3)
/*  f156a4c:	8fab0014 */ 	lw	$t3,0x14($sp)
/*  f156a50:	8fad001c */ 	lw	$t5,0x1c($sp)
/*  f156a54:	01464021 */ 	addu	$t0,$t2,$a2
/*  f156a58:	010b082a */ 	slt	$at,$t0,$t3
/*  f156a5c:	542000bb */ 	bnezl	$at,.L0f156d4c
/*  f156a60:	90ed0002 */ 	lbu	$t5,0x2($a3)
/*  f156a64:	90ee0002 */ 	lbu	$t6,0x2($a3)
/*  f156a68:	016d6021 */ 	addu	$t4,$t3,$t5
/*  f156a6c:	3c188008 */ 	lui	$t8,%hi(g_TextRotated90)
/*  f156a70:	010e1021 */ 	addu	$v0,$t0,$t6
/*  f156a74:	244f0002 */ 	addiu	$t7,$v0,0x2
/*  f156a78:	018f082a */ 	slt	$at,$t4,$t7
/*  f156a7c:	5420007a */ 	bnezl	$at,.L0f156c68
/*  f156a80:	0188082a */ 	slt	$at,$t4,$t0
/*  f156a84:	8f18fac8 */ 	lw	$t8,%lo(g_TextRotated90)($t8)
/*  f156a88:	3c088008 */ 	lui	$t0,%hi(var8007fad0)
/*  f156a8c:	2508fad0 */ 	addiu	$t0,$t0,%lo(var8007fad0)
/*  f156a90:	1300003e */ 	beqz	$t8,.L0f156b8c
/*  f156a94:	00cac823 */ 	subu	$t9,$a2,$t2
/*  f156a98:	00196880 */ 	sll	$t5,$t9,0x2
/*  f156a9c:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f156aa0:	000e7b00 */ 	sll	$t7,$t6,0xc
/*  f156aa4:	0009c880 */ 	sll	$t9,$t1,0x2
/*  f156aa8:	272d0008 */ 	addiu	$t5,$t9,0x8
/*  f156aac:	3c01e500 */ 	lui	$at,0xe500
/*  f156ab0:	01e1c025 */ 	or	$t8,$t7,$at
/*  f156ab4:	31ae0fff */ 	andi	$t6,$t5,0xfff
/*  f156ab8:	030e7825 */ 	or	$t7,$t8,$t6
/*  f156abc:	00801025 */ 	or	$v0,$a0,$zero
/*  f156ac0:	3c088008 */ 	lui	$t0,%hi(var8007fad0)
/*  f156ac4:	ac4f0000 */ 	sw	$t7,0x0($v0)
/*  f156ac8:	90f90002 */ 	lbu	$t9,0x2($a3)
/*  f156acc:	2508fad0 */ 	addiu	$t0,$t0,%lo(var8007fad0)
/*  f156ad0:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f156ad4:	272d0002 */ 	addiu	$t5,$t9,0x2
/*  f156ad8:	80ef0001 */ 	lb	$t7,0x1($a3)
/*  f156adc:	01b80019 */ 	multu	$t5,$t8
/*  f156ae0:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156ae4:	00cfc823 */ 	subu	$t9,$a2,$t7
/*  f156ae8:	00801825 */ 	or	$v1,$a0,$zero
/*  f156aec:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156af0:	00805825 */ 	or	$t3,$a0,$zero
/*  f156af4:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156af8:	00007012 */ 	mflo	$t6
/*  f156afc:	032e6823 */ 	subu	$t5,$t9,$t6
/*  f156b00:	000dc080 */ 	sll	$t8,$t5,0x2
/*  f156b04:	330f0fff */ 	andi	$t7,$t8,0xfff
/*  f156b08:	00057080 */ 	sll	$t6,$a1,0x2
/*  f156b0c:	31cd0fff */ 	andi	$t5,$t6,0xfff
/*  f156b10:	000fcb00 */ 	sll	$t9,$t7,0xc
/*  f156b14:	032dc025 */ 	or	$t8,$t9,$t5
/*  f156b18:	ac580004 */ 	sw	$t8,0x4($v0)
/*  f156b1c:	3c0fb400 */ 	lui	$t7,0xb400
/*  f156b20:	ac6f0000 */ 	sw	$t7,0x0($v1)
/*  f156b24:	90ee0002 */ 	lbu	$t6,0x2($a3)
/*  f156b28:	3c0fb300 */ 	lui	$t7,0xb300
/*  f156b2c:	00801025 */ 	or	$v0,$a0,$zero
/*  f156b30:	25d90001 */ 	addiu	$t9,$t6,0x1
/*  f156b34:	00196940 */ 	sll	$t5,$t9,0x5
/*  f156b38:	31b8ffff */ 	andi	$t8,$t5,0xffff
/*  f156b3c:	ac780004 */ 	sw	$t8,0x4($v1)
/*  f156b40:	24190400 */ 	addiu	$t9,$zero,0x400
/*  f156b44:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f156b48:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f156b4c:	032e001a */ 	div	$zero,$t9,$t6
/*  f156b50:	00006812 */ 	mflo	$t5
/*  f156b54:	31b8ffff */ 	andi	$t8,$t5,0xffff
/*  f156b58:	00187c00 */ 	sll	$t7,$t8,0x10
/*  f156b5c:	15c00002 */ 	bnez	$t6,.L0f156b68
/*  f156b60:	00000000 */ 	nop
/*  f156b64:	0007000d */ 	break	0x7
.L0f156b68:
/*  f156b68:	2401ffff */ 	addiu	$at,$zero,-1
/*  f156b6c:	15c10004 */ 	bne	$t6,$at,.L0f156b80
/*  f156b70:	3c018000 */ 	lui	$at,0x8000
/*  f156b74:	17210002 */ 	bne	$t9,$at,.L0f156b80
/*  f156b78:	00000000 */ 	nop
/*  f156b7c:	0006000d */ 	break	0x6
.L0f156b80:
/*  f156b80:	35f9fc00 */ 	ori	$t9,$t7,0xfc00
/*  f156b84:	03e00008 */ 	jr	$ra
/*  f156b88:	ad790004 */ 	sw	$t9,0x4($t3)
.L0f156b8c:
/*  f156b8c:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f156b90:	3c01e400 */ 	lui	$at,0xe400
/*  f156b94:	00804825 */ 	or	$t1,$a0,$zero
/*  f156b98:	006e0019 */ 	multu	$v1,$t6
/*  f156b9c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156ba0:	00805025 */ 	or	$t2,$a0,$zero
/*  f156ba4:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156ba8:	00805825 */ 	or	$t3,$a0,$zero
/*  f156bac:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156bb0:	00006812 */ 	mflo	$t5
/*  f156bb4:	01a5c021 */ 	addu	$t8,$t5,$a1
/*  f156bb8:	00187880 */ 	sll	$t7,$t8,0x2
/*  f156bbc:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f156bc0:	332e0fff */ 	andi	$t6,$t9,0xfff
/*  f156bc4:	000e6b00 */ 	sll	$t5,$t6,0xc
/*  f156bc8:	00027880 */ 	sll	$t7,$v0,0x2
/*  f156bcc:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f156bd0:	332e0fff */ 	andi	$t6,$t9,0xfff
/*  f156bd4:	01a1c025 */ 	or	$t8,$t5,$at
/*  f156bd8:	030e6825 */ 	or	$t5,$t8,$t6
/*  f156bdc:	ad2d0000 */ 	sw	$t5,0x0($t1)
/*  f156be0:	80ee0001 */ 	lb	$t6,0x1($a3)
/*  f156be4:	00057880 */ 	sll	$t7,$a1,0x2
/*  f156be8:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f156bec:	00ce6821 */ 	addu	$t5,$a2,$t6
/*  f156bf0:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f156bf4:	0019c300 */ 	sll	$t8,$t9,0xc
/*  f156bf8:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f156bfc:	03197025 */ 	or	$t6,$t8,$t9
/*  f156c00:	ad2e0004 */ 	sw	$t6,0x4($t1)
/*  f156c04:	3c0db400 */ 	lui	$t5,0xb400
/*  f156c08:	ad4d0000 */ 	sw	$t5,0x0($t2)
/*  f156c0c:	ad400004 */ 	sw	$zero,0x4($t2)
/*  f156c10:	24190400 */ 	addiu	$t9,$zero,0x400
/*  f156c14:	3c0fb300 */ 	lui	$t7,0xb300
/*  f156c18:	ad6f0000 */ 	sw	$t7,0x0($t3)
/*  f156c1c:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f156c20:	00801025 */ 	or	$v0,$a0,$zero
/*  f156c24:	0338001a */ 	div	$zero,$t9,$t8
/*  f156c28:	00007012 */ 	mflo	$t6
/*  f156c2c:	31cdffff */ 	andi	$t5,$t6,0xffff
/*  f156c30:	000d7c00 */ 	sll	$t7,$t5,0x10
/*  f156c34:	17000002 */ 	bnez	$t8,.L0f156c40
/*  f156c38:	00000000 */ 	nop
/*  f156c3c:	0007000d */ 	break	0x7
.L0f156c40:
/*  f156c40:	2401ffff */ 	addiu	$at,$zero,-1
/*  f156c44:	17010004 */ 	bne	$t8,$at,.L0f156c58
/*  f156c48:	3c018000 */ 	lui	$at,0x8000
/*  f156c4c:	17210002 */ 	bne	$t9,$at,.L0f156c58
/*  f156c50:	00000000 */ 	nop
/*  f156c54:	0006000d */ 	break	0x6
.L0f156c58:
/*  f156c58:	35f90400 */ 	ori	$t9,$t7,0x400
/*  f156c5c:	03e00008 */ 	jr	$ra
/*  f156c60:	ad790004 */ 	sw	$t9,0x4($t3)
/*  f156c64:	0188082a */ 	slt	$at,$t4,$t0
.L0f156c68:
/*  f156c68:	14200075 */ 	bnez	$at,.L0f156e40
/*  f156c6c:	3c088008 */ 	lui	$t0,%hi(var8007fad0)
/*  f156c70:	2508fad0 */ 	addiu	$t0,$t0,%lo(var8007fad0)
/*  f156c74:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f156c78:	3c01e400 */ 	lui	$at,0xe400
/*  f156c7c:	00801025 */ 	or	$v0,$a0,$zero
/*  f156c80:	00780019 */ 	multu	$v1,$t8
/*  f156c84:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156c88:	00804825 */ 	or	$t1,$a0,$zero
/*  f156c8c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156c90:	00805025 */ 	or	$t2,$a0,$zero
/*  f156c94:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156c98:	00007012 */ 	mflo	$t6
/*  f156c9c:	01c56821 */ 	addu	$t5,$t6,$a1
/*  f156ca0:	000d7880 */ 	sll	$t7,$t5,0x2
/*  f156ca4:	25f90008 */ 	addiu	$t9,$t7,0x8
/*  f156ca8:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f156cac:	00187300 */ 	sll	$t6,$t8,0xc
/*  f156cb0:	000c7880 */ 	sll	$t7,$t4,0x2
/*  f156cb4:	31f90fff */ 	andi	$t9,$t7,0xfff
/*  f156cb8:	01c16825 */ 	or	$t5,$t6,$at
/*  f156cbc:	01b9c025 */ 	or	$t8,$t5,$t9
/*  f156cc0:	ac580000 */ 	sw	$t8,0x0($v0)
/*  f156cc4:	80f90001 */ 	lb	$t9,0x1($a3)
/*  f156cc8:	00057080 */ 	sll	$t6,$a1,0x2
/*  f156ccc:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f156cd0:	00d9c021 */ 	addu	$t8,$a2,$t9
/*  f156cd4:	00187080 */ 	sll	$t6,$t8,0x2
/*  f156cd8:	000f6b00 */ 	sll	$t5,$t7,0xc
/*  f156cdc:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f156ce0:	01afc825 */ 	or	$t9,$t5,$t7
/*  f156ce4:	ac590004 */ 	sw	$t9,0x4($v0)
/*  f156ce8:	3c18b400 */ 	lui	$t8,0xb400
/*  f156cec:	ad380000 */ 	sw	$t8,0x0($t1)
/*  f156cf0:	ad200004 */ 	sw	$zero,0x4($t1)
/*  f156cf4:	240f0400 */ 	addiu	$t7,$zero,0x400
/*  f156cf8:	3c0eb300 */ 	lui	$t6,0xb300
/*  f156cfc:	ad4e0000 */ 	sw	$t6,0x0($t2)
/*  f156d00:	8d0d0000 */ 	lw	$t5,0x0($t0)
/*  f156d04:	00801025 */ 	or	$v0,$a0,$zero
/*  f156d08:	01ed001a */ 	div	$zero,$t7,$t5
/*  f156d0c:	0000c812 */ 	mflo	$t9
/*  f156d10:	3338ffff */ 	andi	$t8,$t9,0xffff
/*  f156d14:	00187400 */ 	sll	$t6,$t8,0x10
/*  f156d18:	15a00002 */ 	bnez	$t5,.L0f156d24
/*  f156d1c:	00000000 */ 	nop
/*  f156d20:	0007000d */ 	break	0x7
.L0f156d24:
/*  f156d24:	2401ffff */ 	addiu	$at,$zero,-1
/*  f156d28:	15a10004 */ 	bne	$t5,$at,.L0f156d3c
/*  f156d2c:	3c018000 */ 	lui	$at,0x8000
/*  f156d30:	15e10002 */ 	bne	$t7,$at,.L0f156d3c
/*  f156d34:	00000000 */ 	nop
/*  f156d38:	0006000d */ 	break	0x6
.L0f156d3c:
/*  f156d3c:	35cf0400 */ 	ori	$t7,$t6,0x400
/*  f156d40:	03e00008 */ 	jr	$ra
/*  f156d44:	ad4f0004 */ 	sw	$t7,0x4($t2)
/*  f156d48:	90ed0002 */ 	lbu	$t5,0x2($a3)
.L0f156d4c:
/*  f156d4c:	010d1021 */ 	addu	$v0,$t0,$t5
/*  f156d50:	24590002 */ 	addiu	$t9,$v0,0x2
/*  f156d54:	032b082a */ 	slt	$at,$t9,$t3
/*  f156d58:	14200039 */ 	bnez	$at,.L0f156e40
/*  f156d5c:	3c088008 */ 	lui	$t0,%hi(var8007fad0)
/*  f156d60:	2508fad0 */ 	addiu	$t0,$t0,%lo(var8007fad0)
/*  f156d64:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f156d68:	3c01e400 */ 	lui	$at,0xe400
/*  f156d6c:	00804825 */ 	or	$t1,$a0,$zero
/*  f156d70:	00780019 */ 	multu	$v1,$t8
/*  f156d74:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156d78:	00805025 */ 	or	$t2,$a0,$zero
/*  f156d7c:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156d80:	00806025 */ 	or	$t4,$a0,$zero
/*  f156d84:	24840008 */ 	addiu	$a0,$a0,0x8
/*  f156d88:	00007012 */ 	mflo	$t6
/*  f156d8c:	01c57821 */ 	addu	$t7,$t6,$a1
/*  f156d90:	000f6880 */ 	sll	$t5,$t7,0x2
/*  f156d94:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f156d98:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f156d9c:	00187300 */ 	sll	$t6,$t8,0xc
/*  f156da0:	00026880 */ 	sll	$t5,$v0,0x2
/*  f156da4:	25b90008 */ 	addiu	$t9,$t5,0x8
/*  f156da8:	33380fff */ 	andi	$t8,$t9,0xfff
/*  f156dac:	01c17825 */ 	or	$t7,$t6,$at
/*  f156db0:	01f87025 */ 	or	$t6,$t7,$t8
/*  f156db4:	00056880 */ 	sll	$t5,$a1,0x2
/*  f156db8:	31b90fff */ 	andi	$t9,$t5,0xfff
/*  f156dbc:	ad2e0000 */ 	sw	$t6,0x0($t1)
/*  f156dc0:	000bc080 */ 	sll	$t8,$t3,0x2
/*  f156dc4:	330e0fff */ 	andi	$t6,$t8,0xfff
/*  f156dc8:	00197b00 */ 	sll	$t7,$t9,0xc
/*  f156dcc:	01ee6825 */ 	or	$t5,$t7,$t6
/*  f156dd0:	ad2d0004 */ 	sw	$t5,0x4($t1)
/*  f156dd4:	3c19b400 */ 	lui	$t9,0xb400
/*  f156dd8:	ad590000 */ 	sw	$t9,0x0($t2)
/*  f156ddc:	80f80001 */ 	lb	$t8,0x1($a3)
/*  f156de0:	01787823 */ 	subu	$t7,$t3,$t8
/*  f156de4:	01e67023 */ 	subu	$t6,$t7,$a2
/*  f156de8:	000e6940 */ 	sll	$t5,$t6,0x5
/*  f156dec:	31b9ffff */ 	andi	$t9,$t5,0xffff
/*  f156df0:	ad590004 */ 	sw	$t9,0x4($t2)
/*  f156df4:	3c18b300 */ 	lui	$t8,0xb300
/*  f156df8:	ad980000 */ 	sw	$t8,0x0($t4)
/*  f156dfc:	240e0400 */ 	addiu	$t6,$zero,0x400
/*  f156e00:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f156e04:	01cf001a */ 	div	$zero,$t6,$t7
/*  f156e08:	00006812 */ 	mflo	$t5
/*  f156e0c:	31b9ffff */ 	andi	$t9,$t5,0xffff
/*  f156e10:	0019c400 */ 	sll	$t8,$t9,0x10
/*  f156e14:	15e00002 */ 	bnez	$t7,.L0f156e20
/*  f156e18:	00000000 */ 	nop
/*  f156e1c:	0007000d */ 	break	0x7
.L0f156e20:
/*  f156e20:	2401ffff */ 	addiu	$at,$zero,-1
/*  f156e24:	15e10004 */ 	bne	$t7,$at,.L0f156e38
/*  f156e28:	3c018000 */ 	lui	$at,0x8000
/*  f156e2c:	15c10002 */ 	bne	$t6,$at,.L0f156e38
/*  f156e30:	00000000 */ 	nop
/*  f156e34:	0006000d */ 	break	0x6
.L0f156e38:
/*  f156e38:	370e0400 */ 	ori	$t6,$t8,0x400
/*  f156e3c:	ad8e0004 */ 	sw	$t6,0x4($t4)
.L0f156e40:
/*  f156e40:	03e00008 */ 	jr	$ra
/*  f156e44:	00801025 */ 	or	$v0,$a0,$zero
);
#endif

Gfx *textRender(Gfx *gdl, s32 *x, s32 *y, char *text,
		struct fontchar *chars, struct font *font, u32 arg6, u32 colour,
		s32 width, s32 height, u32 arg10, s32 lineheight)
{
	s32 savedx;
	s32 savedy;
#if VERSION >= VERSION_PAL_BETA
	u8 prevchar;
#else
	s32 prevchar;
#endif

	*x *= g_ScaleX;

	savedx = *x;
	savedy = *y;
	prevchar = 'H';

#if VERSION >= VERSION_JPN_FINAL
	if (lineheight == -1) {
		lineheight = chars['['].baseline + chars['['].height;
	} else {
		lineheight = 13;
	}
#else
	if (lineheight == 0) {
		lineheight = chars['['].height + chars['['].baseline;
	}

	if (g_Jpn && lineheight < 14) {
		lineheight = 14;
	}
#endif

	gDPPipeSync(gdl++);
	gDPSetTextureLUT(gdl++, G_TT_IA16);
	gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(&var8007fb5c));
	gDPLoadSync(gdl++);
	gDPLoadTLUTCmd(gdl++, 6, 31);

#if VERSION >= VERSION_JPN_FINAL
	// Use clamp
	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x007c, 0x007c);
	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, 1, 1, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
#else
	// Use wrap
	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x007c, 0x007c);
	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, 1, 1, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
#endif

	gDPSetTileSize(gdl++, 1, 0, 0, 0x007c, 0x007c);
	gDPSetCycleType(gdl++, G_CYC_2CYCLE);
	gDPSetCombineLERP(gdl++,
			ENVIRONMENT, PRIMITIVE, TEXEL1_ALPHA, PRIMITIVE, 0, 0, 0, TEXEL0,
			0, 0, 0, COMBINED, COMBINED, 0, ENVIRONMENT, 0);
	gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
	gDPSetEnvColorViaWord(gdl++, arg6);
	gDPPipeSync(gdl++);

	var800a45d0.colour08 = colour;
	var800a45d0.colour48 = colour;
	var800a45d0.colour04 = arg6;
	var800a45d0.colour44 = arg6;

#if VERSION >= VERSION_PAL_BETA
	while (*text != '\0') {
		if (*text == ' ') {
			*x += var8007fad0 * 5;
			prevchar = 'H';
			text++;
		} else if (*text == '\n') {
			*x = savedx;
			*y += lineheight;
			prevchar = 'H';
			text++;
		} else {
			struct fontchar *sp78;
			struct fontchar *sp74;

			textMapCodeUnitToChar(&text, &sp78, &sp74, chars, &prevchar);

			gdl = func0f156790(gdl, x, y, sp78, sp74,
					font, savedx, savedy, width * var8007fad0, height, arg10);
		}
	}
#else
	while (*text != '\0') {
		if (*text == ' ') {
			*x += var8007fad0 * 5;
			prevchar = 'H';
			text++;
		} else if (*text == '\n') {
			*x = savedx;
			*y += lineheight;
			prevchar = 'H';
			text++;
		} else if (*text < 0x80) {
			gdl = func0f156790(gdl, x, y, &chars[*text - 0x21], &chars[prevchar - 0x21],
					font, savedx, savedy, width * var8007fad0, height, arg10);
			prevchar = *text;
			text++;
		} else {
			u16 codepoint = ((*text & 0x7f) << 7) | (text[1] & 0x7f);
			struct fontchar sp74 = {0, 0, 12, 11};

			if (codepoint & 0x2000) {
				sp74.width = 15;
				sp74.height = 16;
			}

			if ((codepoint & 0x1fff) >= 0x3c8) {
				codepoint = 2;
			}

			sp74.index = codepoint + 0x80;
			sp74.pixeldata = (void *)lang0f16e3fc(codepoint);

			gdl = func0f156790(gdl, x, y, &sp74, &sp74, font, savedx, savedy, width * var8007fad0, height, arg10);

			text += 2;
		}
	}
#endif

	gDPPipeSync(gdl++);
	gDPSetCycleType(gdl++, G_CYC_1CYCLE);
	gDPSetCombineLERP(gdl++,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0,
			0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);

	*x = *x / g_ScaleX;

	return gdl;
}

#if VERSION == VERSION_JPN_FINAL
Gfx *func0f1574d0jf(Gfx *gdl, s32 *x, s32 *y, char *text, struct fontchar *font1, struct font *font2, s32 colour, u32 colour2, s32 width, s32 height, s32 arg9, u32 arg10)
{
	return textRenderProjected(gdl, x, y, text, font1, font2, colour, width, height, arg9, arg10);
}
#endif

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel textMeasure
/*  f157524:	27bdff98 */ 	addiu	$sp,$sp,-104
/*  f157528:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f15752c:	8fb7007c */ 	lw	$s7,0x7c($sp)
/*  f157530:	240e0048 */ 	li	$t6,0x48
/*  f157534:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f157538:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f15753c:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f157540:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f157544:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f157548:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f15754c:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f157550:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f157554:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f157558:	afa60070 */ 	sw	$a2,0x70($sp)
/*  f15755c:	a3ae0067 */ 	sb	$t6,0x67($sp)
/*  f157560:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f157564:	2401ffff */ 	li	$at,-1
/*  f157568:	00a08025 */ 	move	$s0,$a1
/*  f15756c:	0080a025 */ 	move	$s4,$a0
/*  f157570:	00e0b025 */ 	move	$s6,$a3
/*  f157574:	00008825 */ 	move	$s1,$zero
/*  f157578:	0000a825 */ 	move	$s5,$zero
/*  f15757c:	16e10005 */ 	bne	$s7,$at,.JF0f157594
/*  f157580:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f157584:	90ef0447 */ 	lbu	$t7,0x447($a3)
/*  f157588:	80f80446 */ 	lb	$t8,0x446($a3)
/*  f15758c:	10000002 */ 	b	.JF0f157598
/*  f157590:	01f8b821 */ 	addu	$s7,$t7,$t8
.JF0f157594:
/*  f157594:	2417000d */ 	li	$s7,0xd
.JF0f157598:
/*  f157598:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f15759c:	13200054 */ 	beqz	$t9,.JF0f1576f0
/*  f1575a0:	00000000 */ 	nop
/*  f1575a4:	93220000 */ 	lbu	$v0,0x0($t9)
/*  f1575a8:	241e0020 */ 	li	$s8,0x20
/*  f1575ac:	2413000a */ 	li	$s3,0xa
/*  f1575b0:	1040004f */ 	beqz	$v0,.JF0f1576f0
/*  f1575b4:	8fb20078 */ 	lw	$s2,0x78($sp)
.JF0f1575b8:
/*  f1575b8:	17c2000d */ 	bne	$s8,$v0,.JF0f1575f0
/*  f1575bc:	8fa80070 */ 	lw	$t0,0x70($sp)
/*  f1575c0:	91090001 */ 	lbu	$t1,0x1($t0)
/*  f1575c4:	52690005 */ 	beql	$s3,$t1,.JF0f1575dc
/*  f1575c8:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f1575cc:	8e0a0000 */ 	lw	$t2,0x0($s0)
/*  f1575d0:	254b0005 */ 	addiu	$t3,$t2,0x5
/*  f1575d4:	ae0b0000 */ 	sw	$t3,0x0($s0)
/*  f1575d8:	8fad0070 */ 	lw	$t5,0x70($sp)
.JF0f1575dc:
/*  f1575dc:	240c0048 */ 	li	$t4,0x48
/*  f1575e0:	a3ac0067 */ 	sb	$t4,0x67($sp)
/*  f1575e4:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f1575e8:	1000003d */ 	b	.JF0f1576e0
/*  f1575ec:	afae0070 */ 	sw	$t6,0x70($sp)
.JF0f1575f0:
/*  f1575f0:	16620010 */ 	bne	$s3,$v0,.JF0f157634
/*  f1575f4:	27a40070 */ 	addiu	$a0,$sp,0x70
/*  f1575f8:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f1575fc:	01f1c023 */ 	subu	$t8,$t7,$s1
/*  f157600:	02b8082a */ 	slt	$at,$s5,$t8
/*  f157604:	ae180000 */ 	sw	$t8,0x0($s0)
/*  f157608:	10200002 */ 	beqz	$at,.JF0f157614
/*  f15760c:	00008825 */ 	move	$s1,$zero
/*  f157610:	0300a825 */ 	move	$s5,$t8
.JF0f157614:
/*  f157614:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f157618:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f15761c:	03374021 */ 	addu	$t0,$t9,$s7
/*  f157620:	ae880000 */ 	sw	$t0,0x0($s4)
/*  f157624:	8fa90070 */ 	lw	$t1,0x70($sp)
/*  f157628:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f15762c:	1000002c */ 	b	.JF0f1576e0
/*  f157630:	afaa0070 */ 	sw	$t2,0x70($sp)
.JF0f157634:
/*  f157634:	27ab0067 */ 	addiu	$t3,$sp,0x67
/*  f157638:	afab0010 */ 	sw	$t3,0x10($sp)
/*  f15763c:	27a50054 */ 	addiu	$a1,$sp,0x54
/*  f157640:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f157644:	02c03825 */ 	move	$a3,$s6
/*  f157648:	0fc552c0 */ 	jal	textMapCodeUnitToChar
/*  f15764c:	00008825 */ 	move	$s1,$zero
/*  f157650:	8fac0054 */ 	lw	$t4,0x54($sp)
/*  f157654:	240100be */ 	li	$at,0xbe
/*  f157658:	8fad0050 */ 	lw	$t5,0x50($sp)
/*  f15765c:	95820000 */ 	lhu	$v0,0x0($t4)
/*  f157660:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f157664:	54410003 */ 	bnel	$v0,$at,.JF0f157674
/*  f157668:	24010084 */ 	li	$at,0x84
/*  f15766c:	24110004 */ 	li	$s1,0x4
/*  f157670:	24010084 */ 	li	$at,0x84
.JF0f157674:
/*  f157674:	14410002 */ 	bne	$v0,$at,.JF0f157680
/*  f157678:	00000000 */ 	nop
/*  f15767c:	24110007 */ 	li	$s1,0x7
.JF0f157680:
/*  f157680:	12400011 */ 	beqz	$s2,.JF0f1576c8
/*  f157684:	00001025 */ 	move	$v0,$zero
/*  f157688:	85ae0006 */ 	lh	$t6,0x6($t5)
/*  f15768c:	85090006 */ 	lh	$t1,0x6($t0)
/*  f157690:	3c0d8008 */ 	lui	$t5,0x8008
/*  f157694:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f157698:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f15769c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f1576a0:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f1576a4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1576a8:	0258c821 */ 	addu	$t9,$s2,$t8
/*  f1576ac:	00095080 */ 	sll	$t2,$t1,0x2
/*  f1576b0:	032a5821 */ 	addu	$t3,$t9,$t2
/*  f1576b4:	8d6c0000 */ 	lw	$t4,0x0($t3)
/*  f1576b8:	8dad00fc */ 	lw	$t5,0xfc($t5)
/*  f1576bc:	018d1021 */ 	addu	$v0,$t4,$t5
/*  f1576c0:	10000001 */ 	b	.JF0f1576c8
/*  f1576c4:	2442ffff */ 	addiu	$v0,$v0,-1
.JF0f1576c8:
/*  f1576c8:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f1576cc:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f1576d0:	91f80004 */ 	lbu	$t8,0x4($t7)
/*  f1576d4:	01d84021 */ 	addu	$t0,$t6,$t8
/*  f1576d8:	01024823 */ 	subu	$t1,$t0,$v0
/*  f1576dc:	ae090000 */ 	sw	$t1,0x0($s0)
.JF0f1576e0:
/*  f1576e0:	8fb90070 */ 	lw	$t9,0x70($sp)
/*  f1576e4:	93220000 */ 	lbu	$v0,0x0($t9)
/*  f1576e8:	1440ffb3 */ 	bnez	$v0,.JF0f1575b8
/*  f1576ec:	00000000 */ 	nop
.JF0f1576f0:
/*  f1576f0:	3c0a8008 */ 	lui	$t2,0x8008
/*  f1576f4:	8d4a00f4 */ 	lw	$t2,0xf4($t2)
/*  f1576f8:	24010001 */ 	li	$at,0x1
/*  f1576fc:	3c0c8008 */ 	lui	$t4,0x8008
/*  f157700:	55410008 */ 	bnel	$t2,$at,.JF0f157724
/*  f157704:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f157708:	8e0b0000 */ 	lw	$t3,0x0($s0)
/*  f15770c:	8d8c0108 */ 	lw	$t4,0x108($t4)
/*  f157710:	016c0019 */ 	multu	$t3,$t4
/*  f157714:	00006812 */ 	mflo	$t5
/*  f157718:	ae0d0000 */ 	sw	$t5,0x0($s0)
/*  f15771c:	00000000 */ 	nop
/*  f157720:	8e0f0000 */ 	lw	$t7,0x0($s0)
.JF0f157724:
/*  f157724:	01f17023 */ 	subu	$t6,$t7,$s1
/*  f157728:	01d5082a */ 	slt	$at,$t6,$s5
/*  f15772c:	10200002 */ 	beqz	$at,.JF0f157738
/*  f157730:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f157734:	ae150000 */ 	sw	$s5,0x0($s0)
.JF0f157738:
/*  f157738:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f15773c:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f157740:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f157744:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f157748:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f15774c:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f157750:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f157754:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f157758:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f15775c:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f157760:	03e00008 */ 	jr	$ra
/*  f157764:	27bd0068 */ 	addiu	$sp,$sp,0x68
);
#elif VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel textMeasure
/*  f158268:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f15826c:	240e0048 */ 	li	$t6,0x48
/*  f158270:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f158274:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f158278:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f15827c:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f158280:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f158284:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f158288:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f15828c:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f158290:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f158294:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f158298:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f15829c:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f1582a0:	a3ae005f */ 	sb	$t6,0x5f($sp)
/*  f1582a4:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f1582a8:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f1582ac:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f1582b0:	00a08025 */ 	move	$s0,$a1
/*  f1582b4:	00809025 */ 	move	$s2,$a0
/*  f1582b8:	15e00006 */ 	bnez	$t7,.PF0f1582d4
/*  f1582bc:	00009825 */ 	move	$s3,$zero
/*  f1582c0:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f1582c4:	93190446 */ 	lbu	$t9,0x446($t8)
/*  f1582c8:	83080445 */ 	lb	$t0,0x445($t8)
/*  f1582cc:	03284821 */ 	addu	$t1,$t9,$t0
/*  f1582d0:	afa90074 */ 	sw	$t1,0x74($sp)
.PF0f1582d4:
/*  f1582d4:	3c0a8008 */ 	lui	$t2,0x8008
/*  f1582d8:	8d4a4660 */ 	lw	$t2,0x4660($t2)
/*  f1582dc:	8fab0074 */ 	lw	$t3,0x74($sp)
/*  f1582e0:	11400004 */ 	beqz	$t2,.PF0f1582f4
/*  f1582e4:	2961000e */ 	slti	$at,$t3,0xe
/*  f1582e8:	10200002 */ 	beqz	$at,.PF0f1582f4
/*  f1582ec:	240c000e */ 	li	$t4,0xe
/*  f1582f0:	afac0074 */ 	sw	$t4,0x74($sp)
.PF0f1582f4:
/*  f1582f4:	8fad0068 */ 	lw	$t5,0x68($sp)
/*  f1582f8:	11a00047 */ 	beqz	$t5,.PF0f158418
/*  f1582fc:	00000000 */ 	nop
/*  f158300:	91a20000 */ 	lbu	$v0,0x0($t5)
/*  f158304:	27be004c */ 	addiu	$s8,$sp,0x4c
/*  f158308:	27b70050 */ 	addiu	$s7,$sp,0x50
/*  f15830c:	10400042 */ 	beqz	$v0,.PF0f158418
/*  f158310:	27b60068 */ 	addiu	$s6,$sp,0x68
/*  f158314:	24150020 */ 	li	$s5,0x20
/*  f158318:	8fb40070 */ 	lw	$s4,0x70($sp)
/*  f15831c:	2411000a */ 	li	$s1,0xa
.PF0f158320:
/*  f158320:	16a2000d */ 	bne	$s5,$v0,.PF0f158358
/*  f158324:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f158328:	91cf0001 */ 	lbu	$t7,0x1($t6)
/*  f15832c:	522f0005 */ 	beql	$s1,$t7,.PF0f158344
/*  f158330:	8fa90068 */ 	lw	$t1,0x68($sp)
/*  f158334:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f158338:	27190005 */ 	addiu	$t9,$t8,0x5
/*  f15833c:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f158340:	8fa90068 */ 	lw	$t1,0x68($sp)
.PF0f158344:
/*  f158344:	24080048 */ 	li	$t0,0x48
/*  f158348:	a3a8005f */ 	sb	$t0,0x5f($sp)
/*  f15834c:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f158350:	1000002d */ 	b	.PF0f158408
/*  f158354:	afaa0068 */ 	sw	$t2,0x68($sp)
.PF0f158358:
/*  f158358:	1622000f */ 	bne	$s1,$v0,.PF0f158398
/*  f15835c:	02c02025 */ 	move	$a0,$s6
/*  f158360:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f158364:	0262082a */ 	slt	$at,$s3,$v0
/*  f158368:	50200003 */ 	beqzl	$at,.PF0f158378
/*  f15836c:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f158370:	00409825 */ 	move	$s3,$v0
/*  f158374:	ae000000 */ 	sw	$zero,0x0($s0)
.PF0f158378:
/*  f158378:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f15837c:	8fac0074 */ 	lw	$t4,0x74($sp)
/*  f158380:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f158384:	ae4d0000 */ 	sw	$t5,0x0($s2)
/*  f158388:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f15838c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f158390:	1000001d */ 	b	.PF0f158408
/*  f158394:	afaf0068 */ 	sw	$t7,0x68($sp)
.PF0f158398:
/*  f158398:	27b8005f */ 	addiu	$t8,$sp,0x5f
/*  f15839c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f1583a0:	02e02825 */ 	move	$a1,$s7
/*  f1583a4:	03c03025 */ 	move	$a2,$s8
/*  f1583a8:	0fc5574b */ 	jal	textMapCodeUnitToChar
/*  f1583ac:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f1583b0:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f1583b4:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f1583b8:	8f280004 */ 	lw	$t0,0x4($t9)
/*  f1583bc:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*  f1583c0:	3c198008 */ 	lui	$t9,0x8008
/*  f1583c4:	00084880 */ 	sll	$t1,$t0,0x2
/*  f1583c8:	01284823 */ 	subu	$t1,$t1,$t0
/*  f1583cc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f1583d0:	01284821 */ 	addu	$t1,$t1,$t0
/*  f1583d4:	00095080 */ 	sll	$t2,$t1,0x2
/*  f1583d8:	028a5821 */ 	addu	$t3,$s4,$t2
/*  f1583dc:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f1583e0:	016e7821 */ 	addu	$t7,$t3,$t6
/*  f1583e4:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f1583e8:	8f390024 */ 	lw	$t9,0x24($t9)
/*  f1583ec:	8e080000 */ 	lw	$t0,0x0($s0)
/*  f1583f0:	91890003 */ 	lbu	$t1,0x3($t4)
/*  f1583f4:	03191021 */ 	addu	$v0,$t8,$t9
/*  f1583f8:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f1583fc:	01095021 */ 	addu	$t2,$t0,$t1
/*  f158400:	01426823 */ 	subu	$t5,$t2,$v0
/*  f158404:	ae0d0000 */ 	sw	$t5,0x0($s0)
.PF0f158408:
/*  f158408:	8fab0068 */ 	lw	$t3,0x68($sp)
/*  f15840c:	91620000 */ 	lbu	$v0,0x0($t3)
/*  f158410:	1440ffc3 */ 	bnez	$v0,.PF0f158320
/*  f158414:	00000000 */ 	nop
.PF0f158418:
/*  f158418:	3c0e8008 */ 	lui	$t6,0x8008
/*  f15841c:	8dce0020 */ 	lw	$t6,0x20($t6)
/*  f158420:	24010001 */ 	li	$at,0x1
/*  f158424:	3c188008 */ 	lui	$t8,0x8008
/*  f158428:	55c10008 */ 	bnel	$t6,$at,.PF0f15844c
/*  f15842c:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f158430:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f158434:	8f180030 */ 	lw	$t8,0x30($t8)
/*  f158438:	01f80019 */ 	multu	$t7,$t8
/*  f15843c:	0000c812 */ 	mflo	$t9
/*  f158440:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f158444:	00000000 */ 	nop
/*  f158448:	8e0c0000 */ 	lw	$t4,0x0($s0)
.PF0f15844c:
/*  f15844c:	0193082a */ 	slt	$at,$t4,$s3
/*  f158450:	50200003 */ 	beqzl	$at,.PF0f158460
/*  f158454:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f158458:	ae130000 */ 	sw	$s3,0x0($s0)
/*  f15845c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.PF0f158460:
/*  f158460:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f158464:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f158468:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f15846c:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f158470:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f158474:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f158478:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f15847c:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f158480:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f158484:	03e00008 */ 	jr	$ra
/*  f158488:	27bd0060 */ 	addiu	$sp,$sp,0x60
);
#elif VERSION >= VERSION_PAL_BETA
GLOBAL_ASM(
glabel textMeasure
/*  f158968:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f15896c:	240e0048 */ 	li	$t6,0x48
/*  f158970:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f158974:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f158978:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f15897c:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f158980:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f158984:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f158988:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f15898c:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f158990:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f158994:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f158998:	afa60068 */ 	sw	$a2,0x68($sp)
/*  f15899c:	afa7006c */ 	sw	$a3,0x6c($sp)
/*  f1589a0:	a3ae005f */ 	sb	$t6,0x5f($sp)
/*  f1589a4:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f1589a8:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f1589ac:	8faf0074 */ 	lw	$t7,0x74($sp)
/*  f1589b0:	00a08025 */ 	move	$s0,$a1
/*  f1589b4:	00809025 */ 	move	$s2,$a0
/*  f1589b8:	15e00006 */ 	bnez	$t7,.PB0f1589d4
/*  f1589bc:	00009825 */ 	move	$s3,$zero
/*  f1589c0:	8fb8006c */ 	lw	$t8,0x6c($sp)
/*  f1589c4:	93190446 */ 	lbu	$t9,0x446($t8)
/*  f1589c8:	83080445 */ 	lb	$t0,0x445($t8)
/*  f1589cc:	03284821 */ 	addu	$t1,$t9,$t0
/*  f1589d0:	afa90074 */ 	sw	$t1,0x74($sp)
.PB0f1589d4:
/*  f1589d4:	3c0a8008 */ 	lui	$t2,0x8008
/*  f1589d8:	8d4a65f0 */ 	lw	$t2,0x65f0($t2)
/*  f1589dc:	8fab0074 */ 	lw	$t3,0x74($sp)
/*  f1589e0:	11400004 */ 	beqz	$t2,.PB0f1589f4
/*  f1589e4:	2961000e */ 	slti	$at,$t3,0xe
/*  f1589e8:	10200002 */ 	beqz	$at,.PB0f1589f4
/*  f1589ec:	240c000e */ 	li	$t4,0xe
/*  f1589f0:	afac0074 */ 	sw	$t4,0x74($sp)
.PB0f1589f4:
/*  f1589f4:	8fad0068 */ 	lw	$t5,0x68($sp)
/*  f1589f8:	11a00047 */ 	beqz	$t5,.PB0f158b18
/*  f1589fc:	00000000 */ 	nop
/*  f158a00:	91a20000 */ 	lbu	$v0,0x0($t5)
/*  f158a04:	27be004c */ 	addiu	$s8,$sp,0x4c
/*  f158a08:	27b70050 */ 	addiu	$s7,$sp,0x50
/*  f158a0c:	10400042 */ 	beqz	$v0,.PB0f158b18
/*  f158a10:	27b60068 */ 	addiu	$s6,$sp,0x68
/*  f158a14:	24150020 */ 	li	$s5,0x20
/*  f158a18:	8fb40070 */ 	lw	$s4,0x70($sp)
/*  f158a1c:	2411000a */ 	li	$s1,0xa
.PB0f158a20:
/*  f158a20:	16a2000d */ 	bne	$s5,$v0,.PB0f158a58
/*  f158a24:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f158a28:	91cf0001 */ 	lbu	$t7,0x1($t6)
/*  f158a2c:	522f0005 */ 	beql	$s1,$t7,.PB0f158a44
/*  f158a30:	8fa90068 */ 	lw	$t1,0x68($sp)
/*  f158a34:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f158a38:	27190005 */ 	addiu	$t9,$t8,0x5
/*  f158a3c:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f158a40:	8fa90068 */ 	lw	$t1,0x68($sp)
.PB0f158a44:
/*  f158a44:	24080048 */ 	li	$t0,0x48
/*  f158a48:	a3a8005f */ 	sb	$t0,0x5f($sp)
/*  f158a4c:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f158a50:	1000002d */ 	b	.PB0f158b08
/*  f158a54:	afaa0068 */ 	sw	$t2,0x68($sp)
.PB0f158a58:
/*  f158a58:	1622000f */ 	bne	$s1,$v0,.PB0f158a98
/*  f158a5c:	02c02025 */ 	move	$a0,$s6
/*  f158a60:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f158a64:	0262082a */ 	slt	$at,$s3,$v0
/*  f158a68:	50200003 */ 	beqzl	$at,.PB0f158a78
/*  f158a6c:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f158a70:	00409825 */ 	move	$s3,$v0
/*  f158a74:	ae000000 */ 	sw	$zero,0x0($s0)
.PB0f158a78:
/*  f158a78:	8e4b0000 */ 	lw	$t3,0x0($s2)
/*  f158a7c:	8fac0074 */ 	lw	$t4,0x74($sp)
/*  f158a80:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f158a84:	ae4d0000 */ 	sw	$t5,0x0($s2)
/*  f158a88:	8fae0068 */ 	lw	$t6,0x68($sp)
/*  f158a8c:	25cf0001 */ 	addiu	$t7,$t6,0x1
/*  f158a90:	1000001d */ 	b	.PB0f158b08
/*  f158a94:	afaf0068 */ 	sw	$t7,0x68($sp)
.PB0f158a98:
/*  f158a98:	27b8005f */ 	addiu	$t8,$sp,0x5f
/*  f158a9c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f158aa0:	02e02825 */ 	move	$a1,$s7
/*  f158aa4:	03c03025 */ 	move	$a2,$s8
/*  f158aa8:	0fc5590b */ 	jal	textMapCodeUnitToChar
/*  f158aac:	8fa7006c */ 	lw	$a3,0x6c($sp)
/*  f158ab0:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f158ab4:	8fac0050 */ 	lw	$t4,0x50($sp)
/*  f158ab8:	8f280004 */ 	lw	$t0,0x4($t9)
/*  f158abc:	8d8d0004 */ 	lw	$t5,0x4($t4)
/*  f158ac0:	3c198008 */ 	lui	$t9,0x8008
/*  f158ac4:	00084880 */ 	sll	$t1,$t0,0x2
/*  f158ac8:	01284823 */ 	subu	$t1,$t1,$t0
/*  f158acc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f158ad0:	01284821 */ 	addu	$t1,$t1,$t0
/*  f158ad4:	00095080 */ 	sll	$t2,$t1,0x2
/*  f158ad8:	028a5821 */ 	addu	$t3,$s4,$t2
/*  f158adc:	000d7080 */ 	sll	$t6,$t5,0x2
/*  f158ae0:	016e7821 */ 	addu	$t7,$t3,$t6
/*  f158ae4:	8df80000 */ 	lw	$t8,0x0($t7)
/*  f158ae8:	8f391f94 */ 	lw	$t9,0x1f94($t9)
/*  f158aec:	8e080000 */ 	lw	$t0,0x0($s0)
/*  f158af0:	91890003 */ 	lbu	$t1,0x3($t4)
/*  f158af4:	03191021 */ 	addu	$v0,$t8,$t9
/*  f158af8:	2442ffff */ 	addiu	$v0,$v0,-1
/*  f158afc:	01095021 */ 	addu	$t2,$t0,$t1
/*  f158b00:	01426823 */ 	subu	$t5,$t2,$v0
/*  f158b04:	ae0d0000 */ 	sw	$t5,0x0($s0)
.PB0f158b08:
/*  f158b08:	8fab0068 */ 	lw	$t3,0x68($sp)
/*  f158b0c:	91620000 */ 	lbu	$v0,0x0($t3)
/*  f158b10:	1440ffc3 */ 	bnez	$v0,.PB0f158a20
/*  f158b14:	00000000 */ 	nop
.PB0f158b18:
/*  f158b18:	3c0e8008 */ 	lui	$t6,0x8008
/*  f158b1c:	8dce1f90 */ 	lw	$t6,0x1f90($t6)
/*  f158b20:	24010001 */ 	li	$at,0x1
/*  f158b24:	3c188008 */ 	lui	$t8,0x8008
/*  f158b28:	55c10008 */ 	bnel	$t6,$at,.PB0f158b4c
/*  f158b2c:	8e0c0000 */ 	lw	$t4,0x0($s0)
/*  f158b30:	8e0f0000 */ 	lw	$t7,0x0($s0)
/*  f158b34:	8f181fa0 */ 	lw	$t8,0x1fa0($t8)
/*  f158b38:	01f80019 */ 	multu	$t7,$t8
/*  f158b3c:	0000c812 */ 	mflo	$t9
/*  f158b40:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f158b44:	00000000 */ 	nop
/*  f158b48:	8e0c0000 */ 	lw	$t4,0x0($s0)
.PB0f158b4c:
/*  f158b4c:	0193082a */ 	slt	$at,$t4,$s3
/*  f158b50:	50200003 */ 	beqzl	$at,.PB0f158b60
/*  f158b54:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f158b58:	ae130000 */ 	sw	$s3,0x0($s0)
/*  f158b5c:	8fbf0044 */ 	lw	$ra,0x44($sp)
.PB0f158b60:
/*  f158b60:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f158b64:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f158b68:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f158b6c:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f158b70:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f158b74:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f158b78:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f158b7c:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f158b80:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f158b84:	03e00008 */ 	jr	$ra
/*  f158b88:	27bd0060 */ 	addiu	$sp,$sp,0x60
);
#else
GLOBAL_ASM(
glabel textMeasure
/*  f1572f8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1572fc:	afb10008 */ 	sw	$s1,0x8($sp)
/*  f157300:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f157304:	afb40014 */ 	sw	$s4,0x14($sp)
/*  f157308:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f15730c:	afb2000c */ 	sw	$s2,0xc($sp)
/*  f157310:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f157314:	ac800000 */ 	sw	$zero,0x0($a0)
/*  f157318:	00808025 */ 	or	$s0,$a0,$zero
/*  f15731c:	24030048 */ 	addiu	$v1,$zero,0x48
/*  f157320:	00001025 */ 	or	$v0,$zero,$zero
/*  f157324:	16200004 */ 	bnez	$s1,.L0f157338
/*  f157328:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f15732c:	90ee0446 */ 	lbu	$t6,0x446($a3)
/*  f157330:	80ef0445 */ 	lb	$t7,0x445($a3)
/*  f157334:	01cf8821 */ 	addu	$s1,$t6,$t7
.L0f157338:
/*  f157338:	3c188008 */ 	lui	$t8,%hi(g_Jpn)
/*  f15733c:	8f184120 */ 	lw	$t8,%lo(g_Jpn)($t8)
/*  f157340:	2a21000e */ 	slti	$at,$s1,0xe
/*  f157344:	13000004 */ 	beqz	$t8,.L0f157358
/*  f157348:	00000000 */ 	nop
/*  f15734c:	10200002 */ 	beqz	$at,.L0f157358
/*  f157350:	00000000 */ 	nop
/*  f157354:	2411000e */ 	addiu	$s1,$zero,0xe
.L0f157358:
/*  f157358:	10c00059 */ 	beqz	$a2,.L0f1574c0
/*  f15735c:	00000000 */ 	nop
/*  f157360:	90c40000 */ 	lbu	$a0,0x0($a2)
/*  f157364:	3c148008 */ 	lui	$s4,%hi(var8007fac4)
/*  f157368:	2694fac4 */ 	addiu	$s4,$s4,%lo(var8007fac4)
/*  f15736c:	10800054 */ 	beqz	$a0,.L0f1574c0
/*  f157370:	00804025 */ 	or	$t0,$a0,$zero
/*  f157374:	2413000d */ 	addiu	$s3,$zero,0xd
/*  f157378:	2412000c */ 	addiu	$s2,$zero,0xc
/*  f15737c:	240c000a */ 	addiu	$t4,$zero,0xa
/*  f157380:	240b0020 */ 	addiu	$t3,$zero,0x20
/*  f157384:	8fa90028 */ 	lw	$t1,0x28($sp)
.L0f157388:
/*  f157388:	1568000a */ 	bne	$t3,$t0,.L0f1573b4
/*  f15738c:	00000000 */ 	nop
/*  f157390:	90d90001 */ 	lbu	$t9,0x1($a2)
/*  f157394:	24030048 */ 	addiu	$v1,$zero,0x48
/*  f157398:	11990004 */ 	beq	$t4,$t9,.L0f1573ac
/*  f15739c:	00000000 */ 	nop
/*  f1573a0:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f1573a4:	25cf0005 */ 	addiu	$t7,$t6,0x5
/*  f1573a8:	acaf0000 */ 	sw	$t7,0x0($a1)
.L0f1573ac:
/*  f1573ac:	10000041 */ 	b	.L0f1574b4
/*  f1573b0:	24c60001 */ 	addiu	$a2,$a2,0x1
.L0f1573b4:
/*  f1573b4:	1588000c */ 	bne	$t4,$t0,.L0f1573e8
/*  f1573b8:	29010080 */ 	slti	$at,$t0,0x80
/*  f1573bc:	8ca40000 */ 	lw	$a0,0x0($a1)
/*  f1573c0:	0044082a */ 	slt	$at,$v0,$a0
/*  f1573c4:	50200003 */ 	beqzl	$at,.L0f1573d4
/*  f1573c8:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f1573cc:	00801025 */ 	or	$v0,$a0,$zero
/*  f1573d0:	aca00000 */ 	sw	$zero,0x0($a1)
.L0f1573d4:
/*  f1573d4:	8e180000 */ 	lw	$t8,0x0($s0)
/*  f1573d8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1573dc:	0311c821 */ 	addu	$t9,$t8,$s1
/*  f1573e0:	10000034 */ 	b	.L0f1574b4
/*  f1573e4:	ae190000 */ 	sw	$t9,0x0($s0)
.L0f1573e8:
/*  f1573e8:	5020001d */ 	beqzl	$at,.L0f157460
/*  f1573ec:	290100c0 */ 	slti	$at,$t0,0xc0
/*  f1573f0:	308800ff */ 	andi	$t0,$a0,0xff
/*  f1573f4:	01120019 */ 	multu	$t0,$s2
/*  f1573f8:	24c60001 */ 	addiu	$a2,$a2,0x1
/*  f1573fc:	00007012 */ 	mflo	$t6
/*  f157400:	00ee5021 */ 	addu	$t2,$a3,$t6
/*  f157404:	8d4ffe78 */ 	lw	$t7,-0x188($t2)
/*  f157408:	00720019 */ 	multu	$v1,$s2
/*  f15740c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f157410:	0138c821 */ 	addu	$t9,$t1,$t8
/*  f157414:	00007012 */ 	mflo	$t6
/*  f157418:	00ee7821 */ 	addu	$t7,$a3,$t6
/*  f15741c:	8df8fe78 */ 	lw	$t8,-0x188($t7)
/*  f157420:	03130019 */ 	multu	$t8,$s3
/*  f157424:	00007012 */ 	mflo	$t6
/*  f157428:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f15742c:	032fc021 */ 	addu	$t8,$t9,$t7
/*  f157430:	8f0e0000 */ 	lw	$t6,0x0($t8)
/*  f157434:	8e990000 */ 	lw	$t9,0x0($s4)
/*  f157438:	9158fe77 */ 	lbu	$t8,-0x189($t2)
/*  f15743c:	8caf0000 */ 	lw	$t7,0x0($a1)
/*  f157440:	01d92021 */ 	addu	$a0,$t6,$t9
/*  f157444:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f157448:	01f87021 */ 	addu	$t6,$t7,$t8
/*  f15744c:	01c4c823 */ 	subu	$t9,$t6,$a0
/*  f157450:	acb90000 */ 	sw	$t9,0x0($a1)
/*  f157454:	10000017 */ 	b	.L0f1574b4
/*  f157458:	90c3ffff */ 	lbu	$v1,-0x1($a2)
/*  f15745c:	290100c0 */ 	slti	$at,$t0,0xc0
.L0f157460:
/*  f157460:	5020000c */ 	beqzl	$at,.L0f157494
/*  f157464:	8d380000 */ 	lw	$t8,0x0($t1)
/*  f157468:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f15746c:	8e980000 */ 	lw	$t8,0x0($s4)
/*  f157470:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f157474:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f157478:	01f82021 */ 	addu	$a0,$t7,$t8
/*  f15747c:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f157480:	01c4c823 */ 	subu	$t9,$t6,$a0
/*  f157484:	272f000b */ 	addiu	$t7,$t9,0xb
/*  f157488:	1000000a */ 	b	.L0f1574b4
/*  f15748c:	acaf0000 */ 	sw	$t7,0x0($a1)
/*  f157490:	8d380000 */ 	lw	$t8,0x0($t1)
.L0f157494:
/*  f157494:	8e8e0000 */ 	lw	$t6,0x0($s4)
/*  f157498:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f15749c:	24c60002 */ 	addiu	$a2,$a2,0x2
/*  f1574a0:	030e2021 */ 	addu	$a0,$t8,$t6
/*  f1574a4:	2484ffff */ 	addiu	$a0,$a0,-1
/*  f1574a8:	03247823 */ 	subu	$t7,$t9,$a0
/*  f1574ac:	25f8000f */ 	addiu	$t8,$t7,0xf
/*  f1574b0:	acb80000 */ 	sw	$t8,0x0($a1)
.L0f1574b4:
/*  f1574b4:	90c40000 */ 	lbu	$a0,0x0($a2)
/*  f1574b8:	1480ffb3 */ 	bnez	$a0,.L0f157388
/*  f1574bc:	00804025 */ 	or	$t0,$a0,$zero
.L0f1574c0:
/*  f1574c0:	3c0e8008 */ 	lui	$t6,%hi(g_ScaleX)
/*  f1574c4:	8dcefac0 */ 	lw	$t6,%lo(g_ScaleX)($t6)
/*  f1574c8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1574cc:	3c0f8008 */ 	lui	$t7,%hi(var8007fad0)
/*  f1574d0:	55c10008 */ 	bnel	$t6,$at,.L0f1574f4
/*  f1574d4:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f1574d8:	8cb90000 */ 	lw	$t9,0x0($a1)
/*  f1574dc:	8deffad0 */ 	lw	$t7,%lo(var8007fad0)($t7)
/*  f1574e0:	032f0019 */ 	multu	$t9,$t7
/*  f1574e4:	0000c012 */ 	mflo	$t8
/*  f1574e8:	acb80000 */ 	sw	$t8,0x0($a1)
/*  f1574ec:	00000000 */ 	nop
/*  f1574f0:	8cae0000 */ 	lw	$t6,0x0($a1)
.L0f1574f4:
/*  f1574f4:	01c2082a */ 	slt	$at,$t6,$v0
/*  f1574f8:	50200003 */ 	beqzl	$at,.L0f157508
/*  f1574fc:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f157500:	aca20000 */ 	sw	$v0,0x0($a1)
/*  f157504:	8fb00004 */ 	lw	$s0,0x4($sp)
.L0f157508:
/*  f157508:	8fb10008 */ 	lw	$s1,0x8($sp)
/*  f15750c:	8fb2000c */ 	lw	$s2,0xc($sp)
/*  f157510:	8fb30010 */ 	lw	$s3,0x10($sp)
/*  f157514:	8fb40014 */ 	lw	$s4,0x14($sp)
/*  f157518:	03e00008 */ 	jr	$ra
/*  f15751c:	27bd0018 */ 	addiu	$sp,$sp,0x18
);
#endif

// Mismatch: Goal moves textheight to s0 then uses a0 for text[i] and/or
// thischar.
//void textMeasure(s32 *textheight, s32 *textwidth, char *text, struct fontchar *font1, struct font *font2, s32 lineheight)
//{
//	s32 thischar;
//	s32 prevchar;
//	s32 longest;
//	s32 i;
//	s32 tmp;
//
//	*textheight = 0;
//	prevchar = 'H'; // Just a default - presumably chosen for its flat right edge
//	longest = 0;
//	*textwidth = 0;
//
//	// 324
//	if (lineheight == 0) {
//		lineheight = font1['['].baseline + font1['['].height;
//	}
//
//	// 344
//	// Force minimum height for non-English languages
//	if (g_Jpn && lineheight < 14) {
//		lineheight = 14;
//	}
//
//	// 358
//	if (text) {
//		thischar = text[0];
//
//		for (i = 0; text[i] != '\0'; ) {
//			// 388
//			if (thischar == ' ') {
//				// Space
//				if (text[i + 1] != '\n') {
//					*textwidth += 5;
//				}
//
//				prevchar = 'H';
//				i++;
//			} else /*3b4*/ if (thischar == '\n') {
//				// Line break
//				if (*textwidth > longest) {
//					longest = *textwidth;
//				}
//
//				*textwidth = 0;
//				*textheight += lineheight;
//				i++;
//			} else /*3e8*/ {
//				if (thischar < 0x80) {
//					// Normal single-byte character
//					u8 character = thischar;
//					s32 b = font1[character - 0x21].unk04;
//					s32 a = font1[prevchar - 0x21].unk04;
//
//					tmp = font2->unk000[b + a * 13] + var8007fac4 - 1;
//					tmp = font1[character - 0x21].width + tmp;
//
//					*textwidth = *textwidth - tmp;
//
//					prevchar = text[i];
//					i++;
//				} else /*460*/ if (thischar < 0xc0) {
//					// Multi-byte character
//					tmp = font2->unk000[0] + var8007fac4 - 1;
//					*textwidth = *textwidth - tmp + 11;
//					i += 2;
//				} else {
//					// Multi-byte character
//					// 494
//					tmp = font2->unk000[0] + var8007fac4 - 1;
//					*textwidth = *textwidth - tmp + 15;
//					i += 2;
//				}
//
//				if (textheight);
//			}
//
//			thischar = text[i];
//		}
//	}
//
//	if (g_ScaleX == 1) {
//		*textwidth *= var8007fad0;
//	}
//
//	// @bug? Shouldn't this go before the scale check?
//	if (*textwidth < longest) {
//		*textwidth = longest;
//	}
//}

#if VERSION == VERSION_JPN_FINAL
bool func0f157768jf(s32 arg0, s32 arg1)
{
	return false;
}
#endif

#if VERSION >= VERSION_JPN_FINAL
GLOBAL_ASM(
glabel textWrap
/*  f157778:	27bdff48 */ 	addiu	$sp,$sp,-184
/*  f15777c:	afbe0040 */ 	sw	$s8,0x40($sp)
/*  f157780:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f157784:	240e0001 */ 	li	$t6,0x1
/*  f157788:	00c09825 */ 	move	$s3,$a2
/*  f15778c:	00a0f025 */ 	move	$s8,$a1
/*  f157790:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f157794:	afb7003c */ 	sw	$s7,0x3c($sp)
/*  f157798:	afb60038 */ 	sw	$s6,0x38($sp)
/*  f15779c:	afb50034 */ 	sw	$s5,0x34($sp)
/*  f1577a0:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f1577a4:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f1577a8:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f1577ac:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1577b0:	afa400b8 */ 	sw	$a0,0xb8($sp)
/*  f1577b4:	afa700c4 */ 	sw	$a3,0xc4($sp)
/*  f1577b8:	afa000b4 */ 	sw	$zero,0xb4($sp)
/*  f1577bc:	afa000a4 */ 	sw	$zero,0xa4($sp)
/*  f1577c0:	afae00a0 */ 	sw	$t6,0xa0($sp)
/*  f1577c4:	0000a825 */ 	move	$s5,$zero
.JF0f1577c8:
/*  f1577c8:	afa000a8 */ 	sw	$zero,0xa8($sp)
/*  f1577cc:	00003825 */ 	move	$a3,$zero
/*  f1577d0:	afa00070 */ 	sw	$zero,0x70($sp)
/*  f1577d4:	00009025 */ 	move	$s2,$zero
/*  f1577d8:	27b40074 */ 	addiu	$s4,$sp,0x74
/*  f1577dc:	93c30000 */ 	lbu	$v1,0x0($s8)
.JF0f1577e0:
/*  f1577e0:	00008825 */ 	move	$s1,$zero
/*  f1577e4:	0000b825 */ 	move	$s7,$zero
/*  f1577e8:	28610080 */ 	slti	$at,$v1,0x80
/*  f1577ec:	10200003 */ 	beqz	$at,.JF0f1577fc
/*  f1577f0:	0000b025 */ 	move	$s6,$zero
/*  f1577f4:	1000000f */ 	b	.JF0f157834
/*  f1577f8:	306400ff */ 	andi	$a0,$v1,0xff
.JF0f1577fc:
/*  f1577fc:	93d00001 */ 	lbu	$s0,0x1($s8)
/*  f157800:	306f007f */ 	andi	$t7,$v1,0x7f
/*  f157804:	000fc1c0 */ 	sll	$t8,$t7,0x7
/*  f157808:	3219007f */ 	andi	$t9,$s0,0x7f
/*  f15780c:	03191025 */ 	or	$v0,$t8,$t9
/*  f157810:	24170001 */ 	li	$s7,0x1
/*  f157814:	3051ffff */ 	andi	$s1,$v0,0xffff
/*  f157818:	3044ffff */ 	andi	$a0,$v0,0xffff
/*  f15781c:	0fc551e1 */ 	jal	func0f154784jf
/*  f157820:	afa70094 */ 	sw	$a3,0x94($sp)
/*  f157824:	8fa70094 */ 	lw	$a3,0x94($sp)
/*  f157828:	16000002 */ 	bnez	$s0,.JF0f157834
/*  f15782c:	304400ff */ 	andi	$a0,$v0,0xff
/*  f157830:	0000b825 */ 	move	$s7,$zero
.JF0f157834:
/*  f157834:	1480001d */ 	bnez	$a0,.JF0f1578ac
/*  f157838:	00801025 */ 	move	$v0,$a0
/*  f15783c:	12e00050 */ 	beqz	$s7,.JF0f157980
/*  f157840:	00008025 */ 	move	$s0,$zero
/*  f157844:	2a210034 */ 	slti	$at,$s1,0x34
/*  f157848:	14200005 */ 	bnez	$at,.JF0f157860
/*  f15784c:	02201025 */ 	move	$v0,$s1
/*  f157850:	2a21004e */ 	slti	$at,$s1,0x4e
/*  f157854:	50200003 */ 	beqzl	$at,.JF0f157864
/*  f157858:	284100af */ 	slti	$at,$v0,0xaf
/*  f15785c:	24100001 */ 	li	$s0,0x1
.JF0f157860:
/*  f157860:	284100af */ 	slti	$at,$v0,0xaf
.JF0f157864:
/*  f157864:	14200004 */ 	bnez	$at,.JF0f157878
/*  f157868:	284100b8 */ 	slti	$at,$v0,0xb8
/*  f15786c:	50200003 */ 	beqzl	$at,.JF0f15787c
/*  f157870:	24010104 */ 	li	$at,0x104
/*  f157874:	24100001 */ 	li	$s0,0x1
.JF0f157878:
/*  f157878:	24010104 */ 	li	$at,0x104
.JF0f15787c:
/*  f15787c:	54410003 */ 	bnel	$v0,$at,.JF0f15788c
/*  f157880:	24010105 */ 	li	$at,0x105
/*  f157884:	24100001 */ 	li	$s0,0x1
/*  f157888:	24010105 */ 	li	$at,0x105
.JF0f15788c:
/*  f15788c:	14410002 */ 	bne	$v0,$at,.JF0f157898
/*  f157890:	00000000 */ 	nop
/*  f157894:	24100001 */ 	li	$s0,0x1
.JF0f157898:
/*  f157898:	16a00002 */ 	bnez	$s5,.JF0f1578a4
/*  f15789c:	00000000 */ 	nop
/*  f1578a0:	24100001 */ 	li	$s0,0x1
.JF0f1578a4:
/*  f1578a4:	10000036 */ 	b	.JF0f157980
/*  f1578a8:	2416000b */ 	li	$s6,0xb
.JF0f1578ac:
/*  f1578ac:	28410021 */ 	slti	$at,$v0,0x21
/*  f1578b0:	14200003 */ 	bnez	$at,.JF0f1578c0
/*  f1578b4:	8faa00c4 */ 	lw	$t2,0xc4($sp)
/*  f1578b8:	10000002 */ 	b	.JF0f1578c4
/*  f1578bc:	24100001 */ 	li	$s0,0x1
.JF0f1578c0:
/*  f1578c0:	00008025 */ 	move	$s0,$zero
.JF0f1578c4:
/*  f1578c4:	00025880 */ 	sll	$t3,$v0,0x2
/*  f1578c8:	01625823 */ 	subu	$t3,$t3,$v0
/*  f1578cc:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f1578d0:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f1578d4:	1600000c */ 	bnez	$s0,.JF0f157908
/*  f1578d8:	9196fe78 */ 	lbu	$s6,-0x188($t4)
/*  f1578dc:	16a0000a */ 	bnez	$s5,.JF0f157908
/*  f1578e0:	00000000 */ 	nop
/*  f1578e4:	10400004 */ 	beqz	$v0,.JF0f1578f8
/*  f1578e8:	24010020 */ 	li	$at,0x20
/*  f1578ec:	50410003 */ 	beql	$v0,$at,.JF0f1578fc
/*  f1578f0:	24010020 */ 	li	$at,0x20
/*  f1578f4:	24100001 */ 	li	$s0,0x1
.JF0f1578f8:
/*  f1578f8:	24010020 */ 	li	$at,0x20
.JF0f1578fc:
/*  f1578fc:	14410002 */ 	bne	$v0,$at,.JF0f157908
/*  f157900:	240d0001 */ 	li	$t5,0x1
/*  f157904:	afad0070 */ 	sw	$t5,0x70($sp)
.JF0f157908:
/*  f157908:	12a0001d */ 	beqz	$s5,.JF0f157980
/*  f15790c:	28410041 */ 	slti	$at,$v0,0x41
/*  f157910:	14200002 */ 	bnez	$at,.JF0f15791c
/*  f157914:	2841005b */ 	slti	$at,$v0,0x5b
/*  f157918:	14200009 */ 	bnez	$at,.JF0f157940
.JF0f15791c:
/*  f15791c:	28410061 */ 	slti	$at,$v0,0x61
/*  f157920:	14200002 */ 	bnez	$at,.JF0f15792c
/*  f157924:	2841007b */ 	slti	$at,$v0,0x7b
/*  f157928:	14200005 */ 	bnez	$at,.JF0f157940
.JF0f15792c:
/*  f15792c:	28410030 */ 	slti	$at,$v0,0x30
/*  f157930:	14200013 */ 	bnez	$at,.JF0f157980
/*  f157934:	2841003a */ 	slti	$at,$v0,0x3a
/*  f157938:	10200011 */ 	beqz	$at,.JF0f157980
/*  f15793c:	00000000 */ 	nop
.JF0f157940:
/*  f157940:	9285ffff */ 	lbu	$a1,-0x1($s4)
/*  f157944:	28a10080 */ 	slti	$at,$a1,0x80
/*  f157948:	1420000d */ 	bnez	$at,.JF0f157980
/*  f15794c:	00000000 */ 	nop
/*  f157950:	9282fffe */ 	lbu	$v0,-0x2($s4)
/*  f157954:	30b8007f */ 	andi	$t8,$a1,0x7f
/*  f157958:	afa70094 */ 	sw	$a3,0x94($sp)
/*  f15795c:	304e007f */ 	andi	$t6,$v0,0x7f
/*  f157960:	000e79c0 */ 	sll	$t7,$t6,0x7
/*  f157964:	01f82025 */ 	or	$a0,$t7,$t8
/*  f157968:	3099ffff */ 	andi	$t9,$a0,0xffff
/*  f15796c:	0fc551e1 */ 	jal	func0f154784jf
/*  f157970:	03202025 */ 	move	$a0,$t9
/*  f157974:	14400002 */ 	bnez	$v0,.JF0f157980
/*  f157978:	8fa70094 */ 	lw	$a3,0x94($sp)
/*  f15797c:	00008025 */ 	move	$s0,$zero
.JF0f157980:
/*  f157980:	1200000d */ 	beqz	$s0,.JF0f1579b8
/*  f157984:	00000000 */ 	nop
/*  f157988:	93ca0000 */ 	lbu	$t2,0x0($s8)
/*  f15798c:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f157990:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f157994:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f157998:	12e00006 */ 	beqz	$s7,.JF0f1579b4
/*  f15799c:	a28affff */ 	sb	$t2,-0x1($s4)
/*  f1579a0:	93cb0000 */ 	lbu	$t3,0x0($s8)
/*  f1579a4:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f1579a8:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f1579ac:	26940001 */ 	addiu	$s4,$s4,0x1
/*  f1579b0:	a28bffff */ 	sb	$t3,-0x1($s4)
.JF0f1579b4:
/*  f1579b4:	00f63821 */ 	addu	$a3,$a3,$s6
.JF0f1579b8:
/*  f1579b8:	5600ff89 */ 	bnezl	$s0,.JF0f1577e0
/*  f1579bc:	93c30000 */ 	lbu	$v1,0x0($s8)
/*  f1579c0:	a2800000 */ 	sb	$zero,0x0($s4)
/*  f1579c4:	8fac00c8 */ 	lw	$t4,0xc8($sp)
/*  f1579c8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1579cc:	8fa700c4 */ 	lw	$a3,0xc4($sp)
/*  f1579d0:	27a400a4 */ 	addiu	$a0,$sp,0xa4
/*  f1579d4:	27a500a8 */ 	addiu	$a1,$sp,0xa8
/*  f1579d8:	27a60074 */ 	addiu	$a2,$sp,0x74
/*  f1579dc:	0fc55d49 */ 	jal	textMeasure
/*  f1579e0:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f1579e4:	8fad00b4 */ 	lw	$t5,0xb4($sp)
/*  f1579e8:	8fae00a8 */ 	lw	$t6,0xa8($sp)
/*  f1579ec:	8fb800b8 */ 	lw	$t8,0xb8($sp)
/*  f1579f0:	3c088008 */ 	lui	$t0,0x8008
/*  f1579f4:	01ae7821 */ 	addu	$t7,$t5,$t6
/*  f1579f8:	030f082a */ 	slt	$at,$t8,$t7
/*  f1579fc:	25080104 */ 	addiu	$t0,$t0,0x104
/*  f157a00:	24090020 */ 	li	$t1,0x20
/*  f157a04:	14200003 */ 	bnez	$at,.JF0f157a14
/*  f157a08:	afaf00b4 */ 	sw	$t7,0xb4($sp)
/*  f157a0c:	10000002 */ 	b	.JF0f157a18
/*  f157a10:	24030001 */ 	li	$v1,0x1
.JF0f157a14:
/*  f157a14:	00001825 */ 	move	$v1,$zero
.JF0f157a18:
/*  f157a18:	93c20000 */ 	lbu	$v0,0x0($s8)
/*  f157a1c:	2401000a */ 	li	$at,0xa
/*  f157a20:	240d000a */ 	li	$t5,0xa
/*  f157a24:	1441001d */ 	bne	$v0,$at,.JF0f157a9c
/*  f157a28:	00000000 */ 	nop
/*  f157a2c:	1460000f */ 	bnez	$v1,.JF0f157a6c
/*  f157a30:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f157a34:	2419000a */ 	li	$t9,0xa
/*  f157a38:	a2790000 */ 	sb	$t9,0x0($s3)
/*  f157a3c:	8d0a0000 */ 	lw	$t2,0x0($t0)
/*  f157a40:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f157a44:	19400009 */ 	blez	$t2,.JF0f157a6c
/*  f157a48:	00000000 */ 	nop
/*  f157a4c:	a2690000 */ 	sb	$t1,0x0($s3)
.JF0f157a50:
/*  f157a50:	8d0b0000 */ 	lw	$t3,0x0($t0)
/*  f157a54:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f157a58:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f157a5c:	024b082a */ 	slt	$at,$s2,$t3
/*  f157a60:	5420fffb */ 	bnezl	$at,.JF0f157a50
/*  f157a64:	a2690000 */ 	sb	$t1,0x0($s3)
/*  f157a68:	00009025 */ 	move	$s2,$zero
.JF0f157a6c:
/*  f157a6c:	1aa00007 */ 	blez	$s5,.JF0f157a8c
/*  f157a70:	27a20074 */ 	addiu	$v0,$sp,0x74
.JF0f157a74:
/*  f157a74:	904c0000 */ 	lbu	$t4,0x0($v0)
/*  f157a78:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f157a7c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f157a80:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f157a84:	1655fffb */ 	bne	$s2,$s5,.JF0f157a74
/*  f157a88:	a26cffff */ 	sb	$t4,-0x1($s3)
.JF0f157a8c:
/*  f157a8c:	afa000b4 */ 	sw	$zero,0xb4($sp)
/*  f157a90:	a26d0000 */ 	sb	$t5,0x0($s3)
/*  f157a94:	10000048 */ 	b	.JF0f157bb8
/*  f157a98:	26730001 */ 	addiu	$s3,$s3,0x1
.JF0f157a9c:
/*  f157a9c:	1440001c */ 	bnez	$v0,.JF0f157b10
/*  f157aa0:	00000000 */ 	nop
/*  f157aa4:	1460000f */ 	bnez	$v1,.JF0f157ae4
/*  f157aa8:	afa000a0 */ 	sw	$zero,0xa0($sp)
/*  f157aac:	240e000a */ 	li	$t6,0xa
/*  f157ab0:	a26e0000 */ 	sb	$t6,0x0($s3)
/*  f157ab4:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f157ab8:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f157abc:	1b000009 */ 	blez	$t8,.JF0f157ae4
/*  f157ac0:	00000000 */ 	nop
/*  f157ac4:	a2690000 */ 	sb	$t1,0x0($s3)
.JF0f157ac8:
/*  f157ac8:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f157acc:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f157ad0:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f157ad4:	024f082a */ 	slt	$at,$s2,$t7
/*  f157ad8:	5420fffb */ 	bnezl	$at,.JF0f157ac8
/*  f157adc:	a2690000 */ 	sb	$t1,0x0($s3)
/*  f157ae0:	00009025 */ 	move	$s2,$zero
.JF0f157ae4:
/*  f157ae4:	1aa00008 */ 	blez	$s5,.JF0f157b08
/*  f157ae8:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f157aec:	27a20074 */ 	addiu	$v0,$sp,0x74
.JF0f157af0:
/*  f157af0:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f157af4:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f157af8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f157afc:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f157b00:	1655fffb */ 	bne	$s2,$s5,.JF0f157af0
/*  f157b04:	a279ffff */ 	sb	$t9,-0x1($s3)
.JF0f157b08:
/*  f157b08:	1000002b */ 	b	.JF0f157bb8
/*  f157b0c:	a2600000 */ 	sb	$zero,0x0($s3)
.JF0f157b10:
/*  f157b10:	14600013 */ 	bnez	$v1,.JF0f157b60
/*  f157b14:	240a000a */ 	li	$t2,0xa
/*  f157b18:	a26a0000 */ 	sb	$t2,0x0($s3)
/*  f157b1c:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f157b20:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f157b24:	5840000a */ 	blezl	$v0,.JF0f157b50
/*  f157b28:	8fac00a8 */ 	lw	$t4,0xa8($sp)
/*  f157b2c:	a2690000 */ 	sb	$t1,0x0($s3)
.JF0f157b30:
/*  f157b30:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f157b34:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f157b38:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f157b3c:	0242082a */ 	slt	$at,$s2,$v0
/*  f157b40:	5420fffb */ 	bnezl	$at,.JF0f157b30
/*  f157b44:	a2690000 */ 	sb	$t1,0x0($s3)
/*  f157b48:	00009025 */ 	move	$s2,$zero
/*  f157b4c:	8fac00a8 */ 	lw	$t4,0xa8($sp)
.JF0f157b50:
/*  f157b50:	00025880 */ 	sll	$t3,$v0,0x2
/*  f157b54:	01625821 */ 	addu	$t3,$t3,$v0
/*  f157b58:	016c6821 */ 	addu	$t5,$t3,$t4
/*  f157b5c:	afad00b4 */ 	sw	$t5,0xb4($sp)
.JF0f157b60:
/*  f157b60:	1aa00007 */ 	blez	$s5,.JF0f157b80
/*  f157b64:	27a20074 */ 	addiu	$v0,$sp,0x74
.JF0f157b68:
/*  f157b68:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f157b6c:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f157b70:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f157b74:	26730001 */ 	addiu	$s3,$s3,0x1
/*  f157b78:	1655fffb */ 	bne	$s2,$s5,.JF0f157b68
/*  f157b7c:	a26effff */ 	sb	$t6,-0x1($s3)
.JF0f157b80:
/*  f157b80:	93c20000 */ 	lbu	$v0,0x0($s8)
/*  f157b84:	24010020 */ 	li	$at,0x20
/*  f157b88:	8fb80070 */ 	lw	$t8,0x70($sp)
/*  f157b8c:	10410002 */ 	beq	$v0,$at,.JF0f157b98
/*  f157b90:	8faf00b4 */ 	lw	$t7,0xb4($sp)
/*  f157b94:	13000008 */ 	beqz	$t8,.JF0f157bb8
.JF0f157b98:
/*  f157b98:	28410080 */ 	slti	$at,$v0,0x80
/*  f157b9c:	14200002 */ 	bnez	$at,.JF0f157ba8
/*  f157ba0:	25f90005 */ 	addiu	$t9,$t7,0x5
/*  f157ba4:	27de0001 */ 	addiu	$s8,$s8,0x1
.JF0f157ba8:
/*  f157ba8:	afb900b4 */ 	sw	$t9,0xb4($sp)
/*  f157bac:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f157bb0:	a2690000 */ 	sb	$t1,0x0($s3)
/*  f157bb4:	26730001 */ 	addiu	$s3,$s3,0x1
.JF0f157bb8:
/*  f157bb8:	8faa00a0 */ 	lw	$t2,0xa0($sp)
/*  f157bbc:	24010001 */ 	li	$at,0x1
/*  f157bc0:	5141ff01 */ 	beql	$t2,$at,.JF0f1577c8
/*  f157bc4:	0000a825 */ 	move	$s5,$zero
/*  f157bc8:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f157bcc:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f157bd0:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f157bd4:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f157bd8:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f157bdc:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f157be0:	8fb50034 */ 	lw	$s5,0x34($sp)
/*  f157be4:	8fb60038 */ 	lw	$s6,0x38($sp)
/*  f157be8:	8fb7003c */ 	lw	$s7,0x3c($sp)
/*  f157bec:	8fbe0040 */ 	lw	$s8,0x40($sp)
/*  f157bf0:	03e00008 */ 	jr	$ra
/*  f157bf4:	27bd00b8 */ 	addiu	$sp,$sp,0xb8
);
#elif VERSION >= VERSION_PAL_FINAL
GLOBAL_ASM(
glabel textWrap
/*  f15848c:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f158490:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f158494:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f158498:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f15849c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f1584a0:	00c08025 */ 	move	$s0,$a2
/*  f1584a4:	00a09025 */ 	move	$s2,$a1
/*  f1584a8:	00e09825 */ 	move	$s3,$a3
/*  f1584ac:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f1584b0:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f1584b4:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f1584b8:	00005825 */ 	move	$t3,$zero
/*  f1584bc:	afa00074 */ 	sw	$zero,0x74($sp)
/*  f1584c0:	240d0001 */ 	li	$t5,0x1
/*  f1584c4:	27b40044 */ 	addiu	$s4,$sp,0x44
/*  f1584c8:	240a000c */ 	li	$t2,0xc
.PF0f1584cc:
/*  f1584cc:	afa00078 */ 	sw	$zero,0x78($sp)
/*  f1584d0:	92430000 */ 	lbu	$v1,0x0($s2)
/*  f1584d4:	00008825 */ 	move	$s1,$zero
/*  f1584d8:	00002025 */ 	move	$a0,$zero
/*  f1584dc:	28610021 */ 	slti	$at,$v1,0x21
/*  f1584e0:	14200022 */ 	bnez	$at,.PF0f15856c
/*  f1584e4:	02803025 */ 	move	$a2,$s4
/*  f1584e8:	3c058008 */ 	lui	$a1,0x8008
/*  f1584ec:	8ca54660 */ 	lw	$a1,0x4660($a1)
/*  f1584f0:	27a20044 */ 	addiu	$v0,$sp,0x44
/*  f1584f4:	a0430000 */ 	sb	$v1,0x0($v0)
.PF0f1584f8:
/*  f1584f8:	924e0000 */ 	lbu	$t6,0x0($s2)
/*  f1584fc:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f158500:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f158504:	01ca0019 */ 	multu	$t6,$t2
/*  f158508:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f15850c:	00007812 */ 	mflo	$t7
/*  f158510:	026fc021 */ 	addu	$t8,$s3,$t7
/*  f158514:	9319fe77 */ 	lbu	$t9,-0x189($t8)
/*  f158518:	10a00010 */ 	beqz	$a1,.PF0f15855c
/*  f15851c:	00992021 */ 	addu	$a0,$a0,$t9
/*  f158520:	904effff */ 	lbu	$t6,-0x1($v0)
/*  f158524:	29c10080 */ 	slti	$at,$t6,0x80
/*  f158528:	5420000d */ 	bnezl	$at,.PF0f158560
/*  f15852c:	92430000 */ 	lbu	$v1,0x0($s2)
/*  f158530:	924f0000 */ 	lbu	$t7,0x0($s2)
/*  f158534:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f158538:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f15853c:	a04f0000 */ 	sb	$t7,0x0($v0)
/*  f158540:	9258ffff */ 	lbu	$t8,-0x1($s2)
/*  f158544:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f158548:	030a0019 */ 	multu	$t8,$t2
/*  f15854c:	0000c812 */ 	mflo	$t9
/*  f158550:	02797021 */ 	addu	$t6,$s3,$t9
/*  f158554:	91cffe77 */ 	lbu	$t7,-0x189($t6)
/*  f158558:	008f2021 */ 	addu	$a0,$a0,$t7
.PF0f15855c:
/*  f15855c:	92430000 */ 	lbu	$v1,0x0($s2)
.PF0f158560:
/*  f158560:	28610021 */ 	slti	$at,$v1,0x21
/*  f158564:	5020ffe4 */ 	beqzl	$at,.PF0f1584f8
/*  f158568:	a0430000 */ 	sb	$v1,0x0($v0)
.PF0f15856c:
/*  f15856c:	0291c021 */ 	addu	$t8,$s4,$s1
/*  f158570:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f158574:	8fb90098 */ 	lw	$t9,0x98($sp)
/*  f158578:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f15857c:	afab0084 */ 	sw	$t3,0x84($sp)
/*  f158580:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f158584:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f158588:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f15858c:	02603825 */ 	move	$a3,$s3
/*  f158590:	0fc5609a */ 	jal	textMeasure
/*  f158594:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f158598:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f15859c:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f1585a0:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f1585a4:	3c088008 */ 	lui	$t0,0x8008
/*  f1585a8:	016e5821 */ 	addu	$t3,$t3,$t6
/*  f1585ac:	01eb082a */ 	slt	$at,$t7,$t3
/*  f1585b0:	2508002c */ 	addiu	$t0,$t0,0x2c
/*  f1585b4:	24090020 */ 	li	$t1,0x20
/*  f1585b8:	240a000c */ 	li	$t2,0xc
/*  f1585bc:	240c000a */ 	li	$t4,0xa
/*  f1585c0:	14200003 */ 	bnez	$at,.PF0f1585d0
/*  f1585c4:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f1585c8:	10000002 */ 	b	.PF0f1585d4
/*  f1585cc:	24040001 */ 	li	$a0,0x1
.PF0f1585d0:
/*  f1585d0:	00002025 */ 	move	$a0,$zero
.PF0f1585d4:
/*  f1585d4:	92420000 */ 	lbu	$v0,0x0($s2)
/*  f1585d8:	2401000a */ 	li	$at,0xa
/*  f1585dc:	5441001d */ 	bnel	$v0,$at,.PF0f158654
/*  f1585e0:	24010020 */ 	li	$at,0x20
/*  f1585e4:	1480000e */ 	bnez	$a0,.PF0f158620
/*  f1585e8:	00001825 */ 	move	$v1,$zero
/*  f1585ec:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f1585f0:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f1585f4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1585f8:	1b000009 */ 	blez	$t8,.PF0f158620
/*  f1585fc:	00000000 */ 	nop
/*  f158600:	a2090000 */ 	sb	$t1,0x0($s0)
.PF0f158604:
/*  f158604:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f158608:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f15860c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f158610:	0079082a */ 	slt	$at,$v1,$t9
/*  f158614:	5420fffb */ 	bnezl	$at,.PF0f158604
/*  f158618:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f15861c:	00001825 */ 	move	$v1,$zero
.PF0f158620:
/*  f158620:	1a200008 */ 	blez	$s1,.PF0f158644
/*  f158624:	00005825 */ 	move	$t3,$zero
/*  f158628:	27a20044 */ 	addiu	$v0,$sp,0x44
.PF0f15862c:
/*  f15862c:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f158630:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f158634:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f158638:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15863c:	1471fffb */ 	bne	$v1,$s1,.PF0f15862c
/*  f158640:	a20effff */ 	sb	$t6,-0x1($s0)
.PF0f158644:
/*  f158644:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f158648:	1000003d */ 	b	.PF0f158740
/*  f15864c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f158650:	24010020 */ 	li	$at,0x20
.PF0f158654:
/*  f158654:	14410020 */ 	bne	$v0,$at,.PF0f1586d8
/*  f158658:	00000000 */ 	nop
/*  f15865c:	14800012 */ 	bnez	$a0,.PF0f1586a8
/*  f158660:	00001825 */ 	move	$v1,$zero
/*  f158664:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f158668:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f15866c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f158670:	5840000a */ 	blezl	$v0,.PF0f15869c
/*  f158674:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f158678:	a2090000 */ 	sb	$t1,0x0($s0)
.PF0f15867c:
/*  f15867c:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f158680:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f158684:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f158688:	0062082a */ 	slt	$at,$v1,$v0
/*  f15868c:	5420fffb */ 	bnezl	$at,.PF0f15867c
/*  f158690:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f158694:	00001825 */ 	move	$v1,$zero
/*  f158698:	8fb80078 */ 	lw	$t8,0x78($sp)
.PF0f15869c:
/*  f15869c:	00027880 */ 	sll	$t7,$v0,0x2
/*  f1586a0:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f1586a4:	01f85821 */ 	addu	$t3,$t7,$t8
.PF0f1586a8:
/*  f1586a8:	1a200008 */ 	blez	$s1,.PF0f1586cc
/*  f1586ac:	256b0005 */ 	addiu	$t3,$t3,0x5
/*  f1586b0:	27a20044 */ 	addiu	$v0,$sp,0x44
.PF0f1586b4:
/*  f1586b4:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f1586b8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1586bc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1586c0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1586c4:	1471fffb */ 	bne	$v1,$s1,.PF0f1586b4
/*  f1586c8:	a219ffff */ 	sb	$t9,-0x1($s0)
.PF0f1586cc:
/*  f1586cc:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f1586d0:	1000001b */ 	b	.PF0f158740
/*  f1586d4:	26100001 */ 	addiu	$s0,$s0,0x1
.PF0f1586d8:
/*  f1586d8:	14400019 */ 	bnez	$v0,.PF0f158740
/*  f1586dc:	00001825 */ 	move	$v1,$zero
/*  f1586e0:	1480000e */ 	bnez	$a0,.PF0f15871c
/*  f1586e4:	00006825 */ 	move	$t5,$zero
/*  f1586e8:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f1586ec:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f1586f0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1586f4:	19c00009 */ 	blez	$t6,.PF0f15871c
/*  f1586f8:	00000000 */ 	nop
/*  f1586fc:	a2090000 */ 	sb	$t1,0x0($s0)
.PF0f158700:
/*  f158700:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f158704:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f158708:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15870c:	006f082a */ 	slt	$at,$v1,$t7
/*  f158710:	5420fffb */ 	bnezl	$at,.PF0f158700
/*  f158714:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f158718:	00001825 */ 	move	$v1,$zero
.PF0f15871c:
/*  f15871c:	1a200007 */ 	blez	$s1,.PF0f15873c
/*  f158720:	27a20044 */ 	addiu	$v0,$sp,0x44
.PF0f158724:
/*  f158724:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f158728:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f15872c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f158730:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f158734:	1471fffb */ 	bne	$v1,$s1,.PF0f158724
/*  f158738:	a218ffff */ 	sb	$t8,-0x1($s0)
.PF0f15873c:
/*  f15873c:	a2000000 */ 	sb	$zero,0x0($s0)
.PF0f158740:
/*  f158740:	24010001 */ 	li	$at,0x1
/*  f158744:	11a1ff61 */ 	beq	$t5,$at,.PF0f1584cc
/*  f158748:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f15874c:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f158750:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f158754:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f158758:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f15875c:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f158760:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f158764:	03e00008 */ 	jr	$ra
/*  f158768:	27bd0088 */ 	addiu	$sp,$sp,0x88
);
#else
GLOBAL_ASM(
glabel textWrap
/*  f157520:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f157524:	afb40030 */ 	sw	$s4,0x30($sp)
/*  f157528:	afb3002c */ 	sw	$s3,0x2c($sp)
/*  f15752c:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f157530:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f157534:	00c08025 */ 	or	$s0,$a2,$zero
/*  f157538:	00a09025 */ 	or	$s2,$a1,$zero
/*  f15753c:	00e09825 */ 	or	$s3,$a3,$zero
/*  f157540:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f157544:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f157548:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f15754c:	00005825 */ 	or	$t3,$zero,$zero
/*  f157550:	afa00074 */ 	sw	$zero,0x74($sp)
/*  f157554:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f157558:	27b40044 */ 	addiu	$s4,$sp,0x44
/*  f15755c:	240a000c */ 	addiu	$t2,$zero,0xc
.L0f157560:
/*  f157560:	afa00078 */ 	sw	$zero,0x78($sp)
/*  f157564:	92440000 */ 	lbu	$a0,0x0($s2)
/*  f157568:	00008825 */ 	or	$s1,$zero,$zero
/*  f15756c:	00001825 */ 	or	$v1,$zero,$zero
/*  f157570:	28810021 */ 	slti	$at,$a0,0x21
/*  f157574:	1420001e */ 	bnez	$at,.L0f1575f0
/*  f157578:	27a50078 */ 	addiu	$a1,$sp,0x78
/*  f15757c:	27a20044 */ 	addiu	$v0,$sp,0x44
/*  f157580:	a0440000 */ 	sb	$a0,0x0($v0)
.L0f157584:
/*  f157584:	924e0000 */ 	lbu	$t6,0x0($s2)
/*  f157588:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f15758c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f157590:	01ca0019 */ 	multu	$t6,$t2
/*  f157594:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f157598:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f15759c:	29c10080 */ 	slti	$at,$t6,0x80
/*  f1575a0:	00007812 */ 	mflo	$t7
/*  f1575a4:	026fc021 */ 	addu	$t8,$s3,$t7
/*  f1575a8:	9319fe77 */ 	lbu	$t9,-0x189($t8)
/*  f1575ac:	1420000c */ 	bnez	$at,.L0f1575e0
/*  f1575b0:	00791821 */ 	addu	$v1,$v1,$t9
/*  f1575b4:	924f0000 */ 	lbu	$t7,0x0($s2)
/*  f1575b8:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1575bc:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f1575c0:	a04f0000 */ 	sb	$t7,0x0($v0)
/*  f1575c4:	9258ffff */ 	lbu	$t8,-0x1($s2)
/*  f1575c8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1575cc:	030a0019 */ 	multu	$t8,$t2
/*  f1575d0:	0000c812 */ 	mflo	$t9
/*  f1575d4:	02797021 */ 	addu	$t6,$s3,$t9
/*  f1575d8:	91cffe77 */ 	lbu	$t7,-0x189($t6)
/*  f1575dc:	006f1821 */ 	addu	$v1,$v1,$t7
.L0f1575e0:
/*  f1575e0:	92440000 */ 	lbu	$a0,0x0($s2)
/*  f1575e4:	28810021 */ 	slti	$at,$a0,0x21
/*  f1575e8:	5020ffe6 */ 	beqzl	$at,.L0f157584
/*  f1575ec:	a0440000 */ 	sb	$a0,0x0($v0)
.L0f1575f0:
/*  f1575f0:	0291c021 */ 	addu	$t8,$s4,$s1
/*  f1575f4:	a3000000 */ 	sb	$zero,0x0($t8)
/*  f1575f8:	8fb90098 */ 	lw	$t9,0x98($sp)
/*  f1575fc:	afad0070 */ 	sw	$t5,0x70($sp)
/*  f157600:	afab0084 */ 	sw	$t3,0x84($sp)
/*  f157604:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f157608:	27a40074 */ 	addiu	$a0,$sp,0x74
/*  f15760c:	02803025 */ 	or	$a2,$s4,$zero
/*  f157610:	02603825 */ 	or	$a3,$s3,$zero
/*  f157614:	0fc55cbe */ 	jal	textMeasure
/*  f157618:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f15761c:	8fab0084 */ 	lw	$t3,0x84($sp)
/*  f157620:	8fae0078 */ 	lw	$t6,0x78($sp)
/*  f157624:	8faf0088 */ 	lw	$t7,0x88($sp)
/*  f157628:	3c088008 */ 	lui	$t0,%hi(var8007facc)
/*  f15762c:	016e5821 */ 	addu	$t3,$t3,$t6
/*  f157630:	01eb082a */ 	slt	$at,$t7,$t3
/*  f157634:	2508facc */ 	addiu	$t0,$t0,%lo(var8007facc)
/*  f157638:	24090020 */ 	addiu	$t1,$zero,0x20
/*  f15763c:	240a000c */ 	addiu	$t2,$zero,0xc
/*  f157640:	240c000a */ 	addiu	$t4,$zero,0xa
/*  f157644:	14200003 */ 	bnez	$at,.L0f157654
/*  f157648:	8fad0070 */ 	lw	$t5,0x70($sp)
/*  f15764c:	10000002 */ 	b	.L0f157658
/*  f157650:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f157654:
/*  f157654:	00002025 */ 	or	$a0,$zero,$zero
.L0f157658:
/*  f157658:	92420000 */ 	lbu	$v0,0x0($s2)
/*  f15765c:	2401000a */ 	addiu	$at,$zero,0xa
/*  f157660:	5441001d */ 	bnel	$v0,$at,.L0f1576d8
/*  f157664:	24010020 */ 	addiu	$at,$zero,0x20
/*  f157668:	1480000e */ 	bnez	$a0,.L0f1576a4
/*  f15766c:	00001825 */ 	or	$v1,$zero,$zero
/*  f157670:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f157674:	8d180000 */ 	lw	$t8,0x0($t0)
/*  f157678:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15767c:	1b000009 */ 	blez	$t8,.L0f1576a4
/*  f157680:	00000000 */ 	nop
/*  f157684:	a2090000 */ 	sb	$t1,0x0($s0)
.L0f157688:
/*  f157688:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f15768c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f157690:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f157694:	0079082a */ 	slt	$at,$v1,$t9
/*  f157698:	5420fffb */ 	bnezl	$at,.L0f157688
/*  f15769c:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f1576a0:	00001825 */ 	or	$v1,$zero,$zero
.L0f1576a4:
/*  f1576a4:	1a200008 */ 	blez	$s1,.L0f1576c8
/*  f1576a8:	00005825 */ 	or	$t3,$zero,$zero
/*  f1576ac:	27a20044 */ 	addiu	$v0,$sp,0x44
.L0f1576b0:
/*  f1576b0:	904e0000 */ 	lbu	$t6,0x0($v0)
/*  f1576b4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1576b8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1576bc:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1576c0:	1471fffb */ 	bne	$v1,$s1,.L0f1576b0
/*  f1576c4:	a20effff */ 	sb	$t6,-0x1($s0)
.L0f1576c8:
/*  f1576c8:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f1576cc:	1000003d */ 	b	.L0f1577c4
/*  f1576d0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1576d4:	24010020 */ 	addiu	$at,$zero,0x20
.L0f1576d8:
/*  f1576d8:	14410020 */ 	bne	$v0,$at,.L0f15775c
/*  f1576dc:	00000000 */ 	nop
/*  f1576e0:	14800012 */ 	bnez	$a0,.L0f15772c
/*  f1576e4:	00001825 */ 	or	$v1,$zero,$zero
/*  f1576e8:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f1576ec:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f1576f0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1576f4:	5840000a */ 	blezl	$v0,.L0f157720
/*  f1576f8:	8fb80078 */ 	lw	$t8,0x78($sp)
/*  f1576fc:	a2090000 */ 	sb	$t1,0x0($s0)
.L0f157700:
/*  f157700:	8d020000 */ 	lw	$v0,0x0($t0)
/*  f157704:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f157708:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f15770c:	0062082a */ 	slt	$at,$v1,$v0
/*  f157710:	5420fffb */ 	bnezl	$at,.L0f157700
/*  f157714:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f157718:	00001825 */ 	or	$v1,$zero,$zero
/*  f15771c:	8fb80078 */ 	lw	$t8,0x78($sp)
.L0f157720:
/*  f157720:	00027880 */ 	sll	$t7,$v0,0x2
/*  f157724:	01e27821 */ 	addu	$t7,$t7,$v0
/*  f157728:	01f85821 */ 	addu	$t3,$t7,$t8
.L0f15772c:
/*  f15772c:	1a200008 */ 	blez	$s1,.L0f157750
/*  f157730:	256b0005 */ 	addiu	$t3,$t3,0x5
/*  f157734:	27a20044 */ 	addiu	$v0,$sp,0x44
.L0f157738:
/*  f157738:	90590000 */ 	lbu	$t9,0x0($v0)
/*  f15773c:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f157740:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f157744:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f157748:	1471fffb */ 	bne	$v1,$s1,.L0f157738
/*  f15774c:	a219ffff */ 	sb	$t9,-0x1($s0)
.L0f157750:
/*  f157750:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f157754:	1000001b */ 	b	.L0f1577c4
/*  f157758:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f15775c:
/*  f15775c:	14400019 */ 	bnez	$v0,.L0f1577c4
/*  f157760:	00001825 */ 	or	$v1,$zero,$zero
/*  f157764:	1480000e */ 	bnez	$a0,.L0f1577a0
/*  f157768:	00006825 */ 	or	$t5,$zero,$zero
/*  f15776c:	a20c0000 */ 	sb	$t4,0x0($s0)
/*  f157770:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*  f157774:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f157778:	19c00009 */ 	blez	$t6,.L0f1577a0
/*  f15777c:	00000000 */ 	nop
/*  f157780:	a2090000 */ 	sb	$t1,0x0($s0)
.L0f157784:
/*  f157784:	8d0f0000 */ 	lw	$t7,0x0($t0)
/*  f157788:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f15778c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f157790:	006f082a */ 	slt	$at,$v1,$t7
/*  f157794:	5420fffb */ 	bnezl	$at,.L0f157784
/*  f157798:	a2090000 */ 	sb	$t1,0x0($s0)
/*  f15779c:	00001825 */ 	or	$v1,$zero,$zero
.L0f1577a0:
/*  f1577a0:	1a200007 */ 	blez	$s1,.L0f1577c0
/*  f1577a4:	27a20044 */ 	addiu	$v0,$sp,0x44
.L0f1577a8:
/*  f1577a8:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f1577ac:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1577b0:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f1577b4:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f1577b8:	1471fffb */ 	bne	$v1,$s1,.L0f1577a8
/*  f1577bc:	a218ffff */ 	sb	$t8,-0x1($s0)
.L0f1577c0:
/*  f1577c0:	a2000000 */ 	sb	$zero,0x0($s0)
.L0f1577c4:
/*  f1577c4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1577c8:	11a1ff65 */ 	beq	$t5,$at,.L0f157560
/*  f1577cc:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f1577d0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f1577d4:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f1577d8:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f1577dc:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f1577e0:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*  f1577e4:	8fb40030 */ 	lw	$s4,0x30($sp)
/*  f1577e8:	03e00008 */ 	jr	$ra
/*  f1577ec:	27bd0088 */ 	addiu	$sp,$sp,0x88
);
#endif
