#include <ultra64.h>
#include "game/chr/chraicommands.h"
#include "game/game_000000.h"
#include "game/prop.h"
#include "game/inventory/items.h"
#include "stagesetup.h"
#include "data.h"
#include "types.h"

struct inventory_menupos invmenupos_00010fd0 = {
	0, 0, 0, 1, 6,
};

struct inventory_menupos invmenupos_00010fe4 = {
	0, 3, 1.4, 1, 6,
};

struct inventory_menupos invmenupos_00010ff8 = {
	0, 9, 2, 1, 6,
};

struct inventory_menupos invmenupos_0001100c = {
	0, 14, 2, 1, 6,
};

struct inventory_menupos invmenupos_00011020 = {
	0, 18, 2, 1, 6,
};

struct inventory_menupos invmenupos_00011034 = {
	0, 22, 3, 1, 6,
};

struct inventory_menupos invmenupos_00011048 = {
	0, 25, 15, 5, 6,
};

struct inventory_menupos invmenupos_0001105c = {
	0, 35, 1, 1, 6,
};

struct inventory_menupos invmenupos_00011070 = {
	0, 0, 0, 0.2, 2.3509887016446E-38,
};

struct inventory_menupos invmenupos_00011084 = {
	0.2, 0.2, 0.2, 0.2, 2.3509887016446E-38,
};

struct inventory_menupos invmenupos_00011098 = {
	0.6, 0.6, 0.6, 0.2, 2.3509887016446E-38,
};

struct inventory_menupos invmenupos_000110ac = {
	0.6, 0.6, 2.6, 0.2, 2.3509887016446E-38,
};

struct inventory_class invclass_default = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x10000000,
	WEAPONCLASSFLAG_AUTOAIM,
};

struct inventory_class invclass_smg = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x10000000,
	WEAPONCLASSFLAG_AUTOAIM | WEAPONCLASSFLAG_00000004,
};

struct inventory_class invclass_unarmed = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x07000000,
	WEAPONCLASSFLAG_AUTOAIM,
};

struct inventory_class invclass_falcon2scope = {
	30,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x15000000,
	WEAPONCLASSFLAG_AUTOAIM,
};

struct inventory_class invclass_heavy = {
	30,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x15000000,
	WEAPONCLASSFLAG_AUTOAIM | WEAPONCLASSFLAG_00000004,
};

struct weaponfunc_shootsingle invfunc_00011160 = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_085, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	1, // damage
	6, // spread
	6, 18, 2, 8,
	5,
	2,
	0,
	4,
	4,
	0x8039,
	1,
};

struct inventory_ammo invammo_default = {
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	NULL, // reload animation
	0, // flags
};

struct weapon invitem_hammer = {
	0, // hi model
	0, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	&invammo_default, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	12.5, // left/right
	-17, // up/down
	-27.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_000, // short name
	L_GUN_000, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_DUALWIELD,
};

struct weapon invitem_nothing = {
	0, // hi model
	0, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	12.5, // left/right
	-17, // up/down
	-27.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_000, // short name
	L_GUN_000, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_DUALWIELD,
};

struct guncmd invanim_punch_type3[] = {
	gunscript_playanimation(0x03e9, 0, 10000)
	gunscript_waittime(7, 2)
	gunscript_end
};

struct guncmd invanim_punch_type1[] = {
	gunscript_playanimation(0x03ea, 0, 10000)
	gunscript_waittime(8, 2)
	gunscript_end
};

struct guncmd invanim_punch_type2[] = {
	gunscript_playanimation(0x041f, 0, 10000)
	gunscript_waittime(7, 2)
	gunscript_end
};

struct guncmd invanim_punch_type4[] = {
	gunscript_playanimation(0x0425, 0, 10000)
	gunscript_waittime(8, 2)
	gunscript_waittime(18, 3)
	gunscript_end
};

struct guncmd invanim_punch[] = {
	gunscript_random(20, invanim_punch_type1)
	gunscript_random(40, invanim_punch_type2)
	gunscript_random(60, invanim_punch_type3)
	gunscript_include(0, invanim_punch_type4)
	gunscript_end
};

struct weaponfunc_close invfunc_unarmed_punch = {
	INVENTORYFUNCTYPE_CLOSE,
	L_GUN_100, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_punch, // fire animation
	FUNCFLAG_MAKEDIZZY | FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_LESSDAMAGE | FUNCFLAG_NOSTUN | FUNCFLAG_00400000,
	0.5, // damage
	60,
	0x00000069,
	0x00000069,
	0x00000069,
	0x40f00000,
	0xc20c0000,
	0x40f00000,
	0xc20c0000,
	0xbf800000,
	0xbf800000,
	0x40000000,
	0x40000000,
	0x00000000,
};

struct weaponfunc_close invfunc_unarmed_disarm = {
	INVENTORYFUNCTYPE_CLOSE,
	L_GUN_101, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_punch, // fire animation
	FUNCFLAG_MAKEDIZZY | FUNCFLAG_DROPWEAPON | FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_LESSDAMAGE | FUNCFLAG_NOSTUN | FUNCFLAG_00400000,
	0.3, // damage
	60,
	0x00000069,
	0x00000069,
	0x00000069,
	0x40f00000,
	0xc20c0000,
	0x40f00000,
	0xc20c0000,
	0xbf800000,
	0xbf800000,
	0x40000000,
	0x40000000,
	0x00000000,
};

struct weapon invitem_unarmed = {
	FILE_GCOMBATHANDSLOD, // hi model
	FILE_GCOMBATHANDSLOD, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{&invfunc_unarmed_punch, &invfunc_unarmed_disarm}, // functions
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_unarmed,
	1, // sway
	7.5, // left/right
	-41, // up/down
	-16, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_006, // short name
	L_GUN_006, // name
	L_GUN_000, // manufacturer
	L_GUN_155, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00002000 | WEAPONFLAG_HIDEMENUMODEL | WEAPONFLAG_08000000,
};

struct modelpartvisibility invpartvisibility_falcon2[] = {
	{ MODELPART_MUZZLEFLASH, false },
	{ MODELPART_NEWCLIP3,    false },
	{ MODELPART_NEWCLIP4,    false },
	{ MODELPART_SCOPE,       false },
	{ MODELPART_SILENCER,    false },
	{ MODELPART_2E,          false },
	{ MODELPART_2F,          false },
	{ 255 },
};

struct modelpartvisibility invpartvisibility_falcon2scope[] = {
	{ MODELPART_MUZZLEFLASH, false },
	{ MODELPART_NEWCLIP3,    false },
	{ MODELPART_NEWCLIP4,    false },
	{ MODELPART_SILENCER,    false },
	{ MODELPART_2F,          false },
	{ 255 },
};

struct modelpartvisibility invpartvisibility_falcon2silencer[] = {
	{ MODELPART_MUZZLEFLASH, false },
	{ MODELPART_NEWCLIP3,    false },
	{ MODELPART_NEWCLIP4,    false },
	{ MODELPART_SCOPE,       false },
	{ MODELPART_2E,          false },
	{ 255 },
};

struct inventory_typef invf_000113f4[] = {
	{ 0x0100, 0x0000, 0x0100, 0x002a, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002b, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002c, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002d, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002e, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002f, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct inventory_typef invf_00011444[] = {
	{ 0x0100, 0x0000, 0x0100, 0x002a, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002b, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002d, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002e, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002f, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct inventory_typef invf_0001148c[] = {
	{ 0x0100, 0x0000, 0x0100, 0x002a, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002b, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002c, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002e, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002f, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_falcon2_reload_0[] = {
	gunscript_playanimation(0x00ed, 0, 10000)
	gunscript_showpart(1, 53)
	gunscript_showpart(1, 43)
	gunscript_showpart(1, 42)
	gunscript_playsound(10, 0x01d8)
	gunscript_hidepart(19, 42)
	gunscript_waittime(24, 1)
	gunscript_playsound(24, 0x80f6)
	gunscript_hidepart(24, 43)
	gunscript_playsound(53, 0x01db)
	gunscript_waittime(53, 3)
	gunscript_end
};

struct guncmd invanim_falcon2scope_reload_0[] = {
	gunscript_playanimation(0x0417, 0, 10000)
	gunscript_showpart(1, 53)
	gunscript_showpart(1, 43)
	gunscript_showpart(1, 42)
	gunscript_playsound(10, 0x01d8)
	gunscript_hidepart(19, 42)
	gunscript_waittime(24, 1)
	gunscript_playsound(24, 0x80f6)
	gunscript_hidepart(24, 43)
	gunscript_playsound(53, 0x01db)
	gunscript_waittime(53, 3)
	gunscript_end
};

struct guncmd invanim_falcon2_reload_1[] = {
	gunscript_playanimation(0x03f1, 0, 10000)
	gunscript_hidepart(1, 43)
	gunscript_showpart(1, 42)
	gunscript_playsound(6, 0x01d8)
	gunscript_waittime(50, 1)
	gunscript_playsound(50, 0x80f6)
	gunscript_playsound(71, 0x01db)
	gunscript_end
};

struct guncmd invanim_falcon2_reload[] = {
	gunscript_include(1, invanim_falcon2_reload_1)
	gunscript_include(0, invanim_falcon2_reload_0)
	gunscript_end
};

struct guncmd invanim_falcon2scope_reload[] = {
	gunscript_include(1, invanim_falcon2_reload_1)
	gunscript_include(0, invanim_falcon2scope_reload_0)
	gunscript_end
};

struct guncmd invanim_falcon2_pistolwhip[] = {
	gunscript_playanimation(0x03f2, 0, 10000)
	gunscript_waittime(23, 2)
	gunscript_end
};

struct guncmd invanim_falcon2_equip[] = {
	gunscript_playanimation(0x00ea, 0, 10000)
	gunscript_end
};

struct guncmd invanim_falcon2_unequip[] = {
	gunscript_playanimation(0x00eb, 0, 10000)
	gunscript_end
};

struct guncmd invanim_falcon2_shoot[] = {
	gunscript_playanimation(0x00ec, 0, 10000)
	gunscript_waittime(9, 5)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_falcon2_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_085, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_falcon2_shoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	16,
	1, // damage
	1, // spread
	3, 5, 2, 0,
	10,
	15,
	59.999996185303,
	0,
	0,
	0x804d,
	1,
};

struct weaponfunc_shootsingle invfunc_falcon2silenced_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_085, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_falcon2_shoot, // fire animation
	FUNCFLAG_NOMUZZLEFLASH,
	&invmenupos_00011098,
	16,
	1, // damage
	1, // spread
	3, 5, 2, 0,
	10,
	15,
	59.999996185303,
	0,
	0,
	0x8054,
	1,
};

struct weaponfunc_close invfunc_falcon2_pistolwhip = {
	INVENTORYFUNCTYPE_CLOSE,
	L_GUN_094, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_falcon2_pistolwhip, // fire animation
	FUNCFLAG_MAKEDIZZY | FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_LESSDAMAGE | FUNCFLAG_NOSTUN | FUNCFLAG_00400000,
	0.9, // damage
	60,
	0x00000069,
	0x00000069,
	0x00000069,
	0xc1800000,
	0x3f4ccccd,
	0x41bc0000,
	0xc202cccd,
	0xbf800000,
	0xbf800000,
	0x40000000,
	0x40000000,
	0x00000000,
};

struct inventory_ammo invammo_falcon2 = {
	AMMOTYPE_PISTOL,
	CASING_STANDARD,
	8, // clip size
	invanim_falcon2_reload, // reload animation
	0, // flags
};

struct inventory_ammo invammo_falcon2scope = {
	AMMOTYPE_PISTOL,
	CASING_STANDARD,
	8, // clip size
	invanim_falcon2scope_reload, // reload animation
	0, // flags
};

struct weapon invitem_falcon2 = {
	FILE_GFALCON2, // hi model
	FILE_GFALCON2LOD, // lo model
	invanim_falcon2_equip, // equip animation
	invanim_falcon2_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_falcon2_singleshot, &invfunc_falcon2_pistolwhip }, // functions
	&invammo_falcon2, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	2, // sway
	9, // left/right
	-15.7, // up/down
	-23.8, // front/back
	1, // unk38
	invf_000113f4, // fptr
	invpartvisibility_falcon2, // part visibility
	L_GUN_007, // short name
	L_GUN_007, // name
	L_GUN_150, // manufacturer
	L_GUN_156, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00002000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_GANGSTA,
};

struct weapon invitem_falcon2scope = {
	FILE_GFALCON2, // hi model
	FILE_GFALCON2LOD, // lo model
	invanim_falcon2_equip, // equip animation
	invanim_falcon2_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_falcon2_singleshot, &invfunc_falcon2_pistolwhip }, // functions
	&invammo_falcon2scope, // pri ammo
	NULL, // sec ammo
	&invclass_falcon2scope,
	1, // sway
	9, // left/right
	-15.7, // up/down
	-23.8, // front/back
	1, // unk38
	invf_00011444, // fptr
	invpartvisibility_falcon2scope, // part visibility
	L_GUN_077, // short name
	L_GUN_009, // name
	L_GUN_150, // manufacturer
	L_GUN_158, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00002000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS,
};

struct weapon invitem_falcon2silencer = {
	FILE_GFALCON2, // hi model
	FILE_GFALCON2LOD, // lo model
	invanim_falcon2_equip, // equip animation
	invanim_falcon2_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_falcon2silenced_singleshot, &invfunc_falcon2_pistolwhip }, // functions
	&invammo_falcon2, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	9, // left/right
	-15.7, // up/down
	-23.8, // front/back
	1, // unk38
	invf_0001148c, // fptr
	invpartvisibility_falcon2silencer, // part visibility
	L_GUN_078, // short name
	L_GUN_008, // name
	L_GUN_150, // manufacturer
	L_GUN_157, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00002000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_GANGSTA,
};

struct modelpartvisibility invpartvisibility_magsec[] = {
	{ MODELPART_MUZZLEFLASH, false },
	{ MODELPART_NEWCLIP2,    false },
	{ MODELPART_NEWCLIP3,    false },
	{ 255 },
};

struct inventory_typef invf_00011840[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002a, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x0029, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_magsec_reload_0[] = {
	gunscript_playanimation(0x0409, 0, 10000)
	gunscript_showpart(1, 53)
	gunscript_showpart(1, 41)
	gunscript_setsoundspeed(3, 1300)
	gunscript_playsound(3, 0x01d8)
	gunscript_showpart(10, 42)
	gunscript_hidepart(14, 41)
	gunscript_hidepart(22, 42)
	gunscript_showpart(22, 41)
	gunscript_setsoundspeed(27, 1300)
	gunscript_playsound(27, 0x80f6)
	gunscript_waittime(30, 1)
	gunscript_waittime(56, 3)
	gunscript_setsoundspeed(58, 1300)
	gunscript_playsound(58, 0x01db)
	gunscript_end
};

struct guncmd invanim_magsec_reload_1[] = {
	gunscript_playanimation(0x040a, 0, 10000)
	gunscript_showpart(1, 41)
	gunscript_setsoundspeed(5, 1300)
	gunscript_playsound(5, 0x01d8)
	gunscript_hidepart(25, 41)
	gunscript_setsoundspeed(47, 1300)
	gunscript_playsound(47, 0x80f6)
	gunscript_waittime(49, 1)
	gunscript_setsoundspeed(69, 1300)
	gunscript_playsound(69, 0x01db)
	gunscript_end
};

struct guncmd invanim_magsec_reload[] = {
	gunscript_include(1, invanim_magsec_reload_1)
	gunscript_include(0, invanim_magsec_reload_0)
	gunscript_end
};

struct guncmd invanim_magsec_equiporshoot[] = {
	gunscript_playanimation(0x040b, 0, 10000)
	gunscript_waittime(12, 5)
	gunscript_end
};

struct inventory_class invclass_magsec4 = {
	25,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x11000000,
	WEAPONCLASSFLAG_AUTOAIM,
};

struct weaponfunc_shootsingle invfunc_magsec_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_085, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_magsec_equiporshoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	16,
	1.1, // damage
	6, // spread
	4, 8, 3, 0,
	5,
	10,
	59.999996185303,
	10,
	0,
	0x804c,
	1,
};

struct weaponfunc_shootsingle invfunc_magsec_burst = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_128, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_magsec_equiporshoot, // fire animation
	FUNCFLAG_BURST3,
	&invmenupos_00011098,
	16,
	1.1, // damage
	10, // spread
	9, 14, 0, 0,
	8,
	12,
	59.999996185303,
	10,
	0,
	0x804c,
	1,
};

struct inventory_ammo invammo_magsec = {
	AMMOTYPE_PISTOL,
	CASING_STANDARD,
	9, // clip size
	invanim_magsec_reload, // reload animation
	0, // flags
};

struct weapon invitem_magsec = {
	FILE_GLEEGUN1, // hi model
	FILE_GMAGSECLOD, // lo model
	invanim_magsec_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_magsec_singleshot, &invfunc_magsec_burst }, // functions
	&invammo_magsec, // pri ammo
	NULL, // sec ammo
	&invclass_magsec4,
	2, // sway
	10.5, // left/right
	-17.2, // up/down
	-26.5, // front/back
	1, // unk38
	invf_00011840, // fptr
	invpartvisibility_magsec, // part visibility
	L_GUN_010, // short name
	L_GUN_010, // name
	L_GUN_151, // manufacturer
	L_GUN_159, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_GANGSTA,
};

