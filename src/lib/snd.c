#include <ultra64.h>
#include "n_libaudio.h"
#include "constants.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/music.h"
#include "bss.h"
#include "naudio/n_sndp.h"
#include "lib/rzip.h"
#include "lib/args.h"
#include "lib/audiomgr.h"
#include "lib/crash.h"
#include "lib/dma.h"
#include "lib/snd.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "lib/str.h"
#include "lib/osc.h"
#include "lib/lib_317f0.h"
#include "lib/mp3.h"
#include "lib/lib_39c80.h"
#include "lib/speaker.h"
#include "data.h"
#include "types.h"

#define MAX_SEQ_SIZE_4MB 1024 * 14
#define MAX_SEQ_SIZE_8MB 1024 * 18

#define NUM_CACHE_SLOTS 45
#define NUM_VOLUMES 9

struct sndcache {
	/*0x0000*/ u16 *indexes; // indexed by sfxnum, value is cache index (0-44) or 0xffff
	/*0x0004*/ u8 refcounts[NUM_CACHE_SLOTS];
	/*0x0032*/ u16 ages[NUM_CACHE_SLOTS];
	/*0x008c*/ ALEnvelope envelopes[NUM_CACHE_SLOTS];
	/*0x035c*/ ALKeyMap keymaps[NUM_CACHE_SLOTS];
	/*0x046c*/ ALWaveTable wavetables[NUM_CACHE_SLOTS];
	/*0x07f0*/ ALADPCMBook books[NUM_CACHE_SLOTS];
	/*0x3658*/ ALADPCMloop loops[NUM_CACHE_SLOTS];
	/*0x3e14*/ ALSound sounds[NUM_CACHE_SLOTS];
};

struct curmp3 {
	union soundnumhack sfxref;
	u32 playing;
	u32 unk08;
	s32 responsetimer240;
	s32 prevwhisper;
	s32 prevacknowledge;
	s32 prevgreeting;
	u32 romaddr;
	u32 romsize;
	s32 responsetype;
};

s32 g_NumSounds;
u32 *g_ALSoundRomOffsets;
s32 g_SndMaxFxBusses;
u32 var80094eac;
struct curmp3 g_SndCurMp3;
struct seqinstance g_SeqInstances[3];
ALHeap g_SndHeap;
u32 var80095200;
ALBank *var80095204;
struct seqtable *g_SeqTable;
u32 g_SeqBufferSize;
ALIGNED16 struct sndcache g_SndCache;

const char g_SndGuardString[] = "RUSSES SOUND GUARD STRING";
const char var70053b3c[] = "Snd: SoundHeaderCacheInit\n";

bool g_SndDisabled = false;
u32 var8005dda4 = 0x00000000;

s32 g_SndNosediveVolume = 0;
s32 g_SndNosediveAge240 = -1;
s32 g_SndNosediveDuration240 = 0;

s32 g_SndUfoVolume = 0;
s32 g_SndUfoAge240 = -1;
s32 g_SndUfoDuration240 = 0;

struct sndstate *g_SndNosediveHandle = NULL;
struct sndstate *g_SndUfoHandle = NULL;

u16 g_SfxVolume = AL_VOL_FULL;
s32 g_SoundMode = (VERSION >= VERSION_NTSC_1_0 ? SOUNDMODE_STEREO : SOUNDMODE_SURROUND);
bool g_SndMp3Enabled = false;

#if VERSION >= VERSION_NTSC_1_0
s32 g_SndNumPlaying = 0;
s32 g_SndMostEverPlaying = 0;
s32 var8005dddc = 0;
#endif

u8 *g_SndGuardStringPtr = NULL;

enum audioconfig_e {
	AUDIOCONFIG_00,
	AUDIOCONFIG_01,
	AUDIOCONFIG_02,
	AUDIOCONFIG_03,
	AUDIOCONFIG_04,
	AUDIOCONFIG_05,
	AUDIOCONFIG_06,
	AUDIOCONFIG_07,
	AUDIOCONFIG_08,
	AUDIOCONFIG_09,
	AUDIOCONFIG_10,
	AUDIOCONFIG_11,
	AUDIOCONFIG_12,
	AUDIOCONFIG_13,
	AUDIOCONFIG_14,
	AUDIOCONFIG_15,
	AUDIOCONFIG_16,
	AUDIOCONFIG_17,
	AUDIOCONFIG_18,
	AUDIOCONFIG_19,
	AUDIOCONFIG_20,
	AUDIOCONFIG_21,
	AUDIOCONFIG_22,
	AUDIOCONFIG_23,
	AUDIOCONFIG_24,
	AUDIOCONFIG_25,
	AUDIOCONFIG_26,
	AUDIOCONFIG_27,
	AUDIOCONFIG_28,
	AUDIOCONFIG_29,
	AUDIOCONFIG_30,
	AUDIOCONFIG_31,
	AUDIOCONFIG_32,
	AUDIOCONFIG_33,
	AUDIOCONFIG_34,
	AUDIOCONFIG_35,
	AUDIOCONFIG_36,
	AUDIOCONFIG_37,
	AUDIOCONFIG_38,
	AUDIOCONFIG_39,
	AUDIOCONFIG_40,
	AUDIOCONFIG_41,
	AUDIOCONFIG_42,
	AUDIOCONFIG_43,
	AUDIOCONFIG_44,
	AUDIOCONFIG_45,
	AUDIOCONFIG_46,
	AUDIOCONFIG_47,
	AUDIOCONFIG_48,
	AUDIOCONFIG_49,
	AUDIOCONFIG_50,
	AUDIOCONFIG_51,
	AUDIOCONFIG_52,
	AUDIOCONFIG_53,
#if VERSION >= VERSION_NTSC_1_0
	AUDIOCONFIG_54,
#endif
	AUDIOCONFIG_55,
	AUDIOCONFIG_56,
	AUDIOCONFIG_57,
	AUDIOCONFIG_58,
	AUDIOCONFIG_59,
	AUDIOCONFIG_60,
#if VERSION >= VERSION_NTSC_1_0
	AUDIOCONFIG_61,
	AUDIOCONFIG_62,
	AUDIOCONFIG_63,
#endif
	AUDIOCONFIG_END
};

