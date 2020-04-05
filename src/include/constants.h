#include "files.h"

#define FALSE 0
#define TRUE  1

#define false 0
#define true  1

#define osSyncPrintf

#define U32_MAX 4294967295

#define ABS(val)              (val > 0 ? val : -val)
#define ARRAYCOUNT(a)         (s32)(sizeof(a) / sizeof(a[0]))
#define CHRRACE(chr)          (chr ? chr->race : RACE_HUMAN)
#define FRAMEDURATION         (1 / 60.0f)
#define PLAYERCOUNT()         ((g_Vars.players[0] ? 1 : 0) + (g_Vars.players[1] ? 1 : 0) + (g_Vars.players[2] ? 1 : 0) + (g_Vars.players[3] ? 1 : 0))
#define PLAYERCOUNT3012()     ((g_Vars.players[3] ? 1 : 0) + (g_Vars.players[0] ? 1 : 0) + (g_Vars.players[1] ? 1 : 0) + (g_Vars.players[2] ? 1 : 0))
#define SECSTOFRAMES240(secs) (secs * 240)
#define TEXT(bankid, index)   ((bankid << 9) | index)

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
#define AMSLOTFLAG_HIDDEN  0x10

#define ANIM_IDLE                   0x0000
#define ANIM_TWO_GUN_HOLD           0x0001
#define ANIM_KNEEL_TWO_HANDED_GUN   0x0008
#define ANIM_RUNNING_TWOHANDGUN     0x002a
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
#define ANIM_SITTING_0265           0x0265
#define ANIM_SNIPING_0269           0x0269
#define ANIM_SNIPING_026A           0x026a
#define ANIM_SNIPING_026B           0x026b
#define ANIM_DRAW_PISTOL_0288       0x0288
#define ANIM_DRAW_PISTOL_0289       0x0289
#define ANIM_FIX_GUN_JAM_EASY       0x0299
#define ANIM_FIX_GUN_JAM_HARD       0x029a
#define ANIM_SKEDAR_COLLAPSE        0x0352
#define ANIM_SKEDAR_JUMPSTART       0x0384
#define ANIM_SKEDAR_JUMPAIR         0x0385
#define ANIM_SKEDAR_RUNNING         0x0394

#define BANK_0 0
#define BANK_1 1
#define BANK_2 2
#define BANK_3 3

#define CAMERAMODE_0 0
#define CAMERAMODE_1 1
#define CAMERAMODE_2 2

#define CASING_NONE     -1
#define CASING_STANDARD 0
#define CASING_REAPER   1
#define CASING_RIFLE    2
#define CASING_SHOTGUN  3

// Challenge numbers don't appear to be a 1:1 mapping :(
#define CHALLENGE_7     30
#define CHALLENGE_UNK64 64

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
#define CHRFLAG0_CAN_RUN_FOR_ALARM  0x00040000
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
#define CHRFLAG0_80000000           0x80000000 // Globals, Villa, Chicago, CI Training

// chr->flags2
#define CHRFLAG1_00000001                  0x00000001 // Globals, Extraction, Air Base, Deep Sea
#define CHRFLAG1_00000002                  0x00000002 // Globals
#define CHRFLAG1_00000004                  0x00000004 // Globals - If set, avoids cmd0184
#define CHRFLAG1_00000008                  0x00000008 // Only used in WAR. If set, chr waits 2 seconds before attacking while defending
#define CHRFLAG1_00000010                  0x00000010 // Globals - If set, avoids cmd0184
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
#define CHRHFLAG_00000001           0x00000001 // Set when chr drops weapon
#define CHRHFLAG_00000002           0x00000002 // Not used in scripts
#define CHRHFLAG_00000004           0x00000004 // Related to firing - hand 1
#define CHRHFLAG_00000008           0x00000008 // Related to firing - hand 0
#define CHRHFLAG_00000010           0x00000010 // Not used in scripts
#define CHRHFLAG_00000020           0x00000020 // Not used in scripts
#define CHRHFLAG_TIMER_RUNNING      0x00000040
#define CHRHFLAG_00000080           0x00000080 // Not used in scripts
#define CHRHFLAG_00000100           0x00000100 // Not used in scripts
#define CHRHFLAG_00000200           0x00000200 // Not used in scripts
#define CHRHFLAG_PASSIVE            0x00000400
#define CHRHFLAG_KEEP_CORPSE        0x00000800
#define CHRHFLAG_BUDDY_PLACED       0x00001000
#define CHRHFLAG_00002000           0x00002000 // Globals, Rescue guards once disguised
#define CHRHFLAG_TRIGGER_BUDDY_WARP 0x00004000
#define CHRHFLAG_00008000           0x00008000 // Duel only. Set on each opponent when they start combat.
#define CHRHFLAG_DISGUISE_UNCOVERED 0x00010000
#define CHRHFLAG_00020000           0x00020000 // Used in every stage, on Jo and other chrs. Only ever set, never unset or read.
#define CHRHFLAG_00040000           0x00040000 // Not used in scripts
#define CHRHFLAG_DISGUISED          0x00080000
#define CHRHFLAG_00100000           0x00100000 // Set before warping to pad, never unset or read
#define CHRHFLAG_00200000           0x00200000 // Not used in scripts
#define CHRHFLAG_00400000           0x00400000 // Set in Chicago, G5, AF1, Defense, Attack Ship, Skedar Ruins, Maian SOS, WAR
#define CHRHFLAG_00800000           0x00800000 // Not used in scripts
#define CHRHFLAG_01000000           0x01000000 // Globals - asked about gun (eg. "where did you get that?")
#define CHRHFLAG_02000000           0x02000000 // Similar to DISGUISED flag, but not sure where set
#define CHRHFLAG_04000000           0x04000000 // Related to disguise and detection
#define CHRHFLAG_08000000           0x08000000 // Globals, Villa and G5
#define CHRHFLAG_10000000           0x10000000 // Related to invincible flag
#define CHRHFLAG_CLOAKED            0x20000000
#define CHRHFLAG_40000000           0x40000000 // Air Base and AF1
#define CHRHFLAG_PSYCHOSISED        0x80000000

