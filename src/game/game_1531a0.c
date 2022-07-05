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

#define SPACE_WIDTH 5

const char var7f1b73b0[] = "burncol";

#if VERSION == VERSION_JPN_FINAL
u8 jpnfill5[0x2a8];
#endif

struct var800a45d0 var800a45d0;
Gfx *var800a4634;
Gfx *var800a4638;
#if VERSION == VERSION_JPN_FINAL
struct fontchar g_TmpJpnChar;
#endif
u32 var800a463c;

#if VERSION == VERSION_JPN_FINAL
s32 var800800f0jf = 0;
s32 g_ScaleX = 1;
u32 var80080104jf = 0;
s32 var8007fac4 = 0;
bool g_TextRotated90 = false;
s32 g_WrapIndentCount = 0;
s32 var8007fad0 = 1;
s32 var80080108jf = 1;
#else
s32 g_ScaleX = 1;
s32 var8007fac4 = 0;
bool g_TextRotated90 = false;
s32 g_WrapIndentCount = 0;
s32 var8007fad0 = 1;
#endif

s32 var8007fad4 = -1;
u32 var8007fad8 = 0x00000000;
s32 var8007fadc = 0;
s32 var8007fae0 = 0;
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
u32 ope = 0;
u32 var8007fbd8 = 0x00000000;
#elif VERSION >= VERSION_PAL_BETA
u32 var8007fbd8 = 0x00000000;
#else
u32 var8007fbcc = 0x00000c0b;
u32 var8007fbd0 = 0x00000000;
u32 var8007fbd4 = 0x00000000;
u32 var8007fbd8 = 0x00000000;
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

