#ifndef _IN_CONSTANTS_H
#define _IN_CONSTANTS_H
#include "files.h"
#include "sfx.h"

#define VERSION_NTSC_BETA  0
#define VERSION_NTSC_1_0   1
#define VERSION_NTSC_FINAL 2
#define VERSION_PAL_BETA   3
#define VERSION_PAL_FINAL  4
#define VERSION_JPN_FINAL  5

#define FALSE 0
#define TRUE  1

#define false 0
#define true  1

#define osSyncPrintf

#define S32_MAX  2147483647
#define U32_MAX  4294967295
#define MAXFLOAT ((float)3.40282346638528860e+38)

#define ABS(val)            ((val) > 0 ? (val) : -(val))
#define ALIGN2(val)         (((val) | 1) ^ 0x1)
#define ALIGN8(val)         (((val) + 0x7 | 0x7) ^ 0x7)
#define ALIGN16(val)        (((val) + 0xf | 0xf) ^ 0xf)
#define ALIGN64(val)        ((((u32)val) + 0x3f | 0x3f) ^ 0x3f)
#define ARRAYCOUNT(a)       (s32)(sizeof(a) / sizeof(a[0]))
#define CHRRACE(chr)        (chr ? chr->race : RACE_HUMAN)
#define IS4MB()             (g_Is4Mb == true)
#define IS8MB()             (g_Is4Mb != true)
#define PLAYERCOUNT()       ((g_Vars.players[0] ? 1 : 0) + (g_Vars.players[1] ? 1 : 0) + (g_Vars.players[2] ? 1 : 0) + (g_Vars.players[3] ? 1 : 0))
#define PLAYERCOUNT3012()   ((g_Vars.players[3] ? 1 : 0) + (g_Vars.players[0] ? 1 : 0) + (g_Vars.players[1] ? 1 : 0) + (g_Vars.players[2] ? 1 : 0))
#define SECSTOTIME240(secs) (secs * 240)
#define SECSTOTIME60(secs)  (secs * 60)
#define PFS(device)         (device == SAVEDEVICE_GAMEPAK ? NULL : &g_Pfses[device])

#if VERSION >= VERSION_NTSC_1_0
#define VOLUME(volume)      (volume > 0x5000 ? 0x5000 : volume)
#else
#define VOLUME(volume)      (volume)
#endif

#define EYESPYINACTIVE()    (!g_Vars.currentplayer->eyespy || (g_Vars.currentplayer->eyespy && !g_Vars.currentplayer->eyespy->active))

#define ERASERSQDIST(p) ( \
		(p[0] - g_Vars.currentplayer->eraserpos.f[0]) * (p[0] - g_Vars.currentplayer->eraserpos.f[0]) + \
		(p[1] - g_Vars.currentplayer->eraserpos.f[1]) * (p[1] - g_Vars.currentplayer->eraserpos.f[1]) + \
		(p[2] - g_Vars.currentplayer->eraserpos.f[2]) * (p[2] - g_Vars.currentplayer->eraserpos.f[2]))

#if PAL
#define PALDOWN(val)  ((val) * 50 / 60)
#define PALUP(val)    ((val) * 60 / 50)
#define PALUPF(val)   ((val) * 1.2f)
#define FRAMEDURATION (1 / 50.0f)
#else
#define PALUP(val)    (val)
#define PALDOWN(val)  (val)
#define PALUPF(val)   (val)
#define FRAMEDURATION (1 / 60.0f)
#endif

// Macro to convert an ASCII character to N64 font code.
// N64 font code uses 0x0f for space, 0x10-0x19 for 0-9 and 0x1a-0x33 for A-Z.
#define N64CHAR(c)          (c == ' ' ? 0x0f : (c >= 'A' && c <= 'Z' ? c - 0x27 : c - 0x20))

#if VERSION >= VERSION_NTSC_1_0
#define ROM_COMPANYCODE 0x3459
#else
#define ROM_COMPANYCODE 0x3031
#endif

#if PAL
#define ROM_GAMECODE    'NPDP' // "NPDE" in ASCII
#else
#define ROM_GAMECODE    'NPDE' // "NPDE" in ASCII
#endif

// These actions are assigned to chr->actiontype
#define ACT_INIT             0
#define ACT_STAND            1
#define ACT_KNEEL            2
#define ACT_ANIM             3
#define ACT_DIE              4
#define ACT_DEAD             5
#define ACT_ARGH             6
#define ACT_PREARGH          7
#define ACT_ATTACK           8
#define ACT_ATTACKWALK       9
#define ACT_ATTACKROLL       10
#define ACT_SIDESTEP         11
#define ACT_JUMPOUT          12
#define ACT_RUNPOS           13
#define ACT_PATROL           14
#define ACT_GOPOS            15
#define ACT_SURRENDER        16
#define ACT_LOOKATTARGET     17
#define ACT_SURPRISED        18
#define ACT_STARTALARM       19
#define ACT_THROWGRENADE     20
#define ACT_TURNDIR          21
#define ACT_TEST             22
#define ACT_BONDINTRO        23
#define ACT_BONDDIE          24
#define ACT_BONDMULTI        25
#define ACT_NULL             26
#define ACT_BOT_ATTACKSTAND  27
#define ACT_BOT_ATTACKKNEEL  28
#define ACT_BOT_ATTACKSTRAFE 29
#define ACT_DRUGGEDDROP      30
#define ACT_DRUGGEDKO        31
#define ACT_DRUGGEDCOMINGUP  32
#define ACT_ATTACKAMOUNT     33
#define ACT_ROBOTATTACK      34
#define ACT_SKJUMP           35
#define ACT_PUNCH            36
#define ACT_CUTFIRE          37

#define AIBOTCMD_FOLLOW   0
#define AIBOTCMD_ATTACK   1
#define AIBOTCMD_DEFEND   2
#define AIBOTCMD_HOLD     3
#define AIBOTCMD_NORMAL   4
#define AIBOTCMD_DOWNLOAD 5
#define AIBOTCMD_GETCASE  6
#define AIBOTCMD_TAGBOX   7
#define AIBOTCMD_SAVECASE 8
#define AIBOTCMD_DEFHILL  9
#define AIBOTCMD_HOLDHILL 10
#define AIBOTCMD_GETCASE2 11
#define AIBOTCMD_POPCAP   12
#define AIBOTCMD_PROTECT  13

#define AICMD_END           0x0004
#define AICMD_DROPITEM      0x001c
#define AICMD_SPAWNCHRATPAD 0x00c6
#define AICMD_SPAWNCHRATCHR 0x00c7
#define AICMD_EQUIPWEAPON   0x00c8
#define AICMD_EQUIPHAT      0x00c9

// AI environment commands
#define AIENVCMD_00                   0x00
#define AIENVCMD_01                   0x01
#define AIENVCMD_02                   0x02
#define AIENVCMD_03                   0x03
#define AIENVCMD_04                   0x04
#define AIENVCMD_ROOM_SETAMBIENT      0x05
#define AIENVCMD_ROOM_SETOUTDOORS     0x06
#define AIENVCMD_07                   0x07
#define AIENVCMD_08                   0x08
#define AIENVCMD_SETAMBIENT           0x09
#define AIENVCMD_PLAYNOSEDIVE         0x0a
#define AIENVCMD_0B                   0x0b
#define AIENVCMD_ROOM_SETFAULTYLIGHTS 0x0c
#define AIENVCMD_STOPNOSEDIVE         0x0d
#define AIENVCMD_PLAYUFOHUM           0x0e
#define AIENVCMD_STOPUFOHUM           0x0f

#define AIMCONTROL_HOLD   0
#define AIMCONTROL_TOGGLE 1

#define AMMOTYPE_PISTOL       0x01
#define AMMOTYPE_SMG          0x02
#define AMMOTYPE_CROSSBOW     0x03
#define AMMOTYPE_RIFLE        0x04
#define AMMOTYPE_SHOTGUN      0x05
#define AMMOTYPE_FARSIGHT     0x06
#define AMMOTYPE_GRENADE      0x07
#define AMMOTYPE_ROCKET       0x08
#define AMMOTYPE_KNIFE        0x09
#define AMMOTYPE_MAGNUM       0x0a
#define AMMOTYPE_DEVASTATOR   0x0b
#define AMMOTYPE_REMOTE_MINE  0x0c
#define AMMOTYPE_PROXY_MINE   0x0d
#define AMMOTYPE_TIMED_MINE   0x0e
#define AMMOTYPE_REAPER       0x0f
#define AMMOTYPE_HOMINGROCKET 0x10
#define AMMOTYPE_DART         0x11
#define AMMOTYPE_NBOMB        0x12
#define AMMOTYPE_SEDATIVE     0x13
#define AMMOTYPE_CLOAK        0x14
#define AMMOTYPE_BOOST        0x15
#define AMMOTYPE_PSYCHOSIS    0x16
#define AMMOTYPE_17           0x17
#define AMMOTYPE_BUG          0x18
#define AMMOTYPE_MICROCAMERA  0x19
#define AMMOTYPE_PLASTIQUE    0x1a
#define AMMOTYPE_1B           0x1b
#define AMMOTYPE_1C           0x1c
#define AMMOTYPE_1D           0x1d
#define AMMOTYPE_TOKEN        0x1e
#define AMMOTYPE_1F           0x1f
#define AMMOTYPE_ECM_MINE     0x20

// Active menu slots
#define AMSLOTFLAG_CURRENT 0x02 // black, eg. current equipped weapon
#define AMSLOTFLAG_ACTIVE  0x08 // pulsates slightly, eg. cloak/xray when active
#define AMSLOTFLAG_NOAMMO  0x10 // black BG, no border, orange text

#define AMSLOTMODE_DEFAULT 0
#define AMSLOTMODE_FOCUSED 1
#define AMSLOTMODE_CURRENT 2

// Active menu (weapon wheel) modes
#define AMMODE_CLOSED 0
#define AMMODE_VIEW   1
#define AMMODE_EDIT   2 // unused

#define ANIM_IDLE                   0x0000
#define ANIM_TWO_GUN_HOLD           0x0001
#define ANIM_KNEEL_TWO_HANDED_GUN   0x0008
#define ANIM_DEATH_001A             0x001a
#define ANIM_DEATH_001C             0x001c
#define ANIM_DEATH_0020             0x0020
#define ANIM_DEATH_0021             0x0021
#define ANIM_DEATH_0022             0x0022
#define ANIM_DEATH_0023             0x0023
#define ANIM_DEATH_0024             0x0024
#define ANIM_DEATH_0025             0x0025
#define ANIM_29                     0x0029
#define ANIM_RUNNING_TWOHANDGUN     0x002a
#define ANIM_2B                     0x002b
#define ANIM_SURRENDER_002E         0x002e
#define ANIM_SURRENDER_002F         0x002f
#define ANIM_DEATH_STOMACH_LONG     0x0039
#define ANIM_003C                   0x003c
#define ANIM_TALKING_003D           0x003d
#define ANIM_THROWGRENADE_STANDING  0x003e
#define ANIM_KNEEL_SHOOT_RIGHT_HAND 0x004b
#define ANIM_RUNNING_ONEHANDGUN     0x0059
#define ANIM_TALKING_0098           0x0098
#define ANIM_YAWN                   0x009a
#define ANIM_SCRATCH_HEAD           0x009b
#define ANIM_ROLL_HEAD              0x009c
#define ANIM_GRAB_CROTCH            0x009d
#define ANIM_GRAB_BUTT              0x009e
#define ANIM_SNEEZE                 0x009f
#define ANIM_TALKING_00A0           0x00a0
#define ANIM_TALKING_00A3           0x00a3
#define ANIM_PUSH_BUTTON            0x00ac
#define ANIM_STANDING_TYPE_ONE_HAND 0x00af
#define ANIM_COWER_01F5             0x01f5
#define ANIM_STAND_UP_FROM_SITTING  0x01fa
#define ANIM_SITTING_TYPING         0x01fb
#define ANIM_RELOAD                 0x01ff
#define ANIM_DONT_SHOOT             0x0201
#define ANIM_SURPRISED_0202         0x0202
#define ANIM_OPERATE_0204           0x0204
#define ANIM_OPERATE_0205           0x0205
#define ANIM_OPERATE_0206           0x0206
#define ANIM_SMOKE_CIGARETTE        0x0207
#define ANIM_RELOAD_0209            0x0209
#define ANIM_OPERATE_0221           0x0221
#define ANIM_OPERATE_0222           0x0222
#define ANIM_OPERATE_0223           0x0223
#define ANIM_WALK_BACKWARDS         0x0226
#define ANIM_SITTING_DORMANT        0x0227
#define ANIM_BLINDED                0x0228
#define ANIM_COWER_0229             0x0229
#define ANIM_TALKING_0231           0x0231
#define ANIM_TALKING_0232           0x0232
#define ANIM_TALKING_0233           0x0233
#define ANIM_TALKING_0234           0x0234
#define ANIM_HEAD_ROLL              0x023b
#define ANIM_PICK_UP_GUN            0x023d
#define ANIM_BIG_SNEEZE             0x023f
#define ANIM_THROWGRENADE_NOPIN     0x0242
#define ANIM_THROWGRENADE_CROUCHING 0x0244
#define ANIM_DRAW_PISTOL_0245       0x0245
#define ANIM_LOOK_AROUND_025B       0x025b
#define ANIM_LOOK_AROUND_025C       0x025c
#define ANIM_LOOK_AROUND_025D       0x025d
#define ANIM_LOOK_AROUND_025E       0x025e
#define ANIM_LOOK_AROUND_FRANTIC    0x025f
#define ANIM_SPECIALDIE_FALLBACK    0x0261
#define ANIM_SPECIALDIE_ROLL1       0x0262
#define ANIM_SPECIALDIE_ROLL2       0x0263
#define ANIM_SPECIALDIE_ROLL3       0x0267
#define ANIM_SPECIALDIE_OVERRAILING 0x0268
#define ANIM_SITTING_0265           0x0265
#define ANIM_SNIPING_0269           0x0269
#define ANIM_SNIPING_026A           0x026a
#define ANIM_SNIPING_026B           0x026b
#define ANIM_SNIPING_DIE            0x026c
#define ANIM_DRAW_PISTOL_0288       0x0288
#define ANIM_DRAW_PISTOL_0289       0x0289
#define ANIM_FIX_GUN_JAM_EASY       0x0299
#define ANIM_FIX_GUN_JAM_HARD       0x029a
#define ANIM_SKEDAR_COLLAPSE        0x0352
#define ANIM_SKEDAR_JUMPSTART       0x0384
#define ANIM_SKEDAR_JUMPAIR         0x0385
#define ANIM_SKEDAR_RUNNING         0x0394

#define ANIMFLAG_LOOP 0x01
#define ANIMFLAG_02   0x02

#define AUDIOCHANNELFLAG_IDLE 0x0001
#define AUDIOCHANNELFLAG_0002 0x0002
#define AUDIOCHANNELFLAG_0008 0x0008
#define AUDIOCHANNELFLAG_0010 0x0010
#define AUDIOCHANNELFLAG_0020 0x0020
#define AUDIOCHANNELFLAG_0040 0x0040
#define AUDIOCHANNELFLAG_0080 0x0080
#define AUDIOCHANNELFLAG_0200 0x0200
#define AUDIOCHANNELFLAG_0400 0x0400
#define AUDIOCHANNELFLAG_0800 0x0800
#define AUDIOCHANNELFLAG_1000 0x1000
#define AUDIOCHANNELFLAG_2000 0x2000
#define AUDIOCHANNELFLAG_8000 0x8000

#define AUDIOCHANNELFLAG2_0001 0x0001
#define AUDIOCHANNELFLAG2_0010 0x0010
#define AUDIOCHANNELFLAG2_0020 0x0020
#define AUDIOCHANNELFLAG2_0040 0x0040

#define AUDIOCONFIGFLAG_01 0x01
#define AUDIOCONFIGFLAG_04 0x04
#define AUDIOCONFIGFLAG_08 0x08
#define AUDIOCONFIGFLAG_10 0x10
#define AUDIOCONFIGFLAG_20 0x20
#define AUDIOCONFIGFLAG_40 0x40

#define BANK_0 0
#define BANK_1 1

#define BRIEFINGTYPE_LOCATION 0
#define BRIEFINGTYPE_TEXT_PA  1
#define BRIEFINGTYPE_TEXT_SA  2
#define BRIEFINGTYPE_TEXT_A   3

#define CAMERAMODE_DEFAULT     0
#define CAMERAMODE_THIRDPERSON 1
#define CAMERAMODE_EYESPY      2

#define CASING_NONE     -1
#define CASING_STANDARD 0
#define CASING_REAPER   1
#define CASING_RIFLE    2
#define CASING_SHOTGUN  3

#define CHANNEL_0  0
#define CHANNEL_1  1
#define CHANNEL_2  2
#define CHANNEL_3  3
#define CHANNEL_4  4
#define CHANNEL_5  5
#define CHANNEL_6  6
#define CHANNEL_7  7
#define CHANNEL_8  8
#define CHANNEL_9  9
#define CHANNEL_10 10

#define CHEAT_HURRICANEFISTS         0
#define CHEAT_CLOAKINGDEVICE         1
#define CHEAT_INVINCIBLE             2
#define CHEAT_ALLGUNS                3
#define CHEAT_UNLIMITEDAMMO          4
#define CHEAT_UNLIMITEDAMMONORELOADS 5
#define CHEAT_SLOMO                  6
#define CHEAT_DKMODE                 7
#define CHEAT_TRENTSMAGNUM           8
#define CHEAT_FARSIGHT               9
#define CHEAT_SMALLJO                10
#define CHEAT_SMALLCHARACTERS        11
#define CHEAT_ENEMYSHIELDS           12
#define CHEAT_JOSHIELD               13
#define CHEAT_SUPERSHIELD            14
#define CHEAT_CLASSICSIGHT           15
#define CHEAT_TEAMHEADSONLY          16
#define CHEAT_PLAYASELVIS            17
#define CHEAT_ENEMYROCKETS           18
#define CHEAT_UNLIMITEDAMMOLAPTOP    19
#define CHEAT_MARQUIS                20
#define CHEAT_PERFECTDARKNESS        21
#define CHEAT_PUGILIST               22
#define CHEAT_HOTSHOT                23
#define CHEAT_HITANDRUN              24
#define CHEAT_ALIEN                  25
#define CHEAT_RTRACKER               26
#define CHEAT_ROCKETLAUNCHER         27
#define CHEAT_SNIPERRIFLE            28
#define CHEAT_XRAYSCANNER            29
#define CHEAT_SUPERDRAGON            30
#define CHEAT_LAPTOPGUN              31
#define CHEAT_PHOENIX                32
#define CHEAT_PSYCHOSISGUN           33
#define CHEAT_PP9I                   34
#define CHEAT_CC13                   35
#define CHEAT_KL01313                36
#define CHEAT_KF7SPECIAL             37
#define CHEAT_ZZT                    38
#define CHEAT_DMC                    39
#define CHEAT_AR53                   40
#define CHEAT_RCP45                  41

#define CHEATFLAG_TIMED       0
#define CHEATFLAG_ALWAYSON    1
#define CHEATFLAG_TRANSFERPAK 2
#define CHEATFLAG_COMPLETION  4
#define CHEATFLAG_FIRINGRANGE 8

#define CHECKSUM_PLACEHOLDER 0x99aabbcc

#define CHOKETYPE_NONE   0
#define CHOKETYPE_GURGLE 1
#define CHOKETYPE_COUGH  2

#define CHR_P1P2_OPPOSITE 0xf1
#define CHR_P1P2          0xf2
#define CHR_ANY           0xf3 // Only supported by if_chr_activated_object command
#define CHR_ANTI          0xf4
#define CHR_COOP          0xf5
#define CHR_TARGET        0xf6
#define CHR_BOND          0xf8
#define CHR_CLONE         0xf9
#define CHR_SEESHOT       0xfa
#define CHR_SEEDIE        0xfb
#define CHR_PRESET        0xfc
#define CHR_SELF          0xfd

// chr->flags
#define CHRFLAG0_CANT_ALERT_GROUP   0x00000001 // Don't set group alertness when becoming aware
#define CHRFLAG0_00000002           0x00000002 // Not used in scripts
#define CHRFLAG0_00000004           0x00000004 // Can search for player when heard?
#define CHRFLAG0_CAN_EXAMINE_BODY   0x00000008
#define CHRFLAG0_00000010           0x00000010 // Globals, Skedar Ruins
#define CHRFLAG0_SAID_INJURY_QUIP   0x00000020
#define CHRFLAG0_00000040           0x00000040 // Globals - related to cover?
#define CHRFLAG0_00000080           0x00000080 // Globals, Chicago, Air Base
#define CHRFLAG0_CAN_BACKOFF        0x00000100
#define CHRFLAG0_CAN_RETREAT        0x00000200
#define CHRFLAG0_UNSURPRISABLE      0x00000400 // may also be "can uncover disguise"
#define CHRFLAG0_CAN_THROW_GRENADES 0x00000800
#define CHRFLAG0_CAN_FLANK          0x00001000
#define CHRFLAG0_00002000           0x00002000 // Used quite a lot
#define CHRFLAG0_00004000           0x00004000 // Patroller - if set, overrides the 00002000 flag (interprets 00002000 as off)
#define CHRFLAG0_00008000           0x00008000 // Something to do with breaking cover or grenades?
#define CHRFLAG0_AIVSAI             0x00010000
#define CHRFLAG0_CAN_TRAP           0x00020000
#define CHRFLAG0_CAN_GO_TO_PLACES   0x00040000
#define CHRFLAG0_SQUADALERTANYDIST  0x00080000
#define CHRFLAG0_00100000           0x00100000 // Become alert when hearing player and never on screen
#define CHRFLAG0_00200000           0x00200000 // Globals, Villa hostage takers
#define CHRFLAG0_00400000           0x00400000 // Not used in scripts
#define CHRFLAG0_CAN_HEAR_ALARMS    0x00800000
#define CHRFLAG0_01000000           0x01000000 // Globals
#define CHRFLAG0_02000000           0x02000000 // Globals - set when ambushing
#define CHRFLAG0_04000000           0x04000000 // If set, chr can't follow player (ie. stays)?
#define CHRFLAG0_08000000           0x08000000 // Globals, Villa, Infiltration, Pelagic
#define CHRFLAG0_10000000           0x10000000 // If set, "IM GOING TO POP"
#define CHRFLAG0_CAN_HEARSPAWN      0x20000000
#define CHRFLAG0_NOHEAR             0x40000000 // Globals, Villa
#define CHRFLAG0_CANLOSEGUN         0x80000000 // Globals, Villa, Chicago, CI Training

