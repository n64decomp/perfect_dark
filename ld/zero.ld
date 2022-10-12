/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
	.data 0x00000000 : AT(0x0000) {
		__FILE__ (.data);
		. = ALIGN(0x10);
	}

	.rodata : AT(SIZEOF(.data)) {
		__FILE__ (.rodata);
		. = ALIGN(0x10);
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
