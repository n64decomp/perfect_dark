#ifndef IN_GAME_PAK_H
#define IN_GAME_PAK_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

bool pakIsMemoryPak(s8 device);
s32 pakGetFileIdsByType(s8 device, u32 filetype, u32 *fileids);
s32 pak0f1167d8(s8 device);
s32 pakReadBodyAtGuid(s8 device, s32 fileid, u8 *body, s32 arg3);
s32 pakSaveAtGuid(s8 device, s32 fileid, s32 filetype, u8 *body, s32 *outfileid, u8 *olddata);
bool pakDeleteFile(s8 device, s32 fileid);
s32 pakDeleteGameNote(s8 device, u16 company_code, u32 game_code, char *game_name, char *ext_name);
s32 pak0f1168c4(s8 device, struct pakdata **arg1);
u32 pakGetType(s8 device);
s32 pakGetSerial(s8 device);
void pak0f11698c(s8 device);
void pak0f116994(void);
void pak0f1169c8(s8 device, s32 arg1);
void pak0f116bdc(s8 device, u8 *arg1, u8 *arg2);
void pakSetUnk010(s8 device, s32 value);
s32 pakGetUnk264(s8 device);
void pak0f117150(s8 device, u8 *ptr);
void pak0f1171b4(s8 device, s32 arg1, s32 arg2);
s32 pakGetUnk008(s8 device);
void pakDumpBuffer(u8 *buffer, u32 len, char *name);
void pakDumpEeprom(void);
PakErr1 _pakResizeNote(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, u32 numbytes);
s32 pakGetPdNumPages(s8 device);
s32 pakQueryNumFreePages(s8 device);
bool pakCanFitCameraFileInPak(s8 device);
s32 pakGetNumFreeCameraSpacesInPak(s8 device);
s32 _pakCreateCameraFile(s8 device, s32 *outfileid);
bool pakResizeNote(s8 device, s32 numpages);
void pak0f1185e0(s8 device, s32 arg1, s32 arg2);
void paksInit(void);
s32 pakFindFile(s8 device, u32 fileid, struct pakfileheader *header);
void pakCorrupt(void);
void pakMergeBlanks(s8 device);
void paksReset(void);
void pakWipe(s8 device, u32 blocknumstart, u32 blocknumend);
bool pakReplaceFileAtOffsetWithBlank(s8 device, u32 offset);
bool pakRepair(s8 device);
void paksTick(void);
void pak0f11c6d0(void);
void pakExecuteDebugOperations(void);
void pak0f11d118(u8 *arg0, u8 arg1, u32 arg2);
void pak0f11d174(s8 device, u8 *arg1);
void pak0f11d214(u8 *arg0, u32 arg1);
s32 pak0f11d3f8(s8 device);
bool pak0f11d478(s8 device);
bool pak0f11d4dc(s8 device);
s32 pak0f11d540(s8 device, s32 arg1);
s32 pak0f11d5b0(s8 device);
void pak0f11d620(s8 device);
void pak0f11d9c4(s8 device, u8 *arg1, u8 *arg2, u32 arg3);
void pakRumble(s32 device, f32 numsecs, s32 onduration, s32 offduration);
void paksStop(bool disablepolling);
void pakDisableRumbleForPlayer(s8 playernum);
void pakEnableRumbleForPlayer(s8 playernum);
void pakDisableRumbleForAllPlayers(void);
void pakEnableRumbleForAllPlayers(void);
void pakDumpPak(void);
void pak0f11e3bc(s8 device);
void pakSetBitflag(s32 flagnum, u8 *bitstream, bool set);
bool pakHasBitflag(u32 flagnum, u8 *stream);
void pakClearAllBitflags(u8 *flags);
void pakN64FontCodeToAscii(char *src, char *dst, s32 len);
s8 pakFindBySerial(s32 deviceserial);
s32 pak0f11e750(s8 device);
bool gbpakIsAnyPerfectDark(void);

#endif