// chr->flags2
#define CHRFLAG1_00000001                  0x00000001 // Globals, Extraction, Air Base, Deep Sea
#define CHRFLAG1_00000002                  0x00000002 // Globals
#define CHRFLAG1_00000004                  0x00000004 // Globals - If set, avoids try_attack_amount
#define CHRFLAG1_00000008                  0x00000008 // Only used in WAR. If set, chr waits 2 seconds before attacking while defending
#define CHRFLAG1_00000010                  0x00000010 // Globals - If set, avoids try_attack_amount
#define CHRFLAG1_00000020                  0x00000020 // Globals, AF1, Defense - related to reload animation
#define CHRFLAG1_CAN_SNIPE                 0x00000040
#define CHRFLAG1_00000080                  0x00000080 // Not used in scripts
#define CHRFLAG1_DOINGIDLEANIMATION        0x00000100
#define CHRFLAG1_WARNED                    0x00000200
#define CHRFLAG1_00000400                  0x00000400 // Globals
#define CHRFLAG1_00000800                  0x00000800 // Globals - related to punch damage
#define CHRFLAG1_00001000                  0x00001000 // Globals, Chicago, Infiltration
#define CHRFLAG1_00002000                  0x00002000 // Globals - triggers grenade throw
#define CHRFLAG1_00004000                  0x00004000 // Globals - related to cover
#define CHRFLAG1_LONG_CAMSPY_OBSERVATION   0x00008000
#define CHRFLAG1_00010000                  0x00010000 // Globals - if set, prevents setting of chrflag0_00100000
#define CHRFLAG1_00020000                  0x00020000 // Globals
#define CHRFLAG1_00040000                  0x00040000 // Globals - seems related to 00020000
#define CHRFLAG1_00080000                  0x00080000 // Set in many places, read in globals and AF1
#define CHRFLAG1_00100000                  0x00100000 // Globals
#define CHRFLAG1_00200000                  0x00200000 // Deep Sea (Elvis)
#define CHRFLAG1_PUNCH_THEN_GENERAL_COMBAT 0x00400000 // If unset, return after punching. If set, assign general combat
#define CHRFLAG1_DONE_SEARCH_ANIM          0x00800000
#define CHRFLAG1_01000000                  0x01000000 // Can search for player when heard?
#define CHRFLAG1_02000000                  0x02000000 // Globals
#define CHRFLAG1_CAN_LOOK_AROUND           0x04000000
#define CHRFLAG1_DISSPEE                   0x08000000
#define CHRFLAG1_10000000                  0x10000000 // Some kind of param for searching
#define CHRFLAG1_CAN_DRAW_PISTOL           0x20000000
#define CHRFLAG1_40000000                  0x40000000 // Globals
#define CHRFLAG1_80000000                  0x80000000 // Globals

// chr->hidden
#define CHRHFLAG_00000001            0x00000001 // Set when chr drops weapon
#define CHRHFLAG_IS_HEARING_TARGET   0x00000002 // Not used in scripts
#define CHRHFLAG_00000004            0x00000004 // Related to firing - hand 1
#define CHRHFLAG_00000008            0x00000008 // Related to firing - hand 0
#define CHRHFLAG_00000010            0x00000010 // Not used in scripts
#define CHRHFLAG_REAPED              0x00000020
#define CHRHFLAG_TIMER_RUNNING       0x00000040
#define CHRHFLAG_00000080            0x00000080 // Not used in scripts
#define CHRHFLAG_00000100            0x00000100 // Not used in scripts
#define CHRHFLAG_00000200            0x00000200 // Not used in scripts
#define CHRHFLAG_PASSIVE             0x00000400
#define CHRHFLAG_KEEP_CORPSE         0x00000800 // Appears to be misnamed
#define CHRHFLAG_UNTARGETABLE        0x00001000
#define CHRHFLAG_00002000            0x00002000 // Globals, Rescue guards once disguised
#define CHRHFLAG_TRIGGER_BUDDY_WARP  0x00004000
#define CHRHFLAG_PERFECTACCURACY     0x00008000
#define CHRHFLAG_DISGUISE_UNCOVERED  0x00010000
#define CHRHFLAG_00020000            0x00020000 // Used in every stage, on Jo and other chrs. Only ever set, never unset or read.
#define CHRHFLAG_00040000            0x00040000 // Not used in scripts
#define CHRHFLAG_DISGUISED           0x00080000
#define CHRHFLAG_00100000            0x00100000 // Set before warping to pad, never unset or read
#define CHRHFLAG_NEEDANIM            0x00200000
#define CHRHFLAG_00400000            0x00400000 // Set in Chicago, G5, AF1, Defense, Attack Ship, Skedar Ruins, Maian SOS, WAR
#define CHRHFLAG_00800000            0x00800000 // Not used in scripts
#define CHRHFLAG_01000000            0x01000000 // Globals - asked about gun (eg. "where did you get that?")
#define CHRHFLAG_02000000            0x02000000 // Similar to DISGUISED flag, but not sure where set
#define CHRHFLAG_04000000            0x04000000 // Related to disguise and detection
#define CHRHFLAG_08000000            0x08000000 // Globals, Villa and G5
#define CHRHFLAG_10000000            0x10000000 // Related to invincible flag
#define CHRHFLAG_CLOAKED             0x20000000
#define CHRHFLAG_ANTINONINTERACTABLE 0x40000000
#define CHRHFLAG_PSYCHOSISED         0x80000000

// chr->hidden2
#define CHRH2FLAG_0001              0x0001
#define CHRH2FLAG_0002              0x0002 // Equivalent to OBJFLAG3_00020000
#define CHRH2FLAG_0008              0x0008
#define CHRH2FLAG_TICKDURINGAUTOCUT 0x0010
#define CHRH2FLAG_0040              0x0040
#define CHRH2FLAG_0080              0x0080
#define CHRH2FLAG_HEADSHOTTED       0x1000

// chr->chrflags
#define CHRCFLAG_00000001                    0x00000001 // Villa takers, Attack Ship Cass and skedar - both set at end of intros
#define CHRCFLAG_CLONEABLE                   0x00000002
#define CHRCFLAG_NEAR_MISS                   0x00000004
#define CHRCFLAG_NEVER_BEEN_ON_SCREEN        0x00000008
#define CHRCFLAG_INVINCIBLE                  0x00000010
#define CHRCFLAG_00000020                    0x00000020 // Chicago, Infiltration, AF1, Ruins, WAR
#define CHRCFLAG_00000040                    0x00000040 // Used quite a lot
#define CHRCFLAG_00000080                    0x00000080 // Defection programmer, Rescue lab techs, globals when doing idle animation
#define CHRCFLAG_JUST_INJURED                0x00000100
#define CHRCFLAG_00000200                    0x00000200 // Set on clones
#define CHRCFLAG_HIDDEN                      0x00000400
#define CHRCFLAG_NOAUTOAIM                   0x00000800
#define CHRCFLAG_UNEXPLODABLE                0x00001000
#define CHRCFLAG_NOSHADOW                    0x00002000
#define CHRCFLAG_HAS_SPECIAL_DEATH_ANIMATION 0x00004000
#define CHRCFLAG_00008000                    0x00008000 // Not used in scripts
#define CHRCFLAG_00010000                    0x00010000 // Related to dead people in intro cutscenes
#define CHRCFLAG_FORCEAUTOAIM                0x00020000 // Allow auto aim even if chr is unarmed
#define CHRCFLAG_00040000                    0x00040000 // Used a lot
#define CHRCFLAG_RUNFASTER                   0x00080000
#define CHRCFLAG_KILLCOUNTABLE               0x00100000
#define CHRCFLAG_TRIGGERSHOTLIST             0x00200000
#define CHRCFLAG_00400000                    0x00400000 // Not used in scripts
#define CHRCFLAG_UNPLAYABLE                  0x00800000
#define CHRCFLAG_PUSHABLE                    0x01000000 // Typically set on allies during init
#define CHRCFLAG_02000000                    0x02000000 // can be unset by cmd0168
#define CHRCFLAG_KEEPCORPSEKO                0x04000000
#define CHRCFLAG_CONSIDER_DODGE              0x08000000
#define CHRCFLAG_10000000                    0x10000000 // Not used in scripts
#define CHRCFLAG_20000000                    0x20000000 // Not used in scripts
#define CHRCFLAG_40000000                    0x40000000 // Not used in scripts
#define CHRCFLAG_INJUREDTARGET               0x80000000

#define CIQUIP_GREETING 0
#define CIQUIP_MAIN     1
#define CIQUIP_ANNOYED  2
#define CIQUIP_THANKS   3

#define CIROOM_FIRINGRANGE 0x0a
#define CIROOM_HOLOSTART   0x16
#define CIROOM_HOLOEND     0x19
#define CIROOM_DEVICEROOM  0x1e

#define CMD_LABEL 0x0002
#define CMD_END   0x0004
#define CMD_PRINT 0x00b5

// Collision detection
#define CDRESULT_ERROR       -1
#define CDRESULT_COLLISION   0
#define CDRESULT_NOCOLLISION 1

#define CDTYPE_OBJS              0x0001
#define CDTYPE_DOORS             0x0002
#define CDTYPE_PLAYERS           0x0004
#define CDTYPE_CHRS              0x0008
#define CDTYPE_10                0x0010
#define CDTYPE_BG                0x0020
#define CDTYPE_OBJSWITHFLAG      0x0080
#define CDTYPE_OBJSWITHOUTFLAG   0x0100
#define CDTYPE_OBJSWITHFLAG2     0x0200
#define CDTYPE_OBJSNOTSAFEORHELI 0x0400
#define CDTYPE_DOORSWITHOUTFLAG  0x0800
#define CDTYPE_CLOSEDDOORS       0x1000
#define CDTYPE_OPENDOORS         0x2000
#define CDTYPE_AJARDOORS         0x4000
#define CDTYPE_DOORSLOCKEDTOAI   0x8000
#define CDTYPE_ALL               0x003f

#define COLOR_00_GREEN  0x00
#define COLOR_02_WHITE  0x02
#define COLOR_03_RED    0x03
#define COLOR_04_ORANGE 0x04
#define COLOR_05_GREEN  0x05
#define COLOR_06_WHITE  0x06
#define COLOR_07_RED    0x07
#define COLOR_08_RED    0x08
#define COLOR_09_BLUE   0x09

#define COMPARE_ANY     0
#define COMPARE_FRIENDS 1
#define COMPARE_ENEMIES 2

// Control styles - 1.1, 1.2 etc
#define CONTROLMODE_11 0
#define CONTROLMODE_12 1
#define CONTROLMODE_13 2
#define CONTROLMODE_14 3
#define CONTROLMODE_21 4
#define CONTROLMODE_22 5
#define CONTROLMODE_23 6
#define CONTROLMODE_24 7

#define COVERFLAG_0001            0x0001
#define COVERFLAG_INUSE           0x0002
#define COVERFLAG_AIMSAMEROOM     0x0004 // look + 6 metres is in the same room
#define COVERFLAG_AIMDIFFROOM     0x0008 // look + 6 metres is not in the same room
#define COVERFLAG_OMNIDIRECTIONAL 0x0010
#define COVERFLAG_0020            0x0020
#define COVERFLAG_0040            0x0040
#define COVERFLAG_0080            0x0080

// L/C/R = left/centered/right
// big/med/sml is the font size
#define CREDITSTYLE_R_BIG_R_MED 1
#define CREDITSTYLE_C_BIG       2
#define CREDITSTYLE_C_MED       3
#define CREDITSTYLE_04          4
#define CREDITSTYLE_C_SML       5
#define CREDITSTYLE_L_BIG       7
#define CREDITSTYLE_R_MED       9
#define CREDITSTYLE_11          11
#define CREDITSTYLE_12          12
#define CREDITSTYLE_C_BIG_C_BIG 10
#define CREDITSTYLE_TERMINATOR  20

#define CROUCHPOS_SQUAT 0
#define CROUCHPOS_DUCK  1
#define CROUCHPOS_STAND 2

#define CULLMODE_NONE  1
#define CULLMODE_FRONT 2
#define CULLMODE_BACK  3

#define DAMAGETYPE_0 0
#define DAMAGETYPE_1 1
#define DAMAGETYPE_2 2
#define DAMAGETYPE_3 3
#define DAMAGETYPE_4 4
#define DAMAGETYPE_5 5
#define DAMAGETYPE_6 6
#define DAMAGETYPE_7 7

#define DESCRIPTION_BRIEFING       0x00
#define DESCRIPTION_MPCONFIG       0x01
#define DESCRIPTION_MPCHALLENGE    0x02
#define DESCRIPTION_CHRBIO         0x03
#define DESCRIPTION_MISCBIO        0x04
#define DESCRIPTION_DEVICETRAINING 0x05
#define DESCRIPTION_FRWEAPON       0x06
#define DESCRIPTION_HANGARBIO      0x07
#define DESCRIPTION_HOLOTRAINING   0x08
#define DESCRIPTION_HOLOTIP1       0x09
#define DESCRIPTION_HOLOTIP2       0x0a
#define DESCRIPTION_DEVICETIP1     0x0b
#define DESCRIPTION_DEVICETIP2     0x0c

#define DEVICE_NIGHTVISION 0x01
#define DEVICE_XRAYSCANNER 0x02
#define DEVICE_EYESPY      0x04
#define DEVICE_IRSCANNER   0x08
#define DEVICE_RTRACKER    0x10
#define DEVICE_SUICIDEPILL 0x20
#define DEVICE_CLOAKDEVICE 0x40
#define DEVICE_CLOAKRCP120 0x80

#define DEVICESTATE_UNEQUIPPED -1
#define DEVICESTATE_INACTIVE   0
#define DEVICESTATE_ACTIVE     1

#define DIFF_A  0x00
#define DIFF_SA 0x01
#define DIFF_PA 0x02
#define DIFF_PD 0x03

// These difficulties are for briefings, which can be bitwise ORed
#define DIFFBIT_A  0x01
#define DIFFBIT_SA 0x02
#define DIFFBIT_PA 0x04
#define DIFFBIT_PD 0x08

#define DOORFLAG_WINDOWED        0x0002
#define DOORFLAG_0004            0x0004
#define DOORFLAG_FLIP            0x0008
#define DOORFLAG_AUTOMATIC       0x0010
#define DOORFLAG_0040            0x0040
#define DOORFLAG_0080            0x0080
#define DOORFLAG_0100            0x0100
#define DOORFLAG_0200            0x0200 // dataDyne secret door near lobby elevator
#define DOORFLAG_DAMAGEONCONTACT 0x0400 // Lasers
#define DOORFLAG_0800            0x0800 // Non-CI lasers, and floor grates
#define DOORFLAG_4000            0x4000 // Two Investigation vertical doors after lasers

#define DOORMODE_IDLE    0
#define DOORMODE_OPENING 1
#define DOORMODE_CLOSING 2
#define DOORMODE_WAITING 3 // Waiting for sibling door to close. Eg. Dam gates in GE

// For AI commands - bitwise ORable
#define DOORSTATE_CLOSED  1
#define DOORSTATE_OPEN    2
#define DOORSTATE_CLOSING 4
#define DOORSTATE_OPENING 8

#define DOORTYPE_SLIDING  0
#define DOORTYPE_VERTICAL 4
#define DOORTYPE_SWINGING 5
#define DOORTYPE_8        8
#define DOORTYPE_HULL     10
#define DOORTYPE_LASER    11

#define DRCAROLLIMAGE_EYESDEFAULT  0
#define DRCAROLLIMAGE_HEARTRATE    1
#define DRCAROLLIMAGE_EYESFROWNING 2
#define DRCAROLLIMAGE_X            3
#define DRCAROLLIMAGE_STATIC       4
#define DRCAROLLIMAGE_BINARY       5
#define DRCAROLLIMAGE_EYESSLEEPY   6
#define DRCAROLLIMAGE_RANDOM25     7
#define DRCAROLLIMAGE_RANDOM       8

#define DROPREASON_1 1
#define DROPREASON_2 2
#define DROPREASON_3 3
#define DROPREASON_4 4
#define DROPREASON_5 5
#define DROPREASON_6 6

#define ENTITYTYPE_BOND      0x0001 // aim/shoot at Jo
#define ENTITYTYPE_FORWARD   0x0002 // aim/shoot in front of self
#define ENTITYTYPE_CHR       0x0004 // aim/shoot at chr (ID should be given in entity_id)
#define ENTITYTYPE_PAD       0x0008 // aim/shoot at pad (ID should be given in entity_id)
#define ENTITYTYPE_DIRECTION 0x0010 // aim/shoot in compass direction (0000, 4000, 8000, c000)
#define ENTITYTYPE_AIMONLY   0x0020 // aim only - do not shoot
#define ENTITYTYPE_DONTTURN  0x0040 // don't do a shooting animation that would change the chr's direction
#define ENTITYTYPE_TARGET    0x0200 // aim/shoot at whatever is in the chr's `target` field

#define EXPLOSIONTYPE_0  0
#define EXPLOSIONTYPE_2  2
#define EXPLOSIONTYPE_3  3
#define EXPLOSIONTYPE_5  5
#define EXPLOSIONTYPE_7  7
#define EXPLOSIONTYPE_8  8
#define EXPLOSIONTYPE_12 12
#define EXPLOSIONTYPE_14 14
#define EXPLOSIONTYPE_18 18
#define EXPLOSIONTYPE_23 23
#define EXPLOSIONTYPE_25 25

#define EYESPYMODE_CAMSPY  0
#define EYESPYMODE_DRUGSPY 1
#define EYESPYMODE_BOMBSPY 2

#define FILEERROR_NOPAK            0
#define FILEERROR_SAVEFAILED       1
#define FILEERROR_LOADFAILED       2
#define FILEERROR_DELETEFAILED     3
#define FILEERROR_OUTOFMEMORY      4
#define FILEERROR_ALREADYLOADED    5
#define FILEERROR_PAKREMOVED       6
#define FILEERROR_PAKDAMAGED       7
#define FILEERROR_DELETENOTEFAILED 8

#define FILESTATE_UNSELECTED    0
#define FILESTATE_SELECTED      1
#define FILESTATE_CHANGINGAGENT 2

#define FILETYPE_SOLO     0
#define FILETYPE_MPSETUP  1
#define FILETYPE_MPPLAYER 2

#define FLOORTYPE_DEFAULT 0
#define FLOORTYPE_WOOD    1
#define FLOORTYPE_STONE   2
#define FLOORTYPE_CARPET  3
#define FLOORTYPE_METAL   4
#define FLOORTYPE_MUD     5
#define FLOORTYPE_WATER   6
#define FLOORTYPE_DIRT    7
#define FLOORTYPE_SNOW    8

#define FRCMD_ADDTARGET           0x00
#define FRCMD_SETMAXACTIVETARGETS 0x01
#define FRCMD_SETGOALSCORE        0x02
#define FRCMD_SETTIMELIMIT        0x03
#define FRCMD_SETAMMOLIMIT        0x04
#define FRCMD_SETEXTRASPEED       0x05
#define FRCMD_SETGOALACCURACY     0x06
#define FRCMD_SETGOALTARGETS      0x07
#define FRCMD_SETHELPSCRIPT       0x08
#define FRCMD_SETGRENADELIMIT     0x09
#define FRCMD_SETPADINDEXOFFSET   0x0a
#define FRCMD_SETSCOREMULTIPLIER  0x0b
#define FRCMD_GOTOPAD             0x0c
#define FRCMD_RESTART             0x0d
#define FRCMD_WAITSECONDS         0x0e
#define FRCMD_ROTATE              0x0f
#define FRCMD_HUDMSG              0x10
#define FRCMD_WAITUNTILSHOOT      0x11
#define FRCMD_HELPWAITSECONDS     0x12
#define FRCMD_END                 0x13
#define FRCMD_IFBRONZE            0xfb
#define FRCMD_IFSILVER            0xfc
#define FRCMD_IFGOLD              0xfd

#define FRDIFFICULTY_BRONZE 0
#define FRDIFFICULTY_SILVER 1
#define FRDIFFICULTY_GOLD   2

#define FRFAILREASON_NOTFAILED         0
#define FRFAILREASON_OUTOFAMMO         1
#define FRFAILREASON_TIMEOVER          2
#define FRFAILREASON_SCOREUNATTAINABLE 3
#define FRFAILREASON_INACCURATE        4

#define FRMENUTYPE_WEAPONLIST 0
#define FRMENUTYPE_DETAILS    1
#define FRMENUTYPE_FAILED     2
#define FRMENUTYPE_COMPLETED  3

#define FRROTATE_90R  0
#define FRROTATE_180R 1
#define FRROTATE_90L  2
#define FRROTATE_180L 3

#define FRTARGETFLAG_BRONZE                 0x01
#define FRTARGETFLAG_SILVER                 0x02
#define FRTARGETFLAG_GOLD                   0x04
#define FRTARGETFLAG_ROTATEONCLOAK          0x08
#define FRTARGETFLAG_SPAWNFACINGAWAY        0x10
#define FRTARGETFLAG_ONEHITEXPLODE          0x20
#define FRTARGETFLAG_FARSIGHTAUTOTARGETABLE 0x40
#define FRTARGETFLAG_TMPINVINCIBLE          0x80

#define FRZONE_RING3    1
#define FRZONE_RING2    2
#define FRZONE_RING1    5
#define FRZONE_BULLSEYE 10
#define FRZONE_EXPLODE  11

// Weapon functions
#define FUNC_PRIMARY   0
#define FUNC_SECONDARY 1
#define FUNC_2         2
#define FUNC_POISON         3 // Internal function for delivering knife poison periodically

#define FUNCFLAG_BURST3                 0x00000002
#define FUNCFLAG_BURST50                0x00000020 // automatics only
#define FUNCFLAG_NOAUTOAIM              0x00000040
#define FUNCFLAG_STICKTOWALL            0x00000100
#define FUNCFLAG_MAKEDIZZY              0x00000200
#define FUNCFLAG_DROPWEAPON             0x00000400
#define FUNCFLAG_FLYBYWIRE              0x00000800
#define FUNCFLAG_BURST2                 0x00001000
#define FUNCFLAG_NOMUZZLEFLASH          0x00002000
#define FUNCFLAG_EXPLOSIVESHELLS        0x00004000
#define FUNCFLAG_BLUNTIMPACT            0x00008000
#define FUNCFLAG_NOSTUN                 0x00010000
#define FUNCFLAG_BURST5                 0x00020000
#define FUNCFLAG_DISCARDWEAPON          0x00040000 // Dragon and Laptop throw
#define FUNCFLAG_THREATDETECTOR         0x00080000
#define FUNCFLAG_AUTOSWITCHUNSELECTABLE 0x00100000
#define FUNCFLAG_PSYCHOSIS              0x00200000
#define FUNCFLAG_00400000               0x00400000 // punch, disarm and pistol whip
#define FUNCFLAG_00800000               0x00800000 // mostly throwables but some projectiles too
#define FUNCFLAG_08000000               0x08000000 // rockets
#define FUNCFLAG_10000000               0x10000000 // grenade launchers
#define FUNCFLAG_20000000               0x20000000 // explosives related
#define FUNCFLAG_HOMINGROCKET           0x40000000