struct audiorussmapping g_AudioRussMappings[] = {
	/*0x0000*/ { 0x8000 | SFXNUM_05BA, AUDIOCONFIG_59 },
	/*0x0001*/ { 0x8000 | SFXNUM_05A5, AUDIOCONFIG_15 },
	/*0x0002*/ { 0x8000 | SFXNUM_05A6, AUDIOCONFIG_15 },
	/*0x0003*/ { 0x8000 | SFXNUM_00BB, AUDIOCONFIG_14 },
	/*0x0004*/ { 0x8000 | SFXNUM_00BC, AUDIOCONFIG_14 },
	/*0x0005*/ { 0x8000 | SFXNUM_0007, AUDIOCONFIG_14 },
	/*0x0006*/ { 0x8000 | SFXNUM_0007, AUDIOCONFIG_14 },
	/*0x0007*/ { 0x8000 | SFXNUM_00BE, AUDIOCONFIG_14 },
	/*0x0008*/ { 0x8000 | SFXNUM_00BF, AUDIOCONFIG_14 },
	/*0x0009*/ { 0x8000 | SFXNUM_00BF, AUDIOCONFIG_14 },
	/*0x000a*/ { 0x8000 | SFXNUM_00C0, AUDIOCONFIG_14 },
	/*0x000b*/ { 0x8000 | SFXNUM_0007, AUDIOCONFIG_14 },
	/*0x000c*/ { 0x8000 | SFXNUM_00C2, AUDIOCONFIG_14 },
	/*0x000d*/ { 0x8000 | SFXNUM_00C3, AUDIOCONFIG_14 },
	/*0x000e*/ { 0x8000 | SFXNUM_00C4, AUDIOCONFIG_14 },
	/*0x000f*/ { 0x8000 | SFXNUM_00C5, AUDIOCONFIG_14 },
	/*0x0010*/ { 0x8000 | SFXNUM_0007, AUDIOCONFIG_14 },
	/*0x0011*/ { 0x8000 | SFXNUM_00C7, AUDIOCONFIG_14 },
	/*0x0012*/ { 0x8000 | SFXNUM_00C8, AUDIOCONFIG_14 },
	/*0x0013*/ { 0x8000 | SFXNUM_00C9, AUDIOCONFIG_14 },
	/*0x0014*/ { 0x8000 | SFXNUM_00CA, AUDIOCONFIG_15 },
	/*0x0015*/ { 0x8000 | SFXNUM_00CB, AUDIOCONFIG_15 },
	/*0x0016*/ { 0x8000 | SFXNUM_00CC, AUDIOCONFIG_15 },
	/*0x0017*/ { 0x8000 | SFXNUM_0007, AUDIOCONFIG_15 },
	/*0x0018*/ { 0x8000 | SFXNUM_0007, AUDIOCONFIG_15 },
	/*0x0019*/ { 0x8000 | SFXNUM_0007, AUDIOCONFIG_15 },
	/*0x001a*/ { 0x8000 | SFXNUM_00D2, AUDIOCONFIG_15 },
	/*0x001b*/ { 0x8000 | SFXNUM_00D3, AUDIOCONFIG_15 },
	/*0x001c*/ { 0x8000 | SFXNUM_0007, AUDIOCONFIG_15 },
	/*0x001d*/ { 0x8000 | SFXNUM_00C6, AUDIOCONFIG_14 },
	/*0x001e*/ { 0x8000 | SFXNUM_00D6, AUDIOCONFIG_15 },
	/*0x001f*/ { 0x8000 | SFXNUM_00D7, AUDIOCONFIG_15 },
	/*0x0020*/ { 0x8000 | SFXNUM_00D8, AUDIOCONFIG_15 },
	/*0x0021*/ { 0x8000 | SFXNUM_00DB, AUDIOCONFIG_14 },
	/*0x0022*/ { 0x8000 | SFXNUM_00DA, AUDIOCONFIG_14 },
	/*0x0023*/ { 0x8000 | SFXNUM_00BF, AUDIOCONFIG_14 },
	/*0x0024*/ { 0x8000 | SFXNUM_00BF, AUDIOCONFIG_14 },
	/*0x0025*/ { 0x8000 | SFXNUM_00DE, AUDIOCONFIG_14 },
	/*0x0026*/ { 0x8000 | SFXNUM_00E1, AUDIOCONFIG_15 },
	/*0x0027*/ { 0x8000 | SFXNUM_00E2, AUDIOCONFIG_15 },
	/*0x0028*/ { 0x8000 | MP3(FILE_ACICARR06M), AUDIOCONFIG_60 }, // Carrington: "Hello Joanna"
	/*0x0029*/ { 0x8000 | MP3(FILE_ACICARR07M), AUDIOCONFIG_60 }, // Carrington: "Joanna, it's good to see you"
	/*0x002a*/ { 0x8000 | MP3(FILE_ACICARR08M), AUDIOCONFIG_60 }, // Carrington: "Good day to you, Jo"
	/*0x002b*/ { 0x8000 | MP3(FILE_ACIFARR08M), AUDIOCONFIG_60 }, // Female: "Hi there"
	/*0x002c*/ { 0x8000 | MP3(FILE_ACIGRIM05M), AUDIOCONFIG_60 }, // Grimshaw: "Welcome to hacker central"
	/*0x002d*/ { 0x8000 | MP3(FILE_ACIGRIM06M), AUDIOCONFIG_60 }, // Grimshaw: "Hi there"
	/*0x002e*/ { 0x8000 | MP3(FILE_ACIGRIM07M), AUDIOCONFIG_60 }, // Grimshaw: "Um, er, hi"
	/*0x002f*/ { 0x8000 | MP3(FILE_ACIHOPK09M), AUDIOCONFIG_60 }, // Holo girl: "Hi. What can I do for you?"
	/*0x0030*/ { 0x8000 | MP3(FILE_ACIROGE08M), AUDIOCONFIG_60 }, // Hangar guy: "What do you want?"
	/*0x0031*/ { 0x8000 | MP3(FILE_ACIFOST08M), AUDIOCONFIG_60 }, // Foster: "Ah, our star agent"
	/*0x0032*/ { 0x8000 | MP3(FILE_ACIMALE02M), AUDIOCONFIG_60 }, // Male: "Hey there"
	/*0x0033*/ { 0x8000 | MP3(FILE_ACIMALE03M), AUDIOCONFIG_60 }, // Male: "Hi"
	/*0x0034*/ { 0x8000 | MP3(FILE_ACIMALE07M), AUDIOCONFIG_60 }, // Male "How's it going?"
	/*0x0035*/ { 0x8000 | MP3(FILE_ACIFEMA01M), AUDIOCONFIG_60 }, // Female: "Hello"
	/*0x0036*/ { 0x8000 | MP3(FILE_ACIFEMA04M), AUDIOCONFIG_60 }, // Holo girl: "Hi Jo"
	/*0x0037*/ { 0x8000 | MP3(FILE_ACIFEMA07M), AUDIOCONFIG_60 }, // Holo girl: "How's it going?"
	/*0x0038*/ { 0x8000 | SFXNUM_002E, AUDIOCONFIG_32 },
	/*0x0039*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_35 },
	/*0x003a*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_35 },
	/*0x003b*/ { 0x8000 | SFXNUM_006A, AUDIOCONFIG_33 },
	/*0x003c*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_35 },
	/*0x003d*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_35 },
	/*0x003e*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_35 },
	/*0x003f*/ { 0x8000 | SFXNUM_006D, AUDIOCONFIG_33 },
	/*0x0040*/ { 0x8000 | SFXNUM_006E, AUDIOCONFIG_33 },
	/*0x0041*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_35 },
	/*0x0042*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_35 },
	/*0x0043*/ { 0x8000 | SFXNUM_0070, AUDIOCONFIG_33 },
	/*0x0044*/ { 0x8000 | SFXNUM_0071, AUDIOCONFIG_33 },
	/*0x0045*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_35 },
	/*0x0046*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_35 },
	/*0x0047*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_35 },
	/*0x0048*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_35 },
	/*0x0049*/ { 0x8000 | SFXNUM_0075, AUDIOCONFIG_33 },
	/*0x004a*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_35 },
	/*0x004b*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_35 },
	/*0x004c*/ { 0x8000 | SFXNUM_0079, AUDIOCONFIG_31 },
	/*0x004d*/ { 0x8000 | SFXNUM_0066, AUDIOCONFIG_31 },
	/*0x004e*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_35 },
	/*0x004f*/ { 0x8000 | SFXNUM_0032, AUDIOCONFIG_31 },
	/*0x0050*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_35 },
	/*0x0051*/ { 0x8000 | SFXNUM_007A, AUDIOCONFIG_35 },
	/*0x0052*/ { 0x8000 | SFXNUM_0059, AUDIOCONFIG_31 },
	/*0x0053*/ { 0x8000 | SFXNUM_0001_LAUNCH_ROCKET, AUDIOCONFIG_35 },
	/*0x0054*/ { 0x8000 | SFXNUM_047E, AUDIOCONFIG_32 },
	/*0x0055*/ { 0x8000 | SFXNUM_047D, AUDIOCONFIG_33 },
	/*0x0056*/ { 0x8000 | SFXNUM_04F1, AUDIOCONFIG_32 },
	/*0x0057*/ { 0x8000 | SFXNUM_04F2, AUDIOCONFIG_32 },
	/*0x0058*/ { 0x8000 | SFXNUM_04F3, AUDIOCONFIG_32 },
	/*0x0059*/ { 0x8000 | SFXNUM_04F4, AUDIOCONFIG_33 },
	/*0x005a*/ { 0x8000 | SFXNUM_04F6, AUDIOCONFIG_33 },
	/*0x005b*/ { 0x8000 | SFXNUM_0506, AUDIOCONFIG_31 },
	/*0x005c*/ { 0x8000 | SFXNUM_04FD, AUDIOCONFIG_33 },
	/*0x005d*/ { 0x8000 | SFXNUM_0504, AUDIOCONFIG_33 },
	/*0x005e*/ { 0x8000 | SFXNUM_04FE, AUDIOCONFIG_33 },
	/*0x005f*/ { 0x8000 | SFXNUM_0503, AUDIOCONFIG_33 },
	/*0x0060*/ { 0x8000 | SFXNUM_0500, AUDIOCONFIG_32 },
	/*0x0061*/ { 0x8000 | SFXNUM_0501, AUDIOCONFIG_32 },
	/*0x0062*/ { 0x8000 | SFXNUM_0502, AUDIOCONFIG_32 },
	/*0x0063*/ { 0x8000 | SFXNUM_05CA, AUDIOCONFIG_31 },
	/*0x0064*/ { 0x8000 | SFXNUM_05CB, AUDIOCONFIG_31 },
	/*0x0065*/ { 0x8000 | SFXNUM_05D2, AUDIOCONFIG_31 },
	/*0x0066*/ { 0x8000 | SFXNUM_0074, AUDIOCONFIG_33 },
	/*0x0067*/ { 0x8000 | SFXNUM_05EB, AUDIOCONFIG_35 },
	/*0x0068*/ { 0x8000 | SFXNUM_05EC, AUDIOCONFIG_35 },
	/*0x0069*/ { 0x8000 | SFXNUM_05ED, AUDIOCONFIG_31 },
	/*0x006a*/ { 0x8000 | SFXNUM_05EE, AUDIOCONFIG_31 },
	/*0x006b*/ { 0x8000 | SFXNUM_05EF, AUDIOCONFIG_33 },
	/*0x006c*/ { 0x8000 | SFXNUM_05F0, AUDIOCONFIG_33 },
	/*0x006d*/ { 0x8000 | SFXNUM_05F1, AUDIOCONFIG_33 },
	/*0x006e*/ { 0x8000 | SFXNUM_05F2, AUDIOCONFIG_33 },
	/*0x006f*/ { 0x8000 | SFXNUM_05F3, AUDIOCONFIG_33 },
	/*0x0070*/ { 0x8000 | SFXNUM_05F4, AUDIOCONFIG_33 },
	/*0x0071*/ { 0x8000 | SFXNUM_0508, AUDIOCONFIG_31 },
	/*0x0072*/ { 0x8000 | SFXNUM_050A, AUDIOCONFIG_31 },
	/*0x0073*/ { 0x8000 | SFXNUM_0076, AUDIOCONFIG_33 },
	/*0x0074*/ { 0x8000 | SFXNUM_05F5, AUDIOCONFIG_30 },
	/*0x0075*/ { 0x8000 | SFXNUM_0509, AUDIOCONFIG_33 },
	/*0x0076*/ { 0x8000 | SFXNUM_0045, AUDIOCONFIG_45 },
	/*0x0077*/ { 0x8000 | SFXNUM_0046, AUDIOCONFIG_45 },
	/*0x0078*/ { 0x8000 | SFXNUM_0047, AUDIOCONFIG_25 },
	/*0x0079*/ { 0x8000 | SFXNUM_0048, AUDIOCONFIG_45 },
	/*0x007a*/ { 0x8000 | SFXNUM_00F0, AUDIOCONFIG_45 },
	/*0x007b*/ { 0x8000 | SFXNUM_00EF, AUDIOCONFIG_45 },
	/*0x007c*/ { 0x8000 | SFXNUM_0049, AUDIOCONFIG_45 },
	/*0x007d*/ { 0x8000 | SFXNUM_004A, AUDIOCONFIG_45 },
	/*0x007e*/ { 0x8000 | SFXNUM_004B, AUDIOCONFIG_45 },
	/*0x007f*/ { 0x8000 | SFXNUM_00D9, AUDIOCONFIG_45 },
	/*0x0080*/ { 0x8000 | SFXNUM_004C, AUDIOCONFIG_45 },
	/*0x0081*/ { 0x8000 | SFXNUM_00E7, AUDIOCONFIG_45 },
	/*0x0082*/ { 0x8000 | SFXNUM_00E6, AUDIOCONFIG_45 },
	/*0x0083*/ { 0x8000 | SFXNUM_00E0, AUDIOCONFIG_45 },
	/*0x0084*/ { 0x8000 | SFXNUM_00DC, AUDIOCONFIG_45 },
	/*0x0085*/ { 0x8000 | SFXNUM_00B9, AUDIOCONFIG_45 },
	/*0x0086*/ { 0x8000 | SFXNUM_00D4, AUDIOCONFIG_45 },
	/*0x0087*/ { 0x8000 | SFXNUM_00D0, AUDIOCONFIG_45 },
	/*0x0088*/ { 0x8000 | SFXNUM_00D1, AUDIOCONFIG_45 },
	/*0x0089*/ { 0x8000 | SFXNUM_0078, AUDIOCONFIG_45 },
	/*0x008a*/ { 0x8000 | SFXNUM_00DD, AUDIOCONFIG_45 },
	/*0x008b*/ { 0x8000 | SFXNUM_0003, AUDIOCONFIG_45 },
	/*0x008c*/ { 0x8000 | SFXNUM_002D, AUDIOCONFIG_21 },
	/*0x008d*/ { 0x8000 | SFXNUM_007B, AUDIOCONFIG_21 },
	/*0x008e*/ { 0x8000 | SFXNUM_007C, AUDIOCONFIG_21 },
	/*0x008f*/ { 0x8000 | SFXNUM_007D, AUDIOCONFIG_21 },
	/*0x0090*/ { 0x8000 | SFXNUM_007E, AUDIOCONFIG_21 },
	/*0x0091*/ { 0x8000 | SFXNUM_007F, AUDIOCONFIG_21 },
	/*0x0092*/ { 0x8000 | SFXNUM_0080, AUDIOCONFIG_21 },
	/*0x0093*/ { 0x8000 | SFXNUM_0081, AUDIOCONFIG_21 },
	/*0x0094*/ { 0x8000 | SFXNUM_0082, AUDIOCONFIG_21 },
	/*0x0095*/ { 0x8000 | SFXNUM_0083, AUDIOCONFIG_21 },
	/*0x0096*/ { 0x8000 | SFXNUM_0084, AUDIOCONFIG_21 },
	/*0x0097*/ { 0x8000 | SFXNUM_0085, AUDIOCONFIG_21 },
	/*0x0098*/ { 0x8000 | SFXNUM_00B4, AUDIOCONFIG_18 },
	/*0x0099*/ { 0x8000 | SFXNUM_00B5, AUDIOCONFIG_18 },
	/*0x009a*/ { 0x8000 | SFXNUM_00B6, AUDIOCONFIG_17 },
	/*0x009b*/ { 0x8000 | SFXNUM_00A9, AUDIOCONFIG_18 },
	/*0x009c*/ { 0x8000 | SFXNUM_00AA, AUDIOCONFIG_18 },
	/*0x009d*/ { 0x8000 | SFXNUM_00AB, AUDIOCONFIG_17 },
	/*0x009e*/ { 0x8000 | SFXNUM_00AC, AUDIOCONFIG_18 },
	/*0x009f*/ { 0x8000 | SFXNUM_00AD, AUDIOCONFIG_18 },
	/*0x00a0*/ { 0x8000 | SFXNUM_00AE, AUDIOCONFIG_17 },
	/*0x00a1*/ { 0x8000 | SFXNUM_00B1, AUDIOCONFIG_18 },
	/*0x00a2*/ { 0x8000 | SFXNUM_00B2, AUDIOCONFIG_18 },
	/*0x00a3*/ { 0x8000 | SFXNUM_00B3, AUDIOCONFIG_18 },
	/*0x00a4*/ { 0x8000 | SFXNUM_018A, AUDIOCONFIG_19 },
#if VERSION >= VERSION_NTSC_1_0
	/*0x00a5*/ { 0x8000 | MP3_HI_ZZ(FILE_ASAUCEREXP1M), AUDIOCONFIG_19 },
#else
	/*0x00a5*/ { 0x8000 | SFXNUM_0190, AUDIOCONFIG_19 },
#endif
	/*0x00a6*/ { 0x8000 | SFXNUM_005F, AUDIOCONFIG_32 },
	/*0x00a7*/ { 0x8000 | SFXNUM_0060, AUDIOCONFIG_32 },
	/*0x00a8*/ { 0x8000 | SFXNUM_0061, AUDIOCONFIG_32 },
	/*0x00a9*/ { 0x8000 | SFXNUM_0004, AUDIOCONFIG_32 },
	/*0x00aa*/ { 0x8000 | SFXNUM_00F1, AUDIOCONFIG_32 },
	/*0x00ab*/ { 0x8000 | SFXNUM_00F3, AUDIOCONFIG_32 },
	/*0x00ac*/ { 0x8000 | SFXNUM_0055, AUDIOCONFIG_16 },
	/*0x00ad*/ { 0x8000 | SFXNUM_0056, AUDIOCONFIG_16 },
	/*0x00ae*/ { 0x8000 | SFXNUM_0057, AUDIOCONFIG_16 },
	/*0x00af*/ { 0x8000 | SFXNUM_05F7, AUDIOCONFIG_52 },
	/*0x00b0*/ { 0x8000 | SFXNUM_0127, AUDIOCONFIG_29 },
	/*0x00b1*/ { 0x8000 | SFXNUM_0128, AUDIOCONFIG_29 },
	/*0x00b2*/ { 0x8000 | SFXNUM_0129, AUDIOCONFIG_29 },
	/*0x00b3*/ { 0x8000 | SFXNUM_012A, AUDIOCONFIG_29 },
	/*0x00b4*/ { 0x8000 | SFXNUM_012B, AUDIOCONFIG_29 },
	/*0x00b5*/ { 0x8000 | SFXNUM_012C, AUDIOCONFIG_29 },
	/*0x00b6*/ { 0x8000 | SFXNUM_012D, AUDIOCONFIG_50 },
	/*0x00b7*/ { 0x8000 | SFXNUM_012E, AUDIOCONFIG_50 },
	/*0x00b8*/ { 0x8000 | SFXNUM_0138, AUDIOCONFIG_50 },
	/*0x00b9*/ { 0x8000 | SFXNUM_0138, AUDIOCONFIG_28 },
	/*0x00ba*/ { 0x8000 | SFXNUM_012F, AUDIOCONFIG_51 },
	/*0x00bb*/ { 0x8000 | SFXNUM_0151, AUDIOCONFIG_51 },
	/*0x00bc*/ { 0x8000 | SFXNUM_0154, AUDIOCONFIG_51 },
	/*0x00bd*/ { 0x8000 | SFXNUM_0157, AUDIOCONFIG_51 },
	/*0x00be*/ { 0x8000 | SFXNUM_015A, AUDIOCONFIG_51 },
	/*0x00bf*/ { 0x8000 | SFXNUM_0132, AUDIOCONFIG_51 },
	/*0x00c0*/ { 0x8000 | SFXNUM_0139, AUDIOCONFIG_51 },
	/*0x00c1*/ { 0x8000 | SFXNUM_013F, AUDIOCONFIG_51 },
	/*0x00c2*/ { 0x8000 | SFXNUM_0145, AUDIOCONFIG_51 },
	/*0x00c3*/ { 0x8000 | SFXNUM_014B, AUDIOCONFIG_51 },
	/*0x00c4*/ { 0x8000 | SFXNUM_0161, AUDIOCONFIG_04 },
	/*0x00c5*/ { 0x8000 | SFXNUM_0162, AUDIOCONFIG_04 },
	/*0x00c6*/ { 0x8000 | SFXNUM_0163, AUDIOCONFIG_04 },
	/*0x00c7*/ { 0x8000 | SFXNUM_0164, AUDIOCONFIG_04 },
	/*0x00c8*/ { 0x8000 | SFXNUM_0165, AUDIOCONFIG_04 },
	/*0x00c9*/ { 0x8000 | SFXNUM_0166, AUDIOCONFIG_04 },
	/*0x00ca*/ { 0x8000 | SFXNUM_0167, AUDIOCONFIG_04 },
	/*0x00cb*/ { 0x8000 | SFXNUM_0168, AUDIOCONFIG_04 },
	/*0x00cc*/ { 0x8000 | SFXNUM_0169, AUDIOCONFIG_04 },
	/*0x00cd*/ { 0x8000 | SFXNUM_016A, AUDIOCONFIG_04 },
	/*0x00ce*/ { 0x8000 | SFXNUM_016B, AUDIOCONFIG_04 },
	/*0x00cf*/ { 0x8000 | SFXNUM_016C, AUDIOCONFIG_04 },
	/*0x00d0*/ { 0x8000 | SFXNUM_016D, AUDIOCONFIG_04 },
	/*0x00d1*/ { 0x8000 | SFXNUM_016E, AUDIOCONFIG_04 },
	/*0x00d2*/ { 0x8000 | SFXNUM_016F, AUDIOCONFIG_04 },
	/*0x00d3*/ { 0x8000 | SFXNUM_0170, AUDIOCONFIG_04 },
	/*0x00d4*/ { 0x8000 | SFXNUM_0171, AUDIOCONFIG_04 },
	/*0x00d5*/ { 0x8000 | SFXNUM_0172, AUDIOCONFIG_04 },
	/*0x00d6*/ { 0x8000 | SFXNUM_0173, AUDIOCONFIG_04 },
	/*0x00d7*/ { 0x8000 | SFXNUM_0174, AUDIOCONFIG_04 },
	/*0x00d8*/ { 0x8000 | SFXNUM_0175, AUDIOCONFIG_04 },
	/*0x00d9*/ { 0x8000 | SFXNUM_0176, AUDIOCONFIG_04 },
	/*0x00da*/ { 0x8000 | SFXNUM_0177, AUDIOCONFIG_04 },
	/*0x00db*/ { 0x8000 | SFXNUM_0178, AUDIOCONFIG_04 },
	/*0x00dc*/ { 0x8000 | SFXNUM_0179, AUDIOCONFIG_04 },
	/*0x00dd*/ { 0x8000 | SFXNUM_017A, AUDIOCONFIG_04 },
	/*0x00de*/ { 0x8000 | SFXNUM_017B, AUDIOCONFIG_04 },
	/*0x00df*/ { 0x8000 | SFXNUM_017C, AUDIOCONFIG_04 },
	/*0x00e0*/ { 0x8000 | SFXNUM_017D, AUDIOCONFIG_04 },
	/*0x00e1*/ { 0x8000 | SFXNUM_017E, AUDIOCONFIG_04 },
	/*0x00e2*/ { 0x8000 | SFXNUM_017F, AUDIOCONFIG_04 },
	/*0x00e3*/ { 0x8000 | SFXNUM_0180, AUDIOCONFIG_04 },
	/*0x00e4*/ { 0x8000 | SFXNUM_004D, AUDIOCONFIG_04 },
	/*0x00e5*/ { 0x8000 | SFXNUM_004E, AUDIOCONFIG_04 },
	/*0x00e6*/ { 0x8000 | SFXNUM_05F8, AUDIOCONFIG_05 },
	/*0x00e7*/ { 0x8000 | SFXNUM_05F9, AUDIOCONFIG_05 },
	/*0x00e8*/ { 0x8000 | SFXNUM_05FA, AUDIOCONFIG_05 },
	/*0x00e9*/ { 0x8000 | SFXNUM_05FB, AUDIOCONFIG_05 },
	/*0x00ea*/ { 0x8000 | SFXNUM_05FC, AUDIOCONFIG_06 },
	/*0x00eb*/ { 0x8000 | SFXNUM_05FD, AUDIOCONFIG_06 },
	/*0x00ec*/ { 0x8000 | SFXNUM_05FE, AUDIOCONFIG_06 },
	/*0x00ed*/ { 0x8000 | SFXNUM_05FF, AUDIOCONFIG_06 },
	/*0x00ee*/ { 0x8000 | SFXNUM_0600, AUDIOCONFIG_04 },
	/*0x00ef*/ { 0x8000 | SFXNUM_0601, AUDIOCONFIG_04 },
	/*0x00f0*/ { 0x8000 | SFXNUM_0602, AUDIOCONFIG_04 },
	/*0x00f1*/ { 0x8000 | SFXNUM_0603, AUDIOCONFIG_04 },
	/*0x00f2*/ { 0x8000 | SFXNUM_0604, AUDIOCONFIG_04 },
	/*0x00f3*/ { 0x8000 | SFXNUM_0605, AUDIOCONFIG_04 },
	/*0x00f4*/ { 0x8000 | SFXNUM_0606, AUDIOCONFIG_04 },
	/*0x00f5*/ { 0x8000 | SFXNUM_0606, AUDIOCONFIG_04 },
#if VERSION >= VERSION_NTSC_1_0
	/*0x00f6*/ { 0x8000 | SFXNUM_01D9_RELOAD_INSERT, AUDIOCONFIG_61 },
#endif
	/*0x00f7*/ { 0x8000 | SFXNUM_0267_M0_HOLYSH, AUDIOCONFIG_02 },
	/*0x00f8*/ { 0x8000 | SFXNUM_0268_M0_WHAT_THE_HELL, AUDIOCONFIG_02 },
	/*0x00f9*/ { 0x8000 | SFXNUM_0286_M0_DAMN_IT_MISSED, AUDIOCONFIG_02 },
	/*0x00fa*/ { 0x8000 | SFXNUM_0288_M0_GOD_SAKES_SOMEONE_HIT_HER, AUDIOCONFIG_02 },
	/*0x00fb*/ { 0x8000 | SFXNUM_0291_M0_GET_THE_HELL_OUT_OF_HERE, AUDIOCONFIG_02 },
	/*0x00fc*/ { 0x8000 | SFXNUM_029F_M_YOU_BITCH, AUDIOCONFIG_02 },
	/*0x00fd*/ { 0x8000 | SFXNUM_02A1_M_OH_MY_GOD, AUDIOCONFIG_02 },
#if VERSION >= VERSION_NTSC_1_0
	/*0x00fe*/ { 0x8000 | MP3_HI(FILE_ADEVR08M), AUDIOCONFIG_47 }, // Cass: "You've become quite an annoyance"
	/*0x00ff*/ { 0x8000 | MP3_HI(FILE_ADEVR09M), AUDIOCONFIG_47 }, // Cass: "We meet again, girl"
	/*0x0100*/ { 0x8000 | MP3_HI(FILE_ADEVR10M), AUDIOCONFIG_47 }, // Cass: "Good night, Miss Dark"
#else
	/*0x00fe*/ { 0x8000 | MP3(FILE_ADEVR08M), AUDIOCONFIG_47 }, // Cass: "You've become quite an annoyance"
	/*0x00ff*/ { 0x8000 | MP3(FILE_ADEVR09M), AUDIOCONFIG_47 }, // Cass: "We meet again, girl"
	/*0x0100*/ { 0x8000 | MP3(FILE_ADEVR10M), AUDIOCONFIG_47 }, // Cass: "Good night, Miss Dark"
#endif
	/*0x0101*/ { 0x8000 | MP3(FILE_ADEVR11M), AUDIOCONFIG_47 }, // Cass: "Get her!"
	/*0x0102*/ { 0x8000 | MP3(FILE_ADEVR12M), AUDIOCONFIG_47 }, // Cass: (laughing)
	/*0x0103*/ { 0x8000 | MP3(FILE_ASCIE3AM), AUDIOCONFIG_02 }, // Scientist: "Who the hell are you?"
	/*0x0104*/ { 0x8000 | MP3(FILE_AEXEC10M), AUDIOCONFIG_48 }, // Programmer: "Yes, yes, I agree. Personality..."
	/*0x0105*/ { 0x8000 | MP3(FILE_AEXEC11M), AUDIOCONFIG_48 }, // Programmer: "No. I can start the process..."
	/*0x0106*/ { 0x8000 | MP3(FILE_AEXEC12M), AUDIOCONFIG_48 }, // Programmer: "I'll begin at once. Goodbye"
	/*0x0107*/ { 0x8000 | MP3(FILE_AEXEC13M), AUDIOCONFIG_48 }, // Programmer: "Security, help me!"
	/*0x0108*/ { 0x8000 | MP3(FILE_AEXEC14M), AUDIOCONFIG_48 }, // Programmer: "Help! Help!"
	/*0x0109*/ { 0x8000 | SFXNUM_0435, AUDIOCONFIG_49 },
	/*0x010a*/ { 0x8000 | SFXNUM_01B5, AUDIOCONFIG_07 },
	/*0x010b*/ { 0x8000 | SFXNUM_01B6, AUDIOCONFIG_08 },
	/*0x010c*/ { 0x8000 | SFXNUM_01B5, AUDIOCONFIG_09 },
	/*0x010d*/ { 0x8000 | SFXNUM_01B6, AUDIOCONFIG_10 },
	/*0x010e*/ { 0x8000 | SFXNUM_05F3, AUDIOCONFIG_11 },
	/*0x010f*/ { 0x8000 | SFXNUM_01B5, AUDIOCONFIG_12 },
	/*0x0110*/ { 0x8000 | SFXNUM_01B6, AUDIOCONFIG_13 },
	/*0x0111*/ { 0x8000 | SFXNUM_01B7, AUDIOCONFIG_20 },
	/*0x0112*/ { 0x8000 | SFXNUM_01B8, AUDIOCONFIG_20 },
	/*0x0113*/ { 0x8000 | SFXNUM_01C7, AUDIOCONFIG_20 },
	/*0x0114*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_20 },
	/*0x0115*/ { 0x8000 | SFXNUM_01B7, AUDIOCONFIG_56 },
	/*0x0116*/ { 0x8000 | SFXNUM_01B9, AUDIOCONFIG_00 },
	/*0x0117*/ { 0x8000 | SFXNUM_01BA, AUDIOCONFIG_00 },
	/*0x0118*/ { 0x8000 | SFXNUM_01BB, AUDIOCONFIG_00 },
	/*0x0119*/ { 0x8000 | SFXNUM_01CB, AUDIOCONFIG_36 },
	/*0x011a*/ { 0x8000 | SFXNUM_01CB, AUDIOCONFIG_37 },
	/*0x011b*/ { 0x8000 | SFXNUM_01CB, AUDIOCONFIG_38 },
	/*0x011c*/ { 0x8000 | SFXNUM_01C6, AUDIOCONFIG_55 },
	/*0x011d*/ { 0x8000 | MP3(FILE_ARLTECH01M), AUDIOCONFIG_47 }, // "That's not how it goes"
	/*0x011e*/ { 0x8000 | MP3(FILE_ARLTECH02M), AUDIOCONFIG_47 }, // "Give it to me. You're doing it wrong"
	/*0x011f*/ { 0x8000 | MP3(FILE_ARLTECH03M), AUDIOCONFIG_47 }, // "Oh no, we're too late"
	/*0x0120*/ { 0x8000 | MP3(FILE_ARLTECH04M), AUDIOCONFIG_47 }, // "Yes it is"
	/*0x0121*/ { 0x8000 | MP3(FILE_ARLTECH05M), AUDIOCONFIG_47 }, // "Stop annoying me"
	/*0x0122*/ { 0x8000 | MP3(FILE_ARLTECH06M), AUDIOCONFIG_47 }, // "She's here!"
	/*0x0123*/ { 0x8000 | MP3(FILE_ARLGUARD1M), AUDIOCONFIG_47 }, // "Will you just hurry up?"
	/*0x0124*/ { 0x8000 | SFXNUM_02FD_M_HOLY, AUDIOCONFIG_02 }, // "Holy..."
	/*0x0125*/ { 0x8000 | SFXNUM_02FE_M_WHAT_THE_HELL, AUDIOCONFIG_02 }, // "What the hell?"
	/*0x0126*/ { 0x8000 | SFXNUM_0300_M_OH_MY_GOD, AUDIOCONFIG_02 }, // "Oh my god"
	/*0x0127*/ { 0x8000 | SFXNUM_0303_M_OH_GOD_IM_HIT, AUDIOCONFIG_02 }, // "Oh god I'm hit"
	/*0x0128*/ { 0x8000 | SFXNUM_030A_M_MY_GOD, AUDIOCONFIG_02 }, // "Oh my god"
#if VERSION >= VERSION_NTSC_1_0
	/*0x0129*/ { 0x8000 | SFXNUM_0313_M_NOOO, AUDIOCONFIG_62 }, // "Noooo!"
#endif
	/*0x012a*/ { 0x8000 | SFXNUM_0314_M_OH_GOD_HES_DEAD, AUDIOCONFIG_02 }, // "Oh god he's dead!"
	/*0x012b*/ { 0x8000 | SFXNUM_032E_M_BLOODY_STUPID_GUN, AUDIOCONFIG_02 }, // "Bloody stupid gun"
	/*0x012c*/ { 0x8000 | SFXNUM_0330_M_DAMN_IT, AUDIOCONFIG_02 }, // "Damn it"
	/*0x012d*/ { 0x8000 | SFXNUM_0333_M_DAMN_SHES_GOOD, AUDIOCONFIG_02 }, // "Damn, she's good"
	/*0x012e*/ { 0x8000 | SFXNUM_0334_M_COVER_MY_ASS, AUDIOCONFIG_02 }, // "Cover my ass"
#if VERSION >= VERSION_NTSC_1_0
	/*0x012f*/ { 0x8000 | SFXNUM_034C_M_WAIL, AUDIOCONFIG_62 }, // Death scream
#endif
	/*0x0130*/ { 0x8000 | SFXNUM_03A3_F_DAMN_SHES_GOOD, AUDIOCONFIG_02 }, // Female: "Damn she's good"
	/*0x0131*/ { 0x8000 | SFXNUM_03B9_F_MY_GOD, AUDIOCONFIG_02 }, // Female: "My god"
	/*0x0132*/ { 0x8000 | SFXNUM_03C7_M_GEEZ_THAT_HURT, AUDIOCONFIG_02 }, // "Geez, that hurt"
	/*0x0133*/ { 0x8000 | SFXNUM_03CF_M_DAMN_IT_IM_TAKING_FIRE, AUDIOCONFIG_02 }, // "Damn it, I'm taking fire"
	/*0x0134*/ { 0x8000 | SFXNUM_03D2_M_GOD_DAMN_IT, AUDIOCONFIG_02 }, // "God damn it"
	/*0x0135*/ { 0x8000 | SFXNUM_03D4_M_HOLY_MOLY, AUDIOCONFIG_02 }, // "Holy moley"
	/*0x0136*/ { 0x8000 | SFXNUM_03F3_M_DANG_MISSED_AGAIN, AUDIOCONFIG_02 }, // "Damn, missed again"
	/*0x0137*/ { 0x8000 | SFXNUM_03F5_M_DAMN_YOU, AUDIOCONFIG_02 }, // "Damn"
	/*0x0138*/ { 0x8000 | SFXNUM_03F6_M_HELL_SHES_GOOD, AUDIOCONFIG_02 }, // "Hell, she's good"
	/*0x0139*/ { 0x8000 | SFXNUM_0400_M_LETS_GET_THE_HELL_OUT_OF_HERE, AUDIOCONFIG_02 }, // "Let's get the hell out of here"
#if VERSION >= VERSION_NTSC_1_0
	/*0x013a*/ { 0x8000 | SFXNUM_0411_M_NOOO, AUDIOCONFIG_62 }, // "Noooo!"
#endif
	/*0x013b*/ { 0x8000 | SFXNUM_0413_M_GOD_DAMN_IT, AUDIOCONFIG_02 }, // "Shoot, damn it"
	/*0x013c*/ { 0x8000 | SFXNUM_0414_M_OH_GOD_IM_DYING, AUDIOCONFIG_02 }, // "Oh god, I'm dying"
	/*0x013d*/ { 0x8000 | SFXNUM_0422_M_GOD_RUN, AUDIOCONFIG_02 }, // "God, run!"
	/*0x013e*/ { 0x8000 | SFXNUM_0432, AUDIOCONFIG_33 },
	/*0x013f*/ { 0x8000 | SFXNUM_043C, AUDIOCONFIG_58 },
	/*0x0140*/ { 0x8000 | SFXNUM_043D, AUDIOCONFIG_58 },
	/*0x0141*/ { 0x8000 | SFXNUM_04AB, AUDIOCONFIG_58 },
	/*0x0142*/ { 0x8000 | SFXNUM_043D, AUDIOCONFIG_58 },
	/*0x0143*/ { 0x8000 | SFXNUM_01B7, AUDIOCONFIG_58 },
	/*0x0144*/ { 0x8000 | SFXNUM_0477, AUDIOCONFIG_57 },
	/*0x0145*/ { 0x8000 | SFXNUM_0478, AUDIOCONFIG_57 },
#if VERSION >= VERSION_NTSC_1_0
	/*0x0146*/ { 0x8000 | SFXNUM_01C2, AUDIOCONFIG_54 },
	/*0x0147*/ { 0x8000 | SFXNUM_0479, AUDIOCONFIG_54 },
	/*0x0148*/ { 0x8000 | SFXNUM_01C3, AUDIOCONFIG_54 },
	/*0x0149*/ { 0x8000 | SFXNUM_01C4, AUDIOCONFIG_54 },
#else
	/*0x0146*/ { 0x8000 | SFXNUM_01C2, AUDIOCONFIG_55 },
	/*0x0147*/ { 0x8000 | SFXNUM_0479, AUDIOCONFIG_55 },
	/*0x0148*/ { 0x8000 | SFXNUM_01C3, AUDIOCONFIG_55 },
	/*0x0149*/ { 0x8000 | SFXNUM_01C4, AUDIOCONFIG_55 },
#endif
	/*0x014a*/ { 0x8000 | SFXNUM_0443_CIV_OH_MY_GOD, AUDIOCONFIG_02 }, // Civilian: "Oh my god"
	/*0x014b*/ { 0x8000 | SFXNUM_044E_M_WHAT_THE_HELL_WAS_THAT, AUDIOCONFIG_02 }, // "What the hell was that?"
#if VERSION >= VERSION_NTSC_1_0
	/*0x014c*/ { 0x8000 | SFXNUM_043C, AUDIOCONFIG_63 },
	/*0x014d*/ { 0x8000 | SFXNUM_047C, AUDIOCONFIG_63 },
	/*0x014e*/ { 0x8000 | SFXNUM_043D, AUDIOCONFIG_63 },
#endif
	/*0x014f*/ { 0x8000 | MP3_ZZ(FILE_AA51JON01M), AUDIOCONFIG_01 }, // "Joanna, this is Jonathan. You're in grave danger"
	/*0x0150*/ { 0x8000 | MP3_ZZ(FILE_AA51JON02M), AUDIOCONFIG_01 }, // "They've flooded the area with nerge gas"
	/*0x0151*/ { 0x8000 | MP3_ZZ(FILE_AA51JON03M), AUDIOCONFIG_01 }, // "Get our friend to the containment lab. There's a hiding place there"
	/*0x0152*/ { 0x8000 | MP3_ACK(FILE_AA51JON04M), AUDIOCONFIG_01 }, // "I'll contact you when you get there. Good luck"
	/*0x0153*/ { 0x8000 | MP3_ZZ(FILE_AA51JON05M), AUDIOCONFIG_01 }, // "Good work Jo. We need to meet up. They're getting suspicious of me"
	/*0x0154*/ { 0x8000 | MP3_ACK(FILE_AA51JON06M), AUDIOCONFIG_01 }, // "Use the maintenance hatch I've opened in one of the containment labs. Hurry"
	/*0x0155*/ { 0x8000 | MP3(FILE_AA51JON12M), AUDIOCONFIG_02 }, // "Damn it Joanna, cover me!"
	/*0x0156*/ { 0x8000 | MP3_LO(FILE_ALABTECH5M), AUDIOCONFIG_02 }, // "Oh my god, a gun?!"
	/*0x0157*/ { 0x8000 | MP3_LO(FILE_ALABACC1M), AUDIOCONFIG_47 }, // "So you got here at last"
	/*0x0158*/ { 0x8000 | MP3_LO(FILE_ALABACC2M), AUDIOCONFIG_47 }, // "Hey, you're not, uh, security alert!"
	/*0x0159*/ { 0x8000 | MP3_LO(FILE_ALABACC3M), AUDIOCONFIG_47 }, // "No guns allowed in here. Put your weapon away"
	/*0x015a*/ { 0x8000 | MP3_LO(FILE_ALABACC4M), AUDIOCONFIG_47 }, // "I won't tell you again. Lose the weapon"
	/*0x015b*/ { 0x8000 | MP3_LO(FILE_ALABACC5M), AUDIOCONFIG_47 }, // "Right. I'm calling security"
	/*0x015c*/ { 0x8000 | MP3_LO(FILE_ALABACC6M), AUDIOCONFIG_47 }, // "Everyone's been waiting for you"
	/*0x015d*/ { 0x8000 | MP3_LO(FILE_AA51GRD01M), AUDIOCONFIG_60 }, // "How's things?"
	/*0x015e*/ { 0x8000 | MP3_LO(FILE_AA51GRD02M), AUDIOCONFIG_60 }, // "Hey there"
	/*0x015f*/ { 0x8000 | MP3_LO(FILE_AA51GRD03M), AUDIOCONFIG_60 }, // "Hi. How are you?"
	/*0x0160*/ { 0x8000 | SFXNUM_0037, AUDIOCONFIG_04 },
	/*0x0161*/ { 0x8000 | MP3(FILE_ARECEP01M), AUDIOCONFIG_60 }, // Female: "Good afternoon"
	/*0x0162*/ { 0x8000 | MP3(FILE_ARECEP05M), AUDIOCONFIG_02 }, // Female: "Oh my god!"
	/*0x0163*/ { 0x8000 | MP3_LO(FILE_AAIRBGD01M), AUDIOCONFIG_60 }, // "Hi there"
	/*0x0164*/ { 0x8000 | MP3_LO(FILE_AAIRBGD02M), AUDIOCONFIG_60 }, // "How's things"
	/*0x0165*/ { 0x8000 | MP3_LO(FILE_AAIRBGD09M), AUDIOCONFIG_60 }, // "Hello"
	/*0x0166*/ { 0x8000 | MP3_LO(FILE_AAIRBGD10M), AUDIOCONFIG_60 }, // "Hey, what's up?"
	/*0x0167*/ { 0x8000 | SFXNUM_04C8_M_WHAT_THE_HELL, AUDIOCONFIG_02 }, // "What the hell?"
	/*0x0168*/ { 0x8000 | SFXNUM_04CD_M_GEEZ, AUDIOCONFIG_02 }, // "Geez"
	/*0x0169*/ { 0x8000 | SFXNUM_04AD, AUDIOCONFIG_46 },
	/*0x016a*/ { 0x8000 | SFXNUM_0507, AUDIOCONFIG_27 },
	/*0x016b*/ { 0x8000 | SFXNUM_04EE, AUDIOCONFIG_16 },
	/*0x016c*/ { 0x8000 | SFXNUM_04EF, AUDIOCONFIG_16 },
	/*0x016d*/ { 0x8000 | SFXNUM_04F0, AUDIOCONFIG_16 },
	/*0x016e*/ { 0x8000 | MP3(FILE_AAF1PR10M), AUDIOCONFIG_02 }, // President: "What the hell was that?"
	/*0x016f*/ { 0x8000 | MP3(FILE_AAF1TR01M), AUDIOCONFIG_02 }, // Trent: "How the hell did you get on board?"
	/*0x0170*/ { 0x8000 | MP3_ACKW(FILE_AM1_L1_AM), AUDIOCONFIG_01 }, // Carrington: "We're getting a positive reading. The internal comms hub is nearby"
	/*0x0171*/ { 0x8000 | MP3_ACKW(FILE_AM1_L1_BM), AUDIOCONFIG_01 }, // Carrington: "You're on the same floor as Cassandra's office"
	/*0x0172*/ { 0x8000 | MP3_ACK(FILE_AM1_L1_DM), AUDIOCONFIG_01 }, // Carrington: "The basement elevator must be around there somewhere"
	/*0x0173*/ { 0x8000 | MP3_ACK(FILE_AM1_L2_AM), AUDIOCONFIG_01 }, // Carrington: "That's the highest security sector. Dr Caroll has got to be nearby"
	/*0x0174*/ { 0x8000 | MP3_ACK(FILE_AM1_L2_CM), AUDIOCONFIG_01 }, // Grimshaw: "Reprogram the cleaning bot. It'll give you a way in"
	/*0x0175*/ { 0x8000 | MP3_ACK(FILE_AM1_L2_DM), AUDIOCONFIG_01 }, // Carrington: "Get out Jo! The levels are too high. Use the camspy"
	/*0x0176*/ { 0x8000 | MP3_ACK(FILE_AM1_L3_AM), AUDIOCONFIG_01 }, // Carrington: "They've locked down the ground floor. Get to the elevator"
	/*0x0177*/ { 0x8000 | MP3_ACK(FILE_AM1_L3_BM), AUDIOCONFIG_01 }, // Carrington: "That copter needs to be taken out of the jumpship will get shut down"
	/*0x0178*/ { 0x8000 | MP3_ACK(FILE_AM1_L3_DM), AUDIOCONFIG_01 }, // Carrington: "Don't keep the jumpship waiting. Get back to the landing pad"
	/*0x0179*/ { 0x8000 | MP3_ACK(FILE_AM3_L1_AM), AUDIOCONFIG_01 }, // Carrington: "The only place we could secure the equipment was a storm drain"
	/*0x017a*/ { 0x8000 | MP3_ACK(FILE_AM3_L1_CM), AUDIOCONFIG_01 }, // Grimshaw: "Reprogram that taxi. It's a mark 2 and should be compatible"
	/*0x017b*/ { 0x8000 | MP3_ACK(FILE_AM3_L1_DM), AUDIOCONFIG_01 }, // Carrington: The carpark lift is your only point of ingress"
	/*0x017c*/ { 0x8000 | MP3_ACKW(FILE_AM3_L2_CM), AUDIOCONFIG_01 }, // Grimshaw: "The safe's heavily encrypted. The decoder's going to take a little longer"
	/*0x017d*/ { 0x8000 | MP3_ACK(FILE_AM4_L1_AM), AUDIOCONFIG_01 }, // Carrington: "The air intercept radar is controlled from that bunker"
	/*0x017e*/ { 0x8000 | MP3_ACK(FILE_AM4_L1_CM), AUDIOCONFIG_01 }, // Carrington: "The hangar lift is the other side of that huge door"
	/*0x017f*/ { 0x8000 | MP3_ACK(FILE_AM4_L1_DM), AUDIOCONFIG_01 }, // Jon: "Careful with that trigger finger, Agent Dark. You're closing in on my position"
	/*0x0180*/ { 0x8000 | MP3_ACKW(FILE_AM4_L2_BM), AUDIOCONFIG_01 }, // Carrington: "The temperature's dropping. You must be close to the cryo room"
	/*0x0181*/ { 0x8000 | MP3_ACK(FILE_AM4_L2_DM), AUDIOCONFIG_01 }, // Carrington: "There he is Jo. Hurry or you'll be too late"
	/*0x0182*/ { 0x8000 | MP3_ACKW(FILE_AM5_L1_AM), AUDIOCONFIG_01 }, // Carrington: "Now's your chance. Grab the stewardess's bag and get her uniform"
	/*0x0183*/ { 0x8000 | MP3_ACKW(FILE_AM5_L1_BM), AUDIOCONFIG_01 }, // Carrington: "Use that case to conceal your equipment"
	/*0x0184*/ { 0x8000 | MP3_ACKW(FILE_AM5_L1_CM), AUDIOCONFIG_01 }, // Carrington: "The case will get stopped unless you do something"
	/*0x0185*/ { 0x8000 | MP3_ACKW(FILE_AM5_L2_BM), AUDIOCONFIG_01 }, // Carrington: "The president's room is on this level, Joanna"
	/*0x0186*/ { 0x8000 | MP3_ACKW(FILE_AM5_L2_CM), AUDIOCONFIG_01 }, // Carrington: "Something's wrong. You have to get to the cockpit"
	/*0x0187*/ { 0x8000 | SFXNUM_0594, AUDIOCONFIG_04 }, // Footstep
	/*0x0188*/ { 0x8000 | SFXNUM_0595, AUDIOCONFIG_04 }, // Footstep
	/*0x0189*/ { 0x8000 | SFXNUM_0596, AUDIOCONFIG_04 }, // Footstep
	/*0x018a*/ { 0x8000 | SFXNUM_0597, AUDIOCONFIG_04 }, // Footstep
	/*0x018b*/ { 0x8000 | SFXNUM_0598, AUDIOCONFIG_04 }, // Footstep
	/*0x018c*/ { 0x8000 | SFXNUM_0599, AUDIOCONFIG_04 }, // Footstep
	/*0x018d*/ { 0x8000 | SFXNUM_059A, AUDIOCONFIG_04 }, // Footstep
	/*0x018e*/ { 0x8000 | SFXNUM_059B, AUDIOCONFIG_04 }, // Footstep
	/*0x018f*/ { 0x8000 | SFXNUM_05A0, AUDIOCONFIG_04 }, // Footstep
	/*0x0190*/ { 0x8000 | SFXNUM_05A1, AUDIOCONFIG_04 }, // Footstep
	/*0x0191*/ { 0x8000 | SFXNUM_05A2, AUDIOCONFIG_04 }, // Footstep
	/*0x0192*/ { 0x8000 | SFXNUM_05A3, AUDIOCONFIG_04 }, // Footstep
	/*0x0193*/ { 0x8000 | MP3_ZZ(FILE_AINVCAR01M), AUDIOCONFIG_01 },  // Carrington: "Joanna. We're under attack"
	/*0x0194*/ { 0x8000 | MP3_ACK(FILE_AINVCAR02M), AUDIOCONFIG_01 }, // Carrington: "Get the guns back online. Hurry"
	/*0x0195*/ { 0x8000 | MP3_ZZ(FILE_AINVCAR03M), AUDIOCONFIG_01 },  // Carrington: "The Skedar have taken hostages"
	/*0x0196*/ { 0x8000 | MP3_ACK(FILE_AINVCAR04M), AUDIOCONFIG_01 }, // Carrington: "Get up to the offices and save them"
	/*0x0197*/ { 0x8000 | MP3_ZZ(FILE_AINVCAR05M), AUDIOCONFIG_01 },  // Carrington: "They're using a new form of shield technology"
	/*0x0198*/ { 0x8000 | MP3_ACK(FILE_AINVCAR06M), AUDIOCONFIG_01 }, // Carrington: "Foster was working on a new weapon which may be useful"
	/*0x0199*/ { 0x8000 | MP3_ZZ(FILE_AINVCAR07M), AUDIOCONFIG_03 },  // Carrington: "Damn it, my office. If they get access..."
	/*0x019a*/ { 0x8000 | MP3_ACK(FILE_AINVCAR08M), AUDIOCONFIG_01 }, // Carrington: "Get there first, Jo and destroy the files"
	/*0x019b*/ { 0x8000 | MP3_ZZ(FILE_AINVCAR09M), AUDIOCONFIG_01 },  // Carrington: "Things are desparate. They've planted a bomb"
	/*0x019c*/ { 0x8000 | MP3_ACK(FILE_AINVCAR10M), AUDIOCONFIG_01 }, // Carrington: "Find it and get it out of the building"
	/*0x019d*/ { 0x8000 | MP3_ZZ(FILE_AINVCAR11M), AUDIOCONFIG_01 },  // Carrington: "Well done Joanna. We're nearly clear"
	/*0x019e*/ { 0x8000 | MP3_ACK(FILE_AINVCAR12M), AUDIOCONFIG_01 }, // Carrington: "The last dropship is waiting for you. Hurry"
	/*0x019f*/ { 0x8000 | MP3_ZZ(FILE_AVILGRIMM), AUDIOCONFIG_01 },   // Grimshaw: "Joanna, it's Grimshaw. We've got hackers at..."
	/*0x01a0*/ { 0x8000 | MP3_ZZ(FILE_AASSAEL01M), AUDIOCONFIG_01 },  // Elvis: "We're outside, Joanna. Get the shields down and we can help you"
	/*0x01a1*/ { 0x8000 | MP3_ZZ(FILE_AASSAEL02M), AUDIOCONFIG_01 },  // Elvis: "You've got to open the hanger doors so we can dock"
	/*0x01a2*/ { 0x8000 | MP3_ACK(FILE_AM3L2CARRM), AUDIOCONFIG_01 }, // Carrington: "Stand back Joanna. We'll create your escape route"
#if VERSION >= VERSION_NTSC_1_0
	/*0x01a3*/ { 0x8000 | MP3_HI(FILE_ABNCASS01M), AUDIOCONFIG_02 }, // Cass: "Get the hell out of my office"
#else
	/*0x01a3*/ { 0x8000 | MP3(FILE_ABNCASS01M), AUDIOCONFIG_02 }, // Cass: "Get the hell out of my office"
#endif
	/*0x01a4*/ { 0x8000 | MP3_LO(FILE_APELELV02M), AUDIOCONFIG_47 }, // Elvis: "Joanna, what took you so long? Follow me. Let's get off this old tub"
	/*0x01a5*/ { 0x8000 | SFXNUM_04AA, AUDIOCONFIG_43 },
	/*0x01a6*/ { 0x8000 | SFXNUM_01CF, AUDIOCONFIG_41 },
	/*0x01a7*/ { 0x8000 | SFXNUM_058F, AUDIOCONFIG_40 },
	/*0x01a8*/ { 0x8000 | SFXNUM_00D5, AUDIOCONFIG_39 }, // Lift mechanical sound
	/*0x01a9*/ { 0x8000 | SFXNUM_00EC, AUDIOCONFIG_39 }, // Lift mechanical sound
	/*0x01aa*/ { 0x8000 | SFXNUM_00ED, AUDIOCONFIG_40 }, // Lift mechanical sound
	/*0x01ab*/ { 0x8000 | SFXNUM_00D5, AUDIOCONFIG_41 }, // Lift mechanical sound
	/*0x01ac*/ { 0x8000 | SFXNUM_00EC, AUDIOCONFIG_41 }, // Lift mechanical sound
	/*0x01ad*/ { 0x8000 | SFXNUM_00ED, AUDIOCONFIG_42 }, // Lift mechanical sound
	/*0x01ae*/ { 0x8000 | SFXNUM_00D5, AUDIOCONFIG_41 }, // Lift mechanical sound
	/*0x01af*/ { 0x8000 | SFXNUM_00EC, AUDIOCONFIG_41 }, // Lift mechanical sound
	/*0x01b0*/ { 0x8000 | SFXNUM_003A, AUDIOCONFIG_41 }, // Lift call
	/*0x01b1*/ { 0x8000 | SFXNUM_04E8, AUDIOCONFIG_43 }, // Lift mechanical sound
	/*0x01b2*/ { 0x8000 | SFXNUM_04E9, AUDIOCONFIG_43 }, // Lift mechanical sound
	/*0x01b3*/ { 0x8000 | SFXNUM_00CD, AUDIOCONFIG_42 }, // Lift mechanical sound
	/*0x01b4*/ { 0x8000 | SFXNUM_00CE, AUDIOCONFIG_42 }, // Lift mechanical sound
	/*0x01b5*/ { 0x8000 | SFXNUM_0039, AUDIOCONFIG_42 }, // Lift mechanical sound
	/*0x01b6*/ { 0x8000 | SFXNUM_00CD, AUDIOCONFIG_44 }, // Lift mechanical sound
	/*0x01b7*/ { 0x8000 | SFXNUM_00DB, AUDIOCONFIG_16 }, // Lift roller door
	/*0x01b8*/ { 0x8000 | SFXNUM_00DA, AUDIOCONFIG_16 }, // Lift roller door
	/*0x01b9*/ { 0x8000 | MP3_ZZ(FILE_AP10_05_JOM), AUDIOCONFIG_02 }, // Joanna: "Oh my god"
	/*0x01ba*/ { 0x8000 | MP3_ZZ(FILE_AP13_02_SUM), AUDIOCONFIG_02 }, // Lab guy: "What the hell do you think you're doing? This is supposed..."
	/*0x01bb*/ { 0x8000 | MP3_ZZ(FILE_AP17_04_PRM), AUDIOCONFIG_02 }, // President: "Damn it man. I say no and I mean no..."
	/*0x01bc*/ { 0 },
};

