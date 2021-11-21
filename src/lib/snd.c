#include <ultra64.h>
#include "n_libaudio.h"
#include "constants.h"
#include "game/file.h"
#include "game/lv.h"
#include "game/music.h"
#include "bss.h"
#include "lib/rzip.h"
#include "lib/args.h"
#include "lib/dma.h"
#include "lib/snd.h"
#include "lib/memp.h"
#include "lib/rng.h"
#include "lib/lib_2fc60.h"
#include "lib/lib_317f0.h"
#include "lib/mp3.h"
#include "lib/lib_39c80.h"
#include "data.h"
#include "types.h"

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
struct sndcache g_SndCache;

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

u16 g_SfxVolume = 32767;
s32 g_SoundMode = (VERSION >= VERSION_NTSC_1_0 ? SOUNDMODE_STEREO : SOUNDMODE_SURROUND);
bool g_SndMp3Enabled = false;

#if VERSION >= VERSION_NTSC_1_0
s32 var8005ddd4 = 0;
s32 var8005ddd8 = 0;
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
#if VERSION >= VERSION_NTSC_1_0
	AUDIOCONFIG_60,
	AUDIOCONFIG_61,
	AUDIOCONFIG_62,
	AUDIOCONFIG_63
#else
	AUDIOCONFIG_60
#endif
};

