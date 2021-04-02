//
// Skedar (MP)
//

#include "stagesetup.h"

// AI Lists
#define AILIST_INIT_ENEMY 0x0401
#define AILIST_INIT_MAIAN 0x0402

s32 intro[];
u32 props[];
struct path paths[];
struct ailist ailists[];

struct stagesetup setup = {
	NULL,
	NULL,
	NULL,
	intro,
	props,
	paths,
	ailists,
	NULL,
};

u32 props[] = {
	endprops
};

s32 intro[] = {
	spawn(0x0063)
	outfit(OUTFIT_DEFAULT)
	intro_weapon(WEAPON_FALCON2, -1)
	intro_weapon(WEAPON_CMP150, -1)
	intro_weapon(WEAPON_AR34, -1)
	intro_weapon(WEAPON_REAPER, -1)
	ammo(AMMOTYPE_PISTOL, 500)
	ammo(AMMOTYPE_RIFLE, 500)
	endintro
};

u8 func0406_idle[] = {
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

u8 func0408_idle_with_10_health[] = {
	set_chr_maxdamage(CHR_SELF, 10)
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

u8 func0404_spawn_enemies[] = {
	// Spawn 12 enemies
	set_chr_team(CHR_SELF, TEAM_ENEMY)
	restart_timer
	dprint 'B','4','C','H','E','C','K','\n',0,
	set_morale(12)
	label(0x04)
	if_morale_lt(1, /*goto*/ 0x01)
	try_spawn_chr_at_chr(BODY_DDSHOCK, HEAD_DDSHOCK, 0x06, AILIST_INIT_ENEMY, 0x00000010, /*goto*/ 0xa2)
	goto_next(0x01)
	label(0xa2)
	yield
	subtract_morale(1)
	goto_first(0x04)

	label(0x01)
	yield
	yield
	yield
	yield
	yield
	rebuild_teams
	rebuild_squadrons
	set_ailist(CHR_SELF, AILIST_INIT_ENEMY)
	endlist
};

u8 func0401_init_enemy[] = {
	try_equip_weapon(MODEL_CHRCMP150, WEAPON_CMP150, 0x00000000, /*goto*/ 0x01)
	label(0x01)
	try_inherit_properties(0x06, /*goto*/ 0x01)
	label(0x01)
	assign_path(0)
	start_path
	set_returnlist(CHR_SELF, GAILIST_CHOOSE_TARGET)
	set_ailist(CHR_SELF, GAILIST_CHOOSE_TARGET)
	endlist
};

u8 func0405_spawn_maians[] = {
	// Spawn 12 Maians
	set_chr_team(CHR_SELF, TEAM_ALLY)
	stop_chr
	restart_timer
	dprint 'B','4','C','H','E','K','\n',0,
	set_morale(12)
	label(0x04)
	if_morale_lt(1, /*goto*/ 0x01)
	try_spawn_chr_at_chr(BODY_ELVIS1, HEAD_ELVIS, 0x07, AILIST_INIT_MAIAN, 0x00000010, /*goto*/ 0xa2)
	goto_next(0x01)
	label(0xa2)
	yield
	subtract_morale(1)
	goto_first(0x04)

	label(0x01)
	rebuild_teams
	rebuild_squadrons
	yield
	yield
	yield
	yield
	yield
	set_ailist(CHR_SELF, AILIST_INIT_MAIAN)
	endlist
};

u8 func0402_init_maian[] = {
	set_chr_team(CHR_SELF, TEAM_ALLY)
	try_equip_weapon(MODEL_CHRFALCON2, WEAPON_MAGSEC4, 0x00000000, /*goto*/ 0x01)
	label(0x01)
	try_inherit_properties(0x07, /*goto*/ 0x01)
	label(0x01)
	assign_path(0)
	start_path
	set_returnlist(CHR_SELF, GAILIST_CHOOSE_TARGET)
	set_ailist(CHR_SELF, GAILIST_CHOOSE_TARGET)
	endlist
};

u8 func1001_01a4[] = {
	noop016c
	rebuild_teams
	rebuild_squadrons
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

u8 unregistered_function1[] = {
	// Print "t" to console when Joanna is looking at some object.
	// The object doesn't exist in the props code though, so was likely removed.
	label(0x04)
	yield
	if_chr_looking_at_object(CHR_BOND, 0x00, /*goto*/ 0x01)
	goto_first(0x04)

	label(0x01)
	dprint 't',0,
	goto_first(0x04)

	endlist
};

u8 func1000_idle[] = {
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

u8 func0403_init_some_sound[] = {
	play_sound(SFX_0037, -1)
	set_ailist(CHR_SELF, GAILIST_IDLE)
	endlist
};

// This function is never assigned.
u8 func0407_defend_pad[] = {
	set_shotlist(0x0407)
	if_enemy_distance_lt_and_los(2540, /*goto*/ 0xa5)
	if_chr_distance_to_pad_lt(CHR_SELF, 200, PAD_PRESET, /*goto*/ 0x01)

	// Go to target pad, but stop when seen player or when near pad
	label(0xdb)
	jog_to_pad(PAD_PRESET)
	label(0xdc)
	yield
	dprint 'G','O',' ','T','O',' ','P','A','D','\n',0,
	if_enemy_distance_lt_and_los(2540, /*goto*/ 0xa5)
	if_chr_distance_to_pad_lt(CHR_SELF, 200, PAD_PRESET, /*goto*/ 0x01)
	goto_first(0xdc)

	// Near pad. Wait until detected player.
	label(0x01)
	stop_chr
	label(0xa6)
	yield
	dprint 'A','T',' ','P','A','D','\n',0,
	if_enemy_distance_lt_and_los(2540, /*goto*/ 0xa5)
	if_chr_distance_to_pad_gt(CHR_SELF, 300, PAD_PRESET, /*goto*/ 0x01)
	goto_first(0xa6)

	label(0x01)
	goto_first(0xdb)

	// Do combat
	label(0xa5)
	dprint 'D','E','T','E','C','T','E','D','\n',0,
	set_returnlist(CHR_SELF, 0x0407)
	set_ailist(CHR_SELF, GAILIST_COMBAT_WITH_TARGET)
	endlist
};

struct ailist ailists[] = {
	{ func0401_init_enemy,          0x0401 },
	{ func0402_init_maian,          0x0402 },
	{ func0403_init_some_sound,     0x0403 },
	{ func0404_spawn_enemies,       0x0404 },
	{ func0405_spawn_maians,        0x0405 },
	{ func0406_idle,                0x0406 },
	{ func0407_defend_pad,          0x0407 },
	{ func0408_idle_with_10_health, 0x0408 },
	{ func1000_idle,                0x1000 },
	{ func1001_01a4,                0x1001 },
	{ NULL, 0 },
};

s32 path00[] = {
	0x0014,
	0x0015,
	-1,
};

s32 path01[] = {
	0x0064,
	0x0066,
	-1,
};

s32 path02[] = {
	0x0037,
	0x0033,
	0x0034,
	-1,
};

s32 path03[] = {
	0x0038,
	0x0039,
	0x003a,
	-1,
};

s32 path04[] = {
	0x0033,
	0x0037,
	0x0036,
	0x003d,
	0x003e,
	0x003f,
	0x0045,
	0x0048,
	0x003b,
	0x003a,
	0x0039,
	-1,
};

struct path paths[] = {
	{ path00, 0, 0 },
	{ path01, 1, 0 },
	{ path00, 0, 0 },
	{ path02, 2, 0 },
	{ path03, 3, 0 },
	{ path04, 4, 0 },
	{ NULL, 0, 0 },
};

