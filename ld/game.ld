/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
	.game 0x0f000000 : AT(0) {
		src/game/game_000000.o (.text);
		src/game/chr/chrai.o (.text);
		src/game/chr/chraicommands.o (.text);
		src/game/game_0601b0.o (.text);
	}

	.gamerodata 0x7f000000 + SIZEOF(.game) : AT(SIZEOF(.game)) {
		src/game/game_000000.o (.rodata);
		src/game/chr/chrai.o (.rodata);
		src/game/chr/chraicommands.o (.rodata);
		src/game/game_0601b0.o (.rodata);

		src/game/game_000000.o (.data);
		src/game/chr/chrai.o (.data);
		src/game/chr/chraicommands.o (.data);
		src/game/game_0601b0.o (.data);
	}

	.library 0x00003050 : AT(SIZEOF(.game) + SIZEOF(.gamerodata)) {
		src/library/library.o (.text);
		src/library/library.o (.data);
	}

	.setup 0x80059fe0 : AT(SIZEOF(.game) + SIZEOF(.gamerodata) + SIZEOF(.library)) {
		src/setup/setup_000000.o (.data);
		src/setup/inventory.o (.data);
		src/setup/setup_0160b0.o (.data);
		src/setup/ailists.o (.data);
		src/setup/setup_020df0.o (.data);
	}

	.gvars 0x8008ae20 : AT(SIZEOF(.game) + SIZEOF(.gamerodata) + SIZEOF(.library) + SIZEOF(.setup)) {
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