struct audioconfig g_AudioConfigs[] = {
	{ /* 0*/  200, 1000, 1200, -1, 100, -1,   0, 0 },
	{ /* 1*/  400, 2500, 3000, -1, 100, 48,   0, AUDIOCONFIGFLAG_AMBIENT },
	{ /* 2*/  400, 2500, 3000, -1, 100, -1,   0, AUDIOCONFIGFLAG_OFFENSIVE },
	{ /* 3*/  400, 2500, 3000, -1, 100, 48,   0, AUDIOCONFIGFLAG_OFFENSIVE | AUDIOCONFIGFLAG_AMBIENT },
	{ /* 4*/  200, 1000, 1200, -1, 100, -1,   0, 0 },
	{ /* 5*/  200, 1000, 1200, -1, 100, -1,   0, 0 },
	{ /* 6*/  200, 1000, 1200, -1, 100, -1,   0, 0 },
	{ /* 7*/ 1000, 3500, 4000, -1, 100, -1, 120, AUDIOCONFIGFLAG_SPECIALPAN | AUDIOCONFIGFLAG_IGNOREROOMS },
	{ /* 8*/ 1000, 2500, 3000, -1, 100, -1,  30, AUDIOCONFIGFLAG_SPECIALPAN | AUDIOCONFIGFLAG_IGNOREROOMS },
	{ /* 9*/ 1000, 3500, 4000, -1, 100, -1, 120, AUDIOCONFIGFLAG_SPECIALPAN | AUDIOCONFIGFLAG_IGNOREROOMS },
	{ /*10*/ 1000, 2500, 3000, -1, 100, -1,  30, AUDIOCONFIGFLAG_SPECIALPAN | AUDIOCONFIGFLAG_IGNOREROOMS },
	{ /*11*/ 1600, 3000, 3500, -1, 100, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN | AUDIOCONFIGFLAG_IGNOREROOMS },
	{ /*12*/  400, 1100, 1400, -1, 100, -1, 140, AUDIOCONFIGFLAG_SPECIALPAN | AUDIOCONFIGFLAG_IGNOREROOMS },
	{ /*13*/  400, 1100, 1400, -1, 100, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN | AUDIOCONFIGFLAG_IGNOREROOMS },
	{ /*14*/  300, 1200, 1250, -1, 100, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*15*/  500, 1800, 1900, -1, 100, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*16*/ 1000, 2700, 2900, -1, 100, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*17*/ 1500, 3000, 4000, -1, 100, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*18*/ 2500, 4900, 5000, -1, 100, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*19*/ 5500, 5600, 5700, -1, 100, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN | AUDIOCONFIGFLAG_AMBIENT },
	{ /*20*/   20,  400,  500, -1, 100, -1,   0, 0 },
	{ /*21*/  300, 1700, 2000, -1, 100, -1,   0, 0 },
	{ /*22*/  600, 3500, 5000, -1, 100, -1,   0, 0 },
	{ /*23*/  600, 3500, 5000, -1, 100, -1,   0, 0 },
	{ /*24*/  600, 3500, 5000, -1, 100, -1,   0, 0 },
	{ /*25*/  600, 2500, 3000, -1, 100, -1,   0, 0 },
	{ /*26*/ 1500, 4900, 5500, -1, 100, -1, 100, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*27*/ 5500, 5740, 5800, -1, 100, -1, 100, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*28*/  250, 1000, 1300,  2, 100, -1, 120, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*29*/  200, 2600, 3000, -1, 100, -1,   0, 0 },
	{ /*30*/  200,  750,  850, -1, 100, -1,   0, 0 },
	{ /*31*/  600, 2000, 3000, -1, 100, -1,   0, 0 },
	{ /*32*/  500, 1500, 1800, -1, 100, -1,   0, 0 },
	{ /*33*/  800, 2500, 3000, -1, 100, -1,   0, 0 },
	{ /*34*/  400, 1500, 2000, -1, 100, -1,   0, 0 },
	{ /*35*/ 1000, 3500, 5000, -1, 100, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*36*/   50,  225,  250, -1, 100, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*37*/   50,  225,  250, -1, 100, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*38*/ 2000, 2500, 2700, -1,  50, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN | AUDIOCONFIGFLAG_IGNOREROOMS },
	{ /*39*/  300, 1000, 1200, -1, 100, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*40*/  300, 1000, 1200, -1, 100, -1, 100, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*41*/  600, 1500, 1800, -1, 100, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*42*/  600, 1500, 1800, -1, 100, -1, 100, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*43*/  800, 2600, 3500, -1, 100, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*44*/  800, 2600, 3500, -1, 100, -1, 100, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*45*/  200,  800, 1000, -1, 100, -1,   0, 0 },
	{ /*46*/  200,  700, 1000, -1, 100, -1,   0, 0 },
	{ /*47*/ 1000, 2500, 3000, -1, 100, -1,   0, 0 },
	{ /*48*/  500, 1400, 1500, -1, 100, -1,   0, 0 },
	{ /*49*/  500, 2000, 2200, -1, 100, -1,   0, 0 },
	{ /*50*/  400, 2500, 3000, -1,  50, -1,   0, 0 },
	{ /*51*/  400, 2500, 3000, -1,  75, -1,   0, 0 },
	{ /*52*/  200,  500,  800, -1, 100, -1, 100, 0 },
	{ /*53*/ 1000, 1100, 1600, -1, 100, -1,   0, 0 },
#if VERSION >= VERSION_NTSC_1_0
	{ /*54*/  300, 1300, 1500, -1, 100, -1,   0, AUDIOCONFIGFLAG_SPECIALPAN },
#endif
	{ /*55*/  300, 1300, 1500, -1, 100, -1, 200, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*56*/  250,  600,  900, -1, 100, -1, 200, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*57*/   50,  180,  250, -1, 100, -1, 200, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*58*/  100,  400,  600, -1, 100, -1, 200, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*59*/  700, 1100, 1400, -1, 100, -1, 200, AUDIOCONFIGFLAG_SPECIALPAN },
	{ /*60*/  400, 2500, 3000, -1, 100, -1,   0, AUDIOCONFIGFLAG_RESPONDHELLO },
#if VERSION >= VERSION_NTSC_1_0
	{ /*61*/  300,  900, 1100, -1, 100, -1,   0, 0 },
	{ /*62*/ 1000, 2500, 3000, -1, 100, -1,   0, AUDIOCONFIGFLAG_IGNOREROOMS },
	{ /*63*/  400, 1000, 1200, -1, 100, -1,   0, 0 },
#endif
	{ 0 },
};