// chr->hidden2
#define CHRH2FLAG_0001 0x0001
#define CHRH2FLAG_0040 0x0040
#define CHRH2FLAG_1000 0x1000

// chr->chrflags
#define CHRCFLAG_00000001                    0x00000001 // Villa takers, Attack Ship Cass and skedar - both set at end of intros
#define CHRCFLAG_00000002                    0x00000002 // Seems to be set on guards who can spawn clones?
#define CHRCFLAG_NEAR_MISS                   0x00000004
#define CHRCFLAG_NEVER_BEEN_ON_SCREEN        0x00000008
#define CHRCFLAG_INVINCIBLE_TO_GUNFIRE       0x00000010
#define CHRCFLAG_00000020                    0x00000020 // Chicago, Infiltration, AF1, Ruins, WAR
#define CHRCFLAG_00000040                    0x00000040 // Used quite a lot
#define CHRCFLAG_00000080                    0x00000080 // Defection programmer, Rescue lab techs, globals when doing idle animation
#define CHRCFLAG_JUST_INJURED                0x00000100
#define CHRCFLAG_00000200                    0x00000200 // Set on clones
#define CHRCFLAG_HIDDEN                      0x00000400
#define CHRCFLAG_NOAUTOAIM                   0x00000800
#define CHRCFLAG_UNEXPLODABLE                0x00001000
#define CHRCFLAG_00002000                    0x00002000 // Not used in scripts
#define CHRCFLAG_HAS_SPECIAL_DEATH_ANIMATION 0x00004000
#define CHRCFLAG_00008000                    0x00008000 // Not used in scripts
#define CHRCFLAG_00010000                    0x00010000 // Related to dead people in intro cutscenes
#define CHRCFLAG_00020000                    0x00020000 // Chicago, Crash Site, Deep Sea, Defense, Ruins
#define CHRCFLAG_00040000                    0x00040000 // Used a lot
#define CHRCFLAG_00080000                    0x00080000
#define CHRCFLAG_KILLCOUNTABLE               0x00100000
#define CHRCFLAG_00200000                    0x00200000 // Unset by cmd 00fd
#define CHRCFLAG_00400000                    0x00400000 // Not used in scripts
#define CHRCFLAG_UNPLAYABLE                  0x00800000
#define CHRCFLAG_01000000                    0x01000000 // Typically set on allies during init
#define CHRCFLAG_02000000                    0x02000000 // can be unset by cmd0168
#define CHRCFLAG_04000000                    0x04000000 // Set by aiChrKill command
#define CHRCFLAG_CONSIDER_DODGE              0x08000000
#define CHRCFLAG_10000000                    0x10000000 // Not used in scripts
#define CHRCFLAG_20000000                    0x20000000 // Not used in scripts
#define CHRCFLAG_40000000                    0x40000000 // Not used in scripts
#define CHRCFLAG_INJURED                     0x80000000

#define CIROOM_FIRINGRANGE 0x0a
#define CIROOM_HOLOSTART   0x16
#define CIROOM_HOLOEND     0x19
#define CIROOM_DEVICEROOM  0x1e

#define CMD_LABEL 0x0002
#define CMD_END   0x0004
#define CMD_PRINT 0x00b5

#define COLOR_00_GREEN  0x00
#define COLOR_02_WHITE  0x02
#define COLOR_03_RED    0x03
#define COLOR_04_ORANGE 0x04
#define COLOR_05_GREEN  0x05
#define COLOR_06_WHITE  0x06
#define COLOR_07_RED    0x07
#define COLOR_08_RED    0x08
#define COLOR_09_BLUE   0x09

#define CONTROLMODE_SINGLE 0
#define CONTROLMODE_DOUBLE 1

#define COVERFLAG_0001 0x0001
#define COVERFLAG_0002 0x0002
#define COVERFLAG_0020 0x0020
#define COVERFLAG_0040 0x0040
#define COVERFLAG_0080 0x0080

// L/C/R = left/centered/right
// big/med/sml is the font size
#define CREDITSTYLE_R_BIG_R_MED 1
#define CREDITSTYLE_C_BIG       2
#define CREDITSTYLE_C_MED       3
#define CREDITSTYLE_C_SML       5
#define CREDITSTYLE_L_BIG       7
#define CREDITSTYLE_R_MED       9
#define CREDITSTYLE_C_BIG_C_BIG 10
#define CREDITSTYLE_TERMINATOR  20

#define CROUCH_SQUAT 0
#define CROUCH_HALF  1
#define CROUCH_STAND 2

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
#define DOORFLAG_0008            0x0008 // Changes the angle at which one-way doors can be opened
#define DOORFLAG_0010            0x0010 // Rescue door bottoms, training doors in Defense
#define DOORFLAG_0200            0x0200 // dataDyne secret door near lobby elevator
#define DOORFLAG_DAMAGEONCONTACT 0x0400 // Lasers
#define DOORFLAG_0800            0x0800 // Non-CI lasers, and floor grates
#define DOORFLAG_4000            0x4000 // Two Investigation vertical doors after lasers

#define DOORMODE_IDLE      0
#define DOORMODE_OPENING   1
#define DOORMODE_CLOSING   2
#define DOORMODE_3         3

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

#define ENTITYTYPE_CHR       0x0004
#define ENTITYTYPE_PAD       0x0008
#define ENTITYTYPE_DIRECTION 0x0010
#define ENTITYTYPE_TARGET    0x0200

