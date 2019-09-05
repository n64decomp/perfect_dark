.set NULL,  0
.set FALSE, 0
.set TRUE,  1

.set ACTION_SCAN,               0x01
.set ACTION_UNDER_COVER,        0x02
.set ACTION_GRENADE_STOP,       0x03
.set ACTION_WAIT,               0x04
.set ACTION_GO_TO_COVER,        0x05
.set ACTION_BREAKING_COVER,     0x06
.set ACTION_SEE_COVER,          0x07
.set ACTION_FLANK_LEFT,         0x08
.set ACTION_FLANK_RIGHT,        0x09
.set ACTION_DODGE,              0x0a
.set ACTION_THROW_GRENADE,      0x0b
.set ACTION_SEEWAIT,            0x0c
.set ACTION_BACKOFF,            0x0d
.set ACTION_SYNC_SHOOT,         0x0e
.set ACTION_16,                 0x10 // unknown
.set ACTION_FOLLOW,             0x12
.set ACTION_RETREAT,            0x13
.set ACTION_SURRENDER,          0x14
.set ACTION_COWER,              0x15
.set ACTION_WARN_OTHERS,        0x17
.set ACTION_RUN_AWAY,           0x1f
.set ACTION_FLEE_GRENADE,       0x20
.set ACTION_HAND_COMBAT,        0x21
.set ACTION_FACING_TARGET,      0x35
.set ACTION_HAND_COMBAT_SKEDAR, 0x36

.set ALLIANCE_ENEMY, 0x02
.set ALLIANCE_ALLY,  0x10

.set AMMOTYPE_PISTOL,      0x01
.set AMMOTYPE_SMG,         0x02
.set AMMOTYPE_CROSSBOW,    0x03
.set AMMOTYPE_RIFLE,       0x04
.set AMMOTYPE_SHOTGUN,     0x05
.set AMMOTYPE_FARSIGHT,    0x06
.set AMMOTYPE_GRENADE,     0x07
.set AMMOTYPE_ROCKET,      0x08
.set AMMOTYPE_KNIFE,       0x09
.set AMMOTYPE_MAGNUM,      0x0a
.set AMMOTYPE_DEVASTATOR,  0x0b
.set AMMOTYPE_REMOTE_MINE, 0x0c
.set AMMOTYPE_PROXY_MINE,  0x0d
.set AMMOTYPE_TIMED_MINE,  0x0e
.set AMMOTYPE_REAPER,      0x0f
# 0x10
# 0x11
.set AMMOTYPE_NBOMB,       0x12
.set AMMOTYPE_SEDATIVE,    0x13
.set AMMOTYPE_CLOAK,       0x14
.set AMMOTYPE_BOOST,       0x15
.set AMMOTYPE_PSYCHOSIS,   0x16
# 0x17
.set AMMOTYPE_BUG,         0x18
# 0x19
.set AMMOTYPE_ECM_MINE,    0x20

.set BANK_0, 0
.set BANK_1, 1
.set BANK_2, 2
.set BANK_3, 3

.set CHANNEL_0,  0
.set CHANNEL_1,  1
.set CHANNEL_2,  2
.set CHANNEL_3,  3
.set CHANNEL_4,  4
.set CHANNEL_5,  5
.set CHANNEL_6,  6
.set CHANNEL_7,  7
.set CHANNEL_8,  8
.set CHANNEL_9,  9
.set CHANNEL_10, 10

.set CHR_P1P2,      0xf2
.set CHR_F3,        0xf3
.set CHR_COUNTEROP, 0xf4
.set CHR_VELVET,    0xf5
.set TARGET_CHR,    0xf6
.set CHR_JOANNA,    0xf8
.set CHR_CLONE,     0xf9
.set CHR_FRIEND,    0xfb // when seeing friend die
.set FOLLOW_CHR,    0xfc
.set CHR_SELF,      0xfd

// Character flags - bank 0 (chr struct offset 0x114)
.set CHRFLAG0_CANT_ALERT_GROUP,   0x00000001 // Don't set group alertness when becoming aware
.set CHRFLAG0_00000002,           0x00000002 // Not used in scripts
.set CHRFLAG0_00000004,           0x00000004 // Can search for player when heard?
.set CHRFLAG0_CAN_EXAMINE_BODY,   0x00000008
.set CHRFLAG0_00000010,           0x00000010 // Globals, Skedar Ruins
.set CHRFLAG0_SAID_INJURY_QUIP,   0x00000020
.set CHRFLAG0_00000040,           0x00000040 // Globals - related to cover?
.set CHRFLAG0_00000080,           0x00000080 // Globals, Chicago, Air Base
.set CHRFLAG0_CAN_BACKOFF,        0x00000100
.set CHRFLAG0_CAN_RETREAT,        0x00000200
.set CHRFLAG0_UNSURPRISABLE,      0x00000400 // may also be "can uncover disguise"
.set CHRFLAG0_CAN_THROW_GRENADES, 0x00000800
.set CHRFLAG0_CAN_FLANK,          0x00001000
.set CHRFLAG0_00002000,           0x00002000 // Used quite a lot
.set CHRFLAG0_00004000,           0x00004000 // Patroller - if set, overrides the 00002000 flag (interprets 00002000 as off)
.set CHRFLAG0_00008000,           0x00008000 // Something to do with breaking cover or grenades?
.set CHRFLAG0_AIVSAI,             0x00010000
.set CHRFLAG0_CAN_TRAP,           0x00020000
.set CHRFLAG0_CAN_RUN_FOR_ALARM,  0x00040000
.set CHRFLAG0_00080000,           0x00080000 // Air Force One: a "spawn done" flag
.set CHRFLAG0_00100000,           0x00100000 // Become alert when hearing player and never on screen
.set CHRFLAG0_00200000,           0x00200000 // Globals, Villa hostage takers
.set CHRFLAG0_00400000,           0x00400000 // Not used in scripts
.set CHRFLAG0_CAN_HEAR_ALARMS,    0x00800000
.set CHRFLAG0_01000000,           0x01000000 // Globals
.set CHRFLAG0_02000000,           0x02000000 // Globals - set when ambushing
.set CHRFLAG0_04000000,           0x04000000 // If set, chr can't follow player (ie. stays)?
.set CHRFLAG0_08000000,           0x08000000 // Globals, Villa, Infiltration, Pelagic
.set CHRFLAG0_10000000,           0x10000000 // If set, "IM GOING TO POP"
.set CHRFLAG0_CAN_HEARSPAWN,      0x20000000
.set CHRFLAG0_NOHEAR,             0x40000000 // Globals, Villa
.set CHRFLAG0_80000000,           0x80000000 // Globals, Villa, Chicago, CI Training

// Character flags - bank 1 (chr struct offset 0x118)
.set CHRFLAG1_00000001,                  0x00000001 // Globals, Extraction, Air Base, Deep Sea
.set CHRFLAG1_00000002,                  0x00000002 // Globals
.set CHRFLAG1_00000004,                  0x00000004 // Globals - If set, avoids cmd0184
.set CHRFLAG1_00000008,                  0x00000008 // Only used in WAR. If set, chr waits 2 seconds before attacking while defending
.set CHRFLAG1_00000010,                  0x00000010 // Globals - If set, avoids cmd0184
.set CHRFLAG1_00000020,                  0x00000020 // Globals, AF1, Defense - related to reload animation
.set CHRFLAG1_CAN_SNIPE,                 0x00000040
.set CHRFLAG1_00000080,                  0x00000080 // Not used in scripts
.set CHRFLAG1_DOINGIDLEANIMATION,        0x00000100
.set CHRFLAG1_WARNED,                    0x00000200
.set CHRFLAG1_00000400,                  0x00000400 // Globals
.set CHRFLAG1_00000800,                  0x00000800 // Globals - related to punch damage
.set CHRFLAG1_00001000,                  0x00001000 // Globals, Chicago, Infiltration
.set CHRFLAG1_00002000,                  0x00002000 // Globals - triggers grenade throw
.set CHRFLAG1_00004000,                  0x00004000 // Globals - related to cover
.set CHRFLAG1_LONG_CAMSPY_OBSERVATION,   0x00008000
.set CHRFLAG1_00010000,                  0x00010000 // Globals - if set, prevents setting of chrflag0_00100000
.set CHRFLAG1_00020000,                  0x00020000 // Globals
.set CHRFLAG1_00040000,                  0x00040000 // Globals - seems related to 00020000
.set CHRFLAG1_00080000,                  0x00080000 // Set in many places, read in globals and AF1
.set CHRFLAG1_00100000,                  0x00100000 // Globals
.set CHRFLAG1_00200000,                  0x00200000 // Deep Sea (Elvis)
.set CHRFLAG1_PUNCH_THEN_GENERAL_COMBAT, 0x00400000 // If unset, return after punching. If set, assign general combat
.set CHRFLAG1_DONE_SEARCH_ANIM,          0x00800000
.set CHRFLAG1_01000000,                  0x01000000 // Can search for player when heard?
.set CHRFLAG1_02000000,                  0x02000000 // Globals
.set CHRFLAG1_CAN_LOOK_AROUND,           0x04000000
.set CHRFLAG1_DISSPEE,                   0x08000000
.set CHRFLAG1_10000000,                  0x10000000 // Some kind of param for searching
.set CHRFLAG1_CAN_DRAW_PISTOL,           0x20000000
.set CHRFLAG1_40000000,                  0x40000000 // Globals
.set CHRFLAG1_80000000,                  0x80000000 // Globals