void textSetWrapIndent(s32 count)
{
	g_WrapIndentCount = count;
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
	g_WrapIndentCount = 0;
	var8007fad4 = -1;
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

u32 func0f153e94(s32 x, s32 y, u32 colour)
{
	u32 stack[2];
	f32 zero = 0.0f;
	u32 result = colour;

	if (var800a45d0.unk00 & 1) {
		f32 weightf;
		f32 f12;
		f32 f14;
		f32 f16;
		f32 f18;

		if (x - var800a45d0.unk0c > -3000 && x - var800a45d0.unk0c < 3000
				&& y - var800a45d0.unk10 > -3000 && y - var800a45d0.unk10 < 3000) {
			f12 = sqrtf((x - var800a45d0.unk0c) * (x - var800a45d0.unk0c) + (y - var800a45d0.unk10) * (y - var800a45d0.unk10));
		} else {
			f12 = 3000.0f;
		}

		f14 = var8007fbac;
		f18 = var8007fbb0;
		f16 = var8007fbb4;

		if (var800a45d0.unk18 == 0) {
			if (var800a45d0.unk14 < f12) {
				result = 0;
			} else if (var800a45d0.unk14 - f14 < f12) {
				u32 intensity;
				weightf = (f12 - (var800a45d0.unk14 - f14)) / f14 * 255.0f;
				intensity = 255 - (u32) weightf;
				result = intensity << 8 | intensity | intensity << 16 | intensity << 24;
			} else if (var800a45d0.unk14 - (f14 + f16) < f12) {
				result = ((colour & 0xff) + 0xff) >> 1 | colour & 0xffffff00;
			} else if ((var800a45d0.unk14 - (f14 + f18 + f16)) < f12) {
				u32 colour2 = (((colour & 0xff) + 0xff) / 2) | (colour & 0xffffff00);
				weightf = (f12 - (var800a45d0.unk14 - (f14 + f18 + f16))) / f18 * 255.0f;
				result = colourBlend(colour, colour2, 0xff - (u32) weightf);
			}
		} else if (var800a45d0.unk18 == 2) {
			if (var800a45d0.unk14 < f12) {
				result = 0x00000000;
			} else if (var800a45d0.unk14 - f14 < f12) {
				weightf = (f12 - (var800a45d0.unk14 - f14)) / f14 * 255.0f;
				result = colourBlend(0x00000000, colour & 0xff, weightf);
			} else if (var800a45d0.unk14 - (f14 + zero) < f12) {
				result = colour & 0xff;
			} else if ((var800a45d0.unk14 - (f14 + f18 + zero)) < f12) {
				weightf = (f12 - (var800a45d0.unk14 - (f14 + f18 + zero))) / f18 * 255.0f;
				result = colourBlend(colour & 0xff, colour, weightf);
			}
		}
	}

	return result;
}

GLOBAL_ASM(
glabel func0f1543ac
.late_rodata
glabel var7f1b7404
.word 0x453b8000
.text
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

void textMapCodeUnitToChar2(u8 *c);

#if VERSION >= VERSION_PAL_BETA
void textMapCodeUnitToChar2(u8 *c)
{
	switch (*c) {
	case 0xc0:
	case 0xc1:
	case 0xc4:
		*c = 0x41;
		break;
	case 0xc8:
	case 0xc9:
		*c = 0x45;
		break;
	case 0xcc:
	case 0xcd:
		*c = 0x49;
		break;
	case 0xd2:
	case 0xd3:
	case 0xd6:
		*c = 0x4f;
		break;
	case 0xd9:
	case 0xda:
	case 0xdc:
		*c = 0x55;
		break;
	case 0xe0:
	case 0xe1:
	case 0xe2:
	case 0xe4:
		*c = 0x61;
		break;
	case 0xe8:
	case 0xe9:
	case 0xea:
	case 0xeb:
		*c = 0x65;
		break;
	case 0xec:
	case 0xed:
	case 0xee:
	case 0xef:
		*c = 0x69;
		break;
	case 0xf2:
	case 0xf3:
	case 0xf4:
	case 0xf6:
		*c = 0x6f;
		break;
	case 0xf9:
	case 0xfa:
	case 0xfb:
	case 0xfc:
		*c = 0x75;
		break;
	case 0xd1:
		*c = 0x4e;
		break;
	case 0xf1:
		*c = 0x6e;
		break;
	case 0xe7:
		*c = 0x63;
		break;
	case 0xdf:
		*c = 0x42;
		break;
	case 0xa1:
	case 0xaa:
	case 0xb0:
	case 0xbf:
		*c = 0x20;
		break;
	}
}
#endif

#if VERSION >= VERSION_JPN_FINAL
s32 func0f154784jf(u16 arg0)
{
	u8 result = 0;
	u16 u16val = arg0;
	u8 u8val = arg0;

	if (arg0 >= 0x10 && arg0 < 0x1a) {
		result = u16val;
		result += 0x20;
	}

	if (arg0 >= 0x1a && arg0 < 0x34) {
		result = u16val;
		result += 0x27;
	}

	if (arg0 >= 0x95 && arg0 < 0xaf) {
		result = u16val;
		result -= 0x34;
	}

	if (arg0 == 0x3fe || arg0 == 0x3ff) {
		result = 0x2d;
	}

	if (arg0 < 0xff) {
		switch (u8val) {
		case 0x00: result = 0x20; break;
		case 0x01: result = 0x2c; break;
		case 0x02: result = 0x24; break;
		case 0x03: result = 0x28; break;
		case 0x04: result = 0x29; break;
		case 0x05: result = 0x2e; break;
		case 0x06: result = 0x25; break;
		case 0x07: result = 0x5b; break;
		case 0x08: result = 0x5d; break;
		case 0x09: result = 0x22; break;
		case 0x0a: result = 0x3c; break;
		case 0x0b: result = 0x3e; break;
		case 0x0c: result = 0x26; break;
		case 0x0d: result = 0x7e; break;
		case 0x0e: result = 0x2e; break;
		case 0x0f: result = 0x20; break;
		case 0x34: result = 0x21; break;
		case 0x35: result = 0x22; break;
		case 0x36: result = 0x23; break;
		case 0x37: result = 0x22; break;
		case 0x38: result = 0x2a; break;
		case 0x39: result = 0x2b; break;
		case 0x3a: result = 0x2c; break;
		case 0x3b: result = 0x2d; break;
		case 0x3c: result = 0x2e; break;
		case 0x3d: result = 0x2f; break;
		case 0x3e: result = 0x3a; break;
		case 0x3f: result = 0x3d; break;
		case 0x40: result = 0x3f; break;
		case 0x41: result = 0x40; break;
		}
	}

	return result;
}
#endif

#if VERSION >= VERSION_JPN_FINAL
u16 func0f154968jf(u8 value)
{
	u16 result = 0;

	if (value >= 0x30 && value < 0x3a) {
		result = value - 0x20;
	}

	if (value >= 0x41 && value < 0x5b) {
		result = value - 0x27;
	}

	if (value >= 0x61 && value < 0x7b) {
		result = value + 0x34;
	}

	switch (value) {
	case 0x20: result = 0x00; break;
	case 0x2c: result = 0x01; break;
	case 0x24: result = 0x02; break;
	case 0x28: result = 0x03; break;
	case 0x29: result = 0x04; break;
	case 0x2e: result = 0x05; break;
	case 0x25: result = 0x06; break;
	case 0x5b: result = 0x07; break;
	case 0x5d: result = 0x08; break;
	case 0x22: result = 0x09; break;
	case 0x3c: result = 0x0a; break;
	case 0x3e: result = 0x0b; break;
	case 0x26: result = 0x0c; break;
	case 0x7e: result = 0x0d; break;
	case 0x21: result = 0x34; break;
	case 0x23: result = 0x36; break;
	case 0x2a: result = 0x38; break;
	case 0x2b: result = 0x39; break;
	case 0x2d: result = 0x3b; break;
	case 0x2f: result = 0x3d; break;
	case 0x3a: result = 0x3e; break;
	case 0x3d: result = 0x3f; break;
	case 0x3f: result = 0x40; break;
	case 0x40: result = 0x41; break;
	}

	return result;
}
#endif

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
/*  f154b74:	0fc5525a */ 	jal	func0f154968jf
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

const char var7f1b8068jf[] = "ope";

//void textMapCodeUnitToChar(char **text, struct fontchar **arg1, struct fontchar **arg2, struct fontchar *chars, u8 *prevchar)
//{
//	u16 c;
//	u8 c1;
//	u8 c2;
//	u16 sp2a;
//	u8 sp29;
//
//	c = **text;
//
//	if (c < 0x80) {
//		if (chars == NULL || var800800f0jf) {
//			g_TmpJpnChar.index = 0;
//			g_TmpJpnChar.baseline = 0;
//			g_TmpJpnChar.height = 12;
//			g_TmpJpnChar.width = 12;
//			g_TmpJpnChar.unk06 = 0;
//			g_TmpJpnChar.pixeldata = NULL;
//
//			g_TmpJpnChar.index = 0x80 + func0f154968jf(c);
//
//			*arg1 = &g_TmpJpnChar;
//			*arg2 = &g_TmpJpnChar;
//		} else {
//			*arg1 = &chars[c - 0x21];
//			*arg2 = &chars[*prevchar - 0x21];
//		}
//
//		*prevchar = **text;
//		*text += 1;
//		return;
//	}
//
//	g_TmpJpnChar.index = 0;
//	g_TmpJpnChar.baseline = 0;
//	g_TmpJpnChar.height = 11;
//	g_TmpJpnChar.width = 11;
//	g_TmpJpnChar.unk06 = 0;
//	g_TmpJpnChar.pixeldata = NULL;
//
//	c1 = **text;
//	*text = *text + 1;
//	c2 = **text;
//	*text = *text + 1;
//
//	sp2a = ((c1 & 0x7f) << 7) | (c2 & 0x7f);
//	sp29 = 0;
//
//	mainOverrideVariable("ope", &ope);
//
//	if (ope) {
//		sp29 = func0f154784jf(sp2a);
//	}
//
//	if (sp29 == 0 || chars == NULL) {
//		if ((sp2a & 0x1fff) >= 0x400) {
//			sp2a = 2;
//		}
//
//		g_TmpJpnChar.index = sp2a + 0x80;
//
//		*arg1 = &g_TmpJpnChar;
//		*arg2 = &g_TmpJpnChar;
//	} else {
//		*arg1 = &chars[sp29 - 0x21];
//		*arg2 = &g_TmpJpnChar;
//	}
//}
#elif VERSION >= VERSION_PAL_BETA
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
		textMapCodeUnitToChar2(&c);
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
		textMapCodeUnitToChar2(&c);
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

// Mismatch: Regalloc, an extra move instruction and some minor reordering.
// Related to type casting.
//Gfx *func0f154f38(Gfx *gdl, s32 *arg1, struct fontchar *curchar, struct fontchar *prevchar,
//		struct font *font, f32 widthscale, f32 heightscale, f32 x, f32 y)
//{
//	s32 tmp;
//	u32 stack;
//	s16 sp3e;
//	s16 sp3c;
//	s16 sp3a;
//	s16 sp38;
//	s16 sp36;
//	s16 sp34;
//	s16 sp32;
//	s16 sp30;
//	struct gfxvtx *vertices; // 2c
//	u32 *colours;
//#if VERSION < VERSION_JPN_FINAL
//	s32 stack2;
//#endif
//
//	tmp = font->unk000[prevchar->unk04 * 13 + curchar->unk04] + var8007fac4;
//	*arg1 = *arg1 - tmp + 1;
//
//#if VERSION >= VERSION_JPN_FINAL
//	if (curchar->pixeldata == 0) {
//		curchar->pixeldata = (void *)lang0f16e3fc(curchar->index - 0x80);
//	}
//
//	if (curchar->index >= 0x80) {
//		if (!var80080104jf) {
//			gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(&var800801d8jf));
//			var80080104jf = 1;
//			gDPLoadSync(gdl++);
//			gDPLoadTLUTCmd(gdl++, 6, 15);
//		}
//	} else {
//		if (var80080104jf) {
//			gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(&var8007fb3c));
//			var80080104jf = 0;
//			gDPLoadSync(gdl++);
//			gDPLoadTLUTCmd(gdl++, 6, 15);
//		}
//	}
//#endif
//
//	gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, curchar->pixeldata);
//	gDPLoadSync(gdl++);
//	gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, (((s32)((u32)curchar->height * 8) + 17) >> 1) - 1, 2048);
//	gDPPipeSync(gdl++);
//
//	sp3e = ((s32)var8007fadc + (*arg1 * 4)) * widthscale * 10.0f + 40.0f * x;
//	sp3c = ((s32)var8007fae0 + (curchar->baseline * 4)) * heightscale * 10.0f + 40.0f * y;
//	sp3a = ((s32)var8007fadc + ((*arg1 + (curchar->width + 1)) * 4)) * widthscale * 10.0f + 40.0f * x;
//	sp38 = ((s32)var8007fae0 + ((curchar->baseline + (curchar->height + 1)) * 4)) * heightscale * 10.0f + 40.0f * y;
//
//	sp36 = 1;
//	sp34 = sp36 + ((curchar->width + 1) << 6);
//	sp32 = 1;
//	sp30 = sp32 + ((curchar->height + 1) << 6);
//
//	if (1);
//
//	vertices = gfxAllocateVertices(4);
//
//	colours = gfxAllocateColours(1);
//	colours[0] = 0xff0000ff;
//
//	vertices[0].z = -10;
//	vertices[1].z = -10;
//	vertices[2].z = -10;
//	vertices[3].z = -10;
//
//	vertices[0].colour = 0;
//	vertices[1].colour = 0;
//	vertices[2].colour = 0;
//	vertices[3].colour = 0;
//
//	vertices[0].x = sp3e / 4;
//	vertices[0].y = sp3c / 4;
//	vertices[0].s = sp36;
//	vertices[0].t = sp32;
//	vertices[1].x = sp3a / 4;
//	vertices[1].y = sp3c / 4;
//	vertices[1].s = sp34;
//	vertices[1].t = sp32;
//	vertices[2].x = sp3a / 4;
//	vertices[2].y = sp38 / 4;
//	vertices[2].s = sp34;
//	vertices[2].t = sp30;
//	vertices[3].x = sp3e / 4;
//	vertices[3].y = sp38 / 4;
//	vertices[3].s = sp36;
//	vertices[3].t = sp30;
//
//	gDPSetColorArray(gdl++, colours, 1);
//	gDPSetVerticeArray(gdl++, vertices, 4);
//
//	gDPTri2(gdl++, 0, 1, 2, 2, 3, 0);
//
//	*arg1 += curchar->width;
//
//	return gdl;
//}

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

// Mismatch: Can't match the fx and fy calculations
//Gfx *func0f1552d4(Gfx *gdl, f32 x, f32 y, f32 widthscale, f32 heightscale,
//		char *text, struct fontchar *chars, struct font *font, u32 colour, s32 hdir, s32 vdir)
//{
//	s32 s2;
//	u8 prevchar;
//	s32 textwidth; // cc
//	s32 textheight; // c8
//	s32 spc4;
//	s32 spc0;
//	f32 fx;
//	f32 fy;
//
//	s2 = 0;
//	spc0 = 0;
//	prevchar = 'H';
//
//#if VERSION >= VERSION_JPN_FINAL
//	spc4 = 13;
//#else
//	spc4 = chars['['].height + chars['['].baseline;
//
//	if (g_Jpn && spc4 < 14) {
//		spc4 = 14;
//	}
//#endif
//
//	textMeasure(&textheight, &textwidth, text, chars, font, 0);
//
//	fx = x - (widthscale - 1.0f) * textwidth * 0.5f * hdir;
//	fy = y - (heightscale - 1.0f) * spc4 * 0.5f * vdir;
//
//	if (fx);
//	if (fy);
//
//	gDPPipeSync(gdl++);
//	gDPSetTextureLUT(gdl++, G_TT_IA16);
//	gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(&var8007fb3c));
//
//#if VERSION >= VERSION_JPN_FINAL
//	var80080104jf = true;
//#endif
//
//	gDPLoadSync(gdl++);
//	gDPLoadTLUTCmd(gdl++, 6, 15);
//	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
//	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x007c, 0x007c);
//	gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
//	gDPPipeSync(gdl++);
//
//#if VERSION >= VERSION_PAL_BETA
//	if (text != NULL) {
//		while (*text != '\0') {
//			if (*text == ' ') {
//				prevchar = 'H';
//				text += 1;
//				spc0 = spc0 + var8007fad0 * 5;
//			} else if (*text == '\n') {
//				if (var8007fad4 >= 0 && spc0 == 0) {
//					s2 += var8007fad4;
//					spc0 = 0;
//				} else {
//					spc0 = 0;
//#if VERSION >= VERSION_JPN_FINAL
//					s2 = s2 + spc4 * var80080108jf;
//#else
//					s2 += spc4;
//#endif
//				}
//
//				prevchar = 'H';
//				text += 1;
//			} else {
//				struct fontchar *sp84;
//				struct fontchar *sp80;
//
//				textMapCodeUnitToChar(&text, &sp84, &sp80, chars, &prevchar);
//				gdl = func0f154f38(gdl, &spc0, sp84, sp80, font, widthscale, heightscale, fx, fy);
//			}
//		}
//	}
//#else
//	if (text != NULL) {
//		while (*text != '\0') {
//			if (*text == ' ') {
//				prevchar = 'H';
//				text += 1;
//				spc0 = spc0 + var8007fad0 * 5;
//			} else if (*text == '\n') {
//				prevchar = 'H';
//				text += 1;
//
//				if (var8007fad4 >= 0 && spc0 == 0) {
//					s2 += var8007fad4;
//					spc0 = 0;
//				} else {
//					spc0 = 0;
//					s2 += spc4;
//				}
//			} else if (*text < 0x80) {
//				gdl = func0f154f38(gdl, &spc0, &chars[*text - 0x21], &chars[prevchar - 0x21], font,
//						widthscale, heightscale, fx, fy);
//				prevchar = *text;
//				text += 1;
//			} else {
//				u16 codepoint = ((*text & 0x7f) << 7) | (text[1] & 0x7f);
//				struct fontchar tmpchar = {0, 0, 12, 13}; // var8007fbcc
//
//				if (codepoint & 0x2000) {
//					tmpchar.width = 15;
//					tmpchar.height = 16;
//				}
//
//				if ((codepoint & 0x1fff) >= 0x3c8) {
//					codepoint = 2;
//				}
//
//				tmpchar.index = codepoint + 0x80;
//				tmpchar.pixeldata = (void *)lang0f16e3fc(codepoint);
//
//				text += 2;
//			}
//		}
//	}
//#endif
//
//	return gdl;
//}

Gfx *func0f15568c(Gfx *gdl, s32 *x, s32 *y, struct fontchar *curchar, struct fontchar *prevchar,
		struct font *font, s32 savedx, s32 savedy, s32 width, s32 height, s32 arg10)
{
#if VERSION >= VERSION_JPN_FINAL
	s32 tmp;
	s32 sp90;
	s32 xscale = var8007fad0;
	s32 yscale = var80080108jf;

	savedy -= 2;

	if (g_TextRotated90) {
		xscale = 1;
	}

	sp90 = *y + arg10;
	tmp = var8007fac4 + font->unk000[prevchar->unk04 * 13 + curchar->unk04];
	*x -= (tmp - 1) * xscale;
	width *= xscale;
	height *= yscale;

	if (g_TextRotated90 || (*x > 0 && *x <= viGetWidth() && sp90 + curchar->baseline <= viGetHeight())) {
		if (savedx + width >= *x
				&& savedy + height >= curchar->baseline + sp90
				&& *x >= savedx
				&& curchar->baseline + sp90 + curchar->height >= savedy) {
			if (curchar->pixeldata == NULL) {
				curchar->pixeldata = (void *)lang0f16e3fc(curchar->index - 0x80);
			}

			if (curchar->index >= 0x80) {
				if (!var80080104jf) {
					gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(&var800801d8jf));

					var80080104jf = true;

					gDPLoadSync(gdl++);
					gDPLoadTLUTCmd(gdl++, 6, 15);

				}
			} else {
				if (var80080104jf) {
					gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(&var8007fb3c));

					var80080104jf = false;

					gDPLoadSync(gdl++);
					gDPLoadTLUTCmd(gdl++, 6, 15);
				}
			}

			gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, curchar->pixeldata);
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, ((curchar->height * 8 + 17) >> 1) - 1, 2048);
			gDPPipeSync(gdl++);

			if (var800a45d0.unk00) {
				gdl = func0f154ecc(gdl, *x / g_ScaleX, *y + arg10);
			}

			if (1);

			if (*x + xscale * curchar->width <= savedx + width) {
				if (savedy <= curchar->baseline * yscale + sp90) {
					if (curchar->baseline * yscale + sp90 + curchar->height * yscale <= savedy + height) {
						if (g_TextRotated90) {
							gSPTextureRectangleFlip(gdl++,
									(sp90 - curchar->baseline - curchar->height * var8007fad0) * 4 + var8007fae0,
									*x * 4 + var8007fadc,
									(sp90 - curchar->baseline) * 4 + var8007fae0,
									(*x + curchar->width * var80080108jf) * 4 + var8007fadc,
									G_TX_RENDERTILE,
									var8007fae8 + 32,
									((curchar->height - 1) << 5) + var8007fae4 + 32,
									1024 / var80080108jf,
									65536 - 1024 / var8007fad0);
						} else {
							gSPTextureRectangle(gdl++,
									*x * 4 + var8007fadc,
									(sp90 + curchar->baseline * var80080108jf) * 4 + var8007fae0,
									(*x + curchar->width * var8007fad0) * 4 + var8007fadc,
									(sp90 + curchar->baseline * var80080108jf + curchar->height * var80080108jf) * 4 + var8007fae0 - (var80080108jf - 1) * 4,
									G_TX_RENDERTILE,
									var8007fae4 + 32,
									var8007fae8 + 32,
									1024 / var8007fad0,
									1024 / var80080108jf);

							if (var8007fb9c) {
								func0f153b6c(*y + arg10);

								if (var8007fba0 >= *x / g_ScaleX && *x / g_ScaleX + curchar->width * var8007fad0 >= var8007fba0) {
									var800a4634 = func0f0d4d0c(var800a4634,
											var8007fba0,
											curchar->baseline * var80080108jf + sp90,
											var8007fba0,
											curchar->baseline * var80080108jf + sp90 + curchar->height * var80080108jf,
											var800a45d0.colour04,
											var800a45d0.colour04,
											0);
								}

								if (var8007fba0 - 3 >= *x / g_ScaleX && *x / g_ScaleX + curchar->width * var8007fad0 >= var8007fba0 - 3) {
									var800a4634 = func0f0d4d0c(var800a4634,
											var8007fba0,
											curchar->baseline * var80080108jf + sp90,
											var8007fba0,
											curchar->baseline * var80080108jf + sp90 + curchar->height * var80080108jf,
											var800a45d0.colour04,
											var800a45d0.colour04,
											0);
								}
							}
						}
					} else if (savedy + height >= curchar->baseline * var80080108jf + sp90) {
						gSPTextureRectangle(gdl++,
								*x * 4 + var8007fadc,
								(sp90 + curchar->baseline * var80080108jf) * 4 + var8007fae0,
								(*x + curchar->width * var8007fad0) * 4 + var8007fadc,
								(savedy + height) * 4 + var8007fae0,
								G_TX_RENDERTILE,
								var8007fae4 + 32,
								var8007fae8 + 32,
								1024 / var8007fad0,
								1024 / var80080108jf);
					}
				} else {
					if (curchar->baseline * var80080108jf + sp90 + curchar->height * var80080108jf >= savedy) {
						gSPTextureRectangle(gdl++,
								*x * 4 + var8007fadc,
								savedy * 4 + var8007fae0,
								(*x + curchar->width * var8007fad0) * 4 + var8007fadc,
								(curchar->baseline * var80080108jf + sp90 + curchar->height * var80080108jf) * 4 + var8007fae0,
								G_TX_RENDERTILE,
								var8007fae4 + 32,
								((savedy - sp90 - curchar->baseline * var80080108jf) << 5) + var8007fae8 + 32,
								1024 / var8007fad0,
								1024 / var80080108jf);
					}
				}
			}
		}
	}
