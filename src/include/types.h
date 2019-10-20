#ifndef _IN_TYPES_H
#define _IN_TYPES_H
#include <ultra64.h>
#include "constants.h"

#define bool u32

struct coord {
	float x;
	float y;
	float z;
};

struct position {
	u8 unk00;
	u8 flags;
	u16 unk02;
	u32 unk04;
	struct coord coord;
	u32 unk14;
	u32 unk18;
	u32 unk1c;
	u32 unk20;
	u32 unk24;
	s16 room;
};

struct bitfielddata {
	u8 unk32e;
	u8 specialdie;
	u16 roomtosearch;
};

struct chrdata {
	/*0x000*/ s16 chrnum;
	/*0x002*/ s8 accuracyrating;
	/*0x003*/ s8 speedrating;
	/*0x004*/ u16 firecount;
	/*0x006*/ u8 headnum;
	/*0x007*/ s8 actiontype;
	/*0x008*/ u8 sleep;
	/*0x009*/ u8 invalidmove;
	/*0x00a*/ u8 numclosearghs;
	/*0x00b*/ u8 numarghs;
	/*0x00c*/ u8 fadealpha;
	/*0x00d*/ s8 arghrating;
	/*0x00e*/ u8 aimendcount;
	/*0x00f*/ u8 grenadeprob;
	/*0x010*/ u16 bodynum;
	/*0x012*/ u8 flinchcnt;
	/*0x013*/ u8 path;
	/*0x014*/ u32 hidden;
	/*0x018*/ u32 chrflags;
	/*0x01c*/ struct position *pos;
	/*0x020*/ void *unk020;
	/*0x024*/ u32 chrwidth;
	/*0x028*/ u32 chrheight;
	/*0x02c*/ u32 unk02c;
	/*0x030*/ u32 unk030;
	/*0x034*/ u32 unk034;
	/*0x038*/ u32 unk038;
	/*0x03c*/ u32 unk03c;
	/*0x040*/ u32 unk040;
	/*0x044*/ u32 unk044;
	/*0x048*/ u32 unk048;
	/*0x04c*/ u32 unk04c;
	/*0x050*/ u32 unk050;
	/*0x054*/ u32 unk054;
	/*0x058*/ void *unk058;
	/*0x05c*/ u32 unk05c;
	/*0x060*/ u32 unk060;
	/*0x064*/ u8 unk064;
	/*0x066*/ u8 unk065;
	/*0x066*/ u8 unk066;
	/*0x067*/ u8 unk067;
	/*0x068*/ u32 unk068;
	/*0x06c*/ u32 unk06c;
	/*0x070*/ u32 unk070;
	/*0x074*/ u32 unk074;
	/*0x078*/ u32 unk078;
	/*0x07c*/ u32 unk07c;
	/*0x080*/ u32 unk080;
	/*0x084*/ u32 unk084;
	/*0x088*/ u32 unk088;
	/*0x08c*/ u32 unk08c;
	/*0x090*/ u32 unk090;
	/*0x094*/ u32 unk094;
	/*0x098*/ u32 unk098;
	/*0x09c*/ u32 unk09c;
	/*0x0a0*/ u32 unk0a0;
	/*0x0a4*/ u32 unk0a4;
	/*0x0a8*/ u32 unk0a8;
	/*0x0ac*/ u32 unk0ac;
	/*0x0b0*/ u32 sumground;
	/*0x0b4*/ u32 manground;
	/*0x0b8*/ u32 ground;
	/*0x0bc*/ struct coord fallspeed;
	/*0x0c8*/ struct coord prevpos;
	/*0x0d4*/ u32 lastwalk60;
	/*0x0d8*/ u32 lastmoveok60;
	/*0x0dc*/ float visionrange;
	/*0x0e0*/ u32 lastseetarget60;
	/*0x0e4*/ u32 lastvisibletarg;
	/*0x0e8*/ void *unk0e8;
	/*0x0ec*/ u16 lastshooter;
	/*0x0ee*/ u16 timeshooter;
	/*0x0f0*/ float hearingscale;
	/*0x0f4*/ u32 lastheartarget60;
	/*0x0f8*/ u32 shadecol;
	/*0x0fc*/ u32 nextcol;
	/*0x100*/ float damage;
	/*0x104*/ float maxdamage;
	/*0x108*/ u8 *ailist;
	/*0x10c*/ u16 aioffset;
	/*0x10e*/ u16 aireturnlist;
	/*0x110*/ u16 aishotlist;
	/*0x112*/ u8 morale;
	/*0x113*/ u8 alertness;
	/*0x114*/ u32 flags;
	/*0x118*/ u32 flags2;
	/*0x11c*/ u32 timer60;
	/*0x120*/ u32 soundtimer;
	/*0x124*/ u8 random;
	/*0x125*/ u8 team;
	/*0x126*/ u8 soundgap;
	/*0x128*/ s16 padpreset1;
	/*0x12a*/ s16 chrpreset1;
	/*0x12c*/ s16 proppreset1;
	/*0x12e*/ s16 chrseeshot;
	/*0x130*/ s16 chrseedie;
	/*0x132*/ s16 chrdup;
	/*0x134*/ u32 unk134;
	/*0x138*/ u32 unk138;
	/*0x13c*/ u32 unk13c;
	/*0x140*/ u32 unk140;
	/*0x144*/ u32 unk144;
	/*0x148*/ u32 unk148;
	/*0x14c*/ u32 shotbondsum;
	/*0x150*/ u32 aimuplshoulder;
	/*0x154*/ u32 aimuprshoulder;
	/*0x158*/ u32 aimupback;
	/*0x15c*/ u32 aimsideback;
	/*0x160*/ u32 aimendlshoulder;
	/*0x164*/ u32 aimendrshoulder;
	/*0x168*/ u32 aimendback;
	/*0x16c*/ u32 aimendsideback;
	/*0x170*/ u32 unk170;
	/*0x174*/ u32 unk174;
	/*0x178*/ u32 unk178;
	/*0x17c*/ u16 fireslot;
	/*0x17e*/ s16 target;
	/*0x180*/ u32 cshield;
	/*0x184*/ u8 cmnum;
	/*0x185*/ u8 cmnum2;
	/*0x186*/ u8 cmnum3;
	/*0x187*/ u8 cmnum4;
	/*0x188*/ u16 cmcount;
	/*0x18a*/ u16 floorcol;
	/*0x18c*/ u32 oldframe;
	/*0x190*/ u8 footstep;
	/*0x191*/ u8 floortype;
	/*0x192*/ u16 hidden2;
	/*0x194*/ u32 magicframe;
	/*0x198*/ u32 magicspeed;
	/*0x19c*/ u16 magicanim;
	/*0x19e*/ u16 goposforce;
	/*0x1a0*/ u8 bdlist[240];
	/*0x290*/ u8 bdstart;
	/*0x291*/ u8 goposhitcount;
	/*0x292*/ u16 cover;
	/*0x294*/ struct coord targetlastseenp;
	/*0x2a0*/ u8 myaction;
	/*0x2a1*/ u8 orders;
	/*0x2a2*/ u8 squadron;
	/*0x2a3*/ u8 listening;
	/*0x2a4*/ u32 convtalk;
	/*0x2a8*/ u32 talktimer;
	/*0x2ac*/ u8 question;
	/*0x2ad*/ u8 talkgap;
	/*0x2ae*/ u16 unk2ae;
	/*0x2b0*/ u8 tude;
	/*0x2b1*/ u8 voicebox;
	/*0x2b2*/ u16 floorroom;
	/*0x2b4*/ u32 unk2b4;
	/*0x2b8*/ u16 oldrooms[8];
	/*0x2c8*/ struct coord runfrompos;
	/*0x2d4*/ u32 unk2d4;
	/*0x2d8*/ u16 blurdrugamount;
	/*0x2da*/ u16 cloakpause;
	/*0x2dc*/ u32 drugheadsway;
	/*0x2e0*/ u8 drugheadcount;
	/*0x2e1*/ u8 cloakfade;
	/*0x2e2*/ u8 teamscandist;
	/*0x2e3*/ u8 naturalanim;
	/*0x2e4*/ u32 myspecial;
	/*0x2e8*/ u32 timeextra;
	/*0x2ec*/ u32 elapseextra;
	/*0x2f0*/ struct coord extraspeed;
	/*0x2fc*/ u8 yvisang;
	/*0x2fd*/ u8 ivebeenhit;
	/*0x2fe*/ u8 race;
	/*0x2ff*/ u8 blurnumtimesdied;
	/*0x300*/ struct position *gungroundpos;
	/*0x304*/ u32 pushspeed[2];
	/*0x30c*/ u32 gunroty[2];
	/*0x314*/ u32 gunrotx[2];
	/*0x31c*/ u32 onladder;
	/*0x320*/ struct coord laddernormal;
	/*0x32c*/ u8 liftaction;