// 3e04
struct audiorussmapping g_AudioRussMappings[] = {
	/*0x0000*/ { 0x85ba, AUDIOCONFIG_59 },
	/*0x0001*/ { 0x85a5, AUDIOCONFIG_15 },
	/*0x0002*/ { 0x85a6, AUDIOCONFIG_15 },
	/*0x0003*/ { 0x80bb, AUDIOCONFIG_14 },
	/*0x0004*/ { 0x80bc, AUDIOCONFIG_14 },
	/*0x0005*/ { 0x8007, AUDIOCONFIG_14 },
	/*0x0006*/ { 0x8007, AUDIOCONFIG_14 },
	/*0x0007*/ { 0x80be, AUDIOCONFIG_14 },
	/*0x0008*/ { 0x80bf, AUDIOCONFIG_14 },
	/*0x0009*/ { 0x80bf, AUDIOCONFIG_14 },
	/*0x000a*/ { 0x80c0, AUDIOCONFIG_14 },
	/*0x000b*/ { 0x8007, AUDIOCONFIG_14 },
	/*0x000c*/ { 0x80c2, AUDIOCONFIG_14 },
	/*0x000d*/ { 0x80c3, AUDIOCONFIG_14 },
	/*0x000e*/ { 0x80c4, AUDIOCONFIG_14 },
	/*0x000f*/ { 0x80c5, AUDIOCONFIG_14 },
	/*0x0010*/ { 0x8007, AUDIOCONFIG_14 },
	/*0x0011*/ { 0x80c7, AUDIOCONFIG_14 },
	/*0x0012*/ { 0x80c8, AUDIOCONFIG_14 },
	/*0x0013*/ { 0x80c9, AUDIOCONFIG_14 },
	/*0x0014*/ { 0x80ca, AUDIOCONFIG_15 },
	/*0x0015*/ { 0x80cb, AUDIOCONFIG_15 },
	/*0x0016*/ { 0x80cc, AUDIOCONFIG_15 },
	/*0x0017*/ { 0x8007, AUDIOCONFIG_15 },
	/*0x0018*/ { 0x8007, AUDIOCONFIG_15 },
	/*0x0019*/ { 0x8007, AUDIOCONFIG_15 },
	/*0x001a*/ { 0x80d2, AUDIOCONFIG_15 },
	/*0x001b*/ { 0x80d3, AUDIOCONFIG_15 },
	/*0x001c*/ { 0x8007, AUDIOCONFIG_15 },
	/*0x001d*/ { 0x80c6, AUDIOCONFIG_14 },
	/*0x001e*/ { 0x80d6, AUDIOCONFIG_15 },
	/*0x001f*/ { 0x80d7, AUDIOCONFIG_15 },
	/*0x0020*/ { 0x80d8, AUDIOCONFIG_15 },
	/*0x0021*/ { 0x80db, AUDIOCONFIG_14 },
	/*0x0022*/ { 0x80da, AUDIOCONFIG_14 },
	/*0x0023*/ { 0x80bf, AUDIOCONFIG_14 },
	/*0x0024*/ { 0x80bf, AUDIOCONFIG_14 },
	/*0x0025*/ { 0x80de, AUDIOCONFIG_14 },
	/*0x0026*/ { 0x80e1, AUDIOCONFIG_15 },
	/*0x0027*/ { 0x80e2, AUDIOCONFIG_15 },
	/*0x0028*/ { 0x977a, AUDIOCONFIG_60 }, // Carrington: "Hello Joanna"
	/*0x0029*/ { 0x97b0, AUDIOCONFIG_60 }, // Carrington: "Joanna, it's good to see you"
	/*0x002a*/ { 0x97b1, AUDIOCONFIG_60 }, // Carrington: "Good day to you, Jo"
	/*0x002b*/ { 0x977c, AUDIOCONFIG_60 }, // Female: "Hi there"
	/*0x002c*/ { 0x9786, AUDIOCONFIG_60 }, // Grimshaw: "Welcome to hacker central"
	/*0x002d*/ { 0x9787, AUDIOCONFIG_60 }, // Grimshaw: "Hi there"
	/*0x002e*/ { 0x9788, AUDIOCONFIG_60 }, // Grimshaw: "Um, er, hi"
	/*0x002f*/ { 0x978c, AUDIOCONFIG_60 }, // Holo girl: "Hi. What can I do for you?"
	/*0x0030*/ { 0x9794, AUDIOCONFIG_60 }, // Hangar guy: "What do you want?"
	/*0x0031*/ { 0x9784, AUDIOCONFIG_60 }, // Foster: "Ah, our star agent"
	/*0x0032*/ { 0x978e, AUDIOCONFIG_60 }, // Male: "Hey there"
	/*0x0033*/ { 0x978f, AUDIOCONFIG_60 }, // Male: "Hi"
	/*0x0034*/ { 0x9790, AUDIOCONFIG_60 }, // Male "How's it going?"
	/*0x0035*/ { 0x977e, AUDIOCONFIG_60 }, // Female: "Hello"
	/*0x0036*/ { 0x977f, AUDIOCONFIG_60 }, // Holo girl: "Hi Jo"
	/*0x0037*/ { 0x9780, AUDIOCONFIG_60 }, // Holo girl: "How's it going?"
	/*0x0038*/ { 0x802e, AUDIOCONFIG_32 },
	/*0x0039*/ { 0x8037, AUDIOCONFIG_35 },
	/*0x003a*/ { 0x8037, AUDIOCONFIG_35 },
	/*0x003b*/ { 0x806a, AUDIOCONFIG_33 },
	/*0x003c*/ { 0x8037, AUDIOCONFIG_35 },
	/*0x003d*/ { 0x8037, AUDIOCONFIG_35 },
	/*0x003e*/ { 0x8037, AUDIOCONFIG_35 },
	/*0x003f*/ { 0x806d, AUDIOCONFIG_33 },
	/*0x0040*/ { 0x806e, AUDIOCONFIG_33 },
	/*0x0041*/ { 0x8037, AUDIOCONFIG_35 },
	/*0x0042*/ { 0x8037, AUDIOCONFIG_35 },
	/*0x0043*/ { 0x8070, AUDIOCONFIG_33 },
	/*0x0044*/ { 0x8071, AUDIOCONFIG_33 },
	/*0x0045*/ { 0x8037, AUDIOCONFIG_35 },
	/*0x0046*/ { 0x8037, AUDIOCONFIG_35 },
	/*0x0047*/ { 0x8037, AUDIOCONFIG_35 },
	/*0x0048*/ { 0x8037, AUDIOCONFIG_35 },
	/*0x0049*/ { 0x8075, AUDIOCONFIG_33 },
	/*0x004a*/ { 0x8037, AUDIOCONFIG_35 },
	/*0x004b*/ { 0x8037, AUDIOCONFIG_35 },
	/*0x004c*/ { 0x8079, AUDIOCONFIG_31 },
	/*0x004d*/ { 0x8066, AUDIOCONFIG_31 },
	/*0x004e*/ { 0x8037, AUDIOCONFIG_35 },
	/*0x004f*/ { 0x8032, AUDIOCONFIG_31 },
	/*0x0050*/ { 0x8037, AUDIOCONFIG_35 },
	/*0x0051*/ { 0x807a, AUDIOCONFIG_35 },
	/*0x0052*/ { 0x8059, AUDIOCONFIG_31 },
	/*0x0053*/ { 0x8001, AUDIOCONFIG_35 },
	/*0x0054*/ { 0x847e, AUDIOCONFIG_32 },
	/*0x0055*/ { 0x847d, AUDIOCONFIG_33 },
	/*0x0056*/ { 0x84f1, AUDIOCONFIG_32 },
	/*0x0057*/ { 0x84f2, AUDIOCONFIG_32 },
	/*0x0058*/ { 0x84f3, AUDIOCONFIG_32 },
	/*0x0059*/ { 0x84f4, AUDIOCONFIG_33 },
	/*0x005a*/ { 0x84f6, AUDIOCONFIG_33 },
	/*0x005b*/ { 0x8506, AUDIOCONFIG_31 },
	/*0x005c*/ { 0x84fd, AUDIOCONFIG_33 },
	/*0x005d*/ { 0x8504, AUDIOCONFIG_33 },
	/*0x005e*/ { 0x84fe, AUDIOCONFIG_33 },
	/*0x005f*/ { 0x8503, AUDIOCONFIG_33 },
	/*0x0060*/ { 0x8500, AUDIOCONFIG_32 },
	/*0x0061*/ { 0x8501, AUDIOCONFIG_32 },
	/*0x0062*/ { 0x8502, AUDIOCONFIG_32 },
	/*0x0063*/ { 0x85ca, AUDIOCONFIG_31 },
	/*0x0064*/ { 0x85cb, AUDIOCONFIG_31 },
	/*0x0065*/ { 0x85d2, AUDIOCONFIG_31 },
	/*0x0066*/ { 0x8074, AUDIOCONFIG_33 },
	/*0x0067*/ { 0x85eb, AUDIOCONFIG_35 },
	/*0x0068*/ { 0x85ec, AUDIOCONFIG_35 },
	/*0x0069*/ { 0x85ed, AUDIOCONFIG_31 },
	/*0x006a*/ { 0x85ee, AUDIOCONFIG_31 },
	/*0x006b*/ { 0x85ef, AUDIOCONFIG_33 },
	/*0x006c*/ { 0x85f0, AUDIOCONFIG_33 },
	/*0x006d*/ { 0x85f1, AUDIOCONFIG_33 },
	/*0x006e*/ { 0x85f2, AUDIOCONFIG_33 },
	/*0x006f*/ { 0x85f3, AUDIOCONFIG_33 },
	/*0x0070*/ { 0x85f4, AUDIOCONFIG_33 },
	/*0x0071*/ { 0x8508, AUDIOCONFIG_31 },
	/*0x0072*/ { 0x850a, AUDIOCONFIG_31 },
	/*0x0073*/ { 0x8076, AUDIOCONFIG_33 },
	/*0x0074*/ { 0x85f5, AUDIOCONFIG_30 },
	/*0x0075*/ { 0x8509, AUDIOCONFIG_33 },
	/*0x0076*/ { 0x8045, AUDIOCONFIG_45 },
	/*0x0077*/ { 0x8046, AUDIOCONFIG_45 },
	/*0x0078*/ { 0x8047, AUDIOCONFIG_25 },
	/*0x0079*/ { 0x8048, AUDIOCONFIG_45 },
	/*0x007a*/ { 0x80f0, AUDIOCONFIG_45 },
	/*0x007b*/ { 0x80ef, AUDIOCONFIG_45 },
	/*0x007c*/ { 0x8049, AUDIOCONFIG_45 },
	/*0x007d*/ { 0x804a, AUDIOCONFIG_45 },
	/*0x007e*/ { 0x804b, AUDIOCONFIG_45 },
	/*0x007f*/ { 0x80d9, AUDIOCONFIG_45 },
	/*0x0080*/ { 0x804c, AUDIOCONFIG_45 },
	/*0x0081*/ { 0x80e7, AUDIOCONFIG_45 },
	/*0x0082*/ { 0x80e6, AUDIOCONFIG_45 },
	/*0x0083*/ { 0x80e0, AUDIOCONFIG_45 },
	/*0x0084*/ { 0x80dc, AUDIOCONFIG_45 },
	/*0x0085*/ { 0x80b9, AUDIOCONFIG_45 },
	/*0x0086*/ { 0x80d4, AUDIOCONFIG_45 },
	/*0x0087*/ { 0x80d0, AUDIOCONFIG_45 },
	/*0x0088*/ { 0x80d1, AUDIOCONFIG_45 },
	/*0x0089*/ { 0x8078, AUDIOCONFIG_45 },
	/*0x008a*/ { 0x80dd, AUDIOCONFIG_45 },
	/*0x008b*/ { 0x8003, AUDIOCONFIG_45 },
	/*0x008c*/ { 0x802d, AUDIOCONFIG_21 },
	/*0x008d*/ { 0x807b, AUDIOCONFIG_21 },
	/*0x008e*/ { 0x807c, AUDIOCONFIG_21 },
	/*0x008f*/ { 0x807d, AUDIOCONFIG_21 },
	/*0x0090*/ { 0x807e, AUDIOCONFIG_21 },
	/*0x0091*/ { 0x807f, AUDIOCONFIG_21 },
	/*0x0092*/ { 0x8080, AUDIOCONFIG_21 },
	/*0x0093*/ { 0x8081, AUDIOCONFIG_21 },
	/*0x0094*/ { 0x8082, AUDIOCONFIG_21 },
	/*0x0095*/ { 0x8083, AUDIOCONFIG_21 },
	/*0x0096*/ { 0x8084, AUDIOCONFIG_21 },
	/*0x0097*/ { 0x8085, AUDIOCONFIG_21 },
	/*0x0098*/ { 0x80b4, AUDIOCONFIG_18 },
	/*0x0099*/ { 0x80b5, AUDIOCONFIG_18 },
	/*0x009a*/ { 0x80b6, AUDIOCONFIG_17 },
	/*0x009b*/ { 0x80a9, AUDIOCONFIG_18 },
	/*0x009c*/ { 0x80aa, AUDIOCONFIG_18 },
	/*0x009d*/ { 0x80ab, AUDIOCONFIG_17 },
	/*0x009e*/ { 0x80ac, AUDIOCONFIG_18 },
	/*0x009f*/ { 0x80ad, AUDIOCONFIG_18 },
	/*0x00a0*/ { 0x80ae, AUDIOCONFIG_17 },
	/*0x00a1*/ { 0x80b1, AUDIOCONFIG_18 },
	/*0x00a2*/ { 0x80b2, AUDIOCONFIG_18 },
	/*0x00a3*/ { 0x80b3, AUDIOCONFIG_18 },
	/*0x00a4*/ { 0x818a, AUDIOCONFIG_19 },
	/*0x00a5*/ { VERSION >= VERSION_NTSC_1_0 ? 0xefdd : 0x8190, AUDIOCONFIG_19 },
	/*0x00a6*/ { 0x805f, AUDIOCONFIG_32 },
	/*0x00a7*/ { 0x8060, AUDIOCONFIG_32 },
	/*0x00a8*/ { 0x8061, AUDIOCONFIG_32 },
	/*0x00a9*/ { 0x8004, AUDIOCONFIG_32 },
	/*0x00aa*/ { 0x80f1, AUDIOCONFIG_32 },
	/*0x00ab*/ { 0x80f3, AUDIOCONFIG_32 },
	/*0x00ac*/ { 0x8055, AUDIOCONFIG_16 },
	/*0x00ad*/ { 0x8056, AUDIOCONFIG_16 },
	/*0x00ae*/ { 0x8057, AUDIOCONFIG_16 },
	/*0x00af*/ { 0x85f7, AUDIOCONFIG_52 },
	/*0x00b0*/ { 0x8127, AUDIOCONFIG_29 },
	/*0x00b1*/ { 0x8128, AUDIOCONFIG_29 },
	/*0x00b2*/ { 0x8129, AUDIOCONFIG_29 },
	/*0x00b3*/ { 0x812a, AUDIOCONFIG_29 },
	/*0x00b4*/ { 0x812b, AUDIOCONFIG_29 },
	/*0x00b5*/ { 0x812c, AUDIOCONFIG_29 },
	/*0x00b6*/ { 0x812d, AUDIOCONFIG_50 },
	/*0x00b7*/ { 0x812e, AUDIOCONFIG_50 },
	/*0x00b8*/ { 0x8138, AUDIOCONFIG_50 },
	/*0x00b9*/ { 0x8138, AUDIOCONFIG_28 },
	/*0x00ba*/ { 0x812f, AUDIOCONFIG_51 },
	/*0x00bb*/ { 0x8151, AUDIOCONFIG_51 },
	/*0x00bc*/ { 0x8154, AUDIOCONFIG_51 },
	/*0x00bd*/ { 0x8157, AUDIOCONFIG_51 },
	/*0x00be*/ { 0x815a, AUDIOCONFIG_51 },
	/*0x00bf*/ { 0x8132, AUDIOCONFIG_51 },
	/*0x00c0*/ { 0x8139, AUDIOCONFIG_51 },
	/*0x00c1*/ { 0x813f, AUDIOCONFIG_51 },
	/*0x00c2*/ { 0x8145, AUDIOCONFIG_51 },
	/*0x00c3*/ { 0x814b, AUDIOCONFIG_51 },
	/*0x00c4*/ { 0x8161, AUDIOCONFIG_04 },
	/*0x00c5*/ { 0x8162, AUDIOCONFIG_04 },
	/*0x00c6*/ { 0x8163, AUDIOCONFIG_04 },
	/*0x00c7*/ { 0x8164, AUDIOCONFIG_04 },
	/*0x00c8*/ { 0x8165, AUDIOCONFIG_04 },
	/*0x00c9*/ { 0x8166, AUDIOCONFIG_04 },
	/*0x00ca*/ { 0x8167, AUDIOCONFIG_04 },
	/*0x00cb*/ { 0x8168, AUDIOCONFIG_04 },
	/*0x00cc*/ { 0x8169, AUDIOCONFIG_04 },
	/*0x00cd*/ { 0x816a, AUDIOCONFIG_04 },
	/*0x00ce*/ { 0x816b, AUDIOCONFIG_04 },
	/*0x00cf*/ { 0x816c, AUDIOCONFIG_04 },
	/*0x00d0*/ { 0x816d, AUDIOCONFIG_04 },
	/*0x00d1*/ { 0x816e, AUDIOCONFIG_04 },
	/*0x00d2*/ { 0x816f, AUDIOCONFIG_04 },
	/*0x00d3*/ { 0x8170, AUDIOCONFIG_04 },
	/*0x00d4*/ { 0x8171, AUDIOCONFIG_04 },
	/*0x00d5*/ { 0x8172, AUDIOCONFIG_04 },
	/*0x00d6*/ { 0x8173, AUDIOCONFIG_04 },
	/*0x00d7*/ { 0x8174, AUDIOCONFIG_04 },
	/*0x00d8*/ { 0x8175, AUDIOCONFIG_04 },
	/*0x00d9*/ { 0x8176, AUDIOCONFIG_04 },
	/*0x00da*/ { 0x8177, AUDIOCONFIG_04 },
	/*0x00db*/ { 0x8178, AUDIOCONFIG_04 },
	/*0x00dc*/ { 0x8179, AUDIOCONFIG_04 },
	/*0x00dd*/ { 0x817a, AUDIOCONFIG_04 },
	/*0x00de*/ { 0x817b, AUDIOCONFIG_04 },
	/*0x00df*/ { 0x817c, AUDIOCONFIG_04 },
	/*0x00e0*/ { 0x817d, AUDIOCONFIG_04 },
	/*0x00e1*/ { 0x817e, AUDIOCONFIG_04 },
	/*0x00e2*/ { 0x817f, AUDIOCONFIG_04 },
	/*0x00e3*/ { 0x8180, AUDIOCONFIG_04 },
	/*0x00e4*/ { 0x804d, AUDIOCONFIG_04 },
	/*0x00e5*/ { 0x804e, AUDIOCONFIG_04 },
	/*0x00e6*/ { 0x85f8, AUDIOCONFIG_05 },
	/*0x00e7*/ { 0x85f9, AUDIOCONFIG_05 },
	/*0x00e8*/ { 0x85fa, AUDIOCONFIG_05 },
	/*0x00e9*/ { 0x85fb, AUDIOCONFIG_05 },
	/*0x00ea*/ { 0x85fc, AUDIOCONFIG_06 },
	/*0x00eb*/ { 0x85fd, AUDIOCONFIG_06 },
	/*0x00ec*/ { 0x85fe, AUDIOCONFIG_06 },
	/*0x00ed*/ { 0x85ff, AUDIOCONFIG_06 },
	/*0x00ee*/ { 0x8600, AUDIOCONFIG_04 },
	/*0x00ef*/ { 0x8601, AUDIOCONFIG_04 },
	/*0x00f0*/ { 0x8602, AUDIOCONFIG_04 },
	/*0x00f1*/ { 0x8603, AUDIOCONFIG_04 },
	/*0x00f2*/ { 0x8604, AUDIOCONFIG_04 },
	/*0x00f3*/ { 0x8605, AUDIOCONFIG_04 },
	/*0x00f4*/ { 0x8606, AUDIOCONFIG_04 },
	/*0x00f5*/ { 0x8606, AUDIOCONFIG_04 },
#if VERSION >= VERSION_NTSC_1_0
	/*0x00f6*/ { 0x81d9, AUDIOCONFIG_61 },
#endif
	/*0x00f7*/ { 0x8267, AUDIOCONFIG_02 },
	/*0x00f8*/ { 0x8268, AUDIOCONFIG_02 },
	/*0x00f9*/ { 0x8286, AUDIOCONFIG_02 },
	/*0x00fa*/ { 0x8288, AUDIOCONFIG_02 },
	/*0x00fb*/ { 0x8291, AUDIOCONFIG_02 },
	/*0x00fc*/ { 0x829f, AUDIOCONFIG_02 },
	/*0x00fd*/ { 0x82a1, AUDIOCONFIG_02 },
#if VERSION >= VERSION_NTSC_1_0
	/*0x00fe*/ { 0x8af9, AUDIOCONFIG_47 }, // Cass: "You've become quite an annoyance"
	/*0x00ff*/ { 0x8afa, AUDIOCONFIG_47 }, // Cass: "We meet again, girl"
	/*0x0100*/ { 0x8afb, AUDIOCONFIG_47 }, // Cass: "Good night, Miss Dark"
#else
	/*0x00fe*/ { 0x92f9, AUDIOCONFIG_47 }, // Cass: "You've become quite an annoyance"
	/*0x00ff*/ { 0x92fa, AUDIOCONFIG_47 }, // Cass: "We meet again, girl"
	/*0x0100*/ { 0x92fb, AUDIOCONFIG_47 }, // Cass: "Good night, Miss Dark"
#endif
	/*0x0101*/ { 0x92fc, AUDIOCONFIG_47 }, // Cass: "Get her!"
	/*0x0102*/ { 0x92fd, AUDIOCONFIG_47 }, // Cass: (laughing)
	/*0x0103*/ { 0x9285, AUDIOCONFIG_02 }, // Scientist: "Who the hell are you?"
	/*0x0104*/ { 0x9306, AUDIOCONFIG_48 }, // Programmer: "Yes, yes, I agree. Personality..."
	/*0x0105*/ { 0x9307, AUDIOCONFIG_48 }, // Programmer: "No. I can start the process..."
	/*0x0106*/ { 0x9308, AUDIOCONFIG_48 }, // Programmer: "I'll begin at once. Goodbye"
	/*0x0107*/ { 0x9309, AUDIOCONFIG_48 }, // Programmer: "Security, help me!"
	/*0x0108*/ { 0x930a, AUDIOCONFIG_48 }, // Programmer: "Help! Help!"
	/*0x0109*/ { 0x8435, AUDIOCONFIG_49 },
	/*0x010a*/ { 0x81b5, AUDIOCONFIG_07 },
	/*0x010b*/ { 0x81b6, AUDIOCONFIG_08 },
	/*0x010c*/ { 0x81b5, AUDIOCONFIG_09 },
	/*0x010d*/ { 0x81b6, AUDIOCONFIG_10 },
	/*0x010e*/ { 0x85f3, AUDIOCONFIG_11 },
	/*0x010f*/ { 0x81b5, AUDIOCONFIG_12 },
	/*0x0110*/ { 0x81b6, AUDIOCONFIG_13 },
	/*0x0111*/ { 0x81b7, AUDIOCONFIG_20 },
	/*0x0112*/ { 0x81b8, AUDIOCONFIG_20 },
	/*0x0113*/ { 0x81c7, AUDIOCONFIG_20 },
	/*0x0114*/ { 0x8037, AUDIOCONFIG_20 },
	/*0x0115*/ { 0x81b7, AUDIOCONFIG_56 },
	/*0x0116*/ { 0x81b9, AUDIOCONFIG_00 },
	/*0x0117*/ { 0x81ba, AUDIOCONFIG_00 },
	/*0x0118*/ { 0x81bb, AUDIOCONFIG_00 },
	/*0x0119*/ { 0x81cb, AUDIOCONFIG_36 },
	/*0x011a*/ { 0x81cb, AUDIOCONFIG_37 },
	/*0x011b*/ { 0x81cb, AUDIOCONFIG_38 },
#if VERSION >= VERSION_NTSC_1_0
	/*0x011c*/ { 0x81c6, AUDIOCONFIG_55 },
#else
	/*0x011c*/ { 0x81c6, AUDIOCONFIG_55 },
#endif
	/*0x011d*/ { 0x9278, AUDIOCONFIG_47 }, // "That's not how it goes"
	/*0x011e*/ { 0x9279, AUDIOCONFIG_47 }, // "Give it to me. You're doing it wrong"
	/*0x011f*/ { 0x927a, AUDIOCONFIG_47 }, // "Oh no, we're too late"
	/*0x0120*/ { 0x927b, AUDIOCONFIG_47 }, // "Yes it is"
	/*0x0121*/ { 0x927c, AUDIOCONFIG_47 }, // "Stop annoying me"
	/*0x0122*/ { 0x927d, AUDIOCONFIG_47 }, // "She's here!"
	/*0x0123*/ { 0x9277, AUDIOCONFIG_47 }, // "Will you just hurry up?"
	/*0x0124*/ { 0x82fd, AUDIOCONFIG_02 }, // "Holy..."
	/*0x0125*/ { 0x82fe, AUDIOCONFIG_02 }, // "What the hell?"
	/*0x0126*/ { 0x8300, AUDIOCONFIG_02 }, // "Oh my god"
	/*0x0127*/ { 0x8303, AUDIOCONFIG_02 }, // "Oh god I'm hit"
	/*0x0128*/ { 0x830a, AUDIOCONFIG_02 }, // "Oh my god"
#if VERSION >= VERSION_NTSC_1_0
	/*0x0129*/ { 0x8313, AUDIOCONFIG_62 }, // "Noooo!"
#endif
	/*0x012a*/ { 0x8314, AUDIOCONFIG_02 }, // "Oh god he's dead!"
	/*0x012b*/ { 0x832e, AUDIOCONFIG_02 }, // "Bloody stupid gun"
	/*0x012c*/ { 0x8330, AUDIOCONFIG_02 }, // "Damn it"
	/*0x012d*/ { 0x8333, AUDIOCONFIG_02 }, // "Damn, she's good"
	/*0x012e*/ { 0x8334, AUDIOCONFIG_02 }, // "Cover my ass"
#if VERSION >= VERSION_NTSC_1_0
	/*0x012f*/ { 0x834c, AUDIOCONFIG_62 }, // Death scream
#endif
	/*0x0130*/ { 0x83a3, AUDIOCONFIG_02 }, // Female: "Damn she's good"
	/*0x0131*/ { 0x83b9, AUDIOCONFIG_02 }, // Female: "My god"
	/*0x0132*/ { 0x83c7, AUDIOCONFIG_02 }, // "Geez, that hurt"
	/*0x0133*/ { 0x83cf, AUDIOCONFIG_02 }, // "Damn it, I'm taking fire"
	/*0x0134*/ { 0x83d2, AUDIOCONFIG_02 }, // "God damn it"
	/*0x0135*/ { 0x83d4, AUDIOCONFIG_02 }, // "Holy moley"
	/*0x0136*/ { 0x83f3, AUDIOCONFIG_02 }, // "Damn, missed again"
	/*0x0137*/ { 0x83f5, AUDIOCONFIG_02 }, // "Damn"
	/*0x0138*/ { 0x83f6, AUDIOCONFIG_02 }, // "Hell, she's good"
	/*0x0139*/ { 0x8400, AUDIOCONFIG_02 }, // "Let's get the hell out of here"
#if VERSION >= VERSION_NTSC_1_0
	/*0x013a*/ { 0x8411, AUDIOCONFIG_62 }, // "Noooo!"
#endif
	/*0x013b*/ { 0x8413, AUDIOCONFIG_02 }, // "Shoot, damn it"
	/*0x013c*/ { 0x8414, AUDIOCONFIG_02 }, // "Oh god, I'm dying"
	/*0x013d*/ { 0x8422, AUDIOCONFIG_02 }, // "God, run!"
	/*0x013e*/ { 0x8432, AUDIOCONFIG_33 },
	/*0x013f*/ { 0x843c, AUDIOCONFIG_58 },
	/*0x0140*/ { 0x843d, AUDIOCONFIG_58 },
	/*0x0141*/ { 0x84ab, AUDIOCONFIG_58 },
	/*0x0142*/ { 0x843d, AUDIOCONFIG_58 },
	/*0x0143*/ { 0x81b7, AUDIOCONFIG_58 },
	/*0x0144*/ { 0x8477, AUDIOCONFIG_57 },
	/*0x0145*/ { 0x8478, AUDIOCONFIG_57 },
#if VERSION >= VERSION_NTSC_1_0
	/*0x0146*/ { 0x81c2, AUDIOCONFIG_54 },
	/*0x0147*/ { 0x8479, AUDIOCONFIG_54 },
	/*0x0148*/ { 0x81c3, AUDIOCONFIG_54 },
	/*0x0149*/ { 0x81c4, AUDIOCONFIG_54 },
#else
	/*0x0146*/ { 0x81c2, AUDIOCONFIG_55 },
	/*0x0147*/ { 0x8479, AUDIOCONFIG_55 },
	/*0x0148*/ { 0x81c3, AUDIOCONFIG_55 },
	/*0x0149*/ { 0x81c4, AUDIOCONFIG_55 },
#endif
	/*0x014a*/ { 0x8443, AUDIOCONFIG_02 }, // Civilian: "Oh my god"
	/*0x014b*/ { 0x844e, AUDIOCONFIG_02 }, // "What the hell was that?"
#if VERSION >= VERSION_NTSC_1_0
	/*0x014c*/ { 0x843c, AUDIOCONFIG_63 },
	/*0x014d*/ { 0x847c, AUDIOCONFIG_63 },
	/*0x014e*/ { 0x843d, AUDIOCONFIG_63 },
#endif
	/*0x014f*/ { 0xf2ad, AUDIOCONFIG_01 }, // "Joanna, this is Jonathan. You're in grave danger"
	/*0x0150*/ { 0xf2ae, AUDIOCONFIG_01 }, // "They've flooded the area with nerge gas"
	/*0x0151*/ { 0xf2af, AUDIOCONFIG_01 }, // "Get our friend to the containment lab. There's a hiding place there"
	/*0x0152*/ { 0xd2b0, AUDIOCONFIG_01 }, // "I'll contact you when you get there. Good luck"
	/*0x0153*/ { 0xf2b1, AUDIOCONFIG_01 }, // "Good work Jo. We need to meet up. They're getting suspicious of me"
	/*0x0154*/ { 0xd2b2, AUDIOCONFIG_01 }, // "Use the maintenance hatch I've opened in one of the containment labs. Hurry"
	/*0x0155*/ { 0x92b8, AUDIOCONFIG_02 }, // "Damn it Joanna, cover me!"
	/*0x0156*/ { 0x9b30, AUDIOCONFIG_02 }, // "Oh my god, a gun?!"
	/*0x0157*/ { 0x9b27, AUDIOCONFIG_47 }, // "So you got here at last"
	/*0x0158*/ { 0x9b28, AUDIOCONFIG_47 }, // "Hey, you're not, uh, security alert!"
	/*0x0159*/ { 0x9b29, AUDIOCONFIG_47 }, // "No guns allowed in here. Put your weapon away"
	/*0x015a*/ { 0x9b2a, AUDIOCONFIG_47 }, // "I won't tell you again. Lose the weapon"
	/*0x015b*/ { 0x9b2b, AUDIOCONFIG_47 }, // "Right. I'm calling security"
	/*0x015c*/ { 0x9b2c, AUDIOCONFIG_47 }, // "Everyone's been waiting for you"
	/*0x015d*/ { 0x9a9d, AUDIOCONFIG_60 }, // "How's things?"
	/*0x015e*/ { 0x9a9e, AUDIOCONFIG_60 }, // "Hey there"
	/*0x015f*/ { 0x9a9f, AUDIOCONFIG_60 }, // "Hi. How are you?"
	/*0x0160*/ { 0x8037, AUDIOCONFIG_04 },
	/*0x0161*/ { 0x9271, AUDIOCONFIG_60 }, // Female: "Good afternoon"
	/*0x0162*/ { 0x9275, AUDIOCONFIG_02 }, // Female: "Oh my god!"
	/*0x0163*/ { 0x9acc, AUDIOCONFIG_60 }, // "Hi there"
	/*0x0164*/ { 0x9acd, AUDIOCONFIG_60 }, // "How's things"
	/*0x0165*/ { 0x9ad4, AUDIOCONFIG_60 }, // "Hello"
	/*0x0166*/ { 0x9ad5, AUDIOCONFIG_60 }, // "Hey, what's up?"
	/*0x0167*/ { 0x84c8, AUDIOCONFIG_02 }, // "What the hell?"
	/*0x0168*/ { 0x84cd, AUDIOCONFIG_02 }, // "Geez"
	/*0x0169*/ { 0x84ad, AUDIOCONFIG_46 },
	/*0x016a*/ { 0x8507, AUDIOCONFIG_27 },
	/*0x016b*/ { 0x84ee, AUDIOCONFIG_16 },
	/*0x016c*/ { 0x84ef, AUDIOCONFIG_16 },
	/*0x016d*/ { 0x84f0, AUDIOCONFIG_16 },
	/*0x016e*/ { 0x92c8, AUDIOCONFIG_02 }, // President: "What the hell was that?"
	/*0x016f*/ { 0x92c9, AUDIOCONFIG_02 }, // Trent: "How the hell did you get on board?"
	/*0x0170*/ { 0xb3a0, AUDIOCONFIG_01 }, // Carrington: "We're getting a positive reading. The internal comms hub is nearby"
	/*0x0171*/ { 0xb3a1, AUDIOCONFIG_01 }, // Carrington: "You're on the same floor as Cassandra's office"
	/*0x0172*/ { 0xd3a3, AUDIOCONFIG_01 }, // Carrington: "The basement elevator must be around there somewhere"
	/*0x0173*/ { 0xd3a4, AUDIOCONFIG_01 }, // Carrington: "That's the highest security sector. Dr Caroll has got to be nearby"
	/*0x0174*/ { 0xd3a6, AUDIOCONFIG_01 }, // Grimshaw: "Reprogram the cleaning bot. It'll give you a way in"
	/*0x0175*/ { 0xd3a7, AUDIOCONFIG_01 }, // Carrington: "Get out Jo! The levels are too high. Use the camspy"
	/*0x0176*/ { 0xd3a8, AUDIOCONFIG_01 }, // Carrington: "They've locked down the ground floor. Get to the elevator"
	/*0x0177*/ { 0xd3a9, AUDIOCONFIG_01 }, // Carrington: "That copter needs to be taken out of the jumpship will get shut down"
	/*0x0178*/ { 0xd3ab, AUDIOCONFIG_01 }, // Carrington: "Don't keep the jumpship waiting. Get back to the landing pad"
	/*0x0179*/ { 0xd3b0, AUDIOCONFIG_01 }, // Carrington: "The only place we could secure the equipment was a storm drain"
	/*0x017a*/ { 0xd3b2, AUDIOCONFIG_01 }, // Grimshaw: "Reprogram that taxi. It's a mark 2 and should be compatible"
	/*0x017b*/ { 0xd3b3, AUDIOCONFIG_01 }, // Carrington: The carpark lift is your only point of ingress"
	/*0x017c*/ { 0xb3b6, AUDIOCONFIG_01 }, // Grimshaw: "The safe's heavily encrypted. The decoder's going to take a little longer"
	/*0x017d*/ { 0xd3b8, AUDIOCONFIG_01 }, // Carrington: "The air intercept radar is controlled from that bunker"
	/*0x017e*/ { 0xd3ba, AUDIOCONFIG_01 }, // Carrington: "The hangar lift is the other side of that huge door"
	/*0x017f*/ { 0xd3bb, AUDIOCONFIG_01 }, // Jon: "Careful with that trigger finger, Agent Dark. You're closing in on my position"
	/*0x0180*/ { 0xb3bd, AUDIOCONFIG_01 }, // Carrington: "The temperature's dropping. You must be close to the cryo room"
	/*0x0181*/ { 0xd3bf, AUDIOCONFIG_01 }, // Carrington: "There he is Jo. Hurry or you'll be too late"
	/*0x0182*/ { 0xb3c4, AUDIOCONFIG_01 }, // Carrington: "Now's your chance. Grab the stewardess's bag and get her uniform"
	/*0x0183*/ { 0xb3c5, AUDIOCONFIG_01 }, // Carrington: "Use that case to conceal your equipment"
	/*0x0184*/ { 0xb3c6, AUDIOCONFIG_01 }, // Carrington: "The case will get stopped unless you do something"
	/*0x0185*/ { 0xb3c9, AUDIOCONFIG_01 }, // Carrington: "The president's room is on this level, Joanna"
	/*0x0186*/ { 0xb3ca, AUDIOCONFIG_01 }, // Carrington: "Something's wrong. You have to get to the cockpit"
	/*0x0187*/ { 0x8594, AUDIOCONFIG_04 }, // Footstep
	/*0x0188*/ { 0x8595, AUDIOCONFIG_04 }, // Footstep
	/*0x0189*/ { 0x8596, AUDIOCONFIG_04 }, // Footstep
	/*0x018a*/ { 0x8597, AUDIOCONFIG_04 }, // Footstep
	/*0x018b*/ { 0x8598, AUDIOCONFIG_04 }, // Footstep
	/*0x018c*/ { 0x8599, AUDIOCONFIG_04 }, // Footstep
	/*0x018d*/ { 0x859a, AUDIOCONFIG_04 }, // Footstep
	/*0x018e*/ { 0x859b, AUDIOCONFIG_04 }, // Footstep
	/*0x018f*/ { 0x85a0, AUDIOCONFIG_04 }, // Footstep
	/*0x0190*/ { 0x85a1, AUDIOCONFIG_04 }, // Footstep
	/*0x0191*/ { 0x85a2, AUDIOCONFIG_04 }, // Footstep
	/*0x0192*/ { 0x85a3, AUDIOCONFIG_04 }, // Footstep
	/*0x0193*/ { 0xf310, AUDIOCONFIG_01 }, // Carrington: "Joanna. We're under attack"
	/*0x0194*/ { 0xd311, AUDIOCONFIG_01 }, // Carrington: "Get the guns back online. Hurry"
	/*0x0195*/ { 0xf312, AUDIOCONFIG_01 }, // Carrington: "The Skedar have taken hostages"
	/*0x0196*/ { 0xd313, AUDIOCONFIG_01 }, // Carrington: "Get up to the offices and save them"
	/*0x0197*/ { 0xf314, AUDIOCONFIG_01 }, // Carrington: "They're using a new form of shield technology"
	/*0x0198*/ { 0xd315, AUDIOCONFIG_01 }, // Carrington: "Foster was working on a new weapon which may be useful"
	/*0x0199*/ { 0xf316, AUDIOCONFIG_03 }, // Carrington: "Damn it, my office. If they get access..."
	/*0x019a*/ { 0xd317, AUDIOCONFIG_01 }, // Carrington: "Get there first, Jo and destroy the files"
	/*0x019b*/ { 0xf318, AUDIOCONFIG_01 }, // Carrington: "Things are desparate. They've planted a bomb"
	/*0x019c*/ { 0xd319, AUDIOCONFIG_01 }, // Carrington: "Find it and get it out of the building"
	/*0x019d*/ { 0xf31a, AUDIOCONFIG_01 }, // Carrington: "Well done Joanna. We're nearly clear"
	/*0x019e*/ { 0xd31b, AUDIOCONFIG_01 }, // Carrington: "The last dropship is waiting for you. Hurry"
	/*0x019f*/ { 0xf293, AUDIOCONFIG_01 }, // Grimshaw: "Joanna, it's Grimshaw. We've got hackers at..."
	/*0x01a0*/ { 0xf2df, AUDIOCONFIG_01 }, // Elvis: "We're outside, Joanna. Get the shields down and we can help you"
	/*0x01a1*/ { 0xf2e0, AUDIOCONFIG_01 }, // Elvis: "You've got to open the hanger doors so we can dock"
	/*0x01a2*/ { 0xd4ea, AUDIOCONFIG_01 }, // Carrington: "Stand back Joanna. We'll create your escape route"
	/*0x01a3*/ { VERSION >= VERSION_NTSC_1_0 ? 0x8d24 : 0x9524, AUDIOCONFIG_02 }, // Cass: "Get the hell out of my office"
	/*0x01a4*/ { 0x9d62, AUDIOCONFIG_47 }, // Elvis: "Joanna, what took you so long? Follow me. Let's get off this old tub"
	/*0x01a5*/ { 0x84aa, AUDIOCONFIG_43 },
	/*0x01a6*/ { 0x81cf, AUDIOCONFIG_41 },
	/*0x01a7*/ { 0x858f, AUDIOCONFIG_40 },
	/*0x01a8*/ { 0x80d5, AUDIOCONFIG_39 }, // Lift mechanical sound
	/*0x01a9*/ { 0x80ec, AUDIOCONFIG_39 }, // Lift mechanical sound
	/*0x01aa*/ { 0x80ed, AUDIOCONFIG_40 }, // Lift mechanical sound
	/*0x01ab*/ { 0x80d5, AUDIOCONFIG_41 }, // Lift mechanical sound
	/*0x01ac*/ { 0x80ec, AUDIOCONFIG_41 }, // Lift mechanical sound
	/*0x01ad*/ { 0x80ed, AUDIOCONFIG_42 }, // Lift mechanical sound
	/*0x01ae*/ { 0x80d5, AUDIOCONFIG_41 }, // Lift mechanical sound
	/*0x01af*/ { 0x80ec, AUDIOCONFIG_41 }, // Lift mechanical sound
	/*0x01b0*/ { 0x803a, AUDIOCONFIG_41 }, // Lift call
	/*0x01b1*/ { 0x84e8, AUDIOCONFIG_43 }, // Lift mechanical sound
	/*0x01b2*/ { 0x84e9, AUDIOCONFIG_43 }, // Lift mechanical sound
	/*0x01b3*/ { 0x80cd, AUDIOCONFIG_42 }, // Lift mechanical sound
	/*0x01b4*/ { 0x80ce, AUDIOCONFIG_42 }, // Lift mechanical sound
	/*0x01b5*/ { 0x8039, AUDIOCONFIG_42 }, // Lift mechanical sound
	/*0x01b6*/ { 0x80cd, AUDIOCONFIG_44 }, // Lift mechanical sound
	/*0x01b7*/ { 0x80db, AUDIOCONFIG_16 }, // Lift roller door
	/*0x01b8*/ { 0x80da, AUDIOCONFIG_16 }, // Lift roller door
	/*0x01b9*/ { 0xf41c, AUDIOCONFIG_02 }, // Joanna: "Oh my god"
	/*0x01ba*/ { 0xf434, AUDIOCONFIG_02 }, // Lab guy: "What the hell do you think you're doing? This is supposed..."
	/*0x01bb*/ { 0xf44f, AUDIOCONFIG_02 }, // President: "Damn it man. I say no and I mean no..."
	/*0x01bc*/ { 0x0000, AUDIOCONFIG_00 },
};

