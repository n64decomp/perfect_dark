//
// Complex (MP)
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
	weapon(0x0200, 0x0000, PAD_REF_002F, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION00)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0039, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_003A, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0200, 0x0000, PAD_REF_0030, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION01)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_003B, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_003C, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0200, 0x0000, PAD_REF_0031, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION02)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_003D, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_003E, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0133, 0x0000, PAD_REF_0032, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION03)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_003F, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0040, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0133, 0x0000, PAD_REF_0033, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION04)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0041, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0042, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0133, 0x0000, PAD_REF_0034, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION05)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0043, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0044, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_REF_0035, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION06)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0045, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0046, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_REF_0036, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION07)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0047, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0048, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_REF_0037, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION08)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_0049, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_004A, OBJFLAG_FALL, 0, 0, 1000)
	weapon(0x0100, 0x0000, PAD_REF_0038, OBJFLAG_FALL, 0, 0, WEAPON_MPLOCATION09)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_004B, OBJFLAG_FALL, 0, 0, 1000)
	ammocratemulti(0x0099, MODEL_MULTI_AMMO_CRATE, PAD_REF_004C, OBJFLAG_FALL, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, PAD_REF_004F, OBJFLAG_FALL | OBJFLAG_CORE_GEO_INUSE | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, PAD_REF_0050, OBJFLAG_FALL | OBJFLAG_CORE_GEO_INUSE | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, PAD_REF_0051, OBJFLAG_FALL | OBJFLAG_CORE_GEO_INUSE | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, PAD_REF_004D, OBJFLAG_FALL | OBJFLAG_CORE_GEO_INUSE | OBJFLAG_INVINCIBLE, 0, 0, 1000)
	stdobject(0x0100, MODEL_A51_CRATE2, PAD_REF_004E, OBJFLAG_FALL | OBJFLAG_CORE_GEO_INUSE | OBJFLAG_INVINCIBLE, 0, 0, 1000)
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
	case(0, PAD_REF_0006)
	case_respawn(0, PAD_REF_0000)
	case_respawn(0, PAD_REF_0001)
	case_respawn(0, PAD_REF_0002)
	case_respawn(0, PAD_REF_0003)
	case_respawn(0, PAD_REF_0004)
	case_respawn(0, PAD_REF_0005)
	case(1, PAD_REF_000D)
	case_respawn(1, PAD_REF_0007)
	case_respawn(1, PAD_REF_0008)
	case_respawn(1, PAD_REF_0009)
	case_respawn(1, PAD_REF_000A)
	case_respawn(1, PAD_REF_000B)
	case_respawn(1, PAD_REF_000C)
	case(2, PAD_REF_0014)
	case_respawn(2, PAD_REF_000E)
	case_respawn(2, PAD_REF_000F)
	case_respawn(2, PAD_REF_0010)
	case_respawn(2, PAD_REF_0011)
	case_respawn(2, PAD_REF_0012)
	case_respawn(2, PAD_REF_0013)
	case(3, PAD_REF_001B)
	case_respawn(3, PAD_REF_0015)
	case_respawn(3, PAD_REF_0016)
	case_respawn(3, PAD_REF_0017)
	case_respawn(3, PAD_REF_0018)
	case_respawn(3, PAD_REF_0019)
	case_respawn(3, PAD_REF_001A)
	hill(PAD_REF_0067)
	hill(PAD_REF_007B)
	hill(PAD_REF_00D5)
	hill(PAD_REF_0092)
	hill(PAD_REF_008B)
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