// Character flags - bank 2 (chr struct offset 0x14)
.set CHRFLAG2_00000001,           0x00000001 // Not used in scripts - sunglasses?
.set CHRFLAG2_00000002,           0x00000002 // Not used in scripts
.set CHRFLAG2_00000004,           0x00000004 // Not used in scripts
.set CHRFLAG2_00000008,           0x00000008 // Not used in scripts
.set CHRFLAG2_00000010,           0x00000010 // Not used in scripts
.set CHRFLAG2_00000020,           0x00000020 // Not used in scripts
.set CHRFLAG2_00000040,           0x00000040 // Not used in scripts
.set CHRFLAG2_00000080,           0x00000080 // Not used in scripts
.set CHRFLAG2_00000100,           0x00000100 // Not used in scripts
.set CHRFLAG2_00000200,           0x00000200 // Not used in scripts
.set CHRFLAG2_00000400,           0x00000400 // Related to coop buddy? Also used in Chicago
.set CHRFLAG2_KEEP_CORPSE,        0x00000800
.set CHRFLAG2_BUDDY_PLACED,       0x00001000
.set CHRFLAG2_00002000,           0x00002000 // Globals, Rescue guards once disguised
.set CHRFLAG2_TRIGGER_BUDDY_WARP, 0x00004000
.set CHRFLAG2_00008000,           0x00008000 // Duel only. Set on each opponent when they start combat.
.set CHRFLAG2_DISGUISE_UNCOVERED, 0x00010000
.set CHRFLAG2_00020000,           0x00020000 // Used in every stage, on Jo and other chrs. Only ever set, never unset or read.
.set CHRFLAG2_00040000,           0x00040000 // Not used in scripts
.set CHRFLAG2_DISGUISED,          0x00080000
.set CHRFLAG2_00100000,           0x00100000 // Set before warping to pad, never unset or read
.set CHRFLAG2_00200000,           0x00200000 // Not used in scripts
.set CHRFLAG2_00400000,           0x00400000 // Set in Chicago, G5, AF1, Defense, Attack Ship, Skedar Ruins, Maian SOS, WAR
.set CHRFLAG2_00800000,           0x00800000 // Not used in scripts
.set CHRFLAG2_01000000,           0x01000000 // Globals - asked about gun (eg. "where did you get that?")
.set CHRFLAG2_02000000,           0x02000000 // Similar to DISGUISED flag, but not sure where set
.set CHRFLAG2_04000000,           0x04000000 // Related to disguise and detection
.set CHRFLAG2_08000000,           0x08000000 // Globals, Villa and G5
.set CHRFLAG2_10000000,           0x10000000 // Related to invincible flag
.set CHRFLAG2_CLOAKED,            0x20000000
.set CHRFLAG2_40000000,           0x40000000 // Air Base and AF1
.set CHRFLAG2_PSYCHOSISED,        0x80000000

// Character flags - bank 3 (chr struct offset 0x18)
.set CHRFLAG3_00000001,                    0x00000001 // Villa takers, Attack Ship Cass and skedar - both set at end of intros
.set CHRFLAG3_00000002,                    0x00000002 // Seems to be set on guards who can spawn clones?
.set CHRFLAG3_00000004,                    0x00000004 // Not used in scripts
.set CHRFLAG3_NEVER_BEEN_ON_SCREEN,        0x00000008
.set CHRFLAG3_INVINCIBLE_TO_GUNFIRE,       0x00000010
.set CHRFLAG3_00000020,                    0x00000020 // Chicago, Infiltration, AF1, Ruins, WAR
.set CHRFLAG3_00000040,                    0x00000040 // Used quite a lot
.set CHRFLAG3_00000080,                    0x00000080 // Defection programmer, Rescue lab techs, globals when doing idle animation
.set CHRFLAG3_JUST_INJURED,                0x00000100
.set CHRFLAG3_00000200,                    0x00000200 // Set on clones
.set CHRFLAG3_HIDDEN,                      0x00000400
.set CHRFLAG3_NOAUTOAIM,                   0x00000800
.set CHRFLAG3_UNEXPLODABLE,                0x00001000
.set CHRFLAG3_00002000,                    0x00002000 // Not used in scripts
.set CHRFLAG3_HAS_SPECIAL_DEATH_ANIMATION, 0x00004000
.set CHRFLAG3_00008000,                    0x00008000 // Not used in scripts
.set CHRFLAG3_00010000,                    0x00010000 // Related to dead people in intro cutscenes
.set CHRFLAG3_00020000,                    0x00020000 // Chicago, Crash Site, Deep Sea, Defense, Ruins
.set CHRFLAG3_00040000,                    0x00040000 // Used a lot
.set CHRFLAG3_00080000,                    0x00080000
.set CHRFLAG3_KILLCOUNTABLE,               0x00100000
.set CHRFLAG3_00200000,                    0x00200000 // Not used in scripts
.set CHRFLAG3_00400000,                    0x00400000 // Not used in scripts
.set CHRFLAG3_UNPLAYABLE,                  0x00800000
.set CHRFLAG3_01000000,                    0x01000000 // Typically set on allies during init
.set CHRFLAG3_02000000,                    0x02000000 // can be unset by cmd0168
.set CHRFLAG3_04000000,                    0x04000000
.set CHRFLAG3_08000000,                    0x08000000 // Not used in scripts
.set CHRFLAG3_10000000,                    0x10000000 // Not used in scripts
.set CHRFLAG3_20000000,                    0x20000000 // Not used in scripts
.set CHRFLAG3_40000000,                    0x40000000 // Not used in scripts
.set CHRFLAG3_80000000,                    0x80000000 // Not used in scripts

.set COLOR_00_GREEN,  0x00
.set COLOR_02_WHITE,  0x02
.set COLOR_03_RED,    0x03
.set COLOR_04_ORANGE, 0x04
.set COLOR_05_GREEN,  0x05
.set COLOR_06_WHITE,  0x06
.set COLOR_07_RED,    0x07
.set COLOR_08_RED,    0x08
.set COLOR_09_BLUE,   0x09

.set DIFF_A,  0x00
.set DIFF_SA, 0x01
.set DIFF_PA, 0x02
.set DIFF_PD, 0x03

// These difficulties are for briefings, which can be bitwise ORed
.set DIFFBIT_A,  0x01
.set DIFFBIT_SA, 0x02
.set DIFFBIT_PA, 0x04
.set DIFFBIT_PD, 0x08

.set DOORSTATE_CLOSED,  1
.set DOORSTATE_OPEN,    2
.set DOORSTATE_CLOSING, 4
.set DOORSTATE_OPENING, 8

.set EEPROMFLAG_CI_TOUR_DONE,         0x24
.set EEPROMFLAG_CI_HOLO7_DONE,        0x29
.set EEPROMFLAG_CI_HOLO6_DONE,        0x2a
.set EEPROMFLAG_CI_HOLO5_DONE,        0x2b
.set EEPROMFLAG_CI_HOLO4_DONE,        0x2c
.set EEPROMFLAG_CI_HOLO3_DONE,        0x2d
.set EEPROMFLAG_CI_HOLO2_DONE,        0x2e
.set EEPROMFLAG_CI_HOLO1_DONE,        0x2f
.set EEPROMFLAG_CI_CLOAK_DONE,        0x30
.set EEPROMFLAG_CI_DISGUISE_DONE,     0x31
.set EEPROMFLAG_CI_XRAY_DONE,         0x32
.set EEPROMFLAG_CI_IR_DONE,           0x33
.set EEPROMFLAG_CI_RTRACKER_DONE,     0x34
.set EEPROMFLAG_CI_DOORDECODER_DONE,  0x35
.set EEPROMFLAG_CI_NIGHTVISION_DONE,  0x36
.set EEPROMFLAG_CI_CAMSPY_DONE,       0x37
.set EEPROMFLAG_CI_ECMMINE_DONE,      0x38
.set EEPROMFLAG_CI_UPLINK_DONE,       0x39
.set EEPROMFLAG_CI_TOUR_STARTED,      0x3a
.set EEPROMFLAG_CRASHSITE_BIKE,       0x3b
.set EEPROMFLAG_DEFENSE_JON,          0x3c
.set EEPROMFLAG_AF1_ENTRY,            0x3d
.set EEPROMFLAG_RESCUE_MECHANIC_DEAD, 0x3e
.set EEPROMFLAG_G5_MINE,              0x3f // true if thrown on top door

.set ENTITYTYPE_CHR,       0x0004
.set ENTITYTYPE_PAD,       0x0008
.set ENTITYTYPE_DIRECTION, 0x0010
.set ENTITYTYPE_TARGETCHR, 0x0200

.set GFUNC_IDLE,                   0x0000
.set GFUNC_UNALERTED_0001,         0x0001
.set GFUNC_UNALERTED_0002,         0x0002
.set GFUNC_STOP_UNALERTED,         0x0003 // unused
.set GFUNC_UNALERTED_0004,         0x0004
.set GFUNC_END_CINEMA,             0x0005
.set GFUNC_UNALERTED,              0x0006
.set GFUNC_ALERTED,                0x0007
.set GFUNC_WAKEUP,                 0x0008
.set GFUNC_IDLE_0009,              0x0009
.set GFUNC_BUSY,                   0x000a
.set GFUNC_CHOOSE_TARGET_CHR,      0x000b
.set GFUNC_COMBAT_WITH_TARGET_CHR, 0x000c
.set GFUNC_INIT_COMBAT,            0x000d // unused
.set GFUNC_SEE_THEN_ATTACK,        0x000e // unused
.set GFUNC_HAND_COMBAT,            0x000f
.set GFUNC_CIVILIAN_SAY_COMMENT,   0x0010
.set GFUNC_FLEE_FROM_GRENADE,      0x0011
.set GFUNC_INIT_COOP_100,          0x0012 // unused
.set GFUNC_INIT_COOP_200,          0x0013 // unused
.set GFUNC_COOP_BUDDY,             0x0014
.set GFUNC_TEST_CUTSCENE_BUDDY,    0x0015 // unused
.set GFUNC_SHOW_OBJ_FAILED_MSG,    0x0016
.set GFUNC_REBUILD_GROUPS,         0x0017
.set GFUNC_DO_BORED_ANIMATION,     0x0018
.set GFUNC_DO_SITTING_ANIMATION,   0x0019
.set GFUNC_DISGUISE_DETECTION,     0x001a
.set GFUNC_OBSERVE_CAMSPY,         0x001b
.set GFUNC_SURPRISED,              0x001c
.set GFUNC_SEARCH_FOR_PLAYER,      0x001d
.set GFUNC_LOOK_AROUND,            0x001e
.set GFUNC_RELATED_TO_SPAWNING,    0x001f
.set GFUNC_PLACE_COOP_BUDDY,       0x0020
.set GFUNC_STOP_AND_IDLE,          0x0021
.set GFUNC_COMMENT_ON_PLAYER_DEAD, 0x0022 // unused
.set GFUNC_DODGE,                  0x0023
.set GFUNC_FOLLOW_JOANNA,          0x0024
.set GFUNC_POINTLESS,              0x0025 // unused
.set GFUNC_INIT_PSYCHOSIS,         0x0026
.set GFUNC_PSYCHOSISED,            0x0027
.set GFUNC_AI_BOT_DEAD,            0x0028 // unused
.set GFUNC_AI_BOT_INIT,            0x0029 // unused
.set GFUNC_AI_BOT_ALIVE,           0x002a // unused
.set GFUNC_DO_SOMETHING_AND_WAIT,  0x002b // unused
.set GFUNC_INIT_SEARCH,            0x002c // unused
.set GFUNC_INVINCIBLE_AND_IDLE,    0x002d

