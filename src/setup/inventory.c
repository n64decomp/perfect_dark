#include <ultra64.h>
#include "game/chr/chraicommands.h"
#include "game/game_000000.h"
#include "game/game_0601b0.h"
#include "setup/inventory.h"
#include "stagesetup.h"
#include "types.h"

// 10fd0
struct inventory_menupos invmenupos_00010fd0 = {
	0, 0, 0, 1, 6,
};

// 10fe4
struct inventory_menupos invmenupos_00010fe4 = {
	0, 3, 1.4, 1, 6,
};

// 10ff8
struct inventory_menupos invmenupos_00010ff8 = {
	0, 9, 2, 1, 6,
};

// 1100c
struct inventory_menupos invmenupos_0001100c = {
	0, 14, 2, 1, 6,
};

// 11020
struct inventory_menupos invmenupos_00011020 = {
	0, 18, 2, 1, 6,
};

// 11034
struct inventory_menupos invmenupos_00011034 = {
	0, 22, 3, 1, 6,
};

// 11048
struct inventory_menupos invmenupos_00011048 = {
	0, 25, 15, 5, 6,
};

// 1105c
struct inventory_menupos invmenupos_0001105c = {
	0, 35, 1, 1, 6,
};

// 11070
struct inventory_menupos invmenupos_00011070 = {
	0, 0, 0, 0.2, 2.3509887016446E-38,
};

// 11084
struct inventory_menupos invmenupos_00011084 = {
	0.2, 0.2, 0.2, 0.2, 2.3509887016446E-38,
};

// 11098
struct inventory_menupos invmenupos_00011098 = {
	0.6, 0.6, 0.6, 0.2, 2.3509887016446E-38,
};

// 110ac
struct inventory_menupos invmenupos_000110ac = {
	0.6, 0.6, 2.6, 0.2, 2.3509887016446E-38,
};

// 110c0
struct inventory_typee inve_000110c0 = {
	0x00000000,
	0x40400000,
	0x41000000,
	0x41700000,
	0x3f78db8c,
	0x3f7a0903,
	0x10000000,
	0x00000002,
};

// 110e0
struct inventory_typee inve_000110e0 = {
	0x00000000,
	0x40400000,
	0x41000000,
	0x41700000,
	0x3f78db8c,
	0x3f7a0903,
	0x10000000,
	0x00000006,
};

// 11100
struct inventory_typee inve_00011100 = {
	0x00000000,
	0x40400000,
	0x41000000,
	0x41700000,
	0x3f78db8c,
	0x3f7a0903,
	0x07000000,
	0x00000002,
};

// 11120
struct inventory_typee inve_00011120 = {
	0x41f00000,
	0x40400000,
	0x41000000,
	0x41700000,
	0x3f78db8c,
	0x3f7a0903,
	0x15000000,
	0x00000002,
};

// 11140
struct inventory_typee inve_00011140 = {
	0x41f00000,
	0x40400000,
	0x41000000,
	0x41700000,
	0x3f78db8c,
	0x3f7a0903,
	0x15000000,
	0x00000006,
};

// 11160
struct inventory_function invfunc_00011160 = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c55, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
};

u32 var00011174 = (u32) &invmenupos_00011098;
u32 var00011178 = 0x00000000;
u32 var0001117c = 0x3f800000;
u32 var00011180 = 0x40c00000;
u32 var00011184 = 0x06120208;
u32 var00011188 = 0x40a00000;
u32 var0001118c = 0x40000000;
u32 var00011190 = 0x00000000;
u32 var00011194 = 0x40800000;
u32 var00011198 = 0x04008039;
u32 var0001119c = 0x01000000;

// 111a0
struct inventory_ammo invammo_default = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	NULL, // reload animation
	0, // style
};

// 111b4
struct inventory_item invitem_hammer = {
	0x0000, // lo model
	0x0000, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	&invammo_default, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	12.500000, // left/right
	-17.000000, // up/down
	-27.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c00, // short name
	0x4c00, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x00001258, // flags
};

// 11204
struct inventory_item invitem_nothing = {
	0x0000, // lo model
	0x0000, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	12.500000, // left/right
	-17.000000, // up/down
	-27.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c00, // short name
	0x4c00, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x00001000, // flags
};

// 11254
u32 invanim_punch_type3[] = {
	gunscript_playanimation(0x03e9, 0, 10000)
	gunscript_waittime(7, 2)
	gunscript_end
};

// 1126c
u32 invanim_punch_type1[] = {
	gunscript_playanimation(0x03ea, 0, 10000)
	gunscript_waittime(8, 2)
	gunscript_end
};

// 11284
u32 invanim_punch_type2[] = {
	gunscript_playanimation(0x041f, 0, 10000)
	gunscript_waittime(7, 2)
	gunscript_end
};

// 1129c
u32 invanim_punch_type4[] = {
	gunscript_playanimation(0x0425, 0, 10000)
	gunscript_waittime(8, 2)
	gunscript_waittime(18, 3)
	gunscript_end
};

// 112bc
u32 invanim_punch[] = {
	gunscript_random(20, (u32) invanim_punch_type1)
	gunscript_random(40, (u32) invanim_punch_type2)
	gunscript_random(60, (u32) invanim_punch_type3)
	gunscript_include(0, (u32) invanim_punch_type4)
	gunscript_end
};

// 112e4
struct inventory_function invfunc_unarmed_punch = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_CLOSE,
	0x4c64, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_punch, // fire animation
	0x0041a200, // flags
};

u32 var000112f8 = 0x3f000000;
u32 var000112fc = 0x42700000;
u32 var00011300 = 0x00000069;
u32 var00011304 = 0x00000069;
u32 var00011308 = 0x00000069;
u32 var0001130c = 0x40f00000;
u32 var00011310 = 0xc20c0000;
u32 var00011314 = 0x40f00000;
u32 var00011318 = 0xc20c0000;
u32 var0001131c = 0xbf800000;
u32 var00011320 = 0xbf800000;
u32 var00011324 = 0x40000000;
u32 var00011328 = 0x40000000;
u32 var0001132c = 0x00000000;

// 11330
struct inventory_function invfunc_unarmed_disarm = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_CLOSE,
	0x4c65, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_punch, // fire animation
	0x0041a600, // flags
};

u32 var00011344 = 0x3e99999a;
u32 var00011348 = 0x42700000;
u32 var0001134c = 0x00000069;
u32 var00011350 = 0x00000069;
u32 var00011354 = 0x00000069;
u32 var00011358 = 0x40f00000;
u32 var0001135c = 0xc20c0000;
u32 var00011360 = 0x40f00000;
u32 var00011364 = 0xc20c0000;
u32 var00011368 = 0xbf800000;
u32 var0001136c = 0xbf800000;
u32 var00011370 = 0x40000000;
u32 var00011374 = 0x40000000;
u32 var00011378 = 0x00000000;

// 1137c
struct inventory_item invitem_unarmed = {
	0x04e5, // lo model
	0x04e5, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_unarmed_punch, // pri function
	&invfunc_unarmed_disarm, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_00011100, // eptr
	1.000000, // sway
	7.500000, // left/right
	-41.000000, // up/down
	-16.000000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c06, // short name
	0x4c06, // name
	0x4c00, // manufacturer
	0x4c9b, // description
	0x08042258, // flags
};

// 113cc
// type g
s8 invg_000113cc[] = {90, 0, 42, 0, 43, 0, 44, 0, 45, 0, 46, 0, 47, 0, -1};

// 113dc
// type g
s8 invg_000113dc[] = {90, 0, 42, 0, 43, 0, 45, 0, 47, 0, -1};

// 113e8
// type g
s8 invg_000113e8[] = {90, 0, 42, 0, 43, 0, 44, 0, 46, 0, -1};

// 113f4
struct inventory_typef invf_000113f4 = {
	0x01000000,
	0x0100002a,
	0x00000100,
	0x00000100,
	0x002b0000,
};

u32 var00011408 = 0x01000000;
u32 var0001140c = 0x0100002c;
u32 var00011410 = 0x00000100;
u32 var00011414 = 0x00000100;
u32 var00011418 = 0x002d0000;
u32 var0001141c = 0x01000000;
u32 var00011420 = 0x0100002e;
u32 var00011424 = 0x00000100;
u32 var00011428 = 0x00000100;
u32 var0001142c = 0x002f0000;
u32 var00011430 = 0x01000000;
u32 var00011434 = 0x01000035;
u32 var00011438 = 0x00000000;

// 1143c
u32 invanim_0001143c[] = {
	gunscript_end
};

// 11444
struct inventory_typef invf_00011444 = {
	0x01000000,
	0x0100002a,
	0x00000100,
	0x00000100,
	0x002b0000,
};

u32 var00011458 = 0x01000000;
u32 var0001145c = 0x0100002d;
u32 var00011460 = 0x00000100;
u32 var00011464 = 0x00000100;
u32 var00011468 = 0x002e0000;
u32 var0001146c = 0x01000000;
u32 var00011470 = 0x0100002f;
u32 var00011474 = 0x00000100;
u32 var00011478 = 0x00000100;
u32 var0001147c = 0x00350000;
u32 var00011480 = 0x00000000;
u32 var00011484 = 0x00000000;
u32 var00011488 = 0x00000000;

// 1148c
struct inventory_typef invf_0001148c = {
	0x01000000,
	0x0100002a,
	0x00000100,
	0x00000100,
	0x002b0000,
};

u32 var000114a0 = 0x01000000;
u32 var000114a4 = 0x0100002c;
u32 var000114a8 = 0x00000100;
u32 var000114ac = 0x00000100;
u32 var000114b0 = 0x002e0000;
u32 var000114b4 = 0x01000000;
u32 var000114b8 = 0x0100002f;
u32 var000114bc = 0x00000100;
u32 var000114c0 = 0x00000100;
u32 var000114c4 = 0x00350000;
u32 var000114c8 = 0x00000000;
u32 var000114cc = 0x00000000;
u32 var000114d0 = 0x00000000;

// 114d4
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

// 11534
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

// 11594
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

// 115d4
u32 invanim_falcon2_reload[] = {
	gunscript_include(1, (u32) invanim_falcon2_reload_1)
	gunscript_include(0, (u32) invanim_falcon2_reload_0)
	gunscript_end
};

// 115ec
u32 invanim_falcon2scope_reload[] = {
	gunscript_include(1, (u32) invanim_falcon2_reload_1)
	gunscript_include(0, (u32) invanim_falcon2scope_reload_0)
	gunscript_end
};

// 11604
u32 invanim_falcon2_pistolwhip[] = {
	gunscript_playanimation(0x03f2, 0, 10000)
	gunscript_waittime(23, 2)
	gunscript_end
};

// 1161c
u32 invanim_falcon2_equip[] = {
	gunscript_playanimation(0x00ea, 0, 10000)
	gunscript_end
};

// 1162c
u32 invanim_falcon2_unequip[] = {
	gunscript_playanimation(0x00eb, 0, 10000)
	gunscript_end
};

// 1163c
u32 invanim_falcon2_shoot[] = {
	gunscript_playanimation(0x00ec, 0, 10000)
	gunscript_waittime(9, 5)
	gunscript_end
};

// 11654
struct inventory_function invfunc_falcon2_singleshot = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c55, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_falcon2_shoot, // fire animation
	0x00000000, // flags
};

u32 var00011668 = (u32) &invmenupos_00011098;
u32 var0001166c = 0x10000000;
u32 var00011670 = 0x3f800000;
u32 var00011674 = 0x3f800000;
u32 var00011678 = 0x03050200;
u32 var0001167c = 0x41200000;
u32 var00011680 = 0x41700000;
u32 var00011684 = 0x426fffff;
u32 var00011688 = 0x00000000;
u32 var0001168c = 0x0000804d;
u32 var00011690 = 0x01000000;

// 11694
struct inventory_function invfunc_falcon2silenced_singleshot = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c55, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_falcon2_shoot, // fire animation
	0x00002000, // flags
};

u32 var000116a8 = (u32) &invmenupos_00011098;
u32 var000116ac = 0x10000000;
u32 var000116b0 = 0x3f800000;
u32 var000116b4 = 0x3f800000;
u32 var000116b8 = 0x03050200;
u32 var000116bc = 0x41200000;
u32 var000116c0 = 0x41700000;
u32 var000116c4 = 0x426fffff;
u32 var000116c8 = 0x00000000;
u32 var000116cc = 0x00008054;
u32 var000116d0 = 0x01000000;

// 116d4
struct inventory_function invfunc_falcon2_pistolwhip = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_CLOSE,
	0x4c5e, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_falcon2_pistolwhip, // fire animation
	0x0041a200, // flags
};

u32 var000116e8 = 0x3f666666;
u32 var000116ec = 0x42700000;
u32 var000116f0 = 0x00000069;
u32 var000116f4 = 0x00000069;
u32 var000116f8 = 0x00000069;
u32 var000116fc = 0xc1800000;
u32 var00011700 = 0x3f4ccccd;
u32 var00011704 = 0x41bc0000;
u32 var00011708 = 0xc202cccd;
u32 var0001170c = 0xbf800000;
u32 var00011710 = 0xbf800000;
u32 var00011714 = 0x40000000;
u32 var00011718 = 0x40000000;
u32 var0001171c = 0x00000000;

// 11720
struct inventory_ammo invammo_falcon2 = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_PISTOL,
	CASING_STANDARD,
	8, // clip size
	invanim_falcon2_reload, // reload animation
	0, // style
};

// 11734
struct inventory_ammo invammo_falcon2scope = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_PISTOL,
	CASING_STANDARD,
	8, // clip size
	invanim_falcon2scope_reload, // reload animation
	0, // style
};

// 11748
struct inventory_item invitem_falcon2 = {
	0x0377, // lo model
	0x039c, // hi model
	invanim_falcon2_equip, // equip animation
	invanim_falcon2_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_falcon2_singleshot, // pri function
	&invfunc_falcon2_pistolwhip, // sec function
	&invammo_falcon2, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	2.000000, // sway
	9.000000, // left/right
	-15.700000, // up/down
	-23.799999, // front/back
	1.000000, // unk38
	&invf_000113f4, // fptr
	invg_000113cc, // gptr
	0x4c07, // short name
	0x4c07, // name
	0x4c96, // manufacturer
	0x4c9c, // description
	0x000ab67c, // flags
};

// 11798
struct inventory_item invitem_falcon2scope = {
	0x0377, // lo model
	0x039c, // hi model
	invanim_falcon2_equip, // equip animation
	invanim_falcon2_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_falcon2_singleshot, // pri function
	&invfunc_falcon2_pistolwhip, // sec function
	&invammo_falcon2scope, // pri ammo
	NULL, // sec ammo
	&inve_00011120, // eptr
	1.000000, // sway
	9.000000, // left/right
	-15.700000, // up/down
	-23.799999, // front/back
	1.000000, // unk38
	&invf_00011444, // fptr
	invg_000113dc, // gptr
	0x4c4d, // short name
	0x4c09, // name
	0x4c96, // manufacturer
	0x4c9e, // description
	0x0002b67c, // flags
};

// 117e8
struct inventory_item invitem_falcon2silencer = {
	0x0377, // lo model
	0x039c, // hi model
	invanim_falcon2_equip, // equip animation
	invanim_falcon2_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_falcon2silenced_singleshot, // pri function
	&invfunc_falcon2_pistolwhip, // sec function
	&invammo_falcon2, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	9.000000, // left/right
	-15.700000, // up/down
	-23.799999, // front/back
	1.000000, // unk38
	&invf_0001148c, // fptr
	invg_000113e8, // gptr
	0x4c4e, // short name
	0x4c08, // name
	0x4c96, // manufacturer
	0x4c9d, // description
	0x000ab67c, // flags
};

// 11838
// type g
s8 invg_00011838[] = {90, 0, 41, 0, 42, 0, -1};

// 11840
struct inventory_typef invf_00011840 = {
	0x01000000,
	0x01000035,
	0x00000100,
	0x00000100,
	0x002a0000,
};

u32 var00011854 = 0x01000000;
u32 var00011858 = 0x01000029;
u32 var0001185c = 0x00000000;
u32 var00011860 = 0x00000000;
u32 var00011864 = 0x00000000;

// 11868
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

// 118e8
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

// 11940
u32 invanim_magsec_reload[] = {
	gunscript_include(1, (u32) invanim_magsec_reload_1)
	gunscript_include(0, (u32) invanim_magsec_reload_0)
	gunscript_end
};

// 11958
u32 invanim_magsec_equiporshoot[] = {
	gunscript_playanimation(0x040b, 0, 10000)
	gunscript_waittime(12, 5)
	gunscript_end
};

// 11970
struct inventory_typee inve_00011970 = {
	0x41c80000,
	0x40400000,
	0x41000000,
	0x41700000,
	0x3f78db8c,
	0x3f7a0903,
	0x11000000,
	0x00000002,
};

// 11990
struct inventory_function invfunc_magsec_singleshot = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c55, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_magsec_equiporshoot, // fire animation
	0x00000000, // flags
};

u32 var000119a4 = (u32) &invmenupos_00011098;
u32 var000119a8 = 0x10000000;
u32 var000119ac = 0x3f8ccccd;
u32 var000119b0 = 0x40c00000;
u32 var000119b4 = 0x04080300;
u32 var000119b8 = 0x40a00000;
u32 var000119bc = 0x41200000;
u32 var000119c0 = 0x426fffff;
u32 var000119c4 = 0x41200000;
u32 var000119c8 = 0x0000804c;
u32 var000119cc = 0x01000000;

// 119d0
struct inventory_function invfunc_magsec_burst = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c80, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_magsec_equiporshoot, // fire animation
	0x00000002, // flags
};

u32 var000119e4 = (u32) &invmenupos_00011098;
u32 var000119e8 = 0x10000000;
u32 var000119ec = 0x3f8ccccd;
u32 var000119f0 = 0x41200000;
u32 var000119f4 = 0x090e0000;
u32 var000119f8 = 0x41000000;
u32 var000119fc = 0x41400000;
u32 var00011a00 = 0x426fffff;
u32 var00011a04 = 0x41200000;
u32 var00011a08 = 0x0000804c;
u32 var00011a0c = 0x01000000;

// 11a10
struct inventory_ammo invammo_magsec = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_PISTOL,
	CASING_STANDARD,
	9, // clip size
	invanim_magsec_reload, // reload animation
	0, // style
};

