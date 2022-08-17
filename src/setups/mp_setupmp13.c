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
	weapon(0x0100, 0x0000, PAD_MP13_00BD, OBJFLAG_00000001, 0, 0, 240)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00C7, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00C8, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00BE, OBJFLAG_00000001, 0, 0, 241)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00C9, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00CA, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00BF, OBJFLAG_00000001, 0, 0, 242)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00CB, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00CC, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00C0, OBJFLAG_00000001, 0, 0, 243)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00CD, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00CE, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00C1, OBJFLAG_00000001, 0, 0, 244)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00CF, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D0, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00C2, OBJFLAG_00000001, 0, 0, 245)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D1, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D2, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00C3, OBJFLAG_00000001, 0, 0, 246)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D3, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D4, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00C4, OBJFLAG_00000001, 0, 0, 247)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D5, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D6, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00C5, OBJFLAG_00000001, 0, 0, 248)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D7, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D8, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_MP13_00C6, OBJFLAG_00000001, 0, 0, 249)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00D9, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_MP13_00DA, OBJFLAG_00000001, 0, 0, 1000)
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



