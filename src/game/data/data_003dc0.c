#include <ultra64.h>
#include "game/chr/chraicommands.h"
#include "game/game_000000.h"
#include "game/game_0601b0.h"
#include "game/game_015470.h"
#include "game/game_0dcdb0.h"
#include "game/data/data_000000.h"
#include "game/data/data_00e460.h"
#include "lib/lib_0c000.h"
#include "lib/main.h"
#include "lib/lib_3e730.h"
#include "gvars/gvars.h"
#include "stagesetup.h"
#include "types.h"

u32 var8005dda0 = 0x00000000;
u32 var8005dda4 = 0x00000000;
u32 var8005dda8 = 0x00000000;
u32 var8005ddac = 0xffffffff;
u32 var8005ddb0 = 0x00000000;
u32 var8005ddb4 = 0x00000000;
u32 var8005ddb8 = 0xffffffff;
u32 var8005ddbc = 0x00000000;
u32 var8005ddc0 = 0x00000000;
u32 var8005ddc4 = 0x00000000;
u16 g_SfxVolume = 32767;
u32 g_SoundMode = SOUNDMODE_STEREO;
u32 var8005ddd0 = 0x00000000;
u32 var8005ddd4 = 0x00000000;
u32 var8005ddd8 = 0x00000000;
u32 var8005dddc = 0x00000000;
u32 var8005dde0 = 0x00000000;

// 3e04
struct audiodefinition audiodefinitions[] = {
	/*0x0000*/ { 0x85ba, 59 },
	/*0x0001*/ { 0x85a5, 15 },
	/*0x0002*/ { 0x85a6, 15 },
	/*0x0003*/ { 0x80bb, 14 },
	/*0x0004*/ { 0x80bc, 14 },
	/*0x0005*/ { 0x8007, 14 },
	/*0x0006*/ { 0x8007, 14 },
	/*0x0007*/ { 0x80be, 14 },
	/*0x0008*/ { 0x80bf, 14 },
	/*0x0009*/ { 0x80bf, 14 },
	/*0x000a*/ { 0x80c0, 14 },
	/*0x000b*/ { 0x8007, 14 },
	/*0x000c*/ { 0x80c2, 14 },
	/*0x000d*/ { 0x80c3, 14 },
	/*0x000e*/ { 0x80c4, 14 },
	/*0x000f*/ { 0x80c5, 14 },
	/*0x0010*/ { 0x8007, 14 },
	/*0x0011*/ { 0x80c7, 14 },
	/*0x0012*/ { 0x80c8, 14 },
	/*0x0013*/ { 0x80c9, 14 },
	/*0x0014*/ { 0x80ca, 15 },
	/*0x0015*/ { 0x80cb, 15 },
	/*0x0016*/ { 0x80cc, 15 },
	/*0x0017*/ { 0x8007, 15 },
	/*0x0018*/ { 0x8007, 15 },
	/*0x0019*/ { 0x8007, 15 },
	/*0x001a*/ { 0x80d2, 15 },
	/*0x001b*/ { 0x80d3, 15 },
	/*0x001c*/ { 0x8007, 15 },
	/*0x001d*/ { 0x80c6, 14 },
	/*0x001e*/ { 0x80d6, 15 },
	/*0x001f*/ { 0x80d7, 15 },
	/*0x0020*/ { 0x80d8, 15 },
	/*0x0021*/ { 0x80db, 14 },
	/*0x0022*/ { 0x80da, 14 },
	/*0x0023*/ { 0x80bf, 14 },
	/*0x0024*/ { 0x80bf, 14 },
	/*0x0025*/ { 0x80de, 14 },
	/*0x0026*/ { 0x80e1, 15 },
	/*0x0027*/ { 0x80e2, 15 },
	/*0x0028*/ { 0x977a, 60 }, // Carrington: "Hello Joanna"
	/*0x0029*/ { 0x97b0, 60 }, // Carrington: "Joanna, it's good to see you"
	/*0x002a*/ { 0x97b1, 60 }, // Carrington: "Good day to you, Jo"
	/*0x002b*/ { 0x977c, 60 }, // Female: "Hi there"
	/*0x002c*/ { 0x9786, 60 }, // Grimshaw: "Welcome to hacker central"
	/*0x002d*/ { 0x9787, 60 }, // Grimshaw: "Hi there"
	/*0x002e*/ { 0x9788, 60 }, // Grimshaw: "Um, er, hi"
	/*0x002f*/ { 0x978c, 60 }, // Holo girl: "Hi. What can I do for you?"
	/*0x0030*/ { 0x9794, 60 }, // Hangar guy: "What do you want?"
	/*0x0031*/ { 0x9784, 60 }, // Foster: "Ah, our star agent"
	/*0x0032*/ { 0x978e, 60 }, // Male: "Hey there"
	/*0x0033*/ { 0x978f, 60 }, // Male: "Hi"
	/*0x0034*/ { 0x9790, 60 }, // Male "How's it going?"
	/*0x0035*/ { 0x977e, 60 }, // Female: "Hello"
	/*0x0036*/ { 0x977f, 60 }, // Holo girl: "Hi Jo"
	/*0x0037*/ { 0x9780, 60 }, // Holo girl: "How's it going?"
	/*0x0038*/ { 0x802e, 32 },
	/*0x0039*/ { 0x8037, 35 },
	/*0x003a*/ { 0x8037, 35 },
	/*0x003b*/ { 0x806a, 33 },
	/*0x003c*/ { 0x8037, 35 },
	/*0x003d*/ { 0x8037, 35 },
	/*0x003e*/ { 0x8037, 35 },
	/*0x003f*/ { 0x806d, 33 },
	/*0x0040*/ { 0x806e, 33 },
	/*0x0041*/ { 0x8037, 35 },
	/*0x0042*/ { 0x8037, 35 },
	/*0x0043*/ { 0x8070, 33 },
	/*0x0044*/ { 0x8071, 33 },
	/*0x0045*/ { 0x8037, 35 },
	/*0x0046*/ { 0x8037, 35 },
	/*0x0047*/ { 0x8037, 35 },
	/*0x0048*/ { 0x8037, 35 },
	/*0x0049*/ { 0x8075, 33 },
	/*0x004a*/ { 0x8037, 35 },
	/*0x004b*/ { 0x8037, 35 },
	/*0x004c*/ { 0x8079, 31 },
	/*0x004d*/ { 0x8066, 31 },
	/*0x004e*/ { 0x8037, 35 },
	/*0x004f*/ { 0x8032, 31 },
	/*0x0050*/ { 0x8037, 35 },
	/*0x0051*/ { 0x807a, 35 },
	/*0x0052*/ { 0x8059, 31 },
	/*0x0053*/ { 0x8001, 35 },
	/*0x0054*/ { 0x847e, 32 },
	/*0x0055*/ { 0x847d, 33 },
	/*0x0056*/ { 0x84f1, 32 },
	/*0x0057*/ { 0x84f2, 32 },
	/*0x0058*/ { 0x84f3, 32 },
	/*0x0059*/ { 0x84f4, 33 },
	/*0x005a*/ { 0x84f6, 33 },
	/*0x005b*/ { 0x8506, 31 },
	/*0x005c*/ { 0x84fd, 33 },
	/*0x005d*/ { 0x8504, 33 },
	/*0x005e*/ { 0x84fe, 33 },
	/*0x005f*/ { 0x8503, 33 },
	/*0x0060*/ { 0x8500, 32 },
	/*0x0061*/ { 0x8501, 32 },
	/*0x0062*/ { 0x8502, 32 },
	/*0x0063*/ { 0x85ca, 31 },
	/*0x0064*/ { 0x85cb, 31 },
	/*0x0065*/ { 0x85d2, 31 },
	/*0x0066*/ { 0x8074, 33 },
	/*0x0067*/ { 0x85eb, 35 },
	/*0x0068*/ { 0x85ec, 35 },
	/*0x0069*/ { 0x85ed, 31 },
	/*0x006a*/ { 0x85ee, 31 },
	/*0x006b*/ { 0x85ef, 33 },
	/*0x006c*/ { 0x85f0, 33 },
	/*0x006d*/ { 0x85f1, 33 },
	/*0x006e*/ { 0x85f2, 33 },
	/*0x006f*/ { 0x85f3, 33 },
	/*0x0070*/ { 0x85f4, 33 },
	/*0x0071*/ { 0x8508, 31 },
	/*0x0072*/ { 0x850a, 31 },
	/*0x0073*/ { 0x8076, 33 },
	/*0x0074*/ { 0x85f5, 30 },
	/*0x0075*/ { 0x8509, 33 },
	/*0x0076*/ { 0x8045, 45 },
	/*0x0077*/ { 0x8046, 45 },
	/*0x0078*/ { 0x8047, 25 },
	/*0x0079*/ { 0x8048, 45 },
	/*0x007a*/ { 0x80f0, 45 },
	/*0x007b*/ { 0x80ef, 45 },
	/*0x007c*/ { 0x8049, 45 },
	/*0x007d*/ { 0x804a, 45 },
	/*0x007e*/ { 0x804b, 45 },
	/*0x007f*/ { 0x80d9, 45 },
	/*0x0080*/ { 0x804c, 45 },
	/*0x0081*/ { 0x80e7, 45 },
	/*0x0082*/ { 0x80e6, 45 },
	/*0x0083*/ { 0x80e0, 45 },
	/*0x0084*/ { 0x80dc, 45 },
	/*0x0085*/ { 0x80b9, 45 },
	/*0x0086*/ { 0x80d4, 45 },
	/*0x0087*/ { 0x80d0, 45 },
	/*0x0088*/ { 0x80d1, 45 },
	/*0x0089*/ { 0x8078, 45 },
	/*0x008a*/ { 0x80dd, 45 },
	/*0x008b*/ { 0x8003, 45 },
	/*0x008c*/ { 0x802d, 21 },
	/*0x008d*/ { 0x807b, 21 },
	/*0x008e*/ { 0x807c, 21 },
	/*0x008f*/ { 0x807d, 21 },
	/*0x0090*/ { 0x807e, 21 },
	/*0x0091*/ { 0x807f, 21 },
	/*0x0092*/ { 0x8080, 21 },
	/*0x0093*/ { 0x8081, 21 },
	/*0x0094*/ { 0x8082, 21 },
	/*0x0095*/ { 0x8083, 21 },
	/*0x0096*/ { 0x8084, 21 },
	/*0x0097*/ { 0x8085, 21 },
	/*0x0098*/ { 0x80b4, 18 },
	/*0x0099*/ { 0x80b5, 18 },
	/*0x009a*/ { 0x80b6, 17 },
	/*0x009b*/ { 0x80a9, 18 },
	/*0x009c*/ { 0x80aa, 18 },
	/*0x009d*/ { 0x80ab, 17 },
	/*0x009e*/ { 0x80ac, 18 },
	/*0x009f*/ { 0x80ad, 18 },
	/*0x00a0*/ { 0x80ae, 17 },
	/*0x00a1*/ { 0x80b1, 18 },
	/*0x00a2*/ { 0x80b2, 18 },
	/*0x00a3*/ { 0x80b3, 18 },
	/*0x00a4*/ { 0x818a, 19 },
	/*0x00a5*/ { 0xefdd, 19 },
	/*0x00a6*/ { 0x805f, 32 },
	/*0x00a7*/ { 0x8060, 32 },
	/*0x00a8*/ { 0x8061, 32 },
	/*0x00a9*/ { 0x8004, 32 },
	/*0x00aa*/ { 0x80f1, 32 },
	/*0x00ab*/ { 0x80f3, 32 },
	/*0x00ac*/ { 0x8055, 16 },
	/*0x00ad*/ { 0x8056, 16 },
	/*0x00ae*/ { 0x8057, 16 },
	/*0x00af*/ { 0x85f7, 52 },
	/*0x00b0*/ { 0x8127, 29 },
	/*0x00b1*/ { 0x8128, 29 },
	/*0x00b2*/ { 0x8129, 29 },
	/*0x00b3*/ { 0x812a, 29 },
	/*0x00b4*/ { 0x812b, 29 },
	/*0x00b5*/ { 0x812c, 29 },
	/*0x00b6*/ { 0x812d, 50 },
	/*0x00b7*/ { 0x812e, 50 },
	/*0x00b8*/ { 0x8138, 50 },
	/*0x00b9*/ { 0x8138, 28 },
	/*0x00ba*/ { 0x812f, 51 },
	/*0x00bb*/ { 0x8151, 51 },
	/*0x00bc*/ { 0x8154, 51 },
	/*0x00bd*/ { 0x8157, 51 },
	/*0x00be*/ { 0x815a, 51 },
	/*0x00bf*/ { 0x8132, 51 },
	/*0x00c0*/ { 0x8139, 51 },
	/*0x00c1*/ { 0x813f, 51 },
	/*0x00c2*/ { 0x8145, 51 },
	/*0x00c3*/ { 0x814b, 51 },
	/*0x00c4*/ { 0x8161, 4  },
	/*0x00c5*/ { 0x8162, 4  },
	/*0x00c6*/ { 0x8163, 4  },
	/*0x00c7*/ { 0x8164, 4  },
	/*0x00c8*/ { 0x8165, 4  },
	/*0x00c9*/ { 0x8166, 4  },
	/*0x00ca*/ { 0x8167, 4  },
	/*0x00cb*/ { 0x8168, 4  },
	/*0x00cc*/ { 0x8169, 4  },
	/*0x00cd*/ { 0x816a, 4  },
	/*0x00ce*/ { 0x816b, 4  },
	/*0x00cf*/ { 0x816c, 4  },
	/*0x00d0*/ { 0x816d, 4  },
	/*0x00d1*/ { 0x816e, 4  },
	/*0x00d2*/ { 0x816f, 4  },
	/*0x00d3*/ { 0x8170, 4  },
	/*0x00d4*/ { 0x8171, 4  },
	/*0x00d5*/ { 0x8172, 4  },
	/*0x00d6*/ { 0x8173, 4  },
	/*0x00d7*/ { 0x8174, 4  },
	/*0x00d8*/ { 0x8175, 4  },
	/*0x00d9*/ { 0x8176, 4  },
	/*0x00da*/ { 0x8177, 4  },
	/*0x00db*/ { 0x8178, 4  },
	/*0x00dc*/ { 0x8179, 4  },
	/*0x00dd*/ { 0x817a, 4  },
	/*0x00de*/ { 0x817b, 4  },
	/*0x00df*/ { 0x817c, 4  },
	/*0x00e0*/ { 0x817d, 4  },
	/*0x00e1*/ { 0x817e, 4  },
	/*0x00e2*/ { 0x817f, 4  },
	/*0x00e3*/ { 0x8180, 4  },
	/*0x00e4*/ { 0x804d, 4  },
	/*0x00e5*/ { 0x804e, 4  },
	/*0x00e6*/ { 0x85f8, 5  },
	/*0x00e7*/ { 0x85f9, 5  },
	/*0x00e8*/ { 0x85fa, 5  },
	/*0x00e9*/ { 0x85fb, 5  },
	/*0x00ea*/ { 0x85fc, 6  },
	/*0x00eb*/ { 0x85fd, 6  },
	/*0x00ec*/ { 0x85fe, 6  },
	/*0x00ed*/ { 0x85ff, 6  },
	/*0x00ee*/ { 0x8600, 4  },
	/*0x00ef*/ { 0x8601, 4  },
	/*0x00f0*/ { 0x8602, 4  },
	/*0x00f1*/ { 0x8603, 4  },
	/*0x00f2*/ { 0x8604, 4  },
	/*0x00f3*/ { 0x8605, 4  },
	/*0x00f4*/ { 0x8606, 4  },
	/*0x00f5*/ { 0x8606, 4  },
	/*0x00f6*/ { 0x81d9, 61 },
	/*0x00f7*/ { 0x8267, 2  },
	/*0x00f8*/ { 0x8268, 2  },
	/*0x00f9*/ { 0x8286, 2  },
	/*0x00fa*/ { 0x8288, 2  },
	/*0x00fb*/ { 0x8291, 2  },
	/*0x00fc*/ { 0x829f, 2  },
	/*0x00fd*/ { 0x82a1, 2  },
	/*0x00fe*/ { 0x8af9, 47 }, // Cass: "You've become quite an annoyance"
	/*0x00ff*/ { 0x8afa, 47 }, // Cass: "We meet again, girl"
	/*0x0100*/ { 0x8afb, 47 }, // Cass: "Good night, Miss Dark"
	/*0x0101*/ { 0x92fc, 47 }, // Cass: "Get her!"
	/*0x0102*/ { 0x92fd, 47 }, // Cass: (laughing)
	/*0x0103*/ { 0x9285, 2  }, // Scientist: "Who the hell are you?"
	/*0x0104*/ { 0x9306, 48 }, // Programmer: "Yes, yes, I agree. Personality..."
	/*0x0105*/ { 0x9307, 48 }, // Programmer: "No. I can start the process..."
	/*0x0106*/ { 0x9308, 48 }, // Programmer: "I'll begin at once. Goodbye"
	/*0x0107*/ { 0x9309, 48 }, // Programmer: "Security, help me!"
	/*0x0108*/ { 0x930a, 48 }, // Programmer: "Help! Help!"
	/*0x0109*/ { 0x8435, 49 },
	/*0x010a*/ { 0x81b5, 7  },
	/*0x010b*/ { 0x81b6, 8  },
	/*0x010c*/ { 0x81b5, 9  },
	/*0x010d*/ { 0x81b6, 10 },
	/*0x010e*/ { 0x85f3, 11 },
	/*0x010f*/ { 0x81b5, 12 },
	/*0x0110*/ { 0x81b6, 13 },
	/*0x0111*/ { 0x81b7, 20 },
	/*0x0112*/ { 0x81b8, 20 },
	/*0x0113*/ { 0x81c7, 20 },
	/*0x0114*/ { 0x8037, 20 },
	/*0x0115*/ { 0x81b7, 56 },
	/*0x0116*/ { 0x81b9, 0  },
	/*0x0117*/ { 0x81ba, 0  },
	/*0x0118*/ { 0x81bb, 0  },
	/*0x0119*/ { 0x81cb, 36 },
	/*0x011a*/ { 0x81cb, 37 },
	/*0x011b*/ { 0x81cb, 38 },
	/*0x011c*/ { 0x81c6, 55 },
	/*0x011d*/ { 0x9278, 47 }, // "That's not how it goes"
	/*0x011e*/ { 0x9279, 47 }, // "Give it to me. You're doing it wrong"
	/*0x011f*/ { 0x927a, 47 }, // "Oh no, we're too late"
	/*0x0120*/ { 0x927b, 47 }, // "Yes it is"
	/*0x0121*/ { 0x927c, 47 }, // "Stop annoying me"
	/*0x0122*/ { 0x927d, 47 }, // "She's here!"
	/*0x0123*/ { 0x9277, 47 }, // "Will you just hurry up?"
	/*0x0124*/ { 0x82fd, 2  }, // "Holy..."
	/*0x0125*/ { 0x82fe, 2  }, // "What the hell?"
	/*0x0126*/ { 0x8300, 2  }, // "Oh my god"
	/*0x0127*/ { 0x8303, 2  }, // "Oh god I'm hit"
	/*0x0128*/ { 0x830a, 2  }, // "Oh my god"
	/*0x0129*/ { 0x8313, 62 }, // "Noooo!"
	/*0x012a*/ { 0x8314, 2  }, // "Oh god he's dead!"
	/*0x012b*/ { 0x832e, 2  }, // "Bloody stupid gun"
	/*0x012c*/ { 0x8330, 2  }, // "Damn it"
	/*0x012d*/ { 0x8333, 2  }, // "Damn, she's good"
	/*0x012e*/ { 0x8334, 2  }, // "Cover my ass"
	/*0x012f*/ { 0x834c, 62 }, // Death scream
	/*0x0130*/ { 0x83a3, 2  }, // Female: "Damn she's good"
	/*0x0131*/ { 0x83b9, 2  }, // Female: "My god"
	/*0x0132*/ { 0x83c7, 2  }, // "Geez, that hurt"
	/*0x0133*/ { 0x83cf, 2  }, // "Damn it, I'm taking fire"
	/*0x0134*/ { 0x83d2, 2  }, // "God damn it"
	/*0x0135*/ { 0x83d4, 2  }, // "Holy moley"
	/*0x0136*/ { 0x83f3, 2  }, // "Damn, missed again"
	/*0x0137*/ { 0x83f5, 2  }, // "Damn"
	/*0x0138*/ { 0x83f6, 2  }, // "Hell, she's good"
	/*0x0139*/ { 0x8400, 2  }, // "Let's get the hell out of here"
	/*0x013a*/ { 0x8411, 62 }, // "Noooo!"
	/*0x013b*/ { 0x8413, 2  }, // "Shoot, damn it"
	/*0x013c*/ { 0x8414, 2  }, // "Oh god, I'm dying"
	/*0x013d*/ { 0x8422, 2  }, // "God, run!"
	/*0x013e*/ { 0x8432, 33 },
	/*0x013f*/ { 0x843c, 58 },
	/*0x0140*/ { 0x843d, 58 },
	/*0x0141*/ { 0x84ab, 58 },
	/*0x0142*/ { 0x843d, 58 },
	/*0x0143*/ { 0x81b7, 58 },
	/*0x0144*/ { 0x8477, 57 },
	/*0x0145*/ { 0x8478, 57 },
	/*0x0146*/ { 0x81c2, 54 },
	/*0x0147*/ { 0x8479, 54 },
	/*0x0148*/ { 0x81c3, 54 },
	/*0x0149*/ { 0x81c4, 54 },
	/*0x014a*/ { 0x8443, 2  }, // Civilian: "Oh my god"
	/*0x014b*/ { 0x844e, 2  }, // "What the hell was that?"
	/*0x014c*/ { 0x843c, 63 },
	/*0x014d*/ { 0x847c, 63 },
	/*0x014e*/ { 0x843d, 63 },
	/*0x014f*/ { 0xf2ad, 1  }, // "Joanna, this is Jonathan. You're in grave danger"
	/*0x0150*/ { 0xf2ae, 1  }, // "They've flooded the area with nerge gas"
	/*0x0151*/ { 0xf2af, 1  }, // "Get our friend to the containment lab. There's a hiding place there"
	/*0x0152*/ { 0xd2b0, 1  }, // "I'll contact you when you get there. Good luck"
	/*0x0153*/ { 0xf2b1, 1  }, // "Good work Jo. We need to meet up. They're getting suspicious of me"
	/*0x0154*/ { 0xd2b2, 1  }, // "Use the maintenance hatch I've opened in one of the containment labs. Hurry"
	/*0x0155*/ { 0x92b8, 2  }, // "Damn it Joanna, cover me!"
	/*0x0156*/ { 0x9b30, 2  }, // "Oh my god, a gun?!"
	/*0x0157*/ { 0x9b27, 47 }, // "So you got here at last"
	/*0x0158*/ { 0x9b28, 47 }, // "Hey, you're not, uh, security alert!"
	/*0x0159*/ { 0x9b29, 47 }, // "No guns allowed in here. Put your weapon away"
	/*0x015a*/ { 0x9b2a, 47 }, // "I won't tell you again. Lose the weapon"
	/*0x015b*/ { 0x9b2b, 47 }, // "Right. I'm calling security"
	/*0x015c*/ { 0x9b2c, 47 }, // "Everyone's been waiting for you"
	/*0x015d*/ { 0x9a9d, 60 }, // "How's things?"
	/*0x015e*/ { 0x9a9e, 60 }, // "Hey there"
	/*0x015f*/ { 0x9a9f, 60 }, // "Hi. How are you?"
	/*0x0160*/ { 0x8037, 4  },
	/*0x0161*/ { 0x9271, 60 }, // Female: "Good afternoon"
	/*0x0162*/ { 0x9275, 2  }, // Female: "Oh my god!"
	/*0x0163*/ { 0x9acc, 60 }, // "Hi there"
	/*0x0164*/ { 0x9acd, 60 }, // "How's things"
	/*0x0165*/ { 0x9ad4, 60 }, // "Hello"
	/*0x0166*/ { 0x9ad5, 60 }, // "Hey, what's up?"
	/*0x0167*/ { 0x84c8, 2  }, // "What the hell?"
	/*0x0168*/ { 0x84cd, 2  }, // "Geez"
	/*0x0169*/ { 0x84ad, 46 },
	/*0x016a*/ { 0x8507, 27 },
	/*0x016b*/ { 0x84ee, 16 },
	/*0x016c*/ { 0x84ef, 16 },
	/*0x016d*/ { 0x84f0, 16 },
	/*0x016e*/ { 0x92c8, 2  }, // President: "What the hell was that?"
	/*0x016f*/ { 0x92c9, 2  }, // Trent: "How the hell did you get on board?"
	/*0x0170*/ { 0xb3a0, 1  }, // Carrington: "We're getting a positive reading. The internal comms hub is nearby"
	/*0x0171*/ { 0xb3a1, 1  }, // Carrington: "You're on the same floor as Cassandra's office"
	/*0x0172*/ { 0xd3a3, 1  }, // Carrington: "The basement elevator must be around there somewhere"
	/*0x0173*/ { 0xd3a4, 1  }, // Carrington: "That's the highest security sector. Dr Caroll has got to be nearby"
	/*0x0174*/ { 0xd3a6, 1  }, // Grimshaw: "Reprogram the cleaning bot. It'll give you a way in"
	/*0x0175*/ { 0xd3a7, 1  }, // Carrington: "Get out Jo! The levels are too high. Use the camspy"
	/*0x0176*/ { 0xd3a8, 1  }, // Carrington: "They've locked down the ground floor. Get to the elevator"
	/*0x0177*/ { 0xd3a9, 1  }, // Carrington: "That copter needs to be taken out of the jumpship will get shut down"
	/*0x0178*/ { 0xd3ab, 1  }, // Carrington: "Don't keep the jumpship waiting. Get back to the landing pad"
	/*0x0179*/ { 0xd3b0, 1  }, // Carrington: "The only place we could secure the equipment was a storm drain"
	/*0x017a*/ { 0xd3b2, 1  }, // Grimshaw: "Reprogram that taxi. It's a mark 2 and should be compatible"
	/*0x017b*/ { 0xd3b3, 1  }, // Carrington: The carpark lift is your only point of ingress"
	/*0x017c*/ { 0xb3b6, 1  }, // Grimshaw: "The safe's heavily encrypted. The decoder's going to take a little longer"
	/*0x017d*/ { 0xd3b8, 1  }, // Carrington: "The air intercept radar is controlled from that bunker"
	/*0x017e*/ { 0xd3ba, 1  }, // Carrington: "The hangar lift is the other side of that huge door"
	/*0x017f*/ { 0xd3bb, 1  }, // Jon: "Careful with that trigger finger, Agent Dark. You're closing in on my position"
	/*0x0180*/ { 0xb3bd, 1  }, // Carrington: "The temperature's dropping. You must be close to the cryo room"
	/*0x0181*/ { 0xd3bf, 1  }, // Carrington: "There he is Jo. Hurry or you'll be too late"
	/*0x0182*/ { 0xb3c4, 1  }, // Carrington: "Now's your chance. Grab the stewardess's bag and get her uniform"
	/*0x0183*/ { 0xb3c5, 1  }, // Carrington: "Use that case to conceal your equipment"
	/*0x0184*/ { 0xb3c6, 1  }, // Carrington: "The case will get stopped unless you do something"
	/*0x0185*/ { 0xb3c9, 1  }, // Carrington: "The president's room is on this level, Joanna"
	/*0x0186*/ { 0xb3ca, 1  }, // Carrington: "Something's wrong. You have to get to the cockpit"
	/*0x0187*/ { 0x8594, 4  }, // Footstep
	/*0x0188*/ { 0x8595, 4  }, // Footstep
	/*0x0189*/ { 0x8596, 4  }, // Footstep
	/*0x018a*/ { 0x8597, 4  }, // Footstep
	/*0x018b*/ { 0x8598, 4  }, // Footstep
	/*0x018c*/ { 0x8599, 4  }, // Footstep
	/*0x018d*/ { 0x859a, 4  }, // Footstep
	/*0x018e*/ { 0x859b, 4  }, // Footstep
	/*0x018f*/ { 0x85a0, 4  }, // Footstep
	/*0x0190*/ { 0x85a1, 4  }, // Footstep
	/*0x0191*/ { 0x85a2, 4  }, // Footstep
	/*0x0192*/ { 0x85a3, 4  }, // Footstep
	/*0x0193*/ { 0xf310, 1  }, // Carrington: "Joanna. We're under attack"
	/*0x0194*/ { 0xd311, 1  }, // Carrington: "Get the guns back online. Hurry"
	/*0x0195*/ { 0xf312, 1  }, // Carrington: "The Skedar have taken hostages"
	/*0x0196*/ { 0xd313, 1  }, // Carrington: "Get up to the offices and save them"
	/*0x0197*/ { 0xf314, 1  }, // Carrington: "They're using a new form of shield technology"
	/*0x0198*/ { 0xd315, 1  }, // Carrington: "Foster was working on a new weapon which may be useful"
	/*0x0199*/ { 0xf316, 3  }, // Carrington: "Damn it, my office. If they get access..."
	/*0x019a*/ { 0xd317, 1  }, // Carrington: "Get there first, Jo and destroy the files"
	/*0x019b*/ { 0xf318, 1  }, // Carrington: "Things are desparate. They've planted a bomb"
	/*0x019c*/ { 0xd319, 1  }, // Carrington: "Find it and get it out of the building"
	/*0x019d*/ { 0xf31a, 1  }, // Carrington: "Well done Joanna. We're nearly clear"
	/*0x019e*/ { 0xd31b, 1  }, // Carrington: "The last dropship is waiting for you. Hurry"
	/*0x019f*/ { 0xf293, 1  }, // Grimshaw: "Joanna, it's Grimshaw. We've got hackers at..."
	/*0x01a0*/ { 0xf2df, 1  }, // Elvis: "We're outside, Joanna. Get the shields down and we can help you"
	/*0x01a1*/ { 0xf2e0, 1  }, // Elvis: "You've got to open the hanger doors so we can dock"
	/*0x01a2*/ { 0xd4ea, 1  }, // Carrington: "Stand back Joanna. We'll create your escape route"
	/*0x01a3*/ { 0x8d24, 2  }, // Cass: "Get the hell out of my office"
	/*0x01a4*/ { 0x9d62, 47 }, // Elvis: "Joanna, what took you so long? Follow me. Let's get off this old tub"
	/*0x01a5*/ { 0x84aa, 43 },
	/*0x01a6*/ { 0x81cf, 41 },
	/*0x01a7*/ { 0x858f, 40 },
	/*0x01a8*/ { 0x80d5, 39 }, // Lift mechanical sound
	/*0x01a9*/ { 0x80ec, 39 }, // Lift mechanical sound
	/*0x01aa*/ { 0x80ed, 40 }, // Lift mechanical sound
	/*0x01ab*/ { 0x80d5, 41 }, // Lift mechanical sound
	/*0x01ac*/ { 0x80ec, 41 }, // Lift mechanical sound
	/*0x01ad*/ { 0x80ed, 42 }, // Lift mechanical sound
	/*0x01ae*/ { 0x80d5, 41 }, // Lift mechanical sound
	/*0x01af*/ { 0x80ec, 41 }, // Lift mechanical sound
	/*0x01b0*/ { 0x803a, 41 }, // Lift call
	/*0x01b1*/ { 0x84e8, 43 }, // Lift mechanical sound
	/*0x01b2*/ { 0x84e9, 43 }, // Lift mechanical sound
	/*0x01b3*/ { 0x80cd, 42 }, // Lift mechanical sound
	/*0x01b4*/ { 0x80ce, 42 }, // Lift mechanical sound
	/*0x01b5*/ { 0x8039, 42 }, // Lift mechanical sound
	/*0x01b6*/ { 0x80cd, 44 }, // Lift mechanical sound
	/*0x01b7*/ { 0x80db, 16 }, // Lift roller door
	/*0x01b8*/ { 0x80da, 16 }, // Lift roller door
	/*0x01b9*/ { 0xf41c, 2  }, // Joanna: "Oh my god"
	/*0x01ba*/ { 0xf434, 2  }, // Lab guy: "What the hell do you think you're doing? This is supposed..."
	/*0x01bb*/ { 0xf44f, 2  }, // President: "Damn it man. I say no and I mean no..."
	/*0x01bc*/ { 0x0000, 0  },
};