struct audioconfig g_AudioConfigs[] = {
	{ /* 0*/  200, 1000, 1200, -1, 100, -1,   0, 0 },
	{ /* 1*/  400, 2500, 3000, -1, 100, 48,   0, AUDIOCONFIGFLAG_20 },
	{ /* 2*/  400, 2500, 3000, -1, 100, -1,   0, AUDIOCONFIGFLAG_OFFENSIVE },
	{ /* 3*/  400, 2500, 3000, -1, 100, 48,   0, AUDIOCONFIGFLAG_OFFENSIVE | AUDIOCONFIGFLAG_20 },
	{ /* 4*/  200, 1000, 1200, -1, 100, -1,   0, 0 },
	{ /* 5*/  200, 1000, 1200, -1, 100, -1,   0, 0 },
	{ /* 6*/  200, 1000, 1200, -1, 100, -1,   0, 0 },
	{ /* 7*/ 1000, 3500, 4000, -1, 100, -1, 120, AUDIOCONFIGFLAG_01 | AUDIOCONFIGFLAG_08 },
	{ /* 8*/ 1000, 2500, 3000, -1, 100, -1,  30, AUDIOCONFIGFLAG_01 | AUDIOCONFIGFLAG_08 },
	{ /* 9*/ 1000, 3500, 4000, -1, 100, -1, 120, AUDIOCONFIGFLAG_01 | AUDIOCONFIGFLAG_08 },
	{ /*10*/ 1000, 2500, 3000, -1, 100, -1,  30, AUDIOCONFIGFLAG_01 | AUDIOCONFIGFLAG_08 },
	{ /*11*/ 1600, 3000, 3500, -1, 100, -1,   0, AUDIOCONFIGFLAG_01 | AUDIOCONFIGFLAG_08 },
	{ /*12*/  400, 1100, 1400, -1, 100, -1, 140, AUDIOCONFIGFLAG_01 | AUDIOCONFIGFLAG_08 },
	{ /*13*/  400, 1100, 1400, -1, 100, -1,   0, AUDIOCONFIGFLAG_01 | AUDIOCONFIGFLAG_08 },
	{ /*14*/  300, 1200, 1250, -1, 100, -1,   0, AUDIOCONFIGFLAG_01 },
	{ /*15*/  500, 1800, 1900, -1, 100, -1,   0, AUDIOCONFIGFLAG_01 },
	{ /*16*/ 1000, 2700, 2900, -1, 100, -1,   0, AUDIOCONFIGFLAG_01 },
	{ /*17*/ 1500, 3000, 4000, -1, 100, -1,   0, AUDIOCONFIGFLAG_01 },
	{ /*18*/ 2500, 4900, 5000, -1, 100, -1,   0, AUDIOCONFIGFLAG_01 },
	{ /*19*/ 5500, 5600, 5700, -1, 100, -1,   0, AUDIOCONFIGFLAG_01 | AUDIOCONFIGFLAG_20 },
	{ /*20*/   20,  400,  500, -1, 100, -1,   0, 0 },
	{ /*21*/  300, 1700, 2000, -1, 100, -1,   0, 0 },
	{ /*22*/  600, 3500, 5000, -1, 100, -1,   0, 0 },
	{ /*23*/  600, 3500, 5000, -1, 100, -1,   0, 0 },
	{ /*24*/  600, 3500, 5000, -1, 100, -1,   0, 0 },
	{ /*25*/  600, 2500, 3000, -1, 100, -1,   0, 0 },
	{ /*26*/ 1500, 4900, 5500, -1, 100, -1, 100, AUDIOCONFIGFLAG_01 },
	{ /*27*/ 5500, 5740, 5800, -1, 100, -1, 100, AUDIOCONFIGFLAG_01 },
	{ /*28*/  250, 1000, 1300,  2, 100, -1, 120, AUDIOCONFIGFLAG_01 },
	{ /*29*/  200, 2600, 3000, -1, 100, -1,   0, 0 },
	{ /*30*/  200,  750,  850, -1, 100, -1,   0, 0 },
	{ /*31*/  600, 2000, 3000, -1, 100, -1,   0, 0 },
	{ /*32*/  500, 1500, 1800, -1, 100, -1,   0, 0 },
	{ /*33*/  800, 2500, 3000, -1, 100, -1,   0, 0 },
	{ /*34*/  400, 1500, 2000, -1, 100, -1,   0, 0 },
	{ /*35*/ 1000, 3500, 5000, -1, 100, -1,   0, AUDIOCONFIGFLAG_01 },
	{ /*36*/   50,  225,  250, -1, 100, -1,   0, AUDIOCONFIGFLAG_01 },
	{ /*37*/   50,  225,  250, -1, 100, -1,   0, AUDIOCONFIGFLAG_01 },
	{ /*38*/ 2000, 2500, 2700, -1,  50, -1,   0, AUDIOCONFIGFLAG_01 | AUDIOCONFIGFLAG_08 },
	{ /*39*/  300, 1000, 1200, -1, 100, -1,   0, AUDIOCONFIGFLAG_01 },
	{ /*40*/  300, 1000, 1200, -1, 100, -1, 100, AUDIOCONFIGFLAG_01 },
	{ /*41*/  600, 1500, 1800, -1, 100, -1,   0, AUDIOCONFIGFLAG_01 },
	{ /*42*/  600, 1500, 1800, -1, 100, -1, 100, AUDIOCONFIGFLAG_01 },
	{ /*43*/  800, 2600, 3500, -1, 100, -1,   0, AUDIOCONFIGFLAG_01 },
	{ /*44*/  800, 2600, 3500, -1, 100, -1, 100, AUDIOCONFIGFLAG_01 },
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
	{ /*54*/  300, 1300, 1500, -1, 100, -1,   0, AUDIOCONFIGFLAG_01 },
#endif
	{ /*55*/  300, 1300, 1500, -1, 100, -1, 200, AUDIOCONFIGFLAG_01 },
	{ /*56*/  250,  600,  900, -1, 100, -1, 200, AUDIOCONFIGFLAG_01 },
	{ /*57*/   50,  180,  250, -1, 100, -1, 200, AUDIOCONFIGFLAG_01 },
	{ /*58*/  100,  400,  600, -1, 100, -1, 200, AUDIOCONFIGFLAG_01 },
	{ /*59*/  700, 1100, 1400, -1, 100, -1, 200, AUDIOCONFIGFLAG_01 },
	{ /*60*/  400, 2500, 3000, -1, 100, -1,   0, AUDIOCONFIGFLAG_04 },
#if VERSION >= VERSION_NTSC_1_0
	{ /*61*/  300,  900, 1100, -1, 100, -1,   0, 0 },
	{ /*62*/ 1000, 2500, 3000, -1, 100, -1,   0, AUDIOCONFIGFLAG_08 },
	{ /*63*/  400, 1000, 1200, -1, 100, -1,   0, 0 },
#endif
};

