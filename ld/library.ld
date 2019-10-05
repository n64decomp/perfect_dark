/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
	.library 0x00003050 : AT(0) {
		build/ntsc-final/library.o (.text);
		build/ntsc-final/library.o (.data);
	}

	.setup 0x80059fe0 : AT(SIZEOF(.library)) {
		build/ntsc-final/setup.o (.data);
	}

	.game 0x7f000000 : AT(SIZEOF(.library) + SIZEOF(.setup)) {
		build/ntsc-final/game.o (.text);
		build/ntsc-final/game.o (.data);
	}

	.gvars 0x7f000000 : AT(SIZEOF(.library) + SIZEOF(.setup) + SIZEOF(.game)) {
		build/ntsc-final/gvars.o (.text);
		build/ntsc-final/gvars.o (.data);
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
