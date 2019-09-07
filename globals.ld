/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
   _LnameXDataStart = ADDR(.data);
   _LnameXDataRomStart = 0x0000;
   .data 0x80059fe0 : AT(0x0000) {
      build/globals.tmp.o (.data);
   }
   _LnameXDataEnd = ADDR(.data) + SIZEOF(.data);
   _LnameXDataRomEnd = 0x0000 + SIZEOF(.data);



   _LnameXRODataStart = ADDR(.rodata);
   _LnameXRODataRomStart = _LnameXDataRomEnd;
   .rodata : AT(_LnameXDataRomEnd) {
      build/globals.tmp.o (.rodata);
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

