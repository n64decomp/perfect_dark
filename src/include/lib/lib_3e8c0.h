#ifndef _IN_LIB_LIB_3E8C0_H
#define _IN_LIB_LIB_3E8C0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool mp3dec_init(void);
bool mp3dec00040164(struct asistream *stream, u32 gr, u32 ch);
bool mp3dec_unpack_scale_fac(struct asistream *stream, u32 gr, u32 ch);
bool mp3dec00041600(struct asistream *stream, u32 gr, u32 ch);
bool mp3dec00042238(struct asistream *stream, u32 gr, u32 ch);
bool mp3dec000427d8(struct asistream *stream, u32 gr);
bool mp3dec_reduce_aliases(struct asistream *stream, u32 gr, u32 ch);
bool mp3dec_set_side_info(struct asistream *stream);
bool mp3dec_decode_frame(struct asistream *stream);

#endif
