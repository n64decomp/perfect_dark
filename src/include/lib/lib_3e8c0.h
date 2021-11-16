#ifndef _IN_LIB_LIB_3E8C0_H
#define _IN_LIB_LIB_3E8C0_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

extern const u32 var70054b40[];
extern const u32 var70054b68[];
extern const u32 var70054bb8[];
extern const u32 var70054c08[];
extern const u32 var70054c08[];
extern const u32 var70054c90[];
extern const u32 var70054d18[];
extern const u32 var70054e40[];
extern const u32 var70054f68[];
extern const u32 var70055090[];
extern const u32 var70055298[];
extern const u32 var700554a0[];
extern const u32 var700556a8[];
extern const u32 var70055eb0[];
extern const u32 var70055eb0[];
extern const u32 var700566b8[];
extern const u32 var700566b8[];
extern const u32 var700566b8[];
extern const u32 var700566b8[];
extern const u32 var700566b8[];
extern const u32 var700566b8[];
extern const u32 var700566b8[];
extern const u32 var700566b8[];
extern const u32 var70056ec0[];
extern const u32 var70056ec0[];
extern const u32 var70056ec0[];
extern const u32 var70056ec0[];
extern const u32 var70056ec0[];
extern const u32 var70056ec0[];
extern const u32 var70056ec0[];
extern const u32 var70056ec0[];
extern const u32 var700576c8[];
extern const u32 var70057750[];

u32 func0003f8a0(void);
void func00040164(struct asistream *stream, u32 gr, u32 ch);
bool mp3decUnpackScaleFac(struct asistream *stream, u32 gr, u32 ch);
void func00041600(struct asistream *stream, u32 gr, u32 ch);
bool func00042238(struct asistream *stream, u32 gr, u32 ch);
bool func000427d8(struct asistream *stream, u32 gr);
bool mp3decReduceAliases(struct asistream *stream, u32 gr, u32 ch);
bool mp3decSetSideInfo(struct asistream *stream);
bool mp3decDecodeFrame(struct asistream *stream);

#endif