.set IDLEACTION_STANDING,        0x01
.set IDLEACTION_SITTING_TYPING,  0x02
.set IDLEACTION_SITTING_DORMANT, 0x03
.set IDLEACTION_OPERATING,       0x04
.set IDLEACTION_OPERATING_PAD,   0x05

// Object flags - bank 0 (object struct offset 0x08)
.set OBJECTFLAG0_00000001,             0x00000001 // Not used in scripts
.set OBJECTFLAG0_00000002,             0x00000002 // Not used in scripts
.set OBJECTFLAG0_00000004,             0x00000004 // Not used in scripts
.set OBJECTFLAG0_00000008,             0x00000008 // Not used in scripts
.set OBJECTFLAG0_00000010,             0x00000010 // Not used in scripts
.set OBJECTFLAG0_00000020,             0x00000020 // Not used in scripts
.set OBJECTFLAG0_00000040,             0x00000040 // Not used in scripts
.set OBJECTFLAG0_00000080,             0x00000080 // Not used in scripts
.set OBJECTFLAG0_00000100,             0x00000100 // G5 mines, Air Base brown door, AF1 grate and escape door, Defense shuttle, Ruins mines, MBR lift door
.set OBJECTFLAG0_00000200,             0x00000200 // Not used in scripts
.set OBJECTFLAG0_ILLUMINATED,          0x00000400
.set OBJECTFLAG0_00000800,             0x00000800 // Not used in scripts
.set OBJECTFLAG0_00001000,             0x00001000 // Not used in scripts
.set OBJECTFLAG0_00002000,             0x00002000 // AF1 commhubs
.set OBJECTFLAG0_00004000,             0x00004000 // Not used in scripts
.set OBJECTFLAG0_00008000,             0x00008000 // Not used in scripts
.set OBJECTFLAG0_00010000,             0x00010000 // Not used in scripts
.set OBJECTFLAG0_INVINCIBLE,           0x00020000
.set OBJECTFLAG0_COLLECTABLE,          0x00040000
.set OBJECTFLAG0_00080000,             0x00080000 // Not used in scripts
.set OBJECTFLAG0_00100000,             0x00100000 // Lots of stages - mainly keycards?
.set OBJECTFLAG0_00200000,             0x00200000 // Not used in scripts
.set OBJECTFLAG0_00400000,             0x00400000 // Not used in scripts
.set OBJECTFLAG0_00800000,             0x00800000 // Not used in scripts
.set OBJECTFLAG0_01000000,             0x01000000 // Not used in scripts
.set OBJECTFLAG0_02000000,             0x02000000 // Extraction "winddoor", Rescue doors, Air Base lift door, Attack Ship hanger doors, CI xray comhubs
.set OBJECTFLAG0_04000000,             0x04000000 // Not used in scripts
.set OBJECTFLAG0_08000000,             0x08000000 // Not used in scripts
.set OBJECTFLAG0_DEACTIVATED,          0x10000000
.set OBJECTFLAG0_20000000,             0x20000000 // Not used in scripts
.set OBJECTFLAG0_40000000,             0x40000000 // Used quite a lot
.set OBJECTFLAG0_INTERCEPTOR_DISABLED, 0x80000000

// Object flags - bank 1 (object struct offset 0x0c)
.set OBJECTFLAG1_00000001,  0x00000001 // Used only in CI Training
.set OBJECTFLAG1_00000002,  0x00000002 // Ruins spikes
.set OBJECTFLAG1_00000004,  0x00000004 // Defense hostage doors - openable by AI?
.set OBJECTFLAG1_00000008,  0x00000008 // Not used in scripts
.set OBJECTFLAG1_00000010,  0x00000010 // Not used in scripts
.set OBJECTFLAG1_00000020,  0x00000020 // Not used in scripts
.set OBJECTFLAG1_00000040,  0x00000040 // Not used in scripts
.set OBJECTFLAG1_00000080,  0x00000080 // Not used in scripts
.set OBJECTFLAG1_00000100,  0x00000100 // Not used in scripts
.set OBJECTFLAG1_00000200,  0x00000200 // Not used in scripts
.set OBJECTFLAG1_00000400,  0x00000400 // Not used in scripts
.set OBJECTFLAG1_00000800,  0x00000800 // Not used in scripts
.set OBJECTFLAG1_00001000,  0x00001000 // Investigation CMP150s, Air Base safe item and shield
.set OBJECTFLAG1_00002000,  0x00002000 // Ruins commhub
.set OBJECTFLAG1_00004000,  0x00004000 // Not used in scripts
.set OBJECTFLAG1_00008000,  0x00008000 // Not used in scripts
.set OBJECTFLAG1_00010000,  0x00010000 // Not used in scripts
.set OBJECTFLAG1_00020000,  0x00020000 // G5 mine, Air Base mine
.set OBJECTFLAG1_00040000,  0x00040000 // Only used in CI training
.set OBJECTFLAG1_INVISIBLE, 0x00080000
.set OBJECTFLAG1_00100000,  0x00100000 // Not used in scripts
.set OBJECTFLAG1_00200000,  0x00200000 // Ruins spikes
.set OBJECTFLAG1_00400000,  0x00400000 // Not used in scripts
.set OBJECTFLAG1_00800000,  0x00800000 // Not used in scripts
.set OBJECTFLAG1_01000000,  0x01000000 // Not used in scripts
.set OBJECTFLAG1_02000000,  0x02000000 // Not used in scripts
.set OBJECTFLAG1_04000000,  0x04000000 // Used quite a lot - gravity?
.set OBJECTFLAG1_08000000,  0x08000000 // Locked door?
.set OBJECTFLAG1_10000000,  0x10000000 // Locked door?
.set OBJECTFLAG1_20000000,  0x20000000 // Locked door? Or indestructible by counter op?
.set OBJECTFLAG1_40000000,  0x40000000 // Not used in scripts
.set OBJECTFLAG1_80000000,  0x80000000 // Attack Ship glass

// Object flags - bank 2 (object struct offset 0x10)
.set OBJECTFLAG2_PUSHABLE,        0x00000001
.set OBJECTFLAG2_GRABBABLE,       0x00000002
.set OBJECTFLAG2_00000004,        0x00000004 // Not used in scripts
.set OBJECTFLAG2_00000008,        0x00000008 // Not used in scripts
.set OBJECTFLAG2_00000010,        0x00000010 // Used heaps
.set OBJECTFLAG2_00000020,        0x00000020 // Not used in scripts
.set OBJECTFLAG2_RTRACKED_YELLOW, 0x00000040
.set OBJECTFLAG2_00000080,        0x00000080 // Not used in scripts
.set OBJECTFLAG2_00000100,        0x00000100 // Not used in scripts
.set OBJECTFLAG2_00000200,        0x00000200 // Not used in scripts
.set OBJECTFLAG2_NO_COLLISION,    0x00000400
.set OBJECTFLAG2_RTRACKED_BLUE,   0x00000800
.set OBJECTFLAG2_00001000,        0x00001000 // Show shield around object (always)
.set OBJECTFLAG2_00002000,        0x00002000 // Not used in scripts
.set OBJECTFLAG2_00004000,        0x00004000 // Not used in scripts
.set OBJECTFLAG2_00008000,        0x00008000 // Not used in scripts
.set OBJECTFLAG2_00010000,        0x00010000 // Not used in scripts
.set OBJECTFLAG2_00020000,        0x00020000 // Not used in scripts
.set OBJECTFLAG2_00040000,        0x00040000 // Not used in scripts
.set OBJECTFLAG2_00080000,        0x00080000 // Not used in scripts
.set OBJECTFLAG2_00100000,        0x00100000 // Ruins spikes
.set OBJECTFLAG2_00200000,        0x00200000 // Not used in scripts
.set OBJECTFLAG2_00400000,        0x00400000 // Investigation tech items
.set OBJECTFLAG2_00800000,        0x00800000 // Not used in scripts
.set OBJECTFLAG2_01000000,        0x01000000 // Not used in scripts
.set OBJECTFLAG2_02000000,        0x02000000 // Not used in scripts
.set OBJECTFLAG2_04000000,        0x04000000 // Not used in scripts
.set OBJECTFLAG2_08000000,        0x08000000 // Not used in scripts
.set OBJECTFLAG2_10000000,        0x10000000 // Not used in scripts
.set OBJECTFLAG2_20000000,        0x20000000 // Not used in scripts
.set OBJECTFLAG2_40000000,        0x40000000 // Not used in scripts
.set OBJECTFLAG2_80000000,        0x80000000 // Not used in scripts

.set OPERATOR_LESS_THAN,    0
.set OPERATOR_GREATER_THAN, 1

.set OUTFIT_DEFAULT,      0x00
.set OUTFIT_ELVIS,        0x01
.set OUTFIT_TRENT,        0x02 // unused
.set OUTFIT_TRENCH,       0x03
.set OUTFIT_FROCK_RIPPED, 0x04
.set OUTFIT_FROCK,        0x05
.set OUTFIT_LEATHER,      0x06
.set OUTFIT_DEEPSEA,      0x07
.set OUTFIT_WETSUIT,      0x08
.set OUTFIT_SNOW,         0x09
.set OUTFIT_LAB,          0x0a
.set OUTFIT_STEWARDESS,   0x0b
.set OUTFIT_MRBLONDE,     0x0c
.set OUTFIT_MAIAN,        0x0d
.set OUTFIT_NEGOTIATOR,   0x0e // unused by scripts

.set PADEFFECT_SPARKS,          0x00
.set PADEFFECT_01,              0x01 // used only in Escape on a pad containing nothing
.set PADEFFECT_SPLASH,          0x02
.set PADEFFECT_SPARKS2,         0x03
.set PADEFFECT_SMOKE,           0x04
.set PADEFFECT_SMOKE_TEMPORARY, 0x05

.set SPEED_WALK, 0
.set SPEED_JOG,  1
.set SPEED_RUN,  2