#define GAILIST_IDLE                   0x0000
#define GAILIST_UNALERTED_0001         0x0001
#define GAILIST_UNALERTED_0002         0x0002
#define GAILIST_STOP_UNALERTED         0x0003 // unused
#define GAILIST_UNALERTED_0004         0x0004
#define GAILIST_END_CINEMA             0x0005
#define GAILIST_UNALERTED              0x0006
#define GAILIST_ALERTED                0x0007
#define GAILIST_WAKEUP                 0x0008
#define GAILIST_IDLE_0009              0x0009
#define GAILIST_BUSY                   0x000a
#define GAILIST_CHOOSE_TARGET          0x000b
#define GAILIST_COMBAT_WITH_TARGET     0x000c
#define GAILIST_INIT_COMBAT            0x000d // unused
#define GAILIST_SEE_THEN_ATTACK        0x000e // unused
#define GAILIST_HAND_COMBAT            0x000f
#define GAILIST_CIVILIAN_SAY_COMMENT   0x0010
#define GAILIST_FLEE_FROM_GRENADE      0x0011
#define GAILIST_INIT_COOP_100          0x0012
#define GAILIST_INIT_COOP_200          0x0013
#define GAILIST_COOP_BUDDY             0x0014
#define GAILIST_AIBUDDY_STEALTH        0x0015
#define GAILIST_SHOW_OBJ_FAILED_MSG    (VERSION >= VERSION_NTSC_1_0 ? 0x0016 : 0x0015)
#define GAILIST_REBUILD_GROUPS         (VERSION >= VERSION_NTSC_1_0 ? 0x0017 : 0x0016)
#define GAILIST_DO_BORED_ANIMATION     0x0018
#define GAILIST_DO_SITTING_ANIMATION   0x0019
#define GAILIST_DISGUISE_DETECTION     0x001a
#define GAILIST_OBSERVE_CAMSPY         0x001b
#define GAILIST_SURPRISED              0x001c
#define GAILIST_SEARCH_FOR_PLAYER      0x001d
#define GAILIST_LOOK_AROUND            0x001e
#define GAILIST_RELATED_TO_SPAWNING    0x001f
#define GAILIST_PLACE_COOP_BUDDY       0x0020
#define GAILIST_STOP_AND_IDLE          0x0021
#define GAILIST_COMMENT_ON_PLAYER_DEAD 0x0022 // unused
#define GAILIST_DODGE                  0x0023
#define GAILIST_FOLLOW_BOND            0x0024
#define GAILIST_POINTLESS              0x0025 // unused
#define GAILIST_INIT_PSYCHOSIS         0x0026
#define GAILIST_PSYCHOSISED            0x0027
#define GAILIST_AI_BOT_DEAD            0x0028 // unused
#define GAILIST_AI_BOT_INIT            0x0029 // unused
#define GAILIST_AI_BOT_ALIVE           0x002a // unused
#define GAILIST_DO_SOMETHING_AND_WAIT  0x002b // unused
#define GAILIST_INIT_SEARCH            0x002c // unused
#define GAILIST_INVINCIBLE_AND_IDLE    0x002d

#define GOPOSFLAG_SPEED        0x03 // bits 0x01 and 0x02 combined
#define GOPOSFLAG_INIT         0x04
#define GOPOSFLAG_ONPRESETPATH 0x08
#define GOPOSFLAG_20           0x20
#define GOPOSFLAG_DUCK         0x40
#define GOPOSFLAG_80           0x80

#define GUNCMD_END               0
#define GUNCMD_SHOWPART          1
#define GUNCMD_HIDEPART          2
#define GUNCMD_WAITFORZRELEASED  3
#define GUNCMD_WAITTIME          4
#define GUNCMD_PLAYSOUND         5
#define GUNCMD_INCLUDE           6
#define GUNCMD_RANDOM            7
#define GUNCMD_REPEATUNTILFULL   8
#define GUNCMD_POPOUTSACKOFPILLS 9
#define GUNCMD_PLAYANIMATION     10
#define GUNCMD_SETSOUNDSPEED     11

#define GUNMEMOWNER_0  0
#define GUNMEMOWNER_1  1
#define GUNMEMOWNER_2  2
#define GUNMEMOWNER_3  3
#define GUNMEMOWNER_10 10
#define GUNMEMOWNER_11 11

#define GUNSIGHTREASON_1         0x01
#define GUNSIGHTREASON_AIMING    0x02
#define GUNSIGHTREASON_NOCONTROL 0x04
#define GUNSIGHTREASON_DAMAGE    0x10

#define HAND_RIGHT 0
#define HAND_LEFT  1

#define HANDANIMMODE_IDLE 0
#define HANDANIMMODE_BUSY 2

#define HANDATTACKTYPE_SHOOT               1
#define HANDATTACKTYPE_SHOOTPROJECTILE     2
#define HANDATTACKTYPE_THROWPROJECTILE     3
#define HANDATTACKTYPE_CLOSERANGE          4
#define HANDATTACKTYPE_DETONATE            5
#define HANDATTACKTYPE_BOOST               6
#define HANDATTACKTYPE_REVERTBOOST         7
#define HANDATTACKTYPE_CROUCH              8
#define HANDATTACKTYPE_RCP120CLOAK         9
#define HANDATTACKTYPE_CLOSERANGENOUNCLOAK 10
#define HANDATTACKTYPE_UPLINK              12

#define HANDMODE_NONE  0
#define HANDMODE_1  1
#define HANDMODE_6  6
#define HANDMODE_7  7
#define HANDMODE_8  8
#define HANDMODE_RELOAD  9
#define HANDMODE_11 11
#define HANDMODE_12 12
#define HANDMODE_13 13

#define HANDSTATE_IDLE        0
#define HANDSTATE_RELOAD      1
#define HANDSTATE_2           2
#define HANDSTATE_ATTACKEMPTY 3
#define HANDSTATE_ATTACK      4
#define HANDSTATE_CHANGEGUN   5
#define HANDSTATE_6           6
#define HANDSTATE_CHANGEFUNC  7
#define HANDSTATE_AUTOSWITCH  8

#define HANDSTATEFLAG_00000001 0x00000001
#define HANDSTATEFLAG_00000010 0x00000010
#define HANDSTATEFLAG_00000020 0x00000020
#define HANDSTATEFLAG_00000040 0x00000040
#define HANDSTATEFLAG_00000080 0x00000080

#define HANGARBIO_INSTITUTE      0
#define HANGARBIO_DDTOWER        1
#define HANGARBIO_LABBASEMENT    2
#define HANGARBIO_VILLA          3
#define HANGARBIO_CHICAGO        4
#define HANGARBIO_G5             5
#define HANGARBIO_AREA51         6
#define HANGARBIO_AIRBASE        7
#define HANGARBIO_AIRFORCEONE    8
#define HANGARBIO_CRASHSITE      9
#define HANGARBIO_PELAGIC        10
#define HANGARBIO_DEEPSEA        11
#define HANGARBIO_ATTACKSHIP     12
#define HANGARBIO_SKEDARRUINS    13
#define HANGARBIO_JUMPSHIP       14
#define HANGARBIO_HOVERCRATE     15
#define HANGARBIO_HOVERBIKE      16
#define HANGARBIO_HOVERBOT       17
#define HANGARBIO_HOVERCOPTER    18
#define HANGARBIO_G5ROBOT        19
#define HANGARBIO_A51INTERCEPTOR 20
#define HANGARBIO_MAIANVESSEL    21
#define HANGARBIO_SKEDARSHUTTLE  22

#define HATTYPE_METAL 3
#define HATTYPE_CLOTH 5

#define HEALTHSHOWMODE_HIDDEN   0 // health bar not visible
#define HEALTHSHOWMODE_OPENING  1 // height expanding
#define HEALTHSHOWMODE_PREVIOUS 2 // full height, showing previous health amount
#define HEALTHSHOWMODE_UPDATING 3 // full height, transitioning from previous amount to current amount
#define HEALTHSHOWMODE_CURRENT  4 // full height, showing current amount
#define HEALTHSHOWMODE_CLOSING  5 // height collapsing

#define HUDMSGFLAG_ONLYIFALIVE 0x1
#define HUDMSGFLAG_2           0x2
#define HUDMSGFLAG_4           0x4
#define HUDMSGFLAG_ALLOWDUPES  0x8

#define HUDMSGSTATE_FREE      0
#define HUDMSGSTATE_QUEUED    1
#define HUDMSGSTATE_FADINGIN  3
#define HUDMSGSTATE_ONSCREEN  4
#define HUDMSGSTATE_FADINGOUT 5

#define HUDMSGTYPE_DEFAULT           0
#define HUDMSGTYPE_OBJECTIVECOMPLETE 1
#define HUDMSGTYPE_OBJECTIVEFAILED   2
#define HUDMSGTYPE_3                 3
#define HUDMSGTYPE_4                 4
#define HUDMSGTYPE_SUBTITLE          6
#define HUDMSGTYPE_MPSCENARIO        9
#define HUDMSGTYPE_TRAINING          10
#define HUDMSGTYPE_11                11

// chr->ivebeenhit values
#define IBH_LFOOT       1
#define IBH_LSHIN       2
#define IBH_LTHIGH      3
#define IBH_RFOOT       4
#define IBH_RSHIN       5
#define IBH_RTHIGH      6
#define IBH_PELVIS      7
#define IBH_HEAD        8
#define IBH_LHAND       9
#define IBH_LFOREARM    10
#define IBH_LBICEP      11
#define IBH_RHAND       12
#define IBH_RFOREARM    13
#define IBH_RBICEP      14
#define IBH_TORSO       15
#define IBH_TAIL        16
#define IBH_GUN         100
#define IBH_HAT         110
#define IBH_GENERAL     200
#define IBH_GENERALHALF 201

#define IDLEACTION_STANDING        0x01
#define IDLEACTION_SITTING_TYPING  0x02
#define IDLEACTION_SITTING_DORMANT 0x03
#define IDLEACTION_OPERATING       0x04
#define IDLEACTION_OPERATING_PAD   0x05

#define INTROCMD_SPAWN        0
#define INTROCMD_WEAPON       1
#define INTROCMD_AMMO         2
#define INTROCMD_3            3
#define INTROCMD_4            4
#define INTROCMD_OUTFIT       5
#define INTROCMD_6            6
#define INTROCMD_WATCHTIME    7
#define INTROCMD_CREDITOFFSET 8
#define INTROCMD_CASE         9
#define INTROCMD_CASERESPAWN  10
#define INTROCMD_HILL         11
#define INTROCMD_END          12

#define INVENTORYFUNCTYPE_NONE             0x0000
#define INVENTORYFUNCTYPE_SHOOT            0x0001
#define INVENTORYFUNCTYPE_SHOOT_SINGLE     0x0001
#define INVENTORYFUNCTYPE_SHOOT_AUTOMATIC  0x0101
#define INVENTORYFUNCTYPE_SHOOT_PROJECTILE 0x0201
#define INVENTORYFUNCTYPE_THROW            0x0002
#define INVENTORYFUNCTYPE_CLOSE            0x0003
#define INVENTORYFUNCTYPE_SPECIAL          0x0004
#define INVENTORYFUNCTYPE_DEVICE           0x0005

#define INVITEMTYPE_WEAP 1
#define INVITEMTYPE_PROP 2
#define INVITEMTYPE_DUAL 3

// Lift actions
#define LA_1 1 // either waiting for lift or in lift
#define LA_3 3 // either waiting for lift or in lift

#define LANGUAGE_NTSC_EN 0
#define LANGUAGE_NTSC_JP 1

#define LANGUAGE_PAL_EN  0
#define LANGUAGE_PAL_FR  1
#define LANGUAGE_PAL_DE  2
#define LANGUAGE_PAL_IT  3
#define LANGUAGE_PAL_ES  4

#define LIGHTOP_1       1
#define LIGHTOP_2       2
#define LIGHTOP_3       3
#define LIGHTOP_4       4
#define LIGHTOP_5       5
#define LIGHTOP_TURNON  6
#define LIGHTOP_TURNOFF 7

#define LOADTYPE_NONE  0
#define LOADTYPE_BG    1
#define LOADTYPE_TILES 2
#define LOADTYPE_SETUP 4
#define LOADTYPE_PADS  5
#define LOADTYPE_MODEL 6

// These actions are assigned to chr->myaction
#define MA_NONE            0
#define MA_NORMAL          1
#define MA_COVERWAIT       2
#define MA_GRENADEWAIT     3
#define MA_WAITING         4
#define MA_COVERGOTO       5
#define MA_COVERBREAK      6
#define MA_COVERSEEN       7
#define MA_FLANKLEFT       8
#define MA_FLANKRIGHT      9
#define MA_DODGE           10
#define MA_GRENADE         11
#define MA_WAITSEEN        12
#define MA_WITHDRAW        13
#define MA_SHOOTING        14
#define MA_SYNCSHOOT       15
#define MA_WAITTIMEOUT     16
#define MA_COVERTIMEOUT    17
#define MA_TRACKING        18
#define MA_RETREAT         19
#define MA_SURRENDER       20
#define MA_TALKING         21
#define MA_LISTENING       22
#define MA_GOTOALARM       23
#define MA_BOTFRIENDFOLLOW 24
#define MA_BOTHIDE         25
#define MA_BOTPATH         26
#define MA_BOTINJURED      27
#define MA_BOTNORMAL       28
#define MA_BOTSHOOTING     29
#define MA_DRUGGED         30
#define MA_PANIC           31
#define MA_RUNFROMGRENADE  32
#define MA_UNARMEDATTACK   33
#define MA_SKJUMP_START    34
#define MA_SKJUMP_AIR      35
#define MA_SKJUMP_LAND     36
#define MA_SKJUMP_LANDLOOP 37
#define MA_SKJUMP_SHOT     38
#define MA_AIBOTDEADLIST   39
#define MA_AIBOTINIT       40
#define MA_AIBOTMAINLOOP   41
#define MA_AIBOTGETITEM    42
#define MA_AIBOTGOTOPOS    43
#define MA_AIBOTGOTOPROP   44
#define MA_AIBOTRUNAWAY    45
#define MA_AIBOTDOWNLOAD   46
#define MA_AIBOTATTACK     47
#define MA_UNUSED1         48
#define MA_UNUSED2         49
#define MA_AIBOTFOLLOW     50
#define MA_AIBOTDEFEND     51
#define MA_FLANKBEST       52
#define MA_FACING          53
#define MA_PUNCHING        54
#define MA_END             55

#define MAX_CHRWAYPOINTS   6
#define MAX_DANGEROUSPROPS 12
#define MAX_LIFTS          10
#define MAX_MPCHRS         (4 + MAX_SIMULANTS)
#define MAX_OBJECTIVES     10
#define MAX_SIMULANTS      8
#define MAX_SPAWNPOINTS    24
#define MAX_SQUADRONS      16
#define MAX_TEAMS          8

#define MEMBANK_ONBOARD   0
#define MEMBANK_EXPANSION 1

#define MEMPOOL_0         0
#define MEMPOOL_STAGE     4 // Cleared on stage load
#define MEMPOOL_5         5
#define MEMPOOL_PERMANENT 6 // Never cleared
#define MEMPOOL_7         7
#define MEMPOOL_8         8

#define MENUDIALOGTYPE_DEFAULT 1
#define MENUDIALOGTYPE_DANGER  2
#define MENUDIALOGTYPE_SUCCESS 3

#define MENUITEMTYPE_LABEL       0x01
#define MENUITEMTYPE_LIST        0x02
#define MENUITEMTYPE_SELECTABLE  0x04
#define MENUITEMTYPE_SCROLLABLE  0x05
#define MENUITEMTYPE_OBJECTIVES  0x06
#define MENUITEMTYPE_07          0x07
#define MENUITEMTYPE_SLIDER      0x08
#define MENUITEMTYPE_CHECKBOX    0x09
#define MENUITEMTYPE_SEPARATOR   0x0b
#define MENUITEMTYPE_DROPDOWN    0x0c
#define MENUITEMTYPE_KEYBOARD    0x0d
#define MENUITEMTYPE_RANKING     0x0e
#define MENUITEMTYPE_PLAYERSTATS 0x0f
#define MENUITEMTYPE_10          0x10
#define MENUITEMTYPE_CAROUSEL    0x11
#define MENUITEMTYPE_MODEL       0x12
#define MENUITEMTYPE_13          0x13
#define MENUITEMTYPE_14          0x14
#define MENUITEMTYPE_METER       0x15
#define MENUITEMTYPE_16          0x16
#define MENUITEMTYPE_MARQUEE     0x17
#define MENUITEMTYPE_18          0x18
#define MENUITEMTYPE_CONTROLLER  0x19
#define MENUITEMTYPE_END         0x1a

#define MENUOP_GETOPTIONCOUNT      1
#define MENUOP_GETOPTGROUPCOUNT    2
#define MENUOP_GETOPTIONTEXT       3
#define MENUOP_GETOPTGROUPTEXT     4
#define MENUOP_GETGROUPSTARTINDEX  5
#define MENUOP_SET                 6
#define MENUOP_GETOPTIONVALUE      7
#define MENUOP_GET                 8
#define MENUOP_GETSLIDER           9
#define MENUOP_GETSLIDERLABEL      10
#define MENUOP_11                  11
#define MENUOP_CHECKDISABLED       12
#define MENUOP_FOCUS               13
#define MENUOP_GETLISTITEMCHECKBOX 14
#define MENUOP_CHECKPREFOCUSED     15
#define MENUOP_LISTITEMFOCUS       16
#define MENUOP_GETTEXT             17
#define MENUOP_SETTEXT             18
#define MENUOP_RENDER              19
#define MENUOP_GETOPTIONHEIGHT     20
#define MENUOP_21                  21
#define MENUOP_GETCOLOUR           22
#define MENUOP_CHECKHIDDEN         24
#define MENUOP_25                  25
#define MENUOP_OPEN                100
#define MENUOP_CLOSE               101
#define MENUOP_TICK                102

#define MENUROOT_ENDSCREEN    1
#define MENUROOT_MAINMENU     2
#define MENUROOT_MPSETUP      3
#define MENUROOT_MPPAUSE      4
#define MENUROOT_MPENDSCREEN  5
#define MENUROOT_FILEMGR      6
#define MENUROOT_BOOTPAKMGR   7
#define MENUROOT_PICKTARGET   8
#define MENUROOT_COOPCONTINUE 9
#define MENUROOT_4MBFILEMGR   10
#define MENUROOT_4MBMAINMENU  11
#define MENUROOT_TRAINING     13

#define MENUSOUND_SWIPE          0x00 // Navigating to left/right dialog
#define MENUSOUND_OPENDIALOG     0x01
#define MENUSOUND_FOCUS          0x02 // Focusing a different item
#define MENUSOUND_SELECT         0x03
#define MENUSOUND_ERROR          0x04
#define MENUSOUND_EXPLOSION      0x05
#define MENUSOUND_TOGGLEON       0x08 // Checking a checkbox
#define MENUSOUND_TOGGLEOFF      0x09 // Unchecking a checkbox, opening a dropdown, cancelling a dropdown
#define MENUSOUND_SUBFOCUS       0x0a // Changing focus within a list or dropdown
#define MENUSOUND_KEYBOARDFOCUS  0x0c // Changing focus within a keyboard item
#define MENUSOUND_KEYBOARDCANCEL 0x0d // Pressing A on a keyboard's cancel button

#define MISCBIO_MAIANS     0
#define MISCBIO_SKEDAR     1
#define MISCBIO_BACKGROUND 2
#define MISCBIO_STORY      3

#define MISCSFX_BOOSTHEARTBEAT   0
#define MISCSFX_SLAYERROCKETHUM  1
#define MISCSFX_SLAYERROCKETBEEP 2

