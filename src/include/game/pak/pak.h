#ifndef IN_GAME_PAK_PAK_H
#define IN_GAME_PAK_PAK_H
#include <ultra64.h>
#include "data.h"
#include "types.h"

u32 pakGetBlockSize(s8 device);
u32 pakAlign(s8 device, u32 size);
s32 pakGetAlignedFileLenByBodyLen(s8 device, u32 bodylen);
u32 pakGetBodyLenByFileLen(u32 filelen);
u32 pakGenerateSerial(s8 device);
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
bool pak0f116aec(s8 device);
bool pak0f116b5c(s8 device);
void pak0f116bdc(s8 device, u8 *arg1, u8 *arg2);
u16 _pakGetSerial(s8 device);
u32 _pakGetType(s8 device);
void pakSetUnk010(s8 device, s32 value);
s32 pak0f116df0(s8 device, struct pakdata **arg1);
s32 _pakDeleteGameNote(s8 device, u16 company_code, u32 game_code, char *game_name, char *ext_name);
s32 _pakDeleteFile(s8 device, s32 fileid);
s32 pakGetUnk264(s8 device);
u32 pakGetMaxFileSize(s8 device);
s32 pakGetBodyLenByType(s8 device, u32 filetype);
void pak0f117150(s8 device, u8 *ptr);
void pak0f1171b4(s8 device, s32 arg1, s32 arg2);
s32 pakGetUnk008(s8 device);
bool pakRetrieveBlockFromCache(s8 device, u32 offset, u8 *dst);
PakErr2 pakReadHeaderAtOffset(s8 device, u32 offset, struct pakfileheader *header);
void pakDumpBuffer(u8 *buffer, u32 len, char *name);
void pakDumpEeprom(void);
s32 _pakSaveAtGuid(s8 device, s32 fileid, s32 filetype, u8 *newdata, s32 *outfileid, u8 *olddata);

#if VERSION >= VERSION_NTSC_1_0
PakErr1 pakInitPak(OSMesgQueue *mq, OSPfs *pfs, s32 channel, s32 *arg3);
#else
PakErr1 pakInitPak(OSMesgQueue *mq, OSPfs *pfs, s32 channel);
#endif

