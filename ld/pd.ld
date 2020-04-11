#include "gamefiles.inc"
#include "libfiles.inc"

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

	_addr007e9d20 = 0x007e9d20;

	_antipiracyUncloakWriteAddress = 0x7002a324;

	osCicId = 0x80000310;

	__rompos = 0;
	.boot 0x70001000 : AT(__rompos) {
		src/boot/boot.o (.text);
		src/boot/boot.o (.data);
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
		src/gvars/gvars.o (.data);
	}
	__rompos += SIZEOF(.gvars);

	.game 0x7f000000 : AT(__rompos) {
		GAMEFILES(.text)
		GAMEFILES(.rodata)
	}
	__rompos += SIZEOF(.game);

	.inflate 0x70200000 : AT(__rompos) {
		src/inflate/inflate.o (.text);
		src/inflate/inflate.o (.data);
	}
	__rompos += SIZEOF(.inflate);

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