	union {
	/*0x32e*/ u16 BITFIELD;
	/*0x32e*/ struct bitfielddata bitfielddata;
		/* 0x32e - u8 unk32e;
		 * 0x32f - u8 specialdie;
		 * 0x330 - u16 roomtosearch;
		 */
	};

	/*0x332*/ u8 propsoundcount;
	/*0x333*/ u8 patrolnextstep;
	/*0x334*/ u8 BulletsTaken;
	/*0x335*/ u8 WoundedSplatsAd;
	/*0x336*/ u16 TicksSinceSplat;
	/*0x338*/ u8 SplatsDroppedHe;
	/*0x339*/ u8 StdSplatsAdded;
	/*0x33a*/ u8 DeadDropSplatsA;
	/*0x33b*/ u8 aimtesttimer60;
	/*0x33c*/ struct coord LastDropPos;
	/*0x348*/ u32 unk348;
	/*0x34c*/ u32 unk34c;
	/*0x350*/ u32 unk350;
	/*0x354*/ u16 aipunchdodgelist;
	/*0x356*/ u16 aishootingatmelist;
	/*0x358*/ u16 poisonCounter;
	/*0x35a*/ u16 aidarkroomlist;
	/*0x35c*/ u16 aiplayerdeadlist;
	/*0x35e*/ u8 dodgerating;
	/*0x35f*/ u8 maxdodgerating;
	/*0x360*/ u8 unarmeddodgerating;
	/*0x361*/ u8 lastfootsample;
	/*0x362*/ u8 onlift;
	/*0x364*/ u32 unk364;
	/*0x368*/ u32 m_SoundEndTime;
};

