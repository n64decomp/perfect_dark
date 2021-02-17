#include <ultra64.h>
#include "game/chr/chraicommands.h"
#include "game/game_0f09f0.h"
#include "game/game_102240.h"
#include "game/cheats.h"
#include "game/game_107fb0.h"
#include "game/endscreen.h"
#include "game/camdraw.h"
#include "game/timing.h"
#include "game/game_173a00.h"
#include "game/utils.h"
#include "game/mplayer/ingame.h"
#include "game/mplayer/setup.h"
#include "game/mplayer/scenarios.h"
#include "game/training/training.h"
#include "gvars/gvars.h"
#include "stagesetup.h"
#include "data.h"
#include "types.h"

// 20df0
u16 var8007add0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
};

// 20e10
struct stagethinglist stagethinglist_20e10 = {
	STAGE_DUEL, 16, var8007add0,
};

// 20e18
u16 var8007adf8[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
};

// 20e3c
struct stagethinglist stagethinglist_20e3c = {
	STAGE_MP_VILLA, 18, var8007adf8,
};

// 20e44
u16 var8007ae24[] = {
	0x0000,
};

// 20e48
struct stagethinglist stagethinglist_20e48 = {
	STAGE_RETAKING, 1, var8007ae24,
};

// 20e50
u16 var8007ae30[] = {
	0x0000,
	0x0101,
};

// 20e54
struct stagethinglist stagethinglist_20e54 = {
	0x0f, 2, var8007ae30,
};

// 20e5c
u16 var8007ae3c[] = {
	0x0000,
};

// 20e60
struct stagethinglist stagethinglist_20e60 = {
	STAGE_TEST_SILO, 1, var8007ae3c,
};

// 20e68
u16 var8007ae48[] = {
	0x0000,
};

// 20e6c
struct stagethinglist stagethinglist_20e6c = {
	0x15, 1, var8007ae48,
};

// 20e74
u16 var8007ae54[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
};

// 20e80
struct stagethinglist stagethinglist_20e80 = {
	STAGE_ESCAPE, 5, var8007ae54,
};

// 20e88
u16 var8007ae68[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
};

// 20e94
struct stagethinglist stagethinglist_20e94 = {
	STAGE_WAR, 6, var8007ae68,
};

// 20e9c
u16 var8007ae7c[] = {
	0x0000,
	0x0101,
	0x0202,
};

// 20ea4
struct stagethinglist stagethinglist_20ea4 = {
	0x11, 3, var8007ae7c,
};

// 20eac
u16 var8007ae8c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
};

// 20ec8
struct stagethinglist stagethinglist_20ec8 = {
	0x13, 13, var8007ae8c,
};

// 20ed0
u16 var8007aeb0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
};

// 20edc
struct stagethinglist stagethinglist_20edc = {
	STAGE_TEST_ARCH, 5, var8007aeb0,
};

// 20ee4
u16 var8007aec4[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
};

// 20eec
struct stagethinglist stagethinglist_20eec = {
	0x12, 4, var8007aec4,
};

// 20ef4
u16 var8007aed4[] = {
	0x0000,
};

// 20ef8
struct stagethinglist stagethinglist_20ef8 = {
	0x10, 1, var8007aed4,
};

// 20f00
u16 var8007aee0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
};

// 20f0c
struct stagethinglist stagethinglist_20f0c = {
	STAGE_MP_RAVINE, 5, var8007aee0,
};

// 20f14
u16 var8007aef4[] = {
	0x0000,
};

// 20f18
struct stagethinglist stagethinglist_20f18 = {
	0x0c, 1, var8007aef4,
};

// 20f20
u16 var8007af00[] = {
	0x0000,
};

// 20f24
struct stagethinglist stagethinglist_20f24 = {
	STAGE_CHICAGO, 1, var8007af00,
};

// 20f2c
u16 var8007af0c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
};

// 20f50
struct stagethinglist stagethinglist_20f50 = {
	STAGE_G5BUILDING, 17, var8007af0c,
};

// 20f58
u16 var8007af38[] = {
	0x0000,
};

// 20f5c
struct stagethinglist stagethinglist_20f5c = {
	STAGE_MP_COMPLEX, 1, var8007af38,
};

// 20f64
u16 var8007af44[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
};

// 20f74
struct stagethinglist stagethinglist_20f74 = {
	STAGE_MP_SKEDAR, 8, var8007af44,
};

// 20f7c
u16 var8007af5c[] = {
	0x0000,
	0x0101,
	0x0202,
};

// 20f84
struct stagethinglist stagethinglist_20f84 = {
	STAGE_AIRBASE, 3, var8007af5c,
};

// 20f8c
u16 var8007af6c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
};

// 20fb8
struct stagethinglist stagethinglist_20fb8 = {
	STAGE_MP_PIPES, 21, var8007af6c,
};

// 20fc0
u16 var8007afa0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
};

// 20fd8
struct stagethinglist stagethinglist_20fd8 = {
	STAGE_INVESTIGATION, 11, var8007afa0,
};

// 20fe0
u16 var8007afc0[] = {
	0x0000,
	0x0101,
	0x0202,
};

// 20fe8
struct stagethinglist stagethinglist_20fe8 = {
	STAGE_MP_FORTRESS, 3, var8007afc0,
};

// 20ff0
u16 var8007afd0[] = {
	0x0000,
	0x0101,
	0x0202,
};

// 20ff8
struct stagethinglist stagethinglist_20ff8 = {
	STAGE_MP_WAREHOUSE, 3, var8007afd0,
};

// 21000
u16 var8007afe0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
};

// 2100c
struct stagethinglist stagethinglist_2100c = {
	STAGE_MP_FELICITY, 5, var8007afe0,
};

// 21014
u16 var8007aff4[] = {
	0x0000,
};

// 21018
struct stagethinglist stagethinglist_21018 = {
	0x8c, 1, var8007aff4,
};

// 21020
u16 var8007b000[] = {
	0x0000,
};

// 21024
struct stagethinglist stagethinglist_21024 = {
	STAGE_VILLA, 1, var8007b000,
};

// 2102c
u16 var8007b00c[] = {
	0x0000,
	0x0101,
	0x0202,
};

// 21034
struct stagethinglist stagethinglist_21034 = {
	0xc8, 3, var8007b00c,
};

// 2103c
u16 var8007b01c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
};

// 21084
struct stagethinglist stagethinglist_21084 = {
	0xbb, 35, var8007b01c,
};

