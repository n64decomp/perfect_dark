#ifndef _IN_LIB_LIB_3E8C0_H
#define _IN_LIB_LIB_3E8C0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool mp3decInit(void);
bool mp3dec00040164(struct asistream *stream, u32 gr, u32 ch);
bool mp3decUnpackScaleFac(struct asistream *stream, u32 gr, u32 ch);
bool mp3dec00041600(struct asistream *stream, u32 gr, u32 ch);
bool mp3dec00042238(struct asistream *stream, u32 gr, u32 ch);
bool mp3dec000427d8(struct asistream *stream, u32 gr);
bool mp3decReduceAliases(struct asistream *stream, u32 gr, u32 ch);
bool mp3decSetSideInfo(struct asistream *stream);
bool mp3decDecodeFrame(struct asistream *stream);

#endif