struct modelpartvisibility invpartvisibility_dy357[] = {
	{ MODELPART_MUZZLEFLASH, false },
	{ MODELPART_NEWCLIP,     false },
	{ MODELPART_NEWCLIP2,    false },
	{ MODELPART_NEWCLIP3,    false },
	{ MODELPART_NEWCLIP4,    false },
	{ MODELPART_SCOPE,       false }, // reused model part number
	{ MODELPART_SILENCER,    false }, // reused model part number
	{ 255 },
};

struct inventory_typef invf_00011a84[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0028, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x0029, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002a, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002b, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002c, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002d, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_dy357_equiporshoot[] = {
	gunscript_playanimation(0x0406, 0, 10000)
	gunscript_waittime(12, 5)
	gunscript_waittime(12, 2)
	gunscript_end
};

struct guncmd invanim_dy357_reload_0[] = {
	gunscript_playanimation(0x0408, 0, 10000)
	gunscript_playsound(50, 0x05cf)
	gunscript_setsoundspeed(80, 1830)
	gunscript_playsound(80, 0x01d8)
	gunscript_popoutsackofpills(0x0050)
	gunscript_popoutsackofpills(0x0051)
	gunscript_popoutsackofpills(0x0052)
	gunscript_popoutsackofpills(0x0053)
	gunscript_popoutsackofpills(0x0054)
	gunscript_popoutsackofpills(0x0055)
	gunscript_showpart(92, 53)
	gunscript_showpart(92, 40)
	gunscript_showpart(92, 41)
	gunscript_showpart(92, 42)
	gunscript_showpart(92, 43)
	gunscript_showpart(92, 44)
	gunscript_showpart(92, 45)
	gunscript_setsoundspeed(114, 1210)
	gunscript_playsound(114, 0x01d8)
	gunscript_hidepart(121, 40)
	gunscript_hidepart(121, 41)
	gunscript_hidepart(121, 42)
	gunscript_hidepart(121, 43)
	gunscript_hidepart(121, 44)
	gunscript_hidepart(121, 45)
	gunscript_waittime(123, 1)
	gunscript_playsound(147, 0x05cd)
	gunscript_end
};

struct guncmd invanim_dy357_reload_1[] = {
	gunscript_playanimation(0x0420, 0, 10000)
	gunscript_playsound(50, 0x05cf)
	gunscript_setsoundspeed(80, 1830)
	gunscript_playsound(80, 0x01d8)
	gunscript_popoutsackofpills(0x0050)
	gunscript_popoutsackofpills(0x0051)
	gunscript_popoutsackofpills(0x0052)
	gunscript_popoutsackofpills(0x0053)
	gunscript_popoutsackofpills(0x0054)
	gunscript_popoutsackofpills(0x0055)
	gunscript_setsoundspeed(114, 1210)
	gunscript_playsound(114, 0x01d8)
	gunscript_waittime(123, 1)
	gunscript_playsound(147, 0x05cd)
	gunscript_end
};

struct guncmd invanim_dy357_reload[] = {
	gunscript_include(1, invanim_dy357_reload_1)
	gunscript_include(0, invanim_dy357_reload_0)
	gunscript_end
};

struct guncmd invanim_dy357_pistolwhip[] = {
	gunscript_playanimation(0x0407, 0, 10000)
	gunscript_waittime(23, 2)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_dy357_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_085, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_dy357_equiporshoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	20,
	2, // damage
	0, // spread
	8, 16, 0, -1,
	12,
	35,
	0,
	6,
	0,
	0x8066,
	5,
};

struct weaponfunc_shootsingle invfunc_dy357lx_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_085, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_dy357_equiporshoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	30,
	200, // damage
	0, // spread
	8, 24, 0, -1,
	12,
	35,
	0,
	6,
	0,
	0x8066,
	5,
};

struct weaponfunc_close invfunc_dy357_pistolwhip = {
	INVENTORYFUNCTYPE_CLOSE,
	L_GUN_094, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_dy357_pistolwhip, // fire animation
	FUNCFLAG_MAKEDIZZY | FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_LESSDAMAGE | FUNCFLAG_NOSTUN | FUNCFLAG_00400000,
	0.9, // damage
	60,
	0x00000069,
	0x00000069,
	0x00000069,
	0x41980000,
	0xc195999a,
	0x41980000,
	0xc195999a,
	0xbf800000,
	0xbf800000,
	0x40000000,
	0x40000000,
	0x00000000,
};

struct inventory_ammo invammo_dy357 = {
	AMMOTYPE_MAGNUM,
	CASING_STANDARD,
	6, // clip size
	invanim_dy357_reload, // reload animation
	0, // flags
};

struct weapon invitem_dy357 = {
	FILE_GDY357, // hi model
	FILE_GDY357LOD, // lo model
	invanim_dy357_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_dy357_singleshot, &invfunc_dy357_pistolwhip }, // functions
	&invammo_dy357, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	2, // sway
	9.5, // left/right
	-18.2, // up/down
	-25.5, // front/back
	1, // unk38
	invf_00011a84, // fptr
	invpartvisibility_dy357, // part visibility
	L_GUN_084, // short name
	L_GUN_012, // name
	L_GUN_149, // manufacturer
	L_GUN_161, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS,
};

struct weapon invitem_dy357lx = {
	FILE_GDY357TRENT, // hi model
	FILE_GDY357TRENTLOD, // lo model
	invanim_dy357_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_dy357lx_singleshot, &invfunc_dy357_pistolwhip }, // functions
	&invammo_dy357, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	2, // sway
	9.5, // left/right
	-18.2, // up/down
	-25.5, // front/back
	1, // unk38
	invf_00011a84, // fptr
	invpartvisibility_dy357, // part visibility
	L_GUN_013, // short name
	L_GUN_013, // name
	L_GUN_149, // manufacturer
	L_GUN_162, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS,
};

struct modelpartvisibility invpartvisibility_phoenix[] = {
	{ MODELPART_NEWCLIP, false },
	{ 255 },
};

struct inventory_typef invf_00011e00[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0028, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_equiporreload_0[] = {
	gunscript_playanimation(0x0415, 0, 10000)
	gunscript_showpart(1, 53)
	gunscript_showpart(1, 40)
	gunscript_setsoundspeed(44, 1510)
	gunscript_playsound(44, 0x0433)
	gunscript_hidepart(50, 40)
	gunscript_end
};

struct guncmd invanim_phoenix_equiporreload_1[] = {
	gunscript_playanimation(0x0423, 0, 10000)
	gunscript_showpart(1, 53)
	gunscript_showpart(1, 40)
	gunscript_setsoundspeed(44, 1510)
	gunscript_playsound(44, 0x0433)
	gunscript_hidepart(50, 40)
	gunscript_end
};

struct guncmd invanim_phoenix_equiporreload[] = {
	gunscript_include(1, invanim_phoenix_equiporreload_1)
	gunscript_include(0, invanim_equiporreload_0)
	gunscript_end
};

struct guncmd invanim_phoenix_shoot[] = {
	gunscript_playanimation(0x043e, 0, 10000)
	gunscript_waittime(9, 5)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_phoenix_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_085, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_phoenix_shoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	16,
	1.1, // damage
	3, // spread
	3, 5, 2, 0,
	10,
	15,
	59.999996185303,
	0,
	0,
	0x8071,
	1,
};

struct weaponfunc_shootsingle invfunc_phoenix_explosiveshells = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_095, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_phoenix_shoot, // fire animation
	FUNCFLAG_EXPLOSIVESHELLS,
	&invmenupos_00011098,
	16,
	1.2, // damage
	5, // spread
	13, 15, 25, 0,
	15,
	25,
	59.999996185303,
	0,
	0,
	0x8072,
	1,
};

struct inventory_ammo invammo_phoenix = {
	AMMOTYPE_PISTOL,
	CASING_NONE,
	8, // clip size
	invanim_phoenix_equiporreload, // reload animation
	0, // flags
};

struct weapon invitem_phoenix = {
	FILE_GMAIANPISTOL, // hi model
	FILE_GMAYANPISTOLLOD, // lo model
	invanim_phoenix_equiporreload, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_phoenix_singleshot, &invfunc_phoenix_explosiveshells }, // functions
	&invammo_phoenix, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	9.5, // left/right
	-16.2, // up/down
	-23, // front/back
	1, // unk38
	invf_00011e00, // fptr
	invpartvisibility_phoenix, // part visibility
	L_GUN_014, // short name
	L_GUN_014, // name
	L_GUN_153, // manufacturer
	L_GUN_163, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_GANGSTA,
};

struct modelpartvisibility invpartvisibility_mauler[] = {
	{ MODELPART_NEWCLIP4,    false },
	{ MODELPART_MUZZLEFLASH, false },
	{ 255 },
};

struct inventory_typef invf_00011fac[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002b, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_mauler_equiporshoot[] = {
	gunscript_playanimation(0x03f3, 0, 10000)
	gunscript_waittime(9, 5)
	gunscript_end
};

struct guncmd invanim_mauler_reload_0[] = {
	gunscript_playanimation(0x03f4, 0, 10000)
	gunscript_showpart(0, 53)
	gunscript_setsoundspeed(4, 1200)
	gunscript_playsound(4, 0x0053)
	gunscript_showpart(4, 43)
	gunscript_hidepart(18, 42)
	gunscript_setsoundspeed(20, 2500)
	gunscript_playsound(20, 0x8012)
	gunscript_waittime(25, 1)
	gunscript_showpart(25, 42)
	gunscript_hidepart(25, 43)
	gunscript_setsoundspeed(27, 2000)
	gunscript_playsound(27, 0x05c5)
	gunscript_setsoundspeed(61, 1000)
	gunscript_playsound(61, 0x01db)
	gunscript_waittime(61, 3)
	gunscript_end
};

struct guncmd invanim_mauler_reload_1[] = {
	gunscript_playanimation(0x03f5, 0, 10000)
	gunscript_setsoundspeed(14, 1200)
	gunscript_playsound(14, 0x0053)
	gunscript_setsoundspeed(40, 2500)
	gunscript_playsound(40, 0x8012)
	gunscript_setsoundspeed(47, 2000)
	gunscript_playsound(47, 0x05c5)
	gunscript_waittime(47, 1)
	gunscript_setsoundspeed(68, 1000)
	gunscript_playsound(68, 0x01db)
	gunscript_end
};

struct guncmd invanim_mauler_reload[] = {
	gunscript_include(1, invanim_mauler_reload_1)
	gunscript_include(0, invanim_mauler_reload_0)
	gunscript_end
};

struct guncmd invanim_unused_8007c0bc[] = {
	gunscript_playanimation(0x03f6, 0, 10000)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_mauler_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_085, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_mauler_equiporshoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	1.2, // damage
	6, // spread
	3, 9, 32, 28,
	0,
	0,
	59.999996185303,
	4,
	0,
	0x805b,
	1,
};

struct weaponfunc_shootsingle invfunc_mauler_chargeshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_129, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_mauler_equiporshoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	1.2, // damage
	6, // spread
	3, 9, 32, 28,
	0,
	0,
	59.999996185303,
	4,
	0,
	0x805b,
	1,
};

struct inventory_ammo invammo_mauler = {
	AMMOTYPE_PISTOL,
	CASING_NONE,
	20, // clip size
	invanim_mauler_reload, // reload animation
	0, // flags
};

struct weapon invitem_mauler = {
	FILE_GSKPISTOL, // hi model
	FILE_GSKPISTOLLOD, // lo model
	invanim_mauler_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_mauler_singleshot, &invfunc_mauler_chargeshot }, // functions
	&invammo_mauler, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	11.5, // left/right
	-17.5, // up/down
	-20, // front/back
	1, // unk38
	invf_00011fac, // fptr
	invpartvisibility_mauler, // part visibility
	L_GUN_011, // short name
	L_GUN_011, // name
	L_GUN_152, // manufacturer
	L_GUN_160, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_HASHANDS,
};

struct modelpartvisibility invpartvisibility_cmp150[] = {
	{ MODELPART_MUZZLEFLASH, false },
	{ MODELPART_NEWCLIP4,    false },
	{ 255 },
};

struct inventory_typef invf_000121d8[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x002b, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x0047, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_cmp150_reload_0[] = {
	gunscript_playanimation(0x0115, 0, 10000)
	gunscript_hidepart(23, 42)
	gunscript_showpart(33, 53)
	gunscript_showpart(33, 43)
	gunscript_setsoundspeed(9, 950)
	gunscript_playsound(9, 0x01d8)
	gunscript_setsoundspeed(44, 950)
	gunscript_playsound(44, 0x80f6)
	gunscript_hidepart(45, 43)
	gunscript_showpart(45, 42)
	gunscript_waittime(45, 1)
	gunscript_playsound(86, 0x0431)
	gunscript_end
};

struct guncmd invanim_cmp150_reload_1[] = {
	gunscript_playanimation(0x0422, 0, 10000)
	gunscript_hidepart(23, 42)
	gunscript_showpart(33, 53)
	gunscript_showpart(33, 43)
	gunscript_setsoundspeed(20, 950)
	gunscript_playsound(20, 0x01d8)
	gunscript_setsoundspeed(61, 950)
	gunscript_playsound(61, 0x80f6)
	gunscript_hidepart(61, 43)
	gunscript_showpart(61, 42)
	gunscript_waittime(61, 1)
	gunscript_playsound(76, 0x0431)
	gunscript_end
};

struct guncmd invanim_cmp150_reload[] = {
	gunscript_include(1, invanim_cmp150_reload_1)
	gunscript_include(0, invanim_cmp150_reload_0)
	gunscript_end
};

struct guncmd invanim_cmp150_equiporshoot[] = {
	gunscript_playanimation(0x0116, 0, 10000)
	gunscript_waittime(14, 5)
	gunscript_waitforzreleased(14)
	gunscript_end
};

struct inventory_class invclass_cmp150 = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x40000000,
	WEAPONCLASSFLAG_AUTOAIM | WEAPONCLASSFLAG_00000004,
};

struct weaponfunc_shootauto invfunc_cmp150_rapidfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_086, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_cmp150_equiporshoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	1, // damage
	9, // spread
	6, 18, 0, 6,
	4,
	3,
	0,
	0,
	3,
	0x8040,
	1,
	900,
	900,
	NULL,
	NULL,
	0, 0,
};

struct weaponfunc_shootauto invfunc_cmp150_followlockon = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_102, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_cmp150_equiporshoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	1, // damage
	9, // spread
	6, 18, 0, 6,
	4,
	3,
	0,
	0,
	3,
	0x8040,
	1,
	900,
	900,
	NULL,
	NULL,
	0, 0,
};

struct inventory_ammo invammo_cmp150 = {
	AMMOTYPE_SMG,
	CASING_STANDARD,
	32, // clip size
	invanim_cmp150_reload, // reload animation
	0, // flags
};

