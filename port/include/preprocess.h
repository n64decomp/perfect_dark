#ifndef _IN_PREPROCESS_H
#define _IN_PREPROCESS_H

#include <PR/ultratypes.h>

typedef void (*preprocessfunc)(u8 *data, u32 size);

void preprocessAnimations(u8 *data, u32 size);
void preprocessMpConfigs(u8 *data, u32 size);
void preprocessFont(u8 *data, u32 size);
void preprocessJpnFont(u8 *data, u32 size);
void preprocessALBankFile(u8 *data, u32 size);
void preprocessALCMidiHdr(u8 *data, u32 size);
void preprocessSequences(u8 *data, u32 size);
void preprocessFiringRange(u8 *data, u32 size);
void preprocessTexturesList(u8 *data, u32 size);

void preprocessBgSection1Header(u8 *data, u32 size);
void preprocessBgSection1(u8 *data, u32 size);
void preprocessBgSection2Header(u8 *data, u32 size);
void preprocessBgSection2(u8 *data, u32 size);
void preprocessBgSection3Header(u8 *data, u32 size);
void preprocessBgSection3(u8 *data, u32 size);
void preprocessBgRoom(u8 *data, u32 ofs);
void preprocessBgLights(u8 *data, u32 ofs);

void preprocessLangFile(u8 *data, u32 size);
void preprocessPadsFile(u8 *data, u32 size);
void preprocessTilesFile(u8 *data, u32 size);
void preprocessSetupFile(u8 *data, u32 size);
void preprocessModelFile(u8 *data, u32 size);
void preprocessGunFile(u8 *data, u32 size);

#endif