// 11a24
struct inventory_item invitem_magsec = {
	0x0378, // lo model
	0x04c4, // hi model
	invanim_magsec_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_magsec_singleshot, // pri function
	&invfunc_magsec_burst, // sec function
	&invammo_magsec, // pri ammo
	NULL, // sec ammo
	&inve_00011970, // eptr
	2.000000, // sway
	10.500000, // left/right
	-17.200001, // up/down
	-26.500000, // front/back
	1.000000, // unk38
	&invf_00011840, // fptr
	invg_00011838, // gptr
	0x4c0a, // short name
	0x4c0a, // name
	0x4c97, // manufacturer
	0x4c9f, // description
	0x000a767c, // flags
};

// 11a74
// type g
s8 invg_00011a74[] = {90, 0, 40, 0, 41, 0, 42, 0, 43, 0, 44, 0, 45, 0, -1};

// 11a84
struct inventory_typef invf_00011a84 = {
	0x01000000,
	0x01000028,
	0x00000100,
	0x00000100,
	0x00290000,
};

u32 var00011a98 = 0x01000000;
u32 var00011a9c = 0x0100002a;
u32 var00011aa0 = 0x00000100;
u32 var00011aa4 = 0x00000100;
u32 var00011aa8 = 0x002b0000;
u32 var00011aac = 0x01000000;
u32 var00011ab0 = 0x0100002c;
u32 var00011ab4 = 0x00000100;
u32 var00011ab8 = 0x00000100;
u32 var00011abc = 0x002d0000;
u32 var00011ac0 = 0x01000000;
u32 var00011ac4 = 0x01000035;
u32 var00011ac8 = 0x00000000;
u32 var00011acc = 0x00000000;
u32 var00011ad0 = 0x00000000;

// 11ad4
u32 invanim_dy357_equiporshoot[] = {
	gunscript_playanimation(0x0406, 0, 10000)
	gunscript_waittime(12, 5)
	gunscript_waittime(12, 2)
	gunscript_end
};

// 11af4
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

// 11bd4
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

// 11c4c
u32 invanim_dy357_reload[] = {
	gunscript_include(1, (u32) invanim_dy357_reload_1)
	gunscript_include(0, (u32) invanim_dy357_reload_0)
	gunscript_end
};

// 11c64
u32 invanim_dy357_pistolwhip[] = {
	gunscript_playanimation(0x0407, 0, 10000)
	gunscript_waittime(23, 2)
	gunscript_end
};

// 11c7c
struct inventory_function invfunc_dy357_singleshot = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c55, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_dy357_equiporshoot, // fire animation
	0x00000000, // flags
};

u32 var00011c90 = (u32) &invmenupos_00011098;
u32 var00011c94 = 0x14000000;
u32 var00011c98 = 0x40000000;
u32 var00011c9c = 0x00000000;
u32 var00011ca0 = 0x081000ff;
u32 var00011ca4 = 0x41400000;
u32 var00011ca8 = 0x420c0000;
u32 var00011cac = 0x00000000;
u32 var00011cb0 = 0x40c00000;
u32 var00011cb4 = 0x00008066;
u32 var00011cb8 = 0x05000000;

// 11cbc
struct inventory_function invfunc_dy357lx_singleshot = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c55, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_dy357_equiporshoot, // fire animation
	0x00000000, // flags
};

u32 var00011cd0 = (u32) &invmenupos_00011098;
u32 var00011cd4 = 0x1e000000;
u32 var00011cd8 = 0x43480000;
u32 var00011cdc = 0x00000000;
u32 var00011ce0 = 0x081800ff;
u32 var00011ce4 = 0x41400000;
u32 var00011ce8 = 0x420c0000;
u32 var00011cec = 0x00000000;
u32 var00011cf0 = 0x40c00000;
u32 var00011cf4 = 0x00008066;
u32 var00011cf8 = 0x05000000;

// 11cfc
struct inventory_function invfunc_dy357_pistolwhip = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_CLOSE,
	0x4c5e, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_dy357_pistolwhip, // fire animation
	0x0041a200, // flags
};

u32 var00011d10 = 0x3f666666;
u32 var00011d14 = 0x42700000;
u32 var00011d18 = 0x00000069;
u32 var00011d1c = 0x00000069;
u32 var00011d20 = 0x00000069;
u32 var00011d24 = 0x41980000;
u32 var00011d28 = 0xc195999a;
u32 var00011d2c = 0x41980000;
u32 var00011d30 = 0xc195999a;
u32 var00011d34 = 0xbf800000;
u32 var00011d38 = 0xbf800000;
u32 var00011d3c = 0x40000000;
u32 var00011d40 = 0x40000000;
u32 var00011d44 = 0x00000000;

// 11d48
struct inventory_ammo invammo_dy357 = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_MAGNUM,
	CASING_STANDARD,
	6, // clip size
	invanim_dy357_reload, // reload animation
	0, // style
};

// 11d5c
struct inventory_item invitem_dy357 = {
	0x037a, // lo model
	0x04bd, // hi model
	invanim_dy357_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_dy357_singleshot, // pri function
	&invfunc_dy357_pistolwhip, // sec function
	&invammo_dy357, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	2.000000, // sway
	9.500000, // left/right
	-18.200001, // up/down
	-25.500000, // front/back
	1.000000, // unk38
	&invf_00011a84, // fptr
	invg_00011a74, // gptr
	0x4c54, // short name
	0x4c0c, // name
	0x4c95, // manufacturer
	0x4ca1, // description
	0x0002f67c, // flags
};

// 11dac
struct inventory_item invitem_dy357lx = {
	0x037b, // lo model
	0x04be, // hi model
	invanim_dy357_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_dy357lx_singleshot, // pri function
	&invfunc_dy357_pistolwhip, // sec function
	&invammo_dy357, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	2.000000, // sway
	9.500000, // left/right
	-18.200001, // up/down
	-25.500000, // front/back
	1.000000, // unk38
	&invf_00011a84, // fptr
	invg_00011a74, // gptr
	0x4c0d, // short name
	0x4c0d, // name
	0x4c95, // manufacturer
	0x4ca2, // description
	0x0002f67c, // flags
};

// 11dfc
// type g
s8 invg_00011dfc[] = {40, 0, -1};

// 11e00
struct inventory_typef invf_00011e00 = {
	0x01000000,
	0x01000028,
	0x00000100,
	0x00000100,
	0x00350000,
};

u32 var00011e14 = 0x00000000;
u32 var00011e18 = 0x00000000;
u32 var00011e1c = 0x00000000;

// 11e20
u32 invanim_equiporreload_0[] = {
	gunscript_playanimation(0x0415, 0, 10000)
	gunscript_showpart(1, 53)
	gunscript_showpart(1, 40)
	gunscript_setsoundspeed(44, 1510)
	gunscript_playsound(44, 0x0433)
	gunscript_hidepart(50, 40)
	gunscript_end
};

// 11e58
u32 invanim_phoenix_equiporreload_1[] = {
	gunscript_playanimation(0x0423, 0, 10000)
	gunscript_showpart(1, 53)
	gunscript_showpart(1, 40)
	gunscript_setsoundspeed(44, 1510)
	gunscript_playsound(44, 0x0433)
	gunscript_hidepart(50, 40)
	gunscript_end
};

// 11e90
u32 invanim_phoenix_equiporreload[] = {
	gunscript_include(1, (u32) invanim_phoenix_equiporreload_1)
	gunscript_include(0, (u32) invanim_equiporreload_0)
	gunscript_end
};

// 11ea8
u32 invanim_phoenix_shoot[] = {
	gunscript_playanimation(0x043e, 0, 10000)
	gunscript_waittime(9, 5)
	gunscript_end
};

// 11ec0
struct inventory_function invfunc_phoenix_singleshot = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c55, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_phoenix_shoot, // fire animation
	0x00000000, // flags
};

u32 var00011ed4 = (u32) &invmenupos_00011098;
u32 var00011ed8 = 0x10000000;
u32 var00011edc = 0x3f8ccccd;
u32 var00011ee0 = 0x40400000;
u32 var00011ee4 = 0x03050200;
u32 var00011ee8 = 0x41200000;
u32 var00011eec = 0x41700000;
u32 var00011ef0 = 0x426fffff;
u32 var00011ef4 = 0x00000000;
u32 var00011ef8 = 0x00008071;
u32 var00011efc = 0x01000000;

// 11f00
struct inventory_function invfunc_phoenix_explosiveshells = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c5f, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_phoenix_shoot, // fire animation
	0x00004000, // flags
};

u32 var00011f14 = (u32) &invmenupos_00011098;
u32 var00011f18 = 0x10000000;
u32 var00011f1c = 0x3f99999a;
u32 var00011f20 = 0x40a00000;
u32 var00011f24 = 0x0d0f1900;
u32 var00011f28 = 0x41700000;
u32 var00011f2c = 0x41c80000;
u32 var00011f30 = 0x426fffff;
u32 var00011f34 = 0x00000000;
u32 var00011f38 = 0x00008072;
u32 var00011f3c = 0x01000000;

// 11f40
struct inventory_ammo invammo_phoenix = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_PISTOL,
	CASING_NONE,
	8, // clip size
	invanim_phoenix_equiporreload, // reload animation
	0, // style
};

// 11f54
struct inventory_item invitem_phoenix = {
	0x037c, // lo model
	0x04c5, // hi model
	invanim_phoenix_equiporreload, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_phoenix_singleshot, // pri function
	&invfunc_phoenix_explosiveshells, // sec function
	&invammo_phoenix, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	9.500000, // left/right
	-16.200001, // up/down
	-23.000000, // front/back
	1.000000, // unk38
	&invf_00011e00, // fptr
	invg_00011dfc, // gptr
	0x4c0e, // short name
	0x4c0e, // name
	0x4c99, // manufacturer
	0x4ca3, // description
	0x000af67c, // flags
};

// 11fa4
// type g
s8 invg_00011fa4[] = {43, 0, 90, 0, -1};


// 11fac
struct inventory_typef invf_00011fac = {
	0x01000000,
	0x01000035,
	0x00000100,
	0x00000100,
	0x002b0000,
};

u32 var00011fc0 = 0x00000000;
u32 var00011fc4 = 0x00000000;
u32 var00011fc8 = 0x00000000;

// 11fcc
u32 invanim_mauler_equiporshoot[] = {
	gunscript_playanimation(0x03f3, 0, 10000)
	gunscript_waittime(9, 5)
	gunscript_end
};

// 11fe4
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

// 1206c
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

// 120c4
u32 invanim_mauler_reload[] = {
	gunscript_include(1, (u32) invanim_mauler_reload_1)
	gunscript_include(0, (u32) invanim_mauler_reload_0)
	gunscript_end
};

u32 var000120dc = 0x0a0003f6;
u32 var000120e0 = 0x00002710;
u32 var000120e4 = 0x00000000;
u32 var000120e8 = 0x00000000;

// 120ec
struct inventory_function invfunc_mauler_singleshot = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c55, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_mauler_equiporshoot, // fire animation
	0x00000000, // flags
};

u32 var00012100 = (u32) &invmenupos_00011098;
u32 var00012104 = 0x00000000;
u32 var00012108 = 0x3f99999a;
u32 var0001210c = 0x40c00000;
u32 var00012110 = 0x0309201c;
u32 var00012114 = 0x00000000;
u32 var00012118 = 0x00000000;
u32 var0001211c = 0x426fffff;
u32 var00012120 = 0x40800000;
u32 var00012124 = 0x0000805b;
u32 var00012128 = 0x01000000;

// 1212c
struct inventory_function invfunc_mauler_chargeshot = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c81, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_mauler_equiporshoot, // fire animation
	0x00000000, // flags
};

u32 var00012140 = (u32) &invmenupos_00011098;
u32 var00012144 = 0x00000000;
u32 var00012148 = 0x3f99999a;
u32 var0001214c = 0x40c00000;
u32 var00012150 = 0x0309201c;
u32 var00012154 = 0x00000000;
u32 var00012158 = 0x00000000;
u32 var0001215c = 0x426fffff;
u32 var00012160 = 0x40800000;
u32 var00012164 = 0x0000805b;
u32 var00012168 = 0x01000000;

// 1216c
struct inventory_ammo invammo_mauler = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_PISTOL,
	CASING_NONE,
	20, // clip size
	invanim_mauler_reload, // reload animation
	0, // style
};

// 12180
struct inventory_item invitem_mauler = {
	0x0379, // lo model
	0x04cb, // hi model
	invanim_mauler_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_mauler_singleshot, // pri function
	&invfunc_mauler_chargeshot, // sec function
	&invammo_mauler, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	11.500000, // left/right
	-17.500000, // up/down
	-20.000000, // front/back
	1.000000, // unk38
	&invf_00011fac, // fptr
	invg_00011fa4, // gptr
	0x4c0b, // short name
	0x4c0b, // name
	0x4c98, // manufacturer
	0x4ca0, // description
	0x00027678, // flags
};

// 121d0
// type g
s8 invg_000121d0[] = {90, 0, 43, 0, -1};


// 121d8
struct inventory_typef invf_000121d8 = {
	0x01000000,
	0x01000035,
	0x00000100,
	0x00000100,
	0x002b0000,
};

u32 var000121ec = 0x01000000;
u32 var000121f0 = 0x01000047;
u32 var000121f4 = 0x00000000;
u32 var000121f8 = 0x00000000;
u32 var000121fc = 0x00000000;

// 12200
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

// 12268
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

// 122d0
u32 invanim_cmp150_reload[] = {
	gunscript_include(1, (u32) invanim_cmp150_reload_1)
	gunscript_include(0, (u32) invanim_cmp150_reload_0)
	gunscript_end
};

// 122e8
u32 invanim_cmp150_equiporshoot[] = {
	gunscript_playanimation(0x0116, 0, 10000)
	gunscript_waittime(14, 5)
	gunscript_waitforzreleased(14)
	gunscript_end
};

// 12308
struct inventory_typee inve_00012308 = {
	0x00000000,
	0x40400000,
	0x41000000,
	0x41700000,
	0x3f78db8c,
	0x3f7a0903,
	0x40000000,
	0x00000006,
};

// 12328
struct inventory_function invfunc_cmp150_rapidfire = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c56, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_cmp150_equiporshoot, // fire animation
	0x00000000, // flags
};

u32 var0001233c = (u32) &invmenupos_00011098;
u32 var00012340 = 0x00000000;
u32 var00012344 = 0x3f800000;
u32 var00012348 = 0x41100000;
u32 var0001234c = 0x06120006;
u32 var00012350 = 0x40800000;
u32 var00012354 = 0x40400000;
u32 var00012358 = 0x00000000;
u32 var0001235c = 0x00000000;
u32 var00012360 = 0x03008040;
u32 var00012364 = 0x01000000;
u32 var00012368 = 0x44610000;
u32 var0001236c = 0x44610000;
u32 var00012370 = 0x00000000;
u32 var00012374 = 0x00000000;
u32 var00012378 = 0x00000000;

// 1237c
struct inventory_function invfunc_cmp150_followlockon = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c66, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_cmp150_equiporshoot, // fire animation
	0x00000000, // flags
};

u32 var00012390 = (u32) &invmenupos_00011098;
u32 var00012394 = 0x00000000;
u32 var00012398 = 0x3f800000;
u32 var0001239c = 0x41100000;
u32 var000123a0 = 0x06120006;
u32 var000123a4 = 0x40800000;
u32 var000123a8 = 0x40400000;
u32 var000123ac = 0x00000000;
u32 var000123b0 = 0x00000000;
u32 var000123b4 = 0x03008040;
u32 var000123b8 = 0x01000000;
u32 var000123bc = 0x44610000;
u32 var000123c0 = 0x44610000;
u32 var000123c4 = 0x00000000;
u32 var000123c8 = 0x00000000;
u32 var000123cc = 0x00000000;

// 123d0
struct inventory_ammo invammo_cmp150 = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_SMG,
	CASING_STANDARD,
	32, // clip size
	invanim_cmp150_reload, // reload animation
	0, // style
};

// 123e4
struct inventory_item invitem_cmp150 = {
	0x037d, // lo model
	0x04b9, // hi model
	invanim_cmp150_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_cmp150_rapidfire, // pri function
	&invfunc_cmp150_followlockon, // sec function
	&invammo_cmp150, // pri ammo
	NULL, // sec ammo
	&inve_00012308, // eptr
	3.000000, // sway
	13.000000, // left/right
	-17.700001, // up/down
	-27.500000, // front/back
	1.000000, // unk38
	&invf_000121d8, // fptr
	invg_000121d0, // gptr
	0x4c0f, // short name
	0x4c0f, // name
	0x4c95, // manufacturer
	0x4ca4, // description
	0x4402f678, // flags
};

// 12434
// type g
s8 invg_00012434[] = {90, 0, 40, 0, -1};


// 1243c
struct inventory_typef invf_0001243c = {
	0x01000000,
	0x01000035,
	0x00000100,
	0x00000100,
	0x00280000,
};

u32 var00012450 = 0x00000000;
u32 var00012454 = 0x00000000;
u32 var00012458 = 0x00000000;

// 1245c
u32 invanim_cyclone_equiporreload_0[] = {
	gunscript_playanimation(0x040e, 0, 10000)
	gunscript_showpart(1, 53)
	gunscript_showpart(1, 40)
	gunscript_playsound(60, 0x05d3)
	gunscript_end
};

// 12484
u32 invanim_cyclone_equiporreload_1[] = {
	gunscript_playanimation(0x0421, 0, 10000)
	gunscript_playsound(60, 0x05d3)
	gunscript_end
};

// 1249c
u32 invanim_cyclone_equiporreload[] = {
	gunscript_include(1, (u32) invanim_cyclone_equiporreload_1)
	gunscript_include(0, (u32) invanim_cyclone_equiporreload_0)
	gunscript_end
};

// 124b4
u32 invanim_cyclone_shoot[] = {
	gunscript_playanimation(0x043d, 0, 10000)
	gunscript_waittime(5, 5)
	gunscript_waitforzreleased(5)
	gunscript_end
};

// 124d4
struct inventory_function invfunc_cyclone_rapidfire = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c56, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_cyclone_shoot, // fire animation
	0x00000000, // flags
};