// Models
#define MODEL_ROOFGUN               0x0000
#define MODEL_GROUNDGUN             0x0001
#define MODEL_TVSCREEN              0x0002
#define MODEL_BORG_CRATE            0x0003
#define MODEL_WINDOW                0x0004
#define MODEL_A51_CRATE1_0005       0x0005
#define MODEL_A51_CRATE1_0006       0x0006
#define MODEL_A51_CRATE1_0007       0x0007
#define MODEL_A51_CRATE1_0008       0x0008
#define MODEL_A51_CRATE1_0009       0x0009
#define MODEL_A51_CRATE1_000a       0x000a
#define MODEL_A51_CRATE1_000b       0x000b
#define MODEL_A51_CRATE1_000c       0x000c
#define MODEL_A51_CRATE1_000d       0x000d
#define MODEL_A51_CRATE1_000e       0x000e
#define MODEL_A51_CRATE1_000f       0x000f
#define MODEL_CRYPTDOOR1B           0x0010
#define MODEL_CHRBRIEFCASE          0x0011
#define MODEL_CHRBUG                0x0012
#define MODEL_CHRDATATHIEF          0x0013
#define MODEL_NINTENDOLOGO          0x0014
#define MODEL_DOOR_ROLLERTRAIN      0x0015
#define MODEL_FLAG                  0x0016
#define MODEL_MODEMBOX              0x0017
#define MODEL_DOORCONSOLE           0x0018
#define MODEL_A51_HORIZ_DOOR_TOP    0x0019
#define MODEL_A51_HORIZ_DOOR_BOT    0x001a
#define MODEL_A51_VERT_DOOR_LEFT    0x001b
#define MODEL_A51_VERT_DOOR_RIGHT   0x001c
#define MODEL_A51_VERT_DOOR_ST      0x001d
#define MODEL_A51_HORIZ_DOOR_GL     0x001e
#define MODEL_A51_HORIZ_DOOR_SECRET 0x001f
#define MODEL_A51_CRATE1            0x0020
#define MODEL_A51_CRATE2            0x0021
#define MODEL_A51_CRATE3            0x0022
#define MODEL_A51_EXP1              0x0023
#define MODEL_A51_UNEXP1            0x0024
#define MODEL_A51_EXP2              0x0025
#define MODEL_A51_UNEXP2            0x0026
#define MODEL_A51_UNEXP3            0x0027
#define MODEL_AIVILLADOOR1          0x0028
#define MODEL_AIVILLADOOR2A         0x0029
#define MODEL_AIVILLADOOR4          0x002a
#define MODEL_A51_LIFT_HANGAR       0x002b
#define MODEL_A51_LIFT_CONTROL      0x002c
#define MODEL_A51_LIFT_STORE        0x002d
#define MODEL_A51_LIFT_THINWALL     0x002e
#define MODEL_AIVILLABOT1           0x002f
#define MODEL_AIVILLABOT2           0x0030
#define MODEL_AIVILLABOT3           0x0031
#define MODEL_AIVILLAWINDMILL       0x0032
#define MODEL_HOVERBED              0x0033
#define MODEL_MARKER                0x0034
#define MODEL_ALDOOR_R              0x0035
#define MODEL_ALDOOR_L              0x0036
#define MODEL_DD_LIFTR              0x0037
#define MODEL_DD_FANROOF            0x0038
#define MODEL_DD_FANWALL            0x0039
#define MODEL_HOVBIKE               0x003a
#define MODEL_DD_OFFICEDOOR         0x003b
#define MODEL_DD_PLANTRUBBER        0x003c
#define MODEL_DD_PLANTSPIKE         0x003d
#define MODEL_DD_PLANTSPIDER        0x003e
#define MODEL_DD_WINDOW             0x003f
#define MODEL_DD_REDSOFA            0x0040
#define MODEL_DD_REDARM             0x0041
#define MODEL_DD_SERVICEDOOR        0x0042
#define MODEL_DD_WINDDOOR           0x0043
#define MODEL_DD_LIFTDOOR           0x0044
#define MODEL_DD_VERTBLIND          0x0045
#define MODEL_DD_DESK               0x0046
#define MODEL_DD_CHAIR              0x0047
#define MODEL_NLOGO                 0x0048
#define MODEL_NLOGO2                0x0049
#define MODEL_NLOGO3                0x004a
#define MODEL_PERFECTDARK           0x004b
#define MODEL_PDONE                 0x004c
#define MODEL_PDTWO                 0x004d
#define MODEL_PDTHREE               0x004e
#define MODEL_PDFOUR                0x004f
#define MODEL_DD_HOVCOP             0x0050
#define MODEL_DD_HOVMOTO            0x0051
#define MODEL_DD_HOVTRUCK           0x0052
#define MODEL_DD_HOVCAR             0x0053
#define MODEL_DD_HOVCAB             0x0054
#define MODEL_DD_AC_UNEXP           0x0055
#define MODEL_DD_AC_EXP             0x0056
#define MODEL_DD_ACBOT_UNEXP        0x0057
#define MODEL_DD_ACBOT_EXP          0x0058
#define MODEL_PC1                   0x0059
#define MODEL_HOVERCRATE1           0x005a
#define MODEL_DROPSHIP              0x005b
#define MODEL_AL_AIRLOCK            0x005c
#define MODEL_AL_DOCKLIFT           0x005d
#define MODEL_CASE                  0x005e
#define MODEL_DD_STONEDESK          0x005f
#define MODEL_MEDLABWIN1            0x0060
#define MODEL_MEDLABWIN2            0x0061
#define MODEL_A51TABLE              0x0062
#define MODEL_A51CHAIR              0x0063
#define MODEL_A51SCREEN             0x0064
#define MODEL_A51WASTEBIN           0x0065
#define MODEL_A51DESKENT            0x0066
#define MODEL_A51TROLLEY            0x0067
#define MODEL_A51DIVIDE             0x0068
#define MODEL_A51BOARD              0x0069
#define MODEL_SKCREV_EXP1           0x006a
#define MODEL_SKCREV_UNEXP1         0x006b
#define MODEL_SKTNL_EXP1            0x006c
#define MODEL_SKTNL_UNEXP1          0x006d
#define MODEL_SK_DOOR1              0x006e
#define MODEL_SK_SHIP_DOOR1         0x006f
#define MODEL_SK_SHIP_HOLO1         0x0070
#define MODEL_SK_SHIP_HOLO2         0x0071
#define MODEL_SK_SHIP_HULLDOOR1     0x0072
#define MODEL_SK_SHIP_HULLDOOR2     0x0073
#define MODEL_SK_SHIP_HULLDOOR3     0x0074
#define MODEL_SK_SHIP_HULLDOOR4     0x0075
#define MODEL_SK_FIGHTER1           0x0076
#define MODEL_SK_CRYOPOD1_TOP       0x0077
#define MODEL_SK_CRYOPOD1_BOT       0x0078
#define MODEL_SK_UNDER_GENERATOR    0x0079
#define MODEL_SK_UNDER_TRANS        0x007a
#define MODEL_SK_HANGARDOOR_TOP     0x007b
#define MODEL_SK_HANGARDOOR_BOT     0x007c
#define MODEL_DOOR2_G5              0x007d
#define MODEL_DOOR1A_G5             0x007e
#define MODEL_DOOR1B_G5             0x007f
#define MODEL_DOOR1ATRI_G5          0x0080
#define MODEL_DOOR2A_G5             0x0081
#define MODEL_DD_DECODOOR           0x0082
#define MODEL_DD_SECRETDOOR         0x0083
#define MODEL_DD_SECRETDOOR2        0x0084
#define MODEL_DDJUMPSHIP            0x0085
#define MODEL_TAXICAB               0x0086
#define MODEL_POLICECAR             0x0087
#define MODEL_RAVINELIFT            0x0088
#define MODEL_DD_LAB_DOOR_BS        0x0089
#define MODEL_DD_LAB_DOOR_SEC       0x008a
#define MODEL_DD_LAB_DOOR_WIND      0x008b
#define MODEL_HOOVERBOT             0x008c
#define MODEL_TESTERBOT             0x008d
#define MODEL_DD_LAB_SECTOR2BOT     0x008e
#define MODEL_DD_LAB_SECTOR2TOP     0x008f
#define MODEL_DD_LAB_CAUTIONTOP     0x0090
#define MODEL_DD_LAB_HAZARD         0x0091
#define MODEL_DD_LAB_CAUTION        0x0092
#define MODEL_DR_CAROLL_DOOR        0x0093
#define MODEL_DD_LAB_SECTOR3TOP     0x0094
#define MODEL_DD_LAB_SECTOR3        0x0095
#define MODEL_DD_LAB_SECTOR3WIND    0x0096
#define MODEL_DD_HOVERCOPTER        0x0097
#define MODEL_DD_LAB_SECTOR4TOP     0x0098
#define MODEL_DD_LAB_RESTRICTED     0x0099
#define MODEL_DOOR4A_G5             0x009a
#define MODEL_DOOR4B_G5             0x009b
#define MODEL_LASDOOR               0x009c
#define MODEL_G5SAFEDOOR            0x009d
#define MODEL_ROPE                  0x009e
#define MODEL_G5_MAINFRAME          0x009f
#define MODEL_DR_CAROLL_DOOR_BASE   0x00a0
#define MODEL_DR_CAROLL_DOOR_MAIN   0x00a1
#define MODEL_DR_CAROLL_DOOR_LEFT   0x00a2
#define MODEL_DR_CAROLL_DOOR_RIGHT  0x00a3
#define MODEL_DR_CAROLL_DOOR_BMAIN  0x00a4
#define MODEL_DR_CAROLL_DOOR_BLEFT  0x00a5
#define MODEL_DR_CAROLL_DOOR_BRIGHT 0x00a6
#define MODEL_DD_BANNER             0x00a7
#define MODEL_G5_ESCDOORUP          0x00a8
#define MODEL_G5_ESCDOORUPBOOM      0x00a9
#define MODEL_G5_ESCDOORDOWN        0x00aa
#define MODEL_G5_ESCDOORDOWNBOOM    0x00ab
#define MODEL_DUMPSTER              0x00ac
#define MODEL_G5CARLIFTDOOR         0x00ad
#define MODEL_CH_SHUTTER1           0x00ae
#define MODEL_CCTV_PD               0x00af
#define MODEL_COMHUB                0x00b0
#define MODEL_QUADPOD               0x00b1
#define MODEL_PD_CONSOLE            0x00b2
#define MODEL_DD_GRATE              0x00b3
#define MODEL_LIFT_PLATFORM         0x00b4
#define MODEL_LIGHTSWITCH           0x00b5
#define MODEL_BLASTSHIELD           0x00b6
#define MODEL_LIGHTSWITCH2          0x00b7
#define MODEL_DD_ACCESSDOORUP       0x00b8
#define MODEL_DD_ACCESSDOORDN       0x00b9
#define MODEL_LAB_CONTAINER         0x00ba
#define MODEL_LAB_CHAIR             0x00bb
#define MODEL_LAB_TABLE             0x00bc
#define MODEL_LAB_MICROSCOPE        0x00bd
#define MODEL_LAB_MAINFRAME         0x00be
#define MODEL_DD_LABDOOR            0x00bf
#define MODEL_DD_LAB_DOORTOP        0x00c0
#define MODEL_MULTI_AMMO_CRATE      0x00c1
#define MODEL_CHRCHAIN              0x00c2
#define MODEL_TDOOR                 0x00c3
#define MODEL_CI_SOFA               0x00c4
#define MODEL_CI_LIFT               0x00c5
#define MODEL_CI_LIFTDOOR           0x00c6
#define MODEL_LASERCUT              0x00c7
#define MODEL_SK_SHUTTLE            0x00c8
#define MODEL_NEWVILLADOOR          0x00c9
#define MODEL_SK_PILLARLEFT         0x00ca
#define MODEL_SK_PILLARRIGHT        0x00cb
#define MODEL_SK_PLINTH_T           0x00cc
#define MODEL_SK_PLINTH_ML          0x00cd
#define MODEL_SK_PLINTH_MR          0x00ce
#define MODEL_SK_PLINTH_BL          0x00cf
#define MODEL_SK_PLINTH_BR          0x00d0
#define MODEL_SK_FL_SHAD_T          0x00d1
#define MODEL_SK_FL_SHAD_ML         0x00d2
#define MODEL_SK_FL_SHAD_MR         0x00d3
#define MODEL_SK_FL_SHAD_BL         0x00d4
#define MODEL_SK_FL_SHAD_BR         0x00d5
#define MODEL_SK_FL_NOSHAD_T        0x00d6
#define MODEL_SK_FL_NOSHAD_ML       0x00d7
#define MODEL_SK_FL_NOSHAD_MR       0x00d8
#define MODEL_SK_FL_NOSHAD_BL       0x00d9
#define MODEL_SK_FL_NOSHAD_BR       0x00da
#define MODEL_SK_TEMPLECOLUMN1      0x00db
#define MODEL_SK_TEMPLECOLUMN2      0x00dc
#define MODEL_SK_TEMPLECOLUMN3      0x00dd
#define MODEL_SK_SUNSHAD1           0x00de
#define MODEL_SK_SUNSHAD2           0x00df
#define MODEL_SK_SUNNOSHAD1         0x00e0
#define MODEL_SK_SUNNOSHAD2         0x00e1
#define MODEL_BARREL                0x00e2
#define MODEL_GLASS_FLOOR           0x00e3
#define MODEL_ESCA_STEP             0x00e4
#define MODEL_MATRIX_LIFT           0x00e5
#define MODEL_RUBBLE1               0x00e6
#define MODEL_RUBBLE2               0x00e7
#define MODEL_RUBBLE3               0x00e8
#define MODEL_RUBBLE4               0x00e9
#define MODEL_CABLE_CAR             0x00ea
#define MODEL_ELVIS_SAUCER          0x00eb
#define MODEL_STEWARDESS_TROLLEY    0x00ec
#define MODEL_AIRBASE_LIFT_ENCLOSED 0x00ed
#define MODEL_AIRBASE_LIFT_ANGLE    0x00ee
#define MODEL_AIRBASE_SAFEDOOR      0x00ef
#define MODEL_AF1_PILOTCHAIR        0x00f0
#define MODEL_AF1_PASSCHAIR         0x00f1
#define MODEL_TESTOBJ               0x00f2
#define MODEL_CHRNIGHTSIGHT         0x00f3
#define MODEL_CHRSHIELD             0x00f4
#define MODEL_CHRFALCON2            0x00f5
#define MODEL_CHRLEEGUN1            0x00f6
#define MODEL_CHRMAULER             0x00f7
#define MODEL_CHRDY357              0x00f8
#define MODEL_CHRDY357TRENT         0x00f9
#define MODEL_CHRMAIANPISTOL        0x00fa
#define MODEL_CHRFALCON2SIL         0x00fb
#define MODEL_CHRFALCON2SCOPE       0x00fc
#define MODEL_CHRCMP150             0x00fd
#define MODEL_CHRAR34               0x00fe
#define MODEL_CHRDRAGON             0x00ff
#define MODEL_CHRSUPERDRAGON        0x0100
#define MODEL_CHRAVENGER            0x0101
#define MODEL_CHRCYCLONE            0x0102
#define MODEL_CHRMAIANSMG           0x0103
#define MODEL_CHRRCP120             0x0104
#define MODEL_CHRPCGUN              0x0105
#define MODEL_CHRSHOTGUN            0x0106
#define MODEL_CHRSKMINIGUN          0x0107
#define MODEL_CHRDYROCKET           0x0108
#define MODEL_CHRDEVASTATOR         0x0109
#define MODEL_CHRSKROCKET           0x010a
#define MODEL_CHRZ2020              0x010b
#define MODEL_CHRSNIPERRIFLE        0x010c
#define MODEL_CHRCROSSBOW           0x010d
#define MODEL_CHRDRUGGUN            0x010e
#define MODEL_CHRKNIFE              0x010f
#define MODEL_CHRNBOMB              0x0110
#define MODEL_CHRFLASHBANG          0x0111
#define MODEL_CHRGRENADE            0x0112
#define MODEL_CHRTIMEDMINE          0x0113
#define MODEL_CHRPROXIMITYMINE      0x0114
#define MODEL_CHRREMOTEMINE         0x0115
#define MODEL_CHRECMMINE            0x0116
#define MODEL_CHRWPPK               0x0117
#define MODEL_CHRTT33               0x0118
#define MODEL_CHRSKORPION           0x0119
#define MODEL_CHRKALASH             0x011a
#define MODEL_CHRUZI                0x011b
#define MODEL_CHRMP5K               0x011c
#define MODEL_CHRM16                0x011d
#define MODEL_CHRFNP90              0x011e
#define MODEL_CHRDYROCKETMIS        0x011f
#define MODEL_CHRSKROCKETMIS        0x0120
#define MODEL_CHRCROSSBOLT          0x0121
#define MODEL_CHRDEVGRENADE         0x0122
#define MODEL_CHRDRAGGRENADE        0x0123
#define MODEL_A51_TURRET            0x0124
#define MODEL_PELAGICDOOR           0x0125
#define MODEL_AUTOSURGEON           0x0126
#define MODEL_LIMO                  0x0127
#define MODEL_A51INTERCEPTOR        0x0128
#define MODEL_A51DISH               0x0129
#define MODEL_A51RADARCONSOLE       0x012a
#define MODEL_A51LOCKERDOOR         0x012b
#define MODEL_G5GENERATOR           0x012c
#define MODEL_G5DUMPSTER            0x012d
#define MODEL_CHRCLOAKER            0x012e
#define MODEL_CHRSPEEDPILL          0x012f
#define MODEL_BIGPELAGICDOOR        0x0130
#define MODEL_SK_JONRUBBLE3         0x0131
#define MODEL_SK_JONRUBBLE4         0x0132
#define MODEL_SK_JONRUBBLE5         0x0133
#define MODEL_SK_JONRUBBLE6         0x0134
#define MODEL_BAGGAGECARRIER        0x0135
#define MODEL_MINESIGN              0x0136
#define MODEL_CHAMBER               0x0137
#define MODEL_ISOTOPEEXPERIMENT     0x0138
#define MODEL_ISOTOPE               0x0139
#define MODEL_REACTORDOOR           0x013a
#define MODEL_SAUCERINSIDE          0x013b
#define MODEL_VILLASTOOL            0x013c
#define MODEL_CETANWINDOW1          0x013d
#define MODEL_CETANWINDOW2          0x013e
#define MODEL_CETANWINDOW3          0x013f
#define MODEL_BINOCULARS            0x0140
#define MODEL_SUBMARINE             0x0141
#define MODEL_AIRFORCE1             0x0142
#define MODEL_ENGINEPART            0x0143
#define MODEL_CETROOFGUN            0x0144
#define MODEL_CETANSMALLDOOR        0x0145
#define MODEL_POWERNODE             0x0146
#define MODEL_CETANBLUEGREENL       0x0147
#define MODEL_CETANBLUEGREENR       0x0148
#define MODEL_SKEDARCONSOLE         0x0149
#define MODEL_SKEDARCONSOLEPANEL    0x014a
#define MODEL_WEAPONCDOOR           0x014b
#define MODEL_TARGET                0x014c
#define MODEL_DEVICESECRETDOOR      0x014d
#define MODEL_CARRINGTONSECRETDOOR  0x014e
#define MODEL_SINISTERPC            0x014f
#define MODEL_SINISTERSTATION       0x0150
#define MODEL_KEYPADLOCK            0x0151
#define MODEL_THUMBPRINTSCANNER     0x0152
#define MODEL_RETINALOCK            0x0153
#define MODEL_CARDLOCK              0x0154
#define MODEL_GOODSTATION           0x0155
#define MODEL_GOODPC                0x0156
#define MODEL_CHRAUTOGUN            0x0157
#define MODEL_G5BIGCHAIR            0x0158
#define MODEL_G5SMALLCHAIR          0x0159
#define MODEL_KINGSCEPTRE           0x015a
#define MODEL_LABCOAT               0x015b
#define MODEL_CIDOOR1               0x015c
#define MODEL_G5_CHAIR              0x015d
#define MODEL_G5_CHAIR2             0x015e
#define MODEL_DD_WINDOW_FOYER       0x015f
#define MODEL_CI_CABINET            0x0160
#define MODEL_CI_DESK               0x0161
#define MODEL_CI_CARR_DESK          0x0162
#define MODEL_CI_F_CHAIR            0x0163
#define MODEL_CI_LOUNGER            0x0164
#define MODEL_CI_F_SOFA             0x0165
#define MODEL_CI_TABLE              0x0166
#define MODEL_CV_COFFEE_TABLE       0x0167
#define MODEL_CV_CHAIR1             0x0168
#define MODEL_CV_CHAIR2             0x0169
#define MODEL_CV_SOFA               0x016a
#define MODEL_CV_CHAIR4             0x016b
#define MODEL_CV_LAMP               0x016c
#define MODEL_CV_CABINET            0x016d
#define MODEL_CV_F_BED              0x016e
#define MODEL_PEL_CHAIR1            0x016f
#define MODEL_SK_CONSOLE2           0x0170
#define MODEL_DD_EAR_TABLE          0x0171
#define MODEL_DD_EAR_CHAIR          0x0172
#define MODEL_AIRBASE_TABLE2        0x0173
#define MODEL_AIRBASE_CHAIR2        0x0174
#define MODEL_MISC_CRATE            0x0175
#define MODEL_A51_CRATE1_0175       0x0176
#define MODEL_MISC_IRSPECS          0x0177
#define MODEL_A51_ROOFGUN           0x0178
#define MODEL_SK_DRONE_GUN          0x0179
#define MODEL_CI_ROOFGUN            0x017a
#define MODEL_CV_TABLE              0x017b
#define MODEL_CIDOOR1_REF           0x017c
#define MODEL_ALASKADOOR_OUT        0x017d
#define MODEL_ALASKADOOR_IN         0x017e
#define MODEL_WIREFENCE             0x017f
#define MODEL_RARELOGO              0x0180
#define MODEL_KEYCARD               0x0181
#define MODEL_BODYARMOUR            0x0182
#define MODEL_A51GATE_R             0x0183
#define MODEL_A51GATE_L             0x0184
#define MODEL_AF1_LAMP              0x0185
#define MODEL_AF1_TOILET            0x0186
#define MODEL_AF1_DOORBIG2          0x0187
#define MODEL_AF1_PHONE             0x0188
#define MODEL_AF1_CARGODOOR         0x0189
#define MODEL_G5_ALARM              0x018a
#define MODEL_G5_LASER_SWITCH       0x018b
#define MODEL_SK_TEMPLECOLUMN4      0x018c
#define MODEL_COREHATCH             0x018d
#define MODEL_A51GRATE              0x018e
#define MODEL_AF1ESCAPEDOOR         0x018f
#define MODEL_PRESCAPSULE           0x0190
#define MODEL_SKEDARBRIDGE          0x0191
#define MODEL_PELAGICDOOR2          0x0192
#define MODEL_TTB_BOX               0x0193
#define MODEL_INSTFRONTDOOR         0x0194
#define MODEL_CHRLASER              0x0195
#define MODEL_BAFTA                 0x0196
#define MODEL_CHRSONICSCREWER       0x0197
#define MODEL_CHRLUMPHAMMER         0x0198
#define MODEL_EXPLOSIVEBRICK        0x0199
#define MODEL_SKEDARBOMB            0x019a
#define MODEL_ZIGGYCARD             0x019b
#define MODEL_SAFEITEM              0x019c
#define MODEL_RUSSDAR               0x019d
#define MODEL_XRAYSPECS             0x019e
#define MODEL_CHRLUMPHAMMER2        0x019f
#define MODEL_CHREYESPY             0x01a0
#define MODEL_CHRDOORDECODER        0x01a1
#define MODEL_AF1_TABLE             0x01a2
#define MODEL_SHUTTLEDOOR           0x01a3
#define MODEL_RUINBRIDGE            0x01a4
#define MODEL_SECRETINDOOR          0x01a5
#define MODEL_SENSITIVEINFO         0x01a6
#define MODEL_SUITCASE              0x01a7
#define MODEL_SKPUZZLEOBJECT        0x01a8
#define MODEL_A51LIFTDOOR           0x01a9
#define MODEL_CIHUB                 0x01aa
#define MODEL_SK_SHIP_DOOR2         0x01ab
#define MODEL_SK_WINDOW1            0x01ac
#define MODEL_SK_HANGARDOORB_TOP    0x01ad
#define MODEL_SK_HANGARDOORB_BOT    0x01ae
#define MODEL_AF1_INNERDOOR         0x01af
#define MODEL_LASER_POST            0x01b0
#define MODEL_TARGETAMP             0x01b1
#define MODEL_SK_LIFT               0x01b2
#define MODEL_KNOCKKNOCK            0x01b3
#define MODEL_CETANDOOR             0x01b4
#define MODEL_AF1RUBBLE             0x01b5
#define MODEL_DD_DR_NONREF          0x01b6
#define MODEL_CETANDOORSIDE         0x01b7
#define MODEL_BUDDYBRIDGE           0x01b8

#define MODELNODETYPE_CHRINFO      0x01
#define MODELNODETYPE_POSITION     0x02
#define MODELNODETYPE_GUNDL        0x04
#define MODELNODETYPE_05           0x05
#define MODELNODETYPE_DISTANCE     0x08
#define MODELNODETYPE_REORDER      0x09
#define MODELNODETYPE_BBOX         0x0a
#define MODELNODETYPE_0B           0x0b
#define MODELNODETYPE_GUNFIRE      0x0c
#define MODELNODETYPE_0D           0x0d
#define MODELNODETYPE_0E           0x0e
#define MODELNODETYPE_0F           0x0f
#define MODELNODETYPE_11           0x11
#define MODELNODETYPE_TOGGLE       0x12
#define MODELNODETYPE_POSITIONHELD 0x15
#define MODELNODETYPE_16           0x16
#define MODELNODETYPE_HEADSPOT     0x17
#define MODELNODETYPE_DL           0x18

#define MODELPART_00                0x00
#define MODELPART_LENS              0x00
#define MODELPART_01                0x01
#define MODELPART_02                0x02
#define MODELPART_ROBOTMUZZLEFLASHR 0x02
#define MODELPART_03                0x03
#define MODELPART_ROBOTMUZZLEFLASHL 0x03
#define MODELPART_HUDPIECE          0x04
#define MODELPART_04                0x04
#define MODELPART_05                0x05
#define MODELPART_NECKLACE          0x07
#define MODELPART_NEWCLIP           0x28
#define MODELPART_NEWCLIP2          0x29
#define MODELPART_NEWCLIP3          0x2a
#define MODELPART_NEWCLIP4          0x2b
#define MODELPART_SCOPE             0x2c
#define MODELPART_SILENCER          0x2d
#define MODELPART_2E                0x2e
#define MODELPART_2F                0x2f
#define MODELPART_42                0x42
#define MODELPART_MUZZLEFLASH       0x5a
#define MODELPART_MUZZLEFLASH2      0x5b
#define MODELPART_MUZZLEFLASH3      0x5c
#define MODELPART_6E                0x6e
#define MODELPART_SKGANGWAY         0xb7

#define MODELPART_DRCAROLL_01 0x01
#define MODELPART_DRCAROLL_02 0x02
#define MODELPART_DRCAROLL_03 0x03
#define MODELPART_DRCAROLL_04 0x04
#define MODELPART_DRCAROLL_05 0x05
#define MODELPART_DRCAROLL_07 0x07
#define MODELPART_DRCAROLL_08 0x08
#define MODELPART_DRCAROLL_09 0x09
#define MODELPART_DRCAROLL_0A 0x0a
#define MODELPART_DRCAROLL_0B 0x0b

#define MODELPART_ELVIS_03 0x03