// 44f8
struct audioconfig audioconfigs[] = {
	{ /* 0*/  200, 1000, 1200, -1, 100, -1,   0, 0x00 },
	{ /* 1*/  400, 2500, 3000, -1, 100, 48,   0, 0x20 },
	{ /* 2*/  400, 2500, 3000, -1, 100, -1,   0, 0x10 },
	{ /* 3*/  400, 2500, 3000, -1, 100, 48,   0, 0x30 },
	{ /* 4*/  200, 1000, 1200, -1, 100, -1,   0, 0x00 },
	{ /* 5*/  200, 1000, 1200, -1, 100, -1,   0, 0x00 },
	{ /* 6*/  200, 1000, 1200, -1, 100, -1,   0, 0x00 },
	{ /* 7*/ 1000, 3500, 4000, -1, 100, -1, 120, 0x09 },
	{ /* 8*/ 1000, 2500, 3000, -1, 100, -1,  30, 0x09 },
	{ /* 9*/ 1000, 3500, 4000, -1, 100, -1, 120, 0x09 },
	{ /*10*/ 1000, 2500, 3000, -1, 100, -1,  30, 0x09 },
	{ /*11*/ 1600, 3000, 3500, -1, 100, -1,   0, 0x09 },
	{ /*12*/  400, 1100, 1400, -1, 100, -1, 140, 0x09 },
	{ /*13*/  400, 1100, 1400, -1, 100, -1,   0, 0x09 },
	{ /*14*/  300, 1200, 1250, -1, 100, -1,   0, 0x01 },
	{ /*15*/  500, 1800, 1900, -1, 100, -1,   0, 0x01 },
	{ /*16*/ 1000, 2700, 2900, -1, 100, -1,   0, 0x01 },
	{ /*17*/ 1500, 3000, 4000, -1, 100, -1,   0, 0x01 },
	{ /*18*/ 2500, 4900, 5000, -1, 100, -1,   0, 0x01 },
	{ /*19*/ 5500, 5600, 5700, -1, 100, -1,   0, 0x21 },
	{ /*20*/   20,  400,  500, -1, 100, -1,   0, 0x00 },
	{ /*21*/  300, 1700, 2000, -1, 100, -1,   0, 0x00 },
	{ /*22*/  600, 3500, 5000, -1, 100, -1,   0, 0x00 },
	{ /*23*/  600, 3500, 5000, -1, 100, -1,   0, 0x00 },
	{ /*24*/  600, 3500, 5000, -1, 100, -1,   0, 0x00 },
	{ /*25*/  600, 2500, 3000, -1, 100, -1,   0, 0x00 },
	{ /*26*/ 1500, 4900, 5500, -1, 100, -1, 100, 0x01 },
	{ /*27*/ 5500, 5740, 5800, -1, 100, -1, 100, 0x01 },
	{ /*28*/  250, 1000, 1300,  2, 100, -1, 120, 0x01 },
	{ /*29*/  200, 2600, 3000, -1, 100, -1,   0, 0x00 },
	{ /*30*/  200,  750,  850, -1, 100, -1,   0, 0x00 },
	{ /*31*/  600, 2000, 3000, -1, 100, -1,   0, 0x00 },
	{ /*32*/  500, 1500, 1800, -1, 100, -1,   0, 0x00 },
	{ /*33*/  800, 2500, 3000, -1, 100, -1,   0, 0x00 },
	{ /*34*/  400, 1500, 2000, -1, 100, -1,   0, 0x00 },
	{ /*35*/ 1000, 3500, 5000, -1, 100, -1,   0, 0x01 },
	{ /*36*/   50,  225,  250, -1, 100, -1,   0, 0x01 },
	{ /*37*/   50,  225,  250, -1, 100, -1,   0, 0x01 },
	{ /*38*/ 2000, 2500, 2700, -1,  50, -1,   0, 0x09 },
	{ /*39*/  300, 1000, 1200, -1, 100, -1,   0, 0x01 },
	{ /*40*/  300, 1000, 1200, -1, 100, -1, 100, 0x01 },
	{ /*41*/  600, 1500, 1800, -1, 100, -1,   0, 0x01 },
	{ /*42*/  600, 1500, 1800, -1, 100, -1, 100, 0x01 },
	{ /*43*/  800, 2600, 3500, -1, 100, -1,   0, 0x01 },
	{ /*44*/  800, 2600, 3500, -1, 100, -1, 100, 0x01 },
	{ /*45*/  200,  800, 1000, -1, 100, -1,   0, 0x00 },
	{ /*46*/  200,  700, 1000, -1, 100, -1,   0, 0x00 },
	{ /*47*/ 1000, 2500, 3000, -1, 100, -1,   0, 0x00 },
	{ /*48*/  500, 1400, 1500, -1, 100, -1,   0, 0x00 },
	{ /*49*/  500, 2000, 2200, -1, 100, -1,   0, 0x00 },
	{ /*50*/  400, 2500, 3000, -1,  50, -1,   0, 0x00 },
	{ /*51*/  400, 2500, 3000, -1,  75, -1,   0, 0x00 },
	{ /*52*/  200,  500,  800, -1, 100, -1, 100, 0x00 },
	{ /*53*/ 1000, 1100, 1600, -1, 100, -1,   0, 0x00 },
	{ /*54*/  300, 1300, 1500, -1, 100, -1,   0, 0x01 },
	{ /*55*/  300, 1300, 1500, -1, 100, -1, 200, 0x01 },
	{ /*56*/  250,  600,  900, -1, 100, -1, 200, 0x01 },
	{ /*57*/   50,  180,  250, -1, 100, -1, 200, 0x01 },
	{ /*58*/  100,  400,  600, -1, 100, -1, 200, 0x01 },
	{ /*59*/  700, 1100, 1400, -1, 100, -1, 200, 0x01 },
	{ /*60*/  400, 2500, 3000, -1, 100, -1,   0, 0x04 },
	{ /*61*/  300,  900, 1100, -1, 100, -1,   0, 0x00 },
	{ /*62*/ 1000, 2500, 3000, -1, 100, -1,   0, 0x08 },
	{ /*63*/  400, 1000, 1200, -1, 100, -1,   0, 0x00 },
};

u32 var8005ecd8 = 0x00000000;
u32 var8005ecdc = 0x00000000;
u32 var8005ece0 = 0x00000000;
u32 var8005ece4 = 0x00000000;
u32 var8005ece8 = 0x00000000;
u32 var8005ecec = 0x00000000;
u32 var8005ecf0 = 0x00000000;
u32 var8005ecf4 = 0x00000000;
u32 var8005ecf8 = 0x66655998;
u32 var8005ecfc = 0x5fff4ccc;
u32 var8005ed00 = 0x5fff2ccc;
u32 var8005ed04 = 0x59986665;
u32 var8005ed08 = 0x4ccc5998;
u32 var8005ed0c = 0x59985998;
u32 var8005ed10 = 0x5fff6665;
u32 var8005ed14 = 0x66655fff;
u32 var8005ed18 = 0x59986665;
u32 var8005ed1c = 0x5fff5fff;
u32 var8005ed20 = 0x5fff6665;
u32 var8005ed24 = 0x5fff5fff;
u32 var8005ed28 = 0x5fff7332;
u32 var8005ed2c = 0x5fff6665;
u32 var8005ed30 = 0x5fff5998;
u32 var8005ed34 = 0x59985332;
u32 var8005ed38 = 0x53325fff;
u32 var8005ed3c = 0x33324ccc;
u32 var8005ed40 = 0x5fff4ccc;
u32 var8005ed44 = 0x3fff5fff;
u32 var8005ed48 = 0x5fff5fff;
u32 var8005ed4c = 0x5fff4ccc;
u32 var8005ed50 = 0x4ccc4ccc;
u32 var8005ed54 = 0x4ccc4ccc;
u32 var8005ed58 = 0x4ccc4ccc;
u32 var8005ed5c = 0x5fff5fff;
u32 var8005ed60 = 0x5fff5fff;
u32 var8005ed64 = 0x5fff5fff;
u32 var8005ed68 = 0x5fff4ccc;
u32 var8005ed6c = 0x5fff5fff;
u32 var8005ed70 = 0x5fff5fff;
u32 var8005ed74 = 0x5fff5fff;
u32 var8005ed78 = 0x5fff4ccc;
u32 var8005ed7c = 0x4ccc4ccc;
u32 var8005ed80 = 0x4ccc4ccc;
u32 var8005ed84 = 0x4ccc7332;
u32 var8005ed88 = 0x73327332;
u32 var8005ed8c = 0x4ccc3c28;
u32 var8005ed90 = 0x4ccc4ccc;
u32 var8005ed94 = 0x4ccc4ccc;
u32 var8005ed98 = 0x4ccc4ccc;
u32 var8005ed9c = 0x4ccc4ccc;
u32 var8005eda0 = 0x4ccc4ccc;
u32 var8005eda4 = 0x4ccc4ccc;
u32 var8005eda8 = 0x73327332;
u32 var8005edac = 0x4ccc4ccc;
u32 var8005edb0 = 0x4ccc4ccc;
u32 var8005edb4 = 0x4ccc6665;
u32 var8005edb8 = 0x4ccc4ccc;
u32 var8005edbc = 0x4ccc4ccc;
u32 var8005edc0 = 0x6ccb5fff;
u32 var8005edc4 = 0x59987998;
u32 var8005edc8 = 0x59985998;
u32 var8005edcc = 0x66655fff;
u32 var8005edd0 = 0x5fff7332;
u32 var8005edd4 = 0x73327332;
u32 var8005edd8 = 0x73327332;
u32 var8005eddc = 0x4ccc6665;
u32 var8005ede0 = 0x66656665;
u32 var8005ede4 = 0x4ccc6ccb;
u32 var8005ede8 = 0xffff0000;
u32 var8005edec = 0xffffffff;
u32 var8005edf0 = 0xffffffff;
u32 var8005edf4 = 0x00000000;
u32 var8005edf8 = 0x00000000;
u32 var8005edfc = 0x00000000;

// 4e20
u64 rand_seed = 0xab8d9f7781280783;

