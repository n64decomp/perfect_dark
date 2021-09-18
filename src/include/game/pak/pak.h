#ifndef IN_GAME_PAK_PAK_H
#define IN_GAME_PAK_PAK_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 pakGetAlignment(s8 device);
u32 pakAlign(s8 device, u32 size);
s32 pakGetAlignedFileLenByBodyLen(s8 device, s32 bodylen);
u32 pak0f116684(u32 arg0);
u32 pakGenerateSerial(s8 device);
bool pakIsConnected(s8 device);
s32 pak0f1167b0(s8 device, u32 filetype, u32 *buffer1024);
u32 pak0f1167d8(s8 arg0);
s32 pak0f116800(s8 device, s32 fileid, u8 *body, s32 arg3);
s32 pak0f116828(s8 device, s32 fileid, s32 filetype, u8 *body, s32 *outfileid, s32 arg5);
bool pakDeleteFile(s8 device, s32 fileid);
s32 pakDeleteGameNote(s8 device, u16 company_code, u32 game_code, char *game_name, char *ext_name);
s32 pak0f1168c4(s8 device, struct pakdata **arg1);
u32 pak0f116914(s8 device);
s32 pakGetDeviceSerial(s8 device);
void pak0f11698c(s8 device);
void pak0f116994(void);
void pak0f1169c8(s8 device, s32 arg1);
bool pak0f116aec(s8 device);
bool pak0f116b5c(s8 device);
void pak0f116bdc(s8 device, u8 *arg1, u8 *arg2);
u16 pakGetSerial(s8 device);
u32 pakGetUnk000(s8 device);
void pakSetUnk010(s8 device, s32 value);
s32 pak0f116df0(s8 device, struct pakdata **arg1);
s32 pakDeleteGameNote2(s8 device, u16 company_code, u32 game_code, char *game_name, char *ext_name);
s32 pakDeleteFile2(s8 device, s32 fileid);
s32 pakGetUnk264(s8 device);
u32 pak0f11706c(s8 device);
s32 pakGetBodyLenByType(s8 device, u32 filetype);
void pak0f117150(s8 device, u8 *ptr);
void pak0f1171b4(s8 device, s32 arg1, s32 arg2);
s32 pakGetUnk008(s8 device);
u32 pak0f117430(void);
u32 pakReadHeaderAtOffset(s8 device, u32 arg1, struct pakfileheader *header);
void pakDumpBuffer(u8 *buffer, u32 len, char *name);
void pakDumpEeprom(void);
s32 pak0f11789c(s8 device, s32 fileid, s32 filetype, u8 *body, s32 *outfileid, s32 arg5);

#if VERSION >= VERSION_NTSC_1_0
s32 pakInitPak(OSMesgQueue *mq, OSPfs *pfs, s32 channel, s32 *arg3);
#else
s32 pakInitPak(OSMesgQueue *mq, OSPfs *pfs, s32 channel);
#endif

