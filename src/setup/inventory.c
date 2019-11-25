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

u32 var8006b154 = (u32) &invmenupos_00011098;
u32 var8006b158 = 0x00000000;
u32 var8006b15c = 0x3f800000;
u32 var8006b160 = 0x40c00000;
u32 var8006b164 = 0x06120208;
u32 var8006b168 = 0x40a00000;
u32 var8006b16c = 0x40000000;
u32 var8006b170 = 0x00000000;
u32 var8006b174 = 0x40800000;
u32 var8006b178 = 0x04008039;
u32 var8006b17c = 0x01000000;

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
struct weapon invitem_hammer = {
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
struct weapon invitem_nothing = {
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

u32 var8006b2d8 = 0x3f000000;
u32 var8006b2dc = 0x42700000;
u32 var8006b2e0 = 0x00000069;
u32 var8006b2e4 = 0x00000069;
u32 var8006b2e8 = 0x00000069;
u32 var8006b2ec = 0x40f00000;
u32 var8006b2f0 = 0xc20c0000;
u32 var8006b2f4 = 0x40f00000;
u32 var8006b2f8 = 0xc20c0000;
u32 var8006b2fc = 0xbf800000;
u32 var8006b300 = 0xbf800000;
u32 var8006b304 = 0x40000000;
u32 var8006b308 = 0x40000000;
u32 var8006b30c = 0x00000000;

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

u32 var8006b324 = 0x3e99999a;
u32 var8006b328 = 0x42700000;
u32 var8006b32c = 0x00000069;
u32 var8006b330 = 0x00000069;
u32 var8006b334 = 0x00000069;
u32 var8006b338 = 0x40f00000;
u32 var8006b33c = 0xc20c0000;
u32 var8006b340 = 0x40f00000;
u32 var8006b344 = 0xc20c0000;
u32 var8006b348 = 0xbf800000;
u32 var8006b34c = 0xbf800000;
u32 var8006b350 = 0x40000000;
u32 var8006b354 = 0x40000000;
u32 var8006b358 = 0x00000000;

// 1137c
struct weapon invitem_unarmed = {
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

u32 var8006b3e8 = 0x01000000;
u32 var8006b3ec = 0x0100002c;
u32 var8006b3f0 = 0x00000100;
u32 var8006b3f4 = 0x00000100;
u32 var8006b3f8 = 0x002d0000;
u32 var8006b3fc = 0x01000000;
u32 var8006b400 = 0x0100002e;
u32 var8006b404 = 0x00000100;
u32 var8006b408 = 0x00000100;
u32 var8006b40c = 0x002f0000;
u32 var8006b410 = 0x01000000;
u32 var8006b414 = 0x01000035;
u32 var8006b418 = 0x00000000;

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

u32 var8006b438 = 0x01000000;
u32 var8006b43c = 0x0100002d;
u32 var8006b440 = 0x00000100;
u32 var8006b444 = 0x00000100;
u32 var8006b448 = 0x002e0000;
u32 var8006b44c = 0x01000000;
u32 var8006b450 = 0x0100002f;
u32 var8006b454 = 0x00000100;
u32 var8006b458 = 0x00000100;
u32 var8006b45c = 0x00350000;
u32 var8006b460 = 0x00000000;
u32 var8006b464 = 0x00000000;
u32 var8006b468 = 0x00000000;

// 1148c
struct inventory_typef invf_0001148c = {
	0x01000000,
	0x0100002a,
	0x00000100,
	0x00000100,
	0x002b0000,
};

u32 var8006b480 = 0x01000000;
u32 var8006b484 = 0x0100002c;
u32 var8006b488 = 0x00000100;
u32 var8006b48c = 0x00000100;
u32 var8006b490 = 0x002e0000;
u32 var8006b494 = 0x01000000;
u32 var8006b498 = 0x0100002f;
u32 var8006b49c = 0x00000100;
u32 var8006b4a0 = 0x00000100;
u32 var8006b4a4 = 0x00350000;
u32 var8006b4a8 = 0x00000000;
u32 var8006b4ac = 0x00000000;
u32 var8006b4b0 = 0x00000000;

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

u32 var8006b648 = (u32) &invmenupos_00011098;
u32 var8006b64c = 0x10000000;
u32 var8006b650 = 0x3f800000;
u32 var8006b654 = 0x3f800000;
u32 var8006b658 = 0x03050200;
u32 var8006b65c = 0x41200000;
u32 var8006b660 = 0x41700000;
u32 var8006b664 = 0x426fffff;
u32 var8006b668 = 0x00000000;
u32 var8006b66c = 0x0000804d;
u32 var8006b670 = 0x01000000;

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

u32 var8006b688 = (u32) &invmenupos_00011098;
u32 var8006b68c = 0x10000000;
u32 var8006b690 = 0x3f800000;
u32 var8006b694 = 0x3f800000;
u32 var8006b698 = 0x03050200;
u32 var8006b69c = 0x41200000;
u32 var8006b6a0 = 0x41700000;
u32 var8006b6a4 = 0x426fffff;
u32 var8006b6a8 = 0x00000000;
u32 var8006b6ac = 0x00008054;
u32 var8006b6b0 = 0x01000000;

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

u32 var8006b6c8 = 0x3f666666;
u32 var8006b6cc = 0x42700000;
u32 var8006b6d0 = 0x00000069;
u32 var8006b6d4 = 0x00000069;
u32 var8006b6d8 = 0x00000069;
u32 var8006b6dc = 0xc1800000;
u32 var8006b6e0 = 0x3f4ccccd;
u32 var8006b6e4 = 0x41bc0000;
u32 var8006b6e8 = 0xc202cccd;
u32 var8006b6ec = 0xbf800000;
u32 var8006b6f0 = 0xbf800000;
u32 var8006b6f4 = 0x40000000;
u32 var8006b6f8 = 0x40000000;
u32 var8006b6fc = 0x00000000;

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
struct weapon invitem_falcon2 = {
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
struct weapon invitem_falcon2scope = {
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
struct weapon invitem_falcon2silencer = {
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

u32 var8006b834 = 0x01000000;
u32 var8006b838 = 0x01000029;
u32 var8006b83c = 0x00000000;
u32 var8006b840 = 0x00000000;
u32 var8006b844 = 0x00000000;

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

u32 var8006b984 = (u32) &invmenupos_00011098;
u32 var8006b988 = 0x10000000;
u32 var8006b98c = 0x3f8ccccd;
u32 var8006b990 = 0x40c00000;
u32 var8006b994 = 0x04080300;
u32 var8006b998 = 0x40a00000;
u32 var8006b99c = 0x41200000;
u32 var8006b9a0 = 0x426fffff;
u32 var8006b9a4 = 0x41200000;
u32 var8006b9a8 = 0x0000804c;
u32 var8006b9ac = 0x01000000;

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

u32 var8006b9c4 = (u32) &invmenupos_00011098;
u32 var8006b9c8 = 0x10000000;
u32 var8006b9cc = 0x3f8ccccd;
u32 var8006b9d0 = 0x41200000;
u32 var8006b9d4 = 0x090e0000;
u32 var8006b9d8 = 0x41000000;
u32 var8006b9dc = 0x41400000;
u32 var8006b9e0 = 0x426fffff;
u32 var8006b9e4 = 0x41200000;
u32 var8006b9e8 = 0x0000804c;
u32 var8006b9ec = 0x01000000;

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
struct weapon invitem_magsec = {
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

u32 var8006ba78 = 0x01000000;
u32 var8006ba7c = 0x0100002a;
u32 var8006ba80 = 0x00000100;
u32 var8006ba84 = 0x00000100;
u32 var8006ba88 = 0x002b0000;
u32 var8006ba8c = 0x01000000;
u32 var8006ba90 = 0x0100002c;
u32 var8006ba94 = 0x00000100;
u32 var8006ba98 = 0x00000100;
u32 var8006ba9c = 0x002d0000;
u32 var8006baa0 = 0x01000000;
u32 var8006baa4 = 0x01000035;
u32 var8006baa8 = 0x00000000;
u32 var8006baac = 0x00000000;
u32 var8006bab0 = 0x00000000;

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

u32 var8006bc70 = (u32) &invmenupos_00011098;
u32 var8006bc74 = 0x14000000;
u32 var8006bc78 = 0x40000000;
u32 var8006bc7c = 0x00000000;
u32 var8006bc80 = 0x081000ff;
u32 var8006bc84 = 0x41400000;
u32 var8006bc88 = 0x420c0000;
u32 var8006bc8c = 0x00000000;
u32 var8006bc90 = 0x40c00000;
u32 var8006bc94 = 0x00008066;
u32 var8006bc98 = 0x05000000;

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

u32 var8006bcb0 = (u32) &invmenupos_00011098;
u32 var8006bcb4 = 0x1e000000;
u32 var8006bcb8 = 0x43480000;
u32 var8006bcbc = 0x00000000;
u32 var8006bcc0 = 0x081800ff;
u32 var8006bcc4 = 0x41400000;
u32 var8006bcc8 = 0x420c0000;
u32 var8006bccc = 0x00000000;
u32 var8006bcd0 = 0x40c00000;
u32 var8006bcd4 = 0x00008066;
u32 var8006bcd8 = 0x05000000;

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

u32 var8006bcf0 = 0x3f666666;
u32 var8006bcf4 = 0x42700000;
u32 var8006bcf8 = 0x00000069;
u32 var8006bcfc = 0x00000069;
u32 var8006bd00 = 0x00000069;
u32 var8006bd04 = 0x41980000;
u32 var8006bd08 = 0xc195999a;
u32 var8006bd0c = 0x41980000;
u32 var8006bd10 = 0xc195999a;
u32 var8006bd14 = 0xbf800000;
u32 var8006bd18 = 0xbf800000;
u32 var8006bd1c = 0x40000000;
u32 var8006bd20 = 0x40000000;
u32 var8006bd24 = 0x00000000;

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
struct weapon invitem_dy357 = {
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
struct weapon invitem_dy357lx = {
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

u32 var8006bdf4 = 0x00000000;
u32 var8006bdf8 = 0x00000000;
u32 var8006bdfc = 0x00000000;

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

u32 var8006beb4 = (u32) &invmenupos_00011098;
u32 var8006beb8 = 0x10000000;
u32 var8006bebc = 0x3f8ccccd;
u32 var8006bec0 = 0x40400000;
u32 var8006bec4 = 0x03050200;
u32 var8006bec8 = 0x41200000;
u32 var8006becc = 0x41700000;
u32 var8006bed0 = 0x426fffff;
u32 var8006bed4 = 0x00000000;
u32 var8006bed8 = 0x00008071;
u32 var8006bedc = 0x01000000;

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

u32 var8006bef4 = (u32) &invmenupos_00011098;
u32 var8006bef8 = 0x10000000;
u32 var8006befc = 0x3f99999a;
u32 var8006bf00 = 0x40a00000;
u32 var8006bf04 = 0x0d0f1900;
u32 var8006bf08 = 0x41700000;
u32 var8006bf0c = 0x41c80000;
u32 var8006bf10 = 0x426fffff;
u32 var8006bf14 = 0x00000000;
u32 var8006bf18 = 0x00008072;
u32 var8006bf1c = 0x01000000;

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
struct weapon invitem_phoenix = {
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

u32 var8006bfa0 = 0x00000000;
u32 var8006bfa4 = 0x00000000;
u32 var8006bfa8 = 0x00000000;

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

u32 var8006c0bc = 0x0a0003f6;
u32 var8006c0c0 = 0x00002710;
u32 var8006c0c4 = 0x00000000;
u32 var8006c0c8 = 0x00000000;

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

u32 var8006c0e0 = (u32) &invmenupos_00011098;
u32 var8006c0e4 = 0x00000000;
u32 var8006c0e8 = 0x3f99999a;
u32 var8006c0ec = 0x40c00000;
u32 var8006c0f0 = 0x0309201c;
u32 var8006c0f4 = 0x00000000;
u32 var8006c0f8 = 0x00000000;
u32 var8006c0fc = 0x426fffff;
u32 var8006c100 = 0x40800000;
u32 var8006c104 = 0x0000805b;
u32 var8006c108 = 0x01000000;

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

u32 var8006c120 = (u32) &invmenupos_00011098;
u32 var8006c124 = 0x00000000;
u32 var8006c128 = 0x3f99999a;
u32 var8006c12c = 0x40c00000;
u32 var8006c130 = 0x0309201c;
u32 var8006c134 = 0x00000000;
u32 var8006c138 = 0x00000000;
u32 var8006c13c = 0x426fffff;
u32 var8006c140 = 0x40800000;
u32 var8006c144 = 0x0000805b;
u32 var8006c148 = 0x01000000;

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
struct weapon invitem_mauler = {
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

u32 var8006c1cc = 0x01000000;
u32 var8006c1d0 = 0x01000047;
u32 var8006c1d4 = 0x00000000;
u32 var8006c1d8 = 0x00000000;
u32 var8006c1dc = 0x00000000;

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

u32 var8006c31c = (u32) &invmenupos_00011098;
u32 var8006c320 = 0x00000000;
u32 var8006c324 = 0x3f800000;
u32 var8006c328 = 0x41100000;
u32 var8006c32c = 0x06120006;
u32 var8006c330 = 0x40800000;
u32 var8006c334 = 0x40400000;
u32 var8006c338 = 0x00000000;
u32 var8006c33c = 0x00000000;
u32 var8006c340 = 0x03008040;
u32 var8006c344 = 0x01000000;
u32 var8006c348 = 0x44610000;
u32 var8006c34c = 0x44610000;
u32 var8006c350 = 0x00000000;
u32 var8006c354 = 0x00000000;
u32 var8006c358 = 0x00000000;

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

u32 var8006c370 = (u32) &invmenupos_00011098;
u32 var8006c374 = 0x00000000;
u32 var8006c378 = 0x3f800000;
u32 var8006c37c = 0x41100000;
u32 var8006c380 = 0x06120006;
u32 var8006c384 = 0x40800000;
u32 var8006c388 = 0x40400000;
u32 var8006c38c = 0x00000000;
u32 var8006c390 = 0x00000000;
u32 var8006c394 = 0x03008040;
u32 var8006c398 = 0x01000000;
u32 var8006c39c = 0x44610000;
u32 var8006c3a0 = 0x44610000;
u32 var8006c3a4 = 0x00000000;
u32 var8006c3a8 = 0x00000000;
u32 var8006c3ac = 0x00000000;

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
struct weapon invitem_cmp150 = {
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

u32 var8006c430 = 0x00000000;
u32 var8006c434 = 0x00000000;
u32 var8006c438 = 0x00000000;

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

u32 var8006c4c8 = (u32) &invmenupos_00011098;
u32 var8006c4cc = 0x00000000;
u32 var8006c4d0 = 0x3f4ccccd;
u32 var8006c4d4 = 0x40c00000;
u32 var8006c4d8 = 0x06120208;
u32 var8006c4dc = 0x40a00000;
u32 var8006c4e0 = 0x40000000;
u32 var8006c4e4 = 0x00000000;
u32 var8006c4e8 = 0x40800000;
u32 var8006c4ec = 0x0400805f;
u32 var8006c4f0 = 0x01000000;
u32 var8006c4f4 = 0x44610000;
u32 var8006c4f8 = 0x44610000;
u32 var8006c4fc = 0x00000000;
u32 var8006c500 = 0x00000000;
u32 var8006c504 = 0x00000000;

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

u32 var8006c51c = (u32) &invmenupos_00011098;
u32 var8006c520 = 0x00000000;
u32 var8006c524 = 0x3fb33333;
u32 var8006c528 = 0x41c80000;
u32 var8006c52c = 0x06120208;
u32 var8006c530 = 0x40a00000;
u32 var8006c534 = 0x40000000;
u32 var8006c538 = 0x00000000;
u32 var8006c53c = 0x40800000;
u32 var8006c540 = 0x04008075;
u32 var8006c544 = 0x01000000;
u32 var8006c548 = 0x44fa0000;
u32 var8006c54c = 0x44fa0000;
u32 var8006c550 = 0x00000000;
u32 var8006c554 = 0x00000000;
u32 var8006c558 = 0x00000000;

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
struct weapon invitem_cyclone = {
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

u32 var8006c660 = (u32) &invmenupos_00011098;
u32 var8006c664 = 0x00000000;
u32 var8006c668 = 0x3f99999a;
u32 var8006c66c = 0x40c00000;
u32 var8006c670 = 0x06120006;
u32 var8006c674 = 0x40800000;
u32 var8006c678 = 0x40400000;
u32 var8006c67c = 0x00000000;
u32 var8006c680 = 0x00000000;
u32 var8006c684 = 0x0400806d;
u32 var8006c688 = 0x01000000;
u32 var8006c68c = 0x44898000;
u32 var8006c690 = 0x44898000;
u32 var8006c694 = 0x00000000;
u32 var8006c698 = 0x00000000;
u32 var8006c69c = 0x00000000;

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

u32 var8006c6b4 = 0x00000009;
u32 var8006c6b8 = 0x0000001e;
u32 var8006c6bc = 0x00000000;

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
struct weapon invitem_rcp120 = {
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

u32 var8006c7a0 = (u32) &invmenupos_00011098;
u32 var8006c7a4 = 0x00000000;
u32 var8006c7a8 = 0x3f99999a;
u32 var8006c7ac = 0x41100000;
u32 var8006c7b0 = 0x06120006;
u32 var8006c7b4 = 0x40800000;
u32 var8006c7b8 = 0x40400000;
u32 var8006c7bc = 0x00000000;
u32 var8006c7c0 = 0x00000000;
u32 var8006c7c4 = 0x03008063;
u32 var8006c7c8 = 0x01000000;
u32 var8006c7cc = 0x44610000;
u32 var8006c7d0 = 0x44610000;
u32 var8006c7d4 = 0x00000000;
u32 var8006c7d8 = 0x00000000;
u32 var8006c7dc = 0x00000000;

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

u32 var8006c7f4 = (u32) &invmenupos_00011098;
u32 var8006c7f8 = 0x00000000;
u32 var8006c7fc = 0x4019999a;
u32 var8006c800 = 0x41100000;
u32 var8006c804 = 0x06120006;
u32 var8006c808 = 0x40800000;
u32 var8006c80c = 0x40400000;
u32 var8006c810 = 0x00000000;
u32 var8006c814 = 0x00000000;
u32 var8006c818 = 0x03008064;
u32 var8006c81c = 0x05000000;
u32 var8006c820 = 0x43960000;
u32 var8006c824 = 0x43960000;
u32 var8006c828 = 0x00000000;
u32 var8006c82c = 0x00000000;
u32 var8006c830 = 0x00000000;

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
struct weapon invitem_callisto = {
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

u32 var8006c920 = (u32) &invmenupos_00011098;
u32 var8006c924 = 0x00000000;
u32 var8006c928 = 0x3f8ccccd;
u32 var8006c92c = 0x40c00000;
u32 var8006c930 = 0x06120208;
u32 var8006c934 = 0x40a00000;
u32 var8006c938 = 0x40000000;
u32 var8006c93c = 0x00000000;
u32 var8006c940 = 0x40800000;
u32 var8006c944 = 0x04008049;
u32 var8006c948 = 0x01000000;
u32 var8006c94c = 0x442f0000;
u32 var8006c950 = 0x442f0000;
u32 var8006c954 = 0x00000000;
u32 var8006c958 = 0x00000000;
u32 var8006c95c = 0x00000000;

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

u32 var8006c974 = 0x000000ff;
u32 var8006c978 = 0x00f00000;
u32 var8006c97c = 0x0000003c;
u32 var8006c980 = 0x00000000;

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
struct weapon invitem_dragon = {
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

u32 var8006c9fc = 0x00000000;
u32 var8006ca00 = 0x00000000;
u32 var8006ca04 = 0x00000000;

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

u32 var8006cb04 = (u32) &invmenupos_00011098;
u32 var8006cb08 = 0x00000000;
u32 var8006cb0c = 0x3f99999a;
u32 var8006cb10 = 0x40c00000;
u32 var8006cb14 = 0x06120208;
u32 var8006cb18 = 0x40a00000;
u32 var8006cb1c = 0x40000000;
u32 var8006cb20 = 0x00000000;
u32 var8006cb24 = 0x40800000;
u32 var8006cb28 = 0x04008049;
u32 var8006cb2c = 0x01000000;
u32 var8006cb30 = 0x442f0000;
u32 var8006cb34 = 0x442f0000;
u32 var8006cb38 = 0x00000000;
u32 var8006cb3c = 0x00000000;
u32 var8006cb40 = 0x00000000;

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

u32 var8006cb58 = 0x00000000;
u32 var8006cb5c = 0x00000000;
u32 var8006cb60 = 0x3f99999a;
u32 var8006cb64 = 0x40c00000;
u32 var8006cb68 = 0x050fff00;
u32 var8006cb6c = 0x40400000;
u32 var8006cb70 = 0x40000000;
u32 var8006cb74 = 0x00000000;
u32 var8006cb78 = 0x40800000;
u32 var8006cb7c = 0x04008073;
u32 var8006cb80 = 0x01000000;
u32 var8006cb84 = 0x00000123;
u32 var8006cb88 = 0x00000000;
u32 var8006cb8c = 0x3f800000;
u32 var8006cb90 = 0x00000000;
u32 var8006cb94 = 0x3da3d70a;
u32 var8006cb98 = 0x0000001e;
u32 var8006cb9c = 0x000004b0;
u32 var8006cba0 = 0x3dcccccd;
u32 var8006cba4 = 0x80530000;

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
struct weapon invitem_superdragon = {
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

u32 var8006ccd8 = (u32) &invmenupos_00011098;
u32 var8006ccdc = 0x00000000;
u32 var8006cce0 = 0x3fb33333;
u32 var8006cce4 = 0x41000000;
u32 var8006cce8 = 0x06120208;
u32 var8006ccec = 0x40a00000;
u32 var8006ccf0 = 0x40000000;
u32 var8006ccf4 = 0x00000000;
u32 var8006ccf8 = 0x40800000;
u32 var8006ccfc = 0x05008059;
u32 var8006cd00 = 0x01000000;
u32 var8006cd04 = 0x443b8000;
u32 var8006cd08 = 0x443b8000;
u32 var8006cd0c = 0x00000000;
u32 var8006cd10 = 0x00000000;
u32 var8006cd14 = 0x00000000;

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

u32 var8006cd2c = (u32) &invmenupos_00011098;
u32 var8006cd30 = 0x00000000;
u32 var8006cd34 = 0x3fb33333;
u32 var8006cd38 = 0x41000000;
u32 var8006cd3c = 0x06120208;
u32 var8006cd40 = 0x40a00000;
u32 var8006cd44 = 0x40000000;
u32 var8006cd48 = 0x00000000;
u32 var8006cd4c = 0x40800000;
u32 var8006cd50 = 0x05008059;
u32 var8006cd54 = 0x01000000;
u32 var8006cd58 = 0x443b8000;
u32 var8006cd5c = 0x443b8000;
u32 var8006cd60 = 0x00000000;
u32 var8006cd64 = 0x00000000;
u32 var8006cd68 = 0x00000000;

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
struct weapon invitem_ar34 = {
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

u32 var8006ce6c = 0x0a0000e8;
u32 var8006ce70 = 0x00002710;
u32 var8006ce74 = 0x00000000;
u32 var8006ce78 = 0x00000000;

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

u32 var8006ceb0 = (u32) &invmenupos_00011098;
u32 var8006ceb4 = 0x00000000;
u32 var8006ceb8 = 0x3fc00000;
u32 var8006cebc = 0x40c00000;
u32 var8006cec0 = 0x06120208;
u32 var8006cec4 = 0x40a00000;
u32 var8006cec8 = 0x40000000;
u32 var8006cecc = 0x00000000;
u32 var8006ced0 = 0x40800000;
u32 var8006ced4 = 0x0400805a;
u32 var8006ced8 = 0x01000000;
u32 var8006cedc = 0x446d8000;
u32 var8006cee0 = 0x446d8000;
u32 var8006cee4 = 0x00000000;
u32 var8006cee8 = 0x00000000;
u32 var8006ceec = 0x00000000;

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

u32 var8006cf04 = (u32) &invmenupos_00011098;
u32 var8006cf08 = 0x00000000;
u32 var8006cf0c = 0x3fc00000;
u32 var8006cf10 = 0x40c00000;
u32 var8006cf14 = 0x06120208;
u32 var8006cf18 = 0x40a00000;
u32 var8006cf1c = 0x40000000;
u32 var8006cf20 = 0x00000000;
u32 var8006cf24 = 0x40800000;
u32 var8006cf28 = 0x0400805a;
u32 var8006cf2c = 0x01000000;
u32 var8006cf30 = 0x446d8000;
u32 var8006cf34 = 0x446d8000;
u32 var8006cf38 = 0x00000000;
u32 var8006cf3c = 0x00000000;
u32 var8006cf40 = 0x00000000;

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
struct weapon invitem_k7avenger = {
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

u32 var8006cfbc = 0x00000000;
u32 var8006cfc0 = 0x00000000;
u32 var8006cfc4 = 0x00000000;

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

u32 var8006d0f4 = (u32) &invmenupos_00011098;
u32 var8006d0f8 = 0x00000000;
u32 var8006d0fc = 0x3f933333;
u32 var8006d100 = 0x40c00000;
u32 var8006d104 = 0x06120208;
u32 var8006d108 = 0x40a00000;
u32 var8006d10c = 0x40000000;
u32 var8006d110 = 0x00000000;
u32 var8006d114 = 0x40800000;
u32 var8006d118 = 0x04008044;
u32 var8006d11c = 0x01000000;
u32 var8006d120 = 0x447a0000;
u32 var8006d124 = 0x447a0000;
u32 var8006d128 = 0x00000000;
u32 var8006d12c = 0x00000000;
u32 var8006d130 = 0x00000000;

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

u32 var8006d148 = 0x00000157;
u32 var8006d14c = 0x00f00000;
u32 var8006d150 = 0x0000003c;
u32 var8006d154 = 0x00000000;

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
struct weapon invitem_laptopgun = {
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

u32 var8006d26c = (u32) &invmenupos_00011098;
u32 var8006d270 = 0x00000000;
u32 var8006d274 = 0x3f19999a;
u32 var8006d278 = 0x41f00000;
u32 var8006d27c = 0x141c0000;
u32 var8006d280 = 0x00000000;
u32 var8006d284 = 0x00000000;
u32 var8006d288 = 0x00000000;
u32 var8006d28c = 0x40800000;
u32 var8006d290 = 0x00008055;
u32 var8006d294 = 0x01000000;

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

u32 var8006d2ac = (u32) &invmenupos_00011098;
u32 var8006d2b0 = 0x00000000;
u32 var8006d2b4 = 0x3f19999a;
u32 var8006d2b8 = 0x41800000;
u32 var8006d2bc = 0x141c0000;
u32 var8006d2c0 = 0x00000000;
u32 var8006d2c4 = 0x00000000;
u32 var8006d2c8 = 0x00000000;
u32 var8006d2cc = 0x40800000;
u32 var8006d2d0 = 0x00008055;
u32 var8006d2d4 = 0x01000000;

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
struct weapon invitem_shotgun = {
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

u32 var8006d33c = 0x00000000;
u32 var8006d340 = 0x3f800000;
u32 var8006d344 = 0x3f800000;
u32 var8006d348 = 0x3f800000;
u32 var8006d34c = 0x3f800000;
u32 var8006d350 = 0x3f800000;
u32 var8006d354 = 0x3f800000;
u32 var8006d358 = 0x00000000;
u32 var8006d35c = 0x00000000;
u32 var8006d360 = 0x00000000;
u32 var8006d364 = 0x00000000;
u32 var8006d368 = 0x00000000;
u32 var8006d36c = 0x3f800000;
u32 var8006d370 = 0x3f800000;
u32 var8006d374 = 0x3f800000;
u32 var8006d378 = 0x3f800000;
u32 var8006d37c = 0x3f800000;
u32 var8006d380 = 0x3f800000;
u32 var8006d384 = 0x3f800000;
u32 var8006d388 = 0x00000000;
u32 var8006d38c = 0x00000000;
u32 var8006d390 = 0x00000000;
u32 var8006d394 = 0x00000000;
u32 var8006d398 = 0x00000000;

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

u32 var8006d450 = (u32) &invmenupos_000110ac;
u32 var8006d454 = 0x00000000;
u32 var8006d458 = 0x3f99999a;
u32 var8006d45c = 0x42600000;
u32 var8006d460 = 0x0309201c;
u32 var8006d464 = 0x00000000;
u32 var8006d468 = 0x00000000;
u32 var8006d46c = 0x00000000;
u32 var8006d470 = 0x40800000;
u32 var8006d474 = 0x0200803f;
u32 var8006d478 = 0x01000000;
u32 var8006d47c = 0x42700000;
u32 var8006d480 = 0x44e10000;
u32 var8006d484 = (u32) &var8006d33c;
u32 var8006d488 = (u32) &var8006d36c;
u32 var8006d48c = 0x58580000;

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

u32 var8006d4a4 = 0x3d4ccccd;
u32 var8006d4a8 = 0x42a00000;
u32 var8006d4ac = 0x00000069;
u32 var8006d4b0 = 0x00000069;
u32 var8006d4b4 = 0x00000069;
u32 var8006d4b8 = 0xbf000000;
u32 var8006d4bc = 0xc1a9999a;
u32 var8006d4c0 = 0xbf000000;
u32 var8006d4c4 = 0xc1a9999a;
u32 var8006d4c8 = 0xbf800000;
u32 var8006d4cc = 0xbf800000;
u32 var8006d4d0 = 0x40000000;
u32 var8006d4d4 = 0x40000000;
u32 var8006d4d8 = 0x00000000;

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
struct weapon invitem_reaper = {
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

u32 var8006d604 = 0x00000000;
u32 var8006d608 = 0x00000000;
u32 var8006d60c = 0x3f800000;
u32 var8006d610 = 0x40c00000;
u32 var8006d614 = 0x030c0f00;
u32 var8006d618 = 0x40400000;
u32 var8006d61c = 0x40000000;
u32 var8006d620 = 0x00000000;
u32 var8006d624 = 0x40800000;
u32 var8006d628 = 0x04008053;
u32 var8006d62c = 0x01000000;
u32 var8006d630 = 0x0000011f;
u32 var8006d634 = 0x00000000;
u32 var8006d638 = 0x40066666;
u32 var8006d63c = 0x0000003c;
u32 var8006d640 = 0x00000000;
u32 var8006d644 = 0x00000000;
u32 var8006d648 = 0xffffffff;
u32 var8006d64c = 0x3d4ccccd;
u32 var8006d650 = 0x80530000;

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

u32 var8006d668 = 0x00000000;
u32 var8006d66c = 0x00000000;
u32 var8006d670 = 0x3f800000;
u32 var8006d674 = 0x40c00000;
u32 var8006d678 = 0x030c0f00;
u32 var8006d67c = 0x40400000;
u32 var8006d680 = 0x40000000;
u32 var8006d684 = 0x00000000;
u32 var8006d688 = 0x40800000;
u32 var8006d68c = 0x04008053;
u32 var8006d690 = 0x01000000;
u32 var8006d694 = 0x0000011f;
u32 var8006d698 = 0x00000000;
u32 var8006d69c = 0x40066666;
u32 var8006d6a0 = 0x00000000;
u32 var8006d6a4 = 0x00000000;
u32 var8006d6a8 = 0x00000005;
u32 var8006d6ac = 0xffffffff;
u32 var8006d6b0 = 0x3d4ccccd;
u32 var8006d6b4 = 0x80530000;

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
struct weapon invitem_rocketlauncher = {
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

u32 var8006d778 = 0x00000000;
u32 var8006d77c = 0x00000000;
u32 var8006d780 = 0x3f800000;
u32 var8006d784 = 0x40c00000;
u32 var8006d788 = 0x030c0f00;
u32 var8006d78c = 0x40400000;
u32 var8006d790 = 0x40000000;
u32 var8006d794 = 0x00000000;
u32 var8006d798 = 0x40800000;
u32 var8006d79c = 0x04008067;
u32 var8006d7a0 = 0x01000000;
u32 var8006d7a4 = 0x00000120;
u32 var8006d7a8 = 0x00000000;
u32 var8006d7ac = 0x40833333;
u32 var8006d7b0 = 0x0000000a;
u32 var8006d7b4 = 0x00000000;
u32 var8006d7b8 = 0x00000000;
u32 var8006d7bc = 0xffffffff;
u32 var8006d7c0 = 0x3d4ccccd;
u32 var8006d7c4 = 0x80530000;

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

u32 var8006d7dc = 0x00000000;
u32 var8006d7e0 = 0x00000000;
u32 var8006d7e4 = 0x3f800000;
u32 var8006d7e8 = 0x40c00000;
u32 var8006d7ec = 0x030c0f00;
u32 var8006d7f0 = 0x40400000;
u32 var8006d7f4 = 0x40000000;
u32 var8006d7f8 = 0x00000000;
u32 var8006d7fc = 0x40800000;
u32 var8006d800 = 0x04008067;
u32 var8006d804 = 0x01000000;
u32 var8006d808 = 0x00000120;
u32 var8006d80c = 0x00000000;
u32 var8006d810 = 0x40833333;
u32 var8006d814 = 0x0000000a;
u32 var8006d818 = 0x00000000;
u32 var8006d81c = 0x00000000;
u32 var8006d820 = 0xffffffff;
u32 var8006d824 = 0x3d4ccccd;
u32 var8006d828 = 0x80680000;

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
struct weapon invitem_slayer = {
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

u32 var8006d890 = 0x01000000;
u32 var8006d894 = 0x01000029;
u32 var8006d898 = 0x00000000;
u32 var8006d89c = 0x00000000;
u32 var8006d8a0 = 0x00000000;

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

u32 var8006d928 = 0x00000000;
u32 var8006d92c = 0x00000000;
u32 var8006d930 = 0x3f800000;
u32 var8006d934 = 0x40c00000;
u32 var8006d938 = 0x053aff00;
u32 var8006d93c = 0x40a00000;
u32 var8006d940 = 0x41000000;
u32 var8006d944 = 0x00000000;
u32 var8006d948 = 0x40800000;
u32 var8006d94c = 0x04008073;
u32 var8006d950 = 0x01000000;
u32 var8006d954 = 0x00000122;
u32 var8006d958 = 0x00000000;
u32 var8006d95c = 0x3f800000;
u32 var8006d960 = 0x00000000;
u32 var8006d964 = 0x3da3d70a;
u32 var8006d968 = 0x00000028;
u32 var8006d96c = 0x000004b0;
u32 var8006d970 = 0x3e99999a;
u32 var8006d974 = 0x80530000;

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

u32 var8006d98c = 0x00000000;
u32 var8006d990 = 0x00000000;
u32 var8006d994 = 0x3f800000;
u32 var8006d998 = 0x40c00000;
u32 var8006d99c = 0x053aff00;
u32 var8006d9a0 = 0x40a00000;
u32 var8006d9a4 = 0x41000000;
u32 var8006d9a8 = 0x00000000;
u32 var8006d9ac = 0x40800000;
u32 var8006d9b0 = 0x04008073;
u32 var8006d9b4 = 0x01000000;
u32 var8006d9b8 = 0x00000122;
u32 var8006d9bc = 0x00000000;
u32 var8006d9c0 = 0x3f800000;
u32 var8006d9c4 = 0x00000000;
u32 var8006d9c8 = 0x3da3d70a;
u32 var8006d9cc = 0x00000028;
u32 var8006d9d0 = 0x00000168;
u32 var8006d9d4 = 0x3e99999a;
u32 var8006d9d8 = 0x80530000;

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
struct weapon invitem_devastator = {
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

u32 var8006daac = 0x00000113;
u32 var8006dab0 = 0x00f00000;
u32 var8006dab4 = 0x00000000;
u32 var8006dab8 = 0x00000000;

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
struct weapon invitem_timedmine = {
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

u32 var8006db34 = 0x06000000;
u32 var8006db38 = 0x03000036;
u32 var8006db3c = 0x00000600;
u32 var8006db40 = 0x00000300;
u32 var8006db44 = 0x00280000;
u32 var8006db48 = 0x00000000;
u32 var8006db4c = 0x00000000;
u32 var8006db50 = 0x00000000;

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

u32 var8006dba8 = 0x00000115;
u32 var8006dbac = 0x00f00000;
u32 var8006dbb0 = 0x00000000;
u32 var8006dbb4 = 0x00000000;

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

u32 var8006dbcc = 0x00000005;
u32 var8006dbd0 = 0x0000001e;
u32 var8006dbd4 = 0x00000000;

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
struct weapon invitem_remotemine = {
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

u32 var8006dc54 = 0x00000114;
u32 var8006dc58 = 0x00f00000;
u32 var8006dc5c = 0x00000000;
u32 var8006dc60 = 0x00000000;

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
struct weapon invitem_proximitymine = {
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

u32 var8006dd14 = 0x00000116;
u32 var8006dd18 = 0x00f00000;
u32 var8006dd1c = 0x0000003c;
u32 var8006dd20 = 0x00000000;

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
struct weapon invitem_ecmmine = {
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

u32 var8006dd88 = 0x0387039d;
u32 var8006dd8c = 0x00000000;
u32 var8006dd90 = 0x00000000;
u32 var8006dd94 = 0x00000000;
u32 var8006dd98 = 0x00000000;
u32 var8006dd9c = (u32) &invfunc_remotemine_detonate;
u32 var8006dda0 = 0x00000000;
u32 var8006dda4 = 0x00000000;
u32 var8006dda8 = 0x00000000;
u32 var8006ddac = (u32) &inve_000110c0;
u32 var8006ddb0 = 0x3f800000;
u32 var8006ddb4 = 0x00000000;
u32 var8006ddb8 = 0xc21e0000;
u32 var8006ddbc = 0xc25e0000;
u32 var8006ddc0 = 0x3f800000;
u32 var8006ddc4 = 0x00000000;
u32 var8006ddc8 = 0x00000000;
u32 var8006ddcc = 0x4c264c26;
u32 var8006ddd0 = 0x4c004c00;
u32 var8006ddd4 = 0x08000048;

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

u32 var8006de40 = 0x00000112;
u32 var8006de44 = 0x00f00000;
u32 var8006de48 = 0x0000003c;
u32 var8006de4c = 0x00000000;

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

u32 var8006de64 = 0x00000112;
u32 var8006de68 = 0x005a0000;
u32 var8006de6c = 0x0000003c;
u32 var8006de70 = 0x00000000;

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
struct weapon invitem_grenade = {
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

u32 var8006deec = 0x00000110;
u32 var8006def0 = 0x00f00000;
u32 var8006def4 = 0x0000003c;
u32 var8006def8 = 0x00000000;

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

u32 var8006df10 = 0x00000110;
u32 var8006df14 = 0x00f00000;
u32 var8006df18 = 0x0000003c;
u32 var8006df1c = 0x00000000;

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
struct weapon invitem_nbomb = {
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

u32 var8006e00c = (u32) &invmenupos_00011098;
u32 var8006e010 = 0x00000000;
u32 var8006e014 = 0x42c80000;
u32 var8006e018 = 0x00000000;
u32 var8006e01c = 0x46280000;
u32 var8006e020 = 0x00000000;
u32 var8006e024 = 0x00000000;
u32 var8006e028 = 0x00000000;
u32 var8006e02c = 0x00000000;
u32 var8006e030 = 0x0400813e;
u32 var8006e034 = 0x05000000;

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

u32 var8006e04c = (u32) &invmenupos_00011098;
u32 var8006e050 = 0x00000000;
u32 var8006e054 = 0x42c80000;
u32 var8006e058 = 0x00000000;
u32 var8006e05c = 0x46280000;
u32 var8006e060 = 0x00000000;
u32 var8006e064 = 0x00000000;
u32 var8006e068 = 0x00000000;
u32 var8006e06c = 0x00000000;
u32 var8006e070 = 0x0400813e;
u32 var8006e074 = 0x05000000;

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
struct weapon invitem_farsight = {
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

u32 var8006e0f4 = 0x00000000;
u32 var8006e0f8 = 0x00000000;
u32 var8006e0fc = 0x00000000;

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

u32 var8006e1d4 = 0x00000000;
u32 var8006e1d8 = 0x00000000;
u32 var8006e1dc = 0x42c80000;
u32 var8006e1e0 = 0x40c00000;
u32 var8006e1e4 = 0x030c0f00;
u32 var8006e1e8 = 0x40400000;
u32 var8006e1ec = 0x40000000;
u32 var8006e1f0 = 0x00000000;
u32 var8006e1f4 = 0x40800000;
u32 var8006e1f8 = 0x04008056;
u32 var8006e1fc = 0x01000000;
u32 var8006e200 = 0x00000121;
u32 var8006e204 = 0x00000000;
u32 var8006e208 = 0x40066666;
u32 var8006e20c = 0x00000000;
u32 var8006e210 = 0x00000000;
u32 var8006e214 = 0x0000003c;
u32 var8006e218 = 0xffffffff;
u32 var8006e21c = 0x3d4ccccd;
u32 var8006e220 = 0xffff0000;

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

u32 var8006e238 = 0x00000000;
u32 var8006e23c = 0x00000000;
u32 var8006e240 = 0x3f800000;
u32 var8006e244 = 0x40c00000;
u32 var8006e248 = 0x030c0f00;
u32 var8006e24c = 0x40400000;
u32 var8006e250 = 0x40000000;
u32 var8006e254 = 0x00000000;
u32 var8006e258 = 0x40800000;
u32 var8006e25c = 0x04008056;
u32 var8006e260 = 0x01000000;
u32 var8006e264 = 0x00000121;
u32 var8006e268 = 0x00000000;
u32 var8006e26c = 0x40066666;
u32 var8006e270 = 0x00000000;
u32 var8006e274 = 0x00000000;
u32 var8006e278 = 0x0000003c;
u32 var8006e27c = 0xffffffff;
u32 var8006e280 = 0x3d4ccccd;
u32 var8006e284 = 0xffff0000;

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
struct weapon invitem_crossbow = {
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

u32 var8006e308 = 0x00000000;
u32 var8006e30c = 0x00000000;
u32 var8006e310 = 0x00000000;

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

u32 var8006e3e8 = (u32) &invmenupos_00011098;
u32 var8006e3ec = 0x10000000;
u32 var8006e3f0 = 0x3e800000;
u32 var8006e3f4 = 0x40400000;
u32 var8006e3f8 = 0x03050500;
u32 var8006e3fc = 0x3f800000;
u32 var8006e400 = 0x00000000;
u32 var8006e404 = 0x426fffff;
u32 var8006e408 = 0x00000000;
u32 var8006e40c = 0x00008057;
u32 var8006e410 = 0x01000000;

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

u32 var8006e428 = 0x42c80000;
u32 var8006e42c = 0x42700000;
u32 var8006e430 = 0x00000069;
u32 var8006e434 = 0x00000069;
u32 var8006e438 = 0x00000069;
u32 var8006e43c = 0x41200000;
u32 var8006e440 = 0xc181999a;
u32 var8006e444 = 0x41200000;
u32 var8006e448 = 0xc181999a;
u32 var8006e44c = 0xbf800000;
u32 var8006e450 = 0xbf800000;
u32 var8006e454 = 0x40000000;
u32 var8006e458 = 0x40000000;
u32 var8006e45c = 0x00000000;

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
struct weapon invitem_tranquilizer = {
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

u32 var8006e4f4 = (u32) &invmenupos_00011098;
u32 var8006e4f8 = 0x10000000;
u32 var8006e4fc = 0x3f000000;
u32 var8006e500 = 0x40400000;
u32 var8006e504 = 0x03050500;
u32 var8006e508 = 0x3f800000;
u32 var8006e50c = 0x00000000;
u32 var8006e510 = 0x426fffff;
u32 var8006e514 = 0x00000000;
u32 var8006e518 = 0x00008057;
u32 var8006e51c = 0x01000000;

// 14540
struct weapon invitem_psychosisgun = {
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

u32 var8006e620 = (u32) &invmenupos_00011098;
u32 var8006e624 = 0x10000000;
u32 var8006e628 = 0x3f99999a;
u32 var8006e62c = 0x00000000;
u32 var8006e630 = 0x060a0000;
u32 var8006e634 = 0x41000000;
u32 var8006e638 = 0x00000000;
u32 var8006e63c = 0x00000000;
u32 var8006e640 = 0x00000000;
u32 var8006e644 = 0x04008058;
u32 var8006e648 = 0x01000000;

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

u32 var8006e660 = 0x00000008;
u32 var8006e664 = 0x0000001e;
u32 var8006e668 = 0x00000000;

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
struct weapon invitem_sniperrifle = {
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

u32 var8006e708 = (u32) &invmenupos_00011098;
u32 var8006e70c = 0x00000000;
u32 var8006e710 = 0x3f800000;
u32 var8006e714 = 0x00000000;
u32 var8006e718 = 0x061218ff;
u32 var8006e71c = 0x00000000;
u32 var8006e720 = 0x00000000;
u32 var8006e724 = 0x00000000;
u32 var8006e728 = 0x00000000;
u32 var8006e72c = 0x03008043;
u32 var8006e730 = 0x01000000;

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

u32 var8006e748 = (u32) &invmenupos_00011084;
u32 var8006e74c = 0x00000000;
u32 var8006e750 = 0x3dcccccd;
u32 var8006e754 = 0x00000000;
u32 var8006e758 = 0x06120006;
u32 var8006e75c = 0x40800000;
u32 var8006e760 = 0x40400000;
u32 var8006e764 = 0x00000000;
u32 var8006e768 = 0x00000000;
u32 var8006e76c = 0x03000000;
u32 var8006e770 = 0x01000000;
u32 var8006e774 = 0x45610000;
u32 var8006e778 = 0x45610000;
u32 var8006e77c = 0x00000000;
u32 var8006e780 = 0x00000000;
u32 var8006e784 = 0x00000000;

// 147a8
struct weapon invitem_laser = {
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

u32 var8006e81c = (u32) &invmenupos_00011098;
u32 var8006e820 = 0x10000000;
u32 var8006e824 = 0x3f800000;
u32 var8006e828 = 0x3f800000;
u32 var8006e82c = 0x04080300;
u32 var8006e830 = 0x40400000;
u32 var8006e834 = 0x41200000;
u32 var8006e838 = 0x41efffff;
u32 var8006e83c = 0x00000000;
u32 var8006e840 = 0x00008069;
u32 var8006e844 = 0x01000000;

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
struct weapon invitem_pp9i = {
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

u32 var8006e8d8 = (u32) &invmenupos_00011098;
u32 var8006e8dc = 0x10000000;
u32 var8006e8e0 = 0x3f800000;
u32 var8006e8e4 = 0x40c00000;
u32 var8006e8e8 = 0x04080300;
u32 var8006e8ec = 0x40a00000;
u32 var8006e8f0 = 0x41200000;
u32 var8006e8f4 = 0x426fffff;
u32 var8006e8f8 = 0x00000000;
u32 var8006e8fc = 0x0000806a;
u32 var8006e900 = 0x01000000;

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
struct weapon invitem_cc13 = {
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

u32 var8006e97c = (u32) &invmenupos_00011098;
u32 var8006e980 = 0x00000000;
u32 var8006e984 = 0x3f19999a;
u32 var8006e988 = 0x41700000;
u32 var8006e98c = 0x00000006;
u32 var8006e990 = 0x00000000;
u32 var8006e994 = 0x00000000;
u32 var8006e998 = 0x00000000;
u32 var8006e99c = 0x00000000;
u32 var8006e9a0 = 0x0b00806b;
u32 var8006e9a4 = 0x01000000;
u32 var8006e9a8 = 0x43e10000;
u32 var8006e9ac = 0x43e10000;
u32 var8006e9b0 = 0x00000000;
u32 var8006e9b4 = 0x00000000;
u32 var8006e9b8 = 0x00000000;

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
struct weapon invitem_kl01313 = {
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

u32 var8006ea34 = (u32) &invmenupos_00011098;
u32 var8006ea38 = 0x00000000;
u32 var8006ea3c = 0x3f800000;
u32 var8006ea40 = 0x41200000;
u32 var8006ea44 = 0x040c0006;
u32 var8006ea48 = 0x40900000;
u32 var8006ea4c = 0x40000000;
u32 var8006ea50 = 0x00000000;
u32 var8006ea54 = 0x40400000;
u32 var8006ea58 = 0x0400806c;
u32 var8006ea5c = 0x01000000;
u32 var8006ea60 = 0x43e10000;
u32 var8006ea64 = 0x43e10000;
u32 var8006ea68 = 0x00000000;
u32 var8006ea6c = 0x00000000;
u32 var8006ea70 = 0x00000000;

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
struct weapon invitem_kf7special = {
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

u32 var8006eaec = (u32) &invmenupos_00011098;
u32 var8006eaf0 = 0x00000000;
u32 var8006eaf4 = 0x3f800000;
u32 var8006eaf8 = 0x41100000;
u32 var8006eafc = 0x06120006;
u32 var8006eb00 = 0x40800000;
u32 var8006eb04 = 0x40400000;
u32 var8006eb08 = 0x00000000;
u32 var8006eb0c = 0x00000000;
u32 var8006eb10 = 0x0400806d;
u32 var8006eb14 = 0x01000000;
u32 var8006eb18 = 0x44160000;
u32 var8006eb1c = 0x44160000;
u32 var8006eb20 = 0x00000000;
u32 var8006eb24 = 0x00000000;
u32 var8006eb28 = 0x00000000;

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
struct weapon invitem_zzt9mm = {
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

u32 var8006eba4 = (u32) &invmenupos_00011098;
u32 var8006eba8 = 0x00000000;
u32 var8006ebac = 0x3f800000;
u32 var8006ebb0 = 0x40e00000;
u32 var8006ebb4 = 0x06120006;
u32 var8006ebb8 = 0x40800000;
u32 var8006ebbc = 0x40400000;
u32 var8006ebc0 = 0x00000000;
u32 var8006ebc4 = 0x00000000;
u32 var8006ebc8 = 0x0400806e;
u32 var8006ebcc = 0x01000000;
u32 var8006ebd0 = 0x43e10000;
u32 var8006ebd4 = 0x43e10000;
u32 var8006ebd8 = 0x00000000;
u32 var8006ebdc = 0x00000000;
u32 var8006ebe0 = 0x00000000;

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
struct weapon invitem_dmc = {
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

u32 var8006ec5c = (u32) &invmenupos_00011098;
u32 var8006ec60 = 0x00000000;
u32 var8006ec64 = 0x3fb33333;
u32 var8006ec68 = 0x40c00000;
u32 var8006ec6c = 0x06120208;
u32 var8006ec70 = 0x40a00000;
u32 var8006ec74 = 0x40000000;
u32 var8006ec78 = 0x00000000;
u32 var8006ec7c = 0x40800000;
u32 var8006ec80 = 0x0500806f;
u32 var8006ec84 = 0x01000000;
u32 var8006ec88 = 0x44098000;
u32 var8006ec8c = 0x44098000;
u32 var8006ec90 = 0x00000000;
u32 var8006ec94 = 0x00000000;
u32 var8006ec98 = 0x00000000;

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
struct weapon invitem_ar53 = {
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

u32 var8006ed14 = (u32) &invmenupos_00011098;
u32 var8006ed18 = 0x00000000;
u32 var8006ed1c = 0x3fe66666;
u32 var8006ed20 = 0x40c00000;
u32 var8006ed24 = 0x04080003;
u32 var8006ed28 = 0x40600000;
u32 var8006ed2c = 0x40000000;
u32 var8006ed30 = 0x00000000;
u32 var8006ed34 = 0x40800000;
u32 var8006ed38 = 0x02008070;
u32 var8006ed3c = 0x01000000;
u32 var8006ed40 = 0x44160000;
u32 var8006ed44 = 0x44160000;
u32 var8006ed48 = 0x00000000;
u32 var8006ed4c = 0x00000000;
u32 var8006ed50 = 0x00000000;

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
struct weapon invitem_rcp45 = {
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

u32 var8006edcc = 0x0000001e;
u32 var8006edd0 = 0x00000002;
u32 var8006edd4 = 0x00010000;
u32 var8006edd8 = 0x00000000;
u32 var8006eddc = 0x00000000;

// 14e00
struct weapon invitem_briefcase2 = {
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

u32 var8006ee44 = (u32) &invmenupos_00011098;
u32 var8006ee48 = 0x00000000;
u32 var8006ee4c = 0x3f800000;
u32 var8006ee50 = 0x40c00000;
u32 var8006ee54 = 0x06120208;
u32 var8006ee58 = 0x40a00000;
u32 var8006ee5c = 0x40000000;
u32 var8006ee60 = 0x00000000;
u32 var8006ee64 = 0x40800000;
u32 var8006ee68 = 0x04008059;
u32 var8006ee6c = 0x02000000;
u32 var8006ee70 = 0x44610000;
u32 var8006ee74 = 0x44610000;
u32 var8006ee78 = 0x00000000;
u32 var8006ee7c = 0x00000000;
u32 var8006ee80 = 0x00000000;

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
struct weapon invitem_59 = {
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

u32 var8006eefc = (u32) &invmenupos_00011098;
u32 var8006ef00 = 0x00000000;
u32 var8006ef04 = 0x3f800000;
u32 var8006ef08 = 0x40c00000;
u32 var8006ef0c = 0x06120208;
u32 var8006ef10 = 0x40a00000;
u32 var8006ef14 = 0x40000000;
u32 var8006ef18 = 0x00000000;
u32 var8006ef1c = 0x40800000;
u32 var8006ef20 = 0x0400803f;
u32 var8006ef24 = 0x01000000;
u32 var8006ef28 = 0x44610000;
u32 var8006ef2c = 0x44610000;
u32 var8006ef30 = 0x00000000;
u32 var8006ef34 = 0x00000000;
u32 var8006ef38 = 0x00000000;

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
struct weapon invitem_5a = {
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

u32 var8006f05c = 0x0a00041c;
u32 var8006f060 = 0x00002710;
u32 var8006f064 = 0x04000016;
u32 var8006f068 = 0x00000001;
u32 var8006f06c = 0x00000000;
u32 var8006f070 = 0x00000000;

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

u32 var8006f0a0 = 0x40000000;
u32 var8006f0a4 = 0x428c0000;
u32 var8006f0a8 = 0x00000069;
u32 var8006f0ac = 0x00000069;
u32 var8006f0b0 = 0x00000069;
u32 var8006f0b4 = 0x41300000;
u32 var8006f0b8 = 0xc1cc0000;
u32 var8006f0bc = 0x41300000;
u32 var8006f0c0 = 0xc1cc0000;
u32 var8006f0c4 = 0xbf800000;
u32 var8006f0c8 = 0xbf800000;
u32 var8006f0cc = 0x40000000;
u32 var8006f0d0 = 0x40000000;
u32 var8006f0d4 = 0x00000000;

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

u32 var8006f0ec = 0x0000010f;
u32 var8006f0f0 = 0x00f00000;
u32 var8006f0f4 = 0x0000003c;
u32 var8006f0f8 = 0x3f800000;

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
struct weapon invitem_combatknife = {
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

u32 var8006f174 = 0x00000012;
u32 var8006f178 = 0x00f00000;
u32 var8006f17c = 0x0000003c;
u32 var8006f180 = 0x00000000;

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

u32 var8006f198 = 0x000001b1;
u32 var8006f19c = 0x00f00000;
u32 var8006f1a0 = 0x0000003c;
u32 var8006f1a4 = 0x00000000;

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
struct weapon invitem_commsrider = {
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
struct weapon invitem_tracerbug = {
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
struct weapon invitem_targetamplifier = {
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

u32 var8006f2c0 = 0x00000001;

// 152e4
struct weapon invitem_nightvision = {
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
struct weapon invitem_horizonscanner = {
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

u32 var8006f3ac = 0x00000040;

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
struct weapon invitem_cloakingdevice = {
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

u32 var8006f428 = 0x00000006;
u32 var8006f42c = 0x0000001e;
u32 var8006f430 = 0x05c90000;

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

u32 var8006f448 = 0x00000007;
u32 var8006f44c = 0x0000001e;
u32 var8006f450 = 0x05c90000;

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
struct weapon invitem_combatboost = {
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

u32 var8006f4cc = 0x00000020;

// 154f0
struct weapon invitem_suicidepill = {
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

u32 var8006f534 = 0x00000008;

// 15558
struct weapon invitem_irscanner = {
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
struct weapon invitem_disguise40 = {
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
struct weapon invitem_disguise41 = {
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

u32 var8006f650 = 0x00000004;

// 15674
struct weapon invitem_camspy = {
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

u32 var8006f6b8 = 0x00000010;

// 156dc
struct weapon invitem_rtracker = {
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

u32 var8006f720 = 0x00000002;

// 15744
struct weapon invitem_xrayscanner = {
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

u32 var8006f794 = 0x0a00043b;
u32 var8006f798 = 0x00002710;
u32 var8006f79c = 0x00000000;
u32 var8006f7a0 = 0x00000000;

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

u32 var8006f7b8 = 0x0000000c;
u32 var8006f7bc = 0x0000001e;
u32 var8006f7c0 = 0x00000000;

// 157e4
struct weapon invitem_datauplink = {
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
struct weapon invitem_doordecoder = {
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
struct weapon invitem_rocket = {
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
struct weapon invitem_homingrocket = {
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
struct weapon invitem_grenaderound = {
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
struct weapon invitem_bolt = {
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

u32 var8006f9a4 = 0x00000004;
u32 var8006f9a8 = 0x4c9000ff;
u32 var8006f9ac = (u32) &invmenupos_00010fd0;
u32 var8006f9b0 = 0x00000000;
u32 var8006f9b4 = 0x00102000;
u32 var8006f9b8 = 0x0000000c;
u32 var8006f9bc = 0x0000001e;
u32 var8006f9c0 = 0x00000000;

// 159e4
struct weapon invitem_skedarbomb = {
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
struct weapon invitem_explosives = {
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

u32 var8006fa78 = 0x00000010;

// 15a9c
struct weapon invitem_presidentscanner = {
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
struct weapon invitem_autosurgeon = {
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
struct weapon invitem_flightplans = {
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
struct weapon invitem_researchtape = {
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
struct weapon invitem_backupdisk = {
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
struct weapon invitem_briefcase = {
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
struct weapon invitem_suitcase = {
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
struct weapon invitem_necklace = {
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
struct weapon invitem_shield = {
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
struct weapon invitem_keycard = {
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

u32 var8006fdb0 = 0x00000000;
u32 var8006fdb4 = 0x00000000;
u32 var8006fdb8 = 0x3f800000;
u32 var8006fdbc = 0x40c00000;
u32 var8006fdc0 = 0x030c0f00;
u32 var8006fdc4 = 0x40400000;
u32 var8006fdc8 = 0x40000000;
u32 var8006fdcc = 0x00000000;
u32 var8006fdd0 = 0x40800000;
u32 var8006fdd4 = 0x04008053;
u32 var8006fdd8 = 0x01000000;
u32 var8006fddc = 0x0000011f;
u32 var8006fde0 = 0x00000000;
u32 var8006fde4 = 0x40066666;
u32 var8006fde8 = 0x00000014;
u32 var8006fdec = 0x00000000;
u32 var8006fdf0 = 0x00000000;
u32 var8006fdf4 = 0xffffffff;
u32 var8006fdf8 = 0x3d4ccccd;
u32 var8006fdfc = 0x80530000;

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
struct weapon invitem_rocketlauncher_34 = {
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

u32 var8006fe88 = (u32) &invmenupos_00011070;
u32 var8006fe8c = 0x10000000;
u32 var8006fe90 = 0x3f800000;
u32 var8006fe94 = 0x40c00000;
u32 var8006fe98 = 0x04080300;
u32 var8006fe9c = 0x00000000;
u32 var8006fea0 = 0x00000000;
u32 var8006fea4 = 0x426fffff;
u32 var8006fea8 = 0x00000000;
u32 var8006feac = 0x0000804d;
u32 var8006feb0 = 0x01000000;

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
struct weapon invitem_tester = {
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
