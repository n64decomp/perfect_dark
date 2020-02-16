#include "gamefiles.inc"
#include "libraryfiles.inc"

OUTPUT_ARCH (mips)

SECTIONS
{
	_gamedataSegmentStart = 0x80059fe0;
	_gamedataSegmentRomStart = 0x39850;
	_inflateSegmentRomStart = 0x4e850;
	_ziplistSegmentRomStart = 0x4fc40;

	_antipiracyUncloakWriteAddress = 0x7002a324;

	osCicId = 0x80000310;

	__rompos = 0;
	.boot 0x70001000 : AT(__rompos) {
		src/boot/boot.o (.text);
		src/boot/boot.o (.data);
	}
	__rompos += SIZEOF(.boot);

	.library 0x70003050 : AT(__rompos) {
		LIBRARYFILES(.text)
		LIBRARYFILES(.rodata)
	}
	__rompos += SIZEOF(.library);

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
