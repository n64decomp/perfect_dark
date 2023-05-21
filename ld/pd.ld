#define VERSION_NTSC_BETA  0
#define VERSION_NTSC_1_0   1
#define VERSION_NTSC_FINAL 2
#define VERSION_PAL_BETA   3
#define VERSION_PAL_FINAL  4
#define VERSION_JPN_FINAL  5

#if VERSION >= VERSION_JPN_FINAL
#include "gamefiles.jpn-final.inc"
#include "libfiles.jpn-final.inc"
#elif VERSION >= VERSION_PAL_FINAL
#include "gamefiles.pal-final.inc"
#include "libfiles.pal-final.inc"
#elif VERSION >= VERSION_PAL_BETA
#include "gamefiles.pal-beta.inc"
#include "libfiles.pal-beta.inc"
#elif VERSION >= VERSION_NTSC_1_0
#include "gamefiles.ntsc-final.inc"
#include "libfiles.ntsc-final.inc"
#else
#include "gamefiles.ntsc-beta.inc"
#include "libfiles.ntsc-beta.inc"
#endif

#define BEGIN_SEG(name) \
	_##name##SegmentStart = ADDR(.name); \
	_##name##SegmentRomStart = __rompos; \
	.name __rampos : AT(__rompos)

#define END_SEG(name) \
	__rompos += SIZEOF(.name); \
	__rampos = ADDR(.name) + SIZEOF(.name); \
	_##name##SegmentEnd = ADDR(.name) + SIZEOF(.name); \
	_##name##SegmentRomEnd = __rompos; \
	_##name##SegmentLen = _##name##SegmentEnd - _##name##SegmentStart;

