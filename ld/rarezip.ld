/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
	.text 0x70200000 : AT(0x0000) {
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

