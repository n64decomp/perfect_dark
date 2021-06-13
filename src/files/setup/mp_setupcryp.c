//
// G5 Building (MP)
//

#include "stagesetup.h"

s32 intro[];
u32 props[];
struct path paths[];
struct ailist ailists[];

struct stagesetup setup = {
	NULL,
	NULL,
	NULL,
	intro,
	props,
	paths,
	ailists,
	NULL,
};

u32 props[] = {
	weapon(0x0100, 0x0000, PAD_CRYP_00B2, OBJFLAG_00000001, 0, 0, 240)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00BC, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00BD, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00B3, OBJFLAG_00000001, 0, 0, 241)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00BE, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00BF, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00B4, OBJFLAG_00000001, 0, 0, 242)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C0, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C1, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00B5, OBJFLAG_00000001, 0, 0, 243)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C2, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C3, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00B6, OBJFLAG_00000001, 0, 0, 244)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C4, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C5, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00B7, OBJFLAG_00000001, 0, 0, 245)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C6, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C7, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00B8, OBJFLAG_00000001, 0, 0, 246)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C8, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C9, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00B9, OBJFLAG_00000001, 0, 0, 247)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00CA, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00CB, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00BA, OBJFLAG_00000001, 0, 0, 248)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00CC, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00CD, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00BB, OBJFLAG_00000001, 0, 0, 249)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00CE, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00CF, OBJFLAG_00000001, 0, 0, 1000)
	endprops
};

s32 intro[] = {
	spawn(PAD_CRYP_009D)
	spawn(PAD_CRYP_009E)
	spawn(PAD_CRYP_009F)
	spawn(PAD_CRYP_00A0)
	spawn(PAD_CRYP_00A1)
	spawn(PAD_CRYP_00A2)
	spawn(PAD_CRYP_00A3)
	spawn(PAD_CRYP_00A4)
	spawn(PAD_CRYP_00A5)
	spawn(PAD_CRYP_00A6)
	spawn(PAD_CRYP_00A7)
	spawn(PAD_CRYP_00A8)
	spawn(PAD_CRYP_00A9)
	spawn(PAD_CRYP_00AA)
	spawn(PAD_CRYP_00AB)
	spawn(PAD_CRYP_00AC)
	spawn(PAD_CRYP_00AD)
	spawn(PAD_CRYP_00AE)
	spawn(PAD_CRYP_00AF)
	spawn(PAD_CRYP_00B0)
	spawn(PAD_CRYP_00B1)
	case(0, 0x0087)
	case_respawn(0, 0x0081)
	case_respawn(0, 0x0082)
	case_respawn(0, 0x0083)
	case_respawn(0, 0x0084)
	case_respawn(0, 0x0085)
	case_respawn(0, 0x0086)
	case(1, 0x0088)
	case_respawn(1, 0x0089)
	case_respawn(1, 0x008a)
	case_respawn(1, 0x008b)
	case_respawn(1, 0x008c)
	case_respawn(1, 0x008d)
	case_respawn(1, 0x008e)
	case(2, 0x0095)
	case_respawn(2, 0x008f)
	case_respawn(2, 0x0090)
	case_respawn(2, 0x0091)
	case_respawn(2, 0x0092)
	case_respawn(2, 0x0093)
	case_respawn(2, 0x0094)
	case(3, 0x009c)
	case_respawn(3, 0x0096)
	case_respawn(3, 0x0097)
	case_respawn(3, 0x0098)
	case_respawn(3, 0x0099)
	case_respawn(3, 0x009a)
	case_respawn(3, 0x009b)
	hill(0x0033)
	hill(0x004d)
	hill(0x0056)
	hill(0x001a)
	hill(0x0066)
	endintro
};

struct path paths[] = {
	{ NULL, 0, 0 },
};

u8 func1001_13d4[] = {
	cmd01b2_mponly(11)
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

u8 func1000_13e0[] = {
	mp_init_simulants
	rebuild_teams
	rebuild_squadrons
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

struct ailist ailists[] = {
	{ func1000_13e0, 0x1000 },
	{ func1001_13d4, 0x1001 },
	{ NULL, 0 },
};



