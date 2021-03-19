#define VERSION_NTSC_BETA  0
#define VERSION_NTSC_1_0   1
#define VERSION_NTSC_FINAL 2
#define VERSION_PAL_BETA   3
#define VERSION_PAL_FINAL  4
#define VERSION_JPN_FINAL  5

#if VERSION == VERSION_NTSC_BETA
#include "gamefiles.ntsc-beta.inc"
#include "libfiles.ntsc-beta.inc"
#elif VERSION == VERSION_PAL_FINAL
#include "gamefiles.pal-final.inc"
#include "libfiles.pal-final.inc"
#else
#include "gamefiles.ntsc-final.inc"
#include "libfiles.ntsc-final.inc"
#endif

#define BEGIN_SEG(name) \
	_##name##SegmentStart = ADDR(.name); \
	_##name##SegmentRomStart = __rompos; \
	.name __rampos : AT(__rompos)

#define END_SEG(name) \
	__rompos += SIZEOF(.name); \
	__rampos = ADDR(.name) + SIZEOF(.name); \
	_##name##SegmentEnd = ADDR(.name) + SIZEOF(.name); \
	_##name##SegmentRomEnd = __rompos;

#define MPSTRINGS(lang) \
	BEGIN_SEG(mpstrings##lang) \
	{ \
		build/ROMID/assets/mpstrings/ROMID/mpstrings##lang.o (.data); \
	} \
	END_SEG(mpstrings##lang)

#define FILE(id, filename, varname) \
	varname = __rompos; \
	.file##id : AT(__rompos) { \
		build/ROMID/assets/files/filename.o (.data); \
	} \
	__rompos += SIZEOF(.file##id)

#define FONT(name) \
	BEGIN_SEG(font##name) \
	{ \
		build/ROMID/assets/fonts/name.o (.data); \
	} \
	END_SEG(font##name)

/**
 * Placeholder segments are used to mark the locations where zipped content will
 * go. It's really just here so it appears in the linker map which allows
 * packrom to find it. We only care about the start address for this segment,
 * so the romheader object is used as it's nice and short.
 */
#define PLACEHOLDER_SEGMENT(name) \
	BEGIN_SEG(name) \
	{ \
		build/ROMID/romheader.o (.data); \
	} \
	END_SEG(name)

/******************************************************************************
 * ROM Allocations
 * ----------------------------------------------------------------------------
 * The lib, data and game segments are compressed in the final ROM. To do this,
 * we build them uncompressed here but place them past the end of the ROM, then
 * a later script compresses them and writes them into the ROM.
 *
 * These constants are defining how much space is reserved for the compressed
 * segments. If these segments are edited and grow to a point that their
 * compressed size exceeds the allocation then their allocations will need to be
 * increased.
 */

#if VERSION >= VERSION_PAL_FINAL
#define ROMALLOCATION_LIB   0x038850
#define ROMALLOCATION_DATA  0x015000
#define ROMALLOCATION_GAME  0x13d180
#else
#define ROMALLOCATION_LIB   0x038850
#define ROMALLOCATION_DATA  0x015000
#define ROMALLOCATION_GAME  0x151980
#endif

OUTPUT_ARCH (mips)

SECTIONS
{
#if VERSION >= VERSION_PAL_FINAL
	_gamecode = 0x4450;
	_jpndata1 = 0x17fc40;
	_jpndata2 = 0x18b340;
#else
	_gamecode = 0x4445;
	_jpndata1 = 0x194440;
	_jpndata2 = 0x19fb40;
#endif

#if VERSION >= VERSION_PAL_FINAL
	_val7f116f34 = 0x0339;
	_val7f117634 = 0x0422;
	_val7f1183f8 = 0x070a;
	_val7f118a44 = 0x0801;
	_val7f11a650 = 0x0da5;
	_val7f11a6c8 = 0x0dae;
	_val7f11a88c = 0x0e16;
	_val7f11aa14 = 0x0e4d;
	_val7f11aae4 = 0x0e5b;
	_val7f11ad0c = 0x0efc;
	_val7f11ae0c = 0x0f20;
	_val7f11aef4 = 0x0f38;
	_val7f11b124 = 0x0f73;
	_val7f11b6c0 = 0x1033;
	_val7f11bb48 = 0x1131;
	_val7f11c1d0 = 0x128d;
	_val7f11c378 = 0x12c8;
#elif VERSION >= VERSION_NTSC_FINAL
	_val7f116f34 = 0x0339;
	_val7f117634 = 0x0422;
	_val7f1183f8 = 0x070a;
	_val7f118a44 = 0x0801;
	_val7f11a650 = 0x0d9e;
	_val7f11a6c8 = 0x0da7;
	_val7f11a88c = 0x0e0f;
	_val7f11aa14 = 0x0e46;
	_val7f11aae4 = 0x0e54;
	_val7f11ad0c = 0x0ef5;
	_val7f11ae0c = 0x0f19;
	_val7f11aef4 = 0x0f31;
	_val7f11b124 = 0x0f6c;
	_val7f11b6c0 = 0x102c;
	_val7f11bb48 = 0x112a;
	_val7f11c1d0 = 0x1286;
	_val7f11c378 = 0x12c1;
#else
	_val7f116f34 = 0x0336;
	_val7f117634 = 0x041f;
	_val7f1183f8 = 0x06fc;
	_val7f118a44 = 0x07e0;
	_val7f11a650 = 0x0cda;
	_val7f11a6c8 = 0x0ce3;
	_val7f11a88c = 0x0d4b;
	_val7f11aa14 = 0x0d83;
	_val7f11aae4 = 0x0d91;
	_val7f11ad0c = 0x0e32;
	_val7f11ae0c = 0x0e56;
	_val7f11aef4 = 0x0e6e;
	_val7f11b124 = 0x0ea9;
	_val7f11b6c0 = 0x0f69;
	_val7f11bb48 = 0x1067;
	_val7f11c1d0 = 0x11c3;
	_val7f11c378 = 0x11fe;
#endif

#if VERSION >= VERSION_PAL_FINAL
	rspbootTextStart = 0x80059fe0;
	rspbootTextEnd = 0x8005a0b0;
	aspMainTextStart = 0x8005b180;
	aspMainTextEnd = 0x8005c180;
	aspMainDataStart = 0x8008a2d0;
	aspMainDataEnd = 0x8008aad0;
#else
	rspbootTextStart = 0x80059fe0;
	rspbootTextEnd = 0x8005a0b0;
	aspMainTextStart = 0x8005b4d0;
	aspMainTextEnd = 0x8005c4d0;
	aspMainDataStart = 0x8008a2d0;
	aspMainDataEnd = 0x8008aad0;
#endif

	osTvType = 0x80000300;
	osRomType = 0x80000304;
	osRomBase = 0x80000308;
	osResetType = 0x8000030c;
	osCicId = 0x80000310;
	osVersion = 0x80000314;
	osMemSize = 0x80000318;
	osAppNMIBuffer = 0x8000031c;

	var800902e4 = 0x800902e4; /* for ntsc-beta */
	var800902e8 = 0x800902e8; /* for ntsc-beta */

	var803f50b8 = 0x803f50b8;

	vara00002e8 = 0xa00002e8;

	varbc000c02 = 0xbc000c02; /* for ntsc-beta */

	/***************************************************************************
	 * romheader
	 * -------------------------------------------------------------------------
	 * ROM range: 0x00000000 - 0x00000040
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	__rompos = 0;

	BEGIN_SEG(romheader)
	{
		build/ROMID/romheader.o (.data);
	}
	END_SEG(romheader)

	/***************************************************************************
	 * bootloader
	 * -------------------------------------------------------------------------
	 * ROM range: 0x00000040 - 0x00001000
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	__rompos = 0x40;

	BEGIN_SEG(bootloader)
	{
		build/ROMID/assets/bootloader/bootloader.o (.data);
	}
	END_SEG(bootloader)

	/***************************************************************************
	 * lib
	 * -------------------------------------------------------------------------
	 * ROM range: 0x00001000 - 0x00039850 (compressed from 0x3050 onwards)
	 * RAM range: 0x70001000 - 0x70059fe0
	 * -------------------------------------------------------------------------
	 */

	PLACEHOLDER_SEGMENT(libzip)

	__rompos = 0x02000000;
	__rampos = 0x70001000;

	BEGIN_SEG(lib) SUBALIGN(16)
	{
		LIBFILES(.text)
		LIBFILES(.rodata)
	}
	END_SEG(lib)

	_libSegmentStart = 0x70001050;

	/***************************************************************************
	 * data
	 * -------------------------------------------------------------------------
	 * ROM range: 0x00039850 - 0x0004e850 (compressed)
	 * RAM range: 0x80059fe0 - 0x8008ae20
	 * -------------------------------------------------------------------------
	 * For some reason we can't just add 0x10000000 to __rampos, but we can
	 * recalculate it so that's what we do.
	 */

	__savedrompos = __rompos;
	__rompos = _libzipSegmentRomStart + ROMALLOCATION_LIB;
	PLACEHOLDER_SEGMENT(datazip)

	__rompos = __savedrompos;
	__rampos = 0x80001000 + SIZEOF(.lib);

	BEGIN_SEG(data)
	{
		build/ROMID/assets/rsp/rspboot.text.o (.data);
		build/ROMID/assets/rsp/gsp.text.o (.data);
		build/ROMID/assets/rsp/asp.text.o (.data);
		LIBFILES(.data)
		GAMEFILES(.data)
		build/ROMID/assets/rsp/gsp.data.o (.data);
		build/ROMID/assets/rsp/asp.data.o (.data);
	}
	END_SEG(data)

	_datazipSegmentRomEnd = _datazipSegmentRomStart + ROMALLOCATION_DATA;

	rspbootTextStart = _dataSegmentStart;
	rspbootTextEnd = rspbootTextStart + 0xd0;
	gspTextStart = rspbootTextEnd;
	gspTextEnd = gspTextStart + 0x1420;
	aspTextStart = gspTextEnd;
	aspTextEnd = aspTextStart + 0x1930;

	gspDataStart = _dataSegmentEnd - 0x800 - 0xb50;
	gspDataEnd = gspDataStart + 0x800;
	aspMainDataStart = gspDataEnd;
	aspMainDataEnd = aspMainDataStart + 0xb50;

	/***************************************************************************
	 * bss
	 * -------------------------------------------------------------------------
	 * ROM range: N/A
	 * RAM range: 0x8008ae20 - 0x800ad1c0
	 * -------------------------------------------------------------------------
	 */

	BEGIN_SEG(bss)
	{
		LIBFILES(.bss)
		GAMEFILES(.bss)
	}
	END_SEG(bss)

	/***************************************************************************
	 * inflate
	 * -------------------------------------------------------------------------
	 * ROM range: 0x0004e850 - 0x0004fc40
	 * RAM range: 0x70200000 - 0x702013f0
	 * -------------------------------------------------------------------------
	 */

	__savedrompos = __rompos;
	__rampos = 0x70200000;
	__rompos = _datazipSegmentRomEnd;

	BEGIN_SEG(inflate)
	{
		build/ROMID/inflate/inflate.o (.text);
		build/ROMID/inflate/inflate.o (.data);
	}
	END_SEG(inflate)

	/***************************************************************************
	 * game
	 * -------------------------------------------------------------------------
	 * ROM range: 0x0004fc40 - 0x001a15c0 (compressed)
	 * RAM range: 0x7f000000 - 0x7f1b99e0
	 * -------------------------------------------------------------------------
	 */

	PLACEHOLDER_SEGMENT(gamezip)
	__rompos = __savedrompos;
	__rampos = 0x7f000000;

	BEGIN_SEG(game)
	{
		GAMEFILES(.text)
		GAMEFILES(.rodata)
	}
	END_SEG(game)

	/***************************************************************************
	 * animations
	 * -------------------------------------------------------------------------
	 * ROM range: 0x001a15c0 - 0x007d0a40
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	__rompos = _inflateSegmentRomEnd + ROMALLOCATION_GAME;
	__refpos = .;

#define ANIM(id, filename) \
	anim##id = . - __refpos; \
	build/ROMID/assets/animations/filename (.data)

	BEGIN_SEG(animations) SUBALIGN(1)
	{
#include "../src/assets/animations/list.ld"
		. = ALIGN(0x10);
		build/ROMID/assets/animations/list.o (.data);
	}
	END_SEG(animations)

	_animationsTableRomStart = _animationsSegmentRomEnd - 0x38a0;
	_animationsTableRomEnd = _animationsSegmentRomEnd;

	/***************************************************************************
	 * mpconfigs
	 * -------------------------------------------------------------------------
	 * ROM range: 0x007d0a40 - 0x007d1c20
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	BEGIN_SEG(mpconfigs)
	{
		build/ROMID/assets/mpconfigs.o (.data);
	}
	END_SEG(mpconfigs)

	/***************************************************************************
	 * mpstrings
	 * -------------------------------------------------------------------------
	 * ROM range: 0x007d1c20 - 0x007e9d20
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	MPSTRINGS(E)
	MPSTRINGS(J)
	MPSTRINGS(P)
	MPSTRINGS(G)
	MPSTRINGS(F)
	MPSTRINGS(S)
	MPSTRINGS(I)

	/***************************************************************************
	 * firingrange
	 * -------------------------------------------------------------------------
	 * ROM range: 0x007e9d20 - 0x007eb270
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	BEGIN_SEG(firingrange)
	{
		build/ROMID/assets/firingrange.o (.data);
	}
	END_SEG(firingrange)

	/***************************************************************************
	 * textureconfig
	 * -------------------------------------------------------------------------
	 * ROM range: 0x007eb270 - 0x007ebdc0
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	__rampos = 0x02000000;

	BEGIN_SEG(textureconfig)
	{
		build/ROMID/assets/textures/config.o (.data);
	}
	END_SEG(textureconfig)

	/***************************************************************************
	 * getitle
	 * -------------------------------------------------------------------------
	 * ROM range: 0x007ebdc0 - 0x007f2390
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	BEGIN_SEG(getitle)
	{
		build/ROMID/assets/getitle.o (.data);
	}
	END_SEG(getitle)

	_getitleSegmentStart = 0x02000000;
	_getitleSegmentEnd = 0x020065d0;
	var020043f8 = 0x020043f8;
	var02004468 = 0x02004468;
	var02004700 = 0x02004700;
	var02004d28 = 0x02004d28;
	var02004dc8 = 0x02004dc8;
	var02005dd0 = 0x02005dd0;

	/***************************************************************************
	 * fonts
	 * -------------------------------------------------------------------------
	 * ROM range: 0x007f2390 - 0x0080a250
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	FONT(bankgothic)
	FONT(zurich)
	FONT(tahoma)
	FONT(numeric)
	FONT(handelgothicsm)
	FONT(handelgothicxs)
	FONT(handelgothicmd)
	FONT(handelgothiclg)
	FONT(ocramd)

#if VERSION >= VERSION_NTSC_1_0
	FONT(ocralg)
#endif

	/***************************************************************************
	 * sfxctl
	 * -------------------------------------------------------------------------
	 * ROM range: 0x0080a250 - 0x00839dd0
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	BEGIN_SEG(sfxctl)
	{
		build/ROMID/assets/sfx.ctl.o (.data);
	}
	END_SEG(sfxctl)

	/***************************************************************************
	 * sfxtbl
	 * -------------------------------------------------------------------------
	 * ROM range: 0x00839dd0 - 0x00cfbf30
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	BEGIN_SEG(sfxtbl)
	{
		build/ROMID/assets/sfx.tbl.o (.data);
	}
	END_SEG(sfxtbl)

	/***************************************************************************
	 * seqctl
	 * -------------------------------------------------------------------------
	 * ROM range: 0x00cfbf30 - 0x00d05f90
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	BEGIN_SEG(seqctl)
	{
		build/ROMID/assets/seq.ctl.o (.data);
	}
	END_SEG(seqctl)

	/***************************************************************************
	 * seqtbl
	 * -------------------------------------------------------------------------
	 * ROM range: 0x00d05f90 - 0x00e82000
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	BEGIN_SEG(seqtbl)
	{
		build/ROMID/assets/seq.tbl.o (.data);
	}
	END_SEG(seqtbl)

	/***************************************************************************
	 * sequences
	 * -------------------------------------------------------------------------
	 * ROM range: 0x00e82000 - 0x00ed83a0
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	BEGIN_SEG(sequences)
	{
		build/ROMID/assets/sequences.o (.data);
	}
	END_SEG(sequences)

	/***************************************************************************
	 * files
	 * -------------------------------------------------------------------------
	 * ROM range: 0x00ed83a0 - 0x01d5ca00
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	. = 0;
	_filesSegmentRomStart = __rompos;

#include "../src/assets/files/list.ld"

	_filesSegmentRomEnd = __rompos;

	/***************************************************************************
	 * filenames
	 * -------------------------------------------------------------------------
	 * ROM range: 0x01d5ca00 - 0x01d65740
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	__rampos = 0;

	BEGIN_SEG(filenames)
	{
		build/ROMID/assets/files/list.o (.data);
		build/ROMID/assets/files/list.o (.rodata);
	}
	END_SEG(filenames)

	/***************************************************************************
	 * blank
	 * -------------------------------------------------------------------------
	 * ROM range: 0x01d65740 - 0x01d65f40
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 * Yes, this segment is blank and it has to exist. The game loads it.
	 */

	_blankSegmentRomStart = __rompos;
	__rompos += 0x800;
	_blankSegmentRomEnd = __rompos;

	/***************************************************************************
	 * textures
	 * -------------------------------------------------------------------------
	 * ROM range: 0x01d65f40 - 0x01fffe00
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	__rampos = 0;

	BEGIN_SEG(texturesdata)
	{
		build/ROMID/assets/texturesdata.o (.data);
	}
	END_SEG(texturesdata)

	BEGIN_SEG(textureslist)
	{
		build/ROMID/assets/textureslist.o (.data);
	}
	END_SEG(textureslist)

	/***************************************************************************
	 * copyright
	 * -------------------------------------------------------------------------
	 * ROM range: 0x01ffea20 - 0x01fff550
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	__rampos = 0;

	BEGIN_SEG(copyright)
	{
		build/ROMID/assets/copyrightZ.o (.data);
	}
	END_SEG(copyright)

	/***************************************************************************
	 * accessingpak
	 * -------------------------------------------------------------------------
	 * ROM range: 0x01fff550 - 0x01fffe00
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

#if VERSION >= VERSION_NTSC_1_0
	BEGIN_SEG(accessingpak)
	{
		build/ROMID/assets/accessingpakZ.o (.data);
	}
	END_SEG(accessingpak)
#else
	_accessingpakSegmentRomStart = 0;
	_accessingpakSegmentRomEnd = 0;
#endif

	/DISCARD/ : {
		* (.MIPS.abiflags);
		* (.options);
		* (.gnu.attributes);
		* (.pdr);
		* (.mdebug);
		* (.gptab.bss);
		* (.gptab.data);
		* (.reginfo);
	}
}