u32 var000124e8 = (u32) &invmenupos_00011098;
u32 var000124ec = 0x00000000;
u32 var000124f0 = 0x3f4ccccd;
u32 var000124f4 = 0x40c00000;
u32 var000124f8 = 0x06120208;
u32 var000124fc = 0x40a00000;
u32 var00012500 = 0x40000000;
u32 var00012504 = 0x00000000;
u32 var00012508 = 0x40800000;
u32 var0001250c = 0x0400805f;
u32 var00012510 = 0x01000000;
u32 var00012514 = 0x44610000;
u32 var00012518 = 0x44610000;
u32 var0001251c = 0x00000000;
u32 var00012520 = 0x00000000;
u32 var00012524 = 0x00000000;

// 12528
struct inventory_function invfunc_cyclone_magazinedischarge = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c61, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_cyclone_shoot, // fire animation
	0x00000020, // flags
};

u32 var0001253c = (u32) &invmenupos_00011098;
u32 var00012540 = 0x00000000;
u32 var00012544 = 0x3fb33333;
u32 var00012548 = 0x41c80000;
u32 var0001254c = 0x06120208;
u32 var00012550 = 0x40a00000;
u32 var00012554 = 0x40000000;
u32 var00012558 = 0x00000000;
u32 var0001255c = 0x40800000;
u32 var00012560 = 0x04008075;
u32 var00012564 = 0x01000000;
u32 var00012568 = 0x44fa0000;
u32 var0001256c = 0x44fa0000;
u32 var00012570 = 0x00000000;
u32 var00012574 = 0x00000000;
u32 var00012578 = 0x00000000;

// 1257c
struct inventory_ammo invammo_cyclone = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_SMG,
	CASING_NONE,
	50, // clip size
	invanim_cyclone_equiporreload, // reload animation
	0, // style
};

// 12590
struct inventory_item invitem_cyclone = {
	0x0382, // lo model
	0x04bb, // hi model
	invanim_cyclone_equiporreload, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_cyclone_rapidfire, // pri function
	&invfunc_cyclone_magazinedischarge, // sec function
	&invammo_cyclone, // pri ammo
	NULL, // sec ammo
	&inve_000110e0, // eptr
	1.000000, // sway
	21.500000, // left/right
	-26.500000, // up/down
	-35.000000, // front/back
	1.000000, // unk38
	&invf_0001243c, // fptr
	invg_00012434, // gptr
	0x4c14, // short name
	0x4c14, // name
	0x4c97, // manufacturer
	0x4ca9, // description
	0x00027678, // flags
};

// 125e0
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

// 12630
u32 invanim_rcp120_equiporshoot[] = {
	gunscript_playanimation(0x0424, 0, 10000)
	gunscript_waittime(10, 5)
	gunscript_waitforzreleased(10)
	gunscript_end
};

// 12650
// type g
s8 invg_00012650[] = {90, 0, 41, 0, -1};


// 12658
struct inventory_typef invf_00012658 = {
	0x01000000,
	0x01000029,
	0x00000000,
	0x00000000,
	0x00000000,
};

// 1266c
struct inventory_function invfunc_rcp120_rapidfire = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c56, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_rcp120_equiporshoot, // fire animation
	0x00000000, // flags
};

u32 var00012680 = (u32) &invmenupos_00011098;
u32 var00012684 = 0x00000000;
u32 var00012688 = 0x3f99999a;
u32 var0001268c = 0x40c00000;
u32 var00012690 = 0x06120006;
u32 var00012694 = 0x40800000;
u32 var00012698 = 0x40400000;
u32 var0001269c = 0x00000000;
u32 var000126a0 = 0x00000000;
u32 var000126a4 = 0x0400806d;
u32 var000126a8 = 0x01000000;
u32 var000126ac = 0x44898000;
u32 var000126b0 = 0x44898000;
u32 var000126b4 = 0x00000000;
u32 var000126b8 = 0x00000000;
u32 var000126bc = 0x00000000;

// 126c0
struct inventory_function invfunc_rcp120_cloak = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SPECIAL,
	0x4c74, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00102000, // flags
};

u32 var000126d4 = 0x00000009;
u32 var000126d8 = 0x0000001e;
u32 var000126dc = 0x00000000;

// 126e0
struct inventory_ammo invammo_rcp120 = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_SMG,
	CASING_STANDARD,
	120, // clip size
	invanim_rcp120_reload, // reload animation
	0, // style
};

// 126f4
struct inventory_item invitem_rcp120 = {
	0x0384, // lo model
	0x04c8, // hi model
	invanim_rcp120_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_rcp120_rapidfire, // pri function
	&invfunc_rcp120_cloak, // sec function
	&invammo_rcp120, // pri ammo
	NULL, // sec ammo
	&inve_000110e0, // eptr
	3.000000, // sway
	13.000000, // left/right
	-18.200001, // up/down
	-27.500000, // front/back
	1.000000, // unk38
	&invf_00012658, // fptr
	invg_00012650, // gptr
	0x4c16, // short name
	0x4c16, // name
	0x4c97, // manufacturer
	0x4caa, // description
	0x0062e670, // flags
};

// 12744
u32 invanim_callisto_equiporreload[] = {
	gunscript_playanimation(0x0418, 0, 10000)
	gunscript_showpart(30, 40)
	gunscript_setsoundspeed(58, 933)
	gunscript_playsound(58, 0x0433)
	gunscript_hidepart(79, 40)
	gunscript_end
};

// 12774
u32 invanim_callisto_shoot[] = {
	gunscript_playanimation(0x043c, 0, 10000)
	gunscript_waittime(8, 5)
	gunscript_waitforzreleased(8)
	gunscript_end
};

// 12794
// type g
s8 invg_00012794[] = {40, 0, -1};

// 12798
struct inventory_typef invf_00012798 = {
	0x01000000,
	0x01000028,
	0x00000000,
	0x00000000,
	0x00000000,
};

// 127ac
struct inventory_function invfunc_callisto_rapidfire = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c56, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_callisto_shoot, // fire animation
	0x00000000, // flags
};

u32 var000127c0 = (u32) &invmenupos_00011098;
u32 var000127c4 = 0x00000000;
u32 var000127c8 = 0x3f99999a;
u32 var000127cc = 0x41100000;
u32 var000127d0 = 0x06120006;
u32 var000127d4 = 0x40800000;
u32 var000127d8 = 0x40400000;
u32 var000127dc = 0x00000000;
u32 var000127e0 = 0x00000000;
u32 var000127e4 = 0x03008063;
u32 var000127e8 = 0x01000000;
u32 var000127ec = 0x44610000;
u32 var000127f0 = 0x44610000;
u32 var000127f4 = 0x00000000;
u32 var000127f8 = 0x00000000;
u32 var000127fc = 0x00000000;

// 12800
struct inventory_function invfunc_callisto_highimpactshells = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c73, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_callisto_shoot, // fire animation
	0x00000000, // flags
};

u32 var00012814 = (u32) &invmenupos_00011098;
u32 var00012818 = 0x00000000;
u32 var0001281c = 0x4019999a;
u32 var00012820 = 0x41100000;
u32 var00012824 = 0x06120006;
u32 var00012828 = 0x40800000;
u32 var0001282c = 0x40400000;
u32 var00012830 = 0x00000000;
u32 var00012834 = 0x00000000;
u32 var00012838 = 0x03008064;
u32 var0001283c = 0x05000000;
u32 var00012840 = 0x43960000;
u32 var00012844 = 0x43960000;
u32 var00012848 = 0x00000000;
u32 var0001284c = 0x00000000;
u32 var00012850 = 0x00000000;

// 12854
struct inventory_ammo invammo_callisto = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_SMG,
	CASING_NONE,
	32, // clip size
	invanim_callisto_equiporreload, // reload animation
	0, // style
};

// 12868
struct inventory_item invitem_callisto = {
	0x0383, // lo model
	0x04c6, // hi model
	invanim_callisto_equiporreload, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_callisto_rapidfire, // pri function
	&invfunc_callisto_highimpactshells, // sec function
	&invammo_callisto, // pri ammo
	NULL, // sec ammo
	&inve_000110e0, // eptr
	3.000000, // sway
	17.500000, // left/right
	-22.700001, // up/down
	-25.000000, // front/back
	1.000000, // unk38
	&invf_00012798, // fptr
	invg_00012794, // gptr
	0x4c17, // short name
	0x4c17, // name
	0x4c99, // manufacturer
	0x4cab, // description
	0x0002e670, // flags
};

// 128b8
struct inventory_typef invf_000128b8 = {
	0x01000000,
	0x01000028,
	0x00000000,
	0x00000000,
	0x00000000,
};

// 128cc
// type g
s8 invg_000128cc[] = {40, 0, 90, 0, -1};


// 128d4
u32 invanim_dragon_equiporshoot[] = {
	gunscript_playanimation(0x03f9, 0, 10000)
	gunscript_end
};

// 128e4
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

// 1292c
struct inventory_function invfunc_dragon_rapidfire = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c56, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_dragon_equiporshoot, // fire animation
	0x00000000, // flags
};

u32 var00012940 = (u32) &invmenupos_00011098;
u32 var00012944 = 0x00000000;
u32 var00012948 = 0x3f8ccccd;
u32 var0001294c = 0x40c00000;
u32 var00012950 = 0x06120208;
u32 var00012954 = 0x40a00000;
u32 var00012958 = 0x40000000;
u32 var0001295c = 0x00000000;
u32 var00012960 = 0x40800000;
u32 var00012964 = 0x04008049;
u32 var00012968 = 0x01000000;
u32 var0001296c = 0x442f0000;
u32 var00012970 = 0x442f0000;
u32 var00012974 = 0x00000000;
u32 var00012978 = 0x00000000;
u32 var0001297c = 0x00000000;

// 12980
struct inventory_function invfunc_dragon_selfdestruct = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_THROW,
	0x4c76, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00042040, // flags
};

u32 var00012994 = 0x000000ff;
u32 var00012998 = 0x00f00000;
u32 var0001299c = 0x0000003c;
u32 var000129a0 = 0x00000000;

// 129a4
struct inventory_ammo invammo_dragon = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	invanim_dragon_reload, // reload animation
	0, // style
};

// 129b8
struct inventory_item invitem_dragon = {
	0x037f, // lo model
	0x04c0, // hi model
	invanim_dragon_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_dragon_rapidfire, // pri function
	&invfunc_dragon_selfdestruct, // sec function
	&invammo_dragon, // pri ammo
	NULL, // sec ammo
	&inve_00011140, // eptr
	1.000000, // sway
	15.000000, // left/right
	-29.500000, // up/down
	-27.000000, // front/back
	1.000000, // unk38
	&invf_000128b8, // fptr
	invg_000128cc, // gptr
	0x4c11, // short name
	0x4c11, // name
	0x4c95, // manufacturer
	0x4ca6, // description
	0x04026650, // flags
};

// 12a08
struct inventory_typef invf_00012a08 = {
	0x01000000,
	0x01000028,
	0x00000100,
	0x00000100,
	0x00290000,
};

u32 var00012a1c = 0x00000000;
u32 var00012a20 = 0x00000000;
u32 var00012a24 = 0x00000000;

// 12a28
// type g
s8 invg_00012a28[] = {40, 0, 41, 0, 90, 0, -1};

// 12a30
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

// 12a78
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

// 12ad0
u32 invanim_superdragon_equiporshoot[] = {
	gunscript_playanimation(0x03fe, 0, 10000)
	gunscript_end
};

// 12ae0
u32 invanim_superdragon_shootgrenade[] = {
	gunscript_playanimation(0x03ff, 0, 10000)
	gunscript_end
};

// 12af0
u32 invanim_superdragon_pritosec[] = {
	gunscript_playanimation(0x03fd, 0, 10000)
	gunscript_end
};

// 12b00
u32 invanim_superdragon_sectopri[] = {
	gunscript_playanimation(0x03fd, 65535, 55536)
	gunscript_end
};

// 12b10
struct inventory_function invfunc_superdragon_rapidfire = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c56, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_superdragon_equiporshoot, // fire animation
	0x00000000, // flags
};

u32 var00012b24 = (u32) &invmenupos_00011098;
u32 var00012b28 = 0x00000000;
u32 var00012b2c = 0x3f99999a;
u32 var00012b30 = 0x40c00000;
u32 var00012b34 = 0x06120208;
u32 var00012b38 = 0x40a00000;
u32 var00012b3c = 0x40000000;
u32 var00012b40 = 0x00000000;
u32 var00012b44 = 0x40800000;
u32 var00012b48 = 0x04008049;
u32 var00012b4c = 0x01000000;
u32 var00012b50 = 0x442f0000;
u32 var00012b54 = 0x442f0000;
u32 var00012b58 = 0x00000000;
u32 var00012b5c = 0x00000000;
u32 var00012b60 = 0x00000000;

// 12b64
struct inventory_function invfunc_superdragon_grenadelauncher = {
	0x0000, // unk00
	0x02, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c62, // name
	0x00, // unk06
	1, // unk07
	&invmenupos_00011048, // menupos
	invanim_superdragon_shootgrenade, // fire animation
	0x30000040, // flags
};

u32 var00012b78 = 0x00000000;
u32 var00012b7c = 0x00000000;
u32 var00012b80 = 0x3f99999a;
u32 var00012b84 = 0x40c00000;
u32 var00012b88 = 0x050fff00;
u32 var00012b8c = 0x40400000;
u32 var00012b90 = 0x40000000;
u32 var00012b94 = 0x00000000;
u32 var00012b98 = 0x40800000;
u32 var00012b9c = 0x04008073;
u32 var00012ba0 = 0x01000000;
u32 var00012ba4 = 0x00000123;
u32 var00012ba8 = 0x00000000;
u32 var00012bac = 0x3f800000;
u32 var00012bb0 = 0x00000000;
u32 var00012bb4 = 0x3da3d70a;
u32 var00012bb8 = 0x0000001e;
u32 var00012bbc = 0x000004b0;
u32 var00012bc0 = 0x3dcccccd;
u32 var00012bc4 = 0x80530000;

// 12bc8
struct inventory_ammo invammo_superdragon = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	invanim_superdragon_reload, // reload animation
	0, // style
};

// 12bdc
struct inventory_ammo invammo_superdragon_grenades = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_DEVASTATOR,
	CASING_NONE,
	6, // clip size
	invanim_superdragon_grenadereload, // reload animation
	0, // style
};

// 12bf0
struct inventory_item invitem_superdragon = {
	0x0380, // lo model
	0x04c1, // hi model
	invanim_superdragon_equiporshoot, // equip animation
	NULL, // unequip animation
	invanim_superdragon_pritosec, // pritosec animation
	invanim_superdragon_sectopri, // sectopri animation
	&invfunc_superdragon_rapidfire, // pri function
	&invfunc_superdragon_grenadelauncher, // sec function
	&invammo_superdragon, // pri ammo
	&invammo_superdragon_grenades, // sec ammo
	&inve_00011140, // eptr
	1.000000, // sway
	15.000000, // left/right
	-29.500000, // up/down
	-27.000000, // front/back
	1.000000, // unk38
	&invf_00012a08, // fptr
	invg_00012a28, // gptr
	0x4c12, // short name
	0x4c12, // name
	0x4c95, // manufacturer
	0x4ca7, // description
	0x00026650, // flags
};

// 12c40
struct inventory_typef invf_00012c40 = {
	0x01000000,
	0x0100002a,
	0x00000000,
	0x00000000,
	0x00000000,
};

// 12c54
// type g
s8 invg_00012c54[] = {42, 0, 90, 0, -1};


// 12c5c
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

// 12cc4
struct inventory_typee inve_00012cc4 = {
	0x41a00000,
	0x40400000,
	0x41000000,
	0x41700000,
	0x3f78db8c,
	0x3f7a0903,
	0x15000000,
	0x00000006,
};

// 12ce4
struct inventory_function invfunc_ar34_burstfire = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c57, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	NULL, // fire animation
	0x00000002, // flags
};

u32 var00012cf8 = (u32) &invmenupos_00011098;
u32 var00012cfc = 0x00000000;
u32 var00012d00 = 0x3fb33333;
u32 var00012d04 = 0x41000000;
u32 var00012d08 = 0x06120208;
u32 var00012d0c = 0x40a00000;
u32 var00012d10 = 0x40000000;
u32 var00012d14 = 0x00000000;
u32 var00012d18 = 0x40800000;
u32 var00012d1c = 0x05008059;
u32 var00012d20 = 0x01000000;
u32 var00012d24 = 0x443b8000;
u32 var00012d28 = 0x443b8000;
u32 var00012d2c = 0x00000000;
u32 var00012d30 = 0x00000000;
u32 var00012d34 = 0x00000000;

// 12d38
struct inventory_function invfunc_ar34_usescope = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c67, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	NULL, // fire animation
	0x00000002, // flags
};

u32 var00012d4c = (u32) &invmenupos_00011098;
u32 var00012d50 = 0x00000000;
u32 var00012d54 = 0x3fb33333;
u32 var00012d58 = 0x41000000;
u32 var00012d5c = 0x06120208;
u32 var00012d60 = 0x40a00000;
u32 var00012d64 = 0x40000000;
u32 var00012d68 = 0x00000000;
u32 var00012d6c = 0x40800000;
u32 var00012d70 = 0x05008059;
u32 var00012d74 = 0x01000000;
u32 var00012d78 = 0x443b8000;
u32 var00012d7c = 0x443b8000;
u32 var00012d80 = 0x00000000;
u32 var00012d84 = 0x00000000;
u32 var00012d88 = 0x00000000;

// 12d8c
struct inventory_ammo invammo_ar34 = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	invanim_ar34_equiporreload, // reload animation
	0, // style
};

// 12da0
struct inventory_item invitem_ar34 = {
	0x037e, // lo model
	0x04b7, // hi model
	invanim_ar34_equiporreload, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_ar34_burstfire, // pri function
	&invfunc_ar34_usescope, // sec function
	&invammo_ar34, // pri ammo
	NULL, // sec ammo
	&inve_00012cc4, // eptr
	1.000000, // sway
	11.500000, // left/right
	-25.700001, // up/down
	-30.500000, // front/back
	1.000000, // unk38
	&invf_00012c40, // fptr
	invg_00012c54, // gptr
	0x4c10, // short name
	0x4c10, // name
	0x4c00, // manufacturer
	0x4ca5, // description
	0x04626650, // flags
};