u32 var8005ecd8 = 0x00000000;
u32 var8005ecdc = 0x00000000;
u32 var8005ece0 = 0x00000000;
u32 var8005ece4 = 0x00000000;
u32 var8005ece8 = 0x00000000;
u32 var8005ecec = 0x00000000;
u32 var8005ecf0 = 0x00000000;
u32 var8005ecf4 = 0x00000000;

s16 var8005ecf8[] = {
	0x6665,
	0x5998,
	0x5fff,
	0x4ccc,
	0x5fff,
	0x2ccc,
	0x5998,
	0x6665,
	0x4ccc,
	0x5998,
	0x5998,
	0x5998,
	0x5fff,
	0x6665,
	0x6665,
	0x5fff,
	0x5998,
	0x6665,
	0x5fff,
	0x5fff,
	0x5fff,
	0x6665,
	0x5fff,
	0x5fff,
	0x5fff,
	0x7332,
	0x5fff,
	0x6665,
	0x5fff,
#if VERSION >= VERSION_NTSC_1_0
	0x5998,
	0x5998,
#else
	0x5fff,
	0x5fff,
#endif
	0x5332,
	0x5332,
	0x5fff,
	0x3332,
#if VERSION >= VERSION_NTSC_1_0
	0x4ccc,
#else
	0x3fff,
#endif
	0x5fff,
	0x4ccc,
	0x3fff,
	0x5fff,
	0x5fff,
	0x5fff,
	0x5fff,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x5fff,
	0x5fff,
	0x5fff,
	0x5fff,
	0x5fff,
	0x5fff,
	0x5fff,
	0x4ccc,
	0x5fff,
	0x5fff,
	0x5fff,
	0x5fff,
	0x5fff,
	0x5fff,
	0x5fff,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x7332,
	0x7332,
	0x7332,
	0x4ccc,
#if VERSION >= VERSION_NTSC_1_0
	0x3c28,
#else
	0x4ccc,
#endif
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x7332,
	0x7332,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x6665,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x4ccc,
	0x6ccb,
	0x5fff,
	0x5998,
	0x7998,
	0x5998,
	0x5998,
	0x6665,
	0x5fff,
	0x5fff,
	0x7332,
	0x7332,
	0x7332,
	0x7332,
	0x7332,
	0x4ccc,
	0x6665,
	0x6665,
	0x6665,
	0x4ccc,
	0x6ccb,
	0xffff,
	0x0000,
};

extern u8 _sfxctlSegmentRomStart;
extern u8 _sfxtblSegmentRomStart;
extern u8 _seqctlSegmentRomStart;
extern u8 _seqctlSegmentRomEnd;
extern u8 _seqtblSegmentRomStart;
extern u8 _sequencesSegmentRomStart;

bool sndIsPlayingMp3(void)
{
	return g_SndCurMp3.playing;
}

u16 snd0000e9dc(void)
{
#if VERSION >= VERSION_NTSC_1_0
	s32 result;

	if (func00033ec4(0) < 0x5000) {
		result = func00033ec4(0);
	} else {
		result = 0x5000;
	}

	return result;
#else
	return func00033ec4(0);
#endif
}

void sndSetSfxVolume(u16 volume)
{
	u8 i;

#if VERSION >= VERSION_NTSC_1_0
	if (volume > 0x5000) {
		volume = 0x5000;
	}
#endif

	for (i = 0; i < 9; i++) {
		func00033f44(i, volume);
	}

	g_SfxVolume = volume;
}

void snd0000ea80(u16 volume)
{
	u8 i;

#if VERSION >= VERSION_NTSC_1_0
	if (volume > 0x5000) {
		volume = 0x5000;
	}
#endif

	for (i = 0; i < 9; i++) {
		func00033f44(i, volume);
	}
}

void sndResetCurMp3(void)
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

#if VERSION >= VERSION_NTSC_1_0
void sndLoadSfxCtl(void)
{
	s32 i;
	u8 unalignedbuffer[256 + 16];
	u8 *buffer;
	ALBankFile *file;
	ALBank *bank;
	u32 romaddr;
	u32 size;

	g_ALSoundRomOffsets = NULL;
	buffer = (u8 *) ALIGN16((u32)unalignedbuffer);

	// Load the first 256 bytes of the ctl file.
	size = 256;
	dmaExec(buffer, (u32) &_sfxctlSegmentRomStart, size);

	// Get the ROM address of the first (and only) bank,
	// then load the first 256 bytes of the bank.
	file = (ALBankFile *) buffer;
	romaddr = (u32)&_sfxctlSegmentRomStart;
	romaddr += (u32)file->bankArray[0];
	dmaExec(buffer, romaddr, size);

	// Get the ROM address of the first (and only) instrument,
	// then load the first 256 bytes of the instrument.
	bank = (ALBank *) buffer;
	romaddr = (u32)&_sfxctlSegmentRomStart;
	romaddr += (u32)bank->instArray[0];
	dmaExec(buffer, romaddr, size);

	// Get the soundCount (spoiler: there's 1545+1).
	// The final one might be a null terminator?
	// Or accounting for 1-based indexing of soundnums.
	g_NumSounds = ((ALInstrument *)buffer)->soundCount + 1;

	// Calculate the size of the ALInstrument and load it. The pointer is then
	// shifted forward to point to the instrument's ALSound array. This leaks
	// some memory but this is initialisation code so it's not much of an issue.
	size = g_NumSounds * 4 + 20;
	size = ALIGN16(size);
	g_ALSoundRomOffsets = alHeapAlloc(&g_SndHeap, 1, size);
	dmaExec(g_ALSoundRomOffsets, romaddr, size);

	*(u32 *)&g_ALSoundRomOffsets += 0x10;

	// Convert ctl-local offsets to ROM offsets
	for (i = 0; i < g_NumSounds; i++) {
		g_ALSoundRomOffsets[i] += (u32) &_sfxctlSegmentRomStart;
	}

	// Allocate and initialise cache
	g_SndCache.indexes = alHeapAlloc(&g_SndHeap, sizeof(u16), g_NumSounds);

	for (i = 0; i < (u32)g_NumSounds; i++) {
		g_SndCache.indexes[i] = -1;
	}

	for (i = 0; i < 45; i++) {
		g_SndCache.ages[i] = 1;
		g_SndCache.refcounts[i] = 0;
	}
}
#else
GLOBAL_ASM(
glabel sndLoadSfxCtl
/*     f2d4:	27bdfe90 */ 	addiu	$sp,$sp,-368
/*     f2d8:	afb20028 */ 	sw	$s2,0x28($sp)
/*     f2dc:	03a09025 */ 	or	$s2,$sp,$zero
/*     f2e0:	afb10024 */ 	sw	$s1,0x24($sp)
/*     f2e4:	afb00020 */ 	sw	$s0,0x20($sp)
/*     f2e8:	2652006b */ 	addiu	$s2,$s2,0x6b
/*     f2ec:	3c118009 */ 	lui	$s1,0x8009
/*     f2f0:	364e000f */ 	ori	$t6,$s2,0xf
/*     f2f4:	3c10007c */ 	lui	$s0,0x7c
/*     f2f8:	26317e24 */ 	addiu	$s1,$s1,0x7e24
/*     f2fc:	afbf0034 */ 	sw	$ra,0x34($sp)
/*     f300:	2610e940 */ 	addiu	$s0,$s0,-5824
/*     f304:	39c4000f */ 	xori	$a0,$t6,0xf
/*     f308:	afb40030 */ 	sw	$s4,0x30($sp)
/*     f30c:	afb3002c */ 	sw	$s3,0x2c($sp)
/*     f310:	ae200000 */ 	sw	$zero,0x0($s1)
/*     f314:	00809025 */ 	or	$s2,$a0,$zero
/*     f318:	02002825 */ 	or	$a1,$s0,$zero
/*     f31c:	0c003664 */ 	jal	dmaExec
/*     f320:	24060100 */ 	addiu	$a2,$zero,0x100
/*     f324:	8e580004 */ 	lw	$t8,0x4($s2)
/*     f328:	02402025 */ 	or	$a0,$s2,$zero
/*     f32c:	24060100 */ 	addiu	$a2,$zero,0x100
/*     f330:	0c003664 */ 	jal	dmaExec
/*     f334:	02182821 */ 	addu	$a1,$s0,$t8
/*     f338:	8e59000c */ 	lw	$t9,0xc($s2)
/*     f33c:	02402025 */ 	or	$a0,$s2,$zero
/*     f340:	24060100 */ 	addiu	$a2,$zero,0x100
/*     f344:	0219a021 */ 	addu	$s4,$s0,$t9
/*     f348:	0c003664 */ 	jal	dmaExec
/*     f34c:	02802825 */ 	or	$a1,$s4,$zero
/*     f350:	864a000e */ 	lh	$t2,0xe($s2)
/*     f354:	3c098009 */ 	lui	$t1,0x8009
/*     f358:	3c018009 */ 	lui	$at,0x8009
/*     f35c:	254b0001 */ 	addiu	$t3,$t2,0x1
/*     f360:	25297e20 */ 	addiu	$t1,$t1,0x7e20
/*     f364:	ac2b7e20 */ 	sw	$t3,0x7e20($at)
/*     f368:	8d330000 */ 	lw	$s3,0x0($t1)
/*     f36c:	3c06800a */ 	lui	$a2,0x800a
/*     f370:	24c68170 */ 	addiu	$a2,$a2,-32400
/*     f374:	00136080 */ 	sll	$t4,$s3,0x2
/*     f378:	01809825 */ 	or	$s3,$t4,$zero
/*     f37c:	26730023 */ 	addiu	$s3,$s3,0x23
/*     f380:	366d000f */ 	ori	$t5,$s3,0xf
/*     f384:	39b3000f */ 	xori	$s3,$t5,0xf
/*     f388:	afb30010 */ 	sw	$s3,0x10($sp)
/*     f38c:	00002025 */ 	or	$a0,$zero,$zero
/*     f390:	00002825 */ 	or	$a1,$zero,$zero
/*     f394:	0c00c499 */ 	jal	alHeapDBAlloc
/*     f398:	24070001 */ 	addiu	$a3,$zero,0x1
/*     f39c:	ae220000 */ 	sw	$v0,0x0($s1)
/*     f3a0:	00402025 */ 	or	$a0,$v0,$zero
/*     f3a4:	02802825 */ 	or	$a1,$s4,$zero
/*     f3a8:	0c003664 */ 	jal	dmaExec
/*     f3ac:	02603025 */ 	or	$a2,$s3,$zero
/*     f3b0:	3c098009 */ 	lui	$t1,0x8009
/*     f3b4:	8e2f0000 */ 	lw	$t7,0x0($s1)
/*     f3b8:	25297e20 */ 	addiu	$t1,$t1,0x7e20
/*     f3bc:	8d280000 */ 	lw	$t0,0x0($t1)
/*     f3c0:	25f80010 */ 	addiu	$t8,$t7,0x10
/*     f3c4:	ae380000 */ 	sw	$t8,0x0($s1)
/*     f3c8:	1900000e */ 	blez	$t0,.NB0000f404
/*     f3cc:	00001825 */ 	or	$v1,$zero,$zero
/*     f3d0:	00002025 */ 	or	$a0,$zero,$zero
/*     f3d4:	8e390000 */ 	lw	$t9,0x0($s1)
.NB0000f3d8:
/*     f3d8:	24630001 */ 	addiu	$v1,$v1,0x1
/*     f3dc:	03241021 */ 	addu	$v0,$t9,$a0
/*     f3e0:	8c4a0000 */ 	lw	$t2,0x0($v0)
/*     f3e4:	24840004 */ 	addiu	$a0,$a0,0x4
/*     f3e8:	01505821 */ 	addu	$t3,$t2,$s0
/*     f3ec:	ac4b0000 */ 	sw	$t3,0x0($v0)
/*     f3f0:	8d280000 */ 	lw	$t0,0x0($t1)
/*     f3f4:	0068082a */ 	slt	$at,$v1,$t0
/*     f3f8:	5420fff7 */ 	bnezl	$at,.NB0000f3d8
/*     f3fc:	8e390000 */ 	lw	$t9,0x0($s1)
/*     f400:	00001825 */ 	or	$v1,$zero,$zero
.NB0000f404:
/*     f404:	3c06800a */ 	lui	$a2,0x800a
/*     f408:	24c68170 */ 	addiu	$a2,$a2,-32400
/*     f40c:	00002025 */ 	or	$a0,$zero,$zero
/*     f410:	00002825 */ 	or	$a1,$zero,$zero
/*     f414:	24070002 */ 	addiu	$a3,$zero,0x2
/*     f418:	afa80010 */ 	sw	$t0,0x10($sp)
/*     f41c:	0c00c499 */ 	jal	alHeapDBAlloc
/*     f420:	afa3016c */ 	sw	$v1,0x16c($sp)
/*     f424:	3c098009 */ 	lui	$t1,0x8009
/*     f428:	25297e20 */ 	addiu	$t1,$t1,0x7e20
/*     f42c:	8d2c0000 */ 	lw	$t4,0x0($t1)
/*     f430:	3c05800a */ 	lui	$a1,0x800a
/*     f434:	24a58190 */ 	addiu	$a1,$a1,-32368
/*     f438:	aca20000 */ 	sw	$v0,0x0($a1)
/*     f43c:	1180000c */ 	beqz	$t4,.NB0000f470
/*     f440:	8fa3016c */ 	lw	$v1,0x16c($sp)
/*     f444:	00001025 */ 	or	$v0,$zero,$zero
/*     f448:	3404ffff */ 	dli	$a0,0xffff
/*     f44c:	8cad0000 */ 	lw	$t5,0x0($a1)
.NB0000f450:
/*     f450:	24630001 */ 	addiu	$v1,$v1,0x1
/*     f454:	01a27021 */ 	addu	$t6,$t5,$v0
/*     f458:	a5c40000 */ 	sh	$a0,0x0($t6)
/*     f45c:	8d2f0000 */ 	lw	$t7,0x0($t1)
/*     f460:	24420002 */ 	addiu	$v0,$v0,0x2
/*     f464:	006f082b */ 	sltu	$at,$v1,$t7
/*     f468:	5420fff9 */ 	bnezl	$at,.NB0000f450
/*     f46c:	8cad0000 */ 	lw	$t5,0x0($a1)
.NB0000f470:
/*     f470:	3c18800a */ 	lui	$t8,0x800a
/*     f474:	27028190 */ 	addiu	$v0,$t8,-32368
/*     f478:	3c05800a */ 	lui	$a1,0x800a
/*     f47c:	3c04800a */ 	lui	$a0,0x800a
/*     f480:	248481bd */ 	addiu	$a0,$a0,-32323
/*     f484:	94a5ea1c */ 	lhu	$a1,-0x15e4($a1)
/*     f488:	00401825 */ 	or	$v1,$v0,$zero
.NB0000f48c:
/*     f48c:	24420001 */ 	addiu	$v0,$v0,0x1
/*     f490:	a4650032 */ 	sh	$a1,0x32($v1)
/*     f494:	24630002 */ 	addiu	$v1,$v1,0x2
/*     f498:	1444fffc */ 	bne	$v0,$a0,.NB0000f48c
/*     f49c:	a0400003 */ 	sb	$zero,0x3($v0)
/*     f4a0:	8fbf0034 */ 	lw	$ra,0x34($sp)
/*     f4a4:	8fb00020 */ 	lw	$s0,0x20($sp)
/*     f4a8:	8fb10024 */ 	lw	$s1,0x24($sp)
/*     f4ac:	8fb20028 */ 	lw	$s2,0x28($sp)
/*     f4b0:	8fb3002c */ 	lw	$s3,0x2c($sp)
/*     f4b4:	8fb40030 */ 	lw	$s4,0x30($sp)
/*     f4b8:	03e00008 */ 	jr	$ra
/*     f4bc:	27bd0170 */ 	addiu	$sp,$sp,0x170
);
#endif