#define MPSTRINGS(lang) \
	BEGIN_SEG(mpstrings##lang) \
	{ \
		build/ROMID/assets/mpstrings/mpstrings##lang.o (.data); \
		. = ALIGN(0x10); \
	} \
	END_SEG(mpstrings##lang)

#define FILE(id, filename, varname) \
	varname = __rompos; \
	.file##id : AT(__rompos) { \
		build/ROMID/assets/files/filename.o (.data); \
		. = ALIGN(0x10); \
	} \
	__rompos += SIZEOF(.file##id)

#define FONT(name) \
	BEGIN_SEG(font##name) \
	{ \
		build/ROMID/assets/fonts/name.o (.data); \
		. = ALIGN(0x10); \
	} \
	END_SEG(font##name)

/**
 * Placeholder segments are used to mark the
 * locations where zipped content will go.
 */
#define PLACEHOLDER_SEGMENT(name, len) \
	BEGIN_SEG(name) \
	{ \
		. = . + len; \
	} \
	END_SEG(name)

#define RSP_TEXT_SEGMENT(name) \
		name##TextStart = .; \
		build/ROMID/rsp/name.text.o (.data); \
		name##TextEnd = .;

#define RSP_DATA_SEGMENT(name) \
		name##DataStart = .; \
		build/ROMID/rsp/name.data.o (.data); \
		name##DataEnd = .;

OUTPUT_ARCH (mips)

SECTIONS
{
	osTvType = 0x80000300;
	osRomType = 0x80000304;
	osRomBase = 0x80000308;
	osResetType = 0x8000030c;
	osCicId = 0x80000310;
	osVersion = 0x80000314;
	osMemSize = 0x80000318;
	osAppNMIBuffer = 0x8000031c;

	getitle0f0155f0_hack = getitle0f0155f0;
	nbombCreateStorm_hack = nbombCreateStorm;
	viGetHeight_hack = viGetHeight;

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
		build/ROMID/bootloader.o (.data);
	}
	END_SEG(bootloader)

	/***************************************************************************
	 * preamble
	 * -------------------------------------------------------------------------
	 * ROM range: 0x00001000 - 0x00001050
	 * RAM range: 0x70001000 - 0x70001050
	 * -------------------------------------------------------------------------
	 * This segment contains the entry function.
	 */

	BEGIN_SEG(preamble)
	{
		build/ROMID/preamble/preamble.o (.text);
		. = 0x50;
	}
	END_SEG(preamble)

	/**
	/* vmBoot()'s address is 0x70001050, but preamble calls it by 0x80001050
	 * due to it not being TLB mapped yet. So we set up this variable to allow
	 * this to happen.
	 */
	vmBootFromPreamble = vmBoot + 0x10000000;

	/***************************************************************************
	 * lib
	 * -------------------------------------------------------------------------
	 * ROM range: 0x00001000 - 0x00039850 (compressed from 0x3050 onwards)
	 * RAM range: 0x70001000 - 0x70059fe0
	 * -------------------------------------------------------------------------
	 */

	__rompos = 0x00001050;

	PLACEHOLDER_SEGMENT(libzip, ROMALLOCATION_LIB)

	__rompos = ROM_SIZE * 1024 * 1024;
	__rampos = 0x70001050;

	BEGIN_SEG(lib) SUBALIGN(0x10)
	{
		LIBFILES(.text)
		LIBFILES(.rodata)
		. = ALIGN(0x10);
	}
	END_SEG(lib)

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
	PLACEHOLDER_SEGMENT(datazip, ROMALLOCATION_DATA)

	__rompos = __savedrompos;
	__rampos = 0x80001050 + SIZEOF(.lib);

	BEGIN_SEG(data)
	{
		RSP_TEXT_SEGMENT(rspboot)
		RSP_TEXT_SEGMENT(gsp)
		RSP_TEXT_SEGMENT(asp)

		LIBFILES(.data)
		GAMEFILES(.data)

		. = ALIGN(0x10);

		RSP_DATA_SEGMENT(gsp)
		RSP_DATA_SEGMENT(asp)
	}
	END_SEG(data)

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
		. = ALIGN(0x10);
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
		build/ROMID/inflate/inflate.o (.bss);
		build/ROMID/inflate/inflate.o (.rodata);
		. = ALIGN(0x10);
	}
	END_SEG(inflate)

	/***************************************************************************
	 * game
	 * -------------------------------------------------------------------------
	 * ROM range: 0x0004fc40 - 0x001a15c0 (compressed)
	 * RAM range: 0x7f000000 - 0x7f1b99e0
	 * -------------------------------------------------------------------------
	 */

	PLACEHOLDER_SEGMENT(gamezip, ROMALLOCATION_GAME)

	__rompos = __savedrompos;
	__rampos = 0x7f000000;

	BEGIN_SEG(game)
	{
		GAMEFILES(.text)
		GAMEFILES(.rodata)
		. = ALIGN(0x10);
	}
	END_SEG(game)

	__rompos = _inflateSegmentRomEnd + ROMALLOCATION_GAME;

	/***************************************************************************
	 * jpnfonts
	 * -------------------------------------------------------------------------
	 * ROM range: 0x00178c40 - 0x00190c50 (jpn-final)
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 * On all versions of the game, the start of this segment overlaps with the
	 * end of the gamezips segment, and the start is overwritten with data from
	 * gamezips. This isn't a problem because the early character codes are
	 * non-visual characters and therefore not used. However the SegmentRomStart
	 * linker variable points at the original start. To avoid issues with
	 * overlapping segments, the segment we extracted from the base ROM is just
	 * the non-overlapping part, which means we have to subtract an amount to
	 * get the SegmentRomStart value.
	 *
	 * Note that all versions of the game have this segment. There is basic
	 * support for Japanese characters even in the NTSC beta version.
	 *
	 * In most versions the fonts are split into two font segments: single-byte
	 * and multi-byte. jpn-final combines them into one segment.
	 */

#if VERSION == VERSION_JPN_FINAL
	FONT(jpn)
#else
	FONT(jpnsingle)
	FONT(jpnmulti)
#endif

	/* Subtract based on how much overlap there is */
#if VERSION == VERSION_JPN_FINAL
	_fontjpnSegmentRomStart = _fontjpnSegmentRomStart - 0x6f0;
#elif VERSION >= VERSION_PAL_BETA
	_fontjpnsingleSegmentRomStart = _fontjpnsingleSegmentRomStart - 0x6f0;
#elif VERSION >= VERSION_NTSC_1_0
	_fontjpnsingleSegmentRomStart = _fontjpnsingleSegmentRomStart - 0x6e0;
#endif

	/***************************************************************************
	 * animations
	 * -------------------------------------------------------------------------
	 * ROM range: 0x001a15c0 - 0x007d0a40
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	BEGIN_SEG(animations)
	{
		build/ROMID/assets/animations.o (.data);
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
		build/ROMID/mpconfigs.o (.data);
		. = ALIGN(0x10);
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
		build/ROMID/firingrange.o (.data);
		. = ALIGN(0x10);
	}
	END_SEG(firingrange)

	/***************************************************************************
	 * textureconfig
	 * -------------------------------------------------------------------------
	 * ROM range: 0x007eb270 - 0x007ebdc0
	 * RAM range: N/A
	 * -------------------------------------------------------------------------
	 */

	__rampos = ROM_SIZE * 1024 * 1024;

	BEGIN_SEG(textureconfig)
	{
		build/ROMID/textureconfig.o (.data);
		. = ALIGN(0x10);
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
		build/ROMID/getitle.o (.data);
	}
	END_SEG(getitle)

	_getitleSegmentStart = ROM_SIZE * 1024 * 1024;
	_getitleSegmentEnd = _getitleSegmentStart + 0x65d0;
	var020043f8 = _getitleSegmentStart + 0x43f8;
	var02004468 = _getitleSegmentStart + 0x4468;
	var02004700 = _getitleSegmentStart + 0x4700;
	var02004d28 = _getitleSegmentStart + 0x4d28;
	var02004dc8 = _getitleSegmentStart + 0x4dc8;
	var02005dd0 = _getitleSegmentStart + 0x5dd0;

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
	FONT(ocralg)

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

#if VERSION == VERSION_JPN_FINAL
#include "../src/assets/jpn-final/files/list.ld"
#elif VERSION == VERSION_PAL_FINAL
#include "../src/assets/pal-final/files/list.ld"
#elif VERSION == VERSION_PAL_BETA
#include "../src/assets/pal-beta/files/list.ld"
#elif VERSION == VERSION_NTSC_FINAL
#include "../src/assets/ntsc-final/files/list.ld"
#elif VERSION == VERSION_NTSC_1_0
#include "../src/assets/ntsc-1.0/files/list.ld"
#elif VERSION == VERSION_NTSC_BETA
#include "../src/assets/ntsc-beta/files/list.ld"
#endif

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
		. = ALIGN(0x10);
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

	BEGIN_SEG(fill)
	{
		FILL(0xff);
		. = ROM_SIZE * 1024 * 1024 - __rompos - 1;
		BYTE(0xff);
	}
	END_SEG(fill)

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