// 12df0
struct inventory_typef invf_00012df0 = {
	0x01000000,
	0x0100002a,
	0x00000000,
	0x00000000,
	0x00000000,
};

// 12e04
// type g
s8 invg_00012e04[] = {42, 0, 90, 0, -1};


// 12e0c
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

// 12e6c
u32 invanim_k7avenger_equip[] = {
	gunscript_playanimation(0x00e6, 0, 10000)
	gunscript_end
};

// 12e7c
u32 invanim_k7avenger_unequip[] = {
	gunscript_playanimation(0x00e7, 0, 10000)
	gunscript_end
};

u32 var00012e8c = 0x0a0000e8;
u32 var00012e90 = 0x00002710;
u32 var00012e94 = 0x00000000;
u32 var00012e98 = 0x00000000;

// 12e9c
struct inventory_typee inve_00012e9c = {
	0x41a00000,
	0x40400000,
	0x41000000,
	0x41700000,
	0x3f78db8c,
	0x3f7a0903,
	0x15000000,
	0x00000006,
};

// 12ebc
struct inventory_function invfunc_k7avenger_burstfire = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c57, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	NULL, // fire animation
	0x00000002, // flags
};

u32 var00012ed0 = (u32) &invmenupos_00011098;
u32 var00012ed4 = 0x00000000;
u32 var00012ed8 = 0x3fc00000;
u32 var00012edc = 0x40c00000;
u32 var00012ee0 = 0x06120208;
u32 var00012ee4 = 0x40a00000;
u32 var00012ee8 = 0x40000000;
u32 var00012eec = 0x00000000;
u32 var00012ef0 = 0x40800000;
u32 var00012ef4 = 0x0400805a;
u32 var00012ef8 = 0x01000000;
u32 var00012efc = 0x446d8000;
u32 var00012f00 = 0x446d8000;
u32 var00012f04 = 0x00000000;
u32 var00012f08 = 0x00000000;
u32 var00012f0c = 0x00000000;

// 12f10
struct inventory_function invfunc_k7avenger_threatdetector = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c77, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	NULL, // fire animation
	0x00082002, // flags
};

u32 var00012f24 = (u32) &invmenupos_00011098;
u32 var00012f28 = 0x00000000;
u32 var00012f2c = 0x3fc00000;
u32 var00012f30 = 0x40c00000;
u32 var00012f34 = 0x06120208;
u32 var00012f38 = 0x40a00000;
u32 var00012f3c = 0x40000000;
u32 var00012f40 = 0x00000000;
u32 var00012f44 = 0x40800000;
u32 var00012f48 = 0x0400805a;
u32 var00012f4c = 0x01000000;
u32 var00012f50 = 0x446d8000;
u32 var00012f54 = 0x446d8000;
u32 var00012f58 = 0x00000000;
u32 var00012f5c = 0x00000000;
u32 var00012f60 = 0x00000000;

// 12f64
struct inventory_ammo invammo_k7avenger = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	25, // clip size
	invanim_k7avenger_reload, // reload animation
	0, // style
};

// 12f78
struct inventory_item invitem_k7avenger = {
	0x0381, // lo model
	0x04b8, // hi model
	invanim_k7avenger_equip, // equip animation
	invanim_k7avenger_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_k7avenger_burstfire, // pri function
	&invfunc_k7avenger_threatdetector, // sec function
	&invammo_k7avenger, // pri ammo
	NULL, // sec ammo
	&inve_00012e9c, // eptr
	1.000000, // sway
	6.500000, // left/right
	-24.000000, // up/down
	-27.000000, // front/back
	1.000000, // unk38
	&invf_00012df0, // fptr
	invg_00012e04, // gptr
	0x4c13, // short name
	0x4c13, // name
	0x4c95, // manufacturer
	0x4ca8, // description
	0x00022650, // flags
};

// 12fc8
struct inventory_typef invf_00012fc8 = {
	0x01000000,
	0x0100002a,
	0x00000100,
	0x00000100,
	0x00290000,
};

u32 var00012fdc = 0x00000000;
u32 var00012fe0 = 0x00000000;
u32 var00012fe4 = 0x00000000;

// 12fe8
// type g
s8 invg_00012fe8[] = {90, 0, 41, 0, 42, 0, -1};

// 12ff0
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

// 13080
u32 invanim_laptopgun_shoot[] = {
	gunscript_playanimation(0x00e5, 0, 10000)
	gunscript_waittime(10, 5)
	gunscript_waitforzreleased(10)
	gunscript_end
};

// 130a0
u32 invanim_laptopgun_equip[] = {
	gunscript_playanimation(0x00e2, 0, 10000)
	gunscript_setsoundspeed(15, 720)
	gunscript_playsound(15, 0x04f7)
	gunscript_playsound(35, 0x04f7)
	gunscript_playsound(58, 0x04f8)
	gunscript_end
};

// 130d0
u32 invanim_laptopgun_unequip[] = {
	gunscript_playanimation(0x00e3, 0, 10000)
	gunscript_playsound(1, 0x04f7)
	gunscript_setsoundspeed(25, 720)
	gunscript_playsound(25, 0x04f7)
	gunscript_playsound(50, 0x04f8)
	gunscript_end
};

// 13100
struct inventory_function invfunc_laptopgun_burstfire = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c57, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011020, // menupos
	invanim_laptopgun_shoot, // fire animation
	0x00000002, // flags
};

u32 var00013114 = (u32) &invmenupos_00011098;
u32 var00013118 = 0x00000000;
u32 var0001311c = 0x3f933333;
u32 var00013120 = 0x40c00000;
u32 var00013124 = 0x06120208;
u32 var00013128 = 0x40a00000;
u32 var0001312c = 0x40000000;
u32 var00013130 = 0x00000000;
u32 var00013134 = 0x40800000;
u32 var00013138 = 0x04008044;
u32 var0001313c = 0x01000000;
u32 var00013140 = 0x447a0000;
u32 var00013144 = 0x447a0000;
u32 var00013148 = 0x00000000;
u32 var0001314c = 0x00000000;
u32 var00013150 = 0x00000000;

// 13154
struct inventory_function invfunc_laptopgun_deploy = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_THROW,
	0x4c75, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00842140, // flags
};

u32 var00013168 = 0x00000157;
u32 var0001316c = 0x00f00000;
u32 var00013170 = 0x0000003c;
u32 var00013174 = 0x00000000;

// 13178
struct inventory_ammo invammo_laptopgun = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_SMG,
	CASING_NONE,
	50, // clip size
	invanim_laptopgun_reload, // reload animation
	0, // style
};

// 1318c
struct inventory_item invitem_laptopgun = {
	0x0385, // lo model
	0x04c7, // hi model
	invanim_laptopgun_equip, // equip animation
	invanim_laptopgun_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_laptopgun_burstfire, // pri function
	&invfunc_laptopgun_deploy, // sec function
	&invammo_laptopgun, // pri ammo
	NULL, // sec ammo
	&inve_00011140, // eptr
	1.200000, // sway
	16.000000, // left/right
	-17.700001, // up/down
	-14.500000, // front/back
	1.000000, // unk38
	&invf_00012fc8, // fptr
	invg_00012fe8, // gptr
	0x4c18, // short name
	0x4c18, // name
	0x4c96, // manufacturer
	0x4cac, // description
	0x0402a650, // flags
};

// 131dc
struct inventory_typef invf_000131dc = {
	0x01000000,
	0x0100002b,
	0x00000000,
	0x00000000,
	0x00000000,
};

// 131f0
// type g
s8 invg_000131f0[] = {43, 0, 90, 0, -1};


// 131f8
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

// 13238
u32 invanim_shotgun_equiporsingleshot[] = {
	gunscript_playanimation(0x03ee, 0, 10000)
	gunscript_waittime(9, 2)
	gunscript_playsound(34, 0x04fb)
	gunscript_end
};

// 13258
u32 invanim_shotgun_doubleshot[] = {
	gunscript_playanimation(0x042c, 0, 10000)
	gunscript_waittime(9, 2)
	gunscript_playsound(54, 0x04fb)
	gunscript_end
};

// 13278
struct inventory_function invfunc_shotgun_single = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c59, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_shotgun_equiporsingleshot, // fire animation
	0x00000000, // flags
};

u32 var0001328c = (u32) &invmenupos_00011098;
u32 var00013290 = 0x00000000;
u32 var00013294 = 0x3f19999a;
u32 var00013298 = 0x41f00000;
u32 var0001329c = 0x141c0000;
u32 var000132a0 = 0x00000000;
u32 var000132a4 = 0x00000000;
u32 var000132a8 = 0x00000000;
u32 var000132ac = 0x40800000;
u32 var000132b0 = 0x00008055;
u32 var000132b4 = 0x01000000;

// 132b8
struct inventory_function invfunc_shotgun_double = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c69, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_shotgun_doubleshot, // fire animation
	0x00001000, // flags
};

u32 var000132cc = (u32) &invmenupos_00011098;
u32 var000132d0 = 0x00000000;
u32 var000132d4 = 0x3f19999a;
u32 var000132d8 = 0x41800000;
u32 var000132dc = 0x141c0000;
u32 var000132e0 = 0x00000000;
u32 var000132e4 = 0x00000000;
u32 var000132e8 = 0x00000000;
u32 var000132ec = 0x40800000;
u32 var000132f0 = 0x00008055;
u32 var000132f4 = 0x01000000;

// 132f8
struct inventory_ammo invammo_shotgun = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_SHOTGUN,
	CASING_SHOTGUN,
	9, // clip size
	invanim_shotgun_reload, // reload animation
	67108864, // style
};

// 1330c
struct inventory_item invitem_shotgun = {
	0x0386, // lo model
	0x04ca, // hi model
	invanim_shotgun_equiporsingleshot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_shotgun_single, // pri function
	&invfunc_shotgun_double, // sec function
	&invammo_shotgun, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	12.000000, // left/right
	-16.700001, // up/down
	-21.000000, // front/back
	1.000000, // unk38
	&invf_000131dc, // fptr
	invg_000131f0, // gptr
	0x4c19, // short name
	0x4c19, // name
	0x4c95, // manufacturer
	0x4cad, // description
	0x00026650, // flags
};

u32 var0001335c = 0x00000000;
u32 var00013360 = 0x3f800000;
u32 var00013364 = 0x3f800000;
u32 var00013368 = 0x3f800000;
u32 var0001336c = 0x3f800000;
u32 var00013370 = 0x3f800000;
u32 var00013374 = 0x3f800000;
u32 var00013378 = 0x00000000;
u32 var0001337c = 0x00000000;
u32 var00013380 = 0x00000000;
u32 var00013384 = 0x00000000;
u32 var00013388 = 0x00000000;
u32 var0001338c = 0x3f800000;
u32 var00013390 = 0x3f800000;
u32 var00013394 = 0x3f800000;
u32 var00013398 = 0x3f800000;
u32 var0001339c = 0x3f800000;
u32 var000133a0 = 0x3f800000;
u32 var000133a4 = 0x3f800000;
u32 var000133a8 = 0x00000000;
u32 var000133ac = 0x00000000;
u32 var000133b0 = 0x00000000;
u32 var000133b4 = 0x00000000;
u32 var000133b8 = 0x00000000;

// 133bc
// type g
s8 invg_000133bc[] = {90, 0, 91, 0, 92, 0, 43, 0, -1};


// 133c8
struct inventory_typef invf_000133c8 = {
	0x01000000,
	0x0100002b,
	0x00000000,
	0x00000000,
	0x00000000,
};

// 133dc
u32 invanim_reaper_shoot[] = {
	gunscript_playanimation(0x0400, 0, 10000)
	gunscript_waittime(12, 5)
	gunscript_end
};

// 133f4
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

// 1343c
u32 invanim_reaper_equip[] = {
	gunscript_playanimation(0x0427, 0, 10000)
	gunscript_end
};

// 1344c
u32 invanim_reaper_unequip[] = {
	gunscript_playanimation(0x0428, 0, 10000)
	gunscript_end
};

// 1345c
struct inventory_function invfunc_reaper_shoot = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c58, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001105c, // menupos
	invanim_reaper_shoot, // fire animation
	0x00000002, // flags
};

u32 var00013470 = (u32) &invmenupos_000110ac;
u32 var00013474 = 0x00000000;
u32 var00013478 = 0x3f99999a;
u32 var0001347c = 0x42600000;
u32 var00013480 = 0x0309201c;
u32 var00013484 = 0x00000000;
u32 var00013488 = 0x00000000;
u32 var0001348c = 0x00000000;
u32 var00013490 = 0x40800000;
u32 var00013494 = 0x0200803f;
u32 var00013498 = 0x01000000;
u32 var0001349c = 0x42700000;
u32 var000134a0 = 0x44e10000;
u32 var000134a4 = (u32) &var0001335c;
u32 var000134a8 = (u32) &var0001338c;
u32 var000134ac = 0x58580000;

// 134b0
struct inventory_function invfunc_reaper_grind = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_CLOSE,
	0x4c6a, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00002000, // flags
};

u32 var000134c4 = 0x3d4ccccd;
u32 var000134c8 = 0x42a00000;
u32 var000134cc = 0x00000069;
u32 var000134d0 = 0x00000069;
u32 var000134d4 = 0x00000069;
u32 var000134d8 = 0xbf000000;
u32 var000134dc = 0xc1a9999a;
u32 var000134e0 = 0xbf000000;
u32 var000134e4 = 0xc1a9999a;
u32 var000134e8 = 0xbf800000;
u32 var000134ec = 0xbf800000;
u32 var000134f0 = 0x40000000;
u32 var000134f4 = 0x40000000;
u32 var000134f8 = 0x00000000;

// 134fc
struct inventory_ammo invammo_reaper = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_REAPER,
	CASING_REAPER,
	200, // clip size
	invanim_reaper_reload, // reload animation
	0, // style
};

// 13510
struct inventory_item invitem_reaper = {
	0x0387, // lo model
	0x039d, // hi model
	invanim_reaper_equip, // equip animation
	invanim_reaper_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_reaper_shoot, // pri function
	&invfunc_reaper_grind, // sec function
	&invammo_reaper, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	4.000000, // left/right
	-21.200001, // up/down
	-30.500000, // front/back
	1.000000, // unk38
	&invf_000133c8, // fptr
	invg_000133bc, // gptr
	0x4c1a, // short name
	0x4c1a, // name
	0x4c98, // manufacturer
	0x4cae, // description
	0x00022650, // flags
};

// 13560
// type g
s8 invg_00013560[] = {40, 0, -1};

// 13564
struct inventory_typef invf_00013564 = {
	0x01000000,
	0x01000028,
	0x00000000,
	0x00000000,
	0x00000000,
};

// 13578
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

// 135e0
u32 invanim_rockerlauncher_equiporshoot[] = {
	gunscript_playanimation(0x03f0, 0, 10000)
	gunscript_end
};

// 135f0
struct inventory_typee inve_000135f0 = {
	0x00000000,
	0x40400000,
	0x41000000,
	0x41700000,
	0x3f78db8c,
	0x3f7a0903,
	0x30000000,
	0x00000002,
};

// 13610
struct inventory_function invfunc_rockerlauncher_shoot = {
	0x0000, // unk00
	0x02, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c5b, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_rockerlauncher_equiporshoot, // fire animation
	0x08000040, // flags
};

u32 var00013624 = 0x00000000;
u32 var00013628 = 0x00000000;
u32 var0001362c = 0x3f800000;
u32 var00013630 = 0x40c00000;
u32 var00013634 = 0x030c0f00;
u32 var00013638 = 0x40400000;
u32 var0001363c = 0x40000000;
u32 var00013640 = 0x00000000;
u32 var00013644 = 0x40800000;
u32 var00013648 = 0x04008053;
u32 var0001364c = 0x01000000;
u32 var00013650 = 0x0000011f;
u32 var00013654 = 0x00000000;
u32 var00013658 = 0x40066666;
u32 var0001365c = 0x0000003c;
u32 var00013660 = 0x00000000;
u32 var00013664 = 0x00000000;
u32 var00013668 = 0xffffffff;
u32 var0001366c = 0x3d4ccccd;
u32 var00013670 = 0x80530000;

// 13674
struct inventory_function invfunc_rocketlauncher_homing = {
	0x0000, // unk00
	0x02, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c5c, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_rockerlauncher_equiporshoot, // fire animation
	0x48000040, // flags
};

u32 var00013688 = 0x00000000;
u32 var0001368c = 0x00000000;
u32 var00013690 = 0x3f800000;
u32 var00013694 = 0x40c00000;
u32 var00013698 = 0x030c0f00;
u32 var0001369c = 0x40400000;
u32 var000136a0 = 0x40000000;
u32 var000136a4 = 0x00000000;
u32 var000136a8 = 0x40800000;
u32 var000136ac = 0x04008053;
u32 var000136b0 = 0x01000000;
u32 var000136b4 = 0x0000011f;
u32 var000136b8 = 0x00000000;
u32 var000136bc = 0x40066666;
u32 var000136c0 = 0x00000000;
u32 var000136c4 = 0x00000000;
u32 var000136c8 = 0x00000005;
u32 var000136cc = 0xffffffff;
u32 var000136d0 = 0x3d4ccccd;
u32 var000136d4 = 0x80530000;

// 136d8
struct inventory_ammo invammo_rocketlauncher = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_ROCKET,
	CASING_NONE,
	1, // clip size
	invanim_rocketlauncher_reload, // reload animation
	0, // style
};

// 136ec
struct inventory_item invitem_rocketlauncher = {
	0x0388, // lo model
	0x04c9, // hi model
	invanim_rockerlauncher_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_rockerlauncher_shoot, // pri function
	&invfunc_rocketlauncher_homing, // sec function
	&invammo_rocketlauncher, // pri ammo
	NULL, // sec ammo
	&inve_000135f0, // eptr
	1.000000, // sway
	24.500000, // left/right
	-25.200001, // up/down
	-30.000000, // front/back
	1.000000, // unk38
	&invf_00013564, // fptr
	invg_00013560, // gptr
	0x4c50, // short name
	0x4c1b, // name
	0x4c95, // manufacturer
	0x4caf, // description
	0x40026270, // flags
};

// 1373c
u32 invanim_slayer_equiporshoot[] = {
	gunscript_playanimation(0x042a, 0, 10000)
	gunscript_end
};