.set STAGE_MAIANSOS,      0x09
.set STAGE_WAR,           0x16
.set STAGE_MP_RAVINE,     0x17
.set STAGE_ESCAPE,        0x19
.set STAGE_RETAKING,      0x1b
.set STAGE_CRASHSITE,     0x1c
.set STAGE_CHICAGO,       0x1d
.set STAGE_G5BUILDING,    0x1e
.set STAGE_MP_COMPLEX,    0x1f
.set STAGE_MP_G5BUILDING, 0x20
.set STAGE_PELAGIC,       0x21
.set STAGE_EXTRACTION,    0x22
.set STAGE_MP_TEMPLE,     0x25
.set STAGE_CITRAINING,    0x26
.set STAGE_AIRBASE,       0x27
.set STAGE_MP_PIPES,      0x29
.set STAGE_SKEDARRUINS,   0x2a
.set STAGE_VILLA,         0x2c
.set STAGE_DEFENSE,       0x2d
.set STAGE_INFILTRATION,  0x2f
.set STAGE_DEFECTION,     0x30
.set STAGE_AIRFORCEONE,   0x31
.set STAGE_MP_SKEDAR,     0x32
.set STAGE_INVESTIGATION, 0x33
.set STAGE_ATTACKSHIP,    0x34
.set STAGE_RESCUE,        0x35
.set STAGE_MBR,           0x37
.set STAGE_DEEPSEA,       0x38
.set STAGE_MP_BASE,       0x39
.set STAGE_MP_AREA52,     0x3b
.set STAGE_MP_WAREHOUSE,  0x3c
.set STAGE_MP_CARPARK,    0x3d
.set STAGE_MP_RUINS,      0x41
.set STAGE_MP_SEWERS,     0x42
.set STAGE_MP_FELICITY,   0x43
.set STAGE_MP_FORTRESS,   0x44
.set STAGE_MP_VILLA,      0x45
.set STAGE_MP_GRID,       0x47
.set STAGE_DUEL,          0x4f

.set TARGET_PAD, 0x2328

.set WEAPON_NONE,              0x00
.set WEAPON_UNARMED,           0x01
.set WEAPON_FALCON2,           0x02
.set WEAPON_FALCON2_SILENCER,  0x03
.set WEAPON_FALCON2_SCOPE,     0x04
.set WEAPON_MAGSEC4,           0x05
.set WEAPON_MAULER,            0x06
.set WEAPON_PHOENIX,           0x07
.set WEAPON_DY357MAGNUM,       0x08
.set WEAPON_DY357LX,           0x09
.set WEAPON_CMP150,            0x0a
.set WEAPON_CYCLONE,           0x0b
.set WEAPON_CALLISTONTG,       0x0c
.set WEAPON_RCP120,            0x0d
.set WEAPON_LAPTOPGUN,         0x0e
.set WEAPON_DRAGON,            0x0f
.set WEAPON_K7AVENGER,         0x10
.set WEAPON_AR34,              0x11
.set WEAPON_SUPERDRAGON,       0x12
.set WEAPON_SHOTGUN,           0x13
.set WEAPON_REAPER,            0x14
.set WEAPON_SNIPERRIFLE,       0x15
.set WEAPON_FARSIGHTXR20,      0x16
.set WEAPON_DEVASTATOR,        0x17
.set WEAPON_ROCKETLAUNCHER,    0x18
.set WEAPON_SLAYER,            0x19
.set WEAPON_COMBATKNIFE,       0x1a
.set WEAPON_CROSSBOW,          0x1b
.set WEAPON_TRANQUILIZER,      0x1c
.set WEAPON_LASER,             0x1d
.set WEAPON_GRENADE,           0x1e
.set WEAPON_NBOMB,             0x1f
.set WEAPON_TIMEDMINE,         0x20
.set WEAPON_PROXIMITYMINE,     0x21
.set WEAPON_REMOTEMINE,        0x22
.set WEAPON_COMBATBOOST,       0x23
.set WEAPON_PP9I,              0x24
.set WEAPON_CC13,              0x25
.set WEAPON_KL01313,           0x26
.set WEAPON_KF7SPECIAL,        0x27
.set WEAPON_ZZT9MM,            0x28
.set WEAPON_DMC,               0x29
.set WEAPON_AR53,              0x2a
.set WEAPON_RCP45,             0x2b
.set WEAPON_PSYCHOSISGUN,      0x2c
.set WEAPON_NIGHTVISION,       0x2d
.set WEAPON_CAMSPY,            0x2e
.set WEAPON_XRAYSCANNER,       0x2f
.set WEAPON_IRSCANNER,         0x30
.set WEAPON_CLOAKINGDEVICE,    0x31
.set WEAPON_HORIZONSCANNER,    0x32
.set WEAPON_TESTER,            0x33
.set WEAPON_ROCKETLAUNCHER_34, 0x34
.set WEAPON_ECMMINE,           0x35
.set WEAPON_DATAUPLINK,        0x36
.set WEAPON_RTRACKER,          0x37
.set WEAPON_PRESIDENTSCANNER,  0x38
.set WEAPON_DOORDECODER,       0x39
.set WEAPON_AUTOSURGEON,       0x3a
.set WEAPON_EXPLOSIVES,        0x3b
.set WEAPON_SKEDARBOMB,        0x3c
.set WEAPON_COMMSRIDER,        0x3d
.set WEAPON_TRACERBUG,         0x3e
.set WEAPON_TARGETAMPLIFIER,   0x3f
.set WEAPON_DISGUISE40,        0x40
.set WEAPON_DISGUISE41,        0x41
.set WEAPON_FLIGHTPLANS,       0x42
.set WEAPON_RESEARCHTAPE,      0x43
.set WEAPON_BACKUPDISK,        0x44
.set WEAPON_KEYCARD45,         0x45
.set WEAPON_KEYCARD46,         0x46
.set WEAPON_KEYCARD47,         0x47
.set WEAPON_KEYCARD48,         0x48
.set WEAPON_KEYCARD49,         0x49
.set WEAPON_KEYCARD4A,         0x4a
.set WEAPON_KEYCARD4B,         0x4b
.set WEAPON_KEYCARD4C,         0x4c
.set WEAPON_SUITCASE,          0x4d
.set WEAPON_BRIEFCASE,         0x4e
.set WEAPON_SHIELD,            0x4f
.set WEAPON_NECKLACE,          0x50
.set WEAPON_HAMMER,            0x51
.set WEAPON_52,                0x52
.set WEAPON_ROCKET,            0x53
.set WEAPON_HOMINGROCKET,      0x54
.set WEAPON_GRENADEROUND,      0x55
.set WEAPON_BOLT,              0x56
.set WEAPON_BRIEFCASE,         0x57
.set WEAPON_ROCKET,            0x58
.set WEAPON_59,                0x59
.set WEAPON_5A,                0x5a
.set WEAPON_5B,                0x5b
.set WEAPON_5C,                0x5c
.set WEAPON_SUICIDEPILL,       0x5d

// Heads and bodies
.set HEAD_RANDOM,          -1
.set BODY_DJBOND,          0x00
.set BODY_CONNERY,         0x01
.set BODY_DALTON,          0x02
.set BODY_MOORE,           0x03
.set HEAD_DARK_COMBAT,     0x04
.set HEAD_ELVIS,           0x05
.set HEAD_ROSS,            0x06
.set HEAD_CARRINGTON,      0x07
.set HEAD_MRBLONDE,        0x08
.set HEAD_TRENT,           0x09
.set HEAD_DDSHOCK,         0x0a
.set HEAD_GRAHAM,          0x0b
.set HEAD_DARK_FROCK,      0x0c
.set HEAD_SECRETARY,       0x0d
.set HEAD_CASSANDRA,       0x0e
.set HEAD_THEKING,         0x0f
.set HEAD_FEM_GUARD,       0x10
.set HEAD_JON,             0x11
.set HEAD_MARK2,           0x12
.set HEAD_CHRIST,          0x13
.set HEAD_RUSS,            0x14
.set HEAD_GREY,            0x15
.set HEAD_DARLING,         0x16
.set HEAD_ROBERT,          0x17
.set HEAD_BEAU1,           0x18
.set HEAD_FEM_GUARD2,      0x19
.set HEAD_BRIAN,           0x1a
.set HEAD_JAMIE,           0x1b
.set HEAD_DUNCAN2,         0x1c
.set HEAD_BIOTECH,         0x1d
.set HEAD_NEIL2,           0x1e
.set HEAD_EDMCG,           0x1f
.set HEAD_ANKA,            0x20
.set HEAD_LESLIE_S,        0x21
.set HEAD_MATT_C,          0x22
.set HEAD_PEER_S,          0x23
.set HEAD_EILEEN_T,        0x24
.set HEAD_ANDY_R,          0x25
.set HEAD_BEN_R,           0x26
.set HEAD_STEVE_K,         0x27
.set HEAD_JONATHAN,        0x28
.set HEAD_MAIAN_S,         0x29
.set HEAD_SHAUN,           0x2a
.set HEAD_BEAU2,           0x2b
.set HEAD_EILEEN_H,        0x2c
.set HEAD_SCOTT_H,         0x2d
.set HEAD_SANCHEZ,         0x2e
.set HEAD_DARKAQUA,        0x2f
.set HEAD_DDSNIPER,        0x30
.set HEAD_BEAU3,           0x31
.set HEAD_BEAU4,           0x32
.set HEAD_BEAU5,           0x33
.set HEAD_BEAU6,           0x34
.set HEAD_GRIFFEY,         0x35
.set HEAD_MOTO,            0x36
.set HEAD_KEITH,           0x37
.set HEAD_WINNER,          0x38
.set HEAD_A51FACEPLATE,    0x39
.set HEAD_ELVIS_GOGS,      0x3a
.set HEAD_STEVEM,          0x3b
.set HEAD_DARK_SNOW,       0x3c
.set HEAD_PRESIDENT,       0x3d
.set HEAD_VD,              0x3e
.set HEAD_KEN,             0x3f
.set HEAD_JOEL,            0x40
.set HEAD_TIM,             0x41
.set HEAD_GRANT,           0x42
.set HEAD_PENNY,           0x43
.set HEAD_ROBIN,           0x44
.set HEAD_ALEX,            0x45
.set HEAD_JULIANNE,        0x46
.set HEAD_LAURA,           0x47
.set HEAD_DAVEC,           0x48
.set HEAD_COOK,            0x49
.set HEAD_PRYCE,           0x4a
.set HEAD_SILKE,           0x4b
.set HEAD_SMITH,           0x4c
.set HEAD_GARETH,          0x4d
.set HEAD_MURCHIE,         0x4e
.set HEAD_WONG,            0x4f
.set HEAD_CARTER,          0x50
.set HEAD_TINTIN,          0x51
.set HEAD_MUNTON,          0x52
.set HEAD_STAMPER,         0x53
.set HEAD_JONES,           0x54
.set HEAD_PHELPS,          0x55
.set BODY_DARK_COMBAT,     0x56
.set BODY_ELVIS1,          0x57
.set BODY_AREA51GUARD,     0x58
.set BODY_OVERALL,         0x59
.set BODY_CARRINGTON,      0x5a
.set BODY_MRBLONDE,        0x5b
.set BODY_SKEDAR,          0x5c
.set BODY_TRENT,           0x5d
.set BODY_DDSHOCK,         0x5e
.set BODY_LABTECH,         0x5f
.set BODY_STRIPES,         0x60
.set BODY_DARK_FROCK,      0x61
.set BODY_DARK_TRENCH,     0x62
.set BODY_OFFICEWORKER,    0x63
.set BODY_OFFICEWORKER2,   0x64
.set BODY_SECRETARY,       0x65
.set BODY_CASSANDRA,       0x66
.set BODY_THEKING,         0x67
.set BODY_FEM_GUARD,       0x68
.set BODY_DD_LABTECH,      0x69
.set BODY_DD_SECGUARD,     0x6a
.set BODY_DRCARROLL,       0x6b
.set BODY_EYESPY,          0x6c
.set BODY_DARK_RIPPED,     0x6d
.set BODY_DD_GUARD,        0x6e
.set BODY_DD_SHOCK_INF,    0x6f
.set BODY_TESTCHR,         0x70
.set BODY_BIOTECH,         0x71
.set BODY_FBIGUY,          0x72
.set BODY_CIAGUY,          0x73
.set BODY_A51TROOPER,      0x74
.set BODY_A51AIRMAN,       0x75
.set BODY_CHICROB,         0x76
.set BODY_STEWARD,         0x77
.set BODY_STEWARDESS,      0x78
.set BODY_PRESIDENT,       0x79
.set BODY_STEWARDESS_COAT, 0x7a
.set BODY_MINISKEDAR,      0x7b
.set BODY_NSA_LACKEY,      0x7c
.set BODY_PRES_SECURITY,   0x7d
.set BODY_NEGOTIATOR,      0x7e
.set BODY_G5_GUARD,        0x7f
.set BODY_PELAGIC_GUARD,   0x80
.set BODY_G5_SWAT_GUARD,   0x81
.set BODY_ALASKAN_GUARD,   0x82
.set BODY_MAIAN_SOLDIER,   0x83
.set BODY_PRESIDENT_CLONE, 0x84
.set BODY_PRESIDENT_CLONE, 0x85
.set BODY_DARK_AF1,        0x86
.set BODY_DARKWET,         0x87
.set BODY_DARKAQUALUNG,    0x88
.set BODY_DARKSNOW,        0x89
.set BODY_DARKLAB,         0x8a
.set BODY_FEMLABTECH,      0x8b
.set BODY_DDSNIPER,        0x8c
.set BODY_PILOTAF1,        0x8d
.set BODY_CILABTECH,       0x8e
.set BODY_CIFEMTECH,       0x8f
.set BODY_CARREVENINGSUIT, 0x90
.set BODY_JONATHON,        0x91
.set BODY_CISOLDIER,       0x92
.set BODY_SKEDARKING,      0x93
.set BODY_ELVISWAISTCOAT,  0x94
.set BODY_DARK_LEATHER,    0x95
.set BODY_DARK_NEGOTIATOR, 0x96

