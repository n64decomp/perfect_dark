#ifndef _IN_LIB_LIB_3E8C0_H
#define _IN_LIB_LIB_3E8C0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool func0003f8a0(void);
bool func00040164(struct asistream *stream, u32 gr, u32 ch);
bool mp3decUnpackScaleFac(struct asistream *stream, u32 gr, u32 ch);
bool func00041600(struct asistream *stream, u32 gr, u32 ch);
bool func00042238(struct asistream *stream, u32 gr, u32 ch);
bool func000427d8(struct asistream *stream, u32 gr);
bool mp3decReduceAliases(struct asistream *stream, u32 gr, u32 ch);
bool mp3decSetSideInfo(struct asistream *stream);
bool mp3decDecodeFrame(struct asistream *stream);

#endif