u32 var8005ee08 = 0x00000000;
u32 var8005ee0c = 0x00000000;
u32 var8005ee10 = 0x00000001;
u32 var8005ee14 = 0x00000000;
u32 var8005ee18 = 0x00000000;
u32 var8005ee1c = 0x00000000;
u32 var8005ee20 = 0x00000000;
u32 var8005ee24 = 0x00000000;
u32 var8005ee28 = 0x00000000;
u32 var8005ee2c = 0x00000000;
u32 var8005ee30 = 0x00000000;
u32 var8005ee34 = 0x00000000;
u32 var8005ee38 = 0x00000000;
u32 var8005ee3c = 0x00000000;
u32 var8005ee40 = 0x00000000;
u32 var8005ee44 = 0x00000000;
u32 var8005ee48 = 0x00000000;
u32 var8005ee4c = 0x00000000;
u32 var8005ee50 = 0x00000000;
u32 var8005ee54 = 0x00000000;
u32 var8005ee58 = 0x00000000;
u32 var8005ee5c = 0x00000000;
struct contdata *var8005ee60 = &var80099a60;
u32 var8005ee64 = 0x00000000;
u32 var8005ee68 = 0x00000000;
u32 var8005ee6c[4] = {0};
u32 var8005ee7c[4] = {0};
u32 var8005ee8c = 0x00000000;
u32 var8005ee90 = 0x00000000;
u32 var8005ee94 = 0x00000000;
u32 var8005ee98 = 0x00000000;
u32 var8005ee9c = 0x00000000;
u32 var8005eea0 = 0x00000000;
u32 var8005eea4 = 0x00000000;
u32 var8005eea8 = 0x00000000;
u8 var8005eeac = 0;
u32 var8005eeb0 = 0x00000000;
u32 var8005eeb4 = 0x00000000;
u32 var8005eeb8 = 0x00000001;
u32 var8005eebc = 0x00000000;
u32 var8005eec0 = 0x00000001;
u32 var8005eec4 = 0x00000000;
u32 var8005eec8 = 0x00000000;
u32 var8005eecc = 0x00000000;
u32 var8005eed0 = 0x00000000;
u32 var8005eed4 = 0x00000000;
u32 var8005eed8 = 0x00000000;
u32 var8005eedc = 0x00000001;
u32 var8005eee0 = 0x00000000;
u32 var8005eee4 = 0xffffffff;
u32 var8005eee8 = 0x00000000;
u32 var8005eeec = 0x00000000;
u32 var8005eef0 = 0x00000001;
u32 var8005eef4 = 0x00000000;
u32 var8005eef8 = 0x00000000;
u32 var8005eefc = 0x00000000;
u32 var8005ef00 = 0xff000000;
u32 var8005ef04 = 0x00000000;
u32 var8005ef08 = 0x00000000;
u32 var8005ef0c = 0x00000000;
u32 var8005ef10 = 0x47800000;
u32 var8005ef14 = 0x47800000;
u32 var8005ef18 = 0x00000000;
u32 var8005ef1c = 0x00000000;
u32 var8005ef20 = 0xfe000000;
u32 var8005ef24 = 0x00000000;
u32 var8005ef28 = 0x00000000;
u32 var8005ef2c = 0x00000000;
s32 g_NumGlobalAilists = 0;
s32 g_NumLvAilists = 0;
u32 var8005ef38 = 0x00000000;
u32 var8005ef3c = 0x00000000;
u32 var8005ef40 = 0x00040800;
u32 var8005ef44 = 0x00000000;
u32 var8005ef48 = 0x0c100000;
u32 var8005ef4c = 0x00000000;
u32 var8005ef50 = 0x00001400;
u32 var8005ef54 = 0x0018001c;
u32 var8005ef58 = 0x00000000;
u32 var8005ef5c = 0x70019574;
u32 var8005ef60 = 0x700190bc;
u32 var8005ef64 = 0x70018a28;
u32 var8005ef68 = 0x70019010;
u32 var8005ef6c = 0x7001954c;
u32 var8005ef70 = 0x70019554;
u32 var8005ef74 = 0x700194e0;
u32 var8005ef78 = 0x700194a4;
u32 var8005ef7c = 0x00000000;
u32 var8005ef80 = 0x70019c64;
u32 var8005ef84 = 0x70019c70;
u32 var8005ef88 = 0x70019c88;
u32 var8005ef8c = 0x70019cac;
u32 var8005ef90 = 0xff08ffff;
u32 var8005ef94 = 0xffffffff;
u32 var8005ef98 = 0x0c22ff44;
u32 var8005ef9c = 0x20ffffff;
u32 var8005efa0 = 0xffff04ff;
u32 var8005efa4 = 0xffffff00;
u32 var8005efa8 = 0x14000000;
u32 var8005efac = 0x00000000;
u32 var8005efb0 = 0x00000000;
u32 var8005efb4 = 0x00000000;
u32 var8005efb8 = 0x3f800000;
u32 var8005efbc = 0x00000000;
u32 var8005efc0 = 0x00000000;
u32 var8005efc4 = 0x00000000;
void *var8005efc8 = NULL; // pointer to a function
u32 var8005efcc = 0x00000000;
u32 var8005efd0 = 0x00000000;
u32 var8005efd4 = 0x00000000;
u32 var8005efd8 = 0x00000000;
u32 var8005efdc = 0x00000001;
u32 var8005efe0 = 0x00000000;
u32 var8005efe4 = 0x00000000;
u32 var8005efe8 = 0x00000000;
u32 var8005efec = 0x00000000;
u32 var8005eff0 = 0x00000000;
u32 var8005eff4 = 0x00000000;
u32 var8005eff8 = 0xffffffff;
u32 var8005effc = 0x00000000;
u32 var8005f000 = 0x00000000;
u32 var8005f004 = 0x00000000;
u32 var8005f008 = 0x00000000;
struct animheader *g_Anims = NULL;
u32 var8005f010 = 0x00000000;
u32 var8005f014 = 0x00000000;
u32 var8005f018 = 0x000000b0;
u32 var8005f01c = 0x00000260;
u32 var8005f020 = 0x00000000;
u32 var8005f024 = 0x00000000;
u32 var8005f028 = 0x00000000;
u32 var8005f02c = 0x00000000;
u32 var8005f030 = 0x00000000;
u32 var8005f034 = 0x00000000;
u32 var8005f038 = 0x00000000;
u32 var8005f03c = 0x00000000;
u16 *var8005f040 = NULL;
u16 *var8005f044 = NULL;
u32 var8005f048 = 0x00000000;
u32 var8005f04c = 0x00000000;
u32 var8005f050 = 0x00000000;
u32 var8005f054 = 0x00000000;
u32 var8005f058 = 0x00000001;
u32 var8005f05c = 0x00000002;
u32 var8005f060 = 0x00000000;
u32 var8005f064 = 0x00000000;
u32 var8005f068 = 0x00000000;
u32 var8005f06c = 0x00001000;
u32 var8005f070 = 0x00000000;
u32 var8005f074 = 0x00000800;
u32 var8005f078 = (u32) &var8009a970;
u32 var8005f07c = 0x00000400;
u32 var8005f080 = 0x00000000;
u32 var8005f084 = 0x00000000;
u32 var8005f088 = 0x00000000;
u32 var8005f08c = 0x00000000;
u32 var8005f090 = 0x00000000;
u32 var8005f094 = 0x00000000;
u32 var8005f098 = 0x00000000;
u32 var8005f09c = 0x00000000;
u32 var8005f0a0 = 0x00000000;
u32 var8005f0a4 = 0x00000000;
u32 var8005f0a8 = 0x00000000;
u32 var8005f0ac = 0x00000000;
u32 var8005f0b0 = 0x00000000;
u32 var8005f0b4 = 0x00000000;
u32 var8005f0b8 = 0x00000001;
u32 var8005f0bc = 0x00000002;
u32 var8005f0c0 = 0x00000000;
u32 var8005f0c4 = 0x00000000;
u32 var8005f0c8 = 0x00000000;
u32 var8005f0cc = 0x00001000;
u32 var8005f0d0 = 0x00000000;
u32 var8005f0d4 = 0x00000800;
u32 var8005f0d8 = (u32) &var8009a970;
u32 var8005f0dc = 0x00000400;
u32 var8005f0e0 = 0x00000000;
u32 var8005f0e4 = 0x00000000;
u32 var8005f0e8 = 0x00000000;
u32 var8005f0ec = 0x00000000;
u32 var8005f0f0 = 0x00000000;
u32 var8005f0f4 = 0x00000000;
u32 var8005f0f8 = 0x00000000;
u32 var8005f0fc = 0x00000000;
u32 var8005f100 = 0x00000000;
u32 var8005f104 = 0x00000000;
u32 var8005f108 = (u32) &var8005f048;
u32 var8005f10c = 0x00000000;
u32 var8005f110 = 0x00000000;
u32 var8005f114 = 0x00000000;
u32 var8005f118 = 0x00000000;
u32 var8005f11c = 0x00000000;
u32 var8005f120 = 0x00000000;
u32 var8005f124 = 0x00000000;
u32 var8005f128 = 0x00000000;
u32 var8005f12c = (u32) &var8009c2d0;
u32 var8005f130 = 0x00000000;
u32 var8005f134 = 0x00000000;
u32 var8005f138 = 0x00000000;
u32 var8005f13c = 0x00000000;
u32 var8005f140 = 0x00000000;
u32 var8005f144 = 0x00000000;
u32 var8005f148 = 0x00000000;
u32 var8005f14c = 0x00000000;
u32 var8005f150 = 0x00000000;
u32 var8005f154 = 0x00002710;
u32 var8005f158 = 0x00004e20;
u32 var8005f15c = 0x00007530;
u32 var8005f160 = 0x00009c40;
u32 var8005f164 = 0x0000c350;
u32 var8005f168 = 0x0000ea60;
u32 var8005f16c = 0x00011170;
u32 var8005f170 = 0x00013880;
u32 var8005f174 = 0x00015f90;
u32 var8005f178 = 0x000186a0;
u32 var8005f17c = 0x0001adb0;
u32 var8005f180 = 0x0001adb0;
u32 var8005f184 = 0x0001d4c0;
u32 var8005f188 = 0x0001fbd0;
u32 var8005f18c = 0x000222e0;
u32 var8005f190 = 0x000249f0;
u32 var8005f194 = 0x00027100;
u32 var8005f198 = 0x00029810;
u32 var8005f19c = 0x0002e630;
u32 var8005f1a0 = 0x00030d40;
u32 var8005f1a4 = 0x00035b60;
u32 var8005f1a8 = 0x00038270;
u32 var8005f1ac = 0x0003d090;
u32 var8005f1b0 = 0x00041eb0;
u32 var8005f1b4 = 0x00046cd0;
u32 var8005f1b8 = 0x0004baf0;
u32 var8005f1bc = 0x00050910;
u32 var8005f1c0 = 0x00055730;
u32 var8005f1c4 = 0x0005cc60;
u32 var8005f1c8 = 0x00064190;
u32 var8005f1cc = 0x0006b6c0;
u32 var8005f1d0 = 0x00072bf0;
u32 var8005f1d4 = 0x0007a120;
u32 var8005f1d8 = 0x00083d60;
u32 var8005f1dc = 0x0008d9a0;
u32 var8005f1e0 = 0x000975e0;
u32 var8005f1e4 = 0x000a1220;
u32 var8005f1e8 = 0x000ad570;
u32 var8005f1ec = 0x000b98c0;
u32 var8005f1f0 = 0x000c8320;
u32 var8005f1f4 = 0x000d6d80;
u32 var8005f1f8 = 0x000e57e0;
u32 var8005f1fc = 0x000f4240;
u32 var8005f200 = 0x000f4240;
u32 var8005f204 = 0x0010c8e0;
u32 var8005f208 = 0x00124f80;
u32 var8005f20c = 0x0013d620;
u32 var8005f210 = 0x00155cc0;
u32 var8005f214 = 0x0016e360;
u32 var8005f218 = 0x00186a00;
u32 var8005f21c = 0x0019f0a0;
u32 var8005f220 = 0x001b7740;
u32 var8005f224 = 0x001e8480;
u32 var8005f228 = 0x00200b20;
u32 var8005f22c = 0x00231860;
u32 var8005f230 = 0x00249f00;
u32 var8005f234 = 0x0027ac40;
u32 var8005f238 = 0x002ab980;
u32 var8005f23c = 0x002dc6c0;
u32 var8005f240 = 0x0030d400;
u32 var8005f244 = 0x003567e0;
u32 var8005f248 = 0x00387520;
u32 var8005f24c = 0x003d0900;
u32 var8005f250 = 0x00419ce0;
u32 var8005f254 = 0x004630c0;
u32 var8005f258 = 0x004ac4a0;
u32 var8005f25c = 0x0050df20;
u32 var8005f260 = 0x0056f9a0;
u32 var8005f264 = 0x005d1420;
u32 var8005f268 = 0x00632ea0;
u32 var8005f26c = 0x006acfc0;
u32 var8005f270 = 0x007270e0;
u32 var8005f274 = 0x007b98a0;
u32 var8005f278 = 0x008339c0;
u32 var8005f27c = 0x008de820;
u32 var8005f280 = 0x00970fe0;
u32 var8005f284 = 0x00989680;
u32 var8005f288 = 0x00a7d8c0;
u32 var8005f28c = 0x00b71b00;
u32 var8005f290 = 0x00c65d40;
u32 var8005f294 = 0x00d59f80;
u32 var8005f298 = 0x00e4e1c0;
u32 var8005f29c = 0x00f42400;
u32 var8005f2a0 = 0x01036640;
u32 var8005f2a4 = 0x0112a880;
u32 var8005f2a8 = 0x0121eac0;
u32 var8005f2ac = 0x01406f40;
u32 var8005f2b0 = 0x014fb180;
u32 var8005f2b4 = 0x016e3600;
u32 var8005f2b8 = 0x018cba80;
u32 var8005f2bc = 0x01ab3f00;
u32 var8005f2c0 = 0x01c9c380;
u32 var8005f2c4 = 0x01e84800;
u32 var8005f2c8 = 0x0206cc80;
u32 var8005f2cc = 0x02349340;
u32 var8005f2d0 = 0x025317c0;
u32 var8005f2d4 = 0x0280de80;
u32 var8005f2d8 = 0x02aea540;
u32 var8005f2dc = 0x02ebae40;
u32 var8005f2e0 = 0x02faf080;
u32 var8005f2e4 = 0x03473bc0;
u32 var8005f2e8 = 0x03938700;
u32 var8005f2ec = 0x03dfd240;
u32 var8005f2f0 = 0x042c1d80;
u32 var8005f2f4 = 0x047868c0;
u32 var8005f2f8 = 0x04c4b400;
u32 var8005f2fc = 0x0510ff40;
u32 var8005f300 = 0x055d4a80;
u32 var8005f304 = 0x05a995c0;
u32 var8005f308 = 0x05f5e100;
u32 var8005f30c = 0x06422c40;
u32 var8005f310 = 0x068e7780;
u32 var8005f314 = 0x06dac2c0;
u32 var8005f318 = 0x07270e00;
u32 var8005f31c = 0x07735940;
u32 var8005f320 = 0x07bfa480;
u32 var8005f324 = 0x080befc0;
u32 var8005f328 = 0x08583b00;
u32 var8005f32c = 0x08a48640;
u32 var8005f330 = 0x08f0d180;
u32 var8005f334 = 0x093d1cc0;
u32 var8005f338 = 0x09896800;
u32 var8005f33c = 0x09d5b340;
u32 var8005f340 = 0x0a21fe80;
u32 var8005f344 = 0x0a6e49c0;
u32 var8005f348 = 0x0aba9500;
u32 var8005f34c = 0x3d4ccccd;
u32 var8005f350 = 0x3d4ccccd;
u32 var8005f354 = 0x3d75c28f;
u32 var8005f358 = 0x3d75c28f;
u32 var8005f35c = 0x3d75c28f;
u32 var8005f360 = 0x3d8f5c29;
u32 var8005f364 = 0x3d8f5c29;
u32 var8005f368 = 0x3da3d70a;
u32 var8005f36c = 0x3da3d70a;
u32 var8005f370 = 0x3db851ec;
u32 var8005f374 = 0x3dcccccd;
u32 var8005f378 = 0x3de147ae;
u32 var8005f37c = 0x3e051eb8;
u32 var8005f380 = 0x3e0f5c29;
u32 var8005f384 = 0x3e2e147b;
u32 var8005f388 = 0x3e4ccccd;
u32 var8005f38c = 0x3e800000;
u32 var8005f390 = 0x3ea8f5c3;
u32 var8005f394 = 0x3f000000;
u32 var8005f398 = 0x3f800000;
u32 var8005f39c = 0x3fa00000;
u32 var8005f3a0 = 0x3fc00000;
u32 var8005f3a4 = 0x3fe00000;
u32 var8005f3a8 = 0x40000000;
u32 var8005f3ac = 0x40100000;
u32 var8005f3b0 = 0x40200000;
u32 var8005f3b4 = 0x40300000;
u32 var8005f3b8 = 0x40400000;
u32 var8005f3bc = 0x40500000;
u32 var8005f3c0 = 0x40600000;
u32 var8005f3c4 = 0x40700000;
u32 var8005f3c8 = 0x40800000;
u32 var8005f3cc = 0x40880000;
u32 var8005f3d0 = 0x40900000;
u32 var8005f3d4 = 0x40980000;
u32 var8005f3d8 = 0x40a00000;
u32 var8005f3dc = 0x40a80000;
u32 var8005f3e0 = 0x40b00000;
u32 var8005f3e4 = 0x40b80000;
u32 var8005f3e8 = 0x40c00000;
u32 var8005f3ec = 0x40c80000;
u32 var8005f3f0 = 0x40d00000;
u32 var8005f3f4 = 0x40d80000;
u32 var8005f3f8 = 0x40e00000;
u32 var8005f3fc = 0x40e80000;
u32 var8005f400 = 0x40f00000;
u32 var8005f404 = 0x40f80000;
u32 var8005f408 = 0x41000000;
u32 var8005f40c = 0x41040000;
u32 var8005f410 = 0x41080000;
u32 var8005f414 = 0x410c0000;
u32 var8005f418 = 0x41100000;
u32 var8005f41c = 0x41140000;
u32 var8005f420 = 0x41180000;
u32 var8005f424 = 0x411c0000;
u32 var8005f428 = 0x41200000;
u32 var8005f42c = 0x41240000;
u32 var8005f430 = 0x41280000;
u32 var8005f434 = 0x412c0000;
u32 var8005f438 = 0x41300000;
u32 var8005f43c = 0x41340000;
u32 var8005f440 = 0x41380000;
u32 var8005f444 = 0x413c0000;
u32 var8005f448 = 0x41400000;
u32 var8005f44c = 0x41440000;
u32 var8005f450 = 0x41480000;
u32 var8005f454 = 0x414c0000;
u32 var8005f458 = 0x41500000;
u32 var8005f45c = 0x41540000;
u32 var8005f460 = 0x41580000;
u32 var8005f464 = 0x415c0000;
u32 var8005f468 = 0x41600000;
u32 var8005f46c = 0x41640000;
u32 var8005f470 = 0x41680000;
u32 var8005f474 = 0x416c0000;
u32 var8005f478 = 0x41700000;
u32 var8005f47c = 0x41740000;
u32 var8005f480 = 0x41780000;
u32 var8005f484 = 0x417c0000;
u32 var8005f488 = 0x41800000;
u32 var8005f48c = 0x41820000;
u32 var8005f490 = 0x41840000;
u32 var8005f494 = 0x41860000;
u32 var8005f498 = 0x41880000;
u32 var8005f49c = 0x418a0000;
u32 var8005f4a0 = 0x418c0000;
u32 var8005f4a4 = 0x418e0000;
u32 var8005f4a8 = 0x41900000;
u32 var8005f4ac = 0x41920000;
u32 var8005f4b0 = 0x41940000;
u32 var8005f4b4 = 0x41960000;
u32 var8005f4b8 = 0x41980000;
u32 var8005f4bc = 0x419a0000;
u32 var8005f4c0 = 0x419c0000;
u32 var8005f4c4 = 0x419e0000;
u32 var8005f4c8 = 0x41a00000;
u32 var8005f4cc = 0x41a20000;
u32 var8005f4d0 = 0x41a40000;
u32 var8005f4d4 = 0x41a60000;
u32 var8005f4d8 = 0x41a80000;
u32 var8005f4dc = 0x00000000;
u32 var8005f4e0 = 0x00000003;
u32 var8005f4e4 = 0x00000898;
u32 var8005f4e8 = 0x00000000;
u32 var8005f4ec = 0x000004a0;
u32 var8005f4f0 = 0x00002666;
u32 var8005f4f4 = 0xffffd99a;
u32 var8005f4f8 = 0x00000000;
u32 var8005f4fc = 0x00000000;
u32 var8005f500 = 0x00000000;
u32 var8005f504 = 0x00000000;
u32 var8005f508 = 0x000001a0;
u32 var8005f50c = 0x00000340;
u32 var8005f510 = 0x00000ccc;
u32 var8005f514 = 0xfffff334;
u32 var8005f518 = 0x00003fff;
u32 var8005f51c = 0x00000000;
u32 var8005f520 = 0x00000000;
u32 var8005f524 = 0x00000000;
u32 var8005f528 = 0x00000000;
u32 var8005f52c = 0x00000528;
u32 var8005f530 = 0x00001388;
u32 var8005f534 = 0x00000000;
u32 var8005f538 = 0x00000000;
u32 var8005f53c = 0x00000000;
u32 var8005f540 = 0x00000000;
u32 var8005f544 = 0x00005000;
u32 var8005f548 = 0x00000000;
u32 var8005f54c = 0x00000000;
u32 var8005f550 = 0x00000000;
u32 var8005f554 = 0x00000000;
u32 var8005f558 = 0x00000000;
u32 var8005f55c = 0x00000000;
u32 var8005f560 = 0x00000000;
u32 var8005f564 = 0x00000000;
u32 var8005f568 = 0x00000000;
u32 var8005f56c = 0x00000000;
u32 var8005f570 = 0x7fff7ffc;
u32 var8005f574 = 0x7ff57fe8;
u32 var8005f578 = 0x7fd77fc0;
u32 var8005f57c = 0x7fa57f84;
u32 var8005f580 = 0x7f5f7f34;
u32 var8005f584 = 0x7f057ed0;
u32 var8005f588 = 0x7e977e58;
u32 var8005f58c = 0x7e157dcd;
u32 var8005f590 = 0x7d7f7d2d;
u32 var8005f594 = 0x7cd67c7a;
u32 var8005f598 = 0x7c1a7bb4;
u32 var8005f59c = 0x7b497ada;
u32 var8005f5a0 = 0x7a6679ed;
u32 var8005f5a4 = 0x796f78ed;
u32 var8005f5a8 = 0x786677da;
u32 var8005f5ac = 0x774976b4;
u32 var8005f5b0 = 0x761a757b;
u32 var8005f5b4 = 0x74d87430;
u32 var8005f5b8 = 0x738472d3;
u32 var8005f5bc = 0x721e7164;
u32 var8005f5c0 = 0x70a66fe3;
u32 var8005f5c4 = 0x6f1c6e51;
u32 var8005f5c8 = 0x6d816cad;
u32 var8005f5cc = 0x6bd56af9;
u32 var8005f5d0 = 0x6a186933;
u32 var8005f5d4 = 0x684a675d;
u32 var8005f5d8 = 0x666c6577;
u32 var8005f5dc = 0x647e6381;
u32 var8005f5e0 = 0x6280617c;
u32 var8005f5e4 = 0x60735f67;
u32 var8005f5e8 = 0x5e575d43;
u32 var8005f5ec = 0x5c2c5b11;
u32 var8005f5f0 = 0x59f258d0;
u32 var8005f5f4 = 0x57aa5681;
u32 var8005f5f8 = 0x55555425;
u32 var8005f5fc = 0x52f251bc;
u32 var8005f600 = 0x50824f46;
u32 var8005f604 = 0x4e064cc3;
u32 var8005f608 = 0x4b7d4a35;
u32 var8005f60c = 0x48e9479b;
u32 var8005f610 = 0x464944f5;
u32 var8005f614 = 0x439e4245;
u32 var8005f618 = 0x40e93f8a;
u32 var8005f61c = 0x3e293cc6;
u32 var8005f620 = 0x3b6039f8;
u32 var8005f624 = 0x388d3721;
u32 var8005f628 = 0x35b23441;
u32 var8005f62c = 0x32ce3159;
u32 var8005f630 = 0x2fe22e69;
u32 var8005f634 = 0x2cef2b72;
u32 var8005f638 = 0x29f42875;
u32 var8005f63c = 0x26f32570;
u32 var8005f640 = 0x23ec2266;
u32 var8005f644 = 0x20df1f57;
u32 var8005f648 = 0x1dce1c43;
u32 var8005f64c = 0x1ab7192a;
u32 var8005f650 = 0x179c160e;
u32 var8005f654 = 0x147e12ed;
u32 var8005f658 = 0x115c0fca;
u32 var8005f65c = 0x0e380ca5;
u32 var8005f660 = 0x0b11097d;
u32 var8005f664 = 0x07e90654;
u32 var8005f668 = 0x04c0032a;
u32 var8005f66c = 0x01950000;
u32 var8005f670 = 0x00000000;
u32 var8005f674 = (u32) &var70054b40;
u32 var8005f678 = (u32) &var70054b68;
u32 var8005f67c = (u32) &var70054bb8;
u32 var8005f680 = (u32) &var70054c08;
u32 var8005f684 = (u32) &var70054c08;
u32 var8005f688 = (u32) &var70054c90;
u32 var8005f68c = (u32) &var70054d18;
u32 var8005f690 = (u32) &var70054e40;
u32 var8005f694 = (u32) &var70054f68;
u32 var8005f698 = (u32) &var70055090;
u32 var8005f69c = (u32) &var70055298;
u32 var8005f6a0 = (u32) &var700554a0;
u32 var8005f6a4 = (u32) &var700556a8;
u32 var8005f6a8 = (u32) &var70055eb0;
u32 var8005f6ac = (u32) &var70055eb0;
u32 var8005f6b0 = (u32) &var700566b8;
u32 var8005f6b4 = (u32) &var700566b8;
u32 var8005f6b8 = (u32) &var700566b8;
u32 var8005f6bc = (u32) &var700566b8;
u32 var8005f6c0 = (u32) &var700566b8;
u32 var8005f6c4 = (u32) &var700566b8;
u32 var8005f6c8 = (u32) &var700566b8;
u32 var8005f6cc = (u32) &var700566b8;
u32 var8005f6d0 = (u32) &var70056ec0;
u32 var8005f6d4 = (u32) &var70056ec0;
u32 var8005f6d8 = (u32) &var70056ec0;
u32 var8005f6dc = (u32) &var70056ec0;
u32 var8005f6e0 = (u32) &var70056ec0;
u32 var8005f6e4 = (u32) &var70056ec0;
u32 var8005f6e8 = (u32) &var70056ec0;
u32 var8005f6ec = (u32) &var70056ec0;
u32 var8005f6f0 = (u32) &var700576c8;
u32 var8005f6f4 = (u32) &var70057750;
u32 var8005f6f8 = 0x00000000;
u32 var8005f6fc = 0x00000000;
u32 var8005f700 = 0x00000000;
u32 var8005f704 = 0x00000000;
u32 var8005f708 = 0x00000000;
u32 var8005f70c = 0x00000000;
u32 var8005f710 = 0x00000000;
u32 var8005f714 = 0x0000320e;
u32 var8005f718 = 0x00000140;
u32 var8005f71c = 0x03e52239;
u32 var8005f720 = 0x0000020d;
u32 var8005f724 = 0x00000c15;
u32 var8005f728 = 0x0c150c15;
u32 var8005f72c = 0x006c02ec;
u32 var8005f730 = 0x00000200;
u32 var8005f734 = 0x00000000;
u32 var8005f738 = 0x00000280;
u32 var8005f73c = 0x00000400;
u32 var8005f740 = 0x002501ff;
u32 var8005f744 = 0x000e0204;
u32 var8005f748 = 0x00000002;
u32 var8005f74c = 0x00000280;
u32 var8005f750 = 0x00000400;
u32 var8005f754 = 0x002501ff;
u32 var8005f758 = 0x000e0204;
u32 var8005f75c = 0x00000002;
u32 var8005f760 = 0x01000000;
u32 var8005f764 = 0x0000324e;
u32 var8005f768 = 0x00000140;
u32 var8005f76c = 0x03e52239;
u32 var8005f770 = 0x0000020c;
u32 var8005f774 = 0x00000c15;
u32 var8005f778 = 0x0c150c15;
u32 var8005f77c = 0x006c02ec;
u32 var8005f780 = 0x00000200;
u32 var8005f784 = 0x00000000;
u32 var8005f788 = 0x00000280;
u32 var8005f78c = 0x01000400;
u32 var8005f790 = 0x002301fd;
u32 var8005f794 = 0x000e0204;
u32 var8005f798 = 0x00000002;
u32 var8005f79c = 0x00000280;
u32 var8005f7a0 = 0x03000400;
u32 var8005f7a4 = 0x002501ff;
u32 var8005f7a8 = 0x000e0204;
u32 var8005f7ac = 0x00000002;
u32 var8005f7b0 = 0x02000000;
u32 var8005f7b4 = 0x0000311e;
u32 var8005f7b8 = 0x00000140;
u32 var8005f7bc = 0x03e52239;
u32 var8005f7c0 = 0x0000020d;
u32 var8005f7c4 = 0x00000c15;
u32 var8005f7c8 = 0x0c150c15;
u32 var8005f7cc = 0x006c02ec;
u32 var8005f7d0 = 0x00000200;
u32 var8005f7d4 = 0x00000000;
u32 var8005f7d8 = 0x00000280;
u32 var8005f7dc = 0x00000400;
u32 var8005f7e0 = 0x002501ff;
u32 var8005f7e4 = 0x000e0204;
u32 var8005f7e8 = 0x00000002;
u32 var8005f7ec = 0x00000280;
u32 var8005f7f0 = 0x00000400;
u32 var8005f7f4 = 0x002501ff;
u32 var8005f7f8 = 0x000e0204;
u32 var8005f7fc = 0x00000002;
u32 var8005f800 = 0x03000000;
u32 var8005f804 = 0x0000305e;
u32 var8005f808 = 0x00000140;
u32 var8005f80c = 0x03e52239;
u32 var8005f810 = 0x0000020c;
u32 var8005f814 = 0x00000c15;
u32 var8005f818 = 0x0c150c15;
u32 var8005f81c = 0x006c02ec;
u32 var8005f820 = 0x00000200;
u32 var8005f824 = 0x00000000;
u32 var8005f828 = 0x00000280;
u32 var8005f82c = 0x01000400;
u32 var8005f830 = 0x002301fd;
u32 var8005f834 = 0x000e0204;
u32 var8005f838 = 0x00000002;
u32 var8005f83c = 0x00000280;
u32 var8005f840 = 0x03000400;
u32 var8005f844 = 0x002501ff;
u32 var8005f848 = 0x000e0204;
u32 var8005f84c = 0x00000002;
u32 var8005f850 = 0x04000000;
u32 var8005f854 = 0x0000330f;
u32 var8005f858 = 0x00000140;
u32 var8005f85c = 0x03e52239;
u32 var8005f860 = 0x0000020d;
u32 var8005f864 = 0x00000c15;
u32 var8005f868 = 0x0c150c15;
u32 var8005f86c = 0x006c02ec;
u32 var8005f870 = 0x00000200;
u32 var8005f874 = 0x00000000;
u32 var8005f878 = 0x00000500;
u32 var8005f87c = 0x00000400;
u32 var8005f880 = 0x002501ff;
u32 var8005f884 = 0x000e0204;
u32 var8005f888 = 0x00000002;
u32 var8005f88c = 0x00000500;
u32 var8005f890 = 0x00000400;
u32 var8005f894 = 0x002501ff;
u32 var8005f898 = 0x000e0204;
u32 var8005f89c = 0x00000002;
u32 var8005f8a0 = 0x05000000;
u32 var8005f8a4 = 0x0000324f;
u32 var8005f8a8 = 0x00000140;
u32 var8005f8ac = 0x03e52239;
u32 var8005f8b0 = 0x0000020c;
u32 var8005f8b4 = 0x00000c15;
u32 var8005f8b8 = 0x0c150c15;
u32 var8005f8bc = 0x006c02ec;
u32 var8005f8c0 = 0x00000200;
u32 var8005f8c4 = 0x00000000;
u32 var8005f8c8 = 0x00000500;
u32 var8005f8cc = 0x01000400;
u32 var8005f8d0 = 0x002301fd;
u32 var8005f8d4 = 0x000e0204;
u32 var8005f8d8 = 0x00000002;
u32 var8005f8dc = 0x00000500;
u32 var8005f8e0 = 0x03000400;
u32 var8005f8e4 = 0x002501ff;
u32 var8005f8e8 = 0x000e0204;
u32 var8005f8ec = 0x00000002;
u32 var8005f8f0 = 0x06000000;
u32 var8005f8f4 = 0x0000301f;
u32 var8005f8f8 = 0x00000140;
u32 var8005f8fc = 0x03e52239;
u32 var8005f900 = 0x0000020d;
u32 var8005f904 = 0x00000c15;
u32 var8005f908 = 0x0c150c15;
u32 var8005f90c = 0x006c02ec;
u32 var8005f910 = 0x00000200;
u32 var8005f914 = 0x00000000;
u32 var8005f918 = 0x00000500;
u32 var8005f91c = 0x00000400;
u32 var8005f920 = 0x002501ff;
u32 var8005f924 = 0x000e0204;
u32 var8005f928 = 0x00000002;
u32 var8005f92c = 0x00000500;
u32 var8005f930 = 0x00000400;
u32 var8005f934 = 0x002501ff;
u32 var8005f938 = 0x000e0204;
u32 var8005f93c = 0x00000002;
u32 var8005f940 = 0x07000000;
u32 var8005f944 = 0x0000305f;
u32 var8005f948 = 0x00000140;
u32 var8005f94c = 0x03e52239;
u32 var8005f950 = 0x0000020c;
u32 var8005f954 = 0x00000c15;
u32 var8005f958 = 0x0c150c15;
u32 var8005f95c = 0x006c02ec;
u32 var8005f960 = 0x00000200;
u32 var8005f964 = 0x00000000;
u32 var8005f968 = 0x00000500;
u32 var8005f96c = 0x01000400;
u32 var8005f970 = 0x002301fd;
u32 var8005f974 = 0x000e0204;
u32 var8005f978 = 0x00000002;
u32 var8005f97c = 0x00000500;
u32 var8005f980 = 0x03000400;
u32 var8005f984 = 0x002501ff;
u32 var8005f988 = 0x000e0204;
u32 var8005f98c = 0x00000002;
u32 var8005f990 = 0x08000000;
u32 var8005f994 = 0x0000324e;
u32 var8005f998 = 0x00000500;
u32 var8005f99c = 0x03e52239;
u32 var8005f9a0 = 0x0000020c;
u32 var8005f9a4 = 0x00000c15;
u32 var8005f9a8 = 0x0c150c15;
u32 var8005f9ac = 0x006c02ec;
u32 var8005f9b0 = 0x00000400;
u32 var8005f9b4 = 0x00000000;
u32 var8005f9b8 = 0x00000500;
u32 var8005f9bc = 0x00000400;
u32 var8005f9c0 = 0x002301fd;
u32 var8005f9c4 = 0x000e0204;
u32 var8005f9c8 = 0x00000002;
u32 var8005f9cc = 0x00000a00;
u32 var8005f9d0 = 0x00000400;
u32 var8005f9d4 = 0x002501ff;
u32 var8005f9d8 = 0x000e0204;
u32 var8005f9dc = 0x00000002;
u32 var8005f9e0 = 0x09000000;
u32 var8005f9e4 = 0x0000324e;
u32 var8005f9e8 = 0x00000280;
u32 var8005f9ec = 0x03e52239;
u32 var8005f9f0 = 0x0000020c;
u32 var8005f9f4 = 0x00000c15;
u32 var8005f9f8 = 0x0c150c15;
u32 var8005f9fc = 0x006c02ec;
u32 var8005fa00 = 0x00000400;
u32 var8005fa04 = 0x00000000;
u32 var8005fa08 = 0x00000500;
u32 var8005fa0c = 0x02000800;
u32 var8005fa10 = 0x002301fd;
u32 var8005fa14 = 0x000e0204;
u32 var8005fa18 = 0x00000002;
u32 var8005fa1c = 0x00000a00;
u32 var8005fa20 = 0x02000800;
u32 var8005fa24 = 0x002501ff;
u32 var8005fa28 = 0x000e0204;
u32 var8005fa2c = 0x00000002;
u32 var8005fa30 = 0x0a000000;
u32 var8005fa34 = 0x0000305e;
u32 var8005fa38 = 0x00000500;
u32 var8005fa3c = 0x03e52239;
u32 var8005fa40 = 0x0000020c;
u32 var8005fa44 = 0x00000c15;
u32 var8005fa48 = 0x0c150c15;
u32 var8005fa4c = 0x006c02ec;
u32 var8005fa50 = 0x00000400;
u32 var8005fa54 = 0x00000000;
u32 var8005fa58 = 0x00000500;
u32 var8005fa5c = 0x00000400;
u32 var8005fa60 = 0x002301fd;
u32 var8005fa64 = 0x000e0204;
u32 var8005fa68 = 0x00000002;
u32 var8005fa6c = 0x00000a00;
u32 var8005fa70 = 0x00000400;
u32 var8005fa74 = 0x002501ff;
u32 var8005fa78 = 0x000e0204;
u32 var8005fa7c = 0x00000002;
u32 var8005fa80 = 0x0b000000;
u32 var8005fa84 = 0x0000305e;
u32 var8005fa88 = 0x00000280;
u32 var8005fa8c = 0x03e52239;
u32 var8005fa90 = 0x0000020c;
u32 var8005fa94 = 0x00000c15;
u32 var8005fa98 = 0x0c150c15;
u32 var8005fa9c = 0x006c02ec;
u32 var8005faa0 = 0x00000400;
u32 var8005faa4 = 0x00000000;
u32 var8005faa8 = 0x00000500;
u32 var8005faac = 0x02000800;
u32 var8005fab0 = 0x002301fd;
u32 var8005fab4 = 0x000e0204;
u32 var8005fab8 = 0x00000002;
u32 var8005fabc = 0x00000a00;
u32 var8005fac0 = 0x02000800;
u32 var8005fac4 = 0x002501ff;
u32 var8005fac8 = 0x000e0204;
u32 var8005facc = 0x00000002;
u32 var8005fad0 = 0x0c000000;
u32 var8005fad4 = 0x0000334f;
u32 var8005fad8 = 0x00000500;
u32 var8005fadc = 0x03e52239;
u32 var8005fae0 = 0x0000020c;
u32 var8005fae4 = 0x00000c15;
u32 var8005fae8 = 0x0c150c15;
u32 var8005faec = 0x006c02ec;
u32 var8005faf0 = 0x00000400;
u32 var8005faf4 = 0x00000000;
u32 var8005faf8 = 0x00000a00;
u32 var8005fafc = 0x00000400;
u32 var8005fb00 = 0x002301fd;
u32 var8005fb04 = 0x000e0204;
u32 var8005fb08 = 0x00000002;
u32 var8005fb0c = 0x00001400;
u32 var8005fb10 = 0x00000400;
u32 var8005fb14 = 0x002501ff;
u32 var8005fb18 = 0x000e0204;
u32 var8005fb1c = 0x00000002;
u32 var8005fb20 = 0x0d000000;
u32 var8005fb24 = 0x0000324f;
u32 var8005fb28 = 0x00000280;
u32 var8005fb2c = 0x03e52239;
u32 var8005fb30 = 0x0000020c;
u32 var8005fb34 = 0x00000c15;
u32 var8005fb38 = 0x0c150c15;
u32 var8005fb3c = 0x006c02ec;
u32 var8005fb40 = 0x00000400;
u32 var8005fb44 = 0x00000000;
u32 var8005fb48 = 0x00000a00;
u32 var8005fb4c = 0x02000800;
u32 var8005fb50 = 0x002301fd;
u32 var8005fb54 = 0x000e0204;
u32 var8005fb58 = 0x00000002;
u32 var8005fb5c = 0x00001400;
u32 var8005fb60 = 0x02000800;
u32 var8005fb64 = 0x002501ff;
u32 var8005fb68 = 0x000e0204;
u32 var8005fb6c = 0x00000002;
u32 var8005fb70 = 0x0e000000;
u32 var8005fb74 = 0x0000320e;
u32 var8005fb78 = 0x00000140;
u32 var8005fb7c = 0x04541e3a;
u32 var8005fb80 = 0x00000271;
u32 var8005fb84 = 0x00170c69;
u32 var8005fb88 = 0x0c6f0c6d;
u32 var8005fb8c = 0x00800300;
u32 var8005fb90 = 0x00000200;
u32 var8005fb94 = 0x00000000;
u32 var8005fb98 = 0x00000280;
u32 var8005fb9c = 0x00000400;
u32 var8005fba0 = 0x005f0239;
u32 var8005fba4 = 0x0009026b;
u32 var8005fba8 = 0x00000002;
u32 var8005fbac = 0x00000280;
u32 var8005fbb0 = 0x00000400;
u32 var8005fbb4 = 0x005f0239;
u32 var8005fbb8 = 0x0009026b;
u32 var8005fbbc = 0x00000002;
u32 var8005fbc0 = 0x0f000000;
u32 var8005fbc4 = 0x0000324e;
u32 var8005fbc8 = 0x00000140;
u32 var8005fbcc = 0x04541e3a;
u32 var8005fbd0 = 0x00000270;
u32 var8005fbd4 = 0x00170c69;
u32 var8005fbd8 = 0x0c6f0c6d;
u32 var8005fbdc = 0x00800300;
u32 var8005fbe0 = 0x00000200;
u32 var8005fbe4 = 0x00000000;
u32 var8005fbe8 = 0x00000280;
u32 var8005fbec = 0x01000400;
u32 var8005fbf0 = 0x005d0237;
u32 var8005fbf4 = 0x0009026b;
u32 var8005fbf8 = 0x00000002;
u32 var8005fbfc = 0x00000280;
u32 var8005fc00 = 0x03000400;
u32 var8005fc04 = 0x005f0239;
u32 var8005fc08 = 0x000d0269;
u32 var8005fc0c = 0x00000002;
u32 var8005fc10 = 0x10000000;
u32 var8005fc14 = 0x0000311e;
u32 var8005fc18 = 0x00000140;
u32 var8005fc1c = 0x04541e3a;
u32 var8005fc20 = 0x00000271;
u32 var8005fc24 = 0x00170c69;
u32 var8005fc28 = 0x0c6f0c6d;
u32 var8005fc2c = 0x00800300;
u32 var8005fc30 = 0x00000200;
u32 var8005fc34 = 0x00000000;
u32 var8005fc38 = 0x00000280;
u32 var8005fc3c = 0x00000400;
u32 var8005fc40 = 0x005f0239;
u32 var8005fc44 = 0x0009026b;
u32 var8005fc48 = 0x00000002;
u32 var8005fc4c = 0x00000280;
u32 var8005fc50 = 0x00000400;
u32 var8005fc54 = 0x005f0239;
u32 var8005fc58 = 0x0009026b;
u32 var8005fc5c = 0x00000002;
u32 var8005fc60 = 0x11000000;
u32 var8005fc64 = 0x0000305e;
u32 var8005fc68 = 0x00000140;
u32 var8005fc6c = 0x04541e3a;
u32 var8005fc70 = 0x00000270;
u32 var8005fc74 = 0x00170c69;
u32 var8005fc78 = 0x0c6f0c6d;
u32 var8005fc7c = 0x00800300;
u32 var8005fc80 = 0x00000200;
u32 var8005fc84 = 0x00000000;
u32 var8005fc88 = 0x00000280;
u32 var8005fc8c = 0x01000400;
u32 var8005fc90 = 0x005d0237;
u32 var8005fc94 = 0x0009026b;
u32 var8005fc98 = 0x00000002;
u32 var8005fc9c = 0x00000280;
u32 var8005fca0 = 0x03000400;
u32 var8005fca4 = 0x005f0239;
u32 var8005fca8 = 0x000d0269;
u32 var8005fcac = 0x00000002;
u32 var8005fcb0 = 0x12000000;
u32 var8005fcb4 = 0x0000330f;
u32 var8005fcb8 = 0x00000140;
u32 var8005fcbc = 0x04541e3a;
u32 var8005fcc0 = 0x00000271;
u32 var8005fcc4 = 0x00170c69;
u32 var8005fcc8 = 0x0c6f0c6d;
u32 var8005fccc = 0x00800300;
u32 var8005fcd0 = 0x00000200;
u32 var8005fcd4 = 0x00000000;
u32 var8005fcd8 = 0x00000500;
u32 var8005fcdc = 0x00000400;
u32 var8005fce0 = 0x005f0239;
u32 var8005fce4 = 0x0009026b;
u32 var8005fce8 = 0x00000002;
u32 var8005fcec = 0x00000500;
u32 var8005fcf0 = 0x00000400;
u32 var8005fcf4 = 0x005f0239;
u32 var8005fcf8 = 0x0009026b;
u32 var8005fcfc = 0x00000002;
u32 var8005fd00 = 0x13000000;
u32 var8005fd04 = 0x0000324f;
u32 var8005fd08 = 0x00000140;
u32 var8005fd0c = 0x04541e3a;
u32 var8005fd10 = 0x00000270;
u32 var8005fd14 = 0x00170c69;
u32 var8005fd18 = 0x0c6f0c6d;
u32 var8005fd1c = 0x00800300;
u32 var8005fd20 = 0x00000200;
u32 var8005fd24 = 0x00000000;
u32 var8005fd28 = 0x00000500;
u32 var8005fd2c = 0x01000400;
u32 var8005fd30 = 0x005d0237;
u32 var8005fd34 = 0x0009026b;
u32 var8005fd38 = 0x00000002;
u32 var8005fd3c = 0x00000500;
u32 var8005fd40 = 0x03000400;
u32 var8005fd44 = 0x005f0239;
u32 var8005fd48 = 0x000d0269;
u32 var8005fd4c = 0x00000002;
u32 var8005fd50 = 0x14000000;
u32 var8005fd54 = 0x0000301f;
u32 var8005fd58 = 0x00000140;
u32 var8005fd5c = 0x04541e3a;
u32 var8005fd60 = 0x00000271;
u32 var8005fd64 = 0x00170c69;
u32 var8005fd68 = 0x0c6f0c6d;
u32 var8005fd6c = 0x00800300;
u32 var8005fd70 = 0x00000200;
u32 var8005fd74 = 0x00000000;
u32 var8005fd78 = 0x00000500;
u32 var8005fd7c = 0x00000400;
u32 var8005fd80 = 0x005f0239;
u32 var8005fd84 = 0x0009026b;
u32 var8005fd88 = 0x00000002;
u32 var8005fd8c = 0x00000500;
u32 var8005fd90 = 0x00000400;
u32 var8005fd94 = 0x005f0239;
u32 var8005fd98 = 0x0009026b;
u32 var8005fd9c = 0x00000002;
u32 var8005fda0 = 0x15000000;
u32 var8005fda4 = 0x0000305f;
u32 var8005fda8 = 0x00000140;
u32 var8005fdac = 0x04541e3a;
u32 var8005fdb0 = 0x00000270;
u32 var8005fdb4 = 0x00170c69;
u32 var8005fdb8 = 0x0c6f0c6d;
u32 var8005fdbc = 0x00800300;
u32 var8005fdc0 = 0x00000200;
u32 var8005fdc4 = 0x00000000;
u32 var8005fdc8 = 0x00000500;
u32 var8005fdcc = 0x01000400;
u32 var8005fdd0 = 0x005d0237;
u32 var8005fdd4 = 0x0009026b;
u32 var8005fdd8 = 0x00000002;
u32 var8005fddc = 0x00000500;
u32 var8005fde0 = 0x03000400;
u32 var8005fde4 = 0x005f0239;
u32 var8005fde8 = 0x000d0269;
u32 var8005fdec = 0x00000002;
u32 var8005fdf0 = 0x16000000;
u32 var8005fdf4 = 0x0000324e;
u32 var8005fdf8 = 0x00000500;
u32 var8005fdfc = 0x04541e3a;
u32 var8005fe00 = 0x00000270;
u32 var8005fe04 = 0x00170c69;
u32 var8005fe08 = 0x0c6f0c6d;
u32 var8005fe0c = 0x00800300;
u32 var8005fe10 = 0x00000400;
u32 var8005fe14 = 0x00000000;
u32 var8005fe18 = 0x00000500;
u32 var8005fe1c = 0x00000400;
u32 var8005fe20 = 0x005d0237;
u32 var8005fe24 = 0x0009026b;
u32 var8005fe28 = 0x00000002;
u32 var8005fe2c = 0x00000a00;
u32 var8005fe30 = 0x00000400;
u32 var8005fe34 = 0x005f0239;
u32 var8005fe38 = 0x000d0269;
u32 var8005fe3c = 0x00000002;
u32 var8005fe40 = 0x17000000;
u32 var8005fe44 = 0x0000324e;
u32 var8005fe48 = 0x00000280;
u32 var8005fe4c = 0x04541e3a;
u32 var8005fe50 = 0x00000270;
u32 var8005fe54 = 0x00170c69;
u32 var8005fe58 = 0x0c6f0c6d;
u32 var8005fe5c = 0x00800300;
u32 var8005fe60 = 0x00000400;
u32 var8005fe64 = 0x00000000;
u32 var8005fe68 = 0x00000500;
u32 var8005fe6c = 0x02000800;
u32 var8005fe70 = 0x005d0237;
u32 var8005fe74 = 0x0009026b;
u32 var8005fe78 = 0x00000002;
u32 var8005fe7c = 0x00000a00;
u32 var8005fe80 = 0x02000800;
u32 var8005fe84 = 0x005f0239;
u32 var8005fe88 = 0x000d0269;
u32 var8005fe8c = 0x00000002;
u32 var8005fe90 = 0x18000000;
u32 var8005fe94 = 0x0000305e;
u32 var8005fe98 = 0x00000500;
u32 var8005fe9c = 0x04541e3a;
u32 var8005fea0 = 0x00000270;
u32 var8005fea4 = 0x00170c69;
u32 var8005fea8 = 0x0c6f0c6d;
u32 var8005feac = 0x00800300;
u32 var8005feb0 = 0x00000400;
u32 var8005feb4 = 0x00000000;
u32 var8005feb8 = 0x00000500;
u32 var8005febc = 0x00000400;
u32 var8005fec0 = 0x005d0237;
u32 var8005fec4 = 0x0009026b;
u32 var8005fec8 = 0x00000002;
u32 var8005fecc = 0x00000a00;
u32 var8005fed0 = 0x00000400;
u32 var8005fed4 = 0x005f0239;
u32 var8005fed8 = 0x000d0269;
u32 var8005fedc = 0x00000002;
u32 var8005fee0 = 0x19000000;
u32 var8005fee4 = 0x0000305e;
u32 var8005fee8 = 0x00000280;
u32 var8005feec = 0x04541e3a;
u32 var8005fef0 = 0x00000270;
u32 var8005fef4 = 0x00170c69;
u32 var8005fef8 = 0x0c6f0c6d;
u32 var8005fefc = 0x00800300;
u32 var8005ff00 = 0x00000400;
u32 var8005ff04 = 0x00000000;
u32 var8005ff08 = 0x00000500;
u32 var8005ff0c = 0x02000800;
u32 var8005ff10 = 0x005d0237;
u32 var8005ff14 = 0x0009026b;
u32 var8005ff18 = 0x00000002;
u32 var8005ff1c = 0x00000a00;
u32 var8005ff20 = 0x02000800;
u32 var8005ff24 = 0x005f0239;
u32 var8005ff28 = 0x000d0269;
u32 var8005ff2c = 0x00000002;
u32 var8005ff30 = 0x1a000000;
u32 var8005ff34 = 0x0000334f;
u32 var8005ff38 = 0x00000500;
u32 var8005ff3c = 0x04541e3a;
u32 var8005ff40 = 0x00000270;
u32 var8005ff44 = 0x00170c69;
u32 var8005ff48 = 0x0c6f0c6d;
u32 var8005ff4c = 0x00800300;
u32 var8005ff50 = 0x00000400;
u32 var8005ff54 = 0x00000000;
u32 var8005ff58 = 0x00000a00;
u32 var8005ff5c = 0x00000400;
u32 var8005ff60 = 0x005d0237;
u32 var8005ff64 = 0x0009026b;
u32 var8005ff68 = 0x00000002;
u32 var8005ff6c = 0x00001400;
u32 var8005ff70 = 0x00000400;
u32 var8005ff74 = 0x005f0239;
u32 var8005ff78 = 0x000d0269;
u32 var8005ff7c = 0x00000002;
u32 var8005ff80 = 0x1b000000;
u32 var8005ff84 = 0x0000324f;
u32 var8005ff88 = 0x00000280;
u32 var8005ff8c = 0x04541e3a;
u32 var8005ff90 = 0x00000270;
u32 var8005ff94 = 0x00170c69;
u32 var8005ff98 = 0x0c6f0c6d;
u32 var8005ff9c = 0x00800300;
u32 var8005ffa0 = 0x00000400;
u32 var8005ffa4 = 0x00000000;
u32 var8005ffa8 = 0x00000a00;
u32 var8005ffac = 0x02000800;
u32 var8005ffb0 = 0x005d0237;
u32 var8005ffb4 = 0x0009026b;
u32 var8005ffb8 = 0x00000002;
u32 var8005ffbc = 0x00001400;
u32 var8005ffc0 = 0x02000800;
u32 var8005ffc4 = 0x005f0239;
u32 var8005ffc8 = 0x000d0269;
u32 var8005ffcc = 0x00000002;
u32 var8005ffd0 = 0x1c000000;
u32 var8005ffd4 = 0x0000320e;
u32 var8005ffd8 = 0x00000140;
u32 var8005ffdc = 0x04651e39;
u32 var8005ffe0 = 0x0000020d;
u32 var8005ffe4 = 0x00040c11;
u32 var8005ffe8 = 0x0c190c1a;
u32 var8005ffec = 0x006c02ec;
u32 var8005fff0 = 0x00000200;
u32 var8005fff4 = 0x00000000;
u32 var8005fff8 = 0x00000280;
u32 var8005fffc = 0x00000400;
u32 var80060000 = 0x002501ff;
u32 var80060004 = 0x000e0204;
u32 var80060008 = 0x00000002;
u32 var8006000c = 0x00000280;
u32 var80060010 = 0x00000400;
u32 var80060014 = 0x002501ff;
u32 var80060018 = 0x000e0204;
u32 var8006001c = 0x00000002;
u32 var80060020 = 0x1d000000;
u32 var80060024 = 0x0000324e;
u32 var80060028 = 0x00000140;
u32 var8006002c = 0x04651e39;
u32 var80060030 = 0x0000020c;
u32 var80060034 = 0x00000c10;
u32 var80060038 = 0x0c1c0c1c;
u32 var8006003c = 0x006c02ec;
u32 var80060040 = 0x00000200;
u32 var80060044 = 0x00000000;
u32 var80060048 = 0x00000280;
u32 var8006004c = 0x01000400;
u32 var80060050 = 0x002301fd;
u32 var80060054 = 0x000b0202;
u32 var80060058 = 0x00000002;
u32 var8006005c = 0x00000280;
u32 var80060060 = 0x03000400;
u32 var80060064 = 0x002501ff;
u32 var80060068 = 0x000e0204;
u32 var8006006c = 0x00000002;
u32 var80060070 = 0x1e000000;
u32 var80060074 = 0x0000311e;
u32 var80060078 = 0x00000140;
u32 var8006007c = 0x04651e39;
u32 var80060080 = 0x0000020d;
u32 var80060084 = 0x00040c11;
u32 var80060088 = 0x0c190c1a;
u32 var8006008c = 0x006c02ec;
u32 var80060090 = 0x00000200;
u32 var80060094 = 0x00000000;
u32 var80060098 = 0x00000280;
u32 var8006009c = 0x00000400;
u32 var800600a0 = 0x002501ff;
u32 var800600a4 = 0x000e0204;
u32 var800600a8 = 0x00000002;
u32 var800600ac = 0x00000280;
u32 var800600b0 = 0x00000400;
u32 var800600b4 = 0x002501ff;
u32 var800600b8 = 0x000e0204;
u32 var800600bc = 0x00000002;
u32 var800600c0 = 0x1f000000;
u32 var800600c4 = 0x0000305e;
u32 var800600c8 = 0x00000140;
u32 var800600cc = 0x04651e39;
u32 var800600d0 = 0x0000020c;
u32 var800600d4 = 0x00000c10;
u32 var800600d8 = 0x0c1c0c1c;
u32 var800600dc = 0x006c02ec;
u32 var800600e0 = 0x00000200;
u32 var800600e4 = 0x00000000;
u32 var800600e8 = 0x00000280;
u32 var800600ec = 0x01000400;
u32 var800600f0 = 0x002301fd;
u32 var800600f4 = 0x000b0202;
u32 var800600f8 = 0x00000002;
u32 var800600fc = 0x00000280;
u32 var80060100 = 0x03000400;
u32 var80060104 = 0x002501ff;
u32 var80060108 = 0x000e0204;
u32 var8006010c = 0x00000002;
u32 var80060110 = 0x20000000;
u32 var80060114 = 0x0000330f;
u32 var80060118 = 0x00000140;
u32 var8006011c = 0x04651e39;
u32 var80060120 = 0x0000020d;
u32 var80060124 = 0x00040c11;
u32 var80060128 = 0x0c190c1a;
u32 var8006012c = 0x006c02ec;
u32 var80060130 = 0x00000200;
u32 var80060134 = 0x00000000;
u32 var80060138 = 0x00000500;
u32 var8006013c = 0x00000400;
u32 var80060140 = 0x002501ff;
u32 var80060144 = 0x000e0204;
u32 var80060148 = 0x00000002;
u32 var8006014c = 0x00000500;
u32 var80060150 = 0x00000400;
u32 var80060154 = 0x002501ff;
u32 var80060158 = 0x000e0204;
u32 var8006015c = 0x00000002;
u32 var80060160 = 0x21000000;
u32 var80060164 = 0x0000324f;
u32 var80060168 = 0x00000140;
u32 var8006016c = 0x04651e39;
u32 var80060170 = 0x0000020c;
u32 var80060174 = 0x00000c10;
u32 var80060178 = 0x0c1c0c1c;
u32 var8006017c = 0x006c02ec;
u32 var80060180 = 0x00000200;
u32 var80060184 = 0x00000000;
u32 var80060188 = 0x00000500;
u32 var8006018c = 0x01000400;
u32 var80060190 = 0x002301fd;
u32 var80060194 = 0x000b0202;
u32 var80060198 = 0x00000002;
u32 var8006019c = 0x00000500;
u32 var800601a0 = 0x03000400;
u32 var800601a4 = 0x002501ff;
u32 var800601a8 = 0x000e0204;
u32 var800601ac = 0x00000002;
u32 var800601b0 = 0x22000000;
u32 var800601b4 = 0x0000301f;
u32 var800601b8 = 0x00000140;
u32 var800601bc = 0x04651e39;
u32 var800601c0 = 0x0000020d;
u32 var800601c4 = 0x00040c11;
u32 var800601c8 = 0x0c190c1a;
u32 var800601cc = 0x006c02ec;
u32 var800601d0 = 0x00000200;
u32 var800601d4 = 0x00000000;
u32 var800601d8 = 0x00000500;
u32 var800601dc = 0x00000400;
u32 var800601e0 = 0x002501ff;
u32 var800601e4 = 0x000e0204;
u32 var800601e8 = 0x00000002;
u32 var800601ec = 0x00000500;
u32 var800601f0 = 0x00000400;
u32 var800601f4 = 0x002501ff;
u32 var800601f8 = 0x000e0204;
u32 var800601fc = 0x00000002;
u32 var80060200 = 0x23000000;
u32 var80060204 = 0x0000305f;
u32 var80060208 = 0x00000140;
u32 var8006020c = 0x04651e39;
u32 var80060210 = 0x0000020c;
u32 var80060214 = 0x00000c10;
u32 var80060218 = 0x0c1c0c1c;
u32 var8006021c = 0x006c02ec;
u32 var80060220 = 0x00000200;
u32 var80060224 = 0x00000000;
u32 var80060228 = 0x00000500;
u32 var8006022c = 0x01000400;
u32 var80060230 = 0x002301fd;
u32 var80060234 = 0x000b0202;
u32 var80060238 = 0x00000002;
u32 var8006023c = 0x00000500;
u32 var80060240 = 0x03000400;
u32 var80060244 = 0x002501ff;
u32 var80060248 = 0x000e0204;
u32 var8006024c = 0x00000002;
u32 var80060250 = 0x24000000;
u32 var80060254 = 0x0000324e;
u32 var80060258 = 0x00000500;
u32 var8006025c = 0x04651e39;
u32 var80060260 = 0x0000020c;
u32 var80060264 = 0x00000c10;
u32 var80060268 = 0x0c1c0c1c;
u32 var8006026c = 0x006c02ec;
u32 var80060270 = 0x00000400;
u32 var80060274 = 0x00000000;
u32 var80060278 = 0x00000500;
u32 var8006027c = 0x00000400;
u32 var80060280 = 0x002301fd;
u32 var80060284 = 0x000b0202;
u32 var80060288 = 0x00000002;
u32 var8006028c = 0x00000a00;
u32 var80060290 = 0x00000400;
u32 var80060294 = 0x002501ff;
u32 var80060298 = 0x000e0204;
u32 var8006029c = 0x00000002;
u32 var800602a0 = 0x25000000;
u32 var800602a4 = 0x0000324e;
u32 var800602a8 = 0x00000280;
u32 var800602ac = 0x04651e39;
u32 var800602b0 = 0x0000020c;
u32 var800602b4 = 0x00000c10;
u32 var800602b8 = 0x0c1c0c1c;
u32 var800602bc = 0x006c02ec;
u32 var800602c0 = 0x00000400;
u32 var800602c4 = 0x00000000;
u32 var800602c8 = 0x00000500;
u32 var800602cc = 0x02000800;
u32 var800602d0 = 0x002301fd;
u32 var800602d4 = 0x000b0202;
u32 var800602d8 = 0x00000002;
u32 var800602dc = 0x00000a00;
u32 var800602e0 = 0x02000800;
u32 var800602e4 = 0x002501ff;
u32 var800602e8 = 0x000e0204;
u32 var800602ec = 0x00000002;
u32 var800602f0 = 0x26000000;
u32 var800602f4 = 0x0000305e;
u32 var800602f8 = 0x00000500;
u32 var800602fc = 0x04651e39;
u32 var80060300 = 0x0000020c;
u32 var80060304 = 0x00000c10;
u32 var80060308 = 0x0c1c0c1c;
u32 var8006030c = 0x006c02ec;
u32 var80060310 = 0x00000400;
u32 var80060314 = 0x00000000;
u32 var80060318 = 0x00000500;
u32 var8006031c = 0x00000400;
u32 var80060320 = 0x002301fd;
u32 var80060324 = 0x000b0202;
u32 var80060328 = 0x00000002;
u32 var8006032c = 0x00000a00;
u32 var80060330 = 0x00000400;
u32 var80060334 = 0x002501ff;
u32 var80060338 = 0x000e0204;
u32 var8006033c = 0x00000002;
u32 var80060340 = 0x27000000;
u32 var80060344 = 0x0000305e;
u32 var80060348 = 0x00000280;
u32 var8006034c = 0x04651e39;
u32 var80060350 = 0x0000020c;
u32 var80060354 = 0x00000c10;
u32 var80060358 = 0x0c1c0c1c;
u32 var8006035c = 0x006c02ec;
u32 var80060360 = 0x00000400;
u32 var80060364 = 0x00000000;
u32 var80060368 = 0x00000500;
u32 var8006036c = 0x02000800;
u32 var80060370 = 0x002301fd;
u32 var80060374 = 0x000b0202;
u32 var80060378 = 0x00000002;
u32 var8006037c = 0x00000a00;
u32 var80060380 = 0x02000800;
u32 var80060384 = 0x002501ff;
u32 var80060388 = 0x000e0204;
u32 var8006038c = 0x00000002;
u32 var80060390 = 0x28000000;
u32 var80060394 = 0x0000334f;
u32 var80060398 = 0x00000500;
u32 var8006039c = 0x04651e39;
u32 var800603a0 = 0x0000020c;
u32 var800603a4 = 0x00000c10;
u32 var800603a8 = 0x0c1c0c1c;
u32 var800603ac = 0x006c02ec;
u32 var800603b0 = 0x00000400;
u32 var800603b4 = 0x00000000;
u32 var800603b8 = 0x00000a00;
u32 var800603bc = 0x00000400;
u32 var800603c0 = 0x002301fd;
u32 var800603c4 = 0x000b0202;
u32 var800603c8 = 0x00000002;
u32 var800603cc = 0x00001400;
u32 var800603d0 = 0x00000400;
u32 var800603d4 = 0x002501ff;
u32 var800603d8 = 0x000e0204;
u32 var800603dc = 0x00000002;
u32 var800603e0 = 0x29000000;
u32 var800603e4 = 0x0000324f;
u32 var800603e8 = 0x00000280;
u32 var800603ec = 0x04651e39;
u32 var800603f0 = 0x0000020c;
u32 var800603f4 = 0x00000c10;
u32 var800603f8 = 0x0c1c0c1c;
u32 var800603fc = 0x006c02ec;
u32 var80060400 = 0x00000400;
u32 var80060404 = 0x00000000;
u32 var80060408 = 0x00000a00;
u32 var8006040c = 0x02000800;
u32 var80060410 = 0x002301fd;
u32 var80060414 = 0x000b0202;
u32 var80060418 = 0x00000002;
u32 var8006041c = 0x00001400;
u32 var80060420 = 0x02000800;
u32 var80060424 = 0x002501ff;
u32 var80060428 = 0x000e0204;
u32 var8006042c = 0x00000002;
u32 var80060430 = 0x2a000000;
u32 var80060434 = 0x0000320e;
u32 var80060438 = 0x00000140;
u32 var8006043c = 0x04541e3a;
u32 var80060440 = 0x00000271;
u32 var80060444 = 0x00170c69;
u32 var80060448 = 0x0c6f0c6d;
u32 var8006044c = 0x00800300;
u32 var80060450 = 0x00000200;
u32 var80060454 = 0x00000000;
u32 var80060458 = 0x00000280;
u32 var8006045c = 0x00000400;
u32 var80060460 = 0x002f0269;
u32 var80060464 = 0x0009026b;
u32 var80060468 = 0x00000002;
u32 var8006046c = 0x00000280;
u32 var80060470 = 0x00000400;
u32 var80060474 = 0x002f0269;
u32 var80060478 = 0x0009026b;
u32 var8006047c = 0x00000002;
u32 var80060480 = 0x2b000000;
u32 var80060484 = 0x0000324e;
u32 var80060488 = 0x00000140;
u32 var8006048c = 0x04541e3a;
u32 var80060490 = 0x00000270;
u32 var80060494 = 0x00170c69;
u32 var80060498 = 0x0c6f0c6d;
u32 var8006049c = 0x00800300;
u32 var800604a0 = 0x00000200;
u32 var800604a4 = 0x00000000;
u32 var800604a8 = 0x00000280;
u32 var800604ac = 0x01000400;
u32 var800604b0 = 0x002d0267;
u32 var800604b4 = 0x0009026b;
u32 var800604b8 = 0x00000002;
u32 var800604bc = 0x00000280;
u32 var800604c0 = 0x03000400;
u32 var800604c4 = 0x002f0269;
u32 var800604c8 = 0x000d0269;
u32 var800604cc = 0x00000002;
u32 var800604d0 = 0x2c000000;
u32 var800604d4 = 0x0000311e;
u32 var800604d8 = 0x00000140;
u32 var800604dc = 0x04541e3a;
u32 var800604e0 = 0x00000271;
u32 var800604e4 = 0x00170c69;
u32 var800604e8 = 0x0c6f0c6d;
u32 var800604ec = 0x00800300;
u32 var800604f0 = 0x00000200;
u32 var800604f4 = 0x00000000;
u32 var800604f8 = 0x00000280;
u32 var800604fc = 0x00000400;
u32 var80060500 = 0x002f0269;
u32 var80060504 = 0x0009026b;
u32 var80060508 = 0x00000002;
u32 var8006050c = 0x00000280;
u32 var80060510 = 0x00000400;
u32 var80060514 = 0x002f0269;
u32 var80060518 = 0x0009026b;
u32 var8006051c = 0x00000002;
u32 var80060520 = 0x2d000000;
u32 var80060524 = 0x0000305e;
u32 var80060528 = 0x00000140;
u32 var8006052c = 0x04541e3a;
u32 var80060530 = 0x00000270;
u32 var80060534 = 0x00170c69;
u32 var80060538 = 0x0c6f0c6d;
u32 var8006053c = 0x00800300;
u32 var80060540 = 0x00000200;
u32 var80060544 = 0x00000000;
u32 var80060548 = 0x00000280;
u32 var8006054c = 0x01000400;
u32 var80060550 = 0x002d0267;
u32 var80060554 = 0x0009026b;
u32 var80060558 = 0x00000002;
u32 var8006055c = 0x00000280;
u32 var80060560 = 0x03000400;
u32 var80060564 = 0x002f0269;
u32 var80060568 = 0x000d0269;
u32 var8006056c = 0x00000002;
u32 var80060570 = 0x2e000000;
u32 var80060574 = 0x0000330f;
u32 var80060578 = 0x00000140;
u32 var8006057c = 0x04541e3a;
u32 var80060580 = 0x00000271;
u32 var80060584 = 0x00170c69;
u32 var80060588 = 0x0c6f0c6d;
u32 var8006058c = 0x00800300;
u32 var80060590 = 0x00000200;
u32 var80060594 = 0x00000000;
u32 var80060598 = 0x00000500;
u32 var8006059c = 0x00000400;
u32 var800605a0 = 0x002f0269;
u32 var800605a4 = 0x0009026b;
u32 var800605a8 = 0x00000002;
u32 var800605ac = 0x00000500;
u32 var800605b0 = 0x00000400;
u32 var800605b4 = 0x002f0269;
u32 var800605b8 = 0x0009026b;
u32 var800605bc = 0x00000002;
u32 var800605c0 = 0x2f000000;
u32 var800605c4 = 0x0000324f;
u32 var800605c8 = 0x00000140;
u32 var800605cc = 0x04541e3a;
u32 var800605d0 = 0x00000270;
u32 var800605d4 = 0x00170c69;
u32 var800605d8 = 0x0c6f0c6d;
u32 var800605dc = 0x00800300;
u32 var800605e0 = 0x00000200;
u32 var800605e4 = 0x00000000;
u32 var800605e8 = 0x00000500;
u32 var800605ec = 0x01000400;
u32 var800605f0 = 0x002d0267;
u32 var800605f4 = 0x0009026b;
u32 var800605f8 = 0x00000002;
u32 var800605fc = 0x00000500;
u32 var80060600 = 0x03000400;
u32 var80060604 = 0x002f0269;
u32 var80060608 = 0x000d0269;
u32 var8006060c = 0x00000002;
u32 var80060610 = 0x30000000;
u32 var80060614 = 0x0000301f;
u32 var80060618 = 0x00000140;
u32 var8006061c = 0x04541e3a;
u32 var80060620 = 0x00000271;
u32 var80060624 = 0x00170c69;
u32 var80060628 = 0x0c6f0c6d;
u32 var8006062c = 0x00800300;
u32 var80060630 = 0x00000200;
u32 var80060634 = 0x00000000;
u32 var80060638 = 0x00000500;
u32 var8006063c = 0x00000400;
u32 var80060640 = 0x002f0269;
u32 var80060644 = 0x0009026b;
u32 var80060648 = 0x00000002;
u32 var8006064c = 0x00000500;
u32 var80060650 = 0x00000400;
u32 var80060654 = 0x002f0269;
u32 var80060658 = 0x0009026b;
u32 var8006065c = 0x00000002;
u32 var80060660 = 0x31000000;
u32 var80060664 = 0x0000305f;
u32 var80060668 = 0x00000140;
u32 var8006066c = 0x04541e3a;
u32 var80060670 = 0x00000270;
u32 var80060674 = 0x00170c69;
u32 var80060678 = 0x0c6f0c6d;
u32 var8006067c = 0x00800300;
u32 var80060680 = 0x00000200;
u32 var80060684 = 0x00000000;
u32 var80060688 = 0x00000500;
u32 var8006068c = 0x01000400;
u32 var80060690 = 0x002d0267;
u32 var80060694 = 0x0009026b;
u32 var80060698 = 0x00000002;
u32 var8006069c = 0x00000500;
u32 var800606a0 = 0x03000400;
u32 var800606a4 = 0x002f0269;
u32 var800606a8 = 0x000d0269;
u32 var800606ac = 0x00000002;
u32 var800606b0 = 0x32000000;
u32 var800606b4 = 0x0000324e;
u32 var800606b8 = 0x00000500;
u32 var800606bc = 0x04541e3a;
u32 var800606c0 = 0x00000270;
u32 var800606c4 = 0x00170c69;
u32 var800606c8 = 0x0c6f0c6d;
u32 var800606cc = 0x00800300;
u32 var800606d0 = 0x00000400;
u32 var800606d4 = 0x00000000;
u32 var800606d8 = 0x00000500;
u32 var800606dc = 0x00000400;
u32 var800606e0 = 0x002d0267;
u32 var800606e4 = 0x0009026b;
u32 var800606e8 = 0x00000002;
u32 var800606ec = 0x00000a00;
u32 var800606f0 = 0x00000400;
u32 var800606f4 = 0x002f0269;
u32 var800606f8 = 0x000d0269;
u32 var800606fc = 0x00000002;
u32 var80060700 = 0x33000000;
u32 var80060704 = 0x0000324e;
u32 var80060708 = 0x00000280;
u32 var8006070c = 0x04541e3a;
u32 var80060710 = 0x00000270;
u32 var80060714 = 0x00170c69;
u32 var80060718 = 0x0c6f0c6d;
u32 var8006071c = 0x00800300;
u32 var80060720 = 0x00000400;
u32 var80060724 = 0x00000000;
u32 var80060728 = 0x00000500;
u32 var8006072c = 0x02000800;
u32 var80060730 = 0x002d0267;
u32 var80060734 = 0x0009026b;
u32 var80060738 = 0x00000002;
u32 var8006073c = 0x00000a00;
u32 var80060740 = 0x02000800;
u32 var80060744 = 0x002f0269;
u32 var80060748 = 0x000d0269;
u32 var8006074c = 0x00000002;
u32 var80060750 = 0x34000000;
u32 var80060754 = 0x0000305e;
u32 var80060758 = 0x00000500;
u32 var8006075c = 0x04541e3a;
u32 var80060760 = 0x00000270;
u32 var80060764 = 0x00170c69;
u32 var80060768 = 0x0c6f0c6d;
u32 var8006076c = 0x00800300;
u32 var80060770 = 0x00000400;
u32 var80060774 = 0x00000000;
u32 var80060778 = 0x00000500;
u32 var8006077c = 0x00000400;
u32 var80060780 = 0x002d0267;
u32 var80060784 = 0x0009026b;
u32 var80060788 = 0x00000002;
u32 var8006078c = 0x00000a00;
u32 var80060790 = 0x00000400;
u32 var80060794 = 0x002f0269;
u32 var80060798 = 0x000d0269;
u32 var8006079c = 0x00000002;
u32 var800607a0 = 0x35000000;
u32 var800607a4 = 0x0000305e;
u32 var800607a8 = 0x00000280;
u32 var800607ac = 0x04541e3a;
u32 var800607b0 = 0x00000270;
u32 var800607b4 = 0x00170c69;
u32 var800607b8 = 0x0c6f0c6d;
u32 var800607bc = 0x00800300;
u32 var800607c0 = 0x00000400;
u32 var800607c4 = 0x00000000;
u32 var800607c8 = 0x00000500;
u32 var800607cc = 0x02000800;
u32 var800607d0 = 0x002d0267;
u32 var800607d4 = 0x0009026b;
u32 var800607d8 = 0x00000002;
u32 var800607dc = 0x00000a00;
u32 var800607e0 = 0x02000800;
u32 var800607e4 = 0x002f0269;
u32 var800607e8 = 0x000d0269;
u32 var800607ec = 0x00000002;
u32 var800607f0 = 0x36000000;
u32 var800607f4 = 0x0000334f;
u32 var800607f8 = 0x00000500;
u32 var800607fc = 0x04541e3a;
u32 var80060800 = 0x00000270;
u32 var80060804 = 0x00170c69;
u32 var80060808 = 0x0c6f0c6d;
u32 var8006080c = 0x00800300;
u32 var80060810 = 0x00000400;
u32 var80060814 = 0x00000000;
u32 var80060818 = 0x00000a00;
u32 var8006081c = 0x00000400;
u32 var80060820 = 0x002d0267;
u32 var80060824 = 0x0009026b;
u32 var80060828 = 0x00000002;
u32 var8006082c = 0x00001400;
u32 var80060830 = 0x00000400;
u32 var80060834 = 0x002f0269;
u32 var80060838 = 0x000d0269;
u32 var8006083c = 0x00000002;
u32 var80060840 = 0x37000000;
u32 var80060844 = 0x0000324f;
u32 var80060848 = 0x00000280;
u32 var8006084c = 0x04541e3a;
u32 var80060850 = 0x00000270;
u32 var80060854 = 0x00170c69;
u32 var80060858 = 0x0c6f0c6d;
u32 var8006085c = 0x00800300;
u32 var80060860 = 0x00000400;
u32 var80060864 = 0x00000000;
u32 var80060868 = 0x00000a00;
u32 var8006086c = 0x02000800;
u32 var80060870 = 0x002d0267;
u32 var80060874 = 0x0009026b;
u32 var80060878 = 0x00000002;
u32 var8006087c = 0x00001400;
u32 var80060880 = 0x02000800;
u32 var80060884 = 0x002f0269;
u32 var80060888 = 0x000d0269;
u32 var8006088c = 0x00000002;
u32 var80060890 = 0x00000000;
u32 var80060894 = 0x00000000;
u32 var80060898 = 0x00000000;
u32 var8006089c = 0x00000000;
u32 __osTimerList = (u32) &var8009c760;
u32 var800608a4 = 0x00000000;
u32 var800608a8 = 0x00000000;
u32 var800608ac = 0x00000000;
u32 var800608b0 = 0x00000000;
u32 var800608b4 = 0x00000000;
u32 var800608b8 = 0x00000000;
u32 var800608bc = 0x00000000;
u32 var800608c0 = 0x00000000;
u32 var800608c4 = 0x00000000;
u32 var800608c8 = 0x00000000;
u32 var800608cc = 0x00000000;
u32 var800608d0 = 0x00000000;
u32 var800608d4 = 0x00000000;
u32 var800608d8 = 0x00000000;
u32 var800608dc = 0x00000000;
u32 var800608e0 = 0x00000000;
u32 var800608e4 = 0x00000000;
u32 var800608e8 = 0x00000000;
u32 var800608ec = 0x00000000;
u32 var800608f0 = 0x00000000;
u32 var800608f4 = 0x00000000;
u32 var800608f8 = 0x00000000;
u32 var800608fc = 0x00000000;
u32 var80060900 = 0x00000000;
u32 var80060904 = 0x00000000;
u32 var80060908 = 0x00000000;
u32 var8006090c = 0x00000000;
u32 var80060910 = (u32) &var800608b0;
u32 var80060914 = (u32) &var800608e0;
u32 var80060918 = 0x00000000;
u32 var8006091c = 0x00000000;
u32 __osPiAccessQueueEnabled = 0x00000000;
u32 var80060924 = 0x00000000;
u32 var80060928 = 0x00000000;
u32 var8006092c = 0x00000000;
u32 __osThreadTail = 0x00000000;
u32 var80060934 = 0xffffffff;
u32 __osRunQueue = (u32) &__osThreadTail;
u32 __osActiveQueue = (u32) &__osThreadTail;
OSThread *__osRunningThread = NULL;
u32 var80060944 = 0x00000000;
u32 var80060948 = 0x00000000;
u32 var8006094c = 0x00000000;
u32 var80060950 = 0x00000000;
u32 var80060954 = 0x00000000;
u32 var80060958 = 0x00000000;
u32 var8006095c = 0x00000000;
u32 __osContInitialized = 0x00000000;
u32 var80060964 = 0x00000000;
u32 var80060968 = 0x00000000;
u32 var8006096c = 0x00000000;
u32 var80060970 = 0xffffffff;
u32 var80060974 = 0x00000000;
u32 var80060978 = 0x00000000;
u32 var8006097c = 0x00000000;
u32 var80060980 = 0xffffffff;
u32 var80060984 = 0xfa000000;
u32 var80060988 = 0x00000000;
u32 var8006098c = 0x00000000;
u32 var80060990 = 0x00000000;
u32 var80060994 = 0x00000000;
u32 var80060998 = 0x00000000;
u32 var8006099c = 0x00000000;
u32 var800609a0 = 0x20202020;
u32 var800609a4 = 0x20202020;
u32 var800609a8 = 0x20202020;
u32 var800609ac = 0x20202020;
u32 var800609b0 = 0x20202020;
u32 var800609b4 = 0x20202020;
u32 var800609b8 = 0x20202020;
u32 var800609bc = 0x20202020;
u32 var800609c0 = 0x00000000;
u32 var800609c4 = 0x30303030;
u32 var800609c8 = 0x30303030;
u32 var800609cc = 0x30303030;
u32 var800609d0 = 0x30303030;
u32 var800609d4 = 0x30303030;
u32 var800609d8 = 0x30303030;
u32 var800609dc = 0x30303030;
u32 var800609e0 = 0x30303030;
u32 var800609e4 = 0x00000000;
u32 var800609e8 = 0x00000000;
u32 var800609ec = 0x00000000;
u32 var800609f0 = 0x00000032;
u32 var800609f4 = 0x00640096;
u32 var800609f8 = 0x00c900fb;
u32 var800609fc = 0x012d0160;
u32 var80060a00 = 0x019201c4;
u32 var80060a04 = 0x01f70229;
u32 var80060a08 = 0x025b028e;
u32 var80060a0c = 0x02c002f2;
u32 var80060a10 = 0x03240357;
u32 var80060a14 = 0x038903bb;
u32 var80060a18 = 0x03ee0420;
u32 var80060a1c = 0x04520484;
u32 var80060a20 = 0x04b704e9;
u32 var80060a24 = 0x051b054e;
u32 var80060a28 = 0x058005b2;
u32 var80060a2c = 0x05e40617;
u32 var80060a30 = 0x0649067b;
u32 var80060a34 = 0x06ad06e0;
u32 var80060a38 = 0x07120744;
u32 var80060a3c = 0x077607a9;
u32 var80060a40 = 0x07db080d;
u32 var80060a44 = 0x083f0871;
u32 var80060a48 = 0x08a408d6;
u32 var80060a4c = 0x0908093a;
u32 var80060a50 = 0x096c099f;
u32 var80060a54 = 0x09d10a03;
u32 var80060a58 = 0x0a350a67;
u32 var80060a5c = 0x0a990acb;
u32 var80060a60 = 0x0afe0b30;
u32 var80060a64 = 0x0b620b94;
u32 var80060a68 = 0x0bc60bf8;
u32 var80060a6c = 0x0c2a0c5c;
u32 var80060a70 = 0x0c8e0cc0;
u32 var80060a74 = 0x0cf20d25;
u32 var80060a78 = 0x0d570d89;
u32 var80060a7c = 0x0dbb0ded;
u32 var80060a80 = 0x0e1f0e51;
u32 var80060a84 = 0x0e830eb5;
u32 var80060a88 = 0x0ee70f19;
u32 var80060a8c = 0x0f4b0f7c;
u32 var80060a90 = 0x0fae0fe0;
u32 var80060a94 = 0x10121044;
u32 var80060a98 = 0x107610a8;
u32 var80060a9c = 0x10da110c;
u32 var80060aa0 = 0x113e116f;
u32 var80060aa4 = 0x11a111d3;
u32 var80060aa8 = 0x12051237;
u32 var80060aac = 0x1269129a;
u32 var80060ab0 = 0x12cc12fe;
u32 var80060ab4 = 0x13301361;
u32 var80060ab8 = 0x139313c5;
u32 var80060abc = 0x13f61428;
u32 var80060ac0 = 0x145a148c;
u32 var80060ac4 = 0x14bd14ef;
u32 var80060ac8 = 0x15201552;
u32 var80060acc = 0x158415b5;
u32 var80060ad0 = 0x15e71618;
u32 var80060ad4 = 0x164a167b;
u32 var80060ad8 = 0x16ad16df;
u32 var80060adc = 0x17101741;
u32 var80060ae0 = 0x177317a4;
u32 var80060ae4 = 0x17d61807;
u32 var80060ae8 = 0x1839186a;
u32 var80060aec = 0x189b18cd;
u32 var80060af0 = 0x18fe1930;
u32 var80060af4 = 0x19611992;
u32 var80060af8 = 0x19c319f5;
u32 var80060afc = 0x1a261a57;
u32 var80060b00 = 0x1a881aba;
u32 var80060b04 = 0x1aeb1b1c;
u32 var80060b08 = 0x1b4d1b7e;
u32 var80060b0c = 0x1baf1be1;
u32 var80060b10 = 0x1c121c43;
u32 var80060b14 = 0x1c741ca5;
u32 var80060b18 = 0x1cd61d07;
u32 var80060b1c = 0x1d381d69;
u32 var80060b20 = 0x1d9a1dcb;
u32 var80060b24 = 0x1dfc1e2d;
u32 var80060b28 = 0x1e5d1e8e;
u32 var80060b2c = 0x1ebf1ef0;
u32 var80060b30 = 0x1f211f52;
u32 var80060b34 = 0x1f821fb3;
u32 var80060b38 = 0x1fe42015;
u32 var80060b3c = 0x20452076;
u32 var80060b40 = 0x20a720d7;
u32 var80060b44 = 0x21082139;
u32 var80060b48 = 0x2169219a;
u32 var80060b4c = 0x21ca21fb;
u32 var80060b50 = 0x222b225c;
u32 var80060b54 = 0x228c22bd;
u32 var80060b58 = 0x22ed231d;
u32 var80060b5c = 0x234e237e;
u32 var80060b60 = 0x23ae23df;
u32 var80060b64 = 0x240f243f;
u32 var80060b68 = 0x247024a0;
u32 var80060b6c = 0x24d02500;
u32 var80060b70 = 0x25302560;
u32 var80060b74 = 0x259125c1;
u32 var80060b78 = 0x25f12621;
u32 var80060b7c = 0x26512681;
u32 var80060b80 = 0x26b126e1;
u32 var80060b84 = 0x27112740;
u32 var80060b88 = 0x277027a0;
u32 var80060b8c = 0x27d02800;
u32 var80060b90 = 0x2830285f;
u32 var80060b94 = 0x288f28bf;
u32 var80060b98 = 0x28ee291e;
u32 var80060b9c = 0x294e297d;
u32 var80060ba0 = 0x29ad29dd;
u32 var80060ba4 = 0x2a0c2a3c;
u32 var80060ba8 = 0x2a6b2a9b;
u32 var80060bac = 0x2aca2af9;
u32 var80060bb0 = 0x2b292b58;
u32 var80060bb4 = 0x2b872bb7;
u32 var80060bb8 = 0x2be62c15;
u32 var80060bbc = 0x2c442c74;
u32 var80060bc0 = 0x2ca32cd2;
u32 var80060bc4 = 0x2d012d30;
u32 var80060bc8 = 0x2d5f2d8e;
u32 var80060bcc = 0x2dbd2dec;
u32 var80060bd0 = 0x2e1b2e4a;
u32 var80060bd4 = 0x2e792ea8;
u32 var80060bd8 = 0x2ed72f06;
u32 var80060bdc = 0x2f342f63;
u32 var80060be0 = 0x2f922fc0;
u32 var80060be4 = 0x2fef301e;
u32 var80060be8 = 0x304c307b;
u32 var80060bec = 0x30a930d8;
u32 var80060bf0 = 0x31073135;
u32 var80060bf4 = 0x31633192;
u32 var80060bf8 = 0x31c031ef;
u32 var80060bfc = 0x321d324b;
u32 var80060c00 = 0x327932a8;
u32 var80060c04 = 0x32d63304;
u32 var80060c08 = 0x33323360;
u32 var80060c0c = 0x338e33bc;
u32 var80060c10 = 0x33ea3418;
u32 var80060c14 = 0x34463474;
u32 var80060c18 = 0x34a234d0;
u32 var80060c1c = 0x34fe352b;
u32 var80060c20 = 0x35593587;
u32 var80060c24 = 0x35b535e2;
u32 var80060c28 = 0x3610363d;
u32 var80060c2c = 0x366b3698;
u32 var80060c30 = 0x36c636f3;
u32 var80060c34 = 0x3721374e;
u32 var80060c38 = 0x377c37a9;
u32 var80060c3c = 0x37d63803;
u32 var80060c40 = 0x3831385e;
u32 var80060c44 = 0x388b38b8;
u32 var80060c48 = 0x38e53912;
u32 var80060c4c = 0x393f396c;
u32 var80060c50 = 0x399939c6;
u32 var80060c54 = 0x39f33a20;
u32 var80060c58 = 0x3a4d3a79;
u32 var80060c5c = 0x3aa63ad3;
u32 var80060c60 = 0x3b003b2c;
u32 var80060c64 = 0x3b593b85;
u32 var80060c68 = 0x3bb23bde;
u32 var80060c6c = 0x3c0b3c37;
u32 var80060c70 = 0x3c643c90;
u32 var80060c74 = 0x3cbc3ce9;
u32 var80060c78 = 0x3d153d41;
u32 var80060c7c = 0x3d6d3d99;
u32 var80060c80 = 0x3dc53df1;
u32 var80060c84 = 0x3e1d3e49;
u32 var80060c88 = 0x3e753ea1;
u32 var80060c8c = 0x3ecd3ef9;
u32 var80060c90 = 0x3f253f50;
u32 var80060c94 = 0x3f7c3fa8;
u32 var80060c98 = 0x3fd33fff;
u32 var80060c9c = 0x402b4056;
u32 var80060ca0 = 0x408240ad;
u32 var80060ca4 = 0x40d84104;
u32 var80060ca8 = 0x412f415a;
u32 var80060cac = 0x418641b1;
u32 var80060cb0 = 0x41dc4207;
u32 var80060cb4 = 0x4232425d;
u32 var80060cb8 = 0x428842b3;
u32 var80060cbc = 0x42de4309;
u32 var80060cc0 = 0x4334435f;
u32 var80060cc4 = 0x438943b4;
u32 var80060cc8 = 0x43df4409;
u32 var80060ccc = 0x4434445f;
u32 var80060cd0 = 0x448944b4;
u32 var80060cd4 = 0x44de4508;
u32 var80060cd8 = 0x4533455d;
u32 var80060cdc = 0x458745b1;
u32 var80060ce0 = 0x45dc4606;
u32 var80060ce4 = 0x4630465a;
u32 var80060ce8 = 0x468446ae;
u32 var80060cec = 0x46d84702;
u32 var80060cf0 = 0x472c4755;
u32 var80060cf4 = 0x477f47a9;
u32 var80060cf8 = 0x47d247fc;
u32 var80060cfc = 0x4826484f;
u32 var80060d00 = 0x487948a2;
u32 var80060d04 = 0x48cc48f5;
u32 var80060d08 = 0x491e4948;
u32 var80060d0c = 0x4971499a;
u32 var80060d10 = 0x49c349ec;
u32 var80060d14 = 0x4a154a3e;
u32 var80060d18 = 0x4a674a90;
u32 var80060d1c = 0x4ab94ae2;
u32 var80060d20 = 0x4b0b4b33;
u32 var80060d24 = 0x4b5c4b85;
u32 var80060d28 = 0x4bad4bd6;
u32 var80060d2c = 0x4bfe4c27;
u32 var80060d30 = 0x4c4f4c78;
u32 var80060d34 = 0x4ca04cc8;
u32 var80060d38 = 0x4cf04d19;
u32 var80060d3c = 0x4d414d69;
u32 var80060d40 = 0x4d914db9;
u32 var80060d44 = 0x4de14e09;
u32 var80060d48 = 0x4e314e58;
u32 var80060d4c = 0x4e804ea8;
u32 var80060d50 = 0x4ed04ef7;
u32 var80060d54 = 0x4f1f4f46;
u32 var80060d58 = 0x4f6e4f95;
u32 var80060d5c = 0x4fbd4fe4;
u32 var80060d60 = 0x500b5032;
u32 var80060d64 = 0x505a5081;
u32 var80060d68 = 0x50a850cf;
u32 var80060d6c = 0x50f6511d;
u32 var80060d70 = 0x5144516b;
u32 var80060d74 = 0x519151b8;
u32 var80060d78 = 0x51df5205;
u32 var80060d7c = 0x522c5253;
u32 var80060d80 = 0x527952a0;
u32 var80060d84 = 0x52c652ec;
u32 var80060d88 = 0x53135339;
u32 var80060d8c = 0x535f5385;
u32 var80060d90 = 0x53ab53d1;
u32 var80060d94 = 0x53f7541d;
u32 var80060d98 = 0x54435469;
u32 var80060d9c = 0x548f54b5;
u32 var80060da0 = 0x54da5500;
u32 var80060da4 = 0x5525554b;
u32 var80060da8 = 0x55715596;
u32 var80060dac = 0x55bb55e1;
u32 var80060db0 = 0x5606562b;
u32 var80060db4 = 0x56505675;
u32 var80060db8 = 0x569b56c0;
u32 var80060dbc = 0x56e55709;
u32 var80060dc0 = 0x572e5753;
u32 var80060dc4 = 0x5778579d;
u32 var80060dc8 = 0x57c157e6;
u32 var80060dcc = 0x580a582f;
u32 var80060dd0 = 0x58535878;
u32 var80060dd4 = 0x589c58c0;
u32 var80060dd8 = 0x58e55909;
u32 var80060ddc = 0x592d5951;
u32 var80060de0 = 0x59755999;
u32 var80060de4 = 0x59bd59e1;
u32 var80060de8 = 0x5a045a28;
u32 var80060dec = 0x5a4c5a6f;
u32 var80060df0 = 0x5a935ab7;
u32 var80060df4 = 0x5ada5afd;
u32 var80060df8 = 0x5b215b44;
u32 var80060dfc = 0x5b675b8b;
u32 var80060e00 = 0x5bae5bd1;
u32 var80060e04 = 0x5bf45c17;
u32 var80060e08 = 0x5c3a5c5d;
u32 var80060e0c = 0x5c7f5ca2;
u32 var80060e10 = 0x5cc55ce7;
u32 var80060e14 = 0x5d0a5d2d;
u32 var80060e18 = 0x5d4f5d71;
u32 var80060e1c = 0x5d945db6;
u32 var80060e20 = 0x5dd85dfa;
u32 var80060e24 = 0x5e1d5e3f;
u32 var80060e28 = 0x5e615e83;
u32 var80060e2c = 0x5ea55ec6;
u32 var80060e30 = 0x5ee85f0a;
u32 var80060e34 = 0x5f2c5f4d;
u32 var80060e38 = 0x5f6f5f90;
u32 var80060e3c = 0x5fb25fd3;
u32 var80060e40 = 0x5ff46016;
u32 var80060e44 = 0x60376058;
u32 var80060e48 = 0x6079609a;
u32 var80060e4c = 0x60bb60dc;
u32 var80060e50 = 0x60fd611e;
u32 var80060e54 = 0x613e615f;
u32 var80060e58 = 0x618061a0;
u32 var80060e5c = 0x61c161e1;
u32 var80060e60 = 0x62026222;
u32 var80060e64 = 0x62426263;
u32 var80060e68 = 0x628362a3;
u32 var80060e6c = 0x62c362e3;
u32 var80060e70 = 0x63036323;
u32 var80060e74 = 0x63426362;
u32 var80060e78 = 0x638263a1;
u32 var80060e7c = 0x63c163e0;
u32 var80060e80 = 0x6400641f;
u32 var80060e84 = 0x643f645e;
u32 var80060e88 = 0x647d649c;
u32 var80060e8c = 0x64bb64da;
u32 var80060e90 = 0x64f96518;
u32 var80060e94 = 0x65376556;
u32 var80060e98 = 0x65746593;
u32 var80060e9c = 0x65b265d0;
u32 var80060ea0 = 0x65ef660d;
u32 var80060ea4 = 0x662b664a;
u32 var80060ea8 = 0x66686686;
u32 var80060eac = 0x66a466c2;
u32 var80060eb0 = 0x66e066fe;
u32 var80060eb4 = 0x671c673a;
u32 var80060eb8 = 0x67576775;
u32 var80060ebc = 0x679267b0;
u32 var80060ec0 = 0x67cd67eb;
u32 var80060ec4 = 0x68086825;
u32 var80060ec8 = 0x68436860;
u32 var80060ecc = 0x687d689a;
u32 var80060ed0 = 0x68b768d4;
u32 var80060ed4 = 0x68f1690d;
u32 var80060ed8 = 0x692a6947;
u32 var80060edc = 0x69636980;
u32 var80060ee0 = 0x699c69b9;
u32 var80060ee4 = 0x69d569f1;
u32 var80060ee8 = 0x6a0e6a2a;
u32 var80060eec = 0x6a466a62;
u32 var80060ef0 = 0x6a7e6a9a;
u32 var80060ef4 = 0x6ab56ad1;
u32 var80060ef8 = 0x6aed6b08;
u32 var80060efc = 0x6b246b40;
u32 var80060f00 = 0x6b5b6b76;
u32 var80060f04 = 0x6b926bad;
u32 var80060f08 = 0x6bc86be3;
u32 var80060f0c = 0x6bfe6c19;
u32 var80060f10 = 0x6c346c4f;
u32 var80060f14 = 0x6c6a6c84;
u32 var80060f18 = 0x6c9f6cba;
u32 var80060f1c = 0x6cd46cef;
u32 var80060f20 = 0x6d096d23;
u32 var80060f24 = 0x6d3e6d58;
u32 var80060f28 = 0x6d726d8c;
u32 var80060f2c = 0x6da66dc0;
u32 var80060f30 = 0x6dda6df3;
u32 var80060f34 = 0x6e0d6e27;
u32 var80060f38 = 0x6e406e5a;
u32 var80060f3c = 0x6e736e8d;
u32 var80060f40 = 0x6ea66ebf;
u32 var80060f44 = 0x6ed96ef2;
u32 var80060f48 = 0x6f0b6f24;
u32 var80060f4c = 0x6f3d6f55;
u32 var80060f50 = 0x6f6e6f87;
u32 var80060f54 = 0x6fa06fb8;
u32 var80060f58 = 0x6fd16fe9;
u32 var80060f5c = 0x7002701a;
u32 var80060f60 = 0x7032704a;
u32 var80060f64 = 0x7062707a;
u32 var80060f68 = 0x709270aa;
u32 var80060f6c = 0x70c270da;
u32 var80060f70 = 0x70f27109;
u32 var80060f74 = 0x71217138;
u32 var80060f78 = 0x71507167;
u32 var80060f7c = 0x717e7196;
u32 var80060f80 = 0x71ad71c4;
u32 var80060f84 = 0x71db71f2;
u32 var80060f88 = 0x72097220;
u32 var80060f8c = 0x7236724d;
u32 var80060f90 = 0x7264727a;
u32 var80060f94 = 0x729172a7;
u32 var80060f98 = 0x72bd72d4;
u32 var80060f9c = 0x72ea7300;
u32 var80060fa0 = 0x7316732c;
u32 var80060fa4 = 0x73427358;
u32 var80060fa8 = 0x736e7383;
u32 var80060fac = 0x739973ae;
u32 var80060fb0 = 0x73c473d9;
u32 var80060fb4 = 0x73ef7404;
u32 var80060fb8 = 0x7419742e;
u32 var80060fbc = 0x74437458;
u32 var80060fc0 = 0x746d7482;
u32 var80060fc4 = 0x749774ac;
u32 var80060fc8 = 0x74c074d5;
u32 var80060fcc = 0x74ea74fe;
u32 var80060fd0 = 0x75127527;
u32 var80060fd4 = 0x753b754f;
u32 var80060fd8 = 0x75637577;
u32 var80060fdc = 0x758b759f;
u32 var80060fe0 = 0x75b375c7;
u32 var80060fe4 = 0x75da75ee;
u32 var80060fe8 = 0x76017615;
u32 var80060fec = 0x7628763b;
u32 var80060ff0 = 0x764f7662;
u32 var80060ff4 = 0x76757688;
u32 var80060ff8 = 0x769b76ae;
u32 var80060ffc = 0x76c176d3;
u32 var80061000 = 0x76e676f9;
u32 var80061004 = 0x770b771e;
u32 var80061008 = 0x77307742;
u32 var8006100c = 0x77547767;
u32 var80061010 = 0x7779778b;
u32 var80061014 = 0x779d77af;
u32 var80061018 = 0x77c077d2;
u32 var8006101c = 0x77e477f5;
u32 var80061020 = 0x78077818;
u32 var80061024 = 0x782a783b;
u32 var80061028 = 0x784c785d;
u32 var8006102c = 0x786e787f;
u32 var80061030 = 0x789078a1;
u32 var80061034 = 0x78b278c3;
u32 var80061038 = 0x78d378e4;
u32 var8006103c = 0x78f47905;
u32 var80061040 = 0x79157925;
u32 var80061044 = 0x79367946;
u32 var80061048 = 0x79567966;
u32 var8006104c = 0x79767985;
u32 var80061050 = 0x799579a5;
u32 var80061054 = 0x79b579c4;
u32 var80061058 = 0x79d479e3;
u32 var8006105c = 0x79f27a02;
u32 var80061060 = 0x7a117a20;
u32 var80061064 = 0x7a2f7a3e;
u32 var80061068 = 0x7a4d7a5b;
u32 var8006106c = 0x7a6a7a79;
u32 var80061070 = 0x7a877a96;
u32 var80061074 = 0x7aa47ab3;
u32 var80061078 = 0x7ac17acf;
u32 var8006107c = 0x7add7aeb;
u32 var80061080 = 0x7af97b07;
u32 var80061084 = 0x7b157b23;
u32 var80061088 = 0x7b317b3e;
u32 var8006108c = 0x7b4c7b59;
u32 var80061090 = 0x7b677b74;
u32 var80061094 = 0x7b817b8e;
u32 var80061098 = 0x7b9b7ba8;
u32 var8006109c = 0x7bb57bc2;
u32 var800610a0 = 0x7bcf7bdc;
u32 var800610a4 = 0x7be87bf5;
u32 var800610a8 = 0x7c027c0e;
u32 var800610ac = 0x7c1a7c27;
u32 var800610b0 = 0x7c337c3f;
u32 var800610b4 = 0x7c4b7c57;
u32 var800610b8 = 0x7c637c6f;
u32 var800610bc = 0x7c7a7c86;
u32 var800610c0 = 0x7c927c9d;
u32 var800610c4 = 0x7ca97cb4;
u32 var800610c8 = 0x7cbf7ccb;
u32 var800610cc = 0x7cd67ce1;
u32 var800610d0 = 0x7cec7cf7;
u32 var800610d4 = 0x7d027d0c;
u32 var800610d8 = 0x7d177d22;
u32 var800610dc = 0x7d2c7d37;
u32 var800610e0 = 0x7d417d4b;
u32 var800610e4 = 0x7d567d60;
u32 var800610e8 = 0x7d6a7d74;
u32 var800610ec = 0x7d7e7d88;
u32 var800610f0 = 0x7d917d9b;
u32 var800610f4 = 0x7da57dae;
u32 var800610f8 = 0x7db87dc1;
u32 var800610fc = 0x7dcb7dd4;
u32 var80061100 = 0x7ddd7de6;
u32 var80061104 = 0x7def7df8;
u32 var80061108 = 0x7e017e0a;
u32 var8006110c = 0x7e137e1b;
u32 var80061110 = 0x7e247e2c;
u32 var80061114 = 0x7e357e3d;
u32 var80061118 = 0x7e457e4d;
u32 var8006111c = 0x7e567e5e;
u32 var80061120 = 0x7e667e6d;
u32 var80061124 = 0x7e757e7d;
u32 var80061128 = 0x7e857e8c;
u32 var8006112c = 0x7e947e9b;
u32 var80061130 = 0x7ea37eaa;
u32 var80061134 = 0x7eb17eb8;
u32 var80061138 = 0x7ebf7ec6;
u32 var8006113c = 0x7ecd7ed4;
u32 var80061140 = 0x7edb7ee1;
u32 var80061144 = 0x7ee87eee;
u32 var80061148 = 0x7ef57efb;
u32 var8006114c = 0x7f017f08;
u32 var80061150 = 0x7f0e7f14;
u32 var80061154 = 0x7f1a7f20;
u32 var80061158 = 0x7f257f2b;
u32 var8006115c = 0x7f317f36;
u32 var80061160 = 0x7f3c7f41;
u32 var80061164 = 0x7f477f4c;
u32 var80061168 = 0x7f517f56;
u32 var8006116c = 0x7f5b7f60;
u32 var80061170 = 0x7f657f6a;
u32 var80061174 = 0x7f6f7f74;
u32 var80061178 = 0x7f787f7d;
u32 var8006117c = 0x7f817f85;
u32 var80061180 = 0x7f8a7f8e;
u32 var80061184 = 0x7f927f96;
u32 var80061188 = 0x7f9a7f9e;
u32 var8006118c = 0x7fa27fa6;
u32 var80061190 = 0x7fa97fad;
u32 var80061194 = 0x7fb07fb4;
u32 var80061198 = 0x7fb77fba;
u32 var8006119c = 0x7fbe7fc1;
u32 var800611a0 = 0x7fc47fc7;
u32 var800611a4 = 0x7fca7fcc;
u32 var800611a8 = 0x7fcf7fd2;
u32 var800611ac = 0x7fd47fd7;
u32 var800611b0 = 0x7fd97fdc;
u32 var800611b4 = 0x7fde7fe0;
u32 var800611b8 = 0x7fe27fe4;
u32 var800611bc = 0x7fe67fe8;
u32 var800611c0 = 0x7fea7fec;
u32 var800611c4 = 0x7fed7fef;
u32 var800611c8 = 0x7ff17ff2;
u32 var800611cc = 0x7ff37ff5;
u32 var800611d0 = 0x7ff67ff7;
u32 var800611d4 = 0x7ff87ff9;
u32 var800611d8 = 0x7ffa7ffb;
u32 var800611dc = 0x7ffb7ffc;
u32 var800611e0 = 0x7ffd7ffd;
u32 var800611e4 = 0x7ffe7ffe;
u32 var800611e8 = 0x7ffe7ffe;
u32 var800611ec = 0x7ffe7fff;
u32 var800611f0 = 0xceed6666;
u32 var800611f4 = 0xcc0d000b;
u32 var800611f8 = 0x03730083;
u32 var800611fc = 0x000c000d;
u32 var80061200 = 0x0008111f;
u32 var80061204 = 0x8889000e;
u32 var80061208 = 0xdccc6ee6;
u32 var8006120c = 0xddddd999;
u32 var80061210 = 0xbbbb6763;
u32 var80061214 = 0x6e0eeccc;
u32 var80061218 = 0xdddc999f;
u32 var8006121c = 0xbbb9333e;
u32 var80061220 = 0x00010101;
u32 var80061224 = 0xff0202ff;
u32 var80061228 = 0x0000ffff;
u32 var8006122c = 0xffffff03;
u32 var80061230 = 0x03030303;
u32 var80061234 = 0x00000000;
u32 var80061238 = 0x00000000;
u32 var8006123c = 0x00000000;
u32 var80061240 = 0x10000000;
u32 var80061244 = 0x0000311e;
u32 var80061248 = 0x00000140;
u32 var8006124c = 0x04541e3a;
u32 var80061250 = 0x00000271;
u32 var80061254 = 0x00170c69;
u32 var80061258 = 0x0c6f0c6d;
u32 var8006125c = 0x00800300;
u32 var80061260 = 0x00000200;
u32 var80061264 = 0x00000000;
u32 var80061268 = 0x00000280;
u32 var8006126c = 0x00000400;
u32 var80061270 = 0x005f0239;
u32 var80061274 = 0x0009026b;
u32 var80061278 = 0x00000002;
u32 var8006127c = 0x00000280;
u32 var80061280 = 0x00000400;
u32 var80061284 = 0x005f0239;
u32 var80061288 = 0x0009026b;
u32 var8006128c = 0x00000002;
u32 var80061290 = 0x1e000000;
u32 var80061294 = 0x0000311e;
u32 var80061298 = 0x00000140;
u32 var8006129c = 0x04651e39;
u32 var800612a0 = 0x0000020d;
u32 var800612a4 = 0x00040c11;
u32 var800612a8 = 0x0c190c1a;
u32 var800612ac = 0x006c02ec;
u32 var800612b0 = 0x00000200;
u32 var800612b4 = 0x00000000;
u32 var800612b8 = 0x00000280;
u32 var800612bc = 0x00000400;
u32 var800612c0 = 0x002501ff;
u32 var800612c4 = 0x000e0204;
u32 var800612c8 = 0x00000002;
u32 var800612cc = 0x00000280;
u32 var800612d0 = 0x00000400;
u32 var800612d4 = 0x002501ff;
u32 var800612d8 = 0x000e0204;
u32 var800612dc = 0x00000002;
u32 var800612e0 = 0x02000000;
u32 var800612e4 = 0x0000311e;
u32 var800612e8 = 0x00000140;
u32 var800612ec = 0x03e52239;
u32 var800612f0 = 0x0000020d;
u32 var800612f4 = 0x00000c15;
u32 var800612f8 = 0x0c150c15;
u32 var800612fc = 0x006c02ec;
u32 var80061300 = 0x00000200;
u32 var80061304 = 0x00000000;
u32 var80061308 = 0x00000280;
u32 var8006130c = 0x00000400;
u32 var80061310 = 0x002501ff;
u32 var80061314 = 0x000e0204;
u32 var80061318 = 0x00000002;
u32 var8006131c = 0x00000280;
u32 var80061320 = 0x00000400;
u32 var80061324 = 0x002501ff;
u32 var80061328 = 0x000e0204;
u32 var8006132c = 0x00000002;
u32 var80061330 = 0x30313233;
u32 var80061334 = 0x34353637;
u32 var80061338 = 0x38396162;
u32 var8006133c = 0x63646566;
u32 var80061340 = 0x00000000;
u32 var80061344 = 0x30313233;
u32 var80061348 = 0x34353637;
u32 var8006134c = 0x38394142;
u32 var80061350 = 0x43444546;
u32 var80061354 = 0x00000000;
u32 var80061358 = 0x00000000;
u32 var8006135c = 0x00000000;
u32 var80061360 = 0xb6000000;
u32 var80061364 = 0x001f3204;
u32 var80061368 = 0xbb000000;
u32 var8006136c = 0x00000000;
u32 var80061370 = 0xb7000000;
u32 var80061374 = 0x00000204;
u32 var80061378 = 0xb8000000;
u32 var8006137c = 0x00000000;
u32 var80061380 = 0xb6000000;
u32 var80061384 = 0x001f3204;
u32 var80061388 = 0xbb000000;
u32 var8006138c = 0x00000000;
u32 var80061390 = 0xb7000000;
u32 var80061394 = 0x00000205;
u32 var80061398 = 0xb8000000;
u32 var8006139c = 0x00000000;
u32 var800613a0 = 0xba001402;
u32 var800613a4 = 0x00000000;
u32 var800613a8 = 0xba001701;
u32 var800613ac = 0x00800000;
u32 var800613b0 = 0xba001001;
u32 var800613b4 = 0x00000000;
u32 var800613b8 = 0xba000e02;
u32 var800613bc = 0x00000000;
u32 var800613c0 = 0xba001102;
u32 var800613c4 = 0x00000000;
u32 var800613c8 = 0xba001301;
u32 var800613cc = 0x00080000;
u32 var800613d0 = 0xba000c02;
u32 var800613d4 = 0x00002000;
u32 var800613d8 = 0xba000903;
u32 var800613dc = 0x00000c00;
u32 var800613e0 = 0xfcffffff;
u32 var800613e4 = 0xfffe793c;
u32 var800613e8 = 0xba000801;
u32 var800613ec = 0x00000000;
u32 var800613f0 = 0xb9000002;
u32 var800613f4 = 0x00000000;
u32 var800613f8 = 0xb900031d;
u32 var800613fc = 0x0f0a4000;
u32 var80061400 = 0xba000602;
u32 var80061404 = 0x00000000;
u32 var80061408 = 0xba000402;
u32 var8006140c = 0x00000000;
u32 var80061410 = 0xe7000000;
u32 var80061414 = 0x00000000;
u32 var80061418 = 0xb8000000;
u32 var8006141c = 0x00000000;
struct var80061420 *var80061420 = NULL;
u32 var80061424 = 0x00000000;
u32 var80061428 = 0x00000000;
u32 var8006142c = 0x00000000;
u16 **var80061430 = NULL;
u32 var80061434 = 0x00000000;
u32 var80061438 = 0x00000000;
u32 var8006143c = 0x42480000;
u32 var80061440 = 0x00000000;
u32 var80061444 = 1;
u32 var80061448 = 0x00000000;
u32 var8006144c = 0x00000000;
u32 var80061450 = 0x00000000;
u32 var80061454 = 0xffffffff;
s32 var80061458 = 0x00000000;
u32 var8006145c = 0x00000000;
u32 var80061460 = 0x96969600;
u32 var80061464 = 0x96969600;
u32 var80061468 = 0xffffff00;
u32 var8006146c = 0xffffff00;
u32 var80061470 = 0x4d4d2e00;
u32 var80061474 = 0x00000000;
u32 var80061478 = 0x00000000;
u32 var8006147c = 0x00000000;