struct defaultobj {
	/*0x00*/ u16 extrascale;
	/*0x02*/ u8 hidden2;
	/*0x03*/ u8 type;
	/*0x04*/ u16 obj;
	/*0x06*/ u16 pad;
	/*0x08*/ u32 flags;
	/*0x0c*/ u32 flags2;
	/*0x10*/ u32 flags3;
	/*0x14*/ struct position *pos;
	/*0x18*/ void *unk18; // probably same struct as chrdata->unk020
	/*0x1c*/ float realrot[9];
	/*0x40*/ u32 hidden;
	/*0x44*/ u32 unk44;
	/*0x48*/ u32 unk48;
	/*0x4c*/ s16 damage;
	/*0x4e*/ u16 maxdamage;
	/*0x50*/ u32 shadecol;
	/*0x54*/ u32 nextcol;
	/*0x58*/ u16 floorcol;
	/*0x5a*/ u8 numtiles;
};

struct doorobj { // objtype 0x01
	struct defaultobj base;
	/*0x5c*/ float unk5c;
	/*0x60*/ u32 unk60;
	/*0x64*/ u32 unk64;
	/*0x68*/ u32 unk68;
	/*0x6c*/ u32 unk6c;
	/*0x70*/ u32 unk70;
	/*0x74*/ u32 unk74;
	/*0x78*/ u32 unk78;
	/*0x7c*/ float speed;
	/*0x80*/ float unk80;
	/*0x84*/ s8 state;
	/*0x88*/ u32 unk88;
	/*0x8c*/ u32 unk8c;
	/*0x90*/ u32 unk90;
	/*0x94*/ u32 unk94;
	/*0x98*/ u32 unk98;
	/*0x9c*/ u32 unk9c;
	/*0xa0*/ u32 unka0;
	/*0xa4*/ u32 unka4;
	/*0xa8*/ u32 unka8;
	/*0xac*/ u32 unkac;
	/*0xb0*/ u32 unkb0;
	/*0xb4*/ u32 unkb4;
	/*0xb8*/ u32 unkb8;
	/*0xbc*/ u32 unkbc;
	/*0xc0*/ u32 unkc0;
};

