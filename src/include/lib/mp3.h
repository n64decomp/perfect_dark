#ifndef _IN_LIB_MP3_H
#define _IN_LIB_MP3_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

void mp3_init(ALHeap *heap);
void mp3_play_file(s32 romaddr, s32 filesize);
void mp3_stop(void);
void mp3_pause(void);
void mp3_unpause(void);
s32 mp3_is_busy(void);
void mp3_set_vol(s32 vol, bool arg1);
void mp3_set_pan(s32 pan, bool immediate);
bool mp3_make_samples(s32 arg0, Acmd **cmd);

#endif