// 1374c
u32 invanim_slayer_reload[] = {
	gunscript_playanimation(0x0429, 0, 10000)
	gunscript_setsoundspeed(52, 800)
	gunscript_playsound(52, 0x0053)
	gunscript_playsound(79, 0x808c)
	gunscript_setsoundspeed(126, 900)
	gunscript_playsound(126, 0x04fb)
	gunscript_end
};

// 13784
struct inventory_function invfunc_slayer_shoot = {
	0x0000, // unk00
	0x02, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c5b, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_slayer_equiporshoot, // fire animation
	0x08000040, // flags
};

u32 var00013798 = 0x00000000;
u32 var0001379c = 0x00000000;
u32 var000137a0 = 0x3f800000;
u32 var000137a4 = 0x40c00000;
u32 var000137a8 = 0x030c0f00;
u32 var000137ac = 0x40400000;
u32 var000137b0 = 0x40000000;
u32 var000137b4 = 0x00000000;
u32 var000137b8 = 0x40800000;
u32 var000137bc = 0x04008067;
u32 var000137c0 = 0x01000000;
u32 var000137c4 = 0x00000120;
u32 var000137c8 = 0x00000000;
u32 var000137cc = 0x40833333;
u32 var000137d0 = 0x0000000a;
u32 var000137d4 = 0x00000000;
u32 var000137d8 = 0x00000000;
u32 var000137dc = 0xffffffff;
u32 var000137e0 = 0x3d4ccccd;
u32 var000137e4 = 0x80530000;

// 137e8
struct inventory_function invfunc_slayer_flybywire = {
	0x0000, // unk00
	0x02, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c5d, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	NULL, // fire animation
	0x28000840, // flags
};

u32 var000137fc = 0x00000000;
u32 var00013800 = 0x00000000;
u32 var00013804 = 0x3f800000;
u32 var00013808 = 0x40c00000;
u32 var0001380c = 0x030c0f00;
u32 var00013810 = 0x40400000;
u32 var00013814 = 0x40000000;
u32 var00013818 = 0x00000000;
u32 var0001381c = 0x40800000;
u32 var00013820 = 0x04008067;
u32 var00013824 = 0x01000000;
u32 var00013828 = 0x00000120;
u32 var0001382c = 0x00000000;
u32 var00013830 = 0x40833333;
u32 var00013834 = 0x0000000a;
u32 var00013838 = 0x00000000;
u32 var0001383c = 0x00000000;
u32 var00013840 = 0xffffffff;
u32 var00013844 = 0x3d4ccccd;
u32 var00013848 = 0x80680000;

// 1384c
struct inventory_ammo invammo_slayer = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_ROCKET,
	CASING_NONE,
	1, // clip size
	invanim_slayer_reload, // reload animation
	0, // style
};

// 13860
struct inventory_item invitem_slayer = {
	0x038a, // lo model
	0x04cc, // hi model
	invanim_slayer_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_slayer_shoot, // pri function
	&invfunc_slayer_flybywire, // sec function
	&invammo_slayer, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	22.500000, // left/right
	-32.000000, // up/down
	-40.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c1d, // short name
	0x4c1d, // name
	0x4c98, // manufacturer
	0x4cb1, // description
	0x02026270, // flags
};

u32 var000138b0 = 0x01000000;
u32 var000138b4 = 0x01000029;
u32 var000138b8 = 0x00000000;
u32 var000138bc = 0x00000000;
u32 var000138c0 = 0x00000000;

// 138c4
u32 invanim_devastator_equiporshoot[] = {
	gunscript_playanimation(0x03f7, 0, 10000)
	gunscript_end
};

// 138d4
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

// 13934
struct inventory_function invfunc_devastator_shoot = {
	0x0000, // unk00
	0x02, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c62, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_devastator_equiporshoot, // fire animation
	0x30000040, // flags
};

u32 var00013948 = 0x00000000;
u32 var0001394c = 0x00000000;
u32 var00013950 = 0x3f800000;
u32 var00013954 = 0x40c00000;
u32 var00013958 = 0x053aff00;
u32 var0001395c = 0x40a00000;
u32 var00013960 = 0x41000000;
u32 var00013964 = 0x00000000;
u32 var00013968 = 0x40800000;
u32 var0001396c = 0x04008073;
u32 var00013970 = 0x01000000;
u32 var00013974 = 0x00000122;
u32 var00013978 = 0x00000000;
u32 var0001397c = 0x3f800000;
u32 var00013980 = 0x00000000;
u32 var00013984 = 0x3da3d70a;
u32 var00013988 = 0x00000028;
u32 var0001398c = 0x000004b0;
u32 var00013990 = 0x3e99999a;
u32 var00013994 = 0x80530000;

// 13998
struct inventory_function invfunc_devastator_wallhugger = {
	0x0000, // unk00
	0x02, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c63, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_devastator_equiporshoot, // fire animation
	0x30000140, // flags
};

u32 var000139ac = 0x00000000;
u32 var000139b0 = 0x00000000;
u32 var000139b4 = 0x3f800000;
u32 var000139b8 = 0x40c00000;
u32 var000139bc = 0x053aff00;
u32 var000139c0 = 0x40a00000;
u32 var000139c4 = 0x41000000;
u32 var000139c8 = 0x00000000;
u32 var000139cc = 0x40800000;
u32 var000139d0 = 0x04008073;
u32 var000139d4 = 0x01000000;
u32 var000139d8 = 0x00000122;
u32 var000139dc = 0x00000000;
u32 var000139e0 = 0x3f800000;
u32 var000139e4 = 0x00000000;
u32 var000139e8 = 0x3da3d70a;
u32 var000139ec = 0x00000028;
u32 var000139f0 = 0x00000168;
u32 var000139f4 = 0x3e99999a;
u32 var000139f8 = 0x80530000;

// 139fc
struct inventory_ammo invammo_devastator = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_DEVASTATOR,
	CASING_NONE,
	8, // clip size
	invanim_devastator_reload, // reload animation
	134217728, // style
};

// 13a10
// type g
s8 invg_00013a10[] = {41, 0, -1};

// 13a14
struct inventory_item invitem_devastator = {
	0x0389, // lo model
	0x04bf, // hi model
	invanim_devastator_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_devastator_shoot, // pri function
	&invfunc_devastator_wallhugger, // sec function
	&invammo_devastator, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	19.500000, // left/right
	-25.500000, // up/down
	-29.000000, // front/back
	1.000000, // unk38
	NULL, // fptr
	invg_00013a10, // gptr
	0x4c1c, // short name
	0x4c1c, // name
	0x4c95, // manufacturer
	0x4cb0, // description
	0x00026270, // flags
};

// 13a64
struct inventory_function invfunc_mine_threatdetector = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_NONE,
	0x4c77, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00080000, // flags
};

// 13a78
u32 inanim_mine_equiporreload[] = {
	gunscript_playanimation(0x0430, 0, 10000)
	gunscript_end
};

// 13a88
u32 invanim_mine_unequip[] = {
	gunscript_playanimation(0x0431, 0, 10000)
	gunscript_end
};

// 13a98
u32 invanim_mine_throw[] = {
	gunscript_playanimation(0x0435, 0, 10000)
	gunscript_waitforzreleased(10)
	gunscript_waittime(13, 2)
	gunscript_end
};

// 13ab8
struct inventory_function invfunc_timedmine_throw = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_THROW,
	0x4c78, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_mine_throw, // fire animation
	0x00802040, // flags
};

u32 var00013acc = 0x00000113;
u32 var00013ad0 = 0x00f00000;
u32 var00013ad4 = 0x00000000;
u32 var00013ad8 = 0x00000000;

// 13adc
struct inventory_ammo invammo_timedmine = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_TIMED_MINE,
	CASING_NONE,
	1, // clip size
	inanim_mine_equiporreload, // reload animation
	33554432, // style
};

// 13af0
struct inventory_item invitem_timedmine = {
	0x0391, // lo model
	0x0391, // hi model
	inanim_mine_equiporreload, // equip animation
	invanim_mine_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_timedmine_throw, // pri function
	&invfunc_mine_threatdetector, // sec function
	&invammo_timedmine, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	8.000000, // left/right
	-15.000000, // up/down
	-23.000000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c26, // short name
	0x4c26, // name
	0x4c00, // manufacturer
	0x4cb9, // description
	0x00022259, // flags
};

// 13b40
struct inventory_typef invf_00013b40 = {
	0x05000000,
	0x03000035,
	0x00000500,
	0x00000300,
	0x00290000,
};

u32 var00013b54 = 0x06000000;
u32 var00013b58 = 0x03000036;
u32 var00013b5c = 0x00000600;
u32 var00013b60 = 0x00000300;
u32 var00013b64 = 0x00280000;
u32 var00013b68 = 0x00000000;
u32 var00013b6c = 0x00000000;
u32 var00013b70 = 0x00000000;

// 13b74
u32 invanim_remotemine_equiporreload[] = {
	gunscript_playanimation(0x0432, 0, 10000)
	gunscript_end
};

// 13b84
u32 invanim_remotemine_unequip[] = {
	gunscript_playanimation(0x0433, 0, 10000)
	gunscript_end
};

// 13b94
u32 invanim_remotemine_throw[] = {
	gunscript_playanimation(0x0436, 0, 10000)
	gunscript_waitforzreleased(10)
	gunscript_waittime(11, 2)
	gunscript_end
};

// 13bb4
struct inventory_function invfunc_remotemine_throw = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_THROW,
	0x4c7a, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_remotemine_throw, // fire animation
	0x00802040, // flags
};

u32 var00013bc8 = 0x00000115;
u32 var00013bcc = 0x00f00000;
u32 var00013bd0 = 0x00000000;
u32 var00013bd4 = 0x00000000;

// 13bd8
struct inventory_function invfunc_remotemine_detonate = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SPECIAL,
	0x4c7b, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00102000, // flags
};

u32 var00013bec = 0x00000005;
u32 var00013bf0 = 0x0000001e;
u32 var00013bf4 = 0x00000000;

// 13bf8
struct inventory_ammo invammo_remotemine = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_REMOTE_MINE,
	CASING_NONE,
	1, // clip size
	invanim_remotemine_equiporreload, // reload animation
	33554432, // style
};

// 13c0c
// type g
s8 invg_00013c0c[] = {41, 0, -1};

// 13c10
struct inventory_item invitem_remotemine = {
	0x0393, // lo model
	0x0393, // hi model
	invanim_remotemine_equiporreload, // equip animation
	invanim_remotemine_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_remotemine_throw, // pri function
	&invfunc_remotemine_detonate, // sec function
	&invammo_remotemine, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	4.000000, // left/right
	-15.000000, // up/down
	-23.000000, // front/back
	1.000000, // unk38
	&invf_00013b40, // fptr
	invg_00013c0c, // gptr
	0x4c28, // short name
	0x4c28, // name
	0x4c00, // manufacturer
	0x4cbb, // description
	0x00022259, // flags
};

// 13c60
struct inventory_function invfunc_proxymine_throw = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_THROW,
	0x4c79, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_mine_throw, // fire animation
	0x00802040, // flags
};

u32 var00013c74 = 0x00000114;
u32 var00013c78 = 0x00f00000;
u32 var00013c7c = 0x00000000;
u32 var00013c80 = 0x00000000;

// 13c84
struct inventory_ammo invammo_proximitymine = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_PROXY_MINE,
	CASING_NONE,
	1, // clip size
	inanim_mine_equiporreload, // reload animation
	33554432, // style
};

// 13c98
struct inventory_item invitem_proximitymine = {
	0x0392, // lo model
	0x0392, // hi model
	inanim_mine_equiporreload, // equip animation
	invanim_mine_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_proxymine_throw, // pri function
	&invfunc_mine_threatdetector, // sec function
	&invammo_proximitymine, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	8.000000, // left/right
	-15.000000, // up/down
	-23.000000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c51, // short name
	0x4c27, // name
	0x4c00, // manufacturer
	0x4cba, // description
	0x00022259, // flags
};

// 13ce8
u32 invanim_ecmmine_equiporreload[] = {
	gunscript_playanimation(0x0437, 0, 10000)
	gunscript_end
};

// 13cf8
u32 invanim_ecmmine_unequip[] = {
	gunscript_playanimation(0x0438, 0, 10000)
	gunscript_end
};

// 13d08
u32 invanim_ecmmine_throw[] = {
	gunscript_playanimation(0x0438, 0, 10000)
	gunscript_waittime(23, 2)
	gunscript_end
};

// 13d20
struct inventory_function invfunc_ecmmine_throw = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_THROW,
	0x4c8c, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_ecmmine_throw, // fire animation
	0x00802040, // flags
};

u32 var00013d34 = 0x00000116;
u32 var00013d38 = 0x00f00000;
u32 var00013d3c = 0x0000003c;
u32 var00013d40 = 0x00000000;

// 13d44
struct inventory_ammo invammo_ecmmine = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_ECM_MINE,
	CASING_NONE,
	1, // clip size
	invanim_ecmmine_equiporreload, // reload animation
	33554432, // style
};

// 13d58
struct inventory_item invitem_ecmmine = {
	0x074d, // lo model
	0x074d, // hi model
	invanim_ecmmine_equiporreload, // equip animation
	invanim_ecmmine_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_ecmmine_throw, // pri function
	NULL, // sec function
	&invammo_ecmmine, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	14.000000, // left/right
	-25.000000, // up/down
	-31.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c29, // short name
	0x4c29, // name
	0x4c00, // manufacturer
	0x4cbc, // description
	0x08622059, // flags
};

u32 var00013da8 = 0x0387039d;
u32 var00013dac = 0x00000000;
u32 var00013db0 = 0x00000000;
u32 var00013db4 = 0x00000000;
u32 var00013db8 = 0x00000000;
u32 var00013dbc = (u32) &invfunc_remotemine_detonate;
u32 var00013dc0 = 0x00000000;
u32 var00013dc4 = 0x00000000;
u32 var00013dc8 = 0x00000000;
u32 var00013dcc = (u32) &inve_000110c0;
u32 var00013dd0 = 0x3f800000;
u32 var00013dd4 = 0x00000000;
u32 var00013dd8 = 0xc21e0000;
u32 var00013ddc = 0xc25e0000;
u32 var00013de0 = 0x3f800000;
u32 var00013de4 = 0x00000000;
u32 var00013de8 = 0x00000000;
u32 var00013dec = 0x4c264c26;
u32 var00013df0 = 0x4c004c00;
u32 var00013df4 = 0x08000048;

// 13df8
struct inventory_typef invf_00013df8 = {
	0x01000000,
	0x01000035,
	0x00000000,
	0x00000000,
	0x00000000,
};

// 13e0c
u32 invanim_grenade_throw[] = {
	gunscript_playanimation(0x0426, 0, 10000)
	gunscript_popoutsackofpills(0x0006)
	gunscript_playsound(6, 0x05c1)
	gunscript_waitforzreleased(43)
	gunscript_waittime(49, 2)
	gunscript_end
};

// 13e3c
u32 invanim_grenade_equiporreload[] = {
	gunscript_playanimation(0x042b, 0, 10000)
	gunscript_end
};

// 13e4c
struct inventory_function invfunc_grenade_throw = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_THROW,
	0x4c7c, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_grenade_throw, // fire animation
	0x00002040, // flags
};

u32 var00013e60 = 0x00000112;
u32 var00013e64 = 0x00f00000;
u32 var00013e68 = 0x0000003c;
u32 var00013e6c = 0x00000000;

// 13e70
struct inventory_function invfunc_grenade_pinball = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_THROW,
	0x4c7d, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_grenade_throw, // fire animation
	0x00002040, // flags
};

u32 var00013e84 = 0x00000112;
u32 var00013e88 = 0x005a0000;
u32 var00013e8c = 0x0000003c;
u32 var00013e90 = 0x00000000;

// 13e94
struct inventory_ammo invammo_grenade = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_GRENADE,
	CASING_NONE,
	1, // clip size
	invanim_grenade_equiporreload, // reload animation
	167772160, // style
};

// 13ea8
struct inventory_item invitem_grenade = {
	0x0390, // lo model
	0x04fe, // hi model
	invanim_grenade_equiporreload, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_grenade_throw, // pri function
	&invfunc_grenade_pinball, // sec function
	&invammo_grenade, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	17.000000, // left/right
	-19.700001, // up/down
	-21.000000, // front/back
	1.000000, // unk38
	&invf_00013df8, // fptr
	NULL, // gptr
	0x4c24, // short name
	0x4c24, // name
	0x4c00, // manufacturer
	0x4cb7, // description
	0x0002a67d, // flags
};

// 13ef8
struct inventory_function invfunc_nbomb_throw = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_THROW,
	0x4c86, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_grenade_throw, // fire animation
	0x00002640, // flags
};

u32 var00013f0c = 0x00000110;
u32 var00013f10 = 0x00f00000;
u32 var00013f14 = 0x0000003c;
u32 var00013f18 = 0x00000000;

// 13f1c
struct inventory_function invfunc_nbomb_proxy = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_THROW,
	0x4c7f, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_grenade_throw, // fire animation
	0x00002640, // flags
};

u32 var00013f30 = 0x00000110;
u32 var00013f34 = 0x00f00000;
u32 var00013f38 = 0x0000003c;
u32 var00013f3c = 0x00000000;

// 13f40
struct inventory_ammo invammo_nbomb = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_NBOMB,
	CASING_NONE,
	1, // clip size
	invanim_grenade_equiporreload, // reload animation
	167772160, // style
};

// 13f54
struct inventory_item invitem_nbomb = {
	0x04fc, // lo model
	0x04fd, // hi model
	invanim_grenade_equiporreload, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_nbomb_throw, // pri function
	&invfunc_nbomb_proxy, // sec function
	&invammo_nbomb, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	17.000000, // left/right
	-19.700001, // up/down
	-21.000000, // front/back
	1.000000, // unk38
	&invf_00013df8, // fptr
	NULL, // gptr
	0x4c25, // short name
	0x4c25, // name
	0x4c00, // manufacturer
	0x4cb8, // description
	0x0062a67d, // flags
};

// 13fa4
struct inventory_typef invf_00013fa4 = {
	0x01000000,
	0x01000028,
	0x00000000,
	0x00000000,
	0x00000000,
};