struct weapon invitem_cmp150 = {
	FILE_GCMP150, // hi model
	FILE_GCMP150LOD, // lo model
	invanim_cmp150_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_cmp150_rapidfire, &invfunc_cmp150_followlockon }, // functions
	&invammo_cmp150, // pri ammo
	NULL, // sec ammo
	&invclass_cmp150,
	3, // sway
	13, // left/right
	-17.7, // up/down
	-27.5, // front/back
	1, // unk38
	invf_000121d8, // fptr
	invpartvisibility_cmp150, // part visibility
	L_GUN_015, // short name
	L_GUN_015, // name
	L_GUN_149, // manufacturer
	L_GUN_164, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_04000000 | WEAPONFLAG_AIMTRACK,
};

struct modelpartvisibility invpartvisibility_cyclone[] = {
	{ MODELPART_MUZZLEFLASH, false },
	{ MODELPART_NEWCLIP,     false },
	{ 255 },
};

struct inventory_typef invf_0001243c[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x0028, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_cyclone_equiporreload_0[] = {
	gunscript_playanimation(0x040e, 0, 10000)
	gunscript_showpart(1, 53)
	gunscript_showpart(1, 40)
	gunscript_playsound(60, 0x05d3)
	gunscript_end
};

struct guncmd invanim_cyclone_equiporreload_1[] = {
	gunscript_playanimation(0x0421, 0, 10000)
	gunscript_playsound(60, 0x05d3)
	gunscript_end
};

struct guncmd invanim_cyclone_equiporreload[] = {
	gunscript_include(1, invanim_cyclone_equiporreload_1)
	gunscript_include(0, invanim_cyclone_equiporreload_0)
	gunscript_end
};

struct guncmd invanim_cyclone_shoot[] = {
	gunscript_playanimation(0x043d, 0, 10000)
	gunscript_waittime(5, 5)
	gunscript_waitforzreleased(5)
	gunscript_end
};

struct weaponfunc_shootauto invfunc_cyclone_rapidfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_086, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_cyclone_shoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	0.8, // damage
	6, // spread
	6, 18, 2, 8,
	5,
	2,
	0,
	4,
	4,
	0x805f,
	1,
	900,
	900,
	NULL,
	NULL,
	0, 0,
};

struct weaponfunc_shootauto invfunc_cyclone_magazinedischarge = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_097, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_cyclone_shoot, // fire animation
	FUNCFLAG_BURST50,
	&invmenupos_00011098,
	0,
	1.4, // damage
	25, // spread
	6, 18, 2, 8,
	5,
	2,
	0,
	4,
	4,
	0x8075,
	1,
	2000,
	2000,
	NULL,
	NULL,
	0, 0,
};

struct inventory_ammo invammo_cyclone = {
	AMMOTYPE_SMG,
	CASING_NONE,
	50, // clip size
	invanim_cyclone_equiporreload, // reload animation
	0, // flags
};

struct weapon invitem_cyclone = {
	FILE_GCYCLONE, // hi model
	FILE_GCYCLONELOD, // lo model
	invanim_cyclone_equiporreload, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_cyclone_rapidfire, &invfunc_cyclone_magazinedischarge }, // functions
	&invammo_cyclone, // pri ammo
	NULL, // sec ammo
	&invclass_smg,
	1, // sway
	21.5, // left/right
	-26.5, // up/down
	-35, // front/back
	1, // unk38
	invf_0001243c, // fptr
	invpartvisibility_cyclone, // part visibility
	L_GUN_020, // short name
	L_GUN_020, // name
	L_GUN_151, // manufacturer
	L_GUN_169, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_HASHANDS,
};

struct guncmd invanim_rcp120_reload[] = {
	gunscript_playanimation(0x041a, 0, 10000)
	gunscript_setsoundspeed(18, 1100)
	gunscript_playsound(18, 0x0053)
	gunscript_showpart(25, 40)
	gunscript_showpart(50, 41)
	gunscript_playsound(74, 0x05c5)
	gunscript_hidepart(75, 41)
	gunscript_showpart(75, 40)
	gunscript_playsound(112, 0x0431)
	gunscript_end
};

struct guncmd invanim_rcp120_equiporshoot[] = {
	gunscript_playanimation(0x0424, 0, 10000)
	gunscript_waittime(10, 5)
	gunscript_waitforzreleased(10)
	gunscript_end
};

struct modelpartvisibility invpartvisibility_rcp120[] = {
	{ MODELPART_MUZZLEFLASH, false },
	{ MODELPART_NEWCLIP2,    false },
	{ 255 },
};

struct inventory_typef invf_00012658[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0029, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct weaponfunc_shootauto invfunc_rcp120_rapidfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_086, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_rcp120_equiporshoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	1.2, // damage
	6, // spread
	6, 18, 0, 6,
	4,
	3,
	0,
	0,
	4,
	0x806d,
	1,
	1100,
	1100,
	NULL,
	NULL,
	0, 0,
};

struct weaponfunc_special invfunc_rcp120_cloak = {
	INVENTORYFUNCTYPE_SPECIAL,
	L_GUN_116, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_AUTOSWITCHUNSELECTABLE,
	HANDATTACKTYPE_RCP120CLOAK,
	0x0000001e,
	0x00000000,
};

struct inventory_ammo invammo_rcp120 = {
	AMMOTYPE_SMG,
	CASING_STANDARD,
	120, // clip size
	invanim_rcp120_reload, // reload animation
	0, // flags
};

struct weapon invitem_rcp120 = {
	FILE_GRCP120, // hi model
	FILE_GRCP120LOD, // lo model
	invanim_rcp120_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_rcp120_rapidfire, &invfunc_rcp120_cloak }, // functions
	&invammo_rcp120, // pri ammo
	NULL, // sec ammo
	&invclass_smg,
	3, // sway
	13, // left/right
	-18.2, // up/down
	-27.5, // front/back
	1, // unk38
	invf_00012658, // fptr
	invpartvisibility_rcp120, // part visibility
	L_GUN_022, // short name
	L_GUN_022, // name
	L_GUN_151, // manufacturer
	L_GUN_170, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_DETERMINER_S_AN | WEAPONFLAG_DETERMINER_F_AN,
};

struct guncmd invanim_callisto_equiporreload[] = {
	gunscript_playanimation(0x0418, 0, 10000)
	gunscript_showpart(30, 40)
	gunscript_setsoundspeed(58, 933)
	gunscript_playsound(58, 0x0433)
	gunscript_hidepart(79, 40)
	gunscript_end
};

struct guncmd invanim_callisto_shoot[] = {
	gunscript_playanimation(0x043c, 0, 10000)
	gunscript_waittime(8, 5)
	gunscript_waitforzreleased(8)
	gunscript_end
};

struct modelpartvisibility invpartvisibility_callisto[] = {
	{ MODELPART_NEWCLIP, false },
	{ 255 },
};

struct inventory_typef invf_00012798[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0028, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct weaponfunc_shootauto invfunc_callisto_rapidfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_086, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_callisto_shoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	1.2, // damage
	9, // spread
	6, 18, 0, 6,
	4,
	3,
	0,
	0,
	3,
	0x8063,
	1,
	900,
	900,
	NULL,
	NULL,
	0, 0,
};

struct weaponfunc_shootauto invfunc_callisto_highimpactshells = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_115, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_callisto_shoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	2.4, // damage
	9, // spread
	6, 18, 0, 6,
	4,
	3,
	0,
	0,
	3,
	0x8064,
	5,
	300,
	300,
	NULL,
	NULL,
	0, 0,
};

struct inventory_ammo invammo_callisto = {
	AMMOTYPE_SMG,
	CASING_NONE,
	32, // clip size
	invanim_callisto_equiporreload, // reload animation
	0, // flags
};

struct weapon invitem_callisto = {
	FILE_GMAIANSMG, // hi model
	FILE_GMAYANSMGLOD, // lo model
	invanim_callisto_equiporreload, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_callisto_rapidfire, &invfunc_callisto_highimpactshells }, // functions
	&invammo_callisto, // pri ammo
	NULL, // sec ammo
	&invclass_smg,
	3, // sway
	17.5, // left/right
	-22.7, // up/down
	-25, // front/back
	1, // unk38
	invf_00012798, // fptr
	invpartvisibility_callisto, // part visibility
	L_GUN_023, // short name
	L_GUN_023, // name
	L_GUN_153, // manufacturer
	L_GUN_171, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS,
};

struct inventory_typef invf_000128b8[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0028, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct modelpartvisibility invpartvisibility_dragon[] = {
	{ MODELPART_NEWCLIP,     false },
	{ MODELPART_MUZZLEFLASH, false },
	{ 255 },
};

struct guncmd invanim_dragon_equiporshoot[] = {
	gunscript_playanimation(0x03f9, 0, 10000)
	gunscript_end
};

struct guncmd invanim_dragon_reload[] = {
	gunscript_playanimation(0x03fa, 0, 10000)
	gunscript_playsound(8, 0x0053)
	gunscript_hidepart(17, 42)
	gunscript_showpart(17, 40)
	gunscript_waittime(41, 1)
	gunscript_playsound(41, 0x05c5)
	gunscript_showpart(41, 42)
	gunscript_hidepart(41, 40)
	gunscript_end
};

struct weaponfunc_shootauto invfunc_dragon_rapidfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_086, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_dragon_equiporshoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	1.1, // damage
	6, // spread
	6, 18, 2, 8,
	5,
	2,
	0,
	4,
	4,
	0x8049,
	1,
	700,
	700,
	NULL,
	NULL,
	0, 0,
};

struct weaponfunc_throw invfunc_dragon_selfdestruct = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN_118, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_DISCARDWEAPON,
	0x000000ff,
	240, // activatetime60
	60, // recoverytime60
	0, // damage
};

struct inventory_ammo invammo_dragon = {
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	invanim_dragon_reload, // reload animation
	0, // flags
};

struct weapon invitem_dragon = {
	FILE_GDYDRAGON, // hi model
	FILE_GDYDRAGONLOD, // lo model
	invanim_dragon_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_dragon_rapidfire, &invfunc_dragon_selfdestruct }, // functions
	&invammo_dragon, // pri ammo
	NULL, // sec ammo
	&invclass_heavy,
	1, // sway
	15, // left/right
	-29.5, // up/down
	-27, // front/back
	1, // unk38
	invf_000128b8, // fptr
	invpartvisibility_dragon, // part visibility
	L_GUN_017, // short name
	L_GUN_017, // name
	L_GUN_149, // manufacturer
	L_GUN_166, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_04000000,
};

struct inventory_typef invf_00012a08[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0028, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x0029, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct modelpartvisibility invpartvisibility_superdragon[] = {
	{ MODELPART_NEWCLIP,     false },
	{ MODELPART_NEWCLIP2,    false },
	{ MODELPART_MUZZLEFLASH, false },
	{ 255 },
};

struct guncmd invanim_superdragon_reload[] = {
	gunscript_playanimation(0x03fb, 0, 10000)
	gunscript_playsound(8, 0x0053)
	gunscript_hidepart(16, 42)
	gunscript_showpart(16, 40)
	gunscript_playsound(41, 0x05c5)
	gunscript_waittime(43, 1)
	gunscript_showpart(43, 42)
	gunscript_hidepart(43, 40)
	gunscript_end
};

struct guncmd invanim_superdragon_grenadereload[] = {
	gunscript_playanimation(0x03fc, 0, 10000)
	gunscript_setsoundspeed(6, 700)
	gunscript_playsound(6, 0x0053)
	gunscript_showpart(30, 41)
	gunscript_hidepart(30, 43)
	gunscript_hidepart(64, 41)
	gunscript_showpart(64, 43)
	gunscript_waittime(64, 1)
	gunscript_setsoundspeed(66, 850)
	gunscript_playsound(66, 0x05c5)
	gunscript_end
};

struct guncmd invanim_superdragon_equiporshoot[] = {
	gunscript_playanimation(0x03fe, 0, 10000)
	gunscript_end
};

struct guncmd invanim_superdragon_shootgrenade[] = {
	gunscript_playanimation(0x03ff, 0, 10000)
	gunscript_end
};

struct guncmd invanim_superdragon_pritosec[] = {
	gunscript_playanimation(0x03fd, 0, 10000)
	gunscript_end
};

struct guncmd invanim_superdragon_sectopri[] = {
	gunscript_playanimation(0x03fd, 65535, 55536)
	gunscript_end
};

struct weaponfunc_shootauto invfunc_superdragon_rapidfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_086, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_superdragon_equiporshoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	1.2, // damage
	6, // spread
	6, 18, 2, 8,
	5,
	2,
	0,
	4,
	4,
	0x8049,
	1,
	700,
	700,
	NULL,
	NULL,
	0, 0,
};

struct weaponfunc_shootprojectile invfunc_superdragon_grenadelauncher = {
	INVENTORYFUNCTYPE_SHOOT_PROJECTILE,
	L_GUN_098, // name
	0x00, // unk06
	1, // unk07
	&invmenupos_00011048, // menupos
	invanim_superdragon_shootgrenade, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_10000000 | FUNCFLAG_20000000,
	NULL,
	0,
	1.2, // damage
	6, // spread
	5, 15, -1, 0,
	3,
	2,
	0,
	4,
	4,
	0x8073,
	1,
	0x00000123,
	0x00000000,
	0x3f800000,
	0x00000000,
	0x3da3d70a,
	0x0000001e,
	0x000004b0,
	0x3dcccccd,
	0x80530000,
};

struct inventory_ammo invammo_superdragon = {
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	invanim_superdragon_reload, // reload animation
	0, // flags
};

struct inventory_ammo invammo_superdragon_grenades = {
	AMMOTYPE_DEVASTATOR,
	CASING_NONE,
	6, // clip size
	invanim_superdragon_grenadereload, // reload animation
	0, // flags
};

struct weapon invitem_superdragon = {
	FILE_GDYSUPERDRAGON, // hi model
	FILE_GDYSUPERDRAGONLOD, // lo model
	invanim_superdragon_equiporshoot, // equip animation
	NULL, // unequip animation
	invanim_superdragon_pritosec, // pritosec animation
	invanim_superdragon_sectopri, // sectopri animation
	{ &invfunc_superdragon_rapidfire, &invfunc_superdragon_grenadelauncher }, // functions
	&invammo_superdragon, // pri ammo
	&invammo_superdragon_grenades, // sec ammo
	&invclass_heavy,
	1, // sway
	15, // left/right
	-29.5, // up/down
	-27, // front/back
	1, // unk38
	invf_00012a08, // fptr
	invpartvisibility_superdragon, // part visibility
	L_GUN_018, // short name
	L_GUN_018, // name
	L_GUN_149, // manufacturer
	L_GUN_167, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_HASHANDS,
};

struct inventory_typef invf_00012c40[] = {
	{ 0x0100, 0x0000, 0x0100, 0x002a, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct modelpartvisibility invpartvisibility_ar34[] = {
	{ MODELPART_NEWCLIP3,    false },
	{ MODELPART_MUZZLEFLASH, false },
	{ 255 },
};

struct guncmd invanim_ar34_equiporreload[] = {
	gunscript_playanimation(0x0419, 0, 10000)
	gunscript_setsoundspeed(16, 900)
	gunscript_playsound(16, 0x0053)
	gunscript_hidepart(21, 41)
	gunscript_showpart(50, 42)
	gunscript_setsoundspeed(67, 1400)
	gunscript_playsound(67, 0x8025)
	gunscript_hidepart(72, 42)
	gunscript_showpart(72, 41)
	gunscript_waittime(72, 1)
	gunscript_setsoundspeed(95, 900)
	gunscript_playsound(95, 0x05c5)
	gunscript_end
};

struct inventory_class invclass_ar34 = {
	20,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x15000000,
	WEAPONCLASSFLAG_AUTOAIM | WEAPONCLASSFLAG_00000004,
};

struct weaponfunc_shootauto invfunc_ar34_burstfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_087, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	NULL, // fire animation
	FUNCFLAG_BURST3,
	&invmenupos_00011098,
	0,
	1.4, // damage
	8, // spread
	6, 18, 2, 8,
	5,
	2,
	0,
	4,
	5,
	0x8059,
	1,
	750,
	750,
	NULL,
	NULL,
	0, 0,
};

struct weaponfunc_shootauto invfunc_ar34_usescope = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_103, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	NULL, // fire animation
	FUNCFLAG_BURST3,
	&invmenupos_00011098,
	0,
	1.4, // damage
	8, // spread
	6, 18, 2, 8,
	5,
	2,
	0,
	4,
	5,
	0x8059,
	1,
	750,
	750,
	NULL,
	NULL,
	0, 0,
};