s16 g_SeqVolumes[] = {
	/* MUSIC_NONE                    */ AL_VOL_FULL * 0.80,
	/* MUSIC_TITLE2                  */ AL_VOL_FULL * 0.70,
	/* MUSIC_EXTRACTION              */ AL_VOL_FULL * 0.75,
	/* MUSIC_PAUSEMENU               */ AL_VOL_FULL * 0.60,
	/* MUSIC_DEFENSE                 */ AL_VOL_FULL * 0.75,
	/* MUSIC_INVESTIGATION_SFX       */ AL_VOL_FULL * 0.35,
	/* MUSIC_ESCAPE                  */ AL_VOL_FULL * 0.70,
	/* MUSIC_DEEPSEA                 */ AL_VOL_FULL * 0.80,
	/* MUSIC_DDTOWER_SFX             */ AL_VOL_FULL * 0.60,
	/* MUSIC_DEFECTION               */ AL_VOL_FULL * 0.70,
	/* MUSIC_DEATH_SOLO              */ AL_VOL_FULL * 0.70,
	/* MUSIC_DEFECTION_INTRO_SFX     */ AL_VOL_FULL * 0.70,
	/* MUSIC_VILLA                   */ AL_VOL_FULL * 0.75,
	/* MUSIC_CI                      */ AL_VOL_FULL * 0.80,
	/* MUSIC_CHICAGO                 */ AL_VOL_FULL * 0.80,
	/* MUSIC_G5                      */ AL_VOL_FULL * 0.75,
	/* MUSIC_DEFECTION_X             */ AL_VOL_FULL * 0.70,
	/* MUSIC_EXTRACTION_X            */ AL_VOL_FULL * 0.80,
	/* MUSIC_INVESTIGATION           */ AL_VOL_FULL * 0.75,
	/* MUSIC_INVESTIGATION_X         */ AL_VOL_FULL * 0.75,
	/* MUSIC_INFILTRATION            */ AL_VOL_FULL * 0.75,
	/* MUSIC_DEATH_BETA              */ AL_VOL_FULL * 0.80,
	/* MUSIC_RESCUE                  */ AL_VOL_FULL * 0.75,
	/* MUSIC_AIRBASE                 */ AL_VOL_FULL * 0.75,
	/* MUSIC_AIRFORCEONE             */ AL_VOL_FULL * 0.75,
	/* MUSIC_DEATH_MP                */ AL_VOL_FULL * 0.90,
	/* MUSIC_EXTRACTION_OUTRO_SFX    */ AL_VOL_FULL * 0.75,
	/* MUSIC_MISSION_UNKNOWN         */ AL_VOL_FULL * 0.80,
	/* MUSIC_PELAGIC                 */ AL_VOL_FULL * 0.75,
	/* MUSIC_CRASHSITE               */ AL_VOL_FULL * (VERSION >= VERSION_NTSC_1_0 ? 0.70 : 0.75),
	/* MUSIC_CRASHSITE_X             */ AL_VOL_FULL * (VERSION >= VERSION_NTSC_1_0 ? 0.70 : 0.75),
	/* MUSIC_ATTACKSHIP              */ AL_VOL_FULL * 0.65,
	/* MUSIC_ATTACKSHIP_X            */ AL_VOL_FULL * 0.65,
	/* MUSIC_SKEDARRUINS             */ AL_VOL_FULL * 0.75,
	/* MUSIC_DEFECTION_INTRO         */ AL_VOL_FULL * 0.40,
	/* MUSIC_DEFECTION_OUTRO         */ AL_VOL_FULL * (VERSION >= VERSION_NTSC_1_0 ? 0.60 : 0.50),
	/* MUSIC_DEFENSE_X               */ AL_VOL_FULL * 0.75,
	/* MUSIC_INVESTIGATION_INTRO     */ AL_VOL_FULL * 0.60,
	/* MUSIC_INVESTIGATION_OUTRO     */ AL_VOL_FULL * 0.50,
	/* MUSIC_VILLA_X                 */ AL_VOL_FULL * 0.75,
	/* MUSIC_CHICAGO_X               */ AL_VOL_FULL * 0.75,
	/* MUSIC_G5_X                    */ AL_VOL_FULL * 0.75,
	/* MUSIC_INFILTRATION_X          */ AL_VOL_FULL * 0.75,
	/* MUSIC_CHICAGO_OUTRO           */ AL_VOL_FULL * 0.60,
	/* MUSIC_EXTRACTION_OUTRO        */ AL_VOL_FULL * 0.60,
	/* MUSIC_EXTRACTION_INTRO        */ AL_VOL_FULL * 0.60,
	/* MUSIC_G5_INTRO                */ AL_VOL_FULL * 0.60,
	/* MUSIC_CHICAGO_INTRO           */ AL_VOL_FULL * 0.60,
	/* MUSIC_VILLA_INTRO1            */ AL_VOL_FULL * 0.60,
	/* MUSIC_INFILTRATION_INTRO      */ AL_VOL_FULL * 0.60,
	/* MUSIC_RESCUE_X                */ AL_VOL_FULL * 0.75,
	/* MUSIC_ESCAPE_X                */ AL_VOL_FULL * 0.75,
	/* MUSIC_AIRBASE_X               */ AL_VOL_FULL * 0.75,
	/* MUSIC_AIRFORCEONE_X           */ AL_VOL_FULL * 0.75,
	/* MUSIC_PELAGIC_X               */ AL_VOL_FULL * 0.75,
	/* MUSIC_DEEPSEA_X               */ AL_VOL_FULL * 0.75,
	/* MUSIC_SKEDARRUINS_X           */ AL_VOL_FULL * 0.75,
	/* MUSIC_AIRBASE_OUTRO_LONG      */ AL_VOL_FULL * 0.60,
	/* MUSIC_DARK_COMBAT             */ AL_VOL_FULL * 0.75,
	/* MUSIC_SKEDAR_MYSTERY          */ AL_VOL_FULL * 0.75,
	/* MUSIC_DEEPSEA_BETA            */ AL_VOL_FULL * 0.75,
	/* MUSIC_CI_OPERATIVE            */ AL_VOL_FULL * 0.75,
	/* MUSIC_DATADYNE_ACTION         */ AL_VOL_FULL * 0.75,
	/* MUSIC_MAIAN_TEARS             */ AL_VOL_FULL * 0.75,
	/* MUSIC_ALIEN_CONFLICT          */ AL_VOL_FULL * 0.75,
	/* MUSIC_ESCAPE_INTRO            */ AL_VOL_FULL * 0.60,
	/* MUSIC_RESCUE_OUTRO            */ AL_VOL_FULL * 0.60,
	/* MUSIC_VILLA_INTRO2            */ AL_VOL_FULL * 0.60,
	/* MUSIC_VILLA_INTRO3            */ AL_VOL_FULL * 0.60,
	/* MUSIC_G5_OUTRO                */ AL_VOL_FULL * 0.60,
	/* MUSIC_G5_MIDCUTSCENE          */ AL_VOL_FULL * 0.60,
	/* MUSIC_MISSION_FAILED          */ AL_VOL_FULL * 0.90,
	/* MUSIC_COMBATSIM_MENU          */ AL_VOL_FULL * 0.90,
	/* MUSIC_MISSION_SUCCESS         */ AL_VOL_FULL * 0.90,
	/* MUSIC_CRASHSITE_INTRO         */ AL_VOL_FULL * 0.60,
	/* MUSIC_AIRBASE_INTRO           */ AL_VOL_FULL * (VERSION >= VERSION_NTSC_1_0 ? 0.47 : 0.60),
	/* MUSIC_ATTACKSHIP_INTRO        */ AL_VOL_FULL * 0.60,
	/* MUSIC_DEEPSEA_MIDCUTSCENE     */ AL_VOL_FULL * 0.60,
	/* MUSIC_AIRFORCEONE_INTRO       */ AL_VOL_FULL * 0.60,
	/* MUSIC_ATTACKSHIP_OUTRO        */ AL_VOL_FULL * 0.60,
	/* MUSIC_ESCAPE_MIDCUTSCENE      */ AL_VOL_FULL * 0.60,
	/* MUSIC_RESCUE_INTRO            */ AL_VOL_FULL * 0.60,
	/* MUSIC_DEEPSEA_INTRO           */ AL_VOL_FULL * 0.60,
	/* MUSIC_INFILTRATION_OUTRO      */ AL_VOL_FULL * 0.60,
	/* MUSIC_PELAGIC_INTRO           */ AL_VOL_FULL * 0.60,
	/* MUSIC_ESCAPE_OUTRO_LONG       */ AL_VOL_FULL * 0.60,
	/* MUSIC_DEFENSE_INTRO           */ AL_VOL_FULL * 0.60,
	/* MUSIC_CRASHSITE_OUTRO         */ AL_VOL_FULL * 0.60,
	/* MUSIC_CREDITS                 */ AL_VOL_FULL * 0.90,
	/* MUSIC_MAINMENU                */ AL_VOL_FULL * 0.90,
	/* MUSIC_DEEPSEA_OUTRO           */ AL_VOL_FULL * 0.60,
	/* MUSIC_AIRFORCEONE_MIDCUTSCENE */ AL_VOL_FULL * 0.60,
	/* MUSIC_PELAGIC_OUTRO           */ AL_VOL_FULL * 0.60,
	/* MUSIC_AIRFORCEONE_OUTRO       */ AL_VOL_FULL * 0.60,
	/* MUSIC_SKEDARRUINS_INTRO       */ AL_VOL_FULL * 0.60,
	/* MUSIC_BETA_NOTE               */ AL_VOL_FULL * 0.80,
	/* MUSIC_AIRBASE_OUTRO           */ AL_VOL_FULL * 0.60,
	/* MUSIC_DEFENSE_OUTRO           */ AL_VOL_FULL * 0.60,
	/* MUSIC_SKEDARRUINS_OUTRO       */ AL_VOL_FULL * 0.60,
	/* MUSIC_VILLA_OUTRO             */ AL_VOL_FULL * 0.60,
	/* MUSIC_SKEDARRUINS_KING        */ AL_VOL_FULL * 0.85,
	/* MUSIC_CI_TRAINING             */ AL_VOL_FULL * 0.75,
	/* MUSIC_CRASHSITE_WIND          */ AL_VOL_FULL * 0.70,
	/* MUSIC_COMBATSIM_COMPLETE      */ AL_VOL_FULL * 0.95,
	/* MUSIC_OCEAN                   */ AL_VOL_FULL * 0.70,
	/* MUSIC_WIND                    */ AL_VOL_FULL * 0.70,
	/* MUSIC_TRAFFIC                 */ AL_VOL_FULL * 0.80,
	/* MUSIC_TITLE1                  */ AL_VOL_FULL * 0.75,
	/* MUSIC_CI_INTRO                */ AL_VOL_FULL * 0.75,
	/* MUSIC_INFILTRATION_SFX        */ AL_VOL_FULL * 0.90,
	/* MUSIC_DEEPSEA_SFX             */ AL_VOL_FULL * 0.90,
	/* MUSIC_AIRFORCEONE_SFX         */ AL_VOL_FULL * 0.90,
	/* MUSIC_ATTACKSHIP_SFX          */ AL_VOL_FULL * 0.90,
	/* MUSIC_SKEDAR_WIND             */ AL_VOL_FULL * 0.90,
	/* MUSIC_ESCAPE_OUTRO_SFX        */ AL_VOL_FULL * 0.60,
	/* MUSIC_A51_LOUDSPEAKER1        */ AL_VOL_FULL * 0.80,
	/* MUSIC_A51_LOUDSPEAKER2        */ AL_VOL_FULL * 0.80,
	/* MUSIC_BETA_MELODY             */ AL_VOL_FULL * 0.80,
	/* MUSIC_ESCAPE_OUTRO_SHORT      */ AL_VOL_FULL * 0.60,
	AL_VOL_FULL * 0.85,
	-1,
};