#define EYESPYMODE_CAMSPY  0
#define EYESPYMODE_DRUGSPY 1
#define EYESPYMODE_BOMBSPY 2

#define FLOORFLAG_0100 0x0100
#define FLOORFLAG_4000 0x4000

// Weapon functions
#define FUNC_PRIMARY   0
#define FUNC_SECONDARY 1

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
#define GAILIST_INIT_COOP_100          0x0012 // unused
#define GAILIST_INIT_COOP_200          0x0013 // unused
#define GAILIST_COOP_BUDDY             0x0014
#define GAILIST_AIBUDDY_STEALTH        0x0015
#define GAILIST_SHOW_OBJ_FAILED_MSG    0x0016
#define GAILIST_REBUILD_GROUPS         0x0017
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

#define HUDMSGFLAG_ONLYIFALIVE 0x1
#define HUDMSGFLAG_2           0x2
#define HUDMSGFLAG_4           0x4
#define HUDMSGFLAG_ALLOWDUPES  0x8

#define HUDMSGSTATE_FREE     0
#define HUDMSGSTATE_QUEUED   1
#define HUDMSGSTATE_ONSCREEN 5

#define HUDMSGTYPE_DEFAULT           0
#define HUDMSGTYPE_OBJECTIVECOMPLETE 1
#define HUDMSGTYPE_OBJECTIVEFAILED   2
#define HUDMSGTYPE_3                 3
#define HUDMSGTYPE_4                 4
#define HUDMSGTYPE_SUBTITLE          6

#define IDLEACTION_STANDING        0x01
#define IDLEACTION_SITTING_TYPING  0x02
#define IDLEACTION_SITTING_DORMANT 0x03
#define IDLEACTION_OPERATING       0x04
#define IDLEACTION_OPERATING_PAD   0x05

#define INTROTYPE_SPAWN        0
#define INTROTYPE_WEAPON       1
#define INTROTYPE_AMMO         2
#define INTROTYPE_3            3
#define INTROTYPE_4            4
#define INTROTYPE_OUTFIT       5
#define INTROTYPE_6            6
#define INTROTYPE_WATCHTIME    7
#define INTROTYPE_CREDITOFFSET 8
#define INTROTYPE_CASE         9
#define INTROTYPE_CASERESPAWN  10
#define INTROTYPE_HILL         11
#define INTROTYPE_END          12

#define INVENTORYFUNCTYPE_NONE             0x0000
#define INVENTORYFUNCTYPE_SHOOT_SINGLE     0x0001
#define INVENTORYFUNCTYPE_SHOOT_AUTOMATIC  0x0101
#define INVENTORYFUNCTYPE_SHOOT_PROJECTILE 0x0201
#define INVENTORYFUNCTYPE_THROW            0x0002
#define INVENTORYFUNCTYPE_CLOSE            0x0003
#define INVENTORYFUNCTYPE_SPECIAL          0x0004
#define INVENTORYFUNCTYPE_VISUAL           0x0005

#define INVITEMTYPE_WEAP 1
#define INVITEMTYPE_PROP 2
#define INVITEMTYPE_DUAL 3

#define LANGBANK_AME       0x01
#define LANGBANK_ARCH      0x02
#define LANGBANK_ARK       0x03
#define LANGBANK_ASH       0x04
#define LANGBANK_AZT       0x05
#define LANGBANK_CAT       0x06
#define LANGBANK_CAVE      0x07
#define LANGBANK_AREC      0x08
#define LANGBANK_CRAD      0x09
#define LANGBANK_CRYP      0x0a
#define LANGBANK_DAM       0x0b
#define LANGBANK_DEPO      0x0c
#define LANGBANK_DEST      0x0d
#define LANGBANK_DISH      0x0e
#define LANGBANK_EAR       0x0f
#define LANGBANK_ELD       0x10
#define LANGBANK_IMP       0x11
#define LANGBANK_JUN       0x12
#define LANGBANK_LEE       0x13
#define LANGBANK_LEN       0x14
#define LANGBANK_LIP       0x15
#define LANGBANK_LUE       0x16
#define LANGBANK_OAT       0x17
#define LANGBANK_PAM       0x18
#define LANGBANK_PETE      0x19
#define LANGBANK_REF       0x1a
#define LANGBANK_RIT       0x1b
#define LANGBANK_RUN       0x1c
#define LANGBANK_SEVB      0x1d
#define LANGBANK_SEV       0x1e
#define LANGBANK_SEVX      0x1f
#define LANGBANK_SEVXB     0x20
#define LANGBANK_SHO       0x21
#define LANGBANK_SILO      0x22
#define LANGBANK_STAT      0x23
#define LANGBANK_TRA       0x24
#define LANGBANK_WAX       0x25
#define LANGBANK_GUN       0x26
#define LANGBANK_TITLE     0x27
#define LANGBANK_MPMENU    0x28
#define LANGBANK_PROPOBJ   0x29
#define LANGBANK_MPWEAPONS 0x2a
#define LANGBANK_OPTIONS   0x2b
#define LANGBANK_MISC      0x2c
#define LANGBANK_UFF       0x2d
#define LANGBANK_OLD       0x2e
#define LANGBANK_ATE       0x2f
#define LANGBANK_LAM       0x30
#define LANGBANK_MP1       0x31
#define LANGBANK_MP2       0x32
#define LANGBANK_MP3       0x33
#define LANGBANK_MP4       0x34
#define LANGBANK_MP5       0x35
#define LANGBANK_MP6       0x36
#define LANGBANK_MP7       0x37
#define LANGBANK_MP8       0x38
#define LANGBANK_MP9       0x39
#define LANGBANK_MP10      0x3a
#define LANGBANK_MP11      0x3b
#define LANGBANK_MP12      0x3c
#define LANGBANK_MP13      0x3d
#define LANGBANK_MP14      0x3e
#define LANGBANK_MP15      0x3f
#define LANGBANK_MP16      0x40
#define LANGBANK_MP17      0x41
#define LANGBANK_MP18      0x42
#define LANGBANK_MP19      0x43
#define LANGBANK_MP20      0x44

