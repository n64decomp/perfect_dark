/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
	.gvars 0x80099fc0 : AT(0) {
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
		* (.setup.data);
	}
}
