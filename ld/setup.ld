/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
	.setup 0x80059fe0 : AT(0x0000) {
		build/ntsc-final/setup.o (.data);
	}

	.game 0x7f000000 : AT(SIZEOF(.setup)) {
		build/ntsc-final/game.o (.text);
		build/ntsc-final/game.o (.data);
	}

	.gvars 0x80099fc0 : AT(SIZEOF(.setup) + SIZEOF(.game)) {
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
	}
}
