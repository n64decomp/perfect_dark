/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
	.game 0x0f000000 : AT(0) {
		build/ntsc-final/game.o (.text);
		build/ntsc-final/game.o (.data);
	}

	.library 0x00003050 : AT(SIZEOF(.game)) {
		build/ntsc-final/library.o (.text);
		build/ntsc-final/library.o (.data);
	}

	.setup 0x80059fe0 : AT(SIZEOF(.game) + SIZEOF(.library)) {
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
