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

struct inventory_typee inve_000110c0 = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x10000000,
	0x00000002,
};

struct inventory_typee inve_000110e0 = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x10000000,
	0x00000006,
};

struct inventory_typee inve_00011100 = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x07000000,
	0x00000002,
};

struct inventory_typee inve_00011120 = {
	30,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x15000000,
	0x00000002,
};

struct inventory_typee inve_00011140 = {
	30,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x15000000,
	0x00000006,
};

struct weaponfunc_shootsingle invfunc_00011160 = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(85), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	1, // damage
	0x40c00000,
	6, 18, 2, 8,
	0x40a00000,
	0x40000000,
	0x00000000,
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
	0, // style
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
	&inve_000110c0, // eptr
	1, // sway
	12.5, // left/right
	-17, // up/down
	-27.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(0), // short name
	L_GUN(0), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x00001258, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	12.5, // left/right
	-17, // up/down
	-27.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(0), // short name
	L_GUN(0), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x00001000, // flags
};

u32 invanim_punch_type3[] = {
	gunscript_playanimation(0x03e9, 0, 10000)
	gunscript_waittime(7, 2)
	gunscript_end
};

u32 invanim_punch_type1[] = {
	gunscript_playanimation(0x03ea, 0, 10000)
	gunscript_waittime(8, 2)
	gunscript_end
};

u32 invanim_punch_type2[] = {
	gunscript_playanimation(0x041f, 0, 10000)
	gunscript_waittime(7, 2)
	gunscript_end
};

u32 invanim_punch_type4[] = {
	gunscript_playanimation(0x0425, 0, 10000)
	gunscript_waittime(8, 2)
	gunscript_waittime(18, 3)
	gunscript_end
};

u32 invanim_punch[] = {
	gunscript_random(20, invanim_punch_type1)
	gunscript_random(40, invanim_punch_type2)
	gunscript_random(60, invanim_punch_type3)
	gunscript_include(0, invanim_punch_type4)
	gunscript_end
};

