#
# Skedar (MP)
#

.set HEADERLEN, 0x20
.include "asm/include/setup.inc"

// Functions
.set FUNC0401_INIT_ENEMY, 0x0401
.set FUNC0402_INIT_MAIAN, 0x0402

props:
	endprops

intro:
	spawn 0x0063
	outfit OUTFIT_DEFAULT
	intro_weapon WEAPON_FALCON2, -1
	intro_weapon WEAPON_CMP150, -1
	intro_weapon WEAPON_AR34, -1
	intro_weapon WEAPON_REAPER, -1
	ammo AMMOTYPE_PISTOL, 500
	ammo AMMOTYPE_RIFLE, 500
	endintro

func0406_idle:
	set_function CHR_SELF, GFUNC_IDLE
	endfunction

func0408_idle_with_10_health:
	set_chr_health CHR_SELF, 10
	set_function CHR_SELF, GFUNC_IDLE
	endfunction

func0404_spawn_enemies:
	// Spawn 12 enemies
	set_chr_alliance CHR_SELF, ALLIANCE_ENEMY
	restart_timer
	dprint "B4CHECK\n"
	set_var_a 12
	label 0x04
	if_var_a_lt 1, /*goto*/ 0x01
	try_spawn_clone BODY_DDSHOCK, HEAD_DDSHOCK, 0x06, FUNC0401_INIT_ENEMY, 0x00000010, /*goto*/ 0xa2
	goto_next 0x01
	label 0xa2
	yield
	subtract_var_a 1
	goto_first 0x04

	label 0x01
	yield
	yield
	yield
	yield
	yield
	cmd0145_rebuild_groups
	cmd0146_rebuild_groups
	set_function CHR_SELF, FUNC0401_INIT_ENEMY
	endfunction

func0401_init_enemy:
	try_draw_weapon MODEL_CHRCMP150, WEAPON_CMP150, 0x00000000, /*goto*/ 0x01
	label 0x01
	try_inherit_properties 0x06, /*goto*/ 0x01
	label 0x01
	assign_path 0
	start_path
	set_return_function CHR_SELF, GFUNC_CHOOSE_TARGET_CHR
	set_function CHR_SELF, GFUNC_CHOOSE_TARGET_CHR
	endfunction

func0405_spawn_maians:
	// Spawn 12 Maians
	set_chr_alliance CHR_SELF, ALLIANCE_ALLY
	stop_chr
	restart_timer
	dprint "B4CHEK\n"
	set_var_a 12
	label 0x04
	if_var_a_lt 1, /*goto*/ 0x01
	try_spawn_clone BODY_ELVIS1, HEAD_ELVIS, 0x07, FUNC0402_INIT_MAIAN, 0x00000010, /*goto*/ 0xa2
	goto_next 0x01
	label 0xa2
	yield
	subtract_var_a 1
	goto_first 0x04

	label 0x01
	cmd0145_rebuild_groups
	cmd0146_rebuild_groups
	yield
	yield
	yield
	yield
	yield
	set_function CHR_SELF, FUNC0402_INIT_MAIAN
	endfunction

func0402_init_maian:
	set_chr_alliance CHR_SELF, ALLIANCE_ALLY
	try_draw_weapon MODEL_CHRFALCON2, WEAPON_MAGSEC4, 0x00000000, /*goto*/ 0x01
	label 0x01
	try_inherit_properties 0x07, /*goto*/ 0x01
	label 0x01
	assign_path 0
	start_path
	set_return_function CHR_SELF, GFUNC_CHOOSE_TARGET_CHR
	set_function CHR_SELF, GFUNC_CHOOSE_TARGET_CHR
	endfunction

func1001_01a4:
	noop016c
	cmd0145_rebuild_groups
	cmd0146_rebuild_groups
	set_function CHR_SELF, GFUNC_IDLE
	endfunction

unregistered_function1:
	// Print "t" to console when Joanna is looking at some object.
	// The object doesn't exist in the props code though, so was likely removed.
	label 0x04
	yield
	if_chr_looking_at_object CHR_JOANNA, 0x00, /*goto*/ 0x01
	goto_first 0x04

	label 0x01
	dprint "t"
	goto_first 0x04

	endfunction

func1000_idle:
	set_function CHR_SELF, GFUNC_IDLE
	endfunction

func0403_init_some_sound:
	play_sound 0x0037, -1
	set_function CHR_SELF, GFUNC_IDLE
	endfunction

// This function is never assigned.
func0407_defend_pad:
	set_onshot_function 0x0407
	if_enemy_distance_lt_and_los 2540, /*goto*/ 0xa5
	if_chr_distance_to_pad_lt CHR_SELF, 200, TARGET_PAD, /*goto*/ 0x01

	// Go to target pad, but stop when seen player or when near pad
	label 0xdb
	jog_to_pad TARGET_PAD
	label 0xdc
	yield
	dprint "GO TO PAD\n"
	if_enemy_distance_lt_and_los 2540, /*goto*/ 0xa5
	if_chr_distance_to_pad_lt CHR_SELF, 200, TARGET_PAD, /*goto*/ 0x01
	goto_first 0xdc

	// Near pad. Wait until detected player.
	label 0x01
	stop_chr
	label 0xa6
	yield
	dprint "AT PAD\n"
	if_enemy_distance_lt_and_los 2540, /*goto*/ 0xa5
	if_chr_distance_to_pad_gt CHR_SELF, 300, TARGET_PAD, /*goto*/ 0x01
	goto_first 0xa6

	label 0x01
	goto_first 0xdb

	// Do combat
	label 0xa5
	dprint "DETECTED\n"
	set_return_function CHR_SELF, 0x0407
	set_function CHR_SELF, GFUNC_COMBAT_WITH_TARGET_CHR
	endfunction

functions:
	register_function func0401_init_enemy          0x0401
	register_function func0402_init_maian          0x0402
	register_function func0403_init_some_sound     0x0403
	register_function func0404_spawn_enemies       0x0404
	register_function func0405_spawn_maians        0x0405
	register_function func0406_idle                0x0406
	register_function func0407_defend_pad          0x0407
	register_function func0408_idle_with_10_health 0x0408
	register_function func1000_idle                0x1000
	register_function func1001_01a4                0x1001
	endfunctions

path00:
	pad 0x0014
	pad 0x0015
	endpath

path01:
	pad 0x0064
	pad 0x0066
	endpath

path02:
	pad 0x0037
	pad 0x0033
	pad 0x0034
	endpath

path03:
	pad 0x0038
	pad 0x0039
	pad 0x003a
	endpath

path04:
	pad 0x0033
	pad 0x0037
	pad 0x0036
	pad 0x003d
	pad 0x003e
	pad 0x003f
	pad 0x0045
	pad 0x0048
	pad 0x003b
	pad 0x003a
	pad 0x0039
	endpath

paths:
	register_path path00, 0, 0
	register_path path01, 1, 0
	register_path path00, 0, 0
	register_path path02, 2, 0
	register_path path03, 3, 0
	register_path path04, 4, 0
	endpaths

.align 4
