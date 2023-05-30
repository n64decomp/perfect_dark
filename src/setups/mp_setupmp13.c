//
// Villa (MP)
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
	weapon(0x0100, 0x0000, PAD_MP13_00BD, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION00)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00C7, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00C8, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00BE, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION01)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00C9, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00CA, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00BF, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION02)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00CB, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00CC, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00C0, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION03)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00CD, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00CE, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00C1, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION04)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00CF, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D0, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00C2, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION05)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D1, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D2, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00C3, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION06)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D3, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D4, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00C4, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION07)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D5, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D6, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00C5, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION08)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D7, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D8, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00C6, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION09)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D9, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00DA, OBJFLAG_FALL, 0, 0, 1000)
	endprops
};

s32 intro[] = {
	outfit(OUTFIT_DEFAULT)
	spawn(PAD_MP13_001C)
	spawn(PAD_MP13_001D)
	spawn(PAD_MP13_001E)
	spawn(PAD_MP13_001F)
	spawn(PAD_MP13_0020)
	spawn(PAD_MP13_0021)
	spawn(PAD_MP13_0022)
	spawn(PAD_MP13_0023)
	spawn(PAD_MP13_0024)
	spawn(PAD_MP13_0025)
	spawn(PAD_MP13_0026)
	spawn(PAD_MP13_0027)
	case(0, PAD_MP13_0006)
	case_respawn(0, PAD_MP13_0000)
	case_respawn(0, PAD_MP13_0001)
	case_respawn(0, PAD_MP13_0002)
	case_respawn(0, PAD_MP13_0003)
	case_respawn(0, PAD_MP13_0004)
	case_respawn(0, PAD_MP13_0005)
	case(1, PAD_MP13_000D)
	case_respawn(1, PAD_MP13_0007)
	case_respawn(1, PAD_MP13_0008)
	case_respawn(1, PAD_MP13_0009)
	case_respawn(1, PAD_MP13_000A)
	case_respawn(1, PAD_MP13_000B)
	case_respawn(1, PAD_MP13_000C)
	case(2, PAD_MP13_0013)
	case_respawn(2, PAD_MP13_000E)
	case_respawn(2, PAD_MP13_000F)
	case_respawn(2, PAD_MP13_0010)
	case_respawn(2, PAD_MP13_0011)
	case_respawn(2, PAD_MP13_0012)
	case_respawn(2, PAD_MP13_0014)
	case(3, PAD_MP13_001B)
	case_respawn(3, PAD_MP13_0015)
	case_respawn(3, PAD_MP13_0016)
	case_respawn(3, PAD_MP13_0017)
	case_respawn(3, PAD_MP13_0018)
	case_respawn(3, PAD_MP13_0019)
	case_respawn(3, PAD_MP13_001A)
	hill(PAD_MP13_004C)
	hill(PAD_MP13_008E)
	hill(PAD_MP13_00AA)
	hill(PAD_MP13_0043)
	endintro
};

struct path paths[] = {
	{ NULL, 0, 0 },
};

u8 func1000_1368[] = {
	mp_init_simulants
	rebuild_teams
	rebuild_squadrons
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

struct ailist ailists[] = {
	{ func1000_1368, 0x1000 },
	{ NULL, 0 },
};