#define MODELTYPE_BASIC          0x02
#define MODELTYPE_CHRGUN         0x03
#define MODELTYPE_JOYPAD         0x04
#define MODELTYPE_UZI            0x05
#define MODELTYPE_06             0x06
#define MODELTYPE_CLASSICGUN     0x07
#define MODELTYPE_CASING         0x08
#define MODELTYPE_CHR            0x09
#define MODELTYPE_0A             0x0a
#define MODELTYPE_0B             0x0b
#define MODELTYPE_0C             0x0c
#define MODELTYPE_HEAD           0x0d
#define MODELTYPE_CCTV           0x0f
#define MODELTYPE_WINDOWEDDOOR   0x10
#define MODELTYPE_11             0x11
#define MODELTYPE_12             0x12
#define MODELTYPE_13             0x13
#define MODELTYPE_TERMINAL       0x14
#define MODELTYPE_CIHUB          0x15
#define MODELTYPE_AUTOGUN        0x16
#define MODELTYPE_17             0x17
#define MODELTYPE_18             0x18
#define MODELTYPE_19             0x19
#define MODELTYPE_LIFT           0x1b
#define MODELTYPE_SKEDAR         0x1c
#define MODELTYPE_LOGO           0x1d
#define MODELTYPE_PDLOGO         0x1e
#define MODELTYPE_HOVERBIKE      0x1f
#define MODELTYPE_20             0x20
#define MODELTYPE_21             0x21
#define MODELTYPE_22             0x22
#define MODELTYPE_LAPTOPGUN      0x23
#define MODELTYPE_K7AVENGER      0x24
#define MODELTYPE_FALCON2        0x25
#define MODELTYPE_KNIFE          0x26
#define MODELTYPE_CHOPPER        0x27
#define MODELTYPE_DRCAROLL       0x28
#define MODELTYPE_ROPE           0x29
#define MODELTYPE_HUDPIECE       0x2a
#define MODELTYPE_RARELOGO       0x2c
#define MODELTYPE_JUMPSHIP       0x32
#define MODELTYPE_BANNER         0x33
#define MODELTYPE_ROBOT          0x34
#define MODELTYPE_CABLECAR       0x3c
#define MODELTYPE_SUBMARINE      0x43
#define MODELTYPE_MAIANUFO       0x44
#define MODELTYPE_SKEDARSHUTTLE  0x45
#define MODELTYPE_CMP150         0x46
#define MODELTYPE_DRAGON         0x47
#define MODELTYPE_SUPERDRAGON    0x48
#define MODELTYPE_ROCKET         0x49
#define MODELTYPE_4A             0x4a
#define MODELTYPE_SHOTGUN        0x4b
#define MODELTYPE_FARSIGHT       0x4c
#define MODELTYPE_4D             0x4d
#define MODELTYPE_REAPER         0x4e
#define MODELTYPE_DROPSHIP       0x4f
#define MODELTYPE_MAULER         0x64
#define MODELTYPE_DEVASTATOR     0x65
#define MODELTYPE_PISTOL         0x66
#define MODELTYPE_AR34           0x67
#define MODELTYPE_MAGNUM         0x68
#define MODELTYPE_SLAYERROCKET   0x69
#define MODELTYPE_CYCLONE        0x6a
#define MODELTYPE_SNIPERRIFLE    0x6b
#define MODELTYPE_TRANQUILIZER   0x6c
#define MODELTYPE_CROSSBOW       0x6d
#define MODELTYPE_TIMEDPROXYMINE 0x6e
#define MODELTYPE_PHOENIX        0x6f
#define MODELTYPE_CALLISTO       0x70
#define MODELTYPE_RCP120         0x71
#define MODELTYPE_LASER          0x72
#define MODELTYPE_GRENADE        0x73
#define MODELTYPE_ECMMINE        0x74
#define MODELTYPE_UPLINK         0x75
#define MODELTYPE_REMOTEMINE     0x76
#define MODELTYPE_TARGET         0x8c
#define MODELTYPE_BB             0xbb
#define MODELTYPE_WIREFENCE      0xc8
#define MODELTYPE_HAND           0xfa

#define MODFILE_SOLO    1
#define MODFILE_MPSETUP 2
#define MODFILE_GLOBAL  4

#define MOVEMODE_WALK     0
#define MOVEMODE_BIKE     3
#define MOVEMODE_GRAB     4
#define MOVEMODE_CUTSCENE 5

#define MPBODY_DARK_COMBAT      0x00
#define MPBODY_DARK_TRENCH      0x01
#define MPBODY_DARK_FROCK       0x02
#define MPBODY_DARK_RIPPED      0x03
#define MPBODY_DARK_AF1         0x04
#define MPBODY_DARK_LEATHER     0x05
#define MPBODY_DARK_NEGOTIATOR  0x06
#define MPBODY_DARKWET          0x07
#define MPBODY_DARKAQUALUNG     0x08
#define MPBODY_DARKSNOW         0x09
#define MPBODY_DARKLAB          0x0a
#define MPBODY_THEKING          0x0b
#define MPBODY_ELVIS1           0x0c
#define MPBODY_ELVISWAISTCOAT   0x0d
#define MPBODY_CARRINGTON       0x0e
#define MPBODY_CARREVENINGSUIT  0x0f
#define MPBODY_MRBLONDE         0x10
#define MPBODY_CASSANDRA        0x11
#define MPBODY_TRENT            0x12
#define MPBODY_JONATHAN         0x13
#define MPBODY_CILABTECH        0x14
#define MPBODY_CIFEMTECH        0x15
#define MPBODY_CISOLDIER        0x16
#define MPBODY_DDSHOCK          0x17
#define MPBODY_FEM_GUARD        0x18
#define MPBODY_DD_SECGUARD      0x19
#define MPBODY_DD_GUARD         0x1a
#define MPBODY_DD_SHOCK_INF     0x1b
#define MPBODY_SECRETARY        0x1c
#define MPBODY_OFFICEWORKER     0x1d
#define MPBODY_OFFICEWORKER2    0x1e
#define MPBODY_NEGOTIATOR       0x1f
#define MPBODY_DDSNIPER         0x20
#define MPBODY_G5_GUARD         0x21
#define MPBODY_G5_SWAT_GUARD    0x22
#define MPBODY_CIAGUY           0x23
#define MPBODY_FBIGUY           0x24
#define MPBODY_AREA51GUARD      0x25
#define MPBODY_A51TROOPER       0x26
#define MPBODY_A51AIRMAN        0x27
#define MPBODY_OVERALL          0x28
#define MPBODY_STRIPES          0x29
#define MPBODY_LABTECH          0x2a
#define MPBODY_FEMLABTECH       0x2b
#define MPBODY_DD_LABTECH       0x2c
#define MPBODY_BIOTECH          0x2d
#define MPBODY_ALASKAN_GUARD    0x2e
#define MPBODY_PILOTAF1         0x2f
#define MPBODY_STEWARD          0x30
#define MPBODY_STEWARDESS       0x31
#define MPBODY_STEWARDESS_COAT  0x32
#define MPBODY_PRESIDENT        0x33
#define MPBODY_NSA_LACKEY       0x34
#define MPBODY_PRES_SECURITY    0x35
#define MPBODY_PRESIDENT_CLONE2 0x36
#define MPBODY_PELAGIC_GUARD    0x37
#define MPBODY_MAIAN_SOLDIER    0x38
#define MPBODY_CONNERY          0x39
#define MPBODY_MOORE            0x3a
#define MPBODY_DALTON           0x3b
#define MPBODY_DJBOND           0x3c

#define MPBOTCOMMAND_FOLLOW   0
#define MPBOTCOMMAND_ATTACK   1
#define MPBOTCOMMAND_DEFEND   2
#define MPBOTCOMMAND_HOLD     3
#define MPBOTCOMMAND_NORMAL   4
#define MPBOTCOMMAND_DOWNLOAD 5
#define MPBOTCOMMAND_GETCASE  6
#define MPBOTCOMMAND_TAGBOX   7
#define MPBOTCOMMAND_SAVECASE 8
#define MPBOTCOMMAND_DEFHILL  9
#define MPBOTCOMMAND_HOLDHILL 10
#define MPBOTCOMMAND_GETCASE2 11
#define MPBOTCOMMAND_POPCAP   12
#define MPBOTCOMMAND_PROTECT  13

#define MPCONFIG_TEMPLE      0x00
#define MPCONFIG_PISTOLS     0x01
#define MPCONFIG_FARSIGHT    0x02
#define MPCONFIG_DRUGGUN     0x03
#define MPCONFIG_SLAYER      0x04
#define MPCONFIG_CLOAKING    0x05
#define MPCONFIG_SLOWMO      0x06
#define MPCONFIG_NOSHIELD    0x07
#define MPCONFIG_BRIEFCASE   0x08
#define MPCONFIG_SKEDARKING  0x09
#define MPCONFIG_FLAGS       0x0a
#define MPCONFIG_SIMULANTS   0x0b
#define MPCONFIG_AUTOMATICS  0x0c
#define MPCONFIG_ROCKETS     0x0d
#define MPCONFIG_CHALLENGE01 0x0e
#define MPCONFIG_CHALLENGE02 0x0f
#define MPCONFIG_CHALLENGE03 0x10
#define MPCONFIG_CHALLENGE04 0x11
#define MPCONFIG_CHALLENGE05 0x12
#define MPCONFIG_CHALLENGE06 0x13
#define MPCONFIG_CHALLENGE07 0x14
#define MPCONFIG_CHALLENGE08 0x15
#define MPCONFIG_CHALLENGE09 0x16
#define MPCONFIG_CHALLENGE10 0x17
#define MPCONFIG_CHALLENGE11 0x18
#define MPCONFIG_CHALLENGE12 0x19
#define MPCONFIG_CHALLENGE13 0x1a
#define MPCONFIG_CHALLENGE14 0x1b
#define MPCONFIG_CHALLENGE15 0x1c
#define MPCONFIG_CHALLENGE16 0x1d
#define MPCONFIG_CHALLENGE17 0x1e
#define MPCONFIG_CHALLENGE18 0x1f
#define MPCONFIG_CHALLENGE19 0x20
#define MPCONFIG_CHALLENGE20 0x21
#define MPCONFIG_CHALLENGE21 0x22
#define MPCONFIG_CHALLENGE22 0x23
#define MPCONFIG_CHALLENGE23 0x24
#define MPCONFIG_CHALLENGE24 0x25
#define MPCONFIG_CHALLENGE25 0x26
#define MPCONFIG_CHALLENGE26 0x27
#define MPCONFIG_CHALLENGE27 0x28
#define MPCONFIG_CHALLENGE28 0x29
#define MPCONFIG_CHALLENGE29 0x2a
#define MPCONFIG_CHALLENGE30 0x2b

#define MPDISPLAYOPTION_HIGHLIGHTPLAYERS 0x01
#define MPDISPLAYOPTION_HIGHLIGHTPICKUPS 0x02
#define MPDISPLAYOPTION_RADAR            0x04
#define MPDISPLAYOPTION_HIGHLIGHTTEAMS   0x08

// Features are things that can be unlocked
#define MPFEATURE_WEAPON_FARSIGHT        0x01
#define MPFEATURE_WEAPON_TRANQUILIZER    0x02
#define MPFEATURE_WEAPON_SUPERDRAGON     0x03
#define MPFEATURE_WEAPON_SLAYER          0x04
#define MPFEATURE_WEAPON_FALCON2SILENCED 0x05
#define MPFEATURE_WEAPON_FALCON2SCOPE    0x06
#define MPFEATURE_WEAPON_MAULER          0x07
#define MPFEATURE_WEAPON_PHOENIX         0x08
#define MPFEATURE_WEAPON_DY357LX         0x09
#define MPFEATURE_WEAPON_CALLISTO        0x0a
#define MPFEATURE_WEAPON_LAPTOPGUN       0x0b
#define MPFEATURE_WEAPON_K7AVENGER       0x0c
#define MPFEATURE_WEAPON_RCP120          0x0d
#define MPFEATURE_WEAPON_SHOTGUN         0x0e
#define MPFEATURE_WEAPON_REAPER          0x0f
#define MPFEATURE_WEAPON_DEVASTATOR      0x10
#define MPFEATURE_WEAPON_CROSSBOW        0x11
#define MPFEATURE_WEAPON_NBOMB           0x12
#define MPFEATURE_WEAPON_PROXIMITYMINE   0x13
#define MPFEATURE_WEAPON_REMOTEMINE      0x14
#define MPFEATURE_WEAPON_XRAYSCANNER     0x15
#define MPFEATURE_WEAPON_SHIELD          0x16
#define MPFEATURE_WEAPON_CLOAKINGDEVICE  0x17
#define MPFEATURE_WEAPON_COMBATBOOST     0x18
#define MPFEATURE_SIMDIFF_HARD           0x19
#define MPFEATURE_SIMDIFF_PERFECT        0x1a
#define MPFEATURE_1B                     0x1b
#define MPFEATURE_SIMDIFF_DARK           0x1c
#define MPFEATURE_SLOWMOTION             0x1d
#define MPFEATURE_ONEHITKILLS            0x1e
#define MPFEATURE_1F                     0x1f
#define MPFEATURE_20                     0x20
#define MPFEATURE_21                     0x21
#define MPFEATURE_22                     0x22
#define MPFEATURE_STAGE_CARPARK          0x23
#define MPFEATURE_STAGE_COMPLEX          0x24
#define MPFEATURE_STAGE_WAREHOUSE        0x25
#define MPFEATURE_STAGE_RAVINE           0x26
#define MPFEATURE_STAGE_TEMPLE           0x27
#define MPFEATURE_STAGE_G5BUILDING       0x28
#define MPFEATURE_STAGE_GRID             0x29
#define MPFEATURE_STAGE_FELICITY         0x2a
#define MPFEATURE_STAGE_VILLA            0x2b
#define MPFEATURE_STAGE_SEWERS           0x2c
#define MPFEATURE_STAGE_RUINS            0x2d
#define MPFEATURE_STAGE_BASE             0x2e
#define MPFEATURE_2F                     0x2f
#define MPFEATURE_STAGE_FORTRESS         0x30
#define MPFEATURE_31                     0x31
#define MPFEATURE_32                     0x32
#define MPFEATURE_33                     0x33
#define MPFEATURE_34                     0x34
#define MPFEATURE_35                     0x35
#define MPFEATURE_36                     0x36
#define MPFEATURE_37                     0x37
#define MPFEATURE_38                     0x38
#define MPFEATURE_39                     0x39
#define MPFEATURE_3A                     0x3a
#define MPFEATURE_3B                     0x3b
#define MPFEATURE_3C                     0x3c
#define MPFEATURE_3D                     0x3d
#define MPFEATURE_3E                     0x3e
#define MPFEATURE_3F                     0x3f
#define MPFEATURE_8BOTS                  0x40 // also unlocks the 4 Bonds
#define MPFEATURE_41                     0x41
#define MPFEATURE_42                     0x42
#define MPFEATURE_43                     0x43
#define MPFEATURE_44                     0x44
#define MPFEATURE_45                     0x45
#define MPFEATURE_46                     0x46
#define MPFEATURE_47                     0x47
#define MPFEATURE_48                     0x48
#define MPFEATURE_49                     0x49
#define MPFEATURE_4A                     0x4a
#define MPFEATURE_4B                     0x4b
#define MPFEATURE_4C                     0x4c
#define MPFEATURE_4D                     0x4d
#define MPFEATURE_4E                     0x4e
#define MPFEATURE_WEAPON_LASER           0x4f

#define MPHEAD_DARK_COMBAT  0x00
#define MPHEAD_DARK_FROCK   0x01
#define MPHEAD_DARKAQUA     0x02
#define MPHEAD_DARK_SNOW    0x03
#define MPHEAD_ELVIS        0x04
#define MPHEAD_ELVIS_GOGS   0x05
#define MPHEAD_CARRINGTON   0x06
#define MPHEAD_MRBLONDE     0x07
#define MPHEAD_CASSANDRA    0x08
#define MPHEAD_TRENT        0x09
#define MPHEAD_JONATHAN     0x0a
#define MPHEAD_VD           0x0b
#define MPHEAD_PRESIDENT    0x0c
#define MPHEAD_DDSHOCK      0x0d
#define MPHEAD_BIOTECH      0x0e
#define MPHEAD_DDSNIPER     0x0f
#define MPHEAD_A51FACEPLATE 0x10
#define MPHEAD_SECRETARY    0x11
#define MPHEAD_FEM_GUARD    0x12
#define MPHEAD_FEM_GUARD2   0x13
#define MPHEAD_MAIAN_S      0x14
#define MPHEAD_JON          0x15
#define MPHEAD_BEAU1        0x16
#define MPHEAD_ROSS         0x17
#define MPHEAD_MARK2        0x18
#define MPHEAD_CHRIST       0x19
#define MPHEAD_RUSS         0x1a
#define MPHEAD_DARLING      0x1b
#define MPHEAD_BRIAN        0x1c
#define MPHEAD_JAMIE        0x1d
#define MPHEAD_DUNCAN2      0x1e
#define MPHEAD_KEITH        0x1f
#define MPHEAD_STEVEM       0x20
#define MPHEAD_GRANT        0x21
#define MPHEAD_PENNY        0x22
#define MPHEAD_DAVEC        0x23
#define MPHEAD_JONES        0x24
#define MPHEAD_GRAHAM       0x25
#define MPHEAD_ROBERT       0x26
#define MPHEAD_NEIL2        0x27
#define MPHEAD_SHAUN        0x28
#define MPHEAD_ROBIN        0x29
#define MPHEAD_COOK         0x2a
#define MPHEAD_PRYCE        0x2b
#define MPHEAD_SILKE        0x2c
#define MPHEAD_SMITH        0x2d
#define MPHEAD_GARETH       0x2e
#define MPHEAD_MURCHIE      0x2f
#define MPHEAD_WONG         0x30
#define MPHEAD_CARTER       0x31
#define MPHEAD_TINTIN       0x32
#define MPHEAD_MUNTON       0x33
#define MPHEAD_STAMPER      0x34
#define MPHEAD_PHELPS       0x35
#define MPHEAD_ALEX         0x36
#define MPHEAD_JULIANNE     0x37
#define MPHEAD_LAURA        0x38
#define MPHEAD_EDMCG        0x39
#define MPHEAD_ANKA         0x3a
#define MPHEAD_LESLIE_S     0x3b
#define MPHEAD_MATT_C       0x3c
#define MPHEAD_PEER_S       0x3d
#define MPHEAD_EILEEN_T     0x3e
#define MPHEAD_ANDY_R       0x3f
#define MPHEAD_BEN_R        0x40
#define MPHEAD_STEVE_K      0x41
#define MPHEAD_SANCHEZ      0x42
#define MPHEAD_TIM          0x43
#define MPHEAD_KEN          0x44
#define MPHEAD_EILEEN_H     0x45
#define MPHEAD_SCOTT_H      0x46
#define MPHEAD_JOEL         0x47
#define MPHEAD_GRIFFEY      0x48
#define MPHEAD_MOTO         0x49
#define MPHEAD_WINNER       0x4a

#define MPLOCKTYPE_NONE       0
#define MPLOCKTYPE_LASTWINNER 1
#define MPLOCKTYPE_LASTLOSER  2
#define MPLOCKTYPE_RANDOM     3
#define MPLOCKTYPE_PLAYER     4
#define MPLOCKTYPE_CHALLENGE  5

#define MPOPTION_ONEHITKILLS            0x00000001
#define MPOPTION_TEAMSENABLED           0x00000002
#define MPOPTION_NORADAR                0x00000004
#define MPOPTION_NOAUTOAIM              0x00000008
#define MPOPTION_NOPLAYERHIGHLIGHT      0x00000010
#define MPOPTION_NOPICKUPHIGHLIGHT      0x00000020
#define MPOPTION_SLOWMOTION_ON          0x00000040
#define MPOPTION_SLOWMOTION_SMART       0x00000080
#define MPOPTION_FASTMOVEMENT           0x00000100
#define MPOPTION_DISPLAYTEAM            0x00000200
#define MPOPTION_KILLSSCORE             0x00000400
#define MPOPTION_HTB_HIGHLIGHTBRIEFCASE 0x00000800
#define MPOPTION_HTB_SHOWONRADAR        0x00001000
#define MPOPTION_CTC_SHOWONRADAR        0x00002000
#define MPOPTION_KOH_HILLONRADAR        0x00004000
#define MPOPTION_KOH_MOBILEHILL         0x00008000
#define MPOPTION_00010000               0x00010000
#define MPOPTION_HTM_HIGHLIGHTTERMINAL  0x00020000
#define MPOPTION_HTM_SHOWONRADAR        0x00040000
#define MPOPTION_PAC_HIGHLIGHTTARGET    0x00080000
#define MPOPTION_PAC_SHOWONRADAR        0x00100000

#define MPPAUSEMODE_UNPAUSED 0
#define MPPAUSEMODE_PAUSED   1
#define MPPAUSEMODE_GAMEOVER 2

#define MPPLAYERTITLE_BEGINNER     0
#define MPPLAYERTITLE_TRAINEE      1
#define MPPLAYERTITLE_AMATEUR      2
#define MPPLAYERTITLE_ROOKIE       3
#define MPPLAYERTITLE_NOVICE       4
#define MPPLAYERTITLE_TROOPER      5
#define MPPLAYERTITLE_AGENT        6
#define MPPLAYERTITLE_STARAGENT    7
#define MPPLAYERTITLE_SPECIALAGENT 8
#define MPPLAYERTITLE_EXPERT       9
#define MPPLAYERTITLE_VETERAN      10
#define MPPLAYERTITLE_PROFESSIONAL 11
#define MPPLAYERTITLE_DANGEROUS    12
#define MPPLAYERTITLE_DEADLY       13
#define MPPLAYERTITLE_KILLER       14
#define MPPLAYERTITLE_ASSASSIN     15
#define MPPLAYERTITLE_LETHAL       16
#define MPPLAYERTITLE_ELITE        17
#define MPPLAYERTITLE_INVINCIBLE   18
#define MPPLAYERTITLE_NEARPERFECT  19
#define MPPLAYERTITLE_PERFECT      20

#define MPQUICKTEAM_PLAYERSONLY    0
#define MPQUICKTEAM_PLAYERSANDSIMS 1
#define MPQUICKTEAM_PLAYERSTEAMS   2
#define MPQUICKTEAM_PLAYERSVSSIMS  3
#define MPQUICKTEAM_PLAYERSIMTEAMS 4
#define MPQUICKTEAM_NONE           5

#define MPSCENARIO_COMBAT           0
#define MPSCENARIO_HOLDTHEBRIEFCASE 1
#define MPSCENARIO_HACKERCENTRAL    2
#define MPSCENARIO_POPACAP          3
#define MPSCENARIO_KINGOFTHEHILL    4
#define MPSCENARIO_CAPTURETHECASE   5

#define MPTEAM_0 0
#define MPTEAM_1 1
#define MPTEAM_2 2
#define MPTEAM_3 3
#define MPTEAM_4 4
#define MPTEAM_5 5
#define MPTEAM_6 6
#define MPTEAM_7 7

#define MPWEAPON_NONE             0x00
#define MPWEAPON_FALCON2          0x01
#define MPWEAPON_FALCON2_SILENCER 0x02
#define MPWEAPON_FALCON2_SCOPE    0x03
#define MPWEAPON_MAGSEC4          0x04
#define MPWEAPON_MAULER           0x05
#define MPWEAPON_PHOENIX          0x06
#define MPWEAPON_DY357MAGNUM      0x07
#define MPWEAPON_DY357LX          0x08
#define MPWEAPON_CMP150           0x09
#define MPWEAPON_CYCLONE          0x0a
#define MPWEAPON_CALLISTO         0x0b
#define MPWEAPON_RCP120           0x0c
#define MPWEAPON_LAPTOPGUN        0x0d
#define MPWEAPON_DRAGON           0x0e
#define MPWEAPON_K7AVENGER        0x0f
#define MPWEAPON_AR34             0x10
#define MPWEAPON_SUPERDRAGON      0x11
#define MPWEAPON_SHOTGUN          0x12
#define MPWEAPON_REAPER           0x13
#define MPWEAPON_SNIPERRIFLE      0x14
#define MPWEAPON_FARSIGHT         0x15
#define MPWEAPON_DEVASTATOR       0x16
#define MPWEAPON_ROCKETLAUNCHER   0x17
#define MPWEAPON_SLAYER           0x18
#define MPWEAPON_COMBATKNIFE      0x19
#define MPWEAPON_CROSSBOW         0x1a
#define MPWEAPON_TRANQUILIZER     0x1b
#define MPWEAPON_GRENADE          0x1c
#define MPWEAPON_NBOMB            0x1d
#define MPWEAPON_TIMEDMINE        0x1e
#define MPWEAPON_PROXIMITYMINE    0x1f
#define MPWEAPON_REMOTEMINE       0x20
#define MPWEAPON_LASER            0x21
#define MPWEAPON_XRAYSCANNER      0x22
#define MPWEAPON_CLOAKINGDEVICE   0x23
#define MPWEAPON_COMBATBOOST      0x24
#define MPWEAPON_SHIELD           0x25
#define MPWEAPON_DISABLED         0x26