#define L_AME(index)       TEXT(LANGBANK_AME,       index)
#define L_ARCH(index)      TEXT(LANGBANK_ARCH,      index)
#define L_ARK(index)       TEXT(LANGBANK_ARK,       index)
#define L_ASH(index)       TEXT(LANGBANK_ASH,       index)
#define L_AZT(index)       TEXT(LANGBANK_AZT,       index)
#define L_CAT(index)       TEXT(LANGBANK_CAT,       index)
#define L_CAVE(index)      TEXT(LANGBANK_CAVE,      index)
#define L_AREC(index)      TEXT(LANGBANK_AREC,      index)
#define L_CRAD(index)      TEXT(LANGBANK_CRAD,      index)
#define L_CRYP(index)      TEXT(LANGBANK_CRYP,      index)
#define L_DAM(index)       TEXT(LANGBANK_DAM,       index)
#define L_DEPO(index)      TEXT(LANGBANK_DEPO,      index)
#define L_DEST(index)      TEXT(LANGBANK_DEST,      index)
#define L_DISH(index)      TEXT(LANGBANK_DISH,      index)
#define L_EAR(index)       TEXT(LANGBANK_EAR,       index)
#define L_ELD(index)       TEXT(LANGBANK_ELD,       index)
#define L_IMP(index)       TEXT(LANGBANK_IMP,       index)
#define L_JUN(index)       TEXT(LANGBANK_JUN,       index)
#define L_LEE(index)       TEXT(LANGBANK_LEE,       index)
#define L_LEN(index)       TEXT(LANGBANK_LEN,       index)
#define L_LIP(index)       TEXT(LANGBANK_LIP,       index)
#define L_LUE(index)       TEXT(LANGBANK_LUE,       index)
#define L_OAT(index)       TEXT(LANGBANK_OAT,       index)
#define L_PAM(index)       TEXT(LANGBANK_PAM,       index)
#define L_PETE(index)      TEXT(LANGBANK_PETE,      index)
#define L_REF(index)       TEXT(LANGBANK_REF,       index)
#define L_RIT(index)       TEXT(LANGBANK_RIT,       index)
#define L_RUN(index)       TEXT(LANGBANK_RUN,       index)
#define L_SEVB(index)      TEXT(LANGBANK_SEVB,      index)
#define L_SEV(index)       TEXT(LANGBANK_SEV,       index)
#define L_SEVX(index)      TEXT(LANGBANK_SEVX,      index)
#define L_SEVXB(index)     TEXT(LANGBANK_SEVXB,     index)
#define L_SHO(index)       TEXT(LANGBANK_SHO,       index)
#define L_SILO(index)      TEXT(LANGBANK_SILO,      index)
#define L_STAT(index)      TEXT(LANGBANK_STAT,      index)
#define L_TRA(index)       TEXT(LANGBANK_TRA,       index)
#define L_WAX(index)       TEXT(LANGBANK_WAX,       index)
#define L_GUN(index)       TEXT(LANGBANK_GUN,       index)
#define L_TITLE(index)     TEXT(LANGBANK_TITLE,     index)
#define L_MPMENU(index)    TEXT(LANGBANK_MPMENU,    index)
#define L_PROPOBJ(index)   TEXT(LANGBANK_PROPOBJ,   index)
#define L_MPWEAPONS(index) TEXT(LANGBANK_MPWEAPONS, index)
#define L_OPTIONS(index)   TEXT(LANGBANK_OPTIONS,   index)
#define L_MISC(index)      TEXT(LANGBANK_MISC,      index)
#define L_UFF(index)       TEXT(LANGBANK_UFF,       index)
#define L_OLD(index)       TEXT(LANGBANK_OLD,       index)
#define L_ATE(index)       TEXT(LANGBANK_ATE,       index)
#define L_LAM(index)       TEXT(LANGBANK_LAM,       index)
#define L_MP1(index)       TEXT(LANGBANK_MP1,       index)
#define L_MP2(index)       TEXT(LANGBANK_MP2,       index)
#define L_MP3(index)       TEXT(LANGBANK_MP3,       index)
#define L_MP4(index)       TEXT(LANGBANK_MP4,       index)
#define L_MP5(index)       TEXT(LANGBANK_MP5,       index)
#define L_MP6(index)       TEXT(LANGBANK_MP6,       index)
#define L_MP7(index)       TEXT(LANGBANK_MP7,       index)
#define L_MP8(index)       TEXT(LANGBANK_MP8,       index)
#define L_MP9(index)       TEXT(LANGBANK_MP9,       index)
#define L_MP10(index)      TEXT(LANGBANK_MP10,      index)
#define L_MP11(index)      TEXT(LANGBANK_MP11,      index)
#define L_MP12(index)      TEXT(LANGBANK_MP12,      index)
#define L_MP13(index)      TEXT(LANGBANK_MP13,      index)
#define L_MP14(index)      TEXT(LANGBANK_MP14,      index)
#define L_MP15(index)      TEXT(LANGBANK_MP15,      index)
#define L_MP16(index)      TEXT(LANGBANK_MP16,      index)
#define L_MP17(index)      TEXT(LANGBANK_MP17,      index)
#define L_MP18(index)      TEXT(LANGBANK_MP18,      index)
#define L_MP19(index)      TEXT(LANGBANK_MP19,      index)
#define L_MP20(index)      TEXT(LANGBANK_MP20,      index)

