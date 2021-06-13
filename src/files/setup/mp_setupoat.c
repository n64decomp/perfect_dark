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
	weapon(0x0200, 0x0000, PAD_OAT_00CD, OBJFLAG_00000001, 0, 0, 240)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00DC, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00DD, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0200, 0x0000, PAD_OAT_00CE, OBJFLAG_00000001, 0, 0, 241)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00DE, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00DF, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0200, 0x0000, PAD_OAT_00CF, OBJFLAG_00000001, 0, 0, 242)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00E0, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00E1, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0133, 0x0000, PAD_OAT_00D0, OBJFLAG_00000001, 0, 0, 243)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00E2, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00E3, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0133, 0x0000, PAD_OAT_00D1, OBJFLAG_00000001, 0, 0, 244)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00E4, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00E5, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0133, 0x0000, PAD_OAT_00D2, OBJFLAG_00000001, 0, 0, 245)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00E6, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00E7, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_OAT_00D3, OBJFLAG_00000001, 0, 0, 246)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00E8, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00E9, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_OAT_00D4, OBJFLAG_00000001, 0, 0, 247)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00EA, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00EB, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_OAT_00D5, OBJFLAG_00000001, 0, 0, 248)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00EC, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00ED, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_OAT_00D6, OBJFLAG_00000001, 0, 0, 249)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00EE, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00EF, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_OAT_00D7, OBJFLAG_00000001, 0, 0, 250)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00F0, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00F1, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_OAT_00D8, OBJFLAG_00000001, 0, 0, 251)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00F2, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00F3, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_OAT_00D9, OBJFLAG_00000001, 0, 0, 252)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00F4, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00F5, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_OAT_00DA, OBJFLAG_00000001, 0, 0, 253)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00F6, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00F7, OBJFLAG_00000001, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_OAT_00DB, OBJFLAG_00000001, 0, 0, 254)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00F8, OBJFLAG_00000001, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_OAT_00F9, OBJFLAG_00000001, 0, 0, 1000)
	endprops
};

s32 intro[] = {
	spawn(PAD_OAT_00A5)
	spawn(PAD_OAT_00A6)
	spawn(PAD_OAT_00A7)
	spawn(PAD_OAT_00A8)
	spawn(PAD_OAT_00A9)
	spawn(PAD_OAT_00AA)
	spawn(PAD_OAT_00AB)
	spawn(PAD_OAT_00AC)
	spawn(PAD_OAT_00AD)
	spawn(PAD_OAT_00AE)
	spawn(PAD_OAT_00AF)
	spawn(PAD_OAT_00B0)
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