extern u8 _sfxctlSegmentRomStart;
extern u8 _sfxtblSegmentRomStart;
extern u8 _seqctlSegmentRomStart;
extern u8 _seqctlSegmentRomEnd;
extern u8 _seqtblSegmentRomStart;
extern u8 _sequencesSegmentRomStart;

u16 seq_get_volume(struct seqinstance *seq);
void snd_tick_nosedive(void);
void snd_tick_ufo(void);

bool snd_is_playing_mp3(void)
{
	return g_SndCurMp3.playing;
}

u16 snd_get_sfx_volume(void)
{
#if VERSION >= VERSION_NTSC_1_0
	s32 result;

	if (sndp_get_volume_entry(0) < 0x5000) {
		result = sndp_get_volume_entry(0);
	} else {
		result = 0x5000;
	}

	return result;
#else
	return sndp_get_volume_entry(0);
#endif
}

void snd_set_sfx_volume(u16 volume)
{
	u8 i;

#if VERSION >= VERSION_NTSC_1_0
	if (volume > 0x5000) {
		volume = 0x5000;
	}
#endif

	for (i = 0; i < NUM_VOLUMES; i++) {
		sndp_set_volume_entry(i, volume);
	}

	g_SfxVolume = volume;
}

void snd_set_sfx_volume_untracked(u16 volume)
{
	u8 i;

#if VERSION >= VERSION_NTSC_1_0
	if (volume > 0x5000) {
		volume = 0x5000;
	}
#endif

	for (i = 0; i < NUM_VOLUMES; i++) {
		sndp_set_volume_entry(i, volume);
	}
}

