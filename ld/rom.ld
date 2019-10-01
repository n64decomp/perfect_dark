/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
	.data 0x00003050 : AT(0x3050) {
		build/ntsc-final/library.o (.text);
		build/ntsc-final/library.o (.data);
	}

	.data 0x80059fe0 : AT(0x0000) {
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
	}
}