struct standardobj { // objtype 0x03
	struct defaultobj base;
	/*0x5c*/ u8 *ailist;
	/*0x60*/ u16 aioffset;
	/*0x62*/ u16 aireturnlist;
};

struct image {
	/*0x00*/ u32 unk00;
	/*0x04*/ u32 unk04;
	/*0x08*/ u32 unk08;
	/*0x0c*/ u32 unk0c;
	/*0x10*/ u32 unk10;
	/*0x14*/ u32 unk14;
};

struct weaponobj { // objtype 0x08
	/*0x00*/ u16 extrascale;
	/*0x02*/ u8 hidden2;
	/*0x03*/ u8 type;
	/*0x04*/ u16 obj;
	/*0x06*/ u16 pad;
	/*0x08*/ u32 flags;
	/*0x0c*/ u32 flags2;
	/*0x10*/ u32 flags3;
	/*0x14*/ struct position *pos;
	/*0x18*/ u32 unk18;
	/*0x1c*/ float realrot[9];
	/*0x40*/ u32 hidden;
	/*0x44*/ u32 unk44;
	/*0x48*/ u32 unk48;
	/*0x4c*/ s16 damage;
	/*0x4e*/ u16 maxdamage;
	/*0x50*/ u32 shadecol;
	/*0x54*/ u32 nextcol;
	/*0x58*/ u16 floorcol;
	/*0x5a*/ u8 numtiles;
	/*0x5b*/ u8 unk5b;
	/*0x5c*/ u8 weapon_id;
};

struct singlemonitorobj { // objtype 0x0a
	/*0x00*/ u16 extrascale;
	/*0x02*/ u8 hidden2;
	/*0x03*/ u8 type;
	/*0x04*/ u16 obj;
	/*0x06*/ u16 pad;
	/*0x08*/ u32 flags;
	/*0x0c*/ u32 flags2;
	/*0x10*/ u32 flags3;
	/*0x14*/ struct position *pos;
	/*0x18*/ u32 unk18;
	/*0x1c*/ float realrot[9];
	/*0x40*/ u32 hidden;
	/*0x44*/ u32 unk44;
	/*0x48*/ u32 unk48;
	/*0x4c*/ s16 damage;
	/*0x4e*/ u16 maxdamage;
	/*0x50*/ u32 shadecol;
	/*0x54*/ u32 nextcol;
	/*0x58*/ u16 floorcol;
	/*0x5a*/ u8 numtiles;
	/*0x5c*/ struct image image;
};

struct multimonitorobj { // objtype 0b
	struct singlemonitorobj subobjs[4];
};

struct tag {
	// These three words are possibly the same values as defined in the setup
	// file, but this just a guess.
	u32 unk00;
	u16 unk04;
	s16 unk06;
	u32 unk08;
	struct defaultobj *obj;
};

struct otheraidata {
	/*0x00*/ u32 unk00;
	/*0x04*/ u16 unk04;
	/*0x06*/ u16 padpreset1;
	/*0x08*/ u32 unk08;
	/*0x0c*/ u32 unk0c;
	/*0x10*/ u32 unk10;
	/*0x14*/ u32 unk14;
	/*0x18*/ u32 unk18;
	/*0x1c*/ u32 unk1c;
	/*0x20*/ u32 unk20;
	/*0x24*/ u32 unk24;
	/*0x28*/ u32 unk28;
	/*0x2c*/ u32 unk2c;
	/*0x30*/ u32 unk30;
	/*0x34*/ u32 unk34;
	/*0x38*/ u32 unk38;
	/*0x3c*/ u32 unk3c;
	/*0x40*/ u32 unk40;
	/*0x44*/ u32 unk44;
	/*0x48*/ u32 unk48;
	/*0x4c*/ u32 unk4c;
	/*0x50*/ u32 unk50;
	/*0x54*/ u32 unk54;
	/*0x58*/ u32 unk58;
	/*0x5c*/ u8 *ailist;
	/*0x60*/ u16 aioffset;
	/*0x62*/ u16 aireturnlist;
};

struct playerbc {
	u32 unk00;
	struct chrdata *chr;
};