#define LANGUAGE_ENGLISH  0
#define LANGUAGE_JAPANESE 1

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
#define MAX_GUNHELD        10
#define MAX_LIFTS          10
#define MAX_MPCHRS         (4 + MAX_SIMULANTS)
#define MAX_OBJECTIVES     10
#define MAX_SIMULANTS      8
#define MAX_SPAWNPOINTS    24
#define MAX_SQUADRONS      16
#define MAX_TEAMS          8

#define MENUDIALOGTYPE_DEFAULT 1
#define MENUDIALOGTYPE_DANGER  2
#define MENUDIALOGTYPE_SUCCESS 3

#define MENUITEMTYPE_LABEL       0x01
#define MENUITEMTYPE_CUSTOM      0x02
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
#define MENUITEMTYPE_CAROUSEL    0x11
#define MENUITEMTYPE_MODEL       0x12
#define MENUITEMTYPE_15          0x15
#define MENUITEMTYPE_MARQUEE     0x17
#define MENUITEMTYPE_CONTROLLER  0x19
#define MENUITEMTYPE_END         0x1a

#define MENUOP_GETOPTIONCOUNT     1
#define MENUOP_GETOPTGROUPCOUNT   2
#define MENUOP_GETOPTIONTEXT      3
#define MENUOP_GETOPTGROUPTEXT    4
#define MENUOP_GETGROUPSTARTINDEX 5
#define MENUOP_SET                6
#define MENUOP_GETOPTIONVALUE     7
#define MENUOP_GET                8
#define MENUOP_GETSLIDER          9
#define MENUOP_GETSLIDERLABEL     10
#define MENUOP_CHECKDISABLED      12
#define MENUOP_13                 13
#define MENUOP_CHECKPREFOCUSED    15
#define MENUOP_16                 16
#define MENUOP_GETTEXT            17
#define MENUOP_SETTEXT            18
#define MENUOP_CHECKHIDDEN        24
#define MENUOP_100                100
#define MENUOP_101                101
#define MENUOP_102                102

#define MENUROOT_SOLOENDSCREEN 1
#define MENUROOT_SOLOPAUSE     2
#define MENUROOT_COMBATSIM     3
#define MENUROOT_MPPAUSE       4
#define MENUROOT_MPENDSCREEN   5
#define MENUROOT_FILESELECT    6
#define MENUROOT_BOOTPAKMGR    7
#define MENUROOT_9             9
#define MENUROOT_10            10
#define MENUROOT_4MBMAINMENU   11
#define MENUROOT_TRAINING      13

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

#define MOVEMODE_WALK     0
#define MOVEMODE_BIKE     3
#define MOVEMODE_GRAB     4
#define MOVEMODE_CUTSCENE 5

#define MPLOCKTYPE_NONE       0
#define MPLOCKTYPE_LASTWINNER 1
#define MPLOCKTYPE_LASTLOSER  2
#define MPLOCKTYPE_RANDOM     3
#define MPLOCKTYPE_PLAYER     4
#define MPLOCKTYPE_CHALLENGE  5

#define MPOPTION_TEAMSENABLED       0x00000002
#define MPOPTION_NORADAR            0x00000004
#define MPOPTION_NOAUTOAIM          0x00000008
#define MPOPTION_NOPLAYERHIGHLIGHT  0x00000010
#define MPOPTION_NOPICKUPHIGHLIGHT  0x00000020
#define MPOPTION_SLOWMOTION_ON      0x00000040
#define MPOPTION_SLOWMOTION_SMART   0x00000080
#define MPOPTION_NOPICKUPHIGHLIGHT  0x00000020
#define MPOPTION_FASTMOVEMENT       0x00000100
#define MPOPTION_KILLSSCORE         0x00000400
#define MPOPTION_HIGHLIGHTBRIEFCASE 0x00000800
#define MPOPTION_SHOWONRADAR1       0x00001000
#define MPOPTION_SHOWONRADAR2       0x00002000
#define MPOPTION_HILLONRADAR        0x00004000
#define MPOPTION_MOBILEHILL         0x00008000
#define MPOPTION_HIGHLIGHTTERMINAL  0x00020000
#define MPOPTION_SHOWONRADAR3       0x00040000
#define MPOPTION_HIGHLIGHTTARGET    0x00080000
#define MPOPTION_SHOWONRADAR4       0x00100000

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
#define MPQUICKTEAM_5              5

#define MPSCENARIO_COMBAT           0
#define MPSCENARIO_HOLDTHEBRIEFCASE 1
#define MPSCENARIO_HACKERCENTRAL    2
#define MPSCENARIO_POPACAP          3
#define MPSCENARIO_KINGOFTHEHILL    4
#define MPSCENARIO_CAPTURETHECASE   5

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
#define NUM_CHALLENGES       30
#define NUM_CHEATS           42
#define NUM_EXPLOSIONTYPES   26
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
#define NUM_WEAPONS          94

