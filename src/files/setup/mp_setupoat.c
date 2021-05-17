//
// Skedar (MP)
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
	weapon(0x0200, 0x0000, 0x00cd, OBJFLAG_00000001, 0, 0, 240)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00dc, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00dd, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0200, 0x0000, 0x00ce, OBJFLAG_00000001, 0, 0, 241)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00de, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00df, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0200, 0x0000, 0x00cf, OBJFLAG_00000001, 0, 0, 242)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00e0, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00e1, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0133, 0x0000, 0x00d0, OBJFLAG_00000001, 0, 0, 243)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00e2, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00e3, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0133, 0x0000, 0x00d1, OBJFLAG_00000001, 0, 0, 244)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00e4, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00e5, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0133, 0x0000, 0x00d2, OBJFLAG_00000001, 0, 0, 245)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00e6, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00e7, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00d3, OBJFLAG_00000001, 0, 0, 246)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00e8, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00e9, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00d4, OBJFLAG_00000001, 0, 0, 247)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00ea, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00eb, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00d5, OBJFLAG_00000001, 0, 0, 248)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00ec, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00ed, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00d6, OBJFLAG_00000001, 0, 0, 249)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00ee, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00ef, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00d7, OBJFLAG_00000001, 0, 0, 250)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00f0, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00f1, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00d8, OBJFLAG_00000001, 0, 0, 251)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00f2, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00f3, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00d9, OBJFLAG_00000001, 0, 0, 252)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00f4, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00f5, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00da, OBJFLAG_00000001, 0, 0, 253)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00f6, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00f7, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, 0x00db, OBJFLAG_00000001, 0, 0, 254)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00f8, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, 0x00f9, OBJFLAG_00000001, 0, 0, 1000)
	endprops
};

s32 intro[] = {
	spawn(0x00a5)
	spawn(0x00a6)
	spawn(0x00a7)
	spawn(0x00a8)
	spawn(0x00a9)
	spawn(0x00aa)
	spawn(0x00ab)
	spawn(0x00ac)
	spawn(0x00ad)
	spawn(0x00ae)
	spawn(0x00af)
	spawn(0x00b0)
	case(0, 0x00b1)
	case_respawn(0, 0x00b2)
	case_respawn(0, 0x00b3)
	case_respawn(0, 0x00b4)
	case_respawn(0, 0x00b5)
	case_respawn(0, 0x00b6)
	case_respawn(0, 0x00b7)
	case(1, 0x00b8)
	case_respawn(1, 0x00b9)
	case_respawn(1, 0x00ba)
	case_respawn(1, 0x00bb)
	case_respawn(1, 0x00bc)
	case_respawn(1, 0x00bd)
	case_respawn(1, 0x00be)
	case(2, 0x00bf)
	case_respawn(2, 0x00c0)
	case_respawn(2, 0x00c1)
	case_respawn(2, 0x00c2)
	case_respawn(2, 0x00c3)
	case_respawn(2, 0x00c4)
	case_respawn(2, 0x00c5)
	case(3, 0x00c6)
	case_respawn(3, 0x00c7)
	case_respawn(3, 0x00c8)
	case_respawn(3, 0x00c9)
	case_respawn(3, 0x00ca)
	case_respawn(3, 0x00cb)
	case_respawn(3, 0x00cc)
	hill(0x0093)
	hill(0x00d5)
	hill(0x008d)
	hill(0x00da)
	hill(0x0076)
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

u8 func1000_1c08[] = {
	mp_init_simulants
	rebuild_teams
	rebuild_squadrons
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

struct ailist ailists[] = {
	{ func1000_1c08, 0x1000 },
	{ NULL, 0 },
};