#else
	s32 tmp;
	s32 sp90;
	s32 xscale = var8007fad0;

#if VERSION >= VERSION_PAL_BETA
	savedy -= 2;
#endif

	if (g_TextRotated90) {
		xscale = 1;
	}

	sp90 = *y + arg10;
	tmp = var8007fac4 + font->unk000[prevchar->unk04 * 13 + curchar->unk04];
	*x -= (tmp - 1) * xscale;
	width *= xscale;

	if (g_TextRotated90 || (*x > 0 && *x <= viGetWidth() && sp90 + curchar->baseline <= viGetHeight())) {
		if (savedx + width >= *x
				&& savedy + height >= curchar->baseline + sp90
				&& *x >= savedx
				&& curchar->baseline + sp90 + curchar->height >= savedy) {
			gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, curchar->pixeldata);
			gDPLoadSync(gdl++);
			gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, ((curchar->height * 8 + 17) >> 1) - 1, 2048);
			gDPPipeSync(gdl++);

			if (var800a45d0.unk00) {
				gdl = func0f154ecc(gdl, *x / g_ScaleX, *y + arg10);
			}

			if (1);

			if (*x + xscale * curchar->width <= savedx + width) {
				if (savedy <= curchar->baseline + sp90) {
					if (curchar->baseline + sp90 + curchar->height <= savedy + height) {
						if (g_TextRotated90) {
							gSPTextureRectangleFlip(gdl++,
									(sp90 - curchar->baseline - curchar->height * var8007fad0) * 4 + var8007fae0,
									*x * 4 + var8007fadc,
									(sp90 - curchar->baseline) * 4 + var8007fae0,
									(*x + curchar->width) * 4 + var8007fadc,
									G_TX_RENDERTILE,
									var8007fae8 + 32,
									((curchar->height - 1) << 5) + var8007fae4 + 32,
									1024,
									65536 - 1024 / var8007fad0);
						} else {
							gSPTextureRectangle(gdl++,
									*x * 4 + var8007fadc,
									(sp90 + curchar->baseline) * 4 + var8007fae0,
									(*x + curchar->width * var8007fad0) * 4 + var8007fadc,
									(sp90 + curchar->baseline + curchar->height) * 4 + var8007fae0,
									G_TX_RENDERTILE,
									var8007fae4 + 32,
									var8007fae8 + 32,
									1024 / var8007fad0,
									1024);

							if (var8007fb9c) {
								func0f153b6c(*y + arg10);

								if (var8007fba0 >= *x / g_ScaleX && *x / g_ScaleX + curchar->width * var8007fad0 >= var8007fba0) {
									var800a4634 = func0f0d4d0c(var800a4634,
											var8007fba0,
											curchar->baseline + sp90,
											var8007fba0,
											curchar->baseline + sp90 + curchar->height,
											var800a45d0.colour04,
											var800a45d0.colour04,
											0);
								}

								if (var8007fba0 - 3 >= *x / g_ScaleX && *x / g_ScaleX + curchar->width * var8007fad0 >= var8007fba0 - 3) {
									var800a4634 = func0f0d4d0c(var800a4634,
											var8007fba0,
											curchar->baseline + sp90,
											var8007fba0,
											curchar->baseline + sp90 + curchar->height,
											var800a45d0.colour04,
											var800a45d0.colour04,
											0);
								}
							}
						}
					} else if (savedy + height >= curchar->baseline + sp90) {
						gSPTextureRectangle(gdl++,
								*x * 4 + var8007fadc,
								(sp90 + curchar->baseline) * 4 + var8007fae0,
								(*x + curchar->width * var8007fad0) * 4 + var8007fadc,
								(savedy + height) * 4 + var8007fae0,
								G_TX_RENDERTILE,
								var8007fae4 + 32,
								var8007fae8 + 32,
								1024 / var8007fad0,
								1024);
					}
				} else {
					if (curchar->baseline + sp90 + curchar->height >= savedy) {
						gSPTextureRectangle(gdl++,
								*x * 4 + var8007fadc,
								savedy * 4 + var8007fae0,
								(*x + curchar->width * var8007fad0) * 4 + var8007fadc,
								(curchar->baseline + sp90 + curchar->height) * 4 + var8007fae0,
								G_TX_RENDERTILE,
								var8007fae4 + 32,
								((savedy - sp90 - curchar->baseline) << 5) + var8007fae8 + 32,
								1024 / var8007fad0,
								1024);
					}
				}
			}
		}
	}