// obj->flags
#define OBJFLAG_00000001             0x00000001 // Editor: "Fall to Ground"
#define OBJFLAG_00000002             0x00000002 // Editor: "In Air Rotated 90 Deg Upside-Down"
#define OBJFLAG_00000004             0x00000004 // Editor: "In Air Upside-Down"
#define OBJFLAG_00000008             0x00000008 // Editor: "In Air"
#define OBJFLAG_00000010             0x00000010 // Editor: "Scale to Pad Bounds"
#define OBJFLAG_00000020             0x00000020 // Editor: "X to Pad Bounds"
#define OBJFLAG_00000040             0x00000040 // Editor: "Y to Pad Bounds"
#define OBJFLAG_00000080             0x00000080 // Editor: "Z to Pad Bounds"
#define OBJFLAG_00000100             0x00000100 // G5 mines, Air Base brown door, AF1 grate and escape door, Defense shuttle, Ruins mines, MBR lift door. Editor suggests "Force Collisions" but this seems wrong
#define OBJFLAG_00000200             0x00000200 // Editor: "Special Environment Mapping"
#define OBJFLAG_ILLUMINATED          0x00000400
#define OBJFLAG_00000800             0x00000800 // Editor: "Free Standing Glass"
#define OBJFLAG_00001000             0x00001000 // Editor: "Absolute Position"
#define OBJFLAG_00002000             0x00002000 // AF1 commhubs. Editor suggests "Weapon Not Dropped"
#define OBJFLAG_00004000             0x00004000 // Editor: "Assigned to Actor"
#define OBJFLAG_00008000             0x00008000 // Editor: "Embedded Object"
#define OBJFLAG_00010000             0x00010000 // Not used in scripts
#define OBJFLAG_INVINCIBLE           0x00020000
#define OBJFLAG_COLLECTABLE          0x00040000
#define OBJFLAG_00080000             0x00080000 // Thrown laptop?
#define OBJFLAG_UNCOLLECTABLE        0x00100000
#define OBJFLAG_00200000             0x00200000 // Editor: "Bounce and Destroy If Shot"
#define OBJFLAG_00400000             0x00400000 // Not used in scripts
#define OBJFLAG_00800000             0x00800000 // Not used in scripts
#define OBJFLAG_01000000             0x01000000 // Editor: "Embedded Object"
#define OBJFLAG_CANNOT_ACTIVATE      0x02000000 // Makes it do nothing if player presses B on object. Used mostly for doors.
#define OBJFLAG_04000000             0x04000000 // Editor: "AI Sees Through Door/Object"
#define OBJFLAG_08000000             0x08000000 // Not used in scripts
#define OBJFLAG_DEACTIVATED          0x10000000
#define OBJFLAG_20000000             0x20000000 // Editor: "Door Opens Backwards/Special Function/Conceal Weapon"
#define OBJFLAG_40000000             0x40000000 // Editor: "Door open by default/Empty weapon"
#define OBJFLAG_INTERCEPTOR_DISABLED 0x80000000

// obj->flags2
#define OBJFLAG2_00000001     0x00000001 // Used only in CI Training
#define OBJFLAG2_00000002     0x00000002 // Ruins spikes
#define OBJFLAG2_00000004     0x00000004 // Defense hostage doors - openable by AI?
#define OBJFLAG2_00000008     0x00000008 // Editor: "Don't load in Multiplayer"
#define OBJFLAG2_00000010     0x00000010 // Editor: "Don't Load on Agent Mode"
#define OBJFLAG2_00000020     0x00000020 // Editor: "Don't Load on Secret Agent Mode"
#define OBJFLAG2_00000040     0x00000040 // Editor: "Don't Load on Perfect Agent Mode"
#define OBJFLAG2_00000080     0x00000080 // Not used in scripts
#define OBJFLAG2_00000100     0x00000100 // Editor: "Immobile"
#define OBJFLAG2_00000200     0x00000200 // Editor: "Mines"
#define OBJFLAG2_00000400     0x00000400 // Not used in scripts
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
#define OBJFLAG2_00400000     0x00400000 // Editor: "Don't load on 2P (coop/anti)"
#define OBJFLAG2_00800000     0x00800000 // Editor: "Don't load on 3P"
#define OBJFLAG2_01000000     0x01000000 // Editor: "Don't load on 4P"
#define OBJFLAG2_THROWTHROUGH 0x02000000 // Rockets/mines/grenades etc pass through object
#define OBJFLAG2_04000000     0x04000000 // Used quite a lot - gravity?
#define OBJFLAG2_LOCKEDFRONT  0x08000000 // One-way door lock
#define OBJFLAG2_LOCKEDBACK   0x10000000 // One-way door lock
#define OBJFLAG2_AICANNOTUSE  0x20000000
#define OBJFLAG2_40000000     0x40000000 // Used by doors
#define OBJFLAG2_80000000     0x80000000 // Attack Ship glass

// obj->flags3
#define OBJFLAG3_PUSHABLE        0x00000001
#define OBJFLAG3_GRABBABLE       0x00000002
#define OBJFLAG3_DOOR_STICKY     0x00000004 // eg. Skedar Ruins
#define OBJFLAG3_00000008        0x00000008 // Not used in scripts
#define OBJFLAG3_00000010        0x00000010 // Used heaps
#define OBJFLAG3_00000020        0x00000020 // Not used in scripts
#define OBJFLAG3_RTRACKED_YELLOW 0x00000040
#define OBJFLAG3_00000080        0x00000080 // Not used in scripts
#define OBJFLAG3_00000100        0x00000100 // Not used in scripts
#define OBJFLAG3_00000200        0x00000200 // Not used in scripts
#define OBJFLAG3_WALKTRHOUGH     0x00000400
#define OBJFLAG3_RTRACKED_BLUE   0x00000800
#define OBJFLAG3_SHOWSHIELD      0x00001000 // Show shield effect around object (always)
#define OBJFLAG3_00002000        0x00002000 // Not used in scripts
#define OBJFLAG3_00004000        0x00004000 // Not used in scripts
#define OBJFLAG3_00008000        0x00008000 // Not used in scripts
#define OBJFLAG3_00010000        0x00010000 // Editor: "Can be activated"
#define OBJFLAG3_00020000        0x00020000 // Not used in scripts
#define OBJFLAG3_00040000        0x00040000 // Not used in scripts
#define OBJFLAG3_00080000        0x00080000 // Not used in scripts
#define OBJFLAG3_00100000        0x00100000 // Ruins spikes
#define OBJFLAG3_00200000        0x00200000 // Not used in scripts
#define OBJFLAG3_00400000        0x00400000 // Investigation tech items
#define OBJFLAG3_00800000        0x00800000 // Not used in scripts
#define OBJFLAG3_01000000        0x01000000 // Not used in scripts
#define OBJFLAG3_02000000        0x02000000 // Not used in scripts
#define OBJFLAG3_04000000        0x04000000 // Not used in scripts
#define OBJFLAG3_08000000        0x08000000 // Not used in scripts
#define OBJFLAG3_10000000        0x10000000 // Editor: "Keep Collisions After Fully Destroyed"
#define OBJFLAG3_20000000        0x20000000 // Not used in scripts
#define OBJFLAG3_40000000        0x40000000 // Editor: "Door Highlighted IR Scanner"
#define OBJFLAG3_80000000        0x80000000 // Not used in scripts

