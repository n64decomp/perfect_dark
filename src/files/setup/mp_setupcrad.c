//
// Pipes (MP)
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
	weapon(0x0100, 0x0000, PAD_CRAD_00E2, OBJFLAG_00000001, 0, 0, 240)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00EC, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00ED, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRAD_00E3, OBJFLAG_00000001, 0, 0, 241)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00EE, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00EF, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRAD_00E4, OBJFLAG_00000001, 0, 0, 242)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00F0, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00F1, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRAD_00E5, OBJFLAG_00000001, 0, 0, 243)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00F2, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00F3, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRAD_00E6, OBJFLAG_00000001, 0, 0, 244)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00F4, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00F5, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRAD_00E7, OBJFLAG_00000001, 0, 0, 245)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00F6, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00F7, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRAD_00E8, OBJFLAG_00000001, 0, 0, 246)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00F8, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00F9, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRAD_00E9, OBJFLAG_00000001, 0, 0, 247)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00FA, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00FB, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRAD_00EA, OBJFLAG_00000001, 0, 0, 248)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00FC, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00FD, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_CRAD_00EB, OBJFLAG_00000001, 0, 0, 249)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00FE, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, PAD_CRAD_00FF, OBJFLAG_00000001, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, PAD_CRAD_0100, OBJFLAG_00000001 | OBJFLAG_00000020 | OBJFLAG_00000040 | OBJFLAG_00000080 | OBJFLAG_00000100 | OBJFLAG_INVINCIBLE, 0, OBJFLAG3_PUSHABLE, 1000)
	tag(0x01, 1)
	lift(0x0100, MODEL_A51_LIFT_THINWALL, PAD_CRAD_0104, OBJFLAG_00000008 | OBJFLAG_00000020 | OBJFLAG_00000040 | OBJFLAG_00000080 | OBJFLAG_ILLUMINATED | OBJFLAG_INVINCIBLE | OBJFLAG_UNCOLLECTABLE | OBJFLAG_00400000 | OBJFLAG_01000000 | OBJFLAG_CANNOT_ACTIVATE | OBJFLAG_80000000, OBJFLAG2_00000100 | OBJFLAG2_00000200 | OBJFLAG2_IMMUNETOGUNFIRE | OBJFLAG2_00100000 | OBJFLAG2_00200000, 0, 1000, 0x0104, 0x0103, -1, -1, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000005b0, 0x00050000, 0x00000000)
	endprops
};

s32 intro[] = {
	spawn(PAD_CRAD_00CD)
	spawn(PAD_CRAD_00CE)
	spawn(PAD_CRAD_00CF)
	spawn(PAD_CRAD_00D0)
	spawn(PAD_CRAD_00D1)
	spawn(PAD_CRAD_00D2)
	spawn(PAD_CRAD_00D3)
	spawn(PAD_CRAD_00D4)
	spawn(PAD_CRAD_00D5)
	spawn(PAD_CRAD_00D6)
	spawn(PAD_CRAD_00D7)
	spawn(PAD_CRAD_00D8)
	spawn(PAD_CRAD_00D9)
	spawn(PAD_CRAD_00DA)
	spawn(PAD_CRAD_00DB)
	spawn(PAD_CRAD_00DC)
	spawn(PAD_CRAD_00DD)
	spawn(PAD_CRAD_00DE)
	spawn(PAD_CRAD_00DF)
	spawn(PAD_CRAD_00E0)
	spawn(PAD_CRAD_00E1)
	hill(0x0019)
	hill(0x009e)
	hill(0x0007)
	hill(0x001b)
	hill(0x001f)
	case(0, 0x00b7)
	case_respawn(0, 0x00b1)
	case_respawn(0, 0x00b2)
	case_respawn(0, 0x00b3)
	case_respawn(0, 0x00b4)
	case_respawn(0, 0x00b5)
	case_respawn(0, 0x00b6)
	case(1, 0x00be)
	case_respawn(1, 0x00b8)
	case_respawn(1, 0x00b9)
	case_respawn(1, 0x00ba)
	case_respawn(1, 0x00bb)
	case_respawn(1, 0x00bc)
	case_respawn(1, 0x00bd)
	case(2, 0x00c5)
	case_respawn(2, 0x00bf)
	case_respawn(2, 0x00c0)
	case_respawn(2, 0x00c1)
	case_respawn(2, 0x00c2)
	case_respawn(2, 0x00c3)
	case_respawn(2, 0x00c4)
	case(3, 0x00cc)
	case_respawn(3, 0x00c6)
	case_respawn(3, 0x00c7)
	case_respawn(3, 0x00c8)
	case_respawn(3, 0x00c9)
	case_respawn(3, 0x00ca)
	case_respawn(3, 0x00cb)
	endintro
};

struct path paths[] = {
	{ NULL, 0, 0 },
};

u8 func1001_start_lift[] = {
	activate_lift(1, 0x01)
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

u8 func1000_14e0[] = {
	mp_init_simulants
	rebuild_teams
	rebuild_squadrons
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

struct ailist ailists[] = {
	{ func1000_14e0,       0x1000 },
	{ func1001_start_lift, 0x1001 },
	{ NULL, 0 },
};





