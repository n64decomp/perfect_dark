//
// G5 Building (MP)
//

#include "stagesetup.h"

extern s32 intro[];
extern u32 props[];
extern struct path paths[];
extern struct ailist ailists[];

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
	weapon(0x0100, 0x0000, PAD_CRYP_00B2, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION00)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00BC, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00BD, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00B3, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION01)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00BE, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00BF, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00B4, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION02)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C0, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C1, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00B5, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION03)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C2, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C3, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00B6, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION04)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C4, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C5, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00B7, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION05)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C6, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C7, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00B8, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION06)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C8, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00C9, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00B9, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION07)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00CA, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00CB, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00BA, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION08)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00CC, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00CD, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRYP_00BB, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION09)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00CE, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x00cc, MODEL_MULTI_AMMO_CRATE, PAD_CRYP_00CF, OBJFLAG_FALL, 0, 0, 1000)
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
	case(0, PAD_CRYP_0087)
	case_respawn(0, PAD_CRYP_0081)
	case_respawn(0, PAD_CRYP_0082)
	case_respawn(0, PAD_CRYP_0083)
	case_respawn(0, PAD_CRYP_0084)
	case_respawn(0, PAD_CRYP_0085)
	case_respawn(0, PAD_CRYP_0086)
	case(1, PAD_CRYP_0088)
	case_respawn(1, PAD_CRYP_0089)
	case_respawn(1, PAD_CRYP_008A)
	case_respawn(1, PAD_CRYP_008B)
	case_respawn(1, PAD_CRYP_008C)
	case_respawn(1, PAD_CRYP_008D)
	case_respawn(1, PAD_CRYP_008E)
	case(2, PAD_CRYP_0095)
	case_respawn(2, PAD_CRYP_008F)
	case_respawn(2, PAD_CRYP_0090)
	case_respawn(2, PAD_CRYP_0091)
	case_respawn(2, PAD_CRYP_0092)
	case_respawn(2, PAD_CRYP_0093)
	case_respawn(2, PAD_CRYP_0094)
	case(3, PAD_CRYP_009C)
	case_respawn(3, PAD_CRYP_0096)
	case_respawn(3, PAD_CRYP_0097)
	case_respawn(3, PAD_CRYP_0098)
	case_respawn(3, PAD_CRYP_0099)
	case_respawn(3, PAD_CRYP_009A)
	case_respawn(3, PAD_CRYP_009B)
	hill(PAD_CRYP_0033)
	hill(PAD_CRYP_004D)
	hill(PAD_CRYP_0056)
	hill(PAD_CRYP_001A)
	hill(PAD_CRYP_0066)
	endintro
};

struct path paths[] = {
	{ NULL, 0, 0 },
};

u8 func1001_13d4[] = {
	set_wind_speed(11)
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