// obj->hidden
#define OBJHFLAG_00000004          0x00000004
#define OBJHFLAG_00000080          0x00000080
#define OBJHFLAG_00000200          0x00000200
#define OBJHFLAG_00000400          0x00000400
#define OBJHFLAG_00000800          0x00000800
#define OBJHFLAG_ACTIVATED_BY_BOND 0x00004000
#define OBJHFLAG_ACTIVATED_BY_COOP 0x00040000
#define OBJHFLAG_00100000          0x00100000
#define OBJHFLAG_00200000          0x00200000
#define OBJHFLAG_00400000          0x00400000
#define OBJHFLAG_04000000          0x04000000
#define OBJHFLAG_GRABBED           0x08000000

// obj->hidden2
#define OBJH2FLAG_04 0x04
#define OBJH2FLAG_08 0x08
#define OBJH2FLAG_40 0x40

#define OBJTYPE_DOOR             0x01
#define OBJTYPE_DOORSCALE        0x02
#define OBJTYPE_BASIC            0x03
#define OBJTYPE_KEY              0x04
#define OBJTYPE_ALARM            0x05
#define OBJTYPE_CAMERA           0x06
#define OBJTYPE_AMMOCRATE        0x07
#define OBJTYPE_WEAPON           0x08
#define OBJTYPE_CHR              0x09
#define OBJTYPE_SINGLEMONITOR    0x0a
#define OBJTYPE_MULTIMONITOR     0x0b
#define OBJTYPE_0C               0x0c
#define OBJTYPE_AUTOGUN          0x0d
#define OBJTYPE_LINKGUNS         0x0e
#define OBJTYPE_DEBRIS           0x0f
#define OBJTYPE_10               0x10
#define OBJTYPE_11               0x11
#define OBJTYPE_12               0x12
#define OBJTYPE_LINKOBJS         0x13
#define OBJTYPE_MULTIAMMOCRATE   0x14
#define OBJTYPE_SHIELD           0x15
#define OBJTYPE_TAG              0x16
#define OBJTYPE_BEGINOBJECTIVE   0x17
#define OBJTYPE_ENDOBJECTIVE     0x18
#define OBJECTIVETYPE_DESTROYOBJ 0x19
#define OBJECTIVETYPE_COMPFLAGS  0x1a
#define OBJECTIVETYPE_FAILFLAGS  0x1b
#define OBJECTIVETYPE_COLLECTOBJ 0x1c
#define OBJECTIVETYPE_THROWOBJ   0x1d
#define OBJECTIVETYPE_HOLOGRAPH  0x1e
#define OBJECTIVETYPE_1F         0x1f
#define OBJECTIVETYPE_ENTERROOM  0x20
#define OBJECTIVETYPE_ATTACHOBJ  0x21
#define OBJTYPE_22               0x22
#define OBJTYPE_BRIEFING         0x23
#define OBJTYPE_24               0x24
#define OBJTYPE_RENAMEOBJ        0x25
#define OBJTYPE_26               0x26
#define OBJTYPE_TRUCK            0x27
#define OBJTYPE_HELI             0x28
#define OBJTYPE_29               0x29
#define OBJTYPE_GLASS            0x2a
#define OBJTYPE_2B               0x2b
#define OBJTYPE_2C               0x2c
#define OBJTYPE_2D               0x2d
#define OBJTYPE_CAMERA2          0x2e
#define OBJTYPE_TINTEDGLASS      0x2f
#define OBJTYPE_LIFT             0x30
#define OBJTYPE_LINKSCENERY      0x31
#define OBJTYPE_LINKPATHS        0x32
#define OBJTYPE_HOVERBIKE        0x33
#define OBJTYPE_END              0x34
#define OBJTYPE_HOVERPROP        0x35
#define OBJTYPE_VENTFAN          0x36
#define OBJTYPE_HOVERCAR         0x37
#define OBJTYPE_PADEFFECT        0x38
#define OBJTYPE_CHOPPER          0x39
#define OBJTYPE_MINE             0x3a
#define OBJTYPE_ESCALATOR        0x3b

#define OBJECTIVE_INCOMPLETE 0
#define OBJECTIVE_COMPLETE   1
#define OBJECTIVE_FAILED     2

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

#define PATHTYPE_BACKANDFORTH 0
#define PATHTYPE_CIRCULAR     1
#define PATHTYPE_FLYING       2
#define PATHTYPE_4            4

#define PAUSEMODE_0 0
#define PAUSEMODE_1 1
#define PAUSEMODE_3 3

#define PDMODEPROP_REACTION 0
#define PDMODEPROP_HEALTH   1
#define PDMODEPROP_DAMAGE   2
#define PDMODEPROP_ACCURACY 3

#define PLAYERFLAG_NOCONTROL 0x00000002

#define PROPFLAG_02     0x02
#define PROPFLAG_HIDDEN 0x04
#define PROPFLAG_40     0x40
#define PROPFLAG_80     0x80

