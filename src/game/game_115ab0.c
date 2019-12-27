#include <ultra64.h>
#include "constants.h"
#include "gvars/gvars.h"
#include "setup/setup_000000.h"
#include "setup/setup_0160b0.h"
#include "setup/setup_020df0.h"
#include "types.h"
#include "game/game_0f09f0.h"
#include "game/game_10ccd0.h"
#include "game/game_115ab0.h"
#include "game/game_128f30.h"
#include "game/game_129900.h"
#include "game/game_176d70.h"
#include "library/library_12dc0.h"

const u32 var7f1b3a90[] = {0x002a2a2a};
const u32 var7f1b3a94[] = {0x2a2a2a2a};
const u32 var7f1b3a98[] = {0x2a2a2a2a};
const u32 var7f1b3a9c[] = {0x2a2a2a20};
const u32 var7f1b3aa0[] = {0x30313233};
const u32 var7f1b3aa4[] = {0x34353637};
const u32 var7f1b3aa8[] = {0x38394142};
const u32 var7f1b3aac[] = {0x43444546};
const u32 var7f1b3ab0[] = {0x4748494a};
const u32 var7f1b3ab4[] = {0x4b4c4d4e};
const u32 var7f1b3ab8[] = {0x4f505152};
const u32 var7f1b3abc[] = {0x53545556};
const u32 var7f1b3ac0[] = {0x5758595a};
const u32 var7f1b3ac4[] = {0x21222327};
const u32 var7f1b3ac8[] = {0x2a2b2c2d};
const u32 var7f1b3acc[] = {0x2e2f3a3d};
const u32 var7f1b3ad0[] = {0x3f400000};

const char var7f1b3ad4[] = "Pak %d -> Pak_UpdateAndGetPakNoteInfo - ERROR - ekPakErrorPakFatal\n";
const char var7f1b3b18[] = "Pak %d -> Pak_UpdateAndGetPakNoteInfo - ERROR - ekPakErrorNoPakPresent\n";
const char var7f1b3b60[] = "-> Unknown PakFileType_e - %d\n";
const char var7f1b3b80[] = "-forceversion";
const char var7f1b3b90[] = "Pak %d -> Header Cache 2 - FATAL ERROR\n";
const char var7f1b3bb8[] = "\n";
const char var7f1b3bbc[] = "\nAddress = %u : ";
const char var7f1b3bd0[] = "%2x ";
const char var7f1b3bd8[] = "\n";
const char var7f1b3bdc[] = "EEPROM DUMP";
const char var7f1b3be8[] = "PakSaveAtGuid: new guid = %x\n";
const char var7f1b3c08[] = "Call to osPfsReSizeFile -> pfs=%x, cc=%u, gc=%u, gn=%s, en=%s, l=%d\n";
const char var7f1b3c50[] = "Pak %d -> Pak_AddOneCameraFile\n";
const char var7f1b3c70[] = "Pak %d -> Pak_AddOneCameraFile - Making one default camera file\n";
const char var7f1b3cb4[] = "Pak %d -> Pak_AddOneCameraFile : Got Space - No need for resize\n";
const char var7f1b3cf8[] = "Pak %d -> Pak_AddOneCameraFile : No Space - Need to resize by %d pages\n";
const char var7f1b3d40[] = "Pak %d -> Pak_AddOneCameraFile - Make of one default camera files failed\n";
const char var7f1b3d8c[] = "Pak %d -> Pak_AddOneCameraFile : Error - No Room\n";
const char var7f1b3dc0[] = "Pak %d -> Pak_GameNoteResetSize : New=%u\n";
const char var7f1b3dec[] = "bDoUpdate7\n";
const char var7f1b3df8[] = "Pak_SetThisGameSetupFile -> Pak=%d, File=%d, EEPROM=%d\n";
const char var7f1b3e30[] = "pak/pak.c";
const char var7f1b3e3c[] = "Pak %d -> Pak_Dir - ERROR : Pak Not Ready\n";
const char var7f1b3e68[] = "Pak %d -> Pak_Dir - Done - Pak_GetOffsetEOF\n";
const char var7f1b3e98[] = "Pak %d -> Pak_Dir - Done - ekPakErrorHeaderCrcCheckFail\n";
const char var7f1b3ed4[] = "Pak Return Code = ekPakOk";
const char var7f1b3ef0[] = "Pak Return Code = ekPakErrorNoPakPresent";
const char var7f1b3f1c[] = "Pak Return Code = ekPakErrorPakFatal";
const char var7f1b3f44[] = "Pak Return Code = ekPakErrorFileNotFound";
const char var7f1b3f70[] = "Pak Return Code = ekPakErrorFileSystem";
const char var7f1b3f98[] = "Pak Return Code = ekPakErrorOutOfMemory";
const char var7f1b3fc0[] = "Pak Return Code = ekPakErrorPakWaitingForInit";
const char var7f1b3ff0[] = "Pak Return Code = ekPakErrorHeaderCrcCheckFail";
const char var7f1b4020[] = "Pak Return Code = ekPakErrorDataCrcCheckFail";
const char var7f1b4050[] = "Pak Return Code = ekPakErrorDataNotValid";
const char var7f1b407c[] = "Pak Return Code = Unknown - %d\n";
const char var7f1b409c[] = "Pak %d -> Pak_RepairAsBlank - St=%u, Ed=%u, Gap=%u, Blank Size=%u\n";
const char var7f1b40e0[] = "Pak %d -> Pak_RepairAsBlank - Fatal Error at tOffset %u\n";
const char var7f1b411c[] = "Pak %d -> Pak_ValidateVersion - Start - Game File Size = %d\n";
const char var7f1b415c[] = "Pak %d -> Pak_ValidateVersion - Clearing cache 2\n";
const char var7f1b4190[] = "Pak %d -> Pak_ValidateVersion 1 - Loaded with ret=%d at offset %u\n";
const char var7f1b41d4[] = "Pak %d -> Pak_ValidateVersion 1 - Blank at %u\n";
const char var7f1b4204[] = "Pak %d -> Pak_ValidateVersion 2 - Loaded  at offset %u\n";
const char var7f1b423c[] = "BOS\n";
const char var7f1b4244[] = "CAM\n";
const char var7f1b424c[] = "MPP\n";
const char var7f1b4254[] = "MPG\n";
const char var7f1b425c[] = "GAM";
const char var7f1b4260[] = "> Pak_DefragPak_Level1 - Merge of two blanks failed";
const char var7f1b4294[] = "Pak %d - Pak_StartOne called from line %d in %s -> Flags = %0x\n";
const char var7f1b42d4[] = "\nPak_StartOne -> Pak%d, Modes -\n";
const char var7f1b42f8[] = "Memory,";
const char var7f1b4300[] = "Rumble,";
const char var7f1b4308[] = "Game Boy";
const char var7f1b4314[] = "\n";
const char var7f1b4318[] = "Pak %d -> %u Bytes of scratch for cache 2 memory at %0x\n";
const char var7f1b4354[] = "\nPak%d -> Pak_EndOne - Called from line %d in %s : Modes -\n";
const char var7f1b4390[] = "Memory,";
const char var7f1b4398[] = "Rumble,";
const char var7f1b43a0[] = "Game Boy";
const char var7f1b43ac[] = "\n";
const char var7f1b43b0[] = "Pak -> FATAL ERROR -> MEMORY INSTANCE ENDING IS NO LONGER SUPPORTED\n";
const char var7f1b43f8[] = "Pak -> Pak_MakeOne - Id=%d is finished\n";
const char var7f1b4420[] = "Pak %d -> Pak_Memory_UpdateNoteInfo\n";
const char var7f1b4448[] = "Pak %d -> Couldn't assertain the game note size\n";
const char var7f1b447c[] = "Pak %d -> Pak_AnalyseCurrentGameNote - Game note size = %uk\n";
const char var7f1b44bc[] = "Pak %d -> Searching for the game file\n";
const char var7f1b44e4[] = "Pak %d -> Game file wipe failed\n";
const char var7f1b4508[] = "RWI : Warning : tOffset > gPakObj[PakNum].GameFileSize\n";
const char var7f1b4540[] = "Pak %d -> Pak_DeleteFile_Offset - DataSize = %u\n";
const char var7f1b4574[] = "Pak %d -> Delete file offset (file id %d) failed\n";
const char var7f1b45a8[] = "Pak %d -> Delete file offset failed - Bad Offset passed\n";
const char var7f1b45e4[] = "-forceversion";
const char var7f1b45f4[] = "PakMac_PaksLive()=%x\n";
const char var7f1b460c[] = "paksNeedToBeLive4Game=%x\n";
const char var7f1b4628[] = "paksNeedToBeLive4Menu=%x\n";
const char var7f1b4644[] = "g_LastPackPattern=%x\n";
const char var7f1b465c[] = "forcescrub";
const char var7f1b4668[] = "pakdump";
const char var7f1b4670[] = "pakcache";
const char var7f1b467c[] = "pakinit";
const char var7f1b4684[] = "corruptme";
const char var7f1b4690[] = "wipeeeprom";
const char var7f1b469c[] = "dumpeeprom";
const char var7f1b46a8[] = "\nOS_GBPAK_GBCART_ON       - ";
const char var7f1b46c8[] = "\nOS_GBPAK_GBCART_PULL     - ";
const char var7f1b46e8[] = "\nOS_GBPAK_POWER           - ";
const char var7f1b4708[] = "\nOS_GBPAK_RSTB_DETECTION  - ";
const char var7f1b4728[] = "Pak -> Dumping contents of Game Boy Pack(TM) Id file";
const char var7f1b4760[] = "(u16) - Fixed1             - %d\n";
const char var7f1b4784[] = "(u16) - StartAddress       - %d\n";
const char var7f1b47a8[] = "(u8*) - Nintendo chr data  - %s\n";
const char var7f1b47cc[] = "(u8*) - Game Title         - %s\n";
const char var7f1b47f0[] = "(u16) - Company Code       - %d\n";
const char var7f1b4814[] = "(u8 ) - Body Code          - %d\n";
const char var7f1b4838[] = "(u8 ) - Rom Size           - %d\n";
const char var7f1b485c[] = "(u8 ) - Ram Size           - %d\n";
const char var7f1b4880[] = "(u8 ) - country_code       - %d\n";
const char var7f1b48a4[] = "(u8 ) - Fixed 2 (0x33)     - %d\n";
const char var7f1b48c8[] = "(u8 ) - Version Number     - %d\n";
const char var7f1b48ec[] = "(u8 ) - isum               - %d\n";
const char var7f1b4910[] = "(u16) - sum                - %d\n";
const char var7f1b4934[] = "Pak -> Finished Dump";

const u32 var7f1b494c[] = {0x43000000};
const u32 var7f1b4950[] = {0x43140000};
const u32 var7f1b4954[] = {0x435c0000};
const u32 var7f1b4958[] = {0x437f0000};
const u32 var7f1b495c[] = {0x43020000};
const u32 var7f1b4960[] = {0x43150000};
const u32 var7f1b4964[] = {0x43520000};
const u32 var7f1b4968[] = {0x437f0000};
const u32 var7f1b496c[] = {0x43040000};
const u32 var7f1b4970[] = {0x43160000};
const u32 var7f1b4974[] = {0x434a0000};
const u32 var7f1b4978[] = {0x437f0000};
const u32 var7f1b497c[] = {0x43060000};
const u32 var7f1b4980[] = {0x43160000};
const u32 var7f1b4984[] = {0x43440000};
const u32 var7f1b4988[] = {0x437f0000};
const u32 var7f1b498c[] = {0x43080000};
const u32 var7f1b4990[] = {0x43170000};
const u32 var7f1b4994[] = {0x433e0000};
const u32 var7f1b4998[] = {0x437f0000};
const u32 var7f1b499c[] = {0x430a0000};
const u32 var7f1b49a0[] = {0x43170000};
const u32 var7f1b49a4[] = {0x43380000};
const u32 var7f1b49a8[] = {0x437f0000};
const u32 var7f1b49ac[] = {0x430b0000};
const u32 var7f1b49b0[] = {0x43180000};
const u32 var7f1b49b4[] = {0x43320000};
const u32 var7f1b49b8[] = {0x43750000};
const u32 var7f1b49bc[] = {0x430c0000};
const u32 var7f1b49c0[] = {0x43180000};
const u32 var7f1b49c4[] = {0x432c0000};
const u32 var7f1b49c8[] = {0x436b0000};
const u32 var7f1b49cc[] = {0x430d0000};
const u32 var7f1b49d0[] = {0x43180000};
const u32 var7f1b49d4[] = {0x432a0000};
const u32 var7f1b49d8[] = {0x435d0000};
const u32 var7f1b49dc[] = {0x430e0000};
const u32 var7f1b49e0[] = {0x43180000};
const u32 var7f1b49e4[] = {0x43280000};
const u32 var7f1b49e8[] = {0x43500000};
const u32 var7f1b49ec[] = {0x430f0000};
const u32 var7f1b49f0[] = {0x43180000};
const u32 var7f1b49f4[] = {0x43260000};
const u32 var7f1b49f8[] = {0x43440000};
const u32 var7f1b49fc[] = {0x43100000};
const u32 var7f1b4a00[] = {0x43180000};
const u32 var7f1b4a04[] = {0x43240000};
const u32 var7f1b4a08[] = {0x433a0000};
const u32 var7f1b4a0c[] = {0x43120000};
const u32 var7f1b4a10[] = {0x43180000};
const u32 var7f1b4a14[] = {0x43210000};
const u32 var7f1b4a18[] = {0x43310000};
const u32 var7f1b4a1c[] = {0x43140000};
const u32 var7f1b4a20[] = {0x43180000};
const u32 var7f1b4a24[] = {0x431d0000};
const u32 var7f1b4a28[] = {0x43280000};
const u32 var7f1b4a2c[] = {0x43160000};
const u32 var7f1b4a30[] = {0x43180000};
const u32 var7f1b4a34[] = {0x43190000};
const u32 var7f1b4a38[] = {0x43200000};
const u32 var7f1b4a3c[] = {0x43180000};
const u32 var7f1b4a40[] = {0x43180000};
const u32 var7f1b4a44[] = {0x43180000};
const u32 var7f1b4a48[] = {0x43180000};
const u32 var7f1b4a4c[] = {0x00000000};
const u32 var7f1b4a50[] = {0x00000000};
const u32 var7f1b4a54[] = {0x00000000};
const u32 var7f1b4a58[] = {0x00000000};
const u32 var7f1b4a5c[] = {0x00000000};
const u32 var7f1b4a60[] = {0x41000000};
const u32 var7f1b4a64[] = {0x40000000};
const u32 var7f1b4a68[] = {0x41200000};
const u32 var7f1b4a6c[] = {0x41400000};
const u32 var7f1b4a70[] = {0x40800000};
const u32 var7f1b4a74[] = {0x41600000};
const u32 var7f1b4a78[] = {0x40c00000};
const u32 var7f1b4a7c[] = {0x40400000};
const u32 var7f1b4a80[] = {0x41300000};
const u32 var7f1b4a84[] = {0x3f800000};
const u32 var7f1b4a88[] = {0x41100000};
const u32 var7f1b4a8c[] = {0x41700000};
const u32 var7f1b4a90[] = {0x40e00000};
const u32 var7f1b4a94[] = {0x41500000};
const u32 var7f1b4a98[] = {0x40a00000};
const u32 var7f1b4a9c[] = {0x00000000};
const u32 var7f1b4aa0[] = {0x41600000};
const u32 var7f1b4aa4[] = {0x40400000};
const u32 var7f1b4aa8[] = {0x41500000};
const u32 var7f1b4aac[] = {0x41300000};
const u32 var7f1b4ab0[] = {0x40a00000};
const u32 var7f1b4ab4[] = {0x41000000};
const u32 var7f1b4ab8[] = {0x40c00000};
const u32 var7f1b4abc[] = {0x41400000};
const u32 var7f1b4ac0[] = {0x40000000};
const u32 var7f1b4ac4[] = {0x41700000};
const u32 var7f1b4ac8[] = {0x3f800000};
const u32 var7f1b4acc[] = {0x40e00000};
const u32 var7f1b4ad0[] = {0x41100000};
const u32 var7f1b4ad4[] = {0x40800000};
const u32 var7f1b4ad8[] = {0x41200000};

const char var7f1b4adc[] = "Pak_StartCapture -> Failed - Code = %d\n";
const char var7f1b4b04[] = "Pak_DownloadNextBlockToPackBuffer : eQuality=ekCapQualityHeader, BufferNum=%d\n";
const char var7f1b4b54[] = "Pak : Doing Frame - Top    = %d\n";
const char var7f1b4b78[] = "Pak : Doing Frame - Height = %d\n";
const char var7f1b4b9c[] = "Pak : Doing Frame - Bottom = %d\n";
const char var7f1b4bc0[] = "Pak %d - ekPakInitStatusError_CorruptedPak\n";
const char var7f1b4bec[] = "Pak %d - ekPakInitStatusInitGameBoy_PDGB_Check_Error\n";
const char var7f1b4c24[] = "Pak %d - ekPakInitStatusError_DamagedPak\n";
const char var7f1b4c50[] = "Pak %d - ekPakInitStatusError_StuffedPak\n";
const char var7f1b4c7c[] = "Pak %d - ekPakInitStatusError_StuffedAndCheckedPak\n";
const char var7f1b4cb0[] = "Pak %d - ekPakInitStatusVoid\n";
const char var7f1b4cd0[] = "Pak %d -> Unhandled Init Status - %d\n";
const char var7f1b4cf8[] = "Pak %d - PakDamage_UjiWipedMyAss\n";
const char var7f1b4d1c[] = "-scrub";
const char var7f1b4d24[] = "Pak %d -> Pak_PdGameBoySetRWByte - Fatal Error\n";
const char var7f1b4d54[] = "0123456789012345678901234567890123456789";
const char var7f1b4d80[] = "PerfDark\n";

const u32 var7f1b4d8c[] = {0x7f116794};
const u32 var7f1b4d90[] = {0x7f116794};
const u32 var7f1b4d94[] = {0x7f11679c};
const u32 var7f1b4d98[] = {0x7f11679c};
const u32 var7f1b4d9c[] = {0x7f11679c};
const u32 var7f1b4da0[] = {0x7f116794};
const u32 var7f1b4da4[] = {0x7f116794};
const u32 var7f1b4da8[] = {0x7f11679c};
const u32 var7f1b4dac[] = {0x7f116794};
const u32 var7f1b4db0[] = {0x7f11713c};
const u32 var7f1b4db4[] = {0x7f11713c};
const u32 var7f1b4db8[] = {0x7f11713c};
const u32 var7f1b4dbc[] = {0x7f117108};
const u32 var7f1b4dc0[] = {0x7f11713c};
const u32 var7f1b4dc4[] = {0x7f11713c};
const u32 var7f1b4dc8[] = {0x7f11713c};
const u32 var7f1b4dcc[] = {0x7f117130};
const u32 var7f1b4dd0[] = {0x7f11713c};
const u32 var7f1b4dd4[] = {0x7f11713c};
const u32 var7f1b4dd8[] = {0x7f11713c};
const u32 var7f1b4ddc[] = {0x7f11713c};
const u32 var7f1b4de0[] = {0x7f11713c};
const u32 var7f1b4de4[] = {0x7f11713c};
const u32 var7f1b4de8[] = {0x7f11713c};
const u32 var7f1b4dec[] = {0x7f117118};
const u32 var7f1b4df0[] = {0x7f11713c};
const u32 var7f1b4df4[] = {0x7f11713c};
const u32 var7f1b4df8[] = {0x7f11713c};
const u32 var7f1b4dfc[] = {0x7f11713c};
const u32 var7f1b4e00[] = {0x7f11713c};
const u32 var7f1b4e04[] = {0x7f11713c};
const u32 var7f1b4e08[] = {0x7f11713c};
const u32 var7f1b4e0c[] = {0x7f11713c};
const u32 var7f1b4e10[] = {0x7f11713c};
const u32 var7f1b4e14[] = {0x7f11713c};
const u32 var7f1b4e18[] = {0x7f11713c};
const u32 var7f1b4e1c[] = {0x7f11713c};
const u32 var7f1b4e20[] = {0x7f11713c};
const u32 var7f1b4e24[] = {0x7f11713c};
const u32 var7f1b4e28[] = {0x7f11713c};
const u32 var7f1b4e2c[] = {0x7f117120};
const u32 var7f1b4e30[] = {0x7f11932c};
const u32 var7f1b4e34[] = {0x7f11932c};
const u32 var7f1b4e38[] = {0x7f11932c};
const u32 var7f1b4e3c[] = {0x7f11932c};
const u32 var7f1b4e40[] = {0x7f11932c};
const u32 var7f1b4e44[] = {0x7f119334};
const u32 var7f1b4e48[] = {0x7f119334};
const u32 var7f1b4e4c[] = {0x7f119334};
const u32 var7f1b4e50[] = {0x7f119314};
const u32 var7f1b4e54[] = {0x7f119334};
const u32 var7f1b4e58[] = {0x7f119334};
const u32 var7f1b4e5c[] = {0x7f119334};
const u32 var7f1b4e60[] = {0x7f119334};
const u32 var7f1b4e64[] = {0x7f119334};
const u32 var7f1b4e68[] = {0x7f11931c};
const u32 var7f1b4e6c[] = {0x7f119324};
const u32 var7f1b4e70[] = {0x7f119360};
const u32 var7f1b4e74[] = {0x7f119360};
const u32 var7f1b4e78[] = {0x7f119360};
const u32 var7f1b4e7c[] = {0x7f119360};
const u32 var7f1b4e80[] = {0x7f119360};
const u32 var7f1b4e84[] = {0x7f119360};
const u32 var7f1b4e88[] = {0x7f119360};
const u32 var7f1b4e8c[] = {0x7f119360};
const u32 var7f1b4e90[] = {0x7f119360};
const u32 var7f1b4e94[] = {0x7f119360};
const u32 var7f1b4e98[] = {0x7f119360};
const u32 var7f1b4e9c[] = {0x7f11c3e0};
const u32 var7f1b4ea0[] = {0x7f11c4ec};
const u32 var7f1b4ea4[] = {0x7f11c468};
const u32 var7f1b4ea8[] = {0x7f11c4ec};
const u32 var7f1b4eac[] = {0x7f11c4ec};
const u32 var7f1b4eb0[] = {0x7f11c4ec};
const u32 var7f1b4eb4[] = {0x7f11c4ac};
const u32 var7f1b4eb8[] = {0x7f11c4ac};
const u32 var7f1b4ebc[] = {0x7f11c4ec};
const u32 var7f1b4ec0[] = {0x7f11c468};
const u32 var7f1b4ec4[] = {0x7f11c424};
const u32 var7f1b4ec8[] = {0x7f11c540};
const u32 var7f1b4ecc[] = {0x7f11c540};
const u32 var7f1b4ed0[] = {0x7f11c540};
const u32 var7f1b4ed4[] = {0x7f11c540};
const u32 var7f1b4ed8[] = {0x7f11c540};
const u32 var7f1b4edc[] = {0x7f11c540};
const u32 var7f1b4ee0[] = {0x7f11c540};
const u32 var7f1b4ee4[] = {0x7f11c540};
const u32 var7f1b4ee8[] = {0x7f11c540};
const u32 var7f1b4eec[] = {0x7f11c540};
const u32 var7f1b4ef0[] = {0x7f11c540};
const u32 var7f1b4ef4[] = {0x7f11c540};
const u32 var7f1b4ef8[] = {0x7f11c540};
const u32 var7f1b4efc[] = {0x7f11c540};
const u32 var7f1b4f00[] = {0x7f11c540};
const u32 var7f1b4f04[] = {0x7f11c540};
const u32 var7f1b4f08[] = {0x7f11c540};
const u32 var7f1b4f0c[] = {0x7f11c540};
const u32 var7f1b4f10[] = {0x7f11c73c};
const u32 var7f1b4f14[] = {0x7f11c73c};
const u32 var7f1b4f18[] = {0x7f11c73c};
const u32 var7f1b4f1c[] = {0x7f11c73c};
const u32 var7f1b4f20[] = {0x7f11c73c};
const u32 var7f1b4f24[] = {0x7f11c9e4};
const u32 var7f1b4f28[] = {0x7f11c9e4};
const u32 var7f1b4f2c[] = {0x7f11c9e4};
const u32 var7f1b4f30[] = {0x7f11c9e4};
const u32 var7f1b4f34[] = {0x7f11c9e4};
const u32 var7f1b4f38[] = {0x7f11cbc0};
const u32 var7f1b4f3c[] = {0x7f11cbc0};
const u32 var7f1b4f40[] = {0x7f11cbc0};
const u32 var7f1b4f44[] = {0x7f11cbc0};
const u32 var7f1b4f48[] = {0x7f11cbc0};
const u32 var7f1b4f4c[] = {0x7f11cbc0};
const u32 var7f1b4f50[] = {0x7f11cbc0};
const u32 var7f1b4f54[] = {0x7f11cbc0};
const u32 var7f1b4f58[] = {0x7f11cbc0};
const u32 var7f1b4f5c[] = {0x7f11cbc0};
const u32 var7f1b4f60[] = {0x7f11cbc0};
const u32 var7f1b4f64[] = {0x7f11cbc0};
const u32 var7f1b4f68[] = {0x7f11cbc0};
const u32 var7f1b4f6c[] = {0x7f11e34c};
const u32 var7f1b4f70[] = {0x7f11dffc};
const u32 var7f1b4f74[] = {0x7f11e048};
const u32 var7f1b4f78[] = {0x7f11e07c};
const u32 var7f1b4f7c[] = {0x7f11e0e8};
const u32 var7f1b4f80[] = {0x7f11e118};
const u32 var7f1b4f84[] = {0x7f11e138};
const u32 var7f1b4f88[] = {0x7f11e0c0};
const u32 var7f1b4f8c[] = {0x7f11e160};
const u32 var7f1b4f90[] = {0x7f11e178};
const u32 var7f1b4f94[] = {0x7f11e188};
const u32 var7f1b4f98[] = {0x7f11e34c};
const u32 var7f1b4f9c[] = {0x7f11e1ac};
const u32 var7f1b4fa0[] = {0x7f11e34c};
const u32 var7f1b4fa4[] = {0x7f11e24c};
const u32 var7f1b4fa8[] = {0x7f11e1b8};
const u32 var7f1b4fac[] = {0x7f11e2ac};
const u32 var7f1b4fb0[] = {0x7f11e34c};
const u32 var7f1b4fb4[] = {0x7f11e34c};
const u32 var7f1b4fb8[] = {0x7f11e34c};
const u32 var7f1b4fbc[] = {0x7f11e34c};
const u32 var7f1b4fc0[] = {0x7f11e30c};
const u32 var7f1b4fc4[] = {0x7f11e330};
const u32 var7f1b4fc8[] = {0x7f11e34c};
const u32 var7f1b4fcc[] = {0x7f11e194};
const u32 var7f1b4fd0[] = {0x7f11e1a0};
const u32 var7f1b4fd4[] = {0x7f11e218};
const u32 var7f1b4fd8[] = {0x7f11e240};
const u32 var7f1b4fdc[] = {0x00000000};

GLOBAL_ASM(
glabel padUnpack
/*  f115ab0:	3c0e800a */ 	lui	$t6,0x800a
/*  f115ab4:	8dce2354 */ 	lw	$t6,0x2354($t6)
/*  f115ab8:	00047840 */ 	sll	$t7,$a0,0x1
/*  f115abc:	3c19800a */ 	lui	$t9,0x800a
/*  f115ac0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f115ac4:	97020000 */ 	lhu	$v0,0x0($t8)
/*  f115ac8:	8f39d04c */ 	lw	$t9,-0x2fb4($t9)
/*  f115acc:	00a03825 */ 	or	$a3,$a1,$zero
/*  f115ad0:	30e80040 */ 	andi	$t0,$a3,0x40
/*  f115ad4:	03221821 */ 	addu	$v1,$t9,$v0
/*  f115ad8:	11000005 */ 	beqz	$t0,.L0f115af0
/*  f115adc:	00602825 */ 	or	$a1,$v1,$zero
/*  f115ae0:	8c690000 */ 	lw	$t1,0x0($v1)
/*  f115ae4:	00095480 */ 	sll	$t2,$t1,0x12
/*  f115ae8:	000a5d83 */ 	sra	$t3,$t2,0x16
/*  f115aec:	accb0048 */ 	sw	$t3,0x48($a2)
.L0f115af0:
/*  f115af0:	30ec0100 */ 	andi	$t4,$a3,0x100
/*  f115af4:	11800004 */ 	beqz	$t4,.L0f115b08
/*  f115af8:	30f90002 */ 	andi	$t9,$a3,0x2
/*  f115afc:	8c6d0000 */ 	lw	$t5,0x0($v1)
/*  f115b00:	31ae000f */ 	andi	$t6,$t5,0xf
/*  f115b04:	a0ce0050 */ 	sb	$t6,0x50($a2)
.L0f115b08:
/*  f115b08:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115b0c:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f115b10:	30ec0002 */ 	andi	$t4,$a3,0x2
/*  f115b14:	00027b82 */ 	srl	$t7,$v0,0xe
/*  f115b18:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f115b1c:	13000017 */ 	beqz	$t8,.L0f115b7c
/*  f115b20:	01e01025 */ 	or	$v0,$t7,$zero
/*  f115b24:	13200013 */ 	beqz	$t9,.L0f115b74
/*  f115b28:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115b2c:	84680000 */ 	lh	$t0,0x0($v1)
/*  f115b30:	44882000 */ 	mtc1	$t0,$f4
/*  f115b34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115b38:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f115b3c:	e4c60000 */ 	swc1	$f6,0x0($a2)
/*  f115b40:	84690002 */ 	lh	$t1,0x2($v1)
/*  f115b44:	44894000 */ 	mtc1	$t1,$f8
/*  f115b48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115b4c:	468042a0 */ 	cvt.s.w	$f10,$f8
/*  f115b50:	e4ca0004 */ 	swc1	$f10,0x4($a2)
/*  f115b54:	846a0004 */ 	lh	$t2,0x4($v1)
/*  f115b58:	448a2000 */ 	mtc1	$t2,$f4
/*  f115b5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115b60:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f115b64:	e4c60008 */ 	swc1	$f6,0x8($a2)
/*  f115b68:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115b6c:	00025b82 */ 	srl	$t3,$v0,0xe
/*  f115b70:	01601025 */ 	or	$v0,$t3,$zero
.L0f115b74:
/*  f115b74:	1000000d */ 	beqz	$zero,.L0f115bac
/*  f115b78:	24630008 */ 	addiu	$v1,$v1,0x8
.L0f115b7c:
/*  f115b7c:	5180000b */ 	beqzl	$t4,.L0f115bac
/*  f115b80:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f115b84:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*  f115b88:	e4c80000 */ 	swc1	$f8,0x0($a2)
/*  f115b8c:	c46a0004 */ 	lwc1	$f10,0x4($v1)
/*  f115b90:	e4ca0004 */ 	swc1	$f10,0x4($a2)
/*  f115b94:	c4640008 */ 	lwc1	$f4,0x8($v1)
/*  f115b98:	e4c40008 */ 	swc1	$f4,0x8($a2)
/*  f115b9c:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115ba0:	00026b82 */ 	srl	$t5,$v0,0xe
/*  f115ba4:	01a01025 */ 	or	$v0,$t5,$zero
/*  f115ba8:	2463000c */ 	addiu	$v1,$v1,0xc
.L0f115bac:
/*  f115bac:	304e000e */ 	andi	$t6,$v0,0xe
/*  f115bb0:	11c00049 */ 	beqz	$t6,.L0f115cd8
/*  f115bb4:	30e90018 */ 	andi	$t1,$a3,0x18
/*  f115bb8:	30ef0018 */ 	andi	$t7,$a3,0x18
/*  f115bbc:	11e00043 */ 	beqz	$t7,.L0f115ccc
/*  f115bc0:	30580002 */ 	andi	$t8,$v0,0x2
/*  f115bc4:	13000013 */ 	beqz	$t8,.L0f115c14
/*  f115bc8:	30490004 */ 	andi	$t1,$v0,0x4
/*  f115bcc:	30590010 */ 	andi	$t9,$v0,0x10
/*  f115bd0:	44800000 */ 	mtc1	$zero,$f0
/*  f115bd4:	13200005 */ 	beqz	$t9,.L0f115bec
/*  f115bd8:	3c013f80 */ 	lui	$at,0x3f80
/*  f115bdc:	3c01bf80 */ 	lui	$at,0xbf80
/*  f115be0:	44813000 */ 	mtc1	$at,$f6
/*  f115be4:	10000004 */ 	beqz	$zero,.L0f115bf8
/*  f115be8:	e4c60018 */ 	swc1	$f6,0x18($a2)
.L0f115bec:
/*  f115bec:	44814000 */ 	mtc1	$at,$f8
/*  f115bf0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115bf4:	e4c80018 */ 	swc1	$f8,0x18($a2)
.L0f115bf8:
/*  f115bf8:	e4c0001c */ 	swc1	$f0,0x1c($a2)
/*  f115bfc:	e4c00020 */ 	swc1	$f0,0x20($a2)
/*  f115c00:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115c04:	44800000 */ 	mtc1	$zero,$f0
/*  f115c08:	00024382 */ 	srl	$t0,$v0,0xe
/*  f115c0c:	1000003f */ 	beqz	$zero,.L0f115d0c
/*  f115c10:	01001025 */ 	or	$v0,$t0,$zero
.L0f115c14:
/*  f115c14:	51200017 */ 	beqzl	$t1,.L0f115c74
/*  f115c18:	44800000 */ 	mtc1	$zero,$f0
/*  f115c1c:	44800000 */ 	mtc1	$zero,$f0
/*  f115c20:	3c013f80 */ 	lui	$at,0x3f80
/*  f115c24:	e4c00018 */ 	swc1	$f0,0x18($a2)
/*  f115c28:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f115c2c:	000a5b82 */ 	srl	$t3,$t2,0xe
/*  f115c30:	316c0010 */ 	andi	$t4,$t3,0x10
/*  f115c34:	51800006 */ 	beqzl	$t4,.L0f115c50
/*  f115c38:	44812000 */ 	mtc1	$at,$f4
/*  f115c3c:	3c01bf80 */ 	lui	$at,0xbf80
/*  f115c40:	44815000 */ 	mtc1	$at,$f10
/*  f115c44:	10000004 */ 	beqz	$zero,.L0f115c58
/*  f115c48:	e4ca001c */ 	swc1	$f10,0x1c($a2)
/*  f115c4c:	44812000 */ 	mtc1	$at,$f4
.L0f115c50:
/*  f115c50:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115c54:	e4c4001c */ 	swc1	$f4,0x1c($a2)
.L0f115c58:
/*  f115c58:	e4c00020 */ 	swc1	$f0,0x20($a2)
/*  f115c5c:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115c60:	44800000 */ 	mtc1	$zero,$f0
/*  f115c64:	00026b82 */ 	srl	$t5,$v0,0xe
/*  f115c68:	10000028 */ 	beqz	$zero,.L0f115d0c
/*  f115c6c:	01a01025 */ 	or	$v0,$t5,$zero
/*  f115c70:	44800000 */ 	mtc1	$zero,$f0
.L0f115c74:
/*  f115c74:	3c013f80 */ 	lui	$at,0x3f80
/*  f115c78:	e4c00018 */ 	swc1	$f0,0x18($a2)
/*  f115c7c:	e4c0001c */ 	swc1	$f0,0x1c($a2)
/*  f115c80:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f115c84:	000e7b82 */ 	srl	$t7,$t6,0xe
/*  f115c88:	31f80010 */ 	andi	$t8,$t7,0x10
/*  f115c8c:	5300000a */ 	beqzl	$t8,.L0f115cb8
/*  f115c90:	44814000 */ 	mtc1	$at,$f8
/*  f115c94:	3c01bf80 */ 	lui	$at,0xbf80
/*  f115c98:	44813000 */ 	mtc1	$at,$f6
/*  f115c9c:	44800000 */ 	mtc1	$zero,$f0
/*  f115ca0:	e4c60020 */ 	swc1	$f6,0x20($a2)
/*  f115ca4:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115ca8:	0002cb82 */ 	srl	$t9,$v0,0xe
/*  f115cac:	10000017 */ 	beqz	$zero,.L0f115d0c
/*  f115cb0:	03201025 */ 	or	$v0,$t9,$zero
/*  f115cb4:	44814000 */ 	mtc1	$at,$f8
.L0f115cb8:
/*  f115cb8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115cbc:	e4c80020 */ 	swc1	$f8,0x20($a2)
/*  f115cc0:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115cc4:	00024382 */ 	srl	$t0,$v0,0xe
/*  f115cc8:	01001025 */ 	or	$v0,$t0,$zero
.L0f115ccc:
/*  f115ccc:	44800000 */ 	mtc1	$zero,$f0
/*  f115cd0:	1000000f */ 	beqz	$zero,.L0f115d10
/*  f115cd4:	304b00e0 */ 	andi	$t3,$v0,0xe0
.L0f115cd8:
/*  f115cd8:	5120000b */ 	beqzl	$t1,.L0f115d08
/*  f115cdc:	44800000 */ 	mtc1	$zero,$f0
/*  f115ce0:	c46a0000 */ 	lwc1	$f10,0x0($v1)
/*  f115ce4:	e4ca0018 */ 	swc1	$f10,0x18($a2)
/*  f115ce8:	c4640004 */ 	lwc1	$f4,0x4($v1)
/*  f115cec:	e4c4001c */ 	swc1	$f4,0x1c($a2)
/*  f115cf0:	c4660008 */ 	lwc1	$f6,0x8($v1)
/*  f115cf4:	e4c60020 */ 	swc1	$f6,0x20($a2)
/*  f115cf8:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115cfc:	00025382 */ 	srl	$t2,$v0,0xe
/*  f115d00:	01401025 */ 	or	$v0,$t2,$zero
/*  f115d04:	44800000 */ 	mtc1	$zero,$f0
.L0f115d08:
/*  f115d08:	2463000c */ 	addiu	$v1,$v1,0xc
.L0f115d0c:
/*  f115d0c:	304b00e0 */ 	andi	$t3,$v0,0xe0
.L0f115d10:
/*  f115d10:	11600034 */ 	beqz	$t3,.L0f115de4
/*  f115d14:	30ec0014 */ 	andi	$t4,$a3,0x14
/*  f115d18:	30ec0014 */ 	andi	$t4,$a3,0x14
/*  f115d1c:	1180003a */ 	beqz	$t4,.L0f115e08
/*  f115d20:	304d0020 */ 	andi	$t5,$v0,0x20
/*  f115d24:	11a0000e */ 	beqz	$t5,.L0f115d60
/*  f115d28:	304f0040 */ 	andi	$t7,$v0,0x40
/*  f115d2c:	304e0100 */ 	andi	$t6,$v0,0x100
/*  f115d30:	11c00005 */ 	beqz	$t6,.L0f115d48
/*  f115d34:	3c013f80 */ 	lui	$at,0x3f80
/*  f115d38:	3c01bf80 */ 	lui	$at,0xbf80
/*  f115d3c:	44814000 */ 	mtc1	$at,$f8
/*  f115d40:	10000004 */ 	beqz	$zero,.L0f115d54
/*  f115d44:	e4c8000c */ 	swc1	$f8,0xc($a2)
.L0f115d48:
/*  f115d48:	44815000 */ 	mtc1	$at,$f10
/*  f115d4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115d50:	e4ca000c */ 	swc1	$f10,0xc($a2)
.L0f115d54:
/*  f115d54:	e4c00010 */ 	swc1	$f0,0x10($a2)
/*  f115d58:	1000002b */ 	beqz	$zero,.L0f115e08
/*  f115d5c:	e4c00014 */ 	swc1	$f0,0x14($a2)
.L0f115d60:
/*  f115d60:	51e00012 */ 	beqzl	$t7,.L0f115dac
/*  f115d64:	e4c0000c */ 	swc1	$f0,0xc($a2)
/*  f115d68:	e4c0000c */ 	swc1	$f0,0xc($a2)
/*  f115d6c:	8cb80000 */ 	lw	$t8,0x0($a1)
/*  f115d70:	3c013f80 */ 	lui	$at,0x3f80
/*  f115d74:	0018cb82 */ 	srl	$t9,$t8,0xe
/*  f115d78:	33280100 */ 	andi	$t0,$t9,0x100
/*  f115d7c:	51000006 */ 	beqzl	$t0,.L0f115d98
/*  f115d80:	44813000 */ 	mtc1	$at,$f6
/*  f115d84:	3c01bf80 */ 	lui	$at,0xbf80
/*  f115d88:	44812000 */ 	mtc1	$at,$f4
/*  f115d8c:	10000004 */ 	beqz	$zero,.L0f115da0
/*  f115d90:	e4c40010 */ 	swc1	$f4,0x10($a2)
/*  f115d94:	44813000 */ 	mtc1	$at,$f6
.L0f115d98:
/*  f115d98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115d9c:	e4c60010 */ 	swc1	$f6,0x10($a2)
.L0f115da0:
/*  f115da0:	10000019 */ 	beqz	$zero,.L0f115e08
/*  f115da4:	e4c00014 */ 	swc1	$f0,0x14($a2)
/*  f115da8:	e4c0000c */ 	swc1	$f0,0xc($a2)
.L0f115dac:
/*  f115dac:	e4c00010 */ 	swc1	$f0,0x10($a2)
/*  f115db0:	8ca90000 */ 	lw	$t1,0x0($a1)
/*  f115db4:	3c013f80 */ 	lui	$at,0x3f80
/*  f115db8:	00095382 */ 	srl	$t2,$t1,0xe
/*  f115dbc:	314b0100 */ 	andi	$t3,$t2,0x100
/*  f115dc0:	51600006 */ 	beqzl	$t3,.L0f115ddc
/*  f115dc4:	44815000 */ 	mtc1	$at,$f10
/*  f115dc8:	3c01bf80 */ 	lui	$at,0xbf80
/*  f115dcc:	44814000 */ 	mtc1	$at,$f8
/*  f115dd0:	1000000d */ 	beqz	$zero,.L0f115e08
/*  f115dd4:	e4c80014 */ 	swc1	$f8,0x14($a2)
/*  f115dd8:	44815000 */ 	mtc1	$at,$f10
.L0f115ddc:
/*  f115ddc:	1000000a */ 	beqz	$zero,.L0f115e08
/*  f115de0:	e4ca0014 */ 	swc1	$f10,0x14($a2)
.L0f115de4:
/*  f115de4:	51800008 */ 	beqzl	$t4,.L0f115e08
/*  f115de8:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f115dec:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f115df0:	e4c4000c */ 	swc1	$f4,0xc($a2)
/*  f115df4:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f115df8:	e4c60010 */ 	swc1	$f6,0x10($a2)
/*  f115dfc:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f115e00:	e4c80014 */ 	swc1	$f8,0x14($a2)
/*  f115e04:	2463000c */ 	addiu	$v1,$v1,0xc
.L0f115e08:
/*  f115e08:	30ed0010 */ 	andi	$t5,$a3,0x10
/*  f115e0c:	11a00014 */ 	beqz	$t5,.L0f115e60
/*  f115e10:	30e90080 */ 	andi	$t1,$a3,0x80
/*  f115e14:	c4c0001c */ 	lwc1	$f0,0x1c($a2)
/*  f115e18:	c4c20014 */ 	lwc1	$f2,0x14($a2)
/*  f115e1c:	c4cc0010 */ 	lwc1	$f12,0x10($a2)
/*  f115e20:	c4ce0020 */ 	lwc1	$f14,0x20($a2)
/*  f115e24:	46020282 */ 	mul.s	$f10,$f0,$f2
/*  f115e28:	c4d0000c */ 	lwc1	$f16,0xc($a2)
/*  f115e2c:	c4d20018 */ 	lwc1	$f18,0x18($a2)
/*  f115e30:	460e6102 */ 	mul.s	$f4,$f12,$f14
/*  f115e34:	46045181 */ 	sub.s	$f6,$f10,$f4
/*  f115e38:	46107202 */ 	mul.s	$f8,$f14,$f16
/*  f115e3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115e40:	46121282 */ 	mul.s	$f10,$f2,$f18
/*  f115e44:	e4c60024 */ 	swc1	$f6,0x24($a2)
/*  f115e48:	460c9182 */ 	mul.s	$f6,$f18,$f12
/*  f115e4c:	460a4101 */ 	sub.s	$f4,$f8,$f10
/*  f115e50:	46008202 */ 	mul.s	$f8,$f16,$f0
/*  f115e54:	e4c40028 */ 	swc1	$f4,0x28($a2)
/*  f115e58:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f115e5c:	e4ca002c */ 	swc1	$f10,0x2c($a2)
.L0f115e60:
/*  f115e60:	8cae0000 */ 	lw	$t6,0x0($a1)
/*  f115e64:	30f90020 */ 	andi	$t9,$a3,0x20
/*  f115e68:	30e80020 */ 	andi	$t0,$a3,0x20
/*  f115e6c:	000e7b82 */ 	srl	$t7,$t6,0xe
/*  f115e70:	31f80200 */ 	andi	$t8,$t7,0x200
/*  f115e74:	13000010 */ 	beqz	$t8,.L0f115eb8
/*  f115e78:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115e7c:	13200019 */ 	beqz	$t9,.L0f115ee4
/*  f115e80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115e84:	c4640000 */ 	lwc1	$f4,0x0($v1)
/*  f115e88:	e4c40030 */ 	swc1	$f4,0x30($a2)
/*  f115e8c:	c4660004 */ 	lwc1	$f6,0x4($v1)
/*  f115e90:	e4c60034 */ 	swc1	$f6,0x34($a2)
/*  f115e94:	c4680008 */ 	lwc1	$f8,0x8($v1)
/*  f115e98:	e4c80038 */ 	swc1	$f8,0x38($a2)
/*  f115e9c:	c46a000c */ 	lwc1	$f10,0xc($v1)
/*  f115ea0:	e4ca003c */ 	swc1	$f10,0x3c($a2)
/*  f115ea4:	c4640010 */ 	lwc1	$f4,0x10($v1)
/*  f115ea8:	e4c40040 */ 	swc1	$f4,0x40($a2)
/*  f115eac:	c4660014 */ 	lwc1	$f6,0x14($v1)
/*  f115eb0:	1000000c */ 	beqz	$zero,.L0f115ee4
/*  f115eb4:	e4c60044 */ 	swc1	$f6,0x44($a2)
.L0f115eb8:
/*  f115eb8:	1100000a */ 	beqz	$t0,.L0f115ee4
/*  f115ebc:	3c01c2c8 */ 	lui	$at,0xc2c8
/*  f115ec0:	44810000 */ 	mtc1	$at,$f0
/*  f115ec4:	3c0142c8 */ 	lui	$at,0x42c8
/*  f115ec8:	44811000 */ 	mtc1	$at,$f2
/*  f115ecc:	e4c00030 */ 	swc1	$f0,0x30($a2)
/*  f115ed0:	e4c00038 */ 	swc1	$f0,0x38($a2)
/*  f115ed4:	e4c00040 */ 	swc1	$f0,0x40($a2)
/*  f115ed8:	e4c20034 */ 	swc1	$f2,0x34($a2)
/*  f115edc:	e4c2003c */ 	swc1	$f2,0x3c($a2)
/*  f115ee0:	e4c20044 */ 	swc1	$f2,0x44($a2)
.L0f115ee4:
/*  f115ee4:	11200004 */ 	beqz	$t1,.L0f115ef8
/*  f115ee8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f115eec:	8caa0000 */ 	lw	$t2,0x0($a1)
/*  f115ef0:	000a5b82 */ 	srl	$t3,$t2,0xe
/*  f115ef4:	accb004c */ 	sw	$t3,0x4c($a2)
.L0f115ef8:
/*  f115ef8:	03e00008 */ 	jr	$ra
/*  f115efc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f115f00
/*  f115f00:	3c0e800a */ 	lui	$t6,0x800a
/*  f115f04:	8dce2354 */ 	lw	$t6,0x2354($t6)
/*  f115f08:	00047840 */ 	sll	$t7,$a0,0x1
/*  f115f0c:	3c19800a */ 	lui	$t9,0x800a
/*  f115f10:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f115f14:	97030000 */ 	lhu	$v1,0x0($t8)
/*  f115f18:	8f39d04c */ 	lw	$t9,-0x2fb4($t9)
/*  f115f1c:	03232821 */ 	addu	$a1,$t9,$v1
/*  f115f20:	8ca20000 */ 	lw	$v0,0x0($a1)
/*  f115f24:	00024382 */ 	srl	$t0,$v0,0xe
/*  f115f28:	31090200 */ 	andi	$t1,$t0,0x200
/*  f115f2c:	03e00008 */ 	jr	$ra
/*  f115f30:	0009102b */ 	sltu	$v0,$zero,$t1
);

GLOBAL_ASM(
glabel func0f115f34
/*  f115f34:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f115f38:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f115f3c:	00a03825 */ 	or	$a3,$a1,$zero
/*  f115f40:	afa70074 */ 	sw	$a3,0x74($sp)
/*  f115f44:	2405003e */ 	addiu	$a1,$zero,0x3e
/*  f115f48:	0fc456ac */ 	jal	padUnpack
/*  f115f4c:	27a6001c */ 	addiu	$a2,$sp,0x1c
/*  f115f50:	c7a4004c */ 	lwc1	$f4,0x4c($sp)
/*  f115f54:	c7a60050 */ 	lwc1	$f6,0x50($sp)
/*  f115f58:	c7aa0040 */ 	lwc1	$f10,0x40($sp)
/*  f115f5c:	c7b20054 */ 	lwc1	$f18,0x54($sp)
/*  f115f60:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f115f64:	c7a40058 */ 	lwc1	$f4,0x58($sp)
/*  f115f68:	3c013f00 */ 	lui	$at,0x3f00
/*  f115f6c:	44810000 */ 	mtc1	$at,$f0
/*  f115f70:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f115f74:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f115f78:	c7a80034 */ 	lwc1	$f8,0x34($sp)
/*  f115f7c:	c7a4005c */ 	lwc1	$f4,0x5c($sp)
/*  f115f80:	8fa70074 */ 	lw	$a3,0x74($sp)
/*  f115f84:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f115f88:	c7a60060 */ 	lwc1	$f6,0x60($sp)
/*  f115f8c:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f115f90:	460a8480 */ 	add.s	$f18,$f16,$f10
/*  f115f94:	c7b00028 */ 	lwc1	$f16,0x28($sp)
/*  f115f98:	46088282 */ 	mul.s	$f10,$f16,$f8
/*  f115f9c:	c7b0001c */ 	lwc1	$f16,0x1c($sp)
/*  f115fa0:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f115fa4:	46002182 */ 	mul.s	$f6,$f4,$f0
/*  f115fa8:	46103200 */ 	add.s	$f8,$f6,$f16
/*  f115fac:	e4e80000 */ 	swc1	$f8,0x0($a3)
/*  f115fb0:	c7b20050 */ 	lwc1	$f18,0x50($sp)
/*  f115fb4:	c7aa004c */ 	lwc1	$f10,0x4c($sp)
/*  f115fb8:	c7a80054 */ 	lwc1	$f8,0x54($sp)
/*  f115fbc:	c7a60044 */ 	lwc1	$f6,0x44($sp)
/*  f115fc0:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f115fc4:	c7aa0058 */ 	lwc1	$f10,0x58($sp)
/*  f115fc8:	46062402 */ 	mul.s	$f16,$f4,$f6
/*  f115fcc:	460a4480 */ 	add.s	$f18,$f8,$f10
/*  f115fd0:	c7a40038 */ 	lwc1	$f4,0x38($sp)
/*  f115fd4:	c7aa005c */ 	lwc1	$f10,0x5c($sp)
/*  f115fd8:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f115fdc:	c7b20060 */ 	lwc1	$f18,0x60($sp)
/*  f115fe0:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f115fe4:	46068200 */ 	add.s	$f8,$f16,$f6
/*  f115fe8:	c7b0002c */ 	lwc1	$f16,0x2c($sp)
/*  f115fec:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f115ff0:	c7b00020 */ 	lwc1	$f16,0x20($sp)
/*  f115ff4:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f115ff8:	46005482 */ 	mul.s	$f18,$f10,$f0
/*  f115ffc:	46109100 */ 	add.s	$f4,$f18,$f16
/*  f116000:	e4e40004 */ 	swc1	$f4,0x4($a3)
/*  f116004:	c7a80050 */ 	lwc1	$f8,0x50($sp)
/*  f116008:	c7a6004c */ 	lwc1	$f6,0x4c($sp)
/*  f11600c:	c7a40054 */ 	lwc1	$f4,0x54($sp)
/*  f116010:	c7b20048 */ 	lwc1	$f18,0x48($sp)
/*  f116014:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f116018:	c7a60058 */ 	lwc1	$f6,0x58($sp)
/*  f11601c:	46125402 */ 	mul.s	$f16,$f10,$f18
/*  f116020:	46062200 */ 	add.s	$f8,$f4,$f6
/*  f116024:	c7aa003c */ 	lwc1	$f10,0x3c($sp)
/*  f116028:	c7a6005c */ 	lwc1	$f6,0x5c($sp)
/*  f11602c:	460a4482 */ 	mul.s	$f18,$f8,$f10
/*  f116030:	c7a80060 */ 	lwc1	$f8,0x60($sp)
/*  f116034:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f116038:	46128100 */ 	add.s	$f4,$f16,$f18
/*  f11603c:	c7b00030 */ 	lwc1	$f16,0x30($sp)
/*  f116040:	460a8482 */ 	mul.s	$f18,$f16,$f10
/*  f116044:	c7b00024 */ 	lwc1	$f16,0x24($sp)
/*  f116048:	46049180 */ 	add.s	$f6,$f18,$f4
/*  f11604c:	46003202 */ 	mul.s	$f8,$f6,$f0
/*  f116050:	46104280 */ 	add.s	$f10,$f8,$f16
/*  f116054:	e4ea0008 */ 	swc1	$f10,0x8($a3)
/*  f116058:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11605c:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f116060:	03e00008 */ 	jr	$ra
/*  f116064:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116068
/*  f116068:	3c0e800a */ 	lui	$t6,0x800a
/*  f11606c:	8dce2354 */ 	lw	$t6,0x2354($t6)
/*  f116070:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f116074:	00047840 */ 	sll	$t7,$a0,0x1
/*  f116078:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11607c:	3c19800a */ 	lui	$t9,0x800a
/*  f116080:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f116084:	97060000 */ 	lhu	$a2,0x0($t8)
/*  f116088:	8f39d04c */ 	lw	$t9,-0x2fb4($t9)
/*  f11608c:	03261021 */ 	addu	$v0,$t9,$a2
/*  f116090:	00403825 */ 	or	$a3,$v0,$zero
/*  f116094:	8ce50000 */ 	lw	$a1,0x0($a3)
/*  f116098:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f11609c:	00051b82 */ 	srl	$v1,$a1,0xe
/*  f1160a0:	30680001 */ 	andi	$t0,$v1,0x1
/*  f1160a4:	11000003 */ 	beqz	$t0,.L0f1160b4
/*  f1160a8:	3069000e */ 	andi	$t1,$v1,0xe
/*  f1160ac:	10000002 */ 	beqz	$zero,.L0f1160b8
/*  f1160b0:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f1160b4:
/*  f1160b4:	2442000c */ 	addiu	$v0,$v0,0xc
.L0f1160b8:
/*  f1160b8:	5520001d */ 	bnezl	$t1,.L0f116130
/*  f1160bc:	306a00e0 */ 	andi	$t2,$v1,0xe0
/*  f1160c0:	c4400008 */ 	lwc1	$f0,0x8($v0)
/*  f1160c4:	c4420000 */ 	lwc1	$f2,0x0($v0)
/*  f1160c8:	44802000 */ 	mtc1	$zero,$f4
/*  f1160cc:	46000182 */ 	mul.s	$f6,$f0,$f0
/*  f1160d0:	e4440004 */ 	swc1	$f4,0x4($v0)
/*  f1160d4:	46021202 */ 	mul.s	$f8,$f2,$f2
/*  f1160d8:	afa70024 */ 	sw	$a3,0x24($sp)
/*  f1160dc:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f1160e0:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f1160e4:	0c012974 */ 	jal	sqrtf
/*  f1160e8:	46083300 */ 	add.s	$f12,$f6,$f8
/*  f1160ec:	3c013f80 */ 	lui	$at,0x3f80
/*  f1160f0:	44815000 */ 	mtc1	$at,$f10
/*  f1160f4:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f1160f8:	8fa70024 */ 	lw	$a3,0x24($sp)
/*  f1160fc:	46005083 */ 	div.s	$f2,$f10,$f0
/*  f116100:	c4900000 */ 	lwc1	$f16,0x0($a0)
/*  f116104:	c4840008 */ 	lwc1	$f4,0x8($a0)
/*  f116108:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f11610c:	2442000c */ 	addiu	$v0,$v0,0xc
/*  f116110:	46028482 */ 	mul.s	$f18,$f16,$f2
/*  f116114:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116118:	46022182 */ 	mul.s	$f6,$f4,$f2
/*  f11611c:	e4920000 */ 	swc1	$f18,0x0($a0)
/*  f116120:	e4860008 */ 	swc1	$f6,0x8($a0)
/*  f116124:	8ce50000 */ 	lw	$a1,0x0($a3)
/*  f116128:	00051b82 */ 	srl	$v1,$a1,0xe
/*  f11612c:	306a00e0 */ 	andi	$t2,$v1,0xe0
.L0f116130:
/*  f116130:	1140000d */ 	beqz	$t2,.L0f116168
/*  f116134:	2401fe1f */ 	addiu	$at,$zero,-481
/*  f116138:	00615824 */ 	and	$t3,$v1,$at
/*  f11613c:	01636026 */ 	xor	$t4,$t3,$v1
/*  f116140:	000c6b80 */ 	sll	$t5,$t4,0xe
/*  f116144:	01a57026 */ 	xor	$t6,$t5,$a1
/*  f116148:	000e1b82 */ 	srl	$v1,$t6,0xe
/*  f11614c:	346f0040 */ 	ori	$t7,$v1,0x40
/*  f116150:	01e3c026 */ 	xor	$t8,$t7,$v1
/*  f116154:	0018cb80 */ 	sll	$t9,$t8,0xe
/*  f116158:	acee0000 */ 	sw	$t6,0x0($a3)
/*  f11615c:	032e4026 */ 	xor	$t0,$t9,$t6
/*  f116160:	10000007 */ 	beqz	$zero,.L0f116180
/*  f116164:	ace80000 */ 	sw	$t0,0x0($a3)
.L0f116168:
/*  f116168:	44800000 */ 	mtc1	$zero,$f0
/*  f11616c:	3c013f80 */ 	lui	$at,0x3f80
/*  f116170:	44814000 */ 	mtc1	$at,$f8
/*  f116174:	e4400000 */ 	swc1	$f0,0x0($v0)
/*  f116178:	e4400008 */ 	swc1	$f0,0x8($v0)
/*  f11617c:	e4480004 */ 	swc1	$f8,0x4($v0)
.L0f116180:
/*  f116180:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f116184:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f116188:	03e00008 */ 	jr	$ra
/*  f11618c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116190
/*  f116190:	3c0e800a */ 	lui	$t6,0x800a
/*  f116194:	8dce2354 */ 	lw	$t6,0x2354($t6)
/*  f116198:	00047840 */ 	sll	$t7,$a0,0x1
/*  f11619c:	3c19800a */ 	lui	$t9,0x800a
/*  f1161a0:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f1161a4:	97020000 */ 	lhu	$v0,0x0($t8)
/*  f1161a8:	8f39d04c */ 	lw	$t9,-0x2fb4($t9)
/*  f1161ac:	03221821 */ 	addu	$v1,$t9,$v0
/*  f1161b0:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f1161b4:	00603025 */ 	or	$a2,$v1,$zero
/*  f1161b8:	00084b82 */ 	srl	$t1,$t0,0xe
/*  f1161bc:	312a0200 */ 	andi	$t2,$t1,0x200
/*  f1161c0:	1140001d */ 	beqz	$t2,.L0f116238
/*  f1161c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1161c8:	8cc20000 */ 	lw	$v0,0x0($a2)
/*  f1161cc:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1161d0:	00025b82 */ 	srl	$t3,$v0,0xe
/*  f1161d4:	316c0001 */ 	andi	$t4,$t3,0x1
/*  f1161d8:	11800003 */ 	beqz	$t4,.L0f1161e8
/*  f1161dc:	01601025 */ 	or	$v0,$t3,$zero
/*  f1161e0:	10000002 */ 	beqz	$zero,.L0f1161ec
/*  f1161e4:	24630008 */ 	addiu	$v1,$v1,0x8
.L0f1161e8:
/*  f1161e8:	2463000c */ 	addiu	$v1,$v1,0xc
.L0f1161ec:
/*  f1161ec:	304d000e */ 	andi	$t5,$v0,0xe
/*  f1161f0:	15a00002 */ 	bnez	$t5,.L0f1161fc
/*  f1161f4:	304e00e0 */ 	andi	$t6,$v0,0xe0
/*  f1161f8:	2463000c */ 	addiu	$v1,$v1,0xc
.L0f1161fc:
/*  f1161fc:	55c00003 */ 	bnezl	$t6,.L0f11620c
/*  f116200:	c4a40030 */ 	lwc1	$f4,0x30($a1)
/*  f116204:	2463000c */ 	addiu	$v1,$v1,0xc
/*  f116208:	c4a40030 */ 	lwc1	$f4,0x30($a1)
.L0f11620c:
/*  f11620c:	e4640000 */ 	swc1	$f4,0x0($v1)
/*  f116210:	c4a60034 */ 	lwc1	$f6,0x34($a1)
/*  f116214:	e4660004 */ 	swc1	$f6,0x4($v1)
/*  f116218:	c4a80038 */ 	lwc1	$f8,0x38($a1)
/*  f11621c:	e4680008 */ 	swc1	$f8,0x8($v1)
/*  f116220:	c4aa003c */ 	lwc1	$f10,0x3c($a1)
/*  f116224:	e46a000c */ 	swc1	$f10,0xc($v1)
/*  f116228:	c4b00040 */ 	lwc1	$f16,0x40($a1)
/*  f11622c:	e4700010 */ 	swc1	$f16,0x10($v1)
/*  f116230:	c4b20044 */ 	lwc1	$f18,0x44($a1)
/*  f116234:	e4720014 */ 	swc1	$f18,0x14($v1)
.L0f116238:
/*  f116238:	03e00008 */ 	jr	$ra
/*  f11623c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116240
/*  f116240:	3c0e800a */ 	lui	$t6,0x800a
/*  f116244:	8dce2354 */ 	lw	$t6,0x2354($t6)
/*  f116248:	00047840 */ 	sll	$t7,$a0,0x1
/*  f11624c:	3c19800a */ 	lui	$t9,0x800a
/*  f116250:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f116254:	97020000 */ 	lhu	$v0,0x0($t8)
/*  f116258:	8f39d04c */ 	lw	$t9,-0x2fb4($t9)
/*  f11625c:	03221821 */ 	addu	$v1,$t9,$v0
/*  f116260:	8c660000 */ 	lw	$a2,0x0($v1)
/*  f116264:	00063b82 */ 	srl	$a3,$a2,0xe
/*  f116268:	00e54025 */ 	or	$t0,$a3,$a1
/*  f11626c:	01074826 */ 	xor	$t1,$t0,$a3
/*  f116270:	00095380 */ 	sll	$t2,$t1,0xe
/*  f116274:	01465826 */ 	xor	$t3,$t2,$a2
/*  f116278:	03e00008 */ 	jr	$ra
/*  f11627c:	ac6b0000 */ 	sw	$t3,0x0($v1)
);

GLOBAL_ASM(
glabel func0f116280
/*  f116280:	3c0e800a */ 	lui	$t6,0x800a
/*  f116284:	8dce2354 */ 	lw	$t6,0x2354($t6)
/*  f116288:	00047840 */ 	sll	$t7,$a0,0x1
/*  f11628c:	3c19800a */ 	lui	$t9,0x800a
/*  f116290:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f116294:	97020000 */ 	lhu	$v0,0x0($t8)
/*  f116298:	8f39d04c */ 	lw	$t9,-0x2fb4($t9)
/*  f11629c:	00a04027 */ 	nor	$t0,$a1,$zero
/*  f1162a0:	03221821 */ 	addu	$v1,$t9,$v0
/*  f1162a4:	8c660000 */ 	lw	$a2,0x0($v1)
/*  f1162a8:	00063b82 */ 	srl	$a3,$a2,0xe
/*  f1162ac:	00e84824 */ 	and	$t1,$a3,$t0
/*  f1162b0:	01275026 */ 	xor	$t2,$t1,$a3
/*  f1162b4:	000a5b80 */ 	sll	$t3,$t2,0xe
/*  f1162b8:	01666026 */ 	xor	$t4,$t3,$a2
/*  f1162bc:	03e00008 */ 	jr	$ra
/*  f1162c0:	ac6c0000 */ 	sw	$t4,0x0($v1)
/*  f1162c4:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f1162c8:	03e00008 */ 	jr	$ra
/*  f1162cc:	00801025 */ 	or	$v0,$a0,$zero
);

GLOBAL_ASM(
glabel func0f1162d0
/*  f1162d0:	3c0e800a */ 	lui	$t6,0x800a
/*  f1162d4:	8dce2350 */ 	lw	$t6,0x2350($t6)
/*  f1162d8:	03e00008 */ 	jr	$ra
/*  f1162dc:	8dc20004 */ 	lw	$v0,0x4($t6)
);

GLOBAL_ASM(
glabel func0f1162e0
/*  f1162e0:	3c0e800a */ 	lui	$t6,0x800a
/*  f1162e4:	8dce2350 */ 	lw	$t6,0x2350($t6)
/*  f1162e8:	00a03025 */ 	or	$a2,$a1,$zero
/*  f1162ec:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f1162f0:	008f082a */ 	slt	$at,$a0,$t7
/*  f1162f4:	10200008 */ 	beqz	$at,.L0f116318
/*  f1162f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1162fc:	04800006 */ 	bltz	$a0,.L0f116318
/*  f116300:	3c03800a */ 	lui	$v1,0x800a
/*  f116304:	8c63d038 */ 	lw	$v1,-0x2fc8($v1)
/*  f116308:	3c09800a */ 	lui	$t1,%hi(var800a2360)
/*  f11630c:	25292360 */ 	addiu	$t1,$t1,%lo(var800a2360)
/*  f116310:	14600003 */ 	bnez	$v1,.L0f116320
/*  f116314:	309800ff */ 	andi	$t8,$a0,0xff
.L0f116318:
/*  f116318:	03e00008 */ 	jr	$ra
/*  f11631c:	00001025 */ 	or	$v0,$zero,$zero
.L0f116320:
/*  f116320:	0018c8c0 */ 	sll	$t9,$t8,0x3
/*  f116324:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f116328:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11632c:	00792821 */ 	addu	$a1,$v1,$t9
/*  f116330:	24aa000c */ 	addiu	$t2,$a1,0xc
/*  f116334:	acc50000 */ 	sw	$a1,0x0($a2)
/*  f116338:	acca0004 */ 	sw	$t2,0x4($a2)
/*  f11633c:	8d2b0000 */ 	lw	$t3,0x0($t1)
/*  f116340:	00043840 */ 	sll	$a3,$a0,0x1
/*  f116344:	94ad0018 */ 	lhu	$t5,0x18($a1)
/*  f116348:	01674021 */ 	addu	$t0,$t3,$a3
/*  f11634c:	950c0000 */ 	lhu	$t4,0x0($t0)
/*  f116350:	3c0a800a */ 	lui	$t2,0x800a
/*  f116354:	00045880 */ 	sll	$t3,$a0,0x2
/*  f116358:	018d7025 */ 	or	$t6,$t4,$t5
/*  f11635c:	a50e0000 */ 	sh	$t6,0x0($t0)
/*  f116360:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*  f116364:	240effff */ 	addiu	$t6,$zero,-1
/*  f116368:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11636c:	01e7c021 */ 	addu	$t8,$t7,$a3
/*  f116370:	97190000 */ 	lhu	$t9,0x0($t8)
/*  f116374:	a4d9000c */ 	sh	$t9,0xc($a2)
/*  f116378:	8d4a2364 */ 	lw	$t2,0x2364($t2)
/*  f11637c:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f116380:	8d8d0000 */ 	lw	$t5,0x0($t4)
/*  f116384:	a4ce000a */ 	sh	$t6,0xa($a2)
/*  f116388:	a4cd0008 */ 	sh	$t5,0x8($a2)
/*  f11638c:	03e00008 */ 	jr	$ra
/*  f116390:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116394:	3c02800a */ 	lui	$v0,0x800a
/*  f116398:	03e00008 */ 	jr	$ra
/*  f11639c:	9442236c */ 	lhu	$v0,0x236c($v0)
/*  f1163a0:	3c02800a */ 	lui	$v0,0x800a
/*  f1163a4:	8c422370 */ 	lw	$v0,0x2370($v0)
/*  f1163a8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1163ac:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1163b0:	10400009 */ 	beqz	$v0,.L0f1163d8
/*  f1163b4:	00803025 */ 	or	$a2,$a0,$zero
/*  f1163b8:	04800007 */ 	bltz	$a0,.L0f1163d8
/*  f1163bc:	3c0e800a */ 	lui	$t6,0x800a
/*  f1163c0:	95ce236c */ 	lhu	$t6,0x236c($t6)
/*  f1163c4:	00067840 */ 	sll	$t7,$a2,0x1
/*  f1163c8:	004fc021 */ 	addu	$t8,$v0,$t7
/*  f1163cc:	01c4082a */ 	slt	$at,$t6,$a0
/*  f1163d0:	10200003 */ 	beqz	$at,.L0f1163e0
/*  f1163d4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1163d8:
/*  f1163d8:	10000008 */ 	beqz	$zero,.L0f1163fc
/*  f1163dc:	00001025 */ 	or	$v0,$zero,$zero
.L0f1163e0:
/*  f1163e0:	0fc458b8 */ 	jal	func0f1162e0
/*  f1163e4:	97040000 */ 	lhu	$a0,0x0($t8)
/*  f1163e8:	50400004 */ 	beqzl	$v0,.L0f1163fc
/*  f1163ec:	00001025 */ 	or	$v0,$zero,$zero
/*  f1163f0:	10000002 */ 	beqz	$zero,.L0f1163fc
/*  f1163f4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1163f8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1163fc:
/*  f1163fc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f116400:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f116404:	03e00008 */ 	jr	$ra
/*  f116408:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11640c:	3c03800a */ 	lui	$v1,0x800a
/*  f116410:	8c632370 */ 	lw	$v1,0x2370($v1)
/*  f116414:	10600009 */ 	beqz	$v1,.L0f11643c
/*  f116418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11641c:	04800007 */ 	bltz	$a0,.L0f11643c
/*  f116420:	3c0e800a */ 	lui	$t6,0x800a
/*  f116424:	95ce236c */ 	lhu	$t6,0x236c($t6)
/*  f116428:	00047840 */ 	sll	$t7,$a0,0x1
/*  f11642c:	006fc021 */ 	addu	$t8,$v1,$t7
/*  f116430:	01c4082a */ 	slt	$at,$t6,$a0
/*  f116434:	50200004 */ 	beqzl	$at,.L0f116448
/*  f116438:	97020000 */ 	lhu	$v0,0x0($t8)
.L0f11643c:
/*  f11643c:	03e00008 */ 	jr	$ra
/*  f116440:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f116444:	97020000 */ 	lhu	$v0,0x0($t8)
.L0f116448:
/*  f116448:	03e00008 */ 	jr	$ra
/*  f11644c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116450:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f116454:	03e00008 */ 	jr	$ra
/*  f116458:	00801025 */ 	or	$v0,$a0,$zero
);

GLOBAL_ASM(
glabel func0f11645c
/*  f11645c:	04800007 */ 	bltz	$a0,.L0f11647c
/*  f116460:	3c0e800a */ 	lui	$t6,0x800a
/*  f116464:	8dce2350 */ 	lw	$t6,0x2350($t6)
/*  f116468:	3c18800a */ 	lui	$t8,0x800a
/*  f11646c:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f116470:	01e4082a */ 	slt	$at,$t7,$a0
/*  f116474:	10200003 */ 	beqz	$at,.L0f116484
/*  f116478:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11647c:
/*  f11647c:	03e00008 */ 	jr	$ra
/*  f116480:	00001025 */ 	or	$v0,$zero,$zero
.L0f116484:
/*  f116484:	8f182360 */ 	lw	$t8,0x2360($t8)
/*  f116488:	0004c840 */ 	sll	$t9,$a0,0x1
/*  f11648c:	03194021 */ 	addu	$t0,$t8,$t9
/*  f116490:	95020000 */ 	lhu	$v0,0x0($t0)
/*  f116494:	30490002 */ 	andi	$t1,$v0,0x2
/*  f116498:	01201025 */ 	or	$v0,$t1,$zero
/*  f11649c:	03e00008 */ 	jr	$ra
/*  f1164a0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1164a4
/*  f1164a4:	04800016 */ 	bltz	$a0,.L0f116500
/*  f1164a8:	3c0e800a */ 	lui	$t6,0x800a
/*  f1164ac:	8dce2350 */ 	lw	$t6,0x2350($t6)
/*  f1164b0:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f1164b4:	008f082a */ 	slt	$at,$a0,$t7
/*  f1164b8:	10200011 */ 	beqz	$at,.L0f116500
/*  f1164bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1164c0:	10a00009 */ 	beqz	$a1,.L0f1164e8
/*  f1164c4:	3c0a800a */ 	lui	$t2,0x800a
/*  f1164c8:	3c18800a */ 	lui	$t8,0x800a
/*  f1164cc:	8f182360 */ 	lw	$t8,0x2360($t8)
/*  f1164d0:	0004c840 */ 	sll	$t9,$a0,0x1
/*  f1164d4:	03191021 */ 	addu	$v0,$t8,$t9
/*  f1164d8:	94480000 */ 	lhu	$t0,0x0($v0)
/*  f1164dc:	35090002 */ 	ori	$t1,$t0,0x2
/*  f1164e0:	03e00008 */ 	jr	$ra
/*  f1164e4:	a4490000 */ 	sh	$t1,0x0($v0)
.L0f1164e8:
/*  f1164e8:	8d4a2360 */ 	lw	$t2,0x2360($t2)
/*  f1164ec:	00045840 */ 	sll	$t3,$a0,0x1
/*  f1164f0:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f1164f4:	944c0000 */ 	lhu	$t4,0x0($v0)
/*  f1164f8:	318dfffd */ 	andi	$t5,$t4,0xfffd
/*  f1164fc:	a44d0000 */ 	sh	$t5,0x0($v0)
.L0f116500:
/*  f116500:	03e00008 */ 	jr	$ra
/*  f116504:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116508
/*  f116508:	3c0e800a */ 	lui	$t6,0x800a
/*  f11650c:	8dce2360 */ 	lw	$t6,0x2360($t6)
/*  f116510:	00047840 */ 	sll	$t7,$a0,0x1
/*  f116514:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f116518:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f11651c:	0305c825 */ 	or	$t9,$t8,$a1
/*  f116520:	03e00008 */ 	jr	$ra
/*  f116524:	a4590000 */ 	sh	$t9,0x0($v0)
);

GLOBAL_ASM(
glabel func0f116528
/*  f116528:	3c0e800a */ 	lui	$t6,0x800a
/*  f11652c:	8dce2360 */ 	lw	$t6,0x2360($t6)
/*  f116530:	00047840 */ 	sll	$t7,$a0,0x1
/*  f116534:	00a0c827 */ 	nor	$t9,$a1,$zero
/*  f116538:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f11653c:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f116540:	03194024 */ 	and	$t0,$t8,$t9
/*  f116544:	03e00008 */ 	jr	$ra
/*  f116548:	a4480000 */ 	sh	$t0,0x0($v0)
);

GLOBAL_ASM(
glabel func0f11654c
/*  f11654c:	04800016 */ 	bltz	$a0,.L0f1165a8
/*  f116550:	3c0e800a */ 	lui	$t6,0x800a
/*  f116554:	8dce2350 */ 	lw	$t6,0x2350($t6)
/*  f116558:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f11655c:	008f082a */ 	slt	$at,$a0,$t7
/*  f116560:	10200011 */ 	beqz	$at,.L0f1165a8
/*  f116564:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116568:	10a00009 */ 	beqz	$a1,.L0f116590
/*  f11656c:	3c0a800a */ 	lui	$t2,0x800a
/*  f116570:	3c18800a */ 	lui	$t8,0x800a
/*  f116574:	8f182360 */ 	lw	$t8,0x2360($t8)
/*  f116578:	0004c840 */ 	sll	$t9,$a0,0x1
/*  f11657c:	03191021 */ 	addu	$v0,$t8,$t9
/*  f116580:	94480000 */ 	lhu	$t0,0x0($v0)
/*  f116584:	35090001 */ 	ori	$t1,$t0,0x1
/*  f116588:	03e00008 */ 	jr	$ra
/*  f11658c:	a4490000 */ 	sh	$t1,0x0($v0)
.L0f116590:
/*  f116590:	8d4a2360 */ 	lw	$t2,0x2360($t2)
/*  f116594:	00045840 */ 	sll	$t3,$a0,0x1
/*  f116598:	014b1021 */ 	addu	$v0,$t2,$t3
/*  f11659c:	944c0000 */ 	lhu	$t4,0x0($v0)
/*  f1165a0:	318dfffe */ 	andi	$t5,$t4,0xfffe
/*  f1165a4:	a44d0000 */ 	sh	$t5,0x0($v0)
.L0f1165a8:
/*  f1165a8:	03e00008 */ 	jr	$ra
/*  f1165ac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1165b0
/*  f1165b0:	9482000c */ 	lhu	$v0,0xc($a0)
/*  f1165b4:	304e00e0 */ 	andi	$t6,$v0,0xe0
/*  f1165b8:	03e00008 */ 	jr	$ra
/*  f1165bc:	000e102b */ 	sltu	$v0,$zero,$t6
/*  f1165c0:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f1165c4:	03e00008 */ 	jr	$ra
/*  f1165c8:	00801025 */ 	or	$v0,$a0,$zero
/*  f1165cc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1165d0
/*  f1165d0:	00047600 */ 	sll	$t6,$a0,0x18
/*  f1165d4:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f1165d8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1165dc:	15e10003 */ 	bne	$t7,$at,.L0f1165ec
/*  f1165e0:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f1165e4:	03e00008 */ 	jr	$ra
/*  f1165e8:	24020010 */ 	addiu	$v0,$zero,0x10
.L0f1165ec:
/*  f1165ec:	24030020 */ 	addiu	$v1,$zero,0x20
/*  f1165f0:	03e00008 */ 	jr	$ra
/*  f1165f4:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f1165f8
/*  f1165f8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1165fc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f116600:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f116604:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116608:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f11660c:	0fc45974 */ 	jal	func0f1165d0
/*  f116610:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f116614:	24010020 */ 	addiu	$at,$zero,0x20
/*  f116618:	14410005 */ 	bne	$v0,$at,.L0f116630
/*  f11661c:	8fa4001c */ 	lw	$a0,0x1c($sp)
/*  f116620:	0fc5db70 */ 	jal	func0f176dc0
/*  f116624:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116628:	10000004 */ 	beqz	$zero,.L0f11663c
/*  f11662c:	00401825 */ 	or	$v1,$v0,$zero
.L0f116630:
/*  f116630:	0fc5db69 */ 	jal	func0f176da4
/*  f116634:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116638:	00401825 */ 	or	$v1,$v0,$zero
.L0f11663c:
/*  f11663c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f116640:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f116644:	00601025 */ 	or	$v0,$v1,$zero
/*  f116648:	03e00008 */ 	jr	$ra
/*  f11664c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116650:	03e00008 */ 	jr	$ra
/*  f116654:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116658
/*  f116658:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f11665c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f116660:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f116664:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116668:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f11666c:	0fc4597e */ 	jal	func0f1165f8
/*  f116670:	24a50010 */ 	addiu	$a1,$a1,0x10
/*  f116674:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f116678:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f11667c:	03e00008 */ 	jr	$ra
/*  f116680:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116684
/*  f116684:	03e00008 */ 	jr	$ra
/*  f116688:	2482fff0 */ 	addiu	$v0,$a0,-16
);

GLOBAL_ASM(
glabel func0f11668c
/*  f11668c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f116690:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f116694:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116698:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f11669c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1166a0:	14810003 */ 	bne	$a0,$at,.L0f1166b0
/*  f1166a4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1166a8:	10000019 */ 	beqz	$zero,.L0f116710
/*  f1166ac:	24020baa */ 	addiu	$v0,$zero,0xbaa
.L0f1166b0:
/*  f1166b0:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f1166b4:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f1166b8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1166bc:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f1166c0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1166c4:	0304c021 */ 	addu	$t8,$t8,$a0
/*  f1166c8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1166cc:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f1166d0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1166d4:	3c19800a */ 	lui	$t9,0x800a
/*  f1166d8:	0338c821 */ 	addu	$t9,$t9,$t8
/*  f1166dc:	8f392648 */ 	lw	$t9,0x2648($t9)
/*  f1166e0:	0c004b70 */ 	jal	random
/*  f1166e4:	afb9001c */ 	sw	$t9,0x1c($sp)
/*  f1166e8:	240101f0 */ 	addiu	$at,$zero,0x1f0
/*  f1166ec:	0041001b */ 	divu	$zero,$v0,$at
/*  f1166f0:	00004010 */ 	mfhi	$t0
/*  f1166f4:	25090010 */ 	addiu	$t1,$t0,0x10
/*  f1166f8:	0c012144 */ 	jal	func00048510
/*  f1166fc:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f116700:	8faa001c */ 	lw	$t2,0x1c($sp)
/*  f116704:	8fab0018 */ 	lw	$t3,0x18($sp)
/*  f116708:	014b6026 */ 	xor	$t4,$t2,$t3
/*  f11670c:	01821026 */ 	xor	$v0,$t4,$v0
.L0f116710:
/*  f116710:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f116714:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f116718:	03e00008 */ 	jr	$ra
/*  f11671c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116720
/*  f116720:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116724:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f116728:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11672c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116730:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116734:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116738:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11673c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f116740:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116744:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116748:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11674c:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f116750:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116754:	03191021 */ 	addu	$v0,$t8,$t9
/*  f116758:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f11675c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f116760:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f116764:	55010010 */ 	bnel	$t0,$at,.L0f1167a8
/*  f116768:	00001025 */ 	or	$v0,$zero,$zero
/*  f11676c:	8c490010 */ 	lw	$t1,0x10($v0)
/*  f116770:	252afff2 */ 	addiu	$t2,$t1,-14
/*  f116774:	2d410009 */ 	sltiu	$at,$t2,0x9
/*  f116778:	10200008 */ 	beqz	$at,.L0f11679c
/*  f11677c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f116780:	3c017f1b */ 	lui	$at,%hi(var7f1b4d8c)
/*  f116784:	002a0821 */ 	addu	$at,$at,$t2
/*  f116788:	8c2a4d8c */ 	lw	$t2,%lo(var7f1b4d8c)($at)
/*  f11678c:	01400008 */ 	jr	$t2
/*  f116790:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116794:	03e00008 */ 	jr	$ra
/*  f116798:	00001025 */ 	or	$v0,$zero,$zero
.L0f11679c:
/*  f11679c:	03e00008 */ 	jr	$ra
/*  f1167a0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1167a4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1167a8:
/*  f1167a8:	03e00008 */ 	jr	$ra
/*  f1167ac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1167b0
/*  f1167b0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1167b4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1167b8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1167bc:	00047600 */ 	sll	$t6,$a0,0x18
/*  f1167c0:	0fc46346 */ 	jal	func0f118d18
/*  f1167c4:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f1167c8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1167cc:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1167d0:	03e00008 */ 	jr	$ra
/*  f1167d4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1167d8
/*  f1167d8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1167dc:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1167e0:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1167e4:	00047600 */ 	sll	$t6,$a0,0x18
/*  f1167e8:	0fc464a6 */ 	jal	func0f119298
/*  f1167ec:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f1167f0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1167f4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1167f8:	03e00008 */ 	jr	$ra
/*  f1167fc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116800
/*  f116800:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f116804:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f116808:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f11680c:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116810:	0fc462f2 */ 	jal	func0f118bc8
/*  f116814:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f116818:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11681c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f116820:	03e00008 */ 	jr	$ra
/*  f116824:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116828
/*  f116828:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f11682c:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f116830:	8fb90034 */ 	lw	$t9,0x34($sp)
/*  f116834:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f116838:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f11683c:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116840:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f116844:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f116848:	0fc45e27 */ 	jal	func0f11789c
/*  f11684c:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f116850:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f116854:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f116858:	03e00008 */ 	jr	$ra
/*  f11685c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116860
/*  f116860:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f116864:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f116868:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f11686c:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116870:	0fc45be8 */ 	jal	func0f116fa0
/*  f116874:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f116878:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11687c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f116880:	03e00008 */ 	jr	$ra
/*  f116884:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116888
/*  f116888:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f11688c:	8fb90030 */ 	lw	$t9,0x30($sp)
/*  f116890:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f116894:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f116898:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f11689c:	00047600 */ 	sll	$t6,$a0,0x18
/*  f1168a0:	30b8ffff */ 	andi	$t8,$a1,0xffff
/*  f1168a4:	03002825 */ 	or	$a1,$t8,$zero
/*  f1168a8:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f1168ac:	0fc45ba1 */ 	jal	func0f116e84
/*  f1168b0:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f1168b4:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f1168b8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f1168bc:	03e00008 */ 	jr	$ra
/*  f1168c0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1168c4
/*  f1168c4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1168c8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1168cc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1168d0:	00047600 */ 	sll	$t6,$a0,0x18
/*  f1168d4:	0fc45b7c */ 	jal	func0f116df0
/*  f1168d8:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f1168dc:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1168e0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1168e4:	03e00008 */ 	jr	$ra
/*  f1168e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1168ec:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1168f0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1168f4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1168f8:	00047600 */ 	sll	$t6,$a0,0x18
/*  f1168fc:	0fc4608c */ 	jal	func0f118230
/*  f116900:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f116904:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f116908:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f11690c:	03e00008 */ 	jr	$ra
/*  f116910:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116914
/*  f116914:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f116918:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11691c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f116920:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116924:	0fc45b25 */ 	jal	func0f116c94
/*  f116928:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f11692c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f116930:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f116934:	03e00008 */ 	jr	$ra
/*  f116938:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11693c
/*  f11693c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f116940:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f116944:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f116948:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11694c:	0fc45b15 */ 	jal	func0f116c54
/*  f116950:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f116954:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f116958:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f11695c:	03e00008 */ 	jr	$ra
/*  f116960:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116964:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f116968:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11696c:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f116970:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116974:	0fc45af7 */ 	jal	func0f116bdc
/*  f116978:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f11697c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f116980:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f116984:	03e00008 */ 	jr	$ra
/*  f116988:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11698c:	03e00008 */ 	jr	$ra
/*  f116990:	afa40000 */ 	sw	$a0,0x0($sp)
);

GLOBAL_ASM(
glabel func0f116994
/*  f116994:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f116998:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f11699c:	8c4e04b4 */ 	lw	$t6,0x4b4($v0)
/*  f1169a0:	2401005b */ 	addiu	$at,$zero,0x5b
/*  f1169a4:	240f00f8 */ 	addiu	$t7,$zero,0xf8
/*  f1169a8:	15c10002 */ 	bne	$t6,$at,.L0f1169b4
/*  f1169ac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1169b0:	a44f04e4 */ 	sh	$t7,0x4e4($v0)
.L0f1169b4:
/*  f1169b4:	03e00008 */ 	jr	$ra
/*  f1169b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1169bc:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f1169c0:	03e00008 */ 	jr	$ra
/*  f1169c4:	afa50004 */ 	sw	$a1,0x4($sp)
);

GLOBAL_ASM(
glabel func0f1169c8
/*  f1169c8:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f1169cc:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f1169d0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1169d4:	906804d1 */ 	lbu	$t0,0x4d1($v1)
/*  f1169d8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1169dc:	00048600 */ 	sll	$s0,$a0,0x18
/*  f1169e0:	2418001f */ 	addiu	$t8,$zero,0x1f
/*  f1169e4:	00107603 */ 	sra	$t6,$s0,0x18
/*  f1169e8:	330900ff */ 	andi	$t1,$t8,0xff
/*  f1169ec:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f1169f0:	906f04d0 */ 	lbu	$t7,0x4d0($v1)
/*  f1169f4:	01d91004 */ 	sllv	$v0,$t9,$t6
/*  f1169f8:	01095025 */ 	or	$t2,$t0,$t1
/*  f1169fc:	01425824 */ 	and	$t3,$t2,$v0
/*  f116a00:	01c08025 */ 	or	$s0,$t6,$zero
/*  f116a04:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f116a08:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f116a0c:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f116a10:	a07804d0 */ 	sb	$t8,0x4d0($v1)
/*  f116a14:	1160002d */ 	beqz	$t3,.L0f116acc
/*  f116a18:	a3af0027 */ 	sb	$t7,0x27($sp)
/*  f116a1c:	3c048007 */ 	lui	$a0,%hi(var80075d10)
/*  f116a20:	24845d10 */ 	addiu	$a0,$a0,%lo(var80075d10)
/*  f116a24:	908c0000 */ 	lbu	$t4,0x0($a0)
/*  f116a28:	00406827 */ 	nor	$t5,$v0,$zero
/*  f116a2c:	018d7024 */ 	and	$t6,$t4,$t5
/*  f116a30:	0fc4728c */ 	jal	func0f11ca30
/*  f116a34:	a08e0000 */ 	sb	$t6,0x0($a0)
/*  f116a38:	0fc4728c */ 	jal	func0f11ca30
/*  f116a3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116a40:	8faf002c */ 	lw	$t7,0x2c($sp)
/*  f116a44:	00102600 */ 	sll	$a0,$s0,0x18
/*  f116a48:	3c018006 */ 	lui	$at,0x8006
/*  f116a4c:	11e0001f */ 	beqz	$t7,.L0f116acc
/*  f116a50:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f116a54:	ac20eedc */ 	sw	$zero,-0x1124($at)
/*  f116a58:	0fc477e5 */ 	jal	func0f11df94
/*  f116a5c:	03002025 */ 	or	$a0,$t8,$zero
/*  f116a60:	00102600 */ 	sll	$a0,$s0,0x18
/*  f116a64:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f116a68:	0fc477e5 */ 	jal	func0f11df94
/*  f116a6c:	03202025 */ 	or	$a0,$t9,$zero
/*  f116a70:	00102600 */ 	sll	$a0,$s0,0x18
/*  f116a74:	00044603 */ 	sra	$t0,$a0,0x18
/*  f116a78:	0fc477e5 */ 	jal	func0f11df94
/*  f116a7c:	01002025 */ 	or	$a0,$t0,$zero
/*  f116a80:	00102600 */ 	sll	$a0,$s0,0x18
/*  f116a84:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f116a88:	0fc477e5 */ 	jal	func0f11df94
/*  f116a8c:	01202025 */ 	or	$a0,$t1,$zero
/*  f116a90:	00102600 */ 	sll	$a0,$s0,0x18
/*  f116a94:	00045603 */ 	sra	$t2,$a0,0x18
/*  f116a98:	0fc477e5 */ 	jal	func0f11df94
/*  f116a9c:	01402025 */ 	or	$a0,$t2,$zero
/*  f116aa0:	00102600 */ 	sll	$a0,$s0,0x18
/*  f116aa4:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f116aa8:	0fc477e5 */ 	jal	func0f11df94
/*  f116aac:	01602025 */ 	or	$a0,$t3,$zero
/*  f116ab0:	00102600 */ 	sll	$a0,$s0,0x18
/*  f116ab4:	00046603 */ 	sra	$t4,$a0,0x18
/*  f116ab8:	0fc477e5 */ 	jal	func0f11df94
/*  f116abc:	01802025 */ 	or	$a0,$t4,$zero
/*  f116ac0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f116ac4:	3c018006 */ 	lui	$at,0x8006
/*  f116ac8:	ac2deedc */ 	sw	$t5,-0x1124($at)
.L0f116acc:
/*  f116acc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f116ad0:	93ae0027 */ 	lbu	$t6,0x27($sp)
/*  f116ad4:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f116ad8:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f116adc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f116ae0:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f116ae4:	03e00008 */ 	jr	$ra
/*  f116ae8:	a06e04d0 */ 	sb	$t6,0x4d0($v1)
);

GLOBAL_ASM(
glabel func0f116aec
/*  f116aec:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116af0:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f116af4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f116af8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116afc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116b00:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116b04:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116b08:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f116b0c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116b10:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116b14:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f116b18:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f116b1c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116b20:	03191021 */ 	addu	$v0,$t8,$t9
/*  f116b24:	8c480010 */ 	lw	$t0,0x10($v0)
/*  f116b28:	2401000b */ 	addiu	$at,$zero,0xb
/*  f116b2c:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f116b30:	55010008 */ 	bnel	$t0,$at,.L0f116b54
/*  f116b34:	00001025 */ 	or	$v0,$zero,$zero
/*  f116b38:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f116b3c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f116b40:	55210004 */ 	bnel	$t1,$at,.L0f116b54
/*  f116b44:	00001025 */ 	or	$v0,$zero,$zero
/*  f116b48:	03e00008 */ 	jr	$ra
/*  f116b4c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f116b50:	00001025 */ 	or	$v0,$zero,$zero
.L0f116b54:
/*  f116b54:	03e00008 */ 	jr	$ra
/*  f116b58:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116b5c
/*  f116b5c:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116b60:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f116b64:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f116b68:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116b6c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116b70:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116b74:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116b78:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f116b7c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116b80:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116b84:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f116b88:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f116b8c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116b90:	03191021 */ 	addu	$v0,$t8,$t9
/*  f116b94:	8c430010 */ 	lw	$v1,0x10($v0)
/*  f116b98:	2401000b */ 	addiu	$at,$zero,0xb
/*  f116b9c:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f116ba0:	10610005 */ 	beq	$v1,$at,.L0f116bb8
/*  f116ba4:	24010010 */ 	addiu	$at,$zero,0x10
/*  f116ba8:	10610003 */ 	beq	$v1,$at,.L0f116bb8
/*  f116bac:	24010015 */ 	addiu	$at,$zero,0x15
/*  f116bb0:	54610008 */ 	bnel	$v1,$at,.L0f116bd4
/*  f116bb4:	00001025 */ 	or	$v0,$zero,$zero
.L0f116bb8:
/*  f116bb8:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f116bbc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f116bc0:	55010004 */ 	bnel	$t0,$at,.L0f116bd4
/*  f116bc4:	00001025 */ 	or	$v0,$zero,$zero
/*  f116bc8:	03e00008 */ 	jr	$ra
/*  f116bcc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f116bd0:	00001025 */ 	or	$v0,$zero,$zero
.L0f116bd4:
/*  f116bd4:	03e00008 */ 	jr	$ra
/*  f116bd8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116bdc
/*  f116bdc:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116be0:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f116be4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f116be8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116bec:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116bf0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116bf4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116bf8:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f116bfc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116c00:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116c04:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f116c08:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f116c0c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116c10:	03191021 */ 	addu	$v0,$t8,$t9
/*  f116c14:	904802ba */ 	lbu	$t0,0x2ba($v0)
/*  f116c18:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f116c1c:	a0a80000 */ 	sb	$t0,0x0($a1)
/*  f116c20:	904902bb */ 	lbu	$t1,0x2bb($v0)
/*  f116c24:	03e00008 */ 	jr	$ra
/*  f116c28:	a0c90000 */ 	sb	$t1,0x0($a2)
/*  f116c2c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f116c30:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f116c34:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f116c38:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116c3c:	0c004f13 */ 	jal	func00013c4c
/*  f116c40:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f116c44:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f116c48:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f116c4c:	03e00008 */ 	jr	$ra
/*  f116c50:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116c54
/*  f116c54:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116c58:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f116c5c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f116c60:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116c64:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116c68:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116c6c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116c70:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f116c74:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116c78:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116c7c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116c80:	3c02800a */ 	lui	$v0,0x800a
/*  f116c84:	00581021 */ 	addu	$v0,$v0,$t8
/*  f116c88:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f116c8c:	03e00008 */ 	jr	$ra
/*  f116c90:	944225e2 */ 	lhu	$v0,0x25e2($v0)
);

GLOBAL_ASM(
glabel func0f116c94
/*  f116c94:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116c98:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f116c9c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f116ca0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116ca4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116ca8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116cac:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116cb0:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f116cb4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116cb8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116cbc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116cc0:	3c02800a */ 	lui	$v0,0x800a
/*  f116cc4:	00581021 */ 	addu	$v0,$v0,$t8
/*  f116cc8:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f116ccc:	03e00008 */ 	jr	$ra
/*  f116cd0:	8c422380 */ 	lw	$v0,0x2380($v0)
/*  f116cd4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f116cd8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f116cdc:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f116ce0:	0fc47588 */ 	jal	func0f11d620
/*  f116ce4:	83a4001b */ 	lb	$a0,0x1b($sp)
/*  f116ce8:	83ae001b */ 	lb	$t6,0x1b($sp)
/*  f116cec:	3c02800a */ 	lui	$v0,0x800a
/*  f116cf0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f116cf4:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f116cf8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f116cfc:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f116d00:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f116d04:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f116d08:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f116d0c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f116d10:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f116d14:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f116d18:	004f1021 */ 	addu	$v0,$v0,$t7
/*  f116d1c:	8c422638 */ 	lw	$v0,0x2638($v0)
/*  f116d20:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f116d24:	00021900 */ 	sll	$v1,$v0,0x4
/*  f116d28:	0003c7c2 */ 	srl	$t8,$v1,0x1f
/*  f116d2c:	0018182b */ 	sltu	$v1,$zero,$t8
/*  f116d30:	10600004 */ 	beqz	$v1,.L0f116d44
/*  f116d34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116d38:	00021880 */ 	sll	$v1,$v0,0x2
/*  f116d3c:	000347c2 */ 	srl	$t0,$v1,0x1f
/*  f116d40:	0008182b */ 	sltu	$v1,$zero,$t0
.L0f116d44:
/*  f116d44:	03e00008 */ 	jr	$ra
/*  f116d48:	00601025 */ 	or	$v0,$v1,$zero
/*  f116d4c:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116d50:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f116d54:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f116d58:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116d5c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116d60:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116d64:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116d68:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f116d6c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116d70:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116d74:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116d78:	3c02800a */ 	lui	$v0,0x800a
/*  f116d7c:	00581021 */ 	addu	$v0,$v0,$t8
/*  f116d80:	8c422638 */ 	lw	$v0,0x2638($v0)
/*  f116d84:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f116d88:	00021900 */ 	sll	$v1,$v0,0x4
/*  f116d8c:	0003cfc2 */ 	srl	$t9,$v1,0x1f
/*  f116d90:	0019182b */ 	sltu	$v1,$zero,$t9
/*  f116d94:	10600004 */ 	beqz	$v1,.L0f116da8
/*  f116d98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116d9c:	00021880 */ 	sll	$v1,$v0,0x2
/*  f116da0:	00034fc2 */ 	srl	$t1,$v1,0x1f
/*  f116da4:	2d230001 */ 	sltiu	$v1,$t1,0x1
.L0f116da8:
/*  f116da8:	03e00008 */ 	jr	$ra
/*  f116dac:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f116db0
/*  f116db0:	00047600 */ 	sll	$t6,$a0,0x18
/*  f116db4:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f116db8:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f116dbc:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116dc0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116dc4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116dc8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116dcc:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f116dd0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116dd4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116dd8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116ddc:	3c01800a */ 	lui	$at,0x800a
/*  f116de0:	00380821 */ 	addu	$at,$at,$t8
/*  f116de4:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f116de8:	03e00008 */ 	jr	$ra
/*  f116dec:	ac252390 */ 	sw	$a1,0x2390($at)
);

GLOBAL_ASM(
glabel func0f116df0
/*  f116df0:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f116df4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f116df8:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f116dfc:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f116e00:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f116e04:	0fc45ad7 */ 	jal	func0f116b5c
/*  f116e08:	83a4001b */ 	lb	$a0,0x1b($sp)
/*  f116e0c:	50400019 */ 	beqzl	$v0,.L0f116e74
/*  f116e10:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f116e14:	0fc4695d */ 	jal	func0f11a574
/*  f116e18:	83a4001b */ 	lb	$a0,0x1b($sp)
/*  f116e1c:	10400012 */ 	beqz	$v0,.L0f116e68
/*  f116e20:	83af001b */ 	lb	$t7,0x1b($sp)
/*  f116e24:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f116e28:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116e2c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116e30:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116e34:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116e38:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f116e3c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116e40:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f116e44:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116e48:	3c08800a */ 	lui	$t0,%hi(var800a2380)
/*  f116e4c:	8faa001c */ 	lw	$t2,0x1c($sp)
/*  f116e50:	25082380 */ 	addiu	$t0,$t0,%lo(var800a2380)
/*  f116e54:	27190018 */ 	addiu	$t9,$t8,0x18
/*  f116e58:	03284821 */ 	addu	$t1,$t9,$t0
/*  f116e5c:	00001025 */ 	or	$v0,$zero,$zero
/*  f116e60:	10000004 */ 	beqz	$zero,.L0f116e74
/*  f116e64:	ad490000 */ 	sw	$t1,0x0($t2)
.L0f116e68:
/*  f116e68:	10000002 */ 	beqz	$zero,.L0f116e74
/*  f116e6c:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f116e70:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f116e74:
/*  f116e74:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f116e78:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f116e7c:	03e00008 */ 	jr	$ra
/*  f116e80:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116e84
/*  f116e84:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f116e88:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f116e8c:	00048600 */ 	sll	$s0,$a0,0x18
/*  f116e90:	00107603 */ 	sra	$t6,$s0,0x18
/*  f116e94:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f116e98:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f116e9c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f116ea0:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f116ea4:	01c08025 */ 	or	$s0,$t6,$zero
/*  f116ea8:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f116eac:	afa60038 */ 	sw	$a2,0x38($sp)
/*  f116eb0:	afa7003c */ 	sw	$a3,0x3c($sp)
/*  f116eb4:	0fc45ad7 */ 	jal	func0f116b5c
/*  f116eb8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f116ebc:	50400033 */ 	beqzl	$v0,.L0f116f8c
/*  f116ec0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f116ec4:	0c00543a */ 	jal	func000150e8
/*  f116ec8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f116ecc:	24010004 */ 	addiu	$at,$zero,0x4
/*  f116ed0:	16010003 */ 	bne	$s0,$at,.L0f116ee0
/*  f116ed4:	97a50036 */ 	lhu	$a1,0x36($sp)
/*  f116ed8:	10000009 */ 	beqz	$zero,.L0f116f00
/*  f116edc:	00002025 */ 	or	$a0,$zero,$zero
.L0f116ee0:
/*  f116ee0:	0010c080 */ 	sll	$t8,$s0,0x2
/*  f116ee4:	0310c023 */ 	subu	$t8,$t8,$s0
/*  f116ee8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f116eec:	0310c021 */ 	addu	$t8,$t8,$s0
/*  f116ef0:	3c19800a */ 	lui	$t9,%hi(var800a3180)
/*  f116ef4:	27393180 */ 	addiu	$t9,$t9,%lo(var800a3180)
/*  f116ef8:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f116efc:	03192021 */ 	addu	$a0,$t8,$t9
.L0f116f00:
/*  f116f00:	8fa80040 */ 	lw	$t0,0x40($sp)
/*  f116f04:	8fa60038 */ 	lw	$a2,0x38($sp)
/*  f116f08:	8fa7003c */ 	lw	$a3,0x3c($sp)
/*  f116f0c:	0fc45f80 */ 	jal	func0f117e00
/*  f116f10:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f116f14:	0c005451 */ 	jal	func00015144
/*  f116f18:	afa2002c */ 	sw	$v0,0x2c($sp)
/*  f116f1c:	00102e00 */ 	sll	$a1,$s0,0x18
/*  f116f20:	00054e03 */ 	sra	$t1,$a1,0x18
/*  f116f24:	01202825 */ 	or	$a1,$t1,$zero
/*  f116f28:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f116f2c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f116f30:	0fc470e7 */ 	jal	func0f11c39c
/*  f116f34:	24070339 */ 	addiu	$a3,$zero,0x339
/*  f116f38:	10400011 */ 	beqz	$v0,.L0f116f80
/*  f116f3c:	00105080 */ 	sll	$t2,$s0,0x2
/*  f116f40:	01505023 */ 	subu	$t2,$t2,$s0
/*  f116f44:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f116f48:	01505023 */ 	subu	$t2,$t2,$s0
/*  f116f4c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f116f50:	01505021 */ 	addu	$t2,$t2,$s0
/*  f116f54:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f116f58:	01505023 */ 	subu	$t2,$t2,$s0
/*  f116f5c:	3c0b800a */ 	lui	$t3,%hi(var800a2380)
/*  f116f60:	256b2380 */ 	addiu	$t3,$t3,%lo(var800a2380)
/*  f116f64:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f116f68:	014b1821 */ 	addu	$v1,$t2,$t3
/*  f116f6c:	906d02b8 */ 	lbu	$t5,0x2b8($v1)
/*  f116f70:	00001025 */ 	or	$v0,$zero,$zero
/*  f116f74:	35ae0040 */ 	ori	$t6,$t5,0x40
/*  f116f78:	10000004 */ 	beqz	$zero,.L0f116f8c
/*  f116f7c:	a06e02b8 */ 	sb	$t6,0x2b8($v1)
.L0f116f80:
/*  f116f80:	10000002 */ 	beqz	$zero,.L0f116f8c
/*  f116f84:	24020002 */ 	addiu	$v0,$zero,0x2
/*  f116f88:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f116f8c:
/*  f116f8c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f116f90:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f116f94:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f116f98:	03e00008 */ 	jr	$ra
/*  f116f9c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f116fa0
/*  f116fa0:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f116fa4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f116fa8:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f116fac:	83a4004b */ 	lb	$a0,0x4b($sp)
/*  f116fb0:	0fc464da */ 	jal	func0f119368
/*  f116fb4:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f116fb8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f116fbc:	14410003 */ 	bne	$v0,$at,.L0f116fcc
/*  f116fc0:	00402825 */ 	or	$a1,$v0,$zero
/*  f116fc4:	10000015 */ 	beqz	$zero,.L0f11701c
/*  f116fc8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f116fcc:
/*  f116fcc:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f116fd0:	8fa60040 */ 	lw	$a2,0x40($sp)
/*  f116fd4:	83a4004b */ 	lb	$a0,0x4b($sp)
/*  f116fd8:	000fc500 */ 	sll	$t8,$t7,0x14
/*  f116fdc:	0018cdc2 */ 	srl	$t9,$t8,0x17
/*  f116fe0:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f116fe4:	000675c2 */ 	srl	$t6,$a2,0x17
/*  f116fe8:	01c03025 */ 	or	$a2,$t6,$zero
/*  f116fec:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f116ff0:	00003825 */ 	or	$a3,$zero,$zero
/*  f116ff4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f116ff8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f116ffc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f117000:	0fc46f15 */ 	jal	func0f11bc54
/*  f117004:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f117008:	50400004 */ 	beqzl	$v0,.L0f11701c
/*  f11700c:	00001025 */ 	or	$v0,$zero,$zero
/*  f117010:	10000003 */ 	beqz	$zero,.L0f117020
/*  f117014:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f117018:	00001025 */ 	or	$v0,$zero,$zero
.L0f11701c:
/*  f11701c:	8fbf002c */ 	lw	$ra,0x2c($sp)
.L0f117020:
/*  f117020:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f117024:	03e00008 */ 	jr	$ra
/*  f117028:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11702c
/*  f11702c:	00047600 */ 	sll	$t6,$a0,0x18
/*  f117030:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f117034:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f117038:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11703c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117040:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117044:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117048:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11704c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117050:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117054:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117058:	3c02800a */ 	lui	$v0,0x800a
/*  f11705c:	00581021 */ 	addu	$v0,$v0,$t8
/*  f117060:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f117064:	03e00008 */ 	jr	$ra
/*  f117068:	8c4225e4 */ 	lw	$v0,0x25e4($v0)
);

GLOBAL_ASM(
glabel func0f11706c
/*  f11706c:	00047600 */ 	sll	$t6,$a0,0x18
/*  f117070:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f117074:	24010004 */ 	addiu	$at,$zero,0x4
/*  f117078:	11e10003 */ 	beq	$t7,$at,.L0f117088
/*  f11707c:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f117080:	03e00008 */ 	jr	$ra
/*  f117084:	240204c0 */ 	addiu	$v0,$zero,0x4c0
.L0f117088:
/*  f117088:	24020100 */ 	addiu	$v0,$zero,0x100
/*  f11708c:	03e00008 */ 	jr	$ra
/*  f117090:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f117094
/*  f117094:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f117098:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f11709c:	00047600 */ 	sll	$t6,$a0,0x18
/*  f1170a0:	2ca10041 */ 	sltiu	$at,$a1,0x41
/*  f1170a4:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f1170a8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1170ac:	14200006 */ 	bnez	$at,.L0f1170c8
/*  f1170b0:	00001825 */ 	or	$v1,$zero,$zero
/*  f1170b4:	24010080 */ 	addiu	$at,$zero,0x80
/*  f1170b8:	50a10020 */ 	beql	$a1,$at,.L0f11713c
/*  f1170bc:	240300a0 */ 	addiu	$v1,$zero,0xa0
/*  f1170c0:	1000001f */ 	beqz	$zero,.L0f117140
/*  f1170c4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1170c8:
/*  f1170c8:	2ca10021 */ 	sltiu	$at,$a1,0x21
/*  f1170cc:	14200006 */ 	bnez	$at,.L0f1170e8
/*  f1170d0:	24b8ffff */ 	addiu	$t8,$a1,-1
/*  f1170d4:	24010040 */ 	addiu	$at,$zero,0x40
/*  f1170d8:	10a10013 */ 	beq	$a1,$at,.L0f117128
/*  f1170dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1170e0:	10000017 */ 	beqz	$zero,.L0f117140
/*  f1170e4:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1170e8:
/*  f1170e8:	2f010020 */ 	sltiu	$at,$t8,0x20
/*  f1170ec:	10200013 */ 	beqz	$at,.L0f11713c
/*  f1170f0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1170f4:	3c017f1b */ 	lui	$at,%hi(var7f1b4db0)
/*  f1170f8:	00380821 */ 	addu	$at,$at,$t8
/*  f1170fc:	8c384db0 */ 	lw	$t8,%lo(var7f1b4db0)($at)
/*  f117100:	03000008 */ 	jr	$t8
/*  f117104:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117108:	0fc45c1b */ 	jal	func0f11706c
/*  f11710c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117110:	1000000a */ 	beqz	$zero,.L0f11713c
/*  f117114:	2443fff0 */ 	addiu	$v1,$v0,-16
/*  f117118:	10000008 */ 	beqz	$zero,.L0f11713c
/*  f11711c:	2403005b */ 	addiu	$v1,$zero,0x5b
/*  f117120:	10000006 */ 	beqz	$zero,.L0f11713c
/*  f117124:	2403004e */ 	addiu	$v1,$zero,0x4e
.L0f117128:
/*  f117128:	10000004 */ 	beqz	$zero,.L0f11713c
/*  f11712c:	24030031 */ 	addiu	$v1,$zero,0x31
/*  f117130:	10000002 */ 	beqz	$zero,.L0f11713c
/*  f117134:	240304a0 */ 	addiu	$v1,$zero,0x4a0
/*  f117138:	240300a0 */ 	addiu	$v1,$zero,0xa0
.L0f11713c:
/*  f11713c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f117140:
/*  f117140:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f117144:	00601025 */ 	or	$v0,$v1,$zero
/*  f117148:	03e00008 */ 	jr	$ra
/*  f11714c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f117150
/*  f117150:	00047600 */ 	sll	$t6,$a0,0x18
/*  f117154:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f117158:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11715c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117160:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117164:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117168:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11716c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f117170:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117174:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117178:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11717c:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f117180:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117184:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f117188:	03191021 */ 	addu	$v0,$t8,$t9
/*  f11718c:	ac4502c4 */ 	sw	$a1,0x2c4($v0)
/*  f117190:	24041000 */ 	addiu	$a0,$zero,0x1000
/*  f117194:	00001825 */ 	or	$v1,$zero,$zero
.L0f117198:
/*  f117198:	8c4802c4 */ 	lw	$t0,0x2c4($v0)
/*  f11719c:	01034821 */ 	addu	$t1,$t0,$v1
/*  f1171a0:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1171a4:	1464fffc */ 	bne	$v1,$a0,.L0f117198
/*  f1171a8:	a1200000 */ 	sb	$zero,0x0($t1)
/*  f1171ac:	03e00008 */ 	jr	$ra
/*  f1171b0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1171b4
/*  f1171b4:	00047600 */ 	sll	$t6,$a0,0x18
/*  f1171b8:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f1171bc:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1171c0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1171c4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1171c8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1171cc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1171d0:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f1171d4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1171d8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1171dc:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f1171e0:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f1171e4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1171e8:	03191021 */ 	addu	$v0,$t8,$t9
/*  f1171ec:	904b02b8 */ 	lbu	$t3,0x2b8($v0)
/*  f1171f0:	00064880 */ 	sll	$t1,$a2,0x2
/*  f1171f4:	312a0004 */ 	andi	$t2,$t1,0x4
/*  f1171f8:	316cfffb */ 	andi	$t4,$t3,0xfffb
/*  f1171fc:	014c6825 */ 	or	$t5,$t2,$t4
/*  f117200:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f117204:	ac45000c */ 	sw	$a1,0xc($v0)
/*  f117208:	03e00008 */ 	jr	$ra
/*  f11720c:	a04d02b8 */ 	sb	$t5,0x2b8($v0)
);

GLOBAL_ASM(
glabel func0f117210
/*  f117210:	00047600 */ 	sll	$t6,$a0,0x18
/*  f117214:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f117218:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11721c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117220:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117224:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117228:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11722c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f117230:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117234:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117238:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11723c:	3c02800a */ 	lui	$v0,0x800a
/*  f117240:	00581021 */ 	addu	$v0,$v0,$t8
/*  f117244:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f117248:	03e00008 */ 	jr	$ra
/*  f11724c:	8c422388 */ 	lw	$v0,0x2388($v0)
/*  f117250:	00047600 */ 	sll	$t6,$a0,0x18
/*  f117254:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f117258:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11725c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117260:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117264:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117268:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11726c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f117270:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117274:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117278:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11727c:	3c01800a */ 	lui	$at,0x800a
/*  f117280:	00380821 */ 	addu	$at,$at,$t8
/*  f117284:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f117288:	03e00008 */ 	jr	$ra
/*  f11728c:	ac252388 */ 	sw	$a1,0x2388($at)
/*  f117290:	00047600 */ 	sll	$t6,$a0,0x18
/*  f117294:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f117298:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11729c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1172a0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1172a4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1172a8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1172ac:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f1172b0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1172b4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1172b8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1172bc:	3c02800a */ 	lui	$v0,0x800a
/*  f1172c0:	00581021 */ 	addu	$v0,$v0,$t8
/*  f1172c4:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f1172c8:	03e00008 */ 	jr	$ra
/*  f1172cc:	8c4225f0 */ 	lw	$v0,0x25f0($v0)
/*  f1172d0:	00047600 */ 	sll	$t6,$a0,0x18
/*  f1172d4:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f1172d8:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1172dc:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1172e0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1172e4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1172e8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1172ec:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f1172f0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1172f4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1172f8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1172fc:	3c02800a */ 	lui	$v0,0x800a
/*  f117300:	00581021 */ 	addu	$v0,$v0,$t8
/*  f117304:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f117308:	03e00008 */ 	jr	$ra
/*  f11730c:	8c422384 */ 	lw	$v0,0x2384($v0)
/*  f117310:	00047600 */ 	sll	$t6,$a0,0x18
/*  f117314:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f117318:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11731c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117320:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117324:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117328:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11732c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f117330:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117334:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117338:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11733c:	3c01800a */ 	lui	$at,0x800a
/*  f117340:	00380821 */ 	addu	$at,$at,$t8
/*  f117344:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f117348:	03e00008 */ 	jr	$ra
/*  f11734c:	ac252384 */ 	sw	$a1,0x2384($at)
/*  f117350:	00047600 */ 	sll	$t6,$a0,0x18
/*  f117354:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f117358:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11735c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117360:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117364:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117368:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11736c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f117370:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117374:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117378:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11737c:	3c02800a */ 	lui	$v0,0x800a
/*  f117380:	00581021 */ 	addu	$v0,$v0,$t8
/*  f117384:	8c422638 */ 	lw	$v0,0x2638($v0)
/*  f117388:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11738c:	0002cfc2 */ 	srl	$t9,$v0,0x1f
/*  f117390:	03e00008 */ 	jr	$ra
/*  f117394:	03201025 */ 	or	$v0,$t9,$zero
/*  f117398:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11739c:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f1173a0:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1173a4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1173a8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1173ac:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1173b0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1173b4:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f1173b8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1173bc:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1173c0:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f1173c4:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f1173c8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1173cc:	03191021 */ 	addu	$v0,$t8,$t9
/*  f1173d0:	904902b8 */ 	lbu	$t1,0x2b8($v0)
/*  f1173d4:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f1173d8:	352a0080 */ 	ori	$t2,$t1,0x80
/*  f1173dc:	03e00008 */ 	jr	$ra
/*  f1173e0:	a04a02b8 */ 	sb	$t2,0x2b8($v0)
/*  f1173e4:	00047600 */ 	sll	$t6,$a0,0x18
/*  f1173e8:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f1173ec:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1173f0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1173f4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1173f8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1173fc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117400:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f117404:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117408:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11740c:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f117410:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f117414:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117418:	03191021 */ 	addu	$v0,$t8,$t9
/*  f11741c:	904802b8 */ 	lbu	$t0,0x2b8($v0)
/*  f117420:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f117424:	3109ff7f */ 	andi	$t1,$t0,0xff7f
/*  f117428:	03e00008 */ 	jr	$ra
/*  f11742c:	a04902b8 */ 	sb	$t1,0x2b8($v0)
);

GLOBAL_ASM(
glabel func0f117430
/*  f117430:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f117434:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f117438:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f11743c:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f117440:	afa60040 */ 	sw	$a2,0x40($sp)
/*  f117444:	0fc45974 */ 	jal	func0f1165d0
/*  f117448:	83a4003b */ 	lb	$a0,0x3b($sp)
/*  f11744c:	83ae003b */ 	lb	$t6,0x3b($sp)
/*  f117450:	3c18800a */ 	lui	$t8,%hi(var800a2380)
/*  f117454:	27182380 */ 	addiu	$t8,$t8,%lo(var800a2380)
/*  f117458:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f11745c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f117460:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f117464:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f117468:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11746c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f117470:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f117474:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f117478:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11747c:	01f84021 */ 	addu	$t0,$t7,$t8
/*  f117480:	910502be */ 	lbu	$a1,0x2be($t0)
/*  f117484:	28a10032 */ 	slti	$at,$a1,0x32
/*  f117488:	50200021 */ 	beqzl	$at,.L0f117510
/*  f11748c:	00001025 */ 	or	$v0,$zero,$zero
/*  f117490:	18a0001e */ 	blez	$a1,.L0f11750c
/*  f117494:	00001825 */ 	or	$v1,$zero,$zero
/*  f117498:	8fb9003c */ 	lw	$t9,0x3c($sp)
/*  f11749c:	00003825 */ 	or	$a3,$zero,$zero
/*  f1174a0:	8d0402c0 */ 	lw	$a0,0x2c0($t0)
/*  f1174a4:	0322001b */ 	divu	$zero,$t9,$v0
/*  f1174a8:	00003012 */ 	mflo	$a2
/*  f1174ac:	14400002 */ 	bnez	$v0,.L0f1174b8
/*  f1174b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1174b4:	0007000d */ 	break	0x7
.L0f1174b8:
/*  f1174b8:	8c890000 */ 	lw	$t1,0x0($a0)
/*  f1174bc:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f1174c0:	0065082a */ 	slt	$at,$v1,$a1
/*  f1174c4:	14c9000f */ 	bne	$a2,$t1,.L0f117504
/*  f1174c8:	24840024 */ 	addiu	$a0,$a0,0x24
/*  f1174cc:	83a4003b */ 	lb	$a0,0x3b($sp)
/*  f1174d0:	afa7001c */ 	sw	$a3,0x1c($sp)
/*  f1174d4:	0fc45974 */ 	jal	func0f1165d0
/*  f1174d8:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f1174dc:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f1174e0:	8fa7001c */ 	lw	$a3,0x1c($sp)
/*  f1174e4:	8fa40040 */ 	lw	$a0,0x40($sp)
/*  f1174e8:	8d0a02c0 */ 	lw	$t2,0x2c0($t0)
/*  f1174ec:	00403025 */ 	or	$a2,$v0,$zero
/*  f1174f0:	01472821 */ 	addu	$a1,$t2,$a3
/*  f1174f4:	0c012978 */ 	jal	func0004a5e0
/*  f1174f8:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f1174fc:	10000004 */ 	beqz	$zero,.L0f117510
/*  f117500:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f117504:
/*  f117504:	1420ffec */ 	bnez	$at,.L0f1174b8
/*  f117508:	24e70024 */ 	addiu	$a3,$a3,0x24
.L0f11750c:
/*  f11750c:	00001025 */ 	or	$v0,$zero,$zero
.L0f117510:
/*  f117510:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f117514:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f117518:	03e00008 */ 	jr	$ra
/*  f11751c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f117520
/*  f117520:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f117524:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f117528:	afa40078 */ 	sw	$a0,0x78($sp)
/*  f11752c:	10c00003 */ 	beqz	$a2,.L0f11753c
/*  f117530:	afa5007c */ 	sw	$a1,0x7c($sp)
/*  f117534:	10000003 */ 	beqz	$zero,.L0f117544
/*  f117538:	afa60064 */ 	sw	$a2,0x64($sp)
.L0f11753c:
/*  f11753c:	27ae0068 */ 	addiu	$t6,$sp,0x68
/*  f117540:	afae0064 */ 	sw	$t6,0x64($sp)
.L0f117544:
/*  f117544:	0fc45974 */ 	jal	func0f1165d0
/*  f117548:	83a4007b */ 	lb	$a0,0x7b($sp)
/*  f11754c:	8faf007c */ 	lw	$t7,0x7c($sp)
/*  f117550:	83a4007b */ 	lb	$a0,0x7b($sp)
/*  f117554:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f117558:	01e2001b */ 	divu	$zero,$t7,$v0
/*  f11755c:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f117560:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f117564:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117568:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f11756c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117570:	0304c021 */ 	addu	$t8,$t8,$a0
/*  f117574:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117578:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f11757c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117580:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f117584:	03194021 */ 	addu	$t0,$t8,$t9
/*  f117588:	8d0902a4 */ 	lw	$t1,0x2a4($t0)
/*  f11758c:	00001812 */ 	mflo	$v1
/*  f117590:	00602825 */ 	or	$a1,$v1,$zero
/*  f117594:	14400002 */ 	bnez	$v0,.L0f1175a0
/*  f117598:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11759c:	0007000d */ 	break	0x7
.L0f1175a0:
/*  f1175a0:	0069082b */ 	sltu	$at,$v1,$t1
/*  f1175a4:	14200003 */ 	bnez	$at,.L0f1175b4
/*  f1175a8:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f1175ac:	1000006b */ 	beqz	$zero,.L0f11775c
/*  f1175b0:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f1175b4:
/*  f1175b4:	afa50060 */ 	sw	$a1,0x60($sp)
/*  f1175b8:	0fc46d22 */ 	jal	func0f11b488
/*  f1175bc:	afa80030 */ 	sw	$t0,0x30($sp)
/*  f1175c0:	1440005e */ 	bnez	$v0,.L0f11773c
/*  f1175c4:	8fa80030 */ 	lw	$t0,0x30($sp)
/*  f1175c8:	83a4007b */ 	lb	$a0,0x7b($sp)
/*  f1175cc:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1175d0:	00003825 */ 	or	$a3,$zero,$zero
/*  f1175d4:	14810003 */ 	bne	$a0,$at,.L0f1175e4
/*  f1175d8:	8fac007c */ 	lw	$t4,0x7c($sp)
/*  f1175dc:	10000009 */ 	beqz	$zero,.L0f117604
/*  f1175e0:	00002825 */ 	or	$a1,$zero,$zero
.L0f1175e4:
/*  f1175e4:	00045080 */ 	sll	$t2,$a0,0x2
/*  f1175e8:	01445023 */ 	subu	$t2,$t2,$a0
/*  f1175ec:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f1175f0:	01445021 */ 	addu	$t2,$t2,$a0
/*  f1175f4:	3c0b800a */ 	lui	$t3,%hi(var800a3180)
/*  f1175f8:	256b3180 */ 	addiu	$t3,$t3,%lo(var800a3180)
/*  f1175fc:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f117600:	014b2821 */ 	addu	$a1,$t2,$t3
.L0f117604:
/*  f117604:	240d0020 */ 	addiu	$t5,$zero,0x20
/*  f117608:	27ae0038 */ 	addiu	$t6,$sp,0x38
/*  f11760c:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f117610:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f117614:	8d06029c */ 	lw	$a2,0x29c($t0)
/*  f117618:	0fc46941 */ 	jal	func0f11a504
/*  f11761c:	afac0010 */ 	sw	$t4,0x10($sp)
/*  f117620:	afa2005c */ 	sw	$v0,0x5c($sp)
/*  f117624:	00402025 */ 	or	$a0,$v0,$zero
/*  f117628:	83a5007b */ 	lb	$a1,0x7b($sp)
/*  f11762c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f117630:	0fc470e7 */ 	jal	func0f11c39c
/*  f117634:	24070422 */ 	addiu	$a3,$zero,0x422
/*  f117638:	14400009 */ 	bnez	$v0,.L0f117660
/*  f11763c:	8fa40064 */ 	lw	$a0,0x64($sp)
/*  f117640:	8faf005c */ 	lw	$t7,0x5c($sp)
/*  f117644:	24010001 */ 	addiu	$at,$zero,0x1
/*  f117648:	15e10003 */ 	bne	$t7,$at,.L0f117658
/*  f11764c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117650:	10000042 */ 	beqz	$zero,.L0f11775c
/*  f117654:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f117658:
/*  f117658:	10000040 */ 	beqz	$zero,.L0f11775c
/*  f11765c:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f117660:
/*  f117660:	27a50038 */ 	addiu	$a1,$sp,0x38
/*  f117664:	0c012978 */ 	jal	func0004a5e0
/*  f117668:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f11766c:	27a40040 */ 	addiu	$a0,$sp,0x40
/*  f117670:	27a50048 */ 	addiu	$a1,$sp,0x48
/*  f117674:	0fc462b9 */ 	jal	func0f118ae4
/*  f117678:	27a60058 */ 	addiu	$a2,$sp,0x58
/*  f11767c:	8fa20064 */ 	lw	$v0,0x64($sp)
/*  f117680:	97b90058 */ 	lhu	$t9,0x58($sp)
/*  f117684:	97aa005a */ 	lhu	$t2,0x5a($sp)
/*  f117688:	94580000 */ 	lhu	$t8,0x0($v0)
/*  f11768c:	17190004 */ 	bne	$t8,$t9,.L0f1176a0
/*  f117690:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117694:	94490002 */ 	lhu	$t1,0x2($v0)
/*  f117698:	512a0004 */ 	beql	$t1,$t2,.L0f1176ac
/*  f11769c:	8c4b000c */ 	lw	$t3,0xc($v0)
.L0f1176a0:
/*  f1176a0:	1000002e */ 	beqz	$zero,.L0f11775c
/*  f1176a4:	24020007 */ 	addiu	$v0,$zero,0x7
/*  f1176a8:	8c4b000c */ 	lw	$t3,0xc($v0)
.L0f1176ac:
/*  f1176ac:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f1176b0:	3c057f1b */ 	lui	$a1,%hi(var7f1b3b80)
/*  f1176b4:	000b6f80 */ 	sll	$t5,$t3,0x1e
/*  f1176b8:	05a00003 */ 	bltz	$t5,.L0f1176c8
/*  f1176bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1176c0:	10000026 */ 	beqz	$zero,.L0f11775c
/*  f1176c4:	2402000f */ 	addiu	$v0,$zero,0xf
.L0f1176c8:
/*  f1176c8:	0c004c04 */ 	jal	func00013010
/*  f1176cc:	24a53b80 */ 	addiu	$a1,$a1,%lo(var7f1b3b80)
/*  f1176d0:	10400003 */ 	beqz	$v0,.L0f1176e0
/*  f1176d4:	8fae0064 */ 	lw	$t6,0x64($sp)
/*  f1176d8:	10000002 */ 	beqz	$zero,.L0f1176e4
/*  f1176dc:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f1176e0:
/*  f1176e0:	00002825 */ 	or	$a1,$zero,$zero
.L0f1176e4:
/*  f1176e4:	8dcf000c */ 	lw	$t7,0xc($t6)
/*  f1176e8:	3c198007 */ 	lui	$t9,0x8007
/*  f1176ec:	31f80001 */ 	andi	$t8,$t7,0x1
/*  f1176f0:	10b80003 */ 	beq	$a1,$t8,.L0f117700
/*  f1176f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1176f8:	10000018 */ 	beqz	$zero,.L0f11775c
/*  f1176fc:	24020009 */ 	addiu	$v0,$zero,0x9
.L0f117700:
/*  f117700:	8f395ce8 */ 	lw	$t9,0x5ce8($t9)
/*  f117704:	83a4007b */ 	lb	$a0,0x7b($sp)
/*  f117708:	8fa50060 */ 	lw	$a1,0x60($sp)
/*  f11770c:	5320000c */ 	beqzl	$t9,.L0f117740
/*  f117710:	8fa90064 */ 	lw	$t1,0x64($sp)
/*  f117714:	0fc46c5e */ 	jal	func0f11b178
/*  f117718:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f11771c:	83a4007b */ 	lb	$a0,0x7b($sp)
/*  f117720:	8fa50060 */ 	lw	$a1,0x60($sp)
/*  f117724:	0fc46d22 */ 	jal	func0f11b488
/*  f117728:	8fa60064 */ 	lw	$a2,0x64($sp)
/*  f11772c:	54400004 */ 	bnezl	$v0,.L0f117740
/*  f117730:	8fa90064 */ 	lw	$t1,0x64($sp)
/*  f117734:	10000009 */ 	beqz	$zero,.L0f11775c
/*  f117738:	2402000b */ 	addiu	$v0,$zero,0xb
.L0f11773c:
/*  f11773c:	8fa90064 */ 	lw	$t1,0x64($sp)
.L0f117740:
/*  f117740:	00001025 */ 	or	$v0,$zero,$zero
/*  f117744:	8d2a0008 */ 	lw	$t2,0x8($t1)
/*  f117748:	314b0fff */ 	andi	$t3,$t2,0xfff
/*  f11774c:	15600003 */ 	bnez	$t3,.L0f11775c
/*  f117750:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117754:	10000001 */ 	beqz	$zero,.L0f11775c
/*  f117758:	2402000b */ 	addiu	$v0,$zero,0xb
.L0f11775c:
/*  f11775c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f117760:	27bd0078 */ 	addiu	$sp,$sp,0x78
/*  f117764:	03e00008 */ 	jr	$ra
/*  f117768:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11776c
/*  f11776c:	27bdfdc0 */ 	addiu	$sp,$sp,-576
/*  f117770:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f117774:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f117778:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f11777c:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f117780:	00809025 */ 	or	$s2,$a0,$zero
/*  f117784:	27b3013c */ 	addiu	$s3,$sp,0x13c
/*  f117788:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f11778c:	3c057f1b */ 	lui	$a1,%hi(var7f1b3bb8)
/*  f117790:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f117794:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f117798:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f11779c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1177a0:	afa60248 */ 	sw	$a2,0x248($sp)
/*  f1177a4:	24a53bb8 */ 	addiu	$a1,$a1,%lo(var7f1b3bb8)
/*  f1177a8:	0c004dad */ 	jal	sprintf
/*  f1177ac:	02602025 */ 	or	$a0,$s3,$zero
/*  f1177b0:	12800017 */ 	beqz	$s4,.L0f117810
/*  f1177b4:	00008025 */ 	or	$s0,$zero,$zero
/*  f1177b8:	02408825 */ 	or	$s1,$s2,$zero
/*  f1177bc:	3c167f1b */ 	lui	$s6,%hi(var7f1b3bd0)
/*  f1177c0:	3c157f1b */ 	lui	$s5,%hi(var7f1b3bbc)
/*  f1177c4:	26b53bbc */ 	addiu	$s5,$s5,%lo(var7f1b3bbc)
/*  f1177c8:	26d63bd0 */ 	addiu	$s6,$s6,%lo(var7f1b3bd0)
/*  f1177cc:	27b2003c */ 	addiu	$s2,$sp,0x3c
.L0f1177d0:
/*  f1177d0:	320e000f */ 	andi	$t6,$s0,0xf
/*  f1177d4:	15c00004 */ 	bnez	$t6,.L0f1177e8
/*  f1177d8:	02602025 */ 	or	$a0,$s3,$zero
/*  f1177dc:	02a02825 */ 	or	$a1,$s5,$zero
/*  f1177e0:	0c004dad */ 	jal	sprintf
/*  f1177e4:	02003025 */ 	or	$a2,$s0,$zero
.L0f1177e8:
/*  f1177e8:	02402025 */ 	or	$a0,$s2,$zero
/*  f1177ec:	02c02825 */ 	or	$a1,$s6,$zero
/*  f1177f0:	0c004dad */ 	jal	sprintf
/*  f1177f4:	92260000 */ 	lbu	$a2,0x0($s1)
/*  f1177f8:	02602025 */ 	or	$a0,$s3,$zero
/*  f1177fc:	0c004c89 */ 	jal	func00013224
/*  f117800:	02402825 */ 	or	$a1,$s2,$zero
/*  f117804:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f117808:	1614fff1 */ 	bne	$s0,$s4,.L0f1177d0
/*  f11780c:	26310001 */ 	addiu	$s1,$s1,0x1
.L0f117810:
/*  f117810:	3c057f1b */ 	lui	$a1,%hi(var7f1b3bd8)
/*  f117814:	24a53bd8 */ 	addiu	$a1,$a1,%lo(var7f1b3bd8)
/*  f117818:	0c004c89 */ 	jal	func00013224
/*  f11781c:	02602025 */ 	or	$a0,$s3,$zero
/*  f117820:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f117824:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f117828:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f11782c:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f117830:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f117834:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f117838:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f11783c:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f117840:	03e00008 */ 	jr	$ra
/*  f117844:	27bd0240 */ 	addiu	$sp,$sp,0x240
);

GLOBAL_ASM(
glabel func0f117848
/*  f117848:	27bdf7e8 */ 	addiu	$sp,$sp,-2072
/*  f11784c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f117850:	0c00543a */ 	jal	func000150e8
/*  f117854:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117858:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*  f11785c:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*  f117860:	00002825 */ 	or	$a1,$zero,$zero
/*  f117864:	27a60018 */ 	addiu	$a2,$sp,0x18
/*  f117868:	0c0140fc */ 	jal	func000503f0
/*  f11786c:	24070800 */ 	addiu	$a3,$zero,0x800
/*  f117870:	0c005451 */ 	jal	func00015144
/*  f117874:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117878:	3c067f1b */ 	lui	$a2,%hi(var7f1b3bdc)
/*  f11787c:	24c63bdc */ 	addiu	$a2,$a2,%lo(var7f1b3bdc)
/*  f117880:	27a40018 */ 	addiu	$a0,$sp,0x18
/*  f117884:	0fc45ddb */ 	jal	func0f11776c
/*  f117888:	24050800 */ 	addiu	$a1,$zero,0x800
/*  f11788c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f117890:	27bd0818 */ 	addiu	$sp,$sp,0x818
/*  f117894:	03e00008 */ 	jr	$ra
/*  f117898:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11789c
/*  f11789c:	27bde780 */ 	addiu	$sp,$sp,-6272
/*  f1178a0:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f1178a4:	00048e00 */ 	sll	$s1,$a0,0x18
/*  f1178a8:	00117603 */ 	sra	$t6,$s1,0x18
/*  f1178ac:	afa41880 */ 	sw	$a0,0x1880($sp)
/*  f1178b0:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f1178b4:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f1178b8:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f1178bc:	afa61888 */ 	sw	$a2,0x1888($sp)
/*  f1178c0:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f1178c4:	00a09025 */ 	or	$s2,$a1,$zero
/*  f1178c8:	01c08825 */ 	or	$s1,$t6,$zero
/*  f1178cc:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f1178d0:	afa7188c */ 	sw	$a3,0x188c($sp)
/*  f1178d4:	afa0084c */ 	sw	$zero,0x84c($sp)
/*  f1178d8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f1178dc:	0fc464da */ 	jal	func0f119368
/*  f1178e0:	27a61870 */ 	addiu	$a2,$sp,0x1870
/*  f1178e4:	10400015 */ 	beqz	$v0,.L0f11793c
/*  f1178e8:	afa21858 */ 	sw	$v0,0x1858($sp)
/*  f1178ec:	10400011 */ 	beqz	$v0,.L0f117934
/*  f1178f0:	00112600 */ 	sll	$a0,$s1,0x18
/*  f1178f4:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f1178f8:	0fc45ff0 */ 	jal	func0f117fc0
/*  f1178fc:	03002025 */ 	or	$a0,$t8,$zero
/*  f117900:	8fb91858 */ 	lw	$t9,0x1858($sp)
/*  f117904:	00112600 */ 	sll	$a0,$s1,0x18
/*  f117908:	00044603 */ 	sra	$t0,$a0,0x18
/*  f11790c:	0322082b */ 	sltu	$at,$t9,$v0
/*  f117910:	10200008 */ 	beqz	$at,.L0f117934
/*  f117914:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117918:	0fc45974 */ 	jal	func0f1165d0
/*  f11791c:	01002025 */ 	or	$a0,$t0,$zero
/*  f117920:	8faa1858 */ 	lw	$t2,0x1858($sp)
/*  f117924:	2449ffff */ 	addiu	$t1,$v0,-1
/*  f117928:	012a5824 */ 	and	$t3,$t1,$t2
/*  f11792c:	51600004 */ 	beqzl	$t3,.L0f117940
/*  f117930:	8fa51878 */ 	lw	$a1,0x1878($sp)
.L0f117934:
/*  f117934:	1000006d */ 	beqz	$zero,.L0f117aec
/*  f117938:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f11793c:
/*  f11793c:	8fa51878 */ 	lw	$a1,0x1878($sp)
.L0f117940:
/*  f117940:	8fad1888 */ 	lw	$t5,0x1888($sp)
/*  f117944:	00112600 */ 	sll	$a0,$s1,0x18
/*  f117948:	000565c2 */ 	srl	$t4,$a1,0x17
/*  f11794c:	11ac0003 */ 	beq	$t5,$t4,.L0f11795c
/*  f117950:	01802825 */ 	or	$a1,$t4,$zero
/*  f117954:	10000065 */ 	beqz	$zero,.L0f117aec
/*  f117958:	2402000c */ 	addiu	$v0,$zero,0xc
.L0f11795c:
/*  f11795c:	00047603 */ 	sra	$t6,$a0,0x18
/*  f117960:	01c02025 */ 	or	$a0,$t6,$zero
/*  f117964:	0fc459ec */ 	jal	func0f1167b0
/*  f117968:	27a60850 */ 	addiu	$a2,$sp,0x850
/*  f11796c:	8faf0850 */ 	lw	$t7,0x850($sp)
/*  f117970:	3c10eeee */ 	lui	$s0,0xeeee
/*  f117974:	3610eeee */ 	ori	$s0,$s0,0xeeee
/*  f117978:	11e0001b */ 	beqz	$t7,.L0f1179e8
/*  f11797c:	27a30850 */ 	addiu	$v1,$sp,0x850
/*  f117980:	8c650000 */ 	lw	$a1,0x0($v1)
/*  f117984:	00112600 */ 	sll	$a0,$s1,0x18
.L0f117988:
/*  f117988:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f11798c:	03202025 */ 	or	$a0,$t9,$zero
/*  f117990:	27a61860 */ 	addiu	$a2,$sp,0x1860
/*  f117994:	0fc464da */ 	jal	func0f119368
/*  f117998:	afa30048 */ 	sw	$v1,0x48($sp)
/*  f11799c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1179a0:	8fa30048 */ 	lw	$v1,0x48($sp)
/*  f1179a4:	14410003 */ 	bne	$v0,$at,.L0f1179b4
/*  f1179a8:	00408025 */ 	or	$s0,$v0,$zero
/*  f1179ac:	1000004f */ 	beqz	$zero,.L0f117aec
/*  f1179b0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1179b4:
/*  f1179b4:	8fa4186c */ 	lw	$a0,0x186c($sp)
/*  f1179b8:	00044f40 */ 	sll	$t1,$a0,0x1d
/*  f1179bc:	05200006 */ 	bltz	$t1,.L0f1179d8
/*  f1179c0:	00041340 */ 	sll	$v0,$a0,0xd
/*  f1179c4:	00025642 */ 	srl	$t2,$v0,0x19
/*  f1179c8:	524a0004 */ 	beql	$s2,$t2,.L0f1179dc
/*  f1179cc:	8c650004 */ 	lw	$a1,0x4($v1)
/*  f1179d0:	10000005 */ 	beqz	$zero,.L0f1179e8
/*  f1179d4:	afaa084c */ 	sw	$t2,0x84c($sp)
.L0f1179d8:
/*  f1179d8:	8c650004 */ 	lw	$a1,0x4($v1)
.L0f1179dc:
/*  f1179dc:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f1179e0:	54a0ffe9 */ 	bnezl	$a1,.L0f117988
/*  f1179e4:	00112600 */ 	sll	$a0,$s1,0x18
.L0f1179e8:
/*  f1179e8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1179ec:	16210011 */ 	bne	$s1,$at,.L0f117a34
/*  f1179f0:	00112600 */ 	sll	$a0,$s1,0x18
/*  f1179f4:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f1179f8:	01602025 */ 	or	$a0,$t3,$zero
/*  f1179fc:	8fa5084c */ 	lw	$a1,0x84c($sp)
/*  f117a00:	27a6004c */ 	addiu	$a2,$sp,0x4c
/*  f117a04:	0fc45a00 */ 	jal	func0f116800
/*  f117a08:	2407ffff */ 	addiu	$a3,$zero,-1
/*  f117a0c:	14400003 */ 	bnez	$v0,.L0f117a1c
/*  f117a10:	27a3004c */ 	addiu	$v1,$sp,0x4c
/*  f117a14:	10000007 */ 	beqz	$zero,.L0f117a34
/*  f117a18:	afa31894 */ 	sw	$v1,0x1894($sp)
.L0f117a1c:
/*  f117a1c:	2401000a */ 	addiu	$at,$zero,0xa
/*  f117a20:	54410004 */ 	bnel	$v0,$at,.L0f117a34
/*  f117a24:	afa01894 */ 	sw	$zero,0x1894($sp)
/*  f117a28:	10000002 */ 	beqz	$zero,.L0f117a34
/*  f117a2c:	afa31894 */ 	sw	$v1,0x1894($sp)
/*  f117a30:	afa01894 */ 	sw	$zero,0x1894($sp)
.L0f117a34:
/*  f117a34:	8faf187c */ 	lw	$t7,0x187c($sp)
/*  f117a38:	8fad1890 */ 	lw	$t5,0x1890($sp)
/*  f117a3c:	8fae1894 */ 	lw	$t6,0x1894($sp)
/*  f117a40:	000fc500 */ 	sll	$t8,$t7,0x14
/*  f117a44:	0018cdc2 */ 	srl	$t9,$t8,0x17
/*  f117a48:	00112600 */ 	sll	$a0,$s1,0x18
/*  f117a4c:	00046603 */ 	sra	$t4,$a0,0x18
/*  f117a50:	27280001 */ 	addiu	$t0,$t9,0x1
/*  f117a54:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f117a58:	01802025 */ 	or	$a0,$t4,$zero
/*  f117a5c:	02002825 */ 	or	$a1,$s0,$zero
/*  f117a60:	8fa61888 */ 	lw	$a2,0x1888($sp)
/*  f117a64:	8fa7188c */ 	lw	$a3,0x188c($sp)
/*  f117a68:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f117a6c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f117a70:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f117a74:	0fc46f15 */ 	jal	func0f11bc54
/*  f117a78:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f117a7c:	10400003 */ 	beqz	$v0,.L0f117a8c
/*  f117a80:	8fa51858 */ 	lw	$a1,0x1858($sp)
/*  f117a84:	10000019 */ 	beqz	$zero,.L0f117aec
/*  f117a88:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f117a8c:
/*  f117a8c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f117a90:	54a10004 */ 	bnel	$a1,$at,.L0f117aa4
/*  f117a94:	3c01eeee */ 	lui	$at,0xeeee
/*  f117a98:	10000014 */ 	beqz	$zero,.L0f117aec
/*  f117a9c:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f117aa0:	3c01eeee */ 	lui	$at,0xeeee
.L0f117aa4:
/*  f117aa4:	3421eeee */ 	ori	$at,$at,0xeeee
/*  f117aa8:	10a1000f */ 	beq	$a1,$at,.L0f117ae8
/*  f117aac:	00112600 */ 	sll	$a0,$s1,0x18
/*  f117ab0:	8fab187c */ 	lw	$t3,0x187c($sp)
/*  f117ab4:	8faa084c */ 	lw	$t2,0x84c($sp)
/*  f117ab8:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f117abc:	000b6500 */ 	sll	$t4,$t3,0x14
/*  f117ac0:	000c6dc2 */ 	srl	$t5,$t4,0x17
/*  f117ac4:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f117ac8:	01202025 */ 	or	$a0,$t1,$zero
/*  f117acc:	8fa61888 */ 	lw	$a2,0x1888($sp)
/*  f117ad0:	00003825 */ 	or	$a3,$zero,$zero
/*  f117ad4:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f117ad8:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f117adc:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f117ae0:	0fc46f15 */ 	jal	func0f11bc54
/*  f117ae4:	afaa001c */ 	sw	$t2,0x1c($sp)
.L0f117ae8:
/*  f117ae8:	00001025 */ 	or	$v0,$zero,$zero
.L0f117aec:
/*  f117aec:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f117af0:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f117af4:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f117af8:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f117afc:	03e00008 */ 	jr	$ra
/*  f117b00:	27bd1880 */ 	addiu	$sp,$sp,0x1880
);

GLOBAL_ASM(
glabel func0f117b04
/*  f117b04:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f117b08:	10a00005 */ 	beqz	$a1,.L0f117b20
/*  f117b0c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f117b10:	0c001b58 */ 	jal	func00006d60
/*  f117b14:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117b18:	10000009 */ 	beqz	$zero,.L0f117b40
/*  f117b1c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f117b20:
/*  f117b20:	3c0e8007 */ 	lui	$t6,0x8007
/*  f117b24:	8dce5cd0 */ 	lw	$t6,0x5cd0($t6)
/*  f117b28:	00001025 */ 	or	$v0,$zero,$zero
/*  f117b2c:	15c00003 */ 	bnez	$t6,.L0f117b3c
/*  f117b30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117b34:	10000001 */ 	beqz	$zero,.L0f117b3c
/*  f117b38:	24020080 */ 	addiu	$v0,$zero,0x80
.L0f117b3c:
/*  f117b3c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f117b40:
/*  f117b40:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f117b44:	03e00008 */ 	jr	$ra
/*  f117b48:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f117b4c
/*  f117b4c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f117b50:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f117b54:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f117b58:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f117b5c:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f117b60:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f117b64:	0c004eae */ 	jal	func00013ab8
/*  f117b68:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f117b6c:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f117b70:	93a6002b */ 	lbu	$a2,0x2b($sp)
/*  f117b74:	8fa7002c */ 	lw	$a3,0x2c($sp)
/*  f117b78:	10800009 */ 	beqz	$a0,.L0f117ba0
/*  f117b7c:	3c188007 */ 	lui	$t8,0x8007
/*  f117b80:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f117b84:	8faf0034 */ 	lw	$t7,0x34($sp)
/*  f117b88:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f117b8c:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f117b90:	0c014155 */ 	jal	func00050554
/*  f117b94:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f117b98:	10000019 */ 	beqz	$zero,.L0f117c00
/*  f117b9c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f117ba0:
/*  f117ba0:	8f185cd0 */ 	lw	$t8,0x5cd0($t8)
/*  f117ba4:	000718c2 */ 	srl	$v1,$a3,0x3
/*  f117ba8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f117bac:	17000003 */ 	bnez	$t8,.L0f117bbc
/*  f117bb0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117bb4:	10000011 */ 	beqz	$zero,.L0f117bfc
/*  f117bb8:	24020080 */ 	addiu	$v0,$zero,0x80
.L0f117bbc:
/*  f117bbc:	14c10007 */ 	bne	$a2,$at,.L0f117bdc
/*  f117bc0:	00c01025 */ 	or	$v0,$a2,$zero
/*  f117bc4:	306400ff */ 	andi	$a0,$v1,0xff
/*  f117bc8:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f117bcc:	0fc47935 */ 	jal	func0f11e4d4
/*  f117bd0:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f117bd4:	1000000a */ 	beqz	$zero,.L0f117c00
/*  f117bd8:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f117bdc:
/*  f117bdc:	14400006 */ 	bnez	$v0,.L0f117bf8
/*  f117be0:	306400ff */ 	andi	$a0,$v1,0xff
/*  f117be4:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f117be8:	0fc4791e */ 	jal	func0f11e478
/*  f117bec:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f117bf0:	10000003 */ 	beqz	$zero,.L0f117c00
/*  f117bf4:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f117bf8:
/*  f117bf8:	24020083 */ 	addiu	$v0,$zero,0x83
.L0f117bfc:
/*  f117bfc:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f117c00:
/*  f117c00:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f117c04:	03e00008 */ 	jr	$ra
/*  f117c08:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f117c0c
/*  f117c0c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f117c10:	1080000d */ 	beqz	$a0,.L0f117c48
/*  f117c14:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f117c18:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f117c1c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f117c20:	0c00543a */ 	jal	func000150e8
/*  f117c24:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f117c28:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f117c2c:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f117c30:	0c014234 */ 	jal	func000508d0
/*  f117c34:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f117c38:	0c005451 */ 	jal	func00015144
/*  f117c3c:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f117c40:	1000000b */ 	beqz	$zero,.L0f117c70
/*  f117c44:	8fa2001c */ 	lw	$v0,0x1c($sp)
.L0f117c48:
/*  f117c48:	3c0e8007 */ 	lui	$t6,0x8007
/*  f117c4c:	8dce5cd0 */ 	lw	$t6,0x5cd0($t6)
/*  f117c50:	24030001 */ 	addiu	$v1,$zero,0x1
/*  f117c54:	00001025 */ 	or	$v0,$zero,$zero
/*  f117c58:	55c00004 */ 	bnezl	$t6,.L0f117c6c
/*  f117c5c:	aca30000 */ 	sw	$v1,0x0($a1)
/*  f117c60:	10000003 */ 	beqz	$zero,.L0f117c70
/*  f117c64:	24020080 */ 	addiu	$v0,$zero,0x80
/*  f117c68:	aca30000 */ 	sw	$v1,0x0($a1)
.L0f117c6c:
/*  f117c6c:	acc30000 */ 	sw	$v1,0x0($a2)
.L0f117c70:
/*  f117c70:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f117c74:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f117c78:	03e00008 */ 	jr	$ra
/*  f117c7c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f117c80
/*  f117c80:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f117c84:	1080000b */ 	beqz	$a0,.L0f117cb4
/*  f117c88:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f117c8c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f117c90:	0c00543a */ 	jal	func000150e8
/*  f117c94:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f117c98:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f117c9c:	0c013398 */ 	jal	func0004ce60
/*  f117ca0:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f117ca4:	0c005451 */ 	jal	func00015144
/*  f117ca8:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f117cac:	10000009 */ 	beqz	$zero,.L0f117cd4
/*  f117cb0:	8fa2001c */ 	lw	$v0,0x1c($sp)
.L0f117cb4:
/*  f117cb4:	3c0e8007 */ 	lui	$t6,0x8007
/*  f117cb8:	8dce5cd0 */ 	lw	$t6,0x5cd0($t6)
/*  f117cbc:	00001025 */ 	or	$v0,$zero,$zero
/*  f117cc0:	55c00004 */ 	bnezl	$t6,.L0f117cd4
/*  f117cc4:	aca00000 */ 	sw	$zero,0x0($a1)
/*  f117cc8:	10000002 */ 	beqz	$zero,.L0f117cd4
/*  f117ccc:	24020080 */ 	addiu	$v0,$zero,0x80
/*  f117cd0:	aca00000 */ 	sw	$zero,0x0($a1)
.L0f117cd4:
/*  f117cd4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f117cd8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f117cdc:	03e00008 */ 	jr	$ra
/*  f117ce0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f117ce4
/*  f117ce4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f117ce8:	1080000d */ 	beqz	$a0,.L0f117d20
/*  f117cec:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f117cf0:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f117cf4:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f117cf8:	0c00543a */ 	jal	func000150e8
/*  f117cfc:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f117d00:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f117d04:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f117d08:	0c014280 */ 	jal	func00050a00
/*  f117d0c:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f117d10:	0c005451 */ 	jal	func00015144
/*  f117d14:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f117d18:	10000019 */ 	beqz	$zero,.L0f117d80
/*  f117d1c:	8fa2001c */ 	lw	$v0,0x1c($sp)
.L0f117d20:
/*  f117d20:	3c0e8007 */ 	lui	$t6,0x8007
/*  f117d24:	8dce5cd0 */ 	lw	$t6,0x5cd0($t6)
/*  f117d28:	15c00003 */ 	bnez	$t6,.L0f117d38
/*  f117d2c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117d30:	10000013 */ 	beqz	$zero,.L0f117d80
/*  f117d34:	24020080 */ 	addiu	$v0,$zero,0x80
.L0f117d38:
/*  f117d38:	10a00003 */ 	beqz	$a1,.L0f117d48
/*  f117d3c:	240f0800 */ 	addiu	$t7,$zero,0x800
/*  f117d40:	1000000f */ 	beqz	$zero,.L0f117d80
/*  f117d44:	24020084 */ 	addiu	$v0,$zero,0x84
.L0f117d48:
/*  f117d48:	24183459 */ 	addiu	$t8,$zero,0x3459
/*  f117d4c:	accf0000 */ 	sw	$t7,0x0($a2)
/*  f117d50:	a4d80008 */ 	sh	$t8,0x8($a2)
/*  f117d54:	3c058007 */ 	lui	$a1,%hi(var80075cf8)
/*  f117d58:	24a55cf8 */ 	addiu	$a1,$a1,%lo(var80075cf8)
/*  f117d5c:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f117d60:	0c004c4c */ 	jal	strcpy
/*  f117d64:	24c4000e */ 	addiu	$a0,$a2,0xe
/*  f117d68:	8fa60028 */ 	lw	$a2,0x28($sp)
/*  f117d6c:	3c058007 */ 	lui	$a1,%hi(var80075d08)
/*  f117d70:	24a55d08 */ 	addiu	$a1,$a1,%lo(var80075d08)
/*  f117d74:	0c004c4c */ 	jal	strcpy
/*  f117d78:	24c4000a */ 	addiu	$a0,$a2,0xa
/*  f117d7c:	00001025 */ 	or	$v0,$zero,$zero
.L0f117d80:
/*  f117d80:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f117d84:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f117d88:	03e00008 */ 	jr	$ra
/*  f117d8c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f117d90
/*  f117d90:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f117d94:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f117d98:	30aeffff */ 	andi	$t6,$a1,0xffff
/*  f117d9c:	01c02825 */ 	or	$a1,$t6,$zero
/*  f117da0:	1080000a */ 	beqz	$a0,.L0f117dcc
/*  f117da4:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f117da8:	8faf0038 */ 	lw	$t7,0x38($sp)
/*  f117dac:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f117db0:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f117db4:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f117db8:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f117dbc:	0c013400 */ 	jal	func0004d000
/*  f117dc0:	afb90018 */ 	sw	$t9,0x18($sp)
/*  f117dc4:	1000000b */ 	beqz	$zero,.L0f117df4
/*  f117dc8:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f117dcc:
/*  f117dcc:	3c088007 */ 	lui	$t0,0x8007
/*  f117dd0:	8d085cd0 */ 	lw	$t0,0x5cd0($t0)
/*  f117dd4:	8fa90040 */ 	lw	$t1,0x40($sp)
/*  f117dd8:	00001025 */ 	or	$v0,$zero,$zero
/*  f117ddc:	55000004 */ 	bnezl	$t0,.L0f117df0
/*  f117de0:	ad200000 */ 	sw	$zero,0x0($t1)
/*  f117de4:	10000002 */ 	beqz	$zero,.L0f117df0
/*  f117de8:	24020080 */ 	addiu	$v0,$zero,0x80
/*  f117dec:	ad200000 */ 	sw	$zero,0x0($t1)
.L0f117df0:
/*  f117df0:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f117df4:
/*  f117df4:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f117df8:	03e00008 */ 	jr	$ra
/*  f117dfc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f117e00
/*  f117e00:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f117e04:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f117e08:	30aeffff */ 	andi	$t6,$a1,0xffff
/*  f117e0c:	01c02825 */ 	or	$a1,$t6,$zero
/*  f117e10:	10800006 */ 	beqz	$a0,.L0f117e2c
/*  f117e14:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f117e18:	8faf0030 */ 	lw	$t7,0x30($sp)
/*  f117e1c:	0c013520 */ 	jal	func0004d480
/*  f117e20:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f117e24:	10000009 */ 	beqz	$zero,.L0f117e4c
/*  f117e28:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f117e2c:
/*  f117e2c:	3c188007 */ 	lui	$t8,0x8007
/*  f117e30:	8f185cd0 */ 	lw	$t8,0x5cd0($t8)
/*  f117e34:	00001025 */ 	or	$v0,$zero,$zero
/*  f117e38:	17000003 */ 	bnez	$t8,.L0f117e48
/*  f117e3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117e40:	10000001 */ 	beqz	$zero,.L0f117e48
/*  f117e44:	24020080 */ 	addiu	$v0,$zero,0x80
.L0f117e48:
/*  f117e48:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f117e4c:
/*  f117e4c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f117e50:	03e00008 */ 	jr	$ra
/*  f117e54:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f117e58
/*  f117e58:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f117e5c:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f117e60:	30aeffff */ 	andi	$t6,$a1,0xffff
/*  f117e64:	01c02825 */ 	or	$a1,$t6,$zero
/*  f117e68:	10800008 */ 	beqz	$a0,.L0f117e8c
/*  f117e6c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f117e70:	8faf0030 */ 	lw	$t7,0x30($sp)
/*  f117e74:	8fb80034 */ 	lw	$t8,0x34($sp)
/*  f117e78:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f117e7c:	0c013304 */ 	jal	func0004cc10
/*  f117e80:	afb80014 */ 	sw	$t8,0x14($sp)
/*  f117e84:	1000000b */ 	beqz	$zero,.L0f117eb4
/*  f117e88:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f117e8c:
/*  f117e8c:	3c198007 */ 	lui	$t9,0x8007
/*  f117e90:	8f395cd0 */ 	lw	$t9,0x5cd0($t9)
/*  f117e94:	8fa80034 */ 	lw	$t0,0x34($sp)
/*  f117e98:	24020080 */ 	addiu	$v0,$zero,0x80
/*  f117e9c:	13200004 */ 	beqz	$t9,.L0f117eb0
/*  f117ea0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117ea4:	ad000000 */ 	sw	$zero,0x0($t0)
/*  f117ea8:	10000001 */ 	beqz	$zero,.L0f117eb0
/*  f117eac:	00001025 */ 	or	$v0,$zero,$zero
.L0f117eb0:
/*  f117eb0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f117eb4:
/*  f117eb4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f117eb8:	03e00008 */ 	jr	$ra
/*  f117ebc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f117ec0
/*  f117ec0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f117ec4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f117ec8:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f117ecc:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f117ed0:	10800010 */ 	beqz	$a0,.L0f117f14
/*  f117ed4:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f117ed8:	0c00543a */ 	jal	func000150e8
/*  f117edc:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f117ee0:	8fae0038 */ 	lw	$t6,0x38($sp)
/*  f117ee4:	8faf003c */ 	lw	$t7,0x3c($sp)
/*  f117ee8:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f117eec:	97a5002e */ 	lhu	$a1,0x2e($sp)
/*  f117ef0:	8fa60030 */ 	lw	$a2,0x30($sp)
/*  f117ef4:	8fa70034 */ 	lw	$a3,0x34($sp)
/*  f117ef8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f117efc:	0c001954 */ 	jal	func00006550
/*  f117f00:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f117f04:	0c005451 */ 	jal	func00015144
/*  f117f08:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f117f0c:	10000008 */ 	beqz	$zero,.L0f117f30
/*  f117f10:	8fa20024 */ 	lw	$v0,0x24($sp)
.L0f117f14:
/*  f117f14:	3c188007 */ 	lui	$t8,0x8007
/*  f117f18:	8f185cd0 */ 	lw	$t8,0x5cd0($t8)
/*  f117f1c:	00001025 */ 	or	$v0,$zero,$zero
/*  f117f20:	17000003 */ 	bnez	$t8,.L0f117f30
/*  f117f24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117f28:	10000001 */ 	beqz	$zero,.L0f117f30
/*  f117f2c:	24020080 */ 	addiu	$v0,$zero,0x80
.L0f117f30:
/*  f117f30:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f117f34:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f117f38:	03e00008 */ 	jr	$ra
/*  f117f3c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f117f40:	00047600 */ 	sll	$t6,$a0,0x18
/*  f117f44:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f117f48:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f117f4c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117f50:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117f54:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117f58:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117f5c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f117f60:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117f64:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117f68:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117f6c:	3c02800a */ 	lui	$v0,0x800a
/*  f117f70:	00581021 */ 	addu	$v0,$v0,$t8
/*  f117f74:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f117f78:	03e00008 */ 	jr	$ra
/*  f117f7c:	8c422624 */ 	lw	$v0,0x2624($v0)
);

GLOBAL_ASM(
glabel func0f117f80
/*  f117f80:	00047600 */ 	sll	$t6,$a0,0x18
/*  f117f84:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f117f88:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f117f8c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117f90:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117f94:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117f98:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117f9c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f117fa0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117fa4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117fa8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117fac:	3c02800a */ 	lui	$v0,0x800a
/*  f117fb0:	00581021 */ 	addu	$v0,$v0,$t8
/*  f117fb4:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f117fb8:	03e00008 */ 	jr	$ra
/*  f117fbc:	8c422628 */ 	lw	$v0,0x2628($v0)
);

GLOBAL_ASM(
glabel func0f117fc0
/*  f117fc0:	00047600 */ 	sll	$t6,$a0,0x18
/*  f117fc4:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f117fc8:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f117fcc:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117fd0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117fd4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117fd8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117fdc:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f117fe0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117fe4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f117fe8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f117fec:	3c02800a */ 	lui	$v0,0x800a
/*  f117ff0:	00581021 */ 	addu	$v0,$v0,$t8
/*  f117ff4:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f117ff8:	03e00008 */ 	jr	$ra
/*  f117ffc:	8c422620 */ 	lw	$v0,0x2620($v0)
);

GLOBAL_ASM(
glabel func0f118000
/*  f118000:	00042e00 */ 	sll	$a1,$a0,0x18
/*  f118004:	00057603 */ 	sra	$t6,$a1,0x18
/*  f118008:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f11800c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f118010:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f118014:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f118018:	15c10003 */ 	bne	$t6,$at,.L0f118028
/*  f11801c:	01c02825 */ 	or	$a1,$t6,$zero
/*  f118020:	10000009 */ 	beqz	$zero,.L0f118048
/*  f118024:	00002025 */ 	or	$a0,$zero,$zero
.L0f118028:
/*  f118028:	00057880 */ 	sll	$t7,$a1,0x2
/*  f11802c:	01e57823 */ 	subu	$t7,$t7,$a1
/*  f118030:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f118034:	01e57821 */ 	addu	$t7,$t7,$a1
/*  f118038:	3c18800a */ 	lui	$t8,%hi(var800a3180)
/*  f11803c:	27183180 */ 	addiu	$t8,$t8,%lo(var800a3180)
/*  f118040:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f118044:	01f82021 */ 	addu	$a0,$t7,$t8
.L0f118048:
/*  f118048:	0fc45f20 */ 	jal	func0f117c80
/*  f11804c:	27a5001c */ 	addiu	$a1,$sp,0x1c
/*  f118050:	8fa2001c */ 	lw	$v0,0x1c($sp)
/*  f118054:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f118058:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f11805c:	04410003 */ 	bgez	$v0,.L0f11806c
/*  f118060:	0002ca03 */ 	sra	$t9,$v0,0x8
/*  f118064:	244100ff */ 	addiu	$at,$v0,0xff
/*  f118068:	0001ca03 */ 	sra	$t9,$at,0x8
.L0f11806c:
/*  f11806c:	03e00008 */ 	jr	$ra
/*  f118070:	03201025 */ 	or	$v0,$t9,$zero
/*  f118074:	03e00008 */ 	jr	$ra
/*  f118078:	2402001c */ 	addiu	$v0,$zero,0x1c
);

GLOBAL_ASM(
glabel func0f11807c
/*  f11807c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f118080:	00047600 */ 	sll	$t6,$a0,0x18
/*  f118084:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f118088:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f11808c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f118090:	01e02025 */ 	or	$a0,$t7,$zero
/*  f118094:	11e10027 */ 	beq	$t7,$at,.L0f118134
/*  f118098:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11809c:	0fc45c1b */ 	jal	func0f11706c
/*  f1180a0:	a3af0023 */ 	sb	$t7,0x23($sp)
/*  f1180a4:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f1180a8:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f1180ac:	00003025 */ 	or	$a2,$zero,$zero
/*  f1180b0:	0fc4642f */ 	jal	func0f1190bc
/*  f1180b4:	afa20018 */ 	sw	$v0,0x18($sp)
/*  f1180b8:	14400003 */ 	bnez	$v0,.L0f1180c8
/*  f1180bc:	8fa70018 */ 	lw	$a3,0x18($sp)
/*  f1180c0:	1000001d */ 	beqz	$zero,.L0f118138
/*  f1180c4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1180c8:
/*  f1180c8:	00071202 */ 	srl	$v0,$a3,0x8
/*  f1180cc:	30f800ff */ 	andi	$t8,$a3,0xff
/*  f1180d0:	13000002 */ 	beqz	$t8,.L0f1180dc
/*  f1180d4:	00401825 */ 	or	$v1,$v0,$zero
/*  f1180d8:	24430001 */ 	addiu	$v1,$v0,0x1
.L0f1180dc:
/*  f1180dc:	83b90023 */ 	lb	$t9,0x23($sp)
/*  f1180e0:	3c09800a */ 	lui	$t1,%hi(var800a2380)
/*  f1180e4:	25292380 */ 	addiu	$t1,$t1,%lo(var800a2380)
/*  f1180e8:	00194080 */ 	sll	$t0,$t9,0x2
/*  f1180ec:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1180f0:	00084080 */ 	sll	$t0,$t0,0x2
/*  f1180f4:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1180f8:	00084080 */ 	sll	$t0,$t0,0x2
/*  f1180fc:	01194021 */ 	addu	$t0,$t0,$t9
/*  f118100:	00084080 */ 	sll	$t0,$t0,0x2
/*  f118104:	01194023 */ 	subu	$t0,$t0,$t9
/*  f118108:	00084080 */ 	sll	$t0,$t0,0x2
/*  f11810c:	01092021 */ 	addu	$a0,$t0,$t1
/*  f118110:	948a0258 */ 	lhu	$t2,0x258($a0)
/*  f118114:	01435821 */ 	addu	$t3,$t2,$v1
/*  f118118:	29610080 */ 	slti	$at,$t3,0x80
/*  f11811c:	50200006 */ 	beqzl	$at,.L0f118138
/*  f118120:	00001025 */ 	or	$v0,$zero,$zero
/*  f118124:	948c025a */ 	lhu	$t4,0x25a($a0)
/*  f118128:	0183102a */ 	slt	$v0,$t4,$v1
/*  f11812c:	10000002 */ 	beqz	$zero,.L0f118138
/*  f118130:	38420001 */ 	xori	$v0,$v0,0x1
.L0f118134:
/*  f118134:	00001025 */ 	or	$v0,$zero,$zero
.L0f118138:
/*  f118138:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11813c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f118140:	03e00008 */ 	jr	$ra
/*  f118144:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f118148
/*  f118148:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f11814c:	00047600 */ 	sll	$t6,$a0,0x18
/*  f118150:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f118154:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f118158:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11815c:	01e02025 */ 	or	$a0,$t7,$zero
/*  f118160:	11e1002e */ 	beq	$t7,$at,.L0f11821c
/*  f118164:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f118168:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f11816c:	0fc45c1b */ 	jal	func0f11706c
/*  f118170:	a3af002b */ 	sb	$t7,0x2b($sp)
/*  f118174:	83a4002b */ 	lb	$a0,0x2b($sp)
/*  f118178:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f11817c:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f118180:	0fc4642f */ 	jal	func0f1190bc
/*  f118184:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f118188:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f11818c:	83b9002b */ 	lb	$t9,0x2b($sp)
/*  f118190:	3c09800a */ 	lui	$t1,0x800a
/*  f118194:	00032a02 */ 	srl	$a1,$v1,0x8
/*  f118198:	307800ff */ 	andi	$t8,$v1,0xff
/*  f11819c:	13000002 */ 	beqz	$t8,.L0f1181a8
/*  f1181a0:	00a02025 */ 	or	$a0,$a1,$zero
/*  f1181a4:	24a40001 */ 	addiu	$a0,$a1,0x1
.L0f1181a8:
/*  f1181a8:	00194080 */ 	sll	$t0,$t9,0x2
/*  f1181ac:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1181b0:	00084080 */ 	sll	$t0,$t0,0x2
/*  f1181b4:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1181b8:	00084080 */ 	sll	$t0,$t0,0x2
/*  f1181bc:	01194021 */ 	addu	$t0,$t0,$t9
/*  f1181c0:	00084080 */ 	sll	$t0,$t0,0x2
/*  f1181c4:	01194023 */ 	subu	$t0,$t0,$t9
/*  f1181c8:	00084080 */ 	sll	$t0,$t0,0x2
/*  f1181cc:	01284821 */ 	addu	$t1,$t1,$t0
/*  f1181d0:	952925d8 */ 	lhu	$t1,0x25d8($t1)
/*  f1181d4:	240a0080 */ 	addiu	$t2,$zero,0x80
/*  f1181d8:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f1181dc:	01495823 */ 	subu	$t3,$t2,$t1
/*  f1181e0:	0164001a */ 	div	$zero,$t3,$a0
/*  f1181e4:	00006012 */ 	mflo	$t4
/*  f1181e8:	006c1821 */ 	addu	$v1,$v1,$t4
/*  f1181ec:	14800002 */ 	bnez	$a0,.L0f1181f8
/*  f1181f0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1181f4:	0007000d */ 	break	0x7
.L0f1181f8:
/*  f1181f8:	2401ffff */ 	addiu	$at,$zero,-1
/*  f1181fc:	14810004 */ 	bne	$a0,$at,.L0f118210
/*  f118200:	3c018000 */ 	lui	$at,0x8000
/*  f118204:	15610002 */ 	bne	$t3,$at,.L0f118210
/*  f118208:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11820c:	0006000d */ 	break	0x6
.L0f118210:
/*  f118210:	00601025 */ 	or	$v0,$v1,$zero
/*  f118214:	10000003 */ 	beqz	$zero,.L0f118224
/*  f118218:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f11821c:
/*  f11821c:	00001025 */ 	or	$v0,$zero,$zero
/*  f118220:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f118224:
/*  f118224:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f118228:	03e00008 */ 	jr	$ra
/*  f11822c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f118230
/*  f118230:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f118234:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f118238:	00048600 */ 	sll	$s0,$a0,0x18
/*  f11823c:	00107603 */ 	sra	$t6,$s0,0x18
/*  f118240:	24010004 */ 	addiu	$at,$zero,0x4
/*  f118244:	01c08025 */ 	or	$s0,$t6,$zero
/*  f118248:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11824c:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f118250:	11c10032 */ 	beq	$t6,$at,.L0f11831c
/*  f118254:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f118258:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f11825c:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f118260:	0fc4601f */ 	jal	func0f11807c
/*  f118264:	01e02025 */ 	or	$a0,$t7,$zero
/*  f118268:	1040002c */ 	beqz	$v0,.L0f11831c
/*  f11826c:	00102600 */ 	sll	$a0,$s0,0x18
/*  f118270:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f118274:	0fc45c1b */ 	jal	func0f11706c
/*  f118278:	03002025 */ 	or	$a0,$t8,$zero
/*  f11827c:	00102600 */ 	sll	$a0,$s0,0x18
/*  f118280:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f118284:	afa20020 */ 	sw	$v0,0x20($sp)
/*  f118288:	03202025 */ 	or	$a0,$t9,$zero
/*  f11828c:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f118290:	0fc4642f */ 	jal	func0f1190bc
/*  f118294:	00003025 */ 	or	$a2,$zero,$zero
/*  f118298:	10400014 */ 	beqz	$v0,.L0f1182ec
/*  f11829c:	00102600 */ 	sll	$a0,$s0,0x18
/*  f1182a0:	00044603 */ 	sra	$t0,$a0,0x18
/*  f1182a4:	0fc45fe0 */ 	jal	func0f117f80
/*  f1182a8:	01002025 */ 	or	$a0,$t0,$zero
/*  f1182ac:	8fa60020 */ 	lw	$a2,0x20($sp)
/*  f1182b0:	00402825 */ 	or	$a1,$v0,$zero
/*  f1182b4:	00062202 */ 	srl	$a0,$a2,0x8
/*  f1182b8:	30c900ff */ 	andi	$t1,$a2,0xff
/*  f1182bc:	11200002 */ 	beqz	$t1,.L0f1182c8
/*  f1182c0:	00801825 */ 	or	$v1,$a0,$zero
/*  f1182c4:	24830001 */ 	addiu	$v1,$a0,0x1
.L0f1182c8:
/*  f1182c8:	00102600 */ 	sll	$a0,$s0,0x18
/*  f1182cc:	00045603 */ 	sra	$t2,$a0,0x18
/*  f1182d0:	00a32821 */ 	addu	$a1,$a1,$v1
/*  f1182d4:	0fc460cd */ 	jal	func0f118334
/*  f1182d8:	01402025 */ 	or	$a0,$t2,$zero
/*  f1182dc:	54400004 */ 	bnezl	$v0,.L0f1182f0
/*  f1182e0:	00102600 */ 	sll	$a0,$s0,0x18
/*  f1182e4:	1000000e */ 	beqz	$zero,.L0f118320
/*  f1182e8:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f1182ec:
/*  f1182ec:	00102600 */ 	sll	$a0,$s0,0x18
.L0f1182f0:
/*  f1182f0:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f1182f4:	01602025 */ 	or	$a0,$t3,$zero
/*  f1182f8:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f1182fc:	0fc4619d */ 	jal	func0f118674
/*  f118300:	8fa6002c */ 	lw	$a2,0x2c($sp)
/*  f118304:	10400003 */ 	beqz	$v0,.L0f118314
/*  f118308:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11830c:	10000005 */ 	beqz	$zero,.L0f118324
/*  f118310:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f118314:
/*  f118314:	10000002 */ 	beqz	$zero,.L0f118320
/*  f118318:	00001025 */ 	or	$v0,$zero,$zero
.L0f11831c:
/*  f11831c:	2402000e */ 	addiu	$v0,$zero,0xe
.L0f118320:
/*  f118320:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f118324:
/*  f118324:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f118328:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f11832c:	03e00008 */ 	jr	$ra
/*  f118330:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f118334
/*  f118334:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f118338:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f11833c:	00048600 */ 	sll	$s0,$a0,0x18
/*  f118340:	00107603 */ 	sra	$t6,$s0,0x18
/*  f118344:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f118348:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f11834c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f118350:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f118354:	01c08025 */ 	or	$s0,$t6,$zero
/*  f118358:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f11835c:	0fc45fe0 */ 	jal	func0f117f80
/*  f118360:	01e02025 */ 	or	$a0,$t7,$zero
/*  f118364:	00102600 */ 	sll	$a0,$s0,0x18
/*  f118368:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f11836c:	0fc46000 */ 	jal	func0f118000
/*  f118370:	03002025 */ 	or	$a0,$t8,$zero
/*  f118374:	24010004 */ 	addiu	$at,$zero,0x4
/*  f118378:	16010003 */ 	bne	$s0,$at,.L0f118388
/*  f11837c:	24053459 */ 	addiu	$a1,$zero,0x3459
/*  f118380:	10000009 */ 	beqz	$zero,.L0f1183a8
/*  f118384:	00002025 */ 	or	$a0,$zero,$zero
.L0f118388:
/*  f118388:	0010c880 */ 	sll	$t9,$s0,0x2
/*  f11838c:	0330c823 */ 	subu	$t9,$t9,$s0
/*  f118390:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f118394:	0330c821 */ 	addu	$t9,$t9,$s0
/*  f118398:	3c08800a */ 	lui	$t0,%hi(var800a3180)
/*  f11839c:	25083180 */ 	addiu	$t0,$t0,%lo(var800a3180)
/*  f1183a0:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f1183a4:	03282021 */ 	addu	$a0,$t9,$t0
.L0f1183a8:
/*  f1183a8:	8fa2005c */ 	lw	$v0,0x5c($sp)
/*  f1183ac:	3c098007 */ 	lui	$t1,%hi(var80075d08)
/*  f1183b0:	25295d08 */ 	addiu	$t1,$t1,%lo(var80075d08)
/*  f1183b4:	00025200 */ 	sll	$t2,$v0,0x8
/*  f1183b8:	3c064e50 */ 	lui	$a2,0x4e50
/*  f1183bc:	3c078007 */ 	lui	$a3,%hi(var80075cf8)
/*  f1183c0:	24e75cf8 */ 	addiu	$a3,$a3,%lo(var80075cf8)
/*  f1183c4:	34c64445 */ 	ori	$a2,$a2,0x4445
/*  f1183c8:	01401025 */ 	or	$v0,$t2,$zero
/*  f1183cc:	afaa0014 */ 	sw	$t2,0x14($sp)
/*  f1183d0:	afaa0030 */ 	sw	$t2,0x30($sp)
/*  f1183d4:	0fc45fb0 */ 	jal	func0f117ec0
/*  f1183d8:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f1183dc:	00102e00 */ 	sll	$a1,$s0,0x18
/*  f1183e0:	00055e03 */ 	sra	$t3,$a1,0x18
/*  f1183e4:	afa2004c */ 	sw	$v0,0x4c($sp)
/*  f1183e8:	01602825 */ 	or	$a1,$t3,$zero
/*  f1183ec:	00402025 */ 	or	$a0,$v0,$zero
/*  f1183f0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f1183f4:	0fc470e7 */ 	jal	func0f11c39c
/*  f1183f8:	2407070a */ 	addiu	$a3,$zero,0x70a
/*  f1183fc:	8fac004c */ 	lw	$t4,0x4c($sp)
/*  f118400:	00106880 */ 	sll	$t5,$s0,0x2
/*  f118404:	01b06823 */ 	subu	$t5,$t5,$s0
/*  f118408:	1580002d */ 	bnez	$t4,.L0f1184c0
/*  f11840c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f118410:	01b06823 */ 	subu	$t5,$t5,$s0
/*  f118414:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f118418:	01b06821 */ 	addu	$t5,$t5,$s0
/*  f11841c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f118420:	01b06823 */ 	subu	$t5,$t5,$s0
/*  f118424:	3c0e800a */ 	lui	$t6,%hi(var800a2380)
/*  f118428:	25ce2380 */ 	addiu	$t6,$t6,%lo(var800a2380)
/*  f11842c:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f118430:	01ae1821 */ 	addu	$v1,$t5,$t6
/*  f118434:	8c6802a8 */ 	lw	$t0,0x2a8($v1)
/*  f118438:	8fb9005c */ 	lw	$t9,0x5c($sp)
/*  f11843c:	946b0258 */ 	lhu	$t3,0x258($v1)
/*  f118440:	8c6f029c */ 	lw	$t7,0x29c($v1)
/*  f118444:	9469025a */ 	lhu	$t1,0x25a($v1)
/*  f118448:	03281023 */ 	subu	$v0,$t9,$t0
/*  f11844c:	01626021 */ 	addu	$t4,$t3,$v0
/*  f118450:	318dffff */ 	andi	$t5,$t4,0xffff
/*  f118454:	000fc140 */ 	sll	$t8,$t7,0x5
/*  f118458:	01225023 */ 	subu	$t2,$t1,$v0
/*  f11845c:	00782821 */ 	addu	$a1,$v1,$t8
/*  f118460:	a46a025a */ 	sh	$t2,0x25a($v1)
/*  f118464:	a46c0258 */ 	sh	$t4,0x258($v1)
/*  f118468:	000d7200 */ 	sll	$t6,$t5,0x8
/*  f11846c:	acae0018 */ 	sw	$t6,0x18($a1)
/*  f118470:	8faf0030 */ 	lw	$t7,0x30($sp)
/*  f118474:	00102600 */ 	sll	$a0,$s0,0x18
/*  f118478:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f11847c:	24a50018 */ 	addiu	$a1,$a1,0x18
/*  f118480:	03002025 */ 	or	$a0,$t8,$zero
/*  f118484:	afa3002c */ 	sw	$v1,0x2c($sp)
/*  f118488:	0fc45974 */ 	jal	func0f1165d0
/*  f11848c:	ac6f02a0 */ 	sw	$t7,0x2a0($v1)
/*  f118490:	8fa3002c */ 	lw	$v1,0x2c($sp)
/*  f118494:	8c6402a0 */ 	lw	$a0,0x2a0($v1)
/*  f118498:	0082001b */ 	divu	$zero,$a0,$v0
/*  f11849c:	0000c812 */ 	mflo	$t9
/*  f1184a0:	00044202 */ 	srl	$t0,$a0,0x8
/*  f1184a4:	14400002 */ 	bnez	$v0,.L0f1184b0
/*  f1184a8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1184ac:	0007000d */ 	break	0x7
.L0f1184b0:
/*  f1184b0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1184b4:	ac7902a4 */ 	sw	$t9,0x2a4($v1)
/*  f1184b8:	10000002 */ 	beqz	$zero,.L0f1184c4
/*  f1184bc:	ac6802a8 */ 	sw	$t0,0x2a8($v1)
.L0f1184c0:
/*  f1184c0:	00001025 */ 	or	$v0,$zero,$zero
.L0f1184c4:
/*  f1184c4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1184c8:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f1184cc:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f1184d0:	03e00008 */ 	jr	$ra
/*  f1184d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1184d8:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f1184dc:	00047600 */ 	sll	$t6,$a0,0x18
/*  f1184e0:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f1184e4:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f1184e8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f1184ec:	01e02025 */ 	or	$a0,$t7,$zero
/*  f1184f0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f1184f4:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f1184f8:	11e1001d */ 	beq	$t7,$at,.L0f118570
/*  f1184fc:	00c03825 */ 	or	$a3,$a2,$zero
/*  f118500:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f118504:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f118508:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11850c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f118510:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f118514:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f118518:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11851c:	3c03800a */ 	lui	$v1,%hi(var800a2380)
/*  f118520:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f118524:	24632380 */ 	addiu	$v1,$v1,%lo(var800a2380)
/*  f118528:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11852c:	00781021 */ 	addu	$v0,$v1,$t8
/*  f118530:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f118534:	24010002 */ 	addiu	$at,$zero,0x2
/*  f118538:	57210006 */ 	bnel	$t9,$at,.L0f118554
/*  f11853c:	90650ded */ 	lbu	$a1,0xded($v1)
/*  f118540:	8c480010 */ 	lw	$t0,0x10($v0)
/*  f118544:	2401000b */ 	addiu	$at,$zero,0xb
/*  f118548:	5101000a */ 	beql	$t0,$at,.L0f118574
/*  f11854c:	00045080 */ 	sll	$t2,$a0,0x2
/*  f118550:	90650ded */ 	lbu	$a1,0xded($v1)
.L0f118554:
/*  f118554:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f118558:	afa70020 */ 	sw	$a3,0x20($sp)
/*  f11855c:	30a9000f */ 	andi	$t1,$a1,0xf
/*  f118560:	0fc46178 */ 	jal	func0f1185e0
/*  f118564:	01202825 */ 	or	$a1,$t1,$zero
/*  f118568:	8fa70020 */ 	lw	$a3,0x20($sp)
/*  f11856c:	24040004 */ 	addiu	$a0,$zero,0x4
.L0f118570:
/*  f118570:	00045080 */ 	sll	$t2,$a0,0x2
.L0f118574:
/*  f118574:	01445023 */ 	subu	$t2,$t2,$a0
/*  f118578:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f11857c:	01445023 */ 	subu	$t2,$t2,$a0
/*  f118580:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f118584:	01445021 */ 	addu	$t2,$t2,$a0
/*  f118588:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f11858c:	3c03800a */ 	lui	$v1,%hi(var800a2380)
/*  f118590:	01445023 */ 	subu	$t2,$t2,$a0
/*  f118594:	24632380 */ 	addiu	$v1,$v1,%lo(var800a2380)
/*  f118598:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f11859c:	006a1021 */ 	addu	$v0,$v1,$t2
/*  f1185a0:	904b02bd */ 	lbu	$t3,0x2bd($v0)
/*  f1185a4:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1185a8:	316c0080 */ 	andi	$t4,$t3,0x80
/*  f1185ac:	51800004 */ 	beqzl	$t4,.L0f1185c0
/*  f1185b0:	ace00000 */ 	sw	$zero,0x0($a3)
/*  f1185b4:	10000002 */ 	beqz	$zero,.L0f1185c0
/*  f1185b8:	aced0000 */ 	sw	$t5,0x0($a3)
/*  f1185bc:	ace00000 */ 	sw	$zero,0x0($a3)
.L0f1185c0:
/*  f1185c0:	904e02bd */ 	lbu	$t6,0x2bd($v0)
/*  f1185c4:	8fb8001c */ 	lw	$t8,0x1c($sp)
/*  f1185c8:	31cf000f */ 	andi	$t7,$t6,0xf
/*  f1185cc:	af0f0000 */ 	sw	$t7,0x0($t8)
/*  f1185d0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f1185d4:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1185d8:	03e00008 */ 	jr	$ra
/*  f1185dc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1185e0
/*  f1185e0:	00047600 */ 	sll	$t6,$a0,0x18
/*  f1185e4:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f1185e8:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f1185ec:	10c00010 */ 	beqz	$a2,.L0f118630
/*  f1185f0:	01e02025 */ 	or	$a0,$t7,$zero
/*  f1185f4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1185f8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1185fc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f118600:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f118604:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f118608:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11860c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f118610:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f118614:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f118618:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f11861c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f118620:	03191021 */ 	addu	$v0,$t8,$t9
/*  f118624:	24080080 */ 	addiu	$t0,$zero,0x80
/*  f118628:	1000000e */ 	beqz	$zero,.L0f118664
/*  f11862c:	a04802bd */ 	sb	$t0,0x2bd($v0)
.L0f118630:
/*  f118630:	00044880 */ 	sll	$t1,$a0,0x2
/*  f118634:	01244823 */ 	subu	$t1,$t1,$a0
/*  f118638:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11863c:	01244823 */ 	subu	$t1,$t1,$a0
/*  f118640:	00094880 */ 	sll	$t1,$t1,0x2
/*  f118644:	01244821 */ 	addu	$t1,$t1,$a0
/*  f118648:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11864c:	01244823 */ 	subu	$t1,$t1,$a0
/*  f118650:	3c0a800a */ 	lui	$t2,%hi(var800a2380)
/*  f118654:	254a2380 */ 	addiu	$t2,$t2,%lo(var800a2380)
/*  f118658:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11865c:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f118660:	a04002bd */ 	sb	$zero,0x2bd($v0)
.L0f118664:
/*  f118664:	904b02bd */ 	lbu	$t3,0x2bd($v0)
/*  f118668:	01656021 */ 	addu	$t4,$t3,$a1
/*  f11866c:	03e00008 */ 	jr	$ra
/*  f118670:	a04c02bd */ 	sb	$t4,0x2bd($v0)
);

GLOBAL_ASM(
glabel func0f118674
/*  f118674:	27bdff80 */ 	addiu	$sp,$sp,-128
/*  f118678:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f11867c:	00049600 */ 	sll	$s2,$a0,0x18
/*  f118680:	00127603 */ 	sra	$t6,$s2,0x18
/*  f118684:	afa40080 */ 	sw	$a0,0x80($sp)
/*  f118688:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f11868c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f118690:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f118694:	01c09025 */ 	or	$s2,$t6,$zero
/*  f118698:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f11869c:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f1186a0:	afa50084 */ 	sw	$a1,0x84($sp)
/*  f1186a4:	afa60088 */ 	sw	$a2,0x88($sp)
/*  f1186a8:	0fc45c25 */ 	jal	func0f117094
/*  f1186ac:	01e02025 */ 	or	$a0,$t7,$zero
/*  f1186b0:	00122600 */ 	sll	$a0,$s2,0x18
/*  f1186b4:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f1186b8:	03002025 */ 	or	$a0,$t8,$zero
/*  f1186bc:	0fc45996 */ 	jal	func0f116658
/*  f1186c0:	00402825 */ 	or	$a1,$v0,$zero
/*  f1186c4:	00122600 */ 	sll	$a0,$s2,0x18
/*  f1186c8:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f1186cc:	00044603 */ 	sra	$t0,$a0,0x18
/*  f1186d0:	afa20064 */ 	sw	$v0,0x64($sp)
/*  f1186d4:	afb90060 */ 	sw	$t9,0x60($sp)
/*  f1186d8:	00008025 */ 	or	$s0,$zero,$zero
/*  f1186dc:	afa00058 */ 	sw	$zero,0x58($sp)
/*  f1186e0:	afa00054 */ 	sw	$zero,0x54($sp)
/*  f1186e4:	0fc459f6 */ 	jal	func0f1167d8
/*  f1186e8:	01002025 */ 	or	$a0,$t0,$zero
/*  f1186ec:	10400007 */ 	beqz	$v0,.L0f11870c
/*  f1186f0:	00125080 */ 	sll	$t2,$s2,0x2
/*  f1186f4:	00122600 */ 	sll	$a0,$s2,0x18
/*  f1186f8:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f1186fc:	0fc459f6 */ 	jal	func0f1167d8
/*  f118700:	01202025 */ 	or	$a0,$t1,$zero
/*  f118704:	100000ad */ 	beqz	$zero,.L0f1189bc
/*  f118708:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f11870c:
/*  f11870c:	01525023 */ 	subu	$t2,$t2,$s2
/*  f118710:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f118714:	01525023 */ 	subu	$t2,$t2,$s2
/*  f118718:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f11871c:	01525021 */ 	addu	$t2,$t2,$s2
/*  f118720:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f118724:	01525023 */ 	subu	$t2,$t2,$s2
/*  f118728:	3c0b800a */ 	lui	$t3,%hi(var800a2380)
/*  f11872c:	256b2380 */ 	addiu	$t3,$t3,%lo(var800a2380)
/*  f118730:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f118734:	014b8821 */ 	addu	$s1,$t2,$t3
/*  f118738:	8e2c02a0 */ 	lw	$t4,0x2a0($s1)
/*  f11873c:	11800033 */ 	beqz	$t4,.L0f11880c
/*  f118740:	00122600 */ 	sll	$a0,$s2,0x18
.L0f118744:
/*  f118744:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f118748:	01a02025 */ 	or	$a0,$t5,$zero
/*  f11874c:	02002825 */ 	or	$a1,$s0,$zero
/*  f118750:	0fc45d48 */ 	jal	func0f117520
/*  f118754:	27a60070 */ 	addiu	$a2,$sp,0x70
/*  f118758:	14400020 */ 	bnez	$v0,.L0f1187dc
/*  f11875c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f118760:	8fa30078 */ 	lw	$v1,0x78($sp)
/*  f118764:	000315c2 */ 	srl	$v0,$v1,0x17
/*  f118768:	304e0004 */ 	andi	$t6,$v0,0x4
/*  f11876c:	11c0000c */ 	beqz	$t6,.L0f1187a0
/*  f118770:	30490002 */ 	andi	$t1,$v0,0x2
/*  f118774:	8faf0064 */ 	lw	$t7,0x64($sp)
/*  f118778:	8e3902a0 */ 	lw	$t9,0x2a0($s1)
/*  f11877c:	020fc021 */ 	addu	$t8,$s0,$t7
/*  f118780:	2728ffe0 */ 	addiu	$t0,$t9,-32
/*  f118784:	0118082b */ 	sltu	$at,$t0,$t8
/*  f118788:	10200003 */ 	beqz	$at,.L0f118798
/*  f11878c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118790:	10000089 */ 	beqz	$zero,.L0f1189b8
/*  f118794:	2402000e */ 	addiu	$v0,$zero,0xe
.L0f118798:
/*  f118798:	1000001c */ 	beqz	$zero,.L0f11880c
/*  f11879c:	afb00060 */ 	sw	$s0,0x60($sp)
.L0f1187a0:
/*  f1187a0:	1120000c */ 	beqz	$t1,.L0f1187d4
/*  f1187a4:	306e0fff */ 	andi	$t6,$v1,0xfff
/*  f1187a8:	8faa0064 */ 	lw	$t2,0x64($sp)
/*  f1187ac:	306b0fff */ 	andi	$t3,$v1,0xfff
/*  f1187b0:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f1187b4:	154b0004 */ 	bne	$t2,$t3,.L0f1187c8
/*  f1187b8:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f1187bc:	afac0058 */ 	sw	$t4,0x58($sp)
/*  f1187c0:	10000012 */ 	beqz	$zero,.L0f11880c
/*  f1187c4:	afb00060 */ 	sw	$s0,0x60($sp)
.L0f1187c8:
/*  f1187c8:	afad0054 */ 	sw	$t5,0x54($sp)
/*  f1187cc:	1000000f */ 	beqz	$zero,.L0f11880c
/*  f1187d0:	afb00060 */ 	sw	$s0,0x60($sp)
.L0f1187d4:
/*  f1187d4:	10000009 */ 	beqz	$zero,.L0f1187fc
/*  f1187d8:	020e8021 */ 	addu	$s0,$s0,$t6
.L0f1187dc:
/*  f1187dc:	14410003 */ 	bne	$v0,$at,.L0f1187ec
/*  f1187e0:	00122600 */ 	sll	$a0,$s2,0x18
/*  f1187e4:	10000074 */ 	beqz	$zero,.L0f1189b8
/*  f1187e8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1187ec:
/*  f1187ec:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f1187f0:	0fc45974 */ 	jal	func0f1165d0
/*  f1187f4:	01e02025 */ 	or	$a0,$t7,$zero
/*  f1187f8:	02028021 */ 	addu	$s0,$s0,$v0
.L0f1187fc:
/*  f1187fc:	8e3902a0 */ 	lw	$t9,0x2a0($s1)
/*  f118800:	0219082b */ 	sltu	$at,$s0,$t9
/*  f118804:	5420ffcf */ 	bnezl	$at,.L0f118744
/*  f118808:	00122600 */ 	sll	$a0,$s2,0x18
.L0f11880c:
/*  f11880c:	52000011 */ 	beqzl	$s0,.L0f118854
/*  f118810:	8fab0060 */ 	lw	$t3,0x60($sp)
/*  f118814:	12000057 */ 	beqz	$s0,.L0f118974
/*  f118818:	00122600 */ 	sll	$a0,$s2,0x18
/*  f11881c:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f118820:	0fc45ff0 */ 	jal	func0f117fc0
/*  f118824:	03002025 */ 	or	$a0,$t8,$zero
/*  f118828:	0202082b */ 	sltu	$at,$s0,$v0
/*  f11882c:	10200051 */ 	beqz	$at,.L0f118974
/*  f118830:	00122600 */ 	sll	$a0,$s2,0x18
/*  f118834:	00044603 */ 	sra	$t0,$a0,0x18
/*  f118838:	0fc45974 */ 	jal	func0f1165d0
/*  f11883c:	01002025 */ 	or	$a0,$t0,$zero
/*  f118840:	2449ffff */ 	addiu	$t1,$v0,-1
/*  f118844:	01305024 */ 	and	$t2,$t1,$s0
/*  f118848:	5540004b */ 	bnezl	$t2,.L0f118978
/*  f11884c:	00124080 */ 	sll	$t0,$s2,0x2
/*  f118850:	8fab0060 */ 	lw	$t3,0x60($sp)
.L0f118854:
/*  f118854:	2401ffff */ 	addiu	$at,$zero,-1
/*  f118858:	00122600 */ 	sll	$a0,$s2,0x18
/*  f11885c:	15610003 */ 	bne	$t3,$at,.L0f11886c
/*  f118860:	00046603 */ 	sra	$t4,$a0,0x18
/*  f118864:	10000054 */ 	beqz	$zero,.L0f1189b8
/*  f118868:	2402000e */ 	addiu	$v0,$zero,0xe
.L0f11886c:
/*  f11886c:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f118870:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f118874:	afae0020 */ 	sw	$t6,0x20($sp)
/*  f118878:	01802025 */ 	or	$a0,$t4,$zero
/*  f11887c:	8fa50060 */ 	lw	$a1,0x60($sp)
/*  f118880:	8fa60084 */ 	lw	$a2,0x84($sp)
/*  f118884:	00003825 */ 	or	$a3,$zero,$zero
/*  f118888:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f11888c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f118890:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f118894:	0fc46f15 */ 	jal	func0f11bc54
/*  f118898:	afad0014 */ 	sw	$t5,0x14($sp)
/*  f11889c:	14400033 */ 	bnez	$v0,.L0f11896c
/*  f1188a0:	8faf0054 */ 	lw	$t7,0x54($sp)
/*  f1188a4:	11e0000d */ 	beqz	$t7,.L0f1188dc
/*  f1188a8:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f1188ac:	8fb90060 */ 	lw	$t9,0x60($sp)
/*  f1188b0:	8fb80064 */ 	lw	$t8,0x64($sp)
/*  f1188b4:	00122600 */ 	sll	$a0,$s2,0x18
/*  f1188b8:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f1188bc:	03384021 */ 	addu	$t0,$t9,$t8
/*  f1188c0:	afa80050 */ 	sw	$t0,0x50($sp)
/*  f1188c4:	01202025 */ 	or	$a0,$t1,$zero
/*  f1188c8:	27a50050 */ 	addiu	$a1,$sp,0x50
/*  f1188cc:	0fc46538 */ 	jal	func0f1194e0
/*  f1188d0:	00003025 */ 	or	$a2,$zero,$zero
/*  f1188d4:	10000038 */ 	beqz	$zero,.L0f1189b8
/*  f1188d8:	00001025 */ 	or	$v0,$zero,$zero
.L0f1188dc:
/*  f1188dc:	15400003 */ 	bnez	$t2,.L0f1188ec
/*  f1188e0:	8fab0054 */ 	lw	$t3,0x54($sp)
/*  f1188e4:	11600003 */ 	beqz	$t3,.L0f1188f4
/*  f1188e8:	00122600 */ 	sll	$a0,$s2,0x18
.L0f1188ec:
/*  f1188ec:	10000032 */ 	beqz	$zero,.L0f1189b8
/*  f1188f0:	00001025 */ 	or	$v0,$zero,$zero
.L0f1188f4:
/*  f1188f4:	00046603 */ 	sra	$t4,$a0,0x18
/*  f1188f8:	01802025 */ 	or	$a0,$t4,$zero
/*  f1188fc:	0fc45c25 */ 	jal	func0f117094
/*  f118900:	8fa50084 */ 	lw	$a1,0x84($sp)
/*  f118904:	00122600 */ 	sll	$a0,$s2,0x18
/*  f118908:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f11890c:	01a02025 */ 	or	$a0,$t5,$zero
/*  f118910:	0fc45996 */ 	jal	func0f116658
/*  f118914:	00402825 */ 	or	$a1,$v0,$zero
/*  f118918:	8fae0060 */ 	lw	$t6,0x60($sp)
/*  f11891c:	00122600 */ 	sll	$a0,$s2,0x18
/*  f118920:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f118924:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f118928:	01c22821 */ 	addu	$a1,$t6,$v0
/*  f11892c:	afa50060 */ 	sw	$a1,0x60($sp)
/*  f118930:	afb80020 */ 	sw	$t8,0x20($sp)
/*  f118934:	03202025 */ 	or	$a0,$t9,$zero
/*  f118938:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f11893c:	00003825 */ 	or	$a3,$zero,$zero
/*  f118940:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f118944:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f118948:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f11894c:	0fc46f15 */ 	jal	func0f11bc54
/*  f118950:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f118954:	14400003 */ 	bnez	$v0,.L0f118964
/*  f118958:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11895c:	10000016 */ 	beqz	$zero,.L0f1189b8
/*  f118960:	00001025 */ 	or	$v0,$zero,$zero
.L0f118964:
/*  f118964:	10000014 */ 	beqz	$zero,.L0f1189b8
/*  f118968:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f11896c:
/*  f11896c:	10000012 */ 	beqz	$zero,.L0f1189b8
/*  f118970:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f118974:
/*  f118974:	00124080 */ 	sll	$t0,$s2,0x2
.L0f118978:
/*  f118978:	01124023 */ 	subu	$t0,$t0,$s2
/*  f11897c:	00084080 */ 	sll	$t0,$t0,0x2
/*  f118980:	01124023 */ 	subu	$t0,$t0,$s2
/*  f118984:	00084080 */ 	sll	$t0,$t0,0x2
/*  f118988:	01124021 */ 	addu	$t0,$t0,$s2
/*  f11898c:	00084080 */ 	sll	$t0,$t0,0x2
/*  f118990:	01124023 */ 	subu	$t0,$t0,$s2
/*  f118994:	3c09800a */ 	lui	$t1,%hi(var800a2380)
/*  f118998:	25292380 */ 	addiu	$t1,$t1,%lo(var800a2380)
/*  f11899c:	00084080 */ 	sll	$t0,$t0,0x2
/*  f1189a0:	01098821 */ 	addu	$s1,$t0,$t1
/*  f1189a4:	240a0010 */ 	addiu	$t2,$zero,0x10
/*  f1189a8:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f1189ac:	ae2a0010 */ 	sw	$t2,0x10($s1)
/*  f1189b0:	ae2b0000 */ 	sw	$t3,0x0($s1)
/*  f1189b4:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f1189b8:
/*  f1189b8:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f1189bc:
/*  f1189bc:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f1189c0:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f1189c4:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f1189c8:	03e00008 */ 	jr	$ra
/*  f1189cc:	27bd0080 */ 	addiu	$sp,$sp,0x80
/*  f1189d0:	03e00008 */ 	jr	$ra
/*  f1189d4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1189d8
/*  f1189d8:	3c02800a */ 	lui	$v0,%hi(g_Vars)
/*  f1189dc:	24429fc0 */ 	addiu	$v0,$v0,%lo(g_Vars)
/*  f1189e0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f1189e4:	904e04d0 */ 	lbu	$t6,0x4d0($v0)
/*  f1189e8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f1189ec:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1189f0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f1189f4:	a44004e4 */ 	sh	$zero,0x4e4($v0)
/*  f1189f8:	00008025 */ 	or	$s0,$zero,$zero
/*  f1189fc:	a3ae0027 */ 	sb	$t6,0x27($sp)
/*  f118a00:	00102600 */ 	sll	$a0,$s0,0x18
.L0f118a04:
/*  f118a04:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f118a08:	0fc4690d */ 	jal	func0f11a434
/*  f118a0c:	01e02025 */ 	or	$a0,$t7,$zero
/*  f118a10:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f118a14:	0010c600 */ 	sll	$t8,$s0,0x18
/*  f118a18:	00188603 */ 	sra	$s0,$t8,0x18
/*  f118a1c:	2a010005 */ 	slti	$at,$s0,0x5
/*  f118a20:	5420fff8 */ 	bnezl	$at,.L0f118a04
/*  f118a24:	00102600 */ 	sll	$a0,$s0,0x18
/*  f118a28:	3c117f1b */ 	lui	$s1,%hi(var7f1b3e30)
/*  f118a2c:	26313e30 */ 	addiu	$s1,$s1,%lo(var7f1b3e30)
/*  f118a30:	00008025 */ 	or	$s0,$zero,$zero
/*  f118a34:	00102600 */ 	sll	$a0,$s0,0x18
.L0f118a38:
/*  f118a38:	00044603 */ 	sra	$t0,$a0,0x18
/*  f118a3c:	01002025 */ 	or	$a0,$t0,$zero
/*  f118a40:	24050007 */ 	addiu	$a1,$zero,0x7
/*  f118a44:	24060801 */ 	addiu	$a2,$zero,0x801
/*  f118a48:	0fc468cb */ 	jal	func0f11a32c
/*  f118a4c:	02203825 */ 	or	$a3,$s1,$zero
/*  f118a50:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f118a54:	00104e00 */ 	sll	$t1,$s0,0x18
/*  f118a58:	00098603 */ 	sra	$s0,$t1,0x18
/*  f118a5c:	2a010005 */ 	slti	$at,$s0,0x5
/*  f118a60:	5420fff5 */ 	bnezl	$at,.L0f118a38
/*  f118a64:	00102600 */ 	sll	$a0,$s0,0x18
/*  f118a68:	0fc478ff */ 	jal	func0f11e3fc
/*  f118a6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118a70:	0c004e90 */ 	jal	func00013a40
/*  f118a74:	24040010 */ 	addiu	$a0,$zero,0x10
/*  f118a78:	240b0010 */ 	addiu	$t3,$zero,0x10
/*  f118a7c:	3c01800a */ 	lui	$at,0x800a
/*  f118a80:	a02ba490 */ 	sb	$t3,-0x5b70($at)
/*  f118a84:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f118a88:	0fc45a72 */ 	jal	func0f1169c8
/*  f118a8c:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f118a90:	0fc441b2 */ 	jal	func0f1106c8
/*  f118a94:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118a98:	3c10800a */ 	lui	$s0,%hi(var800a2200)
/*  f118a9c:	26102200 */ 	addiu	$s0,$s0,%lo(var800a2200)
/*  f118aa0:	0fc43da6 */ 	jal	func0f10f698
/*  f118aa4:	02002025 */ 	or	$a0,$s0,$zero
/*  f118aa8:	0fc43c81 */ 	jal	func0f10f204
/*  f118aac:	02002025 */ 	or	$a0,$s0,$zero
/*  f118ab0:	3c01800a */ 	lui	$at,0x800a
/*  f118ab4:	a42022c4 */ 	sh	$zero,0x22c4($at)
/*  f118ab8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f118abc:	3c01800a */ 	lui	$at,0x800a
/*  f118ac0:	240c00f5 */ 	addiu	$t4,$zero,0xf5
/*  f118ac4:	93ad0027 */ 	lbu	$t5,0x27($sp)
/*  f118ac8:	a42ca4a4 */ 	sh	$t4,-0x5b5c($at)
/*  f118acc:	3c01800a */ 	lui	$at,0x800a
/*  f118ad0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f118ad4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f118ad8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f118adc:	03e00008 */ 	jr	$ra
/*  f118ae0:	a02da490 */ 	sb	$t5,-0x5b70($at)
);

GLOBAL_ASM(
glabel func0f118ae4
/*  f118ae4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f118ae8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f118aec:	0fc4a41b */ 	jal	func0f12906c
/*  f118af0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118af4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f118af8:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f118afc:	03e00008 */ 	jr	$ra
/*  f118b00:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118b04:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f118b08:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f118b0c:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f118b10:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f118b14:	0fc459f6 */ 	jal	func0f1167d8
/*  f118b18:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f118b1c:	14400023 */ 	bnez	$v0,.L0f118bac
/*  f118b20:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f118b24:	8fa50024 */ 	lw	$a1,0x24($sp)
/*  f118b28:	0fc464da */ 	jal	func0f119368
/*  f118b2c:	00003025 */ 	or	$a2,$zero,$zero
/*  f118b30:	2401ffff */ 	addiu	$at,$zero,-1
/*  f118b34:	14410003 */ 	bne	$v0,$at,.L0f118b44
/*  f118b38:	00402825 */ 	or	$a1,$v0,$zero
/*  f118b3c:	1000001e */ 	beqz	$zero,.L0f118bb8
/*  f118b40:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f118b44:
/*  f118b44:	10400011 */ 	beqz	$v0,.L0f118b8c
/*  f118b48:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118b4c:	10400015 */ 	beqz	$v0,.L0f118ba4
/*  f118b50:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f118b54:	0fc45ff0 */ 	jal	func0f117fc0
/*  f118b58:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f118b5c:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f118b60:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f118b64:	00a2082b */ 	sltu	$at,$a1,$v0
/*  f118b68:	1020000e */ 	beqz	$at,.L0f118ba4
/*  f118b6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118b70:	0fc45974 */ 	jal	func0f1165d0
/*  f118b74:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f118b78:	8fa5001c */ 	lw	$a1,0x1c($sp)
/*  f118b7c:	244effff */ 	addiu	$t6,$v0,-1
/*  f118b80:	01c57824 */ 	and	$t7,$t6,$a1
/*  f118b84:	15e00007 */ 	bnez	$t7,.L0f118ba4
/*  f118b88:	00000000 */ 	sll	$zero,$zero,0x0
.L0f118b8c:
/*  f118b8c:	0fc46ef6 */ 	jal	func0f11bbd8
/*  f118b90:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f118b94:	54400008 */ 	bnezl	$v0,.L0f118bb8
/*  f118b98:	00001025 */ 	or	$v0,$zero,$zero
/*  f118b9c:	10000006 */ 	beqz	$zero,.L0f118bb8
/*  f118ba0:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f118ba4:
/*  f118ba4:	10000004 */ 	beqz	$zero,.L0f118bb8
/*  f118ba8:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f118bac:
/*  f118bac:	10000002 */ 	beqz	$zero,.L0f118bb8
/*  f118bb0:	24020006 */ 	addiu	$v0,$zero,0x6
/*  f118bb4:	00001025 */ 	or	$v0,$zero,$zero
.L0f118bb8:
/*  f118bb8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f118bbc:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f118bc0:	03e00008 */ 	jr	$ra
/*  f118bc4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f118bc8
/*  f118bc8:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f118bcc:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f118bd0:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f118bd4:	afa50044 */ 	sw	$a1,0x44($sp)
/*  f118bd8:	afa60048 */ 	sw	$a2,0x48($sp)
/*  f118bdc:	afa7004c */ 	sw	$a3,0x4c($sp)
/*  f118be0:	0fc459f6 */ 	jal	func0f1167d8
/*  f118be4:	83a40043 */ 	lb	$a0,0x43($sp)
/*  f118be8:	14400044 */ 	bnez	$v0,.L0f118cfc
/*  f118bec:	83a40043 */ 	lb	$a0,0x43($sp)
/*  f118bf0:	8fa50044 */ 	lw	$a1,0x44($sp)
/*  f118bf4:	0fc464da */ 	jal	func0f119368
/*  f118bf8:	00003025 */ 	or	$a2,$zero,$zero
/*  f118bfc:	2401ffff */ 	addiu	$at,$zero,-1
/*  f118c00:	14410003 */ 	bne	$v0,$at,.L0f118c10
/*  f118c04:	00402825 */ 	or	$a1,$v0,$zero
/*  f118c08:	1000003f */ 	beqz	$zero,.L0f118d08
/*  f118c0c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f118c10:
/*  f118c10:	50400012 */ 	beqzl	$v0,.L0f118c5c
/*  f118c14:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f118c18:	10400036 */ 	beqz	$v0,.L0f118cf4
/*  f118c1c:	83a40043 */ 	lb	$a0,0x43($sp)
/*  f118c20:	0fc45ff0 */ 	jal	func0f117fc0
/*  f118c24:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f118c28:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f118c2c:	83a40043 */ 	lb	$a0,0x43($sp)
/*  f118c30:	00a2082b */ 	sltu	$at,$a1,$v0
/*  f118c34:	1020002f */ 	beqz	$at,.L0f118cf4
/*  f118c38:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118c3c:	0fc45974 */ 	jal	func0f1165d0
/*  f118c40:	afa5003c */ 	sw	$a1,0x3c($sp)
/*  f118c44:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f118c48:	244effff */ 	addiu	$t6,$v0,-1
/*  f118c4c:	01c57824 */ 	and	$t7,$t6,$a1
/*  f118c50:	15e00028 */ 	bnez	$t7,.L0f118cf4
/*  f118c54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118c58:	8fb8004c */ 	lw	$t8,0x4c($sp)
.L0f118c5c:
/*  f118c5c:	83a40043 */ 	lb	$a0,0x43($sp)
/*  f118c60:	8fa60048 */ 	lw	$a2,0x48($sp)
/*  f118c64:	27a7002c */ 	addiu	$a3,$sp,0x2c
/*  f118c68:	0fc46e1b */ 	jal	func0f11b86c
/*  f118c6c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f118c70:	10400003 */ 	beqz	$v0,.L0f118c80
/*  f118c74:	8fb9004c */ 	lw	$t9,0x4c($sp)
/*  f118c78:	10000024 */ 	beqz	$zero,.L0f118d0c
/*  f118c7c:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f118c80:
/*  f118c80:	2401ffff */ 	addiu	$at,$zero,-1
/*  f118c84:	57210003 */ 	bnel	$t9,$at,.L0f118c94
/*  f118c88:	8fa80038 */ 	lw	$t0,0x38($sp)
/*  f118c8c:	afa0004c */ 	sw	$zero,0x4c($sp)
/*  f118c90:	8fa80038 */ 	lw	$t0,0x38($sp)
.L0f118c94:
/*  f118c94:	8fab004c */ 	lw	$t3,0x4c($sp)
/*  f118c98:	00085740 */ 	sll	$t2,$t0,0x1d
/*  f118c9c:	05410013 */ 	bgez	$t2,.L0f118cec
/*  f118ca0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118ca4:	15600017 */ 	bnez	$t3,.L0f118d04
/*  f118ca8:	8fad0034 */ 	lw	$t5,0x34($sp)
/*  f118cac:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f118cb0:	000d7240 */ 	sll	$t6,$t5,0x9
/*  f118cb4:	000e7d42 */ 	srl	$t7,$t6,0x15
/*  f118cb8:	27a60024 */ 	addiu	$a2,$sp,0x24
/*  f118cbc:	0fc462b9 */ 	jal	func0f118ae4
/*  f118cc0:	008f2821 */ 	addu	$a1,$a0,$t7
/*  f118cc4:	97b80030 */ 	lhu	$t8,0x30($sp)
/*  f118cc8:	97b90024 */ 	lhu	$t9,0x24($sp)
/*  f118ccc:	97a80032 */ 	lhu	$t0,0x32($sp)
/*  f118cd0:	97a90026 */ 	lhu	$t1,0x26($sp)
/*  f118cd4:	17190003 */ 	bne	$t8,$t9,.L0f118ce4
/*  f118cd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118cdc:	5109000a */ 	beql	$t0,$t1,.L0f118d08
/*  f118ce0:	00001025 */ 	or	$v0,$zero,$zero
.L0f118ce4:
/*  f118ce4:	10000008 */ 	beqz	$zero,.L0f118d08
/*  f118ce8:	24020008 */ 	addiu	$v0,$zero,0x8
.L0f118cec:
/*  f118cec:	10000006 */ 	beqz	$zero,.L0f118d08
/*  f118cf0:	2402000a */ 	addiu	$v0,$zero,0xa
.L0f118cf4:
/*  f118cf4:	10000004 */ 	beqz	$zero,.L0f118d08
/*  f118cf8:	24020003 */ 	addiu	$v0,$zero,0x3
.L0f118cfc:
/*  f118cfc:	10000002 */ 	beqz	$zero,.L0f118d08
/*  f118d00:	24020006 */ 	addiu	$v0,$zero,0x6
.L0f118d04:
/*  f118d04:	00001025 */ 	or	$v0,$zero,$zero
.L0f118d08:
/*  f118d08:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f118d0c:
/*  f118d0c:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f118d10:	03e00008 */ 	jr	$ra
/*  f118d14:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f118d18
/*  f118d18:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f118d1c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f118d20:	00049e00 */ 	sll	$s3,$a0,0x18
/*  f118d24:	00137603 */ 	sra	$t6,$s3,0x18
/*  f118d28:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f118d2c:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f118d30:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f118d34:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f118d38:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f118d3c:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f118d40:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f118d44:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f118d48:	00a0a825 */ 	or	$s5,$a1,$zero
/*  f118d4c:	00c0b025 */ 	or	$s6,$a2,$zero
/*  f118d50:	01c09825 */ 	or	$s3,$t6,$zero
/*  f118d54:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f118d58:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f118d5c:	00008025 */ 	or	$s0,$zero,$zero
/*  f118d60:	00008825 */ 	or	$s1,$zero,$zero
/*  f118d64:	0fc464a6 */ 	jal	func0f119298
/*  f118d68:	01e02025 */ 	or	$a0,$t7,$zero
/*  f118d6c:	10400003 */ 	beqz	$v0,.L0f118d7c
/*  f118d70:	00132600 */ 	sll	$a0,$s3,0x18
/*  f118d74:	10000045 */ 	beqz	$zero,.L0f118e8c
/*  f118d78:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f118d7c:
/*  f118d7c:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f118d80:	03002025 */ 	or	$a0,$t8,$zero
/*  f118d84:	0fc46dd7 */ 	jal	func0f11b75c
/*  f118d88:	27a50048 */ 	addiu	$a1,$sp,0x48
/*  f118d8c:	10400003 */ 	beqz	$v0,.L0f118d9c
/*  f118d90:	00132600 */ 	sll	$a0,$s3,0x18
/*  f118d94:	1000003d */ 	beqz	$zero,.L0f118e8c
/*  f118d98:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f118d9c:
/*  f118d9c:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f118da0:	0fc459f6 */ 	jal	func0f1167d8
/*  f118da4:	03202025 */ 	or	$a0,$t9,$zero
/*  f118da8:	10400007 */ 	beqz	$v0,.L0f118dc8
/*  f118dac:	27b40050 */ 	addiu	$s4,$sp,0x50
/*  f118db0:	00132600 */ 	sll	$a0,$s3,0x18
/*  f118db4:	00044603 */ 	sra	$t0,$a0,0x18
/*  f118db8:	0fc459f6 */ 	jal	func0f1167d8
/*  f118dbc:	01002025 */ 	or	$a0,$t0,$zero
/*  f118dc0:	10000032 */ 	beqz	$zero,.L0f118e8c
/*  f118dc4:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f118dc8:
/*  f118dc8:	00132600 */ 	sll	$a0,$s3,0x18
/*  f118dcc:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f118dd0:	01202025 */ 	or	$a0,$t1,$zero
/*  f118dd4:	00002825 */ 	or	$a1,$zero,$zero
/*  f118dd8:	0fc45d48 */ 	jal	func0f117520
/*  f118ddc:	02803025 */ 	or	$a2,$s4,$zero
/*  f118de0:	1440001c */ 	bnez	$v0,.L0f118e54
/*  f118de4:	32b20100 */ 	andi	$s2,$s5,0x100
.L0f118de8:
/*  f118de8:	16400006 */ 	bnez	$s2,.L0f118e04
/*  f118dec:	00132600 */ 	sll	$a0,$s3,0x18
/*  f118df0:	8faa0058 */ 	lw	$t2,0x58($sp)
/*  f118df4:	000a5dc2 */ 	srl	$t3,$t2,0x17
/*  f118df8:	02ab6024 */ 	and	$t4,$s5,$t3
/*  f118dfc:	51800009 */ 	beqzl	$t4,.L0f118e24
/*  f118e00:	8fa80058 */ 	lw	$t0,0x58($sp)
.L0f118e04:
/*  f118e04:	8fad005c */ 	lw	$t5,0x5c($sp)
/*  f118e08:	0011c080 */ 	sll	$t8,$s1,0x2
/*  f118e0c:	02d8c821 */ 	addu	$t9,$s6,$t8
/*  f118e10:	000d7340 */ 	sll	$t6,$t5,0xd
/*  f118e14:	000e7e42 */ 	srl	$t7,$t6,0x19
/*  f118e18:	af2f0000 */ 	sw	$t7,0x0($t9)
/*  f118e1c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f118e20:	8fa80058 */ 	lw	$t0,0x58($sp)
.L0f118e24:
/*  f118e24:	8faa0048 */ 	lw	$t2,0x48($sp)
/*  f118e28:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f118e2c:	31090fff */ 	andi	$t1,$t0,0xfff
/*  f118e30:	02098021 */ 	addu	$s0,$s0,$t1
/*  f118e34:	020a082b */ 	sltu	$at,$s0,$t2
/*  f118e38:	10200006 */ 	beqz	$at,.L0f118e54
/*  f118e3c:	01602025 */ 	or	$a0,$t3,$zero
/*  f118e40:	02002825 */ 	or	$a1,$s0,$zero
/*  f118e44:	0fc45d48 */ 	jal	func0f117520
/*  f118e48:	02803025 */ 	or	$a2,$s4,$zero
/*  f118e4c:	1040ffe6 */ 	beqz	$v0,.L0f118de8
/*  f118e50:	00000000 */ 	sll	$zero,$zero,0x0
.L0f118e54:
/*  f118e54:	00116080 */ 	sll	$t4,$s1,0x2
/*  f118e58:	02cc6821 */ 	addu	$t5,$s6,$t4
/*  f118e5c:	24010007 */ 	addiu	$at,$zero,0x7
/*  f118e60:	14410003 */ 	bne	$v0,$at,.L0f118e70
/*  f118e64:	ada00000 */ 	sw	$zero,0x0($t5)
/*  f118e68:	10000007 */ 	beqz	$zero,.L0f118e88
/*  f118e6c:	24020007 */ 	addiu	$v0,$zero,0x7
.L0f118e70:
/*  f118e70:	24010001 */ 	addiu	$at,$zero,0x1
/*  f118e74:	54410004 */ 	bnel	$v0,$at,.L0f118e88
/*  f118e78:	00001025 */ 	or	$v0,$zero,$zero
/*  f118e7c:	10000002 */ 	beqz	$zero,.L0f118e88
/*  f118e80:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f118e84:	00001025 */ 	or	$v0,$zero,$zero
.L0f118e88:
/*  f118e88:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f118e8c:
/*  f118e8c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f118e90:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f118e94:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f118e98:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f118e9c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f118ea0:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f118ea4:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f118ea8:	03e00008 */ 	jr	$ra
/*  f118eac:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f118eb0:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f118eb4:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f118eb8:	00049e00 */ 	sll	$s3,$a0,0x18
/*  f118ebc:	00137603 */ 	sra	$t6,$s3,0x18
/*  f118ec0:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f118ec4:	f7b40010 */ 	sdc1	$f20,0x10($sp)
/*  f118ec8:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f118ecc:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f118ed0:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f118ed4:	4480a000 */ 	mtc1	$zero,$f20
/*  f118ed8:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f118edc:	01c09825 */ 	or	$s3,$t6,$zero
/*  f118ee0:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f118ee4:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f118ee8:	f7b60018 */ 	sdc1	$f22,0x18($sp)
/*  f118eec:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f118ef0:	00008025 */ 	or	$s0,$zero,$zero
/*  f118ef4:	0fc459f6 */ 	jal	func0f1167d8
/*  f118ef8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f118efc:	10400003 */ 	beqz	$v0,.L0f118f0c
/*  f118f00:	27b20048 */ 	addiu	$s2,$sp,0x48
/*  f118f04:	10000055 */ 	beqz	$zero,.L0f11905c
/*  f118f08:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f118f0c:
/*  f118f0c:	00132600 */ 	sll	$a0,$s3,0x18
/*  f118f10:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f118f14:	03002025 */ 	or	$a0,$t8,$zero
/*  f118f18:	00002825 */ 	or	$a1,$zero,$zero
/*  f118f1c:	0fc45d48 */ 	jal	func0f117520
/*  f118f20:	02403025 */ 	or	$a2,$s2,$zero
/*  f118f24:	14400011 */ 	bnez	$v0,.L0f118f6c
/*  f118f28:	3c013f80 */ 	lui	$at,0x3f80
/*  f118f2c:	4481b000 */ 	mtc1	$at,$f22
/*  f118f30:	24110002 */ 	addiu	$s1,$zero,0x2
/*  f118f34:	8fa20050 */ 	lw	$v0,0x50($sp)
.L0f118f38:
/*  f118f38:	00132600 */ 	sll	$a0,$s3,0x18
/*  f118f3c:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f118f40:	0002cdc2 */ 	srl	$t9,$v0,0x17
/*  f118f44:	17310002 */ 	bne	$t9,$s1,.L0f118f50
/*  f118f48:	30480fff */ 	andi	$t0,$v0,0xfff
/*  f118f4c:	4616a500 */ 	add.s	$f20,$f20,$f22
.L0f118f50:
/*  f118f50:	02088021 */ 	addu	$s0,$s0,$t0
/*  f118f54:	02002825 */ 	or	$a1,$s0,$zero
/*  f118f58:	01202025 */ 	or	$a0,$t1,$zero
/*  f118f5c:	0fc45d48 */ 	jal	func0f117520
/*  f118f60:	02403025 */ 	or	$a2,$s2,$zero
/*  f118f64:	5040fff4 */ 	beqzl	$v0,.L0f118f38
/*  f118f68:	8fa20050 */ 	lw	$v0,0x50($sp)
.L0f118f6c:
/*  f118f6c:	00135080 */ 	sll	$t2,$s3,0x2
/*  f118f70:	01535023 */ 	subu	$t2,$t2,$s3
/*  f118f74:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f118f78:	01535023 */ 	subu	$t2,$t2,$s3
/*  f118f7c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f118f80:	01535021 */ 	addu	$t2,$t2,$s3
/*  f118f84:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f118f88:	01535023 */ 	subu	$t2,$t2,$s3
/*  f118f8c:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f118f90:	3c0b800a */ 	lui	$t3,0x800a
/*  f118f94:	016a5821 */ 	addu	$t3,$t3,$t2
/*  f118f98:	8d6b2624 */ 	lw	$t3,0x2624($t3)
/*  f118f9c:	3c0142c8 */ 	lui	$at,0x42c8
/*  f118fa0:	44812000 */ 	mtc1	$at,$f4
/*  f118fa4:	448b3000 */ 	mtc1	$t3,$f6
/*  f118fa8:	8fae005c */ 	lw	$t6,0x5c($sp)
/*  f118fac:	05610005 */ 	bgez	$t3,.L0f118fc4
/*  f118fb0:	46803220 */ 	cvt.s.w	$f8,$f6
/*  f118fb4:	3c014f80 */ 	lui	$at,0x4f80
/*  f118fb8:	44815000 */ 	mtc1	$at,$f10
/*  f118fbc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118fc0:	460a4200 */ 	add.s	$f8,$f8,$f10
.L0f118fc4:
/*  f118fc4:	46082403 */ 	div.s	$f16,$f4,$f8
/*  f118fc8:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f118fcc:	3c014f00 */ 	lui	$at,0x4f00
/*  f118fd0:	46148482 */ 	mul.s	$f18,$f16,$f20
/*  f118fd4:	444cf800 */ 	cfc1	$t4,$31
/*  f118fd8:	44cdf800 */ 	ctc1	$t5,$31
/*  f118fdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118fe0:	460091a4 */ 	cvt.w.s	$f6,$f18
/*  f118fe4:	444df800 */ 	cfc1	$t5,$31
/*  f118fe8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f118fec:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f118ff0:	51a00013 */ 	beqzl	$t5,.L0f119040
/*  f118ff4:	440d3000 */ 	mfc1	$t5,$f6
/*  f118ff8:	44813000 */ 	mtc1	$at,$f6
/*  f118ffc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f119000:	46069181 */ 	sub.s	$f6,$f18,$f6
/*  f119004:	44cdf800 */ 	ctc1	$t5,$31
/*  f119008:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11900c:	460031a4 */ 	cvt.w.s	$f6,$f6
/*  f119010:	444df800 */ 	cfc1	$t5,$31
/*  f119014:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119018:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f11901c:	15a00005 */ 	bnez	$t5,.L0f119034
/*  f119020:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119024:	440d3000 */ 	mfc1	$t5,$f6
/*  f119028:	3c018000 */ 	lui	$at,0x8000
/*  f11902c:	10000007 */ 	beqz	$zero,.L0f11904c
/*  f119030:	01a16825 */ 	or	$t5,$t5,$at
.L0f119034:
/*  f119034:	10000005 */ 	beqz	$zero,.L0f11904c
/*  f119038:	240dffff */ 	addiu	$t5,$zero,-1
/*  f11903c:	440d3000 */ 	mfc1	$t5,$f6
.L0f119040:
/*  f119040:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119044:	05a0fffb */ 	bltz	$t5,.L0f119034
/*  f119048:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11904c:
/*  f11904c:	44ccf800 */ 	ctc1	$t4,$31
/*  f119050:	adcd0000 */ 	sw	$t5,0x0($t6)
/*  f119054:	00001025 */ 	or	$v0,$zero,$zero
/*  f119058:	8fbf0034 */ 	lw	$ra,0x34($sp)
.L0f11905c:
/*  f11905c:	d7b40010 */ 	ldc1	$f20,0x10($sp)
/*  f119060:	d7b60018 */ 	ldc1	$f22,0x18($sp)
/*  f119064:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f119068:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f11906c:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f119070:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f119074:	03e00008 */ 	jr	$ra
/*  f119078:	27bd0058 */ 	addiu	$sp,$sp,0x58
/*  f11907c:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f119080:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f119084:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f119088:	0fc459f6 */ 	jal	func0f1167d8
/*  f11908c:	83a4001b */ 	lb	$a0,0x1b($sp)
/*  f119090:	10400003 */ 	beqz	$v0,.L0f1190a0
/*  f119094:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119098:	10000005 */ 	beqz	$zero,.L0f1190b0
/*  f11909c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1190a0:
/*  f1190a0:	0fc46874 */ 	jal	func0f11a1d0
/*  f1190a4:	83a4001b */ 	lb	$a0,0x1b($sp)
/*  f1190a8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1190ac:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f1190b0:
/*  f1190b0:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f1190b4:	03e00008 */ 	jr	$ra
/*  f1190b8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1190bc
/*  f1190bc:	27bdffa0 */ 	addiu	$sp,$sp,-96
/*  f1190c0:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f1190c4:	00049e00 */ 	sll	$s3,$a0,0x18
/*  f1190c8:	00137603 */ 	sra	$t6,$s3,0x18
/*  f1190cc:	afa40060 */ 	sw	$a0,0x60($sp)
/*  f1190d0:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f1190d4:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f1190d8:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f1190dc:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f1190e0:	00c08825 */ 	or	$s1,$a2,$zero
/*  f1190e4:	01c09825 */ 	or	$s3,$t6,$zero
/*  f1190e8:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f1190ec:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f1190f0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f1190f4:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f1190f8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1190fc:	0fc45c25 */ 	jal	func0f117094
/*  f119100:	01e02025 */ 	or	$a0,$t7,$zero
/*  f119104:	00132600 */ 	sll	$a0,$s3,0x18
/*  f119108:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f11910c:	03002025 */ 	or	$a0,$t8,$zero
/*  f119110:	0fc45996 */ 	jal	func0f116658
/*  f119114:	00402825 */ 	or	$a1,$v0,$zero
/*  f119118:	00132600 */ 	sll	$a0,$s3,0x18
/*  f11911c:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f119120:	0040a825 */ 	or	$s5,$v0,$zero
/*  f119124:	0000b025 */ 	or	$s6,$zero,$zero
/*  f119128:	03202025 */ 	or	$a0,$t9,$zero
/*  f11912c:	0fc46dd7 */ 	jal	func0f11b75c
/*  f119130:	27a50044 */ 	addiu	$a1,$sp,0x44
/*  f119134:	12200002 */ 	beqz	$s1,.L0f119140
/*  f119138:	27b40050 */ 	addiu	$s4,$sp,0x50
/*  f11913c:	ae200000 */ 	sw	$zero,0x0($s1)
.L0f119140:
/*  f119140:	00132600 */ 	sll	$a0,$s3,0x18
/*  f119144:	00044603 */ 	sra	$t0,$a0,0x18
/*  f119148:	01002025 */ 	or	$a0,$t0,$zero
/*  f11914c:	00008025 */ 	or	$s0,$zero,$zero
/*  f119150:	00002825 */ 	or	$a1,$zero,$zero
/*  f119154:	0fc45d48 */ 	jal	func0f117520
/*  f119158:	02803025 */ 	or	$a2,$s4,$zero
/*  f11915c:	1440001f */ 	bnez	$v0,.L0f1191dc
/*  f119160:	8fa90044 */ 	lw	$t1,0x44($sp)
/*  f119164:	5120001e */ 	beqzl	$t1,.L0f1191e0
/*  f119168:	0013c880 */ 	sll	$t9,$s3,0x2
/*  f11916c:	24120002 */ 	addiu	$s2,$zero,0x2
/*  f119170:	8fa20058 */ 	lw	$v0,0x58($sp)
.L0f119174:
/*  f119174:	00132600 */ 	sll	$a0,$s3,0x18
/*  f119178:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f11917c:	000255c2 */ 	srl	$t2,$v0,0x17
/*  f119180:	1552000b */ 	bne	$t2,$s2,.L0f1191b0
/*  f119184:	01e02025 */ 	or	$a0,$t7,$zero
/*  f119188:	304b0fff */ 	andi	$t3,$v0,0xfff
/*  f11918c:	0175082b */ 	sltu	$at,$t3,$s5
/*  f119190:	54200008 */ 	bnezl	$at,.L0f1191b4
/*  f119194:	304e0fff */ 	andi	$t6,$v0,0xfff
/*  f119198:	12200005 */ 	beqz	$s1,.L0f1191b0
/*  f11919c:	24160001 */ 	addiu	$s6,$zero,0x1
/*  f1191a0:	8e2c0000 */ 	lw	$t4,0x0($s1)
/*  f1191a4:	258d0001 */ 	addiu	$t5,$t4,0x1
/*  f1191a8:	ae2d0000 */ 	sw	$t5,0x0($s1)
/*  f1191ac:	8fa20058 */ 	lw	$v0,0x58($sp)
.L0f1191b0:
/*  f1191b0:	304e0fff */ 	andi	$t6,$v0,0xfff
.L0f1191b4:
/*  f1191b4:	020e8021 */ 	addu	$s0,$s0,$t6
/*  f1191b8:	02002825 */ 	or	$a1,$s0,$zero
/*  f1191bc:	0fc45d48 */ 	jal	func0f117520
/*  f1191c0:	02803025 */ 	or	$a2,$s4,$zero
/*  f1191c4:	54400006 */ 	bnezl	$v0,.L0f1191e0
/*  f1191c8:	0013c880 */ 	sll	$t9,$s3,0x2
/*  f1191cc:	8fb80044 */ 	lw	$t8,0x44($sp)
/*  f1191d0:	0218082b */ 	sltu	$at,$s0,$t8
/*  f1191d4:	5420ffe7 */ 	bnezl	$at,.L0f119174
/*  f1191d8:	8fa20058 */ 	lw	$v0,0x58($sp)
.L0f1191dc:
/*  f1191dc:	0013c880 */ 	sll	$t9,$s3,0x2
.L0f1191e0:
/*  f1191e0:	0333c823 */ 	subu	$t9,$t9,$s3
/*  f1191e4:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1191e8:	0333c823 */ 	subu	$t9,$t9,$s3
/*  f1191ec:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1191f0:	0333c821 */ 	addu	$t9,$t9,$s3
/*  f1191f4:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f1191f8:	0333c823 */ 	subu	$t9,$t9,$s3
/*  f1191fc:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f119200:	3c08800a */ 	lui	$t0,0x800a
/*  f119204:	01194021 */ 	addu	$t0,$t0,$t9
/*  f119208:	8d082620 */ 	lw	$t0,0x2620($t0)
/*  f11920c:	8fa90044 */ 	lw	$t1,0x44($sp)
/*  f119210:	00132600 */ 	sll	$a0,$s3,0x18
/*  f119214:	12200009 */ 	beqz	$s1,.L0f11923c
/*  f119218:	01098023 */ 	subu	$s0,$t0,$t1
/*  f11921c:	0215001b */ 	divu	$zero,$s0,$s5
/*  f119220:	8e2a0000 */ 	lw	$t2,0x0($s1)
/*  f119224:	00005812 */ 	mflo	$t3
/*  f119228:	014b6021 */ 	addu	$t4,$t2,$t3
/*  f11922c:	ae2c0000 */ 	sw	$t4,0x0($s1)
/*  f119230:	16a00002 */ 	bnez	$s5,.L0f11923c
/*  f119234:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119238:	0007000d */ 	break	0x7
.L0f11923c:
/*  f11923c:	16c00007 */ 	bnez	$s6,.L0f11925c
/*  f119240:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f119244:	0fc45c1b */ 	jal	func0f11706c
/*  f119248:	01a02025 */ 	or	$a0,$t5,$zero
/*  f11924c:	0202082b */ 	sltu	$at,$s0,$v0
/*  f119250:	14200002 */ 	bnez	$at,.L0f11925c
/*  f119254:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119258:	24160001 */ 	addiu	$s6,$zero,0x1
.L0f11925c:
/*  f11925c:	12c00003 */ 	beqz	$s6,.L0f11926c
/*  f119260:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f119264:	10000002 */ 	beqz	$zero,.L0f119270
/*  f119268:	00001825 */ 	or	$v1,$zero,$zero
.L0f11926c:
/*  f11926c:	24030005 */ 	addiu	$v1,$zero,0x5
.L0f119270:
/*  f119270:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f119274:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f119278:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f11927c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f119280:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f119284:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f119288:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f11928c:	27bd0060 */ 	addiu	$sp,$sp,0x60
/*  f119290:	03e00008 */ 	jr	$ra
/*  f119294:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f119298
/*  f119298:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11929c:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f1192a0:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f1192a4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1192a8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1192ac:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1192b0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1192b4:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f1192b8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1192bc:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f1192c0:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f1192c4:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f1192c8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f1192cc:	03191021 */ 	addu	$v0,$t8,$t9
/*  f1192d0:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f1192d4:	24010002 */ 	addiu	$at,$zero,0x2
/*  f1192d8:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f1192dc:	51010004 */ 	beql	$t0,$at,.L0f1192f0
/*  f1192e0:	8c490010 */ 	lw	$t1,0x10($v0)
/*  f1192e4:	03e00008 */ 	jr	$ra
/*  f1192e8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1192ec:	8c490010 */ 	lw	$t1,0x10($v0)
.L0f1192f0:
/*  f1192f0:	252afffd */ 	addiu	$t2,$t1,-3
/*  f1192f4:	2d410010 */ 	sltiu	$at,$t2,0x10
/*  f1192f8:	1020000e */ 	beqz	$at,.L0f119334
/*  f1192fc:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f119300:	3c017f1b */ 	lui	$at,%hi(var7f1b4e30)
/*  f119304:	002a0821 */ 	addu	$at,$at,$t2
/*  f119308:	8c2a4e30 */ 	lw	$t2,%lo(var7f1b4e30)($at)
/*  f11930c:	01400008 */ 	jr	$t2
/*  f119310:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119314:	03e00008 */ 	jr	$ra
/*  f119318:	00001025 */ 	or	$v0,$zero,$zero
/*  f11931c:	03e00008 */ 	jr	$ra
/*  f119320:	2402000e */ 	addiu	$v0,$zero,0xe
/*  f119324:	03e00008 */ 	jr	$ra
/*  f119328:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f11932c:	03e00008 */ 	jr	$ra
/*  f119330:	2402000d */ 	addiu	$v0,$zero,0xd
.L0f119334:
/*  f119334:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f119338:	03e00008 */ 	jr	$ra
/*  f11933c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f119340
/*  f119340:	2c81000b */ 	sltiu	$at,$a0,0xb
/*  f119344:	10200006 */ 	beqz	$at,.L0f119360
/*  f119348:	00047080 */ 	sll	$t6,$a0,0x2
/*  f11934c:	3c017f1b */ 	lui	$at,%hi(var7f1b4e70)
/*  f119350:	002e0821 */ 	addu	$at,$at,$t6
/*  f119354:	8c2e4e70 */ 	lw	$t6,%lo(var7f1b4e70)($at)
/*  f119358:	01c00008 */ 	jr	$t6
/*  f11935c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f119360:
/*  f119360:	03e00008 */ 	jr	$ra
/*  f119364:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f119368
/*  f119368:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f11936c:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f119370:	00048e00 */ 	sll	$s1,$a0,0x18
/*  f119374:	00117603 */ 	sra	$t6,$s1,0x18
/*  f119378:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f11937c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f119380:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f119384:	00a09025 */ 	or	$s2,$a1,$zero
/*  f119388:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f11938c:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f119390:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f119394:	01c08825 */ 	or	$s1,$t6,$zero
/*  f119398:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f11939c:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f1193a0:	00008025 */ 	or	$s0,$zero,$zero
/*  f1193a4:	01e02025 */ 	or	$a0,$t7,$zero
/*  f1193a8:	0fc46dd7 */ 	jal	func0f11b75c
/*  f1193ac:	27a50030 */ 	addiu	$a1,$sp,0x30
/*  f1193b0:	00112600 */ 	sll	$a0,$s1,0x18
/*  f1193b4:	27b30038 */ 	addiu	$s3,$sp,0x38
/*  f1193b8:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f1193bc:	03002025 */ 	or	$a0,$t8,$zero
/*  f1193c0:	02603025 */ 	or	$a2,$s3,$zero
/*  f1193c4:	0fc45d48 */ 	jal	func0f117520
/*  f1193c8:	00002825 */ 	or	$a1,$zero,$zero
/*  f1193cc:	1440001d */ 	bnez	$v0,.L0f119444
/*  f1193d0:	8fb90030 */ 	lw	$t9,0x30($sp)
/*  f1193d4:	5320001c */ 	beqzl	$t9,.L0f119448
/*  f1193d8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1193dc:	8fa80044 */ 	lw	$t0,0x44($sp)
.L0f1193e0:
/*  f1193e0:	8fab0040 */ 	lw	$t3,0x40($sp)
/*  f1193e4:	00112600 */ 	sll	$a0,$s1,0x18
/*  f1193e8:	00084b40 */ 	sll	$t1,$t0,0xd
/*  f1193ec:	00095642 */ 	srl	$t2,$t1,0x19
/*  f1193f0:	164a0009 */ 	bne	$s2,$t2,.L0f119418
/*  f1193f4:	316c0fff */ 	andi	$t4,$t3,0xfff
/*  f1193f8:	8fa40050 */ 	lw	$a0,0x50($sp)
/*  f1193fc:	02602825 */ 	or	$a1,$s3,$zero
/*  f119400:	10800003 */ 	beqz	$a0,.L0f119410
/*  f119404:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119408:	0c012978 */ 	jal	func0004a5e0
/*  f11940c:	24060010 */ 	addiu	$a2,$zero,0x10
.L0f119410:
/*  f119410:	10000012 */ 	beqz	$zero,.L0f11945c
/*  f119414:	02001025 */ 	or	$v0,$s0,$zero
.L0f119418:
/*  f119418:	020c8021 */ 	addu	$s0,$s0,$t4
/*  f11941c:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f119420:	01a02025 */ 	or	$a0,$t5,$zero
/*  f119424:	02002825 */ 	or	$a1,$s0,$zero
/*  f119428:	0fc45d48 */ 	jal	func0f117520
/*  f11942c:	02603025 */ 	or	$a2,$s3,$zero
/*  f119430:	14400004 */ 	bnez	$v0,.L0f119444
/*  f119434:	8fae0030 */ 	lw	$t6,0x30($sp)
/*  f119438:	020e082b */ 	sltu	$at,$s0,$t6
/*  f11943c:	5420ffe8 */ 	bnezl	$at,.L0f1193e0
/*  f119440:	8fa80044 */ 	lw	$t0,0x44($sp)
.L0f119444:
/*  f119444:	24010001 */ 	addiu	$at,$zero,0x1
.L0f119448:
/*  f119448:	54410004 */ 	bnel	$v0,$at,.L0f11945c
/*  f11944c:	3402ffff */ 	dli	$v0,0xffff
/*  f119450:	10000002 */ 	beqz	$zero,.L0f11945c
/*  f119454:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f119458:	3402ffff */ 	dli	$v0,0xffff
.L0f11945c:
/*  f11945c:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f119460:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f119464:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f119468:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f11946c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f119470:	03e00008 */ 	jr	$ra
/*  f119474:	27bd0048 */ 	addiu	$sp,$sp,0x48
);

GLOBAL_ASM(
glabel func0f119478
/*  f119478:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f11947c:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f119480:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f119484:	afa50034 */ 	sw	$a1,0x34($sp)
/*  f119488:	8cc40008 */ 	lw	$a0,0x8($a2)
/*  f11948c:	308e0fff */ 	andi	$t6,$a0,0xfff
/*  f119490:	0fc459a1 */ 	jal	func0f116684
/*  f119494:	01c02025 */ 	or	$a0,$t6,$zero
/*  f119498:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f11949c:	afaf0020 */ 	sw	$t7,0x20($sp)
/*  f1194a0:	83a40033 */ 	lb	$a0,0x33($sp)
/*  f1194a4:	8fa50034 */ 	lw	$a1,0x34($sp)
/*  f1194a8:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f1194ac:	00003825 */ 	or	$a3,$zero,$zero
/*  f1194b0:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f1194b4:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1194b8:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1194bc:	0fc46f15 */ 	jal	func0f11bc54
/*  f1194c0:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f1194c4:	14400003 */ 	bnez	$v0,.L0f1194d4
/*  f1194c8:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1194cc:	10000002 */ 	beqz	$zero,.L0f1194d8
/*  f1194d0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1194d4:
/*  f1194d4:	00001025 */ 	or	$v0,$zero,$zero
.L0f1194d8:
/*  f1194d8:	03e00008 */ 	jr	$ra
/*  f1194dc:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f1194e0
/*  f1194e0:	27bdff70 */ 	addiu	$sp,$sp,-144
/*  f1194e4:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f1194e8:	00048e00 */ 	sll	$s1,$a0,0x18
/*  f1194ec:	00117603 */ 	sra	$t6,$s1,0x18
/*  f1194f0:	afa40090 */ 	sw	$a0,0x90($sp)
/*  f1194f4:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f1194f8:	afbf0054 */ 	sw	$ra,0x54($sp)
/*  f1194fc:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f119500:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f119504:	00c09025 */ 	or	$s2,$a2,$zero
/*  f119508:	01c08825 */ 	or	$s1,$t6,$zero
/*  f11950c:	afbe0050 */ 	sw	$s8,0x50($sp)
/*  f119510:	afb7004c */ 	sw	$s7,0x4c($sp)
/*  f119514:	afb60048 */ 	sw	$s6,0x48($sp)
/*  f119518:	afb50044 */ 	sw	$s5,0x44($sp)
/*  f11951c:	afb40040 */ 	sw	$s4,0x40($sp)
/*  f119520:	afb3003c */ 	sw	$s3,0x3c($sp)
/*  f119524:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f119528:	afa50094 */ 	sw	$a1,0x94($sp)
/*  f11952c:	0fc45c1b */ 	jal	func0f11706c
/*  f119530:	01e02025 */ 	or	$a0,$t7,$zero
/*  f119534:	8fb80094 */ 	lw	$t8,0x94($sp)
/*  f119538:	00114880 */ 	sll	$t1,$s1,0x2
/*  f11953c:	01314823 */ 	subu	$t1,$t1,$s1
/*  f119540:	8f030000 */ 	lw	$v1,0x0($t8)
/*  f119544:	0040b825 */ 	or	$s7,$v0,$zero
/*  f119548:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11954c:	0060b025 */ 	or	$s6,$v1,$zero
/*  f119550:	0060f025 */ 	or	$s8,$v1,$zero
/*  f119554:	12400004 */ 	beqz	$s2,.L0f119568
/*  f119558:	00608025 */ 	or	$s0,$v1,$zero
/*  f11955c:	8e590008 */ 	lw	$t9,0x8($s2)
/*  f119560:	33280fff */ 	andi	$t0,$t9,0xfff
/*  f119564:	00688021 */ 	addu	$s0,$v1,$t0
.L0f119568:
/*  f119568:	01314823 */ 	subu	$t1,$t1,$s1
/*  f11956c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f119570:	01314821 */ 	addu	$t1,$t1,$s1
/*  f119574:	00094880 */ 	sll	$t1,$t1,0x2
/*  f119578:	01314823 */ 	subu	$t1,$t1,$s1
/*  f11957c:	3c0a800a */ 	lui	$t2,%hi(var800a2380)
/*  f119580:	254a2380 */ 	addiu	$t2,$t2,%lo(var800a2380)
/*  f119584:	00094880 */ 	sll	$t1,$t1,0x2
/*  f119588:	012aa821 */ 	addu	$s5,$t1,$t2
/*  f11958c:	8eab02a0 */ 	lw	$t3,0x2a0($s5)
/*  f119590:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f119594:	24130004 */ 	addiu	$s3,$zero,0x4
/*  f119598:	020b082b */ 	sltu	$at,$s0,$t3
/*  f11959c:	10200038 */ 	beqz	$at,.L0f119680
/*  f1195a0:	27b20080 */ 	addiu	$s2,$sp,0x80
/*  f1195a4:	00112600 */ 	sll	$a0,$s1,0x18
.L0f1195a8:
/*  f1195a8:	00046603 */ 	sra	$t4,$a0,0x18
/*  f1195ac:	01802025 */ 	or	$a0,$t4,$zero
/*  f1195b0:	02002825 */ 	or	$a1,$s0,$zero
/*  f1195b4:	0fc45d48 */ 	jal	func0f117520
/*  f1195b8:	02403025 */ 	or	$a2,$s2,$zero
/*  f1195bc:	14400009 */ 	bnez	$v0,.L0f1195e4
/*  f1195c0:	8fad0088 */ 	lw	$t5,0x88($sp)
/*  f1195c4:	000d75c2 */ 	srl	$t6,$t5,0x17
/*  f1195c8:	31cf0002 */ 	andi	$t7,$t6,0x2
/*  f1195cc:	15e00009 */ 	bnez	$t7,.L0f1195f4
/*  f1195d0:	03d0082b */ 	sltu	$at,$s8,$s0
/*  f1195d4:	50200008 */ 	beqzl	$at,.L0f1195f8
/*  f1195d8:	00112600 */ 	sll	$a0,$s1,0x18
/*  f1195dc:	10000028 */ 	beqz	$zero,.L0f119680
/*  f1195e0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f1195e4:
/*  f1195e4:	54540004 */ 	bnel	$v0,$s4,.L0f1195f8
/*  f1195e8:	00112600 */ 	sll	$a0,$s1,0x18
/*  f1195ec:	1000003b */ 	beqz	$zero,.L0f1196dc
/*  f1195f0:	00001025 */ 	or	$v0,$zero,$zero
.L0f1195f4:
/*  f1195f4:	00112600 */ 	sll	$a0,$s1,0x18
.L0f1195f8:
/*  f1195f8:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f1195fc:	0fc45974 */ 	jal	func0f1165d0
/*  f119600:	03002025 */ 	or	$a0,$t8,$zero
/*  f119604:	12330009 */ 	beq	$s1,$s3,.L0f11962c
/*  f119608:	02028021 */ 	addu	$s0,$s0,$v0
/*  f11960c:	0216c823 */ 	subu	$t9,$s0,$s6
/*  f119610:	02f9082b */ 	sltu	$at,$s7,$t9
/*  f119614:	50200006 */ 	beqzl	$at,.L0f119630
/*  f119618:	8ea202a0 */ 	lw	$v0,0x2a0($s5)
/*  f11961c:	8fa80094 */ 	lw	$t0,0x94($sp)
/*  f119620:	00001025 */ 	or	$v0,$zero,$zero
/*  f119624:	1000002d */ 	beqz	$zero,.L0f1196dc
/*  f119628:	ad100000 */ 	sw	$s0,0x0($t0)
.L0f11962c:
/*  f11962c:	8ea202a0 */ 	lw	$v0,0x2a0($s5)
.L0f119630:
/*  f119630:	0202082b */ 	sltu	$at,$s0,$v0
/*  f119634:	1420000f */ 	bnez	$at,.L0f119674
/*  f119638:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11963c:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f119640:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f119644:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f119648:	01202025 */ 	or	$a0,$t1,$zero
/*  f11964c:	02c02825 */ 	or	$a1,$s6,$zero
/*  f119650:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f119654:	00003825 */ 	or	$a3,$zero,$zero
/*  f119658:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f11965c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f119660:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f119664:	0fc46f15 */ 	jal	func0f11bc54
/*  f119668:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f11966c:	1000001b */ 	beqz	$zero,.L0f1196dc
/*  f119670:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f119674:
/*  f119674:	0202082b */ 	sltu	$at,$s0,$v0
/*  f119678:	5420ffcb */ 	bnezl	$at,.L0f1195a8
/*  f11967c:	00112600 */ 	sll	$a0,$s1,0x18
.L0f119680:
/*  f119680:	0fc459a1 */ 	jal	func0f116684
/*  f119684:	02162023 */ 	subu	$a0,$s0,$s6
/*  f119688:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11968c:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f119690:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f119694:	afac0020 */ 	sw	$t4,0x20($sp)
/*  f119698:	01602025 */ 	or	$a0,$t3,$zero
/*  f11969c:	02c02825 */ 	or	$a1,$s6,$zero
/*  f1196a0:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f1196a4:	00003825 */ 	or	$a3,$zero,$zero
/*  f1196a8:	afa20010 */ 	sw	$v0,0x10($sp)
/*  f1196ac:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f1196b0:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f1196b4:	0fc46f15 */ 	jal	func0f11bc54
/*  f1196b8:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f1196bc:	10400005 */ 	beqz	$v0,.L0f1196d4
/*  f1196c0:	8fae0094 */ 	lw	$t6,0x94($sp)
/*  f1196c4:	8fad0094 */ 	lw	$t5,0x94($sp)
/*  f1196c8:	00001025 */ 	or	$v0,$zero,$zero
/*  f1196cc:	10000003 */ 	beqz	$zero,.L0f1196dc
/*  f1196d0:	adb00000 */ 	sw	$s0,0x0($t5)
.L0f1196d4:
/*  f1196d4:	add00000 */ 	sw	$s0,0x0($t6)
/*  f1196d8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1196dc:
/*  f1196dc:	8fbf0054 */ 	lw	$ra,0x54($sp)
/*  f1196e0:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f1196e4:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f1196e8:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f1196ec:	8fb3003c */ 	lw	$s3,0x3c($sp)
/*  f1196f0:	8fb40040 */ 	lw	$s4,0x40($sp)
/*  f1196f4:	8fb50044 */ 	lw	$s5,0x44($sp)
/*  f1196f8:	8fb60048 */ 	lw	$s6,0x48($sp)
/*  f1196fc:	8fb7004c */ 	lw	$s7,0x4c($sp)
/*  f119700:	8fbe0050 */ 	lw	$s8,0x50($sp)
/*  f119704:	03e00008 */ 	jr	$ra
/*  f119708:	27bd0090 */ 	addiu	$sp,$sp,0x90
);

GLOBAL_ASM(
glabel func0f11970c
/*  f11970c:	27bdf850 */ 	addiu	$sp,$sp,-1968
/*  f119710:	afb50040 */ 	sw	$s5,0x40($sp)
/*  f119714:	0004ae00 */ 	sll	$s5,$a0,0x18
/*  f119718:	00157603 */ 	sra	$t6,$s5,0x18
/*  f11971c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f119720:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f119724:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f119728:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11972c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f119730:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f119734:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f119738:	afa407b0 */ 	sw	$a0,0x7b0($sp)
/*  f11973c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f119740:	3c18800a */ 	lui	$t8,%hi(var800a2380)
/*  f119744:	afb60044 */ 	sw	$s6,0x44($sp)
/*  f119748:	27182380 */ 	addiu	$t8,$t8,%lo(var800a2380)
/*  f11974c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f119750:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f119754:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f119758:	afb70048 */ 	sw	$s7,0x48($sp)
/*  f11975c:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f119760:	01f8b021 */ 	addu	$s6,$t7,$t8
/*  f119764:	3419baba */ 	dli	$t9,0xbaba
/*  f119768:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f11976c:	01c0a825 */ 	or	$s5,$t6,$zero
/*  f119770:	afb4003c */ 	sw	$s4,0x3c($sp)
/*  f119774:	afb30038 */ 	sw	$s3,0x38($sp)
/*  f119778:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f11977c:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f119780:	0000b825 */ 	or	$s7,$zero,$zero
/*  f119784:	afa007a4 */ 	sw	$zero,0x7a4($sp)
/*  f119788:	00008825 */ 	or	$s1,$zero,$zero
/*  f11978c:	aed90260 */ 	sw	$t9,0x260($s6)
/*  f119790:	a2c002be */ 	sb	$zero,0x2be($s6)
/*  f119794:	0fc459f6 */ 	jal	func0f1167d8
/*  f119798:	01202025 */ 	or	$a0,$t1,$zero
/*  f11979c:	50400004 */ 	beqzl	$v0,.L0f1197b0
/*  f1197a0:	8eca02a0 */ 	lw	$t2,0x2a0($s6)
/*  f1197a4:	10000175 */ 	beqz	$zero,.L0f119d7c
/*  f1197a8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f1197ac:	8eca02a0 */ 	lw	$t2,0x2a0($s6)
.L0f1197b0:
/*  f1197b0:	afa003a4 */ 	sw	$zero,0x3a4($sp)
/*  f1197b4:	27b40474 */ 	addiu	$s4,$sp,0x474
/*  f1197b8:	114000a6 */ 	beqz	$t2,.L0f119a54
/*  f1197bc:	27b30484 */ 	addiu	$s3,$sp,0x484
/*  f1197c0:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f1197c4:	00152600 */ 	sll	$a0,$s5,0x18
.L0f1197c8:
/*  f1197c8:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f1197cc:	01602025 */ 	or	$a0,$t3,$zero
/*  f1197d0:	8fa503a4 */ 	lw	$a1,0x3a4($sp)
/*  f1197d4:	0fc45d48 */ 	jal	func0f117520
/*  f1197d8:	02803025 */ 	or	$a2,$s4,$zero
/*  f1197dc:	14400071 */ 	bnez	$v0,.L0f1199a4
/*  f1197e0:	24010001 */ 	addiu	$at,$zero,0x1
/*  f1197e4:	8fa6047c */ 	lw	$a2,0x47c($sp)
/*  f1197e8:	8fae03a4 */ 	lw	$t6,0x3a4($sp)
/*  f1197ec:	00152600 */ 	sll	$a0,$s5,0x18
/*  f1197f0:	000615c2 */ 	srl	$v0,$a2,0x17
/*  f1197f4:	304c0002 */ 	andi	$t4,$v0,0x2
/*  f1197f8:	15800096 */ 	bnez	$t4,.L0f119a54
/*  f1197fc:	304d0004 */ 	andi	$t5,$v0,0x4
/*  f119800:	15a00094 */ 	bnez	$t5,.L0f119a54
/*  f119804:	00001025 */ 	or	$v0,$zero,$zero
/*  f119808:	8ed902a0 */ 	lw	$t9,0x2a0($s6)
/*  f11980c:	30cf0fff */ 	andi	$t7,$a2,0xfff
/*  f119810:	01cfc021 */ 	addu	$t8,$t6,$t7
/*  f119814:	0319082b */ 	sltu	$at,$t8,$t9
/*  f119818:	14200010 */ 	bnez	$at,.L0f11985c
/*  f11981c:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f119820:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f119824:	afaa0020 */ 	sw	$t2,0x20($sp)
/*  f119828:	01202025 */ 	or	$a0,$t1,$zero
/*  f11982c:	01c02825 */ 	or	$a1,$t6,$zero
/*  f119830:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f119834:	00003825 */ 	or	$a3,$zero,$zero
/*  f119838:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f11983c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f119840:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f119844:	0fc46f15 */ 	jal	func0f11bc54
/*  f119848:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f11984c:	50400082 */ 	beqzl	$v0,.L0f119a58
/*  f119850:	8fae07a4 */ 	lw	$t6,0x7a4($sp)
/*  f119854:	10000079 */ 	beqz	$zero,.L0f119a3c
/*  f119858:	24170001 */ 	addiu	$s7,$zero,0x1
.L0f11985c:
/*  f11985c:	1220003c */ 	beqz	$s1,.L0f119950
/*  f119860:	afa0039c */ 	sw	$zero,0x39c($sp)
/*  f119864:	27a703a8 */ 	addiu	$a3,$sp,0x3a8
/*  f119868:	8fa80480 */ 	lw	$t0,0x480($sp)
.L0f11986c:
/*  f11986c:	8ceb0000 */ 	lw	$t3,0x0($a3)
/*  f119870:	00026100 */ 	sll	$t4,$v0,0x4
/*  f119874:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f119878:	124b0033 */ 	beq	$s2,$t3,.L0f119948
/*  f11987c:	026c3021 */ 	addu	$a2,$s3,$t4
/*  f119880:	8cc3000c */ 	lw	$v1,0xc($a2)
/*  f119884:	00086b40 */ 	sll	$t5,$t0,0xd
/*  f119888:	000d7e42 */ 	srl	$t7,$t5,0x19
/*  f11988c:	0003c340 */ 	sll	$t8,$v1,0xd
/*  f119890:	0018ce42 */ 	srl	$t9,$t8,0x19
/*  f119894:	15f9002c */ 	bne	$t7,$t9,.L0f119948
/*  f119898:	00087500 */ 	sll	$t6,$t0,0x14
/*  f11989c:	00035d00 */ 	sll	$t3,$v1,0x14
/*  f1198a0:	000b65c2 */ 	srl	$t4,$t3,0x17
/*  f1198a4:	000e55c2 */ 	srl	$t2,$t6,0x17
/*  f1198a8:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f1198ac:	014c082b */ 	sltu	$at,$t2,$t4
/*  f1198b0:	10200009 */ 	beqz	$at,.L0f1198d8
/*  f1198b4:	afa9039c */ 	sw	$t1,0x39c($sp)
/*  f1198b8:	00152600 */ 	sll	$a0,$s5,0x18
/*  f1198bc:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f1198c0:	01a02025 */ 	or	$a0,$t5,$zero
/*  f1198c4:	27a503a4 */ 	addiu	$a1,$sp,0x3a4
/*  f1198c8:	0fc46538 */ 	jal	func0f1194e0
/*  f1198cc:	02803025 */ 	or	$a2,$s4,$zero
/*  f1198d0:	1000001f */ 	beqz	$zero,.L0f119950
/*  f1198d4:	2c570001 */ 	sltiu	$s7,$v0,0x1
.L0f1198d8:
/*  f1198d8:	00152600 */ 	sll	$a0,$s5,0x18
/*  f1198dc:	00117900 */ 	sll	$t7,$s1,0x4
/*  f1198e0:	026fc821 */ 	addu	$t9,$s3,$t7
/*  f1198e4:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f1198e8:	00114880 */ 	sll	$t1,$s1,0x2
/*  f1198ec:	27ae03a8 */ 	addiu	$t6,$sp,0x3a8
/*  f1198f0:	012e8021 */ 	addu	$s0,$t1,$t6
/*  f1198f4:	03002025 */ 	or	$a0,$t8,$zero
/*  f1198f8:	afb90054 */ 	sw	$t9,0x54($sp)
/*  f1198fc:	00e02825 */ 	or	$a1,$a3,$zero
/*  f119900:	0fc46538 */ 	jal	func0f1194e0
/*  f119904:	afa7005c */ 	sw	$a3,0x5c($sp)
/*  f119908:	8fa7005c */ 	lw	$a3,0x5c($sp)
/*  f11990c:	2c570001 */ 	sltiu	$s7,$v0,0x1
/*  f119910:	02802825 */ 	or	$a1,$s4,$zero
/*  f119914:	acf20000 */ 	sw	$s2,0x0($a3)
/*  f119918:	8fa40054 */ 	lw	$a0,0x54($sp)
/*  f11991c:	0c012978 */ 	jal	func0004a5e0
/*  f119920:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f119924:	8fab03a4 */ 	lw	$t3,0x3a4($sp)
/*  f119928:	8fa6047c */ 	lw	$a2,0x47c($sp)
/*  f11992c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f119930:	ae0b0000 */ 	sw	$t3,0x0($s0)
/*  f119934:	8faa03a4 */ 	lw	$t2,0x3a4($sp)
/*  f119938:	30cc0fff */ 	andi	$t4,$a2,0xfff
/*  f11993c:	014c6821 */ 	addu	$t5,$t2,$t4
/*  f119940:	10000003 */ 	beqz	$zero,.L0f119950
/*  f119944:	afad03a4 */ 	sw	$t5,0x3a4($sp)
.L0f119948:
/*  f119948:	1451ffc8 */ 	bne	$v0,$s1,.L0f11986c
/*  f11994c:	24e70004 */ 	addiu	$a3,$a3,0x4
.L0f119950:
/*  f119950:	8fb8039c */ 	lw	$t8,0x39c($sp)
/*  f119954:	17000039 */ 	bnez	$t8,.L0f119a3c
/*  f119958:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11995c:	16e00037 */ 	bnez	$s7,.L0f119a3c
/*  f119960:	00117900 */ 	sll	$t7,$s1,0x4
/*  f119964:	0011c880 */ 	sll	$t9,$s1,0x2
/*  f119968:	27a903a8 */ 	addiu	$t1,$sp,0x3a8
/*  f11996c:	03298021 */ 	addu	$s0,$t9,$t1
/*  f119970:	026f2021 */ 	addu	$a0,$s3,$t7
/*  f119974:	02802825 */ 	or	$a1,$s4,$zero
/*  f119978:	0c012978 */ 	jal	func0004a5e0
/*  f11997c:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f119980:	8fae03a4 */ 	lw	$t6,0x3a4($sp)
/*  f119984:	8fa6047c */ 	lw	$a2,0x47c($sp)
/*  f119988:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f11998c:	ae0e0000 */ 	sw	$t6,0x0($s0)
/*  f119990:	8fab03a4 */ 	lw	$t3,0x3a4($sp)
/*  f119994:	30ca0fff */ 	andi	$t2,$a2,0xfff
/*  f119998:	016a6021 */ 	addu	$t4,$t3,$t2
/*  f11999c:	10000027 */ 	beqz	$zero,.L0f119a3c
/*  f1199a0:	afac03a4 */ 	sw	$t4,0x3a4($sp)
.L0f1199a4:
/*  f1199a4:	14410003 */ 	bne	$v0,$at,.L0f1199b4
/*  f1199a8:	00152600 */ 	sll	$a0,$s5,0x18
/*  f1199ac:	100000f3 */ 	beqz	$zero,.L0f119d7c
/*  f1199b0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f1199b4:
/*  f1199b4:	24010007 */ 	addiu	$at,$zero,0x7
/*  f1199b8:	14410007 */ 	bne	$v0,$at,.L0f1199d8
/*  f1199bc:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f1199c0:	01a02025 */ 	or	$a0,$t5,$zero
/*  f1199c4:	27a503a4 */ 	addiu	$a1,$sp,0x3a4
/*  f1199c8:	0fc46538 */ 	jal	func0f1194e0
/*  f1199cc:	00003025 */ 	or	$a2,$zero,$zero
/*  f1199d0:	1000001a */ 	beqz	$zero,.L0f119a3c
/*  f1199d4:	2c570001 */ 	sltiu	$s7,$v0,0x1
.L0f1199d8:
/*  f1199d8:	2401000f */ 	addiu	$at,$zero,0xf
/*  f1199dc:	1441000a */ 	bne	$v0,$at,.L0f119a08
/*  f1199e0:	00152600 */ 	sll	$a0,$s5,0x18
/*  f1199e4:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f1199e8:	03002025 */ 	or	$a0,$t8,$zero
/*  f1199ec:	27a503a4 */ 	addiu	$a1,$sp,0x3a4
/*  f1199f0:	0fc46538 */ 	jal	func0f1194e0
/*  f1199f4:	02803025 */ 	or	$a2,$s4,$zero
/*  f1199f8:	14400010 */ 	bnez	$v0,.L0f119a3c
/*  f1199fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119a00:	10000014 */ 	beqz	$zero,.L0f119a54
/*  f119a04:	24170001 */ 	addiu	$s7,$zero,0x1
.L0f119a08:
/*  f119a08:	24100009 */ 	addiu	$s0,$zero,0x9
/*  f119a0c:	14500004 */ 	bne	$v0,$s0,.L0f119a20
/*  f119a10:	24010004 */ 	addiu	$at,$zero,0x4
/*  f119a14:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f119a18:	1000000e */ 	beqz	$zero,.L0f119a54
/*  f119a1c:	afaf07a4 */ 	sw	$t7,0x7a4($sp)
.L0f119a20:
/*  f119a20:	1041000c */ 	beq	$v0,$at,.L0f119a54
/*  f119a24:	24170001 */ 	addiu	$s7,$zero,0x1
/*  f119a28:	2401000b */ 	addiu	$at,$zero,0xb
/*  f119a2c:	5441000a */ 	bnel	$v0,$at,.L0f119a58
/*  f119a30:	8fae07a4 */ 	lw	$t6,0x7a4($sp)
/*  f119a34:	10000008 */ 	beqz	$zero,.L0f119a58
/*  f119a38:	8fae07a4 */ 	lw	$t6,0x7a4($sp)
.L0f119a3c:
/*  f119a3c:	16e00005 */ 	bnez	$s7,.L0f119a54
/*  f119a40:	8fb903a4 */ 	lw	$t9,0x3a4($sp)
/*  f119a44:	8ec902a0 */ 	lw	$t1,0x2a0($s6)
/*  f119a48:	0329082b */ 	sltu	$at,$t9,$t1
/*  f119a4c:	5420ff5e */ 	bnezl	$at,.L0f1197c8
/*  f119a50:	00152600 */ 	sll	$a0,$s5,0x18
.L0f119a54:
/*  f119a54:	8fae07a4 */ 	lw	$t6,0x7a4($sp)
.L0f119a58:
/*  f119a58:	24100009 */ 	addiu	$s0,$zero,0x9
/*  f119a5c:	27b40474 */ 	addiu	$s4,$sp,0x474
/*  f119a60:	15c0003d */ 	bnez	$t6,.L0f119b58
/*  f119a64:	afa003a4 */ 	sw	$zero,0x3a4($sp)
/*  f119a68:	56e0003c */ 	bnezl	$s7,.L0f119b5c
/*  f119a6c:	8fb907a4 */ 	lw	$t9,0x7a4($sp)
/*  f119a70:	8ecb02a0 */ 	lw	$t3,0x2a0($s6)
/*  f119a74:	11600038 */ 	beqz	$t3,.L0f119b58
/*  f119a78:	00152600 */ 	sll	$a0,$s5,0x18
.L0f119a7c:
/*  f119a7c:	00045603 */ 	sra	$t2,$a0,0x18
/*  f119a80:	01402025 */ 	or	$a0,$t2,$zero
/*  f119a84:	8fa503a4 */ 	lw	$a1,0x3a4($sp)
/*  f119a88:	0fc45d48 */ 	jal	func0f117520
/*  f119a8c:	02803025 */ 	or	$a2,$s4,$zero
/*  f119a90:	14400017 */ 	bnez	$v0,.L0f119af0
/*  f119a94:	8fa6047c */ 	lw	$a2,0x47c($sp)
/*  f119a98:	000615c2 */ 	srl	$v0,$a2,0x17
/*  f119a9c:	304c0002 */ 	andi	$t4,$v0,0x2
/*  f119aa0:	11800003 */ 	beqz	$t4,.L0f119ab0
/*  f119aa4:	8fad03a4 */ 	lw	$t5,0x3a4($sp)
/*  f119aa8:	1000000b */ 	beqz	$zero,.L0f119ad8
/*  f119aac:	30430004 */ 	andi	$v1,$v0,0x4
.L0f119ab0:
/*  f119ab0:	11a00003 */ 	beqz	$t5,.L0f119ac0
/*  f119ab4:	8fa80480 */ 	lw	$t0,0x480($sp)
/*  f119ab8:	10000007 */ 	beqz	$zero,.L0f119ad8
/*  f119abc:	30430004 */ 	andi	$v1,$v0,0x4
.L0f119ac0:
/*  f119ac0:	0008c4c2 */ 	srl	$t8,$t0,0x13
/*  f119ac4:	30430004 */ 	andi	$v1,$v0,0x4
/*  f119ac8:	10600003 */ 	beqz	$v1,.L0f119ad8
/*  f119acc:	aed80260 */ 	sw	$t8,0x260($s6)
/*  f119ad0:	100000aa */ 	beqz	$zero,.L0f119d7c
/*  f119ad4:	00001025 */ 	or	$v0,$zero,$zero
.L0f119ad8:
/*  f119ad8:	1460001f */ 	bnez	$v1,.L0f119b58
/*  f119adc:	8faf03a4 */ 	lw	$t7,0x3a4($sp)
/*  f119ae0:	30d90fff */ 	andi	$t9,$a2,0xfff
/*  f119ae4:	01f94821 */ 	addu	$t1,$t7,$t9
/*  f119ae8:	10000011 */ 	beqz	$zero,.L0f119b30
/*  f119aec:	afa903a4 */ 	sw	$t1,0x3a4($sp)
.L0f119af0:
/*  f119af0:	14500008 */ 	bne	$v0,$s0,.L0f119b14
/*  f119af4:	8fa6047c */ 	lw	$a2,0x47c($sp)
/*  f119af8:	8fab03a4 */ 	lw	$t3,0x3a4($sp)
/*  f119afc:	30ca0fff */ 	andi	$t2,$a2,0xfff
/*  f119b00:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f119b04:	016a6021 */ 	addu	$t4,$t3,$t2
/*  f119b08:	afae07a4 */ 	sw	$t6,0x7a4($sp)
/*  f119b0c:	10000008 */ 	beqz	$zero,.L0f119b30
/*  f119b10:	afac03a4 */ 	sw	$t4,0x3a4($sp)
.L0f119b14:
/*  f119b14:	24010001 */ 	addiu	$at,$zero,0x1
/*  f119b18:	14410003 */ 	bne	$v0,$at,.L0f119b28
/*  f119b1c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119b20:	10000096 */ 	beqz	$zero,.L0f119d7c
/*  f119b24:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f119b28:
/*  f119b28:	10000094 */ 	beqz	$zero,.L0f119d7c
/*  f119b2c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f119b30:
/*  f119b30:	8fad07a4 */ 	lw	$t5,0x7a4($sp)
/*  f119b34:	8fb803a4 */ 	lw	$t8,0x3a4($sp)
/*  f119b38:	55a00008 */ 	bnezl	$t5,.L0f119b5c
/*  f119b3c:	8fb907a4 */ 	lw	$t9,0x7a4($sp)
/*  f119b40:	56e00006 */ 	bnezl	$s7,.L0f119b5c
/*  f119b44:	8fb907a4 */ 	lw	$t9,0x7a4($sp)
/*  f119b48:	8ecf02a0 */ 	lw	$t7,0x2a0($s6)
/*  f119b4c:	030f082b */ 	sltu	$at,$t8,$t7
/*  f119b50:	5420ffca */ 	bnezl	$at,.L0f119a7c
/*  f119b54:	00152600 */ 	sll	$a0,$s5,0x18
.L0f119b58:
/*  f119b58:	8fb907a4 */ 	lw	$t9,0x7a4($sp)
.L0f119b5c:
/*  f119b5c:	17200072 */ 	bnez	$t9,.L0f119d28
/*  f119b60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119b64:	16e00070 */ 	bnez	$s7,.L0f119d28
/*  f119b68:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119b6c:	8ec902a0 */ 	lw	$t1,0x2a0($s6)
/*  f119b70:	00008025 */ 	or	$s0,$zero,$zero
/*  f119b74:	afa003a4 */ 	sw	$zero,0x3a4($sp)
/*  f119b78:	1120002e */ 	beqz	$t1,.L0f119c34
/*  f119b7c:	27b2007c */ 	addiu	$s2,$sp,0x7c
/*  f119b80:	24110001 */ 	addiu	$s1,$zero,0x1
.L0f119b84:
/*  f119b84:	00152600 */ 	sll	$a0,$s5,0x18
/*  f119b88:	00047603 */ 	sra	$t6,$a0,0x18
/*  f119b8c:	01c02025 */ 	or	$a0,$t6,$zero
/*  f119b90:	8fa503a4 */ 	lw	$a1,0x3a4($sp)
/*  f119b94:	0fc45d48 */ 	jal	func0f117520
/*  f119b98:	02803025 */ 	or	$a2,$s4,$zero
/*  f119b9c:	14400025 */ 	bnez	$v0,.L0f119c34
/*  f119ba0:	8fa6047c */ 	lw	$a2,0x47c($sp)
/*  f119ba4:	000615c2 */ 	srl	$v0,$a2,0x17
/*  f119ba8:	304b0002 */ 	andi	$t3,$v0,0x2
/*  f119bac:	1560001a */ 	bnez	$t3,.L0f119c18
/*  f119bb0:	304a0004 */ 	andi	$t2,$v0,0x4
/*  f119bb4:	1540001f */ 	bnez	$t2,.L0f119c34
/*  f119bb8:	00002825 */ 	or	$a1,$zero,$zero
/*  f119bbc:	1a00000e */ 	blez	$s0,.L0f119bf8
/*  f119bc0:	00001825 */ 	or	$v1,$zero,$zero
/*  f119bc4:	8fa80480 */ 	lw	$t0,0x480($sp)
/*  f119bc8:	27a2007c */ 	addiu	$v0,$sp,0x7c
/*  f119bcc:	000824c2 */ 	srl	$a0,$t0,0x13
.L0f119bd0:
/*  f119bd0:	8c4c0000 */ 	lw	$t4,0x0($v0)
/*  f119bd4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f119bd8:	148c0005 */ 	bne	$a0,$t4,.L0f119bf0
/*  f119bdc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119be0:	8c4d0004 */ 	lw	$t5,0x4($v0)
/*  f119be4:	02202825 */ 	or	$a1,$s1,$zero
/*  f119be8:	25b80001 */ 	addiu	$t8,$t5,0x1
/*  f119bec:	ac580004 */ 	sw	$t8,0x4($v0)
.L0f119bf0:
/*  f119bf0:	1470fff7 */ 	bne	$v1,$s0,.L0f119bd0
/*  f119bf4:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f119bf8:
/*  f119bf8:	14a00007 */ 	bnez	$a1,.L0f119c18
/*  f119bfc:	8fa80480 */ 	lw	$t0,0x480($sp)
/*  f119c00:	001078c0 */ 	sll	$t7,$s0,0x3
/*  f119c04:	024f1021 */ 	addu	$v0,$s2,$t7
/*  f119c08:	0008ccc2 */ 	srl	$t9,$t0,0x13
/*  f119c0c:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f119c10:	ac510004 */ 	sw	$s1,0x4($v0)
/*  f119c14:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f119c18:
/*  f119c18:	8fa903a4 */ 	lw	$t1,0x3a4($sp)
/*  f119c1c:	8ecc02a0 */ 	lw	$t4,0x2a0($s6)
/*  f119c20:	30ce0fff */ 	andi	$t6,$a2,0xfff
/*  f119c24:	012e5821 */ 	addu	$t3,$t1,$t6
/*  f119c28:	016c082b */ 	sltu	$at,$t3,$t4
/*  f119c2c:	1420ffd5 */ 	bnez	$at,.L0f119b84
/*  f119c30:	afab03a4 */ 	sw	$t3,0x3a4($sp)
.L0f119c34:
/*  f119c34:	2a010002 */ 	slti	$at,$s0,0x2
/*  f119c38:	14200039 */ 	bnez	$at,.L0f119d20
/*  f119c3c:	27b2007c */ 	addiu	$s2,$sp,0x7c
/*  f119c40:	2406ffff */ 	addiu	$a2,$zero,-1
/*  f119c44:	2405ffff */ 	addiu	$a1,$zero,-1
/*  f119c48:	1a00000b */ 	blez	$s0,.L0f119c78
/*  f119c4c:	00001825 */ 	or	$v1,$zero,$zero
/*  f119c50:	27a2007c */ 	addiu	$v0,$sp,0x7c
.L0f119c54:
/*  f119c54:	8c440004 */ 	lw	$a0,0x4($v0)
/*  f119c58:	00a4082a */ 	slt	$at,$a1,$a0
/*  f119c5c:	50200004 */ 	beqzl	$at,.L0f119c70
/*  f119c60:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f119c64:	00603025 */ 	or	$a2,$v1,$zero
/*  f119c68:	00802825 */ 	or	$a1,$a0,$zero
/*  f119c6c:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f119c70:
/*  f119c70:	1470fff8 */ 	bne	$v1,$s0,.L0f119c54
/*  f119c74:	24420008 */ 	addiu	$v0,$v0,0x8
.L0f119c78:
/*  f119c78:	2401ffff */ 	addiu	$at,$zero,-1
/*  f119c7c:	10c1002a */ 	beq	$a2,$at,.L0f119d28
/*  f119c80:	000668c0 */ 	sll	$t5,$a2,0x3
/*  f119c84:	8ed902a0 */ 	lw	$t9,0x2a0($s6)
/*  f119c88:	024dc021 */ 	addu	$t8,$s2,$t5
/*  f119c8c:	8f0f0000 */ 	lw	$t7,0x0($t8)
/*  f119c90:	afa003a4 */ 	sw	$zero,0x3a4($sp)
/*  f119c94:	13200024 */ 	beqz	$t9,.L0f119d28
/*  f119c98:	aecf0260 */ 	sw	$t7,0x260($s6)
.L0f119c9c:
/*  f119c9c:	00152600 */ 	sll	$a0,$s5,0x18
/*  f119ca0:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f119ca4:	01202025 */ 	or	$a0,$t1,$zero
/*  f119ca8:	8fa503a4 */ 	lw	$a1,0x3a4($sp)
/*  f119cac:	0fc45d48 */ 	jal	func0f117520
/*  f119cb0:	02803025 */ 	or	$a2,$s4,$zero
/*  f119cb4:	1440001c */ 	bnez	$v0,.L0f119d28
/*  f119cb8:	8fa6047c */ 	lw	$a2,0x47c($sp)
/*  f119cbc:	000615c2 */ 	srl	$v0,$a2,0x17
/*  f119cc0:	304e0002 */ 	andi	$t6,$v0,0x2
/*  f119cc4:	15c0000d */ 	bnez	$t6,.L0f119cfc
/*  f119cc8:	304b0004 */ 	andi	$t3,$v0,0x4
/*  f119ccc:	15600016 */ 	bnez	$t3,.L0f119d28
/*  f119cd0:	8fa80480 */ 	lw	$t0,0x480($sp)
/*  f119cd4:	8ecc0260 */ 	lw	$t4,0x260($s6)
/*  f119cd8:	000854c2 */ 	srl	$t2,$t0,0x13
/*  f119cdc:	00152600 */ 	sll	$a0,$s5,0x18
/*  f119ce0:	114c0006 */ 	beq	$t2,$t4,.L0f119cfc
/*  f119ce4:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f119ce8:	01a02025 */ 	or	$a0,$t5,$zero
/*  f119cec:	8fa503a4 */ 	lw	$a1,0x3a4($sp)
/*  f119cf0:	0fc4651e */ 	jal	func0f119478
/*  f119cf4:	02803025 */ 	or	$a2,$s4,$zero
/*  f119cf8:	8fa6047c */ 	lw	$a2,0x47c($sp)
.L0f119cfc:
/*  f119cfc:	8fb803a4 */ 	lw	$t8,0x3a4($sp)
/*  f119d00:	8ece02a0 */ 	lw	$t6,0x2a0($s6)
/*  f119d04:	30cf0fff */ 	andi	$t7,$a2,0xfff
/*  f119d08:	030fc821 */ 	addu	$t9,$t8,$t7
/*  f119d0c:	032e082b */ 	sltu	$at,$t9,$t6
/*  f119d10:	1420ffe2 */ 	bnez	$at,.L0f119c9c
/*  f119d14:	afb903a4 */ 	sw	$t9,0x3a4($sp)
/*  f119d18:	10000003 */ 	beqz	$zero,.L0f119d28
/*  f119d1c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f119d20:
/*  f119d20:	8fab007c */ 	lw	$t3,0x7c($sp)
/*  f119d24:	aecb0260 */ 	sw	$t3,0x260($s6)
.L0f119d28:
/*  f119d28:	12e00003 */ 	beqz	$s7,.L0f119d38
/*  f119d2c:	8faa07a4 */ 	lw	$t2,0x7a4($sp)
/*  f119d30:	10000012 */ 	beqz	$zero,.L0f119d7c
/*  f119d34:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f119d38:
/*  f119d38:	11400003 */ 	beqz	$t2,.L0f119d48
/*  f119d3c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f119d40:	1000000e */ 	beqz	$zero,.L0f119d7c
/*  f119d44:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f119d48:
/*  f119d48:	52a1000c */ 	beql	$s5,$at,.L0f119d7c
/*  f119d4c:	00001025 */ 	or	$v0,$zero,$zero
/*  f119d50:	8ecc0260 */ 	lw	$t4,0x260($s6)
/*  f119d54:	00152600 */ 	sll	$a0,$s5,0x18
/*  f119d58:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f119d5c:	55800007 */ 	bnezl	$t4,.L0f119d7c
/*  f119d60:	00001025 */ 	or	$v0,$zero,$zero
/*  f119d64:	0fc459a3 */ 	jal	func0f11668c
/*  f119d68:	01a02025 */ 	or	$a0,$t5,$zero
/*  f119d6c:	aec20260 */ 	sw	$v0,0x260($s6)
/*  f119d70:	10000002 */ 	beqz	$zero,.L0f119d7c
/*  f119d74:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f119d78:	00001025 */ 	or	$v0,$zero,$zero
.L0f119d7c:
/*  f119d7c:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f119d80:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f119d84:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f119d88:	8fb20034 */ 	lw	$s2,0x34($sp)
/*  f119d8c:	8fb30038 */ 	lw	$s3,0x38($sp)
/*  f119d90:	8fb4003c */ 	lw	$s4,0x3c($sp)
/*  f119d94:	8fb50040 */ 	lw	$s5,0x40($sp)
/*  f119d98:	8fb60044 */ 	lw	$s6,0x44($sp)
/*  f119d9c:	8fb70048 */ 	lw	$s7,0x48($sp)
/*  f119da0:	03e00008 */ 	jr	$ra
/*  f119da4:	27bd07b0 */ 	addiu	$sp,$sp,0x7b0
);

GLOBAL_ASM(
glabel func0f119da8
/*  f119da8:	27bdef90 */ 	addiu	$sp,$sp,-4208
/*  f119dac:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f119db0:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f119db4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f119db8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f119dbc:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f119dc0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f119dc4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f119dc8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f119dcc:	27a6005c */ 	addiu	$a2,$sp,0x5c
/*  f119dd0:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f119dd4:	0fc459ec */ 	jal	func0f1167b0
/*  f119dd8:	24050080 */ 	addiu	$a1,$zero,0x80
/*  f119ddc:	8fae005c */ 	lw	$t6,0x5c($sp)
/*  f119de0:	27b2005c */ 	addiu	$s2,$sp,0x5c
/*  f119de4:	00009825 */ 	or	$s3,$zero,$zero
/*  f119de8:	11c0001e */ 	beqz	$t6,.L0f119e64
/*  f119dec:	27b60048 */ 	addiu	$s6,$sp,0x48
/*  f119df0:	3c15800a */ 	lui	$s5,%hi(var80099e78)
/*  f119df4:	26b59e78 */ 	addiu	$s5,$s5,%lo(var80099e78)
/*  f119df8:	27b41060 */ 	addiu	$s4,$sp,0x1060
/*  f119dfc:	27b10050 */ 	addiu	$s1,$sp,0x50
/*  f119e00:	27b00048 */ 	addiu	$s0,$sp,0x48
.L0f119e04:
/*  f119e04:	0c004b70 */ 	jal	random
/*  f119e08:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119e0c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f119e10:	1611fffc */ 	bne	$s0,$s1,.L0f119e04
/*  f119e14:	a202ffff */ 	sb	$v0,-0x1($s0)
/*  f119e18:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f119e1c:	8e450000 */ 	lw	$a1,0x0($s2)
/*  f119e20:	0fc464da */ 	jal	func0f119368
/*  f119e24:	02803025 */ 	or	$a2,$s4,$zero
/*  f119e28:	00538021 */ 	addu	$s0,$v0,$s3
/*  f119e2c:	0c00543a */ 	jal	func000150e8
/*  f119e30:	26100030 */ 	addiu	$s0,$s0,0x30
/*  f119e34:	02a02025 */ 	or	$a0,$s5,$zero
/*  f119e38:	320500ff */ 	andi	$a1,$s0,0xff
/*  f119e3c:	02c03025 */ 	or	$a2,$s6,$zero
/*  f119e40:	0c001910 */ 	jal	func00006440
/*  f119e44:	24070008 */ 	addiu	$a3,$zero,0x8
/*  f119e48:	0c005451 */ 	jal	func00015144
/*  f119e4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119e50:	8e580004 */ 	lw	$t8,0x4($s2)
/*  f119e54:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f119e58:	26730008 */ 	addiu	$s3,$s3,0x8
/*  f119e5c:	5700ffe9 */ 	bnezl	$t8,.L0f119e04
/*  f119e60:	27b00048 */ 	addiu	$s0,$sp,0x48
.L0f119e64:
/*  f119e64:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f119e68:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f119e6c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f119e70:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f119e74:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f119e78:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f119e7c:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f119e80:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f119e84:	03e00008 */ 	jr	$ra
/*  f119e88:	27bd1070 */ 	addiu	$sp,$sp,0x1070
);

GLOBAL_ASM(
glabel func0f119e8c
/*  f119e8c:	27bdef58 */ 	addiu	$sp,$sp,-4264
/*  f119e90:	3c188007 */ 	lui	$t8,%hi(var80075d18)
/*  f119e94:	afbf0034 */ 	sw	$ra,0x34($sp)
/*  f119e98:	afb70030 */ 	sw	$s7,0x30($sp)
/*  f119e9c:	afb6002c */ 	sw	$s6,0x2c($sp)
/*  f119ea0:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f119ea4:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f119ea8:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f119eac:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f119eb0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f119eb4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f119eb8:	afa410a8 */ 	sw	$a0,0x10a8($sp)
/*  f119ebc:	27185d18 */ 	addiu	$t8,$t8,%lo(var80075d18)
/*  f119ec0:	8f010000 */ 	lw	$at,0x0($t8)
/*  f119ec4:	27af0074 */ 	addiu	$t7,$sp,0x74
/*  f119ec8:	8f090004 */ 	lw	$t1,0x4($t8)
/*  f119ecc:	ade10000 */ 	sw	$at,0x0($t7)
/*  f119ed0:	8f010008 */ 	lw	$at,0x8($t8)
/*  f119ed4:	ade90004 */ 	sw	$t1,0x4($t7)
/*  f119ed8:	8f09000c */ 	lw	$t1,0xc($t8)
/*  f119edc:	ade10008 */ 	sw	$at,0x8($t7)
/*  f119ee0:	8f010010 */ 	lw	$at,0x10($t8)
/*  f119ee4:	3c0a8007 */ 	lui	$t2,%hi(var80075d2c)
/*  f119ee8:	254a5d2c */ 	addiu	$t2,$t2,%lo(var80075d2c)
/*  f119eec:	ade9000c */ 	sw	$t1,0xc($t7)
/*  f119ef0:	ade10010 */ 	sw	$at,0x10($t7)
/*  f119ef4:	8d410000 */ 	lw	$at,0x0($t2)
/*  f119ef8:	27b60060 */ 	addiu	$s6,$sp,0x60
/*  f119efc:	3c088007 */ 	lui	$t0,%hi(var80075d40)
/*  f119f00:	aec10000 */ 	sw	$at,0x0($s6)
/*  f119f04:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*  f119f08:	00049e00 */ 	sll	$s3,$a0,0x18
/*  f119f0c:	25085d40 */ 	addiu	$t0,$t0,%lo(var80075d40)
/*  f119f10:	aecd0004 */ 	sw	$t5,0x4($s6)
/*  f119f14:	8d410008 */ 	lw	$at,0x8($t2)
/*  f119f18:	00137603 */ 	sra	$t6,$s3,0x18
/*  f119f1c:	01c09825 */ 	or	$s3,$t6,$zero
/*  f119f20:	aec10008 */ 	sw	$at,0x8($s6)
/*  f119f24:	8d4d000c */ 	lw	$t5,0xc($t2)
/*  f119f28:	27ae004c */ 	addiu	$t6,$sp,0x4c
/*  f119f2c:	00132600 */ 	sll	$a0,$s3,0x18
/*  f119f30:	aecd000c */ 	sw	$t5,0xc($s6)
/*  f119f34:	8d410010 */ 	lw	$at,0x10($t2)
/*  f119f38:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f119f3c:	01202025 */ 	or	$a0,$t1,$zero
/*  f119f40:	aec10010 */ 	sw	$at,0x10($s6)
/*  f119f44:	8d010000 */ 	lw	$at,0x0($t0)
/*  f119f48:	8d180004 */ 	lw	$t8,0x4($t0)
/*  f119f4c:	27a60094 */ 	addiu	$a2,$sp,0x94
/*  f119f50:	adc10000 */ 	sw	$at,0x0($t6)
/*  f119f54:	8d010008 */ 	lw	$at,0x8($t0)
/*  f119f58:	add80004 */ 	sw	$t8,0x4($t6)
/*  f119f5c:	8d18000c */ 	lw	$t8,0xc($t0)
/*  f119f60:	adc10008 */ 	sw	$at,0x8($t6)
/*  f119f64:	8d010010 */ 	lw	$at,0x10($t0)
/*  f119f68:	24050100 */ 	addiu	$a1,$zero,0x100
/*  f119f6c:	add8000c */ 	sw	$t8,0xc($t6)
/*  f119f70:	0fc459ec */ 	jal	func0f1167b0
/*  f119f74:	adc10010 */ 	sw	$at,0x10($t6)
/*  f119f78:	10400003 */ 	beqz	$v0,.L0f119f88
/*  f119f7c:	8fac0094 */ 	lw	$t4,0x94($sp)
/*  f119f80:	1000004e */ 	beqz	$zero,.L0f11a0bc
/*  f119f84:	00001025 */ 	or	$v0,$zero,$zero
.L0f119f88:
/*  f119f88:	11800022 */ 	beqz	$t4,.L0f11a014
/*  f119f8c:	27b20094 */ 	addiu	$s2,$sp,0x94
/*  f119f90:	8e450000 */ 	lw	$a1,0x0($s2)
/*  f119f94:	2415ffff */ 	addiu	$s5,$zero,-1
/*  f119f98:	27b41098 */ 	addiu	$s4,$sp,0x1098
/*  f119f9c:	27b10088 */ 	addiu	$s1,$sp,0x88
/*  f119fa0:	00132600 */ 	sll	$a0,$s3,0x18
.L0f119fa4:
/*  f119fa4:	00045603 */ 	sra	$t2,$a0,0x18
/*  f119fa8:	01402025 */ 	or	$a0,$t2,$zero
/*  f119fac:	0fc464da */ 	jal	func0f119368
/*  f119fb0:	02803025 */ 	or	$a2,$s4,$zero
/*  f119fb4:	14550003 */ 	bne	$v0,$s5,.L0f119fc4
/*  f119fb8:	8fa410a0 */ 	lw	$a0,0x10a0($sp)
/*  f119fbc:	1000003f */ 	beqz	$zero,.L0f11a0bc
/*  f119fc0:	00001025 */ 	or	$v0,$zero,$zero
.L0f119fc4:
/*  f119fc4:	00046dc2 */ 	srl	$t5,$a0,0x17
/*  f119fc8:	01a02025 */ 	or	$a0,$t5,$zero
/*  f119fcc:	00001825 */ 	or	$v1,$zero,$zero
/*  f119fd0:	27a20074 */ 	addiu	$v0,$sp,0x74
.L0f119fd4:
/*  f119fd4:	8c4f0000 */ 	lw	$t7,0x0($v0)
/*  f119fd8:	24420004 */ 	addiu	$v0,$v0,0x4
/*  f119fdc:	148f0007 */ 	bne	$a0,$t7,.L0f119ffc
/*  f119fe0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f119fe4:	02c31021 */ 	addu	$v0,$s6,$v1
/*  f119fe8:	8c440000 */ 	lw	$a0,0x0($v0)
/*  f119fec:	10800005 */ 	beqz	$a0,.L0f11a004
/*  f119ff0:	2499ffff */ 	addiu	$t9,$a0,-1
/*  f119ff4:	10000003 */ 	beqz	$zero,.L0f11a004
/*  f119ff8:	ac590000 */ 	sw	$t9,0x0($v0)
.L0f119ffc:
/*  f119ffc:	1451fff5 */ 	bne	$v0,$s1,.L0f119fd4
/*  f11a000:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f11a004:
/*  f11a004:	8e450004 */ 	lw	$a1,0x4($s2)
/*  f11a008:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f11a00c:	54a0ffe5 */ 	bnezl	$a1,.L0f119fa4
/*  f11a010:	00132600 */ 	sll	$a0,$s3,0x18
.L0f11a014:
/*  f11a014:	0000a025 */ 	or	$s4,$zero,$zero
/*  f11a018:	27b20060 */ 	addiu	$s2,$sp,0x60
/*  f11a01c:	27b70074 */ 	addiu	$s7,$sp,0x74
/*  f11a020:	27b60064 */ 	addiu	$s6,$sp,0x64
/*  f11a024:	24150004 */ 	addiu	$s5,$zero,0x4
.L0f11a028:
/*  f11a028:	8e420000 */ 	lw	$v0,0x0($s2)
/*  f11a02c:	50400020 */ 	beqzl	$v0,.L0f11a0b0
/*  f11a030:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f11a034:	16750003 */ 	bne	$s3,$s5,.L0f11a044
/*  f11a038:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11a03c:	5256001c */ 	beql	$s2,$s6,.L0f11a0b0
/*  f11a040:	26520004 */ 	addiu	$s2,$s2,0x4
.L0f11a044:
/*  f11a044:	10400019 */ 	beqz	$v0,.L0f11a0ac
/*  f11a048:	00008025 */ 	or	$s0,$zero,$zero
/*  f11a04c:	27ae0074 */ 	addiu	$t6,$sp,0x74
/*  f11a050:	028e8821 */ 	addu	$s1,$s4,$t6
/*  f11a054:	00132600 */ 	sll	$a0,$s3,0x18
.L0f11a058:
/*  f11a058:	00044603 */ 	sra	$t0,$a0,0x18
/*  f11a05c:	01002025 */ 	or	$a0,$t0,$zero
/*  f11a060:	8e250000 */ 	lw	$a1,0x0($s1)
/*  f11a064:	0fc4619d */ 	jal	func0f118674
/*  f11a068:	00003025 */ 	or	$a2,$zero,$zero
/*  f11a06c:	1040000a */ 	beqz	$v0,.L0f11a098
/*  f11a070:	00402025 */ 	or	$a0,$v0,$zero
/*  f11a074:	2401000e */ 	addiu	$at,$zero,0xe
/*  f11a078:	14410003 */ 	bne	$v0,$at,.L0f11a088
/*  f11a07c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11a080:	1000000e */ 	beqz	$zero,.L0f11a0bc
/*  f11a084:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11a088:
/*  f11a088:	0fc464d0 */ 	jal	func0f119340
/*  f11a08c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11a090:	1000000a */ 	beqz	$zero,.L0f11a0bc
/*  f11a094:	00001025 */ 	or	$v0,$zero,$zero
.L0f11a098:
/*  f11a098:	8e580000 */ 	lw	$t8,0x0($s2)
/*  f11a09c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11a0a0:	0218082b */ 	sltu	$at,$s0,$t8
/*  f11a0a4:	5420ffec */ 	bnezl	$at,.L0f11a058
/*  f11a0a8:	00132600 */ 	sll	$a0,$s3,0x18
.L0f11a0ac:
/*  f11a0ac:	26520004 */ 	addiu	$s2,$s2,0x4
.L0f11a0b0:
/*  f11a0b0:	1657ffdd */ 	bne	$s2,$s7,.L0f11a028
/*  f11a0b4:	26940004 */ 	addiu	$s4,$s4,0x4
/*  f11a0b8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11a0bc:
/*  f11a0bc:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*  f11a0c0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f11a0c4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f11a0c8:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f11a0cc:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f11a0d0:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f11a0d4:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f11a0d8:	8fb6002c */ 	lw	$s6,0x2c($sp)
/*  f11a0dc:	8fb70030 */ 	lw	$s7,0x30($sp)
/*  f11a0e0:	03e00008 */ 	jr	$ra
/*  f11a0e4:	27bd10a8 */ 	addiu	$sp,$sp,0x10a8
);

GLOBAL_ASM(
glabel func0f11a0e8
/*  f11a0e8:	27bdefa0 */ 	addiu	$sp,$sp,-4192
/*  f11a0ec:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f11a0f0:	0004a600 */ 	sll	$s4,$a0,0x18
/*  f11a0f4:	00147603 */ 	sra	$t6,$s4,0x18
/*  f11a0f8:	afa41060 */ 	sw	$a0,0x1060($sp)
/*  f11a0fc:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f11a100:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f11a104:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f11a108:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f11a10c:	01c0a025 */ 	or	$s4,$t6,$zero
/*  f11a110:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f11a114:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f11a118:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11a11c:	00008825 */ 	or	$s1,$zero,$zero
/*  f11a120:	01e02025 */ 	or	$a0,$t7,$zero
/*  f11a124:	27a6004c */ 	addiu	$a2,$sp,0x4c
/*  f11a128:	0fc459ec */ 	jal	func0f1167b0
/*  f11a12c:	24050100 */ 	addiu	$a1,$zero,0x100
/*  f11a130:	1440001c */ 	bnez	$v0,.L0f11a1a4
/*  f11a134:	8fb8004c */ 	lw	$t8,0x4c($sp)
/*  f11a138:	1300001c */ 	beqz	$t8,.L0f11a1ac
/*  f11a13c:	27b0004c */ 	addiu	$s0,$sp,0x4c
/*  f11a140:	8e050000 */ 	lw	$a1,0x0($s0)
/*  f11a144:	2413ffff */ 	addiu	$s3,$zero,-1
/*  f11a148:	27b21050 */ 	addiu	$s2,$sp,0x1050
/*  f11a14c:	00142600 */ 	sll	$a0,$s4,0x18
.L0f11a150:
/*  f11a150:	00044603 */ 	sra	$t0,$a0,0x18
/*  f11a154:	01002025 */ 	or	$a0,$t0,$zero
/*  f11a158:	0fc464da */ 	jal	func0f119368
/*  f11a15c:	02403025 */ 	or	$a2,$s2,$zero
/*  f11a160:	54530004 */ 	bnel	$v0,$s3,.L0f11a174
/*  f11a164:	8fa2105c */ 	lw	$v0,0x105c($sp)
/*  f11a168:	10000011 */ 	beqz	$zero,.L0f11a1b0
/*  f11a16c:	2402ffff */ 	addiu	$v0,$zero,-1
/*  f11a170:	8fa2105c */ 	lw	$v0,0x105c($sp)
.L0f11a174:
/*  f11a174:	00024b40 */ 	sll	$t1,$v0,0xd
/*  f11a178:	00095642 */ 	srl	$t2,$t1,0x19
/*  f11a17c:	022a082b */ 	sltu	$at,$s1,$t2
/*  f11a180:	50200003 */ 	beqzl	$at,.L0f11a190
/*  f11a184:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f11a188:	01408825 */ 	or	$s1,$t2,$zero
/*  f11a18c:	8e050004 */ 	lw	$a1,0x4($s0)
.L0f11a190:
/*  f11a190:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f11a194:	54a0ffee */ 	bnezl	$a1,.L0f11a150
/*  f11a198:	00142600 */ 	sll	$a0,$s4,0x18
/*  f11a19c:	10000004 */ 	beqz	$zero,.L0f11a1b0
/*  f11a1a0:	02201025 */ 	or	$v0,$s1,$zero
.L0f11a1a4:
/*  f11a1a4:	10000002 */ 	beqz	$zero,.L0f11a1b0
/*  f11a1a8:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f11a1ac:
/*  f11a1ac:	02201025 */ 	or	$v0,$s1,$zero
.L0f11a1b0:
/*  f11a1b0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f11a1b4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f11a1b8:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f11a1bc:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f11a1c0:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f11a1c4:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f11a1c8:	03e00008 */ 	jr	$ra
/*  f11a1cc:	27bd1060 */ 	addiu	$sp,$sp,0x1060
);

GLOBAL_ASM(
glabel func0f11a1d0
/*  f11a1d0:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f11a1d4:	afb20034 */ 	sw	$s2,0x34($sp)
/*  f11a1d8:	00049600 */ 	sll	$s2,$a0,0x18
/*  f11a1dc:	00127603 */ 	sra	$t6,$s2,0x18
/*  f11a1e0:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f11a1e4:	afb50040 */ 	sw	$s5,0x40($sp)
/*  f11a1e8:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f11a1ec:	27b50060 */ 	addiu	$s5,$sp,0x60
/*  f11a1f0:	afbf0044 */ 	sw	$ra,0x44($sp)
/*  f11a1f4:	afb10030 */ 	sw	$s1,0x30($sp)
/*  f11a1f8:	afb0002c */ 	sw	$s0,0x2c($sp)
/*  f11a1fc:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f11a200:	01c09025 */ 	or	$s2,$t6,$zero
/*  f11a204:	afb4003c */ 	sw	$s4,0x3c($sp)
/*  f11a208:	afb30038 */ 	sw	$s3,0x38($sp)
/*  f11a20c:	00008025 */ 	or	$s0,$zero,$zero
/*  f11a210:	3411ffff */ 	dli	$s1,0xffff
/*  f11a214:	01e02025 */ 	or	$a0,$t7,$zero
/*  f11a218:	02a03025 */ 	or	$a2,$s5,$zero
/*  f11a21c:	0fc45d48 */ 	jal	func0f117520
/*  f11a220:	00002825 */ 	or	$a1,$zero,$zero
/*  f11a224:	14400026 */ 	bnez	$v0,.L0f11a2c0
/*  f11a228:	3414ffff */ 	dli	$s4,0xffff
/*  f11a22c:	24130002 */ 	addiu	$s3,$zero,0x2
/*  f11a230:	8fa30068 */ 	lw	$v1,0x68($sp)
.L0f11a234:
/*  f11a234:	30620fff */ 	andi	$v0,$v1,0xfff
/*  f11a238:	0003c5c2 */ 	srl	$t8,$v1,0x17
/*  f11a23c:	17130017 */ 	bne	$t8,$s3,.L0f11a29c
/*  f11a240:	02022821 */ 	addu	$a1,$s0,$v0
/*  f11a244:	12340013 */ 	beq	$s1,$s4,.L0f11a294
/*  f11a248:	00122600 */ 	sll	$a0,$s2,0x18
/*  f11a24c:	02114023 */ 	subu	$t0,$s0,$s1
/*  f11a250:	01024821 */ 	addu	$t1,$t0,$v0
/*  f11a254:	252afff0 */ 	addiu	$t2,$t1,-16
/*  f11a258:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f11a25c:	02202825 */ 	or	$a1,$s1,$zero
/*  f11a260:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f11a264:	afab0020 */ 	sw	$t3,0x20($sp)
/*  f11a268:	3411ffff */ 	dli	$s1,0xffff
/*  f11a26c:	03202025 */ 	or	$a0,$t9,$zero
/*  f11a270:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f11a274:	02603025 */ 	or	$a2,$s3,$zero
/*  f11a278:	00003825 */ 	or	$a3,$zero,$zero
/*  f11a27c:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f11a280:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f11a284:	0fc46f15 */ 	jal	func0f11bc54
/*  f11a288:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f11a28c:	10000004 */ 	beqz	$zero,.L0f11a2a0
/*  f11a290:	00002825 */ 	or	$a1,$zero,$zero
.L0f11a294:
/*  f11a294:	10000002 */ 	beqz	$zero,.L0f11a2a0
/*  f11a298:	02008825 */ 	or	$s1,$s0,$zero
.L0f11a29c:
/*  f11a29c:	02808825 */ 	or	$s1,$s4,$zero
.L0f11a2a0:
/*  f11a2a0:	00122600 */ 	sll	$a0,$s2,0x18
/*  f11a2a4:	00046603 */ 	sra	$t4,$a0,0x18
/*  f11a2a8:	01802025 */ 	or	$a0,$t4,$zero
/*  f11a2ac:	00a08025 */ 	or	$s0,$a1,$zero
/*  f11a2b0:	0fc45d48 */ 	jal	func0f117520
/*  f11a2b4:	02a03025 */ 	or	$a2,$s5,$zero
/*  f11a2b8:	5040ffde */ 	beqzl	$v0,.L0f11a234
/*  f11a2bc:	8fa30068 */ 	lw	$v1,0x68($sp)
.L0f11a2c0:
/*  f11a2c0:	8fbf0044 */ 	lw	$ra,0x44($sp)
/*  f11a2c4:	8fb0002c */ 	lw	$s0,0x2c($sp)
/*  f11a2c8:	8fb10030 */ 	lw	$s1,0x30($sp)
/*  f11a2cc:	8fb20034 */ 	lw	$s2,0x34($sp)
/*  f11a2d0:	8fb30038 */ 	lw	$s3,0x38($sp)
/*  f11a2d4:	8fb4003c */ 	lw	$s4,0x3c($sp)
/*  f11a2d8:	8fb50040 */ 	lw	$s5,0x40($sp)
/*  f11a2dc:	03e00008 */ 	jr	$ra
/*  f11a2e0:	27bd0070 */ 	addiu	$sp,$sp,0x70
);

GLOBAL_ASM(
glabel func0f11a2e4
/*  f11a2e4:	03e00008 */ 	jr	$ra
/*  f11a2e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11a2ec:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11a2f0:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f11a2f4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11a2f8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11a2fc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11a300:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11a304:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11a308:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11a30c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11a310:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11a314:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11a318:	3c02800a */ 	lui	$v0,0x800a
/*  f11a31c:	00581021 */ 	addu	$v0,$v0,$t8
/*  f11a320:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11a324:	03e00008 */ 	jr	$ra
/*  f11a328:	90422394 */ 	lbu	$v0,0x2394($v0)
);

GLOBAL_ASM(
glabel func0f11a32c
/*  f11a32c:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11a330:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f11a334:	000fc880 */ 	sll	$t9,$t7,0x2
/*  f11a338:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f11a33c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11a340:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f11a344:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11a348:	032fc821 */ 	addu	$t9,$t9,$t7
/*  f11a34c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11a350:	032fc823 */ 	subu	$t9,$t9,$t7
/*  f11a354:	3c08800a */ 	lui	$t0,%hi(var800a2380)
/*  f11a358:	25082380 */ 	addiu	$t0,$t0,%lo(var800a2380)
/*  f11a35c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11a360:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f11a364:	03281821 */ 	addu	$v1,$t9,$t0
/*  f11a368:	90690014 */ 	lbu	$t1,0x14($v1)
/*  f11a36c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11a370:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f11a374:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f11a378:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f11a37c:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f11a380:	15200012 */ 	bnez	$t1,.L0f11a3cc
/*  f11a384:	30b800ff */ 	andi	$t8,$a1,0xff
/*  f11a388:	330b0001 */ 	andi	$t3,$t8,0x1
/*  f11a38c:	1160000f */ 	beqz	$t3,.L0f11a3cc
/*  f11a390:	a0780014 */ 	sb	$t8,0x14($v1)
/*  f11a394:	8c6c02c0 */ 	lw	$t4,0x2c0($v1)
/*  f11a398:	24040708 */ 	addiu	$a0,$zero,0x708
/*  f11a39c:	5580000c */ 	bnezl	$t4,.L0f11a3d0
/*  f11a3a0:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11a3a4:	a06002be */ 	sb	$zero,0x2be($v1)
/*  f11a3a8:	0fc5db70 */ 	jal	func0f176dc0
/*  f11a3ac:	afa30018 */ 	sw	$v1,0x18($sp)
/*  f11a3b0:	00402025 */ 	or	$a0,$v0,$zero
/*  f11a3b4:	0c0048f2 */ 	jal	func000123c8
/*  f11a3b8:	24050006 */ 	addiu	$a1,$zero,0x6
/*  f11a3bc:	8fa30018 */ 	lw	$v1,0x18($sp)
/*  f11a3c0:	24040708 */ 	addiu	$a0,$zero,0x708
/*  f11a3c4:	0fc5db70 */ 	jal	func0f176dc0
/*  f11a3c8:	ac6202c0 */ 	sw	$v0,0x2c0($v1)
.L0f11a3cc:
/*  f11a3cc:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f11a3d0:
/*  f11a3d0:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f11a3d4:	03e00008 */ 	jr	$ra
/*  f11a3d8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11a3dc:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11a3e0:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f11a3e4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11a3e8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11a3ec:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11a3f0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11a3f4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11a3f8:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11a3fc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11a400:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11a404:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11a408:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f11a40c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11a410:	03191021 */ 	addu	$v0,$t8,$t9
/*  f11a414:	90430014 */ 	lbu	$v1,0x14($v0)
/*  f11a418:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11a41c:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f11a420:	10600002 */ 	beqz	$v1,.L0f11a42c
/*  f11a424:	afa60008 */ 	sw	$a2,0x8($sp)
/*  f11a428:	a0400014 */ 	sb	$zero,0x14($v0)
.L0f11a42c:
/*  f11a42c:	03e00008 */ 	jr	$ra
/*  f11a430:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11a434
/*  f11a434:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11a438:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f11a43c:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11a440:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11a444:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11a448:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11a44c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11a450:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11a454:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11a458:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11a45c:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11a460:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f11a464:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11a468:	03191021 */ 	addu	$v0,$t8,$t9
/*  f11a46c:	904902b8 */ 	lbu	$t1,0x2b8($v0)
/*  f11a470:	2408ffff */ 	addiu	$t0,$zero,-1
/*  f11a474:	ac48029c */ 	sw	$t0,0x29c($v0)
/*  f11a478:	312bff7f */ 	andi	$t3,$t1,0xff7f
/*  f11a47c:	316d00f7 */ 	andi	$t5,$t3,0xf7
/*  f11a480:	a04b02b8 */ 	sb	$t3,0x2b8($v0)
/*  f11a484:	31af00df */ 	andi	$t7,$t5,0xdf
/*  f11a488:	a04d02b8 */ 	sb	$t5,0x2b8($v0)
/*  f11a48c:	31e800bf */ 	andi	$t0,$t7,0xbf
/*  f11a490:	a04f02b8 */ 	sb	$t7,0x2b8($v0)
/*  f11a494:	310a00fb */ 	andi	$t2,$t0,0xfb
/*  f11a498:	3c01bf80 */ 	lui	$at,0xbf80
/*  f11a49c:	44812000 */ 	mtc1	$at,$f4
/*  f11a4a0:	a04802b8 */ 	sb	$t0,0x2b8($v0)
/*  f11a4a4:	24030003 */ 	addiu	$v1,$zero,0x3
/*  f11a4a8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11a4ac:	24190080 */ 	addiu	$t9,$zero,0x80
/*  f11a4b0:	a04a02b8 */ 	sb	$t2,0x2b8($v0)
/*  f11a4b4:	314b00fd */ 	andi	$t3,$t2,0xfd
/*  f11a4b8:	240c0008 */ 	addiu	$t4,$zero,0x8
/*  f11a4bc:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11a4c0:	ac430274 */ 	sw	$v1,0x274($v0)
/*  f11a4c4:	a0400014 */ 	sb	$zero,0x14($v0)
/*  f11a4c8:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f11a4cc:	ac450008 */ 	sw	$a1,0x8($v0)
/*  f11a4d0:	ac450004 */ 	sw	$a1,0x4($v0)
/*  f11a4d4:	ac43000c */ 	sw	$v1,0xc($v0)
/*  f11a4d8:	ac400010 */ 	sw	$zero,0x10($v0)
/*  f11a4dc:	a05902bd */ 	sb	$t9,0x2bd($v0)
/*  f11a4e0:	ac400264 */ 	sw	$zero,0x264($v0)
/*  f11a4e4:	a04b02b8 */ 	sb	$t3,0x2b8($v0)
/*  f11a4e8:	ac4002c0 */ 	sw	$zero,0x2c0($v0)
/*  f11a4ec:	ac4002c4 */ 	sw	$zero,0x2c4($v0)
/*  f11a4f0:	ac4c025c */ 	sw	$t4,0x25c($v0)
/*  f11a4f4:	ac400260 */ 	sw	$zero,0x260($v0)
/*  f11a4f8:	ac4002c8 */ 	sw	$zero,0x2c8($v0)
/*  f11a4fc:	03e00008 */ 	jr	$ra
/*  f11a500:	e44402b4 */ 	swc1	$f4,0x2b4($v0)
);

GLOBAL_ASM(
glabel func0f11a504
/*  f11a504:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f11a508:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11a50c:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f11a510:	afa5002c */ 	sw	$a1,0x2c($sp)
/*  f11a514:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11a518:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f11a51c:	afa60030 */ 	sw	$a2,0x30($sp)
/*  f11a520:	afa70034 */ 	sw	$a3,0x34($sp)
/*  f11a524:	0fc4597e */ 	jal	func0f1165f8
/*  f11a528:	8fa5003c */ 	lw	$a1,0x3c($sp)
/*  f11a52c:	0c00543a */ 	jal	func000150e8
/*  f11a530:	afa2003c */ 	sw	$v0,0x3c($sp)
/*  f11a534:	8fb8003c */ 	lw	$t8,0x3c($sp)
/*  f11a538:	8fb90040 */ 	lw	$t9,0x40($sp)
/*  f11a53c:	8fa4002c */ 	lw	$a0,0x2c($sp)
/*  f11a540:	8fa50030 */ 	lw	$a1,0x30($sp)
/*  f11a544:	93a60037 */ 	lbu	$a2,0x37($sp)
/*  f11a548:	8fa70038 */ 	lw	$a3,0x38($sp)
/*  f11a54c:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f11a550:	0fc45ed3 */ 	jal	func0f117b4c
/*  f11a554:	afb90014 */ 	sw	$t9,0x14($sp)
/*  f11a558:	0c005451 */ 	jal	func00015144
/*  f11a55c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f11a560:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11a564:	8fa20024 */ 	lw	$v0,0x24($sp)
/*  f11a568:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f11a56c:	03e00008 */ 	jr	$ra
/*  f11a570:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11a574
/*  f11a574:	27bdff58 */ 	addiu	$sp,$sp,-168
/*  f11a578:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f11a57c:	0004ae00 */ 	sll	$s5,$a0,0x18
/*  f11a580:	00157603 */ 	sra	$t6,$s5,0x18
/*  f11a584:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f11a588:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11a58c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11a590:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11a594:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11a598:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f11a59c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11a5a0:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11a5a4:	3c18800a */ 	lui	$t8,%hi(var800a2380)
/*  f11a5a8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f11a5ac:	27182380 */ 	addiu	$t8,$t8,%lo(var800a2380)
/*  f11a5b0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11a5b4:	01f8a021 */ 	addu	$s4,$t7,$t8
/*  f11a5b8:	8e9902b8 */ 	lw	$t9,0x2b8($s4)
/*  f11a5bc:	01c0a825 */ 	or	$s5,$t6,$zero
/*  f11a5c0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f11a5c4:	00194840 */ 	sll	$t1,$t9,0x1
/*  f11a5c8:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f11a5cc:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f11a5d0:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f11a5d4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f11a5d8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f11a5dc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f11a5e0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11a5e4:	05200003 */ 	bltz	$t1,.L0f11a5f4
/*  f11a5e8:	afa400a8 */ 	sw	$a0,0xa8($sp)
/*  f11a5ec:	1000006f */ 	beqz	$zero,.L0f11a7ac
/*  f11a5f0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11a5f4:
/*  f11a5f4:	24170004 */ 	addiu	$s7,$zero,0x4
/*  f11a5f8:	16b70005 */ 	bne	$s5,$s7,.L0f11a610
/*  f11a5fc:	26850290 */ 	addiu	$a1,$s4,0x290
/*  f11a600:	3c1e800a */ 	lui	$s8,%hi(var800a3180)
/*  f11a604:	27de3180 */ 	addiu	$s8,$s8,%lo(var800a3180)
/*  f11a608:	10000009 */ 	beqz	$zero,.L0f11a630
/*  f11a60c:	00002025 */ 	or	$a0,$zero,$zero
.L0f11a610:
/*  f11a610:	00155080 */ 	sll	$t2,$s5,0x2
/*  f11a614:	01555023 */ 	subu	$t2,$t2,$s5
/*  f11a618:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f11a61c:	01555021 */ 	addu	$t2,$t2,$s5
/*  f11a620:	3c1e800a */ 	lui	$s8,%hi(var800a3180)
/*  f11a624:	27de3180 */ 	addiu	$s8,$s8,%lo(var800a3180)
/*  f11a628:	000a50c0 */ 	sll	$t2,$t2,0x3
/*  f11a62c:	03ca2021 */ 	addu	$a0,$s8,$t2
.L0f11a630:
/*  f11a630:	0fc45f03 */ 	jal	func0f117c0c
/*  f11a634:	26860294 */ 	addiu	$a2,$s4,0x294
/*  f11a638:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f11a63c:	00055e03 */ 	sra	$t3,$a1,0x18
/*  f11a640:	01602825 */ 	or	$a1,$t3,$zero
/*  f11a644:	00402025 */ 	or	$a0,$v0,$zero
/*  f11a648:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f11a64c:	0fc470e7 */ 	jal	func0f11c39c
/*  f11a650:	24070d9e */ 	addiu	$a3,$zero,0xd9e
/*  f11a654:	14400006 */ 	bnez	$v0,.L0f11a670
/*  f11a658:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11a65c:	928c02b8 */ 	lbu	$t4,0x2b8($s4)
/*  f11a660:	00001025 */ 	or	$v0,$zero,$zero
/*  f11a664:	318dffbf */ 	andi	$t5,$t4,0xffbf
/*  f11a668:	10000050 */ 	beqz	$zero,.L0f11a7ac
/*  f11a66c:	a28d02b8 */ 	sb	$t5,0x2b8($s4)
.L0f11a670:
/*  f11a670:	16b70003 */ 	bne	$s5,$s7,.L0f11a680
/*  f11a674:	00157080 */ 	sll	$t6,$s5,0x2
/*  f11a678:	10000006 */ 	beqz	$zero,.L0f11a694
/*  f11a67c:	00002025 */ 	or	$a0,$zero,$zero
.L0f11a680:
/*  f11a680:	01d57023 */ 	subu	$t6,$t6,$s5
/*  f11a684:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11a688:	01d57021 */ 	addu	$t6,$t6,$s5
/*  f11a68c:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f11a690:	03ce2021 */ 	addu	$a0,$s8,$t6
.L0f11a694:
/*  f11a694:	0fc45f20 */ 	jal	func0f117c80
/*  f11a698:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f11a69c:	8faf0060 */ 	lw	$t7,0x60($sp)
/*  f11a6a0:	00152e00 */ 	sll	$a1,$s5,0x18
/*  f11a6a4:	00054e03 */ 	sra	$t1,$a1,0x18
/*  f11a6a8:	25f800ff */ 	addiu	$t8,$t7,0xff
/*  f11a6ac:	3319ffff */ 	andi	$t9,$t8,0xffff
/*  f11a6b0:	00194203 */ 	sra	$t0,$t9,0x8
/*  f11a6b4:	a688025a */ 	sh	$t0,0x25a($s4)
/*  f11a6b8:	01202825 */ 	or	$a1,$t1,$zero
/*  f11a6bc:	00402025 */ 	or	$a0,$v0,$zero
/*  f11a6c0:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f11a6c4:	0fc470e7 */ 	jal	func0f11c39c
/*  f11a6c8:	24070da7 */ 	addiu	$a3,$zero,0xda7
/*  f11a6cc:	14400006 */ 	bnez	$v0,.L0f11a6e8
/*  f11a6d0:	00008025 */ 	or	$s0,$zero,$zero
/*  f11a6d4:	928a02b8 */ 	lbu	$t2,0x2b8($s4)
/*  f11a6d8:	00001025 */ 	or	$v0,$zero,$zero
/*  f11a6dc:	314bffbf */ 	andi	$t3,$t2,0xffbf
/*  f11a6e0:	10000032 */ 	beqz	$zero,.L0f11a7ac
/*  f11a6e4:	a28b02b8 */ 	sb	$t3,0x2b8($s4)
.L0f11a6e8:
/*  f11a6e8:	27b10064 */ 	addiu	$s1,$sp,0x64
/*  f11a6ec:	02809025 */ 	or	$s2,$s4,$zero
/*  f11a6f0:	26930018 */ 	addiu	$s3,$s4,0x18
/*  f11a6f4:	24160001 */ 	addiu	$s6,$zero,0x1
.L0f11a6f8:
/*  f11a6f8:	16b70003 */ 	bne	$s5,$s7,.L0f11a708
/*  f11a6fc:	02002825 */ 	or	$a1,$s0,$zero
/*  f11a700:	10000007 */ 	beqz	$zero,.L0f11a720
/*  f11a704:	00002025 */ 	or	$a0,$zero,$zero
.L0f11a708:
/*  f11a708:	00156080 */ 	sll	$t4,$s5,0x2
/*  f11a70c:	01956023 */ 	subu	$t4,$t4,$s5
/*  f11a710:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f11a714:	01956021 */ 	addu	$t4,$t4,$s5
/*  f11a718:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f11a71c:	03cc2021 */ 	addu	$a0,$s8,$t4
.L0f11a720:
/*  f11a720:	0fc45f39 */ 	jal	func0f117ce4
/*  f11a724:	02603025 */ 	or	$a2,$s3,$zero
/*  f11a728:	10400003 */ 	beqz	$v0,.L0f11a738
/*  f11a72c:	ae220000 */ 	sw	$v0,0x0($s1)
/*  f11a730:	10000002 */ 	beqz	$zero,.L0f11a73c
/*  f11a734:	ae400218 */ 	sw	$zero,0x218($s2)
.L0f11a738:
/*  f11a738:	ae560218 */ 	sw	$s6,0x218($s2)
.L0f11a73c:
/*  f11a73c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11a740:	2a010010 */ 	slti	$at,$s0,0x10
/*  f11a744:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f11a748:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f11a74c:	1420ffea */ 	bnez	$at,.L0f11a6f8
/*  f11a750:	26730020 */ 	addiu	$s3,$s3,0x20
/*  f11a754:	00008025 */ 	or	$s0,$zero,$zero
/*  f11a758:	a6800258 */ 	sh	$zero,0x258($s4)
/*  f11a75c:	27b10064 */ 	addiu	$s1,$sp,0x64
/*  f11a760:	24020010 */ 	addiu	$v0,$zero,0x10
.L0f11a764:
/*  f11a764:	8e2d0000 */ 	lw	$t5,0x0($s1)
/*  f11a768:	00107940 */ 	sll	$t7,$s0,0x5
/*  f11a76c:	028fc021 */ 	addu	$t8,$s4,$t7
/*  f11a770:	55a00008 */ 	bnezl	$t5,.L0f11a794
/*  f11a774:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11a778:	8f190018 */ 	lw	$t9,0x18($t8)
/*  f11a77c:	968e0258 */ 	lhu	$t6,0x258($s4)
/*  f11a780:	272800ff */ 	addiu	$t0,$t9,0xff
/*  f11a784:	00084a02 */ 	srl	$t1,$t0,0x8
/*  f11a788:	01c95021 */ 	addu	$t2,$t6,$t1
/*  f11a78c:	a68a0258 */ 	sh	$t2,0x258($s4)
/*  f11a790:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f11a794:
/*  f11a794:	1602fff3 */ 	bne	$s0,$v0,.L0f11a764
/*  f11a798:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f11a79c:	928b02b8 */ 	lbu	$t3,0x2b8($s4)
/*  f11a7a0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11a7a4:	316cffbf */ 	andi	$t4,$t3,0xffbf
/*  f11a7a8:	a28c02b8 */ 	sb	$t4,0x2b8($s4)
.L0f11a7ac:
/*  f11a7ac:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f11a7b0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f11a7b4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f11a7b8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f11a7bc:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f11a7c0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f11a7c4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f11a7c8:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f11a7cc:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f11a7d0:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f11a7d4:	03e00008 */ 	jr	$ra
/*  f11a7d8:	27bd00a8 */ 	addiu	$sp,$sp,0xa8
);

GLOBAL_ASM(
glabel func0f11a7dc
/*  f11a7dc:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f11a7e0:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f11a7e4:	00048e00 */ 	sll	$s1,$a0,0x18
/*  f11a7e8:	00117603 */ 	sra	$t6,$s1,0x18
/*  f11a7ec:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11a7f0:	01c08825 */ 	or	$s1,$t6,$zero
/*  f11a7f4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f11a7f8:	0c00543a */ 	jal	func000150e8
/*  f11a7fc:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f11a800:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11a804:	16210003 */ 	bne	$s1,$at,.L0f11a814
/*  f11a808:	0011c880 */ 	sll	$t9,$s1,0x2
/*  f11a80c:	10000009 */ 	beqz	$zero,.L0f11a834
/*  f11a810:	00002025 */ 	or	$a0,$zero,$zero
.L0f11a814:
/*  f11a814:	00117880 */ 	sll	$t7,$s1,0x2
/*  f11a818:	01f17823 */ 	subu	$t7,$t7,$s1
/*  f11a81c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11a820:	01f17821 */ 	addu	$t7,$t7,$s1
/*  f11a824:	3c18800a */ 	lui	$t8,%hi(var800a3180)
/*  f11a828:	27183180 */ 	addiu	$t8,$t8,%lo(var800a3180)
/*  f11a82c:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f11a830:	01f82021 */ 	addu	$a0,$t7,$t8
.L0f11a834:
/*  f11a834:	0331c823 */ 	subu	$t9,$t9,$s1
/*  f11a838:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11a83c:	0331c823 */ 	subu	$t9,$t9,$s1
/*  f11a840:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11a844:	0331c821 */ 	addu	$t9,$t9,$s1
/*  f11a848:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11a84c:	0331c823 */ 	subu	$t9,$t9,$s1
/*  f11a850:	3c08800a */ 	lui	$t0,%hi(var800a2380)
/*  f11a854:	25082380 */ 	addiu	$t0,$t0,%lo(var800a2380)
/*  f11a858:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11a85c:	03288021 */ 	addu	$s0,$t9,$t0
/*  f11a860:	8e05029c */ 	lw	$a1,0x29c($s0)
/*  f11a864:	0fc45f39 */ 	jal	func0f117ce4
/*  f11a868:	27a6002c */ 	addiu	$a2,$sp,0x2c
/*  f11a86c:	0c005451 */ 	jal	func00015144
/*  f11a870:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f11a874:	00112e00 */ 	sll	$a1,$s1,0x18
/*  f11a878:	00054e03 */ 	sra	$t1,$a1,0x18
/*  f11a87c:	01202825 */ 	or	$a1,$t1,$zero
/*  f11a880:	8fa40028 */ 	lw	$a0,0x28($sp)
/*  f11a884:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f11a888:	0fc470e7 */ 	jal	func0f11c39c
/*  f11a88c:	24070e0f */ 	addiu	$a3,$zero,0xe0f
/*  f11a890:	10400013 */ 	beqz	$v0,.L0f11a8e0
/*  f11a894:	8faa002c */ 	lw	$t2,0x2c($sp)
/*  f11a898:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11a89c:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f11a8a0:	ae0a02a0 */ 	sw	$t2,0x2a0($s0)
/*  f11a8a4:	0fc45974 */ 	jal	func0f1165d0
/*  f11a8a8:	01602025 */ 	or	$a0,$t3,$zero
/*  f11a8ac:	8e0302a0 */ 	lw	$v1,0x2a0($s0)
/*  f11a8b0:	24011c00 */ 	addiu	$at,$zero,0x1c00
/*  f11a8b4:	0062001b */ 	divu	$zero,$v1,$v0
/*  f11a8b8:	00006012 */ 	mflo	$t4
/*  f11a8bc:	00036a02 */ 	srl	$t5,$v1,0x8
/*  f11a8c0:	ae0c02a4 */ 	sw	$t4,0x2a4($s0)
/*  f11a8c4:	0061001b */ 	divu	$zero,$v1,$at
/*  f11a8c8:	00007012 */ 	mflo	$t6
/*  f11a8cc:	ae0d02a8 */ 	sw	$t5,0x2a8($s0)
/*  f11a8d0:	14400002 */ 	bnez	$v0,.L0f11a8dc
/*  f11a8d4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11a8d8:	0007000d */ 	break	0x7
.L0f11a8dc:
/*  f11a8dc:	a20e02bc */ 	sb	$t6,0x2bc($s0)
.L0f11a8e0:
/*  f11a8e0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11a8e4:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f11a8e8:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f11a8ec:	03e00008 */ 	jr	$ra
/*  f11a8f0:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel func0f11a8f4
/*  f11a8f4:	27bdefa0 */ 	addiu	$sp,$sp,-4192
/*  f11a8f8:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f11a8fc:	00048e00 */ 	sll	$s1,$a0,0x18
/*  f11a900:	00117603 */ 	sra	$t6,$s1,0x18
/*  f11a904:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f11a908:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11a90c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11a910:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11a914:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11a918:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f11a91c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11a920:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11a924:	3c18800a */ 	lui	$t8,%hi(var800a2380)
/*  f11a928:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f11a92c:	27182380 */ 	addiu	$t8,$t8,%lo(var800a2380)
/*  f11a930:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11a934:	01f88021 */ 	addu	$s0,$t7,$t8
/*  f11a938:	920902b8 */ 	lbu	$t1,0x2b8($s0)
/*  f11a93c:	afa41060 */ 	sw	$a0,0x1060($sp)
/*  f11a940:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f11a944:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f11a948:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f11a94c:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f11a950:	352a0040 */ 	ori	$t2,$t1,0x40
/*  f11a954:	01c08825 */ 	or	$s1,$t6,$zero
/*  f11a958:	afa01054 */ 	sw	$zero,0x1054($sp)
/*  f11a95c:	afa01050 */ 	sw	$zero,0x1050($sp)
/*  f11a960:	ae190000 */ 	sw	$t9,0x0($s0)
/*  f11a964:	a20a02b8 */ 	sb	$t2,0x2b8($s0)
/*  f11a968:	0fc4695d */ 	jal	func0f11a574
/*  f11a96c:	01602025 */ 	or	$a0,$t3,$zero
/*  f11a970:	8e0c0010 */ 	lw	$t4,0x10($s0)
/*  f11a974:	24010001 */ 	addiu	$at,$zero,0x1
/*  f11a978:	15810003 */ 	bne	$t4,$at,.L0f11a988
/*  f11a97c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11a980:	100000b9 */ 	beqz	$zero,.L0f11ac68
/*  f11a984:	00001025 */ 	or	$v0,$zero,$zero
.L0f11a988:
/*  f11a988:	0c00543a */ 	jal	func000150e8
/*  f11a98c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11a990:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11a994:	16210003 */ 	bne	$s1,$at,.L0f11a9a4
/*  f11a998:	24053459 */ 	addiu	$a1,$zero,0x3459
/*  f11a99c:	10000009 */ 	beqz	$zero,.L0f11a9c4
/*  f11a9a0:	00002025 */ 	or	$a0,$zero,$zero
.L0f11a9a4:
/*  f11a9a4:	00116880 */ 	sll	$t5,$s1,0x2
/*  f11a9a8:	01b16823 */ 	subu	$t5,$t5,$s1
/*  f11a9ac:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f11a9b0:	01b16821 */ 	addu	$t5,$t5,$s1
/*  f11a9b4:	3c0e800a */ 	lui	$t6,%hi(var800a3180)
/*  f11a9b8:	25ce3180 */ 	addiu	$t6,$t6,%lo(var800a3180)
/*  f11a9bc:	000d68c0 */ 	sll	$t5,$t5,0x3
/*  f11a9c0:	01ae2021 */ 	addu	$a0,$t5,$t6
.L0f11a9c4:
/*  f11a9c4:	3c0f8007 */ 	lui	$t7,%hi(var80075d08)
/*  f11a9c8:	25ef5d08 */ 	addiu	$t7,$t7,%lo(var80075d08)
/*  f11a9cc:	3c064e50 */ 	lui	$a2,0x4e50
/*  f11a9d0:	3c078007 */ 	lui	$a3,%hi(var80075cf8)
/*  f11a9d4:	2602029c */ 	addiu	$v0,$s0,0x29c
/*  f11a9d8:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f11a9dc:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f11a9e0:	24e75cf8 */ 	addiu	$a3,$a3,%lo(var80075cf8)
/*  f11a9e4:	34c64445 */ 	ori	$a2,$a2,0x4445
/*  f11a9e8:	0fc45f96 */ 	jal	func0f117e58
/*  f11a9ec:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f11a9f0:	0c005451 */ 	jal	func00015144
/*  f11a9f4:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f11a9f8:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f11a9fc:	00112e00 */ 	sll	$a1,$s1,0x18
/*  f11aa00:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f11aa04:	1080003e */ 	beqz	$a0,.L0f11ab00
/*  f11aa08:	03002825 */ 	or	$a1,$t8,$zero
/*  f11aa0c:	00003025 */ 	or	$a2,$zero,$zero
/*  f11aa10:	0fc470e7 */ 	jal	func0f11c39c
/*  f11aa14:	24070e46 */ 	addiu	$a3,$zero,0xe46
/*  f11aa18:	9619025a */ 	lhu	$t9,0x25a($s0)
/*  f11aa1c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f11aa20:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f11aa24:	2b210081 */ 	slti	$at,$t9,0x81
/*  f11aa28:	54200004 */ 	bnezl	$at,.L0f11aa3c
/*  f11aa2c:	a20902bc */ 	sb	$t1,0x2bc($s0)
/*  f11aa30:	10000002 */ 	beqz	$zero,.L0f11aa3c
/*  f11aa34:	a20802bc */ 	sb	$t0,0x2bc($s0)
/*  f11aa38:	a20902bc */ 	sb	$t1,0x2bc($s0)
.L0f11aa3c:
/*  f11aa3c:	920a02bc */ 	lbu	$t2,0x2bc($s0)
/*  f11aa40:	000a58c0 */ 	sll	$t3,$t2,0x3
/*  f11aa44:	016a5823 */ 	subu	$t3,$t3,$t2
/*  f11aa48:	000b5a80 */ 	sll	$t3,$t3,0xa
/*  f11aa4c:	0c00543a */ 	jal	func000150e8
/*  f11aa50:	afab0044 */ 	sw	$t3,0x44($sp)
/*  f11aa54:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11aa58:	16210003 */ 	bne	$s1,$at,.L0f11aa68
/*  f11aa5c:	24053459 */ 	addiu	$a1,$zero,0x3459
/*  f11aa60:	10000009 */ 	beqz	$zero,.L0f11aa88
/*  f11aa64:	00002025 */ 	or	$a0,$zero,$zero
.L0f11aa68:
/*  f11aa68:	00116080 */ 	sll	$t4,$s1,0x2
/*  f11aa6c:	01916023 */ 	subu	$t4,$t4,$s1
/*  f11aa70:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f11aa74:	01916021 */ 	addu	$t4,$t4,$s1
/*  f11aa78:	3c0d800a */ 	lui	$t5,%hi(var800a3180)
/*  f11aa7c:	25ad3180 */ 	addiu	$t5,$t5,%lo(var800a3180)
/*  f11aa80:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f11aa84:	018d2021 */ 	addu	$a0,$t4,$t5
.L0f11aa88:
/*  f11aa88:	8faf0044 */ 	lw	$t7,0x44($sp)
/*  f11aa8c:	8fb80030 */ 	lw	$t8,0x30($sp)
/*  f11aa90:	3c0e8007 */ 	lui	$t6,%hi(var80075d08)
/*  f11aa94:	25ce5d08 */ 	addiu	$t6,$t6,%lo(var80075d08)
/*  f11aa98:	3c064e50 */ 	lui	$a2,0x4e50
/*  f11aa9c:	3c078007 */ 	lui	$a3,%hi(var80075cf8)
/*  f11aaa0:	24e75cf8 */ 	addiu	$a3,$a3,%lo(var80075cf8)
/*  f11aaa4:	34c64445 */ 	ori	$a2,$a2,0x4445
/*  f11aaa8:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f11aaac:	afaf0014 */ 	sw	$t7,0x14($sp)
/*  f11aab0:	0fc45f64 */ 	jal	func0f117d90
/*  f11aab4:	afb80018 */ 	sw	$t8,0x18($sp)
/*  f11aab8:	0c005451 */ 	jal	func00015144
/*  f11aabc:	afa20048 */ 	sw	$v0,0x48($sp)
/*  f11aac0:	920802b8 */ 	lbu	$t0,0x2b8($s0)
/*  f11aac4:	00112e00 */ 	sll	$a1,$s1,0x18
/*  f11aac8:	8fa40048 */ 	lw	$a0,0x48($sp)
/*  f11aacc:	00055603 */ 	sra	$t2,$a1,0x18
/*  f11aad0:	35090040 */ 	ori	$t1,$t0,0x40
/*  f11aad4:	a20902b8 */ 	sb	$t1,0x2b8($s0)
/*  f11aad8:	01402825 */ 	or	$a1,$t2,$zero
/*  f11aadc:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f11aae0:	0fc470e7 */ 	jal	func0f11c39c
/*  f11aae4:	24070e54 */ 	addiu	$a3,$zero,0xe54
/*  f11aae8:	10400003 */ 	beqz	$v0,.L0f11aaf8
/*  f11aaec:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f11aaf0:	10000003 */ 	beqz	$zero,.L0f11ab00
/*  f11aaf4:	afab1054 */ 	sw	$t3,0x1054($sp)
.L0f11aaf8:
/*  f11aaf8:	1000005b */ 	beqz	$zero,.L0f11ac68
/*  f11aafc:	00001025 */ 	or	$v0,$zero,$zero
.L0f11ab00:
/*  f11ab00:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11ab04:	00046603 */ 	sra	$t4,$a0,0x18
/*  f11ab08:	0fc4695d */ 	jal	func0f11a574
/*  f11ab0c:	01802025 */ 	or	$a0,$t4,$zero
/*  f11ab10:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11ab14:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f11ab18:	0fc469f7 */ 	jal	func0f11a7dc
/*  f11ab1c:	01a02025 */ 	or	$a0,$t5,$zero
/*  f11ab20:	920e02b8 */ 	lbu	$t6,0x2b8($s0)
/*  f11ab24:	2418000b */ 	addiu	$t8,$zero,0xb
/*  f11ab28:	a20002be */ 	sb	$zero,0x2be($s0)
/*  f11ab2c:	31cffffd */ 	andi	$t7,$t6,0xfffd
/*  f11ab30:	a20f02b8 */ 	sb	$t7,0x2b8($s0)
/*  f11ab34:	ae180010 */ 	sw	$t8,0x10($s0)
/*  f11ab38:	8fb91054 */ 	lw	$t9,0x1054($sp)
/*  f11ab3c:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11ab40:	00044603 */ 	sra	$t0,$a0,0x18
/*  f11ab44:	5320000a */ 	beqzl	$t9,.L0f11ab70
/*  f11ab48:	8faa1050 */ 	lw	$t2,0x1050($sp)
/*  f11ab4c:	0fc46d52 */ 	jal	func0f11b548
/*  f11ab50:	01002025 */ 	or	$a0,$t0,$zero
/*  f11ab54:	2401ffff */ 	addiu	$at,$zero,-1
/*  f11ab58:	10410003 */ 	beq	$v0,$at,.L0f11ab68
/*  f11ab5c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f11ab60:	10000002 */ 	beqz	$zero,.L0f11ab6c
/*  f11ab64:	ae020260 */ 	sw	$v0,0x260($s0)
.L0f11ab68:
/*  f11ab68:	afa91050 */ 	sw	$t1,0x1050($sp)
.L0f11ab6c:
/*  f11ab6c:	8faa1050 */ 	lw	$t2,0x1050($sp)
.L0f11ab70:
/*  f11ab70:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11ab74:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f11ab78:	55400016 */ 	bnezl	$t2,.L0f11abd4
/*  f11ab7c:	8fb91050 */ 	lw	$t9,0x1050($sp)
/*  f11ab80:	0fc465c3 */ 	jal	func0f11970c
/*  f11ab84:	01602025 */ 	or	$a0,$t3,$zero
/*  f11ab88:	2401ffff */ 	addiu	$at,$zero,-1
/*  f11ab8c:	14410010 */ 	bne	$v0,$at,.L0f11abd0
/*  f11ab90:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11ab94:	00046603 */ 	sra	$t4,$a0,0x18
/*  f11ab98:	0fc46d52 */ 	jal	func0f11b548
/*  f11ab9c:	01802025 */ 	or	$a0,$t4,$zero
/*  f11aba0:	2401ffff */ 	addiu	$at,$zero,-1
/*  f11aba4:	10410003 */ 	beq	$v0,$at,.L0f11abb4
/*  f11aba8:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f11abac:	10000002 */ 	beqz	$zero,.L0f11abb8
/*  f11abb0:	ae020260 */ 	sw	$v0,0x260($s0)
.L0f11abb4:
/*  f11abb4:	afad1050 */ 	sw	$t5,0x1050($sp)
.L0f11abb8:
/*  f11abb8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11abbc:	52210005 */ 	beql	$s1,$at,.L0f11abd4
/*  f11abc0:	8fb91050 */ 	lw	$t9,0x1050($sp)
/*  f11abc4:	920f02b8 */ 	lbu	$t7,0x2b8($s0)
/*  f11abc8:	35f80002 */ 	ori	$t8,$t7,0x2
/*  f11abcc:	a21802b8 */ 	sb	$t8,0x2b8($s0)
.L0f11abd0:
/*  f11abd0:	8fb91050 */ 	lw	$t9,0x1050($sp)
.L0f11abd4:
/*  f11abd4:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11abd8:	00044603 */ 	sra	$t0,$a0,0x18
/*  f11abdc:	5720001e */ 	bnezl	$t9,.L0f11ac58
/*  f11abe0:	240d0016 */ 	addiu	$t5,$zero,0x16
/*  f11abe4:	0fc4683a */ 	jal	func0f11a0e8
/*  f11abe8:	01002025 */ 	or	$a0,$t0,$zero
/*  f11abec:	2401ffff */ 	addiu	$at,$zero,-1
/*  f11abf0:	10410018 */ 	beq	$v0,$at,.L0f11ac54
/*  f11abf4:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11abf8:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f11abfc:	ae02025c */ 	sw	$v0,0x25c($s0)
/*  f11ac00:	01202025 */ 	or	$a0,$t1,$zero
/*  f11ac04:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f11ac08:	0fc459ec */ 	jal	func0f1167b0
/*  f11ac0c:	27a60050 */ 	addiu	$a2,$sp,0x50
/*  f11ac10:	14400010 */ 	bnez	$v0,.L0f11ac54
/*  f11ac14:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11ac18:	00045603 */ 	sra	$t2,$a0,0x18
/*  f11ac1c:	0fc467a3 */ 	jal	func0f119e8c
/*  f11ac20:	01402025 */ 	or	$a0,$t2,$zero
/*  f11ac24:	1040000b */ 	beqz	$v0,.L0f11ac54
/*  f11ac28:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11ac2c:	16210004 */ 	bne	$s1,$at,.L0f11ac40
/*  f11ac30:	240c0006 */ 	addiu	$t4,$zero,0x6
/*  f11ac34:	240b000b */ 	addiu	$t3,$zero,0xb
/*  f11ac38:	10000002 */ 	beqz	$zero,.L0f11ac44
/*  f11ac3c:	ae0b0010 */ 	sw	$t3,0x10($s0)
.L0f11ac40:
/*  f11ac40:	ae0c0010 */ 	sw	$t4,0x10($s0)
.L0f11ac44:
/*  f11ac44:	0fc44364 */ 	jal	func0f110d90
/*  f11ac48:	02202025 */ 	or	$a0,$s1,$zero
/*  f11ac4c:	10000006 */ 	beqz	$zero,.L0f11ac68
/*  f11ac50:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11ac54:
/*  f11ac54:	240d0016 */ 	addiu	$t5,$zero,0x16
.L0f11ac58:
/*  f11ac58:	ae0d0010 */ 	sw	$t5,0x10($s0)
/*  f11ac5c:	0fc44364 */ 	jal	func0f110d90
/*  f11ac60:	02202025 */ 	or	$a0,$s1,$zero
/*  f11ac64:	00001025 */ 	or	$v0,$zero,$zero
.L0f11ac68:
/*  f11ac68:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f11ac6c:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f11ac70:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f11ac74:	03e00008 */ 	jr	$ra
/*  f11ac78:	27bd1060 */ 	addiu	$sp,$sp,0x1060
);

GLOBAL_ASM(
glabel func0f11ac7c
/*  f11ac7c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f11ac80:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11ac84:	00048600 */ 	sll	$s0,$a0,0x18
/*  f11ac88:	00107603 */ 	sra	$t6,$s0,0x18
/*  f11ac8c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11ac90:	01c08025 */ 	or	$s0,$t6,$zero
/*  f11ac94:	afa40030 */ 	sw	$a0,0x30($sp)
/*  f11ac98:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f11ac9c:	0c00543a */ 	jal	func000150e8
/*  f11aca0:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f11aca4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11aca8:	16010003 */ 	bne	$s0,$at,.L0f11acb8
/*  f11acac:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f11acb0:	10000009 */ 	beqz	$zero,.L0f11acd8
/*  f11acb4:	00002825 */ 	or	$a1,$zero,$zero
.L0f11acb8:
/*  f11acb8:	00107880 */ 	sll	$t7,$s0,0x2
/*  f11acbc:	01f07823 */ 	subu	$t7,$t7,$s0
/*  f11acc0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11acc4:	01f07821 */ 	addu	$t7,$t7,$s0
/*  f11acc8:	3c18800a */ 	lui	$t8,%hi(var800a3180)
/*  f11accc:	27183180 */ 	addiu	$t8,$t8,%lo(var800a3180)
/*  f11acd0:	000f78c0 */ 	sll	$t7,$t7,0x3
/*  f11acd4:	01f82821 */ 	addu	$a1,$t7,$t8
.L0f11acd8:
/*  f11acd8:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*  f11acdc:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*  f11ace0:	02003025 */ 	or	$a2,$s0,$zero
/*  f11ace4:	00003825 */ 	or	$a3,$zero,$zero
/*  f11ace8:	0fc45ec1 */ 	jal	func0f117b04
/*  f11acec:	afa30024 */ 	sw	$v1,0x24($sp)
/*  f11acf0:	00102e00 */ 	sll	$a1,$s0,0x18
/*  f11acf4:	0005ce03 */ 	sra	$t9,$a1,0x18
/*  f11acf8:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f11acfc:	03202825 */ 	or	$a1,$t9,$zero
/*  f11ad00:	00402025 */ 	or	$a0,$v0,$zero
/*  f11ad04:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f11ad08:	0fc470e7 */ 	jal	func0f11c39c
/*  f11ad0c:	24070ef5 */ 	addiu	$a3,$zero,0xef5
/*  f11ad10:	1040001b */ 	beqz	$v0,.L0f11ad80
/*  f11ad14:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f11ad18:	00104880 */ 	sll	$t1,$s0,0x2
/*  f11ad1c:	01304823 */ 	subu	$t1,$t1,$s0
/*  f11ad20:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11ad24:	01304823 */ 	subu	$t1,$t1,$s0
/*  f11ad28:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11ad2c:	01304821 */ 	addu	$t1,$t1,$s0
/*  f11ad30:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11ad34:	01304823 */ 	subu	$t1,$t1,$s0
/*  f11ad38:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11ad3c:	3c01800a */ 	lui	$at,0x800a
/*  f11ad40:	00290821 */ 	addu	$at,$at,$t1
/*  f11ad44:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f11ad48:	ac282390 */ 	sw	$t0,0x2390($at)
/*  f11ad4c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11ad50:	56010008 */ 	bnel	$s0,$at,.L0f11ad74
/*  f11ad54:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f11ad58:	0fc471e8 */ 	jal	func0f11c7a0
/*  f11ad5c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ad60:	0fc471e8 */ 	jal	func0f11c7a0
/*  f11ad64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ad68:	0fc471e8 */ 	jal	func0f11c7a0
/*  f11ad6c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ad70:	240a0001 */ 	addiu	$t2,$zero,0x1
.L0f11ad74:
/*  f11ad74:	afaa002c */ 	sw	$t2,0x2c($sp)
/*  f11ad78:	10000006 */ 	beqz	$zero,.L0f11ad94
/*  f11ad7c:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f11ad80:
/*  f11ad80:	8fab0028 */ 	lw	$t3,0x28($sp)
/*  f11ad84:	24010001 */ 	addiu	$at,$zero,0x1
/*  f11ad88:	15610002 */ 	bne	$t3,$at,.L0f11ad94
/*  f11ad8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ad90:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f11ad94:
/*  f11ad94:	1460007f */ 	bnez	$v1,.L0f11af94
/*  f11ad98:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11ad9c:	16010003 */ 	bne	$s0,$at,.L0f11adac
/*  f11ada0:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*  f11ada4:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f11ada8:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f11adac:
/*  f11adac:	14600079 */ 	bnez	$v1,.L0f11af94
/*  f11adb0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11adb4:	16010003 */ 	bne	$s0,$at,.L0f11adc4
/*  f11adb8:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*  f11adbc:	10000009 */ 	beqz	$zero,.L0f11ade4
/*  f11adc0:	00002825 */ 	or	$a1,$zero,$zero
.L0f11adc4:
/*  f11adc4:	00106080 */ 	sll	$t4,$s0,0x2
/*  f11adc8:	01906023 */ 	subu	$t4,$t4,$s0
/*  f11adcc:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f11add0:	01906021 */ 	addu	$t4,$t4,$s0
/*  f11add4:	3c0d800a */ 	lui	$t5,%hi(var800a3180)
/*  f11add8:	25ad3180 */ 	addiu	$t5,$t5,%lo(var800a3180)
/*  f11addc:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f11ade0:	018d2821 */ 	addu	$a1,$t4,$t5
.L0f11ade4:
/*  f11ade4:	02003025 */ 	or	$a2,$s0,$zero
/*  f11ade8:	0c013e15 */ 	jal	func0004f854
/*  f11adec:	afa30024 */ 	sw	$v1,0x24($sp)
/*  f11adf0:	00102e00 */ 	sll	$a1,$s0,0x18
/*  f11adf4:	00057603 */ 	sra	$t6,$a1,0x18
/*  f11adf8:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f11adfc:	01c02825 */ 	or	$a1,$t6,$zero
/*  f11ae00:	00402025 */ 	or	$a0,$v0,$zero
/*  f11ae04:	00003025 */ 	or	$a2,$zero,$zero
/*  f11ae08:	0fc470e7 */ 	jal	func0f11c39c
/*  f11ae0c:	24070f19 */ 	addiu	$a3,$zero,0xf19
/*  f11ae10:	1040001a */ 	beqz	$v0,.L0f11ae7c
/*  f11ae14:	8fa30024 */ 	lw	$v1,0x24($sp)
/*  f11ae18:	00107880 */ 	sll	$t7,$s0,0x2
/*  f11ae1c:	01f07823 */ 	subu	$t7,$t7,$s0
/*  f11ae20:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11ae24:	01f07823 */ 	subu	$t7,$t7,$s0
/*  f11ae28:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11ae2c:	01f07821 */ 	addu	$t7,$t7,$s0
/*  f11ae30:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11ae34:	01f07823 */ 	subu	$t7,$t7,$s0
/*  f11ae38:	3c18800a */ 	lui	$t8,%hi(var800a2380)
/*  f11ae3c:	27182380 */ 	addiu	$t8,$t8,%lo(var800a2380)
/*  f11ae40:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11ae44:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f11ae48:	8c4a0264 */ 	lw	$t2,0x264($v0)
/*  f11ae4c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f11ae50:	2408000b */ 	addiu	$t0,$zero,0xb
/*  f11ae54:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f11ae58:	240c0001 */ 	addiu	$t4,$zero,0x1
/*  f11ae5c:	254b0001 */ 	addiu	$t3,$t2,0x1
/*  f11ae60:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f11ae64:	ac480010 */ 	sw	$t0,0x10($v0)
/*  f11ae68:	ac490004 */ 	sw	$t1,0x4($v0)
/*  f11ae6c:	ac4b0264 */ 	sw	$t3,0x264($v0)
/*  f11ae70:	afac002c */ 	sw	$t4,0x2c($sp)
/*  f11ae74:	10000007 */ 	beqz	$zero,.L0f11ae94
/*  f11ae78:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f11ae7c:
/*  f11ae7c:	8fad0028 */ 	lw	$t5,0x28($sp)
/*  f11ae80:	24010001 */ 	addiu	$at,$zero,0x1
/*  f11ae84:	15a10003 */ 	bne	$t5,$at,.L0f11ae94
/*  f11ae88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ae8c:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f11ae90:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f11ae94:
/*  f11ae94:	1460003f */ 	bnez	$v1,.L0f11af94
/*  f11ae98:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11ae9c:	16010003 */ 	bne	$s0,$at,.L0f11aeac
/*  f11aea0:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*  f11aea4:	10000009 */ 	beqz	$zero,.L0f11aecc
/*  f11aea8:	00002825 */ 	or	$a1,$zero,$zero
.L0f11aeac:
/*  f11aeac:	00107080 */ 	sll	$t6,$s0,0x2
/*  f11aeb0:	01d07023 */ 	subu	$t6,$t6,$s0
/*  f11aeb4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11aeb8:	01d07021 */ 	addu	$t6,$t6,$s0
/*  f11aebc:	3c0f800a */ 	lui	$t7,%hi(var800a3180)
/*  f11aec0:	25ef3180 */ 	addiu	$t7,$t7,%lo(var800a3180)
/*  f11aec4:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f11aec8:	01cf2821 */ 	addu	$a1,$t6,$t7
.L0f11aecc:
/*  f11aecc:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*  f11aed0:	0c001840 */ 	jal	func00006100
/*  f11aed4:	02003025 */ 	or	$a2,$s0,$zero
/*  f11aed8:	00102e00 */ 	sll	$a1,$s0,0x18
/*  f11aedc:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f11aee0:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f11aee4:	03002825 */ 	or	$a1,$t8,$zero
/*  f11aee8:	00402025 */ 	or	$a0,$v0,$zero
/*  f11aeec:	00003025 */ 	or	$a2,$zero,$zero
/*  f11aef0:	0fc470e7 */ 	jal	func0f11c39c
/*  f11aef4:	24070f31 */ 	addiu	$a3,$zero,0xf31
/*  f11aef8:	10400022 */ 	beqz	$v0,.L0f11af84
/*  f11aefc:	8fa80028 */ 	lw	$t0,0x28($sp)
/*  f11af00:	0010c880 */ 	sll	$t9,$s0,0x2
/*  f11af04:	0330c823 */ 	subu	$t9,$t9,$s0
/*  f11af08:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11af0c:	0330c823 */ 	subu	$t9,$t9,$s0
/*  f11af10:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11af14:	0330c821 */ 	addu	$t9,$t9,$s0
/*  f11af18:	3c0a8009 */ 	lui	$t2,0x8009
/*  f11af1c:	914a0af0 */ 	lbu	$t2,0xaf0($t2)
/*  f11af20:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11af24:	0330c823 */ 	subu	$t9,$t9,$s0
/*  f11af28:	3c08800a */ 	lui	$t0,%hi(var800a2380)
/*  f11af2c:	25082380 */ 	addiu	$t0,$t0,%lo(var800a2380)
/*  f11af30:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11af34:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f11af38:	24010001 */ 	addiu	$at,$zero,0x1
/*  f11af3c:	afa9002c */ 	sw	$t1,0x2c($sp)
/*  f11af40:	15410005 */ 	bne	$t2,$at,.L0f11af58
/*  f11af44:	03281021 */ 	addu	$v0,$t9,$t0
/*  f11af48:	240b0016 */ 	addiu	$t3,$zero,0x16
/*  f11af4c:	ac400000 */ 	sw	$zero,0x0($v0)
/*  f11af50:	10000010 */ 	beqz	$zero,.L0f11af94
/*  f11af54:	ac4b0010 */ 	sw	$t3,0x10($v0)
.L0f11af58:
/*  f11af58:	904e02b8 */ 	lbu	$t6,0x2b8($v0)
/*  f11af5c:	8c580264 */ 	lw	$t8,0x264($v0)
/*  f11af60:	240c0003 */ 	addiu	$t4,$zero,0x3
/*  f11af64:	240d0008 */ 	addiu	$t5,$zero,0x8
/*  f11af68:	31cfff7f */ 	andi	$t7,$t6,0xff7f
/*  f11af6c:	27190001 */ 	addiu	$t9,$t8,0x1
/*  f11af70:	ac4c0000 */ 	sw	$t4,0x0($v0)
/*  f11af74:	ac4d0010 */ 	sw	$t5,0x10($v0)
/*  f11af78:	a04f02b8 */ 	sb	$t7,0x2b8($v0)
/*  f11af7c:	10000005 */ 	beqz	$zero,.L0f11af94
/*  f11af80:	ac590264 */ 	sw	$t9,0x264($v0)
.L0f11af84:
/*  f11af84:	24010001 */ 	addiu	$at,$zero,0x1
/*  f11af88:	15010002 */ 	bne	$t0,$at,.L0f11af94
/*  f11af8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11af90:	afa0002c */ 	sw	$zero,0x2c($sp)
.L0f11af94:
/*  f11af94:	0c005451 */ 	jal	func00015144
/*  f11af98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11af9c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11afa0:	8fa2002c */ 	lw	$v0,0x2c($sp)
/*  f11afa4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f11afa8:	03e00008 */ 	jr	$ra
/*  f11afac:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f11afb0
/*  f11afb0:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f11afb4:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f11afb8:	00049600 */ 	sll	$s2,$a0,0x18
/*  f11afbc:	00127603 */ 	sra	$t6,$s2,0x18
/*  f11afc0:	afa400e8 */ 	sw	$a0,0xe8($sp)
/*  f11afc4:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f11afc8:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f11afcc:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f11afd0:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f11afd4:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f11afd8:	00a0a025 */ 	or	$s4,$a1,$zero
/*  f11afdc:	01c09025 */ 	or	$s2,$t6,$zero
/*  f11afe0:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f11afe4:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f11afe8:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f11afec:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f11aff0:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f11aff4:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f11aff8:	afa600f0 */ 	sw	$a2,0xf0($sp)
/*  f11affc:	01e02025 */ 	or	$a0,$t7,$zero
/*  f11b000:	0fc45974 */ 	jal	func0f1165d0
/*  f11b004:	00008825 */ 	or	$s1,$zero,$zero
/*  f11b008:	1040000d */ 	beqz	$v0,.L0f11b040
/*  f11b00c:	27b80068 */ 	addiu	$t8,$sp,0x68
/*  f11b010:	02388021 */ 	addu	$s0,$s1,$t8
/*  f11b014:	24130021 */ 	addiu	$s3,$zero,0x21
/*  f11b018:	00122600 */ 	sll	$a0,$s2,0x18
.L0f11b01c:
/*  f11b01c:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f11b020:	03202025 */ 	or	$a0,$t9,$zero
/*  f11b024:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f11b028:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11b02c:	0fc45974 */ 	jal	func0f1165d0
/*  f11b030:	a213ffff */ 	sb	$s3,-0x1($s0)
/*  f11b034:	0222082b */ 	sltu	$at,$s1,$v0
/*  f11b038:	5420fff8 */ 	bnezl	$at,.L0f11b01c
/*  f11b03c:	00122600 */ 	sll	$a0,$s2,0x18
.L0f11b040:
/*  f11b040:	8fa800f0 */ 	lw	$t0,0xf0($sp)
/*  f11b044:	00124880 */ 	sll	$t1,$s2,0x2
/*  f11b048:	01324823 */ 	subu	$t1,$t1,$s2
/*  f11b04c:	0288082b */ 	sltu	$at,$s4,$t0
/*  f11b050:	1020003d */ 	beqz	$at,.L0f11b148
/*  f11b054:	02808825 */ 	or	$s1,$s4,$zero
/*  f11b058:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11b05c:	01324823 */ 	subu	$t1,$t1,$s2
/*  f11b060:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11b064:	01324821 */ 	addu	$t1,$t1,$s2
/*  f11b068:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11b06c:	01324823 */ 	subu	$t1,$t1,$s2
/*  f11b070:	3c0a800a */ 	lui	$t2,%hi(var800a2380)
/*  f11b074:	254a2380 */ 	addiu	$t2,$t2,%lo(var800a2380)
/*  f11b078:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11b07c:	3c17800a */ 	lui	$s7,%hi(var800a3180)
/*  f11b080:	26f73180 */ 	addiu	$s7,$s7,%lo(var800a3180)
/*  f11b084:	012aa021 */ 	addu	$s4,$t1,$t2
/*  f11b088:	241e0068 */ 	addiu	$s8,$zero,0x68
/*  f11b08c:	27b60068 */ 	addiu	$s6,$sp,0x68
/*  f11b090:	24150004 */ 	addiu	$s5,$zero,0x4
.L0f11b094:
/*  f11b094:	16550003 */ 	bne	$s2,$s5,.L0f11b0a4
/*  f11b098:	00122600 */ 	sll	$a0,$s2,0x18
/*  f11b09c:	10000005 */ 	beqz	$zero,.L0f11b0b4
/*  f11b0a0:	00008025 */ 	or	$s0,$zero,$zero
.L0f11b0a4:
/*  f11b0a4:	025e0019 */ 	multu	$s2,$s8
/*  f11b0a8:	00005812 */ 	mflo	$t3
/*  f11b0ac:	02eb8021 */ 	addu	$s0,$s7,$t3
/*  f11b0b0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11b0b4:
/*  f11b0b4:	00046603 */ 	sra	$t4,$a0,0x18
/*  f11b0b8:	0fc45974 */ 	jal	func0f1165d0
/*  f11b0bc:	01802025 */ 	or	$a0,$t4,$zero
/*  f11b0c0:	00122600 */ 	sll	$a0,$s2,0x18
/*  f11b0c4:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f11b0c8:	01a02025 */ 	or	$a0,$t5,$zero
/*  f11b0cc:	0fc45974 */ 	jal	func0f1165d0
/*  f11b0d0:	00409825 */ 	or	$s3,$v0,$zero
/*  f11b0d4:	02710019 */ 	multu	$s3,$s1
/*  f11b0d8:	00122600 */ 	sll	$a0,$s2,0x18
/*  f11b0dc:	00047603 */ 	sra	$t6,$a0,0x18
/*  f11b0e0:	01c02025 */ 	or	$a0,$t6,$zero
/*  f11b0e4:	02002825 */ 	or	$a1,$s0,$zero
/*  f11b0e8:	8e86029c */ 	lw	$a2,0x29c($s4)
/*  f11b0ec:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f11b0f0:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f11b0f4:	afb60018 */ 	sw	$s6,0x18($sp)
/*  f11b0f8:	00007812 */ 	mflo	$t7
/*  f11b0fc:	afaf0010 */ 	sw	$t7,0x10($sp)
/*  f11b100:	0fc46941 */ 	jal	func0f11a504
/*  f11b104:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11b108:	00122e00 */ 	sll	$a1,$s2,0x18
/*  f11b10c:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f11b110:	a28002be */ 	sb	$zero,0x2be($s4)
/*  f11b114:	03002825 */ 	or	$a1,$t8,$zero
/*  f11b118:	00402025 */ 	or	$a0,$v0,$zero
/*  f11b11c:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f11b120:	0fc470e7 */ 	jal	func0f11c39c
/*  f11b124:	24070f6c */ 	addiu	$a3,$zero,0xf6c
/*  f11b128:	14400004 */ 	bnez	$v0,.L0f11b13c
/*  f11b12c:	8fa800f0 */ 	lw	$t0,0xf0($sp)
/*  f11b130:	2419ffff */ 	addiu	$t9,$zero,-1
/*  f11b134:	10000004 */ 	beqz	$zero,.L0f11b148
/*  f11b138:	ae99029c */ 	sw	$t9,0x29c($s4)
.L0f11b13c:
/*  f11b13c:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f11b140:	1628ffd4 */ 	bne	$s1,$t0,.L0f11b094
/*  f11b144:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11b148:
/*  f11b148:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f11b14c:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f11b150:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f11b154:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f11b158:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f11b15c:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f11b160:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f11b164:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f11b168:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f11b16c:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f11b170:	03e00008 */ 	jr	$ra
/*  f11b174:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
);

GLOBAL_ASM(
glabel func0f11b178
/*  f11b178:	27bdef80 */ 	addiu	$sp,$sp,-4224
/*  f11b17c:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f11b180:	0004be00 */ 	sll	$s7,$a0,0x18
/*  f11b184:	00177603 */ 	sra	$t6,$s7,0x18
/*  f11b188:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f11b18c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11b190:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11b194:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11b198:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11b19c:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f11b1a0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11b1a4:	afa41080 */ 	sw	$a0,0x1080($sp)
/*  f11b1a8:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11b1ac:	3c18800a */ 	lui	$t8,%hi(var800a2380)
/*  f11b1b0:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f11b1b4:	27182380 */ 	addiu	$t8,$t8,%lo(var800a2380)
/*  f11b1b8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11b1bc:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f11b1c0:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f11b1c4:	01f8b021 */ 	addu	$s6,$t7,$t8
/*  f11b1c8:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f11b1cc:	01c0b825 */ 	or	$s7,$t6,$zero
/*  f11b1d0:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f11b1d4:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f11b1d8:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f11b1dc:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f11b1e0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f11b1e4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f11b1e8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11b1ec:	afa51084 */ 	sw	$a1,0x1084($sp)
/*  f11b1f0:	afa61088 */ 	sw	$a2,0x1088($sp)
/*  f11b1f4:	afb6107c */ 	sw	$s6,0x107c($sp)
/*  f11b1f8:	0fc45974 */ 	jal	func0f1165d0
/*  f11b1fc:	03202025 */ 	or	$a0,$t9,$zero
/*  f11b200:	8fa81088 */ 	lw	$t0,0x1088($sp)
/*  f11b204:	8fa61084 */ 	lw	$a2,0x1084($sp)
/*  f11b208:	0000a825 */ 	or	$s5,$zero,$zero
/*  f11b20c:	8d090008 */ 	lw	$t1,0x8($t0)
/*  f11b210:	27a30078 */ 	addiu	$v1,$sp,0x78
/*  f11b214:	241effff */ 	addiu	$s8,$zero,-1
/*  f11b218:	312a0fff */ 	andi	$t2,$t1,0xfff
/*  f11b21c:	0142001b */ 	divu	$zero,$t2,$v0
/*  f11b220:	00005812 */ 	mflo	$t3
/*  f11b224:	01662821 */ 	addu	$a1,$t3,$a2
/*  f11b228:	14400002 */ 	bnez	$v0,.L0f11b234
/*  f11b22c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11b230:	0007000d */ 	break	0x7
.L0f11b234:
/*  f11b234:	27a21078 */ 	addiu	$v0,$sp,0x1078
.L0f11b238:
/*  f11b238:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f11b23c:	0062082b */ 	sltu	$at,$v1,$v0
/*  f11b240:	1420fffd */ 	bnez	$at,.L0f11b238
/*  f11b244:	ac7efffc */ 	sw	$s8,-0x4($v1)
/*  f11b248:	92cc02be */ 	lbu	$t4,0x2be($s6)
/*  f11b24c:	0000a825 */ 	or	$s5,$zero,$zero
/*  f11b250:	00009825 */ 	or	$s3,$zero,$zero
/*  f11b254:	19800035 */ 	blez	$t4,.L0f11b32c
/*  f11b258:	27b40078 */ 	addiu	$s4,$sp,0x78
/*  f11b25c:	afa50060 */ 	sw	$a1,0x60($sp)
/*  f11b260:	8ecd02c0 */ 	lw	$t5,0x2c0($s6)
.L0f11b264:
/*  f11b264:	00172600 */ 	sll	$a0,$s7,0x18
/*  f11b268:	00047603 */ 	sra	$t6,$a0,0x18
/*  f11b26c:	01b39021 */ 	addu	$s2,$t5,$s3
/*  f11b270:	26520004 */ 	addiu	$s2,$s2,0x4
/*  f11b274:	01c02025 */ 	or	$a0,$t6,$zero
/*  f11b278:	0fc45974 */ 	jal	func0f1165d0
/*  f11b27c:	00008025 */ 	or	$s0,$zero,$zero
/*  f11b280:	8e4f0008 */ 	lw	$t7,0x8($s2)
/*  f11b284:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f11b288:	0302001b */ 	divu	$zero,$t8,$v0
/*  f11b28c:	0000c812 */ 	mflo	$t9
/*  f11b290:	14400002 */ 	bnez	$v0,.L0f11b29c
/*  f11b294:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11b298:	0007000d */ 	break	0x7
.L0f11b29c:
/*  f11b29c:	5320001a */ 	beqzl	$t9,.L0f11b308
/*  f11b2a0:	8fa8107c */ 	lw	$t0,0x107c($sp)
/*  f11b2a4:	00108880 */ 	sll	$s1,$s0,0x2
/*  f11b2a8:	8ec802c0 */ 	lw	$t0,0x2c0($s6)
.L0f11b2ac:
/*  f11b2ac:	00172600 */ 	sll	$a0,$s7,0x18
/*  f11b2b0:	00047603 */ 	sra	$t6,$a0,0x18
/*  f11b2b4:	01134821 */ 	addu	$t1,$t0,$s3
/*  f11b2b8:	8d2a0000 */ 	lw	$t2,0x0($t1)
/*  f11b2bc:	01c02025 */ 	or	$a0,$t6,$zero
/*  f11b2c0:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11b2c4:	000a5880 */ 	sll	$t3,$t2,0x2
/*  f11b2c8:	028b6021 */ 	addu	$t4,$s4,$t3
/*  f11b2cc:	01916821 */ 	addu	$t5,$t4,$s1
/*  f11b2d0:	26310004 */ 	addiu	$s1,$s1,0x4
/*  f11b2d4:	0fc45974 */ 	jal	func0f1165d0
/*  f11b2d8:	adb50000 */ 	sw	$s5,0x0($t5)
/*  f11b2dc:	8e4f0008 */ 	lw	$t7,0x8($s2)
/*  f11b2e0:	31f80fff */ 	andi	$t8,$t7,0xfff
/*  f11b2e4:	0302001b */ 	divu	$zero,$t8,$v0
/*  f11b2e8:	0000c812 */ 	mflo	$t9
/*  f11b2ec:	0219082b */ 	sltu	$at,$s0,$t9
/*  f11b2f0:	14400002 */ 	bnez	$v0,.L0f11b2fc
/*  f11b2f4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11b2f8:	0007000d */ 	break	0x7
.L0f11b2fc:
/*  f11b2fc:	5420ffeb */ 	bnezl	$at,.L0f11b2ac
/*  f11b300:	8ec802c0 */ 	lw	$t0,0x2c0($s6)
/*  f11b304:	8fa8107c */ 	lw	$t0,0x107c($sp)
.L0f11b308:
/*  f11b308:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f11b30c:	26730024 */ 	addiu	$s3,$s3,0x24
/*  f11b310:	910902be */ 	lbu	$t1,0x2be($t0)
/*  f11b314:	02a9082a */ 	slt	$at,$s5,$t1
/*  f11b318:	5420ffd2 */ 	bnezl	$at,.L0f11b264
/*  f11b31c:	8ecd02c0 */ 	lw	$t5,0x2c0($s6)
/*  f11b320:	0000a825 */ 	or	$s5,$zero,$zero
/*  f11b324:	8fa61084 */ 	lw	$a2,0x1084($sp)
/*  f11b328:	8fa50060 */ 	lw	$a1,0x60($sp)
.L0f11b32c:
/*  f11b32c:	00c5082a */ 	slt	$at,$a2,$a1
/*  f11b330:	10200010 */ 	beqz	$at,.L0f11b374
/*  f11b334:	00c01025 */ 	or	$v0,$a2,$zero
/*  f11b338:	00025080 */ 	sll	$t2,$v0,0x2
/*  f11b33c:	27ab0078 */ 	addiu	$t3,$sp,0x78
/*  f11b340:	014b1821 */ 	addu	$v1,$t2,$t3
/*  f11b344:	24140024 */ 	addiu	$s4,$zero,0x24
.L0f11b348:
/*  f11b348:	8c640000 */ 	lw	$a0,0x0($v1)
/*  f11b34c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11b350:	13c40006 */ 	beq	$s8,$a0,.L0f11b36c
/*  f11b354:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11b358:	00940019 */ 	multu	$a0,$s4
/*  f11b35c:	8ecc02c0 */ 	lw	$t4,0x2c0($s6)
/*  f11b360:	00006812 */ 	mflo	$t5
/*  f11b364:	018d7021 */ 	addu	$t6,$t4,$t5
/*  f11b368:	adde0000 */ 	sw	$s8,0x0($t6)
.L0f11b36c:
/*  f11b36c:	1445fff6 */ 	bne	$v0,$a1,.L0f11b348
/*  f11b370:	24630004 */ 	addiu	$v1,$v1,0x4
.L0f11b374:
/*  f11b374:	92d802be */ 	lbu	$t8,0x2be($s6)
/*  f11b378:	24100024 */ 	addiu	$s0,$zero,0x24
/*  f11b37c:	8ecf02c0 */ 	lw	$t7,0x2c0($s6)
/*  f11b380:	03100019 */ 	multu	$t8,$s0
/*  f11b384:	00172600 */ 	sll	$a0,$s7,0x18
/*  f11b388:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f11b38c:	24140024 */ 	addiu	$s4,$zero,0x24
/*  f11b390:	01202025 */ 	or	$a0,$t1,$zero
/*  f11b394:	0000c812 */ 	mflo	$t9
/*  f11b398:	01f94021 */ 	addu	$t0,$t7,$t9
/*  f11b39c:	0fc45974 */ 	jal	func0f1165d0
/*  f11b3a0:	ad060000 */ 	sw	$a2,0x0($t0)
/*  f11b3a4:	92cb02be */ 	lbu	$t3,0x2be($s6)
/*  f11b3a8:	8eca02c0 */ 	lw	$t2,0x2c0($s6)
/*  f11b3ac:	8fa51088 */ 	lw	$a1,0x1088($sp)
/*  f11b3b0:	01700019 */ 	multu	$t3,$s0
/*  f11b3b4:	00403025 */ 	or	$a2,$v0,$zero
/*  f11b3b8:	00006012 */ 	mflo	$t4
/*  f11b3bc:	014c2021 */ 	addu	$a0,$t2,$t4
/*  f11b3c0:	0c012978 */ 	jal	func0004a5e0
/*  f11b3c4:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f11b3c8:	92cd02be */ 	lbu	$t5,0x2be($s6)
/*  f11b3cc:	00009025 */ 	or	$s2,$zero,$zero
/*  f11b3d0:	00009825 */ 	or	$s3,$zero,$zero
/*  f11b3d4:	25ae0001 */ 	addiu	$t6,$t5,0x1
/*  f11b3d8:	31d800ff */ 	andi	$t8,$t6,0xff
/*  f11b3dc:	1b00001d */ 	blez	$t8,.L0f11b454
/*  f11b3e0:	a2ce02be */ 	sb	$t6,0x2be($s6)
/*  f11b3e4:	8ed002c0 */ 	lw	$s0,0x2c0($s6)
.L0f11b3e8:
/*  f11b3e8:	02137821 */ 	addu	$t7,$s0,$s3
/*  f11b3ec:	8de20000 */ 	lw	$v0,0x0($t7)
/*  f11b3f0:	53c20012 */ 	beql	$s8,$v0,.L0f11b43c
/*  f11b3f4:	8fa9107c */ 	lw	$t1,0x107c($sp)
/*  f11b3f8:	02540019 */ 	multu	$s2,$s4
/*  f11b3fc:	00172600 */ 	sll	$a0,$s7,0x18
/*  f11b400:	00044603 */ 	sra	$t0,$a0,0x18
/*  f11b404:	01002025 */ 	or	$a0,$t0,$zero
/*  f11b408:	00008812 */ 	mflo	$s1
/*  f11b40c:	0211c821 */ 	addu	$t9,$s0,$s1
/*  f11b410:	0fc45974 */ 	jal	func0f1165d0
/*  f11b414:	af220000 */ 	sw	$v0,0x0($t9)
/*  f11b418:	8ed002c0 */ 	lw	$s0,0x2c0($s6)
/*  f11b41c:	00403025 */ 	or	$a2,$v0,$zero
/*  f11b420:	02112021 */ 	addu	$a0,$s0,$s1
/*  f11b424:	02132821 */ 	addu	$a1,$s0,$s3
/*  f11b428:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f11b42c:	0c012978 */ 	jal	func0004a5e0
/*  f11b430:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f11b434:	26520001 */ 	addiu	$s2,$s2,0x1
/*  f11b438:	8fa9107c */ 	lw	$t1,0x107c($sp)
.L0f11b43c:
/*  f11b43c:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f11b440:	26730024 */ 	addiu	$s3,$s3,0x24
/*  f11b444:	912b02be */ 	lbu	$t3,0x2be($t1)
/*  f11b448:	02ab082a */ 	slt	$at,$s5,$t3
/*  f11b44c:	5420ffe6 */ 	bnezl	$at,.L0f11b3e8
/*  f11b450:	8ed002c0 */ 	lw	$s0,0x2c0($s6)
.L0f11b454:
/*  f11b454:	a2d202be */ 	sb	$s2,0x2be($s6)
/*  f11b458:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f11b45c:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f11b460:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f11b464:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f11b468:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f11b46c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f11b470:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f11b474:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f11b478:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f11b47c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f11b480:	03e00008 */ 	jr	$ra
/*  f11b484:	27bd1080 */ 	addiu	$sp,$sp,0x1080
);

GLOBAL_ASM(
glabel func0f11b488
/*  f11b488:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11b48c:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f11b490:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11b494:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11b498:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11b49c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11b4a0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11b4a4:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11b4a8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11b4ac:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11b4b0:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11b4b4:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f11b4b8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11b4bc:	03194821 */ 	addu	$t1,$t8,$t9
/*  f11b4c0:	912302be */ 	lbu	$v1,0x2be($t1)
/*  f11b4c4:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f11b4c8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11b4cc:	28610032 */ 	slti	$at,$v1,0x32
/*  f11b4d0:	afa40018 */ 	sw	$a0,0x18($sp)
/*  f11b4d4:	afa60020 */ 	sw	$a2,0x20($sp)
/*  f11b4d8:	10200016 */ 	beqz	$at,.L0f11b534
/*  f11b4dc:	01204025 */ 	or	$t0,$t1,$zero
/*  f11b4e0:	18600014 */ 	blez	$v1,.L0f11b534
/*  f11b4e4:	00001025 */ 	or	$v0,$zero,$zero
/*  f11b4e8:	8d2a02c0 */ 	lw	$t2,0x2c0($t1)
/*  f11b4ec:	00003825 */ 	or	$a3,$zero,$zero
/*  f11b4f0:	8fa40020 */ 	lw	$a0,0x20($sp)
/*  f11b4f4:	01401825 */ 	or	$v1,$t2,$zero
.L0f11b4f8:
/*  f11b4f8:	8c6b0000 */ 	lw	$t3,0x0($v1)
/*  f11b4fc:	54ab0008 */ 	bnel	$a1,$t3,.L0f11b520
/*  f11b500:	910c02be */ 	lbu	$t4,0x2be($t0)
/*  f11b504:	01472821 */ 	addu	$a1,$t2,$a3
/*  f11b508:	24a50004 */ 	addiu	$a1,$a1,0x4
/*  f11b50c:	0c012978 */ 	jal	func0004a5e0
/*  f11b510:	24060010 */ 	addiu	$a2,$zero,0x10
/*  f11b514:	10000008 */ 	beqz	$zero,.L0f11b538
/*  f11b518:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11b51c:	910c02be */ 	lbu	$t4,0x2be($t0)
.L0f11b520:
/*  f11b520:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11b524:	24e70024 */ 	addiu	$a3,$a3,0x24
/*  f11b528:	004c082a */ 	slt	$at,$v0,$t4
/*  f11b52c:	1420fff2 */ 	bnez	$at,.L0f11b4f8
/*  f11b530:	24630024 */ 	addiu	$v1,$v1,0x24
.L0f11b534:
/*  f11b534:	00001025 */ 	or	$v0,$zero,$zero
.L0f11b538:
/*  f11b538:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11b53c:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f11b540:	03e00008 */ 	jr	$ra
/*  f11b544:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11b548
/*  f11b548:	27bdff88 */ 	addiu	$sp,$sp,-120
/*  f11b54c:	afb20038 */ 	sw	$s2,0x38($sp)
/*  f11b550:	00049600 */ 	sll	$s2,$a0,0x18
/*  f11b554:	00127603 */ 	sra	$t6,$s2,0x18
/*  f11b558:	afb10034 */ 	sw	$s1,0x34($sp)
/*  f11b55c:	afb00030 */ 	sw	$s0,0x30($sp)
/*  f11b560:	01c09025 */ 	or	$s2,$t6,$zero
/*  f11b564:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f11b568:	afa40078 */ 	sw	$a0,0x78($sp)
/*  f11b56c:	27b00058 */ 	addiu	$s0,$sp,0x58
/*  f11b570:	27b10078 */ 	addiu	$s1,$sp,0x78
.L0f11b574:
/*  f11b574:	0c004b70 */ 	jal	random
/*  f11b578:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11b57c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11b580:	1611fffc */ 	bne	$s0,$s1,.L0f11b574
/*  f11b584:	a202ffff */ 	sb	$v0,-0x1($s0)
/*  f11b588:	00122600 */ 	sll	$a0,$s2,0x18
/*  f11b58c:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f11b590:	03002025 */ 	or	$a0,$t8,$zero
/*  f11b594:	0fc45c25 */ 	jal	func0f117094
/*  f11b598:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f11b59c:	00122600 */ 	sll	$a0,$s2,0x18
/*  f11b5a0:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f11b5a4:	03202025 */ 	or	$a0,$t9,$zero
/*  f11b5a8:	0fc45996 */ 	jal	func0f116658
/*  f11b5ac:	00402825 */ 	or	$a1,$v0,$zero
/*  f11b5b0:	00124080 */ 	sll	$t0,$s2,0x2
/*  f11b5b4:	01124023 */ 	subu	$t0,$t0,$s2
/*  f11b5b8:	00084080 */ 	sll	$t0,$t0,0x2
/*  f11b5bc:	01124023 */ 	subu	$t0,$t0,$s2
/*  f11b5c0:	00084080 */ 	sll	$t0,$t0,0x2
/*  f11b5c4:	01124021 */ 	addu	$t0,$t0,$s2
/*  f11b5c8:	00084080 */ 	sll	$t0,$t0,0x2
/*  f11b5cc:	01124023 */ 	subu	$t0,$t0,$s2
/*  f11b5d0:	3c09800a */ 	lui	$t1,%hi(var800a2380)
/*  f11b5d4:	25292380 */ 	addiu	$t1,$t1,%lo(var800a2380)
/*  f11b5d8:	00084080 */ 	sll	$t0,$t0,0x2
/*  f11b5dc:	00122600 */ 	sll	$a0,$s2,0x18
/*  f11b5e0:	01098021 */ 	addu	$s0,$t0,$t1
/*  f11b5e4:	240a0010 */ 	addiu	$t2,$zero,0x10
/*  f11b5e8:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f11b5ec:	afa20054 */ 	sw	$v0,0x54($sp)
/*  f11b5f0:	ae0a025c */ 	sw	$t2,0x25c($s0)
/*  f11b5f4:	0fc459a3 */ 	jal	func0f11668c
/*  f11b5f8:	01602025 */ 	or	$a0,$t3,$zero
/*  f11b5fc:	00122600 */ 	sll	$a0,$s2,0x18
/*  f11b600:	00046603 */ 	sra	$t4,$a0,0x18
/*  f11b604:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f11b608:	ae020260 */ 	sw	$v0,0x260($s0)
/*  f11b60c:	a20002be */ 	sb	$zero,0x2be($s0)
/*  f11b610:	afad0020 */ 	sw	$t5,0x20($sp)
/*  f11b614:	01802025 */ 	or	$a0,$t4,$zero
/*  f11b618:	00002825 */ 	or	$a1,$zero,$zero
/*  f11b61c:	24060004 */ 	addiu	$a2,$zero,0x4
/*  f11b620:	00003825 */ 	or	$a3,$zero,$zero
/*  f11b624:	afa00010 */ 	sw	$zero,0x10($sp)
/*  f11b628:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f11b62c:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f11b630:	0fc46f15 */ 	jal	func0f11bc54
/*  f11b634:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f11b638:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11b63c:	16410003 */ 	bne	$s2,$at,.L0f11b64c
/*  f11b640:	00122600 */ 	sll	$a0,$s2,0x18
/*  f11b644:	10000009 */ 	beqz	$zero,.L0f11b66c
/*  f11b648:	00008825 */ 	or	$s1,$zero,$zero
.L0f11b64c:
/*  f11b64c:	00127080 */ 	sll	$t6,$s2,0x2
/*  f11b650:	01d27023 */ 	subu	$t6,$t6,$s2
/*  f11b654:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11b658:	01d27021 */ 	addu	$t6,$t6,$s2
/*  f11b65c:	3c0f800a */ 	lui	$t7,%hi(var800a3180)
/*  f11b660:	25ef3180 */ 	addiu	$t7,$t7,%lo(var800a3180)
/*  f11b664:	000e70c0 */ 	sll	$t6,$t6,0x3
/*  f11b668:	01cf8821 */ 	addu	$s1,$t6,$t7
.L0f11b66c:
/*  f11b66c:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f11b670:	0fc45974 */ 	jal	func0f1165d0
/*  f11b674:	03002025 */ 	or	$a0,$t8,$zero
/*  f11b678:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f11b67c:	00122600 */ 	sll	$a0,$s2,0x18
/*  f11b680:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f11b684:	27a90058 */ 	addiu	$t1,$sp,0x58
/*  f11b688:	afa90018 */ 	sw	$t1,0x18($sp)
/*  f11b68c:	03202025 */ 	or	$a0,$t9,$zero
/*  f11b690:	02202825 */ 	or	$a1,$s1,$zero
/*  f11b694:	8e06029c */ 	lw	$a2,0x29c($s0)
/*  f11b698:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f11b69c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f11b6a0:	0fc46941 */ 	jal	func0f11a504
/*  f11b6a4:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f11b6a8:	00122e00 */ 	sll	$a1,$s2,0x18
/*  f11b6ac:	00055603 */ 	sra	$t2,$a1,0x18
/*  f11b6b0:	01402825 */ 	or	$a1,$t2,$zero
/*  f11b6b4:	00402025 */ 	or	$a0,$v0,$zero
/*  f11b6b8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f11b6bc:	0fc470e7 */ 	jal	func0f11c39c
/*  f11b6c0:	2407102c */ 	addiu	$a3,$zero,0x102c
/*  f11b6c4:	14400003 */ 	bnez	$v0,.L0f11b6d4
/*  f11b6c8:	8fb10034 */ 	lw	$s1,0x34($sp)
/*  f11b6cc:	10000002 */ 	beqz	$zero,.L0f11b6d8
/*  f11b6d0:	2402ffff */ 	addiu	$v0,$zero,-1
.L0f11b6d4:
/*  f11b6d4:	8e020260 */ 	lw	$v0,0x260($s0)
.L0f11b6d8:
/*  f11b6d8:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*  f11b6dc:	8fb00030 */ 	lw	$s0,0x30($sp)
/*  f11b6e0:	8fb20038 */ 	lw	$s2,0x38($sp)
/*  f11b6e4:	03e00008 */ 	jr	$ra
/*  f11b6e8:	27bd0078 */ 	addiu	$sp,$sp,0x78
/*  f11b6ec:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11b6f0:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f11b6f4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11b6f8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11b6fc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11b700:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11b704:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11b708:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11b70c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11b710:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11b714:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11b718:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f11b71c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11b720:	03191021 */ 	addu	$v0,$t8,$t9
/*  f11b724:	8c480010 */ 	lw	$t0,0x10($v0)
/*  f11b728:	2401000b */ 	addiu	$at,$zero,0xb
/*  f11b72c:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11b730:	55010008 */ 	bnel	$t0,$at,.L0f11b754
/*  f11b734:	00001025 */ 	or	$v0,$zero,$zero
/*  f11b738:	8c490000 */ 	lw	$t1,0x0($v0)
/*  f11b73c:	24010002 */ 	addiu	$at,$zero,0x2
/*  f11b740:	55210004 */ 	bnel	$t1,$at,.L0f11b754
/*  f11b744:	00001025 */ 	or	$v0,$zero,$zero
/*  f11b748:	03e00008 */ 	jr	$ra
/*  f11b74c:	24020003 */ 	addiu	$v0,$zero,0x3
/*  f11b750:	00001025 */ 	or	$v0,$zero,$zero
.L0f11b754:
/*  f11b754:	03e00008 */ 	jr	$ra
/*  f11b758:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11b75c
/*  f11b75c:	27bdffa8 */ 	addiu	$sp,$sp,-88
/*  f11b760:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f11b764:	0004ae00 */ 	sll	$s5,$a0,0x18
/*  f11b768:	00157603 */ 	sra	$t6,$s5,0x18
/*  f11b76c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f11b770:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11b774:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11b778:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11b77c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11b780:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f11b784:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11b788:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11b78c:	3c18800a */ 	lui	$t8,%hi(var800a2380)
/*  f11b790:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f11b794:	27182380 */ 	addiu	$t8,$t8,%lo(var800a2380)
/*  f11b798:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11b79c:	01f8a021 */ 	addu	$s4,$t7,$t8
/*  f11b7a0:	8e9902a0 */ 	lw	$t9,0x2a0($s4)
/*  f11b7a4:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f11b7a8:	01c0a825 */ 	or	$s5,$t6,$zero
/*  f11b7ac:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f11b7b0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f11b7b4:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f11b7b8:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f11b7bc:	afa40058 */ 	sw	$a0,0x58($sp)
/*  f11b7c0:	afa5005c */ 	sw	$a1,0x5c($sp)
/*  f11b7c4:	1320001f */ 	beqz	$t9,.L0f11b844
/*  f11b7c8:	00008025 */ 	or	$s0,$zero,$zero
/*  f11b7cc:	24130004 */ 	addiu	$s3,$zero,0x4
/*  f11b7d0:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f11b7d4:	27b10048 */ 	addiu	$s1,$sp,0x48
/*  f11b7d8:	00152600 */ 	sll	$a0,$s5,0x18
.L0f11b7dc:
/*  f11b7dc:	00044603 */ 	sra	$t0,$a0,0x18
/*  f11b7e0:	01002025 */ 	or	$a0,$t0,$zero
/*  f11b7e4:	02002825 */ 	or	$a1,$s0,$zero
/*  f11b7e8:	0fc45d48 */ 	jal	func0f117520
/*  f11b7ec:	02203025 */ 	or	$a2,$s1,$zero
/*  f11b7f0:	8fa30050 */ 	lw	$v1,0x50($sp)
/*  f11b7f4:	30690fff */ 	andi	$t1,$v1,0xfff
/*  f11b7f8:	14520003 */ 	bne	$v0,$s2,.L0f11b808
/*  f11b7fc:	02098021 */ 	addu	$s0,$s0,$t1
/*  f11b800:	10000011 */ 	beqz	$zero,.L0f11b848
/*  f11b804:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11b808:
/*  f11b808:	000355c2 */ 	srl	$t2,$v1,0x17
/*  f11b80c:	15530005 */ 	bne	$t2,$s3,.L0f11b824
/*  f11b810:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11b814:	8fab005c */ 	lw	$t3,0x5c($sp)
/*  f11b818:	00001025 */ 	or	$v0,$zero,$zero
/*  f11b81c:	1000000a */ 	beqz	$zero,.L0f11b848
/*  f11b820:	ad700000 */ 	sw	$s0,0x0($t3)
.L0f11b824:
/*  f11b824:	50400004 */ 	beqzl	$v0,.L0f11b838
/*  f11b828:	8e8c02a0 */ 	lw	$t4,0x2a0($s4)
/*  f11b82c:	10000006 */ 	beqz	$zero,.L0f11b848
/*  f11b830:	00001025 */ 	or	$v0,$zero,$zero
/*  f11b834:	8e8c02a0 */ 	lw	$t4,0x2a0($s4)
.L0f11b838:
/*  f11b838:	020c082b */ 	sltu	$at,$s0,$t4
/*  f11b83c:	5420ffe7 */ 	bnezl	$at,.L0f11b7dc
/*  f11b840:	00152600 */ 	sll	$a0,$s5,0x18
.L0f11b844:
/*  f11b844:	00001025 */ 	or	$v0,$zero,$zero
.L0f11b848:
/*  f11b848:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f11b84c:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f11b850:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f11b854:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f11b858:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f11b85c:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f11b860:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f11b864:	03e00008 */ 	jr	$ra
/*  f11b868:	27bd0058 */ 	addiu	$sp,$sp,0x58
);

GLOBAL_ASM(
glabel func0f11b86c
/*  f11b86c:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f11b870:	afb2002c */ 	sw	$s2,0x2c($sp)
/*  f11b874:	8fb20140 */ 	lw	$s2,0x140($sp)
/*  f11b878:	afb10028 */ 	sw	$s1,0x28($sp)
/*  f11b87c:	00048e00 */ 	sll	$s1,$a0,0x18
/*  f11b880:	00117603 */ 	sra	$t6,$s1,0x18
/*  f11b884:	afb50038 */ 	sw	$s5,0x38($sp)
/*  f11b888:	afb30030 */ 	sw	$s3,0x30($sp)
/*  f11b88c:	2401ffff */ 	addiu	$at,$zero,-1
/*  f11b890:	00e09825 */ 	or	$s3,$a3,$zero
/*  f11b894:	00c0a825 */ 	or	$s5,$a2,$zero
/*  f11b898:	01c08825 */ 	or	$s1,$t6,$zero
/*  f11b89c:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f11b8a0:	afb40034 */ 	sw	$s4,0x34($sp)
/*  f11b8a4:	afb00024 */ 	sw	$s0,0x24($sp)
/*  f11b8a8:	afa40130 */ 	sw	$a0,0x130($sp)
/*  f11b8ac:	16410006 */ 	bne	$s2,$at,.L0f11b8c8
/*  f11b8b0:	afa50134 */ 	sw	$a1,0x134($sp)
/*  f11b8b4:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f11b8b8:	afaf0114 */ 	sw	$t7,0x114($sp)
/*  f11b8bc:	24140001 */ 	addiu	$s4,$zero,0x1
/*  f11b8c0:	10000003 */ 	beqz	$zero,.L0f11b8d0
/*  f11b8c4:	00009025 */ 	or	$s2,$zero,$zero
.L0f11b8c8:
/*  f11b8c8:	afa00114 */ 	sw	$zero,0x114($sp)
/*  f11b8cc:	0000a025 */ 	or	$s4,$zero,$zero
.L0f11b8d0:
/*  f11b8d0:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11b8d4:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f11b8d8:	0fc45974 */ 	jal	func0f1165d0
/*  f11b8dc:	03002025 */ 	or	$a0,$t8,$zero
/*  f11b8e0:	0012802b */ 	sltu	$s0,$zero,$s2
/*  f11b8e4:	12000008 */ 	beqz	$s0,.L0f11b908
/*  f11b8e8:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11b8ec:	0015802b */ 	sltu	$s0,$zero,$s5
/*  f11b8f0:	12000005 */ 	beqz	$s0,.L0f11b908
/*  f11b8f4:	26590010 */ 	addiu	$t9,$s2,0x10
/*  f11b8f8:	0059802b */ 	sltu	$s0,$v0,$t9
/*  f11b8fc:	3a100001 */ 	xori	$s0,$s0,0x1
/*  f11b900:	0010482b */ 	sltu	$t1,$zero,$s0
/*  f11b904:	01208025 */ 	or	$s0,$t1,$zero
.L0f11b908:
/*  f11b908:	16600002 */ 	bnez	$s3,.L0f11b914
/*  f11b90c:	00045603 */ 	sra	$t2,$a0,0x18
/*  f11b910:	27b30120 */ 	addiu	$s3,$sp,0x120
.L0f11b914:
/*  f11b914:	01402025 */ 	or	$a0,$t2,$zero
/*  f11b918:	8fa50134 */ 	lw	$a1,0x134($sp)
/*  f11b91c:	0fc45d48 */ 	jal	func0f117520
/*  f11b920:	02603025 */ 	or	$a2,$s3,$zero
/*  f11b924:	10400003 */ 	beqz	$v0,.L0f11b934
/*  f11b928:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11b92c:	100000a2 */ 	beqz	$zero,.L0f11bbb8
/*  f11b930:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f11b934:
/*  f11b934:	16800007 */ 	bnez	$s4,.L0f11b954
/*  f11b938:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11b93c:	8e6b000c */ 	lw	$t3,0xc($s3)
/*  f11b940:	000b6f40 */ 	sll	$t5,$t3,0x1d
/*  f11b944:	05a00003 */ 	bltz	$t5,.L0f11b954
/*  f11b948:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11b94c:	10000099 */ 	beqz	$zero,.L0f11bbb4
/*  f11b950:	2402000a */ 	addiu	$v0,$zero,0xa
.L0f11b954:
/*  f11b954:	12000014 */ 	beqz	$s0,.L0f11b9a8
/*  f11b958:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11b95c:	00047603 */ 	sra	$t6,$a0,0x18
/*  f11b960:	01c02025 */ 	or	$a0,$t6,$zero
/*  f11b964:	8fa50134 */ 	lw	$a1,0x134($sp)
/*  f11b968:	0fc45d0c */ 	jal	func0f117430
/*  f11b96c:	27a600e0 */ 	addiu	$a2,$sp,0xe0
/*  f11b970:	5040000e */ 	beqzl	$v0,.L0f11b9ac
/*  f11b974:	8e650008 */ 	lw	$a1,0x8($s3)
/*  f11b978:	12400009 */ 	beqz	$s2,.L0f11b9a0
/*  f11b97c:	00008025 */ 	or	$s0,$zero,$zero
/*  f11b980:	02a01025 */ 	or	$v0,$s5,$zero
/*  f11b984:	27a300e0 */ 	addiu	$v1,$sp,0xe0
.L0f11b988:
/*  f11b988:	906f0010 */ 	lbu	$t7,0x10($v1)
/*  f11b98c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11b990:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11b994:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f11b998:	1612fffb */ 	bne	$s0,$s2,.L0f11b988
/*  f11b99c:	a04fffff */ 	sb	$t7,-0x1($v0)
.L0f11b9a0:
/*  f11b9a0:	10000084 */ 	beqz	$zero,.L0f11bbb4
/*  f11b9a4:	00001025 */ 	or	$v0,$zero,$zero
.L0f11b9a8:
/*  f11b9a8:	8e650008 */ 	lw	$a1,0x8($s3)
.L0f11b9ac:
/*  f11b9ac:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11b9b0:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f11b9b4:	0005c240 */ 	sll	$t8,$a1,0x9
/*  f11b9b8:	00182d42 */ 	srl	$a1,$t8,0x15
/*  f11b9bc:	16450002 */ 	bne	$s2,$a1,.L0f11b9c8
/*  f11b9c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11b9c4:	00009025 */ 	or	$s2,$zero,$zero
.L0f11b9c8:
/*  f11b9c8:	0fc45996 */ 	jal	func0f116658
/*  f11b9cc:	01202025 */ 	or	$a0,$t1,$zero
/*  f11b9d0:	16400005 */ 	bnez	$s2,.L0f11b9e8
/*  f11b9d4:	8fac0114 */ 	lw	$t4,0x114($sp)
/*  f11b9d8:	8e700008 */ 	lw	$s0,0x8($s3)
/*  f11b9dc:	00105240 */ 	sll	$t2,$s0,0x9
/*  f11b9e0:	10000002 */ 	beqz	$zero,.L0f11b9ec
/*  f11b9e4:	000a8542 */ 	srl	$s0,$t2,0x15
.L0f11b9e8:
/*  f11b9e8:	02408025 */ 	or	$s0,$s2,$zero
.L0f11b9ec:
/*  f11b9ec:	11800002 */ 	beqz	$t4,.L0f11b9f8
/*  f11b9f0:	26030010 */ 	addiu	$v1,$s0,0x10
/*  f11b9f4:	00401825 */ 	or	$v1,$v0,$zero
.L0f11b9f8:
/*  f11b9f8:	0c00543a */ 	jal	func000150e8
/*  f11b9fc:	afa30104 */ 	sw	$v1,0x104($sp)
/*  f11ba00:	8fad0104 */ 	lw	$t5,0x104($sp)
/*  f11ba04:	00008025 */ 	or	$s0,$zero,$zero
/*  f11ba08:	27b40058 */ 	addiu	$s4,$sp,0x58
/*  f11ba0c:	11a00066 */ 	beqz	$t5,.L0f11bba8
/*  f11ba10:	00112600 */ 	sll	$a0,$s1,0x18
.L0f11ba14:
/*  f11ba14:	00047603 */ 	sra	$t6,$a0,0x18
/*  f11ba18:	0fc45974 */ 	jal	func0f1165d0
/*  f11ba1c:	01c02025 */ 	or	$a0,$t6,$zero
/*  f11ba20:	0202001b */ 	divu	$zero,$s0,$v0
/*  f11ba24:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11ba28:	00009010 */ 	mfhi	$s2
/*  f11ba2c:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f11ba30:	14400002 */ 	bnez	$v0,.L0f11ba3c
/*  f11ba34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ba38:	0007000d */ 	break	0x7
.L0f11ba3c:
/*  f11ba3c:	01e02025 */ 	or	$a0,$t7,$zero
/*  f11ba40:	0fc45974 */ 	jal	func0f1165d0
/*  f11ba44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ba48:	0202001b */ 	divu	$zero,$s0,$v0
/*  f11ba4c:	00001812 */ 	mflo	$v1
/*  f11ba50:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11ba54:	14400002 */ 	bnez	$v0,.L0f11ba60
/*  f11ba58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ba5c:	0007000d */ 	break	0x7
.L0f11ba60:
/*  f11ba60:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f11ba64:	16400044 */ 	bnez	$s2,.L0f11bb78
/*  f11ba68:	0011c880 */ 	sll	$t9,$s1,0x2
/*  f11ba6c:	0331c823 */ 	subu	$t9,$t9,$s1
/*  f11ba70:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11ba74:	0331c823 */ 	subu	$t9,$t9,$s1
/*  f11ba78:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11ba7c:	0331c821 */ 	addu	$t9,$t9,$s1
/*  f11ba80:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11ba84:	0331c823 */ 	subu	$t9,$t9,$s1
/*  f11ba88:	3c09800a */ 	lui	$t1,%hi(var800a2380)
/*  f11ba8c:	25292380 */ 	addiu	$t1,$t1,%lo(var800a2380)
/*  f11ba90:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11ba94:	03299821 */ 	addu	$s3,$t9,$t1
/*  f11ba98:	03002025 */ 	or	$a0,$t8,$zero
/*  f11ba9c:	0fc45974 */ 	jal	func0f1165d0
/*  f11baa0:	afa300d8 */ 	sw	$v1,0xd8($sp)
/*  f11baa4:	8fa300d8 */ 	lw	$v1,0xd8($sp)
/*  f11baa8:	00116080 */ 	sll	$t4,$s1,0x2
/*  f11baac:	01916023 */ 	subu	$t4,$t4,$s1
/*  f11bab0:	00430019 */ 	multu	$v0,$v1
/*  f11bab4:	8fab0134 */ 	lw	$t3,0x134($sp)
/*  f11bab8:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f11babc:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11bac0:	00047603 */ 	sra	$t6,$a0,0x18
/*  f11bac4:	01916021 */ 	addu	$t4,$t4,$s1
/*  f11bac8:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11bacc:	3c0d800a */ 	lui	$t5,%hi(var800a3180)
/*  f11bad0:	25ad3180 */ 	addiu	$t5,$t5,%lo(var800a3180)
/*  f11bad4:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f11bad8:	00005012 */ 	mflo	$t2
/*  f11badc:	01c02025 */ 	or	$a0,$t6,$zero
/*  f11bae0:	16210003 */ 	bne	$s1,$at,.L0f11baf0
/*  f11bae4:	014b4021 */ 	addu	$t0,$t2,$t3
/*  f11bae8:	10000002 */ 	beqz	$zero,.L0f11baf4
/*  f11baec:	00002825 */ 	or	$a1,$zero,$zero
.L0f11baf0:
/*  f11baf0:	018d2821 */ 	addu	$a1,$t4,$t5
.L0f11baf4:
/*  f11baf4:	afa50048 */ 	sw	$a1,0x48($sp)
/*  f11baf8:	0fc45974 */ 	jal	func0f1165d0
/*  f11bafc:	afa80054 */ 	sw	$t0,0x54($sp)
/*  f11bb00:	8fa80054 */ 	lw	$t0,0x54($sp)
/*  f11bb04:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11bb08:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f11bb0c:	01e02025 */ 	or	$a0,$t7,$zero
/*  f11bb10:	8fa50048 */ 	lw	$a1,0x48($sp)
/*  f11bb14:	8e66029c */ 	lw	$a2,0x29c($s3)
/*  f11bb18:	00003825 */ 	or	$a3,$zero,$zero
/*  f11bb1c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f11bb20:	afb40018 */ 	sw	$s4,0x18($sp)
/*  f11bb24:	0fc46941 */ 	jal	func0f11a504
/*  f11bb28:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f11bb2c:	00112e00 */ 	sll	$a1,$s1,0x18
/*  f11bb30:	0005c603 */ 	sra	$t8,$a1,0x18
/*  f11bb34:	00409825 */ 	or	$s3,$v0,$zero
/*  f11bb38:	03002825 */ 	or	$a1,$t8,$zero
/*  f11bb3c:	00402025 */ 	or	$a0,$v0,$zero
/*  f11bb40:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f11bb44:	0fc470e7 */ 	jal	func0f11c39c
/*  f11bb48:	2407112a */ 	addiu	$a3,$zero,0x112a
/*  f11bb4c:	5440000b */ 	bnezl	$v0,.L0f11bb7c
/*  f11bb50:	2e010010 */ 	sltiu	$at,$s0,0x10
/*  f11bb54:	0c005451 */ 	jal	func00015144
/*  f11bb58:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11bb5c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f11bb60:	16610003 */ 	bne	$s3,$at,.L0f11bb70
/*  f11bb64:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11bb68:	10000012 */ 	beqz	$zero,.L0f11bbb4
/*  f11bb6c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11bb70:
/*  f11bb70:	10000010 */ 	beqz	$zero,.L0f11bbb4
/*  f11bb74:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f11bb78:
/*  f11bb78:	2e010010 */ 	sltiu	$at,$s0,0x10
.L0f11bb7c:
/*  f11bb7c:	54200007 */ 	bnezl	$at,.L0f11bb9c
/*  f11bb80:	8faa0104 */ 	lw	$t2,0x104($sp)
/*  f11bb84:	12a00004 */ 	beqz	$s5,.L0f11bb98
/*  f11bb88:	0292c821 */ 	addu	$t9,$s4,$s2
/*  f11bb8c:	93290000 */ 	lbu	$t1,0x0($t9)
/*  f11bb90:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f11bb94:	a2a9ffff */ 	sb	$t1,-0x1($s5)
.L0f11bb98:
/*  f11bb98:	8faa0104 */ 	lw	$t2,0x104($sp)
.L0f11bb9c:
/*  f11bb9c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11bba0:	560aff9c */ 	bnel	$s0,$t2,.L0f11ba14
/*  f11bba4:	00112600 */ 	sll	$a0,$s1,0x18
.L0f11bba8:
/*  f11bba8:	0c005451 */ 	jal	func00015144
/*  f11bbac:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11bbb0:	00001025 */ 	or	$v0,$zero,$zero
.L0f11bbb4:
/*  f11bbb4:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f11bbb8:
/*  f11bbb8:	8fb00024 */ 	lw	$s0,0x24($sp)
/*  f11bbbc:	8fb10028 */ 	lw	$s1,0x28($sp)
/*  f11bbc0:	8fb2002c */ 	lw	$s2,0x2c($sp)
/*  f11bbc4:	8fb30030 */ 	lw	$s3,0x30($sp)
/*  f11bbc8:	8fb40034 */ 	lw	$s4,0x34($sp)
/*  f11bbcc:	8fb50038 */ 	lw	$s5,0x38($sp)
/*  f11bbd0:	03e00008 */ 	jr	$ra
/*  f11bbd4:	27bd0130 */ 	addiu	$sp,$sp,0x130
);

GLOBAL_ASM(
glabel func0f11bbd8
/*  f11bbd8:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f11bbdc:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f11bbe0:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f11bbe4:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f11bbe8:	83a4004b */ 	lb	$a0,0x4b($sp)
/*  f11bbec:	0fc45d48 */ 	jal	func0f117520
/*  f11bbf0:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f11bbf4:	14400012 */ 	bnez	$v0,.L0f11bc40
/*  f11bbf8:	83a4004b */ 	lb	$a0,0x4b($sp)
/*  f11bbfc:	8fae0040 */ 	lw	$t6,0x40($sp)
/*  f11bc00:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f11bc04:	afb90020 */ 	sw	$t9,0x20($sp)
/*  f11bc08:	31cf0fff */ 	andi	$t7,$t6,0xfff
/*  f11bc0c:	25f8fff0 */ 	addiu	$t8,$t7,-16
/*  f11bc10:	afb80010 */ 	sw	$t8,0x10($sp)
/*  f11bc14:	8fa5004c */ 	lw	$a1,0x4c($sp)
/*  f11bc18:	24060002 */ 	addiu	$a2,$zero,0x2
/*  f11bc1c:	00003825 */ 	or	$a3,$zero,$zero
/*  f11bc20:	afa00014 */ 	sw	$zero,0x14($sp)
/*  f11bc24:	afa00018 */ 	sw	$zero,0x18($sp)
/*  f11bc28:	0fc46f15 */ 	jal	func0f11bc54
/*  f11bc2c:	afa0001c */ 	sw	$zero,0x1c($sp)
/*  f11bc30:	54400004 */ 	bnezl	$v0,.L0f11bc44
/*  f11bc34:	00001025 */ 	or	$v0,$zero,$zero
/*  f11bc38:	10000002 */ 	beqz	$zero,.L0f11bc44
/*  f11bc3c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11bc40:
/*  f11bc40:	00001025 */ 	or	$v0,$zero,$zero
.L0f11bc44:
/*  f11bc44:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f11bc48:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f11bc4c:	03e00008 */ 	jr	$ra
/*  f11bc50:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11bc54
/*  f11bc54:	27bddf40 */ 	addiu	$sp,$sp,-8384
/*  f11bc58:	afb70044 */ 	sw	$s7,0x44($sp)
/*  f11bc5c:	0004be00 */ 	sll	$s7,$a0,0x18
/*  f11bc60:	00177603 */ 	sra	$t6,$s7,0x18
/*  f11bc64:	afa420c0 */ 	sw	$a0,0x20c0($sp)
/*  f11bc68:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f11bc6c:	afbf004c */ 	sw	$ra,0x4c($sp)
/*  f11bc70:	afb40038 */ 	sw	$s4,0x38($sp)
/*  f11bc74:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f11bc78:	00c0a025 */ 	or	$s4,$a2,$zero
/*  f11bc7c:	01c0b825 */ 	or	$s7,$t6,$zero
/*  f11bc80:	afbe0048 */ 	sw	$s8,0x48($sp)
/*  f11bc84:	afb60040 */ 	sw	$s6,0x40($sp)
/*  f11bc88:	afb5003c */ 	sw	$s5,0x3c($sp)
/*  f11bc8c:	afb30034 */ 	sw	$s3,0x34($sp)
/*  f11bc90:	afb20030 */ 	sw	$s2,0x30($sp)
/*  f11bc94:	afb1002c */ 	sw	$s1,0x2c($sp)
/*  f11bc98:	afb00028 */ 	sw	$s0,0x28($sp)
/*  f11bc9c:	afa520c4 */ 	sw	$a1,0x20c4($sp)
/*  f11bca0:	afa720cc */ 	sw	$a3,0x20cc($sp)
/*  f11bca4:	0fc45974 */ 	jal	func0f1165d0
/*  f11bca8:	01e02025 */ 	or	$a0,$t7,$zero
/*  f11bcac:	8fb220e0 */ 	lw	$s2,0x20e0($sp)
/*  f11bcb0:	8fa320d0 */ 	lw	$v1,0x20d0($sp)
/*  f11bcb4:	00409825 */ 	or	$s3,$v0,$zero
/*  f11bcb8:	325801ff */ 	andi	$t8,$s2,0x1ff
/*  f11bcbc:	10600003 */ 	beqz	$v1,.L0f11bccc
/*  f11bcc0:	03009025 */ 	or	$s2,$t8,$zero
/*  f11bcc4:	10000007 */ 	beqz	$zero,.L0f11bce4
/*  f11bcc8:	00608825 */ 	or	$s1,$v1,$zero
.L0f11bccc:
/*  f11bccc:	00172600 */ 	sll	$a0,$s7,0x18
/*  f11bcd0:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f11bcd4:	03202025 */ 	or	$a0,$t9,$zero
/*  f11bcd8:	0fc45c25 */ 	jal	func0f117094
/*  f11bcdc:	02802825 */ 	or	$a1,$s4,$zero
/*  f11bce0:	00408825 */ 	or	$s1,$v0,$zero
.L0f11bce4:
/*  f11bce4:	00172600 */ 	sll	$a0,$s7,0x18
/*  f11bce8:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f11bcec:	01202025 */ 	or	$a0,$t1,$zero
/*  f11bcf0:	0fc45996 */ 	jal	func0f116658
/*  f11bcf4:	02202825 */ 	or	$a1,$s1,$zero
/*  f11bcf8:	8fa320dc */ 	lw	$v1,0x20dc($sp)
/*  f11bcfc:	0040b025 */ 	or	$s6,$v0,$zero
/*  f11bd00:	27b020b0 */ 	addiu	$s0,$sp,0x20b0
/*  f11bd04:	10600015 */ 	beqz	$v1,.L0f11bd5c
/*  f11bd08:	00177880 */ 	sll	$t7,$s7,0x2
/*  f11bd0c:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f11bd10:	01f77823 */ 	subu	$t7,$t7,$s7
/*  f11bd14:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11bd18:	01f77823 */ 	subu	$t7,$t7,$s7
/*  f11bd1c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11bd20:	00025302 */ 	srl	$t2,$v0,0xc
/*  f11bd24:	006a5826 */ 	xor	$t3,$v1,$t2
/*  f11bd28:	01f77821 */ 	addu	$t7,$t7,$s7
/*  f11bd2c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11bd30:	000b6640 */ 	sll	$t4,$t3,0x19
/*  f11bd34:	000c6b42 */ 	srl	$t5,$t4,0xd
/*  f11bd38:	01f77823 */ 	subu	$t7,$t7,$s7
/*  f11bd3c:	3c18800a */ 	lui	$t8,%hi(var800a2380)
/*  f11bd40:	27182380 */ 	addiu	$t8,$t8,%lo(var800a2380)
/*  f11bd44:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11bd48:	01a27026 */ 	xor	$t6,$t5,$v0
/*  f11bd4c:	ae0e000c */ 	sw	$t6,0xc($s0)
/*  f11bd50:	01f8c821 */ 	addu	$t9,$t7,$t8
/*  f11bd54:	10000019 */ 	beqz	$zero,.L0f11bdbc
/*  f11bd58:	afb90058 */ 	sw	$t9,0x58($sp)
.L0f11bd5c:
/*  f11bd5c:	00174880 */ 	sll	$t1,$s7,0x2
/*  f11bd60:	01374823 */ 	subu	$t1,$t1,$s7
/*  f11bd64:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11bd68:	01374823 */ 	subu	$t1,$t1,$s7
/*  f11bd6c:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11bd70:	01374821 */ 	addu	$t1,$t1,$s7
/*  f11bd74:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11bd78:	01374823 */ 	subu	$t1,$t1,$s7
/*  f11bd7c:	3c0a800a */ 	lui	$t2,%hi(var800a2380)
/*  f11bd80:	254a2380 */ 	addiu	$t2,$t2,%lo(var800a2380)
/*  f11bd84:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11bd88:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f11bd8c:	8c4b025c */ 	lw	$t3,0x25c($v0)
/*  f11bd90:	8fa320bc */ 	lw	$v1,0x20bc($sp)
/*  f11bd94:	afa20058 */ 	sw	$v0,0x58($sp)
/*  f11bd98:	256c0001 */ 	addiu	$t4,$t3,0x1
/*  f11bd9c:	00037302 */ 	srl	$t6,$v1,0xc
/*  f11bda0:	018e7826 */ 	xor	$t7,$t4,$t6
/*  f11bda4:	000fc640 */ 	sll	$t8,$t7,0x19
/*  f11bda8:	0018cb42 */ 	srl	$t9,$t8,0xd
/*  f11bdac:	03231826 */ 	xor	$v1,$t9,$v1
/*  f11bdb0:	afa320bc */ 	sw	$v1,0x20bc($sp)
/*  f11bdb4:	ac4c025c */ 	sw	$t4,0x25c($v0)
/*  f11bdb8:	27b020b0 */ 	addiu	$s0,$sp,0x20b0
.L0f11bdbc:
/*  f11bdbc:	8fa90058 */ 	lw	$t1,0x58($sp)
/*  f11bdc0:	960e000c */ 	lhu	$t6,0xc($s0)
/*  f11bdc4:	960a000a */ 	lhu	$t2,0xa($s0)
/*  f11bdc8:	8d2b0260 */ 	lw	$t3,0x260($t1)
/*  f11bdcc:	32c90fff */ 	andi	$t1,$s6,0xfff
/*  f11bdd0:	31cf0007 */ 	andi	$t7,$t6,0x7
/*  f11bdd4:	000b68c0 */ 	sll	$t5,$t3,0x3
/*  f11bdd8:	314bf000 */ 	andi	$t3,$t2,0xf000
/*  f11bddc:	01afc025 */ 	or	$t8,$t5,$t7
/*  f11bde0:	012b6025 */ 	or	$t4,$t1,$t3
/*  f11bde4:	3c057f1b */ 	lui	$a1,%hi(var7f1b45e4)
/*  f11bde8:	a618000c */ 	sh	$t8,0xc($s0)
/*  f11bdec:	a60c000a */ 	sh	$t4,0xa($s0)
/*  f11bdf0:	24a545e4 */ 	addiu	$a1,$a1,%lo(var7f1b45e4)
/*  f11bdf4:	0c004c04 */ 	jal	func00013010
/*  f11bdf8:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f11bdfc:	10400003 */ 	beqz	$v0,.L0f11be0c
/*  f11be00:	8fa420d4 */ 	lw	$a0,0x20d4($sp)
/*  f11be04:	10000002 */ 	beqz	$zero,.L0f11be10
/*  f11be08:	24030001 */ 	addiu	$v1,$zero,0x1
.L0f11be0c:
/*  f11be0c:	00001825 */ 	or	$v1,$zero,$zero
.L0f11be10:
/*  f11be10:	920f000f */ 	lbu	$t7,0xf($s0)
/*  f11be14:	00607025 */ 	or	$t6,$v1,$zero
/*  f11be18:	31cd0001 */ 	andi	$t5,$t6,0x1
/*  f11be1c:	31f8fffe */ 	andi	$t8,$t7,0xfffe
/*  f11be20:	01b8c825 */ 	or	$t9,$t5,$t8
/*  f11be24:	a219000f */ 	sb	$t9,0xf($s0)
/*  f11be28:	8fa920b8 */ 	lw	$t1,0x20b8($sp)
/*  f11be2c:	0012c8c0 */ 	sll	$t9,$s2,0x3
/*  f11be30:	332a0ff8 */ 	andi	$t2,$t9,0xff8
/*  f11be34:	00095b02 */ 	srl	$t3,$t1,0xc
/*  f11be38:	022b6026 */ 	xor	$t4,$s1,$t3
/*  f11be3c:	000c7540 */ 	sll	$t6,$t4,0x15
/*  f11be40:	000e7a42 */ 	srl	$t7,$t6,0x9
/*  f11be44:	01e96826 */ 	xor	$t5,$t7,$t1
/*  f11be48:	afad20b8 */ 	sw	$t5,0x20b8($sp)
/*  f11be4c:	960b000e */ 	lhu	$t3,0xe($s0)
/*  f11be50:	96180008 */ 	lhu	$t8,0x8($s0)
/*  f11be54:	02807825 */ 	or	$t7,$s4,$zero
/*  f11be58:	316cf007 */ 	andi	$t4,$t3,0xf007
/*  f11be5c:	014c7025 */ 	or	$t6,$t2,$t4
/*  f11be60:	a60e000e */ 	sh	$t6,0xe($s0)
/*  f11be64:	8e02000c */ 	lw	$v0,0xc($s0)
/*  f11be68:	000f69c0 */ 	sll	$t5,$t7,0x7
/*  f11be6c:	3319007f */ 	andi	$t9,$t8,0x7f
/*  f11be70:	00025340 */ 	sll	$t2,$v0,0xd
/*  f11be74:	000a6642 */ 	srl	$t4,$t2,0x19
/*  f11be78:	318e007f */ 	andi	$t6,$t4,0x7f
/*  f11be7c:	00027b02 */ 	srl	$t7,$v0,0xc
/*  f11be80:	01cf4826 */ 	xor	$t1,$t6,$t7
/*  f11be84:	01b95825 */ 	or	$t3,$t5,$t9
/*  f11be88:	0009c640 */ 	sll	$t8,$t1,0x19
/*  f11be8c:	00186b42 */ 	srl	$t5,$t8,0xd
/*  f11be90:	01a2c826 */ 	xor	$t9,$t5,$v0
/*  f11be94:	a60b0008 */ 	sh	$t3,0x8($s0)
/*  f11be98:	10800004 */ 	beqz	$a0,.L0f11beac
/*  f11be9c:	ae19000c */ 	sw	$t9,0xc($s0)
/*  f11bea0:	00195340 */ 	sll	$t2,$t9,0xd
/*  f11bea4:	000a6642 */ 	srl	$t4,$t2,0x19
/*  f11bea8:	ac8c0000 */ 	sw	$t4,0x0($a0)
.L0f11beac:
/*  f11beac:	8fa720cc */ 	lw	$a3,0x20cc($sp)
/*  f11beb0:	50e00007 */ 	beqzl	$a3,.L0f11bed0
/*  f11beb4:	9218000f */ 	lbu	$t8,0xf($s0)
/*  f11beb8:	920e000f */ 	lbu	$t6,0xf($s0)
/*  f11bebc:	31cffffb */ 	andi	$t7,$t6,0xfffb
/*  f11bec0:	35e90004 */ 	ori	$t1,$t7,0x4
/*  f11bec4:	10000004 */ 	beqz	$zero,.L0f11bed8
/*  f11bec8:	a209000f */ 	sb	$t1,0xf($s0)
/*  f11becc:	9218000f */ 	lbu	$t8,0xf($s0)
.L0f11bed0:
/*  f11bed0:	330dfffb */ 	andi	$t5,$t8,0xfffb
/*  f11bed4:	a20d000f */ 	sb	$t5,0xf($s0)
.L0f11bed8:
/*  f11bed8:	8e19000c */ 	lw	$t9,0xc($s0)
/*  f11bedc:	3409ffff */ 	dli	$t1,0xffff
/*  f11bee0:	3418ffff */ 	dli	$t8,0xffff
/*  f11bee4:	00195f40 */ 	sll	$t3,$t9,0x1d
/*  f11bee8:	000b57c2 */ 	srl	$t2,$t3,0x1f
/*  f11beec:	5140000b */ 	beqzl	$t2,.L0f11bf1c
/*  f11bef0:	a7a920b4 */ 	sh	$t1,0x20b4($sp)
/*  f11bef4:	8fac20b8 */ 	lw	$t4,0x20b8($sp)
/*  f11bef8:	00e02025 */ 	or	$a0,$a3,$zero
/*  f11befc:	27a620b4 */ 	addiu	$a2,$sp,0x20b4
/*  f11bf00:	000c7240 */ 	sll	$t6,$t4,0x9
/*  f11bf04:	000e7d42 */ 	srl	$t7,$t6,0x15
/*  f11bf08:	0fc462b9 */ 	jal	func0f118ae4
/*  f11bf0c:	01e72821 */ 	addu	$a1,$t7,$a3
/*  f11bf10:	10000003 */ 	beqz	$zero,.L0f11bf20
/*  f11bf14:	8fa720cc */ 	lw	$a3,0x20cc($sp)
/*  f11bf18:	a7a920b4 */ 	sh	$t1,0x20b4($sp)
.L0f11bf1c:
/*  f11bf1c:	a7b820b6 */ 	sh	$t8,0x20b6($sp)
.L0f11bf20:
/*  f11bf20:	02d14023 */ 	subu	$t0,$s6,$s1
/*  f11bf24:	27b2109c */ 	addiu	$s2,$sp,0x109c
/*  f11bf28:	27b4009c */ 	addiu	$s4,$sp,0x9c
/*  f11bf2c:	2508fff0 */ 	addiu	$t0,$t0,-16
/*  f11bf30:	01003025 */ 	or	$a2,$t0,$zero
/*  f11bf34:	02401025 */ 	or	$v0,$s2,$zero
/*  f11bf38:	02801825 */ 	or	$v1,$s4,$zero
/*  f11bf3c:	0000a825 */ 	or	$s5,$zero,$zero
/*  f11bf40:	2404002b */ 	addiu	$a0,$zero,0x2b
.L0f11bf44:
/*  f11bf44:	02156821 */ 	addu	$t5,$s0,$s5
/*  f11bf48:	91b90000 */ 	lbu	$t9,0x0($t5)
/*  f11bf4c:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f11bf50:	2ea10010 */ 	sltiu	$at,$s5,0x10
/*  f11bf54:	a0590000 */ 	sb	$t9,0x0($v0)
/*  f11bf58:	a0640000 */ 	sb	$a0,0x0($v1)
/*  f11bf5c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11bf60:	1420fff8 */ 	bnez	$at,.L0f11bf44
/*  f11bf64:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f11bf68:	12200014 */ 	beqz	$s1,.L0f11bfbc
/*  f11bf6c:	0000a825 */ 	or	$s5,$zero,$zero
/*  f11bf70:	8fa520d8 */ 	lw	$a1,0x20d8($sp)
.L0f11bf74:
/*  f11bf74:	50e00006 */ 	beqzl	$a3,.L0f11bf90
/*  f11bf78:	a0440000 */ 	sb	$a0,0x0($v0)
/*  f11bf7c:	00f55821 */ 	addu	$t3,$a3,$s5
/*  f11bf80:	916a0000 */ 	lbu	$t2,0x0($t3)
/*  f11bf84:	10000002 */ 	beqz	$zero,.L0f11bf90
/*  f11bf88:	a04a0000 */ 	sb	$t2,0x0($v0)
/*  f11bf8c:	a0440000 */ 	sb	$a0,0x0($v0)
.L0f11bf90:
/*  f11bf90:	10a00005 */ 	beqz	$a1,.L0f11bfa8
/*  f11bf94:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11bf98:	00b56021 */ 	addu	$t4,$a1,$s5
/*  f11bf9c:	918e0000 */ 	lbu	$t6,0x0($t4)
/*  f11bfa0:	10000002 */ 	beqz	$zero,.L0f11bfac
/*  f11bfa4:	a06e0000 */ 	sb	$t6,0x0($v1)
.L0f11bfa8:
/*  f11bfa8:	a0640000 */ 	sb	$a0,0x0($v1)
.L0f11bfac:
/*  f11bfac:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f11bfb0:	16b1fff0 */ 	bne	$s5,$s1,.L0f11bf74
/*  f11bfb4:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f11bfb8:	0000a825 */ 	or	$s5,$zero,$zero
.L0f11bfbc:
/*  f11bfbc:	11000012 */ 	beqz	$t0,.L0f11c008
/*  f11bfc0:	8fa520d8 */ 	lw	$a1,0x20d8($sp)
.L0f11bfc4:
/*  f11bfc4:	50e00006 */ 	beqzl	$a3,.L0f11bfe0
/*  f11bfc8:	a0440000 */ 	sb	$a0,0x0($v0)
/*  f11bfcc:	00f57821 */ 	addu	$t7,$a3,$s5
/*  f11bfd0:	91e90000 */ 	lbu	$t1,0x0($t7)
/*  f11bfd4:	10000002 */ 	beqz	$zero,.L0f11bfe0
/*  f11bfd8:	a0490000 */ 	sb	$t1,0x0($v0)
/*  f11bfdc:	a0440000 */ 	sb	$a0,0x0($v0)
.L0f11bfe0:
/*  f11bfe0:	10a00005 */ 	beqz	$a1,.L0f11bff8
/*  f11bfe4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11bfe8:	00b5c021 */ 	addu	$t8,$a1,$s5
/*  f11bfec:	930d0000 */ 	lbu	$t5,0x0($t8)
/*  f11bff0:	10000002 */ 	beqz	$zero,.L0f11bffc
/*  f11bff4:	a06d0000 */ 	sb	$t5,0x0($v1)
.L0f11bff8:
/*  f11bff8:	a0640000 */ 	sb	$a0,0x0($v1)
.L0f11bffc:
/*  f11bffc:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f11c000:	16a6fff0 */ 	bne	$s5,$a2,.L0f11bfc4
/*  f11c004:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f11c008:
/*  f11c008:	02d3001b */ 	divu	$zero,$s6,$s3
/*  f11c00c:	00001012 */ 	mflo	$v0
/*  f11c010:	0000c810 */ 	mfhi	$t9
/*  f11c014:	00401825 */ 	or	$v1,$v0,$zero
/*  f11c018:	16600002 */ 	bnez	$s3,.L0f11c024
/*  f11c01c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c020:	0007000d */ 	break	0x7
.L0f11c024:
/*  f11c024:	13200002 */ 	beqz	$t9,.L0f11c030
/*  f11c028:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c02c:	24430001 */ 	addiu	$v1,$v0,0x1
.L0f11c030:
/*  f11c030:	0c00543a */ 	jal	func000150e8
/*  f11c034:	afa30098 */ 	sw	$v1,0x98($sp)
/*  f11c038:	0000f025 */ 	or	$s8,$zero,$zero
.L0f11c03c:
/*  f11c03c:	13c00005 */ 	beqz	$s8,.L0f11c054
/*  f11c040:	0000a825 */ 	or	$s5,$zero,$zero
/*  f11c044:	93aa10ab */ 	lbu	$t2,0x10ab($sp)
/*  f11c048:	354c0002 */ 	ori	$t4,$t2,0x2
/*  f11c04c:	10000004 */ 	beqz	$zero,.L0f11c060
/*  f11c050:	a3ac10ab */ 	sb	$t4,0x10ab($sp)
.L0f11c054:
/*  f11c054:	93ae10ab */ 	lbu	$t6,0x10ab($sp)
/*  f11c058:	31cffffd */ 	andi	$t7,$t6,0xfffd
/*  f11c05c:	a3af10ab */ 	sb	$t7,0x10ab($sp)
.L0f11c060:
/*  f11c060:	27a410a4 */ 	addiu	$a0,$sp,0x10a4
/*  f11c064:	27a510ac */ 	addiu	$a1,$sp,0x10ac
/*  f11c068:	0fc462b9 */ 	jal	func0f118ae4
/*  f11c06c:	02403025 */ 	or	$a2,$s2,$zero
/*  f11c070:	8fa90098 */ 	lw	$t1,0x98($sp)
/*  f11c074:	11200066 */ 	beqz	$t1,.L0f11c210
/*  f11c078:	00172600 */ 	sll	$a0,$s7,0x18
.L0f11c07c:
/*  f11c07c:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f11c080:	03002025 */ 	or	$a0,$t8,$zero
/*  f11c084:	0fc45974 */ 	jal	func0f1165d0
/*  f11c088:	00008025 */ 	or	$s0,$zero,$zero
/*  f11c08c:	00550019 */ 	multu	$v0,$s5
/*  f11c090:	8fad10a4 */ 	lw	$t5,0x10a4($sp)
/*  f11c094:	8fab20cc */ 	lw	$t3,0x20cc($sp)
/*  f11c098:	000dcdc2 */ 	srl	$t9,$t5,0x17
/*  f11c09c:	0000b012 */ 	mflo	$s6
/*  f11c0a0:	2ec10010 */ 	sltiu	$at,$s6,0x10
/*  f11c0a4:	50200004 */ 	beqzl	$at,.L0f11c0b8
/*  f11c0a8:	24010001 */ 	addiu	$at,$zero,0x1
/*  f11c0ac:	10000020 */ 	beqz	$zero,.L0f11c130
/*  f11c0b0:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f11c0b4:	24010001 */ 	addiu	$at,$zero,0x1
.L0f11c0b8:
/*  f11c0b8:	13c10055 */ 	beq	$s8,$at,.L0f11c210
/*  f11c0bc:	8faa20d8 */ 	lw	$t2,0x20d8($sp)
/*  f11c0c0:	24010002 */ 	addiu	$at,$zero,0x2
/*  f11c0c4:	53210053 */ 	beql	$t9,$at,.L0f11c214
/*  f11c0c8:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f11c0cc:	51600051 */ 	beqzl	$t3,.L0f11c214
/*  f11c0d0:	27de0001 */ 	addiu	$s8,$s8,0x1
/*  f11c0d4:	51400016 */ 	beqzl	$t2,.L0f11c130
/*  f11c0d8:	24100001 */ 	addiu	$s0,$zero,0x1
/*  f11c0dc:	12600014 */ 	beqz	$s3,.L0f11c130
/*  f11c0e0:	00001825 */ 	or	$v1,$zero,$zero
/*  f11c0e4:	02b30019 */ 	multu	$s5,$s3
/*  f11c0e8:	00002012 */ 	mflo	$a0
/*  f11c0ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c0f0:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11c0f4:
/*  f11c0f4:	02446021 */ 	addu	$t4,$s2,$a0
/*  f11c0f8:	02847821 */ 	addu	$t7,$s4,$a0
/*  f11c0fc:	91e90000 */ 	lbu	$t1,0x0($t7)
/*  f11c100:	918e0000 */ 	lbu	$t6,0x0($t4)
/*  f11c104:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f11c108:	0073082b */ 	sltu	$at,$v1,$s3
/*  f11c10c:	11c90003 */ 	beq	$t6,$t1,.L0f11c11c
/*  f11c110:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c114:	10000006 */ 	beqz	$zero,.L0f11c130
/*  f11c118:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f11c11c:
/*  f11c11c:	1420fff5 */ 	bnez	$at,.L0f11c0f4
/*  f11c120:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f11c124:	10000002 */ 	beqz	$zero,.L0f11c130
/*  f11c128:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c12c:	24100001 */ 	addiu	$s0,$zero,0x1
.L0f11c130:
/*  f11c130:	12000033 */ 	beqz	$s0,.L0f11c200
/*  f11c134:	00172600 */ 	sll	$a0,$s7,0x18
/*  f11c138:	02b30019 */ 	multu	$s5,$s3
/*  f11c13c:	0017c880 */ 	sll	$t9,$s7,0x2
/*  f11c140:	0337c823 */ 	subu	$t9,$t9,$s7
/*  f11c144:	8fad20c4 */ 	lw	$t5,0x20c4($sp)
/*  f11c148:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11c14c:	0337c821 */ 	addu	$t9,$t9,$s7
/*  f11c150:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11c154:	3c0b800a */ 	lui	$t3,%hi(var800a3180)
/*  f11c158:	256b3180 */ 	addiu	$t3,$t3,%lo(var800a3180)
/*  f11c15c:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f11c160:	0000c012 */ 	mflo	$t8
/*  f11c164:	00045603 */ 	sra	$t2,$a0,0x18
/*  f11c168:	16e10003 */ 	bne	$s7,$at,.L0f11c178
/*  f11c16c:	030d8821 */ 	addu	$s1,$t8,$t5
/*  f11c170:	10000002 */ 	beqz	$zero,.L0f11c17c
/*  f11c174:	00008025 */ 	or	$s0,$zero,$zero
.L0f11c178:
/*  f11c178:	032b8021 */ 	addu	$s0,$t9,$t3
.L0f11c17c:
/*  f11c17c:	0fc45974 */ 	jal	func0f1165d0
/*  f11c180:	01402025 */ 	or	$a0,$t2,$zero
/*  f11c184:	8faf0058 */ 	lw	$t7,0x58($sp)
/*  f11c188:	00172600 */ 	sll	$a0,$s7,0x18
/*  f11c18c:	00046603 */ 	sra	$t4,$a0,0x18
/*  f11c190:	8de6029c */ 	lw	$a2,0x29c($t7)
/*  f11c194:	02567021 */ 	addu	$t6,$s2,$s6
/*  f11c198:	afae0018 */ 	sw	$t6,0x18($sp)
/*  f11c19c:	afa20014 */ 	sw	$v0,0x14($sp)
/*  f11c1a0:	afb10010 */ 	sw	$s1,0x10($sp)
/*  f11c1a4:	01802025 */ 	or	$a0,$t4,$zero
/*  f11c1a8:	02002825 */ 	or	$a1,$s0,$zero
/*  f11c1ac:	0fc46941 */ 	jal	func0f11a504
/*  f11c1b0:	24070001 */ 	addiu	$a3,$zero,0x1
/*  f11c1b4:	00172e00 */ 	sll	$a1,$s7,0x18
/*  f11c1b8:	00054e03 */ 	sra	$t1,$a1,0x18
/*  f11c1bc:	00408025 */ 	or	$s0,$v0,$zero
/*  f11c1c0:	01202825 */ 	or	$a1,$t1,$zero
/*  f11c1c4:	00402025 */ 	or	$a0,$v0,$zero
/*  f11c1c8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f11c1cc:	0fc470e7 */ 	jal	func0f11c39c
/*  f11c1d0:	24071286 */ 	addiu	$a3,$zero,0x1286
/*  f11c1d4:	5440000b */ 	bnezl	$v0,.L0f11c204
/*  f11c1d8:	8fb80098 */ 	lw	$t8,0x98($sp)
/*  f11c1dc:	0c005451 */ 	jal	func00015144
/*  f11c1e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c1e4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f11c1e8:	16010003 */ 	bne	$s0,$at,.L0f11c1f8
/*  f11c1ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c1f0:	10000022 */ 	beqz	$zero,.L0f11c27c
/*  f11c1f4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11c1f8:
/*  f11c1f8:	10000020 */ 	beqz	$zero,.L0f11c27c
/*  f11c1fc:	24020004 */ 	addiu	$v0,$zero,0x4
.L0f11c200:
/*  f11c200:	8fb80098 */ 	lw	$t8,0x98($sp)
.L0f11c204:
/*  f11c204:	26b50001 */ 	addiu	$s5,$s5,0x1
/*  f11c208:	56b8ff9c */ 	bnel	$s5,$t8,.L0f11c07c
/*  f11c20c:	00172600 */ 	sll	$a0,$s7,0x18
.L0f11c210:
/*  f11c210:	27de0001 */ 	addiu	$s8,$s8,0x1
.L0f11c214:
/*  f11c214:	24010002 */ 	addiu	$at,$zero,0x2
/*  f11c218:	17c1ff88 */ 	bne	$s8,$at,.L0f11c03c
/*  f11c21c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c220:	0c005451 */ 	jal	func00015144
/*  f11c224:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c228:	3c0d8007 */ 	lui	$t5,0x8007
/*  f11c22c:	8dad5ce8 */ 	lw	$t5,0x5ce8($t5)
/*  f11c230:	00172600 */ 	sll	$a0,$s7,0x18
/*  f11c234:	0004ce03 */ 	sra	$t9,$a0,0x18
/*  f11c238:	51a00010 */ 	beqzl	$t5,.L0f11c27c
/*  f11c23c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11c240:	0fc45974 */ 	jal	func0f1165d0
/*  f11c244:	03202025 */ 	or	$a0,$t9,$zero
/*  f11c248:	8faa20c4 */ 	lw	$t2,0x20c4($sp)
/*  f11c24c:	00172600 */ 	sll	$a0,$s7,0x18
/*  f11c250:	00045e03 */ 	sra	$t3,$a0,0x18
/*  f11c254:	0142001b */ 	divu	$zero,$t2,$v0
/*  f11c258:	00002812 */ 	mflo	$a1
/*  f11c25c:	01602025 */ 	or	$a0,$t3,$zero
/*  f11c260:	14400002 */ 	bnez	$v0,.L0f11c26c
/*  f11c264:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c268:	0007000d */ 	break	0x7
.L0f11c26c:
/*  f11c26c:	02403025 */ 	or	$a2,$s2,$zero
/*  f11c270:	0fc46c5e */ 	jal	func0f11b178
/*  f11c274:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c278:	00001025 */ 	or	$v0,$zero,$zero
.L0f11c27c:
/*  f11c27c:	8fbf004c */ 	lw	$ra,0x4c($sp)
/*  f11c280:	8fb00028 */ 	lw	$s0,0x28($sp)
/*  f11c284:	8fb1002c */ 	lw	$s1,0x2c($sp)
/*  f11c288:	8fb20030 */ 	lw	$s2,0x30($sp)
/*  f11c28c:	8fb30034 */ 	lw	$s3,0x34($sp)
/*  f11c290:	8fb40038 */ 	lw	$s4,0x38($sp)
/*  f11c294:	8fb5003c */ 	lw	$s5,0x3c($sp)
/*  f11c298:	8fb60040 */ 	lw	$s6,0x40($sp)
/*  f11c29c:	8fb70044 */ 	lw	$s7,0x44($sp)
/*  f11c2a0:	8fbe0048 */ 	lw	$s8,0x48($sp)
/*  f11c2a4:	03e00008 */ 	jr	$ra
/*  f11c2a8:	27bd20c0 */ 	addiu	$sp,$sp,0x20c0
);

GLOBAL_ASM(
glabel func0f11c2ac
/*  f11c2ac:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f11c2b0:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f11c2b4:	83ae002b */ 	lb	$t6,0x2b($sp)
/*  f11c2b8:	3c18800a */ 	lui	$t8,%hi(var800a2380)
/*  f11c2bc:	27182380 */ 	addiu	$t8,$t8,%lo(var800a2380)
/*  f11c2c0:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f11c2c4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11c2c8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11c2cc:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11c2d0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11c2d4:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f11c2d8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11c2dc:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11c2e0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11c2e4:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f11c2e8:	8c450010 */ 	lw	$a1,0x10($v0)
/*  f11c2ec:	2401000e */ 	addiu	$at,$zero,0xe
/*  f11c2f0:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11c2f4:	10a10024 */ 	beq	$a1,$at,.L0f11c388
/*  f11c2f8:	24010013 */ 	addiu	$at,$zero,0x13
/*  f11c2fc:	50a10023 */ 	beql	$a1,$at,.L0f11c38c
/*  f11c300:	00001025 */ 	or	$v0,$zero,$zero
/*  f11c304:	0c00543a */ 	jal	func000150e8
/*  f11c308:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f11c30c:	83a2002b */ 	lb	$v0,0x2b($sp)
/*  f11c310:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11c314:	3c08800a */ 	lui	$t0,%hi(var800a3180)
/*  f11c318:	14410003 */ 	bne	$v0,$at,.L0f11c328
/*  f11c31c:	0002c880 */ 	sll	$t9,$v0,0x2
/*  f11c320:	10000007 */ 	beqz	$zero,.L0f11c340
/*  f11c324:	00002825 */ 	or	$a1,$zero,$zero
.L0f11c328:
/*  f11c328:	0322c823 */ 	subu	$t9,$t9,$v0
/*  f11c32c:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11c330:	0322c821 */ 	addu	$t9,$t9,$v0
/*  f11c334:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f11c338:	25083180 */ 	addiu	$t0,$t0,%lo(var800a3180)
/*  f11c33c:	03282821 */ 	addu	$a1,$t9,$t0
.L0f11c340:
/*  f11c340:	0c0135bc */ 	jal	func0004d6f0
/*  f11c344:	00a02025 */ 	or	$a0,$a1,$zero
/*  f11c348:	0c005451 */ 	jal	func00015144
/*  f11c34c:	afa20024 */ 	sw	$v0,0x24($sp)
/*  f11c350:	8fa40024 */ 	lw	$a0,0x24($sp)
/*  f11c354:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f11c358:	83a5002b */ 	lb	$a1,0x2b($sp)
/*  f11c35c:	14800005 */ 	bnez	$a0,.L0f11c374
/*  f11c360:	00003025 */ 	or	$a2,$zero,$zero
/*  f11c364:	8faa001c */ 	lw	$t2,0x1c($sp)
/*  f11c368:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11c36c:	10000007 */ 	beqz	$zero,.L0f11c38c
/*  f11c370:	ad490010 */ 	sw	$t1,0x10($t2)
.L0f11c374:
/*  f11c374:	0fc470e7 */ 	jal	func0f11c39c
/*  f11c378:	240712c1 */ 	addiu	$a3,$zero,0x12c1
/*  f11c37c:	8fac001c */ 	lw	$t4,0x1c($sp)
/*  f11c380:	240b0016 */ 	addiu	$t3,$zero,0x16
/*  f11c384:	ad8b0010 */ 	sw	$t3,0x10($t4)
.L0f11c388:
/*  f11c388:	00001025 */ 	or	$v0,$zero,$zero
.L0f11c38c:
/*  f11c38c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11c390:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f11c394:	03e00008 */ 	jr	$ra
/*  f11c398:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11c39c
/*  f11c39c:	afa50004 */ 	sw	$a1,0x4($sp)
/*  f11c3a0:	00057600 */ 	sll	$t6,$a1,0x18
/*  f11c3a4:	000e2e03 */ 	sra	$a1,$t6,0x18
/*  f11c3a8:	14800003 */ 	bnez	$a0,.L0f11c3b8
/*  f11c3ac:	afa7000c */ 	sw	$a3,0xc($sp)
/*  f11c3b0:	03e00008 */ 	jr	$ra
/*  f11c3b4:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11c3b8:
/*  f11c3b8:	10c0004c */ 	beqz	$a2,.L0f11c4ec
/*  f11c3bc:	2498ffff */ 	addiu	$t8,$a0,-1
/*  f11c3c0:	2f01000b */ 	sltiu	$at,$t8,0xb
/*  f11c3c4:	10200049 */ 	beqz	$at,.L0f11c4ec
/*  f11c3c8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11c3cc:	3c017f1b */ 	lui	$at,%hi(var7f1b4e9c)
/*  f11c3d0:	00380821 */ 	addu	$at,$at,$t8
/*  f11c3d4:	8c384e9c */ 	lw	$t8,%lo(var7f1b4e9c)($at)
/*  f11c3d8:	03000008 */ 	jr	$t8
/*  f11c3dc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c3e0:	0005c880 */ 	sll	$t9,$a1,0x2
/*  f11c3e4:	0325c823 */ 	subu	$t9,$t9,$a1
/*  f11c3e8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11c3ec:	0325c823 */ 	subu	$t9,$t9,$a1
/*  f11c3f0:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11c3f4:	0325c821 */ 	addu	$t9,$t9,$a1
/*  f11c3f8:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11c3fc:	0325c823 */ 	subu	$t9,$t9,$a1
/*  f11c400:	3c08800a */ 	lui	$t0,%hi(var800a2380)
/*  f11c404:	25082380 */ 	addiu	$t0,$t0,%lo(var800a2380)
/*  f11c408:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11c40c:	03281021 */ 	addu	$v0,$t9,$t0
/*  f11c410:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f11c414:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f11c418:	ac490000 */ 	sw	$t1,0x0($v0)
/*  f11c41c:	10000033 */ 	beqz	$zero,.L0f11c4ec
/*  f11c420:	ac4a0010 */ 	sw	$t2,0x10($v0)
/*  f11c424:	00055880 */ 	sll	$t3,$a1,0x2
/*  f11c428:	01655823 */ 	subu	$t3,$t3,$a1
/*  f11c42c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f11c430:	01655823 */ 	subu	$t3,$t3,$a1
/*  f11c434:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f11c438:	01655821 */ 	addu	$t3,$t3,$a1
/*  f11c43c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f11c440:	01655823 */ 	subu	$t3,$t3,$a1
/*  f11c444:	3c0c800a */ 	lui	$t4,%hi(var800a2380)
/*  f11c448:	258c2380 */ 	addiu	$t4,$t4,%lo(var800a2380)
/*  f11c44c:	000b5880 */ 	sll	$t3,$t3,0x2
/*  f11c450:	016c1021 */ 	addu	$v0,$t3,$t4
/*  f11c454:	240d0002 */ 	addiu	$t5,$zero,0x2
/*  f11c458:	240e000e */ 	addiu	$t6,$zero,0xe
/*  f11c45c:	ac4d0000 */ 	sw	$t5,0x0($v0)
/*  f11c460:	10000022 */ 	beqz	$zero,.L0f11c4ec
/*  f11c464:	ac4e0010 */ 	sw	$t6,0x10($v0)
/*  f11c468:	00057880 */ 	sll	$t7,$a1,0x2
/*  f11c46c:	01e57823 */ 	subu	$t7,$t7,$a1
/*  f11c470:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11c474:	01e57823 */ 	subu	$t7,$t7,$a1
/*  f11c478:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11c47c:	01e57821 */ 	addu	$t7,$t7,$a1
/*  f11c480:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11c484:	01e57823 */ 	subu	$t7,$t7,$a1
/*  f11c488:	3c18800a */ 	lui	$t8,%hi(var800a2380)
/*  f11c48c:	27182380 */ 	addiu	$t8,$t8,%lo(var800a2380)
/*  f11c490:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11c494:	01f81021 */ 	addu	$v0,$t7,$t8
/*  f11c498:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f11c49c:	2408000f */ 	addiu	$t0,$zero,0xf
/*  f11c4a0:	ac590000 */ 	sw	$t9,0x0($v0)
/*  f11c4a4:	10000011 */ 	beqz	$zero,.L0f11c4ec
/*  f11c4a8:	ac480010 */ 	sw	$t0,0x10($v0)
/*  f11c4ac:	00054880 */ 	sll	$t1,$a1,0x2
/*  f11c4b0:	01254823 */ 	subu	$t1,$t1,$a1
/*  f11c4b4:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11c4b8:	01254823 */ 	subu	$t1,$t1,$a1
/*  f11c4bc:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11c4c0:	01254821 */ 	addu	$t1,$t1,$a1
/*  f11c4c4:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11c4c8:	01254823 */ 	subu	$t1,$t1,$a1
/*  f11c4cc:	3c0a800a */ 	lui	$t2,%hi(var800a2380)
/*  f11c4d0:	254a2380 */ 	addiu	$t2,$t2,%lo(var800a2380)
/*  f11c4d4:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11c4d8:	012a1021 */ 	addu	$v0,$t1,$t2
/*  f11c4dc:	240b0002 */ 	addiu	$t3,$zero,0x2
/*  f11c4e0:	240c0010 */ 	addiu	$t4,$zero,0x10
/*  f11c4e4:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*  f11c4e8:	ac4c0010 */ 	sw	$t4,0x10($v0)
.L0f11c4ec:
/*  f11c4ec:	2881000e */ 	slti	$at,$a0,0xe
/*  f11c4f0:	1420000a */ 	bnez	$at,.L0f11c51c
/*  f11c4f4:	00801025 */ 	or	$v0,$a0,$zero
/*  f11c4f8:	244dff80 */ 	addiu	$t5,$v0,-128
/*  f11c4fc:	2da10005 */ 	sltiu	$at,$t5,0x5
/*  f11c500:	1020000f */ 	beqz	$at,.L0f11c540
/*  f11c504:	000d6880 */ 	sll	$t5,$t5,0x2
/*  f11c508:	3c017f1b */ 	lui	$at,%hi(var7f1b4ec8)
/*  f11c50c:	002d0821 */ 	addu	$at,$at,$t5
/*  f11c510:	8c2d4ec8 */ 	lw	$t5,%lo(var7f1b4ec8)($at)
/*  f11c514:	01a00008 */ 	jr	$t5
/*  f11c518:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11c51c:
/*  f11c51c:	244effff */ 	addiu	$t6,$v0,-1
/*  f11c520:	2dc1000d */ 	sltiu	$at,$t6,0xd
/*  f11c524:	10200006 */ 	beqz	$at,.L0f11c540
/*  f11c528:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11c52c:	3c017f1b */ 	lui	$at,%hi(var7f1b4edc)
/*  f11c530:	002e0821 */ 	addu	$at,$at,$t6
/*  f11c534:	8c2e4edc */ 	lw	$t6,%lo(var7f1b4edc)($at)
/*  f11c538:	01c00008 */ 	jr	$t6
/*  f11c53c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11c540:
/*  f11c540:	00001025 */ 	or	$v0,$zero,$zero
/*  f11c544:	03e00008 */ 	jr	$ra
/*  f11c548:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11c54c
/*  f11c54c:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f11c550:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f11c554:	3c12800a */ 	lui	$s2,%hi(g_Vars)
/*  f11c558:	26529fc0 */ 	addiu	$s2,$s2,%lo(g_Vars)
/*  f11c55c:	964e04e4 */ 	lhu	$t6,0x4e4($s2)
/*  f11c560:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f11c564:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f11c568:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f11c56c:	11c00051 */ 	beqz	$t6,.L0f11c6b4
/*  f11c570:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f11c574:	3c018007 */ 	lui	$at,0x8007
/*  f11c578:	ac201448 */ 	sw	$zero,0x1448($at)
/*  f11c57c:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f11c580:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f11c584:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11c588:	3c018007 */ 	lui	$at,0x8007
/*  f11c58c:	ac205d14 */ 	sw	$zero,0x5d14($at)
/*  f11c590:	964f04e4 */ 	lhu	$t7,0x4e4($s2)
/*  f11c594:	31f8000f */ 	andi	$t8,$t7,0xf
/*  f11c598:	13000013 */ 	beqz	$t8,.L0f11c5e8
/*  f11c59c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c5a0:	0c004e5d */ 	jal	func00013974
/*  f11c5a4:	00002025 */ 	or	$a0,$zero,$zero
/*  f11c5a8:	964204e4 */ 	lhu	$v0,0x4e4($s2)
/*  f11c5ac:	3059000f */ 	andi	$t9,$v0,0xf
/*  f11c5b0:	2b21000a */ 	slti	$at,$t9,0xa
/*  f11c5b4:	1420000a */ 	bnez	$at,.L0f11c5e0
/*  f11c5b8:	244bffff */ 	addiu	$t3,$v0,-1
/*  f11c5bc:	8e48000c */ 	lw	$t0,0xc($s2)
/*  f11c5c0:	24010007 */ 	addiu	$at,$zero,0x7
/*  f11c5c4:	244affff */ 	addiu	$t2,$v0,-1
/*  f11c5c8:	0101001a */ 	div	$zero,$t0,$at
/*  f11c5cc:	00004810 */ 	mfhi	$t1
/*  f11c5d0:	55200039 */ 	bnezl	$t1,.L0f11c6b8
/*  f11c5d4:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f11c5d8:	10000036 */ 	beqz	$zero,.L0f11c6b4
/*  f11c5dc:	a64a04e4 */ 	sh	$t2,0x4e4($s2)
.L0f11c5e0:
/*  f11c5e0:	10000034 */ 	beqz	$zero,.L0f11c6b4
/*  f11c5e4:	a64b04e4 */ 	sh	$t3,0x4e4($s2)
.L0f11c5e8:
/*  f11c5e8:	0c004eae */ 	jal	func00013ab8
/*  f11c5ec:	24040002 */ 	addiu	$a0,$zero,0x2
/*  f11c5f0:	00008025 */ 	or	$s0,$zero,$zero
/*  f11c5f4:	24130004 */ 	addiu	$s3,$zero,0x4
/*  f11c5f8:	964204e4 */ 	lhu	$v0,0x4e4($s2)
.L0f11c5fc:
/*  f11c5fc:	260c0004 */ 	addiu	$t4,$s0,0x4
/*  f11c600:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f11c604:	018d8804 */ 	sllv	$s1,$t5,$t4
/*  f11c608:	00517024 */ 	and	$t6,$v0,$s1
/*  f11c60c:	11c0000b */ 	beqz	$t6,.L0f11c63c
/*  f11c610:	26090008 */ 	addiu	$t1,$s0,0x8
/*  f11c614:	00102600 */ 	sll	$a0,$s0,0x18
/*  f11c618:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f11c61c:	01e02025 */ 	or	$a0,$t7,$zero
/*  f11c620:	0fc45a72 */ 	jal	func0f1169c8
/*  f11c624:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11c628:	965804e4 */ 	lhu	$t8,0x4e4($s2)
/*  f11c62c:	0220c827 */ 	nor	$t9,$s1,$zero
/*  f11c630:	03194024 */ 	and	$t0,$t8,$t9
/*  f11c634:	1000000e */ 	beqz	$zero,.L0f11c670
/*  f11c638:	a64804e4 */ 	sh	$t0,0x4e4($s2)
.L0f11c63c:
/*  f11c63c:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f11c640:	012a8804 */ 	sllv	$s1,$t2,$t1
/*  f11c644:	00515824 */ 	and	$t3,$v0,$s1
/*  f11c648:	11600009 */ 	beqz	$t3,.L0f11c670
/*  f11c64c:	00102600 */ 	sll	$a0,$s0,0x18
/*  f11c650:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f11c654:	01a02025 */ 	or	$a0,$t5,$zero
/*  f11c658:	0fc45a72 */ 	jal	func0f1169c8
/*  f11c65c:	00002825 */ 	or	$a1,$zero,$zero
/*  f11c660:	964c04e4 */ 	lhu	$t4,0x4e4($s2)
/*  f11c664:	02207027 */ 	nor	$t6,$s1,$zero
/*  f11c668:	018e7824 */ 	and	$t7,$t4,$t6
/*  f11c66c:	a64f04e4 */ 	sh	$t7,0x4e4($s2)
.L0f11c670:
/*  f11c670:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11c674:	5613ffe1 */ 	bnel	$s0,$s3,.L0f11c5fc
/*  f11c678:	964204e4 */ 	lhu	$v0,0x4e4($s2)
/*  f11c67c:	0c004e60 */ 	jal	func00013980
/*  f11c680:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c684:	54400006 */ 	bnezl	$v0,.L0f11c6a0
/*  f11c688:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f11c68c:	0c004e5d */ 	jal	func00013974
/*  f11c690:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f11c694:	0c004e72 */ 	jal	func000139c8
/*  f11c698:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c69c:	2404ffff */ 	addiu	$a0,$zero,-1
.L0f11c6a0:
/*  f11c6a0:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f11c6a4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11c6a8:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f11c6ac:	3c018007 */ 	lui	$at,0x8007
/*  f11c6b0:	ac385d14 */ 	sw	$t8,0x5d14($at)
.L0f11c6b4:
/*  f11c6b4:	8fbf0024 */ 	lw	$ra,0x24($sp)
.L0f11c6b8:
/*  f11c6b8:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f11c6bc:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f11c6c0:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f11c6c4:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f11c6c8:	03e00008 */ 	jr	$ra
/*  f11c6cc:	27bd0028 */ 	addiu	$sp,$sp,0x28
);

GLOBAL_ASM(
glabel func0f11c6d0
/*  f11c6d0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f11c6d4:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f11c6d8:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f11c6dc:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f11c6e0:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f11c6e4:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f11c6e8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f11c6ec:	3c11800a */ 	lui	$s1,%hi(var800a2380)
/*  f11c6f0:	3c128007 */ 	lui	$s2,%hi(var80075d10)
/*  f11c6f4:	3c138007 */ 	lui	$s3,%hi(g_MenuStackDepth)
/*  f11c6f8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f11c6fc:	26731448 */ 	addiu	$s3,$s3,%lo(g_MenuStackDepth)
/*  f11c700:	26525d10 */ 	addiu	$s2,$s2,%lo(var80075d10)
/*  f11c704:	26312380 */ 	addiu	$s1,$s1,%lo(var800a2380)
/*  f11c708:	00008025 */ 	or	$s0,$zero,$zero
/*  f11c70c:	24140004 */ 	addiu	$s4,$zero,0x4
/*  f11c710:	24150001 */ 	addiu	$s5,$zero,0x1
.L0f11c714:
/*  f11c714:	8e2e0010 */ 	lw	$t6,0x10($s1)
/*  f11c718:	25cffffe */ 	addiu	$t7,$t6,-2
/*  f11c71c:	2de10005 */ 	sltiu	$at,$t7,0x5
/*  f11c720:	10200011 */ 	beqz	$at,.L0f11c768
/*  f11c724:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11c728:	3c017f1b */ 	lui	$at,%hi(var7f1b4f10)
/*  f11c72c:	002f0821 */ 	addu	$at,$at,$t7
/*  f11c730:	8c2f4f10 */ 	lw	$t7,%lo(var7f1b4f10)($at)
/*  f11c734:	01e00008 */ 	jr	$t7
/*  f11c738:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c73c:	92580000 */ 	lbu	$t8,0x0($s2)
/*  f11c740:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f11c744:	02194004 */ 	sllv	$t0,$t9,$s0
/*  f11c748:	01004827 */ 	nor	$t1,$t0,$zero
/*  f11c74c:	03095024 */ 	and	$t2,$t8,$t1
/*  f11c750:	ae350010 */ 	sw	$s5,0x10($s1)
/*  f11c754:	a24a0000 */ 	sb	$t2,0x0($s2)
/*  f11c758:	ae700000 */ 	sw	$s0,0x0($s3)
/*  f11c75c:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f11c760:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f11c764:	02a02825 */ 	or	$a1,$s5,$zero
.L0f11c768:
/*  f11c768:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11c76c:	1614ffe9 */ 	bne	$s0,$s4,.L0f11c714
/*  f11c770:	263102cc */ 	addiu	$s1,$s1,0x2cc
/*  f11c774:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f11c778:	3c018006 */ 	lui	$at,0x8006
/*  f11c77c:	ac35eedc */ 	sw	$s5,-0x1124($at)
/*  f11c780:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f11c784:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f11c788:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f11c78c:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f11c790:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f11c794:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f11c798:	03e00008 */ 	jr	$ra
/*  f11c79c:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f11c7a0
/*  f11c7a0:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f11c7a4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11c7a8:	3c047f1b */ 	lui	$a0,%hi(var7f1b465c)
/*  f11c7ac:	3c058007 */ 	lui	$a1,%hi(var80075ce0)
/*  f11c7b0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11c7b4:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f11c7b8:	24a55ce0 */ 	addiu	$a1,$a1,%lo(var80075ce0)
/*  f11c7bc:	0c0036cc */ 	jal	func0000db30
/*  f11c7c0:	2484465c */ 	addiu	$a0,$a0,%lo(var7f1b465c)
/*  f11c7c4:	3c047f1b */ 	lui	$a0,%hi(var7f1b4668)
/*  f11c7c8:	3c058007 */ 	lui	$a1,%hi(var80075ce4)
/*  f11c7cc:	24a55ce4 */ 	addiu	$a1,$a1,%lo(var80075ce4)
/*  f11c7d0:	0c0036cc */ 	jal	func0000db30
/*  f11c7d4:	24844668 */ 	addiu	$a0,$a0,%lo(var7f1b4668)
/*  f11c7d8:	3c047f1b */ 	lui	$a0,%hi(var7f1b4670)
/*  f11c7dc:	3c058007 */ 	lui	$a1,%hi(var80075ce8)
/*  f11c7e0:	24a55ce8 */ 	addiu	$a1,$a1,%lo(var80075ce8)
/*  f11c7e4:	0c0036cc */ 	jal	func0000db30
/*  f11c7e8:	24844670 */ 	addiu	$a0,$a0,%lo(var7f1b4670)
/*  f11c7ec:	3c047f1b */ 	lui	$a0,%hi(var7f1b467c)
/*  f11c7f0:	3c058007 */ 	lui	$a1,%hi(var80075cec)
/*  f11c7f4:	24a55cec */ 	addiu	$a1,$a1,%lo(var80075cec)
/*  f11c7f8:	0c0036cc */ 	jal	func0000db30
/*  f11c7fc:	2484467c */ 	addiu	$a0,$a0,%lo(var7f1b467c)
/*  f11c800:	3c108007 */ 	lui	$s0,%hi(var80075cf4)
/*  f11c804:	26105cf4 */ 	addiu	$s0,$s0,%lo(var80075cf4)
/*  f11c808:	3c047f1b */ 	lui	$a0,%hi(var7f1b4684)
/*  f11c80c:	24844684 */ 	addiu	$a0,$a0,%lo(var7f1b4684)
/*  f11c810:	0c0036cc */ 	jal	func0000db30
/*  f11c814:	02002825 */ 	or	$a1,$s0,$zero
/*  f11c818:	3c047f1b */ 	lui	$a0,%hi(var7f1b4690)
/*  f11c81c:	3c058007 */ 	lui	$a1,%hi(var80075cf0)
/*  f11c820:	24a55cf0 */ 	addiu	$a1,$a1,%lo(var80075cf0)
/*  f11c824:	0c0036cc */ 	jal	func0000db30
/*  f11c828:	24844690 */ 	addiu	$a0,$a0,%lo(var7f1b4690)
/*  f11c82c:	3c047f1b */ 	lui	$a0,%hi(var7f1b469c)
/*  f11c830:	3c058007 */ 	lui	$a1,%hi(var80075d54)
/*  f11c834:	24a55d54 */ 	addiu	$a1,$a1,%lo(var80075d54)
/*  f11c838:	0c0036cc */ 	jal	func0000db30
/*  f11c83c:	2484469c */ 	addiu	$a0,$a0,%lo(var7f1b469c)
/*  f11c840:	8e0e0000 */ 	lw	$t6,0x0($s0)
/*  f11c844:	11c00003 */ 	beqz	$t6,.L0f11c854
/*  f11c848:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c84c:	0fc4676a */ 	jal	func0f119da8
/*  f11c850:	ae000000 */ 	sw	$zero,0x0($s0)
.L0f11c854:
/*  f11c854:	3c0f8007 */ 	lui	$t7,0x8007
/*  f11c858:	8def5ce4 */ 	lw	$t7,0x5ce4($t7)
/*  f11c85c:	11e00005 */ 	beqz	$t7,.L0f11c874
/*  f11c860:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c864:	0fc477e3 */ 	jal	func0f11df8c
/*  f11c868:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c86c:	3c018007 */ 	lui	$at,0x8007
/*  f11c870:	ac205ce4 */ 	sw	$zero,0x5ce4($at)
.L0f11c874:
/*  f11c874:	3c188007 */ 	lui	$t8,0x8007
/*  f11c878:	8f185d54 */ 	lw	$t8,0x5d54($t8)
/*  f11c87c:	3c018007 */ 	lui	$at,0x8007
/*  f11c880:	13000003 */ 	beqz	$t8,.L0f11c890
/*  f11c884:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c888:	0fc45e12 */ 	jal	func0f117848
/*  f11c88c:	ac205d54 */ 	sw	$zero,0x5d54($at)
.L0f11c890:
/*  f11c890:	3c198007 */ 	lui	$t9,0x8007
/*  f11c894:	8f395cf0 */ 	lw	$t9,0x5cf0($t9)
/*  f11c898:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f11c89c:	00002825 */ 	or	$a1,$zero,$zero
/*  f11c8a0:	13200005 */ 	beqz	$t9,.L0f11c8b8
/*  f11c8a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c8a8:	0fc46bec */ 	jal	func0f11afb0
/*  f11c8ac:	24060080 */ 	addiu	$a2,$zero,0x80
/*  f11c8b0:	3c018007 */ 	lui	$at,0x8007
/*  f11c8b4:	ac205cf0 */ 	sw	$zero,0x5cf0($at)
.L0f11c8b8:
/*  f11c8b8:	3c028007 */ 	lui	$v0,0x8007
/*  f11c8bc:	8c425cec */ 	lw	$v0,0x5cec($v0)
/*  f11c8c0:	10400018 */ 	beqz	$v0,.L0f11c924
/*  f11c8c4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c8c8:	0c00543a */ 	jal	func000150e8
/*  f11c8cc:	2450ffff */ 	addiu	$s0,$v0,-1
/*  f11c8d0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11c8d4:	16010003 */ 	bne	$s0,$at,.L0f11c8e4
/*  f11c8d8:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*  f11c8dc:	10000009 */ 	beqz	$zero,.L0f11c904
/*  f11c8e0:	00002825 */ 	or	$a1,$zero,$zero
.L0f11c8e4:
/*  f11c8e4:	00104080 */ 	sll	$t0,$s0,0x2
/*  f11c8e8:	01104023 */ 	subu	$t0,$t0,$s0
/*  f11c8ec:	00084080 */ 	sll	$t0,$t0,0x2
/*  f11c8f0:	01104021 */ 	addu	$t0,$t0,$s0
/*  f11c8f4:	3c09800a */ 	lui	$t1,%hi(var800a3180)
/*  f11c8f8:	25293180 */ 	addiu	$t1,$t1,%lo(var800a3180)
/*  f11c8fc:	000840c0 */ 	sll	$t0,$t0,0x3
/*  f11c900:	01092821 */ 	addu	$a1,$t0,$t1
.L0f11c904:
/*  f11c904:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*  f11c908:	02003025 */ 	or	$a2,$s0,$zero
/*  f11c90c:	0fc45ec1 */ 	jal	func0f117b04
/*  f11c910:	00003825 */ 	or	$a3,$zero,$zero
/*  f11c914:	0c005451 */ 	jal	func00015144
/*  f11c918:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c91c:	3c018007 */ 	lui	$at,0x8007
/*  f11c920:	ac205cec */ 	sw	$zero,0x5cec($at)
.L0f11c924:
/*  f11c924:	3c0a8007 */ 	lui	$t2,0x8007
/*  f11c928:	8d4a5ce0 */ 	lw	$t2,0x5ce0($t2)
/*  f11c92c:	11400005 */ 	beqz	$t2,.L0f11c944
/*  f11c930:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c934:	0fc46d52 */ 	jal	func0f11b548
/*  f11c938:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f11c93c:	3c018007 */ 	lui	$at,0x8007
/*  f11c940:	ac205ce0 */ 	sw	$zero,0x5ce0($at)
.L0f11c944:
/*  f11c944:	0fc4728c */ 	jal	func0f11ca30
/*  f11c948:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c94c:	3c02800a */ 	lui	$v0,%hi(var800a2380)
/*  f11c950:	24422380 */ 	addiu	$v0,$v0,%lo(var800a2380)
/*  f11c954:	00008025 */ 	or	$s0,$zero,$zero
/*  f11c958:	240302cc */ 	addiu	$v1,$zero,0x2cc
.L0f11c95c:
/*  f11c95c:	02030019 */ 	multu	$s0,$v1
/*  f11c960:	00102600 */ 	sll	$a0,$s0,0x18
/*  f11c964:	00047603 */ 	sra	$t6,$a0,0x18
/*  f11c968:	00005812 */ 	mflo	$t3
/*  f11c96c:	004b6021 */ 	addu	$t4,$v0,$t3
/*  f11c970:	918d0014 */ 	lbu	$t5,0x14($t4)
/*  f11c974:	51a00007 */ 	beqzl	$t5,.L0f11c994
/*  f11c978:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11c97c:	0fc477e5 */ 	jal	func0f11df94
/*  f11c980:	01c02025 */ 	or	$a0,$t6,$zero
/*  f11c984:	3c02800a */ 	lui	$v0,%hi(var800a2380)
/*  f11c988:	24422380 */ 	addiu	$v0,$v0,%lo(var800a2380)
/*  f11c98c:	240302cc */ 	addiu	$v1,$zero,0x2cc
/*  f11c990:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f11c994:
/*  f11c994:	00107e00 */ 	sll	$t7,$s0,0x18
/*  f11c998:	000f8603 */ 	sra	$s0,$t7,0x18
/*  f11c99c:	2a010005 */ 	slti	$at,$s0,0x5
/*  f11c9a0:	1420ffee */ 	bnez	$at,.L0f11c95c
/*  f11c9a4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c9a8:	00008025 */ 	or	$s0,$zero,$zero
/*  f11c9ac:	8fa40024 */ 	lw	$a0,0x24($sp)
.L0f11c9b0:
/*  f11c9b0:	02030019 */ 	multu	$s0,$v1
/*  f11c9b4:	0000c812 */ 	mflo	$t9
/*  f11c9b8:	00594021 */ 	addu	$t0,$v0,$t9
/*  f11c9bc:	8d090010 */ 	lw	$t1,0x10($t0)
/*  f11c9c0:	252afffe */ 	addiu	$t2,$t1,-2
/*  f11c9c4:	2d410005 */ 	sltiu	$at,$t2,0x5
/*  f11c9c8:	10200007 */ 	beqz	$at,.L0f11c9e8
/*  f11c9cc:	000a5080 */ 	sll	$t2,$t2,0x2
/*  f11c9d0:	3c017f1b */ 	lui	$at,%hi(var7f1b4f24)
/*  f11c9d4:	002a0821 */ 	addu	$at,$at,$t2
/*  f11c9d8:	8c2a4f24 */ 	lw	$t2,%lo(var7f1b4f24)($at)
/*  f11c9dc:	01400008 */ 	jr	$t2
/*  f11c9e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11c9e4:	24040001 */ 	addiu	$a0,$zero,0x1
.L0f11c9e8:
/*  f11c9e8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11c9ec:	00105e00 */ 	sll	$t3,$s0,0x18
/*  f11c9f0:	000b8603 */ 	sra	$s0,$t3,0x18
/*  f11c9f4:	2a010005 */ 	slti	$at,$s0,0x5
/*  f11c9f8:	1420ffed */ 	bnez	$at,.L0f11c9b0
/*  f11c9fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ca00:	10800004 */ 	beqz	$a0,.L0f11ca14
/*  f11ca04:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f11ca08:	3c018006 */ 	lui	$at,0x8006
/*  f11ca0c:	10000003 */ 	beqz	$zero,.L0f11ca1c
/*  f11ca10:	ac20eedc */ 	sw	$zero,-0x1124($at)
.L0f11ca14:
/*  f11ca14:	3c018006 */ 	lui	$at,0x8006
/*  f11ca18:	ac2deedc */ 	sw	$t5,-0x1124($at)
.L0f11ca1c:
/*  f11ca1c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11ca20:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f11ca24:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f11ca28:	03e00008 */ 	jr	$ra
/*  f11ca2c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11ca30
/*  f11ca30:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f11ca34:	afb5002c */ 	sw	$s5,0x2c($sp)
/*  f11ca38:	3c15800a */ 	lui	$s5,%hi(g_Vars)
/*  f11ca3c:	26b59fc0 */ 	addiu	$s5,$s5,%lo(g_Vars)
/*  f11ca40:	8eae02ac */ 	lw	$t6,0x2ac($s5)
/*  f11ca44:	24010006 */ 	addiu	$at,$zero,0x6
/*  f11ca48:	afbf003c */ 	sw	$ra,0x3c($sp)
/*  f11ca4c:	afbe0038 */ 	sw	$s8,0x38($sp)
/*  f11ca50:	afb70034 */ 	sw	$s7,0x34($sp)
/*  f11ca54:	afb60030 */ 	sw	$s6,0x30($sp)
/*  f11ca58:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f11ca5c:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f11ca60:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f11ca64:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f11ca68:	15c10005 */ 	bne	$t6,$at,.L0f11ca80
/*  f11ca6c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11ca70:	3c0f800a */ 	lui	$t7,0x800a
/*  f11ca74:	8def19c0 */ 	lw	$t7,0x19c0($t7)
/*  f11ca78:	59e0003d */ 	blezl	$t7,.L0f11cb70
/*  f11ca7c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f11ca80:
/*  f11ca80:	96b804e4 */ 	lhu	$t8,0x4e4($s5)
/*  f11ca84:	3c028007 */ 	lui	$v0,0x8007
/*  f11ca88:	90565d10 */ 	lbu	$s6,0x5d10($v0)
/*  f11ca8c:	3319000f */ 	andi	$t9,$t8,0xf
/*  f11ca90:	241400ff */ 	addiu	$s4,$zero,0xff
/*  f11ca94:	17200035 */ 	bnez	$t9,.L0f11cb6c
/*  f11ca98:	02c09825 */ 	or	$s3,$s6,$zero
/*  f11ca9c:	00008825 */ 	or	$s1,$zero,$zero
/*  f11caa0:	241e0002 */ 	addiu	$s8,$zero,0x2
/*  f11caa4:	241700ff */ 	addiu	$s7,$zero,0xff
/*  f11caa8:	92a904d1 */ 	lbu	$t1,0x4d1($s5)
.L0f11caac:
/*  f11caac:	92aa04d0 */ 	lbu	$t2,0x4d0($s5)
/*  f11cab0:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f11cab4:	02288004 */ 	sllv	$s0,$t0,$s1
/*  f11cab8:	012a5825 */ 	or	$t3,$t1,$t2
/*  f11cabc:	01706024 */ 	and	$t4,$t3,$s0
/*  f11cac0:	11800024 */ 	beqz	$t4,.L0f11cb54
/*  f11cac4:	02801825 */ 	or	$v1,$s4,$zero
/*  f11cac8:	16f40005 */ 	bne	$s7,$s4,.L0f11cae0
/*  f11cacc:	02c09025 */ 	or	$s2,$s6,$zero
/*  f11cad0:	0c004e7a */ 	jal	func000139e8
/*  f11cad4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11cad8:	305400ff */ 	andi	$s4,$v0,0xff
/*  f11cadc:	02801825 */ 	or	$v1,$s4,$zero
.L0f11cae0:
/*  f11cae0:	00701024 */ 	and	$v0,$v1,$s0
/*  f11cae4:	02506824 */ 	and	$t5,$s2,$s0
/*  f11cae8:	11a2001a */ 	beq	$t5,$v0,.L0f11cb54
/*  f11caec:	00117080 */ 	sll	$t6,$s1,0x2
/*  f11caf0:	01d17023 */ 	subu	$t6,$t6,$s1
/*  f11caf4:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11caf8:	01d17023 */ 	subu	$t6,$t6,$s1
/*  f11cafc:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11cb00:	01d17021 */ 	addu	$t6,$t6,$s1
/*  f11cb04:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11cb08:	01d17023 */ 	subu	$t6,$t6,$s1
/*  f11cb0c:	3c0f800a */ 	lui	$t7,%hi(var800a2380)
/*  f11cb10:	25ef2380 */ 	addiu	$t7,$t7,%lo(var800a2380)
/*  f11cb14:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11cb18:	10400006 */ 	beqz	$v0,.L0f11cb34
/*  f11cb1c:	01cf1821 */ 	addu	$v1,$t6,$t7
/*  f11cb20:	02709825 */ 	or	$s3,$s3,$s0
/*  f11cb24:	327800ff */ 	andi	$t8,$s3,0xff
/*  f11cb28:	ac7e0010 */ 	sw	$s8,0x10($v1)
/*  f11cb2c:	10000009 */ 	beqz	$zero,.L0f11cb54
/*  f11cb30:	03009825 */ 	or	$s3,$t8,$zero
.L0f11cb34:
/*  f11cb34:	02004027 */ 	nor	$t0,$s0,$zero
/*  f11cb38:	02689824 */ 	and	$s3,$s3,$t0
/*  f11cb3c:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f11cb40:	326900ff */ 	andi	$t1,$s3,0xff
/*  f11cb44:	ac790010 */ 	sw	$t9,0x10($v1)
/*  f11cb48:	01209825 */ 	or	$s3,$t1,$zero
/*  f11cb4c:	0fc44364 */ 	jal	func0f110d90
/*  f11cb50:	02202025 */ 	or	$a0,$s1,$zero
.L0f11cb54:
/*  f11cb54:	26310001 */ 	addiu	$s1,$s1,0x1
/*  f11cb58:	24010005 */ 	addiu	$at,$zero,0x5
/*  f11cb5c:	5621ffd3 */ 	bnel	$s1,$at,.L0f11caac
/*  f11cb60:	92a904d1 */ 	lbu	$t1,0x4d1($s5)
/*  f11cb64:	3c018007 */ 	lui	$at,0x8007
/*  f11cb68:	a0335d10 */ 	sb	$s3,0x5d10($at)
.L0f11cb6c:
/*  f11cb6c:	8fbf003c */ 	lw	$ra,0x3c($sp)
.L0f11cb70:
/*  f11cb70:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f11cb74:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f11cb78:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f11cb7c:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f11cb80:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f11cb84:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*  f11cb88:	8fb60030 */ 	lw	$s6,0x30($sp)
/*  f11cb8c:	8fb70034 */ 	lw	$s7,0x34($sp)
/*  f11cb90:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*  f11cb94:	03e00008 */ 	jr	$ra
/*  f11cb98:	27bd0040 */ 	addiu	$sp,$sp,0x40
);

GLOBAL_ASM(
glabel func0f11cb9c
/*  f11cb9c:	248effff */ 	addiu	$t6,$a0,-1
/*  f11cba0:	2dc1000d */ 	sltiu	$at,$t6,0xd
/*  f11cba4:	10200006 */ 	beqz	$at,.L0f11cbc0
/*  f11cba8:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11cbac:	3c017f1b */ 	lui	$at,%hi(var7f1b4f38)
/*  f11cbb0:	002e0821 */ 	addu	$at,$at,$t6
/*  f11cbb4:	8c2e4f38 */ 	lw	$t6,%lo(var7f1b4f38)($at)
/*  f11cbb8:	01c00008 */ 	jr	$t6
/*  f11cbbc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11cbc0:
/*  f11cbc0:	03e00008 */ 	jr	$ra
/*  f11cbc4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11cbc8:	03e00008 */ 	jr	$ra
/*  f11cbcc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11cbd0:	03e00008 */ 	jr	$ra
/*  f11cbd4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11cbd8
/*  f11cbd8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f11cbdc:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f11cbe0:	83ae0023 */ 	lb	$t6,0x23($sp)
/*  f11cbe4:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11cbe8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11cbec:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f11cbf0:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f11cbf4:	15c10003 */ 	bne	$t6,$at,.L0f11cc04
/*  f11cbf8:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f11cbfc:	1000000a */ 	beqz	$zero,.L0f11cc28
/*  f11cc00:	00002025 */ 	or	$a0,$zero,$zero
.L0f11cc04:
/*  f11cc04:	83af0023 */ 	lb	$t7,0x23($sp)
/*  f11cc08:	3c19800a */ 	lui	$t9,%hi(var800a3180)
/*  f11cc0c:	27393180 */ 	addiu	$t9,$t9,%lo(var800a3180)
/*  f11cc10:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11cc14:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11cc18:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11cc1c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11cc20:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f11cc24:	03192021 */ 	addu	$a0,$t8,$t9
.L0f11cc28:
/*  f11cc28:	97a8002e */ 	lhu	$t0,0x2e($sp)
/*  f11cc2c:	00002825 */ 	or	$a1,$zero,$zero
/*  f11cc30:	97a60026 */ 	lhu	$a2,0x26($sp)
/*  f11cc34:	8fa70028 */ 	lw	$a3,0x28($sp)
/*  f11cc38:	0c0144ec */ 	jal	func000513b0
/*  f11cc3c:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f11cc40:	10400005 */ 	beqz	$v0,.L0f11cc58
/*  f11cc44:	00402025 */ 	or	$a0,$v0,$zero
/*  f11cc48:	0fc472e7 */ 	jal	func0f11cb9c
/*  f11cc4c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11cc50:	10000002 */ 	beqz	$zero,.L0f11cc5c
/*  f11cc54:	00001025 */ 	or	$v0,$zero,$zero
.L0f11cc58:
/*  f11cc58:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11cc5c:
/*  f11cc5c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11cc60:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f11cc64:	03e00008 */ 	jr	$ra
/*  f11cc68:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11cc6c
/*  f11cc6c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f11cc70:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f11cc74:	83ae0023 */ 	lb	$t6,0x23($sp)
/*  f11cc78:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11cc7c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11cc80:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f11cc84:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f11cc88:	15c10003 */ 	bne	$t6,$at,.L0f11cc98
/*  f11cc8c:	afa7002c */ 	sw	$a3,0x2c($sp)
/*  f11cc90:	1000000a */ 	beqz	$zero,.L0f11ccbc
/*  f11cc94:	00002025 */ 	or	$a0,$zero,$zero
.L0f11cc98:
/*  f11cc98:	83af0023 */ 	lb	$t7,0x23($sp)
/*  f11cc9c:	3c19800a */ 	lui	$t9,%hi(var800a3180)
/*  f11cca0:	27393180 */ 	addiu	$t9,$t9,%lo(var800a3180)
/*  f11cca4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11cca8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11ccac:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11ccb0:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11ccb4:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f11ccb8:	03192021 */ 	addu	$a0,$t8,$t9
.L0f11ccbc:
/*  f11ccbc:	97a8002e */ 	lhu	$t0,0x2e($sp)
/*  f11ccc0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11ccc4:	97a60026 */ 	lhu	$a2,0x26($sp)
/*  f11ccc8:	8fa70028 */ 	lw	$a3,0x28($sp)
/*  f11cccc:	0c0144ec */ 	jal	func000513b0
/*  f11ccd0:	afa80010 */ 	sw	$t0,0x10($sp)
/*  f11ccd4:	10400005 */ 	beqz	$v0,.L0f11ccec
/*  f11ccd8:	00402025 */ 	or	$a0,$v0,$zero
/*  f11ccdc:	0fc472e7 */ 	jal	func0f11cb9c
/*  f11cce0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11cce4:	10000002 */ 	beqz	$zero,.L0f11ccf0
/*  f11cce8:	00001025 */ 	or	$v0,$zero,$zero
.L0f11ccec:
/*  f11ccec:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11ccf0:
/*  f11ccf0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11ccf4:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f11ccf8:	03e00008 */ 	jr	$ra
/*  f11ccfc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11cd00
/*  f11cd00:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f11cd04:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f11cd08:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11cd0c:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f11cd10:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f11cd14:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f11cd18:	00004025 */ 	or	$t0,$zero,$zero
/*  f11cd1c:	27a40048 */ 	addiu	$a0,$sp,0x48
/*  f11cd20:	27a20028 */ 	addiu	$v0,$sp,0x28
/*  f11cd24:	2403000a */ 	addiu	$v1,$zero,0xa
.L0f11cd28:
/*  f11cd28:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11cd2c:	0044082b */ 	sltu	$at,$v0,$a0
/*  f11cd30:	1420fffd */ 	bnez	$at,.L0f11cd28
/*  f11cd34:	a043ffff */ 	sb	$v1,-0x1($v0)
/*  f11cd38:	83a4004b */ 	lb	$a0,0x4b($sp)
/*  f11cd3c:	00002825 */ 	or	$a1,$zero,$zero
/*  f11cd40:	27a60028 */ 	addiu	$a2,$sp,0x28
/*  f11cd44:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11cd48:	0fc4731b */ 	jal	func0f11cc6c
/*  f11cd4c:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f11cd50:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f11cd54:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f11cd58:	00001825 */ 	or	$v1,$zero,$zero
/*  f11cd5c:	05c00018 */ 	bltz	$t6,.L0f11cdc0
/*  f11cd60:	27a20028 */ 	addiu	$v0,$sp,0x28
/*  f11cd64:	97a4004e */ 	lhu	$a0,0x4e($sp)
/*  f11cd68:	3c01ffff */ 	lui	$at,0xffff
/*  f11cd6c:	34216000 */ 	ori	$at,$at,0x6000
/*  f11cd70:	00812021 */ 	addu	$a0,$a0,$at
/*  f11cd74:	04810003 */ 	bgez	$a0,.L0f11cd84
/*  f11cd78:	00047b43 */ 	sra	$t7,$a0,0xd
/*  f11cd7c:	24811fff */ 	addiu	$at,$a0,0x1fff
/*  f11cd80:	00017b43 */ 	sra	$t7,$at,0xd
.L0f11cd84:
/*  f11cd84:	01e02025 */ 	or	$a0,$t7,$zero
/*  f11cd88:	27a30048 */ 	addiu	$v1,$sp,0x48
.L0f11cd8c:
/*  f11cd8c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11cd90:	1443fffe */ 	bne	$v0,$v1,.L0f11cd8c
/*  f11cd94:	a044ffff */ 	sb	$a0,-0x1($v0)
/*  f11cd98:	83a4004b */ 	lb	$a0,0x4b($sp)
/*  f11cd9c:	24054000 */ 	addiu	$a1,$zero,0x4000
/*  f11cda0:	27a60028 */ 	addiu	$a2,$sp,0x28
/*  f11cda4:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11cda8:	0fc4731b */ 	jal	func0f11cc6c
/*  f11cdac:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f11cdb0:	10400004 */ 	beqz	$v0,.L0f11cdc4
/*  f11cdb4:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f11cdb8:	10000002 */ 	beqz	$zero,.L0f11cdc4
/*  f11cdbc:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f11cdc0:
/*  f11cdc0:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f11cdc4:
/*  f11cdc4:	11000009 */ 	beqz	$t0,.L0f11cdec
/*  f11cdc8:	83a4004b */ 	lb	$a0,0x4b($sp)
/*  f11cdcc:	97a5004e */ 	lhu	$a1,0x4e($sp)
/*  f11cdd0:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f11cdd4:	97a70056 */ 	lhu	$a3,0x56($sp)
/*  f11cdd8:	0fc4731b */ 	jal	func0f11cc6c
/*  f11cddc:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f11cde0:	10400002 */ 	beqz	$v0,.L0f11cdec
/*  f11cde4:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f11cde8:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f11cdec:
/*  f11cdec:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11cdf0:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f11cdf4:	01001025 */ 	or	$v0,$t0,$zero
/*  f11cdf8:	03e00008 */ 	jr	$ra
/*  f11cdfc:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11ce00
/*  f11ce00:	27bdffb8 */ 	addiu	$sp,$sp,-72
/*  f11ce04:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11ce08:	afa40048 */ 	sw	$a0,0x48($sp)
/*  f11ce0c:	afa5004c */ 	sw	$a1,0x4c($sp)
/*  f11ce10:	afa60050 */ 	sw	$a2,0x50($sp)
/*  f11ce14:	afa70054 */ 	sw	$a3,0x54($sp)
/*  f11ce18:	00004025 */ 	or	$t0,$zero,$zero
/*  f11ce1c:	27a20028 */ 	addiu	$v0,$sp,0x28
/*  f11ce20:	27a30048 */ 	addiu	$v1,$sp,0x48
.L0f11ce24:
/*  f11ce24:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11ce28:	0043082b */ 	sltu	$at,$v0,$v1
/*  f11ce2c:	1420fffd */ 	bnez	$at,.L0f11ce24
/*  f11ce30:	a040ffff */ 	sb	$zero,-0x1($v0)
/*  f11ce34:	83a4004b */ 	lb	$a0,0x4b($sp)
/*  f11ce38:	00002825 */ 	or	$a1,$zero,$zero
/*  f11ce3c:	27a60028 */ 	addiu	$a2,$sp,0x28
/*  f11ce40:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11ce44:	0fc4731b */ 	jal	func0f11cc6c
/*  f11ce48:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f11ce4c:	8fae0058 */ 	lw	$t6,0x58($sp)
/*  f11ce50:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f11ce54:	27a20028 */ 	addiu	$v0,$sp,0x28
/*  f11ce58:	11c00017 */ 	beqz	$t6,.L0f11ceb8
/*  f11ce5c:	27a30048 */ 	addiu	$v1,$sp,0x48
.L0f11ce60:
/*  f11ce60:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11ce64:	1443fffe */ 	bne	$v0,$v1,.L0f11ce60
/*  f11ce68:	a040ffff */ 	sb	$zero,-0x1($v0)
/*  f11ce6c:	97af004e */ 	lhu	$t7,0x4e($sp)
/*  f11ce70:	3c01ffff */ 	lui	$at,0xffff
/*  f11ce74:	34216000 */ 	ori	$at,$at,0x6000
/*  f11ce78:	01e1c021 */ 	addu	$t8,$t7,$at
/*  f11ce7c:	07010003 */ 	bgez	$t8,.L0f11ce8c
/*  f11ce80:	0018cb43 */ 	sra	$t9,$t8,0xd
/*  f11ce84:	27011fff */ 	addiu	$at,$t8,0x1fff
/*  f11ce88:	0001cb43 */ 	sra	$t9,$at,0xd
.L0f11ce8c:
/*  f11ce8c:	a3b90047 */ 	sb	$t9,0x47($sp)
/*  f11ce90:	83a4004b */ 	lb	$a0,0x4b($sp)
/*  f11ce94:	24054000 */ 	addiu	$a1,$zero,0x4000
/*  f11ce98:	27a60028 */ 	addiu	$a2,$sp,0x28
/*  f11ce9c:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11cea0:	0fc4731b */ 	jal	func0f11cc6c
/*  f11cea4:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f11cea8:	10400004 */ 	beqz	$v0,.L0f11cebc
/*  f11ceac:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f11ceb0:	10000002 */ 	beqz	$zero,.L0f11cebc
/*  f11ceb4:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f11ceb8:
/*  f11ceb8:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f11cebc:
/*  f11cebc:	11000009 */ 	beqz	$t0,.L0f11cee4
/*  f11cec0:	83a4004b */ 	lb	$a0,0x4b($sp)
/*  f11cec4:	97a5004e */ 	lhu	$a1,0x4e($sp)
/*  f11cec8:	8fa60050 */ 	lw	$a2,0x50($sp)
/*  f11cecc:	97a70056 */ 	lhu	$a3,0x56($sp)
/*  f11ced0:	0fc472f6 */ 	jal	func0f11cbd8
/*  f11ced4:	afa80024 */ 	sw	$t0,0x24($sp)
/*  f11ced8:	10400002 */ 	beqz	$v0,.L0f11cee4
/*  f11cedc:	8fa80024 */ 	lw	$t0,0x24($sp)
/*  f11cee0:	24080001 */ 	addiu	$t0,$zero,0x1
.L0f11cee4:
/*  f11cee4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11cee8:	27bd0048 */ 	addiu	$sp,$sp,0x48
/*  f11ceec:	01001025 */ 	or	$v0,$t0,$zero
/*  f11cef0:	03e00008 */ 	jr	$ra
/*  f11cef4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11cef8:	27bdff30 */ 	addiu	$sp,$sp,-208
/*  f11cefc:	afa400d0 */ 	sw	$a0,0xd0($sp)
/*  f11cf00:	83ae00d3 */ 	lb	$t6,0xd3($sp)
/*  f11cf04:	3c18800a */ 	lui	$t8,%hi(var800a2380)
/*  f11cf08:	27182380 */ 	addiu	$t8,$t8,%lo(var800a2380)
/*  f11cf0c:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f11cf10:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11cf14:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11cf18:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11cf1c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11cf20:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f11cf24:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11cf28:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11cf2c:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11cf30:	01f84021 */ 	addu	$t0,$t7,$t8
/*  f11cf34:	8d190000 */ 	lw	$t9,0x0($t0)
/*  f11cf38:	24010003 */ 	addiu	$at,$zero,0x3
/*  f11cf3c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11cf40:	1721006c */ 	bne	$t9,$at,.L0f11d0f4
/*  f11cf44:	27a200ac */ 	addiu	$v0,$sp,0xac
/*  f11cf48:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f11cf4c:	24030002 */ 	addiu	$v1,$zero,0x2
.L0f11cf50:
/*  f11cf50:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11cf54:	0044082b */ 	sltu	$at,$v0,$a0
/*  f11cf58:	1420fffd */ 	bnez	$at,.L0f11cf50
/*  f11cf5c:	a043ffff */ 	sb	$v1,-0x1($v0)
/*  f11cf60:	83a400d3 */ 	lb	$a0,0xd3($sp)
/*  f11cf64:	24054000 */ 	addiu	$a1,$zero,0x4000
/*  f11cf68:	27a600ac */ 	addiu	$a2,$sp,0xac
/*  f11cf6c:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11cf70:	0fc4731b */ 	jal	func0f11cc6c
/*  f11cf74:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f11cf78:	14400003 */ 	bnez	$v0,.L0f11cf88
/*  f11cf7c:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f11cf80:	1000005f */ 	beqz	$zero,.L0f11d100
/*  f11cf84:	00001025 */ 	or	$v0,$zero,$zero
.L0f11cf88:
/*  f11cf88:	83a400d3 */ 	lb	$a0,0xd3($sp)
/*  f11cf8c:	3405afe0 */ 	dli	$a1,0xafe0
/*  f11cf90:	27a6008c */ 	addiu	$a2,$sp,0x8c
/*  f11cf94:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11cf98:	0fc472f6 */ 	jal	func0f11cbd8
/*  f11cf9c:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f11cfa0:	14400003 */ 	bnez	$v0,.L0f11cfb0
/*  f11cfa4:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f11cfa8:	10000055 */ 	beqz	$zero,.L0f11d100
/*  f11cfac:	00001025 */ 	or	$v0,$zero,$zero
.L0f11cfb0:
/*  f11cfb0:	27a200ac */ 	addiu	$v0,$sp,0xac
/*  f11cfb4:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f11cfb8:	24030008 */ 	addiu	$v1,$zero,0x8
.L0f11cfbc:
/*  f11cfbc:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11cfc0:	0044082b */ 	sltu	$at,$v0,$a0
/*  f11cfc4:	1420fffd */ 	bnez	$at,.L0f11cfbc
/*  f11cfc8:	a043ffff */ 	sb	$v1,-0x1($v0)
/*  f11cfcc:	83a400d3 */ 	lb	$a0,0xd3($sp)
/*  f11cfd0:	24054000 */ 	addiu	$a1,$zero,0x4000
/*  f11cfd4:	27a600ac */ 	addiu	$a2,$sp,0xac
/*  f11cfd8:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11cfdc:	0fc4731b */ 	jal	func0f11cc6c
/*  f11cfe0:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f11cfe4:	14400003 */ 	bnez	$v0,.L0f11cff4
/*  f11cfe8:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f11cfec:	10000044 */ 	beqz	$zero,.L0f11d100
/*  f11cff0:	00001025 */ 	or	$v0,$zero,$zero
.L0f11cff4:
/*  f11cff4:	83a400d3 */ 	lb	$a0,0xd3($sp)
/*  f11cff8:	3405bfe0 */ 	dli	$a1,0xbfe0
/*  f11cffc:	27a6006c */ 	addiu	$a2,$sp,0x6c
/*  f11d000:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11d004:	0fc472f6 */ 	jal	func0f11cbd8
/*  f11d008:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f11d00c:	14400003 */ 	bnez	$v0,.L0f11d01c
/*  f11d010:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f11d014:	1000003a */ 	beqz	$zero,.L0f11d100
/*  f11d018:	00001025 */ 	or	$v0,$zero,$zero
.L0f11d01c:
/*  f11d01c:	27a200ac */ 	addiu	$v0,$sp,0xac
/*  f11d020:	27a400cc */ 	addiu	$a0,$sp,0xcc
/*  f11d024:	24030010 */ 	addiu	$v1,$zero,0x10
.L0f11d028:
/*  f11d028:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11d02c:	0044082b */ 	sltu	$at,$v0,$a0
/*  f11d030:	1420fffd */ 	bnez	$at,.L0f11d028
/*  f11d034:	a043ffff */ 	sb	$v1,-0x1($v0)
/*  f11d038:	83a400d3 */ 	lb	$a0,0xd3($sp)
/*  f11d03c:	24054000 */ 	addiu	$a1,$zero,0x4000
/*  f11d040:	27a600ac */ 	addiu	$a2,$sp,0xac
/*  f11d044:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11d048:	0fc4731b */ 	jal	func0f11cc6c
/*  f11d04c:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f11d050:	14400003 */ 	bnez	$v0,.L0f11d060
/*  f11d054:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f11d058:	10000029 */ 	beqz	$zero,.L0f11d100
/*  f11d05c:	00001025 */ 	or	$v0,$zero,$zero
.L0f11d060:
/*  f11d060:	27a2002c */ 	addiu	$v0,$sp,0x2c
/*  f11d064:	27a3006c */ 	addiu	$v1,$sp,0x6c
.L0f11d068:
/*  f11d068:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11d06c:	1443fffe */ 	bne	$v0,$v1,.L0f11d068
/*  f11d070:	a040ffff */ 	sb	$zero,-0x1($v0)
/*  f11d074:	93a900a6 */ 	lbu	$t1,0xa6($sp)
/*  f11d078:	a10902ba */ 	sb	$t1,0x2ba($t0)
/*  f11d07c:	93aa0086 */ 	lbu	$t2,0x86($sp)
/*  f11d080:	312300ff */ 	andi	$v1,$t1,0xff
/*  f11d084:	314200ff */ 	andi	$v0,$t2,0xff
/*  f11d088:	14430003 */ 	bne	$v0,$v1,.L0f11d098
/*  f11d08c:	a10a02bb */ 	sb	$t2,0x2bb($t0)
/*  f11d090:	10000002 */ 	beqz	$zero,.L0f11d09c
/*  f11d094:	a10302b9 */ 	sb	$v1,0x2b9($t0)
.L0f11d098:
/*  f11d098:	a10202b9 */ 	sb	$v0,0x2b9($t0)
.L0f11d09c:
/*  f11d09c:	0fc52a9c */ 	jal	func0f14aa70
/*  f11d0a0:	afa80020 */ 	sw	$t0,0x20($sp)
/*  f11d0a4:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f11d0a8:	27a4002c */ 	addiu	$a0,$sp,0x2c
/*  f11d0ac:	00403025 */ 	or	$a2,$v0,$zero
/*  f11d0b0:	0fc47446 */ 	jal	func0f11d118
/*  f11d0b4:	910502b9 */ 	lbu	$a1,0x2b9($t0)
/*  f11d0b8:	83a400d3 */ 	lb	$a0,0xd3($sp)
/*  f11d0bc:	0fc4745d */ 	jal	func0f11d174
/*  f11d0c0:	27a5002c */ 	addiu	$a1,$sp,0x2c
/*  f11d0c4:	93ab002c */ 	lbu	$t3,0x2c($sp)
/*  f11d0c8:	83a400d3 */ 	lb	$a0,0xd3($sp)
/*  f11d0cc:	3405a000 */ 	dli	$a1,0xa000
/*  f11d0d0:	356c0001 */ 	ori	$t4,$t3,0x1
/*  f11d0d4:	a3ac002c */ 	sb	$t4,0x2c($sp)
/*  f11d0d8:	27a6002c */ 	addiu	$a2,$sp,0x2c
/*  f11d0dc:	0fc4731b */ 	jal	func0f11cc6c
/*  f11d0e0:	24070040 */ 	addiu	$a3,$zero,0x40
/*  f11d0e4:	14400003 */ 	bnez	$v0,.L0f11d0f4
/*  f11d0e8:	8fa80020 */ 	lw	$t0,0x20($sp)
/*  f11d0ec:	10000004 */ 	beqz	$zero,.L0f11d100
/*  f11d0f0:	00001025 */ 	or	$v0,$zero,$zero
.L0f11d0f4:
/*  f11d0f4:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f11d0f8:	ad0d0008 */ 	sw	$t5,0x8($t0)
/*  f11d0fc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11d100:
/*  f11d100:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11d104:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
/*  f11d108:	03e00008 */ 	jr	$ra
/*  f11d10c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11d110:	03e00008 */ 	jr	$ra
/*  f11d114:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11d118
/*  f11d118:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f11d11c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11d120:	afa5001c */ 	sw	$a1,0x1c($sp)
/*  f11d124:	240e0002 */ 	addiu	$t6,$zero,0x2
/*  f11d128:	240f00e4 */ 	addiu	$t7,$zero,0xe4
/*  f11d12c:	24180010 */ 	addiu	$t8,$zero,0x10
/*  f11d130:	a08e0000 */ 	sb	$t6,0x0($a0)
/*  f11d134:	a08f0001 */ 	sb	$t7,0x1($a0)
/*  f11d138:	a0980002 */ 	sb	$t8,0x2($a0)
/*  f11d13c:	a0800003 */ 	sb	$zero,0x3($a0)
/*  f11d140:	93a2001f */ 	lbu	$v0,0x1f($sp)
/*  f11d144:	00c02825 */ 	or	$a1,$a2,$zero
/*  f11d148:	24840006 */ 	addiu	$a0,$a0,0x6
/*  f11d14c:	3048003f */ 	andi	$t0,$v0,0x3f
/*  f11d150:	25090080 */ 	addiu	$t1,$t0,0x80
/*  f11d154:	30590007 */ 	andi	$t9,$v0,0x7
/*  f11d158:	a099fffe */ 	sb	$t9,-0x2($a0)
/*  f11d15c:	0fc47485 */ 	jal	func0f11d214
/*  f11d160:	a089ffff */ 	sb	$t1,-0x1($a0)
/*  f11d164:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11d168:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f11d16c:	03e00008 */ 	jr	$ra
/*  f11d170:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11d174
/*  f11d174:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f11d178:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11d17c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11d180:	00a08025 */ 	or	$s0,$a1,$zero
/*  f11d184:	0fc52a9c */ 	jal	func0f14aa70
/*  f11d188:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f11d18c:	83ae002b */ 	lb	$t6,0x2b($sp)
/*  f11d190:	3c05800a */ 	lui	$a1,0x800a
/*  f11d194:	02002025 */ 	or	$a0,$s0,$zero
/*  f11d198:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f11d19c:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11d1a0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11d1a4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11d1a8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11d1ac:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f11d1b0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11d1b4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11d1b8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11d1bc:	00af2821 */ 	addu	$a1,$a1,$t7
/*  f11d1c0:	90a52639 */ 	lbu	$a1,0x2639($a1)
/*  f11d1c4:	0fc47446 */ 	jal	func0f11d118
/*  f11d1c8:	00403025 */ 	or	$a2,$v0,$zero
/*  f11d1cc:	0fc52b4e */ 	jal	func0f14ad38
/*  f11d1d0:	83a4002b */ 	lb	$a0,0x2b($sp)
/*  f11d1d4:	a3a20027 */ 	sb	$v0,0x27($sp)
/*  f11d1d8:	0fc52b45 */ 	jal	func0f14ad14
/*  f11d1dc:	83a4002b */ 	lb	$a0,0x2b($sp)
/*  f11d1e0:	92180001 */ 	lbu	$t8,0x1($s0)
/*  f11d1e4:	93a80027 */ 	lbu	$t0,0x27($sp)
/*  f11d1e8:	00025a03 */ 	sra	$t3,$v0,0x8
/*  f11d1ec:	331900e0 */ 	andi	$t9,$t8,0xe0
/*  f11d1f0:	03284821 */ 	addu	$t1,$t9,$t0
/*  f11d1f4:	a2090001 */ 	sb	$t1,0x1($s0)
/*  f11d1f8:	a20b0002 */ 	sb	$t3,0x2($s0)
/*  f11d1fc:	a2020003 */ 	sb	$v0,0x3($s0)
/*  f11d200:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11d204:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f11d208:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f11d20c:	03e00008 */ 	jr	$ra
/*  f11d210:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11d214
/*  f11d214:	3c0f7f1b */ 	lui	$t7,%hi(var7f1b494c)
/*  f11d218:	27bdfe48 */ 	addiu	$sp,$sp,-440
/*  f11d21c:	25ef494c */ 	addiu	$t7,$t7,%lo(var7f1b494c)
/*  f11d220:	00803025 */ 	or	$a2,$a0,$zero
/*  f11d224:	25ed0108 */ 	addiu	$t5,$t7,0x108
/*  f11d228:	27ae00a8 */ 	addiu	$t6,$sp,0xa8
.L0f11d22c:
/*  f11d22c:	8de10000 */ 	lw	$at,0x0($t7)
/*  f11d230:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f11d234:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f11d238:	adc1fff4 */ 	sw	$at,-0xc($t6)
/*  f11d23c:	8de1fff8 */ 	lw	$at,-0x8($t7)
/*  f11d240:	adc1fff8 */ 	sw	$at,-0x8($t6)
/*  f11d244:	8de1fffc */ 	lw	$at,-0x4($t7)
/*  f11d248:	15edfff8 */ 	bne	$t7,$t5,.L0f11d22c
/*  f11d24c:	adc1fffc */ 	sw	$at,-0x4($t6)
/*  f11d250:	8de10000 */ 	lw	$at,0x0($t7)
/*  f11d254:	8ded0004 */ 	lw	$t5,0x4($t7)
/*  f11d258:	3c187f1b */ 	lui	$t8,%hi(var7f1b4a5c)
/*  f11d25c:	27184a5c */ 	addiu	$t8,$t8,%lo(var7f1b4a5c)
/*  f11d260:	adc10000 */ 	sw	$at,0x0($t6)
/*  f11d264:	adcd0004 */ 	sw	$t5,0x4($t6)
/*  f11d268:	270e003c */ 	addiu	$t6,$t8,0x3c
/*  f11d26c:	27b90068 */ 	addiu	$t9,$sp,0x68
.L0f11d270:
/*  f11d270:	8f010000 */ 	lw	$at,0x0($t8)
/*  f11d274:	2718000c */ 	addiu	$t8,$t8,0xc
/*  f11d278:	2739000c */ 	addiu	$t9,$t9,0xc
/*  f11d27c:	af21fff4 */ 	sw	$at,-0xc($t9)
/*  f11d280:	8f01fff8 */ 	lw	$at,-0x8($t8)
/*  f11d284:	af21fff8 */ 	sw	$at,-0x8($t9)
/*  f11d288:	8f01fffc */ 	lw	$at,-0x4($t8)
/*  f11d28c:	170efff8 */ 	bne	$t8,$t6,.L0f11d270
/*  f11d290:	af21fffc */ 	sw	$at,-0x4($t9)
/*  f11d294:	8f010000 */ 	lw	$at,0x0($t8)
/*  f11d298:	3c0d7f1b */ 	lui	$t5,%hi(var7f1b4a9c)
/*  f11d29c:	25ad4a9c */ 	addiu	$t5,$t5,%lo(var7f1b4a9c)
/*  f11d2a0:	af210000 */ 	sw	$at,0x0($t9)
/*  f11d2a4:	25b9003c */ 	addiu	$t9,$t5,0x3c
/*  f11d2a8:	27af0028 */ 	addiu	$t7,$sp,0x28
.L0f11d2ac:
/*  f11d2ac:	8da10000 */ 	lw	$at,0x0($t5)
/*  f11d2b0:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f11d2b4:	25ef000c */ 	addiu	$t7,$t7,0xc
/*  f11d2b8:	ade1fff4 */ 	sw	$at,-0xc($t7)
/*  f11d2bc:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*  f11d2c0:	ade1fff8 */ 	sw	$at,-0x8($t7)
/*  f11d2c4:	8da1fffc */ 	lw	$at,-0x4($t5)
/*  f11d2c8:	15b9fff8 */ 	bne	$t5,$t9,.L0f11d2ac
/*  f11d2cc:	ade1fffc */ 	sw	$at,-0x4($t7)
/*  f11d2d0:	8da10000 */ 	lw	$at,0x0($t5)
/*  f11d2d4:	0005c100 */ 	sll	$t8,$a1,0x4
/*  f11d2d8:	27ae00a8 */ 	addiu	$t6,$sp,0xa8
/*  f11d2dc:	ade10000 */ 	sw	$at,0x0($t7)
/*  f11d2e0:	3c013f00 */ 	lui	$at,0x3f00
/*  f11d2e4:	44816000 */ 	mtc1	$at,$f12
/*  f11d2e8:	3c013d80 */ 	lui	$at,0x3d80
/*  f11d2ec:	44811000 */ 	mtc1	$at,$f2
/*  f11d2f0:	030e1821 */ 	addu	$v1,$t8,$t6
/*  f11d2f4:	00001025 */ 	or	$v0,$zero,$zero
/*  f11d2f8:	240c0003 */ 	addiu	$t4,$zero,0x3
/*  f11d2fc:	27ab0068 */ 	addiu	$t3,$sp,0x68
/*  f11d300:	240a0004 */ 	addiu	$t2,$zero,0x4
.L0f11d304:
/*  f11d304:	c4640004 */ 	lwc1	$f4,0x4($v1)
/*  f11d308:	c4660000 */ 	lwc1	$f6,0x0($v1)
/*  f11d30c:	00c02825 */ 	or	$a1,$a2,$zero
/*  f11d310:	27a80028 */ 	addiu	$t0,$sp,0x28
/*  f11d314:	46062201 */ 	sub.s	$f8,$f4,$f6
/*  f11d318:	46024002 */ 	mul.s	$f0,$f8,$f2
/*  f11d31c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11d320:
/*  f11d320:	00002025 */ 	or	$a0,$zero,$zero
/*  f11d324:	00a23821 */ 	addu	$a3,$a1,$v0
/*  f11d328:	01004825 */ 	or	$t1,$t0,$zero
.L0f11d32c:
/*  f11d32c:	c52a0000 */ 	lwc1	$f10,0x0($t1)
/*  f11d330:	c4720000 */ 	lwc1	$f18,0x0($v1)
/*  f11d334:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f11d338:	46005402 */ 	mul.s	$f16,$f10,$f0
/*  f11d33c:	46126100 */ 	add.s	$f4,$f12,$f18
/*  f11d340:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f11d344:	25290004 */ 	addiu	$t1,$t1,0x4
/*  f11d348:	3c014f00 */ 	lui	$at,0x4f00
/*  f11d34c:	46048180 */ 	add.s	$f6,$f16,$f4
/*  f11d350:	4459f800 */ 	cfc1	$t9,$31
/*  f11d354:	44cdf800 */ 	ctc1	$t5,$31
/*  f11d358:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11d35c:	46003224 */ 	cvt.w.s	$f8,$f6
/*  f11d360:	444df800 */ 	cfc1	$t5,$31
/*  f11d364:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11d368:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f11d36c:	51a00013 */ 	beqzl	$t5,.L0f11d3bc
/*  f11d370:	440d4000 */ 	mfc1	$t5,$f8
/*  f11d374:	44814000 */ 	mtc1	$at,$f8
/*  f11d378:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f11d37c:	46083201 */ 	sub.s	$f8,$f6,$f8
/*  f11d380:	44cdf800 */ 	ctc1	$t5,$31
/*  f11d384:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11d388:	46004224 */ 	cvt.w.s	$f8,$f8
/*  f11d38c:	444df800 */ 	cfc1	$t5,$31
/*  f11d390:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11d394:	31ad0078 */ 	andi	$t5,$t5,0x78
/*  f11d398:	15a00005 */ 	bnez	$t5,.L0f11d3b0
/*  f11d39c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11d3a0:	440d4000 */ 	mfc1	$t5,$f8
/*  f11d3a4:	3c018000 */ 	lui	$at,0x8000
/*  f11d3a8:	10000007 */ 	beqz	$zero,.L0f11d3c8
/*  f11d3ac:	01a16825 */ 	or	$t5,$t5,$at
.L0f11d3b0:
/*  f11d3b0:	10000005 */ 	beqz	$zero,.L0f11d3c8
/*  f11d3b4:	240dffff */ 	addiu	$t5,$zero,-1
/*  f11d3b8:	440d4000 */ 	mfc1	$t5,$f8
.L0f11d3bc:
/*  f11d3bc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11d3c0:	05a0fffb */ 	bltz	$t5,.L0f11d3b0
/*  f11d3c4:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11d3c8:
/*  f11d3c8:	44d9f800 */ 	ctc1	$t9,$31
/*  f11d3cc:	24e70003 */ 	addiu	$a3,$a3,0x3
/*  f11d3d0:	148affd6 */ 	bne	$a0,$t2,.L0f11d32c
/*  f11d3d4:	a0edfffd */ 	sb	$t5,-0x3($a3)
/*  f11d3d8:	25080010 */ 	addiu	$t0,$t0,0x10
/*  f11d3dc:	150bffd0 */ 	bne	$t0,$t3,.L0f11d320
/*  f11d3e0:	24a5000c */ 	addiu	$a1,$a1,0xc
/*  f11d3e4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11d3e8:	144cffc6 */ 	bne	$v0,$t4,.L0f11d304
/*  f11d3ec:	24630004 */ 	addiu	$v1,$v1,0x4
/*  f11d3f0:	03e00008 */ 	jr	$ra
/*  f11d3f4:	27bd01b8 */ 	addiu	$sp,$sp,0x1b8
);

GLOBAL_ASM(
glabel func0f11d3f8
/*  f11d3f8:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11d3fc:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f11d400:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11d404:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d408:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d40c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d410:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d414:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11d418:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d41c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d420:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11d424:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f11d428:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d42c:	03191021 */ 	addu	$v0,$t8,$t9
/*  f11d430:	8c480000 */ 	lw	$t0,0x0($v0)
/*  f11d434:	24010003 */ 	addiu	$at,$zero,0x3
/*  f11d438:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11d43c:	5501000c */ 	bnel	$t0,$at,.L0f11d470
/*  f11d440:	00001025 */ 	or	$v0,$zero,$zero
/*  f11d444:	8c430010 */ 	lw	$v1,0x10($v0)
/*  f11d448:	2401000b */ 	addiu	$at,$zero,0xb
/*  f11d44c:	10610005 */ 	beq	$v1,$at,.L0f11d464
/*  f11d450:	2401000c */ 	addiu	$at,$zero,0xc
/*  f11d454:	10610003 */ 	beq	$v1,$at,.L0f11d464
/*  f11d458:	2401000d */ 	addiu	$at,$zero,0xd
/*  f11d45c:	54610004 */ 	bnel	$v1,$at,.L0f11d470
/*  f11d460:	00001025 */ 	or	$v0,$zero,$zero
.L0f11d464:
/*  f11d464:	03e00008 */ 	jr	$ra
/*  f11d468:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11d46c:	00001025 */ 	or	$v0,$zero,$zero
.L0f11d470:
/*  f11d470:	03e00008 */ 	jr	$ra
/*  f11d474:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11d478
/*  f11d478:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11d47c:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f11d480:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11d484:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d488:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d48c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d490:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d494:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11d498:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d49c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d4a0:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11d4a4:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f11d4a8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d4ac:	03191821 */ 	addu	$v1,$t8,$t9
/*  f11d4b0:	8c680008 */ 	lw	$t0,0x8($v1)
/*  f11d4b4:	2401000b */ 	addiu	$at,$zero,0xb
/*  f11d4b8:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11d4bc:	15010004 */ 	bne	$t0,$at,.L0f11d4d0
/*  f11d4c0:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f11d4c4:	ac690008 */ 	sw	$t1,0x8($v1)
/*  f11d4c8:	03e00008 */ 	jr	$ra
/*  f11d4cc:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11d4d0:
/*  f11d4d0:	00001025 */ 	or	$v0,$zero,$zero
/*  f11d4d4:	03e00008 */ 	jr	$ra
/*  f11d4d8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11d4dc
/*  f11d4dc:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11d4e0:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f11d4e4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11d4e8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d4ec:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d4f0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d4f4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d4f8:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11d4fc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d500:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d504:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11d508:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f11d50c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d510:	03191021 */ 	addu	$v0,$t8,$t9
/*  f11d514:	8c430008 */ 	lw	$v1,0x8($v0)
/*  f11d518:	24010001 */ 	addiu	$at,$zero,0x1
/*  f11d51c:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11d520:	10610003 */ 	beq	$v1,$at,.L0f11d530
/*  f11d524:	24080002 */ 	addiu	$t0,$zero,0x2
/*  f11d528:	14600003 */ 	bnez	$v1,.L0f11d538
/*  f11d52c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11d530:
/*  f11d530:	ac480008 */ 	sw	$t0,0x8($v0)
/*  f11d534:	ac400270 */ 	sw	$zero,0x270($v0)
.L0f11d538:
/*  f11d538:	03e00008 */ 	jr	$ra
/*  f11d53c:	00001025 */ 	or	$v0,$zero,$zero
);

GLOBAL_ASM(
glabel func0f11d540
/*  f11d540:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11d544:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f11d548:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11d54c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d550:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d554:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d558:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d55c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11d560:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d564:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d568:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11d56c:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f11d570:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d574:	03191821 */ 	addu	$v1,$t8,$t9
/*  f11d578:	8c620008 */ 	lw	$v0,0x8($v1)
/*  f11d57c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f11d580:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11d584:	10410003 */ 	beq	$v0,$at,.L0f11d594
/*  f11d588:	24080004 */ 	addiu	$t0,$zero,0x4
/*  f11d58c:	54400006 */ 	bnezl	$v0,.L0f11d5a8
/*  f11d590:	00001025 */ 	or	$v0,$zero,$zero
.L0f11d594:
/*  f11d594:	ac680008 */ 	sw	$t0,0x8($v1)
/*  f11d598:	ac650270 */ 	sw	$a1,0x270($v1)
/*  f11d59c:	03e00008 */ 	jr	$ra
/*  f11d5a0:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11d5a4:	00001025 */ 	or	$v0,$zero,$zero
.L0f11d5a8:
/*  f11d5a8:	03e00008 */ 	jr	$ra
/*  f11d5ac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11d5b0
/*  f11d5b0:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11d5b4:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f11d5b8:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11d5bc:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d5c0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d5c4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d5c8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d5cc:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11d5d0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d5d4:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d5d8:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11d5dc:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f11d5e0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d5e4:	03191821 */ 	addu	$v1,$t8,$t9
/*  f11d5e8:	8c620008 */ 	lw	$v0,0x8($v1)
/*  f11d5ec:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11d5f0:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11d5f4:	10a20003 */ 	beq	$a1,$v0,.L0f11d604
/*  f11d5f8:	24080004 */ 	addiu	$t0,$zero,0x4
/*  f11d5fc:	54400006 */ 	bnezl	$v0,.L0f11d618
/*  f11d600:	00001025 */ 	or	$v0,$zero,$zero
.L0f11d604:
/*  f11d604:	ac680008 */ 	sw	$t0,0x8($v1)
/*  f11d608:	ac650270 */ 	sw	$a1,0x270($v1)
/*  f11d60c:	03e00008 */ 	jr	$ra
/*  f11d610:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11d614:	00001025 */ 	or	$v0,$zero,$zero
.L0f11d618:
/*  f11d618:	03e00008 */ 	jr	$ra
/*  f11d61c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11d620
/*  f11d620:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11d624:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f11d628:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11d62c:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d630:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d634:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d638:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d63c:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11d640:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d644:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d648:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11d64c:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f11d650:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d654:	03191021 */ 	addu	$v0,$t8,$t9
/*  f11d658:	8c480010 */ 	lw	$t0,0x10($v0)
/*  f11d65c:	2401000b */ 	addiu	$at,$zero,0xb
/*  f11d660:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11d664:	15010002 */ 	bne	$t0,$at,.L0f11d670
/*  f11d668:	2409000c */ 	addiu	$t1,$zero,0xc
/*  f11d66c:	ac490010 */ 	sw	$t1,0x10($v0)
.L0f11d670:
/*  f11d670:	03e00008 */ 	jr	$ra
/*  f11d674:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11d678:	03e00008 */ 	jr	$ra
/*  f11d67c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11d680:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f11d684:	afa40028 */ 	sw	$a0,0x28($sp)
/*  f11d688:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11d68c:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f11d690:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f11d694:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f11d698:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d69c:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f11d6a0:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d6a4:	0304c021 */ 	addu	$t8,$t8,$a0
/*  f11d6a8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d6ac:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f11d6b0:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11d6b4:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f11d6b8:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d6bc:	03194021 */ 	addu	$t0,$t8,$t9
/*  f11d6c0:	8d02000c */ 	lw	$v0,0xc($t0)
/*  f11d6c4:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11d6c8:	00001825 */ 	or	$v1,$zero,$zero
/*  f11d6cc:	1040000a */ 	beqz	$v0,.L0f11d6f8
/*  f11d6d0:	24090040 */ 	addiu	$t1,$zero,0x40
/*  f11d6d4:	24010001 */ 	addiu	$at,$zero,0x1
/*  f11d6d8:	1041000b */ 	beq	$v0,$at,.L0f11d708
/*  f11d6dc:	24010002 */ 	addiu	$at,$zero,0x2
/*  f11d6e0:	1041000f */ 	beq	$v0,$at,.L0f11d720
/*  f11d6e4:	24010003 */ 	addiu	$at,$zero,0x3
/*  f11d6e8:	10410013 */ 	beq	$v0,$at,.L0f11d738
/*  f11d6ec:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11d6f0:	1000001a */ 	beqz	$zero,.L0f11d75c
/*  f11d6f4:	30af0001 */ 	andi	$t7,$a1,0x1
.L0f11d6f8:
/*  f11d6f8:	240301a0 */ 	addiu	$v1,$zero,0x1a0
/*  f11d6fc:	a7a90020 */ 	sh	$t1,0x20($sp)
/*  f11d700:	10000015 */ 	beqz	$zero,.L0f11d758
/*  f11d704:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f11d708:
/*  f11d708:	8d030278 */ 	lw	$v1,0x278($t0)
/*  f11d70c:	240b0040 */ 	addiu	$t3,$zero,0x40
/*  f11d710:	a7ab0020 */ 	sh	$t3,0x20($sp)
/*  f11d714:	00035200 */ 	sll	$t2,$v1,0x8
/*  f11d718:	1000000f */ 	beqz	$zero,.L0f11d758
/*  f11d71c:	25430660 */ 	addiu	$v1,$t2,0x660
.L0f11d720:
/*  f11d720:	8d030278 */ 	lw	$v1,0x278($t0)
/*  f11d724:	240d0080 */ 	addiu	$t5,$zero,0x80
/*  f11d728:	a7ad0020 */ 	sh	$t5,0x20($sp)
/*  f11d72c:	00036200 */ 	sll	$t4,$v1,0x8
/*  f11d730:	10000009 */ 	beqz	$zero,.L0f11d758
/*  f11d734:	25830440 */ 	addiu	$v1,$t4,0x440
.L0f11d738:
/*  f11d738:	3c028007 */ 	lui	$v0,0x8007
/*  f11d73c:	8c425ccc */ 	lw	$v0,0x5ccc($v0)
/*  f11d740:	8d0e0278 */ 	lw	$t6,0x278($t0)
/*  f11d744:	a7a20020 */ 	sh	$v0,0x20($sp)
/*  f11d748:	01c20019 */ 	multu	$t6,$v0
/*  f11d74c:	00001812 */ 	mflo	$v1
/*  f11d750:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11d754:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11d758:
/*  f11d758:	30af0001 */ 	andi	$t7,$a1,0x1
.L0f11d75c:
/*  f11d75c:	11e00003 */ 	beqz	$t7,.L0f11d76c
/*  f11d760:	3401a000 */ 	dli	$at,0xa000
/*  f11d764:	10000002 */ 	beqz	$zero,.L0f11d770
/*  f11d768:	24021000 */ 	addiu	$v0,$zero,0x1000
.L0f11d76c:
/*  f11d76c:	00001025 */ 	or	$v0,$zero,$zero
.L0f11d770:
/*  f11d770:	00432821 */ 	addu	$a1,$v0,$v1
/*  f11d774:	8d1902c4 */ 	lw	$t9,0x2c4($t0)
/*  f11d778:	00a12821 */ 	addu	$a1,$a1,$at
/*  f11d77c:	30b8ffff */ 	andi	$t8,$a1,0xffff
/*  f11d780:	03002825 */ 	or	$a1,$t8,$zero
/*  f11d784:	97a70020 */ 	lhu	$a3,0x20($sp)
/*  f11d788:	afa80018 */ 	sw	$t0,0x18($sp)
/*  f11d78c:	0fc472f6 */ 	jal	func0f11cbd8
/*  f11d790:	03233021 */ 	addu	$a2,$t9,$v1
/*  f11d794:	14400003 */ 	bnez	$v0,.L0f11d7a4
/*  f11d798:	8fa80018 */ 	lw	$t0,0x18($sp)
/*  f11d79c:	10000005 */ 	beqz	$zero,.L0f11d7b4
/*  f11d7a0:	00001025 */ 	or	$v0,$zero,$zero
.L0f11d7a4:
/*  f11d7a4:	8d090278 */ 	lw	$t1,0x278($t0)
/*  f11d7a8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11d7ac:	252a0001 */ 	addiu	$t2,$t1,0x1
/*  f11d7b0:	ad0a0278 */ 	sw	$t2,0x278($t0)
.L0f11d7b4:
/*  f11d7b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11d7b8:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f11d7bc:	03e00008 */ 	jr	$ra
/*  f11d7c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11d7c4:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11d7c8:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f11d7cc:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11d7d0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d7d4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d7d8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d7dc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d7e0:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11d7e4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d7e8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d7ec:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11d7f0:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f11d7f4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d7f8:	03191821 */ 	addu	$v1,$t8,$t9
/*  f11d7fc:	8c62000c */ 	lw	$v0,0xc($v1)
/*  f11d800:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11d804:	01e02025 */ 	or	$a0,$t7,$zero
/*  f11d808:	10400009 */ 	beqz	$v0,.L0f11d830
/*  f11d80c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f11d810:	1041000d */ 	beq	$v0,$at,.L0f11d848
/*  f11d814:	24010002 */ 	addiu	$at,$zero,0x2
/*  f11d818:	10410011 */ 	beq	$v0,$at,.L0f11d860
/*  f11d81c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f11d820:	10410015 */ 	beq	$v0,$at,.L0f11d878
/*  f11d824:	3c0b8007 */ 	lui	$t3,0x8007
/*  f11d828:	10000020 */ 	beqz	$zero,.L0f11d8ac
/*  f11d82c:	00001025 */ 	or	$v0,$zero,$zero
.L0f11d830:
/*  f11d830:	8c680278 */ 	lw	$t0,0x278($v1)
/*  f11d834:	24010001 */ 	addiu	$at,$zero,0x1
/*  f11d838:	5501001c */ 	bnel	$t0,$at,.L0f11d8ac
/*  f11d83c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11d840:	03e00008 */ 	jr	$ra
/*  f11d844:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11d848:
/*  f11d848:	8c690278 */ 	lw	$t1,0x278($v1)
/*  f11d84c:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11d850:	55210016 */ 	bnel	$t1,$at,.L0f11d8ac
/*  f11d854:	00001025 */ 	or	$v0,$zero,$zero
/*  f11d858:	03e00008 */ 	jr	$ra
/*  f11d85c:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11d860:
/*  f11d860:	8c6a0278 */ 	lw	$t2,0x278($v1)
/*  f11d864:	24010008 */ 	addiu	$at,$zero,0x8
/*  f11d868:	55410010 */ 	bnel	$t2,$at,.L0f11d8ac
/*  f11d86c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11d870:	03e00008 */ 	jr	$ra
/*  f11d874:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11d878:
/*  f11d878:	8d6b5ccc */ 	lw	$t3,0x5ccc($t3)
/*  f11d87c:	240c1000 */ 	addiu	$t4,$zero,0x1000
/*  f11d880:	8c6e0278 */ 	lw	$t6,0x278($v1)
/*  f11d884:	018b001b */ 	divu	$zero,$t4,$t3
/*  f11d888:	00006812 */ 	mflo	$t5
/*  f11d88c:	15600002 */ 	bnez	$t3,.L0f11d898
/*  f11d890:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11d894:	0007000d */ 	break	0x7
.L0f11d898:
/*  f11d898:	55ae0004 */ 	bnel	$t5,$t6,.L0f11d8ac
/*  f11d89c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11d8a0:	03e00008 */ 	jr	$ra
/*  f11d8a4:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11d8a8:	00001025 */ 	or	$v0,$zero,$zero
.L0f11d8ac:
/*  f11d8ac:	03e00008 */ 	jr	$ra
/*  f11d8b0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11d8b4
/*  f11d8b4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f11d8b8:	afb6001c */ 	sw	$s6,0x1c($sp)
/*  f11d8bc:	afb50018 */ 	sw	$s5,0x18($sp)
/*  f11d8c0:	afb40014 */ 	sw	$s4,0x14($sp)
/*  f11d8c4:	afb30010 */ 	sw	$s3,0x10($sp)
/*  f11d8c8:	afb10008 */ 	sw	$s1,0x8($sp)
/*  f11d8cc:	afb00004 */ 	sw	$s0,0x4($sp)
/*  f11d8d0:	00a08025 */ 	or	$s0,$a1,$zero
/*  f11d8d4:	00808825 */ 	or	$s1,$a0,$zero
/*  f11d8d8:	afb2000c */ 	sw	$s2,0xc($sp)
/*  f11d8dc:	24130008 */ 	addiu	$s3,$zero,0x8
/*  f11d8e0:	24140010 */ 	addiu	$s4,$zero,0x10
/*  f11d8e4:	24150080 */ 	addiu	$s5,$zero,0x80
/*  f11d8e8:	24160080 */ 	addiu	$s6,$zero,0x80
/*  f11d8ec:	00001825 */ 	or	$v1,$zero,$zero
/*  f11d8f0:	00004025 */ 	or	$t0,$zero,$zero
.L0f11d8f4:
/*  f11d8f4:	00032100 */ 	sll	$a0,$v1,0x4
/*  f11d8f8:	00003025 */ 	or	$a2,$zero,$zero
.L0f11d8fc:
/*  f11d8fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f11d900:	01004825 */ 	or	$t1,$t0,$zero
/*  f11d904:	00919021 */ 	addu	$s2,$a0,$s1
.L0f11d908:
/*  f11d908:	000951c0 */ 	sll	$t2,$t1,0x7
/*  f11d90c:	020a5821 */ 	addu	$t3,$s0,$t2
/*  f11d910:	00001025 */ 	or	$v0,$zero,$zero
/*  f11d914:	00c03825 */ 	or	$a3,$a2,$zero
.L0f11d918:
/*  f11d918:	01677021 */ 	addu	$t6,$t3,$a3
/*  f11d91c:	a1c00000 */ 	sb	$zero,0x0($t6)
/*  f11d920:	92580000 */ 	lbu	$t8,0x0($s2)
/*  f11d924:	240f0080 */ 	addiu	$t7,$zero,0x80
/*  f11d928:	004f6007 */ 	srav	$t4,$t7,$v0
/*  f11d92c:	030cc824 */ 	and	$t9,$t8,$t4
/*  f11d930:	17200006 */ 	bnez	$t9,.L0f11d94c
/*  f11d934:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11d938:	01477021 */ 	addu	$t6,$t2,$a3
/*  f11d93c:	01d06821 */ 	addu	$t5,$t6,$s0
/*  f11d940:	91af0000 */ 	lbu	$t7,0x0($t5)
/*  f11d944:	25f80040 */ 	addiu	$t8,$t7,0x40
/*  f11d948:	a1b80000 */ 	sb	$t8,0x0($t5)
.L0f11d94c:
/*  f11d94c:	92590001 */ 	lbu	$t9,0x1($s2)
/*  f11d950:	01477821 */ 	addu	$t7,$t2,$a3
/*  f11d954:	01f06821 */ 	addu	$t5,$t7,$s0
/*  f11d958:	032c7024 */ 	and	$t6,$t9,$t4
/*  f11d95c:	15c00004 */ 	bnez	$t6,.L0f11d970
/*  f11d960:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11d964:	91b80000 */ 	lbu	$t8,0x0($t5)
/*  f11d968:	27190080 */ 	addiu	$t9,$t8,0x80
/*  f11d96c:	a1b90000 */ 	sb	$t9,0x0($t5)
.L0f11d970:
/*  f11d970:	1453ffe9 */ 	bne	$v0,$s3,.L0f11d918
/*  f11d974:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f11d978:	24a50002 */ 	addiu	$a1,$a1,0x2
/*  f11d97c:	25290001 */ 	addiu	$t1,$t1,0x1
/*  f11d980:	14b4ffe1 */ 	bne	$a1,$s4,.L0f11d908
/*  f11d984:	26520002 */ 	addiu	$s2,$s2,0x2
/*  f11d988:	24c60008 */ 	addiu	$a2,$a2,0x8
/*  f11d98c:	14d5ffdb */ 	bne	$a2,$s5,.L0f11d8fc
/*  f11d990:	24840010 */ 	addiu	$a0,$a0,0x10
/*  f11d994:	25080008 */ 	addiu	$t0,$t0,0x8
/*  f11d998:	1516ffd6 */ 	bne	$t0,$s6,.L0f11d8f4
/*  f11d99c:	24630010 */ 	addiu	$v1,$v1,0x10
/*  f11d9a0:	8fb00004 */ 	lw	$s0,0x4($sp)
/*  f11d9a4:	8fb10008 */ 	lw	$s1,0x8($sp)
/*  f11d9a8:	8fb2000c */ 	lw	$s2,0xc($sp)
/*  f11d9ac:	8fb30010 */ 	lw	$s3,0x10($sp)
/*  f11d9b0:	8fb40014 */ 	lw	$s4,0x14($sp)
/*  f11d9b4:	8fb50018 */ 	lw	$s5,0x18($sp)
/*  f11d9b8:	8fb6001c */ 	lw	$s6,0x1c($sp)
/*  f11d9bc:	03e00008 */ 	jr	$ra
/*  f11d9c0:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f11d9c4
/*  f11d9c4:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11d9c8:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f11d9cc:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11d9d0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d9d4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d9d8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d9dc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d9e0:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11d9e4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d9e8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11d9ec:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11d9f0:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f11d9f4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11d9f8:	03194021 */ 	addu	$t0,$t8,$t9
/*  f11d9fc:	8d02000c */ 	lw	$v0,0xc($t0)
/*  f11da00:	27bdbfa0 */ 	addiu	$sp,$sp,-16480
/*  f11da04:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11da08:	00a08025 */ 	or	$s0,$a1,$zero
/*  f11da0c:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11da10:	afa44060 */ 	sw	$a0,0x4060($sp)
/*  f11da14:	1040000a */ 	beqz	$v0,.L0f11da40
/*  f11da18:	afa7406c */ 	sw	$a3,0x406c($sp)
/*  f11da1c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f11da20:	10410016 */ 	beq	$v0,$at,.L0f11da7c
/*  f11da24:	24010002 */ 	addiu	$at,$zero,0x2
/*  f11da28:	1041002c */ 	beq	$v0,$at,.L0f11dadc
/*  f11da2c:	24010003 */ 	addiu	$at,$zero,0x3
/*  f11da30:	10410042 */ 	beq	$v0,$at,.L0f11db3c
/*  f11da34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11da38:	10000044 */ 	beqz	$zero,.L0f11db4c
/*  f11da3c:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11da40:
/*  f11da40:	10c00042 */ 	beqz	$a2,.L0f11db4c
/*  f11da44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11da48:	8d0502c4 */ 	lw	$a1,0x2c4($t0)
/*  f11da4c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11da50:	00c01825 */ 	or	$v1,$a2,$zero
/*  f11da54:	24a401b2 */ 	addiu	$a0,$a1,0x1b2
/*  f11da58:	2405001e */ 	addiu	$a1,$zero,0x1e
.L0f11da5c:
/*  f11da5c:	90890000 */ 	lbu	$t1,0x0($a0)
/*  f11da60:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11da64:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f11da68:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f11da6c:	1445fffb */ 	bne	$v0,$a1,.L0f11da5c
/*  f11da70:	a069ffff */ 	sb	$t1,-0x1($v1)
/*  f11da74:	10000035 */ 	beqz	$zero,.L0f11db4c
/*  f11da78:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11da7c:
/*  f11da7c:	12000033 */ 	beqz	$s0,.L0f11db4c
/*  f11da80:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f11da84:	0fc4762d */ 	jal	func0f11d8b4
/*  f11da88:	8d0402c4 */ 	lw	$a0,0x2c4($t0)
/*  f11da8c:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f11da90:	00003825 */ 	or	$a3,$zero,$zero
/*  f11da94:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f11da98:	00001025 */ 	or	$v0,$zero,$zero
.L0f11da9c:
/*  f11da9c:	02071821 */ 	addu	$v1,$s0,$a3
/*  f11daa0:	00072882 */ 	srl	$a1,$a3,0x2
.L0f11daa4:
/*  f11daa4:	00025082 */ 	srl	$t2,$v0,0x2
/*  f11daa8:	000a59c0 */ 	sll	$t3,$t2,0x7
/*  f11daac:	00cb6021 */ 	addu	$t4,$a2,$t3
/*  f11dab0:	01856821 */ 	addu	$t5,$t4,$a1
/*  f11dab4:	91ae1830 */ 	lbu	$t6,0x1830($t5)
/*  f11dab8:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11dabc:	24630080 */ 	addiu	$v1,$v1,0x80
/*  f11dac0:	1444fff8 */ 	bne	$v0,$a0,.L0f11daa4
/*  f11dac4:	a06eff80 */ 	sb	$t6,-0x80($v1)
/*  f11dac8:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f11dacc:	54e4fff3 */ 	bnel	$a3,$a0,.L0f11da9c
/*  f11dad0:	00001025 */ 	or	$v0,$zero,$zero
/*  f11dad4:	1000001d */ 	beqz	$zero,.L0f11db4c
/*  f11dad8:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11dadc:
/*  f11dadc:	1200001b */ 	beqz	$s0,.L0f11db4c
/*  f11dae0:	27a50060 */ 	addiu	$a1,$sp,0x60
/*  f11dae4:	0fc4762d */ 	jal	func0f11d8b4
/*  f11dae8:	8d0402c4 */ 	lw	$a0,0x2c4($t0)
/*  f11daec:	27a60060 */ 	addiu	$a2,$sp,0x60
/*  f11daf0:	00003825 */ 	or	$a3,$zero,$zero
/*  f11daf4:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f11daf8:	00001025 */ 	or	$v0,$zero,$zero
.L0f11dafc:
/*  f11dafc:	02071821 */ 	addu	$v1,$s0,$a3
/*  f11db00:	00072842 */ 	srl	$a1,$a3,0x1
.L0f11db04:
/*  f11db04:	00027842 */ 	srl	$t7,$v0,0x1
/*  f11db08:	000fc1c0 */ 	sll	$t8,$t7,0x7
/*  f11db0c:	00d8c821 */ 	addu	$t9,$a2,$t8
/*  f11db10:	03254821 */ 	addu	$t1,$t9,$a1
/*  f11db14:	912a1020 */ 	lbu	$t2,0x1020($t1)
/*  f11db18:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11db1c:	24630080 */ 	addiu	$v1,$v1,0x80
/*  f11db20:	1444fff8 */ 	bne	$v0,$a0,.L0f11db04
/*  f11db24:	a06aff80 */ 	sb	$t2,-0x80($v1)
/*  f11db28:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f11db2c:	54e4fff3 */ 	bnel	$a3,$a0,.L0f11dafc
/*  f11db30:	00001025 */ 	or	$v0,$zero,$zero
/*  f11db34:	10000005 */ 	beqz	$zero,.L0f11db4c
/*  f11db38:	00000000 */ 	sll	$zero,$zero,0x0
.L0f11db3c:
/*  f11db3c:	12000003 */ 	beqz	$s0,.L0f11db4c
/*  f11db40:	02002825 */ 	or	$a1,$s0,$zero
/*  f11db44:	0fc4762d */ 	jal	func0f11d8b4
/*  f11db48:	8d0402c4 */ 	lw	$a0,0x2c4($t0)
.L0f11db4c:
/*  f11db4c:	12000028 */ 	beqz	$s0,.L0f11dbf0
/*  f11db50:	8fab406c */ 	lw	$t3,0x406c($sp)
/*  f11db54:	11600026 */ 	beqz	$t3,.L0f11dbf0
/*  f11db58:	24080008 */ 	addiu	$t0,$zero,0x8
/*  f11db5c:	24053c00 */ 	addiu	$a1,$zero,0x3c00
/*  f11db60:	24060400 */ 	addiu	$a2,$zero,0x400
/*  f11db64:	24040080 */ 	addiu	$a0,$zero,0x80
/*  f11db68:	00001025 */ 	or	$v0,$zero,$zero
.L0f11db6c:
/*  f11db6c:	00b01821 */ 	addu	$v1,$a1,$s0
.L0f11db70:
/*  f11db70:	906cfc00 */ 	lbu	$t4,-0x400($v1)
/*  f11db74:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11db78:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f11db7c:	1444fffc */ 	bne	$v0,$a0,.L0f11db70
/*  f11db80:	a06cffff */ 	sb	$t4,-0x1($v1)
/*  f11db84:	24a5ff80 */ 	addiu	$a1,$a1,-128
/*  f11db88:	00c5082a */ 	slt	$at,$a2,$a1
/*  f11db8c:	5420fff7 */ 	bnezl	$at,.L0f11db6c
/*  f11db90:	00001025 */ 	or	$v0,$zero,$zero
/*  f11db94:	00003825 */ 	or	$a3,$zero,$zero
/*  f11db98:	02003025 */ 	or	$a2,$s0,$zero
.L0f11db9c:
/*  f11db9c:	00001025 */ 	or	$v0,$zero,$zero
/*  f11dba0:	00c01825 */ 	or	$v1,$a2,$zero
.L0f11dba4:
/*  f11dba4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11dba8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f11dbac:	1444fffd */ 	bne	$v0,$a0,.L0f11dba4
/*  f11dbb0:	a060ffff */ 	sb	$zero,-0x1($v1)
/*  f11dbb4:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f11dbb8:	14e8fff8 */ 	bne	$a3,$t0,.L0f11db9c
/*  f11dbbc:	24c60080 */ 	addiu	$a2,$a2,0x80
/*  f11dbc0:	24053c00 */ 	addiu	$a1,$zero,0x3c00
/*  f11dbc4:	26063c00 */ 	addiu	$a2,$s0,0x3c00
/*  f11dbc8:	24074000 */ 	addiu	$a3,$zero,0x4000
.L0f11dbcc:
/*  f11dbcc:	00001025 */ 	or	$v0,$zero,$zero
/*  f11dbd0:	00c01825 */ 	or	$v1,$a2,$zero
.L0f11dbd4:
/*  f11dbd4:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11dbd8:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f11dbdc:	1444fffd */ 	bne	$v0,$a0,.L0f11dbd4
/*  f11dbe0:	a060ffff */ 	sb	$zero,-0x1($v1)
/*  f11dbe4:	24a50080 */ 	addiu	$a1,$a1,0x80
/*  f11dbe8:	14a7fff8 */ 	bne	$a1,$a3,.L0f11dbcc
/*  f11dbec:	24c60080 */ 	addiu	$a2,$a2,0x80
.L0f11dbf0:
/*  f11dbf0:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11dbf4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f11dbf8:	27bd4060 */ 	addiu	$sp,$sp,0x4060
/*  f11dbfc:	03e00008 */ 	jr	$ra
/*  f11dc00:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11dc04
/*  f11dc04:	00047080 */ 	sll	$t6,$a0,0x2
/*  f11dc08:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f11dc0c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11dc10:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f11dc14:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11dc18:	01c47021 */ 	addu	$t6,$t6,$a0
/*  f11dc1c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11dc20:	01c47023 */ 	subu	$t6,$t6,$a0
/*  f11dc24:	3c0f800a */ 	lui	$t7,%hi(var800a2380)
/*  f11dc28:	25ef2380 */ 	addiu	$t7,$t7,%lo(var800a2380)
/*  f11dc2c:	000e7080 */ 	sll	$t6,$t6,0x2
/*  f11dc30:	01cf1021 */ 	addu	$v0,$t6,$t7
/*  f11dc34:	8c580010 */ 	lw	$t8,0x10($v0)
/*  f11dc38:	44856000 */ 	mtc1	$a1,$f12
/*  f11dc3c:	2401000b */ 	addiu	$at,$zero,0xb
/*  f11dc40:	17010019 */ 	bne	$t8,$at,.L0f11dca8
/*  f11dc44:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11dc48:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f11dc4c:	24010001 */ 	addiu	$at,$zero,0x1
/*  f11dc50:	17210015 */ 	bne	$t9,$at,.L0f11dca8
/*  f11dc54:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11dc58:	8c430004 */ 	lw	$v1,0x4($v0)
/*  f11dc5c:	24010006 */ 	addiu	$at,$zero,0x6
/*  f11dc60:	10610011 */ 	beq	$v1,$at,.L0f11dca8
/*  f11dc64:	24010007 */ 	addiu	$at,$zero,0x7
/*  f11dc68:	1061000f */ 	beq	$v1,$at,.L0f11dca8
/*  f11dc6c:	3c014270 */ 	lui	$at,0x4270
/*  f11dc70:	44812000 */ 	mtc1	$at,$f4
/*  f11dc74:	c44602b4 */ 	lwc1	$f6,0x2b4($v0)
/*  f11dc78:	24080003 */ 	addiu	$t0,$zero,0x3
/*  f11dc7c:	460c2002 */ 	mul.s	$f0,$f4,$f12
/*  f11dc80:	00c74821 */ 	addu	$t1,$a2,$a3
/*  f11dc84:	4600303c */ 	c.lt.s	$f6,$f0
/*  f11dc88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11dc8c:	45000006 */ 	bc1f	.L0f11dca8
/*  f11dc90:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11dc94:	ac480004 */ 	sw	$t0,0x4($v0)
/*  f11dc98:	e44002b4 */ 	swc1	$f0,0x2b4($v0)
/*  f11dc9c:	ac460284 */ 	sw	$a2,0x284($v0)
/*  f11dca0:	ac490288 */ 	sw	$t1,0x288($v0)
/*  f11dca4:	ac40028c */ 	sw	$zero,0x28c($v0)
.L0f11dca8:
/*  f11dca8:	03e00008 */ 	jr	$ra
/*  f11dcac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11dcb0
/*  f11dcb0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f11dcb4:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f11dcb8:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f11dcbc:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f11dcc0:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f11dcc4:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f11dcc8:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f11dccc:	3c12800a */ 	lui	$s2,%hi(var800a2380)
/*  f11dcd0:	00808825 */ 	or	$s1,$a0,$zero
/*  f11dcd4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f11dcd8:	26522380 */ 	addiu	$s2,$s2,%lo(var800a2380)
/*  f11dcdc:	00008025 */ 	or	$s0,$zero,$zero
/*  f11dce0:	241302cc */ 	addiu	$s3,$zero,0x2cc
/*  f11dce4:	24140002 */ 	addiu	$s4,$zero,0x2
/*  f11dce8:	24150003 */ 	addiu	$s5,$zero,0x3
.L0f11dcec:
/*  f11dcec:	02130019 */ 	multu	$s0,$s3
/*  f11dcf0:	00007012 */ 	mflo	$t6
/*  f11dcf4:	024e7821 */ 	addu	$t7,$s2,$t6
/*  f11dcf8:	8de20000 */ 	lw	$v0,0x0($t7)
/*  f11dcfc:	50540008 */ 	beql	$v0,$s4,.L0f11dd20
/*  f11dd00:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11dd04:	10550005 */ 	beq	$v0,$s5,.L0f11dd1c
/*  f11dd08:	00102600 */ 	sll	$a0,$s0,0x18
/*  f11dd0c:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f11dd10:	03002025 */ 	or	$a0,$t8,$zero
/*  f11dd14:	0c0054f1 */ 	jal	func000153c4
/*  f11dd18:	02202825 */ 	or	$a1,$s1,$zero
.L0f11dd1c:
/*  f11dd1c:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f11dd20:
/*  f11dd20:	0010ce00 */ 	sll	$t9,$s0,0x18
/*  f11dd24:	00198603 */ 	sra	$s0,$t9,0x18
/*  f11dd28:	2a010005 */ 	slti	$at,$s0,0x5
/*  f11dd2c:	1420ffef */ 	bnez	$at,.L0f11dcec
/*  f11dd30:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11dd34:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f11dd38:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f11dd3c:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f11dd40:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f11dd44:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f11dd48:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f11dd4c:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f11dd50:	03e00008 */ 	jr	$ra
/*  f11dd54:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f11dd58
/*  f11dd58:	27bdffb0 */ 	addiu	$sp,$sp,-80
/*  f11dd5c:	afa40050 */ 	sw	$a0,0x50($sp)
/*  f11dd60:	00807025 */ 	or	$t6,$a0,$zero
/*  f11dd64:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f11dd68:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f11dd6c:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f11dd70:	afb50028 */ 	sw	$s5,0x28($sp)
/*  f11dd74:	afb40024 */ 	sw	$s4,0x24($sp)
/*  f11dd78:	afb30020 */ 	sw	$s3,0x20($sp)
/*  f11dd7c:	afb2001c */ 	sw	$s2,0x1c($sp)
/*  f11dd80:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f11dd84:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f11dd88:	01e02025 */ 	or	$a0,$t7,$zero
/*  f11dd8c:	27a50040 */ 	addiu	$a1,$sp,0x40
/*  f11dd90:	0c0054b4 */ 	jal	func000152d0
/*  f11dd94:	27a60044 */ 	addiu	$a2,$sp,0x44
/*  f11dd98:	3c12800a */ 	lui	$s2,%hi(var800a2380)
/*  f11dd9c:	26522380 */ 	addiu	$s2,$s2,%lo(var800a2380)
/*  f11dda0:	27b00040 */ 	addiu	$s0,$sp,0x40
/*  f11dda4:	27b50048 */ 	addiu	$s5,$sp,0x48
/*  f11dda8:	24140006 */ 	addiu	$s4,$zero,0x6
/*  f11ddac:	241302cc */ 	addiu	$s3,$zero,0x2cc
/*  f11ddb0:	24110001 */ 	addiu	$s1,$zero,0x1
/*  f11ddb4:	8e020000 */ 	lw	$v0,0x0($s0)
.L0f11ddb8:
/*  f11ddb8:	0442000e */ 	bltzl	$v0,.L0f11ddf4
/*  f11ddbc:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f11ddc0:	00530019 */ 	multu	$v0,$s3
/*  f11ddc4:	00022600 */ 	sll	$a0,$v0,0x18
/*  f11ddc8:	00044603 */ 	sra	$t0,$a0,0x18
/*  f11ddcc:	01002025 */ 	or	$a0,$t0,$zero
/*  f11ddd0:	02202825 */ 	or	$a1,$s1,$zero
/*  f11ddd4:	0000c012 */ 	mflo	$t8
/*  f11ddd8:	02581821 */ 	addu	$v1,$s2,$t8
/*  f11dddc:	8c790000 */ 	lw	$t9,0x0($v1)
/*  f11dde0:	56390004 */ 	bnel	$s1,$t9,.L0f11ddf4
/*  f11dde4:	26100004 */ 	addiu	$s0,$s0,0x4
/*  f11dde8:	0c0054f1 */ 	jal	func000153c4
/*  f11ddec:	ac740004 */ 	sw	$s4,0x4($v1)
/*  f11ddf0:	26100004 */ 	addiu	$s0,$s0,0x4
.L0f11ddf4:
/*  f11ddf4:	5615fff0 */ 	bnel	$s0,$s5,.L0f11ddb8
/*  f11ddf8:	8e020000 */ 	lw	$v0,0x0($s0)
/*  f11ddfc:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f11de00:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f11de04:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f11de08:	8fb2001c */ 	lw	$s2,0x1c($sp)
/*  f11de0c:	8fb30020 */ 	lw	$s3,0x20($sp)
/*  f11de10:	8fb40024 */ 	lw	$s4,0x24($sp)
/*  f11de14:	8fb50028 */ 	lw	$s5,0x28($sp)
/*  f11de18:	03e00008 */ 	jr	$ra
/*  f11de1c:	27bd0050 */ 	addiu	$sp,$sp,0x50
);

GLOBAL_ASM(
glabel func0f11de20
/*  f11de20:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f11de24:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f11de28:	00807025 */ 	or	$t6,$a0,$zero
/*  f11de2c:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f11de30:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11de34:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f11de38:	01e02025 */ 	or	$a0,$t7,$zero
/*  f11de3c:	27a50028 */ 	addiu	$a1,$sp,0x28
/*  f11de40:	0c0054b4 */ 	jal	func000152d0
/*  f11de44:	27a6002c */ 	addiu	$a2,$sp,0x2c
/*  f11de48:	3c06800a */ 	lui	$a2,%hi(var800a2380)
/*  f11de4c:	24c62380 */ 	addiu	$a2,$a2,%lo(var800a2380)
/*  f11de50:	27a40028 */ 	addiu	$a0,$sp,0x28
/*  f11de54:	27aa0030 */ 	addiu	$t2,$sp,0x30
/*  f11de58:	24090008 */ 	addiu	$t1,$zero,0x8
/*  f11de5c:	24080007 */ 	addiu	$t0,$zero,0x7
/*  f11de60:	240702cc */ 	addiu	$a3,$zero,0x2cc
/*  f11de64:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11de68:	8c830000 */ 	lw	$v1,0x0($a0)
.L0f11de6c:
/*  f11de6c:	24840004 */ 	addiu	$a0,$a0,0x4
/*  f11de70:	0460000b */ 	bltz	$v1,.L0f11dea0
/*  f11de74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11de78:	00670019 */ 	multu	$v1,$a3
/*  f11de7c:	0000c012 */ 	mflo	$t8
/*  f11de80:	00d81021 */ 	addu	$v0,$a2,$t8
/*  f11de84:	8c590000 */ 	lw	$t9,0x0($v0)
/*  f11de88:	14b90005 */ 	bne	$a1,$t9,.L0f11dea0
/*  f11de8c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11de90:	8c4b0004 */ 	lw	$t3,0x4($v0)
/*  f11de94:	150b0002 */ 	bne	$t0,$t3,.L0f11dea0
/*  f11de98:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11de9c:	ac490004 */ 	sw	$t1,0x4($v0)
.L0f11dea0:
/*  f11dea0:	548afff2 */ 	bnel	$a0,$t2,.L0f11de6c
/*  f11dea4:	8c830000 */ 	lw	$v1,0x0($a0)
/*  f11dea8:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11deac:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f11deb0:	03e00008 */ 	jr	$ra
/*  f11deb4:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11deb8
/*  f11deb8:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f11debc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f11dec0:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f11dec4:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f11dec8:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f11decc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11ded0:	3c11800a */ 	lui	$s1,%hi(var800a2380)
/*  f11ded4:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f11ded8:	26312380 */ 	addiu	$s1,$s1,%lo(var800a2380)
/*  f11dedc:	00008025 */ 	or	$s0,$zero,$zero
/*  f11dee0:	24120001 */ 	addiu	$s2,$zero,0x1
/*  f11dee4:	24130006 */ 	addiu	$s3,$zero,0x6
/*  f11dee8:	24140004 */ 	addiu	$s4,$zero,0x4
.L0f11deec:
/*  f11deec:	8e2e0000 */ 	lw	$t6,0x0($s1)
/*  f11def0:	00102600 */ 	sll	$a0,$s0,0x18
/*  f11def4:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f11def8:	164e0004 */ 	bne	$s2,$t6,.L0f11df0c
/*  f11defc:	01e02025 */ 	or	$a0,$t7,$zero
/*  f11df00:	ae330004 */ 	sw	$s3,0x4($s1)
/*  f11df04:	0c0054f1 */ 	jal	func000153c4
/*  f11df08:	02402825 */ 	or	$a1,$s2,$zero
.L0f11df0c:
/*  f11df0c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11df10:	1614fff6 */ 	bne	$s0,$s4,.L0f11deec
/*  f11df14:	263102cc */ 	addiu	$s1,$s1,0x2cc
/*  f11df18:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f11df1c:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f11df20:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f11df24:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f11df28:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f11df2c:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f11df30:	03e00008 */ 	jr	$ra
/*  f11df34:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f11df38
/*  f11df38:	3c03800a */ 	lui	$v1,%hi(var800a2380)
/*  f11df3c:	3c06800a */ 	lui	$a2,%hi(var800a2eb0)
/*  f11df40:	24c62eb0 */ 	addiu	$a2,$a2,%lo(var800a2eb0)
/*  f11df44:	24632380 */ 	addiu	$v1,$v1,%lo(var800a2380)
/*  f11df48:	24050008 */ 	addiu	$a1,$zero,0x8
/*  f11df4c:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f11df50:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11df54:	8c6e0000 */ 	lw	$t6,0x0($v1)
.L0f11df58:
/*  f11df58:	544e0006 */ 	bnel	$v0,$t6,.L0f11df74
/*  f11df5c:	246302cc */ 	addiu	$v1,$v1,0x2cc
/*  f11df60:	8c6f0004 */ 	lw	$t7,0x4($v1)
/*  f11df64:	548f0003 */ 	bnel	$a0,$t7,.L0f11df74
/*  f11df68:	246302cc */ 	addiu	$v1,$v1,0x2cc
/*  f11df6c:	ac650004 */ 	sw	$a1,0x4($v1)
/*  f11df70:	246302cc */ 	addiu	$v1,$v1,0x2cc
.L0f11df74:
/*  f11df74:	5466fff8 */ 	bnel	$v1,$a2,.L0f11df58
/*  f11df78:	8c6e0000 */ 	lw	$t6,0x0($v1)
/*  f11df7c:	03e00008 */ 	jr	$ra
/*  f11df80:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11df84:	03e00008 */ 	jr	$ra
/*  f11df88:	00801025 */ 	or	$v0,$a0,$zero
);

void func0f11df8c(void)
{
	// empty
}

GLOBAL_ASM(
glabel func0f11df94
/*  f11df94:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f11df98:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f11df9c:	83ae0023 */ 	lb	$t6,0x23($sp)
/*  f11dfa0:	3c18800a */ 	lui	$t8,%hi(var800a2380)
/*  f11dfa4:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11dfa8:	000e7880 */ 	sll	$t7,$t6,0x2
/*  f11dfac:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11dfb0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11dfb4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11dfb8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11dfbc:	01ee7821 */ 	addu	$t7,$t7,$t6
/*  f11dfc0:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11dfc4:	01ee7823 */ 	subu	$t7,$t7,$t6
/*  f11dfc8:	000f7880 */ 	sll	$t7,$t7,0x2
/*  f11dfcc:	27182380 */ 	addiu	$t8,$t8,%lo(var800a2380)
/*  f11dfd0:	01f88021 */ 	addu	$s0,$t7,$t8
/*  f11dfd4:	8e190010 */ 	lw	$t9,0x10($s0)
/*  f11dfd8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11dfdc:	2f21001c */ 	sltiu	$at,$t9,0x1c
/*  f11dfe0:	102000da */ 	beqz	$at,.L0f11e34c
/*  f11dfe4:	0019c880 */ 	sll	$t9,$t9,0x2
/*  f11dfe8:	3c017f1b */ 	lui	$at,%hi(var7f1b4f6c)
/*  f11dfec:	00390821 */ 	addu	$at,$at,$t9
/*  f11dff0:	8c394f6c */ 	lw	$t9,%lo(var7f1b4f6c)($at)
/*  f11dff4:	03200008 */ 	jr	$t9
/*  f11dff8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11dffc:	8e080264 */ 	lw	$t0,0x264($s0)
/*  f11e000:	920a02b8 */ 	lbu	$t2,0x2b8($s0)
/*  f11e004:	ae000010 */ 	sw	$zero,0x10($s0)
/*  f11e008:	25090001 */ 	addiu	$t1,$t0,0x1
/*  f11e00c:	314bfffd */ 	andi	$t3,$t2,0xfffd
/*  f11e010:	ae090264 */ 	sw	$t1,0x264($s0)
/*  f11e014:	a20b02b8 */ 	sb	$t3,0x2b8($s0)
/*  f11e018:	ae000000 */ 	sw	$zero,0x0($s0)
/*  f11e01c:	3c0c8007 */ 	lui	$t4,0x8007
/*  f11e020:	8d8c5d14 */ 	lw	$t4,0x5d14($t4)
/*  f11e024:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f11e028:	11800003 */ 	beqz	$t4,.L0f11e038
/*  f11e02c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11e030:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f11e034:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f11e038:
/*  f11e038:	0fc52bb4 */ 	jal	func0f14aed0
/*  f11e03c:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f11e040:	100000c3 */ 	beqz	$zero,.L0f11e350
/*  f11e044:	8e0a02b8 */ 	lw	$t2,0x2b8($s0)
/*  f11e048:	3c0d8007 */ 	lui	$t5,0x8007
/*  f11e04c:	8dad5d14 */ 	lw	$t5,0x5d14($t5)
/*  f11e050:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f11e054:	11a00003 */ 	beqz	$t5,.L0f11e064
/*  f11e058:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11e05c:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f11e060:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f11e064:
/*  f11e064:	0fc46b1f */ 	jal	func0f11ac7c
/*  f11e068:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f11e06c:	0fc52bb4 */ 	jal	func0f14aed0
/*  f11e070:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f11e074:	100000b6 */ 	beqz	$zero,.L0f11e350
/*  f11e078:	8e0a02b8 */ 	lw	$t2,0x2b8($s0)
/*  f11e07c:	83af0023 */ 	lb	$t7,0x23($sp)
/*  f11e080:	3c0e800a */ 	lui	$t6,0x800a
/*  f11e084:	91cea490 */ 	lbu	$t6,-0x5b70($t6)
/*  f11e088:	24180001 */ 	addiu	$t8,$zero,0x1
/*  f11e08c:	01f8c804 */ 	sllv	$t9,$t8,$t7
/*  f11e090:	01d94024 */ 	and	$t0,$t6,$t9
/*  f11e094:	11000008 */ 	beqz	$t0,.L0f11e0b8
/*  f11e098:	240a0007 */ 	addiu	$t2,$zero,0x7
/*  f11e09c:	24020004 */ 	addiu	$v0,$zero,0x4
/*  f11e0a0:	15e20003 */ 	bne	$t7,$v0,.L0f11e0b0
/*  f11e0a4:	24090005 */ 	addiu	$t1,$zero,0x5
/*  f11e0a8:	100000a8 */ 	beqz	$zero,.L0f11e34c
/*  f11e0ac:	ae090010 */ 	sw	$t1,0x10($s0)
.L0f11e0b0:
/*  f11e0b0:	100000a6 */ 	beqz	$zero,.L0f11e34c
/*  f11e0b4:	ae020010 */ 	sw	$v0,0x10($s0)
.L0f11e0b8:
/*  f11e0b8:	100000a4 */ 	beqz	$zero,.L0f11e34c
/*  f11e0bc:	ae0a0010 */ 	sw	$t2,0x10($s0)
/*  f11e0c0:	83ac0023 */ 	lb	$t4,0x23($sp)
/*  f11e0c4:	3c0b800a */ 	lui	$t3,0x800a
/*  f11e0c8:	916ba490 */ 	lbu	$t3,-0x5b70($t3)
/*  f11e0cc:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f11e0d0:	018dc004 */ 	sllv	$t8,$t5,$t4
/*  f11e0d4:	01787024 */ 	and	$t6,$t3,$t8
/*  f11e0d8:	11c0009c */ 	beqz	$t6,.L0f11e34c
/*  f11e0dc:	24190002 */ 	addiu	$t9,$zero,0x2
/*  f11e0e0:	1000009a */ 	beqz	$zero,.L0f11e34c
/*  f11e0e4:	ae190010 */ 	sw	$t9,0x10($s0)
/*  f11e0e8:	3c0f8007 */ 	lui	$t7,0x8007
/*  f11e0ec:	8def5d14 */ 	lw	$t7,0x5d14($t7)
/*  f11e0f0:	83a80023 */ 	lb	$t0,0x23($sp)
/*  f11e0f4:	3c018007 */ 	lui	$at,0x8007
/*  f11e0f8:	11e00004 */ 	beqz	$t7,.L0f11e10c
/*  f11e0fc:	ac281448 */ 	sw	$t0,0x1448($at)
/*  f11e100:	24040007 */ 	addiu	$a0,$zero,0x7
/*  f11e104:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f11e108:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f11e10c:
/*  f11e10c:	24090005 */ 	addiu	$t1,$zero,0x5
/*  f11e110:	1000008e */ 	beqz	$zero,.L0f11e34c
/*  f11e114:	ae090010 */ 	sw	$t1,0x10($s0)
/*  f11e118:	0c00543a */ 	jal	func000150e8
/*  f11e11c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11e120:	0fc46a3d */ 	jal	func0f11a8f4
/*  f11e124:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f11e128:	0c005451 */ 	jal	func00015144
/*  f11e12c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11e130:	10000087 */ 	beqz	$zero,.L0f11e350
/*  f11e134:	8e0a02b8 */ 	lw	$t2,0x2b8($s0)
/*  f11e138:	3c0a8007 */ 	lui	$t2,0x8007
/*  f11e13c:	8d4a5d14 */ 	lw	$t2,0x5d14($t2)
/*  f11e140:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f11e144:	51400004 */ 	beqzl	$t2,.L0f11e158
/*  f11e148:	240d000b */ 	addiu	$t5,$zero,0xb
/*  f11e14c:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f11e150:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11e154:	240d000b */ 	addiu	$t5,$zero,0xb
.L0f11e158:
/*  f11e158:	1000007c */ 	beqz	$zero,.L0f11e34c
/*  f11e15c:	ae0d0010 */ 	sw	$t5,0x10($s0)
/*  f11e160:	0fc52ba8 */ 	jal	func0f14aea0
/*  f11e164:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f11e168:	10400078 */ 	beqz	$v0,.L0f11e34c
/*  f11e16c:	240c0009 */ 	addiu	$t4,$zero,0x9
/*  f11e170:	10000076 */ 	beqz	$zero,.L0f11e34c
/*  f11e174:	ae0c0010 */ 	sw	$t4,0x10($s0)
/*  f11e178:	240b000a */ 	addiu	$t3,$zero,0xa
/*  f11e17c:	ae000008 */ 	sw	$zero,0x8($s0)
/*  f11e180:	10000072 */ 	beqz	$zero,.L0f11e34c
/*  f11e184:	ae0b0010 */ 	sw	$t3,0x10($s0)
/*  f11e188:	24180018 */ 	addiu	$t8,$zero,0x18
/*  f11e18c:	1000006f */ 	beqz	$zero,.L0f11e34c
/*  f11e190:	ae180010 */ 	sw	$t8,0x10($s0)
/*  f11e194:	240e0019 */ 	addiu	$t6,$zero,0x19
/*  f11e198:	1000006c */ 	beqz	$zero,.L0f11e34c
/*  f11e19c:	ae0e0010 */ 	sw	$t6,0x10($s0)
/*  f11e1a0:	2419000b */ 	addiu	$t9,$zero,0xb
/*  f11e1a4:	10000069 */ 	beqz	$zero,.L0f11e34c
/*  f11e1a8:	ae190010 */ 	sw	$t9,0x10($s0)
/*  f11e1ac:	2408000b */ 	addiu	$t0,$zero,0xb
/*  f11e1b0:	10000066 */ 	beqz	$zero,.L0f11e34c
/*  f11e1b4:	ae080010 */ 	sw	$t0,0x10($s0)
/*  f11e1b8:	3c0f8007 */ 	lui	$t7,0x8007
/*  f11e1bc:	8def5d14 */ 	lw	$t7,0x5d14($t7)
/*  f11e1c0:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f11e1c4:	51e00004 */ 	beqzl	$t7,.L0f11e1d8
/*  f11e1c8:	83aa0023 */ 	lb	$t2,0x23($sp)
/*  f11e1cc:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f11e1d0:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11e1d4:	83aa0023 */ 	lb	$t2,0x23($sp)
.L0f11e1d8:
/*  f11e1d8:	3c09800a */ 	lui	$t1,0x800a
/*  f11e1dc:	9129a490 */ 	lbu	$t1,-0x5b70($t1)
/*  f11e1e0:	240d0001 */ 	addiu	$t5,$zero,0x1
/*  f11e1e4:	014d6004 */ 	sllv	$t4,$t5,$t2
/*  f11e1e8:	012c5824 */ 	and	$t3,$t1,$t4
/*  f11e1ec:	11600057 */ 	beqz	$t3,.L0f11e34c
/*  f11e1f0:	01402025 */ 	or	$a0,$t2,$zero
/*  f11e1f4:	0fc3f47d */ 	jal	func0f0fd1f4
/*  f11e1f8:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11e1fc:	10400053 */ 	beqz	$v0,.L0f11e34c
/*  f11e200:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f11e204:	0fc3f4c8 */ 	jal	func0f0fd320
/*  f11e208:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11e20c:	24180014 */ 	addiu	$t8,$zero,0x14
/*  f11e210:	1000004e */ 	beqz	$zero,.L0f11e34c
/*  f11e214:	ae180010 */ 	sw	$t8,0x10($s0)
/*  f11e218:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f11e21c:	0fc3f47d */ 	jal	func0f0fd1f4
/*  f11e220:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f11e224:	10400049 */ 	beqz	$v0,.L0f11e34c
/*  f11e228:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f11e22c:	0fc3f4c8 */ 	jal	func0f0fd320
/*  f11e230:	24050003 */ 	addiu	$a1,$zero,0x3
/*  f11e234:	240e001b */ 	addiu	$t6,$zero,0x1b
/*  f11e238:	10000044 */ 	beqz	$zero,.L0f11e34c
/*  f11e23c:	ae0e0010 */ 	sw	$t6,0x10($s0)
/*  f11e240:	2419000b */ 	addiu	$t9,$zero,0xb
/*  f11e244:	10000041 */ 	beqz	$zero,.L0f11e34c
/*  f11e248:	ae190010 */ 	sw	$t9,0x10($s0)
/*  f11e24c:	3c088007 */ 	lui	$t0,0x8007
/*  f11e250:	8d085d14 */ 	lw	$t0,0x5d14($t0)
/*  f11e254:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f11e258:	51000004 */ 	beqzl	$t0,.L0f11e26c
/*  f11e25c:	83ad0023 */ 	lb	$t5,0x23($sp)
/*  f11e260:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f11e264:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11e268:	83ad0023 */ 	lb	$t5,0x23($sp)
.L0f11e26c:
/*  f11e26c:	3c0f800a */ 	lui	$t7,0x800a
/*  f11e270:	91efa490 */ 	lbu	$t7,-0x5b70($t7)
/*  f11e274:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f11e278:	01a96004 */ 	sllv	$t4,$t1,$t5
/*  f11e27c:	01ec5824 */ 	and	$t3,$t7,$t4
/*  f11e280:	11600032 */ 	beqz	$t3,.L0f11e34c
/*  f11e284:	01a02025 */ 	or	$a0,$t5,$zero
/*  f11e288:	0fc3f47d */ 	jal	func0f0fd1f4
/*  f11e28c:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f11e290:	1040002e */ 	beqz	$v0,.L0f11e34c
/*  f11e294:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f11e298:	0fc3f4c8 */ 	jal	func0f0fd320
/*  f11e29c:	24050002 */ 	addiu	$a1,$zero,0x2
/*  f11e2a0:	240a0013 */ 	addiu	$t2,$zero,0x13
/*  f11e2a4:	10000029 */ 	beqz	$zero,.L0f11e34c
/*  f11e2a8:	ae0a0010 */ 	sw	$t2,0x10($s0)
/*  f11e2ac:	3c188007 */ 	lui	$t8,0x8007
/*  f11e2b0:	8f185d14 */ 	lw	$t8,0x5d14($t8)
/*  f11e2b4:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f11e2b8:	53000004 */ 	beqzl	$t8,.L0f11e2cc
/*  f11e2bc:	83b90023 */ 	lb	$t9,0x23($sp)
/*  f11e2c0:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f11e2c4:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11e2c8:	83b90023 */ 	lb	$t9,0x23($sp)
.L0f11e2cc:
/*  f11e2cc:	3c0e800a */ 	lui	$t6,0x800a
/*  f11e2d0:	91cea490 */ 	lbu	$t6,-0x5b70($t6)
/*  f11e2d4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f11e2d8:	03284804 */ 	sllv	$t1,$t0,$t9
/*  f11e2dc:	01c97824 */ 	and	$t7,$t6,$t1
/*  f11e2e0:	11e0001a */ 	beqz	$t7,.L0f11e34c
/*  f11e2e4:	03202025 */ 	or	$a0,$t9,$zero
/*  f11e2e8:	0fc3f47d */ 	jal	func0f0fd1f4
/*  f11e2ec:	00002825 */ 	or	$a1,$zero,$zero
/*  f11e2f0:	10400016 */ 	beqz	$v0,.L0f11e34c
/*  f11e2f4:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f11e2f8:	0fc3f4c8 */ 	jal	func0f0fd320
/*  f11e2fc:	00002825 */ 	or	$a1,$zero,$zero
/*  f11e300:	240c0015 */ 	addiu	$t4,$zero,0x15
/*  f11e304:	10000011 */ 	beqz	$zero,.L0f11e34c
/*  f11e308:	ae0c0010 */ 	sw	$t4,0x10($s0)
/*  f11e30c:	3c0b8007 */ 	lui	$t3,0x8007
/*  f11e310:	8d6b5d14 */ 	lw	$t3,0x5d14($t3)
/*  f11e314:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f11e318:	5160000d */ 	beqzl	$t3,.L0f11e350
/*  f11e31c:	8e0a02b8 */ 	lw	$t2,0x2b8($s0)
/*  f11e320:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f11e324:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11e328:	10000009 */ 	beqz	$zero,.L0f11e350
/*  f11e32c:	8e0a02b8 */ 	lw	$t2,0x2b8($s0)
/*  f11e330:	3c0d8007 */ 	lui	$t5,0x8007
/*  f11e334:	8dad5d14 */ 	lw	$t5,0x5d14($t5)
/*  f11e338:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f11e33c:	51a00004 */ 	beqzl	$t5,.L0f11e350
/*  f11e340:	8e0a02b8 */ 	lw	$t2,0x2b8($s0)
/*  f11e344:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f11e348:	24050001 */ 	addiu	$a1,$zero,0x1
.L0f11e34c:
/*  f11e34c:	8e0a02b8 */ 	lw	$t2,0x2b8($s0)
.L0f11e350:
/*  f11e350:	3c0e8007 */ 	lui	$t6,0x8007
/*  f11e354:	000a4180 */ 	sll	$t0,$t2,0x6
/*  f11e358:	05030012 */ 	bgezl	$t0,.L0f11e3a4
/*  f11e35c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11e360:	8dce5d14 */ 	lw	$t6,0x5d14($t6)
/*  f11e364:	2404ffff */ 	addiu	$a0,$zero,-1
/*  f11e368:	51c00004 */ 	beqzl	$t6,.L0f11e37c
/*  f11e36c:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f11e370:	0fc3c328 */ 	jal	func0f0f0ca0
/*  f11e374:	24050001 */ 	addiu	$a1,$zero,0x1
/*  f11e378:	83a40023 */ 	lb	$a0,0x23($sp)
.L0f11e37c:
/*  f11e37c:	0fc3f47d */ 	jal	func0f0fd1f4
/*  f11e380:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f11e384:	10400006 */ 	beqz	$v0,.L0f11e3a0
/*  f11e388:	83a40023 */ 	lb	$a0,0x23($sp)
/*  f11e38c:	0fc3f4c8 */ 	jal	func0f0fd320
/*  f11e390:	24050004 */ 	addiu	$a1,$zero,0x4
/*  f11e394:	920902b8 */ 	lbu	$t1,0x2b8($s0)
/*  f11e398:	312ffffd */ 	andi	$t7,$t1,0xfffd
/*  f11e39c:	a20f02b8 */ 	sb	$t7,0x2b8($s0)
.L0f11e3a0:
/*  f11e3a0:	8fbf001c */ 	lw	$ra,0x1c($sp)
.L0f11e3a4:
/*  f11e3a4:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f11e3a8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f11e3ac:	03e00008 */ 	jr	$ra
/*  f11e3b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11e3b4:	03e00008 */ 	jr	$ra
/*  f11e3b8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11e3bc
/*  f11e3bc:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11e3c0:	000e7e03 */ 	sra	$t7,$t6,0x18
/*  f11e3c4:	000fc080 */ 	sll	$t8,$t7,0x2
/*  f11e3c8:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11e3cc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11e3d0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11e3d4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11e3d8:	030fc021 */ 	addu	$t8,$t8,$t7
/*  f11e3dc:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11e3e0:	030fc023 */ 	subu	$t8,$t8,$t7
/*  f11e3e4:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11e3e8:	3c01800a */ 	lui	$at,0x800a
/*  f11e3ec:	00380821 */ 	addu	$at,$at,$t8
/*  f11e3f0:	afa40000 */ 	sw	$a0,0x0($sp)
/*  f11e3f4:	03e00008 */ 	jr	$ra
/*  f11e3f8:	ac202388 */ 	sw	$zero,0x2388($at)
);

GLOBAL_ASM(
glabel func0f11e3fc
/*  f11e3fc:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f11e400:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11e404:	0c00543a */ 	jal	func000150e8
/*  f11e408:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11e40c:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*  f11e410:	0c01404c */ 	jal	func00050130
/*  f11e414:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*  f11e418:	0c005451 */ 	jal	func00015144
/*  f11e41c:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f11e420:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f11e424:	24010002 */ 	addiu	$at,$zero,0x2
/*  f11e428:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f11e42c:	15c1000c */ 	bne	$t6,$at,.L0f11e460
/*  f11e430:	24040001 */ 	addiu	$a0,$zero,0x1
/*  f11e434:	3c018007 */ 	lui	$at,0x8007
/*  f11e438:	3c057f1b */ 	lui	$a1,%hi(var7f1b4d1c)
/*  f11e43c:	ac2f5cd0 */ 	sw	$t7,0x5cd0($at)
/*  f11e440:	0c004c04 */ 	jal	func00013010
/*  f11e444:	24a54d1c */ 	addiu	$a1,$a1,%lo(var7f1b4d1c)
/*  f11e448:	50400008 */ 	beqzl	$v0,.L0f11e46c
/*  f11e44c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11e450:	0fc46d52 */ 	jal	func0f11b548
/*  f11e454:	24040004 */ 	addiu	$a0,$zero,0x4
/*  f11e458:	10000004 */ 	beqz	$zero,.L0f11e46c
/*  f11e45c:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f11e460:
/*  f11e460:	3c018007 */ 	lui	$at,0x8007
/*  f11e464:	ac205cd0 */ 	sw	$zero,0x5cd0($at)
/*  f11e468:	8fbf0014 */ 	lw	$ra,0x14($sp)
.L0f11e46c:
/*  f11e46c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f11e470:	03e00008 */ 	jr	$ra
/*  f11e474:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11e478
/*  f11e478:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f11e47c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11e480:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f11e484:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f11e488:	0c00543a */ 	jal	func000150e8
/*  f11e48c:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f11e490:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*  f11e494:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*  f11e498:	93a50023 */ 	lbu	$a1,0x23($sp)
/*  f11e49c:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f11e4a0:	0c0140fc */ 	jal	func000503f0
/*  f11e4a4:	8fa70028 */ 	lw	$a3,0x28($sp)
/*  f11e4a8:	0c005451 */ 	jal	func00015144
/*  f11e4ac:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f11e4b0:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f11e4b4:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11e4b8:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f11e4bc:	15c00003 */ 	bnez	$t6,.L0f11e4cc
/*  f11e4c0:	24030081 */ 	addiu	$v1,$zero,0x81
/*  f11e4c4:	10000001 */ 	beqz	$zero,.L0f11e4cc
/*  f11e4c8:	00001825 */ 	or	$v1,$zero,$zero
.L0f11e4cc:
/*  f11e4cc:	03e00008 */ 	jr	$ra
/*  f11e4d0:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f11e4d4
/*  f11e4d4:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f11e4d8:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11e4dc:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f11e4e0:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f11e4e4:	0c00543a */ 	jal	func000150e8
/*  f11e4e8:	afa60028 */ 	sw	$a2,0x28($sp)
/*  f11e4ec:	3c04800a */ 	lui	$a0,%hi(var80099e78)
/*  f11e4f0:	24849e78 */ 	addiu	$a0,$a0,%lo(var80099e78)
/*  f11e4f4:	93a50023 */ 	lbu	$a1,0x23($sp)
/*  f11e4f8:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f11e4fc:	0c001910 */ 	jal	func00006440
/*  f11e500:	8fa70028 */ 	lw	$a3,0x28($sp)
/*  f11e504:	0c005451 */ 	jal	func00015144
/*  f11e508:	afa2001c */ 	sw	$v0,0x1c($sp)
/*  f11e50c:	8fae001c */ 	lw	$t6,0x1c($sp)
/*  f11e510:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11e514:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f11e518:	15c00003 */ 	bnez	$t6,.L0f11e528
/*  f11e51c:	24030082 */ 	addiu	$v1,$zero,0x82
/*  f11e520:	10000001 */ 	beqz	$zero,.L0f11e528
/*  f11e524:	00001825 */ 	or	$v1,$zero,$zero
.L0f11e528:
/*  f11e528:	03e00008 */ 	jr	$ra
/*  f11e52c:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f11e530
/*  f11e530:	10c0000a */ 	beqz	$a2,.L0f11e55c
/*  f11e534:	000458c2 */ 	srl	$t3,$a0,0x3
/*  f11e538:	000470c2 */ 	srl	$t6,$a0,0x3
/*  f11e53c:	00ae1021 */ 	addu	$v0,$a1,$t6
/*  f11e540:	904f0000 */ 	lbu	$t7,0x0($v0)
/*  f11e544:	30980007 */ 	andi	$t8,$a0,0x7
/*  f11e548:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f11e54c:	03194804 */ 	sllv	$t1,$t9,$t8
/*  f11e550:	01e95025 */ 	or	$t2,$t7,$t1
/*  f11e554:	03e00008 */ 	jr	$ra
/*  f11e558:	a04a0000 */ 	sb	$t2,0x0($v0)
.L0f11e55c:
/*  f11e55c:	00ab1021 */ 	addu	$v0,$a1,$t3
/*  f11e560:	904c0000 */ 	lbu	$t4,0x0($v0)
/*  f11e564:	308d0007 */ 	andi	$t5,$a0,0x7
/*  f11e568:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f11e56c:	01aec004 */ 	sllv	$t8,$t6,$t5
/*  f11e570:	03007827 */ 	nor	$t7,$t8,$zero
/*  f11e574:	018f4824 */ 	and	$t1,$t4,$t7
/*  f11e578:	a0490000 */ 	sb	$t1,0x0($v0)
/*  f11e57c:	03e00008 */ 	jr	$ra
/*  f11e580:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11e584
/*  f11e584:	000470c2 */ 	srl	$t6,$a0,0x3
/*  f11e588:	00ae7821 */ 	addu	$t7,$a1,$t6
/*  f11e58c:	91f80000 */ 	lbu	$t8,0x0($t7)
/*  f11e590:	30990007 */ 	andi	$t9,$a0,0x7
/*  f11e594:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f11e598:	03284804 */ 	sllv	$t1,$t0,$t9
/*  f11e59c:	312a00ff */ 	andi	$t2,$t1,0xff
/*  f11e5a0:	030a5824 */ 	and	$t3,$t8,$t2
/*  f11e5a4:	11600003 */ 	beqz	$t3,.L0f11e5b4
/*  f11e5a8:	00001825 */ 	or	$v1,$zero,$zero
/*  f11e5ac:	03e00008 */ 	jr	$ra
/*  f11e5b0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11e5b4:
/*  f11e5b4:	03e00008 */ 	jr	$ra
/*  f11e5b8:	00601025 */ 	or	$v0,$v1,$zero
);

GLOBAL_ASM(
glabel func0f11e5bc
/*  f11e5bc:	27bdffd8 */ 	addiu	$sp,$sp,-40
/*  f11e5c0:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f11e5c4:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f11e5c8:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11e5cc:	00808825 */ 	or	$s1,$a0,$zero
/*  f11e5d0:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f11e5d4:	00008025 */ 	or	$s0,$zero,$zero
/*  f11e5d8:	2412004f */ 	addiu	$s2,$zero,0x4f
/*  f11e5dc:	02002025 */ 	or	$a0,$s0,$zero
.L0f11e5e0:
/*  f11e5e0:	02202825 */ 	or	$a1,$s1,$zero
/*  f11e5e4:	0fc4794c */ 	jal	func0f11e530
/*  f11e5e8:	00003025 */ 	or	$a2,$zero,$zero
/*  f11e5ec:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11e5f0:	5612fffb */ 	bnel	$s0,$s2,.L0f11e5e0
/*  f11e5f4:	02002025 */ 	or	$a0,$s0,$zero
/*  f11e5f8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f11e5fc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f11e600:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f11e604:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f11e608:	03e00008 */ 	jr	$ra
/*  f11e60c:	27bd0028 */ 	addiu	$sp,$sp,0x28
/*  f11e610:	03e00008 */ 	jr	$ra
/*  f11e614:	00801025 */ 	or	$v0,$a0,$zero
);

GLOBAL_ASM(
glabel func0f11e618
/*  f11e618:	27bdfed0 */ 	addiu	$sp,$sp,-304
/*  f11e61c:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11e620:	00808025 */ 	or	$s0,$a0,$zero
/*  f11e624:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11e628:	afa50134 */ 	sw	$a1,0x134($sp)
/*  f11e62c:	27a30030 */ 	addiu	$v1,$sp,0x30
/*  f11e630:	18c00016 */ 	blez	$a2,.L0f11e68c
/*  f11e634:	00003825 */ 	or	$a3,$zero,$zero
/*  f11e638:	3c087f1b */ 	lui	$t0,%hi(var7f1b3a90)
/*  f11e63c:	25083a90 */ 	addiu	$t0,$t0,%lo(var7f1b3a90)
/*  f11e640:	24090022 */ 	addiu	$t1,$zero,0x22
/*  f11e644:	24050027 */ 	addiu	$a1,$zero,0x27
.L0f11e648:
/*  f11e648:	92040000 */ 	lbu	$a0,0x0($s0)
/*  f11e64c:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11e650:	24e70001 */ 	addiu	$a3,$a3,0x1
/*  f11e654:	28810042 */ 	slti	$at,$a0,0x42
/*  f11e658:	10200003 */ 	beqz	$at,.L0f11e668
/*  f11e65c:	2402002a */ 	addiu	$v0,$zero,0x2a
/*  f11e660:	01047021 */ 	addu	$t6,$t0,$a0
/*  f11e664:	91c20000 */ 	lbu	$v0,0x0($t6)
.L0f11e668:
/*  f11e668:	54490006 */ 	bnel	$v0,$t1,.L0f11e684
/*  f11e66c:	a0620000 */ 	sb	$v0,0x0($v1)
/*  f11e670:	a0650000 */ 	sb	$a1,0x0($v1)
/*  f11e674:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f11e678:	10000002 */ 	beqz	$zero,.L0f11e684
/*  f11e67c:	a0650000 */ 	sb	$a1,0x0($v1)
/*  f11e680:	a0620000 */ 	sb	$v0,0x0($v1)
.L0f11e684:
/*  f11e684:	14e6fff0 */ 	bne	$a3,$a2,.L0f11e648
/*  f11e688:	24630001 */ 	addiu	$v1,$v1,0x1
.L0f11e68c:
/*  f11e68c:	a0600000 */ 	sb	$zero,0x0($v1)
/*  f11e690:	8fa40134 */ 	lw	$a0,0x134($sp)
/*  f11e694:	0c004c4c */ 	jal	strcpy
/*  f11e698:	27a50030 */ 	addiu	$a1,$sp,0x30
/*  f11e69c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11e6a0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f11e6a4:	27bd0130 */ 	addiu	$sp,$sp,0x130
/*  f11e6a8:	03e00008 */ 	jr	$ra
/*  f11e6ac:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11e6b0
/*  f11e6b0:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f11e6b4:	afb40028 */ 	sw	$s4,0x28($sp)
/*  f11e6b8:	afb30024 */ 	sw	$s3,0x24($sp)
/*  f11e6bc:	afb20020 */ 	sw	$s2,0x20($sp)
/*  f11e6c0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11e6c4:	00809825 */ 	or	$s3,$a0,$zero
/*  f11e6c8:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f11e6cc:	afb1001c */ 	sw	$s1,0x1c($sp)
/*  f11e6d0:	2412ffff */ 	addiu	$s2,$zero,-1
/*  f11e6d4:	00008025 */ 	or	$s0,$zero,$zero
/*  f11e6d8:	24140005 */ 	addiu	$s4,$zero,0x5
/*  f11e6dc:	00108e00 */ 	sll	$s1,$s0,0x18
.L0f11e6e0:
/*  f11e6e0:	00117603 */ 	sra	$t6,$s1,0x18
/*  f11e6e4:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f11e6e8:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f11e6ec:	01e02025 */ 	or	$a0,$t7,$zero
/*  f11e6f0:	0fc45abb */ 	jal	func0f116aec
/*  f11e6f4:	01c08825 */ 	or	$s1,$t6,$zero
/*  f11e6f8:	10400009 */ 	beqz	$v0,.L0f11e720
/*  f11e6fc:	00112600 */ 	sll	$a0,$s1,0x18
/*  f11e700:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f11e704:	0fc45a4f */ 	jal	func0f11693c
/*  f11e708:	03002025 */ 	or	$a0,$t8,$zero
/*  f11e70c:	56620005 */ 	bnel	$s3,$v0,.L0f11e724
/*  f11e710:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11e714:	00109600 */ 	sll	$s2,$s0,0x18
/*  f11e718:	0012ce03 */ 	sra	$t9,$s2,0x18
/*  f11e71c:	03209025 */ 	or	$s2,$t9,$zero
.L0f11e720:
/*  f11e720:	26100001 */ 	addiu	$s0,$s0,0x1
.L0f11e724:
/*  f11e724:	5614ffee */ 	bnel	$s0,$s4,.L0f11e6e0
/*  f11e728:	00108e00 */ 	sll	$s1,$s0,0x18
/*  f11e72c:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f11e730:	02401025 */ 	or	$v0,$s2,$zero
/*  f11e734:	8fb20020 */ 	lw	$s2,0x20($sp)
/*  f11e738:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f11e73c:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*  f11e740:	8fb30024 */ 	lw	$s3,0x24($sp)
/*  f11e744:	8fb40028 */ 	lw	$s4,0x28($sp)
/*  f11e748:	03e00008 */ 	jr	$ra
/*  f11e74c:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f11e750
/*  f11e750:	27bdffc8 */ 	addiu	$sp,$sp,-56
/*  f11e754:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11e758:	afa40038 */ 	sw	$a0,0x38($sp)
/*  f11e75c:	00047600 */ 	sll	$t6,$a0,0x18
/*  f11e760:	2418000a */ 	addiu	$t8,$zero,0xa
/*  f11e764:	000e2603 */ 	sra	$a0,$t6,0x18
/*  f11e768:	a3b80018 */ 	sb	$t8,0x18($sp)
/*  f11e76c:	27a60018 */ 	addiu	$a2,$sp,0x18
/*  f11e770:	00002825 */ 	or	$a1,$zero,$zero
/*  f11e774:	0fc4731b */ 	jal	func0f11cc6c
/*  f11e778:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11e77c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11e780:	27bd0038 */ 	addiu	$sp,$sp,0x38
/*  f11e784:	03e00008 */ 	jr	$ra
/*  f11e788:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11e78c
/*  f11e78c:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f11e790:	afb10018 */ 	sw	$s1,0x18($sp)
/*  f11e794:	afb00014 */ 	sw	$s0,0x14($sp)
/*  f11e798:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11e79c:	00008025 */ 	or	$s0,$zero,$zero
/*  f11e7a0:	24110002 */ 	addiu	$s1,$zero,0x2
/*  f11e7a4:	00102600 */ 	sll	$a0,$s0,0x18
.L0f11e7a8:
/*  f11e7a8:	00047603 */ 	sra	$t6,$a0,0x18
/*  f11e7ac:	0fc47a11 */ 	jal	func0f11e844
/*  f11e7b0:	01c02025 */ 	or	$a0,$t6,$zero
/*  f11e7b4:	14510003 */ 	bne	$v0,$s1,.L0f11e7c4
/*  f11e7b8:	26100001 */ 	addiu	$s0,$s0,0x1
/*  f11e7bc:	10000007 */ 	beqz	$zero,.L0f11e7dc
/*  f11e7c0:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11e7c4:
/*  f11e7c4:	00107e00 */ 	sll	$t7,$s0,0x18
/*  f11e7c8:	000f8603 */ 	sra	$s0,$t7,0x18
/*  f11e7cc:	2a010004 */ 	slti	$at,$s0,0x4
/*  f11e7d0:	5420fff5 */ 	bnezl	$at,.L0f11e7a8
/*  f11e7d4:	00102600 */ 	sll	$a0,$s0,0x18
/*  f11e7d8:	00001025 */ 	or	$v0,$zero,$zero
.L0f11e7dc:
/*  f11e7dc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11e7e0:	8fb00014 */ 	lw	$s0,0x14($sp)
/*  f11e7e4:	8fb10018 */ 	lw	$s1,0x18($sp)
/*  f11e7e8:	03e00008 */ 	jr	$ra
/*  f11e7ec:	27bd0020 */ 	addiu	$sp,$sp,0x20
);

GLOBAL_ASM(
glabel func0f11e7f0
/*  f11e7f0:	90820000 */ 	lbu	$v0,0x0($a0)
/*  f11e7f4:	50400011 */ 	beqzl	$v0,.L0f11e83c
/*  f11e7f8:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11e7fc:	90a30000 */ 	lbu	$v1,0x0($a1)
/*  f11e800:	5060000e */ 	beqzl	$v1,.L0f11e83c
/*  f11e804:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11e808:
/*  f11e808:	50430004 */ 	beql	$v0,$v1,.L0f11e81c
/*  f11e80c:	90820001 */ 	lbu	$v0,0x1($a0)
/*  f11e810:	03e00008 */ 	jr	$ra
/*  f11e814:	00001025 */ 	or	$v0,$zero,$zero
/*  f11e818:	90820001 */ 	lbu	$v0,0x1($a0)
.L0f11e81c:
/*  f11e81c:	24840001 */ 	addiu	$a0,$a0,0x1
/*  f11e820:	24a50001 */ 	addiu	$a1,$a1,0x1
/*  f11e824:	50400005 */ 	beqzl	$v0,.L0f11e83c
/*  f11e828:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11e82c:	90a30000 */ 	lbu	$v1,0x0($a1)
/*  f11e830:	1460fff5 */ 	bnez	$v1,.L0f11e808
/*  f11e834:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11e838:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11e83c:
/*  f11e83c:	03e00008 */ 	jr	$ra
/*  f11e840:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11e844
/*  f11e844:	00043e00 */ 	sll	$a3,$a0,0x18
/*  f11e848:	00077603 */ 	sra	$t6,$a3,0x18
/*  f11e84c:	000ec080 */ 	sll	$t8,$t6,0x2
/*  f11e850:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f11e854:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11e858:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f11e85c:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11e860:	030ec021 */ 	addu	$t8,$t8,$t6
/*  f11e864:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11e868:	030ec023 */ 	subu	$t8,$t8,$t6
/*  f11e86c:	3c19800a */ 	lui	$t9,%hi(var800a2380)
/*  f11e870:	27392380 */ 	addiu	$t9,$t9,%lo(var800a2380)
/*  f11e874:	0018c080 */ 	sll	$t8,$t8,0x2
/*  f11e878:	27bdff78 */ 	addiu	$sp,$sp,-136
/*  f11e87c:	03191821 */ 	addu	$v1,$t8,$t9
/*  f11e880:	8c680000 */ 	lw	$t0,0x0($v1)
/*  f11e884:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f11e888:	24010003 */ 	addiu	$at,$zero,0x3
/*  f11e88c:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11e890:	afa40088 */ 	sw	$a0,0x88($sp)
/*  f11e894:	01c03825 */ 	or	$a3,$t6,$zero
/*  f11e898:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f11e89c:	afa00028 */ 	sw	$zero,0x28($sp)
/*  f11e8a0:	11010003 */ 	beq	$t0,$at,.L0f11e8b0
/*  f11e8a4:	afaf0024 */ 	sw	$t7,0x24($sp)
/*  f11e8a8:	1000005e */ 	beqz	$zero,.L0f11ea24
/*  f11e8ac:	00001025 */ 	or	$v0,$zero,$zero
.L0f11e8b0:
/*  f11e8b0:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f11e8b4:	0c00543a */ 	jal	func000150e8
/*  f11e8b8:	a3a7008b */ 	sb	$a3,0x8b($sp)
/*  f11e8bc:	83a7008b */ 	lb	$a3,0x8b($sp)
/*  f11e8c0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11e8c4:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f11e8c8:	14e10003 */ 	bne	$a3,$at,.L0f11e8d8
/*  f11e8cc:	27a50038 */ 	addiu	$a1,$sp,0x38
/*  f11e8d0:	10000009 */ 	beqz	$zero,.L0f11e8f8
/*  f11e8d4:	00002025 */ 	or	$a0,$zero,$zero
.L0f11e8d8:
/*  f11e8d8:	00074880 */ 	sll	$t1,$a3,0x2
/*  f11e8dc:	01274823 */ 	subu	$t1,$t1,$a3
/*  f11e8e0:	00094880 */ 	sll	$t1,$t1,0x2
/*  f11e8e4:	01274821 */ 	addu	$t1,$t1,$a3
/*  f11e8e8:	3c0a800a */ 	lui	$t2,%hi(var800a3180)
/*  f11e8ec:	254a3180 */ 	addiu	$t2,$t2,%lo(var800a3180)
/*  f11e8f0:	000948c0 */ 	sll	$t1,$t1,0x3
/*  f11e8f4:	012a2021 */ 	addu	$a0,$t1,$t2
.L0f11e8f8:
/*  f11e8f8:	27a60037 */ 	addiu	$a2,$sp,0x37
/*  f11e8fc:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f11e900:	0c014358 */ 	jal	func00050d60
/*  f11e904:	a3a7008b */ 	sb	$a3,0x8b($sp)
/*  f11e908:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f11e90c:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f11e910:	83a7008b */ 	lb	$a3,0x8b($sp)
/*  f11e914:	10400002 */ 	beqz	$v0,.L0f11e920
/*  f11e918:	afab0028 */ 	sw	$t3,0x28($sp)
/*  f11e91c:	afa00024 */ 	sw	$zero,0x24($sp)
.L0f11e920:
/*  f11e920:	3c0d8007 */ 	lui	$t5,0x8007
/*  f11e924:	95ad5cb0 */ 	lhu	$t5,0x5cb0($t5)
/*  f11e928:	97ac007c */ 	lhu	$t4,0x7c($sp)
/*  f11e92c:	3c048007 */ 	lui	$a0,%hi(var80075cb4)
/*  f11e930:	24845cb4 */ 	addiu	$a0,$a0,%lo(var80075cb4)
/*  f11e934:	158d0017 */ 	bne	$t4,$t5,.L0f11e994
/*  f11e938:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f11e93c:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f11e940:	0fc479fc */ 	jal	func0f11e7f0
/*  f11e944:	a3a7008b */ 	sb	$a3,0x8b($sp)
/*  f11e948:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f11e94c:	1440000a */ 	bnez	$v0,.L0f11e978
/*  f11e950:	83a7008b */ 	lb	$a3,0x8b($sp)
/*  f11e954:	3c048007 */ 	lui	$a0,%hi(var80075cc0)
/*  f11e958:	24845cc0 */ 	addiu	$a0,$a0,%lo(var80075cc0)
/*  f11e95c:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*  f11e960:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f11e964:	0fc479fc */ 	jal	func0f11e7f0
/*  f11e968:	a3a7008b */ 	sb	$a3,0x8b($sp)
/*  f11e96c:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f11e970:	10400008 */ 	beqz	$v0,.L0f11e994
/*  f11e974:	83a7008b */ 	lb	$a3,0x8b($sp)
.L0f11e978:
/*  f11e978:	906e02b8 */ 	lbu	$t6,0x2b8($v1)
/*  f11e97c:	24090002 */ 	addiu	$t1,$zero,0x2
/*  f11e980:	afa9002c */ 	sw	$t1,0x2c($sp)
/*  f11e984:	31d9ffdf */ 	andi	$t9,$t6,0xffdf
/*  f11e988:	a07902b8 */ 	sb	$t9,0x2b8($v1)
/*  f11e98c:	37280010 */ 	ori	$t0,$t9,0x10
/*  f11e990:	a06802b8 */ 	sb	$t0,0x2b8($v1)
.L0f11e994:
/*  f11e994:	8faa002c */ 	lw	$t2,0x2c($sp)
/*  f11e998:	24010002 */ 	addiu	$at,$zero,0x2
/*  f11e99c:	00002825 */ 	or	$a1,$zero,$zero
/*  f11e9a0:	51410003 */ 	beql	$t2,$at,.L0f11e9b0
/*  f11e9a4:	8fab0028 */ 	lw	$t3,0x28($sp)
/*  f11e9a8:	afa00024 */ 	sw	$zero,0x24($sp)
/*  f11e9ac:	8fab0028 */ 	lw	$t3,0x28($sp)
.L0f11e9b0:
/*  f11e9b0:	24010004 */ 	addiu	$at,$zero,0x4
/*  f11e9b4:	11600011 */ 	beqz	$t3,.L0f11e9fc
/*  f11e9b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11e9bc:	14e10003 */ 	bne	$a3,$at,.L0f11e9cc
/*  f11e9c0:	00076080 */ 	sll	$t4,$a3,0x2
/*  f11e9c4:	10000008 */ 	beqz	$zero,.L0f11e9e8
/*  f11e9c8:	00002025 */ 	or	$a0,$zero,$zero
.L0f11e9cc:
/*  f11e9cc:	01876023 */ 	subu	$t4,$t4,$a3
/*  f11e9d0:	000c6080 */ 	sll	$t4,$t4,0x2
/*  f11e9d4:	01876021 */ 	addu	$t4,$t4,$a3
/*  f11e9d8:	3c0d800a */ 	lui	$t5,%hi(var800a3180)
/*  f11e9dc:	25ad3180 */ 	addiu	$t5,$t5,%lo(var800a3180)
/*  f11e9e0:	000c60c0 */ 	sll	$t4,$t4,0x3
/*  f11e9e4:	018d2021 */ 	addu	$a0,$t4,$t5
.L0f11e9e8:
/*  f11e9e8:	0c0018cc */ 	jal	func00006330
/*  f11e9ec:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f11e9f0:	10400002 */ 	beqz	$v0,.L0f11e9fc
/*  f11e9f4:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f11e9f8:	afa00024 */ 	sw	$zero,0x24($sp)
.L0f11e9fc:
/*  f11e9fc:	0c005451 */ 	jal	func00015144
/*  f11ea00:	afa3001c */ 	sw	$v1,0x1c($sp)
/*  f11ea04:	8fae0024 */ 	lw	$t6,0x24($sp)
/*  f11ea08:	8fa3001c */ 	lw	$v1,0x1c($sp)
/*  f11ea0c:	240f001a */ 	addiu	$t7,$zero,0x1a
/*  f11ea10:	11c00003 */ 	beqz	$t6,.L0f11ea20
/*  f11ea14:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ea18:	10000002 */ 	beqz	$zero,.L0f11ea24
/*  f11ea1c:	8fa2002c */ 	lw	$v0,0x2c($sp)
.L0f11ea20:
/*  f11ea20:	ac6f0010 */ 	sw	$t7,0x10($v1)
.L0f11ea24:
/*  f11ea24:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11ea28:	27bd0088 */ 	addiu	$sp,$sp,0x88
/*  f11ea2c:	03e00008 */ 	jr	$ra
/*  f11ea30:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11ea34
/*  f11ea34:	27bdff90 */ 	addiu	$sp,$sp,-112
/*  f11ea38:	3c0e7f1b */ 	lui	$t6,%hi(var7f1b4d54)
/*  f11ea3c:	27a60044 */ 	addiu	$a2,$sp,0x44
/*  f11ea40:	25ce4d54 */ 	addiu	$t6,$t6,%lo(var7f1b4d54)
/*  f11ea44:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11ea48:	afa40070 */ 	sw	$a0,0x70($sp)
/*  f11ea4c:	25d90024 */ 	addiu	$t9,$t6,0x24
/*  f11ea50:	00c04025 */ 	or	$t0,$a2,$zero
.L0f11ea54:
/*  f11ea54:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f11ea58:	25ce000c */ 	addiu	$t6,$t6,0xc
/*  f11ea5c:	2508000c */ 	addiu	$t0,$t0,0xc
/*  f11ea60:	ad01fff4 */ 	sw	$at,-0xc($t0)
/*  f11ea64:	8dc1fff8 */ 	lw	$at,-0x8($t6)
/*  f11ea68:	ad01fff8 */ 	sw	$at,-0x8($t0)
/*  f11ea6c:	8dc1fffc */ 	lw	$at,-0x4($t6)
/*  f11ea70:	15d9fff8 */ 	bne	$t6,$t9,.L0f11ea54
/*  f11ea74:	ad01fffc */ 	sw	$at,-0x4($t0)
/*  f11ea78:	8dc10000 */ 	lw	$at,0x0($t6)
/*  f11ea7c:	24090001 */ 	addiu	$t1,$zero,0x1
/*  f11ea80:	3405a000 */ 	dli	$a1,0xa000
/*  f11ea84:	ad010000 */ 	sw	$at,0x0($t0)
/*  f11ea88:	91c10004 */ 	lbu	$at,0x4($t6)
/*  f11ea8c:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11ea90:	a1010004 */ 	sb	$at,0x4($t0)
/*  f11ea94:	afa90010 */ 	sw	$t1,0x10($sp)
/*  f11ea98:	0fc47340 */ 	jal	func0f11cd00
/*  f11ea9c:	83a40073 */ 	lb	$a0,0x73($sp)
/*  f11eaa0:	14400003 */ 	bnez	$v0,.L0f11eab0
/*  f11eaa4:	83a40073 */ 	lb	$a0,0x73($sp)
/*  f11eaa8:	1000000c */ 	beqz	$zero,.L0f11eadc
/*  f11eaac:	00001025 */ 	or	$v0,$zero,$zero
.L0f11eab0:
/*  f11eab0:	240a0001 */ 	addiu	$t2,$zero,0x1
/*  f11eab4:	afaa0010 */ 	sw	$t2,0x10($sp)
/*  f11eab8:	3405a000 */ 	dli	$a1,0xa000
/*  f11eabc:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f11eac0:	0fc47380 */ 	jal	func0f11ce00
/*  f11eac4:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11eac8:	54400004 */ 	bnezl	$v0,.L0f11eadc
/*  f11eacc:	24020001 */ 	addiu	$v0,$zero,0x1
/*  f11ead0:	10000002 */ 	beqz	$zero,.L0f11eadc
/*  f11ead4:	00001025 */ 	or	$v0,$zero,$zero
/*  f11ead8:	24020001 */ 	addiu	$v0,$zero,0x1
.L0f11eadc:
/*  f11eadc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11eae0:	27bd0070 */ 	addiu	$sp,$sp,0x70
/*  f11eae4:	03e00008 */ 	jr	$ra
/*  f11eae8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11eaec:	27bdff68 */ 	addiu	$sp,$sp,-152
/*  f11eaf0:	afa40098 */ 	sw	$a0,0x98($sp)
/*  f11eaf4:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11eaf8:	afa00030 */ 	sw	$zero,0x30($sp)
/*  f11eafc:	afa0002c */ 	sw	$zero,0x2c($sp)
/*  f11eb00:	27a40078 */ 	addiu	$a0,$sp,0x78
/*  f11eb04:	27a30078 */ 	addiu	$v1,$sp,0x78
/*  f11eb08:	27a20058 */ 	addiu	$v0,$sp,0x58
.L0f11eb0c:
/*  f11eb0c:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11eb10:	0044082b */ 	sltu	$at,$v0,$a0
/*  f11eb14:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f11eb18:	a060ffff */ 	sb	$zero,-0x1($v1)
/*  f11eb1c:	1420fffb */ 	bnez	$at,.L0f11eb0c
/*  f11eb20:	a040ffff */ 	sb	$zero,-0x1($v0)
/*  f11eb24:	a3a00078 */ 	sb	$zero,0x78($sp)
/*  f11eb28:	0fc47a8d */ 	jal	func0f11ea34
/*  f11eb2c:	83a4009b */ 	lb	$a0,0x9b($sp)
/*  f11eb30:	0fc47a8d */ 	jal	func0f11ea34
/*  f11eb34:	83a4009b */ 	lb	$a0,0x9b($sp)
/*  f11eb38:	0fc47a8d */ 	jal	func0f11ea34
/*  f11eb3c:	83a4009b */ 	lb	$a0,0x9b($sp)
/*  f11eb40:	240e0001 */ 	addiu	$t6,$zero,0x1
/*  f11eb44:	afae0010 */ 	sw	$t6,0x10($sp)
/*  f11eb48:	83a4009b */ 	lb	$a0,0x9b($sp)
/*  f11eb4c:	3405bfe0 */ 	dli	$a1,0xbfe0
/*  f11eb50:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f11eb54:	0fc47380 */ 	jal	func0f11ce00
/*  f11eb58:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11eb5c:	14400003 */ 	bnez	$v0,.L0f11eb6c
/*  f11eb60:	27a30058 */ 	addiu	$v1,$sp,0x58
/*  f11eb64:	240f0001 */ 	addiu	$t7,$zero,0x1
/*  f11eb68:	afaf0030 */ 	sw	$t7,0x30($sp)
.L0f11eb6c:
/*  f11eb6c:	27a20038 */ 	addiu	$v0,$sp,0x38
/*  f11eb70:	a3a00029 */ 	sb	$zero,0x29($sp)
.L0f11eb74:
/*  f11eb74:	90580000 */ 	lbu	$t8,0x0($v0)
/*  f11eb78:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f11eb7c:	1443fffd */ 	bne	$v0,$v1,.L0f11eb74
/*  f11eb80:	a3b80028 */ 	sb	$t8,0x28($sp)
/*  f11eb84:	3c047f1b */ 	lui	$a0,%hi(var7f1b4d80)
/*  f11eb88:	24844d80 */ 	addiu	$a0,$a0,%lo(var7f1b4d80)
/*  f11eb8c:	0fc479fc */ 	jal	func0f11e7f0
/*  f11eb90:	27a50038 */ 	addiu	$a1,$sp,0x38
/*  f11eb94:	24190001 */ 	addiu	$t9,$zero,0x1
/*  f11eb98:	afb90010 */ 	sw	$t9,0x10($sp)
/*  f11eb9c:	83a4009b */ 	lb	$a0,0x9b($sp)
/*  f11eba0:	3405a000 */ 	dli	$a1,0xa000
/*  f11eba4:	27a60038 */ 	addiu	$a2,$sp,0x38
/*  f11eba8:	0fc47380 */ 	jal	func0f11ce00
/*  f11ebac:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11ebb0:	14400002 */ 	bnez	$v0,.L0f11ebbc
/*  f11ebb4:	24080001 */ 	addiu	$t0,$zero,0x1
/*  f11ebb8:	afa80030 */ 	sw	$t0,0x30($sp)
.L0f11ebbc:
/*  f11ebbc:	93a90038 */ 	lbu	$t1,0x38($sp)
/*  f11ebc0:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f11ebc4:	312a0001 */ 	andi	$t2,$t1,0x1
/*  f11ebc8:	51400003 */ 	beqzl	$t2,.L0f11ebd8
/*  f11ebcc:	8fac0030 */ 	lw	$t4,0x30($sp)
/*  f11ebd0:	afab002c */ 	sw	$t3,0x2c($sp)
/*  f11ebd4:	8fac0030 */ 	lw	$t4,0x30($sp)
.L0f11ebd8:
/*  f11ebd8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11ebdc:	8fa2002c */ 	lw	$v0,0x2c($sp)
/*  f11ebe0:	11800003 */ 	beqz	$t4,.L0f11ebf0
/*  f11ebe4:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ebe8:	10000001 */ 	beqz	$zero,.L0f11ebf0
/*  f11ebec:	00001025 */ 	or	$v0,$zero,$zero
.L0f11ebf0:
/*  f11ebf0:	03e00008 */ 	jr	$ra
/*  f11ebf4:	27bd0098 */ 	addiu	$sp,$sp,0x98
/*  f11ebf8:	27bdffc0 */ 	addiu	$sp,$sp,-64
/*  f11ebfc:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f11ec00:	00048600 */ 	sll	$s0,$a0,0x18
/*  f11ec04:	00107603 */ 	sra	$t6,$s0,0x18
/*  f11ec08:	afa40040 */ 	sw	$a0,0x40($sp)
/*  f11ec0c:	000e2600 */ 	sll	$a0,$t6,0x18
/*  f11ec10:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f11ec14:	00047e03 */ 	sra	$t7,$a0,0x18
/*  f11ec18:	01c08025 */ 	or	$s0,$t6,$zero
/*  f11ec1c:	01e02025 */ 	or	$a0,$t7,$zero
/*  f11ec20:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f11ec24:	3405a000 */ 	dli	$a1,0xa000
/*  f11ec28:	0fc472f6 */ 	jal	func0f11cbd8
/*  f11ec2c:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11ec30:	10400029 */ 	beqz	$v0,.L0f11ecd8
/*  f11ec34:	00102600 */ 	sll	$a0,$s0,0x18
/*  f11ec38:	0004c603 */ 	sra	$t8,$a0,0x18
/*  f11ec3c:	0fc479d4 */ 	jal	func0f11e750
/*  f11ec40:	03002025 */ 	or	$a0,$t8,$zero
/*  f11ec44:	93b90020 */ 	lbu	$t9,0x20($sp)
/*  f11ec48:	00102600 */ 	sll	$a0,$s0,0x18
/*  f11ec4c:	00044e03 */ 	sra	$t1,$a0,0x18
/*  f11ec50:	3328007f */ 	andi	$t0,$t9,0x7f
/*  f11ec54:	a3a80020 */ 	sb	$t0,0x20($sp)
/*  f11ec58:	01202025 */ 	or	$a0,$t1,$zero
/*  f11ec5c:	3405a000 */ 	dli	$a1,0xa000
/*  f11ec60:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f11ec64:	0fc4731b */ 	jal	func0f11cc6c
/*  f11ec68:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11ec6c:	1040001a */ 	beqz	$v0,.L0f11ecd8
/*  f11ec70:	00102600 */ 	sll	$a0,$s0,0x18
/*  f11ec74:	00045603 */ 	sra	$t2,$a0,0x18
/*  f11ec78:	01402025 */ 	or	$a0,$t2,$zero
/*  f11ec7c:	3405a000 */ 	dli	$a1,0xa000
/*  f11ec80:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f11ec84:	0fc472f6 */ 	jal	func0f11cbd8
/*  f11ec88:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11ec8c:	10400012 */ 	beqz	$v0,.L0f11ecd8
/*  f11ec90:	93ab0020 */ 	lbu	$t3,0x20($sp)
/*  f11ec94:	00102600 */ 	sll	$a0,$s0,0x18
/*  f11ec98:	356c0080 */ 	ori	$t4,$t3,0x80
/*  f11ec9c:	00046e03 */ 	sra	$t5,$a0,0x18
/*  f11eca0:	a3ac0020 */ 	sb	$t4,0x20($sp)
/*  f11eca4:	01a02025 */ 	or	$a0,$t5,$zero
/*  f11eca8:	3405a000 */ 	dli	$a1,0xa000
/*  f11ecac:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f11ecb0:	0fc4731b */ 	jal	func0f11cc6c
/*  f11ecb4:	24070020 */ 	addiu	$a3,$zero,0x20
/*  f11ecb8:	10400007 */ 	beqz	$v0,.L0f11ecd8
/*  f11ecbc:	00102600 */ 	sll	$a0,$s0,0x18
/*  f11ecc0:	00047603 */ 	sra	$t6,$a0,0x18
/*  f11ecc4:	01c02025 */ 	or	$a0,$t6,$zero
/*  f11ecc8:	3405a000 */ 	dli	$a1,0xa000
/*  f11eccc:	27a60020 */ 	addiu	$a2,$sp,0x20
/*  f11ecd0:	0fc472f6 */ 	jal	func0f11cbd8
/*  f11ecd4:	24070020 */ 	addiu	$a3,$zero,0x20
.L0f11ecd8:
/*  f11ecd8:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f11ecdc:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f11ece0:	27bd0040 */ 	addiu	$sp,$sp,0x40
/*  f11ece4:	03e00008 */ 	jr	$ra
/*  f11ece8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11ecec:	00000000 */ 	sll	$zero,$zero,0x0
);