struct inventory_ammo invammo_ar34 = {
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	invanim_ar34_equiporreload, // reload animation
	0, // flags
};

struct weapon invitem_ar34 = {
	FILE_GAR34, // hi model
	FILE_GAR34LOD, // lo model
	invanim_ar34_equiporreload, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_ar34_burstfire, &invfunc_ar34_usescope }, // functions
	&invammo_ar34, // pri ammo
	NULL, // sec ammo
	&invclass_ar34,
	1, // sway
	11.5, // left/right
	-25.7, // up/down
	-30.5, // front/back
	1, // unk38
	invf_00012c40, // fptr
	invpartvisibility_ar34, // part visibility
	L_GUN_016, // short name
	L_GUN_016, // name
	L_GUN_000, // manufacturer
	L_GUN_165, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_DETERMINER_S_AN | WEAPONFLAG_DETERMINER_F_AN | WEAPONFLAG_04000000,
};

struct inventory_typef invf_00012df0[] = {
	{ 0x0100, 0x0000, 0x0100, 0x002a, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct modelpartvisibility invpartvisibility_k7avenger[] = {
	{ MODELPART_NEWCLIP3,    false },
	{ MODELPART_MUZZLEFLASH, false },
	{ 255 },
};

struct guncmd invanim_k7avenger_reload[] = {
	gunscript_playanimation(0x00e9, 0, 10000)
	gunscript_setsoundspeed(15, 1200)
	gunscript_playsound(15, 0x0053)
	gunscript_hidepart(22, 41)
	gunscript_showpart(48, 42)
	gunscript_waittime(68, 1)
	gunscript_hidepart(69, 42)
	gunscript_showpart(69, 41)
	gunscript_setsoundspeed(69, 1400)
	gunscript_playsound(69, 0x8025)
	gunscript_playsound(91, 0x05c5)
	gunscript_end
};

struct guncmd invanim_k7avenger_equip[] = {
	gunscript_playanimation(0x00e6, 0, 10000)
	gunscript_end
};

struct guncmd invanim_k7avenger_unequip[] = {
	gunscript_playanimation(0x00e7, 0, 10000)
	gunscript_end
};

struct guncmd invanim_unused_8007ce6c[] = {
	gunscript_playanimation(0x00e8, 0, 10000)
	gunscript_end
};

struct inventory_class invclass_k7avenger = {
	20,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x15000000,
	WEAPONCLASSFLAG_AUTOAIM | WEAPONCLASSFLAG_00000004,
};

struct weaponfunc_shootauto invfunc_k7avenger_burstfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_087, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	NULL, // fire animation
	FUNCFLAG_BURST3,
	&invmenupos_00011098,
	0,
	1.5, // damage
	6, // spread
	6, 18, 2, 8,
	5,
	2,
	0,
	4,
	4,
	0x805a,
	1,
	950,
	950,
	NULL,
	NULL,
	0, 0,
};

struct weaponfunc_shootauto invfunc_k7avenger_threatdetector = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_119, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	NULL, // fire animation
	FUNCFLAG_BURST3 | FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_THREATDETECTOR,
	&invmenupos_00011098,
	0,
	1.5, // damage
	6, // spread
	6, 18, 2, 8,
	5,
	2,
	0,
	4,
	4,
	0x805a,
	1,
	950,
	950,
	NULL,
	NULL,
	0, 0,
};

struct inventory_ammo invammo_k7avenger = {
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	25, // clip size
	invanim_k7avenger_reload, // reload animation
	0, // flags
};

struct weapon invitem_k7avenger = {
	FILE_GK7AVENGER, // hi model
	FILE_GAVENGERLOD, // lo model
	invanim_k7avenger_equip, // equip animation
	invanim_k7avenger_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_k7avenger_burstfire, &invfunc_k7avenger_threatdetector }, // functions
	&invammo_k7avenger, // pri ammo
	NULL, // sec ammo
	&invclass_k7avenger,
	1, // sway
	6.5, // left/right
	-24, // up/down
	-27, // front/back
	1, // unk38
	invf_00012df0, // fptr
	invpartvisibility_k7avenger, // part visibility
	L_GUN_019, // short name
	L_GUN_019, // name
	L_GUN_149, // manufacturer
	L_GUN_168, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_HASHANDS,
};

struct inventory_typef invf_00012fc8[] = {
	{ 0x0100, 0x0000, 0x0100, 0x002a, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x0029, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct modelpartvisibility invpartvisibility_laptopgun[] = {
	{ MODELPART_MUZZLEFLASH, false },
	{ MODELPART_NEWCLIP2,    false },
	{ MODELPART_NEWCLIP3,    false },
	{ 255 },
};

struct guncmd invanim_laptopgun_reload[] = {
	gunscript_playanimation(0x00e4, 0, 10000)
	gunscript_setsoundspeed(4, 1630)
	gunscript_playsound(4, 0x04fb)
	gunscript_setsoundspeed(15, 1436)
	gunscript_playsound(15, 0x04fa)
	gunscript_playsound(25, 0x04f7)
	gunscript_showpart(40, 41)
	gunscript_playsound(42, 0x0053)
	gunscript_showpart(48, 42)
	gunscript_hidepart(55, 41)
	gunscript_hidepart(63, 42)
	gunscript_showpart(63, 41)
	gunscript_playsound(63, 0x04f8)
	gunscript_hidepart(85, 41)
	gunscript_waittime(85, 1)
	gunscript_playsound(85, 0x05c5)
	gunscript_playsound(91, 0x04f9)
	gunscript_end
};

struct guncmd invanim_laptopgun_shoot[] = {
	gunscript_playanimation(0x00e5, 0, 10000)
	gunscript_waittime(10, 5)
	gunscript_waitforzreleased(10)
	gunscript_end
};

struct guncmd invanim_laptopgun_equip[] = {
	gunscript_playanimation(0x00e2, 0, 10000)
	gunscript_setsoundspeed(15, 720)
	gunscript_playsound(15, 0x04f7)
	gunscript_playsound(35, 0x04f7)
	gunscript_playsound(58, 0x04f8)
	gunscript_end
};

struct guncmd invanim_laptopgun_unequip[] = {
	gunscript_playanimation(0x00e3, 0, 10000)
	gunscript_playsound(1, 0x04f7)
	gunscript_setsoundspeed(25, 720)
	gunscript_playsound(25, 0x04f7)
	gunscript_playsound(50, 0x04f8)
	gunscript_end
};

struct weaponfunc_shootauto invfunc_laptopgun_burstfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_087, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_laptopgun_shoot, // fire animation
	FUNCFLAG_BURST3,
	&invmenupos_00011098,
	0,
	1.15, // damage
	6, // spread
	6, 18, 2, 8,
	5,
	2,
	0,
	4,
	4,
	0x8044,
	1,
	1000,
	1000,
	NULL,
	NULL,
	0, 0,
};

struct weaponfunc_throw invfunc_laptopgun_deploy = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN_117, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_STICKTOWALL | FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_DISCARDWEAPON | FUNCFLAG_00800000,
	0x00000157,
	240, // activatetime60
	60, // recoverytime60
	0, // damage
};

struct inventory_ammo invammo_laptopgun = {
	AMMOTYPE_SMG,
	CASING_NONE,
	50, // clip size
	invanim_laptopgun_reload, // reload animation
	0, // flags
};

struct weapon invitem_laptopgun = {
	FILE_GPCGUN, // hi model
	FILE_GPCGUNLOD, // lo model
	invanim_laptopgun_equip, // equip animation
	invanim_laptopgun_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_laptopgun_burstfire, &invfunc_laptopgun_deploy }, // functions
	&invammo_laptopgun, // pri ammo
	NULL, // sec ammo
	&invclass_heavy,
	1.2, // sway
	16, // left/right
	-17.7, // up/down
	-14.5, // front/back
	1, // unk38
	invf_00012fc8, // fptr
	invpartvisibility_laptopgun, // part visibility
	PAL ? 0x4cfb : L_GUN_024, // short name
	L_GUN_024, // name
	L_GUN_150, // manufacturer
	L_GUN_172, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_04000000,
};

struct inventory_typef invf_000131dc[] = {
	{ 0x0100, 0x0000, 0x0100, 0x002b, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct modelpartvisibility invpartvisibility_shotgun[] = {
	{ MODELPART_NEWCLIP4,    false },
	{ MODELPART_MUZZLEFLASH, false },
	{ 255 },
};

struct guncmd invanim_shotgun_reload[] = {
	gunscript_playanimation(0x03ed, 0, 10000)
	gunscript_showpart(1, 43)
	gunscript_playsound(67, 0x01d8)
	gunscript_waittime(74, 1)
	gunscript_hidepart(75, 43)
	gunscript_repeatuntilfull(0x0054, 0x0000, 0x0032)
	gunscript_playsound(103, 0x04fb)
	gunscript_end
};

struct guncmd invanim_shotgun_equiporsingleshot[] = {
	gunscript_playanimation(0x03ee, 0, 10000)
	gunscript_waittime(9, 2)
	gunscript_playsound(34, 0x04fb)
	gunscript_end
};

struct guncmd invanim_shotgun_doubleshot[] = {
	gunscript_playanimation(0x042c, 0, 10000)
	gunscript_waittime(9, 2)
	gunscript_playsound(54, 0x04fb)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_shotgun_single = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_089, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_shotgun_equiporsingleshot, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	0.6, // damage
	30, // spread
	20, 28, 0, 0,
	0,
	0,
	0,
	4,
	0,
	0x8055,
	1,
};

struct weaponfunc_shootsingle invfunc_shotgun_double = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_105, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_shotgun_doubleshot, // fire animation
	FUNCFLAG_BURST2,
	&invmenupos_00011098,
	0,
	0.6, // damage
	16, // spread
	20, 28, 0, 0,
	0,
	0,
	0,
	4,
	0,
	0x8055,
	1,
};

struct inventory_ammo invammo_shotgun = {
	AMMOTYPE_SHOTGUN,
	CASING_SHOTGUN,
	9, // clip size
	invanim_shotgun_reload, // reload animation
	0x04, // flags
};

struct weapon invitem_shotgun = {
	FILE_GSHOTGUN, // hi model
	FILE_GSHOTGUNLOD, // lo model
	invanim_shotgun_equiporsingleshot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_shotgun_single, &invfunc_shotgun_double }, // functions
	&invammo_shotgun, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	12, // left/right
	-16.7, // up/down
	-21, // front/back
	1, // unk38
	invf_000131dc, // fptr
	invpartvisibility_shotgun, // part visibility
	PAL ? 0x4cfd : L_GUN_025, // short name
	L_GUN_025, // name
	L_GUN_149, // manufacturer
	L_GUN_173, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_HASHANDS,
};

f32 var8006d33c[] = {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
f32 var8006d36c[] = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};

struct modelpartvisibility invpartvisibility_reaper[] = {
	{ MODELPART_MUZZLEFLASH,  false },
	{ MODELPART_MUZZLEFLASH2, false },
	{ MODELPART_MUZZLEFLASH3, false },
	{ MODELPART_NEWCLIP4,     false },
	{ 255 },
};

struct inventory_typef invf_000133c8[] = {
	{ 0x0100, 0x0000, 0x0100, 0x002b, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_reaper_shoot[] = {
	gunscript_playanimation(0x0400, 0, 10000)
	gunscript_waittime(12, 5)
	gunscript_end
};

struct guncmd invanim_reaper_reload[] = {
	gunscript_playanimation(0x0401, 0, 10000)
	gunscript_playsound(49, 0x05c7)
	gunscript_hidepart(70, 42)
	gunscript_showpart(90, 43)
	gunscript_playsound(124, 0x05c6)
	gunscript_showpart(134, 42)
	gunscript_hidepart(134, 43)
	gunscript_waittime(134, 1)
	gunscript_end
};

struct guncmd invanim_reaper_equip[] = {
	gunscript_playanimation(0x0427, 0, 10000)
	gunscript_end
};

struct guncmd invanim_reaper_unequip[] = {
	gunscript_playanimation(0x0428, 0, 10000)
	gunscript_end
};

struct weaponfunc_shootauto invfunc_reaper_shoot = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_088, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001105c, // menupos
	invanim_reaper_shoot, // fire animation
	FUNCFLAG_BURST3,
	&invmenupos_000110ac,
	0,
	1.2, // damage
	56, // spread
	3, 9, 32, 28,
	0,
	0,
	0,
	4,
	2,
	0x803f,
	1,
	60,
	1800,
	var8006d33c,
	var8006d36c,
	88, 88,
};

struct weaponfunc_close invfunc_reaper_grind = {
	INVENTORYFUNCTYPE_CLOSE,
	L_GUN_106, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH,
	0.05, // damage
	80,
	0x00000069,
	0x00000069,
	0x00000069,
	0xbf000000,
	0xc1a9999a,
	0xbf000000,
	0xc1a9999a,
	0xbf800000,
	0xbf800000,
	0x40000000,
	0x40000000,
	0x00000000,
};

struct inventory_ammo invammo_reaper = {
	AMMOTYPE_REAPER,
	CASING_REAPER,
	200, // clip size
	invanim_reaper_reload, // reload animation
	0, // flags
};

struct weapon invitem_reaper = {
	FILE_GSKMINIGUN, // hi model
	FILE_GSKMINIGUNLOD, // lo model
	invanim_reaper_equip, // equip animation
	invanim_reaper_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_reaper_shoot, &invfunc_reaper_grind }, // functions
	&invammo_reaper, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	4, // left/right
	-21.2, // up/down
	-30.5, // front/back
	1, // unk38
	invf_000133c8, // fptr
	invpartvisibility_reaper, // part visibility
	L_GUN_026, // short name
	L_GUN_026, // name
	L_GUN_152, // manufacturer
	L_GUN_174, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_HASHANDS,
};

struct modelpartvisibility invpartvisibility_rocketlauncher[] = {
	{ MODELPART_NEWCLIP, false },
	{ 255 },
};

struct inventory_typef invf_00013564[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0028, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_rocketlauncher_reload[] = {
	gunscript_playanimation(0x03ef, 0, 10000)
	gunscript_setsoundspeed(16, 900)
	gunscript_playsound(16, 0x04f9)
	gunscript_playsound(40, 0x0053)
	gunscript_showpart(24, 40)
	gunscript_waittime(76, 1)
	gunscript_hidepart(76, 40)
	gunscript_playsound(77, 0x05d1)
	gunscript_setsoundspeed(106, 1000)
	gunscript_playsound(106, 0x04f9)
	gunscript_playsound(123, 0x0053)
	gunscript_playsound(135, 0x04fa)
	gunscript_end
};

struct guncmd invanim_rockerlauncher_equiporshoot[] = {
	gunscript_playanimation(0x03f0, 0, 10000)
	gunscript_end
};

struct inventory_class invclass_rocketlauncher = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x30000000,
	WEAPONCLASSFLAG_AUTOAIM,
};

struct weaponfunc_shootprojectile invfunc_rockerlauncher_shoot = {
	INVENTORYFUNCTYPE_SHOOT_PROJECTILE,
	L_GUN_091, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_rockerlauncher_equiporshoot, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_08000000,
	NULL,
	0,
	1, // damage
	6, // spread
	3, 12, 15, 0,
	3,
	2,
	0,
	4,
	4,
	0x8053,
	1,
	0x0000011f,
	0x00000000,
	0x40066666,
	0x0000003c,
	0x00000000,
	0x00000000,
	0xffffffff,
	0x3d4ccccd,
	0x80530000,
};

struct weaponfunc_shootprojectile invfunc_rocketlauncher_homing = {
	INVENTORYFUNCTYPE_SHOOT_PROJECTILE,
	L_GUN_092, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_rockerlauncher_equiporshoot, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_08000000 | FUNCFLAG_HOMINGROCKET,
	NULL,
	0,
	1, // damage
	6, // spread
	3, 12, 15, 0,
	3,
	2,
	0,
	4,
	4,
	0x8053,
	1,
	0x0000011f,
	0x00000000,
	0x40066666,
	0x00000000,
	0x00000000,
	0x00000005,
	0xffffffff,
	0x3d4ccccd,
	0x80530000,
};