// Models
.set MODEL_ROOFGUN,               0x0000
.set MODEL_GROUNDGUN,             0x0001
.set MODEL_TVSCREEN,              0x0002
.set MODEL_BORG_CRATE,            0x0003
.set MODEL_WINDOW,                0x0004
.set MODEL_A51_CRATE1_0005,       0x0005
.set MODEL_A51_CRATE1_0006,       0x0006
.set MODEL_A51_CRATE1_0007,       0x0007
.set MODEL_A51_CRATE1_0008,       0x0008
.set MODEL_A51_CRATE1_0009,       0x0009
.set MODEL_A51_CRATE1_000a,       0x000a
.set MODEL_A51_CRATE1_000b,       0x000b
.set MODEL_A51_CRATE1_000c,       0x000c
.set MODEL_A51_CRATE1_000d,       0x000d
.set MODEL_A51_CRATE1_000e,       0x000e
.set MODEL_A51_CRATE1_000f,       0x000f
.set MODEL_CRYPTDOOR1B,           0x0010
.set MODEL_CHRBRIEFCASE,          0x0011
.set MODEL_CHRBUG,                0x0012
.set MODEL_CHRDATATHIEF,          0x0013
.set MODEL_NINTENDOLOGO,          0x0014
.set MODEL_DOOR_ROLLERTRAIN,      0x0015
.set MODEL_FLAG,                  0x0016
.set MODEL_MODEMBOX,              0x0017
.set MODEL_DOORCONSOLE,           0x0018
.set MODEL_A51_HORIZ_DOOR_TOP,    0x0019
.set MODEL_A51_HORIZ_DOOR_BOT,    0x001a
.set MODEL_A51_VERT_DOOR_LEFT,    0x001b
.set MODEL_A51_VERT_DOOR_RIGHT,   0x001c
.set MODEL_A51_VERT_DOOR_ST,      0x001d
.set MODEL_A51_HORIZ_DOOR_GL,     0x001e
.set MODEL_A51_HORIZ_DOOR_SECRET, 0x001f
.set MODEL_A51_CRATE1,            0x0020
.set MODEL_A51_CRATE2,            0x0021
.set MODEL_A51_CRATE3,            0x0022
.set MODEL_A51_EXP1,              0x0023
.set MODEL_A51_UNEXP1,            0x0024
.set MODEL_A51_EXP2,              0x0025
.set MODEL_A51_UNEXP2,            0x0026
.set MODEL_A51_UNEXP3,            0x0027
.set MODEL_AIVILLADOOR1,          0x0028
.set MODEL_AIVILLADOOR2A,         0x0029
.set MODEL_AIVILLADOOR4,          0x002a
.set MODEL_A51_LIFT_HANGAR,       0x002b
.set MODEL_A51_LIFT_CONTROL,      0x002c
.set MODEL_A51_LIFT_STORE,        0x002d
.set MODEL_A51_LIFT_THINWALL,     0x002e
.set MODEL_AIVILLABOT1,           0x002f
.set MODEL_AIVILLABOT2,           0x0030
.set MODEL_AIVILLABOT3,           0x0031
.set MODEL_AIVILLAWINDMILL,       0x0032
.set MODEL_HOVERBED,              0x0033
.set MODEL_MARKER,                0x0034
.set MODEL_ALDOOR_R,              0x0035
.set MODEL_ALDOOR_L,              0x0036
.set MODEL_DD_LIFTR,              0x0037
.set MODEL_DD_FANROOF,            0x0038
.set MODEL_DD_FANWALL,            0x0039
.set MODEL_HOVBIKE,               0x003a
.set MODEL_DD_OFFICEDOOR,         0x003b
.set MODEL_DD_PLANTRUBBER,        0x003c
.set MODEL_DD_PLANTSPIKE,         0x003d
.set MODEL_DD_PLANTSPIDER,        0x003e
.set MODEL_DD_WINDOW,             0x003f
.set MODEL_DD_REDSOFA,            0x0040
.set MODEL_DD_REDARM,             0x0041
.set MODEL_DD_SERVICEDOOR,        0x0042
.set MODEL_DD_WINDDOOR,           0x0043
.set MODEL_DD_LIFTDOOR,           0x0044
.set MODEL_DD_VERTBLIND,          0x0045
.set MODEL_DD_DESK,               0x0046
.set MODEL_DD_CHAIR,              0x0047
.set MODEL_NLOGO,                 0x0048
.set MODEL_NLOGO2,                0x0049
.set MODEL_NLOGO3,                0x004a
.set MODEL_PERFECTDARK,           0x004b
.set MODEL_PDONE,                 0x004c
.set MODEL_PDTWO,                 0x004d
.set MODEL_PDTHREE,               0x004e
.set MODEL_PDFOUR,                0x004f
.set MODEL_DD_HOVCOP,             0x0050
.set MODEL_DD_HOVMOTO,            0x0051
.set MODEL_DD_HOVTRUCK,           0x0052
.set MODEL_DD_HOVCAR,             0x0053
.set MODEL_DD_HOVCAB,             0x0054
.set MODEL_DD_AC_UNEXP,           0x0055
.set MODEL_DD_AC_EXP,             0x0056
.set MODEL_DD_ACBOT_UNEXP,        0x0057
.set MODEL_DD_ACBOT_EXP,          0x0058
.set MODEL_PC1,                   0x0059
.set MODEL_HOVERCRATE1,           0x005a
.set MODEL_DROPSHIP,              0x005b
.set MODEL_AL_AIRLOCK,            0x005c
.set MODEL_AL_DOCKLIFT,           0x005d
.set MODEL_CASE,                  0x005e
.set MODEL_DD_STONEDESK,          0x005f
.set MODEL_MEDLABWIN1,            0x0060
.set MODEL_MEDLABWIN2,            0x0061
.set MODEL_A51TABLE,              0x0062
.set MODEL_A51CHAIR,              0x0063
.set MODEL_A51SCREEN,             0x0064
.set MODEL_A51WASTEBIN,           0x0065
.set MODEL_A51DESKENT,            0x0066
.set MODEL_A51TROLLEY,            0x0067
.set MODEL_A51DIVIDE,             0x0068
.set MODEL_A51BOARD,              0x0069
.set MODEL_SKCREV_EXP1,           0x006a
.set MODEL_SKCREV_UNEXP1,         0x006b
.set MODEL_SKTNL_EXP1,            0x006c
.set MODEL_SKTNL_UNEXP1,          0x006d
.set MODEL_SK_DOOR1,              0x006e
.set MODEL_SK_SHIP_DOOR1,         0x006f
.set MODEL_SK_SHIP_HOLO1,         0x0070
.set MODEL_SK_SHIP_HOLO2,         0x0071
.set MODEL_SK_SHIP_HULLDOOR1,     0x0072
.set MODEL_SK_SHIP_HULLDOOR2,     0x0073
.set MODEL_SK_SHIP_HULLDOOR3,     0x0074
.set MODEL_SK_SHIP_HULLDOOR4,     0x0075
.set MODEL_SK_FIGHTER1,           0x0076
.set MODEL_SK_CRYOPOD1_TOP,       0x0077
.set MODEL_SK_CRYOPOD1_BOT,       0x0078
.set MODEL_SK_UNDER_GENERATOR,    0x0079
.set MODEL_SK_UNDER_TRANS,        0x007a
.set MODEL_SK_HANGARDOOR_TOP,     0x007b
.set MODEL_SK_HANGARDOOR_BOT,     0x007c
.set MODEL_DOOR2_G5,              0x007d
.set MODEL_DOOR1A_G5,             0x007e
.set MODEL_DOOR1B_G5,             0x007f
.set MODEL_DOOR1ATRI_G5,          0x0080
.set MODEL_DOOR2A_G5,             0x0081
.set MODEL_DD_DECODOOR,           0x0082
.set MODEL_DD_SECRETDOOR,         0x0083
.set MODEL_DD_SECRETDOOR2,        0x0084
.set MODEL_DDJUMPSHIP,            0x0085
.set MODEL_TAXICAB,               0x0086
.set MODEL_POLICECAR,             0x0087
.set MODEL_RAVINELIFT,            0x0088
.set MODEL_DD_LAB_DOOR_BS,        0x0089
.set MODEL_DD_LAB_DOOR_SEC,       0x008a
.set MODEL_DD_LAB_DOOR_WIND,      0x008b
.set MODEL_HOOVERBOT,             0x008c
.set MODEL_TESTERBOT,             0x008d
.set MODEL_DD_LAB_SECTOR2BOT,     0x008e
.set MODEL_DD_LAB_SECTOR2TOP,     0x008f
.set MODEL_DD_LAB_CAUTIONTOP,     0x0090
.set MODEL_DD_LAB_HAZARD,         0x0091
.set MODEL_DD_LAB_CAUTION,        0x0092
.set MODEL_DR_CAROLL_DOOR,        0x0093
.set MODEL_DD_LAB_SECTOR3TOP,     0x0094
.set MODEL_DD_LAB_SECTOR3,        0x0095
.set MODEL_DD_LAB_SECTOR3WIND,    0x0096
.set MODEL_DD_HOVERCOPTER,        0x0097
.set MODEL_DD_LAB_SECTOR4TOP,     0x0098
.set MODEL_DD_LAB_RESTRICTED,     0x0099
.set MODEL_DOOR4A_G5,             0x009a
.set MODEL_DOOR4B_G5,             0x009b
.set MODEL_LASDOOR,               0x009c
.set MODEL_G5SAFEDOOR,            0x009d
.set MODEL_ROPE,                  0x009e
.set MODEL_G5_MAINFRAME,          0x009f
.set MODEL_DR_CAROLL_DOOR_BASE,   0x00a0
.set MODEL_DR_CAROLL_DOOR_MAIN,   0x00a1
.set MODEL_DR_CAROLL_DOOR_LEFT,   0x00a2
.set MODEL_DR_CAROLL_DOOR_RIGHT,  0x00a3
.set MODEL_DR_CAROLL_DOOR_BMAIN,  0x00a4
.set MODEL_DR_CAROLL_DOOR_BLEFT,  0x00a5
.set MODEL_DR_CAROLL_DOOR_BRIGHT, 0x00a6
.set MODEL_DD_BANNER,             0x00a7
.set MODEL_G5_ESCDOORUP,          0x00a8
.set MODEL_G5_ESCDOORUPBOOM,      0x00a9
.set MODEL_G5_ESCDOORDOWN,        0x00aa
.set MODEL_G5_ESCDOORDOWNBOOM,    0x00ab
.set MODEL_DUMPSTER,              0x00ac
.set MODEL_G5CARLIFTDOOR,         0x00ad
.set MODEL_CH_SHUTTER1,           0x00ae
.set MODEL_CCTV_PD,               0x00af
.set MODEL_COMHUB,                0x00b0
.set MODEL_QUADPOD,               0x00b1
.set MODEL_PD_CONSOLE,            0x00b2
.set MODEL_DD_GRATE,              0x00b3
.set MODEL_LIFT_PLATFORM,         0x00b4
.set MODEL_LIGHTSWITCH,           0x00b5
.set MODEL_BLASTSHIELD,           0x00b6
.set MODEL_LIGHTSWITCH2,          0x00b7
.set MODEL_DD_ACCESSDOORUP,       0x00b8
.set MODEL_DD_ACCESSDOORDN,       0x00b9
.set MODEL_LAB_CONTAINER,         0x00ba
.set MODEL_LAB_CHAIR,             0x00bb
.set MODEL_LAB_TABLE,             0x00bc
.set MODEL_LAB_MICROSCOPE,        0x00bd
.set MODEL_LAB_MAINFRAME,         0x00be
.set MODEL_DD_LABDOOR,            0x00bf
.set MODEL_DD_LAB_DOORTOP,        0x00c0
.set MODEL_MULTI_AMMO_CRATE,      0x00c1
.set MODEL_CHRCHAIN,              0x00c2
.set MODEL_TDOOR,                 0x00c3
.set MODEL_CI_SOFA,               0x00c4
.set MODEL_CI_LIFT,               0x00c5
.set MODEL_CI_LIFTDOOR,           0x00c6
.set MODEL_LASERCUT,              0x00c7
.set MODEL_SK_SHUTTLE,            0x00c8
.set MODEL_NEWVILLADOOR,          0x00c9
.set MODEL_SK_PILLARLEFT,         0x00ca
.set MODEL_SK_PILLARRIGHT,        0x00cb
.set MODEL_SK_PLINTH_T,           0x00cc
.set MODEL_SK_PLINTH_ML,          0x00cd
.set MODEL_SK_PLINTH_MR,          0x00ce
.set MODEL_SK_PLINTH_BL,          0x00cf
.set MODEL_SK_PLINTH_BR,          0x00d0
.set MODEL_SK_FL_SHAD_T,          0x00d1
.set MODEL_SK_FL_SHAD_ML,         0x00d2
.set MODEL_SK_FL_SHAD_MR,         0x00d3
.set MODEL_SK_FL_SHAD_BL,         0x00d4
.set MODEL_SK_FL_SHAD_BR,         0x00d5
.set MODEL_SK_FL_NOSHAD_T,        0x00d6
.set MODEL_SK_FL_NOSHAD_ML,       0x00d7
.set MODEL_SK_FL_NOSHAD_MR,       0x00d8
.set MODEL_SK_FL_NOSHAD_BL,       0x00d9
.set MODEL_SK_FL_NOSHAD_BR,       0x00da
.set MODEL_SK_TEMPLECOLUMN1,      0x00db
.set MODEL_SK_TEMPLECOLUMN2,      0x00dc
.set MODEL_SK_TEMPLECOLUMN3,      0x00dd
.set MODEL_SK_SUNSHAD1,           0x00de
.set MODEL_SK_SUNSHAD2,           0x00df
.set MODEL_SK_SUNNOSHAD1,         0x00e0
.set MODEL_SK_SUNNOSHAD2,         0x00e1
.set MODEL_BARREL,                0x00e2
.set MODEL_GLASS_FLOOR,           0x00e3
.set MODEL_ESCA_STEP,             0x00e4
.set MODEL_MATRIX_LIFT,           0x00e5
.set MODEL_RUBBLE1,               0x00e6
.set MODEL_RUBBLE2,               0x00e7
.set MODEL_RUBBLE3,               0x00e8
.set MODEL_RUBBLE4,               0x00e9
.set MODEL_CABLE_CAR,             0x00ea
.set MODEL_ELVIS_SAUCER,          0x00eb
.set MODEL_STEWARDESS_TROLLEY,    0x00ec
.set MODEL_AIRBASE_LIFT_ENCLOSED, 0x00ed
.set MODEL_AIRBASE_LIFT_ANGLE,    0x00ee
.set MODEL_AIRBASE_SAFEDOOR,      0x00ef
.set MODEL_AF1_PILOTCHAIR,        0x00f0
.set MODEL_AF1_PASSCHAIR,         0x00f1
.set MODEL_TESTOBJ,               0x00f2
.set MODEL_CHRNIGHTSIGHT,         0x00f3
.set MODEL_CHRSHIELD,             0x00f4
.set MODEL_CHRFALCON2,            0x00f5
.set MODEL_CHRLEEGUN1,            0x00f6
.set MODEL_CHRMAULER,             0x00f7
.set MODEL_CHRDY357,              0x00f8
.set MODEL_CHRDY357TRENT,         0x00f9
.set MODEL_CHRMAIANPISTOL,        0x00fa
.set MODEL_CHRFALCON2SIL,         0x00fb
.set MODEL_CHRFALCON2SCOPE,       0x00fc
.set MODEL_CHRCMP150,             0x00fd
.set MODEL_CHRAR34,               0x00fe
.set MODEL_CHRDRAGON,             0x00ff
.set MODEL_CHRSUPERDRAGON,        0x0100
.set MODEL_CHRAVENGER,            0x0101
.set MODEL_CHRCYCLONE,            0x0102
.set MODEL_CHRMAIANSMG,           0x0103
.set MODEL_CHRRCP120,             0x0104
.set MODEL_CHRPCGUN,              0x0105
.set MODEL_CHRSHOTGUN,            0x0106
.set MODEL_CHRSKMINIGUN,          0x0107
.set MODEL_CHRDYROCKET,           0x0108
.set MODEL_CHRDEVASTATOR,         0x0109
.set MODEL_CHRSKROCKET,           0x010a
.set MODEL_CHRZ2020,              0x010b
.set MODEL_CHRSNIPERRIFLE,        0x010c
.set MODEL_CHRCROSSBOW,           0x010d
.set MODEL_CHRDRUGGUN,            0x010e
.set MODEL_CHRKNIFE,              0x010f
.set MODEL_CHRNBOMB,              0x0110
.set MODEL_CHRFLASHBANG,          0x0111
.set MODEL_CHRGRENADE,            0x0112
.set MODEL_CHRTIMEDMINE,          0x0113
.set MODEL_CHRPROXIMITYMINE,      0x0114
.set MODEL_CHRREMOTEMINE,         0x0115
.set MODEL_CHRECMMINE,            0x0116
.set MODEL_CHRWPPK,               0x0117
.set MODEL_CHRTT33,               0x0118
.set MODEL_CHRSKORPION,           0x0119
.set MODEL_CHRKALASH,             0x011a
.set MODEL_CHRUZI,                0x011b
.set MODEL_CHRMP5K,               0x011c
.set MODEL_CHRM16,                0x011d
.set MODEL_CHRFNP90,              0x011e
.set MODEL_CHRDYROCKETMIS,        0x011f
.set MODEL_CHRSKROCKETMIS,        0x0120
.set MODEL_CHRCROSSBOLT,          0x0121
.set MODEL_CHRDEVGRENADE,         0x0122
.set MODEL_CHRDRAGGRENADE,        0x0123
.set MODEL_A51_TURRET,            0x0124
.set MODEL_PELAGICDOOR,           0x0125
.set MODEL_AUTOSURGEON,           0x0126
.set MODEL_LIMO,                  0x0127
.set MODEL_A51INTERCEPTOR,        0x0128
.set MODEL_A51DISH,               0x0129
.set MODEL_A51RADARCONSOLE,       0x012a
.set MODEL_A51LOCKERDOOR,         0x012b
.set MODEL_G5GENERATOR,           0x012c
.set MODEL_G5DUMPSTER,            0x012d
.set MODEL_CHRCLOAKER,            0x012e
.set MODEL_CHRSPEEDPILL,          0x012f
.set MODEL_BIGPELAGICDOOR,        0x0130
.set MODEL_SK_JONRUBBLE3,         0x0131
.set MODEL_SK_JONRUBBLE4,         0x0132
.set MODEL_SK_JONRUBBLE5,         0x0133
.set MODEL_SK_JONRUBBLE6,         0x0134
.set MODEL_BAGGAGECARRIER,        0x0135
.set MODEL_MINESIGN,              0x0136
.set MODEL_CHAMBER,               0x0137
.set MODEL_ISOTOPEEXPERIMENT,     0x0138
.set MODEL_ISOTOPE,               0x0139
.set MODEL_REACTORDOOR,           0x013a
.set MODEL_SAUCERINSIDE,          0x013b
.set MODEL_VILLASTOOL,            0x013c
.set MODEL_CETANWINDOW1,          0x013d
.set MODEL_CETANWINDOW2,          0x013e
.set MODEL_CETANWINDOW3,          0x013f
.set MODEL_BINOCULARS,            0x0140
.set MODEL_SUBMARINE,             0x0141
.set MODEL_AIRFORCE1,             0x0142
.set MODEL_ENGINEPART,            0x0143
.set MODEL_CETROOFGUN,            0x0144
.set MODEL_CETANSMALLDOOR,        0x0145
.set MODEL_POWERNODE,             0x0146
.set MODEL_CETANBLUEGREENL,       0x0147
.set MODEL_CETANBLUEGREENR,       0x0148
.set MODEL_SKEDARCONSOLE,         0x0149
.set MODEL_SKEDARCONSOLEPANEL,    0x014a
.set MODEL_WEAPONCDOOR,           0x014b
.set MODEL_TARGET,                0x014c
.set MODEL_DEVICESECRETDOOR,      0x014d
.set MODEL_CARRINGTONSECRETDOOR,  0x014e
.set MODEL_SINISTERPC,            0x014f
.set MODEL_SINISTERSTATION,       0x0150
.set MODEL_KEYPADLOCK,            0x0151
.set MODEL_THUMBPRINTSCANNER,     0x0152
.set MODEL_RETINALOCK,            0x0153
.set MODEL_CARDLOCK,              0x0154
.set MODEL_GOODSTATION,           0x0155
.set MODEL_GOODPC,                0x0156
.set MODEL_CHRAUTOGUN,            0x0157
.set MODEL_G5BIGCHAIR,            0x0158
.set MODEL_G5SMALLCHAIR,          0x0159
.set MODEL_KINGSCEPTRE,           0x015a
.set MODEL_LABCOAT,               0x015b
.set MODEL_CIDOOR1,               0x015c
.set MODEL_G5_CHAIR,              0x015d
.set MODEL_G5_CHAIR2,             0x015e
.set MODEL_DD_WINDOW_FOYER,       0x015f
.set MODEL_CI_CABINET,            0x0160
.set MODEL_CI_DESK,               0x0161
.set MODEL_CI_CARR_DESK,          0x0162
.set MODEL_CI_F_CHAIR,            0x0163
.set MODEL_CI_LOUNGER,            0x0164
.set MODEL_CI_F_SOFA,             0x0165
.set MODEL_CI_TABLE,              0x0166
.set MODEL_CV_COFFEE_TABLE,       0x0167
.set MODEL_CV_CHAIR1,             0x0168
.set MODEL_CV_CHAIR2,             0x0169
.set MODEL_CV_SOFA,               0x016a
.set MODEL_CV_CHAIR4,             0x016b
.set MODEL_CV_LAMP,               0x016c
.set MODEL_CV_CABINET,            0x016d
.set MODEL_CV_F_BED,              0x016e
.set MODEL_PEL_CHAIR1,            0x016f
.set MODEL_SK_CONSOLE2,           0x0170
.set MODEL_DD_EAR_TABLE,          0x0171
.set MODEL_DD_EAR_CHAIR,          0x0172
.set MODEL_AIRBASE_TABLE2,        0x0173
.set MODEL_AIRBASE_CHAIR2,        0x0174
.set MODEL_MISC_CRATE,            0x0175
.set MODEL_A51_CRATE1_0175,       0x0176
.set MODEL_MISC_IRSPECS,          0x0177
.set MODEL_A51_ROOFGUN,           0x0178
.set MODEL_SK_DRONE_GUN,          0x0179
.set MODEL_CI_ROOFGUN,            0x017a
.set MODEL_CV_TABLE,              0x017b
.set MODEL_CIDOOR1_REF,           0x017c
.set MODEL_ALASKADOOR_OUT,        0x017d
.set MODEL_ALASKADOOR_IN,         0x017e
.set MODEL_WIREFENCE,             0x017f
.set MODEL_RARELOGO,              0x0180
.set MODEL_KEYCARD,               0x0181
.set MODEL_BODYARMOUR,            0x0182
.set MODEL_A51GATE_R,             0x0183
.set MODEL_A51GATE_L,             0x0184
.set MODEL_AF1_LAMP,              0x0185
.set MODEL_AF1_TOILET,            0x0186
.set MODEL_AF1_DOORBIG2,          0x0187
.set MODEL_AF1_PHONE,             0x0188
.set MODEL_AF1_CARGODOOR,         0x0189
.set MODEL_G5_ALARM,              0x018a
.set MODEL_G5_LASER_SWITCH,       0x018b
.set MODEL_SK_TEMPLECOLUMN4,      0x018c
.set MODEL_COREHATCH,             0x018d
.set MODEL_A51GRATE,              0x018e
.set MODEL_AF1ESCAPEDOOR,         0x018f
.set MODEL_PRESCAPSULE,           0x0190
.set MODEL_SKEDARBRIDGE,          0x0191
.set MODEL_PELAGICDOOR2,          0x0192
.set MODEL_TTB_BOX,               0x0193
.set MODEL_INSTFRONTDOOR,         0x0194
.set MODEL_CHRLASER,              0x0195
.set MODEL_BAFTA,                 0x0196
.set MODEL_CHRSONICSCREWER,       0x0197
.set MODEL_CHRLUMPHAMMER,         0x0198
.set MODEL_EXPLOSIVEBRICK,        0x0199
.set MODEL_SKEDARBOMB,            0x019a
.set MODEL_ZIGGYCARD,             0x019b
.set MODEL_SAFEITEM,              0x019c
.set MODEL_RUSSDAR,               0x019d
.set MODEL_XRAYSPECS,             0x019e
.set MODEL_CHRLUMPHAMMER,         0x019f
.set MODEL_CHREYESPY,             0x01a0
.set MODEL_CHRDOORDECODER,        0x01a1
.set MODEL_AF1_TABLE,             0x01a2
.set MODEL_SHUTTLEDOOR,           0x01a3
.set MODEL_RUINBRIDGE,            0x01a4
.set MODEL_SECRETINDOOR,          0x01a5
.set MODEL_SENSITIVEINFO,         0x01a6
.set MODEL_SUITCASE,              0x01a7
.set MODEL_SKPUZZLEOBJECT,        0x01a8
.set MODEL_A51LIFTDOOR,           0x01a9
.set MODEL_CIHUB,                 0x01aa
.set MODEL_SK_SHIP_DOOR2,         0x01ab
.set MODEL_SK_WINDOW1,            0x01ac
.set MODEL_SK_HANGARDOORB_TOP,    0x01ad
.set MODEL_SK_HANGARDOORB_BOT,    0x01ae
.set MODEL_AF1_INNERDOOR,         0x01af
.set MODEL_LASER_POST,            0x01b0
.set MODEL_TARGETAMP,             0x01b1
.set MODEL_SK_LIFT,               0x01b2
.set MODEL_KNOCKKNOCK,            0x01b3
.set MODEL_CETANDOOR,             0x01b4
.set MODEL_AF1RUBBLE,             0x01b5
.set MODEL_DD_DR_NONREF,          0x01b6
.set MODEL_CETANDOORSIDE,         0x01b7
.set MODEL_BUDDYBRIDGE,           0x01b8