struct weaponfunc_close invfunc_unarmed_punch = {
	INVENTORYFUNCTYPE_CLOSE,
	L_GUN(100), // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_punch, // fire animation
	0x0041a200, // flags
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
	L_GUN(101), // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_punch, // fire animation
	0x0041a600, // flags
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
	&inve_00011100, // eptr
	1, // sway
	7.5, // left/right
	-41, // up/down
	-16, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(6), // short name
	L_GUN(6), // name
	L_GUN(0), // manufacturer
	L_GUN(155), // description
	0x08042258, // flags
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

u32 invanim_falcon2_reload_0[] = {
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

u32 invanim_falcon2scope_reload_0[] = {
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

u32 invanim_falcon2_reload_1[] = {
	gunscript_playanimation(0x03f1, 0, 10000)
	gunscript_hidepart(1, 43)
	gunscript_showpart(1, 42)
	gunscript_playsound(6, 0x01d8)
	gunscript_waittime(50, 1)
	gunscript_playsound(50, 0x80f6)
	gunscript_playsound(71, 0x01db)
	gunscript_end
};

u32 invanim_falcon2_reload[] = {
	gunscript_include(1, invanim_falcon2_reload_1)
	gunscript_include(0, invanim_falcon2_reload_0)
	gunscript_end
};

u32 invanim_falcon2scope_reload[] = {
	gunscript_include(1, invanim_falcon2_reload_1)
	gunscript_include(0, invanim_falcon2scope_reload_0)
	gunscript_end
};

u32 invanim_falcon2_pistolwhip[] = {
	gunscript_playanimation(0x03f2, 0, 10000)
	gunscript_waittime(23, 2)
	gunscript_end
};

u32 invanim_falcon2_equip[] = {
	gunscript_playanimation(0x00ea, 0, 10000)
	gunscript_end
};

u32 invanim_falcon2_unequip[] = {
	gunscript_playanimation(0x00eb, 0, 10000)
	gunscript_end
};

u32 invanim_falcon2_shoot[] = {
	gunscript_playanimation(0x00ec, 0, 10000)
	gunscript_waittime(9, 5)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_falcon2_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(85), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_falcon2_shoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x10000000,
	1, // damage
	0x3f800000,
	3, 5, 2, 0,
	0x41200000,
	0x41700000,
	0x426fffff,
	0,
	0,
	0x804d,
	1,
};

struct weaponfunc_shootsingle invfunc_falcon2silenced_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(85), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_falcon2_shoot, // fire animation
	0x00002000, // flags
	&invmenupos_00011098,
	0x10000000,
	1, // damage
	0x3f800000,
	3, 5, 2, 0,
	0x41200000,
	0x41700000,
	0x426fffff,
	0,
	0,
	0x8054,
	1,
};

struct weaponfunc_close invfunc_falcon2_pistolwhip = {
	INVENTORYFUNCTYPE_CLOSE,
	L_GUN(94), // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_falcon2_pistolwhip, // fire animation
	0x0041a200, // flags
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
	0, // style
};

struct inventory_ammo invammo_falcon2scope = {
	AMMOTYPE_PISTOL,
	CASING_STANDARD,
	8, // clip size
	invanim_falcon2scope_reload, // reload animation
	0, // style
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
	&inve_000110c0, // eptr
	2, // sway
	9, // left/right
	-15.7, // up/down
	-23.8, // front/back
	1, // unk38
	invf_000113f4, // fptr
	invpartvisibility_falcon2, // part visibility
	L_GUN(7), // short name
	L_GUN(7), // name
	L_GUN(150), // manufacturer
	L_GUN(156), // description
	0x000ab67c, // flags
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
	&inve_00011120, // eptr
	1, // sway
	9, // left/right
	-15.7, // up/down
	-23.8, // front/back
	1, // unk38
	invf_00011444, // fptr
	invpartvisibility_falcon2scope, // part visibility
	L_GUN(77), // short name
	L_GUN(9), // name
	L_GUN(150), // manufacturer
	L_GUN(158), // description
	0x0002b67c, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	9, // left/right
	-15.7, // up/down
	-23.8, // front/back
	1, // unk38
	invf_0001148c, // fptr
	invpartvisibility_falcon2silencer, // part visibility
	L_GUN(78), // short name
	L_GUN(8), // name
	L_GUN(150), // manufacturer
	L_GUN(157), // description
	0x000ab67c, // flags
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

u32 invanim_magsec_reload_0[] = {
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

u32 invanim_magsec_reload_1[] = {
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

u32 invanim_magsec_reload[] = {
	gunscript_include(1, invanim_magsec_reload_1)
	gunscript_include(0, invanim_magsec_reload_0)
	gunscript_end
};

u32 invanim_magsec_equiporshoot[] = {
	gunscript_playanimation(0x040b, 0, 10000)
	gunscript_waittime(12, 5)
	gunscript_end
};

struct inventory_typee inve_00011970 = {
	25,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x11000000,
	0x00000002,
};

struct weaponfunc_shootsingle invfunc_magsec_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(85), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_magsec_equiporshoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x10000000,
	1.1, // damage
	0x40c00000,
	4, 8, 3, 0,
	0x40a00000,
	0x41200000,
	0x426fffff,
	10,
	0,
	0x804c,
	1,
};

struct weaponfunc_shootsingle invfunc_magsec_burst = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(128), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_magsec_equiporshoot, // fire animation
	0x00000002, // flags
	&invmenupos_00011098,
	0x10000000,
	1.1, // damage
	0x41200000,
	9, 14, 0, 0,
	0x41000000,
	0x41400000,
	0x426fffff,
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
	0, // style
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
	&inve_00011970, // eptr
	2, // sway
	10.5, // left/right
	-17.2, // up/down
	-26.5, // front/back
	1, // unk38
	invf_00011840, // fptr
	invpartvisibility_magsec, // part visibility
	L_GUN(10), // short name
	L_GUN(10), // name
	L_GUN(151), // manufacturer
	L_GUN(159), // description
	0x000a767c, // flags
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

u32 invanim_dy357_equiporshoot[] = {
	gunscript_playanimation(0x0406, 0, 10000)
	gunscript_waittime(12, 5)
	gunscript_waittime(12, 2)
	gunscript_end
};

u32 invanim_dy357_reload_0[] = {
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

u32 invanim_dy357_reload_1[] = {
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

u32 invanim_dy357_reload[] = {
	gunscript_include(1, invanim_dy357_reload_1)
	gunscript_include(0, invanim_dy357_reload_0)
	gunscript_end
};

u32 invanim_dy357_pistolwhip[] = {
	gunscript_playanimation(0x0407, 0, 10000)
	gunscript_waittime(23, 2)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_dy357_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(85), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_dy357_equiporshoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x14000000,
	2, // damage
	0x00000000,
	8, 16, 0, -1,
	0x41400000,
	0x420c0000,
	0x00000000,
	6,
	0,
	0x8066,
	5,
};

struct weaponfunc_shootsingle invfunc_dy357lx_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(85), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_dy357_equiporshoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x1e000000,
	200, // damage
	0x00000000,
	8, 24, 0, -1,
	0x41400000,
	0x420c0000,
	0x00000000,
	6,
	0,
	0x8066,
	5,
};

struct weaponfunc_close invfunc_dy357_pistolwhip = {
	INVENTORYFUNCTYPE_CLOSE,
	L_GUN(94), // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_dy357_pistolwhip, // fire animation
	0x0041a200, // flags
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
	0, // style
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
	&inve_000110c0, // eptr
	2, // sway
	9.5, // left/right
	-18.2, // up/down
	-25.5, // front/back
	1, // unk38
	invf_00011a84, // fptr
	invpartvisibility_dy357, // part visibility
	L_GUN(84), // short name
	L_GUN(12), // name
	L_GUN(149), // manufacturer
	L_GUN(161), // description
	0x0002f67c, // flags
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
	&inve_000110c0, // eptr
	2, // sway
	9.5, // left/right
	-18.2, // up/down
	-25.5, // front/back
	1, // unk38
	invf_00011a84, // fptr
	invpartvisibility_dy357, // part visibility
	L_GUN(13), // short name
	L_GUN(13), // name
	L_GUN(149), // manufacturer
	L_GUN(162), // description
	0x0002f67c, // flags
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

u32 invanim_equiporreload_0[] = {
	gunscript_playanimation(0x0415, 0, 10000)
	gunscript_showpart(1, 53)
	gunscript_showpart(1, 40)
	gunscript_setsoundspeed(44, 1510)
	gunscript_playsound(44, 0x0433)
	gunscript_hidepart(50, 40)
	gunscript_end
};

u32 invanim_phoenix_equiporreload_1[] = {
	gunscript_playanimation(0x0423, 0, 10000)
	gunscript_showpart(1, 53)
	gunscript_showpart(1, 40)
	gunscript_setsoundspeed(44, 1510)
	gunscript_playsound(44, 0x0433)
	gunscript_hidepart(50, 40)
	gunscript_end
};

u32 invanim_phoenix_equiporreload[] = {
	gunscript_include(1, invanim_phoenix_equiporreload_1)
	gunscript_include(0, invanim_equiporreload_0)
	gunscript_end
};

u32 invanim_phoenix_shoot[] = {
	gunscript_playanimation(0x043e, 0, 10000)
	gunscript_waittime(9, 5)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_phoenix_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(85), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_phoenix_shoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x10000000,
	1.1, // damage
	0x40400000,
	3, 5, 2, 0,
	0x41200000,
	0x41700000,
	0x426fffff,
	0,
	0,
	0x8071,
	1,
};

struct weaponfunc_shootsingle invfunc_phoenix_explosiveshells = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(95), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_phoenix_shoot, // fire animation
	0x00004000, // flags
	&invmenupos_00011098,
	0x10000000,
	1.2, // damage
	0x40a00000,
	13, 15, 25, 0,
	0x41700000,
	0x41c80000,
	0x426fffff,
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
	0, // style
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
	&inve_000110c0, // eptr
	1, // sway
	9.5, // left/right
	-16.2, // up/down
	-23, // front/back
	1, // unk38
	invf_00011e00, // fptr
	invpartvisibility_phoenix, // part visibility
	L_GUN(14), // short name
	L_GUN(14), // name
	L_GUN(153), // manufacturer
	L_GUN(163), // description
	0x000af67c, // flags
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

u32 invanim_mauler_equiporshoot[] = {
	gunscript_playanimation(0x03f3, 0, 10000)
	gunscript_waittime(9, 5)
	gunscript_end
};

u32 invanim_mauler_reload_0[] = {
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

u32 invanim_mauler_reload_1[] = {
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

u32 invanim_mauler_reload[] = {
	gunscript_include(1, invanim_mauler_reload_1)
	gunscript_include(0, invanim_mauler_reload_0)
	gunscript_end
};

u32 invanim_unused_8007c0bc[] = {
	gunscript_playanimation(0x03f6, 0, 10000)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_mauler_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(85), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_mauler_equiporshoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	1.2, // damage
	0x40c00000,
	3, 9, 32, 28,
	0x00000000,
	0x00000000,
	0x426fffff,
	4,
	0,
	0x805b,
	1,
};

struct weaponfunc_shootsingle invfunc_mauler_chargeshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(129), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_mauler_equiporshoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	1.2, // damage
	0x40c00000,
	3, 9, 32, 28,
	0x00000000,
	0x00000000,
	0x426fffff,
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
	0, // style
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
	&inve_000110c0, // eptr
	1, // sway
	11.5, // left/right
	-17.5, // up/down
	-20, // front/back
	1, // unk38
	invf_00011fac, // fptr
	invpartvisibility_mauler, // part visibility
	L_GUN(11), // short name
	L_GUN(11), // name
	L_GUN(152), // manufacturer
	L_GUN(160), // description
	0x00027678, // flags
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

u32 invanim_cmp150_reload_0[] = {
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

u32 invanim_cmp150_reload_1[] = {
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

u32 invanim_cmp150_reload[] = {
	gunscript_include(1, invanim_cmp150_reload_1)
	gunscript_include(0, invanim_cmp150_reload_0)
	gunscript_end
};

u32 invanim_cmp150_equiporshoot[] = {
	gunscript_playanimation(0x0116, 0, 10000)
	gunscript_waittime(14, 5)
	gunscript_waitforzreleased(14)
	gunscript_end
};

struct inventory_typee inve_00012308 = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x40000000,
	0x00000006,
};

struct weaponfunc_shootauto invfunc_cmp150_rapidfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(86), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_cmp150_equiporshoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3f800000,
	0x41100000,
	6, 18, 0, 6,
	0x40800000,
	0x40400000,
	0x00000000,
	0x00000000,
	0x03008040,
	0x01000000,
	900,
	900,
	NULL,
	NULL,
	0x00000000,
};

struct weaponfunc_shootauto invfunc_cmp150_followlockon = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(102), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_cmp150_equiporshoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3f800000,
	0x41100000,
	6, 18, 0, 6,
	0x40800000,
	0x40400000,
	0x00000000,
	0x00000000,
	0x03008040,
	0x01000000,
	900,
	900,
	NULL,
	NULL,
	0x00000000,
};

struct inventory_ammo invammo_cmp150 = {
	AMMOTYPE_SMG,
	CASING_STANDARD,
	32, // clip size
	invanim_cmp150_reload, // reload animation
	0, // style
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
	&inve_00012308, // eptr
	3, // sway
	13, // left/right
	-17.7, // up/down
	-27.5, // front/back
	1, // unk38
	invf_000121d8, // fptr
	invpartvisibility_cmp150, // part visibility
	L_GUN(15), // short name
	L_GUN(15), // name
	L_GUN(149), // manufacturer
	L_GUN(164), // description
	0x4402f678, // flags
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

u32 invanim_cyclone_equiporreload_0[] = {
	gunscript_playanimation(0x040e, 0, 10000)
	gunscript_showpart(1, 53)
	gunscript_showpart(1, 40)
	gunscript_playsound(60, 0x05d3)
	gunscript_end
};

u32 invanim_cyclone_equiporreload_1[] = {
	gunscript_playanimation(0x0421, 0, 10000)
	gunscript_playsound(60, 0x05d3)
	gunscript_end
};

u32 invanim_cyclone_equiporreload[] = {
	gunscript_include(1, invanim_cyclone_equiporreload_1)
	gunscript_include(0, invanim_cyclone_equiporreload_0)
	gunscript_end
};

u32 invanim_cyclone_shoot[] = {
	gunscript_playanimation(0x043d, 0, 10000)
	gunscript_waittime(5, 5)
	gunscript_waitforzreleased(5)
	gunscript_end
};

struct weaponfunc_shootauto invfunc_cyclone_rapidfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(86), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_cyclone_shoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3f4ccccd,
	0x40c00000,
	6, 18, 2, 8,
	0x40a00000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x0400805f,
	0x01000000,
	900,
	900,
	NULL,
	NULL,
	0x00000000,
};

struct weaponfunc_shootauto invfunc_cyclone_magazinedischarge = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(97), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_cyclone_shoot, // fire animation
	0x00000020, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3fb33333,
	0x41c80000,
	6, 18, 2, 8,
	0x40a00000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x04008075,
	0x01000000,
	2000,
	2000,
	NULL,
	NULL,
	0x00000000,
};

struct inventory_ammo invammo_cyclone = {
	AMMOTYPE_SMG,
	CASING_NONE,
	50, // clip size
	invanim_cyclone_equiporreload, // reload animation
	0, // style
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
	&inve_000110e0, // eptr
	1, // sway
	21.5, // left/right
	-26.5, // up/down
	-35, // front/back
	1, // unk38
	invf_0001243c, // fptr
	invpartvisibility_cyclone, // part visibility
	L_GUN(20), // short name
	L_GUN(20), // name
	L_GUN(151), // manufacturer
	L_GUN(169), // description
	0x00027678, // flags
};

u32 invanim_rcp120_reload[] = {
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

u32 invanim_rcp120_equiporshoot[] = {
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
	L_GUN(86), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_rcp120_equiporshoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3f99999a,
	0x40c00000,
	6, 18, 0, 6,
	0x40800000,
	0x40400000,
	0x00000000,
	0x00000000,
	0x0400806d,
	0x01000000,
	1100,
	1100,
	NULL,
	NULL,
	0x00000000,
};

struct weaponfunc_special invfunc_rcp120_cloak = {
	INVENTORYFUNCTYPE_SPECIAL,
	L_GUN(116), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00102000, // flags
	HANDATTACKTYPE_RCP120CLOAK,
	0x0000001e,
	0x00000000,
};

struct inventory_ammo invammo_rcp120 = {
	AMMOTYPE_SMG,
	CASING_STANDARD,
	120, // clip size
	invanim_rcp120_reload, // reload animation
	0, // style
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
	&inve_000110e0, // eptr
	3, // sway
	13, // left/right
	-18.2, // up/down
	-27.5, // front/back
	1, // unk38
	invf_00012658, // fptr
	invpartvisibility_rcp120, // part visibility
	L_GUN(22), // short name
	L_GUN(22), // name
	L_GUN(151), // manufacturer
	L_GUN(170), // description
	0x0062e670, // flags
};

u32 invanim_callisto_equiporreload[] = {
	gunscript_playanimation(0x0418, 0, 10000)
	gunscript_showpart(30, 40)
	gunscript_setsoundspeed(58, 933)
	gunscript_playsound(58, 0x0433)
	gunscript_hidepart(79, 40)
	gunscript_end
};

u32 invanim_callisto_shoot[] = {
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
	L_GUN(86), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_callisto_shoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3f99999a,
	0x41100000,
	6, 18, 0, 6,
	0x40800000,
	0x40400000,
	0x00000000,
	0x00000000,
	0x03008063,
	0x01000000,
	900,
	900,
	NULL,
	NULL,
	0x00000000,
};

struct weaponfunc_shootauto invfunc_callisto_highimpactshells = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(115), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_callisto_shoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	0x4019999a,
	0x41100000,
	6, 18, 0, 6,
	0x40800000,
	0x40400000,
	0x00000000,
	0x00000000,
	0x03008064,
	0x05000000,
	300,
	300,
	NULL,
	NULL,
	0x00000000,
};

struct inventory_ammo invammo_callisto = {
	AMMOTYPE_SMG,
	CASING_NONE,
	32, // clip size
	invanim_callisto_equiporreload, // reload animation
	0, // style
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
	&inve_000110e0, // eptr
	3, // sway
	17.5, // left/right
	-22.7, // up/down
	-25, // front/back
	1, // unk38
	invf_00012798, // fptr
	invpartvisibility_callisto, // part visibility
	L_GUN(23), // short name
	L_GUN(23), // name
	L_GUN(153), // manufacturer
	L_GUN(171), // description
	0x0002e670, // flags
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

u32 invanim_dragon_equiporshoot[] = {
	gunscript_playanimation(0x03f9, 0, 10000)
	gunscript_end
};

u32 invanim_dragon_reload[] = {
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
	L_GUN(86), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_dragon_equiporshoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3f8ccccd,
	0x40c00000,
	6, 18, 2, 8,
	0x40a00000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x04008049,
	0x01000000,
	700,
	700,
	NULL,
	NULL,
	0x00000000,
};

struct weaponfunc_throw invfunc_dragon_selfdestruct = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN(118), // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00042040, // flags
	0x000000ff,
	0x00f00000,
	0x0000003c,
	0, // damage
};

struct inventory_ammo invammo_dragon = {
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	invanim_dragon_reload, // reload animation
	0, // style
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
	&inve_00011140, // eptr
	1, // sway
	15, // left/right
	-29.5, // up/down
	-27, // front/back
	1, // unk38
	invf_000128b8, // fptr
	invpartvisibility_dragon, // part visibility
	L_GUN(17), // short name
	L_GUN(17), // name
	L_GUN(149), // manufacturer
	L_GUN(166), // description
	0x04026650, // flags
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

u32 invanim_superdragon_reload[] = {
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

u32 invanim_superdragon_grenadereload[] = {
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

u32 invanim_superdragon_equiporshoot[] = {
	gunscript_playanimation(0x03fe, 0, 10000)
	gunscript_end
};

u32 invanim_superdragon_shootgrenade[] = {
	gunscript_playanimation(0x03ff, 0, 10000)
	gunscript_end
};

u32 invanim_superdragon_pritosec[] = {
	gunscript_playanimation(0x03fd, 0, 10000)
	gunscript_end
};

u32 invanim_superdragon_sectopri[] = {
	gunscript_playanimation(0x03fd, 65535, 55536)
	gunscript_end
};

struct weaponfunc_shootauto invfunc_superdragon_rapidfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(86), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_superdragon_equiporshoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3f99999a,
	0x40c00000,
	6, 18, 2, 8,
	0x40a00000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x04008049,
	0x01000000,
	700,
	700,
	NULL,
	NULL,
	0x00000000,
};

struct weaponfunc_shootprojectile invfunc_superdragon_grenadelauncher = {
	INVENTORYFUNCTYPE_SHOOT_PROJECTILE,
	L_GUN(98), // name
	0x00, // unk06
	1, // unk07
	&invmenupos_00011048, // menupos
	invanim_superdragon_shootgrenade, // fire animation
	0x30000040, // flags
	0x00000000,
	0x00000000,
	0x3f99999a,
	0x40c00000,
	5, 15, -1, 0,
	0x40400000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x04008073,
	0x01000000,
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
	0, // style
};

struct inventory_ammo invammo_superdragon_grenades = {
	AMMOTYPE_DEVASTATOR,
	CASING_NONE,
	6, // clip size
	invanim_superdragon_grenadereload, // reload animation
	0, // style
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
	&inve_00011140, // eptr
	1, // sway
	15, // left/right
	-29.5, // up/down
	-27, // front/back
	1, // unk38
	invf_00012a08, // fptr
	invpartvisibility_superdragon, // part visibility
	L_GUN(18), // short name
	L_GUN(18), // name
	L_GUN(149), // manufacturer
	L_GUN(167), // description
	0x00026650, // flags
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

u32 invanim_ar34_equiporreload[] = {
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

struct inventory_typee inve_00012cc4 = {
	20,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x15000000,
	0x00000006,
};

struct weaponfunc_shootauto invfunc_ar34_burstfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(87), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	NULL, // fire animation
	0x00000002, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3fb33333,
	0x41000000,
	6, 18, 2, 8,
	0x40a00000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x05008059,
	0x01000000,
	750,
	750,
	NULL,
	NULL,
	0x00000000,
};

struct weaponfunc_shootauto invfunc_ar34_usescope = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(103), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	NULL, // fire animation
	0x00000002, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3fb33333,
	0x41000000,
	6, 18, 2, 8,
	0x40a00000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x05008059,
	0x01000000,
	750,
	750,
	NULL,
	NULL,
	0x00000000,
};

struct inventory_ammo invammo_ar34 = {
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	invanim_ar34_equiporreload, // reload animation
	0, // style
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
	&inve_00012cc4, // eptr
	1, // sway
	11.5, // left/right
	-25.7, // up/down
	-30.5, // front/back
	1, // unk38
	invf_00012c40, // fptr
	invpartvisibility_ar34, // part visibility
	L_GUN(16), // short name
	L_GUN(16), // name
	L_GUN(0), // manufacturer
	L_GUN(165), // description
	0x04626650, // flags
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

u32 invanim_k7avenger_reload[] = {
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

u32 invanim_k7avenger_equip[] = {
	gunscript_playanimation(0x00e6, 0, 10000)
	gunscript_end
};

u32 invanim_k7avenger_unequip[] = {
	gunscript_playanimation(0x00e7, 0, 10000)
	gunscript_end
};

u32 invanim_unused_8007ce6c[] = {
	gunscript_playanimation(0x00e8, 0, 10000)
	gunscript_end
};

struct inventory_typee inve_00012e9c = {
	20,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x15000000,
	0x00000006,
};

struct weaponfunc_shootauto invfunc_k7avenger_burstfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(87), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	NULL, // fire animation
	0x00000002, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3fc00000,
	0x40c00000,
	6, 18, 2, 8,
	0x40a00000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x0400805a,
	0x01000000,
	950,
	950,
	NULL,
	NULL,
	0x00000000,
};

struct weaponfunc_shootauto invfunc_k7avenger_threatdetector = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(119), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	NULL, // fire animation
	0x00082002, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3fc00000,
	0x40c00000,
	6, 18, 2, 8,
	0x40a00000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x0400805a,
	0x01000000,
	950,
	950,
	NULL,
	NULL,
	0x00000000,
};

struct inventory_ammo invammo_k7avenger = {
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	25, // clip size
	invanim_k7avenger_reload, // reload animation
	0, // style
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
	&inve_00012e9c, // eptr
	1, // sway
	6.5, // left/right
	-24, // up/down
	-27, // front/back
	1, // unk38
	invf_00012df0, // fptr
	invpartvisibility_k7avenger, // part visibility
	L_GUN(19), // short name
	L_GUN(19), // name
	L_GUN(149), // manufacturer
	L_GUN(168), // description
	0x00022650, // flags
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

u32 invanim_laptopgun_reload[] = {
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

u32 invanim_laptopgun_shoot[] = {
	gunscript_playanimation(0x00e5, 0, 10000)
	gunscript_waittime(10, 5)
	gunscript_waitforzreleased(10)
	gunscript_end
};

u32 invanim_laptopgun_equip[] = {
	gunscript_playanimation(0x00e2, 0, 10000)
	gunscript_setsoundspeed(15, 720)
	gunscript_playsound(15, 0x04f7)
	gunscript_playsound(35, 0x04f7)
	gunscript_playsound(58, 0x04f8)
	gunscript_end
};

u32 invanim_laptopgun_unequip[] = {
	gunscript_playanimation(0x00e3, 0, 10000)
	gunscript_playsound(1, 0x04f7)
	gunscript_setsoundspeed(25, 720)
	gunscript_playsound(25, 0x04f7)
	gunscript_playsound(50, 0x04f8)
	gunscript_end
};

struct weaponfunc_shootauto invfunc_laptopgun_burstfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(87), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_laptopgun_shoot, // fire animation
	0x00000002, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3f933333,
	0x40c00000,
	6, 18, 2, 8,
	0x40a00000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x04008044,
	0x01000000,
	1000,
	1000,
	NULL,
	NULL,
	0x00000000,
};

struct weaponfunc_throw invfunc_laptopgun_deploy = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN(117), // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00842140, // flags
	0x00000157,
	0x00f00000,
	0x0000003c,
	0, // damage
};

struct inventory_ammo invammo_laptopgun = {
	AMMOTYPE_SMG,
	CASING_NONE,
	50, // clip size
	invanim_laptopgun_reload, // reload animation
	0, // style
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
	&inve_00011140, // eptr
	1.2, // sway
	16, // left/right
	-17.7, // up/down
	-14.5, // front/back
	1, // unk38
	invf_00012fc8, // fptr
	invpartvisibility_laptopgun, // part visibility
	L_GUN(24), // short name
	L_GUN(24), // name
	L_GUN(150), // manufacturer
	L_GUN(172), // description
	0x0402a650, // flags
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

u32 invanim_shotgun_reload[] = {
	gunscript_playanimation(0x03ed, 0, 10000)
	gunscript_showpart(1, 43)
	gunscript_playsound(67, 0x01d8)
	gunscript_waittime(74, 1)
	gunscript_hidepart(75, 43)
	gunscript_repeatuntilfull(0x0054, 0x0000, 0x0032)
	gunscript_playsound(103, 0x04fb)
	gunscript_end
};

u32 invanim_shotgun_equiporsingleshot[] = {
	gunscript_playanimation(0x03ee, 0, 10000)
	gunscript_waittime(9, 2)
	gunscript_playsound(34, 0x04fb)
	gunscript_end
};

u32 invanim_shotgun_doubleshot[] = {
	gunscript_playanimation(0x042c, 0, 10000)
	gunscript_waittime(9, 2)
	gunscript_playsound(54, 0x04fb)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_shotgun_single = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(89), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_shotgun_equiporsingleshot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	0.6, // damage
	0x41f00000,
	20, 28, 0, 0,
	0x00000000,
	0x00000000,
	0x00000000,
	4,
	0,
	0x8055,
	1,
};

struct weaponfunc_shootsingle invfunc_shotgun_double = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(105), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_shotgun_doubleshot, // fire animation
	0x00001000, // flags
	&invmenupos_00011098,
	0x00000000,
	0.6, // damage
	0x41800000,
	20, 28, 0, 0,
	0x00000000,
	0x00000000,
	0x00000000,
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
	67108864, // style
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
	&inve_000110c0, // eptr
	1, // sway
	12, // left/right
	-16.7, // up/down
	-21, // front/back
	1, // unk38
	invf_000131dc, // fptr
	invpartvisibility_shotgun, // part visibility
	L_GUN(25), // short name
	L_GUN(25), // name
	L_GUN(149), // manufacturer
	L_GUN(173), // description
	0x00026650, // flags
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

u32 invanim_reaper_shoot[] = {
	gunscript_playanimation(0x0400, 0, 10000)
	gunscript_waittime(12, 5)
	gunscript_end
};

u32 invanim_reaper_reload[] = {
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

u32 invanim_reaper_equip[] = {
	gunscript_playanimation(0x0427, 0, 10000)
	gunscript_end
};

u32 invanim_reaper_unequip[] = {
	gunscript_playanimation(0x0428, 0, 10000)
	gunscript_end
};

struct weaponfunc_shootauto invfunc_reaper_shoot = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(88), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001105c, // menupos
	invanim_reaper_shoot, // fire animation
	0x00000002, // flags
	&invmenupos_000110ac,
	0x00000000,
	0x3f99999a,
	0x42600000,
	3, 9, 32, 28,
	0x00000000,
	0x00000000,
	0x00000000,
	0x40800000,
	0x0200803f,
	0x01000000,
	60,
	1800,
	var8006d33c,
	var8006d36c,
	0x58580000,
};

struct weaponfunc_close invfunc_reaper_grind = {
	INVENTORYFUNCTYPE_CLOSE,
	L_GUN(106), // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00002000, // flags
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
	0, // style
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
	&inve_000110c0, // eptr
	1, // sway
	4, // left/right
	-21.2, // up/down
	-30.5, // front/back
	1, // unk38
	invf_000133c8, // fptr
	invpartvisibility_reaper, // part visibility
	L_GUN(26), // short name
	L_GUN(26), // name
	L_GUN(152), // manufacturer
	L_GUN(174), // description
	0x00022650, // flags
};

struct modelpartvisibility invpartvisibility_rocketlauncher[] = {
	{ MODELPART_NEWCLIP, false },
	{ 255 },
};

struct inventory_typef invf_00013564[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0028, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

u32 invanim_rocketlauncher_reload[] = {
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

u32 invanim_rockerlauncher_equiporshoot[] = {
	gunscript_playanimation(0x03f0, 0, 10000)
	gunscript_end
};

struct inventory_typee inve_000135f0 = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x30000000,
	0x00000002,
};

struct weaponfunc_shootprojectile invfunc_rockerlauncher_shoot = {
	INVENTORYFUNCTYPE_SHOOT_PROJECTILE,
	L_GUN(91), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_rockerlauncher_equiporshoot, // fire animation
	0x08000040, // flags
	0x00000000,
	0x00000000,
	0x3f800000,
	0x40c00000,
	3, 12, 15, 0,
	0x40400000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x04008053,
	0x01000000,
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
	L_GUN(92), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_rockerlauncher_equiporshoot, // fire animation
	0x48000040, // flags
	0x00000000,
	0x00000000,
	0x3f800000,
	0x40c00000,
	3, 12, 15, 0,
	0x40400000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x04008053,
	0x01000000,
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
	0, // style
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
	&inve_000135f0, // eptr
	1, // sway
	24.5, // left/right
	-25.2, // up/down
	-30, // front/back
	1, // unk38
	invf_00013564, // fptr
	invpartvisibility_rocketlauncher, // part visibility
	L_GUN(80), // short name
	L_GUN(27), // name
	L_GUN(149), // manufacturer
	L_GUN(175), // description
	0x40026270, // flags
};

u32 invanim_slayer_equiporshoot[] = {
	gunscript_playanimation(0x042a, 0, 10000)
	gunscript_end
};

u32 invanim_slayer_reload[] = {
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
	L_GUN(91), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_slayer_equiporshoot, // fire animation
	0x08000040, // flags
	0x00000000,
	0x00000000,
	0x3f800000,
	0x40c00000,
	3, 12, 15, 0,
	0x40400000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x04008067,
	0x01000000,
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
	L_GUN(93), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	NULL, // fire animation
	0x28000840, // flags
	0x00000000,
	0x00000000,
	0x3f800000,
	0x40c00000,
	3, 12, 15, 0,
	0x40400000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x04008067,
	0x01000000,
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
	0, // style
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
	&inve_000110c0, // eptr
	1, // sway
	22.5, // left/right
	-32, // up/down
	-40.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(29), // short name
	L_GUN(29), // name
	L_GUN(152), // manufacturer
	L_GUN(177), // description
	0x02026270, // flags
};

struct inventory_typef invf_unused_8006d890[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0029, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

u32 invanim_devastator_equiporshoot[] = {
	gunscript_playanimation(0x03f7, 0, 10000)
	gunscript_end
};

u32 invanim_devastator_reload[] = {
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
	L_GUN(98), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_devastator_equiporshoot, // fire animation
	0x30000040, // flags
	0x00000000,
	0x00000000,
	0x3f800000,
	0x40c00000,
	5, 58, -1, 0,
	0x40a00000,
	0x41000000,
	0x00000000,
	0x40800000,
	0x04008073,
	0x01000000,
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
	L_GUN(99), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_devastator_equiporshoot, // fire animation
	0x30000140, // flags
	0x00000000,
	0x00000000,
	0x3f800000,
	0x40c00000,
	5, 58, -1, 0,
	0x40a00000,
	0x41000000,
	0x00000000,
	0x40800000,
	0x04008073,
	0x01000000,
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
	134217728, // style
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
	&inve_000110c0, // eptr
	1, // sway
	19.5, // left/right
	-25.5, // up/down
	-29, // front/back
	1, // unk38
	NULL, // fptr
	invpartvisibility_devastator, // part visibility
	L_GUN(28), // short name
	L_GUN(28), // name
	L_GUN(149), // manufacturer
	L_GUN(176), // description
	0x00026270, // flags
};

struct weaponfunc invfunc_mine_threatdetector = {
	INVENTORYFUNCTYPE_NONE,
	L_GUN(119), // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00080000, // flags
};

u32 inanim_mine_equiporreload[] = {
	gunscript_playanimation(0x0430, 0, 10000)
	gunscript_end
};

u32 invanim_mine_unequip[] = {
	gunscript_playanimation(0x0431, 0, 10000)
	gunscript_end
};

u32 invanim_mine_throw[] = {
	gunscript_playanimation(0x0435, 0, 10000)
	gunscript_waitforzreleased(10)
	gunscript_waittime(13, 2)
	gunscript_end
};

struct weaponfunc_throw invfunc_timedmine_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN(120), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_mine_throw, // fire animation
	0x00802040, // flags
	0x00000113,
	0x00f00000,
	0x00000000,
	0, // damage
};

struct inventory_ammo invammo_timedmine = {
	AMMOTYPE_TIMED_MINE,
	CASING_NONE,
	1, // clip size
	inanim_mine_equiporreload, // reload animation
	33554432, // style
};

struct weapon invitem_timedmine = {
	FILE_GTIMEDMINE, // hi model
	FILE_GTIMEDMINE, // lo model
	inanim_mine_equiporreload, // equip animation
	invanim_mine_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_timedmine_throw, &invfunc_mine_threatdetector }, // functions
	&invammo_timedmine, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1, // sway
	8, // left/right
	-15, // up/down
	-23, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(38), // short name
	L_GUN(38), // name
	L_GUN(0), // manufacturer
	L_GUN(185), // description
	0x00022259, // flags
};

struct inventory_typef invf_00013b40[] = {
	{ 0x0500, 0x0000, 0x0300, 0x0035, 0x0000 },
	{ 0x0500, 0x0000, 0x0300, 0x0029, 0x0000 },
	{ 0x0600, 0x0000, 0x0300, 0x0036, 0x0000 },
	{ 0x0600, 0x0000, 0x0300, 0x0028, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

u32 invanim_remotemine_equiporreload[] = {
	gunscript_playanimation(0x0432, 0, 10000)
	gunscript_end
};

u32 invanim_remotemine_unequip[] = {
	gunscript_playanimation(0x0433, 0, 10000)
	gunscript_end
};

u32 invanim_remotemine_throw[] = {
	gunscript_playanimation(0x0436, 0, 10000)
	gunscript_waitforzreleased(10)
	gunscript_waittime(11, 2)
	gunscript_end
};

struct weaponfunc_throw invfunc_remotemine_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN(122), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_remotemine_throw, // fire animation
	0x00802040, // flags
	0x00000115,
	0x00f00000,
	0x00000000,
	0, // damage
};

struct weaponfunc_special invfunc_remotemine_detonate = {
	INVENTORYFUNCTYPE_SPECIAL,
	L_GUN(123), // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00102000, // flags
	HANDATTACKTYPE_DETONATE,
	0x0000001e,
	0x00000000,
};

struct inventory_ammo invammo_remotemine = {
	AMMOTYPE_REMOTE_MINE,
	CASING_NONE,
	1, // clip size
	invanim_remotemine_equiporreload, // reload animation
	33554432, // style
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
	&inve_000110c0, // eptr
	1, // sway
	4, // left/right
	-15, // up/down
	-23, // front/back
	1, // unk38
	invf_00013b40, // fptr
	invpartvisibility_remotemine, // part visibility
	L_GUN(40), // short name
	L_GUN(40), // name
	L_GUN(0), // manufacturer
	L_GUN(187), // description
	0x00022259, // flags
};

struct weaponfunc_throw invfunc_proxymine_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN(121), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_mine_throw, // fire animation
	0x00802040, // flags
	0x00000114,
	0x00f00000,
	0x00000000,
	0, // damage
};

struct inventory_ammo invammo_proximitymine = {
	AMMOTYPE_PROXY_MINE,
	CASING_NONE,
	1, // clip size
	inanim_mine_equiporreload, // reload animation
	33554432, // style
};

struct weapon invitem_proximitymine = {
	FILE_GPROXIMITYMINE, // hi model
	FILE_GPROXIMITYMINE, // lo model
	inanim_mine_equiporreload, // equip animation
	invanim_mine_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	{ &invfunc_proxymine_throw, &invfunc_mine_threatdetector }, // functions
	&invammo_proximitymine, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1, // sway
	8, // left/right
	-15, // up/down
	-23, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(81), // short name
	L_GUN(39), // name
	L_GUN(0), // manufacturer
	L_GUN(186), // description
	0x00022259, // flags
};

u32 invanim_ecmmine_equiporreload[] = {
	gunscript_playanimation(0x0437, 0, 10000)
	gunscript_end
};

u32 invanim_ecmmine_unequip[] = {
	gunscript_playanimation(0x0438, 0, 10000)
	gunscript_end
};

u32 invanim_ecmmine_throw[] = {
	gunscript_playanimation(0x0438, 0, 10000)
	gunscript_waittime(23, 2)
	gunscript_end
};

struct weaponfunc_throw invfunc_ecmmine_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN(140), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_ecmmine_throw, // fire animation
	0x00802040, // flags
	0x00000116,
	0x00f00000,
	0x0000003c,
	0, // damage
};

struct inventory_ammo invammo_ecmmine = {
	AMMOTYPE_ECM_MINE,
	CASING_NONE,
	1, // clip size
	invanim_ecmmine_equiporreload, // reload animation
	33554432, // style
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
	&inve_000110c0, // eptr
	1, // sway
	14, // left/right
	-25, // up/down
	-31.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(41), // short name
	L_GUN(41), // name
	L_GUN(0), // manufacturer
	L_GUN(188), // description
	0x08622059, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(38), // short name
	L_GUN(38), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x08000048, // flags
};

struct inventory_typef invf_00013df8[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

u32 invanim_grenade_throw[] = {
	gunscript_playanimation(0x0426, 0, 10000)
	gunscript_popoutsackofpills(0x0006)
	gunscript_playsound(6, 0x05c1)
	gunscript_waitforzreleased(43)
	gunscript_waittime(49, 2)
	gunscript_end
};

u32 invanim_grenade_equiporreload[] = {
	gunscript_playanimation(0x042b, 0, 10000)
	gunscript_end
};

struct weaponfunc_throw invfunc_grenade_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN(124), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_grenade_throw, // fire animation
	0x00002040, // flags
	0x00000112,
	0x00f00000,
	0x0000003c,
	0, // damage
};

struct weaponfunc_throw invfunc_grenade_pinball = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN(125), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_grenade_throw, // fire animation
	0x00002040, // flags
	0x00000112,
	0x005a0000,
	0x0000003c,
	0, // damage
};

struct inventory_ammo invammo_grenade = {
	AMMOTYPE_GRENADE,
	CASING_NONE,
	1, // clip size
	invanim_grenade_equiporreload, // reload animation
	167772160, // style
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
	&inve_000110c0, // eptr
	1, // sway
	17, // left/right
	-19.7, // up/down
	-21, // front/back
	1, // unk38
	invf_00013df8, // fptr
	NULL, // part visibility
	L_GUN(36), // short name
	L_GUN(36), // name
	L_GUN(0), // manufacturer
	L_GUN(183), // description
	0x0002a67d, // flags
};

struct weaponfunc_throw invfunc_nbomb_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN(134), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_grenade_throw, // fire animation
	0x00002640, // flags
	0x00000110,
	0x00f00000,
	0x0000003c,
	0, // damage
};

struct weaponfunc_throw invfunc_nbomb_proxy = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN(127), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_grenade_throw, // fire animation
	0x00002640, // flags
	0x00000110,
	0x00f00000,
	0x0000003c,
	0, // damage
};

struct inventory_ammo invammo_nbomb = {
	AMMOTYPE_NBOMB,
	CASING_NONE,
	1, // clip size
	invanim_grenade_equiporreload, // reload animation
	167772160, // style
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
	&inve_000110c0, // eptr
	1, // sway
	17, // left/right
	-19.7, // up/down
	-21, // front/back
	1, // unk38
	invf_00013df8, // fptr
	NULL, // part visibility
	L_GUN(37), // short name
	L_GUN(37), // name
	L_GUN(0), // manufacturer
	L_GUN(184), // description
	0x0062a67d, // flags
};

struct inventory_typef invf_00013fa4[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0028, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

u32 invanim_farsight_reload[] = {
	gunscript_playanimation(0x03eb, 0, 10000)
	gunscript_showpart(1, 40)
	gunscript_playsound(72, 0x0433)
	gunscript_waittime(76, 1)
	gunscript_hidepart(82, 40)
	gunscript_end
};

u32 invanim_farsight_equiporshoot[] = {
	gunscript_playanimation(0x03ec, 0, 10000)
	gunscript_end
};

struct inventory_typee inve_00013ff8 = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x16000000,
	0x00000005,
};

struct weaponfunc_shootsingle invfunc_farsight_shoot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(90), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_farsight_equiporshoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	100, // damage
	0x00000000,
	70, 40, 0, 0,
	0x00000000,
	0x00000000,
	0x00000000,
	0,
	4,
	0x813e,
	5,
};

struct weaponfunc_shootsingle invfunc_farsight_targetlocator = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(111), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_farsight_equiporshoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	100, // damage
	0x00000000,
	70, 40, 0, 0,
	0x00000000,
	0x00000000,
	0x00000000,
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
	0, // style
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
	&inve_00013ff8, // eptr
	6, // sway
	21.5, // left/right
	-25.2, // up/down
	-32.5, // front/back
	1, // unk38
	invf_00013fa4, // fptr
	invpartvisibility_farsight, // part visibility
	L_GUN(79), // short name
	L_GUN(31), // name
	L_GUN(0), // manufacturer
	L_GUN(178), // description
	0x00026650, // flags
};

struct inventory_typef invf_00014100[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x0029, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

u32 invanim_crossbow_reload[] = {
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

u32 invanim_crossbow_shoot[] = {
	gunscript_playanimation(0x00c2, 0, 10000)
	gunscript_hidepart(20, 40)
	gunscript_playsound(37, 0x04f8)
	gunscript_end
};

u32 invanim_crossbow_unequip[] = {
	gunscript_playanimation(0x00d3, 0, 10000)
	gunscript_hidepart(1, 40)
	gunscript_playsound(37, 0x04f8)
	gunscript_end
};

u32 invanim_crosbow_equip[] = {
	gunscript_playanimation(0x00c1, 0, 10000)
	gunscript_playsound(32, 0x04fc)
	gunscript_playsound(75, 0x04f8)
	gunscript_end
};

struct weaponfunc_shootprojectile invfunc_crossbow_lethal = {
	INVENTORYFUNCTYPE_SHOOT_PROJECTILE,
	L_GUN(112), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_crossbow_shoot, // fire animation
	0x00802000, // flags
	0x00000000,
	0x00000000,
	0x42c80000,
	0x40c00000,
	3, 12, 15, 0,
	0x40400000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x04008056,
	0x01000000,
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
	L_GUN(107), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_crossbow_shoot, // fire animation
	0x00802200, // flags
	0x00000000,
	0x00000000,
	0x3f800000,
	0x40c00000,
	3, 12, 15, 0,
	0x40400000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x04008056,
	0x01000000,
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
	67108864, // style
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
	&inve_000110c0, // eptr
	1, // sway
	11, // left/right
	-15, // up/down
	-21, // front/back
	1, // unk38
	invf_00014100, // fptr
	invpartvisibility_crossbow, // part visibility
	L_GUN(33), // short name
	L_GUN(33), // name
	L_GUN(0), // manufacturer
	L_GUN(180), // description
	0x00022658, // flags
};

struct inventory_typef invf_00014314[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0028, 0x0000 },
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

u32 invanim_tranquilizer_lethalinject[] = {
	gunscript_playanimation(0x0411, 0, 10000)
	gunscript_waittime(18, 2)
	gunscript_end
};

u32 invanim_tranquilizer_equiporshoot[] = {
	gunscript_playanimation(0x042d, 0, 10000)
	gunscript_waittime(7, 5)
	gunscript_end
};

u32 invanim_tranquilizer_reload[] = {
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
	L_GUN(107), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_tranquilizer_equiporshoot, // fire animation
	0x00000200, // flags
	&invmenupos_00011098,
	0x10000000,
	0.25, // damage
	0x40400000,
	3, 5, 5, 0,
	0x3f800000,
	0x00000000,
	0x426fffff,
	0,
	0,
	0x8057,
	1,
};

struct weaponfunc_close invfunc_tranquilizer_lethal = {
	INVENTORYFUNCTYPE_CLOSE,
	L_GUN(108), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_tranquilizer_lethalinject, // fire animation
	0x00002000, // flags
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
	0, // style
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
	&inve_000110c0, // eptr
	1, // sway
	10, // left/right
	-15.2, // up/down
	-24, // front/back
	1, // unk38
	invf_00014314, // fptr
	invpartvisibility_tranquilizer, // part visibility
	L_GUN(34), // short name
	L_GUN(34), // name
	L_GUN(0), // manufacturer
	L_GUN(181), // description
	0x0002e65c, // flags
};

struct inventory_ammo invammo_psychosisgun = {
	AMMOTYPE_PSYCHOSIS,
	CASING_NONE,
	8, // clip size
	invanim_tranquilizer_reload, // reload animation
	0, // style
};

struct weaponfunc_shootsingle invfunc_psychosisgun_shoot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(131), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_tranquilizer_equiporshoot, // fire animation
	0x00200200, // flags
	&invmenupos_00011098,
	0x10000000,
	0.5, // damage
	0x40400000,
	3, 5, 5, 0,
	0x3f800000,
	0x00000000,
	0x426fffff,
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
	&inve_000110c0, // eptr
	1, // sway
	10, // left/right
	-16.2, // up/down
	-28.5, // front/back
	1, // unk38
	invf_00014314, // fptr
	invpartvisibility_tranquilizer, // part visibility
	L_GUN(82), // short name
	L_GUN(49), // name
	L_GUN(0), // manufacturer
	L_GUN(210), // description
	0x0002e65c, // flags
};

struct inventory_typef invf_00014590[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0029, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

u32 invanim_sniperrifle_equip[] = {
	gunscript_playanimation(0x040c, 0, 10000)
	gunscript_end
};

u32 invanim_sniperrifle_reload[] = {
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

struct inventory_typee inve_0001460c = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x15000000,
	0x00000005,
};

struct weaponfunc_shootsingle invfunc_sniperrifle_singleshot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(85), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010ff8, // menupos
	NULL, // fire animation
	0x00002000, // flags
	&invmenupos_00011098,
	0x10000000,
	1.2, // damage
	0x00000000,
	6, 10, 0, 0,
	0x41000000,
	0x00000000,
	0x00000000,
	0,
	4,
	0x8058,
	1,
};

struct weaponfunc_special invfunc_sniperrifle_crouch = {
	INVENTORYFUNCTYPE_SPECIAL,
	L_GUN(130), // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00102000, // flags
	HANDATTACKTYPE_CROUCH,
	0x0000001e,
	0x00000000,
};

struct inventory_ammo invammo_sniperrifle = {
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	8, // clip size
	invanim_sniperrifle_reload, // reload animation
	0, // style
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
	&inve_0001460c, // eptr
	6, // sway
	21, // left/right
	-27.2, // up/down
	-31.5, // front/back
	1, // unk38
	invf_00014590, // fptr
	invpartvisibility_sniperrifle, // part visibility
	L_GUN(32), // short name
	L_GUN(32), // name
	L_GUN(0), // manufacturer
	L_GUN(179), // description
	0x00026650, // flags
};

u32 invanim_laser_equip[] = {
	gunscript_playanimation(0x042e, 0, 10000)
	gunscript_end
};

u32 invanim_laser_unequip[] = {
	gunscript_playanimation(0x042f, 0, 10000)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_laser_pulse = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(132), // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	1, // damage
	0x00000000,
	6, 18, 24, -1,
	0x00000000,
	0x00000000,
	0x00000000,
	0,
	3,
	0x8043,
	1,
};

struct weaponfunc_shootauto invfunc_laser_stream = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(133), // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00000000, // flags
	&invmenupos_00011084,
	0x00000000,
	0x3dcccccd,
	0x00000000,
	6, 18, 0, 6,
	0x40800000,
	0x40400000,
	0x00000000,
	0x00000000,
	0x03000000,
	0x01000000,
	3600,
	3600,
	NULL,
	NULL,
	0x00000000,
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
	&inve_000110c0, // eptr
	3, // sway
	-12, // left/right
	-12.7, // up/down
	-21.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(47), // short name
	L_GUN(47), // name
	L_GUN(150), // manufacturer
	L_GUN(189), // description
	0x0412a678, // flags
};

struct modelpartvisibility invpartvisibility_classic[] = {
	{ MODELPART_MUZZLEFLASH, false },
	{ 255 },
};

struct inventory_typef invf_000147fc[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

u32 invanim_pp9i_equiporshoot[] = {
	gunscript_playanimation(0x0440, 0, 10000)
	gunscript_waittime(10, 5)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_pp9i_shoot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(85), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_pp9i_equiporshoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x10000000,
	1, // damage
	0x3f800000,
	4, 8, 3, 0,
	0x40400000,
	0x41200000,
	0x41efffff,
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
	0, // style
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
	&inve_000110c0, // eptr
	1, // sway
	10, // left/right
	-14.8, // up/down
	-19, // front/back
	1, // unk38
	invf_000147fc, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN(50), // short name
	L_GUN(50), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x000af67c, // flags
};

u32 invanim_cc13_equiporshoot[] = {
	gunscript_playanimation(0x043f, 0, 10000)
	gunscript_waittime(10, 5)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_cc13_shoot = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(85), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_cc13_equiporshoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x10000000,
	1, // damage
	0x40c00000,
	4, 8, 3, 0,
	0x40a00000,
	0x41200000,
	0x426fffff,
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
	0, // style
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
	&inve_000110c0, // eptr
	1, // sway
	10, // left/right
	-17, // up/down
	-26.5, // front/back
	1, // unk38
	invf_000147fc, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN(51), // short name
	L_GUN(51), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x000af67c, // flags
};

struct weaponfunc_shootauto invfunc_kl01313_shoot = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(86), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3f19999a,
	0x41700000,
	0, 0, 0, 6,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x0b00806b,
	0x01000000,
	450,
	450,
	NULL,
	NULL,
	0x00000000,
};

struct inventory_ammo invammo_kl01313 = {
	AMMOTYPE_SMG,
	CASING_STANDARD,
	20, // clip size
	NULL, // reload animation
	0, // style
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
	&inve_000110c0, // eptr
	1, // sway
	8.5, // left/right
	-13, // up/down
	-29.5, // front/back
	1, // unk38
	NULL, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN(52), // short name
	L_GUN(52), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x0000967c, // flags
};

struct weaponfunc_shootauto invfunc_kf7special_shoot = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(87), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000002, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3f800000,
	0x41200000,
	4, 12, 0, 6,
	0x40900000,
	0x40000000,
	0x00000000,
	0x40400000,
	0x0400806c,
	0x01000000,
	450,
	450,
	NULL,
	NULL,
	0x00000000,
};

struct inventory_ammo invammo_kf7special = {
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	NULL, // reload animation
	0, // style
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
	&inve_00011140, // eptr
	2, // sway
	13, // left/right
	-21, // up/down
	-13.5, // front/back
	1, // unk38
	NULL, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN(53), // short name
	L_GUN(53), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x0000967c, // flags
};

struct weaponfunc_shootauto invfunc_zzt9mm_shoot = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(86), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3f800000,
	0x41100000,
	6, 18, 0, 6,
	0x40800000,
	0x40400000,
	0x00000000,
	0x00000000,
	0x0400806d,
	0x01000000,
	600,
	600,
	NULL,
	NULL,
	0x00000000,
};

struct inventory_ammo invammo_zzt9mm = {
	AMMOTYPE_SMG,
	CASING_STANDARD,
	32, // clip size
	NULL, // reload animation
	0, // style
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
	&inve_000110e0, // eptr
	0.5, // sway
	11, // left/right
	-24.5, // up/down
	-37, // front/back
	1, // unk38
	NULL, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN(54), // short name
	L_GUN(54), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x0000967c, // flags
};

struct weaponfunc_shootauto invfunc_dmc_shoot = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(86), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3f800000,
	0x40e00000,
	6, 18, 0, 6,
	0x40800000,
	0x40400000,
	0x00000000,
	0x00000000,
	0x0400806e,
	0x01000000,
	450,
	450,
	NULL,
	NULL,
	0x00000000,
};