struct player {
	/*0x00*/ u32 unk00;
	/*0x04*/ u32 unk04;
	/*0x08*/ u32 unk08;
	/*0x0c*/ u32 unk0c;
	/*0x10*/ u32 unk10;
	/*0x14*/ u32 unk14;
	/*0x18*/ u32 unk18;
	/*0x1c*/ u32 unk1c;
	/*0x20*/ u32 unk20;
	/*0x24*/ u32 unk24;
	/*0x28*/ u32 unk28;
	/*0x2c*/ u32 unk2c;
	/*0x30*/ u32 unk30;
	/*0x34*/ u32 unk34;
	/*0x38*/ u32 unk38;
	/*0x3c*/ u32 unk3c;
	/*0x40*/ u32 unk40;
	/*0x44*/ u32 unk44;
	/*0x48*/ u32 unk48;
	/*0x4c*/ u32 unk4c;
	/*0x50*/ u32 unk50;
	/*0x54*/ u32 unk54;
	/*0x58*/ u32 unk58;
	/*0x5c*/ u32 unk5c;
	/*0x60*/ u32 unk60;
	/*0x64*/ u32 unk64;
	/*0x68*/ u32 unk68;
	/*0x6c*/ u32 unk6c;
	/*0x70*/ u32 unk70;
	/*0x74*/ u32 unk74;
	/*0x78*/ u32 unk78;
	/*0x7c*/ u32 unk7c;
	/*0x80*/ u32 unk80;
	/*0x84*/ u32 unk84;
	/*0x88*/ u32 unk88;
	/*0x8c*/ u32 unk8c;
	/*0x90*/ u32 unk90;
	/*0x94*/ u32 unk94;
	/*0x98*/ u32 unk98;
	/*0x9c*/ u32 unk9c;
	/*0xa0*/ u32 unka0;
	/*0xa4*/ u32 unka4;
	/*0xa8*/ u32 unka8;
	/*0xac*/ u32 unkac;
	/*0xb0*/ u32 unkb0;
	/*0xb4*/ u32 unkb4;
	/*0xb8*/ u32 unkb8;
	/*0xbc*/ struct playerbc *unkbc;
	/*0xc0*/ u32 unkc0;
	/*0xc4*/ u32 unkc4;
	/*0xc8*/ u32 unkc8;
	/*0xcc*/ u32 unkcc;
	/*0xd0*/ u32 unkd0;
	/*0xd4*/ u32 unkd4;
	/*0xd8*/ u32 unkd8;
};

struct targetsomething {
	/*0x00*/ u8 unk00;
	/*0x04*/ struct chrdata *chr;
	/*0x08*/ u32 unk08;
	/*0x0c*/ u32 unk0c;
	/*0x10*/ u32 unk10;
	/*0x14*/ u32 unk14;
	/*0x18*/ u32 unk18;
	/*0x1c*/ u32 unk1c;
	/*0x20*/ u32 unk20;
	/*0x24*/ u32 unk24;
	/*0x28*/ u32 unk28;
	/*0x2c*/ u32 unk2c;
	/*0x30*/ u32 unk30;
	/*0x34*/ u32 unk34;
	/*0x38*/ u32 unk38;
	/*0x3c*/ u32 unk3c;
	/*0x40*/ u32 unk40;
	/*0x44*/ u32 unk44;
};

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

#define MENUITEMTYPE_LABEL       0x01
#define MENUITEMTYPE_CUSTOM      0x02
#define MENUITEMTYPE_SELECTABLE  0x04
#define MENUITEMTYPE_SCROLLABLE  0x05
#define MENUITEMTYPE_OBJECTIVES  0x06
#define MENUITEMTYPE_SLIDER      0x08
#define MENUITEMTYPE_CHECKBOX    0x09
#define MENUITEMTYPE_SEPARATOR   0x0b
#define MENUITEMTYPE_DROPDOWN    0x0c
#define MENUITEMTYPE_KEYBOARD    0x0d
#define MENUITEMTYPE_RANKING     0x0e
#define MENUITEMTYPE_PLAYERSTATS 0x0f
#define MENUITEMTYPE_CAROUSEL    0x11
#define MENUITEMTYPE_MODEL       0x12
#define MENUITEMTYPE_MARQUEE     0x17
#define MENUITEMTYPE_CONTROLLER  0x19
#define MENUITEMTYPE_END         0x1a