// 2108c
struct modelstate g_ModelStates[441] = {
	//                 file                         scale
	/*0x0000*/ { NULL, FILE_PROOFGUN,               0x0199 },
	/*0x0001*/ { NULL, FILE_PGROUNDGUN,             0x0199 },
	/*0x0002*/ { NULL, FILE_PTVSCREEN,              0x0199 },
	/*0x0003*/ { NULL, FILE_PBORG_CRATE,            0x0199 },
	/*0x0004*/ { NULL, FILE_PWINDOW,                0x0199 },
	/*0x0005*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x0006*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x0007*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x0008*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x0009*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x000a*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x000b*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x000c*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x000d*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x000e*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x000f*/ { NULL, FILE_PA51_CRATE1,            0x0199 },
	/*0x0010*/ { NULL, FILE_PCRYPTDOOR1B,           0x1000 },
	/*0x0011*/ { NULL, FILE_PCHRBRIEFCASE,          0x0199 },
	/*0x0012*/ { NULL, FILE_PCHRBUG,                0x0199 },
	/*0x0013*/ { NULL, FILE_PCHRDATATHIEF,          0x0199 },
	/*0x0014*/ { NULL, FILE_PNINTENDOLOGO,          0x0199 },
	/*0x0015*/ { NULL, FILE_PDOOR_ROLLERTRAIN,      0x1000 },
	/*0x0016*/ { NULL, FILE_PFLAG,                  0x0199 },
	/*0x0017*/ { NULL, FILE_PMODEMBOX,              0x0199 },
	/*0x0018*/ { NULL, FILE_PDOORCONSOLE,           0x0199 },
	/*0x0019*/ { NULL, FILE_PA51_HORIZ_DOOR_TOP,    0x1000 },
	/*0x001a*/ { NULL, FILE_PA51_HORIZ_DOOR_BOT,    0x1000 },
	/*0x001b*/ { NULL, FILE_PA51_VERT_DOOR_LEFT,    0x1000 },
	/*0x001c*/ { NULL, FILE_PA51_VERT_DOOR_RIGHT,   0x1000 },
	/*0x001d*/ { NULL, FILE_PA51_VERT_DOOR_ST,      0x1000 },
	/*0x001e*/ { NULL, FILE_PA51_HORIZ_DOOR_GL,     0x1000 },
	/*0x001f*/ { NULL, FILE_PA51_HORIZ_DOOR_SECRET, 0x1000 },
	/*0x0020*/ { NULL, FILE_PA51_CRATE1,            0x1000 },
	/*0x0021*/ { NULL, FILE_PA51_CRATE2,            0x1000 },
	/*0x0022*/ { NULL, FILE_PA51_CRATE3,            0x1000 },
	/*0x0023*/ { NULL, FILE_PA51_EXP1,              0x0199 },
	/*0x0024*/ { NULL, FILE_PA51_UNEXP1,            0x1000 },
	/*0x0025*/ { NULL, FILE_PA51_EXP2,              0x0199 },
	/*0x0026*/ { NULL, FILE_PA51_UNEXP2,            0x1000 },
	/*0x0027*/ { NULL, FILE_PA51_UNEXP3,            0x0199 },
	/*0x0028*/ { NULL, FILE_PAIVILLADOOR1,          0x1000 },
	/*0x0029*/ { NULL, FILE_PAIVILLADOOR2A,         0x1000 },
	/*0x002a*/ { NULL, FILE_PAIVILLADOOR4,          0x1000 },
	/*0x002b*/ { NULL, FILE_PA51_LIFT_HANGAR,       0x1000 },
	/*0x002c*/ { NULL, FILE_PA51_LIFT_CONTROL,      0x1000 },
	/*0x002d*/ { NULL, FILE_PA51_LIFT_STORE,        0x1000 },
	/*0x002e*/ { NULL, FILE_PA51_LIFT_THINWALL,     0x1000 },
	/*0x002f*/ { NULL, FILE_PAIVILLABOT1,           0x1000 },
	/*0x0030*/ { NULL, FILE_PAIVILLABOT2,           0x1000 },
	/*0x0031*/ { NULL, FILE_PAIVILLABOT3,           0x1000 },
	/*0x0032*/ { NULL, FILE_PAIVILLAWINDMILL,       0x1000 },
	/*0x0033*/ { NULL, FILE_PHOVERBED,              0x0199 },
	/*0x0034*/ { NULL, FILE_PMARKER,                0x1000 },
	/*0x0035*/ { NULL, FILE_PALDOOR_R,              0x1000 },
	/*0x0036*/ { NULL, FILE_PALDOOR_L,              0x1000 },
	/*0x0037*/ { NULL, FILE_PDD_LIFTR,              0x1000 },
	/*0x0038*/ { NULL, FILE_PDD_FANROOF,            0x1000 },
	/*0x0039*/ { NULL, FILE_PDD_FANWALL,            0x1000 },
	/*0x003a*/ { NULL, FILE_PHOVBIKE,               0x0199 },
	/*0x003b*/ { NULL, FILE_PDD_OFFICEDOOR,         0x1000 },
	/*0x003c*/ { NULL, FILE_PDD_PLANTRUBBER,        0x1000 },
	/*0x003d*/ { NULL, FILE_PDD_PLANTSPIKE,         0x1000 },
	/*0x003e*/ { NULL, FILE_PDD_PLANTSPIDER,        0x1000 },
	/*0x003f*/ { NULL, FILE_PDD_WINDOW,             0x1000 },
	/*0x0040*/ { NULL, FILE_PDD_REDSOFA,            0x1000 },
	/*0x0041*/ { NULL, FILE_PDD_REDARM,             0x1000 },
	/*0x0042*/ { NULL, FILE_PDD_SERVICEDOOR,        0x1000 },
	/*0x0043*/ { NULL, FILE_PDD_WINDDOOR,           0x1000 },
	/*0x0044*/ { NULL, FILE_PDD_LIFTDOOR,           0x1000 },
	/*0x0045*/ { NULL, FILE_PDD_VERTBLIND,          0x1000 },
	/*0x0046*/ { NULL, FILE_PDD_DESK,               0x1000 },
	/*0x0047*/ { NULL, FILE_PDD_CHAIR,              0x1000 },
	/*0x0048*/ { NULL, FILE_PNLOGO,                 0x0199 },
	/*0x0049*/ { NULL, FILE_PNLOGO2,                0x0199 },
	/*0x004a*/ { NULL, FILE_PNLOGO3,                0x0199 },
	/*0x004b*/ { NULL, FILE_PPERFECTDARK,           0x0199 },
	/*0x004c*/ { NULL, FILE_PPDONE,                 0x0199 },
	/*0x004d*/ { NULL, FILE_PPDTWO,                 0x0199 },
	/*0x004e*/ { NULL, FILE_PPDTHREE,               0x0199 },
	/*0x004f*/ { NULL, FILE_PPDFOUR,                0x0199 },
	/*0x0050*/ { NULL, FILE_PDD_HOVCOP,             0x1000 },
	/*0x0051*/ { NULL, FILE_PDD_HOVMOTO,            0x1000 },
	/*0x0052*/ { NULL, FILE_PDD_HOVTRUCK,           0x1000 },
	/*0x0053*/ { NULL, FILE_PDD_HOVCAR,             0x1000 },
	/*0x0054*/ { NULL, FILE_PDD_HOVCAB,             0x1000 },
	/*0x0055*/ { NULL, FILE_PDD_AC_UNEXP,           0x1000 },
	/*0x0056*/ { NULL, FILE_PDD_AC_EXP,             0x1000 },
	/*0x0057*/ { NULL, FILE_PDD_ACBOT_UNEXP,        0x1000 },
	/*0x0058*/ { NULL, FILE_PDD_ACBOT_EXP,          0x1000 },
	/*0x0059*/ { NULL, FILE_PPC1,                   0x1000 },
	/*0x005a*/ { NULL, FILE_PHOVERCRATE1,           0x1000 },
	/*0x005b*/ { NULL, FILE_PDROPSHIP,              0x0199 },
	/*0x005c*/ { NULL, FILE_PAL_AIRLOCK,            0x1000 },
	/*0x005d*/ { NULL, FILE_PAL_DOCKLIFT,           0x1000 },
	/*0x005e*/ { NULL, FILE_PCASE,                  0x1000 },
	/*0x005f*/ { NULL, FILE_PDD_STONEDESK,          0x1000 },
	/*0x0060*/ { NULL, FILE_PMEDLABWIN1,            0x0199 },
	/*0x0061*/ { NULL, FILE_PMEDLABWIN2,            0x0199 },
	/*0x0062*/ { NULL, FILE_PA51TABLE,              0x1000 },
	/*0x0063*/ { NULL, FILE_PA51CHAIR,              0x1000 },
	/*0x0064*/ { NULL, FILE_PA51SCREEN,             0x1000 },
	/*0x0065*/ { NULL, FILE_PA51WASTEBIN,           0x1000 },
	/*0x0066*/ { NULL, FILE_PA51DESKENT,            0x0199 },
	/*0x0067*/ { NULL, FILE_PA51TROLLEY,            0x1000 },
	/*0x0068*/ { NULL, FILE_PA51DIVIDE,             0x1000 },
	/*0x0069*/ { NULL, FILE_PA51BOARD,              0x1000 },
	/*0x006a*/ { NULL, FILE_PSKCREV_EXP1,           0x1000 },
	/*0x006b*/ { NULL, FILE_PSKCREV_UNEXP1,         0x1000 },
	/*0x006c*/ { NULL, FILE_PSKTNL_EXP1,            0x1000 },
	/*0x006d*/ { NULL, FILE_PSKTNL_UNEXP1,          0x1000 },
	/*0x006e*/ { NULL, FILE_PSK_DOOR1,              0x1000 },
	/*0x006f*/ { NULL, FILE_PSK_SHIP_DOOR1,         0x1000 },
	/*0x0070*/ { NULL, FILE_PSK_SHIP_HOLO1,         0x1000 },
	/*0x0071*/ { NULL, FILE_PSK_SHIP_HOLO2,         0x1000 },
	/*0x0072*/ { NULL, FILE_PSK_SHIP_HULLDOOR1,     0x1000 },
	/*0x0073*/ { NULL, FILE_PSK_SHIP_HULLDOOR2,     0x1000 },
	/*0x0074*/ { NULL, FILE_PSK_SHIP_HULLDOOR3,     0x1000 },
	/*0x0075*/ { NULL, FILE_PSK_SHIP_HULLDOOR4,     0x1000 },
	/*0x0076*/ { NULL, FILE_PSK_FIGHTER1,           0x1000 },
	/*0x0077*/ { NULL, FILE_PSK_CRYOPOD1_TOP,       0x1000 },
	/*0x0078*/ { NULL, FILE_PSK_CRYOPOD1_BOT,       0x1000 },
	/*0x0079*/ { NULL, FILE_PSK_UNDER_GENERATOR,    0x1000 },
	/*0x007a*/ { NULL, FILE_PSK_UNDER_TRANS,        0x1000 },
	/*0x007b*/ { NULL, FILE_PSK_HANGARDOOR_TOP,     0x1000 },
	/*0x007c*/ { NULL, FILE_PSK_HANGARDOOR_BOT,     0x1000 },
	/*0x007d*/ { NULL, FILE_PDOOR2_G5,              0x1000 },
	/*0x007e*/ { NULL, FILE_PDOOR1A_G5,             0x1000 },
	/*0x007f*/ { NULL, FILE_PDOOR1B_G5,             0x1000 },
	/*0x0080*/ { NULL, FILE_PDOOR1ATRI_G5,          0x1000 },
	/*0x0081*/ { NULL, FILE_PDOOR2A_G5,             0x1000 },
	/*0x0082*/ { NULL, FILE_PDD_DECODOOR,           0x1000 },
	/*0x0083*/ { NULL, FILE_PDD_SECRETDOOR,         0x1000 },
	/*0x0084*/ { NULL, FILE_PDD_SECRETDOOR2,        0x1000 },
	/*0x0085*/ { NULL, FILE_PDDJUMPSHIP,            0x0199 },
	/*0x0086*/ { NULL, FILE_PTAXICAB,               0x0199 },
	/*0x0087*/ { NULL, FILE_PPOLICECAR,             0x0199 },
	/*0x0088*/ { NULL, FILE_PRAVINELIFT,            0x1000 },
	/*0x0089*/ { NULL, FILE_PDD_LAB_DOOR_BS,        0x1000 },
	/*0x008a*/ { NULL, FILE_PDD_LAB_DOOR_SEC,       0x1000 },
	/*0x008b*/ { NULL, FILE_PDD_LAB_DOOR_WIND,      0x1000 },
	/*0x008c*/ { NULL, FILE_PHOOVERBOT,             0x0800 },
	/*0x008d*/ { NULL, FILE_PTESTERBOT,             0x0800 },
	/*0x008e*/ { NULL, FILE_PDD_LAB_SECTOR2BOT,     0x1000 },
	/*0x008f*/ { NULL, FILE_PDD_LAB_SECTOR2TOP,     0x1000 },
	/*0x0090*/ { NULL, FILE_PDD_LAB_CAUTIONTOP,     0x1000 },
	/*0x0091*/ { NULL, FILE_PDD_LAB_HAZARD,         0x1000 },
	/*0x0092*/ { NULL, FILE_PDD_LAB_CAUTION,        0x1000 },
	/*0x0093*/ { NULL, FILE_PDR_CAROLL_DOOR,        0x1000 },
	/*0x0094*/ { NULL, FILE_PDD_LAB_SECTOR3TOP,     0x1000 },
	/*0x0095*/ { NULL, FILE_PDD_LAB_SECTOR3,        0x1000 },
	/*0x0096*/ { NULL, FILE_PDD_LAB_SECTOR3WIND,    0x1000 },
	/*0x0097*/ { NULL, FILE_PDD_HOVERCOPTER,        0x1000 },
	/*0x0098*/ { NULL, FILE_PDD_LAB_SECTOR4TOP,     0x1000 },
	/*0x0099*/ { NULL, FILE_PDD_LAB_RESTRICTED,     0x1000 },
	/*0x009a*/ { NULL, FILE_PDOOR4A_G5,             0x1000 },
	/*0x009b*/ { NULL, FILE_PDOOR4B_G5,             0x1000 },
	/*0x009c*/ { NULL, FILE_PLASDOOR,               0x1000 },
	/*0x009d*/ { NULL, FILE_PG5SAFEDOOR,            0x1000 },
	/*0x009e*/ { NULL, FILE_PROPE,                  0x0199 },
	/*0x009f*/ { NULL, FILE_PG5_MAINFRAME,          0x1000 },
	/*0x00a0*/ { NULL, FILE_PDR_CAROLL_DOOR_BASE,   0x1000 },
	/*0x00a1*/ { NULL, FILE_PDR_CAROLL_DOOR_MAIN,   0x1000 },
	/*0x00a2*/ { NULL, FILE_PDR_CAROLL_DOOR_LEFT,   0x1000 },
	/*0x00a3*/ { NULL, FILE_PDR_CAROLL_DOOR_RIGHT,  0x1000 },
	/*0x00a4*/ { NULL, FILE_PDR_CAROLL_DOOR_BMAIN,  0x1000 },
	/*0x00a5*/ { NULL, FILE_PDR_CAROLL_DOOR_BLEFT,  0x1000 },
	/*0x00a6*/ { NULL, FILE_PDR_CAROLL_DOOR_BRIGHT, 0x1000 },
	/*0x00a7*/ { NULL, FILE_PDD_BANNER,             0x0199 },
	/*0x00a8*/ { NULL, FILE_PG5_ESCDOORUP,          0x1000 },
	/*0x00a9*/ { NULL, FILE_PG5_ESCDOORUPBOOM,      0x1000 },
	/*0x00aa*/ { NULL, FILE_PG5_ESCDOORDOWN,        0x1000 },
	/*0x00ab*/ { NULL, FILE_PG5_ESCDOORDOWNBOOM,    0x1000 },
	/*0x00ac*/ { NULL, FILE_PDUMPSTER,              0x1000 },
	/*0x00ad*/ { NULL, FILE_PG5CARLIFTDOOR,         0x1000 },
	/*0x00ae*/ { NULL, FILE_PCH_SHUTTER1,           0x1000 },
	/*0x00af*/ { NULL, FILE_PCCTV_PD,               0x1000 },
	/*0x00b0*/ { NULL, FILE_PCOMHUB,                0x1000 },
	/*0x00b1*/ { NULL, FILE_PQUADPOD,               0x1000 },
	/*0x00b2*/ { NULL, FILE_PPD_CONSOLE,            0x1000 },
	/*0x00b3*/ { NULL, FILE_PDD_GRATE,              0x1000 },
	/*0x00b4*/ { NULL, FILE_PLIFT_PLATFORM,         0x1000 },
	/*0x00b5*/ { NULL, FILE_PLIGHTSWITCH,           0x1000 },
	/*0x00b6*/ { NULL, FILE_PBLASTSHIELD,           0x1000 },
	/*0x00b7*/ { NULL, FILE_PLIGHTSWITCH2,          0x0199 },
	/*0x00b8*/ { NULL, FILE_PDD_ACCESSDOORUP,       0x1000 },
	/*0x00b9*/ { NULL, FILE_PDD_ACCESSDOORDN,       0x1000 },
	/*0x00ba*/ { NULL, FILE_PLAB_CONTAINER,         0x1000 },
	/*0x00bb*/ { NULL, FILE_PLAB_CHAIR,             0x1000 },
	/*0x00bc*/ { NULL, FILE_PLAB_TABLE,             0x1000 },
	/*0x00bd*/ { NULL, FILE_PLAB_MICROSCOPE,        0x1000 },
	/*0x00be*/ { NULL, FILE_PLAB_MAINFRAME,         0x1000 },
	/*0x00bf*/ { NULL, FILE_PDD_LABDOOR,            0x1000 },
	/*0x00c0*/ { NULL, FILE_PDD_LAB_DOORTOP,        0x1000 },
	/*0x00c1*/ { NULL, FILE_PMULTI_AMMO_CRATE,      0x1000 },
	/*0x00c2*/ { NULL, FILE_PCHRCHAIN,              0x1000 },
	/*0x00c3*/ { NULL, FILE_PTDOOR,                 0x1000 },
	/*0x00c4*/ { NULL, FILE_PCI_SOFA,               0x1000 },
	/*0x00c5*/ { NULL, FILE_PCI_LIFT,               0x1000 },
	/*0x00c6*/ { NULL, FILE_PCI_LIFTDOOR,           0x1000 },
	/*0x00c7*/ { NULL, FILE_PLASERCUT,              0x0199 },
	/*0x00c8*/ { NULL, FILE_PSK_SHUTTLE,            0x0199 },
	/*0x00c9*/ { NULL, FILE_PNEWVILLADOOR,          0x1000 },
	/*0x00ca*/ { NULL, FILE_PSK_PILLARLEFT,         0x1000 },
	/*0x00cb*/ { NULL, FILE_PSK_PILLARRIGHT,        0x1000 },
	/*0x00cc*/ { NULL, FILE_PSK_PLINTH_T,           0x1000 },
	/*0x00cd*/ { NULL, FILE_PSK_PLINTH_ML,          0x1000 },
	/*0x00ce*/ { NULL, FILE_PSK_PLINTH_MR,          0x1000 },
	/*0x00cf*/ { NULL, FILE_PSK_PLINTH_BL,          0x1000 },
	/*0x00d0*/ { NULL, FILE_PSK_PLINTH_BR,          0x1000 },
	/*0x00d1*/ { NULL, FILE_PSK_FL_SHAD_T,          0x1000 },
	/*0x00d2*/ { NULL, FILE_PSK_FL_SHAD_ML,         0x1000 },
	/*0x00d3*/ { NULL, FILE_PSK_FL_SHAD_MR,         0x1000 },
	/*0x00d4*/ { NULL, FILE_PSK_FL_SHAD_BL,         0x1000 },
	/*0x00d5*/ { NULL, FILE_PSK_FL_SHAD_BR,         0x1000 },
	/*0x00d6*/ { NULL, FILE_PSK_FL_NOSHAD_T,        0x1000 },
	/*0x00d7*/ { NULL, FILE_PSK_FL_NOSHAD_ML,       0x1000 },
	/*0x00d8*/ { NULL, FILE_PSK_FL_NOSHAD_MR,       0x1000 },
	/*0x00d9*/ { NULL, FILE_PSK_FL_NOSHAD_BL,       0x1000 },
	/*0x00da*/ { NULL, FILE_PSK_FL_NOSHAD_BR,       0x1000 },
	/*0x00db*/ { NULL, FILE_PSK_TEMPLECOLUMN1,      0x1000 },
	/*0x00dc*/ { NULL, FILE_PSK_TEMPLECOLUMN2,      0x1000 },
	/*0x00dd*/ { NULL, FILE_PSK_TEMPLECOLUMN3,      0x1000 },
	/*0x00de*/ { NULL, FILE_PSK_SUNSHAD1,           0x1000 },
	/*0x00df*/ { NULL, FILE_PSK_SUNSHAD2,           0x1000 },
	/*0x00e0*/ { NULL, FILE_PSK_SUNNOSHAD1,         0x1000 },
	/*0x00e1*/ { NULL, FILE_PSK_SUNNOSHAD2,         0x1000 },
	/*0x00e2*/ { NULL, FILE_PBARREL,                0x1000 },
	/*0x00e3*/ { NULL, FILE_PGLASS_FLOOR,           0x0199 },
	/*0x00e4*/ { NULL, FILE_PESCA_STEP,             0x0199 },
	/*0x00e5*/ { NULL, FILE_PMATRIX_LIFT,           0x0199 },
	/*0x00e6*/ { NULL, FILE_PRUBBLE1,               0x1000 },
	/*0x00e7*/ { NULL, FILE_PRUBBLE2,               0x1000 },
	/*0x00e8*/ { NULL, FILE_PRUBBLE3,               0x1000 },
	/*0x00e9*/ { NULL, FILE_PRUBBLE4,               0x1000 },
	/*0x00ea*/ { NULL, FILE_PCABLE_CAR,             0x0199 },
	/*0x00eb*/ { NULL, FILE_PELVIS_SAUCER,          0x0199 },
	/*0x00ec*/ { NULL, FILE_PSTEWARDESS_TROLLEY,    0x0199 },
	/*0x00ed*/ { NULL, FILE_PAIRBASE_LIFT_ENCLOSED, 0x0199 },
	/*0x00ee*/ { NULL, FILE_PAIRBASE_LIFT_ANGLE,    0x0199 },
	/*0x00ef*/ { NULL, FILE_PAIRBASE_SAFEDOOR,      0x1000 },
	/*0x00f0*/ { NULL, FILE_PAF1_PILOTCHAIR,        0x0199 },
	/*0x00f1*/ { NULL, FILE_PAF1_PASSCHAIR,         0x0199 },
	/*0x00f2*/ { NULL, FILE_PTESTOBJ,               0x0199 },
	/*0x00f3*/ { NULL, FILE_PCHRNIGHTSIGHT,         0x0c00 },
	/*0x00f4*/ { NULL, FILE_PCHRSHIELD,             0x0199 },
	/*0x00f5*/ { NULL, FILE_PCHRFALCON2,            0x0199 },
	/*0x00f6*/ { NULL, FILE_PCHRLEEGUN1,            0x0199 },
	/*0x00f7*/ { NULL, FILE_PCHRMAULER,             0x0199 },
	/*0x00f8*/ { NULL, FILE_PCHRDY357,              0x0199 },
	/*0x00f9*/ { NULL, FILE_PCHRDY357TRENT,         0x0199 },
	/*0x00fa*/ { NULL, FILE_PCHRMAIANPISTOL,        0x0199 },
	/*0x00fb*/ { NULL, FILE_PCHRFALCON2SIL,         0x0199 },
	/*0x00fc*/ { NULL, FILE_PCHRFALCON2SCOPE,       0x0199 },
	/*0x00fd*/ { NULL, FILE_PCHRCMP150,             0x0199 },
	/*0x00fe*/ { NULL, FILE_PCHRAR34,               0x0199 },
	/*0x00ff*/ { NULL, FILE_PCHRDRAGON,             0x0199 },
	/*0x0100*/ { NULL, FILE_PCHRSUPERDRAGON,        0x0199 },
	/*0x0101*/ { NULL, FILE_PCHRAVENGER,            0x0199 },
	/*0x0102*/ { NULL, FILE_PCHRCYCLONE,            0x0199 },
	/*0x0103*/ { NULL, FILE_PCHRMAIANSMG,           0x0199 },
	/*0x0104*/ { NULL, FILE_PCHRRCP120,             0x0199 },
	/*0x0105*/ { NULL, FILE_PCHRPCGUN,              0x0199 },
	/*0x0106*/ { NULL, FILE_PCHRSHOTGUN,            0x0199 },
	/*0x0107*/ { NULL, FILE_PCHRSKMINIGUN,          0x0199 },
	/*0x0108*/ { NULL, FILE_PCHRDYROCKET,           0x0199 },
	/*0x0109*/ { NULL, FILE_PCHRDEVASTATOR,         0x0199 },
	/*0x010a*/ { NULL, FILE_PCHRSKROCKET,           0x0199 },
	/*0x010b*/ { NULL, FILE_PCHRZ2020,              0x0199 },
	/*0x010c*/ { NULL, FILE_PCHRSNIPERRIFLE,        0x0199 },
	/*0x010d*/ { NULL, FILE_PCHRCROSSBOW,           0x0199 },
	/*0x010e*/ { NULL, FILE_PCHRDRUGGUN,            0x0199 },
	/*0x010f*/ { NULL, FILE_PCHRKNIFE,              0x0199 },
	/*0x0110*/ { NULL, FILE_PCHRNBOMB,              0x0199 },
	/*0x0111*/ { NULL, FILE_PCHRFLASHBANG,          0x0199 },
	/*0x0112*/ { NULL, FILE_PCHRGRENADE,            0x0199 },
	/*0x0113*/ { NULL, FILE_PCHRTIMEDMINE,          0x0199 },
	/*0x0114*/ { NULL, FILE_PCHRPROXIMITYMINE,      0x0199 },
	/*0x0115*/ { NULL, FILE_PCHRREMOTEMINE,         0x0199 },
	/*0x0116*/ { NULL, FILE_PCHRECMMINE,            0x0199 },
	/*0x0117*/ { NULL, FILE_PCHRWPPK,               0x0199 },
	/*0x0118*/ { NULL, FILE_PCHRTT33,               0x0199 },
	/*0x0119*/ { NULL, FILE_PCHRSKORPION,           0x0199 },
	/*0x011a*/ { NULL, FILE_PCHRKALASH,             0x0199 },
	/*0x011b*/ { NULL, FILE_PCHRUZI,                0x0199 },
	/*0x011c*/ { NULL, FILE_PCHRMP5K,               0x0199 },
	/*0x011d*/ { NULL, FILE_PCHRM16,                0x0199 },
	/*0x011e*/ { NULL, FILE_PCHRFNP90,              0x0199 },
	/*0x011f*/ { NULL, FILE_PCHRDYROCKETMIS,        0x0199 },
	/*0x0120*/ { NULL, FILE_PCHRSKROCKETMIS,        0x0199 },
	/*0x0121*/ { NULL, FILE_PCHRCROSSBOLT,          0x0199 },
	/*0x0122*/ { NULL, FILE_PCHRDEVGRENADE,         0x0199 },
	/*0x0123*/ { NULL, FILE_PCHRDRAGGRENADE,        0x0199 },
	/*0x0124*/ { NULL, FILE_PA51_TURRET,            0x0199 },
	/*0x0125*/ { NULL, FILE_PPELAGICDOOR,           0x1000 },
	/*0x0126*/ { NULL, FILE_PAUTOSURGEON,           0x0199 },
	/*0x0127*/ { NULL, FILE_PLIMO,                  0x0199 },
	/*0x0128*/ { NULL, FILE_PA51INTERCEPTOR,        0x0199 },
	/*0x0129*/ { NULL, FILE_PA51DISH,               0x0199 },
	/*0x012a*/ { NULL, FILE_PA51RADARCONSOLE,       0x0199 },
	/*0x012b*/ { NULL, FILE_PA51LOCKERDOOR,         0x0199 },
	/*0x012c*/ { NULL, FILE_PG5GENERATOR,           0x0199 },
	/*0x012d*/ { NULL, FILE_PG5DUMPSTER,            0x0199 },
	/*0x012e*/ { NULL, FILE_PCHRCLOAKER,            0x0199 },
	/*0x012f*/ { NULL, FILE_PCHRSPEEDPILL,          0x2800 },
	/*0x0130*/ { NULL, FILE_PBIGPELAGICDOOR,        0x1000 },
	/*0x0131*/ { NULL, FILE_PSK_JONRUBBLE3,         0x1000 },
	/*0x0132*/ { NULL, FILE_PSK_JONRUBBLE4,         0x1000 },
	/*0x0133*/ { NULL, FILE_PSK_JONRUBBLE5,         0x1000 },
	/*0x0134*/ { NULL, FILE_PSK_JONRUBBLE6,         0x1000 },
	/*0x0135*/ { NULL, FILE_PBAGGAGECARRIER,        0x0199 },
	/*0x0136*/ { NULL, FILE_PMINESIGN,              0x0199 },
	/*0x0137*/ { NULL, FILE_PCHAMBER,               0x0199 },
	/*0x0138*/ { NULL, FILE_PISOTOPEEXPERIMENT,     0x0199 },
	/*0x0139*/ { NULL, FILE_PISOTOPE,               0x0199 },
	/*0x013a*/ { NULL, FILE_PREACTORDOOR,           0x0199 },
	/*0x013b*/ { NULL, FILE_PSAUCERINSIDE,          0x1000 },
	/*0x013c*/ { NULL, FILE_PVILLASTOOL,            0x0199 },
	/*0x013d*/ { NULL, FILE_PCETANWINDOW1,          0x0199 },
	/*0x013e*/ { NULL, FILE_PCETANWINDOW2,          0x0199 },
	/*0x013f*/ { NULL, FILE_PCETANWINDOW3,          0x0199 },
	/*0x0140*/ { NULL, FILE_PBINOCULARS,            0x0199 },
	/*0x0141*/ { NULL, FILE_PSUBMARINE,             0x0199 },
	/*0x0142*/ { NULL, FILE_PAIRFORCE1,             0x1000 },
	/*0x0143*/ { NULL, FILE_PENGINEPART,            0x0199 },
	/*0x0144*/ { NULL, FILE_PCETROOFGUN,            0x0199 },
	/*0x0145*/ { NULL, FILE_PCETANSMALLDOOR,        0x1000 },
	/*0x0146*/ { NULL, FILE_PPOWERNODE,             0x0199 },
	/*0x0147*/ { NULL, FILE_PCETANBLUEGREENL,       0x1000 },
	/*0x0148*/ { NULL, FILE_PCETANBLUEGREENR,       0x1000 },
	/*0x0149*/ { NULL, FILE_PSKEDARCONSOLE,         0x1000 },
	/*0x014a*/ { NULL, FILE_PSKEDARCONSOLEPANEL,    0x1000 },
	/*0x014b*/ { NULL, FILE_PWEAPONCDOOR,           0x1000 },
	/*0x014c*/ { NULL, FILE_PTARGET,                0x1000 },
	/*0x014d*/ { NULL, FILE_PDEVICESECRETDOOR,      0x1000 },
	/*0x014e*/ { NULL, FILE_PCARRINGTONSECRETDOOR,  0x1000 },
	/*0x014f*/ { NULL, FILE_PSINISTERPC,            0x1000 },
	/*0x0150*/ { NULL, FILE_PSINISTERSTATION,       0x1000 },
	/*0x0151*/ { NULL, FILE_PKEYPADLOCK,            0x1000 },
	/*0x0152*/ { NULL, FILE_PTHUMBPRINTSCANNER,     0x1000 },
	/*0x0153*/ { NULL, FILE_PRETINALOCK,            0x1000 },
	/*0x0154*/ { NULL, FILE_PCARDLOCK,              0x1000 },
	/*0x0155*/ { NULL, FILE_PGOODSTATION,           0x1000 },
	/*0x0156*/ { NULL, FILE_PGOODPC,                0x1000 },
	/*0x0157*/ { NULL, FILE_PCHRAUTOGUN,            0x0199 },
	/*0x0158*/ { NULL, FILE_PG5BIGCHAIR,            0x0199 },
	/*0x0159*/ { NULL, FILE_PG5SMALLCHAIR,          0x0199 },
	/*0x015a*/ { NULL, FILE_PKINGSCEPTRE,           0x0199 },
	/*0x015b*/ { NULL, FILE_PLABCOAT,               0x0199 },
	/*0x015c*/ { NULL, FILE_PCIDOOR1,               0x1000 },
	/*0x015d*/ { NULL, FILE_PG5_CHAIR,              0x1000 },
	/*0x015e*/ { NULL, FILE_PG5_CHAIR2,             0x1000 },
	/*0x015f*/ { NULL, FILE_PDD_WINDOW_FOYER,       0x0199 },
	/*0x0160*/ { NULL, FILE_PCI_CABINET,            0x1000 },
	/*0x0161*/ { NULL, FILE_PCI_DESK,               0x1000 },
	/*0x0162*/ { NULL, FILE_PCI_CARR_DESK,          0x1000 },
	/*0x0163*/ { NULL, FILE_PCI_F_CHAIR,            0x1000 },
	/*0x0164*/ { NULL, FILE_PCI_LOUNGER,            0x1000 },
	/*0x0165*/ { NULL, FILE_PCI_F_SOFA,             0x1000 },
	/*0x0166*/ { NULL, FILE_PCI_TABLE,              0x1000 },
	/*0x0167*/ { NULL, FILE_PCV_COFFEE_TABLE,       0x1000 },
	/*0x0168*/ { NULL, FILE_PCV_CHAIR1,             0x1000 },
	/*0x0169*/ { NULL, FILE_PCV_CHAIR2,             0x1000 },
	/*0x016a*/ { NULL, FILE_PCV_SOFA,               0x1000 },
	/*0x016b*/ { NULL, FILE_PCV_CHAIR4,             0x1000 },
	/*0x016c*/ { NULL, FILE_PCV_LAMP,               0x1000 },
	/*0x016d*/ { NULL, FILE_PCV_CABINET,            0x1000 },
	/*0x016e*/ { NULL, FILE_PCV_F_BED,              0x1000 },
	/*0x016f*/ { NULL, FILE_PPEL_CHAIR1,            0x1000 },
	/*0x0170*/ { NULL, FILE_PSK_CONSOLE2,           0x1000 },
	/*0x0171*/ { NULL, FILE_PDD_EAR_TABLE,          0x1000 },
	/*0x0172*/ { NULL, FILE_PDD_EAR_CHAIR,          0x1000 },
	/*0x0173*/ { NULL, FILE_PAIRBASE_TABLE2,        0x1000 },
	/*0x0174*/ { NULL, FILE_PAIRBASE_CHAIR2,        0x1000 },
	/*0x0175*/ { NULL, FILE_PMISC_CRATE,            0x1000 },
	/*0x0176*/ { NULL, FILE_PA51_CRATE1,            0x1000 },
	/*0x0177*/ { NULL, FILE_PMISC_IRSPECS,          0x0c00 },
	/*0x0178*/ { NULL, FILE_PA51_ROOFGUN,           0x0199 },
	/*0x0179*/ { NULL, FILE_PSK_DRONE_GUN,          0x0199 },
	/*0x017a*/ { NULL, FILE_PCI_ROOFGUN,            0x0199 },
	/*0x017b*/ { NULL, FILE_PCV_TABLE,              0x1000 },
	/*0x017c*/ { NULL, FILE_PCIDOOR1_REF,           0x1000 },
	/*0x017d*/ { NULL, FILE_PALASKADOOR_OUT,        0x1000 },
	/*0x017e*/ { NULL, FILE_PALASKADOOR_IN,         0x1000 },
	/*0x017f*/ { NULL, FILE_PWIREFENCE,             0x0199 },
	/*0x0180*/ { NULL, FILE_PRARELOGO,              0x1000 },
	/*0x0181*/ { NULL, FILE_PKEYCARD,               0x0199 },
	/*0x0182*/ { NULL, FILE_PBODYARMOUR,            0x0133 },
	/*0x0183*/ { NULL, FILE_PA51GATE_R,             0x1000 },
	/*0x0184*/ { NULL, FILE_PA51GATE_L,             0x1000 },
	/*0x0185*/ { NULL, FILE_PAF1_LAMP,              0x1000 },
	/*0x0186*/ { NULL, FILE_PAF1_TOILET,            0x1000 },
	/*0x0187*/ { NULL, FILE_PAF1_DOORBIG2,          0x1000 },
	/*0x0188*/ { NULL, FILE_PAF1_PHONE,             0x1000 },
	/*0x0189*/ { NULL, FILE_PAF1_CARGODOOR,         0x1000 },
	/*0x018a*/ { NULL, FILE_PG5_ALARM,              0x1000 },
	/*0x018b*/ { NULL, FILE_PG5_LASER_SWITCH,       0x1000 },
	/*0x018c*/ { NULL, FILE_PSK_TEMPLECOLUMN4,      0x1000 },
	/*0x018d*/ { NULL, FILE_PCOREHATCH,             0x1000 },
	/*0x018e*/ { NULL, FILE_PA51GRATE,              0x1000 },
	/*0x018f*/ { NULL, FILE_PAF1ESCAPEDOOR,         0x1000 },
	/*0x0190*/ { NULL, FILE_PPRESCAPSULE,           0x1000 },
	/*0x0191*/ { NULL, FILE_PSKEDARBRIDGE,          0x1000 },
	/*0x0192*/ { NULL, FILE_PPELAGICDOOR2,          0x1000 },
	/*0x0193*/ { NULL, FILE_PTTB_BOX,               0x0066 },
	/*0x0194*/ { NULL, FILE_PINSTFRONTDOOR,         0x1000 },
	/*0x0195*/ { NULL, FILE_PCHRLASER,              0x0199 },
	/*0x0196*/ { NULL, FILE_PBAFTA,                 0x1000 },
	/*0x0197*/ { NULL, FILE_PCHRSONICSCREWER,       0x0199 },
	/*0x0198*/ { NULL, FILE_PCHRLUMPHAMMER,         0x0199 },
	/*0x0199*/ { NULL, FILE_PEXPLOSIVEBRICK,        0x1000 },
	/*0x019a*/ { NULL, FILE_PSKEDARBOMB,            0x1000 },
	/*0x019b*/ { NULL, FILE_PZIGGYCARD,             0x1000 },
	/*0x019c*/ { NULL, FILE_PSAFEITEM,              0x1000 },
	/*0x019d*/ { NULL, FILE_PRUSSDAR,               0x0333 },
	/*0x019e*/ { NULL, FILE_PXRAYSPECS,             0x0c00 },
	/*0x019f*/ { NULL, FILE_PCHRLUMPHAMMER,         0x1000 },
	/*0x01a0*/ { NULL, FILE_PCHREYESPY,             0x1800 },
	/*0x01a1*/ { NULL, FILE_PCHRDOORDECODER,        0x0199 },
	/*0x01a2*/ { NULL, FILE_PAF1_TABLE,             0x0199 },
	/*0x01a3*/ { NULL, FILE_PSHUTTLEDOOR,           0x1000 },
	/*0x01a4*/ { NULL, FILE_PRUINBRIDGE,            0x0199 },
	/*0x01a5*/ { NULL, FILE_PSECRETINDOOR,          0x1000 },
	/*0x01a6*/ { NULL, FILE_PSENSITIVEINFO,         0x0199 },
	/*0x01a7*/ { NULL, FILE_PSUITCASE,              0x1000 },
	/*0x01a8*/ { NULL, FILE_PSKPUZZLEOBJECT,        0x1000 },
	/*0x01a9*/ { NULL, FILE_PA51LIFTDOOR,           0x1000 },
	/*0x01aa*/ { NULL, FILE_PCIHUB,                 0x1000 },
	/*0x01ab*/ { NULL, FILE_PSK_SHIP_DOOR2,         0x1000 },
	/*0x01ac*/ { NULL, FILE_PSK_WINDOW1,            0x1000 },
	/*0x01ad*/ { NULL, FILE_PSK_HANGARDOORB_TOP,    0x1000 },
	/*0x01ae*/ { NULL, FILE_PSK_HANGARDOORB_BOT,    0x1000 },
	/*0x01af*/ { NULL, FILE_PAF1_INNERDOOR,         0x1000 },
	/*0x01b0*/ { NULL, FILE_PLASER_POST,            0x1000 },
	/*0x01b1*/ { NULL, FILE_PTARGETAMP,             0x0199 },
	/*0x01b2*/ { NULL, FILE_PSK_LIFT,               0x1000 },
	/*0x01b3*/ { NULL, FILE_PKNOCKKNOCK,            0x1000 },
	/*0x01b4*/ { NULL, FILE_PCETANDOOR,             0x1000 },
	/*0x01b5*/ { NULL, FILE_PAF1RUBBLE,             0x1000 },
	/*0x01b6*/ { NULL, FILE_PDD_DR_NONREF,          0x1000 },
	/*0x01b7*/ { NULL, FILE_PCETANDOORSIDE,         0x1000 },
	/*0x01b8*/ { NULL, FILE_PBUDDYBRIDGE,           0x0199 },
};