struct inventory_ammo invammo_dmc = {
	AMMOTYPE_SMG,
	CASING_STANDARD,
	30, // clip size
	NULL, // reload animation
	0, // style
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
	&inve_000110e0, // eptr
	1, // sway
	16.5, // left/right
	-22.9, // up/down
	-35, // front/back
	1, // unk38
	NULL, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN(55), // short name
	L_GUN(55), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x0000967c, // flags
};

struct weaponfunc_shootauto invfunc_ar53_shoot = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(87), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000002, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3fb33333,
	0x40c00000,
	6, 18, 2, 8,
	0x40a00000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x0500806f,
	0x01000000,
	550,
	550,
	NULL,
	NULL,
	0x00000000,
};

struct inventory_ammo invammo_ar53 = {
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	NULL, // reload animation
	0, // style
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
	&inve_00011140, // eptr
	6, // sway
	11, // left/right
	-19.2, // up/down
	-21.5, // front/back
	1, // unk38
	NULL, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN(56), // short name
	L_GUN(56), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x0060967c, // flags
};

struct weaponfunc_shootauto invfunc_rcp45_shoot = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(86), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3fe66666,
	0x40c00000,
	4, 8, 0, 3,
	0x40600000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x02008070,
	0x01000000,
	600,
	600,
	NULL,
	NULL,
	0x00000000,
};