.set MUSIC_NONE,                    0x00
.set MUSIC_TITLE2,                  0x01
.set MUSIC_EXTRACTION,              0x02
.set MUSIC_PAUSEMENU,               0x03
.set MUSIC_DEFENSE,                 0x04
.set MUSIC_INVESTIGATION_SFX,       0x05
.set MUSIC_ESCAPE,                  0x06
.set MUSIC_DEEPSEA,                 0x07
.set MUSIC_DDTOWER_SFX,             0x08
.set MUSIC_DEFECTION,               0x09
.set MUSIC_DEATH_SOLO,              0x0a
.set MUSIC_DEFECTION_INTRO_SFX,     0x0b
.set MUSIC_VILLA,                   0x0c
.set MUSIC_CI,                      0x0d
.set MUSIC_CHICAGO,                 0x0e
.set MUSIC_G5,                      0x0f
.set MUSIC_DEFECTION_X,             0x10
.set MUSIC_EXTRACTION_X,            0x11
.set MUSIC_INVESTIGATION,           0x12
.set MUSIC_INVESTIGATION_x,         0x13
.set MUSIC_INFILTRATION,            0x14
.set MUSIC_DEATH_BETA,              0x15
.set MUSIC_RESCUE,                  0x16
.set MUSIC_AIRBASE,                 0x17
.set MUSIC_AIRFORCEONE,             0x18
.set MUSIC_DEATH_MP,                0x19
.set MUSIC_EXTRACTION_OUTRO_SFX,    0x1a
.set MUSIC_MISSION_UNKNOWN,         0x1b
.set MUSIC_PELAGIC,                 0x1c
.set MUSIC_CRASHSITE,               0x1d
.set MUSIC_CRASHSITE_X,             0x1e
.set MUSIC_ATTACKSHIP,              0x1f
.set MUSIC_ATTACKSHIP_X,            0x20
.set MUSIC_SKEDARRUINS,             0x21
.set MUSIC_DEFECTION_INTRO,         0x22
.set MUSIC_DEFECTION_OUTRO,         0x23
.set MUSIC_DEFENSE_X,               0x24
.set MUSIC_INVESTIGATION_INTRO,     0x25
.set MUSIC_INVESTIGATION_OUTRO,     0x26
.set MUSIC_VILLA_X,                 0x27
.set MUSIC_CHICAGO_X,               0x28
.set MUSIC_G5_X,                    0x29
.set MUSIC_INFILTRATION_X,          0x2a
.set MUSIC_CHICAGO_OUTRO,           0x2b
.set MUSIC_EXTRACTION_OUTRO,        0x2c
.set MUSIC_EXTRACTION_INTRO,        0x2d
.set MUSIC_G5_INTRO,                0x2e
.set MUSIC_CHICAGO_INTRO,           0x2f
.set MUSIC_VILLA_INTRO1,            0x30
.set MUSIC_INFILTRATION_INTRO,      0x31
.set MUSIC_RESCUE_X,                0x32
.set MUSIC_ESCAPE_X,                0x33
.set MUSIC_AIRBASE_X,               0x34
.set MUSIC_AIRFORCEONE_X,           0x35
.set MUSIC_PELAGIC_X,               0x36
.set MUSIC_DEEPSEA_X,               0x37
.set MUSIC_SKEDARRUINS_X,           0x38
.set MUSIC_AIRBASE_OUTRO_LONG,      0x39
.set MUSIC_DARK_COMBAT,             0x3a
.set MUSIC_SKEDAR_MYSTERY,          0x3b
.set MUSIC_DEEPSEA_BETA,            0x3c
.set MUSIC_CI_OPERATIVE,            0x3d
.set MUSIC_DATADYNE_ACTION,         0x3e
.set MUSIC_MAIAN_TEARS,             0x3f
.set MUSIC_ALIEN_CONFLICT,          0x40
.set MUSIC_ESCAPE_INTRO,            0x41
.set MUSIC_RESCUE_OUTRO,            0x42
.set MUSIC_VILLA_INTRO2,            0x43
.set MUSIC_VILLA_INTRO3,            0x44
.set MUSIC_G5_OUTRO,                0x45
.set MUSIC_G5_MIDCUTSCENE,          0x46
.set MUSIC_MISSION_FAILED,          0x47
.set MUSIC_COMBATSIM_MENU,          0x48
.set MUSIC_MISSION_SUCCESS,         0x49
.set MUSIC_CRASHSITE_INTRO,         0x4a
.set MUSIC_AIRBASE_INTRO,           0x4b
.set MUSIC_ATTACKSHIP_INTRO,        0x4c
.set MUSIC_DEEPSEA_MIDCUTSCENE,     0x4d
.set MUSIC_AIRFORCEONE_INTRO,       0x4e
.set MUSIC_ATTACKSHIP_OUTRO,        0x4f
.set MUSIC_ESCAPE_MIDCUTSCENE,      0x50
.set MUSIC_RESCUE_INTRO,            0x51
.set MUSIC_DEEPSEA_INTRO,           0x52
.set MUSIC_INFILTRATION_OUTRO,      0x53
.set MUSIC_PELAGIC_INTRO,           0x54
.set MUSIC_ESCAPE_OUTRO_LONG,       0x55
.set MUSIC_DEFENSE_INTRO,           0x56
.set MUSIC_CRASHSITE_OUTRO,         0x57
.set MUSIC_CREDITS,                 0x58
.set MUSIC_MAINMENU,                0x59
.set MUSIC_DEEPSEA_OUTRO,           0x5a
.set MUSIC_AIRFORCEONE_MIDCUTSCENE, 0x5b
.set MUSIC_PELAGIC_OUTRO,           0x5c
.set MUSIC_AIRFORCEONE_OUTRO,       0x5d
.set MUSIC_SKEDARRUINS_INTRO,       0x5e
.set MUSIC_BETA_NOTE,               0x5f
.set MUSIC_AIRBASE_OUTRO,           0x60
.set MUSIC_DEFENSE_OUTRO,           0x61
.set MUSIC_SKEDARRUINS_OUTRO,       0x62
.set MUSIC_VILLA_OUTRO,             0x63
.set MUSIC_SKEDARRUINS_KING,        0x64
.set MUSIC_CI_TRAINING,             0x65
.set MUSIC_CRASHSITE_WIND,          0x66
.set MUSIC_COMBATSIM_COMPLETE,      0x67
.set MUSIC_OCEAN,                   0x68
.set MUSIC_WIND,                    0x69
.set MUSIC_TRAFFIC,                 0x6a
.set MUSIC_TITLE1,                  0x6b
.set MUSIC_CI_INTRO,                0x6c
.set MUSIC_INFILTRATION_SFX,        0x6d
.set MUSIC_DEEPSEA_SFX,             0x6e
.set MUSIC_AIRFORCEONE_SFX,         0x6f
.set MUSIC_ATTACKSHIP_SFX,          0x70
.set MUSIC_SKEDAR_WIND,             0x71
.set MUSIC_ESCAPE_OUTRO_SFX,        0x72
.set MUSIC_A51_LOUDSPEAKER1,        0x73
.set MUSIC_A51_LOUDSPEAKER2,        0x74
.set MUSIC_BETA_MELODY,             0x75
.set MUSIC_ESCAPE_OUTRO_SHORT,      0x76