#define MUSIC_NONE                    0x00
#define MUSIC_TITLE2                  0x01
#define MUSIC_EXTRACTION              0x02
#define MUSIC_PAUSEMENU               0x03
#define MUSIC_DEFENSE                 0x04
#define MUSIC_INVESTIGATION_SFX       0x05
#define MUSIC_ESCAPE                  0x06
#define MUSIC_DEEPSEA                 0x07
#define MUSIC_DDTOWER_SFX             0x08
#define MUSIC_DEFECTION               0x09
#define MUSIC_DEATH_SOLO              0x0a
#define MUSIC_DEFECTION_INTRO_SFX     0x0b
#define MUSIC_VILLA                   0x0c
#define MUSIC_CI                      0x0d
#define MUSIC_CHICAGO                 0x0e
#define MUSIC_G5                      0x0f
#define MUSIC_DEFECTION_X             0x10
#define MUSIC_EXTRACTION_X            0x11
#define MUSIC_INVESTIGATION           0x12
#define MUSIC_INVESTIGATION_X         0x13
#define MUSIC_INFILTRATION            0x14
#define MUSIC_DEATH_BETA              0x15
#define MUSIC_RESCUE                  0x16
#define MUSIC_AIRBASE                 0x17
#define MUSIC_AIRFORCEONE             0x18
#define MUSIC_DEATH_MP                0x19
#define MUSIC_EXTRACTION_OUTRO_SFX    0x1a
#define MUSIC_MISSION_UNKNOWN         0x1b
#define MUSIC_PELAGIC                 0x1c
#define MUSIC_CRASHSITE               0x1d
#define MUSIC_CRASHSITE_X             0x1e
#define MUSIC_ATTACKSHIP              0x1f
#define MUSIC_ATTACKSHIP_X            0x20
#define MUSIC_SKEDARRUINS             0x21
#define MUSIC_DEFECTION_INTRO         0x22
#define MUSIC_DEFECTION_OUTRO         0x23
#define MUSIC_DEFENSE_X               0x24
#define MUSIC_INVESTIGATION_INTRO     0x25
#define MUSIC_INVESTIGATION_OUTRO     0x26
#define MUSIC_VILLA_X                 0x27
#define MUSIC_CHICAGO_X               0x28
#define MUSIC_G5_X                    0x29
#define MUSIC_INFILTRATION_X          0x2a
#define MUSIC_CHICAGO_OUTRO           0x2b
#define MUSIC_EXTRACTION_OUTRO        0x2c
#define MUSIC_EXTRACTION_INTRO        0x2d
#define MUSIC_G5_INTRO                0x2e
#define MUSIC_CHICAGO_INTRO           0x2f
#define MUSIC_VILLA_INTRO1            0x30
#define MUSIC_INFILTRATION_INTRO      0x31
#define MUSIC_RESCUE_X                0x32
#define MUSIC_ESCAPE_X                0x33
#define MUSIC_AIRBASE_X               0x34
#define MUSIC_AIRFORCEONE_X           0x35
#define MUSIC_PELAGIC_X               0x36
#define MUSIC_DEEPSEA_X               0x37
#define MUSIC_SKEDARRUINS_X           0x38
#define MUSIC_AIRBASE_OUTRO_LONG      0x39
#define MUSIC_DARK_COMBAT             0x3a
#define MUSIC_SKEDAR_MYSTERY          0x3b
#define MUSIC_DEEPSEA_BETA            0x3c
#define MUSIC_CI_OPERATIVE            0x3d
#define MUSIC_DATADYNE_ACTION         0x3e
#define MUSIC_MAIAN_TEARS             0x3f
#define MUSIC_ALIEN_CONFLICT          0x40
#define MUSIC_ESCAPE_INTRO            0x41
#define MUSIC_RESCUE_OUTRO            0x42
#define MUSIC_VILLA_INTRO2            0x43
#define MUSIC_VILLA_INTRO3            0x44
#define MUSIC_G5_OUTRO                0x45
#define MUSIC_G5_MIDCUTSCENE          0x46
#define MUSIC_MISSION_FAILED          0x47
#define MUSIC_COMBATSIM_MENU          0x48
#define MUSIC_MISSION_SUCCESS         0x49
#define MUSIC_CRASHSITE_INTRO         0x4a
#define MUSIC_AIRBASE_INTRO           0x4b
#define MUSIC_ATTACKSHIP_INTRO        0x4c
#define MUSIC_DEEPSEA_MIDCUTSCENE     0x4d
#define MUSIC_AIRFORCEONE_INTRO       0x4e
#define MUSIC_ATTACKSHIP_OUTRO        0x4f
#define MUSIC_ESCAPE_MIDCUTSCENE      0x50
#define MUSIC_RESCUE_INTRO            0x51
#define MUSIC_DEEPSEA_INTRO           0x52
#define MUSIC_INFILTRATION_OUTRO      0x53
#define MUSIC_PELAGIC_INTRO           0x54
#define MUSIC_ESCAPE_OUTRO_LONG       0x55
#define MUSIC_DEFENSE_INTRO           0x56
#define MUSIC_CRASHSITE_OUTRO         0x57
#define MUSIC_CREDITS                 0x58
#define MUSIC_MAINMENU                0x59
#define MUSIC_DEEPSEA_OUTRO           0x5a
#define MUSIC_AIRFORCEONE_MIDCUTSCENE 0x5b
#define MUSIC_PELAGIC_OUTRO           0x5c
#define MUSIC_AIRFORCEONE_OUTRO       0x5d
#define MUSIC_SKEDARRUINS_INTRO       0x5e
#define MUSIC_BETA_NOTE               0x5f
#define MUSIC_AIRBASE_OUTRO           0x60
#define MUSIC_DEFENSE_OUTRO           0x61
#define MUSIC_SKEDARRUINS_OUTRO       0x62
#define MUSIC_VILLA_OUTRO             0x63
#define MUSIC_SKEDARRUINS_KING        0x64
#define MUSIC_CI_TRAINING             0x65
#define MUSIC_CRASHSITE_WIND          0x66
#define MUSIC_COMBATSIM_COMPLETE      0x67
#define MUSIC_OCEAN                   0x68
#define MUSIC_WIND                    0x69
#define MUSIC_TRAFFIC                 0x6a
#define MUSIC_TITLE1                  0x6b
#define MUSIC_CI_INTRO                0x6c
#define MUSIC_INFILTRATION_SFX        0x6d
#define MUSIC_DEEPSEA_SFX             0x6e
#define MUSIC_AIRFORCEONE_SFX         0x6f
#define MUSIC_ATTACKSHIP_SFX          0x70
#define MUSIC_SKEDAR_WIND             0x71
#define MUSIC_ESCAPE_OUTRO_SFX        0x72
#define MUSIC_A51_LOUDSPEAKER1        0x73
#define MUSIC_A51_LOUDSPEAKER2        0x74
#define MUSIC_BETA_MELODY             0x75
#define MUSIC_ESCAPE_OUTRO_SHORT      0x76

#define NUM_AICOMMANDS       481
#define NUM_BODIES           151
#define NUM_CHALLENGES       30
#define NUM_CHEATS           42
#define NUM_EXPLOSIONTYPES   26
#define NUM_FILES            2014
#define NUM_FIRESLOTS        20
#define NUM_MPBEAUHEADS      5
#define NUM_MPBOTCOMMANDS    14
#define NUM_MPBODIES         61
#define NUM_MPHEADS          75
#define NUM_MPPRESETS        14
#define NUM_MPTRACKS         42
#define NUM_RACES            5
#define NUM_SMOKETYPES       23
#define NUM_SOLONORMALSTAGES 17
#define NUM_SOLOSTAGES       21
#define NUM_STAGES           90
#define NUM_TEXTURES         3504
#define NUM_WEAPONS          94

#define OBJECTIVE_INCOMPLETE 0
#define OBJECTIVE_COMPLETE   1
#define OBJECTIVE_FAILED     2

#define OBJECTIVEFLAG_AUTOCOMPLETE 0x01

// obj->flags
#define OBJFLAG_00000001            0x00000001 // Editor: "Fall to Ground"
#define OBJFLAG_00000002            0x00000002 // Editor: "In Air Rotated 90 Deg Upside-Down"
#define OBJFLAG_00000004            0x00000004 // Editor: "In Air Upside-Down"
#define OBJFLAG_00000008            0x00000008 // Editor: "In Air"
#define OBJFLAG_00000010            0x00000010 // Editor: "Scale to Pad Bounds"
#define OBJFLAG_00000020            0x00000020 // Editor: "X to Pad Bounds"
#define OBJFLAG_00000040            0x00000040 // Editor: "Y to Pad Bounds"
#define OBJFLAG_00000080            0x00000080 // Editor: "Z to Pad Bounds"
#define OBJFLAG_00000100            0x00000100 // G5 mines, Air Base brown door, AF1 grate and escape door, Defense shuttle, Ruins mines, MBR lift door. Editor suggests "Force Collisions" but this seems wrong
#define OBJFLAG_00000200            0x00000200 // Editor: "Special Environment Mapping"
#define OBJFLAG_ILLUMINATED         0x00000400
#define OBJFLAG_00000800            0x00000800 // Editor: "Free Standing Glass"
#define OBJFLAG_00001000            0x00001000 // Editor: "Absolute Position"
#define OBJFLAG_00002000            0x00002000 // AF1 commhubs. Editor suggests "Weapon Not Dropped"
#define OBJFLAG_ASSIGNEDTOCHR       0x00004000
#define OBJFLAG_00008000            0x00008000 // Editor: "Embedded Object"
#define OBJFLAG_00010000            0x00010000 // Not used in scripts
#define OBJFLAG_INVINCIBLE          0x00020000
#define OBJFLAG_COLLECTABLE         0x00040000
#define OBJFLAG_00080000            0x00080000 // Thrown laptop?
#define OBJFLAG_UNCOLLECTABLE       0x00100000
#define OBJFLAG_00200000            0x00200000 // Editor: "Bounce and Destroy If Shot"
#define OBJFLAG_00400000            0x00400000 // Not used in scripts
#define OBJFLAG_00800000            0x00800000 // Not used in scripts
#define OBJFLAG_01000000            0x01000000 // Editor: "Embedded Object"
#define OBJFLAG_CANNOT_ACTIVATE     0x02000000 // Makes it do nothing if player presses B on object. Used mostly for doors.
#define OBJFLAG_04000000            0x04000000 // Editor: "AI Sees Through Door/Object"
#define OBJFLAG_08000000            0x08000000 // Not used in scripts
#define OBJFLAG_DEACTIVATED         0x10000000
#define OBJFLAG_DOOR_HASPORTAL      0x10000000
#define OBJFLAG_WEAPON_10000000     0x10000000
#define OBJFLAG_ESCSTEP_ZALIGNED    0x10000000
#define OBJFLAG_20000000            0x20000000 // Editor: "Door Opens Backwards/Special Function/Conceal Weapon"
#define OBJFLAG_CAMERA_DISABLED     0x20000000
#define OBJFLAG_DOOR_OPENTOFRONT    0x20000000
#define OBJFLAG_40000000            0x40000000
#define OBJFLAG_CAMERA_BONDINVIEW   0x40000000
#define OBJFLAG_DOOR_KEEPOPEN       0x40000000 // Editor: "Door open by default/Empty weapon"
#define OBJFLAG_LIFT_TRIGGERDISABLE 0x40000000
#define OBJFLAG_80000000            0x80000000
#define OBJFLAG_DOOR_TWOWAY         0x80000000 // Door swings in both directions
#define OBJFLAG_CHOPPER_INACTIVE    0x80000000 // Or lift disabled, or hovercar something

// obj->flags2
#define OBJFLAG2_00000001     0x00000001 // Used only in CI Training
#define OBJFLAG2_00000002     0x00000002 // Ruins spikes
#define OBJFLAG2_00000004     0x00000004 // Defense hostage doors - openable by AI?
#define OBJFLAG2_00000008     0x00000008 // Editor: "Don't load in Multiplayer"
#define OBJFLAG2_EXCLUDE_A    0x00000010
#define OBJFLAG2_EXCLUDE_SA   0x00000020
#define OBJFLAG2_EXCLUDE_PA   0x00000040
#define OBJFLAG2_EXCLUDE_PD   0x00000080
#define OBJFLAG2_00000100     0x00000100 // Editor: "Immobile"
#define OBJFLAG2_00000200     0x00000200 // Editor: "Mines"
#define OBJFLAG2_LINKEDTOSAFE 0x00000400 // Applied to safe door and item
#define OBJFLAG2_00000800     0x00000800 // Editor: "Don't activate if clipping gap Jo/Object"
#define OBJFLAG2_00001000     0x00001000 // Investigation CMP150s, Air Base safe item and shield
#define OBJFLAG2_00002000     0x00002000 // Ruins commhub - used as a "shown message" flag
#define OBJFLAG2_00004000     0x00004000 // Editor: "Immune to Gunfire"
#define OBJFLAG2_SHOOTTHROUGH 0x00008000
#define OBJFLAG2_DRAWONTOP    0x00010000
#define OBJFLAG2_00020000     0x00020000 // G5 mine, Air Base mine
#define OBJFLAG2_00040000     0x00040000 // Only used in CI training
#define OBJFLAG2_INVISIBLE    0x00080000
#define OBJFLAG2_00100000     0x00100000 // Editor: "Bulletproof Glass"
#define OBJFLAG2_00200000     0x00200000 // Editor: "Immune to Explosions" (Ruins spikes)
#define OBJFLAG2_EXCLUDE_2P   0x00400000
#define OBJFLAG2_EXCLUDE_3P   0x00800000
#define OBJFLAG2_EXCLUDE_4P   0x01000000
#define OBJFLAG2_THROWTHROUGH 0x02000000 // Rockets/mines/grenades etc pass through object
#define OBJFLAG2_04000000     0x04000000 // Used quite a lot - gravity?
#define OBJFLAG2_LOCKEDFRONT  0x08000000 // One-way door lock
#define OBJFLAG2_LOCKEDBACK   0x10000000 // One-way door lock
#define OBJFLAG2_AICANNOTUSE  0x20000000
#define OBJFLAG2_AIRLOCKDOOR  0x40000000 // Door waits for sibling to close before it can open
#define OBJFLAG2_80000000     0x80000000 // Attack Ship glass

// obj->flags3
#define OBJFLAG3_PUSHABLE           0x00000001
#define OBJFLAG3_GRABBABLE          0x00000002
#define OBJFLAG3_DOOR_STICKY        0x00000004 // eg. Skedar Ruins
#define OBJFLAG3_00000008           0x00000008 // Not used in scripts
#define OBJFLAG3_00000010           0x00000010 // Used heaps
#define OBJFLAG3_AUTOCUTSCENESOUNDS 0x00000020 // For doors and objs - play default open/close noises
#define OBJFLAG3_RTRACKED_YELLOW    0x00000040
#define OBJFLAG3_00000080           0x00000080 // Not used in scripts
#define OBJFLAG3_00000100           0x00000100 // Not used in scripts
#define OBJFLAG3_00000200           0x00000200 // Not used in scripts
#define OBJFLAG3_WALKTHROUGH        0x00000400
#define OBJFLAG3_RTRACKED_BLUE      0x00000800
#define OBJFLAG3_SHOWSHIELD         0x00001000 // Show shield effect around object (always)
#define OBJFLAG3_00002000           0x00002000 // Not used in scripts
#define OBJFLAG3_00004000           0x00004000 // Not used in scripts
#define OBJFLAG3_00008000           0x00008000 // Not used in scripts
#define OBJFLAG3_00010000           0x00010000 // Editor: "Can be activated"
#define OBJFLAG3_00020000           0x00020000 // Equivalent to CHRH2FLAG_0002
#define OBJFLAG3_00040000           0x00040000 // Not used in scripts
#define OBJFLAG3_00080000           0x00080000 // Not used in scripts
#define OBJFLAG3_00100000           0x00100000 // Ruins spikes
#define OBJFLAG3_00200000           0x00200000 // Not used in scripts
#define OBJFLAG3_00400000           0x00400000 // Investigation tech items
#define OBJFLAG3_00800000           0x00800000 // Not used in scripts
#define OBJFLAG3_01000000           0x01000000 // Not used in scripts
#define OBJFLAG3_GEOTYPE3           0x02000000 // If set then obj uses tiletype3 else tiletype2
#define OBJFLAG3_04000000           0x04000000 // Not used in scripts
#define OBJFLAG3_08000000           0x08000000 // Not used in scripts
#define OBJFLAG3_10000000           0x10000000 // Editor: "Keep Collisions After Fully Destroyed"
#define OBJFLAG3_20000000           0x20000000 // Not used in scripts
#define OBJFLAG3_40000000           0x40000000 // Editor: "Door Highlighted IR Scanner"
#define OBJFLAG3_80000000           0x80000000 // Not used in scripts

// obj->hidden
#define OBJHFLAG_LIFTDOOR          0x00000001
#define OBJHFLAG_00000004          0x00000004
#define OBJHFLAG_00000008          0x00000008
#define OBJHFLAG_TAGGED            0x00000010
#define OBJHFLAG_00000040          0x00000040
#define OBJHFLAG_AIRBORNE          0x00000080
#define OBJHFLAG_00000100          0x00000100
#define OBJHFLAG_00000200          0x00000200
#define OBJHFLAG_HASTEXTOVERRIDE   0x00000400
#define OBJHFLAG_00000800          0x00000800
#define OBJHFLAG_00001000          0x00001000
#define OBJHFLAG_PADLOCKEDDOOR     0x00002000
#define OBJHFLAG_ACTIVATED_BY_BOND 0x00004000
#define OBJHFLAG_ACTIVATED_BY_COOP 0x00040000
#define OBJHFLAG_HASOWNER          0x00080000
#define OBJHFLAG_00100000          0x00100000
#define OBJHFLAG_00200000          0x00200000 // Occupied chair?
#define OBJHFLAG_00400000          0x00400000
#define OBJHFLAG_00800000          0x00800000
#define OBJHFLAG_01000000          0x01000000
#define OBJHFLAG_02000000          0x02000000
#define OBJHFLAG_04000000          0x04000000
#define OBJHFLAG_GRABBED           0x08000000
#define OBJHFLAG_20000000          0x20000000 // upper nibble might be a single 4-bit value

// obj->hidden2
#define OBJH2FLAG_RENDEROPAQUE 0x01
#define OBJH2FLAG_RENDERALPHA  0x02 // must be immediately after OBJH2FLAG_RENDEROPAQUE
#define OBJH2FLAG_04           0x04
#define OBJH2FLAG_08           0x08
#define OBJH2FLAG_10           0x10
#define OBJH2FLAG_40           0x40

#define OBJTYPE_DOOR               0x01
#define OBJTYPE_DOORSCALE          0x02
#define OBJTYPE_BASIC              0x03
#define OBJTYPE_KEY                0x04
#define OBJTYPE_ALARM              0x05
#define OBJTYPE_CAMERA             0x06
#define OBJTYPE_AMMOCRATE          0x07
#define OBJTYPE_WEAPON             0x08
#define OBJTYPE_CHR                0x09
#define OBJTYPE_SINGLEMONITOR      0x0a
#define OBJTYPE_MULTIMONITOR       0x0b
#define OBJTYPE_HANGINGMONITORS    0x0c
#define OBJTYPE_AUTOGUN            0x0d
#define OBJTYPE_LINKGUNS           0x0e
#define OBJTYPE_DEBRIS             0x0f
#define OBJTYPE_10                 0x10
#define OBJTYPE_HAT                0x11
#define OBJTYPE_GRENADEPROB        0x12
#define OBJTYPE_LINKLIFTDOOR       0x13
#define OBJTYPE_MULTIAMMOCRATE     0x14
#define OBJTYPE_SHIELD             0x15
#define OBJTYPE_TAG                0x16
#define OBJTYPE_BEGINOBJECTIVE     0x17
#define OBJTYPE_ENDOBJECTIVE       0x18
#define OBJECTIVETYPE_DESTROYOBJ   0x19
#define OBJECTIVETYPE_COMPFLAGS    0x1a
#define OBJECTIVETYPE_FAILFLAGS    0x1b
#define OBJECTIVETYPE_COLLECTOBJ   0x1c
#define OBJECTIVETYPE_THROWOBJ     0x1d
#define OBJECTIVETYPE_HOLOGRAPH    0x1e
#define OBJECTIVETYPE_1F           0x1f
#define OBJECTIVETYPE_ENTERROOM    0x20
#define OBJECTIVETYPE_ATTACHOBJ    0x21
#define OBJTYPE_22                 0x22
#define OBJTYPE_BRIEFING           0x23
#define OBJTYPE_24                 0x24
#define OBJTYPE_RENAMEOBJ          0x25
#define OBJTYPE_PADLOCKEDDOOR      0x26
#define OBJTYPE_TRUCK              0x27
#define OBJTYPE_HELI               0x28
#define OBJTYPE_29                 0x29
#define OBJTYPE_GLASS              0x2a
#define OBJTYPE_SAFE               0x2b
#define OBJTYPE_SAFEITEM           0x2c
#define OBJTYPE_TANK               0x2d
#define OBJTYPE_CAMERA2            0x2e
#define OBJTYPE_TINTEDGLASS        0x2f
#define OBJTYPE_LIFT               0x30
#define OBJTYPE_CONDITIONALSCENERY 0x31
#define OBJTYPE_BLOCKEDPATH        0x32
#define OBJTYPE_HOVERBIKE          0x33
#define OBJTYPE_END                0x34
#define OBJTYPE_HOVERPROP          0x35 // Hovercrates and hoverbeds
#define OBJTYPE_FAN                0x36
#define OBJTYPE_HOVERCAR           0x37 // Datadyne cars, Chicago taxi and limo, and hoverbots
#define OBJTYPE_PADEFFECT          0x38
#define OBJTYPE_CHOPPER            0x39 // Extraction hovercopter and A51 interceptors
#define OBJTYPE_MINE               0x3a
#define OBJTYPE_ESCASTEP           0x3b

#define OPERATOR_LESS_THAN    0
#define OPERATOR_GREATER_THAN 1

#define OPTION_FORWARDPITCH     0x0001
#define OPTION_LOOKAHEAD        0x0002
#define OPTION_SIGHTONSCREEN    0x0004
#define OPTION_AUTOAIM          0x0008
#define OPTION_AIMCONTROL       0x0010
#define OPTION_AMMOONSCREEN     0x0020
#define OPTION_SHOWGUNFUNCTION  0x0040
#define OPTION_HEADROLL         0x0080
#define OPTION_0100             0x0100
#define OPTION_ALWAYSSHOWTARGET 0x0200
#define OPTION_SHOWZOOMRANGE    0x0400
#define OPTION_PAINTBALL        0x0800
#define OPTION_ASKEDSAVEPLAYER  0x4000
#define OPTION_SHOWMISSIONTIME  0x8000

#define OUTFIT_DEFAULT      0x00
#define OUTFIT_ELVIS        0x01
#define OUTFIT_TRENT        0x02 // unused
#define OUTFIT_TRENCH       0x03
#define OUTFIT_FROCK_RIPPED 0x04
#define OUTFIT_FROCK        0x05
#define OUTFIT_LEATHER      0x06
#define OUTFIT_DEEPSEA      0x07
#define OUTFIT_WETSUIT      0x08
#define OUTFIT_SNOW         0x09
#define OUTFIT_LAB          0x0a
#define OUTFIT_STEWARDESS   0x0b
#define OUTFIT_MRBLONDE     0x0c
#define OUTFIT_MAIAN        0x0d
#define OUTFIT_NEGOTIATOR   0x0e // unused by scripts