struct inventory_ammo invammo_rocketlauncher = {
	AMMOTYPE_ROCKET,
	CASING_NONE,
	1, // clip size
	invanim_rocketlauncher_reload, // reload animation
	0, // flags
};

struct weapon invitem_rocketlauncher = {
	FILE_GDYROCKET, // hi model
	FILE_GROCKETLOD, // lo model
	invanim_rockerlauncher_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_rockerlauncher_shoot, &invfunc_rocketlauncher_homing }, // functions
	&invammo_rocketlauncher, // pri ammo
	NULL, // sec ammo
	&invclass_rocketlauncher,
	1, // sway
	24.5, // left/right
	-25.2, // up/down
	-30, // front/back
	1, // unk38
	invf_00013564, // fptr
	invpartvisibility_rocketlauncher, // part visibility
	L_GUN_080, // short name
	L_GUN_027, // name
	L_GUN_149, // manufacturer
	L_GUN_175, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_AIMTRACK,
};

struct guncmd invanim_slayer_equiporshoot[] = {
	gunscript_playanimation(0x042a, 0, 10000)
	gunscript_end
};

struct guncmd invanim_slayer_reload[] = {
	gunscript_playanimation(0x0429, 0, 10000)
	gunscript_setsoundspeed(52, 800)
	gunscript_playsound(52, 0x0053)
	gunscript_playsound(79, 0x808c)
	gunscript_setsoundspeed(126, 900)
	gunscript_playsound(126, 0x04fb)
	gunscript_end
};

struct weaponfunc_shootprojectile invfunc_slayer_shoot = {
	INVENTORYFUNCTYPE_SHOOT_PROJECTILE,
	L_GUN_091, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_slayer_equiporshoot, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_08000000,
	NULL,
	0,
	1, // damage
	6, // spread
	3, 12, 15, 0,
	3,
	2,
	0,
	4,
	4,
	0x8067,
	1,
	0x00000120,
	0x00000000,
	0x40833333,
	0x0000000a,
	0x00000000,
	0x00000000,
	0xffffffff,
	0x3d4ccccd,
	0x80530000,
};

struct weaponfunc_shootprojectile invfunc_slayer_flybywire = {
	INVENTORYFUNCTYPE_SHOOT_PROJECTILE,
	L_GUN_093, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	NULL, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_FLYBYWIRE | FUNCFLAG_08000000 | FUNCFLAG_20000000,
	NULL,
	0,
	1, // damage
	6, // spread
	3, 12, 15, 0,
	3,
	2,
	0,
	4,
	4,
	0x8067,
	1,
	0x00000120,
	0x00000000,
	0x40833333,
	0x0000000a,
	0x00000000,
	0x00000000,
	0xffffffff,
	0x3d4ccccd,
	0x80680000,
};

struct inventory_ammo invammo_slayer = {
	AMMOTYPE_ROCKET,
	CASING_NONE,
	1, // clip size
	invanim_slayer_reload, // reload animation
	0, // flags
};

struct weapon invitem_slayer = {
	FILE_GSKROCKET, // hi model
	FILE_GSKROCKETLOD, // lo model
	invanim_slayer_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_slayer_shoot, &invfunc_slayer_flybywire }, // functions
	&invammo_slayer, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	22.5, // left/right
	-32, // up/down
	-40.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_029, // short name
	L_GUN_029, // name
	L_GUN_152, // manufacturer
	L_GUN_177, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_02000000,
};

struct inventory_typef invf_unused_8006d890[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0029, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_devastator_equiporshoot[] = {
	gunscript_playanimation(0x03f7, 0, 10000)
	gunscript_end
};

struct guncmd invanim_devastator_reload[] = {
	gunscript_playanimation(0x03f8, 0, 10000)
	gunscript_setsoundspeed(15, 600)
	gunscript_playsound(15, 0x0053)
	gunscript_hidepart(22, 42)
	gunscript_showpart(36, 41)
	gunscript_setsoundspeed(47, 700)
	gunscript_playsound(47, 0x05c5)
	gunscript_hidepart(47, 41)
	gunscript_showpart(47, 42)
	gunscript_waittime(47, 1)
	gunscript_playsound(66, 0x05cc)
	gunscript_end
};

struct weaponfunc_shootprojectile invfunc_devastator_shoot = {
	INVENTORYFUNCTYPE_SHOOT_PROJECTILE,
	L_GUN_098, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_devastator_equiporshoot, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_10000000 | FUNCFLAG_20000000,
	NULL,
	0,
	1, // damage
	6, // spread
	5, 58, -1, 0,
	5,
	8,
	0,
	4,
	4,
	0x8073,
	1,
	0x00000122,
	0x00000000,
	0x3f800000,
	0x00000000,
	0x3da3d70a,
	0x00000028,
	0x000004b0,
	0x3e99999a,
	0x80530000,
};

struct weaponfunc_shootprojectile invfunc_devastator_wallhugger = {
	INVENTORYFUNCTYPE_SHOOT_PROJECTILE,
	L_GUN_099, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_devastator_equiporshoot, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_STICKTOWALL | FUNCFLAG_10000000 | FUNCFLAG_20000000,
	NULL,
	0,
	1, // damage
	6, // spread
	5, 58, -1, 0,
	5,
	8,
	0,
	4,
	4,
	0x8073,
	1,
	0x00000122,
	0x00000000,
	0x3f800000,
	0x00000000,
	0x3da3d70a,
	0x00000028,
	0x00000168,
	0x3e99999a,
	0x80530000,
};

struct inventory_ammo invammo_devastator = {
	AMMOTYPE_DEVASTATOR,
	CASING_NONE,
	8, // clip size
	invanim_devastator_reload, // reload animation
	0x08, // flags
};

struct modelpartvisibility invpartvisibility_devastator[] = {
	{ MODELPART_NEWCLIP2, false },
	{ 255 },
};

struct weapon invitem_devastator = {
	FILE_GDYDEVASTATOR, // hi model
	FILE_GDEVASTATORLOD, // lo model
	invanim_devastator_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_devastator_shoot, &invfunc_devastator_wallhugger }, // functions
	&invammo_devastator, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	19.5, // left/right
	-25.5, // up/down
	-29, // front/back
	1, // unk38
	NULL, // fptr
	invpartvisibility_devastator, // part visibility
	L_GUN_028, // short name
	L_GUN_028, // name
	L_GUN_149, // manufacturer
	L_GUN_176, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_HASHANDS,
};

struct weaponfunc invfunc_mine_threatdetector = {
	INVENTORYFUNCTYPE_NONE,
	L_GUN_119, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_THREATDETECTOR,
};

struct guncmd invanim_mine_equiporreload[] = {
	gunscript_playanimation(0x0430, 0, 10000)
	gunscript_end
};

struct guncmd invanim_mine_unequip[] = {
	gunscript_playanimation(0x0431, 0, 10000)
	gunscript_end
};

struct guncmd invanim_mine_throw[] = {
	gunscript_playanimation(0x0435, 0, 10000)
	gunscript_waitforzreleased(10)
	gunscript_waittime(13, 2)
	gunscript_end
};

struct weaponfunc_throw invfunc_timedmine_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN_120, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_mine_throw, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_00800000,
	0x00000113,
	240, // activatetime60
	0, // recoverytime60
	0, // damage
};

struct inventory_ammo invammo_timedmine = {
	AMMOTYPE_TIMED_MINE,
	CASING_NONE,
	1, // clip size
	invanim_mine_equiporreload, // reload animation
	0x02, // flags
};

struct weapon invitem_timedmine = {
	FILE_GTIMEDMINE, // hi model
	FILE_GTIMEDMINE, // lo model
	invanim_mine_equiporreload, // equip animation
	invanim_mine_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_timedmine_throw, &invfunc_mine_threatdetector }, // functions
	&invammo_timedmine, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	8, // left/right
	-15, // up/down
	-23, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	PAL ? 0x4cff : L_GUN_038, // short name
	L_GUN_038, // name
	L_GUN_000, // manufacturer
	L_GUN_185, // description
	WEAPONFLAG_00000001 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00002000 | WEAPONFLAG_HASHANDS,
};

struct inventory_typef invf_00013b40[] = {
	{ 0x0500, 0x0000, 0x0300, 0x0035, 0x0000 },
	{ 0x0500, 0x0000, 0x0300, 0x0029, 0x0000 },
	{ 0x0600, 0x0000, 0x0300, 0x0036, 0x0000 },
	{ 0x0600, 0x0000, 0x0300, 0x0028, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_remotemine_equiporreload[] = {
	gunscript_playanimation(0x0432, 0, 10000)
	gunscript_end
};

struct guncmd invanim_remotemine_unequip[] = {
	gunscript_playanimation(0x0433, 0, 10000)
	gunscript_end
};

struct guncmd invanim_remotemine_throw[] = {
	gunscript_playanimation(0x0436, 0, 10000)
	gunscript_waitforzreleased(10)
	gunscript_waittime(11, 2)
	gunscript_end
};

struct weaponfunc_throw invfunc_remotemine_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN_122, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_remotemine_throw, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_00800000,
	0x00000115,
	240, // activatetime60
	0, // recoverytime60
	0, // damage
};

struct weaponfunc_special invfunc_remotemine_detonate = {
	INVENTORYFUNCTYPE_SPECIAL,
	L_GUN_123, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_AUTOSWITCHUNSELECTABLE,
	HANDATTACKTYPE_DETONATE,
	0x0000001e,
	0x00000000,
};

struct inventory_ammo invammo_remotemine = {
	AMMOTYPE_REMOTE_MINE,
	CASING_NONE,
	1, // clip size
	invanim_remotemine_equiporreload, // reload animation
	0x02, // flags
};

struct modelpartvisibility invpartvisibility_remotemine[] = {
	{ MODELPART_NEWCLIP2, false },
	{ 255 },
};

struct weapon invitem_remotemine = {
	FILE_GREMOTEMINE, // hi model
	FILE_GREMOTEMINE, // lo model
	invanim_remotemine_equiporreload, // equip animation
	invanim_remotemine_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_remotemine_throw, &invfunc_remotemine_detonate }, // functions
	&invammo_remotemine, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	4, // left/right
	-15, // up/down
	-23, // front/back
	1, // unk38
	invf_00013b40, // fptr
	invpartvisibility_remotemine, // part visibility
	PAL ? 0x4cfc : L_GUN_040, // short name
	L_GUN_040, // name
	L_GUN_000, // manufacturer
	L_GUN_187, // description
	WEAPONFLAG_00000001 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00002000 | WEAPONFLAG_HASHANDS,
};

struct weaponfunc_throw invfunc_proxymine_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN_121, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_mine_throw, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_00800000,
	0x00000114,
	240, // activatetime60
	0, // recoverytime60
	0, // damage
};

struct inventory_ammo invammo_proximitymine = {
	AMMOTYPE_PROXY_MINE,
	CASING_NONE,
	1, // clip size
	invanim_mine_equiporreload, // reload animation
	0x02, // flags
};

struct weapon invitem_proximitymine = {
	FILE_GPROXIMITYMINE, // hi model
	FILE_GPROXIMITYMINE, // lo model
	invanim_mine_equiporreload, // equip animation
	invanim_mine_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_proxymine_throw, &invfunc_mine_threatdetector }, // functions
	&invammo_proximitymine, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	8, // left/right
	-15, // up/down
	-23, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_081, // short name
	L_GUN_039, // name
	L_GUN_000, // manufacturer
	L_GUN_186, // description
	WEAPONFLAG_00000001 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00002000 | WEAPONFLAG_HASHANDS,
};

struct guncmd invanim_ecmmine_equiporreload[] = {
	gunscript_playanimation(0x0437, 0, 10000)
	gunscript_end
};

struct guncmd invanim_ecmmine_unequip[] = {
	gunscript_playanimation(0x0438, 0, 10000)
	gunscript_end
};

struct guncmd invanim_ecmmine_throw[] = {
	gunscript_playanimation(0x0438, 0, 10000)
	gunscript_waittime(23, 2)
	gunscript_end
};

struct weaponfunc_throw invfunc_ecmmine_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN_140, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_ecmmine_throw, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_00800000,
	0x00000116,
	240, // activatetime60
	60, // recoverytime60
	0, // damage
};

struct inventory_ammo invammo_ecmmine = {
	AMMOTYPE_ECM_MINE,
	CASING_NONE,
	1, // clip size
	invanim_ecmmine_equiporreload, // reload animation
	0x02, // flags
};

struct weapon invitem_ecmmine = {
	FILE_GECMMINE, // hi model
	FILE_GECMMINE, // lo model
	invanim_ecmmine_equiporreload, // equip animation
	invanim_ecmmine_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_ecmmine_throw, NULL }, // functions
	&invammo_ecmmine, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	14, // left/right
	-25, // up/down
	-31.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_041, // short name
	L_GUN_041, // name
	L_GUN_000, // manufacturer
	L_GUN_188, // description
	WEAPONFLAG_00000001 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_00002000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_DETERMINER_S_AN | WEAPONFLAG_DETERMINER_F_AN | WEAPONFLAG_08000000,
};

// Some unfinished Reaper-like gun. The name is "Timed Mine". The primary
// function is detonate (and it works). It can't shoot.
struct weapon invitem_unused_8007dd88 = {
	FILE_GSKMINIGUN, // hi model
	FILE_GSKMINIGUNLOD, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_remotemine_detonate, NULL }, // functions
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_038, // short name
	L_GUN_038, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_00000040 | WEAPONFLAG_08000000,
};

struct inventory_typef invf_00013df8[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_grenade_throw[] = {
	gunscript_playanimation(0x0426, 0, 10000)
	gunscript_popoutsackofpills(0x0006)
	gunscript_playsound(6, 0x05c1)
	gunscript_waitforzreleased(43)
	gunscript_waittime(49, 2)
	gunscript_end
};

struct guncmd invanim_grenade_equiporreload[] = {
	gunscript_playanimation(0x042b, 0, 10000)
	gunscript_end
};

struct weaponfunc_throw invfunc_grenade_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN_124, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_grenade_throw, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_NOMUZZLEFLASH,
	0x00000112,
	240, // activatetime60
	60, // recoverytime60
	0, // damage
};

struct weaponfunc_throw invfunc_grenade_pinball = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN_125, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_grenade_throw, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_NOMUZZLEFLASH,
	0x00000112,
	90, // activatetime60
	60, // recoverytime60
	0, // damage
};

struct inventory_ammo invammo_grenade = {
	AMMOTYPE_GRENADE,
	CASING_NONE,
	1, // clip size
	invanim_grenade_equiporreload, // reload animation
	0x0a, // flags
};

struct weapon invitem_grenade = {
	FILE_GGRENADE, // hi model
	FILE_GGRENADELOD, // lo model
	invanim_grenade_equiporreload, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_grenade_throw, &invfunc_grenade_pinball }, // functions
	&invammo_grenade, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	17, // left/right
	-19.7, // up/down
	-21, // front/back
	1, // unk38
	invf_00013df8, // fptr
	NULL, // part visibility
	L_GUN_036, // short name
	L_GUN_036, // name
	L_GUN_000, // manufacturer
	L_GUN_183, // description
	WEAPONFLAG_00000001 | WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS,
};

struct weaponfunc_throw invfunc_nbomb_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN_134, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_grenade_throw, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_MAKEDIZZY | FUNCFLAG_DROPWEAPON | FUNCFLAG_NOMUZZLEFLASH,
	0x00000110,
	240, // activatetime60
	60, // recoverytime60
	0, // damage
};

struct weaponfunc_throw invfunc_nbomb_proxy = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN_127, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_grenade_throw, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_MAKEDIZZY | FUNCFLAG_DROPWEAPON | FUNCFLAG_NOMUZZLEFLASH,
	0x00000110,
	240, // activatetime60
	60, // recoverytime60
	0, // damage
};

struct inventory_ammo invammo_nbomb = {
	AMMOTYPE_NBOMB,
	CASING_NONE,
	1, // clip size
	invanim_grenade_equiporreload, // reload animation
	0x0a, // flags
};