// 21e54
u8 propexplosiontypes[] = {
	/*0x0000*/ 0x00,
	/*0x0001*/ 0x00,
	/*0x0002*/ 0x00,
	/*0x0003*/ 0x00,
	/*0x0004*/ 0x00,
	/*0x0005*/ 0x00,
	/*0x0006*/ 0x10,
	/*0x0007*/ 0x00,
	/*0x0008*/ 0x08,
	/*0x0009*/ 0x0b,
	/*0x000a*/ 0x06,
	/*0x000b*/ 0x04,
	/*0x000c*/ 0x00,
	/*0x000d*/ 0x00,
	/*0x000e*/ 0x00,
	/*0x000f*/ 0x00,
	/*0x0010*/ 0x00,
	/*0x0011*/ 0x00,
	/*0x0012*/ 0x00,
	/*0x0013*/ 0x00,
	/*0x0014*/ 0x00,
	/*0x0015*/ 0x00,
	/*0x0016*/ 0x00,
	/*0x0017*/ 0x00,
	/*0x0018*/ 0x00,
	/*0x0019*/ 0x03,
	/*0x001a*/ 0x00,
	/*0x001b*/ 0x06,
	/*0x001c*/ 0x00,
	/*0x001d*/ 0x00,
	/*0x001e*/ 0x00,
	/*0x001f*/ 0x06,
	/*0x0020*/ 0x09,
	/*0x0021*/ 0x00,
	/*0x0022*/ 0x00,
	/*0x0023*/ 0x00,
	/*0x0024*/ 0x00,
	/*0x0025*/ 0x00,
	/*0x0026*/ 0x00,
	/*0x0027*/ 0x00,
	/*0x0028*/ 0x03,
	/*0x0029*/ 0x03,
	/*0x002a*/ 0x03,
	/*0x002b*/ 0x00,
	/*0x002c*/ 0x00,
	/*0x002d*/ 0x00,
	/*0x002e*/ 0x00,
	/*0x002f*/ 0x00,
	/*0x0030*/ 0x00,
	/*0x0031*/ 0x00,
	/*0x0032*/ 0x00,
	/*0x0033*/ 0x00,
	/*0x0034*/ 0x00,
	/*0x0035*/ 0x00,
	/*0x0036*/ 0x00,
	/*0x0037*/ 0x00,
	/*0x0038*/ 0x00,
	/*0x0039*/ 0x00,
	/*0x003a*/ 0x00,
	/*0x003b*/ 0x0c,
	/*0x003c*/ 0x00,
	/*0x003d*/ 0x00,
	/*0x003e*/ 0x00,
	/*0x003f*/ 0x00,
	/*0x0040*/ 0x00,
	/*0x0041*/ 0x00,
	/*0x0042*/ 0x0b,
	/*0x0043*/ 0x00,
	/*0x0044*/ 0x00,
	/*0x0045*/ 0x00,
	/*0x0046*/ 0x00,
	/*0x0047*/ 0x00,
	/*0x0048*/ 0x00,
	/*0x0049*/ 0x00,
	/*0x004a*/ 0x00,
	/*0x004b*/ 0x00,
	/*0x004c*/ 0x00,
	/*0x004d*/ 0x00,
	/*0x004e*/ 0x00,
	/*0x004f*/ 0x00,
	/*0x0050*/ 0x00,
	/*0x0051*/ 0x00,
	/*0x0052*/ 0x00,
	/*0x0053*/ 0x00,
	/*0x0054*/ 0x00,
	/*0x0055*/ 0x00,
	/*0x0056*/ 0x00,
	/*0x0057*/ 0x00,
	/*0x0058*/ 0x0d,
	/*0x0059*/ 0x0d,
	/*0x005a*/ 0x0d,
	/*0x005b*/ 0x0d,
	/*0x005c*/ 0x0d,
	/*0x005d*/ 0x00,
	/*0x005e*/ 0x00,
	/*0x005f*/ 0x00,
	/*0x0060*/ 0x00,
	/*0x0061*/ 0x07,
	/*0x0062*/ 0x04,
	/*0x0063*/ 0x0c,
	/*0x0064*/ 0x00,
	/*0x0065*/ 0x00,
	/*0x0066*/ 0x03,
	/*0x0067*/ 0x00,
	/*0x0068*/ 0x00,
	/*0x0069*/ 0x00,
	/*0x006a*/ 0x00,
	/*0x006b*/ 0x00,
	/*0x006c*/ 0x00,
	/*0x006d*/ 0x00,
	/*0x006e*/ 0x0c,
	/*0x006f*/ 0x0c,
	/*0x0070*/ 0x00,
	/*0x0071*/ 0x00,
	/*0x0072*/ 0x00,
	/*0x0073*/ 0x00,
	/*0x0074*/ 0x00,
	/*0x0075*/ 0x00,
	/*0x0076*/ 0x00,
	/*0x0077*/ 0x00,
	/*0x0078*/ 0x00,
	/*0x0079*/ 0x00,
	/*0x007a*/ 0x00,
	/*0x007b*/ 0x00,
	/*0x007c*/ 0x00,
	/*0x007d*/ 0x00,
	/*0x007e*/ 0x0d,
	/*0x007f*/ 0x00,
	/*0x0080*/ 0x00,
	/*0x0081*/ 0x00,
	/*0x0082*/ 0x00,
	/*0x0083*/ 0x00,
	/*0x0084*/ 0x00,
	/*0x0085*/ 0x00,
	/*0x0086*/ 0x00,
	/*0x0087*/ 0x00,
	/*0x0088*/ 0x00,
	/*0x0089*/ 0x00,
	/*0x008a*/ 0x00,
	/*0x008b*/ 0x00,
	/*0x008c*/ 0x00,
	/*0x008d*/ 0x0d,
	/*0x008e*/ 0x0c,
	/*0x008f*/ 0x0c,
	/*0x0090*/ 0x00,
	/*0x0091*/ 0x00,
	/*0x0092*/ 0x00,
	/*0x0093*/ 0x00,
	/*0x0094*/ 0x00,
	/*0x0095*/ 0x00,
	/*0x0096*/ 0x00,
	/*0x0097*/ 0x00,
	/*0x0098*/ 0x00,
	/*0x0099*/ 0x00,
	/*0x009a*/ 0x00,
	/*0x009b*/ 0x00,
	/*0x009c*/ 0x00,
	/*0x009d*/ 0x00,
	/*0x009e*/ 0x00,
	/*0x009f*/ 0x0d,
	/*0x00a0*/ 0x00,
	/*0x00a1*/ 0x00,
	/*0x00a2*/ 0x00,
	/*0x00a3*/ 0x00,
	/*0x00a4*/ 0x00,
	/*0x00a5*/ 0x00,
	/*0x00a6*/ 0x00,
	/*0x00a7*/ 0x09,
	/*0x00a8*/ 0x00,
	/*0x00a9*/ 0x00,
	/*0x00aa*/ 0x00,
	/*0x00ab*/ 0x00,
	/*0x00ac*/ 0x00,
	/*0x00ad*/ 0x00,
	/*0x00ae*/ 0x00,
	/*0x00af*/ 0x00,
	/*0x00b0*/ 0x00,
	/*0x00b1*/ 0x00,
	/*0x00b2*/ 0x00,
	/*0x00b3*/ 0x00,
	/*0x00b4*/ 0x00,
	/*0x00b5*/ 0x00,
	/*0x00b6*/ 0x00,
	/*0x00b7*/ 0x07,
	/*0x00b8*/ 0x06,
	/*0x00b9*/ 0x00,
	/*0x00ba*/ 0x09,
	/*0x00bb*/ 0x00,
	/*0x00bc*/ 0x00,
	/*0x00bd*/ 0x06,
	/*0x00be*/ 0x06,
	/*0x00bf*/ 0x06,
	/*0x00c0*/ 0x00,
	/*0x00c1*/ 0x00,
	/*0x00c2*/ 0x0b,
	/*0x00c3*/ 0x00,
	/*0x00c4*/ 0x00,
	/*0x00c5*/ 0x06,
	/*0x00c6*/ 0x09,
	/*0x00c7*/ 0x00,
	/*0x00c8*/ 0x00,
	/*0x00c9*/ 0x0b,
	/*0x00ca*/ 0x06,
	/*0x00cb*/ 0x00,
	/*0x00cc*/ 0x00,
	/*0x00cd*/ 0x00,
	/*0x00ce*/ 0x00,
	/*0x00cf*/ 0x00,
	/*0x00d0*/ 0x19,
	/*0x00d1*/ 0x00,
	/*0x00d2*/ 0x00,
	/*0x00d3*/ 0x00,
	/*0x00d4*/ 0x00,
	/*0x00d5*/ 0x00,
	/*0x00d6*/ 0x00,
	/*0x00d7*/ 0x00,
	/*0x00d8*/ 0x00,
	/*0x00d9*/ 0x00,
	/*0x00da*/ 0x00,
	/*0x00db*/ 0x00,
	/*0x00dc*/ 0x00,
	/*0x00dd*/ 0x00,
	/*0x00de*/ 0x00,
	/*0x00df*/ 0x00,
	/*0x00e0*/ 0x00,
	/*0x00e1*/ 0x00,
	/*0x00e2*/ 0x00,
	/*0x00e3*/ 0x00,
	/*0x00e4*/ 0x00,
	/*0x00e5*/ 0x00,
	/*0x00e6*/ 0x00,
	/*0x00e7*/ 0x00,
	/*0x00e8*/ 0x00,
	/*0x00e9*/ 0x00,
	/*0x00ea*/ 0x0b,
	/*0x00eb*/ 0x00,
	/*0x00ec*/ 0x00,
	/*0x00ed*/ 0x00,
	/*0x00ee*/ 0x00,
	/*0x00ef*/ 0x00,
	/*0x00f0*/ 0x00,
	/*0x00f1*/ 0x00,
	/*0x00f2*/ 0x00,
	/*0x00f3*/ 0x11,
	/*0x00f4*/ 0x00,
	/*0x00f5*/ 0x00,
	/*0x00f6*/ 0x00,
	/*0x00f7*/ 0x00,
	/*0x00f8*/ 0x00,
	/*0x00f9*/ 0x00,
	/*0x00fa*/ 0x00,
	/*0x00fb*/ 0x00,
	/*0x00fc*/ 0x00,
	/*0x00fd*/ 0x00,
	/*0x00fe*/ 0x00,
	/*0x00ff*/ 0x00,
	/*0x0100*/ 0x00,
	/*0x0101*/ 0x00,
	/*0x0102*/ 0x00,
	/*0x0103*/ 0x00,
	/*0x0104*/ 0x00,
	/*0x0105*/ 0x00,
	/*0x0106*/ 0x00,
	/*0x0107*/ 0x00,
	/*0x0108*/ 0x00,
	/*0x0109*/ 0x00,
	/*0x010a*/ 0x00,
	/*0x010b*/ 0x00,
	/*0x010c*/ 0x00,
	/*0x010d*/ 0x00,
	/*0x010e*/ 0x00,
	/*0x010f*/ 0x00,
	/*0x0110*/ 0x00,
	/*0x0111*/ 0x00,
	/*0x0112*/ 0x00,
	/*0x0113*/ 0x00,
	/*0x0114*/ 0x00,
	/*0x0115*/ 0x00,
	/*0x0116*/ 0x00,
	/*0x0117*/ 0x00,
	/*0x0118*/ 0x00,
	/*0x0119*/ 0x00,
	/*0x011a*/ 0x0d,
	/*0x011b*/ 0x0d,
	/*0x011c*/ 0x0d,
	/*0x011d*/ 0x0d,
	/*0x011e*/ 0x00,
	/*0x011f*/ 0x00,
	/*0x0120*/ 0x00,
	/*0x0121*/ 0x00,
	/*0x0122*/ 0x00,
	/*0x0123*/ 0x00,
	/*0x0124*/ 0x00,
	/*0x0125*/ 0x00,
	/*0x0126*/ 0x00,
	/*0x0127*/ 0x0d,
	/*0x0128*/ 0x0d,
	/*0x0129*/ 0x00,
	/*0x012a*/ 0x0d,
	/*0x012b*/ 0x0d,
	/*0x012c*/ 0x08,
	/*0x012d*/ 0x00,
	/*0x012e*/ 0x00,
	/*0x012f*/ 0x0c,
	/*0x0130*/ 0x0d,
	/*0x0131*/ 0x07,
	/*0x0132*/ 0x0b,
	/*0x0133*/ 0x00,
	/*0x0134*/ 0x07,
	/*0x0135*/ 0x07,
	/*0x0136*/ 0x00,
	/*0x0137*/ 0x00,
	/*0x0138*/ 0x00,
	/*0x0139*/ 0x00,
	/*0x013a*/ 0x00,
	/*0x013b*/ 0x00,
	/*0x013c*/ 0x00,
	/*0x013d*/ 0x00,
	/*0x013e*/ 0x00,
	/*0x013f*/ 0x00,
	/*0x0140*/ 0x00,
	/*0x0141*/ 0x00,
	/*0x0142*/ 0x00,
	/*0x0143*/ 0x00,
	/*0x0144*/ 0x00,
	/*0x0145*/ 0x00,
	/*0x0146*/ 0x00,
	/*0x0147*/ 0x00,
	/*0x0148*/ 0x00,
	/*0x0149*/ 0x00,
	/*0x014a*/ 0x00,
	/*0x014b*/ 0x0d,
	/*0x014c*/ 0x07,
	/*0x014d*/ 0x00,
	/*0x014e*/ 0x00,
	/*0x014f*/ 0x00,
	/*0x0150*/ 0x00,
	/*0x0151*/ 0x07,
	/*0x0152*/ 0x00,
	/*0x0153*/ 0x00,
	/*0x0154*/ 0x00,
	/*0x0155*/ 0x00,
	/*0x0156*/ 0x00,
	/*0x0157*/ 0x07,
	/*0x0158*/ 0x08,
	/*0x0159*/ 0x06,
	/*0x015a*/ 0x06,
	/*0x015b*/ 0x06,
	/*0x015c*/ 0x06,
	/*0x015d*/ 0x08,
	/*0x015e*/ 0x07,
	/*0x015f*/ 0x07,
	/*0x0160*/ 0x00,
	/*0x0161*/ 0x00,
	/*0x0162*/ 0x00,
	/*0x0163*/ 0x00,
	/*0x0164*/ 0x00,
	/*0x0165*/ 0x00,
	/*0x0166*/ 0x00,
	/*0x0167*/ 0x00,
	/*0x0168*/ 0x00,
	/*0x0169*/ 0x00,
	/*0x016a*/ 0x00,
	/*0x016b*/ 0x00,
	/*0x016c*/ 0x00,
	/*0x016d*/ 0x00,
	/*0x016e*/ 0x00,
	/*0x016f*/ 0x00,
	/*0x0170*/ 0x00,
	/*0x0171*/ 0x00,
	/*0x0172*/ 0x00,
	/*0x0173*/ 0x00,
	/*0x0174*/ 0x06,
	/*0x0175*/ 0x00,
	/*0x0176*/ 0x00,
	/*0x0177*/ 0x00,
	/*0x0178*/ 0x07,
	/*0x0179*/ 0x00,
	/*0x017a*/ 0x00,
	/*0x017b*/ 0x00,
	/*0x017c*/ 0x00,
	/*0x017d*/ 0x00,
	/*0x017e*/ 0x00,
	/*0x017f*/ 0x06,
	/*0x0180*/ 0x08,
	/*0x0181*/ 0x08,
	/*0x0182*/ 0x08,
	/*0x0183*/ 0x00,
	/*0x0184*/ 0x00,
	/*0x0185*/ 0x00,
	/*0x0186*/ 0x00,
	/*0x0187*/ 0x00,
	/*0x0188*/ 0x00,
	/*0x0189*/ 0x00,
	/*0x018a*/ 0x00,
	/*0x018b*/ 0x00,
	/*0x018c*/ 0x00,
	/*0x018d*/ 0x06,
	/*0x018e*/ 0x00,
	/*0x018f*/ 0x00,
	/*0x0190*/ 0x06,
	/*0x0191*/ 0x00,
	/*0x0192*/ 0x07,
	/*0x0193*/ 0x07,
	/*0x0194*/ 0x00,
	/*0x0195*/ 0x00,
	/*0x0196*/ 0x00,
	/*0x0197*/ 0x00,
	/*0x0198*/ 0x0d,
	/*0x0199*/ 0x00,
	/*0x019a*/ 0x00,
	/*0x019b*/ 0x00,
	/*0x019c*/ 0x00,
	/*0x019d*/ 0x00,
	/*0x019e*/ 0x06,
	/*0x019f*/ 0x00,
	/*0x01a0*/ 0x00,
	/*0x01a1*/ 0x00,
	/*0x01a2*/ 0x11,
	/*0x01a3*/ 0x00,
	/*0x01a4*/ 0x00,
	/*0x01a5*/ 0x00,
	/*0x01a6*/ 0x00,
	/*0x01a7*/ 0x00,
	/*0x01a8*/ 0x00,
	/*0x01a9*/ 0x00,
	/*0x01aa*/ 0x00,
	/*0x01ab*/ 0x00,
	/*0x01ac*/ 0x00,
	/*0x01ad*/ 0x00,
	/*0x01ae*/ 0x00,
	/*0x01af*/ 0x0b,
	/*0x01b0*/ 0x00,
	/*0x01b1*/ 0x00,
	/*0x01b2*/ 0x00,
	/*0x01b3*/ 0x06,
	/*0x01b4*/ 0x00,
	/*0x01b5*/ 0x00,
	/*0x01b6*/ 0x00,
	/*0x01b7*/ 0x00,
	/*0x01b8*/ 0x00,
	/*0x01b9*/ 0x00,
	/*0x01ba*/ 0x00,
	/*0x01bb*/ 0x00,
	/*0x01bc*/ 0x00,
	/*0x01bd*/ 0x00,
	/*0x01be*/ 0x00,
	/*0x01bf*/ 0x00,
};