#define PAD_PRESET 9000

#define PADEFFECT_SPARKS          0x00
#define PADEFFECT_01              0x01 // used only in Escape on a pad containing nothing
#define PADEFFECT_SPLASH          0x02
#define PADEFFECT_SPARKS2         0x03
#define PADEFFECT_SMOKE           0x04
#define PADEFFECT_SMOKE_TEMPORARY 0x05

#define PADFIELD_POS    0x0002
#define PADFIELD_LOOK   0x0004
#define PADFIELD_UP     0x0008
#define PADFIELD_NORMAL 0x0010
#define PADFIELD_BBOX   0x0020
#define PADFIELD_ROOM   0x0040
#define PADFIELD_FLAGS  0x0080
#define PADFIELD_LIFT   0x0100

#define PADFLAG_INTPOS          0x0001
#define PADFLAG_UPALIGNTOX      0x0002
#define PADFLAG_UPALIGNTOY      0x0004
#define PADFLAG_UPALIGNTOZ      0x0008
#define PADFLAG_UPALIGNINVERT   0x0010
#define PADFLAG_LOOKALIGNTOX    0x0020
#define PADFLAG_LOOKALIGNTOY    0x0040
#define PADFLAG_LOOKALIGNTOZ    0x0080
#define PADFLAG_LOOKALIGNINVERT 0x0100
#define PADFLAG_HASBBOXDATA     0x0200
#define PADFLAG_AIWAITLIFT      0x0400
#define PADFLAG_AIONLIFT        0x0800
#define PADFLAG_AIWALKDIRECT    0x1000
#define PADFLAG_AIDROP          0x2000
#define PADFLAG_AIDUCK          0x4000
#define PADFLAG_8000            0x8000
#define PADFLAG_10000           0x10000

#define PATHFLAG_CIRCULAR 1
#define PATHFLAG_FLYING   2
#define PATHFLAG_04       4

#define PAUSEMODE_UNPAUSED  0
#define PAUSEMODE_PAUSING   1
#define PAUSEMODE_PAUSED    3
#define PAUSEMODE_UNPAUSING 5

#define PDMODEPROP_REACTION 0
#define PDMODEPROP_HEALTH   1
#define PDMODEPROP_DAMAGE   2
#define PDMODEPROP_ACCURACY 3

#define PLAYERFLAG_NOCONTROL 0x00000002

#define PORTALCMD_END              0x00
#define PORTALCMD_PUSH             0x01
#define PORTALCMD_POP              0x02
#define PORTALCMD_AND              0x03
#define PORTALCMD_OR               0x04
#define PORTALCMD_NOT              0x05
#define PORTALCMD_XOR              0x06
#define PORTALCMD_14               0x14
#define PORTALCMD_SETMODEVIS       0x1e
#define PORTALCMD_1F               0x1f
#define PORTALCMD_20               0x20
#define PORTALCMD_SETMODEINVIS     0x21
#define PORTALCMD_22               0x22
#define PORTALCMD_23               0x23
#define PORTALCMD_DISABLEROOM      0x24
#define PORTALCMD_DISABLEROOMRANGE 0x25
#define PORTALCMD_LOADROOM         0x26
#define PORTALCMD_LOADROOMRANGE    0x27
#define PORTALCMD_28               0x28
#define PORTALCMD_29               0x29
#define PORTALCMD_2A               0x2a
#define PORTALCMD_50               0x50
#define PORTALCMD_51               0x51
#define PORTALCMD_ENABLEPARENTEXEC 0x52
#define PORTALCMD_IF               0x5a
#define PORTALCMD_TOGGLEEXEC       0x5b
#define PORTALCMD_ENDIF            0x5c
#define PORTALCMD_64               0x64
#define PORTALCMD_TRAILER          0x65

#define PORTALFLAG_ENABLED 0x01
#define PORTALFLAG_04      0x04

#define PORTALMODE_SHOW 0
#define PORTALMODE_HIDE 1

#define PROJECTILEFLAG_00000001 0x00000001
#define PROJECTILEFLAG_00000002 0x00000002
#define PROJECTILEFLAG_00000080 0x00000080
#define PROJECTILEFLAG_00000800 0x00000800
#define PROJECTILEFLAG_00001000 0x00001000
#define PROJECTILEFLAG_00002000 0x00002000
#define PROJECTILEFLAG_00004000 0x00004000
#define PROJECTILEFLAG_FREE     0x80000000

#define PROPFLAG_01       0x01
#define PROPFLAG_02       0x02
#define PROPFLAG_TANGIBLE 0x04
#define PROPFLAG_08       0x08
#define PROPFLAG_10       0x10
#define PROPFLAG_20       0x20
#define PROPFLAG_40       0x40
#define PROPFLAG_80       0x80

#define PROPTYPE_OBJ       1
#define PROPTYPE_DOOR      2
#define PROPTYPE_CHR       3
#define PROPTYPE_WEAPON    4
#define PROPTYPE_EYESPY    5
#define PROPTYPE_PLAYER    6
#define PROPTYPE_EXPLOSION 7
#define PROPTYPE_SMOKE     8

#define QUADRANT_BACK          0x01
#define QUADRANT_SIDE1         0x02
#define QUADRANT_SIDE2         0x04
#define QUADRANT_FRONT         0x08
#define QUADRANT_2NDWPTOTARGET 0x10 // second waypoint on route to target
#define QUADRANT_20            0x20

#define QUIP_ATTACK1            0
#define QUIP_ATTACK2            1
#define QUIP_GOTOCOVER1         2
#define QUIP_GRENADE1           3
#define QUIP_RETREAT1           4
#define QUIP_GRENADE2           5
#define QUIP_RETREAT2           6
#define QUIP_FLANK              7
#define QUIP_SURRENDER          8
#define QUIP_HEARNOISE          9
#define QUIP_10                 10
#define QUIP_SEEPLAYER          11
#define QUIP_SHOTUNALERT        12
#define QUIP_INJURED1           13
#define QUIP_INJURED2           14
#define QUIP_KILLEDPLAYER1      15
#define QUIP_WARNFRIENDS        16
#define QUIP_17                 17
#define QUIP_SURPRISED          18
#define QUIP_INSPECTBODY        19
#define QUIP_20                 20
#define QUIP_HITPLAYER          21
#define QUIP_MISSEDPLAYER1      22
#define QUIP_MISSEDPLAYER2      23
#define QUIP_GOTOCOVER2         24
#define QUIP_DIE                25
#define QUIP_26                 26
#define QUIP_SEARCHSUCCESS      27
#define QUIP_SEEEYESPY          28
#define QUIP_GREETING           29
#define QUIP_ASKWEAPON1         30
#define QUIP_ASKWEAPON2         31
#define QUIP_UNCOVERDISGUISE1   32
#define QUIP_LOSTGUN            33
#define QUIP_GOFORALARM         34
#define QUIP_SEARCHFAIL         35
#define QUIP_ATTACK3            36
#define QUIP_ATTACK4            37
#define QUIP_KILLEDPLAYER2      38
#define QUIP_GUNJAMMED          39
#define QUIP_UNCOVEREDDISGUISE2 40

#define RACE_HUMAN    0
#define RACE_SKEDAR   1
#define RACE_DRCAROLL 2
#define RACE_EYESPY   3
#define RACE_ROBOT    4

#define ROOMFLAG_DISABLED         0x0001
#define ROOMFLAG_VISIBLEBYPLAYER  0x0004
#define ROOMFLAG_VISIBLEBYAIBOT   0x0008
#define ROOMFLAG_0010             0x0010
#define ROOMFLAG_0020             0x0020
#define ROOMFLAG_0040             0x0040
#define ROOMFLAG_RENDERALWAYS     0x0080
#define ROOMFLAG_DIRTY            0x0100
#define ROOMFLAG_0200             0x0200
#define ROOMFLAG_0800             0x0800
#define ROOMFLAG_1000             0x1000
#define ROOMFLAG_LIGHTSOFF        0x2000
#define ROOMFLAG_PLAYAMBIENTTRACK 0x4000
#define ROOMFLAG_OUTDOORS         0x8000

#define SAVEDEVICE_CONTROLLERPAK1 0
#define SAVEDEVICE_CONTROLLERPAK2 1
#define SAVEDEVICE_CONTROLLERPAK3 2
#define SAVEDEVICE_CONTROLLERPAK4 3
#define SAVEDEVICE_GAMEPAK        4
#define SAVEDEVICE_INVALID        5

#define SAVEFILEFLAG_P1_FORWARDPITCH      0x00
#define SAVEFILEFLAG_P1_AUTOAIM           0x01
#define SAVEFILEFLAG_P1_AIMCONTROL        0x02
#define SAVEFILEFLAG_P1_SIGHTONSCREEN     0x03
#define SAVEFILEFLAG_P1_LOOKAHEAD         0x04
#define SAVEFILEFLAG_P1_AMMOONSCREEN      0x05
#define SAVEFILEFLAG_SCREENSIZE_WIDE      0x06
#define SAVEFILEFLAG_SCREENRATIO          0x07
#define SAVEFILEFLAG_SCREENSIZE_CINEMA    0x08
#define SAVEFILEFLAG_P1_HEADROLL          0x09
#define SAVEFILEFLAG_P1_SHOWGUNFUNCTION   0x0a
#define SAVEFILEFLAG_INGAMESUBTITLES      0x0b
#define SAVEFILEFLAG_P2_FORWARDPITCH      0x0c
#define SAVEFILEFLAG_P2_AUTOAIM           0x0d
#define SAVEFILEFLAG_P2_AIMCONTROL        0x0e
#define SAVEFILEFLAG_P2_SIGHTONSCREEN     0x0f
#define SAVEFILEFLAG_P2_LOOKAHEAD         0x10
#define SAVEFILEFLAG_P2_AMMOONSCREEN      0x11
#define SAVEFILEFLAG_P2_HEADROLL          0x12
#define SAVEFILEFLAG_P2_SHOWGUNFUNCTION   0x13
#define SAVEFILEFLAG_CUTSCENESUBTITLES    0x14
#define SAVEFILEFLAG_P1_ALWAYSSHOWTARGET  0x15
#define SAVEFILEFLAG_P2_ALWAYSSHOWTARGET  0x16
#define SAVEFILEFLAG_P1_SHOWZOOMRANGE     0x17
#define SAVEFILEFLAG_P2_SHOWZOOMRANGE     0x18
#define SAVEFILEFLAG_SCREENSPLIT          0x19
#define SAVEFILEFLAG_P1_SHOWMISSIONTIME   0x1a
#define SAVEFILEFLAG_P2_SHOWMISSIONTIME   0x1b
#define SAVEFILEFLAG_COOPRADARON          0x1c
#define SAVEFILEFLAG_COOPFRIENDLYFIRE     0x1d
#define SAVEFILEFLAG_ANTIRADARON          0x1e
#define SAVEFILEFLAG_ANTIPLAYERNUM        0x1f
#define SAVEFILEFLAG_P1_PAINTBALL         0x20
#define SAVEFILEFLAG_P2_PAINTBALL         0x21
#define SAVEFILEFLAG_HIRES                0x22
#define SAVEFILEFLAG_USED_TRANSFERPAK     0x23
#define SAVEFILEFLAG_CI_TOUR_DONE         0x24
#define SAVEFILEFLAG_CI_HOLO7_DONE        0x29
#define SAVEFILEFLAG_CI_HOLO6_DONE        0x2a
#define SAVEFILEFLAG_CI_HOLO5_DONE        0x2b
#define SAVEFILEFLAG_CI_HOLO4_DONE        0x2c
#define SAVEFILEFLAG_CI_HOLO3_DONE        0x2d
#define SAVEFILEFLAG_CI_HOLO2_DONE        0x2e
#define SAVEFILEFLAG_CI_HOLO1_DONE        0x2f
#define SAVEFILEFLAG_CI_CLOAK_DONE        0x30
#define SAVEFILEFLAG_CI_DISGUISE_DONE     0x31
#define SAVEFILEFLAG_CI_XRAY_DONE         0x32
#define SAVEFILEFLAG_CI_IR_DONE           0x33
#define SAVEFILEFLAG_CI_RTRACKER_DONE     0x34
#define SAVEFILEFLAG_CI_DOORDECODER_DONE  0x35
#define SAVEFILEFLAG_CI_NIGHTVISION_DONE  0x36
#define SAVEFILEFLAG_CI_CAMSPY_DONE       0x37
#define SAVEFILEFLAG_CI_ECMMINE_DONE      0x38
#define SAVEFILEFLAG_CI_UPLINK_DONE       0x39
#define SAVEFILEFLAG_CI_TOUR_STARTED      0x3a
#define SAVEFILEFLAG_CRASHSITE_BIKE       0x3b
#define SAVEFILEFLAG_DEFENSE_JON          0x3c
#define SAVEFILEFLAG_AF1_ENTRY            0x3d
#define SAVEFILEFLAG_RESCUE_MECHANIC_DEAD 0x3e
#define SAVEFILEFLAG_G5_MINE              0x3f // true if thrown on top door
#define SAVEFILEFLAG_LANGFILTERON         0x40
#define SAVEFILEFLAG_41                   0x41
#define SAVEFILEFLAG_42                   0x42
#define SAVEFILEFLAG_43                   0x43
#define SAVEFILEFLAG_HOWTO_HOVERCRATE     0x47
#define SAVEFILEFLAG_HOWTO_HOVERBIKE      0x48
#define SAVEFILEFLAG_HOWTO_DOORS          0x49
#define SAVEFILEFLAG_HOWTO_ELEVATORS      0x4a
#define SAVEFILEFLAG_HOWTO_TERMINALS      0x4b
#define SAVEFILEFLAG_4C                   0x4c
#define SAVEFILEFLAG_4D                   0x4d
#define SAVEFILEFLAG_4E                   0x4e

#define SCREENRATIO_NORMAL 0
#define SCREENRATIO_16_9   1

#define SCREENSIZE_FULL   0
#define SCREENSIZE_WIDE   1
#define SCREENSIZE_CINEMA 2

#define SCREENSPLIT_HORIZONTAL 0
#define SCREENSPLIT_VERTICAL   1

#define SHARDTYPE_GLASS  0
#define SHARDTYPE_BOTTLE 1
#define SHARDTYPE_WOOD   2

#define SHOTREGION_TOTAL  0
#define SHOTREGION_HEAD   1
#define SHOTREGION_BODY   2
#define SHOTREGION_LIMB   3
#define SHOTREGION_GUN    4
#define SHOTREGION_HAT    5
#define SHOTREGION_OBJECT 6

#define SIGHT_DEFAULT  0
#define SIGHT_CLASSIC  1
#define SIGHT_2        2
#define SIGHT_3        3
#define SIGHT_SKEDAR   4
#define SIGHT_ZOOM     5
#define SIGHT_MAIAN    6
#define SIGHT_NONE     7

#define SIGHTTARGET_0 0
#define SIGHTTARGET_1 1
#define SIGHTTARGET_2 2
#define SIGHTTARGET_3 3
#define SIGHTTARGET_4 4
#define SIGHTTARGET_5 5

#define SIMDIFF_MEAT     0
#define SIMDIFF_EASY     1
#define SIMDIFF_NORMAL   2
#define SIMDIFF_HARD     3
#define SIMDIFF_PERFECT  4
#define SIMDIFF_DARK     5
#define SIMDIFF_DISABLED 6

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

#define SKJUMPSTATE_TAKEOFF  0
#define SKJUMPSTATE_AIRBORNE 1

#define SLOWMOTION_OFF   0
#define SLOWMOTION_ON    1
#define SLOWMOTION_SMART 2

#define SMOKETYPE_NONE             0
#define SMOKETYPE_ELECTRICAL       1 // Dr Caroll, mainframes in Infiltration bunker
#define SMOKETYPE_MINI             2 // Phoenix, Laptop sentry
#define SMOKETYPE_3                3
#define SMOKETYPE_SMALL            4 // SuperDragon grenades, some barrels and autoguns
#define SMOKETYPE_MEDIUM           5 // Maian SOS hoverbed
#define SMOKETYPE_LARGE            6 // Rockets, mines etc
#define SMOKETYPE_BULLETIMPACT     7
#define SMOKETYPE_ROCKETTAIL       8
#define SMOKETYPE_GRENADETAIL      9
#define SMOKETYPE_HOMINGTAIL       11
#define SMOKETYPE_SKCORPSE         13
#define SMOKETYPE_MUZZLE_PISTOL    15
#define SMOKETYPE_MUZZLE_SHOTGUN   16
#define SMOKETYPE_MUZZLE_AUTOMATIC 17
#define SMOKETYPE_MUZZLE_REAPER    18
#define SMOKETYPE_PINBALL          19 // Grenade in proxy pinball mode
#define SMOKETYPE_WATER            20 // Splash effect in Chicago
#define SMOKETYPE_DEBRIS           21 // Crash site cockpit, Skedar Ruins outro
#define SMOKETYPE_UFO              22 // AF1 outro

#define SOLOSTAGEINDEX_DEFECTION     0x00
#define SOLOSTAGEINDEX_INVESTIGATION 0x01
#define SOLOSTAGEINDEX_EXTRACTION    0x02
#define SOLOSTAGEINDEX_VILLA         0x03
#define SOLOSTAGEINDEX_CHICAGO       0x04
#define SOLOSTAGEINDEX_G5BUILDING    0x05
#define SOLOSTAGEINDEX_INFILTRATION  0x06
#define SOLOSTAGEINDEX_RESCUE        0x07
#define SOLOSTAGEINDEX_ESCAPE        0x08
#define SOLOSTAGEINDEX_AIRBASE       0x09
#define SOLOSTAGEINDEX_AIRFORCEONE   0x0a
#define SOLOSTAGEINDEX_CRASHSITE     0x0b
#define SOLOSTAGEINDEX_PELAGIC       0x0c
#define SOLOSTAGEINDEX_DEEPSEA       0x0d
#define SOLOSTAGEINDEX_DEFENSE       0x0e
#define SOLOSTAGEINDEX_ATTACKSHIP    0x0f
#define SOLOSTAGEINDEX_SKEDARRUINS   0x10
#define SOLOSTAGEINDEX_MBR           0x11
#define SOLOSTAGEINDEX_MAIANSOS      0x12
#define SOLOSTAGEINDEX_WAR           0x13
#define SOLOSTAGEINDEX_DUEL          0x14

#define SOUNDMODE_MONO      0
#define SOUNDMODE_STEREO    1
#define SOUNDMODE_HEADPHONE 2
#define SOUNDMODE_SURROUND  3

#define SPECIALDIE_NONE        0
#define SPECIALDIE_FALLBACK    1
#define SPECIALDIE_ROLL1       2
#define SPECIALDIE_ROLL2       3
#define SPECIALDIE_ROLL3       4
#define SPECIALDIE_OVERRAILING 5
#define SPECIALDIE_ONCHAIR     6

#define SPEED_WALK 0
#define SPEED_JOG  1
#define SPEED_RUN  2

#define SQUADRON_00 0x00
#define SQUADRON_01 0x01
#define SQUADRON_02 0x02
#define SQUADRON_03 0x03
#define SQUADRON_04 0x04
#define SQUADRON_05 0x05
#define SQUADRON_06 0x06
#define SQUADRON_07 0x07
#define SQUADRON_08 0x08
#define SQUADRON_09 0x09
#define SQUADRON_0A 0x0a
#define SQUADRON_0B 0x0b
#define SQUADRON_0C 0x0c
#define SQUADRON_0D 0x0d
#define SQUADRON_0E 0x0e
#define SQUADRON_0F 0x0f

#define STACKSIZE_RMON  0x300
#define STACKSIZE_IDLE  0x40
#define STACKSIZE_SCHED 0x400
#define STACKSIZE_MAIN  0x9800
#define STACKSIZE_AUDIO 0x1000
#define STACKSIZE_FAULT 0x2000
#define STACKSIZE_RESET 0x100

#define STAGE_MP_RANDOM     0x01
#define STAGE_MAIANSOS      0x09
#define STAGE_TEST_SILO     0x14
#define STAGE_WAR           0x16
#define STAGE_MP_RAVINE     0x17
#define STAGE_TEST_ARCH     0x18
#define STAGE_ESCAPE        0x19
#define STAGE_TEST_DEST     0x1a
#define STAGE_RETAKING      0x1b
#define STAGE_CRASHSITE     0x1c
#define STAGE_CHICAGO       0x1d
#define STAGE_G5BUILDING    0x1e
#define STAGE_MP_COMPLEX    0x1f
#define STAGE_MP_G5BUILDING 0x20
#define STAGE_PELAGIC       0x21
#define STAGE_EXTRACTION    0x22
#define STAGE_TEST_RUN      0x23
#define STAGE_24            0x24
#define STAGE_MP_TEMPLE     0x25
#define STAGE_CITRAINING    0x26
#define STAGE_AIRBASE       0x27
#define STAGE_28            0x28
#define STAGE_MP_PIPES      0x29
#define STAGE_SKEDARRUINS   0x2a
#define STAGE_2B            0x2b
#define STAGE_VILLA         0x2c
#define STAGE_DEFENSE       0x2d
#define STAGE_TEST_ASH      0x2e
#define STAGE_INFILTRATION  0x2f
#define STAGE_DEFECTION     0x30
#define STAGE_AIRFORCEONE   0x31
#define STAGE_MP_SKEDAR     0x32
#define STAGE_INVESTIGATION 0x33
#define STAGE_ATTACKSHIP    0x34
#define STAGE_RESCUE        0x35
#define STAGE_TEST_LEN      0x36
#define STAGE_MBR           0x37
#define STAGE_DEEPSEA       0x38
#define STAGE_MP_BASE       0x39
#define STAGE_TEST_MP2      0x3a
#define STAGE_MP_AREA52     0x3b
#define STAGE_MP_WAREHOUSE  0x3c
#define STAGE_MP_CARPARK    0x3d
#define STAGE_TEST_MP6      0x3e
#define STAGE_TEST_MP7      0x3f
#define STAGE_TEST_MP8      0x40
#define STAGE_MP_RUINS      0x41
#define STAGE_MP_SEWERS     0x42
#define STAGE_MP_FELICITY   0x43
#define STAGE_MP_FORTRESS   0x44
#define STAGE_MP_VILLA      0x45
#define STAGE_TEST_MP14     0x46
#define STAGE_MP_GRID       0x47
#define STAGE_TEST_MP16     0x48
#define STAGE_TEST_MP17     0x49
#define STAGE_TEST_MP18     0x4a
#define STAGE_TEST_MP19     0x4b
#define STAGE_TEST_MP20     0x4c
#define STAGE_TEST_UFF      0x4d
#define STAGE_TEST_OLD      0x4e
#define STAGE_DUEL          0x4f
#define STAGE_TEST_LAM      0x50
#define STAGE_TITLE         0x5a
#define STAGE_BOOTPAKMENU   0x5b
#define STAGE_CREDITS       0x5c
#define STAGE_4MBMENU       0x5d