#endif

	*x += curchar->width * xscale;

	return gdl;
}

void func0f156024(s32 arg0)
{
	var8007fbd8 = arg0;
}

void func0f156030(u32 colour)
{
	var800a463c = colour;
}

Gfx *textRenderProjected(Gfx *gdl, s32 *x, s32 *y, char *text, struct fontchar *chars, struct font *font,
		s32 colour, s32 width, s32 height, s32 arg9, s32 lineheight)
{
	s32 savedx;
	s32 savedy;
	u8 prevchar;
	s32 spb0;
	u32 colour2;
	u32 tmpcolour;
	s32 newx;
	s32 newy;
#if VERSION >= VERSION_JPN_FINAL
	s32 saved18;
	s32 saved00;
#endif
	f32 alpha;

	static u32 sbrd = 0x00000000;

	spb0 = var8007fad0;

	if (g_TextRotated90) {
		*y *= g_ScaleX;
		spb0 = 1;
	} else {
		*x *= g_ScaleX;
	}

	if (var8007fbd8) {
#if VERSION >= VERSION_JPN_FINAL
		func0f006b08(40);
		newx = *x / g_ScaleX;
		newy = *y;
		tmpcolour = var800a463c;
		saved18 = var800a45d0.unk18;
		saved00 = var800a45d0.unk00;

		if (!g_TextRotated90) {
			newy--;
		}

		mainOverrideVariable("sbrd", &sbrd);

		if (sbrd != 0) {
			tmpcolour = sbrd;
		}

		var800a45d0.unk00 &= ~4;

		if (var800a45d0.unk18 != 0) {
			var800a45d0.unk00 &= ~1;
		} else {
			var800a45d0.unk18 = 2;
		}

		var8007fbd8 = 0;

		newx = *x / g_ScaleX + 1;
		newy = *y - 1;
		gdl = textRenderProjected(gdl, &newx, &newy, text, chars, font, tmpcolour, width, height, arg9, lineheight);

		newx = *x / g_ScaleX + 1;
		newy = *y + 1;
		gdl = textRenderProjected(gdl, &newx, &newy, text, chars, font, tmpcolour, width, height, arg9, lineheight);

		newx = *x / g_ScaleX - 1;
		newy = *y - 1;
		gdl = textRenderProjected(gdl, &newx, &newy, text, chars, font, tmpcolour, width, height, arg9, lineheight);

		newx = *x / g_ScaleX - 1;
		newy = *y + 1;
		gdl = textRenderProjected(gdl, &newx, &newy, text, chars, font, tmpcolour, width, height, arg9, lineheight);

		var8007fbd8 = 1;

		var800a45d0.unk00 = saved00;
		var800a45d0.unk18 = saved18;
#else
		alpha = (1.0f - func0f006b08(40.0f)) * 100.0f + 150.0f;
		newx = *x / g_ScaleX;
		newy = *y;
		tmpcolour = var800a463c;
		colour2 = (colour & 0xffffff00) | (u32) alpha;

		mainOverrideVariable("sbrd", &sbrd);

		if (sbrd) {
			tmpcolour = sbrd;
		}

		gdl = textRender(gdl, &newx, &newy, text, chars, font, colour2, tmpcolour, width, height, arg9, lineheight);
#endif
	}

#if VERSION >= VERSION_JPN_FINAL
	if (!g_TextRotated90) {
		*y = *y - 1;
	}
#endif

	mainOverrideVariable("lalpha", &var8007fbac);
	mainOverrideVariable("subtlety", &var8007fbb8);
	mainOverrideVariable("subtletx", &var8007fbbc);
	mainOverrideVariable("coly", &var8007fbc4);
	mainOverrideVariable("colx", &var8007fbc0);
	mainOverrideVariable("lfade", &var8007fbb0);
	mainOverrideVariable("llimbo", &var8007fbb4);

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

#if VERSION >= VERSION_JPN_FINAL
	gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(&var800801d8jf));
	var80080104jf = 1;
