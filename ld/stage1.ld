/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
	setupSegmentStart = 0x80059fe0;
	setupSegmentRomStart = 0x39850;
	rarezipSegmentRomStart = 0x4e850;
	ziplistSegmentRomStart = 0x4fc40;

	.boot 0x70001000 : AT(0) {
		src/boot/boot.o (.text);
		src/boot/boot.o (.data);
	}

	.library 0x70003050 : AT(SIZEOF(.boot)) {
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
		src/gvars/gvars.o (.data);
	}

	.game 0x7f000000 : AT(SIZEOF(.boot) + SIZEOF(.library) + SIZEOF(.setup) + SIZEOF(.gvars)) {
		src/game/game_000000.o (.text);
		src/game/game_000090.o (.text);
		src/game/game_000130.o (.text);
		src/game/game_000850.o (.text);
		src/game/game_000870.o (.text);
		src/game/game_0008e0.o (.text);
		src/game/game_000900.o (.text);
		src/game/game_000910.o (.text);
		src/game/game_000920.o (.text);
		src/game/game_005fd0.o (.text);
		src/game/game_00b190.o (.text);
		src/game/game_00b200.o (.text);
		src/game/game_00b820.o (.text);
		src/game/game_00c240.o (.text);
		src/game/game_00c490.o (.text);
		src/game/game_0109d0.o (.text);
		src/game/game_011110.o (.text);
		src/game/game_0125a0.o (.text);
		src/game/game_013260.o (.text);
		src/game/game_013540.o (.text);
		src/game/game_014f10.o (.text);
		src/game/game_015010.o (.text);
		src/game/game_0150a0.o (.text);
		src/game/game_015260.o (.text);
		src/game/game_015280.o (.text);
		src/game/game_015400.o (.text);
		src/game/game_015420.o (.text);
		src/game/game_015470.o (.text);
		src/game/game_01d860.o (.text);
		src/game/game_01d9f0.o (.text);
		src/game/chr/chr.o (.text);
		src/game/chr/chrai.o (.text);
		src/game/chr/chraicommands.o (.text);
		src/game/game_0601b0.o (.text);
		src/game/game_066310.o (.text);
		src/game/game_096750.o (.text);
		src/game/game_097890.o (.text);
		src/game/game_097970.o (.text);
		src/game/game_097a50.o (.text);
		src/game/game_0abe70.o (.text);
		src/game/game_0b0420.o (.text);
		src/game/game_0b2150.o (.text);
		src/game/game_0b28d0.o (.text);
		src/game/game_0c3620.o (.text);
		src/game/game_0c37d0.o (.text);
		src/game/game_0c79f0.o (.text);
		src/game/game_0cf150.o (.text);
		src/game/game_0d1fe0.o (.text);
		src/game/game_0d4690.o (.text);
		src/game/game_0dcdb0.o (.text);
		src/game/game_0f09f0.o (.text);
		src/game/game_102240.o (.text);
		src/game/game_106d40.o (.text);
		src/game/game_107fb0.o (.text);
		src/game/game_10ccd0.o (.text);
		src/game/game_111600.o (.text);
		src/game/game_113220.o (.text);
		src/game/game_114240.o (.text);
		src/game/game_115ab0.o (.text);
		src/game/game_11ecf0.o (.text);
		src/game/game_128f30.o (.text);
		src/game/game_129900.o (.text);
		src/game/game_150820.o (.text);
		src/game/game_152710.o (.text);
		src/game/game_152fa0.o (.text);
		src/game/game_157db0.o (.text);
		src/game/game_165670.o (.text);
		src/game/game_1668e0.o (.text);
		src/game/game_16cfa0.o (.text);
		src/game/game_175f50.o (.text);
		src/game/game_176080.o (.text);
		src/game/game_176d70.o (.text);
		src/game/game_187770.o (.text);
		src/game/game_197600.o (.text);
		src/game/game_1999b0.o (.text);
		src/game/game_19c990.o (.text);
		src/game/game_1a3340.o (.text);
		src/game/game_1a78b0.o (.text);

		src/game/game_000000.o (.rodata);
		src/game/game_000090.o (.rodata);
		src/game/game_000130.o (.rodata);
		src/game/game_000850.o (.rodata);
		src/game/game_000870.o (.rodata);
		src/game/game_0008e0.o (.rodata);
		src/game/game_000900.o (.rodata);
		src/game/game_000910.o (.rodata);
		src/game/game_000920.o (.rodata);
		src/game/game_005fd0.o (.rodata);
		src/game/game_00b190.o (.rodata);
		src/game/game_00b200.o (.rodata);
		src/game/game_00b820.o (.rodata);
		src/game/game_00c240.o (.rodata);
		src/game/game_00c490.o (.rodata);
		src/game/game_0109d0.o (.rodata);
		src/game/game_011110.o (.rodata);
		src/game/game_0125a0.o (.rodata);
		src/game/game_013260.o (.rodata);
		src/game/game_013540.o (.rodata);
		src/game/game_014f10.o (.rodata);
		src/game/game_015010.o (.rodata);
		src/game/game_0150a0.o (.rodata);
		src/game/game_015260.o (.rodata);
		src/game/game_015280.o (.rodata);
		src/game/game_015400.o (.rodata);
		src/game/game_015420.o (.rodata);
		src/game/game_015470.o (.rodata);
		src/game/game_01d860.o (.rodata);
		src/game/game_01d9f0.o (.rodata);
		src/game/chr/chr.o (.rodata);
		src/game/chr/chrai.o (.rodata);
		src/game/chr/chraicommands.o (.rodata);
		src/game/game_0601b0.o (.rodata);
		src/game/game_066310.o (.rodata);
		src/game/game_096750.o (.rodata);
		src/game/game_097890.o (.rodata);
		src/game/game_097970.o (.rodata);
		src/game/game_097a50.o (.rodata);
		src/game/game_0abe70.o (.rodata);
		src/game/game_0b0420.o (.rodata);
		src/game/game_0b2150.o (.rodata);
		src/game/game_0b28d0.o (.rodata);
		src/game/game_0c3620.o (.rodata);
		src/game/game_0c37d0.o (.rodata);
		src/game/game_0c79f0.o (.rodata);
		src/game/game_0cf150.o (.rodata);
		src/game/game_0d1fe0.o (.rodata);
		src/game/game_0d4690.o (.rodata);
		src/game/game_0dcdb0.o (.rodata);
		src/game/game_0f09f0.o (.rodata);
		src/game/game_102240.o (.rodata);
		src/game/game_106d40.o (.rodata);
		src/game/game_107fb0.o (.rodata);
		src/game/game_10ccd0.o (.rodata);
		src/game/game_111600.o (.rodata);
		src/game/game_113220.o (.rodata);
		src/game/game_114240.o (.rodata);
		src/game/game_115ab0.o (.rodata);
		src/game/game_11ecf0.o (.rodata);
		src/game/game_128f30.o (.rodata);
		src/game/game_129900.o (.rodata);
		src/game/game_150820.o (.rodata);
		src/game/game_152710.o (.rodata);
		src/game/game_152fa0.o (.rodata);
		src/game/game_157db0.o (.rodata);
		src/game/game_165670.o (.rodata);
		src/game/game_1668e0.o (.rodata);
		src/game/game_16cfa0.o (.rodata);
		src/game/game_175f50.o (.rodata);
		src/game/game_176080.o (.rodata);
		src/game/game_176d70.o (.rodata);
		src/game/game_187770.o (.rodata);
		src/game/game_197600.o (.rodata);
		src/game/game_1999b0.o (.rodata);
		src/game/game_19c990.o (.rodata);
		src/game/game_1a3340.o (.rodata);
		src/game/game_1a78b0.o (.rodata);
	}

	.rarezip 0x70200000 : AT(SIZEOF(.boot) + SIZEOF(.library) + SIZEOF(.setup) + SIZEOF(.gvars) + SIZEOF(.game)) {
		src/rarezip/rarezip.o (.text);
		src/rarezip/rarezip.o (.data);
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