#define STAGEFLAG_CI_IN_TRAINING            0x00000001
#define STAGEFLAG_CI_HOLO_FAILED            0x00000002
#define STAGEFLAG_CI_DEVICE_ABORTING        0x00000004
#define STAGEFLAG_CI_TRIGGER_DEVICE_SUCCESS 0x00000008
#define STAGEFLAG_CI_TRIGGER_DEVICE_FAILURE 0x00000010
#define STAGEFLAG_CI_HOLO_ABORTING          0x00000020
#define STAGEFLAG_CI_TRIGGER_HOLO_SUCCESS   0x00000040
#define STAGEFLAG_CI_TRIGGER_HOLO_FAILURE   0x00000080
#define STAGEFLAG_CI_TRIGGER_UPLINK         0x00000100
#define STAGEFLAG_CI_TRIGGER_ECMMINE        0x00000200
#define STAGEFLAG_CI_TRIGGER_CAMSPY         0x00000400
#define STAGEFLAG_CI_TRIGGER_NIGHTVISION    0x00000800
#define STAGEFLAG_CI_TRIGGER_DOORDECODER    0x00001000
#define STAGEFLAG_CI_TRIGGER_RTRACKER       0x00002000
#define STAGEFLAG_CI_TRIGGER_IR             0x00004000
#define STAGEFLAG_CI_TRIGGER_XRAY           0x00008000
#define STAGEFLAG_CI_TRIGGER_DISGUISE       0x00010000
#define STAGEFLAG_CI_TRIGGER_CLOAK          0x00020000
#define STAGEFLAG_CI_IN_HOLO1               0x00040000
#define STAGEFLAG_CI_IN_HOLO2               0x00080000
#define STAGEFLAG_CI_IN_HOLO3               0x00100000
#define STAGEFLAG_CI_IN_HOLO4               0x00200000
#define STAGEFLAG_CI_IN_HOLO5               0x00400000
#define STAGEFLAG_CI_IN_HOLO6               0x00800000
#define STAGEFLAG_CI_IN_HOLO7               0x01000000
#define STAGEFLAG_CI_GENERAL_PURPOSE        0x02000000
#define STAGEFLAG_EYESPY_DESTROYED          0x00002000

#define STAGEINDEX_MAIANSOS      0x00
#define STAGEINDEX_TEST_SILO     0x01
#define STAGEINDEX_WAR           0x02
#define STAGEINDEX_MP_RAVINE     0x03
#define STAGEINDEX_TEST_ARCH     0x04
#define STAGEINDEX_ESCAPE        0x05
#define STAGEINDEX_TEST_DEST     0x06
#define STAGEINDEX_RETAKING      0x07
#define STAGEINDEX_CRASHSITE     0x08
#define STAGEINDEX_CHICAGO       0x09
#define STAGEINDEX_G5BUILDING    0x0a
#define STAGEINDEX_MP_COMPLEX    0x0b
#define STAGEINDEX_MP_G5BUILDING 0x0c
#define STAGEINDEX_PELAGIC       0x0d
#define STAGEINDEX_EXTRACTION    0x0e
#define STAGEINDEX_TEST_RUN      0x0f
#define STAGEINDEX_MP_TEMPLE     0x11
#define STAGEINDEX_CITRAINING    0x12
#define STAGEINDEX_AIRBASE       0x13
#define STAGEINDEX_MP_PIPES      0x15
#define STAGEINDEX_SKEDARRUINS   0x16
#define STAGEINDEX_VILLA         0x18
#define STAGEINDEX_DEFENSE       0x19
#define STAGEINDEX_TEST_ASH      0x1a
#define STAGEINDEX_INFILTRATION  0x1b
#define STAGEINDEX_DEFECTION     0x1c
#define STAGEINDEX_AIRFORCEONE   0x1d
#define STAGEINDEX_MP_SKEDAR     0x1e
#define STAGEINDEX_INVESTIGATION 0x1f
#define STAGEINDEX_ATTACKSHIP    0x20
#define STAGEINDEX_RESCUE        0x21
#define STAGEINDEX_TEST_LEN      0x22
#define STAGEINDEX_MBR           0x23
#define STAGEINDEX_DEEPSEA       0x24
#define STAGEINDEX_TEST_UFF      0x25
#define STAGEINDEX_TEST_OLD      0x26
#define STAGEINDEX_DUEL          0x27
#define STAGEINDEX_TEST_LAM      0x28
#define STAGEINDEX_MP_BASE       0x29
#define STAGEINDEX_TEST_MP2      0x2a
#define STAGEINDEX_MP_AREA52     0x2b
#define STAGEINDEX_MP_WAREHOUSE  0x2c
#define STAGEINDEX_MP_CARPARK    0x2d
#define STAGEINDEX_TEST_MP6      0x2e
#define STAGEINDEX_TEST_MP7      0x2f
#define STAGEINDEX_TEST_MP8      0x30
#define STAGEINDEX_MP_RUINS      0x31
#define STAGEINDEX_MP_SEWERS     0x32
#define STAGEINDEX_MP_FELICITY   0x33
#define STAGEINDEX_MP_FORTRESS   0x34
#define STAGEINDEX_MP_VILLA      0x35
#define STAGEINDEX_TEST_MP14     0x36
#define STAGEINDEX_MP_GRID       0x37
#define STAGEINDEX_TEST_MP16     0x38
#define STAGEINDEX_TEST_MP17     0x39
#define STAGEINDEX_TEST_MP18     0x3a
#define STAGEINDEX_TEST_MP19     0x3b
#define STAGEINDEX_TEST_MP20     0x3c

#define TEAM_00        0x00
#define TEAM_01        0x01
#define TEAM_ENEMY     0x02
#define TEAM_04        0x04
#define TEAM_ALLY      0x10
#define TEAM_20        0x20
#define TEAM_22        0x22
#define TEAM_32        0x32
#define TEAM_NONCOMBAT 0x80

#define TELEPORTSTATE_INACTIVE 0
#define TELEPORTSTATE_PREENTER 1
#define TELEPORTSTATE_ENTERING 2
#define TELEPORTSTATE_WHITE    3
#define TELEPORTSTATE_EXITING  4

#define THREAD_RMON  0
#define THREAD_IDLE  1
#define THREAD_SCHED 2
#define THREAD_MAIN  3
#define THREAD_AUDIO 4
#define THREAD_FAULT 5
#define THREAD_RESET 6

#define THREADPRI_RMON  250
#define THREADPRI_IDLE  0
#define THREADPRI_SCHED 30
#define THREADPRI_MAIN  10
#define THREADPRI_AUDIO 20
#define THREADPRI_FAULT 40
#define THREADPRI_RESET 11

#define TICKMODE_0        0
#define TICKMODE_NORMAL   1
#define TICKMODE_WARP     3
#define TICKMODE_MPSWIRL  4
#define TICKMODE_5        5
#define TICKMODE_CUTSCENE 6
#define TICKMODE_AUTOWALK 7

#define TILEFLAG_0001           0x0001 // Editor: Traversable
#define TILEFLAG_0002           0x0002
#define TILEFLAG_0004           0x0004 // Editor: Collisions
#define TILEFLAG_0008           0x0008
#define TILEFLAG_0010           0x0010 // Editor: Block AI fire/sight
#define TILEFLAG_0020           0x0020
#define TILEFLAG_LADDER         0x0040
#define TILEFLAG_0080           0x0080
#define TILEFLAG_0100           0x0100 // Editor: Low wall/edge
#define TILEFLAG_UNDERWATER     0x0200
#define TILEFLAG_0400           0x0400
#define TILEFLAG_AIBOTCROUCH    0x0800
#define TILEFLAG_AIBOTDUCK      0x1000
#define TILEFLAG_2000           0x2000 // Editor: Incline
#define TILEFLAG_DIE            0x4000
#define TILEFLAG_CLIMBABLELEDGE 0x8000 // used for most ledges in Chicago, but not near drain pickup

#define TILETYPE_00 0 // Standard BG tiles
#define TILETYPE_01 1
#define TILETYPE_02 2
#define TILETYPE_03 3 // Chr/obj geometry

#define TITLEMODE_LEGAL            0
#define TITLEMODE_CHECKCONTROLLERS 1
#define TITLEMODE_PDLOGO           2
#define TITLEMODE_NINTENDOLOGO     3
#define TITLEMODE_RARELOGO         4
#define TITLEMODE_SKIP             5
#define TITLEMODE_NOCONTROLLER     6
#define TITLEMODE_RAREPRESENTS1    7
#define TITLEMODE_RAREPRESENTS2    8

#define TITLEAIMODE_RAREPRESENTS1 1
#define TITLEAIMODE_RARELOGO      2
#define TITLEAIMODE_NINTENDOLOGO  3
#define TITLEAIMODE_RAREPRESENTS2 4
#define TITLEAIMODE_PDLOGO        5

#define TRACKTYPE_PRIMARY 1
#define TRACKTYPE_X       2
#define TRACKTYPE_MENU    3
#define TRACKTYPE_DEATH   4
#define TRACKTYPE_AMBIENT 5
#define TRACKTYPE_6       6

#define VEHICLEMODE_OFF         0
#define VEHICLEMODE_ENGINESTART 1
#define VEHICLEMODE_RUNNING     2

#define VIMODE_DEFAULT 0
#define VIMODE_HIRES   1

#define VISIONMODE_NORMAL       0
#define VISIONMODE_XRAY         1
#define VISIONMODE_SLAYERROCKET 2
#define VISIONMODE_3            3

#define VOICEBOX_MALE0  0
#define VOICEBOX_MALE1  1
#define VOICEBOX_MALE2  2
#define VOICEBOX_FEMALE 3

#define WAYMODE_EXPENSIVE 0
#define WAYMODE_CHEAP     6

#define WEAPON_NONE              0x00
#define WEAPON_UNARMED           0x01
#define WEAPON_FALCON2           0x02
#define WEAPON_FALCON2_SILENCER  0x03
#define WEAPON_FALCON2_SCOPE     0x04
#define WEAPON_MAGSEC4           0x05
#define WEAPON_MAULER            0x06
#define WEAPON_PHOENIX           0x07
#define WEAPON_DY357MAGNUM       0x08
#define WEAPON_DY357LX           0x09
#define WEAPON_CMP150            0x0a
#define WEAPON_CYCLONE           0x0b
#define WEAPON_CALLISTO          0x0c
#define WEAPON_RCP120            0x0d
#define WEAPON_LAPTOPGUN         0x0e
#define WEAPON_DRAGON            0x0f
#define WEAPON_K7AVENGER         0x10
#define WEAPON_AR34              0x11
#define WEAPON_SUPERDRAGON       0x12
#define WEAPON_SHOTGUN           0x13
#define WEAPON_REAPER            0x14
#define WEAPON_SNIPERRIFLE       0x15
#define WEAPON_FARSIGHT          0x16
#define WEAPON_DEVASTATOR        0x17
#define WEAPON_ROCKETLAUNCHER    0x18
#define WEAPON_SLAYER            0x19
#define WEAPON_COMBATKNIFE       0x1a
#define WEAPON_CROSSBOW          0x1b
#define WEAPON_TRANQUILIZER      0x1c
#define WEAPON_LASER             0x1d
#define WEAPON_GRENADE           0x1e
#define WEAPON_NBOMB             0x1f
#define WEAPON_TIMEDMINE         0x20
#define WEAPON_PROXIMITYMINE     0x21
#define WEAPON_REMOTEMINE        0x22
#define WEAPON_COMBATBOOST       0x23
#define WEAPON_PP9I              0x24
#define WEAPON_CC13              0x25
#define WEAPON_KL01313           0x26
#define WEAPON_KF7SPECIAL        0x27
#define WEAPON_ZZT               0x28
#define WEAPON_DMC               0x29
#define WEAPON_AR53              0x2a
#define WEAPON_RCP45             0x2b
#define WEAPON_PSYCHOSISGUN      0x2c
#define WEAPON_NIGHTVISION       0x2d
#define WEAPON_EYESPY            0x2e
#define WEAPON_XRAYSCANNER       0x2f
#define WEAPON_IRSCANNER         0x30
#define WEAPON_CLOAKINGDEVICE    0x31
#define WEAPON_HORIZONSCANNER    0x32
#define WEAPON_TESTER            0x33
#define WEAPON_ROCKETLAUNCHER_34 0x34
#define WEAPON_ECMMINE           0x35
#define WEAPON_DATAUPLINK        0x36
#define WEAPON_RTRACKER          0x37
#define WEAPON_PRESIDENTSCANNER  0x38
#define WEAPON_DOORDECODER       0x39
#define WEAPON_AUTOSURGEON       0x3a
#define WEAPON_EXPLOSIVES        0x3b
#define WEAPON_SKEDARBOMB        0x3c
#define WEAPON_COMMSRIDER        0x3d
#define WEAPON_TRACERBUG         0x3e
#define WEAPON_TARGETAMPLIFIER   0x3f
#define WEAPON_DISGUISE40        0x40
#define WEAPON_DISGUISE41        0x41
#define WEAPON_FLIGHTPLANS       0x42
#define WEAPON_RESEARCHTAPE      0x43
#define WEAPON_BACKUPDISK        0x44
#define WEAPON_KEYCARD45         0x45
#define WEAPON_KEYCARD46         0x46
#define WEAPON_KEYCARD47         0x47
#define WEAPON_KEYCARD48         0x48
#define WEAPON_KEYCARD49         0x49
#define WEAPON_KEYCARD4A         0x4a
#define WEAPON_KEYCARD4B         0x4b
#define WEAPON_KEYCARD4C         0x4c
#define WEAPON_SUITCASE          0x4d
#define WEAPON_BRIEFCASE         0x4e
#define WEAPON_SHIELD            0x4f
#define WEAPON_NECKLACE          0x50
#define WEAPON_HAMMER            0x51
#define WEAPON_52                0x52
#define WEAPON_ROCKET            0x53
#define WEAPON_HOMINGROCKET      0x54
#define WEAPON_GRENADEROUND      0x55
#define WEAPON_BOLT              0x56
#define WEAPON_BRIEFCASE2        0x57
#define WEAPON_ROCKET2           0x58
#define WEAPON_59                0x59
#define WEAPON_5A                0x5a
#define WEAPON_MPSHIELD          0x5b
#define WEAPON_DISABLED          0x5c
#define WEAPON_SUICIDEPILL       0x5d

#define WEAPONCLASSFLAG_MANUALZOOM 0x00000001
#define WEAPONCLASSFLAG_AUTOAIM    0x00000002
#define WEAPONCLASSFLAG_00000004   0x00000004

#define WEAPONFLAG_00000001          0x00000001 // mines, grenades and knives
#define WEAPONFLAG_00000004          0x00000004
#define WEAPONFLAG_ONEHANDED         0x00000008 // Makes guards carry the gun with one hand
#define WEAPONFLAG_AICANUSE          0x00000010
#define WEAPONFLAG_DUALFLIP          0x00000020 // For dual wielding, flip the right model to make the left (else have two right hands)
#define WEAPONFLAG_00000040          0x00000040
#define WEAPONFLAG_00000080          0x00000080 // Night vision
#define WEAPONFLAG_TRACKTIMEUSED     0x00000200 // Allow tracking how long gun is used, for weapon of choice
#define WEAPONFLAG_00000400          0x00000400
#define WEAPONFLAG_00000800          0x00000800 // MP briefcase
#define WEAPONFLAG_DUALWIELD         0x00001000 // Allow dual wielding
#define WEAPONFLAG_00002000          0x00002000
#define WEAPONFLAG_00004000          0x00004000
#define WEAPONFLAG_00008000          0x00008000 // Editor: "Special environment mapping"
#define WEAPONFLAG_HASHANDS          0x00020000
#define WEAPONFLAG_HIDEMENUMODEL     0x00040000 // Don't display the rotating model in the inventory menu
#define WEAPONFLAG_GANGSTA           0x00080000 // Allow turning the gun sideways at close range
#define WEAPONFLAG_DONTCOUNTSHOTS    0x00100000 // Laser and MP briefcase
#define WEAPONFLAG_DETERMINER_S_AN   0x00200000 // "An ..." (short version - when vertically split)
#define WEAPONFLAG_DETERMINER_F_AN   0x00400000 // "Picked up an ..." (full version)
#define WEAPONFLAG_DETERMINER_S_THE  0x00800000 // "The ..." (short version - when vertically split)
#define WEAPONFLAG_DETERMINER_F_THE  0x01000000 // "Picked up the ..." (full version)
#define WEAPONFLAG_02000000          0x02000000 // Slayer
#define WEAPONFLAG_04000000          0x04000000
#define WEAPONFLAG_08000000          0x08000000
#define WEAPONFLAG_DETERMINER_S_SOME 0x10000000 // "Some ..." (short version - when vertically split)
#define WEAPONFLAG_DETERMINER_F_SOME 0x20000000 // "Picked up some ..." (full version)
#define WEAPONFLAG_AIMTRACK          0x40000000 // Allow drawing red box around targets in aim mode
#define WEAPONFLAG_FIRETOACTIVATE    0x80000000 // For devices/gadgets

#define WEATHERTYPE_RAIN 0
#define WEATHERTYPE_SNOW 1

// Reasons for playing X music
#define XREASON_0       0
#define XREASON_DEFAULT 1
#define XREASON_2       2
#define XREASON_3       3

// Heads and bodies
#define HEAD_RANDOM           -1
#define BODY_DJBOND           0x00
#define BODY_CONNERY          0x01
#define BODY_DALTON           0x02
#define BODY_MOORE            0x03
#define HEAD_DARK_COMBAT      0x04
#define HEAD_ELVIS            0x05
#define HEAD_ROSS             0x06
#define HEAD_CARRINGTON       0x07
#define HEAD_MRBLONDE         0x08
#define HEAD_TRENT            0x09
#define HEAD_DDSHOCK          0x0a
#define HEAD_GRAHAM           0x0b
#define HEAD_DARK_FROCK       0x0c
#define HEAD_SECRETARY        0x0d
#define HEAD_CASSANDRA        0x0e
#define HEAD_THEKING          0x0f
#define HEAD_FEM_GUARD        0x10
#define HEAD_JON              0x11
#define HEAD_MARK2            0x12
#define HEAD_CHRIST           0x13
#define HEAD_RUSS             0x14
#define HEAD_GREY             0x15
#define HEAD_DARLING          0x16
#define HEAD_ROBERT           0x17
#define HEAD_BEAU1            0x18
#define HEAD_FEM_GUARD2       0x19
#define HEAD_BRIAN            0x1a
#define HEAD_JAMIE            0x1b
#define HEAD_DUNCAN2          0x1c
#define HEAD_BIOTECH          0x1d
#define HEAD_NEIL2            0x1e
#define HEAD_EDMCG            0x1f
#define HEAD_ANKA             0x20
#define HEAD_LESLIE_S         0x21
#define HEAD_MATT_C           0x22
#define HEAD_PEER_S           0x23
#define HEAD_EILEEN_T         0x24
#define HEAD_ANDY_R           0x25
#define HEAD_BEN_R            0x26
#define HEAD_STEVE_K          0x27
#define HEAD_JONATHAN         0x28
#define HEAD_MAIAN_S          0x29
#define HEAD_SHAUN            0x2a
#define HEAD_BEAU2            0x2b
#define HEAD_EILEEN_H         0x2c
#define HEAD_SCOTT_H          0x2d
#define HEAD_SANCHEZ          0x2e
#define HEAD_DARKAQUA         0x2f
#define HEAD_DDSNIPER         0x30
#define HEAD_BEAU3            0x31
#define HEAD_BEAU4            0x32
#define HEAD_BEAU5            0x33
#define HEAD_BEAU6            0x34
#define HEAD_GRIFFEY          0x35
#define HEAD_MOTO             0x36
#define HEAD_KEITH            0x37
#define HEAD_WINNER           0x38
#define HEAD_A51FACEPLATE     0x39
#define HEAD_ELVIS_GOGS       0x3a
#define HEAD_STEVEM           0x3b
#define HEAD_DARK_SNOW        0x3c
#define HEAD_PRESIDENT        0x3d
#define HEAD_VD               0x3e
#define HEAD_KEN              0x3f
#define HEAD_JOEL             0x40
#define HEAD_TIM              0x41
#define HEAD_GRANT            0x42
#define HEAD_PENNY            0x43
#define HEAD_ROBIN            0x44
#define HEAD_ALEX             0x45
#define HEAD_JULIANNE         0x46
#define HEAD_LAURA            0x47
#define HEAD_DAVEC            0x48
#define HEAD_COOK             0x49
#define HEAD_PRYCE            0x4a
#define HEAD_SILKE            0x4b
#define HEAD_SMITH            0x4c
#define HEAD_GARETH           0x4d
#define HEAD_MURCHIE          0x4e
#define HEAD_WONG             0x4f
#define HEAD_CARTER           0x50
#define HEAD_TINTIN           0x51
#define HEAD_MUNTON           0x52
#define HEAD_STAMPER          0x53
#define HEAD_JONES            0x54
#define HEAD_PHELPS           0x55
#define BODY_DARK_COMBAT      0x56
#define BODY_ELVIS1           0x57
#define BODY_AREA51GUARD      0x58
#define BODY_OVERALL          0x59
#define BODY_CARRINGTON       0x5a
#define BODY_MRBLONDE         0x5b
#define BODY_SKEDAR           0x5c
#define BODY_TRENT            0x5d
#define BODY_DDSHOCK          0x5e
#define BODY_LABTECH          0x5f
#define BODY_STRIPES          0x60
#define BODY_DARK_FROCK       0x61
#define BODY_DARK_TRENCH      0x62
#define BODY_OFFICEWORKER     0x63
#define BODY_OFFICEWORKER2    0x64
#define BODY_SECRETARY        0x65
#define BODY_CASSANDRA        0x66
#define BODY_THEKING          0x67
#define BODY_FEM_GUARD        0x68
#define BODY_DD_LABTECH       0x69
#define BODY_DD_SECGUARD      0x6a
#define BODY_DRCAROLL         0x6b
#define BODY_EYESPY           0x6c
#define BODY_DARK_RIPPED      0x6d
#define BODY_DD_GUARD         0x6e
#define BODY_DD_SHOCK_INF     0x6f
#define BODY_TESTCHR          0x70
#define BODY_BIOTECH          0x71
#define BODY_FBIGUY           0x72
#define BODY_CIAGUY           0x73
#define BODY_A51TROOPER       0x74
#define BODY_A51AIRMAN        0x75
#define BODY_CHICROB          0x76
#define BODY_STEWARD          0x77
#define BODY_STEWARDESS       0x78
#define BODY_PRESIDENT        0x79
#define BODY_STEWARDESS_COAT  0x7a
#define BODY_MINISKEDAR       0x7b
#define BODY_NSA_LACKEY       0x7c
#define BODY_PRES_SECURITY    0x7d
#define BODY_NEGOTIATOR       0x7e
#define BODY_G5_GUARD         0x7f
#define BODY_PELAGIC_GUARD    0x80
#define BODY_G5_SWAT_GUARD    0x81
#define BODY_ALASKAN_GUARD    0x82
#define BODY_MAIAN_SOLDIER    0x83
#define BODY_PRESIDENT_CLONE  0x84
#define BODY_PRESIDENT_CLONE2 0x85
#define BODY_DARK_AF1         0x86
#define BODY_DARKWET          0x87
#define BODY_DARKAQUALUNG     0x88
#define BODY_DARKSNOW         0x89
#define BODY_DARKLAB          0x8a
#define BODY_FEMLABTECH       0x8b
#define BODY_DDSNIPER         0x8c
#define BODY_PILOTAF1         0x8d
#define BODY_CILABTECH        0x8e
#define BODY_CIFEMTECH        0x8f
#define BODY_CARREVENINGSUIT  0x90
#define BODY_JONATHAN         0x91
#define BODY_CISOLDIER        0x92
#define BODY_SKEDARKING       0x93
#define BODY_ELVISWAISTCOAT   0x94
#define BODY_DARK_LEATHER     0x95
#define BODY_DARK_NEGOTIATOR  0x96

#endif
