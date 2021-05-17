//
// Villa (MP)
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
	weapon(0x0100, 0x0000, 0x00bd, OBJFLAG_00000001, 0, 0, 240)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00c7, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00c8, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00be, OBJFLAG_00000001, 0, 0, 241)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00c9, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00ca, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00bf, OBJFLAG_00000001, 0, 0, 242)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00cb, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00cc, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00c0, OBJFLAG_00000001, 0, 0, 243)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00cd, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00ce, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00c1, OBJFLAG_00000001, 0, 0, 244)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00cf, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00d0, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00c2, OBJFLAG_00000001, 0, 0, 245)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00d1, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00d2, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00c3, OBJFLAG_00000001, 0, 0, 246)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00d3, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00d4, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00c4, OBJFLAG_00000001, 0, 0, 247)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00d5, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00d6, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00c5, OBJFLAG_00000001, 0, 0, 248)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00d7, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00d8, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00c6, OBJFLAG_00000001, 0, 0, 249)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00d9, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00da, OBJFLAG_00000001, 0, 0, 1000)
	endprops
};

s32 intro[] = {
	outfit(OUTFIT_DEFAULT)
	spawn(0x001c)
	spawn(0x001d)
	spawn(0x001e)
	spawn(0x001f)
	spawn(0x0020)
	spawn(0x0021)
	spawn(0x0022)
	spawn(0x0023)
	spawn(0x0024)
	spawn(0x0025)
	spawn(0x0026)
	spawn(0x0027)
	case(0, 0x0006)
	case_respawn(0, 0x0000)
	case_respawn(0, 0x0001)
	case_respawn(0, 0x0002)
	case_respawn(0, 0x0003)
	case_respawn(0, 0x0004)
	case_respawn(0, 0x0005)
	case(1, 0x000d)
	case_respawn(1, 0x0007)
	case_respawn(1, 0x0008)
	case_respawn(1, 0x0009)
	case_respawn(1, 0x000a)
	case_respawn(1, 0x000b)
	case_respawn(1, 0x000c)
	case(2, 0x0013)
	case_respawn(2, 0x000e)
	case_respawn(2, 0x000f)
	case_respawn(2, 0x0010)
	case_respawn(2, 0x0011)
	case_respawn(2, 0x0012)
	case_respawn(2, 0x0014)
	case(3, 0x001b)
	case_respawn(3, 0x0015)
	case_respawn(3, 0x0016)
	case_respawn(3, 0x0017)
	case_respawn(3, 0x0018)
	case_respawn(3, 0x0019)
	case_respawn(3, 0x001a)
	hill(0x004c)
	hill(0x008e)
	hill(0x00aa)
	hill(0x0043)
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



