#include "gamefiles.inc"
#include "libfiles.inc"

#define VERSION_NTSC_BETA  0
#define VERSION_NTSC_1_0   1
#define VERSION_NTSC_FINAL 2
#define VERSION_PAL_BETA   3
#define VERSION_PAL_FINAL  4
#define VERSION_JAP_FINAL  5

#define MPSTRINGS(lang) \
	.mpstrings##lang : AT(__rompos) { \
		build/ROMID/mpstrings/ROMID/mpstrings##lang.o (.data); \
	} \
	__rompos += SIZEOF(.mpstrings##lang);

OUTPUT_ARCH (mips)

SECTIONS
{
	_gamedataSegmentStart = 0x80059fe0;
	_gamedataSegmentRomStart = 0x39850;
	_inflateSegmentRomStart = 0x4e850;
	_ziplistSegmentRomStart = 0x4fc40;
	_textureSegmentRomStart = 0x01ff7ca0;
	_textureSegmentRomEnd = 0x01ffea20;
	_rspMicrocodeStart = 0x80059fe0;
	_rspMicrocodeStartPlusOne = 0x80059fe1;
	_rspMicrocodeEnd = 0x8005afe0;
	_mpconfigsSegmentRomStart = 0x7d0a40;
	_mpstringsESegmentRomStart = 0x007d1c20; _mpstringsESegmentRomEnd = 0x007d5320;
	_mpstringsJSegmentRomStart = 0x007d5320; _mpstringsJSegmentRomEnd = 0x007d8a20;
	_mpstringsPSegmentRomStart = 0x007d8a20; _mpstringsPSegmentRomEnd = 0x007dc120;
	_mpstringsGSegmentRomStart = 0x007dc120; _mpstringsGSegmentRomEnd = 0x007df820;
	_mpstringsFSegmentRomStart = 0x007df820; _mpstringsFSegmentRomEnd = 0x007e2f20;
	_mpstringsSSegmentRomStart = 0x007e2f20; _mpstringsSSegmentRomEnd = 0x007e6620;
	_mpstringsISegmentRomStart = 0x007e6620; _mpstringsISegmentRomEnd = 0x007e9d20;

#if VERSION >= VERSION_NTSC_FINAL
	_bssSegmentEnd = 0x7f1b99e0;
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
	_checksum7f15c9ac = 0x2c7a82c8;
#else
	_bssSegmentEnd = 0x7f1b9870;
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
	_checksum7f15c9ac = 0x2c7b42f8;
#endif

	_firingrangeSegmentRomStart = 0x007e9d20;
	_firingrangeSegmentRomEnd = 0x007eb270;

	_antipiracyUncloakWriteAddress = 0x7002a324;

	osResetType = 0x8000030c;
	osCicId = 0x80000310;

	__rompos = 0;
	.boot 0x70001000 : AT(__rompos) {
		build/ROMID/boot/boot.o (.text);
		build/ROMID/boot/boot.o (.data);
	}
	__rompos += SIZEOF(.boot);

	.lib 0x70003050 : AT(__rompos) {
		LIBFILES(.text)
		LIBFILES(.rodata)
	}
	__rompos += SIZEOF(.lib);

	.gamedata 0x80059fe0 : AT(__rompos) {
		GAMEFILES(.data)
	}
	__rompos += SIZEOF(.gamedata);

	.gvars 0x8008ae20 : AT(__rompos) {
		build/ROMID/gvars/gvars.o (.data);
	}
	__rompos += SIZEOF(.gvars);

	.game 0x7f000000 : AT(__rompos) {
		GAMEFILES(.text)
		GAMEFILES(.rodata)
	}
	__rompos += SIZEOF(.game);

	.inflate 0x70200000 : AT(__rompos) {
		build/ROMID/inflate/inflate.o (.text);
		build/ROMID/inflate/inflate.o (.data);
	}
	__rompos += SIZEOF(.inflate);

	.mpconfigs : AT(__rompos) {
		build/ROMID/mpconfigs/mpconfigs.o (.data);
	}
	__rompos += SIZEOF(.mpconfigs);

	.firingrange : AT(__rompos) {
		build/ROMID/firingrange/firingrange.o (.data);
	}
	__rompos += SIZEOF(.firingrange);

	MPSTRINGS(E)
	MPSTRINGS(J)
	MPSTRINGS(P)
	MPSTRINGS(G)
	MPSTRINGS(F)
	MPSTRINGS(S)
	MPSTRINGS(I)

	__rompos = 0xed83a0;
	_filesSegmentRomStart = __rompos;
	_filesSegmentRamStart = .;

#include "filesegments.inc"

	_filesSegmentRomEnd = __rompos;

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
