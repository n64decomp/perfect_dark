#ifndef _IN_TYPES_H
#define _IN_TYPES_H

#include "ultra64.h"
#include "constants.h"

struct ailists {
	u8 *list;
	u32 id;
};

struct aipaths {
	s32 *pads;
	u8 id;
	u8 type;
};

struct inventory_menupos {
	float x;
	float y;
	float z;
	float rotation;
	float size;
};

struct inventory_typee {
	u32 unk00;
	u32 unk04;
	u32 unk08;
	u32 unk0c;
	u32 unk10;
	u32 unk14;
	u32 unk18;
	u32 unk1c;
};

struct inventory_typef {
	u32 unk00;
	u32 unk04;
	u32 unk08;
	u32 unk0c;
	u32 unk10;
};

#define INVENTORYFUNCTYPE_NONE    0
#define INVENTORYFUNCTYPE_SHOOT   1
#define INVENTORYFUNCTYPE_THROW   2
#define INVENTORYFUNCTYPE_CLOSE   3
#define INVENTORYFUNCTYPE_SPECIAL 4
#define INVENTORYFUNCTYPE_VISUAL  5

struct inventory_function {
	u16 unk00;
	u8 unk02;
	u8 type;
	u16 name;
	u8 unk06;
	s8 unk07;
	struct inventory_menupos *menupos;
	u32 *fire_animation;
	u32 flags;
};

struct inventory_ammo {
	u16 unk00;
	u8 unk02;
	u8 type;
	u32 casingeject;
	u16 clipsize;
	u32 *reload_animation;
	u32 style;
};

struct inventory_item {
	u16 lo_model;
	u16 hi_model;
	u32 *equip_animation;
	u32 *unequip_animation;
	u32 *pritosec_animation;
	u32 *sectopri_animation;
	struct inventory_function *pri_function;
	struct inventory_function *sec_function;
	struct inventory_ammo *pri_ammo;
	struct inventory_ammo *sec_ammo;
	struct inventory_typee *eptr;
	float sway;
	float leftright;
	float updown;
	float frontback;
	float unk38;
	struct inventory_typef *fptr;
	s8 *gptr;
	u16 shortname;
	u16 name;
	u16 manufacturer;
	u16 description;
	u32 flags;
};

struct cutsceneentry {
	u16 stage_id;
	u16 mission;
	u32 scene;
	u16 namefileid;
};

struct cutscenegroup {
	u32 first_cutscene_index;
	u16 namefileid;
};

#define CHEATMETHOD_TIMED       0
#define CHEATMETHOD_TRANSFERPAK 2
#define CHEATMETHOD_COMPLETE    4
#define CHEATMETHOD_FIRINGRANGE 8

struct cheatspec {
	u16 nametextid;
	u16 time;
	u8 stage_index;
	u8 difficulty;
	u8 method;
};

struct bodytableentry {
	u16 unk00;
	u16 bodyfileid;
	float unk04;
	float unk08;
	u32 unk0c;
	u16 handfileid;
};

struct stagetableentry {
	u16 id;
	u8 light_type;
	u8 light_alpha;
	u8 light_width;
	u8 light_height;
	u16 unk06;
	u16 bgfileid;
	u16 tilefileid;
	u16 padsfileid;
	u16 setupfileid;
	u16 mpsetupfileid;
	float unk14;
	float unk18;
	float unk1c;
	u16 unk20;
	u8 unk22;
	s8 unk23;
	u32 unk24;
	u32 unk28;
	s16 unk2c;
	u16 unk2e;
	u16 unk30;
	float unk34;
};

struct mpweaponset {
	u16 namefileid;
	u8 slots[16];
};

struct mpheadentry {
	u16 head;
	u8 unlockvalue;
};

#define SIMTYPE_GENERAL 0
#define SIMTYPE_PEACE   1
#define SIMTYPE_SHIELD  2
#define SIMTYPE_ROCKET  3
#define SIMTYPE_KAZE    4
#define SIMTYPE_FIST    5
#define SIMTYPE_PREY    6
#define SIMTYPE_COWARD  7
#define SIMTYPE_JUDGE   8
#define SIMTYPE_FEUD    9
#define SIMTYPE_SPEED   10
#define SIMTYPE_TURTLE  11
#define SIMTYPE_VENGE   12

struct mpsimulant {
	u8 type;
	u8 skill;
	u16 name;
	u16 body;
	u8 unlockvalue;
};

struct mpbody {
	u16 slot;
	u16 name;
	u16 unk04;
	u8 unk06;
};

struct mpmusictrack {
	u8 audioid;
	u8 duration;
	u16 name;
	s16 unlockcategory;
};

struct stageoverviewentry {
	u32 stage_id;
	u8 unk04;
	u16 name1; // "dataDyne Central"
	u16 name2; // " - Defection"
	u16 name3; // "dataDyne Defection"
};

struct stagemusic {
	u16 stage_id;
	s16 main_music;
	s16 sfx_music;
	s16 x_music;
};

struct mission {
	u32 first_stage_index;
	u16 name;
};

struct sun {
	u8 lens_flare;
	u8 red;
	u8 green;
	u8 blue;
	float x;
	float y;
	float z;
	u16 texture_size;
	u16 orb_size;
};

struct smallsky {
	// len 0x2c
	u16 stage;
	u16 blend_multiplier;
	u16 sky_far;
	u16 unk06;
	u16 unk08;
	u16 unk0a;
	u16 unk0c;
	u16 unk0e;
	u8 sky_r;
	u8 sky_g;
	u8 sky_b;
	u8 sky_enabled;
	struct sun *sun;
	u8 clouds_enabled;
	u8 unk19; // pad
	u16 unk1a;
	u8 unk1c;
	u8 clouds_r;
	u8 clouds_g;
	u8 clouds_b;
	u16 unk20;
	u8 unk22;
	u8 unk23;
	u8 water_enabled;
	u8 water_r;
	u8 water_g;
	u8 water_b;
	u8 unk28;
};

struct sky {
	s32 stage;
	u16 blend_multiplier;
	u16 sky_far;
	u32 unk08;
	u16 unk0c;
	u8 sky_r;
	u8 sky_g;
	u8 sky_b;
	u8 num_suns;
	struct sun *sunptr;
	u8 clouds_enabled;
	u8 clouds_r;
	u8 clouds_g;
	u8 clouds_b;
	float clouds_scale;
	u16 unk20;
	u8 water_enabled;
	u8 water_r;
	u8 water_g;
	u8 water_b;
	float water_scale;
	u16 water_type;
	u32 unk30;
	u32 unk34;
};

struct hoverprop {
	u32 fileid;
	s32 y_offset;
	u16 size;
};

#endif