struct weapon invitem_nbomb = {
	FILE_GNBOMB, // hi model
	FILE_GNBOMBLOD, // lo model
	invanim_grenade_equiporreload, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_nbomb_throw, &invfunc_nbomb_proxy }, // functions
	&invammo_nbomb, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	17, // left/right
	-19.7, // up/down
	-21, // front/back
	1, // unk38
	invf_00013df8, // fptr
	NULL, // part visibility
	L_GUN_037, // short name
	L_GUN_037, // name
	L_GUN_000, // manufacturer
	L_GUN_184, // description
	WEAPONFLAG_00000001 | WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_DETERMINER_S_AN | WEAPONFLAG_DETERMINER_F_AN,
};

struct inventory_typef invf_00013fa4[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0028, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_farsight_reload[] = {
	gunscript_playanimation(0x03eb, 0, 10000)
	gunscript_showpart(1, 40)
	gunscript_playsound(72, 0x0433)
	gunscript_waittime(76, 1)
	gunscript_hidepart(82, 40)
	gunscript_end
};

struct guncmd invanim_farsight_equiporshoot[] = {
	gunscript_playanimation(0x03ec, 0, 10000)
	gunscript_end
};

struct inventory_class invclass_farsight = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x16000000,
	WEAPONCLASSFLAG_MANUALZOOM | WEAPONCLASSFLAG_00000004,
};

struct weaponfunc_shootsingle invfunc_farsight_shoot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_090, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_farsight_equiporshoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	100, // damage
	0, // spread
	70, 40, 0, 0,
	0,
	0,
	0,
	0,
	4,
	0x813e,
	5,
};

struct weaponfunc_shootsingle invfunc_farsight_targetlocator = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_111, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_farsight_equiporshoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	100, // damage
	0, // spread
	70, 40, 0, 0,
	0,
	0,
	0,
	0,
	4,
	0x813e,
	5,
};

struct inventory_ammo invammo_farsight = {
	AMMOTYPE_FARSIGHT,
	CASING_NONE,
	8, // clip size
	invanim_farsight_reload, // reload animation
	0, // flags
};

struct modelpartvisibility invpartvisibility_farsight[] = {
	{ MODELPART_NEWCLIP, false },
	{ 255 },
};

struct weapon invitem_farsight = {
	FILE_GZ2020, // hi model
	FILE_GZ2020LOD, // lo model
	invanim_farsight_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_farsight_shoot, &invfunc_farsight_targetlocator }, // functions
	&invammo_farsight, // pri ammo
	NULL, // sec ammo
	&invclass_farsight,
	6, // sway
	21.5, // left/right
	-25.2, // up/down
	-32.5, // front/back
	1, // unk38
	invf_00013fa4, // fptr
	invpartvisibility_farsight, // part visibility
	L_GUN_079, // short name
	L_GUN_031, // name
	L_GUN_000, // manufacturer
	L_GUN_178, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_HASHANDS,
};

struct inventory_typef invf_00014100[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x0029, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_crossbow_reload[] = {
	gunscript_playanimation(0x00d4, 0, 10000)
	gunscript_hidepart(1, 40)
	gunscript_showpart(1, 41)
	gunscript_showpart(1, 53)
	gunscript_hidepart(19, 40)
	gunscript_showpart(19, 41)
	gunscript_playsound(45, 0x04fc)
	gunscript_waittime(50, 1)
	gunscript_hidepart(50, 41)
	gunscript_showpart(50, 40)
	gunscript_repeatuntilfull(0x0044, 0x0000, 0x0013)
	gunscript_end
};

struct guncmd invanim_crossbow_shoot[] = {
	gunscript_playanimation(0x00c2, 0, 10000)
	gunscript_hidepart(20, 40)
	gunscript_playsound(37, 0x04f8)
	gunscript_end
};

struct guncmd invanim_crossbow_unequip[] = {
	gunscript_playanimation(0x00d3, 0, 10000)
	gunscript_hidepart(1, 40)
	gunscript_playsound(37, 0x04f8)
	gunscript_end
};

struct guncmd invanim_crosbow_equip[] = {
	gunscript_playanimation(0x00c1, 0, 10000)
	gunscript_playsound(32, 0x04fc)
	gunscript_playsound(75, 0x04f8)
	gunscript_end
};

struct weaponfunc_shootprojectile invfunc_crossbow_lethal = {
	INVENTORYFUNCTYPE_SHOOT_PROJECTILE,
	L_GUN_112, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_crossbow_shoot, // fire animation
	FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_00800000,
	NULL,
	0,
	100, // damage
	6, // spread
	3, 12, 15, 0,
	3,
	2,
	0,
	4,
	4,
	0x8056,
	1,
	0x00000121,
	0x00000000,
	0x40066666,
	0x00000000,
	0x00000000,
	0x0000003c,
	0xffffffff,
	0x3d4ccccd,
	0xffff0000,
};

struct weaponfunc_shootprojectile invfunc_crossbow_shoot = {
	INVENTORYFUNCTYPE_SHOOT_PROJECTILE,
	L_GUN_107, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_crossbow_shoot, // fire animation
	FUNCFLAG_MAKEDIZZY | FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_00800000,
	NULL,
	0,
	1, // damage
	6, // spread
	3, 12, 15, 0,
	3,
	2,
	0,
	4,
	4,
	0x8056,
	1,
	0x00000121,
	0x00000000,
	0x40066666,
	0x00000000,
	0x00000000,
	0x0000003c,
	0xffffffff,
	0x3d4ccccd,
	0xffff0000,
};

struct inventory_ammo invammo_crossbow = {
	AMMOTYPE_CROSSBOW,
	CASING_NONE,
	5, // clip size
	invanim_crossbow_reload, // reload animation
	0x04, // flags
};

struct modelpartvisibility invpartvisibility_crossbow[] = {
	{ MODELPART_NEWCLIP,  false },
	{ MODELPART_NEWCLIP2, false },
	{ MODELPART_NEWCLIP3, false },
	{ 255 },
};

struct weapon invitem_crossbow = {
	FILE_GCROSSBOW, // hi model
	FILE_GCROSSBOWLOD, // lo model
	invanim_crosbow_equip, // equip animation
	invanim_crossbow_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_crossbow_shoot, &invfunc_crossbow_lethal }, // functions
	&invammo_crossbow, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	11, // left/right
	-15, // up/down
	-21, // front/back
	1, // unk38
	invf_00014100, // fptr
	invpartvisibility_crossbow, // part visibility
	L_GUN_033, // short name
	L_GUN_033, // name
	L_GUN_000, // manufacturer
	L_GUN_180, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_HASHANDS,
};

struct inventory_typef invf_00014314[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0028, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_tranquilizer_lethalinject[] = {
	gunscript_playanimation(0x0411, 0, 10000)
	gunscript_waittime(18, 2)
	gunscript_end
};

struct guncmd invanim_tranquilizer_equiporshoot[] = {
	gunscript_playanimation(0x042d, 0, 10000)
	gunscript_waittime(7, 5)
	gunscript_end
};

struct guncmd invanim_tranquilizer_reload[] = {
	gunscript_playanimation(0x0410, 0, 10000)
	gunscript_showpart(1, 53)
	gunscript_showpart(1, 40)
	gunscript_showpart(1, 42)
	gunscript_hidepart(1, 41)
	gunscript_popoutsackofpills(0x0001)
	gunscript_setsoundspeed(3, 3500)
	gunscript_playsound(3, 0x8016)
	gunscript_waittime(39, 1)
	gunscript_hidepart(39, 42)
	gunscript_showpart(39, 41)
	gunscript_setsoundspeed(39, 3500)
	gunscript_playsound(39, 0x8083)
	gunscript_setsoundspeed(63, 2070)
	gunscript_playsound(63, 0x04f5)
	gunscript_setsoundspeed(72, 3000)
	gunscript_playsound(72, 0x00ba)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_tranquilizer_shoot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_107, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_tranquilizer_equiporshoot, // fire animation
	FUNCFLAG_MAKEDIZZY,
	&invmenupos_00011098,
	16,
	0.25, // damage
	3, // spread
	3, 5, 5, 0,
	1,
	0,
	59.999996185303,
	0,
	0,
	0x8057,
	1,
};

struct weaponfunc_close invfunc_tranquilizer_lethal = {
	INVENTORYFUNCTYPE_CLOSE,
	L_GUN_108, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_tranquilizer_lethalinject, // fire animation
	FUNCFLAG_NOMUZZLEFLASH,
	100, // damage
	60,
	0x00000069,
	0x00000069,
	0x00000069,
	0x41200000,
	0xc181999a,
	0x41200000,
	0xc181999a,
	0xbf800000,
	0xbf800000,
	0x40000000,
	0x40000000,
	0x00000000,
};

struct inventory_ammo invammo_tranquilizer = {
	AMMOTYPE_SEDATIVE,
	CASING_NONE,
	8, // clip size
	invanim_tranquilizer_reload, // reload animation
	0, // flags
};

struct modelpartvisibility invpartvisibility_tranquilizer[] = {
	{ MODELPART_NEWCLIP,  false },
	{ MODELPART_NEWCLIP2, false },
	{ MODELPART_NEWCLIP3, false },
	{ 255 },
};

struct weapon invitem_tranquilizer = {
	FILE_GDRUGGUN, // hi model
	FILE_GDRUGGUNLOD, // lo model
	invanim_tranquilizer_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_tranquilizer_shoot, &invfunc_tranquilizer_lethal }, // functions
	&invammo_tranquilizer, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	10, // left/right
	-15.2, // up/down
	-24, // front/back
	1, // unk38
	invf_00014314, // fptr
	invpartvisibility_tranquilizer, // part visibility
	PAL ? 0x4cf7 : L_GUN_034, // short name
	L_GUN_034, // name
	L_GUN_000, // manufacturer
	L_GUN_181, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS,
};

struct inventory_ammo invammo_psychosisgun = {
	AMMOTYPE_PSYCHOSIS,
	CASING_NONE,
	8, // clip size
	invanim_tranquilizer_reload, // reload animation
	0, // flags
};

struct weaponfunc_shootsingle invfunc_psychosisgun_shoot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_131, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_tranquilizer_equiporshoot, // fire animation
	FUNCFLAG_MAKEDIZZY | FUNCFLAG_00200000,
	&invmenupos_00011098,
	16,
	0.5, // damage
	3, // spread
	3, 5, 5, 0,
	1,
	0,
	59.999996185303,
	0,
	0,
	0x8057,
	1,
};

struct weapon invitem_psychosisgun = {
	FILE_GDRUGGUN, // hi model
	FILE_GDRUGGUNLOD, // lo model
	invanim_tranquilizer_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_psychosisgun_shoot, NULL }, // functions
	&invammo_psychosisgun, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	10, // left/right
	-16.2, // up/down
	-28.5, // front/back
	1, // unk38
	invf_00014314, // fptr
	invpartvisibility_tranquilizer, // part visibility
	L_GUN_082, // short name
	L_GUN_049, // name
	L_GUN_000, // manufacturer
	L_GUN_210, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS,
};

struct inventory_typef invf_00014590[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0029, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_sniperrifle_equip[] = {
	gunscript_playanimation(0x040c, 0, 10000)
	gunscript_end
};

struct guncmd invanim_sniperrifle_reload[] = {
	gunscript_playanimation(0x040f, 0, 10000)
	gunscript_setsoundspeed(22, 850)
	gunscript_playsound(22, 0x01d8)
	gunscript_showpart(42, 41)
	gunscript_hidepart(42, 40)
	gunscript_setsoundspeed(72, 850)
	gunscript_playsound(72, 0x80f6)
	gunscript_hidepart(72, 41)
	gunscript_showpart(72, 40)
	gunscript_waittime(72, 1)
	gunscript_end
};

struct inventory_class invclass_sniperrifle = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x15000000,
	WEAPONCLASSFLAG_MANUALZOOM | WEAPONCLASSFLAG_00000004,
};

struct weaponfunc_shootsingle invfunc_sniperrifle_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_085, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010ff8, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH,
	&invmenupos_00011098,
	16,
	1.2, // damage
	0, // spread
	6, 10, 0, 0,
	8,
	0,
	0,
	0,
	4,
	0x8058,
	1,
};

struct weaponfunc_special invfunc_sniperrifle_crouch = {
	INVENTORYFUNCTYPE_SPECIAL,
	L_GUN_130, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_AUTOSWITCHUNSELECTABLE,
	HANDATTACKTYPE_CROUCH,
	0x0000001e,
	0x00000000,
};

struct inventory_ammo invammo_sniperrifle = {
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	8, // clip size
	invanim_sniperrifle_reload, // reload animation
	0, // flags
};

struct modelpartvisibility invpartvisibility_sniperrifle[] = {
	{ MODELPART_NEWCLIP2, false },
	{ 255 },
};

struct weapon invitem_sniperrifle = {
	FILE_GSNIPERRIFLE, // hi model
	FILE_GSNIPERLOD, // lo model
	invanim_sniperrifle_equip, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_sniperrifle_singleshot, &invfunc_sniperrifle_crouch }, // functions
	&invammo_sniperrifle, // pri ammo
	NULL, // sec ammo
	&invclass_sniperrifle,
	6, // sway
	21, // left/right
	-27.2, // up/down
	-31.5, // front/back
	1, // unk38
	invf_00014590, // fptr
	invpartvisibility_sniperrifle, // part visibility
	PAL ? 0x4cfe : L_GUN_032, // short name
	L_GUN_032, // name
	L_GUN_000, // manufacturer
	L_GUN_179, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_HASHANDS,
};

struct guncmd invanim_laser_equip[] = {
	gunscript_playanimation(0x042e, 0, 10000)
	gunscript_end
};

struct guncmd invanim_laser_unequip[] = {
	gunscript_playanimation(0x042f, 0, 10000)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_laser_pulse = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_132, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	1, // damage
	0, // spread
	6, 18, 24, -1,
	0,
	0,
	0,
	0,
	3,
	0x8043,
	1,
};

struct weaponfunc_shootauto invfunc_laser_stream = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_133, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0, // flags
	&invmenupos_00011084,
	0,
	0.1, // damage
	0, // spread
	6, 18, 0, 6,
	4,
	3,
	0,
	0,
	3,
	0,
	1,
	3600,
	3600,
	NULL,
	NULL,
	0, 0,
};

struct weapon invitem_laser = {
	FILE_GLASER, // hi model
	FILE_GLASERLOD, // lo model
	invanim_laser_equip, // equip animation
	invanim_laser_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_laser_pulse, &invfunc_laser_stream }, // functions
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	3, // sway
	-12, // left/right
	-12.7, // up/down
	-21.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_047, // short name
	L_GUN_047, // name
	L_GUN_150, // manufacturer
	L_GUN_189, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_DONTCOUNTSHOTS | WEAPONFLAG_04000000,
};

struct modelpartvisibility invpartvisibility_classic[] = {
	{ MODELPART_MUZZLEFLASH, false },
	{ 255 },
};

struct inventory_typef invf_000147fc[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_pp9i_equiporshoot[] = {
	gunscript_playanimation(0x0440, 0, 10000)
	gunscript_waittime(10, 5)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_pp9i_shoot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_085, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_pp9i_equiporshoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	16,
	1, // damage
	1, // spread
	4, 8, 3, 0,
	3,
	10,
	29.999998092651,
	0,
	0,
	0x8069,
	1,
};

struct inventory_ammo invammo_pp9i = {
	AMMOTYPE_PISTOL,
	CASING_STANDARD,
	7, // clip size
	NULL, // reload animation
	0, // flags
};

struct weapon invitem_pp9i = {
	FILE_GWPPK, // hi model
	FILE_GWPPK, // lo model
	invanim_pp9i_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_pp9i_shoot, NULL }, // functions
	&invammo_pp9i, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	10, // left/right
	-14.8, // up/down
	-19, // front/back
	1, // unk38
	invf_000147fc, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN_050, // short name
	L_GUN_050, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_GANGSTA,
};

struct guncmd invanim_cc13_equiporshoot[] = {
	gunscript_playanimation(0x043f, 0, 10000)
	gunscript_waittime(10, 5)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_cc13_shoot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_085, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_cc13_equiporshoot, // fire animation
	0, // flags
	&invmenupos_00011098,
	16,
	1, // damage
	6, // spread
	4, 8, 3, 0,
	5,
	10,
	59.999996185303,
	0,
	0,
	0x806a,
	1,
};