#define PROPTYPE_OBJ       1
#define PROPTYPE_DOOR      2
#define PROPTYPE_CHR       3
#define PROPTYPE_WEAPON    4
#define PROPTYPE_EYESPY    5
#define PROPTYPE_PLAYER    6
#define PROPTYPE_EXPLOSION 7
#define PROPTYPE_EFFECT    8

#define RACE_HUMAN    0
#define RACE_SKEDAR   1
#define RACE_DRCAROLL 2
#define RACE_EYESPY   3
#define RACE_ROBOT    4

#define ROOMFLAG_ACTIVE 0x0004
#define ROOMFLAG_4000   0x4000
#define ROOMFLAG_8000   0x8000

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

#define SCREENRATIO_NORMAL 0
#define SCREENRATIO_16_9   1

#define SCREENSIZE_FULL   0
#define SCREENSIZE_WIDE   1
#define SCREENSIZE_CINEMA 2

#define SCREENSPLIT_HORIZONTAL 0
#define SCREENSPLIT_VERTICAL   1

#define SHOTCOUNT_TOTAL  0
#define SHOTCOUNT_HEAD   1
#define SHOTCOUNT_BODY   2
#define SHOTCOUNT_LIMB   3
#define SHOTCOUNT_GUN    4
#define SHOTCOUNT_5      5 // hat?
#define SHOTCOUNT_OBJECT 6

#define SIGHT_DEFAULT  0
#define SIGHT_CLASSIC  1
#define SIGHT_EMPTYBOX 3
#define SIGHT_SKEDAR   4
#define SIGHT_ZOOM     5
#define SIGHT_MAIAN    6
#define SIGHT_NONE     7

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

#define SMOKETYPE_0 0
#define SMOKETYPE_1 1
#define SMOKETYPE_2 2
#define SMOKETYPE_3 3
#define SMOKETYPE_4 4
#define SMOKETYPE_5 5
#define SMOKETYPE_6 6
#define SMOKETYPE_7 7

#define SOLOSTAGEINDEX_DEFECTION     0
#define SOLOSTAGEINDEX_INVESTIGATION 1
#define SOLOSTAGEINDEX_EXTRACTION    2
#define SOLOSTAGEINDEX_VILLA         3
#define SOLOSTAGEINDEX_CHICAGO       4
#define SOLOSTAGEINDEX_G5BUILDING    5
#define SOLOSTAGEINDEX_INFILTRATION  6
#define SOLOSTAGEINDEX_RESCUE        7
#define SOLOSTAGEINDEX_ESCAPE        8
#define SOLOSTAGEINDEX_AIRBASE       9
#define SOLOSTAGEINDEX_AIRFORCEONE   10
#define SOLOSTAGEINDEX_CRASHSITE     11
#define SOLOSTAGEINDEX_PELAGIC       12
#define SOLOSTAGEINDEX_DEEPSEA       13
#define SOLOSTAGEINDEX_DEFENSE       14
#define SOLOSTAGEINDEX_ATTACKSHIP    15
#define SOLOSTAGEINDEX_SKEDARRUINS   16
#define SOLOSTAGEINDEX_MBR           17
#define SOLOSTAGEINDEX_MAIANSOS      18
#define SOLOSTAGEINDEX_WAR           19
#define SOLOSTAGEINDEX_DUEL          20

#define SOUNDMODE_MONO      0
#define SOUNDMODE_STEREO    1
#define SOUNDMODE_HEADPHONE 2
#define SOUNDMODE_SURROUND  3

#define SPECIALDIE_NONE        0
#define SPECIALDIE_1           1
#define SPECIALDIE_2           2
#define SPECIALDIE_3           3
#define SPECIALDIE_4           4
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

#define TICKMODE_0        0
#define TICKMODE_1        1
#define TICKMODE_3        3
#define TICKMODE_4        4
#define TICKMODE_6        6
#define TICKMODE_AUTOWALK 7

#define TELEPORTSTATE_0        0
#define TELEPORTSTATE_STARTING 1
#define TELEPORTSTATE_3        3
#define TELEPORTSTATE_4        4

#define VISIONMODE_NORMAL       0
#define VISIONMODE_XRAY         1
#define VISIONMODE_SLAYERROCKET 2

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
#define WEAPON_CALLISTONTG       0x0c
#define WEAPON_RCP120            0x0d
#define WEAPON_LAPTOPGUN         0x0e
#define WEAPON_DRAGON            0x0f
#define WEAPON_K7AVENGER         0x10
#define WEAPON_AR34              0x11
#define WEAPON_SUPERDRAGON       0x12
#define WEAPON_SHOTGUN           0x13
#define WEAPON_REAPER            0x14
#define WEAPON_SNIPERRIFLE       0x15
#define WEAPON_FARSIGHTXR20      0x16
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
#define WEAPON_CAMSPY            0x2e
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
#define WEAPON_5B                0x5b
#define WEAPON_5C                0x5c
#define WEAPON_SUICIDEPILL       0x5d

#define WEAPONFLAG_00000010          0x00000010
#define WEAPONFLAG_TRACKTIMEUSED     0x00000200
#define WEAPONFLAG_DUALWIELD         0x00001000
#define WEAPONFLAG_00040000          0x00040000
#define WEAPONFLAG_DETERMINER_S_AN   0x00200000
#define WEAPONFLAG_DETERMINER_F_AN   0x00400000
#define WEAPONFLAG_DETERMINER_S_THE  0x00800000
#define WEAPONFLAG_DETERMINER_F_THE  0x01000000
#define WEAPONFLAG_DETERMINER_S_SOME 0x10000000
#define WEAPONFLAG_DETERMINER_F_SOME 0x20000000

#define WEATHERTYPE_RAIN 0
#define WEATHERTYPE_SNOW 1

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

