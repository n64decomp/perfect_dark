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

struct inventory_typec {
	u32 unk00;
	u32 unk04;
	u32 unk08;
	u32 unk0c;
	u32 unk10;
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
	struct inventory_typec *cptr;
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
	u32 unk08;
	u32 unk0c;
	u16 handfileid;
};

struct stagetableentry {
	u16 id;
	u8 unk02; // usually 2, but 8 for Deep Sea
	s8 unk03; // usually -1, but 96 for Deep Sea
	u8 unk04; // usually 100, but 80 for Deep Sea
	u8 unk05; // usually 100, but 200 for Deep Sea
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
	u16 slot;
	u8 head;
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
	u8 unk06;
};

struct mpbody {
	u16 slot;
	u16 name;
	u16 unk04;
	u8 unk06;
};

struct mpmusictrack {
	u16 audioid;
	u16 name;
	s16 unlockcategory;
};

#endif
