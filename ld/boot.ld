/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
	setupSegmentStart = 0x80059fe0;
	setupSegmentRomStart = 0x39850;
	rarezipSegmentRomStart = 0x4e850;
	ziplistSegmentRomStart = 0x4fc40;

	.boot 0x00001000 : AT(0) {
		build/ntsc-final/boot.o (.text);
		build/ntsc-final/boot.o (.data);
	}

	.library 0x00003050 : AT(SIZEOF(.boot)) {
		build/ntsc-final/library.o (.text);
		build/ntsc-final/library.o (.data);
	}

	.setup 0x80059fe0 : AT(SIZEOF(.boot) + SIZEOF(.library)) {
		build/ntsc-final/setup.o (.text);
		build/ntsc-final/setup.o (.data);
	}

	/DISCARD/ : {
		* (.MIPS.abiflags);
		* (.options);
		* (.gnu.attributes);
		* (.pdr);
		* (.mdebug);
		* (.gptab.bss);
		* (.gptab.data);
		* (.reginfo);
		* (.setup.data);
	}
}