#else
	gDPSetTextureImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, osVirtualToPhysical(&var8007fb3c));
#endif

	gDPLoadSync(gdl++);
	gDPLoadTLUTCmd(gdl++, 6, 15);
	gDPSetTile(gdl++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
	gDPSetTileSize(gdl++, G_TX_RENDERTILE, 0, 0, 0x007c, 0x007c);
	gDPSetPrimColorViaWord(gdl++, 0, 0, colour);
	gDPPipeSync(gdl++);

	var800a45d0.colour04 = colour;
	var800a45d0.colour44 = colour;

#if VERSION >= VERSION_PAL_BETA
	if (text != NULL) {
		while (*text != '\0') {
			if (*text == ' ') {
				*x += spb0 * 5;
				prevchar = 'H';
				text++;
			} else if (*text == '\n') {
				if (var8007fad4 >= 0 && savedx == *x) {
					*y += var8007fad4;
				} else {
					*y += lineheight;
				}

				*x = savedx;
				prevchar = 'H';
				text++;
			} else {
				struct fontchar *sp78;
				struct fontchar *sp74;

				textMapCodeUnitToChar(&text, &sp78, &sp74, chars, &prevchar);

				gdl = func0f15568c(gdl, x, y, sp78, sp74, font, savedx, savedy, width, height, arg9);
			}
		}
	}
#else
	if (text != NULL) {
		while (*text != '\0') {
			if (*text == ' ') {
				prevchar = 'H';
				*x += spb0 * 5;
				text++;
			} else if (*text == '\n') {
				prevchar = 'H';
				text++;

				if (var8007fad4 >= 0 && savedx == *x) {
					*y += var8007fad4;
				} else {
					*y += lineheight;
				}

				*x = savedx;
			} else if (*text < 0x80) {
				gdl = func0f15568c(gdl, x, y, &chars[*text - 0x21], &chars[prevchar - 0x21], font, savedx, savedy, width, height, arg9);
				prevchar = *text;
				text++;
			} else {
				u16 codepoint = ((*text & 0x7f) << 7) | (text[1] & 0x7f);
				struct fontchar tmpchar = {0, 0, 12, 11};

				if (codepoint & 0x2000) {
					tmpchar.width = 15;
					tmpchar.height = 16;
				}

				if ((codepoint & 0x1fff) >= 0x3c8) {
					codepoint = 2;
				}

				tmpchar.index = codepoint + 0x80;
				tmpchar.pixeldata = (void *)lang0f16e3fc(codepoint);

				gdl = func0f15568c(gdl, x, y, &tmpchar, &tmpchar, font, savedx, savedy, width, height, arg9);

				text += 2;
			}
		}
	}
#endif

	if (g_TextRotated90) {
		*y = *y / g_ScaleX;
	} else {
		*x = *x / g_ScaleX;
	}

	return gdl;
}

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