s32 g_FootstepSounds[] = {
	/* none   */     -1,     -1,     -1,     -1,     -1,     -1,     -1,     -1,
	/* wood   */ 0x80dc, 0x80dd, 0x80e0, 0x80e1, 0x80de, 0x80df, 0x80e2, 0x80e3,
	/* stone  */ 0x80c4, 0x80c5, 0x80c8, 0x80c9, 0x80c6, 0x80c7, 0x80ca, 0x80cb,
	/* carpet */ 0x80e6, 0x80e7, 0x80ea, 0x80eb, 0x80e8, 0x80e9, 0x80ec, 0x80ed,
	/* metal  */ 0x80d4, 0x80d5, 0x80d8, 0x80d9, 0x80d6, 0x80d7, 0x80da, 0x80db,
	/* mud    */ 0x80ee, 0x80ef, 0x80f2, 0x80f3, 0x80f0, 0x80f1, 0x80f4, 0x80f5,
	/* water  */ 0x80e4, 0x80e5, 0x80e4, 0x80e5, 0x80e4, 0x80e5, 0x80e4, 0x80e5,
	/* dirt   */ 0x80cc, 0x80cd, 0x80d0, 0x80d1, 0x80ce, 0x80cf, 0x80d2, 0x80d3,
	/* snow   */ 0x8187, 0x8188, 0x818b, 0x818c, 0x8189, 0x818a, 0x818d, 0x818e,
};