struct menu_item {
	u8 type;
	u8 param;
	u32 flags;
	u32 left;
	u32 right;
	u32 (*handler)(u32, u32, u32);
};

#define MENUDIALOGTYPE_DEFAULT 0x01
#define MENUDIALOGTYPE_DANGER  0x02
#define MENUDIALOGTYPE_SUCCESS 0x03

struct menu_dialog {
	u8 type;
	u32 title;
	struct menu_item *items;
	void (*unk0c)(void);
	u32 unk10;
	struct menu_dialog *nextsibling;
};

struct stagethinglist {
	u16 stage;
	u16 numthings;
	u16 *things;
};

struct twowords {
	u32 unk00;
	u32 unk04;
};

struct something {
	u32 *unk00;
	u32 *unk04;
	u32 unk08;
};

struct audiodefinition {
	u16 unk00;
	u16 audioconfig_index;
};

struct audioconfig {
	u32 flags; // 0x10 = contains swearing
	float unk04;
	float unk08;
	float unk0c;
	float unk10;
	u32 unk14;
	s32 unk18;
	u32 unk1c;
};

struct gvars284 {
	u32 unk000;
	u32 unk004;
	u32 unk008;
	u32 unk00c;
	u32 unk010;
	u32 unk014;
	u32 unk018;
	u32 unk01c;
	u32 unk020;
	u32 unk024;
	u32 unk028;
	u32 unk02c;
	u32 unk030;
	u32 unk034;
	u32 unk038;
	u32 unk03c;
	u32 unk040;
	u32 unk044;
	u32 unk048;
	u32 unk04c;
	u32 unk050;
	u32 unk054;
	u32 unk058;
	u32 unk05c;
	u32 unk060;
	u32 unk064;
	u32 unk068;
	u32 unk06c;
	u32 unk070;
	u32 unk074;
	u32 unk078;
	u32 unk07c;
	u32 unk080;
	u32 unk084;
	u32 unk088;
	u32 unk08c;
	u32 unk090;
	u32 unk094;
	u32 unk098;
	u32 unk09c;
	u32 unk0a0;
	u32 unk0a4;
	u32 unk0a8;
	u32 unk0ac;
	u32 unk0b0;
	u32 unk0b4;
	u32 unk0b8;
	u32 unk0bc;
	u32 unk0c0;
	u32 unk0c4;
	u32 unk0c8;
	u32 unk0cc;
	u32 unk0d0;
	u32 unk0d4;
	u32 unk0d8;
	u32 unk0dc;
	u32 unk0e0;
	u32 unk0e4;
	u32 unk0e8;
	u32 unk0ec;
	u32 unk0f0;
	u32 unk0f4;
	u32 unk0f8;
	u32 unk0fc;
	u32 unk100;
	u32 unk104;
	u32 unk108;
	u32 unk10c;
	u32 unk110;
	u32 unk114;
	u32 unk118;
	u32 unk11c;
	u32 unk120;
	u32 unk124;
	u32 unk128;
	u32 unk12c;
	u32 unk130;
	u32 unk134;
	u32 unk138;
	u32 unk13c;
	u32 unk140;
	u32 unk144;
	u32 unk148;
	u32 unk14c;
	u32 unk150;
	u32 unk154;
	u32 unk158;
	u32 unk15c;
	u32 unk160;
	u32 unk164;
	u32 unk168;
	u32 unk16c;
	u32 unk170;
	u32 unk174;
	u32 unk178;
	u32 unk17c;
	u32 unk180;
	u32 unk184;
	u32 unk188;
	u32 unk18c;
	u32 unk190;
	u32 unk194;
	u32 unk198;
	u32 unk19c;
	u32 unk1a0;
	u32 unk1a4;
	u32 unk1a8;
	u32 unk1ac;
	u32 unk1b0;
	u32 unk1b4;
	u32 unk1b8;
	u32 unk1bc;
	u32 unk1c0;
	u32 unk1c4;
	u32 unk1c8;
	u32 unk1cc;
	u32 unk1d0;
	u32 unk1d4;
	u32 unk1d8;
	u32 unk1dc;
	u32 unk1e0;
	u32 unk1e4;
	u32 unk1e8;
	u32 unk1ec;
	u32 unk1f0;
	u32 unk1f4;
	u32 unk1f8;
	u32 unk1fc;
	u32 unk200;
	u32 unk204;
	u32 unk208;
	u32 unk20c;
	u32 unk210;
	u32 unk214;
	u32 unk218;
	u32 unk21c;
	u32 unk220;
	u32 unk224;
	u32 unk228;
	u32 unk22c;
	u32 unk230;
	u32 unk234;
	u32 unk238;
	u32 unk23c;
	u32 unk240;
	u32 unk244;
	u32 unk248;
	u32 unk24c;
	u32 unk250;
	u32 unk254;
	u32 unk258;
	u32 unk25c;
	u32 unk260;
	u32 unk264;
	u32 unk268;
	u32 unk26c;
	u32 unk270;
	u32 unk274;
	u32 unk278;
	u32 unk27c;
	u32 unk280;
	u32 unk284;
	u32 unk288;
	u32 unk28c;
	u32 unk290;
	u32 unk294;
	u32 unk298;
	u32 unk29c;
	u32 unk2a0;
	u32 unk2a4;
	u32 unk2a8;
	u32 unk2ac;
	u32 unk2b0;
	u32 unk2b4;
	u32 unk2b8;
	u32 unk2bc;
	u32 unk2c0;
	u32 unk2c4;
	u32 unk2c8;
	u32 unk2cc;
	u32 unk2d0;
	u32 unk2d4;
	u32 unk2d8;
	u32 unk2dc;
	u32 unk2e0;
	u32 unk2e4;
	u32 unk2e8;
	u32 unk2ec;
	u32 unk2f0;
	u32 unk2f4;
	u32 unk2f8;
	u32 unk2fc;
	u32 unk300;
	u32 unk304;
	u32 unk308;
	u32 unk30c;
	u32 unk310;
	u32 unk314;
	u32 unk318;
	u32 unk31c;
	u32 unk320;
	u32 unk324;
	u32 unk328;
	u32 unk32c;
	u32 unk330;
	u32 unk334;
	u32 unk338;
	u32 unk33c;
	u32 unk340;
	u32 unk344;
	u32 unk348;
	u32 unk34c;
	u32 unk350;
	u32 unk354;
	u32 unk358;
	u32 unk35c;
	u32 unk360;
	u32 unk364;
	u32 unk368;
	u32 unk36c;
	u32 unk370;
	u32 unk374;
	u32 unk378;
	u32 unk37c;
	u32 unk380;
	u32 unk384;
	u32 unk388;
	u32 unk38c;
	u32 unk390;
	u32 unk394;
	u32 unk398;
	u32 unk39c;
	u32 unk3a0;
	u32 unk3a4;
	u32 unk3a8;
	u32 unk3ac;
	u32 unk3b0;
	u32 unk3b4;
	u32 unk3b8;
	u32 unk3bc;
	u32 unk3c0;
	u32 unk3c4;
	u32 unk3c8;
	u32 unk3cc;
	u32 unk3d0;
	u32 unk3d4;
	u32 unk3d8;
	u32 unk3dc;
	u32 unk3e0;
	u32 unk3e4;
	u32 unk3e8;
	u32 unk3ec;
	u32 unk3f0;
	u32 unk3f4;
	u32 unk3f8;
	u32 unk3fc;
	u32 unk400;
	u32 unk404;
	u32 unk408;
	u32 unk40c;
	u32 unk410;
	u32 unk414;
	u32 unk418;
	u32 unk41c;
	u32 unk420;
	u32 unk424;
	u32 unk428;
	u32 unk42c;
	u32 unk430;
	u32 unk434;
	u32 unk438;
	u32 unk43c;
	u32 unk440;
	u32 unk444;
	u32 unk448;
	u32 unk44c;
	u32 unk450;
	u32 unk454;
	u32 unk458;
	u32 unk45c;
	u32 unk460;
	u32 unk464;
	u32 unk468;
	u32 unk46c;
	u32 unk470;
	u32 unk474;
	u32 unk478;
	u32 unk47c;
	u32 unk480;
};

#endif