struct inventory_ammo invammo_rcp45 = {
	AMMOTYPE_SMG,
	CASING_STANDARD,
	80, // clip size
	NULL, // reload animation
	0, // style
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
	&inve_000110e0, // eptr
	4, // sway
	11, // left/right
	-22.3, // up/down
	-29, // front/back
	1, // unk38
	NULL, // fptr
	invpartvisibility_classic, // part visibility
	L_GUN(57), // short name
	L_GUN(57), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x0060967c, // flags
};

struct weaponfunc invfunc_briefcase_use = {
	INVENTORYFUNCTYPE_NONE,
	L_GUN(0), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00000000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	12.5, // left/right
	-17, // up/down
	-27.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(71), // short name
	L_GUN(71), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x01940808, // flags
};

struct weaponfunc_shootauto invfunc_59_rapidfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(86), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3f800000,
	0x40c00000,
	6, 18, 2, 8,
	0x40a00000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x04008059,
	0x02000000,
	900,
	900,
	NULL,
	NULL,
	0x00000000,
};

struct inventory_ammo invammo_59 = {
	AMMOTYPE_SMG,
	CASING_RIFLE,
	27, // clip size
	NULL, // reload animation
	0, // style
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
	&inve_000110c0, // eptr
	1, // sway
	16.5, // left/right
	-19.5, // up/down
	-24, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(0), // short name
	L_GUN(0), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x00001250, // flags
};