u16 var800615a0[][2] = {
	{ 0x002b, 0x0819 }, { 0x0029, 0x050e }, { 0x006b, 0x0819 }, { 0x0028, 0x1b08 },
	{ 0x002a, 0x1206 }, { 0x0052, 0x0819 }, { 0x0053, 0x1908 }, { 0x0054, 0x1908 },
	{ 0x0055, 0x0712 }, { 0x0056, 0x0712 }, { 0x0057, 0x1207 }, { 0x0058, 0x0f05 },
	{ 0x0059, 0x0814 }, { 0x005a, 0x060f }, { 0x006c, 0x1908 }, { 0x006d, 0x1908 },
	{ 0x006e, 0x0813 }, { 0x006f, 0x1508 }, { 0x0070, 0x0f05 }, { 0x0071, 0x0f05 },
	{ 0x0072, 0x1708 }, { 0x0073, 0x0813 }, { 0x0093, 0x170a }, { 0x0094, 0x0f05 },
	{ 0x005f, 0x0e01 }, { 0x0016, 0x1d0a }, { 0x0018, 0x182e }, { 0x001b, 0x0a1c },
	{ 0x001d, 0x0d02 }, { 0x001e, 0x0c01 }, { 0x005c, 0x132a }, { 0x005d, 0x0f05 },
	{ 0x005e, 0x040c }, { 0x0392, 0x0514 }, { 0x0394, 0x0000 },
};