struct inventory_ammo invammo_cc13 = {
	AMMOTYPE_PISTOL,
	CASING_STANDARD,
	8, // clip size
	NULL, // reload animation
	0, // flags
};

struct weapon invitem_cc13 = {
	FILE_GTT33, // hi model
	FILE_GTT33, // lo model
	invanim_cc13_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_cc13_shoot, NULL }, // functions
	&invammo_cc13, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	10, // left/right
	-17, // up/down
	-26.5, // front/back
	1, // unk38
	invf_000147fc, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN_051, // short name
	L_GUN_051, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_GANGSTA,
};

struct weaponfunc_shootauto invfunc_kl01313_shoot = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_086, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	0.6, // damage
	15, // spread
	0, 0, 0, 6,
	0,
	0,
	0,
	0,
	11,
	0x806b,
	1,
	450,
	450,
	NULL,
	NULL,
	0, 0,
};

struct inventory_ammo invammo_kl01313 = {
	AMMOTYPE_SMG,
	CASING_STANDARD,
	20, // clip size
	NULL, // reload animation
	0, // flags
};

struct weapon invitem_kl01313 = {
	FILE_GSKORPION, // hi model
	FILE_GSKORPION, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_kl01313_shoot, NULL }, // functions
	&invammo_kl01313, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	8.5, // left/right
	-13, // up/down
	-29.5, // front/back
	1, // unk38
	NULL, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN_052, // short name
	L_GUN_052, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00008000,
};

struct weaponfunc_shootauto invfunc_kf7special_shoot = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_087, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	FUNCFLAG_BURST3,
	&invmenupos_00011098,
	0,
	1, // damage
	10, // spread
	4, 12, 0, 6,
	4.5,
	2,
	0,
	3,
	4,
	0x806c,
	1,
	450,
	450,
	NULL,
	NULL,
	0, 0,
};

struct inventory_ammo invammo_kf7special = {
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	NULL, // reload animation
	0, // flags
};

struct weapon invitem_kf7special = {
	FILE_GAK47, // hi model
	FILE_GAK47, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_kf7special_shoot, NULL }, // functions
	&invammo_kf7special, // pri ammo
	NULL, // sec ammo
	&invclass_heavy,
	2, // sway
	13, // left/right
	-21, // up/down
	-13.5, // front/back
	1, // unk38
	NULL, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN_053, // short name
	L_GUN_053, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00008000,
};

struct weaponfunc_shootauto invfunc_zzt9mm_shoot = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_086, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	1, // damage
	9, // spread
	6, 18, 0, 6,
	4,
	3,
	0,
	0,
	4,
	0x806d,
	1,
	600,
	600,
	NULL,
	NULL,
	0, 0,
};

struct inventory_ammo invammo_zzt9mm = {
	AMMOTYPE_SMG,
	CASING_STANDARD,
	32, // clip size
	NULL, // reload animation
	0, // flags
};

struct weapon invitem_zzt9mm = {
	FILE_GUZI, // hi model
	FILE_GUZI, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_zzt9mm_shoot, NULL }, // functions
	&invammo_zzt9mm, // pri ammo
	NULL, // sec ammo
	&invclass_smg,
	0.5, // sway
	11, // left/right
	-24.5, // up/down
	-37, // front/back
	1, // unk38
	NULL, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN_054, // short name
	L_GUN_054, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00008000,
};

struct weaponfunc_shootauto invfunc_dmc_shoot = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_086, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	1, // damage
	7, // spread
	6, 18, 0, 6,
	4,
	3,
	0,
	0,
	4,
	0x806e,
	1,
	450,
	450,
	NULL,
	NULL,
	0, 0,
};

struct inventory_ammo invammo_dmc = {
	AMMOTYPE_SMG,
	CASING_STANDARD,
	30, // clip size
	NULL, // reload animation
	0, // flags
};

struct weapon invitem_dmc = {
	FILE_GMP5K, // hi model
	FILE_GMP5K, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_dmc_shoot, NULL }, // functions
	&invammo_dmc, // pri ammo
	NULL, // sec ammo
	&invclass_smg,
	1, // sway
	16.5, // left/right
	-22.9, // up/down
	-35, // front/back
	1, // unk38
	NULL, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN_055, // short name
	L_GUN_055, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00008000,
};

struct weaponfunc_shootauto invfunc_ar53_shoot = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_087, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	FUNCFLAG_BURST3,
	&invmenupos_00011098,
	0,
	1.4, // damage
	6, // spread
	6, 18, 2, 8,
	5,
	2,
	0,
	4,
	5,
	0x806f,
	1,
	550,
	550,
	NULL,
	NULL,
	0, 0,
};

struct inventory_ammo invammo_ar53 = {
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	NULL, // reload animation
	0, // flags
};

struct weapon invitem_ar53 = {
	FILE_GM16, // hi model
	FILE_GM16, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_ar53_shoot, NULL }, // functions
	&invammo_ar53, // pri ammo
	NULL, // sec ammo
	&invclass_heavy,
	6, // sway
	11, // left/right
	-19.2, // up/down
	-21.5, // front/back
	1, // unk38
	NULL, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN_056, // short name
	L_GUN_056, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00008000 | WEAPONFLAG_DETERMINER_S_AN | WEAPONFLAG_DETERMINER_F_AN,
};

struct weaponfunc_shootauto invfunc_rcp45_shoot = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_086, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	1.8, // damage
	6, // spread
	4, 8, 0, 3,
	3.5,
	2,
	0,
	4,
	2,
	0x8070,
	1,
	600,
	600,
	NULL,
	NULL,
	0, 0,
};

struct inventory_ammo invammo_rcp45 = {
	AMMOTYPE_SMG,
	CASING_STANDARD,
	80, // clip size
	NULL, // reload animation
	0, // flags
};

struct weapon invitem_rcp45 = {
	FILE_GFNP90, // hi model
	FILE_GFNP90, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_rcp45_shoot, NULL }, // functions
	&invammo_rcp45, // pri ammo
	NULL, // sec ammo
	&invclass_smg,
	4, // sway
	11, // left/right
	-22.3, // up/down
	-29, // front/back
	1, // unk38
	NULL, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN_057, // short name
	L_GUN_057, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00008000 | WEAPONFLAG_DETERMINER_S_AN | WEAPONFLAG_DETERMINER_F_AN,
};

struct weaponfunc invfunc_briefcase_use = {
	INVENTORYFUNCTYPE_NONE,
	L_GUN_000, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0, // flags
};

struct inventory_typef invf_unused_8006edcc[] = {
	{ 0x0000, 0x001e, 0x0000, 0x0002, 0x0001 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct weapon invitem_briefcase2 = {
	FILE_GFALCON2LOD, // hi model
	FILE_GFALCON2LOD, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_briefcase_use, &invfunc_briefcase_use }, // functions
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	12.5, // left/right
	-17, // up/down
	-27.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_071, // short name
	L_GUN_071, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_00000800 | WEAPONFLAG_HIDEMENUMODEL | WEAPONFLAG_DONTCOUNTSHOTS | WEAPONFLAG_DETERMINER_S_THE | WEAPONFLAG_DETERMINER_F_THE,
};

struct weaponfunc_shootauto invfunc_59_rapidfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_086, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	1, // damage
	6, // spread
	6, 18, 2, 8,
	5,
	2,
	0,
	4,
	4,
	0x8059,
	2,
	900,
	900,
	NULL,
	NULL,
	0, 0,
};

struct inventory_ammo invammo_59 = {
	AMMOTYPE_SMG,
	CASING_RIFLE,
	27, // clip size
	NULL, // reload animation
	0, // flags
};

struct weapon invitem_59 = {
	0, // hi model
	0, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_59_rapidfire, NULL }, // functions
	&invammo_59, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	16.5, // left/right
	-19.5, // up/down
	-24, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_000, // short name
	L_GUN_000, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_DUALWIELD,
};

struct weaponfunc_shootauto invfunc_5a_rapidfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN_086, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0, // flags
	&invmenupos_00011098,
	0,
	1, // damage
	6, // spread
	6, 18, 2, 8,
	5,
	2,
	0,
	4,
	4,
	0x803f,
	1,
	900,
	900,
	NULL,
	NULL,
	0, 0,
};

struct inventory_ammo invammo_5a = {
	AMMOTYPE_SMG,
	CASING_RIFLE,
	27, // clip size
	NULL, // reload animation
	0, // flags
};

struct weapon invitem_5a = {
	0, // hi model
	0, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_5a_rapidfire, NULL }, // functions
	&invammo_5a, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	16.5, // left/right
	-19.5, // up/down
	-24, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_000, // short name
	L_GUN_000, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_DUALWIELD,
};

struct inventory_typef invf_00014fc0[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

struct guncmd invanim_combatknife_equip[] = {
	gunscript_playanimation(0x0403, 0, 10000)
	gunscript_waittime(24, 2)
	gunscript_end
};

struct guncmd invanim_combatknife_slash2[] = {
	gunscript_playanimation(0x0404, 0, 10000)
	gunscript_waittime(24, 2)
	gunscript_end
};

struct guncmd invanim_combatknife_slash[] = {
	gunscript_random(50, invanim_combatknife_slash2)
	gunscript_include(0, invanim_combatknife_equip)
	gunscript_end
};

struct guncmd invanim_combatknife_pritosec[] = {
	gunscript_playanimation(0x0405, 0, 10000)
	gunscript_playsound(30, 0x80a7)
	gunscript_playsound(40, 0x80a6)
	gunscript_end
};

struct guncmd invanim_combatknife_sectopri[] = {
	gunscript_playanimation(0x0405, 65535, 55536)
	gunscript_playsound(10, 0x80a8)
	gunscript_playsound(20, 0x80a6)
	gunscript_end
};

struct guncmd invanim_combatknife_throw[] = {
	gunscript_playanimation(0x041b, 0, 10000)
	gunscript_waitforzreleased(12)
	gunscript_waittime(16, 2)
	gunscript_end
};

struct guncmd invanim_unused_8007f05c[] = {
	gunscript_playanimation(0x041c, 0, 10000)
	gunscript_waittime(22, 1)
	gunscript_end
};

struct guncmd invanim_combatknife_reload[] = {
	gunscript_include(2, invanim_combatknife_sectopri)
	gunscript_include(0, invanim_combatknife_pritosec)
	gunscript_end
};

struct weaponfunc_close invfunc_combatknife_slash = {
	INVENTORYFUNCTYPE_CLOSE,
	L_GUN_109, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_combatknife_slash, // fire animation
	FUNCFLAG_NOMUZZLEFLASH,
	2, // damage
	70,
	0x00000069,
	0x00000069,
	0x00000069,
	0x41300000,
	0xc1cc0000,
	0x41300000,
	0xc1cc0000,
	0xbf800000,
	0xbf800000,
	0x40000000,
	0x40000000,
	0x00000000,
};

struct weaponfunc_throw invfunc_combatknife_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN_110, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_combatknife_throw, // fire animation
	FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_00800000,
	0x0000010f,
	240, // activatetime60
	60, // recoverytime60
	1, // damage
};

struct inventory_ammo invammo_combatknife = {
	AMMOTYPE_KNIFE,
	CASING_NONE,
	1, // clip size
	invanim_combatknife_reload, // reload animation
	0x0a, // flags
};

struct weapon invitem_combatknife = {
	FILE_GKNIFE, // hi model
	FILE_GKNIFELOD, // lo model
	invanim_combatknife_equip, // equip animation
	NULL, // unequip animation
	invanim_combatknife_pritosec, // pritosec animation
	invanim_combatknife_sectopri, // sectopri animation
	{ &invfunc_combatknife_slash, &invfunc_combatknife_throw }, // functions
	&invammo_combatknife, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	18.5, // left/right
	-26.5, // up/down
	-28, // front/back
	1, // unk38
	invf_00014fc0, // fptr
	NULL, // part visibility
	L_GUN_083, // short name
	L_GUN_035, // name
	L_GUN_000, // manufacturer
	L_GUN_182, // description
	WEAPONFLAG_00000001 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_TRACKTIMEUSED | WEAPONFLAG_00000400 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_00008000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_04000000,
};

struct weaponfunc_throw invfunc_bug_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN_000, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_00800000,
	0x00000012,
	240, // activatetime60
	60, // recoverytime60
	0, // damage
};

struct weaponfunc_throw invfunc_targetamplifier_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN_000, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_00800000,
	0x000001b1,
	240, // activatetime60
	60, // recoverytime60
	0, // damage
};

struct inventory_ammo invammo_bug = {
	AMMOTYPE_BUG,
	CASING_NONE,
	1, // clip size
	NULL, // reload animation
	0x02, // flags
};

struct weapon invitem_commsrider = {
	FILE_PCHRBUG, // hi model
	FILE_PCHRBUG, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_bug_throw, NULL }, // functions
	&invammo_bug, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_222, // short name
	L_GUN_222, // name
	L_GUN_000, // manufacturer
	L_GUN_204, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_08000000,
};

struct weapon invitem_tracerbug = {
	FILE_PCHRBUG, // hi model
	FILE_PCHRBUG, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_bug_throw, NULL }, // functions
	&invammo_bug, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_223, // short name
	L_GUN_223, // name
	L_GUN_000, // manufacturer
	L_GUN_205, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_08000000,
};

struct weapon invitem_targetamplifier = {
	FILE_PTARGETAMP, // hi model
	FILE_PTARGETAMP, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_targetamplifier_throw, NULL }, // functions
	&invammo_bug, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_235, // short name
	L_GUN_224, // name
	L_GUN_000, // manufacturer
	L_GUN_206, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_08000000,
};

struct weaponfunc_device invfunc_nightvision_primary = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN_135, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH,
	DEVICE_NIGHTVISION,
};

struct weapon invitem_nightvision = {
	FILE_PCHRNIGHTSIGHT, // hi model
	FILE_PCHRNIGHTSIGHT, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_nightvision_primary, NULL }, // functions
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	PAL ? 0x4cf4 : L_GUN_059, // short name
	L_GUN_059, // name
	L_GUN_000, // manufacturer
	L_GUN_191, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_00000080 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_08000000,
};

struct weaponfunc invfunc_horizonscanner_primary = {
	INVENTORYFUNCTYPE_NONE,
	L_GUN_139, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0, // flags
};

struct inventory_class invclass_horizonscanner = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x05000000,
	WEAPONCLASSFLAG_MANUALZOOM | WEAPONCLASSFLAG_00000004,
};

struct weapon invitem_horizonscanner = {
	FILE_PBINOCULARS, // hi model
	FILE_PBINOCULARS, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_horizonscanner_primary, NULL }, // functions
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_horizonscanner,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_234, // short name
	L_GUN_076, // name
	L_GUN_000, // manufacturer
	L_GUN_196, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_DETERMINER_S_AN | WEAPONFLAG_DETERMINER_F_AN | WEAPONFLAG_08000000,
};

struct weaponfunc_device invfunc_cloak_primary = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN_116, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH,
	DEVICE_CLOAKDEVICE,
};

struct inventory_ammo invammo_cloakingdevice = {
	AMMOTYPE_CLOAK,
	CASING_NONE,
	10, // clip size
	NULL, // reload animation
	0x01, // flags
};

struct weapon invitem_cloakingdevice = {
	FILE_PCHRCLOAKER, // hi model
	FILE_PCHRCLOAKER, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_cloak_primary, NULL }, // functions
	&invammo_cloakingdevice, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_073, // short name
	L_GUN_073, // name
	L_GUN_000, // manufacturer
	L_GUN_195, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_04000000,
};

struct weaponfunc_special invfunc_combatboost_boost = {
	INVENTORYFUNCTYPE_SPECIAL,
	L_GUN_113, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH,
	HANDATTACKTYPE_BOOST,
	0x0000001e,
	0x05c90000,
};

struct weaponfunc_special invfunc_combatboost_revert = {
	INVENTORYFUNCTYPE_SPECIAL,
	L_GUN_114, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH,
	HANDATTACKTYPE_REVERTBOOST,
	0x0000001e,
	0x05c90000,
};

struct inventory_ammo invammo_combatboost = {
	AMMOTYPE_BOOST,
	CASING_NONE,
	4, // clip size
	NULL, // reload animation
	0x01, // flags
};