struct weaponfunc_shootauto invfunc_5a_rapidfire = {
	INVENTORYFUNCTYPE_SHOOT_AUTOMATIC,
	L_GUN(86), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
	&invmenupos_00011098,
	0x00000000,
	0x3f800000,
	0x40c00000,
	6, 18, 2, 8,
	0x40a00000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x0400803f,
	0x01000000,
	900,
	900,
	NULL,
	NULL,
	0x00000000,
};

struct inventory_ammo invammo_5a = {
	AMMOTYPE_SMG,
	CASING_RIFLE,
	27, // clip size
	NULL, // reload animation
	0, // style
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
	&inve_000110c0, // eptr
	1, // sway
	16.5, // left/right
	-19.5, // up/down
	-24, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(0), // short name
	L_GUN(0), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x00001250, // flags
};

struct inventory_typef invf_00014fc0[] = {
	{ 0x0100, 0x0000, 0x0100, 0x0035, 0x0000 },
	{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

u32 invanim_combatknife_equip[] = {
	gunscript_playanimation(0x0403, 0, 10000)
	gunscript_waittime(24, 2)
	gunscript_end
};

u32 invanim_combatknife_slash2[] = {
	gunscript_playanimation(0x0404, 0, 10000)
	gunscript_waittime(24, 2)
	gunscript_end
};

u32 invanim_combatknife_slash[] = {
	gunscript_random(50, invanim_combatknife_slash2)
	gunscript_include(0, invanim_combatknife_equip)
	gunscript_end
};

u32 invanim_combatknife_pritosec[] = {
	gunscript_playanimation(0x0405, 0, 10000)
	gunscript_playsound(30, 0x80a7)
	gunscript_playsound(40, 0x80a6)
	gunscript_end
};

u32 invanim_combatknife_sectopri[] = {
	gunscript_playanimation(0x0405, 65535, 55536)
	gunscript_playsound(10, 0x80a8)
	gunscript_playsound(20, 0x80a6)
	gunscript_end
};

u32 invanim_combatknife_throw[] = {
	gunscript_playanimation(0x041b, 0, 10000)
	gunscript_waitforzreleased(12)
	gunscript_waittime(16, 2)
	gunscript_end
};

u32 invanim_unused_8007f05c[] = {
	gunscript_playanimation(0x041c, 0, 10000)
	gunscript_waittime(22, 1)
	gunscript_end
};

u32 invanim_combatknife_reload[] = {
	gunscript_include(2, invanim_combatknife_sectopri)
	gunscript_include(0, invanim_combatknife_pritosec)
	gunscript_end
};

struct weaponfunc_close invfunc_combatknife_slash = {
	INVENTORYFUNCTYPE_CLOSE,
	L_GUN(109), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_combatknife_slash, // fire animation
	0x00002000, // flags
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
	L_GUN(110), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_combatknife_throw, // fire animation
	0x00802000, // flags
	0x0000010f,
	0x00f00000,
	0x0000003c,
	1, // damage
};

struct inventory_ammo invammo_combatknife = {
	AMMOTYPE_KNIFE,
	CASING_NONE,
	1, // clip size
	invanim_combatknife_reload, // reload animation
	167772160, // style
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
	&inve_000110c0, // eptr
	1, // sway
	18.5, // left/right
	-26.5, // up/down
	-28, // front/back
	1, // unk38
	invf_00014fc0, // fptr
	NULL, // part visibility
	L_GUN(83), // short name
	L_GUN(35), // name
	L_GUN(0), // manufacturer
	L_GUN(182), // description
	0x0402f679, // flags
};

struct weaponfunc_throw invfunc_bug_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN(0), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00802040, // flags
	0x00000012,
	0x00f00000,
	0x0000003c,
	0, // damage
};

struct weaponfunc_throw invfunc_targetamplifier_throw = {
	INVENTORYFUNCTYPE_THROW,
	L_GUN(0), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00802040, // flags
	0x000001b1,
	0x00f00000,
	0x0000003c,
	0, // damage
};

struct inventory_ammo invammo_bug = {
	AMMOTYPE_BUG,
	CASING_NONE,
	1, // clip size
	NULL, // reload animation
	33554432, // style
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
	&inve_000110c0, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(222), // short name
	L_GUN(222), // name
	L_GUN(0), // manufacturer
	L_GUN(204), // description
	0x08000018, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(223), // short name
	L_GUN(223), // name
	L_GUN(0), // manufacturer
	L_GUN(205), // description
	0x08000018, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(235), // short name
	L_GUN(224), // name
	L_GUN(0), // manufacturer
	L_GUN(206), // description
	0x08000018, // flags
};

struct weaponfunc_device invfunc_nightvision_primary = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN(135), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(59), // short name
	L_GUN(59), // name
	L_GUN(0), // manufacturer
	L_GUN(191), // description
	0x08001098, // flags
};