void snd_reset_cur_mp3(void)
{
	g_SndCurMp3.sfxref.id = 0;
	g_SndCurMp3.sfxref.mp3priority = 0;
	g_SndCurMp3.sfxref.unk02 = 0;
	g_SndCurMp3.sfxref.hasconfig = false;
	g_SndCurMp3.playing = false;
	g_SndCurMp3.unk08 = 0;
	g_SndCurMp3.responsetimer240 = -1;
	g_SndCurMp3.prevwhisper = -1;
	g_SndCurMp3.prevacknowledge = -1;
	g_SndCurMp3.prevgreeting = -1;
}

void snd_load_sfx_ctl(void)
{
	s32 i;
	u8 unalignedbuffer[256 + 16];
	u8 *buffer;
	ALBankFile *file;
	ALBank *bank;
	u32 romaddr;
	u32 size;

	g_ALSoundRomOffsets = NULL;
	buffer = (u8 *) ALIGN16((uintptr_t)unalignedbuffer);

	// Load the first 256 bytes of the ctl file.
	size = 256;
	dma_exec(buffer, (romptr_t) &_sfxctlSegmentRomStart, size);

	// Get the ROM address of the first (and only) bank,
	// then load the first 256 bytes of the bank.
	file = (ALBankFile *) buffer;
	romaddr = (romptr_t)&_sfxctlSegmentRomStart;
	romaddr += (u32)file->bankArray[0];
	dma_exec(buffer, romaddr, size);

	// Get the ROM address of the first (and only) instrument,
	// then load the first 256 bytes of the instrument.
	bank = (ALBank *) buffer;
	romaddr = (romptr_t)&_sfxctlSegmentRomStart;
	romaddr += (u32)bank->instArray[0];
	dma_exec(buffer, romaddr, size);

	// Get the soundCount (spoiler: there's 1545+1).
	// The final one might be a null terminator?
	// Or accounting for 1-based indexing of soundnums.
	g_NumSounds = ((ALInstrument *)buffer)->soundCount + 1;

	// Calculate the size of the ALInstrument and load it. The pointer is then
	// shifted forward to point to the instrument's ALSound array.
	size = g_NumSounds * 4 + 20;
	size = ALIGN16(size);
	g_ALSoundRomOffsets = alHeapAlloc(&g_SndHeap, 1, size);
	dma_exec(g_ALSoundRomOffsets, romaddr, size);

	g_ALSoundRomOffsets += 4;

	// Convert ctl-local offsets to ROM offsets
	for (i = 0; i < g_NumSounds; i++) {
		g_ALSoundRomOffsets[i] += (romptr_t) &_sfxctlSegmentRomStart;
	}

	// Allocate and initialise cache
	g_SndCache.indexes = alHeapAlloc(&g_SndHeap, sizeof(u16), g_NumSounds);

	for (i = 0; i < (u32)g_NumSounds; i++) {
		g_SndCache.indexes[i] = -1;
	}

	for (i = 0; i < NUM_CACHE_SLOTS; i++) {
#if VERSION >= VERSION_NTSC_1_0
		g_SndCache.ages[i] = 1;
#else
		g_SndCache.ages[i] = g_Vars.updateframe;
#endif

		g_SndCache.refcounts[i] = 0;
	}
}

#if VERSION >= VERSION_NTSC_1_0
void snd_increment_ages(void)
{
	s32 i;

	for (i = 0; i < NUM_CACHE_SLOTS; i++) {
		if (g_SndCache.refcounts[i] == 0 && g_SndCache.ages[i] < 32000) {
			g_SndCache.ages[i]++;
		}
	}
}
#endif

ALEnvelope *snd_load_envelope(u32 offset, u16 cacheindex)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 spaf[0x50];
	u8 sp5f[0x50];
	ALEnvelope *s2 = (ALEnvelope *)ALIGN16((uintptr_t)spaf);
	ALEnvelope *s1 = (ALEnvelope *)ALIGN16((uintptr_t)sp5f);
	s32 i;
	s32 sum1;
	s32 sum2;

	offset += (romptr_t)&_sfxctlSegmentRomStart;

	do {
		dma_exec_high_priority(s2, offset, 0x40);
		sum1 = 0;

		for (i = 0; i < 16U; i++) {
			sum1 += ((u32 *)s2)[i];
		}

		dma_exec_high_priority(s1, offset, 0x40);
		sum2 = 0;

		for (i = 0; i < 16U; i++) {
			sum2 += ((u32 *)s1)[i];
		}

		if (1);
	} while (sum1 != sum2);
#else
	u8 sp5f[0x50];
	ALEnvelope *s1 = (ALEnvelope *)ALIGN16((uintptr_t)sp5f);

	offset += (romptr_t)&_sfxctlSegmentRomStart;

	dma_exec_high_priority(s1, offset, 0x40);
#endif

	g_SndCache.envelopes[cacheindex] = *s1;

	s1 = g_SndCache.envelopes;
	s1 += cacheindex;

	return s1;
}

ALKeyMap *snd_load_keymap(u32 offset, u16 cacheindex)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 spaf[0x50];
	u8 sp5f[0x50];
	ALKeyMap *s2 = (ALKeyMap *)ALIGN16((uintptr_t)spaf);
	ALKeyMap *s1 = (ALKeyMap *)ALIGN16((uintptr_t)sp5f);
	s32 i;
	s32 sum1;
	s32 sum2;

	offset += (romptr_t)&_sfxctlSegmentRomStart;

	do {
		dma_exec_high_priority(s2, offset, 0x40);
		sum1 = 0;

		for (i = 0; i < 16U; i++) {
			sum1 += ((u32 *)s2)[i];
		}

		dma_exec_high_priority(s1, offset, 0x40);
		sum2 = 0;

		for (i = 0; i < 16U; i++) {
			sum2 += ((u32 *)s1)[i];
		}

		if (1);
	} while (sum1 != sum2);
#else
	u8 sp5f[0x50];
	ALKeyMap *s1 = (ALKeyMap *)ALIGN16((uintptr_t)sp5f);

	offset += (romptr_t)&_sfxctlSegmentRomStart;

	dma_exec_high_priority(s1, offset, 0x40);
#endif

	g_SndCache.keymaps[cacheindex] = *s1;

	s1 = g_SndCache.keymaps;
	s1 += cacheindex;

	return s1;
}

ALADPCMBook *snd_load_adpcm_book(u32 offset, u16 cacheindex)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 spaf[0x150];
	u8 sp5f[0x150];
	ALADPCMBook *s2 = (ALADPCMBook *)ALIGN16((uintptr_t)spaf);
	ALADPCMBook *s1 = (ALADPCMBook *)ALIGN16((uintptr_t)sp5f);
	s32 i;
	s32 sum1;
	s32 sum2;

	offset += (romptr_t)&_sfxctlSegmentRomStart;

	do {
		dma_exec_high_priority(s2, offset, 0x140);
		sum1 = 0;

		for (i = 0; i < 80U; i++) {
			sum1 += ((u32 *)s2)[i];
		}

		dma_exec_high_priority(s1, offset, 0x140);
		sum2 = 0;

		for (i = 0; i < 80U; i++) {
			sum2 += ((u32 *)s1)[i];
		}

		if (1);
	} while (sum1 != sum2);
#else
	u8 sp5f[0x150];
	ALADPCMBook *s1 = (ALADPCMBook *)ALIGN16((uintptr_t)sp5f);

	offset += (romptr_t)&_sfxctlSegmentRomStart;

	dma_exec_high_priority(s1, offset, 0x140);
#endif

	g_SndCache.books[cacheindex] = *s1;

	s1 = g_SndCache.books;
	s1 += cacheindex;

	return s1;
}

ALADPCMloop *snd_load_adpcm_loop(u32 offset, u16 cacheindex)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 spaf[0x50];
	u8 sp5f[0x50];
	ALADPCMloop *s2 = (ALADPCMloop *)ALIGN16((uintptr_t)spaf);
	ALADPCMloop *s1 = (ALADPCMloop *)ALIGN16((uintptr_t)sp5f);
	s32 i;
	s32 sum1;
	s32 sum2;

	if (offset == 0) {
		return NULL;
	}

	offset += (romptr_t)&_sfxctlSegmentRomStart;

	do {
		dma_exec_high_priority(s2, offset, 0x40);
		sum1 = 0;

		for (i = 0; i < 16U; i++) {
			sum1 += ((u32 *)s2)[i];
		}

		dma_exec_high_priority(s1, offset, 0x40);
		sum2 = 0;

		for (i = 0; i < 16U; i++) {
			sum2 += ((u32 *)s1)[i];
		}

		if (1);
	} while (sum1 != sum2);
#else
	u8 sp5f[0x50];
	ALADPCMloop *s1 = (ALADPCMloop *)ALIGN16((uintptr_t)sp5f);

	if (offset == 0) {
		return NULL;
	}

	offset += (romptr_t)&_sfxctlSegmentRomStart;

	dma_exec_high_priority(s1, offset, 0x40);
#endif

	g_SndCache.loops[cacheindex] = *s1;

	s1 = g_SndCache.loops;
	s1 += cacheindex;

	return s1;
}

ALWaveTable *snd_load_wavetable(u32 offset, u16 cacheindex)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 spaf[0x50];
	u8 sp5f[0x50];
	ALWaveTable *s2 = (ALWaveTable *)ALIGN16((uintptr_t)spaf);
	ALWaveTable *s1 = (ALWaveTable *)ALIGN16((uintptr_t)sp5f);
	s32 i;
	s32 sum1;
	s32 sum2;
	ALWaveTable *tmp;

	offset += (romptr_t)&_sfxctlSegmentRomStart;

	do {
		dma_exec_high_priority(s2, offset, 0x40);
		sum1 = 0;

		for (i = 0; i < 16U; i++) {
			sum1 += ((u32 *)s2)[i];
		}

		dma_exec_high_priority(s1, offset, 0x40);
		sum2 = 0;

		for (i = 0; i < 16U; i++) {
			sum2 += ((u32 *)s1)[i];
		}

		if (1);
	} while (sum1 != sum2);
#else
	u8 sp5f[0x50];
	ALWaveTable *s1 = (ALWaveTable *)ALIGN16((uintptr_t)sp5f);
	ALWaveTable *tmp;

	offset += (romptr_t)&_sfxctlSegmentRomStart;

	dma_exec_high_priority(s1, offset, 0x40);
#endif

	tmp = &g_SndCache.wavetables[cacheindex];

	*tmp = *s1;

	tmp->base += (romptr_t)&_sfxtblSegmentRomStart;

	if (tmp->type == AL_ADPCM_WAVE) {
		tmp->waveInfo.adpcmWave.book = snd_load_adpcm_book((uintptr_t)tmp->waveInfo.adpcmWave.book, cacheindex);
		tmp->waveInfo.adpcmWave.loop = snd_load_adpcm_loop((uintptr_t)tmp->waveInfo.adpcmWave.loop, cacheindex);
	}

	return tmp;
}

void snd_set_sound_mode(s32 mode)
{
	s32 i;

	g_SoundMode = mode;

	switch (mode) {
	case SOUNDMODE_MONO:
		alSurround_OutputType(SPEAKERMODE_MONO);
		break;
	case SOUNDMODE_STEREO:
		alSurround_OutputType(SPEAKERMODE_STEREO);
		break;
	case SOUNDMODE_HEADPHONE:
		alSurround_OutputType(SPEAKERMODE_HEADPHONE);
		break;
	case SOUNDMODE_SURROUND:
		alSurround_OutputType(SPEAKERMODE_SURROUND);
		break;
	}

	alSurround_ReverbSetup(0, 4);

	for (i = 1; i < g_SndMaxFxBusses; i++) {
		switch (mode) {
		case SOUNDMODE_STEREO:
		case SOUNDMODE_HEADPHONE:
		case SOUNDMODE_SURROUND:
			alSurround_ReverbSetup(i, 4);
			break;
		}
	}
}

ALSound *snd_load_sound(s16 soundnum)
{
	union soundnumhack tmp;
	u16 cacheindex;
	u16 *ptr;
	ALSound *sound;
	s32 oldestindex;
	u32 oldestage;
	s32 i;
	s16 sfxnum;
	u8 sp47[0x58];

	sound = (ALSound *)ALIGN16((uintptr_t)sp47);

	tmp.packed = soundnum;
	sfxnum = tmp.id;

	if (snd_is_mp3(tmp.packed)) {
		return NULL;
	}

	// If this sound doesn't exist in the cache
	cacheindex = g_SndCache.indexes[sfxnum];

	if (cacheindex == 0xffff) {
		// Find the oldest cache item
		oldestindex = -1;
		oldestage = 0;

		for (i = 0; i < NUM_CACHE_SLOTS; i++) {
			if (g_SndCache.refcounts[i] == 0) {
#if VERSION >= VERSION_NTSC_1_0
				if (g_SndCache.ages[i] > oldestage) {
					oldestage = g_SndCache.ages[i];
					oldestindex = i;
				}
#else
				s32 age = g_Vars.updateframe - g_SndCache.ages[i] + 1;

				if (age > oldestage) {
					oldestage = age;
					oldestindex = i;
				}
#endif
			}
		}

		cacheindex = oldestindex;

		// Remove the old sound from the cacheindexes list
		ptr = g_SndCache.indexes;

		for (i = 0; i < (u32)g_NumSounds; i++) {
			if (*ptr == cacheindex) {
				*ptr = 0xffff;
			}

			ptr++;
		}

		// DMA the ALSound data
		dma_exec_high_priority(sound, g_ALSoundRomOffsets[sfxnum - 1], 0x40);

		// Promote segment offsets to pointers and load their child data
		sound->envelope = snd_load_envelope((uintptr_t)sound->envelope, cacheindex);
		sound->wavetable = snd_load_wavetable((uintptr_t)sound->wavetable, cacheindex);
		sound->keyMap = snd_load_keymap((uintptr_t)sound->keyMap, cacheindex);

		// Save the ALSound into the cache
		g_SndCache.sounds[cacheindex] = *sound;

		g_SndCache.indexes[sfxnum] = cacheindex;
	}

	// Reset this cache item's age, even if it already existed in the cache
#if VERSION >= VERSION_NTSC_1_0
	g_SndCache.ages[cacheindex] = 1;
#else
	g_SndCache.ages[cacheindex] = g_Vars.updateframe;
#endif

	return &g_SndCache.sounds[cacheindex];
}

