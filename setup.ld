/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
   _LnameXDataStart = ADDR(.data);
   _LnameXDataRomStart = 0x0000;
   .data 0x00000000 : AT(0x0000) {
      build/setup.tmp.o (.data);
   }
   _LnameXDataEnd = ADDR(.data) + SIZEOF(.data);
   _LnameXDataRomEnd = 0x0000 + SIZEOF(.data);



   _LnameXRODataStart = ADDR(.rodata);
   _LnameXRODataRomStart = _LnameXDataRomEnd;
   .rodata : AT(_LnameXDataRomEnd) {
      build/setup.tmp.o (.rodata);
   }
   _LnameXRODataEnd = ADDR( .rodata) + SIZEOF( .rodata);
   _LnameXRODataRomEnd = _LnameXDataRomEnd + SIZEOF( .rodata);

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