struct weaponfunc invfunc_horizonscanner_primary = {
	INVENTORYFUNCTYPE_NONE,
	L_GUN(139), // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00000000, // flags
};

struct inventory_typee inve_00015348 = {
	0,
	3,
	8,
	15,
	0.9721,
	0.9767,
	0x05000000,
	0x00000005,
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
	&inve_00015348, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(234), // short name
	L_GUN(76), // name
	L_GUN(0), // manufacturer
	L_GUN(196), // description
	0x08600058, // flags
};

struct weaponfunc_device invfunc_cloak_primary = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN(116), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
	DEVICE_CLOAKDEVICE,
};

struct inventory_ammo invammo_cloakingdevice = {
	AMMOTYPE_CLOAK,
	CASING_NONE,
	10, // clip size
	NULL, // reload animation
	16777216, // style
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
	&inve_000110c0, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(73), // short name
	L_GUN(73), // name
	L_GUN(0), // manufacturer
	L_GUN(195), // description
	0x04000018, // flags
};

struct weaponfunc_special invfunc_combatboost_boost = {
	INVENTORYFUNCTYPE_SPECIAL,
	L_GUN(113), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
	HANDATTACKTYPE_BOOST,
	0x0000001e,
	0x05c90000,
};

struct weaponfunc_special invfunc_combatboost_revert = {
	INVENTORYFUNCTYPE_SPECIAL,
	L_GUN(114), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
	HANDATTACKTYPE_REVERTBOOST,
	0x0000001e,
	0x05c90000,
};

