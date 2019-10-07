/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
	.setup 0x80059fe0 : AT(0x0000) {
		src/setup/setup.o (.data);
	}

	.game 0x7f000000 : AT(SIZEOF(.setup)) {
		src/game/game_000000.o (.text);
		src/game/chr/chraicommands.o (.text);
		src/game/game_0601b0.o (.text);

		src/game/game_000000.o (.data);
		src/game/chr/chraicommands.o (.data);
		src/game/game_0601b0.o (.data);
	}

	.gvars 0x80099fc0 : AT(SIZEOF(.setup) + SIZEOF(.game)) {
		src/gvars/gvars.o (.text);
		src/gvars/gvars.o (.data);
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
