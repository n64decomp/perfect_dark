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
	weapon(0x0200, 0x0000, PAD_REF_002F, OBJFLAG_00000001, 0, 0, 240)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0039, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_003A, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0200, 0x0000, PAD_REF_0030, OBJFLAG_00000001, 0, 0, 241)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_003B, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_003C, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0200, 0x0000, PAD_REF_0031, OBJFLAG_00000001, 0, 0, 242)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_003D, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_003E, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0133, 0x0000, PAD_REF_0032, OBJFLAG_00000001, 0, 0, 243)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_003F, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0040, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0133, 0x0000, PAD_REF_0033, OBJFLAG_00000001, 0, 0, 244)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0041, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0042, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0133, 0x0000, PAD_REF_0034, OBJFLAG_00000001, 0, 0, 245)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0043, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0044, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_REF_0035, OBJFLAG_00000001, 0, 0, 246)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0045, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0046, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_REF_0036, OBJFLAG_00000001, 0, 0, 247)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0047, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0048, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_REF_0037, OBJFLAG_00000001, 0, 0, 248)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0049, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_004A, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_REF_0038, OBJFLAG_00000001, 0, 0, 249)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_004B, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_004C, OBJFLAG_00000001, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, PAD_REF_004F, OBJFLAG_00000001 | OBJFLAG_00000100 | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, PAD_REF_0050, OBJFLAG_00000001 | OBJFLAG_00000100 | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, PAD_REF_0051, OBJFLAG_00000001 | OBJFLAG_00000100 | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, PAD_REF_004D, OBJFLAG_00000001 | OBJFLAG_00000100 | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, PAD_REF_004E, OBJFLAG_00000001 | OBJFLAG_00000100 | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	endprops
};

s32 intro[] = {
	spawn(PAD_REF_001C)
	spawn(PAD_REF_001D)
	spawn(PAD_REF_001E)
	spawn(PAD_REF_001F)
	spawn(PAD_REF_0020)
	spawn(PAD_REF_0021)
	spawn(PAD_REF_0022)
	spawn(PAD_REF_0023)
	spawn(PAD_REF_0024)
	spawn(PAD_REF_0025)
	spawn(PAD_REF_0026)
	spawn(PAD_REF_0027)
	spawn(PAD_REF_0028)
	spawn(PAD_REF_0029)
	spawn(PAD_REF_002A)
	spawn(PAD_REF_002B)
	spawn(PAD_REF_002C)
	spawn(PAD_REF_002D)
	spawn(PAD_REF_002E)
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