u32 var8007bff4 = 0x0000ff00;
u32 var8007bff8 = 0x00000000;
u32 var8007bffc = 0x00000000;
u32 var8007c000 = 0x00000000;
u32 var8007c004 = 0x00000000;
u32 var8007c008 = 0x00000000;
u32 var8007c00c = 0x00000000;
u32 var8007c010 = 0xf8f4f1e0;
u32 var8007c014 = 0x473f41dd;
u32 var8007c018 = 0xa510c9c6;
u32 var8007c01c = 0xbcae0bd1;
u32 var8007c020 = 0x0ff73a30;
u32 var8007c024 = 0x724083b7;
u32 var8007c028 = 0xffffffff;
u32 var8007c02c = 0xffffffff;
u32 var8007c030 = 0xffffffff;
u32 var8007c034 = 0x00000000;
u32 var8007c038 = 0x00000000;
u32 var8007c03c = 0x00000000;

// 22060
u16 var8007c040[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
};

// 2208c
struct stagethinglist stagethinglist_2208c = {
	0x02, 21, var8007c040,
};

u32 var8007c074 = 0x00000000;
u32 var8007c078 = 0x00000000;
u32 var8007c07c = 0x00000000;

// 220a0
u16 var8007c080[] = {
	0x0000,
	0x0101,
};