u32 var8006162c = 0x00000000;
f32 var80061630 = 0;
u32 var80061634 = 0x00000000;
u32 var80061638 = 0x00000000;
u32 var8006163c = 0x00000000;
u32 var80061640 = 0x00000000;
u32 var80061644 = 0x42c80000;
u32 var80061648 = 0x00000000;
u32 var8006164c = 0x00000000;
u32 var80061650 = 0x00000000;
u32 var80061654 = 0x3f800000;
u32 var80061658 = 0x3f800000;
u32 var8006165c = 0x00000000;
u32 var80061660 = 0x00000000;
u32 var80061664 = 0x00000000;
u32 var80061668 = 0x00000000;
u32 var8006166c = 0xbf800000;
u32 var80061670 = 0xbf800000;
u32 var80061674 = 0x00000000;
u32 var80061678 = 0x00000000;
u32 var8006167c = 0x00000000;
u32 var80061680 = 0x3f800000;
u32 var80061684 = 0x00000000;
u32 var80061688 = 0x00000000;
u32 var8006168c = 0xbf800000;
u32 var80061690 = 0x00000000;
u32 var80061694 = 0x00000000;
u32 var80061698 = 0x00000000;
u32 var8006169c = 0x3f800000;
u32 var800616a0 = 0x3f800000;
u32 var800616a4 = 0x00000000;
u32 var800616a8 = 0x00000000;
u32 var800616ac = 0x00000000;
u32 var800616b0 = 0x00000000;
u32 var800616b4 = 0xbf800000;
u32 var800616b8 = 0xbf800000;
u32 var800616bc = 0x00000000;
u32 var800616c0 = 0x00000000;
u32 var800616c4 = 0x00000000;
u32 var800616c8 = 0x3f800000;
u32 var800616cc = 0x00000000;
u32 var800616d0 = 0x00000000;
u32 var800616d4 = 0xbf800000;
u32 var800616d8 = 0x00000000;
u32 var800616dc = 0x00000a30;
u32 var800616e0 = 0x00000330;
u32 var800616e4 = 0x00000000;
u32 var800616e8 = 0x00000000;
u32 var800616ec = 0x00000000;
u32 var800616f0 = 0x00000000;
u32 var800616f4 = 0x00000000;
u32 var800616f8 = 0x00000000;
u32 var800616fc = 0x00000000;
u32 var80061700 = 0x2f053504;
u32 var80061704 = 0x19050000;
u32 var80061708 = 0x00000000;
u32 var8006170c = 0x00000000;
u32 var80061710 = 0x00000000;
u32 var80061714 = 0x00000000;
u32 var80061718 = 0x00000000;
u32 var8006171c = 0x00000000;
u32 var80061720 = 0x00000000;
u32 var80061724 = 0x00000000;
u32 var80061728 = 0x00000000;
u32 var8006172c = 0x00000000;
u32 var80061730 = 0x00000000;
u32 var80061734 = 0x00000000;
u32 var80061738 = 0x00000000;
u32 var8006173c = 0x00000000;
u32 var80061740 = 0x00000000;
u32 var80061744 = 0x00000000;
u32 var80061748 = 0x00000000;
u32 var8006174c = 0x00000000;
u32 var80061750 = 0x00000000;
u32 var80061754 = 0x00000000;
u32 var80061758 = 0x00000000;
u32 var8006175c = 0x00000000;
u32 var80061760 = 0x00000000;
u32 var80061764 = 0x00000000;
u32 var80061768 = 0x00000000;
u32 var8006176c = 0x00000000;
u32 var80061770 = 0x00000000;
u32 var80061774 = 0x00000000;
u32 var80061778 = 0x00000000;
u32 var8006177c = 0x00000000;
u32 var80061780 = 0x00000000;
u32 var80061784 = 0x00000000;
u32 var80061788 = 0x00000000;
u32 var8006178c = 0x00000000;
u32 var80061790 = 0x00000000;
u32 var80061794 = 0x00000000;
u32 var80061798 = 0x00000000;
u32 var8006179c = 0x00000000;
u32 var800617a0 = 0x00000000;
u32 var800617a4 = 0x00000000;
u32 var800617a8 = 0x00000000;
u32 var800617ac = 0x00000000;
u32 var800617b0 = 0x00000000;
u32 var800617b4 = 0x00000000;
u32 var800617b8 = 0x00000000;
u32 var800617bc = 0x00000000;
u32 var800617c0 = 0x00000000;
u32 var800617c4 = 0x00000000;
u32 var800617c8 = 0x00000000;
u32 var800617cc = 0x00000000;
u32 var800617d0 = 0x00000000;
u32 var800617d4 = 0x00000000;
u32 var800617d8 = 0x00000000;
u32 var800617dc = 0x00000000;
u32 var800617e0 = 0x00000000;
u32 var800617e4 = 0x00000000;
u32 var800617e8 = 0x00000000;
u32 var800617ec = 0x00000000;
u32 var800617f0 = 0x00000000;
u32 var800617f4 = 0x00000000;
u32 var800617f8 = 0x00000000;
u32 var800617fc = 0x00000000;
u32 var80061800 = 0x00000000;
u32 var80061804 = 0x00000000;
u32 var80061808 = 0x00000000;
u32 var8006180c = 0x00000000;
u32 var80061810 = 0x00000000;
u32 var80061814 = 0x00000000;
u32 var80061818 = 0x00000000;
u32 var8006181c = 0x00000000;
u32 var80061820 = 0x00000000;
u32 var80061824 = 0x00000000;
u32 var80061828 = 0x00000000;
u32 var8006182c = 0x00000000;
u32 var80061830 = 0x00000000;
u32 var80061834 = 0x00000000;
u32 var80061838 = 0x00000000;
u32 var8006183c = 0x00000000;
u32 var80061840 = 0x00000000;
u32 var80061844 = 0x00000000;
u32 var80061848 = 0x00000000;
u32 var8006184c = 0x00000000;
u32 var80061850 = 0x00000000;
u32 var80061854 = 0x00000000;
u32 var80061858 = 0x00000000;
u32 var8006185c = 0x00000000;
u32 var80061860 = 0x00000000;
u32 var80061864 = 0x00000000;
u32 var80061868 = 0x00000000;
u32 var8006186c = 0x00000000;
u32 var80061870 = 0x00000000;
u32 var80061874 = 0x00000000;
u32 var80061878 = 0x00000000;
u32 var8006187c = 0x00000000;
u32 var80061880 = 0x00000000;
u32 var80061884 = 0x00000000;
u32 var80061888 = 0x00000000;
u32 var8006188c = 0x00000000;
u32 var80061890 = 0x00000000;
u32 var80061894 = 0x00000000;
u32 var80061898 = 0x00000000;
u32 var8006189c = 0x00000000;
u32 var800618a0 = 0x00000000;
u32 var800618a4 = 0x00000000;
u32 var800618a8 = 0x00000000;
u32 var800618ac = 0x00000000;
u32 var800618b0 = 0x00000000;
u32 var800618b4 = 0x00000000;
u32 var800618b8 = 0x00000000;
u32 var800618bc = 0x00000000;
u32 var800618c0 = 0x00000000;
u32 var800618c4 = 0x00000000;
u32 var800618c8 = 0x00000000;
u32 var800618cc = 0x00000000;
u32 var800618d0 = 0x00000000;
u32 var800618d4 = 0x00000000;
u32 var800618d8 = 0x00000000;
u32 var800618dc = 0x00000000;
u32 var800618e0 = 0x00000000;
u32 var800618e4 = 0x00000000;
u32 var800618e8 = 0x00000000;
u32 var800618ec = 0x00000000;
u32 var800618f0 = 0x00000000;
u32 var800618f4 = 0x00000000;
u32 var800618f8 = 0x00000000;
u32 var800618fc = 0x00000000;
u32 var80061900 = 0x00000000;
u32 var80061904 = 0x00000000;
u32 var80061908 = 0x00000000;
u32 var8006190c = 0x00000000;
u32 var80061910 = 0x00000000;
u32 var80061914 = 0x00000000;
u32 var80061918 = 0x00000000;
u32 var8006191c = 0x00000000;
u32 var80061920 = 0x00000000;
u32 var80061924 = 0x00000000;
u32 var80061928 = 0x00000000;
u32 var8006192c = 0x00000000;
u32 var80061930 = 0x00000000;
u32 var80061934 = 0x00000000;
u32 var80061938 = 0x00000000;
u32 var8006193c = 0x00000000;
u32 var80061940 = 0x00000000;
u32 var80061944 = 0x00000000;
u32 var80061948 = 0x00000000;
u32 var8006194c = 0x00000000;
u32 var80061950 = 0x00000000;
u32 var80061954 = 0x00000000;
u32 var80061958 = 0x00000000;
u32 var8006195c = 0x00000000;
u32 var80061960 = 0x00000000;
u32 var80061964 = 0x00000000;
u32 var80061968 = 0x00000000;
u32 var8006196c = 0x00000000;
u32 var80061970 = 0x00000000;
u32 var80061974 = 0x00000000;
u32 var80061978 = 0x00000000;
u32 var8006197c = 0x00000000;
u32 var80061980 = 0x00000000;
u32 var80061984 = 0x00000000;
u32 var80061988 = 0x00000000;
u32 var8006198c = 0x00000000;
u32 var80061990 = 0x00000000;
u32 var80061994 = 0x00000000;
u32 var80061998 = 0x00000000;
u32 var8006199c = 0x00000000;
u32 var800619a0 = 0x00000000;
u32 var800619a4 = 0x00000000;
u32 var800619a8 = 0x00000000;
u32 var800619ac = 0x00000000;
u32 var800619b0 = 0x00000000;
u32 var800619b4 = 0x00000000;
u32 var800619b8 = 0x00000000;
u32 var800619bc = 0x00000000;
u32 var800619c0 = 0x00000000;
u32 var800619c4 = 0x00000000;
u32 var800619c8 = 0x00000000;
u32 var800619cc = 0x00000000;
u32 var800619d0 = 0x00000000;
u32 var800619d4 = 0x00000000;
u32 var800619d8 = 0x00000000;
u32 var800619dc = 0x00000000;
u32 var800619e0 = 0x00000000;
u32 var800619e4 = 0x00000000;
u32 var800619e8 = 0x00000000;
u32 var800619ec = 0x00000000;
u32 var800619f0 = 0x00000000;
u32 var800619f4 = 0x00000000;
u32 var800619f8 = 0x00000000;
u32 var800619fc = 0x00000000;
u32 var80061a00 = 0x00000000;
u32 var80061a04 = 0x00000000;
u32 var80061a08 = 0x00000000;
u32 var80061a0c = 0x00000000;
u32 var80061a10 = 0x00000000;
u32 var80061a14 = 0x00000000;
u32 var80061a18 = 0x00000000;
u32 var80061a1c = 0x00000000;
u32 var80061a20 = 0x00000000;
u32 var80061a24 = 0x00000000;
u32 var80061a28 = 0x00000000;
u32 var80061a2c = 0x00000000;
u32 var80061a30 = 0x00000000;
u32 var80061a34 = 0x00000000;
u32 var80061a38 = 0x00000000;
u32 var80061a3c = 0x00000000;
u32 var80061a40 = 0x00000000;
u32 var80061a44 = 0x00000000;
u32 var80061a48 = 0x00000000;
u32 var80061a4c = 0x00000000;
u32 var80061a50 = 0x00000000;
u32 var80061a54 = 0x00000000;
u32 var80061a58 = 0x00000000;
u32 var80061a5c = 0x00000000;
u32 var80061a60 = 0x00000000;
u32 var80061a64 = 0x00000000;
u32 var80061a68 = 0x00000000;
u32 var80061a6c = 0x00000000;
u32 var80061a70 = 0x00000000;
u32 var80061a74 = 0x00000000;
u32 var80061a78 = 0x00000000;
u32 var80061a7c = 0x00000000;