// 13fb8
u32 invanim_farsight_reload[] = {
	gunscript_playanimation(0x03eb, 0, 10000)
	gunscript_showpart(1, 40)
	gunscript_playsound(72, 0x0433)
	gunscript_waittime(76, 1)
	gunscript_hidepart(82, 40)
	gunscript_end
};

// 13fe8
u32 invanim_farsight_equiporshoot[] = {
	gunscript_playanimation(0x03ec, 0, 10000)
	gunscript_end
};

// 13ff8
struct inventory_typee inve_00013ff8 = {
	0x00000000,
	0x40400000,
	0x41000000,
	0x41700000,
	0x3f78db8c,
	0x3f7a0903,
	0x16000000,
	0x00000005,
};

// 14018
struct inventory_function invfunc_farsight_shoot = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c5a, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_farsight_equiporshoot, // fire animation
	0x00000000, // flags
};

u32 var0001402c = (u32) &invmenupos_00011098;
u32 var00014030 = 0x00000000;
u32 var00014034 = 0x42c80000;
u32 var00014038 = 0x00000000;
u32 var0001403c = 0x46280000;
u32 var00014040 = 0x00000000;
u32 var00014044 = 0x00000000;
u32 var00014048 = 0x00000000;
u32 var0001404c = 0x00000000;
u32 var00014050 = 0x0400813e;
u32 var00014054 = 0x05000000;

// 14058
struct inventory_function invfunc_farsight_targetlocator = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c6f, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011034, // menupos
	invanim_farsight_equiporshoot, // fire animation
	0x00000000, // flags
};

u32 var0001406c = (u32) &invmenupos_00011098;
u32 var00014070 = 0x00000000;
u32 var00014074 = 0x42c80000;
u32 var00014078 = 0x00000000;
u32 var0001407c = 0x46280000;
u32 var00014080 = 0x00000000;
u32 var00014084 = 0x00000000;
u32 var00014088 = 0x00000000;
u32 var0001408c = 0x00000000;
u32 var00014090 = 0x0400813e;
u32 var00014094 = 0x05000000;

// 14098
struct inventory_ammo invammo_farsight = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_FARSIGHT,
	CASING_NONE,
	8, // clip size
	invanim_farsight_reload, // reload animation
	0, // style
};

// 140ac
// type g
s8 invg_000140ac[] = {40, 0, -1};

// 140b0
struct inventory_item invitem_farsight = {
	0x038b, // lo model
	0x04ce, // hi model
	invanim_farsight_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_farsight_shoot, // pri function
	&invfunc_farsight_targetlocator, // sec function
	&invammo_farsight, // pri ammo
	NULL, // sec ammo
	&inve_00013ff8, // eptr
	6.000000, // sway
	21.500000, // left/right
	-25.200001, // up/down
	-32.500000, // front/back
	1.000000, // unk38
	&invf_00013fa4, // fptr
	invg_000140ac, // gptr
	0x4c4f, // short name
	0x4c1f, // name
	0x4c00, // manufacturer
	0x4cb2, // description
	0x00026650, // flags
};

// 14100
struct inventory_typef invf_00014100 = {
	0x01000000,
	0x01000035,
	0x00000100,
	0x00000100,
	0x00290000,
};

u32 var00014114 = 0x00000000;
u32 var00014118 = 0x00000000;
u32 var0001411c = 0x00000000;

// 14120
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

// 14180
u32 invanim_crossbow_shoot[] = {
	gunscript_playanimation(0x00c2, 0, 10000)
	gunscript_hidepart(20, 40)
	gunscript_playsound(37, 0x04f8)
	gunscript_end
};

// 141a0
u32 invanim_crossbow_unequip[] = {
	gunscript_playanimation(0x00d3, 0, 10000)
	gunscript_hidepart(1, 40)
	gunscript_playsound(37, 0x04f8)
	gunscript_end
};

// 141c0
u32 invanim_crosbow_equip[] = {
	gunscript_playanimation(0x00c1, 0, 10000)
	gunscript_playsound(32, 0x04fc)
	gunscript_playsound(75, 0x04f8)
	gunscript_end
};

// 141e0
struct inventory_function invfunc_crossbow_lethal = {
	0x0000, // unk00
	0x02, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c70, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_crossbow_shoot, // fire animation
	0x00802000, // flags
};

u32 var000141f4 = 0x00000000;
u32 var000141f8 = 0x00000000;
u32 var000141fc = 0x42c80000;
u32 var00014200 = 0x40c00000;
u32 var00014204 = 0x030c0f00;
u32 var00014208 = 0x40400000;
u32 var0001420c = 0x40000000;
u32 var00014210 = 0x00000000;
u32 var00014214 = 0x40800000;
u32 var00014218 = 0x04008056;
u32 var0001421c = 0x01000000;
u32 var00014220 = 0x00000121;
u32 var00014224 = 0x00000000;
u32 var00014228 = 0x40066666;
u32 var0001422c = 0x00000000;
u32 var00014230 = 0x00000000;
u32 var00014234 = 0x0000003c;
u32 var00014238 = 0xffffffff;
u32 var0001423c = 0x3d4ccccd;
u32 var00014240 = 0xffff0000;

// 14244
struct inventory_function invfunc_crossbow_shoot = {
	0x0000, // unk00
	0x02, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c6b, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_crossbow_shoot, // fire animation
	0x00802200, // flags
};

u32 var00014258 = 0x00000000;
u32 var0001425c = 0x00000000;
u32 var00014260 = 0x3f800000;
u32 var00014264 = 0x40c00000;
u32 var00014268 = 0x030c0f00;
u32 var0001426c = 0x40400000;
u32 var00014270 = 0x40000000;
u32 var00014274 = 0x00000000;
u32 var00014278 = 0x40800000;
u32 var0001427c = 0x04008056;
u32 var00014280 = 0x01000000;
u32 var00014284 = 0x00000121;
u32 var00014288 = 0x00000000;
u32 var0001428c = 0x40066666;
u32 var00014290 = 0x00000000;
u32 var00014294 = 0x00000000;
u32 var00014298 = 0x0000003c;
u32 var0001429c = 0xffffffff;
u32 var000142a0 = 0x3d4ccccd;
u32 var000142a4 = 0xffff0000;

// 142a8
struct inventory_ammo invammo_crossbow = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_CROSSBOW,
	CASING_NONE,
	5, // clip size
	invanim_crossbow_reload, // reload animation
	67108864, // style
};

// 142bc
// type g
s8 invg_000142bc[] = {40, 0, 41, 0, 42, 0, -1};

// 142c4
struct inventory_item invitem_crossbow = {
	0x038d, // lo model
	0x04ba, // hi model
	invanim_crosbow_equip, // equip animation
	invanim_crossbow_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_crossbow_shoot, // pri function
	&invfunc_crossbow_lethal, // sec function
	&invammo_crossbow, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	11.000000, // left/right
	-15.000000, // up/down
	-21.000000, // front/back
	1.000000, // unk38
	&invf_00014100, // fptr
	invg_000142bc, // gptr
	0x4c21, // short name
	0x4c21, // name
	0x4c00, // manufacturer
	0x4cb4, // description
	0x00022658, // flags
};

// 14314
struct inventory_typef invf_00014314 = {
	0x01000000,
	0x01000028,
	0x00000100,
	0x00000100,
	0x00350000,
};

u32 var00014328 = 0x00000000;
u32 var0001432c = 0x00000000;
u32 var00014330 = 0x00000000;

// 14334
u32 invanim_tranquilizer_lethalinject[] = {
	gunscript_playanimation(0x0411, 0, 10000)
	gunscript_waittime(18, 2)
	gunscript_end
};

// 1434c
u32 invanim_tranquilizer_equiporshoot[] = {
	gunscript_playanimation(0x042d, 0, 10000)
	gunscript_waittime(7, 5)
	gunscript_end
};

// 14364
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

// 143f4
struct inventory_function invfunc_tranquilizer_shoot = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c6b, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_tranquilizer_equiporshoot, // fire animation
	0x00000200, // flags
};

u32 var00014408 = (u32) &invmenupos_00011098;
u32 var0001440c = 0x10000000;
u32 var00014410 = 0x3e800000;
u32 var00014414 = 0x40400000;
u32 var00014418 = 0x03050500;
u32 var0001441c = 0x3f800000;
u32 var00014420 = 0x00000000;
u32 var00014424 = 0x426fffff;
u32 var00014428 = 0x00000000;
u32 var0001442c = 0x00008057;
u32 var00014430 = 0x01000000;

// 14434
struct inventory_function invfunc_tranquilizer_lethal = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_CLOSE,
	0x4c6c, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_tranquilizer_lethalinject, // fire animation
	0x00002000, // flags
};

u32 var00014448 = 0x42c80000;
u32 var0001444c = 0x42700000;
u32 var00014450 = 0x00000069;
u32 var00014454 = 0x00000069;
u32 var00014458 = 0x00000069;
u32 var0001445c = 0x41200000;
u32 var00014460 = 0xc181999a;
u32 var00014464 = 0x41200000;
u32 var00014468 = 0xc181999a;
u32 var0001446c = 0xbf800000;
u32 var00014470 = 0xbf800000;
u32 var00014474 = 0x40000000;
u32 var00014478 = 0x40000000;
u32 var0001447c = 0x00000000;

// 14480
struct inventory_ammo invammo_tranquilizer = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_SEDATIVE,
	CASING_NONE,
	8, // clip size
	invanim_tranquilizer_reload, // reload animation
	0, // style
};

// 14494
// type g
s8 invg_00014494[] = {40, 0, 41, 0, 42, 0, -1};

// 1449c
struct inventory_item invitem_tranquilizer = {
	0x038e, // lo model
	0x04bc, // hi model
	invanim_tranquilizer_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_tranquilizer_shoot, // pri function
	&invfunc_tranquilizer_lethal, // sec function
	&invammo_tranquilizer, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	10.000000, // left/right
	-15.200000, // up/down
	-24.000000, // front/back
	1.000000, // unk38
	&invf_00014314, // fptr
	invg_00014494, // gptr
	0x4c22, // short name
	0x4c22, // name
	0x4c00, // manufacturer
	0x4cb5, // description
	0x0002e65c, // flags
};

// 144ec
struct inventory_ammo invammo_psychosisgun = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_PSYCHOSIS,
	CASING_NONE,
	8, // clip size
	invanim_tranquilizer_reload, // reload animation
	0, // style
};

// 14500
struct inventory_function invfunc_psychosisgun_shoot = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c83, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fe4, // menupos
	invanim_tranquilizer_equiporshoot, // fire animation
	0x00200200, // flags
};

u32 var00014514 = (u32) &invmenupos_00011098;
u32 var00014518 = 0x10000000;
u32 var0001451c = 0x3f000000;
u32 var00014520 = 0x40400000;
u32 var00014524 = 0x03050500;
u32 var00014528 = 0x3f800000;
u32 var0001452c = 0x00000000;
u32 var00014530 = 0x426fffff;
u32 var00014534 = 0x00000000;
u32 var00014538 = 0x00008057;
u32 var0001453c = 0x01000000;

// 14540
struct inventory_item invitem_psychosisgun = {
	0x038e, // lo model
	0x04bc, // hi model
	invanim_tranquilizer_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_psychosisgun_shoot, // pri function
	NULL, // sec function
	&invammo_psychosisgun, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	10.000000, // left/right
	-16.200001, // up/down
	-28.500000, // front/back
	1.000000, // unk38
	&invf_00014314, // fptr
	invg_00014494, // gptr
	0x4c52, // short name
	0x4c31, // name
	0x4c00, // manufacturer
	0x4cd2, // description
	0x0002e65c, // flags
};

// 14590
struct inventory_typef invf_00014590 = {
	0x01000000,
	0x01000029,
	0x00000000,
	0x00000000,
	0x00000000,
};

// 145a4
u32 invanim_sniperrifle_equip[] = {
	gunscript_playanimation(0x040c, 0, 10000)
	gunscript_end
};

// 145b4
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

// 1460c
struct inventory_typee inve_0001460c = {
	0x00000000,
	0x40400000,
	0x41000000,
	0x41700000,
	0x3f78db8c,
	0x3f7a0903,
	0x15000000,
	0x00000005,
};

// 1462c
struct inventory_function invfunc_sniperrifle_singleshot = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c55, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010ff8, // menupos
	NULL, // fire animation
	0x00002000, // flags
};

u32 var00014640 = (u32) &invmenupos_00011098;
u32 var00014644 = 0x10000000;
u32 var00014648 = 0x3f99999a;
u32 var0001464c = 0x00000000;
u32 var00014650 = 0x060a0000;
u32 var00014654 = 0x41000000;
u32 var00014658 = 0x00000000;
u32 var0001465c = 0x00000000;
u32 var00014660 = 0x00000000;
u32 var00014664 = 0x04008058;
u32 var00014668 = 0x01000000;

// 1466c
struct inventory_function invfunc_sniperrifle_crouch = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SPECIAL,
	0x4c82, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00102000, // flags
};

u32 var00014680 = 0x00000008;
u32 var00014684 = 0x0000001e;
u32 var00014688 = 0x00000000;

// 1468c
struct inventory_ammo invammo_sniperrifle = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	8, // clip size
	invanim_sniperrifle_reload, // reload animation
	0, // style
};

// 146a0
// type g
s8 invg_000146a0[] = {41, 0, -1};

// 146a4
struct inventory_item invitem_sniperrifle = {
	0x038c, // lo model
	0x04cd, // hi model
	invanim_sniperrifle_equip, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_sniperrifle_singleshot, // pri function
	&invfunc_sniperrifle_crouch, // sec function
	&invammo_sniperrifle, // pri ammo
	NULL, // sec ammo
	&inve_0001460c, // eptr
	6.000000, // sway
	21.000000, // left/right
	-27.200001, // up/down
	-31.500000, // front/back
	1.000000, // unk38
	&invf_00014590, // fptr
	invg_000146a0, // gptr
	0x4c20, // short name
	0x4c20, // name
	0x4c00, // manufacturer
	0x4cb3, // description
	0x00026650, // flags
};

// 146f4
u32 invanim_laser_equip[] = {
	gunscript_playanimation(0x042e, 0, 10000)
	gunscript_end
};

// 14704
u32 invanim_laser_unequip[] = {
	gunscript_playanimation(0x042f, 0, 10000)
	gunscript_end
};

// 14714
struct inventory_function invfunc_laser_pulse = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c84, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
};

u32 var00014728 = (u32) &invmenupos_00011098;
u32 var0001472c = 0x00000000;
u32 var00014730 = 0x3f800000;
u32 var00014734 = 0x00000000;
u32 var00014738 = 0x061218ff;
u32 var0001473c = 0x00000000;
u32 var00014740 = 0x00000000;
u32 var00014744 = 0x00000000;
u32 var00014748 = 0x00000000;
u32 var0001474c = 0x03008043;
u32 var00014750 = 0x01000000;

// 14754
struct inventory_function invfunc_laser_stream = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c85, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00000000, // flags
};

u32 var00014768 = (u32) &invmenupos_00011084;
u32 var0001476c = 0x00000000;
u32 var00014770 = 0x3dcccccd;
u32 var00014774 = 0x00000000;
u32 var00014778 = 0x06120006;
u32 var0001477c = 0x40800000;
u32 var00014780 = 0x40400000;
u32 var00014784 = 0x00000000;
u32 var00014788 = 0x00000000;
u32 var0001478c = 0x03000000;
u32 var00014790 = 0x01000000;
u32 var00014794 = 0x45610000;
u32 var00014798 = 0x45610000;
u32 var0001479c = 0x00000000;
u32 var000147a0 = 0x00000000;
u32 var000147a4 = 0x00000000;

// 147a8
struct inventory_item invitem_laser = {
	0x04df, // lo model
	0x04c3, // hi model
	invanim_laser_equip, // equip animation
	invanim_laser_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_laser_pulse, // pri function
	&invfunc_laser_stream, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	3.000000, // sway
	-12.000000, // left/right
	-12.700000, // up/down
	-21.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c2f, // short name
	0x4c2f, // name
	0x4c96, // manufacturer
	0x4cbd, // description
	0x0412a678, // flags
};

// 147f8
// type g
s8 invg_000147f8[] = {90, 0, -1};

// 147fc
struct inventory_typef invf_000147fc = {
	0x01000000,
	0x01000035,
	0x00000000,
	0x00000000,
	0x00000000,
};

// 14810
u32 invanim_pp9i_equiporshoot[] = {
	gunscript_playanimation(0x0440, 0, 10000)
	gunscript_waittime(10, 5)
	gunscript_end
};

// 14828
struct inventory_function invfunc_pp9i_shoot = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c55, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_pp9i_equiporshoot, // fire animation
	0x00000000, // flags
};

u32 var0001483c = (u32) &invmenupos_00011098;
u32 var00014840 = 0x10000000;
u32 var00014844 = 0x3f800000;
u32 var00014848 = 0x3f800000;
u32 var0001484c = 0x04080300;
u32 var00014850 = 0x40400000;
u32 var00014854 = 0x41200000;
u32 var00014858 = 0x41efffff;
u32 var0001485c = 0x00000000;
u32 var00014860 = 0x00008069;
u32 var00014864 = 0x01000000;

// 14868
struct inventory_ammo invammo_pp9i = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_PISTOL,
	CASING_STANDARD,
	7, // clip size
	NULL, // reload animation
	0, // style
};

// 1487c
struct inventory_item invitem_pp9i = {
	0x0394, // lo model
	0x0394, // hi model
	invanim_pp9i_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_pp9i_shoot, // pri function
	NULL, // sec function
	&invammo_pp9i, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	10.000000, // left/right
	-14.800000, // up/down
	-19.000000, // front/back
	1.000000, // unk38
	&invf_000147fc, // fptr
	invg_000147f8, // gptr
	0x4c32, // short name
	0x4c32, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x000af67c, // flags
};

// 148cc
u32 invanim_cc13_equiporshoot[] = {
	gunscript_playanimation(0x043f, 0, 10000)
	gunscript_waittime(10, 5)
	gunscript_end
};

// 148e4
struct inventory_function invfunc_cc13_shoot = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c55, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_cc13_equiporshoot, // fire animation
	0x00000000, // flags
};