// 220a4
struct stagethinglist stagethinglist_220a4 = {
	0x03, 2, var8007c080,
};

u32 var8007c08c = 0x00000000;

// 220b0
u16 var8007c090[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0304,
	0x0403,
	0x0506,
	0x0605,
	0x0708,
	0x0807,
	0x090a,
	0x0a09,
	0x0b0c,
	0x0c0b,
	0x0d0e,
	0x0e0d,
};

// 220d0
struct stagethinglist stagethinglist_220d0 = {
	0x0b, 15, var8007c090,
};

u32 var8007c0dc;
u32 var8007c0f4;
u32 var8007c10c;
u32 var8007c124;
u32 var8007c130;
u32 var8007c148;

u32 var8007c0b8 = 0x00000000;
u32 var8007c0bc = 0x00000000;
u32 var8007c0c0 = (u32) &var8007c0dc;
u32 var8007c0c4 = (u32) &stagethinglist_220d0;
u32 var8007c0c8 = 0x00000000;
u32 var8007c0cc = 0x00000003;
u32 var8007c0d0 = 0x4224a519;
u32 var8007c0d4 = 0x00000000;
u32 var8007c0d8 = 0x00000000;

u32 var8007c0dc = 0x00010000;
u32 var8007c0e0 = (u32) &var8007c124;
u32 var8007c0e4 = 0x00000000;
u32 var8007c0e8 = 0x00000000;
u32 var8007c0ec = 0x00000000;
u32 var8007c0f0 = (u32) &var8007c0f4;