struct monitorscreen var80061a80 = {
	(u32) &var80069d90,
	0x0000ffff,
	0x00000000,
	0x00000000,
	0x3f800000,
	0x00000000,
	0x00000000,
	0x3f800000,
	0x3f800000,
	0x3f800000,
	0x00000000,
	0x00000000,
	0x3f800000,
	0x3f800000,
	0x3f000000,
	0x00000000,
	0x00000000,
	0x3f000000,
	0x3f000000,
	0x3f000000,
	0x00000000,
	0x00000000,
	0x3f000000,
	0x3f000000,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0x3f800000,
	0x00000000,
};

struct monitorscreen var80061af4 = {
	(u32) &var8006aaa0,
	0x0000ffff,
	0x00000000,
	0x00000000,
	0x3f800000,
	0x00000000,
	0x00000000,
	0x3f800000,
	0x3f800000,
	0x3f800000,
	0x00000000,
	0x00000000,
	0x3f800000,
	0x3f800000,
	0x3f000000,
	0x00000000,
	0x00000000,
	0x3f000000,
	0x3f000000,
	0x3f000000,
	0x00000000,
	0x00000000,
	0x3f000000,
	0x3f000000,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0x3f800000,
	0x00000000,
};

struct monitorscreen var80061b68 = {
	(u32) &var8006aae4,
	0x0000ffff,
	0x00000000,
	0x00000000,
	0x3f800000,
	0x00000000,
	0x00000000,
	0x3f800000,
	0x3f800000,
	0x3f800000,
	0x00000000,
	0x00000000,
	0x3f800000,
	0x3f800000,
	0x3f000000,
	0x00000000,
	0x00000000,
	0x3f000000,
	0x3f000000,
	0x3f000000,
	0x00000000,
	0x00000000,
	0x3f000000,
	0x3f000000,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0x3f800000,
	0x00000000,
};

