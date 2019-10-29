/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
	.setup 0x80059fe0 : AT(0x0000) {
		src/setup/setup_000000.o (.data);
		src/setup/inventory.o (.data);
		src/setup/setup_0160b0.o (.data);
		src/setup/ailists.o (.data);
		src/setup/setup_020df0.o (.data);
	}

	.library 0x7e000000 : AT(SIZEOF(.setup)) {
		src/library/library.o (.text);
		src/library/library.o (.data);
	}

	.game 0x7f000000 : AT(SIZEOF(.setup) + SIZEOF(.library)) {
		src/game/game_000000.o (.text);
		src/game/chr/chrai.o (.text);
		src/game/chr/chraicommands.o (.text);
		src/game/game_0601b0.o (.text);

		src/game/game_000000.o (.data);
		src/game/chr/chrai.o (.data);
		src/game/chr/chraicommands.o (.data);
		src/game/game_0601b0.o (.data);
	}

	.gvars 0x8008ae20 : AT(SIZEOF(.setup) + SIZEOF(.library) + SIZEOF(.game)) {
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