u32 var8007c0f4 = 0x00020000;
u32 var8007c0f8 = (u32) &var8007c130;
u32 var8007c0fc = (u32) &var8007c0dc;
u32 var8007c100 = 0x00000000;
u32 var8007c104 = 0x00000000;
u32 var8007c108 = (u32) &var8007c10c;

u32 var8007c10c = 0x00020000;
u32 var8007c110 = (u32) &var8007c148;
u32 var8007c114 = (u32) &var8007c0f4;
u32 var8007c118 = 0x00000000;
u32 var8007c11c = 0x00000000;
u32 var8007c120 = 0x00000000;

u32 var8007c124 = 0x00000001;
u32 var8007c128 = 0x00000000;
u32 var8007c12c = 0x00000000;

u32 var8007c130 = 0x3f96c81d;
u32 var8007c134 = 0x422493d6;
u32 var8007c138 = 0x00000000;
u32 var8007c13c = 0x00010002;
u32 var8007c140 = 0xffffffff;
u32 var8007c144 = 0x00000000;

u32 var8007c148 = 0xc024dda0;
u32 var8007c14c = 0x43f036ea;
u32 var8007c150 = 0x00000000;
u32 var8007c154 = 0x00020000;
u32 var8007c158 = 0xffffffff;
u32 var8007c15c = 0x00000000;

// 22180
u16 var8007c160[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0304,
	0x0403,
	0x0506,
	0x0605,
	0x0708,
	0x0807,
	0x090a,
	0x0a09,
	0x0b0c,
	0x0c0b,
	0x0d0e,
	0x0e0d,
	0x0f0f,
	0x1010,
	0x1111,
};

// 221a4
struct stagethinglist stagethinglist_221a4 = {
	0x0a, 18, var8007c160,
};

u32 var8007c18c = 0x00000000;
// 221b0
u16 var8007c190[] = {
	0x0000,
};

// 221b4
struct stagethinglist stagethinglist_221b4 = {
	STAGE_MP_G5BUILDING, 1, var8007c190,
};

u32 var8007c19c = 0x00000000;
// 221c0
u16 var8007c1a0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0505,
	0x0303,
	0x0404,
};

// 221cc
struct stagethinglist stagethinglist_221cc = {
	0x07, 6, var8007c1a0,
};

u32 var8007c1b4 = 0x00000000;
u32 var8007c1b8 = 0x00000000;
u32 var8007c1bc = 0x00000000;
// 221e0
u16 var8007c1c0[] = {
	0x0000,
};

// 221e4
struct stagethinglist stagethinglist_221e4 = {
	0x08, 1, var8007c1c0,
};

u32 var8007c1cc = 0x00000000;
// 221f0
u16 var8007c1d0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
};

// 22200
struct stagethinglist stagethinglist_22200 = {
	0x06, 7, var8007c1d0,
};

u32 var8007c1e8 = 0x00000000;
u32 var8007c1ec = 0x00000000;
// 22210
u16 var8007c1f0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0606,
	0x0404,
	0x0505,
};

// 22220
struct stagethinglist stagethinglist_22220 = {
	0x05, 7, var8007c1f0,
};

u32 var8007c208 = 0x00000000;
u32 var8007c20c = 0x00000000;
// 22230
u16 var8007c210[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
};

// 2224c
struct stagethinglist stagethinglist_2224c = {
	0x04, 13, var8007c210,
};

// 22254
u16 var8007c234[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
	0x2b2b,
	0x2c2c,
	0x2d2d,
	0x2e2e,
};

// 222b4
struct stagethinglist stagethinglist_222b4 = {
	STAGE_PELAGIC, 47, var8007c234,
};

// 222bc
u16 var8007c29c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
	0x2b2b,
	0x2c2c,
	0x2d2d,
};

// 22318
struct stagethinglist stagethinglist_22318 = {
	STAGE_TEST_RUN, 46, var8007c29c,
};

// 22320
u16 var8007c300[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
};

// 22374
struct stagethinglist stagethinglist_22374 = {
	0x24, 41, var8007c300,
};

// 2237c
u16 var8007c35c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
};

// 223d4
struct stagethinglist stagethinglist_223d4 = {
	STAGE_MP_TEMPLE, 43, var8007c35c,
};

// 223dc
u16 var8007c3bc[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
};

// 22424
struct stagethinglist stagethinglist_22424 = {
	STAGE_CITRAINING, 35, var8007c3bc,
};

// 2242c
u16 var8007c40c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
};

// 2247c
struct stagethinglist stagethinglist_2247c = {
	STAGE_TEST_MP14, 40, var8007c40c,
};

// 22484
u16 var8007c464[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
};

// 224d8
struct stagethinglist stagethinglist_224d8 = {
	STAGE_MP_GRID, 41, var8007c464,
};

// 224e0
u16 var8007c4c0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
};

// 22538
struct stagethinglist stagethinglist_22538 = {
	STAGE_TEST_MP16, 43, var8007c4c0,
};

// 22540
u16 var8007c520[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
};

// 2258c
struct stagethinglist stagethinglist_2258c = {
	STAGE_TEST_MP17, 38, var8007c520,
};

// 22594
u16 var8007c574[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
};

// 225d8
struct stagethinglist stagethinglist_225d8 = {
	STAGE_TEST_MP18, 33, var8007c574,
};

// 225e0
u16 var8007c5c0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
};

// 22630
struct stagethinglist stagethinglist_22630 = {
	STAGE_TEST_MP19, 39, var8007c5c0,
};

// 22638
u16 var8007c618[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
	0x2b2b,
	0x2c2c,
	0x2d2d,
	0x2e2e,
	0x2f2f,
};

// 22698
struct stagethinglist stagethinglist_22698 = {
	STAGE_TEST_MP20, 48, var8007c618,
};

// 226a0
u16 var8007c680[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
};

// 226e8
struct stagethinglist stagethinglist_226e8 = {
	STAGE_TEST_UFF, 35, var8007c680,
};

// 226f0
u16 var8007c6d0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
	0x2b2b,
	0x2c2c,
	0x2d2d,
	0x2e2e,
	0x2f2f,
	0x3030,
	0x3131,
};

// 22754
struct stagethinglist stagethinglist_22754 = {
	STAGE_TEST_OLD, 50, var8007c6d0,
};

// 2275c
u16 var8007c73c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
};

// 227ac
struct stagethinglist stagethinglist_227ac = {
	0x64, 39, var8007c73c,
};

// 227b4
u16 var8007c794[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
};

// 22804
struct stagethinglist stagethinglist_22804 = {
	0x65, 40, var8007c794,
};

// 2280c
u16 var8007c7ec[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
};

// 2285c
struct stagethinglist stagethinglist_2285c = {
	0x66, 40, var8007c7ec,
};

// 22864
u16 var8007c844[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
};

// 228b4
struct stagethinglist stagethinglist_228b4 = {
	0x67, 40, var8007c844,
};

// 228bc
u16 var8007c89c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
	0x2b2b,
	0x2c2c,
	0x2d2d,
	0x2e2e,
};

// 2291c
struct stagethinglist stagethinglist_2291c = {
	0x68, 47, var8007c89c,
};

// 22924
u16 var8007c904[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
};

// 22970
struct stagethinglist stagethinglist_22970 = {
	0x69, 37, var8007c904,
};

// 22978
u16 var8007c958[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
};

// 229c4
struct stagethinglist stagethinglist_229c4 = {
	0x6a, 38, var8007c958,
};

// 229cc
u16 var8007c9ac[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
};

// 22a20
struct stagethinglist stagethinglist_22a20 = {
	0x6b, 42, var8007c9ac,
};

// 22a28
u16 var8007ca08[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
};

// 22a78
struct stagethinglist stagethinglist_22a78 = {
	0x6c, 39, var8007ca08,
};

// 22a80
u16 var8007ca60[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
	0x2b2b,
	0x2c2c,
	0x2d2d,
};

// 22adc
struct stagethinglist stagethinglist_22adc = {
	0x6d, 46, var8007ca60,
};

// 22ae4
u16 var8007cac4[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
};

// 22b28
struct stagethinglist stagethinglist_22b28 = {
	0x6e, 34, var8007cac4,
};

// 22b30
u16 var8007cb10[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
};

// 22b80
struct stagethinglist stagethinglist_22b80 = {
	0x6f, 40, var8007cb10,
};

// 22b88
u16 var8007cb68[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
	0x2929,
	0x2a2a,
};

// 22be0
struct stagethinglist stagethinglist_22be0 = {
	0x70, 43, var8007cb68,
};

// 22be8
u16 var8007cbc8[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
	0x2525,
	0x2626,
	0x2727,
	0x2828,
};

// 22c3c
struct stagethinglist stagethinglist_22c3c = {
	0x71, 41, var8007cbc8,
};

// 22c44
u16 var8007cc24[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
};

// 22c54
struct stagethinglist stagethinglist_22c54 = {
	STAGE_SKEDARRUINS, 7, var8007cc24,
};

// 22c5c
u16 var8007cc3c[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
};

// 22ca0
struct stagethinglist stagethinglist_22ca0 = {
	0xfa, 33, var8007cc3c,
};

// 22ca8
u16 var8007cc88[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
};

// 22cf0
struct stagethinglist stagethinglist_22cf0 = {
	0x72, 35, var8007cc88,
};

// 22cf8
u16 var8007ccd8[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
};

// 22d40
struct stagethinglist stagethinglist_22d40 = {
	0x73, 35, var8007ccd8,
};

// 22d48
u16 var8007cd28[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
};

// 22d90
struct stagethinglist stagethinglist_22d90 = {
	0x74, 35, var8007cd28,
};

// 22d98
u16 var8007cd78[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
};

// 22de0
struct stagethinglist stagethinglist_22de0 = {
	0x75, 35, var8007cd78,
};

// 22de8
u16 var8007cdc8[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1212,
	0x1313,
	0x1414,
	0x1515,
	0x1616,
	0x1717,
	0x1818,
	0x1919,
	0x1a1a,
	0x1b1b,
	0x1c1c,
	0x1d1d,
	0x1e1e,
	0x1f1f,
	0x2020,
	0x2121,
	0x2222,
	0x2323,
	0x2424,
};

// 22e34
struct stagethinglist stagethinglist_22e34 = {
	0x76, 37, var8007cdc8,
};

u32 var8007ce1c = 0x00000000;
// 22e40
u16 var8007ce20[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0304,
	0x0403,
	0x0506,
	0x0605,
	0x0708,
	0x0807,
	0x090a,
	0x0a09,
	0x0b0c,
	0x0c0b,
	0x0d0e,
	0x0e0d,
};

// 22e60
struct stagethinglist stagethinglist_22e60 = {
	STAGE_MAIANSOS, 15, var8007ce20,
};