s32 pakReadWriteFile(OSPfs *pfs, s32 file_no, u8 flag, u32 address, u32 len, u8 *buffer);
s32 pak0f117c0c(s32 arg0, s32 *arg1, s32 *arg2);
s32 pakFreeBlocks(OSPfs *pfs, s32 *bytes_not_used);
s32 pakFileState(OSPfs *pfs, s32 file_no, OSPfsState *note);
s32 pakAllocateFile(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name, s32 size, s32 *file_no);
u32 pakDeleteGameNote3(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name);
s32 pakFindNote(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name, s32 *file_no);
s32 pak0f117ec0(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, u32 numbytes);
s32 pakGetUnk2a8(s8 device);
u32 pakGetNoteLen(s8 device);
s32 pak0f118000(s8 device);
s32 pak0f11807c(s8 device);
s32 pak0f118148(s8 device);
s32 pak0f118230(s8 device, s32 arg1);
s32 pak0f118334(s8 device, s32 numpages);
void pak0f1185e0(s8 device, s32 arg1, s32 param_3);
u32 pak0f118674(s8 arg0, u32 arg1, u32 arg2);
void pakInitAll(void);
void pakCalculateChecksum(u8 *arg0, u8 *arg1, u16 *arg2);
s32 pak0f118bc8(s8 device, s32 fileid, u8 *body, s32 arg3);
s32 pak0f118d18(s8 device, u32 filetype, u32 *buffer1024);
s32 pak0f1190bc(s8 device, s32 arg1, s32 *arg2);
u32 pak0f119298(s8 device);
void pak0f119340(u32 arg0);
s32 pakFindFile(s8 device, u32 fileid, struct pakfileheader *header);
#if VERSION >= VERSION_NTSC_FINAL
bool pak0f119478(u32 arg0, u32 arg1, u32 *arg2);
#endif
u32 pak0f1194e0(s8 arg0, u32 *arg1, u32 arg2);
u32 pak0f11970c(void);
void pakCorrupt(void);
u32 pak0f119e8c(void);
u32 pak0f11a0e8(void);
u32 pak0f11a1d0(void);
void pak0f11a2e4(void);
void pak0f11a32c(s8 device, u8 arg1, u32 line, char *file);
void pakInit(s8 arg0);
s32 pak0f11a504(s8 device, OSPfs *pfs, s32 file_no, u8 flag, u32 address, u32 len, u8 *buffer);
s32 pak0f11a574(s8 device);
u32 pak0f11a7dc(void);
u32 pak0f11a8f4(void);
u32 pak0f11ac7c(void);
void pakWipe(s8 device, u32 start, u32 end);
u32 pak0f11b178(void);
u32 pak0f11b488(void);
s32 pakScrub(s8 device);
bool pak0f11b75c(s8 device, u32 *arg1);
s32 pak0f11b86c(s32 device, u32 uVar2, u8 *data, struct pakfileheader *header, s32 arg3);
u32 pak0f11bbd8(void);
s32 pak0f11bc54(s8 device, s32 arg1, s32 filetype, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
bool pakRepair(s8 device);
u32 pak0f11c39c(u32 arg0, s8 device, u32 ar2, u32 arg3);
void pak0f11c54c(void);
void pak0f11c6d0(void);
void pakExecuteDebugOperations(void);
void pak0f11ca30(void);
void pak0f11cb9c(u32 arg0);
s32 pak0f11cbd8(s8 device, s32 arg1, char *arg2, u16 arg3);
s32 pak0f11cc6c(s8 device, u16 arg1, char *buffer, u16 len);
bool pak0f11cd00(s8 device, u16 arg1, char *arg2, s32 arg3, s32 arg4);
bool pak0f11ce00(s8 device, u16 arg1, char *arg2, s32 arg3, bool arg4);
u32 pak0f11d118(void);
u32 pak0f11d174(void);
u32 pak0f11d214(void);
u32 pak0f11d3f8(void);
u32 pak0f11d478(void);
u32 pak0f11d4dc(void);
s32 pak0f11d540(s8 device, s32 arg1);
s32 pak0f11d5b0(s8 device);
void pak0f11d620(s8 device);
u32 pak0f11d8b4(void);
u32 pak0f11d9c4(void);

#if VERSION >= VERSION_NTSC_1_0
void pak0f11dc04(s32 arg0, f32 arg1, s32 arg2, s32 arg3);
#else
void pak0f11dc04(s8 arg0, f32 arg1, s32 arg2, s32 arg3);
#endif

void pak0f11dcb0(s32 arg0);
void pak0f11dd58(s8 playernum);
void pak0f11de20(s8 playernum);
void pak0f11deb8(void);
void pak0f11df38(void);
void pakDumpPak(void);
void pak0f11df94(s8 device);
void pak0f11e3bc(s8 device);
void pakProbeEeprom(void);
s32 pakReadEeprom(u8 address, u8 *buffer, u32 len);
s32 pakWriteEeprom(u8 address, u8 *buffer, u32 len);
void pakSetBitflag(s32 flagnum, u8 *bitstream, bool set);
bool pakHasBitflag(u32 flagnum, u8 *stream);
void pakClearAllBitflags(u8 *flags);
void pakN64FontCodeToAscii(char *src, char *dst, s32 len);
s8 pakFindBySerial(s32 deviceserial);
s32 pak0f11e750(s8 arg0);
bool pak0f11e78c(void);
bool pak0f11e7f0(char *a, char *b);
s32 pak0f11e844(s8 device);
bool pak0f11ea34(s8 arg0);

extern const char var7f1b423c[];
extern const char var7f1b4244[];
extern const char var7f1b424c[];
extern const char var7f1b4254[];
extern const char var7f1b425c[];

#endif