# Animations
#.set ANIM_, 0x0000: idle
.set ANIM_TWO_GUN_HOLD, 0x0001
.set ANIM_SURRENDER_002E, 0x002e
.set ANIM_TALKING_003D, 0x003d
#.set ANIM_, 0x0066: arms up action then move forward
.set ANIM_TALKING_0098, 0x0098
.set ANIM_YAWN, 0x009a
.set ANIM_SCRATCH_HEAD, 0x009b
.set ANIM_ROLL_HEAD, 0x009c
.set ANIM_GRAB_CROTCH, 0x009d
.set ANIM_GRAB_BUTT, 0x009e
.set ANIM_SNEEZE, 0x009f
.set ANIM_TALKING_00A0, 0x00a0
#.set ANIM_, 0x00a1: two handed gun, taunting a bit
.set ANIM_TALKING_00A3, 0x00a3
.set ANIM_PUSH_BUTTON, 0x00ac
.set ANIM_STANDING_TYPE_ONE_HAND, 0x00af
#.set ANIM_, 0x00e1: look up
#.set ANIM_, 0x0156: Jo in Defection intro
#.set ANIM_, 0x0166: Jo in G5 intro
#.set ANIM_, 0x0167: Guard in G5 intro
#.set ANIM_, 0x0179: Jo in Chicago outro
#.set ANIM_, 0x0197: Jo in G5 outro
#.set ANIM_, 0x01d5: Jo in Deep Sea mid cutscene
#.set ANIM_, 0x01d6: Elvis in Deep Sea mid cutscene
#.set ANIM_, 0x01d7: Dr Caroll in Deep Sea mid cutscene
.set ANIM_COWER_01F5, 0x01f5
.set ANIM_STAND_UP_FROM_SITTING, 0x01fa
.set ANIM_SITTING_TYPING, 0x01fb
#.set ANIM_, 0x01fd: slow aim and walk forward
.set ANIM_RELOAD, 0x01ff
.set ANIM_DONT_SHOOT, 0x0201
.set ANIM_SURPRISED_0202, 0x0202
.set ANIM_OPERATE_0204, 0x0204
.set ANIM_OPERATE_0205, 0x0205
.set ANIM_OPERATE_0206, 0x0206
.set ANIM_SMOKE_CIGARETTE, 0x0207
.set ANIM_RELOAD_0209, 0x0209
#.set ANIM_, 0x020b: laying on floor
#.set ANIM_, 0x020c: seated dead on floor
.set ANIM_OPERATE_0221, 0x0221 // point with right arm
.set ANIM_OPERATE_0222, 0x0222 // push button with right hand
.set ANIM_OPERATE_0223, 0x0223 // right arm up, waggle for a bit
.set ANIM_WALK_BACKWARDS, 0x0226
.set ANIM_SITTING_DORMANT, 0x0227
.set ANIM_BLINDED, 0x0228
.set ANIM_COWER_0229, 0x0229
#.set ANIM_, 0x022a: on floor face down
.set ANIM_TALKING_0231, 0x0231
.set ANIM_TALKING_0232, 0x0232
.set ANIM_TALKING_0233, 0x0233
.set ANIM_TALKING_0234, 0x0234
#.set ANIM_, 0x023a: scratch head
.set ANIM_HEAD_ROLL, 0x023b
.set ANIM_PICK_UP_GUN, 0x023d
.set ANIM_BIG_SNEEZE, 0x023f
.set ANIM_DRAW_PISTOL_0245, 0x0245
.set ANIM_LOOK_AROUND_025B, 0x025b
.set ANIM_LOOK_AROUND_025C, 0x025c
.set ANIM_LOOK_AROUND_025D, 0x025d
.set ANIM_LOOK_AROUND_025E, 0x025e
.set ANIM_LOOK_AROUND_FRANTIC, 0x025f
.set ANIM_SITTING_0265, 0x0265
#.set ANIM_, 0x0266: covering mouth looking
.set ANIM_DRAW_PISTOL_0288, 0x0288
.set ANIM_DRAW_PISTOL_0289, 0x0289
#.set ANIM_, 0x02c4: Jo in Defense intro
#.set ANIM_, 0x0350: Skedar right up straight up
#.set ANIM_, 0x0351: Skedar stretching arms and lefts
.set ANIM_SKEDAR_COLLAPSE, 0x0352

