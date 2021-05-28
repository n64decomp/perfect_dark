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
	weapon(0x0100, 0x0000, 0x00e2, OBJFLAG_00000001, 0, 0, 240)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00ec, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00ed, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00e3, OBJFLAG_00000001, 0, 0, 241)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00ee, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00ef, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00e4, OBJFLAG_00000001, 0, 0, 242)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00f0, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00f1, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00e5, OBJFLAG_00000001, 0, 0, 243)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00f2, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00f3, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00e6, OBJFLAG_00000001, 0, 0, 244)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00f4, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00f5, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00e7, OBJFLAG_00000001, 0, 0, 245)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00f6, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00f7, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00e8, OBJFLAG_00000001, 0, 0, 246)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00f8, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00f9, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00e9, OBJFLAG_00000001, 0, 0, 247)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00fa, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00fb, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00ea, OBJFLAG_00000001, 0, 0, 248)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00fc, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00fd, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00eb, OBJFLAG_00000001, 0, 0, 249)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00fe, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0100, MODEL_MULTI_AMMO_CRATE, 0x00ff, OBJFLAG_00000001, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, 0x0100, OBJFLAG_00000001 | OBJFLAG_00000020 | OBJFLAG_00000040 | OBJFLAG_00000080 | OBJFLAG_00000100 | OBJFLAG_INVINCIBLE, 0, OBJFLAG3_PUSHABLE, 1000)
	tag(0x01, 1)
	lift(0x0100, MODEL_A51_LIFT_THINWALL, 0x0104, OBJFLAG_00000008 | OBJFLAG_00000020 | OBJFLAG_00000040 | OBJFLAG_00000080 | OBJFLAG_ILLUMINATED | OBJFLAG_INVINCIBLE | OBJFLAG_UNCOLLECTABLE | OBJFLAG_00400000 | OBJFLAG_01000000 | OBJFLAG_CANNOT_ACTIVATE | OBJFLAG_80000000, OBJFLAG2_00000100 | OBJFLAG2_00000200 | OBJFLAG2_IMMUNETOGUNFIRE | OBJFLAG2_00100000 | OBJFLAG2_00200000, 0, 1000, 0x0104, 0x0103, -1, -1, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000005b0, 0x00050000, 0x00000000)
	endprops
};

s32 intro[] = {
	spawn(0x00cd)
	spawn(0x00ce)
	spawn(0x00cf)
	spawn(0x00d0)
	spawn(0x00d1)
	spawn(0x00d2)
	spawn(0x00d3)
	spawn(0x00d4)
	spawn(0x00d5)
	spawn(0x00d6)
	spawn(0x00d7)
	spawn(0x00d8)
	spawn(0x00d9)
	spawn(0x00da)
	spawn(0x00db)
	spawn(0x00dc)
	spawn(0x00dd)
	spawn(0x00de)
	spawn(0x00df)
	spawn(0x00e0)
	spawn(0x00e1)
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





