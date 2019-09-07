//
// Duel
//

#include "../include/setup.h"

// Characters
#define CHR_GUARD    0x00
#define CHR_JONATHAN 0x01
#define CHR_TRENT    0x02

// Stage flags
#define STAGEFLAG_GUARD_DEAD      0x00000100
#define STAGEFLAG_JONATHAN_DEAD   0x00000200
#define STAGEFLAG_TRENT_DEAD      0x00000400
#define STAGEFLAG_SA_WALK_TRIGGER 0x00000800
#define STAGEFLAG_PA_WALK_TRIGGER 0x00001000

// Functions
#define FUNC_MOVE_TO_PAD  0x0401
#define FUNC_GUARD_COMBAT 0x0402
#define FUNC_JON_COMBAT   0x0403
#define FUNC_TRENT_COMBAT 0x0404
#define FUNC_GUARD_INIT   0x0405
#define FUNC_JON_INIT     0x0406
#define FUNC_TRENT_INIT   0x0407

u8 intro[];
u8 props[];
struct aipaths paths[];
struct ailists functions[];

void *setup[] = {
	NULL,
	NULL,
	NULL,
	intro,
	props,
	paths,
	functions,
	NULL,
};

u8 props[] = {
	briefing(0, 0x5e01)
	briefing(1, 0x5e00)
	briefing(2, 0x5e02)
	briefing(3, 0x5e03)

	beginobjective(0, 0x5e04, (DIFFBIT_A | DIFFBIT_SA | DIFFBIT_PA | DIFFBIT_PD)) // "Defeat dataDyne guard"
		complete_flags(STAGEFLAG_GUARD_DEAD)
	endobjective

	beginobjective(1, 0x5e05, (DIFFBIT_SA | DIFFBIT_PA | DIFFBIT_PD)) // "Defeat Jonathan Dark"
		complete_flags(STAGEFLAG_JONATHAN_DEAD)
	endobjective

	beginobjective(2, 0x5e06, (DIFFBIT_PA | DIFFBIT_PD)) // "Defeat Trent Easton"
		complete_flags(STAGEFLAG_TRENT_DEAD)
	endobjective

	chr(0x00000200, 0x00, 0x0279, BODY_DDSHOCK, HEAD_RANDOM, FUNC_GUARD_INIT, -1, -1, 100, 100, 0x4c080800, 0x02000000, 0x02, 0x04, -1, 0, 0x00000000)
	weapon(0x0100, MODEL_CHRFALCON2, CHR_GUARD, 0x00004000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000003e8, 0x00000000, 0x00000000, 0x0fff0000, WEAPON_FALCON2_SCOPE, 0x00ffffff, 0x00000000)
	chr(0x00000200, 0x01, 0x0023, BODY_CISOLDIER, HEAD_JONATHAN, FUNC_JON_INIT, -1, -1, 100, 100, 0x4c080800, 0x02000000, 0x02, 0x04, -1, 0, 0x00000000)
	weapon(0x0100, MODEL_CHRDY357, CHR_JONATHAN, 0x00004000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000003e8, 0x00000000, 0x00000000, 0x0fff0000, WEAPON_DY357MAGNUM, 0x00ffffff, 0x00000000)
	chr(0x00000200, 0x02, 0x0024, BODY_TRENT, HEAD_TRENT, FUNC_TRENT_INIT, -1, -1, 100, 100, 0x4c080800, 0x02000000, 0x02, 0x04, -1, 0, 0x00000000)
	weapon(0x0100, MODEL_CHRDY357TRENT, CHR_TRENT, 0x00004000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000003e8, 0x00000000, 0x00000000, 0x0fff0000, WEAPON_DY357LX, 0x00ffffff, 0x00000000)
	door(0x0100, MODEL_DD_OFFICEDOOR, 0x0158, 0x00000400, 0x20000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000003e8, 0x00000000, 0x00000000, 0x0fff0000, 0x0000f333, 0x00010000, 0x00007fff, 0x00014000, 0x00000666, 0x00040000, 0x00000040, 0x00000384, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000800, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 0x00000000)
	door(0x0100, MODEL_DD_OFFICEDOOR, 0x0159, 0x00000400, 0x20000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000003e8, 0x00000000, 0x00000000, 0x0fff0000, 0x0000f333, 0x00010000, 0x00007fff, 0x00014000, 0x00000666, 0x00040000, 0x00000040, 0x00000384, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 0xff000000, 0x00000000, 0x00000000, 0x00000000)
	endprops
};