void seq_init(struct seqinstance *seq)
{
	u32 stack;
	ALSeqpConfig config;

	config.maxVoices = 44;
	config.maxEvents = 64;
	config.maxChannels = 16;
	config.debugFlags = 0;
	config.heap = &g_SndHeap;

	osc_set_handlers(&config);

	if (IS4MB()) {
		g_SeqBufferSize = MAX_SEQ_SIZE_4MB;
	} else {
		g_SeqBufferSize = MAX_SEQ_SIZE_8MB;
	}

	seq->data = alHeapAlloc(&g_SndHeap, 1, g_SeqBufferSize);
	seq->seqp = alHeapAlloc(&g_SndHeap, 1, sizeof(N_ALCSPlayer));

	n_alCSPNew(seq->seqp, &config);

	n_alCSPSetBank(seq->seqp, var80095204);
}

void snd_add_ref(ALSound *sound)
{
	if (sound >= &g_SndCache.sounds[0] && sound <= &g_SndCache.sounds[NUM_CACHE_SLOTS - 1]) {
		s32 cacheindex = sound - g_SndCache.sounds;
		g_SndCache.refcounts[cacheindex]++;
	}
}

void snd_remove_ref(ALSound *sound)
{
	if (sound >= &g_SndCache.sounds[0] && sound <= &g_SndCache.sounds[NUM_CACHE_SLOTS - 1]) {
		s32 cacheindex = sound - g_SndCache.sounds;
		g_SndCache.refcounts[cacheindex]--;
	}
}

void snd_init(void)
{
	ALSndpConfig sndpconfig;
	ALSynConfig synconfig;
#if VERSION >= VERSION_PAL_BETA
	u32 settings[3];
#endif

#if VERSION >= VERSION_JPN_FINAL
	u32 heaplen = 1024 * 441;
#elif VERSION >= VERSION_PAL_BETA
	u32 heaplen = 1024 * 446;
#elif VERSION >= VERSION_NTSC_1_0
	u32 heaplen = 1024 * 441;
#else
	u32 heaplen = 1024 * 438;
#endif

	g_Vars.langfilteron = false;

	if (IS4MB()) {
		g_SndMaxFxBusses = 1;

		heaplen -= 1024 * (PAL ? 6 : 38);
		heaplen -= 1024 * 137;
		heaplen -= 1024 * 12;
		heaplen -= 1024 * 23;

		g_SndMp3Enabled = false;
	} else {
		g_SndMp3Enabled = true;
		g_SndMaxFxBusses = 2;

		if (arg_find_by_prefix(1, "-nomp3")) {
			g_SndMp3Enabled = false;
		}
	}

	if (!g_SndDisabled) {
		// Allocate memory for the audio heap,
		// clear it and give it to the audio library
		u32 len = &_seqctlSegmentRomEnd - &_seqctlSegmentRomStart;
		u8 *ptr = memp_alloc(heaplen, MEMPOOL_PERMANENT);
		s32 i;
		u8 *heapstart = ptr;
		u8 *end = heapstart + heaplen;
		ALBankFile *bankfile;

		while (ptr < end) {
			*ptr = 0;
			ptr++;
		}

		alHeapInit(&g_SndHeap, heapstart, heaplen);

		// Allocate some space at the start of the heap for a string identifier.
		// This might be used to determine if the heap has overflowed.
		g_SndGuardStringPtr = alHeapAlloc(&g_SndHeap, 1, ALIGN16(sizeof(g_SndGuardString)));
		strcpy(g_SndGuardStringPtr, g_SndGuardString);

		// Load sfx.ctl
		snd_load_sfx_ctl();

		// Load seq.ctl
		var80095200 = 0xffffffff;
		bankfile = alHeapAlloc(&g_SndHeap, 1, len);
		dma_exec(bankfile, (romptr_t) &_seqctlSegmentRomStart, len);

		// Load seq.tbl
		alBnkfNew(bankfile, &_seqtblSegmentRomStart);

		// Load the sequences table. To do this, load the header of the
		// sequences segment and read the number of sequences, then allocate
		// enough space for the table and load it.
		var80095204 = bankfile->bankArray[0];
		g_SeqTable = alHeapDBAlloc(0, 0, &g_SndHeap, 1, 0x10);
		dma_exec(g_SeqTable, (romptr_t) &_sequencesSegmentRomStart, 0x10);

		len = g_SeqTable->count * sizeof(struct seqtableentry) + 4;
		g_SeqTable = alHeapDBAlloc(0, 0, &g_SndHeap, 1, len);
		dma_exec(g_SeqTable, (romptr_t) &_sequencesSegmentRomStart, (len + 0xf) & ~0xf);

		// Promote segment-relative offsets to ROM addresses
		for (i = 0; i < g_SeqTable->count; i++) {
			g_SeqTable->entries[i].romaddr += (romptr_t) &_sequencesSegmentRomStart;
		}

		synconfig.maxVVoices = 44;
		synconfig.maxPVoices = 30;
		synconfig.maxUpdates = 64;
		synconfig.dmaproc = NULL;
		synconfig.outputRate = 0;
		synconfig.heap = &g_SndHeap;
		synconfig.maxFXbusses = g_SndMaxFxBusses;

		for (i = 0; i < g_SndMaxFxBusses; i++) {
			synconfig.fxTypes[i] = AL_FX_CUSTOM;
		}

		sndpconfig.maxEvents = 64;
		sndpconfig.maxStates = 64;
		sndpconfig.maxSounds = 20;
		sndpconfig.maxVolumes = NUM_VOLUMES;
		sndpconfig.heap = &g_SndHeap;

#if VERSION >= VERSION_PAL_BETA
		settings[0] = 22020;
		settings[1] = 1;
		settings[2] = 2000;

		amgr_create(&synconfig, settings);
#else
		amgr_create(&synconfig);
#endif

		if (g_SndMp3Enabled) {
			osSyncPrintf("RWI : Initialising the new and improved MP3 player\n");

			mp3_init(&g_SndHeap);
			mp3_set_vol(AL_VOL_FULL, true);
			mp3_set_pan(0, true);

			osSyncPrintf("RWI : MP3 player Initialising Done\n");
		}

		for (i = 0; i < ARRAYCOUNT(g_SeqInstances); i++) {
			seq_init(&g_SeqInstances[i]);
		}

		osSyncPrintf("gsSndpNew\n");

		n_alSndpNew(&sndpconfig);

		osSyncPrintf("Set the sample callbacks\n");

		sndp_set_addref_callback(snd_add_ref);
		sndp_set_removeref_callback(snd_remove_ref);

		amgr_start_thread();

		snd_set_sound_mode(g_SoundMode);
	}
}

bool snd_is_mp3(s16 soundnum)
{
	union soundnumhack tmp;
	tmp.packed = soundnum;

	return tmp.mp3priority != 0;
}

bool snd_stop_mp3(s16 soundnum)
{
	if (!g_SndDisabled && g_SndMp3Enabled) {
		if (mp3_is_busy() && g_SndCurMp3.unk08 != 0) {
			return false;
		}

		mp3_stop();

		g_SndCurMp3.playing = false;
		g_SndCurMp3.responsetimer240 = -1;
	}

	return true;
}

void snd_stub_1arg(s32 arg0)
{
	// empty
}

bool seq_play(struct seqinstance *seq, s32 tracknum)
{
	u32 stack;
	s32 binlen;
	u8 *binstart;
	u8 *zipstart;
	s32 ziplen;
	u8 scratch[1024 * 5];

	s32 state = n_alCSPGetState(seq->seqp);

	if (g_SndDisabled) {
		return false;
	}

	seq->tracknum = tracknum;

	if (g_SeqTable && tracknum);

	if (state != AL_STOPPED) {
		return false;
	}

	if (g_SeqTable->entries[seq->tracknum].romaddr < 0x10000) {
		return false;
	}

	binlen = ALIGN16(g_SeqTable->entries[seq->tracknum].binlen) + 0x40;

	if (binlen >= g_SeqBufferSize) {
		return false;
	}

	ziplen = ALIGN16(g_SeqTable->entries[seq->tracknum].ziplen);
#if VERSION < VERSION_NTSC_1_0
	if (seq->data);
#endif
	binstart = seq->data;
	zipstart = binstart + binlen - ziplen;

	dma_exec(zipstart, g_SeqTable->entries[seq->tracknum].romaddr, ziplen);

	ziplen = rzip_inflate(zipstart, binstart, scratch);

#if VERSION < VERSION_NTSC_1_0
	if (ziplen == 0) {
		char message[128];
		sprintf(message, "DMA-Crash %s %d Ram: %02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
				"snd.c", 1676,
				zipstart[0], zipstart[1], zipstart[2], zipstart[3],
				zipstart[4], zipstart[5], zipstart[6], zipstart[7],
				zipstart[8], zipstart[9], zipstart[10], zipstart[11],
				zipstart[12], zipstart[13], zipstart[14], zipstart[15]);
		crash_set_message(message);
		CRASH();
	}
#endif

#if AVOID_UB
	// To avoid undefined behaviour, we must change the sequence player's state
	// from AL_STOPPED to something else. Otherwise a race condition can occur
	// where the same sequence player is used for two sequences if the audio
	// thread hasn't run between the two calls and updated its state.
	seq->seqp->state = AL_STARTING;
#endif

	n_alCSeqNew(&seq->seq, seq->data);
	n_alCSPSetSeq(seq->seqp, &seq->seq);
	seq_set_volume(seq, seq_get_volume(seq));
	n_alCSPPlay(seq->seqp);

	return true;
}

u16 seq_get_volume(struct seqinstance *seq)
{
	return g_SndDisabled ? AL_VOL_FULL : seq->volume;
}

void seq_set_volume(struct seqinstance *seq, u16 volume)
{
	if (!g_SndDisabled) {
		u32 tmp = g_SeqVolumes[seq->tracknum] * volume;
		tmp >>=	15;

		seq->volume = volume;

		if (tmp > AL_VOL_FULL) {
			tmp = AL_VOL_FULL;
		}

		n_alCSPSetVol(seq->seqp, tmp);
	}
}

void snd_handle_retrace(void)
{
	// empty
}

void snd_pause_mp3(void)
{
	if (g_SndMp3Enabled) {
		mp3_pause();
	}
}

void snd_unpause_mp3(void)
{
	if (g_SndMp3Enabled) {
		mp3_unpause();
	}
}

void snd_stub_0args(void)
{
	// empty
}

void snd_tick(void)
{
#if VERSION >= VERSION_NTSC_1_0
	struct sndstate *stateptrs[64];
	struct sndstate states[64];
	s32 i;
	s32 curtime;
	struct sndstate *state;
#endif
	OSPri prevpri;
	s32 volume;
	union soundnumhack sp50;
	s32 index;
	s32 stack;

#if VERSION >= VERSION_NTSC_1_0
	static s32 g_SndMostEverPlaying2 = -1;

	snd_increment_ages();

	prevpri = osGetThreadPri(NULL);
	osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);

	curtime = sndp_get_curtime();
	state = sndp_get_head_state();

	g_SndNumPlaying = 0;
	i = 0;

	while (state) {
		stateptrs[i] = state;
		states[i] = *state;

		g_SndNumPlaying++;

		if ((state->flags & SNDSTATEFLAG_NO_DECAY) == 0
				&& stateptrs[i]->state == AL_PLAYING
				&& stateptrs[i]->cleanuptime > 0
				&& stateptrs[i]->cleanuptime < curtime) {
			state->cleanuptime = 0;
			sndp_cleanup();
			break;
		}

		state = (struct sndstate *)state->node.next;
		i++;
	}

	osSetThreadPri(0, prevpri);

	if (g_SndNumPlaying > g_SndMostEverPlaying) {
		g_SndMostEverPlaying = g_SndNumPlaying;
	}

	if (g_SndMostEverPlaying != g_SndMostEverPlaying2) {
		g_SndMostEverPlaying2 = g_SndMostEverPlaying;
	}
#endif

	if (!g_SndDisabled && g_SndMp3Enabled) {
		if (g_Vars.stagenum == STAGE_AIRFORCEONE) {
			snd_tick_nosedive();
		} else if (g_Vars.stagenum == STAGE_ESCAPE) {
			snd_tick_ufo();
		}

		// In cutscenes, force sfx volume to at least the same as music
		if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
			volume = music_get_volume() > g_SfxVolume ? music_get_volume() : g_SfxVolume;

			if (volume != snd_get_sfx_volume()) {
				snd_set_sfx_volume_untracked(volume);
			}
		} else {
			if (g_SfxVolume != snd_get_sfx_volume()) {
				snd_set_sfx_volume_untracked(g_SfxVolume);
			}
		}

		// Check for sound heap overflow
		if (g_SndGuardStringPtr != NULL) {
			if (strcmp(g_SndGuardStringPtr, g_SndGuardString) != 0) {
#if VERSION < VERSION_NTSC_1_0
				crash_set_message("Snd Heap Check FAILED");
				CRASH();
#endif
			}
		}

		if (!mp3_is_busy() && g_SndCurMp3.playing) {
			if (g_SndCurMp3.unk08) {
				mp3_play_file(g_SndCurMp3.romaddr, g_SndCurMp3.romsize);
				return;
			}

			switch (g_SndCurMp3.responsetype) {
			case MP3RESPONSETYPE_ACKNOWLEDGE:
			case MP3RESPONSETYPE_WHISPER:
				g_SndCurMp3.responsetimer240 = TICKS(60);
				break;
			case MP3RESPONSETYPE_GREETING:
				g_SndCurMp3.responsetimer240 = 1;
				break;
			}

			g_SndCurMp3.playing = false;
			return;
		}

		if (g_SndCurMp3.responsetimer240 > 0) {
			g_SndCurMp3.responsetimer240 -= g_Vars.lvupdate240;

			if (g_SndCurMp3.responsetimer240 <= 0) {
				if (g_SndCurMp3.responsetype == MP3RESPONSETYPE_WHISPER) {
					do {
						index = random() % 4;
					} while (index == g_SndCurMp3.prevwhisper);

					g_SndCurMp3.prevwhisper = index;

					switch (index) {
					case 0: sp50.packed = MP3_LO_ZZ(FILE_AJOREP01M); break;
					case 1: sp50.packed = MP3_LO_ZZ(FILE_AJOREP02M); break;
					case 2: sp50.packed = MP3_LO_ZZ(FILE_AJOREP03M); break;
					case 3: sp50.packed = MP3_LO_ZZ(FILE_AJOREP04M); break;
					}
				} else if (g_SndCurMp3.responsetype == MP3RESPONSETYPE_ACKNOWLEDGE) {
					do {
						index = random() % 4;
					} while (index == g_SndCurMp3.prevacknowledge);

					g_SndCurMp3.prevacknowledge = index;

					switch (index) {
					case 0: sp50.packed = MP3_LO_ZZ(FILE_AJORPLD01M); break;
					case 1: sp50.packed = MP3_LO_ZZ(FILE_AJORPLD02M); break;
					case 2: sp50.packed = MP3_LO_ZZ(FILE_AJORPLD03M); break;
					case 3: sp50.packed = MP3_LO_ZZ(FILE_AJORPLD04M); break;
					}
				} else if (g_SndCurMp3.responsetype == MP3RESPONSETYPE_GREETING) {
					do {
						index = random() % 4;
					} while (index == g_SndCurMp3.prevgreeting);

					g_SndCurMp3.prevgreeting = index;

					switch (index) {
					case 0: sp50.packed = MP3_ZZ(FILE_AJOINST01M); break;
					case 1: sp50.packed = MP3_ZZ(FILE_AJOINST02M); break;
					case 2: sp50.packed = MP3_ZZ(FILE_AJOINST03M); break;
					case 3: sp50.packed = MP3_ZZ(FILE_AJOINST04M); break;
					}
				}

				g_SndCurMp3.responsetimer240 = -1;
				snd_start(0, sp50.packed, 0, -1, -1, -1.0f, -1, -1);
			}
		}
	}
}

s16 snd_sfxref_to_sndnum(s16 sfxnum)
{
	union soundnumhack tmp;

	tmp.packed = sfxnum;
	sfxnum = tmp.id;

	if (tmp.id);

	return sfxnum;
}

bool snd_is_disabled(void)
{
	return g_SndDisabled;
}

void snd_start_mp3_by_filenum(u32 filenum)
{
	union soundnumhack sfxref;

	if (!g_SndDisabled && g_SndMp3Enabled) {
		sfxref.packed = 0;
		sfxref.unk02 = 0;
		sfxref.mp3priority = 1; // high priority
		sfxref.id = filenum;

		snd_start(0, sfxref.packed, NULL, -1, -1, -1, -1, -1);
	}
}

/**
 * Return true if the player has the language filter enabled
 * and the given audio ID is one that should be filtered out.
 */