u32 var80061bdc = 0x00000000;
f32 g_DoorScale = 1;
u32 var80061be4 = 0x00000000;
u32 var80061be8 = 0x00000000;
u32 var80061bec = 0x00000000;
u32 var80061bf0 = 0x00000000;
u32 var80061bf4 = 0x00000100;
u32 var80061bf8 = 0x00000000;
u32 var80061bfc = 0x00000000;
u32 var80061c00 = 0x00000000;
u32 var80061c04 = 0x00000000;
u32 var80061c08 = 0x00000000;
u32 var80061c0c = 0x00000000;
u32 var80061c10 = 0x00000000;
u32 var80061c14 = 0x00000000;
u32 var80061c18 = 0x00000000;
u32 var80061c1c = 0x00000000;
u32 var80061c20 = 0x00000000;
u32 var80061c24 = 0x00000000;
u32 var80061c28 = 0x00000000;
u32 var80061c2c = 0x00000000;
u32 var80061c30 = 0x00000000;
u32 var80061c34 = 0x00000000;
u32 var80061c38 = 0x00000000;
u32 var80061c3c = 0x00000000;
u32 var80061c40 = 0x00000000;
u32 var80061c44 = 0x00000000;
u32 var80061c48 = 0x00000000;
u32 var80061c4c = 0x00000000;
u32 var80061c50 = 0x00000000;
u32 var80061c54 = 0x00000000;
u32 var80061c58 = 0x00000000;
u32 var80061c5c = 0x00000000;
u32 var80061c60 = 0x00000000;
u32 var80061c64 = 0x3f800000;
u32 var80061c68 = 0x00000000;
u32 var80061c6c = 0x00000000;
u32 var80061c70 = 0x00000000;
u32 var80061c74 = 0x00000000;
u32 var80061c78 = 0x3f800000;
u32 var80061c7c = 0x00000000;
u32 var80061c80 = 0x00000000;
u32 var80061c84 = 0x00000000;
u32 var80061c88 = 0x00000000;
u32 var80061c8c = 0x3f800000;
u32 var80061c90 = 0x00000000;
u32 var80061c94 = 0x00000000;
u32 var80061c98 = 0x00000000;
u32 var80061c9c = 0x00000000;
u32 var80061ca0 = 0x3f800000;
u32 var80061ca4 = 0x00000000;
u32 var80061ca8 = 0x00000000;
u32 var80061cac = 0x00000000;
u32 var80061cb0 = 0x00000000;
u32 var80061cb4 = 0x00000000;
u32 var80061cb8 = 0x00000000;
u32 var80061cbc = 0xbf800000;
u32 var80061cc0 = 0x00000000;
u32 var80061cc4 = 0x3f800000;
u32 var80061cc8 = 0x00000000;
u32 var80061ccc = 0x00000000;
u32 var80061cd0 = 0x00000000;
u32 var80061cd4 = 0x00000000;
u32 var80061cd8 = 0x00000000;
u32 var80061cdc = 0x00000000;
u32 var80061ce0 = 0xc19ffffe;
u32 var80061ce4 = 0x00000000;
u32 var80061ce8 = 0x419ffffe;
u32 var80061cec = 0x00000000;
u32 var80061cf0 = 0x00000000;
u32 var80061cf4 = 0x00000000;
u32 var80061cf8 = 0x00000000;
u32 var80061cfc = 0x00000000;
u32 var80061d00 = 0x00000000;
u32 var80061d04 = 0x00000000;
u32 var80061d08 = 0x00000000;
u32 var80061d0c = 0x00000000;
u32 var80061d10 = 0x00000000;
u32 var80061d14 = 0x00000000;
u32 var80061d18 = 0x00000000;
u32 var80061d1c = 0x00000000;
u32 var80061d20 = 0x00000000;
u32 var80061d24 = 0x00000000;
u32 var80061d28 = 0xbf800000;
u32 var80061d2c = 0x00000000;
u32 var80061d30 = 0x00000000;
u32 var80061d34 = 0xbf800000;
u32 var80061d38 = 0x00000000;
u32 var80061d3c = 0x00000000;
u32 var80061d40 = 0xbf800000;
u32 var80061d44 = 0x00000000;
u32 var80061d48 = 0x00000000;
u32 var80061d4c = 0xbf800000;
u32 var80061d50 = 0x00000000;
u32 var80061d54 = 0x3f800000;
u32 var80061d58 = 0x00000000;
u32 var80061d5c = 0x00000000;
u32 var80061d60 = 0x3f800000;
u32 var80061d64 = 0x00000000;
u32 var80061d68 = 0x00000000;
u32 var80061d6c = 0x3f800000;
u32 var80061d70 = 0x00000000;
u32 var80061d74 = 0x00000000;
u32 var80061d78 = 0x3f800000;
u32 var80061d7c = 0x00000000;
u32 var80061d80 = 0x00000000;
u32 var80061d84 = 0x00000000;
u32 var80061d88 = 0x3f800000;
u32 var80061d8c = 0x3f800000;
u32 var80061d90 = 0x00000000;
u32 var80061d94 = 0x00000000;
u32 var80061d98 = 0x00000000;
u32 var80061d9c = 0x00000000;
u32 var80061da0 = 0x00000000;
u32 var80061da4 = 0x00000000;
u32 var80061da8 = 0x00000000;
u32 var80061dac = 0x00000000;
u32 var80061db0 = 0x00000000;
u32 var80061db4 = 0x00000000;
u32 var80061db8 = 0x447a0000;
u32 var80061dbc = 0x00000000;
u32 var80061dc0 = 0x00000000;
u32 var80061dc4 = 0x00000000;
u32 var80061dc8 = 0x00000000;
u32 var80061dcc = 0xff000000;
u32 var80061dd0 = 0x00000000;
u32 var80061dd4 = 0x00000000;
u32 var80061dd8 = 0x00000000;
u32 var80061ddc = 0x00000000;
u32 var80061de0 = 0x00000000;
u32 var80061de4 = 0x00000000;
u32 var80061de8 = 0x00000000;
u32 var80061dec = 0x00000000;
u32 var80061df0 = 0x00000000;
u32 var80061df4 = 0x00000000;
u32 var80061df8 = 0x00000000;
u32 var80061dfc = 0x00000000;
u32 var80061e00 = 0x00000000;
u32 var80061e04 = 0x00000000;
u32 var80061e08 = 0x00000000;
u32 var80061e0c = 0x00000000;
u32 var80061e10 = 0x00000000;
u32 var80061e14 = 0x00000000;
u32 var80061e18 = 0x00000000;
u32 var80061e1c = 0x00000000;
u32 var80061e20 = 0x00000000;
u32 var80061e24 = 0x00000000;
u32 var80061e28 = 0x00000000;
u32 var80061e2c = 0x00000000;
u32 var80061e30 = 0x00000000;
u32 var80061e34 = 0x00000000;
u32 var80061e38 = 0x00000000;
u32 var80061e3c = 0x00000000;
u32 var80061e40 = 0x00000000;
u32 var80061e44 = 0x00000000;
u32 var80061e48 = 0x00000000;
u32 var80061e4c = 0x00000000;
u32 var80061e50 = 0x00000000;
u32 var80061e54 = 0x00000000;
u32 var80061e58 = 0x00000000;
u32 var80061e5c = 0x00000000;
u32 var80061e60 = 0x00000000;
u32 var80061e64 = 0x00000000;
u32 var80061e68 = 0x00000000;
u32 var80061e6c = 0x00000000;
u32 var80061e70 = 0x00000000;
u32 var80061e74 = 0x00000000;
u32 var80061e78 = 0x00000000;
u32 var80061e7c = 0x00000000;
u32 var80061e80 = 0x00000000;
u32 var80061e84 = 0x00000000;
u32 var80061e88 = 0x00000000;
u32 var80061e8c = 0x00000000;
u32 var80061e90 = 0x00000000;
u32 var80061e94 = 0x00000000;
u32 var80061e98 = 0x00000000;
u32 var80061e9c = 0x00000000;
u32 var80061ea0 = 0x00000000;
u32 var80061ea4 = 0x00000000;
u32 var80061ea8 = 0x00000000;
u32 var80061eac = 0x00000000;
u32 var80061eb0 = 0x00000000;
u32 var80061eb4 = 0x00000000;
u32 var80061eb8 = 0x00000000;
u32 var80061ebc = 0x00000000;
u32 var80061ec0 = 0x00000000;
u32 var80061ec4 = 0x00000000;
u32 var80061ec8 = 0x00000000;
u32 var80061ecc = 0x00000000;
u32 var80061ed0 = 0x00000000;
u32 var80061ed4 = 0x00000000;
u32 var80061ed8 = 0x00000000;
u32 var80061edc = 0x00000000;
u32 var80061ee0 = 0x00000000;
u32 var80061ee4 = 0x00000000;
u32 var80061ee8 = 0x00000000;
u32 var80061eec = 0x00000000;
u32 var80061ef0 = 0x00000000;
u32 var80061ef4 = 0x00000000;
u32 var80061ef8 = 0x00000000;
u32 var80061efc = 0x00000000;
u32 var80061f00 = 0x00000000;
u32 var80061f04 = 0x00000000;
u32 var80061f08 = 0x00000000;
u32 var80061f0c = 0x00000000;
u32 var80061f10 = 0x00000000;
u32 var80061f14 = 0x00000000;
u32 var80061f18 = 0x00000000;
u32 var80061f1c = 0x00000000;
u32 var80061f20 = 0x00000000;
u32 var80061f24 = 0x00000000;
u32 var80061f28 = 0x00000000;
u32 var80061f2c = 0x00000000;
u32 var80061f30 = 0x00000000;
u32 var80061f34 = 0x00000000;
u32 var80061f38 = 0x00000000;
u32 var80061f3c = 0x00000000;
u32 var80061f40 = 0x00000000;
u32 var80061f44 = 0x00000000;
u32 var80061f48 = 0x00000000;
u32 var80061f4c = 0x00000000;
u32 var80061f50 = 0x00000000;
u32 var80061f54 = 0x00000000;
u32 var80061f58 = 0x00000000;
u32 var80061f5c = 0x00000000;
u32 var80061f60 = 0x00000000;
u32 var80061f64 = 0x00000000;
u32 var80061f68 = 0x00000000;
u32 var80061f6c = 0x00000000;
u32 var80061f70 = 0x00000000;
u32 var80061f74 = 0x00000000;
u32 var80061f78 = 0x00000000;
u32 var80061f7c = 0x00000000;
u32 var80061f80 = 0x00000000;
u32 var80061f84 = 0x00000000;
u32 var80061f88 = 0x00000000;
u32 var80061f8c = 0x00000000;
u32 var80061f90 = 0x00000000;
u32 var80061f94 = 0x00000000;
u32 var80061f98 = 0x00000000;
u32 var80061f9c = 0x00000000;
u32 var80061fa0 = 0x00000000;
u32 var80061fa4 = 0x00000000;
u32 var80061fa8 = 0x00000000;
u32 var80061fac = 0x00000000;
u32 var80061fb0 = 0x00000000;
u32 var80061fb4 = 0x00000000;
u32 var80061fb8 = 0x00000000;
u32 var80061fbc = 0x00000000;
u32 var80061fc0 = 0x00000000;
u32 var80061fc4 = 0x00000000;
u32 var80061fc8 = 0x00000000;
u32 var80061fcc = 0x00000000;
u32 var80061fd0 = 0x00000000;
u32 var80061fd4 = 0x00000000;
u32 var80061fd8 = 0x00000000;
u32 var80061fdc = 0x00000000;
u32 var80061fe0 = 0x00000000;
u32 var80061fe4 = 0x00000000;
u32 var80061fe8 = 0x00000000;
u32 var80061fec = 0x00000000;
u32 var80061ff0 = 0x00000000;
u32 var80061ff4 = 0x00000000;
u32 var80061ff8 = 0x00000000;
u32 var80061ffc = 0x00000000;
u32 var80062000 = 0x00000000;
u32 var80062004 = 0x00000000;
u32 var80062008 = 0x00000000;
u32 var8006200c = 0x00000000;
u32 var80062010 = 0x00000000;
u32 var80062014 = 0x00000000;
u32 var80062018 = 0x00000000;
u32 var8006201c = 0x00000000;
u32 var80062020 = 0x00000000;
u32 var80062024 = 0x00000000;
u32 var80062028 = 0x00000000;
u32 var8006202c = 0x00000000;
u32 var80062030 = 0x00000000;
u32 var80062034 = 0x00000000;
u32 var80062038 = 0x00000000;
u32 var8006203c = 0x00000000;
u32 var80062040 = 0x00000000;
u32 var80062044 = 0x00000000;
u32 var80062048 = 0x00000000;
u32 var8006204c = 0x00000000;
u32 var80062050 = 0x00000000;
u32 var80062054 = 0x00000000;
u32 var80062058 = 0x00000000;
u32 var8006205c = 0x00000000;
u32 var80062060 = 0x00000000;
u32 var80062064 = 0x00000000;
u32 var80062068 = 0x00000000;
u32 var8006206c = 0x00000000;
u32 var80062070 = 0x00000000;
u32 var80062074 = 0x00000000;
u32 var80062078 = 0x00000000;
u32 var8006207c = 0x00000000;
u32 var80062080 = 0x00000000;
u32 var80062084 = 0x00000000;
u32 var80062088 = 0x00000000;
u32 var8006208c = 0x00000000;
u32 var80062090 = 0x00000000;
u32 var80062094 = 0x00000000;
u32 var80062098 = 0x00000000;
u32 var8006209c = 0x00000000;
u32 var800620a0 = 0x00000000;
u32 var800620a4 = 0x00000000;
u32 var800620a8 = 0x00000000;
u32 var800620ac = 0x00000000;
u32 var800620b0 = 0x00000000;
u32 var800620b4 = 0x00000000;
u32 var800620b8 = 0x00000000;
u32 var800620bc = 0x00000000;
u32 var800620c0 = 0x00000000;
u32 var800620c4 = 0x00000000;
u32 var800620c8 = 0x00000000;
u32 var800620cc = 0x00000000;
u32 var800620d0 = 0x00000000;
u32 var800620d4 = 0x00000000;
u32 var800620d8 = 0x00000000;
u32 var800620dc = 0x00000000;
u32 var800620e0 = 0x00000000;
u32 var800620e4 = 0x00000000;
u32 var800620e8 = 0x00000000;
u32 var800620ec = 0x00000000;
u32 var800620f0 = 0x00000000;
u32 var800620f4 = 0x00000000;
u32 var800620f8 = 0x00000000;
u32 var800620fc = 0x00000000;
u32 var80062100 = 0x00000000;
u32 var80062104 = 0x00000000;
u32 var80062108 = 0x00000000;
u32 var8006210c = 0x00000000;
u32 var80062110 = 0x00000000;
u32 var80062114 = 0x00000000;
u32 var80062118 = 0x00000000;
u32 var8006211c = 0x00000000;
u32 var80062120 = 0x00000000;
u32 var80062124 = 0x00000000;
u32 var80062128 = 0x00000000;
u32 var8006212c = 0x00000000;
u32 var80062130 = 0x00000000;
u32 var80062134 = 0x00000000;
u32 var80062138 = 0x00000000;
u32 var8006213c = 0x00000000;
u32 var80062140 = 0x00000000;
u32 var80062144 = 0x00000000;
u32 var80062148 = 0x00000000;
u32 var8006214c = 0x00000000;
u32 var80062150 = 0x00000000;
u32 var80062154 = 0x00000000;
u32 var80062158 = 0x00000000;
u32 var8006215c = 0x00000000;
u32 var80062160 = 0x00000000;
u32 var80062164 = 0x00000000;
u32 var80062168 = 0x00000000;
u32 var8006216c = 0x00000000;
u32 var80062170 = 0x00000000;
u32 var80062174 = 0x00000000;
u32 var80062178 = 0x00000000;
u32 var8006217c = 0x00000000;
u32 var80062180 = 0x00000000;
u32 var80062184 = 0x00000000;
u32 var80062188 = 0x00000000;
u32 var8006218c = 0x00000000;
u32 var80062190 = 0x00000000;
u32 var80062194 = 0x00000000;
u32 var80062198 = 0x00000000;
u32 var8006219c = 0x00000000;
u32 var800621a0 = 0x00000000;
u32 var800621a4 = 0x00000000;
u32 var800621a8 = 0x00000000;
u32 var800621ac = 0x00000000;
u32 var800621b0 = 0x00000000;
u32 var800621b4 = 0x00000000;
u32 var800621b8 = 0x00000000;
u32 var800621bc = 0x00000000;
u32 var800621c0 = 0x00000000;
u32 var800621c4 = 0x00000000;
u32 var800621c8 = 0x00000000;
u32 var800621cc = 0x00000000;
u32 var800621d0 = 0x00000000;
u32 var800621d4 = 0x00000000;
u32 var800621d8 = 0x00000000;
u32 var800621dc = 0x00000000;
u32 var800621e0 = 0x00000000;
u32 var800621e4 = 0x00000000;
u32 var800621e8 = 0x00000000;
u32 var800621ec = 0x00000000;
u32 var800621f0 = 0x00000000;
u32 var800621f4 = 0x00000000;
u32 var800621f8 = 0x00000000;
u32 var800621fc = 0x00000000;
u32 var80062200 = 0x00000000;
u32 var80062204 = 0x00000000;
u32 var80062208 = 0x00000000;
u32 var8006220c = 0x00000000;
u32 var80062210 = 0x00000000;
u32 var80062214 = 0x00000000;
u32 var80062218 = 0x00000000;
u32 var8006221c = 0x00000000;
u32 var80062220 = 0x00000000;
u32 var80062224 = 0x00000000;
u32 var80062228 = 0x00000000;
u32 var8006222c = 0x00000000;
u32 var80062230 = 0x00000000;
u32 var80062234 = 0x00000000;
u32 var80062238 = 0x00000000;
u32 var8006223c = 0x00000000;
u32 var80062240 = 0x00000000;
u32 var80062244 = 0x00000000;
u32 var80062248 = 0x00000000;
u32 var8006224c = 0x00000000;
u32 var80062250 = 0x00000000;
u32 var80062254 = 0x00000000;
u32 var80062258 = 0x00000000;
u32 var8006225c = 0x00000000;
u32 var80062260 = 0x00000000;
u32 var80062264 = 0x00000000;
u32 var80062268 = 0x00000000;
u32 var8006226c = 0x00000000;
u32 var80062270 = 0x00000000;
u32 var80062274 = 0x00000000;
u32 var80062278 = 0x00000000;
u32 var8006227c = 0x00000000;
u32 var80062280 = 0x00000000;
u32 var80062284 = 0x00000000;
u32 var80062288 = 0x00000000;
u32 var8006228c = 0x00000000;
u32 var80062290 = 0x00000000;
u32 var80062294 = 0x00000000;
u32 var80062298 = 0x00000000;
u32 var8006229c = 0x00000000;
u32 var800622a0 = 0x00000000;
u32 var800622a4 = 0x00000000;
u32 var800622a8 = 0x00000000;
u32 var800622ac = 0x00000000;
u32 var800622b0 = 0x00000000;
u32 var800622b4 = 0x00000000;
u32 var800622b8 = 0x00000000;
u32 var800622bc = 0x00000000;
u32 var800622c0 = 0x00000000;
u32 var800622c4 = 0x00000000;
u32 var800622c8 = 0x00000000;
u32 var800622cc = 0x00000000;
u32 var800622d0 = 0x00000000;
u32 var800622d4 = 0x00000000;
u32 var800622d8 = 0x00000000;
u32 var800622dc = 0x00000000;
u32 var800622e0 = 0x00000000;
u32 var800622e4 = 0x00000000;
u32 var800622e8 = 0x00000000;
u32 var800622ec = 0x00000000;
u32 var800622f0 = 0x00000000;
u32 var800622f4 = 0x00000000;
u32 var800622f8 = 0x00000000;
u32 var800622fc = 0x00000000;
u32 var80062300 = 0x00000000;
u32 var80062304 = 0x00000000;
u32 var80062308 = 0x00000000;
u32 var8006230c = 0x00000000;
u32 var80062310 = 0x00000000;
u32 var80062314 = 0x00000000;
u32 var80062318 = 0x00000000;
u32 var8006231c = 0x00000000;
u32 var80062320 = 0x00000000;
u32 var80062324 = 0x00000000;
u32 var80062328 = 0x00000000;
u32 var8006232c = 0x00000000;
u32 var80062330 = 0x00000000;
u32 var80062334 = 0x00000000;
u32 var80062338 = 0x00000000;
u32 var8006233c = 0x00000000;
u32 var80062340 = 0x00000000;
u32 var80062344 = 0x00000000;
u32 var80062348 = 0x00000000;
u32 var8006234c = 0x00000000;
u32 var80062350 = 0x00000000;
u32 var80062354 = 0x00000000;
u32 var80062358 = 0x00000000;
u32 var8006235c = 0x00000000;
u32 var80062360 = 0x00000000;
u32 var80062364 = 0x00000000;
u32 var80062368 = 0x00000000;
u32 var8006236c = 0x00000000;
u32 var80062370 = 0x00000000;
u32 var80062374 = 0x00000000;
u32 var80062378 = 0x00000000;
u32 var8006237c = 0x00000000;
u32 var80062380 = 0x00000000;
u32 var80062384 = 0x00000000;
u32 var80062388 = 0x00000000;
u32 var8006238c = 0x00000000;
u32 var80062390 = 0x00000000;
u32 var80062394 = 0x00000000;
u32 var80062398 = 0x00000000;
u32 var8006239c = 0x00000000;
