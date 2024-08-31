#ifndef _IN_LIB_LIB_3E8C0_H
#define _IN_LIB_LIB_3E8C0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool mp3dec_init(void);
bool mp3dec_set_side_info(struct asistream *stream);
bool mp3dec_decode_frame(struct asistream *stream);

#endif