bool snd_is_filtered(s32 audio_id)
{
	if (g_Vars.langfilteron) {
		union soundnumhack sfxref;
		sfxref.packed = audio_id;

		if (sfxref.hasconfig) {
			if (g_AudioConfigs[g_AudioRussMappings[sfxref.confignum].audioconfig_index].flags & AUDIOCONFIGFLAG_OFFENSIVE) {
				return true;
			}
		}
#if VERSION >= VERSION_NTSC_1_0
		else {
			// @bug: The masking here makes it impossible to match hangar guy's
			// audio ID, so his phrase can be said even with the lang filter on.
			// The switch value resolves to sfxref & 0x7ff, while hangar guy's
			// reference is 0x17ad.
			switch (sfxref.id) {
			case SFXNUM_051D_ELVIS_KISS_MY_ALIEN_BUTT:
			case SFXNUM_051E_ELVIS_ILL_KICK_YOUR_ASS:
			case MP3(FILE_ACIROGE01M):
				return true;
			}
		}
#endif
	}

	return false;
}

void snd_adjust(struct sndstate **handle, bool ismp3, s32 vol, s32 pan, s32 soundnum, f32 pitch, s32 fxbus, s32 fxmixarg, bool forcefxmix)
{
	s32 fxmix = -1;
	union soundnumhack sp20;
	union soundnumhack sp1c;
	struct audioconfig *config;

	if (forcefxmix || fxmixarg != -1) {
		fxmix = fxmixarg != -1 ? fxmixarg : 0;

#if VERSION >= VERSION_NTSC_1_0
		if (pan != -1 && g_SoundMode == SOUNDMODE_SURROUND && (pan & 0x80)) {
			fxmix += 128;
		}
#else
		if (g_SoundMode == SOUNDMODE_SURROUND && (pan & 0x80)) {
			fxmix += 128;
		}
#endif
	}

	if (soundnum > 0) {
		sp20.packed = soundnum;

		if (sp20.hasconfig) {
			s32 index = g_AudioRussMappings[sp20.confignum].audioconfig_index;

			sp1c.packed = g_AudioRussMappings[sp20.confignum].soundnum;
			sp1c.hasconfig = false;

			soundnum = sp1c.packed;

			config = &g_AudioConfigs[index];

			if (config->volpercentage != 100) {
				vol = vol * config->volpercentage / 100;
			}

			if (config->pan != -1) {
				pan = config->pan;
			}

			if (g_Vars.langfilteron && (config->flags & AUDIOCONFIGFLAG_OFFENSIVE)) {
				vol = 0;
			}
		}
	}

	if (ismp3) {
		if (vol != -1) {
			vol = vol * snd_get_sfx_volume() / AL_VOL_FULL;
			mp3_set_vol(vol, true);
		}

		if (pan != -1) {
			mp3_set_pan(pan, true);
		}
	}

	if (*handle != NULL) {
		if (vol != -1) {
			sndp_post_event(*handle, AL_SNDP_VOL_EVT, vol);
		}

		if (pan != -1) {
			sndp_post_event(*handle, AL_SNDP_PAN_EVT, pan & 0x7f);
		}

		if (pitch != -1.0f) {
			sndp_post_event(*handle, AL_SNDP_PITCH_EVT, *(s32 *)&pitch);
		}

		if (fxmix != -1) {
			sndp_post_event(*handle, AL_SNDP_FX_EVT, fxmix);
		}
	}
}

/**
 * Wrapper around snd_start, but using the same arguments as snd_adjust.
 *
 * Unlike snd_start, this function does the follow "extra" things:
 * - Allows increasing the fxmix by 128 (likely to do with surround sound data)
 * - Applies volpercentage from config
 * - Applies pan from config
 * - Applies language filter if flagged as offensive in config
 *
 * The function starts the sound by ensuring the current thread is higher
 * priority than the audio thread. This doesn't matter so this is pointless.
 *
 * It is likely that snd_adjust was written first, then copied to create
 * snd_start_extra, and because snd_adjust has to be threadsafe they made this
 * one threadsafe as well.
 */
struct sndstate *snd_start_extra(struct sndstate **handle, bool ismp3, s32 volume, s32 pan, s32 soundnum, f32 pitch, s32 fxbus, s32 fxmixarg, bool forcefxmix)
{
	OSPri prevpri = osGetThreadPri(NULL);
	s32 fxmix = -1;
	struct sndstate *state;
	union soundnumhack sp30;
	union soundnumhack sp2c;
	struct audioconfig *config;

	osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);

	if (forcefxmix || fxmixarg != -1) {
		fxmix = fxmixarg != -1 ? fxmixarg : 0;

#if VERSION >= VERSION_NTSC_1_0
		if (pan != -1 && g_SoundMode == SOUNDMODE_SURROUND && (pan & 0x80)) {
			fxmix += 128;
		}
#else
		if (g_SoundMode == SOUNDMODE_SURROUND && (pan & 0x80)) {
			fxmix += 128;
		}
#endif
	}

	if (soundnum) {
		sp30.packed = soundnum;

		if (sp30.hasconfig) {
			s32 index = g_AudioRussMappings[sp30.confignum].audioconfig_index;

			sp2c.packed = g_AudioRussMappings[sp30.confignum].soundnum;
			sp2c.hasconfig = false;

			soundnum = sp2c.packed;

			config = &g_AudioConfigs[index];

			if (config->volpercentage != 100) {
				volume = volume * config->volpercentage / 100;
			}

			if (config->pan != -1) {
				pan = config->pan;
			}

			if (g_Vars.langfilteron && (config->flags & AUDIOCONFIGFLAG_OFFENSIVE)) {
				volume = 0;
			}
		}
	}

	state = snd_start(var80095200, soundnum, handle, volume, pan, pitch, fxbus, fxmix);

	osSetThreadPri(0, prevpri);

	return state;
}

struct sndstate *snd_start(s32 arg0, s16 sound, struct sndstate **handle, s32 volumearg, s32 panarg, f32 pitcharg, s32 fxbusarg, s32 fxmixarg)
{
	union soundnumhack sp44;
	union soundnumhack sp40;
	u8 fxmix;
	u8 fxbus;
	u8 pan;
	u16 volume;
	f32 pitch;

	fxmix = fxmixarg != -1 ? fxmixarg : 0;
	fxbus = fxbusarg != -1 ? fxbusarg : 1;
	pan = panarg != -1 ? panarg : AL_PAN_CENTER;
	volume = volumearg != -1 ? volumearg : AL_VOL_FULL;
	pitch = pitcharg > 0.0f ? pitcharg : 1.0f;

	sp44.packed = sound;

	if (g_SndDisabled) {
		return NULL;
	}

	sp40.packed = sp44.hasconfig ? g_AudioRussMappings[sp44.confignum].soundnum : sp44.packed;

	if (sp40.id == SFXNUM_0037 || sp40.id == SFXNUM_0009) {
		return NULL;
	}

	if (snd_is_mp3(sp40.packed)) {
		snd_start_mp3(sp40.packed, volume, pan, 0);

		if (handle != NULL) {
			*handle = NULL;
		}

		return NULL;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (sp40.id < (u32)g_NumSounds) {
		return sndp_play_sound(arg0, sp40.id, volume, pan & 0x7f, pitch, fxmix, IS4MB() ? 0 : fxbus, handle);
	}

	return NULL;
#else
	return sndp_play_sound(arg0, sp40.id, volume, pan & 0x7f, pitch, fxmix, IS4MB() ? 0 : fxbus, handle);
#endif
}

const char var70053be0[] = "Snd_Play_Universal : Overriding -> Link = %d\n";

#if VERSION < VERSION_NTSC_1_0
const char var700552f0nb[] = "Snd_Play_Mpeg : sndId=%d, vol=%d, pan=%d\n";
#endif

const char var70053c10[] = "Snd_Play_Mpeg : SYSTEM IS DISABLED\n";
const char var70053c34[] = "Snd_Play_Mpeg  : Lib called -> Adr=%x\n";
const char var70053c5c[] = "Snd_Play_Mpeg  : Chunk size -> Adr=%x\n";

void snd_start_mp3(s16 soundnum, s32 volume, s32 pan, s32 responseflags)
{
	union soundnumhack sp24;
	union soundnumhack sp20;

	sp24.packed = soundnum;

	if (!g_SndDisabled) {
		if (sp24.hasconfig) {
			sp20.packed = g_AudioRussMappings[sp24.confignum].soundnum;
			sp20.hasconfig = false;
		} else {
			sp20.packed = soundnum;
		}

		if (!g_SndCurMp3.playing
				|| ((sp20.mp3priority != 1 || g_SndCurMp3.sfxref.mp3priority != 1)
				 && sp20.mp3priority <= g_SndCurMp3.sfxref.mp3priority)) {
			if (sp24.hasconfig) {
				if (g_AudioConfigs[sp24.confignum].volpercentage != -1) {
					volume = g_AudioConfigs[sp24.confignum].volpercentage * AL_VOL_FULL / 100;
				}

				if (g_AudioConfigs[sp24.confignum].pan != -1) {
					pan = g_AudioConfigs[sp24.confignum].pan;
				}

				// This is the same thing again
				if (g_AudioConfigs[sp24.confignum].pan != -1) {
					pan = g_AudioConfigs[sp24.confignum].pan;
				}

				if (g_Vars.langfilteron && (g_AudioConfigs[sp24.confignum].flags & AUDIOCONFIGFLAG_OFFENSIVE)) {
					volume = 0;
				}
			}

			volume = volume * snd_get_sfx_volume() / AL_VOL_FULL;

			g_SndCurMp3.romaddr = file_get_rom_address(sp20.id);
			g_SndCurMp3.romsize = file_get_rom_size(sp20.id);

			mp3_set_vol(volume, true);
			mp3_set_pan(pan, true);

			mp3_play_file(g_SndCurMp3.romaddr, g_SndCurMp3.romsize);

			mp3_set_vol(volume, true);
			mp3_set_pan(pan, true);

			g_SndCurMp3.sfxref.packed = sp20.packed;
			g_SndCurMp3.playing = true;
			g_SndCurMp3.responsetimer240 = -1;
			g_SndCurMp3.responsetype = MP3RESPONSETYPE_NONE;

			if (g_SndCurMp3.sfxref.unk02 == 2) {
				g_SndCurMp3.responsetype = MP3RESPONSETYPE_ACKNOWLEDGE;
			} else if (g_SndCurMp3.sfxref.unk02 == 1) {
				g_SndCurMp3.responsetype = MP3RESPONSETYPE_WHISPER;
			}

			if ((sp24.hasconfig && (g_AudioConfigs[sp24.confignum].flags & AUDIOCONFIGFLAG_RESPONDHELLO)) || (responseflags & 1)) {
				g_SndCurMp3.responsetype = MP3RESPONSETYPE_GREETING;
			}
		}
	}
}

void snd_play_nosedive(s32 seconds)
{
	g_SndNosediveDuration240 = seconds * TICKS(240);
	g_SndNosediveAge240 = 0;
	g_SndNosediveVolume = 0;
	g_SndNosediveHandle = NULL;
}

void snd_stop_nosedive(void)
{
	if (g_SndNosediveAge240 != -1) {
		g_SndNosediveAge240 = g_SndNosediveDuration240 + 1;
	}
}

void snd_tick_nosedive(void)
{
	f32 percentage;

	if (g_SndNosediveAge240 != -1) {
		g_SndNosediveAge240 += g_Vars.lvupdate240;

		percentage = (f32)g_SndNosediveAge240 / (f32)g_SndNosediveDuration240;

		if (percentage < 1.0f) { // less than 100% complete
			percentage += 0.44f;

			if (lv_is_paused()) {
				// Fade out volume during pause instead of stopping abruptly
				if (g_SndNosediveVolume > 0) {
					g_SndNosediveVolume -= g_Vars.diffframe240 * PALUP(80);

					if (g_SndNosediveVolume < 0) {
						g_SndNosediveVolume = 0;
					}
				}

				if (g_SndNosediveVolume) {
					snd_adjust(&g_SndNosediveHandle, 0, g_SndNosediveVolume, AL_PAN_CENTER, -1, percentage, 0, -1, 1);
				} else if (g_SndNosediveHandle != NULL) {
					sndp_stop_sound(g_SndNosediveHandle);
					g_SndNosediveHandle = NULL;
				}
			} else {
				// Not paused
				if (g_SndNosediveHandle == NULL) {
					snd_start(var80095200, SFXNUM_0608_NOSEDIVE, &g_SndNosediveHandle, -1, -1, -1, -1, -1);
				}

				// Fade in over about 2 seconds
				if (g_SndNosediveVolume < 20000) {
					g_SndNosediveVolume += g_Vars.diffframe240 * PALUP(40);

					if (g_SndNosediveVolume > 20000) {
						g_SndNosediveVolume = 20000;
					}
				}

				snd_adjust(&g_SndNosediveHandle, 0, g_SndNosediveVolume, AL_PAN_CENTER, -1, percentage, 0, -1, 1);
			}
		} else {
			// Reached the configured fade out point
			if (g_SndNosediveVolume > 0) {
				g_SndNosediveVolume -= g_Vars.diffframe240 * PALUP(80);

				if (g_SndNosediveVolume < 0) {
					g_SndNosediveVolume = 0;
				}
			}

			if (g_SndNosediveVolume) {
				snd_adjust(&g_SndNosediveHandle, 0, g_SndNosediveVolume, AL_PAN_CENTER, -1, -1, 0, -1, 1);
			} else if (g_SndNosediveHandle != NULL) {
				sndp_stop_sound(g_SndNosediveHandle);
				g_SndNosediveHandle = NULL;
			}
		}
	}
}

void snd_play_ufo(s32 seconds)
{
	g_SndUfoDuration240 = seconds * TICKS(240);
	g_SndUfoAge240 = 0;
	g_SndUfoVolume = 0;
	g_SndUfoHandle = NULL;
}

void snd_stop_ufo(void)
{
	if (g_SndUfoAge240 != -1) {
		g_SndUfoAge240 = g_SndUfoDuration240 + 1;
	}
}

void snd_tick_ufo(void)
{
	f32 percentage;

	if (g_SndUfoAge240 != -1) {
		g_SndUfoAge240 += g_Vars.lvupdate240;

		percentage = (f32)g_SndUfoAge240 / (f32)g_SndUfoDuration240;

		if (percentage < 1.0f) { // less than 100% complete
			if (percentage < 0.65f) {
				percentage = percentage / 0.65f * 0.3f + 0.7f;
			} else {
				percentage = (percentage - 0.65f) / 0.35f * 0.8f + 1.0f;
			}

			if (lv_is_paused()) {
				// Fade out volume during pause instead of stopping abruptly
				if (g_SndUfoVolume > 0) {
					g_SndUfoVolume -= g_Vars.diffframe240 * PALUP(120);

					if (g_SndUfoVolume < 0) {
						g_SndUfoVolume = 0;
					}
				}

				if (g_SndUfoVolume) {
					snd_adjust(&g_SndUfoHandle, 0, g_SndUfoVolume, AL_PAN_CENTER, -1, percentage, 0, -1, 1);
				} else if (g_SndUfoHandle != NULL) {
					sndp_stop_sound(g_SndUfoHandle);
					g_SndUfoHandle = NULL;
				}
			} else {
				// Not paused
				if (g_SndUfoHandle == NULL) {
					snd_start(var80095200, SFXNUM_0609_UFOHUM, &g_SndUfoHandle, -1, -1, -1, -1, -1);
				}

				// Fade in over about 2.4 seconds
				if (g_SndUfoVolume < AL_VOL_FULL) {
					g_SndUfoVolume += g_Vars.diffframe240 * PALUP(40);

					if (g_SndUfoVolume > AL_VOL_FULL) {
						g_SndUfoVolume = AL_VOL_FULL;
					}
				}

				snd_adjust(&g_SndUfoHandle, 0, g_SndUfoVolume, AL_PAN_CENTER, -1, percentage, 0, -1, 1);
			}
		} else {
			// Reached the configured fade out point
			if (g_SndUfoVolume > 0) {
				g_SndUfoVolume -= g_Vars.diffframe240 * PALUP(120);

				if (g_SndUfoVolume < 0) {
					g_SndUfoVolume = 0;
				}
			}

			if (g_SndUfoVolume) {
				snd_adjust(&g_SndUfoHandle, 0, g_SndUfoVolume, AL_PAN_CENTER, -1, -1, 0, -1, 1);
			} else if (g_SndUfoHandle != NULL) {
				sndp_stop_sound(g_SndUfoHandle);
				g_SndUfoHandle = NULL;
			}
		}
	}
}