Gfx *textRenderChar(Gfx *gdl, s32 *x, s32 *y, struct fontchar *char1, struct fontchar *char2,
		struct font *font, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10)
{
	s32 tmp;
	s32 sp38;

	sp38 = *y + arg10;

	tmp = font->unk000[char2->unk04 * 13 + char1->unk04] + var8007fac4;
	*x -= (tmp - 1) * var8007fad0;

	if (*x > 0
			&& *x <= viGetWidth()
			&& sp38 + char1->baseline <= viGetHeight()
			&& *x <= arg6 + arg8
			&& char1->baseline + sp38 <= arg7 + arg9
			&& *x >= arg6
			&& sp38 + char1->baseline + char1->height >= arg7) {
#if VERSION >= VERSION_JPN_FINAL
		if (char1->pixeldata == NULL) {
			char1->pixeldata = (void *)lang0f16e3fc(char1->index - 0x80);
		}
#else
		if (var800a45d0.unk00 != 0) {
			gdl = func0f1566cc(gdl, *x / g_ScaleX, *y + arg10);
		}
#endif

		gDPSetTextureImage(gdl++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, char1->pixeldata);
		gDPLoadSync(gdl++);
		gDPLoadBlock(gdl++, G_TX_LOADTILE, 0, 0, ((char1->height * 8 + 17) >> 1) - 1, 2048);
		gDPPipeSync(gdl++);

		gdl = func0f156a24(gdl, *x - var8007fad0, sp38 - 1, char1, arg6, arg7 - 1, arg8, arg9);
	}