u32 var000148f8 = (u32) &invmenupos_00011098;
u32 var000148fc = 0x10000000;
u32 var00014900 = 0x3f800000;
u32 var00014904 = 0x40c00000;
u32 var00014908 = 0x04080300;
u32 var0001490c = 0x40a00000;
u32 var00014910 = 0x41200000;
u32 var00014914 = 0x426fffff;
u32 var00014918 = 0x00000000;
u32 var0001491c = 0x0000806a;
u32 var00014920 = 0x01000000;

// 14924
struct inventory_ammo invammo_cc13 = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_PISTOL,
	CASING_STANDARD,
	8, // clip size
	NULL, // reload animation
	0, // style
};

// 14938
struct inventory_item invitem_cc13 = {
	0x0395, // lo model
	0x0395, // hi model
	invanim_cc13_equiporshoot, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_cc13_shoot, // pri function
	NULL, // sec function
	&invammo_cc13, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	10.000000, // left/right
	-17.000000, // up/down
	-26.500000, // front/back
	1.000000, // unk38
	&invf_000147fc, // fptr
	invg_000147f8, // gptr
	0x4c33, // short name
	0x4c33, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x000af67c, // flags
};

// 14988
struct inventory_function invfunc_kl01313_shoot = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c56, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
};

u32 var0001499c = (u32) &invmenupos_00011098;
u32 var000149a0 = 0x00000000;
u32 var000149a4 = 0x3f19999a;
u32 var000149a8 = 0x41700000;
u32 var000149ac = 0x00000006;
u32 var000149b0 = 0x00000000;
u32 var000149b4 = 0x00000000;
u32 var000149b8 = 0x00000000;
u32 var000149bc = 0x00000000;
u32 var000149c0 = 0x0b00806b;
u32 var000149c4 = 0x01000000;
u32 var000149c8 = 0x43e10000;
u32 var000149cc = 0x43e10000;
u32 var000149d0 = 0x00000000;
u32 var000149d4 = 0x00000000;
u32 var000149d8 = 0x00000000;

// 149dc
struct inventory_ammo invammo_kl01313 = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_SMG,
	CASING_STANDARD,
	20, // clip size
	NULL, // reload animation
	0, // style
};

// 149f0
struct inventory_item invitem_kl01313 = {
	0x0396, // lo model
	0x0396, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_kl01313_shoot, // pri function
	NULL, // sec function
	&invammo_kl01313, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	8.500000, // left/right
	-13.000000, // up/down
	-29.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	invg_000147f8, // gptr
	0x4c34, // short name
	0x4c34, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x0000967c, // flags
};

// 14a40
struct inventory_function invfunc_kf7special_shoot = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c57, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000002, // flags
};

u32 var00014a54 = (u32) &invmenupos_00011098;
u32 var00014a58 = 0x00000000;
u32 var00014a5c = 0x3f800000;
u32 var00014a60 = 0x41200000;
u32 var00014a64 = 0x040c0006;
u32 var00014a68 = 0x40900000;
u32 var00014a6c = 0x40000000;
u32 var00014a70 = 0x00000000;
u32 var00014a74 = 0x40400000;
u32 var00014a78 = 0x0400806c;
u32 var00014a7c = 0x01000000;
u32 var00014a80 = 0x43e10000;
u32 var00014a84 = 0x43e10000;
u32 var00014a88 = 0x00000000;
u32 var00014a8c = 0x00000000;
u32 var00014a90 = 0x00000000;

// 14a94
struct inventory_ammo invammo_kf7special = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	NULL, // reload animation
	0, // style
};

// 14aa8
struct inventory_item invitem_kf7special = {
	0x0397, // lo model
	0x0397, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_kf7special_shoot, // pri function
	NULL, // sec function
	&invammo_kf7special, // pri ammo
	NULL, // sec ammo
	&inve_00011140, // eptr
	2.000000, // sway
	13.000000, // left/right
	-21.000000, // up/down
	-13.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	invg_000147f8, // gptr
	0x4c35, // short name
	0x4c35, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x0000967c, // flags
};

// 14af8
struct inventory_function invfunc_zzt9mm_shoot = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c56, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
};

u32 var00014b0c = (u32) &invmenupos_00011098;
u32 var00014b10 = 0x00000000;
u32 var00014b14 = 0x3f800000;
u32 var00014b18 = 0x41100000;
u32 var00014b1c = 0x06120006;
u32 var00014b20 = 0x40800000;
u32 var00014b24 = 0x40400000;
u32 var00014b28 = 0x00000000;
u32 var00014b2c = 0x00000000;
u32 var00014b30 = 0x0400806d;
u32 var00014b34 = 0x01000000;
u32 var00014b38 = 0x44160000;
u32 var00014b3c = 0x44160000;
u32 var00014b40 = 0x00000000;
u32 var00014b44 = 0x00000000;
u32 var00014b48 = 0x00000000;

// 14b4c
struct inventory_ammo invammo_zzt9mm = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_SMG,
	CASING_STANDARD,
	32, // clip size
	NULL, // reload animation
	0, // style
};

// 14b60
struct inventory_item invitem_zzt9mm = {
	0x0398, // lo model
	0x0398, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_zzt9mm_shoot, // pri function
	NULL, // sec function
	&invammo_zzt9mm, // pri ammo
	NULL, // sec ammo
	&inve_000110e0, // eptr
	0.500000, // sway
	11.000000, // left/right
	-24.500000, // up/down
	-37.000000, // front/back
	1.000000, // unk38
	NULL, // fptr
	invg_000147f8, // gptr
	0x4c36, // short name
	0x4c36, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x0000967c, // flags
};

// 14bb0
struct inventory_function invfunc_dmc_shoot = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c56, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
};

u32 var00014bc4 = (u32) &invmenupos_00011098;
u32 var00014bc8 = 0x00000000;
u32 var00014bcc = 0x3f800000;
u32 var00014bd0 = 0x40e00000;
u32 var00014bd4 = 0x06120006;
u32 var00014bd8 = 0x40800000;
u32 var00014bdc = 0x40400000;
u32 var00014be0 = 0x00000000;
u32 var00014be4 = 0x00000000;
u32 var00014be8 = 0x0400806e;
u32 var00014bec = 0x01000000;
u32 var00014bf0 = 0x43e10000;
u32 var00014bf4 = 0x43e10000;
u32 var00014bf8 = 0x00000000;
u32 var00014bfc = 0x00000000;
u32 var00014c00 = 0x00000000;

// 14c04
struct inventory_ammo invammo_dmc = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_SMG,
	CASING_STANDARD,
	30, // clip size
	NULL, // reload animation
	0, // style
};

// 14c18
struct inventory_item invitem_dmc = {
	0x0399, // lo model
	0x0399, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_dmc_shoot, // pri function
	NULL, // sec function
	&invammo_dmc, // pri ammo
	NULL, // sec ammo
	&inve_000110e0, // eptr
	1.000000, // sway
	16.500000, // left/right
	-22.900000, // up/down
	-35.000000, // front/back
	1.000000, // unk38
	NULL, // fptr
	invg_000147f8, // gptr
	0x4c37, // short name
	0x4c37, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x0000967c, // flags
};

// 14c68
struct inventory_function invfunc_ar53_shoot = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c57, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000002, // flags
};

u32 var00014c7c = (u32) &invmenupos_00011098;
u32 var00014c80 = 0x00000000;
u32 var00014c84 = 0x3fb33333;
u32 var00014c88 = 0x40c00000;
u32 var00014c8c = 0x06120208;
u32 var00014c90 = 0x40a00000;
u32 var00014c94 = 0x40000000;
u32 var00014c98 = 0x00000000;
u32 var00014c9c = 0x40800000;
u32 var00014ca0 = 0x0500806f;
u32 var00014ca4 = 0x01000000;
u32 var00014ca8 = 0x44098000;
u32 var00014cac = 0x44098000;
u32 var00014cb0 = 0x00000000;
u32 var00014cb4 = 0x00000000;
u32 var00014cb8 = 0x00000000;

// 14cbc
struct inventory_ammo invammo_ar53 = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_RIFLE,
	CASING_RIFLE,
	30, // clip size
	NULL, // reload animation
	0, // style
};

// 14cd0
struct inventory_item invitem_ar53 = {
	0x039a, // lo model
	0x039a, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_ar53_shoot, // pri function
	NULL, // sec function
	&invammo_ar53, // pri ammo
	NULL, // sec ammo
	&inve_00011140, // eptr
	6.000000, // sway
	11.000000, // left/right
	-19.200001, // up/down
	-21.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	invg_000147f8, // gptr
	0x4c38, // short name
	0x4c38, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x0060967c, // flags
};

// 14d20
struct inventory_function invfunc_rcp45_shoot = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c56, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
};

u32 var00014d34 = (u32) &invmenupos_00011098;
u32 var00014d38 = 0x00000000;
u32 var00014d3c = 0x3fe66666;
u32 var00014d40 = 0x40c00000;
u32 var00014d44 = 0x04080003;
u32 var00014d48 = 0x40600000;
u32 var00014d4c = 0x40000000;
u32 var00014d50 = 0x00000000;
u32 var00014d54 = 0x40800000;
u32 var00014d58 = 0x02008070;
u32 var00014d5c = 0x01000000;
u32 var00014d60 = 0x44160000;
u32 var00014d64 = 0x44160000;
u32 var00014d68 = 0x00000000;
u32 var00014d6c = 0x00000000;
u32 var00014d70 = 0x00000000;

// 14d74
struct inventory_ammo invammo_rcp45 = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_SMG,
	CASING_STANDARD,
	80, // clip size
	NULL, // reload animation
	0, // style
};

// 14d88
struct inventory_item invitem_rcp45 = {
	0x039b, // lo model
	0x039b, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_rcp45_shoot, // pri function
	NULL, // sec function
	&invammo_rcp45, // pri ammo
	NULL, // sec ammo
	&inve_000110e0, // eptr
	4.000000, // sway
	11.000000, // left/right
	-22.299999, // up/down
	-29.000000, // front/back
	1.000000, // unk38
	NULL, // fptr
	invg_000147f8, // gptr
	0x4c39, // short name
	0x4c39, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x0060967c, // flags
};

// 14dd8
struct inventory_function invfunc_briefcase_use = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_NONE,
	0x4c00, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00000000, // flags
};

u32 var00014dec = 0x0000001e;
u32 var00014df0 = 0x00000002;
u32 var00014df4 = 0x00010000;
u32 var00014df8 = 0x00000000;
u32 var00014dfc = 0x00000000;

// 14e00
struct inventory_item invitem_briefcase2 = {
	0x039c, // lo model
	0x039c, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_briefcase_use, // pri function
	&invfunc_briefcase_use, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	12.500000, // left/right
	-17.000000, // up/down
	-27.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c47, // short name
	0x4c47, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x01940808, // flags
};

// 14e50
struct inventory_function invfunc_59_rapidfire = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c56, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
};

u32 var00014e64 = (u32) &invmenupos_00011098;
u32 var00014e68 = 0x00000000;
u32 var00014e6c = 0x3f800000;
u32 var00014e70 = 0x40c00000;
u32 var00014e74 = 0x06120208;
u32 var00014e78 = 0x40a00000;
u32 var00014e7c = 0x40000000;
u32 var00014e80 = 0x00000000;
u32 var00014e84 = 0x40800000;
u32 var00014e88 = 0x04008059;
u32 var00014e8c = 0x02000000;
u32 var00014e90 = 0x44610000;
u32 var00014e94 = 0x44610000;
u32 var00014e98 = 0x00000000;
u32 var00014e9c = 0x00000000;
u32 var00014ea0 = 0x00000000;

// 14ea4
struct inventory_ammo invammo_59 = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_SMG,
	CASING_RIFLE,
	27, // clip size
	NULL, // reload animation
	0, // style
};

// 14eb8
struct inventory_item invitem_59 = {
	0x0000, // lo model
	0x0000, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_59_rapidfire, // pri function
	NULL, // sec function
	&invammo_59, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	16.500000, // left/right
	-19.500000, // up/down
	-24.000000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c00, // short name
	0x4c00, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x00001250, // flags
};

// 14f08
struct inventory_function invfunc_5a_rapidfire = {
	0x0000, // unk00
	0x01, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c56, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	NULL, // fire animation
	0x00000000, // flags
};

u32 var00014f1c = (u32) &invmenupos_00011098;
u32 var00014f20 = 0x00000000;
u32 var00014f24 = 0x3f800000;
u32 var00014f28 = 0x40c00000;
u32 var00014f2c = 0x06120208;
u32 var00014f30 = 0x40a00000;
u32 var00014f34 = 0x40000000;
u32 var00014f38 = 0x00000000;
u32 var00014f3c = 0x40800000;
u32 var00014f40 = 0x0400803f;
u32 var00014f44 = 0x01000000;
u32 var00014f48 = 0x44610000;
u32 var00014f4c = 0x44610000;
u32 var00014f50 = 0x00000000;
u32 var00014f54 = 0x00000000;
u32 var00014f58 = 0x00000000;

// 14f5c
struct inventory_ammo invammo_5a = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_SMG,
	CASING_RIFLE,
	27, // clip size
	NULL, // reload animation
	0, // style
};

// 14f70
struct inventory_item invitem_5a = {
	0x0000, // lo model
	0x0000, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_5a_rapidfire, // pri function
	NULL, // sec function
	&invammo_5a, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	16.500000, // left/right
	-19.500000, // up/down
	-24.000000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c00, // short name
	0x4c00, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x00001250, // flags
};

// 14fc0
struct inventory_typef invf_00014fc0 = {
	0x01000000,
	0x01000035,
	0x00000000,
	0x00000000,
	0x00000000,
};

// 14fd4
u32 invanim_combatknife_equip[] = {
	gunscript_playanimation(0x0403, 0, 10000)
	gunscript_waittime(24, 2)
	gunscript_end
};

// 14fec
u32 invanim_combatknife_slash2[] = {
	gunscript_playanimation(0x0404, 0, 10000)
	gunscript_waittime(24, 2)
	gunscript_end
};

// 15004
u32 invanim_combatknife_slash[] = {
	gunscript_random(50, (u32) invanim_combatknife_slash2)
	gunscript_include(0, (u32) invanim_combatknife_equip)
	gunscript_end
};

// 1501c
u32 invanim_combatknife_pritosec[] = {
	gunscript_playanimation(0x0405, 0, 10000)
	gunscript_playsound(30, 0x80a7)
	gunscript_playsound(40, 0x80a6)
	gunscript_end
};

// 1503c
u32 invanim_combatknife_sectopri[] = {
	gunscript_playanimation(0x0405, 65535, 55536)
	gunscript_playsound(10, 0x80a8)
	gunscript_playsound(20, 0x80a6)
	gunscript_end
};

// 1505c
u32 invanim_combatknife_throw[] = {
	gunscript_playanimation(0x041b, 0, 10000)
	gunscript_waitforzreleased(12)
	gunscript_waittime(16, 2)
	gunscript_end
};

u32 var0001507c = 0x0a00041c;
u32 var00015080 = 0x00002710;
u32 var00015084 = 0x04000016;
u32 var00015088 = 0x00000001;
u32 var0001508c = 0x00000000;
u32 var00015090 = 0x00000000;

// 15094
u32 invanim_combatknife_reload[] = {
	gunscript_include(2, (u32) invanim_combatknife_sectopri)
	gunscript_include(0, (u32) invanim_combatknife_pritosec)
	gunscript_end
};

// 150ac
struct inventory_function invfunc_combatknife_slash = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_CLOSE,
	0x4c6d, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_combatknife_slash, // fire animation
	0x00002000, // flags
};

u32 var000150c0 = 0x40000000;
u32 var000150c4 = 0x428c0000;
u32 var000150c8 = 0x00000069;
u32 var000150cc = 0x00000069;
u32 var000150d0 = 0x00000069;
u32 var000150d4 = 0x41300000;
u32 var000150d8 = 0xc1cc0000;
u32 var000150dc = 0x41300000;
u32 var000150e0 = 0xc1cc0000;
u32 var000150e4 = 0xbf800000;
u32 var000150e8 = 0xbf800000;
u32 var000150ec = 0x40000000;
u32 var000150f0 = 0x40000000;
u32 var000150f4 = 0x00000000;

// 150f8
struct inventory_function invfunc_combatknife_throw = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_THROW,
	0x4c6e, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	invanim_combatknife_throw, // fire animation
	0x00802000, // flags
};

u32 var0001510c = 0x0000010f;
u32 var00015110 = 0x00f00000;
u32 var00015114 = 0x0000003c;
u32 var00015118 = 0x3f800000;

// 1511c
struct inventory_ammo invammo_combatknife = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_KNIFE,
	CASING_NONE,
	1, // clip size
	invanim_combatknife_reload, // reload animation
	167772160, // style
};

// 15130
struct inventory_item invitem_combatknife = {
	0x038f, // lo model
	0x04c2, // hi model
	invanim_combatknife_equip, // equip animation
	NULL, // unequip animation
	invanim_combatknife_pritosec, // pritosec animation
	invanim_combatknife_sectopri, // sectopri animation
	&invfunc_combatknife_slash, // pri function
	&invfunc_combatknife_throw, // sec function
	&invammo_combatknife, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	18.500000, // left/right
	-26.500000, // up/down
	-28.000000, // front/back
	1.000000, // unk38
	&invf_00014fc0, // fptr
	NULL, // gptr
	0x4c53, // short name
	0x4c23, // name
	0x4c00, // manufacturer
	0x4cb6, // description
	0x0402f679, // flags
};

// 15180
struct inventory_function invfunc_bug_throw = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_THROW,
	0x4c00, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00802040, // flags
};

u32 var00015194 = 0x00000012;
u32 var00015198 = 0x00f00000;
u32 var0001519c = 0x0000003c;
u32 var000151a0 = 0x00000000;

// 151a4
struct inventory_function invfunc_targetamplifier_throw = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_THROW,
	0x4c00, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00802040, // flags
};

u32 var000151b8 = 0x000001b1;
u32 var000151bc = 0x00f00000;
u32 var000151c0 = 0x0000003c;
u32 var000151c4 = 0x00000000;

// 151c8
struct inventory_ammo invammo_bug = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_BUG,
	CASING_NONE,
	1, // clip size
	NULL, // reload animation
	33554432, // style
};