struct inventory_ammo invammo_combatboost = {
	AMMOTYPE_BOOST,
	CASING_NONE,
	4, // clip size
	NULL, // reload animation
	16777216, // style
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
	&inve_000110c0, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(232), // short name
	L_GUN(74), // name
	L_GUN(0), // manufacturer
	L_GUN(190), // description
	0x34000018, // flags
};

struct weaponfunc_device invfunc_suicidepill_primary = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN(0), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(72), // short name
	L_GUN(72), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x08000010, // flags
};

struct weaponfunc_device invfunc_irscanner_primary = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN(138), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(69), // short name
	L_GUN(69), // name
	L_GUN(0), // manufacturer
	L_GUN(194), // description
	0x08001058, // flags
};

struct weaponfunc invfunc_disguise_primary = {
	INVENTORYFUNCTYPE_NONE,
	L_GUN(143), // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00000000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(43), // short name
	L_GUN(43), // name
	L_GUN(0), // manufacturer
	L_GUN(211), // description
	0x88000018, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(43), // short name
	L_GUN(43), // name
	L_GUN(0), // manufacturer
	L_GUN(211), // description
	0x88000018, // flags
};

struct weaponfunc_device invfunc_camspy_deploy = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN(136), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(60), // short name
	L_GUN(60), // name
	L_GUN(0), // manufacturer
	L_GUN(192), // description
	0x08001018, // flags
};

