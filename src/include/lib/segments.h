#ifndef _IN_BOOT_SEGMENTS_H
#define _IN_BOOT_SEGMENTS_H
#include <ultra64.h>

void *seg_get_data_start(void);
void *seg_get_datazip_rom_start(void);
void *seg_get_inflate_rom_start(void);
void *seg_get_inflate_rom_start2(void);
void *seg_get_gamezips_rom_start(void);
void seg_inflate(void *src, void *dst, void *scratch);

#endif