#if VERSION >= VERSION_NTSC_1_0
void sndIncrementAges(void)
{
	s32 i;

	for (i = 0; i < 45; i++) {
		if (g_SndCache.refcounts[i] == 0 && g_SndCache.ages[i] < 32000) {
			g_SndCache.ages[i]++;
		}
	}
}
#endif

ALEnvelope *sndLoadEnvelope(u32 offset, u16 cacheindex)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 spaf[0x50];
	u8 sp5f[0x50];
	ALEnvelope *s2 = (ALEnvelope *)ALIGN16((u32)spaf);
	ALEnvelope *s1 = (ALEnvelope *)ALIGN16((u32)sp5f);
	s32 i;
	s32 sum1;
	s32 sum2;

	offset += (u32)&_sfxctlSegmentRomStart;

	do {
		dmaExecHighPriority(s2, offset, 0x40);
		sum1 = 0;

		for (i = 0; i < 16U; i++) {
			sum1 += ((u32 *)s2)[i];
		}

		dmaExecHighPriority(s1, offset, 0x40);
		sum2 = 0;

		for (i = 0; i < 16U; i++) {
			sum2 += ((u32 *)s1)[i];
		}

		if (1);
	} while (sum1 != sum2);
#else
	u8 sp5f[0x50];
	ALEnvelope *s1 = (ALEnvelope *)ALIGN16((u32)sp5f);

	offset += (u32)&_sfxctlSegmentRomStart;

	dmaExecHighPriority(s1, offset, 0x40);
#endif

	g_SndCache.envelopes[cacheindex] = *s1;

	s1 = g_SndCache.envelopes;
	s1 += cacheindex;

	return s1;
}

ALKeyMap *sndLoadKeymap(u32 offset, u16 cacheindex)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 spaf[0x50];
	u8 sp5f[0x50];
	ALKeyMap *s2 = (ALKeyMap *)ALIGN16((u32)spaf);
	ALKeyMap *s1 = (ALKeyMap *)ALIGN16((u32)sp5f);
	s32 i;
	s32 sum1;
	s32 sum2;

	offset += (u32)&_sfxctlSegmentRomStart;

	do {
		dmaExecHighPriority(s2, offset, 0x40);
		sum1 = 0;

		for (i = 0; i < 16U; i++) {
			sum1 += ((u32 *)s2)[i];
		}

		dmaExecHighPriority(s1, offset, 0x40);
		sum2 = 0;

		for (i = 0; i < 16U; i++) {
			sum2 += ((u32 *)s1)[i];
		}

		if (1);
	} while (sum1 != sum2);
#else
	u8 sp5f[0x50];
	ALKeyMap *s1 = (ALKeyMap *)ALIGN16((u32)sp5f);

	offset += (u32)&_sfxctlSegmentRomStart;

	dmaExecHighPriority(s1, offset, 0x40);
#endif

	g_SndCache.keymaps[cacheindex] = *s1;

	s1 = g_SndCache.keymaps;
	s1 += cacheindex;

	return s1;
}

ALADPCMBook *sndLoadAdpcmBook(u32 offset, u16 cacheindex)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 spaf[0x150];
	u8 sp5f[0x150];
	ALADPCMBook *s2 = (ALADPCMBook *)ALIGN16((u32)spaf);
	ALADPCMBook *s1 = (ALADPCMBook *)ALIGN16((u32)sp5f);
	s32 i;
	s32 sum1;
	s32 sum2;

	offset += (u32)&_sfxctlSegmentRomStart;

	do {
		dmaExecHighPriority(s2, offset, 0x140);
		sum1 = 0;

		for (i = 0; i < 80U; i++) {
			sum1 += ((u32 *)s2)[i];
		}

		dmaExecHighPriority(s1, offset, 0x140);
		sum2 = 0;

		for (i = 0; i < 80U; i++) {
			sum2 += ((u32 *)s1)[i];
		}

		if (1);
	} while (sum1 != sum2);
#else
	u8 sp5f[0x150];
	ALADPCMBook *s1 = (ALADPCMBook *)ALIGN16((u32)sp5f);

	offset += (u32)&_sfxctlSegmentRomStart;

	dmaExecHighPriority(s1, offset, 0x140);
#endif

	g_SndCache.books[cacheindex] = *s1;

	s1 = g_SndCache.books;
	s1 += cacheindex;

	return s1;
}

ALADPCMloop *sndLoadAdpcmLoop(u32 offset, u16 cacheindex)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 spaf[0x50];
	u8 sp5f[0x50];
	ALADPCMloop *s2 = (ALADPCMloop *)ALIGN16((u32)spaf);
	ALADPCMloop *s1 = (ALADPCMloop *)ALIGN16((u32)sp5f);
	s32 i;
	s32 sum1;
	s32 sum2;

	if (offset == 0) {
		return NULL;
	}

	offset += (u32)&_sfxctlSegmentRomStart;

	do {
		dmaExecHighPriority(s2, offset, 0x40);
		sum1 = 0;

		for (i = 0; i < 16U; i++) {
			sum1 += ((u32 *)s2)[i];
		}

		dmaExecHighPriority(s1, offset, 0x40);
		sum2 = 0;

		for (i = 0; i < 16U; i++) {
			sum2 += ((u32 *)s1)[i];
		}

		if (1);
	} while (sum1 != sum2);
#else
	u8 sp5f[0x50];
	ALADPCMloop *s1 = (ALADPCMloop *)ALIGN16((u32)sp5f);

	if (offset == 0) {
		return NULL;
	}

	offset += (u32)&_sfxctlSegmentRomStart;

	dmaExecHighPriority(s1, offset, 0x40);
#endif

	g_SndCache.loops[cacheindex] = *s1;

	s1 = g_SndCache.loops;
	s1 += cacheindex;

	return s1;
}

ALWaveTable *sndLoadWavetable(u32 offset, u16 cacheindex)
{
#if VERSION >= VERSION_NTSC_1_0
	u8 spaf[0x50];
	u8 sp5f[0x50];
	ALWaveTable *s2 = (ALWaveTable *)ALIGN16((u32)spaf);
	ALWaveTable *s1 = (ALWaveTable *)ALIGN16((u32)sp5f);
	s32 i;
	s32 sum1;
	s32 sum2;
	ALWaveTable *tmp;

	offset += (u32)&_sfxctlSegmentRomStart;

	do {
		dmaExecHighPriority(s2, offset, 0x40);
		sum1 = 0;

		for (i = 0; i < 16U; i++) {
			sum1 += ((u32 *)s2)[i];
		}

		dmaExecHighPriority(s1, offset, 0x40);
		sum2 = 0;

		for (i = 0; i < 16U; i++) {
			sum2 += ((u32 *)s1)[i];
		}

		if (1);
	} while (sum1 != sum2);
#else
	u8 sp5f[0x50];
	ALWaveTable *s1 = (ALWaveTable *)ALIGN16((u32)sp5f);
	ALWaveTable *tmp;

	offset += (u32)&_sfxctlSegmentRomStart;

	dmaExecHighPriority(s1, offset, 0x40);
#endif

	tmp = &g_SndCache.wavetables[cacheindex];

	*tmp = *s1;

	tmp->base += (u32)&_sfxtblSegmentRomStart;

	if (tmp->type == AL_ADPCM_WAVE) {
		tmp->waveInfo.adpcmWave.book = sndLoadAdpcmBook((u32)tmp->waveInfo.adpcmWave.book, cacheindex);
		tmp->waveInfo.adpcmWave.loop = sndLoadAdpcmLoop((u32)tmp->waveInfo.adpcmWave.loop, cacheindex);
	}

	return tmp;
}

void sndSetSoundMode(s32 mode)
{
	s32 i;

	g_SoundMode = mode;

	switch (mode) {
	case SOUNDMODE_MONO:
		speakersSetMode(SPEAKERMODE_MONO);
		break;
	case SOUNDMODE_STEREO:
		speakersSetMode(SPEAKERMODE_STEREO);
		break;
	case SOUNDMODE_HEADPHONE:
		speakersSetMode(SPEAKERMODE_HEADPHONE);
		break;
	case SOUNDMODE_SURROUND:
		speakersSetMode(SPEAKERMODE_SURROUND);
		break;
	}

	speaker00034104(0, 4);

	for (i = 1; i < g_SndMaxFxBusses; i++) {
		switch (mode) {
		case SOUNDMODE_STEREO:
		case SOUNDMODE_HEADPHONE:
		case SOUNDMODE_SURROUND:
			speaker00034104(i, 4);
			break;
		}
	}
}