u32 var8007ce48 = 0x00000000;
u32 var8007ce4c = 0x00000000;
// 22e70
u16 var8007ce50[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x080f,
	0x0910,
	0x0a11,
	0x0b12,
	0x0c13,
	0x0d14,
	0x0e15,
	0x0f08,
	0x1009,
	0x110a,
	0x120b,
	0x130c,
	0x140d,
	0x150e,
	0x161d,
	0x171e,
	0x181f,
	0x1920,
	0x1a21,
	0x1b22,
	0x1c23,
	0x1d16,
	0x1e17,
	0x1f18,
	0x2019,
	0x211a,
	0x221b,
	0x231c,
};

// 22eb8
struct stagethinglist stagethinglist_22eb8 = {
	STAGE_CRASHSITE, 36, var8007ce50,
};

// 22ec0
u16 var8007cea0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
};

// 22ec8
struct stagethinglist stagethinglist_22ec8 = {
	0x28, 4, var8007cea0,
};

// 22ed0
u16 var8007ceb0[] = {
	0x0000,
	0x0101,
	0x0202,
	0x0303,
	0x0404,
	0x0505,
	0x0606,
	0x0707,
	0x0808,
	0x0909,
	0x0a0a,
	0x0b0b,
	0x0c0c,
	0x0d0d,
	0x0e0e,
	0x0f0f,
	0x1010,
	0x1111,
	0x1213,
	0x1312,
	0x1415,
	0x1514,
	0x1617,
	0x1716,
	0x1819,
	0x1918,
	0x1a1b,
	0x1b1a,
	0x1c1d,
	0x1d1c,
};

// 22f0c
struct stagethinglist stagethinglist_22f0c = {
	STAGE_EXTRACTION, 30, var8007ceb0,
};

// 22f14
u16 var8007cef4[] = {
	0x0000,
	0x0102,
	0x0201,
};

// 22f1c
struct stagethinglist stagethinglist_22f1c = {
	STAGE_ATTACKSHIP, 3, var8007cef4,
};

// 22f24
struct body g_Bodies[] = {
	{ /*0x0000*/ 1, 0x029c, FILE_CDJBOND,          1,    1.0446009635925,  0, FILE_GHAND_DDSECURITY      },
	{ /*0x0001*/ 1, 0x029c, FILE_CCONNERY,         1,    1.0300469398499,  0, FILE_GHAND_MRBLONDE        },
	{ /*0x0002*/ 1, 0x0294, FILE_CDALTON,          1,    1.0572769641876,  0, FILE_GHAND_DDSECURITY      },
	{ /*0x0003*/ 1, 0x029c, FILE_CMOORE,           1,    1.0399061441422,  0, FILE_GHAND_DDSECURITY      },
	{ /*0x0004*/ 0, 0x4434, FILE_CHEADDARK_COMBAT, 1,    1,                0, 0                          },
	{ /*0x0005*/ 1, 0x4c6c, FILE_CHEADELVIS,       1,    1,                0, 0                          },
	{ /*0x0006*/ 1, 0x4034, FILE_CHEADROSS,        1,    1,                0, 0                          },
	{ /*0x0007*/ 1, 0x4034, FILE_CHEADCARRINGTON,  1,    1,                0, 0                          },
	{ /*0x0008*/ 1, 0x5434, FILE_CHEADMRBLONDE,    1,    1,                0, 0                          },
	{ /*0x0009*/ 1, 0x4034, FILE_CHEADTRENT,       1,    1,                0, 0                          },
	{ /*0x000a*/ 1, 0x4034, FILE_CHEADDDSHOCK,     1,    1,                0, 0                          },
	{ /*0x000b*/ 1, 0x4034, FILE_CHEADGRAHAM,      1,    1,                0, 0                          },
	{ /*0x000c*/ 0, 0x4434, FILE_CHEADDARK_FROCK,  1,    1,                0, 0                          },
	{ /*0x000d*/ 0, 0x4434, FILE_CHEADSECRETARY,   1,    1,                0, 0                          },
	{ /*0x000e*/ 0, 0x5034, FILE_CHEADCASSANDRA,   1,    1,                0, 0                          },
	{ /*0x000f*/ 1, 0x4c6c, FILE_CHEADTHEKING,     1,    1,                0, 0                          },
	{ /*0x0010*/ 0, 0x4034, FILE_CHEADFEM_GUARD,   1,    1,                0, 0                          },
	{ /*0x0011*/ 1, 0x4034, FILE_CHEADJON,         1,    1,                0, 0                          },
	{ /*0x0012*/ 1, 0x4034, FILE_CHEADMARK2,       1,    1,                0, 0                          },
	{ /*0x0013*/ 1, 0x4034, FILE_CHEADCHRIST,      1,    1,                0, 0                          },
	{ /*0x0014*/ 1, 0x4034, FILE_CHEADRUSS,        1,    1,                0, 0                          },
	{ /*0x0015*/ 1, 0x4c34, FILE_CHEADGREY,        1,    1,                0, 0                          },
	{ /*0x0016*/ 1, 0x4034, FILE_CHEADDARLING,     1,    1,                0, 0                          },
	{ /*0x0017*/ 1, 0x4034, FILE_CHEADROBERT,      1,    1,                0, 0                          },
	{ /*0x0018*/ 1, 0x4034, FILE_CHEADBEAU,        1,    1,                0, 0                          },
	{ /*0x0019*/ 0, 0x4034, FILE_CHEADFEM_GUARD2,  1,    1,                0, 0                          },
	{ /*0x001a*/ 1, 0x4034, FILE_CHEADBRIAN,       1,    1,                0, 0                          },
	{ /*0x001b*/ 1, 0x4034, FILE_CHEADJAMIE,       1,    1,                0, 0                          },
	{ /*0x001c*/ 1, 0x4034, FILE_CHEADDUNCAN2,     1,    1,                0, 0                          },
	{ /*0x001d*/ 1, 0x4034, FILE_CHEADBIOTECH,     1,    1,                0, 0                          },
	{ /*0x001e*/ 1, 0x4034, FILE_CHEADNEIL2,       1,    1,                0, 0                          },
	{ /*0x001f*/ 1, 0x4034, FILE_CHEADEDMCG,       1,    1,                0, 0                          },
	{ /*0x0020*/ 0, 0x4434, FILE_CHEADANKA,        1,    1,                0, 0                          },
	{ /*0x0021*/ 0, 0x4434, FILE_CHEADLESLIE_S,    1,    1,                0, 0                          },
	{ /*0x0022*/ 1, 0x4034, FILE_CHEADMATT_C,      1,    1,                0, 0                          },
	{ /*0x0023*/ 1, 0x4034, FILE_CHEADPEER_S,      1,    1,                0, 0                          },
	{ /*0x0024*/ 0, 0x4434, FILE_CHEADEILEEN_T,    1,    1,                0, 0                          },
	{ /*0x0025*/ 1, 0x4034, FILE_CHEADANDY_R,      1,    1,                0, 0                          },
	{ /*0x0026*/ 1, 0x4034, FILE_CHEADBEN_R,       1,    1,                0, 0                          },
	{ /*0x0027*/ 1, 0x4034, FILE_CHEADSTEVE_K,     1,    1,                0, 0                          },
	{ /*0x0028*/ 1, 0x4034, FILE_CHEADJONATHAN,    1,    1,                0, 0                          },
	{ /*0x0029*/ 1, 0x4c6c, FILE_CHEADMAIAN_S,     1,    1,                0, 0                          },
	{ /*0x002a*/ 1, 0x4034, FILE_CHEADSHAUN,       1,    1,                0, 0                          },
	{ /*0x002b*/ 1, 0x4034, FILE_CHEADBEAU,        1,    1,                0, 0                          },
	{ /*0x002c*/ 0, 0x4434, FILE_CHEADEILEEN_H,    1,    1,                0, 0                          },
	{ /*0x002d*/ 1, 0x4034, FILE_CHEADSCOTT_H,     1,    1,                0, 0                          },
	{ /*0x002e*/ 1, 0x4034, FILE_CHEADSANCHEZ,     1,    1,                0, 0                          },
	{ /*0x002f*/ 0, 0x4434, FILE_CHEADDARKAQUA,    1,    1,                0, 0                          },
	{ /*0x0030*/ 1, 0x4034, FILE_CHEADDDSNIPER,    1,    1,                0, 0                          },
	{ /*0x0031*/ 1, 0x4034, FILE_CHEADBEAU,        1,    1,                0, 0                          },
	{ /*0x0032*/ 1, 0x4034, FILE_CHEADBEAU,        1,    1,                0, 0                          },
	{ /*0x0033*/ 1, 0x4034, FILE_CHEADBEAU,        1,    1,                0, 0                          },
	{ /*0x0034*/ 1, 0x4034, FILE_CHEADBEAU,        1,    1,                0, 0                          },
	{ /*0x0035*/ 1, 0x4034, FILE_CHEADGRIFFEY,     1,    1,                0, 0                          },
	{ /*0x0036*/ 1, 0x4034, FILE_CHEADMOTO,        1,    1,                0, 0                          },
	{ /*0x0037*/ 1, 0x4034, FILE_CHEADKEITH,       1,    1,                0, 0                          },
	{ /*0x0038*/ 0, 0x4434, FILE_CHEADWINNER,      1,    1,                0, 0                          },
	{ /*0x0039*/ 1, 0x4034, FILE_CA51FACEPLATE,    1,    1,                0, 0                          },
	{ /*0x003a*/ 1, 0x4c6c, FILE_CHEADELVIS_GOGS,  1,    1,                0, 0                          },
	{ /*0x003b*/ 1, 0x4034, FILE_CHEADSTEVEM,      1,    1,                0, 0                          },
	{ /*0x003c*/ 0, 0x4434, FILE_CHEADDARK_SNOW,   1,    1,                0, 0                          },
	{ /*0x003d*/ 1, 0x4034, FILE_CHEADPRESIDENT,   1,    1,                0, 0                          },
	{ /*0x003e*/ 0, 0x4434, FILE_CHEAD_VD,         1,    1,                0, 0                          },
	{ /*0x003f*/ 1, 0x4034, FILE_CHEADKEN,         1,    1,                0, 0                          },
	{ /*0x0040*/ 1, 0x4034, FILE_CHEADJOEL,        1,    1,                0, 0                          },
	{ /*0x0041*/ 1, 0x4034, FILE_CHEADTIM,         1,    1,                0, 0                          },
	{ /*0x0042*/ 1, 0x4034, FILE_CHEADGRANT,       1,    1,                0, 0                          },
	{ /*0x0043*/ 1, 0x4034, FILE_CHEADPENNY,       1,    1,                0, 0                          },
	{ /*0x0044*/ 1, 0x4034, FILE_CHEADROBIN,       1,    1,                0, 0                          },
	{ /*0x0045*/ 0, 0x4834, FILE_CHEADALEX,        1,    1,                0, 0                          },
	{ /*0x0046*/ 0, 0x4834, FILE_CHEADJULIANNE,    1,    1,                0, 0                          },
	{ /*0x0047*/ 0, 0x4834, FILE_CHEADLAURA,       1,    1,                0, 0                          },
	{ /*0x0048*/ 1, 0x4034, FILE_CHEADDAVEC,       1,    1,                0, 0                          },
	{ /*0x0049*/ 1, 0x4034, FILE_CHEADCOOK,        1,    1,                0, 0                          },
	{ /*0x004a*/ 1, 0x4034, FILE_CHEADPRYCE,       1,    1,                0, 0                          },
	{ /*0x004b*/ 1, 0x4034, FILE_CHEADSILKE,       1,    1,                0, 0                          },
	{ /*0x004c*/ 1, 0x4034, FILE_CHEADSMITH,       1,    1,                0, 0                          },
	{ /*0x004d*/ 1, 0x4034, FILE_CHEADGARETH,      1,    1,                0, 0                          },
	{ /*0x004e*/ 1, 0x4034, FILE_CHEADMURCHIE,     1,    1,                0, 0                          },
	{ /*0x004f*/ 1, 0x4034, FILE_CHEADWONG,        1,    1,                0, 0                          },
	{ /*0x0050*/ 1, 0x4034, FILE_CHEADCARTER,      1,    1,                0, 0                          },
	{ /*0x0051*/ 1, 0x4034, FILE_CHEADTINTIN,      1,    1,                0, 0                          },
	{ /*0x0052*/ 1, 0x4034, FILE_CHEADMUNTON,      1,    1,                0, 0                          },
	{ /*0x0053*/ 1, 0x4034, FILE_CHEADSTAMPER,     1,    1,                0, 0                          },
	{ /*0x0054*/ 1, 0x4034, FILE_CHEADJONES,       1,    1,                0, 0                          },
	{ /*0x0055*/ 1, 0x4034, FILE_CHEADPHELPS,      1,    1,                0, 0                          },
	{ /*0x0056*/ 0, 0x067c, FILE_CDARK_COMBAT,     1,    0.95305162668228, 0, FILE_GCOMBATHANDSLOD       },
	{ /*0x0057*/ 1, 0x0da8, FILE_CELVIS1,          1,    0.57276993989944, 0, FILE_GHAND_ELVIS           },
	{ /*0x0058*/ 1, 0xa274, FILE_CAREA51GUARD,     1,    0.92769956588745, 0, FILE_GHAND_A51GUARD        },
	{ /*0x0059*/ 1, 0x027c, FILE_COVERALL,         1,    0.92769956588745, 0, FILE_GHAND_A51GUARD        },
	{ /*0x005a*/ 1, 0x0268, FILE_CCARRINGTON,      1,    0.85915493965149, 0, FILE_GHAND_CARRINGTON      },
	{ /*0x005b*/ 1, 0x16a4, FILE_CMRBLONDE,        1,    1.1032863855362,  0, FILE_GHAND_MRBLONDE        },
	{ /*0x005c*/ 1, 0x227c, FILE_CSKEDAR,          1,    1,                0, 0                          },
	{ /*0x005d*/ 1, 0x0284, FILE_CTRENT,           1,    0.93896716833115, 0, FILE_GHAND_TRENT           },
	{ /*0x005e*/ 1, 0x2274, FILE_CDDSHOCK,         1,    0.93896716833115, 0, FILE_GHAND_DDFODDER        },
	{ /*0x005f*/ 1, 0x2274, FILE_CLABTECH,         1,    0.93896716833115, 0, FILE_GHAND_MRBLONDE        },
	{ /*0x0060*/ 1, 0x2278, FILE_CSTRIPES,         1,    0.92769956588745, 0, FILE_GHAND_BLACKGUARD      },
	{ /*0x0061*/ 0, 0x067c, FILE_CDARK_FROCK,      1,    0.95305162668228, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0062*/ 0, 0x067c, FILE_CDARK_TRENCH,     1,    0.95305162668228, 0, FILE_GHAND_JOTRENCH        },
	{ /*0x0063*/ 1, 0x0274, FILE_COFFICEWORKER,    1,    0.93896716833115, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0064*/ 1, 0x0274, FILE_COFFICEWORKER2,   1,    0.93896716833115, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0065*/ 0, 0x0630, FILE_CSECRETARY,       1,    0.87323945760727, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0066*/ 0, 0x129c, FILE_CCASSANDRA,       1,    0.98591554164886, 0, FILE_GHAND_VRIES           },
	{ /*0x0067*/ 1, 0x0da8, FILE_CTHEKING,         1,    0.57276993989944, 0, FILE_GHAND_ELVIS           },
	{ /*0x0068*/ 0, 0x2a80, FILE_CFEM_GUARD,       1,    0.96713620424271, 0, FILE_GHAND_JOTRENCH        },
	{ /*0x0069*/ 1, 0x2274, FILE_CDD_LABTECH,      1,    0.93896716833115, 0, FILE_GHAND_DDLABTECH       },
	{ /*0x006a*/ 1, 0x2280, FILE_CDD_SECGUARD,     1,    0.93427228927612, 0, FILE_GHAND_DDSECURITY      },
	{ /*0x006b*/ 1, 0x427c, FILE_CDRCARROLL,       1,    1,                0, 0                          },
	{ /*0x006c*/ 1, 0x027c, FILE_CEYESPY,          1,    1,                0, 0                          },
	{ /*0x006d*/ 0, 0x067c, FILE_CDARK_RIPPED,     1,    0.95305162668228, 0, FILE_GHAND_JOFROCK         },
	{ /*0x006e*/ 1, 0x2280, FILE_CDD_GUARD,        1,    0.93896716833115, 0, FILE_GHAND_DDSECURITY      },
	{ /*0x006f*/ 1, 0x2274, FILE_CDD_SHOCK_INF,    1,    0.93896716833115, 0, FILE_GHAND_DDSHOCK         },
	{ /*0x0070*/ 1, 0x427c, FILE_CTESTCHR,         1,    1,                0, 0                          },
	{ /*0x0071*/ 1, 0x226c, FILE_CBIOTECH,         1,    0.93896716833115, 0, FILE_GHAND_DDBIO           },
	{ /*0x0072*/ 1, 0x227c, FILE_CFBIGUY,          1,    0.93896716833115, 0, FILE_GHAND_FBIARM          },
	{ /*0x0073*/ 1, 0x227c, FILE_CCIAGUY,          1,    0.93896716833115, 0, FILE_GHAND_CIA             },
	{ /*0x0074*/ 1, 0x227c, FILE_CA51TROOPER,      1,    0.93896716833115, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0075*/ 1, 0x0274, FILE_CA51AIRMAN,       1,    0.93896716833115, 0, FILE_GHAND_A51AIRMAN       },
	{ /*0x0076*/ 1, 0x027c, FILE_CCHICROB,         1,    1,                0, 0                          },
	{ /*0x0077*/ 1, 0x0264, FILE_CSTEWARD,         1,    0.89201879501343, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0078*/ 0, 0x063c, FILE_CSTEWARDESS,      1,    0.85446006059647, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0079*/ 1, 0x027c, FILE_CPRESIDENT,       1,    0.93896716833115, 0, FILE_GHAND_PRESIDENT       },
	{ /*0x007a*/ 0, 0x063c, FILE_CSTEWARDESS_COAT, 1,    0.85446006059647, 0, FILE_GHAND_STEWARDESS_COAT },
	{ /*0x007b*/ 1, 0x027c, FILE_CMINISKEDAR,      0.75, 0.5,              0, 0                          },
	{ /*0x007c*/ 1, 0x027c, FILE_CNSA_LACKEY,      1,    0.93896716833115, 0, FILE_GHAND_CARRINGTON      },
	{ /*0x007d*/ 1, 0x027c, FILE_CPRES_SECURITY,   1,    0.93896716833115, 0, FILE_GHAND_CARRINGTON      },
	{ /*0x007e*/ 0, 0x0638, FILE_CNEGOTIATOR,      1,    0.85446006059647, 0, FILE_GHAND_JOFROCK         },
	{ /*0x007f*/ 1, 0x027c, FILE_CG5_GUARD,        1,    0.93896716833115, 0, FILE_GHAND_G5GUARD         },
	{ /*0x0080*/ 1, 0x227c, FILE_CPELAGIC_GUARD,   1,    0.93896716833115, 0, FILE_GHAND_TRAGIC_PELAGIC  },
	{ /*0x0081*/ 1, 0x2278, FILE_CG5_SWAT_GUARD,   1,    0.93896716833115, 0, FILE_GHAND_G5GUARD         },
	{ /*0x0082*/ 1, 0x2278, FILE_CALASKAN_GUARD,   1,    0.93896716833115, 0, FILE_GHAND_JOSNOW          },
	{ /*0x0083*/ 1, 0x2da8, FILE_CMAIAN_SOLDIER,   1,    0.57276993989944, 0, FILE_GHAND_ELVIS           },
	{ /*0x0084*/ 1, 0x027c, FILE_CPRESIDENT_CLONE, 1,    0.93896716833115, 0, FILE_GCOMBATHANDSLOD       },
	{ /*0x0085*/ 1, 0x027c, FILE_CPRESIDENT_CLONE, 1,    0.93896716833115, 0, FILE_GHAND_PRESIDENT       },
	{ /*0x0086*/ 0, 0x067c, FILE_CDARK_AF1,        1,    0.95305162668228, 0, FILE_GHAND_JOPILOT         },
	{ /*0x0087*/ 0, 0x067c, FILE_CDARKWET,         1,    0.95305162668228, 0, FILE_GHAND_JOWETSUIT       },
	{ /*0x0088*/ 0, 0x067c, FILE_CDARKAQUALUNG,    1,    0.95305162668228, 0, FILE_GHAND_JOWETSUIT       },
	{ /*0x0089*/ 0, 0x067c, FILE_CDARKSNOW,        1,    0.95305162668228, 0, FILE_GHAND_JOSNOW          },
	{ /*0x008a*/ 0, 0x067c, FILE_CDARKLAB,         1,    0.95305162668228, 0, FILE_GHAND_MRBLONDE        },
	{ /*0x008b*/ 0, 0x267c, FILE_CFEMLABTECH,      1,    0.87323945760727, 0, FILE_GHAND_MRBLONDE        },
	{ /*0x008c*/ 1, 0x227c, FILE_CDDSNIPER,        1,    0.93896716833115, 0, FILE_GHAND_DDSNIPER        },
	{ /*0x008d*/ 1, 0x027c, FILE_CPILOTAF1,        1,    0.88262909650803, 0, FILE_GHAND_JOPILOT         },
	{ /*0x008e*/ 1, 0x227c, FILE_CCILABTECH,       1,    0.93896716833115, 0, FILE_GHAND_CIFEMTECH       },
	{ /*0x008f*/ 0, 0x267c, FILE_CCIFEMTECH,       1,    0.86854463815689, 0, FILE_GHAND_CIFEMTECH       },
	{ /*0x0090*/ 1, 0x027c, FILE_CCARREVENINGSUIT, 1,    0.85915493965149, 0, FILE_GHAND_MRBLONDE        },
	{ /*0x0091*/ 1, 0x027c, FILE_CJONATHON,        1,    0.93896716833115, 0, FILE_GHAND_A51GUARD        },
	{ /*0x0092*/ 1, 0x227c, FILE_CCISOLDIER,       1,    0.93896716833115, 0, FILE_GHAND_CISOLDIER       },
	{ /*0x0093*/ 1, 0x027c, FILE_CSKEDARKING,      1,    1.25,             0, 0                          },
	{ /*0x0094*/ 1, 0x0da8, FILE_CELVISWAISTCOAT,  1,    0.57276993989944, 0, FILE_GHAND_ELVIS           },
	{ /*0x0095*/ 0, 0x067c, FILE_CDARK_LEATHER,    1,    0.95305162668228, 0, FILE_GHAND_JOFROCK         },
	{ /*0x0096*/ 0, 0x067c, FILE_CDARK_NEGOTIATOR, 1,    0.95305162668228, 0, FILE_GHAND_JOAF1           },
	{ /*0x0097*/ 0, 0x0000, 0,                     1,    0,                0, FILE_GCOMBATHANDSLOD       },
};

