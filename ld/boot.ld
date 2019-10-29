/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
	setupSegmentStart = 0x80059fe0;
	setupSegmentRomStart = 0x39850;
	rarezipSegmentRomStart = 0x4e850;
	ziplistSegmentRomStart = 0x4fc40;

	.boot 0x00001000 : AT(0) {
		src/boot/boot.o (.text);
		src/boot/boot.o (.data);
	}

	.library 0x00003050 : AT(SIZEOF(.boot)) {
		src/library/library.o (.text);
		src/library/library.o (.data);
	}

	.setup 0x80059fe0 : AT(SIZEOF(.boot) + SIZEOF(.library)) {
		src/setup/setup_000000.o (.data);
		src/setup/inventory.o (.data);
		src/setup/setup_0160b0.o (.data);
		src/setup/ailists.o (.data);
		src/setup/setup_020df0.o (.data);
	}

	.gvars 0x8008ae20 : AT(SIZEOF(.boot) + SIZEOF(.library) + SIZEOF(.setup)) {
		src/gvars/gvars.o (.bss);
	}

	.game 0x0f000000 : AT(SIZEOF(.boot) + SIZEOF(.library) + SIZEOF(.setup) + SIZEOF(.gvars)) {
		src/game/game_000000.o (.text);
		src/game/chr/chrai.o (.text);
		src/game/chr/chraicommands.o (.text);
		src/game/game_0601b0.o (.text);

		src/game/game_000000.o (.data);
		src/game/chr/chrai.o (.data);
		src/game/chr/chraicommands.o (.data);
		src/game/game_0601b0.o (.data);

		src/game/game_000000.o (.rodata);
		src/game/chr/chrai.o (.rodata);
		src/game/chr/chraicommands.o (.rodata);
		src/game/game_0601b0.o (.rodata);
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