#if VERSION >= VERSION_NTSC_1_0
ALSound *sndLoadSound(s16 soundnum)
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

	sound = (ALSound *)ALIGN16((u32)sp47);

	tmp.packed = soundnum;
	sfxnum = tmp.id;

	if (sndIsMp3(tmp.packed)) {
		return NULL;
	}

	// If this sound doesn't exist in the cache
	cacheindex = g_SndCache.indexes[sfxnum];

	if (cacheindex == 0xffff) {
		// Find the oldest cache item
		oldestindex = -1;
		oldestage = 0;

		for (i = 0; i < 45; i++) {
			if (g_SndCache.refcounts[i] == 0 && oldestage < g_SndCache.ages[i]) {
				oldestage = g_SndCache.ages[i];
				oldestindex = i;
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
		dmaExecHighPriority(sound, g_ALSoundRomOffsets[sfxnum - 1], 0x40);

		// Promote segment offsets to pointers and load their child data
		sound->envelope = sndLoadEnvelope((u32)sound->envelope, cacheindex);
		sound->wavetable = sndLoadWavetable((u32)sound->wavetable, cacheindex);
		sound->keyMap = sndLoadKeymap((u32)sound->keyMap, cacheindex);

		// Save the ALSound into the cache
		g_SndCache.sounds[cacheindex] = *sound;

		g_SndCache.indexes[sfxnum] = cacheindex;
	}

	// Reset this cache item's age, even if it already existed in the cache
	g_SndCache.ages[cacheindex] = 1;

	return &g_SndCache.sounds[cacheindex];
}
#else
GLOBAL_ASM(
glabel sndLoadSound
/*     f918:	27bdff50 */ 	addiu	$sp,$sp,-176
/*     f91c:	afb00014 */ 	sw	$s0,0x14($sp)
/*     f920:	00048400 */ 	sll	$s0,$a0,0x10
/*     f924:	00107403 */ 	sra	$t6,$s0,0x10
/*     f928:	afa400b0 */ 	sw	$a0,0xb0($sp)
/*     f92c:	000e2400 */ 	sll	$a0,$t6,0x10
/*     f930:	afbf001c */ 	sw	$ra,0x1c($sp)
/*     f934:	00047c03 */ 	sra	$t7,$a0,0x10
/*     f938:	01c08025 */ 	or	$s0,$t6,$zero
/*     f93c:	afb10018 */ 	sw	$s1,0x18($sp)
/*     f940:	0c00400e */ 	jal	sndIsMp3
/*     f944:	01e02025 */ 	or	$a0,$t7,$zero
/*     f948:	10400003 */ 	beqz	$v0,.NB0000f958
/*     f94c:	3c08800a */ 	lui	$t0,0x800a
/*     f950:	1000006b */ 	beqz	$zero,.NB0000fb00
/*     f954:	00001025 */ 	or	$v0,$zero,$zero
.NB0000f958:
/*     f958:	25088190 */ 	addiu	$t0,$t0,-32368
/*     f95c:	320b07ff */ 	andi	$t3,$s0,0x7ff
/*     f960:	8d060000 */ 	lw	$a2,0x0($t0)
/*     f964:	000bc400 */ 	sll	$t8,$t3,0x10
/*     f968:	00185c03 */ 	sra	$t3,$t8,0x10
/*     f96c:	000b6040 */ 	sll	$t4,$t3,0x1
/*     f970:	00cc6821 */ 	addu	$t5,$a2,$t4
/*     f974:	95aa0000 */ 	lhu	$t2,0x0($t5)
/*     f978:	3401ffff */ 	dli	$at,0xffff
/*     f97c:	2407ffff */ 	addiu	$a3,$zero,-1
/*     f980:	15410056 */ 	bne	$t2,$at,.NB0000fadc
/*     f984:	00002825 */ 	or	$a1,$zero,$zero
/*     f988:	3c03800a */ 	lui	$v1,0x800a
/*     f98c:	3c09800a */ 	lui	$t1,0x800a
/*     f990:	2529e6c0 */ 	addiu	$t1,$t1,-6464
/*     f994:	24638190 */ 	addiu	$v1,$v1,-32368
/*     f998:	00001025 */ 	or	$v0,$zero,$zero
.NB0000f99c:
/*     f99c:	906e0004 */ 	lbu	$t6,0x4($v1)
/*     f9a0:	0002c040 */ 	sll	$t8,$v0,0x1
/*     f9a4:	0118c821 */ 	addu	$t9,$t0,$t8
/*     f9a8:	55c0000b */ 	bnezl	$t6,.NB0000f9d8
/*     f9ac:	24420001 */ 	addiu	$v0,$v0,0x1
/*     f9b0:	952f035c */ 	lhu	$t7,0x35c($t1)
/*     f9b4:	972d0032 */ 	lhu	$t5,0x32($t9)
/*     f9b8:	01ed2023 */ 	subu	$a0,$t7,$t5
/*     f9bc:	24840001 */ 	addiu	$a0,$a0,0x1
/*     f9c0:	00a4082b */ 	sltu	$at,$a1,$a0
/*     f9c4:	50200004 */ 	beqzl	$at,.NB0000f9d8
/*     f9c8:	24420001 */ 	addiu	$v0,$v0,0x1
/*     f9cc:	00802825 */ 	or	$a1,$a0,$zero
/*     f9d0:	00403825 */ 	or	$a3,$v0,$zero
/*     f9d4:	24420001 */ 	addiu	$v0,$v0,0x1
.NB0000f9d8:
/*     f9d8:	2841002d */ 	slti	$at,$v0,0x2d
/*     f9dc:	1420ffef */ 	bnez	$at,.NB0000f99c
/*     f9e0:	24630001 */ 	addiu	$v1,$v1,0x1
/*     f9e4:	3c048009 */ 	lui	$a0,0x8009
/*     f9e8:	8c847e20 */ 	lw	$a0,0x7e20($a0)
/*     f9ec:	30eaffff */ 	andi	$t2,$a3,0xffff
/*     f9f0:	00c01825 */ 	or	$v1,$a2,$zero
/*     f9f4:	1080000d */ 	beqz	$a0,.NB0000fa2c
/*     f9f8:	00001025 */ 	or	$v0,$zero,$zero
/*     f9fc:	30e5ffff */ 	andi	$a1,$a3,0xffff
/*     fa00:	3406ffff */ 	dli	$a2,0xffff
.NB0000fa04:
/*     fa04:	946e0000 */ 	lhu	$t6,0x0($v1)
/*     fa08:	24420001 */ 	addiu	$v0,$v0,0x1
/*     fa0c:	54ae0005 */ 	bnel	$a1,$t6,.NB0000fa24
/*     fa10:	0044082b */ 	sltu	$at,$v0,$a0
/*     fa14:	a4660000 */ 	sh	$a2,0x0($v1)
/*     fa18:	3c048009 */ 	lui	$a0,0x8009
/*     fa1c:	8c847e20 */ 	lw	$a0,0x7e20($a0)
/*     fa20:	0044082b */ 	sltu	$at,$v0,$a0
.NB0000fa24:
/*     fa24:	1420fff7 */ 	bnez	$at,.NB0000fa04
/*     fa28:	24630002 */ 	addiu	$v1,$v1,0x2
.NB0000fa2c:
/*     fa2c:	3c0f8009 */ 	lui	$t7,0x8009
/*     fa30:	8def7e24 */ 	lw	$t7,0x7e24($t7)
/*     fa34:	03a08025 */ 	or	$s0,$sp,$zero
/*     fa38:	26100047 */ 	addiu	$s0,$s0,0x47
/*     fa3c:	000b6880 */ 	sll	$t5,$t3,0x2
/*     fa40:	3618000f */ 	ori	$t8,$s0,0xf
/*     fa44:	01ed7021 */ 	addu	$t6,$t7,$t5
/*     fa48:	8dc5fffc */ 	lw	$a1,-0x4($t6)
/*     fa4c:	3b04000f */ 	xori	$a0,$t8,0xf
/*     fa50:	00808025 */ 	or	$s0,$a0,$zero
/*     fa54:	afac0024 */ 	sw	$t4,0x24($sp)
/*     fa58:	a7aa00aa */ 	sh	$t2,0xaa($sp)
/*     fa5c:	24060040 */ 	addiu	$a2,$zero,0x40
/*     fa60:	0c00366e */ 	jal	dmaExecHighPriority
/*     fa64:	30f1ffff */ 	andi	$s1,$a3,0xffff
/*     fa68:	8e040000 */ 	lw	$a0,0x0($s0)
/*     fa6c:	0c003d30 */ 	jal	sndLoadEnvelope
/*     fa70:	3225ffff */ 	andi	$a1,$s1,0xffff
/*     fa74:	ae020000 */ 	sw	$v0,0x0($s0)
/*     fa78:	8e040008 */ 	lw	$a0,0x8($s0)
/*     fa7c:	0c003dcb */ 	jal	sndLoadWavetable
/*     fa80:	3225ffff */ 	andi	$a1,$s1,0xffff
/*     fa84:	ae020008 */ 	sw	$v0,0x8($s0)
/*     fa88:	8e040004 */ 	lw	$a0,0x4($s0)
/*     fa8c:	0c003d53 */ 	jal	sndLoadKeymap
/*     fa90:	3225ffff */ 	andi	$a1,$s1,0xffff
/*     fa94:	8e010000 */ 	lw	$at,0x0($s0)
/*     fa98:	3c08800a */ 	lui	$t0,0x800a
/*     fa9c:	25088190 */ 	addiu	$t0,$t0,-32368
/*     faa0:	97aa00aa */ 	lhu	$t2,0xaa($sp)
/*     faa4:	0011c100 */ 	sll	$t8,$s1,0x4
/*     faa8:	ae020004 */ 	sw	$v0,0x4($s0)
/*     faac:	0118c821 */ 	addu	$t9,$t0,$t8
/*     fab0:	af213e14 */ 	sw	$at,0x3e14($t9)
/*     fab4:	8e0d0004 */ 	lw	$t5,0x4($s0)
/*     fab8:	af2d3e18 */ 	sw	$t5,0x3e18($t9)
/*     fabc:	8e010008 */ 	lw	$at,0x8($s0)
/*     fac0:	af213e1c */ 	sw	$at,0x3e1c($t9)
/*     fac4:	8e0d000c */ 	lw	$t5,0xc($s0)
/*     fac8:	af2d3e20 */ 	sw	$t5,0x3e20($t9)
/*     facc:	8fb80024 */ 	lw	$t8,0x24($sp)
/*     fad0:	8d0e0000 */ 	lw	$t6,0x0($t0)
/*     fad4:	01d87821 */ 	addu	$t7,$t6,$t8
/*     fad8:	a5f10000 */ 	sh	$s1,0x0($t7)
.NB0000fadc:
/*     fadc:	3c09800a */ 	lui	$t1,0x800a
/*     fae0:	2529e6c0 */ 	addiu	$t1,$t1,-6464
/*     fae4:	9539035c */ 	lhu	$t9,0x35c($t1)
/*     fae8:	000a6840 */ 	sll	$t5,$t2,0x1
/*     faec:	000ac100 */ 	sll	$t8,$t2,0x4
/*     faf0:	010d7021 */ 	addu	$t6,$t0,$t5
/*     faf4:	01181021 */ 	addu	$v0,$t0,$t8
/*     faf8:	24423e14 */ 	addiu	$v0,$v0,0x3e14
/*     fafc:	a5d90032 */ 	sh	$t9,0x32($t6)
.NB0000fb00:
/*     fb00:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*     fb04:	8fb00014 */ 	lw	$s0,0x14($sp)
/*     fb08:	8fb10018 */ 	lw	$s1,0x18($sp)
/*     fb0c:	03e00008 */ 	jr	$ra
/*     fb10:	27bd00b0 */ 	addiu	$sp,$sp,0xb0
);
#endif

void seqInit(struct seqinstance *seq)
{
	u32 stack;
	ALSeqpConfig config;

	config.maxVoices = 44;
	config.maxEvents = 64;
	config.maxChannels = 16;
	config.debugFlags = 0;
	config.heap = &g_SndHeap;

	func00030c98(&config);

	if (IS4MB()) {
		g_SeqBufferSize = 0x3800;
	} else {
		g_SeqBufferSize = 0x4800;
	}

	seq->data = alHeapAlloc(&g_SndHeap, 1, g_SeqBufferSize);
	seq->seqp = alHeapAlloc(&g_SndHeap, 1, sizeof(N_ALCSPlayer));

	n_alCSPNew(seq->seqp, &config);

	n_alCSPSetBank(seq->seqp, var80095204);
}

void sndAddRef(ALSound *sound)
{
	if (sound >= &g_SndCache.sounds[0] && sound <= &g_SndCache.sounds[44]) {
		s32 cacheindex = sound - g_SndCache.sounds;
		g_SndCache.refcounts[cacheindex]++;
	}
}

void sndRemoveRef(ALSound *sound)
{
	if (sound >= &g_SndCache.sounds[0] && sound <= &g_SndCache.sounds[44]) {
		s32 cacheindex = sound - g_SndCache.sounds;
		g_SndCache.refcounts[cacheindex]--;
	}
}

void sndInit(void)
{
	ALSndpConfig sndpconfig;

#if VERSION >= VERSION_PAL_FINAL
	u32 heaplen = 1024 * 446;
#elif VERSION >= VERSION_NTSC_1_0
	u32 heaplen = 1024 * 441;
#else
	u32 heaplen = 1024 * 438;
#endif

	g_Vars.langfilteron = false;

	if (IS4MB()) {
		g_SndMaxFxBusses = 1;

#if VERSION >= VERSION_PAL_FINAL
		heaplen -= 1024 * 6;
#else
		heaplen -= 1024 * 38;
#endif
		heaplen -= 1024 * 137;
		heaplen -= 1024 * 12;
		heaplen -= 1024 * 23;

		g_SndMp3Enabled = false;
	} else {
		g_SndMp3Enabled = true;
		g_SndMaxFxBusses = 2;

		if (argFindByPrefix(1, "-nomp3")) {
			g_SndMp3Enabled = false;
		}
	}

	if (!g_SndDisabled) {
		// Allocate memory for the audio heap,
		// clear it and give it to the audio library
		ALSynConfig synconfig;
#if VERSION >= VERSION_PAL_FINAL
		u32 settings[3];
#endif
		u8 *ptr = mempAlloc(heaplen, MEMPOOL_PERMANENT);
		u32 len = &_seqctlSegmentRomEnd - &_seqctlSegmentRomStart;
		s32 i;
		u32 seqromaddr = (u32) &_sequencesSegmentRomStart;
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
		g_SndGuardStringPtr = alHeapAlloc(&g_SndHeap, 1, 32);
		strcpy(g_SndGuardStringPtr, g_SndGuardString);

		// Load sfx.ctl
		sndLoadSfxCtl();

		// Load seq.ctl
		var80095200 = 0xffffffff;
		bankfile = alHeapAlloc(&g_SndHeap, 1, len);
		dmaExec(bankfile, (u32) &_seqctlSegmentRomStart, len);

		// Load seq.tbl
		alBnkfNew(bankfile, &_seqtblSegmentRomStart);

		// Load the sequences table. To do this, load the header of the
		// sequences segment and read the number of sequences, then allocate
		// enough space for the table and load it.
		var80095204 = bankfile->bankArray[0];
		g_SeqTable = alHeapDBAlloc(0, 0, &g_SndHeap, 1, 0x10);
		dmaExec(g_SeqTable, seqromaddr, 0x10);

		len = g_SeqTable->count * sizeof(struct seqtableentry) + 4;
		g_SeqTable = alHeapDBAlloc(0, 0, &g_SndHeap, 1, len);
		dmaExec(g_SeqTable, seqromaddr, len + 0xf & 0xfffffff0);

		// Promote segment-relative offsets to ROM addresses
		for (i = 0; i < g_SeqTable->count; i++) {
			g_SeqTable->entries[i].romaddr += seqromaddr;
		}

		synconfig.maxVVoices = 44;
		synconfig.maxPVoices = 30;
		synconfig.maxUpdates = 64;
		synconfig.dmaproc = NULL;
		synconfig.outputRate = 0;
		synconfig.heap = &g_SndHeap;
		synconfig.maxFXbusses = g_SndMaxFxBusses;

		for (i = 0; i < g_SndMaxFxBusses; i++) {
			synconfig.fxTypes[i] = 6;
		}

		sndpconfig.maxEvents = 64;
		sndpconfig.maxStates = 64;
		sndpconfig.maxSounds = 20;
		sndpconfig.unk10 = 9;
		sndpconfig.heap = &g_SndHeap;

#if VERSION >= VERSION_PAL_FINAL
		settings[0] = 22020;
		settings[1] = 1;
		settings[2] = 2000;

		amgrCreate(&synconfig, settings);
#else
		amgrCreate(&synconfig);
#endif

		if (g_SndMp3Enabled) {
			osSyncPrintf("RWI : Initialising the new and improved MP3 player\n");

			mp3Init(&g_SndHeap);
			func00037f08(0x7fff, 1);
			func00037f5c(0, true);

			osSyncPrintf("RWI : MP3 player Initialising Done\n");
		}

		for (i = 0; i < 3; i++) {
			seqInit(&g_SeqInstances[i]);
		}

		osSyncPrintf("gsSndpNew\n");

		n_alSndpNew(&sndpconfig);

		osSyncPrintf("Set the sample callbacks\n");

		sndpSetAddRefCallback(sndAddRef);
		sndpSetRemoveRefCallback(sndRemoveRef);

		amgrStartThread();

		sndSetSoundMode(g_SoundMode);
	}
}

bool sndIsMp3(s16 soundnum)
{
	union soundnumhack tmp;
	tmp.packed = soundnum;

	return tmp.mp3priority != 0;
}

bool snd0000fbc4(s16 arg0)
{
	if (!g_SndDisabled && g_SndMp3Enabled) {
		if (func00037ea4() && g_SndCurMp3.unk08 != 0) {
			return false;
		}

		func00037e1c();

		g_SndCurMp3.playing = false;
		g_SndCurMp3.responsetimer240 = -1;
	}

	return true;
}

void snd0000fc40(s32 arg0)
{
	// empty
}

#if VERSION >= VERSION_NTSC_1_0
bool seqPlay(struct seqinstance *seq, s32 tracknum)
{
	u32 stack;
	s32 binlen;
	u8 *binstart;
	s32 ziplen;
	u8 *zipstart;
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
	binstart = seq->data;
	zipstart = binstart + binlen - ziplen;

	dmaExec(zipstart, g_SeqTable->entries[seq->tracknum].romaddr, ziplen);

	rzipInflate(zipstart, binstart, scratch);

	n_alCSeqNew(&seq->seq, seq->data);
	n_alCSPSetSeq(seq->seqp, &seq->seq);
	seqSetVolume(seq, seqGetVolume(seq));
	n_alCSPPlay(seq->seqp);

	return true;
}
#else
const char var70055250nb[] = "DMA-Crash %s %d Ram: %02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x";
const char var700552a8nb[] = "snd.c";

GLOBAL_ASM(
glabel seqPlay
/*    100e0:	27bdeaf8 */ 	addiu	$sp,$sp,-5384
/*    100e4:	afb00058 */ 	sw	$s0,0x58($sp)
/*    100e8:	00808025 */ 	or	$s0,$a0,$zero
/*    100ec:	afbf005c */ 	sw	$ra,0x5c($sp)
/*    100f0:	afa5150c */ 	sw	$a1,0x150c($sp)
/*    100f4:	0c00e838 */ 	jal	n_alCSPGetState
/*    100f8:	8c8400f8 */ 	lw	$a0,0xf8($a0)
/*    100fc:	3c0e8006 */ 	lui	$t6,0x8006
/*    10100:	8dcef6c0 */ 	lw	$t6,-0x940($t6)
/*    10104:	8fa4150c */ 	lw	$a0,0x150c($sp)
/*    10108:	3c03800a */ 	lui	$v1,0x800a
/*    1010c:	51c00004 */ 	beqzl	$t6,.NB00010120
/*    10110:	ae040104 */ 	sw	$a0,0x104($s0)
/*    10114:	10000066 */ 	beqz	$zero,.NB000102b0
/*    10118:	00001025 */ 	or	$v0,$zero,$zero
/*    1011c:	ae040104 */ 	sw	$a0,0x104($s0)
.NB00010120:
/*    10120:	10400003 */ 	beqz	$v0,.NB00010130
/*    10124:	8c638188 */ 	lw	$v1,-0x7e78($v1)
/*    10128:	10000061 */ 	beqz	$zero,.NB000102b0
/*    1012c:	00001025 */ 	or	$v0,$zero,$zero
.NB00010130:
/*    10130:	8e0f0104 */ 	lw	$t7,0x104($s0)
/*    10134:	3c010001 */ 	lui	$at,0x1
/*    10138:	000fc0c0 */ 	sll	$t8,$t7,0x3
/*    1013c:	00781021 */ 	addu	$v0,$v1,$t8
/*    10140:	8c450004 */ 	lw	$a1,0x4($v0)
/*    10144:	00a1082b */ 	sltu	$at,$a1,$at
/*    10148:	50200004 */ 	beqzl	$at,.NB0001015c
/*    1014c:	94470008 */ 	lhu	$a3,0x8($v0)
/*    10150:	10000057 */ 	beqz	$zero,.NB000102b0
/*    10154:	00001025 */ 	or	$v0,$zero,$zero
/*    10158:	94470008 */ 	lhu	$a3,0x8($v0)
.NB0001015c:
/*    1015c:	3c0a800a */ 	lui	$t2,0x800a
/*    10160:	8d4a818c */ 	lw	$t2,-0x7e74($t2)
/*    10164:	24e7000f */ 	addiu	$a3,$a3,0xf
/*    10168:	34f9000f */ 	ori	$t9,$a3,0xf
/*    1016c:	3b29000f */ 	xori	$t1,$t9,0xf
/*    10170:	25270040 */ 	addiu	$a3,$t1,0x40
/*    10174:	00ea082b */ 	sltu	$at,$a3,$t2
/*    10178:	54200004 */ 	bnezl	$at,.NB0001018c
/*    1017c:	9446000a */ 	lhu	$a2,0xa($v0)
/*    10180:	1000004b */ 	beqz	$zero,.NB000102b0
/*    10184:	00001025 */ 	or	$v0,$zero,$zero
/*    10188:	9446000a */ 	lhu	$a2,0xa($v0)
.NB0001018c:
/*    1018c:	8e0800fc */ 	lw	$t0,0xfc($s0)
/*    10190:	24c6000f */ 	addiu	$a2,$a2,0xf
/*    10194:	34cb000f */ 	ori	$t3,$a2,0xf
/*    10198:	3966000f */ 	xori	$a2,$t3,0xf
/*    1019c:	01076821 */ 	addu	$t5,$t0,$a3
/*    101a0:	01a62023 */ 	subu	$a0,$t5,$a2
/*    101a4:	afa414f8 */ 	sw	$a0,0x14f8($sp)
/*    101a8:	afa40064 */ 	sw	$a0,0x64($sp)
/*    101ac:	0c003664 */ 	jal	dmaExec
/*    101b0:	afa814fc */ 	sw	$t0,0x14fc($sp)
/*    101b4:	8fa40064 */ 	lw	$a0,0x64($sp)
/*    101b8:	8fa514fc */ 	lw	$a1,0x14fc($sp)
/*    101bc:	0c001da4 */ 	jal	rzipInflate
/*    101c0:	27a600f4 */ 	addiu	$a2,$sp,0xf4
/*    101c4:	1440002c */ 	bnez	$v0,.NB00010278
/*    101c8:	8fa314f8 */ 	lw	$v1,0x14f8($sp)
/*    101cc:	906e0000 */ 	lbu	$t6,0x0($v1)
/*    101d0:	3c057005 */ 	lui	$a1,0x7005
/*    101d4:	3c067005 */ 	lui	$a2,0x7005
/*    101d8:	afae0010 */ 	sw	$t6,0x10($sp)
/*    101dc:	906f0001 */ 	lbu	$t7,0x1($v1)
/*    101e0:	24c652a8 */ 	addiu	$a2,$a2,0x52a8
/*    101e4:	24a55250 */ 	addiu	$a1,$a1,0x5250
/*    101e8:	afaf0014 */ 	sw	$t7,0x14($sp)
/*    101ec:	90780002 */ 	lbu	$t8,0x2($v1)
/*    101f0:	27a40070 */ 	addiu	$a0,$sp,0x70
/*    101f4:	2407068c */ 	addiu	$a3,$zero,0x68c
/*    101f8:	afb80018 */ 	sw	$t8,0x18($sp)
/*    101fc:	90790003 */ 	lbu	$t9,0x3($v1)
/*    10200:	afb9001c */ 	sw	$t9,0x1c($sp)
/*    10204:	90690004 */ 	lbu	$t1,0x4($v1)
/*    10208:	afa90020 */ 	sw	$t1,0x20($sp)
/*    1020c:	906a0005 */ 	lbu	$t2,0x5($v1)
/*    10210:	afaa0024 */ 	sw	$t2,0x24($sp)
/*    10214:	906b0006 */ 	lbu	$t3,0x6($v1)
/*    10218:	afab0028 */ 	sw	$t3,0x28($sp)
/*    1021c:	906c0007 */ 	lbu	$t4,0x7($v1)
/*    10220:	afac002c */ 	sw	$t4,0x2c($sp)
/*    10224:	906d0008 */ 	lbu	$t5,0x8($v1)
/*    10228:	afad0030 */ 	sw	$t5,0x30($sp)
/*    1022c:	906e0009 */ 	lbu	$t6,0x9($v1)
/*    10230:	afae0034 */ 	sw	$t6,0x34($sp)
/*    10234:	906f000a */ 	lbu	$t7,0xa($v1)
/*    10238:	afaf0038 */ 	sw	$t7,0x38($sp)
/*    1023c:	9078000b */ 	lbu	$t8,0xb($v1)
/*    10240:	afb8003c */ 	sw	$t8,0x3c($sp)
/*    10244:	9079000c */ 	lbu	$t9,0xc($v1)
/*    10248:	afb90040 */ 	sw	$t9,0x40($sp)
/*    1024c:	9069000d */ 	lbu	$t1,0xd($v1)
/*    10250:	afa90044 */ 	sw	$t1,0x44($sp)
/*    10254:	906a000e */ 	lbu	$t2,0xe($v1)
/*    10258:	afaa0048 */ 	sw	$t2,0x48($sp)
/*    1025c:	906b000f */ 	lbu	$t3,0xf($v1)
/*    10260:	0c004fc1 */ 	jal	sprintf
/*    10264:	afab004c */ 	sw	$t3,0x4c($sp)
/*    10268:	0c003074 */ 	jal	crashSetMessage
/*    1026c:	27a40070 */ 	addiu	$a0,$sp,0x70
/*    10270:	240c0045 */ 	addiu	$t4,$zero,0x45
/*    10274:	a00c0000 */ 	sb	$t4,0x0($zero)
.NB00010278:
/*    10278:	02002025 */ 	or	$a0,$s0,$zero
/*    1027c:	0c00e840 */ 	jal	n_alCSeqNew
/*    10280:	8e0500fc */ 	lw	$a1,0xfc($s0)
/*    10284:	8e0400f8 */ 	lw	$a0,0xf8($s0)
/*    10288:	0c00ebec */ 	jal	n_alCSPSetSeq
/*    1028c:	02002825 */ 	or	$a1,$s0,$zero
/*    10290:	0c0040b1 */ 	jal	seqGetVolume
/*    10294:	02002025 */ 	or	$a0,$s0,$zero
/*    10298:	02002025 */ 	or	$a0,$s0,$zero
/*    1029c:	0c0040bb */ 	jal	seqSetVolume
/*    102a0:	3045ffff */ 	andi	$a1,$v0,0xffff
/*    102a4:	0c00ec00 */ 	jal	n_alCSPPlay
/*    102a8:	8e0400f8 */ 	lw	$a0,0xf8($s0)
/*    102ac:	24020001 */ 	addiu	$v0,$zero,0x1
.NB000102b0:
/*    102b0:	8fbf005c */ 	lw	$ra,0x5c($sp)
/*    102b4:	8fb00058 */ 	lw	$s0,0x58($sp)
/*    102b8:	27bd1508 */ 	addiu	$sp,$sp,0x1508
/*    102bc:	03e00008 */ 	jr	$ra
/*    102c0:	00000000 */ 	sll	$zero,$zero,0x0
);
#endif

u16 seqGetVolume(struct seqinstance *seq)
{
	return g_SndDisabled ? 0x7fff : seq->volume;
}

void seqSetVolume(struct seqinstance *seq, u16 volume)
{
	if (!g_SndDisabled) {
		u32 tmp = (var8005ecf8[seq->tracknum] * volume);
		tmp >>=	15;

		seq->volume = volume;

		if (tmp > 0x7fff) {
			tmp = 0x7fff;
		}

		n_alCSPSetVol(seq->seqp, tmp);
	}
}

void snd0000fe18(void)
{
	// empty
}

void snd0000fe20(void)
{
	if (g_SndMp3Enabled) {
		func00037e38();
	}
}

void snd0000fe50(void)
{
	if (g_SndMp3Enabled) {
		func00037e68();
	}
}

void snd0000fe80(void)
{
	// empty
}

void sndTick(void)
{
#if VERSION >= VERSION_NTSC_1_0
	struct sndstate *stateptrs[64];
	struct sndstate states[64];
	s32 i;
	s32 curtime;
	struct sndstate *state;
#endif
	OSPri prevpri;
	s32 s0;
	union soundnumhack sp50;
	s32 index;
	s32 stack;

#if VERSION >= VERSION_NTSC_1_0
	static s32 var8005edec = -1;

	sndIncrementAges();

	prevpri = osGetThreadPri(NULL);
	osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);

	curtime = sndpGetCurTime();
	state = sndpGetHeadState();

	var8005ddd4 = 0;
	i = 0;

	while (state) {
		stateptrs[i] = state;
		states[i] = *state;

		var8005ddd4++;

		if ((state->flags & SNDSTATEFLAG_02) == 0
				&& stateptrs[i]->state == AL_PLAYING
				&& stateptrs[i]->unk48 > 0
				&& stateptrs[i]->unk48 < curtime
				) {
			state->unk48 = 0;
			func00033db0();
			break;
		}

		state = (struct sndstate *)state->node.next;
		i++;
	}

	osSetThreadPri(0, prevpri);

	if (var8005ddd8 < var8005ddd4) {
		var8005ddd8 = var8005ddd4;
	}

	if (var8005edec != var8005ddd8) {
		var8005edec = var8005ddd8;
	}
#endif

	if (!g_SndDisabled && g_SndMp3Enabled) {
		if (g_Vars.stagenum == STAGE_AIRFORCEONE) {
			sndTickNosedive();
		} else if (g_Vars.stagenum == STAGE_ESCAPE) {
			sndTickUfo();
		}

		if (g_Vars.tickmode == TICKMODE_CUTSCENE) {
			s0 = musicGetVolume() > g_SfxVolume ? musicGetVolume() : g_SfxVolume;

			if (s0 != snd0000e9dc()) {
				snd0000ea80(s0);
			}
		} else {
			if (g_SfxVolume != snd0000e9dc()) {
				snd0000ea80(g_SfxVolume);
			}
		}

		if (g_SndGuardStringPtr != NULL) {
			if (strcmp(g_SndGuardStringPtr, &g_SndGuardString) != 0) {
#if VERSION < VERSION_NTSC_1_0
				crashSetMessage("Snd Heap Check FAILED");
				CRASH();
#endif
			}
		}

		if (func00037ea4() == 0 && g_SndCurMp3.playing) {
			if (g_SndCurMp3.unk08) {
				mp3PlayFile(g_SndCurMp3.romaddr, g_SndCurMp3.romsize);
				return;
			}

			switch (g_SndCurMp3.responsetype) {
			case MP3RESPONSETYPE_ACKNOWLEDGE:
			case MP3RESPONSETYPE_WHISPER:
				g_SndCurMp3.responsetimer240 = PALDOWN(60);
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
					case 0: sp50.packed = MP3_JO_WHISPER_RECEIVED; break;
					case 1: sp50.packed = MP3_JO_WHISPER_UNDERSTOOD; break;
					case 2: sp50.packed = MP3_JO_WHISPER_AFFIRMATIVE; break;
					case 3: sp50.packed = MP3_JO_WHISPER_CONFIRMED; break;
					}
				} else if (g_SndCurMp3.responsetype == MP3RESPONSETYPE_ACKNOWLEDGE) {
					do {
						index = random() % 4;
					} while (index == g_SndCurMp3.prevacknowledge);

					g_SndCurMp3.prevacknowledge = index;

					switch (index) {
					case 0: sp50.packed = MP3_JO_ACKNOWLEDGE_CONFIRMED; break;
					case 1: sp50.packed = MP3_JO_ACKNOWLEDGE_UNDERSTOOD; break;
					case 2: sp50.packed = MP3_JO_ACKNOWLEDGE_AFFIRMATIVE; break;
					case 3: sp50.packed = MP3_JO_ACKNOWLEDGE_RECEIVED; break;
					}
				} else if (g_SndCurMp3.responsetype == MP3RESPONSETYPE_GREETING) {
					do {
						index = random() % 4;
					} while (index == g_SndCurMp3.prevgreeting);

					g_SndCurMp3.prevgreeting = index;

					switch (index) {
					case 0: sp50.packed = MP3_JO_GREETING_HELLO; break;
					case 1: sp50.packed = MP3_JO_GREETING_HI; break;
					case 2: sp50.packed = MP3_JO_GREETING_HEY; break;
					case 3: sp50.packed = MP3_JO_GREETING_HIYA; break;
					}
				}

				g_SndCurMp3.responsetimer240 = -1;
				sndStart(0, sp50.packed, 0, -1, -1, -1.0f, -1, -1);
			}
		}
	}
}

