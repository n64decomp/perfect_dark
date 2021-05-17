//
// Complex (MP)
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
	weapon(0x0200, 0x0000, 0x002f, OBJFLAG_00000001, 0, 0, 240)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x0039, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x003a, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0200, 0x0000, 0x0030, OBJFLAG_00000001, 0, 0, 241)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x003b, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x003c, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0200, 0x0000, 0x0031, OBJFLAG_00000001, 0, 0, 242)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x003d, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x003e, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0133, 0x0000, 0x0032, OBJFLAG_00000001, 0, 0, 243)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x003f, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x0040, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0133, 0x0000, 0x0033, OBJFLAG_00000001, 0, 0, 244)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x0041, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x0042, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0133, 0x0000, 0x0034, OBJFLAG_00000001, 0, 0, 245)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x0043, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x0044, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x0035, OBJFLAG_00000001, 0, 0, 246)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x0045, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x0046, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x0036, OBJFLAG_00000001, 0, 0, 247)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x0047, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x0048, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x0037, OBJFLAG_00000001, 0, 0, 248)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x0049, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x004a, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x0038, OBJFLAG_00000001, 0, 0, 249)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x004b, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x004c, OBJFLAG_00000001, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, 0x004f, OBJFLAG_00000001 | OBJFLAG_00000100 | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, 0x0050, OBJFLAG_00000001 | OBJFLAG_00000100 | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, 0x0051, OBJFLAG_00000001 | OBJFLAG_00000100 | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, 0x004d, OBJFLAG_00000001 | OBJFLAG_00000100 | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, 0x004e, OBJFLAG_00000001 | OBJFLAG_00000100 | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	endprops
};

s32 intro[] = {
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
	spawn(0x0028)
	spawn(0x0029)
	spawn(0x002a)
	spawn(0x002b)
	spawn(0x002c)
	spawn(0x002d)
	spawn(0x002e)
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
	case(2, 0x0014)
	case_respawn(2, 0x000e)
	case_respawn(2, 0x000f)
	case_respawn(2, 0x0010)
	case_respawn(2, 0x0011)
	case_respawn(2, 0x0012)
	case_respawn(2, 0x0013)
	case(3, 0x001b)
	case_respawn(3, 0x0015)
	case_respawn(3, 0x0016)
	case_respawn(3, 0x0017)
	case_respawn(3, 0x0018)
	case_respawn(3, 0x0019)
	case_respawn(3, 0x001a)
	hill(0x0067)
	hill(0x007b)
	hill(0x00d5)
	hill(0x0092)
	hill(0x008b)
	outfit(OUTFIT_DEFAULT)
	endintro
};

s32 path00[] = {
	-1,
};

struct path paths[] = {
	{ NULL, 0, 0 },
};

u8 unregistered_func1[] = {
	endlist
};

u8 func1000_1598[] = {
	mp_init_simulants
	rebuild_teams
	rebuild_squadrons
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

struct ailist ailists[] = {
	{ func1000_1598, 0x1000 },
	{ NULL, 0 },
};