struct weapon invitem_combatboost = {
	FILE_PCHRSPEEDPILL, // hi model
	FILE_PCHRSPEEDPILL, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_combatboost_boost, &invfunc_combatboost_revert }, // functions
	&invammo_combatboost, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_232, // short name
	L_GUN_074, // name
	L_GUN_000, // manufacturer
	L_GUN_190, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_04000000 | WEAPONFLAG_DETERMINER_S_SOME | WEAPONFLAG_DETERMINER_F_SOME,
};

struct weaponfunc_device invfunc_suicidepill_primary = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN_000, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH,
	DEVICE_SUICIDEPILL,
};

struct weapon invitem_suicidepill = {
	0, // hi model
	0, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_suicidepill_primary, NULL }, // functions
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	PAL ? 0x4cf6 : L_GUN_072, // short name
	L_GUN_072, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_08000000,
};

struct weaponfunc_device invfunc_irscanner_primary = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN_138, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH,
	DEVICE_IRSCANNER,
};

struct weapon invitem_irscanner = {
	FILE_GIRSCANNER, // hi model
	FILE_GIRSCANNER, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_irscanner_primary, NULL }, // functions
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_069, // short name
	L_GUN_069, // name
	L_GUN_000, // manufacturer
	L_GUN_194, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_DUALWIELD | WEAPONFLAG_08000000,
};

struct weaponfunc invfunc_disguise_primary = {
	INVENTORYFUNCTYPE_NONE,
	L_GUN_143, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0, // flags
};

struct weapon invitem_disguise40 = {
	0, // hi model
	0, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_disguise_primary, NULL }, // functions
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	PAL ? 0x4cfa : L_GUN_043, // short name
	L_GUN_043, // name
	L_GUN_000, // manufacturer
	L_GUN_211, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_08000000 | WEAPONFLAG_FIRETOACTIVATE,
};

struct weapon invitem_disguise41 = {
	0, // hi model
	0, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_disguise_primary, NULL }, // functions
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	PAL ? 0x4cfa : L_GUN_043, // short name
	L_GUN_043, // name
	L_GUN_000, // manufacturer
	L_GUN_211, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_08000000 | WEAPONFLAG_FIRETOACTIVATE,
};

struct weaponfunc_device invfunc_camspy_deploy = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN_136, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH,
	DEVICE_EYESPY,
};

struct weapon invitem_camspy = {
	FILE_CEYESPY, // hi model
	FILE_CEYESPY, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_camspy_deploy, NULL }, // functions
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_060, // short name
	L_GUN_060, // name
	L_GUN_000, // manufacturer
	L_GUN_192, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALWIELD | WEAPONFLAG_08000000,
};

struct weaponfunc_device invfunc_rtracker_primary = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN_142, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH,
	DEVICE_RTRACKER,
};

struct weapon invitem_rtracker = {
	FILE_PRUSSDAR, // hi model
	FILE_PRUSSDAR, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_rtracker_primary, NULL }, // functions
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_070, // short name
	L_GUN_070, // name
	L_GUN_000, // manufacturer
	L_GUN_198, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALWIELD | WEAPONFLAG_08000000,
};

struct weaponfunc_device invfunc_xray_primary = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN_137, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH,
	DEVICE_XRAYSCANNER,
};

struct weapon invitem_xrayscanner = {
	FILE_PXRAYSPECS, // hi model
	FILE_PXRAYSPECS, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_xray_primary, NULL }, // functions
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_233, // short name
	L_GUN_065, // name
	L_GUN_000, // manufacturer
	L_GUN_193, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_00000040 | WEAPONFLAG_DETERMINER_S_AN | WEAPONFLAG_DETERMINER_F_AN | WEAPONFLAG_08000000,
};

struct guncmd invanim_datauplink_equip[] = {
	gunscript_playanimation(0x0439, 0, 10000)
	gunscript_end
};

struct guncmd invanim_datauplink_unequip[] = {
	gunscript_playanimation(0x043a, 0, 10000)
	gunscript_end
};

struct guncmd invanim_unused_8007f794[] = {
	gunscript_playanimation(0x043b, 0, 10000)
	gunscript_end
};

struct weaponfunc_special invfunc_datauplink_primary = {
	INVENTORYFUNCTYPE_SPECIAL,
	L_GUN_141, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_AUTOSWITCHUNSELECTABLE,
	HANDATTACKTYPE_UPLINK,
	0x0000001e,
	0x00000000,
};

struct weapon invitem_datauplink = {
	FILE_GCOMMSUPLINK, // hi model
	FILE_GCOMMSUPLINK, // lo model
	invanim_datauplink_equip, // equip animation
	invanim_datauplink_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_datauplink_primary, NULL }, // functions
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	8, // left/right
	-16.2, // up/down
	-17.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	PAL ? 0x4cf3 : L_GUN_075, // short name
	L_GUN_075, // name
	L_GUN_000, // manufacturer
	L_GUN_197, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_00000040 | WEAPONFLAG_00002000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_08000000 | WEAPONFLAG_FIRETOACTIVATE,
};

struct weapon invitem_doordecoder = {
	FILE_PCHRDOORDECODER, // hi model
	FILE_PCHRDOORDECODER, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	35, // left/right
	-26.7, // up/down
	-41, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	PAL ? 0x4cf5 : L_GUN_063, // short name
	L_GUN_063, // name
	L_GUN_000, // manufacturer
	L_GUN_200, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_08000000 | WEAPONFLAG_FIRETOACTIVATE,
};

struct weapon invitem_rocket = {
	FILE_GCYCLONE, // hi model
	FILE_GCYCLONELOD, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	&invammo_default, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	12.5, // left/right
	-17, // up/down
	-27.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_044, // short name
	L_GUN_044, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	0, // flags
};

struct weapon invitem_homingrocket = {
	FILE_GCYCLONE, // hi model
	FILE_GCYCLONELOD, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	&invammo_default, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	12.5, // left/right
	-17, // up/down
	-27.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_045, // short name
	L_GUN_045, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	0, // flags
};

struct weapon invitem_grenaderound = {
	FILE_GCYCLONE, // hi model
	FILE_GCYCLONELOD, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_devastator_shoot, &invfunc_devastator_wallhugger }, // functions
	&invammo_default, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	12.5, // left/right
	-17, // up/down
	-27.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_046, // short name
	L_GUN_046, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	0, // flags
};

struct weapon invitem_bolt = {
	FILE_GCYCLONE, // hi model
	FILE_GCYCLONELOD, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_crossbow_shoot, &invfunc_crossbow_lethal }, // functions
	&invammo_default, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	12.5, // left/right
	-17, // up/down
	-27.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_048, // short name
	L_GUN_048, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	0, // flags
};

struct weaponfunc_special invfunc_unused_8006f9a4 = {
	INVENTORYFUNCTYPE_SPECIAL,
	L_GUN_144, // "Place Explosives"
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH | FUNCFLAG_AUTOSWITCHUNSELECTABLE,
	HANDATTACKTYPE_UPLINK,
	0x0000001e,
	0x00000000,
};

struct weapon invitem_skedarbomb = {
	FILE_PSKEDARBOMB, // hi model
	FILE_PSKEDARBOMB, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_221, // short name
	L_GUN_221, // name
	L_GUN_000, // manufacturer
	L_GUN_203, // description
	WEAPONFLAG_FIRETOACTIVATE,
};

struct weapon invitem_explosives = {
	FILE_PEXPLOSIVEBRICK, // hi model
	FILE_PEXPLOSIVEBRICK, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_064, // short name
	L_GUN_064, // name
	L_GUN_000, // manufacturer
	L_GUN_202, // description
	WEAPONFLAG_FIRETOACTIVATE,
};

struct weaponfunc_device invfunc_presidentscanner_primary = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN_142, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	FUNCFLAG_NOMUZZLEFLASH,
	DEVICE_RTRACKER,
};

struct weapon invitem_presidentscanner = {
	FILE_PRUSSDAR, // hi model
	FILE_PRUSSDAR, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_presidentscanner_primary, NULL }, // functions
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_231, // short name
	L_GUN_219, // name
	L_GUN_000, // manufacturer
	L_GUN_199, // description
	WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALWIELD | WEAPONFLAG_08000000,
};

struct weapon invitem_autosurgeon = {
	FILE_PAUTOSURGEON, // hi model
	FILE_PAUTOSURGEON, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	PAL ? 0x4cf8 : L_GUN_220, // short name
	L_GUN_220, // name
	L_GUN_000, // manufacturer
	L_GUN_201, // description
	WEAPONFLAG_08000000 | WEAPONFLAG_FIRETOACTIVATE,
};

struct weapon invitem_flightplans = {
	FILE_PSAFEITEM, // hi model
	FILE_PSAFEITEM, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_225, // short name
	L_GUN_225, // name
	L_GUN_000, // manufacturer
	L_GUN_207, // description
	WEAPONFLAG_08000000,
};

struct weapon invitem_researchtape = {
	FILE_PRESEARCHTAPE, // hi model
	FILE_PRESEARCHTAPE, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_226, // short name
	L_GUN_226, // name
	L_GUN_000, // manufacturer
	L_GUN_208, // description
	WEAPONFLAG_08000000,
};

struct weapon invitem_backupdisk = {
	FILE_PZIGGYCARD, // hi model
	FILE_PZIGGYCARD, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	PAL ? 0x4cf9 : L_GUN_227, // short name
	L_GUN_227, // name
	L_GUN_000, // manufacturer
	L_GUN_209, // description
	WEAPONFLAG_08000000,
};

struct weapon invitem_briefcase = {
	FILE_PKEYCARD, // hi model
	FILE_PKEYCARD, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_229, // short name
	L_GUN_229, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_HIDEMENUMODEL | WEAPONFLAG_08000000,
};

struct weapon invitem_suitcase = {
	FILE_PCHRBRIEFCASE, // hi model
	FILE_PCHRBRIEFCASE, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_067, // short name
	L_GUN_067, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_08000000 | WEAPONFLAG_FIRETOACTIVATE,
};

struct weapon invitem_necklace = {
	FILE_PCHRCHAIN, // hi model
	FILE_PCHRCHAIN, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_230, // short name
	L_GUN_230, // name
	L_GUN_000, // manufacturer
	L_GUN_238, // description
	WEAPONFLAG_08000000,
};

struct weapon invitem_shield = {
	FILE_PCHRSHIELD, // hi model
	FILE_PCHRSHIELD, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_240, // short name
	L_GUN_240, // name
	L_GUN_000, // manufacturer
	L_GUN_241, // description
	WEAPONFLAG_08000000,
};

struct weapon invitem_keycard = {
	FILE_PKEYCARD, // hi model
	FILE_PKEYCARD, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_228, // short name
	L_GUN_228, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_08000000,
};

struct weaponfunc_shootprojectile invfunc_rocketlauncher34_primary = {
	INVENTORYFUNCTYPE_SHOOT_PROJECTILE,
	L_GUN_000, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_rockerlauncher_equiporshoot, // fire animation
	FUNCFLAG_NOAUTOAIM | FUNCFLAG_08000000,
	NULL,
	0,
	1, // damage
	6, // spread
	3, 12, 15, 0,
	3,
	2,
	0,
	4,
	4,
	0x8053,
	1,
	0x0000011f,
	0x00000000,
	0x40066666,
	0x00000014,
	0x00000000,
	0x00000000,
	0xffffffff,
	0x3d4ccccd,
	0x80530000,
};

struct inventory_ammo invammo_rocketlauncher34 = {
	AMMOTYPE_ROCKET,
	CASING_NONE,
	1, // clip size
	invanim_rocketlauncher_reload, // reload animation
	0, // flags
};

struct weapon invitem_rocketlauncher_34 = {
	FILE_GDYROCKET, // hi model
	FILE_GROCKETLOD, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_rocketlauncher34_primary, NULL }, // functions
	&invammo_rocketlauncher34, // pri ammo
	NULL, // sec ammo
	&invclass_rocketlauncher,
	1, // sway
	24.5, // left/right
	-25.2, // up/down
	-30, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_080, // short name
	L_GUN_027, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_00002000 | WEAPONFLAG_00004000 | WEAPONFLAG_HASHANDS | WEAPONFLAG_AIMTRACK,
};

struct guncmd invanim_tester_shoot[] = {
	gunscript_playanimation(0x0112, 0, 10000)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_tester_primary = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN_000, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_tester_shoot, // fire animation
	0, // flags
	&invmenupos_00011070,
	16,
	1, // damage
	6, // spread
	4, 8, 3, 0,
	0,
	0,
	59.999996185303,
	0,
	0,
	0x804d,
	1,
};

struct inventory_ammo invammo_tester = {
	AMMOTYPE_PISTOL,
	CASING_STANDARD,
	8, // clip size
	NULL, // reload animation
	0, // flags
};

struct weapon invitem_tester = {
	FILE_GTESTGUN, // hi model
	FILE_GTESTGUN, // lo model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_tester_primary, NULL }, // functions
	&invammo_tester, // pri ammo
	NULL, // sec ammo
	&invclass_default,
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN_058, // short name
	L_GUN_058, // name
	L_GUN_000, // manufacturer
	L_GUN_000, // description
	WEAPONFLAG_00000004 | WEAPONFLAG_ONEHANDED | WEAPONFLAG_AICANUSE | WEAPONFLAG_DUALFLIP | WEAPONFLAG_00000040 | WEAPONFLAG_00000400 | WEAPONFLAG_00002000 | WEAPONFLAG_00008000,
};

struct weapon *g_Weapons[] = {
	&invitem_nothing,
	&invitem_unarmed,
	&invitem_falcon2,
	&invitem_falcon2silencer,
	&invitem_falcon2scope,
	&invitem_magsec,
	&invitem_mauler,
	&invitem_phoenix,
	&invitem_dy357,
	&invitem_dy357lx,
	&invitem_cmp150,
	&invitem_cyclone,
	&invitem_callisto,
	&invitem_rcp120,
	&invitem_laptopgun,
	&invitem_dragon,
	&invitem_k7avenger,
	&invitem_ar34,
	&invitem_superdragon,
	&invitem_shotgun,
	&invitem_reaper,
	&invitem_sniperrifle,
	&invitem_farsight,
	&invitem_devastator,
	&invitem_rocketlauncher,
	&invitem_slayer,
	&invitem_combatknife,
	&invitem_crossbow,
	&invitem_tranquilizer,
	&invitem_laser,
	&invitem_grenade,
	&invitem_nbomb,
	&invitem_timedmine,
	&invitem_proximitymine,
	&invitem_remotemine,
	&invitem_combatboost,
	&invitem_pp9i,
	&invitem_cc13,
	&invitem_kl01313,
	&invitem_kf7special,
	&invitem_zzt9mm,
	&invitem_dmc,
	&invitem_ar53,
	&invitem_rcp45,
	&invitem_psychosisgun,
	&invitem_nightvision,
	&invitem_camspy,
	&invitem_xrayscanner,
	&invitem_irscanner,
	&invitem_cloakingdevice,
	&invitem_horizonscanner,
	&invitem_tester,
	&invitem_rocketlauncher_34,
	&invitem_ecmmine,
	&invitem_datauplink,
	&invitem_rtracker,
	&invitem_presidentscanner,
	&invitem_doordecoder,
	&invitem_autosurgeon,
	&invitem_explosives,
	&invitem_skedarbomb,
	&invitem_commsrider,
	&invitem_tracerbug,
	&invitem_targetamplifier,
	&invitem_disguise40,
	&invitem_disguise41,
	&invitem_flightplans,
	&invitem_researchtape,
	&invitem_backupdisk,
	&invitem_keycard,
	&invitem_keycard,
	&invitem_keycard,
	&invitem_keycard,
	&invitem_keycard,
	&invitem_keycard,
	&invitem_keycard,
	&invitem_keycard,
	&invitem_suitcase,
	&invitem_briefcase,
	&invitem_shield,
	&invitem_necklace,
	&invitem_hammer,
	&invitem_hammer,
	&invitem_rocket,
	&invitem_homingrocket,
	&invitem_grenaderound,
	&invitem_bolt,
	&invitem_briefcase2,
	&invitem_rocket,
	&invitem_59,
	&invitem_5a,
	&invitem_hammer,
	&invitem_hammer,
	&invitem_suicidepill,
};