GLOBAL_ASM(
glabel func0001034c
/*    1034c:	309907ff */ 	andi	$t9,$a0,0x7ff
/*    10350:	00194400 */ 	sll	$t0,$t9,0x10
/*    10354:	afa40000 */ 	sw	$a0,0x0($sp)
/*    10358:	03e00008 */ 	jr	$ra
/*    1035c:	00081403 */ 	sra	$v0,$t0,0x10
);

bool sndIsDisabled(void)
{
	return g_SndDisabled;
}

void sndStartMp3ByFilenum(u32 filenum)
{
	union soundnumhack sfxref;

	if (!g_SndDisabled && g_SndMp3Enabled) {
		sfxref.packed = 0;
		sfxref.unk02 = 0;
		sfxref.mp3priority = 1; // high priority
		sfxref.id = filenum;

		sndStart(0, sfxref.packed, NULL, -1, -1, -1, -1, -1);
	}
}

/**
 * Return true if the player has the language filter enabled
 * and the given audio ID is one that should be filtered out.
 */
bool sndIsFiltered(s32 audio_id)
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
			case SFX_ELVIS_KISS_MY_ALIEN_BUTT:
			case SFX_ELVIS_ILL_KICK_YOUR_ASS:
			case MP3_HANGERGUY_DONT_SCREW_UP:
				return true;
			}
		}
