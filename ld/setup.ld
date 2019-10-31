/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
	.setup 0x80059fe0 : AT(0) {
		src/setup/setup_000000.o (.data);
		src/setup/inventory.o (.data);
		src/setup/setup_0160b0.o (.data);
		src/setup/ailists.o (.data);
		src/setup/setup_020df0.o (.data);
	}

	.gvars 0x8008ae20 : AT(SIZEOF(.setup)) {
		src/gvars/gvars.o (.data);
	}

	.library 0x7e000000 : AT(SIZEOF(.setup) + SIZEOF(.gvars)) {
		src/library/library.o (.text);
		src/library/library.o (.data);
	}

	.game 0x7f000000 : AT(SIZEOF(.setup) + SIZEOF(.gvars) + SIZEOF(.library)) {
		src/game/game_000000.o (.text);
		src/game/chr/chrai.o (.text);
		src/game/chr/chraicommands.o (.text);
		src/game/game_0601b0.o (.text);

		src/game/game_000000.o (.data);
		src/game/chr/chrai.o (.data);
		src/game/chr/chraicommands.o (.data);
		src/game/game_0601b0.o (.data);
	}

	.boot 0x7d001000 : AT(SIZEOF(.setup) + SIZEOF(.gvars) + SIZEOF(.library) + SIZEOF(.game)) {
		src/boot/boot.o (.text);
		src/boot/boot.o (.data);
	}

	/* We don't really care about these values here */
	setupSegmentStart = 0;
	setupSegmentRomStart = 0;
	rarezipSegmentStart = 0;
	rarezipSegmentRomStart = 0;
	ziplistSegmentRomStart = 0;

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