// 151dc
struct inventory_item invitem_commsrider = {
	0x0087, // lo model
	0x0087, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_bug_throw, // pri function
	NULL, // sec function
	&invammo_bug, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	0.000000, // left/right
	-39.500000, // up/down
	-55.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4cde, // short name
	0x4cde, // name
	0x4c00, // manufacturer
	0x4ccc, // description
	0x08000018, // flags
};

// 1522c
struct inventory_item invitem_tracerbug = {
	0x0087, // lo model
	0x0087, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_bug_throw, // pri function
	NULL, // sec function
	&invammo_bug, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	0.000000, // left/right
	-39.500000, // up/down
	-55.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4cdf, // short name
	0x4cdf, // name
	0x4c00, // manufacturer
	0x4ccd, // description
	0x08000018, // flags
};

// 1527c
struct inventory_item invitem_targetamplifier = {
	0x07b2, // lo model
	0x07b2, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_targetamplifier_throw, // pri function
	NULL, // sec function
	&invammo_bug, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	0.000000, // left/right
	-39.500000, // up/down
	-55.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4ceb, // short name
	0x4ce0, // name
	0x4c00, // manufacturer
	0x4cce, // description
	0x08000018, // flags
};

// 152cc
struct inventory_function invfunc_nightvision_primary = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_VISUAL,
	0x4c87, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
};

u32 var000152e0 = 0x00000001;

// 152e4
struct inventory_item invitem_nightvision = {
	0x0346, // lo model
	0x0346, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_nightvision_primary, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	0.000000, // left/right
	-39.500000, // up/down
	-55.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c3b, // short name
	0x4c3b, // name
	0x4c00, // manufacturer
	0x4cbf, // description
	0x08001098, // flags
};

// 15334
struct inventory_function invfunc_horizonscanner_primary = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_NONE,
	0x4c8b, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00000000, // flags
};

// 15348
struct inventory_typee inve_00015348 = {
	0x00000000,
	0x40400000,
	0x41000000,
	0x41700000,
	0x3f78db8c,
	0x3f7a0903,
	0x05000000,
	0x00000005,
};

// 15368
struct inventory_item invitem_horizonscanner = {
	0x04e6, // lo model
	0x04e6, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_horizonscanner_primary, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_00015348, // eptr
	1.000000, // sway
	0.000000, // left/right
	-39.500000, // up/down
	-55.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4cea, // short name
	0x4c4c, // name
	0x4c00, // manufacturer
	0x4cc4, // description
	0x08600058, // flags
};

// 153b8
struct inventory_function invfunc_cloak_primary = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_VISUAL,
	0x4c74, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
};

u32 var000153cc = 0x00000040;

// 153d0
struct inventory_ammo invammo_cloakingdevice = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_CLOAK,
	CASING_NONE,
	10, // clip size
	NULL, // reload animation
	16777216, // style
};

// 153e4
struct inventory_item invitem_cloakingdevice = {
	0x04cf, // lo model
	0x04cf, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_cloak_primary, // pri function
	NULL, // sec function
	&invammo_cloakingdevice, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	0.000000, // left/right
	-39.500000, // up/down
	-55.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c49, // short name
	0x4c49, // name
	0x4c00, // manufacturer
	0x4cc3, // description
	0x04000018, // flags
};

// 15434
struct inventory_function invfunc_combatboost_boost = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SPECIAL,
	0x4c71, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
};

u32 var00015448 = 0x00000006;
u32 var0001544c = 0x0000001e;
u32 var00015450 = 0x05c90000;

// 15454
struct inventory_function invfunc_combatboost_revert = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SPECIAL,
	0x4c72, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
};

u32 var00015468 = 0x00000007;
u32 var0001546c = 0x0000001e;
u32 var00015470 = 0x05c90000;

// 15474
struct inventory_ammo invammo_combatboost = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_BOOST,
	CASING_NONE,
	4, // clip size
	NULL, // reload animation
	16777216, // style
};

// 15488
struct inventory_item invitem_combatboost = {
	0x04d0, // lo model
	0x04d0, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_combatboost_boost, // pri function
	&invfunc_combatboost_revert, // sec function
	&invammo_combatboost, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	0.000000, // left/right
	-39.500000, // up/down
	-55.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4ce8, // short name
	0x4c4a, // name
	0x4c00, // manufacturer
	0x4cbe, // description
	0x34000018, // flags
};

// 154d8
struct inventory_function invfunc_suicidepill_primary = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_VISUAL,
	0x4c00, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
};

u32 var000154ec = 0x00000020;

// 154f0
struct inventory_item invitem_suicidepill = {
	0x0000, // lo model
	0x0000, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_suicidepill_primary, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	0.000000, // left/right
	-39.500000, // up/down
	-55.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c48, // short name
	0x4c48, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x08000010, // flags
};

// 15540
struct inventory_function invfunc_irscanner_primary = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_VISUAL,
	0x4c8a, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
};

u32 var00015554 = 0x00000008;

// 15558
struct inventory_item invitem_irscanner = {
	0x074f, // lo model
	0x074f, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_irscanner_primary, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	0.000000, // left/right
	-39.500000, // up/down
	-55.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c45, // short name
	0x4c45, // name
	0x4c00, // manufacturer
	0x4cc2, // description
	0x08001058, // flags
};

// 155a8
struct inventory_function invfunc_disguise_primary = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_NONE,
	0x4c8f, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00000000, // flags
};

// 155bc
struct inventory_item invitem_disguise40 = {
	0x0000, // lo model
	0x0000, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_disguise_primary, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	0.000000, // left/right
	-39.500000, // up/down
	-55.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c2b, // short name
	0x4c2b, // name
	0x4c00, // manufacturer
	0x4cd3, // description
	0x88000018, // flags
};

// 1560c
struct inventory_item invitem_disguise41 = {
	0x0000, // lo model
	0x0000, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_disguise_primary, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	0.000000, // left/right
	-39.500000, // up/down
	-55.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c2b, // short name
	0x4c2b, // name
	0x4c00, // manufacturer
	0x4cd3, // description
	0x88000018, // flags
};

// 1565c
struct inventory_function invfunc_camspy_deploy = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_VISUAL,
	0x4c88, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
};

u32 var00015670 = 0x00000004;

// 15674
struct inventory_item invitem_camspy = {
	0x004b, // lo model
	0x004b, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_camspy_deploy, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	0.000000, // left/right
	-39.500000, // up/down
	-55.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c3c, // short name
	0x4c3c, // name
	0x4c00, // manufacturer
	0x4cc0, // description
	0x08001018, // flags
};

// 156c4
struct inventory_function invfunc_rtracker_primary = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_VISUAL,
	0x4c8e, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
};

u32 var000156d8 = 0x00000010;

// 156dc
struct inventory_item invitem_rtracker = {
	0x076f, // lo model
	0x076f, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_rtracker_primary, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	0.000000, // left/right
	-39.500000, // up/down
	-55.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c46, // short name
	0x4c46, // name
	0x4c00, // manufacturer
	0x4cc6, // description
	0x08001018, // flags
};

// 1572c
struct inventory_function invfunc_xray_primary = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_VISUAL,
	0x4c89, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
};

u32 var00015740 = 0x00000002;

// 15744
struct inventory_item invitem_xrayscanner = {
	0x0770, // lo model
	0x0770, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_xray_primary, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	0.000000, // left/right
	-39.500000, // up/down
	-55.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4ce9, // short name
	0x4c41, // name
	0x4c00, // manufacturer
	0x4cc1, // description
	0x08600058, // flags
};

// 15794
u32 invanim_datauplink_equip[] = {
	gunscript_playanimation(0x0439, 0, 10000)
	gunscript_end
};

// 157a4
u32 invanim_datauplink_unequip[] = {
	gunscript_playanimation(0x043a, 0, 10000)
	gunscript_end
};

u32 var000157b4 = 0x0a00043b;
u32 var000157b8 = 0x00002710;
u32 var000157bc = 0x00000000;
u32 var000157c0 = 0x00000000;

// 157c4
struct inventory_function invfunc_datauplink_primary = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SPECIAL,
	0x4c8d, // name
	0x00, // unk06
	-1, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00102000, // flags
};

u32 var000157d8 = 0x0000000c;
u32 var000157dc = 0x0000001e;
u32 var000157e0 = 0x00000000;

// 157e4
struct inventory_item invitem_datauplink = {
	0x074e, // lo model
	0x074e, // hi model
	invanim_datauplink_equip, // equip animation
	invanim_datauplink_unequip, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_datauplink_primary, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	8.000000, // left/right
	-16.200001, // up/down
	-17.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c4b, // short name
	0x4c4b, // name
	0x4c00, // manufacturer
	0x4cc5, // description
	0x88022048, // flags
};

// 15834
struct inventory_item invitem_doordecoder = {
	0x0772, // lo model
	0x0772, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	35.000000, // left/right
	-26.700001, // up/down
	-41.000000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c3f, // short name
	0x4c3f, // name
	0x4c00, // manufacturer
	0x4cc8, // description
	0x88000008, // flags
};

// 15884
struct inventory_item invitem_rocket = {
	0x0382, // lo model
	0x04bb, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	&invammo_default, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	12.500000, // left/right
	-17.000000, // up/down
	-27.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c2c, // short name
	0x4c2c, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x00000000, // flags
};

// 158d4
struct inventory_item invitem_homingrocket = {
	0x0382, // lo model
	0x04bb, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	&invammo_default, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	12.500000, // left/right
	-17.000000, // up/down
	-27.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c2d, // short name
	0x4c2d, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x00000000, // flags
};

// 15924
struct inventory_item invitem_grenaderound = {
	0x0382, // lo model
	0x04bb, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_devastator_shoot, // pri function
	&invfunc_devastator_wallhugger, // sec function
	&invammo_default, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	12.500000, // left/right
	-17.000000, // up/down
	-27.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c2e, // short name
	0x4c2e, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x00000000, // flags
};

// 15974
struct inventory_item invitem_bolt = {
	0x0382, // lo model
	0x04bb, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_crossbow_shoot, // pri function
	&invfunc_crossbow_lethal, // sec function
	&invammo_default, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	12.500000, // left/right
	-17.000000, // up/down
	-27.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c30, // short name
	0x4c30, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x00000000, // flags
};

u32 var000159c4 = 0x00000004;
u32 var000159c8 = 0x4c9000ff;
u32 var000159cc = (u32) &invmenupos_00010fd0;
u32 var000159d0 = 0x00000000;
u32 var000159d4 = 0x00102000;
u32 var000159d8 = 0x0000000c;
u32 var000159dc = 0x0000001e;
u32 var000159e0 = 0x00000000;

// 159e4
struct inventory_item invitem_skedarbomb = {
	0x075f, // lo model
	0x075f, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	15.500000, // left/right
	-20.200001, // up/down
	-33.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4cdd, // short name
	0x4cdd, // name
	0x4c00, // manufacturer
	0x4ccb, // description
	0x80000000, // flags
};

// 15a34
struct inventory_item invitem_explosives = {
	0x0760, // lo model
	0x0760, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	15.500000, // left/right
	-20.200001, // up/down
	-33.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c40, // short name
	0x4c40, // name
	0x4c00, // manufacturer
	0x4cca, // description
	0x80000000, // flags
};

// 15a84
struct inventory_function invfunc_presidentscanner_primary = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_VISUAL,
	0x4c8e, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00010fd0, // menupos
	NULL, // fire animation
	0x00002000, // flags
};

u32 var00015a98 = 0x00000010;

// 15a9c
struct inventory_item invitem_presidentscanner = {
	0x076f, // lo model
	0x076f, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_presidentscanner_primary, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	0.000000, // left/right
	-39.500000, // up/down
	-55.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4ce7, // short name
	0x4cdb, // name
	0x4c00, // manufacturer
	0x4cc7, // description
	0x08001018, // flags
};

// 15aec
struct inventory_item invitem_autosurgeon = {
	0x049d, // lo model
	0x049d, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	15.500000, // left/right
	-20.200001, // up/down
	-33.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4cdc, // short name
	0x4cdc, // name
	0x4c00, // manufacturer
	0x4cc9, // description
	0x88000000, // flags
};

// 15b3c
struct inventory_item invitem_flightplans = {
	0x0763, // lo model
	0x0763, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	15.500000, // left/right
	-20.200001, // up/down
	-33.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4ce1, // short name
	0x4ce1, // name
	0x4c00, // manufacturer
	0x4ccf, // description
	0x08000000, // flags
};

// 15b8c
struct inventory_item invitem_researchtape = {
	0x0761, // lo model
	0x0761, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	15.500000, // left/right
	-20.200001, // up/down
	-33.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4ce2, // short name
	0x4ce2, // name
	0x4c00, // manufacturer
	0x4cd0, // description
	0x08000000, // flags
};

// 15bdc
struct inventory_item invitem_backupdisk = {
	0x0762, // lo model
	0x0762, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	15.500000, // left/right
	-20.200001, // up/down
	-33.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4ce3, // short name
	0x4ce3, // name
	0x4c00, // manufacturer
	0x4cd1, // description
	0x08000000, // flags
};

// 15c2c
struct inventory_item invitem_briefcase = {
	0x0563, // lo model
	0x0563, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	15.500000, // left/right
	-20.200001, // up/down
	-33.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4ce5, // short name
	0x4ce5, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x08040000, // flags
};

// 15c7c
struct inventory_item invitem_suitcase = {
	0x0086, // lo model
	0x0086, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	15.500000, // left/right
	-20.200001, // up/down
	-33.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c43, // short name
	0x4c43, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x88000000, // flags
};

// 15ccc
struct inventory_item invitem_necklace = {
	0x01c3, // lo model
	0x01c3, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	15.500000, // left/right
	-20.200001, // up/down
	-33.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4ce6, // short name
	0x4ce6, // name
	0x4c00, // manufacturer
	0x4cee, // description
	0x08000000, // flags
};

// 15d1c
struct inventory_item invitem_shield = {
	0x0347, // lo model
	0x0347, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	15.500000, // left/right
	-20.200001, // up/down
	-33.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4cf0, // short name
	0x4cf0, // name
	0x4c00, // manufacturer
	0x4cf1, // description
	0x08000000, // flags
};

// 15d6c
struct inventory_item invitem_keycard = {
	0x0563, // lo model
	0x0563, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	NULL, // pri function
	NULL, // sec function
	NULL, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	15.500000, // left/right
	-20.200001, // up/down
	-33.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4ce4, // short name
	0x4ce4, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x08000000, // flags
};

// 15dbc
struct inventory_function invfunc_rocketlauncher34_primary = {
	0x0000, // unk00
	0x02, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c00, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_00011048, // menupos
	invanim_rockerlauncher_equiporshoot, // fire animation
	0x08000040, // flags
};

u32 var00015dd0 = 0x00000000;
u32 var00015dd4 = 0x00000000;
u32 var00015dd8 = 0x3f800000;
u32 var00015ddc = 0x40c00000;
u32 var00015de0 = 0x030c0f00;
u32 var00015de4 = 0x40400000;
u32 var00015de8 = 0x40000000;
u32 var00015dec = 0x00000000;
u32 var00015df0 = 0x40800000;
u32 var00015df4 = 0x04008053;
u32 var00015df8 = 0x01000000;
u32 var00015dfc = 0x0000011f;
u32 var00015e00 = 0x00000000;
u32 var00015e04 = 0x40066666;
u32 var00015e08 = 0x00000014;
u32 var00015e0c = 0x00000000;
u32 var00015e10 = 0x00000000;
u32 var00015e14 = 0xffffffff;
u32 var00015e18 = 0x3d4ccccd;
u32 var00015e1c = 0x80530000;

// 15e20
struct inventory_ammo invammo_rocketlauncher34 = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_ROCKET,
	CASING_NONE,
	1, // clip size
	invanim_rocketlauncher_reload, // reload animation
	0, // style
};

// 15e34
struct inventory_item invitem_rocketlauncher_34 = {
	0x0388, // lo model
	0x04c9, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_rocketlauncher34_primary, // pri function
	NULL, // sec function
	&invammo_rocketlauncher34, // pri ammo
	NULL, // sec ammo
	&inve_000135f0, // eptr
	1.000000, // sway
	24.500000, // left/right
	-25.200001, // up/down
	-30.000000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c50, // short name
	0x4c1b, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x40026070, // flags
};

// 15e84
u32 invanim_tester_shoot[] = {
	gunscript_playanimation(0x0112, 0, 10000)
	gunscript_end
};

// 15e94
struct inventory_function invfunc_tester_primary = {
	0x0000, // unk00
	0x00, // unk02
	INVENTORYFUNCTYPE_SHOOT,
	0x4c00, // name
	0x00, // unk06
	0, // unk07
	&invmenupos_0001100c, // menupos
	invanim_tester_shoot, // fire animation
	0x00000000, // flags
};

u32 var00015ea8 = (u32) &invmenupos_00011070;
u32 var00015eac = 0x10000000;
u32 var00015eb0 = 0x3f800000;
u32 var00015eb4 = 0x40c00000;
u32 var00015eb8 = 0x04080300;
u32 var00015ebc = 0x00000000;
u32 var00015ec0 = 0x00000000;
u32 var00015ec4 = 0x426fffff;
u32 var00015ec8 = 0x00000000;
u32 var00015ecc = 0x0000804d;
u32 var00015ed0 = 0x01000000;

// 15ed4
struct inventory_ammo invammo_tester = {
	0x0000, // unk00
	0x00, // unk02
	AMMOTYPE_PISTOL,
	CASING_STANDARD,
	8, // clip size
	NULL, // reload animation
	0, // style
};

// 15ee8
struct inventory_item invitem_tester = {
	0x0193, // lo model
	0x0193, // hi model
	NULL, // equip animation
	NULL, // unequip animation
	NULL, // pritosec animation
	NULL, // sectopri animation
	&invfunc_tester_primary, // pri function
	NULL, // sec function
	&invammo_tester, // pri ammo
	NULL, // sec ammo
	&inve_000110c0, // eptr
	1.000000, // sway
	15.500000, // left/right
	-20.200001, // up/down
	-33.500000, // front/back
	1.000000, // unk38
	NULL, // fptr
	NULL, // gptr
	0x4c3a, // short name
	0x4c3a, // name
	0x4c00, // manufacturer
	0x4c00, // description
	0x0000a47c, // flags
};

// 15f38
struct inventory_item *inventorytable[] = {
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