u32 var8007dae4 = 0xbd8ff972;
u32 var8007dae8 = 0x3efbda51;
u32 var8007daec = 0xbf5566cf;
u32 var8007daf0 = 0x3f8951e7;
u32 var8007daf4 = 0x3f8b4e44;
u32 var8007daf8 = 0x3f6d1644;
u32 var8007dafc = 0xbdcccccd;
u32 var8007db00 = 0x3edae148;
u32 var8007db04 = 0xbef70a3d;
u32 var8007db08 = 0x3f844567;
u32 var8007db0c = 0x3f772c62;
u32 var8007db10 = 0x3f6e0e41;
u32 var8007db14 = 0x3e3851ec;
u32 var8007db18 = 0x00000000;
u32 var8007db1c = 0x00000000;
u32 var8007db20 = 0x3f893e4f;
u32 var8007db24 = 0x3f800000;
u32 var8007db28 = 0x3f800000;
u32 var8007db2c = 0x3e72b021;
u32 var8007db30 = 0x3f7a1cac;
u32 var8007db34 = 0xbee147ae;
u32 var8007db38 = 0x3f96d7e0;
u32 var8007db3c = 0x3f91ff82;
u32 var8007db40 = 0x3f925d10;
u32 var8007db44 = 0xbdb8ef35;
u32 var8007db48 = 0x3e6d7732;
u32 var8007db4c = 0x3e016f00;
u32 var8007db50 = 0x3f7da512;
u32 var8007db54 = 0x3f828f5c;
u32 var8007db58 = 0x3f58bac7;
u32 var8007db5c = 0x00000000;
u32 var8007db60 = 0x3e181062;
u32 var8007db64 = 0x3ec2339c;
u32 var8007db68 = 0x3f93d07d;
u32 var8007db6c = 0x3f7ded29;
u32 var8007db70 = 0x3f738ef3;
u32 var8007db74 = 0x00000000;
u32 var8007db78 = 0x00000000;
u32 var8007db7c = 0x00000000;
f32 var8007db80 = 0;
f32 var8007db84 = 1;
u32 var8007db88 = 0x00000000;
u32 var8007db8c = 0x00000000;
u32 var8007db90 = 0x00000000;
u32 var8007db94 = 0x00000000;
u32 var8007db98 = 0x00000000;
u32 var8007db9c = 0x00000000;
u32 var8007dba0 = 0x00000010;
u32 var8007dba4 = 0x00000020;
u32 var8007dba8 = 0x0000000c;
u32 var8007dbac = 0x00000020;
u32 var8007dbb0 = 0x00000018;
u32 var8007dbb4 = 0x00000040;
u32 var8007dbb8 = 0x0000003c;
u32 var8007dbbc = 0x00000050;
u32 var8007dbc0 = 0x000000e1;
u32 var8007dbc4 = 0x00000113;
u32 var8007dbc8 = 0x000001d6;
u32 var8007dbcc = 0x0000023a;
u32 var8007dbd0 = 0xff99ffff;
u32 var8007dbd4 = 0x9999ffff;
u32 var8007dbd8 = 0x99ffffff;
u32 var8007dbdc = 0x99ff99ff;
u32 var8007dbe0 = 0xffff99ff;
u32 var8007dbe4 = 0xff9999ff;
u32 var8007dbe8 = 0x00000000;
u32 var8007dbec = 0x00000000;
u32 var8007dbf0 = 0x00000000;
u32 var8007dbf4 = 0x00000000;
u32 var8007dbf8 = 0x00000000;
u32 var8007dbfc = 0x3f800000;
u32 var8007dc00 = 0x00000000;
u32 var8007dc04 = 0x3f800000;
u32 var8007dc08 = 0x00000000;
u32 var8007dc0c = 0x00000000;