struct weaponfunc_device invfunc_rtracker_primary = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN(142), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(70), // short name
	L_GUN(70), // name
	L_GUN(0), // manufacturer
	L_GUN(198), // description
	0x08001018, // flags
};

struct weaponfunc_device invfunc_xray_primary = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN(137), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(233), // short name
	L_GUN(65), // name
	L_GUN(0), // manufacturer
	L_GUN(193), // description
	0x08600058, // flags
};

u32 invanim_datauplink_equip[] = {
	gunscript_playanimation(0x0439, 0, 10000)
	gunscript_end
};

u32 invanim_datauplink_unequip[] = {
	gunscript_playanimation(0x043a, 0, 10000)
	gunscript_end
};

u32 invanim_unused_8007f794[] = {
	gunscript_playanimation(0x043b, 0, 10000)
	gunscript_end
};

struct weaponfunc_special invfunc_datauplink_primary = {
	INVENTORYFUNCTYPE_SPECIAL,
	L_GUN(141), // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00102000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	8, // left/right
	-16.2, // up/down
	-17.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(75), // short name
	L_GUN(75), // name
	L_GUN(0), // manufacturer
	L_GUN(197), // description
	0x88022048, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	35, // left/right
	-26.7, // up/down
	-41, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(63), // short name
	L_GUN(63), // name
	L_GUN(0), // manufacturer
	L_GUN(200), // description
	0x88000008, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	12.5, // left/right
	-17, // up/down
	-27.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(44), // short name
	L_GUN(44), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x00000000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	12.5, // left/right
	-17, // up/down
	-27.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(45), // short name
	L_GUN(45), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x00000000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	12.5, // left/right
	-17, // up/down
	-27.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(46), // short name
	L_GUN(46), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x00000000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	12.5, // left/right
	-17, // up/down
	-27.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(48), // short name
	L_GUN(48), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x00000000, // flags
};

struct weaponfunc_special invfunc_unused_8006f9a4 = {
	INVENTORYFUNCTYPE_SPECIAL,
	L_GUN(144), // "Place Explosives"
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00102000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(221), // short name
	L_GUN(221), // name
	L_GUN(0), // manufacturer
	L_GUN(203), // description
	0x80000000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(64), // short name
	L_GUN(64), // name
	L_GUN(0), // manufacturer
	L_GUN(202), // description
	0x80000000, // flags
};

struct weaponfunc_device invfunc_presidentscanner_primary = {
	INVENTORYFUNCTYPE_DEVICE,
	L_GUN(142), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	0, // left/right
	-39.5, // up/down
	-55.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(231), // short name
	L_GUN(219), // name
	L_GUN(0), // manufacturer
	L_GUN(199), // description
	0x08001018, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(220), // short name
	L_GUN(220), // name
	L_GUN(0), // manufacturer
	L_GUN(201), // description
	0x88000000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(225), // short name
	L_GUN(225), // name
	L_GUN(0), // manufacturer
	L_GUN(207), // description
	0x08000000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(226), // short name
	L_GUN(226), // name
	L_GUN(0), // manufacturer
	L_GUN(208), // description
	0x08000000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(227), // short name
	L_GUN(227), // name
	L_GUN(0), // manufacturer
	L_GUN(209), // description
	0x08000000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(229), // short name
	L_GUN(229), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x08040000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(67), // short name
	L_GUN(67), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x88000000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(230), // short name
	L_GUN(230), // name
	L_GUN(0), // manufacturer
	L_GUN(238), // description
	0x08000000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(240), // short name
	L_GUN(240), // name
	L_GUN(0), // manufacturer
	L_GUN(241), // description
	0x08000000, // flags
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
	&inve_000110c0, // eptr
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(228), // short name
	L_GUN(228), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x08000000, // flags
};

struct weaponfunc_shootprojectile invfunc_rocketlauncher34_primary = {
	INVENTORYFUNCTYPE_SHOOT_PROJECTILE,
	L_GUN(0), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_rockerlauncher_equiporshoot, // fire animation
	0x08000040, // flags
	0x00000000,
	0x00000000,
	0x3f800000,
	0x40c00000,
	3, 12, 15, 0,
	0x40400000,
	0x40000000,
	0x00000000,
	0x40800000,
	0x04008053,
	0x01000000,
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
	0, // style
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
	&inve_000135f0, // eptr
	1, // sway
	24.5, // left/right
	-25.2, // up/down
	-30, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(80), // short name
	L_GUN(27), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x40026070, // flags
};

u32 invanim_tester_shoot[] = {
	gunscript_playanimation(0x0112, 0, 10000)
	gunscript_end
};

struct weaponfunc_shootsingle invfunc_tester_primary = {
	INVENTORYFUNCTYPE_SHOOT_SINGLE,
	L_GUN(0), // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_tester_shoot, // fire animation
	0x00000000, // flags
	&invmenupos_00011070,
	0x10000000,
	1, // damage
	0x40c00000,
	4, 8, 3, 0,
	0x00000000,
	0x00000000,
	0x426fffff,
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
	0, // style
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
	&inve_000110c0, // eptr
	1, // sway
	15.5, // left/right
	-20.2, // up/down
	-33.5, // front/back
	1, // unk38
	NULL, // fptr
	NULL, // part visibility
	L_GUN(58), // short name
	L_GUN(58), // name
	L_GUN(0), // manufacturer
	L_GUN(0), // description
	0x0000a47c, // flags
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