#endif
	}

	return false;
}

void sndAdjust(struct sndstate **handle, s32 arg1, s32 arg2, s32 pan, s32 soundnum, f32 arg5, s32 arg6, s32 arg7, s32 arg8)
{
	s32 sp24 = -1;
	union soundnumhack sp20;
	union soundnumhack sp1c;
	struct audioconfig *config;

	if (arg8 || arg7 != -1) {
		if (arg7 != -1) {
			sp24 = arg7;
		} else {
			sp24 = 0;
		}

#if VERSION >= VERSION_NTSC_1_0
		if (pan != -1 && g_SoundMode == SOUNDMODE_SURROUND && (pan & 0x80)) {
			sp24 += 128;
		}
#else
		if (g_SoundMode == SOUNDMODE_SURROUND && (pan & 0x80)) {
			sp24 += 128;
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

			if (config->unk10 != 100) {
				arg2 = arg2 * config->unk10 / 100;
			}

			if (config->unk14 != -1) {
				pan = config->unk14;
			}

			if (g_Vars.langfilteron && (config->flags & AUDIOCONFIGFLAG_OFFENSIVE)) {
				arg2 = 0;
			}
		}
	}

	if (arg1 != 0) {
		if (arg2 != -1) {
			arg2 = arg2 * snd0000e9dc() / 32767;
			func00037f08(arg2, true);
		}

		if (pan != -1) {
			func00037f5c(pan, true);
		}
	}

	if (*handle != NULL) {
		if (arg2 != -1) {
			audioPostEvent(*handle, 8, arg2);
		}

		if (pan != -1) {
			audioPostEvent(*handle, 4, pan & 0x7f);
		}

		if (arg5 != -1.0f) {
			audioPostEvent(*handle, 0x10, *(s32 *)&arg5);
		}

		if (sp24 != -1) {
			audioPostEvent(*handle, 0x100, sp24);
		}
	}
}

struct sndstate *snd00010718(struct sndstate **handle, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 arg6, s32 arg7, s32 arg8)
{
	OSPri prevpri = osGetThreadPri(NULL);
	s32 t0 = -1;
	struct sndstate *state;
	union soundnumhack sp30;
	union soundnumhack sp2c;
	struct audioconfig *config;

	osSetThreadPri(0, osGetThreadPri(&g_AudioManager.thread) + 1);

	if (arg8 || arg7 != -1) {
		if (arg7 != -1) {
			t0 = arg7;
		} else {
			t0 = 0;
		}

#if VERSION >= VERSION_NTSC_1_0
		if (arg3 != -1 && g_SoundMode == SOUNDMODE_SURROUND && (arg3 & 0x80)) {
			t0 += 128;
		}
#else
		if (g_SoundMode == SOUNDMODE_SURROUND && (arg3 & 0x80)) {
			t0 += 128;
		}
#endif
	}

	if (arg4) {
		sp30.packed = arg4;

		if (sp30.hasconfig) {
			s32 index = g_AudioRussMappings[sp30.confignum].audioconfig_index;

			sp2c.packed = g_AudioRussMappings[sp30.confignum].soundnum;
			sp2c.hasconfig = false;

			arg4 = sp2c.packed;

			config = &g_AudioConfigs[index];

			if (config->unk10 != 100) {
				arg2 = arg2 * config->unk10 / 100;
			}

			if (config->unk14 != -1) {
				arg3 = config->unk14;
			}

			if (g_Vars.langfilteron && (config->flags & AUDIOCONFIGFLAG_OFFENSIVE)) {
				arg2 = 0;
			}
		}
	}

	state = sndStart(var80095200, arg4, handle, arg2, arg3, arg5, arg6, t0);

	osSetThreadPri(0, prevpri);

	return state;
}

struct sndstate *sndStart(s32 arg0, s16 sound, struct sndstate **handle, s32 arg3, s32 arg4, f32 arg5, s32 arg6, s32 arg7)
{
	union soundnumhack sp44;
	union soundnumhack sp40;
	u8 sp3f;
	u8 sp3e;
	u8 sp3d;
	u8 sp3c;
	u16 sp3a;
	u16 sp38;
	f32 sp34;

	sp3f = arg7 != -1 ? arg7 : 0;
	sp3e = arg6 != -1 ? arg6 : 1;
	sp3d = arg4 != -1 ? arg4 : 64;
	sp3a = arg3 != -1 ? arg3 : 0x7fff;
	sp34 = arg5 > 0.0f ? arg5 : 1.0f;

	sp44.packed = sound;

	if (g_SndDisabled) {
		return NULL;
	}

	sp40.packed = sp44.hasconfig ? g_AudioRussMappings[sp44.confignum].soundnum : sp44.packed;

	if (sp40.id == SFX_0037 || sp40.id == SFX_0009) {
		return NULL;
	}

	if (sndIsMp3(sp40.packed)) {
		sndStartMp3(sp40.packed, sp3a, sp3d, 0);

		if (handle != NULL) {
			*handle = NULL;
		}

		return NULL;
	}

#if VERSION >= VERSION_NTSC_1_0
	if (sp40.id < (u32)g_NumSounds) {
		return func00033820(arg0, sp40.id, sp3a, sp3d & 0x7f,
				sp34, sp3f, IS4MB() ? 0 : sp3e, handle);
	}

	return NULL;
#else
	return func00033820(arg0, sp40.id, sp3a, sp3d & 0x7f,
			sp34, sp3f, IS4MB() ? 0 : sp3e, handle);
#endif
}

const char var70053be0[] = "Snd_Play_Universal : Overriding -> Link = %d\n";

#if VERSION < VERSION_NTSC_1_0
const char var700552f0nb[] = "Snd_Play_Mpeg : sndId=%d, vol=%d, pan=%d\n";
#endif

const char var70053c10[] = "Snd_Play_Mpeg : SYSTEM IS DISABLED\n";
const char var70053c34[] = "Snd_Play_Mpeg  : Lib called -> Adr=%x\n";
const char var70053c5c[] = "Snd_Play_Mpeg  : Chunk size -> Adr=%x\n";

void sndStartMp3(s16 soundnum, s32 arg1, s32 arg2, s32 arg3)
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
				if (g_AudioConfigs[sp24.confignum].unk10 != -1) {
					arg1 = g_AudioConfigs[sp24.confignum].unk10 * 32767 / 100;
				}

				if (g_AudioConfigs[sp24.confignum].unk14 != -1) {
					arg2 = g_AudioConfigs[sp24.confignum].unk14;
				}

				// This is the same thing again
				if (g_AudioConfigs[sp24.confignum].unk14 != -1) {
					arg2 = g_AudioConfigs[sp24.confignum].unk14;
				}

				if (g_Vars.langfilteron && (g_AudioConfigs[sp24.confignum].flags & AUDIOCONFIGFLAG_OFFENSIVE)) {
					arg1 = 0;
				}
			}

			arg1 = arg1 * snd0000e9dc() / 0x7fff;

			g_SndCurMp3.romaddr = fileGetRomAddress(sp20.id);
			g_SndCurMp3.romsize = fileGetRomSizeByFileNum(sp20.id);

			func00037f08(arg1, true);
			func00037f5c(arg2, true);

			mp3PlayFile(g_SndCurMp3.romaddr, g_SndCurMp3.romsize);

			func00037f08(arg1, true);
			func00037f5c(arg2, true);

			g_SndCurMp3.sfxref.packed = sp20.packed;
			g_SndCurMp3.playing = true;
			g_SndCurMp3.responsetimer240 = -1;
			g_SndCurMp3.responsetype = MP3RESPONSETYPE_NONE;

			if (g_SndCurMp3.sfxref.unk02 == 2) {
				g_SndCurMp3.responsetype = MP3RESPONSETYPE_ACKNOWLEDGE;
			} else if (g_SndCurMp3.sfxref.unk02 == 1) {
				g_SndCurMp3.responsetype = MP3RESPONSETYPE_WHISPER;
			}

			if ((sp24.hasconfig && (g_AudioConfigs[sp24.confignum].flags & AUDIOCONFIGFLAG_04)) || (arg3 & 1)) {
				g_SndCurMp3.responsetype = MP3RESPONSETYPE_GREETING;
			}
		}
	}
}

void sndPlayNosedive(s32 seconds)
{
	g_SndNosediveDuration240 = seconds * PALDOWN(240);
	g_SndNosediveAge240 = 0;
	g_SndNosediveVolume = 0;
	g_SndNosediveHandle = NULL;
}

void sndStopNosedive(void)
{
	if (g_SndNosediveAge240 != -1) {
		g_SndNosediveAge240 = g_SndNosediveDuration240 + 1;
	}
}

void sndTickNosedive(void)
{
	f32 percentage;

	if (g_SndNosediveAge240 != -1) {
		g_SndNosediveAge240 += g_Vars.lvupdate240;

		percentage = (f32)g_SndNosediveAge240 / (f32)g_SndNosediveDuration240;

		if (percentage < 1.0f) { // less than 100% complete
			percentage += 0.44f;

			if (lvIsPaused()) {
				// Fade out volume during pause instead of stopping abruptly
				if (g_SndNosediveVolume > 0) {
					g_SndNosediveVolume -= g_Vars.diffframe240 * PALUP(80);

					if (g_SndNosediveVolume < 0) {
						g_SndNosediveVolume = 0;
					}
				}

				if (g_SndNosediveVolume) {
					sndAdjust(&g_SndNosediveHandle, 0, g_SndNosediveVolume, 64, -1, percentage, 0, -1, 1);
				} else if (g_SndNosediveHandle != NULL) {
					audioStop(g_SndNosediveHandle);
					g_SndNosediveHandle = NULL;
				}
			} else {
				// Not paused
				if (g_SndNosediveHandle == NULL) {
					sndStart(var80095200, SFX_NOSEDIVE, &g_SndNosediveHandle, -1, -1, -1, -1, -1);
				}

				// Fade in over about 2 seconds
				if (g_SndNosediveVolume < 20000) {
					g_SndNosediveVolume += g_Vars.diffframe240 * PALUP(40);

					if (g_SndNosediveVolume > 20000) {
						g_SndNosediveVolume = 20000;
					}
				}

				sndAdjust(&g_SndNosediveHandle, 0, g_SndNosediveVolume, 64, -1, percentage, 0, -1, 1);
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
				sndAdjust(&g_SndNosediveHandle, 0, g_SndNosediveVolume, 64, -1, -1, 0, -1, 1);
			} else if (g_SndNosediveHandle != NULL) {
				audioStop(g_SndNosediveHandle);
				g_SndNosediveHandle = NULL;
			}
		}
	}
}

void sndPlayUfo(s32 seconds)
{
	g_SndUfoDuration240 = seconds * PALDOWN(240);
	g_SndUfoAge240 = 0;
	g_SndUfoVolume = 0;
	g_SndUfoHandle = NULL;
}

void sndStopUfo(void)
{
	if (g_SndUfoAge240 != -1) {
		g_SndUfoAge240 = g_SndUfoDuration240 + 1;
	}
}

void sndTickUfo(void)
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

			if (lvIsPaused()) {
				// Fade out volume during pause instead of stopping abruptly
				if (g_SndUfoVolume > 0) {
					g_SndUfoVolume -= g_Vars.diffframe240 * PALUP(120);

					if (g_SndUfoVolume < 0) {
						g_SndUfoVolume = 0;
					}
				}

				if (g_SndUfoVolume) {
					sndAdjust(&g_SndUfoHandle, 0, g_SndUfoVolume, 64, -1, percentage, 0, -1, 1);
				} else if (g_SndUfoHandle != NULL) {
					audioStop(g_SndUfoHandle);
					g_SndUfoHandle = NULL;
				}
			} else {
				// Not paused
				if (g_SndUfoHandle == NULL) {
					sndStart(var80095200, SFX_UFOHUM, &g_SndUfoHandle, -1, -1, -1, -1, -1);
				}

				// Fade in over about 2.4 seconds
				if (g_SndUfoVolume < 32767) {
					g_SndUfoVolume += g_Vars.diffframe240 * PALUP(40);

					if (g_SndUfoVolume > 32767) {
						g_SndUfoVolume = 32767;
					}
				}

				sndAdjust(&g_SndUfoHandle, 0, g_SndUfoVolume, 64, -1, percentage, 0, -1, 1);
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
				sndAdjust(&g_SndUfoHandle, 0, g_SndUfoVolume, 64, -1, -1, 0, -1, 1);
			} else if (g_SndUfoHandle != NULL) {
				audioStop(g_SndUfoHandle);
				g_SndUfoHandle = NULL;
			}
		}
	}
}