	*x += char1->width * var8007fad0;

	return gdl;
}

Gfx *func0f156a24(Gfx *gdl, s32 x, s32 y, struct fontchar *char1, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
	if (arg4 + arg6 >= char1->width + x + 2) {
		if (y + char1->baseline >= arg5) {
			if (arg5 + arg7 >= y + char1->baseline + char1->height + 2) {
				if (g_TextRotated90) {
					gSPTextureRectangleFlip(gdl++,
							((y - char1->baseline) - ((char1->height + 2) * var8007fad0)) * 4,
							x * 4,
							(y - char1->baseline) * 4,
							(x + char1->width + 2) * 4,
							G_TX_RENDERTILE,
							0,
							(char1->height + 1) << 5,
							1024 / var8007fad0,
							-1024);
				} else {
					gSPTextureRectangle(gdl++,
							x * 4,
							(y + char1->baseline) * 4,
							(x + char1->width * var8007fad0 + 2) * 4,
							(y + char1->baseline + char1->height + 2) * 4,
							G_TX_RENDERTILE,
							0,
							0,
							1024 / var8007fad0,
							1024);
				}
			} else {
				if (arg5 + arg7 >= y + char1->baseline) {
					gSPTextureRectangle(gdl++,
							x * 4,
							(y + char1->baseline) * 4,
							(x + char1->width * var8007fad0 + 2) * 4,
							(arg5 + arg7) * 4,
							G_TX_RENDERTILE,
							0,
							0,
							1024 / var8007fad0,
							1024);
				}
			}
		} else {
			if (y + char1->baseline + char1->height + 2 >= arg5) {
				gSPTextureRectangle(gdl++,
						x * 4,
						arg5 * 4,
						(x + char1->width * var8007fad0 + 2) * 4,
						(y + char1->baseline + char1->height + 2) * 4,
						G_TX_RENDERTILE,
						0,
						(arg5 - char1->baseline - y) << 5,
						1024 / var8007fad0,
						1024);
			}
		}
	}

	return gdl;
}

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

			gdl = textRenderChar(gdl, x, y, sp78, sp74,
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
			gdl = textRenderChar(gdl, x, y, &chars[*text - 0x21], &chars[prevchar - 0x21],
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

			gdl = textRenderChar(gdl, x, y, &sp74, &sp74, font, savedx, savedy, width * var8007fad0, height, arg10);

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
#else
void textWrap(s32 wrapwidth, char *src, char *dst, struct fontchar *chars, struct font *font)
{
#if VERSION >= VERSION_JPN_FINAL
	// JPN mismatch: Regalloc for sp94
	s32 curlinewidth = 0; // b4
	bool itfits;
	s32 i = 0;
	s32 wordwidth; // a8
	s32 wordheight = 0; // a4
	bool more = true; // a0
	bool isvalidchar;
	s32 wordlen;
	s32 sp94 = 0;
	char curword[32]; // 74
	s32 isspace; // 70
	u32 stack;

	while (more == true) {
		wordlen = 0;
		wordwidth = 0;
		sp94 = 0;
		isspace = false;
		isvalidchar = true;

		while (isvalidchar) {
			u16 codepoint = 0;
			bool multibyte = false;
			s32 charwidth = 0;
			s32 c1 = src[0];
			s32 c2;
			u8 c;

			if (c1 < 0x80) {
				c = c1;
			} else {
				c2 = src[1];
				multibyte = true;
				codepoint = ((c1 & 0x7f) << 7) | (c2 & 0x7f);
				c = func0f154784jf(codepoint);

				if (c2 == '\0') {
					multibyte = false;
				}
			}

			if (c == '\0') {
				isvalidchar = false;

				if (multibyte) {
					if (codepoint >= 0x34 && codepoint < 0x4e) {
						isvalidchar = true;
					}

					if (codepoint >= 0xaf && codepoint < 0xb8) {
						isvalidchar = true;
					}

					if (codepoint == 0x104) {
						isvalidchar = true;
					}

					if (codepoint == 0x105) {
						isvalidchar = true;
					}

					if (wordlen == 0) {
						isvalidchar = true;
					}

					charwidth = 11;
				}
			} else {
				if (c > ' ') {
					isvalidchar = true;
				} else {
					isvalidchar = false;
				}

				charwidth = chars[c - 0x21].width;

				if (!isvalidchar && wordlen == 0) {
					if (c != '\0' && c != ' ') {
						isvalidchar = true;
					}

					if (c == ' ') {
						isspace = true;
					}
				}

				if (wordlen != 0
						&& ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
						&& curword[wordlen - 1] >= 0x80) {
					u8 c1 = curword[wordlen - 2];
					u8 c2 = curword[wordlen - 1];
					u16 codepoint = ((c1 & 0x7f) << 7) | (c2 & 0x7f);

					if (func0f154784jf(codepoint) == '\0') {
						isvalidchar = false;
					}
				}
			}

			if (isvalidchar) {
				curword[wordlen] = *src;
				src++;
				wordlen++;

				if (multibyte) {
					curword[wordlen] = *src;
					src++;
					wordlen++;
				}

				sp94 += charwidth;
			}
		}

		curword[wordlen] = '\0';

		textMeasure(&wordheight, &wordwidth, curword, chars, font, 0);

		curlinewidth += wordwidth;

		if (curlinewidth <= wrapwidth) {
			itfits = true;
		} else {
			itfits = false;
		}

		if (*src == '\n') {
			src++;

			if (!itfits) {
				*dst = '\n';
				dst++;

				for (i = 0; i < g_WrapIndentCount; i++) {
					*dst = ' ';
					dst++;
				}
			}

			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			curlinewidth = 0;

			*dst = '\n';
			dst++;
		} else if (*src == '\0') {
			more = false;

			if (!itfits) {
				*dst = '\n';
				dst++;

				for (i = 0; i < g_WrapIndentCount; i++) {
					*dst = ' ';
					dst++;
				}
			}

			src++;

			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			*dst = '\0';
		} else {
			if (!itfits) {
				*dst = '\n';
				dst++;

				for (i = 0; i < g_WrapIndentCount; i++) {
					*dst = ' ';
					dst++;
				}

				curlinewidth = wordwidth + g_WrapIndentCount * SPACE_WIDTH;
			}

			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			if (*src == ' ' || isspace) {
				if (*src >= 0x80) {
					src++;
				}

				src++;

				curlinewidth += SPACE_WIDTH;

				*dst = ' ';
				dst++;
			}
		}
	}
#else
	s32 curlinewidth = 0;
	bool itfits;
	s32 wordlen;
	s32 wordwidth;
	s32 wordheight = 0;
	bool more = true;
	s32 v1;
	s32 i;
	u32 stack;
	char curword[32];

	while (more == true) {
		// Load the next word
		wordwidth = 0;
		wordlen = 0;
		v1 = 0;

		while (*src > ' ') {
			curword[wordlen] = *src;
			v1 += chars[*src - 0x21].width;
			src++;
			wordlen++;

#if VERSION >= VERSION_PAL_FINAL
			if (g_Jpn)
#endif
			{
				if (curword[wordlen - 1] >= 0x80) {
					curword[wordlen] = *src;
					v1 += chars[*src - 0x21].width;
					src++;
					wordlen++;
				}
			}
		}

		curword[wordlen] = '\0';

		textMeasure(&wordheight, &wordwidth, curword, chars, font, 0);

		curlinewidth += wordwidth;

		if (curlinewidth <= wrapwidth) {
			itfits = true;
		} else {
			itfits = false;
		}

		if (*src == '\n') {
			// Write a new line and indent
			if (!itfits) {
				*dst = '\n';
				dst++;

				for (i = 0; i < g_WrapIndentCount; i++) {
					*dst = ' ';
					dst++;
				}
			}

			curlinewidth = 0;

			// Write the current word
			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			// Write the original new line that was in src
			*dst = '\n';
			dst++;
		} else if (*src == ' ') {
			if (!itfits) {
				// Write a new line and indent
				*dst = '\n';
				dst++;

				for (i = 0; i < g_WrapIndentCount; i++) {
					*dst = ' ';
					dst++;
				}

				curlinewidth = g_WrapIndentCount * SPACE_WIDTH + wordwidth;
			}

			curlinewidth += SPACE_WIDTH;

			// Write the current word
			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			// Write the trailing space
			*dst = ' ';
			dst++;
		} else if (*src == '\0') {
			more = false;

			if (!itfits) {
				// Write a new line and indent
				*dst = '\n';
				dst++;

				for (i = 0; i < g_WrapIndentCount; i++) {
					*dst = ' ';
					dst++;
				}
			}

			// Write the current word
			for (i = 0; i < wordlen; i++) {
				*dst = curword[i];
				dst++;
			}

			// Write the null terminator
			*dst = '\0';
		}

		src++;
	}
#endif
}
#endif