u8 intro[] = {
	outfit(OUTFIT_DEFAULT)
	spawn(0x027a)
	intro_weapon(WEAPON_FALCON2_SCOPE, -1)
	ammo(AMMOTYPE_PISTOL, 8)
	endintro
};

struct aipaths paths[] = {
	{ NULL, 0, 0 },
};

u8 func1000_counterop_setup[] = {
	yield
	set_chr_alliance(CHR_COUNTEROP, ALLIANCE_ENEMY)
	set_function(CHR_SELF, GFUNC_REBUILD_GROUPS)
	endfunction
};

u8 func1001_objectives_failed[] = {
	yield
	set_function(CHR_SELF, GFUNC_SHOW_OBJ_FAILED_MSG)
	endfunction
};

u8 func1002_first_walk[] = {
	set_chr_flag_bank3(CHR_VELVET, CHRFLAG3_HIDDEN)
	set_chr_flag_bank3(CHR_COUNTEROP, CHRFLAG3_HIDDEN)
	camera_movement(0x0488)
	unset_chr_flag_bank3(CHR_JOANNA, CHRFLAG3_HIDDEN)
	set_chr_flag_bank3(CHR_JOANNA, CHRFLAG3_UNPLAYABLE)
	set_chr_flag_bank2(CHR_JOANNA, CHRFLAG2_00020000)
	display_text(0x00, COLOR_02_WHITE, 0x5e07) // "THE DUEL"
	animation(ANIM_RELOAD, -1, -1, 0x0600, CHR_GUARD, 2)
	label(0x2d)
	message(CHR_JOANNA, 0x5e0c) // "Opponent skill level: AGENT"

	// Wait for camera to stop animating
	restart_timer

	beginloop(0x08)
		if_camera_animating(/*goto*/ 0x2d)
		goto_next(0x06)
		label(0x2d)
	endloop(0x08)

	// Start walking
	label(0x06)
	remove_displayed_text
	revoke_control(CHR_JOANNA, 0)
	enter_firstperson
	force_walk(CHR_JOANNA, 0x0275, 0x2805, 0x0064)
	chr_move_to_pad(CHR_GUARD, 0x0274, 0x01, /*goto*/ 0x0b)

	// Wait for walk to finish
	beginloop(0x0b)
		if_force_walk_finished(CHR_JOANNA, /*goto*/ 0x0c)
	endloop(0x0b)

	label(0x0c)
	grant_control(CHR_JOANNA)
	set_function(CHR_GUARD, FUNC_GUARD_COMBAT)
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

u8 func1007_second_walk[] = {
	// Wait until SA walk trigger
	beginloop(0x58)
		if_chr_dying(CHR_JOANNA, /*goto*/ 0x2d)
		if_chr_death_animation_finished(CHR_JOANNA, /*goto*/ 0x2d)
		if_stage_flag_eq(STAGEFLAG_SA_WALK_TRIGGER, TRUE, /*goto*/ 0x06)
	endloop(0x58)

	// Begin cutscene
	label(0x2d)
	set_function(CHR_SELF, GFUNC_IDLE)
	label(0x06)
	revoke_control(CHR_JOANNA, 0)
	camera_movement(0x0488)

	// Place chrs
	label(0x8f)
	set_function(CHR_P1P2, FUNC_MOVE_TO_PAD)
	chr_move_to_pad(CHR_JONATHAN, 0x0279, 0x01, /*goto*/ 0x2d)
	yield
	goto_first(0x8f)

	label(0x2d)
	unset_chr_flag_bank3(CHR_JONATHAN, CHRFLAG3_HIDDEN)
	unset_chr_flag_bank3(CHR_JONATHAN, CHRFLAG3_INVINCIBLE_TO_GUNFIRE)
	unset_chr_flag_bank3(CHR_JONATHAN, CHRFLAG3_UNEXPLODABLE)
	yield
	unset_chr_flag_bank3(CHR_JOANNA, CHRFLAG3_HIDDEN)
	set_chr_flag_bank3(CHR_JOANNA, CHRFLAG3_UNPLAYABLE)
	set_chr_flag_bank2(CHR_JOANNA, CHRFLAG2_00020000)
	animation(ANIM_GRAB_CROTCH, -1, -1, 0x0600, CHR_JONATHAN, 2)

	label(0x2d)
	message(CHR_JOANNA, 0x5e0d) // "Opponent skill level: SPECIAL AGENT"
	restart_timer

	beginloop(0x08)
		if_camera_animating(/*goto*/ 0x2d)
		goto_next(0x06)
		label(0x2d)
	endloop(0x08)

	// Start force walk
	label(0x06)
	label(0x2d)
	remove_displayed_text
	revoke_control(CHR_JOANNA, 0)
	enter_firstperson
	yield
	force_walk(CHR_JOANNA, 0x0275, 0x2805, 0x0064)

	// Place Jon
	call_rng
	if_rand_lt(128, /*goto*/ 0x8f)
	chr_move_to_pad(CHR_JONATHAN, 0x0271, 0x01, /*goto*/ 0x0b)
	label(0x8f)
	chr_move_to_pad(CHR_JONATHAN, 0x0270, 0x01, /*goto*/ 0x0b)

	// Wait for force walk to finish
	beginloop(0x0b)
		if_force_walk_finished(CHR_JOANNA, /*goto*/ 0x0c)
	endloop(0x0b)

	// Give control back to Jo
	label(0x0c)
	grant_control(CHR_JOANNA)
	set_function(CHR_JONATHAN, FUNC_JON_COMBAT)
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

u8 func0401_move_to_pad[] = {
	chr_move_to_pad(CHR_SELF, 0x027a, 0x01, /*goto*/ 0x06)
	label(0x06)
	yield
	stop_chr
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

u8 func1008_third_walk[] = {
	// Wait for flag or Jo dying
	beginloop(0x58)
		if_chr_dying(CHR_JOANNA, /*goto*/ 0x2d)
		if_chr_death_animation_finished(CHR_JOANNA, /*goto*/ 0x2d)
		if_stage_flag_eq(STAGEFLAG_PA_WALK_TRIGGER, TRUE, /*goto*/ 0x06)
	endloop(0x58)

	// Jo dead
	label(0x2d)
	set_function(CHR_SELF, GFUNC_IDLE)

	// Do cutscene
	label(0x06)
	revoke_control(CHR_JOANNA, 0)
	camera_movement(0x0488)

	label(0x8f)
	set_function(CHR_P1P2, FUNC_MOVE_TO_PAD)
	chr_move_to_pad(CHR_TRENT, 0x0279, 0x01, /*goto*/ 0x2d)
	yield
	goto_first(0x8f)

	label(0x2d)
	unset_chr_flag_bank3(CHR_TRENT, CHRFLAG3_HIDDEN)
	unset_chr_flag_bank3(CHR_TRENT, CHRFLAG3_INVINCIBLE_TO_GUNFIRE)
	unset_chr_flag_bank3(CHR_TRENT, CHRFLAG3_UNEXPLODABLE)
	yield
	unset_chr_flag_bank3(CHR_JOANNA, CHRFLAG3_HIDDEN)
	set_chr_flag_bank3(CHR_JOANNA, CHRFLAG3_UNPLAYABLE)
	set_chr_flag_bank2(CHR_JOANNA, CHRFLAG2_00020000)
	animation(ANIM_HEAD_ROLL, -1, -1, 0x0600, CHR_TRENT, 2)
	label(0x2d)
	message(CHR_JOANNA, 0x5e0e) // "Opponent skill level: PERFECT AGENT"

	// Wait for cutscene to finish
	restart_timer

	beginloop(0x08)
		if_camera_animating(/*goto*/ 0x2d)
		goto_next(0x06)
		label(0x2d)
	endloop(0x08)

	// Begin force walk
	label(0x06)
	remove_displayed_text
	revoke_control(CHR_JOANNA, 0)
	enter_firstperson
	force_walk(CHR_JOANNA, 0x0275, 0x2805, 0x0064)
	chr_move_to_pad(CHR_TRENT, 0x0272, 0x01, /*goto*/ 0x0b)

	beginloop(0x0b)
		if_force_walk_finished(CHR_JOANNA, /*goto*/ 0x0c)
	endloop(0x0b)

	label(0x0c)
	set_function(CHR_TRENT, FUNC_TRENT_COMBAT)
	grant_control(CHR_JOANNA)
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

u8 func1004_revoke_control[] = {
	yield
	revoke_control(CHR_JOANNA, 0)
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

u8 func1005_main[] = {
	// Wait until guard dead
	beginloop(0x04)
		if_chr_death_animation_finished(CHR_GUARD, /*goto*/ 0x2d)
		if_chr_dying(CHR_GUARD, /*goto*/ 0x2d)
		if_chr_unloaded(CHR_GUARD, /*goto*/ 0x2d)
	endloop(0x04)

	label(0x2d)
	message(CHR_JOANNA, 0x5e09) // "Well done! You were too quick for him!"
	set_stage_flag(STAGEFLAG_GUARD_DEAD)
	restart_timer

	beginloop(0x08)
		if_timer_gt(120, /*goto*/ 0x2d)
	endloop(0x08)

	// If Agent, return
	label(0x2d)
	if_difficulty_lt(DIFF_SA, /*goto*/ 0x2d)
	goto_next(0x06)

	label(0x2d)
	set_function(CHR_SELF, GFUNC_IDLE)

	label(0x06)
	set_stage_flag(STAGEFLAG_SA_WALK_TRIGGER)

	// Wait until Jonathan dead
	beginloop(0x09)
		if_chr_death_animation_finished(CHR_JONATHAN, /*goto*/ 0x2d)
		if_chr_dying(CHR_JONATHAN, /*goto*/ 0x2d)
		if_chr_unloaded(CHR_JONATHAN, /*goto*/ 0x2d)
	endloop(0x09)

	label(0x2d)
	message(CHR_JOANNA, 0x5e0a) // "Well done! You were too quick for him!"
	set_stage_flag(STAGEFLAG_JONATHAN_DEAD)
	restart_timer

	beginloop(0x0b)
		if_timer_gt(120, /*goto*/ 0x2d)
	endloop(0x0b)

	// If Special Agent, return
	label(0x2d)
	if_difficulty_lt(DIFF_PA, /*goto*/ 0x2d)
	goto_next(0x06)

	label(0x2d)
	set_function(CHR_SELF, GFUNC_IDLE)

	label(0x06)
	set_stage_flag(STAGEFLAG_PA_WALK_TRIGGER)

	// Wait until Trent dead
	beginloop(0x0c)
		if_chr_death_animation_finished(CHR_TRENT, /*goto*/ 0x2d)
		if_chr_dying(CHR_TRENT, /*goto*/ 0x2d)
		if_chr_unloaded(CHR_TRENT, /*goto*/ 0x2d)
	endloop(0x0c)

	label(0x2d)
	message(CHR_JOANNA, 0x5e0b) // "Well done! You were too quick for him!"
	set_stage_flag(STAGEFLAG_TRENT_DEAD)
	restart_timer

	beginloop(0x0d)
		if_timer_gt(120, /*goto*/ 0x2d)
	endloop(0x0d)

	label(0x2d)
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

u8 func1003_init_audio[] = {
	restart_default_music
	reset_ambience
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

u8 func1006_check_objectives_complete[] = {
	// Wait for all objectives complete
	beginloop(0x04)
		if_all_objectives_complete(/*goto*/ 0x2d)
	endloop(0x04)

	// Wait 3 seconds
	label(0x2d)
	restart_timer

	beginloop(0x08)
		if_timer_gt(180, /*goto*/ 0x2d)
	endloop(0x08)

	// End level
	label(0x2d)
	end_level
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

u8 func0402_guard_combat[] = {
	set_onshot_function(FUNC_GUARD_COMBAT)
	if_just_injured(CHR_SELF, /*goto*/ 0x03)
	set_chr_flag_bank2(CHR_SELF, CHRFLAG2_00008000)

	// Wait 2 seconds or for guard to come into view
	restart_timer

	beginloop(0x04)
		if_timer_gt(120, /*goto*/ 0x06)
		if_chr_in_view(/*goto*/ 0x2d)
	endloop(0x04)

	// Guard has come into view. Jump sideways.
	label(0x2d)
	try_jump_sideways(/*goto*/ 0x08)

	beginloop(0x08)
		if_chr_distance_lt(250, /*goto*/ 0x0e)
		if_chr_stopped(/*goto*/ 0x03)
	endloop(0x08)

	// Guard has been shot, or finished jump
	beginloop(0x03)
		if_chr_distance_lt(250, /*goto*/ 0x0e)
		if_chr_sees_player(/*goto*/ 0x06)
		reloop(0x03)

		// 2 seconds have passed without seeing guard, or guard has been shot
		label(0x06)
		if_chr_dying(TARGET_CHR, /*goto*/ 0x2e)
		try_aim_and_shoot_thing1(0x0220, 0x0000, /*goto*/ 0x2d)
		label(0x2d)
		try_aim_and_shoot_thing2(0x0200, 0x0000, /*goto*/ 0x0c)

		beginloop(0x0c)
			if_chr_stopped(/*goto*/ 0x06)
		endloop(0x0c)

		// Finished shooting
		label(0x06)
	endloop(0x03)

	// Dying
	label(0x2e)
	set_function(CHR_SELF, GFUNC_IDLE)

	// Hand combat
	label(0x0e)
	set_return_function(CHR_SELF, FUNC_TRENT_COMBAT)
	set_function(CHR_SELF, GFUNC_HAND_COMBAT)
	endfunction
};

u8 func0403_jon_combat[] = {
	set_onshot_function(FUNC_JON_COMBAT)
	if_just_injured(CHR_SELF, /*goto*/ 0x58)
	set_chr_flag_bank2(CHR_SELF, CHRFLAG2_00008000)
	restart_timer

	beginloop(0x04)
		if_timer_gt(240, /*goto*/ 0x58)
		if_within_units_of_sight(30, /*goto*/ 0x58)
	endloop(0x04)

	label(0x58)
	try_run_to_target_chr(/*goto*/ 0x08)

	beginloop(0x08)
		if_chr_distance_lt(250, /*goto*/ 0x0e)
		if_in_disarm_range(/*goto*/ 0x06)
		reloop(0x08)

		label(0x06)
		try_chr_kneel_and_shoot_thing(0x0220, 0x0000, /*goto*/ 0x2d)
		label(0x2d)
		try_roll_and_shoot(/*goto*/ 0x0c)
		try_chr_kneel_and_shoot_thing(0x0200, 0x0000, /*goto*/ 0x0c)

		beginloop(0x0c)
			if_chr_stopped(/*goto*/ 0x06)
		endloop(0x0c)

		label(0x06)
	endloop(0x58)

	label(0x0e)
	set_return_function(CHR_SELF, FUNC_JON_COMBAT)
	set_function(CHR_SELF, GFUNC_HAND_COMBAT)
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

u8 func0404_trent_combat[] = {
	set_onshot_function(FUNC_TRENT_COMBAT)
	if_just_injured(CHR_SELF, /*goto*/ 0x03)
	set_chr_flag_bank2(CHR_SELF, CHRFLAG2_00008000)
	restart_timer

	beginloop(0x04)
		if_timer_gt(120, /*goto*/ 0x03)
		if_chr_in_view(/*goto*/ 0x03)
	endloop(0x04)

	// Wait until player in sight or in close range
	beginloop(0x03)
		if_chr_distance_lt(250, /*goto*/ 0x0e)
		if_chr_sees_player(/*goto*/ 0x06)
		reloop(0x03)

		// Attack
		label(0x06)
		if_chr_dying(TARGET_CHR, /*goto*/ 0x2e)
		try_aim_and_shoot_thing1(0x0220, 0x0000, /*goto*/ 0x2d)
		label(0x2d)
		try_aim_and_shoot_thing2(0x0200, 0x0000, /*goto*/ 0x0c)

		beginloop(0x0c)
			if_chr_stopped(/*goto*/ 0x06)
		endloop(0x0c)

		label(0x06)
	endloop(0x03)

	// Hand combat
	label(0x0e)
	set_return_function(CHR_SELF, FUNC_TRENT_COMBAT)
	set_function(CHR_SELF, GFUNC_HAND_COMBAT)
	label(0x2e)
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

u8 func0405_guard_init[] = {
	set_self_flag_bank3(CHRFLAG3_NOAUTOAIM)
	set_accuracy(200)
	set_reaction_speed(50)
	set_chr_health(CHR_SELF, 20)
	set_armor(0)
	set_recovery_speed(0)
	set_shield(0)
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

u8 func0406_jon_init[] = {
	set_self_flag_bank3(CHRFLAG3_NOAUTOAIM)
	set_accuracy(200)
	set_reaction_speed(75)
	set_chr_health(CHR_SELF, 40)
	set_armor(0)
	set_recovery_speed(0)
	set_shield(0)
	set_self_flag_bank3(CHRFLAG3_HIDDEN)
	set_self_flag_bank3(CHRFLAG3_INVINCIBLE_TO_GUNFIRE)
	set_self_flag_bank3(CHRFLAG3_UNEXPLODABLE)
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

u8 func0407_trent_init[] = {
	set_self_flag_bank3(CHRFLAG3_NOAUTOAIM)
	set_accuracy(200)
	set_reaction_speed(75)
	set_chr_health(CHR_SELF, 40)
	set_armor(0)
	set_recovery_speed(0)
	set_shield(0)
	set_self_flag_bank3(CHRFLAG3_HIDDEN)
	set_self_flag_bank3(CHRFLAG3_INVINCIBLE_TO_GUNFIRE)
	set_self_flag_bank3(CHRFLAG3_UNEXPLODABLE)
	set_function(CHR_SELF, GFUNC_IDLE)
	endfunction
};

struct ailists functions[] = {
	{ func1000_counterop_setup,           0x1000 },
	{ func1001_objectives_failed,         0x1001 },
	{ func1002_first_walk,                0x1002 },
	{ func1003_init_audio,                0x1003 },
	{ func1004_revoke_control,            0x1004 },
	{ func1005_main,                      0x1005 },
	{ func1006_check_objectives_complete, 0x1006 },
	{ func1007_second_walk,               0x1007 },
	{ func1008_third_walk,                0x1008 },
	{ func0401_move_to_pad,               0x0401 },
	{ func0402_guard_combat,              0x0402 },
	{ func0403_jon_combat,                0x0403 },
	{ func0404_trent_combat,              0x0404 },
	{ func0405_guard_init,                0x0405 },
	{ func0406_jon_init,                  0x0406 },
	{ func0407_trent_init,                0x0407 },
	{ NULL, 0 },
};