PakErr1 _pakReadWriteBlock(OSPfs *pfs, s32 file_no, u8 flag, u32 address, u32 len, u8 *buffer);
PakErr1 pakNumFiles(OSPfs *pfs, s32 *max_files, s32 *files_used);
PakErr1 pakFreeBlocks(OSPfs *pfs, s32 *bytes_not_used);
PakErr1 pakFileState(OSPfs *pfs, s32 file_no, OSPfsState *note);
PakErr1 pakAllocateNote(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name, s32 size, s32 *file_no);
PakErr1 pakDeleteGameNote3(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name);
PakErr1 pakFindNote(OSPfs *pfs, u16 company_code, u32 game_code, char *game_name, char *ext_name, s32 *file_no);
PakErr1 _pakResizeNote(OSPfs *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, u32 numbytes);
s32 pakGetNumPages(s8 device);
u32 pakGetNumBytes(s8 device);
s32 pakGetNumFreePages(s8 device);
bool pakCanFitCameraFileInPak(s8 device);
s32 pakGetNumFreeCameraSpacesInPak(s8 device);
s32 _pakCreateCameraFile(s8 device, s32 *outfileid);
bool pakResizeNote(s8 device, s32 numpages);
void pak0f1185e0(s8 device, s32 arg1, s32 arg2);
u32 pak0f118674(s8 device, u32 filetype, s32 *outfileid);
void pakInitAll(void);
void pakCalculateChecksum(u8 *arg0, u8 *arg1, u16 *arg2);
s32 _pakReadBodyAtGuid(s8 device, s32 fileid, u8 *body, s32 arg3);
s32 _pakGetFileIdsByType(s8 device, u32 filetype, u32 *fileids);
s32 pakCheckFileCanFitInNote(s8 device, s32 filetype, s32 *numspaces);
u32 pak0f119298(s8 device);
void pak0f119340(u32 arg0);
s32 pakFindFile(s8 device, u32 fileid, struct pakfileheader *header);
#if VERSION >= VERSION_NTSC_FINAL
bool pakWriteBlankFile(s8 device, u32 offset, struct pakfileheader *header);
#endif
bool pakRepairAsBlank(s8 device, u32 *offset, struct pakfileheader *header);
s32 pakRepairFilesystem(s8 device);
void pakCorrupt(void);
bool pakCreateInitialFiles(s8 device);
s32 pakFindMaxFileId(s8 device);
void pakMergeBlanks(s8 device);
void pak0f11a2e4(void);
void pak0f11a32c(s8 device, u8 arg1, u32 line, char *file);
void pakInit(s8 arg0);
PakErr1 pakReadWriteBlock(s8 device, OSPfs *pfs, s32 file_no, u8 flag, u32 address, u32 len, u8 *buffer);
s32 pak0f11a574(s8 device);
void pakUpdateSize(s8 device);
bool mempakPrepare(s8 device);
void pak0f11ac7c(s8 device);
void pakWipe(s8 device, u32 blocknumstart, u32 blocknumend);
void pakSaveHeaderToCache(s8 device, s32 blocknum, struct pakfileheader *header);
bool pakRetrieveHeaderFromCache(s8 device, s32 blocknum, struct pakfileheader *header);
s32 pakCreateFilesystem(s8 device);
bool pakGetFilesystemLength(s8 device, u32 *outlen);
s32 pak0f11b86c(s8 device, u32 offset, u8 *data, struct pakfileheader *header, s32 arg4);
bool pakReplaceFileAtOffsetWithBlank(s8 device, u32 offset);
s32 pakWriteFileAtOffset(s8 device, u32 offset, u32 filetype, u8 *newdata, s32 bodylen, s32 *outfileid, u8 *olddata, u32 fileid, u32 generation);
bool pakRepair(s8 device);
bool pakHandleResult(s32 err1, s8 device, bool arg2, u32 line);
void pak0f11c54c(void);
void pak0f11c6d0(void);
void pakExecuteDebugOperations(void);
void pak0f11ca30(void);
void gbpakHandleError(u32 arg0);
bool gbpakRead(s8 device, u16 address, u8 *buffer, u16 size);
bool gbpakWrite(s8 device, u16 address, u8 *buffer, u16 size);
bool pak0f11cd00(s8 device, u16 arg1, char *arg2, s32 arg3, s32 arg4);
bool pak0f11ce00(s8 device, u16 arg1, char *arg2, s32 arg3, bool arg4);
void pak0f11d118(u8 *arg0, u8 arg1, u32 arg2);
void pak0f11d174(s8 device, u8 *arg1);
void pak0f11d214(u8 *arg0, u32 arg1);
s32 pak0f11d3f8(s8 device);
bool pak0f11d478(s8 device);
bool pak0f11d4dc(s8 device);
s32 pak0f11d540(s8 device, s32 arg1);
s32 pak0f11d5b0(s8 device);
void pak0f11d620(s8 device);
u32 pak0f11d8b4(void);
u32 pak0f11d9c4(void);

#if VERSION >= VERSION_NTSC_1_0
void pakRumble(s32 device, f32 numsecs, s32 onduration, s32 offduration);
#else
void pakRumble(s8 device, f32 numsecs, s32 onduration, s32 offduration);
#endif

void pakStopRumbleForAllPaks(bool disablepolling);
void pakDisableRumbleForPlayer(s8 playernum);
void pakEnableRumbleForPlayer(s8 playernum);
void pakDisableRumbleForAllPlayers(void);
void pakEnableRumbleForAllPlayers(void);
void pakDumpPak(void);
void pak0f11df94(s8 device);
void pak0f11e3bc(s8 device);
void pakProbeEeprom(void);
PakErr1 pakReadEeprom(u8 address, u8 *buffer, u32 len);
PakErr1 pakWriteEeprom(u8 address, u8 *buffer, u32 len);
void pakSetBitflag(s32 flagnum, u8 *bitstream, bool set);
bool pakHasBitflag(u32 flagnum, u8 *stream);
void pakClearAllBitflags(u8 *flags);
void pakN64FontCodeToAscii(char *src, char *dst, s32 len);
s8 pakFindBySerial(s32 deviceserial);
s32 pak0f11e750(s8 device);
bool gbpakIsAnyPerfectDark(void);
bool gbpakStrcmp(char *a, char *b);
s32 gbpakIdentifyGame(s8 device);
bool pak0f11ea34(s8 device);

extern const char var7f1b423c[];
extern const char var7f1b4244[];
extern const char var7f1b424c[];
extern const char var7f1b4254[];
extern const char var7f1b425c[];

#endif
